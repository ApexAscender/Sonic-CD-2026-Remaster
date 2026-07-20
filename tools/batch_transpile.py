#!/usr/bin/env python3
"""
Batch driver for retroscript2cpp: convert every script under Scripts/ and report
transpiler coverage; with --emit, generate the full native object set plus the
registry / include / CMake glue.

Usage:
  python batch_transpile.py <scripts_root>                 # coverage report
  python batch_transpile.py <scripts_root> --emit <outdir> # emit everything

--emit writes per script:  O_*.hpp / O_*.cpp
and generates:             NativeObjectsGen.hpp   (include list)
                           NativeRegistryGen.inl  (registry rows, path-keyed)
                           gen_sources.cmake      (NATIVE_GEN_SOURCES list)
"""
import os, re, sys, collections
import retroscript2cpp as rs


def obj_name(relpath):
    """Scripts/R1/Platform.txt -> O_R1_Platform (folder prefix avoids collisions)."""
    parts = relpath.replace("\\", "/").split("/")
    stem = os.path.splitext(parts[-1])[0]
    folder = parts[-2] if len(parts) > 1 else ""
    raw = (folder + "_" + stem) if folder and folder != "Global" else stem
    return "O_" + re.sub(r"\W", "", raw)


def classify(w):
    """Normalize a warning to a construct bucket for the histogram."""
    m = re.match(r"func (\w+)", w)
    if m:
        return "func " + m.group(1)
    m = re.match(r"func-ref (\S+)", w)
    if m:
        return "func-ref " + m.group(1)
    m = re.match(r"array field (\S+)", w)
    if m:
        return "array field " + m.group(1)
    if w.startswith("stmt "):
        body = w[6:].strip("'")
        return "stmt " + (body.split(None, 1)[0] if body else "?")
    if w.startswith("expr "):
        return "expr"
    return w


# Unity/jumbo build: compiling 591 tiny TUs re-parses the heavy engine headers
# (RetroEngine.hpp -> SDL2, etc.) 591 times. Grouping the generated .cpp into a
# handful of aggregation TUs parses those headers once per bucket instead, which
# is the dominant build-time cost. Safe here: every generated file's content is
# namespaced (O_Xxx::) with zero file-scope statics, so amalgamation can't clash.
UNITY_BUCKETS = 16


# Objects whose generated .cpp/.hpp have been hand-edited past the faithful
# transliteration (e.g. the remastered title sequence). On --emit we still run
# convert() to pick up their sub names for the registry, but we DON'T overwrite
# the files, so hand edits survive re-emits. Keyed by object name (O_...).
HAND_MAINTAINED = {
    "O_Title_Sega",            # skips the Sega/CW splash -> straight to title (boot video replaces it)
    "O_Players_PlayerObject",  # native state/action dispatch (CallPlayerFunc) — see PlayerConstants.hpp
}


