// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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

struct StateT * slot_12(struct StateT * v962);
struct StateT * slot_143(struct StateT * v4106);
struct StateT * slot_120(struct StateT * v3554);
struct StateT * slot_167(struct StateT * v4682);
struct StateT * slot_152(struct StateT * v4322);
struct StateT * slot_199(struct StateT * v5450);
struct StateT * slot_92(struct StateT * v2882);
struct StateT * slot_31(struct StateT * v1418);
struct StateT * slot_160(struct StateT * v4514);
struct StateT * slot_65(struct StateT * v2234);
struct StateT * slot_10(struct StateT * v914);
struct StateT * slot_150(struct StateT * v4274);
struct StateT * slot_74(struct StateT * v2450);
struct StateT * slot_107(struct StateT * v3242);
struct StateT * slot_136(struct StateT * v3938);
struct StateT * slot_84(struct StateT * v2690);
struct StateT * slot_28(struct StateT * v1346);
struct StateT * slot_155(struct StateT * v4394);
struct StateT * slot_177(struct StateT * v4922);
struct StateT * slot_17(struct StateT * v1082);
struct StateT * slot_181(struct StateT * v5018);
struct StateT * slot_197(struct StateT * v5402);
struct StateT * slot_207(struct StateT * v5642);
struct StateT * slot_156(struct StateT * v4418);
struct StateT * slot_154(struct StateT * v4370);
struct StateT * slot_68(struct StateT * v2306);
struct StateT * slot_105(struct StateT * v3194);
struct StateT * slot_27(struct StateT * v1322);
struct StateT * slot_164(struct StateT * v4610);
struct StateT * slot_15(struct StateT * v1034);
struct StateT * slot_133(struct StateT * v3866);
struct StateT * slot_56(struct StateT * v2018);
struct StateT * slot_222(struct StateT * v6002);
struct StateT * slot_34(struct StateT * v1490);
struct StateT * slot_171(struct StateT * v4778);
struct StateT * slot_162(struct StateT * v4562);
struct StateT * slot_21(struct StateT * v1178);
struct StateT * slot_118(struct StateT * v3506);
struct StateT * slot_121(struct StateT * v3578);
struct StateT * slot_144(struct StateT * v4130);
struct StateT * slot_201(struct StateT * v5498);
struct StateT * slot_94(struct StateT * v2930);
struct StateT * slot_63(struct StateT * v2186);
struct StateT * slot_146(struct StateT * v4178);
struct StateT * slot_24(struct StateT * v1250);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v5354);
struct StateT * slot_125(struct StateT * v3674);
struct StateT * slot_148(struct StateT * v4226);
struct StateT * slot_126(struct StateT * v3698);
struct StateT * slot_223(struct StateT * v6026);
struct StateT * slot_79(struct StateT * v2570);
struct StateT * slot_41(struct StateT * v1658);
struct StateT * slot_39(struct StateT * v1610);
struct StateT * slot_142(struct StateT * v4082);
struct StateT * slot_60(struct StateT * v2114);
struct StateT * slot_112(struct StateT * v3362);
struct StateT * slot_47(struct StateT * v1802);
struct StateT * slot_214(struct StateT * v5810);
struct StateT * slot_29(struct StateT * v1370);
struct StateT * slot_16(struct StateT * v1058);
struct StateT * slot_113(struct StateT * v3386);
struct StateT * slot_151(struct StateT * v4298);
struct StateT * slot_7(struct StateT * v842);
struct StateT * slot_124(struct StateT * v3650);
struct StateT * slot_191(struct StateT * v5258);
struct StateT * slot_103(struct StateT * v3146);
struct StateT * slot_128(struct StateT * v3746);
struct StateT * slot_19(struct StateT * v1130);
struct StateT * slot_87(struct StateT * v2762);
struct StateT * slot_67(struct StateT * v2282);
struct StateT * slot_81(struct StateT * v2618);
struct StateT * slot_95(struct StateT * v2954);
struct StateT * slot_115(struct StateT * v3434);
struct StateT * slot_78(struct StateT * v2546);
struct StateT * slot_32(struct StateT * v1442);
struct StateT * slot_205(struct StateT * v5594);
struct StateT * slot_193(struct StateT * v5306);
struct StateT * slot_176(struct StateT * v4898);
struct StateT * slot_189(struct StateT * v5210);
struct StateT * slot_33(struct StateT * v1466);
struct StateT * slot_35(struct StateT * v1514);
struct StateT * slot_210(struct StateT * v5714);
struct StateT * slot_166(struct StateT * v4658);
struct StateT * slot_51(struct StateT * v1898);
struct StateT * slot_52(struct StateT * v1922);
struct StateT * slot_83(struct StateT * v2666);
struct StateT * slot_25(struct StateT * v1274);
struct StateT * slot_209(struct StateT * v5690);
struct StateT * slot_3(struct StateT * v521);
struct StateT * slot_123(struct StateT * v3626);
struct StateT * slot_73(struct StateT * v2426);
struct StateT * slot_198(struct StateT * v5426);
struct StateT * slot_1(struct StateT * v257);
struct StateT * slot_187(struct StateT * v5162);
struct StateT * slot_97(struct StateT * v3002);
struct StateT * slot_182(struct StateT * v5042);
struct StateT * slot_38(struct StateT * v1586);
struct StateT * slot_178(struct StateT * v4946);
struct StateT * slot_106(struct StateT * v3218);
struct StateT * slot_98(struct StateT * v3026);
struct StateT * slot_159(struct StateT * v4490);
struct StateT * slot_46(struct StateT * v1778);
struct StateT * slot_212(struct StateT * v5762);
struct StateT * slot_132(struct StateT * v3842);
struct StateT * slot_130(struct StateT * v3794);
struct StateT * slot_211(struct StateT * v5738);
struct StateT * slot_20(struct StateT * v1154);
struct StateT * slot_141(struct StateT * v4058);
struct StateT * slot_61(struct StateT * v2138);
struct StateT * slot_30(struct StateT * v1394);
struct StateT * slot_4(struct StateT * v545);
struct StateT * slot_18(struct StateT * v1106);
struct StateT * slot_9(struct StateT * v890);
struct StateT * slot_183(struct StateT * v5066);
struct StateT * slot_43(struct StateT * v1706);
struct StateT * slot_70(struct StateT * v2354);
struct StateT * slot_168(struct StateT * v4706);
struct StateT * slot_76(struct StateT * v2498);
struct StateT * slot_6(struct StateT * v818);
struct StateT * slot_225(struct StateT * v6074);
struct StateT * slot_55(struct StateT * v1994);
struct StateT * slot_213(struct StateT * v5786);
struct StateT * slot_82(struct StateT * v2642);
struct StateT * slot_161(struct StateT * v4538);
struct StateT * slot_185(struct StateT * v5114);
struct StateT * slot_91(struct StateT * v2858);
struct StateT * slot_58(struct StateT * v2066);
struct StateT * slot_89(struct StateT * v2810);
struct StateT * slot_66(struct StateT * v2258);
struct StateT * slot_140(struct StateT * v4034);
struct StateT * slot_49(struct StateT * v1850);
struct StateT * slot_216(struct StateT * v5858);
struct StateT * slot_50(struct StateT * v1874);
struct StateT * slot_37(struct StateT * v1562);
struct StateT * slot_114(struct StateT * v3410);
struct StateT * slot_135(struct StateT * v3914);
struct StateT * slot_59(struct StateT * v2090);
struct StateT * slot_192(struct StateT * v5282);
struct StateT * slot_40(struct StateT * v1634);
struct StateT * slot_48(struct StateT * v1826);
struct StateT * slot_77(struct StateT * v2522);
struct StateT * slot_85(struct StateT * v2714);
struct StateT * slot_75(struct StateT * v2474);
struct StateT * slot_72(struct StateT * v2402);
struct StateT * slot_119(struct StateT * v3530);
struct StateT * slot_71(struct StateT * v2378);
struct StateT * slot_101(struct StateT * v3098);
struct StateT * slot_108(struct StateT * v3266);
struct StateT * slot_116(struct StateT * v3458);
struct StateT * slot_93(struct StateT * v2906);
struct StateT * slot_88(struct StateT * v2786);
struct StateT * slot_96(struct StateT * v2978);
struct StateT * slot_215(struct StateT * v5834);
struct StateT * slot_45(struct StateT * v1754);
struct StateT * slot_218(struct StateT * v5906);
struct StateT * slot_220(struct StateT * v5954);
struct StateT * slot_134(struct StateT * v3890);
struct StateT * slot_175(struct StateT * v4874);
struct StateT * slot_69(struct StateT * v2330);
struct StateT * slot_202(struct StateT * v5522);
struct StateT * slot_188(struct StateT * v5186);
struct StateT * slot_138(struct StateT * v3986);
struct StateT * slot_186(struct StateT * v5138);
struct StateT * slot_102(struct StateT * v3122);
struct StateT * slot_145(struct StateT * v4154);
struct StateT * slot_110(struct StateT * v3314);
struct StateT * slot_196(struct StateT * v5378);
struct StateT * slot_208(struct StateT * v5666);
struct StateT * slot_172(struct StateT * v4802);
struct StateT * slot_131(struct StateT * v3818);
struct StateT * slot_8(struct StateT * v866);
struct StateT * slot_180(struct StateT * v4994);
struct StateT * slot_203(struct StateT * v5546);
struct StateT * slot_190(struct StateT * v5234);
struct StateT * slot_157(struct StateT * v4442);
struct StateT * slot_200(struct StateT * v5474);
struct StateT * slot_173(struct StateT * v4826);
struct StateT * slot_149(struct StateT * v4250);
struct StateT * slot_5(struct StateT * v800);
struct StateT * slot_104(struct StateT * v3170);
struct StateT * slot_54(struct StateT * v1970);
struct StateT * slot_26(struct StateT * v1298);
struct StateT * slot_206(struct StateT * v5618);
struct StateT * slot_169(struct StateT * v4730);
struct StateT * slot_64(struct StateT * v2210);
struct StateT * slot_170(struct StateT * v4754);
struct StateT * slot_14(struct StateT * v1010);
struct StateT * slot_53(struct StateT * v1946);
struct StateT * slot_80(struct StateT * v2594);
struct StateT * slot_44(struct StateT * v1730);
struct StateT * slot_137(struct StateT * v3962);
struct StateT * slot_122(struct StateT * v3602);
struct StateT * slot_99(struct StateT * v3050);
struct StateT * slot_179(struct StateT * v4970);
struct StateT * slot_219(struct StateT * v5930);
struct StateT * slot_36(struct StateT * v1538);
struct StateT * slot_57(struct StateT * v2042);
struct StateT * slot_62(struct StateT * v2162);
struct StateT * slot_22(struct StateT * v1202);
struct StateT * slot_139(struct StateT * v4010);
struct StateT * slot_221(struct StateT * v5978);
struct StateT * slot_23(struct StateT * v1226);
struct StateT * slot_153(struct StateT * v4346);
struct StateT * slot_2(struct StateT * v497);
struct StateT * slot_86(struct StateT * v2738);
struct StateT * slot_129(struct StateT * v3770);
struct StateT * slot_158(struct StateT * v4466);
struct StateT * slot_100(struct StateT * v3074);
struct StateT * slot_127(struct StateT * v3722);
struct StateT * slot_217(struct StateT * v5882);
struct StateT * slot_13(struct StateT * v986);
struct StateT * slot_111(struct StateT * v3338);
struct StateT * slot_109(struct StateT * v3290);
struct StateT * slot_174(struct StateT * v4850);
struct StateT * slot_147(struct StateT * v4202);
struct StateT * slot_42(struct StateT * v1682);
struct StateT * slot_224(struct StateT * v6050);
struct StateT * slot_163(struct StateT * v4586);
struct StateT * slot_184(struct StateT * v5090);
struct StateT * slot_204(struct StateT * v5570);
struct StateT * slot_194(struct StateT * v5330);
struct StateT * slot_165(struct StateT * v4634);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v3482);
struct StateT * slot_90(struct StateT * v2834);
struct StateT * slot_11(struct StateT * v938);
struct StateT * slot_12(struct StateT * v962) {
  int v963 = v962->timer;
  int v964 = v962->timer;
  int v976 = v964 + 1;
  v962->timer = v976;
  int * v966 = v962->reg_ready;
  int v967 = v966[8];
  int * v968 = v962->regs;
  int v969 = v968[8];
  int * v970 = v962->reg_ready;
  int v981 = (v967 + ((v963 - v967) & (~((v963 - v967) >> 31)))) + 1;
  v970[8] = v981;
  int * v972 = v962->regs;
  int v983 = v969 + 1;
  v972[8] = v983;
  struct StateT * v974 = slot_13(v962);
  return v974;
}

struct StateT * slot_143(struct StateT * v4106) {
  int v4107 = v4106->timer;
  int v4108 = v4106->timer;
  int v4120 = v4108 + 1;
  v4106->timer = v4120;
  int * v4110 = v4106->reg_ready;
  int v4111 = v4110[8];
  int * v4112 = v4106->regs;
  int v4113 = v4112[8];
  int * v4114 = v4106->reg_ready;
  int v4125 = (v4111 + ((v4107 - v4111) & (~((v4107 - v4111) >> 31)))) + 1;
  v4114[8] = v4125;
  int * v4116 = v4106->regs;
  int v4127 = v4113 + 1;
  v4116[8] = v4127;
  struct StateT * v4118 = slot_144(v4106);
  return v4118;
}

struct StateT * slot_120(struct StateT * v3554) {
  int v3555 = v3554->timer;
  int v3556 = v3554->timer;
  int v3568 = v3556 + 1;
  v3554->timer = v3568;
  int * v3558 = v3554->reg_ready;
  int v3559 = v3558[8];
  int * v3560 = v3554->regs;
  int v3561 = v3560[8];
  int * v3562 = v3554->reg_ready;
  int v3573 = (v3559 + ((v3555 - v3559) & (~((v3555 - v3559) >> 31)))) + 1;
  v3562[8] = v3573;
  int * v3564 = v3554->regs;
  int v3575 = v3561 + 1;
  v3564[8] = v3575;
  struct StateT * v3566 = slot_121(v3554);
  return v3566;
}

struct StateT * slot_167(struct StateT * v4682) {
  int v4683 = v4682->timer;
  int v4684 = v4682->timer;
  int v4696 = v4684 + 1;
  v4682->timer = v4696;
  int * v4686 = v4682->reg_ready;
  int v4687 = v4686[8];
  int * v4688 = v4682->regs;
  int v4689 = v4688[8];
  int * v4690 = v4682->reg_ready;
  int v4701 = (v4687 + ((v4683 - v4687) & (~((v4683 - v4687) >> 31)))) + 1;
  v4690[8] = v4701;
  int * v4692 = v4682->regs;
  int v4703 = v4689 + 1;
  v4692[8] = v4703;
  struct StateT * v4694 = slot_168(v4682);
  return v4694;
}

struct StateT * slot_152(struct StateT * v4322) {
  int v4323 = v4322->timer;
  int v4324 = v4322->timer;
  int v4336 = v4324 + 1;
  v4322->timer = v4336;
  int * v4326 = v4322->reg_ready;
  int v4327 = v4326[8];
  int * v4328 = v4322->regs;
  int v4329 = v4328[8];
  int * v4330 = v4322->reg_ready;
  int v4341 = (v4327 + ((v4323 - v4327) & (~((v4323 - v4327) >> 31)))) + 1;
  v4330[8] = v4341;
  int * v4332 = v4322->regs;
  int v4343 = v4329 + 1;
  v4332[8] = v4343;
  struct StateT * v4334 = slot_153(v4322);
  return v4334;
}

struct StateT * slot_199(struct StateT * v5450) {
  int v5451 = v5450->timer;
  int v5452 = v5450->timer;
  int v5464 = v5452 + 1;
  v5450->timer = v5464;
  int * v5454 = v5450->reg_ready;
  int v5455 = v5454[8];
  int * v5456 = v5450->regs;
  int v5457 = v5456[8];
  int * v5458 = v5450->reg_ready;
  int v5469 = (v5455 + ((v5451 - v5455) & (~((v5451 - v5455) >> 31)))) + 1;
  v5458[8] = v5469;
  int * v5460 = v5450->regs;
  int v5471 = v5457 + 1;
  v5460[8] = v5471;
  struct StateT * v5462 = slot_200(v5450);
  return v5462;
}

struct StateT * slot_92(struct StateT * v2882) {
  int v2883 = v2882->timer;
  int v2884 = v2882->timer;
  int v2896 = v2884 + 1;
  v2882->timer = v2896;
  int * v2886 = v2882->reg_ready;
  int v2887 = v2886[8];
  int * v2888 = v2882->regs;
  int v2889 = v2888[8];
  int * v2890 = v2882->reg_ready;
  int v2901 = (v2887 + ((v2883 - v2887) & (~((v2883 - v2887) >> 31)))) + 1;
  v2890[8] = v2901;
  int * v2892 = v2882->regs;
  int v2903 = v2889 + 1;
  v2892[8] = v2903;
  struct StateT * v2894 = slot_93(v2882);
  return v2894;
}

struct StateT * slot_31(struct StateT * v1418) {
  int v1419 = v1418->timer;
  int v1420 = v1418->timer;
  int v1432 = v1420 + 1;
  v1418->timer = v1432;
  int * v1422 = v1418->reg_ready;
  int v1423 = v1422[8];
  int * v1424 = v1418->regs;
  int v1425 = v1424[8];
  int * v1426 = v1418->reg_ready;
  int v1437 = (v1423 + ((v1419 - v1423) & (~((v1419 - v1423) >> 31)))) + 1;
  v1426[8] = v1437;
  int * v1428 = v1418->regs;
  int v1439 = v1425 + 1;
  v1428[8] = v1439;
  struct StateT * v1430 = slot_32(v1418);
  return v1430;
}

struct StateT * slot_160(struct StateT * v4514) {
  int v4515 = v4514->timer;
  int v4516 = v4514->timer;
  int v4528 = v4516 + 1;
  v4514->timer = v4528;
  int * v4518 = v4514->reg_ready;
  int v4519 = v4518[8];
  int * v4520 = v4514->regs;
  int v4521 = v4520[8];
  int * v4522 = v4514->reg_ready;
  int v4533 = (v4519 + ((v4515 - v4519) & (~((v4515 - v4519) >> 31)))) + 1;
  v4522[8] = v4533;
  int * v4524 = v4514->regs;
  int v4535 = v4521 + 1;
  v4524[8] = v4535;
  struct StateT * v4526 = slot_161(v4514);
  return v4526;
}

struct StateT * slot_65(struct StateT * v2234) {
  int v2235 = v2234->timer;
  int v2236 = v2234->timer;
  int v2248 = v2236 + 1;
  v2234->timer = v2248;
  int * v2238 = v2234->reg_ready;
  int v2239 = v2238[8];
  int * v2240 = v2234->regs;
  int v2241 = v2240[8];
  int * v2242 = v2234->reg_ready;
  int v2253 = (v2239 + ((v2235 - v2239) & (~((v2235 - v2239) >> 31)))) + 1;
  v2242[8] = v2253;
  int * v2244 = v2234->regs;
  int v2255 = v2241 + 1;
  v2244[8] = v2255;
  struct StateT * v2246 = slot_66(v2234);
  return v2246;
}

struct StateT * slot_10(struct StateT * v914) {
  int v915 = v914->timer;
  int v916 = v914->timer;
  int v928 = v916 + 1;
  v914->timer = v928;
  int * v918 = v914->reg_ready;
  int v919 = v918[8];
  int * v920 = v914->regs;
  int v921 = v920[8];
  int * v922 = v914->reg_ready;
  int v933 = (v919 + ((v915 - v919) & (~((v915 - v919) >> 31)))) + 1;
  v922[8] = v933;
  int * v924 = v914->regs;
  int v935 = v921 + 1;
  v924[8] = v935;
  struct StateT * v926 = slot_11(v914);
  return v926;
}

struct StateT * slot_150(struct StateT * v4274) {
  int v4275 = v4274->timer;
  int v4276 = v4274->timer;
  int v4288 = v4276 + 1;
  v4274->timer = v4288;
  int * v4278 = v4274->reg_ready;
  int v4279 = v4278[8];
  int * v4280 = v4274->regs;
  int v4281 = v4280[8];
  int * v4282 = v4274->reg_ready;
  int v4293 = (v4279 + ((v4275 - v4279) & (~((v4275 - v4279) >> 31)))) + 1;
  v4282[8] = v4293;
  int * v4284 = v4274->regs;
  int v4295 = v4281 + 1;
  v4284[8] = v4295;
  struct StateT * v4286 = slot_151(v4274);
  return v4286;
}

struct StateT * slot_74(struct StateT * v2450) {
  int v2451 = v2450->timer;
  int v2452 = v2450->timer;
  int v2464 = v2452 + 1;
  v2450->timer = v2464;
  int * v2454 = v2450->reg_ready;
  int v2455 = v2454[8];
  int * v2456 = v2450->regs;
  int v2457 = v2456[8];
  int * v2458 = v2450->reg_ready;
  int v2469 = (v2455 + ((v2451 - v2455) & (~((v2451 - v2455) >> 31)))) + 1;
  v2458[8] = v2469;
  int * v2460 = v2450->regs;
  int v2471 = v2457 + 1;
  v2460[8] = v2471;
  struct StateT * v2462 = slot_75(v2450);
  return v2462;
}

struct StateT * slot_107(struct StateT * v3242) {
  int v3243 = v3242->timer;
  int v3244 = v3242->timer;
  int v3256 = v3244 + 1;
  v3242->timer = v3256;
  int * v3246 = v3242->reg_ready;
  int v3247 = v3246[8];
  int * v3248 = v3242->regs;
  int v3249 = v3248[8];
  int * v3250 = v3242->reg_ready;
  int v3261 = (v3247 + ((v3243 - v3247) & (~((v3243 - v3247) >> 31)))) + 1;
  v3250[8] = v3261;
  int * v3252 = v3242->regs;
  int v3263 = v3249 + 1;
  v3252[8] = v3263;
  struct StateT * v3254 = slot_108(v3242);
  return v3254;
}

struct StateT * slot_136(struct StateT * v3938) {
  int v3939 = v3938->timer;
  int v3940 = v3938->timer;
  int v3952 = v3940 + 1;
  v3938->timer = v3952;
  int * v3942 = v3938->reg_ready;
  int v3943 = v3942[8];
  int * v3944 = v3938->regs;
  int v3945 = v3944[8];
  int * v3946 = v3938->reg_ready;
  int v3957 = (v3943 + ((v3939 - v3943) & (~((v3939 - v3943) >> 31)))) + 1;
  v3946[8] = v3957;
  int * v3948 = v3938->regs;
  int v3959 = v3945 + 1;
  v3948[8] = v3959;
  struct StateT * v3950 = slot_137(v3938);
  return v3950;
}

struct StateT * slot_84(struct StateT * v2690) {
  int v2691 = v2690->timer;
  int v2692 = v2690->timer;
  int v2704 = v2692 + 1;
  v2690->timer = v2704;
  int * v2694 = v2690->reg_ready;
  int v2695 = v2694[8];
  int * v2696 = v2690->regs;
  int v2697 = v2696[8];
  int * v2698 = v2690->reg_ready;
  int v2709 = (v2695 + ((v2691 - v2695) & (~((v2691 - v2695) >> 31)))) + 1;
  v2698[8] = v2709;
  int * v2700 = v2690->regs;
  int v2711 = v2697 + 1;
  v2700[8] = v2711;
  struct StateT * v2702 = slot_85(v2690);
  return v2702;
}

struct StateT * slot_28(struct StateT * v1346) {
  int v1347 = v1346->timer;
  int v1348 = v1346->timer;
  int v1360 = v1348 + 1;
  v1346->timer = v1360;
  int * v1350 = v1346->reg_ready;
  int v1351 = v1350[8];
  int * v1352 = v1346->regs;
  int v1353 = v1352[8];
  int * v1354 = v1346->reg_ready;
  int v1365 = (v1351 + ((v1347 - v1351) & (~((v1347 - v1351) >> 31)))) + 1;
  v1354[8] = v1365;
  int * v1356 = v1346->regs;
  int v1367 = v1353 + 1;
  v1356[8] = v1367;
  struct StateT * v1358 = slot_29(v1346);
  return v1358;
}

struct StateT * slot_155(struct StateT * v4394) {
  int v4395 = v4394->timer;
  int v4396 = v4394->timer;
  int v4408 = v4396 + 1;
  v4394->timer = v4408;
  int * v4398 = v4394->reg_ready;
  int v4399 = v4398[8];
  int * v4400 = v4394->regs;
  int v4401 = v4400[8];
  int * v4402 = v4394->reg_ready;
  int v4413 = (v4399 + ((v4395 - v4399) & (~((v4395 - v4399) >> 31)))) + 1;
  v4402[8] = v4413;
  int * v4404 = v4394->regs;
  int v4415 = v4401 + 1;
  v4404[8] = v4415;
  struct StateT * v4406 = slot_156(v4394);
  return v4406;
}

struct StateT * slot_177(struct StateT * v4922) {
  int v4923 = v4922->timer;
  int v4924 = v4922->timer;
  int v4936 = v4924 + 1;
  v4922->timer = v4936;
  int * v4926 = v4922->reg_ready;
  int v4927 = v4926[8];
  int * v4928 = v4922->regs;
  int v4929 = v4928[8];
  int * v4930 = v4922->reg_ready;
  int v4941 = (v4927 + ((v4923 - v4927) & (~((v4923 - v4927) >> 31)))) + 1;
  v4930[8] = v4941;
  int * v4932 = v4922->regs;
  int v4943 = v4929 + 1;
  v4932[8] = v4943;
  struct StateT * v4934 = slot_178(v4922);
  return v4934;
}

