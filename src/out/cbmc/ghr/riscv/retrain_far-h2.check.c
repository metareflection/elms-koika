// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 513]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 512
#define HISTORY_BITS 2

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#define koika_secret(x) ((void)0)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[512];
  int timer;
};

void ret_assert(bool);

struct StateG * slot_12(struct StateG * v417);
struct StateG * slot_228(struct StateG * v4802);
struct StateG * slot_143(struct StateG * v3086);
struct StateG * slot_120(struct StateG * v2540);
struct StateG * slot_226(struct StateG * v4762);
struct StateG * slot_167(struct StateG * v3666);
struct StateG * slot_268(struct StateG * v5574);
struct StateG * slot_152(struct StateG * v3226);
struct StateG * slot_231(struct StateG * v4862);
struct StateG * slot_199(struct StateG * v4362);
struct StateG * slot_252(struct StateG * v5338);
struct StateG * slot_92(struct StateG * v1924);
struct StateG * slot_232(struct StateG * v4882);
struct StateG * slot_269(struct StateG * v5594);
struct StateG * slot_31(struct StateG * v784);
struct StateG * slot_236(struct StateG * v5042);
struct StateG * slot_241(struct StateG * v5206);
struct StateG * slot_160(struct StateG * v3386);
struct StateG * slot_251(struct StateG * v5324);
struct StateG * slot_65(struct StateG * v1348);
struct StateG * slot_10(struct StateG * v396);
struct StateG * slot_150(struct StateG * v3186);
struct StateG * slot_74(struct StateG * v1649);
struct StateG * slot_262(struct StateG * v5468);
struct StateG * slot_277(struct StateG * v5774);
struct StateG * slot_107(struct StateG * v2358);
struct StateG * slot_136(struct StateG * v3010);
struct StateG * slot_84(struct StateG * v1764);
struct StateG * slot_295(struct StateG * v6180);
struct StateG * slot_28(struct StateG * v664);
struct StateG * slot_155(struct StateG * v3286);
struct StateG * slot_177(struct StateG * v3803);
struct StateG * slot_229(struct StateG * v4822);
struct StateG * slot_17(struct StateG * v479);
struct StateG * slot_181(struct StateG * v3862);
struct StateG * slot_197(struct StateG * v4282);
struct StateG * slot_207(struct StateG * v4478);
struct StateG * slot_156(struct StateG * v3306);
struct StateG * slot_154(struct StateG * v3266);
struct StateG * slot_68(struct StateG * v1468);
struct StateG * slot_260(struct StateG * v5442);
struct StateG * slot_105(struct StateG * v2332);
struct StateG * slot_27(struct StateG * v644);
struct StateG * slot_164(struct StateG * v3546);
struct StateG * slot_15(struct StateG * v452);
struct StateG * slot_133(struct StateG * v2896);
struct StateG * slot_56(struct StateG * v1148);
struct StateG * slot_244(struct StateG * v5240);
struct StateG * slot_222(struct StateG * v4682);
struct StateG * slot_34(struct StateG * v845);
struct StateG * slot_171(struct StateG * v3740);
struct StateG * slot_162(struct StateG * v3466);
struct StateG * slot_21(struct StateG * v531);
struct StateG * slot_239(struct StateG * v5159);
struct StateG * slot_118(struct StateG * v2500);
struct StateG * slot_121(struct StateG * v2560);
struct StateG * slot_144(struct StateG * v3094);
struct StateG * slot_267(struct StateG * v5554);
struct StateG * slot_201(struct StateG * v4410);
struct StateG * slot_94(struct StateG * v1964);
struct StateG * slot_63(struct StateG * v1288);
struct StateG * slot_146(struct StateG * v3120);
struct StateG * slot_24(struct StateG * v584);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_286(struct StateG * v6075);
struct StateG * slot_195(struct StateG * v4202);
struct StateG * slot_125(struct StateG * v2640);
struct StateG * slot_254(struct StateG * v5364);
struct StateG * slot_148(struct StateG * v3146);
struct StateG * slot_126(struct StateG * v2660);
struct StateG * slot_223(struct StateG * v4702);
struct StateG * slot_79(struct StateG * v1704);
struct StateG * slot_237(struct StateG * v5081);
struct StateG * slot_41(struct StateG * v922);
struct StateG * slot_39(struct StateG * v900);
struct StateG * slot_142(struct StateG * v3073);
struct StateG * slot_60(struct StateG * v1228);
struct StateG * slot_289(struct StateG * v6104);
struct StateG * slot_238(struct StateG * v5120);
struct StateG * slot_112(struct StateG * v2408);
struct StateG * slot_256(struct StateG * v5390);
struct StateG * slot_280(struct StateG * v5894);
struct StateG * slot_272(struct StateG * v5654);
struct StateG * slot_47(struct StateG * v1003);
struct StateG * slot_214(struct StateG * v4564);
struct StateG * slot_297(struct StateG * v6199);
struct StateG * slot_29(struct StateG * v704);
struct StateG * slot_16(struct StateG * v466);
struct StateG * slot_245(struct StateG * v5248);
struct StateG * slot_113(struct StateG * v2421);
struct StateG * slot_151(struct StateG * v3206);
struct StateG * slot_7(struct StateG * v298);
struct StateG * slot_124(struct StateG * v2620);
struct StateG * slot_191(struct StateG * v4062);
struct StateG * slot_103(struct StateG * v2284);
struct StateG * slot_128(struct StateG * v2700);
struct StateG * slot_19(struct StateG * v505);
struct StateG * slot_87(struct StateG * v1824);
struct StateG * slot_67(struct StateG * v1428);
struct StateG * slot_81(struct StateG * v1725);
struct StateG * slot_95(struct StateG * v1984);
struct StateG * slot_115(struct StateG * v2447);
struct StateG * slot_78(struct StateG * v1691);
struct StateG * slot_32(struct StateG * v824);
struct StateG * slot_205(struct StateG * v4452);
struct StateG * slot_193(struct StateG * v4122);
struct StateG * slot_233(struct StateG * v4922);
struct StateG * slot_176(struct StateG * v3790);
struct StateG * slot_189(struct StateG * v4022);
struct StateG * slot_33(struct StateG * v832);
struct StateG * slot_35(struct StateG * v858);
struct StateG * slot_258(struct StateG * v5416);
struct StateG * slot_246(struct StateG * v5261);
struct StateG * slot_210(struct StateG * v4512);
struct StateG * slot_284(struct StateG * v6054);
struct StateG * slot_166(struct StateG * v3626);
struct StateG * slot_51(struct StateG * v1055);
struct StateG * slot_52(struct StateG * v1068);
struct StateG * slot_83(struct StateG * v1751);
struct StateG * slot_25(struct StateG * v604);
struct StateG * slot_209(struct StateG * v4499);
struct StateG * slot_3(struct StateG * v232);
struct StateG * slot_264(struct StateG * v5494);
struct StateG * slot_123(struct StateG * v2600);
struct StateG * slot_73(struct StateG * v1636);
struct StateG * slot_270(struct StateG * v5614);
struct StateG * slot_198(struct StateG * v4322);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_187(struct StateG * v3982);
struct StateG * slot_97(struct StateG * v2044);
struct StateG * slot_182(struct StateG * v3882);
struct StateG * slot_38(struct StateG * v887);
struct StateG * slot_178(struct StateG * v3816);
struct StateG * slot_106(struct StateG * v2345);
struct StateG * slot_98(struct StateG * v2084);
struct StateG * slot_159(struct StateG * v3366);
struct StateG * slot_46(struct StateG * v990);
struct StateG * slot_212(struct StateG * v4538);
struct StateG * slot_132(struct StateG * v2858);
struct StateG * slot_130(struct StateG * v2780);
struct StateG * slot_211(struct StateG * v4525);
struct StateG * slot_20(struct StateG * v518);
struct StateG * slot_141(struct StateG * v3060);
struct StateG * slot_61(struct StateG * v1248);
struct StateG * slot_30(struct StateG * v744);
struct StateG * slot_4(struct StateG * v245);
struct StateG * slot_18(struct StateG * v492);
struct StateG * slot_9(struct StateG * v357);
struct StateG * slot_183(struct StateG * v3902);
struct StateG * slot_240(struct StateG * v5198);
struct StateG * slot_282(struct StateG * v5974);
struct StateG * slot_247(struct StateG * v5274);
struct StateG * slot_43(struct StateG * v950);
struct StateG * slot_70(struct StateG * v1548);
struct StateG * slot_168(struct StateG * v3706);
struct StateG * slot_76(struct StateG * v1670);
struct StateG * slot_6(struct StateG * v278);
struct StateG * slot_225(struct StateG * v4742);
struct StateG * slot_55(struct StateG * v1128);
struct StateG * slot_283(struct StateG * v6014);
struct StateG * slot_213(struct StateG * v4551);
struct StateG * slot_82(struct StateG * v1738);
struct StateG * slot_274(struct StateG * v5694);
struct StateG * slot_263(struct StateG * v5481);
struct StateG * slot_161(struct StateG * v3426);
struct StateG * slot_185(struct StateG * v3942);
struct StateG * slot_91(struct StateG * v1904);
struct StateG * slot_58(struct StateG * v1188);
struct StateG * slot_89(struct StateG * v1864);
struct StateG * slot_255(struct StateG * v5377);
struct StateG * slot_66(struct StateG * v1388);
struct StateG * slot_140(struct StateG * v3052);
struct StateG * slot_265(struct StateG * v5514);
struct StateG * slot_49(struct StateG * v1029);
struct StateG * slot_216(struct StateG * v4590);
struct StateG * slot_50(struct StateG * v1042);
struct StateG * slot_37(struct StateG * v874);
struct StateG * slot_114(struct StateG * v2434);
struct StateG * slot_135(struct StateG * v2972);
struct StateG * slot_248(struct StateG * v5282);
struct StateG * slot_257(struct StateG * v5403);
struct StateG * slot_59(struct StateG * v1208);
struct StateG * slot_192(struct StateG * v4082);
struct StateG * slot_40(struct StateG * v908);
struct StateG * slot_48(struct StateG * v1016);
struct StateG * slot_77(struct StateG * v1678);
struct StateG * slot_85(struct StateG * v1784);
struct StateG * slot_75(struct StateG * v1662);
struct StateG * slot_72(struct StateG * v1628);
struct StateG * slot_119(struct StateG * v2520);
struct StateG * slot_71(struct StateG * v1588);
struct StateG * slot_101(struct StateG * v2204);
struct StateG * slot_276(struct StateG * v5734);
struct StateG * slot_108(struct StateG * v2366);
struct StateG * slot_116(struct StateG * v2460);
struct StateG * slot_93(struct StateG * v1944);
struct StateG * slot_266(struct StateG * v5534);
struct StateG * slot_88(struct StateG * v1844);
struct StateG * slot_96(struct StateG * v2004);
struct StateG * slot_215(struct StateG * v4577);
struct StateG * slot_234(struct StateG * v4962);
struct StateG * slot_45(struct StateG * v977);
struct StateG * slot_218(struct StateG * v4616);
struct StateG * slot_220(struct StateG * v4642);
struct StateG * slot_134(struct StateG * v2934);
struct StateG * slot_175(struct StateG * v3782);
struct StateG * slot_273(struct StateG * v5674);
struct StateG * slot_69(struct StateG * v1508);
struct StateG * slot_202(struct StateG * v4423);
struct StateG * slot_230(struct StateG * v4842);
struct StateG * slot_188(struct StateG * v4002);
struct StateG * slot_138(struct StateG * v3031);
struct StateG * slot_186(struct StateG * v3962);
struct StateG * slot_102(struct StateG * v2244);
struct StateG * slot_145(struct StateG * v3107);
struct StateG * slot_110(struct StateG * v2387);
struct StateG * slot_196(struct StateG * v4242);
struct StateG * slot_208(struct StateG * v4486);
struct StateG * slot_172(struct StateG * v3748);
struct StateG * slot_131(struct StateG * v2819);
struct StateG * slot_8(struct StateG * v318);
struct StateG * slot_180(struct StateG * v3842);
struct StateG * slot_281(struct StateG * v5934);
struct StateG * slot_203(struct StateG * v4436);
struct StateG * slot_190(struct StateG * v4042);
struct StateG * slot_157(struct StateG * v3326);
struct StateG * slot_242(struct StateG * v5219);
struct StateG * slot_200(struct StateG * v4402);
struct StateG * slot_243(struct StateG * v5232);
struct StateG * slot_173(struct StateG * v3756);
struct StateG * slot_149(struct StateG * v3166);
struct StateG * slot_5(struct StateG * v258);
struct StateG * slot_104(struct StateG * v2324);
struct StateG * slot_235(struct StateG * v5002);
struct StateG * slot_275(struct StateG * v5714);
struct StateG * slot_54(struct StateG * v1108);
struct StateG * slot_26(struct StateG * v624);
struct StateG * slot_206(struct StateG * v4465);
struct StateG * slot_227(struct StateG * v4782);
struct StateG * slot_169(struct StateG * v3714);
struct StateG * slot_253(struct StateG * v5351);
struct StateG * slot_64(struct StateG * v1308);
struct StateG * slot_170(struct StateG * v3727);
struct StateG * slot_14(struct StateG * v438);
struct StateG * slot_53(struct StateG * v1088);
struct StateG * slot_80(struct StateG * v1712);
struct StateG * slot_44(struct StateG * v964);
struct StateG * slot_261(struct StateG * v5455);
struct StateG * slot_137(struct StateG * v3018);
struct StateG * slot_122(struct StateG * v2580);
struct StateG * slot_99(struct StateG * v2124);
struct StateG * slot_179(struct StateG * v3829);
struct StateG * slot_219(struct StateG * v4629);
struct StateG * slot_36(struct StateG * v866);
struct StateG * slot_57(struct StateG * v1168);
struct StateG * slot_62(struct StateG * v1268);
struct StateG * slot_22(struct StateG * v544);
struct StateG * slot_139(struct StateG * v3044);
struct StateG * slot_221(struct StateG * v4662);
struct StateG * slot_23(struct StateG * v564);
struct StateG * slot_153(struct StateG * v3246);
struct StateG * slot_2(struct StateG * v219);
struct StateG * slot_86(struct StateG * v1804);
struct StateG * slot_129(struct StateG * v2740);
struct StateG * slot_158(struct StateG * v3346);
struct StateG * slot_279(struct StateG * v5854);
struct StateG * slot_100(struct StateG * v2164);
struct StateG * slot_271(struct StateG * v5634);
struct StateG * slot_127(struct StateG * v2680);
struct StateG * slot_217(struct StateG * v4603);
struct StateG * slot_13(struct StateG * v430);
struct StateG * slot_111(struct StateG * v2400);
struct StateG * slot_109(struct StateG * v2374);
struct StateG * slot_174(struct StateG * v3769);
struct StateG * slot_147(struct StateG * v3133);
struct StateG * slot_42(struct StateG * v936);
struct StateG * slot_224(struct StateG * v4722);
struct StateG * slot_163(struct StateG * v3506);
struct StateG * slot_184(struct StateG * v3922);
struct StateG * slot_204(struct StateG * v4444);
struct StateG * slot_194(struct StateG * v4162);
struct StateG * slot_165(struct StateG * v3586);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_278(struct StateG * v5814);
struct StateG * slot_250(struct StateG * v5310);
struct StateG * slot_259(struct StateG * v5429);
struct StateG * slot_117(struct StateG * v2480);
struct StateG * slot_249(struct StateG * v5296);
struct StateG * slot_90(struct StateG * v1884);
struct StateG * slot_11(struct StateG * v404);
struct StateG * slot_12(struct StateG * v417) {
  int v418 = v417->timer;
  int v424 = v418 + 1;
  v417->timer = v424;
  int * v420 = v417->regs;
  v420[18] = 2;
  struct StateG * v422 = slot_10(v417);
  return v422;
}

struct StateG * slot_228(struct StateG * v4802) {
  int * v4803 = v4802->saved_regs;
  int * v4804 = v4802->regs;
  int v4805 = v4804[18];
  v4803[18] = v4805;
  int v4807 = v4802->timer;
  int v4817 = v4807 + 1;
  v4802->timer = v4817;
  int * v4809 = v4802->regs;
  v4809[18] = 2;
  struct StateG * v4811 = slot_236(v4802);
  return v4811;
}

struct StateG * slot_143(struct StateG * v3086) {
  int v3087 = v3086->timer;
  int v3091 = v3087 + 1;
  v3086->timer = v3091;
  struct StateG * v3089 = slot_147(v3086);
  return v3089;
}

struct StateG * slot_120(struct StateG * v2540) {
  int * v2541 = v2540->saved_regs;
  int * v2542 = v2540->regs;
  int v2543 = v2542[18];
  v2541[18] = v2543;
  int v2545 = v2540->timer;
  int v2555 = v2545 + 1;
  v2540->timer = v2555;
  int * v2547 = v2540->regs;
  v2547[18] = 2;
  struct StateG * v2549 = slot_128(v2540);
  return v2549;
}

struct StateG * slot_226(struct StateG * v4762) {
  int * v4763 = v4762->saved_regs;
  int * v4764 = v4762->regs;
  int v4765 = v4764[18];
  v4763[18] = v4765;
  int v4767 = v4762->timer;
  int v4777 = v4767 + 1;
  v4762->timer = v4777;
  int * v4769 = v4762->regs;
  v4769[18] = 2;
  struct StateG * v4771 = slot_234(v4762);
  return v4771;
}

struct StateG * slot_167(struct StateG * v3666) {
  int * v3667 = v3666->regs;
  int v3668 = v3667[16];
  int v3669 = v3667[17];
  bool v3689 = v3668 < v3669;
  struct StateG * v3684;
  if (v3689) {
    int * v3670 = v3666->pht;
    v3670[20] = 1;
    int v3672 = v3666->timer;
    int v3693 = v3672 + 15;
    v3666->timer = v3693;
    int * v3674 = v3666->saved_regs;
    int v3675 = v3674[18];
    int * v3676 = v3666->regs;
    v3676[18] = v3675;
    struct StateG * v3678 = slot_174(v3666);
    v3684 = v3678;
  } else {
    int * v3680 = v3666->pht;
    v3680[20] = 0;
    struct StateG * v3682 = slot_175(v3666);
    v3684 = v3682;
  }
  return v3684;
}

struct StateG * slot_268(struct StateG * v5574) {
  int * v5575 = v5574->saved_regs;
  int * v5576 = v5574->regs;
  int v5577 = v5576[19];
  v5575[19] = v5577;
  int v5579 = v5574->timer;
  int v5589 = v5579 + 1;
  v5574->timer = v5589;
  int * v5581 = v5574->regs;
  v5581[19] = 2;
  struct StateG * v5583 = slot_276(v5574);
  return v5583;
}

