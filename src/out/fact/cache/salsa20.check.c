// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]

#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v1095);
struct StateT * slot_228(struct StateT * v4669);
struct StateT * slot_143(struct StateT * v9748);
struct StateT * slot_120(struct StateT * v9318);
struct StateT * slot_226(struct StateT * v4511);
struct StateT * slot_167(struct StateT * v10201);
struct StateT * slot_268(struct StateT * v8288);
struct StateT * slot_152(struct StateT * v9926);
struct StateT * slot_231(struct StateT * v4867);
struct StateT * slot_199(struct StateT * v10811);
struct StateT * slot_252(struct StateT * v6383);
struct StateT * slot_92(struct StateT * v6718);
struct StateT * slot_232(struct StateT * v4992);
struct StateT * slot_269(struct StateT * v8414);
struct StateT * slot_31(struct StateT * v2620);
struct StateT * slot_236(struct StateT * v5325);
struct StateT * slot_241(struct StateT * v5497);
struct StateT * slot_160(struct StateT * v10075);
struct StateT * slot_251(struct StateT * v6265);
struct StateT * slot_65(struct StateT * v4653);
struct StateT * slot_10(struct StateT * v899);
struct StateT * slot_150(struct StateT * v9884);
struct StateT * slot_74(struct StateT * v5345);
struct StateT * slot_262(struct StateT * v7552);
struct StateT * slot_107(struct StateT * v8519);
struct StateT * slot_136(struct StateT * v9626);
struct StateT * slot_84(struct StateT * v5780);
struct StateT * slot_28(struct StateT * v2577);
struct StateT * slot_155(struct StateT * v9989);
struct StateT * slot_177(struct StateT * v10398);
struct StateT * slot_229(struct StateT * v4702);
struct StateT * slot_17(struct StateT * v1514);
struct StateT * slot_181(struct StateT * v10471);
struct StateT * slot_197(struct StateT * v10774);
struct StateT * slot_207(struct StateT * v10953);
struct StateT * slot_156(struct StateT * v10006);
struct StateT * slot_154(struct StateT * v9968);
struct StateT * slot_68(struct StateT * v4847);
struct StateT * slot_260(struct StateT * v7324);
struct StateT * slot_105(struct StateT * v8272);
struct StateT * slot_27(struct StateT * v2564);
struct StateT * slot_164(struct StateT * v10148);
struct StateT * slot_15(struct StateT * v1304);
struct StateT * slot_133(struct StateT * v9567);
struct StateT * slot_56(struct StateT * v3981);
struct StateT * slot_244(struct StateT * v5606);
struct StateT * slot_222(struct StateT * v4188);
struct StateT * slot_34(struct StateT * v2667);
struct StateT * slot_171(struct StateT * v10281);
struct StateT * slot_162(struct StateT * v10112);
struct StateT * slot_21(struct StateT * v1934);
struct StateT * slot_239(struct StateT * v5428);
struct StateT * slot_118(struct StateT * v9285);
struct StateT * slot_121(struct StateT * v9338);
struct StateT * slot_144(struct StateT * v9768);
struct StateT * slot_267(struct StateT * v8167);
struct StateT * slot_201(struct StateT * v10847);
struct StateT * slot_94(struct StateT * v6956);
struct StateT * slot_63(struct StateT * v4491);
struct StateT * slot_146(struct StateT * v9801);
struct StateT * slot_24(struct StateT * v2249);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v10741);
struct StateT * slot_125(struct StateT * v9408);
struct StateT * slot_254(struct StateT * v6620);
struct StateT * slot_148(struct StateT * v9842);
struct StateT * slot_126(struct StateT * v9424);
struct StateT * slot_223(struct StateT * v4313);
struct StateT * slot_79(struct StateT * v5513);
struct StateT * slot_237(struct StateT * v5366);
struct StateT * slot_41(struct StateT * v3185);
struct StateT * slot_39(struct StateT * v2990);
struct StateT * slot_142(struct StateT * v9732);
struct StateT * slot_60(struct StateT * v4293);
struct StateT * slot_238(struct StateT * v5396);
struct StateT * slot_112(struct StateT * v9148);
struct StateT * slot_256(struct StateT * v6858);
struct StateT * slot_272(struct StateT * v8791);
struct StateT * slot_47(struct StateT * v3530);
struct StateT * slot_214(struct StateT * v3723);
struct StateT * slot_29(struct StateT * v2590);
struct StateT * slot_16(struct StateT * v1409);
struct StateT * slot_245(struct StateT * v5642);
struct StateT * slot_113(struct StateT * v9185);
struct StateT * slot_151(struct StateT * v9905);
struct StateT * slot_7(struct StateT * v605);
struct StateT * slot_124(struct StateT * v9391);
struct StateT * slot_191(struct StateT * v10657);
struct StateT * slot_103(struct StateT * v8025);
struct StateT * slot_128(struct StateT * v9464);
struct StateT * slot_19(struct StateT * v1724);
struct StateT * slot_87(struct StateT * v6127);
struct StateT * slot_67(struct StateT * v4807);
struct StateT * slot_81(struct StateT * v5589);
struct StateT * slot_95(struct StateT * v7075);
struct StateT * slot_115(struct StateT * v9232);
struct StateT * slot_78(struct StateT * v5480);
struct StateT * slot_32(struct StateT * v2637);
struct StateT * slot_205(struct StateT * v10917);
struct StateT * slot_193(struct StateT * v10699);
struct StateT * slot_233(struct StateT * v5032);
struct StateT * slot_176(struct StateT * v10382);
struct StateT * slot_189(struct StateT * v10617);
struct StateT * slot_33(struct StateT * v2654);
struct StateT * slot_35(struct StateT * v2683);
struct StateT * slot_258(struct StateT * v7092);
struct StateT * slot_246(struct StateT * v5682);
struct StateT * slot_210(struct StateT * v11014);
struct StateT * slot_166(struct StateT * v10181);
struct StateT * slot_51(struct StateT * v3702);
struct StateT * slot_52(struct StateT * v3743);
struct StateT * slot_83(struct StateT * v5662);
struct StateT * slot_25(struct StateT * v2354);
struct StateT * slot_209(struct StateT * v10994);
struct StateT * slot_3(struct StateT * v213);
struct StateT * slot_264(struct StateT * v7799);
struct StateT * slot_123(struct StateT * v9371);
struct StateT * slot_73(struct StateT * v5304);
struct StateT * slot_270(struct StateT * v8540);
struct StateT * slot_198(struct StateT * v10794);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_187(struct StateT * v10577);
struct StateT * slot_97(struct StateT * v7304);
struct StateT * slot_182(struct StateT * v10488);
struct StateT * slot_38(struct StateT * v2892);
struct StateT * slot_178(struct StateT * v10418);
struct StateT * slot_106(struct StateT * v8393);
struct StateT * slot_98(struct StateT * v7421);
struct StateT * slot_159(struct StateT * v10059);
struct StateT * slot_46(struct StateT * v3513);
struct StateT * slot_212(struct StateT * v11050);
struct StateT * slot_132(struct StateT * v9546);
struct StateT * slot_130(struct StateT * v9505);
struct StateT * slot_211(struct StateT * v11034);
struct StateT * slot_20(struct StateT * v1829);
struct StateT * slot_141(struct StateT * v9715);
struct StateT * slot_61(struct StateT * v4333);
struct StateT * slot_30(struct StateT * v2603);
struct StateT * slot_4(struct StateT * v311);
struct StateT * slot_18(struct StateT * v1619);
struct StateT * slot_9(struct StateT * v801);
struct StateT * slot_183(struct StateT * v10504);
struct StateT * slot_240(struct StateT * v5464);
struct StateT * slot_247(struct StateT * v5797);
struct StateT * slot_43(struct StateT * v3381);
struct StateT * slot_70(struct StateT * v5012);
struct StateT * slot_168(struct StateT * v10221);
struct StateT * slot_76(struct StateT * v5412);
struct StateT * slot_6(struct StateT * v507);
struct StateT * slot_225(struct StateT * v4471);
struct StateT * slot_55(struct StateT * v3944);
struct StateT * slot_213(struct StateT * v3682);
struct StateT * slot_82(struct StateT * v5626);
struct StateT * slot_274(struct StateT * v9043);
struct StateT * slot_263(struct StateT * v7677);
struct StateT * slot_161(struct StateT * v10095);
struct StateT * slot_185(struct StateT * v10541);
struct StateT * slot_91(struct StateT * v6599);
struct StateT * slot_58(struct StateT * v4135);
struct StateT * slot_89(struct StateT * v6363);
struct StateT * slot_255(struct StateT * v6739);
struct StateT * slot_66(struct StateT * v4682);
struct StateT * slot_140(struct StateT * v9695);
struct StateT * slot_265(struct StateT * v7920);
struct StateT * slot_49(struct StateT * v3645);
struct StateT * slot_216(struct StateT * v3798);
struct StateT * slot_50(struct StateT * v3662);
struct StateT * slot_37(struct StateT * v2794);
struct StateT * slot_114(struct StateT * v9211);
struct StateT * slot_135(struct StateT * v9609);
struct StateT * slot_248(struct StateT * v5911);
struct StateT * slot_257(struct StateT * v6977);
struct StateT * slot_59(struct StateT * v4172);
struct StateT * slot_192(struct StateT * v10678);
struct StateT * slot_40(struct StateT * v3087);
struct StateT * slot_48(struct StateT * v3547);
struct StateT * slot_77(struct StateT * v5444);
struct StateT * slot_85(struct StateT * v5895);
struct StateT * slot_75(struct StateT * v5379);
struct StateT * slot_72(struct StateT * v5178);
struct StateT * slot_119(struct StateT * v9302);
struct StateT * slot_71(struct StateT * v5137);
struct StateT * slot_101(struct StateT * v7782);
struct StateT * slot_276(struct StateT * v9206);
struct StateT * slot_108(struct StateT * v8645);
struct StateT * slot_116(struct StateT * v9249);
struct StateT * slot_93(struct StateT * v6837);
struct StateT * slot_266(struct StateT * v8045);
struct StateT * slot_88(struct StateT * v6245);
struct StateT * slot_96(struct StateT * v7190);
struct StateT * slot_215(struct StateT * v3764);
struct StateT * slot_234(struct StateT * v5158);
struct StateT * slot_45(struct StateT * v3496);
struct StateT * slot_218(struct StateT * v3961);
struct StateT * slot_220(struct StateT * v4030);
struct StateT * slot_134(struct StateT * v9588);
struct StateT * slot_175(struct StateT * v10365);
struct StateT * slot_273(struct StateT * v8917);
struct StateT * slot_69(struct StateT * v4972);
struct StateT * slot_202(struct StateT * v10864);
struct StateT * slot_230(struct StateT * v4827);
struct StateT * slot_188(struct StateT * v10597);
struct StateT * slot_138(struct StateT * v9662);
struct StateT * slot_186(struct StateT * v10557);
struct StateT * slot_102(struct StateT * v7904);
struct StateT * slot_145(struct StateT * v9785);
struct StateT * slot_110(struct StateT * v8896);
struct StateT * slot_196(struct StateT * v10758);
struct StateT * slot_208(struct StateT * v10973);
struct StateT * slot_172(struct StateT * v10302);
struct StateT * slot_131(struct StateT * v9525);
struct StateT * slot_8(struct StateT * v703);
struct StateT * slot_180(struct StateT * v10451);
struct StateT * slot_203(struct StateT * v10880);
struct StateT * slot_190(struct StateT * v10637);
struct StateT * slot_157(struct StateT * v10022);
struct StateT * slot_242(struct StateT * v5529);
struct StateT * slot_200(struct StateT * v10827);
struct StateT * slot_243(struct StateT * v5569);
struct StateT * slot_173(struct StateT * v10323);
struct StateT * slot_149(struct StateT * v9863);
struct StateT * slot_5(struct StateT * v409);
struct StateT * slot_104(struct StateT * v8150);
struct StateT * slot_235(struct StateT * v5199);
struct StateT * slot_275(struct StateT * v9169);
struct StateT * slot_54(struct StateT * v3818);
struct StateT * slot_26(struct StateT * v2459);
struct StateT * slot_206(struct StateT * v10933);
struct StateT * slot_227(struct StateT * v4633);
struct StateT * slot_169(struct StateT * v10241);
struct StateT * slot_253(struct StateT * v6501);
struct StateT * slot_64(struct StateT * v4616);
struct StateT * slot_170(struct StateT * v10261);
struct StateT * slot_14(struct StateT * v1291);
struct StateT * slot_53(struct StateT * v3777);
struct StateT * slot_80(struct StateT * v5549);
struct StateT * slot_44(struct StateT * v3479);
struct StateT * slot_261(struct StateT * v7438);
struct StateT * slot_137(struct StateT * v9642);
struct StateT * slot_122(struct StateT * v9355);
struct StateT * slot_99(struct StateT * v7536);
struct StateT * slot_179(struct StateT * v10435);
struct StateT * slot_219(struct StateT * v3997);
struct StateT * slot_36(struct StateT * v2696);
struct StateT * slot_57(struct StateT * v4010);
struct StateT * slot_62(struct StateT * v4455);
struct StateT * slot_22(struct StateT * v2039);
struct StateT * slot_139(struct StateT * v9679);
struct StateT * slot_221(struct StateT * v4152);
struct StateT * slot_23(struct StateT * v2144);
struct StateT * slot_153(struct StateT * v9947);
struct StateT * slot_2(struct StateT * v115);
struct StateT * slot_86(struct StateT * v6009);
struct StateT * slot_129(struct StateT * v9485);
struct StateT * slot_158(struct StateT * v10042);
struct StateT * slot_100(struct StateT * v7657);
struct StateT * slot_271(struct StateT * v8665);
struct StateT * slot_127(struct StateT * v9444);
struct StateT * slot_217(struct StateT * v3839);
struct StateT * slot_13(struct StateT * v1193);
struct StateT * slot_111(struct StateT * v9022);
struct StateT * slot_109(struct StateT * v8770);
struct StateT * slot_174(struct StateT * v10344);
struct StateT * slot_147(struct StateT * v9822);
struct StateT * slot_42(struct StateT * v3283);
struct StateT * slot_224(struct StateT * v4350);
struct StateT * slot_163(struct StateT * v10128);
struct StateT * slot_184(struct StateT * v10524);
struct StateT * slot_204(struct StateT * v10900);
struct StateT * slot_194(struct StateT * v10720);
struct StateT * slot_165(struct StateT * v10165);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v6147);
struct StateT * slot_259(struct StateT * v7206);
struct StateT * slot_117(struct StateT * v9265);
struct StateT * slot_249(struct StateT * v6029);
struct StateT * slot_90(struct StateT * v6481);
struct StateT * slot_11(struct StateT * v997);
struct StateT * slot_12(struct StateT * v1095) {
  int v1096 = v1095->timer;
  int v1150 = v1096 + 1;
  v1095->timer = v1150;
  int * v1098 = v1095->regs;
  int v1099 = v1098[2];
  int * v1100 = v1095->regs;
  int v1101 = v1100[26];
  int * v1102 = v1095->cache_keys;
  int v1103 = v1102[0];
  bool v1157 = v1103 == ((int)((unsigned int)(v1099 + 48) >> 2));
  int v1147;
  if (v1157) {
    int * v1104 = v1095->cache_vals;
    v1104[0] = v1101;
    v1147 = v1101;
  } else {
    int * v1107 = v1095->cache_keys;
    int v1108 = v1107[1];
    bool v1162 = v1108 == ((int)((unsigned int)(v1099 + 48) >> 2));
    int v1145;
    if (v1162) {
      int * v1109 = v1095->cache_keys;
      int * v1110 = v1095->cache_keys;
      int v1111 = v1110[0];
      v1109[1] = v1111;
      int * v1113 = v1095->cache_vals;
      int * v1114 = v1095->cache_vals;
      int v1115 = v1114[0];
      v1113[1] = v1115;
      int * v1117 = v1095->cache_keys;
      int v1170 = (int)((unsigned int)(v1099 + 48) >> 2);
      v1117[0] = v1170;
      int * v1119 = v1095->cache_vals;
      v1119[0] = v1101;
      int v1121 = v1095->timer;
      int v1173 = v1121 + 1;
      v1095->timer = v1173;
      v1145 = v1101;
    } else {
      int * v1124 = v1095->mem;
      int * v1125 = v1095->cache_keys;
      int v1126 = v1125[1];
      int * v1127 = v1095->cache_vals;
      int v1128 = v1127[1];
      v1124[v1126] = v1128;
      int * v1130 = v1095->cache_keys;
      int * v1131 = v1095->cache_keys;
      int v1132 = v1131[0];
      v1130[1] = v1132;
      int * v1134 = v1095->cache_vals;
      int * v1135 = v1095->cache_vals;
      int v1136 = v1135[0];
      v1134[1] = v1136;
      int * v1138 = v1095->cache_keys;
      int v1186 = (int)((unsigned int)(v1099 + 48) >> 2);
      v1138[0] = v1186;
      int * v1140 = v1095->cache_vals;
      v1140[0] = v1101;
      int v1142 = v1095->timer;
      int v1189 = v1142 + 100;
      v1095->timer = v1189;
      v1145 = v1101;
    }
    v1147 = v1145;
  }
  struct StateT * v1148 = slot_13(v1095);
  return v1148;
}

struct StateT * slot_228(struct StateT * v4669) {
  int v4670 = v4669->timer;
  int v4676 = v4670 + 1;
  v4669->timer = v4676;
  int * v4672 = v4669->regs;
  v4672[7] = 2036477952;
  struct StateT * v4674 = slot_229(v4669);
  return v4674;
}

struct StateT * slot_143(struct StateT * v9748) {
  int v9749 = v9748->timer;
  int v9759 = v9749 + 1;
  v9748->timer = v9759;
  int * v9751 = v9748->regs;
  int v9752 = v9751[16];
  int * v9753 = v9748->regs;
  int v9754 = v9753[5];
  int * v9755 = v9748->regs;
  int v9765 = v9752 | v9754;
  v9755[16] = v9765;
  struct StateT * v9757 = slot_144(v9748);
  return v9757;
}

struct StateT * slot_120(struct StateT * v9318) {
  int v9319 = v9318->timer;
  int v9329 = v9319 + 1;
  v9318->timer = v9329;
  int * v9321 = v9318->regs;
  int v9322 = v9321[16];
  int * v9323 = v9318->regs;
  int v9324 = v9323[6];
  int * v9325 = v9318->regs;
  int v9335 = v9322 | v9324;
  v9325[16] = v9335;
  struct StateT * v9327 = slot_121(v9318);
  return v9327;
}

struct StateT * slot_226(struct StateT * v4511) {
  int v4512 = v4511->timer;
  int v4570 = v4512 + 1;
  v4511->timer = v4570;
  int * v4514 = v4511->regs;
  int v4515 = v4514[2];
  int * v4516 = v4511->cache_keys;
  int v4517 = v4516[0];
  bool v4575 = v4517 == ((int)((unsigned int)(v4515 + 24) >> 2));
  int v4565;
  if (v4575) {
    int * v4518 = v4511->cache_vals;
    int v4519 = v4518[0];
    v4565 = v4519;
  } else {
    int * v4521 = v4511->cache_keys;
    int v4522 = v4521[1];
    bool v4580 = v4522 == ((int)((unsigned int)(v4515 + 24) >> 2));
    int v4563;
    if (v4580) {
      int * v4523 = v4511->cache_vals;
      int v4524 = v4523[1];
      int * v4525 = v4511->cache_keys;
      int * v4526 = v4511->cache_keys;
      int v4527 = v4526[0];
      v4525[1] = v4527;
      int * v4529 = v4511->cache_vals;
      int * v4530 = v4511->cache_vals;
      int v4531 = v4530[0];
      v4529[1] = v4531;
      int * v4533 = v4511->cache_keys;
      int v4589 = (int)((unsigned int)(v4515 + 24) >> 2);
      v4533[0] = v4589;
      int * v4535 = v4511->cache_vals;
      v4535[0] = v4524;
      int v4537 = v4511->timer;
      int v4592 = v4537 + 1;
      v4511->timer = v4592;
      v4563 = v4524;
    } else {
      int * v4540 = v4511->mem;
      int v4594 = (int)((unsigned int)(v4515 + 24) >> 2);
      int v4541 = v4540[v4594];
      int * v4542 = v4511->mem;
      int * v4543 = v4511->cache_keys;
      int v4544 = v4543[1];
      int * v4545 = v4511->cache_vals;
      int v4546 = v4545[1];
      v4542[v4544] = v4546;
      int * v4548 = v4511->cache_keys;
      int * v4549 = v4511->cache_keys;
      int v4550 = v4549[0];
      v4548[1] = v4550;
      int * v4552 = v4511->cache_vals;
      int * v4553 = v4511->cache_vals;
      int v4554 = v4553[0];
      v4552[1] = v4554;
      int * v4556 = v4511->cache_keys;
      v4556[0] = v4594;
      int * v4558 = v4511->cache_vals;
      v4558[0] = v4541;
      int v4560 = v4511->timer;
      int v4609 = v4560 + 100;
      v4511->timer = v4609;
      v4563 = v4541;
    }
    v4565 = v4563;
  }
  int * v4566 = v4511->regs;
  v4566[7] = v4565;
  struct StateT * v4568 = slot_227(v4511);
  return v4568;
}

struct StateT * slot_167(struct StateT * v10201) {
  int v10202 = v10201->timer;
  int v10212 = v10202 + 1;
  v10201->timer = v10212;
  int * v10204 = v10201->regs;
  int v10205 = v10204[27];
  int * v10206 = v10201->regs;
  int v10207 = v10206[11];
  int * v10208 = v10201->regs;
  int v10218 = v10205 ^ v10207;
  v10208[27] = v10218;
  struct StateT * v10210 = slot_168(v10201);
  return v10210;
}

struct StateT * slot_268(struct StateT * v8288) {
  int v8289 = v8288->timer;
  int v8347 = v8289 + 1;
  v8288->timer = v8347;
  int * v8291 = v8288->regs;
  int v8292 = v8291[2];
  int * v8293 = v8288->cache_keys;
  int v8294 = v8293[0];
  bool v8352 = v8294 == ((int)((unsigned int)(v8292 + 68) >> 2));
  int v8342;
  if (v8352) {
    int * v8295 = v8288->cache_vals;
    int v8296 = v8295[0];
    v8342 = v8296;
  } else {
    int * v8298 = v8288->cache_keys;
    int v8299 = v8298[1];
    bool v8357 = v8299 == ((int)((unsigned int)(v8292 + 68) >> 2));
    int v8340;
    if (v8357) {
      int * v8300 = v8288->cache_vals;
      int v8301 = v8300[1];
      int * v8302 = v8288->cache_keys;
      int * v8303 = v8288->cache_keys;
      int v8304 = v8303[0];
      v8302[1] = v8304;
      int * v8306 = v8288->cache_vals;
      int * v8307 = v8288->cache_vals;
      int v8308 = v8307[0];
      v8306[1] = v8308;
      int * v8310 = v8288->cache_keys;
      int v8366 = (int)((unsigned int)(v8292 + 68) >> 2);
      v8310[0] = v8366;
      int * v8312 = v8288->cache_vals;
      v8312[0] = v8301;
      int v8314 = v8288->timer;
      int v8369 = v8314 + 1;
      v8288->timer = v8369;
      v8340 = v8301;
    } else {
      int * v8317 = v8288->mem;
      int v8371 = (int)((unsigned int)(v8292 + 68) >> 2);
      int v8318 = v8317[v8371];
      int * v8319 = v8288->mem;
      int * v8320 = v8288->cache_keys;
      int v8321 = v8320[1];
      int * v8322 = v8288->cache_vals;
      int v8323 = v8322[1];
      v8319[v8321] = v8323;
      int * v8325 = v8288->cache_keys;
      int * v8326 = v8288->cache_keys;
      int v8327 = v8326[0];
      v8325[1] = v8327;
      int * v8329 = v8288->cache_vals;
      int * v8330 = v8288->cache_vals;
      int v8331 = v8330[0];
      v8329[1] = v8331;
      int * v8333 = v8288->cache_keys;
      v8333[0] = v8371;
      int * v8335 = v8288->cache_vals;
      v8335[0] = v8318;
      int v8337 = v8288->timer;
      int v8386 = v8337 + 100;
      v8288->timer = v8386;
      v8340 = v8318;
    }
    v8342 = v8340;
  }
  int * v8343 = v8288->regs;
  v8343[21] = v8342;
  struct StateT * v8345 = slot_269(v8288);
  return v8345;
}

struct StateT * slot_152(struct StateT * v9926) {
  int v9927 = v9926->timer;
  int v9937 = v9927 + 1;
  v9926->timer = v9937;
  int * v9929 = v9926->regs;
  int v9930 = v9929[5];
  int * v9931 = v9926->regs;
  int v9932 = v9931[20];
  int * v9933 = v9926->regs;
  int v9944 = v9930 + v9932;
  v9933[15] = v9944;
  struct StateT * v9935 = slot_153(v9926);
  return v9935;
}

struct StateT * slot_231(struct StateT * v4867) {
  int v4868 = v4867->timer;
  int v4926 = v4868 + 1;
  v4867->timer = v4926;
  int * v4870 = v4867->regs;
  int v4871 = v4870[2];
  int * v4872 = v4867->cache_keys;
  int v4873 = v4872[0];
  bool v4931 = v4873 == ((int)((unsigned int)(v4871 + 32) >> 2));
  int v4921;
  if (v4931) {
    int * v4874 = v4867->cache_vals;
    int v4875 = v4874[0];
    v4921 = v4875;
  } else {
    int * v4877 = v4867->cache_keys;
    int v4878 = v4877[1];
    bool v4936 = v4878 == ((int)((unsigned int)(v4871 + 32) >> 2));
    int v4919;
    if (v4936) {
      int * v4879 = v4867->cache_vals;
      int v4880 = v4879[1];
      int * v4881 = v4867->cache_keys;
      int * v4882 = v4867->cache_keys;
      int v4883 = v4882[0];
      v4881[1] = v4883;
      int * v4885 = v4867->cache_vals;
      int * v4886 = v4867->cache_vals;
      int v4887 = v4886[0];
      v4885[1] = v4887;
      int * v4889 = v4867->cache_keys;
      int v4945 = (int)((unsigned int)(v4871 + 32) >> 2);
      v4889[0] = v4945;
      int * v4891 = v4867->cache_vals;
      v4891[0] = v4880;
      int v4893 = v4867->timer;
      int v4948 = v4893 + 1;
      v4867->timer = v4948;
      v4919 = v4880;
    } else {
      int * v4896 = v4867->mem;
      int v4950 = (int)((unsigned int)(v4871 + 32) >> 2);
      int v4897 = v4896[v4950];
      int * v4898 = v4867->mem;
      int * v4899 = v4867->cache_keys;
      int v4900 = v4899[1];
      int * v4901 = v4867->cache_vals;
      int v4902 = v4901[1];
      v4898[v4900] = v4902;
      int * v4904 = v4867->cache_keys;
      int * v4905 = v4867->cache_keys;
      int v4906 = v4905[0];
      v4904[1] = v4906;
      int * v4908 = v4867->cache_vals;
      int * v4909 = v4867->cache_vals;
      int v4910 = v4909[0];
      v4908[1] = v4910;
      int * v4912 = v4867->cache_keys;
      v4912[0] = v4950;
      int * v4914 = v4867->cache_vals;
      v4914[0] = v4897;
      int v4916 = v4867->timer;
      int v4965 = v4916 + 100;
      v4867->timer = v4965;
      v4919 = v4897;
    }
    v4921 = v4919;
  }
  int * v4922 = v4867->regs;
  v4922[30] = v4921;
  struct StateT * v4924 = slot_232(v4867);
  return v4924;
}

struct StateT * slot_199(struct StateT * v10811) {
  int v10812 = v10811->timer;
  int v10820 = v10812 + 1;
  v10811->timer = v10820;
  int * v10814 = v10811->regs;
  int v10815 = v10814[15];
  int * v10816 = v10811->regs;
  int v10824 = v10815 << 18;
  v10816[15] = v10824;
  struct StateT * v10818 = slot_200(v10811);
  return v10818;
}

struct StateT * slot_252(struct StateT * v6383) {
  int v6384 = v6383->timer;
  int v6438 = v6384 + 1;
  v6383->timer = v6438;
  int * v6386 = v6383->regs;
  int v6387 = v6386[10];
  int * v6388 = v6383->regs;
  int v6389 = v6388[5];
  int * v6390 = v6383->cache_keys;
  int v6391 = v6390[0];
  bool v6445 = v6391 == ((int)((unsigned int)(v6387 + 24) >> 2));
  int v6435;
  if (v6445) {
    int * v6392 = v6383->cache_vals;
    v6392[0] = v6389;
    v6435 = v6389;
  } else {
    int * v6395 = v6383->cache_keys;
    int v6396 = v6395[1];
    bool v6450 = v6396 == ((int)((unsigned int)(v6387 + 24) >> 2));
    int v6433;
    if (v6450) {
      int * v6397 = v6383->cache_keys;
      int * v6398 = v6383->cache_keys;
      int v6399 = v6398[0];
      v6397[1] = v6399;
      int * v6401 = v6383->cache_vals;
      int * v6402 = v6383->cache_vals;
      int v6403 = v6402[0];
      v6401[1] = v6403;
      int * v6405 = v6383->cache_keys;
      int v6458 = (int)((unsigned int)(v6387 + 24) >> 2);
      v6405[0] = v6458;
      int * v6407 = v6383->cache_vals;
      v6407[0] = v6389;
      int v6409 = v6383->timer;
      int v6461 = v6409 + 1;
      v6383->timer = v6461;
      v6433 = v6389;
    } else {
      int * v6412 = v6383->mem;
      int * v6413 = v6383->cache_keys;
      int v6414 = v6413[1];
      int * v6415 = v6383->cache_vals;
      int v6416 = v6415[1];
      v6412[v6414] = v6416;
      int * v6418 = v6383->cache_keys;
      int * v6419 = v6383->cache_keys;
      int v6420 = v6419[0];
      v6418[1] = v6420;
      int * v6422 = v6383->cache_vals;
      int * v6423 = v6383->cache_vals;
      int v6424 = v6423[0];
      v6422[1] = v6424;
      int * v6426 = v6383->cache_keys;
      int v6474 = (int)((unsigned int)(v6387 + 24) >> 2);
      v6426[0] = v6474;
      int * v6428 = v6383->cache_vals;
      v6428[0] = v6389;
      int v6430 = v6383->timer;
      int v6477 = v6430 + 100;
      v6383->timer = v6477;
      v6433 = v6389;
    }
    v6435 = v6433;
  }
  struct StateT * v6436 = slot_253(v6383);
  return v6436;
}

struct StateT * slot_92(struct StateT * v6718) {
  int v6719 = v6718->timer;
  int v6729 = v6719 + 1;
  v6718->timer = v6729;
  int * v6721 = v6718->regs;
  int v6722 = v6721[24];
  int * v6723 = v6718->regs;
  int v6724 = v6723[13];
  int * v6725 = v6718->regs;
  int v6736 = v6722 + v6724;
  v6725[8] = v6736;
  struct StateT * v6727 = slot_93(v6718);
  return v6727;
}

struct StateT * slot_232(struct StateT * v4992) {
  int v4993 = v4992->timer;
  int v5003 = v4993 + 1;
  v4992->timer = v5003;
  int * v4995 = v4992->regs;
  int v4996 = v4995[16];
  int * v4997 = v4992->regs;
  int v4998 = v4997[30];
  int * v4999 = v4992->regs;
  int v5009 = v4996 + v4998;
  v4999[16] = v5009;
  struct StateT * v5001 = slot_233(v4992);
  return v5001;
}

struct StateT * slot_269(struct StateT * v8414) {
  int v8415 = v8414->timer;
  int v8473 = v8415 + 1;
  v8414->timer = v8473;
  int * v8417 = v8414->regs;
  int v8418 = v8417[2];
  int * v8419 = v8414->cache_keys;
  int v8420 = v8419[0];
  bool v8478 = v8420 == ((int)((unsigned int)(v8418 + 64) >> 2));
  int v8468;
  if (v8478) {
    int * v8421 = v8414->cache_vals;
    int v8422 = v8421[0];
    v8468 = v8422;
  } else {
    int * v8424 = v8414->cache_keys;
    int v8425 = v8424[1];
    bool v8483 = v8425 == ((int)((unsigned int)(v8418 + 64) >> 2));
    int v8466;
    if (v8483) {
      int * v8426 = v8414->cache_vals;
      int v8427 = v8426[1];
      int * v8428 = v8414->cache_keys;
      int * v8429 = v8414->cache_keys;
      int v8430 = v8429[0];
      v8428[1] = v8430;
      int * v8432 = v8414->cache_vals;
      int * v8433 = v8414->cache_vals;
      int v8434 = v8433[0];
      v8432[1] = v8434;
      int * v8436 = v8414->cache_keys;
      int v8492 = (int)((unsigned int)(v8418 + 64) >> 2);
      v8436[0] = v8492;
      int * v8438 = v8414->cache_vals;
      v8438[0] = v8427;
      int v8440 = v8414->timer;
      int v8495 = v8440 + 1;
      v8414->timer = v8495;
      v8466 = v8427;
    } else {
      int * v8443 = v8414->mem;
      int v8497 = (int)((unsigned int)(v8418 + 64) >> 2);
      int v8444 = v8443[v8497];
      int * v8445 = v8414->mem;
      int * v8446 = v8414->cache_keys;
      int v8447 = v8446[1];
      int * v8448 = v8414->cache_vals;
      int v8449 = v8448[1];
      v8445[v8447] = v8449;
      int * v8451 = v8414->cache_keys;
      int * v8452 = v8414->cache_keys;
      int v8453 = v8452[0];
      v8451[1] = v8453;
      int * v8455 = v8414->cache_vals;
      int * v8456 = v8414->cache_vals;
      int v8457 = v8456[0];
      v8455[1] = v8457;
      int * v8459 = v8414->cache_keys;
      v8459[0] = v8497;
      int * v8461 = v8414->cache_vals;
      v8461[0] = v8444;
      int v8463 = v8414->timer;
      int v8512 = v8463 + 100;
      v8414->timer = v8512;
      v8466 = v8444;
    }
    v8468 = v8466;
  }
  int * v8469 = v8414->regs;
  v8469[22] = v8468;
  struct StateT * v8471 = slot_270(v8414);
  return v8471;
}

struct StateT * slot_31(struct StateT * v2620) {
  int v2621 = v2620->timer;
  int v2629 = v2621 + 1;
  v2620->timer = v2629;
  int * v2623 = v2620->regs;
  int v2624 = v2623[13];
  int * v2625 = v2620->regs;
  int v2634 = v2624 + 1134;
  v2625[11] = v2634;
  struct StateT * v2627 = slot_32(v2620);
  return v2627;
}

struct StateT * slot_236(struct StateT * v5325) {
  int v5326 = v5325->timer;
  int v5336 = v5326 + 1;
  v5325->timer = v5336;
  int * v5328 = v5325->regs;
  int v5329 = v5328[1];
  int * v5330 = v5325->regs;
  int v5331 = v5330[30];
  int * v5332 = v5325->regs;
  int v5342 = v5329 + v5331;
  v5332[1] = v5342;
  struct StateT * v5334 = slot_237(v5325);
  return v5334;
}

struct StateT * slot_241(struct StateT * v5497) {
  int v5498 = v5497->timer;
  int v5506 = v5498 + 1;
  v5497->timer = v5506;
  int * v5500 = v5497->regs;
  int v5501 = v5500[30];
  int * v5502 = v5497->regs;
  int v5510 = v5501 + 1396;
  v5502[30] = v5510;
  struct StateT * v5504 = slot_242(v5497);
  return v5504;
}

struct StateT * slot_160(struct StateT * v10075) {
  int v10076 = v10075->timer;
  int v10086 = v10076 + 1;
  v10075->timer = v10086;
  int * v10078 = v10075->regs;
  int v10079 = v10078[15];
  int * v10080 = v10075->regs;
  int v10081 = v10080[9];
  int * v10082 = v10075->regs;
  int v10092 = v10079 | v10081;
  v10082[15] = v10092;
  struct StateT * v10084 = slot_161(v10075);
  return v10084;
}

