#include "RetroEngine.hpp"
#if RETRO_USE_NATIVE_OBJECTS

#include "O_R5_R5DEffect.hpp"
#include "GameConstants.hpp"
#include "PlayerConstants.hpp"
#include "PlayerFields.hpp"
#include "NativeScriptOps.hpp"

using namespace Native;

// AUTO-GENERATED from R5DEffect.txt by retroscript2cpp.py. Faithful transliteration;
// review, then move to hand-maintained once verified.

void O_R5_R5DEffect::ObjectStartup()
{
    objectEntityList[21].type = TypeNameID("BGEffect");
    objectEntityList[21].priority = 1;
}

void O_R5_R5DEffect::ObjectMain()
{
    Entity *self = Self();

    self->values[0]++;
    if (self->values[0] > 3) {
        self->values[0] = 0;
        self->frame++;
        self->frame &= 3;
        switch (self->frame) {
            case 0:
            Copy16x16Tile(792, 940);
            Copy16x16Tile(793, 944);
            Copy16x16Tile(794, 948);
            Copy16x16Tile(845, 952);
            Copy16x16Tile(846, 956);
            Copy16x16Tile(852, 960);
            Copy16x16Tile(853, 964);
            Copy16x16Tile(862, 968);
            Copy16x16Tile(863, 972);
            Copy16x16Tile(868, 976);
            Copy16x16Tile(869, 980);
            Copy16x16Tile(894, 984);
            Copy16x16Tile(895, 988);
            Copy16x16Tile(912, 992);
            Copy16x16Tile(913, 996);
            Copy16x16Tile(923, 1000);
            break;
            case 1:
            Copy16x16Tile(792, 941);
            Copy16x16Tile(793, 945);
            Copy16x16Tile(794, 949);
            Copy16x16Tile(845, 953);
            Copy16x16Tile(846, 957);
            Copy16x16Tile(852, 961);
            Copy16x16Tile(853, 965);
            Copy16x16Tile(862, 969);
            Copy16x16Tile(863, 973);
            Copy16x16Tile(868, 977);
            Copy16x16Tile(869, 981);
            Copy16x16Tile(894, 985);
            Copy16x16Tile(895, 989);
            Copy16x16Tile(912, 993);
            Copy16x16Tile(913, 997);
            Copy16x16Tile(923, 1001);
            break;
            case 2:
            Copy16x16Tile(792, 942);
            Copy16x16Tile(793, 946);
            Copy16x16Tile(794, 950);
            Copy16x16Tile(845, 954);
            Copy16x16Tile(846, 958);
            Copy16x16Tile(852, 962);
            Copy16x16Tile(853, 966);
            Copy16x16Tile(862, 970);
            Copy16x16Tile(863, 974);
            Copy16x16Tile(868, 978);
            Copy16x16Tile(869, 982);
            Copy16x16Tile(894, 986);
            Copy16x16Tile(895, 990);
            Copy16x16Tile(912, 994);
            Copy16x16Tile(913, 998);
            Copy16x16Tile(923, 1002);
            break;
            case 3:
            Copy16x16Tile(792, 943);
            Copy16x16Tile(793, 947);
            Copy16x16Tile(794, 951);
            Copy16x16Tile(845, 955);
            Copy16x16Tile(846, 959);
            Copy16x16Tile(852, 963);
            Copy16x16Tile(853, 967);
            Copy16x16Tile(862, 971);
            Copy16x16Tile(863, 975);
            Copy16x16Tile(868, 979);
            Copy16x16Tile(869, 983);
            Copy16x16Tile(894, 987);
            Copy16x16Tile(895, 991);
            Copy16x16Tile(912, 995);
            Copy16x16Tile(913, 999);
            Copy16x16Tile(923, 1003);
            break;
        }
    }
}

#endif // RETRO_USE_NATIVE_OBJECTS