struct StateG * slot_152(struct StateG * v3226) {
  int * v3227 = v3226->saved_regs;
  int * v3228 = v3226->regs;
  int v3229 = v3228[18];
  v3227[18] = v3229;
  int v3231 = v3226->timer;
  int v3241 = v3231 + 1;
  v3226->timer = v3241;
  int * v3233 = v3226->regs;
  v3233[18] = 2;
  struct StateG * v3235 = slot_160(v3226);
  return v3235;
}

struct StateG * slot_231(struct StateG * v4862) {
  int * v4863 = v4862->saved_regs;
  int * v4864 = v4862->regs;
  int v4865 = v4864[18];
  v4863[18] = v4865;
  int v4867 = v4862->timer;
  int v4877 = v4867 + 1;
  v4862->timer = v4877;
  int * v4869 = v4862->regs;
  v4869[18] = 1;
  struct StateG * v4871 = slot_239(v4862);
  return v4871;
}

struct StateG * slot_199(struct StateG * v4362) {
  int * v4363 = v4362->regs;
  int v4364 = v4363[16];
  int v4365 = v4363[17];
  bool v4385 = v4364 < v4365;
  struct StateG * v4380;
  if (v4385) {
    int * v4366 = v4362->pht;
    v4366[24] = 1;
    int v4368 = v4362->timer;
    int v4389 = v4368 + 15;
    v4362->timer = v4389;
    int * v4370 = v4362->saved_regs;
    int v4371 = v4370[18];
    int * v4372 = v4362->regs;
    v4372[18] = v4371;
    struct StateG * v4374 = slot_206(v4362);
    v4380 = v4374;
  } else {
    int * v4376 = v4362->pht;
    v4376[24] = 0;
    struct StateG * v4378 = slot_207(v4362);
    v4380 = v4378;
  }
  return v4380;
}

struct StateG * slot_252(struct StateG * v5338) {
  int v5339 = v5338->timer;
  int v5345 = v5339 + 1;
  v5338->timer = v5345;
  int * v5341 = v5338->regs;
  v5341[1] = 156;
  struct StateG * v5343 = slot_256(v5338);
  return v5343;
}

struct StateG * slot_92(struct StateG * v1924) {
  int * v1925 = v1924->saved_regs;
  int * v1926 = v1924->regs;
  int v1927 = v1926[18];
  v1925[18] = v1927;
  int v1929 = v1924->timer;
  int v1939 = v1929 + 1;
  v1924->timer = v1939;
  int * v1931 = v1924->regs;
  v1931[18] = 2;
  struct StateG * v1933 = slot_100(v1924);
  return v1933;
}

struct StateG * slot_232(struct StateG * v4882) {
  int * v4883 = v4882->regs;
  int v4884 = v4883[16];
  int v4885 = v4883[17];
  bool v4905 = v4884 < v4885;
  struct StateG * v4900;
  if (v4905) {
    int * v4886 = v4882->pht;
    v4886[3] = 1;
    struct StateG * v4888 = slot_240(v4882);
    v4900 = v4888;
  } else {
    int * v4890 = v4882->pht;
    v4890[3] = 0;
    int v4892 = v4882->timer;
    int v4914 = v4892 + 15;
    v4882->timer = v4914;
    int * v4894 = v4882->saved_regs;
    int v4895 = v4894[18];
    int * v4896 = v4882->regs;
    v4896[18] = v4895;
    struct StateG * v4898 = slot_241(v4882);
    v4900 = v4898;
  }
  return v4900;
}

struct StateG * slot_269(struct StateG * v5594) {
  int * v5595 = v5594->saved_regs;
  int * v5596 = v5594->regs;
  int v5597 = v5596[19];
  v5595[19] = v5597;
  int v5599 = v5594->timer;
  int v5609 = v5599 + 1;
  v5594->timer = v5609;
  int * v5601 = v5594->regs;
  v5601[19] = 1;
  struct StateG * v5603 = slot_277(v5594);
  return v5603;
}

struct StateG * slot_31(struct StateG * v784) {
  int * v785 = v784->regs;
  int v786 = v785[16];
  int v787 = v785[17];
  bool v807 = v786 >= v787;
  struct StateG * v802;
  if (v807) {
    int * v788 = v784->pht;
    v788[4] = 1;
    int v790 = v784->timer;
    int v811 = v790 + 15;
    v784->timer = v811;
    int * v792 = v784->saved_regs;
    int v793 = v792[19];
    int * v794 = v784->regs;
    v794[19] = v793;
    struct StateG * v796 = slot_38(v784);
    v802 = v796;
  } else {
    int * v798 = v784->pht;
    v798[4] = 0;
    struct StateG * v800 = slot_39(v784);
    v802 = v800;
  }
  return v802;
}

struct StateG * slot_236(struct StateG * v5042) {
  int * v5043 = v5042->regs;
  int v5044 = v5043[16];
  int v5045 = v5043[17];
  bool v5065 = v5044 < v5045;
  struct StateG * v5060;
  if (v5065) {
    int * v5046 = v5042->pht;
    v5046[1] = 1;
    struct StateG * v5048 = slot_240(v5042);
    v5060 = v5048;
  } else {
    int * v5050 = v5042->pht;
    v5050[1] = 0;
    int v5052 = v5042->timer;
    int v5073 = v5052 + 15;
    v5042->timer = v5073;
    int * v5054 = v5042->saved_regs;
    int v5055 = v5054[18];
    int * v5056 = v5042->regs;
    v5056[18] = v5055;
    struct StateG * v5058 = slot_241(v5042);
    v5060 = v5058;
  }
  return v5060;
}

struct StateG * slot_241(struct StateG * v5206) {
  int v5207 = v5206->timer;
  int v5213 = v5207 + 1;
  v5206->timer = v5213;
  int * v5209 = v5206->regs;
  v5209[18] = 1;
  struct StateG * v5211 = slot_243(v5206);
  return v5211;
}

struct StateG * slot_160(struct StateG * v3386) {
  int * v3387 = v3386->regs;
  int v3388 = v3387[16];
  int v3389 = v3387[17];
  bool v3409 = v3388 < v3389;
  struct StateG * v3404;
  if (v3409) {
    int * v3390 = v3386->pht;
    v3390[23] = 1;
    struct StateG * v3392 = slot_168(v3386);
    v3404 = v3392;
  } else {
    int * v3394 = v3386->pht;
    v3394[23] = 0;
    int v3396 = v3386->timer;
    int v3418 = v3396 + 15;
    v3386->timer = v3418;
    int * v3398 = v3386->saved_regs;
    int v3399 = v3398[18];
    int * v3400 = v3386->regs;
    v3400[18] = v3399;
    struct StateG * v3402 = slot_169(v3386);
    v3404 = v3402;
  }
  return v3404;
}

struct StateG * slot_251(struct StateG * v5324) {
  int v5325 = v5324->timer;
  int v5332 = v5325 + 1;
  v5324->timer = v5332;
  int * v5327 = v5324->regs;
  int v5328 = v5327[1];
  bool v5335 = v5328 == 156;
  ret_assert(v5335);
  struct StateG * v5330 = slot_255(v5324);
  return v5330;
}

struct StateG * slot_65(struct StateG * v1348) {
  int * v1349 = v1348->regs;
  int v1350 = v1349[16];
  int v1351 = v1349[17];
  bool v1371 = v1350 < v1351;
  struct StateG * v1366;
  if (v1371) {
    int * v1352 = v1348->pht;
    v1352[11] = 1;
    int v1354 = v1348->timer;
    int v1375 = v1354 + 15;
    v1348->timer = v1375;
    int * v1356 = v1348->saved_regs;
    int v1357 = v1356[18];
    int * v1358 = v1348->regs;
    v1358[18] = v1357;
    struct StateG * v1360 = slot_74(v1348);
    v1366 = v1360;
  } else {
    int * v1362 = v1348->pht;
    v1362[11] = 0;
    struct StateG * v1364 = slot_75(v1348);
    v1366 = v1364;
  }
  return v1366;
}

struct StateG * slot_10(struct StateG * v396) {
  int v397 = v396->timer;
  int v401 = v397 + 1;
  v396->timer = v401;
  struct StateG * v399 = slot_14(v396);
  return v399;
}

struct StateG * slot_150(struct StateG * v3186) {
  int v3187 = v3186->timer;
  int v3197 = v3187 + 1;
  v3186->timer = v3197;
  int * v3189 = v3186->pht;
  int v3190 = v3189[21];
  bool v3200 = !(v3190 == 0);
  struct StateG * v3195;
  if (v3200) {
    struct StateG * v3191 = slot_156(v3186);
    v3195 = v3191;
  } else {
    struct StateG * v3193 = slot_157(v3186);
    v3195 = v3193;
  }
  return v3195;
}

struct StateG * slot_74(struct StateG * v1649) {
  int v1650 = v1649->timer;
  int v1656 = v1650 + 1;
  v1649->timer = v1656;
  int * v1652 = v1649->regs;
  v1652[18] = 2;
  struct StateG * v1654 = slot_72(v1649);
  return v1654;
}

struct StateG * slot_262(struct StateG * v5468) {
  int v5469 = v5468->timer;
  int v5475 = v5469 + 1;
  v5468->timer = v5475;
  int * v5471 = v5468->regs;
  v5471[17] = 10;
  struct StateG * v5473 = slot_266(v5468);
  return v5473;
}

struct StateG * slot_277(struct StateG * v5774) {
  int * v5775 = v5774->regs;
  int v5776 = v5775[16];
  int v5777 = v5775[17];
  bool v5797 = v5776 >= v5777;
  struct StateG * v5792;
  if (v5797) {
    int * v5778 = v5774->pht;
    v5778[7] = 1;
    int v5780 = v5774->timer;
    int v5801 = v5780 + 15;
    v5774->timer = v5801;
    int * v5782 = v5774->saved_regs;
    int v5783 = v5782[19];
    int * v5784 = v5774->regs;
    v5784[19] = v5783;
    struct StateG * v5786 = slot_286(v5774);
    v5792 = v5786;
  } else {
    int * v5788 = v5774->pht;
    v5788[7] = 0;
    struct StateG * v5790 = slot_284(v5774);
    v5792 = v5790;
  }
  return v5792;
}

struct StateG * slot_107(struct StateG * v2358) {
  int v2359 = v2358->timer;
  int v2363 = v2359 + 1;
  v2358->timer = v2363;
  struct StateG * v2361 = slot_113(v2358);
  return v2361;
}

struct StateG * slot_136(struct StateG * v3010) {
  int v3011 = v3010->timer;
  int v3015 = v3011 + 1;
  v3010->timer = v3015;
  struct StateG * v3013 = slot_144(v3010);
  return v3013;
}

struct StateG * slot_84(struct StateG * v1764) {
  int v1765 = v1764->timer;
  int v1775 = v1765 + 1;
  v1764->timer = v1775;
  int * v1767 = v1764->pht;
  int v1768 = v1767[15];
  bool v1778 = !(v1768 == 0);
  struct StateG * v1773;
  if (v1778) {
    struct StateG * v1769 = slot_88(v1764);
    v1773 = v1769;
  } else {
    struct StateG * v1771 = slot_89(v1764);
    v1773 = v1771;
  }
  return v1773;
}

struct StateG * slot_295(struct StateG * v6180) {
  int v6181 = v6180->timer;
  int v6188 = v6181 + 1;
  v6180->timer = v6188;
  int * v6183 = v6180->regs;
  int v6184 = v6183[1];
  bool v6191 = v6184 == 164;
  ret_assert(v6191);
  struct StateG * v6186 = slot_297(v6180);
  return v6186;
}

struct StateG * slot_28(struct StateG * v664) {
  int * v665 = v664->regs;
  int v666 = v665[16];
  int v667 = v665[17];
  bool v687 = v666 >= v667;
  struct StateG * v682;
  if (v687) {
    int * v668 = v664->pht;
    v668[5] = 1;
    struct StateG * v670 = slot_32(v664);
    v682 = v670;
  } else {
    int * v672 = v664->pht;
    v672[5] = 0;
    int v674 = v664->timer;
    int v696 = v674 + 15;
    v664->timer = v696;
    int * v676 = v664->saved_regs;
    int v677 = v676[19];
    int * v678 = v664->regs;
    v678[19] = v677;
    struct StateG * v680 = slot_33(v664);
    v682 = v680;
  }
  return v682;
}

struct StateG * slot_155(struct StateG * v3286) {
  int * v3287 = v3286->saved_regs;
  int * v3288 = v3286->regs;
  int v3289 = v3288[18];
  v3287[18] = v3289;
  int v3291 = v3286->timer;
  int v3301 = v3291 + 1;
  v3286->timer = v3301;
  int * v3293 = v3286->regs;
  v3293[18] = 1;
  struct StateG * v3295 = slot_163(v3286);
  return v3295;
}

struct StateG * slot_177(struct StateG * v3803) {
  int v3804 = v3803->timer;
  int v3810 = v3804 + 1;
  v3803->timer = v3810;
  int * v3806 = v3803->regs;
  v3806[17] = 10;
  struct StateG * v3808 = slot_181(v3803);
  return v3808;
}

struct StateG * slot_229(struct StateG * v4822) {
  int * v4823 = v4822->saved_regs;
  int * v4824 = v4822->regs;
  int v4825 = v4824[18];
  v4823[18] = v4825;
  int v4827 = v4822->timer;
  int v4837 = v4827 + 1;
  v4822->timer = v4837;
  int * v4829 = v4822->regs;
  v4829[18] = 1;
  struct StateG * v4831 = slot_237(v4822);
  return v4831;
}

struct StateG * slot_17(struct StateG * v479) {
  int v480 = v479->timer;
  int v486 = v480 + 1;
  v479->timer = v486;
  int * v482 = v479->regs;
  v482[1] = 16;
  struct StateG * v484 = slot_19(v479);
  return v484;
}

struct StateG * slot_181(struct StateG * v3862) {
  int v3863 = v3862->timer;
  int v3873 = v3863 + 1;
  v3862->timer = v3873;
  int * v3865 = v3862->pht;
  int v3866 = v3865[26];
  bool v3876 = !(v3866 == 0);
  struct StateG * v3871;
  if (v3876) {
    struct StateG * v3867 = slot_186(v3862);
    v3871 = v3867;
  } else {
    struct StateG * v3869 = slot_187(v3862);
    v3871 = v3869;
  }
  return v3871;
}

struct StateG * slot_197(struct StateG * v4282) {
  int * v4283 = v4282->regs;
  int v4284 = v4283[16];
  int v4285 = v4283[17];
  bool v4305 = v4284 < v4285;
  struct StateG * v4300;
  if (v4305) {
    int * v4286 = v4282->pht;
    v4286[25] = 1;
    int v4288 = v4282->timer;
    int v4309 = v4288 + 15;
    v4282->timer = v4309;
    int * v4290 = v4282->saved_regs;
    int v4291 = v4290[18];
    int * v4292 = v4282->regs;
    v4292[18] = v4291;
    struct StateG * v4294 = slot_202(v4282);
    v4300 = v4294;
  } else {
    int * v4296 = v4282->pht;
    v4296[25] = 0;
    struct StateG * v4298 = slot_203(v4282);
    v4300 = v4298;
  }
  return v4300;
}

struct StateG * slot_207(struct StateG * v4478) {
  int v4479 = v4478->timer;
  int v4483 = v4479 + 1;
  v4478->timer = v4483;
  struct StateG * v4481 = slot_211(v4478);
  return v4481;
}

struct StateG * slot_156(struct StateG * v3306) {
  int * v3307 = v3306->saved_regs;
  int * v3308 = v3306->regs;
  int v3309 = v3308[18];
  v3307[18] = v3309;
  int v3311 = v3306->timer;
  int v3321 = v3311 + 1;
  v3306->timer = v3321;
  int * v3313 = v3306->regs;
  v3313[18] = 2;
  struct StateG * v3315 = slot_164(v3306);
  return v3315;
}

struct StateG * slot_154(struct StateG * v3266) {
  int * v3267 = v3266->saved_regs;
  int * v3268 = v3266->regs;
  int v3269 = v3268[18];
  v3267[18] = v3269;
  int v3271 = v3266->timer;
  int v3281 = v3271 + 1;
  v3266->timer = v3281;
  int * v3273 = v3266->regs;
  v3273[18] = 2;
  struct StateG * v3275 = slot_162(v3266);
  return v3275;
}

struct StateG * slot_68(struct StateG * v1468) {
  int * v1469 = v1468->regs;
  int v1470 = v1469[16];
  int v1471 = v1469[17];
  bool v1491 = v1470 < v1471;
  struct StateG * v1486;
  if (v1491) {
    int * v1472 = v1468->pht;
    v1472[9] = 1;
    struct StateG * v1474 = slot_72(v1468);
    v1486 = v1474;
  } else {
    int * v1476 = v1468->pht;
    v1476[9] = 0;
    int v1478 = v1468->timer;
    int v1500 = v1478 + 15;
    v1468->timer = v1500;
    int * v1480 = v1468->saved_regs;
    int v1481 = v1480[18];
    int * v1482 = v1468->regs;
    v1482[18] = v1481;
    struct StateG * v1484 = slot_73(v1468);
    v1486 = v1484;
  }
  return v1486;
}

struct StateG * slot_260(struct StateG * v5442) {
  int v5443 = v5442->timer;
  int v5449 = v5443 + 1;
  v5442->timer = v5449;
  int * v5445 = v5442->regs;
  v5445[17] = 10;
  struct StateG * v5447 = slot_264(v5442);
  return v5447;
}

struct StateG * slot_105(struct StateG * v2332) {
  int v2333 = v2332->timer;
  int v2339 = v2333 + 1;
  v2332->timer = v2339;
  int * v2335 = v2332->regs;
  v2335[18] = 1;
  struct StateG * v2337 = slot_107(v2332);
  return v2337;
}

struct StateG * slot_27(struct StateG * v644) {
  int * v645 = v644->saved_regs;
  int * v646 = v644->regs;
  int v647 = v646[19];
  v645[19] = v647;
  int v649 = v644->timer;
  int v659 = v649 + 1;
  v644->timer = v659;
  int * v651 = v644->regs;
  v651[19] = 1;
  struct StateG * v653 = slot_31(v644);
  return v653;
}

struct StateG * slot_164(struct StateG * v3546) {
  int * v3547 = v3546->regs;
  int v3548 = v3547[16];
  int v3549 = v3547[17];
  bool v3569 = v3548 < v3549;
  struct StateG * v3564;
  if (v3569) {
    int * v3550 = v3546->pht;
    v3550[21] = 1;
    struct StateG * v3552 = slot_168(v3546);
    v3564 = v3552;
  } else {
    int * v3554 = v3546->pht;
    v3554[21] = 0;
    int v3556 = v3546->timer;
    int v3578 = v3556 + 15;
    v3546->timer = v3578;
    int * v3558 = v3546->saved_regs;
    int v3559 = v3558[18];
    int * v3560 = v3546->regs;
    v3560[18] = v3559;
    struct StateG * v3562 = slot_169(v3546);
    v3564 = v3562;
  }
  return v3564;
}