def main():
    root = sys.argv[1]
    emit = None
    if "--emit" in sys.argv:
        emit = sys.argv[sys.argv.index("--emit") + 1]
        os.makedirs(emit, exist_ok=True)

    results = []          # (relpath, obj, warnings, error)
    histogram = collections.Counter()
    emitted = []          # (relpath_fwd, obj, names)
    seen_obj = {}

    for dirpath, _, files in os.walk(root):
        for f in sorted(files):
            if not f.lower().endswith(".txt"):
                continue
            path = os.path.join(dirpath, f)
            rel = os.path.relpath(path, root)
            obj = obj_name(rel)
            if obj in seen_obj:
                raise SystemExit("object name collision: %s (%s vs %s)" % (obj, rel, seen_obj[obj]))
            seen_obj[obj] = rel
            try:
                if emit is not None:
                    hand = obj in HAND_MAINTAINED and os.path.exists(os.path.join(emit, obj + ".cpp"))
                    if hand:
                        # preserve hand edits: get sub names for the registry, don't write
                        t, body, names = rs.convert(path, obj)
                    else:
                        t, names, _reg = rs.write_files(path, obj, emit)
                    emitted.append((rel.replace("\\", "/"), obj, names))
                    warns = list(t.warnings)
                else:
                    t, body, names = rs.convert(path, obj)
                    warns = list(t.warnings)
                results.append((rel, obj, warns, None))
                for w in warns:
                    histogram[classify(w)] += 1
            except Exception as e:
                results.append((rel, obj, [], "%s: %s" % (type(e).__name__, e)))

    total = len(results)
    errors = [r for r in results if r[3]]
    clean = [r for r in results if not r[3] and not r[2]]
    dirty = [r for r in results if not r[3] and r[2]]

    print("=== transpiler coverage ===")
    print("scripts: %d   clean: %d (%.0f%%)   with-warnings: %d   parse-errors: %d"
          % (total, len(clean), 100.0 * len(clean) / total, len(dirty), len(errors)))

    if histogram:
        print("\n=== unmapped constructs by frequency ===")
        for construct, n in histogram.most_common(60):
            print("%5d  %s" % (n, construct))

    if dirty:
        print("\n=== worst scripts (most unmapped) ===")
        for rel, obj, warns, _ in sorted(dirty, key=lambda r: -len(r[2]))[:25]:
            print("%4d  %s" % (len(warns), rel))

    if errors:
        print("\n=== parse errors ===")
        for rel, obj, _, err in errors:
            print("  %s: %s" % (rel, err))

    if emit is None:
        return

    # ---- include list --------------------------------------------------
    inc = ["// AUTO-GENERATED by batch_transpile.py — do not edit.",
           "#ifndef NATIVE_OBJECTS_GEN_H", "#define NATIVE_OBJECTS_GEN_H", ""]
    for rel, obj, names in emitted:
        inc.append('#include "Gen/%s.hpp"' % obj)
    inc += ["", "#endif", ""]
    with open(os.path.join(emit, "..", "NativeObjectsGen.hpp"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(inc))

    # ---- registry rows (script-path keyed) ------------------------------
    rows = ["// AUTO-GENERATED by batch_transpile.py — do not edit.",
            "// { scriptPath, name, subMain, subPlayerInteraction, subDraw, subSetup, funcs, funcCount }"]
    for rel, obj, names in emitted:
        slot = {"subMain": "nullptr", "subPlayerInteraction": "nullptr",
                "subDraw": "nullptr", "subSetup": "nullptr"}
        for n in names:
            if n in rs.SUB2HOOK:
                slot[rs.SUB2HOOK[n]] = "%s::%s" % (obj, rs.cpp_ident(n))
        pub = [n for n in names if n not in rs.SUB2HOOK]
        funcs = ("%s::funcs" % obj, str(len(pub))) if pub else ("nullptr", "0")
        display = os.path.splitext(os.path.basename(rel))[0]
        rows.append('{ "%s", "%s", %s, %s, %s, %s, %s, %s },'
                    % (rel, display, slot["subMain"], slot["subPlayerInteraction"],
                       slot["subDraw"], slot["subSetup"], funcs[0], funcs[1]))
    with open(os.path.join(emit, "..", "NativeRegistryGen.inl"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(rows) + "\n")

    # ---- unity aggregation files ----------------------------------------
    # Deterministic round-robin so a single object's change rebuilds only its
    # bucket, and buckets stay evenly sized for parallel compilation.
    ordered = sorted(emitted, key=lambda e: e[1])  # by object name
    buckets = [[] for _ in range(UNITY_BUCKETS)]
    for i, e in enumerate(ordered):
        buckets[i % UNITY_BUCKETS].append(e)

    unity_names = []
    for b, group in enumerate(buckets):
        if not group:
            continue
        uname = "NativeGenUnity%02d" % b
        unity_names.append(uname)
        lines = ["// AUTO-GENERATED by batch_transpile.py — unity build bucket. Do not edit.",
                 "// Aggregates %d transpiled objects into one translation unit." % len(group), ""]
        for rel, obj, names in group:
            lines.append('#include "Gen/%s.cpp"' % obj)
        lines.append("")
        rs._write_if_changed(os.path.join(emit, "..", uname + ".cpp"), "\n".join(lines))

    # ---- CMake source list (unity TUs, not the individual objects) ------
    cm = ["# AUTO-GENERATED by batch_transpile.py — do not edit.",
          "set(NATIVE_GEN_SOURCES"]
    for uname in unity_names:
        cm.append("    RSDKv3/Native/%s.cpp" % uname)
    cm += [")", ""]
    with open(os.path.join(emit, "..", "gen_sources.cmake"), "w", encoding="utf-8") as fh:
        fh.write("\n".join(cm))

    print("\nemitted %d objects in %d unity TUs to %s (+ NativeObjectsGen.hpp, NativeRegistryGen.inl, gen_sources.cmake)"
          % (len(emitted), len(unity_names), emit))


if __name__ == "__main__":
    main()
