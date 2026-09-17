// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * v881);
struct StateT * slot_143(struct StateT * v2977);
struct StateT * slot_120(struct StateT * v2609);
struct StateT * slot_167(struct StateT * v3361);
struct StateT * slot_152(struct StateT * v3121);
struct StateT * slot_199(struct StateT * v3873);
struct StateT * slot_92(struct StateT * v2161);
struct StateT * slot_31(struct StateT * v1185);
struct StateT * slot_160(struct StateT * v3249);
struct StateT * slot_65(struct StateT * v1729);
struct StateT * slot_10(struct StateT * v849);
struct StateT * slot_150(struct StateT * v3089);
struct StateT * slot_74(struct StateT * v1873);
struct StateT * slot_107(struct StateT * v2401);
struct StateT * slot_136(struct StateT * v2865);
struct StateT * slot_84(struct StateT * v2033);
struct StateT * slot_28(struct StateT * v1137);
struct StateT * slot_155(struct StateT * v3169);
struct StateT * slot_177(struct StateT * v3521);
struct StateT * slot_17(struct StateT * v961);
struct StateT * slot_181(struct StateT * v3585);
struct StateT * slot_197(struct StateT * v3841);
struct StateT * slot_207(struct StateT * v4001);
struct StateT * slot_156(struct StateT * v3185);
struct StateT * slot_154(struct StateT * v3153);
struct StateT * slot_68(struct StateT * v1777);
struct StateT * slot_105(struct StateT * v2369);
struct StateT * slot_27(struct StateT * v1121);
struct StateT * slot_164(struct StateT * v3313);
struct StateT * slot_15(struct StateT * v929);
struct StateT * slot_133(struct StateT * v2817);
struct StateT * slot_56(struct StateT * v1585);
struct StateT * slot_222(struct StateT * v4241);
struct StateT * slot_34(struct StateT * v1233);
struct StateT * slot_171(struct StateT * v3425);
struct StateT * slot_162(struct StateT * v3281);
struct StateT * slot_21(struct StateT * v1025);
struct StateT * slot_118(struct StateT * v2577);
struct StateT * slot_121(struct StateT * v2625);
struct StateT * slot_144(struct StateT * v2993);
struct StateT * slot_201(struct StateT * v3905);
struct StateT * slot_94(struct StateT * v2193);
struct StateT * slot_63(struct StateT * v1697);
struct StateT * slot_146(struct StateT * v3025);
struct StateT * slot_24(struct StateT * v1073);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v3809);
struct StateT * slot_125(struct StateT * v2689);
struct StateT * slot_148(struct StateT * v3057);
struct StateT * slot_126(struct StateT * v2705);
struct StateT * slot_223(struct StateT * v4257);
struct StateT * slot_79(struct StateT * v1953);
struct StateT * slot_41(struct StateT * v1345);
struct StateT * slot_39(struct StateT * v1313);
struct StateT * slot_142(struct StateT * v2961);
struct StateT * slot_60(struct StateT * v1649);
struct StateT * slot_112(struct StateT * v2481);
struct StateT * slot_47(struct StateT * v1441);
struct StateT * slot_214(struct StateT * v4113);
struct StateT * slot_29(struct StateT * v1153);
struct StateT * slot_16(struct StateT * v945);
struct StateT * slot_113(struct StateT * v2497);
struct StateT * slot_151(struct StateT * v3105);
struct StateT * slot_7(struct StateT * v801);
struct StateT * slot_124(struct StateT * v2673);
struct StateT * slot_191(struct StateT * v3745);
struct StateT * slot_103(struct StateT * v2337);
struct StateT * slot_128(struct StateT * v2737);
struct StateT * slot_19(struct StateT * v993);
struct StateT * slot_87(struct StateT * v2081);
struct StateT * slot_67(struct StateT * v1761);
struct StateT * slot_81(struct StateT * v1985);
struct StateT * slot_95(struct StateT * v2209);
struct StateT * slot_115(struct StateT * v2529);
struct StateT * slot_78(struct StateT * v1937);
struct StateT * slot_32(struct StateT * v1201);
struct StateT * slot_205(struct StateT * v3969);
struct StateT * slot_193(struct StateT * v3777);
struct StateT * slot_176(struct StateT * v3505);
struct StateT * slot_189(struct StateT * v3713);
struct StateT * slot_33(struct StateT * v1217);
struct StateT * slot_35(struct StateT * v1249);
struct StateT * slot_210(struct StateT * v4049);
struct StateT * slot_166(struct StateT * v3345);
struct StateT * slot_51(struct StateT * v1505);
struct StateT * slot_52(struct StateT * v1521);
struct StateT * slot_83(struct StateT * v2017);
struct StateT * slot_25(struct StateT * v1089);
struct StateT * slot_209(struct StateT * v4033);
struct StateT * slot_3(struct StateT * v506);
struct StateT * slot_123(struct StateT * v2657);
struct StateT * slot_73(struct StateT * v1857);
struct StateT * slot_198(struct StateT * v3857);
struct StateT * slot_1(struct StateT * v252);
struct StateT * slot_187(struct StateT * v3681);
struct StateT * slot_97(struct StateT * v2241);
struct StateT * slot_182(struct StateT * v3601);
struct StateT * slot_38(struct StateT * v1297);
struct StateT * slot_178(struct StateT * v3537);
struct StateT * slot_106(struct StateT * v2385);
struct StateT * slot_98(struct StateT * v2257);
struct StateT * slot_159(struct StateT * v3233);
struct StateT * slot_46(struct StateT * v1425);
struct StateT * slot_212(struct StateT * v4081);
struct StateT * slot_132(struct StateT * v2801);
struct StateT * slot_130(struct StateT * v2769);
struct StateT * slot_211(struct StateT * v4065);
struct StateT * slot_20(struct StateT * v1009);
struct StateT * slot_141(struct StateT * v2945);
struct StateT * slot_61(struct StateT * v1665);
struct StateT * slot_30(struct StateT * v1169);
struct StateT * slot_4(struct StateT * v522);
struct StateT * slot_18(struct StateT * v977);
struct StateT * slot_9(struct StateT * v833);
struct StateT * slot_183(struct StateT * v3617);
struct StateT * slot_43(struct StateT * v1377);
struct StateT * slot_70(struct StateT * v1809);
struct StateT * slot_168(struct StateT * v3377);
struct StateT * slot_76(struct StateT * v1905);
struct StateT * slot_6(struct StateT * v785);
struct StateT * slot_225(struct StateT * v4289);
struct StateT * slot_55(struct StateT * v1569);
struct StateT * slot_213(struct StateT * v4097);
struct StateT * slot_82(struct StateT * v2001);
struct StateT * slot_161(struct StateT * v3265);
struct StateT * slot_185(struct StateT * v3649);
struct StateT * slot_91(struct StateT * v2145);
struct StateT * slot_58(struct StateT * v1617);
struct StateT * slot_89(struct StateT * v2113);
struct StateT * slot_66(struct StateT * v1745);
struct StateT * slot_140(struct StateT * v2929);
struct StateT * slot_49(struct StateT * v1473);
struct StateT * slot_216(struct StateT * v4145);
struct StateT * slot_50(struct StateT * v1489);
struct StateT * slot_37(struct StateT * v1281);
struct StateT * slot_114(struct StateT * v2513);
struct StateT * slot_135(struct StateT * v2849);
struct StateT * slot_59(struct StateT * v1633);
struct StateT * slot_192(struct StateT * v3761);
struct StateT * slot_40(struct StateT * v1329);
struct StateT * slot_48(struct StateT * v1457);
struct StateT * slot_77(struct StateT * v1921);
struct StateT * slot_85(struct StateT * v2049);
struct StateT * slot_75(struct StateT * v1889);
struct StateT * slot_72(struct StateT * v1841);
struct StateT * slot_119(struct StateT * v2593);
struct StateT * slot_71(struct StateT * v1825);
struct StateT * slot_101(struct StateT * v2305);
struct StateT * slot_108(struct StateT * v2417);
struct StateT * slot_116(struct StateT * v2545);
struct StateT * slot_93(struct StateT * v2177);
struct StateT * slot_88(struct StateT * v2097);
struct StateT * slot_96(struct StateT * v2225);
struct StateT * slot_215(struct StateT * v4129);
struct StateT * slot_45(struct StateT * v1409);
struct StateT * slot_218(struct StateT * v4177);
struct StateT * slot_220(struct StateT * v4209);
struct StateT * slot_134(struct StateT * v2833);
struct StateT * slot_175(struct StateT * v3489);
struct StateT * slot_69(struct StateT * v1793);
struct StateT * slot_202(struct StateT * v3921);
struct StateT * slot_188(struct StateT * v3697);
struct StateT * slot_138(struct StateT * v2897);
struct StateT * slot_186(struct StateT * v3665);
struct StateT * slot_102(struct StateT * v2321);
struct StateT * slot_145(struct StateT * v3009);
struct StateT * slot_110(struct StateT * v2449);
struct StateT * slot_196(struct StateT * v3825);
struct StateT * slot_208(struct StateT * v4017);
struct StateT * slot_172(struct StateT * v3441);
struct StateT * slot_131(struct StateT * v2785);
struct StateT * slot_8(struct StateT * v817);
struct StateT * slot_180(struct StateT * v3569);
struct StateT * slot_203(struct StateT * v3937);
struct StateT * slot_190(struct StateT * v3729);
struct StateT * slot_157(struct StateT * v3201);
struct StateT * slot_200(struct StateT * v3889);
struct StateT * slot_173(struct StateT * v3457);
struct StateT * slot_149(struct StateT * v3073);
struct StateT * slot_5(struct StateT * v772);
struct StateT * slot_104(struct StateT * v2353);
struct StateT * slot_54(struct StateT * v1553);
struct StateT * slot_26(struct StateT * v1105);
struct StateT * slot_206(struct StateT * v3985);
struct StateT * slot_169(struct StateT * v3393);
struct StateT * slot_64(struct StateT * v1713);
struct StateT * slot_170(struct StateT * v3409);
struct StateT * slot_14(struct StateT * v913);
struct StateT * slot_53(struct StateT * v1537);
struct StateT * slot_80(struct StateT * v1969);
struct StateT * slot_44(struct StateT * v1393);
struct StateT * slot_137(struct StateT * v2881);
struct StateT * slot_122(struct StateT * v2641);
struct StateT * slot_99(struct StateT * v2273);
struct StateT * slot_179(struct StateT * v3553);
struct StateT * slot_219(struct StateT * v4193);
struct StateT * slot_36(struct StateT * v1265);
struct StateT * slot_57(struct StateT * v1601);
struct StateT * slot_62(struct StateT * v1681);
struct StateT * slot_22(struct StateT * v1041);
struct StateT * slot_139(struct StateT * v2913);
struct StateT * slot_221(struct StateT * v4225);
struct StateT * slot_23(struct StateT * v1057);
struct StateT * slot_153(struct StateT * v3137);
struct StateT * slot_2(struct StateT * v490);
struct StateT * slot_86(struct StateT * v2065);
struct StateT * slot_129(struct StateT * v2753);
struct StateT * slot_158(struct StateT * v3217);
struct StateT * slot_100(struct StateT * v2289);
struct StateT * slot_127(struct StateT * v2721);
struct StateT * slot_217(struct StateT * v4161);
struct StateT * slot_13(struct StateT * v897);
struct StateT * slot_111(struct StateT * v2465);
struct StateT * slot_109(struct StateT * v2433);
struct StateT * slot_174(struct StateT * v3473);
struct StateT * slot_147(struct StateT * v3041);
struct StateT * slot_42(struct StateT * v1361);
struct StateT * slot_224(struct StateT * v4273);
struct StateT * slot_163(struct StateT * v3297);
struct StateT * slot_184(struct StateT * v3633);
struct StateT * slot_204(struct StateT * v3953);
struct StateT * slot_194(struct StateT * v3793);
struct StateT * slot_165(struct StateT * v3329);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v2561);
struct StateT * slot_90(struct StateT * v2129);
struct StateT * slot_11(struct StateT * v865);
struct StateT * slot_12(struct StateT * v881) {
  int v882 = v881->timer;
  int v890 = v882 + 1;
  v881->timer = v890;
  int * v884 = v881->regs;
  int v885 = v884[8];
  int * v886 = v881->regs;
  int v894 = v885 + 1;
  v886[8] = v894;
  struct StateT * v888 = slot_13(v881);
  return v888;
}

struct StateT * slot_143(struct StateT * v2977) {
  int v2978 = v2977->timer;
  int v2986 = v2978 + 1;
  v2977->timer = v2986;
  int * v2980 = v2977->regs;
  int v2981 = v2980[8];
  int * v2982 = v2977->regs;
  int v2990 = v2981 + 1;
  v2982[8] = v2990;
  struct StateT * v2984 = slot_144(v2977);
  return v2984;
}

struct StateT * slot_120(struct StateT * v2609) {
  int v2610 = v2609->timer;
  int v2618 = v2610 + 1;
  v2609->timer = v2618;
  int * v2612 = v2609->regs;
  int v2613 = v2612[8];
  int * v2614 = v2609->regs;
  int v2622 = v2613 + 1;
  v2614[8] = v2622;
  struct StateT * v2616 = slot_121(v2609);
  return v2616;
}

struct StateT * slot_167(struct StateT * v3361) {
  int v3362 = v3361->timer;
  int v3370 = v3362 + 1;
  v3361->timer = v3370;
  int * v3364 = v3361->regs;
  int v3365 = v3364[8];
  int * v3366 = v3361->regs;
  int v3374 = v3365 + 1;
  v3366[8] = v3374;
  struct StateT * v3368 = slot_168(v3361);
  return v3368;
}

struct StateT * slot_152(struct StateT * v3121) {
  int v3122 = v3121->timer;
  int v3130 = v3122 + 1;
  v3121->timer = v3130;
  int * v3124 = v3121->regs;
  int v3125 = v3124[8];
  int * v3126 = v3121->regs;
  int v3134 = v3125 + 1;
  v3126[8] = v3134;
  struct StateT * v3128 = slot_153(v3121);
  return v3128;
}

struct StateT * slot_199(struct StateT * v3873) {
  int v3874 = v3873->timer;
  int v3882 = v3874 + 1;
  v3873->timer = v3882;
  int * v3876 = v3873->regs;
  int v3877 = v3876[8];
  int * v3878 = v3873->regs;
  int v3886 = v3877 + 1;
  v3878[8] = v3886;
  struct StateT * v3880 = slot_200(v3873);
  return v3880;
}

struct StateT * slot_92(struct StateT * v2161) {
  int v2162 = v2161->timer;
  int v2170 = v2162 + 1;
  v2161->timer = v2170;
  int * v2164 = v2161->regs;
  int v2165 = v2164[8];
  int * v2166 = v2161->regs;
  int v2174 = v2165 + 1;
  v2166[8] = v2174;
  struct StateT * v2168 = slot_93(v2161);
  return v2168;
}

struct StateT * slot_31(struct StateT * v1185) {
  int v1186 = v1185->timer;
  int v1194 = v1186 + 1;
  v1185->timer = v1194;
  int * v1188 = v1185->regs;
  int v1189 = v1188[8];
  int * v1190 = v1185->regs;
  int v1198 = v1189 + 1;
  v1190[8] = v1198;
  struct StateT * v1192 = slot_32(v1185);
  return v1192;
}

struct StateT * slot_160(struct StateT * v3249) {
  int v3250 = v3249->timer;
  int v3258 = v3250 + 1;
  v3249->timer = v3258;
  int * v3252 = v3249->regs;
  int v3253 = v3252[8];
  int * v3254 = v3249->regs;
  int v3262 = v3253 + 1;
  v3254[8] = v3262;
  struct StateT * v3256 = slot_161(v3249);
  return v3256;
}