struct StateG * slot_15(struct StateG * v452) {
  int v453 = v452->timer;
  int v460 = v453 + 1;
  v452->timer = v460;
  int * v455 = v452->regs;
  int v456 = v455[1];
  bool v463 = v456 == 16;
  ret_assert(v463);
  struct StateG * v458 = slot_17(v452);
  return v458;
}

struct StateG * slot_133(struct StateG * v2896) {
  int * v2897 = v2896->regs;
  int v2898 = v2897[16];
  int v2899 = v2897[17];
  bool v2919 = v2898 < v2899;
  struct StateG * v2914;
  if (v2919) {
    int * v2900 = v2896->pht;
    v2900[17] = 1;
    int v2902 = v2896->timer;
    int v2922 = v2902 + 15;
    v2896->timer = v2922;
    int * v2904 = v2896->saved_regs;
    int v2905 = v2904[18];
    int * v2906 = v2896->regs;
    v2906[18] = v2905;
    struct StateG * v2908 = slot_138(v2896);
    v2914 = v2908;
  } else {
    int * v2910 = v2896->pht;
    v2910[17] = 0;
    struct StateG * v2912 = slot_139(v2896);
    v2914 = v2912;
  }
  return v2914;
}

struct StateG * slot_56(struct StateG * v1148) {
  int * v1149 = v1148->saved_regs;
  int * v1150 = v1148->regs;
  int v1151 = v1150[18];
  v1149[18] = v1151;
  int v1153 = v1148->timer;
  int v1163 = v1153 + 1;
  v1148->timer = v1163;
  int * v1155 = v1148->regs;
  v1155[18] = 2;
  struct StateG * v1157 = slot_64(v1148);
  return v1157;
}

struct StateG * slot_244(struct StateG * v5240) {
  int v5241 = v5240->timer;
  int v5245 = v5241 + 1;
  v5240->timer = v5245;
  struct StateG * v5243 = slot_250(v5240);
  return v5243;
}

struct StateG * slot_222(struct StateG * v4682) {
  int v4683 = v4682->timer;
  int v4693 = v4683 + 1;
  v4682->timer = v4693;
  int * v4685 = v4682->pht;
  int v4686 = v4685[1];
  bool v4696 = !(v4686 == 0);
  struct StateG * v4691;
  if (v4696) {
    struct StateG * v4687 = slot_228(v4682);
    v4691 = v4687;
  } else {
    struct StateG * v4689 = slot_229(v4682);
    v4691 = v4689;
  }
  return v4691;
}

struct StateG * slot_34(struct StateG * v845) {
  int v846 = v845->timer;
  int v852 = v846 + 1;
  v845->timer = v852;
  int * v848 = v845->regs;
  v848[19] = 2;
  struct StateG * v850 = slot_32(v845);
  return v850;
}

struct StateG * slot_171(struct StateG * v3740) {
  int v3741 = v3740->timer;
  int v3745 = v3741 + 1;
  v3740->timer = v3745;
  struct StateG * v3743 = slot_177(v3740);
  return v3743;
}

struct StateG * slot_162(struct StateG * v3466) {
  int * v3467 = v3466->regs;
  int v3468 = v3467[16];
  int v3469 = v3467[17];
  bool v3489 = v3468 < v3469;
  struct StateG * v3484;
  if (v3489) {
    int * v3470 = v3466->pht;
    v3470[22] = 1;
    struct StateG * v3472 = slot_172(v3466);
    v3484 = v3472;
  } else {
    int * v3474 = v3466->pht;
    v3474[22] = 0;
    int v3476 = v3466->timer;
    int v3498 = v3476 + 15;
    v3466->timer = v3498;
    int * v3478 = v3466->saved_regs;
    int v3479 = v3478[18];
    int * v3480 = v3466->regs;
    v3480[18] = v3479;
    struct StateG * v3482 = slot_173(v3466);
    v3484 = v3482;
  }
  return v3484;
}

struct StateG * slot_21(struct StateG * v531) {
  int v532 = v531->timer;
  int v538 = v532 + 1;
  v531->timer = v538;
  int * v534 = v531->regs;
  v534[17] = 10;
  struct StateG * v536 = slot_23(v531);
  return v536;
}

struct StateG * slot_239(struct StateG * v5159) {
  int * v5160 = v5159->regs;
  int v5161 = v5160[16];
  int v5162 = v5160[17];
  bool v5182 = v5161 < v5162;
  struct StateG * v5177;
  if (v5182) {
    int * v5163 = v5159->pht;
    v5163[0] = 1;
    int v5165 = v5159->timer;
    int v5186 = v5165 + 15;
    v5159->timer = v5186;
    int * v5167 = v5159->saved_regs;
    int v5168 = v5167[18];
    int * v5169 = v5159->regs;
    v5169[18] = v5168;
    struct StateG * v5171 = slot_246(v5159);
    v5177 = v5171;
  } else {
    int * v5173 = v5159->pht;
    v5173[0] = 0;
    struct StateG * v5175 = slot_247(v5159);
    v5177 = v5175;
  }
  return v5177;
}

struct StateG * slot_118(struct StateG * v2500) {
  int v2501 = v2500->timer;
  int v2511 = v2501 + 1;
  v2500->timer = v2511;
  int * v2503 = v2500->pht;
  int v2504 = v2503[17];
  bool v2514 = !(v2504 == 0);
  struct StateG * v2509;
  if (v2514) {
    struct StateG * v2505 = slot_124(v2500);
    v2509 = v2505;
  } else {
    struct StateG * v2507 = slot_125(v2500);
    v2509 = v2507;
  }
  return v2509;
}

struct StateG * slot_121(struct StateG * v2560) {
  int * v2561 = v2560->saved_regs;
  int * v2562 = v2560->regs;
  int v2563 = v2562[18];
  v2561[18] = v2563;
  int v2565 = v2560->timer;
  int v2575 = v2565 + 1;
  v2560->timer = v2575;
  int * v2567 = v2560->regs;
  v2567[18] = 1;
  struct StateG * v2569 = slot_129(v2560);
  return v2569;
}

struct StateG * slot_144(struct StateG * v3094) {
  int v3095 = v3094->timer;
  int v3101 = v3095 + 1;
  v3094->timer = v3101;
  int * v3097 = v3094->regs;
  v3097[17] = 10;
  struct StateG * v3099 = slot_148(v3094);
  return v3099;
}

struct StateG * slot_267(struct StateG * v5554) {
  int v5555 = v5554->timer;
  int v5565 = v5555 + 1;
  v5554->timer = v5565;
  int * v5557 = v5554->pht;
  int v5558 = v5557[4];
  bool v5568 = !(v5558 == 0);
  struct StateG * v5563;
  if (v5568) {
    struct StateG * v5559 = slot_274(v5554);
    v5563 = v5559;
  } else {
    struct StateG * v5561 = slot_275(v5554);
    v5563 = v5561;
  }
  return v5563;
}

struct StateG * slot_201(struct StateG * v4410) {
  int v4411 = v4410->timer;
  int v4417 = v4411 + 1;
  v4410->timer = v4417;
  int * v4413 = v4410->regs;
  v4413[18] = 1;
  struct StateG * v4415 = slot_203(v4410);
  return v4415;
}

struct StateG * slot_94(struct StateG * v1964) {
  int * v1965 = v1964->saved_regs;
  int * v1966 = v1964->regs;
  int v1967 = v1966[18];
  v1965[18] = v1967;
  int v1969 = v1964->timer;
  int v1979 = v1969 + 1;
  v1964->timer = v1979;
  int * v1971 = v1964->regs;
  v1971[18] = 2;
  struct StateG * v1973 = slot_102(v1964);
  return v1973;
}

struct StateG * slot_63(struct StateG * v1288) {
  int * v1289 = v1288->saved_regs;
  int * v1290 = v1288->regs;
  int v1291 = v1290[18];
  v1289[18] = v1291;
  int v1293 = v1288->timer;
  int v1303 = v1293 + 1;
  v1288->timer = v1303;
  int * v1295 = v1288->regs;
  v1295[18] = 1;
  struct StateG * v1297 = slot_71(v1288);
  return v1297;
}

struct StateG * slot_146(struct StateG * v3120) {
  int v3121 = v3120->timer;
  int v3127 = v3121 + 1;
  v3120->timer = v3127;
  int * v3123 = v3120->regs;
  v3123[17] = 10;
  struct StateG * v3125 = slot_150(v3120);
  return v3125;
}

struct StateG * slot_24(struct StateG * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[19];
  v585[19] = v587;
  int v589 = v584->timer;
  int v599 = v589 + 1;
  v584->timer = v599;
  int * v591 = v584->regs;
  v591[19] = 2;
  struct StateG * v593 = slot_28(v584);
  return v593;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 80;
  struct StateG * v7 = slot_1(v2);
  return v7;
}

struct StateG * slot_286(struct StateG * v6075) {
  int v6076 = v6075->timer;
  int v6082 = v6076 + 1;
  v6075->timer = v6082;
  int * v6078 = v6075->regs;
  v6078[19] = 2;
  struct StateG * v6080 = slot_284(v6075);
  return v6080;
}

struct StateG * slot_195(struct StateG * v4202) {
  int * v4203 = v4202->regs;
  int v4204 = v4203[16];
  int v4205 = v4203[17];
  bool v4225 = v4204 < v4205;
  struct StateG * v4220;
  if (v4225) {
    int * v4206 = v4202->pht;
    v4206[26] = 1;
    int v4208 = v4202->timer;
    int v4229 = v4208 + 15;
    v4202->timer = v4229;
    int * v4210 = v4202->saved_regs;
    int v4211 = v4210[18];
    int * v4212 = v4202->regs;
    v4212[18] = v4211;
    struct StateG * v4214 = slot_206(v4202);
    v4220 = v4214;
  } else {
    int * v4216 = v4202->pht;
    v4216[26] = 0;
    struct StateG * v4218 = slot_207(v4202);
    v4220 = v4218;
  }
  return v4220;
}

struct StateG * slot_125(struct StateG * v2640) {
  int * v2641 = v2640->saved_regs;
  int * v2642 = v2640->regs;
  int v2643 = v2642[18];
  v2641[18] = v2643;
  int v2645 = v2640->timer;
  int v2655 = v2645 + 1;
  v2640->timer = v2655;
  int * v2647 = v2640->regs;
  v2647[18] = 1;
  struct StateG * v2649 = slot_133(v2640);
  return v2649;
}

struct StateG * slot_254(struct StateG * v5364) {
  int v5365 = v5364->timer;
  int v5371 = v5365 + 1;
  v5364->timer = v5371;
  int * v5367 = v5364->regs;
  v5367[1] = 156;
  struct StateG * v5369 = slot_258(v5364);
  return v5369;
}

struct StateG * slot_148(struct StateG * v3146) {
  int v3147 = v3146->timer;
  int v3157 = v3147 + 1;
  v3146->timer = v3157;
  int * v3149 = v3146->pht;
  int v3150 = v3149[23];
  bool v3160 = !(v3150 == 0);
  struct StateG * v3155;
  if (v3160) {
    struct StateG * v3151 = slot_152(v3146);
    v3155 = v3151;
  } else {
    struct StateG * v3153 = slot_153(v3146);
    v3155 = v3153;
  }
  return v3155;
}

struct StateG * slot_126(struct StateG * v2660) {
  int * v2661 = v2660->saved_regs;
  int * v2662 = v2660->regs;
  int v2663 = v2662[18];
  v2661[18] = v2663;
  int v2665 = v2660->timer;
  int v2675 = v2665 + 1;
  v2660->timer = v2675;
  int * v2667 = v2660->regs;
  v2667[18] = 2;
  struct StateG * v2669 = slot_134(v2660);
  return v2669;
}

struct StateG * slot_223(struct StateG * v4702) {
  int v4703 = v4702->timer;
  int v4713 = v4703 + 1;
  v4702->timer = v4713;
  int * v4705 = v4702->pht;
  int v4706 = v4705[0];
  bool v4716 = !(v4706 == 0);
  struct StateG * v4711;
  if (v4716) {
    struct StateG * v4707 = slot_230(v4702);
    v4711 = v4707;
  } else {
    struct StateG * v4709 = slot_231(v4702);
    v4711 = v4709;
  }
  return v4711;
}

struct StateG * slot_79(struct StateG * v1704) {
  int v1705 = v1704->timer;
  int v1709 = v1705 + 1;
  v1704->timer = v1709;
  struct StateG * v1707 = slot_83(v1704);
  return v1707;
}

struct StateG * slot_237(struct StateG * v5081) {
  int * v5082 = v5081->regs;
  int v5083 = v5082[16];
  int v5084 = v5082[17];
  bool v5104 = v5083 < v5084;
  struct StateG * v5099;
  if (v5104) {
    int * v5085 = v5081->pht;
    v5085[1] = 1;
    int v5087 = v5081->timer;
    int v5107 = v5087 + 15;
    v5081->timer = v5107;
    int * v5089 = v5081->saved_regs;
    int v5090 = v5089[18];
    int * v5091 = v5081->regs;
    v5091[18] = v5090;
    struct StateG * v5093 = slot_242(v5081);
    v5099 = v5093;
  } else {
    int * v5095 = v5081->pht;
    v5095[1] = 0;
    struct StateG * v5097 = slot_243(v5081);
    v5099 = v5097;
  }
  return v5099;
}

struct StateG * slot_41(struct StateG * v922) {
  int v923 = v922->timer;
  int v930 = v923 + 1;
  v922->timer = v930;
  int * v925 = v922->regs;
  int v926 = v925[1];
  bool v933 = v926 == 24;
  ret_assert(v933);
  struct StateG * v928 = slot_45(v922);
  return v928;
}

struct StateG * slot_39(struct StateG * v900) {
  int v901 = v900->timer;
  int v905 = v901 + 1;
  v900->timer = v905;
  struct StateG * v903 = slot_43(v900);
  return v903;
}

struct StateG * slot_142(struct StateG * v3073) {
  int v3074 = v3073->timer;
  int v3080 = v3074 + 1;
  v3073->timer = v3080;
  int * v3076 = v3073->regs;
  v3076[18] = 2;
  struct StateG * v3078 = slot_140(v3073);
  return v3078;
}

struct StateG * slot_60(struct StateG * v1228) {
  int * v1229 = v1228->saved_regs;
  int * v1230 = v1228->regs;
  int v1231 = v1230[18];
  v1229[18] = v1231;
  int v1233 = v1228->timer;
  int v1243 = v1233 + 1;
  v1228->timer = v1243;
  int * v1235 = v1228->regs;
  v1235[18] = 2;
  struct StateG * v1237 = slot_68(v1228);
  return v1237;
}

struct StateG * slot_289(struct StateG * v6104) {
  int v6105 = v6104->timer;
  int v6111 = v6105 + 1;
  v6104->timer = v6111;
  int * v6107 = v6104->regs;
  v6107[19] = 1;
  struct StateG * v6109 = slot_284(v6104);
  return v6109;
}

struct StateG * slot_238(struct StateG * v5120) {
  int * v5121 = v5120->regs;
  int v5122 = v5121[16];
  int v5123 = v5121[17];
  bool v5143 = v5122 < v5123;
  struct StateG * v5138;
  if (v5143) {
    int * v5124 = v5120->pht;
    v5124[0] = 1;
    struct StateG * v5126 = slot_244(v5120);
    v5138 = v5126;
  } else {
    int * v5128 = v5120->pht;
    v5128[0] = 0;
    int v5130 = v5120->timer;
    int v5151 = v5130 + 15;
    v5120->timer = v5151;
    int * v5132 = v5120->saved_regs;
    int v5133 = v5132[18];
    int * v5134 = v5120->regs;
    v5134[18] = v5133;
    struct StateG * v5136 = slot_245(v5120);
    v5138 = v5136;
  }
  return v5138;
}

struct StateG * slot_112(struct StateG * v2408) {
  int v2409 = v2408->timer;
  int v2415 = v2409 + 1;
  v2408->timer = v2415;
  int * v2411 = v2408->regs;
  v2411[17] = 10;
  struct StateG * v2413 = slot_116(v2408);
  return v2413;
}

struct StateG * slot_256(struct StateG * v5390) {
  int v5391 = v5390->timer;
  int v5397 = v5391 + 1;
  v5390->timer = v5397;
  int * v5393 = v5390->regs;
  v5393[1] = 164;
  struct StateG * v5395 = slot_260(v5390);
  return v5395;
}

struct StateG * slot_280(struct StateG * v5894) {
  int * v5895 = v5894->regs;
  int v5896 = v5895[16];
  int v5897 = v5895[17];
  bool v5917 = v5896 >= v5897;
  struct StateG * v5912;
  if (v5917) {
    int * v5898 = v5894->pht;
    v5898[5] = 1;
    struct StateG * v5900 = slot_284(v5894);
    v5912 = v5900;
  } else {
    int * v5902 = v5894->pht;
    v5902[5] = 0;
    int v5904 = v5894->timer;
    int v5926 = v5904 + 15;
    v5894->timer = v5926;
    int * v5906 = v5894->saved_regs;
    int v5907 = v5906[19];
    int * v5908 = v5894->regs;
    v5908[19] = v5907;
    struct StateG * v5910 = slot_289(v5894);
    v5912 = v5910;
  }
  return v5912;
}

struct StateG * slot_272(struct StateG * v5654) {
  int * v5655 = v5654->saved_regs;
  int * v5656 = v5654->regs;
  int v5657 = v5656[19];
  v5655[19] = v5657;
  int v5659 = v5654->timer;
  int v5669 = v5659 + 1;
  v5654->timer = v5669;
  int * v5661 = v5654->regs;
  v5661[19] = 2;
  struct StateG * v5663 = slot_280(v5654);
  return v5663;
}

struct StateG * slot_47(struct StateG * v1003) {
  int v1004 = v1003->timer;
  int v1010 = v1004 + 1;
  v1003->timer = v1010;
  int * v1006 = v1003->regs;
  v1006[16] = 20;
  struct StateG * v1008 = slot_51(v1003);
  return v1008;
}

struct StateG * slot_214(struct StateG * v4564) {
  int v4565 = v4564->timer;
  int v4571 = v4565 + 1;
  v4564->timer = v4571;
  int * v4567 = v4564->regs;
  v4567[1] = 156;
  struct StateG * v4569 = slot_218(v4564);
  return v4569;
}

struct StateG * slot_297(struct StateG * v6199) {
  int v6200 = v6199->timer;
  int v6203 = v6200 + 1;
  v6199->timer = v6203;
  return v6199;
}