struct StateT * slot_251(struct StateT * v6265) {
  int v6266 = v6265->timer;
  int v6320 = v6266 + 1;
  v6265->timer = v6320;
  int * v6268 = v6265->regs;
  int v6269 = v6268[10];
  int * v6270 = v6265->regs;
  int v6271 = v6270[11];
  int * v6272 = v6265->cache_keys;
  int v6273 = v6272[0];
  bool v6327 = v6273 == ((int)((unsigned int)(v6269 + 20) >> 2));
  int v6317;
  if (v6327) {
    int * v6274 = v6265->cache_vals;
    v6274[0] = v6271;
    v6317 = v6271;
  } else {
    int * v6277 = v6265->cache_keys;
    int v6278 = v6277[1];
    bool v6332 = v6278 == ((int)((unsigned int)(v6269 + 20) >> 2));
    int v6315;
    if (v6332) {
      int * v6279 = v6265->cache_keys;
      int * v6280 = v6265->cache_keys;
      int v6281 = v6280[0];
      v6279[1] = v6281;
      int * v6283 = v6265->cache_vals;
      int * v6284 = v6265->cache_vals;
      int v6285 = v6284[0];
      v6283[1] = v6285;
      int * v6287 = v6265->cache_keys;
      int v6340 = (int)((unsigned int)(v6269 + 20) >> 2);
      v6287[0] = v6340;
      int * v6289 = v6265->cache_vals;
      v6289[0] = v6271;
      int v6291 = v6265->timer;
      int v6343 = v6291 + 1;
      v6265->timer = v6343;
      v6315 = v6271;
    } else {
      int * v6294 = v6265->mem;
      int * v6295 = v6265->cache_keys;
      int v6296 = v6295[1];
      int * v6297 = v6265->cache_vals;
      int v6298 = v6297[1];
      v6294[v6296] = v6298;
      int * v6300 = v6265->cache_keys;
      int * v6301 = v6265->cache_keys;
      int v6302 = v6301[0];
      v6300[1] = v6302;
      int * v6304 = v6265->cache_vals;
      int * v6305 = v6265->cache_vals;
      int v6306 = v6305[0];
      v6304[1] = v6306;
      int * v6308 = v6265->cache_keys;
      int v6356 = (int)((unsigned int)(v6269 + 20) >> 2);
      v6308[0] = v6356;
      int * v6310 = v6265->cache_vals;
      v6310[0] = v6271;
      int v6312 = v6265->timer;
      int v6359 = v6312 + 100;
      v6265->timer = v6359;
      v6315 = v6271;
    }
    v6317 = v6315;
  }
  struct StateT * v6318 = slot_252(v6265);
  return v6318;
}

struct StateT * slot_65(struct StateT * v4653) {
  int v4654 = v4653->timer;
  int v4662 = v4654 + 1;
  v4653->timer = v4662;
  int * v4656 = v4653->regs;
  int v4657 = v4656[8];
  int * v4658 = v4653->regs;
  int v4666 = v4657 << 7;
  v4658[8] = v4666;
  struct StateT * v4660 = slot_66(v4653);
  return v4660;
}

struct StateT * slot_10(struct StateT * v899) {
  int v900 = v899->timer;
  int v954 = v900 + 1;
  v899->timer = v954;
  int * v902 = v899->regs;
  int v903 = v902[2];
  int * v904 = v899->regs;
  int v905 = v904[24];
  int * v906 = v899->cache_keys;
  int v907 = v906[0];
  bool v961 = v907 == ((int)((unsigned int)(v903 + 56) >> 2));
  int v951;
  if (v961) {
    int * v908 = v899->cache_vals;
    v908[0] = v905;
    v951 = v905;
  } else {
    int * v911 = v899->cache_keys;
    int v912 = v911[1];
    bool v966 = v912 == ((int)((unsigned int)(v903 + 56) >> 2));
    int v949;
    if (v966) {
      int * v913 = v899->cache_keys;
      int * v914 = v899->cache_keys;
      int v915 = v914[0];
      v913[1] = v915;
      int * v917 = v899->cache_vals;
      int * v918 = v899->cache_vals;
      int v919 = v918[0];
      v917[1] = v919;
      int * v921 = v899->cache_keys;
      int v974 = (int)((unsigned int)(v903 + 56) >> 2);
      v921[0] = v974;
      int * v923 = v899->cache_vals;
      v923[0] = v905;
      int v925 = v899->timer;
      int v977 = v925 + 1;
      v899->timer = v977;
      v949 = v905;
    } else {
      int * v928 = v899->mem;
      int * v929 = v899->cache_keys;
      int v930 = v929[1];
      int * v931 = v899->cache_vals;
      int v932 = v931[1];
      v928[v930] = v932;
      int * v934 = v899->cache_keys;
      int * v935 = v899->cache_keys;
      int v936 = v935[0];
      v934[1] = v936;
      int * v938 = v899->cache_vals;
      int * v939 = v899->cache_vals;
      int v940 = v939[0];
      v938[1] = v940;
      int * v942 = v899->cache_keys;
      int v990 = (int)((unsigned int)(v903 + 56) >> 2);
      v942[0] = v990;
      int * v944 = v899->cache_vals;
      v944[0] = v905;
      int v946 = v899->timer;
      int v993 = v946 + 100;
      v899->timer = v993;
      v949 = v905;
    }
    v951 = v949;
  }
  struct StateT * v952 = slot_11(v899);
  return v952;
}

struct StateT * slot_150(struct StateT * v9884) {
  int v9885 = v9884->timer;
  int v9895 = v9885 + 1;
  v9884->timer = v9895;
  int * v9887 = v9884->regs;
  int v9888 = v9887[9];
  int * v9889 = v9884->regs;
  int v9890 = v9889[6];
  int * v9891 = v9884->regs;
  int v9902 = v9888 ^ v9890;
  v9891[16] = v9902;
  struct StateT * v9893 = slot_151(v9884);
  return v9893;
}

struct StateT * slot_74(struct StateT * v5345) {
  int v5346 = v5345->timer;
  int v5356 = v5346 + 1;
  v5345->timer = v5356;
  int * v5348 = v5345->regs;
  int v5349 = v5348[14];
  int * v5350 = v5345->regs;
  int v5351 = v5350[22];
  int * v5352 = v5345->regs;
  int v5363 = v5349 + v5351;
  v5352[18] = v5363;
  struct StateT * v5354 = slot_75(v5345);
  return v5354;
}

struct StateT * slot_262(struct StateT * v7552) {
  int v7553 = v7552->timer;
  int v7611 = v7553 + 1;
  v7552->timer = v7611;
  int * v7555 = v7552->regs;
  int v7556 = v7555[2];
  int * v7557 = v7552->cache_keys;
  int v7558 = v7557[0];
  bool v7616 = v7558 == ((int)((unsigned int)(v7556 + 92) >> 2));
  int v7606;
  if (v7616) {
    int * v7559 = v7552->cache_vals;
    int v7560 = v7559[0];
    v7606 = v7560;
  } else {
    int * v7562 = v7552->cache_keys;
    int v7563 = v7562[1];
    bool v7621 = v7563 == ((int)((unsigned int)(v7556 + 92) >> 2));
    int v7604;
    if (v7621) {
      int * v7564 = v7552->cache_vals;
      int v7565 = v7564[1];
      int * v7566 = v7552->cache_keys;
      int * v7567 = v7552->cache_keys;
      int v7568 = v7567[0];
      v7566[1] = v7568;
      int * v7570 = v7552->cache_vals;
      int * v7571 = v7552->cache_vals;
      int v7572 = v7571[0];
      v7570[1] = v7572;
      int * v7574 = v7552->cache_keys;
      int v7630 = (int)((unsigned int)(v7556 + 92) >> 2);
      v7574[0] = v7630;
      int * v7576 = v7552->cache_vals;
      v7576[0] = v7565;
      int v7578 = v7552->timer;
      int v7633 = v7578 + 1;
      v7552->timer = v7633;
      v7604 = v7565;
    } else {
      int * v7581 = v7552->mem;
      int v7635 = (int)((unsigned int)(v7556 + 92) >> 2);
      int v7582 = v7581[v7635];
      int * v7583 = v7552->mem;
      int * v7584 = v7552->cache_keys;
      int v7585 = v7584[1];
      int * v7586 = v7552->cache_vals;
      int v7587 = v7586[1];
      v7583[v7585] = v7587;
      int * v7589 = v7552->cache_keys;
      int * v7590 = v7552->cache_keys;
      int v7591 = v7590[0];
      v7589[1] = v7591;
      int * v7593 = v7552->cache_vals;
      int * v7594 = v7552->cache_vals;
      int v7595 = v7594[0];
      v7593[1] = v7595;
      int * v7597 = v7552->cache_keys;
      v7597[0] = v7635;
      int * v7599 = v7552->cache_vals;
      v7599[0] = v7582;
      int v7601 = v7552->timer;
      int v7650 = v7601 + 100;
      v7552->timer = v7650;
      v7604 = v7582;
    }
    v7606 = v7604;
  }
  int * v7607 = v7552->regs;
  v7607[1] = v7606;
  struct StateT * v7609 = slot_263(v7552);
  return v7609;
}

struct StateT * slot_107(struct StateT * v8519) {
  int v8520 = v8519->timer;
  int v8530 = v8520 + 1;
  v8519->timer = v8530;
  int * v8522 = v8519->regs;
  int v8523 = v8522[16];
  int * v8524 = v8519->regs;
  int v8525 = v8524[15];
  int * v8526 = v8519->regs;
  int v8537 = v8523 ^ v8525;
  v8526[9] = v8537;
  struct StateT * v8528 = slot_108(v8519);
  return v8528;
}

struct StateT * slot_136(struct StateT * v9626) {
  int v9627 = v9626->timer;
  int v9635 = v9627 + 1;
  v9626->timer = v9635;
  int * v9629 = v9626->regs;
  int v9630 = v9629[15];
  int * v9631 = v9626->regs;
  int v9639 = v9630 << 7;
  v9631[15] = v9639;
  struct StateT * v9633 = slot_137(v9626);
  return v9633;
}

struct StateT * slot_84(struct StateT * v5780) {
  int v5781 = v5780->timer;
  int v5789 = v5781 + 1;
  v5780->timer = v5789;
  int * v5783 = v5780->regs;
  int v5784 = v5783[18];
  int * v5785 = v5780->regs;
  int v5794 = (int)((unsigned int)v5784 >> 23);
  v5785[20] = v5794;
  struct StateT * v5787 = slot_85(v5780);
  return v5787;
}

struct StateT * slot_28(struct StateT * v2577) {
  int v2578 = v2577->timer;
  int v2584 = v2578 + 1;
  v2577->timer = v2584;
  int * v2580 = v2577->regs;
  v2580[13] = 857759744;
  struct StateT * v2582 = slot_29(v2577);
  return v2582;
}

struct StateT * slot_155(struct StateT * v9989) {
  int v9990 = v9989->timer;
  int v9998 = v9990 + 1;
  v9989->timer = v9998;
  int * v9992 = v9989->regs;
  int v9993 = v9992[11];
  int * v9994 = v9989->regs;
  int v10003 = (int)((unsigned int)v9993 >> 23);
  v9994[9] = v10003;
  struct StateT * v9996 = slot_156(v9989);
  return v9996;
}

struct StateT * slot_177(struct StateT * v10398) {
  int v10399 = v10398->timer;
  int v10409 = v10399 + 1;
  v10398->timer = v10409;
  int * v10401 = v10398->regs;
  int v10402 = v10401[11];
  int * v10403 = v10398->regs;
  int v10404 = v10403[9];
  int * v10405 = v10398->regs;
  int v10415 = v10402 | v10404;
  v10405[11] = v10415;
  struct StateT * v10407 = slot_178(v10398);
  return v10407;
}

struct StateT * slot_229(struct StateT * v4702) {
  int v4703 = v4702->timer;
  int v4761 = v4703 + 1;
  v4702->timer = v4761;
  int * v4705 = v4702->regs;
  int v4706 = v4705[2];
  int * v4707 = v4702->cache_keys;
  int v4708 = v4707[0];
  bool v4766 = v4708 == ((int)((unsigned int)(v4706 + 28) >> 2));
  int v4756;
  if (v4766) {
    int * v4709 = v4702->cache_vals;
    int v4710 = v4709[0];
    v4756 = v4710;
  } else {
    int * v4712 = v4702->cache_keys;
    int v4713 = v4712[1];
    bool v4771 = v4713 == ((int)((unsigned int)(v4706 + 28) >> 2));
    int v4754;
    if (v4771) {
      int * v4714 = v4702->cache_vals;
      int v4715 = v4714[1];
      int * v4716 = v4702->cache_keys;
      int * v4717 = v4702->cache_keys;
      int v4718 = v4717[0];
      v4716[1] = v4718;
      int * v4720 = v4702->cache_vals;
      int * v4721 = v4702->cache_vals;
      int v4722 = v4721[0];
      v4720[1] = v4722;
      int * v4724 = v4702->cache_keys;
      int v4780 = (int)((unsigned int)(v4706 + 28) >> 2);
      v4724[0] = v4780;
      int * v4726 = v4702->cache_vals;
      v4726[0] = v4715;
      int v4728 = v4702->timer;
      int v4783 = v4728 + 1;
      v4702->timer = v4783;
      v4754 = v4715;
    } else {
      int * v4731 = v4702->mem;
      int v4785 = (int)((unsigned int)(v4706 + 28) >> 2);
      int v4732 = v4731[v4785];
      int * v4733 = v4702->mem;
      int * v4734 = v4702->cache_keys;
      int v4735 = v4734[1];
      int * v4736 = v4702->cache_vals;
      int v4737 = v4736[1];
      v4733[v4735] = v4737;
      int * v4739 = v4702->cache_keys;
      int * v4740 = v4702->cache_keys;
      int v4741 = v4740[0];
      v4739[1] = v4741;
      int * v4743 = v4702->cache_vals;
      int * v4744 = v4702->cache_vals;
      int v4745 = v4744[0];
      v4743[1] = v4745;
      int * v4747 = v4702->cache_keys;
      v4747[0] = v4785;
      int * v4749 = v4702->cache_vals;
      v4749[0] = v4732;
      int v4751 = v4702->timer;
      int v4800 = v4751 + 100;
      v4702->timer = v4800;
      v4754 = v4732;
    }
    v4756 = v4754;
  }
  int * v4757 = v4702->regs;
  v4757[30] = v4756;
  struct StateT * v4759 = slot_230(v4702);
  return v4759;
}

struct StateT * slot_17(struct StateT * v1514) {
  int v1515 = v1514->timer;
  int v1573 = v1515 + 1;
  v1514->timer = v1573;
  int * v1517 = v1514->regs;
  int v1518 = v1517[12];
  int * v1519 = v1514->cache_keys;
  int v1520 = v1519[0];
  bool v1578 = v1520 == ((int)((unsigned int)(v1518 + 8) >> 2));
  int v1568;
  if (v1578) {
    int * v1521 = v1514->cache_vals;
    int v1522 = v1521[0];
    v1568 = v1522;
  } else {
    int * v1524 = v1514->cache_keys;
    int v1525 = v1524[1];
    bool v1583 = v1525 == ((int)((unsigned int)(v1518 + 8) >> 2));
    int v1566;
    if (v1583) {
      int * v1526 = v1514->cache_vals;
      int v1527 = v1526[1];
      int * v1528 = v1514->cache_keys;
      int * v1529 = v1514->cache_keys;
      int v1530 = v1529[0];
      v1528[1] = v1530;
      int * v1532 = v1514->cache_vals;
      int * v1533 = v1514->cache_vals;
      int v1534 = v1533[0];
      v1532[1] = v1534;
      int * v1536 = v1514->cache_keys;
      int v1592 = (int)((unsigned int)(v1518 + 8) >> 2);
      v1536[0] = v1592;
      int * v1538 = v1514->cache_vals;
      v1538[0] = v1527;
      int v1540 = v1514->timer;
      int v1595 = v1540 + 1;
      v1514->timer = v1595;
      v1566 = v1527;
    } else {
      int * v1543 = v1514->mem;
      int v1597 = (int)((unsigned int)(v1518 + 8) >> 2);
      int v1544 = v1543[v1597];
      int * v1545 = v1514->mem;
      int * v1546 = v1514->cache_keys;
      int v1547 = v1546[1];
      int * v1548 = v1514->cache_vals;
      int v1549 = v1548[1];
      v1545[v1547] = v1549;
      int * v1551 = v1514->cache_keys;
      int * v1552 = v1514->cache_keys;
      int v1553 = v1552[0];
      v1551[1] = v1553;
      int * v1555 = v1514->cache_vals;
      int * v1556 = v1514->cache_vals;
      int v1557 = v1556[0];
      v1555[1] = v1557;
      int * v1559 = v1514->cache_keys;
      v1559[0] = v1597;
      int * v1561 = v1514->cache_vals;
      v1561[0] = v1544;
      int v1563 = v1514->timer;
      int v1612 = v1563 + 100;
      v1514->timer = v1612;
      v1566 = v1544;
    }
    v1568 = v1566;
  }
  int * v1569 = v1514->regs;
  v1569[7] = v1568;
  struct StateT * v1571 = slot_18(v1514);
  return v1571;
}

struct StateT * slot_181(struct StateT * v10471) {
  int v10472 = v10471->timer;
  int v10480 = v10472 + 1;
  v10471->timer = v10480;
  int * v10474 = v10471->regs;
  int v10475 = v10474[6];
  int * v10476 = v10471->regs;
  int v10485 = (int)((unsigned int)v10475 >> 19);
  v10476[9] = v10485;
  struct StateT * v10478 = slot_182(v10471);
  return v10478;
}

struct StateT * slot_197(struct StateT * v10774) {
  int v10775 = v10774->timer;
  int v10785 = v10775 + 1;
  v10774->timer = v10785;
  int * v10777 = v10774->regs;
  int v10778 = v10777[11];
  int * v10779 = v10774->regs;
  int v10780 = v10779[9];
  int * v10781 = v10774->regs;
  int v10791 = v10778 | v10780;
  v10781[11] = v10791;
  struct StateT * v10783 = slot_198(v10774);
  return v10783;
}

struct StateT * slot_207(struct StateT * v10953) {
  int v10954 = v10953->timer;
  int v10964 = v10954 + 1;
  v10953->timer = v10964;
  int * v10956 = v10953->regs;
  int v10957 = v10956[21];
  int * v10958 = v10953->regs;
  int v10959 = v10958[11];
  int * v10960 = v10953->regs;
  int v10970 = v10957 ^ v10959;
  v10960[21] = v10970;
  struct StateT * v10962 = slot_208(v10953);
  return v10962;
}

struct StateT * slot_156(struct StateT * v10006) {
  int v10007 = v10006->timer;
  int v10015 = v10007 + 1;
  v10006->timer = v10015;
  int * v10009 = v10006->regs;
  int v10010 = v10009[11];
  int * v10011 = v10006->regs;
  int v10019 = v10010 << 9;
  v10011[11] = v10019;
  struct StateT * v10013 = slot_157(v10006);
  return v10013;
}

struct StateT * slot_154(struct StateT * v9968) {
  int v9969 = v9968->timer;
  int v9979 = v9969 + 1;
  v9968->timer = v9979;
  int * v9971 = v9968->regs;
  int v9972 = v9971[16];
  int * v9973 = v9968->regs;
  int v9974 = v9973[22];
  int * v9975 = v9968->regs;
  int v9986 = v9972 + v9974;
  v9975[8] = v9986;
  struct StateT * v9977 = slot_155(v9968);
  return v9977;
}

struct StateT * slot_68(struct StateT * v4847) {
  int v4848 = v4847->timer;
  int v4858 = v4848 + 1;
  v4847->timer = v4858;
  int * v4850 = v4847->regs;
  int v4851 = v4850[13];
  int * v4852 = v4847->regs;
  int v4853 = v4852[9];
  int * v4854 = v4847->regs;
  int v4864 = v4851 ^ v4853;
  v4854[13] = v4864;
  struct StateT * v4856 = slot_69(v4847);
  return v4856;
}

struct StateT * slot_260(struct StateT * v7324) {
  int v7325 = v7324->timer;
  int v7379 = v7325 + 1;
  v7324->timer = v7379;
  int * v7327 = v7324->regs;
  int v7328 = v7327[10];
  int * v7329 = v7324->regs;
  int v7330 = v7329[1];
  int * v7331 = v7324->cache_keys;
  int v7332 = v7331[0];
  bool v7386 = v7332 == ((int)((unsigned int)(v7328 + 56) >> 2));
  int v7376;
  if (v7386) {
    int * v7333 = v7324->cache_vals;
    v7333[0] = v7330;
    v7376 = v7330;
  } else {
    int * v7336 = v7324->cache_keys;
    int v7337 = v7336[1];
    bool v7390 = v7337 == ((int)((unsigned int)(v7328 + 56) >> 2));
    int v7374;
    if (v7390) {
      int * v7338 = v7324->cache_keys;
      int * v7339 = v7324->cache_keys;
      int v7340 = v7339[0];
      v7338[1] = v7340;
      int * v7342 = v7324->cache_vals;
      int * v7343 = v7324->cache_vals;
      int v7344 = v7343[0];
      v7342[1] = v7344;
      int * v7346 = v7324->cache_keys;
      int v7398 = (int)((unsigned int)(v7328 + 56) >> 2);
      v7346[0] = v7398;
      int * v7348 = v7324->cache_vals;
      v7348[0] = v7330;
      int v7350 = v7324->timer;
      int v7401 = v7350 + 1;
      v7324->timer = v7401;
      v7374 = v7330;
    } else {
      int * v7353 = v7324->mem;
      int * v7354 = v7324->cache_keys;
      int v7355 = v7354[1];
      int * v7356 = v7324->cache_vals;
      int v7357 = v7356[1];
      v7353[v7355] = v7357;
      int * v7359 = v7324->cache_keys;
      int * v7360 = v7324->cache_keys;
      int v7361 = v7360[0];
      v7359[1] = v7361;
      int * v7363 = v7324->cache_vals;
      int * v7364 = v7324->cache_vals;
      int v7365 = v7364[0];
      v7363[1] = v7365;
      int * v7367 = v7324->cache_keys;
      int v7414 = (int)((unsigned int)(v7328 + 56) >> 2);
      v7367[0] = v7414;
      int * v7369 = v7324->cache_vals;
      v7369[0] = v7330;
      int v7371 = v7324->timer;
      int v7417 = v7371 + 100;
      v7324->timer = v7417;
      v7374 = v7330;
    }
    v7376 = v7374;
  }
  struct StateT * v7377 = slot_261(v7324);
  return v7377;
}

struct StateT * slot_105(struct StateT * v8272) {
  int v8273 = v8272->timer;
  int v8281 = v8273 + 1;
  v8272->timer = v8281;
  int * v8275 = v8272->regs;
  int v8276 = v8275[18];
  int * v8277 = v8272->regs;
  int v8285 = v8276 << 13;
  v8277[18] = v8285;
  struct StateT * v8279 = slot_106(v8272);
  return v8279;
}

struct StateT * slot_27(struct StateT * v2564) {
  int v2565 = v2564->timer;
  int v2571 = v2565 + 1;
  v2564->timer = v2571;
  int * v2567 = v2564->regs;
  v2567[12] = 1634762752;
  struct StateT * v2569 = slot_28(v2564);
  return v2569;
}

struct StateT * slot_164(struct StateT * v10148) {
  int v10149 = v10148->timer;
  int v10157 = v10149 + 1;
  v10148->timer = v10157;
  int * v10151 = v10148->regs;
  int v10152 = v10151[8];
  int * v10153 = v10148->regs;
  int v10162 = (int)((unsigned int)v10152 >> 23);
  v10153[9] = v10162;
  struct StateT * v10155 = slot_165(v10148);
  return v10155;
}

struct StateT * slot_15(struct StateT * v1304) {
  int v1305 = v1304->timer;
  int v1363 = v1305 + 1;
  v1304->timer = v1363;
  int * v1307 = v1304->regs;
  int v1308 = v1307[12];
  int * v1309 = v1304->cache_keys;
  int v1310 = v1309[0];
  bool v1368 = v1310 == ((int)((unsigned int)v1308 >> 2));
  int v1358;
  if (v1368) {
    int * v1311 = v1304->cache_vals;
    int v1312 = v1311[0];
    v1358 = v1312;
  } else {
    int * v1314 = v1304->cache_keys;
    int v1315 = v1314[1];
    bool v1373 = v1315 == ((int)((unsigned int)v1308 >> 2));
    int v1356;
    if (v1373) {
      int * v1316 = v1304->cache_vals;
      int v1317 = v1316[1];
      int * v1318 = v1304->cache_keys;
      int * v1319 = v1304->cache_keys;
      int v1320 = v1319[0];
      v1318[1] = v1320;
      int * v1322 = v1304->cache_vals;
      int * v1323 = v1304->cache_vals;
      int v1324 = v1323[0];
      v1322[1] = v1324;
      int * v1326 = v1304->cache_keys;
      int v1382 = (int)((unsigned int)v1308 >> 2);
      v1326[0] = v1382;
      int * v1328 = v1304->cache_vals;
      v1328[0] = v1317;
      int v1330 = v1304->timer;
      int v1385 = v1330 + 1;
      v1304->timer = v1385;
      v1356 = v1317;
    } else {
      int * v1333 = v1304->mem;
      int v1387 = (int)((unsigned int)v1308 >> 2);
      int v1334 = v1333[v1387];
      int * v1335 = v1304->mem;
      int * v1336 = v1304->cache_keys;
      int v1337 = v1336[1];
      int * v1338 = v1304->cache_vals;
      int v1339 = v1338[1];
      v1335[v1337] = v1339;
      int * v1341 = v1304->cache_keys;
      int * v1342 = v1304->cache_keys;
      int v1343 = v1342[0];
      v1341[1] = v1343;
      int * v1345 = v1304->cache_vals;
      int * v1346 = v1304->cache_vals;
      int v1347 = v1346[0];
      v1345[1] = v1347;
      int * v1349 = v1304->cache_keys;
      v1349[0] = v1387;
      int * v1351 = v1304->cache_vals;
      v1351[0] = v1334;
      int v1353 = v1304->timer;
      int v1402 = v1353 + 100;
      v1304->timer = v1402;
      v1356 = v1334;
    }
    v1358 = v1356;
  }
  int * v1359 = v1304->regs;
  v1359[29] = v1358;
  struct StateT * v1361 = slot_16(v1304);
  return v1361;
}

struct StateT * slot_133(struct StateT * v9567) {
  int v9568 = v9567->timer;
  int v9578 = v9568 + 1;
  v9567->timer = v9578;
  int * v9570 = v9567->regs;
  int v9571 = v9570[19];
  int * v9572 = v9567->regs;
  int v9573 = v9572[13];
  int * v9574 = v9567->regs;
  int v9585 = v9571 + v9573;
  v9574[16] = v9585;
  struct StateT * v9576 = slot_134(v9567);
  return v9576;
}

struct StateT * slot_56(struct StateT * v3981) {
  int v3982 = v3981->timer;
  int v3990 = v3982 + 1;
  v3981->timer = v3990;
  int * v3984 = v3981->regs;
  int v3985 = v3984[15];
  int * v3986 = v3981->regs;
  int v3994 = v3985 << 7;
  v3986[15] = v3994;
  struct StateT * v3988 = slot_57(v3981);
  return v3988;
}

struct StateT * slot_244(struct StateT * v5606) {
  int v5607 = v5606->timer;
  int v5617 = v5607 + 1;
  v5606->timer = v5617;
  int * v5609 = v5606->regs;
  int v5610 = v5609[19];
  int * v5611 = v5606->regs;
  int v5612 = v5611[7];
  int * v5613 = v5606->regs;
  int v5623 = v5610 + v5612;
  v5613[7] = v5623;
  struct StateT * v5615 = slot_245(v5606);
  return v5615;
}

struct StateT * slot_222(struct StateT * v4188) {
  int v4189 = v4188->timer;
  int v4247 = v4189 + 1;
  v4188->timer = v4247;
  int * v4191 = v4188->regs;
  int v4192 = v4191[2];
  int * v4193 = v4188->cache_keys;
  int v4194 = v4193[0];
  bool v4252 = v4194 == ((int)((unsigned int)(v4192 + 16) >> 2));
  int v4242;
  if (v4252) {
    int * v4195 = v4188->cache_vals;
    int v4196 = v4195[0];
    v4242 = v4196;
  } else {
    int * v4198 = v4188->cache_keys;
    int v4199 = v4198[1];
    bool v4257 = v4199 == ((int)((unsigned int)(v4192 + 16) >> 2));
    int v4240;
    if (v4257) {
      int * v4200 = v4188->cache_vals;
      int v4201 = v4200[1];
      int * v4202 = v4188->cache_keys;
      int * v4203 = v4188->cache_keys;
      int v4204 = v4203[0];
      v4202[1] = v4204;
      int * v4206 = v4188->cache_vals;
      int * v4207 = v4188->cache_vals;
      int v4208 = v4207[0];
      v4206[1] = v4208;
      int * v4210 = v4188->cache_keys;
      int v4266 = (int)((unsigned int)(v4192 + 16) >> 2);
      v4210[0] = v4266;
      int * v4212 = v4188->cache_vals;
      v4212[0] = v4201;
      int v4214 = v4188->timer;
      int v4269 = v4214 + 1;
      v4188->timer = v4269;
      v4240 = v4201;
    } else {
      int * v4217 = v4188->mem;
      int v4271 = (int)((unsigned int)(v4192 + 16) >> 2);
      int v4218 = v4217[v4271];
      int * v4219 = v4188->mem;
      int * v4220 = v4188->cache_keys;
      int v4221 = v4220[1];
      int * v4222 = v4188->cache_vals;
      int v4223 = v4222[1];
      v4219[v4221] = v4223;
      int * v4225 = v4188->cache_keys;
      int * v4226 = v4188->cache_keys;
      int v4227 = v4226[0];
      v4225[1] = v4227;
      int * v4229 = v4188->cache_vals;
      int * v4230 = v4188->cache_vals;
      int v4231 = v4230[0];
      v4229[1] = v4231;
      int * v4233 = v4188->cache_keys;
      v4233[0] = v4271;
      int * v4235 = v4188->cache_vals;
      v4235[0] = v4218;
      int v4237 = v4188->timer;
      int v4286 = v4237 + 100;
      v4188->timer = v4286;
      v4240 = v4218;
    }
    v4242 = v4240;
  }
  int * v4243 = v4188->regs;
  v4243[7] = v4242;
  struct StateT * v4245 = slot_223(v4188);
  return v4245;
}

struct StateT * slot_34(struct StateT * v2667) {
  int v2668 = v2667->timer;
  int v2676 = v2668 + 1;
  v2667->timer = v2676;
  int * v2670 = v2667->regs;
  int v2671 = v2670[22];
  int * v2672 = v2667->regs;
  int v2680 = v2671 + 1396;
  v2672[22] = v2680;
  struct StateT * v2674 = slot_35(v2667);
  return v2674;
}

struct StateT * slot_171(struct StateT * v10281) {
  int v10282 = v10281->timer;
  int v10292 = v10282 + 1;
  v10281->timer = v10292;
  int * v10284 = v10281->regs;
  int v10285 = v10284[27];
  int * v10286 = v10281->regs;
  int v10287 = v10286[23];
  int * v10288 = v10281->regs;
  int v10299 = v10285 + v10287;
  v10288[11] = v10299;
  struct StateT * v10290 = slot_172(v10281);
  return v10290;
}

struct StateT * slot_162(struct StateT * v10112) {
  int v10113 = v10112->timer;
  int v10121 = v10113 + 1;
  v10112->timer = v10121;
  int * v10115 = v10112->regs;
  int v10116 = v10115[6];
  int * v10117 = v10112->regs;
  int v10125 = v10116 << 9;
  v10117[6] = v10125;
  struct StateT * v10119 = slot_163(v10112);
  return v10119;
}

struct StateT * slot_21(struct StateT * v1934) {
  int v1935 = v1934->timer;
  int v1993 = v1935 + 1;
  v1934->timer = v1993;
  int * v1937 = v1934->regs;
  int v1938 = v1937[12];
  int * v1939 = v1934->cache_keys;
  int v1940 = v1939[0];
  bool v1998 = v1940 == ((int)((unsigned int)(v1938 + 24) >> 2));
  int v1988;
  if (v1998) {
    int * v1941 = v1934->cache_vals;
    int v1942 = v1941[0];
    v1988 = v1942;
  } else {
    int * v1944 = v1934->cache_keys;
    int v1945 = v1944[1];
    bool v2003 = v1945 == ((int)((unsigned int)(v1938 + 24) >> 2));
    int v1986;
    if (v2003) {
      int * v1946 = v1934->cache_vals;
      int v1947 = v1946[1];
      int * v1948 = v1934->cache_keys;
      int * v1949 = v1934->cache_keys;
      int v1950 = v1949[0];
      v1948[1] = v1950;
      int * v1952 = v1934->cache_vals;
      int * v1953 = v1934->cache_vals;
      int v1954 = v1953[0];
      v1952[1] = v1954;
      int * v1956 = v1934->cache_keys;
      int v2012 = (int)((unsigned int)(v1938 + 24) >> 2);
      v1956[0] = v2012;
      int * v1958 = v1934->cache_vals;
      v1958[0] = v1947;
      int v1960 = v1934->timer;
      int v2015 = v1960 + 1;
      v1934->timer = v2015;
      v1986 = v1947;
    } else {
      int * v1963 = v1934->mem;
      int v2017 = (int)((unsigned int)(v1938 + 24) >> 2);
      int v1964 = v1963[v2017];
      int * v1965 = v1934->mem;
      int * v1966 = v1934->cache_keys;
      int v1967 = v1966[1];
      int * v1968 = v1934->cache_vals;
      int v1969 = v1968[1];
      v1965[v1967] = v1969;
      int * v1971 = v1934->cache_keys;
      int * v1972 = v1934->cache_keys;
      int v1973 = v1972[0];
      v1971[1] = v1973;
      int * v1975 = v1934->cache_vals;
      int * v1976 = v1934->cache_vals;
      int v1977 = v1976[0];
      v1975[1] = v1977;
      int * v1979 = v1934->cache_keys;
      v1979[0] = v2017;
      int * v1981 = v1934->cache_vals;
      v1981[0] = v1964;
      int v1983 = v1934->timer;
      int v2032 = v1983 + 100;
      v1934->timer = v2032;
      v1986 = v1964;
    }
    v1988 = v1986;
  }
  int * v1989 = v1934->regs;
  v1989[24] = v1988;
  struct StateT * v1991 = slot_22(v1934);
  return v1991;
}

struct StateT * slot_239(struct StateT * v5428) {
  int v5429 = v5428->timer;
  int v5437 = v5429 + 1;
  v5428->timer = v5437;
  int * v5431 = v5428->regs;
  int v5432 = v5431[6];
  int * v5433 = v5428->regs;
  int v5441 = v5432 + 1134;
  v5433[6] = v5441;
  struct StateT * v5435 = slot_240(v5428);
  return v5435;
}

struct StateT * slot_118(struct StateT * v9285) {
  int v9286 = v9285->timer;
  int v9294 = v9286 + 1;
  v9285->timer = v9294;
  int * v9288 = v9285->regs;
  int v9289 = v9288[16];
  int * v9290 = v9285->regs;
  int v9299 = (int)((unsigned int)v9289 >> 14);
  v9290[6] = v9299;
  struct StateT * v9292 = slot_119(v9285);
  return v9292;
}

struct StateT * slot_121(struct StateT * v9338) {
  int v9339 = v9338->timer;
  int v9347 = v9339 + 1;
  v9338->timer = v9347;
  int * v9341 = v9338->regs;
  int v9342 = v9341[17];
  int * v9343 = v9338->regs;
  int v9352 = (int)((unsigned int)v9342 >> 14);
  v9343[6] = v9352;
  struct StateT * v9345 = slot_122(v9338);
  return v9345;
}

struct StateT * slot_144(struct StateT * v9768) {
  int v9769 = v9768->timer;
  int v9777 = v9769 + 1;
  v9768->timer = v9777;
  int * v9771 = v9768->regs;
  int v9772 = v9771[17];
  int * v9773 = v9768->regs;
  int v9782 = (int)((unsigned int)v9772 >> 25);
  v9773[5] = v9782;
  struct StateT * v9775 = slot_145(v9768);
  return v9775;
}

struct StateT * slot_267(struct StateT * v8167) {
  int v8168 = v8167->timer;
  int v8226 = v8168 + 1;
  v8167->timer = v8226;
  int * v8170 = v8167->regs;
  int v8171 = v8170[2];
  int * v8172 = v8167->cache_keys;
  int v8173 = v8172[0];
  bool v8231 = v8173 == ((int)((unsigned int)(v8171 + 72) >> 2));
  int v8221;
  if (v8231) {
    int * v8174 = v8167->cache_vals;
    int v8175 = v8174[0];
    v8221 = v8175;
  } else {
    int * v8177 = v8167->cache_keys;
    int v8178 = v8177[1];
    bool v8236 = v8178 == ((int)((unsigned int)(v8171 + 72) >> 2));
    int v8219;
    if (v8236) {
      int * v8179 = v8167->cache_vals;
      int v8180 = v8179[1];
      int * v8181 = v8167->cache_keys;
      int * v8182 = v8167->cache_keys;
      int v8183 = v8182[0];
      v8181[1] = v8183;
      int * v8185 = v8167->cache_vals;
      int * v8186 = v8167->cache_vals;
      int v8187 = v8186[0];
      v8185[1] = v8187;
      int * v8189 = v8167->cache_keys;
      int v8245 = (int)((unsigned int)(v8171 + 72) >> 2);
      v8189[0] = v8245;
      int * v8191 = v8167->cache_vals;
      v8191[0] = v8180;
      int v8193 = v8167->timer;
      int v8248 = v8193 + 1;
      v8167->timer = v8248;
      v8219 = v8180;
    } else {
      int * v8196 = v8167->mem;
      int v8250 = (int)((unsigned int)(v8171 + 72) >> 2);
      int v8197 = v8196[v8250];
      int * v8198 = v8167->mem;
      int * v8199 = v8167->cache_keys;
      int v8200 = v8199[1];
      int * v8201 = v8167->cache_vals;
      int v8202 = v8201[1];
      v8198[v8200] = v8202;
      int * v8204 = v8167->cache_keys;
      int * v8205 = v8167->cache_keys;
      int v8206 = v8205[0];
      v8204[1] = v8206;
      int * v8208 = v8167->cache_vals;
      int * v8209 = v8167->cache_vals;
      int v8210 = v8209[0];
      v8208[1] = v8210;
      int * v8212 = v8167->cache_keys;
      v8212[0] = v8250;
      int * v8214 = v8167->cache_vals;
      v8214[0] = v8197;
      int v8216 = v8167->timer;
      int v8265 = v8216 + 100;
      v8167->timer = v8265;
      v8219 = v8197;
    }
    v8221 = v8219;
  }
  int * v8222 = v8167->regs;
  v8222[20] = v8221;
  struct StateT * v8224 = slot_268(v8167);
  return v8224;
}