struct StateT * slot_17(struct StateT * v1082) {
  int v1083 = v1082->timer;
  int v1084 = v1082->timer;
  int v1096 = v1084 + 1;
  v1082->timer = v1096;
  int * v1086 = v1082->reg_ready;
  int v1087 = v1086[8];
  int * v1088 = v1082->regs;
  int v1089 = v1088[8];
  int * v1090 = v1082->reg_ready;
  int v1101 = (v1087 + ((v1083 - v1087) & (~((v1083 - v1087) >> 31)))) + 1;
  v1090[8] = v1101;
  int * v1092 = v1082->regs;
  int v1103 = v1089 + 1;
  v1092[8] = v1103;
  struct StateT * v1094 = slot_18(v1082);
  return v1094;
}

struct StateT * slot_181(struct StateT * v5018) {
  int v5019 = v5018->timer;
  int v5020 = v5018->timer;
  int v5032 = v5020 + 1;
  v5018->timer = v5032;
  int * v5022 = v5018->reg_ready;
  int v5023 = v5022[8];
  int * v5024 = v5018->regs;
  int v5025 = v5024[8];
  int * v5026 = v5018->reg_ready;
  int v5037 = (v5023 + ((v5019 - v5023) & (~((v5019 - v5023) >> 31)))) + 1;
  v5026[8] = v5037;
  int * v5028 = v5018->regs;
  int v5039 = v5025 + 1;
  v5028[8] = v5039;
  struct StateT * v5030 = slot_182(v5018);
  return v5030;
}

struct StateT * slot_197(struct StateT * v5402) {
  int v5403 = v5402->timer;
  int v5404 = v5402->timer;
  int v5416 = v5404 + 1;
  v5402->timer = v5416;
  int * v5406 = v5402->reg_ready;
  int v5407 = v5406[8];
  int * v5408 = v5402->regs;
  int v5409 = v5408[8];
  int * v5410 = v5402->reg_ready;
  int v5421 = (v5407 + ((v5403 - v5407) & (~((v5403 - v5407) >> 31)))) + 1;
  v5410[8] = v5421;
  int * v5412 = v5402->regs;
  int v5423 = v5409 + 1;
  v5412[8] = v5423;
  struct StateT * v5414 = slot_198(v5402);
  return v5414;
}

struct StateT * slot_207(struct StateT * v5642) {
  int v5643 = v5642->timer;
  int v5644 = v5642->timer;
  int v5656 = v5644 + 1;
  v5642->timer = v5656;
  int * v5646 = v5642->reg_ready;
  int v5647 = v5646[8];
  int * v5648 = v5642->regs;
  int v5649 = v5648[8];
  int * v5650 = v5642->reg_ready;
  int v5661 = (v5647 + ((v5643 - v5647) & (~((v5643 - v5647) >> 31)))) + 1;
  v5650[8] = v5661;
  int * v5652 = v5642->regs;
  int v5663 = v5649 + 1;
  v5652[8] = v5663;
  struct StateT * v5654 = slot_208(v5642);
  return v5654;
}

struct StateT * slot_156(struct StateT * v4418) {
  int v4419 = v4418->timer;
  int v4420 = v4418->timer;
  int v4432 = v4420 + 1;
  v4418->timer = v4432;
  int * v4422 = v4418->reg_ready;
  int v4423 = v4422[8];
  int * v4424 = v4418->regs;
  int v4425 = v4424[8];
  int * v4426 = v4418->reg_ready;
  int v4437 = (v4423 + ((v4419 - v4423) & (~((v4419 - v4423) >> 31)))) + 1;
  v4426[8] = v4437;
  int * v4428 = v4418->regs;
  int v4439 = v4425 + 1;
  v4428[8] = v4439;
  struct StateT * v4430 = slot_157(v4418);
  return v4430;
}

struct StateT * slot_154(struct StateT * v4370) {
  int v4371 = v4370->timer;
  int v4372 = v4370->timer;
  int v4384 = v4372 + 1;
  v4370->timer = v4384;
  int * v4374 = v4370->reg_ready;
  int v4375 = v4374[8];
  int * v4376 = v4370->regs;
  int v4377 = v4376[8];
  int * v4378 = v4370->reg_ready;
  int v4389 = (v4375 + ((v4371 - v4375) & (~((v4371 - v4375) >> 31)))) + 1;
  v4378[8] = v4389;
  int * v4380 = v4370->regs;
  int v4391 = v4377 + 1;
  v4380[8] = v4391;
  struct StateT * v4382 = slot_155(v4370);
  return v4382;
}

struct StateT * slot_68(struct StateT * v2306) {
  int v2307 = v2306->timer;
  int v2308 = v2306->timer;
  int v2320 = v2308 + 1;
  v2306->timer = v2320;
  int * v2310 = v2306->reg_ready;
  int v2311 = v2310[8];
  int * v2312 = v2306->regs;
  int v2313 = v2312[8];
  int * v2314 = v2306->reg_ready;
  int v2325 = (v2311 + ((v2307 - v2311) & (~((v2307 - v2311) >> 31)))) + 1;
  v2314[8] = v2325;
  int * v2316 = v2306->regs;
  int v2327 = v2313 + 1;
  v2316[8] = v2327;
  struct StateT * v2318 = slot_69(v2306);
  return v2318;
}

struct StateT * slot_105(struct StateT * v3194) {
  int v3195 = v3194->timer;
  int v3196 = v3194->timer;
  int v3208 = v3196 + 1;
  v3194->timer = v3208;
  int * v3198 = v3194->reg_ready;
  int v3199 = v3198[8];
  int * v3200 = v3194->regs;
  int v3201 = v3200[8];
  int * v3202 = v3194->reg_ready;
  int v3213 = (v3199 + ((v3195 - v3199) & (~((v3195 - v3199) >> 31)))) + 1;
  v3202[8] = v3213;
  int * v3204 = v3194->regs;
  int v3215 = v3201 + 1;
  v3204[8] = v3215;
  struct StateT * v3206 = slot_106(v3194);
  return v3206;
}

struct StateT * slot_27(struct StateT * v1322) {
  int v1323 = v1322->timer;
  int v1324 = v1322->timer;
  int v1336 = v1324 + 1;
  v1322->timer = v1336;
  int * v1326 = v1322->reg_ready;
  int v1327 = v1326[8];
  int * v1328 = v1322->regs;
  int v1329 = v1328[8];
  int * v1330 = v1322->reg_ready;
  int v1341 = (v1327 + ((v1323 - v1327) & (~((v1323 - v1327) >> 31)))) + 1;
  v1330[8] = v1341;
  int * v1332 = v1322->regs;
  int v1343 = v1329 + 1;
  v1332[8] = v1343;
  struct StateT * v1334 = slot_28(v1322);
  return v1334;
}

struct StateT * slot_164(struct StateT * v4610) {
  int v4611 = v4610->timer;
  int v4612 = v4610->timer;
  int v4624 = v4612 + 1;
  v4610->timer = v4624;
  int * v4614 = v4610->reg_ready;
  int v4615 = v4614[8];
  int * v4616 = v4610->regs;
  int v4617 = v4616[8];
  int * v4618 = v4610->reg_ready;
  int v4629 = (v4615 + ((v4611 - v4615) & (~((v4611 - v4615) >> 31)))) + 1;
  v4618[8] = v4629;
  int * v4620 = v4610->regs;
  int v4631 = v4617 + 1;
  v4620[8] = v4631;
  struct StateT * v4622 = slot_165(v4610);
  return v4622;
}

struct StateT * slot_15(struct StateT * v1034) {
  int v1035 = v1034->timer;
  int v1036 = v1034->timer;
  int v1048 = v1036 + 1;
  v1034->timer = v1048;
  int * v1038 = v1034->reg_ready;
  int v1039 = v1038[8];
  int * v1040 = v1034->regs;
  int v1041 = v1040[8];
  int * v1042 = v1034->reg_ready;
  int v1053 = (v1039 + ((v1035 - v1039) & (~((v1035 - v1039) >> 31)))) + 1;
  v1042[8] = v1053;
  int * v1044 = v1034->regs;
  int v1055 = v1041 + 1;
  v1044[8] = v1055;
  struct StateT * v1046 = slot_16(v1034);
  return v1046;
}

struct StateT * slot_133(struct StateT * v3866) {
  int v3867 = v3866->timer;
  int v3868 = v3866->timer;
  int v3880 = v3868 + 1;
  v3866->timer = v3880;
  int * v3870 = v3866->reg_ready;
  int v3871 = v3870[8];
  int * v3872 = v3866->regs;
  int v3873 = v3872[8];
  int * v3874 = v3866->reg_ready;
  int v3885 = (v3871 + ((v3867 - v3871) & (~((v3867 - v3871) >> 31)))) + 1;
  v3874[8] = v3885;
  int * v3876 = v3866->regs;
  int v3887 = v3873 + 1;
  v3876[8] = v3887;
  struct StateT * v3878 = slot_134(v3866);
  return v3878;
}

struct StateT * slot_56(struct StateT * v2018) {
  int v2019 = v2018->timer;
  int v2020 = v2018->timer;
  int v2032 = v2020 + 1;
  v2018->timer = v2032;
  int * v2022 = v2018->reg_ready;
  int v2023 = v2022[8];
  int * v2024 = v2018->regs;
  int v2025 = v2024[8];
  int * v2026 = v2018->reg_ready;
  int v2037 = (v2023 + ((v2019 - v2023) & (~((v2019 - v2023) >> 31)))) + 1;
  v2026[8] = v2037;
  int * v2028 = v2018->regs;
  int v2039 = v2025 + 1;
  v2028[8] = v2039;
  struct StateT * v2030 = slot_57(v2018);
  return v2030;
}

struct StateT * slot_222(struct StateT * v6002) {
  int v6003 = v6002->timer;
  int v6004 = v6002->timer;
  int v6016 = v6004 + 1;
  v6002->timer = v6016;
  int * v6006 = v6002->reg_ready;
  int v6007 = v6006[8];
  int * v6008 = v6002->regs;
  int v6009 = v6008[8];
  int * v6010 = v6002->reg_ready;
  int v6021 = (v6007 + ((v6003 - v6007) & (~((v6003 - v6007) >> 31)))) + 1;
  v6010[8] = v6021;
  int * v6012 = v6002->regs;
  int v6023 = v6009 + 1;
  v6012[8] = v6023;
  struct StateT * v6014 = slot_223(v6002);
  return v6014;
}

struct StateT * slot_34(struct StateT * v1490) {
  int v1491 = v1490->timer;
  int v1492 = v1490->timer;
  int v1504 = v1492 + 1;
  v1490->timer = v1504;
  int * v1494 = v1490->reg_ready;
  int v1495 = v1494[8];
  int * v1496 = v1490->regs;
  int v1497 = v1496[8];
  int * v1498 = v1490->reg_ready;
  int v1509 = (v1495 + ((v1491 - v1495) & (~((v1491 - v1495) >> 31)))) + 1;
  v1498[8] = v1509;
  int * v1500 = v1490->regs;
  int v1511 = v1497 + 1;
  v1500[8] = v1511;
  struct StateT * v1502 = slot_35(v1490);
  return v1502;
}

struct StateT * slot_171(struct StateT * v4778) {
  int v4779 = v4778->timer;
  int v4780 = v4778->timer;
  int v4792 = v4780 + 1;
  v4778->timer = v4792;
  int * v4782 = v4778->reg_ready;
  int v4783 = v4782[8];
  int * v4784 = v4778->regs;
  int v4785 = v4784[8];
  int * v4786 = v4778->reg_ready;
  int v4797 = (v4783 + ((v4779 - v4783) & (~((v4779 - v4783) >> 31)))) + 1;
  v4786[8] = v4797;
  int * v4788 = v4778->regs;
  int v4799 = v4785 + 1;
  v4788[8] = v4799;
  struct StateT * v4790 = slot_172(v4778);
  return v4790;
}

struct StateT * slot_162(struct StateT * v4562) {
  int v4563 = v4562->timer;
  int v4564 = v4562->timer;
  int v4576 = v4564 + 1;
  v4562->timer = v4576;
  int * v4566 = v4562->reg_ready;
  int v4567 = v4566[8];
  int * v4568 = v4562->regs;
  int v4569 = v4568[8];
  int * v4570 = v4562->reg_ready;
  int v4581 = (v4567 + ((v4563 - v4567) & (~((v4563 - v4567) >> 31)))) + 1;
  v4570[8] = v4581;
  int * v4572 = v4562->regs;
  int v4583 = v4569 + 1;
  v4572[8] = v4583;
  struct StateT * v4574 = slot_163(v4562);
  return v4574;
}

struct StateT * slot_21(struct StateT * v1178) {
  int v1179 = v1178->timer;
  int v1180 = v1178->timer;
  int v1192 = v1180 + 1;
  v1178->timer = v1192;
  int * v1182 = v1178->reg_ready;
  int v1183 = v1182[8];
  int * v1184 = v1178->regs;
  int v1185 = v1184[8];
  int * v1186 = v1178->reg_ready;
  int v1197 = (v1183 + ((v1179 - v1183) & (~((v1179 - v1183) >> 31)))) + 1;
  v1186[8] = v1197;
  int * v1188 = v1178->regs;
  int v1199 = v1185 + 1;
  v1188[8] = v1199;
  struct StateT * v1190 = slot_22(v1178);
  return v1190;
}

struct StateT * slot_118(struct StateT * v3506) {
  int v3507 = v3506->timer;
  int v3508 = v3506->timer;
  int v3520 = v3508 + 1;
  v3506->timer = v3520;
  int * v3510 = v3506->reg_ready;
  int v3511 = v3510[8];
  int * v3512 = v3506->regs;
  int v3513 = v3512[8];
  int * v3514 = v3506->reg_ready;
  int v3525 = (v3511 + ((v3507 - v3511) & (~((v3507 - v3511) >> 31)))) + 1;
  v3514[8] = v3525;
  int * v3516 = v3506->regs;
  int v3527 = v3513 + 1;
  v3516[8] = v3527;
  struct StateT * v3518 = slot_119(v3506);
  return v3518;
}

struct StateT * slot_121(struct StateT * v3578) {
  int v3579 = v3578->timer;
  int v3580 = v3578->timer;
  int v3592 = v3580 + 1;
  v3578->timer = v3592;
  int * v3582 = v3578->reg_ready;
  int v3583 = v3582[8];
  int * v3584 = v3578->regs;
  int v3585 = v3584[8];
  int * v3586 = v3578->reg_ready;
  int v3597 = (v3583 + ((v3579 - v3583) & (~((v3579 - v3583) >> 31)))) + 1;
  v3586[8] = v3597;
  int * v3588 = v3578->regs;
  int v3599 = v3585 + 1;
  v3588[8] = v3599;
  struct StateT * v3590 = slot_122(v3578);
  return v3590;
}

struct StateT * slot_144(struct StateT * v4130) {
  int v4131 = v4130->timer;
  int v4132 = v4130->timer;
  int v4144 = v4132 + 1;
  v4130->timer = v4144;
  int * v4134 = v4130->reg_ready;
  int v4135 = v4134[8];
  int * v4136 = v4130->regs;
  int v4137 = v4136[8];
  int * v4138 = v4130->reg_ready;
  int v4149 = (v4135 + ((v4131 - v4135) & (~((v4131 - v4135) >> 31)))) + 1;
  v4138[8] = v4149;
  int * v4140 = v4130->regs;
  int v4151 = v4137 + 1;
  v4140[8] = v4151;
  struct StateT * v4142 = slot_145(v4130);
  return v4142;
}

struct StateT * slot_201(struct StateT * v5498) {
  int v5499 = v5498->timer;
  int v5500 = v5498->timer;
  int v5512 = v5500 + 1;
  v5498->timer = v5512;
  int * v5502 = v5498->reg_ready;
  int v5503 = v5502[8];
  int * v5504 = v5498->regs;
  int v5505 = v5504[8];
  int * v5506 = v5498->reg_ready;
  int v5517 = (v5503 + ((v5499 - v5503) & (~((v5499 - v5503) >> 31)))) + 1;
  v5506[8] = v5517;
  int * v5508 = v5498->regs;
  int v5519 = v5505 + 1;
  v5508[8] = v5519;
  struct StateT * v5510 = slot_202(v5498);
  return v5510;
}

struct StateT * slot_94(struct StateT * v2930) {
  int v2931 = v2930->timer;
  int v2932 = v2930->timer;
  int v2944 = v2932 + 1;
  v2930->timer = v2944;
  int * v2934 = v2930->reg_ready;
  int v2935 = v2934[8];
  int * v2936 = v2930->regs;
  int v2937 = v2936[8];
  int * v2938 = v2930->reg_ready;
  int v2949 = (v2935 + ((v2931 - v2935) & (~((v2931 - v2935) >> 31)))) + 1;
  v2938[8] = v2949;
  int * v2940 = v2930->regs;
  int v2951 = v2937 + 1;
  v2940[8] = v2951;
  struct StateT * v2942 = slot_95(v2930);
  return v2942;
}

struct StateT * slot_63(struct StateT * v2186) {
  int v2187 = v2186->timer;
  int v2188 = v2186->timer;
  int v2200 = v2188 + 1;
  v2186->timer = v2200;
  int * v2190 = v2186->reg_ready;
  int v2191 = v2190[8];
  int * v2192 = v2186->regs;
  int v2193 = v2192[8];
  int * v2194 = v2186->reg_ready;
  int v2205 = (v2191 + ((v2187 - v2191) & (~((v2187 - v2191) >> 31)))) + 1;
  v2194[8] = v2205;
  int * v2196 = v2186->regs;
  int v2207 = v2193 + 1;
  v2196[8] = v2207;
  struct StateT * v2198 = slot_64(v2186);
  return v2198;
}

struct StateT * slot_146(struct StateT * v4178) {
  int v4179 = v4178->timer;
  int v4180 = v4178->timer;
  int v4192 = v4180 + 1;
  v4178->timer = v4192;
  int * v4182 = v4178->reg_ready;
  int v4183 = v4182[8];
  int * v4184 = v4178->regs;
  int v4185 = v4184[8];
  int * v4186 = v4178->reg_ready;
  int v4197 = (v4183 + ((v4179 - v4183) & (~((v4179 - v4183) >> 31)))) + 1;
  v4186[8] = v4197;
  int * v4188 = v4178->regs;
  int v4199 = v4185 + 1;
  v4188[8] = v4199;
  struct StateT * v4190 = slot_147(v4178);
  return v4190;
}