struct StateG * slot_29(struct StateG * v704) {
  int * v705 = v704->regs;
  int v706 = v705[16];
  int v707 = v705[17];
  bool v727 = v706 >= v707;
  struct StateG * v722;
  if (v727) {
    int * v708 = v704->pht;
    v708[5] = 1;
    int v710 = v704->timer;
    int v731 = v710 + 15;
    v704->timer = v731;
    int * v712 = v704->saved_regs;
    int v713 = v712[19];
    int * v714 = v704->regs;
    v714[19] = v713;
    struct StateG * v716 = slot_34(v704);
    v722 = v716;
  } else {
    int * v718 = v704->pht;
    v718[5] = 0;
    struct StateG * v720 = slot_35(v704);
    v722 = v720;
  }
  return v722;
}

struct StateG * slot_16(struct StateG * v466) {
  int v467 = v466->timer;
  int v473 = v467 + 1;
  v466->timer = v473;
  int * v469 = v466->regs;
  v469[1] = 16;
  struct StateG * v471 = slot_18(v466);
  return v471;
}

struct StateG * slot_245(struct StateG * v5248) {
  int v5249 = v5248->timer;
  int v5255 = v5249 + 1;
  v5248->timer = v5255;
  int * v5251 = v5248->regs;
  v5251[18] = 1;
  struct StateG * v5253 = slot_247(v5248);
  return v5253;
}

struct StateG * slot_113(struct StateG * v2421) {
  int v2422 = v2421->timer;
  int v2428 = v2422 + 1;
  v2421->timer = v2428;
  int * v2424 = v2421->regs;
  v2424[17] = 10;
  struct StateG * v2426 = slot_117(v2421);
  return v2426;
}

struct StateG * slot_151(struct StateG * v3206) {
  int v3207 = v3206->timer;
  int v3217 = v3207 + 1;
  v3206->timer = v3217;
  int * v3209 = v3206->pht;
  int v3210 = v3209[20];
  bool v3220 = !(v3210 == 0);
  struct StateG * v3215;
  if (v3220) {
    struct StateG * v3211 = slot_158(v3206);
    v3215 = v3211;
  } else {
    struct StateG * v3213 = slot_159(v3206);
    v3215 = v3213;
  }
  return v3215;
}

struct StateG * slot_7(struct StateG * v298) {
  int * v299 = v298->saved_regs;
  int * v300 = v298->regs;
  int v301 = v300[18];
  v299[18] = v301;
  int v303 = v298->timer;
  int v313 = v303 + 1;
  v298->timer = v313;
  int * v305 = v298->regs;
  v305[18] = 1;
  struct StateG * v307 = slot_9(v298);
  return v307;
}

struct StateG * slot_124(struct StateG * v2620) {
  int * v2621 = v2620->saved_regs;
  int * v2622 = v2620->regs;
  int v2623 = v2622[18];
  v2621[18] = v2623;
  int v2625 = v2620->timer;
  int v2635 = v2625 + 1;
  v2620->timer = v2635;
  int * v2627 = v2620->regs;
  v2627[18] = 2;
  struct StateG * v2629 = slot_132(v2620);
  return v2629;
}

struct StateG * slot_191(struct StateG * v4062) {
  int * v4063 = v4062->saved_regs;
  int * v4064 = v4062->regs;
  int v4065 = v4064[18];
  v4063[18] = v4065;
  int v4067 = v4062->timer;
  int v4077 = v4067 + 1;
  v4062->timer = v4077;
  int * v4069 = v4062->regs;
  v4069[18] = 1;
  struct StateG * v4071 = slot_199(v4062);
  return v4071;
}

struct StateG * slot_103(struct StateG * v2284) {
  int * v2285 = v2284->regs;
  int v2286 = v2285[16];
  int v2287 = v2285[17];
  bool v2307 = v2286 < v2287;
  struct StateG * v2302;
  if (v2307) {
    int * v2288 = v2284->pht;
    v2288[12] = 1;
    int v2290 = v2284->timer;
    int v2311 = v2290 + 15;
    v2284->timer = v2311;
    int * v2292 = v2284->saved_regs;
    int v2293 = v2292[18];
    int * v2294 = v2284->regs;
    v2294[18] = v2293;
    struct StateG * v2296 = slot_110(v2284);
    v2302 = v2296;
  } else {
    int * v2298 = v2284->pht;
    v2298[12] = 0;
    struct StateG * v2300 = slot_111(v2284);
    v2302 = v2300;
  }
  return v2302;
}

struct StateG * slot_128(struct StateG * v2700) {
  int * v2701 = v2700->regs;
  int v2702 = v2701[16];
  int v2703 = v2701[17];
  bool v2723 = v2702 < v2703;
  struct StateG * v2718;
  if (v2723) {
    int * v2704 = v2700->pht;
    v2704[19] = 1;
    struct StateG * v2706 = slot_136(v2700);
    v2718 = v2706;
  } else {
    int * v2708 = v2700->pht;
    v2708[19] = 0;
    int v2710 = v2700->timer;
    int v2732 = v2710 + 15;
    v2700->timer = v2732;
    int * v2712 = v2700->saved_regs;
    int v2713 = v2712[18];
    int * v2714 = v2700->regs;
    v2714[18] = v2713;
    struct StateG * v2716 = slot_137(v2700);
    v2718 = v2716;
  }
  return v2718;
}

struct StateG * slot_19(struct StateG * v505) {
  int v506 = v505->timer;
  int v512 = v506 + 1;
  v505->timer = v512;
  int * v508 = v505->regs;
  v508[1] = 24;
  struct StateG * v510 = slot_21(v505);
  return v510;
}

struct StateG * slot_87(struct StateG * v1824) {
  int v1825 = v1824->timer;
  int v1835 = v1825 + 1;
  v1824->timer = v1835;
  int * v1827 = v1824->pht;
  int v1828 = v1827[12];
  bool v1838 = !(v1828 == 0);
  struct StateG * v1833;
  if (v1838) {
    struct StateG * v1829 = slot_94(v1824);
    v1833 = v1829;
  } else {
    struct StateG * v1831 = slot_95(v1824);
    v1833 = v1831;
  }
  return v1833;
}

struct StateG * slot_67(struct StateG * v1428) {
  int * v1429 = v1428->regs;
  int v1430 = v1429[16];
  int v1431 = v1429[17];
  bool v1451 = v1430 < v1431;
  struct StateG * v1446;
  if (v1451) {
    int * v1432 = v1428->pht;
    v1432[10] = 1;
    int v1434 = v1428->timer;
    int v1455 = v1434 + 15;
    v1428->timer = v1455;
    int * v1436 = v1428->saved_regs;
    int v1437 = v1436[18];
    int * v1438 = v1428->regs;
    v1438[18] = v1437;
    struct StateG * v1440 = slot_78(v1428);
    v1446 = v1440;
  } else {
    int * v1442 = v1428->pht;
    v1442[10] = 0;
    struct StateG * v1444 = slot_79(v1428);
    v1446 = v1444;
  }
  return v1446;
}

struct StateG * slot_81(struct StateG * v1725) {
  int v1726 = v1725->timer;
  int v1732 = v1726 + 1;
  v1725->timer = v1732;
  int * v1728 = v1725->regs;
  v1728[17] = 10;
  struct StateG * v1730 = slot_85(v1725);
  return v1730;
}

struct StateG * slot_95(struct StateG * v1984) {
  int * v1985 = v1984->saved_regs;
  int * v1986 = v1984->regs;
  int v1987 = v1986[18];
  v1985[18] = v1987;
  int v1989 = v1984->timer;
  int v1999 = v1989 + 1;
  v1984->timer = v1999;
  int * v1991 = v1984->regs;
  v1991[18] = 1;
  struct StateG * v1993 = slot_103(v1984);
  return v1993;
}

struct StateG * slot_115(struct StateG * v2447) {
  int v2448 = v2447->timer;
  int v2454 = v2448 + 1;
  v2447->timer = v2454;
  int * v2450 = v2447->regs;
  v2450[17] = 10;
  struct StateG * v2452 = slot_119(v2447);
  return v2452;
}

struct StateG * slot_78(struct StateG * v1691) {
  int v1692 = v1691->timer;
  int v1698 = v1692 + 1;
  v1691->timer = v1698;
  int * v1694 = v1691->regs;
  v1694[18] = 2;
  struct StateG * v1696 = slot_76(v1691);
  return v1696;
}

struct StateG * slot_32(struct StateG * v824) {
  int v825 = v824->timer;
  int v829 = v825 + 1;
  v824->timer = v829;
  struct StateG * v827 = slot_40(v824);
  return v827;
}

struct StateG * slot_205(struct StateG * v4452) {
  int v4453 = v4452->timer;
  int v4459 = v4453 + 1;
  v4452->timer = v4459;
  int * v4455 = v4452->regs;
  v4455[18] = 1;
  struct StateG * v4457 = slot_207(v4452);
  return v4457;
}

struct StateG * slot_193(struct StateG * v4122) {
  int * v4123 = v4122->regs;
  int v4124 = v4123[16];
  int v4125 = v4123[17];
  bool v4145 = v4124 < v4125;
  struct StateG * v4140;
  if (v4145) {
    int * v4126 = v4122->pht;
    v4126[27] = 1;
    int v4128 = v4122->timer;
    int v4149 = v4128 + 15;
    v4122->timer = v4149;
    int * v4130 = v4122->saved_regs;
    int v4131 = v4130[18];
    int * v4132 = v4122->regs;
    v4132[18] = v4131;
    struct StateG * v4134 = slot_202(v4122);
    v4140 = v4134;
  } else {
    int * v4136 = v4122->pht;
    v4136[27] = 0;
    struct StateG * v4138 = slot_203(v4122);
    v4140 = v4138;
  }
  return v4140;
}

struct StateG * slot_233(struct StateG * v4922) {
  int * v4923 = v4922->regs;
  int v4924 = v4923[16];
  int v4925 = v4923[17];
  bool v4945 = v4924 < v4925;
  struct StateG * v4940;
  if (v4945) {
    int * v4926 = v4922->pht;
    v4926[3] = 1;
    int v4928 = v4922->timer;
    int v4949 = v4928 + 15;
    v4922->timer = v4949;
    int * v4930 = v4922->saved_regs;
    int v4931 = v4930[18];
    int * v4932 = v4922->regs;
    v4932[18] = v4931;
    struct StateG * v4934 = slot_242(v4922);
    v4940 = v4934;
  } else {
    int * v4936 = v4922->pht;
    v4936[3] = 0;
    struct StateG * v4938 = slot_243(v4922);
    v4940 = v4938;
  }
  return v4940;
}

struct StateG * slot_176(struct StateG * v3790) {
  int v3791 = v3790->timer;
  int v3797 = v3791 + 1;
  v3790->timer = v3797;
  int * v3793 = v3790->regs;
  v3793[17] = 10;
  struct StateG * v3795 = slot_180(v3790);
  return v3795;
}

struct StateG * slot_189(struct StateG * v4022) {
  int * v4023 = v4022->saved_regs;
  int * v4024 = v4022->regs;
  int v4025 = v4024[18];
  v4023[18] = v4025;
  int v4027 = v4022->timer;
  int v4037 = v4027 + 1;
  v4022->timer = v4037;
  int * v4029 = v4022->regs;
  v4029[18] = 1;
  struct StateG * v4031 = slot_197(v4022);
  return v4031;
}

struct StateG * slot_33(struct StateG * v832) {
  int v833 = v832->timer;
  int v839 = v833 + 1;
  v832->timer = v839;
  int * v835 = v832->regs;
  v835[19] = 1;
  struct StateG * v837 = slot_35(v832);
  return v837;
}

struct StateG * slot_35(struct StateG * v858) {
  int v859 = v858->timer;
  int v863 = v859 + 1;
  v858->timer = v863;
  struct StateG * v861 = slot_41(v858);
  return v861;
}

struct StateG * slot_258(struct StateG * v5416) {
  int v5417 = v5416->timer;
  int v5423 = v5417 + 1;
  v5416->timer = v5423;
  int * v5419 = v5416->regs;
  v5419[1] = 164;
  struct StateG * v5421 = slot_262(v5416);
  return v5421;
}

struct StateG * slot_246(struct StateG * v5261) {
  int v5262 = v5261->timer;
  int v5268 = v5262 + 1;
  v5261->timer = v5268;
  int * v5264 = v5261->regs;
  v5264[18] = 2;
  struct StateG * v5266 = slot_244(v5261);
  return v5266;
}

struct StateG * slot_210(struct StateG * v4512) {
  int v4513 = v4512->timer;
  int v4519 = v4513 + 1;
  v4512->timer = v4519;
  int * v4515 = v4512->regs;
  v4515[1] = 148;
  struct StateG * v4517 = slot_214(v4512);
  return v4517;
}

struct StateG * slot_284(struct StateG * v6054) {
  int v6055 = v6054->timer;
  int v6059 = v6055 + 1;
  v6054->timer = v6059;
  struct StateG * v6057 = slot_295(v6054);
  return v6057;
}

struct StateG * slot_166(struct StateG * v3626) {
  int * v3627 = v3626->regs;
  int v3628 = v3627[16];
  int v3629 = v3627[17];
  bool v3649 = v3628 < v3629;
  struct StateG * v3644;
  if (v3649) {
    int * v3630 = v3626->pht;
    v3630[20] = 1;
    struct StateG * v3632 = slot_172(v3626);
    v3644 = v3632;
  } else {
    int * v3634 = v3626->pht;
    v3634[20] = 0;
    int v3636 = v3626->timer;
    int v3658 = v3636 + 15;
    v3626->timer = v3658;
    int * v3638 = v3626->saved_regs;
    int v3639 = v3638[18];
    int * v3640 = v3626->regs;
    v3640[18] = v3639;
    struct StateG * v3642 = slot_173(v3626);
    v3644 = v3642;
  }
  return v3644;
}

struct StateG * slot_51(struct StateG * v1055) {
  int v1056 = v1055->timer;
  int v1062 = v1056 + 1;
  v1055->timer = v1062;
  int * v1058 = v1055->regs;
  v1058[17] = 10;
  struct StateG * v1060 = slot_55(v1055);
  return v1060;
}

struct StateG * slot_52(struct StateG * v1068) {
  int v1069 = v1068->timer;
  int v1079 = v1069 + 1;
  v1068->timer = v1079;
  int * v1071 = v1068->pht;
  int v1072 = v1071[11];
  bool v1082 = !(v1072 == 0);
  struct StateG * v1077;
  if (v1082) {
    struct StateG * v1073 = slot_56(v1068);
    v1077 = v1073;
  } else {
    struct StateG * v1075 = slot_57(v1068);
    v1077 = v1075;
  }
  return v1077;
}

struct StateG * slot_83(struct StateG * v1751) {
  int v1752 = v1751->timer;
  int v1758 = v1752 + 1;
  v1751->timer = v1758;
  int * v1754 = v1751->regs;
  v1754[17] = 10;
  struct StateG * v1756 = slot_87(v1751);
  return v1756;
}

struct StateG * slot_25(struct StateG * v604) {
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[19];
  v605[19] = v607;
  int v609 = v604->timer;
  int v619 = v609 + 1;
  v604->timer = v619;
  int * v611 = v604->regs;
  v611[19] = 1;
  struct StateG * v613 = slot_29(v604);
  return v613;
}

struct StateG * slot_209(struct StateG * v4499) {
  int v4500 = v4499->timer;
  int v4506 = v4500 + 1;
  v4499->timer = v4506;
  int * v4502 = v4499->regs;
  v4502[1] = 148;
  struct StateG * v4504 = slot_213(v4499);
  return v4504;
}

struct StateG * slot_3(struct StateG * v232) {
  int v233 = v232->timer;
  int v239 = v233 + 1;
  v232->timer = v239;
  int * v235 = v232->regs;
  v235[1] = 16;
  struct StateG * v237 = slot_4(v232);
  return v237;
}

struct StateG * slot_264(struct StateG * v5494) {
  int v5495 = v5494->timer;
  int v5505 = v5495 + 1;
  v5494->timer = v5505;
  int * v5497 = v5494->pht;
  int v5498 = v5497[7];
  bool v5508 = !(v5498 == 0);
  struct StateG * v5503;
  if (v5508) {
    struct StateG * v5499 = slot_268(v5494);
    v5503 = v5499;
  } else {
    struct StateG * v5501 = slot_269(v5494);
    v5503 = v5501;
  }
  return v5503;
}

struct StateG * slot_123(struct StateG * v2600) {
  int * v2601 = v2600->saved_regs;
  int * v2602 = v2600->regs;
  int v2603 = v2602[18];
  v2601[18] = v2603;
  int v2605 = v2600->timer;
  int v2615 = v2605 + 1;
  v2600->timer = v2615;
  int * v2607 = v2600->regs;
  v2607[18] = 1;
  struct StateG * v2609 = slot_131(v2600);
  return v2609;
}

struct StateG * slot_73(struct StateG * v1636) {
  int v1637 = v1636->timer;
  int v1643 = v1637 + 1;
  v1636->timer = v1643;
  int * v1639 = v1636->regs;
  v1639[18] = 1;
  struct StateG * v1641 = slot_75(v1636);
  return v1641;
}

struct StateG * slot_270(struct StateG * v5614) {
  int * v5615 = v5614->saved_regs;
  int * v5616 = v5614->regs;
  int v5617 = v5616[19];
  v5615[19] = v5617;
  int v5619 = v5614->timer;
  int v5629 = v5619 + 1;
  v5614->timer = v5629;
  int * v5621 = v5614->regs;
  v5621[19] = 2;
  struct StateG * v5623 = slot_278(v5614);
  return v5623;
}

struct StateG * slot_198(struct StateG * v4322) {
  int * v4323 = v4322->regs;
  int v4324 = v4323[16];
  int v4325 = v4323[17];
  bool v4345 = v4324 < v4325;
  struct StateG * v4340;
  if (v4345) {
    int * v4326 = v4322->pht;
    v4326[24] = 1;
    struct StateG * v4328 = slot_204(v4322);
    v4340 = v4328;
  } else {
    int * v4330 = v4322->pht;
    v4330[24] = 0;
    int v4332 = v4322->timer;
    int v4354 = v4332 + 15;
    v4322->timer = v4354;
    int * v4334 = v4322->saved_regs;
    int v4335 = v4334[18];
    int * v4336 = v4322->regs;
    v4336[18] = v4335;
    struct StateG * v4338 = slot_205(v4322);
    v4340 = v4338;
  }
  return v4340;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[16] = v121;
  struct StateG * v124 = slot_2(v15);
  return v124;
}

struct StateG * slot_187(struct StateG * v3982) {
  int * v3983 = v3982->saved_regs;
  int * v3984 = v3982->regs;
  int v3985 = v3984[18];
  v3983[18] = v3985;
  int v3987 = v3982->timer;
  int v3997 = v3987 + 1;
  v3982->timer = v3997;
  int * v3989 = v3982->regs;
  v3989[18] = 1;
  struct StateG * v3991 = slot_195(v3982);
  return v3991;
}