struct StateT * slot_201(struct StateT * v10847) {
  int v10848 = v10847->timer;
  int v10856 = v10848 + 1;
  v10847->timer = v10856;
  int * v10850 = v10847->regs;
  int v10851 = v10850[6];
  int * v10852 = v10847->regs;
  int v10861 = (int)((unsigned int)v10851 >> 14);
  v10852[9] = v10861;
  struct StateT * v10854 = slot_202(v10847);
  return v10854;
}

struct StateT * slot_94(struct StateT * v6956) {
  int v6957 = v6956->timer;
  int v6967 = v6957 + 1;
  v6956->timer = v6967;
  int * v6959 = v6956->regs;
  int v6960 = v6959[25];
  int * v6961 = v6956->regs;
  int v6962 = v6961[14];
  int * v6963 = v6956->regs;
  int v6974 = v6960 + v6962;
  v6963[18] = v6974;
  struct StateT * v6965 = slot_95(v6956);
  return v6965;
}

struct StateT * slot_63(struct StateT * v4491) {
  int v4492 = v4491->timer;
  int v4502 = v4492 + 1;
  v4491->timer = v4502;
  int * v4494 = v4491->regs;
  int v4495 = v4494[18];
  int * v4496 = v4491->regs;
  int v4497 = v4496[20];
  int * v4498 = v4491->regs;
  int v4508 = v4495 | v4497;
  v4498[18] = v4508;
  struct StateT * v4500 = slot_64(v4491);
  return v4500;
}

struct StateT * slot_146(struct StateT * v9801) {
  int v9802 = v9801->timer;
  int v9812 = v9802 + 1;
  v9801->timer = v9812;
  int * v9804 = v9801->regs;
  int v9805 = v9804[17];
  int * v9806 = v9801->regs;
  int v9807 = v9806[5];
  int * v9808 = v9801->regs;
  int v9819 = v9805 | v9807;
  v9808[6] = v9819;
  struct StateT * v9810 = slot_147(v9801);
  return v9810;
}

