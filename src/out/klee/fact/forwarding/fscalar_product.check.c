// verify: leak likely-timeout (KLEE probably does not finish this path space) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
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

struct StateT * slot_12(struct StateT * v2226);
struct StateT * slot_228(struct StateT * v12471);
struct StateT * slot_143(struct StateT * v8657);
struct StateT * slot_120(struct StateT * v7885);
struct StateT * slot_226(struct StateT * v12132);
struct StateT * slot_167(struct StateT * v10266);
struct StateT * slot_152(struct StateT * v8829);
struct StateT * slot_231(struct StateT * v13911);
struct StateT * slot_199(struct StateT * v10984);
struct StateT * slot_92(struct StateT * v6416);
struct StateT * slot_232(struct StateT * v14136);
struct StateT * slot_31(struct StateT * v3594);
struct StateT * slot_236(struct StateT * v14115);
struct StateT * slot_241(struct StateT * v14571);
struct StateT * slot_160(struct StateT * v8994);
struct StateT * slot_65(struct StateT * v4620);
struct StateT * slot_10(struct StateT * v2165);
struct StateT * slot_150(struct StateT * v8788);
struct StateT * slot_74(struct StateT * v5144);
struct StateT * slot_107(struct StateT * v6704);
struct StateT * slot_136(struct StateT * v8524);
struct StateT * slot_84(struct StateT * v6281);
struct StateT * slot_28(struct StateT * v3618);
struct StateT * slot_155(struct StateT * v8870);
struct StateT * slot_177(struct StateT * v10580);
struct StateT * slot_229(struct StateT * v13662);
struct StateT * slot_17(struct StateT * v2310);
struct StateT * slot_181(struct StateT * v10648);
struct StateT * slot_197(struct StateT * v10952);
struct StateT * slot_207(struct StateT * v11153);
struct StateT * slot_156(struct StateT * v8902);
struct StateT * slot_154(struct StateT * v8862);
struct StateT * slot_68(struct StateT * v4692);
struct StateT * slot_105(struct StateT * v6663);
struct StateT * slot_27(struct StateT * v3578);
struct StateT * slot_164(struct StateT * v9394);
struct StateT * slot_15(struct StateT * v2277);
struct StateT * slot_133(struct StateT * v8473);
struct StateT * slot_56(struct StateT * v4466);
struct StateT * slot_244(struct StateT * v14618);
struct StateT * slot_222(struct StateT * v11472);
struct StateT * slot_34(struct StateT * v4084);
struct StateT * slot_171(struct StateT * v10242);
struct StateT * slot_162(struct StateT * v9062);
struct StateT * slot_21(struct StateT * v2383);
struct StateT * slot_239(struct StateT * v14340);
struct StateT * slot_118(struct StateT * v7252);
struct StateT * slot_121(struct StateT * v7899);
struct StateT * slot_144(struct StateT * v8673);
struct StateT * slot_201(struct StateT * v11024);
struct StateT * slot_94(struct StateT * v6449);
struct StateT * slot_63(struct StateT * v4596);
struct StateT * slot_146(struct StateT * v8715);
struct StateT * slot_24(struct StateT * v2439);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v10911);
struct StateT * slot_125(struct StateT * v7914);
struct StateT * slot_148(struct StateT * v8747);
struct StateT * slot_126(struct StateT * v8118);
struct StateT * slot_223(struct StateT * v11787);
struct StateT * slot_79(struct StateT * v6077);
struct StateT * slot_237(struct StateT * v14120);
struct StateT * slot_41(struct StateT * v4196);
struct StateT * slot_39(struct StateT * v4162);
struct StateT * slot_142(struct StateT * v8632);
struct StateT * slot_60(struct StateT * v4539);
struct StateT * slot_112(struct StateT * v6793);
struct StateT * slot_47(struct StateT * v4294);
struct StateT * slot_214(struct StateT * v11259);
struct StateT * slot_29(struct StateT * v3847);
struct StateT * slot_16(struct StateT * v2294);
struct StateT * slot_245(struct StateT * v14634);
struct StateT * slot_113(struct StateT * v6817);
struct StateT * slot_151(struct StateT * v8813);
struct StateT * slot_7(struct StateT * v2182);
struct StateT * slot_124(struct StateT * v8202);
struct StateT * slot_191(struct StateT * v10837);
struct StateT * slot_103(struct StateT * v6622);
struct StateT * slot_128(struct StateT * v8188);
struct StateT * slot_19(struct StateT * v2351);
struct StateT * slot_87(struct StateT * v6331);
struct StateT * slot_67(struct StateT * v4668);
struct StateT * slot_81(struct StateT * v5993);
struct StateT * slot_95(struct StateT * v6466);
struct StateT * slot_115(struct StateT * v6869);
struct StateT * slot_78(struct StateT * v6047);
struct StateT * slot_32(struct StateT * v3822);
struct StateT * slot_205(struct StateT * v11115);
struct StateT * slot_193(struct StateT * v10870);
struct StateT * slot_233(struct StateT * v14353);
struct StateT * slot_176(struct StateT * v10563);
struct StateT * slot_189(struct StateT * v10796);
struct StateT * slot_33(struct StateT * v4051);
struct StateT * slot_35(struct StateT * v4099);
struct StateT * slot_246(struct StateT * v14650);
struct StateT * slot_210(struct StateT * v11196);
struct StateT * slot_166(struct StateT * v10024);
struct StateT * slot_51(struct StateT * v4366);
struct StateT * slot_52(struct StateT * v4383);
struct StateT * slot_83(struct StateT * v6063);
struct StateT * slot_25(struct StateT * v2455);
struct StateT * slot_209(struct StateT * v11182);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_123(struct StateT * v8172);
struct StateT * slot_73(struct StateT * v5127);
struct StateT * slot_198(struct StateT * v10968);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v10755);
struct StateT * slot_97(struct StateT * v6507);
struct StateT * slot_182(struct StateT * v10664);
struct StateT * slot_38(struct StateT * v4145);
struct StateT * slot_178(struct StateT * v10597);
struct StateT * slot_106(struct StateT * v6688);
struct StateT * slot_98(struct StateT * v6532);
struct StateT * slot_159(struct StateT * v8963);
struct StateT * slot_46(struct StateT * v4277);
struct StateT * slot_212(struct StateT * v11226);
struct StateT * slot_132(struct StateT * v8456);
struct StateT * slot_130(struct StateT * v8422);
struct StateT * slot_211(struct StateT * v11210);
struct StateT * slot_20(struct StateT * v2367);
struct StateT * slot_141(struct StateT * v8616);
struct StateT * slot_61(struct StateT * v4564);
struct StateT * slot_30(struct StateT * v4067);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_18(struct StateT * v2326);
struct StateT * slot_9(struct StateT * v1944);
struct StateT * slot_183(struct StateT * v10680);
struct StateT * slot_240(struct StateT * v14557);
struct StateT * slot_247(struct StateT * v14666);
struct StateT * slot_43(struct StateT * v4230);
struct StateT * slot_70(struct StateT * v4744);
struct StateT * slot_168(struct StateT * v10296);
struct StateT * slot_76(struct StateT * v5774);
struct StateT * slot_6(struct StateT * v1961);
struct StateT * slot_225(struct StateT * v12118);
struct StateT * slot_55(struct StateT * v4449);
struct StateT * slot_213(struct StateT * v11243);
struct StateT * slot_82(struct StateT * v6031);
struct StateT * slot_161(struct StateT * v9046);
struct StateT * slot_185(struct StateT * v10713);
struct StateT * slot_91(struct StateT * v6399);
struct StateT * slot_58(struct StateT * v4498);
struct StateT * slot_89(struct StateT * v6365);
struct StateT * slot_66(struct StateT * v4652);
struct StateT * slot_140(struct StateT * v8591);
struct StateT * slot_49(struct StateT * v4326);
struct StateT * slot_216(struct StateT * v11298);
struct StateT * slot_50(struct StateT * v4342);
struct StateT * slot_37(struct StateT * v4129);
struct StateT * slot_114(struct StateT * v6838);
struct StateT * slot_135(struct StateT * v8507);
struct StateT * slot_248(struct StateT * v14682);
struct StateT * slot_59(struct StateT * v4515);
struct StateT * slot_192(struct StateT * v10853);
struct StateT * slot_40(struct StateT * v4179);
struct StateT * slot_48(struct StateT * v4310);
struct StateT * slot_77(struct StateT * v6017);
struct StateT * slot_85(struct StateT * v6297);
struct StateT * slot_75(struct StateT * v5760);
struct StateT * slot_72(struct StateT * v4812);
struct StateT * slot_119(struct StateT * v7269);
struct StateT * slot_71(struct StateT * v4796);
struct StateT * slot_101(struct StateT * v6590);
struct StateT * slot_108(struct StateT * v6721);
struct StateT * slot_116(struct StateT * v6921);
struct StateT * slot_93(struct StateT * v6432);
struct StateT * slot_88(struct StateT * v6348);
struct StateT * slot_96(struct StateT * v6491);
struct StateT * slot_215(struct StateT * v11282);
struct StateT * slot_234(struct StateT * v13882);
struct StateT * slot_45(struct StateT * v4260);
struct StateT * slot_218(struct StateT * v11345);
struct StateT * slot_220(struct StateT * v11377);
struct StateT * slot_134(struct StateT * v8490);
struct StateT * slot_175(struct StateT * v10546);
struct StateT * slot_69(struct StateT * v4713);
struct StateT * slot_202(struct StateT * v11040);
struct StateT * slot_230(struct StateT * v13678);
struct StateT * slot_188(struct StateT * v10780);
struct StateT * slot_138(struct StateT * v8557);
struct StateT * slot_186(struct StateT * v10738);
struct StateT * slot_102(struct StateT * v6606);
struct StateT * slot_145(struct StateT * v8698);
struct StateT * slot_110(struct StateT * v6745);
struct StateT * slot_196(struct StateT * v10936);
struct StateT * slot_208(struct StateT * v11169);
struct StateT * slot_172(struct StateT * v10280);
struct StateT * slot_131(struct StateT * v8439);
struct StateT * slot_8(struct StateT * v2212);
struct StateT * slot_180(struct StateT * v10631);
struct StateT * slot_203(struct StateT * v11063);
struct StateT * slot_190(struct StateT * v10821);
struct StateT * slot_157(struct StateT * v8918);
struct StateT * slot_242(struct StateT * v14585);
struct StateT * slot_200(struct StateT * v10992);
struct StateT * slot_243(struct StateT * v14601);
struct StateT * slot_173(struct StateT * v10312);
struct StateT * slot_149(struct StateT * v8764);
struct StateT * slot_5(struct StateT * v1740);
struct StateT * slot_104(struct StateT * v6639);
struct StateT * slot_235(struct StateT * v13896);
struct StateT * slot_54(struct StateT * v4424);
struct StateT * slot_26(struct StateT * v2770);
struct StateT * slot_206(struct StateT * v11131);
struct StateT * slot_227(struct StateT * v12447);
struct StateT * slot_169(struct StateT * v10326);
struct StateT * slot_64(struct StateT * v4612);
struct StateT * slot_170(struct StateT * v10039);
struct StateT * slot_14(struct StateT * v2260);
struct StateT * slot_53(struct StateT * v4408);
struct StateT * slot_80(struct StateT * v5789);
struct StateT * slot_44(struct StateT * v4244);
struct StateT * slot_137(struct StateT * v8541);
struct StateT * slot_122(struct StateT * v8142);
struct StateT * slot_99(struct StateT * v6548);
struct StateT * slot_179(struct StateT * v10614);
struct StateT * slot_219(struct StateT * v11361);
struct StateT * slot_36(struct StateT * v4113);
struct StateT * slot_57(struct StateT * v4482);
struct StateT * slot_62(struct StateT * v4580);
struct StateT * slot_22(struct StateT * v2408);
struct StateT * slot_139(struct StateT * v8574);
struct StateT * slot_221(struct StateT * v11456);
struct StateT * slot_23(struct StateT * v2425);
struct StateT * slot_153(struct StateT * v8846);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v6314);
struct StateT * slot_129(struct StateT * v8406);
struct StateT * slot_158(struct StateT * v8942);
struct StateT * slot_100(struct StateT * v6573);
struct StateT * slot_127(struct StateT * v8156);
struct StateT * slot_217(struct StateT * v11314);
struct StateT * slot_13(struct StateT * v2243);
struct StateT * slot_111(struct StateT * v6777);
struct StateT * slot_109(struct StateT * v6737);
struct StateT * slot_174(struct StateT * v10530);
struct StateT * slot_147(struct StateT * v8731);
struct StateT * slot_42(struct StateT * v4213);
struct StateT * slot_224(struct StateT * v11803);
struct StateT * slot_163(struct StateT * v9377);
struct StateT * slot_184(struct StateT * v10696);
struct StateT * slot_204(struct StateT * v11084);
struct StateT * slot_194(struct StateT * v10887);
struct StateT * slot_165(struct StateT * v10010);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v14722);
struct StateT * slot_117(struct StateT * v6937);
struct StateT * slot_249(struct StateT * v14706);
struct StateT * slot_90(struct StateT * v6382);
struct StateT * slot_11(struct StateT * v2195);
struct StateT * slot_12(struct StateT * v2226) {
  int v2227 = v2226->timer;
  int v2235 = v2227 + 1;
  v2226->timer = v2235;
  int * v2229 = v2226->regs;
  int v2230 = v2229[14];
  int v2231 = v2229[13];
  int v2240 = v2230 * v2231;
  v2229[7] = v2240;
  struct StateT * v2233 = slot_13(v2226);
  return v2233;
}

struct StateT * slot_228(struct StateT * v12471) {
  int v12472 = v12471->timer;
  int v13121 = v12472 + 1;
  v12471->timer = v13121;
  int * v12474 = v12471->regs;
  int v12475 = v12474[10];
  int v12476 = v12474[16];
  int * v12477 = v12471->saved_regs;
  int v12478 = v12474[8];
  v12477[8] = v12478;
  int v12480 = v12471->timer;
  int v13128 = v12480 + 1;
  v12471->timer = v13128;
  int * v12482 = v12471->regs;
  int v12483 = v12482[2];
  int * v12484 = v12471->cache_tags;
  int v13132 = (((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2;
  int v12485 = v12484[v13132];
  int v13133 = ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12486 = v12484[v13133];
  int v13134 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2);
  int v12487 = v12484[v13134];
  int v13135 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12488 = v12484[v13135];
  int v12489 = v12471->timer;
  int v13136 = v12489 + ((100 ^ (((~(((v12487 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12487 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12485 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12485 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12486 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12486 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12487 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12487 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12471->timer = v13136;
  int * v12491 = v12471->cache_vals;
  bool v13137 = !(((~(((v12485 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12485 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12486 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12486 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v12584;
  if (v13137) {
    int * v12492 = v12471->cache_age;
    int v13139 = ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v12486 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12486 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v12493 = v12492[v13139];
    int v12494 = v12492[v13132];
    int v13140 = v12494 + ((int)((unsigned int)(v12494 - v12493) >> 31));
    v12492[v13132] = v13140;
    int * v12496 = v12471->cache_age;
    int v12497 = v12496[v13133];
    int v13142 = v12497 + ((int)((unsigned int)(v12497 - v12493) >> 31));
    v12496[v13133] = v13142;
    int * v12499 = v12471->cache_age;
    v12499[v13139] = 0;
    v12584 = v13139;
  } else {
    int * v12502 = v12471->cache_age;
    int v13146 = (((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2;
    int v12503 = v12502[v13146];
    int * v12504 = v12471->cache_tags;
    int v12505 = v12504[v13146];
    int v12506 = v12502[v13133];
    int v12507 = v12504[v13133];
    bool v13148 = !(((~(((v12487 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12487 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v12561;
    if (v13148) {
      int * v12508 = v12471->cache_age;
      int v13150 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))) | (-(v12488 ^ ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v12509 = v12508[v13150];
      int v12510 = v12508[v13134];
      int v13151 = v12510 + ((int)((unsigned int)(v12510 - v12509) >> 31));
      v12508[v13134] = v13151;
      int * v12512 = v12471->cache_age;
      int v12513 = v12512[v13135];
      int v13153 = v12513 + ((int)((unsigned int)(v12513 - v12509) >> 31));
      v12512[v13135] = v13153;
      int * v12515 = v12471->cache_age;
      v12515[v13150] = 0;
      v12561 = v13150;
    } else {
      int * v12518 = v12471->cache_age;
      int v13157 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2);
      int v12519 = v12518[v13157];
      int * v12520 = v12471->cache_tags;
      int v12521 = v12520[v13157];
      int v12522 = v12518[v13135];
      int v12523 = v12520[v13135];
      int * v12524 = v12471->cache_dirty;
      int v13160 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12519 + ((~(((v12521 ^ -1) | (-(v12521 ^ -1))) >> 31)) & 2)) - (v12522 + ((~(((v12523 ^ -1) | (-(v12523 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12525 = v12524[v13160];
      bool v13161 = !(v12525 == 0);
      if (v13161) {
        int * v12526 = v12471->cache_tags;
        int v12527 = v12526[v13160];
        int * v12528 = v12471->cache_vals;
        int v13164 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12519 + ((~(((v12521 ^ -1) | (-(v12521 ^ -1))) >> 31)) & 2)) - (v12522 + ((~(((v12523 ^ -1) | (-(v12523 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12529 = v12528[v13164];
        int v13165 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12519 + ((~(((v12521 ^ -1) | (-(v12521 ^ -1))) >> 31)) & 2)) - (v12522 + ((~(((v12523 ^ -1) | (-(v12523 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12530 = v12528[v13165];
        int * v12531 = v12471->mem;
        int v13167 = v12527 * 2;
        v12531[v13167] = v12529;
        int * v12533 = v12471->mem;
        int v13170 = (v12527 * 2) + 1;
        v12533[v13170] = v12530;
        ;
      } else {
        ;
      }
      int * v12538 = v12471->mem;
      int v13175 = ((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) * 2;
      int v12539 = v12538[v13175];
      int v13176 = (((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) * 2) + 1;
      int v12540 = v12538[v13176];
      int * v12541 = v12471->cache_vals;
      int v13178 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12519 + ((~(((v12521 ^ -1) | (-(v12521 ^ -1))) >> 31)) & 2)) - (v12522 + ((~(((v12523 ^ -1) | (-(v12523 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12541[v13178] = v12539;
      int * v12543 = v12471->cache_vals;
      int v13181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v12519 + ((~(((v12521 ^ -1) | (-(v12521 ^ -1))) >> 31)) & 2)) - (v12522 + ((~(((v12523 ^ -1) | (-(v12523 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12543[v13181] = v12540;
      int * v12545 = v12471->cache_tags;
      int v13184 = (int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1);
      v12545[v13160] = v13184;
      int * v12547 = v12471->cache_dirty;
      v12547[v13160] = 0;
      int * v12549 = v12471->cache_age;
      v12549[v13160] = 1;
      int * v12551 = v12471->cache_age;
      int v12552 = v12551[v13160];
      int v12553 = v12551[v13134];
      int v13190 = v12553 + ((int)((unsigned int)(v12553 - v12552) >> 31));
      v12551[v13134] = v13190;
      int * v12555 = v12471->cache_age;
      int v12556 = v12555[v13135];
      int v13192 = v12556 + ((int)((unsigned int)(v12556 - v12552) >> 31));
      v12555[v13135] = v13192;
      int * v12558 = v12471->cache_age;
      v12558[v13160] = 0;
      v12561 = v13160;
    }
    int * v12562 = v12471->cache_vals;
    int v13195 = v12561 * 2;
    int v12563 = v12562[v13195];
    int v13196 = (v12561 * 2) + 1;
    int v12564 = v12562[v13196];
    int v13197 = (((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v12503 + ((~(((v12505 ^ -1) | (-(v12505 ^ -1))) >> 31)) & 2)) - (v12506 + ((~(((v12507 ^ -1) | (-(v12507 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12562[v13197] = v12563;
    int * v12566 = v12471->cache_vals;
    int v13200 = ((((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v12503 + ((~(((v12505 ^ -1) | (-(v12505 ^ -1))) >> 31)) & 2)) - (v12506 + ((~(((v12507 ^ -1) | (-(v12507 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12566[v13200] = v12564;
    int * v12568 = v12471->cache_tags;
    int v13203 = ((((int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v12503 + ((~(((v12505 ^ -1) | (-(v12505 ^ -1))) >> 31)) & 2)) - (v12506 + ((~(((v12507 ^ -1) | (-(v12507 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13204 = (int)((unsigned int)((int)((unsigned int)(v12483 + 12) >> 2)) >> 1);
    v12568[v13203] = v13204;
    int * v12570 = v12471->cache_dirty;
    v12570[v13203] = 0;
    int * v12572 = v12471->cache_age;
    v12572[v13203] = 1;
    int * v12574 = v12471->cache_age;
    int v12575 = v12574[v13203];
    int v12576 = v12574[v13132];
    int v13210 = v12576 + ((int)((unsigned int)(v12576 - v12575) >> 31));
    v12574[v13132] = v13210;
    int * v12578 = v12471->cache_age;
    int v12579 = v12578[v13133];
    int v13212 = v12579 + ((int)((unsigned int)(v12579 - v12575) >> 31));
    v12578[v13133] = v13212;
    int * v12581 = v12471->cache_age;
    v12581[v13203] = 0;
    v12584 = v13203;
  }
  int v13215 = (v12584 * 2) + (((int)((unsigned int)(v12483 + 12) >> 2)) & 1);
  int v12585 = v12491[v13215];
  int * v12586 = v12471->regs;
  v12586[8] = v12585;
  int * v12588 = v12471->saved_regs;
  int * v12589 = v12471->regs;
  int v12590 = v12589[9];
  v12588[9] = v12590;
  int v12592 = v12471->timer;
  int v13222 = v12592 + 1;
  v12471->timer = v13222;
  int * v12594 = v12471->regs;
  int v12595 = v12594[2];
  int * v12596 = v12471->cache_tags;
  int v13225 = (((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2;
  int v12597 = v12596[v13225];
  int v13226 = ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12598 = v12596[v13226];
  int v13227 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2);
  int v12599 = v12596[v13227];
  int v13228 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12600 = v12596[v13228];
  int v12601 = v12471->timer;
  int v13229 = v12601 + ((100 ^ (((~(((v12599 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12599 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12597 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12597 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v12598 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12598 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12599 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12599 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12471->timer = v13229;
  int * v12603 = v12471->cache_vals;
  bool v13230 = !(((~(((v12597 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12597 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v12598 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12598 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v12696;
  if (v13230) {
    int * v12604 = v12471->cache_age;
    int v13232 = ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v12598 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12598 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v12605 = v12604[v13232];
    int v12606 = v12604[v13225];
    int v13233 = v12606 + ((int)((unsigned int)(v12606 - v12605) >> 31));
    v12604[v13225] = v13233;
    int * v12608 = v12471->cache_age;
    int v12609 = v12608[v13226];
    int v13235 = v12609 + ((int)((unsigned int)(v12609 - v12605) >> 31));
    v12608[v13226] = v13235;
    int * v12611 = v12471->cache_age;
    v12611[v13232] = 0;
    v12696 = v13232;
  } else {
    int * v12614 = v12471->cache_age;
    int v13239 = (((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2;
    int v12615 = v12614[v13239];
    int * v12616 = v12471->cache_tags;
    int v12617 = v12616[v13239];
    int v12618 = v12614[v13226];
    int v12619 = v12616[v13226];
    bool v13241 = !(((~(((v12599 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12599 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v12673;
    if (v13241) {
      int * v12620 = v12471->cache_age;
      int v13243 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))) | (-(v12600 ^ ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v12621 = v12620[v13243];
      int v12622 = v12620[v13227];
      int v13244 = v12622 + ((int)((unsigned int)(v12622 - v12621) >> 31));
      v12620[v13227] = v13244;
      int * v12624 = v12471->cache_age;
      int v12625 = v12624[v13228];
      int v13246 = v12625 + ((int)((unsigned int)(v12625 - v12621) >> 31));
      v12624[v13228] = v13246;
      int * v12627 = v12471->cache_age;
      v12627[v13243] = 0;
      v12673 = v13243;
    } else {
      int * v12630 = v12471->cache_age;
      int v13250 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2);
      int v12631 = v12630[v13250];
      int * v12632 = v12471->cache_tags;
      int v12633 = v12632[v13250];
      int v12634 = v12630[v13228];
      int v12635 = v12632[v13228];
      int * v12636 = v12471->cache_dirty;
      int v13253 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v12631 + ((~(((v12633 ^ -1) | (-(v12633 ^ -1))) >> 31)) & 2)) - (v12634 + ((~(((v12635 ^ -1) | (-(v12635 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12637 = v12636[v13253];
      bool v13254 = !(v12637 == 0);
      if (v13254) {
        int * v12638 = v12471->cache_tags;
        int v12639 = v12638[v13253];
        int * v12640 = v12471->cache_vals;
        int v13257 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v12631 + ((~(((v12633 ^ -1) | (-(v12633 ^ -1))) >> 31)) & 2)) - (v12634 + ((~(((v12635 ^ -1) | (-(v12635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12641 = v12640[v13257];
        int v13258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v12631 + ((~(((v12633 ^ -1) | (-(v12633 ^ -1))) >> 31)) & 2)) - (v12634 + ((~(((v12635 ^ -1) | (-(v12635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12642 = v12640[v13258];
        int * v12643 = v12471->mem;
        int v13260 = v12639 * 2;
        v12643[v13260] = v12641;
        int * v12645 = v12471->mem;
        int v13263 = (v12639 * 2) + 1;
        v12645[v13263] = v12642;
        ;
      } else {
        ;
      }
      int * v12650 = v12471->mem;
      int v13268 = ((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) * 2;
      int v12651 = v12650[v13268];
      int v13269 = (((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) * 2) + 1;
      int v12652 = v12650[v13269];
      int * v12653 = v12471->cache_vals;
      int v13271 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v12631 + ((~(((v12633 ^ -1) | (-(v12633 ^ -1))) >> 31)) & 2)) - (v12634 + ((~(((v12635 ^ -1) | (-(v12635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12653[v13271] = v12651;
      int * v12655 = v12471->cache_vals;
      int v13274 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v12631 + ((~(((v12633 ^ -1) | (-(v12633 ^ -1))) >> 31)) & 2)) - (v12634 + ((~(((v12635 ^ -1) | (-(v12635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12655[v13274] = v12652;
      int * v12657 = v12471->cache_tags;
      int v13277 = (int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1);
      v12657[v13253] = v13277;
      int * v12659 = v12471->cache_dirty;
      v12659[v13253] = 0;
      int * v12661 = v12471->cache_age;
      v12661[v13253] = 1;
      int * v12663 = v12471->cache_age;
      int v12664 = v12663[v13253];
      int v12665 = v12663[v13227];
      int v13283 = v12665 + ((int)((unsigned int)(v12665 - v12664) >> 31));
      v12663[v13227] = v13283;
      int * v12667 = v12471->cache_age;
      int v12668 = v12667[v13228];
      int v13285 = v12668 + ((int)((unsigned int)(v12668 - v12664) >> 31));
      v12667[v13228] = v13285;
      int * v12670 = v12471->cache_age;
      v12670[v13253] = 0;
      v12673 = v13253;
    }
    int * v12674 = v12471->cache_vals;
    int v13288 = v12673 * 2;
    int v12675 = v12674[v13288];
    int v13289 = (v12673 * 2) + 1;
    int v12676 = v12674[v13289];
    int v13290 = (((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v12615 + ((~(((v12617 ^ -1) | (-(v12617 ^ -1))) >> 31)) & 2)) - (v12618 + ((~(((v12619 ^ -1) | (-(v12619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12674[v13290] = v12675;
    int * v12678 = v12471->cache_vals;
    int v13293 = ((((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v12615 + ((~(((v12617 ^ -1) | (-(v12617 ^ -1))) >> 31)) & 2)) - (v12618 + ((~(((v12619 ^ -1) | (-(v12619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12678[v13293] = v12676;
    int * v12680 = v12471->cache_tags;
    int v13296 = ((((int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v12615 + ((~(((v12617 ^ -1) | (-(v12617 ^ -1))) >> 31)) & 2)) - (v12618 + ((~(((v12619 ^ -1) | (-(v12619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13297 = (int)((unsigned int)((int)((unsigned int)(v12595 + 8) >> 2)) >> 1);
    v12680[v13296] = v13297;
    int * v12682 = v12471->cache_dirty;
    v12682[v13296] = 0;
    int * v12684 = v12471->cache_age;
    v12684[v13296] = 1;
    int * v12686 = v12471->cache_age;
    int v12687 = v12686[v13296];
    int v12688 = v12686[v13225];
    int v13303 = v12688 + ((int)((unsigned int)(v12688 - v12687) >> 31));
    v12686[v13225] = v13303;
    int * v12690 = v12471->cache_age;
    int v12691 = v12690[v13226];
    int v13305 = v12691 + ((int)((unsigned int)(v12691 - v12687) >> 31));
    v12690[v13226] = v13305;
    int * v12693 = v12471->cache_age;
    v12693[v13296] = 0;
    v12696 = v13296;
  }
  int v13308 = (v12696 * 2) + (((int)((unsigned int)(v12595 + 8) >> 2)) & 1);
  int v12697 = v12603[v13308];
  int * v12698 = v12471->regs;
  v12698[9] = v12697;
  int * v12700 = v12471->saved_regs;
  int * v12701 = v12471->regs;
  int v12702 = v12701[18];
  v12700[18] = v12702;
  int v12704 = v12471->timer;
  int v13315 = v12704 + 1;
  v12471->timer = v13315;
  int * v12706 = v12471->regs;
  int v12707 = v12706[2];
  bool v13317 = (((int)((unsigned int)(v12475 + 36) >> 2)) & 3) == (((int)((unsigned int)(v12707 + 4) >> 2)) & 3);
  int v12814;
  if (v13317) {
    int v12708 = v12471->timer;
    int v13318 = v12708 + 1;
    v12471->timer = v13318;
    v12814 = v12476;
  } else {
    int * v12711 = v12471->cache_tags;
    int v13321 = (((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2;
    int v12712 = v12711[v13321];
    int v13322 = ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
    int v12713 = v12711[v13322];
    int v13323 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2);
    int v12714 = v12711[v13323];
    int v13324 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v12715 = v12711[v13324];
    int v12716 = v12471->timer;
    int v13325 = v12716 + ((100 ^ (((~(((v12714 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12714 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12714 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12714 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
    v12471->timer = v13325;
    int * v12718 = v12471->cache_vals;
    bool v13326 = !(((~(((v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12712 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v12811;
    if (v13326) {
      int * v12719 = v12471->cache_age;
      int v13328 = ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12713 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v12720 = v12719[v13328];
      int v12721 = v12719[v13321];
      int v13329 = v12721 + ((int)((unsigned int)(v12721 - v12720) >> 31));
      v12719[v13321] = v13329;
      int * v12723 = v12471->cache_age;
      int v12724 = v12723[v13322];
      int v13331 = v12724 + ((int)((unsigned int)(v12724 - v12720) >> 31));
      v12723[v13322] = v13331;
      int * v12726 = v12471->cache_age;
      v12726[v13328] = 0;
      v12811 = v13328;
    } else {
      int * v12729 = v12471->cache_age;
      int v13335 = (((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2;
      int v12730 = v12729[v13335];
      int * v12731 = v12471->cache_tags;
      int v12732 = v12731[v13335];
      int v12733 = v12729[v13322];
      int v12734 = v12731[v13322];
      bool v13337 = !(((~(((v12714 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12714 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31))) == 0);
      int v12788;
      if (v13337) {
        int * v12735 = v12471->cache_age;
        int v13339 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))) | (-(v12715 ^ ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1))))) >> 31)) & 1);
        int v12736 = v12735[v13339];
        int v12737 = v12735[v13323];
        int v13340 = v12737 + ((int)((unsigned int)(v12737 - v12736) >> 31));
        v12735[v13323] = v13340;
        int * v12739 = v12471->cache_age;
        int v12740 = v12739[v13324];
        int v13342 = v12740 + ((int)((unsigned int)(v12740 - v12736) >> 31));
        v12739[v13324] = v13342;
        int * v12742 = v12471->cache_age;
        v12742[v13339] = 0;
        v12788 = v13339;
      } else {
        int * v12745 = v12471->cache_age;
        int v13346 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2);
        int v12746 = v12745[v13346];
        int * v12747 = v12471->cache_tags;
        int v12748 = v12747[v13346];
        int v12749 = v12745[v13324];
        int v12750 = v12747[v13324];
        int * v12751 = v12471->cache_dirty;
        int v13349 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12746 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2)) - (v12749 + ((~(((v12750 ^ -1) | (-(v12750 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v12752 = v12751[v13349];
        bool v13350 = !(v12752 == 0);
        if (v13350) {
          int * v12753 = v12471->cache_tags;
          int v12754 = v12753[v13349];
          int * v12755 = v12471->cache_vals;
          int v13353 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12746 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2)) - (v12749 + ((~(((v12750 ^ -1) | (-(v12750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v12756 = v12755[v13353];
          int v13354 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12746 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2)) - (v12749 + ((~(((v12750 ^ -1) | (-(v12750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v12757 = v12755[v13354];
          int * v12758 = v12471->mem;
          int v13356 = v12754 * 2;
          v12758[v13356] = v12756;
          int * v12760 = v12471->mem;
          int v13359 = (v12754 * 2) + 1;
          v12760[v13359] = v12757;
          ;
        } else {
          ;
        }
        int * v12765 = v12471->mem;
        int v13364 = ((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) * 2;
        int v12766 = v12765[v13364];
        int v13365 = (((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) * 2) + 1;
        int v12767 = v12765[v13365];
        int * v12768 = v12471->cache_vals;
        int v13367 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12746 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2)) - (v12749 + ((~(((v12750 ^ -1) | (-(v12750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v12768[v13367] = v12766;
        int * v12770 = v12471->cache_vals;
        int v13370 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12746 + ((~(((v12748 ^ -1) | (-(v12748 ^ -1))) >> 31)) & 2)) - (v12749 + ((~(((v12750 ^ -1) | (-(v12750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v12770[v13370] = v12767;
        int * v12772 = v12471->cache_tags;
        int v13373 = (int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1);
        v12772[v13349] = v13373;
        int * v12774 = v12471->cache_dirty;
        v12774[v13349] = 0;
        int * v12776 = v12471->cache_age;
        v12776[v13349] = 1;
        int * v12778 = v12471->cache_age;
        int v12779 = v12778[v13349];
        int v12780 = v12778[v13323];
        int v13379 = v12780 + ((int)((unsigned int)(v12780 - v12779) >> 31));
        v12778[v13323] = v13379;
        int * v12782 = v12471->cache_age;
        int v12783 = v12782[v13324];
        int v13381 = v12783 + ((int)((unsigned int)(v12783 - v12779) >> 31));
        v12782[v13324] = v13381;
        int * v12785 = v12471->cache_age;
        v12785[v13349] = 0;
        v12788 = v13349;
      }
      int * v12789 = v12471->cache_vals;
      int v13384 = v12788 * 2;
      int v12790 = v12789[v13384];
      int v13385 = (v12788 * 2) + 1;
      int v12791 = v12789[v13385];
      int v13386 = (((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v12730 + ((~(((v12732 ^ -1) | (-(v12732 ^ -1))) >> 31)) & 2)) - (v12733 + ((~(((v12734 ^ -1) | (-(v12734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12789[v13386] = v12790;
      int * v12793 = v12471->cache_vals;
      int v13389 = ((((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v12730 + ((~(((v12732 ^ -1) | (-(v12732 ^ -1))) >> 31)) & 2)) - (v12733 + ((~(((v12734 ^ -1) | (-(v12734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12793[v13389] = v12791;
      int * v12795 = v12471->cache_tags;
      int v13392 = ((((int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v12730 + ((~(((v12732 ^ -1) | (-(v12732 ^ -1))) >> 31)) & 2)) - (v12733 + ((~(((v12734 ^ -1) | (-(v12734 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13393 = (int)((unsigned int)((int)((unsigned int)(v12707 + 4) >> 2)) >> 1);
      v12795[v13392] = v13393;
      int * v12797 = v12471->cache_dirty;
      v12797[v13392] = 0;
      int * v12799 = v12471->cache_age;
      v12799[v13392] = 1;
      int * v12801 = v12471->cache_age;
      int v12802 = v12801[v13392];
      int v12803 = v12801[v13321];
      int v13399 = v12803 + ((int)((unsigned int)(v12803 - v12802) >> 31));
      v12801[v13321] = v13399;
      int * v12805 = v12471->cache_age;
      int v12806 = v12805[v13322];
      int v13401 = v12806 + ((int)((unsigned int)(v12806 - v12802) >> 31));
      v12805[v13322] = v13401;
      int * v12808 = v12471->cache_age;
      v12808[v13392] = 0;
      v12811 = v13392;
    }
    int v13404 = (v12811 * 2) + (((int)((unsigned int)(v12707 + 4) >> 2)) & 1);
    int v12812 = v12718[v13404];
    v12814 = v12812;
  }
  int * v12815 = v12471->regs;
  v12815[18] = v12814;
  int * v12817 = v12471->saved_regs;
  int * v12818 = v12471->regs;
  int v12819 = v12818[19];
  v12817[19] = v12819;
  int v12821 = v12471->timer;
  int v13412 = v12821 + 1;
  v12471->timer = v13412;
  int * v12823 = v12471->regs;
  int v12824 = v12823[2];
  bool v13414 = (((int)((unsigned int)(v12475 + 36) >> 2)) & 3) == (((int)((unsigned int)v12824 >> 2)) & 3);
  int v12931;
  if (v13414) {
    int v12825 = v12471->timer;
    int v13415 = v12825 + 1;
    v12471->timer = v13415;
    v12931 = v12476;
  } else {
    int * v12828 = v12471->cache_tags;
    int v13418 = (((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2;
    int v12829 = v12828[v13418];
    int v13419 = ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2) + 1;
    int v12830 = v12828[v13419];
    int v13420 = 4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2);
    int v12831 = v12828[v13420];
    int v13421 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v12832 = v12828[v13421];
    int v12833 = v12471->timer;
    int v13422 = v12833 + ((100 ^ (((~(((v12831 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12831 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) | (~(((v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12829 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12829 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) | (~(((v12830 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12830 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12831 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12831 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) | (~(((v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31))) & 104)))));
    v12471->timer = v13422;
    int * v12835 = v12471->cache_vals;
    bool v13423 = !(((~(((v12829 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12829 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) | (~(((v12830 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12830 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31))) == 0);
    int v12928;
    if (v13423) {
      int * v12836 = v12471->cache_age;
      int v13425 = ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2) + ((~(((v12830 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12830 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) & 1);
      int v12837 = v12836[v13425];
      int v12838 = v12836[v13418];
      int v13426 = v12838 + ((int)((unsigned int)(v12838 - v12837) >> 31));
      v12836[v13418] = v13426;
      int * v12840 = v12471->cache_age;
      int v12841 = v12840[v13419];
      int v13428 = v12841 + ((int)((unsigned int)(v12841 - v12837) >> 31));
      v12840[v13419] = v13428;
      int * v12843 = v12471->cache_age;
      v12843[v13425] = 0;
      v12928 = v13425;
    } else {
      int * v12846 = v12471->cache_age;
      int v13432 = (((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2;
      int v12847 = v12846[v13432];
      int * v12848 = v12471->cache_tags;
      int v12849 = v12848[v13432];
      int v12850 = v12846[v13419];
      int v12851 = v12848[v13419];
      bool v13434 = !(((~(((v12831 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12831 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) | (~(((v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31))) == 0);
      int v12905;
      if (v13434) {
        int * v12852 = v12471->cache_age;
        int v13436 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + ((~(((v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))) | (-(v12832 ^ ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1))))) >> 31)) & 1);
        int v12853 = v12852[v13436];
        int v12854 = v12852[v13420];
        int v13437 = v12854 + ((int)((unsigned int)(v12854 - v12853) >> 31));
        v12852[v13420] = v13437;
        int * v12856 = v12471->cache_age;
        int v12857 = v12856[v13421];
        int v13439 = v12857 + ((int)((unsigned int)(v12857 - v12853) >> 31));
        v12856[v13421] = v13439;
        int * v12859 = v12471->cache_age;
        v12859[v13436] = 0;
        v12905 = v13436;
      } else {
        int * v12862 = v12471->cache_age;
        int v13443 = 4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2);
        int v12863 = v12862[v13443];
        int * v12864 = v12471->cache_tags;
        int v12865 = v12864[v13443];
        int v12866 = v12862[v13421];
        int v12867 = v12864[v13421];
        int * v12868 = v12471->cache_dirty;
        int v13446 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + ((((v12863 + ((~(((v12865 ^ -1) | (-(v12865 ^ -1))) >> 31)) & 2)) - (v12866 + ((~(((v12867 ^ -1) | (-(v12867 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v12869 = v12868[v13446];
        bool v13447 = !(v12869 == 0);
        if (v13447) {
          int * v12870 = v12471->cache_tags;
          int v12871 = v12870[v13446];
          int * v12872 = v12471->cache_vals;
          int v13450 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + ((((v12863 + ((~(((v12865 ^ -1) | (-(v12865 ^ -1))) >> 31)) & 2)) - (v12866 + ((~(((v12867 ^ -1) | (-(v12867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v12873 = v12872[v13450];
          int v13451 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + ((((v12863 + ((~(((v12865 ^ -1) | (-(v12865 ^ -1))) >> 31)) & 2)) - (v12866 + ((~(((v12867 ^ -1) | (-(v12867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v12874 = v12872[v13451];
          int * v12875 = v12471->mem;
          int v13453 = v12871 * 2;
          v12875[v13453] = v12873;
          int * v12877 = v12471->mem;
          int v13456 = (v12871 * 2) + 1;
          v12877[v13456] = v12874;
          ;
        } else {
          ;
        }
        int * v12882 = v12471->mem;
        int v13461 = ((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) * 2;
        int v12883 = v12882[v13461];
        int v13462 = (((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) * 2) + 1;
        int v12884 = v12882[v13462];
        int * v12885 = v12471->cache_vals;
        int v13464 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + ((((v12863 + ((~(((v12865 ^ -1) | (-(v12865 ^ -1))) >> 31)) & 2)) - (v12866 + ((~(((v12867 ^ -1) | (-(v12867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v12885[v13464] = v12883;
        int * v12887 = v12471->cache_vals;
        int v13467 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 3) * 2)) + ((((v12863 + ((~(((v12865 ^ -1) | (-(v12865 ^ -1))) >> 31)) & 2)) - (v12866 + ((~(((v12867 ^ -1) | (-(v12867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v12887[v13467] = v12884;
        int * v12889 = v12471->cache_tags;
        int v13470 = (int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1);
        v12889[v13446] = v13470;
        int * v12891 = v12471->cache_dirty;
        v12891[v13446] = 0;
        int * v12893 = v12471->cache_age;
        v12893[v13446] = 1;
        int * v12895 = v12471->cache_age;
        int v12896 = v12895[v13446];
        int v12897 = v12895[v13420];
        int v13476 = v12897 + ((int)((unsigned int)(v12897 - v12896) >> 31));
        v12895[v13420] = v13476;
        int * v12899 = v12471->cache_age;
        int v12900 = v12899[v13421];
        int v13478 = v12900 + ((int)((unsigned int)(v12900 - v12896) >> 31));
        v12899[v13421] = v13478;
        int * v12902 = v12471->cache_age;
        v12902[v13446] = 0;
        v12905 = v13446;
      }
      int * v12906 = v12471->cache_vals;
      int v13481 = v12905 * 2;
      int v12907 = v12906[v13481];
      int v13482 = (v12905 * 2) + 1;
      int v12908 = v12906[v13482];
      int v13483 = (((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2) + ((((v12847 + ((~(((v12849 ^ -1) | (-(v12849 ^ -1))) >> 31)) & 2)) - (v12850 + ((~(((v12851 ^ -1) | (-(v12851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12906[v13483] = v12907;
      int * v12910 = v12471->cache_vals;
      int v13486 = ((((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2) + ((((v12847 + ((~(((v12849 ^ -1) | (-(v12849 ^ -1))) >> 31)) & 2)) - (v12850 + ((~(((v12851 ^ -1) | (-(v12851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12910[v13486] = v12908;
      int * v12912 = v12471->cache_tags;
      int v13489 = ((((int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1)) & 1) * 2) + ((((v12847 + ((~(((v12849 ^ -1) | (-(v12849 ^ -1))) >> 31)) & 2)) - (v12850 + ((~(((v12851 ^ -1) | (-(v12851 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13490 = (int)((unsigned int)((int)((unsigned int)v12824 >> 2)) >> 1);
      v12912[v13489] = v13490;
      int * v12914 = v12471->cache_dirty;
      v12914[v13489] = 0;
      int * v12916 = v12471->cache_age;
      v12916[v13489] = 1;
      int * v12918 = v12471->cache_age;
      int v12919 = v12918[v13489];
      int v12920 = v12918[v13418];
      int v13496 = v12920 + ((int)((unsigned int)(v12920 - v12919) >> 31));
      v12918[v13418] = v13496;
      int * v12922 = v12471->cache_age;
      int v12923 = v12922[v13419];
      int v13498 = v12923 + ((int)((unsigned int)(v12923 - v12919) >> 31));
      v12922[v13419] = v13498;
      int * v12925 = v12471->cache_age;
      v12925[v13489] = 0;
      v12928 = v13489;
    }
    int v13501 = (v12928 * 2) + (((int)((unsigned int)v12824 >> 2)) & 1);
    int v12929 = v12835[v13501];
    v12931 = v12929;
  }
  int * v12932 = v12471->regs;
  v12932[19] = v12931;
  int * v12934 = v12471->cache_tags;
  int v13506 = (((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2;
  int v12935 = v12934[v13506];
  int v13507 = ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12936 = v12934[v13507];
  int v13508 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2);
  int v12937 = v12934[v13508];
  int v13509 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12938 = v12934[v13509];
  int v12939 = v12471->timer;
  int v13510 = v12939 + ((100 ^ (((~(((v12937 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12937 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12935 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12935 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v12936 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12936 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12937 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12937 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12471->timer = v13510;
  bool v13511 = !(((~(((v12935 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12935 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v12936 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12936 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v13033;
  if (v13511) {
    int * v12941 = v12471->cache_age;
    int v13513 = ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v12936 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12936 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v12942 = v12941[v13513];
    int v12943 = v12941[v13506];
    int v13514 = v12943 + ((int)((unsigned int)(v12943 - v12942) >> 31));
    v12941[v13506] = v13514;
    int * v12945 = v12471->cache_age;
    int v12946 = v12945[v13507];
    int v13516 = v12946 + ((int)((unsigned int)(v12946 - v12942) >> 31));
    v12945[v13507] = v13516;
    int * v12948 = v12471->cache_age;
    v12948[v13513] = 0;
    v13033 = v13513;
  } else {
    int * v12951 = v12471->cache_age;
    int v13520 = (((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2;
    int v12952 = v12951[v13520];
    int * v12953 = v12471->cache_tags;
    int v12954 = v12953[v13520];
    int v12955 = v12951[v13507];
    int v12956 = v12953[v13507];
    bool v13522 = !(((~(((v12937 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12937 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v13010;
    if (v13522) {
      int * v12957 = v12471->cache_age;
      int v13524 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v12938 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v12958 = v12957[v13524];
      int v12959 = v12957[v13508];
      int v13525 = v12959 + ((int)((unsigned int)(v12959 - v12958) >> 31));
      v12957[v13508] = v13525;
      int * v12961 = v12471->cache_age;
      int v12962 = v12961[v13509];
      int v13527 = v12962 + ((int)((unsigned int)(v12962 - v12958) >> 31));
      v12961[v13509] = v13527;
      int * v12964 = v12471->cache_age;
      v12964[v13524] = 0;
      v13010 = v13524;
    } else {
      int * v12967 = v12471->cache_age;
      int v13531 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2);
      int v12968 = v12967[v13531];
      int * v12969 = v12471->cache_tags;
      int v12970 = v12969[v13531];
      int v12971 = v12967[v13509];
      int v12972 = v12969[v13509];
      int * v12973 = v12471->cache_dirty;
      int v13534 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v12968 + ((~(((v12970 ^ -1) | (-(v12970 ^ -1))) >> 31)) & 2)) - (v12971 + ((~(((v12972 ^ -1) | (-(v12972 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12974 = v12973[v13534];
      bool v13535 = !(v12974 == 0);
      if (v13535) {
        int * v12975 = v12471->cache_tags;
        int v12976 = v12975[v13534];
        int * v12977 = v12471->cache_vals;
        int v13538 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v12968 + ((~(((v12970 ^ -1) | (-(v12970 ^ -1))) >> 31)) & 2)) - (v12971 + ((~(((v12972 ^ -1) | (-(v12972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12978 = v12977[v13538];
        int v13539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v12968 + ((~(((v12970 ^ -1) | (-(v12970 ^ -1))) >> 31)) & 2)) - (v12971 + ((~(((v12972 ^ -1) | (-(v12972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12979 = v12977[v13539];
        int * v12980 = v12471->mem;
        int v13541 = v12976 * 2;
        v12980[v13541] = v12978;
        int * v12982 = v12471->mem;
        int v13544 = (v12976 * 2) + 1;
        v12982[v13544] = v12979;
        ;
      } else {
        ;
      }
      int * v12987 = v12471->mem;
      int v13549 = ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) * 2;
      int v12988 = v12987[v13549];
      int v13550 = (((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) * 2) + 1;
      int v12989 = v12987[v13550];
      int * v12990 = v12471->cache_vals;
      int v13552 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v12968 + ((~(((v12970 ^ -1) | (-(v12970 ^ -1))) >> 31)) & 2)) - (v12971 + ((~(((v12972 ^ -1) | (-(v12972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12990[v13552] = v12988;
      int * v12992 = v12471->cache_vals;
      int v13555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v12968 + ((~(((v12970 ^ -1) | (-(v12970 ^ -1))) >> 31)) & 2)) - (v12971 + ((~(((v12972 ^ -1) | (-(v12972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12992[v13555] = v12989;
      int * v12994 = v12471->cache_tags;
      int v13558 = (int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1);
      v12994[v13534] = v13558;
      int * v12996 = v12471->cache_dirty;
      v12996[v13534] = 0;
      int * v12998 = v12471->cache_age;
      v12998[v13534] = 1;
      int * v13000 = v12471->cache_age;
      int v13001 = v13000[v13534];
      int v13002 = v13000[v13508];
      int v13564 = v13002 + ((int)((unsigned int)(v13002 - v13001) >> 31));
      v13000[v13508] = v13564;
      int * v13004 = v12471->cache_age;
      int v13005 = v13004[v13509];
      int v13566 = v13005 + ((int)((unsigned int)(v13005 - v13001) >> 31));
      v13004[v13509] = v13566;
      int * v13007 = v12471->cache_age;
      v13007[v13534] = 0;
      v13010 = v13534;
    }
    int * v13011 = v12471->cache_vals;
    int v13569 = v13010 * 2;
    int v13012 = v13011[v13569];
    int v13570 = (v13010 * 2) + 1;
    int v13013 = v13011[v13570];
    int v13571 = (((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v12952 + ((~(((v12954 ^ -1) | (-(v12954 ^ -1))) >> 31)) & 2)) - (v12955 + ((~(((v12956 ^ -1) | (-(v12956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13011[v13571] = v13012;
    int * v13015 = v12471->cache_vals;
    int v13574 = ((((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v12952 + ((~(((v12954 ^ -1) | (-(v12954 ^ -1))) >> 31)) & 2)) - (v12955 + ((~(((v12956 ^ -1) | (-(v12956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13015[v13574] = v13013;
    int * v13017 = v12471->cache_tags;
    int v13577 = ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v12952 + ((~(((v12954 ^ -1) | (-(v12954 ^ -1))) >> 31)) & 2)) - (v12955 + ((~(((v12956 ^ -1) | (-(v12956 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13578 = (int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1);
    v13017[v13577] = v13578;
    int * v13019 = v12471->cache_dirty;
    v13019[v13577] = 0;
    int * v13021 = v12471->cache_age;
    v13021[v13577] = 1;
    int * v13023 = v12471->cache_age;
    int v13024 = v13023[v13577];
    int v13025 = v13023[v13506];
    int v13584 = v13025 + ((int)((unsigned int)(v13025 - v13024) >> 31));
    v13023[v13506] = v13584;
    int * v13027 = v12471->cache_age;
    int v13028 = v13027[v13507];
    int v13586 = v13028 + ((int)((unsigned int)(v13028 - v13024) >> 31));
    v13027[v13507] = v13586;
    int * v13030 = v12471->cache_age;
    v13030[v13577] = 0;
    v13033 = v13577;
  }
  int * v13034 = v12471->cache_vals;
  int v13589 = (v13033 * 2) + (((int)((unsigned int)(v12475 + 36) >> 2)) & 1);
  v13034[v13589] = v12476;
  int * v13036 = v12471->cache_tags;
  int v13037 = v13036[v13508];
  int v13038 = v13036[v13509];
  bool v13592 = !(((~(((v13037 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v13037 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v13038 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v13038 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v13092;
  if (v13592) {
    int * v13039 = v12471->cache_age;
    int v13594 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13038 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))) | (-(v13038 ^ ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v13040 = v13039[v13594];
    int v13041 = v13039[v13508];
    int v13595 = v13041 + ((int)((unsigned int)(v13041 - v13040) >> 31));
    v13039[v13508] = v13595;
    int * v13043 = v12471->cache_age;
    int v13044 = v13043[v13509];
    int v13597 = v13044 + ((int)((unsigned int)(v13044 - v13040) >> 31));
    v13043[v13509] = v13597;
    int * v13046 = v12471->cache_age;
    v13046[v13594] = 0;
    v13092 = v13594;
  } else {
    int * v13049 = v12471->cache_age;
    int v13601 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2);
    int v13050 = v13049[v13601];
    int * v13051 = v12471->cache_tags;
    int v13052 = v13051[v13601];
    int v13053 = v13049[v13509];
    int v13054 = v13051[v13509];
    int * v13055 = v12471->cache_dirty;
    int v13604 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13050 + ((~(((v13052 ^ -1) | (-(v13052 ^ -1))) >> 31)) & 2)) - (v13053 + ((~(((v13054 ^ -1) | (-(v13054 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13056 = v13055[v13604];
    bool v13605 = !(v13056 == 0);
    if (v13605) {
      int * v13057 = v12471->cache_tags;
      int v13058 = v13057[v13604];
      int * v13059 = v12471->cache_vals;
      int v13608 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13050 + ((~(((v13052 ^ -1) | (-(v13052 ^ -1))) >> 31)) & 2)) - (v13053 + ((~(((v13054 ^ -1) | (-(v13054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v13060 = v13059[v13608];
      int v13609 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13050 + ((~(((v13052 ^ -1) | (-(v13052 ^ -1))) >> 31)) & 2)) - (v13053 + ((~(((v13054 ^ -1) | (-(v13054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v13061 = v13059[v13609];
      int * v13062 = v12471->mem;
      int v13611 = v13058 * 2;
      v13062[v13611] = v13060;
      int * v13064 = v12471->mem;
      int v13614 = (v13058 * 2) + 1;
      v13064[v13614] = v13061;
      ;
    } else {
      ;
    }
    int * v13069 = v12471->mem;
    int v13619 = ((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) * 2;
    int v13070 = v13069[v13619];
    int v13620 = (((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) * 2) + 1;
    int v13071 = v13069[v13620];
    int * v13072 = v12471->cache_vals;
    int v13622 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13050 + ((~(((v13052 ^ -1) | (-(v13052 ^ -1))) >> 31)) & 2)) - (v13053 + ((~(((v13054 ^ -1) | (-(v13054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13072[v13622] = v13070;
    int * v13074 = v12471->cache_vals;
    int v13625 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13050 + ((~(((v13052 ^ -1) | (-(v13052 ^ -1))) >> 31)) & 2)) - (v13053 + ((~(((v13054 ^ -1) | (-(v13054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13074[v13625] = v13071;
    int * v13076 = v12471->cache_tags;
    int v13628 = (int)((unsigned int)((int)((unsigned int)(v12475 + 36) >> 2)) >> 1);
    v13076[v13604] = v13628;
    int * v13078 = v12471->cache_dirty;
    v13078[v13604] = 0;
    int * v13080 = v12471->cache_age;
    v13080[v13604] = 1;
    int * v13082 = v12471->cache_age;
    int v13083 = v13082[v13604];
    int v13084 = v13082[v13508];
    int v13634 = v13084 + ((int)((unsigned int)(v13084 - v13083) >> 31));
    v13082[v13508] = v13634;
    int * v13086 = v12471->cache_age;
    int v13087 = v13086[v13509];
    int v13636 = v13087 + ((int)((unsigned int)(v13087 - v13083) >> 31));
    v13086[v13509] = v13636;
    int * v13089 = v12471->cache_age;
    v13089[v13604] = 0;
    v13092 = v13604;
  }
  int * v13093 = v12471->cache_vals;
  int v13639 = (v13092 * 2) + (((int)((unsigned int)(v12475 + 36) >> 2)) & 1);
  v13093[v13639] = v12476;
  int * v13095 = v12471->cache_dirty;
  v13095[v13092] = 1;
  bool v13643 = (((((int)((unsigned int)(v12483 + 12) >> 2)) == ((int)((unsigned int)(v12475 + 36) >> 2))) | (((int)((unsigned int)(v12595 + 8) >> 2)) == ((int)((unsigned int)(v12475 + 36) >> 2)))) | (((((int)((unsigned int)(v12707 + 4) >> 2)) & 3) == (((int)((unsigned int)(v12475 + 36) >> 2)) & 3)) & (!(((int)((unsigned int)(v12707 + 4) >> 2)) == ((int)((unsigned int)(v12475 + 36) >> 2)))))) | (((((int)((unsigned int)v12824 >> 2)) & 3) == (((int)((unsigned int)(v12475 + 36) >> 2)) & 3)) & (!(((int)((unsigned int)v12824 >> 2)) == ((int)((unsigned int)(v12475 + 36) >> 2)))));
  struct StateT * v13119;
  if (v13643) {
    int v13097 = v12471->timer;
    int v13644 = v13097 + 15;
    v12471->timer = v13644;
    int * v13099 = v12471->saved_regs;
    int v13100 = v13099[8];
    int * v13101 = v12471->regs;
    v13101[8] = v13100;
    int * v13103 = v12471->saved_regs;
    int v13104 = v13103[9];
    int * v13105 = v12471->regs;
    v13105[9] = v13104;
    int * v13107 = v12471->saved_regs;
    int v13108 = v13107[18];
    int * v13109 = v12471->regs;
    v13109[18] = v13108;
    int * v13111 = v12471->saved_regs;
    int v13112 = v13111[19];
    int * v13113 = v12471->regs;
    v13113[19] = v13112;
    struct StateT * v13115 = slot_230(v12471);
    v13119 = v13115;
  } else {
    struct StateT * v13117 = slot_234(v12471);
    v13119 = v13117;
  }
  return v13119;
}

struct StateT * slot_143(struct StateT * v8657) {
  int v8658 = v8657->timer;
  int v8666 = v8658 + 1;
  v8657->timer = v8666;
  int * v8660 = v8657->regs;
  int v8661 = v8660[30];
  int v8662 = v8660[7];
  int v8670 = v8661 + v8662;
  v8660[7] = v8670;
  struct StateT * v8664 = slot_144(v8657);
  return v8664;
}

struct StateT * slot_120(struct StateT * v7885) {
  int v7886 = v7885->timer;
  int v7893 = v7886 + 1;
  v7885->timer = v7893;
  int * v7888 = v7885->regs;
  int v7889 = v7888[7];
  int v7896 = (int)((unsigned int)v7889 >> 19);
  v7888[7] = v7896;
  struct StateT * v7891 = slot_126(v7885);
  return v7891;
}

struct StateT * slot_226(struct StateT * v12132) {
  int v12133 = v12132->timer;
  int v12303 = v12133 + 1;
  v12132->timer = v12303;
  int * v12135 = v12132->regs;
  int v12136 = v12135[10];
  int v12137 = v12135[11];
  int * v12138 = v12132->cache_tags;
  int v12308 = (((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2;
  int v12139 = v12138[v12308];
  int v12309 = ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12140 = v12138[v12309];
  int v12310 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2);
  int v12141 = v12138[v12310];
  int v12311 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12142 = v12138[v12311];
  int v12143 = v12132->timer;
  int v12312 = v12143 + ((100 ^ (((~(((v12141 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12141 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12139 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12139 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v12140 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12140 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12141 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12141 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12132->timer = v12312;
  bool v12313 = !(((~(((v12139 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12139 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v12140 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12140 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v12237;
  if (v12313) {
    int * v12145 = v12132->cache_age;
    int v12315 = ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v12140 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12140 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v12146 = v12145[v12315];
    int v12147 = v12145[v12308];
    int v12316 = v12147 + ((int)((unsigned int)(v12147 - v12146) >> 31));
    v12145[v12308] = v12316;
    int * v12149 = v12132->cache_age;
    int v12150 = v12149[v12309];
    int v12318 = v12150 + ((int)((unsigned int)(v12150 - v12146) >> 31));
    v12149[v12309] = v12318;
    int * v12152 = v12132->cache_age;
    v12152[v12315] = 0;
    v12237 = v12315;
  } else {
    int * v12155 = v12132->cache_age;
    int v12322 = (((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2;
    int v12156 = v12155[v12322];
    int * v12157 = v12132->cache_tags;
    int v12158 = v12157[v12322];
    int v12159 = v12155[v12309];
    int v12160 = v12157[v12309];
    bool v12324 = !(((~(((v12141 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12141 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v12214;
    if (v12324) {
      int * v12161 = v12132->cache_age;
      int v12326 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12142 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v12162 = v12161[v12326];
      int v12163 = v12161[v12310];
      int v12327 = v12163 + ((int)((unsigned int)(v12163 - v12162) >> 31));
      v12161[v12310] = v12327;
      int * v12165 = v12132->cache_age;
      int v12166 = v12165[v12311];
      int v12329 = v12166 + ((int)((unsigned int)(v12166 - v12162) >> 31));
      v12165[v12311] = v12329;
      int * v12168 = v12132->cache_age;
      v12168[v12326] = 0;
      v12214 = v12326;
    } else {
      int * v12171 = v12132->cache_age;
      int v12333 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2);
      int v12172 = v12171[v12333];
      int * v12173 = v12132->cache_tags;
      int v12174 = v12173[v12333];
      int v12175 = v12171[v12311];
      int v12176 = v12173[v12311];
      int * v12177 = v12132->cache_dirty;
      int v12336 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12172 + ((~(((v12174 ^ -1) | (-(v12174 ^ -1))) >> 31)) & 2)) - (v12175 + ((~(((v12176 ^ -1) | (-(v12176 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12178 = v12177[v12336];
      bool v12337 = !(v12178 == 0);
      if (v12337) {
        int * v12179 = v12132->cache_tags;
        int v12180 = v12179[v12336];
        int * v12181 = v12132->cache_vals;
        int v12340 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12172 + ((~(((v12174 ^ -1) | (-(v12174 ^ -1))) >> 31)) & 2)) - (v12175 + ((~(((v12176 ^ -1) | (-(v12176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12182 = v12181[v12340];
        int v12341 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12172 + ((~(((v12174 ^ -1) | (-(v12174 ^ -1))) >> 31)) & 2)) - (v12175 + ((~(((v12176 ^ -1) | (-(v12176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12183 = v12181[v12341];
        int * v12184 = v12132->mem;
        int v12343 = v12180 * 2;
        v12184[v12343] = v12182;
        int * v12186 = v12132->mem;
        int v12346 = (v12180 * 2) + 1;
        v12186[v12346] = v12183;
        ;
      } else {
        ;
      }
      int * v12191 = v12132->mem;
      int v12351 = ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) * 2;
      int v12192 = v12191[v12351];
      int v12352 = (((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) * 2) + 1;
      int v12193 = v12191[v12352];
      int * v12194 = v12132->cache_vals;
      int v12354 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12172 + ((~(((v12174 ^ -1) | (-(v12174 ^ -1))) >> 31)) & 2)) - (v12175 + ((~(((v12176 ^ -1) | (-(v12176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12194[v12354] = v12192;
      int * v12196 = v12132->cache_vals;
      int v12357 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12172 + ((~(((v12174 ^ -1) | (-(v12174 ^ -1))) >> 31)) & 2)) - (v12175 + ((~(((v12176 ^ -1) | (-(v12176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12196[v12357] = v12193;
      int * v12198 = v12132->cache_tags;
      int v12360 = (int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1);
      v12198[v12336] = v12360;
      int * v12200 = v12132->cache_dirty;
      v12200[v12336] = 0;
      int * v12202 = v12132->cache_age;
      v12202[v12336] = 1;
      int * v12204 = v12132->cache_age;
      int v12205 = v12204[v12336];
      int v12206 = v12204[v12310];
      int v12366 = v12206 + ((int)((unsigned int)(v12206 - v12205) >> 31));
      v12204[v12310] = v12366;
      int * v12208 = v12132->cache_age;
      int v12209 = v12208[v12311];
      int v12368 = v12209 + ((int)((unsigned int)(v12209 - v12205) >> 31));
      v12208[v12311] = v12368;
      int * v12211 = v12132->cache_age;
      v12211[v12336] = 0;
      v12214 = v12336;
    }
    int * v12215 = v12132->cache_vals;
    int v12371 = v12214 * 2;
    int v12216 = v12215[v12371];
    int v12372 = (v12214 * 2) + 1;
    int v12217 = v12215[v12372];
    int v12373 = (((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v12156 + ((~(((v12158 ^ -1) | (-(v12158 ^ -1))) >> 31)) & 2)) - (v12159 + ((~(((v12160 ^ -1) | (-(v12160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12215[v12373] = v12216;
    int * v12219 = v12132->cache_vals;
    int v12376 = ((((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v12156 + ((~(((v12158 ^ -1) | (-(v12158 ^ -1))) >> 31)) & 2)) - (v12159 + ((~(((v12160 ^ -1) | (-(v12160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12219[v12376] = v12217;
    int * v12221 = v12132->cache_tags;
    int v12379 = ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v12156 + ((~(((v12158 ^ -1) | (-(v12158 ^ -1))) >> 31)) & 2)) - (v12159 + ((~(((v12160 ^ -1) | (-(v12160 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12380 = (int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1);
    v12221[v12379] = v12380;
    int * v12223 = v12132->cache_dirty;
    v12223[v12379] = 0;
    int * v12225 = v12132->cache_age;
    v12225[v12379] = 1;
    int * v12227 = v12132->cache_age;
    int v12228 = v12227[v12379];
    int v12229 = v12227[v12308];
    int v12386 = v12229 + ((int)((unsigned int)(v12229 - v12228) >> 31));
    v12227[v12308] = v12386;
    int * v12231 = v12132->cache_age;
    int v12232 = v12231[v12309];
    int v12388 = v12232 + ((int)((unsigned int)(v12232 - v12228) >> 31));
    v12231[v12309] = v12388;
    int * v12234 = v12132->cache_age;
    v12234[v12379] = 0;
    v12237 = v12379;
  }
  int * v12238 = v12132->cache_vals;
  int v12391 = (v12237 * 2) + (((int)((unsigned int)(v12136 + 32) >> 2)) & 1);
  v12238[v12391] = v12137;
  int * v12240 = v12132->cache_tags;
  int v12241 = v12240[v12310];
  int v12242 = v12240[v12311];
  bool v12394 = !(((~(((v12241 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12241 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v12242 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12242 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v12296;
  if (v12394) {
    int * v12243 = v12132->cache_age;
    int v12396 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12242 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))) | (-(v12242 ^ ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v12244 = v12243[v12396];
    int v12245 = v12243[v12310];
    int v12397 = v12245 + ((int)((unsigned int)(v12245 - v12244) >> 31));
    v12243[v12310] = v12397;
    int * v12247 = v12132->cache_age;
    int v12248 = v12247[v12311];
    int v12399 = v12248 + ((int)((unsigned int)(v12248 - v12244) >> 31));
    v12247[v12311] = v12399;
    int * v12250 = v12132->cache_age;
    v12250[v12396] = 0;
    v12296 = v12396;
  } else {
    int * v12253 = v12132->cache_age;
    int v12403 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2);
    int v12254 = v12253[v12403];
    int * v12255 = v12132->cache_tags;
    int v12256 = v12255[v12403];
    int v12257 = v12253[v12311];
    int v12258 = v12255[v12311];
    int * v12259 = v12132->cache_dirty;
    int v12406 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12254 + ((~(((v12256 ^ -1) | (-(v12256 ^ -1))) >> 31)) & 2)) - (v12257 + ((~(((v12258 ^ -1) | (-(v12258 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12260 = v12259[v12406];
    bool v12407 = !(v12260 == 0);
    if (v12407) {
      int * v12261 = v12132->cache_tags;
      int v12262 = v12261[v12406];
      int * v12263 = v12132->cache_vals;
      int v12410 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12254 + ((~(((v12256 ^ -1) | (-(v12256 ^ -1))) >> 31)) & 2)) - (v12257 + ((~(((v12258 ^ -1) | (-(v12258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12264 = v12263[v12410];
      int v12411 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12254 + ((~(((v12256 ^ -1) | (-(v12256 ^ -1))) >> 31)) & 2)) - (v12257 + ((~(((v12258 ^ -1) | (-(v12258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12265 = v12263[v12411];
      int * v12266 = v12132->mem;
      int v12413 = v12262 * 2;
      v12266[v12413] = v12264;
      int * v12268 = v12132->mem;
      int v12416 = (v12262 * 2) + 1;
      v12268[v12416] = v12265;
      ;
    } else {
      ;
    }
    int * v12273 = v12132->mem;
    int v12421 = ((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) * 2;
    int v12274 = v12273[v12421];
    int v12422 = (((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) * 2) + 1;
    int v12275 = v12273[v12422];
    int * v12276 = v12132->cache_vals;
    int v12424 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12254 + ((~(((v12256 ^ -1) | (-(v12256 ^ -1))) >> 31)) & 2)) - (v12257 + ((~(((v12258 ^ -1) | (-(v12258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12276[v12424] = v12274;
    int * v12278 = v12132->cache_vals;
    int v12427 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v12254 + ((~(((v12256 ^ -1) | (-(v12256 ^ -1))) >> 31)) & 2)) - (v12257 + ((~(((v12258 ^ -1) | (-(v12258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12278[v12427] = v12275;
    int * v12280 = v12132->cache_tags;
    int v12430 = (int)((unsigned int)((int)((unsigned int)(v12136 + 32) >> 2)) >> 1);
    v12280[v12406] = v12430;
    int * v12282 = v12132->cache_dirty;
    v12282[v12406] = 0;
    int * v12284 = v12132->cache_age;
    v12284[v12406] = 1;
    int * v12286 = v12132->cache_age;
    int v12287 = v12286[v12406];
    int v12288 = v12286[v12310];
    int v12436 = v12288 + ((int)((unsigned int)(v12288 - v12287) >> 31));
    v12286[v12310] = v12436;
    int * v12290 = v12132->cache_age;
    int v12291 = v12290[v12311];
    int v12438 = v12291 + ((int)((unsigned int)(v12291 - v12287) >> 31));
    v12290[v12311] = v12438;
    int * v12293 = v12132->cache_age;
    v12293[v12406] = 0;
    v12296 = v12406;
  }
  int * v12297 = v12132->cache_vals;
  int v12441 = (v12296 * 2) + (((int)((unsigned int)(v12136 + 32) >> 2)) & 1);
  v12297[v12441] = v12137;
  int * v12299 = v12132->cache_dirty;
  v12299[v12296] = 1;
  struct StateT * v12301 = slot_228(v12132);
  return v12301;
}

struct StateT * slot_167(struct StateT * v10266) {
  int v10267 = v10266->timer;
  int v10274 = v10267 + 1;
  v10266->timer = v10274;
  int * v10269 = v10266->regs;
  int v10270 = v10269[28];
  int v10277 = v10270 << 13;
  v10269[28] = v10277;
  struct StateT * v10272 = slot_168(v10266);
  return v10272;
}

struct StateT * slot_152(struct StateT * v8829) {
  int v8830 = v8829->timer;
  int v8838 = v8830 + 1;
  v8829->timer = v8838;
  int * v8832 = v8829->regs;
  int v8833 = v8832[30];
  int v8834 = v8832[28];
  int v8843 = v8833 + v8834;
  v8832[7] = v8843;
  struct StateT * v8836 = slot_153(v8829);
  return v8836;
}

struct StateT * slot_231(struct StateT * v13911) {
  int v13912 = v13911->timer;
  int v14022 = v13912 + 1;
  v13911->timer = v14022;
  int * v13914 = v13911->regs;
  int v13915 = v13914[2];
  int * v13916 = v13911->cache_tags;
  int v14026 = (((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2;
  int v13917 = v13916[v14026];
  int v14027 = ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13918 = v13916[v14027];
  int v14028 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2);
  int v13919 = v13916[v14028];
  int v14029 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13920 = v13916[v14029];
  int v13921 = v13911->timer;
  int v14030 = v13921 + ((100 ^ (((~(((v13919 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13919 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13917 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13917 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13918 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13918 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13919 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13919 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13911->timer = v14030;
  int * v13923 = v13911->cache_vals;
  bool v14031 = !(((~(((v13917 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13917 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13918 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13918 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v14016;
  if (v14031) {
    int * v13924 = v13911->cache_age;
    int v14033 = ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v13918 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13918 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v13925 = v13924[v14033];
    int v13926 = v13924[v14026];
    int v14034 = v13926 + ((int)((unsigned int)(v13926 - v13925) >> 31));
    v13924[v14026] = v14034;
    int * v13928 = v13911->cache_age;
    int v13929 = v13928[v14027];
    int v14036 = v13929 + ((int)((unsigned int)(v13929 - v13925) >> 31));
    v13928[v14027] = v14036;
    int * v13931 = v13911->cache_age;
    v13931[v14033] = 0;
    v14016 = v14033;
  } else {
    int * v13934 = v13911->cache_age;
    int v14040 = (((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2;
    int v13935 = v13934[v14040];
    int * v13936 = v13911->cache_tags;
    int v13937 = v13936[v14040];
    int v13938 = v13934[v14027];
    int v13939 = v13936[v14027];
    bool v14042 = !(((~(((v13919 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13919 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v13993;
    if (v14042) {
      int * v13940 = v13911->cache_age;
      int v14044 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))) | (-(v13920 ^ ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v13941 = v13940[v14044];
      int v13942 = v13940[v14028];
      int v14045 = v13942 + ((int)((unsigned int)(v13942 - v13941) >> 31));
      v13940[v14028] = v14045;
      int * v13944 = v13911->cache_age;
      int v13945 = v13944[v14029];
      int v14047 = v13945 + ((int)((unsigned int)(v13945 - v13941) >> 31));
      v13944[v14029] = v14047;
      int * v13947 = v13911->cache_age;
      v13947[v14044] = 0;
      v13993 = v14044;
    } else {
      int * v13950 = v13911->cache_age;
      int v14051 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2);
      int v13951 = v13950[v14051];
      int * v13952 = v13911->cache_tags;
      int v13953 = v13952[v14051];
      int v13954 = v13950[v14029];
      int v13955 = v13952[v14029];
      int * v13956 = v13911->cache_dirty;
      int v14054 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13951 + ((~(((v13953 ^ -1) | (-(v13953 ^ -1))) >> 31)) & 2)) - (v13954 + ((~(((v13955 ^ -1) | (-(v13955 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13957 = v13956[v14054];
      bool v14055 = !(v13957 == 0);
      if (v14055) {
        int * v13958 = v13911->cache_tags;
        int v13959 = v13958[v14054];
        int * v13960 = v13911->cache_vals;
        int v14058 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13951 + ((~(((v13953 ^ -1) | (-(v13953 ^ -1))) >> 31)) & 2)) - (v13954 + ((~(((v13955 ^ -1) | (-(v13955 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13961 = v13960[v14058];
        int v14059 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13951 + ((~(((v13953 ^ -1) | (-(v13953 ^ -1))) >> 31)) & 2)) - (v13954 + ((~(((v13955 ^ -1) | (-(v13955 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13962 = v13960[v14059];
        int * v13963 = v13911->mem;
        int v14061 = v13959 * 2;
        v13963[v14061] = v13961;
        int * v13965 = v13911->mem;
        int v14064 = (v13959 * 2) + 1;
        v13965[v14064] = v13962;
        ;
      } else {
        ;
      }
      int * v13970 = v13911->mem;
      int v14069 = ((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) * 2;
      int v13971 = v13970[v14069];
      int v14070 = (((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) * 2) + 1;
      int v13972 = v13970[v14070];
      int * v13973 = v13911->cache_vals;
      int v14072 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13951 + ((~(((v13953 ^ -1) | (-(v13953 ^ -1))) >> 31)) & 2)) - (v13954 + ((~(((v13955 ^ -1) | (-(v13955 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13973[v14072] = v13971;
      int * v13975 = v13911->cache_vals;
      int v14075 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13951 + ((~(((v13953 ^ -1) | (-(v13953 ^ -1))) >> 31)) & 2)) - (v13954 + ((~(((v13955 ^ -1) | (-(v13955 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13975[v14075] = v13972;
      int * v13977 = v13911->cache_tags;
      int v14078 = (int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1);
      v13977[v14054] = v14078;
      int * v13979 = v13911->cache_dirty;
      v13979[v14054] = 0;
      int * v13981 = v13911->cache_age;
      v13981[v14054] = 1;
      int * v13983 = v13911->cache_age;
      int v13984 = v13983[v14054];
      int v13985 = v13983[v14028];
      int v14084 = v13985 + ((int)((unsigned int)(v13985 - v13984) >> 31));
      v13983[v14028] = v14084;
      int * v13987 = v13911->cache_age;
      int v13988 = v13987[v14029];
      int v14086 = v13988 + ((int)((unsigned int)(v13988 - v13984) >> 31));
      v13987[v14029] = v14086;
      int * v13990 = v13911->cache_age;
      v13990[v14054] = 0;
      v13993 = v14054;
    }
    int * v13994 = v13911->cache_vals;
    int v14089 = v13993 * 2;
    int v13995 = v13994[v14089];
    int v14090 = (v13993 * 2) + 1;
    int v13996 = v13994[v14090];
    int v14091 = (((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v13935 + ((~(((v13937 ^ -1) | (-(v13937 ^ -1))) >> 31)) & 2)) - (v13938 + ((~(((v13939 ^ -1) | (-(v13939 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13994[v14091] = v13995;
    int * v13998 = v13911->cache_vals;
    int v14094 = ((((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v13935 + ((~(((v13937 ^ -1) | (-(v13937 ^ -1))) >> 31)) & 2)) - (v13938 + ((~(((v13939 ^ -1) | (-(v13939 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13998[v14094] = v13996;
    int * v14000 = v13911->cache_tags;
    int v14097 = ((((int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v13935 + ((~(((v13937 ^ -1) | (-(v13937 ^ -1))) >> 31)) & 2)) - (v13938 + ((~(((v13939 ^ -1) | (-(v13939 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14098 = (int)((unsigned int)((int)((unsigned int)(v13915 + 8) >> 2)) >> 1);
    v14000[v14097] = v14098;
    int * v14002 = v13911->cache_dirty;
    v14002[v14097] = 0;
    int * v14004 = v13911->cache_age;
    v14004[v14097] = 1;
    int * v14006 = v13911->cache_age;
    int v14007 = v14006[v14097];
    int v14008 = v14006[v14026];
    int v14104 = v14008 + ((int)((unsigned int)(v14008 - v14007) >> 31));
    v14006[v14026] = v14104;
    int * v14010 = v13911->cache_age;
    int v14011 = v14010[v14027];
    int v14106 = v14011 + ((int)((unsigned int)(v14011 - v14007) >> 31));
    v14010[v14027] = v14106;
    int * v14013 = v13911->cache_age;
    v14013[v14097] = 0;
    v14016 = v14097;
  }
  int v14109 = (v14016 * 2) + (((int)((unsigned int)(v13915 + 8) >> 2)) & 1);
  int v14017 = v13923[v14109];
  int * v14018 = v13911->regs;
  v14018[9] = v14017;
  struct StateT * v14020 = slot_232(v13911);
  return v14020;
}

struct StateT * slot_199(struct StateT * v10984) {
  int v10985 = v10984->timer;
  int v10989 = v10985 + 1;
  v10984->timer = v10989;
  struct StateT * v10987 = slot_200(v10984);
  return v10987;
}

struct StateT * slot_92(struct StateT * v6416) {
  int v6417 = v6416->timer;
  int v6425 = v6417 + 1;
  v6416->timer = v6425;
  int * v6419 = v6416->regs;
  int v6420 = v6419[6];
  int v6421 = v6419[12];
  int v6429 = v6420 * v6421;
  v6419[6] = v6429;
  struct StateT * v6423 = slot_93(v6416);
  return v6423;
}

struct StateT * slot_232(struct StateT * v14136) {
  int v14137 = v14136->timer;
  int v14247 = v14137 + 1;
  v14136->timer = v14247;
  int * v14139 = v14136->regs;
  int v14140 = v14139[2];
  int * v14141 = v14136->cache_tags;
  int v14251 = (((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2;
  int v14142 = v14141[v14251];
  int v14252 = ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14143 = v14141[v14252];
  int v14253 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2);
  int v14144 = v14141[v14253];
  int v14254 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14145 = v14141[v14254];
  int v14146 = v14136->timer;
  int v14255 = v14146 + ((100 ^ (((~(((v14144 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14144 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14142 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14142 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v14143 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14143 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14144 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14144 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14136->timer = v14255;
  int * v14148 = v14136->cache_vals;
  bool v14256 = !(((~(((v14142 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14142 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v14143 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14143 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v14241;
  if (v14256) {
    int * v14149 = v14136->cache_age;
    int v14258 = ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v14143 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14143 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v14150 = v14149[v14258];
    int v14151 = v14149[v14251];
    int v14259 = v14151 + ((int)((unsigned int)(v14151 - v14150) >> 31));
    v14149[v14251] = v14259;
    int * v14153 = v14136->cache_age;
    int v14154 = v14153[v14252];
    int v14261 = v14154 + ((int)((unsigned int)(v14154 - v14150) >> 31));
    v14153[v14252] = v14261;
    int * v14156 = v14136->cache_age;
    v14156[v14258] = 0;
    v14241 = v14258;
  } else {
    int * v14159 = v14136->cache_age;
    int v14265 = (((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2;
    int v14160 = v14159[v14265];
    int * v14161 = v14136->cache_tags;
    int v14162 = v14161[v14265];
    int v14163 = v14159[v14252];
    int v14164 = v14161[v14252];
    bool v14267 = !(((~(((v14144 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14144 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v14218;
    if (v14267) {
      int * v14165 = v14136->cache_age;
      int v14269 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))) | (-(v14145 ^ ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v14166 = v14165[v14269];
      int v14167 = v14165[v14253];
      int v14270 = v14167 + ((int)((unsigned int)(v14167 - v14166) >> 31));
      v14165[v14253] = v14270;
      int * v14169 = v14136->cache_age;
      int v14170 = v14169[v14254];
      int v14272 = v14170 + ((int)((unsigned int)(v14170 - v14166) >> 31));
      v14169[v14254] = v14272;
      int * v14172 = v14136->cache_age;
      v14172[v14269] = 0;
      v14218 = v14269;
    } else {
      int * v14175 = v14136->cache_age;
      int v14276 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2);
      int v14176 = v14175[v14276];
      int * v14177 = v14136->cache_tags;
      int v14178 = v14177[v14276];
      int v14179 = v14175[v14254];
      int v14180 = v14177[v14254];
      int * v14181 = v14136->cache_dirty;
      int v14279 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v14176 + ((~(((v14178 ^ -1) | (-(v14178 ^ -1))) >> 31)) & 2)) - (v14179 + ((~(((v14180 ^ -1) | (-(v14180 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14182 = v14181[v14279];
      bool v14280 = !(v14182 == 0);
      if (v14280) {
        int * v14183 = v14136->cache_tags;
        int v14184 = v14183[v14279];
        int * v14185 = v14136->cache_vals;
        int v14283 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v14176 + ((~(((v14178 ^ -1) | (-(v14178 ^ -1))) >> 31)) & 2)) - (v14179 + ((~(((v14180 ^ -1) | (-(v14180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14186 = v14185[v14283];
        int v14284 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v14176 + ((~(((v14178 ^ -1) | (-(v14178 ^ -1))) >> 31)) & 2)) - (v14179 + ((~(((v14180 ^ -1) | (-(v14180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14187 = v14185[v14284];
        int * v14188 = v14136->mem;
        int v14286 = v14184 * 2;
        v14188[v14286] = v14186;
        int * v14190 = v14136->mem;
        int v14289 = (v14184 * 2) + 1;
        v14190[v14289] = v14187;
        ;
      } else {
        ;
      }
      int * v14195 = v14136->mem;
      int v14294 = ((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) * 2;
      int v14196 = v14195[v14294];
      int v14295 = (((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) * 2) + 1;
      int v14197 = v14195[v14295];
      int * v14198 = v14136->cache_vals;
      int v14297 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v14176 + ((~(((v14178 ^ -1) | (-(v14178 ^ -1))) >> 31)) & 2)) - (v14179 + ((~(((v14180 ^ -1) | (-(v14180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14198[v14297] = v14196;
      int * v14200 = v14136->cache_vals;
      int v14300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v14176 + ((~(((v14178 ^ -1) | (-(v14178 ^ -1))) >> 31)) & 2)) - (v14179 + ((~(((v14180 ^ -1) | (-(v14180 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14200[v14300] = v14197;
      int * v14202 = v14136->cache_tags;
      int v14303 = (int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1);
      v14202[v14279] = v14303;
      int * v14204 = v14136->cache_dirty;
      v14204[v14279] = 0;
      int * v14206 = v14136->cache_age;
      v14206[v14279] = 1;
      int * v14208 = v14136->cache_age;
      int v14209 = v14208[v14279];
      int v14210 = v14208[v14253];
      int v14309 = v14210 + ((int)((unsigned int)(v14210 - v14209) >> 31));
      v14208[v14253] = v14309;
      int * v14212 = v14136->cache_age;
      int v14213 = v14212[v14254];
      int v14311 = v14213 + ((int)((unsigned int)(v14213 - v14209) >> 31));
      v14212[v14254] = v14311;
      int * v14215 = v14136->cache_age;
      v14215[v14279] = 0;
      v14218 = v14279;
    }
    int * v14219 = v14136->cache_vals;
    int v14314 = v14218 * 2;
    int v14220 = v14219[v14314];
    int v14315 = (v14218 * 2) + 1;
    int v14221 = v14219[v14315];
    int v14316 = (((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v14160 + ((~(((v14162 ^ -1) | (-(v14162 ^ -1))) >> 31)) & 2)) - (v14163 + ((~(((v14164 ^ -1) | (-(v14164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14219[v14316] = v14220;
    int * v14223 = v14136->cache_vals;
    int v14319 = ((((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v14160 + ((~(((v14162 ^ -1) | (-(v14162 ^ -1))) >> 31)) & 2)) - (v14163 + ((~(((v14164 ^ -1) | (-(v14164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14223[v14319] = v14221;
    int * v14225 = v14136->cache_tags;
    int v14322 = ((((int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v14160 + ((~(((v14162 ^ -1) | (-(v14162 ^ -1))) >> 31)) & 2)) - (v14163 + ((~(((v14164 ^ -1) | (-(v14164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14323 = (int)((unsigned int)((int)((unsigned int)(v14140 + 4) >> 2)) >> 1);
    v14225[v14322] = v14323;
    int * v14227 = v14136->cache_dirty;
    v14227[v14322] = 0;
    int * v14229 = v14136->cache_age;
    v14229[v14322] = 1;
    int * v14231 = v14136->cache_age;
    int v14232 = v14231[v14322];
    int v14233 = v14231[v14251];
    int v14329 = v14233 + ((int)((unsigned int)(v14233 - v14232) >> 31));
    v14231[v14251] = v14329;
    int * v14235 = v14136->cache_age;
    int v14236 = v14235[v14252];
    int v14331 = v14236 + ((int)((unsigned int)(v14236 - v14232) >> 31));
    v14235[v14252] = v14331;
    int * v14238 = v14136->cache_age;
    v14238[v14322] = 0;
    v14241 = v14322;
  }
  int v14334 = (v14241 * 2) + (((int)((unsigned int)(v14140 + 4) >> 2)) & 1);
  int v14242 = v14148[v14334];
  int * v14243 = v14136->regs;
  v14243[18] = v14242;
  struct StateT * v14245 = slot_233(v14136);
  return v14245;
}

struct StateT * slot_31(struct StateT * v3594) {
  int v3595 = v3594->timer;
  int v3607 = v3595 + 1;
  v3594->timer = v3607;
  int * v3597 = v3594->regs;
  int v3598 = v3597[5];
  int v3599 = v3597[6];
  bool v3611 = (v3598 ^ -2147483648) < (v3599 ^ -2147483648);
  int v3602;
  if (v3611) {
    v3602 = 1;
  } else {
    v3602 = 0;
  }
  int * v3603 = v3594->regs;
  v3603[5] = v3602;
  struct StateT * v3605 = slot_32(v3594);
  return v3605;
}

struct StateT * slot_236(struct StateT * v14115) {
  int v14116 = v14115->timer;
  int v14119 = v14116 + 1;
  v14115->timer = v14119;
  return v14115;
}

struct StateT * slot_241(struct StateT * v14571) {
  int v14572 = v14571->timer;
  int v14579 = v14572 + 1;
  v14571->timer = v14579;
  int * v14574 = v14571->regs;
  int v14575 = v14574[12];
  int v14582 = v14575 << 13;
  v14574[12] = v14582;
  struct StateT * v14577 = slot_242(v14571);
  return v14577;
}

struct StateT * slot_160(struct StateT * v8994) {
  int * v8995 = v8994->saved_regs;
  int v8996 = v8995[7];
  int v8997 = v8995[29];
  bool v9025 = v8996 == v8997;
  struct StateT * v9020;
  if (v9025) {
    int v8998 = v8994->timer;
    int v9026 = v8998 + 15;
    v8994->timer = v9026;
    int * v9000 = v8994->saved_regs;
    int v9001 = v9000[28];
    int * v9002 = v8994->regs;
    v9002[28] = v9001;
    int * v9004 = v8994->saved_regs;
    int v9005 = v9004[29];
    int * v9006 = v8994->regs;
    v9006[29] = v9005;
    int * v9008 = v8994->saved_regs;
    int v9009 = v9008[7];
    int * v9010 = v8994->regs;
    v9010[7] = v9009;
    int * v9012 = v8994->saved_regs;
    int v9013 = v9012[5];
    int * v9014 = v8994->regs;
    v9014[5] = v9013;
    struct StateT * v9016 = slot_161(v8994);
    v9020 = v9016;
  } else {
    struct StateT * v9018 = slot_162(v8994);
    v9020 = v9018;
  }
  return v9020;
}

struct StateT * slot_65(struct StateT * v4620) {
  int * v4621 = v4620->saved_regs;
  int * v4622 = v4620->regs;
  int v4623 = v4622[28];
  v4621[28] = v4623;
  int v4625 = v4620->timer;
  int v4641 = v4625 + 1;
  v4620->timer = v4641;
  int * v4627 = v4620->regs;
  int v4628 = v4627[7];
  int v4629 = v4627[29];
  bool v4645 = (v4628 ^ -2147483648) < (v4629 ^ -2147483648);
  int v4632;
  if (v4645) {
    v4632 = 1;
  } else {
    v4632 = 0;
  }
  int * v4633 = v4620->regs;
  v4633[28] = v4632;
  struct StateT * v4635 = slot_66(v4620);
  return v4635;
}

struct StateT * slot_10(struct StateT * v2165) {
  int v2166 = v2165->timer;
  int v2174 = v2166 + 1;
  v2165->timer = v2174;
  int * v2168 = v2165->regs;
  int v2169 = v2168[15];
  int v2170 = v2168[12];
  int v2179 = v2169 * v2170;
  v2168[5] = v2179;
  struct StateT * v2172 = slot_11(v2165);
  return v2172;
}

struct StateT * slot_150(struct StateT * v8788) {
  int v8789 = v8788->timer;
  int v8801 = v8789 + 1;
  v8788->timer = v8801;
  int * v8791 = v8788->regs;
  int v8792 = v8791[5];
  int v8793 = v8791[9];
  bool v8805 = (v8792 ^ -2147483648) < (v8793 ^ -2147483648);
  int v8796;
  if (v8805) {
    v8796 = 1;
  } else {
    v8796 = 0;
  }
  int * v8797 = v8788->regs;
  v8797[31] = v8796;
  struct StateT * v8799 = slot_151(v8788);
  return v8799;
}

struct StateT * slot_74(struct StateT * v5144) {
  int v5145 = v5144->timer;
  int v5481 = v5145 + 1;
  v5144->timer = v5481;
  int * v5147 = v5144->regs;
  int v5148 = v5147[10];
  int v5149 = v5147[29];
  int * v5150 = v5144->saved_regs;
  int v5151 = v5147[17];
  v5150[17] = v5151;
  int v5153 = v5144->timer;
  int v5488 = v5153 + 1;
  v5144->timer = v5488;
  int * v5155 = v5144->regs;
  int v5156 = v5155[28];
  int v5491 = (int)((unsigned int)v5156 >> 19);
  v5155[17] = v5491;
  int * v5158 = v5144->saved_regs;
  int * v5159 = v5144->regs;
  int v5160 = v5159[28];
  v5158[28] = v5160;
  int v5162 = v5144->timer;
  int v5495 = v5162 + 1;
  v5144->timer = v5495;
  int * v5164 = v5144->regs;
  int v5165 = v5164[28];
  int v5497 = v5165 << 13;
  v5164[28] = v5497;
  int * v5167 = v5144->saved_regs;
  int * v5168 = v5144->regs;
  int v5169 = v5168[5];
  v5167[5] = v5169;
  int v5171 = v5144->timer;
  int v5502 = v5171 + 1;
  v5144->timer = v5502;
  int * v5173 = v5144->regs;
  int v5174 = v5173[6];
  int v5175 = v5173[5];
  int v5505 = v5174 + v5175;
  v5173[5] = v5505;
  int * v5177 = v5144->saved_regs;
  int * v5178 = v5144->regs;
  int v5179 = v5178[6];
  v5177[6] = v5179;
  int v5181 = v5144->timer;
  int v5509 = v5181 + 1;
  v5144->timer = v5509;
  int * v5183 = v5144->regs;
  int v5184 = v5183[11];
  bool v5512 = (((int)((unsigned int)(v5148 + 12) >> 2)) & 3) == (((int)((unsigned int)(v5184 + 16) >> 2)) & 3);
  int v5291;
  if (v5512) {
    int v5185 = v5144->timer;
    int v5513 = v5185 + 1;
    v5144->timer = v5513;
    v5291 = v5149;
  } else {
    int * v5188 = v5144->cache_tags;
    int v5516 = (((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2;
    int v5189 = v5188[v5516];
    int v5517 = ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
    int v5190 = v5188[v5517];
    int v5518 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2);
    int v5191 = v5188[v5518];
    int v5519 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v5192 = v5188[v5519];
    int v5193 = v5144->timer;
    int v5520 = v5193 + ((100 ^ (((~(((v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
    v5144->timer = v5520;
    int * v5195 = v5144->cache_vals;
    bool v5521 = !(((~(((v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v5288;
    if (v5521) {
      int * v5196 = v5144->cache_age;
      int v5523 = ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v5197 = v5196[v5523];
      int v5198 = v5196[v5516];
      int v5524 = v5198 + ((int)((unsigned int)(v5198 - v5197) >> 31));
      v5196[v5516] = v5524;
      int * v5200 = v5144->cache_age;
      int v5201 = v5200[v5517];
      int v5526 = v5201 + ((int)((unsigned int)(v5201 - v5197) >> 31));
      v5200[v5517] = v5526;
      int * v5203 = v5144->cache_age;
      v5203[v5523] = 0;
      v5288 = v5523;
    } else {
      int * v5206 = v5144->cache_age;
      int v5530 = (((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2;
      int v5207 = v5206[v5530];
      int * v5208 = v5144->cache_tags;
      int v5209 = v5208[v5530];
      int v5210 = v5206[v5517];
      int v5211 = v5208[v5517];
      bool v5532 = !(((~(((v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) == 0);
      int v5265;
      if (v5532) {
        int * v5212 = v5144->cache_age;
        int v5534 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) & 1);
        int v5213 = v5212[v5534];
        int v5214 = v5212[v5518];
        int v5535 = v5214 + ((int)((unsigned int)(v5214 - v5213) >> 31));
        v5212[v5518] = v5535;
        int * v5216 = v5144->cache_age;
        int v5217 = v5216[v5519];
        int v5537 = v5217 + ((int)((unsigned int)(v5217 - v5213) >> 31));
        v5216[v5519] = v5537;
        int * v5219 = v5144->cache_age;
        v5219[v5534] = 0;
        v5265 = v5534;
      } else {
        int * v5222 = v5144->cache_age;
        int v5541 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2);
        int v5223 = v5222[v5541];
        int * v5224 = v5144->cache_tags;
        int v5225 = v5224[v5541];
        int v5226 = v5222[v5519];
        int v5227 = v5224[v5519];
        int * v5228 = v5144->cache_dirty;
        int v5544 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v5229 = v5228[v5544];
        bool v5545 = !(v5229 == 0);
        if (v5545) {
          int * v5230 = v5144->cache_tags;
          int v5231 = v5230[v5544];
          int * v5232 = v5144->cache_vals;
          int v5548 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v5233 = v5232[v5548];
          int v5549 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v5234 = v5232[v5549];
          int * v5235 = v5144->mem;
          int v5551 = v5231 * 2;
          v5235[v5551] = v5233;
          int * v5237 = v5144->mem;
          int v5554 = (v5231 * 2) + 1;
          v5237[v5554] = v5234;
          ;
        } else {
          ;
        }
        int * v5242 = v5144->mem;
        int v5559 = ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) * 2;
        int v5243 = v5242[v5559];
        int v5560 = (((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) * 2) + 1;
        int v5244 = v5242[v5560];
        int * v5245 = v5144->cache_vals;
        int v5562 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v5245[v5562] = v5243;
        int * v5247 = v5144->cache_vals;
        int v5565 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v5247[v5565] = v5244;
        int * v5249 = v5144->cache_tags;
        int v5568 = (int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1);
        v5249[v5544] = v5568;
        int * v5251 = v5144->cache_dirty;
        v5251[v5544] = 0;
        int * v5253 = v5144->cache_age;
        v5253[v5544] = 1;
        int * v5255 = v5144->cache_age;
        int v5256 = v5255[v5544];
        int v5257 = v5255[v5518];
        int v5574 = v5257 + ((int)((unsigned int)(v5257 - v5256) >> 31));
        v5255[v5518] = v5574;
        int * v5259 = v5144->cache_age;
        int v5260 = v5259[v5519];
        int v5576 = v5260 + ((int)((unsigned int)(v5260 - v5256) >> 31));
        v5259[v5519] = v5576;
        int * v5262 = v5144->cache_age;
        v5262[v5544] = 0;
        v5265 = v5544;
      }
      int * v5266 = v5144->cache_vals;
      int v5579 = v5265 * 2;
      int v5267 = v5266[v5579];
      int v5580 = (v5265 * 2) + 1;
      int v5268 = v5266[v5580];
      int v5581 = (((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5207 + ((~(((v5209 ^ -1) | (-(v5209 ^ -1))) >> 31)) & 2)) - (v5210 + ((~(((v5211 ^ -1) | (-(v5211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5266[v5581] = v5267;
      int * v5270 = v5144->cache_vals;
      int v5584 = ((((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5207 + ((~(((v5209 ^ -1) | (-(v5209 ^ -1))) >> 31)) & 2)) - (v5210 + ((~(((v5211 ^ -1) | (-(v5211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5270[v5584] = v5268;
      int * v5272 = v5144->cache_tags;
      int v5587 = ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5207 + ((~(((v5209 ^ -1) | (-(v5209 ^ -1))) >> 31)) & 2)) - (v5210 + ((~(((v5211 ^ -1) | (-(v5211 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5588 = (int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1);
      v5272[v5587] = v5588;
      int * v5274 = v5144->cache_dirty;
      v5274[v5587] = 0;
      int * v5276 = v5144->cache_age;
      v5276[v5587] = 1;
      int * v5278 = v5144->cache_age;
      int v5279 = v5278[v5587];
      int v5280 = v5278[v5516];
      int v5594 = v5280 + ((int)((unsigned int)(v5280 - v5279) >> 31));
      v5278[v5516] = v5594;
      int * v5282 = v5144->cache_age;
      int v5283 = v5282[v5517];
      int v5596 = v5283 + ((int)((unsigned int)(v5283 - v5279) >> 31));
      v5282[v5517] = v5596;
      int * v5285 = v5144->cache_age;
      v5285[v5587] = 0;
      v5288 = v5587;
    }
    int v5599 = (v5288 * 2) + (((int)((unsigned int)(v5184 + 16) >> 2)) & 1);
    int v5289 = v5195[v5599];
    v5291 = v5289;
  }
  int * v5292 = v5144->regs;
  v5292[6] = v5291;
  int * v5294 = v5144->cache_tags;
  int v5604 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2;
  int v5295 = v5294[v5604];
  int v5605 = ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5296 = v5294[v5605];
  int v5606 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2);
  int v5297 = v5294[v5606];
  int v5607 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5298 = v5294[v5607];
  int v5299 = v5144->timer;
  int v5608 = v5299 + ((100 ^ (((~(((v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5144->timer = v5608;
  bool v5609 = !(((~(((v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5393;
  if (v5609) {
    int * v5301 = v5144->cache_age;
    int v5611 = ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5302 = v5301[v5611];
    int v5303 = v5301[v5604];
    int v5612 = v5303 + ((int)((unsigned int)(v5303 - v5302) >> 31));
    v5301[v5604] = v5612;
    int * v5305 = v5144->cache_age;
    int v5306 = v5305[v5605];
    int v5614 = v5306 + ((int)((unsigned int)(v5306 - v5302) >> 31));
    v5305[v5605] = v5614;
    int * v5308 = v5144->cache_age;
    v5308[v5611] = 0;
    v5393 = v5611;
  } else {
    int * v5311 = v5144->cache_age;
    int v5618 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2;
    int v5312 = v5311[v5618];
    int * v5313 = v5144->cache_tags;
    int v5314 = v5313[v5618];
    int v5315 = v5311[v5605];
    int v5316 = v5313[v5605];
    bool v5620 = !(((~(((v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v5370;
    if (v5620) {
      int * v5317 = v5144->cache_age;
      int v5622 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v5318 = v5317[v5622];
      int v5319 = v5317[v5606];
      int v5623 = v5319 + ((int)((unsigned int)(v5319 - v5318) >> 31));
      v5317[v5606] = v5623;
      int * v5321 = v5144->cache_age;
      int v5322 = v5321[v5607];
      int v5625 = v5322 + ((int)((unsigned int)(v5322 - v5318) >> 31));
      v5321[v5607] = v5625;
      int * v5324 = v5144->cache_age;
      v5324[v5622] = 0;
      v5370 = v5622;
    } else {
      int * v5327 = v5144->cache_age;
      int v5629 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2);
      int v5328 = v5327[v5629];
      int * v5329 = v5144->cache_tags;
      int v5330 = v5329[v5629];
      int v5331 = v5327[v5607];
      int v5332 = v5329[v5607];
      int * v5333 = v5144->cache_dirty;
      int v5632 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5334 = v5333[v5632];
      bool v5633 = !(v5334 == 0);
      if (v5633) {
        int * v5335 = v5144->cache_tags;
        int v5336 = v5335[v5632];
        int * v5337 = v5144->cache_vals;
        int v5636 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5338 = v5337[v5636];
        int v5637 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5339 = v5337[v5637];
        int * v5340 = v5144->mem;
        int v5639 = v5336 * 2;
        v5340[v5639] = v5338;
        int * v5342 = v5144->mem;
        int v5642 = (v5336 * 2) + 1;
        v5342[v5642] = v5339;
        ;
      } else {
        ;
      }
      int * v5347 = v5144->mem;
      int v5647 = ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2;
      int v5348 = v5347[v5647];
      int v5648 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2) + 1;
      int v5349 = v5347[v5648];
      int * v5350 = v5144->cache_vals;
      int v5650 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5350[v5650] = v5348;
      int * v5352 = v5144->cache_vals;
      int v5653 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5352[v5653] = v5349;
      int * v5354 = v5144->cache_tags;
      int v5656 = (int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1);
      v5354[v5632] = v5656;
      int * v5356 = v5144->cache_dirty;
      v5356[v5632] = 0;
      int * v5358 = v5144->cache_age;
      v5358[v5632] = 1;
      int * v5360 = v5144->cache_age;
      int v5361 = v5360[v5632];
      int v5362 = v5360[v5606];
      int v5662 = v5362 + ((int)((unsigned int)(v5362 - v5361) >> 31));
      v5360[v5606] = v5662;
      int * v5364 = v5144->cache_age;
      int v5365 = v5364[v5607];
      int v5664 = v5365 + ((int)((unsigned int)(v5365 - v5361) >> 31));
      v5364[v5607] = v5664;
      int * v5367 = v5144->cache_age;
      v5367[v5632] = 0;
      v5370 = v5632;
    }
    int * v5371 = v5144->cache_vals;
    int v5667 = v5370 * 2;
    int v5372 = v5371[v5667];
    int v5668 = (v5370 * 2) + 1;
    int v5373 = v5371[v5668];
    int v5669 = (((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5312 + ((~(((v5314 ^ -1) | (-(v5314 ^ -1))) >> 31)) & 2)) - (v5315 + ((~(((v5316 ^ -1) | (-(v5316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5371[v5669] = v5372;
    int * v5375 = v5144->cache_vals;
    int v5672 = ((((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5312 + ((~(((v5314 ^ -1) | (-(v5314 ^ -1))) >> 31)) & 2)) - (v5315 + ((~(((v5316 ^ -1) | (-(v5316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5375[v5672] = v5373;
    int * v5377 = v5144->cache_tags;
    int v5675 = ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5312 + ((~(((v5314 ^ -1) | (-(v5314 ^ -1))) >> 31)) & 2)) - (v5315 + ((~(((v5316 ^ -1) | (-(v5316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5676 = (int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1);
    v5377[v5675] = v5676;
    int * v5379 = v5144->cache_dirty;
    v5379[v5675] = 0;
    int * v5381 = v5144->cache_age;
    v5381[v5675] = 1;
    int * v5383 = v5144->cache_age;
    int v5384 = v5383[v5675];
    int v5385 = v5383[v5604];
    int v5682 = v5385 + ((int)((unsigned int)(v5385 - v5384) >> 31));
    v5383[v5604] = v5682;
    int * v5387 = v5144->cache_age;
    int v5388 = v5387[v5605];
    int v5684 = v5388 + ((int)((unsigned int)(v5388 - v5384) >> 31));
    v5387[v5605] = v5684;
    int * v5390 = v5144->cache_age;
    v5390[v5675] = 0;
    v5393 = v5675;
  }
  int * v5394 = v5144->cache_vals;
  int v5687 = (v5393 * 2) + (((int)((unsigned int)(v5148 + 12) >> 2)) & 1);
  v5394[v5687] = v5149;
  int * v5396 = v5144->cache_tags;
  int v5397 = v5396[v5606];
  int v5398 = v5396[v5607];
  bool v5690 = !(((~(((v5397 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5397 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5452;
  if (v5690) {
    int * v5399 = v5144->cache_age;
    int v5692 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5400 = v5399[v5692];
    int v5401 = v5399[v5606];
    int v5693 = v5401 + ((int)((unsigned int)(v5401 - v5400) >> 31));
    v5399[v5606] = v5693;
    int * v5403 = v5144->cache_age;
    int v5404 = v5403[v5607];
    int v5695 = v5404 + ((int)((unsigned int)(v5404 - v5400) >> 31));
    v5403[v5607] = v5695;
    int * v5406 = v5144->cache_age;
    v5406[v5692] = 0;
    v5452 = v5692;
  } else {
    int * v5409 = v5144->cache_age;
    int v5699 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2);
    int v5410 = v5409[v5699];
    int * v5411 = v5144->cache_tags;
    int v5412 = v5411[v5699];
    int v5413 = v5409[v5607];
    int v5414 = v5411[v5607];
    int * v5415 = v5144->cache_dirty;
    int v5702 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5416 = v5415[v5702];
    bool v5703 = !(v5416 == 0);
    if (v5703) {
      int * v5417 = v5144->cache_tags;
      int v5418 = v5417[v5702];
      int * v5419 = v5144->cache_vals;
      int v5706 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5420 = v5419[v5706];
      int v5707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5421 = v5419[v5707];
      int * v5422 = v5144->mem;
      int v5709 = v5418 * 2;
      v5422[v5709] = v5420;
      int * v5424 = v5144->mem;
      int v5712 = (v5418 * 2) + 1;
      v5424[v5712] = v5421;
      ;
    } else {
      ;
    }
    int * v5429 = v5144->mem;
    int v5717 = ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2;
    int v5430 = v5429[v5717];
    int v5718 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2) + 1;
    int v5431 = v5429[v5718];
    int * v5432 = v5144->cache_vals;
    int v5720 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5432[v5720] = v5430;
    int * v5434 = v5144->cache_vals;
    int v5723 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5434[v5723] = v5431;
    int * v5436 = v5144->cache_tags;
    int v5726 = (int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1);
    v5436[v5702] = v5726;
    int * v5438 = v5144->cache_dirty;
    v5438[v5702] = 0;
    int * v5440 = v5144->cache_age;
    v5440[v5702] = 1;
    int * v5442 = v5144->cache_age;
    int v5443 = v5442[v5702];
    int v5444 = v5442[v5606];
    int v5732 = v5444 + ((int)((unsigned int)(v5444 - v5443) >> 31));
    v5442[v5606] = v5732;
    int * v5446 = v5144->cache_age;
    int v5447 = v5446[v5607];
    int v5734 = v5447 + ((int)((unsigned int)(v5447 - v5443) >> 31));
    v5446[v5607] = v5734;
    int * v5449 = v5144->cache_age;
    v5449[v5702] = 0;
    v5452 = v5702;
  }
  int * v5453 = v5144->cache_vals;
  int v5737 = (v5452 * 2) + (((int)((unsigned int)(v5148 + 12) >> 2)) & 1);
  v5453[v5737] = v5149;
  int * v5455 = v5144->cache_dirty;
  v5455[v5452] = 1;
  bool v5741 = ((((int)((unsigned int)(v5184 + 16) >> 2)) & 3) == (((int)((unsigned int)(v5148 + 12) >> 2)) & 3)) & (!(((int)((unsigned int)(v5184 + 16) >> 2)) == ((int)((unsigned int)(v5148 + 12) >> 2))));
  struct StateT * v5479;
  if (v5741) {
    int v5457 = v5144->timer;
    int v5742 = v5457 + 15;
    v5144->timer = v5742;
    int * v5459 = v5144->saved_regs;
    int v5460 = v5459[17];
    int * v5461 = v5144->regs;
    v5461[17] = v5460;
    int * v5463 = v5144->saved_regs;
    int v5464 = v5463[28];
    int * v5465 = v5144->regs;
    v5465[28] = v5464;
    int * v5467 = v5144->saved_regs;
    int v5468 = v5467[5];
    int * v5469 = v5144->regs;
    v5469[5] = v5468;
    int * v5471 = v5144->saved_regs;
    int v5472 = v5471[6];
    int * v5473 = v5144->regs;
    v5473[6] = v5472;
    struct StateT * v5475 = slot_76(v5144);
    v5479 = v5475;
  } else {
    struct StateT * v5477 = slot_80(v5144);
    v5479 = v5477;
  }
  return v5479;
}

struct StateT * slot_107(struct StateT * v6704) {
  int v6705 = v6704->timer;
  int v6713 = v6705 + 1;
  v6704->timer = v6713;
  int * v6707 = v6704->regs;
  int v6708 = v6707[30];
  int v6709 = v6707[28];
  int v6718 = v6708 + v6709;
  v6707[7] = v6718;
  struct StateT * v6711 = slot_108(v6704);
  return v6711;
}

struct StateT * slot_136(struct StateT * v8524) {
  int v8525 = v8524->timer;
  int v8533 = v8525 + 1;
  v8524->timer = v8533;
  int * v8527 = v8524->regs;
  int v8528 = v8527[29];
  int v8529 = v8527[13];
  int v8538 = (((((int)((unsigned int)v8528 >> 16)) * ((int)((unsigned int)v8529 >> 16))) + ((int)((unsigned int)((v8528 & 65535) * ((int)((unsigned int)v8529 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8528 >> 16)) * (v8529 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8528 & 65535) * (v8529 & 65535)) >> 16)) + (((v8528 & 65535) * ((int)((unsigned int)v8529 >> 16))) & 65535)) + ((((int)((unsigned int)v8528 >> 16)) * (v8529 & 65535)) & 65535)) >> 16));
  v8527[18] = v8538;
  struct StateT * v8531 = slot_137(v8524);
  return v8531;
}

struct StateT * slot_84(struct StateT * v6281) {
  int v6282 = v6281->timer;
  int v6290 = v6282 + 1;
  v6281->timer = v6290;
  int * v6284 = v6281->regs;
  int v6285 = v6284[5];
  int v6286 = v6284[17];
  int v6294 = v6285 | v6286;
  v6284[5] = v6294;
  struct StateT * v6288 = slot_85(v6281);
  return v6288;
}

struct StateT * slot_28(struct StateT * v3618) {
  int v3619 = v3618->timer;
  int v3729 = v3619 + 1;
  v3618->timer = v3729;
  int * v3621 = v3618->regs;
  int v3622 = v3621[11];
  int * v3623 = v3618->cache_tags;
  int v3733 = (((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3624 = v3623[v3733];
  int v3734 = ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3625 = v3623[v3734];
  int v3735 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3626 = v3623[v3735];
  int v3736 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3627 = v3623[v3736];
  int v3628 = v3618->timer;
  int v3737 = v3628 + ((100 ^ (((~(((v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3618->timer = v3737;
  int * v3630 = v3618->cache_vals;
  bool v3738 = !(((~(((v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3723;
  if (v3738) {
    int * v3631 = v3618->cache_age;
    int v3740 = ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3632 = v3631[v3740];
    int v3633 = v3631[v3733];
    int v3741 = v3633 + ((int)((unsigned int)(v3633 - v3632) >> 31));
    v3631[v3733] = v3741;
    int * v3635 = v3618->cache_age;
    int v3636 = v3635[v3734];
    int v3743 = v3636 + ((int)((unsigned int)(v3636 - v3632) >> 31));
    v3635[v3734] = v3743;
    int * v3638 = v3618->cache_age;
    v3638[v3740] = 0;
    v3723 = v3740;
  } else {
    int * v3641 = v3618->cache_age;
    int v3747 = (((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3642 = v3641[v3747];
    int * v3643 = v3618->cache_tags;
    int v3644 = v3643[v3747];
    int v3645 = v3641[v3734];
    int v3646 = v3643[v3734];
    bool v3749 = !(((~(((v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3700;
    if (v3749) {
      int * v3647 = v3618->cache_age;
      int v3751 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3648 = v3647[v3751];
      int v3649 = v3647[v3735];
      int v3752 = v3649 + ((int)((unsigned int)(v3649 - v3648) >> 31));
      v3647[v3735] = v3752;
      int * v3651 = v3618->cache_age;
      int v3652 = v3651[v3736];
      int v3754 = v3652 + ((int)((unsigned int)(v3652 - v3648) >> 31));
      v3651[v3736] = v3754;
      int * v3654 = v3618->cache_age;
      v3654[v3751] = 0;
      v3700 = v3751;
    } else {
      int * v3657 = v3618->cache_age;
      int v3758 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3658 = v3657[v3758];
      int * v3659 = v3618->cache_tags;
      int v3660 = v3659[v3758];
      int v3661 = v3657[v3736];
      int v3662 = v3659[v3736];
      int * v3663 = v3618->cache_dirty;
      int v3761 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3664 = v3663[v3761];
      bool v3762 = !(v3664 == 0);
      if (v3762) {
        int * v3665 = v3618->cache_tags;
        int v3666 = v3665[v3761];
        int * v3667 = v3618->cache_vals;
        int v3765 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3668 = v3667[v3765];
        int v3766 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3669 = v3667[v3766];
        int * v3670 = v3618->mem;
        int v3768 = v3666 * 2;
        v3670[v3768] = v3668;
        int * v3672 = v3618->mem;
        int v3771 = (v3666 * 2) + 1;
        v3672[v3771] = v3669;
        ;
      } else {
        ;
      }
      int * v3677 = v3618->mem;
      int v3776 = ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) * 2;
      int v3678 = v3677[v3776];
      int v3777 = (((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3679 = v3677[v3777];
      int * v3680 = v3618->cache_vals;
      int v3779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3680[v3779] = v3678;
      int * v3682 = v3618->cache_vals;
      int v3782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3682[v3782] = v3679;
      int * v3684 = v3618->cache_tags;
      int v3785 = (int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1);
      v3684[v3761] = v3785;
      int * v3686 = v3618->cache_dirty;
      v3686[v3761] = 0;
      int * v3688 = v3618->cache_age;
      v3688[v3761] = 1;
      int * v3690 = v3618->cache_age;
      int v3691 = v3690[v3761];
      int v3692 = v3690[v3735];
      int v3791 = v3692 + ((int)((unsigned int)(v3692 - v3691) >> 31));
      v3690[v3735] = v3791;
      int * v3694 = v3618->cache_age;
      int v3695 = v3694[v3736];
      int v3793 = v3695 + ((int)((unsigned int)(v3695 - v3691) >> 31));
      v3694[v3736] = v3793;
      int * v3697 = v3618->cache_age;
      v3697[v3761] = 0;
      v3700 = v3761;
    }
    int * v3701 = v3618->cache_vals;
    int v3796 = v3700 * 2;
    int v3702 = v3701[v3796];
    int v3797 = (v3700 * 2) + 1;
    int v3703 = v3701[v3797];
    int v3798 = (((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3642 + ((~(((v3644 ^ -1) | (-(v3644 ^ -1))) >> 31)) & 2)) - (v3645 + ((~(((v3646 ^ -1) | (-(v3646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3701[v3798] = v3702;
    int * v3705 = v3618->cache_vals;
    int v3801 = ((((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3642 + ((~(((v3644 ^ -1) | (-(v3644 ^ -1))) >> 31)) & 2)) - (v3645 + ((~(((v3646 ^ -1) | (-(v3646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3705[v3801] = v3703;
    int * v3707 = v3618->cache_tags;
    int v3804 = ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3642 + ((~(((v3644 ^ -1) | (-(v3644 ^ -1))) >> 31)) & 2)) - (v3645 + ((~(((v3646 ^ -1) | (-(v3646 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3805 = (int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1);
    v3707[v3804] = v3805;
    int * v3709 = v3618->cache_dirty;
    v3709[v3804] = 0;
    int * v3711 = v3618->cache_age;
    v3711[v3804] = 1;
    int * v3713 = v3618->cache_age;
    int v3714 = v3713[v3804];
    int v3715 = v3713[v3733];
    int v3811 = v3715 + ((int)((unsigned int)(v3715 - v3714) >> 31));
    v3713[v3733] = v3811;
    int * v3717 = v3618->cache_age;
    int v3718 = v3717[v3734];
    int v3813 = v3718 + ((int)((unsigned int)(v3718 - v3714) >> 31));
    v3717[v3734] = v3813;
    int * v3720 = v3618->cache_age;
    v3720[v3804] = 0;
    v3723 = v3804;
  }
  int v3816 = (v3723 * 2) + (((int)((unsigned int)(v3622 + 8) >> 2)) & 1);
  int v3724 = v3630[v3816];
  int * v3725 = v3618->regs;
  v3725[7] = v3724;
  struct StateT * v3727 = slot_29(v3618);
  return v3727;
}

struct StateT * slot_155(struct StateT * v8870) {
  int * v8871 = v8870->saved_regs;
  int * v8872 = v8870->regs;
  int v8873 = v8872[28];
  v8871[28] = v8873;
  int v8875 = v8870->timer;
  int v8891 = v8875 + 1;
  v8870->timer = v8891;
  int * v8877 = v8870->regs;
  int v8878 = v8877[7];
  int v8879 = v8877[29];
  bool v8895 = (v8878 ^ -2147483648) < (v8879 ^ -2147483648);
  int v8882;
  if (v8895) {
    v8882 = 1;
  } else {
    v8882 = 0;
  }
  int * v8883 = v8870->regs;
  v8883[28] = v8882;
  struct StateT * v8885 = slot_156(v8870);
  return v8885;
}

struct StateT * slot_177(struct StateT * v10580) {
  int v10581 = v10580->timer;
  int v10589 = v10581 + 1;
  v10580->timer = v10589;
  int * v10583 = v10580->regs;
  int v10584 = v10583[11];
  int v10585 = v10583[12];
  int v10594 = (((((int)((unsigned int)v10584 >> 16)) * ((int)((unsigned int)v10585 >> 16))) + ((int)((unsigned int)((v10584 & 65535) * ((int)((unsigned int)v10585 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v10584 >> 16)) * (v10585 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v10584 & 65535) * (v10585 & 65535)) >> 16)) + (((v10584 & 65535) * ((int)((unsigned int)v10585 >> 16))) & 65535)) + ((((int)((unsigned int)v10584 >> 16)) * (v10585 & 65535)) & 65535)) >> 16));
  v10583[29] = v10594;
  struct StateT * v10587 = slot_178(v10580);
  return v10587;
}

struct StateT * slot_229(struct StateT * v13662) {
  int v13663 = v13662->timer;
  int v13671 = v13663 + 1;
  v13662->timer = v13671;
  int * v13665 = v13662->regs;
  int v13666 = v13665[13];
  int v13667 = v13665[12];
  int v13675 = v13666 + v13667;
  v13665[12] = v13675;
  struct StateT * v13669 = slot_235(v13662);
  return v13669;
}

struct StateT * slot_17(struct StateT * v2310) {
  int v2311 = v2310->timer;
  int v2319 = v2311 + 1;
  v2310->timer = v2319;
  int * v2313 = v2310->regs;
  int v2314 = v2313[5];
  int v2315 = v2313[17];
  int v2323 = v2314 + v2315;
  v2313[17] = v2323;
  struct StateT * v2317 = slot_18(v2310);
  return v2317;
}

struct StateT * slot_181(struct StateT * v10648) {
  int v10649 = v10648->timer;
  int v10657 = v10649 + 1;
  v10648->timer = v10657;
  int * v10651 = v10648->regs;
  int v10652 = v10651[11];
  int v10653 = v10651[13];
  int v10661 = (((((int)((unsigned int)v10652 >> 16)) * ((int)((unsigned int)v10653 >> 16))) + ((int)((unsigned int)((v10652 & 65535) * ((int)((unsigned int)v10653 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v10652 >> 16)) * (v10653 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v10652 & 65535) * (v10653 & 65535)) >> 16)) + (((v10652 & 65535) * ((int)((unsigned int)v10653 >> 16))) & 65535)) + ((((int)((unsigned int)v10652 >> 16)) * (v10653 & 65535)) & 65535)) >> 16));
  v10651[13] = v10661;
  struct StateT * v10655 = slot_182(v10648);
  return v10655;
}

struct StateT * slot_197(struct StateT * v10952) {
  int v10953 = v10952->timer;
  int v10961 = v10953 + 1;
  v10952->timer = v10961;
  int * v10955 = v10952->regs;
  int v10956 = v10955[17];
  int v10957 = v10955[5];
  int v10965 = v10956 + v10957;
  v10955[17] = v10965;
  struct StateT * v10959 = slot_198(v10952);
  return v10959;
}

struct StateT * slot_207(struct StateT * v11153) {
  int v11154 = v11153->timer;
  int v11162 = v11154 + 1;
  v11153->timer = v11162;
  int * v11156 = v11153->regs;
  int v11157 = v11156[17];
  int v11158 = v11156[13];
  int v11166 = v11157 | v11158;
  v11156[13] = v11166;
  struct StateT * v11160 = slot_208(v11153);
  return v11160;
}

struct StateT * slot_156(struct StateT * v8902) {
  int v8903 = v8902->timer;
  int v8911 = v8903 + 1;
  v8902->timer = v8911;
  int * v8905 = v8902->regs;
  int v8906 = v8905[5];
  int v8907 = v8905[28];
  int v8915 = v8906 + v8907;
  v8905[28] = v8915;
  struct StateT * v8909 = slot_157(v8902);
  return v8909;
}

struct StateT * slot_154(struct StateT * v8862) {
  int v8863 = v8862->timer;
  int v8867 = v8863 + 1;
  v8862->timer = v8867;
  struct StateT * v8865 = slot_155(v8862);
  return v8865;
}

struct StateT * slot_68(struct StateT * v4692) {
  int * v4693 = v4692->saved_regs;
  int * v4694 = v4692->regs;
  int v4695 = v4694[7];
  v4693[7] = v4695;
  int v4697 = v4692->timer;
  int v4708 = v4697 + 1;
  v4692->timer = v4708;
  int * v4699 = v4692->regs;
  int v4700 = v4699[7];
  int v4710 = (int)((unsigned int)v4700 >> 19);
  v4699[7] = v4710;
  struct StateT * v4702 = slot_69(v4692);
  return v4702;
}

struct StateT * slot_105(struct StateT * v6663) {
  int v6664 = v6663->timer;
  int v6676 = v6664 + 1;
  v6663->timer = v6676;
  int * v6666 = v6663->regs;
  int v6667 = v6666[5];
  int v6668 = v6666[9];
  bool v6680 = (v6667 ^ -2147483648) < (v6668 ^ -2147483648);
  int v6671;
  if (v6680) {
    v6671 = 1;
  } else {
    v6671 = 0;
  }
  int * v6672 = v6663->regs;
  v6672[31] = v6671;
  struct StateT * v6674 = slot_106(v6663);
  return v6674;
}

struct StateT * slot_27(struct StateT * v3578) {
  int v3579 = v3578->timer;
  int v3587 = v3579 + 1;
  v3578->timer = v3587;
  int * v3581 = v3578->regs;
  int v3582 = v3581[6];
  int v3583 = v3581[5];
  int v3591 = v3582 + v3583;
  v3581[5] = v3591;
  struct StateT * v3585 = slot_28(v3578);
  return v3585;
}

struct StateT * slot_164(struct StateT * v9394) {
  int v9395 = v9394->timer;
  int v9731 = v9395 + 1;
  v9394->timer = v9731;
  int * v9397 = v9394->regs;
  int v9398 = v9397[10];
  int v9399 = v9397[29];
  int * v9400 = v9394->saved_regs;
  int v9401 = v9397[17];
  v9400[17] = v9401;
  int v9403 = v9394->timer;
  int v9738 = v9403 + 1;
  v9394->timer = v9738;
  int * v9405 = v9394->regs;
  int v9406 = v9405[28];
  int v9741 = (int)((unsigned int)v9406 >> 19);
  v9405[17] = v9741;
  int * v9408 = v9394->saved_regs;
  int * v9409 = v9394->regs;
  int v9410 = v9409[28];
  v9408[28] = v9410;
  int v9412 = v9394->timer;
  int v9745 = v9412 + 1;
  v9394->timer = v9745;
  int * v9414 = v9394->regs;
  int v9415 = v9414[28];
  int v9747 = v9415 << 13;
  v9414[28] = v9747;
  int * v9417 = v9394->saved_regs;
  int * v9418 = v9394->regs;
  int v9419 = v9418[5];
  v9417[5] = v9419;
  int v9421 = v9394->timer;
  int v9752 = v9421 + 1;
  v9394->timer = v9752;
  int * v9423 = v9394->regs;
  int v9424 = v9423[6];
  int v9425 = v9423[5];
  int v9755 = v9424 + v9425;
  v9423[5] = v9755;
  int * v9427 = v9394->saved_regs;
  int * v9428 = v9394->regs;
  int v9429 = v9428[6];
  v9427[6] = v9429;
  int v9431 = v9394->timer;
  int v9759 = v9431 + 1;
  v9394->timer = v9759;
  int * v9433 = v9394->regs;
  int v9434 = v9433[11];
  bool v9762 = (((int)((unsigned int)(v9398 + 28) >> 2)) & 3) == (((int)((unsigned int)(v9434 + 32) >> 2)) & 3);
  int v9541;
  if (v9762) {
    int v9435 = v9394->timer;
    int v9763 = v9435 + 1;
    v9394->timer = v9763;
    v9541 = v9399;
  } else {
    int * v9438 = v9394->cache_tags;
    int v9766 = (((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2;
    int v9439 = v9438[v9766];
    int v9767 = ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
    int v9440 = v9438[v9767];
    int v9768 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2);
    int v9441 = v9438[v9768];
    int v9769 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v9442 = v9438[v9769];
    int v9443 = v9394->timer;
    int v9770 = v9443 + ((100 ^ (((~(((v9441 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9441 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9439 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9439 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9440 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9440 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9441 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9441 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
    v9394->timer = v9770;
    int * v9445 = v9394->cache_vals;
    bool v9771 = !(((~(((v9439 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9439 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9440 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9440 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v9538;
    if (v9771) {
      int * v9446 = v9394->cache_age;
      int v9773 = ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v9440 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9440 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v9447 = v9446[v9773];
      int v9448 = v9446[v9766];
      int v9774 = v9448 + ((int)((unsigned int)(v9448 - v9447) >> 31));
      v9446[v9766] = v9774;
      int * v9450 = v9394->cache_age;
      int v9451 = v9450[v9767];
      int v9776 = v9451 + ((int)((unsigned int)(v9451 - v9447) >> 31));
      v9450[v9767] = v9776;
      int * v9453 = v9394->cache_age;
      v9453[v9773] = 0;
      v9538 = v9773;
    } else {
      int * v9456 = v9394->cache_age;
      int v9780 = (((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2;
      int v9457 = v9456[v9780];
      int * v9458 = v9394->cache_tags;
      int v9459 = v9458[v9780];
      int v9460 = v9456[v9767];
      int v9461 = v9458[v9767];
      bool v9782 = !(((~(((v9441 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9441 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31))) == 0);
      int v9515;
      if (v9782) {
        int * v9462 = v9394->cache_age;
        int v9784 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))) | (-(v9442 ^ ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1))))) >> 31)) & 1);
        int v9463 = v9462[v9784];
        int v9464 = v9462[v9768];
        int v9785 = v9464 + ((int)((unsigned int)(v9464 - v9463) >> 31));
        v9462[v9768] = v9785;
        int * v9466 = v9394->cache_age;
        int v9467 = v9466[v9769];
        int v9787 = v9467 + ((int)((unsigned int)(v9467 - v9463) >> 31));
        v9466[v9769] = v9787;
        int * v9469 = v9394->cache_age;
        v9469[v9784] = 0;
        v9515 = v9784;
      } else {
        int * v9472 = v9394->cache_age;
        int v9791 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2);
        int v9473 = v9472[v9791];
        int * v9474 = v9394->cache_tags;
        int v9475 = v9474[v9791];
        int v9476 = v9472[v9769];
        int v9477 = v9474[v9769];
        int * v9478 = v9394->cache_dirty;
        int v9794 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9473 + ((~(((v9475 ^ -1) | (-(v9475 ^ -1))) >> 31)) & 2)) - (v9476 + ((~(((v9477 ^ -1) | (-(v9477 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v9479 = v9478[v9794];
        bool v9795 = !(v9479 == 0);
        if (v9795) {
          int * v9480 = v9394->cache_tags;
          int v9481 = v9480[v9794];
          int * v9482 = v9394->cache_vals;
          int v9798 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9473 + ((~(((v9475 ^ -1) | (-(v9475 ^ -1))) >> 31)) & 2)) - (v9476 + ((~(((v9477 ^ -1) | (-(v9477 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v9483 = v9482[v9798];
          int v9799 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9473 + ((~(((v9475 ^ -1) | (-(v9475 ^ -1))) >> 31)) & 2)) - (v9476 + ((~(((v9477 ^ -1) | (-(v9477 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v9484 = v9482[v9799];
          int * v9485 = v9394->mem;
          int v9801 = v9481 * 2;
          v9485[v9801] = v9483;
          int * v9487 = v9394->mem;
          int v9804 = (v9481 * 2) + 1;
          v9487[v9804] = v9484;
          ;
        } else {
          ;
        }
        int * v9492 = v9394->mem;
        int v9809 = ((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) * 2;
        int v9493 = v9492[v9809];
        int v9810 = (((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) * 2) + 1;
        int v9494 = v9492[v9810];
        int * v9495 = v9394->cache_vals;
        int v9812 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9473 + ((~(((v9475 ^ -1) | (-(v9475 ^ -1))) >> 31)) & 2)) - (v9476 + ((~(((v9477 ^ -1) | (-(v9477 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v9495[v9812] = v9493;
        int * v9497 = v9394->cache_vals;
        int v9815 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9473 + ((~(((v9475 ^ -1) | (-(v9475 ^ -1))) >> 31)) & 2)) - (v9476 + ((~(((v9477 ^ -1) | (-(v9477 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v9497[v9815] = v9494;
        int * v9499 = v9394->cache_tags;
        int v9818 = (int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1);
        v9499[v9794] = v9818;
        int * v9501 = v9394->cache_dirty;
        v9501[v9794] = 0;
        int * v9503 = v9394->cache_age;
        v9503[v9794] = 1;
        int * v9505 = v9394->cache_age;
        int v9506 = v9505[v9794];
        int v9507 = v9505[v9768];
        int v9824 = v9507 + ((int)((unsigned int)(v9507 - v9506) >> 31));
        v9505[v9768] = v9824;
        int * v9509 = v9394->cache_age;
        int v9510 = v9509[v9769];
        int v9826 = v9510 + ((int)((unsigned int)(v9510 - v9506) >> 31));
        v9509[v9769] = v9826;
        int * v9512 = v9394->cache_age;
        v9512[v9794] = 0;
        v9515 = v9794;
      }
      int * v9516 = v9394->cache_vals;
      int v9829 = v9515 * 2;
      int v9517 = v9516[v9829];
      int v9830 = (v9515 * 2) + 1;
      int v9518 = v9516[v9830];
      int v9831 = (((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v9457 + ((~(((v9459 ^ -1) | (-(v9459 ^ -1))) >> 31)) & 2)) - (v9460 + ((~(((v9461 ^ -1) | (-(v9461 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9516[v9831] = v9517;
      int * v9520 = v9394->cache_vals;
      int v9834 = ((((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v9457 + ((~(((v9459 ^ -1) | (-(v9459 ^ -1))) >> 31)) & 2)) - (v9460 + ((~(((v9461 ^ -1) | (-(v9461 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9520[v9834] = v9518;
      int * v9522 = v9394->cache_tags;
      int v9837 = ((((int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v9457 + ((~(((v9459 ^ -1) | (-(v9459 ^ -1))) >> 31)) & 2)) - (v9460 + ((~(((v9461 ^ -1) | (-(v9461 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9838 = (int)((unsigned int)((int)((unsigned int)(v9434 + 32) >> 2)) >> 1);
      v9522[v9837] = v9838;
      int * v9524 = v9394->cache_dirty;
      v9524[v9837] = 0;
      int * v9526 = v9394->cache_age;
      v9526[v9837] = 1;
      int * v9528 = v9394->cache_age;
      int v9529 = v9528[v9837];
      int v9530 = v9528[v9766];
      int v9844 = v9530 + ((int)((unsigned int)(v9530 - v9529) >> 31));
      v9528[v9766] = v9844;
      int * v9532 = v9394->cache_age;
      int v9533 = v9532[v9767];
      int v9846 = v9533 + ((int)((unsigned int)(v9533 - v9529) >> 31));
      v9532[v9767] = v9846;
      int * v9535 = v9394->cache_age;
      v9535[v9837] = 0;
      v9538 = v9837;
    }
    int v9849 = (v9538 * 2) + (((int)((unsigned int)(v9434 + 32) >> 2)) & 1);
    int v9539 = v9445[v9849];
    v9541 = v9539;
  }
  int * v9542 = v9394->regs;
  v9542[6] = v9541;
  int * v9544 = v9394->cache_tags;
  int v9854 = (((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2;
  int v9545 = v9544[v9854];
  int v9855 = ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9546 = v9544[v9855];
  int v9856 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2);
  int v9547 = v9544[v9856];
  int v9857 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9548 = v9544[v9857];
  int v9549 = v9394->timer;
  int v9858 = v9549 + ((100 ^ (((~(((v9547 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9547 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9545 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9545 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v9546 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9546 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9547 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9547 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9394->timer = v9858;
  bool v9859 = !(((~(((v9545 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9545 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v9546 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9546 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v9643;
  if (v9859) {
    int * v9551 = v9394->cache_age;
    int v9861 = ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v9546 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9546 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v9552 = v9551[v9861];
    int v9553 = v9551[v9854];
    int v9862 = v9553 + ((int)((unsigned int)(v9553 - v9552) >> 31));
    v9551[v9854] = v9862;
    int * v9555 = v9394->cache_age;
    int v9556 = v9555[v9855];
    int v9864 = v9556 + ((int)((unsigned int)(v9556 - v9552) >> 31));
    v9555[v9855] = v9864;
    int * v9558 = v9394->cache_age;
    v9558[v9861] = 0;
    v9643 = v9861;
  } else {
    int * v9561 = v9394->cache_age;
    int v9868 = (((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2;
    int v9562 = v9561[v9868];
    int * v9563 = v9394->cache_tags;
    int v9564 = v9563[v9868];
    int v9565 = v9561[v9855];
    int v9566 = v9563[v9855];
    bool v9870 = !(((~(((v9547 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9547 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v9620;
    if (v9870) {
      int * v9567 = v9394->cache_age;
      int v9872 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9548 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v9568 = v9567[v9872];
      int v9569 = v9567[v9856];
      int v9873 = v9569 + ((int)((unsigned int)(v9569 - v9568) >> 31));
      v9567[v9856] = v9873;
      int * v9571 = v9394->cache_age;
      int v9572 = v9571[v9857];
      int v9875 = v9572 + ((int)((unsigned int)(v9572 - v9568) >> 31));
      v9571[v9857] = v9875;
      int * v9574 = v9394->cache_age;
      v9574[v9872] = 0;
      v9620 = v9872;
    } else {
      int * v9577 = v9394->cache_age;
      int v9879 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2);
      int v9578 = v9577[v9879];
      int * v9579 = v9394->cache_tags;
      int v9580 = v9579[v9879];
      int v9581 = v9577[v9857];
      int v9582 = v9579[v9857];
      int * v9583 = v9394->cache_dirty;
      int v9882 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9578 + ((~(((v9580 ^ -1) | (-(v9580 ^ -1))) >> 31)) & 2)) - (v9581 + ((~(((v9582 ^ -1) | (-(v9582 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9584 = v9583[v9882];
      bool v9883 = !(v9584 == 0);
      if (v9883) {
        int * v9585 = v9394->cache_tags;
        int v9586 = v9585[v9882];
        int * v9587 = v9394->cache_vals;
        int v9886 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9578 + ((~(((v9580 ^ -1) | (-(v9580 ^ -1))) >> 31)) & 2)) - (v9581 + ((~(((v9582 ^ -1) | (-(v9582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9588 = v9587[v9886];
        int v9887 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9578 + ((~(((v9580 ^ -1) | (-(v9580 ^ -1))) >> 31)) & 2)) - (v9581 + ((~(((v9582 ^ -1) | (-(v9582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9589 = v9587[v9887];
        int * v9590 = v9394->mem;
        int v9889 = v9586 * 2;
        v9590[v9889] = v9588;
        int * v9592 = v9394->mem;
        int v9892 = (v9586 * 2) + 1;
        v9592[v9892] = v9589;
        ;
      } else {
        ;
      }
      int * v9597 = v9394->mem;
      int v9897 = ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) * 2;
      int v9598 = v9597[v9897];
      int v9898 = (((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) * 2) + 1;
      int v9599 = v9597[v9898];
      int * v9600 = v9394->cache_vals;
      int v9900 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9578 + ((~(((v9580 ^ -1) | (-(v9580 ^ -1))) >> 31)) & 2)) - (v9581 + ((~(((v9582 ^ -1) | (-(v9582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9600[v9900] = v9598;
      int * v9602 = v9394->cache_vals;
      int v9903 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9578 + ((~(((v9580 ^ -1) | (-(v9580 ^ -1))) >> 31)) & 2)) - (v9581 + ((~(((v9582 ^ -1) | (-(v9582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9602[v9903] = v9599;
      int * v9604 = v9394->cache_tags;
      int v9906 = (int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1);
      v9604[v9882] = v9906;
      int * v9606 = v9394->cache_dirty;
      v9606[v9882] = 0;
      int * v9608 = v9394->cache_age;
      v9608[v9882] = 1;
      int * v9610 = v9394->cache_age;
      int v9611 = v9610[v9882];
      int v9612 = v9610[v9856];
      int v9912 = v9612 + ((int)((unsigned int)(v9612 - v9611) >> 31));
      v9610[v9856] = v9912;
      int * v9614 = v9394->cache_age;
      int v9615 = v9614[v9857];
      int v9914 = v9615 + ((int)((unsigned int)(v9615 - v9611) >> 31));
      v9614[v9857] = v9914;
      int * v9617 = v9394->cache_age;
      v9617[v9882] = 0;
      v9620 = v9882;
    }
    int * v9621 = v9394->cache_vals;
    int v9917 = v9620 * 2;
    int v9622 = v9621[v9917];
    int v9918 = (v9620 * 2) + 1;
    int v9623 = v9621[v9918];
    int v9919 = (((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v9562 + ((~(((v9564 ^ -1) | (-(v9564 ^ -1))) >> 31)) & 2)) - (v9565 + ((~(((v9566 ^ -1) | (-(v9566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9621[v9919] = v9622;
    int * v9625 = v9394->cache_vals;
    int v9922 = ((((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v9562 + ((~(((v9564 ^ -1) | (-(v9564 ^ -1))) >> 31)) & 2)) - (v9565 + ((~(((v9566 ^ -1) | (-(v9566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9625[v9922] = v9623;
    int * v9627 = v9394->cache_tags;
    int v9925 = ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v9562 + ((~(((v9564 ^ -1) | (-(v9564 ^ -1))) >> 31)) & 2)) - (v9565 + ((~(((v9566 ^ -1) | (-(v9566 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9926 = (int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1);
    v9627[v9925] = v9926;
    int * v9629 = v9394->cache_dirty;
    v9629[v9925] = 0;
    int * v9631 = v9394->cache_age;
    v9631[v9925] = 1;
    int * v9633 = v9394->cache_age;
    int v9634 = v9633[v9925];
    int v9635 = v9633[v9854];
    int v9932 = v9635 + ((int)((unsigned int)(v9635 - v9634) >> 31));
    v9633[v9854] = v9932;
    int * v9637 = v9394->cache_age;
    int v9638 = v9637[v9855];
    int v9934 = v9638 + ((int)((unsigned int)(v9638 - v9634) >> 31));
    v9637[v9855] = v9934;
    int * v9640 = v9394->cache_age;
    v9640[v9925] = 0;
    v9643 = v9925;
  }
  int * v9644 = v9394->cache_vals;
  int v9937 = (v9643 * 2) + (((int)((unsigned int)(v9398 + 28) >> 2)) & 1);
  v9644[v9937] = v9399;
  int * v9646 = v9394->cache_tags;
  int v9647 = v9646[v9856];
  int v9648 = v9646[v9857];
  bool v9940 = !(((~(((v9647 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9647 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v9648 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9648 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v9702;
  if (v9940) {
    int * v9649 = v9394->cache_age;
    int v9942 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9648 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))) | (-(v9648 ^ ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v9650 = v9649[v9942];
    int v9651 = v9649[v9856];
    int v9943 = v9651 + ((int)((unsigned int)(v9651 - v9650) >> 31));
    v9649[v9856] = v9943;
    int * v9653 = v9394->cache_age;
    int v9654 = v9653[v9857];
    int v9945 = v9654 + ((int)((unsigned int)(v9654 - v9650) >> 31));
    v9653[v9857] = v9945;
    int * v9656 = v9394->cache_age;
    v9656[v9942] = 0;
    v9702 = v9942;
  } else {
    int * v9659 = v9394->cache_age;
    int v9949 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2);
    int v9660 = v9659[v9949];
    int * v9661 = v9394->cache_tags;
    int v9662 = v9661[v9949];
    int v9663 = v9659[v9857];
    int v9664 = v9661[v9857];
    int * v9665 = v9394->cache_dirty;
    int v9952 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9666 = v9665[v9952];
    bool v9953 = !(v9666 == 0);
    if (v9953) {
      int * v9667 = v9394->cache_tags;
      int v9668 = v9667[v9952];
      int * v9669 = v9394->cache_vals;
      int v9956 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9670 = v9669[v9956];
      int v9957 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9671 = v9669[v9957];
      int * v9672 = v9394->mem;
      int v9959 = v9668 * 2;
      v9672[v9959] = v9670;
      int * v9674 = v9394->mem;
      int v9962 = (v9668 * 2) + 1;
      v9674[v9962] = v9671;
      ;
    } else {
      ;
    }
    int * v9679 = v9394->mem;
    int v9967 = ((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) * 2;
    int v9680 = v9679[v9967];
    int v9968 = (((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) * 2) + 1;
    int v9681 = v9679[v9968];
    int * v9682 = v9394->cache_vals;
    int v9970 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9682[v9970] = v9680;
    int * v9684 = v9394->cache_vals;
    int v9973 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9684[v9973] = v9681;
    int * v9686 = v9394->cache_tags;
    int v9976 = (int)((unsigned int)((int)((unsigned int)(v9398 + 28) >> 2)) >> 1);
    v9686[v9952] = v9976;
    int * v9688 = v9394->cache_dirty;
    v9688[v9952] = 0;
    int * v9690 = v9394->cache_age;
    v9690[v9952] = 1;
    int * v9692 = v9394->cache_age;
    int v9693 = v9692[v9952];
    int v9694 = v9692[v9856];
    int v9982 = v9694 + ((int)((unsigned int)(v9694 - v9693) >> 31));
    v9692[v9856] = v9982;
    int * v9696 = v9394->cache_age;
    int v9697 = v9696[v9857];
    int v9984 = v9697 + ((int)((unsigned int)(v9697 - v9693) >> 31));
    v9696[v9857] = v9984;
    int * v9699 = v9394->cache_age;
    v9699[v9952] = 0;
    v9702 = v9952;
  }
  int * v9703 = v9394->cache_vals;
  int v9987 = (v9702 * 2) + (((int)((unsigned int)(v9398 + 28) >> 2)) & 1);
  v9703[v9987] = v9399;
  int * v9705 = v9394->cache_dirty;
  v9705[v9702] = 1;
  bool v9991 = ((((int)((unsigned int)(v9434 + 32) >> 2)) & 3) == (((int)((unsigned int)(v9398 + 28) >> 2)) & 3)) & (!(((int)((unsigned int)(v9434 + 32) >> 2)) == ((int)((unsigned int)(v9398 + 28) >> 2))));
  struct StateT * v9729;
  if (v9991) {
    int v9707 = v9394->timer;
    int v9992 = v9707 + 15;
    v9394->timer = v9992;
    int * v9709 = v9394->saved_regs;
    int v9710 = v9709[17];
    int * v9711 = v9394->regs;
    v9711[17] = v9710;
    int * v9713 = v9394->saved_regs;
    int v9714 = v9713[28];
    int * v9715 = v9394->regs;
    v9715[28] = v9714;
    int * v9717 = v9394->saved_regs;
    int v9718 = v9717[5];
    int * v9719 = v9394->regs;
    v9719[5] = v9718;
    int * v9721 = v9394->saved_regs;
    int v9722 = v9721[6];
    int * v9723 = v9394->regs;
    v9723[6] = v9722;
    struct StateT * v9725 = slot_166(v9394);
    v9729 = v9725;
  } else {
    struct StateT * v9727 = slot_170(v9394);
    v9729 = v9727;
  }
  return v9729;
}

struct StateT * slot_15(struct StateT * v2277) {
  int v2278 = v2277->timer;
  int v2286 = v2278 + 1;
  v2277->timer = v2286;
  int * v2280 = v2277->regs;
  int v2281 = v2280[15];
  int v2282 = v2280[13];
  int v2291 = (((((int)((unsigned int)v2281 >> 16)) * ((int)((unsigned int)v2282 >> 16))) + ((int)((unsigned int)((v2281 & 65535) * ((int)((unsigned int)v2282 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2281 >> 16)) * (v2282 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2281 & 65535) * (v2282 & 65535)) >> 16)) + (((v2281 & 65535) * ((int)((unsigned int)v2282 >> 16))) & 65535)) + ((((int)((unsigned int)v2281 >> 16)) * (v2282 & 65535)) & 65535)) >> 16));
  v2280[30] = v2291;
  struct StateT * v2284 = slot_16(v2277);
  return v2284;
}

struct StateT * slot_133(struct StateT * v8473) {
  int v8474 = v8473->timer;
  int v8482 = v8474 + 1;
  v8473->timer = v8482;
  int * v8476 = v8473->regs;
  int v8477 = v8476[6];
  int v8478 = v8476[13];
  int v8487 = v8477 * v8478;
  v8476[31] = v8487;
  struct StateT * v8480 = slot_134(v8473);
  return v8480;
}

struct StateT * slot_56(struct StateT * v4466) {
  int v4467 = v4466->timer;
  int v4475 = v4467 + 1;
  v4466->timer = v4475;
  int * v4469 = v4466->regs;
  int v4470 = v4469[9];
  int v4471 = v4469[6];
  int v4479 = v4470 + v4471;
  v4469[6] = v4479;
  struct StateT * v4473 = slot_57(v4466);
  return v4473;
}

struct StateT * slot_244(struct StateT * v14618) {
  int v14619 = v14618->timer;
  int v14627 = v14619 + 1;
  v14618->timer = v14627;
  int * v14621 = v14618->regs;
  int v14622 = v14621[13];
  int v14623 = v14621[17];
  int v14631 = v14622 * v14623;
  v14621[13] = v14631;
  struct StateT * v14625 = slot_245(v14618);
  return v14625;
}

struct StateT * slot_222(struct StateT * v11472) {
  int v11473 = v11472->timer;
  int v11643 = v11473 + 1;
  v11472->timer = v11643;
  int * v11475 = v11472->regs;
  int v11476 = v11475[10];
  int v11477 = v11475[13];
  int * v11478 = v11472->cache_tags;
  int v11648 = (((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2;
  int v11479 = v11478[v11648];
  int v11649 = ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2) + 1;
  int v11480 = v11478[v11649];
  int v11650 = 4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2);
  int v11481 = v11478[v11650];
  int v11651 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11482 = v11478[v11651];
  int v11483 = v11472->timer;
  int v11652 = v11483 + ((100 ^ (((~(((v11481 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11481 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) | (~(((v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11479 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11479 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) | (~(((v11480 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11480 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11481 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11481 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) | (~(((v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31))) & 104)))));
  v11472->timer = v11652;
  bool v11653 = !(((~(((v11479 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11479 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) | (~(((v11480 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11480 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31))) == 0);
  int v11577;
  if (v11653) {
    int * v11485 = v11472->cache_age;
    int v11655 = ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2) + ((~(((v11480 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11480 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) & 1);
    int v11486 = v11485[v11655];
    int v11487 = v11485[v11648];
    int v11656 = v11487 + ((int)((unsigned int)(v11487 - v11486) >> 31));
    v11485[v11648] = v11656;
    int * v11489 = v11472->cache_age;
    int v11490 = v11489[v11649];
    int v11658 = v11490 + ((int)((unsigned int)(v11490 - v11486) >> 31));
    v11489[v11649] = v11658;
    int * v11492 = v11472->cache_age;
    v11492[v11655] = 0;
    v11577 = v11655;
  } else {
    int * v11495 = v11472->cache_age;
    int v11662 = (((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2;
    int v11496 = v11495[v11662];
    int * v11497 = v11472->cache_tags;
    int v11498 = v11497[v11662];
    int v11499 = v11495[v11649];
    int v11500 = v11497[v11649];
    bool v11664 = !(((~(((v11481 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11481 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) | (~(((v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31))) == 0);
    int v11554;
    if (v11664) {
      int * v11501 = v11472->cache_age;
      int v11666 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11482 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) & 1);
      int v11502 = v11501[v11666];
      int v11503 = v11501[v11650];
      int v11667 = v11503 + ((int)((unsigned int)(v11503 - v11502) >> 31));
      v11501[v11650] = v11667;
      int * v11505 = v11472->cache_age;
      int v11506 = v11505[v11651];
      int v11669 = v11506 + ((int)((unsigned int)(v11506 - v11502) >> 31));
      v11505[v11651] = v11669;
      int * v11508 = v11472->cache_age;
      v11508[v11666] = 0;
      v11554 = v11666;
    } else {
      int * v11511 = v11472->cache_age;
      int v11673 = 4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2);
      int v11512 = v11511[v11673];
      int * v11513 = v11472->cache_tags;
      int v11514 = v11513[v11673];
      int v11515 = v11511[v11651];
      int v11516 = v11513[v11651];
      int * v11517 = v11472->cache_dirty;
      int v11676 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11512 + ((~(((v11514 ^ -1) | (-(v11514 ^ -1))) >> 31)) & 2)) - (v11515 + ((~(((v11516 ^ -1) | (-(v11516 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11518 = v11517[v11676];
      bool v11677 = !(v11518 == 0);
      if (v11677) {
        int * v11519 = v11472->cache_tags;
        int v11520 = v11519[v11676];
        int * v11521 = v11472->cache_vals;
        int v11680 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11512 + ((~(((v11514 ^ -1) | (-(v11514 ^ -1))) >> 31)) & 2)) - (v11515 + ((~(((v11516 ^ -1) | (-(v11516 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11522 = v11521[v11680];
        int v11681 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11512 + ((~(((v11514 ^ -1) | (-(v11514 ^ -1))) >> 31)) & 2)) - (v11515 + ((~(((v11516 ^ -1) | (-(v11516 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11523 = v11521[v11681];
        int * v11524 = v11472->mem;
        int v11683 = v11520 * 2;
        v11524[v11683] = v11522;
        int * v11526 = v11472->mem;
        int v11686 = (v11520 * 2) + 1;
        v11526[v11686] = v11523;
        ;
      } else {
        ;
      }
      int * v11531 = v11472->mem;
      int v11691 = ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) * 2;
      int v11532 = v11531[v11691];
      int v11692 = (((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) * 2) + 1;
      int v11533 = v11531[v11692];
      int * v11534 = v11472->cache_vals;
      int v11694 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11512 + ((~(((v11514 ^ -1) | (-(v11514 ^ -1))) >> 31)) & 2)) - (v11515 + ((~(((v11516 ^ -1) | (-(v11516 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11534[v11694] = v11532;
      int * v11536 = v11472->cache_vals;
      int v11697 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11512 + ((~(((v11514 ^ -1) | (-(v11514 ^ -1))) >> 31)) & 2)) - (v11515 + ((~(((v11516 ^ -1) | (-(v11516 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11536[v11697] = v11533;
      int * v11538 = v11472->cache_tags;
      int v11700 = (int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1);
      v11538[v11676] = v11700;
      int * v11540 = v11472->cache_dirty;
      v11540[v11676] = 0;
      int * v11542 = v11472->cache_age;
      v11542[v11676] = 1;
      int * v11544 = v11472->cache_age;
      int v11545 = v11544[v11676];
      int v11546 = v11544[v11650];
      int v11706 = v11546 + ((int)((unsigned int)(v11546 - v11545) >> 31));
      v11544[v11650] = v11706;
      int * v11548 = v11472->cache_age;
      int v11549 = v11548[v11651];
      int v11708 = v11549 + ((int)((unsigned int)(v11549 - v11545) >> 31));
      v11548[v11651] = v11708;
      int * v11551 = v11472->cache_age;
      v11551[v11676] = 0;
      v11554 = v11676;
    }
    int * v11555 = v11472->cache_vals;
    int v11711 = v11554 * 2;
    int v11556 = v11555[v11711];
    int v11712 = (v11554 * 2) + 1;
    int v11557 = v11555[v11712];
    int v11713 = (((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2) + ((((v11496 + ((~(((v11498 ^ -1) | (-(v11498 ^ -1))) >> 31)) & 2)) - (v11499 + ((~(((v11500 ^ -1) | (-(v11500 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11555[v11713] = v11556;
    int * v11559 = v11472->cache_vals;
    int v11716 = ((((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2) + ((((v11496 + ((~(((v11498 ^ -1) | (-(v11498 ^ -1))) >> 31)) & 2)) - (v11499 + ((~(((v11500 ^ -1) | (-(v11500 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11559[v11716] = v11557;
    int * v11561 = v11472->cache_tags;
    int v11719 = ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 1) * 2) + ((((v11496 + ((~(((v11498 ^ -1) | (-(v11498 ^ -1))) >> 31)) & 2)) - (v11499 + ((~(((v11500 ^ -1) | (-(v11500 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11720 = (int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1);
    v11561[v11719] = v11720;
    int * v11563 = v11472->cache_dirty;
    v11563[v11719] = 0;
    int * v11565 = v11472->cache_age;
    v11565[v11719] = 1;
    int * v11567 = v11472->cache_age;
    int v11568 = v11567[v11719];
    int v11569 = v11567[v11648];
    int v11726 = v11569 + ((int)((unsigned int)(v11569 - v11568) >> 31));
    v11567[v11648] = v11726;
    int * v11571 = v11472->cache_age;
    int v11572 = v11571[v11649];
    int v11728 = v11572 + ((int)((unsigned int)(v11572 - v11568) >> 31));
    v11571[v11649] = v11728;
    int * v11574 = v11472->cache_age;
    v11574[v11719] = 0;
    v11577 = v11719;
  }
  int * v11578 = v11472->cache_vals;
  int v11731 = (v11577 * 2) + (((int)((unsigned int)v11476 >> 2)) & 1);
  v11578[v11731] = v11477;
  int * v11580 = v11472->cache_tags;
  int v11581 = v11580[v11650];
  int v11582 = v11580[v11651];
  bool v11734 = !(((~(((v11581 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11581 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) | (~(((v11582 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11582 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31))) == 0);
  int v11636;
  if (v11734) {
    int * v11583 = v11472->cache_age;
    int v11736 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11582 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))) | (-(v11582 ^ ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1))))) >> 31)) & 1);
    int v11584 = v11583[v11736];
    int v11585 = v11583[v11650];
    int v11737 = v11585 + ((int)((unsigned int)(v11585 - v11584) >> 31));
    v11583[v11650] = v11737;
    int * v11587 = v11472->cache_age;
    int v11588 = v11587[v11651];
    int v11739 = v11588 + ((int)((unsigned int)(v11588 - v11584) >> 31));
    v11587[v11651] = v11739;
    int * v11590 = v11472->cache_age;
    v11590[v11736] = 0;
    v11636 = v11736;
  } else {
    int * v11593 = v11472->cache_age;
    int v11743 = 4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2);
    int v11594 = v11593[v11743];
    int * v11595 = v11472->cache_tags;
    int v11596 = v11595[v11743];
    int v11597 = v11593[v11651];
    int v11598 = v11595[v11651];
    int * v11599 = v11472->cache_dirty;
    int v11746 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11594 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2)) - (v11597 + ((~(((v11598 ^ -1) | (-(v11598 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11600 = v11599[v11746];
    bool v11747 = !(v11600 == 0);
    if (v11747) {
      int * v11601 = v11472->cache_tags;
      int v11602 = v11601[v11746];
      int * v11603 = v11472->cache_vals;
      int v11750 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11594 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2)) - (v11597 + ((~(((v11598 ^ -1) | (-(v11598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11604 = v11603[v11750];
      int v11751 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11594 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2)) - (v11597 + ((~(((v11598 ^ -1) | (-(v11598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11605 = v11603[v11751];
      int * v11606 = v11472->mem;
      int v11753 = v11602 * 2;
      v11606[v11753] = v11604;
      int * v11608 = v11472->mem;
      int v11756 = (v11602 * 2) + 1;
      v11608[v11756] = v11605;
      ;
    } else {
      ;
    }
    int * v11613 = v11472->mem;
    int v11761 = ((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) * 2;
    int v11614 = v11613[v11761];
    int v11762 = (((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) * 2) + 1;
    int v11615 = v11613[v11762];
    int * v11616 = v11472->cache_vals;
    int v11764 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11594 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2)) - (v11597 + ((~(((v11598 ^ -1) | (-(v11598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11616[v11764] = v11614;
    int * v11618 = v11472->cache_vals;
    int v11767 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1)) & 3) * 2)) + ((((v11594 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2)) - (v11597 + ((~(((v11598 ^ -1) | (-(v11598 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11618[v11767] = v11615;
    int * v11620 = v11472->cache_tags;
    int v11770 = (int)((unsigned int)((int)((unsigned int)v11476 >> 2)) >> 1);
    v11620[v11746] = v11770;
    int * v11622 = v11472->cache_dirty;
    v11622[v11746] = 0;
    int * v11624 = v11472->cache_age;
    v11624[v11746] = 1;
    int * v11626 = v11472->cache_age;
    int v11627 = v11626[v11746];
    int v11628 = v11626[v11650];
    int v11776 = v11628 + ((int)((unsigned int)(v11628 - v11627) >> 31));
    v11626[v11650] = v11776;
    int * v11630 = v11472->cache_age;
    int v11631 = v11630[v11651];
    int v11778 = v11631 + ((int)((unsigned int)(v11631 - v11627) >> 31));
    v11630[v11651] = v11778;
    int * v11633 = v11472->cache_age;
    v11633[v11746] = 0;
    v11636 = v11746;
  }
  int * v11637 = v11472->cache_vals;
  int v11781 = (v11636 * 2) + (((int)((unsigned int)v11476 >> 2)) & 1);
  v11637[v11781] = v11477;
  int * v11639 = v11472->cache_dirty;
  v11639[v11636] = 1;
  struct StateT * v11641 = slot_224(v11472);
  return v11641;
}

struct StateT * slot_34(struct StateT * v4084) {
  int v4085 = v4084->timer;
  int v4092 = v4085 + 1;
  v4084->timer = v4092;
  int * v4087 = v4084->regs;
  int v4088 = v4087[31];
  int v4096 = (int)((unsigned int)v4088 >> 19);
  v4087[29] = v4096;
  struct StateT * v4090 = slot_35(v4084);
  return v4090;
}

struct StateT * slot_171(struct StateT * v10242) {
  int v10243 = v10242->timer;
  int v10255 = v10243 + 1;
  v10242->timer = v10255;
  int * v10245 = v10242->regs;
  int v10246 = v10245[28];
  int v10247 = v10245[5];
  bool v10259 = (v10246 ^ -2147483648) < (v10247 ^ -2147483648);
  int v10250;
  if (v10259) {
    v10250 = 1;
  } else {
    v10250 = 0;
  }
  int * v10251 = v10242->regs;
  v10251[5] = v10250;
  struct StateT * v10253 = slot_162(v10242);
  return v10253;
}

struct StateT * slot_162(struct StateT * v9062) {
  int v9063 = v9062->timer;
  int v9233 = v9063 + 1;
  v9062->timer = v9233;
  int * v9065 = v9062->regs;
  int v9066 = v9065[10];
  int v9067 = v9065[17];
  int * v9068 = v9062->cache_tags;
  int v9238 = (((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2;
  int v9069 = v9068[v9238];
  int v9239 = ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9070 = v9068[v9239];
  int v9240 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2);
  int v9071 = v9068[v9240];
  int v9241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9072 = v9068[v9241];
  int v9073 = v9062->timer;
  int v9242 = v9073 + ((100 ^ (((~(((v9071 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9071 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9069 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9069 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9070 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9070 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9071 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9071 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9062->timer = v9242;
  bool v9243 = !(((~(((v9069 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9069 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9070 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9070 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v9167;
  if (v9243) {
    int * v9075 = v9062->cache_age;
    int v9245 = ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v9070 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9070 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v9076 = v9075[v9245];
    int v9077 = v9075[v9238];
    int v9246 = v9077 + ((int)((unsigned int)(v9077 - v9076) >> 31));
    v9075[v9238] = v9246;
    int * v9079 = v9062->cache_age;
    int v9080 = v9079[v9239];
    int v9248 = v9080 + ((int)((unsigned int)(v9080 - v9076) >> 31));
    v9079[v9239] = v9248;
    int * v9082 = v9062->cache_age;
    v9082[v9245] = 0;
    v9167 = v9245;
  } else {
    int * v9085 = v9062->cache_age;
    int v9252 = (((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2;
    int v9086 = v9085[v9252];
    int * v9087 = v9062->cache_tags;
    int v9088 = v9087[v9252];
    int v9089 = v9085[v9239];
    int v9090 = v9087[v9239];
    bool v9254 = !(((~(((v9071 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9071 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v9144;
    if (v9254) {
      int * v9091 = v9062->cache_age;
      int v9256 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9072 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v9092 = v9091[v9256];
      int v9093 = v9091[v9240];
      int v9257 = v9093 + ((int)((unsigned int)(v9093 - v9092) >> 31));
      v9091[v9240] = v9257;
      int * v9095 = v9062->cache_age;
      int v9096 = v9095[v9241];
      int v9259 = v9096 + ((int)((unsigned int)(v9096 - v9092) >> 31));
      v9095[v9241] = v9259;
      int * v9098 = v9062->cache_age;
      v9098[v9256] = 0;
      v9144 = v9256;
    } else {
      int * v9101 = v9062->cache_age;
      int v9263 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2);
      int v9102 = v9101[v9263];
      int * v9103 = v9062->cache_tags;
      int v9104 = v9103[v9263];
      int v9105 = v9101[v9241];
      int v9106 = v9103[v9241];
      int * v9107 = v9062->cache_dirty;
      int v9266 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9102 + ((~(((v9104 ^ -1) | (-(v9104 ^ -1))) >> 31)) & 2)) - (v9105 + ((~(((v9106 ^ -1) | (-(v9106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9108 = v9107[v9266];
      bool v9267 = !(v9108 == 0);
      if (v9267) {
        int * v9109 = v9062->cache_tags;
        int v9110 = v9109[v9266];
        int * v9111 = v9062->cache_vals;
        int v9270 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9102 + ((~(((v9104 ^ -1) | (-(v9104 ^ -1))) >> 31)) & 2)) - (v9105 + ((~(((v9106 ^ -1) | (-(v9106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9112 = v9111[v9270];
        int v9271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9102 + ((~(((v9104 ^ -1) | (-(v9104 ^ -1))) >> 31)) & 2)) - (v9105 + ((~(((v9106 ^ -1) | (-(v9106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9113 = v9111[v9271];
        int * v9114 = v9062->mem;
        int v9273 = v9110 * 2;
        v9114[v9273] = v9112;
        int * v9116 = v9062->mem;
        int v9276 = (v9110 * 2) + 1;
        v9116[v9276] = v9113;
        ;
      } else {
        ;
      }
      int * v9121 = v9062->mem;
      int v9281 = ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) * 2;
      int v9122 = v9121[v9281];
      int v9282 = (((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) * 2) + 1;
      int v9123 = v9121[v9282];
      int * v9124 = v9062->cache_vals;
      int v9284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9102 + ((~(((v9104 ^ -1) | (-(v9104 ^ -1))) >> 31)) & 2)) - (v9105 + ((~(((v9106 ^ -1) | (-(v9106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9124[v9284] = v9122;
      int * v9126 = v9062->cache_vals;
      int v9287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9102 + ((~(((v9104 ^ -1) | (-(v9104 ^ -1))) >> 31)) & 2)) - (v9105 + ((~(((v9106 ^ -1) | (-(v9106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9126[v9287] = v9123;
      int * v9128 = v9062->cache_tags;
      int v9290 = (int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1);
      v9128[v9266] = v9290;
      int * v9130 = v9062->cache_dirty;
      v9130[v9266] = 0;
      int * v9132 = v9062->cache_age;
      v9132[v9266] = 1;
      int * v9134 = v9062->cache_age;
      int v9135 = v9134[v9266];
      int v9136 = v9134[v9240];
      int v9296 = v9136 + ((int)((unsigned int)(v9136 - v9135) >> 31));
      v9134[v9240] = v9296;
      int * v9138 = v9062->cache_age;
      int v9139 = v9138[v9241];
      int v9298 = v9139 + ((int)((unsigned int)(v9139 - v9135) >> 31));
      v9138[v9241] = v9298;
      int * v9141 = v9062->cache_age;
      v9141[v9266] = 0;
      v9144 = v9266;
    }
    int * v9145 = v9062->cache_vals;
    int v9301 = v9144 * 2;
    int v9146 = v9145[v9301];
    int v9302 = (v9144 * 2) + 1;
    int v9147 = v9145[v9302];
    int v9303 = (((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9145[v9303] = v9146;
    int * v9149 = v9062->cache_vals;
    int v9306 = ((((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9149[v9306] = v9147;
    int * v9151 = v9062->cache_tags;
    int v9309 = ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9310 = (int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1);
    v9151[v9309] = v9310;
    int * v9153 = v9062->cache_dirty;
    v9153[v9309] = 0;
    int * v9155 = v9062->cache_age;
    v9155[v9309] = 1;
    int * v9157 = v9062->cache_age;
    int v9158 = v9157[v9309];
    int v9159 = v9157[v9238];
    int v9316 = v9159 + ((int)((unsigned int)(v9159 - v9158) >> 31));
    v9157[v9238] = v9316;
    int * v9161 = v9062->cache_age;
    int v9162 = v9161[v9239];
    int v9318 = v9162 + ((int)((unsigned int)(v9162 - v9158) >> 31));
    v9161[v9239] = v9318;
    int * v9164 = v9062->cache_age;
    v9164[v9309] = 0;
    v9167 = v9309;
  }
  int * v9168 = v9062->cache_vals;
  int v9321 = (v9167 * 2) + (((int)((unsigned int)(v9066 + 24) >> 2)) & 1);
  v9168[v9321] = v9067;
  int * v9170 = v9062->cache_tags;
  int v9171 = v9170[v9240];
  int v9172 = v9170[v9241];
  bool v9324 = !(((~(((v9171 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9171 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9172 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9172 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v9226;
  if (v9324) {
    int * v9173 = v9062->cache_age;
    int v9326 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9172 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))) | (-(v9172 ^ ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v9174 = v9173[v9326];
    int v9175 = v9173[v9240];
    int v9327 = v9175 + ((int)((unsigned int)(v9175 - v9174) >> 31));
    v9173[v9240] = v9327;
    int * v9177 = v9062->cache_age;
    int v9178 = v9177[v9241];
    int v9329 = v9178 + ((int)((unsigned int)(v9178 - v9174) >> 31));
    v9177[v9241] = v9329;
    int * v9180 = v9062->cache_age;
    v9180[v9326] = 0;
    v9226 = v9326;
  } else {
    int * v9183 = v9062->cache_age;
    int v9333 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2);
    int v9184 = v9183[v9333];
    int * v9185 = v9062->cache_tags;
    int v9186 = v9185[v9333];
    int v9187 = v9183[v9241];
    int v9188 = v9185[v9241];
    int * v9189 = v9062->cache_dirty;
    int v9336 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9184 + ((~(((v9186 ^ -1) | (-(v9186 ^ -1))) >> 31)) & 2)) - (v9187 + ((~(((v9188 ^ -1) | (-(v9188 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9190 = v9189[v9336];
    bool v9337 = !(v9190 == 0);
    if (v9337) {
      int * v9191 = v9062->cache_tags;
      int v9192 = v9191[v9336];
      int * v9193 = v9062->cache_vals;
      int v9340 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9184 + ((~(((v9186 ^ -1) | (-(v9186 ^ -1))) >> 31)) & 2)) - (v9187 + ((~(((v9188 ^ -1) | (-(v9188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9194 = v9193[v9340];
      int v9341 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9184 + ((~(((v9186 ^ -1) | (-(v9186 ^ -1))) >> 31)) & 2)) - (v9187 + ((~(((v9188 ^ -1) | (-(v9188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9195 = v9193[v9341];
      int * v9196 = v9062->mem;
      int v9343 = v9192 * 2;
      v9196[v9343] = v9194;
      int * v9198 = v9062->mem;
      int v9346 = (v9192 * 2) + 1;
      v9198[v9346] = v9195;
      ;
    } else {
      ;
    }
    int * v9203 = v9062->mem;
    int v9351 = ((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) * 2;
    int v9204 = v9203[v9351];
    int v9352 = (((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) * 2) + 1;
    int v9205 = v9203[v9352];
    int * v9206 = v9062->cache_vals;
    int v9354 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9184 + ((~(((v9186 ^ -1) | (-(v9186 ^ -1))) >> 31)) & 2)) - (v9187 + ((~(((v9188 ^ -1) | (-(v9188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9206[v9354] = v9204;
    int * v9208 = v9062->cache_vals;
    int v9357 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9184 + ((~(((v9186 ^ -1) | (-(v9186 ^ -1))) >> 31)) & 2)) - (v9187 + ((~(((v9188 ^ -1) | (-(v9188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9208[v9357] = v9205;
    int * v9210 = v9062->cache_tags;
    int v9360 = (int)((unsigned int)((int)((unsigned int)(v9066 + 24) >> 2)) >> 1);
    v9210[v9336] = v9360;
    int * v9212 = v9062->cache_dirty;
    v9212[v9336] = 0;
    int * v9214 = v9062->cache_age;
    v9214[v9336] = 1;
    int * v9216 = v9062->cache_age;
    int v9217 = v9216[v9336];
    int v9218 = v9216[v9240];
    int v9366 = v9218 + ((int)((unsigned int)(v9218 - v9217) >> 31));
    v9216[v9240] = v9366;
    int * v9220 = v9062->cache_age;
    int v9221 = v9220[v9241];
    int v9368 = v9221 + ((int)((unsigned int)(v9221 - v9217) >> 31));
    v9220[v9241] = v9368;
    int * v9223 = v9062->cache_age;
    v9223[v9336] = 0;
    v9226 = v9336;
  }
  int * v9227 = v9062->cache_vals;
  int v9371 = (v9226 * 2) + (((int)((unsigned int)(v9066 + 24) >> 2)) & 1);
  v9227[v9371] = v9067;
  int * v9229 = v9062->cache_dirty;
  v9229[v9226] = 1;
  struct StateT * v9231 = slot_164(v9062);
  return v9231;
}

struct StateT * slot_21(struct StateT * v2383) {
  int v2384 = v2383->timer;
  int v2396 = v2384 + 1;
  v2383->timer = v2396;
  int * v2386 = v2383->regs;
  int v2387 = v2386[17];
  int v2388 = v2386[7];
  bool v2400 = (v2387 ^ -2147483648) < (v2388 ^ -2147483648);
  int v2391;
  if (v2400) {
    v2391 = 1;
  } else {
    v2391 = 0;
  }
  int * v2392 = v2383->regs;
  v2392[5] = v2391;
  struct StateT * v2394 = slot_22(v2383);
  return v2394;
}

struct StateT * slot_239(struct StateT * v14340) {
  int v14341 = v14340->timer;
  int v14347 = v14341 + 1;
  v14340->timer = v14347;
  int * v14343 = v14340->regs;
  v14343[17] = 19;
  struct StateT * v14345 = slot_240(v14340);
  return v14345;
}

struct StateT * slot_118(struct StateT * v7252) {
  int v7253 = v7252->timer;
  int v7261 = v7253 + 1;
  v7252->timer = v7261;
  int * v7255 = v7252->regs;
  int v7256 = v7255[7];
  int v7257 = v7255[16];
  int v7266 = v7256 & v7257;
  v7255[29] = v7266;
  struct StateT * v7259 = slot_120(v7252);
  return v7259;
}

struct StateT * slot_121(struct StateT * v7899) {
  int v7900 = v7899->timer;
  int v7907 = v7900 + 1;
  v7899->timer = v7907;
  int * v7902 = v7899->regs;
  int v7903 = v7902[28];
  int v7911 = (int)((unsigned int)v7903 >> 19);
  v7902[17] = v7911;
  struct StateT * v7905 = slot_122(v7899);
  return v7905;
}

struct StateT * slot_144(struct StateT * v8673) {
  int v8674 = v8673->timer;
  int v8686 = v8674 + 1;
  v8673->timer = v8686;
  int * v8676 = v8673->regs;
  int v8677 = v8676[29];
  int v8678 = v8676[31];
  bool v8690 = (v8677 ^ -2147483648) < (v8678 ^ -2147483648);
  int v8681;
  if (v8690) {
    v8681 = 1;
  } else {
    v8681 = 0;
  }
  int * v8682 = v8673->regs;
  v8682[6] = v8681;
  struct StateT * v8684 = slot_145(v8673);
  return v8684;
}

struct StateT * slot_201(struct StateT * v11024) {
  int v11025 = v11024->timer;
  int v11033 = v11025 + 1;
  v11024->timer = v11033;
  int * v11027 = v11024->regs;
  int v11028 = v11027[12];
  int v11029 = v11027[5];
  int v11037 = v11028 + v11029;
  v11027[5] = v11037;
  struct StateT * v11031 = slot_202(v11024);
  return v11031;
}

struct StateT * slot_94(struct StateT * v6449) {
  int v6450 = v6449->timer;
  int v6458 = v6450 + 1;
  v6449->timer = v6458;
  int * v6452 = v6449->regs;
  int v6453 = v6452[6];
  int v6454 = v6452[7];
  int v6463 = v6453 + v6454;
  v6452[17] = v6463;
  struct StateT * v6456 = slot_95(v6449);
  return v6456;
}

struct StateT * slot_63(struct StateT * v4596) {
  int v4597 = v4596->timer;
  int v4605 = v4597 + 1;
  v4596->timer = v4605;
  int * v4599 = v4596->regs;
  int v4600 = v4599[6];
  int v4601 = v4599[30];
  int v4609 = v4600 + v4601;
  v4599[6] = v4609;
  struct StateT * v4603 = slot_64(v4596);
  return v4603;
}

struct StateT * slot_146(struct StateT * v8715) {
  int v8716 = v8715->timer;
  int v8724 = v8716 + 1;
  v8715->timer = v8724;
  int * v8718 = v8715->regs;
  int v8719 = v8718[8];
  int v8720 = v8718[6];
  int v8728 = v8719 + v8720;
  v8718[6] = v8728;
  struct StateT * v8722 = slot_147(v8715);
  return v8722;
}

struct StateT * slot_24(struct StateT * v2439) {
  int v2440 = v2439->timer;
  int v2448 = v2440 + 1;
  v2439->timer = v2448;
  int * v2442 = v2439->regs;
  int v2443 = v2442[28];
  int v2444 = v2442[5];
  int v2452 = v2443 + v2444;
  v2442[5] = v2452;
  struct StateT * v2446 = slot_25(v2439);
  return v2446;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -16;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_195(struct StateT * v10911) {
  int v10912 = v10911->timer;
  int v10924 = v10912 + 1;
  v10911->timer = v10924;
  int * v10914 = v10911->regs;
  int v10915 = v10914[12];
  int v10916 = v10914[8];
  bool v10928 = (v10915 ^ -2147483648) < (v10916 ^ -2147483648);
  int v10919;
  if (v10928) {
    v10919 = 1;
  } else {
    v10919 = 0;
  }
  int * v10920 = v10911->regs;
  v10920[28] = v10919;
  struct StateT * v10922 = slot_196(v10911);
  return v10922;
}

struct StateT * slot_125(struct StateT * v7914) {
  int v7915 = v7914->timer;
  int v8025 = v7915 + 1;
  v7914->timer = v8025;
  int * v7917 = v7914->regs;
  int v7918 = v7917[11];
  int * v7919 = v7914->cache_tags;
  int v8029 = (((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2;
  int v7920 = v7919[v8029];
  int v8030 = ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7921 = v7919[v8030];
  int v8031 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2);
  int v7922 = v7919[v8031];
  int v8032 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7923 = v7919[v8032];
  int v7924 = v7914->timer;
  int v8033 = v7924 + ((100 ^ (((~(((v7922 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7922 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7920 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7920 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7921 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7921 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7922 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7922 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7914->timer = v8033;
  int * v7926 = v7914->cache_vals;
  bool v8034 = !(((~(((v7920 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7920 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7921 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7921 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v8019;
  if (v8034) {
    int * v7927 = v7914->cache_age;
    int v8036 = ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v7921 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7921 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7928 = v7927[v8036];
    int v7929 = v7927[v8029];
    int v8037 = v7929 + ((int)((unsigned int)(v7929 - v7928) >> 31));
    v7927[v8029] = v8037;
    int * v7931 = v7914->cache_age;
    int v7932 = v7931[v8030];
    int v8039 = v7932 + ((int)((unsigned int)(v7932 - v7928) >> 31));
    v7931[v8030] = v8039;
    int * v7934 = v7914->cache_age;
    v7934[v8036] = 0;
    v8019 = v8036;
  } else {
    int * v7937 = v7914->cache_age;
    int v8043 = (((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2;
    int v7938 = v7937[v8043];
    int * v7939 = v7914->cache_tags;
    int v7940 = v7939[v8043];
    int v7941 = v7937[v8030];
    int v7942 = v7939[v8030];
    bool v8045 = !(((~(((v7922 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7922 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v7996;
    if (v8045) {
      int * v7943 = v7914->cache_age;
      int v8047 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))) | (-(v7923 ^ ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v7944 = v7943[v8047];
      int v7945 = v7943[v8031];
      int v8048 = v7945 + ((int)((unsigned int)(v7945 - v7944) >> 31));
      v7943[v8031] = v8048;
      int * v7947 = v7914->cache_age;
      int v7948 = v7947[v8032];
      int v8050 = v7948 + ((int)((unsigned int)(v7948 - v7944) >> 31));
      v7947[v8032] = v8050;
      int * v7950 = v7914->cache_age;
      v7950[v8047] = 0;
      v7996 = v8047;
    } else {
      int * v7953 = v7914->cache_age;
      int v8054 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2);
      int v7954 = v7953[v8054];
      int * v7955 = v7914->cache_tags;
      int v7956 = v7955[v8054];
      int v7957 = v7953[v8032];
      int v7958 = v7955[v8032];
      int * v7959 = v7914->cache_dirty;
      int v8057 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7954 + ((~(((v7956 ^ -1) | (-(v7956 ^ -1))) >> 31)) & 2)) - (v7957 + ((~(((v7958 ^ -1) | (-(v7958 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7960 = v7959[v8057];
      bool v8058 = !(v7960 == 0);
      if (v8058) {
        int * v7961 = v7914->cache_tags;
        int v7962 = v7961[v8057];
        int * v7963 = v7914->cache_vals;
        int v8061 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7954 + ((~(((v7956 ^ -1) | (-(v7956 ^ -1))) >> 31)) & 2)) - (v7957 + ((~(((v7958 ^ -1) | (-(v7958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7964 = v7963[v8061];
        int v8062 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7954 + ((~(((v7956 ^ -1) | (-(v7956 ^ -1))) >> 31)) & 2)) - (v7957 + ((~(((v7958 ^ -1) | (-(v7958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7965 = v7963[v8062];
        int * v7966 = v7914->mem;
        int v8064 = v7962 * 2;
        v7966[v8064] = v7964;
        int * v7968 = v7914->mem;
        int v8067 = (v7962 * 2) + 1;
        v7968[v8067] = v7965;
        ;
      } else {
        ;
      }
      int * v7973 = v7914->mem;
      int v8072 = ((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) * 2;
      int v7974 = v7973[v8072];
      int v8073 = (((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) * 2) + 1;
      int v7975 = v7973[v8073];
      int * v7976 = v7914->cache_vals;
      int v8075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7954 + ((~(((v7956 ^ -1) | (-(v7956 ^ -1))) >> 31)) & 2)) - (v7957 + ((~(((v7958 ^ -1) | (-(v7958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7976[v8075] = v7974;
      int * v7978 = v7914->cache_vals;
      int v8078 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7954 + ((~(((v7956 ^ -1) | (-(v7956 ^ -1))) >> 31)) & 2)) - (v7957 + ((~(((v7958 ^ -1) | (-(v7958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7978[v8078] = v7975;
      int * v7980 = v7914->cache_tags;
      int v8081 = (int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1);
      v7980[v8057] = v8081;
      int * v7982 = v7914->cache_dirty;
      v7982[v8057] = 0;
      int * v7984 = v7914->cache_age;
      v7984[v8057] = 1;
      int * v7986 = v7914->cache_age;
      int v7987 = v7986[v8057];
      int v7988 = v7986[v8031];
      int v8087 = v7988 + ((int)((unsigned int)(v7988 - v7987) >> 31));
      v7986[v8031] = v8087;
      int * v7990 = v7914->cache_age;
      int v7991 = v7990[v8032];
      int v8089 = v7991 + ((int)((unsigned int)(v7991 - v7987) >> 31));
      v7990[v8032] = v8089;
      int * v7993 = v7914->cache_age;
      v7993[v8057] = 0;
      v7996 = v8057;
    }
    int * v7997 = v7914->cache_vals;
    int v8092 = v7996 * 2;
    int v7998 = v7997[v8092];
    int v8093 = (v7996 * 2) + 1;
    int v7999 = v7997[v8093];
    int v8094 = (((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7938 + ((~(((v7940 ^ -1) | (-(v7940 ^ -1))) >> 31)) & 2)) - (v7941 + ((~(((v7942 ^ -1) | (-(v7942 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7997[v8094] = v7998;
    int * v8001 = v7914->cache_vals;
    int v8097 = ((((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7938 + ((~(((v7940 ^ -1) | (-(v7940 ^ -1))) >> 31)) & 2)) - (v7941 + ((~(((v7942 ^ -1) | (-(v7942 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8001[v8097] = v7999;
    int * v8003 = v7914->cache_tags;
    int v8100 = ((((int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7938 + ((~(((v7940 ^ -1) | (-(v7940 ^ -1))) >> 31)) & 2)) - (v7941 + ((~(((v7942 ^ -1) | (-(v7942 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8101 = (int)((unsigned int)((int)((unsigned int)(v7918 + 28) >> 2)) >> 1);
    v8003[v8100] = v8101;
    int * v8005 = v7914->cache_dirty;
    v8005[v8100] = 0;
    int * v8007 = v7914->cache_age;
    v8007[v8100] = 1;
    int * v8009 = v7914->cache_age;
    int v8010 = v8009[v8100];
    int v8011 = v8009[v8029];
    int v8107 = v8011 + ((int)((unsigned int)(v8011 - v8010) >> 31));
    v8009[v8029] = v8107;
    int * v8013 = v7914->cache_age;
    int v8014 = v8013[v8030];
    int v8109 = v8014 + ((int)((unsigned int)(v8014 - v8010) >> 31));
    v8013[v8030] = v8109;
    int * v8016 = v7914->cache_age;
    v8016[v8100] = 0;
    v8019 = v8100;
  }
  int v8112 = (v8019 * 2) + (((int)((unsigned int)(v7918 + 28) >> 2)) & 1);
  int v8020 = v7926[v8112];
  int * v8021 = v7914->regs;
  v8021[29] = v8020;
  struct StateT * v8023 = slot_127(v7914);
  return v8023;
}

struct StateT * slot_148(struct StateT * v8747) {
  int v8748 = v8747->timer;
  int v8756 = v8748 + 1;
  v8747->timer = v8756;
  int * v8750 = v8747->regs;
  int v8751 = v8750[9];
  int v8752 = v8750[6];
  int v8761 = v8751 + v8752;
  v8750[5] = v8761;
  struct StateT * v8754 = slot_149(v8747);
  return v8754;
}

struct StateT * slot_126(struct StateT * v8118) {
  int v8119 = v8118->timer;
  int v8131 = v8119 + 1;
  v8118->timer = v8131;
  int * v8121 = v8118->regs;
  int v8122 = v8121[28];
  int v8123 = v8121[5];
  bool v8135 = (v8122 ^ -2147483648) < (v8123 ^ -2147483648);
  int v8126;
  if (v8135) {
    v8126 = 1;
  } else {
    v8126 = 0;
  }
  int * v8127 = v8118->regs;
  v8127[5] = v8126;
  struct StateT * v8129 = slot_117(v8118);
  return v8129;
}

struct StateT * slot_223(struct StateT * v11787) {
  int v11788 = v11787->timer;
  int v11796 = v11788 + 1;
  v11787->timer = v11796;
  int * v11790 = v11787->regs;
  int v11791 = v11790[17];
  int v11792 = v11790[16];
  int v11800 = v11791 & v11792;
  v11790[16] = v11800;
  struct StateT * v11794 = slot_225(v11787);
  return v11794;
}

struct StateT * slot_79(struct StateT * v6077) {
  int v6078 = v6077->timer;
  int v6188 = v6078 + 1;
  v6077->timer = v6188;
  int * v6080 = v6077->regs;
  int v6081 = v6080[11];
  int * v6082 = v6077->cache_tags;
  int v6192 = (((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2;
  int v6083 = v6082[v6192];
  int v6193 = ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6084 = v6082[v6193];
  int v6194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2);
  int v6085 = v6082[v6194];
  int v6195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6086 = v6082[v6195];
  int v6087 = v6077->timer;
  int v6196 = v6087 + ((100 ^ (((~(((v6085 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6085 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6083 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6083 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6084 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6084 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6085 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6085 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6077->timer = v6196;
  int * v6089 = v6077->cache_vals;
  bool v6197 = !(((~(((v6083 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6083 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6084 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6084 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v6182;
  if (v6197) {
    int * v6090 = v6077->cache_age;
    int v6199 = ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v6084 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6084 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v6091 = v6090[v6199];
    int v6092 = v6090[v6192];
    int v6200 = v6092 + ((int)((unsigned int)(v6092 - v6091) >> 31));
    v6090[v6192] = v6200;
    int * v6094 = v6077->cache_age;
    int v6095 = v6094[v6193];
    int v6202 = v6095 + ((int)((unsigned int)(v6095 - v6091) >> 31));
    v6094[v6193] = v6202;
    int * v6097 = v6077->cache_age;
    v6097[v6199] = 0;
    v6182 = v6199;
  } else {
    int * v6100 = v6077->cache_age;
    int v6206 = (((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2;
    int v6101 = v6100[v6206];
    int * v6102 = v6077->cache_tags;
    int v6103 = v6102[v6206];
    int v6104 = v6100[v6193];
    int v6105 = v6102[v6193];
    bool v6208 = !(((~(((v6085 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6085 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v6159;
    if (v6208) {
      int * v6106 = v6077->cache_age;
      int v6210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))) | (-(v6086 ^ ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v6107 = v6106[v6210];
      int v6108 = v6106[v6194];
      int v6211 = v6108 + ((int)((unsigned int)(v6108 - v6107) >> 31));
      v6106[v6194] = v6211;
      int * v6110 = v6077->cache_age;
      int v6111 = v6110[v6195];
      int v6213 = v6111 + ((int)((unsigned int)(v6111 - v6107) >> 31));
      v6110[v6195] = v6213;
      int * v6113 = v6077->cache_age;
      v6113[v6210] = 0;
      v6159 = v6210;
    } else {
      int * v6116 = v6077->cache_age;
      int v6217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2);
      int v6117 = v6116[v6217];
      int * v6118 = v6077->cache_tags;
      int v6119 = v6118[v6217];
      int v6120 = v6116[v6195];
      int v6121 = v6118[v6195];
      int * v6122 = v6077->cache_dirty;
      int v6220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6117 + ((~(((v6119 ^ -1) | (-(v6119 ^ -1))) >> 31)) & 2)) - (v6120 + ((~(((v6121 ^ -1) | (-(v6121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6123 = v6122[v6220];
      bool v6221 = !(v6123 == 0);
      if (v6221) {
        int * v6124 = v6077->cache_tags;
        int v6125 = v6124[v6220];
        int * v6126 = v6077->cache_vals;
        int v6224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6117 + ((~(((v6119 ^ -1) | (-(v6119 ^ -1))) >> 31)) & 2)) - (v6120 + ((~(((v6121 ^ -1) | (-(v6121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6127 = v6126[v6224];
        int v6225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6117 + ((~(((v6119 ^ -1) | (-(v6119 ^ -1))) >> 31)) & 2)) - (v6120 + ((~(((v6121 ^ -1) | (-(v6121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6128 = v6126[v6225];
        int * v6129 = v6077->mem;
        int v6227 = v6125 * 2;
        v6129[v6227] = v6127;
        int * v6131 = v6077->mem;
        int v6230 = (v6125 * 2) + 1;
        v6131[v6230] = v6128;
        ;
      } else {
        ;
      }
      int * v6136 = v6077->mem;
      int v6235 = ((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) * 2;
      int v6137 = v6136[v6235];
      int v6236 = (((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) * 2) + 1;
      int v6138 = v6136[v6236];
      int * v6139 = v6077->cache_vals;
      int v6238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6117 + ((~(((v6119 ^ -1) | (-(v6119 ^ -1))) >> 31)) & 2)) - (v6120 + ((~(((v6121 ^ -1) | (-(v6121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6139[v6238] = v6137;
      int * v6141 = v6077->cache_vals;
      int v6241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6117 + ((~(((v6119 ^ -1) | (-(v6119 ^ -1))) >> 31)) & 2)) - (v6120 + ((~(((v6121 ^ -1) | (-(v6121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6141[v6241] = v6138;
      int * v6143 = v6077->cache_tags;
      int v6244 = (int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1);
      v6143[v6220] = v6244;
      int * v6145 = v6077->cache_dirty;
      v6145[v6220] = 0;
      int * v6147 = v6077->cache_age;
      v6147[v6220] = 1;
      int * v6149 = v6077->cache_age;
      int v6150 = v6149[v6220];
      int v6151 = v6149[v6194];
      int v6250 = v6151 + ((int)((unsigned int)(v6151 - v6150) >> 31));
      v6149[v6194] = v6250;
      int * v6153 = v6077->cache_age;
      int v6154 = v6153[v6195];
      int v6252 = v6154 + ((int)((unsigned int)(v6154 - v6150) >> 31));
      v6153[v6195] = v6252;
      int * v6156 = v6077->cache_age;
      v6156[v6220] = 0;
      v6159 = v6220;
    }
    int * v6160 = v6077->cache_vals;
    int v6255 = v6159 * 2;
    int v6161 = v6160[v6255];
    int v6256 = (v6159 * 2) + 1;
    int v6162 = v6160[v6256];
    int v6257 = (((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6101 + ((~(((v6103 ^ -1) | (-(v6103 ^ -1))) >> 31)) & 2)) - (v6104 + ((~(((v6105 ^ -1) | (-(v6105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6160[v6257] = v6161;
    int * v6164 = v6077->cache_vals;
    int v6260 = ((((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6101 + ((~(((v6103 ^ -1) | (-(v6103 ^ -1))) >> 31)) & 2)) - (v6104 + ((~(((v6105 ^ -1) | (-(v6105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6164[v6260] = v6162;
    int * v6166 = v6077->cache_tags;
    int v6263 = ((((int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6101 + ((~(((v6103 ^ -1) | (-(v6103 ^ -1))) >> 31)) & 2)) - (v6104 + ((~(((v6105 ^ -1) | (-(v6105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6264 = (int)((unsigned int)((int)((unsigned int)(v6081 + 16) >> 2)) >> 1);
    v6166[v6263] = v6264;
    int * v6168 = v6077->cache_dirty;
    v6168[v6263] = 0;
    int * v6170 = v6077->cache_age;
    v6170[v6263] = 1;
    int * v6172 = v6077->cache_age;
    int v6173 = v6172[v6263];
    int v6174 = v6172[v6192];
    int v6270 = v6174 + ((int)((unsigned int)(v6174 - v6173) >> 31));
    v6172[v6192] = v6270;
    int * v6176 = v6077->cache_age;
    int v6177 = v6176[v6193];
    int v6272 = v6177 + ((int)((unsigned int)(v6177 - v6173) >> 31));
    v6176[v6193] = v6272;
    int * v6179 = v6077->cache_age;
    v6179[v6263] = 0;
    v6182 = v6263;
  }
  int v6275 = (v6182 * 2) + (((int)((unsigned int)(v6081 + 16) >> 2)) & 1);
  int v6183 = v6089[v6275];
  int * v6184 = v6077->regs;
  v6184[6] = v6183;
  struct StateT * v6186 = slot_80(v6077);
  return v6186;
}

struct StateT * slot_237(struct StateT * v14120) {
  int v14121 = v14120->timer;
  int v14129 = v14121 + 1;
  v14120->timer = v14129;
  int * v14123 = v14120->regs;
  int v14124 = v14123[17];
  int v14125 = v14123[13];
  int v14133 = v14124 | v14125;
  v14123[13] = v14133;
  struct StateT * v14127 = slot_239(v14120);
  return v14127;
}

struct StateT * slot_41(struct StateT * v4196) {
  int v4197 = v4196->timer;
  int v4205 = v4197 + 1;
  v4196->timer = v4205;
  int * v4199 = v4196->regs;
  int v4200 = v4199[7];
  int v4201 = v4199[13];
  int v4210 = v4200 * v4201;
  v4199[8] = v4210;
  struct StateT * v4203 = slot_42(v4196);
  return v4203;
}

struct StateT * slot_39(struct StateT * v4162) {
  int v4163 = v4162->timer;
  int v4171 = v4163 + 1;
  v4162->timer = v4171;
  int * v4165 = v4162->regs;
  int v4166 = v4165[28];
  int v4167 = v4165[12];
  int v4176 = v4166 * v4167;
  v4165[30] = v4176;
  struct StateT * v4169 = slot_40(v4162);
  return v4169;
}

struct StateT * slot_142(struct StateT * v8632) {
  int v8633 = v8632->timer;
  int v8645 = v8633 + 1;
  v8632->timer = v8645;
  int * v8635 = v8632->regs;
  int v8636 = v8635[17];
  int v8637 = v8635[6];
  bool v8649 = (v8636 ^ -2147483648) < (v8637 ^ -2147483648);
  int v8640;
  if (v8649) {
    v8640 = 1;
  } else {
    v8640 = 0;
  }
  int * v8641 = v8632->regs;
  v8641[28] = v8640;
  struct StateT * v8643 = slot_143(v8632);
  return v8643;
}

struct StateT * slot_60(struct StateT * v4539) {
  int v4540 = v4539->timer;
  int v4552 = v4540 + 1;
  v4539->timer = v4552;
  int * v4542 = v4539->regs;
  int v4543 = v4542[5];
  int v4544 = v4542[18];
  bool v4556 = (v4543 ^ -2147483648) < (v4544 ^ -2147483648);
  int v4547;
  if (v4556) {
    v4547 = 1;
  } else {
    v4547 = 0;
  }
  int * v4548 = v4539->regs;
  v4548[30] = v4547;
  struct StateT * v4550 = slot_61(v4539);
  return v4550;
}

struct StateT * slot_112(struct StateT * v6793) {
  int * v6794 = v6793->saved_regs;
  int * v6795 = v6793->regs;
  int v6796 = v6795[29];
  v6794[29] = v6796;
  int v6798 = v6793->timer;
  int v6810 = v6798 + 1;
  v6793->timer = v6810;
  int * v6800 = v6793->regs;
  int v6801 = v6800[7];
  int v6802 = v6800[16];
  int v6814 = v6801 & v6802;
  v6800[29] = v6814;
  struct StateT * v6804 = slot_113(v6793);
  return v6804;
}

struct StateT * slot_47(struct StateT * v4294) {
  int v4295 = v4294->timer;
  int v4303 = v4295 + 1;
  v4294->timer = v4303;
  int * v4297 = v4294->regs;
  int v4298 = v4297[7];
  int v4299 = v4297[12];
  int v4307 = v4298 * v4299;
  v4297[7] = v4307;
  struct StateT * v4301 = slot_48(v4294);
  return v4301;
}

struct StateT * slot_214(struct StateT * v11259) {
  int * v11260 = v11259->saved_regs;
  int * v11261 = v11259->regs;
  int v11262 = v11261[15];
  v11260[15] = v11262;
  int v11264 = v11259->timer;
  int v11276 = v11264 + 1;
  v11259->timer = v11276;
  int * v11266 = v11259->regs;
  int v11267 = v11266[15];
  int v11268 = v11266[5];
  int v11279 = v11267 + v11268;
  v11266[15] = v11279;
  struct StateT * v11270 = slot_215(v11259);
  return v11270;
}

struct StateT * slot_29(struct StateT * v3847) {
  int v3848 = v3847->timer;
  int v3958 = v3848 + 1;
  v3847->timer = v3958;
  int * v3850 = v3847->regs;
  int v3851 = v3850[11];
  int * v3852 = v3847->cache_tags;
  int v3962 = (((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2;
  int v3853 = v3852[v3962];
  int v3963 = ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3854 = v3852[v3963];
  int v3964 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2);
  int v3855 = v3852[v3964];
  int v3965 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3856 = v3852[v3965];
  int v3857 = v3847->timer;
  int v3966 = v3857 + ((100 ^ (((~(((v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3847->timer = v3966;
  int * v3859 = v3847->cache_vals;
  bool v3967 = !(((~(((v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3952;
  if (v3967) {
    int * v3860 = v3847->cache_age;
    int v3969 = ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3861 = v3860[v3969];
    int v3862 = v3860[v3962];
    int v3970 = v3862 + ((int)((unsigned int)(v3862 - v3861) >> 31));
    v3860[v3962] = v3970;
    int * v3864 = v3847->cache_age;
    int v3865 = v3864[v3963];
    int v3972 = v3865 + ((int)((unsigned int)(v3865 - v3861) >> 31));
    v3864[v3963] = v3972;
    int * v3867 = v3847->cache_age;
    v3867[v3969] = 0;
    v3952 = v3969;
  } else {
    int * v3870 = v3847->cache_age;
    int v3976 = (((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2;
    int v3871 = v3870[v3976];
    int * v3872 = v3847->cache_tags;
    int v3873 = v3872[v3976];
    int v3874 = v3870[v3963];
    int v3875 = v3872[v3963];
    bool v3978 = !(((~(((v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3929;
    if (v3978) {
      int * v3876 = v3847->cache_age;
      int v3980 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v3877 = v3876[v3980];
      int v3878 = v3876[v3964];
      int v3981 = v3878 + ((int)((unsigned int)(v3878 - v3877) >> 31));
      v3876[v3964] = v3981;
      int * v3880 = v3847->cache_age;
      int v3881 = v3880[v3965];
      int v3983 = v3881 + ((int)((unsigned int)(v3881 - v3877) >> 31));
      v3880[v3965] = v3983;
      int * v3883 = v3847->cache_age;
      v3883[v3980] = 0;
      v3929 = v3980;
    } else {
      int * v3886 = v3847->cache_age;
      int v3987 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3887 = v3886[v3987];
      int * v3888 = v3847->cache_tags;
      int v3889 = v3888[v3987];
      int v3890 = v3886[v3965];
      int v3891 = v3888[v3965];
      int * v3892 = v3847->cache_dirty;
      int v3990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3893 = v3892[v3990];
      bool v3991 = !(v3893 == 0);
      if (v3991) {
        int * v3894 = v3847->cache_tags;
        int v3895 = v3894[v3990];
        int * v3896 = v3847->cache_vals;
        int v3994 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3897 = v3896[v3994];
        int v3995 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3898 = v3896[v3995];
        int * v3899 = v3847->mem;
        int v3997 = v3895 * 2;
        v3899[v3997] = v3897;
        int * v3901 = v3847->mem;
        int v4000 = (v3895 * 2) + 1;
        v3901[v4000] = v3898;
        ;
      } else {
        ;
      }
      int * v3906 = v3847->mem;
      int v4005 = ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) * 2;
      int v3907 = v3906[v4005];
      int v4006 = (((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3908 = v3906[v4006];
      int * v3909 = v3847->cache_vals;
      int v4008 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3909[v4008] = v3907;
      int * v3911 = v3847->cache_vals;
      int v4011 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3911[v4011] = v3908;
      int * v3913 = v3847->cache_tags;
      int v4014 = (int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1);
      v3913[v3990] = v4014;
      int * v3915 = v3847->cache_dirty;
      v3915[v3990] = 0;
      int * v3917 = v3847->cache_age;
      v3917[v3990] = 1;
      int * v3919 = v3847->cache_age;
      int v3920 = v3919[v3990];
      int v3921 = v3919[v3964];
      int v4020 = v3921 + ((int)((unsigned int)(v3921 - v3920) >> 31));
      v3919[v3964] = v4020;
      int * v3923 = v3847->cache_age;
      int v3924 = v3923[v3965];
      int v4022 = v3924 + ((int)((unsigned int)(v3924 - v3920) >> 31));
      v3923[v3965] = v4022;
      int * v3926 = v3847->cache_age;
      v3926[v3990] = 0;
      v3929 = v3990;
    }
    int * v3930 = v3847->cache_vals;
    int v4025 = v3929 * 2;
    int v3931 = v3930[v4025];
    int v4026 = (v3929 * 2) + 1;
    int v3932 = v3930[v4026];
    int v4027 = (((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3871 + ((~(((v3873 ^ -1) | (-(v3873 ^ -1))) >> 31)) & 2)) - (v3874 + ((~(((v3875 ^ -1) | (-(v3875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3930[v4027] = v3931;
    int * v3934 = v3847->cache_vals;
    int v4030 = ((((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3871 + ((~(((v3873 ^ -1) | (-(v3873 ^ -1))) >> 31)) & 2)) - (v3874 + ((~(((v3875 ^ -1) | (-(v3875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3934[v4030] = v3932;
    int * v3936 = v3847->cache_tags;
    int v4033 = ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3871 + ((~(((v3873 ^ -1) | (-(v3873 ^ -1))) >> 31)) & 2)) - (v3874 + ((~(((v3875 ^ -1) | (-(v3875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4034 = (int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1);
    v3936[v4033] = v4034;
    int * v3938 = v3847->cache_dirty;
    v3938[v4033] = 0;
    int * v3940 = v3847->cache_age;
    v3940[v4033] = 1;
    int * v3942 = v3847->cache_age;
    int v3943 = v3942[v4033];
    int v3944 = v3942[v3962];
    int v4040 = v3944 + ((int)((unsigned int)(v3944 - v3943) >> 31));
    v3942[v3962] = v4040;
    int * v3946 = v3847->cache_age;
    int v3947 = v3946[v3963];
    int v4042 = v3947 + ((int)((unsigned int)(v3947 - v3943) >> 31));
    v3946[v3963] = v4042;
    int * v3949 = v3847->cache_age;
    v3949[v4033] = 0;
    v3952 = v4033;
  }
  int v4045 = (v3952 * 2) + (((int)((unsigned int)(v3851 + 12) >> 2)) & 1);
  int v3953 = v3859[v4045];
  int * v3954 = v3847->regs;
  v3954[28] = v3953;
  struct StateT * v3956 = slot_30(v3847);
  return v3956;
}

struct StateT * slot_16(struct StateT * v2294) {
  int v2295 = v2294->timer;
  int v2303 = v2295 + 1;
  v2294->timer = v2303;
  int * v2297 = v2294->regs;
  int v2298 = v2297[14];
  int v2299 = v2297[12];
  int v2307 = v2298 * v2299;
  v2297[14] = v2307;
  struct StateT * v2301 = slot_17(v2294);
  return v2301;
}

struct StateT * slot_245(struct StateT * v14634) {
  int v14635 = v14634->timer;
  int v14643 = v14635 + 1;
  v14634->timer = v14643;
  int * v14637 = v14634->regs;
  int v14638 = v14637[15];
  int v14639 = v14637[5];
  int v14647 = v14638 + v14639;
  v14637[15] = v14647;
  struct StateT * v14641 = slot_246(v14634);
  return v14641;
}

struct StateT * slot_113(struct StateT * v6817) {
  int * v6818 = v6817->saved_regs;
  int * v6819 = v6817->regs;
  int v6820 = v6819[7];
  v6818[7] = v6820;
  int v6822 = v6817->timer;
  int v6833 = v6822 + 1;
  v6817->timer = v6833;
  int * v6824 = v6817->regs;
  int v6825 = v6824[7];
  int v6835 = (int)((unsigned int)v6825 >> 19);
  v6824[7] = v6835;
  struct StateT * v6827 = slot_114(v6817);
  return v6827;
}

struct StateT * slot_151(struct StateT * v8813) {
  int v8814 = v8813->timer;
  int v8822 = v8814 + 1;
  v8813->timer = v8822;
  int * v8816 = v8813->regs;
  int v8817 = v8816[18];
  int v8818 = v8816[6];
  int v8826 = v8817 + v8818;
  v8816[6] = v8826;
  struct StateT * v8820 = slot_152(v8813);
  return v8820;
}

struct StateT * slot_7(struct StateT * v2182) {
  int v2183 = v2182->timer;
  int v2189 = v2183 + 1;
  v2182->timer = v2189;
  int * v2185 = v2182->regs;
  v2185[16] = 524288;
  struct StateT * v2187 = slot_8(v2182);
  return v2187;
}

struct StateT * slot_124(struct StateT * v8202) {
  int v8203 = v8202->timer;
  int v8313 = v8203 + 1;
  v8202->timer = v8313;
  int * v8205 = v8202->regs;
  int v8206 = v8205[11];
  int * v8207 = v8202->cache_tags;
  int v8317 = (((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2;
  int v8208 = v8207[v8317];
  int v8318 = ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8209 = v8207[v8318];
  int v8319 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2);
  int v8210 = v8207[v8319];
  int v8320 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8211 = v8207[v8320];
  int v8212 = v8202->timer;
  int v8321 = v8212 + ((100 ^ (((~(((v8210 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8210 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8208 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8208 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v8209 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8209 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8210 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8210 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8202->timer = v8321;
  int * v8214 = v8202->cache_vals;
  bool v8322 = !(((~(((v8208 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8208 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v8209 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8209 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v8307;
  if (v8322) {
    int * v8215 = v8202->cache_age;
    int v8324 = ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v8209 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8209 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v8216 = v8215[v8324];
    int v8217 = v8215[v8317];
    int v8325 = v8217 + ((int)((unsigned int)(v8217 - v8216) >> 31));
    v8215[v8317] = v8325;
    int * v8219 = v8202->cache_age;
    int v8220 = v8219[v8318];
    int v8327 = v8220 + ((int)((unsigned int)(v8220 - v8216) >> 31));
    v8219[v8318] = v8327;
    int * v8222 = v8202->cache_age;
    v8222[v8324] = 0;
    v8307 = v8324;
  } else {
    int * v8225 = v8202->cache_age;
    int v8331 = (((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2;
    int v8226 = v8225[v8331];
    int * v8227 = v8202->cache_tags;
    int v8228 = v8227[v8331];
    int v8229 = v8225[v8318];
    int v8230 = v8227[v8318];
    bool v8333 = !(((~(((v8210 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8210 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v8284;
    if (v8333) {
      int * v8231 = v8202->cache_age;
      int v8335 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))) | (-(v8211 ^ ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v8232 = v8231[v8335];
      int v8233 = v8231[v8319];
      int v8336 = v8233 + ((int)((unsigned int)(v8233 - v8232) >> 31));
      v8231[v8319] = v8336;
      int * v8235 = v8202->cache_age;
      int v8236 = v8235[v8320];
      int v8338 = v8236 + ((int)((unsigned int)(v8236 - v8232) >> 31));
      v8235[v8320] = v8338;
      int * v8238 = v8202->cache_age;
      v8238[v8335] = 0;
      v8284 = v8335;
    } else {
      int * v8241 = v8202->cache_age;
      int v8342 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2);
      int v8242 = v8241[v8342];
      int * v8243 = v8202->cache_tags;
      int v8244 = v8243[v8342];
      int v8245 = v8241[v8320];
      int v8246 = v8243[v8320];
      int * v8247 = v8202->cache_dirty;
      int v8345 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v8242 + ((~(((v8244 ^ -1) | (-(v8244 ^ -1))) >> 31)) & 2)) - (v8245 + ((~(((v8246 ^ -1) | (-(v8246 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8248 = v8247[v8345];
      bool v8346 = !(v8248 == 0);
      if (v8346) {
        int * v8249 = v8202->cache_tags;
        int v8250 = v8249[v8345];
        int * v8251 = v8202->cache_vals;
        int v8349 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v8242 + ((~(((v8244 ^ -1) | (-(v8244 ^ -1))) >> 31)) & 2)) - (v8245 + ((~(((v8246 ^ -1) | (-(v8246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8252 = v8251[v8349];
        int v8350 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v8242 + ((~(((v8244 ^ -1) | (-(v8244 ^ -1))) >> 31)) & 2)) - (v8245 + ((~(((v8246 ^ -1) | (-(v8246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8253 = v8251[v8350];
        int * v8254 = v8202->mem;
        int v8352 = v8250 * 2;
        v8254[v8352] = v8252;
        int * v8256 = v8202->mem;
        int v8355 = (v8250 * 2) + 1;
        v8256[v8355] = v8253;
        ;
      } else {
        ;
      }
      int * v8261 = v8202->mem;
      int v8360 = ((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) * 2;
      int v8262 = v8261[v8360];
      int v8361 = (((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) * 2) + 1;
      int v8263 = v8261[v8361];
      int * v8264 = v8202->cache_vals;
      int v8363 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v8242 + ((~(((v8244 ^ -1) | (-(v8244 ^ -1))) >> 31)) & 2)) - (v8245 + ((~(((v8246 ^ -1) | (-(v8246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8264[v8363] = v8262;
      int * v8266 = v8202->cache_vals;
      int v8366 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v8242 + ((~(((v8244 ^ -1) | (-(v8244 ^ -1))) >> 31)) & 2)) - (v8245 + ((~(((v8246 ^ -1) | (-(v8246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8266[v8366] = v8263;
      int * v8268 = v8202->cache_tags;
      int v8369 = (int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1);
      v8268[v8345] = v8369;
      int * v8270 = v8202->cache_dirty;
      v8270[v8345] = 0;
      int * v8272 = v8202->cache_age;
      v8272[v8345] = 1;
      int * v8274 = v8202->cache_age;
      int v8275 = v8274[v8345];
      int v8276 = v8274[v8319];
      int v8375 = v8276 + ((int)((unsigned int)(v8276 - v8275) >> 31));
      v8274[v8319] = v8375;
      int * v8278 = v8202->cache_age;
      int v8279 = v8278[v8320];
      int v8377 = v8279 + ((int)((unsigned int)(v8279 - v8275) >> 31));
      v8278[v8320] = v8377;
      int * v8281 = v8202->cache_age;
      v8281[v8345] = 0;
      v8284 = v8345;
    }
    int * v8285 = v8202->cache_vals;
    int v8380 = v8284 * 2;
    int v8286 = v8285[v8380];
    int v8381 = (v8284 * 2) + 1;
    int v8287 = v8285[v8381];
    int v8382 = (((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v8226 + ((~(((v8228 ^ -1) | (-(v8228 ^ -1))) >> 31)) & 2)) - (v8229 + ((~(((v8230 ^ -1) | (-(v8230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8285[v8382] = v8286;
    int * v8289 = v8202->cache_vals;
    int v8385 = ((((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v8226 + ((~(((v8228 ^ -1) | (-(v8228 ^ -1))) >> 31)) & 2)) - (v8229 + ((~(((v8230 ^ -1) | (-(v8230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8289[v8385] = v8287;
    int * v8291 = v8202->cache_tags;
    int v8388 = ((((int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v8226 + ((~(((v8228 ^ -1) | (-(v8228 ^ -1))) >> 31)) & 2)) - (v8229 + ((~(((v8230 ^ -1) | (-(v8230 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8389 = (int)((unsigned int)((int)((unsigned int)(v8206 + 24) >> 2)) >> 1);
    v8291[v8388] = v8389;
    int * v8293 = v8202->cache_dirty;
    v8293[v8388] = 0;
    int * v8295 = v8202->cache_age;
    v8295[v8388] = 1;
    int * v8297 = v8202->cache_age;
    int v8298 = v8297[v8388];
    int v8299 = v8297[v8317];
    int v8395 = v8299 + ((int)((unsigned int)(v8299 - v8298) >> 31));
    v8297[v8317] = v8395;
    int * v8301 = v8202->cache_age;
    int v8302 = v8301[v8318];
    int v8397 = v8302 + ((int)((unsigned int)(v8302 - v8298) >> 31));
    v8301[v8318] = v8397;
    int * v8304 = v8202->cache_age;
    v8304[v8388] = 0;
    v8307 = v8388;
  }
  int v8400 = (v8307 * 2) + (((int)((unsigned int)(v8206 + 24) >> 2)) & 1);
  int v8308 = v8214[v8400];
  int * v8309 = v8202->regs;
  v8309[6] = v8308;
  struct StateT * v8311 = slot_125(v8202);
  return v8311;
}

struct StateT * slot_191(struct StateT * v10837) {
  int v10838 = v10837->timer;
  int v10846 = v10838 + 1;
  v10837->timer = v10846;
  int * v10840 = v10837->regs;
  int v10841 = v10840[31];
  int v10842 = v10840[12];
  int v10850 = v10841 + v10842;
  v10840[12] = v10850;
  struct StateT * v10844 = slot_192(v10837);
  return v10844;
}

struct StateT * slot_103(struct StateT * v6622) {
  int v6623 = v6622->timer;
  int v6631 = v6623 + 1;
  v6622->timer = v6631;
  int * v6625 = v6622->regs;
  int v6626 = v6625[9];
  int v6627 = v6625[6];
  int v6636 = v6626 + v6627;
  v6625[5] = v6636;
  struct StateT * v6629 = slot_104(v6622);
  return v6629;
}

struct StateT * slot_128(struct StateT * v8188) {
  int v8189 = v8188->timer;
  int v8196 = v8189 + 1;
  v8188->timer = v8196;
  int * v8191 = v8188->regs;
  int v8192 = v8191[5];
  int v8199 = v8192 << 13;
  v8191[5] = v8199;
  struct StateT * v8194 = slot_129(v8188);
  return v8194;
}

struct StateT * slot_19(struct StateT * v2351) {
  int v2352 = v2351->timer;
  int v2360 = v2352 + 1;
  v2351->timer = v2360;
  int * v2354 = v2351->regs;
  int v2355 = v2354[7];
  int v2356 = v2354[17];
  int v2364 = v2355 + v2356;
  v2354[17] = v2364;
  struct StateT * v2358 = slot_20(v2351);
  return v2358;
}

struct StateT * slot_87(struct StateT * v6331) {
  int v6332 = v6331->timer;
  int v6340 = v6332 + 1;
  v6331->timer = v6340;
  int * v6334 = v6331->regs;
  int v6335 = v6334[29];
  int v6336 = v6334[12];
  int v6345 = (((((int)((unsigned int)v6335 >> 16)) * ((int)((unsigned int)v6336 >> 16))) + ((int)((unsigned int)((v6335 & 65535) * ((int)((unsigned int)v6336 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6335 >> 16)) * (v6336 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6335 & 65535) * (v6336 & 65535)) >> 16)) + (((v6335 & 65535) * ((int)((unsigned int)v6336 >> 16))) & 65535)) + ((((int)((unsigned int)v6335 >> 16)) * (v6336 & 65535)) & 65535)) >> 16));
  v6334[30] = v6345;
  struct StateT * v6338 = slot_88(v6331);
  return v6338;
}

struct StateT * slot_67(struct StateT * v4668) {
  int * v4669 = v4668->saved_regs;
  int * v4670 = v4668->regs;
  int v4671 = v4670[29];
  v4669[29] = v4671;
  int v4673 = v4668->timer;
  int v4685 = v4673 + 1;
  v4668->timer = v4685;
  int * v4675 = v4668->regs;
  int v4676 = v4675[7];
  int v4677 = v4675[16];
  int v4689 = v4676 & v4677;
  v4675[29] = v4689;
  struct StateT * v4679 = slot_68(v4668);
  return v4679;
}

struct StateT * slot_81(struct StateT * v5993) {
  int v5994 = v5993->timer;
  int v6006 = v5994 + 1;
  v5993->timer = v6006;
  int * v5996 = v5993->regs;
  int v5997 = v5996[28];
  int v5998 = v5996[5];
  bool v6010 = (v5997 ^ -2147483648) < (v5998 ^ -2147483648);
  int v6001;
  if (v6010) {
    v6001 = 1;
  } else {
    v6001 = 0;
  }
  int * v6002 = v5993->regs;
  v6002[5] = v6001;
  struct StateT * v6004 = slot_72(v5993);
  return v6004;
}

struct StateT * slot_95(struct StateT * v6466) {
  int v6467 = v6466->timer;
  int v6479 = v6467 + 1;
  v6466->timer = v6479;
  int * v6469 = v6466->regs;
  int v6470 = v6469[29];
  int v6471 = v6469[28];
  bool v6483 = (v6470 ^ -2147483648) < (v6471 ^ -2147483648);
  int v6474;
  if (v6483) {
    v6474 = 1;
  } else {
    v6474 = 0;
  }
  int * v6475 = v6466->regs;
  v6475[7] = v6474;
  struct StateT * v6477 = slot_96(v6466);
  return v6477;
}

struct StateT * slot_115(struct StateT * v6869) {
  int * v6870 = v6869->saved_regs;
  int v6871 = v6870[7];
  int v6872 = v6870[29];
  bool v6900 = v6871 == v6872;
  struct StateT * v6895;
  if (v6900) {
    int v6873 = v6869->timer;
    int v6901 = v6873 + 15;
    v6869->timer = v6901;
    int * v6875 = v6869->saved_regs;
    int v6876 = v6875[28];
    int * v6877 = v6869->regs;
    v6877[28] = v6876;
    int * v6879 = v6869->saved_regs;
    int v6880 = v6879[29];
    int * v6881 = v6869->regs;
    v6881[29] = v6880;
    int * v6883 = v6869->saved_regs;
    int v6884 = v6883[7];
    int * v6885 = v6869->regs;
    v6885[7] = v6884;
    int * v6887 = v6869->saved_regs;
    int v6888 = v6887[5];
    int * v6889 = v6869->regs;
    v6889[5] = v6888;
    struct StateT * v6891 = slot_116(v6869);
    v6895 = v6891;
  } else {
    struct StateT * v6893 = slot_117(v6869);
    v6895 = v6893;
  }
  return v6895;
}

struct StateT * slot_78(struct StateT * v6047) {
  int v6048 = v6047->timer;
  int v6056 = v6048 + 1;
  v6047->timer = v6056;
  int * v6050 = v6047->regs;
  int v6051 = v6050[6];
  int v6052 = v6050[5];
  int v6060 = v6051 + v6052;
  v6050[5] = v6060;
  struct StateT * v6054 = slot_79(v6047);
  return v6054;
}

struct StateT * slot_32(struct StateT * v3822) {
  int v3823 = v3822->timer;
  int v3835 = v3823 + 1;
  v3822->timer = v3835;
  int * v3825 = v3822->regs;
  int v3826 = v3825[31];
  int v3827 = v3825[29];
  bool v3839 = (v3826 ^ -2147483648) < (v3827 ^ -2147483648);
  int v3830;
  if (v3839) {
    v3830 = 1;
  } else {
    v3830 = 0;
  }
  int * v3831 = v3822->regs;
  v3831[6] = v3830;
  struct StateT * v3833 = slot_33(v3822);
  return v3833;
}

struct StateT * slot_205(struct StateT * v11115) {
  int v11116 = v11115->timer;
  int v11124 = v11116 + 1;
  v11115->timer = v11124;
  int * v11118 = v11115->regs;
  int v11119 = v11118[13];
  int v11120 = v11118[12];
  int v11128 = v11119 + v11120;
  v11118[12] = v11128;
  struct StateT * v11122 = slot_206(v11115);
  return v11122;
}

struct StateT * slot_193(struct StateT * v10870) {
  int v10871 = v10870->timer;
  int v10879 = v10871 + 1;
  v10870->timer = v10879;
  int * v10873 = v10870->regs;
  int v10874 = v10873[8];
  int v10875 = v10873[28];
  int v10884 = v10874 + v10875;
  v10873[12] = v10884;
  struct StateT * v10877 = slot_194(v10870);
  return v10877;
}

struct StateT * slot_233(struct StateT * v14353) {
  int v14354 = v14353->timer;
  int v14464 = v14354 + 1;
  v14353->timer = v14464;
  int * v14356 = v14353->regs;
  int v14357 = v14356[2];
  int * v14358 = v14353->cache_tags;
  int v14468 = (((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2;
  int v14359 = v14358[v14468];
  int v14469 = ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2) + 1;
  int v14360 = v14358[v14469];
  int v14470 = 4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2);
  int v14361 = v14358[v14470];
  int v14471 = (4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14362 = v14358[v14471];
  int v14363 = v14353->timer;
  int v14472 = v14363 + ((100 ^ (((~(((v14361 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14361 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) | (~(((v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14359 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14359 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) | (~(((v14360 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14360 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14361 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14361 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) | (~(((v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31))) & 104)))));
  v14353->timer = v14472;
  int * v14365 = v14353->cache_vals;
  bool v14473 = !(((~(((v14359 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14359 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) | (~(((v14360 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14360 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31))) == 0);
  int v14458;
  if (v14473) {
    int * v14366 = v14353->cache_age;
    int v14475 = ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2) + ((~(((v14360 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14360 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) & 1);
    int v14367 = v14366[v14475];
    int v14368 = v14366[v14468];
    int v14476 = v14368 + ((int)((unsigned int)(v14368 - v14367) >> 31));
    v14366[v14468] = v14476;
    int * v14370 = v14353->cache_age;
    int v14371 = v14370[v14469];
    int v14478 = v14371 + ((int)((unsigned int)(v14371 - v14367) >> 31));
    v14370[v14469] = v14478;
    int * v14373 = v14353->cache_age;
    v14373[v14475] = 0;
    v14458 = v14475;
  } else {
    int * v14376 = v14353->cache_age;
    int v14482 = (((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2;
    int v14377 = v14376[v14482];
    int * v14378 = v14353->cache_tags;
    int v14379 = v14378[v14482];
    int v14380 = v14376[v14469];
    int v14381 = v14378[v14469];
    bool v14484 = !(((~(((v14361 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14361 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) | (~(((v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31))) == 0);
    int v14435;
    if (v14484) {
      int * v14382 = v14353->cache_age;
      int v14486 = (4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + ((~(((v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))) | (-(v14362 ^ ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1))))) >> 31)) & 1);
      int v14383 = v14382[v14486];
      int v14384 = v14382[v14470];
      int v14487 = v14384 + ((int)((unsigned int)(v14384 - v14383) >> 31));
      v14382[v14470] = v14487;
      int * v14386 = v14353->cache_age;
      int v14387 = v14386[v14471];
      int v14489 = v14387 + ((int)((unsigned int)(v14387 - v14383) >> 31));
      v14386[v14471] = v14489;
      int * v14389 = v14353->cache_age;
      v14389[v14486] = 0;
      v14435 = v14486;
    } else {
      int * v14392 = v14353->cache_age;
      int v14493 = 4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2);
      int v14393 = v14392[v14493];
      int * v14394 = v14353->cache_tags;
      int v14395 = v14394[v14493];
      int v14396 = v14392[v14471];
      int v14397 = v14394[v14471];
      int * v14398 = v14353->cache_dirty;
      int v14496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + ((((v14393 + ((~(((v14395 ^ -1) | (-(v14395 ^ -1))) >> 31)) & 2)) - (v14396 + ((~(((v14397 ^ -1) | (-(v14397 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14399 = v14398[v14496];
      bool v14497 = !(v14399 == 0);
      if (v14497) {
        int * v14400 = v14353->cache_tags;
        int v14401 = v14400[v14496];
        int * v14402 = v14353->cache_vals;
        int v14500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + ((((v14393 + ((~(((v14395 ^ -1) | (-(v14395 ^ -1))) >> 31)) & 2)) - (v14396 + ((~(((v14397 ^ -1) | (-(v14397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14403 = v14402[v14500];
        int v14501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + ((((v14393 + ((~(((v14395 ^ -1) | (-(v14395 ^ -1))) >> 31)) & 2)) - (v14396 + ((~(((v14397 ^ -1) | (-(v14397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14404 = v14402[v14501];
        int * v14405 = v14353->mem;
        int v14503 = v14401 * 2;
        v14405[v14503] = v14403;
        int * v14407 = v14353->mem;
        int v14506 = (v14401 * 2) + 1;
        v14407[v14506] = v14404;
        ;
      } else {
        ;
      }
      int * v14412 = v14353->mem;
      int v14511 = ((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) * 2;
      int v14413 = v14412[v14511];
      int v14512 = (((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) * 2) + 1;
      int v14414 = v14412[v14512];
      int * v14415 = v14353->cache_vals;
      int v14514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + ((((v14393 + ((~(((v14395 ^ -1) | (-(v14395 ^ -1))) >> 31)) & 2)) - (v14396 + ((~(((v14397 ^ -1) | (-(v14397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14415[v14514] = v14413;
      int * v14417 = v14353->cache_vals;
      int v14517 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 3) * 2)) + ((((v14393 + ((~(((v14395 ^ -1) | (-(v14395 ^ -1))) >> 31)) & 2)) - (v14396 + ((~(((v14397 ^ -1) | (-(v14397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14417[v14517] = v14414;
      int * v14419 = v14353->cache_tags;
      int v14520 = (int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1);
      v14419[v14496] = v14520;
      int * v14421 = v14353->cache_dirty;
      v14421[v14496] = 0;
      int * v14423 = v14353->cache_age;
      v14423[v14496] = 1;
      int * v14425 = v14353->cache_age;
      int v14426 = v14425[v14496];
      int v14427 = v14425[v14470];
      int v14526 = v14427 + ((int)((unsigned int)(v14427 - v14426) >> 31));
      v14425[v14470] = v14526;
      int * v14429 = v14353->cache_age;
      int v14430 = v14429[v14471];
      int v14528 = v14430 + ((int)((unsigned int)(v14430 - v14426) >> 31));
      v14429[v14471] = v14528;
      int * v14432 = v14353->cache_age;
      v14432[v14496] = 0;
      v14435 = v14496;
    }
    int * v14436 = v14353->cache_vals;
    int v14531 = v14435 * 2;
    int v14437 = v14436[v14531];
    int v14532 = (v14435 * 2) + 1;
    int v14438 = v14436[v14532];
    int v14533 = (((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2) + ((((v14377 + ((~(((v14379 ^ -1) | (-(v14379 ^ -1))) >> 31)) & 2)) - (v14380 + ((~(((v14381 ^ -1) | (-(v14381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14436[v14533] = v14437;
    int * v14440 = v14353->cache_vals;
    int v14536 = ((((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2) + ((((v14377 + ((~(((v14379 ^ -1) | (-(v14379 ^ -1))) >> 31)) & 2)) - (v14380 + ((~(((v14381 ^ -1) | (-(v14381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14440[v14536] = v14438;
    int * v14442 = v14353->cache_tags;
    int v14539 = ((((int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1)) & 1) * 2) + ((((v14377 + ((~(((v14379 ^ -1) | (-(v14379 ^ -1))) >> 31)) & 2)) - (v14380 + ((~(((v14381 ^ -1) | (-(v14381 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14540 = (int)((unsigned int)((int)((unsigned int)v14357 >> 2)) >> 1);
    v14442[v14539] = v14540;
    int * v14444 = v14353->cache_dirty;
    v14444[v14539] = 0;
    int * v14446 = v14353->cache_age;
    v14446[v14539] = 1;
    int * v14448 = v14353->cache_age;
    int v14449 = v14448[v14539];
    int v14450 = v14448[v14468];
    int v14546 = v14450 + ((int)((unsigned int)(v14450 - v14449) >> 31));
    v14448[v14468] = v14546;
    int * v14452 = v14353->cache_age;
    int v14453 = v14452[v14469];
    int v14548 = v14453 + ((int)((unsigned int)(v14453 - v14449) >> 31));
    v14452[v14469] = v14548;
    int * v14455 = v14353->cache_age;
    v14455[v14539] = 0;
    v14458 = v14539;
  }
  int v14551 = (v14458 * 2) + (((int)((unsigned int)v14357 >> 2)) & 1);
  int v14459 = v14365[v14551];
  int * v14460 = v14353->regs;
  v14460[19] = v14459;
  struct StateT * v14462 = slot_234(v14353);
  return v14462;
}

struct StateT * slot_176(struct StateT * v10563) {
  int v10564 = v10563->timer;
  int v10572 = v10564 + 1;
  v10563->timer = v10572;
  int * v10566 = v10563->regs;
  int v10567 = v10566[11];
  int v10568 = v10566[12];
  int v10577 = v10567 * v10568;
  v10566[28] = v10577;
  struct StateT * v10570 = slot_177(v10563);
  return v10570;
}

struct StateT * slot_189(struct StateT * v10796) {
  int v10797 = v10796->timer;
  int v10809 = v10797 + 1;
  v10796->timer = v10809;
  int * v10799 = v10796->regs;
  int v10800 = v10799[6];
  int v10801 = v10799[30];
  bool v10813 = (v10800 ^ -2147483648) < (v10801 ^ -2147483648);
  int v10804;
  if (v10813) {
    v10804 = 1;
  } else {
    v10804 = 0;
  }
  int * v10805 = v10796->regs;
  v10805[12] = v10804;
  struct StateT * v10807 = slot_190(v10796);
  return v10807;
}

struct StateT * slot_33(struct StateT * v4051) {
  int v4052 = v4051->timer;
  int v4060 = v4052 + 1;
  v4051->timer = v4060;
  int * v4054 = v4051->regs;
  int v4055 = v4054[30];
  int v4056 = v4054[5];
  int v4064 = v4055 + v4056;
  v4054[5] = v4064;
  struct StateT * v4058 = slot_34(v4051);
  return v4058;
}

struct StateT * slot_35(struct StateT * v4099) {
  int v4100 = v4099->timer;
  int v4107 = v4100 + 1;
  v4099->timer = v4107;
  int * v4102 = v4099->regs;
  int v4103 = v4102[31];
  int v4110 = v4103 << 13;
  v4102[31] = v4110;
  struct StateT * v4105 = slot_36(v4099);
  return v4105;
}

struct StateT * slot_246(struct StateT * v14650) {
  int v14651 = v14650->timer;
  int v14659 = v14651 + 1;
  v14650->timer = v14659;
  int * v14653 = v14650->regs;
  int v14654 = v14653[14];
  int v14655 = v14653[13];
  int v14663 = v14654 + v14655;
  v14653[13] = v14663;
  struct StateT * v14657 = slot_247(v14650);
  return v14657;
}

struct StateT * slot_210(struct StateT * v11196) {
  int v11197 = v11196->timer;
  int v11204 = v11197 + 1;
  v11196->timer = v11204;
  int * v11199 = v11196->regs;
  int v11200 = v11199[12];
  int v11207 = v11200 << 13;
  v11199[12] = v11207;
  struct StateT * v11202 = slot_211(v11196);
  return v11202;
}

struct StateT * slot_166(struct StateT * v10024) {
  int v10025 = v10024->timer;
  int v10032 = v10025 + 1;
  v10024->timer = v10032;
  int * v10027 = v10024->regs;
  int v10028 = v10027[28];
  int v10036 = (int)((unsigned int)v10028 >> 19);
  v10027[17] = v10036;
  struct StateT * v10030 = slot_167(v10024);
  return v10030;
}

struct StateT * slot_51(struct StateT * v4366) {
  int v4367 = v4366->timer;
  int v4375 = v4367 + 1;
  v4366->timer = v4375;
  int * v4369 = v4366->regs;
  int v4370 = v4369[8];
  int v4371 = v4369[6];
  int v4380 = v4370 + v4371;
  v4369[29] = v4380;
  struct StateT * v4373 = slot_52(v4366);
  return v4373;
}

struct StateT * slot_52(struct StateT * v4383) {
  int v4384 = v4383->timer;
  int v4396 = v4384 + 1;
  v4383->timer = v4396;
  int * v4386 = v4383->regs;
  int v4387 = v4386[17];
  int v4388 = v4386[7];
  bool v4400 = (v4387 ^ -2147483648) < (v4388 ^ -2147483648);
  int v4391;
  if (v4400) {
    v4391 = 1;
  } else {
    v4391 = 0;
  }
  int * v4392 = v4383->regs;
  v4392[28] = v4391;
  struct StateT * v4394 = slot_53(v4383);
  return v4394;
}

struct StateT * slot_83(struct StateT * v6063) {
  int v6064 = v6063->timer;
  int v6071 = v6064 + 1;
  v6063->timer = v6071;
  int * v6066 = v6063->regs;
  int v6067 = v6066[5];
  int v6074 = v6067 << 13;
  v6066[5] = v6074;
  struct StateT * v6069 = slot_84(v6063);
  return v6069;
}

struct StateT * slot_25(struct StateT * v2455) {
  int v2456 = v2455->timer;
  int v2626 = v2456 + 1;
  v2455->timer = v2626;
  int * v2458 = v2455->regs;
  int v2459 = v2458[10];
  int v2460 = v2458[14];
  int * v2461 = v2455->cache_tags;
  int v2631 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2;
  int v2462 = v2461[v2631];
  int v2632 = ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2463 = v2461[v2632];
  int v2633 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2);
  int v2464 = v2461[v2633];
  int v2634 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2465 = v2461[v2634];
  int v2466 = v2455->timer;
  int v2635 = v2466 + ((100 ^ (((~(((v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2455->timer = v2635;
  bool v2636 = !(((~(((v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) == 0);
  int v2560;
  if (v2636) {
    int * v2468 = v2455->cache_age;
    int v2638 = ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((~(((v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) & 1);
    int v2469 = v2468[v2638];
    int v2470 = v2468[v2631];
    int v2639 = v2470 + ((int)((unsigned int)(v2470 - v2469) >> 31));
    v2468[v2631] = v2639;
    int * v2472 = v2455->cache_age;
    int v2473 = v2472[v2632];
    int v2641 = v2473 + ((int)((unsigned int)(v2473 - v2469) >> 31));
    v2472[v2632] = v2641;
    int * v2475 = v2455->cache_age;
    v2475[v2638] = 0;
    v2560 = v2638;
  } else {
    int * v2478 = v2455->cache_age;
    int v2645 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2;
    int v2479 = v2478[v2645];
    int * v2480 = v2455->cache_tags;
    int v2481 = v2480[v2645];
    int v2482 = v2478[v2632];
    int v2483 = v2480[v2632];
    bool v2647 = !(((~(((v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) == 0);
    int v2537;
    if (v2647) {
      int * v2484 = v2455->cache_age;
      int v2649 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) & 1);
      int v2485 = v2484[v2649];
      int v2486 = v2484[v2633];
      int v2650 = v2486 + ((int)((unsigned int)(v2486 - v2485) >> 31));
      v2484[v2633] = v2650;
      int * v2488 = v2455->cache_age;
      int v2489 = v2488[v2634];
      int v2652 = v2489 + ((int)((unsigned int)(v2489 - v2485) >> 31));
      v2488[v2634] = v2652;
      int * v2491 = v2455->cache_age;
      v2491[v2649] = 0;
      v2537 = v2649;
    } else {
      int * v2494 = v2455->cache_age;
      int v2656 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2);
      int v2495 = v2494[v2656];
      int * v2496 = v2455->cache_tags;
      int v2497 = v2496[v2656];
      int v2498 = v2494[v2634];
      int v2499 = v2496[v2634];
      int * v2500 = v2455->cache_dirty;
      int v2659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2501 = v2500[v2659];
      bool v2660 = !(v2501 == 0);
      if (v2660) {
        int * v2502 = v2455->cache_tags;
        int v2503 = v2502[v2659];
        int * v2504 = v2455->cache_vals;
        int v2663 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2505 = v2504[v2663];
        int v2664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2506 = v2504[v2664];
        int * v2507 = v2455->mem;
        int v2666 = v2503 * 2;
        v2507[v2666] = v2505;
        int * v2509 = v2455->mem;
        int v2669 = (v2503 * 2) + 1;
        v2509[v2669] = v2506;
        ;
      } else {
        ;
      }
      int * v2514 = v2455->mem;
      int v2674 = ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2;
      int v2515 = v2514[v2674];
      int v2675 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2) + 1;
      int v2516 = v2514[v2675];
      int * v2517 = v2455->cache_vals;
      int v2677 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2517[v2677] = v2515;
      int * v2519 = v2455->cache_vals;
      int v2680 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2519[v2680] = v2516;
      int * v2521 = v2455->cache_tags;
      int v2683 = (int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1);
      v2521[v2659] = v2683;
      int * v2523 = v2455->cache_dirty;
      v2523[v2659] = 0;
      int * v2525 = v2455->cache_age;
      v2525[v2659] = 1;
      int * v2527 = v2455->cache_age;
      int v2528 = v2527[v2659];
      int v2529 = v2527[v2633];
      int v2689 = v2529 + ((int)((unsigned int)(v2529 - v2528) >> 31));
      v2527[v2633] = v2689;
      int * v2531 = v2455->cache_age;
      int v2532 = v2531[v2634];
      int v2691 = v2532 + ((int)((unsigned int)(v2532 - v2528) >> 31));
      v2531[v2634] = v2691;
      int * v2534 = v2455->cache_age;
      v2534[v2659] = 0;
      v2537 = v2659;
    }
    int * v2538 = v2455->cache_vals;
    int v2694 = v2537 * 2;
    int v2539 = v2538[v2694];
    int v2695 = (v2537 * 2) + 1;
    int v2540 = v2538[v2695];
    int v2696 = (((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((((v2479 + ((~(((v2481 ^ -1) | (-(v2481 ^ -1))) >> 31)) & 2)) - (v2482 + ((~(((v2483 ^ -1) | (-(v2483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2538[v2696] = v2539;
    int * v2542 = v2455->cache_vals;
    int v2699 = ((((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((((v2479 + ((~(((v2481 ^ -1) | (-(v2481 ^ -1))) >> 31)) & 2)) - (v2482 + ((~(((v2483 ^ -1) | (-(v2483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2542[v2699] = v2540;
    int * v2544 = v2455->cache_tags;
    int v2702 = ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((((v2479 + ((~(((v2481 ^ -1) | (-(v2481 ^ -1))) >> 31)) & 2)) - (v2482 + ((~(((v2483 ^ -1) | (-(v2483 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2703 = (int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1);
    v2544[v2702] = v2703;
    int * v2546 = v2455->cache_dirty;
    v2546[v2702] = 0;
    int * v2548 = v2455->cache_age;
    v2548[v2702] = 1;
    int * v2550 = v2455->cache_age;
    int v2551 = v2550[v2702];
    int v2552 = v2550[v2631];
    int v2709 = v2552 + ((int)((unsigned int)(v2552 - v2551) >> 31));
    v2550[v2631] = v2709;
    int * v2554 = v2455->cache_age;
    int v2555 = v2554[v2632];
    int v2711 = v2555 + ((int)((unsigned int)(v2555 - v2551) >> 31));
    v2554[v2632] = v2711;
    int * v2557 = v2455->cache_age;
    v2557[v2702] = 0;
    v2560 = v2702;
  }
  int * v2561 = v2455->cache_vals;
  int v2714 = (v2560 * 2) + (((int)((unsigned int)v2459 >> 2)) & 1);
  v2561[v2714] = v2460;
  int * v2563 = v2455->cache_tags;
  int v2564 = v2563[v2633];
  int v2565 = v2563[v2634];
  bool v2717 = !(((~(((v2564 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2564 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) == 0);
  int v2619;
  if (v2717) {
    int * v2566 = v2455->cache_age;
    int v2719 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) & 1);
    int v2567 = v2566[v2719];
    int v2568 = v2566[v2633];
    int v2720 = v2568 + ((int)((unsigned int)(v2568 - v2567) >> 31));
    v2566[v2633] = v2720;
    int * v2570 = v2455->cache_age;
    int v2571 = v2570[v2634];
    int v2722 = v2571 + ((int)((unsigned int)(v2571 - v2567) >> 31));
    v2570[v2634] = v2722;
    int * v2573 = v2455->cache_age;
    v2573[v2719] = 0;
    v2619 = v2719;
  } else {
    int * v2576 = v2455->cache_age;
    int v2726 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2);
    int v2577 = v2576[v2726];
    int * v2578 = v2455->cache_tags;
    int v2579 = v2578[v2726];
    int v2580 = v2576[v2634];
    int v2581 = v2578[v2634];
    int * v2582 = v2455->cache_dirty;
    int v2729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2583 = v2582[v2729];
    bool v2730 = !(v2583 == 0);
    if (v2730) {
      int * v2584 = v2455->cache_tags;
      int v2585 = v2584[v2729];
      int * v2586 = v2455->cache_vals;
      int v2733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2587 = v2586[v2733];
      int v2734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2588 = v2586[v2734];
      int * v2589 = v2455->mem;
      int v2736 = v2585 * 2;
      v2589[v2736] = v2587;
      int * v2591 = v2455->mem;
      int v2739 = (v2585 * 2) + 1;
      v2591[v2739] = v2588;
      ;
    } else {
      ;
    }
    int * v2596 = v2455->mem;
    int v2744 = ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2;
    int v2597 = v2596[v2744];
    int v2745 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2) + 1;
    int v2598 = v2596[v2745];
    int * v2599 = v2455->cache_vals;
    int v2747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2599[v2747] = v2597;
    int * v2601 = v2455->cache_vals;
    int v2750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2601[v2750] = v2598;
    int * v2603 = v2455->cache_tags;
    int v2753 = (int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1);
    v2603[v2729] = v2753;
    int * v2605 = v2455->cache_dirty;
    v2605[v2729] = 0;
    int * v2607 = v2455->cache_age;
    v2607[v2729] = 1;
    int * v2609 = v2455->cache_age;
    int v2610 = v2609[v2729];
    int v2611 = v2609[v2633];
    int v2759 = v2611 + ((int)((unsigned int)(v2611 - v2610) >> 31));
    v2609[v2633] = v2759;
    int * v2613 = v2455->cache_age;
    int v2614 = v2613[v2634];
    int v2761 = v2614 + ((int)((unsigned int)(v2614 - v2610) >> 31));
    v2613[v2634] = v2761;
    int * v2616 = v2455->cache_age;
    v2616[v2729] = 0;
    v2619 = v2729;
  }
  int * v2620 = v2455->cache_vals;
  int v2764 = (v2619 * 2) + (((int)((unsigned int)v2459 >> 2)) & 1);
  v2620[v2764] = v2460;
  int * v2622 = v2455->cache_dirty;
  v2622[v2619] = 1;
  struct StateT * v2624 = slot_26(v2455);
  return v2624;
}

struct StateT * slot_209(struct StateT * v11182) {
  int v11183 = v11182->timer;
  int v11190 = v11183 + 1;
  v11182->timer = v11190;
  int * v11185 = v11182->regs;
  int v11186 = v11185[5];
  int v11193 = (int)((unsigned int)v11186 >> 19);
  v11185[5] = v11193;
  struct StateT * v11188 = slot_210(v11182);
  return v11188;
}

struct StateT * slot_3(struct StateT * v646) {
  int v647 = v646->timer;
  int v817 = v647 + 1;
  v646->timer = v817;
  int * v649 = v646->regs;
  int v650 = v649[2];
  int v651 = v649[18];
  int * v652 = v646->cache_tags;
  int v822 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2;
  int v653 = v652[v822];
  int v823 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v654 = v652[v823];
  int v824 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2);
  int v655 = v652[v824];
  int v825 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v656 = v652[v825];
  int v657 = v646->timer;
  int v826 = v657 + ((100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v646->timer = v826;
  bool v827 = !(((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v751;
  if (v827) {
    int * v659 = v646->cache_age;
    int v829 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v660 = v659[v829];
    int v661 = v659[v822];
    int v830 = v661 + ((int)((unsigned int)(v661 - v660) >> 31));
    v659[v822] = v830;
    int * v663 = v646->cache_age;
    int v664 = v663[v823];
    int v832 = v664 + ((int)((unsigned int)(v664 - v660) >> 31));
    v663[v823] = v832;
    int * v666 = v646->cache_age;
    v666[v829] = 0;
    v751 = v829;
  } else {
    int * v669 = v646->cache_age;
    int v836 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2;
    int v670 = v669[v836];
    int * v671 = v646->cache_tags;
    int v672 = v671[v836];
    int v673 = v669[v823];
    int v674 = v671[v823];
    bool v838 = !(((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v728;
    if (v838) {
      int * v675 = v646->cache_age;
      int v840 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v676 = v675[v840];
      int v677 = v675[v824];
      int v841 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
      v675[v824] = v841;
      int * v679 = v646->cache_age;
      int v680 = v679[v825];
      int v843 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
      v679[v825] = v843;
      int * v682 = v646->cache_age;
      v682[v840] = 0;
      v728 = v840;
    } else {
      int * v685 = v646->cache_age;
      int v847 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2);
      int v686 = v685[v847];
      int * v687 = v646->cache_tags;
      int v688 = v687[v847];
      int v689 = v685[v825];
      int v690 = v687[v825];
      int * v691 = v646->cache_dirty;
      int v850 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v692 = v691[v850];
      bool v851 = !(v692 == 0);
      if (v851) {
        int * v693 = v646->cache_tags;
        int v694 = v693[v850];
        int * v695 = v646->cache_vals;
        int v854 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v696 = v695[v854];
        int v855 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v697 = v695[v855];
        int * v698 = v646->mem;
        int v857 = v694 * 2;
        v698[v857] = v696;
        int * v700 = v646->mem;
        int v860 = (v694 * 2) + 1;
        v700[v860] = v697;
        ;
      } else {
        ;
      }
      int * v705 = v646->mem;
      int v865 = ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2;
      int v706 = v705[v865];
      int v866 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2) + 1;
      int v707 = v705[v866];
      int * v708 = v646->cache_vals;
      int v868 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v708[v868] = v706;
      int * v710 = v646->cache_vals;
      int v871 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v710[v871] = v707;
      int * v712 = v646->cache_tags;
      int v874 = (int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1);
      v712[v850] = v874;
      int * v714 = v646->cache_dirty;
      v714[v850] = 0;
      int * v716 = v646->cache_age;
      v716[v850] = 1;
      int * v718 = v646->cache_age;
      int v719 = v718[v850];
      int v720 = v718[v824];
      int v880 = v720 + ((int)((unsigned int)(v720 - v719) >> 31));
      v718[v824] = v880;
      int * v722 = v646->cache_age;
      int v723 = v722[v825];
      int v882 = v723 + ((int)((unsigned int)(v723 - v719) >> 31));
      v722[v825] = v882;
      int * v725 = v646->cache_age;
      v725[v850] = 0;
      v728 = v850;
    }
    int * v729 = v646->cache_vals;
    int v885 = v728 * 2;
    int v730 = v729[v885];
    int v886 = (v728 * 2) + 1;
    int v731 = v729[v886];
    int v887 = (((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v729[v887] = v730;
    int * v733 = v646->cache_vals;
    int v890 = ((((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v733[v890] = v731;
    int * v735 = v646->cache_tags;
    int v893 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v894 = (int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1);
    v735[v893] = v894;
    int * v737 = v646->cache_dirty;
    v737[v893] = 0;
    int * v739 = v646->cache_age;
    v739[v893] = 1;
    int * v741 = v646->cache_age;
    int v742 = v741[v893];
    int v743 = v741[v822];
    int v900 = v743 + ((int)((unsigned int)(v743 - v742) >> 31));
    v741[v822] = v900;
    int * v745 = v646->cache_age;
    int v746 = v745[v823];
    int v902 = v746 + ((int)((unsigned int)(v746 - v742) >> 31));
    v745[v823] = v902;
    int * v748 = v646->cache_age;
    v748[v893] = 0;
    v751 = v893;
  }
  int * v752 = v646->cache_vals;
  int v905 = (v751 * 2) + (((int)((unsigned int)(v650 + 4) >> 2)) & 1);
  v752[v905] = v651;
  int * v754 = v646->cache_tags;
  int v755 = v754[v824];
  int v756 = v754[v825];
  bool v908 = !(((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v810;
  if (v908) {
    int * v757 = v646->cache_age;
    int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v758 = v757[v910];
    int v759 = v757[v824];
    int v911 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v824] = v911;
    int * v761 = v646->cache_age;
    int v762 = v761[v825];
    int v913 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v825] = v913;
    int * v764 = v646->cache_age;
    v764[v910] = 0;
    v810 = v910;
  } else {
    int * v767 = v646->cache_age;
    int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2);
    int v768 = v767[v917];
    int * v769 = v646->cache_tags;
    int v770 = v769[v917];
    int v771 = v767[v825];
    int v772 = v769[v825];
    int * v773 = v646->cache_dirty;
    int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v774 = v773[v920];
    bool v921 = !(v774 == 0);
    if (v921) {
      int * v775 = v646->cache_tags;
      int v776 = v775[v920];
      int * v777 = v646->cache_vals;
      int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v778 = v777[v924];
      int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v779 = v777[v925];
      int * v780 = v646->mem;
      int v927 = v776 * 2;
      v780[v927] = v778;
      int * v782 = v646->mem;
      int v930 = (v776 * 2) + 1;
      v782[v930] = v779;
      ;
    } else {
      ;
    }
    int * v787 = v646->mem;
    int v935 = ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2;
    int v788 = v787[v935];
    int v936 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2) + 1;
    int v789 = v787[v936];
    int * v790 = v646->cache_vals;
    int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v790[v938] = v788;
    int * v792 = v646->cache_vals;
    int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v792[v941] = v789;
    int * v794 = v646->cache_tags;
    int v944 = (int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1);
    v794[v920] = v944;
    int * v796 = v646->cache_dirty;
    v796[v920] = 0;
    int * v798 = v646->cache_age;
    v798[v920] = 1;
    int * v800 = v646->cache_age;
    int v801 = v800[v920];
    int v802 = v800[v824];
    int v950 = v802 + ((int)((unsigned int)(v802 - v801) >> 31));
    v800[v824] = v950;
    int * v804 = v646->cache_age;
    int v805 = v804[v825];
    int v952 = v805 + ((int)((unsigned int)(v805 - v801) >> 31));
    v804[v825] = v952;
    int * v807 = v646->cache_age;
    v807[v920] = 0;
    v810 = v920;
  }
  int * v811 = v646->cache_vals;
  int v955 = (v810 * 2) + (((int)((unsigned int)(v650 + 4) >> 2)) & 1);
  v811[v955] = v651;
  int * v813 = v646->cache_dirty;
  v813[v810] = 1;
  struct StateT * v815 = slot_4(v646);
  return v815;
}

struct StateT * slot_123(struct StateT * v8172) {
  int v8173 = v8172->timer;
  int v8181 = v8173 + 1;
  v8172->timer = v8181;
  int * v8175 = v8172->regs;
  int v8176 = v8175[6];
  int v8177 = v8175[5];
  int v8185 = v8176 + v8177;
  v8175[5] = v8185;
  struct StateT * v8179 = slot_124(v8172);
  return v8179;
}

struct StateT * slot_73(struct StateT * v5127) {
  int v5128 = v5127->timer;
  int v5136 = v5128 + 1;
  v5127->timer = v5136;
  int * v5130 = v5127->regs;
  int v5131 = v5130[7];
  int v5132 = v5130[16];
  int v5141 = v5131 & v5132;
  v5130[29] = v5141;
  struct StateT * v5134 = slot_75(v5127);
  return v5134;
}

struct StateT * slot_198(struct StateT * v10968) {
  int v10969 = v10968->timer;
  int v10977 = v10969 + 1;
  v10968->timer = v10977;
  int * v10971 = v10968->regs;
  int v10972 = v10971[13];
  int v10973 = v10971[28];
  int v10981 = v10972 + v10973;
  v10971[13] = v10981;
  struct StateT * v10975 = slot_199(v10968);
  return v10975;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v187 = v17 + 1;
  v16->timer = v187;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2;
  int v23 = v22[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v24 = v22[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2);
  int v25 = v22[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26 = v22[v195];
  int v27 = v16->timer;
  int v196 = v27 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16->timer = v196;
  bool v197 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v121;
  if (v197) {
    int * v29 = v16->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v30 = v29[v199];
    int v31 = v29[v192];
    int v200 = v31 + ((int)((unsigned int)(v31 - v30) >> 31));
    v29[v192] = v200;
    int * v33 = v16->cache_age;
    int v34 = v33[v193];
    int v202 = v34 + ((int)((unsigned int)(v34 - v30) >> 31));
    v33[v193] = v202;
    int * v36 = v16->cache_age;
    v36[v199] = 0;
    v121 = v199;
  } else {
    int * v39 = v16->cache_age;
    int v206 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2;
    int v40 = v39[v206];
    int * v41 = v16->cache_tags;
    int v42 = v41[v206];
    int v43 = v39[v193];
    int v44 = v41[v193];
    bool v208 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v98;
    if (v208) {
      int * v45 = v16->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v46 = v45[v210];
      int v47 = v45[v194];
      int v211 = v47 + ((int)((unsigned int)(v47 - v46) >> 31));
      v45[v194] = v211;
      int * v49 = v16->cache_age;
      int v50 = v49[v195];
      int v213 = v50 + ((int)((unsigned int)(v50 - v46) >> 31));
      v49[v195] = v213;
      int * v52 = v16->cache_age;
      v52[v210] = 0;
      v98 = v210;
    } else {
      int * v55 = v16->cache_age;
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2);
      int v56 = v55[v217];
      int * v57 = v16->cache_tags;
      int v58 = v57[v217];
      int v59 = v55[v195];
      int v60 = v57[v195];
      int * v61 = v16->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v62 = v61[v220];
      bool v221 = !(v62 == 0);
      if (v221) {
        int * v63 = v16->cache_tags;
        int v64 = v63[v220];
        int * v65 = v16->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66 = v65[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v65[v225];
        int * v68 = v16->mem;
        int v227 = v64 * 2;
        v68[v227] = v66;
        int * v70 = v16->mem;
        int v230 = (v64 * 2) + 1;
        v70[v230] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v16->mem;
      int v235 = ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2;
      int v76 = v75[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2) + 1;
      int v77 = v75[v236];
      int * v78 = v16->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v78[v238] = v76;
      int * v80 = v16->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v80[v241] = v77;
      int * v82 = v16->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1);
      v82[v220] = v244;
      int * v84 = v16->cache_dirty;
      v84[v220] = 0;
      int * v86 = v16->cache_age;
      v86[v220] = 1;
      int * v88 = v16->cache_age;
      int v89 = v88[v220];
      int v90 = v88[v194];
      int v250 = v90 + ((int)((unsigned int)(v90 - v89) >> 31));
      v88[v194] = v250;
      int * v92 = v16->cache_age;
      int v93 = v92[v195];
      int v252 = v93 + ((int)((unsigned int)(v93 - v89) >> 31));
      v92[v195] = v252;
      int * v95 = v16->cache_age;
      v95[v220] = 0;
      v98 = v220;
    }
    int * v99 = v16->cache_vals;
    int v255 = v98 * 2;
    int v100 = v99[v255];
    int v256 = (v98 * 2) + 1;
    int v101 = v99[v256];
    int v257 = (((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v99[v257] = v100;
    int * v103 = v16->cache_vals;
    int v260 = ((((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v103[v260] = v101;
    int * v105 = v16->cache_tags;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v264 = (int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1);
    v105[v263] = v264;
    int * v107 = v16->cache_dirty;
    v107[v263] = 0;
    int * v109 = v16->cache_age;
    v109[v263] = 1;
    int * v111 = v16->cache_age;
    int v112 = v111[v263];
    int v113 = v111[v192];
    int v270 = v113 + ((int)((unsigned int)(v113 - v112) >> 31));
    v111[v192] = v270;
    int * v115 = v16->cache_age;
    int v116 = v115[v193];
    int v272 = v116 + ((int)((unsigned int)(v116 - v112) >> 31));
    v115[v193] = v272;
    int * v118 = v16->cache_age;
    v118[v263] = 0;
    v121 = v263;
  }
  int * v122 = v16->cache_vals;
  int v275 = (v121 * 2) + (((int)((unsigned int)(v20 + 12) >> 2)) & 1);
  v122[v275] = v21;
  int * v124 = v16->cache_tags;
  int v125 = v124[v194];
  int v126 = v124[v195];
  bool v278 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v180;
  if (v278) {
    int * v127 = v16->cache_age;
    int v280 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v128 = v127[v280];
    int v129 = v127[v194];
    int v281 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
    v127[v194] = v281;
    int * v131 = v16->cache_age;
    int v132 = v131[v195];
    int v283 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
    v131[v195] = v283;
    int * v134 = v16->cache_age;
    v134[v280] = 0;
    v180 = v280;
  } else {
    int * v137 = v16->cache_age;
    int v287 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2);
    int v138 = v137[v287];
    int * v139 = v16->cache_tags;
    int v140 = v139[v287];
    int v141 = v137[v195];
    int v142 = v139[v195];
    int * v143 = v16->cache_dirty;
    int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v144 = v143[v290];
    bool v291 = !(v144 == 0);
    if (v291) {
      int * v145 = v16->cache_tags;
      int v146 = v145[v290];
      int * v147 = v16->cache_vals;
      int v294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v148 = v147[v294];
      int v295 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v149 = v147[v295];
      int * v150 = v16->mem;
      int v297 = v146 * 2;
      v150[v297] = v148;
      int * v152 = v16->mem;
      int v300 = (v146 * 2) + 1;
      v152[v300] = v149;
      ;
    } else {
      ;
    }
    int * v157 = v16->mem;
    int v305 = ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2;
    int v158 = v157[v305];
    int v306 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2) + 1;
    int v159 = v157[v306];
    int * v160 = v16->cache_vals;
    int v308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v308] = v158;
    int * v162 = v16->cache_vals;
    int v311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v162[v311] = v159;
    int * v164 = v16->cache_tags;
    int v314 = (int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1);
    v164[v290] = v314;
    int * v166 = v16->cache_dirty;
    v166[v290] = 0;
    int * v168 = v16->cache_age;
    v168[v290] = 1;
    int * v170 = v16->cache_age;
    int v171 = v170[v290];
    int v172 = v170[v194];
    int v320 = v172 + ((int)((unsigned int)(v172 - v171) >> 31));
    v170[v194] = v320;
    int * v174 = v16->cache_age;
    int v175 = v174[v195];
    int v322 = v175 + ((int)((unsigned int)(v175 - v171) >> 31));
    v174[v195] = v322;
    int * v177 = v16->cache_age;
    v177[v290] = 0;
    v180 = v290;
  }
  int * v181 = v16->cache_vals;
  int v325 = (v180 * 2) + (((int)((unsigned int)(v20 + 12) >> 2)) & 1);
  v181[v325] = v21;
  int * v183 = v16->cache_dirty;
  v183[v180] = 1;
  struct StateT * v185 = slot_2(v16);
  return v185;
}

struct StateT * slot_187(struct StateT * v10755) {
  int v10756 = v10755->timer;
  int v10768 = v10756 + 1;
  v10755->timer = v10768;
  int * v10758 = v10755->regs;
  int v10759 = v10758[11];
  int v10760 = v10758[12];
  bool v10772 = (v10759 ^ -2147483648) < (v10760 ^ -2147483648);
  int v10763;
  if (v10772) {
    v10763 = 1;
  } else {
    v10763 = 0;
  }
  int * v10764 = v10755->regs;
  v10764[5] = v10763;
  struct StateT * v10766 = slot_188(v10755);
  return v10766;
}

struct StateT * slot_97(struct StateT * v6507) {
  int v6508 = v6507->timer;
  int v6520 = v6508 + 1;
  v6507->timer = v6520;
  int * v6510 = v6507->regs;
  int v6511 = v6510[17];
  int v6512 = v6510[6];
  bool v6524 = (v6511 ^ -2147483648) < (v6512 ^ -2147483648);
  int v6515;
  if (v6524) {
    v6515 = 1;
  } else {
    v6515 = 0;
  }
  int * v6516 = v6507->regs;
  v6516[28] = v6515;
  struct StateT * v6518 = slot_98(v6507);
  return v6518;
}

struct StateT * slot_182(struct StateT * v10664) {
  int v10665 = v10664->timer;
  int v10673 = v10665 + 1;
  v10664->timer = v10673;
  int * v10667 = v10664->regs;
  int v10668 = v10667[6];
  int v10669 = v10667[12];
  int v10677 = v10668 * v10669;
  v10667[12] = v10677;
  struct StateT * v10671 = slot_183(v10664);
  return v10671;
}

struct StateT * slot_38(struct StateT * v4145) {
  int v4146 = v4145->timer;
  int v4154 = v4146 + 1;
  v4145->timer = v4154;
  int * v4148 = v4145->regs;
  int v4149 = v4148[7];
  int v4150 = v4148[12];
  int v4159 = (((((int)((unsigned int)v4149 >> 16)) * ((int)((unsigned int)v4150 >> 16))) + ((int)((unsigned int)((v4149 & 65535) * ((int)((unsigned int)v4150 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4149 >> 16)) * (v4150 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4149 & 65535) * (v4150 & 65535)) >> 16)) + (((v4149 & 65535) * ((int)((unsigned int)v4150 >> 16))) & 65535)) + ((((int)((unsigned int)v4149 >> 16)) * (v4150 & 65535)) & 65535)) >> 16));
  v4148[6] = v4159;
  struct StateT * v4152 = slot_39(v4145);
  return v4152;
}

struct StateT * slot_178(struct StateT * v10597) {
  int v10598 = v10597->timer;
  int v10606 = v10598 + 1;
  v10597->timer = v10606;
  int * v10600 = v10597->regs;
  int v10601 = v10600[6];
  int v10602 = v10600[13];
  int v10611 = v10601 * v10602;
  v10600[30] = v10611;
  struct StateT * v10604 = slot_179(v10597);
  return v10604;
}

struct StateT * slot_106(struct StateT * v6688) {
  int v6689 = v6688->timer;
  int v6697 = v6689 + 1;
  v6688->timer = v6697;
  int * v6691 = v6688->regs;
  int v6692 = v6691[18];
  int v6693 = v6691[6];
  int v6701 = v6692 + v6693;
  v6691[6] = v6701;
  struct StateT * v6695 = slot_107(v6688);
  return v6695;
}

struct StateT * slot_98(struct StateT * v6532) {
  int v6533 = v6532->timer;
  int v6541 = v6533 + 1;
  v6532->timer = v6541;
  int * v6535 = v6532->regs;
  int v6536 = v6535[30];
  int v6537 = v6535[7];
  int v6545 = v6536 + v6537;
  v6535[7] = v6545;
  struct StateT * v6539 = slot_99(v6532);
  return v6539;
}

struct StateT * slot_159(struct StateT * v8963) {
  int * v8964 = v8963->saved_regs;
  int * v8965 = v8963->regs;
  int v8966 = v8965[5];
  v8964[5] = v8966;
  int v8968 = v8963->timer;
  int v8984 = v8968 + 1;
  v8963->timer = v8984;
  int * v8970 = v8963->regs;
  int v8971 = v8970[28];
  int v8972 = v8970[5];
  bool v8987 = (v8971 ^ -2147483648) < (v8972 ^ -2147483648);
  int v8975;
  if (v8987) {
    v8975 = 1;
  } else {
    v8975 = 0;
  }
  int * v8976 = v8963->regs;
  v8976[5] = v8975;
  struct StateT * v8978 = slot_160(v8963);
  return v8978;
}

struct StateT * slot_46(struct StateT * v4277) {
  int v4278 = v4277->timer;
  int v4286 = v4278 + 1;
  v4277->timer = v4286;
  int * v4280 = v4277->regs;
  int v4281 = v4280[28];
  int v4282 = v4280[13];
  int v4291 = (((((int)((unsigned int)v4281 >> 16)) * ((int)((unsigned int)v4282 >> 16))) + ((int)((unsigned int)((v4281 & 65535) * ((int)((unsigned int)v4282 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4281 >> 16)) * (v4282 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4281 & 65535) * (v4282 & 65535)) >> 16)) + (((v4281 & 65535) * ((int)((unsigned int)v4282 >> 16))) & 65535)) + ((((int)((unsigned int)v4281 >> 16)) * (v4282 & 65535)) & 65535)) >> 16));
  v4280[19] = v4291;
  struct StateT * v4284 = slot_47(v4277);
  return v4284;
}

struct StateT * slot_212(struct StateT * v11226) {
  int v11227 = v11226->timer;
  int v11235 = v11227 + 1;
  v11226->timer = v11235;
  int * v11229 = v11226->regs;
  int v11230 = v11229[13];
  int v11231 = v11229[17];
  int v11240 = (((((int)((unsigned int)v11230 >> 16)) * ((int)((unsigned int)v11231 >> 16))) + ((int)((unsigned int)((v11230 & 65535) * ((int)((unsigned int)v11231 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v11230 >> 16)) * (v11231 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v11230 & 65535) * (v11231 & 65535)) >> 16)) + (((v11230 & 65535) * ((int)((unsigned int)v11231 >> 16))) & 65535)) + ((((int)((unsigned int)v11230 >> 16)) * (v11231 & 65535)) & 65535)) >> 16));
  v11229[5] = v11240;
  struct StateT * v11233 = slot_213(v11226);
  return v11233;
}

struct StateT * slot_132(struct StateT * v8456) {
  int v8457 = v8456->timer;
  int v8465 = v8457 + 1;
  v8456->timer = v8465;
  int * v8459 = v8456->regs;
  int v8460 = v8459[29];
  int v8461 = v8459[12];
  int v8470 = (((((int)((unsigned int)v8460 >> 16)) * ((int)((unsigned int)v8461 >> 16))) + ((int)((unsigned int)((v8460 & 65535) * ((int)((unsigned int)v8461 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8460 >> 16)) * (v8461 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8460 & 65535) * (v8461 & 65535)) >> 16)) + (((v8460 & 65535) * ((int)((unsigned int)v8461 >> 16))) & 65535)) + ((((int)((unsigned int)v8460 >> 16)) * (v8461 & 65535)) & 65535)) >> 16));
  v8459[30] = v8470;
  struct StateT * v8463 = slot_133(v8456);
  return v8463;
}

struct StateT * slot_130(struct StateT * v8422) {
  int v8423 = v8422->timer;
  int v8431 = v8423 + 1;
  v8422->timer = v8431;
  int * v8425 = v8422->regs;
  int v8426 = v8425[6];
  int v8427 = v8425[12];
  int v8436 = (((((int)((unsigned int)v8426 >> 16)) * ((int)((unsigned int)v8427 >> 16))) + ((int)((unsigned int)((v8426 & 65535) * ((int)((unsigned int)v8427 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8426 >> 16)) * (v8427 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8426 & 65535) * (v8427 & 65535)) >> 16)) + (((v8426 & 65535) * ((int)((unsigned int)v8427 >> 16))) & 65535)) + ((((int)((unsigned int)v8426 >> 16)) * (v8427 & 65535)) & 65535)) >> 16));
  v8425[17] = v8436;
  struct StateT * v8429 = slot_131(v8422);
  return v8429;
}

struct StateT * slot_211(struct StateT * v11210) {
  int v11211 = v11210->timer;
  int v11219 = v11211 + 1;
  v11210->timer = v11219;
  int * v11213 = v11210->regs;
  int v11214 = v11213[12];
  int v11215 = v11213[5];
  int v11223 = v11214 | v11215;
  v11213[12] = v11223;
  struct StateT * v11217 = slot_212(v11210);
  return v11217;
}

struct StateT * slot_20(struct StateT * v2367) {
  int v2368 = v2367->timer;
  int v2376 = v2368 + 1;
  v2367->timer = v2376;
  int * v2370 = v2367->regs;
  int v2371 = v2370[6];
  int v2372 = v2370[15];
  int v2380 = v2371 + v2372;
  v2370[6] = v2380;
  struct StateT * v2374 = slot_21(v2367);
  return v2374;
}

struct StateT * slot_141(struct StateT * v8616) {
  int v8617 = v8616->timer;
  int v8625 = v8617 + 1;
  v8616->timer = v8625;
  int * v8619 = v8616->regs;
  int v8620 = v8619[31];
  int v8621 = v8619[29];
  int v8629 = v8620 + v8621;
  v8619[29] = v8629;
  struct StateT * v8623 = slot_142(v8616);
  return v8623;
}

struct StateT * slot_61(struct StateT * v4564) {
  int v4565 = v4564->timer;
  int v4573 = v4565 + 1;
  v4564->timer = v4573;
  int * v4567 = v4564->regs;
  int v4568 = v4567[19];
  int v4569 = v4567[6];
  int v4577 = v4568 + v4569;
  v4567[6] = v4577;
  struct StateT * v4571 = slot_62(v4564);
  return v4571;
}

struct StateT * slot_30(struct StateT * v4067) {
  int v4068 = v4067->timer;
  int v4076 = v4068 + 1;
  v4067->timer = v4076;
  int * v4070 = v4067->regs;
  int v4071 = v4070[29];
  int v4072 = v4070[5];
  int v4081 = v4071 + v4072;
  v4070[31] = v4081;
  struct StateT * v4074 = slot_31(v4067);
  return v4074;
}

struct StateT * slot_4(struct StateT * v961) {
  int v962 = v961->timer;
  int v1386 = v962 + 1;
  v961->timer = v1386;
  int * v964 = v961->regs;
  int v965 = v964[2];
  int v966 = v964[19];
  int * v967 = v961->saved_regs;
  int v968 = v964[14];
  v967[14] = v968;
  int v970 = v961->timer;
  int v1393 = v970 + 1;
  v961->timer = v1393;
  int * v972 = v961->regs;
  int v973 = v972[11];
  int * v974 = v961->cache_tags;
  int v1397 = (((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2;
  int v975 = v974[v1397];
  int v1398 = ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + 1;
  int v976 = v974[v1398];
  int v1399 = 4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2);
  int v977 = v974[v1399];
  int v1400 = (4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v978 = v974[v1400];
  int v979 = v961->timer;
  int v1401 = v979 + ((100 ^ (((~(((v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1401;
  int * v981 = v961->cache_vals;
  bool v1402 = !(((~(((v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) == 0);
  int v1074;
  if (v1402) {
    int * v982 = v961->cache_age;
    int v1404 = ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((~(((v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) & 1);
    int v983 = v982[v1404];
    int v984 = v982[v1397];
    int v1405 = v984 + ((int)((unsigned int)(v984 - v983) >> 31));
    v982[v1397] = v1405;
    int * v986 = v961->cache_age;
    int v987 = v986[v1398];
    int v1407 = v987 + ((int)((unsigned int)(v987 - v983) >> 31));
    v986[v1398] = v1407;
    int * v989 = v961->cache_age;
    v989[v1404] = 0;
    v1074 = v1404;
  } else {
    int * v992 = v961->cache_age;
    int v1411 = (((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2;
    int v993 = v992[v1411];
    int * v994 = v961->cache_tags;
    int v995 = v994[v1411];
    int v996 = v992[v1398];
    int v997 = v994[v1398];
    bool v1413 = !(((~(((v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) == 0);
    int v1051;
    if (v1413) {
      int * v998 = v961->cache_age;
      int v1415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) & 1);
      int v999 = v998[v1415];
      int v1000 = v998[v1399];
      int v1416 = v1000 + ((int)((unsigned int)(v1000 - v999) >> 31));
      v998[v1399] = v1416;
      int * v1002 = v961->cache_age;
      int v1003 = v1002[v1400];
      int v1418 = v1003 + ((int)((unsigned int)(v1003 - v999) >> 31));
      v1002[v1400] = v1418;
      int * v1005 = v961->cache_age;
      v1005[v1415] = 0;
      v1051 = v1415;
    } else {
      int * v1008 = v961->cache_age;
      int v1422 = 4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2);
      int v1009 = v1008[v1422];
      int * v1010 = v961->cache_tags;
      int v1011 = v1010[v1422];
      int v1012 = v1008[v1400];
      int v1013 = v1010[v1400];
      int * v1014 = v961->cache_dirty;
      int v1425 = (4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1015 = v1014[v1425];
      bool v1426 = !(v1015 == 0);
      if (v1426) {
        int * v1016 = v961->cache_tags;
        int v1017 = v1016[v1425];
        int * v1018 = v961->cache_vals;
        int v1429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1019 = v1018[v1429];
        int v1430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1020 = v1018[v1430];
        int * v1021 = v961->mem;
        int v1432 = v1017 * 2;
        v1021[v1432] = v1019;
        int * v1023 = v961->mem;
        int v1435 = (v1017 * 2) + 1;
        v1023[v1435] = v1020;
        ;
      } else {
        ;
      }
      int * v1028 = v961->mem;
      int v1440 = ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) * 2;
      int v1029 = v1028[v1440];
      int v1441 = (((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) * 2) + 1;
      int v1030 = v1028[v1441];
      int * v1031 = v961->cache_vals;
      int v1443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1031[v1443] = v1029;
      int * v1033 = v961->cache_vals;
      int v1446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1033[v1446] = v1030;
      int * v1035 = v961->cache_tags;
      int v1449 = (int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1);
      v1035[v1425] = v1449;
      int * v1037 = v961->cache_dirty;
      v1037[v1425] = 0;
      int * v1039 = v961->cache_age;
      v1039[v1425] = 1;
      int * v1041 = v961->cache_age;
      int v1042 = v1041[v1425];
      int v1043 = v1041[v1399];
      int v1455 = v1043 + ((int)((unsigned int)(v1043 - v1042) >> 31));
      v1041[v1399] = v1455;
      int * v1045 = v961->cache_age;
      int v1046 = v1045[v1400];
      int v1457 = v1046 + ((int)((unsigned int)(v1046 - v1042) >> 31));
      v1045[v1400] = v1457;
      int * v1048 = v961->cache_age;
      v1048[v1425] = 0;
      v1051 = v1425;
    }
    int * v1052 = v961->cache_vals;
    int v1460 = v1051 * 2;
    int v1053 = v1052[v1460];
    int v1461 = (v1051 * 2) + 1;
    int v1054 = v1052[v1461];
    int v1462 = (((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1052[v1462] = v1053;
    int * v1056 = v961->cache_vals;
    int v1465 = ((((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1056[v1465] = v1054;
    int * v1058 = v961->cache_tags;
    int v1468 = ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1469 = (int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1);
    v1058[v1468] = v1469;
    int * v1060 = v961->cache_dirty;
    v1060[v1468] = 0;
    int * v1062 = v961->cache_age;
    v1062[v1468] = 1;
    int * v1064 = v961->cache_age;
    int v1065 = v1064[v1468];
    int v1066 = v1064[v1397];
    int v1475 = v1066 + ((int)((unsigned int)(v1066 - v1065) >> 31));
    v1064[v1397] = v1475;
    int * v1068 = v961->cache_age;
    int v1069 = v1068[v1398];
    int v1477 = v1069 + ((int)((unsigned int)(v1069 - v1065) >> 31));
    v1068[v1398] = v1477;
    int * v1071 = v961->cache_age;
    v1071[v1468] = 0;
    v1074 = v1468;
  }
  int v1480 = (v1074 * 2) + (((int)((unsigned int)v973 >> 2)) & 1);
  int v1075 = v981[v1480];
  int * v1076 = v961->regs;
  v1076[14] = v1075;
  int * v1078 = v961->saved_regs;
  int * v1079 = v961->regs;
  int v1080 = v1079[15];
  v1078[15] = v1080;
  int v1082 = v961->timer;
  int v1487 = v1082 + 1;
  v961->timer = v1487;
  int * v1084 = v961->regs;
  int v1085 = v1084[11];
  int * v1086 = v961->cache_tags;
  int v1490 = (((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1087 = v1086[v1490];
  int v1491 = ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1088 = v1086[v1491];
  int v1492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1089 = v1086[v1492];
  int v1493 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1090 = v1086[v1493];
  int v1091 = v961->timer;
  int v1494 = v1091 + ((100 ^ (((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1494;
  int * v1093 = v961->cache_vals;
  bool v1495 = !(((~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1186;
  if (v1495) {
    int * v1094 = v961->cache_age;
    int v1497 = ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1095 = v1094[v1497];
    int v1096 = v1094[v1490];
    int v1498 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
    v1094[v1490] = v1498;
    int * v1098 = v961->cache_age;
    int v1099 = v1098[v1491];
    int v1500 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
    v1098[v1491] = v1500;
    int * v1101 = v961->cache_age;
    v1101[v1497] = 0;
    v1186 = v1497;
  } else {
    int * v1104 = v961->cache_age;
    int v1504 = (((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1105 = v1104[v1504];
    int * v1106 = v961->cache_tags;
    int v1107 = v1106[v1504];
    int v1108 = v1104[v1491];
    int v1109 = v1106[v1491];
    bool v1506 = !(((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1163;
    if (v1506) {
      int * v1110 = v961->cache_age;
      int v1508 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1111 = v1110[v1508];
      int v1112 = v1110[v1492];
      int v1509 = v1112 + ((int)((unsigned int)(v1112 - v1111) >> 31));
      v1110[v1492] = v1509;
      int * v1114 = v961->cache_age;
      int v1115 = v1114[v1493];
      int v1511 = v1115 + ((int)((unsigned int)(v1115 - v1111) >> 31));
      v1114[v1493] = v1511;
      int * v1117 = v961->cache_age;
      v1117[v1508] = 0;
      v1163 = v1508;
    } else {
      int * v1120 = v961->cache_age;
      int v1515 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1121 = v1120[v1515];
      int * v1122 = v961->cache_tags;
      int v1123 = v1122[v1515];
      int v1124 = v1120[v1493];
      int v1125 = v1122[v1493];
      int * v1126 = v961->cache_dirty;
      int v1518 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1127 = v1126[v1518];
      bool v1519 = !(v1127 == 0);
      if (v1519) {
        int * v1128 = v961->cache_tags;
        int v1129 = v1128[v1518];
        int * v1130 = v961->cache_vals;
        int v1522 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1131 = v1130[v1522];
        int v1523 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1132 = v1130[v1523];
        int * v1133 = v961->mem;
        int v1525 = v1129 * 2;
        v1133[v1525] = v1131;
        int * v1135 = v961->mem;
        int v1528 = (v1129 * 2) + 1;
        v1135[v1528] = v1132;
        ;
      } else {
        ;
      }
      int * v1140 = v961->mem;
      int v1533 = ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) * 2;
      int v1141 = v1140[v1533];
      int v1534 = (((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1142 = v1140[v1534];
      int * v1143 = v961->cache_vals;
      int v1536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1143[v1536] = v1141;
      int * v1145 = v961->cache_vals;
      int v1539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1145[v1539] = v1142;
      int * v1147 = v961->cache_tags;
      int v1542 = (int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1);
      v1147[v1518] = v1542;
      int * v1149 = v961->cache_dirty;
      v1149[v1518] = 0;
      int * v1151 = v961->cache_age;
      v1151[v1518] = 1;
      int * v1153 = v961->cache_age;
      int v1154 = v1153[v1518];
      int v1155 = v1153[v1492];
      int v1548 = v1155 + ((int)((unsigned int)(v1155 - v1154) >> 31));
      v1153[v1492] = v1548;
      int * v1157 = v961->cache_age;
      int v1158 = v1157[v1493];
      int v1550 = v1158 + ((int)((unsigned int)(v1158 - v1154) >> 31));
      v1157[v1493] = v1550;
      int * v1160 = v961->cache_age;
      v1160[v1518] = 0;
      v1163 = v1518;
    }
    int * v1164 = v961->cache_vals;
    int v1553 = v1163 * 2;
    int v1165 = v1164[v1553];
    int v1554 = (v1163 * 2) + 1;
    int v1166 = v1164[v1554];
    int v1555 = (((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1164[v1555] = v1165;
    int * v1168 = v961->cache_vals;
    int v1558 = ((((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1168[v1558] = v1166;
    int * v1170 = v961->cache_tags;
    int v1561 = ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1562 = (int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1);
    v1170[v1561] = v1562;
    int * v1172 = v961->cache_dirty;
    v1172[v1561] = 0;
    int * v1174 = v961->cache_age;
    v1174[v1561] = 1;
    int * v1176 = v961->cache_age;
    int v1177 = v1176[v1561];
    int v1178 = v1176[v1490];
    int v1568 = v1178 + ((int)((unsigned int)(v1178 - v1177) >> 31));
    v1176[v1490] = v1568;
    int * v1180 = v961->cache_age;
    int v1181 = v1180[v1491];
    int v1570 = v1181 + ((int)((unsigned int)(v1181 - v1177) >> 31));
    v1180[v1491] = v1570;
    int * v1183 = v961->cache_age;
    v1183[v1561] = 0;
    v1186 = v1561;
  }
  int v1573 = (v1186 * 2) + (((int)((unsigned int)(v1085 + 4) >> 2)) & 1);
  int v1187 = v1093[v1573];
  int * v1188 = v961->regs;
  v1188[15] = v1187;
  int * v1190 = v961->saved_regs;
  int * v1191 = v961->regs;
  int v1192 = v1191[16];
  v1190[16] = v1192;
  int v1194 = v961->timer;
  int v1580 = v1194 + 1;
  v961->timer = v1580;
  int * v1196 = v961->regs;
  v1196[16] = 524288;
  int v1198 = v961->timer;
  int v1583 = v1198 + 1;
  v961->timer = v1583;
  int * v1200 = v961->regs;
  int v1201 = v1200[16];
  int v1585 = v1201 + -1;
  v1200[16] = v1585;
  int * v1203 = v961->cache_tags;
  int v1587 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
  int v1204 = v1203[v1587];
  int v1588 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1205 = v1203[v1588];
  int v1589 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
  int v1206 = v1203[v1589];
  int v1590 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1207 = v1203[v1590];
  int v1208 = v961->timer;
  int v1591 = v1208 + ((100 ^ (((~(((v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1591;
  bool v1592 = !(((~(((v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1302;
  if (v1592) {
    int * v1210 = v961->cache_age;
    int v1594 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((~(((v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v1211 = v1210[v1594];
    int v1212 = v1210[v1587];
    int v1595 = v1212 + ((int)((unsigned int)(v1212 - v1211) >> 31));
    v1210[v1587] = v1595;
    int * v1214 = v961->cache_age;
    int v1215 = v1214[v1588];
    int v1597 = v1215 + ((int)((unsigned int)(v1215 - v1211) >> 31));
    v1214[v1588] = v1597;
    int * v1217 = v961->cache_age;
    v1217[v1594] = 0;
    v1302 = v1594;
  } else {
    int * v1220 = v961->cache_age;
    int v1601 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
    int v1221 = v1220[v1601];
    int * v1222 = v961->cache_tags;
    int v1223 = v1222[v1601];
    int v1224 = v1220[v1588];
    int v1225 = v1222[v1588];
    bool v1603 = !(((~(((v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
    int v1279;
    if (v1603) {
      int * v1226 = v961->cache_age;
      int v1605 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
      int v1227 = v1226[v1605];
      int v1228 = v1226[v1589];
      int v1606 = v1228 + ((int)((unsigned int)(v1228 - v1227) >> 31));
      v1226[v1589] = v1606;
      int * v1230 = v961->cache_age;
      int v1231 = v1230[v1590];
      int v1608 = v1231 + ((int)((unsigned int)(v1231 - v1227) >> 31));
      v1230[v1590] = v1608;
      int * v1233 = v961->cache_age;
      v1233[v1605] = 0;
      v1279 = v1605;
    } else {
      int * v1236 = v961->cache_age;
      int v1612 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
      int v1237 = v1236[v1612];
      int * v1238 = v961->cache_tags;
      int v1239 = v1238[v1612];
      int v1240 = v1236[v1590];
      int v1241 = v1238[v1590];
      int * v1242 = v961->cache_dirty;
      int v1615 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1243 = v1242[v1615];
      bool v1616 = !(v1243 == 0);
      if (v1616) {
        int * v1244 = v961->cache_tags;
        int v1245 = v1244[v1615];
        int * v1246 = v961->cache_vals;
        int v1619 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1247 = v1246[v1619];
        int v1620 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1248 = v1246[v1620];
        int * v1249 = v961->mem;
        int v1622 = v1245 * 2;
        v1249[v1622] = v1247;
        int * v1251 = v961->mem;
        int v1625 = (v1245 * 2) + 1;
        v1251[v1625] = v1248;
        ;
      } else {
        ;
      }
      int * v1256 = v961->mem;
      int v1630 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
      int v1257 = v1256[v1630];
      int v1631 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
      int v1258 = v1256[v1631];
      int * v1259 = v961->cache_vals;
      int v1633 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1259[v1633] = v1257;
      int * v1261 = v961->cache_vals;
      int v1636 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1261[v1636] = v1258;
      int * v1263 = v961->cache_tags;
      int v1639 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
      v1263[v1615] = v1639;
      int * v1265 = v961->cache_dirty;
      v1265[v1615] = 0;
      int * v1267 = v961->cache_age;
      v1267[v1615] = 1;
      int * v1269 = v961->cache_age;
      int v1270 = v1269[v1615];
      int v1271 = v1269[v1589];
      int v1645 = v1271 + ((int)((unsigned int)(v1271 - v1270) >> 31));
      v1269[v1589] = v1645;
      int * v1273 = v961->cache_age;
      int v1274 = v1273[v1590];
      int v1647 = v1274 + ((int)((unsigned int)(v1274 - v1270) >> 31));
      v1273[v1590] = v1647;
      int * v1276 = v961->cache_age;
      v1276[v1615] = 0;
      v1279 = v1615;
    }
    int * v1280 = v961->cache_vals;
    int v1650 = v1279 * 2;
    int v1281 = v1280[v1650];
    int v1651 = (v1279 * 2) + 1;
    int v1282 = v1280[v1651];
    int v1652 = (((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v1221 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2)) - (v1224 + ((~(((v1225 ^ -1) | (-(v1225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1280[v1652] = v1281;
    int * v1284 = v961->cache_vals;
    int v1655 = ((((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v1221 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2)) - (v1224 + ((~(((v1225 ^ -1) | (-(v1225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1284[v1655] = v1282;
    int * v1286 = v961->cache_tags;
    int v1658 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v1221 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2)) - (v1224 + ((~(((v1225 ^ -1) | (-(v1225 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1659 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1286[v1658] = v1659;
    int * v1288 = v961->cache_dirty;
    v1288[v1658] = 0;
    int * v1290 = v961->cache_age;
    v1290[v1658] = 1;
    int * v1292 = v961->cache_age;
    int v1293 = v1292[v1658];
    int v1294 = v1292[v1587];
    int v1665 = v1294 + ((int)((unsigned int)(v1294 - v1293) >> 31));
    v1292[v1587] = v1665;
    int * v1296 = v961->cache_age;
    int v1297 = v1296[v1588];
    int v1667 = v1297 + ((int)((unsigned int)(v1297 - v1293) >> 31));
    v1296[v1588] = v1667;
    int * v1299 = v961->cache_age;
    v1299[v1658] = 0;
    v1302 = v1658;
  }
  int * v1303 = v961->cache_vals;
  int v1670 = (v1302 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1303[v1670] = v966;
  int * v1305 = v961->cache_tags;
  int v1306 = v1305[v1589];
  int v1307 = v1305[v1590];
  bool v1673 = !(((~(((v1306 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1306 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1361;
  if (v1673) {
    int * v1308 = v961->cache_age;
    int v1675 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v1309 = v1308[v1675];
    int v1310 = v1308[v1589];
    int v1676 = v1310 + ((int)((unsigned int)(v1310 - v1309) >> 31));
    v1308[v1589] = v1676;
    int * v1312 = v961->cache_age;
    int v1313 = v1312[v1590];
    int v1678 = v1313 + ((int)((unsigned int)(v1313 - v1309) >> 31));
    v1312[v1590] = v1678;
    int * v1315 = v961->cache_age;
    v1315[v1675] = 0;
    v1361 = v1675;
  } else {
    int * v1318 = v961->cache_age;
    int v1682 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
    int v1319 = v1318[v1682];
    int * v1320 = v961->cache_tags;
    int v1321 = v1320[v1682];
    int v1322 = v1318[v1590];
    int v1323 = v1320[v1590];
    int * v1324 = v961->cache_dirty;
    int v1685 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1325 = v1324[v1685];
    bool v1686 = !(v1325 == 0);
    if (v1686) {
      int * v1326 = v961->cache_tags;
      int v1327 = v1326[v1685];
      int * v1328 = v961->cache_vals;
      int v1689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1329 = v1328[v1689];
      int v1690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1330 = v1328[v1690];
      int * v1331 = v961->mem;
      int v1692 = v1327 * 2;
      v1331[v1692] = v1329;
      int * v1333 = v961->mem;
      int v1695 = (v1327 * 2) + 1;
      v1333[v1695] = v1330;
      ;
    } else {
      ;
    }
    int * v1338 = v961->mem;
    int v1700 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
    int v1339 = v1338[v1700];
    int v1701 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
    int v1340 = v1338[v1701];
    int * v1341 = v961->cache_vals;
    int v1703 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1341[v1703] = v1339;
    int * v1343 = v961->cache_vals;
    int v1706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1343[v1706] = v1340;
    int * v1345 = v961->cache_tags;
    int v1709 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1345[v1685] = v1709;
    int * v1347 = v961->cache_dirty;
    v1347[v1685] = 0;
    int * v1349 = v961->cache_age;
    v1349[v1685] = 1;
    int * v1351 = v961->cache_age;
    int v1352 = v1351[v1685];
    int v1353 = v1351[v1589];
    int v1715 = v1353 + ((int)((unsigned int)(v1353 - v1352) >> 31));
    v1351[v1589] = v1715;
    int * v1355 = v961->cache_age;
    int v1356 = v1355[v1590];
    int v1717 = v1356 + ((int)((unsigned int)(v1356 - v1352) >> 31));
    v1355[v1590] = v1717;
    int * v1358 = v961->cache_age;
    v1358[v1685] = 0;
    v1361 = v1685;
  }
  int * v1362 = v961->cache_vals;
  int v1720 = (v1361 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1362[v1720] = v966;
  int * v1364 = v961->cache_dirty;
  v1364[v1361] = 1;
  bool v1724 = (((int)((unsigned int)v973 >> 2)) == ((int)((unsigned int)v965 >> 2))) | (((int)((unsigned int)(v1085 + 4) >> 2)) == ((int)((unsigned int)v965 >> 2)));
  struct StateT * v1384;
  if (v1724) {
    int v1366 = v961->timer;
    int v1725 = v1366 + 15;
    v961->timer = v1725;
    int * v1368 = v961->saved_regs;
    int v1369 = v1368[14];
    int * v1370 = v961->regs;
    v1370[14] = v1369;
    int * v1372 = v961->saved_regs;
    int v1373 = v1372[15];
    int * v1374 = v961->regs;
    v1374[15] = v1373;
    int * v1376 = v961->saved_regs;
    int v1377 = v1376[16];
    int * v1378 = v961->regs;
    v1378[16] = v1377;
    struct StateT * v1380 = slot_5(v961);
    v1384 = v1380;
  } else {
    struct StateT * v1382 = slot_9(v961);
    v1384 = v1382;
  }
  return v1384;
}

struct StateT * slot_18(struct StateT * v2326) {
  int v2327 = v2326->timer;
  int v2339 = v2327 + 1;
  v2326->timer = v2339;
  int * v2329 = v2326->regs;
  int v2330 = v2329[17];
  int v2331 = v2329[5];
  bool v2343 = (v2330 ^ -2147483648) < (v2331 ^ -2147483648);
  int v2334;
  if (v2343) {
    v2334 = 1;
  } else {
    v2334 = 0;
  }
  int * v2335 = v2326->regs;
  v2335[15] = v2334;
  struct StateT * v2337 = slot_19(v2326);
  return v2337;
}

struct StateT * slot_9(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1953 = v1945 + 1;
  v1944->timer = v1953;
  int * v1947 = v1944->regs;
  int v1948 = v1947[14];
  int v1949 = v1947[12];
  int v1958 = (((((int)((unsigned int)v1948 >> 16)) * ((int)((unsigned int)v1949 >> 16))) + ((int)((unsigned int)((v1948 & 65535) * ((int)((unsigned int)v1949 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1948 >> 16)) * (v1949 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1948 & 65535) * (v1949 & 65535)) >> 16)) + (((v1948 & 65535) * ((int)((unsigned int)v1949 >> 16))) & 65535)) + ((((int)((unsigned int)v1948 >> 16)) * (v1949 & 65535)) & 65535)) >> 16));
  v1947[17] = v1958;
  struct StateT * v1951 = slot_10(v1944);
  return v1951;
}

struct StateT * slot_183(struct StateT * v10680) {
  int v10681 = v10680->timer;
  int v10689 = v10681 + 1;
  v10680->timer = v10689;
  int * v10683 = v10680->regs;
  int v10684 = v10683[28];
  int v10685 = v10683[5];
  int v10693 = v10684 + v10685;
  v10683[5] = v10693;
  struct StateT * v10687 = slot_184(v10680);
  return v10687;
}

struct StateT * slot_240(struct StateT * v14557) {
  int v14558 = v14557->timer;
  int v14565 = v14558 + 1;
  v14557->timer = v14565;
  int * v14560 = v14557->regs;
  int v14561 = v14560[5];
  int v14568 = (int)((unsigned int)v14561 >> 19);
  v14560[5] = v14568;
  struct StateT * v14563 = slot_241(v14557);
  return v14563;
}

struct StateT * slot_247(struct StateT * v14666) {
  int v14667 = v14666->timer;
  int v14675 = v14667 + 1;
  v14666->timer = v14675;
  int * v14669 = v14666->regs;
  int v14670 = v14669[12];
  int v14671 = v14669[17];
  int v14679 = v14670 * v14671;
  v14669[12] = v14679;
  struct StateT * v14673 = slot_248(v14666);
  return v14673;
}

struct StateT * slot_43(struct StateT * v4230) {
  int v4231 = v4230->timer;
  int v4238 = v4231 + 1;
  v4230->timer = v4238;
  int * v4233 = v4230->regs;
  int v4234 = v4233[5];
  int v4241 = v4234 << 13;
  v4233[5] = v4241;
  struct StateT * v4236 = slot_44(v4230);
  return v4236;
}

struct StateT * slot_70(struct StateT * v4744) {
  int * v4745 = v4744->saved_regs;
  int v4746 = v4745[7];
  int v4747 = v4745[29];
  bool v4775 = v4746 == v4747;
  struct StateT * v4770;
  if (v4775) {
    int v4748 = v4744->timer;
    int v4776 = v4748 + 15;
    v4744->timer = v4776;
    int * v4750 = v4744->saved_regs;
    int v4751 = v4750[28];
    int * v4752 = v4744->regs;
    v4752[28] = v4751;
    int * v4754 = v4744->saved_regs;
    int v4755 = v4754[29];
    int * v4756 = v4744->regs;
    v4756[29] = v4755;
    int * v4758 = v4744->saved_regs;
    int v4759 = v4758[7];
    int * v4760 = v4744->regs;
    v4760[7] = v4759;
    int * v4762 = v4744->saved_regs;
    int v4763 = v4762[5];
    int * v4764 = v4744->regs;
    v4764[5] = v4763;
    struct StateT * v4766 = slot_71(v4744);
    v4770 = v4766;
  } else {
    struct StateT * v4768 = slot_72(v4744);
    v4770 = v4768;
  }
  return v4770;
}

struct StateT * slot_168(struct StateT * v10296) {
  int v10297 = v10296->timer;
  int v10305 = v10297 + 1;
  v10296->timer = v10305;
  int * v10299 = v10296->regs;
  int v10300 = v10299[6];
  int v10301 = v10299[5];
  int v10309 = v10300 + v10301;
  v10299[5] = v10309;
  struct StateT * v10303 = slot_169(v10296);
  return v10303;
}

struct StateT * slot_76(struct StateT * v5774) {
  int v5775 = v5774->timer;
  int v5782 = v5775 + 1;
  v5774->timer = v5782;
  int * v5777 = v5774->regs;
  int v5778 = v5777[28];
  int v5786 = (int)((unsigned int)v5778 >> 19);
  v5777[17] = v5786;
  struct StateT * v5780 = slot_77(v5774);
  return v5780;
}

struct StateT * slot_6(struct StateT * v1961) {
  int v1962 = v1961->timer;
  int v2072 = v1962 + 1;
  v1961->timer = v2072;
  int * v1964 = v1961->regs;
  int v1965 = v1964[11];
  int * v1966 = v1961->cache_tags;
  int v2076 = (((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1967 = v1966[v2076];
  int v2077 = ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1968 = v1966[v2077];
  int v2078 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1969 = v1966[v2078];
  int v2079 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1970 = v1966[v2079];
  int v1971 = v1961->timer;
  int v2080 = v1971 + ((100 ^ (((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1961->timer = v2080;
  int * v1973 = v1961->cache_vals;
  bool v2081 = !(((~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2066;
  if (v2081) {
    int * v1974 = v1961->cache_age;
    int v2083 = ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1975 = v1974[v2083];
    int v1976 = v1974[v2076];
    int v2084 = v1976 + ((int)((unsigned int)(v1976 - v1975) >> 31));
    v1974[v2076] = v2084;
    int * v1978 = v1961->cache_age;
    int v1979 = v1978[v2077];
    int v2086 = v1979 + ((int)((unsigned int)(v1979 - v1975) >> 31));
    v1978[v2077] = v2086;
    int * v1981 = v1961->cache_age;
    v1981[v2083] = 0;
    v2066 = v2083;
  } else {
    int * v1984 = v1961->cache_age;
    int v2090 = (((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1985 = v1984[v2090];
    int * v1986 = v1961->cache_tags;
    int v1987 = v1986[v2090];
    int v1988 = v1984[v2077];
    int v1989 = v1986[v2077];
    bool v2092 = !(((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2043;
    if (v2092) {
      int * v1990 = v1961->cache_age;
      int v2094 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1991 = v1990[v2094];
      int v1992 = v1990[v2078];
      int v2095 = v1992 + ((int)((unsigned int)(v1992 - v1991) >> 31));
      v1990[v2078] = v2095;
      int * v1994 = v1961->cache_age;
      int v1995 = v1994[v2079];
      int v2097 = v1995 + ((int)((unsigned int)(v1995 - v1991) >> 31));
      v1994[v2079] = v2097;
      int * v1997 = v1961->cache_age;
      v1997[v2094] = 0;
      v2043 = v2094;
    } else {
      int * v2000 = v1961->cache_age;
      int v2101 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2001 = v2000[v2101];
      int * v2002 = v1961->cache_tags;
      int v2003 = v2002[v2101];
      int v2004 = v2000[v2079];
      int v2005 = v2002[v2079];
      int * v2006 = v1961->cache_dirty;
      int v2104 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2007 = v2006[v2104];
      bool v2105 = !(v2007 == 0);
      if (v2105) {
        int * v2008 = v1961->cache_tags;
        int v2009 = v2008[v2104];
        int * v2010 = v1961->cache_vals;
        int v2108 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2011 = v2010[v2108];
        int v2109 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2012 = v2010[v2109];
        int * v2013 = v1961->mem;
        int v2111 = v2009 * 2;
        v2013[v2111] = v2011;
        int * v2015 = v1961->mem;
        int v2114 = (v2009 * 2) + 1;
        v2015[v2114] = v2012;
        ;
      } else {
        ;
      }
      int * v2020 = v1961->mem;
      int v2119 = ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) * 2;
      int v2021 = v2020[v2119];
      int v2120 = (((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2022 = v2020[v2120];
      int * v2023 = v1961->cache_vals;
      int v2122 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2023[v2122] = v2021;
      int * v2025 = v1961->cache_vals;
      int v2125 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2025[v2125] = v2022;
      int * v2027 = v1961->cache_tags;
      int v2128 = (int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1);
      v2027[v2104] = v2128;
      int * v2029 = v1961->cache_dirty;
      v2029[v2104] = 0;
      int * v2031 = v1961->cache_age;
      v2031[v2104] = 1;
      int * v2033 = v1961->cache_age;
      int v2034 = v2033[v2104];
      int v2035 = v2033[v2078];
      int v2134 = v2035 + ((int)((unsigned int)(v2035 - v2034) >> 31));
      v2033[v2078] = v2134;
      int * v2037 = v1961->cache_age;
      int v2038 = v2037[v2079];
      int v2136 = v2038 + ((int)((unsigned int)(v2038 - v2034) >> 31));
      v2037[v2079] = v2136;
      int * v2040 = v1961->cache_age;
      v2040[v2104] = 0;
      v2043 = v2104;
    }
    int * v2044 = v1961->cache_vals;
    int v2139 = v2043 * 2;
    int v2045 = v2044[v2139];
    int v2140 = (v2043 * 2) + 1;
    int v2046 = v2044[v2140];
    int v2141 = (((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1985 + ((~(((v1987 ^ -1) | (-(v1987 ^ -1))) >> 31)) & 2)) - (v1988 + ((~(((v1989 ^ -1) | (-(v1989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2044[v2141] = v2045;
    int * v2048 = v1961->cache_vals;
    int v2144 = ((((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1985 + ((~(((v1987 ^ -1) | (-(v1987 ^ -1))) >> 31)) & 2)) - (v1988 + ((~(((v1989 ^ -1) | (-(v1989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2048[v2144] = v2046;
    int * v2050 = v1961->cache_tags;
    int v2147 = ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1985 + ((~(((v1987 ^ -1) | (-(v1987 ^ -1))) >> 31)) & 2)) - (v1988 + ((~(((v1989 ^ -1) | (-(v1989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2148 = (int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1);
    v2050[v2147] = v2148;
    int * v2052 = v1961->cache_dirty;
    v2052[v2147] = 0;
    int * v2054 = v1961->cache_age;
    v2054[v2147] = 1;
    int * v2056 = v1961->cache_age;
    int v2057 = v2056[v2147];
    int v2058 = v2056[v2076];
    int v2154 = v2058 + ((int)((unsigned int)(v2058 - v2057) >> 31));
    v2056[v2076] = v2154;
    int * v2060 = v1961->cache_age;
    int v2061 = v2060[v2077];
    int v2156 = v2061 + ((int)((unsigned int)(v2061 - v2057) >> 31));
    v2060[v2077] = v2156;
    int * v2063 = v1961->cache_age;
    v2063[v2147] = 0;
    v2066 = v2147;
  }
  int v2159 = (v2066 * 2) + (((int)((unsigned int)(v1965 + 4) >> 2)) & 1);
  int v2067 = v1973[v2159];
  int * v2068 = v1961->regs;
  v2068[15] = v2067;
  struct StateT * v2070 = slot_7(v1961);
  return v2070;
}

struct StateT * slot_225(struct StateT * v12118) {
  int v12119 = v12118->timer;
  int v12126 = v12119 + 1;
  v12118->timer = v12126;
  int * v12121 = v12118->regs;
  int v12122 = v12121[17];
  int v12129 = (int)((unsigned int)v12122 >> 19);
  v12121[17] = v12129;
  struct StateT * v12124 = slot_227(v12118);
  return v12124;
}

struct StateT * slot_55(struct StateT * v4449) {
  int v4450 = v4449->timer;
  int v4458 = v4450 + 1;
  v4449->timer = v4458;
  int * v4452 = v4449->regs;
  int v4453 = v4452[29];
  int v4454 = v4452[5];
  int v4463 = v4453 + v4454;
  v4452[7] = v4463;
  struct StateT * v4456 = slot_56(v4449);
  return v4456;
}

struct StateT * slot_213(struct StateT * v11243) {
  int v11244 = v11243->timer;
  int v11252 = v11244 + 1;
  v11243->timer = v11252;
  int * v11246 = v11243->regs;
  int v11247 = v11246[13];
  int v11248 = v11246[17];
  int v11256 = v11247 * v11248;
  v11246[13] = v11256;
  struct StateT * v11250 = slot_214(v11243);
  return v11250;
}

struct StateT * slot_82(struct StateT * v6031) {
  int v6032 = v6031->timer;
  int v6040 = v6032 + 1;
  v6031->timer = v6040;
  int * v6034 = v6031->regs;
  int v6035 = v6034[7];
  int v6036 = v6034[28];
  int v6044 = v6035 | v6036;
  v6034[7] = v6044;
  struct StateT * v6038 = slot_83(v6031);
  return v6038;
}

struct StateT * slot_161(struct StateT * v9046) {
  int v9047 = v9046->timer;
  int v9055 = v9047 + 1;
  v9046->timer = v9055;
  int * v9049 = v9046->regs;
  int v9050 = v9049[5];
  int v9051 = v9049[28];
  int v9059 = v9050 + v9051;
  v9049[28] = v9059;
  struct StateT * v9053 = slot_163(v9046);
  return v9053;
}

struct StateT * slot_185(struct StateT * v10713) {
  int v10714 = v10713->timer;
  int v10726 = v10714 + 1;
  v10713->timer = v10726;
  int * v10716 = v10713->regs;
  int v10717 = v10716[5];
  int v10718 = v10716[28];
  bool v10730 = (v10717 ^ -2147483648) < (v10718 ^ -2147483648);
  int v10721;
  if (v10730) {
    v10721 = 1;
  } else {
    v10721 = 0;
  }
  int * v10722 = v10713->regs;
  v10722[7] = v10721;
  struct StateT * v10724 = slot_186(v10713);
  return v10724;
}

struct StateT * slot_91(struct StateT * v6399) {
  int v6400 = v6399->timer;
  int v6408 = v6400 + 1;
  v6399->timer = v6408;
  int * v6402 = v6399->regs;
  int v6403 = v6402[29];
  int v6404 = v6402[13];
  int v6413 = (((((int)((unsigned int)v6403 >> 16)) * ((int)((unsigned int)v6404 >> 16))) + ((int)((unsigned int)((v6403 & 65535) * ((int)((unsigned int)v6404 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6403 >> 16)) * (v6404 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6403 & 65535) * (v6404 & 65535)) >> 16)) + (((v6403 & 65535) * ((int)((unsigned int)v6404 >> 16))) & 65535)) + ((((int)((unsigned int)v6403 >> 16)) * (v6404 & 65535)) & 65535)) >> 16));
  v6402[18] = v6413;
  struct StateT * v6406 = slot_92(v6399);
  return v6406;
}

struct StateT * slot_58(struct StateT * v4498) {
  int v4499 = v4498->timer;
  int v4507 = v4499 + 1;
  v4498->timer = v4507;
  int * v4501 = v4498->regs;
  int v4502 = v4501[18];
  int v4503 = v4501[6];
  int v4512 = v4502 + v4503;
  v4501[5] = v4512;
  struct StateT * v4505 = slot_59(v4498);
  return v4505;
}

struct StateT * slot_89(struct StateT * v6365) {
  int v6366 = v6365->timer;
  int v6374 = v6366 + 1;
  v6365->timer = v6374;
  int * v6368 = v6365->regs;
  int v6369 = v6368[6];
  int v6370 = v6368[13];
  int v6379 = (((((int)((unsigned int)v6369 >> 16)) * ((int)((unsigned int)v6370 >> 16))) + ((int)((unsigned int)((v6369 & 65535) * ((int)((unsigned int)v6370 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6369 >> 16)) * (v6370 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6369 & 65535) * (v6370 & 65535)) >> 16)) + (((v6369 & 65535) * ((int)((unsigned int)v6370 >> 16))) & 65535)) + ((((int)((unsigned int)v6369 >> 16)) * (v6370 & 65535)) & 65535)) >> 16));
  v6368[8] = v6379;
  struct StateT * v6372 = slot_90(v6365);
  return v6372;
}

struct StateT * slot_66(struct StateT * v4652) {
  int v4653 = v4652->timer;
  int v4661 = v4653 + 1;
  v4652->timer = v4661;
  int * v4655 = v4652->regs;
  int v4656 = v4655[5];
  int v4657 = v4655[28];
  int v4665 = v4656 + v4657;
  v4655[28] = v4665;
  struct StateT * v4659 = slot_67(v4652);
  return v4659;
}

struct StateT * slot_140(struct StateT * v8591) {
  int v8592 = v8591->timer;
  int v8604 = v8592 + 1;
  v8591->timer = v8604;
  int * v8594 = v8591->regs;
  int v8595 = v8594[29];
  int v8596 = v8594[28];
  bool v8608 = (v8595 ^ -2147483648) < (v8596 ^ -2147483648);
  int v8599;
  if (v8608) {
    v8599 = 1;
  } else {
    v8599 = 0;
  }
  int * v8600 = v8591->regs;
  v8600[7] = v8599;
  struct StateT * v8602 = slot_141(v8591);
  return v8602;
}

struct StateT * slot_49(struct StateT * v4326) {
  int v4327 = v4326->timer;
  int v4335 = v4327 + 1;
  v4326->timer = v4335;
  int * v4329 = v4326->regs;
  int v4330 = v4329[7];
  int v4331 = v4329[17];
  int v4339 = v4330 + v4331;
  v4329[17] = v4339;
  struct StateT * v4333 = slot_50(v4326);
  return v4333;
}

struct StateT * slot_216(struct StateT * v11298) {
  int v11299 = v11298->timer;
  int v11307 = v11299 + 1;
  v11298->timer = v11307;
  int * v11301 = v11298->regs;
  int v11302 = v11301[12];
  int v11303 = v11301[17];
  int v11311 = v11302 * v11303;
  v11301[12] = v11311;
  struct StateT * v11305 = slot_217(v11298);
  return v11305;
}

struct StateT * slot_50(struct StateT * v4342) {
  int v4343 = v4342->timer;
  int v4355 = v4343 + 1;
  v4342->timer = v4355;
  int * v4345 = v4342->regs;
  int v4346 = v4345[6];
  int v4347 = v4345[30];
  bool v4359 = (v4346 ^ -2147483648) < (v4347 ^ -2147483648);
  int v4350;
  if (v4359) {
    v4350 = 1;
  } else {
    v4350 = 0;
  }
  int * v4351 = v4342->regs;
  v4351[30] = v4350;
  struct StateT * v4353 = slot_51(v4342);
  return v4353;
}

struct StateT * slot_37(struct StateT * v4129) {
  int v4130 = v4129->timer;
  int v4138 = v4130 + 1;
  v4129->timer = v4138;
  int * v4132 = v4129->regs;
  int v4133 = v4132[17];
  int v4134 = v4132[31];
  int v4142 = v4133 | v4134;
  v4132[17] = v4142;
  struct StateT * v4136 = slot_38(v4129);
  return v4136;
}

struct StateT * slot_114(struct StateT * v6838) {
  int * v6839 = v6838->saved_regs;
  int * v6840 = v6838->regs;
  int v6841 = v6840[5];
  v6839[5] = v6841;
  int v6843 = v6838->timer;
  int v6859 = v6843 + 1;
  v6838->timer = v6859;
  int * v6845 = v6838->regs;
  int v6846 = v6845[28];
  int v6847 = v6845[5];
  bool v6862 = (v6846 ^ -2147483648) < (v6847 ^ -2147483648);
  int v6850;
  if (v6862) {
    v6850 = 1;
  } else {
    v6850 = 0;
  }
  int * v6851 = v6838->regs;
  v6851[5] = v6850;
  struct StateT * v6853 = slot_115(v6838);
  return v6853;
}

struct StateT * slot_135(struct StateT * v8507) {
  int v8508 = v8507->timer;
  int v8516 = v8508 + 1;
  v8507->timer = v8516;
  int * v8510 = v8507->regs;
  int v8511 = v8510[29];
  int v8512 = v8510[13];
  int v8521 = v8511 * v8512;
  v8510[9] = v8521;
  struct StateT * v8514 = slot_136(v8507);
  return v8514;
}

struct StateT * slot_248(struct StateT * v14682) {
  int v14683 = v14682->timer;
  int v14695 = v14683 + 1;
  v14682->timer = v14695;
  int * v14685 = v14682->regs;
  int v14686 = v14685[13];
  int v14687 = v14685[14];
  bool v14699 = (v14686 ^ -2147483648) < (v14687 ^ -2147483648);
  int v14690;
  if (v14699) {
    v14690 = 1;
  } else {
    v14690 = 0;
  }
  int * v14691 = v14682->regs;
  v14691[14] = v14690;
  struct StateT * v14693 = slot_249(v14682);
  return v14693;
}

struct StateT * slot_59(struct StateT * v4515) {
  int v4516 = v4515->timer;
  int v4528 = v4516 + 1;
  v4515->timer = v4528;
  int * v4518 = v4515->regs;
  int v4519 = v4518[6];
  int v4520 = v4518[30];
  bool v4532 = (v4519 ^ -2147483648) < (v4520 ^ -2147483648);
  int v4523;
  if (v4532) {
    v4523 = 1;
  } else {
    v4523 = 0;
  }
  int * v4524 = v4515->regs;
  v4524[6] = v4523;
  struct StateT * v4526 = slot_60(v4515);
  return v4526;
}

struct StateT * slot_192(struct StateT * v10853) {
  int v10854 = v10853->timer;
  int v10862 = v10854 + 1;
  v10853->timer = v10862;
  int * v10856 = v10853->regs;
  int v10857 = v10856[7];
  int v10858 = v10856[12];
  int v10867 = v10857 + v10858;
  v10856[28] = v10867;
  struct StateT * v10860 = slot_193(v10853);
  return v10860;
}

struct StateT * slot_40(struct StateT * v4179) {
  int v4180 = v4179->timer;
  int v4188 = v4180 + 1;
  v4179->timer = v4188;
  int * v4182 = v4179->regs;
  int v4183 = v4182[28];
  int v4184 = v4182[12];
  int v4193 = (((((int)((unsigned int)v4183 >> 16)) * ((int)((unsigned int)v4184 >> 16))) + ((int)((unsigned int)((v4183 & 65535) * ((int)((unsigned int)v4184 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4183 >> 16)) * (v4184 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4183 & 65535) * (v4184 & 65535)) >> 16)) + (((v4183 & 65535) * ((int)((unsigned int)v4184 >> 16))) & 65535)) + ((((int)((unsigned int)v4183 >> 16)) * (v4184 & 65535)) & 65535)) >> 16));
  v4182[31] = v4193;
  struct StateT * v4186 = slot_41(v4179);
  return v4186;
}

struct StateT * slot_48(struct StateT * v4310) {
  int v4311 = v4310->timer;
  int v4319 = v4311 + 1;
  v4310->timer = v4319;
  int * v4313 = v4310->regs;
  int v4314 = v4313[30];
  int v4315 = v4313[6];
  int v4323 = v4314 + v4315;
  v4313[6] = v4323;
  struct StateT * v4317 = slot_49(v4310);
  return v4317;
}

struct StateT * slot_77(struct StateT * v6017) {
  int v6018 = v6017->timer;
  int v6025 = v6018 + 1;
  v6017->timer = v6025;
  int * v6020 = v6017->regs;
  int v6021 = v6020[28];
  int v6028 = v6021 << 13;
  v6020[28] = v6028;
  struct StateT * v6023 = slot_78(v6017);
  return v6023;
}

struct StateT * slot_85(struct StateT * v6297) {
  int v6298 = v6297->timer;
  int v6306 = v6298 + 1;
  v6297->timer = v6306;
  int * v6300 = v6297->regs;
  int v6301 = v6300[6];
  int v6302 = v6300[12];
  int v6311 = (((((int)((unsigned int)v6301 >> 16)) * ((int)((unsigned int)v6302 >> 16))) + ((int)((unsigned int)((v6301 & 65535) * ((int)((unsigned int)v6302 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6301 >> 16)) * (v6302 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6301 & 65535) * (v6302 & 65535)) >> 16)) + (((v6301 & 65535) * ((int)((unsigned int)v6302 >> 16))) & 65535)) + ((((int)((unsigned int)v6301 >> 16)) * (v6302 & 65535)) & 65535)) >> 16));
  v6300[17] = v6311;
  struct StateT * v6304 = slot_86(v6297);
  return v6304;
}

struct StateT * slot_75(struct StateT * v5760) {
  int v5761 = v5760->timer;
  int v5768 = v5761 + 1;
  v5760->timer = v5768;
  int * v5763 = v5760->regs;
  int v5764 = v5763[7];
  int v5771 = (int)((unsigned int)v5764 >> 19);
  v5763[7] = v5771;
  struct StateT * v5766 = slot_81(v5760);
  return v5766;
}

struct StateT * slot_72(struct StateT * v4812) {
  int v4813 = v4812->timer;
  int v4983 = v4813 + 1;
  v4812->timer = v4983;
  int * v4815 = v4812->regs;
  int v4816 = v4815[10];
  int v4817 = v4815[17];
  int * v4818 = v4812->cache_tags;
  int v4988 = (((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2;
  int v4819 = v4818[v4988];
  int v4989 = ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4820 = v4818[v4989];
  int v4990 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2);
  int v4821 = v4818[v4990];
  int v4991 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4822 = v4818[v4991];
  int v4823 = v4812->timer;
  int v4992 = v4823 + ((100 ^ (((~(((v4821 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4821 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4819 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4819 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4820 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4820 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4821 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4821 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4812->timer = v4992;
  bool v4993 = !(((~(((v4819 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4819 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4820 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4820 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4917;
  if (v4993) {
    int * v4825 = v4812->cache_age;
    int v4995 = ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v4820 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4820 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4826 = v4825[v4995];
    int v4827 = v4825[v4988];
    int v4996 = v4827 + ((int)((unsigned int)(v4827 - v4826) >> 31));
    v4825[v4988] = v4996;
    int * v4829 = v4812->cache_age;
    int v4830 = v4829[v4989];
    int v4998 = v4830 + ((int)((unsigned int)(v4830 - v4826) >> 31));
    v4829[v4989] = v4998;
    int * v4832 = v4812->cache_age;
    v4832[v4995] = 0;
    v4917 = v4995;
  } else {
    int * v4835 = v4812->cache_age;
    int v5002 = (((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2;
    int v4836 = v4835[v5002];
    int * v4837 = v4812->cache_tags;
    int v4838 = v4837[v5002];
    int v4839 = v4835[v4989];
    int v4840 = v4837[v4989];
    bool v5004 = !(((~(((v4821 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4821 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v4894;
    if (v5004) {
      int * v4841 = v4812->cache_age;
      int v5006 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4822 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v4842 = v4841[v5006];
      int v4843 = v4841[v4990];
      int v5007 = v4843 + ((int)((unsigned int)(v4843 - v4842) >> 31));
      v4841[v4990] = v5007;
      int * v4845 = v4812->cache_age;
      int v4846 = v4845[v4991];
      int v5009 = v4846 + ((int)((unsigned int)(v4846 - v4842) >> 31));
      v4845[v4991] = v5009;
      int * v4848 = v4812->cache_age;
      v4848[v5006] = 0;
      v4894 = v5006;
    } else {
      int * v4851 = v4812->cache_age;
      int v5013 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2);
      int v4852 = v4851[v5013];
      int * v4853 = v4812->cache_tags;
      int v4854 = v4853[v5013];
      int v4855 = v4851[v4991];
      int v4856 = v4853[v4991];
      int * v4857 = v4812->cache_dirty;
      int v5016 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4852 + ((~(((v4854 ^ -1) | (-(v4854 ^ -1))) >> 31)) & 2)) - (v4855 + ((~(((v4856 ^ -1) | (-(v4856 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4858 = v4857[v5016];
      bool v5017 = !(v4858 == 0);
      if (v5017) {
        int * v4859 = v4812->cache_tags;
        int v4860 = v4859[v5016];
        int * v4861 = v4812->cache_vals;
        int v5020 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4852 + ((~(((v4854 ^ -1) | (-(v4854 ^ -1))) >> 31)) & 2)) - (v4855 + ((~(((v4856 ^ -1) | (-(v4856 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4862 = v4861[v5020];
        int v5021 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4852 + ((~(((v4854 ^ -1) | (-(v4854 ^ -1))) >> 31)) & 2)) - (v4855 + ((~(((v4856 ^ -1) | (-(v4856 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4863 = v4861[v5021];
        int * v4864 = v4812->mem;
        int v5023 = v4860 * 2;
        v4864[v5023] = v4862;
        int * v4866 = v4812->mem;
        int v5026 = (v4860 * 2) + 1;
        v4866[v5026] = v4863;
        ;
      } else {
        ;
      }
      int * v4871 = v4812->mem;
      int v5031 = ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) * 2;
      int v4872 = v4871[v5031];
      int v5032 = (((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) * 2) + 1;
      int v4873 = v4871[v5032];
      int * v4874 = v4812->cache_vals;
      int v5034 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4852 + ((~(((v4854 ^ -1) | (-(v4854 ^ -1))) >> 31)) & 2)) - (v4855 + ((~(((v4856 ^ -1) | (-(v4856 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4874[v5034] = v4872;
      int * v4876 = v4812->cache_vals;
      int v5037 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4852 + ((~(((v4854 ^ -1) | (-(v4854 ^ -1))) >> 31)) & 2)) - (v4855 + ((~(((v4856 ^ -1) | (-(v4856 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4876[v5037] = v4873;
      int * v4878 = v4812->cache_tags;
      int v5040 = (int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1);
      v4878[v5016] = v5040;
      int * v4880 = v4812->cache_dirty;
      v4880[v5016] = 0;
      int * v4882 = v4812->cache_age;
      v4882[v5016] = 1;
      int * v4884 = v4812->cache_age;
      int v4885 = v4884[v5016];
      int v4886 = v4884[v4990];
      int v5046 = v4886 + ((int)((unsigned int)(v4886 - v4885) >> 31));
      v4884[v4990] = v5046;
      int * v4888 = v4812->cache_age;
      int v4889 = v4888[v4991];
      int v5048 = v4889 + ((int)((unsigned int)(v4889 - v4885) >> 31));
      v4888[v4991] = v5048;
      int * v4891 = v4812->cache_age;
      v4891[v5016] = 0;
      v4894 = v5016;
    }
    int * v4895 = v4812->cache_vals;
    int v5051 = v4894 * 2;
    int v4896 = v4895[v5051];
    int v5052 = (v4894 * 2) + 1;
    int v4897 = v4895[v5052];
    int v5053 = (((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4836 + ((~(((v4838 ^ -1) | (-(v4838 ^ -1))) >> 31)) & 2)) - (v4839 + ((~(((v4840 ^ -1) | (-(v4840 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4895[v5053] = v4896;
    int * v4899 = v4812->cache_vals;
    int v5056 = ((((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4836 + ((~(((v4838 ^ -1) | (-(v4838 ^ -1))) >> 31)) & 2)) - (v4839 + ((~(((v4840 ^ -1) | (-(v4840 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4899[v5056] = v4897;
    int * v4901 = v4812->cache_tags;
    int v5059 = ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4836 + ((~(((v4838 ^ -1) | (-(v4838 ^ -1))) >> 31)) & 2)) - (v4839 + ((~(((v4840 ^ -1) | (-(v4840 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5060 = (int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1);
    v4901[v5059] = v5060;
    int * v4903 = v4812->cache_dirty;
    v4903[v5059] = 0;
    int * v4905 = v4812->cache_age;
    v4905[v5059] = 1;
    int * v4907 = v4812->cache_age;
    int v4908 = v4907[v5059];
    int v4909 = v4907[v4988];
    int v5066 = v4909 + ((int)((unsigned int)(v4909 - v4908) >> 31));
    v4907[v4988] = v5066;
    int * v4911 = v4812->cache_age;
    int v4912 = v4911[v4989];
    int v5068 = v4912 + ((int)((unsigned int)(v4912 - v4908) >> 31));
    v4911[v4989] = v5068;
    int * v4914 = v4812->cache_age;
    v4914[v5059] = 0;
    v4917 = v5059;
  }
  int * v4918 = v4812->cache_vals;
  int v5071 = (v4917 * 2) + (((int)((unsigned int)(v4816 + 8) >> 2)) & 1);
  v4918[v5071] = v4817;
  int * v4920 = v4812->cache_tags;
  int v4921 = v4920[v4990];
  int v4922 = v4920[v4991];
  bool v5074 = !(((~(((v4921 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4921 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4922 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4922 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4976;
  if (v5074) {
    int * v4923 = v4812->cache_age;
    int v5076 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4922 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))) | (-(v4922 ^ ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4924 = v4923[v5076];
    int v4925 = v4923[v4990];
    int v5077 = v4925 + ((int)((unsigned int)(v4925 - v4924) >> 31));
    v4923[v4990] = v5077;
    int * v4927 = v4812->cache_age;
    int v4928 = v4927[v4991];
    int v5079 = v4928 + ((int)((unsigned int)(v4928 - v4924) >> 31));
    v4927[v4991] = v5079;
    int * v4930 = v4812->cache_age;
    v4930[v5076] = 0;
    v4976 = v5076;
  } else {
    int * v4933 = v4812->cache_age;
    int v5083 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2);
    int v4934 = v4933[v5083];
    int * v4935 = v4812->cache_tags;
    int v4936 = v4935[v5083];
    int v4937 = v4933[v4991];
    int v4938 = v4935[v4991];
    int * v4939 = v4812->cache_dirty;
    int v5086 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4934 + ((~(((v4936 ^ -1) | (-(v4936 ^ -1))) >> 31)) & 2)) - (v4937 + ((~(((v4938 ^ -1) | (-(v4938 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4940 = v4939[v5086];
    bool v5087 = !(v4940 == 0);
    if (v5087) {
      int * v4941 = v4812->cache_tags;
      int v4942 = v4941[v5086];
      int * v4943 = v4812->cache_vals;
      int v5090 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4934 + ((~(((v4936 ^ -1) | (-(v4936 ^ -1))) >> 31)) & 2)) - (v4937 + ((~(((v4938 ^ -1) | (-(v4938 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4944 = v4943[v5090];
      int v5091 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4934 + ((~(((v4936 ^ -1) | (-(v4936 ^ -1))) >> 31)) & 2)) - (v4937 + ((~(((v4938 ^ -1) | (-(v4938 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4945 = v4943[v5091];
      int * v4946 = v4812->mem;
      int v5093 = v4942 * 2;
      v4946[v5093] = v4944;
      int * v4948 = v4812->mem;
      int v5096 = (v4942 * 2) + 1;
      v4948[v5096] = v4945;
      ;
    } else {
      ;
    }
    int * v4953 = v4812->mem;
    int v5101 = ((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) * 2;
    int v4954 = v4953[v5101];
    int v5102 = (((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) * 2) + 1;
    int v4955 = v4953[v5102];
    int * v4956 = v4812->cache_vals;
    int v5104 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4934 + ((~(((v4936 ^ -1) | (-(v4936 ^ -1))) >> 31)) & 2)) - (v4937 + ((~(((v4938 ^ -1) | (-(v4938 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4956[v5104] = v4954;
    int * v4958 = v4812->cache_vals;
    int v5107 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4934 + ((~(((v4936 ^ -1) | (-(v4936 ^ -1))) >> 31)) & 2)) - (v4937 + ((~(((v4938 ^ -1) | (-(v4938 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4958[v5107] = v4955;
    int * v4960 = v4812->cache_tags;
    int v5110 = (int)((unsigned int)((int)((unsigned int)(v4816 + 8) >> 2)) >> 1);
    v4960[v5086] = v5110;
    int * v4962 = v4812->cache_dirty;
    v4962[v5086] = 0;
    int * v4964 = v4812->cache_age;
    v4964[v5086] = 1;
    int * v4966 = v4812->cache_age;
    int v4967 = v4966[v5086];
    int v4968 = v4966[v4990];
    int v5116 = v4968 + ((int)((unsigned int)(v4968 - v4967) >> 31));
    v4966[v4990] = v5116;
    int * v4970 = v4812->cache_age;
    int v4971 = v4970[v4991];
    int v5118 = v4971 + ((int)((unsigned int)(v4971 - v4967) >> 31));
    v4970[v4991] = v5118;
    int * v4973 = v4812->cache_age;
    v4973[v5086] = 0;
    v4976 = v5086;
  }
  int * v4977 = v4812->cache_vals;
  int v5121 = (v4976 * 2) + (((int)((unsigned int)(v4816 + 8) >> 2)) & 1);
  v4977[v5121] = v4817;
  int * v4979 = v4812->cache_dirty;
  v4979[v4976] = 1;
  struct StateT * v4981 = slot_74(v4812);
  return v4981;
}

struct StateT * slot_119(struct StateT * v7269) {
  int v7270 = v7269->timer;
  int v7606 = v7270 + 1;
  v7269->timer = v7606;
  int * v7272 = v7269->regs;
  int v7273 = v7272[10];
  int v7274 = v7272[29];
  int * v7275 = v7269->saved_regs;
  int v7276 = v7272[17];
  v7275[17] = v7276;
  int v7278 = v7269->timer;
  int v7613 = v7278 + 1;
  v7269->timer = v7613;
  int * v7280 = v7269->regs;
  int v7281 = v7280[28];
  int v7616 = (int)((unsigned int)v7281 >> 19);
  v7280[17] = v7616;
  int * v7283 = v7269->saved_regs;
  int * v7284 = v7269->regs;
  int v7285 = v7284[28];
  v7283[28] = v7285;
  int v7287 = v7269->timer;
  int v7620 = v7287 + 1;
  v7269->timer = v7620;
  int * v7289 = v7269->regs;
  int v7290 = v7289[28];
  int v7622 = v7290 << 13;
  v7289[28] = v7622;
  int * v7292 = v7269->saved_regs;
  int * v7293 = v7269->regs;
  int v7294 = v7293[5];
  v7292[5] = v7294;
  int v7296 = v7269->timer;
  int v7627 = v7296 + 1;
  v7269->timer = v7627;
  int * v7298 = v7269->regs;
  int v7299 = v7298[6];
  int v7300 = v7298[5];
  int v7630 = v7299 + v7300;
  v7298[5] = v7630;
  int * v7302 = v7269->saved_regs;
  int * v7303 = v7269->regs;
  int v7304 = v7303[6];
  v7302[6] = v7304;
  int v7306 = v7269->timer;
  int v7634 = v7306 + 1;
  v7269->timer = v7634;
  int * v7308 = v7269->regs;
  int v7309 = v7308[11];
  bool v7637 = (((int)((unsigned int)(v7273 + 20) >> 2)) & 3) == (((int)((unsigned int)(v7309 + 24) >> 2)) & 3);
  int v7416;
  if (v7637) {
    int v7310 = v7269->timer;
    int v7638 = v7310 + 1;
    v7269->timer = v7638;
    v7416 = v7274;
  } else {
    int * v7313 = v7269->cache_tags;
    int v7641 = (((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2;
    int v7314 = v7313[v7641];
    int v7642 = ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
    int v7315 = v7313[v7642];
    int v7643 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2);
    int v7316 = v7313[v7643];
    int v7644 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v7317 = v7313[v7644];
    int v7318 = v7269->timer;
    int v7645 = v7318 + ((100 ^ (((~(((v7316 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7316 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7314 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7314 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7315 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7315 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7316 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7316 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
    v7269->timer = v7645;
    int * v7320 = v7269->cache_vals;
    bool v7646 = !(((~(((v7314 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7314 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7315 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7315 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v7413;
    if (v7646) {
      int * v7321 = v7269->cache_age;
      int v7648 = ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v7315 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7315 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v7322 = v7321[v7648];
      int v7323 = v7321[v7641];
      int v7649 = v7323 + ((int)((unsigned int)(v7323 - v7322) >> 31));
      v7321[v7641] = v7649;
      int * v7325 = v7269->cache_age;
      int v7326 = v7325[v7642];
      int v7651 = v7326 + ((int)((unsigned int)(v7326 - v7322) >> 31));
      v7325[v7642] = v7651;
      int * v7328 = v7269->cache_age;
      v7328[v7648] = 0;
      v7413 = v7648;
    } else {
      int * v7331 = v7269->cache_age;
      int v7655 = (((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2;
      int v7332 = v7331[v7655];
      int * v7333 = v7269->cache_tags;
      int v7334 = v7333[v7655];
      int v7335 = v7331[v7642];
      int v7336 = v7333[v7642];
      bool v7657 = !(((~(((v7316 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7316 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31))) == 0);
      int v7390;
      if (v7657) {
        int * v7337 = v7269->cache_age;
        int v7659 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))) | (-(v7317 ^ ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1))))) >> 31)) & 1);
        int v7338 = v7337[v7659];
        int v7339 = v7337[v7643];
        int v7660 = v7339 + ((int)((unsigned int)(v7339 - v7338) >> 31));
        v7337[v7643] = v7660;
        int * v7341 = v7269->cache_age;
        int v7342 = v7341[v7644];
        int v7662 = v7342 + ((int)((unsigned int)(v7342 - v7338) >> 31));
        v7341[v7644] = v7662;
        int * v7344 = v7269->cache_age;
        v7344[v7659] = 0;
        v7390 = v7659;
      } else {
        int * v7347 = v7269->cache_age;
        int v7666 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2);
        int v7348 = v7347[v7666];
        int * v7349 = v7269->cache_tags;
        int v7350 = v7349[v7666];
        int v7351 = v7347[v7644];
        int v7352 = v7349[v7644];
        int * v7353 = v7269->cache_dirty;
        int v7669 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7348 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2)) - (v7351 + ((~(((v7352 ^ -1) | (-(v7352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v7354 = v7353[v7669];
        bool v7670 = !(v7354 == 0);
        if (v7670) {
          int * v7355 = v7269->cache_tags;
          int v7356 = v7355[v7669];
          int * v7357 = v7269->cache_vals;
          int v7673 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7348 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2)) - (v7351 + ((~(((v7352 ^ -1) | (-(v7352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v7358 = v7357[v7673];
          int v7674 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7348 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2)) - (v7351 + ((~(((v7352 ^ -1) | (-(v7352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v7359 = v7357[v7674];
          int * v7360 = v7269->mem;
          int v7676 = v7356 * 2;
          v7360[v7676] = v7358;
          int * v7362 = v7269->mem;
          int v7679 = (v7356 * 2) + 1;
          v7362[v7679] = v7359;
          ;
        } else {
          ;
        }
        int * v7367 = v7269->mem;
        int v7684 = ((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) * 2;
        int v7368 = v7367[v7684];
        int v7685 = (((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) * 2) + 1;
        int v7369 = v7367[v7685];
        int * v7370 = v7269->cache_vals;
        int v7687 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7348 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2)) - (v7351 + ((~(((v7352 ^ -1) | (-(v7352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v7370[v7687] = v7368;
        int * v7372 = v7269->cache_vals;
        int v7690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7348 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2)) - (v7351 + ((~(((v7352 ^ -1) | (-(v7352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v7372[v7690] = v7369;
        int * v7374 = v7269->cache_tags;
        int v7693 = (int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1);
        v7374[v7669] = v7693;
        int * v7376 = v7269->cache_dirty;
        v7376[v7669] = 0;
        int * v7378 = v7269->cache_age;
        v7378[v7669] = 1;
        int * v7380 = v7269->cache_age;
        int v7381 = v7380[v7669];
        int v7382 = v7380[v7643];
        int v7699 = v7382 + ((int)((unsigned int)(v7382 - v7381) >> 31));
        v7380[v7643] = v7699;
        int * v7384 = v7269->cache_age;
        int v7385 = v7384[v7644];
        int v7701 = v7385 + ((int)((unsigned int)(v7385 - v7381) >> 31));
        v7384[v7644] = v7701;
        int * v7387 = v7269->cache_age;
        v7387[v7669] = 0;
        v7390 = v7669;
      }
      int * v7391 = v7269->cache_vals;
      int v7704 = v7390 * 2;
      int v7392 = v7391[v7704];
      int v7705 = (v7390 * 2) + 1;
      int v7393 = v7391[v7705];
      int v7706 = (((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7332 + ((~(((v7334 ^ -1) | (-(v7334 ^ -1))) >> 31)) & 2)) - (v7335 + ((~(((v7336 ^ -1) | (-(v7336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7391[v7706] = v7392;
      int * v7395 = v7269->cache_vals;
      int v7709 = ((((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7332 + ((~(((v7334 ^ -1) | (-(v7334 ^ -1))) >> 31)) & 2)) - (v7335 + ((~(((v7336 ^ -1) | (-(v7336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7395[v7709] = v7393;
      int * v7397 = v7269->cache_tags;
      int v7712 = ((((int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7332 + ((~(((v7334 ^ -1) | (-(v7334 ^ -1))) >> 31)) & 2)) - (v7335 + ((~(((v7336 ^ -1) | (-(v7336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7713 = (int)((unsigned int)((int)((unsigned int)(v7309 + 24) >> 2)) >> 1);
      v7397[v7712] = v7713;
      int * v7399 = v7269->cache_dirty;
      v7399[v7712] = 0;
      int * v7401 = v7269->cache_age;
      v7401[v7712] = 1;
      int * v7403 = v7269->cache_age;
      int v7404 = v7403[v7712];
      int v7405 = v7403[v7641];
      int v7719 = v7405 + ((int)((unsigned int)(v7405 - v7404) >> 31));
      v7403[v7641] = v7719;
      int * v7407 = v7269->cache_age;
      int v7408 = v7407[v7642];
      int v7721 = v7408 + ((int)((unsigned int)(v7408 - v7404) >> 31));
      v7407[v7642] = v7721;
      int * v7410 = v7269->cache_age;
      v7410[v7712] = 0;
      v7413 = v7712;
    }
    int v7724 = (v7413 * 2) + (((int)((unsigned int)(v7309 + 24) >> 2)) & 1);
    int v7414 = v7320[v7724];
    v7416 = v7414;
  }
  int * v7417 = v7269->regs;
  v7417[6] = v7416;
  int * v7419 = v7269->cache_tags;
  int v7729 = (((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2;
  int v7420 = v7419[v7729];
  int v7730 = ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7421 = v7419[v7730];
  int v7731 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2);
  int v7422 = v7419[v7731];
  int v7732 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7423 = v7419[v7732];
  int v7424 = v7269->timer;
  int v7733 = v7424 + ((100 ^ (((~(((v7422 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7422 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7420 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7420 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7421 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7421 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7422 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7422 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7269->timer = v7733;
  bool v7734 = !(((~(((v7420 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7420 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7421 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7421 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v7518;
  if (v7734) {
    int * v7426 = v7269->cache_age;
    int v7736 = ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v7421 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7421 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v7427 = v7426[v7736];
    int v7428 = v7426[v7729];
    int v7737 = v7428 + ((int)((unsigned int)(v7428 - v7427) >> 31));
    v7426[v7729] = v7737;
    int * v7430 = v7269->cache_age;
    int v7431 = v7430[v7730];
    int v7739 = v7431 + ((int)((unsigned int)(v7431 - v7427) >> 31));
    v7430[v7730] = v7739;
    int * v7433 = v7269->cache_age;
    v7433[v7736] = 0;
    v7518 = v7736;
  } else {
    int * v7436 = v7269->cache_age;
    int v7743 = (((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2;
    int v7437 = v7436[v7743];
    int * v7438 = v7269->cache_tags;
    int v7439 = v7438[v7743];
    int v7440 = v7436[v7730];
    int v7441 = v7438[v7730];
    bool v7745 = !(((~(((v7422 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7422 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v7495;
    if (v7745) {
      int * v7442 = v7269->cache_age;
      int v7747 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7423 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v7443 = v7442[v7747];
      int v7444 = v7442[v7731];
      int v7748 = v7444 + ((int)((unsigned int)(v7444 - v7443) >> 31));
      v7442[v7731] = v7748;
      int * v7446 = v7269->cache_age;
      int v7447 = v7446[v7732];
      int v7750 = v7447 + ((int)((unsigned int)(v7447 - v7443) >> 31));
      v7446[v7732] = v7750;
      int * v7449 = v7269->cache_age;
      v7449[v7747] = 0;
      v7495 = v7747;
    } else {
      int * v7452 = v7269->cache_age;
      int v7754 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2);
      int v7453 = v7452[v7754];
      int * v7454 = v7269->cache_tags;
      int v7455 = v7454[v7754];
      int v7456 = v7452[v7732];
      int v7457 = v7454[v7732];
      int * v7458 = v7269->cache_dirty;
      int v7757 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7453 + ((~(((v7455 ^ -1) | (-(v7455 ^ -1))) >> 31)) & 2)) - (v7456 + ((~(((v7457 ^ -1) | (-(v7457 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7459 = v7458[v7757];
      bool v7758 = !(v7459 == 0);
      if (v7758) {
        int * v7460 = v7269->cache_tags;
        int v7461 = v7460[v7757];
        int * v7462 = v7269->cache_vals;
        int v7761 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7453 + ((~(((v7455 ^ -1) | (-(v7455 ^ -1))) >> 31)) & 2)) - (v7456 + ((~(((v7457 ^ -1) | (-(v7457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7463 = v7462[v7761];
        int v7762 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7453 + ((~(((v7455 ^ -1) | (-(v7455 ^ -1))) >> 31)) & 2)) - (v7456 + ((~(((v7457 ^ -1) | (-(v7457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7464 = v7462[v7762];
        int * v7465 = v7269->mem;
        int v7764 = v7461 * 2;
        v7465[v7764] = v7463;
        int * v7467 = v7269->mem;
        int v7767 = (v7461 * 2) + 1;
        v7467[v7767] = v7464;
        ;
      } else {
        ;
      }
      int * v7472 = v7269->mem;
      int v7772 = ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) * 2;
      int v7473 = v7472[v7772];
      int v7773 = (((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) * 2) + 1;
      int v7474 = v7472[v7773];
      int * v7475 = v7269->cache_vals;
      int v7775 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7453 + ((~(((v7455 ^ -1) | (-(v7455 ^ -1))) >> 31)) & 2)) - (v7456 + ((~(((v7457 ^ -1) | (-(v7457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7475[v7775] = v7473;
      int * v7477 = v7269->cache_vals;
      int v7778 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7453 + ((~(((v7455 ^ -1) | (-(v7455 ^ -1))) >> 31)) & 2)) - (v7456 + ((~(((v7457 ^ -1) | (-(v7457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7477[v7778] = v7474;
      int * v7479 = v7269->cache_tags;
      int v7781 = (int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1);
      v7479[v7757] = v7781;
      int * v7481 = v7269->cache_dirty;
      v7481[v7757] = 0;
      int * v7483 = v7269->cache_age;
      v7483[v7757] = 1;
      int * v7485 = v7269->cache_age;
      int v7486 = v7485[v7757];
      int v7487 = v7485[v7731];
      int v7787 = v7487 + ((int)((unsigned int)(v7487 - v7486) >> 31));
      v7485[v7731] = v7787;
      int * v7489 = v7269->cache_age;
      int v7490 = v7489[v7732];
      int v7789 = v7490 + ((int)((unsigned int)(v7490 - v7486) >> 31));
      v7489[v7732] = v7789;
      int * v7492 = v7269->cache_age;
      v7492[v7757] = 0;
      v7495 = v7757;
    }
    int * v7496 = v7269->cache_vals;
    int v7792 = v7495 * 2;
    int v7497 = v7496[v7792];
    int v7793 = (v7495 * 2) + 1;
    int v7498 = v7496[v7793];
    int v7794 = (((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7437 + ((~(((v7439 ^ -1) | (-(v7439 ^ -1))) >> 31)) & 2)) - (v7440 + ((~(((v7441 ^ -1) | (-(v7441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7496[v7794] = v7497;
    int * v7500 = v7269->cache_vals;
    int v7797 = ((((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7437 + ((~(((v7439 ^ -1) | (-(v7439 ^ -1))) >> 31)) & 2)) - (v7440 + ((~(((v7441 ^ -1) | (-(v7441 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7500[v7797] = v7498;
    int * v7502 = v7269->cache_tags;
    int v7800 = ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7437 + ((~(((v7439 ^ -1) | (-(v7439 ^ -1))) >> 31)) & 2)) - (v7440 + ((~(((v7441 ^ -1) | (-(v7441 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7801 = (int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1);
    v7502[v7800] = v7801;
    int * v7504 = v7269->cache_dirty;
    v7504[v7800] = 0;
    int * v7506 = v7269->cache_age;
    v7506[v7800] = 1;
    int * v7508 = v7269->cache_age;
    int v7509 = v7508[v7800];
    int v7510 = v7508[v7729];
    int v7807 = v7510 + ((int)((unsigned int)(v7510 - v7509) >> 31));
    v7508[v7729] = v7807;
    int * v7512 = v7269->cache_age;
    int v7513 = v7512[v7730];
    int v7809 = v7513 + ((int)((unsigned int)(v7513 - v7509) >> 31));
    v7512[v7730] = v7809;
    int * v7515 = v7269->cache_age;
    v7515[v7800] = 0;
    v7518 = v7800;
  }
  int * v7519 = v7269->cache_vals;
  int v7812 = (v7518 * 2) + (((int)((unsigned int)(v7273 + 20) >> 2)) & 1);
  v7519[v7812] = v7274;
  int * v7521 = v7269->cache_tags;
  int v7522 = v7521[v7731];
  int v7523 = v7521[v7732];
  bool v7815 = !(((~(((v7522 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7522 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7523 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7523 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v7577;
  if (v7815) {
    int * v7524 = v7269->cache_age;
    int v7817 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7523 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))) | (-(v7523 ^ ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v7525 = v7524[v7817];
    int v7526 = v7524[v7731];
    int v7818 = v7526 + ((int)((unsigned int)(v7526 - v7525) >> 31));
    v7524[v7731] = v7818;
    int * v7528 = v7269->cache_age;
    int v7529 = v7528[v7732];
    int v7820 = v7529 + ((int)((unsigned int)(v7529 - v7525) >> 31));
    v7528[v7732] = v7820;
    int * v7531 = v7269->cache_age;
    v7531[v7817] = 0;
    v7577 = v7817;
  } else {
    int * v7534 = v7269->cache_age;
    int v7824 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2);
    int v7535 = v7534[v7824];
    int * v7536 = v7269->cache_tags;
    int v7537 = v7536[v7824];
    int v7538 = v7534[v7732];
    int v7539 = v7536[v7732];
    int * v7540 = v7269->cache_dirty;
    int v7827 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7535 + ((~(((v7537 ^ -1) | (-(v7537 ^ -1))) >> 31)) & 2)) - (v7538 + ((~(((v7539 ^ -1) | (-(v7539 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7541 = v7540[v7827];
    bool v7828 = !(v7541 == 0);
    if (v7828) {
      int * v7542 = v7269->cache_tags;
      int v7543 = v7542[v7827];
      int * v7544 = v7269->cache_vals;
      int v7831 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7535 + ((~(((v7537 ^ -1) | (-(v7537 ^ -1))) >> 31)) & 2)) - (v7538 + ((~(((v7539 ^ -1) | (-(v7539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7545 = v7544[v7831];
      int v7832 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7535 + ((~(((v7537 ^ -1) | (-(v7537 ^ -1))) >> 31)) & 2)) - (v7538 + ((~(((v7539 ^ -1) | (-(v7539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7546 = v7544[v7832];
      int * v7547 = v7269->mem;
      int v7834 = v7543 * 2;
      v7547[v7834] = v7545;
      int * v7549 = v7269->mem;
      int v7837 = (v7543 * 2) + 1;
      v7549[v7837] = v7546;
      ;
    } else {
      ;
    }
    int * v7554 = v7269->mem;
    int v7842 = ((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) * 2;
    int v7555 = v7554[v7842];
    int v7843 = (((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) * 2) + 1;
    int v7556 = v7554[v7843];
    int * v7557 = v7269->cache_vals;
    int v7845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7535 + ((~(((v7537 ^ -1) | (-(v7537 ^ -1))) >> 31)) & 2)) - (v7538 + ((~(((v7539 ^ -1) | (-(v7539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7557[v7845] = v7555;
    int * v7559 = v7269->cache_vals;
    int v7848 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7535 + ((~(((v7537 ^ -1) | (-(v7537 ^ -1))) >> 31)) & 2)) - (v7538 + ((~(((v7539 ^ -1) | (-(v7539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7559[v7848] = v7556;
    int * v7561 = v7269->cache_tags;
    int v7851 = (int)((unsigned int)((int)((unsigned int)(v7273 + 20) >> 2)) >> 1);
    v7561[v7827] = v7851;
    int * v7563 = v7269->cache_dirty;
    v7563[v7827] = 0;
    int * v7565 = v7269->cache_age;
    v7565[v7827] = 1;
    int * v7567 = v7269->cache_age;
    int v7568 = v7567[v7827];
    int v7569 = v7567[v7731];
    int v7857 = v7569 + ((int)((unsigned int)(v7569 - v7568) >> 31));
    v7567[v7731] = v7857;
    int * v7571 = v7269->cache_age;
    int v7572 = v7571[v7732];
    int v7859 = v7572 + ((int)((unsigned int)(v7572 - v7568) >> 31));
    v7571[v7732] = v7859;
    int * v7574 = v7269->cache_age;
    v7574[v7827] = 0;
    v7577 = v7827;
  }
  int * v7578 = v7269->cache_vals;
  int v7862 = (v7577 * 2) + (((int)((unsigned int)(v7273 + 20) >> 2)) & 1);
  v7578[v7862] = v7274;
  int * v7580 = v7269->cache_dirty;
  v7580[v7577] = 1;
  bool v7866 = ((((int)((unsigned int)(v7309 + 24) >> 2)) & 3) == (((int)((unsigned int)(v7273 + 20) >> 2)) & 3)) & (!(((int)((unsigned int)(v7309 + 24) >> 2)) == ((int)((unsigned int)(v7273 + 20) >> 2))));
  struct StateT * v7604;
  if (v7866) {
    int v7582 = v7269->timer;
    int v7867 = v7582 + 15;
    v7269->timer = v7867;
    int * v7584 = v7269->saved_regs;
    int v7585 = v7584[17];
    int * v7586 = v7269->regs;
    v7586[17] = v7585;
    int * v7588 = v7269->saved_regs;
    int v7589 = v7588[28];
    int * v7590 = v7269->regs;
    v7590[28] = v7589;
    int * v7592 = v7269->saved_regs;
    int v7593 = v7592[5];
    int * v7594 = v7269->regs;
    v7594[5] = v7593;
    int * v7596 = v7269->saved_regs;
    int v7597 = v7596[6];
    int * v7598 = v7269->regs;
    v7598[6] = v7597;
    struct StateT * v7600 = slot_121(v7269);
    v7604 = v7600;
  } else {
    struct StateT * v7602 = slot_125(v7269);
    v7604 = v7602;
  }
  return v7604;
}

struct StateT * slot_71(struct StateT * v4796) {
  int v4797 = v4796->timer;
  int v4805 = v4797 + 1;
  v4796->timer = v4805;
  int * v4799 = v4796->regs;
  int v4800 = v4799[5];
  int v4801 = v4799[28];
  int v4809 = v4800 + v4801;
  v4799[28] = v4809;
  struct StateT * v4803 = slot_73(v4796);
  return v4803;
}

struct StateT * slot_101(struct StateT * v6590) {
  int v6591 = v6590->timer;
  int v6599 = v6591 + 1;
  v6590->timer = v6599;
  int * v6593 = v6590->regs;
  int v6594 = v6593[8];
  int v6595 = v6593[6];
  int v6603 = v6594 + v6595;
  v6593[6] = v6603;
  struct StateT * v6597 = slot_102(v6590);
  return v6597;
}

struct StateT * slot_108(struct StateT * v6721) {
  int v6722 = v6721->timer;
  int v6730 = v6722 + 1;
  v6721->timer = v6730;
  int * v6724 = v6721->regs;
  int v6725 = v6724[6];
  int v6726 = v6724[31];
  int v6734 = v6725 + v6726;
  v6724[6] = v6734;
  struct StateT * v6728 = slot_109(v6721);
  return v6728;
}

struct StateT * slot_116(struct StateT * v6921) {
  int v6922 = v6921->timer;
  int v6930 = v6922 + 1;
  v6921->timer = v6930;
  int * v6924 = v6921->regs;
  int v6925 = v6924[5];
  int v6926 = v6924[28];
  int v6934 = v6925 + v6926;
  v6924[28] = v6934;
  struct StateT * v6928 = slot_118(v6921);
  return v6928;
}

struct StateT * slot_93(struct StateT * v6432) {
  int v6433 = v6432->timer;
  int v6441 = v6433 + 1;
  v6432->timer = v6441;
  int * v6435 = v6432->regs;
  int v6436 = v6435[28];
  int v6437 = v6435[17];
  int v6446 = v6436 + v6437;
  v6435[29] = v6446;
  struct StateT * v6439 = slot_94(v6432);
  return v6439;
}

struct StateT * slot_88(struct StateT * v6348) {
  int v6349 = v6348->timer;
  int v6357 = v6349 + 1;
  v6348->timer = v6357;
  int * v6351 = v6348->regs;
  int v6352 = v6351[6];
  int v6353 = v6351[13];
  int v6362 = v6352 * v6353;
  v6351[31] = v6362;
  struct StateT * v6355 = slot_89(v6348);
  return v6355;
}

struct StateT * slot_96(struct StateT * v6491) {
  int v6492 = v6491->timer;
  int v6500 = v6492 + 1;
  v6491->timer = v6500;
  int * v6494 = v6491->regs;
  int v6495 = v6494[31];
  int v6496 = v6494[29];
  int v6504 = v6495 + v6496;
  v6494[29] = v6504;
  struct StateT * v6498 = slot_97(v6491);
  return v6498;
}

struct StateT * slot_215(struct StateT * v11282) {
  int v11283 = v11282->timer;
  int v11291 = v11283 + 1;
  v11282->timer = v11291;
  int * v11285 = v11282->regs;
  int v11286 = v11285[14];
  int v11287 = v11285[13];
  int v11295 = v11286 + v11287;
  v11285[13] = v11295;
  struct StateT * v11289 = slot_216(v11282);
  return v11289;
}

struct StateT * slot_234(struct StateT * v13882) {
  int v13883 = v13882->timer;
  int v13890 = v13883 + 1;
  v13882->timer = v13890;
  int * v13885 = v13882->regs;
  int v13886 = v13885[2];
  int v13893 = v13886 + 16;
  v13885[2] = v13893;
  struct StateT * v13888 = slot_236(v13882);
  return v13888;
}

struct StateT * slot_45(struct StateT * v4260) {
  int v4261 = v4260->timer;
  int v4269 = v4261 + 1;
  v4260->timer = v4269;
  int * v4263 = v4260->regs;
  int v4264 = v4263[28];
  int v4265 = v4263[13];
  int v4274 = v4264 * v4265;
  v4263[18] = v4274;
  struct StateT * v4267 = slot_46(v4260);
  return v4267;
}

struct StateT * slot_218(struct StateT * v11345) {
  int v11346 = v11345->timer;
  int v11354 = v11346 + 1;
  v11345->timer = v11354;
  int * v11348 = v11345->regs;
  int v11349 = v11348[15];
  int v11350 = v11348[12];
  int v11358 = v11349 + v11350;
  v11348[12] = v11358;
  struct StateT * v11352 = slot_219(v11345);
  return v11352;
}

struct StateT * slot_220(struct StateT * v11377) {
  int * v11378 = v11377->saved_regs;
  int v11379 = v11378[17];
  int * v11380 = v11377->regs;
  int v11381 = v11380[6];
  bool v11422 = v11379 == v11381;
  struct StateT * v11416;
  if (v11422) {
    int v11382 = v11377->timer;
    int v11423 = v11382 + 15;
    v11377->timer = v11423;
    int * v11384 = v11377->saved_regs;
    int v11385 = v11384[5];
    int * v11386 = v11377->regs;
    v11386[5] = v11385;
    int * v11388 = v11377->saved_regs;
    int v11389 = v11388[16];
    int * v11390 = v11377->regs;
    v11390[16] = v11389;
    int * v11392 = v11377->saved_regs;
    int v11393 = v11392[17];
    int * v11394 = v11377->regs;
    v11394[17] = v11393;
    int * v11396 = v11377->saved_regs;
    int v11397 = v11396[12];
    int * v11398 = v11377->regs;
    v11398[12] = v11397;
    int * v11400 = v11377->saved_regs;
    int v11401 = v11400[13];
    int * v11402 = v11377->regs;
    v11402[13] = v11401;
    int * v11404 = v11377->saved_regs;
    int v11405 = v11404[15];
    int * v11406 = v11377->regs;
    v11406[15] = v11405;
    int * v11408 = v11377->saved_regs;
    int v11409 = v11408[14];
    int * v11410 = v11377->regs;
    v11410[14] = v11409;
    struct StateT * v11412 = slot_221(v11377);
    v11416 = v11412;
  } else {
    struct StateT * v11414 = slot_222(v11377);
    v11416 = v11414;
  }
  return v11416;
}

struct StateT * slot_134(struct StateT * v8490) {
  int v8491 = v8490->timer;
  int v8499 = v8491 + 1;
  v8490->timer = v8499;
  int * v8493 = v8490->regs;
  int v8494 = v8493[6];
  int v8495 = v8493[13];
  int v8504 = (((((int)((unsigned int)v8494 >> 16)) * ((int)((unsigned int)v8495 >> 16))) + ((int)((unsigned int)((v8494 & 65535) * ((int)((unsigned int)v8495 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8494 >> 16)) * (v8495 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8494 & 65535) * (v8495 & 65535)) >> 16)) + (((v8494 & 65535) * ((int)((unsigned int)v8495 >> 16))) & 65535)) + ((((int)((unsigned int)v8494 >> 16)) * (v8495 & 65535)) & 65535)) >> 16));
  v8493[8] = v8504;
  struct StateT * v8497 = slot_135(v8490);
  return v8497;
}

struct StateT * slot_175(struct StateT * v10546) {
  int v10547 = v10546->timer;
  int v10555 = v10547 + 1;
  v10546->timer = v10555;
  int * v10549 = v10546->regs;
  int v10550 = v10549[6];
  int v10551 = v10549[12];
  int v10560 = (((((int)((unsigned int)v10550 >> 16)) * ((int)((unsigned int)v10551 >> 16))) + ((int)((unsigned int)((v10550 & 65535) * ((int)((unsigned int)v10551 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v10550 >> 16)) * (v10551 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v10550 & 65535) * (v10551 & 65535)) >> 16)) + (((v10550 & 65535) * ((int)((unsigned int)v10551 >> 16))) & 65535)) + ((((int)((unsigned int)v10550 >> 16)) * (v10551 & 65535)) & 65535)) >> 16));
  v10549[5] = v10560;
  struct StateT * v10553 = slot_176(v10546);
  return v10553;
}

struct StateT * slot_69(struct StateT * v4713) {
  int * v4714 = v4713->saved_regs;
  int * v4715 = v4713->regs;
  int v4716 = v4715[5];
  v4714[5] = v4716;
  int v4718 = v4713->timer;
  int v4734 = v4718 + 1;
  v4713->timer = v4734;
  int * v4720 = v4713->regs;
  int v4721 = v4720[28];
  int v4722 = v4720[5];
  bool v4737 = (v4721 ^ -2147483648) < (v4722 ^ -2147483648);
  int v4725;
  if (v4737) {
    v4725 = 1;
  } else {
    v4725 = 0;
  }
  int * v4726 = v4713->regs;
  v4726[5] = v4725;
  struct StateT * v4728 = slot_70(v4713);
  return v4728;
}

struct StateT * slot_202(struct StateT * v11040) {
  int * v11041 = v11040->saved_regs;
  int * v11042 = v11040->regs;
  int v11043 = v11042[16];
  v11041[16] = v11043;
  int v11045 = v11040->timer;
  int v11057 = v11045 + 1;
  v11040->timer = v11057;
  int * v11047 = v11040->regs;
  int v11048 = v11047[17];
  int v11049 = v11047[16];
  int v11060 = v11048 & v11049;
  v11047[16] = v11060;
  struct StateT * v11051 = slot_203(v11040);
  return v11051;
}

struct StateT * slot_230(struct StateT * v13678) {
  int v13679 = v13678->timer;
  int v13789 = v13679 + 1;
  v13678->timer = v13789;
  int * v13681 = v13678->regs;
  int v13682 = v13681[2];
  int * v13683 = v13678->cache_tags;
  int v13793 = (((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2;
  int v13684 = v13683[v13793];
  int v13794 = ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13685 = v13683[v13794];
  int v13795 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2);
  int v13686 = v13683[v13795];
  int v13796 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13687 = v13683[v13796];
  int v13688 = v13678->timer;
  int v13797 = v13688 + ((100 ^ (((~(((v13686 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13686 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13684 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13684 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13685 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13685 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13686 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13686 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13678->timer = v13797;
  int * v13690 = v13678->cache_vals;
  bool v13798 = !(((~(((v13684 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13684 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13685 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13685 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v13783;
  if (v13798) {
    int * v13691 = v13678->cache_age;
    int v13800 = ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v13685 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13685 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v13692 = v13691[v13800];
    int v13693 = v13691[v13793];
    int v13801 = v13693 + ((int)((unsigned int)(v13693 - v13692) >> 31));
    v13691[v13793] = v13801;
    int * v13695 = v13678->cache_age;
    int v13696 = v13695[v13794];
    int v13803 = v13696 + ((int)((unsigned int)(v13696 - v13692) >> 31));
    v13695[v13794] = v13803;
    int * v13698 = v13678->cache_age;
    v13698[v13800] = 0;
    v13783 = v13800;
  } else {
    int * v13701 = v13678->cache_age;
    int v13807 = (((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2;
    int v13702 = v13701[v13807];
    int * v13703 = v13678->cache_tags;
    int v13704 = v13703[v13807];
    int v13705 = v13701[v13794];
    int v13706 = v13703[v13794];
    bool v13809 = !(((~(((v13686 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13686 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v13760;
    if (v13809) {
      int * v13707 = v13678->cache_age;
      int v13811 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))) | (-(v13687 ^ ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v13708 = v13707[v13811];
      int v13709 = v13707[v13795];
      int v13812 = v13709 + ((int)((unsigned int)(v13709 - v13708) >> 31));
      v13707[v13795] = v13812;
      int * v13711 = v13678->cache_age;
      int v13712 = v13711[v13796];
      int v13814 = v13712 + ((int)((unsigned int)(v13712 - v13708) >> 31));
      v13711[v13796] = v13814;
      int * v13714 = v13678->cache_age;
      v13714[v13811] = 0;
      v13760 = v13811;
    } else {
      int * v13717 = v13678->cache_age;
      int v13818 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2);
      int v13718 = v13717[v13818];
      int * v13719 = v13678->cache_tags;
      int v13720 = v13719[v13818];
      int v13721 = v13717[v13796];
      int v13722 = v13719[v13796];
      int * v13723 = v13678->cache_dirty;
      int v13821 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13718 + ((~(((v13720 ^ -1) | (-(v13720 ^ -1))) >> 31)) & 2)) - (v13721 + ((~(((v13722 ^ -1) | (-(v13722 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13724 = v13723[v13821];
      bool v13822 = !(v13724 == 0);
      if (v13822) {
        int * v13725 = v13678->cache_tags;
        int v13726 = v13725[v13821];
        int * v13727 = v13678->cache_vals;
        int v13825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13718 + ((~(((v13720 ^ -1) | (-(v13720 ^ -1))) >> 31)) & 2)) - (v13721 + ((~(((v13722 ^ -1) | (-(v13722 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13728 = v13727[v13825];
        int v13826 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13718 + ((~(((v13720 ^ -1) | (-(v13720 ^ -1))) >> 31)) & 2)) - (v13721 + ((~(((v13722 ^ -1) | (-(v13722 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13729 = v13727[v13826];
        int * v13730 = v13678->mem;
        int v13828 = v13726 * 2;
        v13730[v13828] = v13728;
        int * v13732 = v13678->mem;
        int v13831 = (v13726 * 2) + 1;
        v13732[v13831] = v13729;
        ;
      } else {
        ;
      }
      int * v13737 = v13678->mem;
      int v13836 = ((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) * 2;
      int v13738 = v13737[v13836];
      int v13837 = (((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) * 2) + 1;
      int v13739 = v13737[v13837];
      int * v13740 = v13678->cache_vals;
      int v13839 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13718 + ((~(((v13720 ^ -1) | (-(v13720 ^ -1))) >> 31)) & 2)) - (v13721 + ((~(((v13722 ^ -1) | (-(v13722 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13740[v13839] = v13738;
      int * v13742 = v13678->cache_vals;
      int v13842 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13718 + ((~(((v13720 ^ -1) | (-(v13720 ^ -1))) >> 31)) & 2)) - (v13721 + ((~(((v13722 ^ -1) | (-(v13722 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13742[v13842] = v13739;
      int * v13744 = v13678->cache_tags;
      int v13845 = (int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1);
      v13744[v13821] = v13845;
      int * v13746 = v13678->cache_dirty;
      v13746[v13821] = 0;
      int * v13748 = v13678->cache_age;
      v13748[v13821] = 1;
      int * v13750 = v13678->cache_age;
      int v13751 = v13750[v13821];
      int v13752 = v13750[v13795];
      int v13851 = v13752 + ((int)((unsigned int)(v13752 - v13751) >> 31));
      v13750[v13795] = v13851;
      int * v13754 = v13678->cache_age;
      int v13755 = v13754[v13796];
      int v13853 = v13755 + ((int)((unsigned int)(v13755 - v13751) >> 31));
      v13754[v13796] = v13853;
      int * v13757 = v13678->cache_age;
      v13757[v13821] = 0;
      v13760 = v13821;
    }
    int * v13761 = v13678->cache_vals;
    int v13856 = v13760 * 2;
    int v13762 = v13761[v13856];
    int v13857 = (v13760 * 2) + 1;
    int v13763 = v13761[v13857];
    int v13858 = (((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v13702 + ((~(((v13704 ^ -1) | (-(v13704 ^ -1))) >> 31)) & 2)) - (v13705 + ((~(((v13706 ^ -1) | (-(v13706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13761[v13858] = v13762;
    int * v13765 = v13678->cache_vals;
    int v13861 = ((((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v13702 + ((~(((v13704 ^ -1) | (-(v13704 ^ -1))) >> 31)) & 2)) - (v13705 + ((~(((v13706 ^ -1) | (-(v13706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13765[v13861] = v13763;
    int * v13767 = v13678->cache_tags;
    int v13864 = ((((int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v13702 + ((~(((v13704 ^ -1) | (-(v13704 ^ -1))) >> 31)) & 2)) - (v13705 + ((~(((v13706 ^ -1) | (-(v13706 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13865 = (int)((unsigned int)((int)((unsigned int)(v13682 + 12) >> 2)) >> 1);
    v13767[v13864] = v13865;
    int * v13769 = v13678->cache_dirty;
    v13769[v13864] = 0;
    int * v13771 = v13678->cache_age;
    v13771[v13864] = 1;
    int * v13773 = v13678->cache_age;
    int v13774 = v13773[v13864];
    int v13775 = v13773[v13793];
    int v13871 = v13775 + ((int)((unsigned int)(v13775 - v13774) >> 31));
    v13773[v13793] = v13871;
    int * v13777 = v13678->cache_age;
    int v13778 = v13777[v13794];
    int v13873 = v13778 + ((int)((unsigned int)(v13778 - v13774) >> 31));
    v13777[v13794] = v13873;
    int * v13780 = v13678->cache_age;
    v13780[v13864] = 0;
    v13783 = v13864;
  }
  int v13876 = (v13783 * 2) + (((int)((unsigned int)(v13682 + 12) >> 2)) & 1);
  int v13784 = v13690[v13876];
  int * v13785 = v13678->regs;
  v13785[8] = v13784;
  struct StateT * v13787 = slot_231(v13678);
  return v13787;
}

struct StateT * slot_188(struct StateT * v10780) {
  int v10781 = v10780->timer;
  int v10789 = v10781 + 1;
  v10780->timer = v10789;
  int * v10783 = v10780->regs;
  int v10784 = v10783[29];
  int v10785 = v10783[7];
  int v10793 = v10784 + v10785;
  v10783[7] = v10793;
  struct StateT * v10787 = slot_189(v10780);
  return v10787;
}

struct StateT * slot_138(struct StateT * v8557) {
  int v8558 = v8557->timer;
  int v8566 = v8558 + 1;
  v8557->timer = v8566;
  int * v8560 = v8557->regs;
  int v8561 = v8560[28];
  int v8562 = v8560[17];
  int v8571 = v8561 + v8562;
  v8560[29] = v8571;
  struct StateT * v8564 = slot_139(v8557);
  return v8564;
}

struct StateT * slot_186(struct StateT * v10738) {
  int v10739 = v10738->timer;
  int v10747 = v10739 + 1;
  v10738->timer = v10747;
  int * v10741 = v10738->regs;
  int v10742 = v10741[30];
  int v10743 = v10741[5];
  int v10752 = v10742 + v10743;
  v10741[6] = v10752;
  struct StateT * v10745 = slot_187(v10738);
  return v10745;
}

struct StateT * slot_102(struct StateT * v6606) {
  int v6607 = v6606->timer;
  int v6615 = v6607 + 1;
  v6606->timer = v6615;
  int * v6609 = v6606->regs;
  int v6610 = v6609[7];
  int v6611 = v6609[6];
  int v6619 = v6610 + v6611;
  v6609[6] = v6619;
  struct StateT * v6613 = slot_103(v6606);
  return v6613;
}

struct StateT * slot_145(struct StateT * v8698) {
  int v8699 = v8698->timer;
  int v8707 = v8699 + 1;
  v8698->timer = v8707;
  int * v8701 = v8698->regs;
  int v8702 = v8701[29];
  int v8703 = v8701[5];
  int v8712 = v8702 + v8703;
  v8701[30] = v8712;
  struct StateT * v8705 = slot_146(v8698);
  return v8705;
}

struct StateT * slot_110(struct StateT * v6745) {
  int * v6746 = v6745->saved_regs;
  int * v6747 = v6745->regs;
  int v6748 = v6747[28];
  v6746[28] = v6748;
  int v6750 = v6745->timer;
  int v6766 = v6750 + 1;
  v6745->timer = v6766;
  int * v6752 = v6745->regs;
  int v6753 = v6752[7];
  int v6754 = v6752[29];
  bool v6770 = (v6753 ^ -2147483648) < (v6754 ^ -2147483648);
  int v6757;
  if (v6770) {
    v6757 = 1;
  } else {
    v6757 = 0;
  }
  int * v6758 = v6745->regs;
  v6758[28] = v6757;
  struct StateT * v6760 = slot_111(v6745);
  return v6760;
}

struct StateT * slot_196(struct StateT * v10936) {
  int v10937 = v10936->timer;
  int v10945 = v10937 + 1;
  v10936->timer = v10945;
  int * v10939 = v10936->regs;
  int v10940 = v10939[13];
  int v10941 = v10939[7];
  int v10949 = v10940 + v10941;
  v10939[13] = v10949;
  struct StateT * v10943 = slot_197(v10936);
  return v10943;
}

struct StateT * slot_208(struct StateT * v11169) {
  int v11170 = v11169->timer;
  int v11176 = v11170 + 1;
  v11169->timer = v11176;
  int * v11172 = v11169->regs;
  v11172[17] = 19;
  struct StateT * v11174 = slot_209(v11169);
  return v11174;
}

struct StateT * slot_172(struct StateT * v10280) {
  int v10281 = v10280->timer;
  int v10289 = v10281 + 1;
  v10280->timer = v10289;
  int * v10283 = v10280->regs;
  int v10284 = v10283[7];
  int v10285 = v10283[28];
  int v10293 = v10284 | v10285;
  v10283[7] = v10293;
  struct StateT * v10287 = slot_173(v10280);
  return v10287;
}

struct StateT * slot_131(struct StateT * v8439) {
  int v8440 = v8439->timer;
  int v8448 = v8440 + 1;
  v8439->timer = v8448;
  int * v8442 = v8439->regs;
  int v8443 = v8442[29];
  int v8444 = v8442[12];
  int v8453 = v8443 * v8444;
  v8442[28] = v8453;
  struct StateT * v8446 = slot_132(v8439);
  return v8446;
}

struct StateT * slot_8(struct StateT * v2212) {
  int v2213 = v2212->timer;
  int v2220 = v2213 + 1;
  v2212->timer = v2220;
  int * v2215 = v2212->regs;
  int v2216 = v2215[16];
  int v2223 = v2216 + -1;
  v2215[16] = v2223;
  struct StateT * v2218 = slot_9(v2212);
  return v2218;
}

struct StateT * slot_180(struct StateT * v10631) {
  int v10632 = v10631->timer;
  int v10640 = v10632 + 1;
  v10631->timer = v10640;
  int * v10634 = v10631->regs;
  int v10635 = v10634[11];
  int v10636 = v10634[13];
  int v10645 = v10635 * v10636;
  v10634[8] = v10645;
  struct StateT * v10638 = slot_181(v10631);
  return v10638;
}

struct StateT * slot_203(struct StateT * v11063) {
  int * v11064 = v11063->saved_regs;
  int * v11065 = v11063->regs;
  int v11066 = v11065[17];
  v11064[17] = v11066;
  int v11068 = v11063->timer;
  int v11079 = v11068 + 1;
  v11063->timer = v11079;
  int * v11070 = v11063->regs;
  int v11071 = v11070[17];
  int v11081 = (int)((unsigned int)v11071 >> 19);
  v11070[17] = v11081;
  struct StateT * v11073 = slot_204(v11063);
  return v11073;
}

struct StateT * slot_190(struct StateT * v10821) {
  int v10822 = v10821->timer;
  int v10830 = v10822 + 1;
  v10821->timer = v10830;
  int * v10824 = v10821->regs;
  int v10825 = v10824[6];
  int v10826 = v10824[17];
  int v10834 = v10825 + v10826;
  v10824[17] = v10834;
  struct StateT * v10828 = slot_191(v10821);
  return v10828;
}

struct StateT * slot_157(struct StateT * v8918) {
  int * v8919 = v8918->saved_regs;
  int * v8920 = v8918->regs;
  int v8921 = v8920[29];
  v8919[29] = v8921;
  int v8923 = v8918->timer;
  int v8935 = v8923 + 1;
  v8918->timer = v8935;
  int * v8925 = v8918->regs;
  int v8926 = v8925[7];
  int v8927 = v8925[16];
  int v8939 = v8926 & v8927;
  v8925[29] = v8939;
  struct StateT * v8929 = slot_158(v8918);
  return v8929;
}

struct StateT * slot_242(struct StateT * v14585) {
  int v14586 = v14585->timer;
  int v14594 = v14586 + 1;
  v14585->timer = v14594;
  int * v14588 = v14585->regs;
  int v14589 = v14588[12];
  int v14590 = v14588[5];
  int v14598 = v14589 | v14590;
  v14588[12] = v14598;
  struct StateT * v14592 = slot_243(v14585);
  return v14592;
}

struct StateT * slot_200(struct StateT * v10992) {
  int * v10993 = v10992->saved_regs;
  int * v10994 = v10992->regs;
  int v10995 = v10994[5];
  v10993[5] = v10995;
  int v10997 = v10992->timer;
  int v11013 = v10997 + 1;
  v10992->timer = v11013;
  int * v10999 = v10992->regs;
  int v11000 = v10999[17];
  int v11001 = v10999[6];
  bool v11017 = (v11000 ^ -2147483648) < (v11001 ^ -2147483648);
  int v11004;
  if (v11017) {
    v11004 = 1;
  } else {
    v11004 = 0;
  }
  int * v11005 = v10992->regs;
  v11005[5] = v11004;
  struct StateT * v11007 = slot_201(v10992);
  return v11007;
}

struct StateT * slot_243(struct StateT * v14601) {
  int v14602 = v14601->timer;
  int v14610 = v14602 + 1;
  v14601->timer = v14610;
  int * v14604 = v14601->regs;
  int v14605 = v14604[13];
  int v14606 = v14604[17];
  int v14615 = (((((int)((unsigned int)v14605 >> 16)) * ((int)((unsigned int)v14606 >> 16))) + ((int)((unsigned int)((v14605 & 65535) * ((int)((unsigned int)v14606 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v14605 >> 16)) * (v14606 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v14605 & 65535) * (v14606 & 65535)) >> 16)) + (((v14605 & 65535) * ((int)((unsigned int)v14606 >> 16))) & 65535)) + ((((int)((unsigned int)v14605 >> 16)) * (v14606 & 65535)) & 65535)) >> 16));
  v14604[5] = v14615;
  struct StateT * v14608 = slot_244(v14601);
  return v14608;
}

struct StateT * slot_173(struct StateT * v10312) {
  int v10313 = v10312->timer;
  int v10320 = v10313 + 1;
  v10312->timer = v10320;
  int * v10315 = v10312->regs;
  int v10316 = v10315[5];
  int v10323 = v10316 << 13;
  v10315[5] = v10323;
  struct StateT * v10318 = slot_174(v10312);
  return v10318;
}

struct StateT * slot_149(struct StateT * v8764) {
  int v8765 = v8764->timer;
  int v8777 = v8765 + 1;
  v8764->timer = v8777;
  int * v8767 = v8764->regs;
  int v8768 = v8767[6];
  int v8769 = v8767[7];
  bool v8781 = (v8768 ^ -2147483648) < (v8769 ^ -2147483648);
  int v8772;
  if (v8781) {
    v8772 = 1;
  } else {
    v8772 = 0;
  }
  int * v8773 = v8764->regs;
  v8773[6] = v8772;
  struct StateT * v8775 = slot_150(v8764);
  return v8775;
}

struct StateT * slot_5(struct StateT * v1740) {
  int v1741 = v1740->timer;
  int v1851 = v1741 + 1;
  v1740->timer = v1851;
  int * v1743 = v1740->regs;
  int v1744 = v1743[11];
  int * v1745 = v1740->cache_tags;
  int v1855 = (((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2;
  int v1746 = v1745[v1855];
  int v1856 = ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1747 = v1745[v1856];
  int v1857 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2);
  int v1748 = v1745[v1857];
  int v1858 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1749 = v1745[v1858];
  int v1750 = v1740->timer;
  int v1859 = v1750 + ((100 ^ (((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1740->timer = v1859;
  int * v1752 = v1740->cache_vals;
  bool v1860 = !(((~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) == 0);
  int v1845;
  if (v1860) {
    int * v1753 = v1740->cache_age;
    int v1862 = ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) & 1);
    int v1754 = v1753[v1862];
    int v1755 = v1753[v1855];
    int v1863 = v1755 + ((int)((unsigned int)(v1755 - v1754) >> 31));
    v1753[v1855] = v1863;
    int * v1757 = v1740->cache_age;
    int v1758 = v1757[v1856];
    int v1865 = v1758 + ((int)((unsigned int)(v1758 - v1754) >> 31));
    v1757[v1856] = v1865;
    int * v1760 = v1740->cache_age;
    v1760[v1862] = 0;
    v1845 = v1862;
  } else {
    int * v1763 = v1740->cache_age;
    int v1869 = (((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2;
    int v1764 = v1763[v1869];
    int * v1765 = v1740->cache_tags;
    int v1766 = v1765[v1869];
    int v1767 = v1763[v1856];
    int v1768 = v1765[v1856];
    bool v1871 = !(((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) == 0);
    int v1822;
    if (v1871) {
      int * v1769 = v1740->cache_age;
      int v1873 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) & 1);
      int v1770 = v1769[v1873];
      int v1771 = v1769[v1857];
      int v1874 = v1771 + ((int)((unsigned int)(v1771 - v1770) >> 31));
      v1769[v1857] = v1874;
      int * v1773 = v1740->cache_age;
      int v1774 = v1773[v1858];
      int v1876 = v1774 + ((int)((unsigned int)(v1774 - v1770) >> 31));
      v1773[v1858] = v1876;
      int * v1776 = v1740->cache_age;
      v1776[v1873] = 0;
      v1822 = v1873;
    } else {
      int * v1779 = v1740->cache_age;
      int v1880 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2);
      int v1780 = v1779[v1880];
      int * v1781 = v1740->cache_tags;
      int v1782 = v1781[v1880];
      int v1783 = v1779[v1858];
      int v1784 = v1781[v1858];
      int * v1785 = v1740->cache_dirty;
      int v1883 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1786 = v1785[v1883];
      bool v1884 = !(v1786 == 0);
      if (v1884) {
        int * v1787 = v1740->cache_tags;
        int v1788 = v1787[v1883];
        int * v1789 = v1740->cache_vals;
        int v1887 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1790 = v1789[v1887];
        int v1888 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1791 = v1789[v1888];
        int * v1792 = v1740->mem;
        int v1890 = v1788 * 2;
        v1792[v1890] = v1790;
        int * v1794 = v1740->mem;
        int v1893 = (v1788 * 2) + 1;
        v1794[v1893] = v1791;
        ;
      } else {
        ;
      }
      int * v1799 = v1740->mem;
      int v1898 = ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) * 2;
      int v1800 = v1799[v1898];
      int v1899 = (((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) * 2) + 1;
      int v1801 = v1799[v1899];
      int * v1802 = v1740->cache_vals;
      int v1901 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1802[v1901] = v1800;
      int * v1804 = v1740->cache_vals;
      int v1904 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1804[v1904] = v1801;
      int * v1806 = v1740->cache_tags;
      int v1907 = (int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1);
      v1806[v1883] = v1907;
      int * v1808 = v1740->cache_dirty;
      v1808[v1883] = 0;
      int * v1810 = v1740->cache_age;
      v1810[v1883] = 1;
      int * v1812 = v1740->cache_age;
      int v1813 = v1812[v1883];
      int v1814 = v1812[v1857];
      int v1913 = v1814 + ((int)((unsigned int)(v1814 - v1813) >> 31));
      v1812[v1857] = v1913;
      int * v1816 = v1740->cache_age;
      int v1817 = v1816[v1858];
      int v1915 = v1817 + ((int)((unsigned int)(v1817 - v1813) >> 31));
      v1816[v1858] = v1915;
      int * v1819 = v1740->cache_age;
      v1819[v1883] = 0;
      v1822 = v1883;
    }
    int * v1823 = v1740->cache_vals;
    int v1918 = v1822 * 2;
    int v1824 = v1823[v1918];
    int v1919 = (v1822 * 2) + 1;
    int v1825 = v1823[v1919];
    int v1920 = (((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((((v1764 + ((~(((v1766 ^ -1) | (-(v1766 ^ -1))) >> 31)) & 2)) - (v1767 + ((~(((v1768 ^ -1) | (-(v1768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1823[v1920] = v1824;
    int * v1827 = v1740->cache_vals;
    int v1923 = ((((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((((v1764 + ((~(((v1766 ^ -1) | (-(v1766 ^ -1))) >> 31)) & 2)) - (v1767 + ((~(((v1768 ^ -1) | (-(v1768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1827[v1923] = v1825;
    int * v1829 = v1740->cache_tags;
    int v1926 = ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((((v1764 + ((~(((v1766 ^ -1) | (-(v1766 ^ -1))) >> 31)) & 2)) - (v1767 + ((~(((v1768 ^ -1) | (-(v1768 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1927 = (int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1);
    v1829[v1926] = v1927;
    int * v1831 = v1740->cache_dirty;
    v1831[v1926] = 0;
    int * v1833 = v1740->cache_age;
    v1833[v1926] = 1;
    int * v1835 = v1740->cache_age;
    int v1836 = v1835[v1926];
    int v1837 = v1835[v1855];
    int v1933 = v1837 + ((int)((unsigned int)(v1837 - v1836) >> 31));
    v1835[v1855] = v1933;
    int * v1839 = v1740->cache_age;
    int v1840 = v1839[v1856];
    int v1935 = v1840 + ((int)((unsigned int)(v1840 - v1836) >> 31));
    v1839[v1856] = v1935;
    int * v1842 = v1740->cache_age;
    v1842[v1926] = 0;
    v1845 = v1926;
  }
  int v1938 = (v1845 * 2) + (((int)((unsigned int)v1744 >> 2)) & 1);
  int v1846 = v1752[v1938];
  int * v1847 = v1740->regs;
  v1847[14] = v1846;
  struct StateT * v1849 = slot_6(v1740);
  return v1849;
}

struct StateT * slot_104(struct StateT * v6639) {
  int v6640 = v6639->timer;
  int v6652 = v6640 + 1;
  v6639->timer = v6652;
  int * v6642 = v6639->regs;
  int v6643 = v6642[6];
  int v6644 = v6642[7];
  bool v6656 = (v6643 ^ -2147483648) < (v6644 ^ -2147483648);
  int v6647;
  if (v6656) {
    v6647 = 1;
  } else {
    v6647 = 0;
  }
  int * v6648 = v6639->regs;
  v6648[6] = v6647;
  struct StateT * v6650 = slot_105(v6639);
  return v6650;
}

struct StateT * slot_235(struct StateT * v13896) {
  int v13897 = v13896->timer;
  int v13904 = v13897 + 1;
  v13896->timer = v13904;
  int * v13899 = v13896->regs;
  int v13900 = v13899[5];
  int v13908 = v13900 << 13;
  v13899[13] = v13908;
  struct StateT * v13902 = slot_237(v13896);
  return v13902;
}

struct StateT * slot_54(struct StateT * v4424) {
  int v4425 = v4424->timer;
  int v4437 = v4425 + 1;
  v4424->timer = v4437;
  int * v4427 = v4424->regs;
  int v4428 = v4427[29];
  int v4429 = v4427[8];
  bool v4441 = (v4428 ^ -2147483648) < (v4429 ^ -2147483648);
  int v4432;
  if (v4441) {
    v4432 = 1;
  } else {
    v4432 = 0;
  }
  int * v4433 = v4424->regs;
  v4433[6] = v4432;
  struct StateT * v4435 = slot_55(v4424);
  return v4435;
}

struct StateT * slot_26(struct StateT * v2770) {
  int v2771 = v2770->timer;
  int v3211 = v2771 + 1;
  v2770->timer = v3211;
  int * v2773 = v2770->regs;
  int v2774 = v2773[10];
  int v2775 = v2773[15];
  int * v2776 = v2770->saved_regs;
  int v2777 = v2773[5];
  v2776[5] = v2777;
  int v2779 = v2770->timer;
  int v3218 = v2779 + 1;
  v2770->timer = v3218;
  int * v2781 = v2770->regs;
  int v2782 = v2781[6];
  int v2783 = v2781[5];
  int v3221 = v2782 + v2783;
  v2781[5] = v3221;
  int * v2785 = v2770->saved_regs;
  int * v2786 = v2770->regs;
  int v2787 = v2786[7];
  v2785[7] = v2787;
  int v2789 = v2770->timer;
  int v3226 = v2789 + 1;
  v2770->timer = v3226;
  int * v2791 = v2770->regs;
  int v2792 = v2791[11];
  int * v2793 = v2770->cache_tags;
  int v3230 = (((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2794 = v2793[v3230];
  int v3231 = ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2795 = v2793[v3231];
  int v3232 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2796 = v2793[v3232];
  int v3233 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2797 = v2793[v3233];
  int v2798 = v2770->timer;
  int v3234 = v2798 + ((100 ^ (((~(((v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2770->timer = v3234;
  int * v2800 = v2770->cache_vals;
  bool v3235 = !(((~(((v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2893;
  if (v3235) {
    int * v2801 = v2770->cache_age;
    int v3237 = ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2802 = v2801[v3237];
    int v2803 = v2801[v3230];
    int v3238 = v2803 + ((int)((unsigned int)(v2803 - v2802) >> 31));
    v2801[v3230] = v3238;
    int * v2805 = v2770->cache_age;
    int v2806 = v2805[v3231];
    int v3240 = v2806 + ((int)((unsigned int)(v2806 - v2802) >> 31));
    v2805[v3231] = v3240;
    int * v2808 = v2770->cache_age;
    v2808[v3237] = 0;
    v2893 = v3237;
  } else {
    int * v2811 = v2770->cache_age;
    int v3244 = (((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2812 = v2811[v3244];
    int * v2813 = v2770->cache_tags;
    int v2814 = v2813[v3244];
    int v2815 = v2811[v3231];
    int v2816 = v2813[v3231];
    bool v3246 = !(((~(((v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2870;
    if (v3246) {
      int * v2817 = v2770->cache_age;
      int v3248 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2818 = v2817[v3248];
      int v2819 = v2817[v3232];
      int v3249 = v2819 + ((int)((unsigned int)(v2819 - v2818) >> 31));
      v2817[v3232] = v3249;
      int * v2821 = v2770->cache_age;
      int v2822 = v2821[v3233];
      int v3251 = v2822 + ((int)((unsigned int)(v2822 - v2818) >> 31));
      v2821[v3233] = v3251;
      int * v2824 = v2770->cache_age;
      v2824[v3248] = 0;
      v2870 = v3248;
    } else {
      int * v2827 = v2770->cache_age;
      int v3255 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2828 = v2827[v3255];
      int * v2829 = v2770->cache_tags;
      int v2830 = v2829[v3255];
      int v2831 = v2827[v3233];
      int v2832 = v2829[v3233];
      int * v2833 = v2770->cache_dirty;
      int v3258 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2834 = v2833[v3258];
      bool v3259 = !(v2834 == 0);
      if (v3259) {
        int * v2835 = v2770->cache_tags;
        int v2836 = v2835[v3258];
        int * v2837 = v2770->cache_vals;
        int v3262 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2838 = v2837[v3262];
        int v3263 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2839 = v2837[v3263];
        int * v2840 = v2770->mem;
        int v3265 = v2836 * 2;
        v2840[v3265] = v2838;
        int * v2842 = v2770->mem;
        int v3268 = (v2836 * 2) + 1;
        v2842[v3268] = v2839;
        ;
      } else {
        ;
      }
      int * v2847 = v2770->mem;
      int v3273 = ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) * 2;
      int v2848 = v2847[v3273];
      int v3274 = (((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2849 = v2847[v3274];
      int * v2850 = v2770->cache_vals;
      int v3276 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2850[v3276] = v2848;
      int * v2852 = v2770->cache_vals;
      int v3279 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2852[v3279] = v2849;
      int * v2854 = v2770->cache_tags;
      int v3282 = (int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1);
      v2854[v3258] = v3282;
      int * v2856 = v2770->cache_dirty;
      v2856[v3258] = 0;
      int * v2858 = v2770->cache_age;
      v2858[v3258] = 1;
      int * v2860 = v2770->cache_age;
      int v2861 = v2860[v3258];
      int v2862 = v2860[v3232];
      int v3288 = v2862 + ((int)((unsigned int)(v2862 - v2861) >> 31));
      v2860[v3232] = v3288;
      int * v2864 = v2770->cache_age;
      int v2865 = v2864[v3233];
      int v3290 = v2865 + ((int)((unsigned int)(v2865 - v2861) >> 31));
      v2864[v3233] = v3290;
      int * v2867 = v2770->cache_age;
      v2867[v3258] = 0;
      v2870 = v3258;
    }
    int * v2871 = v2770->cache_vals;
    int v3293 = v2870 * 2;
    int v2872 = v2871[v3293];
    int v3294 = (v2870 * 2) + 1;
    int v2873 = v2871[v3294];
    int v3295 = (((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2812 + ((~(((v2814 ^ -1) | (-(v2814 ^ -1))) >> 31)) & 2)) - (v2815 + ((~(((v2816 ^ -1) | (-(v2816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2871[v3295] = v2872;
    int * v2875 = v2770->cache_vals;
    int v3298 = ((((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2812 + ((~(((v2814 ^ -1) | (-(v2814 ^ -1))) >> 31)) & 2)) - (v2815 + ((~(((v2816 ^ -1) | (-(v2816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2875[v3298] = v2873;
    int * v2877 = v2770->cache_tags;
    int v3301 = ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2812 + ((~(((v2814 ^ -1) | (-(v2814 ^ -1))) >> 31)) & 2)) - (v2815 + ((~(((v2816 ^ -1) | (-(v2816 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3302 = (int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1);
    v2877[v3301] = v3302;
    int * v2879 = v2770->cache_dirty;
    v2879[v3301] = 0;
    int * v2881 = v2770->cache_age;
    v2881[v3301] = 1;
    int * v2883 = v2770->cache_age;
    int v2884 = v2883[v3301];
    int v2885 = v2883[v3230];
    int v3308 = v2885 + ((int)((unsigned int)(v2885 - v2884) >> 31));
    v2883[v3230] = v3308;
    int * v2887 = v2770->cache_age;
    int v2888 = v2887[v3231];
    int v3310 = v2888 + ((int)((unsigned int)(v2888 - v2884) >> 31));
    v2887[v3231] = v3310;
    int * v2890 = v2770->cache_age;
    v2890[v3301] = 0;
    v2893 = v3301;
  }
  int v3313 = (v2893 * 2) + (((int)((unsigned int)(v2792 + 8) >> 2)) & 1);
  int v2894 = v2800[v3313];
  int * v2895 = v2770->regs;
  v2895[7] = v2894;
  int * v2897 = v2770->saved_regs;
  int * v2898 = v2770->regs;
  int v2899 = v2898[28];
  v2897[28] = v2899;
  int v2901 = v2770->timer;
  int v3320 = v2901 + 1;
  v2770->timer = v3320;
  int * v2903 = v2770->regs;
  int v2904 = v2903[11];
  bool v3322 = (((int)((unsigned int)(v2774 + 4) >> 2)) & 3) == (((int)((unsigned int)(v2904 + 12) >> 2)) & 3);
  int v3011;
  if (v3322) {
    int v2905 = v2770->timer;
    int v3323 = v2905 + 1;
    v2770->timer = v3323;
    v3011 = v2775;
  } else {
    int * v2908 = v2770->cache_tags;
    int v3326 = (((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2909 = v2908[v3326];
    int v3327 = ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
    int v2910 = v2908[v3327];
    int v3328 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2);
    int v2911 = v2908[v3328];
    int v3329 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v2912 = v2908[v3329];
    int v2913 = v2770->timer;
    int v3330 = v2913 + ((100 ^ (((~(((v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
    v2770->timer = v3330;
    int * v2915 = v2770->cache_vals;
    bool v3331 = !(((~(((v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3008;
    if (v3331) {
      int * v2916 = v2770->cache_age;
      int v3333 = ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2917 = v2916[v3333];
      int v2918 = v2916[v3326];
      int v3334 = v2918 + ((int)((unsigned int)(v2918 - v2917) >> 31));
      v2916[v3326] = v3334;
      int * v2920 = v2770->cache_age;
      int v2921 = v2920[v3327];
      int v3336 = v2921 + ((int)((unsigned int)(v2921 - v2917) >> 31));
      v2920[v3327] = v3336;
      int * v2923 = v2770->cache_age;
      v2923[v3333] = 0;
      v3008 = v3333;
    } else {
      int * v2926 = v2770->cache_age;
      int v3340 = (((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2;
      int v2927 = v2926[v3340];
      int * v2928 = v2770->cache_tags;
      int v2929 = v2928[v3340];
      int v2930 = v2926[v3327];
      int v2931 = v2928[v3327];
      bool v3342 = !(((~(((v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) == 0);
      int v2985;
      if (v3342) {
        int * v2932 = v2770->cache_age;
        int v3344 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) & 1);
        int v2933 = v2932[v3344];
        int v2934 = v2932[v3328];
        int v3345 = v2934 + ((int)((unsigned int)(v2934 - v2933) >> 31));
        v2932[v3328] = v3345;
        int * v2936 = v2770->cache_age;
        int v2937 = v2936[v3329];
        int v3347 = v2937 + ((int)((unsigned int)(v2937 - v2933) >> 31));
        v2936[v3329] = v3347;
        int * v2939 = v2770->cache_age;
        v2939[v3344] = 0;
        v2985 = v3344;
      } else {
        int * v2942 = v2770->cache_age;
        int v3351 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2);
        int v2943 = v2942[v3351];
        int * v2944 = v2770->cache_tags;
        int v2945 = v2944[v3351];
        int v2946 = v2942[v3329];
        int v2947 = v2944[v3329];
        int * v2948 = v2770->cache_dirty;
        int v3354 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v2949 = v2948[v3354];
        bool v3355 = !(v2949 == 0);
        if (v3355) {
          int * v2950 = v2770->cache_tags;
          int v2951 = v2950[v3354];
          int * v2952 = v2770->cache_vals;
          int v3358 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v2953 = v2952[v3358];
          int v3359 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v2954 = v2952[v3359];
          int * v2955 = v2770->mem;
          int v3361 = v2951 * 2;
          v2955[v3361] = v2953;
          int * v2957 = v2770->mem;
          int v3364 = (v2951 * 2) + 1;
          v2957[v3364] = v2954;
          ;
        } else {
          ;
        }
        int * v2962 = v2770->mem;
        int v3369 = ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) * 2;
        int v2963 = v2962[v3369];
        int v3370 = (((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) * 2) + 1;
        int v2964 = v2962[v3370];
        int * v2965 = v2770->cache_vals;
        int v3372 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v2965[v3372] = v2963;
        int * v2967 = v2770->cache_vals;
        int v3375 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v2967[v3375] = v2964;
        int * v2969 = v2770->cache_tags;
        int v3378 = (int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1);
        v2969[v3354] = v3378;
        int * v2971 = v2770->cache_dirty;
        v2971[v3354] = 0;
        int * v2973 = v2770->cache_age;
        v2973[v3354] = 1;
        int * v2975 = v2770->cache_age;
        int v2976 = v2975[v3354];
        int v2977 = v2975[v3328];
        int v3384 = v2977 + ((int)((unsigned int)(v2977 - v2976) >> 31));
        v2975[v3328] = v3384;
        int * v2979 = v2770->cache_age;
        int v2980 = v2979[v3329];
        int v3386 = v2980 + ((int)((unsigned int)(v2980 - v2976) >> 31));
        v2979[v3329] = v3386;
        int * v2982 = v2770->cache_age;
        v2982[v3354] = 0;
        v2985 = v3354;
      }
      int * v2986 = v2770->cache_vals;
      int v3389 = v2985 * 2;
      int v2987 = v2986[v3389];
      int v3390 = (v2985 * 2) + 1;
      int v2988 = v2986[v3390];
      int v3391 = (((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2927 + ((~(((v2929 ^ -1) | (-(v2929 ^ -1))) >> 31)) & 2)) - (v2930 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2986[v3391] = v2987;
      int * v2990 = v2770->cache_vals;
      int v3394 = ((((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2927 + ((~(((v2929 ^ -1) | (-(v2929 ^ -1))) >> 31)) & 2)) - (v2930 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2990[v3394] = v2988;
      int * v2992 = v2770->cache_tags;
      int v3397 = ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2927 + ((~(((v2929 ^ -1) | (-(v2929 ^ -1))) >> 31)) & 2)) - (v2930 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3398 = (int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1);
      v2992[v3397] = v3398;
      int * v2994 = v2770->cache_dirty;
      v2994[v3397] = 0;
      int * v2996 = v2770->cache_age;
      v2996[v3397] = 1;
      int * v2998 = v2770->cache_age;
      int v2999 = v2998[v3397];
      int v3000 = v2998[v3326];
      int v3404 = v3000 + ((int)((unsigned int)(v3000 - v2999) >> 31));
      v2998[v3326] = v3404;
      int * v3002 = v2770->cache_age;
      int v3003 = v3002[v3327];
      int v3406 = v3003 + ((int)((unsigned int)(v3003 - v2999) >> 31));
      v3002[v3327] = v3406;
      int * v3005 = v2770->cache_age;
      v3005[v3397] = 0;
      v3008 = v3397;
    }
    int v3409 = (v3008 * 2) + (((int)((unsigned int)(v2904 + 12) >> 2)) & 1);
    int v3009 = v2915[v3409];
    v3011 = v3009;
  }
  int * v3012 = v2770->regs;
  v3012[28] = v3011;
  int * v3014 = v2770->saved_regs;
  int * v3015 = v2770->regs;
  int v3016 = v3015[31];
  v3014[31] = v3016;
  int v3018 = v2770->timer;
  int v3417 = v3018 + 1;
  v2770->timer = v3417;
  int * v3020 = v2770->regs;
  int v3021 = v3020[29];
  int v3022 = v3020[5];
  int v3420 = v3021 + v3022;
  v3020[31] = v3420;
  int * v3024 = v2770->cache_tags;
  int v3422 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3025 = v3024[v3422];
  int v3423 = ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3026 = v3024[v3423];
  int v3424 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3027 = v3024[v3424];
  int v3425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3028 = v3024[v3425];
  int v3029 = v2770->timer;
  int v3426 = v3029 + ((100 ^ (((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2770->timer = v3426;
  bool v3427 = !(((~(((v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3123;
  if (v3427) {
    int * v3031 = v2770->cache_age;
    int v3429 = ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3032 = v3031[v3429];
    int v3033 = v3031[v3422];
    int v3430 = v3033 + ((int)((unsigned int)(v3033 - v3032) >> 31));
    v3031[v3422] = v3430;
    int * v3035 = v2770->cache_age;
    int v3036 = v3035[v3423];
    int v3432 = v3036 + ((int)((unsigned int)(v3036 - v3032) >> 31));
    v3035[v3423] = v3432;
    int * v3038 = v2770->cache_age;
    v3038[v3429] = 0;
    v3123 = v3429;
  } else {
    int * v3041 = v2770->cache_age;
    int v3436 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3042 = v3041[v3436];
    int * v3043 = v2770->cache_tags;
    int v3044 = v3043[v3436];
    int v3045 = v3041[v3423];
    int v3046 = v3043[v3423];
    bool v3438 = !(((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3100;
    if (v3438) {
      int * v3047 = v2770->cache_age;
      int v3440 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3048 = v3047[v3440];
      int v3049 = v3047[v3424];
      int v3441 = v3049 + ((int)((unsigned int)(v3049 - v3048) >> 31));
      v3047[v3424] = v3441;
      int * v3051 = v2770->cache_age;
      int v3052 = v3051[v3425];
      int v3443 = v3052 + ((int)((unsigned int)(v3052 - v3048) >> 31));
      v3051[v3425] = v3443;
      int * v3054 = v2770->cache_age;
      v3054[v3440] = 0;
      v3100 = v3440;
    } else {
      int * v3057 = v2770->cache_age;
      int v3447 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3058 = v3057[v3447];
      int * v3059 = v2770->cache_tags;
      int v3060 = v3059[v3447];
      int v3061 = v3057[v3425];
      int v3062 = v3059[v3425];
      int * v3063 = v2770->cache_dirty;
      int v3450 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3064 = v3063[v3450];
      bool v3451 = !(v3064 == 0);
      if (v3451) {
        int * v3065 = v2770->cache_tags;
        int v3066 = v3065[v3450];
        int * v3067 = v2770->cache_vals;
        int v3454 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3068 = v3067[v3454];
        int v3455 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3069 = v3067[v3455];
        int * v3070 = v2770->mem;
        int v3457 = v3066 * 2;
        v3070[v3457] = v3068;
        int * v3072 = v2770->mem;
        int v3460 = (v3066 * 2) + 1;
        v3072[v3460] = v3069;
        ;
      } else {
        ;
      }
      int * v3077 = v2770->mem;
      int v3465 = ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2;
      int v3078 = v3077[v3465];
      int v3466 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3079 = v3077[v3466];
      int * v3080 = v2770->cache_vals;
      int v3468 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3080[v3468] = v3078;
      int * v3082 = v2770->cache_vals;
      int v3471 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3082[v3471] = v3079;
      int * v3084 = v2770->cache_tags;
      int v3474 = (int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1);
      v3084[v3450] = v3474;
      int * v3086 = v2770->cache_dirty;
      v3086[v3450] = 0;
      int * v3088 = v2770->cache_age;
      v3088[v3450] = 1;
      int * v3090 = v2770->cache_age;
      int v3091 = v3090[v3450];
      int v3092 = v3090[v3424];
      int v3480 = v3092 + ((int)((unsigned int)(v3092 - v3091) >> 31));
      v3090[v3424] = v3480;
      int * v3094 = v2770->cache_age;
      int v3095 = v3094[v3425];
      int v3482 = v3095 + ((int)((unsigned int)(v3095 - v3091) >> 31));
      v3094[v3425] = v3482;
      int * v3097 = v2770->cache_age;
      v3097[v3450] = 0;
      v3100 = v3450;
    }
    int * v3101 = v2770->cache_vals;
    int v3485 = v3100 * 2;
    int v3102 = v3101[v3485];
    int v3486 = (v3100 * 2) + 1;
    int v3103 = v3101[v3486];
    int v3487 = (((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3042 + ((~(((v3044 ^ -1) | (-(v3044 ^ -1))) >> 31)) & 2)) - (v3045 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3101[v3487] = v3102;
    int * v3105 = v2770->cache_vals;
    int v3490 = ((((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3042 + ((~(((v3044 ^ -1) | (-(v3044 ^ -1))) >> 31)) & 2)) - (v3045 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3105[v3490] = v3103;
    int * v3107 = v2770->cache_tags;
    int v3493 = ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3042 + ((~(((v3044 ^ -1) | (-(v3044 ^ -1))) >> 31)) & 2)) - (v3045 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3494 = (int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1);
    v3107[v3493] = v3494;
    int * v3109 = v2770->cache_dirty;
    v3109[v3493] = 0;
    int * v3111 = v2770->cache_age;
    v3111[v3493] = 1;
    int * v3113 = v2770->cache_age;
    int v3114 = v3113[v3493];
    int v3115 = v3113[v3422];
    int v3500 = v3115 + ((int)((unsigned int)(v3115 - v3114) >> 31));
    v3113[v3422] = v3500;
    int * v3117 = v2770->cache_age;
    int v3118 = v3117[v3423];
    int v3502 = v3118 + ((int)((unsigned int)(v3118 - v3114) >> 31));
    v3117[v3423] = v3502;
    int * v3120 = v2770->cache_age;
    v3120[v3493] = 0;
    v3123 = v3493;
  }
  int * v3124 = v2770->cache_vals;
  int v3505 = (v3123 * 2) + (((int)((unsigned int)(v2774 + 4) >> 2)) & 1);
  v3124[v3505] = v2775;
  int * v3126 = v2770->cache_tags;
  int v3127 = v3126[v3424];
  int v3128 = v3126[v3425];
  bool v3508 = !(((~(((v3127 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3127 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3182;
  if (v3508) {
    int * v3129 = v2770->cache_age;
    int v3510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3130 = v3129[v3510];
    int v3131 = v3129[v3424];
    int v3511 = v3131 + ((int)((unsigned int)(v3131 - v3130) >> 31));
    v3129[v3424] = v3511;
    int * v3133 = v2770->cache_age;
    int v3134 = v3133[v3425];
    int v3513 = v3134 + ((int)((unsigned int)(v3134 - v3130) >> 31));
    v3133[v3425] = v3513;
    int * v3136 = v2770->cache_age;
    v3136[v3510] = 0;
    v3182 = v3510;
  } else {
    int * v3139 = v2770->cache_age;
    int v3517 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2);
    int v3140 = v3139[v3517];
    int * v3141 = v2770->cache_tags;
    int v3142 = v3141[v3517];
    int v3143 = v3139[v3425];
    int v3144 = v3141[v3425];
    int * v3145 = v2770->cache_dirty;
    int v3520 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3146 = v3145[v3520];
    bool v3521 = !(v3146 == 0);
    if (v3521) {
      int * v3147 = v2770->cache_tags;
      int v3148 = v3147[v3520];
      int * v3149 = v2770->cache_vals;
      int v3524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3150 = v3149[v3524];
      int v3525 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3151 = v3149[v3525];
      int * v3152 = v2770->mem;
      int v3527 = v3148 * 2;
      v3152[v3527] = v3150;
      int * v3154 = v2770->mem;
      int v3530 = (v3148 * 2) + 1;
      v3154[v3530] = v3151;
      ;
    } else {
      ;
    }
    int * v3159 = v2770->mem;
    int v3535 = ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2;
    int v3160 = v3159[v3535];
    int v3536 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2) + 1;
    int v3161 = v3159[v3536];
    int * v3162 = v2770->cache_vals;
    int v3538 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3162[v3538] = v3160;
    int * v3164 = v2770->cache_vals;
    int v3541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3164[v3541] = v3161;
    int * v3166 = v2770->cache_tags;
    int v3544 = (int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1);
    v3166[v3520] = v3544;
    int * v3168 = v2770->cache_dirty;
    v3168[v3520] = 0;
    int * v3170 = v2770->cache_age;
    v3170[v3520] = 1;
    int * v3172 = v2770->cache_age;
    int v3173 = v3172[v3520];
    int v3174 = v3172[v3424];
    int v3550 = v3174 + ((int)((unsigned int)(v3174 - v3173) >> 31));
    v3172[v3424] = v3550;
    int * v3176 = v2770->cache_age;
    int v3177 = v3176[v3425];
    int v3552 = v3177 + ((int)((unsigned int)(v3177 - v3173) >> 31));
    v3176[v3425] = v3552;
    int * v3179 = v2770->cache_age;
    v3179[v3520] = 0;
    v3182 = v3520;
  }
  int * v3183 = v2770->cache_vals;
  int v3555 = (v3182 * 2) + (((int)((unsigned int)(v2774 + 4) >> 2)) & 1);
  v3183[v3555] = v2775;
  int * v3185 = v2770->cache_dirty;
  v3185[v3182] = 1;
  bool v3559 = (((int)((unsigned int)(v2792 + 8) >> 2)) == ((int)((unsigned int)(v2774 + 4) >> 2))) | (((((int)((unsigned int)(v2904 + 12) >> 2)) & 3) == (((int)((unsigned int)(v2774 + 4) >> 2)) & 3)) & (!(((int)((unsigned int)(v2904 + 12) >> 2)) == ((int)((unsigned int)(v2774 + 4) >> 2)))));
  struct StateT * v3209;
  if (v3559) {
    int v3187 = v2770->timer;
    int v3560 = v3187 + 15;
    v2770->timer = v3560;
    int * v3189 = v2770->saved_regs;
    int v3190 = v3189[5];
    int * v3191 = v2770->regs;
    v3191[5] = v3190;
    int * v3193 = v2770->saved_regs;
    int v3194 = v3193[7];
    int * v3195 = v2770->regs;
    v3195[7] = v3194;
    int * v3197 = v2770->saved_regs;
    int v3198 = v3197[28];
    int * v3199 = v2770->regs;
    v3199[28] = v3198;
    int * v3201 = v2770->saved_regs;
    int v3202 = v3201[31];
    int * v3203 = v2770->regs;
    v3203[31] = v3202;
    struct StateT * v3205 = slot_27(v2770);
    v3209 = v3205;
  } else {
    struct StateT * v3207 = slot_31(v2770);
    v3209 = v3207;
  }
  return v3209;
}

struct StateT * slot_206(struct StateT * v11131) {
  int * v11132 = v11131->saved_regs;
  int * v11133 = v11131->regs;
  int v11134 = v11133[13];
  v11132[13] = v11134;
  int v11136 = v11131->timer;
  int v11147 = v11136 + 1;
  v11131->timer = v11147;
  int * v11138 = v11131->regs;
  int v11139 = v11138[5];
  int v11150 = v11139 << 13;
  v11138[13] = v11150;
  struct StateT * v11141 = slot_207(v11131);
  return v11141;
}

struct StateT * slot_227(struct StateT * v12447) {
  int v12448 = v12447->timer;
  int v12460 = v12448 + 1;
  v12447->timer = v12460;
  int * v12450 = v12447->regs;
  int v12451 = v12450[5];
  int v12452 = v12450[12];
  bool v12464 = (v12451 ^ -2147483648) < (v12452 ^ -2147483648);
  int v12455;
  if (v12464) {
    v12455 = 1;
  } else {
    v12455 = 0;
  }
  int * v12456 = v12447->regs;
  v12456[12] = v12455;
  struct StateT * v12458 = slot_229(v12447);
  return v12458;
}

struct StateT * slot_169(struct StateT * v10326) {
  int v10327 = v10326->timer;
  int v10437 = v10327 + 1;
  v10326->timer = v10437;
  int * v10329 = v10326->regs;
  int v10330 = v10329[11];
  int * v10331 = v10326->cache_tags;
  int v10441 = (((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2;
  int v10332 = v10331[v10441];
  int v10442 = ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10333 = v10331[v10442];
  int v10443 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2);
  int v10334 = v10331[v10443];
  int v10444 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10335 = v10331[v10444];
  int v10336 = v10326->timer;
  int v10445 = v10336 + ((100 ^ (((~(((v10334 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10334 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10332 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10332 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10333 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10333 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10334 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10334 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10326->timer = v10445;
  int * v10338 = v10326->cache_vals;
  bool v10446 = !(((~(((v10332 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10332 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10333 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10333 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v10431;
  if (v10446) {
    int * v10339 = v10326->cache_age;
    int v10448 = ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v10333 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10333 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v10340 = v10339[v10448];
    int v10341 = v10339[v10441];
    int v10449 = v10341 + ((int)((unsigned int)(v10341 - v10340) >> 31));
    v10339[v10441] = v10449;
    int * v10343 = v10326->cache_age;
    int v10344 = v10343[v10442];
    int v10451 = v10344 + ((int)((unsigned int)(v10344 - v10340) >> 31));
    v10343[v10442] = v10451;
    int * v10346 = v10326->cache_age;
    v10346[v10448] = 0;
    v10431 = v10448;
  } else {
    int * v10349 = v10326->cache_age;
    int v10455 = (((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2;
    int v10350 = v10349[v10455];
    int * v10351 = v10326->cache_tags;
    int v10352 = v10351[v10455];
    int v10353 = v10349[v10442];
    int v10354 = v10351[v10442];
    bool v10457 = !(((~(((v10334 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10334 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v10408;
    if (v10457) {
      int * v10355 = v10326->cache_age;
      int v10459 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))) | (-(v10335 ^ ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v10356 = v10355[v10459];
      int v10357 = v10355[v10443];
      int v10460 = v10357 + ((int)((unsigned int)(v10357 - v10356) >> 31));
      v10355[v10443] = v10460;
      int * v10359 = v10326->cache_age;
      int v10360 = v10359[v10444];
      int v10462 = v10360 + ((int)((unsigned int)(v10360 - v10356) >> 31));
      v10359[v10444] = v10462;
      int * v10362 = v10326->cache_age;
      v10362[v10459] = 0;
      v10408 = v10459;
    } else {
      int * v10365 = v10326->cache_age;
      int v10466 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2);
      int v10366 = v10365[v10466];
      int * v10367 = v10326->cache_tags;
      int v10368 = v10367[v10466];
      int v10369 = v10365[v10444];
      int v10370 = v10367[v10444];
      int * v10371 = v10326->cache_dirty;
      int v10469 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10366 + ((~(((v10368 ^ -1) | (-(v10368 ^ -1))) >> 31)) & 2)) - (v10369 + ((~(((v10370 ^ -1) | (-(v10370 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10372 = v10371[v10469];
      bool v10470 = !(v10372 == 0);
      if (v10470) {
        int * v10373 = v10326->cache_tags;
        int v10374 = v10373[v10469];
        int * v10375 = v10326->cache_vals;
        int v10473 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10366 + ((~(((v10368 ^ -1) | (-(v10368 ^ -1))) >> 31)) & 2)) - (v10369 + ((~(((v10370 ^ -1) | (-(v10370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10376 = v10375[v10473];
        int v10474 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10366 + ((~(((v10368 ^ -1) | (-(v10368 ^ -1))) >> 31)) & 2)) - (v10369 + ((~(((v10370 ^ -1) | (-(v10370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10377 = v10375[v10474];
        int * v10378 = v10326->mem;
        int v10476 = v10374 * 2;
        v10378[v10476] = v10376;
        int * v10380 = v10326->mem;
        int v10479 = (v10374 * 2) + 1;
        v10380[v10479] = v10377;
        ;
      } else {
        ;
      }
      int * v10385 = v10326->mem;
      int v10484 = ((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) * 2;
      int v10386 = v10385[v10484];
      int v10485 = (((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) * 2) + 1;
      int v10387 = v10385[v10485];
      int * v10388 = v10326->cache_vals;
      int v10487 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10366 + ((~(((v10368 ^ -1) | (-(v10368 ^ -1))) >> 31)) & 2)) - (v10369 + ((~(((v10370 ^ -1) | (-(v10370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10388[v10487] = v10386;
      int * v10390 = v10326->cache_vals;
      int v10490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10366 + ((~(((v10368 ^ -1) | (-(v10368 ^ -1))) >> 31)) & 2)) - (v10369 + ((~(((v10370 ^ -1) | (-(v10370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10390[v10490] = v10387;
      int * v10392 = v10326->cache_tags;
      int v10493 = (int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1);
      v10392[v10469] = v10493;
      int * v10394 = v10326->cache_dirty;
      v10394[v10469] = 0;
      int * v10396 = v10326->cache_age;
      v10396[v10469] = 1;
      int * v10398 = v10326->cache_age;
      int v10399 = v10398[v10469];
      int v10400 = v10398[v10443];
      int v10499 = v10400 + ((int)((unsigned int)(v10400 - v10399) >> 31));
      v10398[v10443] = v10499;
      int * v10402 = v10326->cache_age;
      int v10403 = v10402[v10444];
      int v10501 = v10403 + ((int)((unsigned int)(v10403 - v10399) >> 31));
      v10402[v10444] = v10501;
      int * v10405 = v10326->cache_age;
      v10405[v10469] = 0;
      v10408 = v10469;
    }
    int * v10409 = v10326->cache_vals;
    int v10504 = v10408 * 2;
    int v10410 = v10409[v10504];
    int v10505 = (v10408 * 2) + 1;
    int v10411 = v10409[v10505];
    int v10506 = (((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v10350 + ((~(((v10352 ^ -1) | (-(v10352 ^ -1))) >> 31)) & 2)) - (v10353 + ((~(((v10354 ^ -1) | (-(v10354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10409[v10506] = v10410;
    int * v10413 = v10326->cache_vals;
    int v10509 = ((((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v10350 + ((~(((v10352 ^ -1) | (-(v10352 ^ -1))) >> 31)) & 2)) - (v10353 + ((~(((v10354 ^ -1) | (-(v10354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10413[v10509] = v10411;
    int * v10415 = v10326->cache_tags;
    int v10512 = ((((int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v10350 + ((~(((v10352 ^ -1) | (-(v10352 ^ -1))) >> 31)) & 2)) - (v10353 + ((~(((v10354 ^ -1) | (-(v10354 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10513 = (int)((unsigned int)((int)((unsigned int)(v10330 + 32) >> 2)) >> 1);
    v10415[v10512] = v10513;
    int * v10417 = v10326->cache_dirty;
    v10417[v10512] = 0;
    int * v10419 = v10326->cache_age;
    v10419[v10512] = 1;
    int * v10421 = v10326->cache_age;
    int v10422 = v10421[v10512];
    int v10423 = v10421[v10441];
    int v10519 = v10423 + ((int)((unsigned int)(v10423 - v10422) >> 31));
    v10421[v10441] = v10519;
    int * v10425 = v10326->cache_age;
    int v10426 = v10425[v10442];
    int v10521 = v10426 + ((int)((unsigned int)(v10426 - v10422) >> 31));
    v10425[v10442] = v10521;
    int * v10428 = v10326->cache_age;
    v10428[v10512] = 0;
    v10431 = v10512;
  }
  int v10524 = (v10431 * 2) + (((int)((unsigned int)(v10330 + 32) >> 2)) & 1);
  int v10432 = v10338[v10524];
  int * v10433 = v10326->regs;
  v10433[6] = v10432;
  struct StateT * v10435 = slot_170(v10326);
  return v10435;
}

struct StateT * slot_64(struct StateT * v4612) {
  int v4613 = v4612->timer;
  int v4617 = v4613 + 1;
  v4612->timer = v4617;
  struct StateT * v4615 = slot_65(v4612);
  return v4615;
}

struct StateT * slot_170(struct StateT * v10039) {
  int v10040 = v10039->timer;
  int v10150 = v10040 + 1;
  v10039->timer = v10150;
  int * v10042 = v10039->regs;
  int v10043 = v10042[11];
  int * v10044 = v10039->cache_tags;
  int v10154 = (((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2;
  int v10045 = v10044[v10154];
  int v10155 = ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10046 = v10044[v10155];
  int v10156 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2);
  int v10047 = v10044[v10156];
  int v10157 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10048 = v10044[v10157];
  int v10049 = v10039->timer;
  int v10158 = v10049 + ((100 ^ (((~(((v10047 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10047 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10045 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10045 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10046 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10046 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10047 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10047 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10039->timer = v10158;
  int * v10051 = v10039->cache_vals;
  bool v10159 = !(((~(((v10045 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10045 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10046 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10046 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v10144;
  if (v10159) {
    int * v10052 = v10039->cache_age;
    int v10161 = ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v10046 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10046 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v10053 = v10052[v10161];
    int v10054 = v10052[v10154];
    int v10162 = v10054 + ((int)((unsigned int)(v10054 - v10053) >> 31));
    v10052[v10154] = v10162;
    int * v10056 = v10039->cache_age;
    int v10057 = v10056[v10155];
    int v10164 = v10057 + ((int)((unsigned int)(v10057 - v10053) >> 31));
    v10056[v10155] = v10164;
    int * v10059 = v10039->cache_age;
    v10059[v10161] = 0;
    v10144 = v10161;
  } else {
    int * v10062 = v10039->cache_age;
    int v10168 = (((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2;
    int v10063 = v10062[v10168];
    int * v10064 = v10039->cache_tags;
    int v10065 = v10064[v10168];
    int v10066 = v10062[v10155];
    int v10067 = v10064[v10155];
    bool v10170 = !(((~(((v10047 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10047 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v10121;
    if (v10170) {
      int * v10068 = v10039->cache_age;
      int v10172 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))) | (-(v10048 ^ ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v10069 = v10068[v10172];
      int v10070 = v10068[v10156];
      int v10173 = v10070 + ((int)((unsigned int)(v10070 - v10069) >> 31));
      v10068[v10156] = v10173;
      int * v10072 = v10039->cache_age;
      int v10073 = v10072[v10157];
      int v10175 = v10073 + ((int)((unsigned int)(v10073 - v10069) >> 31));
      v10072[v10157] = v10175;
      int * v10075 = v10039->cache_age;
      v10075[v10172] = 0;
      v10121 = v10172;
    } else {
      int * v10078 = v10039->cache_age;
      int v10179 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2);
      int v10079 = v10078[v10179];
      int * v10080 = v10039->cache_tags;
      int v10081 = v10080[v10179];
      int v10082 = v10078[v10157];
      int v10083 = v10080[v10157];
      int * v10084 = v10039->cache_dirty;
      int v10182 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10079 + ((~(((v10081 ^ -1) | (-(v10081 ^ -1))) >> 31)) & 2)) - (v10082 + ((~(((v10083 ^ -1) | (-(v10083 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10085 = v10084[v10182];
      bool v10183 = !(v10085 == 0);
      if (v10183) {
        int * v10086 = v10039->cache_tags;
        int v10087 = v10086[v10182];
        int * v10088 = v10039->cache_vals;
        int v10186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10079 + ((~(((v10081 ^ -1) | (-(v10081 ^ -1))) >> 31)) & 2)) - (v10082 + ((~(((v10083 ^ -1) | (-(v10083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10089 = v10088[v10186];
        int v10187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10079 + ((~(((v10081 ^ -1) | (-(v10081 ^ -1))) >> 31)) & 2)) - (v10082 + ((~(((v10083 ^ -1) | (-(v10083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10090 = v10088[v10187];
        int * v10091 = v10039->mem;
        int v10189 = v10087 * 2;
        v10091[v10189] = v10089;
        int * v10093 = v10039->mem;
        int v10192 = (v10087 * 2) + 1;
        v10093[v10192] = v10090;
        ;
      } else {
        ;
      }
      int * v10098 = v10039->mem;
      int v10197 = ((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) * 2;
      int v10099 = v10098[v10197];
      int v10198 = (((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) * 2) + 1;
      int v10100 = v10098[v10198];
      int * v10101 = v10039->cache_vals;
      int v10200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10079 + ((~(((v10081 ^ -1) | (-(v10081 ^ -1))) >> 31)) & 2)) - (v10082 + ((~(((v10083 ^ -1) | (-(v10083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10101[v10200] = v10099;
      int * v10103 = v10039->cache_vals;
      int v10203 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10079 + ((~(((v10081 ^ -1) | (-(v10081 ^ -1))) >> 31)) & 2)) - (v10082 + ((~(((v10083 ^ -1) | (-(v10083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10103[v10203] = v10100;
      int * v10105 = v10039->cache_tags;
      int v10206 = (int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1);
      v10105[v10182] = v10206;
      int * v10107 = v10039->cache_dirty;
      v10107[v10182] = 0;
      int * v10109 = v10039->cache_age;
      v10109[v10182] = 1;
      int * v10111 = v10039->cache_age;
      int v10112 = v10111[v10182];
      int v10113 = v10111[v10156];
      int v10212 = v10113 + ((int)((unsigned int)(v10113 - v10112) >> 31));
      v10111[v10156] = v10212;
      int * v10115 = v10039->cache_age;
      int v10116 = v10115[v10157];
      int v10214 = v10116 + ((int)((unsigned int)(v10116 - v10112) >> 31));
      v10115[v10157] = v10214;
      int * v10118 = v10039->cache_age;
      v10118[v10182] = 0;
      v10121 = v10182;
    }
    int * v10122 = v10039->cache_vals;
    int v10217 = v10121 * 2;
    int v10123 = v10122[v10217];
    int v10218 = (v10121 * 2) + 1;
    int v10124 = v10122[v10218];
    int v10219 = (((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10063 + ((~(((v10065 ^ -1) | (-(v10065 ^ -1))) >> 31)) & 2)) - (v10066 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10122[v10219] = v10123;
    int * v10126 = v10039->cache_vals;
    int v10222 = ((((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10063 + ((~(((v10065 ^ -1) | (-(v10065 ^ -1))) >> 31)) & 2)) - (v10066 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10126[v10222] = v10124;
    int * v10128 = v10039->cache_tags;
    int v10225 = ((((int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10063 + ((~(((v10065 ^ -1) | (-(v10065 ^ -1))) >> 31)) & 2)) - (v10066 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10226 = (int)((unsigned int)((int)((unsigned int)(v10043 + 36) >> 2)) >> 1);
    v10128[v10225] = v10226;
    int * v10130 = v10039->cache_dirty;
    v10130[v10225] = 0;
    int * v10132 = v10039->cache_age;
    v10132[v10225] = 1;
    int * v10134 = v10039->cache_age;
    int v10135 = v10134[v10225];
    int v10136 = v10134[v10154];
    int v10232 = v10136 + ((int)((unsigned int)(v10136 - v10135) >> 31));
    v10134[v10154] = v10232;
    int * v10138 = v10039->cache_age;
    int v10139 = v10138[v10155];
    int v10234 = v10139 + ((int)((unsigned int)(v10139 - v10135) >> 31));
    v10138[v10155] = v10234;
    int * v10141 = v10039->cache_age;
    v10141[v10225] = 0;
    v10144 = v10225;
  }
  int v10237 = (v10144 * 2) + (((int)((unsigned int)(v10043 + 36) >> 2)) & 1);
  int v10145 = v10051[v10237];
  int * v10146 = v10039->regs;
  v10146[11] = v10145;
  struct StateT * v10148 = slot_172(v10039);
  return v10148;
}

struct StateT * slot_14(struct StateT * v2260) {
  int v2261 = v2260->timer;
  int v2269 = v2261 + 1;
  v2260->timer = v2269;
  int * v2263 = v2260->regs;
  int v2264 = v2263[15];
  int v2265 = v2263[13];
  int v2274 = v2264 * v2265;
  v2263[29] = v2274;
  struct StateT * v2267 = slot_15(v2260);
  return v2267;
}

struct StateT * slot_53(struct StateT * v4408) {
  int v4409 = v4408->timer;
  int v4417 = v4409 + 1;
  v4408->timer = v4417;
  int * v4411 = v4408->regs;
  int v4412 = v4411[31];
  int v4413 = v4411[30];
  int v4421 = v4412 + v4413;
  v4411[30] = v4421;
  struct StateT * v4415 = slot_54(v4408);
  return v4415;
}

struct StateT * slot_80(struct StateT * v5789) {
  int v5790 = v5789->timer;
  int v5900 = v5790 + 1;
  v5789->timer = v5900;
  int * v5792 = v5789->regs;
  int v5793 = v5792[11];
  int * v5794 = v5789->cache_tags;
  int v5904 = (((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2;
  int v5795 = v5794[v5904];
  int v5905 = ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5796 = v5794[v5905];
  int v5906 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2);
  int v5797 = v5794[v5906];
  int v5907 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5798 = v5794[v5907];
  int v5799 = v5789->timer;
  int v5908 = v5799 + ((100 ^ (((~(((v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5789->timer = v5908;
  int * v5801 = v5789->cache_vals;
  bool v5909 = !(((~(((v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5894;
  if (v5909) {
    int * v5802 = v5789->cache_age;
    int v5911 = ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5803 = v5802[v5911];
    int v5804 = v5802[v5904];
    int v5912 = v5804 + ((int)((unsigned int)(v5804 - v5803) >> 31));
    v5802[v5904] = v5912;
    int * v5806 = v5789->cache_age;
    int v5807 = v5806[v5905];
    int v5914 = v5807 + ((int)((unsigned int)(v5807 - v5803) >> 31));
    v5806[v5905] = v5914;
    int * v5809 = v5789->cache_age;
    v5809[v5911] = 0;
    v5894 = v5911;
  } else {
    int * v5812 = v5789->cache_age;
    int v5918 = (((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2;
    int v5813 = v5812[v5918];
    int * v5814 = v5789->cache_tags;
    int v5815 = v5814[v5918];
    int v5816 = v5812[v5905];
    int v5817 = v5814[v5905];
    bool v5920 = !(((~(((v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v5871;
    if (v5920) {
      int * v5818 = v5789->cache_age;
      int v5922 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v5819 = v5818[v5922];
      int v5820 = v5818[v5906];
      int v5923 = v5820 + ((int)((unsigned int)(v5820 - v5819) >> 31));
      v5818[v5906] = v5923;
      int * v5822 = v5789->cache_age;
      int v5823 = v5822[v5907];
      int v5925 = v5823 + ((int)((unsigned int)(v5823 - v5819) >> 31));
      v5822[v5907] = v5925;
      int * v5825 = v5789->cache_age;
      v5825[v5922] = 0;
      v5871 = v5922;
    } else {
      int * v5828 = v5789->cache_age;
      int v5929 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2);
      int v5829 = v5828[v5929];
      int * v5830 = v5789->cache_tags;
      int v5831 = v5830[v5929];
      int v5832 = v5828[v5907];
      int v5833 = v5830[v5907];
      int * v5834 = v5789->cache_dirty;
      int v5932 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5829 + ((~(((v5831 ^ -1) | (-(v5831 ^ -1))) >> 31)) & 2)) - (v5832 + ((~(((v5833 ^ -1) | (-(v5833 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5835 = v5834[v5932];
      bool v5933 = !(v5835 == 0);
      if (v5933) {
        int * v5836 = v5789->cache_tags;
        int v5837 = v5836[v5932];
        int * v5838 = v5789->cache_vals;
        int v5936 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5829 + ((~(((v5831 ^ -1) | (-(v5831 ^ -1))) >> 31)) & 2)) - (v5832 + ((~(((v5833 ^ -1) | (-(v5833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5839 = v5838[v5936];
        int v5937 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5829 + ((~(((v5831 ^ -1) | (-(v5831 ^ -1))) >> 31)) & 2)) - (v5832 + ((~(((v5833 ^ -1) | (-(v5833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5840 = v5838[v5937];
        int * v5841 = v5789->mem;
        int v5939 = v5837 * 2;
        v5841[v5939] = v5839;
        int * v5843 = v5789->mem;
        int v5942 = (v5837 * 2) + 1;
        v5843[v5942] = v5840;
        ;
      } else {
        ;
      }
      int * v5848 = v5789->mem;
      int v5947 = ((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) * 2;
      int v5849 = v5848[v5947];
      int v5948 = (((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) * 2) + 1;
      int v5850 = v5848[v5948];
      int * v5851 = v5789->cache_vals;
      int v5950 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5829 + ((~(((v5831 ^ -1) | (-(v5831 ^ -1))) >> 31)) & 2)) - (v5832 + ((~(((v5833 ^ -1) | (-(v5833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5851[v5950] = v5849;
      int * v5853 = v5789->cache_vals;
      int v5953 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5829 + ((~(((v5831 ^ -1) | (-(v5831 ^ -1))) >> 31)) & 2)) - (v5832 + ((~(((v5833 ^ -1) | (-(v5833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5853[v5953] = v5850;
      int * v5855 = v5789->cache_tags;
      int v5956 = (int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1);
      v5855[v5932] = v5956;
      int * v5857 = v5789->cache_dirty;
      v5857[v5932] = 0;
      int * v5859 = v5789->cache_age;
      v5859[v5932] = 1;
      int * v5861 = v5789->cache_age;
      int v5862 = v5861[v5932];
      int v5863 = v5861[v5906];
      int v5962 = v5863 + ((int)((unsigned int)(v5863 - v5862) >> 31));
      v5861[v5906] = v5962;
      int * v5865 = v5789->cache_age;
      int v5866 = v5865[v5907];
      int v5964 = v5866 + ((int)((unsigned int)(v5866 - v5862) >> 31));
      v5865[v5907] = v5964;
      int * v5868 = v5789->cache_age;
      v5868[v5932] = 0;
      v5871 = v5932;
    }
    int * v5872 = v5789->cache_vals;
    int v5967 = v5871 * 2;
    int v5873 = v5872[v5967];
    int v5968 = (v5871 * 2) + 1;
    int v5874 = v5872[v5968];
    int v5969 = (((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5813 + ((~(((v5815 ^ -1) | (-(v5815 ^ -1))) >> 31)) & 2)) - (v5816 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5872[v5969] = v5873;
    int * v5876 = v5789->cache_vals;
    int v5972 = ((((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5813 + ((~(((v5815 ^ -1) | (-(v5815 ^ -1))) >> 31)) & 2)) - (v5816 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5876[v5972] = v5874;
    int * v5878 = v5789->cache_tags;
    int v5975 = ((((int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5813 + ((~(((v5815 ^ -1) | (-(v5815 ^ -1))) >> 31)) & 2)) - (v5816 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5976 = (int)((unsigned int)((int)((unsigned int)(v5793 + 20) >> 2)) >> 1);
    v5878[v5975] = v5976;
    int * v5880 = v5789->cache_dirty;
    v5880[v5975] = 0;
    int * v5882 = v5789->cache_age;
    v5882[v5975] = 1;
    int * v5884 = v5789->cache_age;
    int v5885 = v5884[v5975];
    int v5886 = v5884[v5904];
    int v5982 = v5886 + ((int)((unsigned int)(v5886 - v5885) >> 31));
    v5884[v5904] = v5982;
    int * v5888 = v5789->cache_age;
    int v5889 = v5888[v5905];
    int v5984 = v5889 + ((int)((unsigned int)(v5889 - v5885) >> 31));
    v5888[v5905] = v5984;
    int * v5891 = v5789->cache_age;
    v5891[v5975] = 0;
    v5894 = v5975;
  }
  int v5987 = (v5894 * 2) + (((int)((unsigned int)(v5793 + 20) >> 2)) & 1);
  int v5895 = v5801[v5987];
  int * v5896 = v5789->regs;
  v5896[29] = v5895;
  struct StateT * v5898 = slot_82(v5789);
  return v5898;
}

struct StateT * slot_44(struct StateT * v4244) {
  int v4245 = v4244->timer;
  int v4253 = v4245 + 1;
  v4244->timer = v4253;
  int * v4247 = v4244->regs;
  int v4248 = v4247[5];
  int v4249 = v4247[29];
  int v4257 = v4248 | v4249;
  v4247[5] = v4257;
  struct StateT * v4251 = slot_45(v4244);
  return v4251;
}

struct StateT * slot_137(struct StateT * v8541) {
  int v8542 = v8541->timer;
  int v8550 = v8542 + 1;
  v8541->timer = v8550;
  int * v8544 = v8541->regs;
  int v8545 = v8544[6];
  int v8546 = v8544[12];
  int v8554 = v8545 * v8546;
  v8544[6] = v8554;
  struct StateT * v8548 = slot_138(v8541);
  return v8548;
}

struct StateT * slot_122(struct StateT * v8142) {
  int v8143 = v8142->timer;
  int v8150 = v8143 + 1;
  v8142->timer = v8150;
  int * v8145 = v8142->regs;
  int v8146 = v8145[28];
  int v8153 = v8146 << 13;
  v8145[28] = v8153;
  struct StateT * v8148 = slot_123(v8142);
  return v8148;
}

struct StateT * slot_99(struct StateT * v6548) {
  int v6549 = v6548->timer;
  int v6561 = v6549 + 1;
  v6548->timer = v6561;
  int * v6551 = v6548->regs;
  int v6552 = v6551[29];
  int v6553 = v6551[31];
  bool v6565 = (v6552 ^ -2147483648) < (v6553 ^ -2147483648);
  int v6556;
  if (v6565) {
    v6556 = 1;
  } else {
    v6556 = 0;
  }
  int * v6557 = v6548->regs;
  v6557[6] = v6556;
  struct StateT * v6559 = slot_100(v6548);
  return v6559;
}

struct StateT * slot_179(struct StateT * v10614) {
  int v10615 = v10614->timer;
  int v10623 = v10615 + 1;
  v10614->timer = v10623;
  int * v10617 = v10614->regs;
  int v10618 = v10617[6];
  int v10619 = v10617[13];
  int v10628 = (((((int)((unsigned int)v10618 >> 16)) * ((int)((unsigned int)v10619 >> 16))) + ((int)((unsigned int)((v10618 & 65535) * ((int)((unsigned int)v10619 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v10618 >> 16)) * (v10619 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v10618 & 65535) * (v10619 & 65535)) >> 16)) + (((v10618 & 65535) * ((int)((unsigned int)v10619 >> 16))) & 65535)) + ((((int)((unsigned int)v10618 >> 16)) * (v10619 & 65535)) & 65535)) >> 16));
  v10617[31] = v10628;
  struct StateT * v10621 = slot_180(v10614);
  return v10621;
}

struct StateT * slot_219(struct StateT * v11361) {
  int v11362 = v11361->timer;
  int v11370 = v11362 + 1;
  v11361->timer = v11370;
  int * v11364 = v11361->regs;
  int v11365 = v11364[12];
  int v11366 = v11364[14];
  int v11374 = v11365 + v11366;
  v11364[12] = v11374;
  struct StateT * v11368 = slot_220(v11361);
  return v11368;
}

struct StateT * slot_36(struct StateT * v4113) {
  int v4114 = v4113->timer;
  int v4122 = v4114 + 1;
  v4113->timer = v4122;
  int * v4116 = v4113->regs;
  int v4117 = v4116[5];
  int v4118 = v4116[6];
  int v4126 = v4117 + v4118;
  v4116[5] = v4126;
  struct StateT * v4120 = slot_37(v4113);
  return v4120;
}

struct StateT * slot_57(struct StateT * v4482) {
  int v4483 = v4482->timer;
  int v4491 = v4483 + 1;
  v4482->timer = v4491;
  int * v4485 = v4482->regs;
  int v4486 = v4485[30];
  int v4487 = v4485[6];
  int v4495 = v4486 + v4487;
  v4485[6] = v4495;
  struct StateT * v4489 = slot_58(v4482);
  return v4489;
}

struct StateT * slot_62(struct StateT * v4580) {
  int v4581 = v4580->timer;
  int v4589 = v4581 + 1;
  v4580->timer = v4589;
  int * v4583 = v4580->regs;
  int v4584 = v4583[7];
  int v4585 = v4583[28];
  int v4593 = v4584 + v4585;
  v4583[7] = v4593;
  struct StateT * v4587 = slot_63(v4580);
  return v4587;
}

struct StateT * slot_22(struct StateT * v2408) {
  int v2409 = v2408->timer;
  int v2417 = v2409 + 1;
  v2408->timer = v2417;
  int * v2411 = v2408->regs;
  int v2412 = v2411[17];
  int v2413 = v2411[16];
  int v2422 = v2412 & v2413;
  v2411[15] = v2422;
  struct StateT * v2415 = slot_23(v2408);
  return v2415;
}

struct StateT * slot_139(struct StateT * v8574) {
  int v8575 = v8574->timer;
  int v8583 = v8575 + 1;
  v8574->timer = v8583;
  int * v8577 = v8574->regs;
  int v8578 = v8577[6];
  int v8579 = v8577[7];
  int v8588 = v8578 + v8579;
  v8577[17] = v8588;
  struct StateT * v8581 = slot_140(v8574);
  return v8581;
}

struct StateT * slot_221(struct StateT * v11456) {
  int v11457 = v11456->timer;
  int v11465 = v11457 + 1;
  v11456->timer = v11465;
  int * v11459 = v11456->regs;
  int v11460 = v11459[12];
  int v11461 = v11459[5];
  int v11469 = v11460 + v11461;
  v11459[5] = v11469;
  struct StateT * v11463 = slot_223(v11456);
  return v11463;
}

struct StateT * slot_23(struct StateT * v2425) {
  int v2426 = v2425->timer;
  int v2433 = v2426 + 1;
  v2425->timer = v2433;
  int * v2428 = v2425->regs;
  int v2429 = v2428[17];
  int v2436 = (int)((unsigned int)v2429 >> 19);
  v2428[17] = v2436;
  struct StateT * v2431 = slot_24(v2425);
  return v2431;
}

struct StateT * slot_153(struct StateT * v8846) {
  int v8847 = v8846->timer;
  int v8855 = v8847 + 1;
  v8846->timer = v8855;
  int * v8849 = v8846->regs;
  int v8850 = v8849[6];
  int v8851 = v8849[31];
  int v8859 = v8850 + v8851;
  v8849[6] = v8859;
  struct StateT * v8853 = slot_154(v8846);
  return v8853;
}

struct StateT * slot_2(struct StateT * v331) {
  int v332 = v331->timer;
  int v502 = v332 + 1;
  v331->timer = v502;
  int * v334 = v331->regs;
  int v335 = v334[2];
  int v336 = v334[9];
  int * v337 = v331->cache_tags;
  int v507 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v507];
  int v508 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v508];
  int v509 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v509];
  int v510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v510];
  int v342 = v331->timer;
  int v511 = v342 + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v331->timer = v511;
  bool v512 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v436;
  if (v512) {
    int * v344 = v331->cache_age;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v345 = v344[v514];
    int v346 = v344[v507];
    int v515 = v346 + ((int)((unsigned int)(v346 - v345) >> 31));
    v344[v507] = v515;
    int * v348 = v331->cache_age;
    int v349 = v348[v508];
    int v517 = v349 + ((int)((unsigned int)(v349 - v345) >> 31));
    v348[v508] = v517;
    int * v351 = v331->cache_age;
    v351[v514] = 0;
    v436 = v514;
  } else {
    int * v354 = v331->cache_age;
    int v521 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2;
    int v355 = v354[v521];
    int * v356 = v331->cache_tags;
    int v357 = v356[v521];
    int v358 = v354[v508];
    int v359 = v356[v508];
    bool v523 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v413;
    if (v523) {
      int * v360 = v331->cache_age;
      int v525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v361 = v360[v525];
      int v362 = v360[v509];
      int v526 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
      v360[v509] = v526;
      int * v364 = v331->cache_age;
      int v365 = v364[v510];
      int v528 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
      v364[v510] = v528;
      int * v367 = v331->cache_age;
      v367[v525] = 0;
      v413 = v525;
    } else {
      int * v370 = v331->cache_age;
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2);
      int v371 = v370[v532];
      int * v372 = v331->cache_tags;
      int v373 = v372[v532];
      int v374 = v370[v510];
      int v375 = v372[v510];
      int * v376 = v331->cache_dirty;
      int v535 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v377 = v376[v535];
      bool v536 = !(v377 == 0);
      if (v536) {
        int * v378 = v331->cache_tags;
        int v379 = v378[v535];
        int * v380 = v331->cache_vals;
        int v539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v381 = v380[v539];
        int v540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v382 = v380[v540];
        int * v383 = v331->mem;
        int v542 = v379 * 2;
        v383[v542] = v381;
        int * v385 = v331->mem;
        int v545 = (v379 * 2) + 1;
        v385[v545] = v382;
        ;
      } else {
        ;
      }
      int * v390 = v331->mem;
      int v550 = ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2;
      int v391 = v390[v550];
      int v551 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2) + 1;
      int v392 = v390[v551];
      int * v393 = v331->cache_vals;
      int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v393[v553] = v391;
      int * v395 = v331->cache_vals;
      int v556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v395[v556] = v392;
      int * v397 = v331->cache_tags;
      int v559 = (int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1);
      v397[v535] = v559;
      int * v399 = v331->cache_dirty;
      v399[v535] = 0;
      int * v401 = v331->cache_age;
      v401[v535] = 1;
      int * v403 = v331->cache_age;
      int v404 = v403[v535];
      int v405 = v403[v509];
      int v565 = v405 + ((int)((unsigned int)(v405 - v404) >> 31));
      v403[v509] = v565;
      int * v407 = v331->cache_age;
      int v408 = v407[v510];
      int v567 = v408 + ((int)((unsigned int)(v408 - v404) >> 31));
      v407[v510] = v567;
      int * v410 = v331->cache_age;
      v410[v535] = 0;
      v413 = v535;
    }
    int * v414 = v331->cache_vals;
    int v570 = v413 * 2;
    int v415 = v414[v570];
    int v571 = (v413 * 2) + 1;
    int v416 = v414[v571];
    int v572 = (((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v414[v572] = v415;
    int * v418 = v331->cache_vals;
    int v575 = ((((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v418[v575] = v416;
    int * v420 = v331->cache_tags;
    int v578 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v579 = (int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1);
    v420[v578] = v579;
    int * v422 = v331->cache_dirty;
    v422[v578] = 0;
    int * v424 = v331->cache_age;
    v424[v578] = 1;
    int * v426 = v331->cache_age;
    int v427 = v426[v578];
    int v428 = v426[v507];
    int v585 = v428 + ((int)((unsigned int)(v428 - v427) >> 31));
    v426[v507] = v585;
    int * v430 = v331->cache_age;
    int v431 = v430[v508];
    int v587 = v431 + ((int)((unsigned int)(v431 - v427) >> 31));
    v430[v508] = v587;
    int * v433 = v331->cache_age;
    v433[v578] = 0;
    v436 = v578;
  }
  int * v437 = v331->cache_vals;
  int v590 = (v436 * 2) + (((int)((unsigned int)(v335 + 8) >> 2)) & 1);
  v437[v590] = v336;
  int * v439 = v331->cache_tags;
  int v440 = v439[v509];
  int v441 = v439[v510];
  bool v593 = !(((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v495;
  if (v593) {
    int * v442 = v331->cache_age;
    int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v443 = v442[v595];
    int v444 = v442[v509];
    int v596 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[v509] = v596;
    int * v446 = v331->cache_age;
    int v447 = v446[v510];
    int v598 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[v510] = v598;
    int * v449 = v331->cache_age;
    v449[v595] = 0;
    v495 = v595;
  } else {
    int * v452 = v331->cache_age;
    int v602 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2);
    int v453 = v452[v602];
    int * v454 = v331->cache_tags;
    int v455 = v454[v602];
    int v456 = v452[v510];
    int v457 = v454[v510];
    int * v458 = v331->cache_dirty;
    int v605 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v459 = v458[v605];
    bool v606 = !(v459 == 0);
    if (v606) {
      int * v460 = v331->cache_tags;
      int v461 = v460[v605];
      int * v462 = v331->cache_vals;
      int v609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v463 = v462[v609];
      int v610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v464 = v462[v610];
      int * v465 = v331->mem;
      int v612 = v461 * 2;
      v465[v612] = v463;
      int * v467 = v331->mem;
      int v615 = (v461 * 2) + 1;
      v467[v615] = v464;
      ;
    } else {
      ;
    }
    int * v472 = v331->mem;
    int v620 = ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2;
    int v473 = v472[v620];
    int v621 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2) + 1;
    int v474 = v472[v621];
    int * v475 = v331->cache_vals;
    int v623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v475[v623] = v473;
    int * v477 = v331->cache_vals;
    int v626 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v477[v626] = v474;
    int * v479 = v331->cache_tags;
    int v629 = (int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1);
    v479[v605] = v629;
    int * v481 = v331->cache_dirty;
    v481[v605] = 0;
    int * v483 = v331->cache_age;
    v483[v605] = 1;
    int * v485 = v331->cache_age;
    int v486 = v485[v605];
    int v487 = v485[v509];
    int v635 = v487 + ((int)((unsigned int)(v487 - v486) >> 31));
    v485[v509] = v635;
    int * v489 = v331->cache_age;
    int v490 = v489[v510];
    int v637 = v490 + ((int)((unsigned int)(v490 - v486) >> 31));
    v489[v510] = v637;
    int * v492 = v331->cache_age;
    v492[v605] = 0;
    v495 = v605;
  }
  int * v496 = v331->cache_vals;
  int v640 = (v495 * 2) + (((int)((unsigned int)(v335 + 8) >> 2)) & 1);
  v496[v640] = v336;
  int * v498 = v331->cache_dirty;
  v498[v495] = 1;
  struct StateT * v500 = slot_3(v331);
  return v500;
}

struct StateT * slot_86(struct StateT * v6314) {
  int v6315 = v6314->timer;
  int v6323 = v6315 + 1;
  v6314->timer = v6323;
  int * v6317 = v6314->regs;
  int v6318 = v6317[29];
  int v6319 = v6317[12];
  int v6328 = v6318 * v6319;
  v6317[28] = v6328;
  struct StateT * v6321 = slot_87(v6314);
  return v6321;
}

struct StateT * slot_129(struct StateT * v8406) {
  int v8407 = v8406->timer;
  int v8415 = v8407 + 1;
  v8406->timer = v8415;
  int * v8409 = v8406->regs;
  int v8410 = v8409[5];
  int v8411 = v8409[17];
  int v8419 = v8410 | v8411;
  v8409[5] = v8419;
  struct StateT * v8413 = slot_130(v8406);
  return v8413;
}

struct StateT * slot_158(struct StateT * v8942) {
  int * v8943 = v8942->saved_regs;
  int * v8944 = v8942->regs;
  int v8945 = v8944[7];
  v8943[7] = v8945;
  int v8947 = v8942->timer;
  int v8958 = v8947 + 1;
  v8942->timer = v8958;
  int * v8949 = v8942->regs;
  int v8950 = v8949[7];
  int v8960 = (int)((unsigned int)v8950 >> 19);
  v8949[7] = v8960;
  struct StateT * v8952 = slot_159(v8942);
  return v8952;
}

struct StateT * slot_100(struct StateT * v6573) {
  int v6574 = v6573->timer;
  int v6582 = v6574 + 1;
  v6573->timer = v6582;
  int * v6576 = v6573->regs;
  int v6577 = v6576[29];
  int v6578 = v6576[5];
  int v6587 = v6577 + v6578;
  v6576[30] = v6587;
  struct StateT * v6580 = slot_101(v6573);
  return v6580;
}

struct StateT * slot_127(struct StateT * v8156) {
  int v8157 = v8156->timer;
  int v8165 = v8157 + 1;
  v8156->timer = v8165;
  int * v8159 = v8156->regs;
  int v8160 = v8159[7];
  int v8161 = v8159[28];
  int v8169 = v8160 | v8161;
  v8159[7] = v8169;
  struct StateT * v8163 = slot_128(v8156);
  return v8163;
}

struct StateT * slot_217(struct StateT * v11314) {
  int * v11315 = v11314->saved_regs;
  int * v11316 = v11314->regs;
  int v11317 = v11316[14];
  v11315[14] = v11317;
  int v11319 = v11314->timer;
  int v11335 = v11319 + 1;
  v11314->timer = v11335;
  int * v11321 = v11314->regs;
  int v11322 = v11321[13];
  int v11323 = v11321[14];
  bool v11338 = (v11322 ^ -2147483648) < (v11323 ^ -2147483648);
  int v11326;
  if (v11338) {
    v11326 = 1;
  } else {
    v11326 = 0;
  }
  int * v11327 = v11314->regs;
  v11327[14] = v11326;
  struct StateT * v11329 = slot_218(v11314);
  return v11329;
}

struct StateT * slot_13(struct StateT * v2243) {
  int v2244 = v2243->timer;
  int v2252 = v2244 + 1;
  v2243->timer = v2252;
  int * v2246 = v2243->regs;
  int v2247 = v2246[14];
  int v2248 = v2246[13];
  int v2257 = (((((int)((unsigned int)v2247 >> 16)) * ((int)((unsigned int)v2248 >> 16))) + ((int)((unsigned int)((v2247 & 65535) * ((int)((unsigned int)v2248 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2247 >> 16)) * (v2248 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2247 & 65535) * (v2248 & 65535)) >> 16)) + (((v2247 & 65535) * ((int)((unsigned int)v2248 >> 16))) & 65535)) + ((((int)((unsigned int)v2247 >> 16)) * (v2248 & 65535)) & 65535)) >> 16));
  v2246[28] = v2257;
  struct StateT * v2250 = slot_14(v2243);
  return v2250;
}

struct StateT * slot_111(struct StateT * v6777) {
  int v6778 = v6777->timer;
  int v6786 = v6778 + 1;
  v6777->timer = v6786;
  int * v6780 = v6777->regs;
  int v6781 = v6780[5];
  int v6782 = v6780[28];
  int v6790 = v6781 + v6782;
  v6780[28] = v6790;
  struct StateT * v6784 = slot_112(v6777);
  return v6784;
}

struct StateT * slot_109(struct StateT * v6737) {
  int v6738 = v6737->timer;
  int v6742 = v6738 + 1;
  v6737->timer = v6742;
  struct StateT * v6740 = slot_110(v6737);
  return v6740;
}

struct StateT * slot_174(struct StateT * v10530) {
  int v10531 = v10530->timer;
  int v10539 = v10531 + 1;
  v10530->timer = v10539;
  int * v10533 = v10530->regs;
  int v10534 = v10533[5];
  int v10535 = v10533[17];
  int v10543 = v10534 | v10535;
  v10533[17] = v10543;
  struct StateT * v10537 = slot_175(v10530);
  return v10537;
}

struct StateT * slot_147(struct StateT * v8731) {
  int v8732 = v8731->timer;
  int v8740 = v8732 + 1;
  v8731->timer = v8740;
  int * v8734 = v8731->regs;
  int v8735 = v8734[7];
  int v8736 = v8734[6];
  int v8744 = v8735 + v8736;
  v8734[6] = v8744;
  struct StateT * v8738 = slot_148(v8731);
  return v8738;
}

struct StateT * slot_42(struct StateT * v4213) {
  int v4214 = v4213->timer;
  int v4222 = v4214 + 1;
  v4213->timer = v4222;
  int * v4216 = v4213->regs;
  int v4217 = v4216[7];
  int v4218 = v4216[13];
  int v4227 = (((((int)((unsigned int)v4217 >> 16)) * ((int)((unsigned int)v4218 >> 16))) + ((int)((unsigned int)((v4217 & 65535) * ((int)((unsigned int)v4218 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4217 >> 16)) * (v4218 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4217 & 65535) * (v4218 & 65535)) >> 16)) + (((v4217 & 65535) * ((int)((unsigned int)v4218 >> 16))) & 65535)) + ((((int)((unsigned int)v4217 >> 16)) * (v4218 & 65535)) & 65535)) >> 16));
  v4216[9] = v4227;
  struct StateT * v4220 = slot_43(v4213);
  return v4220;
}

struct StateT * slot_224(struct StateT * v11803) {
  int v11804 = v11803->timer;
  int v11974 = v11804 + 1;
  v11803->timer = v11974;
  int * v11806 = v11803->regs;
  int v11807 = v11806[10];
  int v11808 = v11806[12];
  int * v11809 = v11803->cache_tags;
  int v11979 = (((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2;
  int v11810 = v11809[v11979];
  int v11980 = ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11811 = v11809[v11980];
  int v11981 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2);
  int v11812 = v11809[v11981];
  int v11982 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11813 = v11809[v11982];
  int v11814 = v11803->timer;
  int v11983 = v11814 + ((100 ^ (((~(((v11812 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11812 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11810 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11810 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11811 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11811 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11812 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11812 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11803->timer = v11983;
  bool v11984 = !(((~(((v11810 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11810 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11811 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11811 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v11908;
  if (v11984) {
    int * v11816 = v11803->cache_age;
    int v11986 = ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v11811 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11811 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v11817 = v11816[v11986];
    int v11818 = v11816[v11979];
    int v11987 = v11818 + ((int)((unsigned int)(v11818 - v11817) >> 31));
    v11816[v11979] = v11987;
    int * v11820 = v11803->cache_age;
    int v11821 = v11820[v11980];
    int v11989 = v11821 + ((int)((unsigned int)(v11821 - v11817) >> 31));
    v11820[v11980] = v11989;
    int * v11823 = v11803->cache_age;
    v11823[v11986] = 0;
    v11908 = v11986;
  } else {
    int * v11826 = v11803->cache_age;
    int v11993 = (((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2;
    int v11827 = v11826[v11993];
    int * v11828 = v11803->cache_tags;
    int v11829 = v11828[v11993];
    int v11830 = v11826[v11980];
    int v11831 = v11828[v11980];
    bool v11995 = !(((~(((v11812 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11812 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v11885;
    if (v11995) {
      int * v11832 = v11803->cache_age;
      int v11997 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11813 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v11833 = v11832[v11997];
      int v11834 = v11832[v11981];
      int v11998 = v11834 + ((int)((unsigned int)(v11834 - v11833) >> 31));
      v11832[v11981] = v11998;
      int * v11836 = v11803->cache_age;
      int v11837 = v11836[v11982];
      int v12000 = v11837 + ((int)((unsigned int)(v11837 - v11833) >> 31));
      v11836[v11982] = v12000;
      int * v11839 = v11803->cache_age;
      v11839[v11997] = 0;
      v11885 = v11997;
    } else {
      int * v11842 = v11803->cache_age;
      int v12004 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2);
      int v11843 = v11842[v12004];
      int * v11844 = v11803->cache_tags;
      int v11845 = v11844[v12004];
      int v11846 = v11842[v11982];
      int v11847 = v11844[v11982];
      int * v11848 = v11803->cache_dirty;
      int v12007 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11843 + ((~(((v11845 ^ -1) | (-(v11845 ^ -1))) >> 31)) & 2)) - (v11846 + ((~(((v11847 ^ -1) | (-(v11847 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11849 = v11848[v12007];
      bool v12008 = !(v11849 == 0);
      if (v12008) {
        int * v11850 = v11803->cache_tags;
        int v11851 = v11850[v12007];
        int * v11852 = v11803->cache_vals;
        int v12011 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11843 + ((~(((v11845 ^ -1) | (-(v11845 ^ -1))) >> 31)) & 2)) - (v11846 + ((~(((v11847 ^ -1) | (-(v11847 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11853 = v11852[v12011];
        int v12012 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11843 + ((~(((v11845 ^ -1) | (-(v11845 ^ -1))) >> 31)) & 2)) - (v11846 + ((~(((v11847 ^ -1) | (-(v11847 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11854 = v11852[v12012];
        int * v11855 = v11803->mem;
        int v12014 = v11851 * 2;
        v11855[v12014] = v11853;
        int * v11857 = v11803->mem;
        int v12017 = (v11851 * 2) + 1;
        v11857[v12017] = v11854;
        ;
      } else {
        ;
      }
      int * v11862 = v11803->mem;
      int v12022 = ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) * 2;
      int v11863 = v11862[v12022];
      int v12023 = (((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) * 2) + 1;
      int v11864 = v11862[v12023];
      int * v11865 = v11803->cache_vals;
      int v12025 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11843 + ((~(((v11845 ^ -1) | (-(v11845 ^ -1))) >> 31)) & 2)) - (v11846 + ((~(((v11847 ^ -1) | (-(v11847 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11865[v12025] = v11863;
      int * v11867 = v11803->cache_vals;
      int v12028 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11843 + ((~(((v11845 ^ -1) | (-(v11845 ^ -1))) >> 31)) & 2)) - (v11846 + ((~(((v11847 ^ -1) | (-(v11847 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11867[v12028] = v11864;
      int * v11869 = v11803->cache_tags;
      int v12031 = (int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1);
      v11869[v12007] = v12031;
      int * v11871 = v11803->cache_dirty;
      v11871[v12007] = 0;
      int * v11873 = v11803->cache_age;
      v11873[v12007] = 1;
      int * v11875 = v11803->cache_age;
      int v11876 = v11875[v12007];
      int v11877 = v11875[v11981];
      int v12037 = v11877 + ((int)((unsigned int)(v11877 - v11876) >> 31));
      v11875[v11981] = v12037;
      int * v11879 = v11803->cache_age;
      int v11880 = v11879[v11982];
      int v12039 = v11880 + ((int)((unsigned int)(v11880 - v11876) >> 31));
      v11879[v11982] = v12039;
      int * v11882 = v11803->cache_age;
      v11882[v12007] = 0;
      v11885 = v12007;
    }
    int * v11886 = v11803->cache_vals;
    int v12042 = v11885 * 2;
    int v11887 = v11886[v12042];
    int v12043 = (v11885 * 2) + 1;
    int v11888 = v11886[v12043];
    int v12044 = (((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v11827 + ((~(((v11829 ^ -1) | (-(v11829 ^ -1))) >> 31)) & 2)) - (v11830 + ((~(((v11831 ^ -1) | (-(v11831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11886[v12044] = v11887;
    int * v11890 = v11803->cache_vals;
    int v12047 = ((((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v11827 + ((~(((v11829 ^ -1) | (-(v11829 ^ -1))) >> 31)) & 2)) - (v11830 + ((~(((v11831 ^ -1) | (-(v11831 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11890[v12047] = v11888;
    int * v11892 = v11803->cache_tags;
    int v12050 = ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v11827 + ((~(((v11829 ^ -1) | (-(v11829 ^ -1))) >> 31)) & 2)) - (v11830 + ((~(((v11831 ^ -1) | (-(v11831 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12051 = (int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1);
    v11892[v12050] = v12051;
    int * v11894 = v11803->cache_dirty;
    v11894[v12050] = 0;
    int * v11896 = v11803->cache_age;
    v11896[v12050] = 1;
    int * v11898 = v11803->cache_age;
    int v11899 = v11898[v12050];
    int v11900 = v11898[v11979];
    int v12057 = v11900 + ((int)((unsigned int)(v11900 - v11899) >> 31));
    v11898[v11979] = v12057;
    int * v11902 = v11803->cache_age;
    int v11903 = v11902[v11980];
    int v12059 = v11903 + ((int)((unsigned int)(v11903 - v11899) >> 31));
    v11902[v11980] = v12059;
    int * v11905 = v11803->cache_age;
    v11905[v12050] = 0;
    v11908 = v12050;
  }
  int * v11909 = v11803->cache_vals;
  int v12062 = (v11908 * 2) + (((int)((unsigned int)(v11807 + 4) >> 2)) & 1);
  v11909[v12062] = v11808;
  int * v11911 = v11803->cache_tags;
  int v11912 = v11911[v11981];
  int v11913 = v11911[v11982];
  bool v12065 = !(((~(((v11912 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11912 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v11967;
  if (v12065) {
    int * v11914 = v11803->cache_age;
    int v12067 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))) | (-(v11913 ^ ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v11915 = v11914[v12067];
    int v11916 = v11914[v11981];
    int v12068 = v11916 + ((int)((unsigned int)(v11916 - v11915) >> 31));
    v11914[v11981] = v12068;
    int * v11918 = v11803->cache_age;
    int v11919 = v11918[v11982];
    int v12070 = v11919 + ((int)((unsigned int)(v11919 - v11915) >> 31));
    v11918[v11982] = v12070;
    int * v11921 = v11803->cache_age;
    v11921[v12067] = 0;
    v11967 = v12067;
  } else {
    int * v11924 = v11803->cache_age;
    int v12074 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2);
    int v11925 = v11924[v12074];
    int * v11926 = v11803->cache_tags;
    int v11927 = v11926[v12074];
    int v11928 = v11924[v11982];
    int v11929 = v11926[v11982];
    int * v11930 = v11803->cache_dirty;
    int v12077 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11925 + ((~(((v11927 ^ -1) | (-(v11927 ^ -1))) >> 31)) & 2)) - (v11928 + ((~(((v11929 ^ -1) | (-(v11929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11931 = v11930[v12077];
    bool v12078 = !(v11931 == 0);
    if (v12078) {
      int * v11932 = v11803->cache_tags;
      int v11933 = v11932[v12077];
      int * v11934 = v11803->cache_vals;
      int v12081 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11925 + ((~(((v11927 ^ -1) | (-(v11927 ^ -1))) >> 31)) & 2)) - (v11928 + ((~(((v11929 ^ -1) | (-(v11929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11935 = v11934[v12081];
      int v12082 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11925 + ((~(((v11927 ^ -1) | (-(v11927 ^ -1))) >> 31)) & 2)) - (v11928 + ((~(((v11929 ^ -1) | (-(v11929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11936 = v11934[v12082];
      int * v11937 = v11803->mem;
      int v12084 = v11933 * 2;
      v11937[v12084] = v11935;
      int * v11939 = v11803->mem;
      int v12087 = (v11933 * 2) + 1;
      v11939[v12087] = v11936;
      ;
    } else {
      ;
    }
    int * v11944 = v11803->mem;
    int v12092 = ((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) * 2;
    int v11945 = v11944[v12092];
    int v12093 = (((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) * 2) + 1;
    int v11946 = v11944[v12093];
    int * v11947 = v11803->cache_vals;
    int v12095 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11925 + ((~(((v11927 ^ -1) | (-(v11927 ^ -1))) >> 31)) & 2)) - (v11928 + ((~(((v11929 ^ -1) | (-(v11929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11947[v12095] = v11945;
    int * v11949 = v11803->cache_vals;
    int v12098 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11925 + ((~(((v11927 ^ -1) | (-(v11927 ^ -1))) >> 31)) & 2)) - (v11928 + ((~(((v11929 ^ -1) | (-(v11929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11949[v12098] = v11946;
    int * v11951 = v11803->cache_tags;
    int v12101 = (int)((unsigned int)((int)((unsigned int)(v11807 + 4) >> 2)) >> 1);
    v11951[v12077] = v12101;
    int * v11953 = v11803->cache_dirty;
    v11953[v12077] = 0;
    int * v11955 = v11803->cache_age;
    v11955[v12077] = 1;
    int * v11957 = v11803->cache_age;
    int v11958 = v11957[v12077];
    int v11959 = v11957[v11981];
    int v12107 = v11959 + ((int)((unsigned int)(v11959 - v11958) >> 31));
    v11957[v11981] = v12107;
    int * v11961 = v11803->cache_age;
    int v11962 = v11961[v11982];
    int v12109 = v11962 + ((int)((unsigned int)(v11962 - v11958) >> 31));
    v11961[v11982] = v12109;
    int * v11964 = v11803->cache_age;
    v11964[v12077] = 0;
    v11967 = v12077;
  }
  int * v11968 = v11803->cache_vals;
  int v12112 = (v11967 * 2) + (((int)((unsigned int)(v11807 + 4) >> 2)) & 1);
  v11968[v12112] = v11808;
  int * v11970 = v11803->cache_dirty;
  v11970[v11967] = 1;
  struct StateT * v11972 = slot_226(v11803);
  return v11972;
}

struct StateT * slot_163(struct StateT * v9377) {
  int v9378 = v9377->timer;
  int v9386 = v9378 + 1;
  v9377->timer = v9386;
  int * v9380 = v9377->regs;
  int v9381 = v9380[7];
  int v9382 = v9380[16];
  int v9391 = v9381 & v9382;
  v9380[29] = v9391;
  struct StateT * v9384 = slot_165(v9377);
  return v9384;
}

struct StateT * slot_184(struct StateT * v10696) {
  int v10697 = v10696->timer;
  int v10705 = v10697 + 1;
  v10696->timer = v10705;
  int * v10699 = v10696->regs;
  int v10700 = v10699[12];
  int v10701 = v10699[7];
  int v10710 = v10700 + v10701;
  v10699[11] = v10710;
  struct StateT * v10703 = slot_185(v10696);
  return v10703;
}

struct StateT * slot_204(struct StateT * v11084) {
  int * v11085 = v11084->saved_regs;
  int * v11086 = v11084->regs;
  int v11087 = v11086[12];
  v11085[12] = v11087;
  int v11089 = v11084->timer;
  int v11105 = v11089 + 1;
  v11084->timer = v11105;
  int * v11091 = v11084->regs;
  int v11092 = v11091[5];
  int v11093 = v11091[12];
  bool v11108 = (v11092 ^ -2147483648) < (v11093 ^ -2147483648);
  int v11096;
  if (v11108) {
    v11096 = 1;
  } else {
    v11096 = 0;
  }
  int * v11097 = v11084->regs;
  v11097[12] = v11096;
  struct StateT * v11099 = slot_205(v11084);
  return v11099;
}

struct StateT * slot_194(struct StateT * v10887) {
  int v10888 = v10887->timer;
  int v10900 = v10888 + 1;
  v10887->timer = v10900;
  int * v10890 = v10887->regs;
  int v10891 = v10890[28];
  int v10892 = v10890[7];
  bool v10904 = (v10891 ^ -2147483648) < (v10892 ^ -2147483648);
  int v10895;
  if (v10904) {
    v10895 = 1;
  } else {
    v10895 = 0;
  }
  int * v10896 = v10887->regs;
  v10896[7] = v10895;
  struct StateT * v10898 = slot_195(v10887);
  return v10898;
}

struct StateT * slot_165(struct StateT * v10010) {
  int v10011 = v10010->timer;
  int v10018 = v10011 + 1;
  v10010->timer = v10018;
  int * v10013 = v10010->regs;
  int v10014 = v10013[7];
  int v10021 = (int)((unsigned int)v10014 >> 19);
  v10013[7] = v10021;
  struct StateT * v10016 = slot_171(v10010);
  return v10016;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v14722) {
  int v14723 = v14722->timer;
  int v14731 = v14723 + 1;
  v14722->timer = v14731;
  int * v14725 = v14722->regs;
  int v14726 = v14725[12];
  int v14727 = v14725[14];
  int v14735 = v14726 + v14727;
  v14725[12] = v14735;
  struct StateT * v14729 = slot_222(v14722);
  return v14729;
}

struct StateT * slot_117(struct StateT * v6937) {
  int v6938 = v6937->timer;
  int v7108 = v6938 + 1;
  v6937->timer = v7108;
  int * v6940 = v6937->regs;
  int v6941 = v6940[10];
  int v6942 = v6940[17];
  int * v6943 = v6937->cache_tags;
  int v7113 = (((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2;
  int v6944 = v6943[v7113];
  int v7114 = ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6945 = v6943[v7114];
  int v7115 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2);
  int v6946 = v6943[v7115];
  int v7116 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6947 = v6943[v7116];
  int v6948 = v6937->timer;
  int v7117 = v6948 + ((100 ^ (((~(((v6946 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6946 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6944 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6944 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6945 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6945 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6946 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6946 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6937->timer = v7117;
  bool v7118 = !(((~(((v6944 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6944 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6945 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6945 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v7042;
  if (v7118) {
    int * v6950 = v6937->cache_age;
    int v7120 = ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v6945 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6945 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v6951 = v6950[v7120];
    int v6952 = v6950[v7113];
    int v7121 = v6952 + ((int)((unsigned int)(v6952 - v6951) >> 31));
    v6950[v7113] = v7121;
    int * v6954 = v6937->cache_age;
    int v6955 = v6954[v7114];
    int v7123 = v6955 + ((int)((unsigned int)(v6955 - v6951) >> 31));
    v6954[v7114] = v7123;
    int * v6957 = v6937->cache_age;
    v6957[v7120] = 0;
    v7042 = v7120;
  } else {
    int * v6960 = v6937->cache_age;
    int v7127 = (((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2;
    int v6961 = v6960[v7127];
    int * v6962 = v6937->cache_tags;
    int v6963 = v6962[v7127];
    int v6964 = v6960[v7114];
    int v6965 = v6962[v7114];
    bool v7129 = !(((~(((v6946 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6946 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v7019;
    if (v7129) {
      int * v6966 = v6937->cache_age;
      int v7131 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v6947 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v6967 = v6966[v7131];
      int v6968 = v6966[v7115];
      int v7132 = v6968 + ((int)((unsigned int)(v6968 - v6967) >> 31));
      v6966[v7115] = v7132;
      int * v6970 = v6937->cache_age;
      int v6971 = v6970[v7116];
      int v7134 = v6971 + ((int)((unsigned int)(v6971 - v6967) >> 31));
      v6970[v7116] = v7134;
      int * v6973 = v6937->cache_age;
      v6973[v7131] = 0;
      v7019 = v7131;
    } else {
      int * v6976 = v6937->cache_age;
      int v7138 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2);
      int v6977 = v6976[v7138];
      int * v6978 = v6937->cache_tags;
      int v6979 = v6978[v7138];
      int v6980 = v6976[v7116];
      int v6981 = v6978[v7116];
      int * v6982 = v6937->cache_dirty;
      int v7141 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6977 + ((~(((v6979 ^ -1) | (-(v6979 ^ -1))) >> 31)) & 2)) - (v6980 + ((~(((v6981 ^ -1) | (-(v6981 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6983 = v6982[v7141];
      bool v7142 = !(v6983 == 0);
      if (v7142) {
        int * v6984 = v6937->cache_tags;
        int v6985 = v6984[v7141];
        int * v6986 = v6937->cache_vals;
        int v7145 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6977 + ((~(((v6979 ^ -1) | (-(v6979 ^ -1))) >> 31)) & 2)) - (v6980 + ((~(((v6981 ^ -1) | (-(v6981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6987 = v6986[v7145];
        int v7146 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6977 + ((~(((v6979 ^ -1) | (-(v6979 ^ -1))) >> 31)) & 2)) - (v6980 + ((~(((v6981 ^ -1) | (-(v6981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6988 = v6986[v7146];
        int * v6989 = v6937->mem;
        int v7148 = v6985 * 2;
        v6989[v7148] = v6987;
        int * v6991 = v6937->mem;
        int v7151 = (v6985 * 2) + 1;
        v6991[v7151] = v6988;
        ;
      } else {
        ;
      }
      int * v6996 = v6937->mem;
      int v7156 = ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) * 2;
      int v6997 = v6996[v7156];
      int v7157 = (((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) * 2) + 1;
      int v6998 = v6996[v7157];
      int * v6999 = v6937->cache_vals;
      int v7159 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6977 + ((~(((v6979 ^ -1) | (-(v6979 ^ -1))) >> 31)) & 2)) - (v6980 + ((~(((v6981 ^ -1) | (-(v6981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6999[v7159] = v6997;
      int * v7001 = v6937->cache_vals;
      int v7162 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6977 + ((~(((v6979 ^ -1) | (-(v6979 ^ -1))) >> 31)) & 2)) - (v6980 + ((~(((v6981 ^ -1) | (-(v6981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7001[v7162] = v6998;
      int * v7003 = v6937->cache_tags;
      int v7165 = (int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1);
      v7003[v7141] = v7165;
      int * v7005 = v6937->cache_dirty;
      v7005[v7141] = 0;
      int * v7007 = v6937->cache_age;
      v7007[v7141] = 1;
      int * v7009 = v6937->cache_age;
      int v7010 = v7009[v7141];
      int v7011 = v7009[v7115];
      int v7171 = v7011 + ((int)((unsigned int)(v7011 - v7010) >> 31));
      v7009[v7115] = v7171;
      int * v7013 = v6937->cache_age;
      int v7014 = v7013[v7116];
      int v7173 = v7014 + ((int)((unsigned int)(v7014 - v7010) >> 31));
      v7013[v7116] = v7173;
      int * v7016 = v6937->cache_age;
      v7016[v7141] = 0;
      v7019 = v7141;
    }
    int * v7020 = v6937->cache_vals;
    int v7176 = v7019 * 2;
    int v7021 = v7020[v7176];
    int v7177 = (v7019 * 2) + 1;
    int v7022 = v7020[v7177];
    int v7178 = (((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6961 + ((~(((v6963 ^ -1) | (-(v6963 ^ -1))) >> 31)) & 2)) - (v6964 + ((~(((v6965 ^ -1) | (-(v6965 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7020[v7178] = v7021;
    int * v7024 = v6937->cache_vals;
    int v7181 = ((((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6961 + ((~(((v6963 ^ -1) | (-(v6963 ^ -1))) >> 31)) & 2)) - (v6964 + ((~(((v6965 ^ -1) | (-(v6965 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7024[v7181] = v7022;
    int * v7026 = v6937->cache_tags;
    int v7184 = ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6961 + ((~(((v6963 ^ -1) | (-(v6963 ^ -1))) >> 31)) & 2)) - (v6964 + ((~(((v6965 ^ -1) | (-(v6965 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7185 = (int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1);
    v7026[v7184] = v7185;
    int * v7028 = v6937->cache_dirty;
    v7028[v7184] = 0;
    int * v7030 = v6937->cache_age;
    v7030[v7184] = 1;
    int * v7032 = v6937->cache_age;
    int v7033 = v7032[v7184];
    int v7034 = v7032[v7113];
    int v7191 = v7034 + ((int)((unsigned int)(v7034 - v7033) >> 31));
    v7032[v7113] = v7191;
    int * v7036 = v6937->cache_age;
    int v7037 = v7036[v7114];
    int v7193 = v7037 + ((int)((unsigned int)(v7037 - v7033) >> 31));
    v7036[v7114] = v7193;
    int * v7039 = v6937->cache_age;
    v7039[v7184] = 0;
    v7042 = v7184;
  }
  int * v7043 = v6937->cache_vals;
  int v7196 = (v7042 * 2) + (((int)((unsigned int)(v6941 + 16) >> 2)) & 1);
  v7043[v7196] = v6942;
  int * v7045 = v6937->cache_tags;
  int v7046 = v7045[v7115];
  int v7047 = v7045[v7116];
  bool v7199 = !(((~(((v7046 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v7046 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7047 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v7047 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v7101;
  if (v7199) {
    int * v7048 = v6937->cache_age;
    int v7201 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7047 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))) | (-(v7047 ^ ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v7049 = v7048[v7201];
    int v7050 = v7048[v7115];
    int v7202 = v7050 + ((int)((unsigned int)(v7050 - v7049) >> 31));
    v7048[v7115] = v7202;
    int * v7052 = v6937->cache_age;
    int v7053 = v7052[v7116];
    int v7204 = v7053 + ((int)((unsigned int)(v7053 - v7049) >> 31));
    v7052[v7116] = v7204;
    int * v7055 = v6937->cache_age;
    v7055[v7201] = 0;
    v7101 = v7201;
  } else {
    int * v7058 = v6937->cache_age;
    int v7208 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2);
    int v7059 = v7058[v7208];
    int * v7060 = v6937->cache_tags;
    int v7061 = v7060[v7208];
    int v7062 = v7058[v7116];
    int v7063 = v7060[v7116];
    int * v7064 = v6937->cache_dirty;
    int v7211 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7059 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2)) - (v7062 + ((~(((v7063 ^ -1) | (-(v7063 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7065 = v7064[v7211];
    bool v7212 = !(v7065 == 0);
    if (v7212) {
      int * v7066 = v6937->cache_tags;
      int v7067 = v7066[v7211];
      int * v7068 = v6937->cache_vals;
      int v7215 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7059 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2)) - (v7062 + ((~(((v7063 ^ -1) | (-(v7063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7069 = v7068[v7215];
      int v7216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7059 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2)) - (v7062 + ((~(((v7063 ^ -1) | (-(v7063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7070 = v7068[v7216];
      int * v7071 = v6937->mem;
      int v7218 = v7067 * 2;
      v7071[v7218] = v7069;
      int * v7073 = v6937->mem;
      int v7221 = (v7067 * 2) + 1;
      v7073[v7221] = v7070;
      ;
    } else {
      ;
    }
    int * v7078 = v6937->mem;
    int v7226 = ((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) * 2;
    int v7079 = v7078[v7226];
    int v7227 = (((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) * 2) + 1;
    int v7080 = v7078[v7227];
    int * v7081 = v6937->cache_vals;
    int v7229 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7059 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2)) - (v7062 + ((~(((v7063 ^ -1) | (-(v7063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7081[v7229] = v7079;
    int * v7083 = v6937->cache_vals;
    int v7232 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7059 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2)) - (v7062 + ((~(((v7063 ^ -1) | (-(v7063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7083[v7232] = v7080;
    int * v7085 = v6937->cache_tags;
    int v7235 = (int)((unsigned int)((int)((unsigned int)(v6941 + 16) >> 2)) >> 1);
    v7085[v7211] = v7235;
    int * v7087 = v6937->cache_dirty;
    v7087[v7211] = 0;
    int * v7089 = v6937->cache_age;
    v7089[v7211] = 1;
    int * v7091 = v6937->cache_age;
    int v7092 = v7091[v7211];
    int v7093 = v7091[v7115];
    int v7241 = v7093 + ((int)((unsigned int)(v7093 - v7092) >> 31));
    v7091[v7115] = v7241;
    int * v7095 = v6937->cache_age;
    int v7096 = v7095[v7116];
    int v7243 = v7096 + ((int)((unsigned int)(v7096 - v7092) >> 31));
    v7095[v7116] = v7243;
    int * v7098 = v6937->cache_age;
    v7098[v7211] = 0;
    v7101 = v7211;
  }
  int * v7102 = v6937->cache_vals;
  int v7246 = (v7101 * 2) + (((int)((unsigned int)(v6941 + 16) >> 2)) & 1);
  v7102[v7246] = v6942;
  int * v7104 = v6937->cache_dirty;
  v7104[v7101] = 1;
  struct StateT * v7106 = slot_119(v6937);
  return v7106;
}

struct StateT * slot_249(struct StateT * v14706) {
  int v14707 = v14706->timer;
  int v14715 = v14707 + 1;
  v14706->timer = v14715;
  int * v14709 = v14706->regs;
  int v14710 = v14709[15];
  int v14711 = v14709[12];
  int v14719 = v14710 + v14711;
  v14709[12] = v14719;
  struct StateT * v14713 = slot_250(v14706);
  return v14713;
}

struct StateT * slot_90(struct StateT * v6382) {
  int v6383 = v6382->timer;
  int v6391 = v6383 + 1;
  v6382->timer = v6391;
  int * v6385 = v6382->regs;
  int v6386 = v6385[29];
  int v6387 = v6385[13];
  int v6396 = v6386 * v6387;
  v6385[9] = v6396;
  struct StateT * v6389 = slot_91(v6382);
  return v6389;
}

struct StateT * slot_11(struct StateT * v2195) {
  int v2196 = v2195->timer;
  int v2204 = v2196 + 1;
  v2195->timer = v2204;
  int * v2198 = v2195->regs;
  int v2199 = v2198[15];
  int v2200 = v2198[12];
  int v2209 = (((((int)((unsigned int)v2199 >> 16)) * ((int)((unsigned int)v2200 >> 16))) + ((int)((unsigned int)((v2199 & 65535) * ((int)((unsigned int)v2200 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2199 >> 16)) * (v2200 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2199 & 65535) * (v2200 & 65535)) >> 16)) + (((v2199 & 65535) * ((int)((unsigned int)v2200 >> 16))) & 65535)) + ((((int)((unsigned int)v2199 >> 16)) * (v2200 & 65535)) & 65535)) >> 16));
  v2198[6] = v2209;
  struct StateT * v2202 = slot_12(v2195);
  return v2202;
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
  
  // a10, 10 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 2147483647);
    s2.mem[10 + i] = secret(0, 2147483647);
  }
  // a12 and a13, secret: a uint64's halves, drawn separately
  // in each state
  s1.regs[12] = secret(0, 2147483647);
  s2.regs[12] = secret(0, 2147483647);
  s1.regs[13] = secret(0, 2147483647);
  s2.regs[13] = secret(0, 2147483647);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}