struct StateG * slot_97(struct StateG * v2044) {
  int * v2045 = v2044->regs;
  int v2046 = v2045[16];
  int v2047 = v2045[17];
  bool v2067 = v2046 < v2047;
  struct StateG * v2062;
  if (v2067) {
    int * v2048 = v2044->pht;
    v2048[15] = 1;
    int v2050 = v2044->timer;
    int v2071 = v2050 + 15;
    v2044->timer = v2071;
    int * v2052 = v2044->saved_regs;
    int v2053 = v2052[18];
    int * v2054 = v2044->regs;
    v2054[18] = v2053;
    struct StateG * v2056 = slot_106(v2044);
    v2062 = v2056;
  } else {
    int * v2058 = v2044->pht;
    v2058[15] = 0;
    struct StateG * v2060 = slot_107(v2044);
    v2062 = v2060;
  }
  return v2062;
}

struct StateG * slot_182(struct StateG * v3882) {
  int v3883 = v3882->timer;
  int v3893 = v3883 + 1;
  v3882->timer = v3893;
  int * v3885 = v3882->pht;
  int v3886 = v3885[25];
  bool v3896 = !(v3886 == 0);
  struct StateG * v3891;
  if (v3896) {
    struct StateG * v3887 = slot_188(v3882);
    v3891 = v3887;
  } else {
    struct StateG * v3889 = slot_189(v3882);
    v3891 = v3889;
  }
  return v3891;
}

struct StateG * slot_38(struct StateG * v887) {
  int v888 = v887->timer;
  int v894 = v888 + 1;
  v887->timer = v894;
  int * v890 = v887->regs;
  v890[19] = 2;
  struct StateG * v892 = slot_36(v887);
  return v892;
}

struct StateG * slot_178(struct StateG * v3816) {
  int v3817 = v3816->timer;
  int v3823 = v3817 + 1;
  v3816->timer = v3823;
  int * v3819 = v3816->regs;
  v3819[17] = 10;
  struct StateG * v3821 = slot_182(v3816);
  return v3821;
}

struct StateG * slot_106(struct StateG * v2345) {
  int v2346 = v2345->timer;
  int v2352 = v2346 + 1;
  v2345->timer = v2352;
  int * v2348 = v2345->regs;
  v2348[18] = 2;
  struct StateG * v2350 = slot_104(v2345);
  return v2350;
}

struct StateG * slot_98(struct StateG * v2084) {
  int * v2085 = v2084->regs;
  int v2086 = v2085[16];
  int v2087 = v2085[17];
  bool v2107 = v2086 < v2087;
  struct StateG * v2102;
  if (v2107) {
    int * v2088 = v2084->pht;
    v2088[14] = 1;
    struct StateG * v2090 = slot_108(v2084);
    v2102 = v2090;
  } else {
    int * v2092 = v2084->pht;
    v2092[14] = 0;
    int v2094 = v2084->timer;
    int v2116 = v2094 + 15;
    v2084->timer = v2116;
    int * v2096 = v2084->saved_regs;
    int v2097 = v2096[18];
    int * v2098 = v2084->regs;
    v2098[18] = v2097;
    struct StateG * v2100 = slot_109(v2084);
    v2102 = v2100;
  }
  return v2102;
}

struct StateG * slot_159(struct StateG * v3366) {
  int * v3367 = v3366->saved_regs;
  int * v3368 = v3366->regs;
  int v3369 = v3368[18];
  v3367[18] = v3369;
  int v3371 = v3366->timer;
  int v3381 = v3371 + 1;
  v3366->timer = v3381;
  int * v3373 = v3366->regs;
  v3373[18] = 1;
  struct StateG * v3375 = slot_167(v3366);
  return v3375;
}

struct StateG * slot_46(struct StateG * v990) {
  int v991 = v990->timer;
  int v997 = v991 + 1;
  v990->timer = v997;
  int * v993 = v990->regs;
  v993[16] = 20;
  struct StateG * v995 = slot_50(v990);
  return v995;
}

struct StateG * slot_212(struct StateG * v4538) {
  int v4539 = v4538->timer;
  int v4545 = v4539 + 1;
  v4538->timer = v4545;
  int * v4541 = v4538->regs;
  v4541[1] = 156;
  struct StateG * v4543 = slot_216(v4538);
  return v4543;
}

struct StateG * slot_132(struct StateG * v2858) {
  int * v2859 = v2858->regs;
  int v2860 = v2859[16];
  int v2861 = v2859[17];
  bool v2881 = v2860 < v2861;
  struct StateG * v2876;
  if (v2881) {
    int * v2862 = v2858->pht;
    v2862[17] = 1;
    struct StateG * v2864 = slot_136(v2858);
    v2876 = v2864;
  } else {
    int * v2866 = v2858->pht;
    v2866[17] = 0;
    int v2868 = v2858->timer;
    int v2888 = v2868 + 15;
    v2858->timer = v2888;
    int * v2870 = v2858->saved_regs;
    int v2871 = v2870[18];
    int * v2872 = v2858->regs;
    v2872[18] = v2871;
    struct StateG * v2874 = slot_137(v2858);
    v2876 = v2874;
  }
  return v2876;
}

struct StateG * slot_130(struct StateG * v2780) {
  int * v2781 = v2780->regs;
  int v2782 = v2781[16];
  int v2783 = v2781[17];
  bool v2803 = v2782 < v2783;
  struct StateG * v2798;
  if (v2803) {
    int * v2784 = v2780->pht;
    v2784[18] = 1;
    struct StateG * v2786 = slot_140(v2780);
    v2798 = v2786;
  } else {
    int * v2788 = v2780->pht;
    v2788[18] = 0;
    int v2790 = v2780->timer;
    int v2812 = v2790 + 15;
    v2780->timer = v2812;
    int * v2792 = v2780->saved_regs;
    int v2793 = v2792[18];
    int * v2794 = v2780->regs;
    v2794[18] = v2793;
    struct StateG * v2796 = slot_141(v2780);
    v2798 = v2796;
  }
  return v2798;
}

struct StateG * slot_211(struct StateG * v4525) {
  int v4526 = v4525->timer;
  int v4532 = v4526 + 1;
  v4525->timer = v4532;
  int * v4528 = v4525->regs;
  v4528[1] = 148;
  struct StateG * v4530 = slot_215(v4525);
  return v4530;
}

struct StateG * slot_20(struct StateG * v518) {
  int v519 = v518->timer;
  int v525 = v519 + 1;
  v518->timer = v525;
  int * v521 = v518->regs;
  v521[17] = 10;
  struct StateG * v523 = slot_22(v518);
  return v523;
}

struct StateG * slot_141(struct StateG * v3060) {
  int v3061 = v3060->timer;
  int v3067 = v3061 + 1;
  v3060->timer = v3067;
  int * v3063 = v3060->regs;
  v3063[18] = 1;
  struct StateG * v3065 = slot_143(v3060);
  return v3065;
}

struct StateG * slot_61(struct StateG * v1248) {
  int * v1249 = v1248->saved_regs;
  int * v1250 = v1248->regs;
  int v1251 = v1250[18];
  v1249[18] = v1251;
  int v1253 = v1248->timer;
  int v1263 = v1253 + 1;
  v1248->timer = v1263;
  int * v1255 = v1248->regs;
  v1255[18] = 1;
  struct StateG * v1257 = slot_69(v1248);
  return v1257;
}

struct StateG * slot_30(struct StateG * v744) {
  int * v745 = v744->regs;
  int v746 = v745[16];
  int v747 = v745[17];
  bool v767 = v746 >= v747;
  struct StateG * v762;
  if (v767) {
    int * v748 = v744->pht;
    v748[4] = 1;
    struct StateG * v750 = slot_36(v744);
    v762 = v750;
  } else {
    int * v752 = v744->pht;
    v752[4] = 0;
    int v754 = v744->timer;
    int v776 = v754 + 15;
    v744->timer = v776;
    int * v756 = v744->saved_regs;
    int v757 = v756[19];
    int * v758 = v744->regs;
    v758[19] = v757;
    struct StateG * v760 = slot_37(v744);
    v762 = v760;
  }
  return v762;
}

struct StateG * slot_4(struct StateG * v245) {
  int v246 = v245->timer;
  int v252 = v246 + 1;
  v245->timer = v252;
  int * v248 = v245->regs;
  v248[17] = 10;
  struct StateG * v250 = slot_5(v245);
  return v250;
}

struct StateG * slot_18(struct StateG * v492) {
  int v493 = v492->timer;
  int v499 = v493 + 1;
  v492->timer = v499;
  int * v495 = v492->regs;
  v495[1] = 24;
  struct StateG * v497 = slot_20(v492);
  return v497;
}

struct StateG * slot_9(struct StateG * v357) {
  int * v358 = v357->regs;
  int v359 = v358[16];
  int v360 = v358[17];
  bool v380 = v359 < v360;
  struct StateG * v375;
  if (v380) {
    int * v361 = v357->pht;
    v361[0] = 1;
    int v363 = v357->timer;
    int v384 = v363 + 15;
    v357->timer = v384;
    int * v365 = v357->saved_regs;
    int v366 = v365[18];
    int * v367 = v357->regs;
    v367[18] = v366;
    struct StateG * v369 = slot_12(v357);
    v375 = v369;
  } else {
    int * v371 = v357->pht;
    v371[0] = 0;
    struct StateG * v373 = slot_13(v357);
    v375 = v373;
  }
  return v375;
}

struct StateG * slot_183(struct StateG * v3902) {
  int v3903 = v3902->timer;
  int v3913 = v3903 + 1;
  v3902->timer = v3913;
  int * v3905 = v3902->pht;
  int v3906 = v3905[24];
  bool v3916 = !(v3906 == 0);
  struct StateG * v3911;
  if (v3916) {
    struct StateG * v3907 = slot_190(v3902);
    v3911 = v3907;
  } else {
    struct StateG * v3909 = slot_191(v3902);
    v3911 = v3909;
  }
  return v3911;
}

struct StateG * slot_240(struct StateG * v5198) {
  int v5199 = v5198->timer;
  int v5203 = v5199 + 1;
  v5198->timer = v5203;
  struct StateG * v5201 = slot_248(v5198);
  return v5201;
}

struct StateG * slot_282(struct StateG * v5974) {
  int * v5975 = v5974->regs;
  int v5976 = v5975[16];
  int v5977 = v5975[17];
  bool v5997 = v5976 >= v5977;
  struct StateG * v5992;
  if (v5997) {
    int * v5978 = v5974->pht;
    v5978[4] = 1;
    struct StateG * v5980 = slot_284(v5974);
    v5992 = v5980;
  } else {
    int * v5982 = v5974->pht;
    v5982[4] = 0;
    int v5984 = v5974->timer;
    int v6006 = v5984 + 15;
    v5974->timer = v6006;
    int * v5986 = v5974->saved_regs;
    int v5987 = v5986[19];
    int * v5988 = v5974->regs;
    v5988[19] = v5987;
    struct StateG * v5990 = slot_289(v5974);
    v5992 = v5990;
  }
  return v5992;
}

struct StateG * slot_247(struct StateG * v5274) {
  int v5275 = v5274->timer;
  int v5279 = v5275 + 1;
  v5274->timer = v5279;
  struct StateG * v5277 = slot_251(v5274);
  return v5277;
}

struct StateG * slot_43(struct StateG * v950) {
  int v951 = v950->timer;
  int v958 = v951 + 1;
  v950->timer = v958;
  int * v953 = v950->regs;
  int v954 = v953[1];
  bool v961 = v954 == 24;
  ret_assert(v961);
  struct StateG * v956 = slot_47(v950);
  return v956;
}

struct StateG * slot_70(struct StateG * v1548) {
  int * v1549 = v1548->regs;
  int v1550 = v1549[16];
  int v1551 = v1549[17];
  bool v1571 = v1550 < v1551;
  struct StateG * v1566;
  if (v1571) {
    int * v1552 = v1548->pht;
    v1552[8] = 1;
    struct StateG * v1554 = slot_76(v1548);
    v1566 = v1554;
  } else {
    int * v1556 = v1548->pht;
    v1556[8] = 0;
    int v1558 = v1548->timer;
    int v1580 = v1558 + 15;
    v1548->timer = v1580;
    int * v1560 = v1548->saved_regs;
    int v1561 = v1560[18];
    int * v1562 = v1548->regs;
    v1562[18] = v1561;
    struct StateG * v1564 = slot_77(v1548);
    v1566 = v1564;
  }
  return v1566;
}

struct StateG * slot_168(struct StateG * v3706) {
  int v3707 = v3706->timer;
  int v3711 = v3707 + 1;
  v3706->timer = v3711;
  struct StateG * v3709 = slot_176(v3706);
  return v3709;
}

struct StateG * slot_76(struct StateG * v1670) {
  int v1671 = v1670->timer;
  int v1675 = v1671 + 1;
  v1670->timer = v1675;
  struct StateG * v1673 = slot_82(v1670);
  return v1673;
}

struct StateG * slot_6(struct StateG * v278) {
  int * v279 = v278->saved_regs;
  int * v280 = v278->regs;
  int v281 = v280[18];
  v279[18] = v281;
  int v283 = v278->timer;
  int v293 = v283 + 1;
  v278->timer = v293;
  int * v285 = v278->regs;
  v285[18] = 2;
  struct StateG * v287 = slot_8(v278);
  return v287;
}

struct StateG * slot_225(struct StateG * v4742) {
  int * v4743 = v4742->saved_regs;
  int * v4744 = v4742->regs;
  int v4745 = v4744[18];
  v4743[18] = v4745;
  int v4747 = v4742->timer;
  int v4757 = v4747 + 1;
  v4742->timer = v4757;
  int * v4749 = v4742->regs;
  v4749[18] = 1;
  struct StateG * v4751 = slot_233(v4742);
  return v4751;
}

struct StateG * slot_55(struct StateG * v1128) {
  int v1129 = v1128->timer;
  int v1139 = v1129 + 1;
  v1128->timer = v1139;
  int * v1131 = v1128->pht;
  int v1132 = v1131[8];
  bool v1142 = !(v1132 == 0);
  struct StateG * v1137;
  if (v1142) {
    struct StateG * v1133 = slot_62(v1128);
    v1137 = v1133;
  } else {
    struct StateG * v1135 = slot_63(v1128);
    v1137 = v1135;
  }
  return v1137;
}

struct StateG * slot_283(struct StateG * v6014) {
  int * v6015 = v6014->regs;
  int v6016 = v6015[16];
  int v6017 = v6015[17];
  bool v6037 = v6016 >= v6017;
  struct StateG * v6032;
  if (v6037) {
    int * v6018 = v6014->pht;
    v6018[4] = 1;
    int v6020 = v6014->timer;
    int v6041 = v6020 + 15;
    v6014->timer = v6041;
    int * v6022 = v6014->saved_regs;
    int v6023 = v6022[19];
    int * v6024 = v6014->regs;
    v6024[19] = v6023;
    struct StateG * v6026 = slot_286(v6014);
    v6032 = v6026;
  } else {
    int * v6028 = v6014->pht;
    v6028[4] = 0;
    struct StateG * v6030 = slot_284(v6014);
    v6032 = v6030;
  }
  return v6032;
}

struct StateG * slot_213(struct StateG * v4551) {
  int v4552 = v4551->timer;
  int v4558 = v4552 + 1;
  v4551->timer = v4558;
  int * v4554 = v4551->regs;
  v4554[1] = 156;
  struct StateG * v4556 = slot_217(v4551);
  return v4556;
}

struct StateG * slot_82(struct StateG * v1738) {
  int v1739 = v1738->timer;
  int v1745 = v1739 + 1;
  v1738->timer = v1745;
  int * v1741 = v1738->regs;
  v1741[17] = 10;
  struct StateG * v1743 = slot_86(v1738);
  return v1743;
}

struct StateG * slot_274(struct StateG * v5694) {
  int * v5695 = v5694->saved_regs;
  int * v5696 = v5694->regs;
  int v5697 = v5696[19];
  v5695[19] = v5697;
  int v5699 = v5694->timer;
  int v5709 = v5699 + 1;
  v5694->timer = v5709;
  int * v5701 = v5694->regs;
  v5701[19] = 2;
  struct StateG * v5703 = slot_282(v5694);
  return v5703;
}

struct StateG * slot_263(struct StateG * v5481) {
  int v5482 = v5481->timer;
  int v5488 = v5482 + 1;
  v5481->timer = v5488;
  int * v5484 = v5481->regs;
  v5484[17] = 10;
  struct StateG * v5486 = slot_267(v5481);
  return v5486;
}

struct StateG * slot_161(struct StateG * v3426) {
  int * v3427 = v3426->regs;
  int v3428 = v3427[16];
  int v3429 = v3427[17];
  bool v3449 = v3428 < v3429;
  struct StateG * v3444;
  if (v3449) {
    int * v3430 = v3426->pht;
    v3430[23] = 1;
    int v3432 = v3426->timer;
    int v3453 = v3432 + 15;
    v3426->timer = v3453;
    int * v3434 = v3426->saved_regs;
    int v3435 = v3434[18];
    int * v3436 = v3426->regs;
    v3436[18] = v3435;
    struct StateG * v3438 = slot_170(v3426);
    v3444 = v3438;
  } else {
    int * v3440 = v3426->pht;
    v3440[23] = 0;
    struct StateG * v3442 = slot_171(v3426);
    v3444 = v3442;
  }
  return v3444;
}

struct StateG * slot_185(struct StateG * v3942) {
  int * v3943 = v3942->saved_regs;
  int * v3944 = v3942->regs;
  int v3945 = v3944[18];
  v3943[18] = v3945;
  int v3947 = v3942->timer;
  int v3957 = v3947 + 1;
  v3942->timer = v3957;
  int * v3949 = v3942->regs;
  v3949[18] = 1;
  struct StateG * v3951 = slot_193(v3942);
  return v3951;
}

struct StateG * slot_91(struct StateG * v1904) {
  int * v1905 = v1904->saved_regs;
  int * v1906 = v1904->regs;
  int v1907 = v1906[18];
  v1905[18] = v1907;
  int v1909 = v1904->timer;
  int v1919 = v1909 + 1;
  v1904->timer = v1919;
  int * v1911 = v1904->regs;
  v1911[18] = 1;
  struct StateG * v1913 = slot_99(v1904);
  return v1913;
}

struct StateG * slot_58(struct StateG * v1188) {
  int * v1189 = v1188->saved_regs;
  int * v1190 = v1188->regs;
  int v1191 = v1190[18];
  v1189[18] = v1191;
  int v1193 = v1188->timer;
  int v1203 = v1193 + 1;
  v1188->timer = v1203;
  int * v1195 = v1188->regs;
  v1195[18] = 2;
  struct StateG * v1197 = slot_66(v1188);
  return v1197;
}

struct StateG * slot_89(struct StateG * v1864) {
  int * v1865 = v1864->saved_regs;
  int * v1866 = v1864->regs;
  int v1867 = v1866[18];
  v1865[18] = v1867;
  int v1869 = v1864->timer;
  int v1879 = v1869 + 1;
  v1864->timer = v1879;
  int * v1871 = v1864->regs;
  v1871[18] = 1;
  struct StateG * v1873 = slot_97(v1864);
  return v1873;
}