struct StateT * slot_24(struct StateT * v2249) {
  int v2250 = v2249->timer;
  int v2308 = v2250 + 1;
  v2249->timer = v2308;
  int * v2252 = v2249->regs;
  int v2253 = v2252[11];
  int * v2254 = v2249->cache_keys;
  int v2255 = v2254[0];
  bool v2313 = v2255 == ((int)((unsigned int)(v2253 + 4) >> 2));
  int v2303;
  if (v2313) {
    int * v2256 = v2249->cache_vals;
    int v2257 = v2256[0];
    v2303 = v2257;
  } else {
    int * v2259 = v2249->cache_keys;
    int v2260 = v2259[1];
    bool v2318 = v2260 == ((int)((unsigned int)(v2253 + 4) >> 2));
    int v2301;
    if (v2318) {
      int * v2261 = v2249->cache_vals;
      int v2262 = v2261[1];
      int * v2263 = v2249->cache_keys;
      int * v2264 = v2249->cache_keys;
      int v2265 = v2264[0];
      v2263[1] = v2265;
      int * v2267 = v2249->cache_vals;
      int * v2268 = v2249->cache_vals;
      int v2269 = v2268[0];
      v2267[1] = v2269;
      int * v2271 = v2249->cache_keys;
      int v2327 = (int)((unsigned int)(v2253 + 4) >> 2);
      v2271[0] = v2327;
      int * v2273 = v2249->cache_vals;
      v2273[0] = v2262;
      int v2275 = v2249->timer;
      int v2330 = v2275 + 1;
      v2249->timer = v2330;
      v2301 = v2262;
    } else {
      int * v2278 = v2249->mem;
      int v2332 = (int)((unsigned int)(v2253 + 4) >> 2);
      int v2279 = v2278[v2332];
      int * v2280 = v2249->mem;
      int * v2281 = v2249->cache_keys;
      int v2282 = v2281[1];
      int * v2283 = v2249->cache_vals;
      int v2284 = v2283[1];
      v2280[v2282] = v2284;
      int * v2286 = v2249->cache_keys;
      int * v2287 = v2249->cache_keys;
      int v2288 = v2287[0];
      v2286[1] = v2288;
      int * v2290 = v2249->cache_vals;
      int * v2291 = v2249->cache_vals;
      int v2292 = v2291[0];
      v2290[1] = v2292;
      int * v2294 = v2249->cache_keys;
      v2294[0] = v2332;
      int * v2296 = v2249->cache_vals;
      v2296[0] = v2279;
      int v2298 = v2249->timer;
      int v2347 = v2298 + 100;
      v2249->timer = v2347;
      v2301 = v2279;
    }
    v2303 = v2301;
  }
  int * v2304 = v2249->regs;
  v2304[25] = v2303;
  struct StateT * v2306 = slot_25(v2249);
  return v2306;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v15 = v6 + -96;
  v7[2] = v15;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_195(struct StateT * v10741) {
  int v10742 = v10741->timer;
  int v10750 = v10742 + 1;
  v10741->timer = v10750;
  int * v10744 = v10741->regs;
  int v10745 = v10744[11];
  int * v10746 = v10741->regs;
  int v10755 = (int)((unsigned int)v10745 >> 14);
  v10746[9] = v10755;
  struct StateT * v10748 = slot_196(v10741);
  return v10748;
}

struct StateT * slot_125(struct StateT * v9408) {
  int v9409 = v9408->timer;
  int v9417 = v9409 + 1;
  v9408->timer = v9417;
  int * v9411 = v9408->regs;
  int v9412 = v9411[5];
  int * v9413 = v9408->regs;
  int v9421 = v9412 << 18;
  v9413[5] = v9421;
  struct StateT * v9415 = slot_126(v9408);
  return v9415;
}

struct StateT * slot_254(struct StateT * v6620) {
  int v6621 = v6620->timer;
  int v6675 = v6621 + 1;
  v6620->timer = v6675;
  int * v6623 = v6620->regs;
  int v6624 = v6623[10];
  int * v6625 = v6620->regs;
  int v6626 = v6625[26];
  int * v6627 = v6620->cache_keys;
  int v6628 = v6627[0];
  bool v6682 = v6628 == ((int)((unsigned int)(v6624 + 32) >> 2));
  int v6672;
  if (v6682) {
    int * v6629 = v6620->cache_vals;
    v6629[0] = v6626;
    v6672 = v6626;
  } else {
    int * v6632 = v6620->cache_keys;
    int v6633 = v6632[1];
    bool v6687 = v6633 == ((int)((unsigned int)(v6624 + 32) >> 2));
    int v6670;
    if (v6687) {
      int * v6634 = v6620->cache_keys;
      int * v6635 = v6620->cache_keys;
      int v6636 = v6635[0];
      v6634[1] = v6636;
      int * v6638 = v6620->cache_vals;
      int * v6639 = v6620->cache_vals;
      int v6640 = v6639[0];
      v6638[1] = v6640;
      int * v6642 = v6620->cache_keys;
      int v6695 = (int)((unsigned int)(v6624 + 32) >> 2);
      v6642[0] = v6695;
      int * v6644 = v6620->cache_vals;
      v6644[0] = v6626;
      int v6646 = v6620->timer;
      int v6698 = v6646 + 1;
      v6620->timer = v6698;
      v6670 = v6626;
    } else {
      int * v6649 = v6620->mem;
      int * v6650 = v6620->cache_keys;
      int v6651 = v6650[1];
      int * v6652 = v6620->cache_vals;
      int v6653 = v6652[1];
      v6649[v6651] = v6653;
      int * v6655 = v6620->cache_keys;
      int * v6656 = v6620->cache_keys;
      int v6657 = v6656[0];
      v6655[1] = v6657;
      int * v6659 = v6620->cache_vals;
      int * v6660 = v6620->cache_vals;
      int v6661 = v6660[0];
      v6659[1] = v6661;
      int * v6663 = v6620->cache_keys;
      int v6711 = (int)((unsigned int)(v6624 + 32) >> 2);
      v6663[0] = v6711;
      int * v6665 = v6620->cache_vals;
      v6665[0] = v6626;
      int v6667 = v6620->timer;
      int v6714 = v6667 + 100;
      v6620->timer = v6714;
      v6670 = v6626;
    }
    v6672 = v6670;
  }
  struct StateT * v6673 = slot_255(v6620);
  return v6673;
}

struct StateT * slot_148(struct StateT * v9842) {
  int v9843 = v9842->timer;
  int v9853 = v9843 + 1;
  v9842->timer = v9853;
  int * v9845 = v9842->regs;
  int v9846 = v9845[18];
  int * v9847 = v9842->regs;
  int v9848 = v9847[11];
  int * v9849 = v9842->regs;
  int v9860 = v9846 ^ v9848;
  v9849[5] = v9860;
  struct StateT * v9851 = slot_149(v9842);
  return v9851;
}

struct StateT * slot_126(struct StateT * v9424) {
  int v9425 = v9424->timer;
  int v9435 = v9425 + 1;
  v9424->timer = v9435;
  int * v9427 = v9424->regs;
  int v9428 = v9427[5];
  int * v9429 = v9424->regs;
  int v9430 = v9429[6];
  int * v9431 = v9424->regs;
  int v9441 = v9428 | v9430;
  v9431[5] = v9441;
  struct StateT * v9433 = slot_127(v9424);
  return v9433;
}

struct StateT * slot_223(struct StateT * v4313) {
  int v4314 = v4313->timer;
  int v4324 = v4314 + 1;
  v4313->timer = v4324;
  int * v4316 = v4313->regs;
  int v4317 = v4316[25];
  int * v4318 = v4313->regs;
  int v4319 = v4318[7];
  int * v4320 = v4313->regs;
  int v4330 = v4317 + v4319;
  v4320[25] = v4330;
  struct StateT * v4322 = slot_224(v4313);
  return v4322;
}

struct StateT * slot_79(struct StateT * v5513) {
  int v5514 = v5513->timer;
  int v5522 = v5514 + 1;
  v5513->timer = v5522;
  int * v5516 = v5513->regs;
  int v5517 = v5516[8];
  int * v5518 = v5513->regs;
  int v5526 = v5517 << 9;
  v5518[8] = v5526;
  struct StateT * v5520 = slot_80(v5513);
  return v5520;
}

struct StateT * slot_237(struct StateT * v5366) {
  int v5367 = v5366->timer;
  int v5373 = v5367 + 1;
  v5366->timer = v5373;
  int * v5369 = v5366->regs;
  v5369[30] = 1797283840;
  struct StateT * v5371 = slot_238(v5366);
  return v5371;
}

struct StateT * slot_41(struct StateT * v3185) {
  int v3186 = v3185->timer;
  int v3240 = v3186 + 1;
  v3185->timer = v3240;
  int * v3188 = v3185->regs;
  int v3189 = v3188[2];
  int * v3190 = v3185->regs;
  int v3191 = v3190[16];
  int * v3192 = v3185->cache_keys;
  int v3193 = v3192[0];
  bool v3247 = v3193 == ((int)((unsigned int)(v3189 + 32) >> 2));
  int v3237;
  if (v3247) {
    int * v3194 = v3185->cache_vals;
    v3194[0] = v3191;
    v3237 = v3191;
  } else {
    int * v3197 = v3185->cache_keys;
    int v3198 = v3197[1];
    bool v3252 = v3198 == ((int)((unsigned int)(v3189 + 32) >> 2));
    int v3235;
    if (v3252) {
      int * v3199 = v3185->cache_keys;
      int * v3200 = v3185->cache_keys;
      int v3201 = v3200[0];
      v3199[1] = v3201;
      int * v3203 = v3185->cache_vals;
      int * v3204 = v3185->cache_vals;
      int v3205 = v3204[0];
      v3203[1] = v3205;
      int * v3207 = v3185->cache_keys;
      int v3260 = (int)((unsigned int)(v3189 + 32) >> 2);
      v3207[0] = v3260;
      int * v3209 = v3185->cache_vals;
      v3209[0] = v3191;
      int v3211 = v3185->timer;
      int v3263 = v3211 + 1;
      v3185->timer = v3263;
      v3235 = v3191;
    } else {
      int * v3214 = v3185->mem;
      int * v3215 = v3185->cache_keys;
      int v3216 = v3215[1];
      int * v3217 = v3185->cache_vals;
      int v3218 = v3217[1];
      v3214[v3216] = v3218;
      int * v3220 = v3185->cache_keys;
      int * v3221 = v3185->cache_keys;
      int v3222 = v3221[0];
      v3220[1] = v3222;
      int * v3224 = v3185->cache_vals;
      int * v3225 = v3185->cache_vals;
      int v3226 = v3225[0];
      v3224[1] = v3226;
      int * v3228 = v3185->cache_keys;
      int v3276 = (int)((unsigned int)(v3189 + 32) >> 2);
      v3228[0] = v3276;
      int * v3230 = v3185->cache_vals;
      v3230[0] = v3191;
      int v3232 = v3185->timer;
      int v3279 = v3232 + 100;
      v3185->timer = v3279;
      v3235 = v3191;
    }
    v3237 = v3235;
  }
  struct StateT * v3238 = slot_42(v3185);
  return v3238;
}

struct StateT * slot_39(struct StateT * v2990) {
  int v2991 = v2990->timer;
  int v3045 = v2991 + 1;
  v2990->timer = v3045;
  int * v2993 = v2990->regs;
  int v2994 = v2993[2];
  int * v2995 = v2990->regs;
  int v2996 = v2995[1];
  int * v2997 = v2990->cache_keys;
  int v2998 = v2997[0];
  bool v3052 = v2998 == ((int)((unsigned int)(v2994 + 40) >> 2));
  int v3042;
  if (v3052) {
    int * v2999 = v2990->cache_vals;
    v2999[0] = v2996;
    v3042 = v2996;
  } else {
    int * v3002 = v2990->cache_keys;
    int v3003 = v3002[1];
    bool v3056 = v3003 == ((int)((unsigned int)(v2994 + 40) >> 2));
    int v3040;
    if (v3056) {
      int * v3004 = v2990->cache_keys;
      int * v3005 = v2990->cache_keys;
      int v3006 = v3005[0];
      v3004[1] = v3006;
      int * v3008 = v2990->cache_vals;
      int * v3009 = v2990->cache_vals;
      int v3010 = v3009[0];
      v3008[1] = v3010;
      int * v3012 = v2990->cache_keys;
      int v3064 = (int)((unsigned int)(v2994 + 40) >> 2);
      v3012[0] = v3064;
      int * v3014 = v2990->cache_vals;
      v3014[0] = v2996;
      int v3016 = v2990->timer;
      int v3067 = v3016 + 1;
      v2990->timer = v3067;
      v3040 = v2996;
    } else {
      int * v3019 = v2990->mem;
      int * v3020 = v2990->cache_keys;
      int v3021 = v3020[1];
      int * v3022 = v2990->cache_vals;
      int v3023 = v3022[1];
      v3019[v3021] = v3023;
      int * v3025 = v2990->cache_keys;
      int * v3026 = v2990->cache_keys;
      int v3027 = v3026[0];
      v3025[1] = v3027;
      int * v3029 = v2990->cache_vals;
      int * v3030 = v2990->cache_vals;
      int v3031 = v3030[0];
      v3029[1] = v3031;
      int * v3033 = v2990->cache_keys;
      int v3080 = (int)((unsigned int)(v2994 + 40) >> 2);
      v3033[0] = v3080;
      int * v3035 = v2990->cache_vals;
      v3035[0] = v2996;
      int v3037 = v2990->timer;
      int v3083 = v3037 + 100;
      v2990->timer = v3083;
      v3040 = v2996;
    }
    v3042 = v3040;
  }
  struct StateT * v3043 = slot_40(v2990);
  return v3043;
}

struct StateT * slot_142(struct StateT * v9732) {
  int v9733 = v9732->timer;
  int v9741 = v9733 + 1;
  v9732->timer = v9741;
  int * v9735 = v9732->regs;
  int v9736 = v9735[16];
  int * v9737 = v9732->regs;
  int v9745 = v9736 << 7;
  v9737[16] = v9745;
  struct StateT * v9739 = slot_143(v9732);
  return v9739;
}

struct StateT * slot_60(struct StateT * v4293) {
  int v4294 = v4293->timer;
  int v4304 = v4294 + 1;
  v4293->timer = v4304;
  int * v4296 = v4293->regs;
  int v4297 = v4296[20];
  int * v4298 = v4293->regs;
  int v4299 = v4298[9];
  int * v4300 = v4293->regs;
  int v4310 = v4297 | v4299;
  v4300[9] = v4310;
  struct StateT * v4302 = slot_61(v4293);
  return v4302;
}

struct StateT * slot_238(struct StateT * v5396) {
  int v5397 = v5396->timer;
  int v5405 = v5397 + 1;
  v5396->timer = v5405;
  int * v5399 = v5396->regs;
  int v5400 = v5399[15];
  int * v5401 = v5396->regs;
  int v5409 = v5400 + -1947;
  v5401[15] = v5409;
  struct StateT * v5403 = slot_239(v5396);
  return v5403;
}

struct StateT * slot_112(struct StateT * v9148) {
  int v9149 = v9148->timer;
  int v9159 = v9149 + 1;
  v9148->timer = v9159;
  int * v9151 = v9148->regs;
  int v9152 = v9151[23];
  int * v9153 = v9148->regs;
  int v9154 = v9153[24];
  int * v9155 = v9148->regs;
  int v9166 = v9152 + v9154;
  v9155[16] = v9166;
  struct StateT * v9157 = slot_113(v9148);
  return v9157;
}

struct StateT * slot_256(struct StateT * v6858) {
  int v6859 = v6858->timer;
  int v6913 = v6859 + 1;
  v6858->timer = v6913;
  int * v6861 = v6858->regs;
  int v6862 = v6861[10];
  int * v6863 = v6858->regs;
  int v6864 = v6863[7];
  int * v6865 = v6858->cache_keys;
  int v6866 = v6865[0];
  bool v6920 = v6866 == ((int)((unsigned int)(v6862 + 40) >> 2));
  int v6910;
  if (v6920) {
    int * v6867 = v6858->cache_vals;
    v6867[0] = v6864;
    v6910 = v6864;
  } else {
    int * v6870 = v6858->cache_keys;
    int v6871 = v6870[1];
    bool v6925 = v6871 == ((int)((unsigned int)(v6862 + 40) >> 2));
    int v6908;
    if (v6925) {
      int * v6872 = v6858->cache_keys;
      int * v6873 = v6858->cache_keys;
      int v6874 = v6873[0];
      v6872[1] = v6874;
      int * v6876 = v6858->cache_vals;
      int * v6877 = v6858->cache_vals;
      int v6878 = v6877[0];
      v6876[1] = v6878;
      int * v6880 = v6858->cache_keys;
      int v6933 = (int)((unsigned int)(v6862 + 40) >> 2);
      v6880[0] = v6933;
      int * v6882 = v6858->cache_vals;
      v6882[0] = v6864;
      int v6884 = v6858->timer;
      int v6936 = v6884 + 1;
      v6858->timer = v6936;
      v6908 = v6864;
    } else {
      int * v6887 = v6858->mem;
      int * v6888 = v6858->cache_keys;
      int v6889 = v6888[1];
      int * v6890 = v6858->cache_vals;
      int v6891 = v6890[1];
      v6887[v6889] = v6891;
      int * v6893 = v6858->cache_keys;
      int * v6894 = v6858->cache_keys;
      int v6895 = v6894[0];
      v6893[1] = v6895;
      int * v6897 = v6858->cache_vals;
      int * v6898 = v6858->cache_vals;
      int v6899 = v6898[0];
      v6897[1] = v6899;
      int * v6901 = v6858->cache_keys;
      int v6949 = (int)((unsigned int)(v6862 + 40) >> 2);
      v6901[0] = v6949;
      int * v6903 = v6858->cache_vals;
      v6903[0] = v6864;
      int v6905 = v6858->timer;
      int v6952 = v6905 + 100;
      v6858->timer = v6952;
      v6908 = v6864;
    }
    v6910 = v6908;
  }
  struct StateT * v6911 = slot_257(v6858);
  return v6911;
}

struct StateT * slot_272(struct StateT * v8791) {
  int v8792 = v8791->timer;
  int v8850 = v8792 + 1;
  v8791->timer = v8850;
  int * v8794 = v8791->regs;
  int v8795 = v8794[2];
  int * v8796 = v8791->cache_keys;
  int v8797 = v8796[0];
  bool v8855 = v8797 == ((int)((unsigned int)(v8795 + 52) >> 2));
  int v8845;
  if (v8855) {
    int * v8798 = v8791->cache_vals;
    int v8799 = v8798[0];
    v8845 = v8799;
  } else {
    int * v8801 = v8791->cache_keys;
    int v8802 = v8801[1];
    bool v8860 = v8802 == ((int)((unsigned int)(v8795 + 52) >> 2));
    int v8843;
    if (v8860) {
      int * v8803 = v8791->cache_vals;
      int v8804 = v8803[1];
      int * v8805 = v8791->cache_keys;
      int * v8806 = v8791->cache_keys;
      int v8807 = v8806[0];
      v8805[1] = v8807;
      int * v8809 = v8791->cache_vals;
      int * v8810 = v8791->cache_vals;
      int v8811 = v8810[0];
      v8809[1] = v8811;
      int * v8813 = v8791->cache_keys;
      int v8869 = (int)((unsigned int)(v8795 + 52) >> 2);
      v8813[0] = v8869;
      int * v8815 = v8791->cache_vals;
      v8815[0] = v8804;
      int v8817 = v8791->timer;
      int v8872 = v8817 + 1;
      v8791->timer = v8872;
      v8843 = v8804;
    } else {
      int * v8820 = v8791->mem;
      int v8874 = (int)((unsigned int)(v8795 + 52) >> 2);
      int v8821 = v8820[v8874];
      int * v8822 = v8791->mem;
      int * v8823 = v8791->cache_keys;
      int v8824 = v8823[1];
      int * v8825 = v8791->cache_vals;
      int v8826 = v8825[1];
      v8822[v8824] = v8826;
      int * v8828 = v8791->cache_keys;
      int * v8829 = v8791->cache_keys;
      int v8830 = v8829[0];
      v8828[1] = v8830;
      int * v8832 = v8791->cache_vals;
      int * v8833 = v8791->cache_vals;
      int v8834 = v8833[0];
      v8832[1] = v8834;
      int * v8836 = v8791->cache_keys;
      v8836[0] = v8874;
      int * v8838 = v8791->cache_vals;
      v8838[0] = v8821;
      int v8840 = v8791->timer;
      int v8889 = v8840 + 100;
      v8791->timer = v8889;
      v8843 = v8821;
    }
    v8845 = v8843;
  }
  int * v8846 = v8791->regs;
  v8846[25] = v8845;
  struct StateT * v8848 = slot_273(v8791);
  return v8848;
}

struct StateT * slot_47(struct StateT * v3530) {
  int v3531 = v3530->timer;
  int v3539 = v3531 + 1;
  v3530->timer = v3539;
  int * v3533 = v3530->regs;
  int v3534 = v3533[29];
  int * v3535 = v3530->regs;
  v3535[23] = v3534;
  struct StateT * v3537 = slot_48(v3530);
  return v3537;
}

struct StateT * slot_214(struct StateT * v3723) {
  int v3724 = v3723->timer;
  int v3734 = v3724 + 1;
  v3723->timer = v3734;
  int * v3726 = v3723->regs;
  int v3727 = v3726[27];
  int * v3728 = v3723->regs;
  int v3729 = v3728[28];
  int * v3730 = v3723->regs;
  int v3740 = v3727 + v3729;
  v3730[28] = v3740;
  struct StateT * v3732 = slot_215(v3723);
  return v3732;
}

struct StateT * slot_29(struct StateT * v2590) {
  int v2591 = v2590->timer;
  int v2597 = v2591 + 1;
  v2590->timer = v2597;
  int * v2593 = v2590->regs;
  v2593[14] = 2036477952;
  struct StateT * v2595 = slot_30(v2590);
  return v2595;
}

struct StateT * slot_16(struct StateT * v1409) {
  int v1410 = v1409->timer;
  int v1468 = v1410 + 1;
  v1409->timer = v1468;
  int * v1412 = v1409->regs;
  int v1413 = v1412[12];
  int * v1414 = v1409->cache_keys;
  int v1415 = v1414[0];
  bool v1473 = v1415 == ((int)((unsigned int)(v1413 + 4) >> 2));
  int v1463;
  if (v1473) {
    int * v1416 = v1409->cache_vals;
    int v1417 = v1416[0];
    v1463 = v1417;
  } else {
    int * v1419 = v1409->cache_keys;
    int v1420 = v1419[1];
    bool v1478 = v1420 == ((int)((unsigned int)(v1413 + 4) >> 2));
    int v1461;
    if (v1478) {
      int * v1421 = v1409->cache_vals;
      int v1422 = v1421[1];
      int * v1423 = v1409->cache_keys;
      int * v1424 = v1409->cache_keys;
      int v1425 = v1424[0];
      v1423[1] = v1425;
      int * v1427 = v1409->cache_vals;
      int * v1428 = v1409->cache_vals;
      int v1429 = v1428[0];
      v1427[1] = v1429;
      int * v1431 = v1409->cache_keys;
      int v1487 = (int)((unsigned int)(v1413 + 4) >> 2);
      v1431[0] = v1487;
      int * v1433 = v1409->cache_vals;
      v1433[0] = v1422;
      int v1435 = v1409->timer;
      int v1490 = v1435 + 1;
      v1409->timer = v1490;
      v1461 = v1422;
    } else {
      int * v1438 = v1409->mem;
      int v1492 = (int)((unsigned int)(v1413 + 4) >> 2);
      int v1439 = v1438[v1492];
      int * v1440 = v1409->mem;
      int * v1441 = v1409->cache_keys;
      int v1442 = v1441[1];
      int * v1443 = v1409->cache_vals;
      int v1444 = v1443[1];
      v1440[v1442] = v1444;
      int * v1446 = v1409->cache_keys;
      int * v1447 = v1409->cache_keys;
      int v1448 = v1447[0];
      v1446[1] = v1448;
      int * v1450 = v1409->cache_vals;
      int * v1451 = v1409->cache_vals;
      int v1452 = v1451[0];
      v1450[1] = v1452;
      int * v1454 = v1409->cache_keys;
      v1454[0] = v1492;
      int * v1456 = v1409->cache_vals;
      v1456[0] = v1439;
      int v1458 = v1409->timer;
      int v1507 = v1458 + 100;
      v1409->timer = v1507;
      v1461 = v1439;
    }
    v1463 = v1461;
  }
  int * v1464 = v1409->regs;
  v1464[28] = v1463;
  struct StateT * v1466 = slot_17(v1409);
  return v1466;
}

struct StateT * slot_245(struct StateT * v5642) {
  int v5643 = v5642->timer;
  int v5653 = v5643 + 1;
  v5642->timer = v5653;
  int * v5645 = v5642->regs;
  int v5646 = v5645[22];
  int * v5647 = v5642->regs;
  int v5648 = v5647[30];
  int * v5649 = v5642->regs;
  int v5659 = v5646 + v5648;
  v5649[30] = v5659;
  struct StateT * v5651 = slot_246(v5642);
  return v5651;
}

struct StateT * slot_113(struct StateT * v9185) {
  int v9186 = v9185->timer;
  int v9196 = v9186 + 1;
  v9185->timer = v9196;
  int * v9188 = v9185->regs;
  int v9189 = v9188[18];
  int * v9190 = v9185->regs;
  int v9191 = v9190[27];
  int * v9192 = v9185->regs;
  int v9203 = v9189 + v9191;
  v9192[17] = v9203;
  struct StateT * v9194 = slot_114(v9185);
  return v9194;
}

struct StateT * slot_151(struct StateT * v9905) {
  int v9906 = v9905->timer;
  int v9916 = v9906 + 1;
  v9905->timer = v9916;
  int * v9908 = v9905->regs;
  int v9909 = v9908[23];
  int * v9910 = v9905->regs;
  int v9911 = v9910[21];
  int * v9912 = v9905->regs;
  int v9923 = v9909 + v9911;
  v9912[11] = v9923;
  struct StateT * v9914 = slot_152(v9905);
  return v9914;
}

struct StateT * slot_7(struct StateT * v605) {
  int v606 = v605->timer;
  int v660 = v606 + 1;
  v605->timer = v660;
  int * v608 = v605->regs;
  int v609 = v608[2];
  int * v610 = v605->regs;
  int v611 = v610[21];
  int * v612 = v605->cache_keys;
  int v613 = v612[0];
  bool v667 = v613 == ((int)((unsigned int)(v609 + 68) >> 2));
  int v657;
  if (v667) {
    int * v614 = v605->cache_vals;
    v614[0] = v611;
    v657 = v611;
  } else {
    int * v617 = v605->cache_keys;
    int v618 = v617[1];
    bool v672 = v618 == ((int)((unsigned int)(v609 + 68) >> 2));
    int v655;
    if (v672) {
      int * v619 = v605->cache_keys;
      int * v620 = v605->cache_keys;
      int v621 = v620[0];
      v619[1] = v621;
      int * v623 = v605->cache_vals;
      int * v624 = v605->cache_vals;
      int v625 = v624[0];
      v623[1] = v625;
      int * v627 = v605->cache_keys;
      int v680 = (int)((unsigned int)(v609 + 68) >> 2);
      v627[0] = v680;
      int * v629 = v605->cache_vals;
      v629[0] = v611;
      int v631 = v605->timer;
      int v683 = v631 + 1;
      v605->timer = v683;
      v655 = v611;
    } else {
      int * v634 = v605->mem;
      int * v635 = v605->cache_keys;
      int v636 = v635[1];
      int * v637 = v605->cache_vals;
      int v638 = v637[1];
      v634[v636] = v638;
      int * v640 = v605->cache_keys;
      int * v641 = v605->cache_keys;
      int v642 = v641[0];
      v640[1] = v642;
      int * v644 = v605->cache_vals;
      int * v645 = v605->cache_vals;
      int v646 = v645[0];
      v644[1] = v646;
      int * v648 = v605->cache_keys;
      int v696 = (int)((unsigned int)(v609 + 68) >> 2);
      v648[0] = v696;
      int * v650 = v605->cache_vals;
      v650[0] = v611;
      int v652 = v605->timer;
      int v699 = v652 + 100;
      v605->timer = v699;
      v655 = v611;
    }
    v657 = v655;
  }
  struct StateT * v658 = slot_8(v605);
  return v658;
}

struct StateT * slot_124(struct StateT * v9391) {
  int v9392 = v9391->timer;
  int v9400 = v9392 + 1;
  v9391->timer = v9400;
  int * v9394 = v9391->regs;
  int v9395 = v9394[5];
  int * v9396 = v9391->regs;
  int v9405 = (int)((unsigned int)v9395 >> 14);
  v9396[6] = v9405;
  struct StateT * v9398 = slot_125(v9391);
  return v9398;
}

struct StateT * slot_191(struct StateT * v10657) {
  int v10658 = v10657->timer;
  int v10668 = v10658 + 1;
  v10657->timer = v10668;
  int * v10660 = v10657->regs;
  int v10661 = v10660[14];
  int * v10662 = v10657->regs;
  int v10663 = v10662[27];
  int * v10664 = v10657->regs;
  int v10675 = v10661 + v10663;
  v10664[11] = v10675;
  struct StateT * v10666 = slot_192(v10657);
  return v10666;
}

struct StateT * slot_103(struct StateT * v8025) {
  int v8026 = v8025->timer;
  int v8036 = v8026 + 1;
  v8025->timer = v8036;
  int * v8028 = v8025->regs;
  int v8029 = v8028[9];
  int * v8030 = v8025->regs;
  int v8031 = v8030[20];
  int * v8032 = v8025->regs;
  int v8042 = v8029 | v8031;
  v8032[20] = v8042;
  struct StateT * v8034 = slot_104(v8025);
  return v8034;
}

struct StateT * slot_128(struct StateT * v9464) {
  int v9465 = v9464->timer;
  int v9475 = v9465 + 1;
  v9464->timer = v9475;
  int * v9467 = v9464->regs;
  int v9468 = v9467[11];
  int * v9469 = v9464->regs;
  int v9470 = v9469[16];
  int * v9471 = v9464->regs;
  int v9482 = v9468 ^ v9470;
  v9471[20] = v9482;
  struct StateT * v9473 = slot_129(v9464);
  return v9473;
}

struct StateT * slot_19(struct StateT * v1724) {
  int v1725 = v1724->timer;
  int v1783 = v1725 + 1;
  v1724->timer = v1783;
  int * v1727 = v1724->regs;
  int v1728 = v1727[12];
  int * v1729 = v1724->cache_keys;
  int v1730 = v1729[0];
  bool v1788 = v1730 == ((int)((unsigned int)(v1728 + 16) >> 2));
  int v1778;
  if (v1788) {
    int * v1731 = v1724->cache_vals;
    int v1732 = v1731[0];
    v1778 = v1732;
  } else {
    int * v1734 = v1724->cache_keys;
    int v1735 = v1734[1];
    bool v1793 = v1735 == ((int)((unsigned int)(v1728 + 16) >> 2));
    int v1776;
    if (v1793) {
      int * v1736 = v1724->cache_vals;
      int v1737 = v1736[1];
      int * v1738 = v1724->cache_keys;
      int * v1739 = v1724->cache_keys;
      int v1740 = v1739[0];
      v1738[1] = v1740;
      int * v1742 = v1724->cache_vals;
      int * v1743 = v1724->cache_vals;
      int v1744 = v1743[0];
      v1742[1] = v1744;
      int * v1746 = v1724->cache_keys;
      int v1802 = (int)((unsigned int)(v1728 + 16) >> 2);
      v1746[0] = v1802;
      int * v1748 = v1724->cache_vals;
      v1748[0] = v1737;
      int v1750 = v1724->timer;
      int v1805 = v1750 + 1;
      v1724->timer = v1805;
      v1776 = v1737;
    } else {
      int * v1753 = v1724->mem;
      int v1807 = (int)((unsigned int)(v1728 + 16) >> 2);
      int v1754 = v1753[v1807];
      int * v1755 = v1724->mem;
      int * v1756 = v1724->cache_keys;
      int v1757 = v1756[1];
      int * v1758 = v1724->cache_vals;
      int v1759 = v1758[1];
      v1755[v1757] = v1759;
      int * v1761 = v1724->cache_keys;
      int * v1762 = v1724->cache_keys;
      int v1763 = v1762[0];
      v1761[1] = v1763;
      int * v1765 = v1724->cache_vals;
      int * v1766 = v1724->cache_vals;
      int v1767 = v1766[0];
      v1765[1] = v1767;
      int * v1769 = v1724->cache_keys;
      v1769[0] = v1807;
      int * v1771 = v1724->cache_vals;
      v1771[0] = v1754;
      int v1773 = v1724->timer;
      int v1822 = v1773 + 100;
      v1724->timer = v1822;
      v1776 = v1754;
    }
    v1778 = v1776;
  }
  int * v1779 = v1724->regs;
  v1779[17] = v1778;
  struct StateT * v1781 = slot_20(v1724);
  return v1781;
}

struct StateT * slot_87(struct StateT * v6127) {
  int v6128 = v6127->timer;
  int v6138 = v6128 + 1;
  v6127->timer = v6138;
  int * v6130 = v6127->regs;
  int v6131 = v6130[26];
  int * v6132 = v6127->regs;
  int v6133 = v6132[15];
  int * v6134 = v6127->regs;
  int v6144 = v6131 ^ v6133;
  v6134[26] = v6144;
  struct StateT * v6136 = slot_88(v6127);
  return v6136;
}

struct StateT * slot_67(struct StateT * v4807) {
  int v4808 = v4807->timer;
  int v4818 = v4808 + 1;
  v4807->timer = v4818;
  int * v4810 = v4807->regs;
  int v4811 = v4810[12];
  int * v4812 = v4807->regs;
  int v4813 = v4812[15];
  int * v4814 = v4807->regs;
  int v4824 = v4811 ^ v4813;
  v4814[12] = v4824;
  struct StateT * v4816 = slot_68(v4807);
  return v4816;
}

struct StateT * slot_81(struct StateT * v5589) {
  int v5590 = v5589->timer;
  int v5598 = v5590 + 1;
  v5589->timer = v5598;
  int * v5592 = v5589->regs;
  int v5593 = v5592[9];
  int * v5594 = v5589->regs;
  int v5603 = (int)((unsigned int)v5593 >> 23);
  v5594[20] = v5603;
  struct StateT * v5596 = slot_82(v5589);
  return v5596;
}

struct StateT * slot_95(struct StateT * v7075) {
  int v7076 = v7075->timer;
  int v7084 = v7076 + 1;
  v7075->timer = v7084;
  int * v7078 = v7075->regs;
  int v7079 = v7078[15];
  int * v7080 = v7075->regs;
  int v7089 = (int)((unsigned int)v7079 >> 19);
  v7080[20] = v7089;
  struct StateT * v7082 = slot_96(v7075);
  return v7082;
}

struct StateT * slot_115(struct StateT * v9232) {
  int v9233 = v9232->timer;
  int v9241 = v9233 + 1;
  v9232->timer = v9241;
  int * v9235 = v9232->regs;
  int v9236 = v9235[15];
  int * v9237 = v9232->regs;
  int v9246 = (int)((unsigned int)v9236 >> 14);
  v9237[6] = v9246;
  struct StateT * v9239 = slot_116(v9232);
  return v9239;
}

struct StateT * slot_78(struct StateT * v5480) {
  int v5481 = v5480->timer;
  int v5489 = v5481 + 1;
  v5480->timer = v5489;
  int * v5483 = v5480->regs;
  int v5484 = v5483[8];
  int * v5485 = v5480->regs;
  int v5494 = (int)((unsigned int)v5484 >> 23);
  v5485[20] = v5494;
  struct StateT * v5487 = slot_79(v5480);
  return v5487;
}

struct StateT * slot_32(struct StateT * v2637) {
  int v2638 = v2637->timer;
  int v2646 = v2638 + 1;
  v2637->timer = v2646;
  int * v2640 = v2637->regs;
  int v2641 = v2640[14];
  int * v2642 = v2637->regs;
  int v2651 = v2641 + -718;
  v2642[19] = v2651;
  struct StateT * v2644 = slot_33(v2637);
  return v2644;
}

struct StateT * slot_205(struct StateT * v10917) {
  int v10918 = v10917->timer;
  int v10926 = v10918 + 1;
  v10917->timer = v10926;
  int * v10920 = v10917->regs;
  int v10921 = v10920[8];
  int * v10922 = v10917->regs;
  int v10930 = v10921 << 18;
  v10922[8] = v10930;
  struct StateT * v10924 = slot_206(v10917);
  return v10924;
}

struct StateT * slot_193(struct StateT * v10699) {
  int v10700 = v10699->timer;
  int v10710 = v10700 + 1;
  v10699->timer = v10710;
  int * v10702 = v10699->regs;
  int v10703 = v10702[13];
  int * v10704 = v10699->regs;
  int v10705 = v10704[26];
  int * v10706 = v10699->regs;
  int v10717 = v10703 + v10705;
  v10706[6] = v10717;
  struct StateT * v10708 = slot_194(v10699);
  return v10708;
}

struct StateT * slot_233(struct StateT * v5032) {
  int v5033 = v5032->timer;
  int v5091 = v5033 + 1;
  v5032->timer = v5091;
  int * v5035 = v5032->regs;
  int v5036 = v5035[2];
  int * v5037 = v5032->cache_keys;
  int v5038 = v5037[0];
  bool v5096 = v5038 == ((int)((unsigned int)(v5036 + 36) >> 2));
  int v5086;
  if (v5096) {
    int * v5039 = v5032->cache_vals;
    int v5040 = v5039[0];
    v5086 = v5040;
  } else {
    int * v5042 = v5032->cache_keys;
    int v5043 = v5042[1];
    bool v5101 = v5043 == ((int)((unsigned int)(v5036 + 36) >> 2));
    int v5084;
    if (v5101) {
      int * v5044 = v5032->cache_vals;
      int v5045 = v5044[1];
      int * v5046 = v5032->cache_keys;
      int * v5047 = v5032->cache_keys;
      int v5048 = v5047[0];
      v5046[1] = v5048;
      int * v5050 = v5032->cache_vals;
      int * v5051 = v5032->cache_vals;
      int v5052 = v5051[0];
      v5050[1] = v5052;
      int * v5054 = v5032->cache_keys;
      int v5110 = (int)((unsigned int)(v5036 + 36) >> 2);
      v5054[0] = v5110;
      int * v5056 = v5032->cache_vals;
      v5056[0] = v5045;
      int v5058 = v5032->timer;
      int v5113 = v5058 + 1;
      v5032->timer = v5113;
      v5084 = v5045;
    } else {
      int * v5061 = v5032->mem;
      int v5115 = (int)((unsigned int)(v5036 + 36) >> 2);
      int v5062 = v5061[v5115];
      int * v5063 = v5032->mem;
      int * v5064 = v5032->cache_keys;
      int v5065 = v5064[1];
      int * v5066 = v5032->cache_vals;
      int v5067 = v5066[1];
      v5063[v5065] = v5067;
      int * v5069 = v5032->cache_keys;
      int * v5070 = v5032->cache_keys;
      int v5071 = v5070[0];
      v5069[1] = v5071;
      int * v5073 = v5032->cache_vals;
      int * v5074 = v5032->cache_vals;
      int v5075 = v5074[0];
      v5073[1] = v5075;
      int * v5077 = v5032->cache_keys;
      v5077[0] = v5115;
      int * v5079 = v5032->cache_vals;
      v5079[0] = v5062;
      int v5081 = v5032->timer;
      int v5130 = v5081 + 100;
      v5032->timer = v5130;
      v5084 = v5062;
    }
    v5086 = v5084;
  }
  int * v5087 = v5032->regs;
  v5087[30] = v5086;
  struct StateT * v5089 = slot_234(v5032);
  return v5089;
}

struct StateT * slot_176(struct StateT * v10382) {
  int v10383 = v10382->timer;
  int v10391 = v10383 + 1;
  v10382->timer = v10391;
  int * v10385 = v10382->regs;
  int v10386 = v10385[11];
  int * v10387 = v10382->regs;
  int v10395 = v10386 << 13;
  v10387[11] = v10395;
  struct StateT * v10389 = slot_177(v10382);
  return v10389;
}

struct StateT * slot_189(struct StateT * v10617) {
  int v10618 = v10617->timer;
  int v10628 = v10618 + 1;
  v10617->timer = v10628;
  int * v10620 = v10617->regs;
  int v10621 = v10620[13];
  int * v10622 = v10617->regs;
  int v10623 = v10622[6];
  int * v10624 = v10617->regs;
  int v10634 = v10621 ^ v10623;
  v10624[13] = v10634;
  struct StateT * v10626 = slot_190(v10617);
  return v10626;
}

struct StateT * slot_33(struct StateT * v2654) {
  int v2655 = v2654->timer;
  int v2661 = v2655 + 1;
  v2654->timer = v2661;
  int * v2657 = v2654->regs;
  v2657[22] = 1797283840;
  struct StateT * v2659 = slot_34(v2654);
  return v2659;
}

struct StateT * slot_35(struct StateT * v2683) {
  int v2684 = v2683->timer;
  int v2690 = v2684 + 1;
  v2683->timer = v2690;
  int * v2686 = v2683->regs;
  v2686[31] = 9;
  struct StateT * v2688 = slot_36(v2683);
  return v2688;
}

struct StateT * slot_258(struct StateT * v7092) {
  int v7093 = v7092->timer;
  int v7147 = v7093 + 1;
  v7092->timer = v7147;
  int * v7095 = v7092->regs;
  int v7096 = v7095[10];
  int * v7097 = v7092->regs;
  int v7098 = v7097[16];
  int * v7099 = v7092->cache_keys;
  int v7100 = v7099[0];
  bool v7154 = v7100 == ((int)((unsigned int)(v7096 + 48) >> 2));
  int v7144;
  if (v7154) {
    int * v7101 = v7092->cache_vals;
    v7101[0] = v7098;
    v7144 = v7098;
  } else {
    int * v7104 = v7092->cache_keys;
    int v7105 = v7104[1];
    bool v7159 = v7105 == ((int)((unsigned int)(v7096 + 48) >> 2));
    int v7142;
    if (v7159) {
      int * v7106 = v7092->cache_keys;
      int * v7107 = v7092->cache_keys;
      int v7108 = v7107[0];
      v7106[1] = v7108;
      int * v7110 = v7092->cache_vals;
      int * v7111 = v7092->cache_vals;
      int v7112 = v7111[0];
      v7110[1] = v7112;
      int * v7114 = v7092->cache_keys;
      int v7167 = (int)((unsigned int)(v7096 + 48) >> 2);
      v7114[0] = v7167;
      int * v7116 = v7092->cache_vals;
      v7116[0] = v7098;
      int v7118 = v7092->timer;
      int v7170 = v7118 + 1;
      v7092->timer = v7170;
      v7142 = v7098;
    } else {
      int * v7121 = v7092->mem;
      int * v7122 = v7092->cache_keys;
      int v7123 = v7122[1];
      int * v7124 = v7092->cache_vals;
      int v7125 = v7124[1];
      v7121[v7123] = v7125;
      int * v7127 = v7092->cache_keys;
      int * v7128 = v7092->cache_keys;
      int v7129 = v7128[0];
      v7127[1] = v7129;
      int * v7131 = v7092->cache_vals;
      int * v7132 = v7092->cache_vals;
      int v7133 = v7132[0];
      v7131[1] = v7133;
      int * v7135 = v7092->cache_keys;
      int v7183 = (int)((unsigned int)(v7096 + 48) >> 2);
      v7135[0] = v7183;
      int * v7137 = v7092->cache_vals;
      v7137[0] = v7098;
      int v7139 = v7092->timer;
      int v7186 = v7139 + 100;
      v7092->timer = v7186;
      v7142 = v7098;
    }
    v7144 = v7142;
  }
  struct StateT * v7145 = slot_259(v7092);
  return v7145;
}

struct StateT * slot_246(struct StateT * v5682) {
  int v5683 = v5682->timer;
  int v5737 = v5683 + 1;
  v5682->timer = v5737;
  int * v5685 = v5682->regs;
  int v5686 = v5685[10];
  int * v5687 = v5682->regs;
  int v5688 = v5687[15];
  int * v5689 = v5682->cache_keys;
  int v5690 = v5689[0];
  bool v5744 = v5690 == ((int)((unsigned int)v5686 >> 2));
  int v5734;
  if (v5744) {
    int * v5691 = v5682->cache_vals;
    v5691[0] = v5688;
    v5734 = v5688;
  } else {
    int * v5694 = v5682->cache_keys;
    int v5695 = v5694[1];
    bool v5749 = v5695 == ((int)((unsigned int)v5686 >> 2));
    int v5732;
    if (v5749) {
      int * v5696 = v5682->cache_keys;
      int * v5697 = v5682->cache_keys;
      int v5698 = v5697[0];
      v5696[1] = v5698;
      int * v5700 = v5682->cache_vals;
      int * v5701 = v5682->cache_vals;
      int v5702 = v5701[0];
      v5700[1] = v5702;
      int * v5704 = v5682->cache_keys;
      int v5757 = (int)((unsigned int)v5686 >> 2);
      v5704[0] = v5757;
      int * v5706 = v5682->cache_vals;
      v5706[0] = v5688;
      int v5708 = v5682->timer;
      int v5760 = v5708 + 1;
      v5682->timer = v5760;
      v5732 = v5688;
    } else {
      int * v5711 = v5682->mem;
      int * v5712 = v5682->cache_keys;
      int v5713 = v5712[1];
      int * v5714 = v5682->cache_vals;
      int v5715 = v5714[1];
      v5711[v5713] = v5715;
      int * v5717 = v5682->cache_keys;
      int * v5718 = v5682->cache_keys;
      int v5719 = v5718[0];
      v5717[1] = v5719;
      int * v5721 = v5682->cache_vals;
      int * v5722 = v5682->cache_vals;
      int v5723 = v5722[0];
      v5721[1] = v5723;
      int * v5725 = v5682->cache_keys;
      int v5773 = (int)((unsigned int)v5686 >> 2);
      v5725[0] = v5773;
      int * v5727 = v5682->cache_vals;
      v5727[0] = v5688;
      int v5729 = v5682->timer;
      int v5776 = v5729 + 100;
      v5682->timer = v5776;
      v5732 = v5688;
    }
    v5734 = v5732;
  }
  struct StateT * v5735 = slot_247(v5682);
  return v5735;
}

struct StateT * slot_210(struct StateT * v11014) {
  int v11015 = v11014->timer;
  int v11025 = v11015 + 1;
  v11014->timer = v11025;
  int * v11017 = v11014->regs;
  int v11018 = v11017[22];
  int * v11019 = v11014->regs;
  int v11020 = v11019[8];
  int * v11021 = v11014->regs;
  int v11031 = v11018 ^ v11020;
  v11021[22] = v11031;
  struct StateT * v11023 = slot_211(v11014);
  return v11023;
}

struct StateT * slot_166(struct StateT * v10181) {
  int v10182 = v10181->timer;
  int v10192 = v10182 + 1;
  v10181->timer = v10192;
  int * v10184 = v10181->regs;
  int v10185 = v10184[8];
  int * v10186 = v10181->regs;
  int v10187 = v10186[9];
  int * v10188 = v10181->regs;
  int v10198 = v10185 | v10187;
  v10188[8] = v10198;
  struct StateT * v10190 = slot_167(v10181);
  return v10190;
}

struct StateT * slot_51(struct StateT * v3702) {
  int v3703 = v3702->timer;
  int v3713 = v3703 + 1;
  v3702->timer = v3713;
  int * v3705 = v3702->regs;
  int v3706 = v3705[21];
  int * v3707 = v3702->regs;
  int v3708 = v3707[16];
  int * v3709 = v3702->regs;
  int v3720 = v3706 + v3708;
  v3709[15] = v3720;
  struct StateT * v3711 = slot_52(v3702);
  return v3711;
}

struct StateT * slot_52(struct StateT * v3743) {
  int v3744 = v3743->timer;
  int v3754 = v3744 + 1;
  v3743->timer = v3754;
  int * v3746 = v3743->regs;
  int v3747 = v3746[11];
  int * v3748 = v3743->regs;
  int v3749 = v3748[23];
  int * v3750 = v3743->regs;
  int v3761 = v3747 + v3749;
  v3750[20] = v3761;
  struct StateT * v3752 = slot_53(v3743);
  return v3752;
}

struct StateT * slot_83(struct StateT * v5662) {
  int v5663 = v5662->timer;
  int v5673 = v5663 + 1;
  v5662->timer = v5673;
  int * v5665 = v5662->regs;
  int v5666 = v5665[9];
  int * v5667 = v5662->regs;
  int v5668 = v5667[20];
  int * v5669 = v5662->regs;
  int v5679 = v5666 | v5668;
  v5669[9] = v5679;
  struct StateT * v5671 = slot_84(v5662);
  return v5671;
}

struct StateT * slot_25(struct StateT * v2354) {
  int v2355 = v2354->timer;
  int v2413 = v2355 + 1;
  v2354->timer = v2413;
  int * v2357 = v2354->regs;
  int v2358 = v2357[11];
  int * v2359 = v2354->cache_keys;
  int v2360 = v2359[0];
  bool v2418 = v2360 == ((int)((unsigned int)(v2358 + 8) >> 2));
  int v2408;
  if (v2418) {
    int * v2361 = v2354->cache_vals;
    int v2362 = v2361[0];
    v2408 = v2362;
  } else {
    int * v2364 = v2354->cache_keys;
    int v2365 = v2364[1];
    bool v2423 = v2365 == ((int)((unsigned int)(v2358 + 8) >> 2));
    int v2406;
    if (v2423) {
      int * v2366 = v2354->cache_vals;
      int v2367 = v2366[1];
      int * v2368 = v2354->cache_keys;
      int * v2369 = v2354->cache_keys;
      int v2370 = v2369[0];
      v2368[1] = v2370;
      int * v2372 = v2354->cache_vals;
      int * v2373 = v2354->cache_vals;
      int v2374 = v2373[0];
      v2372[1] = v2374;
      int * v2376 = v2354->cache_keys;
      int v2432 = (int)((unsigned int)(v2358 + 8) >> 2);
      v2376[0] = v2432;
      int * v2378 = v2354->cache_vals;
      v2378[0] = v2367;
      int v2380 = v2354->timer;
      int v2435 = v2380 + 1;
      v2354->timer = v2435;
      v2406 = v2367;
    } else {
      int * v2383 = v2354->mem;
      int v2437 = (int)((unsigned int)(v2358 + 8) >> 2);
      int v2384 = v2383[v2437];
      int * v2385 = v2354->mem;
      int * v2386 = v2354->cache_keys;
      int v2387 = v2386[1];
      int * v2388 = v2354->cache_vals;
      int v2389 = v2388[1];
      v2385[v2387] = v2389;
      int * v2391 = v2354->cache_keys;
      int * v2392 = v2354->cache_keys;
      int v2393 = v2392[0];
      v2391[1] = v2393;
      int * v2395 = v2354->cache_vals;
      int * v2396 = v2354->cache_vals;
      int v2397 = v2396[0];
      v2395[1] = v2397;
      int * v2399 = v2354->cache_keys;
      v2399[0] = v2437;
      int * v2401 = v2354->cache_vals;
      v2401[0] = v2384;
      int v2403 = v2354->timer;
      int v2452 = v2403 + 100;
      v2354->timer = v2452;
      v2406 = v2384;
    }
    v2408 = v2406;
  }
  int * v2409 = v2354->regs;
  v2409[26] = v2408;
  struct StateT * v2411 = slot_26(v2354);
  return v2411;
}

struct StateT * slot_209(struct StateT * v10994) {
  int v10995 = v10994->timer;
  int v11005 = v10995 + 1;
  v10994->timer = v11005;
  int * v10997 = v10994->regs;
  int v10998 = v10997[19];
  int * v10999 = v10994->regs;
  int v11000 = v10999[6];
  int * v11001 = v10994->regs;
  int v11011 = v10998 ^ v11000;
  v11001[19] = v11011;
  struct StateT * v11003 = slot_210(v10994);
  return v11003;
}

struct StateT * slot_3(struct StateT * v213) {
  int v214 = v213->timer;
  int v268 = v214 + 1;
  v213->timer = v268;
  int * v216 = v213->regs;
  int v217 = v216[2];
  int * v218 = v213->regs;
  int v219 = v218[9];
  int * v220 = v213->cache_keys;
  int v221 = v220[0];
  bool v275 = v221 == ((int)((unsigned int)(v217 + 84) >> 2));
  int v265;
  if (v275) {
    int * v222 = v213->cache_vals;
    v222[0] = v219;
    v265 = v219;
  } else {
    int * v225 = v213->cache_keys;
    int v226 = v225[1];
    bool v280 = v226 == ((int)((unsigned int)(v217 + 84) >> 2));
    int v263;
    if (v280) {
      int * v227 = v213->cache_keys;
      int * v228 = v213->cache_keys;
      int v229 = v228[0];
      v227[1] = v229;
      int * v231 = v213->cache_vals;
      int * v232 = v213->cache_vals;
      int v233 = v232[0];
      v231[1] = v233;
      int * v235 = v213->cache_keys;
      int v288 = (int)((unsigned int)(v217 + 84) >> 2);
      v235[0] = v288;
      int * v237 = v213->cache_vals;
      v237[0] = v219;
      int v239 = v213->timer;
      int v291 = v239 + 1;
      v213->timer = v291;
      v263 = v219;
    } else {
      int * v242 = v213->mem;
      int * v243 = v213->cache_keys;
      int v244 = v243[1];
      int * v245 = v213->cache_vals;
      int v246 = v245[1];
      v242[v244] = v246;
      int * v248 = v213->cache_keys;
      int * v249 = v213->cache_keys;
      int v250 = v249[0];
      v248[1] = v250;
      int * v252 = v213->cache_vals;
      int * v253 = v213->cache_vals;
      int v254 = v253[0];
      v252[1] = v254;
      int * v256 = v213->cache_keys;
      int v304 = (int)((unsigned int)(v217 + 84) >> 2);
      v256[0] = v304;
      int * v258 = v213->cache_vals;
      v258[0] = v219;
      int v260 = v213->timer;
      int v307 = v260 + 100;
      v213->timer = v307;
      v263 = v219;
    }
    v265 = v263;
  }
  struct StateT * v266 = slot_4(v213);
  return v266;
}

struct StateT * slot_264(struct StateT * v7799) {
  int v7800 = v7799->timer;
  int v7858 = v7800 + 1;
  v7799->timer = v7858;
  int * v7802 = v7799->regs;
  int v7803 = v7802[2];
  int * v7804 = v7799->cache_keys;
  int v7805 = v7804[0];
  bool v7863 = v7805 == ((int)((unsigned int)(v7803 + 84) >> 2));
  int v7853;
  if (v7863) {
    int * v7806 = v7799->cache_vals;
    int v7807 = v7806[0];
    v7853 = v7807;
  } else {
    int * v7809 = v7799->cache_keys;
    int v7810 = v7809[1];
    bool v7868 = v7810 == ((int)((unsigned int)(v7803 + 84) >> 2));
    int v7851;
    if (v7868) {
      int * v7811 = v7799->cache_vals;
      int v7812 = v7811[1];
      int * v7813 = v7799->cache_keys;
      int * v7814 = v7799->cache_keys;
      int v7815 = v7814[0];
      v7813[1] = v7815;
      int * v7817 = v7799->cache_vals;
      int * v7818 = v7799->cache_vals;
      int v7819 = v7818[0];
      v7817[1] = v7819;
      int * v7821 = v7799->cache_keys;
      int v7877 = (int)((unsigned int)(v7803 + 84) >> 2);
      v7821[0] = v7877;
      int * v7823 = v7799->cache_vals;
      v7823[0] = v7812;
      int v7825 = v7799->timer;
      int v7880 = v7825 + 1;
      v7799->timer = v7880;
      v7851 = v7812;
    } else {
      int * v7828 = v7799->mem;
      int v7882 = (int)((unsigned int)(v7803 + 84) >> 2);
      int v7829 = v7828[v7882];
      int * v7830 = v7799->mem;
      int * v7831 = v7799->cache_keys;
      int v7832 = v7831[1];
      int * v7833 = v7799->cache_vals;
      int v7834 = v7833[1];
      v7830[v7832] = v7834;
      int * v7836 = v7799->cache_keys;
      int * v7837 = v7799->cache_keys;
      int v7838 = v7837[0];
      v7836[1] = v7838;
      int * v7840 = v7799->cache_vals;
      int * v7841 = v7799->cache_vals;
      int v7842 = v7841[0];
      v7840[1] = v7842;
      int * v7844 = v7799->cache_keys;
      v7844[0] = v7882;
      int * v7846 = v7799->cache_vals;
      v7846[0] = v7829;
      int v7848 = v7799->timer;
      int v7897 = v7848 + 100;
      v7799->timer = v7897;
      v7851 = v7829;
    }
    v7853 = v7851;
  }
  int * v7854 = v7799->regs;
  v7854[9] = v7853;
  struct StateT * v7856 = slot_265(v7799);
  return v7856;
}

struct StateT * slot_123(struct StateT * v9371) {
  int v9372 = v9371->timer;
  int v9382 = v9372 + 1;
  v9371->timer = v9382;
  int * v9374 = v9371->regs;
  int v9375 = v9374[17];
  int * v9376 = v9371->regs;
  int v9377 = v9376[6];
  int * v9378 = v9371->regs;
  int v9388 = v9375 | v9377;
  v9378[17] = v9388;
  struct StateT * v9380 = slot_124(v9371);
  return v9380;
}

struct StateT * slot_73(struct StateT * v5304) {
  int v5305 = v5304->timer;
  int v5315 = v5305 + 1;
  v5304->timer = v5315;
  int * v5307 = v5304->regs;
  int v5308 = v5307[1];
  int * v5309 = v5304->regs;
  int v5310 = v5309[19];
  int * v5311 = v5304->regs;
  int v5322 = v5308 + v5310;
  v5311[9] = v5322;
  struct StateT * v5313 = slot_74(v5304);
  return v5313;
}

struct StateT * slot_270(struct StateT * v8540) {
  int v8541 = v8540->timer;
  int v8599 = v8541 + 1;
  v8540->timer = v8599;
  int * v8543 = v8540->regs;
  int v8544 = v8543[2];
  int * v8545 = v8540->cache_keys;
  int v8546 = v8545[0];
  bool v8604 = v8546 == ((int)((unsigned int)(v8544 + 60) >> 2));
  int v8594;
  if (v8604) {
    int * v8547 = v8540->cache_vals;
    int v8548 = v8547[0];
    v8594 = v8548;
  } else {
    int * v8550 = v8540->cache_keys;
    int v8551 = v8550[1];
    bool v8609 = v8551 == ((int)((unsigned int)(v8544 + 60) >> 2));
    int v8592;
    if (v8609) {
      int * v8552 = v8540->cache_vals;
      int v8553 = v8552[1];
      int * v8554 = v8540->cache_keys;
      int * v8555 = v8540->cache_keys;
      int v8556 = v8555[0];
      v8554[1] = v8556;
      int * v8558 = v8540->cache_vals;
      int * v8559 = v8540->cache_vals;
      int v8560 = v8559[0];
      v8558[1] = v8560;
      int * v8562 = v8540->cache_keys;
      int v8618 = (int)((unsigned int)(v8544 + 60) >> 2);
      v8562[0] = v8618;
      int * v8564 = v8540->cache_vals;
      v8564[0] = v8553;
      int v8566 = v8540->timer;
      int v8621 = v8566 + 1;
      v8540->timer = v8621;
      v8592 = v8553;
    } else {
      int * v8569 = v8540->mem;
      int v8623 = (int)((unsigned int)(v8544 + 60) >> 2);
      int v8570 = v8569[v8623];
      int * v8571 = v8540->mem;
      int * v8572 = v8540->cache_keys;
      int v8573 = v8572[1];
      int * v8574 = v8540->cache_vals;
      int v8575 = v8574[1];
      v8571[v8573] = v8575;
      int * v8577 = v8540->cache_keys;
      int * v8578 = v8540->cache_keys;
      int v8579 = v8578[0];
      v8577[1] = v8579;
      int * v8581 = v8540->cache_vals;
      int * v8582 = v8540->cache_vals;
      int v8583 = v8582[0];
      v8581[1] = v8583;
      int * v8585 = v8540->cache_keys;
      v8585[0] = v8623;
      int * v8587 = v8540->cache_vals;
      v8587[0] = v8570;
      int v8589 = v8540->timer;
      int v8638 = v8589 + 100;
      v8540->timer = v8638;
      v8592 = v8570;
    }
    v8594 = v8592;
  }
  int * v8595 = v8540->regs;
  v8595[23] = v8594;
  struct StateT * v8597 = slot_271(v8540);
  return v8597;
}

struct StateT * slot_198(struct StateT * v10794) {
  int v10795 = v10794->timer;
  int v10803 = v10795 + 1;
  v10794->timer = v10803;
  int * v10797 = v10794->regs;
  int v10798 = v10797[15];
  int * v10799 = v10794->regs;
  int v10808 = (int)((unsigned int)v10798 >> 14);
  v10799[9] = v10808;
  struct StateT * v10801 = slot_199(v10794);
  return v10801;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v73 = v19 + 1;
  v18->timer = v73;
  int * v21 = v18->regs;
  int v22 = v21[2];
  int * v23 = v18->regs;
  int v24 = v23[1];
  int * v25 = v18->cache_keys;
  int v26 = v25[0];
  bool v80 = v26 == ((int)((unsigned int)(v22 + 92) >> 2));
  int v70;
  if (v80) {
    int * v27 = v18->cache_vals;
    v27[0] = v24;
    v70 = v24;
  } else {
    int * v30 = v18->cache_keys;
    int v31 = v30[1];
    bool v84 = v31 == ((int)((unsigned int)(v22 + 92) >> 2));
    int v68;
    if (v84) {
      int * v32 = v18->cache_keys;
      int * v33 = v18->cache_keys;
      int v34 = v33[0];
      v32[1] = v34;
      int * v36 = v18->cache_vals;
      int * v37 = v18->cache_vals;
      int v38 = v37[0];
      v36[1] = v38;
      int * v40 = v18->cache_keys;
      int v92 = (int)((unsigned int)(v22 + 92) >> 2);
      v40[0] = v92;
      int * v42 = v18->cache_vals;
      v42[0] = v24;
      int v44 = v18->timer;
      int v95 = v44 + 1;
      v18->timer = v95;
      v68 = v24;
    } else {
      int * v47 = v18->mem;
      int * v48 = v18->cache_keys;
      int v49 = v48[1];
      int * v50 = v18->cache_vals;
      int v51 = v50[1];
      v47[v49] = v51;
      int * v53 = v18->cache_keys;
      int * v54 = v18->cache_keys;
      int v55 = v54[0];
      v53[1] = v55;
      int * v57 = v18->cache_vals;
      int * v58 = v18->cache_vals;
      int v59 = v58[0];
      v57[1] = v59;
      int * v61 = v18->cache_keys;
      int v108 = (int)((unsigned int)(v22 + 92) >> 2);
      v61[0] = v108;
      int * v63 = v18->cache_vals;
      v63[0] = v24;
      int v65 = v18->timer;
      int v111 = v65 + 100;
      v18->timer = v111;
      v68 = v24;
    }
    v70 = v68;
  }
  struct StateT * v71 = slot_2(v18);
  return v71;
}

struct StateT * slot_187(struct StateT * v10577) {
  int v10578 = v10577->timer;
  int v10588 = v10578 + 1;
  v10577->timer = v10588;
  int * v10580 = v10577->regs;
  int v10581 = v10580[14];
  int * v10582 = v10577->regs;
  int v10583 = v10582[11];
  int * v10584 = v10577->regs;
  int v10594 = v10581 ^ v10583;
  v10584[14] = v10594;
  struct StateT * v10586 = slot_188(v10577);
  return v10586;
}

struct StateT * slot_97(struct StateT * v7304) {
  int v7305 = v7304->timer;
  int v7315 = v7305 + 1;
  v7304->timer = v7315;
  int * v7307 = v7304->regs;
  int v7308 = v7307[15];
  int * v7309 = v7304->regs;
  int v7310 = v7309[20];
  int * v7311 = v7304->regs;
  int v7321 = v7308 | v7310;
  v7311[15] = v7321;
  struct StateT * v7313 = slot_98(v7304);
  return v7313;
}

struct StateT * slot_182(struct StateT * v10488) {
  int v10489 = v10488->timer;
  int v10497 = v10489 + 1;
  v10488->timer = v10497;
  int * v10491 = v10488->regs;
  int v10492 = v10491[6];
  int * v10493 = v10488->regs;
  int v10501 = v10492 << 13;
  v10493[6] = v10501;
  struct StateT * v10495 = slot_183(v10488);
  return v10495;
}

struct StateT * slot_38(struct StateT * v2892) {
  int v2893 = v2892->timer;
  int v2947 = v2893 + 1;
  v2892->timer = v2947;
  int * v2895 = v2892->regs;
  int v2896 = v2895[2];
  int * v2897 = v2892->regs;
  int v2898 = v2897[5];
  int * v2899 = v2892->cache_keys;
  int v2900 = v2899[0];
  bool v2954 = v2900 == ((int)((unsigned int)(v2896 + 12) >> 2));
  int v2944;
  if (v2954) {
    int * v2901 = v2892->cache_vals;
    v2901[0] = v2898;
    v2944 = v2898;
  } else {
    int * v2904 = v2892->cache_keys;
    int v2905 = v2904[1];
    bool v2959 = v2905 == ((int)((unsigned int)(v2896 + 12) >> 2));
    int v2942;
    if (v2959) {
      int * v2906 = v2892->cache_keys;
      int * v2907 = v2892->cache_keys;
      int v2908 = v2907[0];
      v2906[1] = v2908;
      int * v2910 = v2892->cache_vals;
      int * v2911 = v2892->cache_vals;
      int v2912 = v2911[0];
      v2910[1] = v2912;
      int * v2914 = v2892->cache_keys;
      int v2967 = (int)((unsigned int)(v2896 + 12) >> 2);
      v2914[0] = v2967;
      int * v2916 = v2892->cache_vals;
      v2916[0] = v2898;
      int v2918 = v2892->timer;
      int v2970 = v2918 + 1;
      v2892->timer = v2970;
      v2942 = v2898;
    } else {
      int * v2921 = v2892->mem;
      int * v2922 = v2892->cache_keys;
      int v2923 = v2922[1];
      int * v2924 = v2892->cache_vals;
      int v2925 = v2924[1];
      v2921[v2923] = v2925;
      int * v2927 = v2892->cache_keys;
      int * v2928 = v2892->cache_keys;
      int v2929 = v2928[0];
      v2927[1] = v2929;
      int * v2931 = v2892->cache_vals;
      int * v2932 = v2892->cache_vals;
      int v2933 = v2932[0];
      v2931[1] = v2933;
      int * v2935 = v2892->cache_keys;
      int v2983 = (int)((unsigned int)(v2896 + 12) >> 2);
      v2935[0] = v2983;
      int * v2937 = v2892->cache_vals;
      v2937[0] = v2898;
      int v2939 = v2892->timer;
      int v2986 = v2939 + 100;
      v2892->timer = v2986;
      v2942 = v2898;
    }
    v2944 = v2942;
  }
  struct StateT * v2945 = slot_39(v2892);
  return v2945;
}

struct StateT * slot_178(struct StateT * v10418) {
  int v10419 = v10418->timer;
  int v10427 = v10419 + 1;
  v10418->timer = v10427;
  int * v10421 = v10418->regs;
  int v10422 = v10421[15];
  int * v10423 = v10418->regs;
  int v10432 = (int)((unsigned int)v10422 >> 19);
  v10423[9] = v10432;
  struct StateT * v10425 = slot_179(v10418);
  return v10425;
}

struct StateT * slot_106(struct StateT * v8393) {
  int v8394 = v8393->timer;
  int v8404 = v8394 + 1;
  v8393->timer = v8404;
  int * v8396 = v8393->regs;
  int v8397 = v8396[18];
  int * v8398 = v8393->regs;
  int v8399 = v8398[9];
  int * v8400 = v8393->regs;
  int v8411 = v8397 | v8399;
  v8400[6] = v8411;
  struct StateT * v8402 = slot_107(v8393);
  return v8402;
}

struct StateT * slot_98(struct StateT * v7421) {
  int v7422 = v7421->timer;
  int v7430 = v7422 + 1;
  v7421->timer = v7430;
  int * v7424 = v7421->regs;
  int v7425 = v7424[8];
  int * v7426 = v7421->regs;
  int v7435 = (int)((unsigned int)v7425 >> 19);
  v7426[20] = v7435;
  struct StateT * v7428 = slot_99(v7421);
  return v7428;
}

struct StateT * slot_159(struct StateT * v10059) {
  int v10060 = v10059->timer;
  int v10068 = v10060 + 1;
  v10059->timer = v10068;
  int * v10062 = v10059->regs;
  int v10063 = v10062[15];
  int * v10064 = v10059->regs;
  int v10072 = v10063 << 9;
  v10064[15] = v10072;
  struct StateT * v10066 = slot_160(v10059);
  return v10066;
}

struct StateT * slot_46(struct StateT * v3513) {
  int v3514 = v3513->timer;
  int v3522 = v3514 + 1;
  v3513->timer = v3522;
  int * v3516 = v3513->regs;
  int v3517 = v3516[28];
  int * v3518 = v3513->regs;
  v3518[27] = v3517;
  struct StateT * v3520 = slot_47(v3513);
  return v3520;
}

struct StateT * slot_212(struct StateT * v11050) {
  int v11051 = v11050->timer;
  int v11063 = v11051 + 1;
  v11050->timer = v11063;
  int * v11053 = v11050->regs;
  int v11054 = v11053[31];
  int * v11055 = v11050->regs;
  int v11056 = v11055[30];
  bool v11068 = (v11054 ^ -2147483648) >= (v11056 ^ -2147483648);
  struct StateT * v11061;
  if (v11068) {
    struct StateT * v11057 = slot_51(v11050);
    v11061 = v11057;
  } else {
    struct StateT * v11059 = slot_213(v11050);
    v11061 = v11059;
  }
  return v11061;
}

struct StateT * slot_132(struct StateT * v9546) {
  int v9547 = v9546->timer;
  int v9557 = v9547 + 1;
  v9546->timer = v9557;
  int * v9549 = v9546->regs;
  int v9550 = v9549[20];
  int * v9551 = v9546->regs;
  int v9552 = v9551[12];
  int * v9553 = v9546->regs;
  int v9564 = v9550 + v9552;
  v9553[11] = v9564;
  struct StateT * v9555 = slot_133(v9546);
  return v9555;
}

struct StateT * slot_130(struct StateT * v9505) {
  int v9506 = v9505->timer;
  int v9516 = v9506 + 1;
  v9505->timer = v9516;
  int * v9508 = v9505->regs;
  int v9509 = v9508[22];
  int * v9510 = v9505->regs;
  int v9511 = v9510[5];
  int * v9512 = v9505->regs;
  int v9522 = v9509 ^ v9511;
  v9512[22] = v9522;
  struct StateT * v9514 = slot_131(v9505);
  return v9514;
}

struct StateT * slot_211(struct StateT * v11034) {
  int v11035 = v11034->timer;
  int v11043 = v11035 + 1;
  v11034->timer = v11043;
  int * v11037 = v11034->regs;
  int v11038 = v11037[30];
  int * v11039 = v11034->regs;
  int v11047 = v11038 + 1;
  v11039[30] = v11047;
  struct StateT * v11041 = slot_212(v11034);
  return v11041;
}

struct StateT * slot_20(struct StateT * v1829) {
  int v1830 = v1829->timer;
  int v1888 = v1830 + 1;
  v1829->timer = v1888;
  int * v1832 = v1829->regs;
  int v1833 = v1832[12];
  int * v1834 = v1829->cache_keys;
  int v1835 = v1834[0];
  bool v1893 = v1835 == ((int)((unsigned int)(v1833 + 20) >> 2));
  int v1883;
  if (v1893) {
    int * v1836 = v1829->cache_vals;
    int v1837 = v1836[0];
    v1883 = v1837;
  } else {
    int * v1839 = v1829->cache_keys;
    int v1840 = v1839[1];
    bool v1898 = v1840 == ((int)((unsigned int)(v1833 + 20) >> 2));
    int v1881;
    if (v1898) {
      int * v1841 = v1829->cache_vals;
      int v1842 = v1841[1];
      int * v1843 = v1829->cache_keys;
      int * v1844 = v1829->cache_keys;
      int v1845 = v1844[0];
      v1843[1] = v1845;
      int * v1847 = v1829->cache_vals;
      int * v1848 = v1829->cache_vals;
      int v1849 = v1848[0];
      v1847[1] = v1849;
      int * v1851 = v1829->cache_keys;
      int v1907 = (int)((unsigned int)(v1833 + 20) >> 2);
      v1851[0] = v1907;
      int * v1853 = v1829->cache_vals;
      v1853[0] = v1842;
      int v1855 = v1829->timer;
      int v1910 = v1855 + 1;
      v1829->timer = v1910;
      v1881 = v1842;
    } else {
      int * v1858 = v1829->mem;
      int v1912 = (int)((unsigned int)(v1833 + 20) >> 2);
      int v1859 = v1858[v1912];
      int * v1860 = v1829->mem;
      int * v1861 = v1829->cache_keys;
      int v1862 = v1861[1];
      int * v1863 = v1829->cache_vals;
      int v1864 = v1863[1];
      v1860[v1862] = v1864;
      int * v1866 = v1829->cache_keys;
      int * v1867 = v1829->cache_keys;
      int v1868 = v1867[0];
      v1866[1] = v1868;
      int * v1870 = v1829->cache_vals;
      int * v1871 = v1829->cache_vals;
      int v1872 = v1871[0];
      v1870[1] = v1872;
      int * v1874 = v1829->cache_keys;
      v1874[0] = v1912;
      int * v1876 = v1829->cache_vals;
      v1876[0] = v1859;
      int v1878 = v1829->timer;
      int v1927 = v1878 + 100;
      v1829->timer = v1927;
      v1881 = v1859;
    }
    v1883 = v1881;
  }
  int * v1884 = v1829->regs;
  v1884[16] = v1883;
  struct StateT * v1886 = slot_21(v1829);
  return v1886;
}

struct StateT * slot_141(struct StateT * v9715) {
  int v9716 = v9715->timer;
  int v9724 = v9716 + 1;
  v9715->timer = v9724;
  int * v9718 = v9715->regs;
  int v9719 = v9718[16];
  int * v9720 = v9715->regs;
  int v9729 = (int)((unsigned int)v9719 >> 25);
  v9720[5] = v9729;
  struct StateT * v9722 = slot_142(v9715);
  return v9722;
}

struct StateT * slot_61(struct StateT * v4333) {
  int v4334 = v4333->timer;
  int v4342 = v4334 + 1;
  v4333->timer = v4342;
  int * v4336 = v4333->regs;
  int v4337 = v4336[18];
  int * v4338 = v4333->regs;
  int v4347 = (int)((unsigned int)v4337 >> 25);
  v4338[20] = v4347;
  struct StateT * v4340 = slot_62(v4333);
  return v4340;
}

struct StateT * slot_30(struct StateT * v2603) {
  int v2604 = v2603->timer;
  int v2612 = v2604 + 1;
  v2603->timer = v2612;
  int * v2606 = v2603->regs;
  int v2607 = v2606[12];
  int * v2608 = v2603->regs;
  int v2617 = v2607 + -1947;
  v2608[21] = v2617;
  struct StateT * v2610 = slot_31(v2603);
  return v2610;
}

struct StateT * slot_4(struct StateT * v311) {
  int v312 = v311->timer;
  int v366 = v312 + 1;
  v311->timer = v366;
  int * v314 = v311->regs;
  int v315 = v314[2];
  int * v316 = v311->regs;
  int v317 = v316[18];
  int * v318 = v311->cache_keys;
  int v319 = v318[0];
  bool v373 = v319 == ((int)((unsigned int)(v315 + 80) >> 2));
  int v363;
  if (v373) {
    int * v320 = v311->cache_vals;
    v320[0] = v317;
    v363 = v317;
  } else {
    int * v323 = v311->cache_keys;
    int v324 = v323[1];
    bool v378 = v324 == ((int)((unsigned int)(v315 + 80) >> 2));
    int v361;
    if (v378) {
      int * v325 = v311->cache_keys;
      int * v326 = v311->cache_keys;
      int v327 = v326[0];
      v325[1] = v327;
      int * v329 = v311->cache_vals;
      int * v330 = v311->cache_vals;
      int v331 = v330[0];
      v329[1] = v331;
      int * v333 = v311->cache_keys;
      int v386 = (int)((unsigned int)(v315 + 80) >> 2);
      v333[0] = v386;
      int * v335 = v311->cache_vals;
      v335[0] = v317;
      int v337 = v311->timer;
      int v389 = v337 + 1;
      v311->timer = v389;
      v361 = v317;
    } else {
      int * v340 = v311->mem;
      int * v341 = v311->cache_keys;
      int v342 = v341[1];
      int * v343 = v311->cache_vals;
      int v344 = v343[1];
      v340[v342] = v344;
      int * v346 = v311->cache_keys;
      int * v347 = v311->cache_keys;
      int v348 = v347[0];
      v346[1] = v348;
      int * v350 = v311->cache_vals;
      int * v351 = v311->cache_vals;
      int v352 = v351[0];
      v350[1] = v352;
      int * v354 = v311->cache_keys;
      int v402 = (int)((unsigned int)(v315 + 80) >> 2);
      v354[0] = v402;
      int * v356 = v311->cache_vals;
      v356[0] = v317;
      int v358 = v311->timer;
      int v405 = v358 + 100;
      v311->timer = v405;
      v361 = v317;
    }
    v363 = v361;
  }
  struct StateT * v364 = slot_5(v311);
  return v364;
}

struct StateT * slot_18(struct StateT * v1619) {
  int v1620 = v1619->timer;
  int v1678 = v1620 + 1;
  v1619->timer = v1678;
  int * v1622 = v1619->regs;
  int v1623 = v1622[12];
  int * v1624 = v1619->cache_keys;
  int v1625 = v1624[0];
  bool v1683 = v1625 == ((int)((unsigned int)(v1623 + 12) >> 2));
  int v1673;
  if (v1683) {
    int * v1626 = v1619->cache_vals;
    int v1627 = v1626[0];
    v1673 = v1627;
  } else {
    int * v1629 = v1619->cache_keys;
    int v1630 = v1629[1];
    bool v1688 = v1630 == ((int)((unsigned int)(v1623 + 12) >> 2));
    int v1671;
    if (v1688) {
      int * v1631 = v1619->cache_vals;
      int v1632 = v1631[1];
      int * v1633 = v1619->cache_keys;
      int * v1634 = v1619->cache_keys;
      int v1635 = v1634[0];
      v1633[1] = v1635;
      int * v1637 = v1619->cache_vals;
      int * v1638 = v1619->cache_vals;
      int v1639 = v1638[0];
      v1637[1] = v1639;
      int * v1641 = v1619->cache_keys;
      int v1697 = (int)((unsigned int)(v1623 + 12) >> 2);
      v1641[0] = v1697;
      int * v1643 = v1619->cache_vals;
      v1643[0] = v1632;
      int v1645 = v1619->timer;
      int v1700 = v1645 + 1;
      v1619->timer = v1700;
      v1671 = v1632;
    } else {
      int * v1648 = v1619->mem;
      int v1702 = (int)((unsigned int)(v1623 + 12) >> 2);
      int v1649 = v1648[v1702];
      int * v1650 = v1619->mem;
      int * v1651 = v1619->cache_keys;
      int v1652 = v1651[1];
      int * v1653 = v1619->cache_vals;
      int v1654 = v1653[1];
      v1650[v1652] = v1654;
      int * v1656 = v1619->cache_keys;
      int * v1657 = v1619->cache_keys;
      int v1658 = v1657[0];
      v1656[1] = v1658;
      int * v1660 = v1619->cache_vals;
      int * v1661 = v1619->cache_vals;
      int v1662 = v1661[0];
      v1660[1] = v1662;
      int * v1664 = v1619->cache_keys;
      v1664[0] = v1702;
      int * v1666 = v1619->cache_vals;
      v1666[0] = v1649;
      int v1668 = v1619->timer;
      int v1717 = v1668 + 100;
      v1619->timer = v1717;
      v1671 = v1649;
    }
    v1673 = v1671;
  }
  int * v1674 = v1619->regs;
  v1674[6] = v1673;
  struct StateT * v1676 = slot_19(v1619);
  return v1676;
}

struct StateT * slot_9(struct StateT * v801) {
  int v802 = v801->timer;
  int v856 = v802 + 1;
  v801->timer = v856;
  int * v804 = v801->regs;
  int v805 = v804[2];
  int * v806 = v801->regs;
  int v807 = v806[23];
  int * v808 = v801->cache_keys;
  int v809 = v808[0];
  bool v863 = v809 == ((int)((unsigned int)(v805 + 60) >> 2));
  int v853;
  if (v863) {
    int * v810 = v801->cache_vals;
    v810[0] = v807;
    v853 = v807;
  } else {
    int * v813 = v801->cache_keys;
    int v814 = v813[1];
    bool v868 = v814 == ((int)((unsigned int)(v805 + 60) >> 2));
    int v851;
    if (v868) {
      int * v815 = v801->cache_keys;
      int * v816 = v801->cache_keys;
      int v817 = v816[0];
      v815[1] = v817;
      int * v819 = v801->cache_vals;
      int * v820 = v801->cache_vals;
      int v821 = v820[0];
      v819[1] = v821;
      int * v823 = v801->cache_keys;
      int v876 = (int)((unsigned int)(v805 + 60) >> 2);
      v823[0] = v876;
      int * v825 = v801->cache_vals;
      v825[0] = v807;
      int v827 = v801->timer;
      int v879 = v827 + 1;
      v801->timer = v879;
      v851 = v807;
    } else {
      int * v830 = v801->mem;
      int * v831 = v801->cache_keys;
      int v832 = v831[1];
      int * v833 = v801->cache_vals;
      int v834 = v833[1];
      v830[v832] = v834;
      int * v836 = v801->cache_keys;
      int * v837 = v801->cache_keys;
      int v838 = v837[0];
      v836[1] = v838;
      int * v840 = v801->cache_vals;
      int * v841 = v801->cache_vals;
      int v842 = v841[0];
      v840[1] = v842;
      int * v844 = v801->cache_keys;
      int v892 = (int)((unsigned int)(v805 + 60) >> 2);
      v844[0] = v892;
      int * v846 = v801->cache_vals;
      v846[0] = v807;
      int v848 = v801->timer;
      int v895 = v848 + 100;
      v801->timer = v895;
      v851 = v807;
    }
    v853 = v851;
  }
  struct StateT * v854 = slot_10(v801);
  return v854;
}

struct StateT * slot_183(struct StateT * v10504) {
  int v10505 = v10504->timer;
  int v10515 = v10505 + 1;
  v10504->timer = v10515;
  int * v10507 = v10504->regs;
  int v10508 = v10507[6];
  int * v10509 = v10504->regs;
  int v10510 = v10509[9];
  int * v10511 = v10504->regs;
  int v10521 = v10508 | v10510;
  v10511[6] = v10521;
  struct StateT * v10513 = slot_184(v10504);
  return v10513;
}

struct StateT * slot_240(struct StateT * v5464) {
  int v5465 = v5464->timer;
  int v5473 = v5465 + 1;
  v5464->timer = v5473;
  int * v5467 = v5464->regs;
  int v5468 = v5467[7];
  int * v5469 = v5464->regs;
  int v5477 = v5468 + -718;
  v5469[7] = v5477;
  struct StateT * v5471 = slot_241(v5464);
  return v5471;
}

struct StateT * slot_247(struct StateT * v5797) {
  int v5798 = v5797->timer;
  int v5852 = v5798 + 1;
  v5797->timer = v5852;
  int * v5800 = v5797->regs;
  int v5801 = v5800[10];
  int * v5802 = v5797->regs;
  int v5803 = v5802[29];
  int * v5804 = v5797->cache_keys;
  int v5805 = v5804[0];
  bool v5859 = v5805 == ((int)((unsigned int)(v5801 + 4) >> 2));
  int v5849;
  if (v5859) {
    int * v5806 = v5797->cache_vals;
    v5806[0] = v5803;
    v5849 = v5803;
  } else {
    int * v5809 = v5797->cache_keys;
    int v5810 = v5809[1];
    bool v5864 = v5810 == ((int)((unsigned int)(v5801 + 4) >> 2));
    int v5847;
    if (v5864) {
      int * v5811 = v5797->cache_keys;
      int * v5812 = v5797->cache_keys;
      int v5813 = v5812[0];
      v5811[1] = v5813;
      int * v5815 = v5797->cache_vals;
      int * v5816 = v5797->cache_vals;
      int v5817 = v5816[0];
      v5815[1] = v5817;
      int * v5819 = v5797->cache_keys;
      int v5872 = (int)((unsigned int)(v5801 + 4) >> 2);
      v5819[0] = v5872;
      int * v5821 = v5797->cache_vals;
      v5821[0] = v5803;
      int v5823 = v5797->timer;
      int v5875 = v5823 + 1;
      v5797->timer = v5875;
      v5847 = v5803;
    } else {
      int * v5826 = v5797->mem;
      int * v5827 = v5797->cache_keys;
      int v5828 = v5827[1];
      int * v5829 = v5797->cache_vals;
      int v5830 = v5829[1];
      v5826[v5828] = v5830;
      int * v5832 = v5797->cache_keys;
      int * v5833 = v5797->cache_keys;
      int v5834 = v5833[0];
      v5832[1] = v5834;
      int * v5836 = v5797->cache_vals;
      int * v5837 = v5797->cache_vals;
      int v5838 = v5837[0];
      v5836[1] = v5838;
      int * v5840 = v5797->cache_keys;
      int v5888 = (int)((unsigned int)(v5801 + 4) >> 2);
      v5840[0] = v5888;
      int * v5842 = v5797->cache_vals;
      v5842[0] = v5803;
      int v5844 = v5797->timer;
      int v5891 = v5844 + 100;
      v5797->timer = v5891;
      v5847 = v5803;
    }
    v5849 = v5847;
  }
  struct StateT * v5850 = slot_248(v5797);
  return v5850;
}

struct StateT * slot_43(struct StateT * v3381) {
  int v3382 = v3381->timer;
  int v3436 = v3382 + 1;
  v3381->timer = v3436;
  int * v3384 = v3381->regs;
  int v3385 = v3384[2];
  int * v3386 = v3381->regs;
  int v3387 = v3386[6];
  int * v3388 = v3381->cache_keys;
  int v3389 = v3388[0];
  bool v3443 = v3389 == ((int)((unsigned int)(v3385 + 8) >> 2));
  int v3433;
  if (v3443) {
    int * v3390 = v3381->cache_vals;
    v3390[0] = v3387;
    v3433 = v3387;
  } else {
    int * v3393 = v3381->cache_keys;
    int v3394 = v3393[1];
    bool v3448 = v3394 == ((int)((unsigned int)(v3385 + 8) >> 2));
    int v3431;
    if (v3448) {
      int * v3395 = v3381->cache_keys;
      int * v3396 = v3381->cache_keys;
      int v3397 = v3396[0];
      v3395[1] = v3397;
      int * v3399 = v3381->cache_vals;
      int * v3400 = v3381->cache_vals;
      int v3401 = v3400[0];
      v3399[1] = v3401;
      int * v3403 = v3381->cache_keys;
      int v3456 = (int)((unsigned int)(v3385 + 8) >> 2);
      v3403[0] = v3456;
      int * v3405 = v3381->cache_vals;
      v3405[0] = v3387;
      int v3407 = v3381->timer;
      int v3459 = v3407 + 1;
      v3381->timer = v3459;
      v3431 = v3387;
    } else {
      int * v3410 = v3381->mem;
      int * v3411 = v3381->cache_keys;
      int v3412 = v3411[1];
      int * v3413 = v3381->cache_vals;
      int v3414 = v3413[1];
      v3410[v3412] = v3414;
      int * v3416 = v3381->cache_keys;
      int * v3417 = v3381->cache_keys;
      int v3418 = v3417[0];
      v3416[1] = v3418;
      int * v3420 = v3381->cache_vals;
      int * v3421 = v3381->cache_vals;
      int v3422 = v3421[0];
      v3420[1] = v3422;
      int * v3424 = v3381->cache_keys;
      int v3472 = (int)((unsigned int)(v3385 + 8) >> 2);
      v3424[0] = v3472;
      int * v3426 = v3381->cache_vals;
      v3426[0] = v3387;
      int v3428 = v3381->timer;
      int v3475 = v3428 + 100;
      v3381->timer = v3475;
      v3431 = v3387;
    }
    v3433 = v3431;
  }
  struct StateT * v3434 = slot_44(v3381);
  return v3434;
}

struct StateT * slot_70(struct StateT * v5012) {
  int v5013 = v5012->timer;
  int v5023 = v5013 + 1;
  v5012->timer = v5023;
  int * v5015 = v5012->regs;
  int v5016 = v5015[14];
  int * v5017 = v5012->regs;
  int v5018 = v5017[8];
  int * v5019 = v5012->regs;
  int v5029 = v5016 ^ v5018;
  v5019[14] = v5029;
  struct StateT * v5021 = slot_71(v5012);
  return v5021;
}

struct StateT * slot_168(struct StateT * v10221) {
  int v10222 = v10221->timer;
  int v10232 = v10222 + 1;
  v10221->timer = v10232;
  int * v10224 = v10221->regs;
  int v10225 = v10224[25];
  int * v10226 = v10221->regs;
  int v10227 = v10226[15];
  int * v10228 = v10221->regs;
  int v10238 = v10225 ^ v10227;
  v10228[25] = v10238;
  struct StateT * v10230 = slot_169(v10221);
  return v10230;
}

struct StateT * slot_76(struct StateT * v5412) {
  int v5413 = v5412->timer;
  int v5421 = v5413 + 1;
  v5412->timer = v5421;
  int * v5415 = v5412->regs;
  int v5416 = v5415[15];
  int * v5417 = v5412->regs;
  int v5425 = v5416 << 9;
  v5417[15] = v5425;
  struct StateT * v5419 = slot_77(v5412);
  return v5419;
}

struct StateT * slot_6(struct StateT * v507) {
  int v508 = v507->timer;
  int v562 = v508 + 1;
  v507->timer = v562;
  int * v510 = v507->regs;
  int v511 = v510[2];
  int * v512 = v507->regs;
  int v513 = v512[20];
  int * v514 = v507->cache_keys;
  int v515 = v514[0];
  bool v569 = v515 == ((int)((unsigned int)(v511 + 72) >> 2));
  int v559;
  if (v569) {
    int * v516 = v507->cache_vals;
    v516[0] = v513;
    v559 = v513;
  } else {
    int * v519 = v507->cache_keys;
    int v520 = v519[1];
    bool v574 = v520 == ((int)((unsigned int)(v511 + 72) >> 2));
    int v557;
    if (v574) {
      int * v521 = v507->cache_keys;
      int * v522 = v507->cache_keys;
      int v523 = v522[0];
      v521[1] = v523;
      int * v525 = v507->cache_vals;
      int * v526 = v507->cache_vals;
      int v527 = v526[0];
      v525[1] = v527;
      int * v529 = v507->cache_keys;
      int v582 = (int)((unsigned int)(v511 + 72) >> 2);
      v529[0] = v582;
      int * v531 = v507->cache_vals;
      v531[0] = v513;
      int v533 = v507->timer;
      int v585 = v533 + 1;
      v507->timer = v585;
      v557 = v513;
    } else {
      int * v536 = v507->mem;
      int * v537 = v507->cache_keys;
      int v538 = v537[1];
      int * v539 = v507->cache_vals;
      int v540 = v539[1];
      v536[v538] = v540;
      int * v542 = v507->cache_keys;
      int * v543 = v507->cache_keys;
      int v544 = v543[0];
      v542[1] = v544;
      int * v546 = v507->cache_vals;
      int * v547 = v507->cache_vals;
      int v548 = v547[0];
      v546[1] = v548;
      int * v550 = v507->cache_keys;
      int v598 = (int)((unsigned int)(v511 + 72) >> 2);
      v550[0] = v598;
      int * v552 = v507->cache_vals;
      v552[0] = v513;
      int v554 = v507->timer;
      int v601 = v554 + 100;
      v507->timer = v601;
      v557 = v513;
    }
    v559 = v557;
  }
  struct StateT * v560 = slot_7(v507);
  return v560;
}

struct StateT * slot_225(struct StateT * v4471) {
  int v4472 = v4471->timer;
  int v4482 = v4472 + 1;
  v4471->timer = v4482;
  int * v4474 = v4471->regs;
  int v4475 = v4474[26];
  int * v4476 = v4471->regs;
  int v4477 = v4476[7];
  int * v4478 = v4471->regs;
  int v4488 = v4475 + v4477;
  v4478[26] = v4488;
  struct StateT * v4480 = slot_226(v4471);
  return v4480;
}

struct StateT * slot_55(struct StateT * v3944) {
  int v3945 = v3944->timer;
  int v3953 = v3945 + 1;
  v3944->timer = v3953;
  int * v3947 = v3944->regs;
  int v3948 = v3947[15];
  int * v3949 = v3944->regs;
  int v3958 = (int)((unsigned int)v3948 >> 25);
  v3949[9] = v3958;
  struct StateT * v3951 = slot_56(v3944);
  return v3951;
}

struct StateT * slot_213(struct StateT * v3682) {
  int v3683 = v3682->timer;
  int v3693 = v3683 + 1;
  v3682->timer = v3693;
  int * v3685 = v3682->regs;
  int v3686 = v3685[23];
  int * v3687 = v3682->regs;
  int v3688 = v3687[29];
  int * v3689 = v3682->regs;
  int v3699 = v3686 + v3688;
  v3689[29] = v3699;
  struct StateT * v3691 = slot_214(v3682);
  return v3691;
}

struct StateT * slot_82(struct StateT * v5626) {
  int v5627 = v5626->timer;
  int v5635 = v5627 + 1;
  v5626->timer = v5635;
  int * v5629 = v5626->regs;
  int v5630 = v5629[9];
  int * v5631 = v5626->regs;
  int v5639 = v5630 << 9;
  v5631[9] = v5639;
  struct StateT * v5633 = slot_83(v5626);
  return v5633;
}

struct StateT * slot_274(struct StateT * v9043) {
  int v9044 = v9043->timer;
  int v9102 = v9044 + 1;
  v9043->timer = v9102;
  int * v9046 = v9043->regs;
  int v9047 = v9046[2];
  int * v9048 = v9043->cache_keys;
  int v9049 = v9048[0];
  bool v9107 = v9049 == ((int)((unsigned int)(v9047 + 44) >> 2));
  int v9097;
  if (v9107) {
    int * v9050 = v9043->cache_vals;
    int v9051 = v9050[0];
    v9097 = v9051;
  } else {
    int * v9053 = v9043->cache_keys;
    int v9054 = v9053[1];
    bool v9112 = v9054 == ((int)((unsigned int)(v9047 + 44) >> 2));
    int v9095;
    if (v9112) {
      int * v9055 = v9043->cache_vals;
      int v9056 = v9055[1];
      int * v9057 = v9043->cache_keys;
      int * v9058 = v9043->cache_keys;
      int v9059 = v9058[0];
      v9057[1] = v9059;
      int * v9061 = v9043->cache_vals;
      int * v9062 = v9043->cache_vals;
      int v9063 = v9062[0];
      v9061[1] = v9063;
      int * v9065 = v9043->cache_keys;
      int v9121 = (int)((unsigned int)(v9047 + 44) >> 2);
      v9065[0] = v9121;
      int * v9067 = v9043->cache_vals;
      v9067[0] = v9056;
      int v9069 = v9043->timer;
      int v9124 = v9069 + 1;
      v9043->timer = v9124;
      v9095 = v9056;
    } else {
      int * v9072 = v9043->mem;
      int v9126 = (int)((unsigned int)(v9047 + 44) >> 2);
      int v9073 = v9072[v9126];
      int * v9074 = v9043->mem;
      int * v9075 = v9043->cache_keys;
      int v9076 = v9075[1];
      int * v9077 = v9043->cache_vals;
      int v9078 = v9077[1];
      v9074[v9076] = v9078;
      int * v9080 = v9043->cache_keys;
      int * v9081 = v9043->cache_keys;
      int v9082 = v9081[0];
      v9080[1] = v9082;
      int * v9084 = v9043->cache_vals;
      int * v9085 = v9043->cache_vals;
      int v9086 = v9085[0];
      v9084[1] = v9086;
      int * v9088 = v9043->cache_keys;
      v9088[0] = v9126;
      int * v9090 = v9043->cache_vals;
      v9090[0] = v9073;
      int v9092 = v9043->timer;
      int v9141 = v9092 + 100;
      v9043->timer = v9141;
      v9095 = v9073;
    }
    v9097 = v9095;
  }
  int * v9098 = v9043->regs;
  v9098[27] = v9097;
  struct StateT * v9100 = slot_275(v9043);
  return v9100;
}

struct StateT * slot_263(struct StateT * v7677) {
  int v7678 = v7677->timer;
  int v7736 = v7678 + 1;
  v7677->timer = v7736;
  int * v7680 = v7677->regs;
  int v7681 = v7680[2];
  int * v7682 = v7677->cache_keys;
  int v7683 = v7682[0];
  bool v7741 = v7683 == ((int)((unsigned int)(v7681 + 88) >> 2));
  int v7731;
  if (v7741) {
    int * v7684 = v7677->cache_vals;
    int v7685 = v7684[0];
    v7731 = v7685;
  } else {
    int * v7687 = v7677->cache_keys;
    int v7688 = v7687[1];
    bool v7746 = v7688 == ((int)((unsigned int)(v7681 + 88) >> 2));
    int v7729;
    if (v7746) {
      int * v7689 = v7677->cache_vals;
      int v7690 = v7689[1];
      int * v7691 = v7677->cache_keys;
      int * v7692 = v7677->cache_keys;
      int v7693 = v7692[0];
      v7691[1] = v7693;
      int * v7695 = v7677->cache_vals;
      int * v7696 = v7677->cache_vals;
      int v7697 = v7696[0];
      v7695[1] = v7697;
      int * v7699 = v7677->cache_keys;
      int v7755 = (int)((unsigned int)(v7681 + 88) >> 2);
      v7699[0] = v7755;
      int * v7701 = v7677->cache_vals;
      v7701[0] = v7690;
      int v7703 = v7677->timer;
      int v7758 = v7703 + 1;
      v7677->timer = v7758;
      v7729 = v7690;
    } else {
      int * v7706 = v7677->mem;
      int v7760 = (int)((unsigned int)(v7681 + 88) >> 2);
      int v7707 = v7706[v7760];
      int * v7708 = v7677->mem;
      int * v7709 = v7677->cache_keys;
      int v7710 = v7709[1];
      int * v7711 = v7677->cache_vals;
      int v7712 = v7711[1];
      v7708[v7710] = v7712;
      int * v7714 = v7677->cache_keys;
      int * v7715 = v7677->cache_keys;
      int v7716 = v7715[0];
      v7714[1] = v7716;
      int * v7718 = v7677->cache_vals;
      int * v7719 = v7677->cache_vals;
      int v7720 = v7719[0];
      v7718[1] = v7720;
      int * v7722 = v7677->cache_keys;
      v7722[0] = v7760;
      int * v7724 = v7677->cache_vals;
      v7724[0] = v7707;
      int v7726 = v7677->timer;
      int v7775 = v7726 + 100;
      v7677->timer = v7775;
      v7729 = v7707;
    }
    v7731 = v7729;
  }
  int * v7732 = v7677->regs;
  v7732[8] = v7731;
  struct StateT * v7734 = slot_264(v7677);
  return v7734;
}

struct StateT * slot_161(struct StateT * v10095) {
  int v10096 = v10095->timer;
  int v10104 = v10096 + 1;
  v10095->timer = v10104;
  int * v10098 = v10095->regs;
  int v10099 = v10098[6];
  int * v10100 = v10095->regs;
  int v10109 = (int)((unsigned int)v10099 >> 23);
  v10100[9] = v10109;
  struct StateT * v10102 = slot_162(v10095);
  return v10102;
}

struct StateT * slot_185(struct StateT * v10541) {
  int v10542 = v10541->timer;
  int v10550 = v10542 + 1;
  v10541->timer = v10550;
  int * v10544 = v10541->regs;
  int v10545 = v10544[8];
  int * v10546 = v10541->regs;
  int v10554 = v10545 << 13;
  v10546[8] = v10554;
  struct StateT * v10548 = slot_186(v10541);
  return v10548;
}

struct StateT * slot_91(struct StateT * v6599) {
  int v6600 = v6599->timer;
  int v6610 = v6600 + 1;
  v6599->timer = v6610;
  int * v6602 = v6599->regs;
  int v6603 = v6602[26];
  int * v6604 = v6599->regs;
  int v6605 = v6604[12];
  int * v6606 = v6599->regs;
  int v6617 = v6603 + v6605;
  v6606[15] = v6617;
  struct StateT * v6608 = slot_92(v6599);
  return v6608;
}

struct StateT * slot_58(struct StateT * v4135) {
  int v4136 = v4135->timer;
  int v4144 = v4136 + 1;
  v4135->timer = v4144;
  int * v4138 = v4135->regs;
  int v4139 = v4138[20];
  int * v4140 = v4135->regs;
  int v4149 = (int)((unsigned int)v4139 >> 25);
  v4140[9] = v4149;
  struct StateT * v4142 = slot_59(v4135);
  return v4142;
}

struct StateT * slot_89(struct StateT * v6363) {
  int v6364 = v6363->timer;
  int v6374 = v6364 + 1;
  v6363->timer = v6374;
  int * v6366 = v6363->regs;
  int v6367 = v6366[27];
  int * v6368 = v6363->regs;
  int v6369 = v6368[9];
  int * v6370 = v6363->regs;
  int v6380 = v6367 ^ v6369;
  v6370[27] = v6380;
  struct StateT * v6372 = slot_90(v6363);
  return v6372;
}

struct StateT * slot_255(struct StateT * v6739) {
  int v6740 = v6739->timer;
  int v6794 = v6740 + 1;
  v6739->timer = v6794;
  int * v6742 = v6739->regs;
  int v6743 = v6742[10];
  int * v6744 = v6739->regs;
  int v6745 = v6744[13];
  int * v6746 = v6739->cache_keys;
  int v6747 = v6746[0];
  bool v6801 = v6747 == ((int)((unsigned int)(v6743 + 36) >> 2));
  int v6791;
  if (v6801) {
    int * v6748 = v6739->cache_vals;
    v6748[0] = v6745;
    v6791 = v6745;
  } else {
    int * v6751 = v6739->cache_keys;
    int v6752 = v6751[1];
    bool v6806 = v6752 == ((int)((unsigned int)(v6743 + 36) >> 2));
    int v6789;
    if (v6806) {
      int * v6753 = v6739->cache_keys;
      int * v6754 = v6739->cache_keys;
      int v6755 = v6754[0];
      v6753[1] = v6755;
      int * v6757 = v6739->cache_vals;
      int * v6758 = v6739->cache_vals;
      int v6759 = v6758[0];
      v6757[1] = v6759;
      int * v6761 = v6739->cache_keys;
      int v6814 = (int)((unsigned int)(v6743 + 36) >> 2);
      v6761[0] = v6814;
      int * v6763 = v6739->cache_vals;
      v6763[0] = v6745;
      int v6765 = v6739->timer;
      int v6817 = v6765 + 1;
      v6739->timer = v6817;
      v6789 = v6745;
    } else {
      int * v6768 = v6739->mem;
      int * v6769 = v6739->cache_keys;
      int v6770 = v6769[1];
      int * v6771 = v6739->cache_vals;
      int v6772 = v6771[1];
      v6768[v6770] = v6772;
      int * v6774 = v6739->cache_keys;
      int * v6775 = v6739->cache_keys;
      int v6776 = v6775[0];
      v6774[1] = v6776;
      int * v6778 = v6739->cache_vals;
      int * v6779 = v6739->cache_vals;
      int v6780 = v6779[0];
      v6778[1] = v6780;
      int * v6782 = v6739->cache_keys;
      int v6830 = (int)((unsigned int)(v6743 + 36) >> 2);
      v6782[0] = v6830;
      int * v6784 = v6739->cache_vals;
      v6784[0] = v6745;
      int v6786 = v6739->timer;
      int v6833 = v6786 + 100;
      v6739->timer = v6833;
      v6789 = v6745;
    }
    v6791 = v6789;
  }
  struct StateT * v6792 = slot_256(v6739);
  return v6792;
}

struct StateT * slot_66(struct StateT * v4682) {
  int v4683 = v4682->timer;
  int v4693 = v4683 + 1;
  v4682->timer = v4693;
  int * v4685 = v4682->regs;
  int v4686 = v4685[8];
  int * v4687 = v4682->regs;
  int v4688 = v4687[20];
  int * v4689 = v4682->regs;
  int v4699 = v4686 | v4688;
  v4689[8] = v4699;
  struct StateT * v4691 = slot_67(v4682);
  return v4691;
}

struct StateT * slot_140(struct StateT * v9695) {
  int v9696 = v9695->timer;
  int v9706 = v9696 + 1;
  v9695->timer = v9706;
  int * v9698 = v9695->regs;
  int v9699 = v9698[11];
  int * v9700 = v9695->regs;
  int v9701 = v9700[5];
  int * v9702 = v9695->regs;
  int v9712 = v9699 | v9701;
  v9702[11] = v9712;
  struct StateT * v9704 = slot_141(v9695);
  return v9704;
}

struct StateT * slot_265(struct StateT * v7920) {
  int v7921 = v7920->timer;
  int v7979 = v7921 + 1;
  v7920->timer = v7979;
  int * v7923 = v7920->regs;
  int v7924 = v7923[2];
  int * v7925 = v7920->cache_keys;
  int v7926 = v7925[0];
  bool v7984 = v7926 == ((int)((unsigned int)(v7924 + 80) >> 2));
  int v7974;
  if (v7984) {
    int * v7927 = v7920->cache_vals;
    int v7928 = v7927[0];
    v7974 = v7928;
  } else {
    int * v7930 = v7920->cache_keys;
    int v7931 = v7930[1];
    bool v7989 = v7931 == ((int)((unsigned int)(v7924 + 80) >> 2));
    int v7972;
    if (v7989) {
      int * v7932 = v7920->cache_vals;
      int v7933 = v7932[1];
      int * v7934 = v7920->cache_keys;
      int * v7935 = v7920->cache_keys;
      int v7936 = v7935[0];
      v7934[1] = v7936;
      int * v7938 = v7920->cache_vals;
      int * v7939 = v7920->cache_vals;
      int v7940 = v7939[0];
      v7938[1] = v7940;
      int * v7942 = v7920->cache_keys;
      int v7998 = (int)((unsigned int)(v7924 + 80) >> 2);
      v7942[0] = v7998;
      int * v7944 = v7920->cache_vals;
      v7944[0] = v7933;
      int v7946 = v7920->timer;
      int v8001 = v7946 + 1;
      v7920->timer = v8001;
      v7972 = v7933;
    } else {
      int * v7949 = v7920->mem;
      int v8003 = (int)((unsigned int)(v7924 + 80) >> 2);
      int v7950 = v7949[v8003];
      int * v7951 = v7920->mem;
      int * v7952 = v7920->cache_keys;
      int v7953 = v7952[1];
      int * v7954 = v7920->cache_vals;
      int v7955 = v7954[1];
      v7951[v7953] = v7955;
      int * v7957 = v7920->cache_keys;
      int * v7958 = v7920->cache_keys;
      int v7959 = v7958[0];
      v7957[1] = v7959;
      int * v7961 = v7920->cache_vals;
      int * v7962 = v7920->cache_vals;
      int v7963 = v7962[0];
      v7961[1] = v7963;
      int * v7965 = v7920->cache_keys;
      v7965[0] = v8003;
      int * v7967 = v7920->cache_vals;
      v7967[0] = v7950;
      int v7969 = v7920->timer;
      int v8018 = v7969 + 100;
      v7920->timer = v8018;
      v7972 = v7950;
    }
    v7974 = v7972;
  }
  int * v7975 = v7920->regs;
  v7975[18] = v7974;
  struct StateT * v7977 = slot_266(v7920);
  return v7977;
}

struct StateT * slot_49(struct StateT * v3645) {
  int v3646 = v3645->timer;
  int v3654 = v3646 + 1;
  v3645->timer = v3654;
  int * v3648 = v3645->regs;
  int v3649 = v3648[15];
  int * v3650 = v3645->regs;
  v3650[13] = v3649;
  struct StateT * v3652 = slot_50(v3645);
  return v3652;
}

struct StateT * slot_216(struct StateT * v3798) {
  int v3799 = v3798->timer;
  int v3809 = v3799 + 1;
  v3798->timer = v3809;
  int * v3801 = v3798->regs;
  int v3802 = v3801[14];
  int * v3803 = v3798->regs;
  int v3804 = v3803[7];
  int * v3805 = v3798->regs;
  int v3815 = v3802 + v3804;
  v3805[14] = v3815;
  struct StateT * v3807 = slot_217(v3798);
  return v3807;
}

struct StateT * slot_50(struct StateT * v3662) {
  int v3663 = v3662->timer;
  int v3673 = v3663 + 1;
  v3662->timer = v3673;
  int * v3665 = v3662->regs;
  int v3666 = v3665[31];
  bool v3676 = (v3666 ^ -2147483648) < -2147483648;
  struct StateT * v3671;
  if (v3676) {
    struct StateT * v3667 = slot_213(v3662);
    v3671 = v3667;
  } else {
    struct StateT * v3669 = slot_51(v3662);
    v3671 = v3669;
  }
  return v3671;
}

struct StateT * slot_37(struct StateT * v2794) {
  int v2795 = v2794->timer;
  int v2849 = v2795 + 1;
  v2794->timer = v2849;
  int * v2797 = v2794->regs;
  int v2798 = v2797[2];
  int * v2799 = v2794->regs;
  int v2800 = v2799[25];
  int * v2801 = v2794->cache_keys;
  int v2802 = v2801[0];
  bool v2856 = v2802 == ((int)((unsigned int)(v2798 + 16) >> 2));
  int v2846;
  if (v2856) {
    int * v2803 = v2794->cache_vals;
    v2803[0] = v2800;
    v2846 = v2800;
  } else {
    int * v2806 = v2794->cache_keys;
    int v2807 = v2806[1];
    bool v2861 = v2807 == ((int)((unsigned int)(v2798 + 16) >> 2));
    int v2844;
    if (v2861) {
      int * v2808 = v2794->cache_keys;
      int * v2809 = v2794->cache_keys;
      int v2810 = v2809[0];
      v2808[1] = v2810;
      int * v2812 = v2794->cache_vals;
      int * v2813 = v2794->cache_vals;
      int v2814 = v2813[0];
      v2812[1] = v2814;
      int * v2816 = v2794->cache_keys;
      int v2869 = (int)((unsigned int)(v2798 + 16) >> 2);
      v2816[0] = v2869;
      int * v2818 = v2794->cache_vals;
      v2818[0] = v2800;
      int v2820 = v2794->timer;
      int v2872 = v2820 + 1;
      v2794->timer = v2872;
      v2844 = v2800;
    } else {
      int * v2823 = v2794->mem;
      int * v2824 = v2794->cache_keys;
      int v2825 = v2824[1];
      int * v2826 = v2794->cache_vals;
      int v2827 = v2826[1];
      v2823[v2825] = v2827;
      int * v2829 = v2794->cache_keys;
      int * v2830 = v2794->cache_keys;
      int v2831 = v2830[0];
      v2829[1] = v2831;
      int * v2833 = v2794->cache_vals;
      int * v2834 = v2794->cache_vals;
      int v2835 = v2834[0];
      v2833[1] = v2835;
      int * v2837 = v2794->cache_keys;
      int v2885 = (int)((unsigned int)(v2798 + 16) >> 2);
      v2837[0] = v2885;
      int * v2839 = v2794->cache_vals;
      v2839[0] = v2800;
      int v2841 = v2794->timer;
      int v2888 = v2841 + 100;
      v2794->timer = v2888;
      v2844 = v2800;
    }
    v2846 = v2844;
  }
  struct StateT * v2847 = slot_38(v2794);
  return v2847;
}

struct StateT * slot_114(struct StateT * v9211) {
  int v9212 = v9211->timer;
  int v9222 = v9212 + 1;
  v9211->timer = v9222;
  int * v9214 = v9211->regs;
  int v9215 = v9214[8];
  int * v9216 = v9211->regs;
  int v9217 = v9216[25];
  int * v9218 = v9211->regs;
  int v9229 = v9215 + v9217;
  v9218[5] = v9229;
  struct StateT * v9220 = slot_115(v9211);
  return v9220;
}

struct StateT * slot_135(struct StateT * v9609) {
  int v9610 = v9609->timer;
  int v9618 = v9610 + 1;
  v9609->timer = v9618;
  int * v9612 = v9609->regs;
  int v9613 = v9612[15];
  int * v9614 = v9609->regs;
  int v9623 = (int)((unsigned int)v9613 >> 25);
  v9614[5] = v9623;
  struct StateT * v9616 = slot_136(v9609);
  return v9616;
}

struct StateT * slot_248(struct StateT * v5911) {
  int v5912 = v5911->timer;
  int v5966 = v5912 + 1;
  v5911->timer = v5966;
  int * v5914 = v5911->regs;
  int v5915 = v5914[10];
  int * v5916 = v5911->regs;
  int v5917 = v5916[28];
  int * v5918 = v5911->cache_keys;
  int v5919 = v5918[0];
  bool v5973 = v5919 == ((int)((unsigned int)(v5915 + 8) >> 2));
  int v5963;
  if (v5973) {
    int * v5920 = v5911->cache_vals;
    v5920[0] = v5917;
    v5963 = v5917;
  } else {
    int * v5923 = v5911->cache_keys;
    int v5924 = v5923[1];
    bool v5978 = v5924 == ((int)((unsigned int)(v5915 + 8) >> 2));
    int v5961;
    if (v5978) {
      int * v5925 = v5911->cache_keys;
      int * v5926 = v5911->cache_keys;
      int v5927 = v5926[0];
      v5925[1] = v5927;
      int * v5929 = v5911->cache_vals;
      int * v5930 = v5911->cache_vals;
      int v5931 = v5930[0];
      v5929[1] = v5931;
      int * v5933 = v5911->cache_keys;
      int v5986 = (int)((unsigned int)(v5915 + 8) >> 2);
      v5933[0] = v5986;
      int * v5935 = v5911->cache_vals;
      v5935[0] = v5917;
      int v5937 = v5911->timer;
      int v5989 = v5937 + 1;
      v5911->timer = v5989;
      v5961 = v5917;
    } else {
      int * v5940 = v5911->mem;
      int * v5941 = v5911->cache_keys;
      int v5942 = v5941[1];
      int * v5943 = v5911->cache_vals;
      int v5944 = v5943[1];
      v5940[v5942] = v5944;
      int * v5946 = v5911->cache_keys;
      int * v5947 = v5911->cache_keys;
      int v5948 = v5947[0];
      v5946[1] = v5948;
      int * v5950 = v5911->cache_vals;
      int * v5951 = v5911->cache_vals;
      int v5952 = v5951[0];
      v5950[1] = v5952;
      int * v5954 = v5911->cache_keys;
      int v6002 = (int)((unsigned int)(v5915 + 8) >> 2);
      v5954[0] = v6002;
      int * v5956 = v5911->cache_vals;
      v5956[0] = v5917;
      int v5958 = v5911->timer;
      int v6005 = v5958 + 100;
      v5911->timer = v6005;
      v5961 = v5917;
    }
    v5963 = v5961;
  }
  struct StateT * v5964 = slot_249(v5911);
  return v5964;
}

struct StateT * slot_257(struct StateT * v6977) {
  int v6978 = v6977->timer;
  int v7032 = v6978 + 1;
  v6977->timer = v7032;
  int * v6980 = v6977->regs;
  int v6981 = v6980[10];
  int * v6982 = v6977->regs;
  int v6983 = v6982[17];
  int * v6984 = v6977->cache_keys;
  int v6985 = v6984[0];
  bool v7039 = v6985 == ((int)((unsigned int)(v6981 + 44) >> 2));
  int v7029;
  if (v7039) {
    int * v6986 = v6977->cache_vals;
    v6986[0] = v6983;
    v7029 = v6983;
  } else {
    int * v6989 = v6977->cache_keys;
    int v6990 = v6989[1];
    bool v7044 = v6990 == ((int)((unsigned int)(v6981 + 44) >> 2));
    int v7027;
    if (v7044) {
      int * v6991 = v6977->cache_keys;
      int * v6992 = v6977->cache_keys;
      int v6993 = v6992[0];
      v6991[1] = v6993;
      int * v6995 = v6977->cache_vals;
      int * v6996 = v6977->cache_vals;
      int v6997 = v6996[0];
      v6995[1] = v6997;
      int * v6999 = v6977->cache_keys;
      int v7052 = (int)((unsigned int)(v6981 + 44) >> 2);
      v6999[0] = v7052;
      int * v7001 = v6977->cache_vals;
      v7001[0] = v6983;
      int v7003 = v6977->timer;
      int v7055 = v7003 + 1;
      v6977->timer = v7055;
      v7027 = v6983;
    } else {
      int * v7006 = v6977->mem;
      int * v7007 = v6977->cache_keys;
      int v7008 = v7007[1];
      int * v7009 = v6977->cache_vals;
      int v7010 = v7009[1];
      v7006[v7008] = v7010;
      int * v7012 = v6977->cache_keys;
      int * v7013 = v6977->cache_keys;
      int v7014 = v7013[0];
      v7012[1] = v7014;
      int * v7016 = v6977->cache_vals;
      int * v7017 = v6977->cache_vals;
      int v7018 = v7017[0];
      v7016[1] = v7018;
      int * v7020 = v6977->cache_keys;
      int v7068 = (int)((unsigned int)(v6981 + 44) >> 2);
      v7020[0] = v7068;
      int * v7022 = v6977->cache_vals;
      v7022[0] = v6983;
      int v7024 = v6977->timer;
      int v7071 = v7024 + 100;
      v6977->timer = v7071;
      v7027 = v6983;
    }
    v7029 = v7027;
  }
  struct StateT * v7030 = slot_258(v6977);
  return v7030;
}

struct StateT * slot_59(struct StateT * v4172) {
  int v4173 = v4172->timer;
  int v4181 = v4173 + 1;
  v4172->timer = v4181;
  int * v4175 = v4172->regs;
  int v4176 = v4175[20];
  int * v4177 = v4172->regs;
  int v4185 = v4176 << 7;
  v4177[20] = v4185;
  struct StateT * v4179 = slot_60(v4172);
  return v4179;
}

struct StateT * slot_192(struct StateT * v10678) {
  int v10679 = v10678->timer;
  int v10689 = v10679 + 1;
  v10678->timer = v10689;
  int * v10681 = v10678->regs;
  int v10682 = v10681[12];
  int * v10683 = v10678->regs;
  int v10684 = v10683[25];
  int * v10685 = v10678->regs;
  int v10696 = v10682 + v10684;
  v10685[15] = v10696;
  struct StateT * v10687 = slot_193(v10678);
  return v10687;
}

struct StateT * slot_40(struct StateT * v3087) {
  int v3088 = v3087->timer;
  int v3142 = v3088 + 1;
  v3087->timer = v3142;
  int * v3090 = v3087->regs;
  int v3091 = v3090[2];
  int * v3092 = v3087->regs;
  int v3093 = v3092[24];
  int * v3094 = v3087->cache_keys;
  int v3095 = v3094[0];
  bool v3149 = v3095 == ((int)((unsigned int)(v3091 + 36) >> 2));
  int v3139;
  if (v3149) {
    int * v3096 = v3087->cache_vals;
    v3096[0] = v3093;
    v3139 = v3093;
  } else {
    int * v3099 = v3087->cache_keys;
    int v3100 = v3099[1];
    bool v3154 = v3100 == ((int)((unsigned int)(v3091 + 36) >> 2));
    int v3137;
    if (v3154) {
      int * v3101 = v3087->cache_keys;
      int * v3102 = v3087->cache_keys;
      int v3103 = v3102[0];
      v3101[1] = v3103;
      int * v3105 = v3087->cache_vals;
      int * v3106 = v3087->cache_vals;
      int v3107 = v3106[0];
      v3105[1] = v3107;
      int * v3109 = v3087->cache_keys;
      int v3162 = (int)((unsigned int)(v3091 + 36) >> 2);
      v3109[0] = v3162;
      int * v3111 = v3087->cache_vals;
      v3111[0] = v3093;
      int v3113 = v3087->timer;
      int v3165 = v3113 + 1;
      v3087->timer = v3165;
      v3137 = v3093;
    } else {
      int * v3116 = v3087->mem;
      int * v3117 = v3087->cache_keys;
      int v3118 = v3117[1];
      int * v3119 = v3087->cache_vals;
      int v3120 = v3119[1];
      v3116[v3118] = v3120;
      int * v3122 = v3087->cache_keys;
      int * v3123 = v3087->cache_keys;
      int v3124 = v3123[0];
      v3122[1] = v3124;
      int * v3126 = v3087->cache_vals;
      int * v3127 = v3087->cache_vals;
      int v3128 = v3127[0];
      v3126[1] = v3128;
      int * v3130 = v3087->cache_keys;
      int v3178 = (int)((unsigned int)(v3091 + 36) >> 2);
      v3130[0] = v3178;
      int * v3132 = v3087->cache_vals;
      v3132[0] = v3093;
      int v3134 = v3087->timer;
      int v3181 = v3134 + 100;
      v3087->timer = v3181;
      v3137 = v3093;
    }
    v3139 = v3137;
  }
  struct StateT * v3140 = slot_41(v3087);
  return v3140;
}

struct StateT * slot_48(struct StateT * v3547) {
  int v3548 = v3547->timer;
  int v3602 = v3548 + 1;
  v3547->timer = v3602;
  int * v3550 = v3547->regs;
  int v3551 = v3550[2];
  int * v3552 = v3547->regs;
  int v3553 = v3552[15];
  int * v3554 = v3547->cache_keys;
  int v3555 = v3554[0];
  bool v3609 = v3555 == ((int)((unsigned int)(v3551 + 24) >> 2));
  int v3599;
  if (v3609) {
    int * v3556 = v3547->cache_vals;
    v3556[0] = v3553;
    v3599 = v3553;
  } else {
    int * v3559 = v3547->cache_keys;
    int v3560 = v3559[1];
    bool v3614 = v3560 == ((int)((unsigned int)(v3551 + 24) >> 2));
    int v3597;
    if (v3614) {
      int * v3561 = v3547->cache_keys;
      int * v3562 = v3547->cache_keys;
      int v3563 = v3562[0];
      v3561[1] = v3563;
      int * v3565 = v3547->cache_vals;
      int * v3566 = v3547->cache_vals;
      int v3567 = v3566[0];
      v3565[1] = v3567;
      int * v3569 = v3547->cache_keys;
      int v3622 = (int)((unsigned int)(v3551 + 24) >> 2);
      v3569[0] = v3622;
      int * v3571 = v3547->cache_vals;
      v3571[0] = v3553;
      int v3573 = v3547->timer;
      int v3625 = v3573 + 1;
      v3547->timer = v3625;
      v3597 = v3553;
    } else {
      int * v3576 = v3547->mem;
      int * v3577 = v3547->cache_keys;
      int v3578 = v3577[1];
      int * v3579 = v3547->cache_vals;
      int v3580 = v3579[1];
      v3576[v3578] = v3580;
      int * v3582 = v3547->cache_keys;
      int * v3583 = v3547->cache_keys;
      int v3584 = v3583[0];
      v3582[1] = v3584;
      int * v3586 = v3547->cache_vals;
      int * v3587 = v3547->cache_vals;
      int v3588 = v3587[0];
      v3586[1] = v3588;
      int * v3590 = v3547->cache_keys;
      int v3638 = (int)((unsigned int)(v3551 + 24) >> 2);
      v3590[0] = v3638;
      int * v3592 = v3547->cache_vals;
      v3592[0] = v3553;
      int v3594 = v3547->timer;
      int v3641 = v3594 + 100;
      v3547->timer = v3641;
      v3597 = v3553;
    }
    v3599 = v3597;
  }
  struct StateT * v3600 = slot_49(v3547);
  return v3600;
}

struct StateT * slot_77(struct StateT * v5444) {
  int v5445 = v5444->timer;
  int v5455 = v5445 + 1;
  v5444->timer = v5455;
  int * v5447 = v5444->regs;
  int v5448 = v5447[15];
  int * v5449 = v5444->regs;
  int v5450 = v5449[20];
  int * v5451 = v5444->regs;
  int v5461 = v5448 | v5450;
  v5451[15] = v5461;
  struct StateT * v5453 = slot_78(v5444);
  return v5453;
}

struct StateT * slot_85(struct StateT * v5895) {
  int v5896 = v5895->timer;
  int v5904 = v5896 + 1;
  v5895->timer = v5904;
  int * v5898 = v5895->regs;
  int v5899 = v5898[18];
  int * v5900 = v5895->regs;
  int v5908 = v5899 << 9;
  v5900[18] = v5908;
  struct StateT * v5902 = slot_86(v5895);
  return v5902;
}

struct StateT * slot_75(struct StateT * v5379) {
  int v5380 = v5379->timer;
  int v5388 = v5380 + 1;
  v5379->timer = v5388;
  int * v5382 = v5379->regs;
  int v5383 = v5382[15];
  int * v5384 = v5379->regs;
  int v5393 = (int)((unsigned int)v5383 >> 23);
  v5384[20] = v5393;
  struct StateT * v5386 = slot_76(v5379);
  return v5386;
}

struct StateT * slot_72(struct StateT * v5178) {
  int v5179 = v5178->timer;
  int v5189 = v5179 + 1;
  v5178->timer = v5189;
  int * v5181 = v5178->regs;
  int v5182 = v5181[13];
  int * v5183 = v5178->regs;
  int v5184 = v5183[11];
  int * v5185 = v5178->regs;
  int v5196 = v5182 + v5184;
  v5185[8] = v5196;
  struct StateT * v5187 = slot_73(v5178);
  return v5187;
}

struct StateT * slot_119(struct StateT * v9302) {
  int v9303 = v9302->timer;
  int v9311 = v9303 + 1;
  v9302->timer = v9311;
  int * v9305 = v9302->regs;
  int v9306 = v9305[16];
  int * v9307 = v9302->regs;
  int v9315 = v9306 << 18;
  v9307[16] = v9315;
  struct StateT * v9309 = slot_120(v9302);
  return v9309;
}

struct StateT * slot_71(struct StateT * v5137) {
  int v5138 = v5137->timer;
  int v5148 = v5138 + 1;
  v5137->timer = v5148;
  int * v5140 = v5137->regs;
  int v5141 = v5140[12];
  int * v5142 = v5137->regs;
  int v5143 = v5142[21];
  int * v5144 = v5137->regs;
  int v5155 = v5141 + v5143;
  v5144[15] = v5155;
  struct StateT * v5146 = slot_72(v5137);
  return v5146;
}

struct StateT * slot_101(struct StateT * v7782) {
  int v7783 = v7782->timer;
  int v7791 = v7783 + 1;
  v7782->timer = v7791;
  int * v7785 = v7782->regs;
  int v7786 = v7785[9];
  int * v7787 = v7782->regs;
  int v7796 = (int)((unsigned int)v7786 >> 19);
  v7787[20] = v7796;
  struct StateT * v7789 = slot_102(v7782);
  return v7789;
}

struct StateT * slot_276(struct StateT * v9206) {
  int v9207 = v9206->timer;
  int v9210 = v9207 + 1;
  v9206->timer = v9210;
  return v9206;
}

struct StateT * slot_108(struct StateT * v8645) {
  int v8646 = v8645->timer;
  int v8656 = v8646 + 1;
  v8645->timer = v8656;
  int * v8648 = v8645->regs;
  int v8649 = v8648[23];
  int * v8650 = v8645->regs;
  int v8651 = v8650[8];
  int * v8652 = v8645->regs;
  int v8662 = v8649 ^ v8651;
  v8652[23] = v8662;
  struct StateT * v8654 = slot_109(v8645);
  return v8654;
}

struct StateT * slot_116(struct StateT * v9249) {
  int v9250 = v9249->timer;
  int v9258 = v9250 + 1;
  v9249->timer = v9258;
  int * v9252 = v9249->regs;
  int v9253 = v9252[15];
  int * v9254 = v9249->regs;
  int v9262 = v9253 << 18;
  v9254[15] = v9262;
  struct StateT * v9256 = slot_117(v9249);
  return v9256;
}

struct StateT * slot_93(struct StateT * v6837) {
  int v6838 = v6837->timer;
  int v6848 = v6838 + 1;
  v6837->timer = v6848;
  int * v6840 = v6837->regs;
  int v6841 = v6840[27];
  int * v6842 = v6837->regs;
  int v6843 = v6842[1];
  int * v6844 = v6837->regs;
  int v6855 = v6841 + v6843;
  v6844[9] = v6855;
  struct StateT * v6846 = slot_94(v6837);
  return v6846;
}

struct StateT * slot_266(struct StateT * v8045) {
  int v8046 = v8045->timer;
  int v8104 = v8046 + 1;
  v8045->timer = v8104;
  int * v8048 = v8045->regs;
  int v8049 = v8048[2];
  int * v8050 = v8045->cache_keys;
  int v8051 = v8050[0];
  bool v8109 = v8051 == ((int)((unsigned int)(v8049 + 76) >> 2));
  int v8099;
  if (v8109) {
    int * v8052 = v8045->cache_vals;
    int v8053 = v8052[0];
    v8099 = v8053;
  } else {
    int * v8055 = v8045->cache_keys;
    int v8056 = v8055[1];
    bool v8114 = v8056 == ((int)((unsigned int)(v8049 + 76) >> 2));
    int v8097;
    if (v8114) {
      int * v8057 = v8045->cache_vals;
      int v8058 = v8057[1];
      int * v8059 = v8045->cache_keys;
      int * v8060 = v8045->cache_keys;
      int v8061 = v8060[0];
      v8059[1] = v8061;
      int * v8063 = v8045->cache_vals;
      int * v8064 = v8045->cache_vals;
      int v8065 = v8064[0];
      v8063[1] = v8065;
      int * v8067 = v8045->cache_keys;
      int v8123 = (int)((unsigned int)(v8049 + 76) >> 2);
      v8067[0] = v8123;
      int * v8069 = v8045->cache_vals;
      v8069[0] = v8058;
      int v8071 = v8045->timer;
      int v8126 = v8071 + 1;
      v8045->timer = v8126;
      v8097 = v8058;
    } else {
      int * v8074 = v8045->mem;
      int v8128 = (int)((unsigned int)(v8049 + 76) >> 2);
      int v8075 = v8074[v8128];
      int * v8076 = v8045->mem;
      int * v8077 = v8045->cache_keys;
      int v8078 = v8077[1];
      int * v8079 = v8045->cache_vals;
      int v8080 = v8079[1];
      v8076[v8078] = v8080;
      int * v8082 = v8045->cache_keys;
      int * v8083 = v8045->cache_keys;
      int v8084 = v8083[0];
      v8082[1] = v8084;
      int * v8086 = v8045->cache_vals;
      int * v8087 = v8045->cache_vals;
      int v8088 = v8087[0];
      v8086[1] = v8088;
      int * v8090 = v8045->cache_keys;
      v8090[0] = v8128;
      int * v8092 = v8045->cache_vals;
      v8092[0] = v8075;
      int v8094 = v8045->timer;
      int v8143 = v8094 + 100;
      v8045->timer = v8143;
      v8097 = v8075;
    }
    v8099 = v8097;
  }
  int * v8100 = v8045->regs;
  v8100[19] = v8099;
  struct StateT * v8102 = slot_267(v8045);
  return v8102;
}

struct StateT * slot_88(struct StateT * v6245) {
  int v6246 = v6245->timer;
  int v6256 = v6246 + 1;
  v6245->timer = v6256;
  int * v6248 = v6245->regs;
  int v6249 = v6248[24];
  int * v6250 = v6245->regs;
  int v6251 = v6250[8];
  int * v6252 = v6245->regs;
  int v6262 = v6249 ^ v6251;
  v6252[24] = v6262;
  struct StateT * v6254 = slot_89(v6245);
  return v6254;
}

struct StateT * slot_96(struct StateT * v7190) {
  int v7191 = v7190->timer;
  int v7199 = v7191 + 1;
  v7190->timer = v7199;
  int * v7193 = v7190->regs;
  int v7194 = v7193[15];
  int * v7195 = v7190->regs;
  int v7203 = v7194 << 13;
  v7195[15] = v7203;
  struct StateT * v7197 = slot_97(v7190);
  return v7197;
}

struct StateT * slot_215(struct StateT * v3764) {
  int v3765 = v3764->timer;
  int v3771 = v3765 + 1;
  v3764->timer = v3771;
  int * v3767 = v3764->regs;
  v3767[15] = 1634762752;
  struct StateT * v3769 = slot_216(v3764);
  return v3769;
}

struct StateT * slot_234(struct StateT * v5158) {
  int v5159 = v5158->timer;
  int v5169 = v5159 + 1;
  v5158->timer = v5169;
  int * v5161 = v5158->regs;
  int v5162 = v5161[24];
  int * v5163 = v5158->regs;
  int v5164 = v5163[30];
  int * v5165 = v5158->regs;
  int v5175 = v5162 + v5164;
  v5165[24] = v5175;
  struct StateT * v5167 = slot_235(v5158);
  return v5167;
}

struct StateT * slot_45(struct StateT * v3496) {
  int v3497 = v3496->timer;
  int v3505 = v3497 + 1;
  v3496->timer = v3505;
  int * v3499 = v3496->regs;
  int v3500 = v3499[7];
  int * v3501 = v3496->regs;
  v3501[14] = v3500;
  struct StateT * v3503 = slot_46(v3496);
  return v3503;
}

struct StateT * slot_218(struct StateT * v3961) {
  int v3962 = v3961->timer;
  int v3972 = v3962 + 1;
  v3961->timer = v3972;
  int * v3964 = v3961->regs;
  int v3965 = v3964[12];
  int * v3966 = v3961->regs;
  int v3967 = v3966[6];
  int * v3968 = v3961->regs;
  int v3978 = v3965 + v3967;
  v3968[12] = v3978;
  struct StateT * v3970 = slot_219(v3961);
  return v3970;
}

struct StateT * slot_220(struct StateT * v4030) {
  int v4031 = v4030->timer;
  int v4089 = v4031 + 1;
  v4030->timer = v4089;
  int * v4033 = v4030->regs;
  int v4034 = v4033[2];
  int * v4035 = v4030->cache_keys;
  int v4036 = v4035[0];
  bool v4094 = v4036 == ((int)((unsigned int)(v4034 + 12) >> 2));
  int v4084;
  if (v4094) {
    int * v4037 = v4030->cache_vals;
    int v4038 = v4037[0];
    v4084 = v4038;
  } else {
    int * v4040 = v4030->cache_keys;
    int v4041 = v4040[1];
    bool v4099 = v4041 == ((int)((unsigned int)(v4034 + 12) >> 2));
    int v4082;
    if (v4099) {
      int * v4042 = v4030->cache_vals;
      int v4043 = v4042[1];
      int * v4044 = v4030->cache_keys;
      int * v4045 = v4030->cache_keys;
      int v4046 = v4045[0];
      v4044[1] = v4046;
      int * v4048 = v4030->cache_vals;
      int * v4049 = v4030->cache_vals;
      int v4050 = v4049[0];
      v4048[1] = v4050;
      int * v4052 = v4030->cache_keys;
      int v4108 = (int)((unsigned int)(v4034 + 12) >> 2);
      v4052[0] = v4108;
      int * v4054 = v4030->cache_vals;
      v4054[0] = v4043;
      int v4056 = v4030->timer;
      int v4111 = v4056 + 1;
      v4030->timer = v4111;
      v4082 = v4043;
    } else {
      int * v4059 = v4030->mem;
      int v4113 = (int)((unsigned int)(v4034 + 12) >> 2);
      int v4060 = v4059[v4113];
      int * v4061 = v4030->mem;
      int * v4062 = v4030->cache_keys;
      int v4063 = v4062[1];
      int * v4064 = v4030->cache_vals;
      int v4065 = v4064[1];
      v4061[v4063] = v4065;
      int * v4067 = v4030->cache_keys;
      int * v4068 = v4030->cache_keys;
      int v4069 = v4068[0];
      v4067[1] = v4069;
      int * v4071 = v4030->cache_vals;
      int * v4072 = v4030->cache_vals;
      int v4073 = v4072[0];
      v4071[1] = v4073;
      int * v4075 = v4030->cache_keys;
      v4075[0] = v4113;
      int * v4077 = v4030->cache_vals;
      v4077[0] = v4060;
      int v4079 = v4030->timer;
      int v4128 = v4079 + 100;
      v4030->timer = v4128;
      v4082 = v4060;
    }
    v4084 = v4082;
  }
  int * v4085 = v4030->regs;
  v4085[7] = v4084;
  struct StateT * v4087 = slot_221(v4030);
  return v4087;
}

struct StateT * slot_134(struct StateT * v9588) {
  int v9589 = v9588->timer;
  int v9599 = v9589 + 1;
  v9588->timer = v9599;
  int * v9591 = v9588->regs;
  int v9592 = v9591[22];
  int * v9593 = v9588->regs;
  int v9594 = v9593[1];
  int * v9595 = v9588->regs;
  int v9606 = v9592 + v9594;
  v9595[17] = v9606;
  struct StateT * v9597 = slot_135(v9588);
  return v9597;
}

struct StateT * slot_175(struct StateT * v10365) {
  int v10366 = v10365->timer;
  int v10374 = v10366 + 1;
  v10365->timer = v10374;
  int * v10368 = v10365->regs;
  int v10369 = v10368[11];
  int * v10370 = v10365->regs;
  int v10379 = (int)((unsigned int)v10369 >> 19);
  v10370[9] = v10379;
  struct StateT * v10372 = slot_176(v10365);
  return v10372;
}

struct StateT * slot_273(struct StateT * v8917) {
  int v8918 = v8917->timer;
  int v8976 = v8918 + 1;
  v8917->timer = v8976;
  int * v8920 = v8917->regs;
  int v8921 = v8920[2];
  int * v8922 = v8917->cache_keys;
  int v8923 = v8922[0];
  bool v8981 = v8923 == ((int)((unsigned int)(v8921 + 48) >> 2));
  int v8971;
  if (v8981) {
    int * v8924 = v8917->cache_vals;
    int v8925 = v8924[0];
    v8971 = v8925;
  } else {
    int * v8927 = v8917->cache_keys;
    int v8928 = v8927[1];
    bool v8986 = v8928 == ((int)((unsigned int)(v8921 + 48) >> 2));
    int v8969;
    if (v8986) {
      int * v8929 = v8917->cache_vals;
      int v8930 = v8929[1];
      int * v8931 = v8917->cache_keys;
      int * v8932 = v8917->cache_keys;
      int v8933 = v8932[0];
      v8931[1] = v8933;
      int * v8935 = v8917->cache_vals;
      int * v8936 = v8917->cache_vals;
      int v8937 = v8936[0];
      v8935[1] = v8937;
      int * v8939 = v8917->cache_keys;
      int v8995 = (int)((unsigned int)(v8921 + 48) >> 2);
      v8939[0] = v8995;
      int * v8941 = v8917->cache_vals;
      v8941[0] = v8930;
      int v8943 = v8917->timer;
      int v8998 = v8943 + 1;
      v8917->timer = v8998;
      v8969 = v8930;
    } else {
      int * v8946 = v8917->mem;
      int v9000 = (int)((unsigned int)(v8921 + 48) >> 2);
      int v8947 = v8946[v9000];
      int * v8948 = v8917->mem;
      int * v8949 = v8917->cache_keys;
      int v8950 = v8949[1];
      int * v8951 = v8917->cache_vals;
      int v8952 = v8951[1];
      v8948[v8950] = v8952;
      int * v8954 = v8917->cache_keys;
      int * v8955 = v8917->cache_keys;
      int v8956 = v8955[0];
      v8954[1] = v8956;
      int * v8958 = v8917->cache_vals;
      int * v8959 = v8917->cache_vals;
      int v8960 = v8959[0];
      v8958[1] = v8960;
      int * v8962 = v8917->cache_keys;
      v8962[0] = v9000;
      int * v8964 = v8917->cache_vals;
      v8964[0] = v8947;
      int v8966 = v8917->timer;
      int v9015 = v8966 + 100;
      v8917->timer = v9015;
      v8969 = v8947;
    }
    v8971 = v8969;
  }
  int * v8972 = v8917->regs;
  v8972[26] = v8971;
  struct StateT * v8974 = slot_274(v8917);
  return v8974;
}

struct StateT * slot_69(struct StateT * v4972) {
  int v4973 = v4972->timer;
  int v4983 = v4973 + 1;
  v4972->timer = v4983;
  int * v4975 = v4972->regs;
  int v4976 = v4975[1];
  int * v4977 = v4972->regs;
  int v4978 = v4977[18];
  int * v4979 = v4972->regs;
  int v4989 = v4976 ^ v4978;
  v4979[1] = v4989;
  struct StateT * v4981 = slot_70(v4972);
  return v4981;
}

struct StateT * slot_202(struct StateT * v10864) {
  int v10865 = v10864->timer;
  int v10873 = v10865 + 1;
  v10864->timer = v10873;
  int * v10867 = v10864->regs;
  int v10868 = v10867[6];
  int * v10869 = v10864->regs;
  int v10877 = v10868 << 18;
  v10869[6] = v10877;
  struct StateT * v10871 = slot_203(v10864);
  return v10871;
}

struct StateT * slot_230(struct StateT * v4827) {
  int v4828 = v4827->timer;
  int v4838 = v4828 + 1;
  v4827->timer = v4838;
  int * v4830 = v4827->regs;
  int v4831 = v4830[17];
  int * v4832 = v4827->regs;
  int v4833 = v4832[30];
  int * v4834 = v4827->regs;
  int v4844 = v4831 + v4833;
  v4834[17] = v4844;
  struct StateT * v4836 = slot_231(v4827);
  return v4836;
}

struct StateT * slot_188(struct StateT * v10597) {
  int v10598 = v10597->timer;
  int v10608 = v10598 + 1;
  v10597->timer = v10608;
  int * v10600 = v10597->regs;
  int v10601 = v10600[12];
  int * v10602 = v10597->regs;
  int v10603 = v10602[15];
  int * v10604 = v10597->regs;
  int v10614 = v10601 ^ v10603;
  v10604[12] = v10614;
  struct StateT * v10606 = slot_189(v10597);
  return v10606;
}

struct StateT * slot_138(struct StateT * v9662) {
  int v9663 = v9662->timer;
  int v9671 = v9663 + 1;
  v9662->timer = v9671;
  int * v9665 = v9662->regs;
  int v9666 = v9665[11];
  int * v9667 = v9662->regs;
  int v9676 = (int)((unsigned int)v9666 >> 25);
  v9667[5] = v9676;
  struct StateT * v9669 = slot_139(v9662);
  return v9669;
}

struct StateT * slot_186(struct StateT * v10557) {
  int v10558 = v10557->timer;
  int v10568 = v10558 + 1;
  v10557->timer = v10568;
  int * v10560 = v10557->regs;
  int v10561 = v10560[8];
  int * v10562 = v10557->regs;
  int v10563 = v10562[9];
  int * v10564 = v10557->regs;
  int v10574 = v10561 | v10563;
  v10564[8] = v10574;
  struct StateT * v10566 = slot_187(v10557);
  return v10566;
}

struct StateT * slot_102(struct StateT * v7904) {
  int v7905 = v7904->timer;
  int v7913 = v7905 + 1;
  v7904->timer = v7913;
  int * v7907 = v7904->regs;
  int v7908 = v7907[9];
  int * v7909 = v7904->regs;
  int v7917 = v7908 << 13;
  v7909[9] = v7917;
  struct StateT * v7911 = slot_103(v7904);
  return v7911;
}

struct StateT * slot_145(struct StateT * v9785) {
  int v9786 = v9785->timer;
  int v9794 = v9786 + 1;
  v9785->timer = v9794;
  int * v9788 = v9785->regs;
  int v9789 = v9788[17];
  int * v9790 = v9785->regs;
  int v9798 = v9789 << 7;
  v9790[17] = v9798;
  struct StateT * v9792 = slot_146(v9785);
  return v9792;
}

struct StateT * slot_110(struct StateT * v8896) {
  int v8897 = v8896->timer;
  int v8907 = v8897 + 1;
  v8896->timer = v8907;
  int * v8899 = v8896->regs;
  int v8900 = v8899[17];
  int * v8901 = v8896->regs;
  int v8902 = v8901[6];
  int * v8903 = v8896->regs;
  int v8914 = v8900 ^ v8902;
  v8903[8] = v8914;
  struct StateT * v8905 = slot_111(v8896);
  return v8905;
}

struct StateT * slot_196(struct StateT * v10758) {
  int v10759 = v10758->timer;
  int v10767 = v10759 + 1;
  v10758->timer = v10767;
  int * v10761 = v10758->regs;
  int v10762 = v10761[11];
  int * v10763 = v10758->regs;
  int v10771 = v10762 << 18;
  v10763[11] = v10771;
  struct StateT * v10765 = slot_197(v10758);
  return v10765;
}

struct StateT * slot_208(struct StateT * v10973) {
  int v10974 = v10973->timer;
  int v10984 = v10974 + 1;
  v10973->timer = v10984;
  int * v10976 = v10973->regs;
  int v10977 = v10976[20];
  int * v10978 = v10973->regs;
  int v10979 = v10978[15];
  int * v10980 = v10973->regs;
  int v10991 = v10977 ^ v10979;
  v10980[11] = v10991;
  struct StateT * v10982 = slot_209(v10973);
  return v10982;
}

struct StateT * slot_172(struct StateT * v10302) {
  int v10303 = v10302->timer;
  int v10313 = v10303 + 1;
  v10302->timer = v10313;
  int * v10305 = v10302->regs;
  int v10306 = v10305[25];
  int * v10307 = v10302->regs;
  int v10308 = v10307[5];
  int * v10309 = v10302->regs;
  int v10320 = v10306 + v10308;
  v10309[15] = v10320;
  struct StateT * v10311 = slot_173(v10302);
  return v10311;
}

struct StateT * slot_131(struct StateT * v9525) {
  int v9526 = v9525->timer;
  int v9536 = v9526 + 1;
  v9525->timer = v9536;
  int * v9528 = v9525->regs;
  int v9529 = v9528[21];
  int * v9530 = v9525->regs;
  int v9531 = v9530[14];
  int * v9532 = v9525->regs;
  int v9543 = v9529 + v9531;
  v9532[15] = v9543;
  struct StateT * v9534 = slot_132(v9525);
  return v9534;
}

struct StateT * slot_8(struct StateT * v703) {
  int v704 = v703->timer;
  int v758 = v704 + 1;
  v703->timer = v758;
  int * v706 = v703->regs;
  int v707 = v706[2];
  int * v708 = v703->regs;
  int v709 = v708[22];
  int * v710 = v703->cache_keys;
  int v711 = v710[0];
  bool v765 = v711 == ((int)((unsigned int)(v707 + 64) >> 2));
  int v755;
  if (v765) {
    int * v712 = v703->cache_vals;
    v712[0] = v709;
    v755 = v709;
  } else {
    int * v715 = v703->cache_keys;
    int v716 = v715[1];
    bool v770 = v716 == ((int)((unsigned int)(v707 + 64) >> 2));
    int v753;
    if (v770) {
      int * v717 = v703->cache_keys;
      int * v718 = v703->cache_keys;
      int v719 = v718[0];
      v717[1] = v719;
      int * v721 = v703->cache_vals;
      int * v722 = v703->cache_vals;
      int v723 = v722[0];
      v721[1] = v723;
      int * v725 = v703->cache_keys;
      int v778 = (int)((unsigned int)(v707 + 64) >> 2);
      v725[0] = v778;
      int * v727 = v703->cache_vals;
      v727[0] = v709;
      int v729 = v703->timer;
      int v781 = v729 + 1;
      v703->timer = v781;
      v753 = v709;
    } else {
      int * v732 = v703->mem;
      int * v733 = v703->cache_keys;
      int v734 = v733[1];
      int * v735 = v703->cache_vals;
      int v736 = v735[1];
      v732[v734] = v736;
      int * v738 = v703->cache_keys;
      int * v739 = v703->cache_keys;
      int v740 = v739[0];
      v738[1] = v740;
      int * v742 = v703->cache_vals;
      int * v743 = v703->cache_vals;
      int v744 = v743[0];
      v742[1] = v744;
      int * v746 = v703->cache_keys;
      int v794 = (int)((unsigned int)(v707 + 64) >> 2);
      v746[0] = v794;
      int * v748 = v703->cache_vals;
      v748[0] = v709;
      int v750 = v703->timer;
      int v797 = v750 + 100;
      v703->timer = v797;
      v753 = v709;
    }
    v755 = v753;
  }
  struct StateT * v756 = slot_9(v703);
  return v756;
}

struct StateT * slot_180(struct StateT * v10451) {
  int v10452 = v10451->timer;
  int v10462 = v10452 + 1;
  v10451->timer = v10462;
  int * v10454 = v10451->regs;
  int v10455 = v10454[15];
  int * v10456 = v10451->regs;
  int v10457 = v10456[9];
  int * v10458 = v10451->regs;
  int v10468 = v10455 | v10457;
  v10458[15] = v10468;
  struct StateT * v10460 = slot_181(v10451);
  return v10460;
}

struct StateT * slot_203(struct StateT * v10880) {
  int v10881 = v10880->timer;
  int v10891 = v10881 + 1;
  v10880->timer = v10891;
  int * v10883 = v10880->regs;
  int v10884 = v10883[6];
  int * v10885 = v10880->regs;
  int v10886 = v10885[9];
  int * v10887 = v10880->regs;
  int v10897 = v10884 | v10886;
  v10887[6] = v10897;
  struct StateT * v10889 = slot_204(v10880);
  return v10889;
}

struct StateT * slot_190(struct StateT * v10637) {
  int v10638 = v10637->timer;
  int v10648 = v10638 + 1;
  v10637->timer = v10648;
  int * v10640 = v10637->regs;
  int v10641 = v10640[1];
  int * v10642 = v10637->regs;
  int v10643 = v10642[8];
  int * v10644 = v10637->regs;
  int v10654 = v10641 ^ v10643;
  v10644[1] = v10654;
  struct StateT * v10646 = slot_191(v10637);
  return v10646;
}

struct StateT * slot_157(struct StateT * v10022) {
  int v10023 = v10022->timer;
  int v10033 = v10023 + 1;
  v10022->timer = v10033;
  int * v10025 = v10022->regs;
  int v10026 = v10025[11];
  int * v10027 = v10022->regs;
  int v10028 = v10027[9];
  int * v10029 = v10022->regs;
  int v10039 = v10026 | v10028;
  v10029[11] = v10039;
  struct StateT * v10031 = slot_158(v10022);
  return v10031;
}

struct StateT * slot_242(struct StateT * v5529) {
  int v5530 = v5529->timer;
  int v5540 = v5530 + 1;
  v5529->timer = v5540;
  int * v5532 = v5529->regs;
  int v5533 = v5532[21];
  int * v5534 = v5529->regs;
  int v5535 = v5534[15];
  int * v5536 = v5529->regs;
  int v5546 = v5533 + v5535;
  v5536[15] = v5546;
  struct StateT * v5538 = slot_243(v5529);
  return v5538;
}

struct StateT * slot_200(struct StateT * v10827) {
  int v10828 = v10827->timer;
  int v10838 = v10828 + 1;
  v10827->timer = v10838;
  int * v10830 = v10827->regs;
  int v10831 = v10830[15];
  int * v10832 = v10827->regs;
  int v10833 = v10832[9];
  int * v10834 = v10827->regs;
  int v10844 = v10831 | v10833;
  v10834[15] = v10844;
  struct StateT * v10836 = slot_201(v10827);
  return v10836;
}

struct StateT * slot_243(struct StateT * v5569) {
  int v5570 = v5569->timer;
  int v5580 = v5570 + 1;
  v5569->timer = v5580;
  int * v5572 = v5569->regs;
  int v5573 = v5572[11];
  int * v5574 = v5569->regs;
  int v5575 = v5574[6];
  int * v5576 = v5569->regs;
  int v5586 = v5573 + v5575;
  v5576[11] = v5586;
  struct StateT * v5578 = slot_244(v5569);
  return v5578;
}

struct StateT * slot_173(struct StateT * v10323) {
  int v10324 = v10323->timer;
  int v10334 = v10324 + 1;
  v10323->timer = v10334;
  int * v10326 = v10323->regs;
  int v10327 = v10326[26];
  int * v10328 = v10323->regs;
  int v10329 = v10328[17];
  int * v10330 = v10323->regs;
  int v10341 = v10327 + v10329;
  v10330[6] = v10341;
  struct StateT * v10332 = slot_174(v10323);
  return v10332;
}

struct StateT * slot_149(struct StateT * v9863) {
  int v9864 = v9863->timer;
  int v9874 = v9864 + 1;
  v9863->timer = v9874;
  int * v9866 = v9863->regs;
  int v9867 = v9866[8];
  int * v9868 = v9863->regs;
  int v9869 = v9868[16];
  int * v9870 = v9863->regs;
  int v9881 = v9867 ^ v9869;
  v9870[17] = v9881;
  struct StateT * v9872 = slot_150(v9863);
  return v9872;
}

struct StateT * slot_5(struct StateT * v409) {
  int v410 = v409->timer;
  int v464 = v410 + 1;
  v409->timer = v464;
  int * v412 = v409->regs;
  int v413 = v412[2];
  int * v414 = v409->regs;
  int v415 = v414[19];
  int * v416 = v409->cache_keys;
  int v417 = v416[0];
  bool v471 = v417 == ((int)((unsigned int)(v413 + 76) >> 2));
  int v461;
  if (v471) {
    int * v418 = v409->cache_vals;
    v418[0] = v415;
    v461 = v415;
  } else {
    int * v421 = v409->cache_keys;
    int v422 = v421[1];
    bool v476 = v422 == ((int)((unsigned int)(v413 + 76) >> 2));
    int v459;
    if (v476) {
      int * v423 = v409->cache_keys;
      int * v424 = v409->cache_keys;
      int v425 = v424[0];
      v423[1] = v425;
      int * v427 = v409->cache_vals;
      int * v428 = v409->cache_vals;
      int v429 = v428[0];
      v427[1] = v429;
      int * v431 = v409->cache_keys;
      int v484 = (int)((unsigned int)(v413 + 76) >> 2);
      v431[0] = v484;
      int * v433 = v409->cache_vals;
      v433[0] = v415;
      int v435 = v409->timer;
      int v487 = v435 + 1;
      v409->timer = v487;
      v459 = v415;
    } else {
      int * v438 = v409->mem;
      int * v439 = v409->cache_keys;
      int v440 = v439[1];
      int * v441 = v409->cache_vals;
      int v442 = v441[1];
      v438[v440] = v442;
      int * v444 = v409->cache_keys;
      int * v445 = v409->cache_keys;
      int v446 = v445[0];
      v444[1] = v446;
      int * v448 = v409->cache_vals;
      int * v449 = v409->cache_vals;
      int v450 = v449[0];
      v448[1] = v450;
      int * v452 = v409->cache_keys;
      int v500 = (int)((unsigned int)(v413 + 76) >> 2);
      v452[0] = v500;
      int * v454 = v409->cache_vals;
      v454[0] = v415;
      int v456 = v409->timer;
      int v503 = v456 + 100;
      v409->timer = v503;
      v459 = v415;
    }
    v461 = v459;
  }
  struct StateT * v462 = slot_6(v409);
  return v462;
}

struct StateT * slot_104(struct StateT * v8150) {
  int v8151 = v8150->timer;
  int v8159 = v8151 + 1;
  v8150->timer = v8159;
  int * v8153 = v8150->regs;
  int v8154 = v8153[18];
  int * v8155 = v8150->regs;
  int v8164 = (int)((unsigned int)v8154 >> 19);
  v8155[9] = v8164;
  struct StateT * v8157 = slot_105(v8150);
  return v8157;
}

struct StateT * slot_235(struct StateT * v5199) {
  int v5200 = v5199->timer;
  int v5258 = v5200 + 1;
  v5199->timer = v5258;
  int * v5202 = v5199->regs;
  int v5203 = v5202[2];
  int * v5204 = v5199->cache_keys;
  int v5205 = v5204[0];
  bool v5263 = v5205 == ((int)((unsigned int)(v5203 + 40) >> 2));
  int v5253;
  if (v5263) {
    int * v5206 = v5199->cache_vals;
    int v5207 = v5206[0];
    v5253 = v5207;
  } else {
    int * v5209 = v5199->cache_keys;
    int v5210 = v5209[1];
    bool v5268 = v5210 == ((int)((unsigned int)(v5203 + 40) >> 2));
    int v5251;
    if (v5268) {
      int * v5211 = v5199->cache_vals;
      int v5212 = v5211[1];
      int * v5213 = v5199->cache_keys;
      int * v5214 = v5199->cache_keys;
      int v5215 = v5214[0];
      v5213[1] = v5215;
      int * v5217 = v5199->cache_vals;
      int * v5218 = v5199->cache_vals;
      int v5219 = v5218[0];
      v5217[1] = v5219;
      int * v5221 = v5199->cache_keys;
      int v5277 = (int)((unsigned int)(v5203 + 40) >> 2);
      v5221[0] = v5277;
      int * v5223 = v5199->cache_vals;
      v5223[0] = v5212;
      int v5225 = v5199->timer;
      int v5280 = v5225 + 1;
      v5199->timer = v5280;
      v5251 = v5212;
    } else {
      int * v5228 = v5199->mem;
      int v5282 = (int)((unsigned int)(v5203 + 40) >> 2);
      int v5229 = v5228[v5282];
      int * v5230 = v5199->mem;
      int * v5231 = v5199->cache_keys;
      int v5232 = v5231[1];
      int * v5233 = v5199->cache_vals;
      int v5234 = v5233[1];
      v5230[v5232] = v5234;
      int * v5236 = v5199->cache_keys;
      int * v5237 = v5199->cache_keys;
      int v5238 = v5237[0];
      v5236[1] = v5238;
      int * v5240 = v5199->cache_vals;
      int * v5241 = v5199->cache_vals;
      int v5242 = v5241[0];
      v5240[1] = v5242;
      int * v5244 = v5199->cache_keys;
      v5244[0] = v5282;
      int * v5246 = v5199->cache_vals;
      v5246[0] = v5229;
      int v5248 = v5199->timer;
      int v5297 = v5248 + 100;
      v5199->timer = v5297;
      v5251 = v5229;
    }
    v5253 = v5251;
  }
  int * v5254 = v5199->regs;
  v5254[30] = v5253;
  struct StateT * v5256 = slot_236(v5199);
  return v5256;
}

struct StateT * slot_275(struct StateT * v9169) {
  int v9170 = v9169->timer;
  int v9178 = v9170 + 1;
  v9169->timer = v9178;
  int * v9172 = v9169->regs;
  int v9173 = v9172[2];
  int * v9174 = v9169->regs;
  int v9182 = v9173 + 96;
  v9174[2] = v9182;
  struct StateT * v9176 = slot_276(v9169);
  return v9176;
}

struct StateT * slot_54(struct StateT * v3818) {
  int v3819 = v3818->timer;
  int v3829 = v3819 + 1;
  v3818->timer = v3829;
  int * v3821 = v3818->regs;
  int v3822 = v3821[22];
  int * v3823 = v3818->regs;
  int v3824 = v3823[17];
  int * v3825 = v3818->regs;
  int v3836 = v3822 + v3824;
  v3825[8] = v3836;
  struct StateT * v3827 = slot_55(v3818);
  return v3827;
}

struct StateT * slot_26(struct StateT * v2459) {
  int v2460 = v2459->timer;
  int v2518 = v2460 + 1;
  v2459->timer = v2518;
  int * v2462 = v2459->regs;
  int v2463 = v2462[11];
  int * v2464 = v2459->cache_keys;
  int v2465 = v2464[0];
  bool v2523 = v2465 == ((int)((unsigned int)(v2463 + 12) >> 2));
  int v2513;
  if (v2523) {
    int * v2466 = v2459->cache_vals;
    int v2467 = v2466[0];
    v2513 = v2467;
  } else {
    int * v2469 = v2459->cache_keys;
    int v2470 = v2469[1];
    bool v2528 = v2470 == ((int)((unsigned int)(v2463 + 12) >> 2));
    int v2511;
    if (v2528) {
      int * v2471 = v2459->cache_vals;
      int v2472 = v2471[1];
      int * v2473 = v2459->cache_keys;
      int * v2474 = v2459->cache_keys;
      int v2475 = v2474[0];
      v2473[1] = v2475;
      int * v2477 = v2459->cache_vals;
      int * v2478 = v2459->cache_vals;
      int v2479 = v2478[0];
      v2477[1] = v2479;
      int * v2481 = v2459->cache_keys;
      int v2537 = (int)((unsigned int)(v2463 + 12) >> 2);
      v2481[0] = v2537;
      int * v2483 = v2459->cache_vals;
      v2483[0] = v2472;
      int v2485 = v2459->timer;
      int v2540 = v2485 + 1;
      v2459->timer = v2540;
      v2511 = v2472;
    } else {
      int * v2488 = v2459->mem;
      int v2542 = (int)((unsigned int)(v2463 + 12) >> 2);
      int v2489 = v2488[v2542];
      int * v2490 = v2459->mem;
      int * v2491 = v2459->cache_keys;
      int v2492 = v2491[1];
      int * v2493 = v2459->cache_vals;
      int v2494 = v2493[1];
      v2490[v2492] = v2494;
      int * v2496 = v2459->cache_keys;
      int * v2497 = v2459->cache_keys;
      int v2498 = v2497[0];
      v2496[1] = v2498;
      int * v2500 = v2459->cache_vals;
      int * v2501 = v2459->cache_vals;
      int v2502 = v2501[0];
      v2500[1] = v2502;
      int * v2504 = v2459->cache_keys;
      v2504[0] = v2542;
      int * v2506 = v2459->cache_vals;
      v2506[0] = v2489;
      int v2508 = v2459->timer;
      int v2557 = v2508 + 100;
      v2459->timer = v2557;
      v2511 = v2489;
    }
    v2513 = v2511;
  }
  int * v2514 = v2459->regs;
  v2514[15] = v2513;
  struct StateT * v2516 = slot_27(v2459);
  return v2516;
}

struct StateT * slot_206(struct StateT * v10933) {
  int v10934 = v10933->timer;
  int v10944 = v10934 + 1;
  v10933->timer = v10944;
  int * v10936 = v10933->regs;
  int v10937 = v10936[8];
  int * v10938 = v10933->regs;
  int v10939 = v10938[9];
  int * v10940 = v10933->regs;
  int v10950 = v10937 | v10939;
  v10940[8] = v10950;
  struct StateT * v10942 = slot_207(v10933);
  return v10942;
}

struct StateT * slot_227(struct StateT * v4633) {
  int v4634 = v4633->timer;
  int v4644 = v4634 + 1;
  v4633->timer = v4644;
  int * v4636 = v4633->regs;
  int v4637 = v4636[13];
  int * v4638 = v4633->regs;
  int v4639 = v4638[7];
  int * v4640 = v4633->regs;
  int v4650 = v4637 + v4639;
  v4640[13] = v4650;
  struct StateT * v4642 = slot_228(v4633);
  return v4642;
}

struct StateT * slot_169(struct StateT * v10241) {
  int v10242 = v10241->timer;
  int v10252 = v10242 + 1;
  v10241->timer = v10252;
  int * v10244 = v10241->regs;
  int v10245 = v10244[26];
  int * v10246 = v10241->regs;
  int v10247 = v10246[6];
  int * v10248 = v10241->regs;
  int v10258 = v10245 ^ v10247;
  v10248[26] = v10258;
  struct StateT * v10250 = slot_170(v10241);
  return v10250;
}

struct StateT * slot_253(struct StateT * v6501) {
  int v6502 = v6501->timer;
  int v6556 = v6502 + 1;
  v6501->timer = v6556;
  int * v6504 = v6501->regs;
  int v6505 = v6504[10];
  int * v6506 = v6501->regs;
  int v6507 = v6506[25];
  int * v6508 = v6501->cache_keys;
  int v6509 = v6508[0];
  bool v6563 = v6509 == ((int)((unsigned int)(v6505 + 28) >> 2));
  int v6553;
  if (v6563) {
    int * v6510 = v6501->cache_vals;
    v6510[0] = v6507;
    v6553 = v6507;
  } else {
    int * v6513 = v6501->cache_keys;
    int v6514 = v6513[1];
    bool v6568 = v6514 == ((int)((unsigned int)(v6505 + 28) >> 2));
    int v6551;
    if (v6568) {
      int * v6515 = v6501->cache_keys;
      int * v6516 = v6501->cache_keys;
      int v6517 = v6516[0];
      v6515[1] = v6517;
      int * v6519 = v6501->cache_vals;
      int * v6520 = v6501->cache_vals;
      int v6521 = v6520[0];
      v6519[1] = v6521;
      int * v6523 = v6501->cache_keys;
      int v6576 = (int)((unsigned int)(v6505 + 28) >> 2);
      v6523[0] = v6576;
      int * v6525 = v6501->cache_vals;
      v6525[0] = v6507;
      int v6527 = v6501->timer;
      int v6579 = v6527 + 1;
      v6501->timer = v6579;
      v6551 = v6507;
    } else {
      int * v6530 = v6501->mem;
      int * v6531 = v6501->cache_keys;
      int v6532 = v6531[1];
      int * v6533 = v6501->cache_vals;
      int v6534 = v6533[1];
      v6530[v6532] = v6534;
      int * v6536 = v6501->cache_keys;
      int * v6537 = v6501->cache_keys;
      int v6538 = v6537[0];
      v6536[1] = v6538;
      int * v6540 = v6501->cache_vals;
      int * v6541 = v6501->cache_vals;
      int v6542 = v6541[0];
      v6540[1] = v6542;
      int * v6544 = v6501->cache_keys;
      int v6592 = (int)((unsigned int)(v6505 + 28) >> 2);
      v6544[0] = v6592;
      int * v6546 = v6501->cache_vals;
      v6546[0] = v6507;
      int v6548 = v6501->timer;
      int v6595 = v6548 + 100;
      v6501->timer = v6595;
      v6551 = v6507;
    }
    v6553 = v6551;
  }
  struct StateT * v6554 = slot_254(v6501);
  return v6554;
}

struct StateT * slot_64(struct StateT * v4616) {
  int v4617 = v4616->timer;
  int v4625 = v4617 + 1;
  v4616->timer = v4625;
  int * v4619 = v4616->regs;
  int v4620 = v4619[8];
  int * v4621 = v4616->regs;
  int v4630 = (int)((unsigned int)v4620 >> 25);
  v4621[20] = v4630;
  struct StateT * v4623 = slot_65(v4616);
  return v4623;
}

struct StateT * slot_170(struct StateT * v10261) {
  int v10262 = v10261->timer;
  int v10272 = v10262 + 1;
  v10261->timer = v10272;
  int * v10264 = v10261->regs;
  int v10265 = v10264[24];
  int * v10266 = v10261->regs;
  int v10267 = v10266[8];
  int * v10268 = v10261->regs;
  int v10278 = v10265 ^ v10267;
  v10268[24] = v10278;
  struct StateT * v10270 = slot_171(v10261);
  return v10270;
}

struct StateT * slot_14(struct StateT * v1291) {
  int v1292 = v1291->timer;
  int v1298 = v1292 + 1;
  v1291->timer = v1298;
  int * v1294 = v1291->regs;
  v1294[30] = 0;
  struct StateT * v1296 = slot_15(v1291);
  return v1296;
}

struct StateT * slot_53(struct StateT * v3777) {
  int v3778 = v3777->timer;
  int v3788 = v3778 + 1;
  v3777->timer = v3788;
  int * v3780 = v3777->regs;
  int v3781 = v3780[19];
  int * v3782 = v3777->regs;
  int v3783 = v3782[5];
  int * v3784 = v3777->regs;
  int v3795 = v3781 + v3783;
  v3784[18] = v3795;
  struct StateT * v3786 = slot_54(v3777);
  return v3786;
}

struct StateT * slot_80(struct StateT * v5549) {
  int v5550 = v5549->timer;
  int v5560 = v5550 + 1;
  v5549->timer = v5560;
  int * v5552 = v5549->regs;
  int v5553 = v5552[8];
  int * v5554 = v5549->regs;
  int v5555 = v5554[20];
  int * v5556 = v5549->regs;
  int v5566 = v5553 | v5555;
  v5556[8] = v5566;
  struct StateT * v5558 = slot_81(v5549);
  return v5558;
}

struct StateT * slot_44(struct StateT * v3479) {
  int v3480 = v3479->timer;
  int v3488 = v3480 + 1;
  v3479->timer = v3488;
  int * v3482 = v3479->regs;
  int v3483 = v3482[6];
  int * v3484 = v3479->regs;
  v3484[12] = v3483;
  struct StateT * v3486 = slot_45(v3479);
  return v3486;
}

struct StateT * slot_261(struct StateT * v7438) {
  int v7439 = v7438->timer;
  int v7493 = v7439 + 1;
  v7438->timer = v7493;
  int * v7441 = v7438->regs;
  int v7442 = v7441[10];
  int * v7443 = v7438->regs;
  int v7444 = v7443[30];
  int * v7445 = v7438->cache_keys;
  int v7446 = v7445[0];
  bool v7500 = v7446 == ((int)((unsigned int)(v7442 + 60) >> 2));
  int v7490;
  if (v7500) {
    int * v7447 = v7438->cache_vals;
    v7447[0] = v7444;
    v7490 = v7444;
  } else {
    int * v7450 = v7438->cache_keys;
    int v7451 = v7450[1];
    bool v7505 = v7451 == ((int)((unsigned int)(v7442 + 60) >> 2));
    int v7488;
    if (v7505) {
      int * v7452 = v7438->cache_keys;
      int * v7453 = v7438->cache_keys;
      int v7454 = v7453[0];
      v7452[1] = v7454;
      int * v7456 = v7438->cache_vals;
      int * v7457 = v7438->cache_vals;
      int v7458 = v7457[0];
      v7456[1] = v7458;
      int * v7460 = v7438->cache_keys;
      int v7513 = (int)((unsigned int)(v7442 + 60) >> 2);
      v7460[0] = v7513;
      int * v7462 = v7438->cache_vals;
      v7462[0] = v7444;
      int v7464 = v7438->timer;
      int v7516 = v7464 + 1;
      v7438->timer = v7516;
      v7488 = v7444;
    } else {
      int * v7467 = v7438->mem;
      int * v7468 = v7438->cache_keys;
      int v7469 = v7468[1];
      int * v7470 = v7438->cache_vals;
      int v7471 = v7470[1];
      v7467[v7469] = v7471;
      int * v7473 = v7438->cache_keys;
      int * v7474 = v7438->cache_keys;
      int v7475 = v7474[0];
      v7473[1] = v7475;
      int * v7477 = v7438->cache_vals;
      int * v7478 = v7438->cache_vals;
      int v7479 = v7478[0];
      v7477[1] = v7479;
      int * v7481 = v7438->cache_keys;
      int v7529 = (int)((unsigned int)(v7442 + 60) >> 2);
      v7481[0] = v7529;
      int * v7483 = v7438->cache_vals;
      v7483[0] = v7444;
      int v7485 = v7438->timer;
      int v7532 = v7485 + 100;
      v7438->timer = v7532;
      v7488 = v7444;
    }
    v7490 = v7488;
  }
  struct StateT * v7491 = slot_262(v7438);
  return v7491;
}

struct StateT * slot_137(struct StateT * v9642) {
  int v9643 = v9642->timer;
  int v9653 = v9643 + 1;
  v9642->timer = v9653;
  int * v9645 = v9642->regs;
  int v9646 = v9645[15];
  int * v9647 = v9642->regs;
  int v9648 = v9647[5];
  int * v9649 = v9642->regs;
  int v9659 = v9646 | v9648;
  v9649[15] = v9659;
  struct StateT * v9651 = slot_138(v9642);
  return v9651;
}

struct StateT * slot_122(struct StateT * v9355) {
  int v9356 = v9355->timer;
  int v9364 = v9356 + 1;
  v9355->timer = v9364;
  int * v9358 = v9355->regs;
  int v9359 = v9358[17];
  int * v9360 = v9355->regs;
  int v9368 = v9359 << 18;
  v9360[17] = v9368;
  struct StateT * v9362 = slot_123(v9355);
  return v9362;
}

struct StateT * slot_99(struct StateT * v7536) {
  int v7537 = v7536->timer;
  int v7545 = v7537 + 1;
  v7536->timer = v7545;
  int * v7539 = v7536->regs;
  int v7540 = v7539[8];
  int * v7541 = v7536->regs;
  int v7549 = v7540 << 13;
  v7541[8] = v7549;
  struct StateT * v7543 = slot_100(v7536);
  return v7543;
}

struct StateT * slot_179(struct StateT * v10435) {
  int v10436 = v10435->timer;
  int v10444 = v10436 + 1;
  v10435->timer = v10444;
  int * v10438 = v10435->regs;
  int v10439 = v10438[15];
  int * v10440 = v10435->regs;
  int v10448 = v10439 << 13;
  v10440[15] = v10448;
  struct StateT * v10442 = slot_180(v10435);
  return v10442;
}

struct StateT * slot_219(struct StateT * v3997) {
  int v3998 = v3997->timer;
  int v4004 = v3998 + 1;
  v3997->timer = v4004;
  int * v4000 = v3997->regs;
  v4000[6] = 857759744;
  struct StateT * v4002 = slot_220(v3997);
  return v4002;
}

struct StateT * slot_36(struct StateT * v2696) {
  int v2697 = v2696->timer;
  int v2751 = v2697 + 1;
  v2696->timer = v2751;
  int * v2699 = v2696->regs;
  int v2700 = v2699[2];
  int * v2701 = v2696->regs;
  int v2702 = v2701[26];
  int * v2703 = v2696->cache_keys;
  int v2704 = v2703[0];
  bool v2758 = v2704 == ((int)((unsigned int)(v2700 + 20) >> 2));
  int v2748;
  if (v2758) {
    int * v2705 = v2696->cache_vals;
    v2705[0] = v2702;
    v2748 = v2702;
  } else {
    int * v2708 = v2696->cache_keys;
    int v2709 = v2708[1];
    bool v2763 = v2709 == ((int)((unsigned int)(v2700 + 20) >> 2));
    int v2746;
    if (v2763) {
      int * v2710 = v2696->cache_keys;
      int * v2711 = v2696->cache_keys;
      int v2712 = v2711[0];
      v2710[1] = v2712;
      int * v2714 = v2696->cache_vals;
      int * v2715 = v2696->cache_vals;
      int v2716 = v2715[0];
      v2714[1] = v2716;
      int * v2718 = v2696->cache_keys;
      int v2771 = (int)((unsigned int)(v2700 + 20) >> 2);
      v2718[0] = v2771;
      int * v2720 = v2696->cache_vals;
      v2720[0] = v2702;
      int v2722 = v2696->timer;
      int v2774 = v2722 + 1;
      v2696->timer = v2774;
      v2746 = v2702;
    } else {
      int * v2725 = v2696->mem;
      int * v2726 = v2696->cache_keys;
      int v2727 = v2726[1];
      int * v2728 = v2696->cache_vals;
      int v2729 = v2728[1];
      v2725[v2727] = v2729;
      int * v2731 = v2696->cache_keys;
      int * v2732 = v2696->cache_keys;
      int v2733 = v2732[0];
      v2731[1] = v2733;
      int * v2735 = v2696->cache_vals;
      int * v2736 = v2696->cache_vals;
      int v2737 = v2736[0];
      v2735[1] = v2737;
      int * v2739 = v2696->cache_keys;
      int v2787 = (int)((unsigned int)(v2700 + 20) >> 2);
      v2739[0] = v2787;
      int * v2741 = v2696->cache_vals;
      v2741[0] = v2702;
      int v2743 = v2696->timer;
      int v2790 = v2743 + 100;
      v2696->timer = v2790;
      v2746 = v2702;
    }
    v2748 = v2746;
  }
  struct StateT * v2749 = slot_37(v2696);
  return v2749;
}

struct StateT * slot_57(struct StateT * v4010) {
  int v4011 = v4010->timer;
  int v4021 = v4011 + 1;
  v4010->timer = v4021;
  int * v4013 = v4010->regs;
  int v4014 = v4013[15];
  int * v4015 = v4010->regs;
  int v4016 = v4015[9];
  int * v4017 = v4010->regs;
  int v4027 = v4014 | v4016;
  v4017[15] = v4027;
  struct StateT * v4019 = slot_58(v4010);
  return v4019;
}

struct StateT * slot_62(struct StateT * v4455) {
  int v4456 = v4455->timer;
  int v4464 = v4456 + 1;
  v4455->timer = v4464;
  int * v4458 = v4455->regs;
  int v4459 = v4458[18];
  int * v4460 = v4455->regs;
  int v4468 = v4459 << 7;
  v4460[18] = v4468;
  struct StateT * v4462 = slot_63(v4455);
  return v4462;
}

struct StateT * slot_22(struct StateT * v2039) {
  int v2040 = v2039->timer;
  int v2098 = v2040 + 1;
  v2039->timer = v2098;
  int * v2042 = v2039->regs;
  int v2043 = v2042[12];
  int * v2044 = v2039->cache_keys;
  int v2045 = v2044[0];
  bool v2103 = v2045 == ((int)((unsigned int)(v2043 + 28) >> 2));
  int v2093;
  if (v2103) {
    int * v2046 = v2039->cache_vals;
    int v2047 = v2046[0];
    v2093 = v2047;
  } else {
    int * v2049 = v2039->cache_keys;
    int v2050 = v2049[1];
    bool v2108 = v2050 == ((int)((unsigned int)(v2043 + 28) >> 2));
    int v2091;
    if (v2108) {
      int * v2051 = v2039->cache_vals;
      int v2052 = v2051[1];
      int * v2053 = v2039->cache_keys;
      int * v2054 = v2039->cache_keys;
      int v2055 = v2054[0];
      v2053[1] = v2055;
      int * v2057 = v2039->cache_vals;
      int * v2058 = v2039->cache_vals;
      int v2059 = v2058[0];
      v2057[1] = v2059;
      int * v2061 = v2039->cache_keys;
      int v2117 = (int)((unsigned int)(v2043 + 28) >> 2);
      v2061[0] = v2117;
      int * v2063 = v2039->cache_vals;
      v2063[0] = v2052;
      int v2065 = v2039->timer;
      int v2120 = v2065 + 1;
      v2039->timer = v2120;
      v2091 = v2052;
    } else {
      int * v2068 = v2039->mem;
      int v2122 = (int)((unsigned int)(v2043 + 28) >> 2);
      int v2069 = v2068[v2122];
      int * v2070 = v2039->mem;
      int * v2071 = v2039->cache_keys;
      int v2072 = v2071[1];
      int * v2073 = v2039->cache_vals;
      int v2074 = v2073[1];
      v2070[v2072] = v2074;
      int * v2076 = v2039->cache_keys;
      int * v2077 = v2039->cache_keys;
      int v2078 = v2077[0];
      v2076[1] = v2078;
      int * v2080 = v2039->cache_vals;
      int * v2081 = v2039->cache_vals;
      int v2082 = v2081[0];
      v2080[1] = v2082;
      int * v2084 = v2039->cache_keys;
      v2084[0] = v2122;
      int * v2086 = v2039->cache_vals;
      v2086[0] = v2069;
      int v2088 = v2039->timer;
      int v2137 = v2088 + 100;
      v2039->timer = v2137;
      v2091 = v2069;
    }
    v2093 = v2091;
  }
  int * v2094 = v2039->regs;
  v2094[1] = v2093;
  struct StateT * v2096 = slot_23(v2039);
  return v2096;
}

struct StateT * slot_139(struct StateT * v9679) {
  int v9680 = v9679->timer;
  int v9688 = v9680 + 1;
  v9679->timer = v9688;
  int * v9682 = v9679->regs;
  int v9683 = v9682[11];
  int * v9684 = v9679->regs;
  int v9692 = v9683 << 7;
  v9684[11] = v9692;
  struct StateT * v9686 = slot_140(v9679);
  return v9686;
}

struct StateT * slot_221(struct StateT * v4152) {
  int v4153 = v4152->timer;
  int v4163 = v4153 + 1;
  v4152->timer = v4163;
  int * v4155 = v4152->regs;
  int v4156 = v4155[5];
  int * v4157 = v4152->regs;
  int v4158 = v4157[7];
  int * v4159 = v4152->regs;
  int v4169 = v4156 + v4158;
  v4159[5] = v4169;
  struct StateT * v4161 = slot_222(v4152);
  return v4161;
}

struct StateT * slot_23(struct StateT * v2144) {
  int v2145 = v2144->timer;
  int v2203 = v2145 + 1;
  v2144->timer = v2203;
  int * v2147 = v2144->regs;
  int v2148 = v2147[11];
  int * v2149 = v2144->cache_keys;
  int v2150 = v2149[0];
  bool v2208 = v2150 == ((int)((unsigned int)v2148 >> 2));
  int v2198;
  if (v2208) {
    int * v2151 = v2144->cache_vals;
    int v2152 = v2151[0];
    v2198 = v2152;
  } else {
    int * v2154 = v2144->cache_keys;
    int v2155 = v2154[1];
    bool v2213 = v2155 == ((int)((unsigned int)v2148 >> 2));
    int v2196;
    if (v2213) {
      int * v2156 = v2144->cache_vals;
      int v2157 = v2156[1];
      int * v2158 = v2144->cache_keys;
      int * v2159 = v2144->cache_keys;
      int v2160 = v2159[0];
      v2158[1] = v2160;
      int * v2162 = v2144->cache_vals;
      int * v2163 = v2144->cache_vals;
      int v2164 = v2163[0];
      v2162[1] = v2164;
      int * v2166 = v2144->cache_keys;
      int v2222 = (int)((unsigned int)v2148 >> 2);
      v2166[0] = v2222;
      int * v2168 = v2144->cache_vals;
      v2168[0] = v2157;
      int v2170 = v2144->timer;
      int v2225 = v2170 + 1;
      v2144->timer = v2225;
      v2196 = v2157;
    } else {
      int * v2173 = v2144->mem;
      int v2227 = (int)((unsigned int)v2148 >> 2);
      int v2174 = v2173[v2227];
      int * v2175 = v2144->mem;
      int * v2176 = v2144->cache_keys;
      int v2177 = v2176[1];
      int * v2178 = v2144->cache_vals;
      int v2179 = v2178[1];
      v2175[v2177] = v2179;
      int * v2181 = v2144->cache_keys;
      int * v2182 = v2144->cache_keys;
      int v2183 = v2182[0];
      v2181[1] = v2183;
      int * v2185 = v2144->cache_vals;
      int * v2186 = v2144->cache_vals;
      int v2187 = v2186[0];
      v2185[1] = v2187;
      int * v2189 = v2144->cache_keys;
      v2189[0] = v2227;
      int * v2191 = v2144->cache_vals;
      v2191[0] = v2174;
      int v2193 = v2144->timer;
      int v2242 = v2193 + 100;
      v2144->timer = v2242;
      v2196 = v2174;
    }
    v2198 = v2196;
  }
  int * v2199 = v2144->regs;
  v2199[5] = v2198;
  struct StateT * v2201 = slot_24(v2144);
  return v2201;
}

struct StateT * slot_153(struct StateT * v9947) {
  int v9948 = v9947->timer;
  int v9958 = v9948 + 1;
  v9947->timer = v9958;
  int * v9950 = v9947->regs;
  int v9951 = v9950[17];
  int * v9952 = v9947->regs;
  int v9953 = v9952[19];
  int * v9954 = v9947->regs;
  int v9965 = v9951 + v9953;
  v9954[6] = v9965;
  struct StateT * v9956 = slot_154(v9947);
  return v9956;
}

struct StateT * slot_2(struct StateT * v115) {
  int v116 = v115->timer;
  int v170 = v116 + 1;
  v115->timer = v170;
  int * v118 = v115->regs;
  int v119 = v118[2];
  int * v120 = v115->regs;
  int v121 = v120[8];
  int * v122 = v115->cache_keys;
  int v123 = v122[0];
  bool v177 = v123 == ((int)((unsigned int)(v119 + 88) >> 2));
  int v167;
  if (v177) {
    int * v124 = v115->cache_vals;
    v124[0] = v121;
    v167 = v121;
  } else {
    int * v127 = v115->cache_keys;
    int v128 = v127[1];
    bool v182 = v128 == ((int)((unsigned int)(v119 + 88) >> 2));
    int v165;
    if (v182) {
      int * v129 = v115->cache_keys;
      int * v130 = v115->cache_keys;
      int v131 = v130[0];
      v129[1] = v131;
      int * v133 = v115->cache_vals;
      int * v134 = v115->cache_vals;
      int v135 = v134[0];
      v133[1] = v135;
      int * v137 = v115->cache_keys;
      int v190 = (int)((unsigned int)(v119 + 88) >> 2);
      v137[0] = v190;
      int * v139 = v115->cache_vals;
      v139[0] = v121;
      int v141 = v115->timer;
      int v193 = v141 + 1;
      v115->timer = v193;
      v165 = v121;
    } else {
      int * v144 = v115->mem;
      int * v145 = v115->cache_keys;
      int v146 = v145[1];
      int * v147 = v115->cache_vals;
      int v148 = v147[1];
      v144[v146] = v148;
      int * v150 = v115->cache_keys;
      int * v151 = v115->cache_keys;
      int v152 = v151[0];
      v150[1] = v152;
      int * v154 = v115->cache_vals;
      int * v155 = v115->cache_vals;
      int v156 = v155[0];
      v154[1] = v156;
      int * v158 = v115->cache_keys;
      int v206 = (int)((unsigned int)(v119 + 88) >> 2);
      v158[0] = v206;
      int * v160 = v115->cache_vals;
      v160[0] = v121;
      int v162 = v115->timer;
      int v209 = v162 + 100;
      v115->timer = v209;
      v165 = v121;
    }
    v167 = v165;
  }
  struct StateT * v168 = slot_3(v115);
  return v168;
}

struct StateT * slot_86(struct StateT * v6009) {
  int v6010 = v6009->timer;
  int v6020 = v6010 + 1;
  v6009->timer = v6020;
  int * v6012 = v6009->regs;
  int v6013 = v6012[18];
  int * v6014 = v6009->regs;
  int v6015 = v6014[20];
  int * v6016 = v6009->regs;
  int v6026 = v6013 | v6015;
  v6016[18] = v6026;
  struct StateT * v6018 = slot_87(v6009);
  return v6018;
}

struct StateT * slot_129(struct StateT * v9485) {
  int v9486 = v9485->timer;
  int v9496 = v9486 + 1;
  v9485->timer = v9496;
  int * v9488 = v9485->regs;
  int v9489 = v9488[19];
  int * v9490 = v9485->regs;
  int v9491 = v9490[17];
  int * v9492 = v9485->regs;
  int v9502 = v9489 ^ v9491;
  v9492[19] = v9502;
  struct StateT * v9494 = slot_130(v9485);
  return v9494;
}

struct StateT * slot_158(struct StateT * v10042) {
  int v10043 = v10042->timer;
  int v10051 = v10043 + 1;
  v10042->timer = v10051;
  int * v10045 = v10042->regs;
  int v10046 = v10045[15];
  int * v10047 = v10042->regs;
  int v10056 = (int)((unsigned int)v10046 >> 23);
  v10047[9] = v10056;
  struct StateT * v10049 = slot_159(v10042);
  return v10049;
}

struct StateT * slot_100(struct StateT * v7657) {
  int v7658 = v7657->timer;
  int v7668 = v7658 + 1;
  v7657->timer = v7668;
  int * v7660 = v7657->regs;
  int v7661 = v7660[8];
  int * v7662 = v7657->regs;
  int v7663 = v7662[20];
  int * v7664 = v7657->regs;
  int v7674 = v7661 | v7663;
  v7664[8] = v7674;
  struct StateT * v7666 = slot_101(v7657);
  return v7666;
}

struct StateT * slot_271(struct StateT * v8665) {
  int v8666 = v8665->timer;
  int v8724 = v8666 + 1;
  v8665->timer = v8724;
  int * v8668 = v8665->regs;
  int v8669 = v8668[2];
  int * v8670 = v8665->cache_keys;
  int v8671 = v8670[0];
  bool v8729 = v8671 == ((int)((unsigned int)(v8669 + 56) >> 2));
  int v8719;
  if (v8729) {
    int * v8672 = v8665->cache_vals;
    int v8673 = v8672[0];
    v8719 = v8673;
  } else {
    int * v8675 = v8665->cache_keys;
    int v8676 = v8675[1];
    bool v8734 = v8676 == ((int)((unsigned int)(v8669 + 56) >> 2));
    int v8717;
    if (v8734) {
      int * v8677 = v8665->cache_vals;
      int v8678 = v8677[1];
      int * v8679 = v8665->cache_keys;
      int * v8680 = v8665->cache_keys;
      int v8681 = v8680[0];
      v8679[1] = v8681;
      int * v8683 = v8665->cache_vals;
      int * v8684 = v8665->cache_vals;
      int v8685 = v8684[0];
      v8683[1] = v8685;
      int * v8687 = v8665->cache_keys;
      int v8743 = (int)((unsigned int)(v8669 + 56) >> 2);
      v8687[0] = v8743;
      int * v8689 = v8665->cache_vals;
      v8689[0] = v8678;
      int v8691 = v8665->timer;
      int v8746 = v8691 + 1;
      v8665->timer = v8746;
      v8717 = v8678;
    } else {
      int * v8694 = v8665->mem;
      int v8748 = (int)((unsigned int)(v8669 + 56) >> 2);
      int v8695 = v8694[v8748];
      int * v8696 = v8665->mem;
      int * v8697 = v8665->cache_keys;
      int v8698 = v8697[1];
      int * v8699 = v8665->cache_vals;
      int v8700 = v8699[1];
      v8696[v8698] = v8700;
      int * v8702 = v8665->cache_keys;
      int * v8703 = v8665->cache_keys;
      int v8704 = v8703[0];
      v8702[1] = v8704;
      int * v8706 = v8665->cache_vals;
      int * v8707 = v8665->cache_vals;
      int v8708 = v8707[0];
      v8706[1] = v8708;
      int * v8710 = v8665->cache_keys;
      v8710[0] = v8748;
      int * v8712 = v8665->cache_vals;
      v8712[0] = v8695;
      int v8714 = v8665->timer;
      int v8763 = v8714 + 100;
      v8665->timer = v8763;
      v8717 = v8695;
    }
    v8719 = v8717;
  }
  int * v8720 = v8665->regs;
  v8720[24] = v8719;
  struct StateT * v8722 = slot_272(v8665);
  return v8722;
}

struct StateT * slot_127(struct StateT * v9444) {
  int v9445 = v9444->timer;
  int v9455 = v9445 + 1;
  v9444->timer = v9455;
  int * v9447 = v9444->regs;
  int v9448 = v9447[21];
  int * v9449 = v9444->regs;
  int v9450 = v9449[15];
  int * v9451 = v9444->regs;
  int v9461 = v9448 ^ v9450;
  v9451[21] = v9461;
  struct StateT * v9453 = slot_128(v9444);
  return v9453;
}

struct StateT * slot_217(struct StateT * v3839) {
  int v3840 = v3839->timer;
  int v3898 = v3840 + 1;
  v3839->timer = v3898;
  int * v3842 = v3839->regs;
  int v3843 = v3842[2];
  int * v3844 = v3839->cache_keys;
  int v3845 = v3844[0];
  bool v3903 = v3845 == ((int)((unsigned int)(v3843 + 8) >> 2));
  int v3893;
  if (v3903) {
    int * v3846 = v3839->cache_vals;
    int v3847 = v3846[0];
    v3893 = v3847;
  } else {
    int * v3849 = v3839->cache_keys;
    int v3850 = v3849[1];
    bool v3908 = v3850 == ((int)((unsigned int)(v3843 + 8) >> 2));
    int v3891;
    if (v3908) {
      int * v3851 = v3839->cache_vals;
      int v3852 = v3851[1];
      int * v3853 = v3839->cache_keys;
      int * v3854 = v3839->cache_keys;
      int v3855 = v3854[0];
      v3853[1] = v3855;
      int * v3857 = v3839->cache_vals;
      int * v3858 = v3839->cache_vals;
      int v3859 = v3858[0];
      v3857[1] = v3859;
      int * v3861 = v3839->cache_keys;
      int v3917 = (int)((unsigned int)(v3843 + 8) >> 2);
      v3861[0] = v3917;
      int * v3863 = v3839->cache_vals;
      v3863[0] = v3852;
      int v3865 = v3839->timer;
      int v3920 = v3865 + 1;
      v3839->timer = v3920;
      v3891 = v3852;
    } else {
      int * v3868 = v3839->mem;
      int v3922 = (int)((unsigned int)(v3843 + 8) >> 2);
      int v3869 = v3868[v3922];
      int * v3870 = v3839->mem;
      int * v3871 = v3839->cache_keys;
      int v3872 = v3871[1];
      int * v3873 = v3839->cache_vals;
      int v3874 = v3873[1];
      v3870[v3872] = v3874;
      int * v3876 = v3839->cache_keys;
      int * v3877 = v3839->cache_keys;
      int v3878 = v3877[0];
      v3876[1] = v3878;
      int * v3880 = v3839->cache_vals;
      int * v3881 = v3839->cache_vals;
      int v3882 = v3881[0];
      v3880[1] = v3882;
      int * v3884 = v3839->cache_keys;
      v3884[0] = v3922;
      int * v3886 = v3839->cache_vals;
      v3886[0] = v3869;
      int v3888 = v3839->timer;
      int v3937 = v3888 + 100;
      v3839->timer = v3937;
      v3891 = v3869;
    }
    v3893 = v3891;
  }
  int * v3894 = v3839->regs;
  v3894[6] = v3893;
  struct StateT * v3896 = slot_218(v3839);
  return v3896;
}

struct StateT * slot_13(struct StateT * v1193) {
  int v1194 = v1193->timer;
  int v1248 = v1194 + 1;
  v1193->timer = v1248;
  int * v1196 = v1193->regs;
  int v1197 = v1196[2];
  int * v1198 = v1193->regs;
  int v1199 = v1198[27];
  int * v1200 = v1193->cache_keys;
  int v1201 = v1200[0];
  bool v1255 = v1201 == ((int)((unsigned int)(v1197 + 44) >> 2));
  int v1245;
  if (v1255) {
    int * v1202 = v1193->cache_vals;
    v1202[0] = v1199;
    v1245 = v1199;
  } else {
    int * v1205 = v1193->cache_keys;
    int v1206 = v1205[1];
    bool v1260 = v1206 == ((int)((unsigned int)(v1197 + 44) >> 2));
    int v1243;
    if (v1260) {
      int * v1207 = v1193->cache_keys;
      int * v1208 = v1193->cache_keys;
      int v1209 = v1208[0];
      v1207[1] = v1209;
      int * v1211 = v1193->cache_vals;
      int * v1212 = v1193->cache_vals;
      int v1213 = v1212[0];
      v1211[1] = v1213;
      int * v1215 = v1193->cache_keys;
      int v1268 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1215[0] = v1268;
      int * v1217 = v1193->cache_vals;
      v1217[0] = v1199;
      int v1219 = v1193->timer;
      int v1271 = v1219 + 1;
      v1193->timer = v1271;
      v1243 = v1199;
    } else {
      int * v1222 = v1193->mem;
      int * v1223 = v1193->cache_keys;
      int v1224 = v1223[1];
      int * v1225 = v1193->cache_vals;
      int v1226 = v1225[1];
      v1222[v1224] = v1226;
      int * v1228 = v1193->cache_keys;
      int * v1229 = v1193->cache_keys;
      int v1230 = v1229[0];
      v1228[1] = v1230;
      int * v1232 = v1193->cache_vals;
      int * v1233 = v1193->cache_vals;
      int v1234 = v1233[0];
      v1232[1] = v1234;
      int * v1236 = v1193->cache_keys;
      int v1284 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1236[0] = v1284;
      int * v1238 = v1193->cache_vals;
      v1238[0] = v1199;
      int v1240 = v1193->timer;
      int v1287 = v1240 + 100;
      v1193->timer = v1287;
      v1243 = v1199;
    }
    v1245 = v1243;
  }
  struct StateT * v1246 = slot_14(v1193);
  return v1246;
}

struct StateT * slot_111(struct StateT * v9022) {
  int v9023 = v9022->timer;
  int v9033 = v9023 + 1;
  v9022->timer = v9033;
  int * v9025 = v9022->regs;
  int v9026 = v9025[9];
  int * v9027 = v9022->regs;
  int v9028 = v9027[26];
  int * v9029 = v9022->regs;
  int v9040 = v9026 + v9028;
  v9029[15] = v9040;
  struct StateT * v9031 = slot_112(v9022);
  return v9031;
}

struct StateT * slot_109(struct StateT * v8770) {
  int v8771 = v8770->timer;
  int v8781 = v8771 + 1;
  v8770->timer = v8781;
  int * v8773 = v8770->regs;
  int v8774 = v8773[5];
  int * v8775 = v8770->regs;
  int v8776 = v8775[20];
  int * v8777 = v8770->regs;
  int v8788 = v8774 ^ v8776;
  v8777[18] = v8788;
  struct StateT * v8779 = slot_110(v8770);
  return v8779;
}

struct StateT * slot_174(struct StateT * v10344) {
  int v10345 = v10344->timer;
  int v10355 = v10345 + 1;
  v10344->timer = v10355;
  int * v10347 = v10344->regs;
  int v10348 = v10347[24];
  int * v10349 = v10344->regs;
  int v10350 = v10349[16];
  int * v10351 = v10344->regs;
  int v10362 = v10348 + v10350;
  v10351[8] = v10362;
  struct StateT * v10353 = slot_175(v10344);
  return v10353;
}

struct StateT * slot_147(struct StateT * v9822) {
  int v9823 = v9822->timer;
  int v9833 = v9823 + 1;
  v9822->timer = v9833;
  int * v9825 = v9822->regs;
  int v9826 = v9825[23];
  int * v9827 = v9822->regs;
  int v9828 = v9827[15];
  int * v9829 = v9822->regs;
  int v9839 = v9826 ^ v9828;
  v9829[23] = v9839;
  struct StateT * v9831 = slot_148(v9822);
  return v9831;
}

struct StateT * slot_42(struct StateT * v3283) {
  int v3284 = v3283->timer;
  int v3338 = v3284 + 1;
  v3283->timer = v3338;
  int * v3286 = v3283->regs;
  int v3287 = v3286[2];
  int * v3288 = v3283->regs;
  int v3289 = v3288[17];
  int * v3290 = v3283->cache_keys;
  int v3291 = v3290[0];
  bool v3345 = v3291 == ((int)((unsigned int)(v3287 + 28) >> 2));
  int v3335;
  if (v3345) {
    int * v3292 = v3283->cache_vals;
    v3292[0] = v3289;
    v3335 = v3289;
  } else {
    int * v3295 = v3283->cache_keys;
    int v3296 = v3295[1];
    bool v3350 = v3296 == ((int)((unsigned int)(v3287 + 28) >> 2));
    int v3333;
    if (v3350) {
      int * v3297 = v3283->cache_keys;
      int * v3298 = v3283->cache_keys;
      int v3299 = v3298[0];
      v3297[1] = v3299;
      int * v3301 = v3283->cache_vals;
      int * v3302 = v3283->cache_vals;
      int v3303 = v3302[0];
      v3301[1] = v3303;
      int * v3305 = v3283->cache_keys;
      int v3358 = (int)((unsigned int)(v3287 + 28) >> 2);
      v3305[0] = v3358;
      int * v3307 = v3283->cache_vals;
      v3307[0] = v3289;
      int v3309 = v3283->timer;
      int v3361 = v3309 + 1;
      v3283->timer = v3361;
      v3333 = v3289;
    } else {
      int * v3312 = v3283->mem;
      int * v3313 = v3283->cache_keys;
      int v3314 = v3313[1];
      int * v3315 = v3283->cache_vals;
      int v3316 = v3315[1];
      v3312[v3314] = v3316;
      int * v3318 = v3283->cache_keys;
      int * v3319 = v3283->cache_keys;
      int v3320 = v3319[0];
      v3318[1] = v3320;
      int * v3322 = v3283->cache_vals;
      int * v3323 = v3283->cache_vals;
      int v3324 = v3323[0];
      v3322[1] = v3324;
      int * v3326 = v3283->cache_keys;
      int v3374 = (int)((unsigned int)(v3287 + 28) >> 2);
      v3326[0] = v3374;
      int * v3328 = v3283->cache_vals;
      v3328[0] = v3289;
      int v3330 = v3283->timer;
      int v3377 = v3330 + 100;
      v3283->timer = v3377;
      v3333 = v3289;
    }
    v3335 = v3333;
  }
  struct StateT * v3336 = slot_43(v3283);
  return v3336;
}

struct StateT * slot_224(struct StateT * v4350) {
  int v4351 = v4350->timer;
  int v4409 = v4351 + 1;
  v4350->timer = v4409;
  int * v4353 = v4350->regs;
  int v4354 = v4353[2];
  int * v4355 = v4350->cache_keys;
  int v4356 = v4355[0];
  bool v4414 = v4356 == ((int)((unsigned int)(v4354 + 20) >> 2));
  int v4404;
  if (v4414) {
    int * v4357 = v4350->cache_vals;
    int v4358 = v4357[0];
    v4404 = v4358;
  } else {
    int * v4360 = v4350->cache_keys;
    int v4361 = v4360[1];
    bool v4419 = v4361 == ((int)((unsigned int)(v4354 + 20) >> 2));
    int v4402;
    if (v4419) {
      int * v4362 = v4350->cache_vals;
      int v4363 = v4362[1];
      int * v4364 = v4350->cache_keys;
      int * v4365 = v4350->cache_keys;
      int v4366 = v4365[0];
      v4364[1] = v4366;
      int * v4368 = v4350->cache_vals;
      int * v4369 = v4350->cache_vals;
      int v4370 = v4369[0];
      v4368[1] = v4370;
      int * v4372 = v4350->cache_keys;
      int v4428 = (int)((unsigned int)(v4354 + 20) >> 2);
      v4372[0] = v4428;
      int * v4374 = v4350->cache_vals;
      v4374[0] = v4363;
      int v4376 = v4350->timer;
      int v4431 = v4376 + 1;
      v4350->timer = v4431;
      v4402 = v4363;
    } else {
      int * v4379 = v4350->mem;
      int v4433 = (int)((unsigned int)(v4354 + 20) >> 2);
      int v4380 = v4379[v4433];
      int * v4381 = v4350->mem;
      int * v4382 = v4350->cache_keys;
      int v4383 = v4382[1];
      int * v4384 = v4350->cache_vals;
      int v4385 = v4384[1];
      v4381[v4383] = v4385;
      int * v4387 = v4350->cache_keys;
      int * v4388 = v4350->cache_keys;
      int v4389 = v4388[0];
      v4387[1] = v4389;
      int * v4391 = v4350->cache_vals;
      int * v4392 = v4350->cache_vals;
      int v4393 = v4392[0];
      v4391[1] = v4393;
      int * v4395 = v4350->cache_keys;
      v4395[0] = v4433;
      int * v4397 = v4350->cache_vals;
      v4397[0] = v4380;
      int v4399 = v4350->timer;
      int v4448 = v4399 + 100;
      v4350->timer = v4448;
      v4402 = v4380;
    }
    v4404 = v4402;
  }
  int * v4405 = v4350->regs;
  v4405[7] = v4404;
  struct StateT * v4407 = slot_225(v4350);
  return v4407;
}

struct StateT * slot_163(struct StateT * v10128) {
  int v10129 = v10128->timer;
  int v10139 = v10129 + 1;
  v10128->timer = v10139;
  int * v10131 = v10128->regs;
  int v10132 = v10131[6];
  int * v10133 = v10128->regs;
  int v10134 = v10133[9];
  int * v10135 = v10128->regs;
  int v10145 = v10132 | v10134;
  v10135[6] = v10145;
  struct StateT * v10137 = slot_164(v10128);
  return v10137;
}

struct StateT * slot_184(struct StateT * v10524) {
  int v10525 = v10524->timer;
  int v10533 = v10525 + 1;
  v10524->timer = v10533;
  int * v10527 = v10524->regs;
  int v10528 = v10527[8];
  int * v10529 = v10524->regs;
  int v10538 = (int)((unsigned int)v10528 >> 19);
  v10529[9] = v10538;
  struct StateT * v10531 = slot_185(v10524);
  return v10531;
}

struct StateT * slot_204(struct StateT * v10900) {
  int v10901 = v10900->timer;
  int v10909 = v10901 + 1;
  v10900->timer = v10909;
  int * v10903 = v10900->regs;
  int v10904 = v10903[8];
  int * v10905 = v10900->regs;
  int v10914 = (int)((unsigned int)v10904 >> 14);
  v10905[9] = v10914;
  struct StateT * v10907 = slot_205(v10900);
  return v10907;
}

struct StateT * slot_194(struct StateT * v10720) {
  int v10721 = v10720->timer;
  int v10731 = v10721 + 1;
  v10720->timer = v10731;
  int * v10723 = v10720->regs;
  int v10724 = v10723[1];
  int * v10725 = v10720->regs;
  int v10726 = v10725[24];
  int * v10727 = v10720->regs;
  int v10738 = v10724 + v10726;
  v10727[8] = v10738;
  struct StateT * v10729 = slot_195(v10720);
  return v10729;
}

struct StateT * slot_165(struct StateT * v10165) {
  int v10166 = v10165->timer;
  int v10174 = v10166 + 1;
  v10165->timer = v10174;
  int * v10168 = v10165->regs;
  int v10169 = v10168[8];
  int * v10170 = v10165->regs;
  int v10178 = v10169 << 9;
  v10170[8] = v10178;
  struct StateT * v10172 = slot_166(v10165);
  return v10172;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v6147) {
  int v6148 = v6147->timer;
  int v6202 = v6148 + 1;
  v6147->timer = v6202;
  int * v6150 = v6147->regs;
  int v6151 = v6150[10];
  int * v6152 = v6147->regs;
  int v6153 = v6152[12];
  int * v6154 = v6147->cache_keys;
  int v6155 = v6154[0];
  bool v6209 = v6155 == ((int)((unsigned int)(v6151 + 16) >> 2));
  int v6199;
  if (v6209) {
    int * v6156 = v6147->cache_vals;
    v6156[0] = v6153;
    v6199 = v6153;
  } else {
    int * v6159 = v6147->cache_keys;
    int v6160 = v6159[1];
    bool v6214 = v6160 == ((int)((unsigned int)(v6151 + 16) >> 2));
    int v6197;
    if (v6214) {
      int * v6161 = v6147->cache_keys;
      int * v6162 = v6147->cache_keys;
      int v6163 = v6162[0];
      v6161[1] = v6163;
      int * v6165 = v6147->cache_vals;
      int * v6166 = v6147->cache_vals;
      int v6167 = v6166[0];
      v6165[1] = v6167;
      int * v6169 = v6147->cache_keys;
      int v6222 = (int)((unsigned int)(v6151 + 16) >> 2);
      v6169[0] = v6222;
      int * v6171 = v6147->cache_vals;
      v6171[0] = v6153;
      int v6173 = v6147->timer;
      int v6225 = v6173 + 1;
      v6147->timer = v6225;
      v6197 = v6153;
    } else {
      int * v6176 = v6147->mem;
      int * v6177 = v6147->cache_keys;
      int v6178 = v6177[1];
      int * v6179 = v6147->cache_vals;
      int v6180 = v6179[1];
      v6176[v6178] = v6180;
      int * v6182 = v6147->cache_keys;
      int * v6183 = v6147->cache_keys;
      int v6184 = v6183[0];
      v6182[1] = v6184;
      int * v6186 = v6147->cache_vals;
      int * v6187 = v6147->cache_vals;
      int v6188 = v6187[0];
      v6186[1] = v6188;
      int * v6190 = v6147->cache_keys;
      int v6238 = (int)((unsigned int)(v6151 + 16) >> 2);
      v6190[0] = v6238;
      int * v6192 = v6147->cache_vals;
      v6192[0] = v6153;
      int v6194 = v6147->timer;
      int v6241 = v6194 + 100;
      v6147->timer = v6241;
      v6197 = v6153;
    }
    v6199 = v6197;
  }
  struct StateT * v6200 = slot_251(v6147);
  return v6200;
}

struct StateT * slot_259(struct StateT * v7206) {
  int v7207 = v7206->timer;
  int v7261 = v7207 + 1;
  v7206->timer = v7261;
  int * v7209 = v7206->regs;
  int v7210 = v7209[10];
  int * v7211 = v7206->regs;
  int v7212 = v7211[24];
  int * v7213 = v7206->cache_keys;
  int v7214 = v7213[0];
  bool v7268 = v7214 == ((int)((unsigned int)(v7210 + 52) >> 2));
  int v7258;
  if (v7268) {
    int * v7215 = v7206->cache_vals;
    v7215[0] = v7212;
    v7258 = v7212;
  } else {
    int * v7218 = v7206->cache_keys;
    int v7219 = v7218[1];
    bool v7273 = v7219 == ((int)((unsigned int)(v7210 + 52) >> 2));
    int v7256;
    if (v7273) {
      int * v7220 = v7206->cache_keys;
      int * v7221 = v7206->cache_keys;
      int v7222 = v7221[0];
      v7220[1] = v7222;
      int * v7224 = v7206->cache_vals;
      int * v7225 = v7206->cache_vals;
      int v7226 = v7225[0];
      v7224[1] = v7226;
      int * v7228 = v7206->cache_keys;
      int v7281 = (int)((unsigned int)(v7210 + 52) >> 2);
      v7228[0] = v7281;
      int * v7230 = v7206->cache_vals;
      v7230[0] = v7212;
      int v7232 = v7206->timer;
      int v7284 = v7232 + 1;
      v7206->timer = v7284;
      v7256 = v7212;
    } else {
      int * v7235 = v7206->mem;
      int * v7236 = v7206->cache_keys;
      int v7237 = v7236[1];
      int * v7238 = v7206->cache_vals;
      int v7239 = v7238[1];
      v7235[v7237] = v7239;
      int * v7241 = v7206->cache_keys;
      int * v7242 = v7206->cache_keys;
      int v7243 = v7242[0];
      v7241[1] = v7243;
      int * v7245 = v7206->cache_vals;
      int * v7246 = v7206->cache_vals;
      int v7247 = v7246[0];
      v7245[1] = v7247;
      int * v7249 = v7206->cache_keys;
      int v7297 = (int)((unsigned int)(v7210 + 52) >> 2);
      v7249[0] = v7297;
      int * v7251 = v7206->cache_vals;
      v7251[0] = v7212;
      int v7253 = v7206->timer;
      int v7300 = v7253 + 100;
      v7206->timer = v7300;
      v7256 = v7212;
    }
    v7258 = v7256;
  }
  struct StateT * v7259 = slot_260(v7206);
  return v7259;
}

struct StateT * slot_117(struct StateT * v9265) {
  int v9266 = v9265->timer;
  int v9276 = v9266 + 1;
  v9265->timer = v9276;
  int * v9268 = v9265->regs;
  int v9269 = v9268[15];
  int * v9270 = v9265->regs;
  int v9271 = v9270[6];
  int * v9272 = v9265->regs;
  int v9282 = v9269 | v9271;
  v9272[15] = v9282;
  struct StateT * v9274 = slot_118(v9265);
  return v9274;
}

struct StateT * slot_249(struct StateT * v6029) {
  int v6030 = v6029->timer;
  int v6084 = v6030 + 1;
  v6029->timer = v6084;
  int * v6032 = v6029->regs;
  int v6033 = v6032[10];
  int * v6034 = v6029->regs;
  int v6035 = v6034[14];
  int * v6036 = v6029->cache_keys;
  int v6037 = v6036[0];
  bool v6091 = v6037 == ((int)((unsigned int)(v6033 + 12) >> 2));
  int v6081;
  if (v6091) {
    int * v6038 = v6029->cache_vals;
    v6038[0] = v6035;
    v6081 = v6035;
  } else {
    int * v6041 = v6029->cache_keys;
    int v6042 = v6041[1];
    bool v6096 = v6042 == ((int)((unsigned int)(v6033 + 12) >> 2));
    int v6079;
    if (v6096) {
      int * v6043 = v6029->cache_keys;
      int * v6044 = v6029->cache_keys;
      int v6045 = v6044[0];
      v6043[1] = v6045;
      int * v6047 = v6029->cache_vals;
      int * v6048 = v6029->cache_vals;
      int v6049 = v6048[0];
      v6047[1] = v6049;
      int * v6051 = v6029->cache_keys;
      int v6104 = (int)((unsigned int)(v6033 + 12) >> 2);
      v6051[0] = v6104;
      int * v6053 = v6029->cache_vals;
      v6053[0] = v6035;
      int v6055 = v6029->timer;
      int v6107 = v6055 + 1;
      v6029->timer = v6107;
      v6079 = v6035;
    } else {
      int * v6058 = v6029->mem;
      int * v6059 = v6029->cache_keys;
      int v6060 = v6059[1];
      int * v6061 = v6029->cache_vals;
      int v6062 = v6061[1];
      v6058[v6060] = v6062;
      int * v6064 = v6029->cache_keys;
      int * v6065 = v6029->cache_keys;
      int v6066 = v6065[0];
      v6064[1] = v6066;
      int * v6068 = v6029->cache_vals;
      int * v6069 = v6029->cache_vals;
      int v6070 = v6069[0];
      v6068[1] = v6070;
      int * v6072 = v6029->cache_keys;
      int v6120 = (int)((unsigned int)(v6033 + 12) >> 2);
      v6072[0] = v6120;
      int * v6074 = v6029->cache_vals;
      v6074[0] = v6035;
      int v6076 = v6029->timer;
      int v6123 = v6076 + 100;
      v6029->timer = v6123;
      v6079 = v6035;
    }
    v6081 = v6079;
  }
  struct StateT * v6082 = slot_250(v6029);
  return v6082;
}

struct StateT * slot_90(struct StateT * v6481) {
  int v6482 = v6481->timer;
  int v6492 = v6482 + 1;
  v6481->timer = v6492;
  int * v6484 = v6481->regs;
  int v6485 = v6484[25];
  int * v6486 = v6481->regs;
  int v6487 = v6486[18];
  int * v6488 = v6481->regs;
  int v6498 = v6485 ^ v6487;
  v6488[25] = v6498;
  struct StateT * v6490 = slot_91(v6481);
  return v6490;
}

struct StateT * slot_11(struct StateT * v997) {
  int v998 = v997->timer;
  int v1052 = v998 + 1;
  v997->timer = v1052;
  int * v1000 = v997->regs;
  int v1001 = v1000[2];
  int * v1002 = v997->regs;
  int v1003 = v1002[25];
  int * v1004 = v997->cache_keys;
  int v1005 = v1004[0];
  bool v1059 = v1005 == ((int)((unsigned int)(v1001 + 52) >> 2));
  int v1049;
  if (v1059) {
    int * v1006 = v997->cache_vals;
    v1006[0] = v1003;
    v1049 = v1003;
  } else {
    int * v1009 = v997->cache_keys;
    int v1010 = v1009[1];
    bool v1064 = v1010 == ((int)((unsigned int)(v1001 + 52) >> 2));
    int v1047;
    if (v1064) {
      int * v1011 = v997->cache_keys;
      int * v1012 = v997->cache_keys;
      int v1013 = v1012[0];
      v1011[1] = v1013;
      int * v1015 = v997->cache_vals;
      int * v1016 = v997->cache_vals;
      int v1017 = v1016[0];
      v1015[1] = v1017;
      int * v1019 = v997->cache_keys;
      int v1072 = (int)((unsigned int)(v1001 + 52) >> 2);
      v1019[0] = v1072;
      int * v1021 = v997->cache_vals;
      v1021[0] = v1003;
      int v1023 = v997->timer;
      int v1075 = v1023 + 1;
      v997->timer = v1075;
      v1047 = v1003;
    } else {
      int * v1026 = v997->mem;
      int * v1027 = v997->cache_keys;
      int v1028 = v1027[1];
      int * v1029 = v997->cache_vals;
      int v1030 = v1029[1];
      v1026[v1028] = v1030;
      int * v1032 = v997->cache_keys;
      int * v1033 = v997->cache_keys;
      int v1034 = v1033[0];
      v1032[1] = v1034;
      int * v1036 = v997->cache_vals;
      int * v1037 = v997->cache_vals;
      int v1038 = v1037[0];
      v1036[1] = v1038;
      int * v1040 = v997->cache_keys;
      int v1088 = (int)((unsigned int)(v1001 + 52) >> 2);
      v1040[0] = v1088;
      int * v1042 = v997->cache_vals;
      v1042[0] = v1003;
      int v1044 = v997->timer;
      int v1091 = v1044 + 100;
      v997->timer = v1091;
      v1047 = v1003;
    }
    v1049 = v1047;
  }
  struct StateT * v1050 = slot_12(v997);
  return v1050;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, 16 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 64;
  s2.regs[11] = 64;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = bounded(0, 20);
    s2.mem[20 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}