struct StateT * slot_24(struct StateT * v1250) {
  int v1251 = v1250->timer;
  int v1252 = v1250->timer;
  int v1264 = v1252 + 1;
  v1250->timer = v1264;
  int * v1254 = v1250->reg_ready;
  int v1255 = v1254[8];
  int * v1256 = v1250->regs;
  int v1257 = v1256[8];
  int * v1258 = v1250->reg_ready;
  int v1269 = (v1255 + ((v1251 - v1255) & (~((v1251 - v1255) >> 31)))) + 1;
  v1258[8] = v1269;
  int * v1260 = v1250->regs;
  int v1271 = v1257 + 1;
  v1260[8] = v1271;
  struct StateT * v1262 = slot_25(v1250);
  return v1262;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v139 = v4 + 1;
  v2->timer = v139;
  int * v6 = v2->reg_ready;
  int v7 = v6[10];
  int * v8 = v2->regs;
  int v9 = v8[10];
  int * v10 = v2->cache_tags;
  int v144 = (((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2;
  int v11 = v10[v144];
  int * v12 = v2->cache_tags;
  int v146 = ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2) + 1;
  int v13 = v12[v146];
  int * v14 = v2->cache_tags;
  int v148 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2);
  int v15 = v14[v148];
  int * v16 = v2->cache_tags;
  int v150 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17 = v16[v150];
  int * v18 = v2->cache_vals;
  bool v151 = !(((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) | (~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31))) == 0);
  int v131;
  if (v151) {
    int * v19 = v2->cache_age;
    int v153 = ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2) + ((~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) & 1);
    int v20 = v19[v153];
    int * v21 = v2->cache_age;
    int v22 = v21[v144];
    int * v23 = v2->cache_age;
    int v156 = v22 + ((int)((unsigned int)(v22 - v20) >> 31));
    v23[v144] = v156;
    int * v25 = v2->cache_age;
    int v26 = v25[v146];
    int * v27 = v2->cache_age;
    int v159 = v26 + ((int)((unsigned int)(v26 - v20) >> 31));
    v27[v146] = v159;
    int * v29 = v2->cache_age;
    v29[v153] = 0;
    v131 = v153;
  } else {
    int * v32 = v2->cache_age;
    int v163 = (((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2;
    int v33 = v32[v163];
    int * v34 = v2->cache_tags;
    int v35 = v34[v163];
    int * v36 = v2->cache_age;
    int v37 = v36[v146];
    int * v38 = v2->cache_tags;
    int v39 = v38[v146];
    bool v167 = !(((~(((v15 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v15 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) | (~(((v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31))) == 0);
    int v103;
    if (v167) {
      int * v40 = v2->cache_age;
      int v169 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + ((~(((v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) & 1);
      int v41 = v40[v169];
      int * v42 = v2->cache_age;
      int v43 = v42[v148];
      int * v44 = v2->cache_age;
      int v172 = v43 + ((int)((unsigned int)(v43 - v41) >> 31));
      v44[v148] = v172;
      int * v46 = v2->cache_age;
      int v47 = v46[v150];
      int * v48 = v2->cache_age;
      int v175 = v47 + ((int)((unsigned int)(v47 - v41) >> 31));
      v48[v150] = v175;
      int * v50 = v2->cache_age;
      v50[v169] = 0;
      v103 = v169;
    } else {
      int * v53 = v2->cache_age;
      int v179 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2);
      int v54 = v53[v179];
      int * v55 = v2->cache_tags;
      int v56 = v55[v179];
      int * v57 = v2->cache_age;
      int v58 = v57[v150];
      int * v59 = v2->cache_tags;
      int v60 = v59[v150];
      int * v61 = v2->cache_dirty;
      int v184 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v62 = v61[v184];
      bool v185 = !(v62 == 0);
      if (v185) {
        int * v63 = v2->cache_tags;
        int v64 = v63[v184];
        int * v65 = v2->cache_vals;
        int v188 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66 = v65[v188];
        int * v67 = v2->cache_vals;
        int v190 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v68 = v67[v190];
        int * v69 = v2->mem;
        int v192 = v64 * 2;
        v69[v192] = v66;
        int * v71 = v2->mem;
        int v195 = (v64 * 2) + 1;
        v71[v195] = v68;
        ;
      } else {
        ;
      }
      int * v76 = v2->mem;
      int v200 = ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) * 2;
      int v77 = v76[v200];
      int * v78 = v2->mem;
      int v202 = (((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) * 2) + 1;
      int v79 = v78[v202];
      int * v80 = v2->cache_vals;
      int v204 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v204] = v77;
      int * v82 = v2->cache_vals;
      int v207 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v207] = v79;
      int * v84 = v2->cache_tags;
      int v210 = (int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1);
      v84[v184] = v210;
      int * v86 = v2->cache_dirty;
      v86[v184] = 0;
      int * v88 = v2->cache_age;
      v88[v184] = 1;
      int * v90 = v2->cache_age;
      int v91 = v90[v184];
      int * v92 = v2->cache_age;
      int v93 = v92[v148];
      int * v94 = v2->cache_age;
      int v218 = v93 + ((int)((unsigned int)(v93 - v91) >> 31));
      v94[v148] = v218;
      int * v96 = v2->cache_age;
      int v97 = v96[v150];
      int * v98 = v2->cache_age;
      int v221 = v97 + ((int)((unsigned int)(v97 - v91) >> 31));
      v98[v150] = v221;
      int * v100 = v2->cache_age;
      v100[v184] = 0;
      v103 = v184;
    }
    int * v104 = v2->cache_vals;
    int v224 = v103 * 2;
    int v105 = v104[v224];
    int * v106 = v2->cache_vals;
    int v226 = (v103 * 2) + 1;
    int v107 = v106[v226];
    int * v108 = v2->cache_vals;
    int v228 = (((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2) + ((((v33 + ((~(((v35 ^ -1) | (-(v35 ^ -1))) >> 31)) & 2)) - (v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v108[v228] = v105;
    int * v110 = v2->cache_vals;
    int v231 = ((((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2) + ((((v33 + ((~(((v35 ^ -1) | (-(v35 ^ -1))) >> 31)) & 2)) - (v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v110[v231] = v107;
    int * v112 = v2->cache_tags;
    int v234 = ((((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1)) & 1) * 2) + ((((v33 + ((~(((v35 ^ -1) | (-(v35 ^ -1))) >> 31)) & 2)) - (v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v235 = (int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1);
    v112[v234] = v235;
    int * v114 = v2->cache_dirty;
    v114[v234] = 0;
    int * v116 = v2->cache_age;
    v116[v234] = 1;
    int * v118 = v2->cache_age;
    int v119 = v118[v234];
    int * v120 = v2->cache_age;
    int v121 = v120[v144];
    int * v122 = v2->cache_age;
    int v243 = v121 + ((int)((unsigned int)(v121 - v119) >> 31));
    v122[v144] = v243;
    int * v124 = v2->cache_age;
    int v125 = v124[v146];
    int * v126 = v2->cache_age;
    int v246 = v125 + ((int)((unsigned int)(v125 - v119) >> 31));
    v126[v146] = v246;
    int * v128 = v2->cache_age;
    v128[v234] = 0;
    v131 = v234;
  }
  int v249 = (v131 * 2) + (((int)((unsigned int)v9 >> 2)) & 1);
  int v132 = v18[v249];
  int * v133 = v2->reg_ready;
  int v252 = ((v7 + ((v3 - v7) & (~((v3 - v7) >> 31)))) + 1) + ((100 ^ (((~(((v15 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v15 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) | (~(((v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) | (~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v15 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31)) | (~(((v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))) | (-(v17 ^ ((int)((unsigned int)((int)((unsigned int)v9 >> 2)) >> 1))))) >> 31))) & 104)))));
  v133[5] = v252;
  int * v135 = v2->regs;
  v135[5] = v132;
  struct StateT * v137 = slot_1(v2);
  return v137;
}

struct StateT * slot_195(struct StateT * v5354) {
  int v5355 = v5354->timer;
  int v5356 = v5354->timer;
  int v5368 = v5356 + 1;
  v5354->timer = v5368;
  int * v5358 = v5354->reg_ready;
  int v5359 = v5358[8];
  int * v5360 = v5354->regs;
  int v5361 = v5360[8];
  int * v5362 = v5354->reg_ready;
  int v5373 = (v5359 + ((v5355 - v5359) & (~((v5355 - v5359) >> 31)))) + 1;
  v5362[8] = v5373;
  int * v5364 = v5354->regs;
  int v5375 = v5361 + 1;
  v5364[8] = v5375;
  struct StateT * v5366 = slot_196(v5354);
  return v5366;
}

struct StateT * slot_125(struct StateT * v3674) {
  int v3675 = v3674->timer;
  int v3676 = v3674->timer;
  int v3688 = v3676 + 1;
  v3674->timer = v3688;
  int * v3678 = v3674->reg_ready;
  int v3679 = v3678[8];
  int * v3680 = v3674->regs;
  int v3681 = v3680[8];
  int * v3682 = v3674->reg_ready;
  int v3693 = (v3679 + ((v3675 - v3679) & (~((v3675 - v3679) >> 31)))) + 1;
  v3682[8] = v3693;
  int * v3684 = v3674->regs;
  int v3695 = v3681 + 1;
  v3684[8] = v3695;
  struct StateT * v3686 = slot_126(v3674);
  return v3686;
}

struct StateT * slot_148(struct StateT * v4226) {
  int v4227 = v4226->timer;
  int v4228 = v4226->timer;
  int v4240 = v4228 + 1;
  v4226->timer = v4240;
  int * v4230 = v4226->reg_ready;
  int v4231 = v4230[8];
  int * v4232 = v4226->regs;
  int v4233 = v4232[8];
  int * v4234 = v4226->reg_ready;
  int v4245 = (v4231 + ((v4227 - v4231) & (~((v4227 - v4231) >> 31)))) + 1;
  v4234[8] = v4245;
  int * v4236 = v4226->regs;
  int v4247 = v4233 + 1;
  v4236[8] = v4247;
  struct StateT * v4238 = slot_149(v4226);
  return v4238;
}

struct StateT * slot_126(struct StateT * v3698) {
  int v3699 = v3698->timer;
  int v3700 = v3698->timer;
  int v3712 = v3700 + 1;
  v3698->timer = v3712;
  int * v3702 = v3698->reg_ready;
  int v3703 = v3702[8];
  int * v3704 = v3698->regs;
  int v3705 = v3704[8];
  int * v3706 = v3698->reg_ready;
  int v3717 = (v3703 + ((v3699 - v3703) & (~((v3699 - v3703) >> 31)))) + 1;
  v3706[8] = v3717;
  int * v3708 = v3698->regs;
  int v3719 = v3705 + 1;
  v3708[8] = v3719;
  struct StateT * v3710 = slot_127(v3698);
  return v3710;
}

struct StateT * slot_223(struct StateT * v6026) {
  int v6027 = v6026->timer;
  int v6028 = v6026->timer;
  int v6040 = v6028 + 1;
  v6026->timer = v6040;
  int * v6030 = v6026->reg_ready;
  int v6031 = v6030[8];
  int * v6032 = v6026->regs;
  int v6033 = v6032[8];
  int * v6034 = v6026->reg_ready;
  int v6045 = (v6031 + ((v6027 - v6031) & (~((v6027 - v6031) >> 31)))) + 1;
  v6034[8] = v6045;
  int * v6036 = v6026->regs;
  int v6047 = v6033 + 1;
  v6036[8] = v6047;
  struct StateT * v6038 = slot_224(v6026);
  return v6038;
}

struct StateT * slot_79(struct StateT * v2570) {
  int v2571 = v2570->timer;
  int v2572 = v2570->timer;
  int v2584 = v2572 + 1;
  v2570->timer = v2584;
  int * v2574 = v2570->reg_ready;
  int v2575 = v2574[8];
  int * v2576 = v2570->regs;
  int v2577 = v2576[8];
  int * v2578 = v2570->reg_ready;
  int v2589 = (v2575 + ((v2571 - v2575) & (~((v2571 - v2575) >> 31)))) + 1;
  v2578[8] = v2589;
  int * v2580 = v2570->regs;
  int v2591 = v2577 + 1;
  v2580[8] = v2591;
  struct StateT * v2582 = slot_80(v2570);
  return v2582;
}

struct StateT * slot_41(struct StateT * v1658) {
  int v1659 = v1658->timer;
  int v1660 = v1658->timer;
  int v1672 = v1660 + 1;
  v1658->timer = v1672;
  int * v1662 = v1658->reg_ready;
  int v1663 = v1662[8];
  int * v1664 = v1658->regs;
  int v1665 = v1664[8];
  int * v1666 = v1658->reg_ready;
  int v1677 = (v1663 + ((v1659 - v1663) & (~((v1659 - v1663) >> 31)))) + 1;
  v1666[8] = v1677;
  int * v1668 = v1658->regs;
  int v1679 = v1665 + 1;
  v1668[8] = v1679;
  struct StateT * v1670 = slot_42(v1658);
  return v1670;
}

struct StateT * slot_39(struct StateT * v1610) {
  int v1611 = v1610->timer;
  int v1612 = v1610->timer;
  int v1624 = v1612 + 1;
  v1610->timer = v1624;
  int * v1614 = v1610->reg_ready;
  int v1615 = v1614[8];
  int * v1616 = v1610->regs;
  int v1617 = v1616[8];
  int * v1618 = v1610->reg_ready;
  int v1629 = (v1615 + ((v1611 - v1615) & (~((v1611 - v1615) >> 31)))) + 1;
  v1618[8] = v1629;
  int * v1620 = v1610->regs;
  int v1631 = v1617 + 1;
  v1620[8] = v1631;
  struct StateT * v1622 = slot_40(v1610);
  return v1622;
}

struct StateT * slot_142(struct StateT * v4082) {
  int v4083 = v4082->timer;
  int v4084 = v4082->timer;
  int v4096 = v4084 + 1;
  v4082->timer = v4096;
  int * v4086 = v4082->reg_ready;
  int v4087 = v4086[8];
  int * v4088 = v4082->regs;
  int v4089 = v4088[8];
  int * v4090 = v4082->reg_ready;
  int v4101 = (v4087 + ((v4083 - v4087) & (~((v4083 - v4087) >> 31)))) + 1;
  v4090[8] = v4101;
  int * v4092 = v4082->regs;
  int v4103 = v4089 + 1;
  v4092[8] = v4103;
  struct StateT * v4094 = slot_143(v4082);
  return v4094;
}

struct StateT * slot_60(struct StateT * v2114) {
  int v2115 = v2114->timer;
  int v2116 = v2114->timer;
  int v2128 = v2116 + 1;
  v2114->timer = v2128;
  int * v2118 = v2114->reg_ready;
  int v2119 = v2118[8];
  int * v2120 = v2114->regs;
  int v2121 = v2120[8];
  int * v2122 = v2114->reg_ready;
  int v2133 = (v2119 + ((v2115 - v2119) & (~((v2115 - v2119) >> 31)))) + 1;
  v2122[8] = v2133;
  int * v2124 = v2114->regs;
  int v2135 = v2121 + 1;
  v2124[8] = v2135;
  struct StateT * v2126 = slot_61(v2114);
  return v2126;
}

struct StateT * slot_112(struct StateT * v3362) {
  int v3363 = v3362->timer;
  int v3364 = v3362->timer;
  int v3376 = v3364 + 1;
  v3362->timer = v3376;
  int * v3366 = v3362->reg_ready;
  int v3367 = v3366[8];
  int * v3368 = v3362->regs;
  int v3369 = v3368[8];
  int * v3370 = v3362->reg_ready;
  int v3381 = (v3367 + ((v3363 - v3367) & (~((v3363 - v3367) >> 31)))) + 1;
  v3370[8] = v3381;
  int * v3372 = v3362->regs;
  int v3383 = v3369 + 1;
  v3372[8] = v3383;
  struct StateT * v3374 = slot_113(v3362);
  return v3374;
}

struct StateT * slot_47(struct StateT * v1802) {
  int v1803 = v1802->timer;
  int v1804 = v1802->timer;
  int v1816 = v1804 + 1;
  v1802->timer = v1816;
  int * v1806 = v1802->reg_ready;
  int v1807 = v1806[8];
  int * v1808 = v1802->regs;
  int v1809 = v1808[8];
  int * v1810 = v1802->reg_ready;
  int v1821 = (v1807 + ((v1803 - v1807) & (~((v1803 - v1807) >> 31)))) + 1;
  v1810[8] = v1821;
  int * v1812 = v1802->regs;
  int v1823 = v1809 + 1;
  v1812[8] = v1823;
  struct StateT * v1814 = slot_48(v1802);
  return v1814;
}

struct StateT * slot_214(struct StateT * v5810) {
  int v5811 = v5810->timer;
  int v5812 = v5810->timer;
  int v5824 = v5812 + 1;
  v5810->timer = v5824;
  int * v5814 = v5810->reg_ready;
  int v5815 = v5814[8];
  int * v5816 = v5810->regs;
  int v5817 = v5816[8];
  int * v5818 = v5810->reg_ready;
  int v5829 = (v5815 + ((v5811 - v5815) & (~((v5811 - v5815) >> 31)))) + 1;
  v5818[8] = v5829;
  int * v5820 = v5810->regs;
  int v5831 = v5817 + 1;
  v5820[8] = v5831;
  struct StateT * v5822 = slot_215(v5810);
  return v5822;
}

struct StateT * slot_29(struct StateT * v1370) {
  int v1371 = v1370->timer;
  int v1372 = v1370->timer;
  int v1384 = v1372 + 1;
  v1370->timer = v1384;
  int * v1374 = v1370->reg_ready;
  int v1375 = v1374[8];
  int * v1376 = v1370->regs;
  int v1377 = v1376[8];
  int * v1378 = v1370->reg_ready;
  int v1389 = (v1375 + ((v1371 - v1375) & (~((v1371 - v1375) >> 31)))) + 1;
  v1378[8] = v1389;
  int * v1380 = v1370->regs;
  int v1391 = v1377 + 1;
  v1380[8] = v1391;
  struct StateT * v1382 = slot_30(v1370);
  return v1382;
}

struct StateT * slot_16(struct StateT * v1058) {
  int v1059 = v1058->timer;
  int v1060 = v1058->timer;
  int v1072 = v1060 + 1;
  v1058->timer = v1072;
  int * v1062 = v1058->reg_ready;
  int v1063 = v1062[8];
  int * v1064 = v1058->regs;
  int v1065 = v1064[8];
  int * v1066 = v1058->reg_ready;
  int v1077 = (v1063 + ((v1059 - v1063) & (~((v1059 - v1063) >> 31)))) + 1;
  v1066[8] = v1077;
  int * v1068 = v1058->regs;
  int v1079 = v1065 + 1;
  v1068[8] = v1079;
  struct StateT * v1070 = slot_17(v1058);
  return v1070;
}

struct StateT * slot_113(struct StateT * v3386) {
  int v3387 = v3386->timer;
  int v3388 = v3386->timer;
  int v3400 = v3388 + 1;
  v3386->timer = v3400;
  int * v3390 = v3386->reg_ready;
  int v3391 = v3390[8];
  int * v3392 = v3386->regs;
  int v3393 = v3392[8];
  int * v3394 = v3386->reg_ready;
  int v3405 = (v3391 + ((v3387 - v3391) & (~((v3387 - v3391) >> 31)))) + 1;
  v3394[8] = v3405;
  int * v3396 = v3386->regs;
  int v3407 = v3393 + 1;
  v3396[8] = v3407;
  struct StateT * v3398 = slot_114(v3386);
  return v3398;
}

struct StateT * slot_151(struct StateT * v4298) {
  int v4299 = v4298->timer;
  int v4300 = v4298->timer;
  int v4312 = v4300 + 1;
  v4298->timer = v4312;
  int * v4302 = v4298->reg_ready;
  int v4303 = v4302[8];
  int * v4304 = v4298->regs;
  int v4305 = v4304[8];
  int * v4306 = v4298->reg_ready;
  int v4317 = (v4303 + ((v4299 - v4303) & (~((v4299 - v4303) >> 31)))) + 1;
  v4306[8] = v4317;
  int * v4308 = v4298->regs;
  int v4319 = v4305 + 1;
  v4308[8] = v4319;
  struct StateT * v4310 = slot_152(v4298);
  return v4310;
}

struct StateT * slot_7(struct StateT * v842) {
  int v843 = v842->timer;
  int v844 = v842->timer;
  int v856 = v844 + 1;
  v842->timer = v856;
  int * v846 = v842->reg_ready;
  int v847 = v846[8];
  int * v848 = v842->regs;
  int v849 = v848[8];
  int * v850 = v842->reg_ready;
  int v861 = (v847 + ((v843 - v847) & (~((v843 - v847) >> 31)))) + 1;
  v850[8] = v861;
  int * v852 = v842->regs;
  int v863 = v849 + 1;
  v852[8] = v863;
  struct StateT * v854 = slot_8(v842);
  return v854;
}

struct StateT * slot_124(struct StateT * v3650) {
  int v3651 = v3650->timer;
  int v3652 = v3650->timer;
  int v3664 = v3652 + 1;
  v3650->timer = v3664;
  int * v3654 = v3650->reg_ready;
  int v3655 = v3654[8];
  int * v3656 = v3650->regs;
  int v3657 = v3656[8];
  int * v3658 = v3650->reg_ready;
  int v3669 = (v3655 + ((v3651 - v3655) & (~((v3651 - v3655) >> 31)))) + 1;
  v3658[8] = v3669;
  int * v3660 = v3650->regs;
  int v3671 = v3657 + 1;
  v3660[8] = v3671;
  struct StateT * v3662 = slot_125(v3650);
  return v3662;
}

struct StateT * slot_191(struct StateT * v5258) {
  int v5259 = v5258->timer;
  int v5260 = v5258->timer;
  int v5272 = v5260 + 1;
  v5258->timer = v5272;
  int * v5262 = v5258->reg_ready;
  int v5263 = v5262[8];
  int * v5264 = v5258->regs;
  int v5265 = v5264[8];
  int * v5266 = v5258->reg_ready;
  int v5277 = (v5263 + ((v5259 - v5263) & (~((v5259 - v5263) >> 31)))) + 1;
  v5266[8] = v5277;
  int * v5268 = v5258->regs;
  int v5279 = v5265 + 1;
  v5268[8] = v5279;
  struct StateT * v5270 = slot_192(v5258);
  return v5270;
}

struct StateT * slot_103(struct StateT * v3146) {
  int v3147 = v3146->timer;
  int v3148 = v3146->timer;
  int v3160 = v3148 + 1;
  v3146->timer = v3160;
  int * v3150 = v3146->reg_ready;
  int v3151 = v3150[8];
  int * v3152 = v3146->regs;
  int v3153 = v3152[8];
  int * v3154 = v3146->reg_ready;
  int v3165 = (v3151 + ((v3147 - v3151) & (~((v3147 - v3151) >> 31)))) + 1;
  v3154[8] = v3165;
  int * v3156 = v3146->regs;
  int v3167 = v3153 + 1;
  v3156[8] = v3167;
  struct StateT * v3158 = slot_104(v3146);
  return v3158;
}

struct StateT * slot_128(struct StateT * v3746) {
  int v3747 = v3746->timer;
  int v3748 = v3746->timer;
  int v3760 = v3748 + 1;
  v3746->timer = v3760;
  int * v3750 = v3746->reg_ready;
  int v3751 = v3750[8];
  int * v3752 = v3746->regs;
  int v3753 = v3752[8];
  int * v3754 = v3746->reg_ready;
  int v3765 = (v3751 + ((v3747 - v3751) & (~((v3747 - v3751) >> 31)))) + 1;
  v3754[8] = v3765;
  int * v3756 = v3746->regs;
  int v3767 = v3753 + 1;
  v3756[8] = v3767;
  struct StateT * v3758 = slot_129(v3746);
  return v3758;
}

struct StateT * slot_19(struct StateT * v1130) {
  int v1131 = v1130->timer;
  int v1132 = v1130->timer;
  int v1144 = v1132 + 1;
  v1130->timer = v1144;
  int * v1134 = v1130->reg_ready;
  int v1135 = v1134[8];
  int * v1136 = v1130->regs;
  int v1137 = v1136[8];
  int * v1138 = v1130->reg_ready;
  int v1149 = (v1135 + ((v1131 - v1135) & (~((v1131 - v1135) >> 31)))) + 1;
  v1138[8] = v1149;
  int * v1140 = v1130->regs;
  int v1151 = v1137 + 1;
  v1140[8] = v1151;
  struct StateT * v1142 = slot_20(v1130);
  return v1142;
}

struct StateT * slot_87(struct StateT * v2762) {
  int v2763 = v2762->timer;
  int v2764 = v2762->timer;
  int v2776 = v2764 + 1;
  v2762->timer = v2776;
  int * v2766 = v2762->reg_ready;
  int v2767 = v2766[8];
  int * v2768 = v2762->regs;
  int v2769 = v2768[8];
  int * v2770 = v2762->reg_ready;
  int v2781 = (v2767 + ((v2763 - v2767) & (~((v2763 - v2767) >> 31)))) + 1;
  v2770[8] = v2781;
  int * v2772 = v2762->regs;
  int v2783 = v2769 + 1;
  v2772[8] = v2783;
  struct StateT * v2774 = slot_88(v2762);
  return v2774;
}

struct StateT * slot_67(struct StateT * v2282) {
  int v2283 = v2282->timer;
  int v2284 = v2282->timer;
  int v2296 = v2284 + 1;
  v2282->timer = v2296;
  int * v2286 = v2282->reg_ready;
  int v2287 = v2286[8];
  int * v2288 = v2282->regs;
  int v2289 = v2288[8];
  int * v2290 = v2282->reg_ready;
  int v2301 = (v2287 + ((v2283 - v2287) & (~((v2283 - v2287) >> 31)))) + 1;
  v2290[8] = v2301;
  int * v2292 = v2282->regs;
  int v2303 = v2289 + 1;
  v2292[8] = v2303;
  struct StateT * v2294 = slot_68(v2282);
  return v2294;
}

struct StateT * slot_81(struct StateT * v2618) {
  int v2619 = v2618->timer;
  int v2620 = v2618->timer;
  int v2632 = v2620 + 1;
  v2618->timer = v2632;
  int * v2622 = v2618->reg_ready;
  int v2623 = v2622[8];
  int * v2624 = v2618->regs;
  int v2625 = v2624[8];
  int * v2626 = v2618->reg_ready;
  int v2637 = (v2623 + ((v2619 - v2623) & (~((v2619 - v2623) >> 31)))) + 1;
  v2626[8] = v2637;
  int * v2628 = v2618->regs;
  int v2639 = v2625 + 1;
  v2628[8] = v2639;
  struct StateT * v2630 = slot_82(v2618);
  return v2630;
}

struct StateT * slot_95(struct StateT * v2954) {
  int v2955 = v2954->timer;
  int v2956 = v2954->timer;
  int v2968 = v2956 + 1;
  v2954->timer = v2968;
  int * v2958 = v2954->reg_ready;
  int v2959 = v2958[8];
  int * v2960 = v2954->regs;
  int v2961 = v2960[8];
  int * v2962 = v2954->reg_ready;
  int v2973 = (v2959 + ((v2955 - v2959) & (~((v2955 - v2959) >> 31)))) + 1;
  v2962[8] = v2973;
  int * v2964 = v2954->regs;
  int v2975 = v2961 + 1;
  v2964[8] = v2975;
  struct StateT * v2966 = slot_96(v2954);
  return v2966;
}

struct StateT * slot_115(struct StateT * v3434) {
  int v3435 = v3434->timer;
  int v3436 = v3434->timer;
  int v3448 = v3436 + 1;
  v3434->timer = v3448;
  int * v3438 = v3434->reg_ready;
  int v3439 = v3438[8];
  int * v3440 = v3434->regs;
  int v3441 = v3440[8];
  int * v3442 = v3434->reg_ready;
  int v3453 = (v3439 + ((v3435 - v3439) & (~((v3435 - v3439) >> 31)))) + 1;
  v3442[8] = v3453;
  int * v3444 = v3434->regs;
  int v3455 = v3441 + 1;
  v3444[8] = v3455;
  struct StateT * v3446 = slot_116(v3434);
  return v3446;
}

struct StateT * slot_78(struct StateT * v2546) {
  int v2547 = v2546->timer;
  int v2548 = v2546->timer;
  int v2560 = v2548 + 1;
  v2546->timer = v2560;
  int * v2550 = v2546->reg_ready;
  int v2551 = v2550[8];
  int * v2552 = v2546->regs;
  int v2553 = v2552[8];
  int * v2554 = v2546->reg_ready;
  int v2565 = (v2551 + ((v2547 - v2551) & (~((v2547 - v2551) >> 31)))) + 1;
  v2554[8] = v2565;
  int * v2556 = v2546->regs;
  int v2567 = v2553 + 1;
  v2556[8] = v2567;
  struct StateT * v2558 = slot_79(v2546);
  return v2558;
}

struct StateT * slot_32(struct StateT * v1442) {
  int v1443 = v1442->timer;
  int v1444 = v1442->timer;
  int v1456 = v1444 + 1;
  v1442->timer = v1456;
  int * v1446 = v1442->reg_ready;
  int v1447 = v1446[8];
  int * v1448 = v1442->regs;
  int v1449 = v1448[8];
  int * v1450 = v1442->reg_ready;
  int v1461 = (v1447 + ((v1443 - v1447) & (~((v1443 - v1447) >> 31)))) + 1;
  v1450[8] = v1461;
  int * v1452 = v1442->regs;
  int v1463 = v1449 + 1;
  v1452[8] = v1463;
  struct StateT * v1454 = slot_33(v1442);
  return v1454;
}

struct StateT * slot_205(struct StateT * v5594) {
  int v5595 = v5594->timer;
  int v5596 = v5594->timer;
  int v5608 = v5596 + 1;
  v5594->timer = v5608;
  int * v5598 = v5594->reg_ready;
  int v5599 = v5598[8];
  int * v5600 = v5594->regs;
  int v5601 = v5600[8];
  int * v5602 = v5594->reg_ready;
  int v5613 = (v5599 + ((v5595 - v5599) & (~((v5595 - v5599) >> 31)))) + 1;
  v5602[8] = v5613;
  int * v5604 = v5594->regs;
  int v5615 = v5601 + 1;
  v5604[8] = v5615;
  struct StateT * v5606 = slot_206(v5594);
  return v5606;
}

struct StateT * slot_193(struct StateT * v5306) {
  int v5307 = v5306->timer;
  int v5308 = v5306->timer;
  int v5320 = v5308 + 1;
  v5306->timer = v5320;
  int * v5310 = v5306->reg_ready;
  int v5311 = v5310[8];
  int * v5312 = v5306->regs;
  int v5313 = v5312[8];
  int * v5314 = v5306->reg_ready;
  int v5325 = (v5311 + ((v5307 - v5311) & (~((v5307 - v5311) >> 31)))) + 1;
  v5314[8] = v5325;
  int * v5316 = v5306->regs;
  int v5327 = v5313 + 1;
  v5316[8] = v5327;
  struct StateT * v5318 = slot_194(v5306);
  return v5318;
}

struct StateT * slot_176(struct StateT * v4898) {
  int v4899 = v4898->timer;
  int v4900 = v4898->timer;
  int v4912 = v4900 + 1;
  v4898->timer = v4912;
  int * v4902 = v4898->reg_ready;
  int v4903 = v4902[8];
  int * v4904 = v4898->regs;
  int v4905 = v4904[8];
  int * v4906 = v4898->reg_ready;
  int v4917 = (v4903 + ((v4899 - v4903) & (~((v4899 - v4903) >> 31)))) + 1;
  v4906[8] = v4917;
  int * v4908 = v4898->regs;
  int v4919 = v4905 + 1;
  v4908[8] = v4919;
  struct StateT * v4910 = slot_177(v4898);
  return v4910;
}

struct StateT * slot_189(struct StateT * v5210) {
  int v5211 = v5210->timer;
  int v5212 = v5210->timer;
  int v5224 = v5212 + 1;
  v5210->timer = v5224;
  int * v5214 = v5210->reg_ready;
  int v5215 = v5214[8];
  int * v5216 = v5210->regs;
  int v5217 = v5216[8];
  int * v5218 = v5210->reg_ready;
  int v5229 = (v5215 + ((v5211 - v5215) & (~((v5211 - v5215) >> 31)))) + 1;
  v5218[8] = v5229;
  int * v5220 = v5210->regs;
  int v5231 = v5217 + 1;
  v5220[8] = v5231;
  struct StateT * v5222 = slot_190(v5210);
  return v5222;
}

struct StateT * slot_33(struct StateT * v1466) {
  int v1467 = v1466->timer;
  int v1468 = v1466->timer;
  int v1480 = v1468 + 1;
  v1466->timer = v1480;
  int * v1470 = v1466->reg_ready;
  int v1471 = v1470[8];
  int * v1472 = v1466->regs;
  int v1473 = v1472[8];
  int * v1474 = v1466->reg_ready;
  int v1485 = (v1471 + ((v1467 - v1471) & (~((v1467 - v1471) >> 31)))) + 1;
  v1474[8] = v1485;
  int * v1476 = v1466->regs;
  int v1487 = v1473 + 1;
  v1476[8] = v1487;
  struct StateT * v1478 = slot_34(v1466);
  return v1478;
}

struct StateT * slot_35(struct StateT * v1514) {
  int v1515 = v1514->timer;
  int v1516 = v1514->timer;
  int v1528 = v1516 + 1;
  v1514->timer = v1528;
  int * v1518 = v1514->reg_ready;
  int v1519 = v1518[8];
  int * v1520 = v1514->regs;
  int v1521 = v1520[8];
  int * v1522 = v1514->reg_ready;
  int v1533 = (v1519 + ((v1515 - v1519) & (~((v1515 - v1519) >> 31)))) + 1;
  v1522[8] = v1533;
  int * v1524 = v1514->regs;
  int v1535 = v1521 + 1;
  v1524[8] = v1535;
  struct StateT * v1526 = slot_36(v1514);
  return v1526;
}

struct StateT * slot_210(struct StateT * v5714) {
  int v5715 = v5714->timer;
  int v5716 = v5714->timer;
  int v5728 = v5716 + 1;
  v5714->timer = v5728;
  int * v5718 = v5714->reg_ready;
  int v5719 = v5718[8];
  int * v5720 = v5714->regs;
  int v5721 = v5720[8];
  int * v5722 = v5714->reg_ready;
  int v5733 = (v5719 + ((v5715 - v5719) & (~((v5715 - v5719) >> 31)))) + 1;
  v5722[8] = v5733;
  int * v5724 = v5714->regs;
  int v5735 = v5721 + 1;
  v5724[8] = v5735;
  struct StateT * v5726 = slot_211(v5714);
  return v5726;
}

struct StateT * slot_166(struct StateT * v4658) {
  int v4659 = v4658->timer;
  int v4660 = v4658->timer;
  int v4672 = v4660 + 1;
  v4658->timer = v4672;
  int * v4662 = v4658->reg_ready;
  int v4663 = v4662[8];
  int * v4664 = v4658->regs;
  int v4665 = v4664[8];
  int * v4666 = v4658->reg_ready;
  int v4677 = (v4663 + ((v4659 - v4663) & (~((v4659 - v4663) >> 31)))) + 1;
  v4666[8] = v4677;
  int * v4668 = v4658->regs;
  int v4679 = v4665 + 1;
  v4668[8] = v4679;
  struct StateT * v4670 = slot_167(v4658);
  return v4670;
}

struct StateT * slot_51(struct StateT * v1898) {
  int v1899 = v1898->timer;
  int v1900 = v1898->timer;
  int v1912 = v1900 + 1;
  v1898->timer = v1912;
  int * v1902 = v1898->reg_ready;
  int v1903 = v1902[8];
  int * v1904 = v1898->regs;
  int v1905 = v1904[8];
  int * v1906 = v1898->reg_ready;
  int v1917 = (v1903 + ((v1899 - v1903) & (~((v1899 - v1903) >> 31)))) + 1;
  v1906[8] = v1917;
  int * v1908 = v1898->regs;
  int v1919 = v1905 + 1;
  v1908[8] = v1919;
  struct StateT * v1910 = slot_52(v1898);
  return v1910;
}

struct StateT * slot_52(struct StateT * v1922) {
  int v1923 = v1922->timer;
  int v1924 = v1922->timer;
  int v1936 = v1924 + 1;
  v1922->timer = v1936;
  int * v1926 = v1922->reg_ready;
  int v1927 = v1926[8];
  int * v1928 = v1922->regs;
  int v1929 = v1928[8];
  int * v1930 = v1922->reg_ready;
  int v1941 = (v1927 + ((v1923 - v1927) & (~((v1923 - v1927) >> 31)))) + 1;
  v1930[8] = v1941;
  int * v1932 = v1922->regs;
  int v1943 = v1929 + 1;
  v1932[8] = v1943;
  struct StateT * v1934 = slot_53(v1922);
  return v1934;
}

struct StateT * slot_83(struct StateT * v2666) {
  int v2667 = v2666->timer;
  int v2668 = v2666->timer;
  int v2680 = v2668 + 1;
  v2666->timer = v2680;
  int * v2670 = v2666->reg_ready;
  int v2671 = v2670[8];
  int * v2672 = v2666->regs;
  int v2673 = v2672[8];
  int * v2674 = v2666->reg_ready;
  int v2685 = (v2671 + ((v2667 - v2671) & (~((v2667 - v2671) >> 31)))) + 1;
  v2674[8] = v2685;
  int * v2676 = v2666->regs;
  int v2687 = v2673 + 1;
  v2676[8] = v2687;
  struct StateT * v2678 = slot_84(v2666);
  return v2678;
}

struct StateT * slot_25(struct StateT * v1274) {
  int v1275 = v1274->timer;
  int v1276 = v1274->timer;
  int v1288 = v1276 + 1;
  v1274->timer = v1288;
  int * v1278 = v1274->reg_ready;
  int v1279 = v1278[8];
  int * v1280 = v1274->regs;
  int v1281 = v1280[8];
  int * v1282 = v1274->reg_ready;
  int v1293 = (v1279 + ((v1275 - v1279) & (~((v1275 - v1279) >> 31)))) + 1;
  v1282[8] = v1293;
  int * v1284 = v1274->regs;
  int v1295 = v1281 + 1;
  v1284[8] = v1295;
  struct StateT * v1286 = slot_26(v1274);
  return v1286;
}

struct StateT * slot_209(struct StateT * v5690) {
  int v5691 = v5690->timer;
  int v5692 = v5690->timer;
  int v5704 = v5692 + 1;
  v5690->timer = v5704;
  int * v5694 = v5690->reg_ready;
  int v5695 = v5694[8];
  int * v5696 = v5690->regs;
  int v5697 = v5696[8];
  int * v5698 = v5690->reg_ready;
  int v5709 = (v5695 + ((v5691 - v5695) & (~((v5691 - v5695) >> 31)))) + 1;
  v5698[8] = v5709;
  int * v5700 = v5690->regs;
  int v5711 = v5697 + 1;
  v5700[8] = v5711;
  struct StateT * v5702 = slot_210(v5690);
  return v5702;
}

struct StateT * slot_3(struct StateT * v521) {
  int v522 = v521->timer;
  int v523 = v521->timer;
  int v535 = v523 + 1;
  v521->timer = v535;
  int * v525 = v521->reg_ready;
  int v526 = v525[6];
  int * v527 = v521->regs;
  int v528 = v527[6];
  int * v529 = v521->reg_ready;
  int v540 = (v526 + ((v522 - v526) & (~((v522 - v526) >> 31)))) + 1;
  v529[6] = v540;
  int * v531 = v521->regs;
  int v542 = v528 << 2;
  v531[6] = v542;
  struct StateT * v533 = slot_4(v521);
  return v533;
}

struct StateT * slot_123(struct StateT * v3626) {
  int v3627 = v3626->timer;
  int v3628 = v3626->timer;
  int v3640 = v3628 + 1;
  v3626->timer = v3640;
  int * v3630 = v3626->reg_ready;
  int v3631 = v3630[8];
  int * v3632 = v3626->regs;
  int v3633 = v3632[8];
  int * v3634 = v3626->reg_ready;
  int v3645 = (v3631 + ((v3627 - v3631) & (~((v3627 - v3631) >> 31)))) + 1;
  v3634[8] = v3645;
  int * v3636 = v3626->regs;
  int v3647 = v3633 + 1;
  v3636[8] = v3647;
  struct StateT * v3638 = slot_124(v3626);
  return v3638;
}

struct StateT * slot_73(struct StateT * v2426) {
  int v2427 = v2426->timer;
  int v2428 = v2426->timer;
  int v2440 = v2428 + 1;
  v2426->timer = v2440;
  int * v2430 = v2426->reg_ready;
  int v2431 = v2430[8];
  int * v2432 = v2426->regs;
  int v2433 = v2432[8];
  int * v2434 = v2426->reg_ready;
  int v2445 = (v2431 + ((v2427 - v2431) & (~((v2427 - v2431) >> 31)))) + 1;
  v2434[8] = v2445;
  int * v2436 = v2426->regs;
  int v2447 = v2433 + 1;
  v2436[8] = v2447;
  struct StateT * v2438 = slot_74(v2426);
  return v2438;
}

struct StateT * slot_198(struct StateT * v5426) {
  int v5427 = v5426->timer;
  int v5428 = v5426->timer;
  int v5440 = v5428 + 1;
  v5426->timer = v5440;
  int * v5430 = v5426->reg_ready;
  int v5431 = v5430[8];
  int * v5432 = v5426->regs;
  int v5433 = v5432[8];
  int * v5434 = v5426->reg_ready;
  int v5445 = (v5431 + ((v5427 - v5431) & (~((v5427 - v5431) >> 31)))) + 1;
  v5434[8] = v5445;
  int * v5436 = v5426->regs;
  int v5447 = v5433 + 1;
  v5436[8] = v5447;
  struct StateT * v5438 = slot_199(v5426);
  return v5438;
}

struct StateT * slot_1(struct StateT * v257) {
  int v258 = v257->timer;
  int v259 = v257->timer;
  int v390 = v259 + 1;
  v257->timer = v390;
  int * v261 = v257->cache_tags;
  int v262 = v261[0];
  int * v263 = v257->cache_tags;
  int v264 = v263[1];
  int * v265 = v257->cache_tags;
  int v266 = v265[8];
  int * v267 = v257->cache_tags;
  int v268 = v267[9];
  int * v269 = v257->cache_vals;
  bool v399 = !(((~(((v262 ^ 10) | (-(v262 ^ 10))) >> 31)) | (~(((v264 ^ 10) | (-(v264 ^ 10))) >> 31))) == 0);
  int v382;
  if (v399) {
    int * v270 = v257->cache_age;
    int v401 = (~(((v264 ^ 10) | (-(v264 ^ 10))) >> 31)) & 1;
    int v271 = v270[v401];
    int * v272 = v257->cache_age;
    int v273 = v272[0];
    int * v274 = v257->cache_age;
    int v404 = v273 + ((int)((unsigned int)(v273 - v271) >> 31));
    v274[0] = v404;
    int * v276 = v257->cache_age;
    int v277 = v276[1];
    int * v278 = v257->cache_age;
    int v407 = v277 + ((int)((unsigned int)(v277 - v271) >> 31));
    v278[1] = v407;
    int * v280 = v257->cache_age;
    v280[v401] = 0;
    v382 = v401;
  } else {
    int * v283 = v257->cache_age;
    int v284 = v283[0];
    int * v285 = v257->cache_tags;
    int v286 = v285[0];
    int * v287 = v257->cache_age;
    int v288 = v287[1];
    int * v289 = v257->cache_tags;
    int v290 = v289[1];
    bool v413 = !(((~(((v266 ^ 10) | (-(v266 ^ 10))) >> 31)) | (~(((v268 ^ 10) | (-(v268 ^ 10))) >> 31))) == 0);
    int v354;
    if (v413) {
      int * v291 = v257->cache_age;
      int v415 = 8 + ((~(((v268 ^ 10) | (-(v268 ^ 10))) >> 31)) & 1);
      int v292 = v291[v415];
      int * v293 = v257->cache_age;
      int v294 = v293[8];
      int * v295 = v257->cache_age;
      int v418 = v294 + ((int)((unsigned int)(v294 - v292) >> 31));
      v295[8] = v418;
      int * v297 = v257->cache_age;
      int v298 = v297[9];
      int * v299 = v257->cache_age;
      int v421 = v298 + ((int)((unsigned int)(v298 - v292) >> 31));
      v299[9] = v421;
      int * v301 = v257->cache_age;
      v301[v415] = 0;
      v354 = v415;
    } else {
      int * v304 = v257->cache_age;
      int v305 = v304[8];
      int * v306 = v257->cache_tags;
      int v307 = v306[8];
      int * v308 = v257->cache_age;
      int v309 = v308[9];
      int * v310 = v257->cache_tags;
      int v311 = v310[9];
      int * v312 = v257->cache_dirty;
      int v428 = 8 + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v313 = v312[v428];
      bool v429 = !(v313 == 0);
      if (v429) {
        int * v314 = v257->cache_tags;
        int v315 = v314[v428];
        int * v316 = v257->cache_vals;
        int v432 = (8 + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v317 = v316[v432];
        int * v318 = v257->cache_vals;
        int v434 = ((8 + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v319 = v318[v434];
        int * v320 = v257->mem;
        int v436 = v315 * 2;
        v320[v436] = v317;
        int * v322 = v257->mem;
        int v439 = (v315 * 2) + 1;
        v322[v439] = v319;
        ;
      } else {
        ;
      }
      int * v327 = v257->mem;
      int v328 = v327[20];
      int * v329 = v257->mem;
      int v330 = v329[21];
      int * v331 = v257->cache_vals;
      int v448 = (8 + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v331[v448] = v328;
      int * v333 = v257->cache_vals;
      int v451 = ((8 + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v333[v451] = v330;
      int * v335 = v257->cache_tags;
      v335[v428] = 10;
      int * v337 = v257->cache_dirty;
      v337[v428] = 0;
      int * v339 = v257->cache_age;
      v339[v428] = 1;
      int * v341 = v257->cache_age;
      int v342 = v341[v428];
      int * v343 = v257->cache_age;
      int v344 = v343[8];
      int * v345 = v257->cache_age;
      int v460 = v344 + ((int)((unsigned int)(v344 - v342) >> 31));
      v345[8] = v460;
      int * v347 = v257->cache_age;
      int v348 = v347[9];
      int * v349 = v257->cache_age;
      int v463 = v348 + ((int)((unsigned int)(v348 - v342) >> 31));
      v349[9] = v463;
      int * v351 = v257->cache_age;
      v351[v428] = 0;
      v354 = v428;
    }
    int * v355 = v257->cache_vals;
    int v466 = v354 * 2;
    int v356 = v355[v466];
    int * v357 = v257->cache_vals;
    int v468 = (v354 * 2) + 1;
    int v358 = v357[v468];
    int * v359 = v257->cache_vals;
    int v470 = ((((v284 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v290 ^ -1) | (-(v290 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v359[v470] = v356;
    int * v361 = v257->cache_vals;
    int v473 = (((((v284 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v290 ^ -1) | (-(v290 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v361[v473] = v358;
    int * v363 = v257->cache_tags;
    int v476 = (((v284 + ((~(((v286 ^ -1) | (-(v286 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v290 ^ -1) | (-(v290 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v363[v476] = 10;
    int * v365 = v257->cache_dirty;
    v365[v476] = 0;
    int * v367 = v257->cache_age;
    v367[v476] = 1;
    int * v369 = v257->cache_age;
    int v370 = v369[v476];
    int * v371 = v257->cache_age;
    int v372 = v371[0];
    int * v373 = v257->cache_age;
    int v483 = v372 + ((int)((unsigned int)(v372 - v370) >> 31));
    v373[0] = v483;
    int * v375 = v257->cache_age;
    int v376 = v375[1];
    int * v377 = v257->cache_age;
    int v486 = v376 + ((int)((unsigned int)(v376 - v370) >> 31));
    v377[1] = v486;
    int * v379 = v257->cache_age;
    v379[v476] = 0;
    v382 = v476;
  }
  int v489 = v382 * 2;
  int v383 = v269[v489];
  int * v384 = v257->reg_ready;
  int v492 = (v258 + 1) + ((100 ^ (((~(((v266 ^ 10) | (-(v266 ^ 10))) >> 31)) | (~(((v268 ^ 10) | (-(v268 ^ 10))) >> 31))) & 104)) ^ (((~(((v262 ^ 10) | (-(v262 ^ 10))) >> 31)) | (~(((v264 ^ 10) | (-(v264 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v266 ^ 10) | (-(v266 ^ 10))) >> 31)) | (~(((v268 ^ 10) | (-(v268 ^ 10))) >> 31))) & 104)))));
  v384[6] = v492;
  int * v386 = v257->regs;
  v386[6] = v383;
  struct StateT * v388 = slot_2(v257);
  return v388;
}

struct StateT * slot_187(struct StateT * v5162) {
  int v5163 = v5162->timer;
  int v5164 = v5162->timer;
  int v5176 = v5164 + 1;
  v5162->timer = v5176;
  int * v5166 = v5162->reg_ready;
  int v5167 = v5166[8];
  int * v5168 = v5162->regs;
  int v5169 = v5168[8];
  int * v5170 = v5162->reg_ready;
  int v5181 = (v5167 + ((v5163 - v5167) & (~((v5163 - v5167) >> 31)))) + 1;
  v5170[8] = v5181;
  int * v5172 = v5162->regs;
  int v5183 = v5169 + 1;
  v5172[8] = v5183;
  struct StateT * v5174 = slot_188(v5162);
  return v5174;
}

struct StateT * slot_97(struct StateT * v3002) {
  int v3003 = v3002->timer;
  int v3004 = v3002->timer;
  int v3016 = v3004 + 1;
  v3002->timer = v3016;
  int * v3006 = v3002->reg_ready;
  int v3007 = v3006[8];
  int * v3008 = v3002->regs;
  int v3009 = v3008[8];
  int * v3010 = v3002->reg_ready;
  int v3021 = (v3007 + ((v3003 - v3007) & (~((v3003 - v3007) >> 31)))) + 1;
  v3010[8] = v3021;
  int * v3012 = v3002->regs;
  int v3023 = v3009 + 1;
  v3012[8] = v3023;
  struct StateT * v3014 = slot_98(v3002);
  return v3014;
}

struct StateT * slot_182(struct StateT * v5042) {
  int v5043 = v5042->timer;
  int v5044 = v5042->timer;
  int v5056 = v5044 + 1;
  v5042->timer = v5056;
  int * v5046 = v5042->reg_ready;
  int v5047 = v5046[8];
  int * v5048 = v5042->regs;
  int v5049 = v5048[8];
  int * v5050 = v5042->reg_ready;
  int v5061 = (v5047 + ((v5043 - v5047) & (~((v5043 - v5047) >> 31)))) + 1;
  v5050[8] = v5061;
  int * v5052 = v5042->regs;
  int v5063 = v5049 + 1;
  v5052[8] = v5063;
  struct StateT * v5054 = slot_183(v5042);
  return v5054;
}

struct StateT * slot_38(struct StateT * v1586) {
  int v1587 = v1586->timer;
  int v1588 = v1586->timer;
  int v1600 = v1588 + 1;
  v1586->timer = v1600;
  int * v1590 = v1586->reg_ready;
  int v1591 = v1590[8];
  int * v1592 = v1586->regs;
  int v1593 = v1592[8];
  int * v1594 = v1586->reg_ready;
  int v1605 = (v1591 + ((v1587 - v1591) & (~((v1587 - v1591) >> 31)))) + 1;
  v1594[8] = v1605;
  int * v1596 = v1586->regs;
  int v1607 = v1593 + 1;
  v1596[8] = v1607;
  struct StateT * v1598 = slot_39(v1586);
  return v1598;
}

struct StateT * slot_178(struct StateT * v4946) {
  int v4947 = v4946->timer;
  int v4948 = v4946->timer;
  int v4960 = v4948 + 1;
  v4946->timer = v4960;
  int * v4950 = v4946->reg_ready;
  int v4951 = v4950[8];
  int * v4952 = v4946->regs;
  int v4953 = v4952[8];
  int * v4954 = v4946->reg_ready;
  int v4965 = (v4951 + ((v4947 - v4951) & (~((v4947 - v4951) >> 31)))) + 1;
  v4954[8] = v4965;
  int * v4956 = v4946->regs;
  int v4967 = v4953 + 1;
  v4956[8] = v4967;
  struct StateT * v4958 = slot_179(v4946);
  return v4958;
}

struct StateT * slot_106(struct StateT * v3218) {
  int v3219 = v3218->timer;
  int v3220 = v3218->timer;
  int v3232 = v3220 + 1;
  v3218->timer = v3232;
  int * v3222 = v3218->reg_ready;
  int v3223 = v3222[8];
  int * v3224 = v3218->regs;
  int v3225 = v3224[8];
  int * v3226 = v3218->reg_ready;
  int v3237 = (v3223 + ((v3219 - v3223) & (~((v3219 - v3223) >> 31)))) + 1;
  v3226[8] = v3237;
  int * v3228 = v3218->regs;
  int v3239 = v3225 + 1;
  v3228[8] = v3239;
  struct StateT * v3230 = slot_107(v3218);
  return v3230;
}

struct StateT * slot_98(struct StateT * v3026) {
  int v3027 = v3026->timer;
  int v3028 = v3026->timer;
  int v3040 = v3028 + 1;
  v3026->timer = v3040;
  int * v3030 = v3026->reg_ready;
  int v3031 = v3030[8];
  int * v3032 = v3026->regs;
  int v3033 = v3032[8];
  int * v3034 = v3026->reg_ready;
  int v3045 = (v3031 + ((v3027 - v3031) & (~((v3027 - v3031) >> 31)))) + 1;
  v3034[8] = v3045;
  int * v3036 = v3026->regs;
  int v3047 = v3033 + 1;
  v3036[8] = v3047;
  struct StateT * v3038 = slot_99(v3026);
  return v3038;
}

struct StateT * slot_159(struct StateT * v4490) {
  int v4491 = v4490->timer;
  int v4492 = v4490->timer;
  int v4504 = v4492 + 1;
  v4490->timer = v4504;
  int * v4494 = v4490->reg_ready;
  int v4495 = v4494[8];
  int * v4496 = v4490->regs;
  int v4497 = v4496[8];
  int * v4498 = v4490->reg_ready;
  int v4509 = (v4495 + ((v4491 - v4495) & (~((v4491 - v4495) >> 31)))) + 1;
  v4498[8] = v4509;
  int * v4500 = v4490->regs;
  int v4511 = v4497 + 1;
  v4500[8] = v4511;
  struct StateT * v4502 = slot_160(v4490);
  return v4502;
}

struct StateT * slot_46(struct StateT * v1778) {
  int v1779 = v1778->timer;
  int v1780 = v1778->timer;
  int v1792 = v1780 + 1;
  v1778->timer = v1792;
  int * v1782 = v1778->reg_ready;
  int v1783 = v1782[8];
  int * v1784 = v1778->regs;
  int v1785 = v1784[8];
  int * v1786 = v1778->reg_ready;
  int v1797 = (v1783 + ((v1779 - v1783) & (~((v1779 - v1783) >> 31)))) + 1;
  v1786[8] = v1797;
  int * v1788 = v1778->regs;
  int v1799 = v1785 + 1;
  v1788[8] = v1799;
  struct StateT * v1790 = slot_47(v1778);
  return v1790;
}

struct StateT * slot_212(struct StateT * v5762) {
  int v5763 = v5762->timer;
  int v5764 = v5762->timer;
  int v5776 = v5764 + 1;
  v5762->timer = v5776;
  int * v5766 = v5762->reg_ready;
  int v5767 = v5766[8];
  int * v5768 = v5762->regs;
  int v5769 = v5768[8];
  int * v5770 = v5762->reg_ready;
  int v5781 = (v5767 + ((v5763 - v5767) & (~((v5763 - v5767) >> 31)))) + 1;
  v5770[8] = v5781;
  int * v5772 = v5762->regs;
  int v5783 = v5769 + 1;
  v5772[8] = v5783;
  struct StateT * v5774 = slot_213(v5762);
  return v5774;
}

struct StateT * slot_132(struct StateT * v3842) {
  int v3843 = v3842->timer;
  int v3844 = v3842->timer;
  int v3856 = v3844 + 1;
  v3842->timer = v3856;
  int * v3846 = v3842->reg_ready;
  int v3847 = v3846[8];
  int * v3848 = v3842->regs;
  int v3849 = v3848[8];
  int * v3850 = v3842->reg_ready;
  int v3861 = (v3847 + ((v3843 - v3847) & (~((v3843 - v3847) >> 31)))) + 1;
  v3850[8] = v3861;
  int * v3852 = v3842->regs;
  int v3863 = v3849 + 1;
  v3852[8] = v3863;
  struct StateT * v3854 = slot_133(v3842);
  return v3854;
}

struct StateT * slot_130(struct StateT * v3794) {
  int v3795 = v3794->timer;
  int v3796 = v3794->timer;
  int v3808 = v3796 + 1;
  v3794->timer = v3808;
  int * v3798 = v3794->reg_ready;
  int v3799 = v3798[8];
  int * v3800 = v3794->regs;
  int v3801 = v3800[8];
  int * v3802 = v3794->reg_ready;
  int v3813 = (v3799 + ((v3795 - v3799) & (~((v3795 - v3799) >> 31)))) + 1;
  v3802[8] = v3813;
  int * v3804 = v3794->regs;
  int v3815 = v3801 + 1;
  v3804[8] = v3815;
  struct StateT * v3806 = slot_131(v3794);
  return v3806;
}

struct StateT * slot_211(struct StateT * v5738) {
  int v5739 = v5738->timer;
  int v5740 = v5738->timer;
  int v5752 = v5740 + 1;
  v5738->timer = v5752;
  int * v5742 = v5738->reg_ready;
  int v5743 = v5742[8];
  int * v5744 = v5738->regs;
  int v5745 = v5744[8];
  int * v5746 = v5738->reg_ready;
  int v5757 = (v5743 + ((v5739 - v5743) & (~((v5739 - v5743) >> 31)))) + 1;
  v5746[8] = v5757;
  int * v5748 = v5738->regs;
  int v5759 = v5745 + 1;
  v5748[8] = v5759;
  struct StateT * v5750 = slot_212(v5738);
  return v5750;
}

struct StateT * slot_20(struct StateT * v1154) {
  int v1155 = v1154->timer;
  int v1156 = v1154->timer;
  int v1168 = v1156 + 1;
  v1154->timer = v1168;
  int * v1158 = v1154->reg_ready;
  int v1159 = v1158[8];
  int * v1160 = v1154->regs;
  int v1161 = v1160[8];
  int * v1162 = v1154->reg_ready;
  int v1173 = (v1159 + ((v1155 - v1159) & (~((v1155 - v1159) >> 31)))) + 1;
  v1162[8] = v1173;
  int * v1164 = v1154->regs;
  int v1175 = v1161 + 1;
  v1164[8] = v1175;
  struct StateT * v1166 = slot_21(v1154);
  return v1166;
}

struct StateT * slot_141(struct StateT * v4058) {
  int v4059 = v4058->timer;
  int v4060 = v4058->timer;
  int v4072 = v4060 + 1;
  v4058->timer = v4072;
  int * v4062 = v4058->reg_ready;
  int v4063 = v4062[8];
  int * v4064 = v4058->regs;
  int v4065 = v4064[8];
  int * v4066 = v4058->reg_ready;
  int v4077 = (v4063 + ((v4059 - v4063) & (~((v4059 - v4063) >> 31)))) + 1;
  v4066[8] = v4077;
  int * v4068 = v4058->regs;
  int v4079 = v4065 + 1;
  v4068[8] = v4079;
  struct StateT * v4070 = slot_142(v4058);
  return v4070;
}

struct StateT * slot_61(struct StateT * v2138) {
  int v2139 = v2138->timer;
  int v2140 = v2138->timer;
  int v2152 = v2140 + 1;
  v2138->timer = v2152;
  int * v2142 = v2138->reg_ready;
  int v2143 = v2142[8];
  int * v2144 = v2138->regs;
  int v2145 = v2144[8];
  int * v2146 = v2138->reg_ready;
  int v2157 = (v2143 + ((v2139 - v2143) & (~((v2139 - v2143) >> 31)))) + 1;
  v2146[8] = v2157;
  int * v2148 = v2138->regs;
  int v2159 = v2145 + 1;
  v2148[8] = v2159;
  struct StateT * v2150 = slot_62(v2138);
  return v2150;
}

struct StateT * slot_30(struct StateT * v1394) {
  int v1395 = v1394->timer;
  int v1396 = v1394->timer;
  int v1408 = v1396 + 1;
  v1394->timer = v1408;
  int * v1398 = v1394->reg_ready;
  int v1399 = v1398[8];
  int * v1400 = v1394->regs;
  int v1401 = v1400[8];
  int * v1402 = v1394->reg_ready;
  int v1413 = (v1399 + ((v1395 - v1399) & (~((v1395 - v1399) >> 31)))) + 1;
  v1402[8] = v1413;
  int * v1404 = v1394->regs;
  int v1415 = v1401 + 1;
  v1404[8] = v1415;
  struct StateT * v1406 = slot_31(v1394);
  return v1406;
}

struct StateT * slot_4(struct StateT * v545) {
  int v546 = v545->timer;
  int v547 = v545->timer;
  int v682 = v547 + 1;
  v545->timer = v682;
  int * v549 = v545->reg_ready;
  int v550 = v549[6];
  int * v551 = v545->regs;
  int v552 = v551[6];
  int * v553 = v545->cache_tags;
  int v687 = (((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2;
  int v554 = v553[v687];
  int * v555 = v545->cache_tags;
  int v689 = ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2) + 1;
  int v556 = v555[v689];
  int * v557 = v545->cache_tags;
  int v691 = 4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2);
  int v558 = v557[v691];
  int * v559 = v545->cache_tags;
  int v693 = (4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v560 = v559[v693];
  int * v561 = v545->cache_vals;
  bool v694 = !(((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) | (~(((v556 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v556 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31))) == 0);
  int v674;
  if (v694) {
    int * v562 = v545->cache_age;
    int v696 = ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2) + ((~(((v556 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v556 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) & 1);
    int v563 = v562[v696];
    int * v564 = v545->cache_age;
    int v565 = v564[v687];
    int * v566 = v545->cache_age;
    int v699 = v565 + ((int)((unsigned int)(v565 - v563) >> 31));
    v566[v687] = v699;
    int * v568 = v545->cache_age;
    int v569 = v568[v689];
    int * v570 = v545->cache_age;
    int v702 = v569 + ((int)((unsigned int)(v569 - v563) >> 31));
    v570[v689] = v702;
    int * v572 = v545->cache_age;
    v572[v696] = 0;
    v674 = v696;
  } else {
    int * v575 = v545->cache_age;
    int v706 = (((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2;
    int v576 = v575[v706];
    int * v577 = v545->cache_tags;
    int v578 = v577[v706];
    int * v579 = v545->cache_age;
    int v580 = v579[v689];
    int * v581 = v545->cache_tags;
    int v582 = v581[v689];
    bool v710 = !(((~(((v558 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v558 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) | (~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31))) == 0);
    int v646;
    if (v710) {
      int * v583 = v545->cache_age;
      int v712 = (4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + ((~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) & 1);
      int v584 = v583[v712];
      int * v585 = v545->cache_age;
      int v586 = v585[v691];
      int * v587 = v545->cache_age;
      int v715 = v586 + ((int)((unsigned int)(v586 - v584) >> 31));
      v587[v691] = v715;
      int * v589 = v545->cache_age;
      int v590 = v589[v693];
      int * v591 = v545->cache_age;
      int v718 = v590 + ((int)((unsigned int)(v590 - v584) >> 31));
      v591[v693] = v718;
      int * v593 = v545->cache_age;
      v593[v712] = 0;
      v646 = v712;
    } else {
      int * v596 = v545->cache_age;
      int v722 = 4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2);
      int v597 = v596[v722];
      int * v598 = v545->cache_tags;
      int v599 = v598[v722];
      int * v600 = v545->cache_age;
      int v601 = v600[v693];
      int * v602 = v545->cache_tags;
      int v603 = v602[v693];
      int * v604 = v545->cache_dirty;
      int v727 = (4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + ((((v597 + ((~(((v599 ^ -1) | (-(v599 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v605 = v604[v727];
      bool v728 = !(v605 == 0);
      if (v728) {
        int * v606 = v545->cache_tags;
        int v607 = v606[v727];
        int * v608 = v545->cache_vals;
        int v731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + ((((v597 + ((~(((v599 ^ -1) | (-(v599 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v609 = v608[v731];
        int * v610 = v545->cache_vals;
        int v733 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + ((((v597 + ((~(((v599 ^ -1) | (-(v599 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v611 = v610[v733];
        int * v612 = v545->mem;
        int v735 = v607 * 2;
        v612[v735] = v609;
        int * v614 = v545->mem;
        int v738 = (v607 * 2) + 1;
        v614[v738] = v611;
        ;
      } else {
        ;
      }
      int * v619 = v545->mem;
      int v743 = ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) * 2;
      int v620 = v619[v743];
      int * v621 = v545->mem;
      int v745 = (((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) * 2) + 1;
      int v622 = v621[v745];
      int * v623 = v545->cache_vals;
      int v747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + ((((v597 + ((~(((v599 ^ -1) | (-(v599 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v623[v747] = v620;
      int * v625 = v545->cache_vals;
      int v750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 3) * 2)) + ((((v597 + ((~(((v599 ^ -1) | (-(v599 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v625[v750] = v622;
      int * v627 = v545->cache_tags;
      int v753 = (int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1);
      v627[v727] = v753;
      int * v629 = v545->cache_dirty;
      v629[v727] = 0;
      int * v631 = v545->cache_age;
      v631[v727] = 1;
      int * v633 = v545->cache_age;
      int v634 = v633[v727];
      int * v635 = v545->cache_age;
      int v636 = v635[v691];
      int * v637 = v545->cache_age;
      int v761 = v636 + ((int)((unsigned int)(v636 - v634) >> 31));
      v637[v691] = v761;
      int * v639 = v545->cache_age;
      int v640 = v639[v693];
      int * v641 = v545->cache_age;
      int v764 = v640 + ((int)((unsigned int)(v640 - v634) >> 31));
      v641[v693] = v764;
      int * v643 = v545->cache_age;
      v643[v727] = 0;
      v646 = v727;
    }
    int * v647 = v545->cache_vals;
    int v767 = v646 * 2;
    int v648 = v647[v767];
    int * v649 = v545->cache_vals;
    int v769 = (v646 * 2) + 1;
    int v650 = v649[v769];
    int * v651 = v545->cache_vals;
    int v771 = (((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2) + ((((v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v651[v771] = v648;
    int * v653 = v545->cache_vals;
    int v774 = ((((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2) + ((((v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v653[v774] = v650;
    int * v655 = v545->cache_tags;
    int v777 = ((((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1)) & 1) * 2) + ((((v576 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v778 = (int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1);
    v655[v777] = v778;
    int * v657 = v545->cache_dirty;
    v657[v777] = 0;
    int * v659 = v545->cache_age;
    v659[v777] = 1;
    int * v661 = v545->cache_age;
    int v662 = v661[v777];
    int * v663 = v545->cache_age;
    int v664 = v663[v687];
    int * v665 = v545->cache_age;
    int v786 = v664 + ((int)((unsigned int)(v664 - v662) >> 31));
    v665[v687] = v786;
    int * v667 = v545->cache_age;
    int v668 = v667[v689];
    int * v669 = v545->cache_age;
    int v789 = v668 + ((int)((unsigned int)(v668 - v662) >> 31));
    v669[v689] = v789;
    int * v671 = v545->cache_age;
    v671[v777] = 0;
    v674 = v777;
  }
  int v792 = (v674 * 2) + (((int)((unsigned int)v552 >> 2)) & 1);
  int v675 = v561[v792];
  int * v676 = v545->reg_ready;
  int v795 = ((v550 + ((v546 - v550) & (~((v546 - v550) >> 31)))) + 1) + ((100 ^ (((~(((v558 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v558 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) | (~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) | (~(((v556 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v556 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v558 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v558 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31)) | (~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)v552 >> 2)) >> 1))))) >> 31))) & 104)))));
  v676[7] = v795;
  int * v678 = v545->regs;
  v678[7] = v675;
  struct StateT * v680 = slot_5(v545);
  return v680;
}

struct StateT * slot_18(struct StateT * v1106) {
  int v1107 = v1106->timer;
  int v1108 = v1106->timer;
  int v1120 = v1108 + 1;
  v1106->timer = v1120;
  int * v1110 = v1106->reg_ready;
  int v1111 = v1110[8];
  int * v1112 = v1106->regs;
  int v1113 = v1112[8];
  int * v1114 = v1106->reg_ready;
  int v1125 = (v1111 + ((v1107 - v1111) & (~((v1107 - v1111) >> 31)))) + 1;
  v1114[8] = v1125;
  int * v1116 = v1106->regs;
  int v1127 = v1113 + 1;
  v1116[8] = v1127;
  struct StateT * v1118 = slot_19(v1106);
  return v1118;
}

struct StateT * slot_9(struct StateT * v890) {
  int v891 = v890->timer;
  int v892 = v890->timer;
  int v904 = v892 + 1;
  v890->timer = v904;
  int * v894 = v890->reg_ready;
  int v895 = v894[8];
  int * v896 = v890->regs;
  int v897 = v896[8];
  int * v898 = v890->reg_ready;
  int v909 = (v895 + ((v891 - v895) & (~((v891 - v895) >> 31)))) + 1;
  v898[8] = v909;
  int * v900 = v890->regs;
  int v911 = v897 + 1;
  v900[8] = v911;
  struct StateT * v902 = slot_10(v890);
  return v902;
}

struct StateT * slot_183(struct StateT * v5066) {
  int v5067 = v5066->timer;
  int v5068 = v5066->timer;
  int v5080 = v5068 + 1;
  v5066->timer = v5080;
  int * v5070 = v5066->reg_ready;
  int v5071 = v5070[8];
  int * v5072 = v5066->regs;
  int v5073 = v5072[8];
  int * v5074 = v5066->reg_ready;
  int v5085 = (v5071 + ((v5067 - v5071) & (~((v5067 - v5071) >> 31)))) + 1;
  v5074[8] = v5085;
  int * v5076 = v5066->regs;
  int v5087 = v5073 + 1;
  v5076[8] = v5087;
  struct StateT * v5078 = slot_184(v5066);
  return v5078;
}

struct StateT * slot_43(struct StateT * v1706) {
  int v1707 = v1706->timer;
  int v1708 = v1706->timer;
  int v1720 = v1708 + 1;
  v1706->timer = v1720;
  int * v1710 = v1706->reg_ready;
  int v1711 = v1710[8];
  int * v1712 = v1706->regs;
  int v1713 = v1712[8];
  int * v1714 = v1706->reg_ready;
  int v1725 = (v1711 + ((v1707 - v1711) & (~((v1707 - v1711) >> 31)))) + 1;
  v1714[8] = v1725;
  int * v1716 = v1706->regs;
  int v1727 = v1713 + 1;
  v1716[8] = v1727;
  struct StateT * v1718 = slot_44(v1706);
  return v1718;
}

struct StateT * slot_70(struct StateT * v2354) {
  int v2355 = v2354->timer;
  int v2356 = v2354->timer;
  int v2368 = v2356 + 1;
  v2354->timer = v2368;
  int * v2358 = v2354->reg_ready;
  int v2359 = v2358[8];
  int * v2360 = v2354->regs;
  int v2361 = v2360[8];
  int * v2362 = v2354->reg_ready;
  int v2373 = (v2359 + ((v2355 - v2359) & (~((v2355 - v2359) >> 31)))) + 1;
  v2362[8] = v2373;
  int * v2364 = v2354->regs;
  int v2375 = v2361 + 1;
  v2364[8] = v2375;
  struct StateT * v2366 = slot_71(v2354);
  return v2366;
}

struct StateT * slot_168(struct StateT * v4706) {
  int v4707 = v4706->timer;
  int v4708 = v4706->timer;
  int v4720 = v4708 + 1;
  v4706->timer = v4720;
  int * v4710 = v4706->reg_ready;
  int v4711 = v4710[8];
  int * v4712 = v4706->regs;
  int v4713 = v4712[8];
  int * v4714 = v4706->reg_ready;
  int v4725 = (v4711 + ((v4707 - v4711) & (~((v4707 - v4711) >> 31)))) + 1;
  v4714[8] = v4725;
  int * v4716 = v4706->regs;
  int v4727 = v4713 + 1;
  v4716[8] = v4727;
  struct StateT * v4718 = slot_169(v4706);
  return v4718;
}

struct StateT * slot_76(struct StateT * v2498) {
  int v2499 = v2498->timer;
  int v2500 = v2498->timer;
  int v2512 = v2500 + 1;
  v2498->timer = v2512;
  int * v2502 = v2498->reg_ready;
  int v2503 = v2502[8];
  int * v2504 = v2498->regs;
  int v2505 = v2504[8];
  int * v2506 = v2498->reg_ready;
  int v2517 = (v2503 + ((v2499 - v2503) & (~((v2499 - v2503) >> 31)))) + 1;
  v2506[8] = v2517;
  int * v2508 = v2498->regs;
  int v2519 = v2505 + 1;
  v2508[8] = v2519;
  struct StateT * v2510 = slot_77(v2498);
  return v2510;
}

struct StateT * slot_6(struct StateT * v818) {
  int v819 = v818->timer;
  int v820 = v818->timer;
  int v832 = v820 + 1;
  v818->timer = v832;
  int * v822 = v818->reg_ready;
  int v823 = v822[8];
  int * v824 = v818->regs;
  int v825 = v824[8];
  int * v826 = v818->reg_ready;
  int v837 = (v823 + ((v819 - v823) & (~((v819 - v823) >> 31)))) + 1;
  v826[8] = v837;
  int * v828 = v818->regs;
  int v839 = v825 + 1;
  v828[8] = v839;
  struct StateT * v830 = slot_7(v818);
  return v830;
}

struct StateT * slot_225(struct StateT * v6074) {
  int v6075 = v6074->timer;
  int v6076 = v6074->timer;
  int v6087 = v6076 + 1;
  v6074->timer = v6087;
  int * v6078 = v6074->reg_ready;
  int v6079 = v6078[8];
  int * v6080 = v6074->regs;
  int v6081 = v6080[8];
  int * v6082 = v6074->reg_ready;
  int v6092 = (v6079 + ((v6075 - v6079) & (~((v6075 - v6079) >> 31)))) + 1;
  v6082[8] = v6092;
  int * v6084 = v6074->regs;
  int v6094 = v6081 + 1;
  v6084[8] = v6094;
  return v6074;
}

struct StateT * slot_55(struct StateT * v1994) {
  int v1995 = v1994->timer;
  int v1996 = v1994->timer;
  int v2008 = v1996 + 1;
  v1994->timer = v2008;
  int * v1998 = v1994->reg_ready;
  int v1999 = v1998[8];
  int * v2000 = v1994->regs;
  int v2001 = v2000[8];
  int * v2002 = v1994->reg_ready;
  int v2013 = (v1999 + ((v1995 - v1999) & (~((v1995 - v1999) >> 31)))) + 1;
  v2002[8] = v2013;
  int * v2004 = v1994->regs;
  int v2015 = v2001 + 1;
  v2004[8] = v2015;
  struct StateT * v2006 = slot_56(v1994);
  return v2006;
}

struct StateT * slot_213(struct StateT * v5786) {
  int v5787 = v5786->timer;
  int v5788 = v5786->timer;
  int v5800 = v5788 + 1;
  v5786->timer = v5800;
  int * v5790 = v5786->reg_ready;
  int v5791 = v5790[8];
  int * v5792 = v5786->regs;
  int v5793 = v5792[8];
  int * v5794 = v5786->reg_ready;
  int v5805 = (v5791 + ((v5787 - v5791) & (~((v5787 - v5791) >> 31)))) + 1;
  v5794[8] = v5805;
  int * v5796 = v5786->regs;
  int v5807 = v5793 + 1;
  v5796[8] = v5807;
  struct StateT * v5798 = slot_214(v5786);
  return v5798;
}

struct StateT * slot_82(struct StateT * v2642) {
  int v2643 = v2642->timer;
  int v2644 = v2642->timer;
  int v2656 = v2644 + 1;
  v2642->timer = v2656;
  int * v2646 = v2642->reg_ready;
  int v2647 = v2646[8];
  int * v2648 = v2642->regs;
  int v2649 = v2648[8];
  int * v2650 = v2642->reg_ready;
  int v2661 = (v2647 + ((v2643 - v2647) & (~((v2643 - v2647) >> 31)))) + 1;
  v2650[8] = v2661;
  int * v2652 = v2642->regs;
  int v2663 = v2649 + 1;
  v2652[8] = v2663;
  struct StateT * v2654 = slot_83(v2642);
  return v2654;
}

struct StateT * slot_161(struct StateT * v4538) {
  int v4539 = v4538->timer;
  int v4540 = v4538->timer;
  int v4552 = v4540 + 1;
  v4538->timer = v4552;
  int * v4542 = v4538->reg_ready;
  int v4543 = v4542[8];
  int * v4544 = v4538->regs;
  int v4545 = v4544[8];
  int * v4546 = v4538->reg_ready;
  int v4557 = (v4543 + ((v4539 - v4543) & (~((v4539 - v4543) >> 31)))) + 1;
  v4546[8] = v4557;
  int * v4548 = v4538->regs;
  int v4559 = v4545 + 1;
  v4548[8] = v4559;
  struct StateT * v4550 = slot_162(v4538);
  return v4550;
}

struct StateT * slot_185(struct StateT * v5114) {
  int v5115 = v5114->timer;
  int v5116 = v5114->timer;
  int v5128 = v5116 + 1;
  v5114->timer = v5128;
  int * v5118 = v5114->reg_ready;
  int v5119 = v5118[8];
  int * v5120 = v5114->regs;
  int v5121 = v5120[8];
  int * v5122 = v5114->reg_ready;
  int v5133 = (v5119 + ((v5115 - v5119) & (~((v5115 - v5119) >> 31)))) + 1;
  v5122[8] = v5133;
  int * v5124 = v5114->regs;
  int v5135 = v5121 + 1;
  v5124[8] = v5135;
  struct StateT * v5126 = slot_186(v5114);
  return v5126;
}

struct StateT * slot_91(struct StateT * v2858) {
  int v2859 = v2858->timer;
  int v2860 = v2858->timer;
  int v2872 = v2860 + 1;
  v2858->timer = v2872;
  int * v2862 = v2858->reg_ready;
  int v2863 = v2862[8];
  int * v2864 = v2858->regs;
  int v2865 = v2864[8];
  int * v2866 = v2858->reg_ready;
  int v2877 = (v2863 + ((v2859 - v2863) & (~((v2859 - v2863) >> 31)))) + 1;
  v2866[8] = v2877;
  int * v2868 = v2858->regs;
  int v2879 = v2865 + 1;
  v2868[8] = v2879;
  struct StateT * v2870 = slot_92(v2858);
  return v2870;
}

struct StateT * slot_58(struct StateT * v2066) {
  int v2067 = v2066->timer;
  int v2068 = v2066->timer;
  int v2080 = v2068 + 1;
  v2066->timer = v2080;
  int * v2070 = v2066->reg_ready;
  int v2071 = v2070[8];
  int * v2072 = v2066->regs;
  int v2073 = v2072[8];
  int * v2074 = v2066->reg_ready;
  int v2085 = (v2071 + ((v2067 - v2071) & (~((v2067 - v2071) >> 31)))) + 1;
  v2074[8] = v2085;
  int * v2076 = v2066->regs;
  int v2087 = v2073 + 1;
  v2076[8] = v2087;
  struct StateT * v2078 = slot_59(v2066);
  return v2078;
}

struct StateT * slot_89(struct StateT * v2810) {
  int v2811 = v2810->timer;
  int v2812 = v2810->timer;
  int v2824 = v2812 + 1;
  v2810->timer = v2824;
  int * v2814 = v2810->reg_ready;
  int v2815 = v2814[8];
  int * v2816 = v2810->regs;
  int v2817 = v2816[8];
  int * v2818 = v2810->reg_ready;
  int v2829 = (v2815 + ((v2811 - v2815) & (~((v2811 - v2815) >> 31)))) + 1;
  v2818[8] = v2829;
  int * v2820 = v2810->regs;
  int v2831 = v2817 + 1;
  v2820[8] = v2831;
  struct StateT * v2822 = slot_90(v2810);
  return v2822;
}

struct StateT * slot_66(struct StateT * v2258) {
  int v2259 = v2258->timer;
  int v2260 = v2258->timer;
  int v2272 = v2260 + 1;
  v2258->timer = v2272;
  int * v2262 = v2258->reg_ready;
  int v2263 = v2262[8];
  int * v2264 = v2258->regs;
  int v2265 = v2264[8];
  int * v2266 = v2258->reg_ready;
  int v2277 = (v2263 + ((v2259 - v2263) & (~((v2259 - v2263) >> 31)))) + 1;
  v2266[8] = v2277;
  int * v2268 = v2258->regs;
  int v2279 = v2265 + 1;
  v2268[8] = v2279;
  struct StateT * v2270 = slot_67(v2258);
  return v2270;
}

struct StateT * slot_140(struct StateT * v4034) {
  int v4035 = v4034->timer;
  int v4036 = v4034->timer;
  int v4048 = v4036 + 1;
  v4034->timer = v4048;
  int * v4038 = v4034->reg_ready;
  int v4039 = v4038[8];
  int * v4040 = v4034->regs;
  int v4041 = v4040[8];
  int * v4042 = v4034->reg_ready;
  int v4053 = (v4039 + ((v4035 - v4039) & (~((v4035 - v4039) >> 31)))) + 1;
  v4042[8] = v4053;
  int * v4044 = v4034->regs;
  int v4055 = v4041 + 1;
  v4044[8] = v4055;
  struct StateT * v4046 = slot_141(v4034);
  return v4046;
}

struct StateT * slot_49(struct StateT * v1850) {
  int v1851 = v1850->timer;
  int v1852 = v1850->timer;
  int v1864 = v1852 + 1;
  v1850->timer = v1864;
  int * v1854 = v1850->reg_ready;
  int v1855 = v1854[8];
  int * v1856 = v1850->regs;
  int v1857 = v1856[8];
  int * v1858 = v1850->reg_ready;
  int v1869 = (v1855 + ((v1851 - v1855) & (~((v1851 - v1855) >> 31)))) + 1;
  v1858[8] = v1869;
  int * v1860 = v1850->regs;
  int v1871 = v1857 + 1;
  v1860[8] = v1871;
  struct StateT * v1862 = slot_50(v1850);
  return v1862;
}

struct StateT * slot_216(struct StateT * v5858) {
  int v5859 = v5858->timer;
  int v5860 = v5858->timer;
  int v5872 = v5860 + 1;
  v5858->timer = v5872;
  int * v5862 = v5858->reg_ready;
  int v5863 = v5862[8];
  int * v5864 = v5858->regs;
  int v5865 = v5864[8];
  int * v5866 = v5858->reg_ready;
  int v5877 = (v5863 + ((v5859 - v5863) & (~((v5859 - v5863) >> 31)))) + 1;
  v5866[8] = v5877;
  int * v5868 = v5858->regs;
  int v5879 = v5865 + 1;
  v5868[8] = v5879;
  struct StateT * v5870 = slot_217(v5858);
  return v5870;
}

struct StateT * slot_50(struct StateT * v1874) {
  int v1875 = v1874->timer;
  int v1876 = v1874->timer;
  int v1888 = v1876 + 1;
  v1874->timer = v1888;
  int * v1878 = v1874->reg_ready;
  int v1879 = v1878[8];
  int * v1880 = v1874->regs;
  int v1881 = v1880[8];
  int * v1882 = v1874->reg_ready;
  int v1893 = (v1879 + ((v1875 - v1879) & (~((v1875 - v1879) >> 31)))) + 1;
  v1882[8] = v1893;
  int * v1884 = v1874->regs;
  int v1895 = v1881 + 1;
  v1884[8] = v1895;
  struct StateT * v1886 = slot_51(v1874);
  return v1886;
}

struct StateT * slot_37(struct StateT * v1562) {
  int v1563 = v1562->timer;
  int v1564 = v1562->timer;
  int v1576 = v1564 + 1;
  v1562->timer = v1576;
  int * v1566 = v1562->reg_ready;
  int v1567 = v1566[8];
  int * v1568 = v1562->regs;
  int v1569 = v1568[8];
  int * v1570 = v1562->reg_ready;
  int v1581 = (v1567 + ((v1563 - v1567) & (~((v1563 - v1567) >> 31)))) + 1;
  v1570[8] = v1581;
  int * v1572 = v1562->regs;
  int v1583 = v1569 + 1;
  v1572[8] = v1583;
  struct StateT * v1574 = slot_38(v1562);
  return v1574;
}

struct StateT * slot_114(struct StateT * v3410) {
  int v3411 = v3410->timer;
  int v3412 = v3410->timer;
  int v3424 = v3412 + 1;
  v3410->timer = v3424;
  int * v3414 = v3410->reg_ready;
  int v3415 = v3414[8];
  int * v3416 = v3410->regs;
  int v3417 = v3416[8];
  int * v3418 = v3410->reg_ready;
  int v3429 = (v3415 + ((v3411 - v3415) & (~((v3411 - v3415) >> 31)))) + 1;
  v3418[8] = v3429;
  int * v3420 = v3410->regs;
  int v3431 = v3417 + 1;
  v3420[8] = v3431;
  struct StateT * v3422 = slot_115(v3410);
  return v3422;
}

struct StateT * slot_135(struct StateT * v3914) {
  int v3915 = v3914->timer;
  int v3916 = v3914->timer;
  int v3928 = v3916 + 1;
  v3914->timer = v3928;
  int * v3918 = v3914->reg_ready;
  int v3919 = v3918[8];
  int * v3920 = v3914->regs;
  int v3921 = v3920[8];
  int * v3922 = v3914->reg_ready;
  int v3933 = (v3919 + ((v3915 - v3919) & (~((v3915 - v3919) >> 31)))) + 1;
  v3922[8] = v3933;
  int * v3924 = v3914->regs;
  int v3935 = v3921 + 1;
  v3924[8] = v3935;
  struct StateT * v3926 = slot_136(v3914);
  return v3926;
}

struct StateT * slot_59(struct StateT * v2090) {
  int v2091 = v2090->timer;
  int v2092 = v2090->timer;
  int v2104 = v2092 + 1;
  v2090->timer = v2104;
  int * v2094 = v2090->reg_ready;
  int v2095 = v2094[8];
  int * v2096 = v2090->regs;
  int v2097 = v2096[8];
  int * v2098 = v2090->reg_ready;
  int v2109 = (v2095 + ((v2091 - v2095) & (~((v2091 - v2095) >> 31)))) + 1;
  v2098[8] = v2109;
  int * v2100 = v2090->regs;
  int v2111 = v2097 + 1;
  v2100[8] = v2111;
  struct StateT * v2102 = slot_60(v2090);
  return v2102;
}

struct StateT * slot_192(struct StateT * v5282) {
  int v5283 = v5282->timer;
  int v5284 = v5282->timer;
  int v5296 = v5284 + 1;
  v5282->timer = v5296;
  int * v5286 = v5282->reg_ready;
  int v5287 = v5286[8];
  int * v5288 = v5282->regs;
  int v5289 = v5288[8];
  int * v5290 = v5282->reg_ready;
  int v5301 = (v5287 + ((v5283 - v5287) & (~((v5283 - v5287) >> 31)))) + 1;
  v5290[8] = v5301;
  int * v5292 = v5282->regs;
  int v5303 = v5289 + 1;
  v5292[8] = v5303;
  struct StateT * v5294 = slot_193(v5282);
  return v5294;
}

struct StateT * slot_40(struct StateT * v1634) {
  int v1635 = v1634->timer;
  int v1636 = v1634->timer;
  int v1648 = v1636 + 1;
  v1634->timer = v1648;
  int * v1638 = v1634->reg_ready;
  int v1639 = v1638[8];
  int * v1640 = v1634->regs;
  int v1641 = v1640[8];
  int * v1642 = v1634->reg_ready;
  int v1653 = (v1639 + ((v1635 - v1639) & (~((v1635 - v1639) >> 31)))) + 1;
  v1642[8] = v1653;
  int * v1644 = v1634->regs;
  int v1655 = v1641 + 1;
  v1644[8] = v1655;
  struct StateT * v1646 = slot_41(v1634);
  return v1646;
}

struct StateT * slot_48(struct StateT * v1826) {
  int v1827 = v1826->timer;
  int v1828 = v1826->timer;
  int v1840 = v1828 + 1;
  v1826->timer = v1840;
  int * v1830 = v1826->reg_ready;
  int v1831 = v1830[8];
  int * v1832 = v1826->regs;
  int v1833 = v1832[8];
  int * v1834 = v1826->reg_ready;
  int v1845 = (v1831 + ((v1827 - v1831) & (~((v1827 - v1831) >> 31)))) + 1;
  v1834[8] = v1845;
  int * v1836 = v1826->regs;
  int v1847 = v1833 + 1;
  v1836[8] = v1847;
  struct StateT * v1838 = slot_49(v1826);
  return v1838;
}

struct StateT * slot_77(struct StateT * v2522) {
  int v2523 = v2522->timer;
  int v2524 = v2522->timer;
  int v2536 = v2524 + 1;
  v2522->timer = v2536;
  int * v2526 = v2522->reg_ready;
  int v2527 = v2526[8];
  int * v2528 = v2522->regs;
  int v2529 = v2528[8];
  int * v2530 = v2522->reg_ready;
  int v2541 = (v2527 + ((v2523 - v2527) & (~((v2523 - v2527) >> 31)))) + 1;
  v2530[8] = v2541;
  int * v2532 = v2522->regs;
  int v2543 = v2529 + 1;
  v2532[8] = v2543;
  struct StateT * v2534 = slot_78(v2522);
  return v2534;
}

struct StateT * slot_85(struct StateT * v2714) {
  int v2715 = v2714->timer;
  int v2716 = v2714->timer;
  int v2728 = v2716 + 1;
  v2714->timer = v2728;
  int * v2718 = v2714->reg_ready;
  int v2719 = v2718[8];
  int * v2720 = v2714->regs;
  int v2721 = v2720[8];
  int * v2722 = v2714->reg_ready;
  int v2733 = (v2719 + ((v2715 - v2719) & (~((v2715 - v2719) >> 31)))) + 1;
  v2722[8] = v2733;
  int * v2724 = v2714->regs;
  int v2735 = v2721 + 1;
  v2724[8] = v2735;
  struct StateT * v2726 = slot_86(v2714);
  return v2726;
}

struct StateT * slot_75(struct StateT * v2474) {
  int v2475 = v2474->timer;
  int v2476 = v2474->timer;
  int v2488 = v2476 + 1;
  v2474->timer = v2488;
  int * v2478 = v2474->reg_ready;
  int v2479 = v2478[8];
  int * v2480 = v2474->regs;
  int v2481 = v2480[8];
  int * v2482 = v2474->reg_ready;
  int v2493 = (v2479 + ((v2475 - v2479) & (~((v2475 - v2479) >> 31)))) + 1;
  v2482[8] = v2493;
  int * v2484 = v2474->regs;
  int v2495 = v2481 + 1;
  v2484[8] = v2495;
  struct StateT * v2486 = slot_76(v2474);
  return v2486;
}

struct StateT * slot_72(struct StateT * v2402) {
  int v2403 = v2402->timer;
  int v2404 = v2402->timer;
  int v2416 = v2404 + 1;
  v2402->timer = v2416;
  int * v2406 = v2402->reg_ready;
  int v2407 = v2406[8];
  int * v2408 = v2402->regs;
  int v2409 = v2408[8];
  int * v2410 = v2402->reg_ready;
  int v2421 = (v2407 + ((v2403 - v2407) & (~((v2403 - v2407) >> 31)))) + 1;
  v2410[8] = v2421;
  int * v2412 = v2402->regs;
  int v2423 = v2409 + 1;
  v2412[8] = v2423;
  struct StateT * v2414 = slot_73(v2402);
  return v2414;
}

struct StateT * slot_119(struct StateT * v3530) {
  int v3531 = v3530->timer;
  int v3532 = v3530->timer;
  int v3544 = v3532 + 1;
  v3530->timer = v3544;
  int * v3534 = v3530->reg_ready;
  int v3535 = v3534[8];
  int * v3536 = v3530->regs;
  int v3537 = v3536[8];
  int * v3538 = v3530->reg_ready;
  int v3549 = (v3535 + ((v3531 - v3535) & (~((v3531 - v3535) >> 31)))) + 1;
  v3538[8] = v3549;
  int * v3540 = v3530->regs;
  int v3551 = v3537 + 1;
  v3540[8] = v3551;
  struct StateT * v3542 = slot_120(v3530);
  return v3542;
}

struct StateT * slot_71(struct StateT * v2378) {
  int v2379 = v2378->timer;
  int v2380 = v2378->timer;
  int v2392 = v2380 + 1;
  v2378->timer = v2392;
  int * v2382 = v2378->reg_ready;
  int v2383 = v2382[8];
  int * v2384 = v2378->regs;
  int v2385 = v2384[8];
  int * v2386 = v2378->reg_ready;
  int v2397 = (v2383 + ((v2379 - v2383) & (~((v2379 - v2383) >> 31)))) + 1;
  v2386[8] = v2397;
  int * v2388 = v2378->regs;
  int v2399 = v2385 + 1;
  v2388[8] = v2399;
  struct StateT * v2390 = slot_72(v2378);
  return v2390;
}

struct StateT * slot_101(struct StateT * v3098) {
  int v3099 = v3098->timer;
  int v3100 = v3098->timer;
  int v3112 = v3100 + 1;
  v3098->timer = v3112;
  int * v3102 = v3098->reg_ready;
  int v3103 = v3102[8];
  int * v3104 = v3098->regs;
  int v3105 = v3104[8];
  int * v3106 = v3098->reg_ready;
  int v3117 = (v3103 + ((v3099 - v3103) & (~((v3099 - v3103) >> 31)))) + 1;
  v3106[8] = v3117;
  int * v3108 = v3098->regs;
  int v3119 = v3105 + 1;
  v3108[8] = v3119;
  struct StateT * v3110 = slot_102(v3098);
  return v3110;
}

struct StateT * slot_108(struct StateT * v3266) {
  int v3267 = v3266->timer;
  int v3268 = v3266->timer;
  int v3280 = v3268 + 1;
  v3266->timer = v3280;
  int * v3270 = v3266->reg_ready;
  int v3271 = v3270[8];
  int * v3272 = v3266->regs;
  int v3273 = v3272[8];
  int * v3274 = v3266->reg_ready;
  int v3285 = (v3271 + ((v3267 - v3271) & (~((v3267 - v3271) >> 31)))) + 1;
  v3274[8] = v3285;
  int * v3276 = v3266->regs;
  int v3287 = v3273 + 1;
  v3276[8] = v3287;
  struct StateT * v3278 = slot_109(v3266);
  return v3278;
}

struct StateT * slot_116(struct StateT * v3458) {
  int v3459 = v3458->timer;
  int v3460 = v3458->timer;
  int v3472 = v3460 + 1;
  v3458->timer = v3472;
  int * v3462 = v3458->reg_ready;
  int v3463 = v3462[8];
  int * v3464 = v3458->regs;
  int v3465 = v3464[8];
  int * v3466 = v3458->reg_ready;
  int v3477 = (v3463 + ((v3459 - v3463) & (~((v3459 - v3463) >> 31)))) + 1;
  v3466[8] = v3477;
  int * v3468 = v3458->regs;
  int v3479 = v3465 + 1;
  v3468[8] = v3479;
  struct StateT * v3470 = slot_117(v3458);
  return v3470;
}

struct StateT * slot_93(struct StateT * v2906) {
  int v2907 = v2906->timer;
  int v2908 = v2906->timer;
  int v2920 = v2908 + 1;
  v2906->timer = v2920;
  int * v2910 = v2906->reg_ready;
  int v2911 = v2910[8];
  int * v2912 = v2906->regs;
  int v2913 = v2912[8];
  int * v2914 = v2906->reg_ready;
  int v2925 = (v2911 + ((v2907 - v2911) & (~((v2907 - v2911) >> 31)))) + 1;
  v2914[8] = v2925;
  int * v2916 = v2906->regs;
  int v2927 = v2913 + 1;
  v2916[8] = v2927;
  struct StateT * v2918 = slot_94(v2906);
  return v2918;
}

struct StateT * slot_88(struct StateT * v2786) {
  int v2787 = v2786->timer;
  int v2788 = v2786->timer;
  int v2800 = v2788 + 1;
  v2786->timer = v2800;
  int * v2790 = v2786->reg_ready;
  int v2791 = v2790[8];
  int * v2792 = v2786->regs;
  int v2793 = v2792[8];
  int * v2794 = v2786->reg_ready;
  int v2805 = (v2791 + ((v2787 - v2791) & (~((v2787 - v2791) >> 31)))) + 1;
  v2794[8] = v2805;
  int * v2796 = v2786->regs;
  int v2807 = v2793 + 1;
  v2796[8] = v2807;
  struct StateT * v2798 = slot_89(v2786);
  return v2798;
}

struct StateT * slot_96(struct StateT * v2978) {
  int v2979 = v2978->timer;
  int v2980 = v2978->timer;
  int v2992 = v2980 + 1;
  v2978->timer = v2992;
  int * v2982 = v2978->reg_ready;
  int v2983 = v2982[8];
  int * v2984 = v2978->regs;
  int v2985 = v2984[8];
  int * v2986 = v2978->reg_ready;
  int v2997 = (v2983 + ((v2979 - v2983) & (~((v2979 - v2983) >> 31)))) + 1;
  v2986[8] = v2997;
  int * v2988 = v2978->regs;
  int v2999 = v2985 + 1;
  v2988[8] = v2999;
  struct StateT * v2990 = slot_97(v2978);
  return v2990;
}

struct StateT * slot_215(struct StateT * v5834) {
  int v5835 = v5834->timer;
  int v5836 = v5834->timer;
  int v5848 = v5836 + 1;
  v5834->timer = v5848;
  int * v5838 = v5834->reg_ready;
  int v5839 = v5838[8];
  int * v5840 = v5834->regs;
  int v5841 = v5840[8];
  int * v5842 = v5834->reg_ready;
  int v5853 = (v5839 + ((v5835 - v5839) & (~((v5835 - v5839) >> 31)))) + 1;
  v5842[8] = v5853;
  int * v5844 = v5834->regs;
  int v5855 = v5841 + 1;
  v5844[8] = v5855;
  struct StateT * v5846 = slot_216(v5834);
  return v5846;
}

struct StateT * slot_45(struct StateT * v1754) {
  int v1755 = v1754->timer;
  int v1756 = v1754->timer;
  int v1768 = v1756 + 1;
  v1754->timer = v1768;
  int * v1758 = v1754->reg_ready;
  int v1759 = v1758[8];
  int * v1760 = v1754->regs;
  int v1761 = v1760[8];
  int * v1762 = v1754->reg_ready;
  int v1773 = (v1759 + ((v1755 - v1759) & (~((v1755 - v1759) >> 31)))) + 1;
  v1762[8] = v1773;
  int * v1764 = v1754->regs;
  int v1775 = v1761 + 1;
  v1764[8] = v1775;
  struct StateT * v1766 = slot_46(v1754);
  return v1766;
}

struct StateT * slot_218(struct StateT * v5906) {
  int v5907 = v5906->timer;
  int v5908 = v5906->timer;
  int v5920 = v5908 + 1;
  v5906->timer = v5920;
  int * v5910 = v5906->reg_ready;
  int v5911 = v5910[8];
  int * v5912 = v5906->regs;
  int v5913 = v5912[8];
  int * v5914 = v5906->reg_ready;
  int v5925 = (v5911 + ((v5907 - v5911) & (~((v5907 - v5911) >> 31)))) + 1;
  v5914[8] = v5925;
  int * v5916 = v5906->regs;
  int v5927 = v5913 + 1;
  v5916[8] = v5927;
  struct StateT * v5918 = slot_219(v5906);
  return v5918;
}

struct StateT * slot_220(struct StateT * v5954) {
  int v5955 = v5954->timer;
  int v5956 = v5954->timer;
  int v5968 = v5956 + 1;
  v5954->timer = v5968;
  int * v5958 = v5954->reg_ready;
  int v5959 = v5958[8];
  int * v5960 = v5954->regs;
  int v5961 = v5960[8];
  int * v5962 = v5954->reg_ready;
  int v5973 = (v5959 + ((v5955 - v5959) & (~((v5955 - v5959) >> 31)))) + 1;
  v5962[8] = v5973;
  int * v5964 = v5954->regs;
  int v5975 = v5961 + 1;
  v5964[8] = v5975;
  struct StateT * v5966 = slot_221(v5954);
  return v5966;
}

struct StateT * slot_134(struct StateT * v3890) {
  int v3891 = v3890->timer;
  int v3892 = v3890->timer;
  int v3904 = v3892 + 1;
  v3890->timer = v3904;
  int * v3894 = v3890->reg_ready;
  int v3895 = v3894[8];
  int * v3896 = v3890->regs;
  int v3897 = v3896[8];
  int * v3898 = v3890->reg_ready;
  int v3909 = (v3895 + ((v3891 - v3895) & (~((v3891 - v3895) >> 31)))) + 1;
  v3898[8] = v3909;
  int * v3900 = v3890->regs;
  int v3911 = v3897 + 1;
  v3900[8] = v3911;
  struct StateT * v3902 = slot_135(v3890);
  return v3902;
}

struct StateT * slot_175(struct StateT * v4874) {
  int v4875 = v4874->timer;
  int v4876 = v4874->timer;
  int v4888 = v4876 + 1;
  v4874->timer = v4888;
  int * v4878 = v4874->reg_ready;
  int v4879 = v4878[8];
  int * v4880 = v4874->regs;
  int v4881 = v4880[8];
  int * v4882 = v4874->reg_ready;
  int v4893 = (v4879 + ((v4875 - v4879) & (~((v4875 - v4879) >> 31)))) + 1;
  v4882[8] = v4893;
  int * v4884 = v4874->regs;
  int v4895 = v4881 + 1;
  v4884[8] = v4895;
  struct StateT * v4886 = slot_176(v4874);
  return v4886;
}

struct StateT * slot_69(struct StateT * v2330) {
  int v2331 = v2330->timer;
  int v2332 = v2330->timer;
  int v2344 = v2332 + 1;
  v2330->timer = v2344;
  int * v2334 = v2330->reg_ready;
  int v2335 = v2334[8];
  int * v2336 = v2330->regs;
  int v2337 = v2336[8];
  int * v2338 = v2330->reg_ready;
  int v2349 = (v2335 + ((v2331 - v2335) & (~((v2331 - v2335) >> 31)))) + 1;
  v2338[8] = v2349;
  int * v2340 = v2330->regs;
  int v2351 = v2337 + 1;
  v2340[8] = v2351;
  struct StateT * v2342 = slot_70(v2330);
  return v2342;
}

struct StateT * slot_202(struct StateT * v5522) {
  int v5523 = v5522->timer;
  int v5524 = v5522->timer;
  int v5536 = v5524 + 1;
  v5522->timer = v5536;
  int * v5526 = v5522->reg_ready;
  int v5527 = v5526[8];
  int * v5528 = v5522->regs;
  int v5529 = v5528[8];
  int * v5530 = v5522->reg_ready;
  int v5541 = (v5527 + ((v5523 - v5527) & (~((v5523 - v5527) >> 31)))) + 1;
  v5530[8] = v5541;
  int * v5532 = v5522->regs;
  int v5543 = v5529 + 1;
  v5532[8] = v5543;
  struct StateT * v5534 = slot_203(v5522);
  return v5534;
}

struct StateT * slot_188(struct StateT * v5186) {
  int v5187 = v5186->timer;
  int v5188 = v5186->timer;
  int v5200 = v5188 + 1;
  v5186->timer = v5200;
  int * v5190 = v5186->reg_ready;
  int v5191 = v5190[8];
  int * v5192 = v5186->regs;
  int v5193 = v5192[8];
  int * v5194 = v5186->reg_ready;
  int v5205 = (v5191 + ((v5187 - v5191) & (~((v5187 - v5191) >> 31)))) + 1;
  v5194[8] = v5205;
  int * v5196 = v5186->regs;
  int v5207 = v5193 + 1;
  v5196[8] = v5207;
  struct StateT * v5198 = slot_189(v5186);
  return v5198;
}

struct StateT * slot_138(struct StateT * v3986) {
  int v3987 = v3986->timer;
  int v3988 = v3986->timer;
  int v4000 = v3988 + 1;
  v3986->timer = v4000;
  int * v3990 = v3986->reg_ready;
  int v3991 = v3990[8];
  int * v3992 = v3986->regs;
  int v3993 = v3992[8];
  int * v3994 = v3986->reg_ready;
  int v4005 = (v3991 + ((v3987 - v3991) & (~((v3987 - v3991) >> 31)))) + 1;
  v3994[8] = v4005;
  int * v3996 = v3986->regs;
  int v4007 = v3993 + 1;
  v3996[8] = v4007;
  struct StateT * v3998 = slot_139(v3986);
  return v3998;
}

struct StateT * slot_186(struct StateT * v5138) {
  int v5139 = v5138->timer;
  int v5140 = v5138->timer;
  int v5152 = v5140 + 1;
  v5138->timer = v5152;
  int * v5142 = v5138->reg_ready;
  int v5143 = v5142[8];
  int * v5144 = v5138->regs;
  int v5145 = v5144[8];
  int * v5146 = v5138->reg_ready;
  int v5157 = (v5143 + ((v5139 - v5143) & (~((v5139 - v5143) >> 31)))) + 1;
  v5146[8] = v5157;
  int * v5148 = v5138->regs;
  int v5159 = v5145 + 1;
  v5148[8] = v5159;
  struct StateT * v5150 = slot_187(v5138);
  return v5150;
}

struct StateT * slot_102(struct StateT * v3122) {
  int v3123 = v3122->timer;
  int v3124 = v3122->timer;
  int v3136 = v3124 + 1;
  v3122->timer = v3136;
  int * v3126 = v3122->reg_ready;
  int v3127 = v3126[8];
  int * v3128 = v3122->regs;
  int v3129 = v3128[8];
  int * v3130 = v3122->reg_ready;
  int v3141 = (v3127 + ((v3123 - v3127) & (~((v3123 - v3127) >> 31)))) + 1;
  v3130[8] = v3141;
  int * v3132 = v3122->regs;
  int v3143 = v3129 + 1;
  v3132[8] = v3143;
  struct StateT * v3134 = slot_103(v3122);
  return v3134;
}

struct StateT * slot_145(struct StateT * v4154) {
  int v4155 = v4154->timer;
  int v4156 = v4154->timer;
  int v4168 = v4156 + 1;
  v4154->timer = v4168;
  int * v4158 = v4154->reg_ready;
  int v4159 = v4158[8];
  int * v4160 = v4154->regs;
  int v4161 = v4160[8];
  int * v4162 = v4154->reg_ready;
  int v4173 = (v4159 + ((v4155 - v4159) & (~((v4155 - v4159) >> 31)))) + 1;
  v4162[8] = v4173;
  int * v4164 = v4154->regs;
  int v4175 = v4161 + 1;
  v4164[8] = v4175;
  struct StateT * v4166 = slot_146(v4154);
  return v4166;
}

struct StateT * slot_110(struct StateT * v3314) {
  int v3315 = v3314->timer;
  int v3316 = v3314->timer;
  int v3328 = v3316 + 1;
  v3314->timer = v3328;
  int * v3318 = v3314->reg_ready;
  int v3319 = v3318[8];
  int * v3320 = v3314->regs;
  int v3321 = v3320[8];
  int * v3322 = v3314->reg_ready;
  int v3333 = (v3319 + ((v3315 - v3319) & (~((v3315 - v3319) >> 31)))) + 1;
  v3322[8] = v3333;
  int * v3324 = v3314->regs;
  int v3335 = v3321 + 1;
  v3324[8] = v3335;
  struct StateT * v3326 = slot_111(v3314);
  return v3326;
}

struct StateT * slot_196(struct StateT * v5378) {
  int v5379 = v5378->timer;
  int v5380 = v5378->timer;
  int v5392 = v5380 + 1;
  v5378->timer = v5392;
  int * v5382 = v5378->reg_ready;
  int v5383 = v5382[8];
  int * v5384 = v5378->regs;
  int v5385 = v5384[8];
  int * v5386 = v5378->reg_ready;
  int v5397 = (v5383 + ((v5379 - v5383) & (~((v5379 - v5383) >> 31)))) + 1;
  v5386[8] = v5397;
  int * v5388 = v5378->regs;
  int v5399 = v5385 + 1;
  v5388[8] = v5399;
  struct StateT * v5390 = slot_197(v5378);
  return v5390;
}

struct StateT * slot_208(struct StateT * v5666) {
  int v5667 = v5666->timer;
  int v5668 = v5666->timer;
  int v5680 = v5668 + 1;
  v5666->timer = v5680;
  int * v5670 = v5666->reg_ready;
  int v5671 = v5670[8];
  int * v5672 = v5666->regs;
  int v5673 = v5672[8];
  int * v5674 = v5666->reg_ready;
  int v5685 = (v5671 + ((v5667 - v5671) & (~((v5667 - v5671) >> 31)))) + 1;
  v5674[8] = v5685;
  int * v5676 = v5666->regs;
  int v5687 = v5673 + 1;
  v5676[8] = v5687;
  struct StateT * v5678 = slot_209(v5666);
  return v5678;
}

struct StateT * slot_172(struct StateT * v4802) {
  int v4803 = v4802->timer;
  int v4804 = v4802->timer;
  int v4816 = v4804 + 1;
  v4802->timer = v4816;
  int * v4806 = v4802->reg_ready;
  int v4807 = v4806[8];
  int * v4808 = v4802->regs;
  int v4809 = v4808[8];
  int * v4810 = v4802->reg_ready;
  int v4821 = (v4807 + ((v4803 - v4807) & (~((v4803 - v4807) >> 31)))) + 1;
  v4810[8] = v4821;
  int * v4812 = v4802->regs;
  int v4823 = v4809 + 1;
  v4812[8] = v4823;
  struct StateT * v4814 = slot_173(v4802);
  return v4814;
}

struct StateT * slot_131(struct StateT * v3818) {
  int v3819 = v3818->timer;
  int v3820 = v3818->timer;
  int v3832 = v3820 + 1;
  v3818->timer = v3832;
  int * v3822 = v3818->reg_ready;
  int v3823 = v3822[8];
  int * v3824 = v3818->regs;
  int v3825 = v3824[8];
  int * v3826 = v3818->reg_ready;
  int v3837 = (v3823 + ((v3819 - v3823) & (~((v3819 - v3823) >> 31)))) + 1;
  v3826[8] = v3837;
  int * v3828 = v3818->regs;
  int v3839 = v3825 + 1;
  v3828[8] = v3839;
  struct StateT * v3830 = slot_132(v3818);
  return v3830;
}

struct StateT * slot_8(struct StateT * v866) {
  int v867 = v866->timer;
  int v868 = v866->timer;
  int v880 = v868 + 1;
  v866->timer = v880;
  int * v870 = v866->reg_ready;
  int v871 = v870[8];
  int * v872 = v866->regs;
  int v873 = v872[8];
  int * v874 = v866->reg_ready;
  int v885 = (v871 + ((v867 - v871) & (~((v867 - v871) >> 31)))) + 1;
  v874[8] = v885;
  int * v876 = v866->regs;
  int v887 = v873 + 1;
  v876[8] = v887;
  struct StateT * v878 = slot_9(v866);
  return v878;
}

struct StateT * slot_180(struct StateT * v4994) {
  int v4995 = v4994->timer;
  int v4996 = v4994->timer;
  int v5008 = v4996 + 1;
  v4994->timer = v5008;
  int * v4998 = v4994->reg_ready;
  int v4999 = v4998[8];
  int * v5000 = v4994->regs;
  int v5001 = v5000[8];
  int * v5002 = v4994->reg_ready;
  int v5013 = (v4999 + ((v4995 - v4999) & (~((v4995 - v4999) >> 31)))) + 1;
  v5002[8] = v5013;
  int * v5004 = v4994->regs;
  int v5015 = v5001 + 1;
  v5004[8] = v5015;
  struct StateT * v5006 = slot_181(v4994);
  return v5006;
}

struct StateT * slot_203(struct StateT * v5546) {
  int v5547 = v5546->timer;
  int v5548 = v5546->timer;
  int v5560 = v5548 + 1;
  v5546->timer = v5560;
  int * v5550 = v5546->reg_ready;
  int v5551 = v5550[8];
  int * v5552 = v5546->regs;
  int v5553 = v5552[8];
  int * v5554 = v5546->reg_ready;
  int v5565 = (v5551 + ((v5547 - v5551) & (~((v5547 - v5551) >> 31)))) + 1;
  v5554[8] = v5565;
  int * v5556 = v5546->regs;
  int v5567 = v5553 + 1;
  v5556[8] = v5567;
  struct StateT * v5558 = slot_204(v5546);
  return v5558;
}

struct StateT * slot_190(struct StateT * v5234) {
  int v5235 = v5234->timer;
  int v5236 = v5234->timer;
  int v5248 = v5236 + 1;
  v5234->timer = v5248;
  int * v5238 = v5234->reg_ready;
  int v5239 = v5238[8];
  int * v5240 = v5234->regs;
  int v5241 = v5240[8];
  int * v5242 = v5234->reg_ready;
  int v5253 = (v5239 + ((v5235 - v5239) & (~((v5235 - v5239) >> 31)))) + 1;
  v5242[8] = v5253;
  int * v5244 = v5234->regs;
  int v5255 = v5241 + 1;
  v5244[8] = v5255;
  struct StateT * v5246 = slot_191(v5234);
  return v5246;
}

struct StateT * slot_157(struct StateT * v4442) {
  int v4443 = v4442->timer;
  int v4444 = v4442->timer;
  int v4456 = v4444 + 1;
  v4442->timer = v4456;
  int * v4446 = v4442->reg_ready;
  int v4447 = v4446[8];
  int * v4448 = v4442->regs;
  int v4449 = v4448[8];
  int * v4450 = v4442->reg_ready;
  int v4461 = (v4447 + ((v4443 - v4447) & (~((v4443 - v4447) >> 31)))) + 1;
  v4450[8] = v4461;
  int * v4452 = v4442->regs;
  int v4463 = v4449 + 1;
  v4452[8] = v4463;
  struct StateT * v4454 = slot_158(v4442);
  return v4454;
}

struct StateT * slot_200(struct StateT * v5474) {
  int v5475 = v5474->timer;
  int v5476 = v5474->timer;
  int v5488 = v5476 + 1;
  v5474->timer = v5488;
  int * v5478 = v5474->reg_ready;
  int v5479 = v5478[8];
  int * v5480 = v5474->regs;
  int v5481 = v5480[8];
  int * v5482 = v5474->reg_ready;
  int v5493 = (v5479 + ((v5475 - v5479) & (~((v5475 - v5479) >> 31)))) + 1;
  v5482[8] = v5493;
  int * v5484 = v5474->regs;
  int v5495 = v5481 + 1;
  v5484[8] = v5495;
  struct StateT * v5486 = slot_201(v5474);
  return v5486;
}

struct StateT * slot_173(struct StateT * v4826) {
  int v4827 = v4826->timer;
  int v4828 = v4826->timer;
  int v4840 = v4828 + 1;
  v4826->timer = v4840;
  int * v4830 = v4826->reg_ready;
  int v4831 = v4830[8];
  int * v4832 = v4826->regs;
  int v4833 = v4832[8];
  int * v4834 = v4826->reg_ready;
  int v4845 = (v4831 + ((v4827 - v4831) & (~((v4827 - v4831) >> 31)))) + 1;
  v4834[8] = v4845;
  int * v4836 = v4826->regs;
  int v4847 = v4833 + 1;
  v4836[8] = v4847;
  struct StateT * v4838 = slot_174(v4826);
  return v4838;
}

struct StateT * slot_149(struct StateT * v4250) {
  int v4251 = v4250->timer;
  int v4252 = v4250->timer;
  int v4264 = v4252 + 1;
  v4250->timer = v4264;
  int * v4254 = v4250->reg_ready;
  int v4255 = v4254[8];
  int * v4256 = v4250->regs;
  int v4257 = v4256[8];
  int * v4258 = v4250->reg_ready;
  int v4269 = (v4255 + ((v4251 - v4255) & (~((v4251 - v4255) >> 31)))) + 1;
  v4258[8] = v4269;
  int * v4260 = v4250->regs;
  int v4271 = v4257 + 1;
  v4260[8] = v4271;
  struct StateT * v4262 = slot_150(v4250);
  return v4262;
}

struct StateT * slot_5(struct StateT * v800) {
  int v801 = v800->timer;
  int v802 = v800->timer;
  int v810 = v802 + 1;
  v800->timer = v810;
  int * v804 = v800->reg_ready;
  int v813 = v801 + 1;
  v804[8] = v813;
  int * v806 = v800->regs;
  v806[8] = 0;
  struct StateT * v808 = slot_6(v800);
  return v808;
}

struct StateT * slot_104(struct StateT * v3170) {
  int v3171 = v3170->timer;
  int v3172 = v3170->timer;
  int v3184 = v3172 + 1;
  v3170->timer = v3184;
  int * v3174 = v3170->reg_ready;
  int v3175 = v3174[8];
  int * v3176 = v3170->regs;
  int v3177 = v3176[8];
  int * v3178 = v3170->reg_ready;
  int v3189 = (v3175 + ((v3171 - v3175) & (~((v3171 - v3175) >> 31)))) + 1;
  v3178[8] = v3189;
  int * v3180 = v3170->regs;
  int v3191 = v3177 + 1;
  v3180[8] = v3191;
  struct StateT * v3182 = slot_105(v3170);
  return v3182;
}

struct StateT * slot_54(struct StateT * v1970) {
  int v1971 = v1970->timer;
  int v1972 = v1970->timer;
  int v1984 = v1972 + 1;
  v1970->timer = v1984;
  int * v1974 = v1970->reg_ready;
  int v1975 = v1974[8];
  int * v1976 = v1970->regs;
  int v1977 = v1976[8];
  int * v1978 = v1970->reg_ready;
  int v1989 = (v1975 + ((v1971 - v1975) & (~((v1971 - v1975) >> 31)))) + 1;
  v1978[8] = v1989;
  int * v1980 = v1970->regs;
  int v1991 = v1977 + 1;
  v1980[8] = v1991;
  struct StateT * v1982 = slot_55(v1970);
  return v1982;
}

struct StateT * slot_26(struct StateT * v1298) {
  int v1299 = v1298->timer;
  int v1300 = v1298->timer;
  int v1312 = v1300 + 1;
  v1298->timer = v1312;
  int * v1302 = v1298->reg_ready;
  int v1303 = v1302[8];
  int * v1304 = v1298->regs;
  int v1305 = v1304[8];
  int * v1306 = v1298->reg_ready;
  int v1317 = (v1303 + ((v1299 - v1303) & (~((v1299 - v1303) >> 31)))) + 1;
  v1306[8] = v1317;
  int * v1308 = v1298->regs;
  int v1319 = v1305 + 1;
  v1308[8] = v1319;
  struct StateT * v1310 = slot_27(v1298);
  return v1310;
}

struct StateT * slot_206(struct StateT * v5618) {
  int v5619 = v5618->timer;
  int v5620 = v5618->timer;
  int v5632 = v5620 + 1;
  v5618->timer = v5632;
  int * v5622 = v5618->reg_ready;
  int v5623 = v5622[8];
  int * v5624 = v5618->regs;
  int v5625 = v5624[8];
  int * v5626 = v5618->reg_ready;
  int v5637 = (v5623 + ((v5619 - v5623) & (~((v5619 - v5623) >> 31)))) + 1;
  v5626[8] = v5637;
  int * v5628 = v5618->regs;
  int v5639 = v5625 + 1;
  v5628[8] = v5639;
  struct StateT * v5630 = slot_207(v5618);
  return v5630;
}

struct StateT * slot_169(struct StateT * v4730) {
  int v4731 = v4730->timer;
  int v4732 = v4730->timer;
  int v4744 = v4732 + 1;
  v4730->timer = v4744;
  int * v4734 = v4730->reg_ready;
  int v4735 = v4734[8];
  int * v4736 = v4730->regs;
  int v4737 = v4736[8];
  int * v4738 = v4730->reg_ready;
  int v4749 = (v4735 + ((v4731 - v4735) & (~((v4731 - v4735) >> 31)))) + 1;
  v4738[8] = v4749;
  int * v4740 = v4730->regs;
  int v4751 = v4737 + 1;
  v4740[8] = v4751;
  struct StateT * v4742 = slot_170(v4730);
  return v4742;
}

struct StateT * slot_64(struct StateT * v2210) {
  int v2211 = v2210->timer;
  int v2212 = v2210->timer;
  int v2224 = v2212 + 1;
  v2210->timer = v2224;
  int * v2214 = v2210->reg_ready;
  int v2215 = v2214[8];
  int * v2216 = v2210->regs;
  int v2217 = v2216[8];
  int * v2218 = v2210->reg_ready;
  int v2229 = (v2215 + ((v2211 - v2215) & (~((v2211 - v2215) >> 31)))) + 1;
  v2218[8] = v2229;
  int * v2220 = v2210->regs;
  int v2231 = v2217 + 1;
  v2220[8] = v2231;
  struct StateT * v2222 = slot_65(v2210);
  return v2222;
}

struct StateT * slot_170(struct StateT * v4754) {
  int v4755 = v4754->timer;
  int v4756 = v4754->timer;
  int v4768 = v4756 + 1;
  v4754->timer = v4768;
  int * v4758 = v4754->reg_ready;
  int v4759 = v4758[8];
  int * v4760 = v4754->regs;
  int v4761 = v4760[8];
  int * v4762 = v4754->reg_ready;
  int v4773 = (v4759 + ((v4755 - v4759) & (~((v4755 - v4759) >> 31)))) + 1;
  v4762[8] = v4773;
  int * v4764 = v4754->regs;
  int v4775 = v4761 + 1;
  v4764[8] = v4775;
  struct StateT * v4766 = slot_171(v4754);
  return v4766;
}

struct StateT * slot_14(struct StateT * v1010) {
  int v1011 = v1010->timer;
  int v1012 = v1010->timer;
  int v1024 = v1012 + 1;
  v1010->timer = v1024;
  int * v1014 = v1010->reg_ready;
  int v1015 = v1014[8];
  int * v1016 = v1010->regs;
  int v1017 = v1016[8];
  int * v1018 = v1010->reg_ready;
  int v1029 = (v1015 + ((v1011 - v1015) & (~((v1011 - v1015) >> 31)))) + 1;
  v1018[8] = v1029;
  int * v1020 = v1010->regs;
  int v1031 = v1017 + 1;
  v1020[8] = v1031;
  struct StateT * v1022 = slot_15(v1010);
  return v1022;
}

struct StateT * slot_53(struct StateT * v1946) {
  int v1947 = v1946->timer;
  int v1948 = v1946->timer;
  int v1960 = v1948 + 1;
  v1946->timer = v1960;
  int * v1950 = v1946->reg_ready;
  int v1951 = v1950[8];
  int * v1952 = v1946->regs;
  int v1953 = v1952[8];
  int * v1954 = v1946->reg_ready;
  int v1965 = (v1951 + ((v1947 - v1951) & (~((v1947 - v1951) >> 31)))) + 1;
  v1954[8] = v1965;
  int * v1956 = v1946->regs;
  int v1967 = v1953 + 1;
  v1956[8] = v1967;
  struct StateT * v1958 = slot_54(v1946);
  return v1958;
}

struct StateT * slot_80(struct StateT * v2594) {
  int v2595 = v2594->timer;
  int v2596 = v2594->timer;
  int v2608 = v2596 + 1;
  v2594->timer = v2608;
  int * v2598 = v2594->reg_ready;
  int v2599 = v2598[8];
  int * v2600 = v2594->regs;
  int v2601 = v2600[8];
  int * v2602 = v2594->reg_ready;
  int v2613 = (v2599 + ((v2595 - v2599) & (~((v2595 - v2599) >> 31)))) + 1;
  v2602[8] = v2613;
  int * v2604 = v2594->regs;
  int v2615 = v2601 + 1;
  v2604[8] = v2615;
  struct StateT * v2606 = slot_81(v2594);
  return v2606;
}

struct StateT * slot_44(struct StateT * v1730) {
  int v1731 = v1730->timer;
  int v1732 = v1730->timer;
  int v1744 = v1732 + 1;
  v1730->timer = v1744;
  int * v1734 = v1730->reg_ready;
  int v1735 = v1734[8];
  int * v1736 = v1730->regs;
  int v1737 = v1736[8];
  int * v1738 = v1730->reg_ready;
  int v1749 = (v1735 + ((v1731 - v1735) & (~((v1731 - v1735) >> 31)))) + 1;
  v1738[8] = v1749;
  int * v1740 = v1730->regs;
  int v1751 = v1737 + 1;
  v1740[8] = v1751;
  struct StateT * v1742 = slot_45(v1730);
  return v1742;
}

struct StateT * slot_137(struct StateT * v3962) {
  int v3963 = v3962->timer;
  int v3964 = v3962->timer;
  int v3976 = v3964 + 1;
  v3962->timer = v3976;
  int * v3966 = v3962->reg_ready;
  int v3967 = v3966[8];
  int * v3968 = v3962->regs;
  int v3969 = v3968[8];
  int * v3970 = v3962->reg_ready;
  int v3981 = (v3967 + ((v3963 - v3967) & (~((v3963 - v3967) >> 31)))) + 1;
  v3970[8] = v3981;
  int * v3972 = v3962->regs;
  int v3983 = v3969 + 1;
  v3972[8] = v3983;
  struct StateT * v3974 = slot_138(v3962);
  return v3974;
}

struct StateT * slot_122(struct StateT * v3602) {
  int v3603 = v3602->timer;
  int v3604 = v3602->timer;
  int v3616 = v3604 + 1;
  v3602->timer = v3616;
  int * v3606 = v3602->reg_ready;
  int v3607 = v3606[8];
  int * v3608 = v3602->regs;
  int v3609 = v3608[8];
  int * v3610 = v3602->reg_ready;
  int v3621 = (v3607 + ((v3603 - v3607) & (~((v3603 - v3607) >> 31)))) + 1;
  v3610[8] = v3621;
  int * v3612 = v3602->regs;
  int v3623 = v3609 + 1;
  v3612[8] = v3623;
  struct StateT * v3614 = slot_123(v3602);
  return v3614;
}

struct StateT * slot_99(struct StateT * v3050) {
  int v3051 = v3050->timer;
  int v3052 = v3050->timer;
  int v3064 = v3052 + 1;
  v3050->timer = v3064;
  int * v3054 = v3050->reg_ready;
  int v3055 = v3054[8];
  int * v3056 = v3050->regs;
  int v3057 = v3056[8];
  int * v3058 = v3050->reg_ready;
  int v3069 = (v3055 + ((v3051 - v3055) & (~((v3051 - v3055) >> 31)))) + 1;
  v3058[8] = v3069;
  int * v3060 = v3050->regs;
  int v3071 = v3057 + 1;
  v3060[8] = v3071;
  struct StateT * v3062 = slot_100(v3050);
  return v3062;
}

struct StateT * slot_179(struct StateT * v4970) {
  int v4971 = v4970->timer;
  int v4972 = v4970->timer;
  int v4984 = v4972 + 1;
  v4970->timer = v4984;
  int * v4974 = v4970->reg_ready;
  int v4975 = v4974[8];
  int * v4976 = v4970->regs;
  int v4977 = v4976[8];
  int * v4978 = v4970->reg_ready;
  int v4989 = (v4975 + ((v4971 - v4975) & (~((v4971 - v4975) >> 31)))) + 1;
  v4978[8] = v4989;
  int * v4980 = v4970->regs;
  int v4991 = v4977 + 1;
  v4980[8] = v4991;
  struct StateT * v4982 = slot_180(v4970);
  return v4982;
}

struct StateT * slot_219(struct StateT * v5930) {
  int v5931 = v5930->timer;
  int v5932 = v5930->timer;
  int v5944 = v5932 + 1;
  v5930->timer = v5944;
  int * v5934 = v5930->reg_ready;
  int v5935 = v5934[8];
  int * v5936 = v5930->regs;
  int v5937 = v5936[8];
  int * v5938 = v5930->reg_ready;
  int v5949 = (v5935 + ((v5931 - v5935) & (~((v5931 - v5935) >> 31)))) + 1;
  v5938[8] = v5949;
  int * v5940 = v5930->regs;
  int v5951 = v5937 + 1;
  v5940[8] = v5951;
  struct StateT * v5942 = slot_220(v5930);
  return v5942;
}

struct StateT * slot_36(struct StateT * v1538) {
  int v1539 = v1538->timer;
  int v1540 = v1538->timer;
  int v1552 = v1540 + 1;
  v1538->timer = v1552;
  int * v1542 = v1538->reg_ready;
  int v1543 = v1542[8];
  int * v1544 = v1538->regs;
  int v1545 = v1544[8];
  int * v1546 = v1538->reg_ready;
  int v1557 = (v1543 + ((v1539 - v1543) & (~((v1539 - v1543) >> 31)))) + 1;
  v1546[8] = v1557;
  int * v1548 = v1538->regs;
  int v1559 = v1545 + 1;
  v1548[8] = v1559;
  struct StateT * v1550 = slot_37(v1538);
  return v1550;
}

struct StateT * slot_57(struct StateT * v2042) {
  int v2043 = v2042->timer;
  int v2044 = v2042->timer;
  int v2056 = v2044 + 1;
  v2042->timer = v2056;
  int * v2046 = v2042->reg_ready;
  int v2047 = v2046[8];
  int * v2048 = v2042->regs;
  int v2049 = v2048[8];
  int * v2050 = v2042->reg_ready;
  int v2061 = (v2047 + ((v2043 - v2047) & (~((v2043 - v2047) >> 31)))) + 1;
  v2050[8] = v2061;
  int * v2052 = v2042->regs;
  int v2063 = v2049 + 1;
  v2052[8] = v2063;
  struct StateT * v2054 = slot_58(v2042);
  return v2054;
}

struct StateT * slot_62(struct StateT * v2162) {
  int v2163 = v2162->timer;
  int v2164 = v2162->timer;
  int v2176 = v2164 + 1;
  v2162->timer = v2176;
  int * v2166 = v2162->reg_ready;
  int v2167 = v2166[8];
  int * v2168 = v2162->regs;
  int v2169 = v2168[8];
  int * v2170 = v2162->reg_ready;
  int v2181 = (v2167 + ((v2163 - v2167) & (~((v2163 - v2167) >> 31)))) + 1;
  v2170[8] = v2181;
  int * v2172 = v2162->regs;
  int v2183 = v2169 + 1;
  v2172[8] = v2183;
  struct StateT * v2174 = slot_63(v2162);
  return v2174;
}

struct StateT * slot_22(struct StateT * v1202) {
  int v1203 = v1202->timer;
  int v1204 = v1202->timer;
  int v1216 = v1204 + 1;
  v1202->timer = v1216;
  int * v1206 = v1202->reg_ready;
  int v1207 = v1206[8];
  int * v1208 = v1202->regs;
  int v1209 = v1208[8];
  int * v1210 = v1202->reg_ready;
  int v1221 = (v1207 + ((v1203 - v1207) & (~((v1203 - v1207) >> 31)))) + 1;
  v1210[8] = v1221;
  int * v1212 = v1202->regs;
  int v1223 = v1209 + 1;
  v1212[8] = v1223;
  struct StateT * v1214 = slot_23(v1202);
  return v1214;
}

struct StateT * slot_139(struct StateT * v4010) {
  int v4011 = v4010->timer;
  int v4012 = v4010->timer;
  int v4024 = v4012 + 1;
  v4010->timer = v4024;
  int * v4014 = v4010->reg_ready;
  int v4015 = v4014[8];
  int * v4016 = v4010->regs;
  int v4017 = v4016[8];
  int * v4018 = v4010->reg_ready;
  int v4029 = (v4015 + ((v4011 - v4015) & (~((v4011 - v4015) >> 31)))) + 1;
  v4018[8] = v4029;
  int * v4020 = v4010->regs;
  int v4031 = v4017 + 1;
  v4020[8] = v4031;
  struct StateT * v4022 = slot_140(v4010);
  return v4022;
}

struct StateT * slot_221(struct StateT * v5978) {
  int v5979 = v5978->timer;
  int v5980 = v5978->timer;
  int v5992 = v5980 + 1;
  v5978->timer = v5992;
  int * v5982 = v5978->reg_ready;
  int v5983 = v5982[8];
  int * v5984 = v5978->regs;
  int v5985 = v5984[8];
  int * v5986 = v5978->reg_ready;
  int v5997 = (v5983 + ((v5979 - v5983) & (~((v5979 - v5983) >> 31)))) + 1;
  v5986[8] = v5997;
  int * v5988 = v5978->regs;
  int v5999 = v5985 + 1;
  v5988[8] = v5999;
  struct StateT * v5990 = slot_222(v5978);
  return v5990;
}

struct StateT * slot_23(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1228 = v1226->timer;
  int v1240 = v1228 + 1;
  v1226->timer = v1240;
  int * v1230 = v1226->reg_ready;
  int v1231 = v1230[8];
  int * v1232 = v1226->regs;
  int v1233 = v1232[8];
  int * v1234 = v1226->reg_ready;
  int v1245 = (v1231 + ((v1227 - v1231) & (~((v1227 - v1231) >> 31)))) + 1;
  v1234[8] = v1245;
  int * v1236 = v1226->regs;
  int v1247 = v1233 + 1;
  v1236[8] = v1247;
  struct StateT * v1238 = slot_24(v1226);
  return v1238;
}

struct StateT * slot_153(struct StateT * v4346) {
  int v4347 = v4346->timer;
  int v4348 = v4346->timer;
  int v4360 = v4348 + 1;
  v4346->timer = v4360;
  int * v4350 = v4346->reg_ready;
  int v4351 = v4350[8];
  int * v4352 = v4346->regs;
  int v4353 = v4352[8];
  int * v4354 = v4346->reg_ready;
  int v4365 = (v4351 + ((v4347 - v4351) & (~((v4347 - v4351) >> 31)))) + 1;
  v4354[8] = v4365;
  int * v4356 = v4346->regs;
  int v4367 = v4353 + 1;
  v4356[8] = v4367;
  struct StateT * v4358 = slot_154(v4346);
  return v4358;
}

struct StateT * slot_2(struct StateT * v497) {
  int v498 = v497->timer;
  int v499 = v497->timer;
  int v511 = v499 + 1;
  v497->timer = v511;
  int * v501 = v497->reg_ready;
  int v502 = v501[6];
  int * v503 = v497->regs;
  int v504 = v503[6];
  int * v505 = v497->reg_ready;
  int v516 = (v502 + ((v498 - v502) & (~((v498 - v502) >> 31)))) + 1;
  v505[6] = v516;
  int * v507 = v497->regs;
  int v518 = v504 & 7;
  v507[6] = v518;
  struct StateT * v509 = slot_3(v497);
  return v509;
}

struct StateT * slot_86(struct StateT * v2738) {
  int v2739 = v2738->timer;
  int v2740 = v2738->timer;
  int v2752 = v2740 + 1;
  v2738->timer = v2752;
  int * v2742 = v2738->reg_ready;
  int v2743 = v2742[8];
  int * v2744 = v2738->regs;
  int v2745 = v2744[8];
  int * v2746 = v2738->reg_ready;
  int v2757 = (v2743 + ((v2739 - v2743) & (~((v2739 - v2743) >> 31)))) + 1;
  v2746[8] = v2757;
  int * v2748 = v2738->regs;
  int v2759 = v2745 + 1;
  v2748[8] = v2759;
  struct StateT * v2750 = slot_87(v2738);
  return v2750;
}

struct StateT * slot_129(struct StateT * v3770) {
  int v3771 = v3770->timer;
  int v3772 = v3770->timer;
  int v3784 = v3772 + 1;
  v3770->timer = v3784;
  int * v3774 = v3770->reg_ready;
  int v3775 = v3774[8];
  int * v3776 = v3770->regs;
  int v3777 = v3776[8];
  int * v3778 = v3770->reg_ready;
  int v3789 = (v3775 + ((v3771 - v3775) & (~((v3771 - v3775) >> 31)))) + 1;
  v3778[8] = v3789;
  int * v3780 = v3770->regs;
  int v3791 = v3777 + 1;
  v3780[8] = v3791;
  struct StateT * v3782 = slot_130(v3770);
  return v3782;
}

struct StateT * slot_158(struct StateT * v4466) {
  int v4467 = v4466->timer;
  int v4468 = v4466->timer;
  int v4480 = v4468 + 1;
  v4466->timer = v4480;
  int * v4470 = v4466->reg_ready;
  int v4471 = v4470[8];
  int * v4472 = v4466->regs;
  int v4473 = v4472[8];
  int * v4474 = v4466->reg_ready;
  int v4485 = (v4471 + ((v4467 - v4471) & (~((v4467 - v4471) >> 31)))) + 1;
  v4474[8] = v4485;
  int * v4476 = v4466->regs;
  int v4487 = v4473 + 1;
  v4476[8] = v4487;
  struct StateT * v4478 = slot_159(v4466);
  return v4478;
}

struct StateT * slot_100(struct StateT * v3074) {
  int v3075 = v3074->timer;
  int v3076 = v3074->timer;
  int v3088 = v3076 + 1;
  v3074->timer = v3088;
  int * v3078 = v3074->reg_ready;
  int v3079 = v3078[8];
  int * v3080 = v3074->regs;
  int v3081 = v3080[8];
  int * v3082 = v3074->reg_ready;
  int v3093 = (v3079 + ((v3075 - v3079) & (~((v3075 - v3079) >> 31)))) + 1;
  v3082[8] = v3093;
  int * v3084 = v3074->regs;
  int v3095 = v3081 + 1;
  v3084[8] = v3095;
  struct StateT * v3086 = slot_101(v3074);
  return v3086;
}

struct StateT * slot_127(struct StateT * v3722) {
  int v3723 = v3722->timer;
  int v3724 = v3722->timer;
  int v3736 = v3724 + 1;
  v3722->timer = v3736;
  int * v3726 = v3722->reg_ready;
  int v3727 = v3726[8];
  int * v3728 = v3722->regs;
  int v3729 = v3728[8];
  int * v3730 = v3722->reg_ready;
  int v3741 = (v3727 + ((v3723 - v3727) & (~((v3723 - v3727) >> 31)))) + 1;
  v3730[8] = v3741;
  int * v3732 = v3722->regs;
  int v3743 = v3729 + 1;
  v3732[8] = v3743;
  struct StateT * v3734 = slot_128(v3722);
  return v3734;
}

struct StateT * slot_217(struct StateT * v5882) {
  int v5883 = v5882->timer;
  int v5884 = v5882->timer;
  int v5896 = v5884 + 1;
  v5882->timer = v5896;
  int * v5886 = v5882->reg_ready;
  int v5887 = v5886[8];
  int * v5888 = v5882->regs;
  int v5889 = v5888[8];
  int * v5890 = v5882->reg_ready;
  int v5901 = (v5887 + ((v5883 - v5887) & (~((v5883 - v5887) >> 31)))) + 1;
  v5890[8] = v5901;
  int * v5892 = v5882->regs;
  int v5903 = v5889 + 1;
  v5892[8] = v5903;
  struct StateT * v5894 = slot_218(v5882);
  return v5894;
}

struct StateT * slot_13(struct StateT * v986) {
  int v987 = v986->timer;
  int v988 = v986->timer;
  int v1000 = v988 + 1;
  v986->timer = v1000;
  int * v990 = v986->reg_ready;
  int v991 = v990[8];
  int * v992 = v986->regs;
  int v993 = v992[8];
  int * v994 = v986->reg_ready;
  int v1005 = (v991 + ((v987 - v991) & (~((v987 - v991) >> 31)))) + 1;
  v994[8] = v1005;
  int * v996 = v986->regs;
  int v1007 = v993 + 1;
  v996[8] = v1007;
  struct StateT * v998 = slot_14(v986);
  return v998;
}

struct StateT * slot_111(struct StateT * v3338) {
  int v3339 = v3338->timer;
  int v3340 = v3338->timer;
  int v3352 = v3340 + 1;
  v3338->timer = v3352;
  int * v3342 = v3338->reg_ready;
  int v3343 = v3342[8];
  int * v3344 = v3338->regs;
  int v3345 = v3344[8];
  int * v3346 = v3338->reg_ready;
  int v3357 = (v3343 + ((v3339 - v3343) & (~((v3339 - v3343) >> 31)))) + 1;
  v3346[8] = v3357;
  int * v3348 = v3338->regs;
  int v3359 = v3345 + 1;
  v3348[8] = v3359;
  struct StateT * v3350 = slot_112(v3338);
  return v3350;
}

struct StateT * slot_109(struct StateT * v3290) {
  int v3291 = v3290->timer;
  int v3292 = v3290->timer;
  int v3304 = v3292 + 1;
  v3290->timer = v3304;
  int * v3294 = v3290->reg_ready;
  int v3295 = v3294[8];
  int * v3296 = v3290->regs;
  int v3297 = v3296[8];
  int * v3298 = v3290->reg_ready;
  int v3309 = (v3295 + ((v3291 - v3295) & (~((v3291 - v3295) >> 31)))) + 1;
  v3298[8] = v3309;
  int * v3300 = v3290->regs;
  int v3311 = v3297 + 1;
  v3300[8] = v3311;
  struct StateT * v3302 = slot_110(v3290);
  return v3302;
}

struct StateT * slot_174(struct StateT * v4850) {
  int v4851 = v4850->timer;
  int v4852 = v4850->timer;
  int v4864 = v4852 + 1;
  v4850->timer = v4864;
  int * v4854 = v4850->reg_ready;
  int v4855 = v4854[8];
  int * v4856 = v4850->regs;
  int v4857 = v4856[8];
  int * v4858 = v4850->reg_ready;
  int v4869 = (v4855 + ((v4851 - v4855) & (~((v4851 - v4855) >> 31)))) + 1;
  v4858[8] = v4869;
  int * v4860 = v4850->regs;
  int v4871 = v4857 + 1;
  v4860[8] = v4871;
  struct StateT * v4862 = slot_175(v4850);
  return v4862;
}

struct StateT * slot_147(struct StateT * v4202) {
  int v4203 = v4202->timer;
  int v4204 = v4202->timer;
  int v4216 = v4204 + 1;
  v4202->timer = v4216;
  int * v4206 = v4202->reg_ready;
  int v4207 = v4206[8];
  int * v4208 = v4202->regs;
  int v4209 = v4208[8];
  int * v4210 = v4202->reg_ready;
  int v4221 = (v4207 + ((v4203 - v4207) & (~((v4203 - v4207) >> 31)))) + 1;
  v4210[8] = v4221;
  int * v4212 = v4202->regs;
  int v4223 = v4209 + 1;
  v4212[8] = v4223;
  struct StateT * v4214 = slot_148(v4202);
  return v4214;
}

struct StateT * slot_42(struct StateT * v1682) {
  int v1683 = v1682->timer;
  int v1684 = v1682->timer;
  int v1696 = v1684 + 1;
  v1682->timer = v1696;
  int * v1686 = v1682->reg_ready;
  int v1687 = v1686[8];
  int * v1688 = v1682->regs;
  int v1689 = v1688[8];
  int * v1690 = v1682->reg_ready;
  int v1701 = (v1687 + ((v1683 - v1687) & (~((v1683 - v1687) >> 31)))) + 1;
  v1690[8] = v1701;
  int * v1692 = v1682->regs;
  int v1703 = v1689 + 1;
  v1692[8] = v1703;
  struct StateT * v1694 = slot_43(v1682);
  return v1694;
}

struct StateT * slot_224(struct StateT * v6050) {
  int v6051 = v6050->timer;
  int v6052 = v6050->timer;
  int v6064 = v6052 + 1;
  v6050->timer = v6064;
  int * v6054 = v6050->reg_ready;
  int v6055 = v6054[8];
  int * v6056 = v6050->regs;
  int v6057 = v6056[8];
  int * v6058 = v6050->reg_ready;
  int v6069 = (v6055 + ((v6051 - v6055) & (~((v6051 - v6055) >> 31)))) + 1;
  v6058[8] = v6069;
  int * v6060 = v6050->regs;
  int v6071 = v6057 + 1;
  v6060[8] = v6071;
  struct StateT * v6062 = slot_225(v6050);
  return v6062;
}

struct StateT * slot_163(struct StateT * v4586) {
  int v4587 = v4586->timer;
  int v4588 = v4586->timer;
  int v4600 = v4588 + 1;
  v4586->timer = v4600;
  int * v4590 = v4586->reg_ready;
  int v4591 = v4590[8];
  int * v4592 = v4586->regs;
  int v4593 = v4592[8];
  int * v4594 = v4586->reg_ready;
  int v4605 = (v4591 + ((v4587 - v4591) & (~((v4587 - v4591) >> 31)))) + 1;
  v4594[8] = v4605;
  int * v4596 = v4586->regs;
  int v4607 = v4593 + 1;
  v4596[8] = v4607;
  struct StateT * v4598 = slot_164(v4586);
  return v4598;
}

struct StateT * slot_184(struct StateT * v5090) {
  int v5091 = v5090->timer;
  int v5092 = v5090->timer;
  int v5104 = v5092 + 1;
  v5090->timer = v5104;
  int * v5094 = v5090->reg_ready;
  int v5095 = v5094[8];
  int * v5096 = v5090->regs;
  int v5097 = v5096[8];
  int * v5098 = v5090->reg_ready;
  int v5109 = (v5095 + ((v5091 - v5095) & (~((v5091 - v5095) >> 31)))) + 1;
  v5098[8] = v5109;
  int * v5100 = v5090->regs;
  int v5111 = v5097 + 1;
  v5100[8] = v5111;
  struct StateT * v5102 = slot_185(v5090);
  return v5102;
}

struct StateT * slot_204(struct StateT * v5570) {
  int v5571 = v5570->timer;
  int v5572 = v5570->timer;
  int v5584 = v5572 + 1;
  v5570->timer = v5584;
  int * v5574 = v5570->reg_ready;
  int v5575 = v5574[8];
  int * v5576 = v5570->regs;
  int v5577 = v5576[8];
  int * v5578 = v5570->reg_ready;
  int v5589 = (v5575 + ((v5571 - v5575) & (~((v5571 - v5575) >> 31)))) + 1;
  v5578[8] = v5589;
  int * v5580 = v5570->regs;
  int v5591 = v5577 + 1;
  v5580[8] = v5591;
  struct StateT * v5582 = slot_205(v5570);
  return v5582;
}

struct StateT * slot_194(struct StateT * v5330) {
  int v5331 = v5330->timer;
  int v5332 = v5330->timer;
  int v5344 = v5332 + 1;
  v5330->timer = v5344;
  int * v5334 = v5330->reg_ready;
  int v5335 = v5334[8];
  int * v5336 = v5330->regs;
  int v5337 = v5336[8];
  int * v5338 = v5330->reg_ready;
  int v5349 = (v5335 + ((v5331 - v5335) & (~((v5331 - v5335) >> 31)))) + 1;
  v5338[8] = v5349;
  int * v5340 = v5330->regs;
  int v5351 = v5337 + 1;
  v5340[8] = v5351;
  struct StateT * v5342 = slot_195(v5330);
  return v5342;
}

struct StateT * slot_165(struct StateT * v4634) {
  int v4635 = v4634->timer;
  int v4636 = v4634->timer;
  int v4648 = v4636 + 1;
  v4634->timer = v4648;
  int * v4638 = v4634->reg_ready;
  int v4639 = v4638[8];
  int * v4640 = v4634->regs;
  int v4641 = v4640[8];
  int * v4642 = v4634->reg_ready;
  int v4653 = (v4639 + ((v4635 - v4639) & (~((v4635 - v4639) >> 31)))) + 1;
  v4642[8] = v4653;
  int * v4644 = v4634->regs;
  int v4655 = v4641 + 1;
  v4644[8] = v4655;
  struct StateT * v4646 = slot_166(v4634);
  return v4646;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v6095 = v1->timer;
  int * v6096 = v1->reg_ready;
  int v6097 = v6096[0];
  int v6228 = v6097 + ((v6095 - v6097) & (~((v6095 - v6097) >> 31)));
  v1->timer = v6228;
  int v6099 = v1->timer;
  int * v6100 = v1->reg_ready;
  int v6101 = v6100[1];
  int v6231 = v6101 + ((v6099 - v6101) & (~((v6099 - v6101) >> 31)));
  v1->timer = v6231;
  int v6103 = v1->timer;
  int * v6104 = v1->reg_ready;
  int v6105 = v6104[2];
  int v6234 = v6105 + ((v6103 - v6105) & (~((v6103 - v6105) >> 31)));
  v1->timer = v6234;
  int v6107 = v1->timer;
  int * v6108 = v1->reg_ready;
  int v6109 = v6108[3];
  int v6237 = v6109 + ((v6107 - v6109) & (~((v6107 - v6109) >> 31)));
  v1->timer = v6237;
  int v6111 = v1->timer;
  int * v6112 = v1->reg_ready;
  int v6113 = v6112[4];
  int v6240 = v6113 + ((v6111 - v6113) & (~((v6111 - v6113) >> 31)));
  v1->timer = v6240;
  int v6115 = v1->timer;
  int * v6116 = v1->reg_ready;
  int v6117 = v6116[5];
  int v6243 = v6117 + ((v6115 - v6117) & (~((v6115 - v6117) >> 31)));
  v1->timer = v6243;
  int v6119 = v1->timer;
  int * v6120 = v1->reg_ready;
  int v6121 = v6120[6];
  int v6246 = v6121 + ((v6119 - v6121) & (~((v6119 - v6121) >> 31)));
  v1->timer = v6246;
  int v6123 = v1->timer;
  int * v6124 = v1->reg_ready;
  int v6125 = v6124[7];
  int v6249 = v6125 + ((v6123 - v6125) & (~((v6123 - v6125) >> 31)));
  v1->timer = v6249;
  int v6127 = v1->timer;
  int * v6128 = v1->reg_ready;
  int v6129 = v6128[8];
  int v6252 = v6129 + ((v6127 - v6129) & (~((v6127 - v6129) >> 31)));
  v1->timer = v6252;
  int v6131 = v1->timer;
  int * v6132 = v1->reg_ready;
  int v6133 = v6132[9];
  int v6255 = v6133 + ((v6131 - v6133) & (~((v6131 - v6133) >> 31)));
  v1->timer = v6255;
  int v6135 = v1->timer;
  int * v6136 = v1->reg_ready;
  int v6137 = v6136[10];
  int v6258 = v6137 + ((v6135 - v6137) & (~((v6135 - v6137) >> 31)));
  v1->timer = v6258;
  int v6139 = v1->timer;
  int * v6140 = v1->reg_ready;
  int v6141 = v6140[11];
  int v6261 = v6141 + ((v6139 - v6141) & (~((v6139 - v6141) >> 31)));
  v1->timer = v6261;
  int v6143 = v1->timer;
  int * v6144 = v1->reg_ready;
  int v6145 = v6144[12];
  int v6264 = v6145 + ((v6143 - v6145) & (~((v6143 - v6145) >> 31)));
  v1->timer = v6264;
  int v6147 = v1->timer;
  int * v6148 = v1->reg_ready;
  int v6149 = v6148[13];
  int v6267 = v6149 + ((v6147 - v6149) & (~((v6147 - v6149) >> 31)));
  v1->timer = v6267;
  int v6151 = v1->timer;
  int * v6152 = v1->reg_ready;
  int v6153 = v6152[14];
  int v6270 = v6153 + ((v6151 - v6153) & (~((v6151 - v6153) >> 31)));
  v1->timer = v6270;
  int v6155 = v1->timer;
  int * v6156 = v1->reg_ready;
  int v6157 = v6156[15];
  int v6273 = v6157 + ((v6155 - v6157) & (~((v6155 - v6157) >> 31)));
  v1->timer = v6273;
  int v6159 = v1->timer;
  int * v6160 = v1->reg_ready;
  int v6161 = v6160[16];
  int v6276 = v6161 + ((v6159 - v6161) & (~((v6159 - v6161) >> 31)));
  v1->timer = v6276;
  int v6163 = v1->timer;
  int * v6164 = v1->reg_ready;
  int v6165 = v6164[17];
  int v6279 = v6165 + ((v6163 - v6165) & (~((v6163 - v6165) >> 31)));
  v1->timer = v6279;
  int v6167 = v1->timer;
  int * v6168 = v1->reg_ready;
  int v6169 = v6168[18];
  int v6282 = v6169 + ((v6167 - v6169) & (~((v6167 - v6169) >> 31)));
  v1->timer = v6282;
  int v6171 = v1->timer;
  int * v6172 = v1->reg_ready;
  int v6173 = v6172[19];
  int v6285 = v6173 + ((v6171 - v6173) & (~((v6171 - v6173) >> 31)));
  v1->timer = v6285;
  int v6175 = v1->timer;
  int * v6176 = v1->reg_ready;
  int v6177 = v6176[20];
  int v6288 = v6177 + ((v6175 - v6177) & (~((v6175 - v6177) >> 31)));
  v1->timer = v6288;
  int v6179 = v1->timer;
  int * v6180 = v1->reg_ready;
  int v6181 = v6180[21];
  int v6291 = v6181 + ((v6179 - v6181) & (~((v6179 - v6181) >> 31)));
  v1->timer = v6291;
  int v6183 = v1->timer;
  int * v6184 = v1->reg_ready;
  int v6185 = v6184[22];
  int v6294 = v6185 + ((v6183 - v6185) & (~((v6183 - v6185) >> 31)));
  v1->timer = v6294;
  int v6187 = v1->timer;
  int * v6188 = v1->reg_ready;
  int v6189 = v6188[23];
  int v6297 = v6189 + ((v6187 - v6189) & (~((v6187 - v6189) >> 31)));
  v1->timer = v6297;
  int v6191 = v1->timer;
  int * v6192 = v1->reg_ready;
  int v6193 = v6192[24];
  int v6300 = v6193 + ((v6191 - v6193) & (~((v6191 - v6193) >> 31)));
  v1->timer = v6300;
  int v6195 = v1->timer;
  int * v6196 = v1->reg_ready;
  int v6197 = v6196[25];
  int v6303 = v6197 + ((v6195 - v6197) & (~((v6195 - v6197) >> 31)));
  v1->timer = v6303;
  int v6199 = v1->timer;
  int * v6200 = v1->reg_ready;
  int v6201 = v6200[26];
  int v6306 = v6201 + ((v6199 - v6201) & (~((v6199 - v6201) >> 31)));
  v1->timer = v6306;
  int v6203 = v1->timer;
  int * v6204 = v1->reg_ready;
  int v6205 = v6204[27];
  int v6309 = v6205 + ((v6203 - v6205) & (~((v6203 - v6205) >> 31)));
  v1->timer = v6309;
  int v6207 = v1->timer;
  int * v6208 = v1->reg_ready;
  int v6209 = v6208[28];
  int v6312 = v6209 + ((v6207 - v6209) & (~((v6207 - v6209) >> 31)));
  v1->timer = v6312;
  int v6211 = v1->timer;
  int * v6212 = v1->reg_ready;
  int v6213 = v6212[29];
  int v6315 = v6213 + ((v6211 - v6213) & (~((v6211 - v6213) >> 31)));
  v1->timer = v6315;
  int v6215 = v1->timer;
  int * v6216 = v1->reg_ready;
  int v6217 = v6216[30];
  int v6318 = v6217 + ((v6215 - v6217) & (~((v6215 - v6217) >> 31)));
  v1->timer = v6318;
  int v6219 = v1->timer;
  int * v6220 = v1->reg_ready;
  int v6221 = v6220[31];
  int v6321 = v6221 + ((v6219 - v6221) & (~((v6219 - v6221) >> 31)));
  v1->timer = v6321;
  return v1;
}

struct StateT * slot_117(struct StateT * v3482) {
  int v3483 = v3482->timer;
  int v3484 = v3482->timer;
  int v3496 = v3484 + 1;
  v3482->timer = v3496;
  int * v3486 = v3482->reg_ready;
  int v3487 = v3486[8];
  int * v3488 = v3482->regs;
  int v3489 = v3488[8];
  int * v3490 = v3482->reg_ready;
  int v3501 = (v3487 + ((v3483 - v3487) & (~((v3483 - v3487) >> 31)))) + 1;
  v3490[8] = v3501;
  int * v3492 = v3482->regs;
  int v3503 = v3489 + 1;
  v3492[8] = v3503;
  struct StateT * v3494 = slot_118(v3482);
  return v3494;
}

struct StateT * slot_90(struct StateT * v2834) {
  int v2835 = v2834->timer;
  int v2836 = v2834->timer;
  int v2848 = v2836 + 1;
  v2834->timer = v2848;
  int * v2838 = v2834->reg_ready;
  int v2839 = v2838[8];
  int * v2840 = v2834->regs;
  int v2841 = v2840[8];
  int * v2842 = v2834->reg_ready;
  int v2853 = (v2839 + ((v2835 - v2839) & (~((v2835 - v2839) >> 31)))) + 1;
  v2842[8] = v2853;
  int * v2844 = v2834->regs;
  int v2855 = v2841 + 1;
  v2844[8] = v2855;
  struct StateT * v2846 = slot_91(v2834);
  return v2846;
}

struct StateT * slot_11(struct StateT * v938) {
  int v939 = v938->timer;
  int v940 = v938->timer;
  int v952 = v940 + 1;
  v938->timer = v952;
  int * v942 = v938->reg_ready;
  int v943 = v942[8];
  int * v944 = v938->regs;
  int v945 = v944[8];
  int * v946 = v938->reg_ready;
  int v957 = (v943 + ((v939 - v943) & (~((v939 - v943) >> 31)))) + 1;
  v946[8] = v957;
  int * v948 = v938->regs;
  int v959 = v945 + 1;
  v948[8] = v959;
  struct StateT * v950 = slot_12(v938);
  return v950;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
    s->reg_ready[i] = 0;
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