struct StateG * slot_255(struct StateG * v5377) {
  int v5378 = v5377->timer;
  int v5384 = v5378 + 1;
  v5377->timer = v5384;
  int * v5380 = v5377->regs;
  v5380[1] = 156;
  struct StateG * v5382 = slot_259(v5377);
  return v5382;
}

struct StateG * slot_66(struct StateG * v1388) {
  int * v1389 = v1388->regs;
  int v1390 = v1389[16];
  int v1391 = v1389[17];
  bool v1411 = v1390 < v1391;
  struct StateG * v1406;
  if (v1411) {
    int * v1392 = v1388->pht;
    v1392[10] = 1;
    struct StateG * v1394 = slot_76(v1388);
    v1406 = v1394;
  } else {
    int * v1396 = v1388->pht;
    v1396[10] = 0;
    int v1398 = v1388->timer;
    int v1420 = v1398 + 15;
    v1388->timer = v1420;
    int * v1400 = v1388->saved_regs;
    int v1401 = v1400[18];
    int * v1402 = v1388->regs;
    v1402[18] = v1401;
    struct StateG * v1404 = slot_77(v1388);
    v1406 = v1404;
  }
  return v1406;
}

struct StateG * slot_140(struct StateG * v3052) {
  int v3053 = v3052->timer;
  int v3057 = v3053 + 1;
  v3052->timer = v3057;
  struct StateG * v3055 = slot_146(v3052);
  return v3055;
}

struct StateG * slot_265(struct StateG * v5514) {
  int v5515 = v5514->timer;
  int v5525 = v5515 + 1;
  v5514->timer = v5525;
  int * v5517 = v5514->pht;
  int v5518 = v5517[6];
  bool v5528 = !(v5518 == 0);
  struct StateG * v5523;
  if (v5528) {
    struct StateG * v5519 = slot_270(v5514);
    v5523 = v5519;
  } else {
    struct StateG * v5521 = slot_271(v5514);
    v5523 = v5521;
  }
  return v5523;
}

struct StateG * slot_49(struct StateG * v1029) {
  int v1030 = v1029->timer;
  int v1036 = v1030 + 1;
  v1029->timer = v1036;
  int * v1032 = v1029->regs;
  v1032[17] = 10;
  struct StateG * v1034 = slot_53(v1029);
  return v1034;
}

struct StateG * slot_216(struct StateG * v4590) {
  int v4591 = v4590->timer;
  int v4597 = v4591 + 1;
  v4590->timer = v4597;
  int * v4593 = v4590->regs;
  v4593[17] = 10;
  struct StateG * v4595 = slot_220(v4590);
  return v4595;
}

struct StateG * slot_50(struct StateG * v1042) {
  int v1043 = v1042->timer;
  int v1049 = v1043 + 1;
  v1042->timer = v1049;
  int * v1045 = v1042->regs;
  v1045[17] = 10;
  struct StateG * v1047 = slot_54(v1042);
  return v1047;
}

struct StateG * slot_37(struct StateG * v874) {
  int v875 = v874->timer;
  int v881 = v875 + 1;
  v874->timer = v881;
  int * v877 = v874->regs;
  v877[19] = 1;
  struct StateG * v879 = slot_39(v874);
  return v879;
}

struct StateG * slot_114(struct StateG * v2434) {
  int v2435 = v2434->timer;
  int v2441 = v2435 + 1;
  v2434->timer = v2441;
  int * v2437 = v2434->regs;
  v2437[17] = 10;
  struct StateG * v2439 = slot_118(v2434);
  return v2439;
}

struct StateG * slot_135(struct StateG * v2972) {
  int * v2973 = v2972->regs;
  int v2974 = v2973[16];
  int v2975 = v2973[17];
  bool v2995 = v2974 < v2975;
  struct StateG * v2990;
  if (v2995) {
    int * v2976 = v2972->pht;
    v2976[16] = 1;
    int v2978 = v2972->timer;
    int v2998 = v2978 + 15;
    v2972->timer = v2998;
    int * v2980 = v2972->saved_regs;
    int v2981 = v2980[18];
    int * v2982 = v2972->regs;
    v2982[18] = v2981;
    struct StateG * v2984 = slot_142(v2972);
    v2990 = v2984;
  } else {
    int * v2986 = v2972->pht;
    v2986[16] = 0;
    struct StateG * v2988 = slot_143(v2972);
    v2990 = v2988;
  }
  return v2990;
}

struct StateG * slot_248(struct StateG * v5282) {
  int v5283 = v5282->timer;
  int v5290 = v5283 + 1;
  v5282->timer = v5290;
  int * v5285 = v5282->regs;
  int v5286 = v5285[1];
  bool v5293 = v5286 == 156;
  ret_assert(v5293);
  struct StateG * v5288 = slot_252(v5282);
  return v5288;
}

struct StateG * slot_257(struct StateG * v5403) {
  int v5404 = v5403->timer;
  int v5410 = v5404 + 1;
  v5403->timer = v5410;
  int * v5406 = v5403->regs;
  v5406[1] = 164;
  struct StateG * v5408 = slot_261(v5403);
  return v5408;
}

struct StateG * slot_59(struct StateG * v1208) {
  int * v1209 = v1208->saved_regs;
  int * v1210 = v1208->regs;
  int v1211 = v1210[18];
  v1209[18] = v1211;
  int v1213 = v1208->timer;
  int v1223 = v1213 + 1;
  v1208->timer = v1223;
  int * v1215 = v1208->regs;
  v1215[18] = 1;
  struct StateG * v1217 = slot_67(v1208);
  return v1217;
}

struct StateG * slot_192(struct StateG * v4082) {
  int * v4083 = v4082->regs;
  int v4084 = v4083[16];
  int v4085 = v4083[17];
  bool v4105 = v4084 < v4085;
  struct StateG * v4100;
  if (v4105) {
    int * v4086 = v4082->pht;
    v4086[27] = 1;
    struct StateG * v4088 = slot_200(v4082);
    v4100 = v4088;
  } else {
    int * v4090 = v4082->pht;
    v4090[27] = 0;
    int v4092 = v4082->timer;
    int v4114 = v4092 + 15;
    v4082->timer = v4114;
    int * v4094 = v4082->saved_regs;
    int v4095 = v4094[18];
    int * v4096 = v4082->regs;
    v4096[18] = v4095;
    struct StateG * v4098 = slot_201(v4082);
    v4100 = v4098;
  }
  return v4100;
}

struct StateG * slot_40(struct StateG * v908) {
  int v909 = v908->timer;
  int v916 = v909 + 1;
  v908->timer = v916;
  int * v911 = v908->regs;
  int v912 = v911[1];
  bool v919 = v912 == 24;
  ret_assert(v919);
  struct StateG * v914 = slot_44(v908);
  return v914;
}

struct StateG * slot_48(struct StateG * v1016) {
  int v1017 = v1016->timer;
  int v1023 = v1017 + 1;
  v1016->timer = v1023;
  int * v1019 = v1016->regs;
  v1019[17] = 10;
  struct StateG * v1021 = slot_52(v1016);
  return v1021;
}

struct StateG * slot_77(struct StateG * v1678) {
  int v1679 = v1678->timer;
  int v1685 = v1679 + 1;
  v1678->timer = v1685;
  int * v1681 = v1678->regs;
  v1681[18] = 1;
  struct StateG * v1683 = slot_79(v1678);
  return v1683;
}

struct StateG * slot_85(struct StateG * v1784) {
  int v1785 = v1784->timer;
  int v1795 = v1785 + 1;
  v1784->timer = v1795;
  int * v1787 = v1784->pht;
  int v1788 = v1787[14];
  bool v1798 = !(v1788 == 0);
  struct StateG * v1793;
  if (v1798) {
    struct StateG * v1789 = slot_90(v1784);
    v1793 = v1789;
  } else {
    struct StateG * v1791 = slot_91(v1784);
    v1793 = v1791;
  }
  return v1793;
}

struct StateG * slot_75(struct StateG * v1662) {
  int v1663 = v1662->timer;
  int v1667 = v1663 + 1;
  v1662->timer = v1667;
  struct StateG * v1665 = slot_81(v1662);
  return v1665;
}

struct StateG * slot_72(struct StateG * v1628) {
  int v1629 = v1628->timer;
  int v1633 = v1629 + 1;
  v1628->timer = v1633;
  struct StateG * v1631 = slot_80(v1628);
  return v1631;
}

struct StateG * slot_119(struct StateG * v2520) {
  int v2521 = v2520->timer;
  int v2531 = v2521 + 1;
  v2520->timer = v2531;
  int * v2523 = v2520->pht;
  int v2524 = v2523[16];
  bool v2534 = !(v2524 == 0);
  struct StateG * v2529;
  if (v2534) {
    struct StateG * v2525 = slot_126(v2520);
    v2529 = v2525;
  } else {
    struct StateG * v2527 = slot_127(v2520);
    v2529 = v2527;
  }
  return v2529;
}

struct StateG * slot_71(struct StateG * v1588) {
  int * v1589 = v1588->regs;
  int v1590 = v1589[16];
  int v1591 = v1589[17];
  bool v1611 = v1590 < v1591;
  struct StateG * v1606;
  if (v1611) {
    int * v1592 = v1588->pht;
    v1592[8] = 1;
    int v1594 = v1588->timer;
    int v1615 = v1594 + 15;
    v1588->timer = v1615;
    int * v1596 = v1588->saved_regs;
    int v1597 = v1596[18];
    int * v1598 = v1588->regs;
    v1598[18] = v1597;
    struct StateG * v1600 = slot_78(v1588);
    v1606 = v1600;
  } else {
    int * v1602 = v1588->pht;
    v1602[8] = 0;
    struct StateG * v1604 = slot_79(v1588);
    v1606 = v1604;
  }
  return v1606;
}

struct StateG * slot_101(struct StateG * v2204) {
  int * v2205 = v2204->regs;
  int v2206 = v2205[16];
  int v2207 = v2205[17];
  bool v2227 = v2206 < v2207;
  struct StateG * v2222;
  if (v2227) {
    int * v2208 = v2204->pht;
    v2208[13] = 1;
    int v2210 = v2204->timer;
    int v2231 = v2210 + 15;
    v2204->timer = v2231;
    int * v2212 = v2204->saved_regs;
    int v2213 = v2212[18];
    int * v2214 = v2204->regs;
    v2214[18] = v2213;
    struct StateG * v2216 = slot_106(v2204);
    v2222 = v2216;
  } else {
    int * v2218 = v2204->pht;
    v2218[13] = 0;
    struct StateG * v2220 = slot_107(v2204);
    v2222 = v2220;
  }
  return v2222;
}

struct StateG * slot_276(struct StateG * v5734) {
  int * v5735 = v5734->regs;
  int v5736 = v5735[16];
  int v5737 = v5735[17];
  bool v5757 = v5736 >= v5737;
  struct StateG * v5752;
  if (v5757) {
    int * v5738 = v5734->pht;
    v5738[7] = 1;
    struct StateG * v5740 = slot_284(v5734);
    v5752 = v5740;
  } else {
    int * v5742 = v5734->pht;
    v5742[7] = 0;
    int v5744 = v5734->timer;
    int v5766 = v5744 + 15;
    v5734->timer = v5766;
    int * v5746 = v5734->saved_regs;
    int v5747 = v5746[19];
    int * v5748 = v5734->regs;
    v5748[19] = v5747;
    struct StateG * v5750 = slot_289(v5734);
    v5752 = v5750;
  }
  return v5752;
}

struct StateG * slot_108(struct StateG * v2366) {
  int v2367 = v2366->timer;
  int v2371 = v2367 + 1;
  v2366->timer = v2371;
  struct StateG * v2369 = slot_114(v2366);
  return v2369;
}

struct StateG * slot_116(struct StateG * v2460) {
  int v2461 = v2460->timer;
  int v2471 = v2461 + 1;
  v2460->timer = v2471;
  int * v2463 = v2460->pht;
  int v2464 = v2463[19];
  bool v2474 = !(v2464 == 0);
  struct StateG * v2469;
  if (v2474) {
    struct StateG * v2465 = slot_120(v2460);
    v2469 = v2465;
  } else {
    struct StateG * v2467 = slot_121(v2460);
    v2469 = v2467;
  }
  return v2469;
}

struct StateG * slot_93(struct StateG * v1944) {
  int * v1945 = v1944->saved_regs;
  int * v1946 = v1944->regs;
  int v1947 = v1946[18];
  v1945[18] = v1947;
  int v1949 = v1944->timer;
  int v1959 = v1949 + 1;
  v1944->timer = v1959;
  int * v1951 = v1944->regs;
  v1951[18] = 1;
  struct StateG * v1953 = slot_101(v1944);
  return v1953;
}

struct StateG * slot_266(struct StateG * v5534) {
  int v5535 = v5534->timer;
  int v5545 = v5535 + 1;
  v5534->timer = v5545;
  int * v5537 = v5534->pht;
  int v5538 = v5537[5];
  bool v5548 = !(v5538 == 0);
  struct StateG * v5543;
  if (v5548) {
    struct StateG * v5539 = slot_272(v5534);
    v5543 = v5539;
  } else {
    struct StateG * v5541 = slot_273(v5534);
    v5543 = v5541;
  }
  return v5543;
}

struct StateG * slot_88(struct StateG * v1844) {
  int * v1845 = v1844->saved_regs;
  int * v1846 = v1844->regs;
  int v1847 = v1846[18];
  v1845[18] = v1847;
  int v1849 = v1844->timer;
  int v1859 = v1849 + 1;
  v1844->timer = v1859;
  int * v1851 = v1844->regs;
  v1851[18] = 2;
  struct StateG * v1853 = slot_96(v1844);
  return v1853;
}

struct StateG * slot_96(struct StateG * v2004) {
  int * v2005 = v2004->regs;
  int v2006 = v2005[16];
  int v2007 = v2005[17];
  bool v2027 = v2006 < v2007;
  struct StateG * v2022;
  if (v2027) {
    int * v2008 = v2004->pht;
    v2008[15] = 1;
    struct StateG * v2010 = slot_104(v2004);
    v2022 = v2010;
  } else {
    int * v2012 = v2004->pht;
    v2012[15] = 0;
    int v2014 = v2004->timer;
    int v2036 = v2014 + 15;
    v2004->timer = v2036;
    int * v2016 = v2004->saved_regs;
    int v2017 = v2016[18];
    int * v2018 = v2004->regs;
    v2018[18] = v2017;
    struct StateG * v2020 = slot_105(v2004);
    v2022 = v2020;
  }
  return v2022;
}

struct StateG * slot_215(struct StateG * v4577) {
  int v4578 = v4577->timer;
  int v4584 = v4578 + 1;
  v4577->timer = v4584;
  int * v4580 = v4577->regs;
  v4580[1] = 156;
  struct StateG * v4582 = slot_219(v4577);
  return v4582;
}

struct StateG * slot_234(struct StateG * v4962) {
  int * v4963 = v4962->regs;
  int v4964 = v4963[16];
  int v4965 = v4963[17];
  bool v4985 = v4964 < v4965;
  struct StateG * v4980;
  if (v4985) {
    int * v4966 = v4962->pht;
    v4966[2] = 1;
    struct StateG * v4968 = slot_244(v4962);
    v4980 = v4968;
  } else {
    int * v4970 = v4962->pht;
    v4970[2] = 0;
    int v4972 = v4962->timer;
    int v4994 = v4972 + 15;
    v4962->timer = v4994;
    int * v4974 = v4962->saved_regs;
    int v4975 = v4974[18];
    int * v4976 = v4962->regs;
    v4976[18] = v4975;
    struct StateG * v4978 = slot_245(v4962);
    v4980 = v4978;
  }
  return v4980;
}

struct StateG * slot_45(struct StateG * v977) {
  int v978 = v977->timer;
  int v984 = v978 + 1;
  v977->timer = v984;
  int * v980 = v977->regs;
  v980[16] = 20;
  struct StateG * v982 = slot_49(v977);
  return v982;
}

struct StateG * slot_218(struct StateG * v4616) {
  int v4617 = v4616->timer;
  int v4623 = v4617 + 1;
  v4616->timer = v4623;
  int * v4619 = v4616->regs;
  v4619[17] = 10;
  struct StateG * v4621 = slot_222(v4616);
  return v4621;
}

struct StateG * slot_220(struct StateG * v4642) {
  int v4643 = v4642->timer;
  int v4653 = v4643 + 1;
  v4642->timer = v4653;
  int * v4645 = v4642->pht;
  int v4646 = v4645[3];
  bool v4656 = !(v4646 == 0);
  struct StateG * v4651;
  if (v4656) {
    struct StateG * v4647 = slot_224(v4642);
    v4651 = v4647;
  } else {
    struct StateG * v4649 = slot_225(v4642);
    v4651 = v4649;
  }
  return v4651;
}

struct StateG * slot_134(struct StateG * v2934) {
  int * v2935 = v2934->regs;
  int v2936 = v2935[16];
  int v2937 = v2935[17];
  bool v2957 = v2936 < v2937;
  struct StateG * v2952;
  if (v2957) {
    int * v2938 = v2934->pht;
    v2938[16] = 1;
    struct StateG * v2940 = slot_140(v2934);
    v2952 = v2940;
  } else {
    int * v2942 = v2934->pht;
    v2942[16] = 0;
    int v2944 = v2934->timer;
    int v2964 = v2944 + 15;
    v2934->timer = v2964;
    int * v2946 = v2934->saved_regs;
    int v2947 = v2946[18];
    int * v2948 = v2934->regs;
    v2948[18] = v2947;
    struct StateG * v2950 = slot_141(v2934);
    v2952 = v2950;
  }
  return v2952;
}

struct StateG * slot_175(struct StateG * v3782) {
  int v3783 = v3782->timer;
  int v3787 = v3783 + 1;
  v3782->timer = v3787;
  struct StateG * v3785 = slot_179(v3782);
  return v3785;
}

struct StateG * slot_273(struct StateG * v5674) {
  int * v5675 = v5674->saved_regs;
  int * v5676 = v5674->regs;
  int v5677 = v5676[19];
  v5675[19] = v5677;
  int v5679 = v5674->timer;
  int v5689 = v5679 + 1;
  v5674->timer = v5689;
  int * v5681 = v5674->regs;
  v5681[19] = 1;
  struct StateG * v5683 = slot_281(v5674);
  return v5683;
}