struct StateT * slot_65(struct StateT * v1729) {
  int v1730 = v1729->timer;
  int v1738 = v1730 + 1;
  v1729->timer = v1738;
  int * v1732 = v1729->regs;
  int v1733 = v1732[8];
  int * v1734 = v1729->regs;
  int v1742 = v1733 + 1;
  v1734[8] = v1742;
  struct StateT * v1736 = slot_66(v1729);
  return v1736;
}

struct StateT * slot_10(struct StateT * v849) {
  int v850 = v849->timer;
  int v858 = v850 + 1;
  v849->timer = v858;
  int * v852 = v849->regs;
  int v853 = v852[8];
  int * v854 = v849->regs;
  int v862 = v853 + 1;
  v854[8] = v862;
  struct StateT * v856 = slot_11(v849);
  return v856;
}

struct StateT * slot_150(struct StateT * v3089) {
  int v3090 = v3089->timer;
  int v3098 = v3090 + 1;
  v3089->timer = v3098;
  int * v3092 = v3089->regs;
  int v3093 = v3092[8];
  int * v3094 = v3089->regs;
  int v3102 = v3093 + 1;
  v3094[8] = v3102;
  struct StateT * v3096 = slot_151(v3089);
  return v3096;
}

struct StateT * slot_74(struct StateT * v1873) {
  int v1874 = v1873->timer;
  int v1882 = v1874 + 1;
  v1873->timer = v1882;
  int * v1876 = v1873->regs;
  int v1877 = v1876[8];
  int * v1878 = v1873->regs;
  int v1886 = v1877 + 1;
  v1878[8] = v1886;
  struct StateT * v1880 = slot_75(v1873);
  return v1880;
}

struct StateT * slot_107(struct StateT * v2401) {
  int v2402 = v2401->timer;
  int v2410 = v2402 + 1;
  v2401->timer = v2410;
  int * v2404 = v2401->regs;
  int v2405 = v2404[8];
  int * v2406 = v2401->regs;
  int v2414 = v2405 + 1;
  v2406[8] = v2414;
  struct StateT * v2408 = slot_108(v2401);
  return v2408;
}

struct StateT * slot_136(struct StateT * v2865) {
  int v2866 = v2865->timer;
  int v2874 = v2866 + 1;
  v2865->timer = v2874;
  int * v2868 = v2865->regs;
  int v2869 = v2868[8];
  int * v2870 = v2865->regs;
  int v2878 = v2869 + 1;
  v2870[8] = v2878;
  struct StateT * v2872 = slot_137(v2865);
  return v2872;
}

struct StateT * slot_84(struct StateT * v2033) {
  int v2034 = v2033->timer;
  int v2042 = v2034 + 1;
  v2033->timer = v2042;
  int * v2036 = v2033->regs;
  int v2037 = v2036[8];
  int * v2038 = v2033->regs;
  int v2046 = v2037 + 1;
  v2038[8] = v2046;
  struct StateT * v2040 = slot_85(v2033);
  return v2040;
}

struct StateT * slot_28(struct StateT * v1137) {
  int v1138 = v1137->timer;
  int v1146 = v1138 + 1;
  v1137->timer = v1146;
  int * v1140 = v1137->regs;
  int v1141 = v1140[8];
  int * v1142 = v1137->regs;
  int v1150 = v1141 + 1;
  v1142[8] = v1150;
  struct StateT * v1144 = slot_29(v1137);
  return v1144;
}

struct StateT * slot_155(struct StateT * v3169) {
  int v3170 = v3169->timer;
  int v3178 = v3170 + 1;
  v3169->timer = v3178;
  int * v3172 = v3169->regs;
  int v3173 = v3172[8];
  int * v3174 = v3169->regs;
  int v3182 = v3173 + 1;
  v3174[8] = v3182;
  struct StateT * v3176 = slot_156(v3169);
  return v3176;
}

struct StateT * slot_177(struct StateT * v3521) {
  int v3522 = v3521->timer;
  int v3530 = v3522 + 1;
  v3521->timer = v3530;
  int * v3524 = v3521->regs;
  int v3525 = v3524[8];
  int * v3526 = v3521->regs;
  int v3534 = v3525 + 1;
  v3526[8] = v3534;
  struct StateT * v3528 = slot_178(v3521);
  return v3528;
}

struct StateT * slot_17(struct StateT * v961) {
  int v962 = v961->timer;
  int v970 = v962 + 1;
  v961->timer = v970;
  int * v964 = v961->regs;
  int v965 = v964[8];
  int * v966 = v961->regs;
  int v974 = v965 + 1;
  v966[8] = v974;
  struct StateT * v968 = slot_18(v961);
  return v968;
}

struct StateT * slot_181(struct StateT * v3585) {
  int v3586 = v3585->timer;
  int v3594 = v3586 + 1;
  v3585->timer = v3594;
  int * v3588 = v3585->regs;
  int v3589 = v3588[8];
  int * v3590 = v3585->regs;
  int v3598 = v3589 + 1;
  v3590[8] = v3598;
  struct StateT * v3592 = slot_182(v3585);
  return v3592;
}

struct StateT * slot_197(struct StateT * v3841) {
  int v3842 = v3841->timer;
  int v3850 = v3842 + 1;
  v3841->timer = v3850;
  int * v3844 = v3841->regs;
  int v3845 = v3844[8];
  int * v3846 = v3841->regs;
  int v3854 = v3845 + 1;
  v3846[8] = v3854;
  struct StateT * v3848 = slot_198(v3841);
  return v3848;
}

struct StateT * slot_207(struct StateT * v4001) {
  int v4002 = v4001->timer;
  int v4010 = v4002 + 1;
  v4001->timer = v4010;
  int * v4004 = v4001->regs;
  int v4005 = v4004[8];
  int * v4006 = v4001->regs;
  int v4014 = v4005 + 1;
  v4006[8] = v4014;
  struct StateT * v4008 = slot_208(v4001);
  return v4008;
}

struct StateT * slot_156(struct StateT * v3185) {
  int v3186 = v3185->timer;
  int v3194 = v3186 + 1;
  v3185->timer = v3194;
  int * v3188 = v3185->regs;
  int v3189 = v3188[8];
  int * v3190 = v3185->regs;
  int v3198 = v3189 + 1;
  v3190[8] = v3198;
  struct StateT * v3192 = slot_157(v3185);
  return v3192;
}

struct StateT * slot_154(struct StateT * v3153) {
  int v3154 = v3153->timer;
  int v3162 = v3154 + 1;
  v3153->timer = v3162;
  int * v3156 = v3153->regs;
  int v3157 = v3156[8];
  int * v3158 = v3153->regs;
  int v3166 = v3157 + 1;
  v3158[8] = v3166;
  struct StateT * v3160 = slot_155(v3153);
  return v3160;
}

struct StateT * slot_68(struct StateT * v1777) {
  int v1778 = v1777->timer;
  int v1786 = v1778 + 1;
  v1777->timer = v1786;
  int * v1780 = v1777->regs;
  int v1781 = v1780[8];
  int * v1782 = v1777->regs;
  int v1790 = v1781 + 1;
  v1782[8] = v1790;
  struct StateT * v1784 = slot_69(v1777);
  return v1784;
}

struct StateT * slot_105(struct StateT * v2369) {
  int v2370 = v2369->timer;
  int v2378 = v2370 + 1;
  v2369->timer = v2378;
  int * v2372 = v2369->regs;
  int v2373 = v2372[8];
  int * v2374 = v2369->regs;
  int v2382 = v2373 + 1;
  v2374[8] = v2382;
  struct StateT * v2376 = slot_106(v2369);
  return v2376;
}

struct StateT * slot_27(struct StateT * v1121) {
  int v1122 = v1121->timer;
  int v1130 = v1122 + 1;
  v1121->timer = v1130;
  int * v1124 = v1121->regs;
  int v1125 = v1124[8];
  int * v1126 = v1121->regs;
  int v1134 = v1125 + 1;
  v1126[8] = v1134;
  struct StateT * v1128 = slot_28(v1121);
  return v1128;
}

struct StateT * slot_164(struct StateT * v3313) {
  int v3314 = v3313->timer;
  int v3322 = v3314 + 1;
  v3313->timer = v3322;
  int * v3316 = v3313->regs;
  int v3317 = v3316[8];
  int * v3318 = v3313->regs;
  int v3326 = v3317 + 1;
  v3318[8] = v3326;
  struct StateT * v3320 = slot_165(v3313);
  return v3320;
}

struct StateT * slot_15(struct StateT * v929) {
  int v930 = v929->timer;
  int v938 = v930 + 1;
  v929->timer = v938;
  int * v932 = v929->regs;
  int v933 = v932[8];
  int * v934 = v929->regs;
  int v942 = v933 + 1;
  v934[8] = v942;
  struct StateT * v936 = slot_16(v929);
  return v936;
}

struct StateT * slot_133(struct StateT * v2817) {
  int v2818 = v2817->timer;
  int v2826 = v2818 + 1;
  v2817->timer = v2826;
  int * v2820 = v2817->regs;
  int v2821 = v2820[8];
  int * v2822 = v2817->regs;
  int v2830 = v2821 + 1;
  v2822[8] = v2830;
  struct StateT * v2824 = slot_134(v2817);
  return v2824;
}

struct StateT * slot_56(struct StateT * v1585) {
  int v1586 = v1585->timer;
  int v1594 = v1586 + 1;
  v1585->timer = v1594;
  int * v1588 = v1585->regs;
  int v1589 = v1588[8];
  int * v1590 = v1585->regs;
  int v1598 = v1589 + 1;
  v1590[8] = v1598;
  struct StateT * v1592 = slot_57(v1585);
  return v1592;
}

struct StateT * slot_222(struct StateT * v4241) {
  int v4242 = v4241->timer;
  int v4250 = v4242 + 1;
  v4241->timer = v4250;
  int * v4244 = v4241->regs;
  int v4245 = v4244[8];
  int * v4246 = v4241->regs;
  int v4254 = v4245 + 1;
  v4246[8] = v4254;
  struct StateT * v4248 = slot_223(v4241);
  return v4248;
}

struct StateT * slot_34(struct StateT * v1233) {
  int v1234 = v1233->timer;
  int v1242 = v1234 + 1;
  v1233->timer = v1242;
  int * v1236 = v1233->regs;
  int v1237 = v1236[8];
  int * v1238 = v1233->regs;
  int v1246 = v1237 + 1;
  v1238[8] = v1246;
  struct StateT * v1240 = slot_35(v1233);
  return v1240;
}

struct StateT * slot_171(struct StateT * v3425) {
  int v3426 = v3425->timer;
  int v3434 = v3426 + 1;
  v3425->timer = v3434;
  int * v3428 = v3425->regs;
  int v3429 = v3428[8];
  int * v3430 = v3425->regs;
  int v3438 = v3429 + 1;
  v3430[8] = v3438;
  struct StateT * v3432 = slot_172(v3425);
  return v3432;
}

struct StateT * slot_162(struct StateT * v3281) {
  int v3282 = v3281->timer;
  int v3290 = v3282 + 1;
  v3281->timer = v3290;
  int * v3284 = v3281->regs;
  int v3285 = v3284[8];
  int * v3286 = v3281->regs;
  int v3294 = v3285 + 1;
  v3286[8] = v3294;
  struct StateT * v3288 = slot_163(v3281);
  return v3288;
}

struct StateT * slot_21(struct StateT * v1025) {
  int v1026 = v1025->timer;
  int v1034 = v1026 + 1;
  v1025->timer = v1034;
  int * v1028 = v1025->regs;
  int v1029 = v1028[8];
  int * v1030 = v1025->regs;
  int v1038 = v1029 + 1;
  v1030[8] = v1038;
  struct StateT * v1032 = slot_22(v1025);
  return v1032;
}

struct StateT * slot_118(struct StateT * v2577) {
  int v2578 = v2577->timer;
  int v2586 = v2578 + 1;
  v2577->timer = v2586;
  int * v2580 = v2577->regs;
  int v2581 = v2580[8];
  int * v2582 = v2577->regs;
  int v2590 = v2581 + 1;
  v2582[8] = v2590;
  struct StateT * v2584 = slot_119(v2577);
  return v2584;
}

struct StateT * slot_121(struct StateT * v2625) {
  int v2626 = v2625->timer;
  int v2634 = v2626 + 1;
  v2625->timer = v2634;
  int * v2628 = v2625->regs;
  int v2629 = v2628[8];
  int * v2630 = v2625->regs;
  int v2638 = v2629 + 1;
  v2630[8] = v2638;
  struct StateT * v2632 = slot_122(v2625);
  return v2632;
}

struct StateT * slot_144(struct StateT * v2993) {
  int v2994 = v2993->timer;
  int v3002 = v2994 + 1;
  v2993->timer = v3002;
  int * v2996 = v2993->regs;
  int v2997 = v2996[8];
  int * v2998 = v2993->regs;
  int v3006 = v2997 + 1;
  v2998[8] = v3006;
  struct StateT * v3000 = slot_145(v2993);
  return v3000;
}

struct StateT * slot_201(struct StateT * v3905) {
  int v3906 = v3905->timer;
  int v3914 = v3906 + 1;
  v3905->timer = v3914;
  int * v3908 = v3905->regs;
  int v3909 = v3908[8];
  int * v3910 = v3905->regs;
  int v3918 = v3909 + 1;
  v3910[8] = v3918;
  struct StateT * v3912 = slot_202(v3905);
  return v3912;
}

struct StateT * slot_94(struct StateT * v2193) {
  int v2194 = v2193->timer;
  int v2202 = v2194 + 1;
  v2193->timer = v2202;
  int * v2196 = v2193->regs;
  int v2197 = v2196[8];
  int * v2198 = v2193->regs;
  int v2206 = v2197 + 1;
  v2198[8] = v2206;
  struct StateT * v2200 = slot_95(v2193);
  return v2200;
}

struct StateT * slot_63(struct StateT * v1697) {
  int v1698 = v1697->timer;
  int v1706 = v1698 + 1;
  v1697->timer = v1706;
  int * v1700 = v1697->regs;
  int v1701 = v1700[8];
  int * v1702 = v1697->regs;
  int v1710 = v1701 + 1;
  v1702[8] = v1710;
  struct StateT * v1704 = slot_64(v1697);
  return v1704;
}

struct StateT * slot_146(struct StateT * v3025) {
  int v3026 = v3025->timer;
  int v3034 = v3026 + 1;
  v3025->timer = v3034;
  int * v3028 = v3025->regs;
  int v3029 = v3028[8];
  int * v3030 = v3025->regs;
  int v3038 = v3029 + 1;
  v3030[8] = v3038;
  struct StateT * v3032 = slot_147(v3025);
  return v3032;
}

