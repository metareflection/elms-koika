// verify: clean (KLEE should report no failing assertion) [budget 120s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v1095);
struct StateT * slot_228(struct StateT * v7306);
struct StateT * slot_143(struct StateT * v13006);
struct StateT * slot_120(struct StateT * v12576);
struct StateT * slot_226(struct StateT * v7148);
struct StateT * slot_167(struct StateT * v13459);
struct StateT * slot_268(struct StateT * v11372);
struct StateT * slot_152(struct StateT * v13184);
struct StateT * slot_231(struct StateT * v7504);
struct StateT * slot_199(struct StateT * v14069);
struct StateT * slot_252(struct StateT * v9020);
struct StateT * slot_92(struct StateT * v9355);
struct StateT * slot_232(struct StateT * v7629);
struct StateT * slot_269(struct StateT * v11598);
struct StateT * slot_31(struct StateT * v3007);
struct StateT * slot_236(struct StateT * v7962);
struct StateT * slot_241(struct StateT * v8134);
struct StateT * slot_160(struct StateT * v13333);
struct StateT * slot_251(struct StateT * v8902);
struct StateT * slot_65(struct StateT * v7290);
struct StateT * slot_10(struct StateT * v899);
struct StateT * slot_150(struct StateT * v13142);
struct StateT * slot_74(struct StateT * v7982);
struct StateT * slot_262(struct StateT * v10810);
struct StateT * slot_107(struct StateT * v12197);
struct StateT * slot_136(struct StateT * v12884);
struct StateT * slot_84(struct StateT * v8417);
struct StateT * slot_28(struct StateT * v2964);
struct StateT * slot_155(struct StateT * v13247);
struct StateT * slot_177(struct StateT * v13656);
struct StateT * slot_229(struct StateT * v7339);
struct StateT * slot_17(struct StateT * v2216);
struct StateT * slot_181(struct StateT * v13729);
struct StateT * slot_197(struct StateT * v14032);
struct StateT * slot_207(struct StateT * v14211);
struct StateT * slot_156(struct StateT * v13264);
struct StateT * slot_154(struct StateT * v13226);
struct StateT * slot_68(struct StateT * v7484);
struct StateT * slot_260(struct StateT * v9961);
struct StateT * slot_105(struct StateT * v11950);
struct StateT * slot_27(struct StateT * v2951);
struct StateT * slot_164(struct StateT * v13406);
struct StateT * slot_15(struct StateT * v1796);
struct StateT * slot_133(struct StateT * v12825);
struct StateT * slot_56(struct StateT * v6618);
struct StateT * slot_244(struct StateT * v8243);
struct StateT * slot_222(struct StateT * v6825);
struct StateT * slot_34(struct StateT * v3054);
struct StateT * slot_171(struct StateT * v13539);
struct StateT * slot_162(struct StateT * v13370);
struct StateT * slot_21(struct StateT * v2321);
struct StateT * slot_239(struct StateT * v8065);
struct StateT * slot_118(struct StateT * v12543);
struct StateT * slot_121(struct StateT * v12596);
struct StateT * slot_144(struct StateT * v13026);
struct StateT * slot_267(struct StateT * v11145);
struct StateT * slot_201(struct StateT * v14105);
struct StateT * slot_94(struct StateT * v9593);
struct StateT * slot_63(struct StateT * v7128);
struct StateT * slot_146(struct StateT * v13059);
struct StateT * slot_24(struct StateT * v2636);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v13999);
struct StateT * slot_125(struct StateT * v12666);
struct StateT * slot_254(struct StateT * v9257);
struct StateT * slot_148(struct StateT * v13100);
struct StateT * slot_126(struct StateT * v12682);
struct StateT * slot_223(struct StateT * v6950);
struct StateT * slot_79(struct StateT * v8150);
struct StateT * slot_237(struct StateT * v8003);
struct StateT * slot_41(struct StateT * v3572);
struct StateT * slot_39(struct StateT * v3377);
struct StateT * slot_142(struct StateT * v12990);
struct StateT * slot_60(struct StateT * v6930);
struct StateT * slot_238(struct StateT * v8033);
struct StateT * slot_112(struct StateT * v12427);
struct StateT * slot_256(struct StateT * v9495);
struct StateT * slot_272(struct StateT * v11966);
struct StateT * slot_214(struct StateT * v6360);
struct StateT * slot_29(struct StateT * v2977);
struct StateT * slot_16(struct StateT * v2006);
struct StateT * slot_245(struct StateT * v8279);
struct StateT * slot_113(struct StateT * v12448);
struct StateT * slot_151(struct StateT * v13163);
struct StateT * slot_7(struct StateT * v605);
struct StateT * slot_124(struct StateT * v12649);
struct StateT * slot_191(struct StateT * v13915);
struct StateT * slot_103(struct StateT * v11703);
struct StateT * slot_128(struct StateT * v12722);
struct StateT * slot_19(struct StateT * v1901);
struct StateT * slot_87(struct StateT * v8764);
struct StateT * slot_67(struct StateT * v7444);
struct StateT * slot_81(struct StateT * v8226);
struct StateT * slot_95(struct StateT * v9712);
struct StateT * slot_115(struct StateT * v12490);
struct StateT * slot_78(struct StateT * v8117);
struct StateT * slot_32(struct StateT * v3024);
struct StateT * slot_205(struct StateT * v14175);
struct StateT * slot_193(struct StateT * v13957);
struct StateT * slot_233(struct StateT * v7669);
struct StateT * slot_176(struct StateT * v13640);
struct StateT * slot_189(struct StateT * v13875);
struct StateT * slot_33(struct StateT * v3041);
struct StateT * slot_35(struct StateT * v3070);
struct StateT * slot_258(struct StateT * v9729);
struct StateT * slot_246(struct StateT * v8319);
struct StateT * slot_210(struct StateT * v14272);
struct StateT * slot_166(struct StateT * v13439);
struct StateT * slot_51(struct StateT * v6339);
struct StateT * slot_52(struct StateT * v6380);
struct StateT * slot_83(struct StateT * v8299);
struct StateT * slot_25(struct StateT * v2741);
struct StateT * slot_209(struct StateT * v14252);
struct StateT * slot_3(struct StateT * v213);
struct StateT * slot_264(struct StateT * v11267);
struct StateT * slot_123(struct StateT * v12629);
struct StateT * slot_73(struct StateT * v7941);
struct StateT * slot_270(struct StateT * v11723);
struct StateT * slot_198(struct StateT * v14052);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_187(struct StateT * v13835);
struct StateT * slot_97(struct StateT * v9941);
struct StateT * slot_182(struct StateT * v13746);
struct StateT * slot_38(struct StateT * v3279);
struct StateT * slot_178(struct StateT * v13676);
struct StateT * slot_106(struct StateT * v12071);
struct StateT * slot_98(struct StateT * v10058);
struct StateT * slot_159(struct StateT * v13317);
struct StateT * slot_212(struct StateT * v14308);
struct StateT * slot_132(struct StateT * v12804);
struct StateT * slot_130(struct StateT * v12763);
struct StateT * slot_211(struct StateT * v14292);
struct StateT * slot_20(struct StateT * v2111);
struct StateT * slot_141(struct StateT * v12973);
struct StateT * slot_61(struct StateT * v6970);
struct StateT * slot_30(struct StateT * v2990);
struct StateT * slot_4(struct StateT * v311);
struct StateT * slot_18(struct StateT * v1691);
struct StateT * slot_9(struct StateT * v801);
struct StateT * slot_183(struct StateT * v13762);
struct StateT * slot_240(struct StateT * v8101);
struct StateT * slot_247(struct StateT * v8434);
struct StateT * slot_43(struct StateT * v3768);
struct StateT * slot_70(struct StateT * v7649);
struct StateT * slot_168(struct StateT * v13479);
struct StateT * slot_76(struct StateT * v8049);
struct StateT * slot_6(struct StateT * v507);
struct StateT * slot_225(struct StateT * v7108);
struct StateT * slot_55(struct StateT * v6581);
struct StateT * slot_213(struct StateT * v6319);
struct StateT * slot_82(struct StateT * v8263);
struct StateT * slot_274(struct StateT * v12218);
struct StateT * slot_263(struct StateT * v11040);
struct StateT * slot_161(struct StateT * v13353);
struct StateT * slot_185(struct StateT * v13799);
struct StateT * slot_91(struct StateT * v9236);
struct StateT * slot_58(struct StateT * v6772);
struct StateT * slot_89(struct StateT * v9000);
struct StateT * slot_255(struct StateT * v9376);
struct StateT * slot_66(struct StateT * v7319);
struct StateT * slot_140(struct StateT * v12953);
struct StateT * slot_265(struct StateT * v11493);
struct StateT * slot_216(struct StateT * v6435);
struct StateT * slot_50(struct StateT * v4057);
struct StateT * slot_37(struct StateT * v3181);
struct StateT * slot_114(struct StateT * v12469);
struct StateT * slot_135(struct StateT * v12867);
struct StateT * slot_248(struct StateT * v8548);
struct StateT * slot_257(struct StateT * v9614);
struct StateT * slot_59(struct StateT * v6809);
struct StateT * slot_192(struct StateT * v13936);
struct StateT * slot_40(struct StateT * v3474);
struct StateT * slot_48(struct StateT * v3941);
struct StateT * slot_77(struct StateT * v8081);
struct StateT * slot_85(struct StateT * v8532);
struct StateT * slot_75(struct StateT * v8016);
struct StateT * slot_72(struct StateT * v7815);
struct StateT * slot_119(struct StateT * v12560);
struct StateT * slot_71(struct StateT * v7774);
struct StateT * slot_101(struct StateT * v11250);
struct StateT * slot_276(struct StateT * v12380);
struct StateT * slot_108(struct StateT * v12323);
struct StateT * slot_116(struct StateT * v12507);
struct StateT * slot_93(struct StateT * v9474);
struct StateT * slot_266(struct StateT * v10915);
struct StateT * slot_88(struct StateT * v8882);
struct StateT * slot_96(struct StateT * v9827);
struct StateT * slot_215(struct StateT * v6401);
struct StateT * slot_234(struct StateT * v7795);
struct StateT * slot_218(struct StateT * v6598);
struct StateT * slot_220(struct StateT * v6667);
struct StateT * slot_134(struct StateT * v12846);
struct StateT * slot_175(struct StateT * v13623);
struct StateT * slot_273(struct StateT * v12092);
struct StateT * slot_69(struct StateT * v7609);
struct StateT * slot_202(struct StateT * v14122);
struct StateT * slot_230(struct StateT * v7464);
struct StateT * slot_188(struct StateT * v13855);
struct StateT * slot_138(struct StateT * v12920);
struct StateT * slot_186(struct StateT * v13815);
struct StateT * slot_102(struct StateT * v11477);
struct StateT * slot_145(struct StateT * v13043);
struct StateT * slot_110(struct StateT * v12385);
struct StateT * slot_196(struct StateT * v14016);
struct StateT * slot_208(struct StateT * v14231);
struct StateT * slot_172(struct StateT * v13560);
struct StateT * slot_131(struct StateT * v12783);
struct StateT * slot_8(struct StateT * v703);
struct StateT * slot_180(struct StateT * v13709);
struct StateT * slot_203(struct StateT * v14138);
struct StateT * slot_190(struct StateT * v13895);
struct StateT * slot_157(struct StateT * v13280);
struct StateT * slot_242(struct StateT * v8166);
struct StateT * slot_200(struct StateT * v14085);
struct StateT * slot_243(struct StateT * v8206);
struct StateT * slot_173(struct StateT * v13581);
struct StateT * slot_149(struct StateT * v13121);
struct StateT * slot_5(struct StateT * v409);
struct StateT * slot_104(struct StateT * v11828);
struct StateT * slot_235(struct StateT * v7836);
struct StateT * slot_275(struct StateT * v12343);
struct StateT * slot_54(struct StateT * v6455);
struct StateT * slot_26(struct StateT * v2846);
struct StateT * slot_206(struct StateT * v14191);
struct StateT * slot_227(struct StateT * v7270);
struct StateT * slot_169(struct StateT * v13499);
struct StateT * slot_253(struct StateT * v9138);
struct StateT * slot_64(struct StateT * v7253);
struct StateT * slot_170(struct StateT * v13519);
struct StateT * slot_14(struct StateT * v1678);
struct StateT * slot_53(struct StateT * v6414);
struct StateT * slot_80(struct StateT * v8186);
struct StateT * slot_261(struct StateT * v10075);
struct StateT * slot_137(struct StateT * v12900);
struct StateT * slot_122(struct StateT * v12613);
struct StateT * slot_99(struct StateT * v10794);
struct StateT * slot_179(struct StateT * v13693);
struct StateT * slot_219(struct StateT * v6634);
struct StateT * slot_36(struct StateT * v3083);
struct StateT * slot_57(struct StateT * v6647);
struct StateT * slot_62(struct StateT * v7092);
struct StateT * slot_22(struct StateT * v2426);
struct StateT * slot_139(struct StateT * v12937);
struct StateT * slot_221(struct StateT * v6789);
struct StateT * slot_23(struct StateT * v2531);
struct StateT * slot_153(struct StateT * v13205);
struct StateT * slot_2(struct StateT * v115);
struct StateT * slot_86(struct StateT * v8646);
struct StateT * slot_129(struct StateT * v12743);
struct StateT * slot_158(struct StateT * v13300);
struct StateT * slot_100(struct StateT * v11020);
struct StateT * slot_271(struct StateT * v11845);
struct StateT * slot_127(struct StateT * v12702);
struct StateT * slot_217(struct StateT * v6476);
struct StateT * slot_13(struct StateT * v1193);
struct StateT * slot_111(struct StateT * v12406);
struct StateT * slot_109(struct StateT * v12359);
struct StateT * slot_174(struct StateT * v13602);
struct StateT * slot_147(struct StateT * v13080);
struct StateT * slot_42(struct StateT * v3670);
struct StateT * slot_224(struct StateT * v6987);
struct StateT * slot_163(struct StateT * v13386);
struct StateT * slot_184(struct StateT * v13782);
struct StateT * slot_204(struct StateT * v14158);
struct StateT * slot_194(struct StateT * v13978);
struct StateT * slot_165(struct StateT * v13423);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v8784);
struct StateT * slot_259(struct StateT * v9843);
struct StateT * slot_117(struct StateT * v12523);
struct StateT * slot_249(struct StateT * v8666);
struct StateT * slot_90(struct StateT * v9118);
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

struct StateT * slot_228(struct StateT * v7306) {
  int v7307 = v7306->timer;
  int v7313 = v7307 + 1;
  v7306->timer = v7313;
  int * v7309 = v7306->regs;
  v7309[7] = 2036477952;
  struct StateT * v7311 = slot_229(v7306);
  return v7311;
}

struct StateT * slot_143(struct StateT * v13006) {
  int v13007 = v13006->timer;
  int v13017 = v13007 + 1;
  v13006->timer = v13017;
  int * v13009 = v13006->regs;
  int v13010 = v13009[16];
  int * v13011 = v13006->regs;
  int v13012 = v13011[5];
  int * v13013 = v13006->regs;
  int v13023 = v13010 | v13012;
  v13013[16] = v13023;
  struct StateT * v13015 = slot_144(v13006);
  return v13015;
}

struct StateT * slot_120(struct StateT * v12576) {
  int v12577 = v12576->timer;
  int v12587 = v12577 + 1;
  v12576->timer = v12587;
  int * v12579 = v12576->regs;
  int v12580 = v12579[16];
  int * v12581 = v12576->regs;
  int v12582 = v12581[6];
  int * v12583 = v12576->regs;
  int v12593 = v12580 | v12582;
  v12583[16] = v12593;
  struct StateT * v12585 = slot_121(v12576);
  return v12585;
}

struct StateT * slot_226(struct StateT * v7148) {
  int v7149 = v7148->timer;
  int v7207 = v7149 + 1;
  v7148->timer = v7207;
  int * v7151 = v7148->regs;
  int v7152 = v7151[2];
  int * v7153 = v7148->cache_keys;
  int v7154 = v7153[0];
  bool v7212 = v7154 == ((int)((unsigned int)(v7152 + 24) >> 2));
  int v7202;
  if (v7212) {
    int * v7155 = v7148->cache_vals;
    int v7156 = v7155[0];
    v7202 = v7156;
  } else {
    int * v7158 = v7148->cache_keys;
    int v7159 = v7158[1];
    bool v7217 = v7159 == ((int)((unsigned int)(v7152 + 24) >> 2));
    int v7200;
    if (v7217) {
      int * v7160 = v7148->cache_vals;
      int v7161 = v7160[1];
      int * v7162 = v7148->cache_keys;
      int * v7163 = v7148->cache_keys;
      int v7164 = v7163[0];
      v7162[1] = v7164;
      int * v7166 = v7148->cache_vals;
      int * v7167 = v7148->cache_vals;
      int v7168 = v7167[0];
      v7166[1] = v7168;
      int * v7170 = v7148->cache_keys;
      int v7226 = (int)((unsigned int)(v7152 + 24) >> 2);
      v7170[0] = v7226;
      int * v7172 = v7148->cache_vals;
      v7172[0] = v7161;
      int v7174 = v7148->timer;
      int v7229 = v7174 + 1;
      v7148->timer = v7229;
      v7200 = v7161;
    } else {
      int * v7177 = v7148->mem;
      int v7231 = (int)((unsigned int)(v7152 + 24) >> 2);
      int v7178 = v7177[v7231];
      int * v7179 = v7148->mem;
      int * v7180 = v7148->cache_keys;
      int v7181 = v7180[1];
      int * v7182 = v7148->cache_vals;
      int v7183 = v7182[1];
      v7179[v7181] = v7183;
      int * v7185 = v7148->cache_keys;
      int * v7186 = v7148->cache_keys;
      int v7187 = v7186[0];
      v7185[1] = v7187;
      int * v7189 = v7148->cache_vals;
      int * v7190 = v7148->cache_vals;
      int v7191 = v7190[0];
      v7189[1] = v7191;
      int * v7193 = v7148->cache_keys;
      v7193[0] = v7231;
      int * v7195 = v7148->cache_vals;
      v7195[0] = v7178;
      int v7197 = v7148->timer;
      int v7246 = v7197 + 100;
      v7148->timer = v7246;
      v7200 = v7178;
    }
    v7202 = v7200;
  }
  int * v7203 = v7148->regs;
  v7203[7] = v7202;
  struct StateT * v7205 = slot_227(v7148);
  return v7205;
}

struct StateT * slot_167(struct StateT * v13459) {
  int v13460 = v13459->timer;
  int v13470 = v13460 + 1;
  v13459->timer = v13470;
  int * v13462 = v13459->regs;
  int v13463 = v13462[27];
  int * v13464 = v13459->regs;
  int v13465 = v13464[11];
  int * v13466 = v13459->regs;
  int v13476 = v13463 ^ v13465;
  v13466[27] = v13476;
  struct StateT * v13468 = slot_168(v13459);
  return v13468;
}

struct StateT * slot_268(struct StateT * v11372) {
  int v11373 = v11372->timer;
  int v11431 = v11373 + 1;
  v11372->timer = v11431;
  int * v11375 = v11372->regs;
  int v11376 = v11375[2];
  int * v11377 = v11372->cache_keys;
  int v11378 = v11377[0];
  bool v11436 = v11378 == ((int)((unsigned int)(v11376 + 68) >> 2));
  int v11426;
  if (v11436) {
    int * v11379 = v11372->cache_vals;
    int v11380 = v11379[0];
    v11426 = v11380;
  } else {
    int * v11382 = v11372->cache_keys;
    int v11383 = v11382[1];
    bool v11441 = v11383 == ((int)((unsigned int)(v11376 + 68) >> 2));
    int v11424;
    if (v11441) {
      int * v11384 = v11372->cache_vals;
      int v11385 = v11384[1];
      int * v11386 = v11372->cache_keys;
      int * v11387 = v11372->cache_keys;
      int v11388 = v11387[0];
      v11386[1] = v11388;
      int * v11390 = v11372->cache_vals;
      int * v11391 = v11372->cache_vals;
      int v11392 = v11391[0];
      v11390[1] = v11392;
      int * v11394 = v11372->cache_keys;
      int v11450 = (int)((unsigned int)(v11376 + 68) >> 2);
      v11394[0] = v11450;
      int * v11396 = v11372->cache_vals;
      v11396[0] = v11385;
      int v11398 = v11372->timer;
      int v11453 = v11398 + 1;
      v11372->timer = v11453;
      v11424 = v11385;
    } else {
      int * v11401 = v11372->mem;
      int v11455 = (int)((unsigned int)(v11376 + 68) >> 2);
      int v11402 = v11401[v11455];
      int * v11403 = v11372->mem;
      int * v11404 = v11372->cache_keys;
      int v11405 = v11404[1];
      int * v11406 = v11372->cache_vals;
      int v11407 = v11406[1];
      v11403[v11405] = v11407;
      int * v11409 = v11372->cache_keys;
      int * v11410 = v11372->cache_keys;
      int v11411 = v11410[0];
      v11409[1] = v11411;
      int * v11413 = v11372->cache_vals;
      int * v11414 = v11372->cache_vals;
      int v11415 = v11414[0];
      v11413[1] = v11415;
      int * v11417 = v11372->cache_keys;
      v11417[0] = v11455;
      int * v11419 = v11372->cache_vals;
      v11419[0] = v11402;
      int v11421 = v11372->timer;
      int v11470 = v11421 + 100;
      v11372->timer = v11470;
      v11424 = v11402;
    }
    v11426 = v11424;
  }
  int * v11427 = v11372->regs;
  v11427[21] = v11426;
  struct StateT * v11429 = slot_269(v11372);
  return v11429;
}

struct StateT * slot_152(struct StateT * v13184) {
  int v13185 = v13184->timer;
  int v13195 = v13185 + 1;
  v13184->timer = v13195;
  int * v13187 = v13184->regs;
  int v13188 = v13187[5];
  int * v13189 = v13184->regs;
  int v13190 = v13189[20];
  int * v13191 = v13184->regs;
  int v13202 = v13188 + v13190;
  v13191[15] = v13202;
  struct StateT * v13193 = slot_153(v13184);
  return v13193;
}

struct StateT * slot_231(struct StateT * v7504) {
  int v7505 = v7504->timer;
  int v7563 = v7505 + 1;
  v7504->timer = v7563;
  int * v7507 = v7504->regs;
  int v7508 = v7507[2];
  int * v7509 = v7504->cache_keys;
  int v7510 = v7509[0];
  bool v7568 = v7510 == ((int)((unsigned int)(v7508 + 32) >> 2));
  int v7558;
  if (v7568) {
    int * v7511 = v7504->cache_vals;
    int v7512 = v7511[0];
    v7558 = v7512;
  } else {
    int * v7514 = v7504->cache_keys;
    int v7515 = v7514[1];
    bool v7573 = v7515 == ((int)((unsigned int)(v7508 + 32) >> 2));
    int v7556;
    if (v7573) {
      int * v7516 = v7504->cache_vals;
      int v7517 = v7516[1];
      int * v7518 = v7504->cache_keys;
      int * v7519 = v7504->cache_keys;
      int v7520 = v7519[0];
      v7518[1] = v7520;
      int * v7522 = v7504->cache_vals;
      int * v7523 = v7504->cache_vals;
      int v7524 = v7523[0];
      v7522[1] = v7524;
      int * v7526 = v7504->cache_keys;
      int v7582 = (int)((unsigned int)(v7508 + 32) >> 2);
      v7526[0] = v7582;
      int * v7528 = v7504->cache_vals;
      v7528[0] = v7517;
      int v7530 = v7504->timer;
      int v7585 = v7530 + 1;
      v7504->timer = v7585;
      v7556 = v7517;
    } else {
      int * v7533 = v7504->mem;
      int v7587 = (int)((unsigned int)(v7508 + 32) >> 2);
      int v7534 = v7533[v7587];
      int * v7535 = v7504->mem;
      int * v7536 = v7504->cache_keys;
      int v7537 = v7536[1];
      int * v7538 = v7504->cache_vals;
      int v7539 = v7538[1];
      v7535[v7537] = v7539;
      int * v7541 = v7504->cache_keys;
      int * v7542 = v7504->cache_keys;
      int v7543 = v7542[0];
      v7541[1] = v7543;
      int * v7545 = v7504->cache_vals;
      int * v7546 = v7504->cache_vals;
      int v7547 = v7546[0];
      v7545[1] = v7547;
      int * v7549 = v7504->cache_keys;
      v7549[0] = v7587;
      int * v7551 = v7504->cache_vals;
      v7551[0] = v7534;
      int v7553 = v7504->timer;
      int v7602 = v7553 + 100;
      v7504->timer = v7602;
      v7556 = v7534;
    }
    v7558 = v7556;
  }
  int * v7559 = v7504->regs;
  v7559[30] = v7558;
  struct StateT * v7561 = slot_232(v7504);
  return v7561;
}

struct StateT * slot_199(struct StateT * v14069) {
  int v14070 = v14069->timer;
  int v14078 = v14070 + 1;
  v14069->timer = v14078;
  int * v14072 = v14069->regs;
  int v14073 = v14072[15];
  int * v14074 = v14069->regs;
  int v14082 = v14073 << 18;
  v14074[15] = v14082;
  struct StateT * v14076 = slot_200(v14069);
  return v14076;
}

struct StateT * slot_252(struct StateT * v9020) {
  int v9021 = v9020->timer;
  int v9075 = v9021 + 1;
  v9020->timer = v9075;
  int * v9023 = v9020->regs;
  int v9024 = v9023[10];
  int * v9025 = v9020->regs;
  int v9026 = v9025[5];
  int * v9027 = v9020->cache_keys;
  int v9028 = v9027[0];
  bool v9082 = v9028 == ((int)((unsigned int)(v9024 + 24) >> 2));
  int v9072;
  if (v9082) {
    int * v9029 = v9020->cache_vals;
    v9029[0] = v9026;
    v9072 = v9026;
  } else {
    int * v9032 = v9020->cache_keys;
    int v9033 = v9032[1];
    bool v9087 = v9033 == ((int)((unsigned int)(v9024 + 24) >> 2));
    int v9070;
    if (v9087) {
      int * v9034 = v9020->cache_keys;
      int * v9035 = v9020->cache_keys;
      int v9036 = v9035[0];
      v9034[1] = v9036;
      int * v9038 = v9020->cache_vals;
      int * v9039 = v9020->cache_vals;
      int v9040 = v9039[0];
      v9038[1] = v9040;
      int * v9042 = v9020->cache_keys;
      int v9095 = (int)((unsigned int)(v9024 + 24) >> 2);
      v9042[0] = v9095;
      int * v9044 = v9020->cache_vals;
      v9044[0] = v9026;
      int v9046 = v9020->timer;
      int v9098 = v9046 + 1;
      v9020->timer = v9098;
      v9070 = v9026;
    } else {
      int * v9049 = v9020->mem;
      int * v9050 = v9020->cache_keys;
      int v9051 = v9050[1];
      int * v9052 = v9020->cache_vals;
      int v9053 = v9052[1];
      v9049[v9051] = v9053;
      int * v9055 = v9020->cache_keys;
      int * v9056 = v9020->cache_keys;
      int v9057 = v9056[0];
      v9055[1] = v9057;
      int * v9059 = v9020->cache_vals;
      int * v9060 = v9020->cache_vals;
      int v9061 = v9060[0];
      v9059[1] = v9061;
      int * v9063 = v9020->cache_keys;
      int v9111 = (int)((unsigned int)(v9024 + 24) >> 2);
      v9063[0] = v9111;
      int * v9065 = v9020->cache_vals;
      v9065[0] = v9026;
      int v9067 = v9020->timer;
      int v9114 = v9067 + 100;
      v9020->timer = v9114;
      v9070 = v9026;
    }
    v9072 = v9070;
  }
  struct StateT * v9073 = slot_253(v9020);
  return v9073;
}

struct StateT * slot_92(struct StateT * v9355) {
  int v9356 = v9355->timer;
  int v9366 = v9356 + 1;
  v9355->timer = v9366;
  int * v9358 = v9355->regs;
  int v9359 = v9358[24];
  int * v9360 = v9355->regs;
  int v9361 = v9360[13];
  int * v9362 = v9355->regs;
  int v9373 = v9359 + v9361;
  v9362[8] = v9373;
  struct StateT * v9364 = slot_93(v9355);
  return v9364;
}

struct StateT * slot_232(struct StateT * v7629) {
  int v7630 = v7629->timer;
  int v7640 = v7630 + 1;
  v7629->timer = v7640;
  int * v7632 = v7629->regs;
  int v7633 = v7632[16];
  int * v7634 = v7629->regs;
  int v7635 = v7634[30];
  int * v7636 = v7629->regs;
  int v7646 = v7633 + v7635;
  v7636[16] = v7646;
  struct StateT * v7638 = slot_233(v7629);
  return v7638;
}

struct StateT * slot_269(struct StateT * v11598) {
  int v11599 = v11598->timer;
  int v11657 = v11599 + 1;
  v11598->timer = v11657;
  int * v11601 = v11598->regs;
  int v11602 = v11601[2];
  int * v11603 = v11598->cache_keys;
  int v11604 = v11603[0];
  bool v11662 = v11604 == ((int)((unsigned int)(v11602 + 64) >> 2));
  int v11652;
  if (v11662) {
    int * v11605 = v11598->cache_vals;
    int v11606 = v11605[0];
    v11652 = v11606;
  } else {
    int * v11608 = v11598->cache_keys;
    int v11609 = v11608[1];
    bool v11667 = v11609 == ((int)((unsigned int)(v11602 + 64) >> 2));
    int v11650;
    if (v11667) {
      int * v11610 = v11598->cache_vals;
      int v11611 = v11610[1];
      int * v11612 = v11598->cache_keys;
      int * v11613 = v11598->cache_keys;
      int v11614 = v11613[0];
      v11612[1] = v11614;
      int * v11616 = v11598->cache_vals;
      int * v11617 = v11598->cache_vals;
      int v11618 = v11617[0];
      v11616[1] = v11618;
      int * v11620 = v11598->cache_keys;
      int v11676 = (int)((unsigned int)(v11602 + 64) >> 2);
      v11620[0] = v11676;
      int * v11622 = v11598->cache_vals;
      v11622[0] = v11611;
      int v11624 = v11598->timer;
      int v11679 = v11624 + 1;
      v11598->timer = v11679;
      v11650 = v11611;
    } else {
      int * v11627 = v11598->mem;
      int v11681 = (int)((unsigned int)(v11602 + 64) >> 2);
      int v11628 = v11627[v11681];
      int * v11629 = v11598->mem;
      int * v11630 = v11598->cache_keys;
      int v11631 = v11630[1];
      int * v11632 = v11598->cache_vals;
      int v11633 = v11632[1];
      v11629[v11631] = v11633;
      int * v11635 = v11598->cache_keys;
      int * v11636 = v11598->cache_keys;
      int v11637 = v11636[0];
      v11635[1] = v11637;
      int * v11639 = v11598->cache_vals;
      int * v11640 = v11598->cache_vals;
      int v11641 = v11640[0];
      v11639[1] = v11641;
      int * v11643 = v11598->cache_keys;
      v11643[0] = v11681;
      int * v11645 = v11598->cache_vals;
      v11645[0] = v11628;
      int v11647 = v11598->timer;
      int v11696 = v11647 + 100;
      v11598->timer = v11696;
      v11650 = v11628;
    }
    v11652 = v11650;
  }
  int * v11653 = v11598->regs;
  v11653[22] = v11652;
  struct StateT * v11655 = slot_270(v11598);
  return v11655;
}

struct StateT * slot_31(struct StateT * v3007) {
  int v3008 = v3007->timer;
  int v3016 = v3008 + 1;
  v3007->timer = v3016;
  int * v3010 = v3007->regs;
  int v3011 = v3010[13];
  int * v3012 = v3007->regs;
  int v3021 = v3011 + 1134;
  v3012[11] = v3021;
  struct StateT * v3014 = slot_32(v3007);
  return v3014;
}

struct StateT * slot_236(struct StateT * v7962) {
  int v7963 = v7962->timer;
  int v7973 = v7963 + 1;
  v7962->timer = v7973;
  int * v7965 = v7962->regs;
  int v7966 = v7965[1];
  int * v7967 = v7962->regs;
  int v7968 = v7967[30];
  int * v7969 = v7962->regs;
  int v7979 = v7966 + v7968;
  v7969[1] = v7979;
  struct StateT * v7971 = slot_237(v7962);
  return v7971;
}

struct StateT * slot_241(struct StateT * v8134) {
  int v8135 = v8134->timer;
  int v8143 = v8135 + 1;
  v8134->timer = v8143;
  int * v8137 = v8134->regs;
  int v8138 = v8137[30];
  int * v8139 = v8134->regs;
  int v8147 = v8138 + 1396;
  v8139[30] = v8147;
  struct StateT * v8141 = slot_242(v8134);
  return v8141;
}

struct StateT * slot_160(struct StateT * v13333) {
  int v13334 = v13333->timer;
  int v13344 = v13334 + 1;
  v13333->timer = v13344;
  int * v13336 = v13333->regs;
  int v13337 = v13336[15];
  int * v13338 = v13333->regs;
  int v13339 = v13338[9];
  int * v13340 = v13333->regs;
  int v13350 = v13337 | v13339;
  v13340[15] = v13350;
  struct StateT * v13342 = slot_161(v13333);
  return v13342;
}

struct StateT * slot_251(struct StateT * v8902) {
  int v8903 = v8902->timer;
  int v8957 = v8903 + 1;
  v8902->timer = v8957;
  int * v8905 = v8902->regs;
  int v8906 = v8905[10];
  int * v8907 = v8902->regs;
  int v8908 = v8907[11];
  int * v8909 = v8902->cache_keys;
  int v8910 = v8909[0];
  bool v8964 = v8910 == ((int)((unsigned int)(v8906 + 20) >> 2));
  int v8954;
  if (v8964) {
    int * v8911 = v8902->cache_vals;
    v8911[0] = v8908;
    v8954 = v8908;
  } else {
    int * v8914 = v8902->cache_keys;
    int v8915 = v8914[1];
    bool v8969 = v8915 == ((int)((unsigned int)(v8906 + 20) >> 2));
    int v8952;
    if (v8969) {
      int * v8916 = v8902->cache_keys;
      int * v8917 = v8902->cache_keys;
      int v8918 = v8917[0];
      v8916[1] = v8918;
      int * v8920 = v8902->cache_vals;
      int * v8921 = v8902->cache_vals;
      int v8922 = v8921[0];
      v8920[1] = v8922;
      int * v8924 = v8902->cache_keys;
      int v8977 = (int)((unsigned int)(v8906 + 20) >> 2);
      v8924[0] = v8977;
      int * v8926 = v8902->cache_vals;
      v8926[0] = v8908;
      int v8928 = v8902->timer;
      int v8980 = v8928 + 1;
      v8902->timer = v8980;
      v8952 = v8908;
    } else {
      int * v8931 = v8902->mem;
      int * v8932 = v8902->cache_keys;
      int v8933 = v8932[1];
      int * v8934 = v8902->cache_vals;
      int v8935 = v8934[1];
      v8931[v8933] = v8935;
      int * v8937 = v8902->cache_keys;
      int * v8938 = v8902->cache_keys;
      int v8939 = v8938[0];
      v8937[1] = v8939;
      int * v8941 = v8902->cache_vals;
      int * v8942 = v8902->cache_vals;
      int v8943 = v8942[0];
      v8941[1] = v8943;
      int * v8945 = v8902->cache_keys;
      int v8993 = (int)((unsigned int)(v8906 + 20) >> 2);
      v8945[0] = v8993;
      int * v8947 = v8902->cache_vals;
      v8947[0] = v8908;
      int v8949 = v8902->timer;
      int v8996 = v8949 + 100;
      v8902->timer = v8996;
      v8952 = v8908;
    }
    v8954 = v8952;
  }
  struct StateT * v8955 = slot_252(v8902);
  return v8955;
}

struct StateT * slot_65(struct StateT * v7290) {
  int v7291 = v7290->timer;
  int v7299 = v7291 + 1;
  v7290->timer = v7299;
  int * v7293 = v7290->regs;
  int v7294 = v7293[8];
  int * v7295 = v7290->regs;
  int v7303 = v7294 << 7;
  v7295[8] = v7303;
  struct StateT * v7297 = slot_66(v7290);
  return v7297;
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

struct StateT * slot_150(struct StateT * v13142) {
  int v13143 = v13142->timer;
  int v13153 = v13143 + 1;
  v13142->timer = v13153;
  int * v13145 = v13142->regs;
  int v13146 = v13145[9];
  int * v13147 = v13142->regs;
  int v13148 = v13147[6];
  int * v13149 = v13142->regs;
  int v13160 = v13146 ^ v13148;
  v13149[16] = v13160;
  struct StateT * v13151 = slot_151(v13142);
  return v13151;
}

struct StateT * slot_74(struct StateT * v7982) {
  int v7983 = v7982->timer;
  int v7993 = v7983 + 1;
  v7982->timer = v7993;
  int * v7985 = v7982->regs;
  int v7986 = v7985[14];
  int * v7987 = v7982->regs;
  int v7988 = v7987[22];
  int * v7989 = v7982->regs;
  int v8000 = v7986 + v7988;
  v7989[18] = v8000;
  struct StateT * v7991 = slot_75(v7982);
  return v7991;
}

struct StateT * slot_262(struct StateT * v10810) {
  int v10811 = v10810->timer;
  int v10869 = v10811 + 1;
  v10810->timer = v10869;
  int * v10813 = v10810->regs;
  int v10814 = v10813[2];
  int * v10815 = v10810->cache_keys;
  int v10816 = v10815[0];
  bool v10874 = v10816 == ((int)((unsigned int)(v10814 + 92) >> 2));
  int v10864;
  if (v10874) {
    int * v10817 = v10810->cache_vals;
    int v10818 = v10817[0];
    v10864 = v10818;
  } else {
    int * v10820 = v10810->cache_keys;
    int v10821 = v10820[1];
    bool v10879 = v10821 == ((int)((unsigned int)(v10814 + 92) >> 2));
    int v10862;
    if (v10879) {
      int * v10822 = v10810->cache_vals;
      int v10823 = v10822[1];
      int * v10824 = v10810->cache_keys;
      int * v10825 = v10810->cache_keys;
      int v10826 = v10825[0];
      v10824[1] = v10826;
      int * v10828 = v10810->cache_vals;
      int * v10829 = v10810->cache_vals;
      int v10830 = v10829[0];
      v10828[1] = v10830;
      int * v10832 = v10810->cache_keys;
      int v10888 = (int)((unsigned int)(v10814 + 92) >> 2);
      v10832[0] = v10888;
      int * v10834 = v10810->cache_vals;
      v10834[0] = v10823;
      int v10836 = v10810->timer;
      int v10891 = v10836 + 1;
      v10810->timer = v10891;
      v10862 = v10823;
    } else {
      int * v10839 = v10810->mem;
      int v10893 = (int)((unsigned int)(v10814 + 92) >> 2);
      int v10840 = v10839[v10893];
      int * v10841 = v10810->mem;
      int * v10842 = v10810->cache_keys;
      int v10843 = v10842[1];
      int * v10844 = v10810->cache_vals;
      int v10845 = v10844[1];
      v10841[v10843] = v10845;
      int * v10847 = v10810->cache_keys;
      int * v10848 = v10810->cache_keys;
      int v10849 = v10848[0];
      v10847[1] = v10849;
      int * v10851 = v10810->cache_vals;
      int * v10852 = v10810->cache_vals;
      int v10853 = v10852[0];
      v10851[1] = v10853;
      int * v10855 = v10810->cache_keys;
      v10855[0] = v10893;
      int * v10857 = v10810->cache_vals;
      v10857[0] = v10840;
      int v10859 = v10810->timer;
      int v10908 = v10859 + 100;
      v10810->timer = v10908;
      v10862 = v10840;
    }
    v10864 = v10862;
  }
  int * v10865 = v10810->regs;
  v10865[1] = v10864;
  struct StateT * v10867 = slot_263(v10810);
  return v10867;
}

struct StateT * slot_107(struct StateT * v12197) {
  int v12198 = v12197->timer;
  int v12208 = v12198 + 1;
  v12197->timer = v12208;
  int * v12200 = v12197->regs;
  int v12201 = v12200[16];
  int * v12202 = v12197->regs;
  int v12203 = v12202[15];
  int * v12204 = v12197->regs;
  int v12215 = v12201 ^ v12203;
  v12204[9] = v12215;
  struct StateT * v12206 = slot_108(v12197);
  return v12206;
}

struct StateT * slot_136(struct StateT * v12884) {
  int v12885 = v12884->timer;
  int v12893 = v12885 + 1;
  v12884->timer = v12893;
  int * v12887 = v12884->regs;
  int v12888 = v12887[15];
  int * v12889 = v12884->regs;
  int v12897 = v12888 << 7;
  v12889[15] = v12897;
  struct StateT * v12891 = slot_137(v12884);
  return v12891;
}

struct StateT * slot_84(struct StateT * v8417) {
  int v8418 = v8417->timer;
  int v8426 = v8418 + 1;
  v8417->timer = v8426;
  int * v8420 = v8417->regs;
  int v8421 = v8420[18];
  int * v8422 = v8417->regs;
  int v8431 = (int)((unsigned int)v8421 >> 23);
  v8422[20] = v8431;
  struct StateT * v8424 = slot_85(v8417);
  return v8424;
}

struct StateT * slot_28(struct StateT * v2964) {
  int v2965 = v2964->timer;
  int v2971 = v2965 + 1;
  v2964->timer = v2971;
  int * v2967 = v2964->regs;
  v2967[13] = 857759744;
  struct StateT * v2969 = slot_29(v2964);
  return v2969;
}

struct StateT * slot_155(struct StateT * v13247) {
  int v13248 = v13247->timer;
  int v13256 = v13248 + 1;
  v13247->timer = v13256;
  int * v13250 = v13247->regs;
  int v13251 = v13250[11];
  int * v13252 = v13247->regs;
  int v13261 = (int)((unsigned int)v13251 >> 23);
  v13252[9] = v13261;
  struct StateT * v13254 = slot_156(v13247);
  return v13254;
}

struct StateT * slot_177(struct StateT * v13656) {
  int v13657 = v13656->timer;
  int v13667 = v13657 + 1;
  v13656->timer = v13667;
  int * v13659 = v13656->regs;
  int v13660 = v13659[11];
  int * v13661 = v13656->regs;
  int v13662 = v13661[9];
  int * v13663 = v13656->regs;
  int v13673 = v13660 | v13662;
  v13663[11] = v13673;
  struct StateT * v13665 = slot_178(v13656);
  return v13665;
}

struct StateT * slot_229(struct StateT * v7339) {
  int v7340 = v7339->timer;
  int v7398 = v7340 + 1;
  v7339->timer = v7398;
  int * v7342 = v7339->regs;
  int v7343 = v7342[2];
  int * v7344 = v7339->cache_keys;
  int v7345 = v7344[0];
  bool v7403 = v7345 == ((int)((unsigned int)(v7343 + 28) >> 2));
  int v7393;
  if (v7403) {
    int * v7346 = v7339->cache_vals;
    int v7347 = v7346[0];
    v7393 = v7347;
  } else {
    int * v7349 = v7339->cache_keys;
    int v7350 = v7349[1];
    bool v7408 = v7350 == ((int)((unsigned int)(v7343 + 28) >> 2));
    int v7391;
    if (v7408) {
      int * v7351 = v7339->cache_vals;
      int v7352 = v7351[1];
      int * v7353 = v7339->cache_keys;
      int * v7354 = v7339->cache_keys;
      int v7355 = v7354[0];
      v7353[1] = v7355;
      int * v7357 = v7339->cache_vals;
      int * v7358 = v7339->cache_vals;
      int v7359 = v7358[0];
      v7357[1] = v7359;
      int * v7361 = v7339->cache_keys;
      int v7417 = (int)((unsigned int)(v7343 + 28) >> 2);
      v7361[0] = v7417;
      int * v7363 = v7339->cache_vals;
      v7363[0] = v7352;
      int v7365 = v7339->timer;
      int v7420 = v7365 + 1;
      v7339->timer = v7420;
      v7391 = v7352;
    } else {
      int * v7368 = v7339->mem;
      int v7422 = (int)((unsigned int)(v7343 + 28) >> 2);
      int v7369 = v7368[v7422];
      int * v7370 = v7339->mem;
      int * v7371 = v7339->cache_keys;
      int v7372 = v7371[1];
      int * v7373 = v7339->cache_vals;
      int v7374 = v7373[1];
      v7370[v7372] = v7374;
      int * v7376 = v7339->cache_keys;
      int * v7377 = v7339->cache_keys;
      int v7378 = v7377[0];
      v7376[1] = v7378;
      int * v7380 = v7339->cache_vals;
      int * v7381 = v7339->cache_vals;
      int v7382 = v7381[0];
      v7380[1] = v7382;
      int * v7384 = v7339->cache_keys;
      v7384[0] = v7422;
      int * v7386 = v7339->cache_vals;
      v7386[0] = v7369;
      int v7388 = v7339->timer;
      int v7437 = v7388 + 100;
      v7339->timer = v7437;
      v7391 = v7369;
    }
    v7393 = v7391;
  }
  int * v7394 = v7339->regs;
  v7394[30] = v7393;
  struct StateT * v7396 = slot_230(v7339);
  return v7396;
}

struct StateT * slot_17(struct StateT * v2216) {
  int v2217 = v2216->timer;
  int v2275 = v2217 + 1;
  v2216->timer = v2275;
  int * v2219 = v2216->regs;
  int v2220 = v2219[12];
  int * v2221 = v2216->cache_keys;
  int v2222 = v2221[0];
  bool v2280 = v2222 == ((int)((unsigned int)(v2220 + 8) >> 2));
  int v2270;
  if (v2280) {
    int * v2223 = v2216->cache_vals;
    int v2224 = v2223[0];
    v2270 = v2224;
  } else {
    int * v2226 = v2216->cache_keys;
    int v2227 = v2226[1];
    bool v2285 = v2227 == ((int)((unsigned int)(v2220 + 8) >> 2));
    int v2268;
    if (v2285) {
      int * v2228 = v2216->cache_vals;
      int v2229 = v2228[1];
      int * v2230 = v2216->cache_keys;
      int * v2231 = v2216->cache_keys;
      int v2232 = v2231[0];
      v2230[1] = v2232;
      int * v2234 = v2216->cache_vals;
      int * v2235 = v2216->cache_vals;
      int v2236 = v2235[0];
      v2234[1] = v2236;
      int * v2238 = v2216->cache_keys;
      int v2294 = (int)((unsigned int)(v2220 + 8) >> 2);
      v2238[0] = v2294;
      int * v2240 = v2216->cache_vals;
      v2240[0] = v2229;
      int v2242 = v2216->timer;
      int v2297 = v2242 + 1;
      v2216->timer = v2297;
      v2268 = v2229;
    } else {
      int * v2245 = v2216->mem;
      int v2299 = (int)((unsigned int)(v2220 + 8) >> 2);
      int v2246 = v2245[v2299];
      int * v2247 = v2216->mem;
      int * v2248 = v2216->cache_keys;
      int v2249 = v2248[1];
      int * v2250 = v2216->cache_vals;
      int v2251 = v2250[1];
      v2247[v2249] = v2251;
      int * v2253 = v2216->cache_keys;
      int * v2254 = v2216->cache_keys;
      int v2255 = v2254[0];
      v2253[1] = v2255;
      int * v2257 = v2216->cache_vals;
      int * v2258 = v2216->cache_vals;
      int v2259 = v2258[0];
      v2257[1] = v2259;
      int * v2261 = v2216->cache_keys;
      v2261[0] = v2299;
      int * v2263 = v2216->cache_vals;
      v2263[0] = v2246;
      int v2265 = v2216->timer;
      int v2314 = v2265 + 100;
      v2216->timer = v2314;
      v2268 = v2246;
    }
    v2270 = v2268;
  }
  int * v2271 = v2216->regs;
  v2271[7] = v2270;
  struct StateT * v2273 = slot_18(v2216);
  return v2273;
}

struct StateT * slot_181(struct StateT * v13729) {
  int v13730 = v13729->timer;
  int v13738 = v13730 + 1;
  v13729->timer = v13738;
  int * v13732 = v13729->regs;
  int v13733 = v13732[6];
  int * v13734 = v13729->regs;
  int v13743 = (int)((unsigned int)v13733 >> 19);
  v13734[9] = v13743;
  struct StateT * v13736 = slot_182(v13729);
  return v13736;
}

struct StateT * slot_197(struct StateT * v14032) {
  int v14033 = v14032->timer;
  int v14043 = v14033 + 1;
  v14032->timer = v14043;
  int * v14035 = v14032->regs;
  int v14036 = v14035[11];
  int * v14037 = v14032->regs;
  int v14038 = v14037[9];
  int * v14039 = v14032->regs;
  int v14049 = v14036 | v14038;
  v14039[11] = v14049;
  struct StateT * v14041 = slot_198(v14032);
  return v14041;
}

struct StateT * slot_207(struct StateT * v14211) {
  int v14212 = v14211->timer;
  int v14222 = v14212 + 1;
  v14211->timer = v14222;
  int * v14214 = v14211->regs;
  int v14215 = v14214[21];
  int * v14216 = v14211->regs;
  int v14217 = v14216[11];
  int * v14218 = v14211->regs;
  int v14228 = v14215 ^ v14217;
  v14218[21] = v14228;
  struct StateT * v14220 = slot_208(v14211);
  return v14220;
}

struct StateT * slot_156(struct StateT * v13264) {
  int v13265 = v13264->timer;
  int v13273 = v13265 + 1;
  v13264->timer = v13273;
  int * v13267 = v13264->regs;
  int v13268 = v13267[11];
  int * v13269 = v13264->regs;
  int v13277 = v13268 << 9;
  v13269[11] = v13277;
  struct StateT * v13271 = slot_157(v13264);
  return v13271;
}

struct StateT * slot_154(struct StateT * v13226) {
  int v13227 = v13226->timer;
  int v13237 = v13227 + 1;
  v13226->timer = v13237;
  int * v13229 = v13226->regs;
  int v13230 = v13229[16];
  int * v13231 = v13226->regs;
  int v13232 = v13231[22];
  int * v13233 = v13226->regs;
  int v13244 = v13230 + v13232;
  v13233[8] = v13244;
  struct StateT * v13235 = slot_155(v13226);
  return v13235;
}

struct StateT * slot_68(struct StateT * v7484) {
  int v7485 = v7484->timer;
  int v7495 = v7485 + 1;
  v7484->timer = v7495;
  int * v7487 = v7484->regs;
  int v7488 = v7487[13];
  int * v7489 = v7484->regs;
  int v7490 = v7489[9];
  int * v7491 = v7484->regs;
  int v7501 = v7488 ^ v7490;
  v7491[13] = v7501;
  struct StateT * v7493 = slot_69(v7484);
  return v7493;
}

struct StateT * slot_260(struct StateT * v9961) {
  int v9962 = v9961->timer;
  int v10016 = v9962 + 1;
  v9961->timer = v10016;
  int * v9964 = v9961->regs;
  int v9965 = v9964[10];
  int * v9966 = v9961->regs;
  int v9967 = v9966[1];
  int * v9968 = v9961->cache_keys;
  int v9969 = v9968[0];
  bool v10023 = v9969 == ((int)((unsigned int)(v9965 + 56) >> 2));
  int v10013;
  if (v10023) {
    int * v9970 = v9961->cache_vals;
    v9970[0] = v9967;
    v10013 = v9967;
  } else {
    int * v9973 = v9961->cache_keys;
    int v9974 = v9973[1];
    bool v10027 = v9974 == ((int)((unsigned int)(v9965 + 56) >> 2));
    int v10011;
    if (v10027) {
      int * v9975 = v9961->cache_keys;
      int * v9976 = v9961->cache_keys;
      int v9977 = v9976[0];
      v9975[1] = v9977;
      int * v9979 = v9961->cache_vals;
      int * v9980 = v9961->cache_vals;
      int v9981 = v9980[0];
      v9979[1] = v9981;
      int * v9983 = v9961->cache_keys;
      int v10035 = (int)((unsigned int)(v9965 + 56) >> 2);
      v9983[0] = v10035;
      int * v9985 = v9961->cache_vals;
      v9985[0] = v9967;
      int v9987 = v9961->timer;
      int v10038 = v9987 + 1;
      v9961->timer = v10038;
      v10011 = v9967;
    } else {
      int * v9990 = v9961->mem;
      int * v9991 = v9961->cache_keys;
      int v9992 = v9991[1];
      int * v9993 = v9961->cache_vals;
      int v9994 = v9993[1];
      v9990[v9992] = v9994;
      int * v9996 = v9961->cache_keys;
      int * v9997 = v9961->cache_keys;
      int v9998 = v9997[0];
      v9996[1] = v9998;
      int * v10000 = v9961->cache_vals;
      int * v10001 = v9961->cache_vals;
      int v10002 = v10001[0];
      v10000[1] = v10002;
      int * v10004 = v9961->cache_keys;
      int v10051 = (int)((unsigned int)(v9965 + 56) >> 2);
      v10004[0] = v10051;
      int * v10006 = v9961->cache_vals;
      v10006[0] = v9967;
      int v10008 = v9961->timer;
      int v10054 = v10008 + 100;
      v9961->timer = v10054;
      v10011 = v9967;
    }
    v10013 = v10011;
  }
  struct StateT * v10014 = slot_261(v9961);
  return v10014;
}

struct StateT * slot_105(struct StateT * v11950) {
  int v11951 = v11950->timer;
  int v11959 = v11951 + 1;
  v11950->timer = v11959;
  int * v11953 = v11950->regs;
  int v11954 = v11953[18];
  int * v11955 = v11950->regs;
  int v11963 = v11954 << 13;
  v11955[18] = v11963;
  struct StateT * v11957 = slot_106(v11950);
  return v11957;
}

struct StateT * slot_27(struct StateT * v2951) {
  int v2952 = v2951->timer;
  int v2958 = v2952 + 1;
  v2951->timer = v2958;
  int * v2954 = v2951->regs;
  v2954[12] = 1634762752;
  struct StateT * v2956 = slot_28(v2951);
  return v2956;
}

struct StateT * slot_164(struct StateT * v13406) {
  int v13407 = v13406->timer;
  int v13415 = v13407 + 1;
  v13406->timer = v13415;
  int * v13409 = v13406->regs;
  int v13410 = v13409[8];
  int * v13411 = v13406->regs;
  int v13420 = (int)((unsigned int)v13410 >> 23);
  v13411[9] = v13420;
  struct StateT * v13413 = slot_165(v13406);
  return v13413;
}

struct StateT * slot_15(struct StateT * v1796) {
  int v1797 = v1796->timer;
  int v1855 = v1797 + 1;
  v1796->timer = v1855;
  int * v1799 = v1796->regs;
  int v1800 = v1799[12];
  int * v1801 = v1796->cache_keys;
  int v1802 = v1801[0];
  bool v1860 = v1802 == ((int)((unsigned int)v1800 >> 2));
  int v1850;
  if (v1860) {
    int * v1803 = v1796->cache_vals;
    int v1804 = v1803[0];
    v1850 = v1804;
  } else {
    int * v1806 = v1796->cache_keys;
    int v1807 = v1806[1];
    bool v1865 = v1807 == ((int)((unsigned int)v1800 >> 2));
    int v1848;
    if (v1865) {
      int * v1808 = v1796->cache_vals;
      int v1809 = v1808[1];
      int * v1810 = v1796->cache_keys;
      int * v1811 = v1796->cache_keys;
      int v1812 = v1811[0];
      v1810[1] = v1812;
      int * v1814 = v1796->cache_vals;
      int * v1815 = v1796->cache_vals;
      int v1816 = v1815[0];
      v1814[1] = v1816;
      int * v1818 = v1796->cache_keys;
      int v1874 = (int)((unsigned int)v1800 >> 2);
      v1818[0] = v1874;
      int * v1820 = v1796->cache_vals;
      v1820[0] = v1809;
      int v1822 = v1796->timer;
      int v1877 = v1822 + 1;
      v1796->timer = v1877;
      v1848 = v1809;
    } else {
      int * v1825 = v1796->mem;
      int v1879 = (int)((unsigned int)v1800 >> 2);
      int v1826 = v1825[v1879];
      int * v1827 = v1796->mem;
      int * v1828 = v1796->cache_keys;
      int v1829 = v1828[1];
      int * v1830 = v1796->cache_vals;
      int v1831 = v1830[1];
      v1827[v1829] = v1831;
      int * v1833 = v1796->cache_keys;
      int * v1834 = v1796->cache_keys;
      int v1835 = v1834[0];
      v1833[1] = v1835;
      int * v1837 = v1796->cache_vals;
      int * v1838 = v1796->cache_vals;
      int v1839 = v1838[0];
      v1837[1] = v1839;
      int * v1841 = v1796->cache_keys;
      v1841[0] = v1879;
      int * v1843 = v1796->cache_vals;
      v1843[0] = v1826;
      int v1845 = v1796->timer;
      int v1894 = v1845 + 100;
      v1796->timer = v1894;
      v1848 = v1826;
    }
    v1850 = v1848;
  }
  int * v1851 = v1796->regs;
  v1851[29] = v1850;
  struct StateT * v1853 = slot_16(v1796);
  return v1853;
}

struct StateT * slot_133(struct StateT * v12825) {
  int v12826 = v12825->timer;
  int v12836 = v12826 + 1;
  v12825->timer = v12836;
  int * v12828 = v12825->regs;
  int v12829 = v12828[19];
  int * v12830 = v12825->regs;
  int v12831 = v12830[13];
  int * v12832 = v12825->regs;
  int v12843 = v12829 + v12831;
  v12832[16] = v12843;
  struct StateT * v12834 = slot_134(v12825);
  return v12834;
}

struct StateT * slot_56(struct StateT * v6618) {
  int v6619 = v6618->timer;
  int v6627 = v6619 + 1;
  v6618->timer = v6627;
  int * v6621 = v6618->regs;
  int v6622 = v6621[15];
  int * v6623 = v6618->regs;
  int v6631 = v6622 << 7;
  v6623[15] = v6631;
  struct StateT * v6625 = slot_57(v6618);
  return v6625;
}

struct StateT * slot_244(struct StateT * v8243) {
  int v8244 = v8243->timer;
  int v8254 = v8244 + 1;
  v8243->timer = v8254;
  int * v8246 = v8243->regs;
  int v8247 = v8246[19];
  int * v8248 = v8243->regs;
  int v8249 = v8248[7];
  int * v8250 = v8243->regs;
  int v8260 = v8247 + v8249;
  v8250[7] = v8260;
  struct StateT * v8252 = slot_245(v8243);
  return v8252;
}

struct StateT * slot_222(struct StateT * v6825) {
  int v6826 = v6825->timer;
  int v6884 = v6826 + 1;
  v6825->timer = v6884;
  int * v6828 = v6825->regs;
  int v6829 = v6828[2];
  int * v6830 = v6825->cache_keys;
  int v6831 = v6830[0];
  bool v6889 = v6831 == ((int)((unsigned int)(v6829 + 16) >> 2));
  int v6879;
  if (v6889) {
    int * v6832 = v6825->cache_vals;
    int v6833 = v6832[0];
    v6879 = v6833;
  } else {
    int * v6835 = v6825->cache_keys;
    int v6836 = v6835[1];
    bool v6894 = v6836 == ((int)((unsigned int)(v6829 + 16) >> 2));
    int v6877;
    if (v6894) {
      int * v6837 = v6825->cache_vals;
      int v6838 = v6837[1];
      int * v6839 = v6825->cache_keys;
      int * v6840 = v6825->cache_keys;
      int v6841 = v6840[0];
      v6839[1] = v6841;
      int * v6843 = v6825->cache_vals;
      int * v6844 = v6825->cache_vals;
      int v6845 = v6844[0];
      v6843[1] = v6845;
      int * v6847 = v6825->cache_keys;
      int v6903 = (int)((unsigned int)(v6829 + 16) >> 2);
      v6847[0] = v6903;
      int * v6849 = v6825->cache_vals;
      v6849[0] = v6838;
      int v6851 = v6825->timer;
      int v6906 = v6851 + 1;
      v6825->timer = v6906;
      v6877 = v6838;
    } else {
      int * v6854 = v6825->mem;
      int v6908 = (int)((unsigned int)(v6829 + 16) >> 2);
      int v6855 = v6854[v6908];
      int * v6856 = v6825->mem;
      int * v6857 = v6825->cache_keys;
      int v6858 = v6857[1];
      int * v6859 = v6825->cache_vals;
      int v6860 = v6859[1];
      v6856[v6858] = v6860;
      int * v6862 = v6825->cache_keys;
      int * v6863 = v6825->cache_keys;
      int v6864 = v6863[0];
      v6862[1] = v6864;
      int * v6866 = v6825->cache_vals;
      int * v6867 = v6825->cache_vals;
      int v6868 = v6867[0];
      v6866[1] = v6868;
      int * v6870 = v6825->cache_keys;
      v6870[0] = v6908;
      int * v6872 = v6825->cache_vals;
      v6872[0] = v6855;
      int v6874 = v6825->timer;
      int v6923 = v6874 + 100;
      v6825->timer = v6923;
      v6877 = v6855;
    }
    v6879 = v6877;
  }
  int * v6880 = v6825->regs;
  v6880[7] = v6879;
  struct StateT * v6882 = slot_223(v6825);
  return v6882;
}

struct StateT * slot_34(struct StateT * v3054) {
  int v3055 = v3054->timer;
  int v3063 = v3055 + 1;
  v3054->timer = v3063;
  int * v3057 = v3054->regs;
  int v3058 = v3057[22];
  int * v3059 = v3054->regs;
  int v3067 = v3058 + 1396;
  v3059[22] = v3067;
  struct StateT * v3061 = slot_35(v3054);
  return v3061;
}

struct StateT * slot_171(struct StateT * v13539) {
  int v13540 = v13539->timer;
  int v13550 = v13540 + 1;
  v13539->timer = v13550;
  int * v13542 = v13539->regs;
  int v13543 = v13542[27];
  int * v13544 = v13539->regs;
  int v13545 = v13544[23];
  int * v13546 = v13539->regs;
  int v13557 = v13543 + v13545;
  v13546[11] = v13557;
  struct StateT * v13548 = slot_172(v13539);
  return v13548;
}

struct StateT * slot_162(struct StateT * v13370) {
  int v13371 = v13370->timer;
  int v13379 = v13371 + 1;
  v13370->timer = v13379;
  int * v13373 = v13370->regs;
  int v13374 = v13373[6];
  int * v13375 = v13370->regs;
  int v13383 = v13374 << 9;
  v13375[6] = v13383;
  struct StateT * v13377 = slot_163(v13370);
  return v13377;
}

struct StateT * slot_21(struct StateT * v2321) {
  int v2322 = v2321->timer;
  int v2380 = v2322 + 1;
  v2321->timer = v2380;
  int * v2324 = v2321->regs;
  int v2325 = v2324[12];
  int * v2326 = v2321->cache_keys;
  int v2327 = v2326[0];
  bool v2385 = v2327 == ((int)((unsigned int)(v2325 + 24) >> 2));
  int v2375;
  if (v2385) {
    int * v2328 = v2321->cache_vals;
    int v2329 = v2328[0];
    v2375 = v2329;
  } else {
    int * v2331 = v2321->cache_keys;
    int v2332 = v2331[1];
    bool v2390 = v2332 == ((int)((unsigned int)(v2325 + 24) >> 2));
    int v2373;
    if (v2390) {
      int * v2333 = v2321->cache_vals;
      int v2334 = v2333[1];
      int * v2335 = v2321->cache_keys;
      int * v2336 = v2321->cache_keys;
      int v2337 = v2336[0];
      v2335[1] = v2337;
      int * v2339 = v2321->cache_vals;
      int * v2340 = v2321->cache_vals;
      int v2341 = v2340[0];
      v2339[1] = v2341;
      int * v2343 = v2321->cache_keys;
      int v2399 = (int)((unsigned int)(v2325 + 24) >> 2);
      v2343[0] = v2399;
      int * v2345 = v2321->cache_vals;
      v2345[0] = v2334;
      int v2347 = v2321->timer;
      int v2402 = v2347 + 1;
      v2321->timer = v2402;
      v2373 = v2334;
    } else {
      int * v2350 = v2321->mem;
      int v2404 = (int)((unsigned int)(v2325 + 24) >> 2);
      int v2351 = v2350[v2404];
      int * v2352 = v2321->mem;
      int * v2353 = v2321->cache_keys;
      int v2354 = v2353[1];
      int * v2355 = v2321->cache_vals;
      int v2356 = v2355[1];
      v2352[v2354] = v2356;
      int * v2358 = v2321->cache_keys;
      int * v2359 = v2321->cache_keys;
      int v2360 = v2359[0];
      v2358[1] = v2360;
      int * v2362 = v2321->cache_vals;
      int * v2363 = v2321->cache_vals;
      int v2364 = v2363[0];
      v2362[1] = v2364;
      int * v2366 = v2321->cache_keys;
      v2366[0] = v2404;
      int * v2368 = v2321->cache_vals;
      v2368[0] = v2351;
      int v2370 = v2321->timer;
      int v2419 = v2370 + 100;
      v2321->timer = v2419;
      v2373 = v2351;
    }
    v2375 = v2373;
  }
  int * v2376 = v2321->regs;
  v2376[24] = v2375;
  struct StateT * v2378 = slot_22(v2321);
  return v2378;
}

struct StateT * slot_239(struct StateT * v8065) {
  int v8066 = v8065->timer;
  int v8074 = v8066 + 1;
  v8065->timer = v8074;
  int * v8068 = v8065->regs;
  int v8069 = v8068[6];
  int * v8070 = v8065->regs;
  int v8078 = v8069 + 1134;
  v8070[6] = v8078;
  struct StateT * v8072 = slot_240(v8065);
  return v8072;
}

struct StateT * slot_118(struct StateT * v12543) {
  int v12544 = v12543->timer;
  int v12552 = v12544 + 1;
  v12543->timer = v12552;
  int * v12546 = v12543->regs;
  int v12547 = v12546[16];
  int * v12548 = v12543->regs;
  int v12557 = (int)((unsigned int)v12547 >> 14);
  v12548[6] = v12557;
  struct StateT * v12550 = slot_119(v12543);
  return v12550;
}

struct StateT * slot_121(struct StateT * v12596) {
  int v12597 = v12596->timer;
  int v12605 = v12597 + 1;
  v12596->timer = v12605;
  int * v12599 = v12596->regs;
  int v12600 = v12599[17];
  int * v12601 = v12596->regs;
  int v12610 = (int)((unsigned int)v12600 >> 14);
  v12601[6] = v12610;
  struct StateT * v12603 = slot_122(v12596);
  return v12603;
}

struct StateT * slot_144(struct StateT * v13026) {
  int v13027 = v13026->timer;
  int v13035 = v13027 + 1;
  v13026->timer = v13035;
  int * v13029 = v13026->regs;
  int v13030 = v13029[17];
  int * v13031 = v13026->regs;
  int v13040 = (int)((unsigned int)v13030 >> 25);
  v13031[5] = v13040;
  struct StateT * v13033 = slot_145(v13026);
  return v13033;
}

struct StateT * slot_267(struct StateT * v11145) {
  int v11146 = v11145->timer;
  int v11204 = v11146 + 1;
  v11145->timer = v11204;
  int * v11148 = v11145->regs;
  int v11149 = v11148[2];
  int * v11150 = v11145->cache_keys;
  int v11151 = v11150[0];
  bool v11209 = v11151 == ((int)((unsigned int)(v11149 + 72) >> 2));
  int v11199;
  if (v11209) {
    int * v11152 = v11145->cache_vals;
    int v11153 = v11152[0];
    v11199 = v11153;
  } else {
    int * v11155 = v11145->cache_keys;
    int v11156 = v11155[1];
    bool v11214 = v11156 == ((int)((unsigned int)(v11149 + 72) >> 2));
    int v11197;
    if (v11214) {
      int * v11157 = v11145->cache_vals;
      int v11158 = v11157[1];
      int * v11159 = v11145->cache_keys;
      int * v11160 = v11145->cache_keys;
      int v11161 = v11160[0];
      v11159[1] = v11161;
      int * v11163 = v11145->cache_vals;
      int * v11164 = v11145->cache_vals;
      int v11165 = v11164[0];
      v11163[1] = v11165;
      int * v11167 = v11145->cache_keys;
      int v11223 = (int)((unsigned int)(v11149 + 72) >> 2);
      v11167[0] = v11223;
      int * v11169 = v11145->cache_vals;
      v11169[0] = v11158;
      int v11171 = v11145->timer;
      int v11226 = v11171 + 1;
      v11145->timer = v11226;
      v11197 = v11158;
    } else {
      int * v11174 = v11145->mem;
      int v11228 = (int)((unsigned int)(v11149 + 72) >> 2);
      int v11175 = v11174[v11228];
      int * v11176 = v11145->mem;
      int * v11177 = v11145->cache_keys;
      int v11178 = v11177[1];
      int * v11179 = v11145->cache_vals;
      int v11180 = v11179[1];
      v11176[v11178] = v11180;
      int * v11182 = v11145->cache_keys;
      int * v11183 = v11145->cache_keys;
      int v11184 = v11183[0];
      v11182[1] = v11184;
      int * v11186 = v11145->cache_vals;
      int * v11187 = v11145->cache_vals;
      int v11188 = v11187[0];
      v11186[1] = v11188;
      int * v11190 = v11145->cache_keys;
      v11190[0] = v11228;
      int * v11192 = v11145->cache_vals;
      v11192[0] = v11175;
      int v11194 = v11145->timer;
      int v11243 = v11194 + 100;
      v11145->timer = v11243;
      v11197 = v11175;
    }
    v11199 = v11197;
  }
  int * v11200 = v11145->regs;
  v11200[20] = v11199;
  struct StateT * v11202 = slot_268(v11145);
  return v11202;
}

struct StateT * slot_201(struct StateT * v14105) {
  int v14106 = v14105->timer;
  int v14114 = v14106 + 1;
  v14105->timer = v14114;
  int * v14108 = v14105->regs;
  int v14109 = v14108[6];
  int * v14110 = v14105->regs;
  int v14119 = (int)((unsigned int)v14109 >> 14);
  v14110[9] = v14119;
  struct StateT * v14112 = slot_202(v14105);
  return v14112;
}

struct StateT * slot_94(struct StateT * v9593) {
  int v9594 = v9593->timer;
  int v9604 = v9594 + 1;
  v9593->timer = v9604;
  int * v9596 = v9593->regs;
  int v9597 = v9596[25];
  int * v9598 = v9593->regs;
  int v9599 = v9598[14];
  int * v9600 = v9593->regs;
  int v9611 = v9597 + v9599;
  v9600[18] = v9611;
  struct StateT * v9602 = slot_95(v9593);
  return v9602;
}

struct StateT * slot_63(struct StateT * v7128) {
  int v7129 = v7128->timer;
  int v7139 = v7129 + 1;
  v7128->timer = v7139;
  int * v7131 = v7128->regs;
  int v7132 = v7131[18];
  int * v7133 = v7128->regs;
  int v7134 = v7133[20];
  int * v7135 = v7128->regs;
  int v7145 = v7132 | v7134;
  v7135[18] = v7145;
  struct StateT * v7137 = slot_64(v7128);
  return v7137;
}

struct StateT * slot_146(struct StateT * v13059) {
  int v13060 = v13059->timer;
  int v13070 = v13060 + 1;
  v13059->timer = v13070;
  int * v13062 = v13059->regs;
  int v13063 = v13062[17];
  int * v13064 = v13059->regs;
  int v13065 = v13064[5];
  int * v13066 = v13059->regs;
  int v13077 = v13063 | v13065;
  v13066[6] = v13077;
  struct StateT * v13068 = slot_147(v13059);
  return v13068;
}

struct StateT * slot_24(struct StateT * v2636) {
  int v2637 = v2636->timer;
  int v2695 = v2637 + 1;
  v2636->timer = v2695;
  int * v2639 = v2636->regs;
  int v2640 = v2639[11];
  int * v2641 = v2636->cache_keys;
  int v2642 = v2641[0];
  bool v2700 = v2642 == ((int)((unsigned int)(v2640 + 4) >> 2));
  int v2690;
  if (v2700) {
    int * v2643 = v2636->cache_vals;
    int v2644 = v2643[0];
    v2690 = v2644;
  } else {
    int * v2646 = v2636->cache_keys;
    int v2647 = v2646[1];
    bool v2705 = v2647 == ((int)((unsigned int)(v2640 + 4) >> 2));
    int v2688;
    if (v2705) {
      int * v2648 = v2636->cache_vals;
      int v2649 = v2648[1];
      int * v2650 = v2636->cache_keys;
      int * v2651 = v2636->cache_keys;
      int v2652 = v2651[0];
      v2650[1] = v2652;
      int * v2654 = v2636->cache_vals;
      int * v2655 = v2636->cache_vals;
      int v2656 = v2655[0];
      v2654[1] = v2656;
      int * v2658 = v2636->cache_keys;
      int v2714 = (int)((unsigned int)(v2640 + 4) >> 2);
      v2658[0] = v2714;
      int * v2660 = v2636->cache_vals;
      v2660[0] = v2649;
      int v2662 = v2636->timer;
      int v2717 = v2662 + 1;
      v2636->timer = v2717;
      v2688 = v2649;
    } else {
      int * v2665 = v2636->mem;
      int v2719 = (int)((unsigned int)(v2640 + 4) >> 2);
      int v2666 = v2665[v2719];
      int * v2667 = v2636->mem;
      int * v2668 = v2636->cache_keys;
      int v2669 = v2668[1];
      int * v2670 = v2636->cache_vals;
      int v2671 = v2670[1];
      v2667[v2669] = v2671;
      int * v2673 = v2636->cache_keys;
      int * v2674 = v2636->cache_keys;
      int v2675 = v2674[0];
      v2673[1] = v2675;
      int * v2677 = v2636->cache_vals;
      int * v2678 = v2636->cache_vals;
      int v2679 = v2678[0];
      v2677[1] = v2679;
      int * v2681 = v2636->cache_keys;
      v2681[0] = v2719;
      int * v2683 = v2636->cache_vals;
      v2683[0] = v2666;
      int v2685 = v2636->timer;
      int v2734 = v2685 + 100;
      v2636->timer = v2734;
      v2688 = v2666;
    }
    v2690 = v2688;
  }
  int * v2691 = v2636->regs;
  v2691[25] = v2690;
  struct StateT * v2693 = slot_25(v2636);
  return v2693;
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

struct StateT * slot_195(struct StateT * v13999) {
  int v14000 = v13999->timer;
  int v14008 = v14000 + 1;
  v13999->timer = v14008;
  int * v14002 = v13999->regs;
  int v14003 = v14002[11];
  int * v14004 = v13999->regs;
  int v14013 = (int)((unsigned int)v14003 >> 14);
  v14004[9] = v14013;
  struct StateT * v14006 = slot_196(v13999);
  return v14006;
}

struct StateT * slot_125(struct StateT * v12666) {
  int v12667 = v12666->timer;
  int v12675 = v12667 + 1;
  v12666->timer = v12675;
  int * v12669 = v12666->regs;
  int v12670 = v12669[5];
  int * v12671 = v12666->regs;
  int v12679 = v12670 << 18;
  v12671[5] = v12679;
  struct StateT * v12673 = slot_126(v12666);
  return v12673;
}

struct StateT * slot_254(struct StateT * v9257) {
  int v9258 = v9257->timer;
  int v9312 = v9258 + 1;
  v9257->timer = v9312;
  int * v9260 = v9257->regs;
  int v9261 = v9260[10];
  int * v9262 = v9257->regs;
  int v9263 = v9262[26];
  int * v9264 = v9257->cache_keys;
  int v9265 = v9264[0];
  bool v9319 = v9265 == ((int)((unsigned int)(v9261 + 32) >> 2));
  int v9309;
  if (v9319) {
    int * v9266 = v9257->cache_vals;
    v9266[0] = v9263;
    v9309 = v9263;
  } else {
    int * v9269 = v9257->cache_keys;
    int v9270 = v9269[1];
    bool v9324 = v9270 == ((int)((unsigned int)(v9261 + 32) >> 2));
    int v9307;
    if (v9324) {
      int * v9271 = v9257->cache_keys;
      int * v9272 = v9257->cache_keys;
      int v9273 = v9272[0];
      v9271[1] = v9273;
      int * v9275 = v9257->cache_vals;
      int * v9276 = v9257->cache_vals;
      int v9277 = v9276[0];
      v9275[1] = v9277;
      int * v9279 = v9257->cache_keys;
      int v9332 = (int)((unsigned int)(v9261 + 32) >> 2);
      v9279[0] = v9332;
      int * v9281 = v9257->cache_vals;
      v9281[0] = v9263;
      int v9283 = v9257->timer;
      int v9335 = v9283 + 1;
      v9257->timer = v9335;
      v9307 = v9263;
    } else {
      int * v9286 = v9257->mem;
      int * v9287 = v9257->cache_keys;
      int v9288 = v9287[1];
      int * v9289 = v9257->cache_vals;
      int v9290 = v9289[1];
      v9286[v9288] = v9290;
      int * v9292 = v9257->cache_keys;
      int * v9293 = v9257->cache_keys;
      int v9294 = v9293[0];
      v9292[1] = v9294;
      int * v9296 = v9257->cache_vals;
      int * v9297 = v9257->cache_vals;
      int v9298 = v9297[0];
      v9296[1] = v9298;
      int * v9300 = v9257->cache_keys;
      int v9348 = (int)((unsigned int)(v9261 + 32) >> 2);
      v9300[0] = v9348;
      int * v9302 = v9257->cache_vals;
      v9302[0] = v9263;
      int v9304 = v9257->timer;
      int v9351 = v9304 + 100;
      v9257->timer = v9351;
      v9307 = v9263;
    }
    v9309 = v9307;
  }
  struct StateT * v9310 = slot_255(v9257);
  return v9310;
}

struct StateT * slot_148(struct StateT * v13100) {
  int v13101 = v13100->timer;
  int v13111 = v13101 + 1;
  v13100->timer = v13111;
  int * v13103 = v13100->regs;
  int v13104 = v13103[18];
  int * v13105 = v13100->regs;
  int v13106 = v13105[11];
  int * v13107 = v13100->regs;
  int v13118 = v13104 ^ v13106;
  v13107[5] = v13118;
  struct StateT * v13109 = slot_149(v13100);
  return v13109;
}

struct StateT * slot_126(struct StateT * v12682) {
  int v12683 = v12682->timer;
  int v12693 = v12683 + 1;
  v12682->timer = v12693;
  int * v12685 = v12682->regs;
  int v12686 = v12685[5];
  int * v12687 = v12682->regs;
  int v12688 = v12687[6];
  int * v12689 = v12682->regs;
  int v12699 = v12686 | v12688;
  v12689[5] = v12699;
  struct StateT * v12691 = slot_127(v12682);
  return v12691;
}

struct StateT * slot_223(struct StateT * v6950) {
  int v6951 = v6950->timer;
  int v6961 = v6951 + 1;
  v6950->timer = v6961;
  int * v6953 = v6950->regs;
  int v6954 = v6953[25];
  int * v6955 = v6950->regs;
  int v6956 = v6955[7];
  int * v6957 = v6950->regs;
  int v6967 = v6954 + v6956;
  v6957[25] = v6967;
  struct StateT * v6959 = slot_224(v6950);
  return v6959;
}

struct StateT * slot_79(struct StateT * v8150) {
  int v8151 = v8150->timer;
  int v8159 = v8151 + 1;
  v8150->timer = v8159;
  int * v8153 = v8150->regs;
  int v8154 = v8153[8];
  int * v8155 = v8150->regs;
  int v8163 = v8154 << 9;
  v8155[8] = v8163;
  struct StateT * v8157 = slot_80(v8150);
  return v8157;
}

struct StateT * slot_237(struct StateT * v8003) {
  int v8004 = v8003->timer;
  int v8010 = v8004 + 1;
  v8003->timer = v8010;
  int * v8006 = v8003->regs;
  v8006[30] = 1797283840;
  struct StateT * v8008 = slot_238(v8003);
  return v8008;
}

struct StateT * slot_41(struct StateT * v3572) {
  int v3573 = v3572->timer;
  int v3627 = v3573 + 1;
  v3572->timer = v3627;
  int * v3575 = v3572->regs;
  int v3576 = v3575[2];
  int * v3577 = v3572->regs;
  int v3578 = v3577[16];
  int * v3579 = v3572->cache_keys;
  int v3580 = v3579[0];
  bool v3634 = v3580 == ((int)((unsigned int)(v3576 + 32) >> 2));
  int v3624;
  if (v3634) {
    int * v3581 = v3572->cache_vals;
    v3581[0] = v3578;
    v3624 = v3578;
  } else {
    int * v3584 = v3572->cache_keys;
    int v3585 = v3584[1];
    bool v3639 = v3585 == ((int)((unsigned int)(v3576 + 32) >> 2));
    int v3622;
    if (v3639) {
      int * v3586 = v3572->cache_keys;
      int * v3587 = v3572->cache_keys;
      int v3588 = v3587[0];
      v3586[1] = v3588;
      int * v3590 = v3572->cache_vals;
      int * v3591 = v3572->cache_vals;
      int v3592 = v3591[0];
      v3590[1] = v3592;
      int * v3594 = v3572->cache_keys;
      int v3647 = (int)((unsigned int)(v3576 + 32) >> 2);
      v3594[0] = v3647;
      int * v3596 = v3572->cache_vals;
      v3596[0] = v3578;
      int v3598 = v3572->timer;
      int v3650 = v3598 + 1;
      v3572->timer = v3650;
      v3622 = v3578;
    } else {
      int * v3601 = v3572->mem;
      int * v3602 = v3572->cache_keys;
      int v3603 = v3602[1];
      int * v3604 = v3572->cache_vals;
      int v3605 = v3604[1];
      v3601[v3603] = v3605;
      int * v3607 = v3572->cache_keys;
      int * v3608 = v3572->cache_keys;
      int v3609 = v3608[0];
      v3607[1] = v3609;
      int * v3611 = v3572->cache_vals;
      int * v3612 = v3572->cache_vals;
      int v3613 = v3612[0];
      v3611[1] = v3613;
      int * v3615 = v3572->cache_keys;
      int v3663 = (int)((unsigned int)(v3576 + 32) >> 2);
      v3615[0] = v3663;
      int * v3617 = v3572->cache_vals;
      v3617[0] = v3578;
      int v3619 = v3572->timer;
      int v3666 = v3619 + 100;
      v3572->timer = v3666;
      v3622 = v3578;
    }
    v3624 = v3622;
  }
  struct StateT * v3625 = slot_42(v3572);
  return v3625;
}

struct StateT * slot_39(struct StateT * v3377) {
  int v3378 = v3377->timer;
  int v3432 = v3378 + 1;
  v3377->timer = v3432;
  int * v3380 = v3377->regs;
  int v3381 = v3380[2];
  int * v3382 = v3377->regs;
  int v3383 = v3382[1];
  int * v3384 = v3377->cache_keys;
  int v3385 = v3384[0];
  bool v3439 = v3385 == ((int)((unsigned int)(v3381 + 40) >> 2));
  int v3429;
  if (v3439) {
    int * v3386 = v3377->cache_vals;
    v3386[0] = v3383;
    v3429 = v3383;
  } else {
    int * v3389 = v3377->cache_keys;
    int v3390 = v3389[1];
    bool v3443 = v3390 == ((int)((unsigned int)(v3381 + 40) >> 2));
    int v3427;
    if (v3443) {
      int * v3391 = v3377->cache_keys;
      int * v3392 = v3377->cache_keys;
      int v3393 = v3392[0];
      v3391[1] = v3393;
      int * v3395 = v3377->cache_vals;
      int * v3396 = v3377->cache_vals;
      int v3397 = v3396[0];
      v3395[1] = v3397;
      int * v3399 = v3377->cache_keys;
      int v3451 = (int)((unsigned int)(v3381 + 40) >> 2);
      v3399[0] = v3451;
      int * v3401 = v3377->cache_vals;
      v3401[0] = v3383;
      int v3403 = v3377->timer;
      int v3454 = v3403 + 1;
      v3377->timer = v3454;
      v3427 = v3383;
    } else {
      int * v3406 = v3377->mem;
      int * v3407 = v3377->cache_keys;
      int v3408 = v3407[1];
      int * v3409 = v3377->cache_vals;
      int v3410 = v3409[1];
      v3406[v3408] = v3410;
      int * v3412 = v3377->cache_keys;
      int * v3413 = v3377->cache_keys;
      int v3414 = v3413[0];
      v3412[1] = v3414;
      int * v3416 = v3377->cache_vals;
      int * v3417 = v3377->cache_vals;
      int v3418 = v3417[0];
      v3416[1] = v3418;
      int * v3420 = v3377->cache_keys;
      int v3467 = (int)((unsigned int)(v3381 + 40) >> 2);
      v3420[0] = v3467;
      int * v3422 = v3377->cache_vals;
      v3422[0] = v3383;
      int v3424 = v3377->timer;
      int v3470 = v3424 + 100;
      v3377->timer = v3470;
      v3427 = v3383;
    }
    v3429 = v3427;
  }
  struct StateT * v3430 = slot_40(v3377);
  return v3430;
}

struct StateT * slot_142(struct StateT * v12990) {
  int v12991 = v12990->timer;
  int v12999 = v12991 + 1;
  v12990->timer = v12999;
  int * v12993 = v12990->regs;
  int v12994 = v12993[16];
  int * v12995 = v12990->regs;
  int v13003 = v12994 << 7;
  v12995[16] = v13003;
  struct StateT * v12997 = slot_143(v12990);
  return v12997;
}

struct StateT * slot_60(struct StateT * v6930) {
  int v6931 = v6930->timer;
  int v6941 = v6931 + 1;
  v6930->timer = v6941;
  int * v6933 = v6930->regs;
  int v6934 = v6933[20];
  int * v6935 = v6930->regs;
  int v6936 = v6935[9];
  int * v6937 = v6930->regs;
  int v6947 = v6934 | v6936;
  v6937[9] = v6947;
  struct StateT * v6939 = slot_61(v6930);
  return v6939;
}

struct StateT * slot_238(struct StateT * v8033) {
  int v8034 = v8033->timer;
  int v8042 = v8034 + 1;
  v8033->timer = v8042;
  int * v8036 = v8033->regs;
  int v8037 = v8036[15];
  int * v8038 = v8033->regs;
  int v8046 = v8037 + -1947;
  v8038[15] = v8046;
  struct StateT * v8040 = slot_239(v8033);
  return v8040;
}

struct StateT * slot_112(struct StateT * v12427) {
  int v12428 = v12427->timer;
  int v12438 = v12428 + 1;
  v12427->timer = v12438;
  int * v12430 = v12427->regs;
  int v12431 = v12430[23];
  int * v12432 = v12427->regs;
  int v12433 = v12432[24];
  int * v12434 = v12427->regs;
  int v12445 = v12431 + v12433;
  v12434[16] = v12445;
  struct StateT * v12436 = slot_113(v12427);
  return v12436;
}

struct StateT * slot_256(struct StateT * v9495) {
  int v9496 = v9495->timer;
  int v9550 = v9496 + 1;
  v9495->timer = v9550;
  int * v9498 = v9495->regs;
  int v9499 = v9498[10];
  int * v9500 = v9495->regs;
  int v9501 = v9500[7];
  int * v9502 = v9495->cache_keys;
  int v9503 = v9502[0];
  bool v9557 = v9503 == ((int)((unsigned int)(v9499 + 40) >> 2));
  int v9547;
  if (v9557) {
    int * v9504 = v9495->cache_vals;
    v9504[0] = v9501;
    v9547 = v9501;
  } else {
    int * v9507 = v9495->cache_keys;
    int v9508 = v9507[1];
    bool v9562 = v9508 == ((int)((unsigned int)(v9499 + 40) >> 2));
    int v9545;
    if (v9562) {
      int * v9509 = v9495->cache_keys;
      int * v9510 = v9495->cache_keys;
      int v9511 = v9510[0];
      v9509[1] = v9511;
      int * v9513 = v9495->cache_vals;
      int * v9514 = v9495->cache_vals;
      int v9515 = v9514[0];
      v9513[1] = v9515;
      int * v9517 = v9495->cache_keys;
      int v9570 = (int)((unsigned int)(v9499 + 40) >> 2);
      v9517[0] = v9570;
      int * v9519 = v9495->cache_vals;
      v9519[0] = v9501;
      int v9521 = v9495->timer;
      int v9573 = v9521 + 1;
      v9495->timer = v9573;
      v9545 = v9501;
    } else {
      int * v9524 = v9495->mem;
      int * v9525 = v9495->cache_keys;
      int v9526 = v9525[1];
      int * v9527 = v9495->cache_vals;
      int v9528 = v9527[1];
      v9524[v9526] = v9528;
      int * v9530 = v9495->cache_keys;
      int * v9531 = v9495->cache_keys;
      int v9532 = v9531[0];
      v9530[1] = v9532;
      int * v9534 = v9495->cache_vals;
      int * v9535 = v9495->cache_vals;
      int v9536 = v9535[0];
      v9534[1] = v9536;
      int * v9538 = v9495->cache_keys;
      int v9586 = (int)((unsigned int)(v9499 + 40) >> 2);
      v9538[0] = v9586;
      int * v9540 = v9495->cache_vals;
      v9540[0] = v9501;
      int v9542 = v9495->timer;
      int v9589 = v9542 + 100;
      v9495->timer = v9589;
      v9545 = v9501;
    }
    v9547 = v9545;
  }
  struct StateT * v9548 = slot_257(v9495);
  return v9548;
}

struct StateT * slot_272(struct StateT * v11966) {
  int v11967 = v11966->timer;
  int v12025 = v11967 + 1;
  v11966->timer = v12025;
  int * v11969 = v11966->regs;
  int v11970 = v11969[2];
  int * v11971 = v11966->cache_keys;
  int v11972 = v11971[0];
  bool v12030 = v11972 == ((int)((unsigned int)(v11970 + 52) >> 2));
  int v12020;
  if (v12030) {
    int * v11973 = v11966->cache_vals;
    int v11974 = v11973[0];
    v12020 = v11974;
  } else {
    int * v11976 = v11966->cache_keys;
    int v11977 = v11976[1];
    bool v12035 = v11977 == ((int)((unsigned int)(v11970 + 52) >> 2));
    int v12018;
    if (v12035) {
      int * v11978 = v11966->cache_vals;
      int v11979 = v11978[1];
      int * v11980 = v11966->cache_keys;
      int * v11981 = v11966->cache_keys;
      int v11982 = v11981[0];
      v11980[1] = v11982;
      int * v11984 = v11966->cache_vals;
      int * v11985 = v11966->cache_vals;
      int v11986 = v11985[0];
      v11984[1] = v11986;
      int * v11988 = v11966->cache_keys;
      int v12044 = (int)((unsigned int)(v11970 + 52) >> 2);
      v11988[0] = v12044;
      int * v11990 = v11966->cache_vals;
      v11990[0] = v11979;
      int v11992 = v11966->timer;
      int v12047 = v11992 + 1;
      v11966->timer = v12047;
      v12018 = v11979;
    } else {
      int * v11995 = v11966->mem;
      int v12049 = (int)((unsigned int)(v11970 + 52) >> 2);
      int v11996 = v11995[v12049];
      int * v11997 = v11966->mem;
      int * v11998 = v11966->cache_keys;
      int v11999 = v11998[1];
      int * v12000 = v11966->cache_vals;
      int v12001 = v12000[1];
      v11997[v11999] = v12001;
      int * v12003 = v11966->cache_keys;
      int * v12004 = v11966->cache_keys;
      int v12005 = v12004[0];
      v12003[1] = v12005;
      int * v12007 = v11966->cache_vals;
      int * v12008 = v11966->cache_vals;
      int v12009 = v12008[0];
      v12007[1] = v12009;
      int * v12011 = v11966->cache_keys;
      v12011[0] = v12049;
      int * v12013 = v11966->cache_vals;
      v12013[0] = v11996;
      int v12015 = v11966->timer;
      int v12064 = v12015 + 100;
      v11966->timer = v12064;
      v12018 = v11996;
    }
    v12020 = v12018;
  }
  int * v12021 = v11966->regs;
  v12021[25] = v12020;
  struct StateT * v12023 = slot_273(v11966);
  return v12023;
}

struct StateT * slot_214(struct StateT * v6360) {
  int v6361 = v6360->timer;
  int v6371 = v6361 + 1;
  v6360->timer = v6371;
  int * v6363 = v6360->regs;
  int v6364 = v6363[27];
  int * v6365 = v6360->regs;
  int v6366 = v6365[28];
  int * v6367 = v6360->regs;
  int v6377 = v6364 + v6366;
  v6367[28] = v6377;
  struct StateT * v6369 = slot_215(v6360);
  return v6369;
}

struct StateT * slot_29(struct StateT * v2977) {
  int v2978 = v2977->timer;
  int v2984 = v2978 + 1;
  v2977->timer = v2984;
  int * v2980 = v2977->regs;
  v2980[14] = 2036477952;
  struct StateT * v2982 = slot_30(v2977);
  return v2982;
}

struct StateT * slot_16(struct StateT * v2006) {
  int v2007 = v2006->timer;
  int v2065 = v2007 + 1;
  v2006->timer = v2065;
  int * v2009 = v2006->regs;
  int v2010 = v2009[12];
  int * v2011 = v2006->cache_keys;
  int v2012 = v2011[0];
  bool v2070 = v2012 == ((int)((unsigned int)(v2010 + 4) >> 2));
  int v2060;
  if (v2070) {
    int * v2013 = v2006->cache_vals;
    int v2014 = v2013[0];
    v2060 = v2014;
  } else {
    int * v2016 = v2006->cache_keys;
    int v2017 = v2016[1];
    bool v2075 = v2017 == ((int)((unsigned int)(v2010 + 4) >> 2));
    int v2058;
    if (v2075) {
      int * v2018 = v2006->cache_vals;
      int v2019 = v2018[1];
      int * v2020 = v2006->cache_keys;
      int * v2021 = v2006->cache_keys;
      int v2022 = v2021[0];
      v2020[1] = v2022;
      int * v2024 = v2006->cache_vals;
      int * v2025 = v2006->cache_vals;
      int v2026 = v2025[0];
      v2024[1] = v2026;
      int * v2028 = v2006->cache_keys;
      int v2084 = (int)((unsigned int)(v2010 + 4) >> 2);
      v2028[0] = v2084;
      int * v2030 = v2006->cache_vals;
      v2030[0] = v2019;
      int v2032 = v2006->timer;
      int v2087 = v2032 + 1;
      v2006->timer = v2087;
      v2058 = v2019;
    } else {
      int * v2035 = v2006->mem;
      int v2089 = (int)((unsigned int)(v2010 + 4) >> 2);
      int v2036 = v2035[v2089];
      int * v2037 = v2006->mem;
      int * v2038 = v2006->cache_keys;
      int v2039 = v2038[1];
      int * v2040 = v2006->cache_vals;
      int v2041 = v2040[1];
      v2037[v2039] = v2041;
      int * v2043 = v2006->cache_keys;
      int * v2044 = v2006->cache_keys;
      int v2045 = v2044[0];
      v2043[1] = v2045;
      int * v2047 = v2006->cache_vals;
      int * v2048 = v2006->cache_vals;
      int v2049 = v2048[0];
      v2047[1] = v2049;
      int * v2051 = v2006->cache_keys;
      v2051[0] = v2089;
      int * v2053 = v2006->cache_vals;
      v2053[0] = v2036;
      int v2055 = v2006->timer;
      int v2104 = v2055 + 100;
      v2006->timer = v2104;
      v2058 = v2036;
    }
    v2060 = v2058;
  }
  int * v2061 = v2006->regs;
  v2061[28] = v2060;
  struct StateT * v2063 = slot_17(v2006);
  return v2063;
}

struct StateT * slot_245(struct StateT * v8279) {
  int v8280 = v8279->timer;
  int v8290 = v8280 + 1;
  v8279->timer = v8290;
  int * v8282 = v8279->regs;
  int v8283 = v8282[22];
  int * v8284 = v8279->regs;
  int v8285 = v8284[30];
  int * v8286 = v8279->regs;
  int v8296 = v8283 + v8285;
  v8286[30] = v8296;
  struct StateT * v8288 = slot_246(v8279);
  return v8288;
}

struct StateT * slot_113(struct StateT * v12448) {
  int v12449 = v12448->timer;
  int v12459 = v12449 + 1;
  v12448->timer = v12459;
  int * v12451 = v12448->regs;
  int v12452 = v12451[18];
  int * v12453 = v12448->regs;
  int v12454 = v12453[27];
  int * v12455 = v12448->regs;
  int v12466 = v12452 + v12454;
  v12455[17] = v12466;
  struct StateT * v12457 = slot_114(v12448);
  return v12457;
}

struct StateT * slot_151(struct StateT * v13163) {
  int v13164 = v13163->timer;
  int v13174 = v13164 + 1;
  v13163->timer = v13174;
  int * v13166 = v13163->regs;
  int v13167 = v13166[23];
  int * v13168 = v13163->regs;
  int v13169 = v13168[21];
  int * v13170 = v13163->regs;
  int v13181 = v13167 + v13169;
  v13170[11] = v13181;
  struct StateT * v13172 = slot_152(v13163);
  return v13172;
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

struct StateT * slot_124(struct StateT * v12649) {
  int v12650 = v12649->timer;
  int v12658 = v12650 + 1;
  v12649->timer = v12658;
  int * v12652 = v12649->regs;
  int v12653 = v12652[5];
  int * v12654 = v12649->regs;
  int v12663 = (int)((unsigned int)v12653 >> 14);
  v12654[6] = v12663;
  struct StateT * v12656 = slot_125(v12649);
  return v12656;
}

struct StateT * slot_191(struct StateT * v13915) {
  int v13916 = v13915->timer;
  int v13926 = v13916 + 1;
  v13915->timer = v13926;
  int * v13918 = v13915->regs;
  int v13919 = v13918[14];
  int * v13920 = v13915->regs;
  int v13921 = v13920[27];
  int * v13922 = v13915->regs;
  int v13933 = v13919 + v13921;
  v13922[11] = v13933;
  struct StateT * v13924 = slot_192(v13915);
  return v13924;
}

struct StateT * slot_103(struct StateT * v11703) {
  int v11704 = v11703->timer;
  int v11714 = v11704 + 1;
  v11703->timer = v11714;
  int * v11706 = v11703->regs;
  int v11707 = v11706[9];
  int * v11708 = v11703->regs;
  int v11709 = v11708[20];
  int * v11710 = v11703->regs;
  int v11720 = v11707 | v11709;
  v11710[20] = v11720;
  struct StateT * v11712 = slot_104(v11703);
  return v11712;
}

struct StateT * slot_128(struct StateT * v12722) {
  int v12723 = v12722->timer;
  int v12733 = v12723 + 1;
  v12722->timer = v12733;
  int * v12725 = v12722->regs;
  int v12726 = v12725[11];
  int * v12727 = v12722->regs;
  int v12728 = v12727[16];
  int * v12729 = v12722->regs;
  int v12740 = v12726 ^ v12728;
  v12729[20] = v12740;
  struct StateT * v12731 = slot_129(v12722);
  return v12731;
}

struct StateT * slot_19(struct StateT * v1901) {
  int v1902 = v1901->timer;
  int v1960 = v1902 + 1;
  v1901->timer = v1960;
  int * v1904 = v1901->regs;
  int v1905 = v1904[12];
  int * v1906 = v1901->cache_keys;
  int v1907 = v1906[0];
  bool v1965 = v1907 == ((int)((unsigned int)(v1905 + 16) >> 2));
  int v1955;
  if (v1965) {
    int * v1908 = v1901->cache_vals;
    int v1909 = v1908[0];
    v1955 = v1909;
  } else {
    int * v1911 = v1901->cache_keys;
    int v1912 = v1911[1];
    bool v1970 = v1912 == ((int)((unsigned int)(v1905 + 16) >> 2));
    int v1953;
    if (v1970) {
      int * v1913 = v1901->cache_vals;
      int v1914 = v1913[1];
      int * v1915 = v1901->cache_keys;
      int * v1916 = v1901->cache_keys;
      int v1917 = v1916[0];
      v1915[1] = v1917;
      int * v1919 = v1901->cache_vals;
      int * v1920 = v1901->cache_vals;
      int v1921 = v1920[0];
      v1919[1] = v1921;
      int * v1923 = v1901->cache_keys;
      int v1979 = (int)((unsigned int)(v1905 + 16) >> 2);
      v1923[0] = v1979;
      int * v1925 = v1901->cache_vals;
      v1925[0] = v1914;
      int v1927 = v1901->timer;
      int v1982 = v1927 + 1;
      v1901->timer = v1982;
      v1953 = v1914;
    } else {
      int * v1930 = v1901->mem;
      int v1984 = (int)((unsigned int)(v1905 + 16) >> 2);
      int v1931 = v1930[v1984];
      int * v1932 = v1901->mem;
      int * v1933 = v1901->cache_keys;
      int v1934 = v1933[1];
      int * v1935 = v1901->cache_vals;
      int v1936 = v1935[1];
      v1932[v1934] = v1936;
      int * v1938 = v1901->cache_keys;
      int * v1939 = v1901->cache_keys;
      int v1940 = v1939[0];
      v1938[1] = v1940;
      int * v1942 = v1901->cache_vals;
      int * v1943 = v1901->cache_vals;
      int v1944 = v1943[0];
      v1942[1] = v1944;
      int * v1946 = v1901->cache_keys;
      v1946[0] = v1984;
      int * v1948 = v1901->cache_vals;
      v1948[0] = v1931;
      int v1950 = v1901->timer;
      int v1999 = v1950 + 100;
      v1901->timer = v1999;
      v1953 = v1931;
    }
    v1955 = v1953;
  }
  int * v1956 = v1901->regs;
  v1956[17] = v1955;
  struct StateT * v1958 = slot_20(v1901);
  return v1958;
}

struct StateT * slot_87(struct StateT * v8764) {
  int v8765 = v8764->timer;
  int v8775 = v8765 + 1;
  v8764->timer = v8775;
  int * v8767 = v8764->regs;
  int v8768 = v8767[26];
  int * v8769 = v8764->regs;
  int v8770 = v8769[15];
  int * v8771 = v8764->regs;
  int v8781 = v8768 ^ v8770;
  v8771[26] = v8781;
  struct StateT * v8773 = slot_88(v8764);
  return v8773;
}

struct StateT * slot_67(struct StateT * v7444) {
  int v7445 = v7444->timer;
  int v7455 = v7445 + 1;
  v7444->timer = v7455;
  int * v7447 = v7444->regs;
  int v7448 = v7447[12];
  int * v7449 = v7444->regs;
  int v7450 = v7449[15];
  int * v7451 = v7444->regs;
  int v7461 = v7448 ^ v7450;
  v7451[12] = v7461;
  struct StateT * v7453 = slot_68(v7444);
  return v7453;
}

struct StateT * slot_81(struct StateT * v8226) {
  int v8227 = v8226->timer;
  int v8235 = v8227 + 1;
  v8226->timer = v8235;
  int * v8229 = v8226->regs;
  int v8230 = v8229[9];
  int * v8231 = v8226->regs;
  int v8240 = (int)((unsigned int)v8230 >> 23);
  v8231[20] = v8240;
  struct StateT * v8233 = slot_82(v8226);
  return v8233;
}

struct StateT * slot_95(struct StateT * v9712) {
  int v9713 = v9712->timer;
  int v9721 = v9713 + 1;
  v9712->timer = v9721;
  int * v9715 = v9712->regs;
  int v9716 = v9715[15];
  int * v9717 = v9712->regs;
  int v9726 = (int)((unsigned int)v9716 >> 19);
  v9717[20] = v9726;
  struct StateT * v9719 = slot_96(v9712);
  return v9719;
}

struct StateT * slot_115(struct StateT * v12490) {
  int v12491 = v12490->timer;
  int v12499 = v12491 + 1;
  v12490->timer = v12499;
  int * v12493 = v12490->regs;
  int v12494 = v12493[15];
  int * v12495 = v12490->regs;
  int v12504 = (int)((unsigned int)v12494 >> 14);
  v12495[6] = v12504;
  struct StateT * v12497 = slot_116(v12490);
  return v12497;
}

struct StateT * slot_78(struct StateT * v8117) {
  int v8118 = v8117->timer;
  int v8126 = v8118 + 1;
  v8117->timer = v8126;
  int * v8120 = v8117->regs;
  int v8121 = v8120[8];
  int * v8122 = v8117->regs;
  int v8131 = (int)((unsigned int)v8121 >> 23);
  v8122[20] = v8131;
  struct StateT * v8124 = slot_79(v8117);
  return v8124;
}

struct StateT * slot_32(struct StateT * v3024) {
  int v3025 = v3024->timer;
  int v3033 = v3025 + 1;
  v3024->timer = v3033;
  int * v3027 = v3024->regs;
  int v3028 = v3027[14];
  int * v3029 = v3024->regs;
  int v3038 = v3028 + -718;
  v3029[19] = v3038;
  struct StateT * v3031 = slot_33(v3024);
  return v3031;
}

struct StateT * slot_205(struct StateT * v14175) {
  int v14176 = v14175->timer;
  int v14184 = v14176 + 1;
  v14175->timer = v14184;
  int * v14178 = v14175->regs;
  int v14179 = v14178[8];
  int * v14180 = v14175->regs;
  int v14188 = v14179 << 18;
  v14180[8] = v14188;
  struct StateT * v14182 = slot_206(v14175);
  return v14182;
}

struct StateT * slot_193(struct StateT * v13957) {
  int v13958 = v13957->timer;
  int v13968 = v13958 + 1;
  v13957->timer = v13968;
  int * v13960 = v13957->regs;
  int v13961 = v13960[13];
  int * v13962 = v13957->regs;
  int v13963 = v13962[26];
  int * v13964 = v13957->regs;
  int v13975 = v13961 + v13963;
  v13964[6] = v13975;
  struct StateT * v13966 = slot_194(v13957);
  return v13966;
}

struct StateT * slot_233(struct StateT * v7669) {
  int v7670 = v7669->timer;
  int v7728 = v7670 + 1;
  v7669->timer = v7728;
  int * v7672 = v7669->regs;
  int v7673 = v7672[2];
  int * v7674 = v7669->cache_keys;
  int v7675 = v7674[0];
  bool v7733 = v7675 == ((int)((unsigned int)(v7673 + 36) >> 2));
  int v7723;
  if (v7733) {
    int * v7676 = v7669->cache_vals;
    int v7677 = v7676[0];
    v7723 = v7677;
  } else {
    int * v7679 = v7669->cache_keys;
    int v7680 = v7679[1];
    bool v7738 = v7680 == ((int)((unsigned int)(v7673 + 36) >> 2));
    int v7721;
    if (v7738) {
      int * v7681 = v7669->cache_vals;
      int v7682 = v7681[1];
      int * v7683 = v7669->cache_keys;
      int * v7684 = v7669->cache_keys;
      int v7685 = v7684[0];
      v7683[1] = v7685;
      int * v7687 = v7669->cache_vals;
      int * v7688 = v7669->cache_vals;
      int v7689 = v7688[0];
      v7687[1] = v7689;
      int * v7691 = v7669->cache_keys;
      int v7747 = (int)((unsigned int)(v7673 + 36) >> 2);
      v7691[0] = v7747;
      int * v7693 = v7669->cache_vals;
      v7693[0] = v7682;
      int v7695 = v7669->timer;
      int v7750 = v7695 + 1;
      v7669->timer = v7750;
      v7721 = v7682;
    } else {
      int * v7698 = v7669->mem;
      int v7752 = (int)((unsigned int)(v7673 + 36) >> 2);
      int v7699 = v7698[v7752];
      int * v7700 = v7669->mem;
      int * v7701 = v7669->cache_keys;
      int v7702 = v7701[1];
      int * v7703 = v7669->cache_vals;
      int v7704 = v7703[1];
      v7700[v7702] = v7704;
      int * v7706 = v7669->cache_keys;
      int * v7707 = v7669->cache_keys;
      int v7708 = v7707[0];
      v7706[1] = v7708;
      int * v7710 = v7669->cache_vals;
      int * v7711 = v7669->cache_vals;
      int v7712 = v7711[0];
      v7710[1] = v7712;
      int * v7714 = v7669->cache_keys;
      v7714[0] = v7752;
      int * v7716 = v7669->cache_vals;
      v7716[0] = v7699;
      int v7718 = v7669->timer;
      int v7767 = v7718 + 100;
      v7669->timer = v7767;
      v7721 = v7699;
    }
    v7723 = v7721;
  }
  int * v7724 = v7669->regs;
  v7724[30] = v7723;
  struct StateT * v7726 = slot_234(v7669);
  return v7726;
}

struct StateT * slot_176(struct StateT * v13640) {
  int v13641 = v13640->timer;
  int v13649 = v13641 + 1;
  v13640->timer = v13649;
  int * v13643 = v13640->regs;
  int v13644 = v13643[11];
  int * v13645 = v13640->regs;
  int v13653 = v13644 << 13;
  v13645[11] = v13653;
  struct StateT * v13647 = slot_177(v13640);
  return v13647;
}

struct StateT * slot_189(struct StateT * v13875) {
  int v13876 = v13875->timer;
  int v13886 = v13876 + 1;
  v13875->timer = v13886;
  int * v13878 = v13875->regs;
  int v13879 = v13878[13];
  int * v13880 = v13875->regs;
  int v13881 = v13880[6];
  int * v13882 = v13875->regs;
  int v13892 = v13879 ^ v13881;
  v13882[13] = v13892;
  struct StateT * v13884 = slot_190(v13875);
  return v13884;
}

struct StateT * slot_33(struct StateT * v3041) {
  int v3042 = v3041->timer;
  int v3048 = v3042 + 1;
  v3041->timer = v3048;
  int * v3044 = v3041->regs;
  v3044[22] = 1797283840;
  struct StateT * v3046 = slot_34(v3041);
  return v3046;
}

struct StateT * slot_35(struct StateT * v3070) {
  int v3071 = v3070->timer;
  int v3077 = v3071 + 1;
  v3070->timer = v3077;
  int * v3073 = v3070->regs;
  v3073[31] = 9;
  struct StateT * v3075 = slot_36(v3070);
  return v3075;
}

struct StateT * slot_258(struct StateT * v9729) {
  int v9730 = v9729->timer;
  int v9784 = v9730 + 1;
  v9729->timer = v9784;
  int * v9732 = v9729->regs;
  int v9733 = v9732[10];
  int * v9734 = v9729->regs;
  int v9735 = v9734[16];
  int * v9736 = v9729->cache_keys;
  int v9737 = v9736[0];
  bool v9791 = v9737 == ((int)((unsigned int)(v9733 + 48) >> 2));
  int v9781;
  if (v9791) {
    int * v9738 = v9729->cache_vals;
    v9738[0] = v9735;
    v9781 = v9735;
  } else {
    int * v9741 = v9729->cache_keys;
    int v9742 = v9741[1];
    bool v9796 = v9742 == ((int)((unsigned int)(v9733 + 48) >> 2));
    int v9779;
    if (v9796) {
      int * v9743 = v9729->cache_keys;
      int * v9744 = v9729->cache_keys;
      int v9745 = v9744[0];
      v9743[1] = v9745;
      int * v9747 = v9729->cache_vals;
      int * v9748 = v9729->cache_vals;
      int v9749 = v9748[0];
      v9747[1] = v9749;
      int * v9751 = v9729->cache_keys;
      int v9804 = (int)((unsigned int)(v9733 + 48) >> 2);
      v9751[0] = v9804;
      int * v9753 = v9729->cache_vals;
      v9753[0] = v9735;
      int v9755 = v9729->timer;
      int v9807 = v9755 + 1;
      v9729->timer = v9807;
      v9779 = v9735;
    } else {
      int * v9758 = v9729->mem;
      int * v9759 = v9729->cache_keys;
      int v9760 = v9759[1];
      int * v9761 = v9729->cache_vals;
      int v9762 = v9761[1];
      v9758[v9760] = v9762;
      int * v9764 = v9729->cache_keys;
      int * v9765 = v9729->cache_keys;
      int v9766 = v9765[0];
      v9764[1] = v9766;
      int * v9768 = v9729->cache_vals;
      int * v9769 = v9729->cache_vals;
      int v9770 = v9769[0];
      v9768[1] = v9770;
      int * v9772 = v9729->cache_keys;
      int v9820 = (int)((unsigned int)(v9733 + 48) >> 2);
      v9772[0] = v9820;
      int * v9774 = v9729->cache_vals;
      v9774[0] = v9735;
      int v9776 = v9729->timer;
      int v9823 = v9776 + 100;
      v9729->timer = v9823;
      v9779 = v9735;
    }
    v9781 = v9779;
  }
  struct StateT * v9782 = slot_259(v9729);
  return v9782;
}

struct StateT * slot_246(struct StateT * v8319) {
  int v8320 = v8319->timer;
  int v8374 = v8320 + 1;
  v8319->timer = v8374;
  int * v8322 = v8319->regs;
  int v8323 = v8322[10];
  int * v8324 = v8319->regs;
  int v8325 = v8324[15];
  int * v8326 = v8319->cache_keys;
  int v8327 = v8326[0];
  bool v8381 = v8327 == ((int)((unsigned int)v8323 >> 2));
  int v8371;
  if (v8381) {
    int * v8328 = v8319->cache_vals;
    v8328[0] = v8325;
    v8371 = v8325;
  } else {
    int * v8331 = v8319->cache_keys;
    int v8332 = v8331[1];
    bool v8386 = v8332 == ((int)((unsigned int)v8323 >> 2));
    int v8369;
    if (v8386) {
      int * v8333 = v8319->cache_keys;
      int * v8334 = v8319->cache_keys;
      int v8335 = v8334[0];
      v8333[1] = v8335;
      int * v8337 = v8319->cache_vals;
      int * v8338 = v8319->cache_vals;
      int v8339 = v8338[0];
      v8337[1] = v8339;
      int * v8341 = v8319->cache_keys;
      int v8394 = (int)((unsigned int)v8323 >> 2);
      v8341[0] = v8394;
      int * v8343 = v8319->cache_vals;
      v8343[0] = v8325;
      int v8345 = v8319->timer;
      int v8397 = v8345 + 1;
      v8319->timer = v8397;
      v8369 = v8325;
    } else {
      int * v8348 = v8319->mem;
      int * v8349 = v8319->cache_keys;
      int v8350 = v8349[1];
      int * v8351 = v8319->cache_vals;
      int v8352 = v8351[1];
      v8348[v8350] = v8352;
      int * v8354 = v8319->cache_keys;
      int * v8355 = v8319->cache_keys;
      int v8356 = v8355[0];
      v8354[1] = v8356;
      int * v8358 = v8319->cache_vals;
      int * v8359 = v8319->cache_vals;
      int v8360 = v8359[0];
      v8358[1] = v8360;
      int * v8362 = v8319->cache_keys;
      int v8410 = (int)((unsigned int)v8323 >> 2);
      v8362[0] = v8410;
      int * v8364 = v8319->cache_vals;
      v8364[0] = v8325;
      int v8366 = v8319->timer;
      int v8413 = v8366 + 100;
      v8319->timer = v8413;
      v8369 = v8325;
    }
    v8371 = v8369;
  }
  struct StateT * v8372 = slot_247(v8319);
  return v8372;
}

struct StateT * slot_210(struct StateT * v14272) {
  int v14273 = v14272->timer;
  int v14283 = v14273 + 1;
  v14272->timer = v14283;
  int * v14275 = v14272->regs;
  int v14276 = v14275[22];
  int * v14277 = v14272->regs;
  int v14278 = v14277[8];
  int * v14279 = v14272->regs;
  int v14289 = v14276 ^ v14278;
  v14279[22] = v14289;
  struct StateT * v14281 = slot_211(v14272);
  return v14281;
}

struct StateT * slot_166(struct StateT * v13439) {
  int v13440 = v13439->timer;
  int v13450 = v13440 + 1;
  v13439->timer = v13450;
  int * v13442 = v13439->regs;
  int v13443 = v13442[8];
  int * v13444 = v13439->regs;
  int v13445 = v13444[9];
  int * v13446 = v13439->regs;
  int v13456 = v13443 | v13445;
  v13446[8] = v13456;
  struct StateT * v13448 = slot_167(v13439);
  return v13448;
}

struct StateT * slot_51(struct StateT * v6339) {
  int v6340 = v6339->timer;
  int v6350 = v6340 + 1;
  v6339->timer = v6350;
  int * v6342 = v6339->regs;
  int v6343 = v6342[21];
  int * v6344 = v6339->regs;
  int v6345 = v6344[16];
  int * v6346 = v6339->regs;
  int v6357 = v6343 + v6345;
  v6346[15] = v6357;
  struct StateT * v6348 = slot_52(v6339);
  return v6348;
}

struct StateT * slot_52(struct StateT * v6380) {
  int v6381 = v6380->timer;
  int v6391 = v6381 + 1;
  v6380->timer = v6391;
  int * v6383 = v6380->regs;
  int v6384 = v6383[11];
  int * v6385 = v6380->regs;
  int v6386 = v6385[23];
  int * v6387 = v6380->regs;
  int v6398 = v6384 + v6386;
  v6387[20] = v6398;
  struct StateT * v6389 = slot_53(v6380);
  return v6389;
}

struct StateT * slot_83(struct StateT * v8299) {
  int v8300 = v8299->timer;
  int v8310 = v8300 + 1;
  v8299->timer = v8310;
  int * v8302 = v8299->regs;
  int v8303 = v8302[9];
  int * v8304 = v8299->regs;
  int v8305 = v8304[20];
  int * v8306 = v8299->regs;
  int v8316 = v8303 | v8305;
  v8306[9] = v8316;
  struct StateT * v8308 = slot_84(v8299);
  return v8308;
}

struct StateT * slot_25(struct StateT * v2741) {
  int v2742 = v2741->timer;
  int v2800 = v2742 + 1;
  v2741->timer = v2800;
  int * v2744 = v2741->regs;
  int v2745 = v2744[11];
  int * v2746 = v2741->cache_keys;
  int v2747 = v2746[0];
  bool v2805 = v2747 == ((int)((unsigned int)(v2745 + 8) >> 2));
  int v2795;
  if (v2805) {
    int * v2748 = v2741->cache_vals;
    int v2749 = v2748[0];
    v2795 = v2749;
  } else {
    int * v2751 = v2741->cache_keys;
    int v2752 = v2751[1];
    bool v2810 = v2752 == ((int)((unsigned int)(v2745 + 8) >> 2));
    int v2793;
    if (v2810) {
      int * v2753 = v2741->cache_vals;
      int v2754 = v2753[1];
      int * v2755 = v2741->cache_keys;
      int * v2756 = v2741->cache_keys;
      int v2757 = v2756[0];
      v2755[1] = v2757;
      int * v2759 = v2741->cache_vals;
      int * v2760 = v2741->cache_vals;
      int v2761 = v2760[0];
      v2759[1] = v2761;
      int * v2763 = v2741->cache_keys;
      int v2819 = (int)((unsigned int)(v2745 + 8) >> 2);
      v2763[0] = v2819;
      int * v2765 = v2741->cache_vals;
      v2765[0] = v2754;
      int v2767 = v2741->timer;
      int v2822 = v2767 + 1;
      v2741->timer = v2822;
      v2793 = v2754;
    } else {
      int * v2770 = v2741->mem;
      int v2824 = (int)((unsigned int)(v2745 + 8) >> 2);
      int v2771 = v2770[v2824];
      int * v2772 = v2741->mem;
      int * v2773 = v2741->cache_keys;
      int v2774 = v2773[1];
      int * v2775 = v2741->cache_vals;
      int v2776 = v2775[1];
      v2772[v2774] = v2776;
      int * v2778 = v2741->cache_keys;
      int * v2779 = v2741->cache_keys;
      int v2780 = v2779[0];
      v2778[1] = v2780;
      int * v2782 = v2741->cache_vals;
      int * v2783 = v2741->cache_vals;
      int v2784 = v2783[0];
      v2782[1] = v2784;
      int * v2786 = v2741->cache_keys;
      v2786[0] = v2824;
      int * v2788 = v2741->cache_vals;
      v2788[0] = v2771;
      int v2790 = v2741->timer;
      int v2839 = v2790 + 100;
      v2741->timer = v2839;
      v2793 = v2771;
    }
    v2795 = v2793;
  }
  int * v2796 = v2741->regs;
  v2796[26] = v2795;
  struct StateT * v2798 = slot_26(v2741);
  return v2798;
}

struct StateT * slot_209(struct StateT * v14252) {
  int v14253 = v14252->timer;
  int v14263 = v14253 + 1;
  v14252->timer = v14263;
  int * v14255 = v14252->regs;
  int v14256 = v14255[19];
  int * v14257 = v14252->regs;
  int v14258 = v14257[6];
  int * v14259 = v14252->regs;
  int v14269 = v14256 ^ v14258;
  v14259[19] = v14269;
  struct StateT * v14261 = slot_210(v14252);
  return v14261;
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

struct StateT * slot_264(struct StateT * v11267) {
  int v11268 = v11267->timer;
  int v11326 = v11268 + 1;
  v11267->timer = v11326;
  int * v11270 = v11267->regs;
  int v11271 = v11270[2];
  int * v11272 = v11267->cache_keys;
  int v11273 = v11272[0];
  bool v11331 = v11273 == ((int)((unsigned int)(v11271 + 84) >> 2));
  int v11321;
  if (v11331) {
    int * v11274 = v11267->cache_vals;
    int v11275 = v11274[0];
    v11321 = v11275;
  } else {
    int * v11277 = v11267->cache_keys;
    int v11278 = v11277[1];
    bool v11336 = v11278 == ((int)((unsigned int)(v11271 + 84) >> 2));
    int v11319;
    if (v11336) {
      int * v11279 = v11267->cache_vals;
      int v11280 = v11279[1];
      int * v11281 = v11267->cache_keys;
      int * v11282 = v11267->cache_keys;
      int v11283 = v11282[0];
      v11281[1] = v11283;
      int * v11285 = v11267->cache_vals;
      int * v11286 = v11267->cache_vals;
      int v11287 = v11286[0];
      v11285[1] = v11287;
      int * v11289 = v11267->cache_keys;
      int v11345 = (int)((unsigned int)(v11271 + 84) >> 2);
      v11289[0] = v11345;
      int * v11291 = v11267->cache_vals;
      v11291[0] = v11280;
      int v11293 = v11267->timer;
      int v11348 = v11293 + 1;
      v11267->timer = v11348;
      v11319 = v11280;
    } else {
      int * v11296 = v11267->mem;
      int v11350 = (int)((unsigned int)(v11271 + 84) >> 2);
      int v11297 = v11296[v11350];
      int * v11298 = v11267->mem;
      int * v11299 = v11267->cache_keys;
      int v11300 = v11299[1];
      int * v11301 = v11267->cache_vals;
      int v11302 = v11301[1];
      v11298[v11300] = v11302;
      int * v11304 = v11267->cache_keys;
      int * v11305 = v11267->cache_keys;
      int v11306 = v11305[0];
      v11304[1] = v11306;
      int * v11308 = v11267->cache_vals;
      int * v11309 = v11267->cache_vals;
      int v11310 = v11309[0];
      v11308[1] = v11310;
      int * v11312 = v11267->cache_keys;
      v11312[0] = v11350;
      int * v11314 = v11267->cache_vals;
      v11314[0] = v11297;
      int v11316 = v11267->timer;
      int v11365 = v11316 + 100;
      v11267->timer = v11365;
      v11319 = v11297;
    }
    v11321 = v11319;
  }
  int * v11322 = v11267->regs;
  v11322[9] = v11321;
  struct StateT * v11324 = slot_265(v11267);
  return v11324;
}

struct StateT * slot_123(struct StateT * v12629) {
  int v12630 = v12629->timer;
  int v12640 = v12630 + 1;
  v12629->timer = v12640;
  int * v12632 = v12629->regs;
  int v12633 = v12632[17];
  int * v12634 = v12629->regs;
  int v12635 = v12634[6];
  int * v12636 = v12629->regs;
  int v12646 = v12633 | v12635;
  v12636[17] = v12646;
  struct StateT * v12638 = slot_124(v12629);
  return v12638;
}

struct StateT * slot_73(struct StateT * v7941) {
  int v7942 = v7941->timer;
  int v7952 = v7942 + 1;
  v7941->timer = v7952;
  int * v7944 = v7941->regs;
  int v7945 = v7944[1];
  int * v7946 = v7941->regs;
  int v7947 = v7946[19];
  int * v7948 = v7941->regs;
  int v7959 = v7945 + v7947;
  v7948[9] = v7959;
  struct StateT * v7950 = slot_74(v7941);
  return v7950;
}

struct StateT * slot_270(struct StateT * v11723) {
  int v11724 = v11723->timer;
  int v11782 = v11724 + 1;
  v11723->timer = v11782;
  int * v11726 = v11723->regs;
  int v11727 = v11726[2];
  int * v11728 = v11723->cache_keys;
  int v11729 = v11728[0];
  bool v11787 = v11729 == ((int)((unsigned int)(v11727 + 60) >> 2));
  int v11777;
  if (v11787) {
    int * v11730 = v11723->cache_vals;
    int v11731 = v11730[0];
    v11777 = v11731;
  } else {
    int * v11733 = v11723->cache_keys;
    int v11734 = v11733[1];
    bool v11792 = v11734 == ((int)((unsigned int)(v11727 + 60) >> 2));
    int v11775;
    if (v11792) {
      int * v11735 = v11723->cache_vals;
      int v11736 = v11735[1];
      int * v11737 = v11723->cache_keys;
      int * v11738 = v11723->cache_keys;
      int v11739 = v11738[0];
      v11737[1] = v11739;
      int * v11741 = v11723->cache_vals;
      int * v11742 = v11723->cache_vals;
      int v11743 = v11742[0];
      v11741[1] = v11743;
      int * v11745 = v11723->cache_keys;
      int v11801 = (int)((unsigned int)(v11727 + 60) >> 2);
      v11745[0] = v11801;
      int * v11747 = v11723->cache_vals;
      v11747[0] = v11736;
      int v11749 = v11723->timer;
      int v11804 = v11749 + 1;
      v11723->timer = v11804;
      v11775 = v11736;
    } else {
      int * v11752 = v11723->mem;
      int v11806 = (int)((unsigned int)(v11727 + 60) >> 2);
      int v11753 = v11752[v11806];
      int * v11754 = v11723->mem;
      int * v11755 = v11723->cache_keys;
      int v11756 = v11755[1];
      int * v11757 = v11723->cache_vals;
      int v11758 = v11757[1];
      v11754[v11756] = v11758;
      int * v11760 = v11723->cache_keys;
      int * v11761 = v11723->cache_keys;
      int v11762 = v11761[0];
      v11760[1] = v11762;
      int * v11764 = v11723->cache_vals;
      int * v11765 = v11723->cache_vals;
      int v11766 = v11765[0];
      v11764[1] = v11766;
      int * v11768 = v11723->cache_keys;
      v11768[0] = v11806;
      int * v11770 = v11723->cache_vals;
      v11770[0] = v11753;
      int v11772 = v11723->timer;
      int v11821 = v11772 + 100;
      v11723->timer = v11821;
      v11775 = v11753;
    }
    v11777 = v11775;
  }
  int * v11778 = v11723->regs;
  v11778[23] = v11777;
  struct StateT * v11780 = slot_271(v11723);
  return v11780;
}

struct StateT * slot_198(struct StateT * v14052) {
  int v14053 = v14052->timer;
  int v14061 = v14053 + 1;
  v14052->timer = v14061;
  int * v14055 = v14052->regs;
  int v14056 = v14055[15];
  int * v14057 = v14052->regs;
  int v14066 = (int)((unsigned int)v14056 >> 14);
  v14057[9] = v14066;
  struct StateT * v14059 = slot_199(v14052);
  return v14059;
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

struct StateT * slot_187(struct StateT * v13835) {
  int v13836 = v13835->timer;
  int v13846 = v13836 + 1;
  v13835->timer = v13846;
  int * v13838 = v13835->regs;
  int v13839 = v13838[14];
  int * v13840 = v13835->regs;
  int v13841 = v13840[11];
  int * v13842 = v13835->regs;
  int v13852 = v13839 ^ v13841;
  v13842[14] = v13852;
  struct StateT * v13844 = slot_188(v13835);
  return v13844;
}

struct StateT * slot_97(struct StateT * v9941) {
  int v9942 = v9941->timer;
  int v9952 = v9942 + 1;
  v9941->timer = v9952;
  int * v9944 = v9941->regs;
  int v9945 = v9944[15];
  int * v9946 = v9941->regs;
  int v9947 = v9946[20];
  int * v9948 = v9941->regs;
  int v9958 = v9945 | v9947;
  v9948[15] = v9958;
  struct StateT * v9950 = slot_98(v9941);
  return v9950;
}

struct StateT * slot_182(struct StateT * v13746) {
  int v13747 = v13746->timer;
  int v13755 = v13747 + 1;
  v13746->timer = v13755;
  int * v13749 = v13746->regs;
  int v13750 = v13749[6];
  int * v13751 = v13746->regs;
  int v13759 = v13750 << 13;
  v13751[6] = v13759;
  struct StateT * v13753 = slot_183(v13746);
  return v13753;
}

struct StateT * slot_38(struct StateT * v3279) {
  int v3280 = v3279->timer;
  int v3334 = v3280 + 1;
  v3279->timer = v3334;
  int * v3282 = v3279->regs;
  int v3283 = v3282[2];
  int * v3284 = v3279->regs;
  int v3285 = v3284[5];
  int * v3286 = v3279->cache_keys;
  int v3287 = v3286[0];
  bool v3341 = v3287 == ((int)((unsigned int)(v3283 + 12) >> 2));
  int v3331;
  if (v3341) {
    int * v3288 = v3279->cache_vals;
    v3288[0] = v3285;
    v3331 = v3285;
  } else {
    int * v3291 = v3279->cache_keys;
    int v3292 = v3291[1];
    bool v3346 = v3292 == ((int)((unsigned int)(v3283 + 12) >> 2));
    int v3329;
    if (v3346) {
      int * v3293 = v3279->cache_keys;
      int * v3294 = v3279->cache_keys;
      int v3295 = v3294[0];
      v3293[1] = v3295;
      int * v3297 = v3279->cache_vals;
      int * v3298 = v3279->cache_vals;
      int v3299 = v3298[0];
      v3297[1] = v3299;
      int * v3301 = v3279->cache_keys;
      int v3354 = (int)((unsigned int)(v3283 + 12) >> 2);
      v3301[0] = v3354;
      int * v3303 = v3279->cache_vals;
      v3303[0] = v3285;
      int v3305 = v3279->timer;
      int v3357 = v3305 + 1;
      v3279->timer = v3357;
      v3329 = v3285;
    } else {
      int * v3308 = v3279->mem;
      int * v3309 = v3279->cache_keys;
      int v3310 = v3309[1];
      int * v3311 = v3279->cache_vals;
      int v3312 = v3311[1];
      v3308[v3310] = v3312;
      int * v3314 = v3279->cache_keys;
      int * v3315 = v3279->cache_keys;
      int v3316 = v3315[0];
      v3314[1] = v3316;
      int * v3318 = v3279->cache_vals;
      int * v3319 = v3279->cache_vals;
      int v3320 = v3319[0];
      v3318[1] = v3320;
      int * v3322 = v3279->cache_keys;
      int v3370 = (int)((unsigned int)(v3283 + 12) >> 2);
      v3322[0] = v3370;
      int * v3324 = v3279->cache_vals;
      v3324[0] = v3285;
      int v3326 = v3279->timer;
      int v3373 = v3326 + 100;
      v3279->timer = v3373;
      v3329 = v3285;
    }
    v3331 = v3329;
  }
  struct StateT * v3332 = slot_39(v3279);
  return v3332;
}

struct StateT * slot_178(struct StateT * v13676) {
  int v13677 = v13676->timer;
  int v13685 = v13677 + 1;
  v13676->timer = v13685;
  int * v13679 = v13676->regs;
  int v13680 = v13679[15];
  int * v13681 = v13676->regs;
  int v13690 = (int)((unsigned int)v13680 >> 19);
  v13681[9] = v13690;
  struct StateT * v13683 = slot_179(v13676);
  return v13683;
}

struct StateT * slot_106(struct StateT * v12071) {
  int v12072 = v12071->timer;
  int v12082 = v12072 + 1;
  v12071->timer = v12082;
  int * v12074 = v12071->regs;
  int v12075 = v12074[18];
  int * v12076 = v12071->regs;
  int v12077 = v12076[9];
  int * v12078 = v12071->regs;
  int v12089 = v12075 | v12077;
  v12078[6] = v12089;
  struct StateT * v12080 = slot_107(v12071);
  return v12080;
}

struct StateT * slot_98(struct StateT * v10058) {
  int v10059 = v10058->timer;
  int v10067 = v10059 + 1;
  v10058->timer = v10067;
  int * v10061 = v10058->regs;
  int v10062 = v10061[8];
  int * v10063 = v10058->regs;
  int v10072 = (int)((unsigned int)v10062 >> 19);
  v10063[20] = v10072;
  struct StateT * v10065 = slot_99(v10058);
  return v10065;
}

struct StateT * slot_159(struct StateT * v13317) {
  int v13318 = v13317->timer;
  int v13326 = v13318 + 1;
  v13317->timer = v13326;
  int * v13320 = v13317->regs;
  int v13321 = v13320[15];
  int * v13322 = v13317->regs;
  int v13330 = v13321 << 9;
  v13322[15] = v13330;
  struct StateT * v13324 = slot_160(v13317);
  return v13324;
}

struct StateT * slot_212(struct StateT * v14308) {
  int v14309 = v14308->timer;
  int v14321 = v14309 + 1;
  v14308->timer = v14321;
  int * v14311 = v14308->regs;
  int v14312 = v14311[31];
  int * v14313 = v14308->regs;
  int v14314 = v14313[30];
  bool v14326 = (v14312 ^ -2147483648) >= (v14314 ^ -2147483648);
  struct StateT * v14319;
  if (v14326) {
    struct StateT * v14315 = slot_51(v14308);
    v14319 = v14315;
  } else {
    struct StateT * v14317 = slot_213(v14308);
    v14319 = v14317;
  }
  return v14319;
}

struct StateT * slot_132(struct StateT * v12804) {
  int v12805 = v12804->timer;
  int v12815 = v12805 + 1;
  v12804->timer = v12815;
  int * v12807 = v12804->regs;
  int v12808 = v12807[20];
  int * v12809 = v12804->regs;
  int v12810 = v12809[12];
  int * v12811 = v12804->regs;
  int v12822 = v12808 + v12810;
  v12811[11] = v12822;
  struct StateT * v12813 = slot_133(v12804);
  return v12813;
}

struct StateT * slot_130(struct StateT * v12763) {
  int v12764 = v12763->timer;
  int v12774 = v12764 + 1;
  v12763->timer = v12774;
  int * v12766 = v12763->regs;
  int v12767 = v12766[22];
  int * v12768 = v12763->regs;
  int v12769 = v12768[5];
  int * v12770 = v12763->regs;
  int v12780 = v12767 ^ v12769;
  v12770[22] = v12780;
  struct StateT * v12772 = slot_131(v12763);
  return v12772;
}

struct StateT * slot_211(struct StateT * v14292) {
  int v14293 = v14292->timer;
  int v14301 = v14293 + 1;
  v14292->timer = v14301;
  int * v14295 = v14292->regs;
  int v14296 = v14295[30];
  int * v14297 = v14292->regs;
  int v14305 = v14296 + 1;
  v14297[30] = v14305;
  struct StateT * v14299 = slot_212(v14292);
  return v14299;
}

struct StateT * slot_20(struct StateT * v2111) {
  int v2112 = v2111->timer;
  int v2170 = v2112 + 1;
  v2111->timer = v2170;
  int * v2114 = v2111->regs;
  int v2115 = v2114[12];
  int * v2116 = v2111->cache_keys;
  int v2117 = v2116[0];
  bool v2175 = v2117 == ((int)((unsigned int)(v2115 + 20) >> 2));
  int v2165;
  if (v2175) {
    int * v2118 = v2111->cache_vals;
    int v2119 = v2118[0];
    v2165 = v2119;
  } else {
    int * v2121 = v2111->cache_keys;
    int v2122 = v2121[1];
    bool v2180 = v2122 == ((int)((unsigned int)(v2115 + 20) >> 2));
    int v2163;
    if (v2180) {
      int * v2123 = v2111->cache_vals;
      int v2124 = v2123[1];
      int * v2125 = v2111->cache_keys;
      int * v2126 = v2111->cache_keys;
      int v2127 = v2126[0];
      v2125[1] = v2127;
      int * v2129 = v2111->cache_vals;
      int * v2130 = v2111->cache_vals;
      int v2131 = v2130[0];
      v2129[1] = v2131;
      int * v2133 = v2111->cache_keys;
      int v2189 = (int)((unsigned int)(v2115 + 20) >> 2);
      v2133[0] = v2189;
      int * v2135 = v2111->cache_vals;
      v2135[0] = v2124;
      int v2137 = v2111->timer;
      int v2192 = v2137 + 1;
      v2111->timer = v2192;
      v2163 = v2124;
    } else {
      int * v2140 = v2111->mem;
      int v2194 = (int)((unsigned int)(v2115 + 20) >> 2);
      int v2141 = v2140[v2194];
      int * v2142 = v2111->mem;
      int * v2143 = v2111->cache_keys;
      int v2144 = v2143[1];
      int * v2145 = v2111->cache_vals;
      int v2146 = v2145[1];
      v2142[v2144] = v2146;
      int * v2148 = v2111->cache_keys;
      int * v2149 = v2111->cache_keys;
      int v2150 = v2149[0];
      v2148[1] = v2150;
      int * v2152 = v2111->cache_vals;
      int * v2153 = v2111->cache_vals;
      int v2154 = v2153[0];
      v2152[1] = v2154;
      int * v2156 = v2111->cache_keys;
      v2156[0] = v2194;
      int * v2158 = v2111->cache_vals;
      v2158[0] = v2141;
      int v2160 = v2111->timer;
      int v2209 = v2160 + 100;
      v2111->timer = v2209;
      v2163 = v2141;
    }
    v2165 = v2163;
  }
  int * v2166 = v2111->regs;
  v2166[16] = v2165;
  struct StateT * v2168 = slot_21(v2111);
  return v2168;
}

struct StateT * slot_141(struct StateT * v12973) {
  int v12974 = v12973->timer;
  int v12982 = v12974 + 1;
  v12973->timer = v12982;
  int * v12976 = v12973->regs;
  int v12977 = v12976[16];
  int * v12978 = v12973->regs;
  int v12987 = (int)((unsigned int)v12977 >> 25);
  v12978[5] = v12987;
  struct StateT * v12980 = slot_142(v12973);
  return v12980;
}

struct StateT * slot_61(struct StateT * v6970) {
  int v6971 = v6970->timer;
  int v6979 = v6971 + 1;
  v6970->timer = v6979;
  int * v6973 = v6970->regs;
  int v6974 = v6973[18];
  int * v6975 = v6970->regs;
  int v6984 = (int)((unsigned int)v6974 >> 25);
  v6975[20] = v6984;
  struct StateT * v6977 = slot_62(v6970);
  return v6977;
}

struct StateT * slot_30(struct StateT * v2990) {
  int v2991 = v2990->timer;
  int v2999 = v2991 + 1;
  v2990->timer = v2999;
  int * v2993 = v2990->regs;
  int v2994 = v2993[12];
  int * v2995 = v2990->regs;
  int v3004 = v2994 + -1947;
  v2995[21] = v3004;
  struct StateT * v2997 = slot_31(v2990);
  return v2997;
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

struct StateT * slot_18(struct StateT * v1691) {
  int v1692 = v1691->timer;
  int v1750 = v1692 + 1;
  v1691->timer = v1750;
  int * v1694 = v1691->regs;
  int v1695 = v1694[12];
  int * v1696 = v1691->cache_keys;
  int v1697 = v1696[0];
  bool v1755 = v1697 == ((int)((unsigned int)(v1695 + 12) >> 2));
  int v1745;
  if (v1755) {
    int * v1698 = v1691->cache_vals;
    int v1699 = v1698[0];
    v1745 = v1699;
  } else {
    int * v1701 = v1691->cache_keys;
    int v1702 = v1701[1];
    bool v1760 = v1702 == ((int)((unsigned int)(v1695 + 12) >> 2));
    int v1743;
    if (v1760) {
      int * v1703 = v1691->cache_vals;
      int v1704 = v1703[1];
      int * v1705 = v1691->cache_keys;
      int * v1706 = v1691->cache_keys;
      int v1707 = v1706[0];
      v1705[1] = v1707;
      int * v1709 = v1691->cache_vals;
      int * v1710 = v1691->cache_vals;
      int v1711 = v1710[0];
      v1709[1] = v1711;
      int * v1713 = v1691->cache_keys;
      int v1769 = (int)((unsigned int)(v1695 + 12) >> 2);
      v1713[0] = v1769;
      int * v1715 = v1691->cache_vals;
      v1715[0] = v1704;
      int v1717 = v1691->timer;
      int v1772 = v1717 + 1;
      v1691->timer = v1772;
      v1743 = v1704;
    } else {
      int * v1720 = v1691->mem;
      int v1774 = (int)((unsigned int)(v1695 + 12) >> 2);
      int v1721 = v1720[v1774];
      int * v1722 = v1691->mem;
      int * v1723 = v1691->cache_keys;
      int v1724 = v1723[1];
      int * v1725 = v1691->cache_vals;
      int v1726 = v1725[1];
      v1722[v1724] = v1726;
      int * v1728 = v1691->cache_keys;
      int * v1729 = v1691->cache_keys;
      int v1730 = v1729[0];
      v1728[1] = v1730;
      int * v1732 = v1691->cache_vals;
      int * v1733 = v1691->cache_vals;
      int v1734 = v1733[0];
      v1732[1] = v1734;
      int * v1736 = v1691->cache_keys;
      v1736[0] = v1774;
      int * v1738 = v1691->cache_vals;
      v1738[0] = v1721;
      int v1740 = v1691->timer;
      int v1789 = v1740 + 100;
      v1691->timer = v1789;
      v1743 = v1721;
    }
    v1745 = v1743;
  }
  int * v1746 = v1691->regs;
  v1746[6] = v1745;
  struct StateT * v1748 = slot_19(v1691);
  return v1748;
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

struct StateT * slot_183(struct StateT * v13762) {
  int v13763 = v13762->timer;
  int v13773 = v13763 + 1;
  v13762->timer = v13773;
  int * v13765 = v13762->regs;
  int v13766 = v13765[6];
  int * v13767 = v13762->regs;
  int v13768 = v13767[9];
  int * v13769 = v13762->regs;
  int v13779 = v13766 | v13768;
  v13769[6] = v13779;
  struct StateT * v13771 = slot_184(v13762);
  return v13771;
}

struct StateT * slot_240(struct StateT * v8101) {
  int v8102 = v8101->timer;
  int v8110 = v8102 + 1;
  v8101->timer = v8110;
  int * v8104 = v8101->regs;
  int v8105 = v8104[7];
  int * v8106 = v8101->regs;
  int v8114 = v8105 + -718;
  v8106[7] = v8114;
  struct StateT * v8108 = slot_241(v8101);
  return v8108;
}

struct StateT * slot_247(struct StateT * v8434) {
  int v8435 = v8434->timer;
  int v8489 = v8435 + 1;
  v8434->timer = v8489;
  int * v8437 = v8434->regs;
  int v8438 = v8437[10];
  int * v8439 = v8434->regs;
  int v8440 = v8439[29];
  int * v8441 = v8434->cache_keys;
  int v8442 = v8441[0];
  bool v8496 = v8442 == ((int)((unsigned int)(v8438 + 4) >> 2));
  int v8486;
  if (v8496) {
    int * v8443 = v8434->cache_vals;
    v8443[0] = v8440;
    v8486 = v8440;
  } else {
    int * v8446 = v8434->cache_keys;
    int v8447 = v8446[1];
    bool v8501 = v8447 == ((int)((unsigned int)(v8438 + 4) >> 2));
    int v8484;
    if (v8501) {
      int * v8448 = v8434->cache_keys;
      int * v8449 = v8434->cache_keys;
      int v8450 = v8449[0];
      v8448[1] = v8450;
      int * v8452 = v8434->cache_vals;
      int * v8453 = v8434->cache_vals;
      int v8454 = v8453[0];
      v8452[1] = v8454;
      int * v8456 = v8434->cache_keys;
      int v8509 = (int)((unsigned int)(v8438 + 4) >> 2);
      v8456[0] = v8509;
      int * v8458 = v8434->cache_vals;
      v8458[0] = v8440;
      int v8460 = v8434->timer;
      int v8512 = v8460 + 1;
      v8434->timer = v8512;
      v8484 = v8440;
    } else {
      int * v8463 = v8434->mem;
      int * v8464 = v8434->cache_keys;
      int v8465 = v8464[1];
      int * v8466 = v8434->cache_vals;
      int v8467 = v8466[1];
      v8463[v8465] = v8467;
      int * v8469 = v8434->cache_keys;
      int * v8470 = v8434->cache_keys;
      int v8471 = v8470[0];
      v8469[1] = v8471;
      int * v8473 = v8434->cache_vals;
      int * v8474 = v8434->cache_vals;
      int v8475 = v8474[0];
      v8473[1] = v8475;
      int * v8477 = v8434->cache_keys;
      int v8525 = (int)((unsigned int)(v8438 + 4) >> 2);
      v8477[0] = v8525;
      int * v8479 = v8434->cache_vals;
      v8479[0] = v8440;
      int v8481 = v8434->timer;
      int v8528 = v8481 + 100;
      v8434->timer = v8528;
      v8484 = v8440;
    }
    v8486 = v8484;
  }
  struct StateT * v8487 = slot_248(v8434);
  return v8487;
}

struct StateT * slot_43(struct StateT * v3768) {
  int v3769 = v3768->timer;
  int v3863 = v3769 + 1;
  v3768->timer = v3863;
  int * v3771 = v3768->regs;
  int v3772 = v3771[2];
  int * v3773 = v3768->regs;
  int v3774 = v3773[6];
  int * v3775 = v3768->saved_regs;
  int * v3776 = v3768->regs;
  int v3777 = v3776[12];
  v3775[12] = v3777;
  int v3779 = v3768->timer;
  int v3872 = v3779 + 1;
  v3768->timer = v3872;
  int * v3781 = v3768->regs;
  int v3782 = v3781[6];
  int * v3783 = v3768->regs;
  v3783[12] = v3782;
  int * v3785 = v3768->saved_regs;
  int * v3786 = v3768->regs;
  int v3787 = v3786[14];
  v3785[14] = v3787;
  int v3789 = v3768->timer;
  int v3880 = v3789 + 1;
  v3768->timer = v3880;
  int * v3791 = v3768->regs;
  int v3792 = v3791[7];
  int * v3793 = v3768->regs;
  v3793[14] = v3792;
  int * v3795 = v3768->saved_regs;
  int * v3796 = v3768->regs;
  int v3797 = v3796[27];
  v3795[27] = v3797;
  int v3799 = v3768->timer;
  int v3889 = v3799 + 1;
  v3768->timer = v3889;
  int * v3801 = v3768->regs;
  int v3802 = v3801[28];
  int * v3803 = v3768->regs;
  v3803[27] = v3802;
  int * v3805 = v3768->saved_regs;
  int * v3806 = v3768->regs;
  int v3807 = v3806[23];
  v3805[23] = v3807;
  int v3809 = v3768->timer;
  int v3898 = v3809 + 1;
  v3768->timer = v3898;
  int * v3811 = v3768->regs;
  int v3812 = v3811[29];
  int * v3813 = v3768->regs;
  v3813[23] = v3812;
  int * v3815 = v3768->cache_keys;
  int v3816 = v3815[0];
  bool v3905 = v3816 == ((int)((unsigned int)(v3772 + 8) >> 2));
  int v3860;
  if (v3905) {
    int * v3817 = v3768->cache_vals;
    v3817[0] = v3774;
    v3860 = v3774;
  } else {
    int * v3820 = v3768->cache_keys;
    int v3821 = v3820[1];
    bool v3910 = v3821 == ((int)((unsigned int)(v3772 + 8) >> 2));
    int v3858;
    if (v3910) {
      int * v3822 = v3768->cache_keys;
      int * v3823 = v3768->cache_keys;
      int v3824 = v3823[0];
      v3822[1] = v3824;
      int * v3826 = v3768->cache_vals;
      int * v3827 = v3768->cache_vals;
      int v3828 = v3827[0];
      v3826[1] = v3828;
      int * v3830 = v3768->cache_keys;
      int v3918 = (int)((unsigned int)(v3772 + 8) >> 2);
      v3830[0] = v3918;
      int * v3832 = v3768->cache_vals;
      v3832[0] = v3774;
      int v3834 = v3768->timer;
      int v3921 = v3834 + 1;
      v3768->timer = v3921;
      v3858 = v3774;
    } else {
      int * v3837 = v3768->mem;
      int * v3838 = v3768->cache_keys;
      int v3839 = v3838[1];
      int * v3840 = v3768->cache_vals;
      int v3841 = v3840[1];
      v3837[v3839] = v3841;
      int * v3843 = v3768->cache_keys;
      int * v3844 = v3768->cache_keys;
      int v3845 = v3844[0];
      v3843[1] = v3845;
      int * v3847 = v3768->cache_vals;
      int * v3848 = v3768->cache_vals;
      int v3849 = v3848[0];
      v3847[1] = v3849;
      int * v3851 = v3768->cache_keys;
      int v3934 = (int)((unsigned int)(v3772 + 8) >> 2);
      v3851[0] = v3934;
      int * v3853 = v3768->cache_vals;
      v3853[0] = v3774;
      int v3855 = v3768->timer;
      int v3937 = v3855 + 100;
      v3768->timer = v3937;
      v3858 = v3774;
    }
    v3860 = v3858;
  }
  struct StateT * v3861 = slot_48(v3768);
  return v3861;
}

struct StateT * slot_70(struct StateT * v7649) {
  int v7650 = v7649->timer;
  int v7660 = v7650 + 1;
  v7649->timer = v7660;
  int * v7652 = v7649->regs;
  int v7653 = v7652[14];
  int * v7654 = v7649->regs;
  int v7655 = v7654[8];
  int * v7656 = v7649->regs;
  int v7666 = v7653 ^ v7655;
  v7656[14] = v7666;
  struct StateT * v7658 = slot_71(v7649);
  return v7658;
}

struct StateT * slot_168(struct StateT * v13479) {
  int v13480 = v13479->timer;
  int v13490 = v13480 + 1;
  v13479->timer = v13490;
  int * v13482 = v13479->regs;
  int v13483 = v13482[25];
  int * v13484 = v13479->regs;
  int v13485 = v13484[15];
  int * v13486 = v13479->regs;
  int v13496 = v13483 ^ v13485;
  v13486[25] = v13496;
  struct StateT * v13488 = slot_169(v13479);
  return v13488;
}

struct StateT * slot_76(struct StateT * v8049) {
  int v8050 = v8049->timer;
  int v8058 = v8050 + 1;
  v8049->timer = v8058;
  int * v8052 = v8049->regs;
  int v8053 = v8052[15];
  int * v8054 = v8049->regs;
  int v8062 = v8053 << 9;
  v8054[15] = v8062;
  struct StateT * v8056 = slot_77(v8049);
  return v8056;
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

struct StateT * slot_225(struct StateT * v7108) {
  int v7109 = v7108->timer;
  int v7119 = v7109 + 1;
  v7108->timer = v7119;
  int * v7111 = v7108->regs;
  int v7112 = v7111[26];
  int * v7113 = v7108->regs;
  int v7114 = v7113[7];
  int * v7115 = v7108->regs;
  int v7125 = v7112 + v7114;
  v7115[26] = v7125;
  struct StateT * v7117 = slot_226(v7108);
  return v7117;
}

struct StateT * slot_55(struct StateT * v6581) {
  int v6582 = v6581->timer;
  int v6590 = v6582 + 1;
  v6581->timer = v6590;
  int * v6584 = v6581->regs;
  int v6585 = v6584[15];
  int * v6586 = v6581->regs;
  int v6595 = (int)((unsigned int)v6585 >> 25);
  v6586[9] = v6595;
  struct StateT * v6588 = slot_56(v6581);
  return v6588;
}

struct StateT * slot_213(struct StateT * v6319) {
  int v6320 = v6319->timer;
  int v6330 = v6320 + 1;
  v6319->timer = v6330;
  int * v6322 = v6319->regs;
  int v6323 = v6322[23];
  int * v6324 = v6319->regs;
  int v6325 = v6324[29];
  int * v6326 = v6319->regs;
  int v6336 = v6323 + v6325;
  v6326[29] = v6336;
  struct StateT * v6328 = slot_214(v6319);
  return v6328;
}

struct StateT * slot_82(struct StateT * v8263) {
  int v8264 = v8263->timer;
  int v8272 = v8264 + 1;
  v8263->timer = v8272;
  int * v8266 = v8263->regs;
  int v8267 = v8266[9];
  int * v8268 = v8263->regs;
  int v8276 = v8267 << 9;
  v8268[9] = v8276;
  struct StateT * v8270 = slot_83(v8263);
  return v8270;
}

struct StateT * slot_274(struct StateT * v12218) {
  int v12219 = v12218->timer;
  int v12277 = v12219 + 1;
  v12218->timer = v12277;
  int * v12221 = v12218->regs;
  int v12222 = v12221[2];
  int * v12223 = v12218->cache_keys;
  int v12224 = v12223[0];
  bool v12282 = v12224 == ((int)((unsigned int)(v12222 + 44) >> 2));
  int v12272;
  if (v12282) {
    int * v12225 = v12218->cache_vals;
    int v12226 = v12225[0];
    v12272 = v12226;
  } else {
    int * v12228 = v12218->cache_keys;
    int v12229 = v12228[1];
    bool v12287 = v12229 == ((int)((unsigned int)(v12222 + 44) >> 2));
    int v12270;
    if (v12287) {
      int * v12230 = v12218->cache_vals;
      int v12231 = v12230[1];
      int * v12232 = v12218->cache_keys;
      int * v12233 = v12218->cache_keys;
      int v12234 = v12233[0];
      v12232[1] = v12234;
      int * v12236 = v12218->cache_vals;
      int * v12237 = v12218->cache_vals;
      int v12238 = v12237[0];
      v12236[1] = v12238;
      int * v12240 = v12218->cache_keys;
      int v12296 = (int)((unsigned int)(v12222 + 44) >> 2);
      v12240[0] = v12296;
      int * v12242 = v12218->cache_vals;
      v12242[0] = v12231;
      int v12244 = v12218->timer;
      int v12299 = v12244 + 1;
      v12218->timer = v12299;
      v12270 = v12231;
    } else {
      int * v12247 = v12218->mem;
      int v12301 = (int)((unsigned int)(v12222 + 44) >> 2);
      int v12248 = v12247[v12301];
      int * v12249 = v12218->mem;
      int * v12250 = v12218->cache_keys;
      int v12251 = v12250[1];
      int * v12252 = v12218->cache_vals;
      int v12253 = v12252[1];
      v12249[v12251] = v12253;
      int * v12255 = v12218->cache_keys;
      int * v12256 = v12218->cache_keys;
      int v12257 = v12256[0];
      v12255[1] = v12257;
      int * v12259 = v12218->cache_vals;
      int * v12260 = v12218->cache_vals;
      int v12261 = v12260[0];
      v12259[1] = v12261;
      int * v12263 = v12218->cache_keys;
      v12263[0] = v12301;
      int * v12265 = v12218->cache_vals;
      v12265[0] = v12248;
      int v12267 = v12218->timer;
      int v12316 = v12267 + 100;
      v12218->timer = v12316;
      v12270 = v12248;
    }
    v12272 = v12270;
  }
  int * v12273 = v12218->regs;
  v12273[27] = v12272;
  struct StateT * v12275 = slot_275(v12218);
  return v12275;
}

struct StateT * slot_263(struct StateT * v11040) {
  int v11041 = v11040->timer;
  int v11099 = v11041 + 1;
  v11040->timer = v11099;
  int * v11043 = v11040->regs;
  int v11044 = v11043[2];
  int * v11045 = v11040->cache_keys;
  int v11046 = v11045[0];
  bool v11104 = v11046 == ((int)((unsigned int)(v11044 + 88) >> 2));
  int v11094;
  if (v11104) {
    int * v11047 = v11040->cache_vals;
    int v11048 = v11047[0];
    v11094 = v11048;
  } else {
    int * v11050 = v11040->cache_keys;
    int v11051 = v11050[1];
    bool v11109 = v11051 == ((int)((unsigned int)(v11044 + 88) >> 2));
    int v11092;
    if (v11109) {
      int * v11052 = v11040->cache_vals;
      int v11053 = v11052[1];
      int * v11054 = v11040->cache_keys;
      int * v11055 = v11040->cache_keys;
      int v11056 = v11055[0];
      v11054[1] = v11056;
      int * v11058 = v11040->cache_vals;
      int * v11059 = v11040->cache_vals;
      int v11060 = v11059[0];
      v11058[1] = v11060;
      int * v11062 = v11040->cache_keys;
      int v11118 = (int)((unsigned int)(v11044 + 88) >> 2);
      v11062[0] = v11118;
      int * v11064 = v11040->cache_vals;
      v11064[0] = v11053;
      int v11066 = v11040->timer;
      int v11121 = v11066 + 1;
      v11040->timer = v11121;
      v11092 = v11053;
    } else {
      int * v11069 = v11040->mem;
      int v11123 = (int)((unsigned int)(v11044 + 88) >> 2);
      int v11070 = v11069[v11123];
      int * v11071 = v11040->mem;
      int * v11072 = v11040->cache_keys;
      int v11073 = v11072[1];
      int * v11074 = v11040->cache_vals;
      int v11075 = v11074[1];
      v11071[v11073] = v11075;
      int * v11077 = v11040->cache_keys;
      int * v11078 = v11040->cache_keys;
      int v11079 = v11078[0];
      v11077[1] = v11079;
      int * v11081 = v11040->cache_vals;
      int * v11082 = v11040->cache_vals;
      int v11083 = v11082[0];
      v11081[1] = v11083;
      int * v11085 = v11040->cache_keys;
      v11085[0] = v11123;
      int * v11087 = v11040->cache_vals;
      v11087[0] = v11070;
      int v11089 = v11040->timer;
      int v11138 = v11089 + 100;
      v11040->timer = v11138;
      v11092 = v11070;
    }
    v11094 = v11092;
  }
  int * v11095 = v11040->regs;
  v11095[8] = v11094;
  struct StateT * v11097 = slot_264(v11040);
  return v11097;
}

struct StateT * slot_161(struct StateT * v13353) {
  int v13354 = v13353->timer;
  int v13362 = v13354 + 1;
  v13353->timer = v13362;
  int * v13356 = v13353->regs;
  int v13357 = v13356[6];
  int * v13358 = v13353->regs;
  int v13367 = (int)((unsigned int)v13357 >> 23);
  v13358[9] = v13367;
  struct StateT * v13360 = slot_162(v13353);
  return v13360;
}

struct StateT * slot_185(struct StateT * v13799) {
  int v13800 = v13799->timer;
  int v13808 = v13800 + 1;
  v13799->timer = v13808;
  int * v13802 = v13799->regs;
  int v13803 = v13802[8];
  int * v13804 = v13799->regs;
  int v13812 = v13803 << 13;
  v13804[8] = v13812;
  struct StateT * v13806 = slot_186(v13799);
  return v13806;
}

struct StateT * slot_91(struct StateT * v9236) {
  int v9237 = v9236->timer;
  int v9247 = v9237 + 1;
  v9236->timer = v9247;
  int * v9239 = v9236->regs;
  int v9240 = v9239[26];
  int * v9241 = v9236->regs;
  int v9242 = v9241[12];
  int * v9243 = v9236->regs;
  int v9254 = v9240 + v9242;
  v9243[15] = v9254;
  struct StateT * v9245 = slot_92(v9236);
  return v9245;
}

struct StateT * slot_58(struct StateT * v6772) {
  int v6773 = v6772->timer;
  int v6781 = v6773 + 1;
  v6772->timer = v6781;
  int * v6775 = v6772->regs;
  int v6776 = v6775[20];
  int * v6777 = v6772->regs;
  int v6786 = (int)((unsigned int)v6776 >> 25);
  v6777[9] = v6786;
  struct StateT * v6779 = slot_59(v6772);
  return v6779;
}

struct StateT * slot_89(struct StateT * v9000) {
  int v9001 = v9000->timer;
  int v9011 = v9001 + 1;
  v9000->timer = v9011;
  int * v9003 = v9000->regs;
  int v9004 = v9003[27];
  int * v9005 = v9000->regs;
  int v9006 = v9005[9];
  int * v9007 = v9000->regs;
  int v9017 = v9004 ^ v9006;
  v9007[27] = v9017;
  struct StateT * v9009 = slot_90(v9000);
  return v9009;
}

struct StateT * slot_255(struct StateT * v9376) {
  int v9377 = v9376->timer;
  int v9431 = v9377 + 1;
  v9376->timer = v9431;
  int * v9379 = v9376->regs;
  int v9380 = v9379[10];
  int * v9381 = v9376->regs;
  int v9382 = v9381[13];
  int * v9383 = v9376->cache_keys;
  int v9384 = v9383[0];
  bool v9438 = v9384 == ((int)((unsigned int)(v9380 + 36) >> 2));
  int v9428;
  if (v9438) {
    int * v9385 = v9376->cache_vals;
    v9385[0] = v9382;
    v9428 = v9382;
  } else {
    int * v9388 = v9376->cache_keys;
    int v9389 = v9388[1];
    bool v9443 = v9389 == ((int)((unsigned int)(v9380 + 36) >> 2));
    int v9426;
    if (v9443) {
      int * v9390 = v9376->cache_keys;
      int * v9391 = v9376->cache_keys;
      int v9392 = v9391[0];
      v9390[1] = v9392;
      int * v9394 = v9376->cache_vals;
      int * v9395 = v9376->cache_vals;
      int v9396 = v9395[0];
      v9394[1] = v9396;
      int * v9398 = v9376->cache_keys;
      int v9451 = (int)((unsigned int)(v9380 + 36) >> 2);
      v9398[0] = v9451;
      int * v9400 = v9376->cache_vals;
      v9400[0] = v9382;
      int v9402 = v9376->timer;
      int v9454 = v9402 + 1;
      v9376->timer = v9454;
      v9426 = v9382;
    } else {
      int * v9405 = v9376->mem;
      int * v9406 = v9376->cache_keys;
      int v9407 = v9406[1];
      int * v9408 = v9376->cache_vals;
      int v9409 = v9408[1];
      v9405[v9407] = v9409;
      int * v9411 = v9376->cache_keys;
      int * v9412 = v9376->cache_keys;
      int v9413 = v9412[0];
      v9411[1] = v9413;
      int * v9415 = v9376->cache_vals;
      int * v9416 = v9376->cache_vals;
      int v9417 = v9416[0];
      v9415[1] = v9417;
      int * v9419 = v9376->cache_keys;
      int v9467 = (int)((unsigned int)(v9380 + 36) >> 2);
      v9419[0] = v9467;
      int * v9421 = v9376->cache_vals;
      v9421[0] = v9382;
      int v9423 = v9376->timer;
      int v9470 = v9423 + 100;
      v9376->timer = v9470;
      v9426 = v9382;
    }
    v9428 = v9426;
  }
  struct StateT * v9429 = slot_256(v9376);
  return v9429;
}

struct StateT * slot_66(struct StateT * v7319) {
  int v7320 = v7319->timer;
  int v7330 = v7320 + 1;
  v7319->timer = v7330;
  int * v7322 = v7319->regs;
  int v7323 = v7322[8];
  int * v7324 = v7319->regs;
  int v7325 = v7324[20];
  int * v7326 = v7319->regs;
  int v7336 = v7323 | v7325;
  v7326[8] = v7336;
  struct StateT * v7328 = slot_67(v7319);
  return v7328;
}

struct StateT * slot_140(struct StateT * v12953) {
  int v12954 = v12953->timer;
  int v12964 = v12954 + 1;
  v12953->timer = v12964;
  int * v12956 = v12953->regs;
  int v12957 = v12956[11];
  int * v12958 = v12953->regs;
  int v12959 = v12958[5];
  int * v12960 = v12953->regs;
  int v12970 = v12957 | v12959;
  v12960[11] = v12970;
  struct StateT * v12962 = slot_141(v12953);
  return v12962;
}

struct StateT * slot_265(struct StateT * v11493) {
  int v11494 = v11493->timer;
  int v11552 = v11494 + 1;
  v11493->timer = v11552;
  int * v11496 = v11493->regs;
  int v11497 = v11496[2];
  int * v11498 = v11493->cache_keys;
  int v11499 = v11498[0];
  bool v11557 = v11499 == ((int)((unsigned int)(v11497 + 80) >> 2));
  int v11547;
  if (v11557) {
    int * v11500 = v11493->cache_vals;
    int v11501 = v11500[0];
    v11547 = v11501;
  } else {
    int * v11503 = v11493->cache_keys;
    int v11504 = v11503[1];
    bool v11562 = v11504 == ((int)((unsigned int)(v11497 + 80) >> 2));
    int v11545;
    if (v11562) {
      int * v11505 = v11493->cache_vals;
      int v11506 = v11505[1];
      int * v11507 = v11493->cache_keys;
      int * v11508 = v11493->cache_keys;
      int v11509 = v11508[0];
      v11507[1] = v11509;
      int * v11511 = v11493->cache_vals;
      int * v11512 = v11493->cache_vals;
      int v11513 = v11512[0];
      v11511[1] = v11513;
      int * v11515 = v11493->cache_keys;
      int v11571 = (int)((unsigned int)(v11497 + 80) >> 2);
      v11515[0] = v11571;
      int * v11517 = v11493->cache_vals;
      v11517[0] = v11506;
      int v11519 = v11493->timer;
      int v11574 = v11519 + 1;
      v11493->timer = v11574;
      v11545 = v11506;
    } else {
      int * v11522 = v11493->mem;
      int v11576 = (int)((unsigned int)(v11497 + 80) >> 2);
      int v11523 = v11522[v11576];
      int * v11524 = v11493->mem;
      int * v11525 = v11493->cache_keys;
      int v11526 = v11525[1];
      int * v11527 = v11493->cache_vals;
      int v11528 = v11527[1];
      v11524[v11526] = v11528;
      int * v11530 = v11493->cache_keys;
      int * v11531 = v11493->cache_keys;
      int v11532 = v11531[0];
      v11530[1] = v11532;
      int * v11534 = v11493->cache_vals;
      int * v11535 = v11493->cache_vals;
      int v11536 = v11535[0];
      v11534[1] = v11536;
      int * v11538 = v11493->cache_keys;
      v11538[0] = v11576;
      int * v11540 = v11493->cache_vals;
      v11540[0] = v11523;
      int v11542 = v11493->timer;
      int v11591 = v11542 + 100;
      v11493->timer = v11591;
      v11545 = v11523;
    }
    v11547 = v11545;
  }
  int * v11548 = v11493->regs;
  v11548[18] = v11547;
  struct StateT * v11550 = slot_266(v11493);
  return v11550;
}

struct StateT * slot_216(struct StateT * v6435) {
  int v6436 = v6435->timer;
  int v6446 = v6436 + 1;
  v6435->timer = v6446;
  int * v6438 = v6435->regs;
  int v6439 = v6438[14];
  int * v6440 = v6435->regs;
  int v6441 = v6440[7];
  int * v6442 = v6435->regs;
  int v6452 = v6439 + v6441;
  v6442[14] = v6452;
  struct StateT * v6444 = slot_217(v6435);
  return v6444;
}

struct StateT * slot_50(struct StateT * v4057) {
  int * v4058 = v4057->saved_regs;
  int * v4059 = v4057->regs;
  int v4060 = v4059[15];
  v4058[15] = v4060;
  int v4062 = v4057->timer;
  int v5412 = v4062 + 1;
  v4057->timer = v5412;
  int * v4064 = v4057->regs;
  int v4065 = v4064[21];
  int * v4066 = v4057->regs;
  int v4067 = v4066[16];
  int * v4068 = v4057->regs;
  int v5418 = v4065 + v4067;
  v4068[15] = v5418;
  int * v4070 = v4057->saved_regs;
  int * v4071 = v4057->regs;
  int v4072 = v4071[20];
  v4070[20] = v4072;
  int v4074 = v4057->timer;
  int v5423 = v4074 + 1;
  v4057->timer = v5423;
  int * v4076 = v4057->regs;
  int v4077 = v4076[11];
  int * v4078 = v4057->regs;
  int v4079 = v4078[23];
  int * v4080 = v4057->regs;
  int v5429 = v4077 + v4079;
  v4080[20] = v5429;
  int * v4082 = v4057->saved_regs;
  int * v4083 = v4057->regs;
  int v4084 = v4083[18];
  v4082[18] = v4084;
  int v4086 = v4057->timer;
  int v5434 = v4086 + 1;
  v4057->timer = v5434;
  int * v4088 = v4057->regs;
  int v4089 = v4088[19];
  int * v4090 = v4057->regs;
  int v4091 = v4090[5];
  int * v4092 = v4057->regs;
  int v5440 = v4089 + v4091;
  v4092[18] = v5440;
  int * v4094 = v4057->saved_regs;
  int * v4095 = v4057->regs;
  int v4096 = v4095[8];
  v4094[8] = v4096;
  int v4098 = v4057->timer;
  int v5445 = v4098 + 1;
  v4057->timer = v5445;
  int * v4100 = v4057->regs;
  int v4101 = v4100[22];
  int * v4102 = v4057->regs;
  int v4103 = v4102[17];
  int * v4104 = v4057->regs;
  int v5451 = v4101 + v4103;
  v4104[8] = v5451;
  int * v4106 = v4057->saved_regs;
  int * v4107 = v4057->regs;
  int v4108 = v4107[9];
  v4106[9] = v4108;
  int v4110 = v4057->timer;
  int v5456 = v4110 + 1;
  v4057->timer = v5456;
  int * v4112 = v4057->regs;
  int v4113 = v4112[15];
  int * v4114 = v4057->regs;
  int v5459 = (int)((unsigned int)v4113 >> 25);
  v4114[9] = v5459;
  int v4116 = v4057->timer;
  int v5460 = v4116 + 1;
  v4057->timer = v5460;
  int * v4118 = v4057->regs;
  int v4119 = v4118[15];
  int * v4120 = v4057->regs;
  int v5463 = v4119 << 7;
  v4120[15] = v5463;
  int v4122 = v4057->timer;
  int v5464 = v4122 + 1;
  v4057->timer = v5464;
  int * v4124 = v4057->regs;
  int v4125 = v4124[15];
  int * v4126 = v4057->regs;
  int v4127 = v4126[9];
  int * v4128 = v4057->regs;
  int v5468 = v4125 | v4127;
  v4128[15] = v5468;
  int v4130 = v4057->timer;
  int v5469 = v4130 + 1;
  v4057->timer = v5469;
  int * v4132 = v4057->regs;
  int v4133 = v4132[20];
  int * v4134 = v4057->regs;
  int v5472 = (int)((unsigned int)v4133 >> 25);
  v4134[9] = v5472;
  int v4136 = v4057->timer;
  int v5473 = v4136 + 1;
  v4057->timer = v5473;
  int * v4138 = v4057->regs;
  int v4139 = v4138[20];
  int * v4140 = v4057->regs;
  int v5476 = v4139 << 7;
  v4140[20] = v5476;
  int v4142 = v4057->timer;
  int v5477 = v4142 + 1;
  v4057->timer = v5477;
  int * v4144 = v4057->regs;
  int v4145 = v4144[20];
  int * v4146 = v4057->regs;
  int v4147 = v4146[9];
  int * v4148 = v4057->regs;
  int v5481 = v4145 | v4147;
  v4148[9] = v5481;
  int v4150 = v4057->timer;
  int v5482 = v4150 + 1;
  v4057->timer = v5482;
  int * v4152 = v4057->regs;
  int v4153 = v4152[18];
  int * v4154 = v4057->regs;
  int v5485 = (int)((unsigned int)v4153 >> 25);
  v4154[20] = v5485;
  int v4156 = v4057->timer;
  int v5486 = v4156 + 1;
  v4057->timer = v5486;
  int * v4158 = v4057->regs;
  int v4159 = v4158[18];
  int * v4160 = v4057->regs;
  int v5489 = v4159 << 7;
  v4160[18] = v5489;
  int v4162 = v4057->timer;
  int v5490 = v4162 + 1;
  v4057->timer = v5490;
  int * v4164 = v4057->regs;
  int v4165 = v4164[18];
  int * v4166 = v4057->regs;
  int v4167 = v4166[20];
  int * v4168 = v4057->regs;
  int v5494 = v4165 | v4167;
  v4168[18] = v5494;
  int v4170 = v4057->timer;
  int v5495 = v4170 + 1;
  v4057->timer = v5495;
  int * v4172 = v4057->regs;
  int v4173 = v4172[8];
  int * v4174 = v4057->regs;
  int v5498 = (int)((unsigned int)v4173 >> 25);
  v4174[20] = v5498;
  int v4176 = v4057->timer;
  int v5499 = v4176 + 1;
  v4057->timer = v5499;
  int * v4178 = v4057->regs;
  int v4179 = v4178[8];
  int * v4180 = v4057->regs;
  int v5502 = v4179 << 7;
  v4180[8] = v5502;
  int v4182 = v4057->timer;
  int v5503 = v4182 + 1;
  v4057->timer = v5503;
  int * v4184 = v4057->regs;
  int v4185 = v4184[8];
  int * v4186 = v4057->regs;
  int v4187 = v4186[20];
  int * v4188 = v4057->regs;
  int v5507 = v4185 | v4187;
  v4188[8] = v5507;
  int v4190 = v4057->timer;
  int v5508 = v4190 + 1;
  v4057->timer = v5508;
  int * v4192 = v4057->regs;
  int v4193 = v4192[12];
  int * v4194 = v4057->regs;
  int v4195 = v4194[15];
  int * v4196 = v4057->regs;
  int v5513 = v4193 ^ v4195;
  v4196[12] = v5513;
  int v4198 = v4057->timer;
  int v5514 = v4198 + 1;
  v4057->timer = v5514;
  int * v4200 = v4057->regs;
  int v4201 = v4200[13];
  int * v4202 = v4057->regs;
  int v4203 = v4202[9];
  int * v4204 = v4057->regs;
  int v5519 = v4201 ^ v4203;
  v4204[13] = v5519;
  int * v4206 = v4057->saved_regs;
  int * v4207 = v4057->regs;
  int v4208 = v4207[1];
  v4206[1] = v4208;
  int v4210 = v4057->timer;
  int v5524 = v4210 + 1;
  v4057->timer = v5524;
  int * v4212 = v4057->regs;
  int v4213 = v4212[1];
  int * v4214 = v4057->regs;
  int v4215 = v4214[18];
  int * v4216 = v4057->regs;
  int v5528 = v4213 ^ v4215;
  v4216[1] = v5528;
  int v4218 = v4057->timer;
  int v5529 = v4218 + 1;
  v4057->timer = v5529;
  int * v4220 = v4057->regs;
  int v4221 = v4220[14];
  int * v4222 = v4057->regs;
  int v4223 = v4222[8];
  int * v4224 = v4057->regs;
  int v5534 = v4221 ^ v4223;
  v4224[14] = v5534;
  int v4226 = v4057->timer;
  int v5535 = v4226 + 1;
  v4057->timer = v5535;
  int * v4228 = v4057->regs;
  int v4229 = v4228[12];
  int * v4230 = v4057->regs;
  int v4231 = v4230[21];
  int * v4232 = v4057->regs;
  int v5539 = v4229 + v4231;
  v4232[15] = v5539;
  int v4234 = v4057->timer;
  int v5540 = v4234 + 1;
  v4057->timer = v5540;
  int * v4236 = v4057->regs;
  int v4237 = v4236[13];
  int * v4238 = v4057->regs;
  int v4239 = v4238[11];
  int * v4240 = v4057->regs;
  int v5544 = v4237 + v4239;
  v4240[8] = v5544;
  int v4242 = v4057->timer;
  int v5545 = v4242 + 1;
  v4057->timer = v5545;
  int * v4244 = v4057->regs;
  int v4245 = v4244[1];
  int * v4246 = v4057->regs;
  int v4247 = v4246[19];
  int * v4248 = v4057->regs;
  int v5549 = v4245 + v4247;
  v4248[9] = v5549;
  int v4250 = v4057->timer;
  int v5550 = v4250 + 1;
  v4057->timer = v5550;
  int * v4252 = v4057->regs;
  int v4253 = v4252[14];
  int * v4254 = v4057->regs;
  int v4255 = v4254[22];
  int * v4256 = v4057->regs;
  int v5554 = v4253 + v4255;
  v4256[18] = v5554;
  int v4258 = v4057->timer;
  int v5555 = v4258 + 1;
  v4057->timer = v5555;
  int * v4260 = v4057->regs;
  int v4261 = v4260[15];
  int * v4262 = v4057->regs;
  int v5558 = (int)((unsigned int)v4261 >> 23);
  v4262[20] = v5558;
  int v4264 = v4057->timer;
  int v5559 = v4264 + 1;
  v4057->timer = v5559;
  int * v4266 = v4057->regs;
  int v4267 = v4266[15];
  int * v4268 = v4057->regs;
  int v5562 = v4267 << 9;
  v4268[15] = v5562;
  int v4270 = v4057->timer;
  int v5563 = v4270 + 1;
  v4057->timer = v5563;
  int * v4272 = v4057->regs;
  int v4273 = v4272[15];
  int * v4274 = v4057->regs;
  int v4275 = v4274[20];
  int * v4276 = v4057->regs;
  int v5567 = v4273 | v4275;
  v4276[15] = v5567;
  int v4278 = v4057->timer;
  int v5568 = v4278 + 1;
  v4057->timer = v5568;
  int * v4280 = v4057->regs;
  int v4281 = v4280[8];
  int * v4282 = v4057->regs;
  int v5571 = (int)((unsigned int)v4281 >> 23);
  v4282[20] = v5571;
  int v4284 = v4057->timer;
  int v5572 = v4284 + 1;
  v4057->timer = v5572;
  int * v4286 = v4057->regs;
  int v4287 = v4286[8];
  int * v4288 = v4057->regs;
  int v5575 = v4287 << 9;
  v4288[8] = v5575;
  int v4290 = v4057->timer;
  int v5576 = v4290 + 1;
  v4057->timer = v5576;
  int * v4292 = v4057->regs;
  int v4293 = v4292[8];
  int * v4294 = v4057->regs;
  int v4295 = v4294[20];
  int * v4296 = v4057->regs;
  int v5580 = v4293 | v4295;
  v4296[8] = v5580;
  int v4298 = v4057->timer;
  int v5581 = v4298 + 1;
  v4057->timer = v5581;
  int * v4300 = v4057->regs;
  int v4301 = v4300[9];
  int * v4302 = v4057->regs;
  int v5584 = (int)((unsigned int)v4301 >> 23);
  v4302[20] = v5584;
  int v4304 = v4057->timer;
  int v5585 = v4304 + 1;
  v4057->timer = v5585;
  int * v4306 = v4057->regs;
  int v4307 = v4306[9];
  int * v4308 = v4057->regs;
  int v5588 = v4307 << 9;
  v4308[9] = v5588;
  int v4310 = v4057->timer;
  int v5589 = v4310 + 1;
  v4057->timer = v5589;
  int * v4312 = v4057->regs;
  int v4313 = v4312[9];
  int * v4314 = v4057->regs;
  int v4315 = v4314[20];
  int * v4316 = v4057->regs;
  int v5593 = v4313 | v4315;
  v4316[9] = v5593;
  int v4318 = v4057->timer;
  int v5594 = v4318 + 1;
  v4057->timer = v5594;
  int * v4320 = v4057->regs;
  int v4321 = v4320[18];
  int * v4322 = v4057->regs;
  int v5597 = (int)((unsigned int)v4321 >> 23);
  v4322[20] = v5597;
  int v4324 = v4057->timer;
  int v5598 = v4324 + 1;
  v4057->timer = v5598;
  int * v4326 = v4057->regs;
  int v4327 = v4326[18];
  int * v4328 = v4057->regs;
  int v5601 = v4327 << 9;
  v4328[18] = v5601;
  int v4330 = v4057->timer;
  int v5602 = v4330 + 1;
  v4057->timer = v5602;
  int * v4332 = v4057->regs;
  int v4333 = v4332[18];
  int * v4334 = v4057->regs;
  int v4335 = v4334[20];
  int * v4336 = v4057->regs;
  int v5606 = v4333 | v4335;
  v4336[18] = v5606;
  int * v4338 = v4057->saved_regs;
  int * v4339 = v4057->regs;
  int v4340 = v4339[26];
  v4338[26] = v4340;
  int v4342 = v4057->timer;
  int v5611 = v4342 + 1;
  v4057->timer = v5611;
  int * v4344 = v4057->regs;
  int v4345 = v4344[26];
  int * v4346 = v4057->regs;
  int v4347 = v4346[15];
  int * v4348 = v4057->regs;
  int v5615 = v4345 ^ v4347;
  v4348[26] = v5615;
  int * v4350 = v4057->saved_regs;
  int * v4351 = v4057->regs;
  int v4352 = v4351[24];
  v4350[24] = v4352;
  int v4354 = v4057->timer;
  int v5620 = v4354 + 1;
  v4057->timer = v5620;
  int * v4356 = v4057->regs;
  int v4357 = v4356[24];
  int * v4358 = v4057->regs;
  int v4359 = v4358[8];
  int * v4360 = v4057->regs;
  int v5624 = v4357 ^ v4359;
  v4360[24] = v5624;
  int v4362 = v4057->timer;
  int v5625 = v4362 + 1;
  v4057->timer = v5625;
  int * v4364 = v4057->regs;
  int v4365 = v4364[27];
  int * v4366 = v4057->regs;
  int v4367 = v4366[9];
  int * v4368 = v4057->regs;
  int v5630 = v4365 ^ v4367;
  v4368[27] = v5630;
  int * v4370 = v4057->saved_regs;
  int * v4371 = v4057->regs;
  int v4372 = v4371[25];
  v4370[25] = v4372;
  int v4374 = v4057->timer;
  int v5635 = v4374 + 1;
  v4057->timer = v5635;
  int * v4376 = v4057->regs;
  int v4377 = v4376[25];
  int * v4378 = v4057->regs;
  int v4379 = v4378[18];
  int * v4380 = v4057->regs;
  int v5639 = v4377 ^ v4379;
  v4380[25] = v5639;
  int v4382 = v4057->timer;
  int v5640 = v4382 + 1;
  v4057->timer = v5640;
  int * v4384 = v4057->regs;
  int v4385 = v4384[26];
  int * v4386 = v4057->regs;
  int v4387 = v4386[12];
  int * v4388 = v4057->regs;
  int v5644 = v4385 + v4387;
  v4388[15] = v5644;
  int v4390 = v4057->timer;
  int v5645 = v4390 + 1;
  v4057->timer = v5645;
  int * v4392 = v4057->regs;
  int v4393 = v4392[24];
  int * v4394 = v4057->regs;
  int v4395 = v4394[13];
  int * v4396 = v4057->regs;
  int v5649 = v4393 + v4395;
  v4396[8] = v5649;
  int v4398 = v4057->timer;
  int v5650 = v4398 + 1;
  v4057->timer = v5650;
  int * v4400 = v4057->regs;
  int v4401 = v4400[27];
  int * v4402 = v4057->regs;
  int v4403 = v4402[1];
  int * v4404 = v4057->regs;
  int v5654 = v4401 + v4403;
  v4404[9] = v5654;
  int v4406 = v4057->timer;
  int v5655 = v4406 + 1;
  v4057->timer = v5655;
  int * v4408 = v4057->regs;
  int v4409 = v4408[25];
  int * v4410 = v4057->regs;
  int v4411 = v4410[14];
  int * v4412 = v4057->regs;
  int v5659 = v4409 + v4411;
  v4412[18] = v5659;
  int v4414 = v4057->timer;
  int v5660 = v4414 + 1;
  v4057->timer = v5660;
  int * v4416 = v4057->regs;
  int v4417 = v4416[15];
  int * v4418 = v4057->regs;
  int v5663 = (int)((unsigned int)v4417 >> 19);
  v4418[20] = v5663;
  int v4420 = v4057->timer;
  int v5664 = v4420 + 1;
  v4057->timer = v5664;
  int * v4422 = v4057->regs;
  int v4423 = v4422[15];
  int * v4424 = v4057->regs;
  int v5667 = v4423 << 13;
  v4424[15] = v5667;
  int v4426 = v4057->timer;
  int v5668 = v4426 + 1;
  v4057->timer = v5668;
  int * v4428 = v4057->regs;
  int v4429 = v4428[15];
  int * v4430 = v4057->regs;
  int v4431 = v4430[20];
  int * v4432 = v4057->regs;
  int v5672 = v4429 | v4431;
  v4432[15] = v5672;
  int v4434 = v4057->timer;
  int v5673 = v4434 + 1;
  v4057->timer = v5673;
  int * v4436 = v4057->regs;
  int v4437 = v4436[8];
  int * v4438 = v4057->regs;
  int v5676 = (int)((unsigned int)v4437 >> 19);
  v4438[20] = v5676;
  int v4440 = v4057->timer;
  int v5677 = v4440 + 1;
  v4057->timer = v5677;
  int * v4442 = v4057->regs;
  int v4443 = v4442[8];
  int * v4444 = v4057->regs;
  int v5680 = v4443 << 13;
  v4444[8] = v5680;
  int v4446 = v4057->timer;
  int v5681 = v4446 + 1;
  v4057->timer = v5681;
  int * v4448 = v4057->regs;
  int v4449 = v4448[8];
  int * v4450 = v4057->regs;
  int v4451 = v4450[20];
  int * v4452 = v4057->regs;
  int v5685 = v4449 | v4451;
  v4452[8] = v5685;
  int v4454 = v4057->timer;
  int v5686 = v4454 + 1;
  v4057->timer = v5686;
  int * v4456 = v4057->regs;
  int v4457 = v4456[9];
  int * v4458 = v4057->regs;
  int v5689 = (int)((unsigned int)v4457 >> 19);
  v4458[20] = v5689;
  int v4460 = v4057->timer;
  int v5690 = v4460 + 1;
  v4057->timer = v5690;
  int * v4462 = v4057->regs;
  int v4463 = v4462[9];
  int * v4464 = v4057->regs;
  int v5693 = v4463 << 13;
  v4464[9] = v5693;
  int v4466 = v4057->timer;
  int v5694 = v4466 + 1;
  v4057->timer = v5694;
  int * v4468 = v4057->regs;
  int v4469 = v4468[9];
  int * v4470 = v4057->regs;
  int v4471 = v4470[20];
  int * v4472 = v4057->regs;
  int v5698 = v4469 | v4471;
  v4472[20] = v5698;
  int v4474 = v4057->timer;
  int v5699 = v4474 + 1;
  v4057->timer = v5699;
  int * v4476 = v4057->regs;
  int v4477 = v4476[18];
  int * v4478 = v4057->regs;
  int v5702 = (int)((unsigned int)v4477 >> 19);
  v4478[9] = v5702;
  int v4480 = v4057->timer;
  int v5703 = v4480 + 1;
  v4057->timer = v5703;
  int * v4482 = v4057->regs;
  int v4483 = v4482[18];
  int * v4484 = v4057->regs;
  int v5706 = v4483 << 13;
  v4484[18] = v5706;
  int * v4486 = v4057->saved_regs;
  int * v4487 = v4057->regs;
  int v4488 = v4487[6];
  v4486[6] = v4488;
  int v4490 = v4057->timer;
  int v5711 = v4490 + 1;
  v4057->timer = v5711;
  int * v4492 = v4057->regs;
  int v4493 = v4492[18];
  int * v4494 = v4057->regs;
  int v4495 = v4494[9];
  int * v4496 = v4057->regs;
  int v5715 = v4493 | v4495;
  v4496[6] = v5715;
  int v4498 = v4057->timer;
  int v5716 = v4498 + 1;
  v4057->timer = v5716;
  int * v4500 = v4057->regs;
  int v4501 = v4500[16];
  int * v4502 = v4057->regs;
  int v4503 = v4502[15];
  int * v4504 = v4057->regs;
  int v5720 = v4501 ^ v4503;
  v4504[9] = v5720;
  int v4506 = v4057->timer;
  int v5721 = v4506 + 1;
  v4057->timer = v5721;
  int * v4508 = v4057->regs;
  int v4509 = v4508[23];
  int * v4510 = v4057->regs;
  int v4511 = v4510[8];
  int * v4512 = v4057->regs;
  int v5725 = v4509 ^ v4511;
  v4512[23] = v5725;
  int v4514 = v4057->timer;
  int v5726 = v4514 + 1;
  v4057->timer = v5726;
  int * v4516 = v4057->regs;
  int v4517 = v4516[5];
  int * v4518 = v4057->regs;
  int v4519 = v4518[20];
  int * v4520 = v4057->regs;
  int v5730 = v4517 ^ v4519;
  v4520[18] = v5730;
  int v4522 = v4057->timer;
  int v5731 = v4522 + 1;
  v4057->timer = v5731;
  int * v4524 = v4057->regs;
  int v4525 = v4524[17];
  int * v4526 = v4057->regs;
  int v4527 = v4526[6];
  int * v4528 = v4057->regs;
  int v5735 = v4525 ^ v4527;
  v4528[8] = v5735;
  int v4530 = v4057->timer;
  int v5736 = v4530 + 1;
  v4057->timer = v5736;
  int * v4532 = v4057->regs;
  int v4533 = v4532[9];
  int * v4534 = v4057->regs;
  int v4535 = v4534[26];
  int * v4536 = v4057->regs;
  int v5740 = v4533 + v4535;
  v4536[15] = v5740;
  int * v4538 = v4057->saved_regs;
  int * v4539 = v4057->regs;
  int v4540 = v4539[16];
  v4538[16] = v4540;
  int v4542 = v4057->timer;
  int v5744 = v4542 + 1;
  v4057->timer = v5744;
  int * v4544 = v4057->regs;
  int v4545 = v4544[23];
  int * v4546 = v4057->regs;
  int v4547 = v4546[24];
  int * v4548 = v4057->regs;
  int v5748 = v4545 + v4547;
  v4548[16] = v5748;
  int * v4550 = v4057->saved_regs;
  int * v4551 = v4057->regs;
  int v4552 = v4551[17];
  v4550[17] = v4552;
  int v4554 = v4057->timer;
  int v5752 = v4554 + 1;
  v4057->timer = v5752;
  int * v4556 = v4057->regs;
  int v4557 = v4556[18];
  int * v4558 = v4057->regs;
  int v4559 = v4558[27];
  int * v4560 = v4057->regs;
  int v5756 = v4557 + v4559;
  v4560[17] = v5756;
  int * v4562 = v4057->saved_regs;
  int * v4563 = v4057->regs;
  int v4564 = v4563[5];
  v4562[5] = v4564;
  int v4566 = v4057->timer;
  int v5760 = v4566 + 1;
  v4057->timer = v5760;
  int * v4568 = v4057->regs;
  int v4569 = v4568[8];
  int * v4570 = v4057->regs;
  int v4571 = v4570[25];
  int * v4572 = v4057->regs;
  int v5764 = v4569 + v4571;
  v4572[5] = v5764;
  int v4574 = v4057->timer;
  int v5765 = v4574 + 1;
  v4057->timer = v5765;
  int * v4576 = v4057->regs;
  int v4577 = v4576[15];
  int * v4578 = v4057->regs;
  int v5768 = (int)((unsigned int)v4577 >> 14);
  v4578[6] = v5768;
  int v4580 = v4057->timer;
  int v5769 = v4580 + 1;
  v4057->timer = v5769;
  int * v4582 = v4057->regs;
  int v4583 = v4582[15];
  int * v4584 = v4057->regs;
  int v5772 = v4583 << 18;
  v4584[15] = v5772;
  int v4586 = v4057->timer;
  int v5773 = v4586 + 1;
  v4057->timer = v5773;
  int * v4588 = v4057->regs;
  int v4589 = v4588[15];
  int * v4590 = v4057->regs;
  int v4591 = v4590[6];
  int * v4592 = v4057->regs;
  int v5777 = v4589 | v4591;
  v4592[15] = v5777;
  int v4594 = v4057->timer;
  int v5778 = v4594 + 1;
  v4057->timer = v5778;
  int * v4596 = v4057->regs;
  int v4597 = v4596[16];
  int * v4598 = v4057->regs;
  int v5781 = (int)((unsigned int)v4597 >> 14);
  v4598[6] = v5781;
  int v4600 = v4057->timer;
  int v5782 = v4600 + 1;
  v4057->timer = v5782;
  int * v4602 = v4057->regs;
  int v4603 = v4602[16];
  int * v4604 = v4057->regs;
  int v5785 = v4603 << 18;
  v4604[16] = v5785;
  int v4606 = v4057->timer;
  int v5786 = v4606 + 1;
  v4057->timer = v5786;
  int * v4608 = v4057->regs;
  int v4609 = v4608[16];
  int * v4610 = v4057->regs;
  int v4611 = v4610[6];
  int * v4612 = v4057->regs;
  int v5790 = v4609 | v4611;
  v4612[16] = v5790;
  int v4614 = v4057->timer;
  int v5791 = v4614 + 1;
  v4057->timer = v5791;
  int * v4616 = v4057->regs;
  int v4617 = v4616[17];
  int * v4618 = v4057->regs;
  int v5794 = (int)((unsigned int)v4617 >> 14);
  v4618[6] = v5794;
  int v4620 = v4057->timer;
  int v5795 = v4620 + 1;
  v4057->timer = v5795;
  int * v4622 = v4057->regs;
  int v4623 = v4622[17];
  int * v4624 = v4057->regs;
  int v5798 = v4623 << 18;
  v4624[17] = v5798;
  int v4626 = v4057->timer;
  int v5799 = v4626 + 1;
  v4057->timer = v5799;
  int * v4628 = v4057->regs;
  int v4629 = v4628[17];
  int * v4630 = v4057->regs;
  int v4631 = v4630[6];
  int * v4632 = v4057->regs;
  int v5803 = v4629 | v4631;
  v4632[17] = v5803;
  int v4634 = v4057->timer;
  int v5804 = v4634 + 1;
  v4057->timer = v5804;
  int * v4636 = v4057->regs;
  int v4637 = v4636[5];
  int * v4638 = v4057->regs;
  int v5807 = (int)((unsigned int)v4637 >> 14);
  v4638[6] = v5807;
  int v4640 = v4057->timer;
  int v5808 = v4640 + 1;
  v4057->timer = v5808;
  int * v4642 = v4057->regs;
  int v4643 = v4642[5];
  int * v4644 = v4057->regs;
  int v5811 = v4643 << 18;
  v4644[5] = v5811;
  int v4646 = v4057->timer;
  int v5812 = v4646 + 1;
  v4057->timer = v5812;
  int * v4648 = v4057->regs;
  int v4649 = v4648[5];
  int * v4650 = v4057->regs;
  int v4651 = v4650[6];
  int * v4652 = v4057->regs;
  int v5816 = v4649 | v4651;
  v4652[5] = v5816;
  int * v4654 = v4057->saved_regs;
  int * v4655 = v4057->regs;
  int v4656 = v4655[21];
  v4654[21] = v4656;
  int v4658 = v4057->timer;
  int v5820 = v4658 + 1;
  v4057->timer = v5820;
  int * v4660 = v4057->regs;
  int v4661 = v4660[21];
  int * v4662 = v4057->regs;
  int v4663 = v4662[15];
  int * v4664 = v4057->regs;
  int v5824 = v4661 ^ v4663;
  v4664[21] = v5824;
  int v4666 = v4057->timer;
  int v5825 = v4666 + 1;
  v4057->timer = v5825;
  int * v4668 = v4057->regs;
  int v4669 = v4668[11];
  int * v4670 = v4057->regs;
  int v4671 = v4670[16];
  int * v4672 = v4057->regs;
  int v5829 = v4669 ^ v4671;
  v4672[20] = v5829;
  int * v4674 = v4057->saved_regs;
  int * v4675 = v4057->regs;
  int v4676 = v4675[19];
  v4674[19] = v4676;
  int v4678 = v4057->timer;
  int v5833 = v4678 + 1;
  v4057->timer = v5833;
  int * v4680 = v4057->regs;
  int v4681 = v4680[19];
  int * v4682 = v4057->regs;
  int v4683 = v4682[17];
  int * v4684 = v4057->regs;
  int v5837 = v4681 ^ v4683;
  v4684[19] = v5837;
  int * v4686 = v4057->saved_regs;
  int * v4687 = v4057->regs;
  int v4688 = v4687[22];
  v4686[22] = v4688;
  int v4690 = v4057->timer;
  int v5841 = v4690 + 1;
  v4057->timer = v5841;
  int * v4692 = v4057->regs;
  int v4693 = v4692[22];
  int * v4694 = v4057->regs;
  int v4695 = v4694[5];
  int * v4696 = v4057->regs;
  int v5845 = v4693 ^ v4695;
  v4696[22] = v5845;
  int v4698 = v4057->timer;
  int v5846 = v4698 + 1;
  v4057->timer = v5846;
  int * v4700 = v4057->regs;
  int v4701 = v4700[21];
  int * v4702 = v4057->regs;
  int v4703 = v4702[14];
  int * v4704 = v4057->regs;
  int v5850 = v4701 + v4703;
  v4704[15] = v5850;
  int * v4706 = v4057->saved_regs;
  int * v4707 = v4057->regs;
  int v4708 = v4707[11];
  v4706[11] = v4708;
  int v4710 = v4057->timer;
  int v5854 = v4710 + 1;
  v4057->timer = v5854;
  int * v4712 = v4057->regs;
  int v4713 = v4712[20];
  int * v4714 = v4057->regs;
  int v4715 = v4714[12];
  int * v4716 = v4057->regs;
  int v5858 = v4713 + v4715;
  v4716[11] = v5858;
  int v4718 = v4057->timer;
  int v5859 = v4718 + 1;
  v4057->timer = v5859;
  int * v4720 = v4057->regs;
  int v4721 = v4720[19];
  int * v4722 = v4057->regs;
  int v4723 = v4722[13];
  int * v4724 = v4057->regs;
  int v5863 = v4721 + v4723;
  v4724[16] = v5863;
  int v4726 = v4057->timer;
  int v5864 = v4726 + 1;
  v4057->timer = v5864;
  int * v4728 = v4057->regs;
  int v4729 = v4728[22];
  int * v4730 = v4057->regs;
  int v4731 = v4730[1];
  int * v4732 = v4057->regs;
  int v5868 = v4729 + v4731;
  v4732[17] = v5868;
  int v4734 = v4057->timer;
  int v5869 = v4734 + 1;
  v4057->timer = v5869;
  int * v4736 = v4057->regs;
  int v4737 = v4736[15];
  int * v4738 = v4057->regs;
  int v5872 = (int)((unsigned int)v4737 >> 25);
  v4738[5] = v5872;
  int v4740 = v4057->timer;
  int v5873 = v4740 + 1;
  v4057->timer = v5873;
  int * v4742 = v4057->regs;
  int v4743 = v4742[15];
  int * v4744 = v4057->regs;
  int v5876 = v4743 << 7;
  v4744[15] = v5876;
  int v4746 = v4057->timer;
  int v5877 = v4746 + 1;
  v4057->timer = v5877;
  int * v4748 = v4057->regs;
  int v4749 = v4748[15];
  int * v4750 = v4057->regs;
  int v4751 = v4750[5];
  int * v4752 = v4057->regs;
  int v5881 = v4749 | v4751;
  v4752[15] = v5881;
  int v4754 = v4057->timer;
  int v5882 = v4754 + 1;
  v4057->timer = v5882;
  int * v4756 = v4057->regs;
  int v4757 = v4756[11];
  int * v4758 = v4057->regs;
  int v5885 = (int)((unsigned int)v4757 >> 25);
  v4758[5] = v5885;
  int v4760 = v4057->timer;
  int v5886 = v4760 + 1;
  v4057->timer = v5886;
  int * v4762 = v4057->regs;
  int v4763 = v4762[11];
  int * v4764 = v4057->regs;
  int v5889 = v4763 << 7;
  v4764[11] = v5889;
  int v4766 = v4057->timer;
  int v5890 = v4766 + 1;
  v4057->timer = v5890;
  int * v4768 = v4057->regs;
  int v4769 = v4768[11];
  int * v4770 = v4057->regs;
  int v4771 = v4770[5];
  int * v4772 = v4057->regs;
  int v5894 = v4769 | v4771;
  v4772[11] = v5894;
  int v4774 = v4057->timer;
  int v5895 = v4774 + 1;
  v4057->timer = v5895;
  int * v4776 = v4057->regs;
  int v4777 = v4776[16];
  int * v4778 = v4057->regs;
  int v5898 = (int)((unsigned int)v4777 >> 25);
  v4778[5] = v5898;
  int v4780 = v4057->timer;
  int v5899 = v4780 + 1;
  v4057->timer = v5899;
  int * v4782 = v4057->regs;
  int v4783 = v4782[16];
  int * v4784 = v4057->regs;
  int v5902 = v4783 << 7;
  v4784[16] = v5902;
  int v4786 = v4057->timer;
  int v5903 = v4786 + 1;
  v4057->timer = v5903;
  int * v4788 = v4057->regs;
  int v4789 = v4788[16];
  int * v4790 = v4057->regs;
  int v4791 = v4790[5];
  int * v4792 = v4057->regs;
  int v5907 = v4789 | v4791;
  v4792[16] = v5907;
  int v4794 = v4057->timer;
  int v5908 = v4794 + 1;
  v4057->timer = v5908;
  int * v4796 = v4057->regs;
  int v4797 = v4796[17];
  int * v4798 = v4057->regs;
  int v5911 = (int)((unsigned int)v4797 >> 25);
  v4798[5] = v5911;
  int v4800 = v4057->timer;
  int v5912 = v4800 + 1;
  v4057->timer = v5912;
  int * v4802 = v4057->regs;
  int v4803 = v4802[17];
  int * v4804 = v4057->regs;
  int v5915 = v4803 << 7;
  v4804[17] = v5915;
  int v4806 = v4057->timer;
  int v5916 = v4806 + 1;
  v4057->timer = v5916;
  int * v4808 = v4057->regs;
  int v4809 = v4808[17];
  int * v4810 = v4057->regs;
  int v4811 = v4810[5];
  int * v4812 = v4057->regs;
  int v5920 = v4809 | v4811;
  v4812[6] = v5920;
  int v4814 = v4057->timer;
  int v5921 = v4814 + 1;
  v4057->timer = v5921;
  int * v4816 = v4057->regs;
  int v4817 = v4816[23];
  int * v4818 = v4057->regs;
  int v4819 = v4818[15];
  int * v4820 = v4057->regs;
  int v5925 = v4817 ^ v4819;
  v4820[23] = v5925;
  int v4822 = v4057->timer;
  int v5926 = v4822 + 1;
  v4057->timer = v5926;
  int * v4824 = v4057->regs;
  int v4825 = v4824[18];
  int * v4826 = v4057->regs;
  int v4827 = v4826[11];
  int * v4828 = v4057->regs;
  int v5930 = v4825 ^ v4827;
  v4828[5] = v5930;
  int v4830 = v4057->timer;
  int v5931 = v4830 + 1;
  v4057->timer = v5931;
  int * v4832 = v4057->regs;
  int v4833 = v4832[8];
  int * v4834 = v4057->regs;
  int v4835 = v4834[16];
  int * v4836 = v4057->regs;
  int v5935 = v4833 ^ v4835;
  v4836[17] = v5935;
  int v4838 = v4057->timer;
  int v5936 = v4838 + 1;
  v4057->timer = v5936;
  int * v4840 = v4057->regs;
  int v4841 = v4840[9];
  int * v4842 = v4057->regs;
  int v4843 = v4842[6];
  int * v4844 = v4057->regs;
  int v5940 = v4841 ^ v4843;
  v4844[16] = v5940;
  int v4846 = v4057->timer;
  int v5941 = v4846 + 1;
  v4057->timer = v5941;
  int * v4848 = v4057->regs;
  int v4849 = v4848[23];
  int * v4850 = v4057->regs;
  int v4851 = v4850[21];
  int * v4852 = v4057->regs;
  int v5945 = v4849 + v4851;
  v4852[11] = v5945;
  int v4854 = v4057->timer;
  int v5946 = v4854 + 1;
  v4057->timer = v5946;
  int * v4856 = v4057->regs;
  int v4857 = v4856[5];
  int * v4858 = v4057->regs;
  int v4859 = v4858[20];
  int * v4860 = v4057->regs;
  int v5950 = v4857 + v4859;
  v4860[15] = v5950;
  int v4862 = v4057->timer;
  int v5951 = v4862 + 1;
  v4057->timer = v5951;
  int * v4864 = v4057->regs;
  int v4865 = v4864[17];
  int * v4866 = v4057->regs;
  int v4867 = v4866[19];
  int * v4868 = v4057->regs;
  int v5955 = v4865 + v4867;
  v4868[6] = v5955;
  int v4870 = v4057->timer;
  int v5956 = v4870 + 1;
  v4057->timer = v5956;
  int * v4872 = v4057->regs;
  int v4873 = v4872[16];
  int * v4874 = v4057->regs;
  int v4875 = v4874[22];
  int * v4876 = v4057->regs;
  int v5960 = v4873 + v4875;
  v4876[8] = v5960;
  int v4878 = v4057->timer;
  int v5961 = v4878 + 1;
  v4057->timer = v5961;
  int * v4880 = v4057->regs;
  int v4881 = v4880[11];
  int * v4882 = v4057->regs;
  int v5964 = (int)((unsigned int)v4881 >> 23);
  v4882[9] = v5964;
  int v4884 = v4057->timer;
  int v5965 = v4884 + 1;
  v4057->timer = v5965;
  int * v4886 = v4057->regs;
  int v4887 = v4886[11];
  int * v4888 = v4057->regs;
  int v5968 = v4887 << 9;
  v4888[11] = v5968;
  int v4890 = v4057->timer;
  int v5969 = v4890 + 1;
  v4057->timer = v5969;
  int * v4892 = v4057->regs;
  int v4893 = v4892[11];
  int * v4894 = v4057->regs;
  int v4895 = v4894[9];
  int * v4896 = v4057->regs;
  int v5973 = v4893 | v4895;
  v4896[11] = v5973;
  int v4898 = v4057->timer;
  int v5974 = v4898 + 1;
  v4057->timer = v5974;
  int * v4900 = v4057->regs;
  int v4901 = v4900[15];
  int * v4902 = v4057->regs;
  int v5977 = (int)((unsigned int)v4901 >> 23);
  v4902[9] = v5977;
  int v4904 = v4057->timer;
  int v5978 = v4904 + 1;
  v4057->timer = v5978;
  int * v4906 = v4057->regs;
  int v4907 = v4906[15];
  int * v4908 = v4057->regs;
  int v5981 = v4907 << 9;
  v4908[15] = v5981;
  int v4910 = v4057->timer;
  int v5982 = v4910 + 1;
  v4057->timer = v5982;
  int * v4912 = v4057->regs;
  int v4913 = v4912[15];
  int * v4914 = v4057->regs;
  int v4915 = v4914[9];
  int * v4916 = v4057->regs;
  int v5986 = v4913 | v4915;
  v4916[15] = v5986;
  int v4918 = v4057->timer;
  int v5987 = v4918 + 1;
  v4057->timer = v5987;
  int * v4920 = v4057->regs;
  int v4921 = v4920[6];
  int * v4922 = v4057->regs;
  int v5990 = (int)((unsigned int)v4921 >> 23);
  v4922[9] = v5990;
  int v4924 = v4057->timer;
  int v5991 = v4924 + 1;
  v4057->timer = v5991;
  int * v4926 = v4057->regs;
  int v4927 = v4926[6];
  int * v4928 = v4057->regs;
  int v5994 = v4927 << 9;
  v4928[6] = v5994;
  int v4930 = v4057->timer;
  int v5995 = v4930 + 1;
  v4057->timer = v5995;
  int * v4932 = v4057->regs;
  int v4933 = v4932[6];
  int * v4934 = v4057->regs;
  int v4935 = v4934[9];
  int * v4936 = v4057->regs;
  int v5999 = v4933 | v4935;
  v4936[6] = v5999;
  int v4938 = v4057->timer;
  int v6000 = v4938 + 1;
  v4057->timer = v6000;
  int * v4940 = v4057->regs;
  int v4941 = v4940[8];
  int * v4942 = v4057->regs;
  int v6003 = (int)((unsigned int)v4941 >> 23);
  v4942[9] = v6003;
  int v4944 = v4057->timer;
  int v6004 = v4944 + 1;
  v4057->timer = v6004;
  int * v4946 = v4057->regs;
  int v4947 = v4946[8];
  int * v4948 = v4057->regs;
  int v6007 = v4947 << 9;
  v4948[8] = v6007;
  int v4950 = v4057->timer;
  int v6008 = v4950 + 1;
  v4057->timer = v6008;
  int * v4952 = v4057->regs;
  int v4953 = v4952[8];
  int * v4954 = v4057->regs;
  int v4955 = v4954[9];
  int * v4956 = v4057->regs;
  int v6012 = v4953 | v4955;
  v4956[8] = v6012;
  int v4958 = v4057->timer;
  int v6013 = v4958 + 1;
  v4057->timer = v6013;
  int * v4960 = v4057->regs;
  int v4961 = v4960[27];
  int * v4962 = v4057->regs;
  int v4963 = v4962[11];
  int * v4964 = v4057->regs;
  int v6017 = v4961 ^ v4963;
  v4964[27] = v6017;
  int v4966 = v4057->timer;
  int v6018 = v4966 + 1;
  v4057->timer = v6018;
  int * v4968 = v4057->regs;
  int v4969 = v4968[25];
  int * v4970 = v4057->regs;
  int v4971 = v4970[15];
  int * v4972 = v4057->regs;
  int v6022 = v4969 ^ v4971;
  v4972[25] = v6022;
  int v4974 = v4057->timer;
  int v6023 = v4974 + 1;
  v4057->timer = v6023;
  int * v4976 = v4057->regs;
  int v4977 = v4976[26];
  int * v4978 = v4057->regs;
  int v4979 = v4978[6];
  int * v4980 = v4057->regs;
  int v6027 = v4977 ^ v4979;
  v4980[26] = v6027;
  int v4982 = v4057->timer;
  int v6028 = v4982 + 1;
  v4057->timer = v6028;
  int * v4984 = v4057->regs;
  int v4985 = v4984[24];
  int * v4986 = v4057->regs;
  int v4987 = v4986[8];
  int * v4988 = v4057->regs;
  int v6032 = v4985 ^ v4987;
  v4988[24] = v6032;
  int v4990 = v4057->timer;
  int v6033 = v4990 + 1;
  v4057->timer = v6033;
  int * v4992 = v4057->regs;
  int v4993 = v4992[27];
  int * v4994 = v4057->regs;
  int v4995 = v4994[23];
  int * v4996 = v4057->regs;
  int v6037 = v4993 + v4995;
  v4996[11] = v6037;
  int v4998 = v4057->timer;
  int v6038 = v4998 + 1;
  v4057->timer = v6038;
  int * v5000 = v4057->regs;
  int v5001 = v5000[25];
  int * v5002 = v4057->regs;
  int v5003 = v5002[5];
  int * v5004 = v4057->regs;
  int v6042 = v5001 + v5003;
  v5004[15] = v6042;
  int v5006 = v4057->timer;
  int v6043 = v5006 + 1;
  v4057->timer = v6043;
  int * v5008 = v4057->regs;
  int v5009 = v5008[26];
  int * v5010 = v4057->regs;
  int v5011 = v5010[17];
  int * v5012 = v4057->regs;
  int v6047 = v5009 + v5011;
  v5012[6] = v6047;
  int v5014 = v4057->timer;
  int v6048 = v5014 + 1;
  v4057->timer = v6048;
  int * v5016 = v4057->regs;
  int v5017 = v5016[24];
  int * v5018 = v4057->regs;
  int v5019 = v5018[16];
  int * v5020 = v4057->regs;
  int v6052 = v5017 + v5019;
  v5020[8] = v6052;
  int v5022 = v4057->timer;
  int v6053 = v5022 + 1;
  v4057->timer = v6053;
  int * v5024 = v4057->regs;
  int v5025 = v5024[11];
  int * v5026 = v4057->regs;
  int v6056 = (int)((unsigned int)v5025 >> 19);
  v5026[9] = v6056;
  int v5028 = v4057->timer;
  int v6057 = v5028 + 1;
  v4057->timer = v6057;
  int * v5030 = v4057->regs;
  int v5031 = v5030[11];
  int * v5032 = v4057->regs;
  int v6060 = v5031 << 13;
  v5032[11] = v6060;
  int v5034 = v4057->timer;
  int v6061 = v5034 + 1;
  v4057->timer = v6061;
  int * v5036 = v4057->regs;
  int v5037 = v5036[11];
  int * v5038 = v4057->regs;
  int v5039 = v5038[9];
  int * v5040 = v4057->regs;
  int v6065 = v5037 | v5039;
  v5040[11] = v6065;
  int v5042 = v4057->timer;
  int v6066 = v5042 + 1;
  v4057->timer = v6066;
  int * v5044 = v4057->regs;
  int v5045 = v5044[15];
  int * v5046 = v4057->regs;
  int v6069 = (int)((unsigned int)v5045 >> 19);
  v5046[9] = v6069;
  int v5048 = v4057->timer;
  int v6070 = v5048 + 1;
  v4057->timer = v6070;
  int * v5050 = v4057->regs;
  int v5051 = v5050[15];
  int * v5052 = v4057->regs;
  int v6073 = v5051 << 13;
  v5052[15] = v6073;
  int v5054 = v4057->timer;
  int v6074 = v5054 + 1;
  v4057->timer = v6074;
  int * v5056 = v4057->regs;
  int v5057 = v5056[15];
  int * v5058 = v4057->regs;
  int v5059 = v5058[9];
  int * v5060 = v4057->regs;
  int v6078 = v5057 | v5059;
  v5060[15] = v6078;
  int v5062 = v4057->timer;
  int v6079 = v5062 + 1;
  v4057->timer = v6079;
  int * v5064 = v4057->regs;
  int v5065 = v5064[6];
  int * v5066 = v4057->regs;
  int v6082 = (int)((unsigned int)v5065 >> 19);
  v5066[9] = v6082;
  int v5068 = v4057->timer;
  int v6083 = v5068 + 1;
  v4057->timer = v6083;
  int * v5070 = v4057->regs;
  int v5071 = v5070[6];
  int * v5072 = v4057->regs;
  int v6086 = v5071 << 13;
  v5072[6] = v6086;
  int v5074 = v4057->timer;
  int v6087 = v5074 + 1;
  v4057->timer = v6087;
  int * v5076 = v4057->regs;
  int v5077 = v5076[6];
  int * v5078 = v4057->regs;
  int v5079 = v5078[9];
  int * v5080 = v4057->regs;
  int v6091 = v5077 | v5079;
  v5080[6] = v6091;
  int v5082 = v4057->timer;
  int v6092 = v5082 + 1;
  v4057->timer = v6092;
  int * v5084 = v4057->regs;
  int v5085 = v5084[8];
  int * v5086 = v4057->regs;
  int v6095 = (int)((unsigned int)v5085 >> 19);
  v5086[9] = v6095;
  int v5088 = v4057->timer;
  int v6096 = v5088 + 1;
  v4057->timer = v6096;
  int * v5090 = v4057->regs;
  int v5091 = v5090[8];
  int * v5092 = v4057->regs;
  int v6099 = v5091 << 13;
  v5092[8] = v6099;
  int v5094 = v4057->timer;
  int v6100 = v5094 + 1;
  v4057->timer = v6100;
  int * v5096 = v4057->regs;
  int v5097 = v5096[8];
  int * v5098 = v4057->regs;
  int v5099 = v5098[9];
  int * v5100 = v4057->regs;
  int v6104 = v5097 | v5099;
  v5100[8] = v6104;
  int v5102 = v4057->timer;
  int v6105 = v5102 + 1;
  v4057->timer = v6105;
  int * v5104 = v4057->regs;
  int v5105 = v5104[14];
  int * v5106 = v4057->regs;
  int v5107 = v5106[11];
  int * v5108 = v4057->regs;
  int v6109 = v5105 ^ v5107;
  v5108[14] = v6109;
  int v5110 = v4057->timer;
  int v6110 = v5110 + 1;
  v4057->timer = v6110;
  int * v5112 = v4057->regs;
  int v5113 = v5112[12];
  int * v5114 = v4057->regs;
  int v5115 = v5114[15];
  int * v5116 = v4057->regs;
  int v6114 = v5113 ^ v5115;
  v5116[12] = v6114;
  int v5118 = v4057->timer;
  int v6115 = v5118 + 1;
  v4057->timer = v6115;
  int * v5120 = v4057->regs;
  int v5121 = v5120[13];
  int * v5122 = v4057->regs;
  int v5123 = v5122[6];
  int * v5124 = v4057->regs;
  int v6119 = v5121 ^ v5123;
  v5124[13] = v6119;
  int v5126 = v4057->timer;
  int v6120 = v5126 + 1;
  v4057->timer = v6120;
  int * v5128 = v4057->regs;
  int v5129 = v5128[1];
  int * v5130 = v4057->regs;
  int v5131 = v5130[8];
  int * v5132 = v4057->regs;
  int v6124 = v5129 ^ v5131;
  v5132[1] = v6124;
  int v5134 = v4057->timer;
  int v6125 = v5134 + 1;
  v4057->timer = v6125;
  int * v5136 = v4057->regs;
  int v5137 = v5136[14];
  int * v5138 = v4057->regs;
  int v5139 = v5138[27];
  int * v5140 = v4057->regs;
  int v6129 = v5137 + v5139;
  v5140[11] = v6129;
  int v5142 = v4057->timer;
  int v6130 = v5142 + 1;
  v4057->timer = v6130;
  int * v5144 = v4057->regs;
  int v5145 = v5144[12];
  int * v5146 = v4057->regs;
  int v5147 = v5146[25];
  int * v5148 = v4057->regs;
  int v6134 = v5145 + v5147;
  v5148[15] = v6134;
  int v5150 = v4057->timer;
  int v6135 = v5150 + 1;
  v4057->timer = v6135;
  int * v5152 = v4057->regs;
  int v5153 = v5152[13];
  int * v5154 = v4057->regs;
  int v5155 = v5154[26];
  int * v5156 = v4057->regs;
  int v6139 = v5153 + v5155;
  v5156[6] = v6139;
  int v5158 = v4057->timer;
  int v6140 = v5158 + 1;
  v4057->timer = v6140;
  int * v5160 = v4057->regs;
  int v5161 = v5160[1];
  int * v5162 = v4057->regs;
  int v5163 = v5162[24];
  int * v5164 = v4057->regs;
  int v6144 = v5161 + v5163;
  v5164[8] = v6144;
  int v5166 = v4057->timer;
  int v6145 = v5166 + 1;
  v4057->timer = v6145;
  int * v5168 = v4057->regs;
  int v5169 = v5168[11];
  int * v5170 = v4057->regs;
  int v6148 = (int)((unsigned int)v5169 >> 14);
  v5170[9] = v6148;
  int v5172 = v4057->timer;
  int v6149 = v5172 + 1;
  v4057->timer = v6149;
  int * v5174 = v4057->regs;
  int v5175 = v5174[11];
  int * v5176 = v4057->regs;
  int v6152 = v5175 << 18;
  v5176[11] = v6152;
  int v5178 = v4057->timer;
  int v6153 = v5178 + 1;
  v4057->timer = v6153;
  int * v5180 = v4057->regs;
  int v5181 = v5180[11];
  int * v5182 = v4057->regs;
  int v5183 = v5182[9];
  int * v5184 = v4057->regs;
  int v6157 = v5181 | v5183;
  v5184[11] = v6157;
  int v5186 = v4057->timer;
  int v6158 = v5186 + 1;
  v4057->timer = v6158;
  int * v5188 = v4057->regs;
  int v5189 = v5188[15];
  int * v5190 = v4057->regs;
  int v6161 = (int)((unsigned int)v5189 >> 14);
  v5190[9] = v6161;
  int v5192 = v4057->timer;
  int v6162 = v5192 + 1;
  v4057->timer = v6162;
  int * v5194 = v4057->regs;
  int v5195 = v5194[15];
  int * v5196 = v4057->regs;
  int v6165 = v5195 << 18;
  v5196[15] = v6165;
  int v5198 = v4057->timer;
  int v6166 = v5198 + 1;
  v4057->timer = v6166;
  int * v5200 = v4057->regs;
  int v5201 = v5200[15];
  int * v5202 = v4057->regs;
  int v5203 = v5202[9];
  int * v5204 = v4057->regs;
  int v6170 = v5201 | v5203;
  v5204[15] = v6170;
  int v5206 = v4057->timer;
  int v6171 = v5206 + 1;
  v4057->timer = v6171;
  int * v5208 = v4057->regs;
  int v5209 = v5208[6];
  int * v5210 = v4057->regs;
  int v6174 = (int)((unsigned int)v5209 >> 14);
  v5210[9] = v6174;
  int v5212 = v4057->timer;
  int v6175 = v5212 + 1;
  v4057->timer = v6175;
  int * v5214 = v4057->regs;
  int v5215 = v5214[6];
  int * v5216 = v4057->regs;
  int v6178 = v5215 << 18;
  v5216[6] = v6178;
  int v5218 = v4057->timer;
  int v6179 = v5218 + 1;
  v4057->timer = v6179;
  int * v5220 = v4057->regs;
  int v5221 = v5220[6];
  int * v5222 = v4057->regs;
  int v5223 = v5222[9];
  int * v5224 = v4057->regs;
  int v6183 = v5221 | v5223;
  v5224[6] = v6183;
  int v5226 = v4057->timer;
  int v6184 = v5226 + 1;
  v4057->timer = v6184;
  int * v5228 = v4057->regs;
  int v5229 = v5228[8];
  int * v5230 = v4057->regs;
  int v6187 = (int)((unsigned int)v5229 >> 14);
  v5230[9] = v6187;
  int v5232 = v4057->timer;
  int v6188 = v5232 + 1;
  v4057->timer = v6188;
  int * v5234 = v4057->regs;
  int v5235 = v5234[8];
  int * v5236 = v4057->regs;
  int v6191 = v5235 << 18;
  v5236[8] = v6191;
  int v5238 = v4057->timer;
  int v6192 = v5238 + 1;
  v4057->timer = v6192;
  int * v5240 = v4057->regs;
  int v5241 = v5240[8];
  int * v5242 = v4057->regs;
  int v5243 = v5242[9];
  int * v5244 = v4057->regs;
  int v6196 = v5241 | v5243;
  v5244[8] = v6196;
  int v5246 = v4057->timer;
  int v6197 = v5246 + 1;
  v4057->timer = v6197;
  int * v5248 = v4057->regs;
  int v5249 = v5248[21];
  int * v5250 = v4057->regs;
  int v5251 = v5250[11];
  int * v5252 = v4057->regs;
  int v6201 = v5249 ^ v5251;
  v5252[21] = v6201;
  int v5254 = v4057->timer;
  int v6202 = v5254 + 1;
  v4057->timer = v6202;
  int * v5256 = v4057->regs;
  int v5257 = v5256[20];
  int * v5258 = v4057->regs;
  int v5259 = v5258[15];
  int * v5260 = v4057->regs;
  int v6206 = v5257 ^ v5259;
  v5260[11] = v6206;
  int v5262 = v4057->timer;
  int v6207 = v5262 + 1;
  v4057->timer = v6207;
  int * v5264 = v4057->regs;
  int v5265 = v5264[19];
  int * v5266 = v4057->regs;
  int v5267 = v5266[6];
  int * v5268 = v4057->regs;
  int v6211 = v5265 ^ v5267;
  v5268[19] = v6211;
  int v5270 = v4057->timer;
  int v6212 = v5270 + 1;
  v4057->timer = v6212;
  int * v5272 = v4057->regs;
  int v5273 = v5272[22];
  int * v5274 = v4057->regs;
  int v5275 = v5274[8];
  int * v5276 = v4057->regs;
  int v6216 = v5273 ^ v5275;
  v5276[22] = v6216;
  int v5278 = v4057->timer;
  int v6217 = v5278 + 1;
  v4057->timer = v6217;
  int * v5280 = v4057->regs;
  int v5281 = v5280[30];
  int * v5282 = v4057->regs;
  int v6221 = v5281 + 1;
  v5282[30] = v6221;
  int * v5284 = v4057->regs;
  int v5285 = v5284[31];
  bool v6224 = (v5285 ^ -2147483648) < -2147483648;
  struct StateT * v5406;
  if (v6224) {
    int v5286 = v4057->timer;
    int v6225 = v5286 + 15;
    v4057->timer = v6225;
    int * v5288 = v4057->saved_regs;
    int v5289 = v5288[30];
    int * v5290 = v4057->regs;
    v5290[30] = v5289;
    int * v5292 = v4057->saved_regs;
    int v5293 = v5292[29];
    int * v5294 = v4057->regs;
    v5294[29] = v5293;
    int * v5296 = v4057->saved_regs;
    int v5297 = v5296[28];
    int * v5298 = v4057->regs;
    v5298[28] = v5297;
    int * v5300 = v4057->saved_regs;
    int v5301 = v5300[7];
    int * v5302 = v4057->regs;
    v5302[7] = v5301;
    int * v5304 = v4057->saved_regs;
    int v5305 = v5304[12];
    int * v5306 = v4057->regs;
    v5306[12] = v5305;
    int * v5308 = v4057->saved_regs;
    int v5309 = v5308[14];
    int * v5310 = v4057->regs;
    v5310[14] = v5309;
    int * v5312 = v4057->saved_regs;
    int v5313 = v5312[27];
    int * v5314 = v4057->regs;
    v5314[27] = v5313;
    int * v5316 = v4057->saved_regs;
    int v5317 = v5316[23];
    int * v5318 = v4057->regs;
    v5318[23] = v5317;
    int * v5320 = v4057->saved_regs;
    int v5321 = v5320[13];
    int * v5322 = v4057->regs;
    v5322[13] = v5321;
    int * v5324 = v4057->saved_regs;
    int v5325 = v5324[15];
    int * v5326 = v4057->regs;
    v5326[15] = v5325;
    int * v5328 = v4057->saved_regs;
    int v5329 = v5328[20];
    int * v5330 = v4057->regs;
    v5330[20] = v5329;
    int * v5332 = v4057->saved_regs;
    int v5333 = v5332[18];
    int * v5334 = v4057->regs;
    v5334[18] = v5333;
    int * v5336 = v4057->saved_regs;
    int v5337 = v5336[8];
    int * v5338 = v4057->regs;
    v5338[8] = v5337;
    int * v5340 = v4057->saved_regs;
    int v5341 = v5340[9];
    int * v5342 = v4057->regs;
    v5342[9] = v5341;
    int * v5344 = v4057->saved_regs;
    int v5345 = v5344[1];
    int * v5346 = v4057->regs;
    v5346[1] = v5345;
    int * v5348 = v4057->saved_regs;
    int v5349 = v5348[26];
    int * v5350 = v4057->regs;
    v5350[26] = v5349;
    int * v5352 = v4057->saved_regs;
    int v5353 = v5352[24];
    int * v5354 = v4057->regs;
    v5354[24] = v5353;
    int * v5356 = v4057->saved_regs;
    int v5357 = v5356[25];
    int * v5358 = v4057->regs;
    v5358[25] = v5357;
    int * v5360 = v4057->saved_regs;
    int v5361 = v5360[6];
    int * v5362 = v4057->regs;
    v5362[6] = v5361;
    int * v5364 = v4057->saved_regs;
    int v5365 = v5364[16];
    int * v5366 = v4057->regs;
    v5366[16] = v5365;
    int * v5368 = v4057->saved_regs;
    int v5369 = v5368[17];
    int * v5370 = v4057->regs;
    v5370[17] = v5369;
    int * v5372 = v4057->saved_regs;
    int v5373 = v5372[5];
    int * v5374 = v4057->regs;
    v5374[5] = v5373;
    int * v5376 = v4057->saved_regs;
    int v5377 = v5376[21];
    int * v5378 = v4057->regs;
    v5378[21] = v5377;
    int * v5380 = v4057->saved_regs;
    int v5381 = v5380[19];
    int * v5382 = v4057->regs;
    v5382[19] = v5381;
    int * v5384 = v4057->saved_regs;
    int v5385 = v5384[22];
    int * v5386 = v4057->regs;
    v5386[22] = v5385;
    int * v5388 = v4057->saved_regs;
    int v5389 = v5388[11];
    int * v5390 = v4057->regs;
    v5390[11] = v5389;
    struct StateT * v5392 = slot_213(v4057);
    v5406 = v5392;
  } else {
    int v5394 = v4057->timer;
    int v6309 = v5394 + 1;
    v4057->timer = v6309;
    int * v5396 = v4057->regs;
    int v5397 = v5396[31];
    int * v5398 = v4057->regs;
    int v5399 = v5398[30];
    bool v6312 = (v5397 ^ -2147483648) >= (v5399 ^ -2147483648);
    struct StateT * v5404;
    if (v6312) {
      struct StateT * v5400 = slot_51(v4057);
      v5404 = v5400;
    } else {
      struct StateT * v5402 = slot_213(v4057);
      v5404 = v5402;
    }
    v5406 = v5404;
  }
  return v5406;
}

struct StateT * slot_37(struct StateT * v3181) {
  int v3182 = v3181->timer;
  int v3236 = v3182 + 1;
  v3181->timer = v3236;
  int * v3184 = v3181->regs;
  int v3185 = v3184[2];
  int * v3186 = v3181->regs;
  int v3187 = v3186[25];
  int * v3188 = v3181->cache_keys;
  int v3189 = v3188[0];
  bool v3243 = v3189 == ((int)((unsigned int)(v3185 + 16) >> 2));
  int v3233;
  if (v3243) {
    int * v3190 = v3181->cache_vals;
    v3190[0] = v3187;
    v3233 = v3187;
  } else {
    int * v3193 = v3181->cache_keys;
    int v3194 = v3193[1];
    bool v3248 = v3194 == ((int)((unsigned int)(v3185 + 16) >> 2));
    int v3231;
    if (v3248) {
      int * v3195 = v3181->cache_keys;
      int * v3196 = v3181->cache_keys;
      int v3197 = v3196[0];
      v3195[1] = v3197;
      int * v3199 = v3181->cache_vals;
      int * v3200 = v3181->cache_vals;
      int v3201 = v3200[0];
      v3199[1] = v3201;
      int * v3203 = v3181->cache_keys;
      int v3256 = (int)((unsigned int)(v3185 + 16) >> 2);
      v3203[0] = v3256;
      int * v3205 = v3181->cache_vals;
      v3205[0] = v3187;
      int v3207 = v3181->timer;
      int v3259 = v3207 + 1;
      v3181->timer = v3259;
      v3231 = v3187;
    } else {
      int * v3210 = v3181->mem;
      int * v3211 = v3181->cache_keys;
      int v3212 = v3211[1];
      int * v3213 = v3181->cache_vals;
      int v3214 = v3213[1];
      v3210[v3212] = v3214;
      int * v3216 = v3181->cache_keys;
      int * v3217 = v3181->cache_keys;
      int v3218 = v3217[0];
      v3216[1] = v3218;
      int * v3220 = v3181->cache_vals;
      int * v3221 = v3181->cache_vals;
      int v3222 = v3221[0];
      v3220[1] = v3222;
      int * v3224 = v3181->cache_keys;
      int v3272 = (int)((unsigned int)(v3185 + 16) >> 2);
      v3224[0] = v3272;
      int * v3226 = v3181->cache_vals;
      v3226[0] = v3187;
      int v3228 = v3181->timer;
      int v3275 = v3228 + 100;
      v3181->timer = v3275;
      v3231 = v3187;
    }
    v3233 = v3231;
  }
  struct StateT * v3234 = slot_38(v3181);
  return v3234;
}

struct StateT * slot_114(struct StateT * v12469) {
  int v12470 = v12469->timer;
  int v12480 = v12470 + 1;
  v12469->timer = v12480;
  int * v12472 = v12469->regs;
  int v12473 = v12472[8];
  int * v12474 = v12469->regs;
  int v12475 = v12474[25];
  int * v12476 = v12469->regs;
  int v12487 = v12473 + v12475;
  v12476[5] = v12487;
  struct StateT * v12478 = slot_115(v12469);
  return v12478;
}

struct StateT * slot_135(struct StateT * v12867) {
  int v12868 = v12867->timer;
  int v12876 = v12868 + 1;
  v12867->timer = v12876;
  int * v12870 = v12867->regs;
  int v12871 = v12870[15];
  int * v12872 = v12867->regs;
  int v12881 = (int)((unsigned int)v12871 >> 25);
  v12872[5] = v12881;
  struct StateT * v12874 = slot_136(v12867);
  return v12874;
}

struct StateT * slot_248(struct StateT * v8548) {
  int v8549 = v8548->timer;
  int v8603 = v8549 + 1;
  v8548->timer = v8603;
  int * v8551 = v8548->regs;
  int v8552 = v8551[10];
  int * v8553 = v8548->regs;
  int v8554 = v8553[28];
  int * v8555 = v8548->cache_keys;
  int v8556 = v8555[0];
  bool v8610 = v8556 == ((int)((unsigned int)(v8552 + 8) >> 2));
  int v8600;
  if (v8610) {
    int * v8557 = v8548->cache_vals;
    v8557[0] = v8554;
    v8600 = v8554;
  } else {
    int * v8560 = v8548->cache_keys;
    int v8561 = v8560[1];
    bool v8615 = v8561 == ((int)((unsigned int)(v8552 + 8) >> 2));
    int v8598;
    if (v8615) {
      int * v8562 = v8548->cache_keys;
      int * v8563 = v8548->cache_keys;
      int v8564 = v8563[0];
      v8562[1] = v8564;
      int * v8566 = v8548->cache_vals;
      int * v8567 = v8548->cache_vals;
      int v8568 = v8567[0];
      v8566[1] = v8568;
      int * v8570 = v8548->cache_keys;
      int v8623 = (int)((unsigned int)(v8552 + 8) >> 2);
      v8570[0] = v8623;
      int * v8572 = v8548->cache_vals;
      v8572[0] = v8554;
      int v8574 = v8548->timer;
      int v8626 = v8574 + 1;
      v8548->timer = v8626;
      v8598 = v8554;
    } else {
      int * v8577 = v8548->mem;
      int * v8578 = v8548->cache_keys;
      int v8579 = v8578[1];
      int * v8580 = v8548->cache_vals;
      int v8581 = v8580[1];
      v8577[v8579] = v8581;
      int * v8583 = v8548->cache_keys;
      int * v8584 = v8548->cache_keys;
      int v8585 = v8584[0];
      v8583[1] = v8585;
      int * v8587 = v8548->cache_vals;
      int * v8588 = v8548->cache_vals;
      int v8589 = v8588[0];
      v8587[1] = v8589;
      int * v8591 = v8548->cache_keys;
      int v8639 = (int)((unsigned int)(v8552 + 8) >> 2);
      v8591[0] = v8639;
      int * v8593 = v8548->cache_vals;
      v8593[0] = v8554;
      int v8595 = v8548->timer;
      int v8642 = v8595 + 100;
      v8548->timer = v8642;
      v8598 = v8554;
    }
    v8600 = v8598;
  }
  struct StateT * v8601 = slot_249(v8548);
  return v8601;
}

struct StateT * slot_257(struct StateT * v9614) {
  int v9615 = v9614->timer;
  int v9669 = v9615 + 1;
  v9614->timer = v9669;
  int * v9617 = v9614->regs;
  int v9618 = v9617[10];
  int * v9619 = v9614->regs;
  int v9620 = v9619[17];
  int * v9621 = v9614->cache_keys;
  int v9622 = v9621[0];
  bool v9676 = v9622 == ((int)((unsigned int)(v9618 + 44) >> 2));
  int v9666;
  if (v9676) {
    int * v9623 = v9614->cache_vals;
    v9623[0] = v9620;
    v9666 = v9620;
  } else {
    int * v9626 = v9614->cache_keys;
    int v9627 = v9626[1];
    bool v9681 = v9627 == ((int)((unsigned int)(v9618 + 44) >> 2));
    int v9664;
    if (v9681) {
      int * v9628 = v9614->cache_keys;
      int * v9629 = v9614->cache_keys;
      int v9630 = v9629[0];
      v9628[1] = v9630;
      int * v9632 = v9614->cache_vals;
      int * v9633 = v9614->cache_vals;
      int v9634 = v9633[0];
      v9632[1] = v9634;
      int * v9636 = v9614->cache_keys;
      int v9689 = (int)((unsigned int)(v9618 + 44) >> 2);
      v9636[0] = v9689;
      int * v9638 = v9614->cache_vals;
      v9638[0] = v9620;
      int v9640 = v9614->timer;
      int v9692 = v9640 + 1;
      v9614->timer = v9692;
      v9664 = v9620;
    } else {
      int * v9643 = v9614->mem;
      int * v9644 = v9614->cache_keys;
      int v9645 = v9644[1];
      int * v9646 = v9614->cache_vals;
      int v9647 = v9646[1];
      v9643[v9645] = v9647;
      int * v9649 = v9614->cache_keys;
      int * v9650 = v9614->cache_keys;
      int v9651 = v9650[0];
      v9649[1] = v9651;
      int * v9653 = v9614->cache_vals;
      int * v9654 = v9614->cache_vals;
      int v9655 = v9654[0];
      v9653[1] = v9655;
      int * v9657 = v9614->cache_keys;
      int v9705 = (int)((unsigned int)(v9618 + 44) >> 2);
      v9657[0] = v9705;
      int * v9659 = v9614->cache_vals;
      v9659[0] = v9620;
      int v9661 = v9614->timer;
      int v9708 = v9661 + 100;
      v9614->timer = v9708;
      v9664 = v9620;
    }
    v9666 = v9664;
  }
  struct StateT * v9667 = slot_258(v9614);
  return v9667;
}

struct StateT * slot_59(struct StateT * v6809) {
  int v6810 = v6809->timer;
  int v6818 = v6810 + 1;
  v6809->timer = v6818;
  int * v6812 = v6809->regs;
  int v6813 = v6812[20];
  int * v6814 = v6809->regs;
  int v6822 = v6813 << 7;
  v6814[20] = v6822;
  struct StateT * v6816 = slot_60(v6809);
  return v6816;
}

struct StateT * slot_192(struct StateT * v13936) {
  int v13937 = v13936->timer;
  int v13947 = v13937 + 1;
  v13936->timer = v13947;
  int * v13939 = v13936->regs;
  int v13940 = v13939[12];
  int * v13941 = v13936->regs;
  int v13942 = v13941[25];
  int * v13943 = v13936->regs;
  int v13954 = v13940 + v13942;
  v13943[15] = v13954;
  struct StateT * v13945 = slot_193(v13936);
  return v13945;
}

struct StateT * slot_40(struct StateT * v3474) {
  int v3475 = v3474->timer;
  int v3529 = v3475 + 1;
  v3474->timer = v3529;
  int * v3477 = v3474->regs;
  int v3478 = v3477[2];
  int * v3479 = v3474->regs;
  int v3480 = v3479[24];
  int * v3481 = v3474->cache_keys;
  int v3482 = v3481[0];
  bool v3536 = v3482 == ((int)((unsigned int)(v3478 + 36) >> 2));
  int v3526;
  if (v3536) {
    int * v3483 = v3474->cache_vals;
    v3483[0] = v3480;
    v3526 = v3480;
  } else {
    int * v3486 = v3474->cache_keys;
    int v3487 = v3486[1];
    bool v3541 = v3487 == ((int)((unsigned int)(v3478 + 36) >> 2));
    int v3524;
    if (v3541) {
      int * v3488 = v3474->cache_keys;
      int * v3489 = v3474->cache_keys;
      int v3490 = v3489[0];
      v3488[1] = v3490;
      int * v3492 = v3474->cache_vals;
      int * v3493 = v3474->cache_vals;
      int v3494 = v3493[0];
      v3492[1] = v3494;
      int * v3496 = v3474->cache_keys;
      int v3549 = (int)((unsigned int)(v3478 + 36) >> 2);
      v3496[0] = v3549;
      int * v3498 = v3474->cache_vals;
      v3498[0] = v3480;
      int v3500 = v3474->timer;
      int v3552 = v3500 + 1;
      v3474->timer = v3552;
      v3524 = v3480;
    } else {
      int * v3503 = v3474->mem;
      int * v3504 = v3474->cache_keys;
      int v3505 = v3504[1];
      int * v3506 = v3474->cache_vals;
      int v3507 = v3506[1];
      v3503[v3505] = v3507;
      int * v3509 = v3474->cache_keys;
      int * v3510 = v3474->cache_keys;
      int v3511 = v3510[0];
      v3509[1] = v3511;
      int * v3513 = v3474->cache_vals;
      int * v3514 = v3474->cache_vals;
      int v3515 = v3514[0];
      v3513[1] = v3515;
      int * v3517 = v3474->cache_keys;
      int v3565 = (int)((unsigned int)(v3478 + 36) >> 2);
      v3517[0] = v3565;
      int * v3519 = v3474->cache_vals;
      v3519[0] = v3480;
      int v3521 = v3474->timer;
      int v3568 = v3521 + 100;
      v3474->timer = v3568;
      v3524 = v3480;
    }
    v3526 = v3524;
  }
  struct StateT * v3527 = slot_41(v3474);
  return v3527;
}

struct StateT * slot_48(struct StateT * v3941) {
  int v3942 = v3941->timer;
  int v4006 = v3942 + 1;
  v3941->timer = v4006;
  int * v3944 = v3941->regs;
  int v3945 = v3944[2];
  int * v3946 = v3941->regs;
  int v3947 = v3946[15];
  int * v3948 = v3941->saved_regs;
  int * v3949 = v3941->regs;
  int v3950 = v3949[13];
  v3948[13] = v3950;
  int v3952 = v3941->timer;
  int v4015 = v3952 + 1;
  v3941->timer = v4015;
  int * v3954 = v3941->regs;
  int v3955 = v3954[15];
  int * v3956 = v3941->regs;
  v3956[13] = v3955;
  int * v3958 = v3941->cache_keys;
  int v3959 = v3958[0];
  bool v4021 = v3959 == ((int)((unsigned int)(v3945 + 24) >> 2));
  int v4003;
  if (v4021) {
    int * v3960 = v3941->cache_vals;
    v3960[0] = v3947;
    v4003 = v3947;
  } else {
    int * v3963 = v3941->cache_keys;
    int v3964 = v3963[1];
    bool v4026 = v3964 == ((int)((unsigned int)(v3945 + 24) >> 2));
    int v4001;
    if (v4026) {
      int * v3965 = v3941->cache_keys;
      int * v3966 = v3941->cache_keys;
      int v3967 = v3966[0];
      v3965[1] = v3967;
      int * v3969 = v3941->cache_vals;
      int * v3970 = v3941->cache_vals;
      int v3971 = v3970[0];
      v3969[1] = v3971;
      int * v3973 = v3941->cache_keys;
      int v4034 = (int)((unsigned int)(v3945 + 24) >> 2);
      v3973[0] = v4034;
      int * v3975 = v3941->cache_vals;
      v3975[0] = v3947;
      int v3977 = v3941->timer;
      int v4037 = v3977 + 1;
      v3941->timer = v4037;
      v4001 = v3947;
    } else {
      int * v3980 = v3941->mem;
      int * v3981 = v3941->cache_keys;
      int v3982 = v3981[1];
      int * v3983 = v3941->cache_vals;
      int v3984 = v3983[1];
      v3980[v3982] = v3984;
      int * v3986 = v3941->cache_keys;
      int * v3987 = v3941->cache_keys;
      int v3988 = v3987[0];
      v3986[1] = v3988;
      int * v3990 = v3941->cache_vals;
      int * v3991 = v3941->cache_vals;
      int v3992 = v3991[0];
      v3990[1] = v3992;
      int * v3994 = v3941->cache_keys;
      int v4050 = (int)((unsigned int)(v3945 + 24) >> 2);
      v3994[0] = v4050;
      int * v3996 = v3941->cache_vals;
      v3996[0] = v3947;
      int v3998 = v3941->timer;
      int v4053 = v3998 + 100;
      v3941->timer = v4053;
      v4001 = v3947;
    }
    v4003 = v4001;
  }
  struct StateT * v4004 = slot_50(v3941);
  return v4004;
}

struct StateT * slot_77(struct StateT * v8081) {
  int v8082 = v8081->timer;
  int v8092 = v8082 + 1;
  v8081->timer = v8092;
  int * v8084 = v8081->regs;
  int v8085 = v8084[15];
  int * v8086 = v8081->regs;
  int v8087 = v8086[20];
  int * v8088 = v8081->regs;
  int v8098 = v8085 | v8087;
  v8088[15] = v8098;
  struct StateT * v8090 = slot_78(v8081);
  return v8090;
}

struct StateT * slot_85(struct StateT * v8532) {
  int v8533 = v8532->timer;
  int v8541 = v8533 + 1;
  v8532->timer = v8541;
  int * v8535 = v8532->regs;
  int v8536 = v8535[18];
  int * v8537 = v8532->regs;
  int v8545 = v8536 << 9;
  v8537[18] = v8545;
  struct StateT * v8539 = slot_86(v8532);
  return v8539;
}

struct StateT * slot_75(struct StateT * v8016) {
  int v8017 = v8016->timer;
  int v8025 = v8017 + 1;
  v8016->timer = v8025;
  int * v8019 = v8016->regs;
  int v8020 = v8019[15];
  int * v8021 = v8016->regs;
  int v8030 = (int)((unsigned int)v8020 >> 23);
  v8021[20] = v8030;
  struct StateT * v8023 = slot_76(v8016);
  return v8023;
}

struct StateT * slot_72(struct StateT * v7815) {
  int v7816 = v7815->timer;
  int v7826 = v7816 + 1;
  v7815->timer = v7826;
  int * v7818 = v7815->regs;
  int v7819 = v7818[13];
  int * v7820 = v7815->regs;
  int v7821 = v7820[11];
  int * v7822 = v7815->regs;
  int v7833 = v7819 + v7821;
  v7822[8] = v7833;
  struct StateT * v7824 = slot_73(v7815);
  return v7824;
}

struct StateT * slot_119(struct StateT * v12560) {
  int v12561 = v12560->timer;
  int v12569 = v12561 + 1;
  v12560->timer = v12569;
  int * v12563 = v12560->regs;
  int v12564 = v12563[16];
  int * v12565 = v12560->regs;
  int v12573 = v12564 << 18;
  v12565[16] = v12573;
  struct StateT * v12567 = slot_120(v12560);
  return v12567;
}

struct StateT * slot_71(struct StateT * v7774) {
  int v7775 = v7774->timer;
  int v7785 = v7775 + 1;
  v7774->timer = v7785;
  int * v7777 = v7774->regs;
  int v7778 = v7777[12];
  int * v7779 = v7774->regs;
  int v7780 = v7779[21];
  int * v7781 = v7774->regs;
  int v7792 = v7778 + v7780;
  v7781[15] = v7792;
  struct StateT * v7783 = slot_72(v7774);
  return v7783;
}

struct StateT * slot_101(struct StateT * v11250) {
  int v11251 = v11250->timer;
  int v11259 = v11251 + 1;
  v11250->timer = v11259;
  int * v11253 = v11250->regs;
  int v11254 = v11253[9];
  int * v11255 = v11250->regs;
  int v11264 = (int)((unsigned int)v11254 >> 19);
  v11255[20] = v11264;
  struct StateT * v11257 = slot_102(v11250);
  return v11257;
}

struct StateT * slot_276(struct StateT * v12380) {
  int v12381 = v12380->timer;
  int v12384 = v12381 + 1;
  v12380->timer = v12384;
  return v12380;
}

struct StateT * slot_108(struct StateT * v12323) {
  int v12324 = v12323->timer;
  int v12334 = v12324 + 1;
  v12323->timer = v12334;
  int * v12326 = v12323->regs;
  int v12327 = v12326[23];
  int * v12328 = v12323->regs;
  int v12329 = v12328[8];
  int * v12330 = v12323->regs;
  int v12340 = v12327 ^ v12329;
  v12330[23] = v12340;
  struct StateT * v12332 = slot_109(v12323);
  return v12332;
}

struct StateT * slot_116(struct StateT * v12507) {
  int v12508 = v12507->timer;
  int v12516 = v12508 + 1;
  v12507->timer = v12516;
  int * v12510 = v12507->regs;
  int v12511 = v12510[15];
  int * v12512 = v12507->regs;
  int v12520 = v12511 << 18;
  v12512[15] = v12520;
  struct StateT * v12514 = slot_117(v12507);
  return v12514;
}

struct StateT * slot_93(struct StateT * v9474) {
  int v9475 = v9474->timer;
  int v9485 = v9475 + 1;
  v9474->timer = v9485;
  int * v9477 = v9474->regs;
  int v9478 = v9477[27];
  int * v9479 = v9474->regs;
  int v9480 = v9479[1];
  int * v9481 = v9474->regs;
  int v9492 = v9478 + v9480;
  v9481[9] = v9492;
  struct StateT * v9483 = slot_94(v9474);
  return v9483;
}

struct StateT * slot_266(struct StateT * v10915) {
  int v10916 = v10915->timer;
  int v10974 = v10916 + 1;
  v10915->timer = v10974;
  int * v10918 = v10915->regs;
  int v10919 = v10918[2];
  int * v10920 = v10915->cache_keys;
  int v10921 = v10920[0];
  bool v10979 = v10921 == ((int)((unsigned int)(v10919 + 76) >> 2));
  int v10969;
  if (v10979) {
    int * v10922 = v10915->cache_vals;
    int v10923 = v10922[0];
    v10969 = v10923;
  } else {
    int * v10925 = v10915->cache_keys;
    int v10926 = v10925[1];
    bool v10984 = v10926 == ((int)((unsigned int)(v10919 + 76) >> 2));
    int v10967;
    if (v10984) {
      int * v10927 = v10915->cache_vals;
      int v10928 = v10927[1];
      int * v10929 = v10915->cache_keys;
      int * v10930 = v10915->cache_keys;
      int v10931 = v10930[0];
      v10929[1] = v10931;
      int * v10933 = v10915->cache_vals;
      int * v10934 = v10915->cache_vals;
      int v10935 = v10934[0];
      v10933[1] = v10935;
      int * v10937 = v10915->cache_keys;
      int v10993 = (int)((unsigned int)(v10919 + 76) >> 2);
      v10937[0] = v10993;
      int * v10939 = v10915->cache_vals;
      v10939[0] = v10928;
      int v10941 = v10915->timer;
      int v10996 = v10941 + 1;
      v10915->timer = v10996;
      v10967 = v10928;
    } else {
      int * v10944 = v10915->mem;
      int v10998 = (int)((unsigned int)(v10919 + 76) >> 2);
      int v10945 = v10944[v10998];
      int * v10946 = v10915->mem;
      int * v10947 = v10915->cache_keys;
      int v10948 = v10947[1];
      int * v10949 = v10915->cache_vals;
      int v10950 = v10949[1];
      v10946[v10948] = v10950;
      int * v10952 = v10915->cache_keys;
      int * v10953 = v10915->cache_keys;
      int v10954 = v10953[0];
      v10952[1] = v10954;
      int * v10956 = v10915->cache_vals;
      int * v10957 = v10915->cache_vals;
      int v10958 = v10957[0];
      v10956[1] = v10958;
      int * v10960 = v10915->cache_keys;
      v10960[0] = v10998;
      int * v10962 = v10915->cache_vals;
      v10962[0] = v10945;
      int v10964 = v10915->timer;
      int v11013 = v10964 + 100;
      v10915->timer = v11013;
      v10967 = v10945;
    }
    v10969 = v10967;
  }
  int * v10970 = v10915->regs;
  v10970[19] = v10969;
  struct StateT * v10972 = slot_267(v10915);
  return v10972;
}

struct StateT * slot_88(struct StateT * v8882) {
  int v8883 = v8882->timer;
  int v8893 = v8883 + 1;
  v8882->timer = v8893;
  int * v8885 = v8882->regs;
  int v8886 = v8885[24];
  int * v8887 = v8882->regs;
  int v8888 = v8887[8];
  int * v8889 = v8882->regs;
  int v8899 = v8886 ^ v8888;
  v8889[24] = v8899;
  struct StateT * v8891 = slot_89(v8882);
  return v8891;
}

struct StateT * slot_96(struct StateT * v9827) {
  int v9828 = v9827->timer;
  int v9836 = v9828 + 1;
  v9827->timer = v9836;
  int * v9830 = v9827->regs;
  int v9831 = v9830[15];
  int * v9832 = v9827->regs;
  int v9840 = v9831 << 13;
  v9832[15] = v9840;
  struct StateT * v9834 = slot_97(v9827);
  return v9834;
}

struct StateT * slot_215(struct StateT * v6401) {
  int v6402 = v6401->timer;
  int v6408 = v6402 + 1;
  v6401->timer = v6408;
  int * v6404 = v6401->regs;
  v6404[15] = 1634762752;
  struct StateT * v6406 = slot_216(v6401);
  return v6406;
}

struct StateT * slot_234(struct StateT * v7795) {
  int v7796 = v7795->timer;
  int v7806 = v7796 + 1;
  v7795->timer = v7806;
  int * v7798 = v7795->regs;
  int v7799 = v7798[24];
  int * v7800 = v7795->regs;
  int v7801 = v7800[30];
  int * v7802 = v7795->regs;
  int v7812 = v7799 + v7801;
  v7802[24] = v7812;
  struct StateT * v7804 = slot_235(v7795);
  return v7804;
}

struct StateT * slot_218(struct StateT * v6598) {
  int v6599 = v6598->timer;
  int v6609 = v6599 + 1;
  v6598->timer = v6609;
  int * v6601 = v6598->regs;
  int v6602 = v6601[12];
  int * v6603 = v6598->regs;
  int v6604 = v6603[6];
  int * v6605 = v6598->regs;
  int v6615 = v6602 + v6604;
  v6605[12] = v6615;
  struct StateT * v6607 = slot_219(v6598);
  return v6607;
}

struct StateT * slot_220(struct StateT * v6667) {
  int v6668 = v6667->timer;
  int v6726 = v6668 + 1;
  v6667->timer = v6726;
  int * v6670 = v6667->regs;
  int v6671 = v6670[2];
  int * v6672 = v6667->cache_keys;
  int v6673 = v6672[0];
  bool v6731 = v6673 == ((int)((unsigned int)(v6671 + 12) >> 2));
  int v6721;
  if (v6731) {
    int * v6674 = v6667->cache_vals;
    int v6675 = v6674[0];
    v6721 = v6675;
  } else {
    int * v6677 = v6667->cache_keys;
    int v6678 = v6677[1];
    bool v6736 = v6678 == ((int)((unsigned int)(v6671 + 12) >> 2));
    int v6719;
    if (v6736) {
      int * v6679 = v6667->cache_vals;
      int v6680 = v6679[1];
      int * v6681 = v6667->cache_keys;
      int * v6682 = v6667->cache_keys;
      int v6683 = v6682[0];
      v6681[1] = v6683;
      int * v6685 = v6667->cache_vals;
      int * v6686 = v6667->cache_vals;
      int v6687 = v6686[0];
      v6685[1] = v6687;
      int * v6689 = v6667->cache_keys;
      int v6745 = (int)((unsigned int)(v6671 + 12) >> 2);
      v6689[0] = v6745;
      int * v6691 = v6667->cache_vals;
      v6691[0] = v6680;
      int v6693 = v6667->timer;
      int v6748 = v6693 + 1;
      v6667->timer = v6748;
      v6719 = v6680;
    } else {
      int * v6696 = v6667->mem;
      int v6750 = (int)((unsigned int)(v6671 + 12) >> 2);
      int v6697 = v6696[v6750];
      int * v6698 = v6667->mem;
      int * v6699 = v6667->cache_keys;
      int v6700 = v6699[1];
      int * v6701 = v6667->cache_vals;
      int v6702 = v6701[1];
      v6698[v6700] = v6702;
      int * v6704 = v6667->cache_keys;
      int * v6705 = v6667->cache_keys;
      int v6706 = v6705[0];
      v6704[1] = v6706;
      int * v6708 = v6667->cache_vals;
      int * v6709 = v6667->cache_vals;
      int v6710 = v6709[0];
      v6708[1] = v6710;
      int * v6712 = v6667->cache_keys;
      v6712[0] = v6750;
      int * v6714 = v6667->cache_vals;
      v6714[0] = v6697;
      int v6716 = v6667->timer;
      int v6765 = v6716 + 100;
      v6667->timer = v6765;
      v6719 = v6697;
    }
    v6721 = v6719;
  }
  int * v6722 = v6667->regs;
  v6722[7] = v6721;
  struct StateT * v6724 = slot_221(v6667);
  return v6724;
}

struct StateT * slot_134(struct StateT * v12846) {
  int v12847 = v12846->timer;
  int v12857 = v12847 + 1;
  v12846->timer = v12857;
  int * v12849 = v12846->regs;
  int v12850 = v12849[22];
  int * v12851 = v12846->regs;
  int v12852 = v12851[1];
  int * v12853 = v12846->regs;
  int v12864 = v12850 + v12852;
  v12853[17] = v12864;
  struct StateT * v12855 = slot_135(v12846);
  return v12855;
}

struct StateT * slot_175(struct StateT * v13623) {
  int v13624 = v13623->timer;
  int v13632 = v13624 + 1;
  v13623->timer = v13632;
  int * v13626 = v13623->regs;
  int v13627 = v13626[11];
  int * v13628 = v13623->regs;
  int v13637 = (int)((unsigned int)v13627 >> 19);
  v13628[9] = v13637;
  struct StateT * v13630 = slot_176(v13623);
  return v13630;
}

struct StateT * slot_273(struct StateT * v12092) {
  int v12093 = v12092->timer;
  int v12151 = v12093 + 1;
  v12092->timer = v12151;
  int * v12095 = v12092->regs;
  int v12096 = v12095[2];
  int * v12097 = v12092->cache_keys;
  int v12098 = v12097[0];
  bool v12156 = v12098 == ((int)((unsigned int)(v12096 + 48) >> 2));
  int v12146;
  if (v12156) {
    int * v12099 = v12092->cache_vals;
    int v12100 = v12099[0];
    v12146 = v12100;
  } else {
    int * v12102 = v12092->cache_keys;
    int v12103 = v12102[1];
    bool v12161 = v12103 == ((int)((unsigned int)(v12096 + 48) >> 2));
    int v12144;
    if (v12161) {
      int * v12104 = v12092->cache_vals;
      int v12105 = v12104[1];
      int * v12106 = v12092->cache_keys;
      int * v12107 = v12092->cache_keys;
      int v12108 = v12107[0];
      v12106[1] = v12108;
      int * v12110 = v12092->cache_vals;
      int * v12111 = v12092->cache_vals;
      int v12112 = v12111[0];
      v12110[1] = v12112;
      int * v12114 = v12092->cache_keys;
      int v12170 = (int)((unsigned int)(v12096 + 48) >> 2);
      v12114[0] = v12170;
      int * v12116 = v12092->cache_vals;
      v12116[0] = v12105;
      int v12118 = v12092->timer;
      int v12173 = v12118 + 1;
      v12092->timer = v12173;
      v12144 = v12105;
    } else {
      int * v12121 = v12092->mem;
      int v12175 = (int)((unsigned int)(v12096 + 48) >> 2);
      int v12122 = v12121[v12175];
      int * v12123 = v12092->mem;
      int * v12124 = v12092->cache_keys;
      int v12125 = v12124[1];
      int * v12126 = v12092->cache_vals;
      int v12127 = v12126[1];
      v12123[v12125] = v12127;
      int * v12129 = v12092->cache_keys;
      int * v12130 = v12092->cache_keys;
      int v12131 = v12130[0];
      v12129[1] = v12131;
      int * v12133 = v12092->cache_vals;
      int * v12134 = v12092->cache_vals;
      int v12135 = v12134[0];
      v12133[1] = v12135;
      int * v12137 = v12092->cache_keys;
      v12137[0] = v12175;
      int * v12139 = v12092->cache_vals;
      v12139[0] = v12122;
      int v12141 = v12092->timer;
      int v12190 = v12141 + 100;
      v12092->timer = v12190;
      v12144 = v12122;
    }
    v12146 = v12144;
  }
  int * v12147 = v12092->regs;
  v12147[26] = v12146;
  struct StateT * v12149 = slot_274(v12092);
  return v12149;
}

struct StateT * slot_69(struct StateT * v7609) {
  int v7610 = v7609->timer;
  int v7620 = v7610 + 1;
  v7609->timer = v7620;
  int * v7612 = v7609->regs;
  int v7613 = v7612[1];
  int * v7614 = v7609->regs;
  int v7615 = v7614[18];
  int * v7616 = v7609->regs;
  int v7626 = v7613 ^ v7615;
  v7616[1] = v7626;
  struct StateT * v7618 = slot_70(v7609);
  return v7618;
}

struct StateT * slot_202(struct StateT * v14122) {
  int v14123 = v14122->timer;
  int v14131 = v14123 + 1;
  v14122->timer = v14131;
  int * v14125 = v14122->regs;
  int v14126 = v14125[6];
  int * v14127 = v14122->regs;
  int v14135 = v14126 << 18;
  v14127[6] = v14135;
  struct StateT * v14129 = slot_203(v14122);
  return v14129;
}

struct StateT * slot_230(struct StateT * v7464) {
  int v7465 = v7464->timer;
  int v7475 = v7465 + 1;
  v7464->timer = v7475;
  int * v7467 = v7464->regs;
  int v7468 = v7467[17];
  int * v7469 = v7464->regs;
  int v7470 = v7469[30];
  int * v7471 = v7464->regs;
  int v7481 = v7468 + v7470;
  v7471[17] = v7481;
  struct StateT * v7473 = slot_231(v7464);
  return v7473;
}

struct StateT * slot_188(struct StateT * v13855) {
  int v13856 = v13855->timer;
  int v13866 = v13856 + 1;
  v13855->timer = v13866;
  int * v13858 = v13855->regs;
  int v13859 = v13858[12];
  int * v13860 = v13855->regs;
  int v13861 = v13860[15];
  int * v13862 = v13855->regs;
  int v13872 = v13859 ^ v13861;
  v13862[12] = v13872;
  struct StateT * v13864 = slot_189(v13855);
  return v13864;
}

struct StateT * slot_138(struct StateT * v12920) {
  int v12921 = v12920->timer;
  int v12929 = v12921 + 1;
  v12920->timer = v12929;
  int * v12923 = v12920->regs;
  int v12924 = v12923[11];
  int * v12925 = v12920->regs;
  int v12934 = (int)((unsigned int)v12924 >> 25);
  v12925[5] = v12934;
  struct StateT * v12927 = slot_139(v12920);
  return v12927;
}

struct StateT * slot_186(struct StateT * v13815) {
  int v13816 = v13815->timer;
  int v13826 = v13816 + 1;
  v13815->timer = v13826;
  int * v13818 = v13815->regs;
  int v13819 = v13818[8];
  int * v13820 = v13815->regs;
  int v13821 = v13820[9];
  int * v13822 = v13815->regs;
  int v13832 = v13819 | v13821;
  v13822[8] = v13832;
  struct StateT * v13824 = slot_187(v13815);
  return v13824;
}

struct StateT * slot_102(struct StateT * v11477) {
  int v11478 = v11477->timer;
  int v11486 = v11478 + 1;
  v11477->timer = v11486;
  int * v11480 = v11477->regs;
  int v11481 = v11480[9];
  int * v11482 = v11477->regs;
  int v11490 = v11481 << 13;
  v11482[9] = v11490;
  struct StateT * v11484 = slot_103(v11477);
  return v11484;
}

struct StateT * slot_145(struct StateT * v13043) {
  int v13044 = v13043->timer;
  int v13052 = v13044 + 1;
  v13043->timer = v13052;
  int * v13046 = v13043->regs;
  int v13047 = v13046[17];
  int * v13048 = v13043->regs;
  int v13056 = v13047 << 7;
  v13048[17] = v13056;
  struct StateT * v13050 = slot_146(v13043);
  return v13050;
}

struct StateT * slot_110(struct StateT * v12385) {
  int v12386 = v12385->timer;
  int v12396 = v12386 + 1;
  v12385->timer = v12396;
  int * v12388 = v12385->regs;
  int v12389 = v12388[17];
  int * v12390 = v12385->regs;
  int v12391 = v12390[6];
  int * v12392 = v12385->regs;
  int v12403 = v12389 ^ v12391;
  v12392[8] = v12403;
  struct StateT * v12394 = slot_111(v12385);
  return v12394;
}

struct StateT * slot_196(struct StateT * v14016) {
  int v14017 = v14016->timer;
  int v14025 = v14017 + 1;
  v14016->timer = v14025;
  int * v14019 = v14016->regs;
  int v14020 = v14019[11];
  int * v14021 = v14016->regs;
  int v14029 = v14020 << 18;
  v14021[11] = v14029;
  struct StateT * v14023 = slot_197(v14016);
  return v14023;
}

struct StateT * slot_208(struct StateT * v14231) {
  int v14232 = v14231->timer;
  int v14242 = v14232 + 1;
  v14231->timer = v14242;
  int * v14234 = v14231->regs;
  int v14235 = v14234[20];
  int * v14236 = v14231->regs;
  int v14237 = v14236[15];
  int * v14238 = v14231->regs;
  int v14249 = v14235 ^ v14237;
  v14238[11] = v14249;
  struct StateT * v14240 = slot_209(v14231);
  return v14240;
}

struct StateT * slot_172(struct StateT * v13560) {
  int v13561 = v13560->timer;
  int v13571 = v13561 + 1;
  v13560->timer = v13571;
  int * v13563 = v13560->regs;
  int v13564 = v13563[25];
  int * v13565 = v13560->regs;
  int v13566 = v13565[5];
  int * v13567 = v13560->regs;
  int v13578 = v13564 + v13566;
  v13567[15] = v13578;
  struct StateT * v13569 = slot_173(v13560);
  return v13569;
}

struct StateT * slot_131(struct StateT * v12783) {
  int v12784 = v12783->timer;
  int v12794 = v12784 + 1;
  v12783->timer = v12794;
  int * v12786 = v12783->regs;
  int v12787 = v12786[21];
  int * v12788 = v12783->regs;
  int v12789 = v12788[14];
  int * v12790 = v12783->regs;
  int v12801 = v12787 + v12789;
  v12790[15] = v12801;
  struct StateT * v12792 = slot_132(v12783);
  return v12792;
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

struct StateT * slot_180(struct StateT * v13709) {
  int v13710 = v13709->timer;
  int v13720 = v13710 + 1;
  v13709->timer = v13720;
  int * v13712 = v13709->regs;
  int v13713 = v13712[15];
  int * v13714 = v13709->regs;
  int v13715 = v13714[9];
  int * v13716 = v13709->regs;
  int v13726 = v13713 | v13715;
  v13716[15] = v13726;
  struct StateT * v13718 = slot_181(v13709);
  return v13718;
}

struct StateT * slot_203(struct StateT * v14138) {
  int v14139 = v14138->timer;
  int v14149 = v14139 + 1;
  v14138->timer = v14149;
  int * v14141 = v14138->regs;
  int v14142 = v14141[6];
  int * v14143 = v14138->regs;
  int v14144 = v14143[9];
  int * v14145 = v14138->regs;
  int v14155 = v14142 | v14144;
  v14145[6] = v14155;
  struct StateT * v14147 = slot_204(v14138);
  return v14147;
}

struct StateT * slot_190(struct StateT * v13895) {
  int v13896 = v13895->timer;
  int v13906 = v13896 + 1;
  v13895->timer = v13906;
  int * v13898 = v13895->regs;
  int v13899 = v13898[1];
  int * v13900 = v13895->regs;
  int v13901 = v13900[8];
  int * v13902 = v13895->regs;
  int v13912 = v13899 ^ v13901;
  v13902[1] = v13912;
  struct StateT * v13904 = slot_191(v13895);
  return v13904;
}

struct StateT * slot_157(struct StateT * v13280) {
  int v13281 = v13280->timer;
  int v13291 = v13281 + 1;
  v13280->timer = v13291;
  int * v13283 = v13280->regs;
  int v13284 = v13283[11];
  int * v13285 = v13280->regs;
  int v13286 = v13285[9];
  int * v13287 = v13280->regs;
  int v13297 = v13284 | v13286;
  v13287[11] = v13297;
  struct StateT * v13289 = slot_158(v13280);
  return v13289;
}

struct StateT * slot_242(struct StateT * v8166) {
  int v8167 = v8166->timer;
  int v8177 = v8167 + 1;
  v8166->timer = v8177;
  int * v8169 = v8166->regs;
  int v8170 = v8169[21];
  int * v8171 = v8166->regs;
  int v8172 = v8171[15];
  int * v8173 = v8166->regs;
  int v8183 = v8170 + v8172;
  v8173[15] = v8183;
  struct StateT * v8175 = slot_243(v8166);
  return v8175;
}

struct StateT * slot_200(struct StateT * v14085) {
  int v14086 = v14085->timer;
  int v14096 = v14086 + 1;
  v14085->timer = v14096;
  int * v14088 = v14085->regs;
  int v14089 = v14088[15];
  int * v14090 = v14085->regs;
  int v14091 = v14090[9];
  int * v14092 = v14085->regs;
  int v14102 = v14089 | v14091;
  v14092[15] = v14102;
  struct StateT * v14094 = slot_201(v14085);
  return v14094;
}

struct StateT * slot_243(struct StateT * v8206) {
  int v8207 = v8206->timer;
  int v8217 = v8207 + 1;
  v8206->timer = v8217;
  int * v8209 = v8206->regs;
  int v8210 = v8209[11];
  int * v8211 = v8206->regs;
  int v8212 = v8211[6];
  int * v8213 = v8206->regs;
  int v8223 = v8210 + v8212;
  v8213[11] = v8223;
  struct StateT * v8215 = slot_244(v8206);
  return v8215;
}

struct StateT * slot_173(struct StateT * v13581) {
  int v13582 = v13581->timer;
  int v13592 = v13582 + 1;
  v13581->timer = v13592;
  int * v13584 = v13581->regs;
  int v13585 = v13584[26];
  int * v13586 = v13581->regs;
  int v13587 = v13586[17];
  int * v13588 = v13581->regs;
  int v13599 = v13585 + v13587;
  v13588[6] = v13599;
  struct StateT * v13590 = slot_174(v13581);
  return v13590;
}

struct StateT * slot_149(struct StateT * v13121) {
  int v13122 = v13121->timer;
  int v13132 = v13122 + 1;
  v13121->timer = v13132;
  int * v13124 = v13121->regs;
  int v13125 = v13124[8];
  int * v13126 = v13121->regs;
  int v13127 = v13126[16];
  int * v13128 = v13121->regs;
  int v13139 = v13125 ^ v13127;
  v13128[17] = v13139;
  struct StateT * v13130 = slot_150(v13121);
  return v13130;
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

struct StateT * slot_104(struct StateT * v11828) {
  int v11829 = v11828->timer;
  int v11837 = v11829 + 1;
  v11828->timer = v11837;
  int * v11831 = v11828->regs;
  int v11832 = v11831[18];
  int * v11833 = v11828->regs;
  int v11842 = (int)((unsigned int)v11832 >> 19);
  v11833[9] = v11842;
  struct StateT * v11835 = slot_105(v11828);
  return v11835;
}

struct StateT * slot_235(struct StateT * v7836) {
  int v7837 = v7836->timer;
  int v7895 = v7837 + 1;
  v7836->timer = v7895;
  int * v7839 = v7836->regs;
  int v7840 = v7839[2];
  int * v7841 = v7836->cache_keys;
  int v7842 = v7841[0];
  bool v7900 = v7842 == ((int)((unsigned int)(v7840 + 40) >> 2));
  int v7890;
  if (v7900) {
    int * v7843 = v7836->cache_vals;
    int v7844 = v7843[0];
    v7890 = v7844;
  } else {
    int * v7846 = v7836->cache_keys;
    int v7847 = v7846[1];
    bool v7905 = v7847 == ((int)((unsigned int)(v7840 + 40) >> 2));
    int v7888;
    if (v7905) {
      int * v7848 = v7836->cache_vals;
      int v7849 = v7848[1];
      int * v7850 = v7836->cache_keys;
      int * v7851 = v7836->cache_keys;
      int v7852 = v7851[0];
      v7850[1] = v7852;
      int * v7854 = v7836->cache_vals;
      int * v7855 = v7836->cache_vals;
      int v7856 = v7855[0];
      v7854[1] = v7856;
      int * v7858 = v7836->cache_keys;
      int v7914 = (int)((unsigned int)(v7840 + 40) >> 2);
      v7858[0] = v7914;
      int * v7860 = v7836->cache_vals;
      v7860[0] = v7849;
      int v7862 = v7836->timer;
      int v7917 = v7862 + 1;
      v7836->timer = v7917;
      v7888 = v7849;
    } else {
      int * v7865 = v7836->mem;
      int v7919 = (int)((unsigned int)(v7840 + 40) >> 2);
      int v7866 = v7865[v7919];
      int * v7867 = v7836->mem;
      int * v7868 = v7836->cache_keys;
      int v7869 = v7868[1];
      int * v7870 = v7836->cache_vals;
      int v7871 = v7870[1];
      v7867[v7869] = v7871;
      int * v7873 = v7836->cache_keys;
      int * v7874 = v7836->cache_keys;
      int v7875 = v7874[0];
      v7873[1] = v7875;
      int * v7877 = v7836->cache_vals;
      int * v7878 = v7836->cache_vals;
      int v7879 = v7878[0];
      v7877[1] = v7879;
      int * v7881 = v7836->cache_keys;
      v7881[0] = v7919;
      int * v7883 = v7836->cache_vals;
      v7883[0] = v7866;
      int v7885 = v7836->timer;
      int v7934 = v7885 + 100;
      v7836->timer = v7934;
      v7888 = v7866;
    }
    v7890 = v7888;
  }
  int * v7891 = v7836->regs;
  v7891[30] = v7890;
  struct StateT * v7893 = slot_236(v7836);
  return v7893;
}

struct StateT * slot_275(struct StateT * v12343) {
  int v12344 = v12343->timer;
  int v12352 = v12344 + 1;
  v12343->timer = v12352;
  int * v12346 = v12343->regs;
  int v12347 = v12346[2];
  int * v12348 = v12343->regs;
  int v12356 = v12347 + 96;
  v12348[2] = v12356;
  struct StateT * v12350 = slot_276(v12343);
  return v12350;
}

struct StateT * slot_54(struct StateT * v6455) {
  int v6456 = v6455->timer;
  int v6466 = v6456 + 1;
  v6455->timer = v6466;
  int * v6458 = v6455->regs;
  int v6459 = v6458[22];
  int * v6460 = v6455->regs;
  int v6461 = v6460[17];
  int * v6462 = v6455->regs;
  int v6473 = v6459 + v6461;
  v6462[8] = v6473;
  struct StateT * v6464 = slot_55(v6455);
  return v6464;
}

struct StateT * slot_26(struct StateT * v2846) {
  int v2847 = v2846->timer;
  int v2905 = v2847 + 1;
  v2846->timer = v2905;
  int * v2849 = v2846->regs;
  int v2850 = v2849[11];
  int * v2851 = v2846->cache_keys;
  int v2852 = v2851[0];
  bool v2910 = v2852 == ((int)((unsigned int)(v2850 + 12) >> 2));
  int v2900;
  if (v2910) {
    int * v2853 = v2846->cache_vals;
    int v2854 = v2853[0];
    v2900 = v2854;
  } else {
    int * v2856 = v2846->cache_keys;
    int v2857 = v2856[1];
    bool v2915 = v2857 == ((int)((unsigned int)(v2850 + 12) >> 2));
    int v2898;
    if (v2915) {
      int * v2858 = v2846->cache_vals;
      int v2859 = v2858[1];
      int * v2860 = v2846->cache_keys;
      int * v2861 = v2846->cache_keys;
      int v2862 = v2861[0];
      v2860[1] = v2862;
      int * v2864 = v2846->cache_vals;
      int * v2865 = v2846->cache_vals;
      int v2866 = v2865[0];
      v2864[1] = v2866;
      int * v2868 = v2846->cache_keys;
      int v2924 = (int)((unsigned int)(v2850 + 12) >> 2);
      v2868[0] = v2924;
      int * v2870 = v2846->cache_vals;
      v2870[0] = v2859;
      int v2872 = v2846->timer;
      int v2927 = v2872 + 1;
      v2846->timer = v2927;
      v2898 = v2859;
    } else {
      int * v2875 = v2846->mem;
      int v2929 = (int)((unsigned int)(v2850 + 12) >> 2);
      int v2876 = v2875[v2929];
      int * v2877 = v2846->mem;
      int * v2878 = v2846->cache_keys;
      int v2879 = v2878[1];
      int * v2880 = v2846->cache_vals;
      int v2881 = v2880[1];
      v2877[v2879] = v2881;
      int * v2883 = v2846->cache_keys;
      int * v2884 = v2846->cache_keys;
      int v2885 = v2884[0];
      v2883[1] = v2885;
      int * v2887 = v2846->cache_vals;
      int * v2888 = v2846->cache_vals;
      int v2889 = v2888[0];
      v2887[1] = v2889;
      int * v2891 = v2846->cache_keys;
      v2891[0] = v2929;
      int * v2893 = v2846->cache_vals;
      v2893[0] = v2876;
      int v2895 = v2846->timer;
      int v2944 = v2895 + 100;
      v2846->timer = v2944;
      v2898 = v2876;
    }
    v2900 = v2898;
  }
  int * v2901 = v2846->regs;
  v2901[15] = v2900;
  struct StateT * v2903 = slot_27(v2846);
  return v2903;
}

struct StateT * slot_206(struct StateT * v14191) {
  int v14192 = v14191->timer;
  int v14202 = v14192 + 1;
  v14191->timer = v14202;
  int * v14194 = v14191->regs;
  int v14195 = v14194[8];
  int * v14196 = v14191->regs;
  int v14197 = v14196[9];
  int * v14198 = v14191->regs;
  int v14208 = v14195 | v14197;
  v14198[8] = v14208;
  struct StateT * v14200 = slot_207(v14191);
  return v14200;
}

struct StateT * slot_227(struct StateT * v7270) {
  int v7271 = v7270->timer;
  int v7281 = v7271 + 1;
  v7270->timer = v7281;
  int * v7273 = v7270->regs;
  int v7274 = v7273[13];
  int * v7275 = v7270->regs;
  int v7276 = v7275[7];
  int * v7277 = v7270->regs;
  int v7287 = v7274 + v7276;
  v7277[13] = v7287;
  struct StateT * v7279 = slot_228(v7270);
  return v7279;
}

struct StateT * slot_169(struct StateT * v13499) {
  int v13500 = v13499->timer;
  int v13510 = v13500 + 1;
  v13499->timer = v13510;
  int * v13502 = v13499->regs;
  int v13503 = v13502[26];
  int * v13504 = v13499->regs;
  int v13505 = v13504[6];
  int * v13506 = v13499->regs;
  int v13516 = v13503 ^ v13505;
  v13506[26] = v13516;
  struct StateT * v13508 = slot_170(v13499);
  return v13508;
}

struct StateT * slot_253(struct StateT * v9138) {
  int v9139 = v9138->timer;
  int v9193 = v9139 + 1;
  v9138->timer = v9193;
  int * v9141 = v9138->regs;
  int v9142 = v9141[10];
  int * v9143 = v9138->regs;
  int v9144 = v9143[25];
  int * v9145 = v9138->cache_keys;
  int v9146 = v9145[0];
  bool v9200 = v9146 == ((int)((unsigned int)(v9142 + 28) >> 2));
  int v9190;
  if (v9200) {
    int * v9147 = v9138->cache_vals;
    v9147[0] = v9144;
    v9190 = v9144;
  } else {
    int * v9150 = v9138->cache_keys;
    int v9151 = v9150[1];
    bool v9205 = v9151 == ((int)((unsigned int)(v9142 + 28) >> 2));
    int v9188;
    if (v9205) {
      int * v9152 = v9138->cache_keys;
      int * v9153 = v9138->cache_keys;
      int v9154 = v9153[0];
      v9152[1] = v9154;
      int * v9156 = v9138->cache_vals;
      int * v9157 = v9138->cache_vals;
      int v9158 = v9157[0];
      v9156[1] = v9158;
      int * v9160 = v9138->cache_keys;
      int v9213 = (int)((unsigned int)(v9142 + 28) >> 2);
      v9160[0] = v9213;
      int * v9162 = v9138->cache_vals;
      v9162[0] = v9144;
      int v9164 = v9138->timer;
      int v9216 = v9164 + 1;
      v9138->timer = v9216;
      v9188 = v9144;
    } else {
      int * v9167 = v9138->mem;
      int * v9168 = v9138->cache_keys;
      int v9169 = v9168[1];
      int * v9170 = v9138->cache_vals;
      int v9171 = v9170[1];
      v9167[v9169] = v9171;
      int * v9173 = v9138->cache_keys;
      int * v9174 = v9138->cache_keys;
      int v9175 = v9174[0];
      v9173[1] = v9175;
      int * v9177 = v9138->cache_vals;
      int * v9178 = v9138->cache_vals;
      int v9179 = v9178[0];
      v9177[1] = v9179;
      int * v9181 = v9138->cache_keys;
      int v9229 = (int)((unsigned int)(v9142 + 28) >> 2);
      v9181[0] = v9229;
      int * v9183 = v9138->cache_vals;
      v9183[0] = v9144;
      int v9185 = v9138->timer;
      int v9232 = v9185 + 100;
      v9138->timer = v9232;
      v9188 = v9144;
    }
    v9190 = v9188;
  }
  struct StateT * v9191 = slot_254(v9138);
  return v9191;
}

struct StateT * slot_64(struct StateT * v7253) {
  int v7254 = v7253->timer;
  int v7262 = v7254 + 1;
  v7253->timer = v7262;
  int * v7256 = v7253->regs;
  int v7257 = v7256[8];
  int * v7258 = v7253->regs;
  int v7267 = (int)((unsigned int)v7257 >> 25);
  v7258[20] = v7267;
  struct StateT * v7260 = slot_65(v7253);
  return v7260;
}

struct StateT * slot_170(struct StateT * v13519) {
  int v13520 = v13519->timer;
  int v13530 = v13520 + 1;
  v13519->timer = v13530;
  int * v13522 = v13519->regs;
  int v13523 = v13522[24];
  int * v13524 = v13519->regs;
  int v13525 = v13524[8];
  int * v13526 = v13519->regs;
  int v13536 = v13523 ^ v13525;
  v13526[24] = v13536;
  struct StateT * v13528 = slot_171(v13519);
  return v13528;
}

struct StateT * slot_14(struct StateT * v1678) {
  int v1679 = v1678->timer;
  int v1685 = v1679 + 1;
  v1678->timer = v1685;
  int * v1681 = v1678->regs;
  v1681[30] = 0;
  struct StateT * v1683 = slot_15(v1678);
  return v1683;
}

struct StateT * slot_53(struct StateT * v6414) {
  int v6415 = v6414->timer;
  int v6425 = v6415 + 1;
  v6414->timer = v6425;
  int * v6417 = v6414->regs;
  int v6418 = v6417[19];
  int * v6419 = v6414->regs;
  int v6420 = v6419[5];
  int * v6421 = v6414->regs;
  int v6432 = v6418 + v6420;
  v6421[18] = v6432;
  struct StateT * v6423 = slot_54(v6414);
  return v6423;
}

struct StateT * slot_80(struct StateT * v8186) {
  int v8187 = v8186->timer;
  int v8197 = v8187 + 1;
  v8186->timer = v8197;
  int * v8189 = v8186->regs;
  int v8190 = v8189[8];
  int * v8191 = v8186->regs;
  int v8192 = v8191[20];
  int * v8193 = v8186->regs;
  int v8203 = v8190 | v8192;
  v8193[8] = v8203;
  struct StateT * v8195 = slot_81(v8186);
  return v8195;
}

struct StateT * slot_261(struct StateT * v10075) {
  int v10076 = v10075->timer;
  int v10474 = v10076 + 1;
  v10075->timer = v10474;
  int * v10078 = v10075->regs;
  int v10079 = v10078[10];
  int * v10080 = v10075->regs;
  int v10081 = v10080[30];
  int v10082 = v10075->timer;
  int v10479 = v10082 + 1;
  v10075->timer = v10479;
  int * v10084 = v10075->regs;
  int v10085 = v10084[2];
  int * v10086 = v10075->cache_keys;
  int v10087 = v10086[0];
  bool v10484 = v10087 == ((int)((unsigned int)(v10085 + 92) >> 2));
  int v10135;
  if (v10484) {
    int * v10088 = v10075->cache_vals;
    int v10089 = v10088[0];
    v10135 = v10089;
  } else {
    int * v10091 = v10075->cache_keys;
    int v10092 = v10091[1];
    bool v10489 = v10092 == ((int)((unsigned int)(v10085 + 92) >> 2));
    int v10133;
    if (v10489) {
      int * v10093 = v10075->cache_vals;
      int v10094 = v10093[1];
      int * v10095 = v10075->cache_keys;
      int * v10096 = v10075->cache_keys;
      int v10097 = v10096[0];
      v10095[1] = v10097;
      int * v10099 = v10075->cache_vals;
      int * v10100 = v10075->cache_vals;
      int v10101 = v10100[0];
      v10099[1] = v10101;
      int * v10103 = v10075->cache_keys;
      int v10498 = (int)((unsigned int)(v10085 + 92) >> 2);
      v10103[0] = v10498;
      int * v10105 = v10075->cache_vals;
      v10105[0] = v10094;
      int v10107 = v10075->timer;
      int v10501 = v10107 + 1;
      v10075->timer = v10501;
      v10133 = v10094;
    } else {
      int * v10110 = v10075->mem;
      int v10503 = (int)((unsigned int)(v10085 + 92) >> 2);
      int v10111 = v10110[v10503];
      int * v10112 = v10075->mem;
      int * v10113 = v10075->cache_keys;
      int v10114 = v10113[1];
      int * v10115 = v10075->cache_vals;
      int v10116 = v10115[1];
      v10112[v10114] = v10116;
      int * v10118 = v10075->cache_keys;
      int * v10119 = v10075->cache_keys;
      int v10120 = v10119[0];
      v10118[1] = v10120;
      int * v10122 = v10075->cache_vals;
      int * v10123 = v10075->cache_vals;
      int v10124 = v10123[0];
      v10122[1] = v10124;
      int * v10126 = v10075->cache_keys;
      v10126[0] = v10503;
      int * v10128 = v10075->cache_vals;
      v10128[0] = v10111;
      int v10130 = v10075->timer;
      int v10518 = v10130 + 100;
      v10075->timer = v10518;
      v10133 = v10111;
    }
    v10135 = v10133;
  }
  int * v10136 = v10075->regs;
  v10136[1] = v10135;
  int v10138 = v10075->timer;
  int v10523 = v10138 + 1;
  v10075->timer = v10523;
  int * v10140 = v10075->regs;
  int v10141 = v10140[2];
  int * v10142 = v10075->cache_keys;
  int v10143 = v10142[0];
  bool v10526 = v10143 == ((int)((unsigned int)(v10141 + 88) >> 2));
  int v10191;
  if (v10526) {
    int * v10144 = v10075->cache_vals;
    int v10145 = v10144[0];
    v10191 = v10145;
  } else {
    int * v10147 = v10075->cache_keys;
    int v10148 = v10147[1];
    bool v10530 = v10148 == ((int)((unsigned int)(v10141 + 88) >> 2));
    int v10189;
    if (v10530) {
      int * v10149 = v10075->cache_vals;
      int v10150 = v10149[1];
      int * v10151 = v10075->cache_keys;
      int * v10152 = v10075->cache_keys;
      int v10153 = v10152[0];
      v10151[1] = v10153;
      int * v10155 = v10075->cache_vals;
      int * v10156 = v10075->cache_vals;
      int v10157 = v10156[0];
      v10155[1] = v10157;
      int * v10159 = v10075->cache_keys;
      int v10539 = (int)((unsigned int)(v10141 + 88) >> 2);
      v10159[0] = v10539;
      int * v10161 = v10075->cache_vals;
      v10161[0] = v10150;
      int v10163 = v10075->timer;
      int v10542 = v10163 + 1;
      v10075->timer = v10542;
      v10189 = v10150;
    } else {
      int * v10166 = v10075->mem;
      int v10544 = (int)((unsigned int)(v10141 + 88) >> 2);
      int v10167 = v10166[v10544];
      int * v10168 = v10075->mem;
      int * v10169 = v10075->cache_keys;
      int v10170 = v10169[1];
      int * v10171 = v10075->cache_vals;
      int v10172 = v10171[1];
      v10168[v10170] = v10172;
      int * v10174 = v10075->cache_keys;
      int * v10175 = v10075->cache_keys;
      int v10176 = v10175[0];
      v10174[1] = v10176;
      int * v10178 = v10075->cache_vals;
      int * v10179 = v10075->cache_vals;
      int v10180 = v10179[0];
      v10178[1] = v10180;
      int * v10182 = v10075->cache_keys;
      v10182[0] = v10544;
      int * v10184 = v10075->cache_vals;
      v10184[0] = v10167;
      int v10186 = v10075->timer;
      int v10559 = v10186 + 100;
      v10075->timer = v10559;
      v10189 = v10167;
    }
    v10191 = v10189;
  }
  int * v10192 = v10075->regs;
  v10192[8] = v10191;
  int v10194 = v10075->timer;
  int v10564 = v10194 + 1;
  v10075->timer = v10564;
  int * v10196 = v10075->regs;
  int v10197 = v10196[2];
  bool v10566 = ((int)((unsigned int)(v10079 + 60) >> 2)) == ((int)((unsigned int)(v10197 + 84) >> 2));
  int v10252;
  if (v10566) {
    int v10198 = v10075->timer;
    int v10567 = v10198 + 1;
    v10075->timer = v10567;
    v10252 = v10081;
  } else {
    int * v10201 = v10075->cache_keys;
    int v10202 = v10201[0];
    bool v10570 = v10202 == ((int)((unsigned int)(v10197 + 84) >> 2));
    int v10250;
    if (v10570) {
      int * v10203 = v10075->cache_vals;
      int v10204 = v10203[0];
      v10250 = v10204;
    } else {
      int * v10206 = v10075->cache_keys;
      int v10207 = v10206[1];
      bool v10574 = v10207 == ((int)((unsigned int)(v10197 + 84) >> 2));
      int v10248;
      if (v10574) {
        int * v10208 = v10075->cache_vals;
        int v10209 = v10208[1];
        int * v10210 = v10075->cache_keys;
        int * v10211 = v10075->cache_keys;
        int v10212 = v10211[0];
        v10210[1] = v10212;
        int * v10214 = v10075->cache_vals;
        int * v10215 = v10075->cache_vals;
        int v10216 = v10215[0];
        v10214[1] = v10216;
        int * v10218 = v10075->cache_keys;
        int v10583 = (int)((unsigned int)(v10197 + 84) >> 2);
        v10218[0] = v10583;
        int * v10220 = v10075->cache_vals;
        v10220[0] = v10209;
        int v10222 = v10075->timer;
        int v10586 = v10222 + 1;
        v10075->timer = v10586;
        v10248 = v10209;
      } else {
        int * v10225 = v10075->mem;
        int v10588 = (int)((unsigned int)(v10197 + 84) >> 2);
        int v10226 = v10225[v10588];
        int * v10227 = v10075->mem;
        int * v10228 = v10075->cache_keys;
        int v10229 = v10228[1];
        int * v10230 = v10075->cache_vals;
        int v10231 = v10230[1];
        v10227[v10229] = v10231;
        int * v10233 = v10075->cache_keys;
        int * v10234 = v10075->cache_keys;
        int v10235 = v10234[0];
        v10233[1] = v10235;
        int * v10237 = v10075->cache_vals;
        int * v10238 = v10075->cache_vals;
        int v10239 = v10238[0];
        v10237[1] = v10239;
        int * v10241 = v10075->cache_keys;
        v10241[0] = v10588;
        int * v10243 = v10075->cache_vals;
        v10243[0] = v10226;
        int v10245 = v10075->timer;
        int v10603 = v10245 + 100;
        v10075->timer = v10603;
        v10248 = v10226;
      }
      v10250 = v10248;
    }
    v10252 = v10250;
  }
  int * v10253 = v10075->regs;
  v10253[9] = v10252;
  int v10255 = v10075->timer;
  int v10609 = v10255 + 1;
  v10075->timer = v10609;
  int * v10257 = v10075->regs;
  int v10258 = v10257[2];
  bool v10611 = ((int)((unsigned int)(v10079 + 60) >> 2)) == ((int)((unsigned int)(v10258 + 80) >> 2));
  int v10313;
  if (v10611) {
    int v10259 = v10075->timer;
    int v10612 = v10259 + 1;
    v10075->timer = v10612;
    v10313 = v10081;
  } else {
    int * v10262 = v10075->cache_keys;
    int v10263 = v10262[0];
    bool v10615 = v10263 == ((int)((unsigned int)(v10258 + 80) >> 2));
    int v10311;
    if (v10615) {
      int * v10264 = v10075->cache_vals;
      int v10265 = v10264[0];
      v10311 = v10265;
    } else {
      int * v10267 = v10075->cache_keys;
      int v10268 = v10267[1];
      bool v10619 = v10268 == ((int)((unsigned int)(v10258 + 80) >> 2));
      int v10309;
      if (v10619) {
        int * v10269 = v10075->cache_vals;
        int v10270 = v10269[1];
        int * v10271 = v10075->cache_keys;
        int * v10272 = v10075->cache_keys;
        int v10273 = v10272[0];
        v10271[1] = v10273;
        int * v10275 = v10075->cache_vals;
        int * v10276 = v10075->cache_vals;
        int v10277 = v10276[0];
        v10275[1] = v10277;
        int * v10279 = v10075->cache_keys;
        int v10628 = (int)((unsigned int)(v10258 + 80) >> 2);
        v10279[0] = v10628;
        int * v10281 = v10075->cache_vals;
        v10281[0] = v10270;
        int v10283 = v10075->timer;
        int v10631 = v10283 + 1;
        v10075->timer = v10631;
        v10309 = v10270;
      } else {
        int * v10286 = v10075->mem;
        int v10633 = (int)((unsigned int)(v10258 + 80) >> 2);
        int v10287 = v10286[v10633];
        int * v10288 = v10075->mem;
        int * v10289 = v10075->cache_keys;
        int v10290 = v10289[1];
        int * v10291 = v10075->cache_vals;
        int v10292 = v10291[1];
        v10288[v10290] = v10292;
        int * v10294 = v10075->cache_keys;
        int * v10295 = v10075->cache_keys;
        int v10296 = v10295[0];
        v10294[1] = v10296;
        int * v10298 = v10075->cache_vals;
        int * v10299 = v10075->cache_vals;
        int v10300 = v10299[0];
        v10298[1] = v10300;
        int * v10302 = v10075->cache_keys;
        v10302[0] = v10633;
        int * v10304 = v10075->cache_vals;
        v10304[0] = v10287;
        int v10306 = v10075->timer;
        int v10648 = v10306 + 100;
        v10075->timer = v10648;
        v10309 = v10287;
      }
      v10311 = v10309;
    }
    v10313 = v10311;
  }
  int * v10314 = v10075->regs;
  v10314[18] = v10313;
  int * v10316 = v10075->cache_keys;
  int v10317 = v10316[0];
  bool v10655 = v10317 == ((int)((unsigned int)(v10079 + 60) >> 2));
  int v10361;
  if (v10655) {
    int * v10318 = v10075->cache_vals;
    v10318[0] = v10081;
    v10361 = v10081;
  } else {
    int * v10321 = v10075->cache_keys;
    int v10322 = v10321[1];
    bool v10659 = v10322 == ((int)((unsigned int)(v10079 + 60) >> 2));
    int v10359;
    if (v10659) {
      int * v10323 = v10075->cache_keys;
      int * v10324 = v10075->cache_keys;
      int v10325 = v10324[0];
      v10323[1] = v10325;
      int * v10327 = v10075->cache_vals;
      int * v10328 = v10075->cache_vals;
      int v10329 = v10328[0];
      v10327[1] = v10329;
      int * v10331 = v10075->cache_keys;
      int v10667 = (int)((unsigned int)(v10079 + 60) >> 2);
      v10331[0] = v10667;
      int * v10333 = v10075->cache_vals;
      v10333[0] = v10081;
      int v10335 = v10075->timer;
      int v10670 = v10335 + 1;
      v10075->timer = v10670;
      v10359 = v10081;
    } else {
      int * v10338 = v10075->mem;
      int * v10339 = v10075->cache_keys;
      int v10340 = v10339[1];
      int * v10341 = v10075->cache_vals;
      int v10342 = v10341[1];
      v10338[v10340] = v10342;
      int * v10344 = v10075->cache_keys;
      int * v10345 = v10075->cache_keys;
      int v10346 = v10345[0];
      v10344[1] = v10346;
      int * v10348 = v10075->cache_vals;
      int * v10349 = v10075->cache_vals;
      int v10350 = v10349[0];
      v10348[1] = v10350;
      int * v10352 = v10075->cache_keys;
      int v10683 = (int)((unsigned int)(v10079 + 60) >> 2);
      v10352[0] = v10683;
      int * v10354 = v10075->cache_vals;
      v10354[0] = v10081;
      int v10356 = v10075->timer;
      int v10686 = v10356 + 100;
      v10075->timer = v10686;
      v10359 = v10081;
    }
    v10361 = v10359;
  }
  bool v10688 = (((int)((unsigned int)(v10085 + 92) >> 2)) == ((int)((unsigned int)(v10079 + 60) >> 2))) | (((int)((unsigned int)(v10141 + 88) >> 2)) == ((int)((unsigned int)(v10079 + 60) >> 2)));
  struct StateT * v10472;
  if (v10688) {
    int v10362 = v10075->timer;
    int v10689 = v10362 + 15;
    v10075->timer = v10689;
    int * v10364 = v10075->saved_regs;
    int v10365 = v10364[30];
    int * v10366 = v10075->regs;
    v10366[30] = v10365;
    int * v10368 = v10075->saved_regs;
    int v10369 = v10368[29];
    int * v10370 = v10075->regs;
    v10370[29] = v10369;
    int * v10372 = v10075->saved_regs;
    int v10373 = v10372[28];
    int * v10374 = v10075->regs;
    v10374[28] = v10373;
    int * v10376 = v10075->saved_regs;
    int v10377 = v10376[7];
    int * v10378 = v10075->regs;
    v10378[7] = v10377;
    int * v10380 = v10075->saved_regs;
    int v10381 = v10380[12];
    int * v10382 = v10075->regs;
    v10382[12] = v10381;
    int * v10384 = v10075->saved_regs;
    int v10385 = v10384[14];
    int * v10386 = v10075->regs;
    v10386[14] = v10385;
    int * v10388 = v10075->saved_regs;
    int v10389 = v10388[27];
    int * v10390 = v10075->regs;
    v10390[27] = v10389;
    int * v10392 = v10075->saved_regs;
    int v10393 = v10392[23];
    int * v10394 = v10075->regs;
    v10394[23] = v10393;
    int * v10396 = v10075->saved_regs;
    int v10397 = v10396[13];
    int * v10398 = v10075->regs;
    v10398[13] = v10397;
    int * v10400 = v10075->saved_regs;
    int v10401 = v10400[15];
    int * v10402 = v10075->regs;
    v10402[15] = v10401;
    int * v10404 = v10075->saved_regs;
    int v10405 = v10404[20];
    int * v10406 = v10075->regs;
    v10406[20] = v10405;
    int * v10408 = v10075->saved_regs;
    int v10409 = v10408[18];
    int * v10410 = v10075->regs;
    v10410[18] = v10409;
    int * v10412 = v10075->saved_regs;
    int v10413 = v10412[8];
    int * v10414 = v10075->regs;
    v10414[8] = v10413;
    int * v10416 = v10075->saved_regs;
    int v10417 = v10416[9];
    int * v10418 = v10075->regs;
    v10418[9] = v10417;
    int * v10420 = v10075->saved_regs;
    int v10421 = v10420[1];
    int * v10422 = v10075->regs;
    v10422[1] = v10421;
    int * v10424 = v10075->saved_regs;
    int v10425 = v10424[26];
    int * v10426 = v10075->regs;
    v10426[26] = v10425;
    int * v10428 = v10075->saved_regs;
    int v10429 = v10428[24];
    int * v10430 = v10075->regs;
    v10430[24] = v10429;
    int * v10432 = v10075->saved_regs;
    int v10433 = v10432[25];
    int * v10434 = v10075->regs;
    v10434[25] = v10433;
    int * v10436 = v10075->saved_regs;
    int v10437 = v10436[6];
    int * v10438 = v10075->regs;
    v10438[6] = v10437;
    int * v10440 = v10075->saved_regs;
    int v10441 = v10440[16];
    int * v10442 = v10075->regs;
    v10442[16] = v10441;
    int * v10444 = v10075->saved_regs;
    int v10445 = v10444[17];
    int * v10446 = v10075->regs;
    v10446[17] = v10445;
    int * v10448 = v10075->saved_regs;
    int v10449 = v10448[5];
    int * v10450 = v10075->regs;
    v10450[5] = v10449;
    int * v10452 = v10075->saved_regs;
    int v10453 = v10452[21];
    int * v10454 = v10075->regs;
    v10454[21] = v10453;
    int * v10456 = v10075->saved_regs;
    int v10457 = v10456[19];
    int * v10458 = v10075->regs;
    v10458[19] = v10457;
    int * v10460 = v10075->saved_regs;
    int v10461 = v10460[22];
    int * v10462 = v10075->regs;
    v10462[22] = v10461;
    int * v10464 = v10075->saved_regs;
    int v10465 = v10464[11];
    int * v10466 = v10075->regs;
    v10466[11] = v10465;
    struct StateT * v10468 = slot_262(v10075);
    v10472 = v10468;
  } else {
    struct StateT * v10470 = slot_266(v10075);
    v10472 = v10470;
  }
  return v10472;
}

struct StateT * slot_137(struct StateT * v12900) {
  int v12901 = v12900->timer;
  int v12911 = v12901 + 1;
  v12900->timer = v12911;
  int * v12903 = v12900->regs;
  int v12904 = v12903[15];
  int * v12905 = v12900->regs;
  int v12906 = v12905[5];
  int * v12907 = v12900->regs;
  int v12917 = v12904 | v12906;
  v12907[15] = v12917;
  struct StateT * v12909 = slot_138(v12900);
  return v12909;
}

struct StateT * slot_122(struct StateT * v12613) {
  int v12614 = v12613->timer;
  int v12622 = v12614 + 1;
  v12613->timer = v12622;
  int * v12616 = v12613->regs;
  int v12617 = v12616[17];
  int * v12618 = v12613->regs;
  int v12626 = v12617 << 18;
  v12618[17] = v12626;
  struct StateT * v12620 = slot_123(v12613);
  return v12620;
}

struct StateT * slot_99(struct StateT * v10794) {
  int v10795 = v10794->timer;
  int v10803 = v10795 + 1;
  v10794->timer = v10803;
  int * v10797 = v10794->regs;
  int v10798 = v10797[8];
  int * v10799 = v10794->regs;
  int v10807 = v10798 << 13;
  v10799[8] = v10807;
  struct StateT * v10801 = slot_100(v10794);
  return v10801;
}

struct StateT * slot_179(struct StateT * v13693) {
  int v13694 = v13693->timer;
  int v13702 = v13694 + 1;
  v13693->timer = v13702;
  int * v13696 = v13693->regs;
  int v13697 = v13696[15];
  int * v13698 = v13693->regs;
  int v13706 = v13697 << 13;
  v13698[15] = v13706;
  struct StateT * v13700 = slot_180(v13693);
  return v13700;
}

struct StateT * slot_219(struct StateT * v6634) {
  int v6635 = v6634->timer;
  int v6641 = v6635 + 1;
  v6634->timer = v6641;
  int * v6637 = v6634->regs;
  v6637[6] = 857759744;
  struct StateT * v6639 = slot_220(v6634);
  return v6639;
}

struct StateT * slot_36(struct StateT * v3083) {
  int v3084 = v3083->timer;
  int v3138 = v3084 + 1;
  v3083->timer = v3138;
  int * v3086 = v3083->regs;
  int v3087 = v3086[2];
  int * v3088 = v3083->regs;
  int v3089 = v3088[26];
  int * v3090 = v3083->cache_keys;
  int v3091 = v3090[0];
  bool v3145 = v3091 == ((int)((unsigned int)(v3087 + 20) >> 2));
  int v3135;
  if (v3145) {
    int * v3092 = v3083->cache_vals;
    v3092[0] = v3089;
    v3135 = v3089;
  } else {
    int * v3095 = v3083->cache_keys;
    int v3096 = v3095[1];
    bool v3150 = v3096 == ((int)((unsigned int)(v3087 + 20) >> 2));
    int v3133;
    if (v3150) {
      int * v3097 = v3083->cache_keys;
      int * v3098 = v3083->cache_keys;
      int v3099 = v3098[0];
      v3097[1] = v3099;
      int * v3101 = v3083->cache_vals;
      int * v3102 = v3083->cache_vals;
      int v3103 = v3102[0];
      v3101[1] = v3103;
      int * v3105 = v3083->cache_keys;
      int v3158 = (int)((unsigned int)(v3087 + 20) >> 2);
      v3105[0] = v3158;
      int * v3107 = v3083->cache_vals;
      v3107[0] = v3089;
      int v3109 = v3083->timer;
      int v3161 = v3109 + 1;
      v3083->timer = v3161;
      v3133 = v3089;
    } else {
      int * v3112 = v3083->mem;
      int * v3113 = v3083->cache_keys;
      int v3114 = v3113[1];
      int * v3115 = v3083->cache_vals;
      int v3116 = v3115[1];
      v3112[v3114] = v3116;
      int * v3118 = v3083->cache_keys;
      int * v3119 = v3083->cache_keys;
      int v3120 = v3119[0];
      v3118[1] = v3120;
      int * v3122 = v3083->cache_vals;
      int * v3123 = v3083->cache_vals;
      int v3124 = v3123[0];
      v3122[1] = v3124;
      int * v3126 = v3083->cache_keys;
      int v3174 = (int)((unsigned int)(v3087 + 20) >> 2);
      v3126[0] = v3174;
      int * v3128 = v3083->cache_vals;
      v3128[0] = v3089;
      int v3130 = v3083->timer;
      int v3177 = v3130 + 100;
      v3083->timer = v3177;
      v3133 = v3089;
    }
    v3135 = v3133;
  }
  struct StateT * v3136 = slot_37(v3083);
  return v3136;
}

struct StateT * slot_57(struct StateT * v6647) {
  int v6648 = v6647->timer;
  int v6658 = v6648 + 1;
  v6647->timer = v6658;
  int * v6650 = v6647->regs;
  int v6651 = v6650[15];
  int * v6652 = v6647->regs;
  int v6653 = v6652[9];
  int * v6654 = v6647->regs;
  int v6664 = v6651 | v6653;
  v6654[15] = v6664;
  struct StateT * v6656 = slot_58(v6647);
  return v6656;
}

struct StateT * slot_62(struct StateT * v7092) {
  int v7093 = v7092->timer;
  int v7101 = v7093 + 1;
  v7092->timer = v7101;
  int * v7095 = v7092->regs;
  int v7096 = v7095[18];
  int * v7097 = v7092->regs;
  int v7105 = v7096 << 7;
  v7097[18] = v7105;
  struct StateT * v7099 = slot_63(v7092);
  return v7099;
}

struct StateT * slot_22(struct StateT * v2426) {
  int v2427 = v2426->timer;
  int v2485 = v2427 + 1;
  v2426->timer = v2485;
  int * v2429 = v2426->regs;
  int v2430 = v2429[12];
  int * v2431 = v2426->cache_keys;
  int v2432 = v2431[0];
  bool v2490 = v2432 == ((int)((unsigned int)(v2430 + 28) >> 2));
  int v2480;
  if (v2490) {
    int * v2433 = v2426->cache_vals;
    int v2434 = v2433[0];
    v2480 = v2434;
  } else {
    int * v2436 = v2426->cache_keys;
    int v2437 = v2436[1];
    bool v2495 = v2437 == ((int)((unsigned int)(v2430 + 28) >> 2));
    int v2478;
    if (v2495) {
      int * v2438 = v2426->cache_vals;
      int v2439 = v2438[1];
      int * v2440 = v2426->cache_keys;
      int * v2441 = v2426->cache_keys;
      int v2442 = v2441[0];
      v2440[1] = v2442;
      int * v2444 = v2426->cache_vals;
      int * v2445 = v2426->cache_vals;
      int v2446 = v2445[0];
      v2444[1] = v2446;
      int * v2448 = v2426->cache_keys;
      int v2504 = (int)((unsigned int)(v2430 + 28) >> 2);
      v2448[0] = v2504;
      int * v2450 = v2426->cache_vals;
      v2450[0] = v2439;
      int v2452 = v2426->timer;
      int v2507 = v2452 + 1;
      v2426->timer = v2507;
      v2478 = v2439;
    } else {
      int * v2455 = v2426->mem;
      int v2509 = (int)((unsigned int)(v2430 + 28) >> 2);
      int v2456 = v2455[v2509];
      int * v2457 = v2426->mem;
      int * v2458 = v2426->cache_keys;
      int v2459 = v2458[1];
      int * v2460 = v2426->cache_vals;
      int v2461 = v2460[1];
      v2457[v2459] = v2461;
      int * v2463 = v2426->cache_keys;
      int * v2464 = v2426->cache_keys;
      int v2465 = v2464[0];
      v2463[1] = v2465;
      int * v2467 = v2426->cache_vals;
      int * v2468 = v2426->cache_vals;
      int v2469 = v2468[0];
      v2467[1] = v2469;
      int * v2471 = v2426->cache_keys;
      v2471[0] = v2509;
      int * v2473 = v2426->cache_vals;
      v2473[0] = v2456;
      int v2475 = v2426->timer;
      int v2524 = v2475 + 100;
      v2426->timer = v2524;
      v2478 = v2456;
    }
    v2480 = v2478;
  }
  int * v2481 = v2426->regs;
  v2481[1] = v2480;
  struct StateT * v2483 = slot_23(v2426);
  return v2483;
}

struct StateT * slot_139(struct StateT * v12937) {
  int v12938 = v12937->timer;
  int v12946 = v12938 + 1;
  v12937->timer = v12946;
  int * v12940 = v12937->regs;
  int v12941 = v12940[11];
  int * v12942 = v12937->regs;
  int v12950 = v12941 << 7;
  v12942[11] = v12950;
  struct StateT * v12944 = slot_140(v12937);
  return v12944;
}

struct StateT * slot_221(struct StateT * v6789) {
  int v6790 = v6789->timer;
  int v6800 = v6790 + 1;
  v6789->timer = v6800;
  int * v6792 = v6789->regs;
  int v6793 = v6792[5];
  int * v6794 = v6789->regs;
  int v6795 = v6794[7];
  int * v6796 = v6789->regs;
  int v6806 = v6793 + v6795;
  v6796[5] = v6806;
  struct StateT * v6798 = slot_222(v6789);
  return v6798;
}

struct StateT * slot_23(struct StateT * v2531) {
  int v2532 = v2531->timer;
  int v2590 = v2532 + 1;
  v2531->timer = v2590;
  int * v2534 = v2531->regs;
  int v2535 = v2534[11];
  int * v2536 = v2531->cache_keys;
  int v2537 = v2536[0];
  bool v2595 = v2537 == ((int)((unsigned int)v2535 >> 2));
  int v2585;
  if (v2595) {
    int * v2538 = v2531->cache_vals;
    int v2539 = v2538[0];
    v2585 = v2539;
  } else {
    int * v2541 = v2531->cache_keys;
    int v2542 = v2541[1];
    bool v2600 = v2542 == ((int)((unsigned int)v2535 >> 2));
    int v2583;
    if (v2600) {
      int * v2543 = v2531->cache_vals;
      int v2544 = v2543[1];
      int * v2545 = v2531->cache_keys;
      int * v2546 = v2531->cache_keys;
      int v2547 = v2546[0];
      v2545[1] = v2547;
      int * v2549 = v2531->cache_vals;
      int * v2550 = v2531->cache_vals;
      int v2551 = v2550[0];
      v2549[1] = v2551;
      int * v2553 = v2531->cache_keys;
      int v2609 = (int)((unsigned int)v2535 >> 2);
      v2553[0] = v2609;
      int * v2555 = v2531->cache_vals;
      v2555[0] = v2544;
      int v2557 = v2531->timer;
      int v2612 = v2557 + 1;
      v2531->timer = v2612;
      v2583 = v2544;
    } else {
      int * v2560 = v2531->mem;
      int v2614 = (int)((unsigned int)v2535 >> 2);
      int v2561 = v2560[v2614];
      int * v2562 = v2531->mem;
      int * v2563 = v2531->cache_keys;
      int v2564 = v2563[1];
      int * v2565 = v2531->cache_vals;
      int v2566 = v2565[1];
      v2562[v2564] = v2566;
      int * v2568 = v2531->cache_keys;
      int * v2569 = v2531->cache_keys;
      int v2570 = v2569[0];
      v2568[1] = v2570;
      int * v2572 = v2531->cache_vals;
      int * v2573 = v2531->cache_vals;
      int v2574 = v2573[0];
      v2572[1] = v2574;
      int * v2576 = v2531->cache_keys;
      v2576[0] = v2614;
      int * v2578 = v2531->cache_vals;
      v2578[0] = v2561;
      int v2580 = v2531->timer;
      int v2629 = v2580 + 100;
      v2531->timer = v2629;
      v2583 = v2561;
    }
    v2585 = v2583;
  }
  int * v2586 = v2531->regs;
  v2586[5] = v2585;
  struct StateT * v2588 = slot_24(v2531);
  return v2588;
}

struct StateT * slot_153(struct StateT * v13205) {
  int v13206 = v13205->timer;
  int v13216 = v13206 + 1;
  v13205->timer = v13216;
  int * v13208 = v13205->regs;
  int v13209 = v13208[17];
  int * v13210 = v13205->regs;
  int v13211 = v13210[19];
  int * v13212 = v13205->regs;
  int v13223 = v13209 + v13211;
  v13212[6] = v13223;
  struct StateT * v13214 = slot_154(v13205);
  return v13214;
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

struct StateT * slot_86(struct StateT * v8646) {
  int v8647 = v8646->timer;
  int v8657 = v8647 + 1;
  v8646->timer = v8657;
  int * v8649 = v8646->regs;
  int v8650 = v8649[18];
  int * v8651 = v8646->regs;
  int v8652 = v8651[20];
  int * v8653 = v8646->regs;
  int v8663 = v8650 | v8652;
  v8653[18] = v8663;
  struct StateT * v8655 = slot_87(v8646);
  return v8655;
}

struct StateT * slot_129(struct StateT * v12743) {
  int v12744 = v12743->timer;
  int v12754 = v12744 + 1;
  v12743->timer = v12754;
  int * v12746 = v12743->regs;
  int v12747 = v12746[19];
  int * v12748 = v12743->regs;
  int v12749 = v12748[17];
  int * v12750 = v12743->regs;
  int v12760 = v12747 ^ v12749;
  v12750[19] = v12760;
  struct StateT * v12752 = slot_130(v12743);
  return v12752;
}

struct StateT * slot_158(struct StateT * v13300) {
  int v13301 = v13300->timer;
  int v13309 = v13301 + 1;
  v13300->timer = v13309;
  int * v13303 = v13300->regs;
  int v13304 = v13303[15];
  int * v13305 = v13300->regs;
  int v13314 = (int)((unsigned int)v13304 >> 23);
  v13305[9] = v13314;
  struct StateT * v13307 = slot_159(v13300);
  return v13307;
}

struct StateT * slot_100(struct StateT * v11020) {
  int v11021 = v11020->timer;
  int v11031 = v11021 + 1;
  v11020->timer = v11031;
  int * v11023 = v11020->regs;
  int v11024 = v11023[8];
  int * v11025 = v11020->regs;
  int v11026 = v11025[20];
  int * v11027 = v11020->regs;
  int v11037 = v11024 | v11026;
  v11027[8] = v11037;
  struct StateT * v11029 = slot_101(v11020);
  return v11029;
}

struct StateT * slot_271(struct StateT * v11845) {
  int v11846 = v11845->timer;
  int v11904 = v11846 + 1;
  v11845->timer = v11904;
  int * v11848 = v11845->regs;
  int v11849 = v11848[2];
  int * v11850 = v11845->cache_keys;
  int v11851 = v11850[0];
  bool v11909 = v11851 == ((int)((unsigned int)(v11849 + 56) >> 2));
  int v11899;
  if (v11909) {
    int * v11852 = v11845->cache_vals;
    int v11853 = v11852[0];
    v11899 = v11853;
  } else {
    int * v11855 = v11845->cache_keys;
    int v11856 = v11855[1];
    bool v11914 = v11856 == ((int)((unsigned int)(v11849 + 56) >> 2));
    int v11897;
    if (v11914) {
      int * v11857 = v11845->cache_vals;
      int v11858 = v11857[1];
      int * v11859 = v11845->cache_keys;
      int * v11860 = v11845->cache_keys;
      int v11861 = v11860[0];
      v11859[1] = v11861;
      int * v11863 = v11845->cache_vals;
      int * v11864 = v11845->cache_vals;
      int v11865 = v11864[0];
      v11863[1] = v11865;
      int * v11867 = v11845->cache_keys;
      int v11923 = (int)((unsigned int)(v11849 + 56) >> 2);
      v11867[0] = v11923;
      int * v11869 = v11845->cache_vals;
      v11869[0] = v11858;
      int v11871 = v11845->timer;
      int v11926 = v11871 + 1;
      v11845->timer = v11926;
      v11897 = v11858;
    } else {
      int * v11874 = v11845->mem;
      int v11928 = (int)((unsigned int)(v11849 + 56) >> 2);
      int v11875 = v11874[v11928];
      int * v11876 = v11845->mem;
      int * v11877 = v11845->cache_keys;
      int v11878 = v11877[1];
      int * v11879 = v11845->cache_vals;
      int v11880 = v11879[1];
      v11876[v11878] = v11880;
      int * v11882 = v11845->cache_keys;
      int * v11883 = v11845->cache_keys;
      int v11884 = v11883[0];
      v11882[1] = v11884;
      int * v11886 = v11845->cache_vals;
      int * v11887 = v11845->cache_vals;
      int v11888 = v11887[0];
      v11886[1] = v11888;
      int * v11890 = v11845->cache_keys;
      v11890[0] = v11928;
      int * v11892 = v11845->cache_vals;
      v11892[0] = v11875;
      int v11894 = v11845->timer;
      int v11943 = v11894 + 100;
      v11845->timer = v11943;
      v11897 = v11875;
    }
    v11899 = v11897;
  }
  int * v11900 = v11845->regs;
  v11900[24] = v11899;
  struct StateT * v11902 = slot_272(v11845);
  return v11902;
}

struct StateT * slot_127(struct StateT * v12702) {
  int v12703 = v12702->timer;
  int v12713 = v12703 + 1;
  v12702->timer = v12713;
  int * v12705 = v12702->regs;
  int v12706 = v12705[21];
  int * v12707 = v12702->regs;
  int v12708 = v12707[15];
  int * v12709 = v12702->regs;
  int v12719 = v12706 ^ v12708;
  v12709[21] = v12719;
  struct StateT * v12711 = slot_128(v12702);
  return v12711;
}

struct StateT * slot_217(struct StateT * v6476) {
  int v6477 = v6476->timer;
  int v6535 = v6477 + 1;
  v6476->timer = v6535;
  int * v6479 = v6476->regs;
  int v6480 = v6479[2];
  int * v6481 = v6476->cache_keys;
  int v6482 = v6481[0];
  bool v6540 = v6482 == ((int)((unsigned int)(v6480 + 8) >> 2));
  int v6530;
  if (v6540) {
    int * v6483 = v6476->cache_vals;
    int v6484 = v6483[0];
    v6530 = v6484;
  } else {
    int * v6486 = v6476->cache_keys;
    int v6487 = v6486[1];
    bool v6545 = v6487 == ((int)((unsigned int)(v6480 + 8) >> 2));
    int v6528;
    if (v6545) {
      int * v6488 = v6476->cache_vals;
      int v6489 = v6488[1];
      int * v6490 = v6476->cache_keys;
      int * v6491 = v6476->cache_keys;
      int v6492 = v6491[0];
      v6490[1] = v6492;
      int * v6494 = v6476->cache_vals;
      int * v6495 = v6476->cache_vals;
      int v6496 = v6495[0];
      v6494[1] = v6496;
      int * v6498 = v6476->cache_keys;
      int v6554 = (int)((unsigned int)(v6480 + 8) >> 2);
      v6498[0] = v6554;
      int * v6500 = v6476->cache_vals;
      v6500[0] = v6489;
      int v6502 = v6476->timer;
      int v6557 = v6502 + 1;
      v6476->timer = v6557;
      v6528 = v6489;
    } else {
      int * v6505 = v6476->mem;
      int v6559 = (int)((unsigned int)(v6480 + 8) >> 2);
      int v6506 = v6505[v6559];
      int * v6507 = v6476->mem;
      int * v6508 = v6476->cache_keys;
      int v6509 = v6508[1];
      int * v6510 = v6476->cache_vals;
      int v6511 = v6510[1];
      v6507[v6509] = v6511;
      int * v6513 = v6476->cache_keys;
      int * v6514 = v6476->cache_keys;
      int v6515 = v6514[0];
      v6513[1] = v6515;
      int * v6517 = v6476->cache_vals;
      int * v6518 = v6476->cache_vals;
      int v6519 = v6518[0];
      v6517[1] = v6519;
      int * v6521 = v6476->cache_keys;
      v6521[0] = v6559;
      int * v6523 = v6476->cache_vals;
      v6523[0] = v6506;
      int v6525 = v6476->timer;
      int v6574 = v6525 + 100;
      v6476->timer = v6574;
      v6528 = v6506;
    }
    v6530 = v6528;
  }
  int * v6531 = v6476->regs;
  v6531[6] = v6530;
  struct StateT * v6533 = slot_218(v6476);
  return v6533;
}

struct StateT * slot_13(struct StateT * v1193) {
  int v1194 = v1193->timer;
  int v1468 = v1194 + 1;
  v1193->timer = v1468;
  int * v1196 = v1193->regs;
  int v1197 = v1196[2];
  int * v1198 = v1193->regs;
  int v1199 = v1198[27];
  int * v1200 = v1193->saved_regs;
  int * v1201 = v1193->regs;
  int v1202 = v1201[30];
  v1200[30] = v1202;
  int v1204 = v1193->timer;
  int v1477 = v1204 + 1;
  v1193->timer = v1477;
  int * v1206 = v1193->regs;
  v1206[30] = 0;
  int * v1208 = v1193->saved_regs;
  int * v1209 = v1193->regs;
  int v1210 = v1209[29];
  v1208[29] = v1210;
  int v1212 = v1193->timer;
  int v1484 = v1212 + 1;
  v1193->timer = v1484;
  int * v1214 = v1193->regs;
  int v1215 = v1214[12];
  int * v1216 = v1193->cache_keys;
  int v1217 = v1216[0];
  bool v1488 = v1217 == ((int)((unsigned int)v1215 >> 2));
  int v1265;
  if (v1488) {
    int * v1218 = v1193->cache_vals;
    int v1219 = v1218[0];
    v1265 = v1219;
  } else {
    int * v1221 = v1193->cache_keys;
    int v1222 = v1221[1];
    bool v1493 = v1222 == ((int)((unsigned int)v1215 >> 2));
    int v1263;
    if (v1493) {
      int * v1223 = v1193->cache_vals;
      int v1224 = v1223[1];
      int * v1225 = v1193->cache_keys;
      int * v1226 = v1193->cache_keys;
      int v1227 = v1226[0];
      v1225[1] = v1227;
      int * v1229 = v1193->cache_vals;
      int * v1230 = v1193->cache_vals;
      int v1231 = v1230[0];
      v1229[1] = v1231;
      int * v1233 = v1193->cache_keys;
      int v1502 = (int)((unsigned int)v1215 >> 2);
      v1233[0] = v1502;
      int * v1235 = v1193->cache_vals;
      v1235[0] = v1224;
      int v1237 = v1193->timer;
      int v1505 = v1237 + 1;
      v1193->timer = v1505;
      v1263 = v1224;
    } else {
      int * v1240 = v1193->mem;
      int v1507 = (int)((unsigned int)v1215 >> 2);
      int v1241 = v1240[v1507];
      int * v1242 = v1193->mem;
      int * v1243 = v1193->cache_keys;
      int v1244 = v1243[1];
      int * v1245 = v1193->cache_vals;
      int v1246 = v1245[1];
      v1242[v1244] = v1246;
      int * v1248 = v1193->cache_keys;
      int * v1249 = v1193->cache_keys;
      int v1250 = v1249[0];
      v1248[1] = v1250;
      int * v1252 = v1193->cache_vals;
      int * v1253 = v1193->cache_vals;
      int v1254 = v1253[0];
      v1252[1] = v1254;
      int * v1256 = v1193->cache_keys;
      v1256[0] = v1507;
      int * v1258 = v1193->cache_vals;
      v1258[0] = v1241;
      int v1260 = v1193->timer;
      int v1522 = v1260 + 100;
      v1193->timer = v1522;
      v1263 = v1241;
    }
    v1265 = v1263;
  }
  int * v1266 = v1193->regs;
  v1266[29] = v1265;
  int * v1268 = v1193->saved_regs;
  int * v1269 = v1193->regs;
  int v1270 = v1269[28];
  v1268[28] = v1270;
  int v1272 = v1193->timer;
  int v1530 = v1272 + 1;
  v1193->timer = v1530;
  int * v1274 = v1193->regs;
  int v1275 = v1274[12];
  bool v1532 = ((int)((unsigned int)(v1197 + 44) >> 2)) == ((int)((unsigned int)(v1275 + 4) >> 2));
  int v1330;
  if (v1532) {
    int v1276 = v1193->timer;
    int v1533 = v1276 + 1;
    v1193->timer = v1533;
    v1330 = v1199;
  } else {
    int * v1279 = v1193->cache_keys;
    int v1280 = v1279[0];
    bool v1536 = v1280 == ((int)((unsigned int)(v1275 + 4) >> 2));
    int v1328;
    if (v1536) {
      int * v1281 = v1193->cache_vals;
      int v1282 = v1281[0];
      v1328 = v1282;
    } else {
      int * v1284 = v1193->cache_keys;
      int v1285 = v1284[1];
      bool v1541 = v1285 == ((int)((unsigned int)(v1275 + 4) >> 2));
      int v1326;
      if (v1541) {
        int * v1286 = v1193->cache_vals;
        int v1287 = v1286[1];
        int * v1288 = v1193->cache_keys;
        int * v1289 = v1193->cache_keys;
        int v1290 = v1289[0];
        v1288[1] = v1290;
        int * v1292 = v1193->cache_vals;
        int * v1293 = v1193->cache_vals;
        int v1294 = v1293[0];
        v1292[1] = v1294;
        int * v1296 = v1193->cache_keys;
        int v1550 = (int)((unsigned int)(v1275 + 4) >> 2);
        v1296[0] = v1550;
        int * v1298 = v1193->cache_vals;
        v1298[0] = v1287;
        int v1300 = v1193->timer;
        int v1553 = v1300 + 1;
        v1193->timer = v1553;
        v1326 = v1287;
      } else {
        int * v1303 = v1193->mem;
        int v1555 = (int)((unsigned int)(v1275 + 4) >> 2);
        int v1304 = v1303[v1555];
        int * v1305 = v1193->mem;
        int * v1306 = v1193->cache_keys;
        int v1307 = v1306[1];
        int * v1308 = v1193->cache_vals;
        int v1309 = v1308[1];
        v1305[v1307] = v1309;
        int * v1311 = v1193->cache_keys;
        int * v1312 = v1193->cache_keys;
        int v1313 = v1312[0];
        v1311[1] = v1313;
        int * v1315 = v1193->cache_vals;
        int * v1316 = v1193->cache_vals;
        int v1317 = v1316[0];
        v1315[1] = v1317;
        int * v1319 = v1193->cache_keys;
        v1319[0] = v1555;
        int * v1321 = v1193->cache_vals;
        v1321[0] = v1304;
        int v1323 = v1193->timer;
        int v1570 = v1323 + 100;
        v1193->timer = v1570;
        v1326 = v1304;
      }
      v1328 = v1326;
    }
    v1330 = v1328;
  }
  int * v1331 = v1193->regs;
  v1331[28] = v1330;
  int * v1333 = v1193->saved_regs;
  int * v1334 = v1193->regs;
  int v1335 = v1334[7];
  v1333[7] = v1335;
  int v1337 = v1193->timer;
  int v1579 = v1337 + 1;
  v1193->timer = v1579;
  int * v1339 = v1193->regs;
  int v1340 = v1339[12];
  bool v1581 = ((int)((unsigned int)(v1197 + 44) >> 2)) == ((int)((unsigned int)(v1340 + 8) >> 2));
  int v1395;
  if (v1581) {
    int v1341 = v1193->timer;
    int v1582 = v1341 + 1;
    v1193->timer = v1582;
    v1395 = v1199;
  } else {
    int * v1344 = v1193->cache_keys;
    int v1345 = v1344[0];
    bool v1585 = v1345 == ((int)((unsigned int)(v1340 + 8) >> 2));
    int v1393;
    if (v1585) {
      int * v1346 = v1193->cache_vals;
      int v1347 = v1346[0];
      v1393 = v1347;
    } else {
      int * v1349 = v1193->cache_keys;
      int v1350 = v1349[1];
      bool v1590 = v1350 == ((int)((unsigned int)(v1340 + 8) >> 2));
      int v1391;
      if (v1590) {
        int * v1351 = v1193->cache_vals;
        int v1352 = v1351[1];
        int * v1353 = v1193->cache_keys;
        int * v1354 = v1193->cache_keys;
        int v1355 = v1354[0];
        v1353[1] = v1355;
        int * v1357 = v1193->cache_vals;
        int * v1358 = v1193->cache_vals;
        int v1359 = v1358[0];
        v1357[1] = v1359;
        int * v1361 = v1193->cache_keys;
        int v1599 = (int)((unsigned int)(v1340 + 8) >> 2);
        v1361[0] = v1599;
        int * v1363 = v1193->cache_vals;
        v1363[0] = v1352;
        int v1365 = v1193->timer;
        int v1602 = v1365 + 1;
        v1193->timer = v1602;
        v1391 = v1352;
      } else {
        int * v1368 = v1193->mem;
        int v1604 = (int)((unsigned int)(v1340 + 8) >> 2);
        int v1369 = v1368[v1604];
        int * v1370 = v1193->mem;
        int * v1371 = v1193->cache_keys;
        int v1372 = v1371[1];
        int * v1373 = v1193->cache_vals;
        int v1374 = v1373[1];
        v1370[v1372] = v1374;
        int * v1376 = v1193->cache_keys;
        int * v1377 = v1193->cache_keys;
        int v1378 = v1377[0];
        v1376[1] = v1378;
        int * v1380 = v1193->cache_vals;
        int * v1381 = v1193->cache_vals;
        int v1382 = v1381[0];
        v1380[1] = v1382;
        int * v1384 = v1193->cache_keys;
        v1384[0] = v1604;
        int * v1386 = v1193->cache_vals;
        v1386[0] = v1369;
        int v1388 = v1193->timer;
        int v1619 = v1388 + 100;
        v1193->timer = v1619;
        v1391 = v1369;
      }
      v1393 = v1391;
    }
    v1395 = v1393;
  }
  int * v1396 = v1193->regs;
  v1396[7] = v1395;
  int * v1398 = v1193->cache_keys;
  int v1399 = v1398[0];
  bool v1625 = v1399 == ((int)((unsigned int)(v1197 + 44) >> 2));
  int v1443;
  if (v1625) {
    int * v1400 = v1193->cache_vals;
    v1400[0] = v1199;
    v1443 = v1199;
  } else {
    int * v1403 = v1193->cache_keys;
    int v1404 = v1403[1];
    bool v1630 = v1404 == ((int)((unsigned int)(v1197 + 44) >> 2));
    int v1441;
    if (v1630) {
      int * v1405 = v1193->cache_keys;
      int * v1406 = v1193->cache_keys;
      int v1407 = v1406[0];
      v1405[1] = v1407;
      int * v1409 = v1193->cache_vals;
      int * v1410 = v1193->cache_vals;
      int v1411 = v1410[0];
      v1409[1] = v1411;
      int * v1413 = v1193->cache_keys;
      int v1638 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1413[0] = v1638;
      int * v1415 = v1193->cache_vals;
      v1415[0] = v1199;
      int v1417 = v1193->timer;
      int v1641 = v1417 + 1;
      v1193->timer = v1641;
      v1441 = v1199;
    } else {
      int * v1420 = v1193->mem;
      int * v1421 = v1193->cache_keys;
      int v1422 = v1421[1];
      int * v1423 = v1193->cache_vals;
      int v1424 = v1423[1];
      v1420[v1422] = v1424;
      int * v1426 = v1193->cache_keys;
      int * v1427 = v1193->cache_keys;
      int v1428 = v1427[0];
      v1426[1] = v1428;
      int * v1430 = v1193->cache_vals;
      int * v1431 = v1193->cache_vals;
      int v1432 = v1431[0];
      v1430[1] = v1432;
      int * v1434 = v1193->cache_keys;
      int v1654 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1434[0] = v1654;
      int * v1436 = v1193->cache_vals;
      v1436[0] = v1199;
      int v1438 = v1193->timer;
      int v1657 = v1438 + 100;
      v1193->timer = v1657;
      v1441 = v1199;
    }
    v1443 = v1441;
  }
  bool v1659 = ((int)((unsigned int)v1215 >> 2)) == ((int)((unsigned int)(v1197 + 44) >> 2));
  struct StateT * v1466;
  if (v1659) {
    int v1444 = v1193->timer;
    int v1660 = v1444 + 15;
    v1193->timer = v1660;
    int * v1446 = v1193->saved_regs;
    int v1447 = v1446[30];
    int * v1448 = v1193->regs;
    v1448[30] = v1447;
    int * v1450 = v1193->saved_regs;
    int v1451 = v1450[29];
    int * v1452 = v1193->regs;
    v1452[29] = v1451;
    int * v1454 = v1193->saved_regs;
    int v1455 = v1454[28];
    int * v1456 = v1193->regs;
    v1456[28] = v1455;
    int * v1458 = v1193->saved_regs;
    int v1459 = v1458[7];
    int * v1460 = v1193->regs;
    v1460[7] = v1459;
    struct StateT * v1462 = slot_14(v1193);
    v1466 = v1462;
  } else {
    struct StateT * v1464 = slot_18(v1193);
    v1466 = v1464;
  }
  return v1466;
}

struct StateT * slot_111(struct StateT * v12406) {
  int v12407 = v12406->timer;
  int v12417 = v12407 + 1;
  v12406->timer = v12417;
  int * v12409 = v12406->regs;
  int v12410 = v12409[9];
  int * v12411 = v12406->regs;
  int v12412 = v12411[26];
  int * v12413 = v12406->regs;
  int v12424 = v12410 + v12412;
  v12413[15] = v12424;
  struct StateT * v12415 = slot_112(v12406);
  return v12415;
}

struct StateT * slot_109(struct StateT * v12359) {
  int v12360 = v12359->timer;
  int v12370 = v12360 + 1;
  v12359->timer = v12370;
  int * v12362 = v12359->regs;
  int v12363 = v12362[5];
  int * v12364 = v12359->regs;
  int v12365 = v12364[20];
  int * v12366 = v12359->regs;
  int v12377 = v12363 ^ v12365;
  v12366[18] = v12377;
  struct StateT * v12368 = slot_110(v12359);
  return v12368;
}

struct StateT * slot_174(struct StateT * v13602) {
  int v13603 = v13602->timer;
  int v13613 = v13603 + 1;
  v13602->timer = v13613;
  int * v13605 = v13602->regs;
  int v13606 = v13605[24];
  int * v13607 = v13602->regs;
  int v13608 = v13607[16];
  int * v13609 = v13602->regs;
  int v13620 = v13606 + v13608;
  v13609[8] = v13620;
  struct StateT * v13611 = slot_175(v13602);
  return v13611;
}

struct StateT * slot_147(struct StateT * v13080) {
  int v13081 = v13080->timer;
  int v13091 = v13081 + 1;
  v13080->timer = v13091;
  int * v13083 = v13080->regs;
  int v13084 = v13083[23];
  int * v13085 = v13080->regs;
  int v13086 = v13085[15];
  int * v13087 = v13080->regs;
  int v13097 = v13084 ^ v13086;
  v13087[23] = v13097;
  struct StateT * v13089 = slot_148(v13080);
  return v13089;
}

struct StateT * slot_42(struct StateT * v3670) {
  int v3671 = v3670->timer;
  int v3725 = v3671 + 1;
  v3670->timer = v3725;
  int * v3673 = v3670->regs;
  int v3674 = v3673[2];
  int * v3675 = v3670->regs;
  int v3676 = v3675[17];
  int * v3677 = v3670->cache_keys;
  int v3678 = v3677[0];
  bool v3732 = v3678 == ((int)((unsigned int)(v3674 + 28) >> 2));
  int v3722;
  if (v3732) {
    int * v3679 = v3670->cache_vals;
    v3679[0] = v3676;
    v3722 = v3676;
  } else {
    int * v3682 = v3670->cache_keys;
    int v3683 = v3682[1];
    bool v3737 = v3683 == ((int)((unsigned int)(v3674 + 28) >> 2));
    int v3720;
    if (v3737) {
      int * v3684 = v3670->cache_keys;
      int * v3685 = v3670->cache_keys;
      int v3686 = v3685[0];
      v3684[1] = v3686;
      int * v3688 = v3670->cache_vals;
      int * v3689 = v3670->cache_vals;
      int v3690 = v3689[0];
      v3688[1] = v3690;
      int * v3692 = v3670->cache_keys;
      int v3745 = (int)((unsigned int)(v3674 + 28) >> 2);
      v3692[0] = v3745;
      int * v3694 = v3670->cache_vals;
      v3694[0] = v3676;
      int v3696 = v3670->timer;
      int v3748 = v3696 + 1;
      v3670->timer = v3748;
      v3720 = v3676;
    } else {
      int * v3699 = v3670->mem;
      int * v3700 = v3670->cache_keys;
      int v3701 = v3700[1];
      int * v3702 = v3670->cache_vals;
      int v3703 = v3702[1];
      v3699[v3701] = v3703;
      int * v3705 = v3670->cache_keys;
      int * v3706 = v3670->cache_keys;
      int v3707 = v3706[0];
      v3705[1] = v3707;
      int * v3709 = v3670->cache_vals;
      int * v3710 = v3670->cache_vals;
      int v3711 = v3710[0];
      v3709[1] = v3711;
      int * v3713 = v3670->cache_keys;
      int v3761 = (int)((unsigned int)(v3674 + 28) >> 2);
      v3713[0] = v3761;
      int * v3715 = v3670->cache_vals;
      v3715[0] = v3676;
      int v3717 = v3670->timer;
      int v3764 = v3717 + 100;
      v3670->timer = v3764;
      v3720 = v3676;
    }
    v3722 = v3720;
  }
  struct StateT * v3723 = slot_43(v3670);
  return v3723;
}

struct StateT * slot_224(struct StateT * v6987) {
  int v6988 = v6987->timer;
  int v7046 = v6988 + 1;
  v6987->timer = v7046;
  int * v6990 = v6987->regs;
  int v6991 = v6990[2];
  int * v6992 = v6987->cache_keys;
  int v6993 = v6992[0];
  bool v7051 = v6993 == ((int)((unsigned int)(v6991 + 20) >> 2));
  int v7041;
  if (v7051) {
    int * v6994 = v6987->cache_vals;
    int v6995 = v6994[0];
    v7041 = v6995;
  } else {
    int * v6997 = v6987->cache_keys;
    int v6998 = v6997[1];
    bool v7056 = v6998 == ((int)((unsigned int)(v6991 + 20) >> 2));
    int v7039;
    if (v7056) {
      int * v6999 = v6987->cache_vals;
      int v7000 = v6999[1];
      int * v7001 = v6987->cache_keys;
      int * v7002 = v6987->cache_keys;
      int v7003 = v7002[0];
      v7001[1] = v7003;
      int * v7005 = v6987->cache_vals;
      int * v7006 = v6987->cache_vals;
      int v7007 = v7006[0];
      v7005[1] = v7007;
      int * v7009 = v6987->cache_keys;
      int v7065 = (int)((unsigned int)(v6991 + 20) >> 2);
      v7009[0] = v7065;
      int * v7011 = v6987->cache_vals;
      v7011[0] = v7000;
      int v7013 = v6987->timer;
      int v7068 = v7013 + 1;
      v6987->timer = v7068;
      v7039 = v7000;
    } else {
      int * v7016 = v6987->mem;
      int v7070 = (int)((unsigned int)(v6991 + 20) >> 2);
      int v7017 = v7016[v7070];
      int * v7018 = v6987->mem;
      int * v7019 = v6987->cache_keys;
      int v7020 = v7019[1];
      int * v7021 = v6987->cache_vals;
      int v7022 = v7021[1];
      v7018[v7020] = v7022;
      int * v7024 = v6987->cache_keys;
      int * v7025 = v6987->cache_keys;
      int v7026 = v7025[0];
      v7024[1] = v7026;
      int * v7028 = v6987->cache_vals;
      int * v7029 = v6987->cache_vals;
      int v7030 = v7029[0];
      v7028[1] = v7030;
      int * v7032 = v6987->cache_keys;
      v7032[0] = v7070;
      int * v7034 = v6987->cache_vals;
      v7034[0] = v7017;
      int v7036 = v6987->timer;
      int v7085 = v7036 + 100;
      v6987->timer = v7085;
      v7039 = v7017;
    }
    v7041 = v7039;
  }
  int * v7042 = v6987->regs;
  v7042[7] = v7041;
  struct StateT * v7044 = slot_225(v6987);
  return v7044;
}

struct StateT * slot_163(struct StateT * v13386) {
  int v13387 = v13386->timer;
  int v13397 = v13387 + 1;
  v13386->timer = v13397;
  int * v13389 = v13386->regs;
  int v13390 = v13389[6];
  int * v13391 = v13386->regs;
  int v13392 = v13391[9];
  int * v13393 = v13386->regs;
  int v13403 = v13390 | v13392;
  v13393[6] = v13403;
  struct StateT * v13395 = slot_164(v13386);
  return v13395;
}

struct StateT * slot_184(struct StateT * v13782) {
  int v13783 = v13782->timer;
  int v13791 = v13783 + 1;
  v13782->timer = v13791;
  int * v13785 = v13782->regs;
  int v13786 = v13785[8];
  int * v13787 = v13782->regs;
  int v13796 = (int)((unsigned int)v13786 >> 19);
  v13787[9] = v13796;
  struct StateT * v13789 = slot_185(v13782);
  return v13789;
}

struct StateT * slot_204(struct StateT * v14158) {
  int v14159 = v14158->timer;
  int v14167 = v14159 + 1;
  v14158->timer = v14167;
  int * v14161 = v14158->regs;
  int v14162 = v14161[8];
  int * v14163 = v14158->regs;
  int v14172 = (int)((unsigned int)v14162 >> 14);
  v14163[9] = v14172;
  struct StateT * v14165 = slot_205(v14158);
  return v14165;
}

struct StateT * slot_194(struct StateT * v13978) {
  int v13979 = v13978->timer;
  int v13989 = v13979 + 1;
  v13978->timer = v13989;
  int * v13981 = v13978->regs;
  int v13982 = v13981[1];
  int * v13983 = v13978->regs;
  int v13984 = v13983[24];
  int * v13985 = v13978->regs;
  int v13996 = v13982 + v13984;
  v13985[8] = v13996;
  struct StateT * v13987 = slot_195(v13978);
  return v13987;
}

struct StateT * slot_165(struct StateT * v13423) {
  int v13424 = v13423->timer;
  int v13432 = v13424 + 1;
  v13423->timer = v13432;
  int * v13426 = v13423->regs;
  int v13427 = v13426[8];
  int * v13428 = v13423->regs;
  int v13436 = v13427 << 9;
  v13428[8] = v13436;
  struct StateT * v13430 = slot_166(v13423);
  return v13430;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v8784) {
  int v8785 = v8784->timer;
  int v8839 = v8785 + 1;
  v8784->timer = v8839;
  int * v8787 = v8784->regs;
  int v8788 = v8787[10];
  int * v8789 = v8784->regs;
  int v8790 = v8789[12];
  int * v8791 = v8784->cache_keys;
  int v8792 = v8791[0];
  bool v8846 = v8792 == ((int)((unsigned int)(v8788 + 16) >> 2));
  int v8836;
  if (v8846) {
    int * v8793 = v8784->cache_vals;
    v8793[0] = v8790;
    v8836 = v8790;
  } else {
    int * v8796 = v8784->cache_keys;
    int v8797 = v8796[1];
    bool v8851 = v8797 == ((int)((unsigned int)(v8788 + 16) >> 2));
    int v8834;
    if (v8851) {
      int * v8798 = v8784->cache_keys;
      int * v8799 = v8784->cache_keys;
      int v8800 = v8799[0];
      v8798[1] = v8800;
      int * v8802 = v8784->cache_vals;
      int * v8803 = v8784->cache_vals;
      int v8804 = v8803[0];
      v8802[1] = v8804;
      int * v8806 = v8784->cache_keys;
      int v8859 = (int)((unsigned int)(v8788 + 16) >> 2);
      v8806[0] = v8859;
      int * v8808 = v8784->cache_vals;
      v8808[0] = v8790;
      int v8810 = v8784->timer;
      int v8862 = v8810 + 1;
      v8784->timer = v8862;
      v8834 = v8790;
    } else {
      int * v8813 = v8784->mem;
      int * v8814 = v8784->cache_keys;
      int v8815 = v8814[1];
      int * v8816 = v8784->cache_vals;
      int v8817 = v8816[1];
      v8813[v8815] = v8817;
      int * v8819 = v8784->cache_keys;
      int * v8820 = v8784->cache_keys;
      int v8821 = v8820[0];
      v8819[1] = v8821;
      int * v8823 = v8784->cache_vals;
      int * v8824 = v8784->cache_vals;
      int v8825 = v8824[0];
      v8823[1] = v8825;
      int * v8827 = v8784->cache_keys;
      int v8875 = (int)((unsigned int)(v8788 + 16) >> 2);
      v8827[0] = v8875;
      int * v8829 = v8784->cache_vals;
      v8829[0] = v8790;
      int v8831 = v8784->timer;
      int v8878 = v8831 + 100;
      v8784->timer = v8878;
      v8834 = v8790;
    }
    v8836 = v8834;
  }
  struct StateT * v8837 = slot_251(v8784);
  return v8837;
}

struct StateT * slot_259(struct StateT * v9843) {
  int v9844 = v9843->timer;
  int v9898 = v9844 + 1;
  v9843->timer = v9898;
  int * v9846 = v9843->regs;
  int v9847 = v9846[10];
  int * v9848 = v9843->regs;
  int v9849 = v9848[24];
  int * v9850 = v9843->cache_keys;
  int v9851 = v9850[0];
  bool v9905 = v9851 == ((int)((unsigned int)(v9847 + 52) >> 2));
  int v9895;
  if (v9905) {
    int * v9852 = v9843->cache_vals;
    v9852[0] = v9849;
    v9895 = v9849;
  } else {
    int * v9855 = v9843->cache_keys;
    int v9856 = v9855[1];
    bool v9910 = v9856 == ((int)((unsigned int)(v9847 + 52) >> 2));
    int v9893;
    if (v9910) {
      int * v9857 = v9843->cache_keys;
      int * v9858 = v9843->cache_keys;
      int v9859 = v9858[0];
      v9857[1] = v9859;
      int * v9861 = v9843->cache_vals;
      int * v9862 = v9843->cache_vals;
      int v9863 = v9862[0];
      v9861[1] = v9863;
      int * v9865 = v9843->cache_keys;
      int v9918 = (int)((unsigned int)(v9847 + 52) >> 2);
      v9865[0] = v9918;
      int * v9867 = v9843->cache_vals;
      v9867[0] = v9849;
      int v9869 = v9843->timer;
      int v9921 = v9869 + 1;
      v9843->timer = v9921;
      v9893 = v9849;
    } else {
      int * v9872 = v9843->mem;
      int * v9873 = v9843->cache_keys;
      int v9874 = v9873[1];
      int * v9875 = v9843->cache_vals;
      int v9876 = v9875[1];
      v9872[v9874] = v9876;
      int * v9878 = v9843->cache_keys;
      int * v9879 = v9843->cache_keys;
      int v9880 = v9879[0];
      v9878[1] = v9880;
      int * v9882 = v9843->cache_vals;
      int * v9883 = v9843->cache_vals;
      int v9884 = v9883[0];
      v9882[1] = v9884;
      int * v9886 = v9843->cache_keys;
      int v9934 = (int)((unsigned int)(v9847 + 52) >> 2);
      v9886[0] = v9934;
      int * v9888 = v9843->cache_vals;
      v9888[0] = v9849;
      int v9890 = v9843->timer;
      int v9937 = v9890 + 100;
      v9843->timer = v9937;
      v9893 = v9849;
    }
    v9895 = v9893;
  }
  struct StateT * v9896 = slot_260(v9843);
  return v9896;
}

struct StateT * slot_117(struct StateT * v12523) {
  int v12524 = v12523->timer;
  int v12534 = v12524 + 1;
  v12523->timer = v12534;
  int * v12526 = v12523->regs;
  int v12527 = v12526[15];
  int * v12528 = v12523->regs;
  int v12529 = v12528[6];
  int * v12530 = v12523->regs;
  int v12540 = v12527 | v12529;
  v12530[15] = v12540;
  struct StateT * v12532 = slot_118(v12523);
  return v12532;
}

struct StateT * slot_249(struct StateT * v8666) {
  int v8667 = v8666->timer;
  int v8721 = v8667 + 1;
  v8666->timer = v8721;
  int * v8669 = v8666->regs;
  int v8670 = v8669[10];
  int * v8671 = v8666->regs;
  int v8672 = v8671[14];
  int * v8673 = v8666->cache_keys;
  int v8674 = v8673[0];
  bool v8728 = v8674 == ((int)((unsigned int)(v8670 + 12) >> 2));
  int v8718;
  if (v8728) {
    int * v8675 = v8666->cache_vals;
    v8675[0] = v8672;
    v8718 = v8672;
  } else {
    int * v8678 = v8666->cache_keys;
    int v8679 = v8678[1];
    bool v8733 = v8679 == ((int)((unsigned int)(v8670 + 12) >> 2));
    int v8716;
    if (v8733) {
      int * v8680 = v8666->cache_keys;
      int * v8681 = v8666->cache_keys;
      int v8682 = v8681[0];
      v8680[1] = v8682;
      int * v8684 = v8666->cache_vals;
      int * v8685 = v8666->cache_vals;
      int v8686 = v8685[0];
      v8684[1] = v8686;
      int * v8688 = v8666->cache_keys;
      int v8741 = (int)((unsigned int)(v8670 + 12) >> 2);
      v8688[0] = v8741;
      int * v8690 = v8666->cache_vals;
      v8690[0] = v8672;
      int v8692 = v8666->timer;
      int v8744 = v8692 + 1;
      v8666->timer = v8744;
      v8716 = v8672;
    } else {
      int * v8695 = v8666->mem;
      int * v8696 = v8666->cache_keys;
      int v8697 = v8696[1];
      int * v8698 = v8666->cache_vals;
      int v8699 = v8698[1];
      v8695[v8697] = v8699;
      int * v8701 = v8666->cache_keys;
      int * v8702 = v8666->cache_keys;
      int v8703 = v8702[0];
      v8701[1] = v8703;
      int * v8705 = v8666->cache_vals;
      int * v8706 = v8666->cache_vals;
      int v8707 = v8706[0];
      v8705[1] = v8707;
      int * v8709 = v8666->cache_keys;
      int v8757 = (int)((unsigned int)(v8670 + 12) >> 2);
      v8709[0] = v8757;
      int * v8711 = v8666->cache_vals;
      v8711[0] = v8672;
      int v8713 = v8666->timer;
      int v8760 = v8713 + 100;
      v8666->timer = v8760;
      v8716 = v8672;
    }
    v8718 = v8716;
  }
  struct StateT * v8719 = slot_250(v8666);
  return v8719;
}

struct StateT * slot_90(struct StateT * v9118) {
  int v9119 = v9118->timer;
  int v9129 = v9119 + 1;
  v9118->timer = v9129;
  int * v9121 = v9118->regs;
  int v9122 = v9121[25];
  int * v9123 = v9118->regs;
  int v9124 = v9123[18];
  int * v9125 = v9118->regs;
  int v9135 = v9122 ^ v9124;
  v9125[25] = v9135;
  struct StateT * v9127 = slot_91(v9118);
  return v9127;
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
    s->saved_regs[i] = 0;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}