struct StateG * slot_69(struct StateG * v1508) {
  int * v1509 = v1508->regs;
  int v1510 = v1509[16];
  int v1511 = v1509[17];
  bool v1531 = v1510 < v1511;
  struct StateG * v1526;
  if (v1531) {
    int * v1512 = v1508->pht;
    v1512[9] = 1;
    int v1514 = v1508->timer;
    int v1535 = v1514 + 15;
    v1508->timer = v1535;
    int * v1516 = v1508->saved_regs;
    int v1517 = v1516[18];
    int * v1518 = v1508->regs;
    v1518[18] = v1517;
    struct StateG * v1520 = slot_74(v1508);
    v1526 = v1520;
  } else {
    int * v1522 = v1508->pht;
    v1522[9] = 0;
    struct StateG * v1524 = slot_75(v1508);
    v1526 = v1524;
  }
  return v1526;
}

struct StateG * slot_202(struct StateG * v4423) {
  int v4424 = v4423->timer;
  int v4430 = v4424 + 1;
  v4423->timer = v4430;
  int * v4426 = v4423->regs;
  v4426[18] = 2;
  struct StateG * v4428 = slot_200(v4423);
  return v4428;
}

struct StateG * slot_230(struct StateG * v4842) {
  int * v4843 = v4842->saved_regs;
  int * v4844 = v4842->regs;
  int v4845 = v4844[18];
  v4843[18] = v4845;
  int v4847 = v4842->timer;
  int v4857 = v4847 + 1;
  v4842->timer = v4857;
  int * v4849 = v4842->regs;
  v4849[18] = 2;
  struct StateG * v4851 = slot_238(v4842);
  return v4851;
}

struct StateG * slot_188(struct StateG * v4002) {
  int * v4003 = v4002->saved_regs;
  int * v4004 = v4002->regs;
  int v4005 = v4004[18];
  v4003[18] = v4005;
  int v4007 = v4002->timer;
  int v4017 = v4007 + 1;
  v4002->timer = v4017;
  int * v4009 = v4002->regs;
  v4009[18] = 2;
  struct StateG * v4011 = slot_196(v4002);
  return v4011;
}

struct StateG * slot_138(struct StateG * v3031) {
  int v3032 = v3031->timer;
  int v3038 = v3032 + 1;
  v3031->timer = v3038;
  int * v3034 = v3031->regs;
  v3034[18] = 2;
  struct StateG * v3036 = slot_136(v3031);
  return v3036;
}

struct StateG * slot_186(struct StateG * v3962) {
  int * v3963 = v3962->saved_regs;
  int * v3964 = v3962->regs;
  int v3965 = v3964[18];
  v3963[18] = v3965;
  int v3967 = v3962->timer;
  int v3977 = v3967 + 1;
  v3962->timer = v3977;
  int * v3969 = v3962->regs;
  v3969[18] = 2;
  struct StateG * v3971 = slot_194(v3962);
  return v3971;
}

struct StateG * slot_102(struct StateG * v2244) {
  int * v2245 = v2244->regs;
  int v2246 = v2245[16];
  int v2247 = v2245[17];
  bool v2267 = v2246 < v2247;
  struct StateG * v2262;
  if (v2267) {
    int * v2248 = v2244->pht;
    v2248[12] = 1;
    struct StateG * v2250 = slot_108(v2244);
    v2262 = v2250;
  } else {
    int * v2252 = v2244->pht;
    v2252[12] = 0;
    int v2254 = v2244->timer;
    int v2276 = v2254 + 15;
    v2244->timer = v2276;
    int * v2256 = v2244->saved_regs;
    int v2257 = v2256[18];
    int * v2258 = v2244->regs;
    v2258[18] = v2257;
    struct StateG * v2260 = slot_109(v2244);
    v2262 = v2260;
  }
  return v2262;
}

struct StateG * slot_145(struct StateG * v3107) {
  int v3108 = v3107->timer;
  int v3114 = v3108 + 1;
  v3107->timer = v3114;
  int * v3110 = v3107->regs;
  v3110[17] = 10;
  struct StateG * v3112 = slot_149(v3107);
  return v3112;
}

struct StateG * slot_110(struct StateG * v2387) {
  int v2388 = v2387->timer;
  int v2394 = v2388 + 1;
  v2387->timer = v2394;
  int * v2390 = v2387->regs;
  v2390[18] = 2;
  struct StateG * v2392 = slot_108(v2387);
  return v2392;
}

struct StateG * slot_196(struct StateG * v4242) {
  int * v4243 = v4242->regs;
  int v4244 = v4243[16];
  int v4245 = v4243[17];
  bool v4265 = v4244 < v4245;
  struct StateG * v4260;
  if (v4265) {
    int * v4246 = v4242->pht;
    v4246[25] = 1;
    struct StateG * v4248 = slot_200(v4242);
    v4260 = v4248;
  } else {
    int * v4250 = v4242->pht;
    v4250[25] = 0;
    int v4252 = v4242->timer;
    int v4274 = v4252 + 15;
    v4242->timer = v4274;
    int * v4254 = v4242->saved_regs;
    int v4255 = v4254[18];
    int * v4256 = v4242->regs;
    v4256[18] = v4255;
    struct StateG * v4258 = slot_201(v4242);
    v4260 = v4258;
  }
  return v4260;
}

struct StateG * slot_208(struct StateG * v4486) {
  int v4487 = v4486->timer;
  int v4493 = v4487 + 1;
  v4486->timer = v4493;
  int * v4489 = v4486->regs;
  v4489[1] = 148;
  struct StateG * v4491 = slot_212(v4486);
  return v4491;
}

struct StateG * slot_172(struct StateG * v3748) {
  int v3749 = v3748->timer;
  int v3753 = v3749 + 1;
  v3748->timer = v3753;
  struct StateG * v3751 = slot_178(v3748);
  return v3751;
}

struct StateG * slot_131(struct StateG * v2819) {
  int * v2820 = v2819->regs;
  int v2821 = v2820[16];
  int v2822 = v2820[17];
  bool v2842 = v2821 < v2822;
  struct StateG * v2837;
  if (v2842) {
    int * v2823 = v2819->pht;
    v2823[18] = 1;
    int v2825 = v2819->timer;
    int v2846 = v2825 + 15;
    v2819->timer = v2846;
    int * v2827 = v2819->saved_regs;
    int v2828 = v2827[18];
    int * v2829 = v2819->regs;
    v2829[18] = v2828;
    struct StateG * v2831 = slot_142(v2819);
    v2837 = v2831;
  } else {
    int * v2833 = v2819->pht;
    v2833[18] = 0;
    struct StateG * v2835 = slot_143(v2819);
    v2837 = v2835;
  }
  return v2837;
}

struct StateG * slot_8(struct StateG * v318) {
  int * v319 = v318->regs;
  int v320 = v319[16];
  int v321 = v319[17];
  bool v341 = v320 < v321;
  struct StateG * v336;
  if (v341) {
    int * v322 = v318->pht;
    v322[0] = 1;
    struct StateG * v324 = slot_10(v318);
    v336 = v324;
  } else {
    int * v326 = v318->pht;
    v326[0] = 0;
    int v328 = v318->timer;
    int v349 = v328 + 15;
    v318->timer = v349;
    int * v330 = v318->saved_regs;
    int v331 = v330[18];
    int * v332 = v318->regs;
    v332[18] = v331;
    struct StateG * v334 = slot_11(v318);
    v336 = v334;
  }
  return v336;
}

struct StateG * slot_180(struct StateG * v3842) {
  int v3843 = v3842->timer;
  int v3853 = v3843 + 1;
  v3842->timer = v3853;
  int * v3845 = v3842->pht;
  int v3846 = v3845[27];
  bool v3856 = !(v3846 == 0);
  struct StateG * v3851;
  if (v3856) {
    struct StateG * v3847 = slot_184(v3842);
    v3851 = v3847;
  } else {
    struct StateG * v3849 = slot_185(v3842);
    v3851 = v3849;
  }
  return v3851;
}

struct StateG * slot_281(struct StateG * v5934) {
  int * v5935 = v5934->regs;
  int v5936 = v5935[16];
  int v5937 = v5935[17];
  bool v5957 = v5936 >= v5937;
  struct StateG * v5952;
  if (v5957) {
    int * v5938 = v5934->pht;
    v5938[5] = 1;
    int v5940 = v5934->timer;
    int v5961 = v5940 + 15;
    v5934->timer = v5961;
    int * v5942 = v5934->saved_regs;
    int v5943 = v5942[19];
    int * v5944 = v5934->regs;
    v5944[19] = v5943;
    struct StateG * v5946 = slot_286(v5934);
    v5952 = v5946;
  } else {
    int * v5948 = v5934->pht;
    v5948[5] = 0;
    struct StateG * v5950 = slot_284(v5934);
    v5952 = v5950;
  }
  return v5952;
}

struct StateG * slot_203(struct StateG * v4436) {
  int v4437 = v4436->timer;
  int v4441 = v4437 + 1;
  v4436->timer = v4441;
  struct StateG * v4439 = slot_209(v4436);
  return v4439;
}

struct StateG * slot_190(struct StateG * v4042) {
  int * v4043 = v4042->saved_regs;
  int * v4044 = v4042->regs;
  int v4045 = v4044[18];
  v4043[18] = v4045;
  int v4047 = v4042->timer;
  int v4057 = v4047 + 1;
  v4042->timer = v4057;
  int * v4049 = v4042->regs;
  v4049[18] = 2;
  struct StateG * v4051 = slot_198(v4042);
  return v4051;
}

struct StateG * slot_157(struct StateG * v3326) {
  int * v3327 = v3326->saved_regs;
  int * v3328 = v3326->regs;
  int v3329 = v3328[18];
  v3327[18] = v3329;
  int v3331 = v3326->timer;
  int v3341 = v3331 + 1;
  v3326->timer = v3341;
  int * v3333 = v3326->regs;
  v3333[18] = 1;
  struct StateG * v3335 = slot_165(v3326);
  return v3335;
}

struct StateG * slot_242(struct StateG * v5219) {
  int v5220 = v5219->timer;
  int v5226 = v5220 + 1;
  v5219->timer = v5226;
  int * v5222 = v5219->regs;
  v5222[18] = 2;
  struct StateG * v5224 = slot_240(v5219);
  return v5224;
}

struct StateG * slot_200(struct StateG * v4402) {
  int v4403 = v4402->timer;
  int v4407 = v4403 + 1;
  v4402->timer = v4407;
  struct StateG * v4405 = slot_208(v4402);
  return v4405;
}

struct StateG * slot_243(struct StateG * v5232) {
  int v5233 = v5232->timer;
  int v5237 = v5233 + 1;
  v5232->timer = v5237;
  struct StateG * v5235 = slot_249(v5232);
  return v5235;
}

struct StateG * slot_173(struct StateG * v3756) {
  int v3757 = v3756->timer;
  int v3763 = v3757 + 1;
  v3756->timer = v3763;
  int * v3759 = v3756->regs;
  v3759[18] = 1;
  struct StateG * v3761 = slot_175(v3756);
  return v3761;
}

struct StateG * slot_149(struct StateG * v3166) {
  int v3167 = v3166->timer;
  int v3177 = v3167 + 1;
  v3166->timer = v3177;
  int * v3169 = v3166->pht;
  int v3170 = v3169[22];
  bool v3180 = !(v3170 == 0);
  struct StateG * v3175;
  if (v3180) {
    struct StateG * v3171 = slot_154(v3166);
    v3175 = v3171;
  } else {
    struct StateG * v3173 = slot_155(v3166);
    v3175 = v3173;
  }
  return v3175;
}

struct StateG * slot_5(struct StateG * v258) {
  int v259 = v258->timer;
  int v269 = v259 + 1;
  v258->timer = v269;
  int * v261 = v258->pht;
  int v262 = v261[0];
  bool v272 = !(v262 == 0);
  struct StateG * v267;
  if (v272) {
    struct StateG * v263 = slot_6(v258);
    v267 = v263;
  } else {
    struct StateG * v265 = slot_7(v258);
    v267 = v265;
  }
  return v267;
}

struct StateG * slot_104(struct StateG * v2324) {
  int v2325 = v2324->timer;
  int v2329 = v2325 + 1;
  v2324->timer = v2329;
  struct StateG * v2327 = slot_112(v2324);
  return v2327;
}

struct StateG * slot_235(struct StateG * v5002) {
  int * v5003 = v5002->regs;
  int v5004 = v5003[16];
  int v5005 = v5003[17];
  bool v5025 = v5004 < v5005;
  struct StateG * v5020;
  if (v5025) {
    int * v5006 = v5002->pht;
    v5006[2] = 1;
    int v5008 = v5002->timer;
    int v5029 = v5008 + 15;
    v5002->timer = v5029;
    int * v5010 = v5002->saved_regs;
    int v5011 = v5010[18];
    int * v5012 = v5002->regs;
    v5012[18] = v5011;
    struct StateG * v5014 = slot_246(v5002);
    v5020 = v5014;
  } else {
    int * v5016 = v5002->pht;
    v5016[2] = 0;
    struct StateG * v5018 = slot_247(v5002);
    v5020 = v5018;
  }
  return v5020;
}

struct StateG * slot_275(struct StateG * v5714) {
  int * v5715 = v5714->saved_regs;
  int * v5716 = v5714->regs;
  int v5717 = v5716[19];
  v5715[19] = v5717;
  int v5719 = v5714->timer;
  int v5729 = v5719 + 1;
  v5714->timer = v5729;
  int * v5721 = v5714->regs;
  v5721[19] = 1;
  struct StateG * v5723 = slot_283(v5714);
  return v5723;
}

struct StateG * slot_54(struct StateG * v1108) {
  int v1109 = v1108->timer;
  int v1119 = v1109 + 1;
  v1108->timer = v1119;
  int * v1111 = v1108->pht;
  int v1112 = v1111[9];
  bool v1122 = !(v1112 == 0);
  struct StateG * v1117;
  if (v1122) {
    struct StateG * v1113 = slot_60(v1108);
    v1117 = v1113;
  } else {
    struct StateG * v1115 = slot_61(v1108);
    v1117 = v1115;
  }
  return v1117;
}

struct StateG * slot_26(struct StateG * v624) {
  int * v625 = v624->saved_regs;
  int * v626 = v624->regs;
  int v627 = v626[19];
  v625[19] = v627;
  int v629 = v624->timer;
  int v639 = v629 + 1;
  v624->timer = v639;
  int * v631 = v624->regs;
  v631[19] = 2;
  struct StateG * v633 = slot_30(v624);
  return v633;
}

struct StateG * slot_206(struct StateG * v4465) {
  int v4466 = v4465->timer;
  int v4472 = v4466 + 1;
  v4465->timer = v4472;
  int * v4468 = v4465->regs;
  v4468[18] = 2;
  struct StateG * v4470 = slot_204(v4465);
  return v4470;
}

struct StateG * slot_227(struct StateG * v4782) {
  int * v4783 = v4782->saved_regs;
  int * v4784 = v4782->regs;
  int v4785 = v4784[18];
  v4783[18] = v4785;
  int v4787 = v4782->timer;
  int v4797 = v4787 + 1;
  v4782->timer = v4797;
  int * v4789 = v4782->regs;
  v4789[18] = 1;
  struct StateG * v4791 = slot_235(v4782);
  return v4791;
}

struct StateG * slot_169(struct StateG * v3714) {
  int v3715 = v3714->timer;
  int v3721 = v3715 + 1;
  v3714->timer = v3721;
  int * v3717 = v3714->regs;
  v3717[18] = 1;
  struct StateG * v3719 = slot_171(v3714);
  return v3719;
}

struct StateG * slot_253(struct StateG * v5351) {
  int v5352 = v5351->timer;
  int v5358 = v5352 + 1;
  v5351->timer = v5358;
  int * v5354 = v5351->regs;
  v5354[1] = 156;
  struct StateG * v5356 = slot_257(v5351);
  return v5356;
}

struct StateG * slot_64(struct StateG * v1308) {
  int * v1309 = v1308->regs;
  int v1310 = v1309[16];
  int v1311 = v1309[17];
  bool v1331 = v1310 < v1311;
  struct StateG * v1326;
  if (v1331) {
    int * v1312 = v1308->pht;
    v1312[11] = 1;
    struct StateG * v1314 = slot_72(v1308);
    v1326 = v1314;
  } else {
    int * v1316 = v1308->pht;
    v1316[11] = 0;
    int v1318 = v1308->timer;
    int v1340 = v1318 + 15;
    v1308->timer = v1340;
    int * v1320 = v1308->saved_regs;
    int v1321 = v1320[18];
    int * v1322 = v1308->regs;
    v1322[18] = v1321;
    struct StateG * v1324 = slot_73(v1308);
    v1326 = v1324;
  }
  return v1326;
}

struct StateG * slot_170(struct StateG * v3727) {
  int v3728 = v3727->timer;
  int v3734 = v3728 + 1;
  v3727->timer = v3734;
  int * v3730 = v3727->regs;
  v3730[18] = 2;
  struct StateG * v3732 = slot_168(v3727);
  return v3732;
}

struct StateG * slot_14(struct StateG * v438) {
  int v439 = v438->timer;
  int v446 = v439 + 1;
  v438->timer = v446;
  int * v441 = v438->regs;
  int v442 = v441[1];
  bool v449 = v442 == 16;
  ret_assert(v449);
  struct StateG * v444 = slot_16(v438);
  return v444;
}

struct StateG * slot_53(struct StateG * v1088) {
  int v1089 = v1088->timer;
  int v1099 = v1089 + 1;
  v1088->timer = v1099;
  int * v1091 = v1088->pht;
  int v1092 = v1091[10];
  bool v1102 = !(v1092 == 0);
  struct StateG * v1097;
  if (v1102) {
    struct StateG * v1093 = slot_58(v1088);
    v1097 = v1093;
  } else {
    struct StateG * v1095 = slot_59(v1088);
    v1097 = v1095;
  }
  return v1097;
}

struct StateG * slot_80(struct StateG * v1712) {
  int v1713 = v1712->timer;
  int v1719 = v1713 + 1;
  v1712->timer = v1719;
  int * v1715 = v1712->regs;
  v1715[17] = 10;
  struct StateG * v1717 = slot_84(v1712);
  return v1717;
}

struct StateG * slot_44(struct StateG * v964) {
  int v965 = v964->timer;
  int v971 = v965 + 1;
  v964->timer = v971;
  int * v967 = v964->regs;
  v967[16] = 20;
  struct StateG * v969 = slot_48(v964);
  return v969;
}

struct StateG * slot_261(struct StateG * v5455) {
  int v5456 = v5455->timer;
  int v5462 = v5456 + 1;
  v5455->timer = v5462;
  int * v5458 = v5455->regs;
  v5458[17] = 10;
  struct StateG * v5460 = slot_265(v5455);
  return v5460;
}

struct StateG * slot_137(struct StateG * v3018) {
  int v3019 = v3018->timer;
  int v3025 = v3019 + 1;
  v3018->timer = v3025;
  int * v3021 = v3018->regs;
  v3021[18] = 1;
  struct StateG * v3023 = slot_139(v3018);
  return v3023;
}