struct StateT * slot_24(struct StateT * v1073) {
  int v1074 = v1073->timer;
  int v1082 = v1074 + 1;
  v1073->timer = v1082;
  int * v1076 = v1073->regs;
  int v1077 = v1076[8];
  int * v1078 = v1073->regs;
  int v1086 = v1077 + 1;
  v1078[8] = v1086;
  struct StateT * v1080 = slot_25(v1073);
  return v1080;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v136 = v3 + 1;
  v2->timer = v136;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->cache_tags;
  int v140 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v140];
  int * v9 = v2->cache_tags;
  int v142 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v10 = v9[v142];
  int * v11 = v2->cache_tags;
  int v144 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v12 = v11[v144];
  int * v13 = v2->cache_tags;
  int v146 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14 = v13[v146];
  int v15 = v2->timer;
  int v147 = v15 + ((100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v147;
  int * v17 = v2->cache_vals;
  bool v148 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v130;
  if (v148) {
    int * v18 = v2->cache_age;
    int v150 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v19 = v18[v150];
    int * v20 = v2->cache_age;
    int v21 = v20[v140];
    int * v22 = v2->cache_age;
    int v153 = v21 + ((int)((unsigned int)(v21 - v19) >> 31));
    v22[v140] = v153;
    int * v24 = v2->cache_age;
    int v25 = v24[v142];
    int * v26 = v2->cache_age;
    int v156 = v25 + ((int)((unsigned int)(v25 - v19) >> 31));
    v26[v142] = v156;
    int * v28 = v2->cache_age;
    v28[v150] = 0;
    v130 = v150;
  } else {
    int * v31 = v2->cache_age;
    int v160 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v32 = v31[v160];
    int * v33 = v2->cache_tags;
    int v34 = v33[v160];
    int * v35 = v2->cache_age;
    int v36 = v35[v142];
    int * v37 = v2->cache_tags;
    int v38 = v37[v142];
    bool v164 = !(((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v102;
    if (v164) {
      int * v39 = v2->cache_age;
      int v166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v40 = v39[v166];
      int * v41 = v2->cache_age;
      int v42 = v41[v144];
      int * v43 = v2->cache_age;
      int v169 = v42 + ((int)((unsigned int)(v42 - v40) >> 31));
      v43[v144] = v169;
      int * v45 = v2->cache_age;
      int v46 = v45[v146];
      int * v47 = v2->cache_age;
      int v172 = v46 + ((int)((unsigned int)(v46 - v40) >> 31));
      v47[v146] = v172;
      int * v49 = v2->cache_age;
      v49[v166] = 0;
      v102 = v166;
    } else {
      int * v52 = v2->cache_age;
      int v176 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v53 = v52[v176];
      int * v54 = v2->cache_tags;
      int v55 = v54[v176];
      int * v56 = v2->cache_age;
      int v57 = v56[v146];
      int * v58 = v2->cache_tags;
      int v59 = v58[v146];
      int * v60 = v2->cache_dirty;
      int v181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v181];
      bool v182 = !(v61 == 0);
      if (v182) {
        int * v62 = v2->cache_tags;
        int v63 = v62[v181];
        int * v64 = v2->cache_vals;
        int v185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v185];
        int * v66 = v2->cache_vals;
        int v187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v66[v187];
        int * v68 = v2->mem;
        int v189 = v63 * 2;
        v68[v189] = v65;
        int * v70 = v2->mem;
        int v192 = (v63 * 2) + 1;
        v70[v192] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v2->mem;
      int v197 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v76 = v75[v197];
      int * v77 = v2->mem;
      int v199 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v78 = v77[v199];
      int * v79 = v2->cache_vals;
      int v201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v79[v201] = v76;
      int * v81 = v2->cache_vals;
      int v204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v81[v204] = v78;
      int * v83 = v2->cache_tags;
      int v207 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v83[v181] = v207;
      int * v85 = v2->cache_dirty;
      v85[v181] = 0;
      int * v87 = v2->cache_age;
      v87[v181] = 1;
      int * v89 = v2->cache_age;
      int v90 = v89[v181];
      int * v91 = v2->cache_age;
      int v92 = v91[v144];
      int * v93 = v2->cache_age;
      int v215 = v92 + ((int)((unsigned int)(v92 - v90) >> 31));
      v93[v144] = v215;
      int * v95 = v2->cache_age;
      int v96 = v95[v146];
      int * v97 = v2->cache_age;
      int v218 = v96 + ((int)((unsigned int)(v96 - v90) >> 31));
      v97[v146] = v218;
      int * v99 = v2->cache_age;
      v99[v181] = 0;
      v102 = v181;
    }
    int * v103 = v2->cache_vals;
    int v221 = v102 * 2;
    int v104 = v103[v221];
    int * v105 = v2->cache_vals;
    int v223 = (v102 * 2) + 1;
    int v106 = v105[v223];
    int * v107 = v2->cache_vals;
    int v225 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v107[v225] = v104;
    int * v109 = v2->cache_vals;
    int v228 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v109[v228] = v106;
    int * v111 = v2->cache_tags;
    int v231 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v232 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v111[v231] = v232;
    int * v113 = v2->cache_dirty;
    v113[v231] = 0;
    int * v115 = v2->cache_age;
    v115[v231] = 1;
    int * v117 = v2->cache_age;
    int v118 = v117[v231];
    int * v119 = v2->cache_age;
    int v120 = v119[v140];
    int * v121 = v2->cache_age;
    int v240 = v120 + ((int)((unsigned int)(v120 - v118) >> 31));
    v121[v140] = v240;
    int * v123 = v2->cache_age;
    int v124 = v123[v142];
    int * v125 = v2->cache_age;
    int v243 = v124 + ((int)((unsigned int)(v124 - v118) >> 31));
    v125[v142] = v243;
    int * v127 = v2->cache_age;
    v127[v231] = 0;
    v130 = v231;
  }
  int v246 = (v130 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v131 = v17[v246];
  int * v132 = v2->regs;
  v132[5] = v131;
  struct StateT * v134 = slot_1(v2);
  return v134;
}

struct StateT * slot_195(struct StateT * v3809) {
  int v3810 = v3809->timer;
  int v3818 = v3810 + 1;
  v3809->timer = v3818;
  int * v3812 = v3809->regs;
  int v3813 = v3812[8];
  int * v3814 = v3809->regs;
  int v3822 = v3813 + 1;
  v3814[8] = v3822;
  struct StateT * v3816 = slot_196(v3809);
  return v3816;
}

struct StateT * slot_125(struct StateT * v2689) {
  int v2690 = v2689->timer;
  int v2698 = v2690 + 1;
  v2689->timer = v2698;
  int * v2692 = v2689->regs;
  int v2693 = v2692[8];
  int * v2694 = v2689->regs;
  int v2702 = v2693 + 1;
  v2694[8] = v2702;
  struct StateT * v2696 = slot_126(v2689);
  return v2696;
}

struct StateT * slot_148(struct StateT * v3057) {
  int v3058 = v3057->timer;
  int v3066 = v3058 + 1;
  v3057->timer = v3066;
  int * v3060 = v3057->regs;
  int v3061 = v3060[8];
  int * v3062 = v3057->regs;
  int v3070 = v3061 + 1;
  v3062[8] = v3070;
  struct StateT * v3064 = slot_149(v3057);
  return v3064;
}

struct StateT * slot_126(struct StateT * v2705) {
  int v2706 = v2705->timer;
  int v2714 = v2706 + 1;
  v2705->timer = v2714;
  int * v2708 = v2705->regs;
  int v2709 = v2708[8];
  int * v2710 = v2705->regs;
  int v2718 = v2709 + 1;
  v2710[8] = v2718;
  struct StateT * v2712 = slot_127(v2705);
  return v2712;
}

struct StateT * slot_223(struct StateT * v4257) {
  int v4258 = v4257->timer;
  int v4266 = v4258 + 1;
  v4257->timer = v4266;
  int * v4260 = v4257->regs;
  int v4261 = v4260[8];
  int * v4262 = v4257->regs;
  int v4270 = v4261 + 1;
  v4262[8] = v4270;
  struct StateT * v4264 = slot_224(v4257);
  return v4264;
}

struct StateT * slot_79(struct StateT * v1953) {
  int v1954 = v1953->timer;
  int v1962 = v1954 + 1;
  v1953->timer = v1962;
  int * v1956 = v1953->regs;
  int v1957 = v1956[8];
  int * v1958 = v1953->regs;
  int v1966 = v1957 + 1;
  v1958[8] = v1966;
  struct StateT * v1960 = slot_80(v1953);
  return v1960;
}

struct StateT * slot_41(struct StateT * v1345) {
  int v1346 = v1345->timer;
  int v1354 = v1346 + 1;
  v1345->timer = v1354;
  int * v1348 = v1345->regs;
  int v1349 = v1348[8];
  int * v1350 = v1345->regs;
  int v1358 = v1349 + 1;
  v1350[8] = v1358;
  struct StateT * v1352 = slot_42(v1345);
  return v1352;
}

struct StateT * slot_39(struct StateT * v1313) {
  int v1314 = v1313->timer;
  int v1322 = v1314 + 1;
  v1313->timer = v1322;
  int * v1316 = v1313->regs;
  int v1317 = v1316[8];
  int * v1318 = v1313->regs;
  int v1326 = v1317 + 1;
  v1318[8] = v1326;
  struct StateT * v1320 = slot_40(v1313);
  return v1320;
}

struct StateT * slot_142(struct StateT * v2961) {
  int v2962 = v2961->timer;
  int v2970 = v2962 + 1;
  v2961->timer = v2970;
  int * v2964 = v2961->regs;
  int v2965 = v2964[8];
  int * v2966 = v2961->regs;
  int v2974 = v2965 + 1;
  v2966[8] = v2974;
  struct StateT * v2968 = slot_143(v2961);
  return v2968;
}

struct StateT * slot_60(struct StateT * v1649) {
  int v1650 = v1649->timer;
  int v1658 = v1650 + 1;
  v1649->timer = v1658;
  int * v1652 = v1649->regs;
  int v1653 = v1652[8];
  int * v1654 = v1649->regs;
  int v1662 = v1653 + 1;
  v1654[8] = v1662;
  struct StateT * v1656 = slot_61(v1649);
  return v1656;
}

struct StateT * slot_112(struct StateT * v2481) {
  int v2482 = v2481->timer;
  int v2490 = v2482 + 1;
  v2481->timer = v2490;
  int * v2484 = v2481->regs;
  int v2485 = v2484[8];
  int * v2486 = v2481->regs;
  int v2494 = v2485 + 1;
  v2486[8] = v2494;
  struct StateT * v2488 = slot_113(v2481);
  return v2488;
}

struct StateT * slot_47(struct StateT * v1441) {
  int v1442 = v1441->timer;
  int v1450 = v1442 + 1;
  v1441->timer = v1450;
  int * v1444 = v1441->regs;
  int v1445 = v1444[8];
  int * v1446 = v1441->regs;
  int v1454 = v1445 + 1;
  v1446[8] = v1454;
  struct StateT * v1448 = slot_48(v1441);
  return v1448;
}

struct StateT * slot_214(struct StateT * v4113) {
  int v4114 = v4113->timer;
  int v4122 = v4114 + 1;
  v4113->timer = v4122;
  int * v4116 = v4113->regs;
  int v4117 = v4116[8];
  int * v4118 = v4113->regs;
  int v4126 = v4117 + 1;
  v4118[8] = v4126;
  struct StateT * v4120 = slot_215(v4113);
  return v4120;
}

struct StateT * slot_29(struct StateT * v1153) {
  int v1154 = v1153->timer;
  int v1162 = v1154 + 1;
  v1153->timer = v1162;
  int * v1156 = v1153->regs;
  int v1157 = v1156[8];
  int * v1158 = v1153->regs;
  int v1166 = v1157 + 1;
  v1158[8] = v1166;
  struct StateT * v1160 = slot_30(v1153);
  return v1160;
}

struct StateT * slot_16(struct StateT * v945) {
  int v946 = v945->timer;
  int v954 = v946 + 1;
  v945->timer = v954;
  int * v948 = v945->regs;
  int v949 = v948[8];
  int * v950 = v945->regs;
  int v958 = v949 + 1;
  v950[8] = v958;
  struct StateT * v952 = slot_17(v945);
  return v952;
}

struct StateT * slot_113(struct StateT * v2497) {
  int v2498 = v2497->timer;
  int v2506 = v2498 + 1;
  v2497->timer = v2506;
  int * v2500 = v2497->regs;
  int v2501 = v2500[8];
  int * v2502 = v2497->regs;
  int v2510 = v2501 + 1;
  v2502[8] = v2510;
  struct StateT * v2504 = slot_114(v2497);
  return v2504;
}

struct StateT * slot_151(struct StateT * v3105) {
  int v3106 = v3105->timer;
  int v3114 = v3106 + 1;
  v3105->timer = v3114;
  int * v3108 = v3105->regs;
  int v3109 = v3108[8];
  int * v3110 = v3105->regs;
  int v3118 = v3109 + 1;
  v3110[8] = v3118;
  struct StateT * v3112 = slot_152(v3105);
  return v3112;
}

struct StateT * slot_7(struct StateT * v801) {
  int v802 = v801->timer;
  int v810 = v802 + 1;
  v801->timer = v810;
  int * v804 = v801->regs;
  int v805 = v804[8];
  int * v806 = v801->regs;
  int v814 = v805 + 1;
  v806[8] = v814;
  struct StateT * v808 = slot_8(v801);
  return v808;
}

struct StateT * slot_124(struct StateT * v2673) {
  int v2674 = v2673->timer;
  int v2682 = v2674 + 1;
  v2673->timer = v2682;
  int * v2676 = v2673->regs;
  int v2677 = v2676[8];
  int * v2678 = v2673->regs;
  int v2686 = v2677 + 1;
  v2678[8] = v2686;
  struct StateT * v2680 = slot_125(v2673);
  return v2680;
}

struct StateT * slot_191(struct StateT * v3745) {
  int v3746 = v3745->timer;
  int v3754 = v3746 + 1;
  v3745->timer = v3754;
  int * v3748 = v3745->regs;
  int v3749 = v3748[8];
  int * v3750 = v3745->regs;
  int v3758 = v3749 + 1;
  v3750[8] = v3758;
  struct StateT * v3752 = slot_192(v3745);
  return v3752;
}

struct StateT * slot_103(struct StateT * v2337) {
  int v2338 = v2337->timer;
  int v2346 = v2338 + 1;
  v2337->timer = v2346;
  int * v2340 = v2337->regs;
  int v2341 = v2340[8];
  int * v2342 = v2337->regs;
  int v2350 = v2341 + 1;
  v2342[8] = v2350;
  struct StateT * v2344 = slot_104(v2337);
  return v2344;
}

struct StateT * slot_128(struct StateT * v2737) {
  int v2738 = v2737->timer;
  int v2746 = v2738 + 1;
  v2737->timer = v2746;
  int * v2740 = v2737->regs;
  int v2741 = v2740[8];
  int * v2742 = v2737->regs;
  int v2750 = v2741 + 1;
  v2742[8] = v2750;
  struct StateT * v2744 = slot_129(v2737);
  return v2744;
}

struct StateT * slot_19(struct StateT * v993) {
  int v994 = v993->timer;
  int v1002 = v994 + 1;
  v993->timer = v1002;
  int * v996 = v993->regs;
  int v997 = v996[8];
  int * v998 = v993->regs;
  int v1006 = v997 + 1;
  v998[8] = v1006;
  struct StateT * v1000 = slot_20(v993);
  return v1000;
}

struct StateT * slot_87(struct StateT * v2081) {
  int v2082 = v2081->timer;
  int v2090 = v2082 + 1;
  v2081->timer = v2090;
  int * v2084 = v2081->regs;
  int v2085 = v2084[8];
  int * v2086 = v2081->regs;
  int v2094 = v2085 + 1;
  v2086[8] = v2094;
  struct StateT * v2088 = slot_88(v2081);
  return v2088;
}

struct StateT * slot_67(struct StateT * v1761) {
  int v1762 = v1761->timer;
  int v1770 = v1762 + 1;
  v1761->timer = v1770;
  int * v1764 = v1761->regs;
  int v1765 = v1764[8];
  int * v1766 = v1761->regs;
  int v1774 = v1765 + 1;
  v1766[8] = v1774;
  struct StateT * v1768 = slot_68(v1761);
  return v1768;
}

struct StateT * slot_81(struct StateT * v1985) {
  int v1986 = v1985->timer;
  int v1994 = v1986 + 1;
  v1985->timer = v1994;
  int * v1988 = v1985->regs;
  int v1989 = v1988[8];
  int * v1990 = v1985->regs;
  int v1998 = v1989 + 1;
  v1990[8] = v1998;
  struct StateT * v1992 = slot_82(v1985);
  return v1992;
}

struct StateT * slot_95(struct StateT * v2209) {
  int v2210 = v2209->timer;
  int v2218 = v2210 + 1;
  v2209->timer = v2218;
  int * v2212 = v2209->regs;
  int v2213 = v2212[8];
  int * v2214 = v2209->regs;
  int v2222 = v2213 + 1;
  v2214[8] = v2222;
  struct StateT * v2216 = slot_96(v2209);
  return v2216;
}

struct StateT * slot_115(struct StateT * v2529) {
  int v2530 = v2529->timer;
  int v2538 = v2530 + 1;
  v2529->timer = v2538;
  int * v2532 = v2529->regs;
  int v2533 = v2532[8];
  int * v2534 = v2529->regs;
  int v2542 = v2533 + 1;
  v2534[8] = v2542;
  struct StateT * v2536 = slot_116(v2529);
  return v2536;
}

struct StateT * slot_78(struct StateT * v1937) {
  int v1938 = v1937->timer;
  int v1946 = v1938 + 1;
  v1937->timer = v1946;
  int * v1940 = v1937->regs;
  int v1941 = v1940[8];
  int * v1942 = v1937->regs;
  int v1950 = v1941 + 1;
  v1942[8] = v1950;
  struct StateT * v1944 = slot_79(v1937);
  return v1944;
}

struct StateT * slot_32(struct StateT * v1201) {
  int v1202 = v1201->timer;
  int v1210 = v1202 + 1;
  v1201->timer = v1210;
  int * v1204 = v1201->regs;
  int v1205 = v1204[8];
  int * v1206 = v1201->regs;
  int v1214 = v1205 + 1;
  v1206[8] = v1214;
  struct StateT * v1208 = slot_33(v1201);
  return v1208;
}

struct StateT * slot_205(struct StateT * v3969) {
  int v3970 = v3969->timer;
  int v3978 = v3970 + 1;
  v3969->timer = v3978;
  int * v3972 = v3969->regs;
  int v3973 = v3972[8];
  int * v3974 = v3969->regs;
  int v3982 = v3973 + 1;
  v3974[8] = v3982;
  struct StateT * v3976 = slot_206(v3969);
  return v3976;
}

struct StateT * slot_193(struct StateT * v3777) {
  int v3778 = v3777->timer;
  int v3786 = v3778 + 1;
  v3777->timer = v3786;
  int * v3780 = v3777->regs;
  int v3781 = v3780[8];
  int * v3782 = v3777->regs;
  int v3790 = v3781 + 1;
  v3782[8] = v3790;
  struct StateT * v3784 = slot_194(v3777);
  return v3784;
}

struct StateT * slot_176(struct StateT * v3505) {
  int v3506 = v3505->timer;
  int v3514 = v3506 + 1;
  v3505->timer = v3514;
  int * v3508 = v3505->regs;
  int v3509 = v3508[8];
  int * v3510 = v3505->regs;
  int v3518 = v3509 + 1;
  v3510[8] = v3518;
  struct StateT * v3512 = slot_177(v3505);
  return v3512;
}

struct StateT * slot_189(struct StateT * v3713) {
  int v3714 = v3713->timer;
  int v3722 = v3714 + 1;
  v3713->timer = v3722;
  int * v3716 = v3713->regs;
  int v3717 = v3716[8];
  int * v3718 = v3713->regs;
  int v3726 = v3717 + 1;
  v3718[8] = v3726;
  struct StateT * v3720 = slot_190(v3713);
  return v3720;
}

struct StateT * slot_33(struct StateT * v1217) {
  int v1218 = v1217->timer;
  int v1226 = v1218 + 1;
  v1217->timer = v1226;
  int * v1220 = v1217->regs;
  int v1221 = v1220[8];
  int * v1222 = v1217->regs;
  int v1230 = v1221 + 1;
  v1222[8] = v1230;
  struct StateT * v1224 = slot_34(v1217);
  return v1224;
}

struct StateT * slot_35(struct StateT * v1249) {
  int v1250 = v1249->timer;
  int v1258 = v1250 + 1;
  v1249->timer = v1258;
  int * v1252 = v1249->regs;
  int v1253 = v1252[8];
  int * v1254 = v1249->regs;
  int v1262 = v1253 + 1;
  v1254[8] = v1262;
  struct StateT * v1256 = slot_36(v1249);
  return v1256;
}

struct StateT * slot_210(struct StateT * v4049) {
  int v4050 = v4049->timer;
  int v4058 = v4050 + 1;
  v4049->timer = v4058;
  int * v4052 = v4049->regs;
  int v4053 = v4052[8];
  int * v4054 = v4049->regs;
  int v4062 = v4053 + 1;
  v4054[8] = v4062;
  struct StateT * v4056 = slot_211(v4049);
  return v4056;
}

struct StateT * slot_166(struct StateT * v3345) {
  int v3346 = v3345->timer;
  int v3354 = v3346 + 1;
  v3345->timer = v3354;
  int * v3348 = v3345->regs;
  int v3349 = v3348[8];
  int * v3350 = v3345->regs;
  int v3358 = v3349 + 1;
  v3350[8] = v3358;
  struct StateT * v3352 = slot_167(v3345);
  return v3352;
}

struct StateT * slot_51(struct StateT * v1505) {
  int v1506 = v1505->timer;
  int v1514 = v1506 + 1;
  v1505->timer = v1514;
  int * v1508 = v1505->regs;
  int v1509 = v1508[8];
  int * v1510 = v1505->regs;
  int v1518 = v1509 + 1;
  v1510[8] = v1518;
  struct StateT * v1512 = slot_52(v1505);
  return v1512;
}

struct StateT * slot_52(struct StateT * v1521) {
  int v1522 = v1521->timer;
  int v1530 = v1522 + 1;
  v1521->timer = v1530;
  int * v1524 = v1521->regs;
  int v1525 = v1524[8];
  int * v1526 = v1521->regs;
  int v1534 = v1525 + 1;
  v1526[8] = v1534;
  struct StateT * v1528 = slot_53(v1521);
  return v1528;
}

struct StateT * slot_83(struct StateT * v2017) {
  int v2018 = v2017->timer;
  int v2026 = v2018 + 1;
  v2017->timer = v2026;
  int * v2020 = v2017->regs;
  int v2021 = v2020[8];
  int * v2022 = v2017->regs;
  int v2030 = v2021 + 1;
  v2022[8] = v2030;
  struct StateT * v2024 = slot_84(v2017);
  return v2024;
}

struct StateT * slot_25(struct StateT * v1089) {
  int v1090 = v1089->timer;
  int v1098 = v1090 + 1;
  v1089->timer = v1098;
  int * v1092 = v1089->regs;
  int v1093 = v1092[8];
  int * v1094 = v1089->regs;
  int v1102 = v1093 + 1;
  v1094[8] = v1102;
  struct StateT * v1096 = slot_26(v1089);
  return v1096;
}

struct StateT * slot_209(struct StateT * v4033) {
  int v4034 = v4033->timer;
  int v4042 = v4034 + 1;
  v4033->timer = v4042;
  int * v4036 = v4033->regs;
  int v4037 = v4036[8];
  int * v4038 = v4033->regs;
  int v4046 = v4037 + 1;
  v4038[8] = v4046;
  struct StateT * v4040 = slot_210(v4033);
  return v4040;
}

struct StateT * slot_3(struct StateT * v506) {
  int v507 = v506->timer;
  int v515 = v507 + 1;
  v506->timer = v515;
  int * v509 = v506->regs;
  int v510 = v509[6];
  int * v511 = v506->regs;
  int v519 = v510 << 2;
  v511[6] = v519;
  struct StateT * v513 = slot_4(v506);
  return v513;
}

struct StateT * slot_123(struct StateT * v2657) {
  int v2658 = v2657->timer;
  int v2666 = v2658 + 1;
  v2657->timer = v2666;
  int * v2660 = v2657->regs;
  int v2661 = v2660[8];
  int * v2662 = v2657->regs;
  int v2670 = v2661 + 1;
  v2662[8] = v2670;
  struct StateT * v2664 = slot_124(v2657);
  return v2664;
}

struct StateT * slot_73(struct StateT * v1857) {
  int v1858 = v1857->timer;
  int v1866 = v1858 + 1;
  v1857->timer = v1866;
  int * v1860 = v1857->regs;
  int v1861 = v1860[8];
  int * v1862 = v1857->regs;
  int v1870 = v1861 + 1;
  v1862[8] = v1870;
  struct StateT * v1864 = slot_74(v1857);
  return v1864;
}

struct StateT * slot_198(struct StateT * v3857) {
  int v3858 = v3857->timer;
  int v3866 = v3858 + 1;
  v3857->timer = v3866;
  int * v3860 = v3857->regs;
  int v3861 = v3860[8];
  int * v3862 = v3857->regs;
  int v3870 = v3861 + 1;
  v3862[8] = v3870;
  struct StateT * v3864 = slot_199(v3857);
  return v3864;
}

struct StateT * slot_1(struct StateT * v252) {
  int v253 = v252->timer;
  int v384 = v253 + 1;
  v252->timer = v384;
  int * v255 = v252->cache_tags;
  int v256 = v255[0];
  int * v257 = v252->cache_tags;
  int v258 = v257[1];
  int * v259 = v252->cache_tags;
  int v260 = v259[8];
  int * v261 = v252->cache_tags;
  int v262 = v261[9];
  int v263 = v252->timer;
  int v393 = v263 + ((100 ^ (((~(((v260 ^ 10) | (-(v260 ^ 10))) >> 31)) | (~(((v262 ^ 10) | (-(v262 ^ 10))) >> 31))) & 104)) ^ (((~(((v256 ^ 10) | (-(v256 ^ 10))) >> 31)) | (~(((v258 ^ 10) | (-(v258 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v260 ^ 10) | (-(v260 ^ 10))) >> 31)) | (~(((v262 ^ 10) | (-(v262 ^ 10))) >> 31))) & 104)))));
  v252->timer = v393;
  int * v265 = v252->cache_vals;
  bool v394 = !(((~(((v256 ^ 10) | (-(v256 ^ 10))) >> 31)) | (~(((v258 ^ 10) | (-(v258 ^ 10))) >> 31))) == 0);
  int v378;
  if (v394) {
    int * v266 = v252->cache_age;
    int v396 = (~(((v258 ^ 10) | (-(v258 ^ 10))) >> 31)) & 1;
    int v267 = v266[v396];
    int * v268 = v252->cache_age;
    int v269 = v268[0];
    int * v270 = v252->cache_age;
    int v399 = v269 + ((int)((unsigned int)(v269 - v267) >> 31));
    v270[0] = v399;
    int * v272 = v252->cache_age;
    int v273 = v272[1];
    int * v274 = v252->cache_age;
    int v402 = v273 + ((int)((unsigned int)(v273 - v267) >> 31));
    v274[1] = v402;
    int * v276 = v252->cache_age;
    v276[v396] = 0;
    v378 = v396;
  } else {
    int * v279 = v252->cache_age;
    int v280 = v279[0];
    int * v281 = v252->cache_tags;
    int v282 = v281[0];
    int * v283 = v252->cache_age;
    int v284 = v283[1];
    int * v285 = v252->cache_tags;
    int v286 = v285[1];
    bool v408 = !(((~(((v260 ^ 10) | (-(v260 ^ 10))) >> 31)) | (~(((v262 ^ 10) | (-(v262 ^ 10))) >> 31))) == 0);
    int v350;
    if (v408) {
      int * v287 = v252->cache_age;
      int v410 = 8 + ((~(((v262 ^ 10) | (-(v262 ^ 10))) >> 31)) & 1);
      int v288 = v287[v410];
      int * v289 = v252->cache_age;
      int v290 = v289[8];
      int * v291 = v252->cache_age;
      int v413 = v290 + ((int)((unsigned int)(v290 - v288) >> 31));
      v291[8] = v413;
      int * v293 = v252->cache_age;
      int v294 = v293[9];
      int * v295 = v252->cache_age;
      int v416 = v294 + ((int)((unsigned int)(v294 - v288) >> 31));
      v295[9] = v416;
      int * v297 = v252->cache_age;
      v297[v410] = 0;
      v350 = v410;
    } else {
      int * v300 = v252->cache_age;
      int v301 = v300[8];
      int * v302 = v252->cache_tags;
      int v303 = v302[8];
      int * v304 = v252->cache_age;
      int v305 = v304[9];
      int * v306 = v252->cache_tags;
      int v307 = v306[9];
      int * v308 = v252->cache_dirty;
      int v423 = 8 + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v309 = v308[v423];
      bool v424 = !(v309 == 0);
      if (v424) {
        int * v310 = v252->cache_tags;
        int v311 = v310[v423];
        int * v312 = v252->cache_vals;
        int v427 = (8 + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v313 = v312[v427];
        int * v314 = v252->cache_vals;
        int v429 = ((8 + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v315 = v314[v429];
        int * v316 = v252->mem;
        int v431 = v311 * 2;
        v316[v431] = v313;
        int * v318 = v252->mem;
        int v434 = (v311 * 2) + 1;
        v318[v434] = v315;
        ;
      } else {
        ;
      }
      int * v323 = v252->mem;
      int v324 = v323[20];
      int * v325 = v252->mem;
      int v326 = v325[21];
      int * v327 = v252->cache_vals;
      int v443 = (8 + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v327[v443] = v324;
      int * v329 = v252->cache_vals;
      int v446 = ((8 + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v329[v446] = v326;
      int * v331 = v252->cache_tags;
      v331[v423] = 10;
      int * v333 = v252->cache_dirty;
      v333[v423] = 0;
      int * v335 = v252->cache_age;
      v335[v423] = 1;
      int * v337 = v252->cache_age;
      int v338 = v337[v423];
      int * v339 = v252->cache_age;
      int v340 = v339[8];
      int * v341 = v252->cache_age;
      int v455 = v340 + ((int)((unsigned int)(v340 - v338) >> 31));
      v341[8] = v455;
      int * v343 = v252->cache_age;
      int v344 = v343[9];
      int * v345 = v252->cache_age;
      int v458 = v344 + ((int)((unsigned int)(v344 - v338) >> 31));
      v345[9] = v458;
      int * v347 = v252->cache_age;
      v347[v423] = 0;
      v350 = v423;
    }
    int * v351 = v252->cache_vals;
    int v461 = v350 * 2;
    int v352 = v351[v461];
    int * v353 = v252->cache_vals;
    int v463 = (v350 * 2) + 1;
    int v354 = v353[v463];
    int * v355 = v252->cache_vals;
    int v465 = ((((v280 + ((~(((v282 ^ -1) | (-(v282 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v355[v465] = v352;
    int * v357 = v252->cache_vals;
    int v468 = (((((v280 + ((~(((v282 ^ -1) | (-(v282 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v357[v468] = v354;
    int * v359 = v252->cache_tags;
    int v471 = (((v280 + ((~(((v282 ^ -1) | (-(v282 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v359[v471] = 10;
    int * v361 = v252->cache_dirty;
    v361[v471] = 0;
    int * v363 = v252->cache_age;
    v363[v471] = 1;
    int * v365 = v252->cache_age;
    int v366 = v365[v471];
    int * v367 = v252->cache_age;
    int v368 = v367[0];
    int * v369 = v252->cache_age;
    int v478 = v368 + ((int)((unsigned int)(v368 - v366) >> 31));
    v369[0] = v478;
    int * v371 = v252->cache_age;
    int v372 = v371[1];
    int * v373 = v252->cache_age;
    int v481 = v372 + ((int)((unsigned int)(v372 - v366) >> 31));
    v373[1] = v481;
    int * v375 = v252->cache_age;
    v375[v471] = 0;
    v378 = v471;
  }
  int v484 = v378 * 2;
  int v379 = v265[v484];
  int * v380 = v252->regs;
  v380[6] = v379;
  struct StateT * v382 = slot_2(v252);
  return v382;
}

struct StateT * slot_187(struct StateT * v3681) {
  int v3682 = v3681->timer;
  int v3690 = v3682 + 1;
  v3681->timer = v3690;
  int * v3684 = v3681->regs;
  int v3685 = v3684[8];
  int * v3686 = v3681->regs;
  int v3694 = v3685 + 1;
  v3686[8] = v3694;
  struct StateT * v3688 = slot_188(v3681);
  return v3688;
}

struct StateT * slot_97(struct StateT * v2241) {
  int v2242 = v2241->timer;
  int v2250 = v2242 + 1;
  v2241->timer = v2250;
  int * v2244 = v2241->regs;
  int v2245 = v2244[8];
  int * v2246 = v2241->regs;
  int v2254 = v2245 + 1;
  v2246[8] = v2254;
  struct StateT * v2248 = slot_98(v2241);
  return v2248;
}

struct StateT * slot_182(struct StateT * v3601) {
  int v3602 = v3601->timer;
  int v3610 = v3602 + 1;
  v3601->timer = v3610;
  int * v3604 = v3601->regs;
  int v3605 = v3604[8];
  int * v3606 = v3601->regs;
  int v3614 = v3605 + 1;
  v3606[8] = v3614;
  struct StateT * v3608 = slot_183(v3601);
  return v3608;
}

struct StateT * slot_38(struct StateT * v1297) {
  int v1298 = v1297->timer;
  int v1306 = v1298 + 1;
  v1297->timer = v1306;
  int * v1300 = v1297->regs;
  int v1301 = v1300[8];
  int * v1302 = v1297->regs;
  int v1310 = v1301 + 1;
  v1302[8] = v1310;
  struct StateT * v1304 = slot_39(v1297);
  return v1304;
}

struct StateT * slot_178(struct StateT * v3537) {
  int v3538 = v3537->timer;
  int v3546 = v3538 + 1;
  v3537->timer = v3546;
  int * v3540 = v3537->regs;
  int v3541 = v3540[8];
  int * v3542 = v3537->regs;
  int v3550 = v3541 + 1;
  v3542[8] = v3550;
  struct StateT * v3544 = slot_179(v3537);
  return v3544;
}

struct StateT * slot_106(struct StateT * v2385) {
  int v2386 = v2385->timer;
  int v2394 = v2386 + 1;
  v2385->timer = v2394;
  int * v2388 = v2385->regs;
  int v2389 = v2388[8];
  int * v2390 = v2385->regs;
  int v2398 = v2389 + 1;
  v2390[8] = v2398;
  struct StateT * v2392 = slot_107(v2385);
  return v2392;
}

struct StateT * slot_98(struct StateT * v2257) {
  int v2258 = v2257->timer;
  int v2266 = v2258 + 1;
  v2257->timer = v2266;
  int * v2260 = v2257->regs;
  int v2261 = v2260[8];
  int * v2262 = v2257->regs;
  int v2270 = v2261 + 1;
  v2262[8] = v2270;
  struct StateT * v2264 = slot_99(v2257);
  return v2264;
}

struct StateT * slot_159(struct StateT * v3233) {
  int v3234 = v3233->timer;
  int v3242 = v3234 + 1;
  v3233->timer = v3242;
  int * v3236 = v3233->regs;
  int v3237 = v3236[8];
  int * v3238 = v3233->regs;
  int v3246 = v3237 + 1;
  v3238[8] = v3246;
  struct StateT * v3240 = slot_160(v3233);
  return v3240;
}

struct StateT * slot_46(struct StateT * v1425) {
  int v1426 = v1425->timer;
  int v1434 = v1426 + 1;
  v1425->timer = v1434;
  int * v1428 = v1425->regs;
  int v1429 = v1428[8];
  int * v1430 = v1425->regs;
  int v1438 = v1429 + 1;
  v1430[8] = v1438;
  struct StateT * v1432 = slot_47(v1425);
  return v1432;
}

struct StateT * slot_212(struct StateT * v4081) {
  int v4082 = v4081->timer;
  int v4090 = v4082 + 1;
  v4081->timer = v4090;
  int * v4084 = v4081->regs;
  int v4085 = v4084[8];
  int * v4086 = v4081->regs;
  int v4094 = v4085 + 1;
  v4086[8] = v4094;
  struct StateT * v4088 = slot_213(v4081);
  return v4088;
}

struct StateT * slot_132(struct StateT * v2801) {
  int v2802 = v2801->timer;
  int v2810 = v2802 + 1;
  v2801->timer = v2810;
  int * v2804 = v2801->regs;
  int v2805 = v2804[8];
  int * v2806 = v2801->regs;
  int v2814 = v2805 + 1;
  v2806[8] = v2814;
  struct StateT * v2808 = slot_133(v2801);
  return v2808;
}

struct StateT * slot_130(struct StateT * v2769) {
  int v2770 = v2769->timer;
  int v2778 = v2770 + 1;
  v2769->timer = v2778;
  int * v2772 = v2769->regs;
  int v2773 = v2772[8];
  int * v2774 = v2769->regs;
  int v2782 = v2773 + 1;
  v2774[8] = v2782;
  struct StateT * v2776 = slot_131(v2769);
  return v2776;
}

struct StateT * slot_211(struct StateT * v4065) {
  int v4066 = v4065->timer;
  int v4074 = v4066 + 1;
  v4065->timer = v4074;
  int * v4068 = v4065->regs;
  int v4069 = v4068[8];
  int * v4070 = v4065->regs;
  int v4078 = v4069 + 1;
  v4070[8] = v4078;
  struct StateT * v4072 = slot_212(v4065);
  return v4072;
}

struct StateT * slot_20(struct StateT * v1009) {
  int v1010 = v1009->timer;
  int v1018 = v1010 + 1;
  v1009->timer = v1018;
  int * v1012 = v1009->regs;
  int v1013 = v1012[8];
  int * v1014 = v1009->regs;
  int v1022 = v1013 + 1;
  v1014[8] = v1022;
  struct StateT * v1016 = slot_21(v1009);
  return v1016;
}

struct StateT * slot_141(struct StateT * v2945) {
  int v2946 = v2945->timer;
  int v2954 = v2946 + 1;
  v2945->timer = v2954;
  int * v2948 = v2945->regs;
  int v2949 = v2948[8];
  int * v2950 = v2945->regs;
  int v2958 = v2949 + 1;
  v2950[8] = v2958;
  struct StateT * v2952 = slot_142(v2945);
  return v2952;
}

struct StateT * slot_61(struct StateT * v1665) {
  int v1666 = v1665->timer;
  int v1674 = v1666 + 1;
  v1665->timer = v1674;
  int * v1668 = v1665->regs;
  int v1669 = v1668[8];
  int * v1670 = v1665->regs;
  int v1678 = v1669 + 1;
  v1670[8] = v1678;
  struct StateT * v1672 = slot_62(v1665);
  return v1672;
}

struct StateT * slot_30(struct StateT * v1169) {
  int v1170 = v1169->timer;
  int v1178 = v1170 + 1;
  v1169->timer = v1178;
  int * v1172 = v1169->regs;
  int v1173 = v1172[8];
  int * v1174 = v1169->regs;
  int v1182 = v1173 + 1;
  v1174[8] = v1182;
  struct StateT * v1176 = slot_31(v1169);
  return v1176;
}

struct StateT * slot_4(struct StateT * v522) {
  int v523 = v522->timer;
  int v656 = v523 + 1;
  v522->timer = v656;
  int * v525 = v522->regs;
  int v526 = v525[6];
  int * v527 = v522->cache_tags;
  int v660 = (((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2;
  int v528 = v527[v660];
  int * v529 = v522->cache_tags;
  int v662 = ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2) + 1;
  int v530 = v529[v662];
  int * v531 = v522->cache_tags;
  int v664 = 4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2);
  int v532 = v531[v664];
  int * v533 = v522->cache_tags;
  int v666 = (4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v534 = v533[v666];
  int v535 = v522->timer;
  int v667 = v535 + ((100 ^ (((~(((v532 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v532 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) | (~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) | (~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v532 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v532 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) | (~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31))) & 104)))));
  v522->timer = v667;
  int * v537 = v522->cache_vals;
  bool v668 = !(((~(((v528 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v528 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) | (~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31))) == 0);
  int v650;
  if (v668) {
    int * v538 = v522->cache_age;
    int v670 = ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2) + ((~(((v530 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v530 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) & 1);
    int v539 = v538[v670];
    int * v540 = v522->cache_age;
    int v541 = v540[v660];
    int * v542 = v522->cache_age;
    int v673 = v541 + ((int)((unsigned int)(v541 - v539) >> 31));
    v542[v660] = v673;
    int * v544 = v522->cache_age;
    int v545 = v544[v662];
    int * v546 = v522->cache_age;
    int v676 = v545 + ((int)((unsigned int)(v545 - v539) >> 31));
    v546[v662] = v676;
    int * v548 = v522->cache_age;
    v548[v670] = 0;
    v650 = v670;
  } else {
    int * v551 = v522->cache_age;
    int v680 = (((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2;
    int v552 = v551[v680];
    int * v553 = v522->cache_tags;
    int v554 = v553[v680];
    int * v555 = v522->cache_age;
    int v556 = v555[v662];
    int * v557 = v522->cache_tags;
    int v558 = v557[v662];
    bool v684 = !(((~(((v532 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v532 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) | (~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31))) == 0);
    int v622;
    if (v684) {
      int * v559 = v522->cache_age;
      int v686 = (4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + ((~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1))))) >> 31)) & 1);
      int v560 = v559[v686];
      int * v561 = v522->cache_age;
      int v562 = v561[v664];
      int * v563 = v522->cache_age;
      int v689 = v562 + ((int)((unsigned int)(v562 - v560) >> 31));
      v563[v664] = v689;
      int * v565 = v522->cache_age;
      int v566 = v565[v666];
      int * v567 = v522->cache_age;
      int v692 = v566 + ((int)((unsigned int)(v566 - v560) >> 31));
      v567[v666] = v692;
      int * v569 = v522->cache_age;
      v569[v686] = 0;
      v622 = v686;
    } else {
      int * v572 = v522->cache_age;
      int v696 = 4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2);
      int v573 = v572[v696];
      int * v574 = v522->cache_tags;
      int v575 = v574[v696];
      int * v576 = v522->cache_age;
      int v577 = v576[v666];
      int * v578 = v522->cache_tags;
      int v579 = v578[v666];
      int * v580 = v522->cache_dirty;
      int v701 = (4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + ((((v573 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v581 = v580[v701];
      bool v702 = !(v581 == 0);
      if (v702) {
        int * v582 = v522->cache_tags;
        int v583 = v582[v701];
        int * v584 = v522->cache_vals;
        int v705 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + ((((v573 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v585 = v584[v705];
        int * v586 = v522->cache_vals;
        int v707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + ((((v573 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v587 = v586[v707];
        int * v588 = v522->mem;
        int v709 = v583 * 2;
        v588[v709] = v585;
        int * v590 = v522->mem;
        int v712 = (v583 * 2) + 1;
        v590[v712] = v587;
        ;
      } else {
        ;
      }
      int * v595 = v522->mem;
      int v717 = ((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) * 2;
      int v596 = v595[v717];
      int * v597 = v522->mem;
      int v719 = (((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) * 2) + 1;
      int v598 = v597[v719];
      int * v599 = v522->cache_vals;
      int v721 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + ((((v573 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v599[v721] = v596;
      int * v601 = v522->cache_vals;
      int v724 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 3) * 2)) + ((((v573 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v601[v724] = v598;
      int * v603 = v522->cache_tags;
      int v727 = (int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1);
      v603[v701] = v727;
      int * v605 = v522->cache_dirty;
      v605[v701] = 0;
      int * v607 = v522->cache_age;
      v607[v701] = 1;
      int * v609 = v522->cache_age;
      int v610 = v609[v701];
      int * v611 = v522->cache_age;
      int v612 = v611[v664];
      int * v613 = v522->cache_age;
      int v735 = v612 + ((int)((unsigned int)(v612 - v610) >> 31));
      v613[v664] = v735;
      int * v615 = v522->cache_age;
      int v616 = v615[v666];
      int * v617 = v522->cache_age;
      int v738 = v616 + ((int)((unsigned int)(v616 - v610) >> 31));
      v617[v666] = v738;
      int * v619 = v522->cache_age;
      v619[v701] = 0;
      v622 = v701;
    }
    int * v623 = v522->cache_vals;
    int v741 = v622 * 2;
    int v624 = v623[v741];
    int * v625 = v522->cache_vals;
    int v743 = (v622 * 2) + 1;
    int v626 = v625[v743];
    int * v627 = v522->cache_vals;
    int v745 = (((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v627[v745] = v624;
    int * v629 = v522->cache_vals;
    int v748 = ((((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v629[v748] = v626;
    int * v631 = v522->cache_tags;
    int v751 = ((((int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1)) & 1) * 2) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v752 = (int)((unsigned int)((int)((unsigned int)v526 >> 2)) >> 1);
    v631[v751] = v752;
    int * v633 = v522->cache_dirty;
    v633[v751] = 0;
    int * v635 = v522->cache_age;
    v635[v751] = 1;
    int * v637 = v522->cache_age;
    int v638 = v637[v751];
    int * v639 = v522->cache_age;
    int v640 = v639[v660];
    int * v641 = v522->cache_age;
    int v760 = v640 + ((int)((unsigned int)(v640 - v638) >> 31));
    v641[v660] = v760;
    int * v643 = v522->cache_age;
    int v644 = v643[v662];
    int * v645 = v522->cache_age;
    int v763 = v644 + ((int)((unsigned int)(v644 - v638) >> 31));
    v645[v662] = v763;
    int * v647 = v522->cache_age;
    v647[v751] = 0;
    v650 = v751;
  }
  int v766 = (v650 * 2) + (((int)((unsigned int)v526 >> 2)) & 1);
  int v651 = v537[v766];
  int * v652 = v522->regs;
  v652[7] = v651;
  struct StateT * v654 = slot_5(v522);
  return v654;
}

struct StateT * slot_18(struct StateT * v977) {
  int v978 = v977->timer;
  int v986 = v978 + 1;
  v977->timer = v986;
  int * v980 = v977->regs;
  int v981 = v980[8];
  int * v982 = v977->regs;
  int v990 = v981 + 1;
  v982[8] = v990;
  struct StateT * v984 = slot_19(v977);
  return v984;
}

struct StateT * slot_9(struct StateT * v833) {
  int v834 = v833->timer;
  int v842 = v834 + 1;
  v833->timer = v842;
  int * v836 = v833->regs;
  int v837 = v836[8];
  int * v838 = v833->regs;
  int v846 = v837 + 1;
  v838[8] = v846;
  struct StateT * v840 = slot_10(v833);
  return v840;
}

struct StateT * slot_183(struct StateT * v3617) {
  int v3618 = v3617->timer;
  int v3626 = v3618 + 1;
  v3617->timer = v3626;
  int * v3620 = v3617->regs;
  int v3621 = v3620[8];
  int * v3622 = v3617->regs;
  int v3630 = v3621 + 1;
  v3622[8] = v3630;
  struct StateT * v3624 = slot_184(v3617);
  return v3624;
}

struct StateT * slot_43(struct StateT * v1377) {
  int v1378 = v1377->timer;
  int v1386 = v1378 + 1;
  v1377->timer = v1386;
  int * v1380 = v1377->regs;
  int v1381 = v1380[8];
  int * v1382 = v1377->regs;
  int v1390 = v1381 + 1;
  v1382[8] = v1390;
  struct StateT * v1384 = slot_44(v1377);
  return v1384;
}

struct StateT * slot_70(struct StateT * v1809) {
  int v1810 = v1809->timer;
  int v1818 = v1810 + 1;
  v1809->timer = v1818;
  int * v1812 = v1809->regs;
  int v1813 = v1812[8];
  int * v1814 = v1809->regs;
  int v1822 = v1813 + 1;
  v1814[8] = v1822;
  struct StateT * v1816 = slot_71(v1809);
  return v1816;
}

struct StateT * slot_168(struct StateT * v3377) {
  int v3378 = v3377->timer;
  int v3386 = v3378 + 1;
  v3377->timer = v3386;
  int * v3380 = v3377->regs;
  int v3381 = v3380[8];
  int * v3382 = v3377->regs;
  int v3390 = v3381 + 1;
  v3382[8] = v3390;
  struct StateT * v3384 = slot_169(v3377);
  return v3384;
}

struct StateT * slot_76(struct StateT * v1905) {
  int v1906 = v1905->timer;
  int v1914 = v1906 + 1;
  v1905->timer = v1914;
  int * v1908 = v1905->regs;
  int v1909 = v1908[8];
  int * v1910 = v1905->regs;
  int v1918 = v1909 + 1;
  v1910[8] = v1918;
  struct StateT * v1912 = slot_77(v1905);
  return v1912;
}

struct StateT * slot_6(struct StateT * v785) {
  int v786 = v785->timer;
  int v794 = v786 + 1;
  v785->timer = v794;
  int * v788 = v785->regs;
  int v789 = v788[8];
  int * v790 = v785->regs;
  int v798 = v789 + 1;
  v790[8] = v798;
  struct StateT * v792 = slot_7(v785);
  return v792;
}

struct StateT * slot_225(struct StateT * v4289) {
  int v4290 = v4289->timer;
  int v4297 = v4290 + 1;
  v4289->timer = v4297;
  int * v4292 = v4289->regs;
  int v4293 = v4292[8];
  int * v4294 = v4289->regs;
  int v4301 = v4293 + 1;
  v4294[8] = v4301;
  return v4289;
}

struct StateT * slot_55(struct StateT * v1569) {
  int v1570 = v1569->timer;
  int v1578 = v1570 + 1;
  v1569->timer = v1578;
  int * v1572 = v1569->regs;
  int v1573 = v1572[8];
  int * v1574 = v1569->regs;
  int v1582 = v1573 + 1;
  v1574[8] = v1582;
  struct StateT * v1576 = slot_56(v1569);
  return v1576;
}

struct StateT * slot_213(struct StateT * v4097) {
  int v4098 = v4097->timer;
  int v4106 = v4098 + 1;
  v4097->timer = v4106;
  int * v4100 = v4097->regs;
  int v4101 = v4100[8];
  int * v4102 = v4097->regs;
  int v4110 = v4101 + 1;
  v4102[8] = v4110;
  struct StateT * v4104 = slot_214(v4097);
  return v4104;
}

struct StateT * slot_82(struct StateT * v2001) {
  int v2002 = v2001->timer;
  int v2010 = v2002 + 1;
  v2001->timer = v2010;
  int * v2004 = v2001->regs;
  int v2005 = v2004[8];
  int * v2006 = v2001->regs;
  int v2014 = v2005 + 1;
  v2006[8] = v2014;
  struct StateT * v2008 = slot_83(v2001);
  return v2008;
}

struct StateT * slot_161(struct StateT * v3265) {
  int v3266 = v3265->timer;
  int v3274 = v3266 + 1;
  v3265->timer = v3274;
  int * v3268 = v3265->regs;
  int v3269 = v3268[8];
  int * v3270 = v3265->regs;
  int v3278 = v3269 + 1;
  v3270[8] = v3278;
  struct StateT * v3272 = slot_162(v3265);
  return v3272;
}

struct StateT * slot_185(struct StateT * v3649) {
  int v3650 = v3649->timer;
  int v3658 = v3650 + 1;
  v3649->timer = v3658;
  int * v3652 = v3649->regs;
  int v3653 = v3652[8];
  int * v3654 = v3649->regs;
  int v3662 = v3653 + 1;
  v3654[8] = v3662;
  struct StateT * v3656 = slot_186(v3649);
  return v3656;
}

struct StateT * slot_91(struct StateT * v2145) {
  int v2146 = v2145->timer;
  int v2154 = v2146 + 1;
  v2145->timer = v2154;
  int * v2148 = v2145->regs;
  int v2149 = v2148[8];
  int * v2150 = v2145->regs;
  int v2158 = v2149 + 1;
  v2150[8] = v2158;
  struct StateT * v2152 = slot_92(v2145);
  return v2152;
}

struct StateT * slot_58(struct StateT * v1617) {
  int v1618 = v1617->timer;
  int v1626 = v1618 + 1;
  v1617->timer = v1626;
  int * v1620 = v1617->regs;
  int v1621 = v1620[8];
  int * v1622 = v1617->regs;
  int v1630 = v1621 + 1;
  v1622[8] = v1630;
  struct StateT * v1624 = slot_59(v1617);
  return v1624;
}

struct StateT * slot_89(struct StateT * v2113) {
  int v2114 = v2113->timer;
  int v2122 = v2114 + 1;
  v2113->timer = v2122;
  int * v2116 = v2113->regs;
  int v2117 = v2116[8];
  int * v2118 = v2113->regs;
  int v2126 = v2117 + 1;
  v2118[8] = v2126;
  struct StateT * v2120 = slot_90(v2113);
  return v2120;
}

struct StateT * slot_66(struct StateT * v1745) {
  int v1746 = v1745->timer;
  int v1754 = v1746 + 1;
  v1745->timer = v1754;
  int * v1748 = v1745->regs;
  int v1749 = v1748[8];
  int * v1750 = v1745->regs;
  int v1758 = v1749 + 1;
  v1750[8] = v1758;
  struct StateT * v1752 = slot_67(v1745);
  return v1752;
}

struct StateT * slot_140(struct StateT * v2929) {
  int v2930 = v2929->timer;
  int v2938 = v2930 + 1;
  v2929->timer = v2938;
  int * v2932 = v2929->regs;
  int v2933 = v2932[8];
  int * v2934 = v2929->regs;
  int v2942 = v2933 + 1;
  v2934[8] = v2942;
  struct StateT * v2936 = slot_141(v2929);
  return v2936;
}

struct StateT * slot_49(struct StateT * v1473) {
  int v1474 = v1473->timer;
  int v1482 = v1474 + 1;
  v1473->timer = v1482;
  int * v1476 = v1473->regs;
  int v1477 = v1476[8];
  int * v1478 = v1473->regs;
  int v1486 = v1477 + 1;
  v1478[8] = v1486;
  struct StateT * v1480 = slot_50(v1473);
  return v1480;
}

struct StateT * slot_216(struct StateT * v4145) {
  int v4146 = v4145->timer;
  int v4154 = v4146 + 1;
  v4145->timer = v4154;
  int * v4148 = v4145->regs;
  int v4149 = v4148[8];
  int * v4150 = v4145->regs;
  int v4158 = v4149 + 1;
  v4150[8] = v4158;
  struct StateT * v4152 = slot_217(v4145);
  return v4152;
}

struct StateT * slot_50(struct StateT * v1489) {
  int v1490 = v1489->timer;
  int v1498 = v1490 + 1;
  v1489->timer = v1498;
  int * v1492 = v1489->regs;
  int v1493 = v1492[8];
  int * v1494 = v1489->regs;
  int v1502 = v1493 + 1;
  v1494[8] = v1502;
  struct StateT * v1496 = slot_51(v1489);
  return v1496;
}

struct StateT * slot_37(struct StateT * v1281) {
  int v1282 = v1281->timer;
  int v1290 = v1282 + 1;
  v1281->timer = v1290;
  int * v1284 = v1281->regs;
  int v1285 = v1284[8];
  int * v1286 = v1281->regs;
  int v1294 = v1285 + 1;
  v1286[8] = v1294;
  struct StateT * v1288 = slot_38(v1281);
  return v1288;
}

struct StateT * slot_114(struct StateT * v2513) {
  int v2514 = v2513->timer;
  int v2522 = v2514 + 1;
  v2513->timer = v2522;
  int * v2516 = v2513->regs;
  int v2517 = v2516[8];
  int * v2518 = v2513->regs;
  int v2526 = v2517 + 1;
  v2518[8] = v2526;
  struct StateT * v2520 = slot_115(v2513);
  return v2520;
}

struct StateT * slot_135(struct StateT * v2849) {
  int v2850 = v2849->timer;
  int v2858 = v2850 + 1;
  v2849->timer = v2858;
  int * v2852 = v2849->regs;
  int v2853 = v2852[8];
  int * v2854 = v2849->regs;
  int v2862 = v2853 + 1;
  v2854[8] = v2862;
  struct StateT * v2856 = slot_136(v2849);
  return v2856;
}

struct StateT * slot_59(struct StateT * v1633) {
  int v1634 = v1633->timer;
  int v1642 = v1634 + 1;
  v1633->timer = v1642;
  int * v1636 = v1633->regs;
  int v1637 = v1636[8];
  int * v1638 = v1633->regs;
  int v1646 = v1637 + 1;
  v1638[8] = v1646;
  struct StateT * v1640 = slot_60(v1633);
  return v1640;
}

struct StateT * slot_192(struct StateT * v3761) {
  int v3762 = v3761->timer;
  int v3770 = v3762 + 1;
  v3761->timer = v3770;
  int * v3764 = v3761->regs;
  int v3765 = v3764[8];
  int * v3766 = v3761->regs;
  int v3774 = v3765 + 1;
  v3766[8] = v3774;
  struct StateT * v3768 = slot_193(v3761);
  return v3768;
}

struct StateT * slot_40(struct StateT * v1329) {
  int v1330 = v1329->timer;
  int v1338 = v1330 + 1;
  v1329->timer = v1338;
  int * v1332 = v1329->regs;
  int v1333 = v1332[8];
  int * v1334 = v1329->regs;
  int v1342 = v1333 + 1;
  v1334[8] = v1342;
  struct StateT * v1336 = slot_41(v1329);
  return v1336;
}

struct StateT * slot_48(struct StateT * v1457) {
  int v1458 = v1457->timer;
  int v1466 = v1458 + 1;
  v1457->timer = v1466;
  int * v1460 = v1457->regs;
  int v1461 = v1460[8];
  int * v1462 = v1457->regs;
  int v1470 = v1461 + 1;
  v1462[8] = v1470;
  struct StateT * v1464 = slot_49(v1457);
  return v1464;
}

struct StateT * slot_77(struct StateT * v1921) {
  int v1922 = v1921->timer;
  int v1930 = v1922 + 1;
  v1921->timer = v1930;
  int * v1924 = v1921->regs;
  int v1925 = v1924[8];
  int * v1926 = v1921->regs;
  int v1934 = v1925 + 1;
  v1926[8] = v1934;
  struct StateT * v1928 = slot_78(v1921);
  return v1928;
}

struct StateT * slot_85(struct StateT * v2049) {
  int v2050 = v2049->timer;
  int v2058 = v2050 + 1;
  v2049->timer = v2058;
  int * v2052 = v2049->regs;
  int v2053 = v2052[8];
  int * v2054 = v2049->regs;
  int v2062 = v2053 + 1;
  v2054[8] = v2062;
  struct StateT * v2056 = slot_86(v2049);
  return v2056;
}

struct StateT * slot_75(struct StateT * v1889) {
  int v1890 = v1889->timer;
  int v1898 = v1890 + 1;
  v1889->timer = v1898;
  int * v1892 = v1889->regs;
  int v1893 = v1892[8];
  int * v1894 = v1889->regs;
  int v1902 = v1893 + 1;
  v1894[8] = v1902;
  struct StateT * v1896 = slot_76(v1889);
  return v1896;
}

struct StateT * slot_72(struct StateT * v1841) {
  int v1842 = v1841->timer;
  int v1850 = v1842 + 1;
  v1841->timer = v1850;
  int * v1844 = v1841->regs;
  int v1845 = v1844[8];
  int * v1846 = v1841->regs;
  int v1854 = v1845 + 1;
  v1846[8] = v1854;
  struct StateT * v1848 = slot_73(v1841);
  return v1848;
}

struct StateT * slot_119(struct StateT * v2593) {
  int v2594 = v2593->timer;
  int v2602 = v2594 + 1;
  v2593->timer = v2602;
  int * v2596 = v2593->regs;
  int v2597 = v2596[8];
  int * v2598 = v2593->regs;
  int v2606 = v2597 + 1;
  v2598[8] = v2606;
  struct StateT * v2600 = slot_120(v2593);
  return v2600;
}

struct StateT * slot_71(struct StateT * v1825) {
  int v1826 = v1825->timer;
  int v1834 = v1826 + 1;
  v1825->timer = v1834;
  int * v1828 = v1825->regs;
  int v1829 = v1828[8];
  int * v1830 = v1825->regs;
  int v1838 = v1829 + 1;
  v1830[8] = v1838;
  struct StateT * v1832 = slot_72(v1825);
  return v1832;
}

struct StateT * slot_101(struct StateT * v2305) {
  int v2306 = v2305->timer;
  int v2314 = v2306 + 1;
  v2305->timer = v2314;
  int * v2308 = v2305->regs;
  int v2309 = v2308[8];
  int * v2310 = v2305->regs;
  int v2318 = v2309 + 1;
  v2310[8] = v2318;
  struct StateT * v2312 = slot_102(v2305);
  return v2312;
}

struct StateT * slot_108(struct StateT * v2417) {
  int v2418 = v2417->timer;
  int v2426 = v2418 + 1;
  v2417->timer = v2426;
  int * v2420 = v2417->regs;
  int v2421 = v2420[8];
  int * v2422 = v2417->regs;
  int v2430 = v2421 + 1;
  v2422[8] = v2430;
  struct StateT * v2424 = slot_109(v2417);
  return v2424;
}

struct StateT * slot_116(struct StateT * v2545) {
  int v2546 = v2545->timer;
  int v2554 = v2546 + 1;
  v2545->timer = v2554;
  int * v2548 = v2545->regs;
  int v2549 = v2548[8];
  int * v2550 = v2545->regs;
  int v2558 = v2549 + 1;
  v2550[8] = v2558;
  struct StateT * v2552 = slot_117(v2545);
  return v2552;
}

struct StateT * slot_93(struct StateT * v2177) {
  int v2178 = v2177->timer;
  int v2186 = v2178 + 1;
  v2177->timer = v2186;
  int * v2180 = v2177->regs;
  int v2181 = v2180[8];
  int * v2182 = v2177->regs;
  int v2190 = v2181 + 1;
  v2182[8] = v2190;
  struct StateT * v2184 = slot_94(v2177);
  return v2184;
}

struct StateT * slot_88(struct StateT * v2097) {
  int v2098 = v2097->timer;
  int v2106 = v2098 + 1;
  v2097->timer = v2106;
  int * v2100 = v2097->regs;
  int v2101 = v2100[8];
  int * v2102 = v2097->regs;
  int v2110 = v2101 + 1;
  v2102[8] = v2110;
  struct StateT * v2104 = slot_89(v2097);
  return v2104;
}

struct StateT * slot_96(struct StateT * v2225) {
  int v2226 = v2225->timer;
  int v2234 = v2226 + 1;
  v2225->timer = v2234;
  int * v2228 = v2225->regs;
  int v2229 = v2228[8];
  int * v2230 = v2225->regs;
  int v2238 = v2229 + 1;
  v2230[8] = v2238;
  struct StateT * v2232 = slot_97(v2225);
  return v2232;
}

struct StateT * slot_215(struct StateT * v4129) {
  int v4130 = v4129->timer;
  int v4138 = v4130 + 1;
  v4129->timer = v4138;
  int * v4132 = v4129->regs;
  int v4133 = v4132[8];
  int * v4134 = v4129->regs;
  int v4142 = v4133 + 1;
  v4134[8] = v4142;
  struct StateT * v4136 = slot_216(v4129);
  return v4136;
}

struct StateT * slot_45(struct StateT * v1409) {
  int v1410 = v1409->timer;
  int v1418 = v1410 + 1;
  v1409->timer = v1418;
  int * v1412 = v1409->regs;
  int v1413 = v1412[8];
  int * v1414 = v1409->regs;
  int v1422 = v1413 + 1;
  v1414[8] = v1422;
  struct StateT * v1416 = slot_46(v1409);
  return v1416;
}

struct StateT * slot_218(struct StateT * v4177) {
  int v4178 = v4177->timer;
  int v4186 = v4178 + 1;
  v4177->timer = v4186;
  int * v4180 = v4177->regs;
  int v4181 = v4180[8];
  int * v4182 = v4177->regs;
  int v4190 = v4181 + 1;
  v4182[8] = v4190;
  struct StateT * v4184 = slot_219(v4177);
  return v4184;
}

struct StateT * slot_220(struct StateT * v4209) {
  int v4210 = v4209->timer;
  int v4218 = v4210 + 1;
  v4209->timer = v4218;
  int * v4212 = v4209->regs;
  int v4213 = v4212[8];
  int * v4214 = v4209->regs;
  int v4222 = v4213 + 1;
  v4214[8] = v4222;
  struct StateT * v4216 = slot_221(v4209);
  return v4216;
}

struct StateT * slot_134(struct StateT * v2833) {
  int v2834 = v2833->timer;
  int v2842 = v2834 + 1;
  v2833->timer = v2842;
  int * v2836 = v2833->regs;
  int v2837 = v2836[8];
  int * v2838 = v2833->regs;
  int v2846 = v2837 + 1;
  v2838[8] = v2846;
  struct StateT * v2840 = slot_135(v2833);
  return v2840;
}

struct StateT * slot_175(struct StateT * v3489) {
  int v3490 = v3489->timer;
  int v3498 = v3490 + 1;
  v3489->timer = v3498;
  int * v3492 = v3489->regs;
  int v3493 = v3492[8];
  int * v3494 = v3489->regs;
  int v3502 = v3493 + 1;
  v3494[8] = v3502;
  struct StateT * v3496 = slot_176(v3489);
  return v3496;
}

struct StateT * slot_69(struct StateT * v1793) {
  int v1794 = v1793->timer;
  int v1802 = v1794 + 1;
  v1793->timer = v1802;
  int * v1796 = v1793->regs;
  int v1797 = v1796[8];
  int * v1798 = v1793->regs;
  int v1806 = v1797 + 1;
  v1798[8] = v1806;
  struct StateT * v1800 = slot_70(v1793);
  return v1800;
}

struct StateT * slot_202(struct StateT * v3921) {
  int v3922 = v3921->timer;
  int v3930 = v3922 + 1;
  v3921->timer = v3930;
  int * v3924 = v3921->regs;
  int v3925 = v3924[8];
  int * v3926 = v3921->regs;
  int v3934 = v3925 + 1;
  v3926[8] = v3934;
  struct StateT * v3928 = slot_203(v3921);
  return v3928;
}

struct StateT * slot_188(struct StateT * v3697) {
  int v3698 = v3697->timer;
  int v3706 = v3698 + 1;
  v3697->timer = v3706;
  int * v3700 = v3697->regs;
  int v3701 = v3700[8];
  int * v3702 = v3697->regs;
  int v3710 = v3701 + 1;
  v3702[8] = v3710;
  struct StateT * v3704 = slot_189(v3697);
  return v3704;
}

struct StateT * slot_138(struct StateT * v2897) {
  int v2898 = v2897->timer;
  int v2906 = v2898 + 1;
  v2897->timer = v2906;
  int * v2900 = v2897->regs;
  int v2901 = v2900[8];
  int * v2902 = v2897->regs;
  int v2910 = v2901 + 1;
  v2902[8] = v2910;
  struct StateT * v2904 = slot_139(v2897);
  return v2904;
}

struct StateT * slot_186(struct StateT * v3665) {
  int v3666 = v3665->timer;
  int v3674 = v3666 + 1;
  v3665->timer = v3674;
  int * v3668 = v3665->regs;
  int v3669 = v3668[8];
  int * v3670 = v3665->regs;
  int v3678 = v3669 + 1;
  v3670[8] = v3678;
  struct StateT * v3672 = slot_187(v3665);
  return v3672;
}

struct StateT * slot_102(struct StateT * v2321) {
  int v2322 = v2321->timer;
  int v2330 = v2322 + 1;
  v2321->timer = v2330;
  int * v2324 = v2321->regs;
  int v2325 = v2324[8];
  int * v2326 = v2321->regs;
  int v2334 = v2325 + 1;
  v2326[8] = v2334;
  struct StateT * v2328 = slot_103(v2321);
  return v2328;
}

struct StateT * slot_145(struct StateT * v3009) {
  int v3010 = v3009->timer;
  int v3018 = v3010 + 1;
  v3009->timer = v3018;
  int * v3012 = v3009->regs;
  int v3013 = v3012[8];
  int * v3014 = v3009->regs;
  int v3022 = v3013 + 1;
  v3014[8] = v3022;
  struct StateT * v3016 = slot_146(v3009);
  return v3016;
}

struct StateT * slot_110(struct StateT * v2449) {
  int v2450 = v2449->timer;
  int v2458 = v2450 + 1;
  v2449->timer = v2458;
  int * v2452 = v2449->regs;
  int v2453 = v2452[8];
  int * v2454 = v2449->regs;
  int v2462 = v2453 + 1;
  v2454[8] = v2462;
  struct StateT * v2456 = slot_111(v2449);
  return v2456;
}

struct StateT * slot_196(struct StateT * v3825) {
  int v3826 = v3825->timer;
  int v3834 = v3826 + 1;
  v3825->timer = v3834;
  int * v3828 = v3825->regs;
  int v3829 = v3828[8];
  int * v3830 = v3825->regs;
  int v3838 = v3829 + 1;
  v3830[8] = v3838;
  struct StateT * v3832 = slot_197(v3825);
  return v3832;
}

struct StateT * slot_208(struct StateT * v4017) {
  int v4018 = v4017->timer;
  int v4026 = v4018 + 1;
  v4017->timer = v4026;
  int * v4020 = v4017->regs;
  int v4021 = v4020[8];
  int * v4022 = v4017->regs;
  int v4030 = v4021 + 1;
  v4022[8] = v4030;
  struct StateT * v4024 = slot_209(v4017);
  return v4024;
}

struct StateT * slot_172(struct StateT * v3441) {
  int v3442 = v3441->timer;
  int v3450 = v3442 + 1;
  v3441->timer = v3450;
  int * v3444 = v3441->regs;
  int v3445 = v3444[8];
  int * v3446 = v3441->regs;
  int v3454 = v3445 + 1;
  v3446[8] = v3454;
  struct StateT * v3448 = slot_173(v3441);
  return v3448;
}

struct StateT * slot_131(struct StateT * v2785) {
  int v2786 = v2785->timer;
  int v2794 = v2786 + 1;
  v2785->timer = v2794;
  int * v2788 = v2785->regs;
  int v2789 = v2788[8];
  int * v2790 = v2785->regs;
  int v2798 = v2789 + 1;
  v2790[8] = v2798;
  struct StateT * v2792 = slot_132(v2785);
  return v2792;
}

struct StateT * slot_8(struct StateT * v817) {
  int v818 = v817->timer;
  int v826 = v818 + 1;
  v817->timer = v826;
  int * v820 = v817->regs;
  int v821 = v820[8];
  int * v822 = v817->regs;
  int v830 = v821 + 1;
  v822[8] = v830;
  struct StateT * v824 = slot_9(v817);
  return v824;
}

struct StateT * slot_180(struct StateT * v3569) {
  int v3570 = v3569->timer;
  int v3578 = v3570 + 1;
  v3569->timer = v3578;
  int * v3572 = v3569->regs;
  int v3573 = v3572[8];
  int * v3574 = v3569->regs;
  int v3582 = v3573 + 1;
  v3574[8] = v3582;
  struct StateT * v3576 = slot_181(v3569);
  return v3576;
}

struct StateT * slot_203(struct StateT * v3937) {
  int v3938 = v3937->timer;
  int v3946 = v3938 + 1;
  v3937->timer = v3946;
  int * v3940 = v3937->regs;
  int v3941 = v3940[8];
  int * v3942 = v3937->regs;
  int v3950 = v3941 + 1;
  v3942[8] = v3950;
  struct StateT * v3944 = slot_204(v3937);
  return v3944;
}

struct StateT * slot_190(struct StateT * v3729) {
  int v3730 = v3729->timer;
  int v3738 = v3730 + 1;
  v3729->timer = v3738;
  int * v3732 = v3729->regs;
  int v3733 = v3732[8];
  int * v3734 = v3729->regs;
  int v3742 = v3733 + 1;
  v3734[8] = v3742;
  struct StateT * v3736 = slot_191(v3729);
  return v3736;
}

struct StateT * slot_157(struct StateT * v3201) {
  int v3202 = v3201->timer;
  int v3210 = v3202 + 1;
  v3201->timer = v3210;
  int * v3204 = v3201->regs;
  int v3205 = v3204[8];
  int * v3206 = v3201->regs;
  int v3214 = v3205 + 1;
  v3206[8] = v3214;
  struct StateT * v3208 = slot_158(v3201);
  return v3208;
}

struct StateT * slot_200(struct StateT * v3889) {
  int v3890 = v3889->timer;
  int v3898 = v3890 + 1;
  v3889->timer = v3898;
  int * v3892 = v3889->regs;
  int v3893 = v3892[8];
  int * v3894 = v3889->regs;
  int v3902 = v3893 + 1;
  v3894[8] = v3902;
  struct StateT * v3896 = slot_201(v3889);
  return v3896;
}

struct StateT * slot_173(struct StateT * v3457) {
  int v3458 = v3457->timer;
  int v3466 = v3458 + 1;
  v3457->timer = v3466;
  int * v3460 = v3457->regs;
  int v3461 = v3460[8];
  int * v3462 = v3457->regs;
  int v3470 = v3461 + 1;
  v3462[8] = v3470;
  struct StateT * v3464 = slot_174(v3457);
  return v3464;
}

struct StateT * slot_149(struct StateT * v3073) {
  int v3074 = v3073->timer;
  int v3082 = v3074 + 1;
  v3073->timer = v3082;
  int * v3076 = v3073->regs;
  int v3077 = v3076[8];
  int * v3078 = v3073->regs;
  int v3086 = v3077 + 1;
  v3078[8] = v3086;
  struct StateT * v3080 = slot_150(v3073);
  return v3080;
}

struct StateT * slot_5(struct StateT * v772) {
  int v773 = v772->timer;
  int v779 = v773 + 1;
  v772->timer = v779;
  int * v775 = v772->regs;
  v775[8] = 0;
  struct StateT * v777 = slot_6(v772);
  return v777;
}

struct StateT * slot_104(struct StateT * v2353) {
  int v2354 = v2353->timer;
  int v2362 = v2354 + 1;
  v2353->timer = v2362;
  int * v2356 = v2353->regs;
  int v2357 = v2356[8];
  int * v2358 = v2353->regs;
  int v2366 = v2357 + 1;
  v2358[8] = v2366;
  struct StateT * v2360 = slot_105(v2353);
  return v2360;
}

struct StateT * slot_54(struct StateT * v1553) {
  int v1554 = v1553->timer;
  int v1562 = v1554 + 1;
  v1553->timer = v1562;
  int * v1556 = v1553->regs;
  int v1557 = v1556[8];
  int * v1558 = v1553->regs;
  int v1566 = v1557 + 1;
  v1558[8] = v1566;
  struct StateT * v1560 = slot_55(v1553);
  return v1560;
}

struct StateT * slot_26(struct StateT * v1105) {
  int v1106 = v1105->timer;
  int v1114 = v1106 + 1;
  v1105->timer = v1114;
  int * v1108 = v1105->regs;
  int v1109 = v1108[8];
  int * v1110 = v1105->regs;
  int v1118 = v1109 + 1;
  v1110[8] = v1118;
  struct StateT * v1112 = slot_27(v1105);
  return v1112;
}

struct StateT * slot_206(struct StateT * v3985) {
  int v3986 = v3985->timer;
  int v3994 = v3986 + 1;
  v3985->timer = v3994;
  int * v3988 = v3985->regs;
  int v3989 = v3988[8];
  int * v3990 = v3985->regs;
  int v3998 = v3989 + 1;
  v3990[8] = v3998;
  struct StateT * v3992 = slot_207(v3985);
  return v3992;
}

struct StateT * slot_169(struct StateT * v3393) {
  int v3394 = v3393->timer;
  int v3402 = v3394 + 1;
  v3393->timer = v3402;
  int * v3396 = v3393->regs;
  int v3397 = v3396[8];
  int * v3398 = v3393->regs;
  int v3406 = v3397 + 1;
  v3398[8] = v3406;
  struct StateT * v3400 = slot_170(v3393);
  return v3400;
}

struct StateT * slot_64(struct StateT * v1713) {
  int v1714 = v1713->timer;
  int v1722 = v1714 + 1;
  v1713->timer = v1722;
  int * v1716 = v1713->regs;
  int v1717 = v1716[8];
  int * v1718 = v1713->regs;
  int v1726 = v1717 + 1;
  v1718[8] = v1726;
  struct StateT * v1720 = slot_65(v1713);
  return v1720;
}

struct StateT * slot_170(struct StateT * v3409) {
  int v3410 = v3409->timer;
  int v3418 = v3410 + 1;
  v3409->timer = v3418;
  int * v3412 = v3409->regs;
  int v3413 = v3412[8];
  int * v3414 = v3409->regs;
  int v3422 = v3413 + 1;
  v3414[8] = v3422;
  struct StateT * v3416 = slot_171(v3409);
  return v3416;
}

struct StateT * slot_14(struct StateT * v913) {
  int v914 = v913->timer;
  int v922 = v914 + 1;
  v913->timer = v922;
  int * v916 = v913->regs;
  int v917 = v916[8];
  int * v918 = v913->regs;
  int v926 = v917 + 1;
  v918[8] = v926;
  struct StateT * v920 = slot_15(v913);
  return v920;
}

struct StateT * slot_53(struct StateT * v1537) {
  int v1538 = v1537->timer;
  int v1546 = v1538 + 1;
  v1537->timer = v1546;
  int * v1540 = v1537->regs;
  int v1541 = v1540[8];
  int * v1542 = v1537->regs;
  int v1550 = v1541 + 1;
  v1542[8] = v1550;
  struct StateT * v1544 = slot_54(v1537);
  return v1544;
}

struct StateT * slot_80(struct StateT * v1969) {
  int v1970 = v1969->timer;
  int v1978 = v1970 + 1;
  v1969->timer = v1978;
  int * v1972 = v1969->regs;
  int v1973 = v1972[8];
  int * v1974 = v1969->regs;
  int v1982 = v1973 + 1;
  v1974[8] = v1982;
  struct StateT * v1976 = slot_81(v1969);
  return v1976;
}

struct StateT * slot_44(struct StateT * v1393) {
  int v1394 = v1393->timer;
  int v1402 = v1394 + 1;
  v1393->timer = v1402;
  int * v1396 = v1393->regs;
  int v1397 = v1396[8];
  int * v1398 = v1393->regs;
  int v1406 = v1397 + 1;
  v1398[8] = v1406;
  struct StateT * v1400 = slot_45(v1393);
  return v1400;
}

struct StateT * slot_137(struct StateT * v2881) {
  int v2882 = v2881->timer;
  int v2890 = v2882 + 1;
  v2881->timer = v2890;
  int * v2884 = v2881->regs;
  int v2885 = v2884[8];
  int * v2886 = v2881->regs;
  int v2894 = v2885 + 1;
  v2886[8] = v2894;
  struct StateT * v2888 = slot_138(v2881);
  return v2888;
}

struct StateT * slot_122(struct StateT * v2641) {
  int v2642 = v2641->timer;
  int v2650 = v2642 + 1;
  v2641->timer = v2650;
  int * v2644 = v2641->regs;
  int v2645 = v2644[8];
  int * v2646 = v2641->regs;
  int v2654 = v2645 + 1;
  v2646[8] = v2654;
  struct StateT * v2648 = slot_123(v2641);
  return v2648;
}

struct StateT * slot_99(struct StateT * v2273) {
  int v2274 = v2273->timer;
  int v2282 = v2274 + 1;
  v2273->timer = v2282;
  int * v2276 = v2273->regs;
  int v2277 = v2276[8];
  int * v2278 = v2273->regs;
  int v2286 = v2277 + 1;
  v2278[8] = v2286;
  struct StateT * v2280 = slot_100(v2273);
  return v2280;
}

struct StateT * slot_179(struct StateT * v3553) {
  int v3554 = v3553->timer;
  int v3562 = v3554 + 1;
  v3553->timer = v3562;
  int * v3556 = v3553->regs;
  int v3557 = v3556[8];
  int * v3558 = v3553->regs;
  int v3566 = v3557 + 1;
  v3558[8] = v3566;
  struct StateT * v3560 = slot_180(v3553);
  return v3560;
}

struct StateT * slot_219(struct StateT * v4193) {
  int v4194 = v4193->timer;
  int v4202 = v4194 + 1;
  v4193->timer = v4202;
  int * v4196 = v4193->regs;
  int v4197 = v4196[8];
  int * v4198 = v4193->regs;
  int v4206 = v4197 + 1;
  v4198[8] = v4206;
  struct StateT * v4200 = slot_220(v4193);
  return v4200;
}

struct StateT * slot_36(struct StateT * v1265) {
  int v1266 = v1265->timer;
  int v1274 = v1266 + 1;
  v1265->timer = v1274;
  int * v1268 = v1265->regs;
  int v1269 = v1268[8];
  int * v1270 = v1265->regs;
  int v1278 = v1269 + 1;
  v1270[8] = v1278;
  struct StateT * v1272 = slot_37(v1265);
  return v1272;
}

struct StateT * slot_57(struct StateT * v1601) {
  int v1602 = v1601->timer;
  int v1610 = v1602 + 1;
  v1601->timer = v1610;
  int * v1604 = v1601->regs;
  int v1605 = v1604[8];
  int * v1606 = v1601->regs;
  int v1614 = v1605 + 1;
  v1606[8] = v1614;
  struct StateT * v1608 = slot_58(v1601);
  return v1608;
}

struct StateT * slot_62(struct StateT * v1681) {
  int v1682 = v1681->timer;
  int v1690 = v1682 + 1;
  v1681->timer = v1690;
  int * v1684 = v1681->regs;
  int v1685 = v1684[8];
  int * v1686 = v1681->regs;
  int v1694 = v1685 + 1;
  v1686[8] = v1694;
  struct StateT * v1688 = slot_63(v1681);
  return v1688;
}

struct StateT * slot_22(struct StateT * v1041) {
  int v1042 = v1041->timer;
  int v1050 = v1042 + 1;
  v1041->timer = v1050;
  int * v1044 = v1041->regs;
  int v1045 = v1044[8];
  int * v1046 = v1041->regs;
  int v1054 = v1045 + 1;
  v1046[8] = v1054;
  struct StateT * v1048 = slot_23(v1041);
  return v1048;
}

struct StateT * slot_139(struct StateT * v2913) {
  int v2914 = v2913->timer;
  int v2922 = v2914 + 1;
  v2913->timer = v2922;
  int * v2916 = v2913->regs;
  int v2917 = v2916[8];
  int * v2918 = v2913->regs;
  int v2926 = v2917 + 1;
  v2918[8] = v2926;
  struct StateT * v2920 = slot_140(v2913);
  return v2920;
}

struct StateT * slot_221(struct StateT * v4225) {
  int v4226 = v4225->timer;
  int v4234 = v4226 + 1;
  v4225->timer = v4234;
  int * v4228 = v4225->regs;
  int v4229 = v4228[8];
  int * v4230 = v4225->regs;
  int v4238 = v4229 + 1;
  v4230[8] = v4238;
  struct StateT * v4232 = slot_222(v4225);
  return v4232;
}

struct StateT * slot_23(struct StateT * v1057) {
  int v1058 = v1057->timer;
  int v1066 = v1058 + 1;
  v1057->timer = v1066;
  int * v1060 = v1057->regs;
  int v1061 = v1060[8];
  int * v1062 = v1057->regs;
  int v1070 = v1061 + 1;
  v1062[8] = v1070;
  struct StateT * v1064 = slot_24(v1057);
  return v1064;
}

struct StateT * slot_153(struct StateT * v3137) {
  int v3138 = v3137->timer;
  int v3146 = v3138 + 1;
  v3137->timer = v3146;
  int * v3140 = v3137->regs;
  int v3141 = v3140[8];
  int * v3142 = v3137->regs;
  int v3150 = v3141 + 1;
  v3142[8] = v3150;
  struct StateT * v3144 = slot_154(v3137);
  return v3144;
}

struct StateT * slot_2(struct StateT * v490) {
  int v491 = v490->timer;
  int v499 = v491 + 1;
  v490->timer = v499;
  int * v493 = v490->regs;
  int v494 = v493[6];
  int * v495 = v490->regs;
  int v503 = v494 & 7;
  v495[6] = v503;
  struct StateT * v497 = slot_3(v490);
  return v497;
}

struct StateT * slot_86(struct StateT * v2065) {
  int v2066 = v2065->timer;
  int v2074 = v2066 + 1;
  v2065->timer = v2074;
  int * v2068 = v2065->regs;
  int v2069 = v2068[8];
  int * v2070 = v2065->regs;
  int v2078 = v2069 + 1;
  v2070[8] = v2078;
  struct StateT * v2072 = slot_87(v2065);
  return v2072;
}

struct StateT * slot_129(struct StateT * v2753) {
  int v2754 = v2753->timer;
  int v2762 = v2754 + 1;
  v2753->timer = v2762;
  int * v2756 = v2753->regs;
  int v2757 = v2756[8];
  int * v2758 = v2753->regs;
  int v2766 = v2757 + 1;
  v2758[8] = v2766;
  struct StateT * v2760 = slot_130(v2753);
  return v2760;
}

struct StateT * slot_158(struct StateT * v3217) {
  int v3218 = v3217->timer;
  int v3226 = v3218 + 1;
  v3217->timer = v3226;
  int * v3220 = v3217->regs;
  int v3221 = v3220[8];
  int * v3222 = v3217->regs;
  int v3230 = v3221 + 1;
  v3222[8] = v3230;
  struct StateT * v3224 = slot_159(v3217);
  return v3224;
}

struct StateT * slot_100(struct StateT * v2289) {
  int v2290 = v2289->timer;
  int v2298 = v2290 + 1;
  v2289->timer = v2298;
  int * v2292 = v2289->regs;
  int v2293 = v2292[8];
  int * v2294 = v2289->regs;
  int v2302 = v2293 + 1;
  v2294[8] = v2302;
  struct StateT * v2296 = slot_101(v2289);
  return v2296;
}

struct StateT * slot_127(struct StateT * v2721) {
  int v2722 = v2721->timer;
  int v2730 = v2722 + 1;
  v2721->timer = v2730;
  int * v2724 = v2721->regs;
  int v2725 = v2724[8];
  int * v2726 = v2721->regs;
  int v2734 = v2725 + 1;
  v2726[8] = v2734;
  struct StateT * v2728 = slot_128(v2721);
  return v2728;
}

struct StateT * slot_217(struct StateT * v4161) {
  int v4162 = v4161->timer;
  int v4170 = v4162 + 1;
  v4161->timer = v4170;
  int * v4164 = v4161->regs;
  int v4165 = v4164[8];
  int * v4166 = v4161->regs;
  int v4174 = v4165 + 1;
  v4166[8] = v4174;
  struct StateT * v4168 = slot_218(v4161);
  return v4168;
}

struct StateT * slot_13(struct StateT * v897) {
  int v898 = v897->timer;
  int v906 = v898 + 1;
  v897->timer = v906;
  int * v900 = v897->regs;
  int v901 = v900[8];
  int * v902 = v897->regs;
  int v910 = v901 + 1;
  v902[8] = v910;
  struct StateT * v904 = slot_14(v897);
  return v904;
}

struct StateT * slot_111(struct StateT * v2465) {
  int v2466 = v2465->timer;
  int v2474 = v2466 + 1;
  v2465->timer = v2474;
  int * v2468 = v2465->regs;
  int v2469 = v2468[8];
  int * v2470 = v2465->regs;
  int v2478 = v2469 + 1;
  v2470[8] = v2478;
  struct StateT * v2472 = slot_112(v2465);
  return v2472;
}

struct StateT * slot_109(struct StateT * v2433) {
  int v2434 = v2433->timer;
  int v2442 = v2434 + 1;
  v2433->timer = v2442;
  int * v2436 = v2433->regs;
  int v2437 = v2436[8];
  int * v2438 = v2433->regs;
  int v2446 = v2437 + 1;
  v2438[8] = v2446;
  struct StateT * v2440 = slot_110(v2433);
  return v2440;
}

struct StateT * slot_174(struct StateT * v3473) {
  int v3474 = v3473->timer;
  int v3482 = v3474 + 1;
  v3473->timer = v3482;
  int * v3476 = v3473->regs;
  int v3477 = v3476[8];
  int * v3478 = v3473->regs;
  int v3486 = v3477 + 1;
  v3478[8] = v3486;
  struct StateT * v3480 = slot_175(v3473);
  return v3480;
}

struct StateT * slot_147(struct StateT * v3041) {
  int v3042 = v3041->timer;
  int v3050 = v3042 + 1;
  v3041->timer = v3050;
  int * v3044 = v3041->regs;
  int v3045 = v3044[8];
  int * v3046 = v3041->regs;
  int v3054 = v3045 + 1;
  v3046[8] = v3054;
  struct StateT * v3048 = slot_148(v3041);
  return v3048;
}

struct StateT * slot_42(struct StateT * v1361) {
  int v1362 = v1361->timer;
  int v1370 = v1362 + 1;
  v1361->timer = v1370;
  int * v1364 = v1361->regs;
  int v1365 = v1364[8];
  int * v1366 = v1361->regs;
  int v1374 = v1365 + 1;
  v1366[8] = v1374;
  struct StateT * v1368 = slot_43(v1361);
  return v1368;
}

struct StateT * slot_224(struct StateT * v4273) {
  int v4274 = v4273->timer;
  int v4282 = v4274 + 1;
  v4273->timer = v4282;
  int * v4276 = v4273->regs;
  int v4277 = v4276[8];
  int * v4278 = v4273->regs;
  int v4286 = v4277 + 1;
  v4278[8] = v4286;
  struct StateT * v4280 = slot_225(v4273);
  return v4280;
}

struct StateT * slot_163(struct StateT * v3297) {
  int v3298 = v3297->timer;
  int v3306 = v3298 + 1;
  v3297->timer = v3306;
  int * v3300 = v3297->regs;
  int v3301 = v3300[8];
  int * v3302 = v3297->regs;
  int v3310 = v3301 + 1;
  v3302[8] = v3310;
  struct StateT * v3304 = slot_164(v3297);
  return v3304;
}

struct StateT * slot_184(struct StateT * v3633) {
  int v3634 = v3633->timer;
  int v3642 = v3634 + 1;
  v3633->timer = v3642;
  int * v3636 = v3633->regs;
  int v3637 = v3636[8];
  int * v3638 = v3633->regs;
  int v3646 = v3637 + 1;
  v3638[8] = v3646;
  struct StateT * v3640 = slot_185(v3633);
  return v3640;
}

struct StateT * slot_204(struct StateT * v3953) {
  int v3954 = v3953->timer;
  int v3962 = v3954 + 1;
  v3953->timer = v3962;
  int * v3956 = v3953->regs;
  int v3957 = v3956[8];
  int * v3958 = v3953->regs;
  int v3966 = v3957 + 1;
  v3958[8] = v3966;
  struct StateT * v3960 = slot_205(v3953);
  return v3960;
}

struct StateT * slot_194(struct StateT * v3793) {
  int v3794 = v3793->timer;
  int v3802 = v3794 + 1;
  v3793->timer = v3802;
  int * v3796 = v3793->regs;
  int v3797 = v3796[8];
  int * v3798 = v3793->regs;
  int v3806 = v3797 + 1;
  v3798[8] = v3806;
  struct StateT * v3800 = slot_195(v3793);
  return v3800;
}

struct StateT * slot_165(struct StateT * v3329) {
  int v3330 = v3329->timer;
  int v3338 = v3330 + 1;
  v3329->timer = v3338;
  int * v3332 = v3329->regs;
  int v3333 = v3332[8];
  int * v3334 = v3329->regs;
  int v3342 = v3333 + 1;
  v3334[8] = v3342;
  struct StateT * v3336 = slot_166(v3329);
  return v3336;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v2561) {
  int v2562 = v2561->timer;
  int v2570 = v2562 + 1;
  v2561->timer = v2570;
  int * v2564 = v2561->regs;
  int v2565 = v2564[8];
  int * v2566 = v2561->regs;
  int v2574 = v2565 + 1;
  v2566[8] = v2574;
  struct StateT * v2568 = slot_118(v2561);
  return v2568;
}

struct StateT * slot_90(struct StateT * v2129) {
  int v2130 = v2129->timer;
  int v2138 = v2130 + 1;
  v2129->timer = v2138;
  int * v2132 = v2129->regs;
  int v2133 = v2132[8];
  int * v2134 = v2129->regs;
  int v2142 = v2133 + 1;
  v2134[8] = v2142;
  struct StateT * v2136 = slot_91(v2129);
  return v2136;
}

struct StateT * slot_11(struct StateT * v865) {
  int v866 = v865->timer;
  int v874 = v866 + 1;
  v865->timer = v874;
  int * v868 = v865->regs;
  int v869 = v868[8];
  int * v870 = v865->regs;
  int v878 = v869 + 1;
  v870[8] = v878;
  struct StateT * v872 = slot_12(v865);
  return v872;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}