struct StateG * slot_122(struct StateG * v2580) {
  int * v2581 = v2580->saved_regs;
  int * v2582 = v2580->regs;
  int v2583 = v2582[18];
  v2581[18] = v2583;
  int v2585 = v2580->timer;
  int v2595 = v2585 + 1;
  v2580->timer = v2595;
  int * v2587 = v2580->regs;
  v2587[18] = 2;
  struct StateG * v2589 = slot_130(v2580);
  return v2589;
}

struct StateG * slot_99(struct StateG * v2124) {
  int * v2125 = v2124->regs;
  int v2126 = v2125[16];
  int v2127 = v2125[17];
  bool v2147 = v2126 < v2127;
  struct StateG * v2142;
  if (v2147) {
    int * v2128 = v2124->pht;
    v2128[14] = 1;
    int v2130 = v2124->timer;
    int v2151 = v2130 + 15;
    v2124->timer = v2151;
    int * v2132 = v2124->saved_regs;
    int v2133 = v2132[18];
    int * v2134 = v2124->regs;
    v2134[18] = v2133;
    struct StateG * v2136 = slot_110(v2124);
    v2142 = v2136;
  } else {
    int * v2138 = v2124->pht;
    v2138[14] = 0;
    struct StateG * v2140 = slot_111(v2124);
    v2142 = v2140;
  }
  return v2142;
}

struct StateG * slot_179(struct StateG * v3829) {
  int v3830 = v3829->timer;
  int v3836 = v3830 + 1;
  v3829->timer = v3836;
  int * v3832 = v3829->regs;
  v3832[17] = 10;
  struct StateG * v3834 = slot_183(v3829);
  return v3834;
}

struct StateG * slot_219(struct StateG * v4629) {
  int v4630 = v4629->timer;
  int v4636 = v4630 + 1;
  v4629->timer = v4636;
  int * v4632 = v4629->regs;
  v4632[17] = 10;
  struct StateG * v4634 = slot_223(v4629);
  return v4634;
}

struct StateG * slot_36(struct StateG * v866) {
  int v867 = v866->timer;
  int v871 = v867 + 1;
  v866->timer = v871;
  struct StateG * v869 = slot_42(v866);
  return v869;
}

struct StateG * slot_57(struct StateG * v1168) {
  int * v1169 = v1168->saved_regs;
  int * v1170 = v1168->regs;
  int v1171 = v1170[18];
  v1169[18] = v1171;
  int v1173 = v1168->timer;
  int v1183 = v1173 + 1;
  v1168->timer = v1183;
  int * v1175 = v1168->regs;
  v1175[18] = 1;
  struct StateG * v1177 = slot_65(v1168);
  return v1177;
}

struct StateG * slot_62(struct StateG * v1268) {
  int * v1269 = v1268->saved_regs;
  int * v1270 = v1268->regs;
  int v1271 = v1270[18];
  v1269[18] = v1271;
  int v1273 = v1268->timer;
  int v1283 = v1273 + 1;
  v1268->timer = v1283;
  int * v1275 = v1268->regs;
  v1275[18] = 2;
  struct StateG * v1277 = slot_70(v1268);
  return v1277;
}

struct StateG * slot_22(struct StateG * v544) {
  int v545 = v544->timer;
  int v555 = v545 + 1;
  v544->timer = v555;
  int * v547 = v544->pht;
  int v548 = v547[5];
  bool v558 = !(v548 == 0);
  struct StateG * v553;
  if (v558) {
    struct StateG * v549 = slot_24(v544);
    v553 = v549;
  } else {
    struct StateG * v551 = slot_25(v544);
    v553 = v551;
  }
  return v553;
}

struct StateG * slot_139(struct StateG * v3044) {
  int v3045 = v3044->timer;
  int v3049 = v3045 + 1;
  v3044->timer = v3049;
  struct StateG * v3047 = slot_145(v3044);
  return v3047;
}

struct StateG * slot_221(struct StateG * v4662) {
  int v4663 = v4662->timer;
  int v4673 = v4663 + 1;
  v4662->timer = v4673;
  int * v4665 = v4662->pht;
  int v4666 = v4665[2];
  bool v4676 = !(v4666 == 0);
  struct StateG * v4671;
  if (v4676) {
    struct StateG * v4667 = slot_226(v4662);
    v4671 = v4667;
  } else {
    struct StateG * v4669 = slot_227(v4662);
    v4671 = v4669;
  }
  return v4671;
}

struct StateG * slot_23(struct StateG * v564) {
  int v565 = v564->timer;
  int v575 = v565 + 1;
  v564->timer = v575;
  int * v567 = v564->pht;
  int v568 = v567[4];
  bool v578 = !(v568 == 0);
  struct StateG * v573;
  if (v578) {
    struct StateG * v569 = slot_26(v564);
    v573 = v569;
  } else {
    struct StateG * v571 = slot_27(v564);
    v573 = v571;
  }
  return v573;
}

struct StateG * slot_153(struct StateG * v3246) {
  int * v3247 = v3246->saved_regs;
  int * v3248 = v3246->regs;
  int v3249 = v3248[18];
  v3247[18] = v3249;
  int v3251 = v3246->timer;
  int v3261 = v3251 + 1;
  v3246->timer = v3261;
  int * v3253 = v3246->regs;
  v3253[18] = 1;
  struct StateG * v3255 = slot_161(v3246);
  return v3255;
}

struct StateG * slot_2(struct StateG * v219) {
  int v220 = v219->timer;
  int v226 = v220 + 1;
  v219->timer = v226;
  int * v222 = v219->regs;
  v222[1] = 8;
  struct StateG * v224 = slot_3(v219);
  return v224;
}

struct StateG * slot_86(struct StateG * v1804) {
  int v1805 = v1804->timer;
  int v1815 = v1805 + 1;
  v1804->timer = v1815;
  int * v1807 = v1804->pht;
  int v1808 = v1807[13];
  bool v1818 = !(v1808 == 0);
  struct StateG * v1813;
  if (v1818) {
    struct StateG * v1809 = slot_92(v1804);
    v1813 = v1809;
  } else {
    struct StateG * v1811 = slot_93(v1804);
    v1813 = v1811;
  }
  return v1813;
}

struct StateG * slot_129(struct StateG * v2740) {
  int * v2741 = v2740->regs;
  int v2742 = v2741[16];
  int v2743 = v2741[17];
  bool v2763 = v2742 < v2743;
  struct StateG * v2758;
  if (v2763) {
    int * v2744 = v2740->pht;
    v2744[19] = 1;
    int v2746 = v2740->timer;
    int v2767 = v2746 + 15;
    v2740->timer = v2767;
    int * v2748 = v2740->saved_regs;
    int v2749 = v2748[18];
    int * v2750 = v2740->regs;
    v2750[18] = v2749;
    struct StateG * v2752 = slot_138(v2740);
    v2758 = v2752;
  } else {
    int * v2754 = v2740->pht;
    v2754[19] = 0;
    struct StateG * v2756 = slot_139(v2740);
    v2758 = v2756;
  }
  return v2758;
}

struct StateG * slot_158(struct StateG * v3346) {
  int * v3347 = v3346->saved_regs;
  int * v3348 = v3346->regs;
  int v3349 = v3348[18];
  v3347[18] = v3349;
  int v3351 = v3346->timer;
  int v3361 = v3351 + 1;
  v3346->timer = v3361;
  int * v3353 = v3346->regs;
  v3353[18] = 2;
  struct StateG * v3355 = slot_166(v3346);
  return v3355;
}

struct StateG * slot_279(struct StateG * v5854) {
  int * v5855 = v5854->regs;
  int v5856 = v5855[16];
  int v5857 = v5855[17];
  bool v5877 = v5856 >= v5857;
  struct StateG * v5872;
  if (v5877) {
    int * v5858 = v5854->pht;
    v5858[6] = 1;
    int v5860 = v5854->timer;
    int v5881 = v5860 + 15;
    v5854->timer = v5881;
    int * v5862 = v5854->saved_regs;
    int v5863 = v5862[19];
    int * v5864 = v5854->regs;
    v5864[19] = v5863;
    struct StateG * v5866 = slot_286(v5854);
    v5872 = v5866;
  } else {
    int * v5868 = v5854->pht;
    v5868[6] = 0;
    struct StateG * v5870 = slot_284(v5854);
    v5872 = v5870;
  }
  return v5872;
}

struct StateG * slot_100(struct StateG * v2164) {
  int * v2165 = v2164->regs;
  int v2166 = v2165[16];
  int v2167 = v2165[17];
  bool v2187 = v2166 < v2167;
  struct StateG * v2182;
  if (v2187) {
    int * v2168 = v2164->pht;
    v2168[13] = 1;
    struct StateG * v2170 = slot_104(v2164);
    v2182 = v2170;
  } else {
    int * v2172 = v2164->pht;
    v2172[13] = 0;
    int v2174 = v2164->timer;
    int v2196 = v2174 + 15;
    v2164->timer = v2196;
    int * v2176 = v2164->saved_regs;
    int v2177 = v2176[18];
    int * v2178 = v2164->regs;
    v2178[18] = v2177;
    struct StateG * v2180 = slot_105(v2164);
    v2182 = v2180;
  }
  return v2182;
}

struct StateG * slot_271(struct StateG * v5634) {
  int * v5635 = v5634->saved_regs;
  int * v5636 = v5634->regs;
  int v5637 = v5636[19];
  v5635[19] = v5637;
  int v5639 = v5634->timer;
  int v5649 = v5639 + 1;
  v5634->timer = v5649;
  int * v5641 = v5634->regs;
  v5641[19] = 1;
  struct StateG * v5643 = slot_279(v5634);
  return v5643;
}

struct StateG * slot_127(struct StateG * v2680) {
  int * v2681 = v2680->saved_regs;
  int * v2682 = v2680->regs;
  int v2683 = v2682[18];
  v2681[18] = v2683;
  int v2685 = v2680->timer;
  int v2695 = v2685 + 1;
  v2680->timer = v2695;
  int * v2687 = v2680->regs;
  v2687[18] = 1;
  struct StateG * v2689 = slot_135(v2680);
  return v2689;
}

struct StateG * slot_217(struct StateG * v4603) {
  int v4604 = v4603->timer;
  int v4610 = v4604 + 1;
  v4603->timer = v4610;
  int * v4606 = v4603->regs;
  v4606[17] = 10;
  struct StateG * v4608 = slot_221(v4603);
  return v4608;
}

struct StateG * slot_13(struct StateG * v430) {
  int v431 = v430->timer;
  int v435 = v431 + 1;
  v430->timer = v435;
  struct StateG * v433 = slot_15(v430);
  return v433;
}

struct StateG * slot_111(struct StateG * v2400) {
  int v2401 = v2400->timer;
  int v2405 = v2401 + 1;
  v2400->timer = v2405;
  struct StateG * v2403 = slot_115(v2400);
  return v2403;
}

struct StateG * slot_109(struct StateG * v2374) {
  int v2375 = v2374->timer;
  int v2381 = v2375 + 1;
  v2374->timer = v2381;
  int * v2377 = v2374->regs;
  v2377[18] = 1;
  struct StateG * v2379 = slot_111(v2374);
  return v2379;
}

struct StateG * slot_174(struct StateG * v3769) {
  int v3770 = v3769->timer;
  int v3776 = v3770 + 1;
  v3769->timer = v3776;
  int * v3772 = v3769->regs;
  v3772[18] = 2;
  struct StateG * v3774 = slot_172(v3769);
  return v3774;
}

struct StateG * slot_147(struct StateG * v3133) {
  int v3134 = v3133->timer;
  int v3140 = v3134 + 1;
  v3133->timer = v3140;
  int * v3136 = v3133->regs;
  v3136[17] = 10;
  struct StateG * v3138 = slot_151(v3133);
  return v3138;
}

struct StateG * slot_42(struct StateG * v936) {
  int v937 = v936->timer;
  int v944 = v937 + 1;
  v936->timer = v944;
  int * v939 = v936->regs;
  int v940 = v939[1];
  bool v947 = v940 == 24;
  ret_assert(v947);
  struct StateG * v942 = slot_46(v936);
  return v942;
}

struct StateG * slot_224(struct StateG * v4722) {
  int * v4723 = v4722->saved_regs;
  int * v4724 = v4722->regs;
  int v4725 = v4724[18];
  v4723[18] = v4725;
  int v4727 = v4722->timer;
  int v4737 = v4727 + 1;
  v4722->timer = v4737;
  int * v4729 = v4722->regs;
  v4729[18] = 2;
  struct StateG * v4731 = slot_232(v4722);
  return v4731;
}

struct StateG * slot_163(struct StateG * v3506) {
  int * v3507 = v3506->regs;
  int v3508 = v3507[16];
  int v3509 = v3507[17];
  bool v3529 = v3508 < v3509;
  struct StateG * v3524;
  if (v3529) {
    int * v3510 = v3506->pht;
    v3510[22] = 1;
    int v3512 = v3506->timer;
    int v3533 = v3512 + 15;
    v3506->timer = v3533;
    int * v3514 = v3506->saved_regs;
    int v3515 = v3514[18];
    int * v3516 = v3506->regs;
    v3516[18] = v3515;
    struct StateG * v3518 = slot_174(v3506);
    v3524 = v3518;
  } else {
    int * v3520 = v3506->pht;
    v3520[22] = 0;
    struct StateG * v3522 = slot_175(v3506);
    v3524 = v3522;
  }
  return v3524;
}

struct StateG * slot_184(struct StateG * v3922) {
  int * v3923 = v3922->saved_regs;
  int * v3924 = v3922->regs;
  int v3925 = v3924[18];
  v3923[18] = v3925;
  int v3927 = v3922->timer;
  int v3937 = v3927 + 1;
  v3922->timer = v3937;
  int * v3929 = v3922->regs;
  v3929[18] = 2;
  struct StateG * v3931 = slot_192(v3922);
  return v3931;
}

struct StateG * slot_204(struct StateG * v4444) {
  int v4445 = v4444->timer;
  int v4449 = v4445 + 1;
  v4444->timer = v4449;
  struct StateG * v4447 = slot_210(v4444);
  return v4447;
}

struct StateG * slot_194(struct StateG * v4162) {
  int * v4163 = v4162->regs;
  int v4164 = v4163[16];
  int v4165 = v4163[17];
  bool v4185 = v4164 < v4165;
  struct StateG * v4180;
  if (v4185) {
    int * v4166 = v4162->pht;
    v4166[26] = 1;
    struct StateG * v4168 = slot_204(v4162);
    v4180 = v4168;
  } else {
    int * v4170 = v4162->pht;
    v4170[26] = 0;
    int v4172 = v4162->timer;
    int v4194 = v4172 + 15;
    v4162->timer = v4194;
    int * v4174 = v4162->saved_regs;
    int v4175 = v4174[18];
    int * v4176 = v4162->regs;
    v4176[18] = v4175;
    struct StateG * v4178 = slot_205(v4162);
    v4180 = v4178;
  }
  return v4180;
}

struct StateG * slot_165(struct StateG * v3586) {
  int * v3587 = v3586->regs;
  int v3588 = v3587[16];
  int v3589 = v3587[17];
  bool v3609 = v3588 < v3589;
  struct StateG * v3604;
  if (v3609) {
    int * v3590 = v3586->pht;
    v3590[21] = 1;
    int v3592 = v3586->timer;
    int v3613 = v3592 + 15;
    v3586->timer = v3613;
    int * v3594 = v3586->saved_regs;
    int v3595 = v3594[18];
    int * v3596 = v3586->regs;
    v3596[18] = v3595;
    struct StateG * v3598 = slot_170(v3586);
    v3604 = v3598;
  } else {
    int * v3600 = v3586->pht;
    v3600[21] = 0;
    struct StateG * v3602 = slot_171(v3586);
    v3604 = v3602;
  }
  return v3604;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_278(struct StateG * v5814) {
  int * v5815 = v5814->regs;
  int v5816 = v5815[16];
  int v5817 = v5815[17];
  bool v5837 = v5816 >= v5817;
  struct StateG * v5832;
  if (v5837) {
    int * v5818 = v5814->pht;
    v5818[6] = 1;
    struct StateG * v5820 = slot_284(v5814);
    v5832 = v5820;
  } else {
    int * v5822 = v5814->pht;
    v5822[6] = 0;
    int v5824 = v5814->timer;
    int v5846 = v5824 + 15;
    v5814->timer = v5846;
    int * v5826 = v5814->saved_regs;
    int v5827 = v5826[19];
    int * v5828 = v5814->regs;
    v5828[19] = v5827;
    struct StateG * v5830 = slot_289(v5814);
    v5832 = v5830;
  }
  return v5832;
}

struct StateG * slot_250(struct StateG * v5310) {
  int v5311 = v5310->timer;
  int v5318 = v5311 + 1;
  v5310->timer = v5318;
  int * v5313 = v5310->regs;
  int v5314 = v5313[1];
  bool v5321 = v5314 == 156;
  ret_assert(v5321);
  struct StateG * v5316 = slot_254(v5310);
  return v5316;
}

struct StateG * slot_259(struct StateG * v5429) {
  int v5430 = v5429->timer;
  int v5436 = v5430 + 1;
  v5429->timer = v5436;
  int * v5432 = v5429->regs;
  v5432[1] = 164;
  struct StateG * v5434 = slot_263(v5429);
  return v5434;
}

struct StateG * slot_117(struct StateG * v2480) {
  int v2481 = v2480->timer;
  int v2491 = v2481 + 1;
  v2480->timer = v2491;
  int * v2483 = v2480->pht;
  int v2484 = v2483[18];
  bool v2494 = !(v2484 == 0);
  struct StateG * v2489;
  if (v2494) {
    struct StateG * v2485 = slot_122(v2480);
    v2489 = v2485;
  } else {
    struct StateG * v2487 = slot_123(v2480);
    v2489 = v2487;
  }
  return v2489;
}

struct StateG * slot_249(struct StateG * v5296) {
  int v5297 = v5296->timer;
  int v5304 = v5297 + 1;
  v5296->timer = v5304;
  int * v5299 = v5296->regs;
  int v5300 = v5299[1];
  bool v5307 = v5300 == 156;
  ret_assert(v5307);
  struct StateG * v5302 = slot_253(v5296);
  return v5302;
}

struct StateG * slot_90(struct StateG * v1884) {
  int * v1885 = v1884->saved_regs;
  int * v1886 = v1884->regs;
  int v1887 = v1886[18];
  v1885[18] = v1887;
  int v1889 = v1884->timer;
  int v1899 = v1889 + 1;
  v1884->timer = v1899;
  int * v1891 = v1884->regs;
  v1891[18] = 2;
  struct StateG * v1893 = slot_98(v1884);
  return v1893;
}

struct StateG * slot_11(struct StateG * v404) {
  int v405 = v404->timer;
  int v411 = v405 + 1;
  v404->timer = v411;
  int * v407 = v404->regs;
  v407[18] = 1;
  struct StateG * v409 = slot_13(v404);
  return v409;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

void ret_assert(bool c) { koika_assert(c, "return address"); }

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}