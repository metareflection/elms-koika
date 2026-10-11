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

struct StateT * slot_12(struct StateT * v1762);
struct StateT * slot_228(struct StateT * v10611);
struct StateT * slot_143(struct StateT * v7098);
struct StateT * slot_120(struct StateT * v6326);
struct StateT * slot_226(struct StateT * v10272);
struct StateT * slot_167(struct StateT * v8179);
struct StateT * slot_152(struct StateT * v7270);
struct StateT * slot_231(struct StateT * v11146);
struct StateT * slot_199(struct StateT * v9124);
struct StateT * slot_92(struct StateT * v5158);
struct StateT * slot_232(struct StateT * v11161);
struct StateT * slot_31(struct StateT * v3062);
struct StateT * slot_236(struct StateT * v11598);
struct StateT * slot_241(struct StateT * v11849);
struct StateT * slot_160(struct StateT * v7435);
struct StateT * slot_65(struct StateT * v3663);
struct StateT * slot_10(struct StateT * v1728);
struct StateT * slot_150(struct StateT * v7229);
struct StateT * slot_74(struct StateT * v4187);
struct StateT * slot_107(struct StateT * v5446);
struct StateT * slot_136(struct StateT * v6965);
struct StateT * slot_84(struct StateT * v5023);
struct StateT * slot_28(struct StateT * v2637);
struct StateT * slot_155(struct StateT * v7311);
struct StateT * slot_177(struct StateT * v8720);
struct StateT * slot_229(struct StateT * v10926);
struct StateT * slot_17(struct StateT * v1846);
struct StateT * slot_181(struct StateT * v8788);
struct StateT * slot_197(struct StateT * v9092);
struct StateT * slot_207(struct StateT * v9293);
struct StateT * slot_156(struct StateT * v7343);
struct StateT * slot_154(struct StateT * v7303);
struct StateT * slot_68(struct StateT * v3735);
struct StateT * slot_105(struct StateT * v5405);
struct StateT * slot_27(struct StateT * v2621);
struct StateT * slot_164(struct StateT * v7835);
struct StateT * slot_15(struct StateT * v1813);
struct StateT * slot_133(struct StateT * v6914);
struct StateT * slot_56(struct StateT * v3509);
struct StateT * slot_244(struct StateT * v11882);
struct StateT * slot_222(struct StateT * v9612);
struct StateT * slot_34(struct StateT * v3127);
struct StateT * slot_171(struct StateT * v8437);
struct StateT * slot_162(struct StateT * v7503);
struct StateT * slot_21(struct StateT * v1919);
struct StateT * slot_239(struct StateT * v11830);
struct StateT * slot_118(struct StateT * v5994);
struct StateT * slot_121(struct StateT * v6340);
struct StateT * slot_144(struct StateT * v7114);
struct StateT * slot_201(struct StateT * v9164);
struct StateT * slot_94(struct StateT * v5191);
struct StateT * slot_63(struct StateT * v3639);
struct StateT * slot_146(struct StateT * v7156);
struct StateT * slot_24(struct StateT * v1975);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v9051);
struct StateT * slot_125(struct StateT * v6409);
struct StateT * slot_148(struct StateT * v7188);
struct StateT * slot_126(struct StateT * v6613);
struct StateT * slot_223(struct StateT * v9927);
struct StateT * slot_79(struct StateT * v4569);
struct StateT * slot_237(struct StateT * v11802);
struct StateT * slot_41(struct StateT * v3239);
struct StateT * slot_39(struct StateT * v3205);
struct StateT * slot_142(struct StateT * v7073);
struct StateT * slot_60(struct StateT * v3582);
struct StateT * slot_238(struct StateT * v11816);
struct StateT * slot_112(struct StateT * v5535);
struct StateT * slot_47(struct StateT * v3337);
struct StateT * slot_214(struct StateT * v9399);
struct StateT * slot_29(struct StateT * v2841);
struct StateT * slot_16(struct StateT * v1830);
struct StateT * slot_245(struct StateT * v11898);
struct StateT * slot_113(struct StateT * v5559);
struct StateT * slot_151(struct StateT * v7254);
struct StateT * slot_7(struct StateT * v1684);
struct StateT * slot_124(struct StateT * v6393);
struct StateT * slot_191(struct StateT * v8977);
struct StateT * slot_103(struct StateT * v5364);
struct StateT * slot_128(struct StateT * v6833);
struct StateT * slot_19(struct StateT * v1887);
struct StateT * slot_87(struct StateT * v5073);
struct StateT * slot_67(struct StateT * v3711);
struct StateT * slot_81(struct StateT * v4789);
struct StateT * slot_95(struct StateT * v5208);
struct StateT * slot_115(struct StateT * v5611);
struct StateT * slot_78(struct StateT * v4555);
struct StateT * slot_32(struct StateT * v3086);
struct StateT * slot_205(struct StateT * v9255);
struct StateT * slot_193(struct StateT * v9010);
struct StateT * slot_233(struct StateT * v11365);
struct StateT * slot_176(struct StateT * v8703);
struct StateT * slot_189(struct StateT * v8936);
struct StateT * slot_33(struct StateT * v3111);
struct StateT * slot_35(struct StateT * v3142);
struct StateT * slot_246(struct StateT * v11914);
struct StateT * slot_210(struct StateT * v9336);
struct StateT * slot_166(struct StateT * v8164);
struct StateT * slot_51(struct StateT * v3409);
struct StateT * slot_52(struct StateT * v3426);
struct StateT * slot_83(struct StateT * v5009);
struct StateT * slot_25(struct StateT * v1991);
struct StateT * slot_209(struct StateT * v9322);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_123(struct StateT * v6379);
struct StateT * slot_73(struct StateT * v4170);
struct StateT * slot_198(struct StateT * v9108);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v8895);
struct StateT * slot_97(struct StateT * v5249);
struct StateT * slot_182(struct StateT * v8804);
struct StateT * slot_38(struct StateT * v3188);
struct StateT * slot_178(struct StateT * v8737);
struct StateT * slot_106(struct StateT * v5430);
struct StateT * slot_98(struct StateT * v5274);
struct StateT * slot_159(struct StateT * v7404);
struct StateT * slot_46(struct StateT * v3320);
struct StateT * slot_212(struct StateT * v9366);
struct StateT * slot_132(struct StateT * v6897);
struct StateT * slot_130(struct StateT * v6863);
struct StateT * slot_211(struct StateT * v9350);
struct StateT * slot_20(struct StateT * v1903);
struct StateT * slot_141(struct StateT * v7057);
struct StateT * slot_61(struct StateT * v3607);
struct StateT * slot_30(struct StateT * v3045);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_18(struct StateT * v1862);
struct StateT * slot_9(struct StateT * v1711);
struct StateT * slot_183(struct StateT * v8820);
struct StateT * slot_240(struct StateT * v11844);
struct StateT * slot_247(struct StateT * v11930);
struct StateT * slot_43(struct StateT * v3273);
struct StateT * slot_70(struct StateT * v3787);
struct StateT * slot_168(struct StateT * v8203);
struct StateT * slot_76(struct StateT * v4516);
struct StateT * slot_6(struct StateT * v1480);
struct StateT * slot_225(struct StateT * v10258);
struct StateT * slot_55(struct StateT * v3492);
struct StateT * slot_213(struct StateT * v9383);
struct StateT * slot_82(struct StateT * v4993);
struct StateT * slot_161(struct StateT * v7487);
struct StateT * slot_185(struct StateT * v8853);
struct StateT * slot_91(struct StateT * v5141);
struct StateT * slot_58(struct StateT * v3541);
struct StateT * slot_89(struct StateT * v5107);
struct StateT * slot_66(struct StateT * v3695);
struct StateT * slot_140(struct StateT * v7032);
struct StateT * slot_49(struct StateT * v3369);
struct StateT * slot_216(struct StateT * v9438);
struct StateT * slot_50(struct StateT * v3385);
struct StateT * slot_37(struct StateT * v3172);
struct StateT * slot_114(struct StateT * v5580);
struct StateT * slot_135(struct StateT * v6948);
struct StateT * slot_248(struct StateT * v11946);
struct StateT * slot_59(struct StateT * v3558);
struct StateT * slot_192(struct StateT * v8993);
struct StateT * slot_40(struct StateT * v3222);
struct StateT * slot_48(struct StateT * v3353);
struct StateT * slot_77(struct StateT * v4531);
struct StateT * slot_85(struct StateT * v5039);
struct StateT * slot_75(struct StateT * v4502);
struct StateT * slot_72(struct StateT * v3855);
struct StateT * slot_119(struct StateT * v6011);
struct StateT * slot_71(struct StateT * v3839);
struct StateT * slot_101(struct StateT * v5332);
struct StateT * slot_108(struct StateT * v5463);
struct StateT * slot_116(struct StateT * v5663);
struct StateT * slot_93(struct StateT * v5174);
struct StateT * slot_88(struct StateT * v5090);
struct StateT * slot_96(struct StateT * v5233);
struct StateT * slot_215(struct StateT * v9422);
struct StateT * slot_234(struct StateT * v11381);
struct StateT * slot_45(struct StateT * v3303);
struct StateT * slot_218(struct StateT * v9485);
struct StateT * slot_220(struct StateT * v9517);
struct StateT * slot_134(struct StateT * v6931);
struct StateT * slot_175(struct StateT * v8686);
struct StateT * slot_69(struct StateT * v3756);
struct StateT * slot_202(struct StateT * v9180);
struct StateT * slot_230(struct StateT * v10942);
struct StateT * slot_188(struct StateT * v8920);
struct StateT * slot_138(struct StateT * v6998);
struct StateT * slot_186(struct StateT * v8878);
struct StateT * slot_102(struct StateT * v5348);
struct StateT * slot_145(struct StateT * v7139);
struct StateT * slot_110(struct StateT * v5487);
struct StateT * slot_196(struct StateT * v9076);
struct StateT * slot_208(struct StateT * v9309);
struct StateT * slot_172(struct StateT * v8640);
struct StateT * slot_131(struct StateT * v6880);
struct StateT * slot_8(struct StateT * v1697);
struct StateT * slot_180(struct StateT * v8771);
struct StateT * slot_203(struct StateT * v9203);
struct StateT * slot_190(struct StateT * v8961);
struct StateT * slot_157(struct StateT * v7359);
struct StateT * slot_200(struct StateT * v9132);
struct StateT * slot_243(struct StateT * v11865);
struct StateT * slot_173(struct StateT * v8656);
struct StateT * slot_149(struct StateT * v7205);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_104(struct StateT * v5381);
struct StateT * slot_235(struct StateT * v11585);
struct StateT * slot_54(struct StateT * v3467);
struct StateT * slot_26(struct StateT * v2306);
struct StateT * slot_206(struct StateT * v9271);
struct StateT * slot_227(struct StateT * v10587);
struct StateT * slot_169(struct StateT * v8217);
struct StateT * slot_64(struct StateT * v3655);
struct StateT * slot_170(struct StateT * v8233);
struct StateT * slot_14(struct StateT * v1796);
struct StateT * slot_53(struct StateT * v3451);
struct StateT * slot_80(struct StateT * v4585);
struct StateT * slot_44(struct StateT * v3287);
struct StateT * slot_137(struct StateT * v6982);
struct StateT * slot_122(struct StateT * v6355);
struct StateT * slot_99(struct StateT * v5290);
struct StateT * slot_179(struct StateT * v8754);
struct StateT * slot_219(struct StateT * v9501);
struct StateT * slot_36(struct StateT * v3156);
struct StateT * slot_57(struct StateT * v3525);
struct StateT * slot_62(struct StateT * v3623);
struct StateT * slot_22(struct StateT * v1944);
struct StateT * slot_139(struct StateT * v7015);
struct StateT * slot_221(struct StateT * v9596);
struct StateT * slot_23(struct StateT * v1961);
struct StateT * slot_153(struct StateT * v7287);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v5056);
struct StateT * slot_129(struct StateT * v6847);
struct StateT * slot_158(struct StateT * v7383);
struct StateT * slot_100(struct StateT * v5315);
struct StateT * slot_127(struct StateT * v6817);
struct StateT * slot_217(struct StateT * v9454);
struct StateT * slot_13(struct StateT * v1779);
struct StateT * slot_111(struct StateT * v5519);
struct StateT * slot_109(struct StateT * v5479);
struct StateT * slot_174(struct StateT * v8670);
struct StateT * slot_147(struct StateT * v7172);
struct StateT * slot_42(struct StateT * v3256);
struct StateT * slot_224(struct StateT * v9943);
struct StateT * slot_163(struct StateT * v7818);
struct StateT * slot_184(struct StateT * v8836);
struct StateT * slot_204(struct StateT * v9224);
struct StateT * slot_194(struct StateT * v9027);
struct StateT * slot_165(struct StateT * v8150);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v11986);
struct StateT * slot_117(struct StateT * v5679);
struct StateT * slot_249(struct StateT * v11970);
struct StateT * slot_90(struct StateT * v5124);
struct StateT * slot_11(struct StateT * v1745);
struct StateT * slot_12(struct StateT * v1762) {
  int v1763 = v1762->timer;
  int v1771 = v1763 + 1;
  v1762->timer = v1771;
  int * v1765 = v1762->regs;
  int v1766 = v1765[14];
  int v1767 = v1765[13];
  int v1776 = v1766 * v1767;
  v1765[7] = v1776;
  struct StateT * v1769 = slot_13(v1762);
  return v1769;
}

struct StateT * slot_228(struct StateT * v10611) {
  int v10612 = v10611->timer;
  int v10782 = v10612 + 1;
  v10611->timer = v10782;
  int * v10614 = v10611->regs;
  int v10615 = v10614[10];
  int v10616 = v10614[16];
  int * v10617 = v10611->cache_tags;
  int v10787 = (((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2;
  int v10618 = v10617[v10787];
  int v10788 = ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10619 = v10617[v10788];
  int v10789 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2);
  int v10620 = v10617[v10789];
  int v10790 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10621 = v10617[v10790];
  int v10622 = v10611->timer;
  int v10791 = v10622 + ((100 ^ (((~(((v10620 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10620 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10618 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10618 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10619 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10619 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10620 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10620 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10611->timer = v10791;
  bool v10792 = !(((~(((v10618 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10618 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10619 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10619 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v10716;
  if (v10792) {
    int * v10624 = v10611->cache_age;
    int v10794 = ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v10619 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10619 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v10625 = v10624[v10794];
    int v10626 = v10624[v10787];
    int v10795 = v10626 + ((int)((unsigned int)(v10626 - v10625) >> 31));
    v10624[v10787] = v10795;
    int * v10628 = v10611->cache_age;
    int v10629 = v10628[v10788];
    int v10797 = v10629 + ((int)((unsigned int)(v10629 - v10625) >> 31));
    v10628[v10788] = v10797;
    int * v10631 = v10611->cache_age;
    v10631[v10794] = 0;
    v10716 = v10794;
  } else {
    int * v10634 = v10611->cache_age;
    int v10801 = (((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2;
    int v10635 = v10634[v10801];
    int * v10636 = v10611->cache_tags;
    int v10637 = v10636[v10801];
    int v10638 = v10634[v10788];
    int v10639 = v10636[v10788];
    bool v10803 = !(((~(((v10620 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10620 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v10693;
    if (v10803) {
      int * v10640 = v10611->cache_age;
      int v10805 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10621 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v10641 = v10640[v10805];
      int v10642 = v10640[v10789];
      int v10806 = v10642 + ((int)((unsigned int)(v10642 - v10641) >> 31));
      v10640[v10789] = v10806;
      int * v10644 = v10611->cache_age;
      int v10645 = v10644[v10790];
      int v10808 = v10645 + ((int)((unsigned int)(v10645 - v10641) >> 31));
      v10644[v10790] = v10808;
      int * v10647 = v10611->cache_age;
      v10647[v10805] = 0;
      v10693 = v10805;
    } else {
      int * v10650 = v10611->cache_age;
      int v10812 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2);
      int v10651 = v10650[v10812];
      int * v10652 = v10611->cache_tags;
      int v10653 = v10652[v10812];
      int v10654 = v10650[v10790];
      int v10655 = v10652[v10790];
      int * v10656 = v10611->cache_dirty;
      int v10815 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10651 + ((~(((v10653 ^ -1) | (-(v10653 ^ -1))) >> 31)) & 2)) - (v10654 + ((~(((v10655 ^ -1) | (-(v10655 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10657 = v10656[v10815];
      bool v10816 = !(v10657 == 0);
      if (v10816) {
        int * v10658 = v10611->cache_tags;
        int v10659 = v10658[v10815];
        int * v10660 = v10611->cache_vals;
        int v10819 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10651 + ((~(((v10653 ^ -1) | (-(v10653 ^ -1))) >> 31)) & 2)) - (v10654 + ((~(((v10655 ^ -1) | (-(v10655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10661 = v10660[v10819];
        int v10820 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10651 + ((~(((v10653 ^ -1) | (-(v10653 ^ -1))) >> 31)) & 2)) - (v10654 + ((~(((v10655 ^ -1) | (-(v10655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10662 = v10660[v10820];
        int * v10663 = v10611->mem;
        int v10822 = v10659 * 2;
        v10663[v10822] = v10661;
        int * v10665 = v10611->mem;
        int v10825 = (v10659 * 2) + 1;
        v10665[v10825] = v10662;
        ;
      } else {
        ;
      }
      int * v10670 = v10611->mem;
      int v10830 = ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) * 2;
      int v10671 = v10670[v10830];
      int v10831 = (((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) * 2) + 1;
      int v10672 = v10670[v10831];
      int * v10673 = v10611->cache_vals;
      int v10833 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10651 + ((~(((v10653 ^ -1) | (-(v10653 ^ -1))) >> 31)) & 2)) - (v10654 + ((~(((v10655 ^ -1) | (-(v10655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10673[v10833] = v10671;
      int * v10675 = v10611->cache_vals;
      int v10836 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10651 + ((~(((v10653 ^ -1) | (-(v10653 ^ -1))) >> 31)) & 2)) - (v10654 + ((~(((v10655 ^ -1) | (-(v10655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10675[v10836] = v10672;
      int * v10677 = v10611->cache_tags;
      int v10839 = (int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1);
      v10677[v10815] = v10839;
      int * v10679 = v10611->cache_dirty;
      v10679[v10815] = 0;
      int * v10681 = v10611->cache_age;
      v10681[v10815] = 1;
      int * v10683 = v10611->cache_age;
      int v10684 = v10683[v10815];
      int v10685 = v10683[v10789];
      int v10845 = v10685 + ((int)((unsigned int)(v10685 - v10684) >> 31));
      v10683[v10789] = v10845;
      int * v10687 = v10611->cache_age;
      int v10688 = v10687[v10790];
      int v10847 = v10688 + ((int)((unsigned int)(v10688 - v10684) >> 31));
      v10687[v10790] = v10847;
      int * v10690 = v10611->cache_age;
      v10690[v10815] = 0;
      v10693 = v10815;
    }
    int * v10694 = v10611->cache_vals;
    int v10850 = v10693 * 2;
    int v10695 = v10694[v10850];
    int v10851 = (v10693 * 2) + 1;
    int v10696 = v10694[v10851];
    int v10852 = (((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10635 + ((~(((v10637 ^ -1) | (-(v10637 ^ -1))) >> 31)) & 2)) - (v10638 + ((~(((v10639 ^ -1) | (-(v10639 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10694[v10852] = v10695;
    int * v10698 = v10611->cache_vals;
    int v10855 = ((((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10635 + ((~(((v10637 ^ -1) | (-(v10637 ^ -1))) >> 31)) & 2)) - (v10638 + ((~(((v10639 ^ -1) | (-(v10639 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10698[v10855] = v10696;
    int * v10700 = v10611->cache_tags;
    int v10858 = ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10635 + ((~(((v10637 ^ -1) | (-(v10637 ^ -1))) >> 31)) & 2)) - (v10638 + ((~(((v10639 ^ -1) | (-(v10639 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10859 = (int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1);
    v10700[v10858] = v10859;
    int * v10702 = v10611->cache_dirty;
    v10702[v10858] = 0;
    int * v10704 = v10611->cache_age;
    v10704[v10858] = 1;
    int * v10706 = v10611->cache_age;
    int v10707 = v10706[v10858];
    int v10708 = v10706[v10787];
    int v10865 = v10708 + ((int)((unsigned int)(v10708 - v10707) >> 31));
    v10706[v10787] = v10865;
    int * v10710 = v10611->cache_age;
    int v10711 = v10710[v10788];
    int v10867 = v10711 + ((int)((unsigned int)(v10711 - v10707) >> 31));
    v10710[v10788] = v10867;
    int * v10713 = v10611->cache_age;
    v10713[v10858] = 0;
    v10716 = v10858;
  }
  int * v10717 = v10611->cache_vals;
  int v10870 = (v10716 * 2) + (((int)((unsigned int)(v10615 + 36) >> 2)) & 1);
  v10717[v10870] = v10616;
  int * v10719 = v10611->cache_tags;
  int v10720 = v10719[v10789];
  int v10721 = v10719[v10790];
  bool v10873 = !(((~(((v10720 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10720 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10721 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10721 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v10775;
  if (v10873) {
    int * v10722 = v10611->cache_age;
    int v10875 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10721 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))) | (-(v10721 ^ ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v10723 = v10722[v10875];
    int v10724 = v10722[v10789];
    int v10876 = v10724 + ((int)((unsigned int)(v10724 - v10723) >> 31));
    v10722[v10789] = v10876;
    int * v10726 = v10611->cache_age;
    int v10727 = v10726[v10790];
    int v10878 = v10727 + ((int)((unsigned int)(v10727 - v10723) >> 31));
    v10726[v10790] = v10878;
    int * v10729 = v10611->cache_age;
    v10729[v10875] = 0;
    v10775 = v10875;
  } else {
    int * v10732 = v10611->cache_age;
    int v10882 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2);
    int v10733 = v10732[v10882];
    int * v10734 = v10611->cache_tags;
    int v10735 = v10734[v10882];
    int v10736 = v10732[v10790];
    int v10737 = v10734[v10790];
    int * v10738 = v10611->cache_dirty;
    int v10885 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10733 + ((~(((v10735 ^ -1) | (-(v10735 ^ -1))) >> 31)) & 2)) - (v10736 + ((~(((v10737 ^ -1) | (-(v10737 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10739 = v10738[v10885];
    bool v10886 = !(v10739 == 0);
    if (v10886) {
      int * v10740 = v10611->cache_tags;
      int v10741 = v10740[v10885];
      int * v10742 = v10611->cache_vals;
      int v10889 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10733 + ((~(((v10735 ^ -1) | (-(v10735 ^ -1))) >> 31)) & 2)) - (v10736 + ((~(((v10737 ^ -1) | (-(v10737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10743 = v10742[v10889];
      int v10890 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10733 + ((~(((v10735 ^ -1) | (-(v10735 ^ -1))) >> 31)) & 2)) - (v10736 + ((~(((v10737 ^ -1) | (-(v10737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10744 = v10742[v10890];
      int * v10745 = v10611->mem;
      int v10892 = v10741 * 2;
      v10745[v10892] = v10743;
      int * v10747 = v10611->mem;
      int v10895 = (v10741 * 2) + 1;
      v10747[v10895] = v10744;
      ;
    } else {
      ;
    }
    int * v10752 = v10611->mem;
    int v10900 = ((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) * 2;
    int v10753 = v10752[v10900];
    int v10901 = (((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) * 2) + 1;
    int v10754 = v10752[v10901];
    int * v10755 = v10611->cache_vals;
    int v10903 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10733 + ((~(((v10735 ^ -1) | (-(v10735 ^ -1))) >> 31)) & 2)) - (v10736 + ((~(((v10737 ^ -1) | (-(v10737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10755[v10903] = v10753;
    int * v10757 = v10611->cache_vals;
    int v10906 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10733 + ((~(((v10735 ^ -1) | (-(v10735 ^ -1))) >> 31)) & 2)) - (v10736 + ((~(((v10737 ^ -1) | (-(v10737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10757[v10906] = v10754;
    int * v10759 = v10611->cache_tags;
    int v10909 = (int)((unsigned int)((int)((unsigned int)(v10615 + 36) >> 2)) >> 1);
    v10759[v10885] = v10909;
    int * v10761 = v10611->cache_dirty;
    v10761[v10885] = 0;
    int * v10763 = v10611->cache_age;
    v10763[v10885] = 1;
    int * v10765 = v10611->cache_age;
    int v10766 = v10765[v10885];
    int v10767 = v10765[v10789];
    int v10915 = v10767 + ((int)((unsigned int)(v10767 - v10766) >> 31));
    v10765[v10789] = v10915;
    int * v10769 = v10611->cache_age;
    int v10770 = v10769[v10790];
    int v10917 = v10770 + ((int)((unsigned int)(v10770 - v10766) >> 31));
    v10769[v10790] = v10917;
    int * v10772 = v10611->cache_age;
    v10772[v10885] = 0;
    v10775 = v10885;
  }
  int * v10776 = v10611->cache_vals;
  int v10920 = (v10775 * 2) + (((int)((unsigned int)(v10615 + 36) >> 2)) & 1);
  v10776[v10920] = v10616;
  int * v10778 = v10611->cache_dirty;
  v10778[v10775] = 1;
  struct StateT * v10780 = slot_230(v10611);
  return v10780;
}

struct StateT * slot_143(struct StateT * v7098) {
  int v7099 = v7098->timer;
  int v7107 = v7099 + 1;
  v7098->timer = v7107;
  int * v7101 = v7098->regs;
  int v7102 = v7101[30];
  int v7103 = v7101[7];
  int v7111 = v7102 + v7103;
  v7101[7] = v7111;
  struct StateT * v7105 = slot_144(v7098);
  return v7105;
}

struct StateT * slot_120(struct StateT * v6326) {
  int v6327 = v6326->timer;
  int v6334 = v6327 + 1;
  v6326->timer = v6334;
  int * v6329 = v6326->regs;
  int v6330 = v6329[7];
  int v6337 = (int)((unsigned int)v6330 >> 19);
  v6329[7] = v6337;
  struct StateT * v6332 = slot_122(v6326);
  return v6332;
}

struct StateT * slot_226(struct StateT * v10272) {
  int v10273 = v10272->timer;
  int v10443 = v10273 + 1;
  v10272->timer = v10443;
  int * v10275 = v10272->regs;
  int v10276 = v10275[10];
  int v10277 = v10275[11];
  int * v10278 = v10272->cache_tags;
  int v10448 = (((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2;
  int v10279 = v10278[v10448];
  int v10449 = ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10280 = v10278[v10449];
  int v10450 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2);
  int v10281 = v10278[v10450];
  int v10451 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10282 = v10278[v10451];
  int v10283 = v10272->timer;
  int v10452 = v10283 + ((100 ^ (((~(((v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10279 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10279 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10272->timer = v10452;
  bool v10453 = !(((~(((v10279 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10279 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v10377;
  if (v10453) {
    int * v10285 = v10272->cache_age;
    int v10455 = ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v10286 = v10285[v10455];
    int v10287 = v10285[v10448];
    int v10456 = v10287 + ((int)((unsigned int)(v10287 - v10286) >> 31));
    v10285[v10448] = v10456;
    int * v10289 = v10272->cache_age;
    int v10290 = v10289[v10449];
    int v10458 = v10290 + ((int)((unsigned int)(v10290 - v10286) >> 31));
    v10289[v10449] = v10458;
    int * v10292 = v10272->cache_age;
    v10292[v10455] = 0;
    v10377 = v10455;
  } else {
    int * v10295 = v10272->cache_age;
    int v10462 = (((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2;
    int v10296 = v10295[v10462];
    int * v10297 = v10272->cache_tags;
    int v10298 = v10297[v10462];
    int v10299 = v10295[v10449];
    int v10300 = v10297[v10449];
    bool v10464 = !(((~(((v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v10354;
    if (v10464) {
      int * v10301 = v10272->cache_age;
      int v10466 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v10302 = v10301[v10466];
      int v10303 = v10301[v10450];
      int v10467 = v10303 + ((int)((unsigned int)(v10303 - v10302) >> 31));
      v10301[v10450] = v10467;
      int * v10305 = v10272->cache_age;
      int v10306 = v10305[v10451];
      int v10469 = v10306 + ((int)((unsigned int)(v10306 - v10302) >> 31));
      v10305[v10451] = v10469;
      int * v10308 = v10272->cache_age;
      v10308[v10466] = 0;
      v10354 = v10466;
    } else {
      int * v10311 = v10272->cache_age;
      int v10473 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2);
      int v10312 = v10311[v10473];
      int * v10313 = v10272->cache_tags;
      int v10314 = v10313[v10473];
      int v10315 = v10311[v10451];
      int v10316 = v10313[v10451];
      int * v10317 = v10272->cache_dirty;
      int v10476 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10312 + ((~(((v10314 ^ -1) | (-(v10314 ^ -1))) >> 31)) & 2)) - (v10315 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10318 = v10317[v10476];
      bool v10477 = !(v10318 == 0);
      if (v10477) {
        int * v10319 = v10272->cache_tags;
        int v10320 = v10319[v10476];
        int * v10321 = v10272->cache_vals;
        int v10480 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10312 + ((~(((v10314 ^ -1) | (-(v10314 ^ -1))) >> 31)) & 2)) - (v10315 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10322 = v10321[v10480];
        int v10481 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10312 + ((~(((v10314 ^ -1) | (-(v10314 ^ -1))) >> 31)) & 2)) - (v10315 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10323 = v10321[v10481];
        int * v10324 = v10272->mem;
        int v10483 = v10320 * 2;
        v10324[v10483] = v10322;
        int * v10326 = v10272->mem;
        int v10486 = (v10320 * 2) + 1;
        v10326[v10486] = v10323;
        ;
      } else {
        ;
      }
      int * v10331 = v10272->mem;
      int v10491 = ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) * 2;
      int v10332 = v10331[v10491];
      int v10492 = (((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) * 2) + 1;
      int v10333 = v10331[v10492];
      int * v10334 = v10272->cache_vals;
      int v10494 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10312 + ((~(((v10314 ^ -1) | (-(v10314 ^ -1))) >> 31)) & 2)) - (v10315 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10334[v10494] = v10332;
      int * v10336 = v10272->cache_vals;
      int v10497 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10312 + ((~(((v10314 ^ -1) | (-(v10314 ^ -1))) >> 31)) & 2)) - (v10315 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10336[v10497] = v10333;
      int * v10338 = v10272->cache_tags;
      int v10500 = (int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1);
      v10338[v10476] = v10500;
      int * v10340 = v10272->cache_dirty;
      v10340[v10476] = 0;
      int * v10342 = v10272->cache_age;
      v10342[v10476] = 1;
      int * v10344 = v10272->cache_age;
      int v10345 = v10344[v10476];
      int v10346 = v10344[v10450];
      int v10506 = v10346 + ((int)((unsigned int)(v10346 - v10345) >> 31));
      v10344[v10450] = v10506;
      int * v10348 = v10272->cache_age;
      int v10349 = v10348[v10451];
      int v10508 = v10349 + ((int)((unsigned int)(v10349 - v10345) >> 31));
      v10348[v10451] = v10508;
      int * v10351 = v10272->cache_age;
      v10351[v10476] = 0;
      v10354 = v10476;
    }
    int * v10355 = v10272->cache_vals;
    int v10511 = v10354 * 2;
    int v10356 = v10355[v10511];
    int v10512 = (v10354 * 2) + 1;
    int v10357 = v10355[v10512];
    int v10513 = (((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v10296 + ((~(((v10298 ^ -1) | (-(v10298 ^ -1))) >> 31)) & 2)) - (v10299 + ((~(((v10300 ^ -1) | (-(v10300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10355[v10513] = v10356;
    int * v10359 = v10272->cache_vals;
    int v10516 = ((((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v10296 + ((~(((v10298 ^ -1) | (-(v10298 ^ -1))) >> 31)) & 2)) - (v10299 + ((~(((v10300 ^ -1) | (-(v10300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10359[v10516] = v10357;
    int * v10361 = v10272->cache_tags;
    int v10519 = ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v10296 + ((~(((v10298 ^ -1) | (-(v10298 ^ -1))) >> 31)) & 2)) - (v10299 + ((~(((v10300 ^ -1) | (-(v10300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10520 = (int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1);
    v10361[v10519] = v10520;
    int * v10363 = v10272->cache_dirty;
    v10363[v10519] = 0;
    int * v10365 = v10272->cache_age;
    v10365[v10519] = 1;
    int * v10367 = v10272->cache_age;
    int v10368 = v10367[v10519];
    int v10369 = v10367[v10448];
    int v10526 = v10369 + ((int)((unsigned int)(v10369 - v10368) >> 31));
    v10367[v10448] = v10526;
    int * v10371 = v10272->cache_age;
    int v10372 = v10371[v10449];
    int v10528 = v10372 + ((int)((unsigned int)(v10372 - v10368) >> 31));
    v10371[v10449] = v10528;
    int * v10374 = v10272->cache_age;
    v10374[v10519] = 0;
    v10377 = v10519;
  }
  int * v10378 = v10272->cache_vals;
  int v10531 = (v10377 * 2) + (((int)((unsigned int)(v10276 + 32) >> 2)) & 1);
  v10378[v10531] = v10277;
  int * v10380 = v10272->cache_tags;
  int v10381 = v10380[v10450];
  int v10382 = v10380[v10451];
  bool v10534 = !(((~(((v10381 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10381 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v10382 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10382 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v10436;
  if (v10534) {
    int * v10383 = v10272->cache_age;
    int v10536 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10382 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))) | (-(v10382 ^ ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v10384 = v10383[v10536];
    int v10385 = v10383[v10450];
    int v10537 = v10385 + ((int)((unsigned int)(v10385 - v10384) >> 31));
    v10383[v10450] = v10537;
    int * v10387 = v10272->cache_age;
    int v10388 = v10387[v10451];
    int v10539 = v10388 + ((int)((unsigned int)(v10388 - v10384) >> 31));
    v10387[v10451] = v10539;
    int * v10390 = v10272->cache_age;
    v10390[v10536] = 0;
    v10436 = v10536;
  } else {
    int * v10393 = v10272->cache_age;
    int v10543 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2);
    int v10394 = v10393[v10543];
    int * v10395 = v10272->cache_tags;
    int v10396 = v10395[v10543];
    int v10397 = v10393[v10451];
    int v10398 = v10395[v10451];
    int * v10399 = v10272->cache_dirty;
    int v10546 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10394 + ((~(((v10396 ^ -1) | (-(v10396 ^ -1))) >> 31)) & 2)) - (v10397 + ((~(((v10398 ^ -1) | (-(v10398 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10400 = v10399[v10546];
    bool v10547 = !(v10400 == 0);
    if (v10547) {
      int * v10401 = v10272->cache_tags;
      int v10402 = v10401[v10546];
      int * v10403 = v10272->cache_vals;
      int v10550 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10394 + ((~(((v10396 ^ -1) | (-(v10396 ^ -1))) >> 31)) & 2)) - (v10397 + ((~(((v10398 ^ -1) | (-(v10398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10404 = v10403[v10550];
      int v10551 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10394 + ((~(((v10396 ^ -1) | (-(v10396 ^ -1))) >> 31)) & 2)) - (v10397 + ((~(((v10398 ^ -1) | (-(v10398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10405 = v10403[v10551];
      int * v10406 = v10272->mem;
      int v10553 = v10402 * 2;
      v10406[v10553] = v10404;
      int * v10408 = v10272->mem;
      int v10556 = (v10402 * 2) + 1;
      v10408[v10556] = v10405;
      ;
    } else {
      ;
    }
    int * v10413 = v10272->mem;
    int v10561 = ((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) * 2;
    int v10414 = v10413[v10561];
    int v10562 = (((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) * 2) + 1;
    int v10415 = v10413[v10562];
    int * v10416 = v10272->cache_vals;
    int v10564 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10394 + ((~(((v10396 ^ -1) | (-(v10396 ^ -1))) >> 31)) & 2)) - (v10397 + ((~(((v10398 ^ -1) | (-(v10398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10416[v10564] = v10414;
    int * v10418 = v10272->cache_vals;
    int v10567 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v10394 + ((~(((v10396 ^ -1) | (-(v10396 ^ -1))) >> 31)) & 2)) - (v10397 + ((~(((v10398 ^ -1) | (-(v10398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10418[v10567] = v10415;
    int * v10420 = v10272->cache_tags;
    int v10570 = (int)((unsigned int)((int)((unsigned int)(v10276 + 32) >> 2)) >> 1);
    v10420[v10546] = v10570;
    int * v10422 = v10272->cache_dirty;
    v10422[v10546] = 0;
    int * v10424 = v10272->cache_age;
    v10424[v10546] = 1;
    int * v10426 = v10272->cache_age;
    int v10427 = v10426[v10546];
    int v10428 = v10426[v10450];
    int v10576 = v10428 + ((int)((unsigned int)(v10428 - v10427) >> 31));
    v10426[v10450] = v10576;
    int * v10430 = v10272->cache_age;
    int v10431 = v10430[v10451];
    int v10578 = v10431 + ((int)((unsigned int)(v10431 - v10427) >> 31));
    v10430[v10451] = v10578;
    int * v10433 = v10272->cache_age;
    v10433[v10546] = 0;
    v10436 = v10546;
  }
  int * v10437 = v10272->cache_vals;
  int v10581 = (v10436 * 2) + (((int)((unsigned int)(v10276 + 32) >> 2)) & 1);
  v10437[v10581] = v10277;
  int * v10439 = v10272->cache_dirty;
  v10439[v10436] = 1;
  struct StateT * v10441 = slot_228(v10272);
  return v10441;
}

struct StateT * slot_167(struct StateT * v8179) {
  int v8180 = v8179->timer;
  int v8192 = v8180 + 1;
  v8179->timer = v8192;
  int * v8182 = v8179->regs;
  int v8183 = v8182[28];
  int v8184 = v8182[5];
  bool v8196 = (v8183 ^ -2147483648) < (v8184 ^ -2147483648);
  int v8187;
  if (v8196) {
    v8187 = 1;
  } else {
    v8187 = 0;
  }
  int * v8188 = v8179->regs;
  v8188[5] = v8187;
  struct StateT * v8190 = slot_162(v8179);
  return v8190;
}

struct StateT * slot_152(struct StateT * v7270) {
  int v7271 = v7270->timer;
  int v7279 = v7271 + 1;
  v7270->timer = v7279;
  int * v7273 = v7270->regs;
  int v7274 = v7273[30];
  int v7275 = v7273[28];
  int v7284 = v7274 + v7275;
  v7273[7] = v7284;
  struct StateT * v7277 = slot_153(v7270);
  return v7277;
}

struct StateT * slot_231(struct StateT * v11146) {
  int v11147 = v11146->timer;
  int v11154 = v11147 + 1;
  v11146->timer = v11154;
  int * v11149 = v11146->regs;
  int v11150 = v11149[5];
  int v11158 = v11150 << 13;
  v11149[13] = v11158;
  struct StateT * v11152 = slot_233(v11146);
  return v11152;
}

struct StateT * slot_199(struct StateT * v9124) {
  int v9125 = v9124->timer;
  int v9129 = v9125 + 1;
  v9124->timer = v9129;
  struct StateT * v9127 = slot_200(v9124);
  return v9127;
}

struct StateT * slot_92(struct StateT * v5158) {
  int v5159 = v5158->timer;
  int v5167 = v5159 + 1;
  v5158->timer = v5167;
  int * v5161 = v5158->regs;
  int v5162 = v5161[6];
  int v5163 = v5161[12];
  int v5171 = v5162 * v5163;
  v5161[6] = v5171;
  struct StateT * v5165 = slot_93(v5158);
  return v5165;
}

struct StateT * slot_232(struct StateT * v11161) {
  int v11162 = v11161->timer;
  int v11272 = v11162 + 1;
  v11161->timer = v11272;
  int * v11164 = v11161->regs;
  int v11165 = v11164[2];
  int * v11166 = v11161->cache_tags;
  int v11276 = (((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2;
  int v11167 = v11166[v11276];
  int v11277 = ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11168 = v11166[v11277];
  int v11278 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2);
  int v11169 = v11166[v11278];
  int v11279 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11170 = v11166[v11279];
  int v11171 = v11161->timer;
  int v11280 = v11171 + ((100 ^ (((~(((v11169 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11169 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11167 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11167 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v11168 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11168 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11169 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11169 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11161->timer = v11280;
  int * v11173 = v11161->cache_vals;
  bool v11281 = !(((~(((v11167 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11167 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v11168 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11168 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v11266;
  if (v11281) {
    int * v11174 = v11161->cache_age;
    int v11283 = ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v11168 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11168 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v11175 = v11174[v11283];
    int v11176 = v11174[v11276];
    int v11284 = v11176 + ((int)((unsigned int)(v11176 - v11175) >> 31));
    v11174[v11276] = v11284;
    int * v11178 = v11161->cache_age;
    int v11179 = v11178[v11277];
    int v11286 = v11179 + ((int)((unsigned int)(v11179 - v11175) >> 31));
    v11178[v11277] = v11286;
    int * v11181 = v11161->cache_age;
    v11181[v11283] = 0;
    v11266 = v11283;
  } else {
    int * v11184 = v11161->cache_age;
    int v11290 = (((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2;
    int v11185 = v11184[v11290];
    int * v11186 = v11161->cache_tags;
    int v11187 = v11186[v11290];
    int v11188 = v11184[v11277];
    int v11189 = v11186[v11277];
    bool v11292 = !(((~(((v11169 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11169 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v11243;
    if (v11292) {
      int * v11190 = v11161->cache_age;
      int v11294 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))) | (-(v11170 ^ ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v11191 = v11190[v11294];
      int v11192 = v11190[v11278];
      int v11295 = v11192 + ((int)((unsigned int)(v11192 - v11191) >> 31));
      v11190[v11278] = v11295;
      int * v11194 = v11161->cache_age;
      int v11195 = v11194[v11279];
      int v11297 = v11195 + ((int)((unsigned int)(v11195 - v11191) >> 31));
      v11194[v11279] = v11297;
      int * v11197 = v11161->cache_age;
      v11197[v11294] = 0;
      v11243 = v11294;
    } else {
      int * v11200 = v11161->cache_age;
      int v11301 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2);
      int v11201 = v11200[v11301];
      int * v11202 = v11161->cache_tags;
      int v11203 = v11202[v11301];
      int v11204 = v11200[v11279];
      int v11205 = v11202[v11279];
      int * v11206 = v11161->cache_dirty;
      int v11304 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v11201 + ((~(((v11203 ^ -1) | (-(v11203 ^ -1))) >> 31)) & 2)) - (v11204 + ((~(((v11205 ^ -1) | (-(v11205 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11207 = v11206[v11304];
      bool v11305 = !(v11207 == 0);
      if (v11305) {
        int * v11208 = v11161->cache_tags;
        int v11209 = v11208[v11304];
        int * v11210 = v11161->cache_vals;
        int v11308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v11201 + ((~(((v11203 ^ -1) | (-(v11203 ^ -1))) >> 31)) & 2)) - (v11204 + ((~(((v11205 ^ -1) | (-(v11205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11211 = v11210[v11308];
        int v11309 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v11201 + ((~(((v11203 ^ -1) | (-(v11203 ^ -1))) >> 31)) & 2)) - (v11204 + ((~(((v11205 ^ -1) | (-(v11205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11212 = v11210[v11309];
        int * v11213 = v11161->mem;
        int v11311 = v11209 * 2;
        v11213[v11311] = v11211;
        int * v11215 = v11161->mem;
        int v11314 = (v11209 * 2) + 1;
        v11215[v11314] = v11212;
        ;
      } else {
        ;
      }
      int * v11220 = v11161->mem;
      int v11319 = ((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) * 2;
      int v11221 = v11220[v11319];
      int v11320 = (((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) * 2) + 1;
      int v11222 = v11220[v11320];
      int * v11223 = v11161->cache_vals;
      int v11322 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v11201 + ((~(((v11203 ^ -1) | (-(v11203 ^ -1))) >> 31)) & 2)) - (v11204 + ((~(((v11205 ^ -1) | (-(v11205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11223[v11322] = v11221;
      int * v11225 = v11161->cache_vals;
      int v11325 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v11201 + ((~(((v11203 ^ -1) | (-(v11203 ^ -1))) >> 31)) & 2)) - (v11204 + ((~(((v11205 ^ -1) | (-(v11205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11225[v11325] = v11222;
      int * v11227 = v11161->cache_tags;
      int v11328 = (int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1);
      v11227[v11304] = v11328;
      int * v11229 = v11161->cache_dirty;
      v11229[v11304] = 0;
      int * v11231 = v11161->cache_age;
      v11231[v11304] = 1;
      int * v11233 = v11161->cache_age;
      int v11234 = v11233[v11304];
      int v11235 = v11233[v11278];
      int v11334 = v11235 + ((int)((unsigned int)(v11235 - v11234) >> 31));
      v11233[v11278] = v11334;
      int * v11237 = v11161->cache_age;
      int v11238 = v11237[v11279];
      int v11336 = v11238 + ((int)((unsigned int)(v11238 - v11234) >> 31));
      v11237[v11279] = v11336;
      int * v11240 = v11161->cache_age;
      v11240[v11304] = 0;
      v11243 = v11304;
    }
    int * v11244 = v11161->cache_vals;
    int v11339 = v11243 * 2;
    int v11245 = v11244[v11339];
    int v11340 = (v11243 * 2) + 1;
    int v11246 = v11244[v11340];
    int v11341 = (((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v11185 + ((~(((v11187 ^ -1) | (-(v11187 ^ -1))) >> 31)) & 2)) - (v11188 + ((~(((v11189 ^ -1) | (-(v11189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11244[v11341] = v11245;
    int * v11248 = v11161->cache_vals;
    int v11344 = ((((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v11185 + ((~(((v11187 ^ -1) | (-(v11187 ^ -1))) >> 31)) & 2)) - (v11188 + ((~(((v11189 ^ -1) | (-(v11189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11248[v11344] = v11246;
    int * v11250 = v11161->cache_tags;
    int v11347 = ((((int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v11185 + ((~(((v11187 ^ -1) | (-(v11187 ^ -1))) >> 31)) & 2)) - (v11188 + ((~(((v11189 ^ -1) | (-(v11189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11348 = (int)((unsigned int)((int)((unsigned int)(v11165 + 8) >> 2)) >> 1);
    v11250[v11347] = v11348;
    int * v11252 = v11161->cache_dirty;
    v11252[v11347] = 0;
    int * v11254 = v11161->cache_age;
    v11254[v11347] = 1;
    int * v11256 = v11161->cache_age;
    int v11257 = v11256[v11347];
    int v11258 = v11256[v11276];
    int v11354 = v11258 + ((int)((unsigned int)(v11258 - v11257) >> 31));
    v11256[v11276] = v11354;
    int * v11260 = v11161->cache_age;
    int v11261 = v11260[v11277];
    int v11356 = v11261 + ((int)((unsigned int)(v11261 - v11257) >> 31));
    v11260[v11277] = v11356;
    int * v11263 = v11161->cache_age;
    v11263[v11347] = 0;
    v11266 = v11347;
  }
  int v11359 = (v11266 * 2) + (((int)((unsigned int)(v11165 + 8) >> 2)) & 1);
  int v11267 = v11173[v11359];
  int * v11268 = v11161->regs;
  v11268[9] = v11267;
  struct StateT * v11270 = slot_234(v11161);
  return v11270;
}

struct StateT * slot_31(struct StateT * v3062) {
  int v3063 = v3062->timer;
  int v3075 = v3063 + 1;
  v3062->timer = v3075;
  int * v3065 = v3062->regs;
  int v3066 = v3065[5];
  int v3067 = v3065[6];
  bool v3079 = (v3066 ^ -2147483648) < (v3067 ^ -2147483648);
  int v3070;
  if (v3079) {
    v3070 = 1;
  } else {
    v3070 = 0;
  }
  int * v3071 = v3062->regs;
  v3071[5] = v3070;
  struct StateT * v3073 = slot_32(v3062);
  return v3073;
}

struct StateT * slot_236(struct StateT * v11598) {
  int v11599 = v11598->timer;
  int v11709 = v11599 + 1;
  v11598->timer = v11709;
  int * v11601 = v11598->regs;
  int v11602 = v11601[2];
  int * v11603 = v11598->cache_tags;
  int v11713 = (((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2;
  int v11604 = v11603[v11713];
  int v11714 = ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2) + 1;
  int v11605 = v11603[v11714];
  int v11715 = 4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2);
  int v11606 = v11603[v11715];
  int v11716 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11607 = v11603[v11716];
  int v11608 = v11598->timer;
  int v11717 = v11608 + ((100 ^ (((~(((v11606 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11606 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) | (~(((v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11604 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11604 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) | (~(((v11605 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11605 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11606 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11606 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) | (~(((v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31))) & 104)))));
  v11598->timer = v11717;
  int * v11610 = v11598->cache_vals;
  bool v11718 = !(((~(((v11604 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11604 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) | (~(((v11605 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11605 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31))) == 0);
  int v11703;
  if (v11718) {
    int * v11611 = v11598->cache_age;
    int v11720 = ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2) + ((~(((v11605 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11605 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) & 1);
    int v11612 = v11611[v11720];
    int v11613 = v11611[v11713];
    int v11721 = v11613 + ((int)((unsigned int)(v11613 - v11612) >> 31));
    v11611[v11713] = v11721;
    int * v11615 = v11598->cache_age;
    int v11616 = v11615[v11714];
    int v11723 = v11616 + ((int)((unsigned int)(v11616 - v11612) >> 31));
    v11615[v11714] = v11723;
    int * v11618 = v11598->cache_age;
    v11618[v11720] = 0;
    v11703 = v11720;
  } else {
    int * v11621 = v11598->cache_age;
    int v11727 = (((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2;
    int v11622 = v11621[v11727];
    int * v11623 = v11598->cache_tags;
    int v11624 = v11623[v11727];
    int v11625 = v11621[v11714];
    int v11626 = v11623[v11714];
    bool v11729 = !(((~(((v11606 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11606 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) | (~(((v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31))) == 0);
    int v11680;
    if (v11729) {
      int * v11627 = v11598->cache_age;
      int v11731 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))) | (-(v11607 ^ ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1))))) >> 31)) & 1);
      int v11628 = v11627[v11731];
      int v11629 = v11627[v11715];
      int v11732 = v11629 + ((int)((unsigned int)(v11629 - v11628) >> 31));
      v11627[v11715] = v11732;
      int * v11631 = v11598->cache_age;
      int v11632 = v11631[v11716];
      int v11734 = v11632 + ((int)((unsigned int)(v11632 - v11628) >> 31));
      v11631[v11716] = v11734;
      int * v11634 = v11598->cache_age;
      v11634[v11731] = 0;
      v11680 = v11731;
    } else {
      int * v11637 = v11598->cache_age;
      int v11738 = 4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2);
      int v11638 = v11637[v11738];
      int * v11639 = v11598->cache_tags;
      int v11640 = v11639[v11738];
      int v11641 = v11637[v11716];
      int v11642 = v11639[v11716];
      int * v11643 = v11598->cache_dirty;
      int v11741 = (4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + ((((v11638 + ((~(((v11640 ^ -1) | (-(v11640 ^ -1))) >> 31)) & 2)) - (v11641 + ((~(((v11642 ^ -1) | (-(v11642 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11644 = v11643[v11741];
      bool v11742 = !(v11644 == 0);
      if (v11742) {
        int * v11645 = v11598->cache_tags;
        int v11646 = v11645[v11741];
        int * v11647 = v11598->cache_vals;
        int v11745 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + ((((v11638 + ((~(((v11640 ^ -1) | (-(v11640 ^ -1))) >> 31)) & 2)) - (v11641 + ((~(((v11642 ^ -1) | (-(v11642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11648 = v11647[v11745];
        int v11746 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + ((((v11638 + ((~(((v11640 ^ -1) | (-(v11640 ^ -1))) >> 31)) & 2)) - (v11641 + ((~(((v11642 ^ -1) | (-(v11642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11649 = v11647[v11746];
        int * v11650 = v11598->mem;
        int v11748 = v11646 * 2;
        v11650[v11748] = v11648;
        int * v11652 = v11598->mem;
        int v11751 = (v11646 * 2) + 1;
        v11652[v11751] = v11649;
        ;
      } else {
        ;
      }
      int * v11657 = v11598->mem;
      int v11756 = ((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) * 2;
      int v11658 = v11657[v11756];
      int v11757 = (((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) * 2) + 1;
      int v11659 = v11657[v11757];
      int * v11660 = v11598->cache_vals;
      int v11759 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + ((((v11638 + ((~(((v11640 ^ -1) | (-(v11640 ^ -1))) >> 31)) & 2)) - (v11641 + ((~(((v11642 ^ -1) | (-(v11642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11660[v11759] = v11658;
      int * v11662 = v11598->cache_vals;
      int v11762 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 3) * 2)) + ((((v11638 + ((~(((v11640 ^ -1) | (-(v11640 ^ -1))) >> 31)) & 2)) - (v11641 + ((~(((v11642 ^ -1) | (-(v11642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11662[v11762] = v11659;
      int * v11664 = v11598->cache_tags;
      int v11765 = (int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1);
      v11664[v11741] = v11765;
      int * v11666 = v11598->cache_dirty;
      v11666[v11741] = 0;
      int * v11668 = v11598->cache_age;
      v11668[v11741] = 1;
      int * v11670 = v11598->cache_age;
      int v11671 = v11670[v11741];
      int v11672 = v11670[v11715];
      int v11771 = v11672 + ((int)((unsigned int)(v11672 - v11671) >> 31));
      v11670[v11715] = v11771;
      int * v11674 = v11598->cache_age;
      int v11675 = v11674[v11716];
      int v11773 = v11675 + ((int)((unsigned int)(v11675 - v11671) >> 31));
      v11674[v11716] = v11773;
      int * v11677 = v11598->cache_age;
      v11677[v11741] = 0;
      v11680 = v11741;
    }
    int * v11681 = v11598->cache_vals;
    int v11776 = v11680 * 2;
    int v11682 = v11681[v11776];
    int v11777 = (v11680 * 2) + 1;
    int v11683 = v11681[v11777];
    int v11778 = (((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2) + ((((v11622 + ((~(((v11624 ^ -1) | (-(v11624 ^ -1))) >> 31)) & 2)) - (v11625 + ((~(((v11626 ^ -1) | (-(v11626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11681[v11778] = v11682;
    int * v11685 = v11598->cache_vals;
    int v11781 = ((((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2) + ((((v11622 + ((~(((v11624 ^ -1) | (-(v11624 ^ -1))) >> 31)) & 2)) - (v11625 + ((~(((v11626 ^ -1) | (-(v11626 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11685[v11781] = v11683;
    int * v11687 = v11598->cache_tags;
    int v11784 = ((((int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1)) & 1) * 2) + ((((v11622 + ((~(((v11624 ^ -1) | (-(v11624 ^ -1))) >> 31)) & 2)) - (v11625 + ((~(((v11626 ^ -1) | (-(v11626 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11785 = (int)((unsigned int)((int)((unsigned int)v11602 >> 2)) >> 1);
    v11687[v11784] = v11785;
    int * v11689 = v11598->cache_dirty;
    v11689[v11784] = 0;
    int * v11691 = v11598->cache_age;
    v11691[v11784] = 1;
    int * v11693 = v11598->cache_age;
    int v11694 = v11693[v11784];
    int v11695 = v11693[v11713];
    int v11791 = v11695 + ((int)((unsigned int)(v11695 - v11694) >> 31));
    v11693[v11713] = v11791;
    int * v11697 = v11598->cache_age;
    int v11698 = v11697[v11714];
    int v11793 = v11698 + ((int)((unsigned int)(v11698 - v11694) >> 31));
    v11697[v11714] = v11793;
    int * v11700 = v11598->cache_age;
    v11700[v11784] = 0;
    v11703 = v11784;
  }
  int v11796 = (v11703 * 2) + (((int)((unsigned int)v11602 >> 2)) & 1);
  int v11704 = v11610[v11796];
  int * v11705 = v11598->regs;
  v11705[19] = v11704;
  struct StateT * v11707 = slot_238(v11598);
  return v11707;
}

struct StateT * slot_241(struct StateT * v11849) {
  int v11850 = v11849->timer;
  int v11858 = v11850 + 1;
  v11849->timer = v11858;
  int * v11852 = v11849->regs;
  int v11853 = v11852[12];
  int v11854 = v11852[5];
  int v11862 = v11853 | v11854;
  v11852[12] = v11862;
  struct StateT * v11856 = slot_243(v11849);
  return v11856;
}

struct StateT * slot_160(struct StateT * v7435) {
  int * v7436 = v7435->saved_regs;
  int v7437 = v7436[7];
  int v7438 = v7436[29];
  bool v7466 = v7437 == v7438;
  struct StateT * v7461;
  if (v7466) {
    int v7439 = v7435->timer;
    int v7467 = v7439 + 15;
    v7435->timer = v7467;
    int * v7441 = v7435->saved_regs;
    int v7442 = v7441[28];
    int * v7443 = v7435->regs;
    v7443[28] = v7442;
    int * v7445 = v7435->saved_regs;
    int v7446 = v7445[29];
    int * v7447 = v7435->regs;
    v7447[29] = v7446;
    int * v7449 = v7435->saved_regs;
    int v7450 = v7449[7];
    int * v7451 = v7435->regs;
    v7451[7] = v7450;
    int * v7453 = v7435->saved_regs;
    int v7454 = v7453[5];
    int * v7455 = v7435->regs;
    v7455[5] = v7454;
    struct StateT * v7457 = slot_161(v7435);
    v7461 = v7457;
  } else {
    struct StateT * v7459 = slot_162(v7435);
    v7461 = v7459;
  }
  return v7461;
}

struct StateT * slot_65(struct StateT * v3663) {
  int * v3664 = v3663->saved_regs;
  int * v3665 = v3663->regs;
  int v3666 = v3665[28];
  v3664[28] = v3666;
  int v3668 = v3663->timer;
  int v3684 = v3668 + 1;
  v3663->timer = v3684;
  int * v3670 = v3663->regs;
  int v3671 = v3670[7];
  int v3672 = v3670[29];
  bool v3688 = (v3671 ^ -2147483648) < (v3672 ^ -2147483648);
  int v3675;
  if (v3688) {
    v3675 = 1;
  } else {
    v3675 = 0;
  }
  int * v3676 = v3663->regs;
  v3676[28] = v3675;
  struct StateT * v3678 = slot_66(v3663);
  return v3678;
}

struct StateT * slot_10(struct StateT * v1728) {
  int v1729 = v1728->timer;
  int v1737 = v1729 + 1;
  v1728->timer = v1737;
  int * v1731 = v1728->regs;
  int v1732 = v1731[15];
  int v1733 = v1731[12];
  int v1742 = v1732 * v1733;
  v1731[5] = v1742;
  struct StateT * v1735 = slot_11(v1728);
  return v1735;
}

struct StateT * slot_150(struct StateT * v7229) {
  int v7230 = v7229->timer;
  int v7242 = v7230 + 1;
  v7229->timer = v7242;
  int * v7232 = v7229->regs;
  int v7233 = v7232[5];
  int v7234 = v7232[9];
  bool v7246 = (v7233 ^ -2147483648) < (v7234 ^ -2147483648);
  int v7237;
  if (v7246) {
    v7237 = 1;
  } else {
    v7237 = 0;
  }
  int * v7238 = v7229->regs;
  v7238[31] = v7237;
  struct StateT * v7240 = slot_151(v7229);
  return v7240;
}

struct StateT * slot_74(struct StateT * v4187) {
  int v4188 = v4187->timer;
  int v4358 = v4188 + 1;
  v4187->timer = v4358;
  int * v4190 = v4187->regs;
  int v4191 = v4190[10];
  int v4192 = v4190[29];
  int * v4193 = v4187->cache_tags;
  int v4363 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2;
  int v4194 = v4193[v4363];
  int v4364 = ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4195 = v4193[v4364];
  int v4365 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2);
  int v4196 = v4193[v4365];
  int v4366 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4197 = v4193[v4366];
  int v4198 = v4187->timer;
  int v4367 = v4198 + ((100 ^ (((~(((v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4187->timer = v4367;
  bool v4368 = !(((~(((v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4292;
  if (v4368) {
    int * v4200 = v4187->cache_age;
    int v4370 = ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4201 = v4200[v4370];
    int v4202 = v4200[v4363];
    int v4371 = v4202 + ((int)((unsigned int)(v4202 - v4201) >> 31));
    v4200[v4363] = v4371;
    int * v4204 = v4187->cache_age;
    int v4205 = v4204[v4364];
    int v4373 = v4205 + ((int)((unsigned int)(v4205 - v4201) >> 31));
    v4204[v4364] = v4373;
    int * v4207 = v4187->cache_age;
    v4207[v4370] = 0;
    v4292 = v4370;
  } else {
    int * v4210 = v4187->cache_age;
    int v4377 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2;
    int v4211 = v4210[v4377];
    int * v4212 = v4187->cache_tags;
    int v4213 = v4212[v4377];
    int v4214 = v4210[v4364];
    int v4215 = v4212[v4364];
    bool v4379 = !(((~(((v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v4269;
    if (v4379) {
      int * v4216 = v4187->cache_age;
      int v4381 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v4217 = v4216[v4381];
      int v4218 = v4216[v4365];
      int v4382 = v4218 + ((int)((unsigned int)(v4218 - v4217) >> 31));
      v4216[v4365] = v4382;
      int * v4220 = v4187->cache_age;
      int v4221 = v4220[v4366];
      int v4384 = v4221 + ((int)((unsigned int)(v4221 - v4217) >> 31));
      v4220[v4366] = v4384;
      int * v4223 = v4187->cache_age;
      v4223[v4381] = 0;
      v4269 = v4381;
    } else {
      int * v4226 = v4187->cache_age;
      int v4388 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2);
      int v4227 = v4226[v4388];
      int * v4228 = v4187->cache_tags;
      int v4229 = v4228[v4388];
      int v4230 = v4226[v4366];
      int v4231 = v4228[v4366];
      int * v4232 = v4187->cache_dirty;
      int v4391 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4233 = v4232[v4391];
      bool v4392 = !(v4233 == 0);
      if (v4392) {
        int * v4234 = v4187->cache_tags;
        int v4235 = v4234[v4391];
        int * v4236 = v4187->cache_vals;
        int v4395 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4237 = v4236[v4395];
        int v4396 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4238 = v4236[v4396];
        int * v4239 = v4187->mem;
        int v4398 = v4235 * 2;
        v4239[v4398] = v4237;
        int * v4241 = v4187->mem;
        int v4401 = (v4235 * 2) + 1;
        v4241[v4401] = v4238;
        ;
      } else {
        ;
      }
      int * v4246 = v4187->mem;
      int v4406 = ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2;
      int v4247 = v4246[v4406];
      int v4407 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2) + 1;
      int v4248 = v4246[v4407];
      int * v4249 = v4187->cache_vals;
      int v4409 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4249[v4409] = v4247;
      int * v4251 = v4187->cache_vals;
      int v4412 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4251[v4412] = v4248;
      int * v4253 = v4187->cache_tags;
      int v4415 = (int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1);
      v4253[v4391] = v4415;
      int * v4255 = v4187->cache_dirty;
      v4255[v4391] = 0;
      int * v4257 = v4187->cache_age;
      v4257[v4391] = 1;
      int * v4259 = v4187->cache_age;
      int v4260 = v4259[v4391];
      int v4261 = v4259[v4365];
      int v4421 = v4261 + ((int)((unsigned int)(v4261 - v4260) >> 31));
      v4259[v4365] = v4421;
      int * v4263 = v4187->cache_age;
      int v4264 = v4263[v4366];
      int v4423 = v4264 + ((int)((unsigned int)(v4264 - v4260) >> 31));
      v4263[v4366] = v4423;
      int * v4266 = v4187->cache_age;
      v4266[v4391] = 0;
      v4269 = v4391;
    }
    int * v4270 = v4187->cache_vals;
    int v4426 = v4269 * 2;
    int v4271 = v4270[v4426];
    int v4427 = (v4269 * 2) + 1;
    int v4272 = v4270[v4427];
    int v4428 = (((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4211 + ((~(((v4213 ^ -1) | (-(v4213 ^ -1))) >> 31)) & 2)) - (v4214 + ((~(((v4215 ^ -1) | (-(v4215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4270[v4428] = v4271;
    int * v4274 = v4187->cache_vals;
    int v4431 = ((((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4211 + ((~(((v4213 ^ -1) | (-(v4213 ^ -1))) >> 31)) & 2)) - (v4214 + ((~(((v4215 ^ -1) | (-(v4215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4274[v4431] = v4272;
    int * v4276 = v4187->cache_tags;
    int v4434 = ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4211 + ((~(((v4213 ^ -1) | (-(v4213 ^ -1))) >> 31)) & 2)) - (v4214 + ((~(((v4215 ^ -1) | (-(v4215 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4435 = (int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1);
    v4276[v4434] = v4435;
    int * v4278 = v4187->cache_dirty;
    v4278[v4434] = 0;
    int * v4280 = v4187->cache_age;
    v4280[v4434] = 1;
    int * v4282 = v4187->cache_age;
    int v4283 = v4282[v4434];
    int v4284 = v4282[v4363];
    int v4441 = v4284 + ((int)((unsigned int)(v4284 - v4283) >> 31));
    v4282[v4363] = v4441;
    int * v4286 = v4187->cache_age;
    int v4287 = v4286[v4364];
    int v4443 = v4287 + ((int)((unsigned int)(v4287 - v4283) >> 31));
    v4286[v4364] = v4443;
    int * v4289 = v4187->cache_age;
    v4289[v4434] = 0;
    v4292 = v4434;
  }
  int * v4293 = v4187->cache_vals;
  int v4446 = (v4292 * 2) + (((int)((unsigned int)(v4191 + 12) >> 2)) & 1);
  v4293[v4446] = v4192;
  int * v4295 = v4187->cache_tags;
  int v4296 = v4295[v4365];
  int v4297 = v4295[v4366];
  bool v4449 = !(((~(((v4296 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4296 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4351;
  if (v4449) {
    int * v4298 = v4187->cache_age;
    int v4451 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4299 = v4298[v4451];
    int v4300 = v4298[v4365];
    int v4452 = v4300 + ((int)((unsigned int)(v4300 - v4299) >> 31));
    v4298[v4365] = v4452;
    int * v4302 = v4187->cache_age;
    int v4303 = v4302[v4366];
    int v4454 = v4303 + ((int)((unsigned int)(v4303 - v4299) >> 31));
    v4302[v4366] = v4454;
    int * v4305 = v4187->cache_age;
    v4305[v4451] = 0;
    v4351 = v4451;
  } else {
    int * v4308 = v4187->cache_age;
    int v4458 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2);
    int v4309 = v4308[v4458];
    int * v4310 = v4187->cache_tags;
    int v4311 = v4310[v4458];
    int v4312 = v4308[v4366];
    int v4313 = v4310[v4366];
    int * v4314 = v4187->cache_dirty;
    int v4461 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4315 = v4314[v4461];
    bool v4462 = !(v4315 == 0);
    if (v4462) {
      int * v4316 = v4187->cache_tags;
      int v4317 = v4316[v4461];
      int * v4318 = v4187->cache_vals;
      int v4465 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4319 = v4318[v4465];
      int v4466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4320 = v4318[v4466];
      int * v4321 = v4187->mem;
      int v4468 = v4317 * 2;
      v4321[v4468] = v4319;
      int * v4323 = v4187->mem;
      int v4471 = (v4317 * 2) + 1;
      v4323[v4471] = v4320;
      ;
    } else {
      ;
    }
    int * v4328 = v4187->mem;
    int v4476 = ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2;
    int v4329 = v4328[v4476];
    int v4477 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2) + 1;
    int v4330 = v4328[v4477];
    int * v4331 = v4187->cache_vals;
    int v4479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4331[v4479] = v4329;
    int * v4333 = v4187->cache_vals;
    int v4482 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4333[v4482] = v4330;
    int * v4335 = v4187->cache_tags;
    int v4485 = (int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1);
    v4335[v4461] = v4485;
    int * v4337 = v4187->cache_dirty;
    v4337[v4461] = 0;
    int * v4339 = v4187->cache_age;
    v4339[v4461] = 1;
    int * v4341 = v4187->cache_age;
    int v4342 = v4341[v4461];
    int v4343 = v4341[v4365];
    int v4491 = v4343 + ((int)((unsigned int)(v4343 - v4342) >> 31));
    v4341[v4365] = v4491;
    int * v4345 = v4187->cache_age;
    int v4346 = v4345[v4366];
    int v4493 = v4346 + ((int)((unsigned int)(v4346 - v4342) >> 31));
    v4345[v4366] = v4493;
    int * v4348 = v4187->cache_age;
    v4348[v4461] = 0;
    v4351 = v4461;
  }
  int * v4352 = v4187->cache_vals;
  int v4496 = (v4351 * 2) + (((int)((unsigned int)(v4191 + 12) >> 2)) & 1);
  v4352[v4496] = v4192;
  int * v4354 = v4187->cache_dirty;
  v4354[v4351] = 1;
  struct StateT * v4356 = slot_76(v4187);
  return v4356;
}

struct StateT * slot_107(struct StateT * v5446) {
  int v5447 = v5446->timer;
  int v5455 = v5447 + 1;
  v5446->timer = v5455;
  int * v5449 = v5446->regs;
  int v5450 = v5449[30];
  int v5451 = v5449[28];
  int v5460 = v5450 + v5451;
  v5449[7] = v5460;
  struct StateT * v5453 = slot_108(v5446);
  return v5453;
}

struct StateT * slot_136(struct StateT * v6965) {
  int v6966 = v6965->timer;
  int v6974 = v6966 + 1;
  v6965->timer = v6974;
  int * v6968 = v6965->regs;
  int v6969 = v6968[29];
  int v6970 = v6968[13];
  int v6979 = (((((int)((unsigned int)v6969 >> 16)) * ((int)((unsigned int)v6970 >> 16))) + ((int)((unsigned int)((v6969 & 65535) * ((int)((unsigned int)v6970 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6969 >> 16)) * (v6970 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6969 & 65535) * (v6970 & 65535)) >> 16)) + (((v6969 & 65535) * ((int)((unsigned int)v6970 >> 16))) & 65535)) + ((((int)((unsigned int)v6969 >> 16)) * (v6970 & 65535)) & 65535)) >> 16));
  v6968[18] = v6979;
  struct StateT * v6972 = slot_137(v6965);
  return v6972;
}

struct StateT * slot_84(struct StateT * v5023) {
  int v5024 = v5023->timer;
  int v5032 = v5024 + 1;
  v5023->timer = v5032;
  int * v5026 = v5023->regs;
  int v5027 = v5026[5];
  int v5028 = v5026[17];
  int v5036 = v5027 | v5028;
  v5026[5] = v5036;
  struct StateT * v5030 = slot_85(v5023);
  return v5030;
}

struct StateT * slot_28(struct StateT * v2637) {
  int v2638 = v2637->timer;
  int v2748 = v2638 + 1;
  v2637->timer = v2748;
  int * v2640 = v2637->regs;
  int v2641 = v2640[11];
  int * v2642 = v2637->cache_tags;
  int v2752 = (((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2643 = v2642[v2752];
  int v2753 = ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2644 = v2642[v2753];
  int v2754 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2645 = v2642[v2754];
  int v2755 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2646 = v2642[v2755];
  int v2647 = v2637->timer;
  int v2756 = v2647 + ((100 ^ (((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2637->timer = v2756;
  int * v2649 = v2637->cache_vals;
  bool v2757 = !(((~(((v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2742;
  if (v2757) {
    int * v2650 = v2637->cache_age;
    int v2759 = ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2651 = v2650[v2759];
    int v2652 = v2650[v2752];
    int v2760 = v2652 + ((int)((unsigned int)(v2652 - v2651) >> 31));
    v2650[v2752] = v2760;
    int * v2654 = v2637->cache_age;
    int v2655 = v2654[v2753];
    int v2762 = v2655 + ((int)((unsigned int)(v2655 - v2651) >> 31));
    v2654[v2753] = v2762;
    int * v2657 = v2637->cache_age;
    v2657[v2759] = 0;
    v2742 = v2759;
  } else {
    int * v2660 = v2637->cache_age;
    int v2766 = (((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2661 = v2660[v2766];
    int * v2662 = v2637->cache_tags;
    int v2663 = v2662[v2766];
    int v2664 = v2660[v2753];
    int v2665 = v2662[v2753];
    bool v2768 = !(((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2719;
    if (v2768) {
      int * v2666 = v2637->cache_age;
      int v2770 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2667 = v2666[v2770];
      int v2668 = v2666[v2754];
      int v2771 = v2668 + ((int)((unsigned int)(v2668 - v2667) >> 31));
      v2666[v2754] = v2771;
      int * v2670 = v2637->cache_age;
      int v2671 = v2670[v2755];
      int v2773 = v2671 + ((int)((unsigned int)(v2671 - v2667) >> 31));
      v2670[v2755] = v2773;
      int * v2673 = v2637->cache_age;
      v2673[v2770] = 0;
      v2719 = v2770;
    } else {
      int * v2676 = v2637->cache_age;
      int v2777 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2677 = v2676[v2777];
      int * v2678 = v2637->cache_tags;
      int v2679 = v2678[v2777];
      int v2680 = v2676[v2755];
      int v2681 = v2678[v2755];
      int * v2682 = v2637->cache_dirty;
      int v2780 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2683 = v2682[v2780];
      bool v2781 = !(v2683 == 0);
      if (v2781) {
        int * v2684 = v2637->cache_tags;
        int v2685 = v2684[v2780];
        int * v2686 = v2637->cache_vals;
        int v2784 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2687 = v2686[v2784];
        int v2785 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2688 = v2686[v2785];
        int * v2689 = v2637->mem;
        int v2787 = v2685 * 2;
        v2689[v2787] = v2687;
        int * v2691 = v2637->mem;
        int v2790 = (v2685 * 2) + 1;
        v2691[v2790] = v2688;
        ;
      } else {
        ;
      }
      int * v2696 = v2637->mem;
      int v2795 = ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) * 2;
      int v2697 = v2696[v2795];
      int v2796 = (((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2698 = v2696[v2796];
      int * v2699 = v2637->cache_vals;
      int v2798 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2699[v2798] = v2697;
      int * v2701 = v2637->cache_vals;
      int v2801 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2701[v2801] = v2698;
      int * v2703 = v2637->cache_tags;
      int v2804 = (int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1);
      v2703[v2780] = v2804;
      int * v2705 = v2637->cache_dirty;
      v2705[v2780] = 0;
      int * v2707 = v2637->cache_age;
      v2707[v2780] = 1;
      int * v2709 = v2637->cache_age;
      int v2710 = v2709[v2780];
      int v2711 = v2709[v2754];
      int v2810 = v2711 + ((int)((unsigned int)(v2711 - v2710) >> 31));
      v2709[v2754] = v2810;
      int * v2713 = v2637->cache_age;
      int v2714 = v2713[v2755];
      int v2812 = v2714 + ((int)((unsigned int)(v2714 - v2710) >> 31));
      v2713[v2755] = v2812;
      int * v2716 = v2637->cache_age;
      v2716[v2780] = 0;
      v2719 = v2780;
    }
    int * v2720 = v2637->cache_vals;
    int v2815 = v2719 * 2;
    int v2721 = v2720[v2815];
    int v2816 = (v2719 * 2) + 1;
    int v2722 = v2720[v2816];
    int v2817 = (((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2661 + ((~(((v2663 ^ -1) | (-(v2663 ^ -1))) >> 31)) & 2)) - (v2664 + ((~(((v2665 ^ -1) | (-(v2665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2720[v2817] = v2721;
    int * v2724 = v2637->cache_vals;
    int v2820 = ((((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2661 + ((~(((v2663 ^ -1) | (-(v2663 ^ -1))) >> 31)) & 2)) - (v2664 + ((~(((v2665 ^ -1) | (-(v2665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2724[v2820] = v2722;
    int * v2726 = v2637->cache_tags;
    int v2823 = ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2661 + ((~(((v2663 ^ -1) | (-(v2663 ^ -1))) >> 31)) & 2)) - (v2664 + ((~(((v2665 ^ -1) | (-(v2665 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2824 = (int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1);
    v2726[v2823] = v2824;
    int * v2728 = v2637->cache_dirty;
    v2728[v2823] = 0;
    int * v2730 = v2637->cache_age;
    v2730[v2823] = 1;
    int * v2732 = v2637->cache_age;
    int v2733 = v2732[v2823];
    int v2734 = v2732[v2752];
    int v2830 = v2734 + ((int)((unsigned int)(v2734 - v2733) >> 31));
    v2732[v2752] = v2830;
    int * v2736 = v2637->cache_age;
    int v2737 = v2736[v2753];
    int v2832 = v2737 + ((int)((unsigned int)(v2737 - v2733) >> 31));
    v2736[v2753] = v2832;
    int * v2739 = v2637->cache_age;
    v2739[v2823] = 0;
    v2742 = v2823;
  }
  int v2835 = (v2742 * 2) + (((int)((unsigned int)(v2641 + 8) >> 2)) & 1);
  int v2743 = v2649[v2835];
  int * v2744 = v2637->regs;
  v2744[7] = v2743;
  struct StateT * v2746 = slot_29(v2637);
  return v2746;
}

struct StateT * slot_155(struct StateT * v7311) {
  int * v7312 = v7311->saved_regs;
  int * v7313 = v7311->regs;
  int v7314 = v7313[28];
  v7312[28] = v7314;
  int v7316 = v7311->timer;
  int v7332 = v7316 + 1;
  v7311->timer = v7332;
  int * v7318 = v7311->regs;
  int v7319 = v7318[7];
  int v7320 = v7318[29];
  bool v7336 = (v7319 ^ -2147483648) < (v7320 ^ -2147483648);
  int v7323;
  if (v7336) {
    v7323 = 1;
  } else {
    v7323 = 0;
  }
  int * v7324 = v7311->regs;
  v7324[28] = v7323;
  struct StateT * v7326 = slot_156(v7311);
  return v7326;
}

struct StateT * slot_177(struct StateT * v8720) {
  int v8721 = v8720->timer;
  int v8729 = v8721 + 1;
  v8720->timer = v8729;
  int * v8723 = v8720->regs;
  int v8724 = v8723[11];
  int v8725 = v8723[12];
  int v8734 = (((((int)((unsigned int)v8724 >> 16)) * ((int)((unsigned int)v8725 >> 16))) + ((int)((unsigned int)((v8724 & 65535) * ((int)((unsigned int)v8725 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8724 >> 16)) * (v8725 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8724 & 65535) * (v8725 & 65535)) >> 16)) + (((v8724 & 65535) * ((int)((unsigned int)v8725 >> 16))) & 65535)) + ((((int)((unsigned int)v8724 >> 16)) * (v8725 & 65535)) & 65535)) >> 16));
  v8723[29] = v8734;
  struct StateT * v8727 = slot_178(v8720);
  return v8727;
}

struct StateT * slot_229(struct StateT * v10926) {
  int v10927 = v10926->timer;
  int v10935 = v10927 + 1;
  v10926->timer = v10935;
  int * v10929 = v10926->regs;
  int v10930 = v10929[13];
  int v10931 = v10929[12];
  int v10939 = v10930 + v10931;
  v10929[12] = v10939;
  struct StateT * v10933 = slot_231(v10926);
  return v10933;
}

struct StateT * slot_17(struct StateT * v1846) {
  int v1847 = v1846->timer;
  int v1855 = v1847 + 1;
  v1846->timer = v1855;
  int * v1849 = v1846->regs;
  int v1850 = v1849[5];
  int v1851 = v1849[17];
  int v1859 = v1850 + v1851;
  v1849[17] = v1859;
  struct StateT * v1853 = slot_18(v1846);
  return v1853;
}

struct StateT * slot_181(struct StateT * v8788) {
  int v8789 = v8788->timer;
  int v8797 = v8789 + 1;
  v8788->timer = v8797;
  int * v8791 = v8788->regs;
  int v8792 = v8791[11];
  int v8793 = v8791[13];
  int v8801 = (((((int)((unsigned int)v8792 >> 16)) * ((int)((unsigned int)v8793 >> 16))) + ((int)((unsigned int)((v8792 & 65535) * ((int)((unsigned int)v8793 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8792 >> 16)) * (v8793 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8792 & 65535) * (v8793 & 65535)) >> 16)) + (((v8792 & 65535) * ((int)((unsigned int)v8793 >> 16))) & 65535)) + ((((int)((unsigned int)v8792 >> 16)) * (v8793 & 65535)) & 65535)) >> 16));
  v8791[13] = v8801;
  struct StateT * v8795 = slot_182(v8788);
  return v8795;
}

struct StateT * slot_197(struct StateT * v9092) {
  int v9093 = v9092->timer;
  int v9101 = v9093 + 1;
  v9092->timer = v9101;
  int * v9095 = v9092->regs;
  int v9096 = v9095[17];
  int v9097 = v9095[5];
  int v9105 = v9096 + v9097;
  v9095[17] = v9105;
  struct StateT * v9099 = slot_198(v9092);
  return v9099;
}

struct StateT * slot_207(struct StateT * v9293) {
  int v9294 = v9293->timer;
  int v9302 = v9294 + 1;
  v9293->timer = v9302;
  int * v9296 = v9293->regs;
  int v9297 = v9296[17];
  int v9298 = v9296[13];
  int v9306 = v9297 | v9298;
  v9296[13] = v9306;
  struct StateT * v9300 = slot_208(v9293);
  return v9300;
}

struct StateT * slot_156(struct StateT * v7343) {
  int v7344 = v7343->timer;
  int v7352 = v7344 + 1;
  v7343->timer = v7352;
  int * v7346 = v7343->regs;
  int v7347 = v7346[5];
  int v7348 = v7346[28];
  int v7356 = v7347 + v7348;
  v7346[28] = v7356;
  struct StateT * v7350 = slot_157(v7343);
  return v7350;
}

struct StateT * slot_154(struct StateT * v7303) {
  int v7304 = v7303->timer;
  int v7308 = v7304 + 1;
  v7303->timer = v7308;
  struct StateT * v7306 = slot_155(v7303);
  return v7306;
}

struct StateT * slot_68(struct StateT * v3735) {
  int * v3736 = v3735->saved_regs;
  int * v3737 = v3735->regs;
  int v3738 = v3737[7];
  v3736[7] = v3738;
  int v3740 = v3735->timer;
  int v3751 = v3740 + 1;
  v3735->timer = v3751;
  int * v3742 = v3735->regs;
  int v3743 = v3742[7];
  int v3753 = (int)((unsigned int)v3743 >> 19);
  v3742[7] = v3753;
  struct StateT * v3745 = slot_69(v3735);
  return v3745;
}

struct StateT * slot_105(struct StateT * v5405) {
  int v5406 = v5405->timer;
  int v5418 = v5406 + 1;
  v5405->timer = v5418;
  int * v5408 = v5405->regs;
  int v5409 = v5408[5];
  int v5410 = v5408[9];
  bool v5422 = (v5409 ^ -2147483648) < (v5410 ^ -2147483648);
  int v5413;
  if (v5422) {
    v5413 = 1;
  } else {
    v5413 = 0;
  }
  int * v5414 = v5405->regs;
  v5414[31] = v5413;
  struct StateT * v5416 = slot_106(v5405);
  return v5416;
}

struct StateT * slot_27(struct StateT * v2621) {
  int v2622 = v2621->timer;
  int v2630 = v2622 + 1;
  v2621->timer = v2630;
  int * v2624 = v2621->regs;
  int v2625 = v2624[6];
  int v2626 = v2624[5];
  int v2634 = v2625 + v2626;
  v2624[5] = v2634;
  struct StateT * v2628 = slot_28(v2621);
  return v2628;
}

struct StateT * slot_164(struct StateT * v7835) {
  int v7836 = v7835->timer;
  int v8006 = v7836 + 1;
  v7835->timer = v8006;
  int * v7838 = v7835->regs;
  int v7839 = v7838[10];
  int v7840 = v7838[29];
  int * v7841 = v7835->cache_tags;
  int v8011 = (((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2;
  int v7842 = v7841[v8011];
  int v8012 = ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7843 = v7841[v8012];
  int v8013 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2);
  int v7844 = v7841[v8013];
  int v8014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7845 = v7841[v8014];
  int v7846 = v7835->timer;
  int v8015 = v7846 + ((100 ^ (((~(((v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7842 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7842 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7843 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7843 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7835->timer = v8015;
  bool v8016 = !(((~(((v7842 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7842 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7843 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7843 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v7940;
  if (v8016) {
    int * v7848 = v7835->cache_age;
    int v8018 = ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v7843 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7843 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7849 = v7848[v8018];
    int v7850 = v7848[v8011];
    int v8019 = v7850 + ((int)((unsigned int)(v7850 - v7849) >> 31));
    v7848[v8011] = v8019;
    int * v7852 = v7835->cache_age;
    int v7853 = v7852[v8012];
    int v8021 = v7853 + ((int)((unsigned int)(v7853 - v7849) >> 31));
    v7852[v8012] = v8021;
    int * v7855 = v7835->cache_age;
    v7855[v8018] = 0;
    v7940 = v8018;
  } else {
    int * v7858 = v7835->cache_age;
    int v8025 = (((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2;
    int v7859 = v7858[v8025];
    int * v7860 = v7835->cache_tags;
    int v7861 = v7860[v8025];
    int v7862 = v7858[v8012];
    int v7863 = v7860[v8012];
    bool v8027 = !(((~(((v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v7917;
    if (v8027) {
      int * v7864 = v7835->cache_age;
      int v8029 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v7865 = v7864[v8029];
      int v7866 = v7864[v8013];
      int v8030 = v7866 + ((int)((unsigned int)(v7866 - v7865) >> 31));
      v7864[v8013] = v8030;
      int * v7868 = v7835->cache_age;
      int v7869 = v7868[v8014];
      int v8032 = v7869 + ((int)((unsigned int)(v7869 - v7865) >> 31));
      v7868[v8014] = v8032;
      int * v7871 = v7835->cache_age;
      v7871[v8029] = 0;
      v7917 = v8029;
    } else {
      int * v7874 = v7835->cache_age;
      int v8036 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2);
      int v7875 = v7874[v8036];
      int * v7876 = v7835->cache_tags;
      int v7877 = v7876[v8036];
      int v7878 = v7874[v8014];
      int v7879 = v7876[v8014];
      int * v7880 = v7835->cache_dirty;
      int v8039 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7875 + ((~(((v7877 ^ -1) | (-(v7877 ^ -1))) >> 31)) & 2)) - (v7878 + ((~(((v7879 ^ -1) | (-(v7879 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7881 = v7880[v8039];
      bool v8040 = !(v7881 == 0);
      if (v8040) {
        int * v7882 = v7835->cache_tags;
        int v7883 = v7882[v8039];
        int * v7884 = v7835->cache_vals;
        int v8043 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7875 + ((~(((v7877 ^ -1) | (-(v7877 ^ -1))) >> 31)) & 2)) - (v7878 + ((~(((v7879 ^ -1) | (-(v7879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7885 = v7884[v8043];
        int v8044 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7875 + ((~(((v7877 ^ -1) | (-(v7877 ^ -1))) >> 31)) & 2)) - (v7878 + ((~(((v7879 ^ -1) | (-(v7879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7886 = v7884[v8044];
        int * v7887 = v7835->mem;
        int v8046 = v7883 * 2;
        v7887[v8046] = v7885;
        int * v7889 = v7835->mem;
        int v8049 = (v7883 * 2) + 1;
        v7889[v8049] = v7886;
        ;
      } else {
        ;
      }
      int * v7894 = v7835->mem;
      int v8054 = ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) * 2;
      int v7895 = v7894[v8054];
      int v8055 = (((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) * 2) + 1;
      int v7896 = v7894[v8055];
      int * v7897 = v7835->cache_vals;
      int v8057 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7875 + ((~(((v7877 ^ -1) | (-(v7877 ^ -1))) >> 31)) & 2)) - (v7878 + ((~(((v7879 ^ -1) | (-(v7879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7897[v8057] = v7895;
      int * v7899 = v7835->cache_vals;
      int v8060 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7875 + ((~(((v7877 ^ -1) | (-(v7877 ^ -1))) >> 31)) & 2)) - (v7878 + ((~(((v7879 ^ -1) | (-(v7879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7899[v8060] = v7896;
      int * v7901 = v7835->cache_tags;
      int v8063 = (int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1);
      v7901[v8039] = v8063;
      int * v7903 = v7835->cache_dirty;
      v7903[v8039] = 0;
      int * v7905 = v7835->cache_age;
      v7905[v8039] = 1;
      int * v7907 = v7835->cache_age;
      int v7908 = v7907[v8039];
      int v7909 = v7907[v8013];
      int v8069 = v7909 + ((int)((unsigned int)(v7909 - v7908) >> 31));
      v7907[v8013] = v8069;
      int * v7911 = v7835->cache_age;
      int v7912 = v7911[v8014];
      int v8071 = v7912 + ((int)((unsigned int)(v7912 - v7908) >> 31));
      v7911[v8014] = v8071;
      int * v7914 = v7835->cache_age;
      v7914[v8039] = 0;
      v7917 = v8039;
    }
    int * v7918 = v7835->cache_vals;
    int v8074 = v7917 * 2;
    int v7919 = v7918[v8074];
    int v8075 = (v7917 * 2) + 1;
    int v7920 = v7918[v8075];
    int v8076 = (((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7859 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2)) - (v7862 + ((~(((v7863 ^ -1) | (-(v7863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7918[v8076] = v7919;
    int * v7922 = v7835->cache_vals;
    int v8079 = ((((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7859 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2)) - (v7862 + ((~(((v7863 ^ -1) | (-(v7863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7922[v8079] = v7920;
    int * v7924 = v7835->cache_tags;
    int v8082 = ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7859 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2)) - (v7862 + ((~(((v7863 ^ -1) | (-(v7863 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8083 = (int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1);
    v7924[v8082] = v8083;
    int * v7926 = v7835->cache_dirty;
    v7926[v8082] = 0;
    int * v7928 = v7835->cache_age;
    v7928[v8082] = 1;
    int * v7930 = v7835->cache_age;
    int v7931 = v7930[v8082];
    int v7932 = v7930[v8011];
    int v8089 = v7932 + ((int)((unsigned int)(v7932 - v7931) >> 31));
    v7930[v8011] = v8089;
    int * v7934 = v7835->cache_age;
    int v7935 = v7934[v8012];
    int v8091 = v7935 + ((int)((unsigned int)(v7935 - v7931) >> 31));
    v7934[v8012] = v8091;
    int * v7937 = v7835->cache_age;
    v7937[v8082] = 0;
    v7940 = v8082;
  }
  int * v7941 = v7835->cache_vals;
  int v8094 = (v7940 * 2) + (((int)((unsigned int)(v7839 + 28) >> 2)) & 1);
  v7941[v8094] = v7840;
  int * v7943 = v7835->cache_tags;
  int v7944 = v7943[v8013];
  int v7945 = v7943[v8014];
  bool v8097 = !(((~(((v7944 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7944 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7945 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7945 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v7999;
  if (v8097) {
    int * v7946 = v7835->cache_age;
    int v8099 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7945 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))) | (-(v7945 ^ ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7947 = v7946[v8099];
    int v7948 = v7946[v8013];
    int v8100 = v7948 + ((int)((unsigned int)(v7948 - v7947) >> 31));
    v7946[v8013] = v8100;
    int * v7950 = v7835->cache_age;
    int v7951 = v7950[v8014];
    int v8102 = v7951 + ((int)((unsigned int)(v7951 - v7947) >> 31));
    v7950[v8014] = v8102;
    int * v7953 = v7835->cache_age;
    v7953[v8099] = 0;
    v7999 = v8099;
  } else {
    int * v7956 = v7835->cache_age;
    int v8106 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2);
    int v7957 = v7956[v8106];
    int * v7958 = v7835->cache_tags;
    int v7959 = v7958[v8106];
    int v7960 = v7956[v8014];
    int v7961 = v7958[v8014];
    int * v7962 = v7835->cache_dirty;
    int v8109 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7957 + ((~(((v7959 ^ -1) | (-(v7959 ^ -1))) >> 31)) & 2)) - (v7960 + ((~(((v7961 ^ -1) | (-(v7961 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7963 = v7962[v8109];
    bool v8110 = !(v7963 == 0);
    if (v8110) {
      int * v7964 = v7835->cache_tags;
      int v7965 = v7964[v8109];
      int * v7966 = v7835->cache_vals;
      int v8113 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7957 + ((~(((v7959 ^ -1) | (-(v7959 ^ -1))) >> 31)) & 2)) - (v7960 + ((~(((v7961 ^ -1) | (-(v7961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7967 = v7966[v8113];
      int v8114 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7957 + ((~(((v7959 ^ -1) | (-(v7959 ^ -1))) >> 31)) & 2)) - (v7960 + ((~(((v7961 ^ -1) | (-(v7961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7968 = v7966[v8114];
      int * v7969 = v7835->mem;
      int v8116 = v7965 * 2;
      v7969[v8116] = v7967;
      int * v7971 = v7835->mem;
      int v8119 = (v7965 * 2) + 1;
      v7971[v8119] = v7968;
      ;
    } else {
      ;
    }
    int * v7976 = v7835->mem;
    int v8124 = ((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) * 2;
    int v7977 = v7976[v8124];
    int v8125 = (((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) * 2) + 1;
    int v7978 = v7976[v8125];
    int * v7979 = v7835->cache_vals;
    int v8127 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7957 + ((~(((v7959 ^ -1) | (-(v7959 ^ -1))) >> 31)) & 2)) - (v7960 + ((~(((v7961 ^ -1) | (-(v7961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7979[v8127] = v7977;
    int * v7981 = v7835->cache_vals;
    int v8130 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7957 + ((~(((v7959 ^ -1) | (-(v7959 ^ -1))) >> 31)) & 2)) - (v7960 + ((~(((v7961 ^ -1) | (-(v7961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7981[v8130] = v7978;
    int * v7983 = v7835->cache_tags;
    int v8133 = (int)((unsigned int)((int)((unsigned int)(v7839 + 28) >> 2)) >> 1);
    v7983[v8109] = v8133;
    int * v7985 = v7835->cache_dirty;
    v7985[v8109] = 0;
    int * v7987 = v7835->cache_age;
    v7987[v8109] = 1;
    int * v7989 = v7835->cache_age;
    int v7990 = v7989[v8109];
    int v7991 = v7989[v8013];
    int v8139 = v7991 + ((int)((unsigned int)(v7991 - v7990) >> 31));
    v7989[v8013] = v8139;
    int * v7993 = v7835->cache_age;
    int v7994 = v7993[v8014];
    int v8141 = v7994 + ((int)((unsigned int)(v7994 - v7990) >> 31));
    v7993[v8014] = v8141;
    int * v7996 = v7835->cache_age;
    v7996[v8109] = 0;
    v7999 = v8109;
  }
  int * v8000 = v7835->cache_vals;
  int v8144 = (v7999 * 2) + (((int)((unsigned int)(v7839 + 28) >> 2)) & 1);
  v8000[v8144] = v7840;
  int * v8002 = v7835->cache_dirty;
  v8002[v7999] = 1;
  struct StateT * v8004 = slot_166(v7835);
  return v8004;
}

struct StateT * slot_15(struct StateT * v1813) {
  int v1814 = v1813->timer;
  int v1822 = v1814 + 1;
  v1813->timer = v1822;
  int * v1816 = v1813->regs;
  int v1817 = v1816[15];
  int v1818 = v1816[13];
  int v1827 = (((((int)((unsigned int)v1817 >> 16)) * ((int)((unsigned int)v1818 >> 16))) + ((int)((unsigned int)((v1817 & 65535) * ((int)((unsigned int)v1818 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1817 >> 16)) * (v1818 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1817 & 65535) * (v1818 & 65535)) >> 16)) + (((v1817 & 65535) * ((int)((unsigned int)v1818 >> 16))) & 65535)) + ((((int)((unsigned int)v1817 >> 16)) * (v1818 & 65535)) & 65535)) >> 16));
  v1816[30] = v1827;
  struct StateT * v1820 = slot_16(v1813);
  return v1820;
}

struct StateT * slot_133(struct StateT * v6914) {
  int v6915 = v6914->timer;
  int v6923 = v6915 + 1;
  v6914->timer = v6923;
  int * v6917 = v6914->regs;
  int v6918 = v6917[6];
  int v6919 = v6917[13];
  int v6928 = v6918 * v6919;
  v6917[31] = v6928;
  struct StateT * v6921 = slot_134(v6914);
  return v6921;
}

struct StateT * slot_56(struct StateT * v3509) {
  int v3510 = v3509->timer;
  int v3518 = v3510 + 1;
  v3509->timer = v3518;
  int * v3512 = v3509->regs;
  int v3513 = v3512[9];
  int v3514 = v3512[6];
  int v3522 = v3513 + v3514;
  v3512[6] = v3522;
  struct StateT * v3516 = slot_57(v3509);
  return v3516;
}

struct StateT * slot_244(struct StateT * v11882) {
  int v11883 = v11882->timer;
  int v11891 = v11883 + 1;
  v11882->timer = v11891;
  int * v11885 = v11882->regs;
  int v11886 = v11885[13];
  int v11887 = v11885[17];
  int v11895 = v11886 * v11887;
  v11885[13] = v11895;
  struct StateT * v11889 = slot_245(v11882);
  return v11889;
}

struct StateT * slot_222(struct StateT * v9612) {
  int v9613 = v9612->timer;
  int v9783 = v9613 + 1;
  v9612->timer = v9783;
  int * v9615 = v9612->regs;
  int v9616 = v9615[10];
  int v9617 = v9615[13];
  int * v9618 = v9612->cache_tags;
  int v9788 = (((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2;
  int v9619 = v9618[v9788];
  int v9789 = ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9620 = v9618[v9789];
  int v9790 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2);
  int v9621 = v9618[v9790];
  int v9791 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9622 = v9618[v9791];
  int v9623 = v9612->timer;
  int v9792 = v9623 + ((100 ^ (((~(((v9621 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9621 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) | (~(((v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9619 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9619 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) | (~(((v9620 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9620 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9621 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9621 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) | (~(((v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31))) & 104)))));
  v9612->timer = v9792;
  bool v9793 = !(((~(((v9619 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9619 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) | (~(((v9620 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9620 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31))) == 0);
  int v9717;
  if (v9793) {
    int * v9625 = v9612->cache_age;
    int v9795 = ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2) + ((~(((v9620 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9620 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) & 1);
    int v9626 = v9625[v9795];
    int v9627 = v9625[v9788];
    int v9796 = v9627 + ((int)((unsigned int)(v9627 - v9626) >> 31));
    v9625[v9788] = v9796;
    int * v9629 = v9612->cache_age;
    int v9630 = v9629[v9789];
    int v9798 = v9630 + ((int)((unsigned int)(v9630 - v9626) >> 31));
    v9629[v9789] = v9798;
    int * v9632 = v9612->cache_age;
    v9632[v9795] = 0;
    v9717 = v9795;
  } else {
    int * v9635 = v9612->cache_age;
    int v9802 = (((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2;
    int v9636 = v9635[v9802];
    int * v9637 = v9612->cache_tags;
    int v9638 = v9637[v9802];
    int v9639 = v9635[v9789];
    int v9640 = v9637[v9789];
    bool v9804 = !(((~(((v9621 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9621 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) | (~(((v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31))) == 0);
    int v9694;
    if (v9804) {
      int * v9641 = v9612->cache_age;
      int v9806 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9622 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) & 1);
      int v9642 = v9641[v9806];
      int v9643 = v9641[v9790];
      int v9807 = v9643 + ((int)((unsigned int)(v9643 - v9642) >> 31));
      v9641[v9790] = v9807;
      int * v9645 = v9612->cache_age;
      int v9646 = v9645[v9791];
      int v9809 = v9646 + ((int)((unsigned int)(v9646 - v9642) >> 31));
      v9645[v9791] = v9809;
      int * v9648 = v9612->cache_age;
      v9648[v9806] = 0;
      v9694 = v9806;
    } else {
      int * v9651 = v9612->cache_age;
      int v9813 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2);
      int v9652 = v9651[v9813];
      int * v9653 = v9612->cache_tags;
      int v9654 = v9653[v9813];
      int v9655 = v9651[v9791];
      int v9656 = v9653[v9791];
      int * v9657 = v9612->cache_dirty;
      int v9816 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9658 = v9657[v9816];
      bool v9817 = !(v9658 == 0);
      if (v9817) {
        int * v9659 = v9612->cache_tags;
        int v9660 = v9659[v9816];
        int * v9661 = v9612->cache_vals;
        int v9820 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9662 = v9661[v9820];
        int v9821 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9663 = v9661[v9821];
        int * v9664 = v9612->mem;
        int v9823 = v9660 * 2;
        v9664[v9823] = v9662;
        int * v9666 = v9612->mem;
        int v9826 = (v9660 * 2) + 1;
        v9666[v9826] = v9663;
        ;
      } else {
        ;
      }
      int * v9671 = v9612->mem;
      int v9831 = ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) * 2;
      int v9672 = v9671[v9831];
      int v9832 = (((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) * 2) + 1;
      int v9673 = v9671[v9832];
      int * v9674 = v9612->cache_vals;
      int v9834 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9674[v9834] = v9672;
      int * v9676 = v9612->cache_vals;
      int v9837 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9652 + ((~(((v9654 ^ -1) | (-(v9654 ^ -1))) >> 31)) & 2)) - (v9655 + ((~(((v9656 ^ -1) | (-(v9656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9676[v9837] = v9673;
      int * v9678 = v9612->cache_tags;
      int v9840 = (int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1);
      v9678[v9816] = v9840;
      int * v9680 = v9612->cache_dirty;
      v9680[v9816] = 0;
      int * v9682 = v9612->cache_age;
      v9682[v9816] = 1;
      int * v9684 = v9612->cache_age;
      int v9685 = v9684[v9816];
      int v9686 = v9684[v9790];
      int v9846 = v9686 + ((int)((unsigned int)(v9686 - v9685) >> 31));
      v9684[v9790] = v9846;
      int * v9688 = v9612->cache_age;
      int v9689 = v9688[v9791];
      int v9848 = v9689 + ((int)((unsigned int)(v9689 - v9685) >> 31));
      v9688[v9791] = v9848;
      int * v9691 = v9612->cache_age;
      v9691[v9816] = 0;
      v9694 = v9816;
    }
    int * v9695 = v9612->cache_vals;
    int v9851 = v9694 * 2;
    int v9696 = v9695[v9851];
    int v9852 = (v9694 * 2) + 1;
    int v9697 = v9695[v9852];
    int v9853 = (((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2) + ((((v9636 + ((~(((v9638 ^ -1) | (-(v9638 ^ -1))) >> 31)) & 2)) - (v9639 + ((~(((v9640 ^ -1) | (-(v9640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9695[v9853] = v9696;
    int * v9699 = v9612->cache_vals;
    int v9856 = ((((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2) + ((((v9636 + ((~(((v9638 ^ -1) | (-(v9638 ^ -1))) >> 31)) & 2)) - (v9639 + ((~(((v9640 ^ -1) | (-(v9640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9699[v9856] = v9697;
    int * v9701 = v9612->cache_tags;
    int v9859 = ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 1) * 2) + ((((v9636 + ((~(((v9638 ^ -1) | (-(v9638 ^ -1))) >> 31)) & 2)) - (v9639 + ((~(((v9640 ^ -1) | (-(v9640 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9860 = (int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1);
    v9701[v9859] = v9860;
    int * v9703 = v9612->cache_dirty;
    v9703[v9859] = 0;
    int * v9705 = v9612->cache_age;
    v9705[v9859] = 1;
    int * v9707 = v9612->cache_age;
    int v9708 = v9707[v9859];
    int v9709 = v9707[v9788];
    int v9866 = v9709 + ((int)((unsigned int)(v9709 - v9708) >> 31));
    v9707[v9788] = v9866;
    int * v9711 = v9612->cache_age;
    int v9712 = v9711[v9789];
    int v9868 = v9712 + ((int)((unsigned int)(v9712 - v9708) >> 31));
    v9711[v9789] = v9868;
    int * v9714 = v9612->cache_age;
    v9714[v9859] = 0;
    v9717 = v9859;
  }
  int * v9718 = v9612->cache_vals;
  int v9871 = (v9717 * 2) + (((int)((unsigned int)v9616 >> 2)) & 1);
  v9718[v9871] = v9617;
  int * v9720 = v9612->cache_tags;
  int v9721 = v9720[v9790];
  int v9722 = v9720[v9791];
  bool v9874 = !(((~(((v9721 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9721 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) | (~(((v9722 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9722 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31))) == 0);
  int v9776;
  if (v9874) {
    int * v9723 = v9612->cache_age;
    int v9876 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9722 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))) | (-(v9722 ^ ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1))))) >> 31)) & 1);
    int v9724 = v9723[v9876];
    int v9725 = v9723[v9790];
    int v9877 = v9725 + ((int)((unsigned int)(v9725 - v9724) >> 31));
    v9723[v9790] = v9877;
    int * v9727 = v9612->cache_age;
    int v9728 = v9727[v9791];
    int v9879 = v9728 + ((int)((unsigned int)(v9728 - v9724) >> 31));
    v9727[v9791] = v9879;
    int * v9730 = v9612->cache_age;
    v9730[v9876] = 0;
    v9776 = v9876;
  } else {
    int * v9733 = v9612->cache_age;
    int v9883 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2);
    int v9734 = v9733[v9883];
    int * v9735 = v9612->cache_tags;
    int v9736 = v9735[v9883];
    int v9737 = v9733[v9791];
    int v9738 = v9735[v9791];
    int * v9739 = v9612->cache_dirty;
    int v9886 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9734 + ((~(((v9736 ^ -1) | (-(v9736 ^ -1))) >> 31)) & 2)) - (v9737 + ((~(((v9738 ^ -1) | (-(v9738 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9740 = v9739[v9886];
    bool v9887 = !(v9740 == 0);
    if (v9887) {
      int * v9741 = v9612->cache_tags;
      int v9742 = v9741[v9886];
      int * v9743 = v9612->cache_vals;
      int v9890 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9734 + ((~(((v9736 ^ -1) | (-(v9736 ^ -1))) >> 31)) & 2)) - (v9737 + ((~(((v9738 ^ -1) | (-(v9738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9744 = v9743[v9890];
      int v9891 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9734 + ((~(((v9736 ^ -1) | (-(v9736 ^ -1))) >> 31)) & 2)) - (v9737 + ((~(((v9738 ^ -1) | (-(v9738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9745 = v9743[v9891];
      int * v9746 = v9612->mem;
      int v9893 = v9742 * 2;
      v9746[v9893] = v9744;
      int * v9748 = v9612->mem;
      int v9896 = (v9742 * 2) + 1;
      v9748[v9896] = v9745;
      ;
    } else {
      ;
    }
    int * v9753 = v9612->mem;
    int v9901 = ((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) * 2;
    int v9754 = v9753[v9901];
    int v9902 = (((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) * 2) + 1;
    int v9755 = v9753[v9902];
    int * v9756 = v9612->cache_vals;
    int v9904 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9734 + ((~(((v9736 ^ -1) | (-(v9736 ^ -1))) >> 31)) & 2)) - (v9737 + ((~(((v9738 ^ -1) | (-(v9738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9756[v9904] = v9754;
    int * v9758 = v9612->cache_vals;
    int v9907 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1)) & 3) * 2)) + ((((v9734 + ((~(((v9736 ^ -1) | (-(v9736 ^ -1))) >> 31)) & 2)) - (v9737 + ((~(((v9738 ^ -1) | (-(v9738 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9758[v9907] = v9755;
    int * v9760 = v9612->cache_tags;
    int v9910 = (int)((unsigned int)((int)((unsigned int)v9616 >> 2)) >> 1);
    v9760[v9886] = v9910;
    int * v9762 = v9612->cache_dirty;
    v9762[v9886] = 0;
    int * v9764 = v9612->cache_age;
    v9764[v9886] = 1;
    int * v9766 = v9612->cache_age;
    int v9767 = v9766[v9886];
    int v9768 = v9766[v9790];
    int v9916 = v9768 + ((int)((unsigned int)(v9768 - v9767) >> 31));
    v9766[v9790] = v9916;
    int * v9770 = v9612->cache_age;
    int v9771 = v9770[v9791];
    int v9918 = v9771 + ((int)((unsigned int)(v9771 - v9767) >> 31));
    v9770[v9791] = v9918;
    int * v9773 = v9612->cache_age;
    v9773[v9886] = 0;
    v9776 = v9886;
  }
  int * v9777 = v9612->cache_vals;
  int v9921 = (v9776 * 2) + (((int)((unsigned int)v9616 >> 2)) & 1);
  v9777[v9921] = v9617;
  int * v9779 = v9612->cache_dirty;
  v9779[v9776] = 1;
  struct StateT * v9781 = slot_224(v9612);
  return v9781;
}

struct StateT * slot_34(struct StateT * v3127) {
  int v3128 = v3127->timer;
  int v3135 = v3128 + 1;
  v3127->timer = v3135;
  int * v3130 = v3127->regs;
  int v3131 = v3130[31];
  int v3139 = (int)((unsigned int)v3131 >> 19);
  v3130[29] = v3139;
  struct StateT * v3133 = slot_35(v3127);
  return v3133;
}

struct StateT * slot_171(struct StateT * v8437) {
  int v8438 = v8437->timer;
  int v8548 = v8438 + 1;
  v8437->timer = v8548;
  int * v8440 = v8437->regs;
  int v8441 = v8440[11];
  int * v8442 = v8437->cache_tags;
  int v8552 = (((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2;
  int v8443 = v8442[v8552];
  int v8553 = ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8444 = v8442[v8553];
  int v8554 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2);
  int v8445 = v8442[v8554];
  int v8555 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8446 = v8442[v8555];
  int v8447 = v8437->timer;
  int v8556 = v8447 + ((100 ^ (((~(((v8445 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8445 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8443 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8443 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8444 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8444 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8445 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8445 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8437->timer = v8556;
  int * v8449 = v8437->cache_vals;
  bool v8557 = !(((~(((v8443 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8443 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8444 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8444 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v8542;
  if (v8557) {
    int * v8450 = v8437->cache_age;
    int v8559 = ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v8444 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8444 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v8451 = v8450[v8559];
    int v8452 = v8450[v8552];
    int v8560 = v8452 + ((int)((unsigned int)(v8452 - v8451) >> 31));
    v8450[v8552] = v8560;
    int * v8454 = v8437->cache_age;
    int v8455 = v8454[v8553];
    int v8562 = v8455 + ((int)((unsigned int)(v8455 - v8451) >> 31));
    v8454[v8553] = v8562;
    int * v8457 = v8437->cache_age;
    v8457[v8559] = 0;
    v8542 = v8559;
  } else {
    int * v8460 = v8437->cache_age;
    int v8566 = (((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2;
    int v8461 = v8460[v8566];
    int * v8462 = v8437->cache_tags;
    int v8463 = v8462[v8566];
    int v8464 = v8460[v8553];
    int v8465 = v8462[v8553];
    bool v8568 = !(((~(((v8445 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8445 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v8519;
    if (v8568) {
      int * v8466 = v8437->cache_age;
      int v8570 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))) | (-(v8446 ^ ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v8467 = v8466[v8570];
      int v8468 = v8466[v8554];
      int v8571 = v8468 + ((int)((unsigned int)(v8468 - v8467) >> 31));
      v8466[v8554] = v8571;
      int * v8470 = v8437->cache_age;
      int v8471 = v8470[v8555];
      int v8573 = v8471 + ((int)((unsigned int)(v8471 - v8467) >> 31));
      v8470[v8555] = v8573;
      int * v8473 = v8437->cache_age;
      v8473[v8570] = 0;
      v8519 = v8570;
    } else {
      int * v8476 = v8437->cache_age;
      int v8577 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2);
      int v8477 = v8476[v8577];
      int * v8478 = v8437->cache_tags;
      int v8479 = v8478[v8577];
      int v8480 = v8476[v8555];
      int v8481 = v8478[v8555];
      int * v8482 = v8437->cache_dirty;
      int v8580 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8477 + ((~(((v8479 ^ -1) | (-(v8479 ^ -1))) >> 31)) & 2)) - (v8480 + ((~(((v8481 ^ -1) | (-(v8481 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8483 = v8482[v8580];
      bool v8581 = !(v8483 == 0);
      if (v8581) {
        int * v8484 = v8437->cache_tags;
        int v8485 = v8484[v8580];
        int * v8486 = v8437->cache_vals;
        int v8584 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8477 + ((~(((v8479 ^ -1) | (-(v8479 ^ -1))) >> 31)) & 2)) - (v8480 + ((~(((v8481 ^ -1) | (-(v8481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8487 = v8486[v8584];
        int v8585 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8477 + ((~(((v8479 ^ -1) | (-(v8479 ^ -1))) >> 31)) & 2)) - (v8480 + ((~(((v8481 ^ -1) | (-(v8481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8488 = v8486[v8585];
        int * v8489 = v8437->mem;
        int v8587 = v8485 * 2;
        v8489[v8587] = v8487;
        int * v8491 = v8437->mem;
        int v8590 = (v8485 * 2) + 1;
        v8491[v8590] = v8488;
        ;
      } else {
        ;
      }
      int * v8496 = v8437->mem;
      int v8595 = ((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) * 2;
      int v8497 = v8496[v8595];
      int v8596 = (((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) * 2) + 1;
      int v8498 = v8496[v8596];
      int * v8499 = v8437->cache_vals;
      int v8598 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8477 + ((~(((v8479 ^ -1) | (-(v8479 ^ -1))) >> 31)) & 2)) - (v8480 + ((~(((v8481 ^ -1) | (-(v8481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8499[v8598] = v8497;
      int * v8501 = v8437->cache_vals;
      int v8601 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8477 + ((~(((v8479 ^ -1) | (-(v8479 ^ -1))) >> 31)) & 2)) - (v8480 + ((~(((v8481 ^ -1) | (-(v8481 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8501[v8601] = v8498;
      int * v8503 = v8437->cache_tags;
      int v8604 = (int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1);
      v8503[v8580] = v8604;
      int * v8505 = v8437->cache_dirty;
      v8505[v8580] = 0;
      int * v8507 = v8437->cache_age;
      v8507[v8580] = 1;
      int * v8509 = v8437->cache_age;
      int v8510 = v8509[v8580];
      int v8511 = v8509[v8554];
      int v8610 = v8511 + ((int)((unsigned int)(v8511 - v8510) >> 31));
      v8509[v8554] = v8610;
      int * v8513 = v8437->cache_age;
      int v8514 = v8513[v8555];
      int v8612 = v8514 + ((int)((unsigned int)(v8514 - v8510) >> 31));
      v8513[v8555] = v8612;
      int * v8516 = v8437->cache_age;
      v8516[v8580] = 0;
      v8519 = v8580;
    }
    int * v8520 = v8437->cache_vals;
    int v8615 = v8519 * 2;
    int v8521 = v8520[v8615];
    int v8616 = (v8519 * 2) + 1;
    int v8522 = v8520[v8616];
    int v8617 = (((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8461 + ((~(((v8463 ^ -1) | (-(v8463 ^ -1))) >> 31)) & 2)) - (v8464 + ((~(((v8465 ^ -1) | (-(v8465 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8520[v8617] = v8521;
    int * v8524 = v8437->cache_vals;
    int v8620 = ((((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8461 + ((~(((v8463 ^ -1) | (-(v8463 ^ -1))) >> 31)) & 2)) - (v8464 + ((~(((v8465 ^ -1) | (-(v8465 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8524[v8620] = v8522;
    int * v8526 = v8437->cache_tags;
    int v8623 = ((((int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8461 + ((~(((v8463 ^ -1) | (-(v8463 ^ -1))) >> 31)) & 2)) - (v8464 + ((~(((v8465 ^ -1) | (-(v8465 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8624 = (int)((unsigned int)((int)((unsigned int)(v8441 + 36) >> 2)) >> 1);
    v8526[v8623] = v8624;
    int * v8528 = v8437->cache_dirty;
    v8528[v8623] = 0;
    int * v8530 = v8437->cache_age;
    v8530[v8623] = 1;
    int * v8532 = v8437->cache_age;
    int v8533 = v8532[v8623];
    int v8534 = v8532[v8552];
    int v8630 = v8534 + ((int)((unsigned int)(v8534 - v8533) >> 31));
    v8532[v8552] = v8630;
    int * v8536 = v8437->cache_age;
    int v8537 = v8536[v8553];
    int v8632 = v8537 + ((int)((unsigned int)(v8537 - v8533) >> 31));
    v8536[v8553] = v8632;
    int * v8539 = v8437->cache_age;
    v8539[v8623] = 0;
    v8542 = v8623;
  }
  int v8635 = (v8542 * 2) + (((int)((unsigned int)(v8441 + 36) >> 2)) & 1);
  int v8543 = v8449[v8635];
  int * v8544 = v8437->regs;
  v8544[11] = v8543;
  struct StateT * v8546 = slot_172(v8437);
  return v8546;
}

struct StateT * slot_162(struct StateT * v7503) {
  int v7504 = v7503->timer;
  int v7674 = v7504 + 1;
  v7503->timer = v7674;
  int * v7506 = v7503->regs;
  int v7507 = v7506[10];
  int v7508 = v7506[17];
  int * v7509 = v7503->cache_tags;
  int v7679 = (((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2;
  int v7510 = v7509[v7679];
  int v7680 = ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7511 = v7509[v7680];
  int v7681 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2);
  int v7512 = v7509[v7681];
  int v7682 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7513 = v7509[v7682];
  int v7514 = v7503->timer;
  int v7683 = v7514 + ((100 ^ (((~(((v7512 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7512 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7510 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7510 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7511 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7511 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7512 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7512 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7503->timer = v7683;
  bool v7684 = !(((~(((v7510 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7510 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7511 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7511 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v7608;
  if (v7684) {
    int * v7516 = v7503->cache_age;
    int v7686 = ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v7511 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7511 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v7517 = v7516[v7686];
    int v7518 = v7516[v7679];
    int v7687 = v7518 + ((int)((unsigned int)(v7518 - v7517) >> 31));
    v7516[v7679] = v7687;
    int * v7520 = v7503->cache_age;
    int v7521 = v7520[v7680];
    int v7689 = v7521 + ((int)((unsigned int)(v7521 - v7517) >> 31));
    v7520[v7680] = v7689;
    int * v7523 = v7503->cache_age;
    v7523[v7686] = 0;
    v7608 = v7686;
  } else {
    int * v7526 = v7503->cache_age;
    int v7693 = (((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2;
    int v7527 = v7526[v7693];
    int * v7528 = v7503->cache_tags;
    int v7529 = v7528[v7693];
    int v7530 = v7526[v7680];
    int v7531 = v7528[v7680];
    bool v7695 = !(((~(((v7512 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7512 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v7585;
    if (v7695) {
      int * v7532 = v7503->cache_age;
      int v7697 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7513 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v7533 = v7532[v7697];
      int v7534 = v7532[v7681];
      int v7698 = v7534 + ((int)((unsigned int)(v7534 - v7533) >> 31));
      v7532[v7681] = v7698;
      int * v7536 = v7503->cache_age;
      int v7537 = v7536[v7682];
      int v7700 = v7537 + ((int)((unsigned int)(v7537 - v7533) >> 31));
      v7536[v7682] = v7700;
      int * v7539 = v7503->cache_age;
      v7539[v7697] = 0;
      v7585 = v7697;
    } else {
      int * v7542 = v7503->cache_age;
      int v7704 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2);
      int v7543 = v7542[v7704];
      int * v7544 = v7503->cache_tags;
      int v7545 = v7544[v7704];
      int v7546 = v7542[v7682];
      int v7547 = v7544[v7682];
      int * v7548 = v7503->cache_dirty;
      int v7707 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7543 + ((~(((v7545 ^ -1) | (-(v7545 ^ -1))) >> 31)) & 2)) - (v7546 + ((~(((v7547 ^ -1) | (-(v7547 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7549 = v7548[v7707];
      bool v7708 = !(v7549 == 0);
      if (v7708) {
        int * v7550 = v7503->cache_tags;
        int v7551 = v7550[v7707];
        int * v7552 = v7503->cache_vals;
        int v7711 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7543 + ((~(((v7545 ^ -1) | (-(v7545 ^ -1))) >> 31)) & 2)) - (v7546 + ((~(((v7547 ^ -1) | (-(v7547 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7553 = v7552[v7711];
        int v7712 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7543 + ((~(((v7545 ^ -1) | (-(v7545 ^ -1))) >> 31)) & 2)) - (v7546 + ((~(((v7547 ^ -1) | (-(v7547 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7554 = v7552[v7712];
        int * v7555 = v7503->mem;
        int v7714 = v7551 * 2;
        v7555[v7714] = v7553;
        int * v7557 = v7503->mem;
        int v7717 = (v7551 * 2) + 1;
        v7557[v7717] = v7554;
        ;
      } else {
        ;
      }
      int * v7562 = v7503->mem;
      int v7722 = ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) * 2;
      int v7563 = v7562[v7722];
      int v7723 = (((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) * 2) + 1;
      int v7564 = v7562[v7723];
      int * v7565 = v7503->cache_vals;
      int v7725 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7543 + ((~(((v7545 ^ -1) | (-(v7545 ^ -1))) >> 31)) & 2)) - (v7546 + ((~(((v7547 ^ -1) | (-(v7547 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7565[v7725] = v7563;
      int * v7567 = v7503->cache_vals;
      int v7728 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7543 + ((~(((v7545 ^ -1) | (-(v7545 ^ -1))) >> 31)) & 2)) - (v7546 + ((~(((v7547 ^ -1) | (-(v7547 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7567[v7728] = v7564;
      int * v7569 = v7503->cache_tags;
      int v7731 = (int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1);
      v7569[v7707] = v7731;
      int * v7571 = v7503->cache_dirty;
      v7571[v7707] = 0;
      int * v7573 = v7503->cache_age;
      v7573[v7707] = 1;
      int * v7575 = v7503->cache_age;
      int v7576 = v7575[v7707];
      int v7577 = v7575[v7681];
      int v7737 = v7577 + ((int)((unsigned int)(v7577 - v7576) >> 31));
      v7575[v7681] = v7737;
      int * v7579 = v7503->cache_age;
      int v7580 = v7579[v7682];
      int v7739 = v7580 + ((int)((unsigned int)(v7580 - v7576) >> 31));
      v7579[v7682] = v7739;
      int * v7582 = v7503->cache_age;
      v7582[v7707] = 0;
      v7585 = v7707;
    }
    int * v7586 = v7503->cache_vals;
    int v7742 = v7585 * 2;
    int v7587 = v7586[v7742];
    int v7743 = (v7585 * 2) + 1;
    int v7588 = v7586[v7743];
    int v7744 = (((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7527 + ((~(((v7529 ^ -1) | (-(v7529 ^ -1))) >> 31)) & 2)) - (v7530 + ((~(((v7531 ^ -1) | (-(v7531 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7586[v7744] = v7587;
    int * v7590 = v7503->cache_vals;
    int v7747 = ((((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7527 + ((~(((v7529 ^ -1) | (-(v7529 ^ -1))) >> 31)) & 2)) - (v7530 + ((~(((v7531 ^ -1) | (-(v7531 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7590[v7747] = v7588;
    int * v7592 = v7503->cache_tags;
    int v7750 = ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7527 + ((~(((v7529 ^ -1) | (-(v7529 ^ -1))) >> 31)) & 2)) - (v7530 + ((~(((v7531 ^ -1) | (-(v7531 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7751 = (int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1);
    v7592[v7750] = v7751;
    int * v7594 = v7503->cache_dirty;
    v7594[v7750] = 0;
    int * v7596 = v7503->cache_age;
    v7596[v7750] = 1;
    int * v7598 = v7503->cache_age;
    int v7599 = v7598[v7750];
    int v7600 = v7598[v7679];
    int v7757 = v7600 + ((int)((unsigned int)(v7600 - v7599) >> 31));
    v7598[v7679] = v7757;
    int * v7602 = v7503->cache_age;
    int v7603 = v7602[v7680];
    int v7759 = v7603 + ((int)((unsigned int)(v7603 - v7599) >> 31));
    v7602[v7680] = v7759;
    int * v7605 = v7503->cache_age;
    v7605[v7750] = 0;
    v7608 = v7750;
  }
  int * v7609 = v7503->cache_vals;
  int v7762 = (v7608 * 2) + (((int)((unsigned int)(v7507 + 24) >> 2)) & 1);
  v7609[v7762] = v7508;
  int * v7611 = v7503->cache_tags;
  int v7612 = v7611[v7681];
  int v7613 = v7611[v7682];
  bool v7765 = !(((~(((v7612 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7612 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7613 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7613 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v7667;
  if (v7765) {
    int * v7614 = v7503->cache_age;
    int v7767 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7613 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))) | (-(v7613 ^ ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v7615 = v7614[v7767];
    int v7616 = v7614[v7681];
    int v7768 = v7616 + ((int)((unsigned int)(v7616 - v7615) >> 31));
    v7614[v7681] = v7768;
    int * v7618 = v7503->cache_age;
    int v7619 = v7618[v7682];
    int v7770 = v7619 + ((int)((unsigned int)(v7619 - v7615) >> 31));
    v7618[v7682] = v7770;
    int * v7621 = v7503->cache_age;
    v7621[v7767] = 0;
    v7667 = v7767;
  } else {
    int * v7624 = v7503->cache_age;
    int v7774 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2);
    int v7625 = v7624[v7774];
    int * v7626 = v7503->cache_tags;
    int v7627 = v7626[v7774];
    int v7628 = v7624[v7682];
    int v7629 = v7626[v7682];
    int * v7630 = v7503->cache_dirty;
    int v7777 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7625 + ((~(((v7627 ^ -1) | (-(v7627 ^ -1))) >> 31)) & 2)) - (v7628 + ((~(((v7629 ^ -1) | (-(v7629 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7631 = v7630[v7777];
    bool v7778 = !(v7631 == 0);
    if (v7778) {
      int * v7632 = v7503->cache_tags;
      int v7633 = v7632[v7777];
      int * v7634 = v7503->cache_vals;
      int v7781 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7625 + ((~(((v7627 ^ -1) | (-(v7627 ^ -1))) >> 31)) & 2)) - (v7628 + ((~(((v7629 ^ -1) | (-(v7629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7635 = v7634[v7781];
      int v7782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7625 + ((~(((v7627 ^ -1) | (-(v7627 ^ -1))) >> 31)) & 2)) - (v7628 + ((~(((v7629 ^ -1) | (-(v7629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7636 = v7634[v7782];
      int * v7637 = v7503->mem;
      int v7784 = v7633 * 2;
      v7637[v7784] = v7635;
      int * v7639 = v7503->mem;
      int v7787 = (v7633 * 2) + 1;
      v7639[v7787] = v7636;
      ;
    } else {
      ;
    }
    int * v7644 = v7503->mem;
    int v7792 = ((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) * 2;
    int v7645 = v7644[v7792];
    int v7793 = (((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) * 2) + 1;
    int v7646 = v7644[v7793];
    int * v7647 = v7503->cache_vals;
    int v7795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7625 + ((~(((v7627 ^ -1) | (-(v7627 ^ -1))) >> 31)) & 2)) - (v7628 + ((~(((v7629 ^ -1) | (-(v7629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7647[v7795] = v7645;
    int * v7649 = v7503->cache_vals;
    int v7798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7625 + ((~(((v7627 ^ -1) | (-(v7627 ^ -1))) >> 31)) & 2)) - (v7628 + ((~(((v7629 ^ -1) | (-(v7629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7649[v7798] = v7646;
    int * v7651 = v7503->cache_tags;
    int v7801 = (int)((unsigned int)((int)((unsigned int)(v7507 + 24) >> 2)) >> 1);
    v7651[v7777] = v7801;
    int * v7653 = v7503->cache_dirty;
    v7653[v7777] = 0;
    int * v7655 = v7503->cache_age;
    v7655[v7777] = 1;
    int * v7657 = v7503->cache_age;
    int v7658 = v7657[v7777];
    int v7659 = v7657[v7681];
    int v7807 = v7659 + ((int)((unsigned int)(v7659 - v7658) >> 31));
    v7657[v7681] = v7807;
    int * v7661 = v7503->cache_age;
    int v7662 = v7661[v7682];
    int v7809 = v7662 + ((int)((unsigned int)(v7662 - v7658) >> 31));
    v7661[v7682] = v7809;
    int * v7664 = v7503->cache_age;
    v7664[v7777] = 0;
    v7667 = v7777;
  }
  int * v7668 = v7503->cache_vals;
  int v7812 = (v7667 * 2) + (((int)((unsigned int)(v7507 + 24) >> 2)) & 1);
  v7668[v7812] = v7508;
  int * v7670 = v7503->cache_dirty;
  v7670[v7667] = 1;
  struct StateT * v7672 = slot_164(v7503);
  return v7672;
}

struct StateT * slot_21(struct StateT * v1919) {
  int v1920 = v1919->timer;
  int v1932 = v1920 + 1;
  v1919->timer = v1932;
  int * v1922 = v1919->regs;
  int v1923 = v1922[17];
  int v1924 = v1922[7];
  bool v1936 = (v1923 ^ -2147483648) < (v1924 ^ -2147483648);
  int v1927;
  if (v1936) {
    v1927 = 1;
  } else {
    v1927 = 0;
  }
  int * v1928 = v1919->regs;
  v1928[5] = v1927;
  struct StateT * v1930 = slot_22(v1919);
  return v1930;
}

struct StateT * slot_239(struct StateT * v11830) {
  int v11831 = v11830->timer;
  int v11838 = v11831 + 1;
  v11830->timer = v11838;
  int * v11833 = v11830->regs;
  int v11834 = v11833[12];
  int v11841 = v11834 << 13;
  v11833[12] = v11841;
  struct StateT * v11836 = slot_241(v11830);
  return v11836;
}

struct StateT * slot_118(struct StateT * v5994) {
  int v5995 = v5994->timer;
  int v6003 = v5995 + 1;
  v5994->timer = v6003;
  int * v5997 = v5994->regs;
  int v5998 = v5997[7];
  int v5999 = v5997[16];
  int v6008 = v5998 & v5999;
  v5997[29] = v6008;
  struct StateT * v6001 = slot_120(v5994);
  return v6001;
}

struct StateT * slot_121(struct StateT * v6340) {
  int v6341 = v6340->timer;
  int v6348 = v6341 + 1;
  v6340->timer = v6348;
  int * v6343 = v6340->regs;
  int v6344 = v6343[28];
  int v6352 = (int)((unsigned int)v6344 >> 19);
  v6343[17] = v6352;
  struct StateT * v6346 = slot_123(v6340);
  return v6346;
}

struct StateT * slot_144(struct StateT * v7114) {
  int v7115 = v7114->timer;
  int v7127 = v7115 + 1;
  v7114->timer = v7127;
  int * v7117 = v7114->regs;
  int v7118 = v7117[29];
  int v7119 = v7117[31];
  bool v7131 = (v7118 ^ -2147483648) < (v7119 ^ -2147483648);
  int v7122;
  if (v7131) {
    v7122 = 1;
  } else {
    v7122 = 0;
  }
  int * v7123 = v7114->regs;
  v7123[6] = v7122;
  struct StateT * v7125 = slot_145(v7114);
  return v7125;
}

struct StateT * slot_201(struct StateT * v9164) {
  int v9165 = v9164->timer;
  int v9173 = v9165 + 1;
  v9164->timer = v9173;
  int * v9167 = v9164->regs;
  int v9168 = v9167[12];
  int v9169 = v9167[5];
  int v9177 = v9168 + v9169;
  v9167[5] = v9177;
  struct StateT * v9171 = slot_202(v9164);
  return v9171;
}

struct StateT * slot_94(struct StateT * v5191) {
  int v5192 = v5191->timer;
  int v5200 = v5192 + 1;
  v5191->timer = v5200;
  int * v5194 = v5191->regs;
  int v5195 = v5194[6];
  int v5196 = v5194[7];
  int v5205 = v5195 + v5196;
  v5194[17] = v5205;
  struct StateT * v5198 = slot_95(v5191);
  return v5198;
}

struct StateT * slot_63(struct StateT * v3639) {
  int v3640 = v3639->timer;
  int v3648 = v3640 + 1;
  v3639->timer = v3648;
  int * v3642 = v3639->regs;
  int v3643 = v3642[6];
  int v3644 = v3642[30];
  int v3652 = v3643 + v3644;
  v3642[6] = v3652;
  struct StateT * v3646 = slot_64(v3639);
  return v3646;
}

struct StateT * slot_146(struct StateT * v7156) {
  int v7157 = v7156->timer;
  int v7165 = v7157 + 1;
  v7156->timer = v7165;
  int * v7159 = v7156->regs;
  int v7160 = v7159[8];
  int v7161 = v7159[6];
  int v7169 = v7160 + v7161;
  v7159[6] = v7169;
  struct StateT * v7163 = slot_147(v7156);
  return v7163;
}

struct StateT * slot_24(struct StateT * v1975) {
  int v1976 = v1975->timer;
  int v1984 = v1976 + 1;
  v1975->timer = v1984;
  int * v1978 = v1975->regs;
  int v1979 = v1978[28];
  int v1980 = v1978[5];
  int v1988 = v1979 + v1980;
  v1978[5] = v1988;
  struct StateT * v1982 = slot_25(v1975);
  return v1982;
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

struct StateT * slot_195(struct StateT * v9051) {
  int v9052 = v9051->timer;
  int v9064 = v9052 + 1;
  v9051->timer = v9064;
  int * v9054 = v9051->regs;
  int v9055 = v9054[12];
  int v9056 = v9054[8];
  bool v9068 = (v9055 ^ -2147483648) < (v9056 ^ -2147483648);
  int v9059;
  if (v9068) {
    v9059 = 1;
  } else {
    v9059 = 0;
  }
  int * v9060 = v9051->regs;
  v9060[28] = v9059;
  struct StateT * v9062 = slot_196(v9051);
  return v9062;
}

struct StateT * slot_125(struct StateT * v6409) {
  int v6410 = v6409->timer;
  int v6520 = v6410 + 1;
  v6409->timer = v6520;
  int * v6412 = v6409->regs;
  int v6413 = v6412[11];
  int * v6414 = v6409->cache_tags;
  int v6524 = (((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2;
  int v6415 = v6414[v6524];
  int v6525 = ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6416 = v6414[v6525];
  int v6526 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2);
  int v6417 = v6414[v6526];
  int v6527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6418 = v6414[v6527];
  int v6419 = v6409->timer;
  int v6528 = v6419 + ((100 ^ (((~(((v6417 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6417 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6415 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6415 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6416 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6416 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6417 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6417 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6409->timer = v6528;
  int * v6421 = v6409->cache_vals;
  bool v6529 = !(((~(((v6415 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6415 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6416 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6416 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v6514;
  if (v6529) {
    int * v6422 = v6409->cache_age;
    int v6531 = ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v6416 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6416 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v6423 = v6422[v6531];
    int v6424 = v6422[v6524];
    int v6532 = v6424 + ((int)((unsigned int)(v6424 - v6423) >> 31));
    v6422[v6524] = v6532;
    int * v6426 = v6409->cache_age;
    int v6427 = v6426[v6525];
    int v6534 = v6427 + ((int)((unsigned int)(v6427 - v6423) >> 31));
    v6426[v6525] = v6534;
    int * v6429 = v6409->cache_age;
    v6429[v6531] = 0;
    v6514 = v6531;
  } else {
    int * v6432 = v6409->cache_age;
    int v6538 = (((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2;
    int v6433 = v6432[v6538];
    int * v6434 = v6409->cache_tags;
    int v6435 = v6434[v6538];
    int v6436 = v6432[v6525];
    int v6437 = v6434[v6525];
    bool v6540 = !(((~(((v6417 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6417 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v6491;
    if (v6540) {
      int * v6438 = v6409->cache_age;
      int v6542 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))) | (-(v6418 ^ ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v6439 = v6438[v6542];
      int v6440 = v6438[v6526];
      int v6543 = v6440 + ((int)((unsigned int)(v6440 - v6439) >> 31));
      v6438[v6526] = v6543;
      int * v6442 = v6409->cache_age;
      int v6443 = v6442[v6527];
      int v6545 = v6443 + ((int)((unsigned int)(v6443 - v6439) >> 31));
      v6442[v6527] = v6545;
      int * v6445 = v6409->cache_age;
      v6445[v6542] = 0;
      v6491 = v6542;
    } else {
      int * v6448 = v6409->cache_age;
      int v6549 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2);
      int v6449 = v6448[v6549];
      int * v6450 = v6409->cache_tags;
      int v6451 = v6450[v6549];
      int v6452 = v6448[v6527];
      int v6453 = v6450[v6527];
      int * v6454 = v6409->cache_dirty;
      int v6552 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6449 + ((~(((v6451 ^ -1) | (-(v6451 ^ -1))) >> 31)) & 2)) - (v6452 + ((~(((v6453 ^ -1) | (-(v6453 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6455 = v6454[v6552];
      bool v6553 = !(v6455 == 0);
      if (v6553) {
        int * v6456 = v6409->cache_tags;
        int v6457 = v6456[v6552];
        int * v6458 = v6409->cache_vals;
        int v6556 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6449 + ((~(((v6451 ^ -1) | (-(v6451 ^ -1))) >> 31)) & 2)) - (v6452 + ((~(((v6453 ^ -1) | (-(v6453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6459 = v6458[v6556];
        int v6557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6449 + ((~(((v6451 ^ -1) | (-(v6451 ^ -1))) >> 31)) & 2)) - (v6452 + ((~(((v6453 ^ -1) | (-(v6453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6460 = v6458[v6557];
        int * v6461 = v6409->mem;
        int v6559 = v6457 * 2;
        v6461[v6559] = v6459;
        int * v6463 = v6409->mem;
        int v6562 = (v6457 * 2) + 1;
        v6463[v6562] = v6460;
        ;
      } else {
        ;
      }
      int * v6468 = v6409->mem;
      int v6567 = ((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) * 2;
      int v6469 = v6468[v6567];
      int v6568 = (((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) * 2) + 1;
      int v6470 = v6468[v6568];
      int * v6471 = v6409->cache_vals;
      int v6570 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6449 + ((~(((v6451 ^ -1) | (-(v6451 ^ -1))) >> 31)) & 2)) - (v6452 + ((~(((v6453 ^ -1) | (-(v6453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6471[v6570] = v6469;
      int * v6473 = v6409->cache_vals;
      int v6573 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6449 + ((~(((v6451 ^ -1) | (-(v6451 ^ -1))) >> 31)) & 2)) - (v6452 + ((~(((v6453 ^ -1) | (-(v6453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6473[v6573] = v6470;
      int * v6475 = v6409->cache_tags;
      int v6576 = (int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1);
      v6475[v6552] = v6576;
      int * v6477 = v6409->cache_dirty;
      v6477[v6552] = 0;
      int * v6479 = v6409->cache_age;
      v6479[v6552] = 1;
      int * v6481 = v6409->cache_age;
      int v6482 = v6481[v6552];
      int v6483 = v6481[v6526];
      int v6582 = v6483 + ((int)((unsigned int)(v6483 - v6482) >> 31));
      v6481[v6526] = v6582;
      int * v6485 = v6409->cache_age;
      int v6486 = v6485[v6527];
      int v6584 = v6486 + ((int)((unsigned int)(v6486 - v6482) >> 31));
      v6485[v6527] = v6584;
      int * v6488 = v6409->cache_age;
      v6488[v6552] = 0;
      v6491 = v6552;
    }
    int * v6492 = v6409->cache_vals;
    int v6587 = v6491 * 2;
    int v6493 = v6492[v6587];
    int v6588 = (v6491 * 2) + 1;
    int v6494 = v6492[v6588];
    int v6589 = (((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v6433 + ((~(((v6435 ^ -1) | (-(v6435 ^ -1))) >> 31)) & 2)) - (v6436 + ((~(((v6437 ^ -1) | (-(v6437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6492[v6589] = v6493;
    int * v6496 = v6409->cache_vals;
    int v6592 = ((((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v6433 + ((~(((v6435 ^ -1) | (-(v6435 ^ -1))) >> 31)) & 2)) - (v6436 + ((~(((v6437 ^ -1) | (-(v6437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6496[v6592] = v6494;
    int * v6498 = v6409->cache_tags;
    int v6595 = ((((int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v6433 + ((~(((v6435 ^ -1) | (-(v6435 ^ -1))) >> 31)) & 2)) - (v6436 + ((~(((v6437 ^ -1) | (-(v6437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6596 = (int)((unsigned int)((int)((unsigned int)(v6413 + 24) >> 2)) >> 1);
    v6498[v6595] = v6596;
    int * v6500 = v6409->cache_dirty;
    v6500[v6595] = 0;
    int * v6502 = v6409->cache_age;
    v6502[v6595] = 1;
    int * v6504 = v6409->cache_age;
    int v6505 = v6504[v6595];
    int v6506 = v6504[v6524];
    int v6602 = v6506 + ((int)((unsigned int)(v6506 - v6505) >> 31));
    v6504[v6524] = v6602;
    int * v6508 = v6409->cache_age;
    int v6509 = v6508[v6525];
    int v6604 = v6509 + ((int)((unsigned int)(v6509 - v6505) >> 31));
    v6508[v6525] = v6604;
    int * v6511 = v6409->cache_age;
    v6511[v6595] = 0;
    v6514 = v6595;
  }
  int v6607 = (v6514 * 2) + (((int)((unsigned int)(v6413 + 24) >> 2)) & 1);
  int v6515 = v6421[v6607];
  int * v6516 = v6409->regs;
  v6516[6] = v6515;
  struct StateT * v6518 = slot_126(v6409);
  return v6518;
}

struct StateT * slot_148(struct StateT * v7188) {
  int v7189 = v7188->timer;
  int v7197 = v7189 + 1;
  v7188->timer = v7197;
  int * v7191 = v7188->regs;
  int v7192 = v7191[9];
  int v7193 = v7191[6];
  int v7202 = v7192 + v7193;
  v7191[5] = v7202;
  struct StateT * v7195 = slot_149(v7188);
  return v7195;
}

struct StateT * slot_126(struct StateT * v6613) {
  int v6614 = v6613->timer;
  int v6724 = v6614 + 1;
  v6613->timer = v6724;
  int * v6616 = v6613->regs;
  int v6617 = v6616[11];
  int * v6618 = v6613->cache_tags;
  int v6728 = (((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2;
  int v6619 = v6618[v6728];
  int v6729 = ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6620 = v6618[v6729];
  int v6730 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2);
  int v6621 = v6618[v6730];
  int v6731 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6622 = v6618[v6731];
  int v6623 = v6613->timer;
  int v6732 = v6623 + ((100 ^ (((~(((v6621 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6621 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6619 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6619 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6620 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6620 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6621 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6621 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6613->timer = v6732;
  int * v6625 = v6613->cache_vals;
  bool v6733 = !(((~(((v6619 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6619 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6620 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6620 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v6718;
  if (v6733) {
    int * v6626 = v6613->cache_age;
    int v6735 = ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v6620 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6620 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v6627 = v6626[v6735];
    int v6628 = v6626[v6728];
    int v6736 = v6628 + ((int)((unsigned int)(v6628 - v6627) >> 31));
    v6626[v6728] = v6736;
    int * v6630 = v6613->cache_age;
    int v6631 = v6630[v6729];
    int v6738 = v6631 + ((int)((unsigned int)(v6631 - v6627) >> 31));
    v6630[v6729] = v6738;
    int * v6633 = v6613->cache_age;
    v6633[v6735] = 0;
    v6718 = v6735;
  } else {
    int * v6636 = v6613->cache_age;
    int v6742 = (((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2;
    int v6637 = v6636[v6742];
    int * v6638 = v6613->cache_tags;
    int v6639 = v6638[v6742];
    int v6640 = v6636[v6729];
    int v6641 = v6638[v6729];
    bool v6744 = !(((~(((v6621 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6621 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v6695;
    if (v6744) {
      int * v6642 = v6613->cache_age;
      int v6746 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))) | (-(v6622 ^ ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v6643 = v6642[v6746];
      int v6644 = v6642[v6730];
      int v6747 = v6644 + ((int)((unsigned int)(v6644 - v6643) >> 31));
      v6642[v6730] = v6747;
      int * v6646 = v6613->cache_age;
      int v6647 = v6646[v6731];
      int v6749 = v6647 + ((int)((unsigned int)(v6647 - v6643) >> 31));
      v6646[v6731] = v6749;
      int * v6649 = v6613->cache_age;
      v6649[v6746] = 0;
      v6695 = v6746;
    } else {
      int * v6652 = v6613->cache_age;
      int v6753 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2);
      int v6653 = v6652[v6753];
      int * v6654 = v6613->cache_tags;
      int v6655 = v6654[v6753];
      int v6656 = v6652[v6731];
      int v6657 = v6654[v6731];
      int * v6658 = v6613->cache_dirty;
      int v6756 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6653 + ((~(((v6655 ^ -1) | (-(v6655 ^ -1))) >> 31)) & 2)) - (v6656 + ((~(((v6657 ^ -1) | (-(v6657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6659 = v6658[v6756];
      bool v6757 = !(v6659 == 0);
      if (v6757) {
        int * v6660 = v6613->cache_tags;
        int v6661 = v6660[v6756];
        int * v6662 = v6613->cache_vals;
        int v6760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6653 + ((~(((v6655 ^ -1) | (-(v6655 ^ -1))) >> 31)) & 2)) - (v6656 + ((~(((v6657 ^ -1) | (-(v6657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6663 = v6662[v6760];
        int v6761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6653 + ((~(((v6655 ^ -1) | (-(v6655 ^ -1))) >> 31)) & 2)) - (v6656 + ((~(((v6657 ^ -1) | (-(v6657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6664 = v6662[v6761];
        int * v6665 = v6613->mem;
        int v6763 = v6661 * 2;
        v6665[v6763] = v6663;
        int * v6667 = v6613->mem;
        int v6766 = (v6661 * 2) + 1;
        v6667[v6766] = v6664;
        ;
      } else {
        ;
      }
      int * v6672 = v6613->mem;
      int v6771 = ((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) * 2;
      int v6673 = v6672[v6771];
      int v6772 = (((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) * 2) + 1;
      int v6674 = v6672[v6772];
      int * v6675 = v6613->cache_vals;
      int v6774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6653 + ((~(((v6655 ^ -1) | (-(v6655 ^ -1))) >> 31)) & 2)) - (v6656 + ((~(((v6657 ^ -1) | (-(v6657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6675[v6774] = v6673;
      int * v6677 = v6613->cache_vals;
      int v6777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6653 + ((~(((v6655 ^ -1) | (-(v6655 ^ -1))) >> 31)) & 2)) - (v6656 + ((~(((v6657 ^ -1) | (-(v6657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6677[v6777] = v6674;
      int * v6679 = v6613->cache_tags;
      int v6780 = (int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1);
      v6679[v6756] = v6780;
      int * v6681 = v6613->cache_dirty;
      v6681[v6756] = 0;
      int * v6683 = v6613->cache_age;
      v6683[v6756] = 1;
      int * v6685 = v6613->cache_age;
      int v6686 = v6685[v6756];
      int v6687 = v6685[v6730];
      int v6786 = v6687 + ((int)((unsigned int)(v6687 - v6686) >> 31));
      v6685[v6730] = v6786;
      int * v6689 = v6613->cache_age;
      int v6690 = v6689[v6731];
      int v6788 = v6690 + ((int)((unsigned int)(v6690 - v6686) >> 31));
      v6689[v6731] = v6788;
      int * v6692 = v6613->cache_age;
      v6692[v6756] = 0;
      v6695 = v6756;
    }
    int * v6696 = v6613->cache_vals;
    int v6791 = v6695 * 2;
    int v6697 = v6696[v6791];
    int v6792 = (v6695 * 2) + 1;
    int v6698 = v6696[v6792];
    int v6793 = (((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6637 + ((~(((v6639 ^ -1) | (-(v6639 ^ -1))) >> 31)) & 2)) - (v6640 + ((~(((v6641 ^ -1) | (-(v6641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6696[v6793] = v6697;
    int * v6700 = v6613->cache_vals;
    int v6796 = ((((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6637 + ((~(((v6639 ^ -1) | (-(v6639 ^ -1))) >> 31)) & 2)) - (v6640 + ((~(((v6641 ^ -1) | (-(v6641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6700[v6796] = v6698;
    int * v6702 = v6613->cache_tags;
    int v6799 = ((((int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6637 + ((~(((v6639 ^ -1) | (-(v6639 ^ -1))) >> 31)) & 2)) - (v6640 + ((~(((v6641 ^ -1) | (-(v6641 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6800 = (int)((unsigned int)((int)((unsigned int)(v6617 + 28) >> 2)) >> 1);
    v6702[v6799] = v6800;
    int * v6704 = v6613->cache_dirty;
    v6704[v6799] = 0;
    int * v6706 = v6613->cache_age;
    v6706[v6799] = 1;
    int * v6708 = v6613->cache_age;
    int v6709 = v6708[v6799];
    int v6710 = v6708[v6728];
    int v6806 = v6710 + ((int)((unsigned int)(v6710 - v6709) >> 31));
    v6708[v6728] = v6806;
    int * v6712 = v6613->cache_age;
    int v6713 = v6712[v6729];
    int v6808 = v6713 + ((int)((unsigned int)(v6713 - v6709) >> 31));
    v6712[v6729] = v6808;
    int * v6715 = v6613->cache_age;
    v6715[v6799] = 0;
    v6718 = v6799;
  }
  int v6811 = (v6718 * 2) + (((int)((unsigned int)(v6617 + 28) >> 2)) & 1);
  int v6719 = v6625[v6811];
  int * v6720 = v6613->regs;
  v6720[29] = v6719;
  struct StateT * v6722 = slot_127(v6613);
  return v6722;
}

struct StateT * slot_223(struct StateT * v9927) {
  int v9928 = v9927->timer;
  int v9936 = v9928 + 1;
  v9927->timer = v9936;
  int * v9930 = v9927->regs;
  int v9931 = v9930[17];
  int v9932 = v9930[16];
  int v9940 = v9931 & v9932;
  v9930[16] = v9940;
  struct StateT * v9934 = slot_225(v9927);
  return v9934;
}

struct StateT * slot_79(struct StateT * v4569) {
  int v4570 = v4569->timer;
  int v4578 = v4570 + 1;
  v4569->timer = v4578;
  int * v4572 = v4569->regs;
  int v4573 = v4572[6];
  int v4574 = v4572[5];
  int v4582 = v4573 + v4574;
  v4572[5] = v4582;
  struct StateT * v4576 = slot_80(v4569);
  return v4576;
}

struct StateT * slot_237(struct StateT * v11802) {
  int v11803 = v11802->timer;
  int v11810 = v11803 + 1;
  v11802->timer = v11810;
  int * v11805 = v11802->regs;
  int v11806 = v11805[5];
  int v11813 = (int)((unsigned int)v11806 >> 19);
  v11805[5] = v11813;
  struct StateT * v11808 = slot_239(v11802);
  return v11808;
}

struct StateT * slot_41(struct StateT * v3239) {
  int v3240 = v3239->timer;
  int v3248 = v3240 + 1;
  v3239->timer = v3248;
  int * v3242 = v3239->regs;
  int v3243 = v3242[7];
  int v3244 = v3242[13];
  int v3253 = v3243 * v3244;
  v3242[8] = v3253;
  struct StateT * v3246 = slot_42(v3239);
  return v3246;
}

struct StateT * slot_39(struct StateT * v3205) {
  int v3206 = v3205->timer;
  int v3214 = v3206 + 1;
  v3205->timer = v3214;
  int * v3208 = v3205->regs;
  int v3209 = v3208[28];
  int v3210 = v3208[12];
  int v3219 = v3209 * v3210;
  v3208[30] = v3219;
  struct StateT * v3212 = slot_40(v3205);
  return v3212;
}

struct StateT * slot_142(struct StateT * v7073) {
  int v7074 = v7073->timer;
  int v7086 = v7074 + 1;
  v7073->timer = v7086;
  int * v7076 = v7073->regs;
  int v7077 = v7076[17];
  int v7078 = v7076[6];
  bool v7090 = (v7077 ^ -2147483648) < (v7078 ^ -2147483648);
  int v7081;
  if (v7090) {
    v7081 = 1;
  } else {
    v7081 = 0;
  }
  int * v7082 = v7073->regs;
  v7082[28] = v7081;
  struct StateT * v7084 = slot_143(v7073);
  return v7084;
}

struct StateT * slot_60(struct StateT * v3582) {
  int v3583 = v3582->timer;
  int v3595 = v3583 + 1;
  v3582->timer = v3595;
  int * v3585 = v3582->regs;
  int v3586 = v3585[5];
  int v3587 = v3585[18];
  bool v3599 = (v3586 ^ -2147483648) < (v3587 ^ -2147483648);
  int v3590;
  if (v3599) {
    v3590 = 1;
  } else {
    v3590 = 0;
  }
  int * v3591 = v3582->regs;
  v3591[30] = v3590;
  struct StateT * v3593 = slot_61(v3582);
  return v3593;
}

struct StateT * slot_238(struct StateT * v11816) {
  int v11817 = v11816->timer;
  int v11824 = v11817 + 1;
  v11816->timer = v11824;
  int * v11819 = v11816->regs;
  int v11820 = v11819[2];
  int v11827 = v11820 + 16;
  v11819[2] = v11827;
  struct StateT * v11822 = slot_240(v11816);
  return v11822;
}

struct StateT * slot_112(struct StateT * v5535) {
  int * v5536 = v5535->saved_regs;
  int * v5537 = v5535->regs;
  int v5538 = v5537[29];
  v5536[29] = v5538;
  int v5540 = v5535->timer;
  int v5552 = v5540 + 1;
  v5535->timer = v5552;
  int * v5542 = v5535->regs;
  int v5543 = v5542[7];
  int v5544 = v5542[16];
  int v5556 = v5543 & v5544;
  v5542[29] = v5556;
  struct StateT * v5546 = slot_113(v5535);
  return v5546;
}

struct StateT * slot_47(struct StateT * v3337) {
  int v3338 = v3337->timer;
  int v3346 = v3338 + 1;
  v3337->timer = v3346;
  int * v3340 = v3337->regs;
  int v3341 = v3340[7];
  int v3342 = v3340[12];
  int v3350 = v3341 * v3342;
  v3340[7] = v3350;
  struct StateT * v3344 = slot_48(v3337);
  return v3344;
}

struct StateT * slot_214(struct StateT * v9399) {
  int * v9400 = v9399->saved_regs;
  int * v9401 = v9399->regs;
  int v9402 = v9401[15];
  v9400[15] = v9402;
  int v9404 = v9399->timer;
  int v9416 = v9404 + 1;
  v9399->timer = v9416;
  int * v9406 = v9399->regs;
  int v9407 = v9406[15];
  int v9408 = v9406[5];
  int v9419 = v9407 + v9408;
  v9406[15] = v9419;
  struct StateT * v9410 = slot_215(v9399);
  return v9410;
}

struct StateT * slot_29(struct StateT * v2841) {
  int v2842 = v2841->timer;
  int v2952 = v2842 + 1;
  v2841->timer = v2952;
  int * v2844 = v2841->regs;
  int v2845 = v2844[11];
  int * v2846 = v2841->cache_tags;
  int v2956 = (((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2847 = v2846[v2956];
  int v2957 = ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2848 = v2846[v2957];
  int v2958 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2849 = v2846[v2958];
  int v2959 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2850 = v2846[v2959];
  int v2851 = v2841->timer;
  int v2960 = v2851 + ((100 ^ (((~(((v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2841->timer = v2960;
  int * v2853 = v2841->cache_vals;
  bool v2961 = !(((~(((v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2946;
  if (v2961) {
    int * v2854 = v2841->cache_age;
    int v2963 = ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2855 = v2854[v2963];
    int v2856 = v2854[v2956];
    int v2964 = v2856 + ((int)((unsigned int)(v2856 - v2855) >> 31));
    v2854[v2956] = v2964;
    int * v2858 = v2841->cache_age;
    int v2859 = v2858[v2957];
    int v2966 = v2859 + ((int)((unsigned int)(v2859 - v2855) >> 31));
    v2858[v2957] = v2966;
    int * v2861 = v2841->cache_age;
    v2861[v2963] = 0;
    v2946 = v2963;
  } else {
    int * v2864 = v2841->cache_age;
    int v2970 = (((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2865 = v2864[v2970];
    int * v2866 = v2841->cache_tags;
    int v2867 = v2866[v2970];
    int v2868 = v2864[v2957];
    int v2869 = v2866[v2957];
    bool v2972 = !(((~(((v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v2923;
    if (v2972) {
      int * v2870 = v2841->cache_age;
      int v2974 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2871 = v2870[v2974];
      int v2872 = v2870[v2958];
      int v2975 = v2872 + ((int)((unsigned int)(v2872 - v2871) >> 31));
      v2870[v2958] = v2975;
      int * v2874 = v2841->cache_age;
      int v2875 = v2874[v2959];
      int v2977 = v2875 + ((int)((unsigned int)(v2875 - v2871) >> 31));
      v2874[v2959] = v2977;
      int * v2877 = v2841->cache_age;
      v2877[v2974] = 0;
      v2923 = v2974;
    } else {
      int * v2880 = v2841->cache_age;
      int v2981 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2);
      int v2881 = v2880[v2981];
      int * v2882 = v2841->cache_tags;
      int v2883 = v2882[v2981];
      int v2884 = v2880[v2959];
      int v2885 = v2882[v2959];
      int * v2886 = v2841->cache_dirty;
      int v2984 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2887 = v2886[v2984];
      bool v2985 = !(v2887 == 0);
      if (v2985) {
        int * v2888 = v2841->cache_tags;
        int v2889 = v2888[v2984];
        int * v2890 = v2841->cache_vals;
        int v2988 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2891 = v2890[v2988];
        int v2989 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2892 = v2890[v2989];
        int * v2893 = v2841->mem;
        int v2991 = v2889 * 2;
        v2893[v2991] = v2891;
        int * v2895 = v2841->mem;
        int v2994 = (v2889 * 2) + 1;
        v2895[v2994] = v2892;
        ;
      } else {
        ;
      }
      int * v2900 = v2841->mem;
      int v2999 = ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) * 2;
      int v2901 = v2900[v2999];
      int v3000 = (((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) * 2) + 1;
      int v2902 = v2900[v3000];
      int * v2903 = v2841->cache_vals;
      int v3002 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2903[v3002] = v2901;
      int * v2905 = v2841->cache_vals;
      int v3005 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2905[v3005] = v2902;
      int * v2907 = v2841->cache_tags;
      int v3008 = (int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1);
      v2907[v2984] = v3008;
      int * v2909 = v2841->cache_dirty;
      v2909[v2984] = 0;
      int * v2911 = v2841->cache_age;
      v2911[v2984] = 1;
      int * v2913 = v2841->cache_age;
      int v2914 = v2913[v2984];
      int v2915 = v2913[v2958];
      int v3014 = v2915 + ((int)((unsigned int)(v2915 - v2914) >> 31));
      v2913[v2958] = v3014;
      int * v2917 = v2841->cache_age;
      int v2918 = v2917[v2959];
      int v3016 = v2918 + ((int)((unsigned int)(v2918 - v2914) >> 31));
      v2917[v2959] = v3016;
      int * v2920 = v2841->cache_age;
      v2920[v2984] = 0;
      v2923 = v2984;
    }
    int * v2924 = v2841->cache_vals;
    int v3019 = v2923 * 2;
    int v2925 = v2924[v3019];
    int v3020 = (v2923 * 2) + 1;
    int v2926 = v2924[v3020];
    int v3021 = (((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2865 + ((~(((v2867 ^ -1) | (-(v2867 ^ -1))) >> 31)) & 2)) - (v2868 + ((~(((v2869 ^ -1) | (-(v2869 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2924[v3021] = v2925;
    int * v2928 = v2841->cache_vals;
    int v3024 = ((((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2865 + ((~(((v2867 ^ -1) | (-(v2867 ^ -1))) >> 31)) & 2)) - (v2868 + ((~(((v2869 ^ -1) | (-(v2869 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2928[v3024] = v2926;
    int * v2930 = v2841->cache_tags;
    int v3027 = ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2865 + ((~(((v2867 ^ -1) | (-(v2867 ^ -1))) >> 31)) & 2)) - (v2868 + ((~(((v2869 ^ -1) | (-(v2869 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3028 = (int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1);
    v2930[v3027] = v3028;
    int * v2932 = v2841->cache_dirty;
    v2932[v3027] = 0;
    int * v2934 = v2841->cache_age;
    v2934[v3027] = 1;
    int * v2936 = v2841->cache_age;
    int v2937 = v2936[v3027];
    int v2938 = v2936[v2956];
    int v3034 = v2938 + ((int)((unsigned int)(v2938 - v2937) >> 31));
    v2936[v2956] = v3034;
    int * v2940 = v2841->cache_age;
    int v2941 = v2940[v2957];
    int v3036 = v2941 + ((int)((unsigned int)(v2941 - v2937) >> 31));
    v2940[v2957] = v3036;
    int * v2943 = v2841->cache_age;
    v2943[v3027] = 0;
    v2946 = v3027;
  }
  int v3039 = (v2946 * 2) + (((int)((unsigned int)(v2845 + 12) >> 2)) & 1);
  int v2947 = v2853[v3039];
  int * v2948 = v2841->regs;
  v2948[28] = v2947;
  struct StateT * v2950 = slot_30(v2841);
  return v2950;
}

struct StateT * slot_16(struct StateT * v1830) {
  int v1831 = v1830->timer;
  int v1839 = v1831 + 1;
  v1830->timer = v1839;
  int * v1833 = v1830->regs;
  int v1834 = v1833[14];
  int v1835 = v1833[12];
  int v1843 = v1834 * v1835;
  v1833[14] = v1843;
  struct StateT * v1837 = slot_17(v1830);
  return v1837;
}

struct StateT * slot_245(struct StateT * v11898) {
  int v11899 = v11898->timer;
  int v11907 = v11899 + 1;
  v11898->timer = v11907;
  int * v11901 = v11898->regs;
  int v11902 = v11901[15];
  int v11903 = v11901[5];
  int v11911 = v11902 + v11903;
  v11901[15] = v11911;
  struct StateT * v11905 = slot_246(v11898);
  return v11905;
}

struct StateT * slot_113(struct StateT * v5559) {
  int * v5560 = v5559->saved_regs;
  int * v5561 = v5559->regs;
  int v5562 = v5561[7];
  v5560[7] = v5562;
  int v5564 = v5559->timer;
  int v5575 = v5564 + 1;
  v5559->timer = v5575;
  int * v5566 = v5559->regs;
  int v5567 = v5566[7];
  int v5577 = (int)((unsigned int)v5567 >> 19);
  v5566[7] = v5577;
  struct StateT * v5569 = slot_114(v5559);
  return v5569;
}

struct StateT * slot_151(struct StateT * v7254) {
  int v7255 = v7254->timer;
  int v7263 = v7255 + 1;
  v7254->timer = v7263;
  int * v7257 = v7254->regs;
  int v7258 = v7257[18];
  int v7259 = v7257[6];
  int v7267 = v7258 + v7259;
  v7257[6] = v7267;
  struct StateT * v7261 = slot_152(v7254);
  return v7261;
}

struct StateT * slot_7(struct StateT * v1684) {
  int v1685 = v1684->timer;
  int v1691 = v1685 + 1;
  v1684->timer = v1691;
  int * v1687 = v1684->regs;
  v1687[16] = 524288;
  struct StateT * v1689 = slot_8(v1684);
  return v1689;
}

struct StateT * slot_124(struct StateT * v6393) {
  int v6394 = v6393->timer;
  int v6402 = v6394 + 1;
  v6393->timer = v6402;
  int * v6396 = v6393->regs;
  int v6397 = v6396[6];
  int v6398 = v6396[5];
  int v6406 = v6397 + v6398;
  v6396[5] = v6406;
  struct StateT * v6400 = slot_125(v6393);
  return v6400;
}

struct StateT * slot_191(struct StateT * v8977) {
  int v8978 = v8977->timer;
  int v8986 = v8978 + 1;
  v8977->timer = v8986;
  int * v8980 = v8977->regs;
  int v8981 = v8980[31];
  int v8982 = v8980[12];
  int v8990 = v8981 + v8982;
  v8980[12] = v8990;
  struct StateT * v8984 = slot_192(v8977);
  return v8984;
}

struct StateT * slot_103(struct StateT * v5364) {
  int v5365 = v5364->timer;
  int v5373 = v5365 + 1;
  v5364->timer = v5373;
  int * v5367 = v5364->regs;
  int v5368 = v5367[9];
  int v5369 = v5367[6];
  int v5378 = v5368 + v5369;
  v5367[5] = v5378;
  struct StateT * v5371 = slot_104(v5364);
  return v5371;
}

struct StateT * slot_128(struct StateT * v6833) {
  int v6834 = v6833->timer;
  int v6841 = v6834 + 1;
  v6833->timer = v6841;
  int * v6836 = v6833->regs;
  int v6837 = v6836[5];
  int v6844 = v6837 << 13;
  v6836[5] = v6844;
  struct StateT * v6839 = slot_129(v6833);
  return v6839;
}

struct StateT * slot_19(struct StateT * v1887) {
  int v1888 = v1887->timer;
  int v1896 = v1888 + 1;
  v1887->timer = v1896;
  int * v1890 = v1887->regs;
  int v1891 = v1890[7];
  int v1892 = v1890[17];
  int v1900 = v1891 + v1892;
  v1890[17] = v1900;
  struct StateT * v1894 = slot_20(v1887);
  return v1894;
}

struct StateT * slot_87(struct StateT * v5073) {
  int v5074 = v5073->timer;
  int v5082 = v5074 + 1;
  v5073->timer = v5082;
  int * v5076 = v5073->regs;
  int v5077 = v5076[29];
  int v5078 = v5076[12];
  int v5087 = (((((int)((unsigned int)v5077 >> 16)) * ((int)((unsigned int)v5078 >> 16))) + ((int)((unsigned int)((v5077 & 65535) * ((int)((unsigned int)v5078 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v5077 >> 16)) * (v5078 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v5077 & 65535) * (v5078 & 65535)) >> 16)) + (((v5077 & 65535) * ((int)((unsigned int)v5078 >> 16))) & 65535)) + ((((int)((unsigned int)v5077 >> 16)) * (v5078 & 65535)) & 65535)) >> 16));
  v5076[30] = v5087;
  struct StateT * v5080 = slot_88(v5073);
  return v5080;
}

struct StateT * slot_67(struct StateT * v3711) {
  int * v3712 = v3711->saved_regs;
  int * v3713 = v3711->regs;
  int v3714 = v3713[29];
  v3712[29] = v3714;
  int v3716 = v3711->timer;
  int v3728 = v3716 + 1;
  v3711->timer = v3728;
  int * v3718 = v3711->regs;
  int v3719 = v3718[7];
  int v3720 = v3718[16];
  int v3732 = v3719 & v3720;
  v3718[29] = v3732;
  struct StateT * v3722 = slot_68(v3711);
  return v3722;
}

struct StateT * slot_81(struct StateT * v4789) {
  int v4790 = v4789->timer;
  int v4900 = v4790 + 1;
  v4789->timer = v4900;
  int * v4792 = v4789->regs;
  int v4793 = v4792[11];
  int * v4794 = v4789->cache_tags;
  int v4904 = (((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2;
  int v4795 = v4794[v4904];
  int v4905 = ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4796 = v4794[v4905];
  int v4906 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2);
  int v4797 = v4794[v4906];
  int v4907 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4798 = v4794[v4907];
  int v4799 = v4789->timer;
  int v4908 = v4799 + ((100 ^ (((~(((v4797 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4797 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4795 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4795 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4796 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4796 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4797 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4797 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4789->timer = v4908;
  int * v4801 = v4789->cache_vals;
  bool v4909 = !(((~(((v4795 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4795 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4796 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4796 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v4894;
  if (v4909) {
    int * v4802 = v4789->cache_age;
    int v4911 = ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v4796 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4796 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v4803 = v4802[v4911];
    int v4804 = v4802[v4904];
    int v4912 = v4804 + ((int)((unsigned int)(v4804 - v4803) >> 31));
    v4802[v4904] = v4912;
    int * v4806 = v4789->cache_age;
    int v4807 = v4806[v4905];
    int v4914 = v4807 + ((int)((unsigned int)(v4807 - v4803) >> 31));
    v4806[v4905] = v4914;
    int * v4809 = v4789->cache_age;
    v4809[v4911] = 0;
    v4894 = v4911;
  } else {
    int * v4812 = v4789->cache_age;
    int v4918 = (((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2;
    int v4813 = v4812[v4918];
    int * v4814 = v4789->cache_tags;
    int v4815 = v4814[v4918];
    int v4816 = v4812[v4905];
    int v4817 = v4814[v4905];
    bool v4920 = !(((~(((v4797 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4797 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v4871;
    if (v4920) {
      int * v4818 = v4789->cache_age;
      int v4922 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))) | (-(v4798 ^ ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v4819 = v4818[v4922];
      int v4820 = v4818[v4906];
      int v4923 = v4820 + ((int)((unsigned int)(v4820 - v4819) >> 31));
      v4818[v4906] = v4923;
      int * v4822 = v4789->cache_age;
      int v4823 = v4822[v4907];
      int v4925 = v4823 + ((int)((unsigned int)(v4823 - v4819) >> 31));
      v4822[v4907] = v4925;
      int * v4825 = v4789->cache_age;
      v4825[v4922] = 0;
      v4871 = v4922;
    } else {
      int * v4828 = v4789->cache_age;
      int v4929 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2);
      int v4829 = v4828[v4929];
      int * v4830 = v4789->cache_tags;
      int v4831 = v4830[v4929];
      int v4832 = v4828[v4907];
      int v4833 = v4830[v4907];
      int * v4834 = v4789->cache_dirty;
      int v4932 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4829 + ((~(((v4831 ^ -1) | (-(v4831 ^ -1))) >> 31)) & 2)) - (v4832 + ((~(((v4833 ^ -1) | (-(v4833 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4835 = v4834[v4932];
      bool v4933 = !(v4835 == 0);
      if (v4933) {
        int * v4836 = v4789->cache_tags;
        int v4837 = v4836[v4932];
        int * v4838 = v4789->cache_vals;
        int v4936 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4829 + ((~(((v4831 ^ -1) | (-(v4831 ^ -1))) >> 31)) & 2)) - (v4832 + ((~(((v4833 ^ -1) | (-(v4833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4839 = v4838[v4936];
        int v4937 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4829 + ((~(((v4831 ^ -1) | (-(v4831 ^ -1))) >> 31)) & 2)) - (v4832 + ((~(((v4833 ^ -1) | (-(v4833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4840 = v4838[v4937];
        int * v4841 = v4789->mem;
        int v4939 = v4837 * 2;
        v4841[v4939] = v4839;
        int * v4843 = v4789->mem;
        int v4942 = (v4837 * 2) + 1;
        v4843[v4942] = v4840;
        ;
      } else {
        ;
      }
      int * v4848 = v4789->mem;
      int v4947 = ((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) * 2;
      int v4849 = v4848[v4947];
      int v4948 = (((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) * 2) + 1;
      int v4850 = v4848[v4948];
      int * v4851 = v4789->cache_vals;
      int v4950 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4829 + ((~(((v4831 ^ -1) | (-(v4831 ^ -1))) >> 31)) & 2)) - (v4832 + ((~(((v4833 ^ -1) | (-(v4833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4851[v4950] = v4849;
      int * v4853 = v4789->cache_vals;
      int v4953 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4829 + ((~(((v4831 ^ -1) | (-(v4831 ^ -1))) >> 31)) & 2)) - (v4832 + ((~(((v4833 ^ -1) | (-(v4833 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4853[v4953] = v4850;
      int * v4855 = v4789->cache_tags;
      int v4956 = (int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1);
      v4855[v4932] = v4956;
      int * v4857 = v4789->cache_dirty;
      v4857[v4932] = 0;
      int * v4859 = v4789->cache_age;
      v4859[v4932] = 1;
      int * v4861 = v4789->cache_age;
      int v4862 = v4861[v4932];
      int v4863 = v4861[v4906];
      int v4962 = v4863 + ((int)((unsigned int)(v4863 - v4862) >> 31));
      v4861[v4906] = v4962;
      int * v4865 = v4789->cache_age;
      int v4866 = v4865[v4907];
      int v4964 = v4866 + ((int)((unsigned int)(v4866 - v4862) >> 31));
      v4865[v4907] = v4964;
      int * v4868 = v4789->cache_age;
      v4868[v4932] = 0;
      v4871 = v4932;
    }
    int * v4872 = v4789->cache_vals;
    int v4967 = v4871 * 2;
    int v4873 = v4872[v4967];
    int v4968 = (v4871 * 2) + 1;
    int v4874 = v4872[v4968];
    int v4969 = (((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4813 + ((~(((v4815 ^ -1) | (-(v4815 ^ -1))) >> 31)) & 2)) - (v4816 + ((~(((v4817 ^ -1) | (-(v4817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4872[v4969] = v4873;
    int * v4876 = v4789->cache_vals;
    int v4972 = ((((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4813 + ((~(((v4815 ^ -1) | (-(v4815 ^ -1))) >> 31)) & 2)) - (v4816 + ((~(((v4817 ^ -1) | (-(v4817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4876[v4972] = v4874;
    int * v4878 = v4789->cache_tags;
    int v4975 = ((((int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4813 + ((~(((v4815 ^ -1) | (-(v4815 ^ -1))) >> 31)) & 2)) - (v4816 + ((~(((v4817 ^ -1) | (-(v4817 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4976 = (int)((unsigned int)((int)((unsigned int)(v4793 + 20) >> 2)) >> 1);
    v4878[v4975] = v4976;
    int * v4880 = v4789->cache_dirty;
    v4880[v4975] = 0;
    int * v4882 = v4789->cache_age;
    v4882[v4975] = 1;
    int * v4884 = v4789->cache_age;
    int v4885 = v4884[v4975];
    int v4886 = v4884[v4904];
    int v4982 = v4886 + ((int)((unsigned int)(v4886 - v4885) >> 31));
    v4884[v4904] = v4982;
    int * v4888 = v4789->cache_age;
    int v4889 = v4888[v4905];
    int v4984 = v4889 + ((int)((unsigned int)(v4889 - v4885) >> 31));
    v4888[v4905] = v4984;
    int * v4891 = v4789->cache_age;
    v4891[v4975] = 0;
    v4894 = v4975;
  }
  int v4987 = (v4894 * 2) + (((int)((unsigned int)(v4793 + 20) >> 2)) & 1);
  int v4895 = v4801[v4987];
  int * v4896 = v4789->regs;
  v4896[29] = v4895;
  struct StateT * v4898 = slot_82(v4789);
  return v4898;
}

struct StateT * slot_95(struct StateT * v5208) {
  int v5209 = v5208->timer;
  int v5221 = v5209 + 1;
  v5208->timer = v5221;
  int * v5211 = v5208->regs;
  int v5212 = v5211[29];
  int v5213 = v5211[28];
  bool v5225 = (v5212 ^ -2147483648) < (v5213 ^ -2147483648);
  int v5216;
  if (v5225) {
    v5216 = 1;
  } else {
    v5216 = 0;
  }
  int * v5217 = v5208->regs;
  v5217[7] = v5216;
  struct StateT * v5219 = slot_96(v5208);
  return v5219;
}

struct StateT * slot_115(struct StateT * v5611) {
  int * v5612 = v5611->saved_regs;
  int v5613 = v5612[7];
  int v5614 = v5612[29];
  bool v5642 = v5613 == v5614;
  struct StateT * v5637;
  if (v5642) {
    int v5615 = v5611->timer;
    int v5643 = v5615 + 15;
    v5611->timer = v5643;
    int * v5617 = v5611->saved_regs;
    int v5618 = v5617[28];
    int * v5619 = v5611->regs;
    v5619[28] = v5618;
    int * v5621 = v5611->saved_regs;
    int v5622 = v5621[29];
    int * v5623 = v5611->regs;
    v5623[29] = v5622;
    int * v5625 = v5611->saved_regs;
    int v5626 = v5625[7];
    int * v5627 = v5611->regs;
    v5627[7] = v5626;
    int * v5629 = v5611->saved_regs;
    int v5630 = v5629[5];
    int * v5631 = v5611->regs;
    v5631[5] = v5630;
    struct StateT * v5633 = slot_116(v5611);
    v5637 = v5633;
  } else {
    struct StateT * v5635 = slot_117(v5611);
    v5637 = v5635;
  }
  return v5637;
}

struct StateT * slot_78(struct StateT * v4555) {
  int v4556 = v4555->timer;
  int v4563 = v4556 + 1;
  v4555->timer = v4563;
  int * v4558 = v4555->regs;
  int v4559 = v4558[28];
  int v4566 = v4559 << 13;
  v4558[28] = v4566;
  struct StateT * v4561 = slot_79(v4555);
  return v4561;
}

struct StateT * slot_32(struct StateT * v3086) {
  int v3087 = v3086->timer;
  int v3099 = v3087 + 1;
  v3086->timer = v3099;
  int * v3089 = v3086->regs;
  int v3090 = v3089[31];
  int v3091 = v3089[29];
  bool v3103 = (v3090 ^ -2147483648) < (v3091 ^ -2147483648);
  int v3094;
  if (v3103) {
    v3094 = 1;
  } else {
    v3094 = 0;
  }
  int * v3095 = v3086->regs;
  v3095[6] = v3094;
  struct StateT * v3097 = slot_33(v3086);
  return v3097;
}

struct StateT * slot_205(struct StateT * v9255) {
  int v9256 = v9255->timer;
  int v9264 = v9256 + 1;
  v9255->timer = v9264;
  int * v9258 = v9255->regs;
  int v9259 = v9258[13];
  int v9260 = v9258[12];
  int v9268 = v9259 + v9260;
  v9258[12] = v9268;
  struct StateT * v9262 = slot_206(v9255);
  return v9262;
}

struct StateT * slot_193(struct StateT * v9010) {
  int v9011 = v9010->timer;
  int v9019 = v9011 + 1;
  v9010->timer = v9019;
  int * v9013 = v9010->regs;
  int v9014 = v9013[8];
  int v9015 = v9013[28];
  int v9024 = v9014 + v9015;
  v9013[12] = v9024;
  struct StateT * v9017 = slot_194(v9010);
  return v9017;
}

struct StateT * slot_233(struct StateT * v11365) {
  int v11366 = v11365->timer;
  int v11374 = v11366 + 1;
  v11365->timer = v11374;
  int * v11368 = v11365->regs;
  int v11369 = v11368[17];
  int v11370 = v11368[13];
  int v11378 = v11369 | v11370;
  v11368[13] = v11378;
  struct StateT * v11372 = slot_235(v11365);
  return v11372;
}

struct StateT * slot_176(struct StateT * v8703) {
  int v8704 = v8703->timer;
  int v8712 = v8704 + 1;
  v8703->timer = v8712;
  int * v8706 = v8703->regs;
  int v8707 = v8706[11];
  int v8708 = v8706[12];
  int v8717 = v8707 * v8708;
  v8706[28] = v8717;
  struct StateT * v8710 = slot_177(v8703);
  return v8710;
}

struct StateT * slot_189(struct StateT * v8936) {
  int v8937 = v8936->timer;
  int v8949 = v8937 + 1;
  v8936->timer = v8949;
  int * v8939 = v8936->regs;
  int v8940 = v8939[6];
  int v8941 = v8939[30];
  bool v8953 = (v8940 ^ -2147483648) < (v8941 ^ -2147483648);
  int v8944;
  if (v8953) {
    v8944 = 1;
  } else {
    v8944 = 0;
  }
  int * v8945 = v8936->regs;
  v8945[12] = v8944;
  struct StateT * v8947 = slot_190(v8936);
  return v8947;
}

struct StateT * slot_33(struct StateT * v3111) {
  int v3112 = v3111->timer;
  int v3120 = v3112 + 1;
  v3111->timer = v3120;
  int * v3114 = v3111->regs;
  int v3115 = v3114[30];
  int v3116 = v3114[5];
  int v3124 = v3115 + v3116;
  v3114[5] = v3124;
  struct StateT * v3118 = slot_34(v3111);
  return v3118;
}

struct StateT * slot_35(struct StateT * v3142) {
  int v3143 = v3142->timer;
  int v3150 = v3143 + 1;
  v3142->timer = v3150;
  int * v3145 = v3142->regs;
  int v3146 = v3145[31];
  int v3153 = v3146 << 13;
  v3145[31] = v3153;
  struct StateT * v3148 = slot_36(v3142);
  return v3148;
}

struct StateT * slot_246(struct StateT * v11914) {
  int v11915 = v11914->timer;
  int v11923 = v11915 + 1;
  v11914->timer = v11923;
  int * v11917 = v11914->regs;
  int v11918 = v11917[14];
  int v11919 = v11917[13];
  int v11927 = v11918 + v11919;
  v11917[13] = v11927;
  struct StateT * v11921 = slot_247(v11914);
  return v11921;
}

struct StateT * slot_210(struct StateT * v9336) {
  int v9337 = v9336->timer;
  int v9344 = v9337 + 1;
  v9336->timer = v9344;
  int * v9339 = v9336->regs;
  int v9340 = v9339[12];
  int v9347 = v9340 << 13;
  v9339[12] = v9347;
  struct StateT * v9342 = slot_211(v9336);
  return v9342;
}

struct StateT * slot_166(struct StateT * v8164) {
  int v8165 = v8164->timer;
  int v8172 = v8165 + 1;
  v8164->timer = v8172;
  int * v8167 = v8164->regs;
  int v8168 = v8167[28];
  int v8176 = (int)((unsigned int)v8168 >> 19);
  v8167[17] = v8176;
  struct StateT * v8170 = slot_168(v8164);
  return v8170;
}

struct StateT * slot_51(struct StateT * v3409) {
  int v3410 = v3409->timer;
  int v3418 = v3410 + 1;
  v3409->timer = v3418;
  int * v3412 = v3409->regs;
  int v3413 = v3412[8];
  int v3414 = v3412[6];
  int v3423 = v3413 + v3414;
  v3412[29] = v3423;
  struct StateT * v3416 = slot_52(v3409);
  return v3416;
}

struct StateT * slot_52(struct StateT * v3426) {
  int v3427 = v3426->timer;
  int v3439 = v3427 + 1;
  v3426->timer = v3439;
  int * v3429 = v3426->regs;
  int v3430 = v3429[17];
  int v3431 = v3429[7];
  bool v3443 = (v3430 ^ -2147483648) < (v3431 ^ -2147483648);
  int v3434;
  if (v3443) {
    v3434 = 1;
  } else {
    v3434 = 0;
  }
  int * v3435 = v3426->regs;
  v3435[28] = v3434;
  struct StateT * v3437 = slot_53(v3426);
  return v3437;
}

struct StateT * slot_83(struct StateT * v5009) {
  int v5010 = v5009->timer;
  int v5017 = v5010 + 1;
  v5009->timer = v5017;
  int * v5012 = v5009->regs;
  int v5013 = v5012[5];
  int v5020 = v5013 << 13;
  v5012[5] = v5020;
  struct StateT * v5015 = slot_84(v5009);
  return v5015;
}

struct StateT * slot_25(struct StateT * v1991) {
  int v1992 = v1991->timer;
  int v2162 = v1992 + 1;
  v1991->timer = v2162;
  int * v1994 = v1991->regs;
  int v1995 = v1994[10];
  int v1996 = v1994[14];
  int * v1997 = v1991->cache_tags;
  int v2167 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2;
  int v1998 = v1997[v2167];
  int v2168 = ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1999 = v1997[v2168];
  int v2169 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2);
  int v2000 = v1997[v2169];
  int v2170 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2001 = v1997[v2170];
  int v2002 = v1991->timer;
  int v2171 = v2002 + ((100 ^ (((~(((v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1991->timer = v2171;
  bool v2172 = !(((~(((v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) == 0);
  int v2096;
  if (v2172) {
    int * v2004 = v1991->cache_age;
    int v2174 = ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((~(((v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) & 1);
    int v2005 = v2004[v2174];
    int v2006 = v2004[v2167];
    int v2175 = v2006 + ((int)((unsigned int)(v2006 - v2005) >> 31));
    v2004[v2167] = v2175;
    int * v2008 = v1991->cache_age;
    int v2009 = v2008[v2168];
    int v2177 = v2009 + ((int)((unsigned int)(v2009 - v2005) >> 31));
    v2008[v2168] = v2177;
    int * v2011 = v1991->cache_age;
    v2011[v2174] = 0;
    v2096 = v2174;
  } else {
    int * v2014 = v1991->cache_age;
    int v2181 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2;
    int v2015 = v2014[v2181];
    int * v2016 = v1991->cache_tags;
    int v2017 = v2016[v2181];
    int v2018 = v2014[v2168];
    int v2019 = v2016[v2168];
    bool v2183 = !(((~(((v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) == 0);
    int v2073;
    if (v2183) {
      int * v2020 = v1991->cache_age;
      int v2185 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) & 1);
      int v2021 = v2020[v2185];
      int v2022 = v2020[v2169];
      int v2186 = v2022 + ((int)((unsigned int)(v2022 - v2021) >> 31));
      v2020[v2169] = v2186;
      int * v2024 = v1991->cache_age;
      int v2025 = v2024[v2170];
      int v2188 = v2025 + ((int)((unsigned int)(v2025 - v2021) >> 31));
      v2024[v2170] = v2188;
      int * v2027 = v1991->cache_age;
      v2027[v2185] = 0;
      v2073 = v2185;
    } else {
      int * v2030 = v1991->cache_age;
      int v2192 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2);
      int v2031 = v2030[v2192];
      int * v2032 = v1991->cache_tags;
      int v2033 = v2032[v2192];
      int v2034 = v2030[v2170];
      int v2035 = v2032[v2170];
      int * v2036 = v1991->cache_dirty;
      int v2195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2037 = v2036[v2195];
      bool v2196 = !(v2037 == 0);
      if (v2196) {
        int * v2038 = v1991->cache_tags;
        int v2039 = v2038[v2195];
        int * v2040 = v1991->cache_vals;
        int v2199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2041 = v2040[v2199];
        int v2200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2042 = v2040[v2200];
        int * v2043 = v1991->mem;
        int v2202 = v2039 * 2;
        v2043[v2202] = v2041;
        int * v2045 = v1991->mem;
        int v2205 = (v2039 * 2) + 1;
        v2045[v2205] = v2042;
        ;
      } else {
        ;
      }
      int * v2050 = v1991->mem;
      int v2210 = ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2;
      int v2051 = v2050[v2210];
      int v2211 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2) + 1;
      int v2052 = v2050[v2211];
      int * v2053 = v1991->cache_vals;
      int v2213 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2053[v2213] = v2051;
      int * v2055 = v1991->cache_vals;
      int v2216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2055[v2216] = v2052;
      int * v2057 = v1991->cache_tags;
      int v2219 = (int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1);
      v2057[v2195] = v2219;
      int * v2059 = v1991->cache_dirty;
      v2059[v2195] = 0;
      int * v2061 = v1991->cache_age;
      v2061[v2195] = 1;
      int * v2063 = v1991->cache_age;
      int v2064 = v2063[v2195];
      int v2065 = v2063[v2169];
      int v2225 = v2065 + ((int)((unsigned int)(v2065 - v2064) >> 31));
      v2063[v2169] = v2225;
      int * v2067 = v1991->cache_age;
      int v2068 = v2067[v2170];
      int v2227 = v2068 + ((int)((unsigned int)(v2068 - v2064) >> 31));
      v2067[v2170] = v2227;
      int * v2070 = v1991->cache_age;
      v2070[v2195] = 0;
      v2073 = v2195;
    }
    int * v2074 = v1991->cache_vals;
    int v2230 = v2073 * 2;
    int v2075 = v2074[v2230];
    int v2231 = (v2073 * 2) + 1;
    int v2076 = v2074[v2231];
    int v2232 = (((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((((v2015 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2)) - (v2018 + ((~(((v2019 ^ -1) | (-(v2019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2074[v2232] = v2075;
    int * v2078 = v1991->cache_vals;
    int v2235 = ((((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((((v2015 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2)) - (v2018 + ((~(((v2019 ^ -1) | (-(v2019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2078[v2235] = v2076;
    int * v2080 = v1991->cache_tags;
    int v2238 = ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((((v2015 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2)) - (v2018 + ((~(((v2019 ^ -1) | (-(v2019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2239 = (int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1);
    v2080[v2238] = v2239;
    int * v2082 = v1991->cache_dirty;
    v2082[v2238] = 0;
    int * v2084 = v1991->cache_age;
    v2084[v2238] = 1;
    int * v2086 = v1991->cache_age;
    int v2087 = v2086[v2238];
    int v2088 = v2086[v2167];
    int v2245 = v2088 + ((int)((unsigned int)(v2088 - v2087) >> 31));
    v2086[v2167] = v2245;
    int * v2090 = v1991->cache_age;
    int v2091 = v2090[v2168];
    int v2247 = v2091 + ((int)((unsigned int)(v2091 - v2087) >> 31));
    v2090[v2168] = v2247;
    int * v2093 = v1991->cache_age;
    v2093[v2238] = 0;
    v2096 = v2238;
  }
  int * v2097 = v1991->cache_vals;
  int v2250 = (v2096 * 2) + (((int)((unsigned int)v1995 >> 2)) & 1);
  v2097[v2250] = v1996;
  int * v2099 = v1991->cache_tags;
  int v2100 = v2099[v2169];
  int v2101 = v2099[v2170];
  bool v2253 = !(((~(((v2100 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2100 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) == 0);
  int v2155;
  if (v2253) {
    int * v2102 = v1991->cache_age;
    int v2255 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) & 1);
    int v2103 = v2102[v2255];
    int v2104 = v2102[v2169];
    int v2256 = v2104 + ((int)((unsigned int)(v2104 - v2103) >> 31));
    v2102[v2169] = v2256;
    int * v2106 = v1991->cache_age;
    int v2107 = v2106[v2170];
    int v2258 = v2107 + ((int)((unsigned int)(v2107 - v2103) >> 31));
    v2106[v2170] = v2258;
    int * v2109 = v1991->cache_age;
    v2109[v2255] = 0;
    v2155 = v2255;
  } else {
    int * v2112 = v1991->cache_age;
    int v2262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2);
    int v2113 = v2112[v2262];
    int * v2114 = v1991->cache_tags;
    int v2115 = v2114[v2262];
    int v2116 = v2112[v2170];
    int v2117 = v2114[v2170];
    int * v2118 = v1991->cache_dirty;
    int v2265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2119 = v2118[v2265];
    bool v2266 = !(v2119 == 0);
    if (v2266) {
      int * v2120 = v1991->cache_tags;
      int v2121 = v2120[v2265];
      int * v2122 = v1991->cache_vals;
      int v2269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2123 = v2122[v2269];
      int v2270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2124 = v2122[v2270];
      int * v2125 = v1991->mem;
      int v2272 = v2121 * 2;
      v2125[v2272] = v2123;
      int * v2127 = v1991->mem;
      int v2275 = (v2121 * 2) + 1;
      v2127[v2275] = v2124;
      ;
    } else {
      ;
    }
    int * v2132 = v1991->mem;
    int v2280 = ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2;
    int v2133 = v2132[v2280];
    int v2281 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2) + 1;
    int v2134 = v2132[v2281];
    int * v2135 = v1991->cache_vals;
    int v2283 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2135[v2283] = v2133;
    int * v2137 = v1991->cache_vals;
    int v2286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2137[v2286] = v2134;
    int * v2139 = v1991->cache_tags;
    int v2289 = (int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1);
    v2139[v2265] = v2289;
    int * v2141 = v1991->cache_dirty;
    v2141[v2265] = 0;
    int * v2143 = v1991->cache_age;
    v2143[v2265] = 1;
    int * v2145 = v1991->cache_age;
    int v2146 = v2145[v2265];
    int v2147 = v2145[v2169];
    int v2295 = v2147 + ((int)((unsigned int)(v2147 - v2146) >> 31));
    v2145[v2169] = v2295;
    int * v2149 = v1991->cache_age;
    int v2150 = v2149[v2170];
    int v2297 = v2150 + ((int)((unsigned int)(v2150 - v2146) >> 31));
    v2149[v2170] = v2297;
    int * v2152 = v1991->cache_age;
    v2152[v2265] = 0;
    v2155 = v2265;
  }
  int * v2156 = v1991->cache_vals;
  int v2300 = (v2155 * 2) + (((int)((unsigned int)v1995 >> 2)) & 1);
  v2156[v2300] = v1996;
  int * v2158 = v1991->cache_dirty;
  v2158[v2155] = 1;
  struct StateT * v2160 = slot_26(v1991);
  return v2160;
}

struct StateT * slot_209(struct StateT * v9322) {
  int v9323 = v9322->timer;
  int v9330 = v9323 + 1;
  v9322->timer = v9330;
  int * v9325 = v9322->regs;
  int v9326 = v9325[5];
  int v9333 = (int)((unsigned int)v9326 >> 19);
  v9325[5] = v9333;
  struct StateT * v9328 = slot_210(v9322);
  return v9328;
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

struct StateT * slot_123(struct StateT * v6379) {
  int v6380 = v6379->timer;
  int v6387 = v6380 + 1;
  v6379->timer = v6387;
  int * v6382 = v6379->regs;
  int v6383 = v6382[28];
  int v6390 = v6383 << 13;
  v6382[28] = v6390;
  struct StateT * v6385 = slot_124(v6379);
  return v6385;
}

struct StateT * slot_73(struct StateT * v4170) {
  int v4171 = v4170->timer;
  int v4179 = v4171 + 1;
  v4170->timer = v4179;
  int * v4173 = v4170->regs;
  int v4174 = v4173[7];
  int v4175 = v4173[16];
  int v4184 = v4174 & v4175;
  v4173[29] = v4184;
  struct StateT * v4177 = slot_75(v4170);
  return v4177;
}

struct StateT * slot_198(struct StateT * v9108) {
  int v9109 = v9108->timer;
  int v9117 = v9109 + 1;
  v9108->timer = v9117;
  int * v9111 = v9108->regs;
  int v9112 = v9111[13];
  int v9113 = v9111[28];
  int v9121 = v9112 + v9113;
  v9111[13] = v9121;
  struct StateT * v9115 = slot_199(v9108);
  return v9115;
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

struct StateT * slot_187(struct StateT * v8895) {
  int v8896 = v8895->timer;
  int v8908 = v8896 + 1;
  v8895->timer = v8908;
  int * v8898 = v8895->regs;
  int v8899 = v8898[11];
  int v8900 = v8898[12];
  bool v8912 = (v8899 ^ -2147483648) < (v8900 ^ -2147483648);
  int v8903;
  if (v8912) {
    v8903 = 1;
  } else {
    v8903 = 0;
  }
  int * v8904 = v8895->regs;
  v8904[5] = v8903;
  struct StateT * v8906 = slot_188(v8895);
  return v8906;
}

struct StateT * slot_97(struct StateT * v5249) {
  int v5250 = v5249->timer;
  int v5262 = v5250 + 1;
  v5249->timer = v5262;
  int * v5252 = v5249->regs;
  int v5253 = v5252[17];
  int v5254 = v5252[6];
  bool v5266 = (v5253 ^ -2147483648) < (v5254 ^ -2147483648);
  int v5257;
  if (v5266) {
    v5257 = 1;
  } else {
    v5257 = 0;
  }
  int * v5258 = v5249->regs;
  v5258[28] = v5257;
  struct StateT * v5260 = slot_98(v5249);
  return v5260;
}

struct StateT * slot_182(struct StateT * v8804) {
  int v8805 = v8804->timer;
  int v8813 = v8805 + 1;
  v8804->timer = v8813;
  int * v8807 = v8804->regs;
  int v8808 = v8807[6];
  int v8809 = v8807[12];
  int v8817 = v8808 * v8809;
  v8807[12] = v8817;
  struct StateT * v8811 = slot_183(v8804);
  return v8811;
}

struct StateT * slot_38(struct StateT * v3188) {
  int v3189 = v3188->timer;
  int v3197 = v3189 + 1;
  v3188->timer = v3197;
  int * v3191 = v3188->regs;
  int v3192 = v3191[7];
  int v3193 = v3191[12];
  int v3202 = (((((int)((unsigned int)v3192 >> 16)) * ((int)((unsigned int)v3193 >> 16))) + ((int)((unsigned int)((v3192 & 65535) * ((int)((unsigned int)v3193 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3192 >> 16)) * (v3193 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3192 & 65535) * (v3193 & 65535)) >> 16)) + (((v3192 & 65535) * ((int)((unsigned int)v3193 >> 16))) & 65535)) + ((((int)((unsigned int)v3192 >> 16)) * (v3193 & 65535)) & 65535)) >> 16));
  v3191[6] = v3202;
  struct StateT * v3195 = slot_39(v3188);
  return v3195;
}

struct StateT * slot_178(struct StateT * v8737) {
  int v8738 = v8737->timer;
  int v8746 = v8738 + 1;
  v8737->timer = v8746;
  int * v8740 = v8737->regs;
  int v8741 = v8740[6];
  int v8742 = v8740[13];
  int v8751 = v8741 * v8742;
  v8740[30] = v8751;
  struct StateT * v8744 = slot_179(v8737);
  return v8744;
}

struct StateT * slot_106(struct StateT * v5430) {
  int v5431 = v5430->timer;
  int v5439 = v5431 + 1;
  v5430->timer = v5439;
  int * v5433 = v5430->regs;
  int v5434 = v5433[18];
  int v5435 = v5433[6];
  int v5443 = v5434 + v5435;
  v5433[6] = v5443;
  struct StateT * v5437 = slot_107(v5430);
  return v5437;
}

struct StateT * slot_98(struct StateT * v5274) {
  int v5275 = v5274->timer;
  int v5283 = v5275 + 1;
  v5274->timer = v5283;
  int * v5277 = v5274->regs;
  int v5278 = v5277[30];
  int v5279 = v5277[7];
  int v5287 = v5278 + v5279;
  v5277[7] = v5287;
  struct StateT * v5281 = slot_99(v5274);
  return v5281;
}

struct StateT * slot_159(struct StateT * v7404) {
  int * v7405 = v7404->saved_regs;
  int * v7406 = v7404->regs;
  int v7407 = v7406[5];
  v7405[5] = v7407;
  int v7409 = v7404->timer;
  int v7425 = v7409 + 1;
  v7404->timer = v7425;
  int * v7411 = v7404->regs;
  int v7412 = v7411[28];
  int v7413 = v7411[5];
  bool v7428 = (v7412 ^ -2147483648) < (v7413 ^ -2147483648);
  int v7416;
  if (v7428) {
    v7416 = 1;
  } else {
    v7416 = 0;
  }
  int * v7417 = v7404->regs;
  v7417[5] = v7416;
  struct StateT * v7419 = slot_160(v7404);
  return v7419;
}

struct StateT * slot_46(struct StateT * v3320) {
  int v3321 = v3320->timer;
  int v3329 = v3321 + 1;
  v3320->timer = v3329;
  int * v3323 = v3320->regs;
  int v3324 = v3323[28];
  int v3325 = v3323[13];
  int v3334 = (((((int)((unsigned int)v3324 >> 16)) * ((int)((unsigned int)v3325 >> 16))) + ((int)((unsigned int)((v3324 & 65535) * ((int)((unsigned int)v3325 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3324 >> 16)) * (v3325 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3324 & 65535) * (v3325 & 65535)) >> 16)) + (((v3324 & 65535) * ((int)((unsigned int)v3325 >> 16))) & 65535)) + ((((int)((unsigned int)v3324 >> 16)) * (v3325 & 65535)) & 65535)) >> 16));
  v3323[19] = v3334;
  struct StateT * v3327 = slot_47(v3320);
  return v3327;
}

struct StateT * slot_212(struct StateT * v9366) {
  int v9367 = v9366->timer;
  int v9375 = v9367 + 1;
  v9366->timer = v9375;
  int * v9369 = v9366->regs;
  int v9370 = v9369[13];
  int v9371 = v9369[17];
  int v9380 = (((((int)((unsigned int)v9370 >> 16)) * ((int)((unsigned int)v9371 >> 16))) + ((int)((unsigned int)((v9370 & 65535) * ((int)((unsigned int)v9371 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v9370 >> 16)) * (v9371 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v9370 & 65535) * (v9371 & 65535)) >> 16)) + (((v9370 & 65535) * ((int)((unsigned int)v9371 >> 16))) & 65535)) + ((((int)((unsigned int)v9370 >> 16)) * (v9371 & 65535)) & 65535)) >> 16));
  v9369[5] = v9380;
  struct StateT * v9373 = slot_213(v9366);
  return v9373;
}

struct StateT * slot_132(struct StateT * v6897) {
  int v6898 = v6897->timer;
  int v6906 = v6898 + 1;
  v6897->timer = v6906;
  int * v6900 = v6897->regs;
  int v6901 = v6900[29];
  int v6902 = v6900[12];
  int v6911 = (((((int)((unsigned int)v6901 >> 16)) * ((int)((unsigned int)v6902 >> 16))) + ((int)((unsigned int)((v6901 & 65535) * ((int)((unsigned int)v6902 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6901 >> 16)) * (v6902 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6901 & 65535) * (v6902 & 65535)) >> 16)) + (((v6901 & 65535) * ((int)((unsigned int)v6902 >> 16))) & 65535)) + ((((int)((unsigned int)v6901 >> 16)) * (v6902 & 65535)) & 65535)) >> 16));
  v6900[30] = v6911;
  struct StateT * v6904 = slot_133(v6897);
  return v6904;
}

struct StateT * slot_130(struct StateT * v6863) {
  int v6864 = v6863->timer;
  int v6872 = v6864 + 1;
  v6863->timer = v6872;
  int * v6866 = v6863->regs;
  int v6867 = v6866[6];
  int v6868 = v6866[12];
  int v6877 = (((((int)((unsigned int)v6867 >> 16)) * ((int)((unsigned int)v6868 >> 16))) + ((int)((unsigned int)((v6867 & 65535) * ((int)((unsigned int)v6868 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6867 >> 16)) * (v6868 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6867 & 65535) * (v6868 & 65535)) >> 16)) + (((v6867 & 65535) * ((int)((unsigned int)v6868 >> 16))) & 65535)) + ((((int)((unsigned int)v6867 >> 16)) * (v6868 & 65535)) & 65535)) >> 16));
  v6866[17] = v6877;
  struct StateT * v6870 = slot_131(v6863);
  return v6870;
}

struct StateT * slot_211(struct StateT * v9350) {
  int v9351 = v9350->timer;
  int v9359 = v9351 + 1;
  v9350->timer = v9359;
  int * v9353 = v9350->regs;
  int v9354 = v9353[12];
  int v9355 = v9353[5];
  int v9363 = v9354 | v9355;
  v9353[12] = v9363;
  struct StateT * v9357 = slot_212(v9350);
  return v9357;
}

struct StateT * slot_20(struct StateT * v1903) {
  int v1904 = v1903->timer;
  int v1912 = v1904 + 1;
  v1903->timer = v1912;
  int * v1906 = v1903->regs;
  int v1907 = v1906[6];
  int v1908 = v1906[15];
  int v1916 = v1907 + v1908;
  v1906[6] = v1916;
  struct StateT * v1910 = slot_21(v1903);
  return v1910;
}

struct StateT * slot_141(struct StateT * v7057) {
  int v7058 = v7057->timer;
  int v7066 = v7058 + 1;
  v7057->timer = v7066;
  int * v7060 = v7057->regs;
  int v7061 = v7060[31];
  int v7062 = v7060[29];
  int v7070 = v7061 + v7062;
  v7060[29] = v7070;
  struct StateT * v7064 = slot_142(v7057);
  return v7064;
}

struct StateT * slot_61(struct StateT * v3607) {
  int v3608 = v3607->timer;
  int v3616 = v3608 + 1;
  v3607->timer = v3616;
  int * v3610 = v3607->regs;
  int v3611 = v3610[19];
  int v3612 = v3610[6];
  int v3620 = v3611 + v3612;
  v3610[6] = v3620;
  struct StateT * v3614 = slot_62(v3607);
  return v3614;
}

struct StateT * slot_30(struct StateT * v3045) {
  int v3046 = v3045->timer;
  int v3054 = v3046 + 1;
  v3045->timer = v3054;
  int * v3048 = v3045->regs;
  int v3049 = v3048[29];
  int v3050 = v3048[5];
  int v3059 = v3049 + v3050;
  v3048[31] = v3059;
  struct StateT * v3052 = slot_31(v3045);
  return v3052;
}

struct StateT * slot_4(struct StateT * v961) {
  int v962 = v961->timer;
  int v1132 = v962 + 1;
  v961->timer = v1132;
  int * v964 = v961->regs;
  int v965 = v964[2];
  int v966 = v964[19];
  int * v967 = v961->cache_tags;
  int v1137 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
  int v968 = v967[v1137];
  int v1138 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + 1;
  int v969 = v967[v1138];
  int v1139 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
  int v970 = v967[v1139];
  int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v971 = v967[v1140];
  int v972 = v961->timer;
  int v1141 = v972 + ((100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1141;
  bool v1142 = !(((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1066;
  if (v1142) {
    int * v974 = v961->cache_age;
    int v1144 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v975 = v974[v1144];
    int v976 = v974[v1137];
    int v1145 = v976 + ((int)((unsigned int)(v976 - v975) >> 31));
    v974[v1137] = v1145;
    int * v978 = v961->cache_age;
    int v979 = v978[v1138];
    int v1147 = v979 + ((int)((unsigned int)(v979 - v975) >> 31));
    v978[v1138] = v1147;
    int * v981 = v961->cache_age;
    v981[v1144] = 0;
    v1066 = v1144;
  } else {
    int * v984 = v961->cache_age;
    int v1151 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
    int v985 = v984[v1151];
    int * v986 = v961->cache_tags;
    int v987 = v986[v1151];
    int v988 = v984[v1138];
    int v989 = v986[v1138];
    bool v1153 = !(((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
    int v1043;
    if (v1153) {
      int * v990 = v961->cache_age;
      int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
      int v991 = v990[v1155];
      int v992 = v990[v1139];
      int v1156 = v992 + ((int)((unsigned int)(v992 - v991) >> 31));
      v990[v1139] = v1156;
      int * v994 = v961->cache_age;
      int v995 = v994[v1140];
      int v1158 = v995 + ((int)((unsigned int)(v995 - v991) >> 31));
      v994[v1140] = v1158;
      int * v997 = v961->cache_age;
      v997[v1155] = 0;
      v1043 = v1155;
    } else {
      int * v1000 = v961->cache_age;
      int v1162 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
      int v1001 = v1000[v1162];
      int * v1002 = v961->cache_tags;
      int v1003 = v1002[v1162];
      int v1004 = v1000[v1140];
      int v1005 = v1002[v1140];
      int * v1006 = v961->cache_dirty;
      int v1165 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1007 = v1006[v1165];
      bool v1166 = !(v1007 == 0);
      if (v1166) {
        int * v1008 = v961->cache_tags;
        int v1009 = v1008[v1165];
        int * v1010 = v961->cache_vals;
        int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1011 = v1010[v1169];
        int v1170 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1012 = v1010[v1170];
        int * v1013 = v961->mem;
        int v1172 = v1009 * 2;
        v1013[v1172] = v1011;
        int * v1015 = v961->mem;
        int v1175 = (v1009 * 2) + 1;
        v1015[v1175] = v1012;
        ;
      } else {
        ;
      }
      int * v1020 = v961->mem;
      int v1180 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
      int v1021 = v1020[v1180];
      int v1181 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
      int v1022 = v1020[v1181];
      int * v1023 = v961->cache_vals;
      int v1183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1023[v1183] = v1021;
      int * v1025 = v961->cache_vals;
      int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1025[v1186] = v1022;
      int * v1027 = v961->cache_tags;
      int v1189 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
      v1027[v1165] = v1189;
      int * v1029 = v961->cache_dirty;
      v1029[v1165] = 0;
      int * v1031 = v961->cache_age;
      v1031[v1165] = 1;
      int * v1033 = v961->cache_age;
      int v1034 = v1033[v1165];
      int v1035 = v1033[v1139];
      int v1195 = v1035 + ((int)((unsigned int)(v1035 - v1034) >> 31));
      v1033[v1139] = v1195;
      int * v1037 = v961->cache_age;
      int v1038 = v1037[v1140];
      int v1197 = v1038 + ((int)((unsigned int)(v1038 - v1034) >> 31));
      v1037[v1140] = v1197;
      int * v1040 = v961->cache_age;
      v1040[v1165] = 0;
      v1043 = v1165;
    }
    int * v1044 = v961->cache_vals;
    int v1200 = v1043 * 2;
    int v1045 = v1044[v1200];
    int v1201 = (v1043 * 2) + 1;
    int v1046 = v1044[v1201];
    int v1202 = (((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1044[v1202] = v1045;
    int * v1048 = v961->cache_vals;
    int v1205 = ((((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1048[v1205] = v1046;
    int * v1050 = v961->cache_tags;
    int v1208 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1209 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1050[v1208] = v1209;
    int * v1052 = v961->cache_dirty;
    v1052[v1208] = 0;
    int * v1054 = v961->cache_age;
    v1054[v1208] = 1;
    int * v1056 = v961->cache_age;
    int v1057 = v1056[v1208];
    int v1058 = v1056[v1137];
    int v1215 = v1058 + ((int)((unsigned int)(v1058 - v1057) >> 31));
    v1056[v1137] = v1215;
    int * v1060 = v961->cache_age;
    int v1061 = v1060[v1138];
    int v1217 = v1061 + ((int)((unsigned int)(v1061 - v1057) >> 31));
    v1060[v1138] = v1217;
    int * v1063 = v961->cache_age;
    v1063[v1208] = 0;
    v1066 = v1208;
  }
  int * v1067 = v961->cache_vals;
  int v1220 = (v1066 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1067[v1220] = v966;
  int * v1069 = v961->cache_tags;
  int v1070 = v1069[v1139];
  int v1071 = v1069[v1140];
  bool v1223 = !(((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1125;
  if (v1223) {
    int * v1072 = v961->cache_age;
    int v1225 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v1073 = v1072[v1225];
    int v1074 = v1072[v1139];
    int v1226 = v1074 + ((int)((unsigned int)(v1074 - v1073) >> 31));
    v1072[v1139] = v1226;
    int * v1076 = v961->cache_age;
    int v1077 = v1076[v1140];
    int v1228 = v1077 + ((int)((unsigned int)(v1077 - v1073) >> 31));
    v1076[v1140] = v1228;
    int * v1079 = v961->cache_age;
    v1079[v1225] = 0;
    v1125 = v1225;
  } else {
    int * v1082 = v961->cache_age;
    int v1232 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
    int v1083 = v1082[v1232];
    int * v1084 = v961->cache_tags;
    int v1085 = v1084[v1232];
    int v1086 = v1082[v1140];
    int v1087 = v1084[v1140];
    int * v1088 = v961->cache_dirty;
    int v1235 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1089 = v1088[v1235];
    bool v1236 = !(v1089 == 0);
    if (v1236) {
      int * v1090 = v961->cache_tags;
      int v1091 = v1090[v1235];
      int * v1092 = v961->cache_vals;
      int v1239 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1093 = v1092[v1239];
      int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1094 = v1092[v1240];
      int * v1095 = v961->mem;
      int v1242 = v1091 * 2;
      v1095[v1242] = v1093;
      int * v1097 = v961->mem;
      int v1245 = (v1091 * 2) + 1;
      v1097[v1245] = v1094;
      ;
    } else {
      ;
    }
    int * v1102 = v961->mem;
    int v1250 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
    int v1103 = v1102[v1250];
    int v1251 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
    int v1104 = v1102[v1251];
    int * v1105 = v961->cache_vals;
    int v1253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1105[v1253] = v1103;
    int * v1107 = v961->cache_vals;
    int v1256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1107[v1256] = v1104;
    int * v1109 = v961->cache_tags;
    int v1259 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1109[v1235] = v1259;
    int * v1111 = v961->cache_dirty;
    v1111[v1235] = 0;
    int * v1113 = v961->cache_age;
    v1113[v1235] = 1;
    int * v1115 = v961->cache_age;
    int v1116 = v1115[v1235];
    int v1117 = v1115[v1139];
    int v1265 = v1117 + ((int)((unsigned int)(v1117 - v1116) >> 31));
    v1115[v1139] = v1265;
    int * v1119 = v961->cache_age;
    int v1120 = v1119[v1140];
    int v1267 = v1120 + ((int)((unsigned int)(v1120 - v1116) >> 31));
    v1119[v1140] = v1267;
    int * v1122 = v961->cache_age;
    v1122[v1235] = 0;
    v1125 = v1235;
  }
  int * v1126 = v961->cache_vals;
  int v1270 = (v1125 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1126[v1270] = v966;
  int * v1128 = v961->cache_dirty;
  v1128[v1125] = 1;
  struct StateT * v1130 = slot_5(v961);
  return v1130;
}

struct StateT * slot_18(struct StateT * v1862) {
  int v1863 = v1862->timer;
  int v1875 = v1863 + 1;
  v1862->timer = v1875;
  int * v1865 = v1862->regs;
  int v1866 = v1865[17];
  int v1867 = v1865[5];
  bool v1879 = (v1866 ^ -2147483648) < (v1867 ^ -2147483648);
  int v1870;
  if (v1879) {
    v1870 = 1;
  } else {
    v1870 = 0;
  }
  int * v1871 = v1862->regs;
  v1871[15] = v1870;
  struct StateT * v1873 = slot_19(v1862);
  return v1873;
}

struct StateT * slot_9(struct StateT * v1711) {
  int v1712 = v1711->timer;
  int v1720 = v1712 + 1;
  v1711->timer = v1720;
  int * v1714 = v1711->regs;
  int v1715 = v1714[14];
  int v1716 = v1714[12];
  int v1725 = (((((int)((unsigned int)v1715 >> 16)) * ((int)((unsigned int)v1716 >> 16))) + ((int)((unsigned int)((v1715 & 65535) * ((int)((unsigned int)v1716 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1715 >> 16)) * (v1716 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1715 & 65535) * (v1716 & 65535)) >> 16)) + (((v1715 & 65535) * ((int)((unsigned int)v1716 >> 16))) & 65535)) + ((((int)((unsigned int)v1715 >> 16)) * (v1716 & 65535)) & 65535)) >> 16));
  v1714[17] = v1725;
  struct StateT * v1718 = slot_10(v1711);
  return v1718;
}

struct StateT * slot_183(struct StateT * v8820) {
  int v8821 = v8820->timer;
  int v8829 = v8821 + 1;
  v8820->timer = v8829;
  int * v8823 = v8820->regs;
  int v8824 = v8823[28];
  int v8825 = v8823[5];
  int v8833 = v8824 + v8825;
  v8823[5] = v8833;
  struct StateT * v8827 = slot_184(v8820);
  return v8827;
}

struct StateT * slot_240(struct StateT * v11844) {
  int v11845 = v11844->timer;
  int v11848 = v11845 + 1;
  v11844->timer = v11848;
  return v11844;
}

struct StateT * slot_247(struct StateT * v11930) {
  int v11931 = v11930->timer;
  int v11939 = v11931 + 1;
  v11930->timer = v11939;
  int * v11933 = v11930->regs;
  int v11934 = v11933[12];
  int v11935 = v11933[17];
  int v11943 = v11934 * v11935;
  v11933[12] = v11943;
  struct StateT * v11937 = slot_248(v11930);
  return v11937;
}

struct StateT * slot_43(struct StateT * v3273) {
  int v3274 = v3273->timer;
  int v3281 = v3274 + 1;
  v3273->timer = v3281;
  int * v3276 = v3273->regs;
  int v3277 = v3276[5];
  int v3284 = v3277 << 13;
  v3276[5] = v3284;
  struct StateT * v3279 = slot_44(v3273);
  return v3279;
}

struct StateT * slot_70(struct StateT * v3787) {
  int * v3788 = v3787->saved_regs;
  int v3789 = v3788[7];
  int v3790 = v3788[29];
  bool v3818 = v3789 == v3790;
  struct StateT * v3813;
  if (v3818) {
    int v3791 = v3787->timer;
    int v3819 = v3791 + 15;
    v3787->timer = v3819;
    int * v3793 = v3787->saved_regs;
    int v3794 = v3793[28];
    int * v3795 = v3787->regs;
    v3795[28] = v3794;
    int * v3797 = v3787->saved_regs;
    int v3798 = v3797[29];
    int * v3799 = v3787->regs;
    v3799[29] = v3798;
    int * v3801 = v3787->saved_regs;
    int v3802 = v3801[7];
    int * v3803 = v3787->regs;
    v3803[7] = v3802;
    int * v3805 = v3787->saved_regs;
    int v3806 = v3805[5];
    int * v3807 = v3787->regs;
    v3807[5] = v3806;
    struct StateT * v3809 = slot_71(v3787);
    v3813 = v3809;
  } else {
    struct StateT * v3811 = slot_72(v3787);
    v3813 = v3811;
  }
  return v3813;
}

struct StateT * slot_168(struct StateT * v8203) {
  int v8204 = v8203->timer;
  int v8211 = v8204 + 1;
  v8203->timer = v8211;
  int * v8206 = v8203->regs;
  int v8207 = v8206[28];
  int v8214 = v8207 << 13;
  v8206[28] = v8214;
  struct StateT * v8209 = slot_169(v8203);
  return v8209;
}

struct StateT * slot_76(struct StateT * v4516) {
  int v4517 = v4516->timer;
  int v4524 = v4517 + 1;
  v4516->timer = v4524;
  int * v4519 = v4516->regs;
  int v4520 = v4519[28];
  int v4528 = (int)((unsigned int)v4520 >> 19);
  v4519[17] = v4528;
  struct StateT * v4522 = slot_78(v4516);
  return v4522;
}

struct StateT * slot_6(struct StateT * v1480) {
  int v1481 = v1480->timer;
  int v1591 = v1481 + 1;
  v1480->timer = v1591;
  int * v1483 = v1480->regs;
  int v1484 = v1483[11];
  int * v1485 = v1480->cache_tags;
  int v1595 = (((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1486 = v1485[v1595];
  int v1596 = ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1487 = v1485[v1596];
  int v1597 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1488 = v1485[v1597];
  int v1598 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1489 = v1485[v1598];
  int v1490 = v1480->timer;
  int v1599 = v1490 + ((100 ^ (((~(((v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1480->timer = v1599;
  int * v1492 = v1480->cache_vals;
  bool v1600 = !(((~(((v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1585;
  if (v1600) {
    int * v1493 = v1480->cache_age;
    int v1602 = ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1494 = v1493[v1602];
    int v1495 = v1493[v1595];
    int v1603 = v1495 + ((int)((unsigned int)(v1495 - v1494) >> 31));
    v1493[v1595] = v1603;
    int * v1497 = v1480->cache_age;
    int v1498 = v1497[v1596];
    int v1605 = v1498 + ((int)((unsigned int)(v1498 - v1494) >> 31));
    v1497[v1596] = v1605;
    int * v1500 = v1480->cache_age;
    v1500[v1602] = 0;
    v1585 = v1602;
  } else {
    int * v1503 = v1480->cache_age;
    int v1609 = (((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1504 = v1503[v1609];
    int * v1505 = v1480->cache_tags;
    int v1506 = v1505[v1609];
    int v1507 = v1503[v1596];
    int v1508 = v1505[v1596];
    bool v1611 = !(((~(((v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1562;
    if (v1611) {
      int * v1509 = v1480->cache_age;
      int v1613 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1510 = v1509[v1613];
      int v1511 = v1509[v1597];
      int v1614 = v1511 + ((int)((unsigned int)(v1511 - v1510) >> 31));
      v1509[v1597] = v1614;
      int * v1513 = v1480->cache_age;
      int v1514 = v1513[v1598];
      int v1616 = v1514 + ((int)((unsigned int)(v1514 - v1510) >> 31));
      v1513[v1598] = v1616;
      int * v1516 = v1480->cache_age;
      v1516[v1613] = 0;
      v1562 = v1613;
    } else {
      int * v1519 = v1480->cache_age;
      int v1620 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1520 = v1519[v1620];
      int * v1521 = v1480->cache_tags;
      int v1522 = v1521[v1620];
      int v1523 = v1519[v1598];
      int v1524 = v1521[v1598];
      int * v1525 = v1480->cache_dirty;
      int v1623 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1526 = v1525[v1623];
      bool v1624 = !(v1526 == 0);
      if (v1624) {
        int * v1527 = v1480->cache_tags;
        int v1528 = v1527[v1623];
        int * v1529 = v1480->cache_vals;
        int v1627 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1530 = v1529[v1627];
        int v1628 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1531 = v1529[v1628];
        int * v1532 = v1480->mem;
        int v1630 = v1528 * 2;
        v1532[v1630] = v1530;
        int * v1534 = v1480->mem;
        int v1633 = (v1528 * 2) + 1;
        v1534[v1633] = v1531;
        ;
      } else {
        ;
      }
      int * v1539 = v1480->mem;
      int v1638 = ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) * 2;
      int v1540 = v1539[v1638];
      int v1639 = (((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1541 = v1539[v1639];
      int * v1542 = v1480->cache_vals;
      int v1641 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1542[v1641] = v1540;
      int * v1544 = v1480->cache_vals;
      int v1644 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1544[v1644] = v1541;
      int * v1546 = v1480->cache_tags;
      int v1647 = (int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1);
      v1546[v1623] = v1647;
      int * v1548 = v1480->cache_dirty;
      v1548[v1623] = 0;
      int * v1550 = v1480->cache_age;
      v1550[v1623] = 1;
      int * v1552 = v1480->cache_age;
      int v1553 = v1552[v1623];
      int v1554 = v1552[v1597];
      int v1653 = v1554 + ((int)((unsigned int)(v1554 - v1553) >> 31));
      v1552[v1597] = v1653;
      int * v1556 = v1480->cache_age;
      int v1557 = v1556[v1598];
      int v1655 = v1557 + ((int)((unsigned int)(v1557 - v1553) >> 31));
      v1556[v1598] = v1655;
      int * v1559 = v1480->cache_age;
      v1559[v1623] = 0;
      v1562 = v1623;
    }
    int * v1563 = v1480->cache_vals;
    int v1658 = v1562 * 2;
    int v1564 = v1563[v1658];
    int v1659 = (v1562 * 2) + 1;
    int v1565 = v1563[v1659];
    int v1660 = (((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1504 + ((~(((v1506 ^ -1) | (-(v1506 ^ -1))) >> 31)) & 2)) - (v1507 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1563[v1660] = v1564;
    int * v1567 = v1480->cache_vals;
    int v1663 = ((((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1504 + ((~(((v1506 ^ -1) | (-(v1506 ^ -1))) >> 31)) & 2)) - (v1507 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1567[v1663] = v1565;
    int * v1569 = v1480->cache_tags;
    int v1666 = ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1504 + ((~(((v1506 ^ -1) | (-(v1506 ^ -1))) >> 31)) & 2)) - (v1507 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1667 = (int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1);
    v1569[v1666] = v1667;
    int * v1571 = v1480->cache_dirty;
    v1571[v1666] = 0;
    int * v1573 = v1480->cache_age;
    v1573[v1666] = 1;
    int * v1575 = v1480->cache_age;
    int v1576 = v1575[v1666];
    int v1577 = v1575[v1595];
    int v1673 = v1577 + ((int)((unsigned int)(v1577 - v1576) >> 31));
    v1575[v1595] = v1673;
    int * v1579 = v1480->cache_age;
    int v1580 = v1579[v1596];
    int v1675 = v1580 + ((int)((unsigned int)(v1580 - v1576) >> 31));
    v1579[v1596] = v1675;
    int * v1582 = v1480->cache_age;
    v1582[v1666] = 0;
    v1585 = v1666;
  }
  int v1678 = (v1585 * 2) + (((int)((unsigned int)(v1484 + 4) >> 2)) & 1);
  int v1586 = v1492[v1678];
  int * v1587 = v1480->regs;
  v1587[15] = v1586;
  struct StateT * v1589 = slot_7(v1480);
  return v1589;
}

struct StateT * slot_225(struct StateT * v10258) {
  int v10259 = v10258->timer;
  int v10266 = v10259 + 1;
  v10258->timer = v10266;
  int * v10261 = v10258->regs;
  int v10262 = v10261[17];
  int v10269 = (int)((unsigned int)v10262 >> 19);
  v10261[17] = v10269;
  struct StateT * v10264 = slot_227(v10258);
  return v10264;
}

struct StateT * slot_55(struct StateT * v3492) {
  int v3493 = v3492->timer;
  int v3501 = v3493 + 1;
  v3492->timer = v3501;
  int * v3495 = v3492->regs;
  int v3496 = v3495[29];
  int v3497 = v3495[5];
  int v3506 = v3496 + v3497;
  v3495[7] = v3506;
  struct StateT * v3499 = slot_56(v3492);
  return v3499;
}

struct StateT * slot_213(struct StateT * v9383) {
  int v9384 = v9383->timer;
  int v9392 = v9384 + 1;
  v9383->timer = v9392;
  int * v9386 = v9383->regs;
  int v9387 = v9386[13];
  int v9388 = v9386[17];
  int v9396 = v9387 * v9388;
  v9386[13] = v9396;
  struct StateT * v9390 = slot_214(v9383);
  return v9390;
}

struct StateT * slot_82(struct StateT * v4993) {
  int v4994 = v4993->timer;
  int v5002 = v4994 + 1;
  v4993->timer = v5002;
  int * v4996 = v4993->regs;
  int v4997 = v4996[7];
  int v4998 = v4996[28];
  int v5006 = v4997 | v4998;
  v4996[7] = v5006;
  struct StateT * v5000 = slot_83(v4993);
  return v5000;
}

struct StateT * slot_161(struct StateT * v7487) {
  int v7488 = v7487->timer;
  int v7496 = v7488 + 1;
  v7487->timer = v7496;
  int * v7490 = v7487->regs;
  int v7491 = v7490[5];
  int v7492 = v7490[28];
  int v7500 = v7491 + v7492;
  v7490[28] = v7500;
  struct StateT * v7494 = slot_163(v7487);
  return v7494;
}

struct StateT * slot_185(struct StateT * v8853) {
  int v8854 = v8853->timer;
  int v8866 = v8854 + 1;
  v8853->timer = v8866;
  int * v8856 = v8853->regs;
  int v8857 = v8856[5];
  int v8858 = v8856[28];
  bool v8870 = (v8857 ^ -2147483648) < (v8858 ^ -2147483648);
  int v8861;
  if (v8870) {
    v8861 = 1;
  } else {
    v8861 = 0;
  }
  int * v8862 = v8853->regs;
  v8862[7] = v8861;
  struct StateT * v8864 = slot_186(v8853);
  return v8864;
}

struct StateT * slot_91(struct StateT * v5141) {
  int v5142 = v5141->timer;
  int v5150 = v5142 + 1;
  v5141->timer = v5150;
  int * v5144 = v5141->regs;
  int v5145 = v5144[29];
  int v5146 = v5144[13];
  int v5155 = (((((int)((unsigned int)v5145 >> 16)) * ((int)((unsigned int)v5146 >> 16))) + ((int)((unsigned int)((v5145 & 65535) * ((int)((unsigned int)v5146 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v5145 >> 16)) * (v5146 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v5145 & 65535) * (v5146 & 65535)) >> 16)) + (((v5145 & 65535) * ((int)((unsigned int)v5146 >> 16))) & 65535)) + ((((int)((unsigned int)v5145 >> 16)) * (v5146 & 65535)) & 65535)) >> 16));
  v5144[18] = v5155;
  struct StateT * v5148 = slot_92(v5141);
  return v5148;
}

struct StateT * slot_58(struct StateT * v3541) {
  int v3542 = v3541->timer;
  int v3550 = v3542 + 1;
  v3541->timer = v3550;
  int * v3544 = v3541->regs;
  int v3545 = v3544[18];
  int v3546 = v3544[6];
  int v3555 = v3545 + v3546;
  v3544[5] = v3555;
  struct StateT * v3548 = slot_59(v3541);
  return v3548;
}

struct StateT * slot_89(struct StateT * v5107) {
  int v5108 = v5107->timer;
  int v5116 = v5108 + 1;
  v5107->timer = v5116;
  int * v5110 = v5107->regs;
  int v5111 = v5110[6];
  int v5112 = v5110[13];
  int v5121 = (((((int)((unsigned int)v5111 >> 16)) * ((int)((unsigned int)v5112 >> 16))) + ((int)((unsigned int)((v5111 & 65535) * ((int)((unsigned int)v5112 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v5111 >> 16)) * (v5112 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v5111 & 65535) * (v5112 & 65535)) >> 16)) + (((v5111 & 65535) * ((int)((unsigned int)v5112 >> 16))) & 65535)) + ((((int)((unsigned int)v5111 >> 16)) * (v5112 & 65535)) & 65535)) >> 16));
  v5110[8] = v5121;
  struct StateT * v5114 = slot_90(v5107);
  return v5114;
}

struct StateT * slot_66(struct StateT * v3695) {
  int v3696 = v3695->timer;
  int v3704 = v3696 + 1;
  v3695->timer = v3704;
  int * v3698 = v3695->regs;
  int v3699 = v3698[5];
  int v3700 = v3698[28];
  int v3708 = v3699 + v3700;
  v3698[28] = v3708;
  struct StateT * v3702 = slot_67(v3695);
  return v3702;
}

struct StateT * slot_140(struct StateT * v7032) {
  int v7033 = v7032->timer;
  int v7045 = v7033 + 1;
  v7032->timer = v7045;
  int * v7035 = v7032->regs;
  int v7036 = v7035[29];
  int v7037 = v7035[28];
  bool v7049 = (v7036 ^ -2147483648) < (v7037 ^ -2147483648);
  int v7040;
  if (v7049) {
    v7040 = 1;
  } else {
    v7040 = 0;
  }
  int * v7041 = v7032->regs;
  v7041[7] = v7040;
  struct StateT * v7043 = slot_141(v7032);
  return v7043;
}

struct StateT * slot_49(struct StateT * v3369) {
  int v3370 = v3369->timer;
  int v3378 = v3370 + 1;
  v3369->timer = v3378;
  int * v3372 = v3369->regs;
  int v3373 = v3372[7];
  int v3374 = v3372[17];
  int v3382 = v3373 + v3374;
  v3372[17] = v3382;
  struct StateT * v3376 = slot_50(v3369);
  return v3376;
}

struct StateT * slot_216(struct StateT * v9438) {
  int v9439 = v9438->timer;
  int v9447 = v9439 + 1;
  v9438->timer = v9447;
  int * v9441 = v9438->regs;
  int v9442 = v9441[12];
  int v9443 = v9441[17];
  int v9451 = v9442 * v9443;
  v9441[12] = v9451;
  struct StateT * v9445 = slot_217(v9438);
  return v9445;
}

struct StateT * slot_50(struct StateT * v3385) {
  int v3386 = v3385->timer;
  int v3398 = v3386 + 1;
  v3385->timer = v3398;
  int * v3388 = v3385->regs;
  int v3389 = v3388[6];
  int v3390 = v3388[30];
  bool v3402 = (v3389 ^ -2147483648) < (v3390 ^ -2147483648);
  int v3393;
  if (v3402) {
    v3393 = 1;
  } else {
    v3393 = 0;
  }
  int * v3394 = v3385->regs;
  v3394[30] = v3393;
  struct StateT * v3396 = slot_51(v3385);
  return v3396;
}

struct StateT * slot_37(struct StateT * v3172) {
  int v3173 = v3172->timer;
  int v3181 = v3173 + 1;
  v3172->timer = v3181;
  int * v3175 = v3172->regs;
  int v3176 = v3175[17];
  int v3177 = v3175[31];
  int v3185 = v3176 | v3177;
  v3175[17] = v3185;
  struct StateT * v3179 = slot_38(v3172);
  return v3179;
}

struct StateT * slot_114(struct StateT * v5580) {
  int * v5581 = v5580->saved_regs;
  int * v5582 = v5580->regs;
  int v5583 = v5582[5];
  v5581[5] = v5583;
  int v5585 = v5580->timer;
  int v5601 = v5585 + 1;
  v5580->timer = v5601;
  int * v5587 = v5580->regs;
  int v5588 = v5587[28];
  int v5589 = v5587[5];
  bool v5604 = (v5588 ^ -2147483648) < (v5589 ^ -2147483648);
  int v5592;
  if (v5604) {
    v5592 = 1;
  } else {
    v5592 = 0;
  }
  int * v5593 = v5580->regs;
  v5593[5] = v5592;
  struct StateT * v5595 = slot_115(v5580);
  return v5595;
}

struct StateT * slot_135(struct StateT * v6948) {
  int v6949 = v6948->timer;
  int v6957 = v6949 + 1;
  v6948->timer = v6957;
  int * v6951 = v6948->regs;
  int v6952 = v6951[29];
  int v6953 = v6951[13];
  int v6962 = v6952 * v6953;
  v6951[9] = v6962;
  struct StateT * v6955 = slot_136(v6948);
  return v6955;
}

struct StateT * slot_248(struct StateT * v11946) {
  int v11947 = v11946->timer;
  int v11959 = v11947 + 1;
  v11946->timer = v11959;
  int * v11949 = v11946->regs;
  int v11950 = v11949[13];
  int v11951 = v11949[14];
  bool v11963 = (v11950 ^ -2147483648) < (v11951 ^ -2147483648);
  int v11954;
  if (v11963) {
    v11954 = 1;
  } else {
    v11954 = 0;
  }
  int * v11955 = v11946->regs;
  v11955[14] = v11954;
  struct StateT * v11957 = slot_249(v11946);
  return v11957;
}

struct StateT * slot_59(struct StateT * v3558) {
  int v3559 = v3558->timer;
  int v3571 = v3559 + 1;
  v3558->timer = v3571;
  int * v3561 = v3558->regs;
  int v3562 = v3561[6];
  int v3563 = v3561[30];
  bool v3575 = (v3562 ^ -2147483648) < (v3563 ^ -2147483648);
  int v3566;
  if (v3575) {
    v3566 = 1;
  } else {
    v3566 = 0;
  }
  int * v3567 = v3558->regs;
  v3567[6] = v3566;
  struct StateT * v3569 = slot_60(v3558);
  return v3569;
}

struct StateT * slot_192(struct StateT * v8993) {
  int v8994 = v8993->timer;
  int v9002 = v8994 + 1;
  v8993->timer = v9002;
  int * v8996 = v8993->regs;
  int v8997 = v8996[7];
  int v8998 = v8996[12];
  int v9007 = v8997 + v8998;
  v8996[28] = v9007;
  struct StateT * v9000 = slot_193(v8993);
  return v9000;
}

struct StateT * slot_40(struct StateT * v3222) {
  int v3223 = v3222->timer;
  int v3231 = v3223 + 1;
  v3222->timer = v3231;
  int * v3225 = v3222->regs;
  int v3226 = v3225[28];
  int v3227 = v3225[12];
  int v3236 = (((((int)((unsigned int)v3226 >> 16)) * ((int)((unsigned int)v3227 >> 16))) + ((int)((unsigned int)((v3226 & 65535) * ((int)((unsigned int)v3227 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3226 >> 16)) * (v3227 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3226 & 65535) * (v3227 & 65535)) >> 16)) + (((v3226 & 65535) * ((int)((unsigned int)v3227 >> 16))) & 65535)) + ((((int)((unsigned int)v3226 >> 16)) * (v3227 & 65535)) & 65535)) >> 16));
  v3225[31] = v3236;
  struct StateT * v3229 = slot_41(v3222);
  return v3229;
}

struct StateT * slot_48(struct StateT * v3353) {
  int v3354 = v3353->timer;
  int v3362 = v3354 + 1;
  v3353->timer = v3362;
  int * v3356 = v3353->regs;
  int v3357 = v3356[30];
  int v3358 = v3356[6];
  int v3366 = v3357 + v3358;
  v3356[6] = v3366;
  struct StateT * v3360 = slot_49(v3353);
  return v3360;
}

struct StateT * slot_77(struct StateT * v4531) {
  int v4532 = v4531->timer;
  int v4544 = v4532 + 1;
  v4531->timer = v4544;
  int * v4534 = v4531->regs;
  int v4535 = v4534[28];
  int v4536 = v4534[5];
  bool v4548 = (v4535 ^ -2147483648) < (v4536 ^ -2147483648);
  int v4539;
  if (v4548) {
    v4539 = 1;
  } else {
    v4539 = 0;
  }
  int * v4540 = v4531->regs;
  v4540[5] = v4539;
  struct StateT * v4542 = slot_72(v4531);
  return v4542;
}

struct StateT * slot_85(struct StateT * v5039) {
  int v5040 = v5039->timer;
  int v5048 = v5040 + 1;
  v5039->timer = v5048;
  int * v5042 = v5039->regs;
  int v5043 = v5042[6];
  int v5044 = v5042[12];
  int v5053 = (((((int)((unsigned int)v5043 >> 16)) * ((int)((unsigned int)v5044 >> 16))) + ((int)((unsigned int)((v5043 & 65535) * ((int)((unsigned int)v5044 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v5043 >> 16)) * (v5044 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v5043 & 65535) * (v5044 & 65535)) >> 16)) + (((v5043 & 65535) * ((int)((unsigned int)v5044 >> 16))) & 65535)) + ((((int)((unsigned int)v5043 >> 16)) * (v5044 & 65535)) & 65535)) >> 16));
  v5042[17] = v5053;
  struct StateT * v5046 = slot_86(v5039);
  return v5046;
}

struct StateT * slot_75(struct StateT * v4502) {
  int v4503 = v4502->timer;
  int v4510 = v4503 + 1;
  v4502->timer = v4510;
  int * v4505 = v4502->regs;
  int v4506 = v4505[7];
  int v4513 = (int)((unsigned int)v4506 >> 19);
  v4505[7] = v4513;
  struct StateT * v4508 = slot_77(v4502);
  return v4508;
}

struct StateT * slot_72(struct StateT * v3855) {
  int v3856 = v3855->timer;
  int v4026 = v3856 + 1;
  v3855->timer = v4026;
  int * v3858 = v3855->regs;
  int v3859 = v3858[10];
  int v3860 = v3858[17];
  int * v3861 = v3855->cache_tags;
  int v4031 = (((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3862 = v3861[v4031];
  int v4032 = ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3863 = v3861[v4032];
  int v4033 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3864 = v3861[v4033];
  int v4034 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3865 = v3861[v4034];
  int v3866 = v3855->timer;
  int v4035 = v3866 + ((100 ^ (((~(((v3864 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3864 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3862 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3862 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3863 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3863 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3864 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3864 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3855->timer = v4035;
  bool v4036 = !(((~(((v3862 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3862 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3863 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3863 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3960;
  if (v4036) {
    int * v3868 = v3855->cache_age;
    int v4038 = ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3863 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3863 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3869 = v3868[v4038];
    int v3870 = v3868[v4031];
    int v4039 = v3870 + ((int)((unsigned int)(v3870 - v3869) >> 31));
    v3868[v4031] = v4039;
    int * v3872 = v3855->cache_age;
    int v3873 = v3872[v4032];
    int v4041 = v3873 + ((int)((unsigned int)(v3873 - v3869) >> 31));
    v3872[v4032] = v4041;
    int * v3875 = v3855->cache_age;
    v3875[v4038] = 0;
    v3960 = v4038;
  } else {
    int * v3878 = v3855->cache_age;
    int v4045 = (((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3879 = v3878[v4045];
    int * v3880 = v3855->cache_tags;
    int v3881 = v3880[v4045];
    int v3882 = v3878[v4032];
    int v3883 = v3880[v4032];
    bool v4047 = !(((~(((v3864 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3864 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3937;
    if (v4047) {
      int * v3884 = v3855->cache_age;
      int v4049 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3885 = v3884[v4049];
      int v3886 = v3884[v4033];
      int v4050 = v3886 + ((int)((unsigned int)(v3886 - v3885) >> 31));
      v3884[v4033] = v4050;
      int * v3888 = v3855->cache_age;
      int v3889 = v3888[v4034];
      int v4052 = v3889 + ((int)((unsigned int)(v3889 - v3885) >> 31));
      v3888[v4034] = v4052;
      int * v3891 = v3855->cache_age;
      v3891[v4049] = 0;
      v3937 = v4049;
    } else {
      int * v3894 = v3855->cache_age;
      int v4056 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3895 = v3894[v4056];
      int * v3896 = v3855->cache_tags;
      int v3897 = v3896[v4056];
      int v3898 = v3894[v4034];
      int v3899 = v3896[v4034];
      int * v3900 = v3855->cache_dirty;
      int v4059 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3901 = v3900[v4059];
      bool v4060 = !(v3901 == 0);
      if (v4060) {
        int * v3902 = v3855->cache_tags;
        int v3903 = v3902[v4059];
        int * v3904 = v3855->cache_vals;
        int v4063 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3905 = v3904[v4063];
        int v4064 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3906 = v3904[v4064];
        int * v3907 = v3855->mem;
        int v4066 = v3903 * 2;
        v3907[v4066] = v3905;
        int * v3909 = v3855->mem;
        int v4069 = (v3903 * 2) + 1;
        v3909[v4069] = v3906;
        ;
      } else {
        ;
      }
      int * v3914 = v3855->mem;
      int v4074 = ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) * 2;
      int v3915 = v3914[v4074];
      int v4075 = (((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3916 = v3914[v4075];
      int * v3917 = v3855->cache_vals;
      int v4077 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3917[v4077] = v3915;
      int * v3919 = v3855->cache_vals;
      int v4080 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3919[v4080] = v3916;
      int * v3921 = v3855->cache_tags;
      int v4083 = (int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1);
      v3921[v4059] = v4083;
      int * v3923 = v3855->cache_dirty;
      v3923[v4059] = 0;
      int * v3925 = v3855->cache_age;
      v3925[v4059] = 1;
      int * v3927 = v3855->cache_age;
      int v3928 = v3927[v4059];
      int v3929 = v3927[v4033];
      int v4089 = v3929 + ((int)((unsigned int)(v3929 - v3928) >> 31));
      v3927[v4033] = v4089;
      int * v3931 = v3855->cache_age;
      int v3932 = v3931[v4034];
      int v4091 = v3932 + ((int)((unsigned int)(v3932 - v3928) >> 31));
      v3931[v4034] = v4091;
      int * v3934 = v3855->cache_age;
      v3934[v4059] = 0;
      v3937 = v4059;
    }
    int * v3938 = v3855->cache_vals;
    int v4094 = v3937 * 2;
    int v3939 = v3938[v4094];
    int v4095 = (v3937 * 2) + 1;
    int v3940 = v3938[v4095];
    int v4096 = (((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3879 + ((~(((v3881 ^ -1) | (-(v3881 ^ -1))) >> 31)) & 2)) - (v3882 + ((~(((v3883 ^ -1) | (-(v3883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3938[v4096] = v3939;
    int * v3942 = v3855->cache_vals;
    int v4099 = ((((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3879 + ((~(((v3881 ^ -1) | (-(v3881 ^ -1))) >> 31)) & 2)) - (v3882 + ((~(((v3883 ^ -1) | (-(v3883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3942[v4099] = v3940;
    int * v3944 = v3855->cache_tags;
    int v4102 = ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3879 + ((~(((v3881 ^ -1) | (-(v3881 ^ -1))) >> 31)) & 2)) - (v3882 + ((~(((v3883 ^ -1) | (-(v3883 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4103 = (int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1);
    v3944[v4102] = v4103;
    int * v3946 = v3855->cache_dirty;
    v3946[v4102] = 0;
    int * v3948 = v3855->cache_age;
    v3948[v4102] = 1;
    int * v3950 = v3855->cache_age;
    int v3951 = v3950[v4102];
    int v3952 = v3950[v4031];
    int v4109 = v3952 + ((int)((unsigned int)(v3952 - v3951) >> 31));
    v3950[v4031] = v4109;
    int * v3954 = v3855->cache_age;
    int v3955 = v3954[v4032];
    int v4111 = v3955 + ((int)((unsigned int)(v3955 - v3951) >> 31));
    v3954[v4032] = v4111;
    int * v3957 = v3855->cache_age;
    v3957[v4102] = 0;
    v3960 = v4102;
  }
  int * v3961 = v3855->cache_vals;
  int v4114 = (v3960 * 2) + (((int)((unsigned int)(v3859 + 8) >> 2)) & 1);
  v3961[v4114] = v3860;
  int * v3963 = v3855->cache_tags;
  int v3964 = v3963[v4033];
  int v3965 = v3963[v4034];
  bool v4117 = !(((~(((v3964 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3964 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3965 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3965 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4019;
  if (v4117) {
    int * v3966 = v3855->cache_age;
    int v4119 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3965 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))) | (-(v3965 ^ ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3967 = v3966[v4119];
    int v3968 = v3966[v4033];
    int v4120 = v3968 + ((int)((unsigned int)(v3968 - v3967) >> 31));
    v3966[v4033] = v4120;
    int * v3970 = v3855->cache_age;
    int v3971 = v3970[v4034];
    int v4122 = v3971 + ((int)((unsigned int)(v3971 - v3967) >> 31));
    v3970[v4034] = v4122;
    int * v3973 = v3855->cache_age;
    v3973[v4119] = 0;
    v4019 = v4119;
  } else {
    int * v3976 = v3855->cache_age;
    int v4126 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2);
    int v3977 = v3976[v4126];
    int * v3978 = v3855->cache_tags;
    int v3979 = v3978[v4126];
    int v3980 = v3976[v4034];
    int v3981 = v3978[v4034];
    int * v3982 = v3855->cache_dirty;
    int v4129 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3977 + ((~(((v3979 ^ -1) | (-(v3979 ^ -1))) >> 31)) & 2)) - (v3980 + ((~(((v3981 ^ -1) | (-(v3981 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3983 = v3982[v4129];
    bool v4130 = !(v3983 == 0);
    if (v4130) {
      int * v3984 = v3855->cache_tags;
      int v3985 = v3984[v4129];
      int * v3986 = v3855->cache_vals;
      int v4133 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3977 + ((~(((v3979 ^ -1) | (-(v3979 ^ -1))) >> 31)) & 2)) - (v3980 + ((~(((v3981 ^ -1) | (-(v3981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3987 = v3986[v4133];
      int v4134 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3977 + ((~(((v3979 ^ -1) | (-(v3979 ^ -1))) >> 31)) & 2)) - (v3980 + ((~(((v3981 ^ -1) | (-(v3981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3988 = v3986[v4134];
      int * v3989 = v3855->mem;
      int v4136 = v3985 * 2;
      v3989[v4136] = v3987;
      int * v3991 = v3855->mem;
      int v4139 = (v3985 * 2) + 1;
      v3991[v4139] = v3988;
      ;
    } else {
      ;
    }
    int * v3996 = v3855->mem;
    int v4144 = ((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) * 2;
    int v3997 = v3996[v4144];
    int v4145 = (((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) * 2) + 1;
    int v3998 = v3996[v4145];
    int * v3999 = v3855->cache_vals;
    int v4147 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3977 + ((~(((v3979 ^ -1) | (-(v3979 ^ -1))) >> 31)) & 2)) - (v3980 + ((~(((v3981 ^ -1) | (-(v3981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3999[v4147] = v3997;
    int * v4001 = v3855->cache_vals;
    int v4150 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3977 + ((~(((v3979 ^ -1) | (-(v3979 ^ -1))) >> 31)) & 2)) - (v3980 + ((~(((v3981 ^ -1) | (-(v3981 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4001[v4150] = v3998;
    int * v4003 = v3855->cache_tags;
    int v4153 = (int)((unsigned int)((int)((unsigned int)(v3859 + 8) >> 2)) >> 1);
    v4003[v4129] = v4153;
    int * v4005 = v3855->cache_dirty;
    v4005[v4129] = 0;
    int * v4007 = v3855->cache_age;
    v4007[v4129] = 1;
    int * v4009 = v3855->cache_age;
    int v4010 = v4009[v4129];
    int v4011 = v4009[v4033];
    int v4159 = v4011 + ((int)((unsigned int)(v4011 - v4010) >> 31));
    v4009[v4033] = v4159;
    int * v4013 = v3855->cache_age;
    int v4014 = v4013[v4034];
    int v4161 = v4014 + ((int)((unsigned int)(v4014 - v4010) >> 31));
    v4013[v4034] = v4161;
    int * v4016 = v3855->cache_age;
    v4016[v4129] = 0;
    v4019 = v4129;
  }
  int * v4020 = v3855->cache_vals;
  int v4164 = (v4019 * 2) + (((int)((unsigned int)(v3859 + 8) >> 2)) & 1);
  v4020[v4164] = v3860;
  int * v4022 = v3855->cache_dirty;
  v4022[v4019] = 1;
  struct StateT * v4024 = slot_74(v3855);
  return v4024;
}

struct StateT * slot_119(struct StateT * v6011) {
  int v6012 = v6011->timer;
  int v6182 = v6012 + 1;
  v6011->timer = v6182;
  int * v6014 = v6011->regs;
  int v6015 = v6014[10];
  int v6016 = v6014[29];
  int * v6017 = v6011->cache_tags;
  int v6187 = (((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2;
  int v6018 = v6017[v6187];
  int v6188 = ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6019 = v6017[v6188];
  int v6189 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2);
  int v6020 = v6017[v6189];
  int v6190 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6021 = v6017[v6190];
  int v6022 = v6011->timer;
  int v6191 = v6022 + ((100 ^ (((~(((v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6018 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6018 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6011->timer = v6191;
  bool v6192 = !(((~(((v6018 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6018 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v6116;
  if (v6192) {
    int * v6024 = v6011->cache_age;
    int v6194 = ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6019 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v6025 = v6024[v6194];
    int v6026 = v6024[v6187];
    int v6195 = v6026 + ((int)((unsigned int)(v6026 - v6025) >> 31));
    v6024[v6187] = v6195;
    int * v6028 = v6011->cache_age;
    int v6029 = v6028[v6188];
    int v6197 = v6029 + ((int)((unsigned int)(v6029 - v6025) >> 31));
    v6028[v6188] = v6197;
    int * v6031 = v6011->cache_age;
    v6031[v6194] = 0;
    v6116 = v6194;
  } else {
    int * v6034 = v6011->cache_age;
    int v6201 = (((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2;
    int v6035 = v6034[v6201];
    int * v6036 = v6011->cache_tags;
    int v6037 = v6036[v6201];
    int v6038 = v6034[v6188];
    int v6039 = v6036[v6188];
    bool v6203 = !(((~(((v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6020 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v6093;
    if (v6203) {
      int * v6040 = v6011->cache_age;
      int v6205 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6021 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v6041 = v6040[v6205];
      int v6042 = v6040[v6189];
      int v6206 = v6042 + ((int)((unsigned int)(v6042 - v6041) >> 31));
      v6040[v6189] = v6206;
      int * v6044 = v6011->cache_age;
      int v6045 = v6044[v6190];
      int v6208 = v6045 + ((int)((unsigned int)(v6045 - v6041) >> 31));
      v6044[v6190] = v6208;
      int * v6047 = v6011->cache_age;
      v6047[v6205] = 0;
      v6093 = v6205;
    } else {
      int * v6050 = v6011->cache_age;
      int v6212 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2);
      int v6051 = v6050[v6212];
      int * v6052 = v6011->cache_tags;
      int v6053 = v6052[v6212];
      int v6054 = v6050[v6190];
      int v6055 = v6052[v6190];
      int * v6056 = v6011->cache_dirty;
      int v6215 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6051 + ((~(((v6053 ^ -1) | (-(v6053 ^ -1))) >> 31)) & 2)) - (v6054 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6057 = v6056[v6215];
      bool v6216 = !(v6057 == 0);
      if (v6216) {
        int * v6058 = v6011->cache_tags;
        int v6059 = v6058[v6215];
        int * v6060 = v6011->cache_vals;
        int v6219 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6051 + ((~(((v6053 ^ -1) | (-(v6053 ^ -1))) >> 31)) & 2)) - (v6054 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6061 = v6060[v6219];
        int v6220 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6051 + ((~(((v6053 ^ -1) | (-(v6053 ^ -1))) >> 31)) & 2)) - (v6054 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6062 = v6060[v6220];
        int * v6063 = v6011->mem;
        int v6222 = v6059 * 2;
        v6063[v6222] = v6061;
        int * v6065 = v6011->mem;
        int v6225 = (v6059 * 2) + 1;
        v6065[v6225] = v6062;
        ;
      } else {
        ;
      }
      int * v6070 = v6011->mem;
      int v6230 = ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) * 2;
      int v6071 = v6070[v6230];
      int v6231 = (((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) * 2) + 1;
      int v6072 = v6070[v6231];
      int * v6073 = v6011->cache_vals;
      int v6233 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6051 + ((~(((v6053 ^ -1) | (-(v6053 ^ -1))) >> 31)) & 2)) - (v6054 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6073[v6233] = v6071;
      int * v6075 = v6011->cache_vals;
      int v6236 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6051 + ((~(((v6053 ^ -1) | (-(v6053 ^ -1))) >> 31)) & 2)) - (v6054 + ((~(((v6055 ^ -1) | (-(v6055 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6075[v6236] = v6072;
      int * v6077 = v6011->cache_tags;
      int v6239 = (int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1);
      v6077[v6215] = v6239;
      int * v6079 = v6011->cache_dirty;
      v6079[v6215] = 0;
      int * v6081 = v6011->cache_age;
      v6081[v6215] = 1;
      int * v6083 = v6011->cache_age;
      int v6084 = v6083[v6215];
      int v6085 = v6083[v6189];
      int v6245 = v6085 + ((int)((unsigned int)(v6085 - v6084) >> 31));
      v6083[v6189] = v6245;
      int * v6087 = v6011->cache_age;
      int v6088 = v6087[v6190];
      int v6247 = v6088 + ((int)((unsigned int)(v6088 - v6084) >> 31));
      v6087[v6190] = v6247;
      int * v6090 = v6011->cache_age;
      v6090[v6215] = 0;
      v6093 = v6215;
    }
    int * v6094 = v6011->cache_vals;
    int v6250 = v6093 * 2;
    int v6095 = v6094[v6250];
    int v6251 = (v6093 * 2) + 1;
    int v6096 = v6094[v6251];
    int v6252 = (((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v6035 + ((~(((v6037 ^ -1) | (-(v6037 ^ -1))) >> 31)) & 2)) - (v6038 + ((~(((v6039 ^ -1) | (-(v6039 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6094[v6252] = v6095;
    int * v6098 = v6011->cache_vals;
    int v6255 = ((((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v6035 + ((~(((v6037 ^ -1) | (-(v6037 ^ -1))) >> 31)) & 2)) - (v6038 + ((~(((v6039 ^ -1) | (-(v6039 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6098[v6255] = v6096;
    int * v6100 = v6011->cache_tags;
    int v6258 = ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v6035 + ((~(((v6037 ^ -1) | (-(v6037 ^ -1))) >> 31)) & 2)) - (v6038 + ((~(((v6039 ^ -1) | (-(v6039 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6259 = (int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1);
    v6100[v6258] = v6259;
    int * v6102 = v6011->cache_dirty;
    v6102[v6258] = 0;
    int * v6104 = v6011->cache_age;
    v6104[v6258] = 1;
    int * v6106 = v6011->cache_age;
    int v6107 = v6106[v6258];
    int v6108 = v6106[v6187];
    int v6265 = v6108 + ((int)((unsigned int)(v6108 - v6107) >> 31));
    v6106[v6187] = v6265;
    int * v6110 = v6011->cache_age;
    int v6111 = v6110[v6188];
    int v6267 = v6111 + ((int)((unsigned int)(v6111 - v6107) >> 31));
    v6110[v6188] = v6267;
    int * v6113 = v6011->cache_age;
    v6113[v6258] = 0;
    v6116 = v6258;
  }
  int * v6117 = v6011->cache_vals;
  int v6270 = (v6116 * 2) + (((int)((unsigned int)(v6015 + 20) >> 2)) & 1);
  v6117[v6270] = v6016;
  int * v6119 = v6011->cache_tags;
  int v6120 = v6119[v6189];
  int v6121 = v6119[v6190];
  bool v6273 = !(((~(((v6120 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6120 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6121 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6121 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v6175;
  if (v6273) {
    int * v6122 = v6011->cache_age;
    int v6275 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6121 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))) | (-(v6121 ^ ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v6123 = v6122[v6275];
    int v6124 = v6122[v6189];
    int v6276 = v6124 + ((int)((unsigned int)(v6124 - v6123) >> 31));
    v6122[v6189] = v6276;
    int * v6126 = v6011->cache_age;
    int v6127 = v6126[v6190];
    int v6278 = v6127 + ((int)((unsigned int)(v6127 - v6123) >> 31));
    v6126[v6190] = v6278;
    int * v6129 = v6011->cache_age;
    v6129[v6275] = 0;
    v6175 = v6275;
  } else {
    int * v6132 = v6011->cache_age;
    int v6282 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2);
    int v6133 = v6132[v6282];
    int * v6134 = v6011->cache_tags;
    int v6135 = v6134[v6282];
    int v6136 = v6132[v6190];
    int v6137 = v6134[v6190];
    int * v6138 = v6011->cache_dirty;
    int v6285 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6133 + ((~(((v6135 ^ -1) | (-(v6135 ^ -1))) >> 31)) & 2)) - (v6136 + ((~(((v6137 ^ -1) | (-(v6137 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6139 = v6138[v6285];
    bool v6286 = !(v6139 == 0);
    if (v6286) {
      int * v6140 = v6011->cache_tags;
      int v6141 = v6140[v6285];
      int * v6142 = v6011->cache_vals;
      int v6289 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6133 + ((~(((v6135 ^ -1) | (-(v6135 ^ -1))) >> 31)) & 2)) - (v6136 + ((~(((v6137 ^ -1) | (-(v6137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6143 = v6142[v6289];
      int v6290 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6133 + ((~(((v6135 ^ -1) | (-(v6135 ^ -1))) >> 31)) & 2)) - (v6136 + ((~(((v6137 ^ -1) | (-(v6137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6144 = v6142[v6290];
      int * v6145 = v6011->mem;
      int v6292 = v6141 * 2;
      v6145[v6292] = v6143;
      int * v6147 = v6011->mem;
      int v6295 = (v6141 * 2) + 1;
      v6147[v6295] = v6144;
      ;
    } else {
      ;
    }
    int * v6152 = v6011->mem;
    int v6300 = ((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) * 2;
    int v6153 = v6152[v6300];
    int v6301 = (((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) * 2) + 1;
    int v6154 = v6152[v6301];
    int * v6155 = v6011->cache_vals;
    int v6303 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6133 + ((~(((v6135 ^ -1) | (-(v6135 ^ -1))) >> 31)) & 2)) - (v6136 + ((~(((v6137 ^ -1) | (-(v6137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6155[v6303] = v6153;
    int * v6157 = v6011->cache_vals;
    int v6306 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6133 + ((~(((v6135 ^ -1) | (-(v6135 ^ -1))) >> 31)) & 2)) - (v6136 + ((~(((v6137 ^ -1) | (-(v6137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6157[v6306] = v6154;
    int * v6159 = v6011->cache_tags;
    int v6309 = (int)((unsigned int)((int)((unsigned int)(v6015 + 20) >> 2)) >> 1);
    v6159[v6285] = v6309;
    int * v6161 = v6011->cache_dirty;
    v6161[v6285] = 0;
    int * v6163 = v6011->cache_age;
    v6163[v6285] = 1;
    int * v6165 = v6011->cache_age;
    int v6166 = v6165[v6285];
    int v6167 = v6165[v6189];
    int v6315 = v6167 + ((int)((unsigned int)(v6167 - v6166) >> 31));
    v6165[v6189] = v6315;
    int * v6169 = v6011->cache_age;
    int v6170 = v6169[v6190];
    int v6317 = v6170 + ((int)((unsigned int)(v6170 - v6166) >> 31));
    v6169[v6190] = v6317;
    int * v6172 = v6011->cache_age;
    v6172[v6285] = 0;
    v6175 = v6285;
  }
  int * v6176 = v6011->cache_vals;
  int v6320 = (v6175 * 2) + (((int)((unsigned int)(v6015 + 20) >> 2)) & 1);
  v6176[v6320] = v6016;
  int * v6178 = v6011->cache_dirty;
  v6178[v6175] = 1;
  struct StateT * v6180 = slot_121(v6011);
  return v6180;
}

struct StateT * slot_71(struct StateT * v3839) {
  int v3840 = v3839->timer;
  int v3848 = v3840 + 1;
  v3839->timer = v3848;
  int * v3842 = v3839->regs;
  int v3843 = v3842[5];
  int v3844 = v3842[28];
  int v3852 = v3843 + v3844;
  v3842[28] = v3852;
  struct StateT * v3846 = slot_73(v3839);
  return v3846;
}

struct StateT * slot_101(struct StateT * v5332) {
  int v5333 = v5332->timer;
  int v5341 = v5333 + 1;
  v5332->timer = v5341;
  int * v5335 = v5332->regs;
  int v5336 = v5335[8];
  int v5337 = v5335[6];
  int v5345 = v5336 + v5337;
  v5335[6] = v5345;
  struct StateT * v5339 = slot_102(v5332);
  return v5339;
}

struct StateT * slot_108(struct StateT * v5463) {
  int v5464 = v5463->timer;
  int v5472 = v5464 + 1;
  v5463->timer = v5472;
  int * v5466 = v5463->regs;
  int v5467 = v5466[6];
  int v5468 = v5466[31];
  int v5476 = v5467 + v5468;
  v5466[6] = v5476;
  struct StateT * v5470 = slot_109(v5463);
  return v5470;
}

struct StateT * slot_116(struct StateT * v5663) {
  int v5664 = v5663->timer;
  int v5672 = v5664 + 1;
  v5663->timer = v5672;
  int * v5666 = v5663->regs;
  int v5667 = v5666[5];
  int v5668 = v5666[28];
  int v5676 = v5667 + v5668;
  v5666[28] = v5676;
  struct StateT * v5670 = slot_118(v5663);
  return v5670;
}

struct StateT * slot_93(struct StateT * v5174) {
  int v5175 = v5174->timer;
  int v5183 = v5175 + 1;
  v5174->timer = v5183;
  int * v5177 = v5174->regs;
  int v5178 = v5177[28];
  int v5179 = v5177[17];
  int v5188 = v5178 + v5179;
  v5177[29] = v5188;
  struct StateT * v5181 = slot_94(v5174);
  return v5181;
}

struct StateT * slot_88(struct StateT * v5090) {
  int v5091 = v5090->timer;
  int v5099 = v5091 + 1;
  v5090->timer = v5099;
  int * v5093 = v5090->regs;
  int v5094 = v5093[6];
  int v5095 = v5093[13];
  int v5104 = v5094 * v5095;
  v5093[31] = v5104;
  struct StateT * v5097 = slot_89(v5090);
  return v5097;
}

struct StateT * slot_96(struct StateT * v5233) {
  int v5234 = v5233->timer;
  int v5242 = v5234 + 1;
  v5233->timer = v5242;
  int * v5236 = v5233->regs;
  int v5237 = v5236[31];
  int v5238 = v5236[29];
  int v5246 = v5237 + v5238;
  v5236[29] = v5246;
  struct StateT * v5240 = slot_97(v5233);
  return v5240;
}

struct StateT * slot_215(struct StateT * v9422) {
  int v9423 = v9422->timer;
  int v9431 = v9423 + 1;
  v9422->timer = v9431;
  int * v9425 = v9422->regs;
  int v9426 = v9425[14];
  int v9427 = v9425[13];
  int v9435 = v9426 + v9427;
  v9425[13] = v9435;
  struct StateT * v9429 = slot_216(v9422);
  return v9429;
}

struct StateT * slot_234(struct StateT * v11381) {
  int v11382 = v11381->timer;
  int v11492 = v11382 + 1;
  v11381->timer = v11492;
  int * v11384 = v11381->regs;
  int v11385 = v11384[2];
  int * v11386 = v11381->cache_tags;
  int v11496 = (((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2;
  int v11387 = v11386[v11496];
  int v11497 = ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11388 = v11386[v11497];
  int v11498 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2);
  int v11389 = v11386[v11498];
  int v11499 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11390 = v11386[v11499];
  int v11391 = v11381->timer;
  int v11500 = v11391 + ((100 ^ (((~(((v11389 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11389 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11387 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11387 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11388 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11388 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11389 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11389 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11381->timer = v11500;
  int * v11393 = v11381->cache_vals;
  bool v11501 = !(((~(((v11387 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11387 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11388 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11388 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v11486;
  if (v11501) {
    int * v11394 = v11381->cache_age;
    int v11503 = ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v11388 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11388 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v11395 = v11394[v11503];
    int v11396 = v11394[v11496];
    int v11504 = v11396 + ((int)((unsigned int)(v11396 - v11395) >> 31));
    v11394[v11496] = v11504;
    int * v11398 = v11381->cache_age;
    int v11399 = v11398[v11497];
    int v11506 = v11399 + ((int)((unsigned int)(v11399 - v11395) >> 31));
    v11398[v11497] = v11506;
    int * v11401 = v11381->cache_age;
    v11401[v11503] = 0;
    v11486 = v11503;
  } else {
    int * v11404 = v11381->cache_age;
    int v11510 = (((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2;
    int v11405 = v11404[v11510];
    int * v11406 = v11381->cache_tags;
    int v11407 = v11406[v11510];
    int v11408 = v11404[v11497];
    int v11409 = v11406[v11497];
    bool v11512 = !(((~(((v11389 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11389 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v11463;
    if (v11512) {
      int * v11410 = v11381->cache_age;
      int v11514 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))) | (-(v11390 ^ ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v11411 = v11410[v11514];
      int v11412 = v11410[v11498];
      int v11515 = v11412 + ((int)((unsigned int)(v11412 - v11411) >> 31));
      v11410[v11498] = v11515;
      int * v11414 = v11381->cache_age;
      int v11415 = v11414[v11499];
      int v11517 = v11415 + ((int)((unsigned int)(v11415 - v11411) >> 31));
      v11414[v11499] = v11517;
      int * v11417 = v11381->cache_age;
      v11417[v11514] = 0;
      v11463 = v11514;
    } else {
      int * v11420 = v11381->cache_age;
      int v11521 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2);
      int v11421 = v11420[v11521];
      int * v11422 = v11381->cache_tags;
      int v11423 = v11422[v11521];
      int v11424 = v11420[v11499];
      int v11425 = v11422[v11499];
      int * v11426 = v11381->cache_dirty;
      int v11524 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11421 + ((~(((v11423 ^ -1) | (-(v11423 ^ -1))) >> 31)) & 2)) - (v11424 + ((~(((v11425 ^ -1) | (-(v11425 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11427 = v11426[v11524];
      bool v11525 = !(v11427 == 0);
      if (v11525) {
        int * v11428 = v11381->cache_tags;
        int v11429 = v11428[v11524];
        int * v11430 = v11381->cache_vals;
        int v11528 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11421 + ((~(((v11423 ^ -1) | (-(v11423 ^ -1))) >> 31)) & 2)) - (v11424 + ((~(((v11425 ^ -1) | (-(v11425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11431 = v11430[v11528];
        int v11529 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11421 + ((~(((v11423 ^ -1) | (-(v11423 ^ -1))) >> 31)) & 2)) - (v11424 + ((~(((v11425 ^ -1) | (-(v11425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11432 = v11430[v11529];
        int * v11433 = v11381->mem;
        int v11531 = v11429 * 2;
        v11433[v11531] = v11431;
        int * v11435 = v11381->mem;
        int v11534 = (v11429 * 2) + 1;
        v11435[v11534] = v11432;
        ;
      } else {
        ;
      }
      int * v11440 = v11381->mem;
      int v11539 = ((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) * 2;
      int v11441 = v11440[v11539];
      int v11540 = (((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) * 2) + 1;
      int v11442 = v11440[v11540];
      int * v11443 = v11381->cache_vals;
      int v11542 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11421 + ((~(((v11423 ^ -1) | (-(v11423 ^ -1))) >> 31)) & 2)) - (v11424 + ((~(((v11425 ^ -1) | (-(v11425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11443[v11542] = v11441;
      int * v11445 = v11381->cache_vals;
      int v11545 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v11421 + ((~(((v11423 ^ -1) | (-(v11423 ^ -1))) >> 31)) & 2)) - (v11424 + ((~(((v11425 ^ -1) | (-(v11425 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11445[v11545] = v11442;
      int * v11447 = v11381->cache_tags;
      int v11548 = (int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1);
      v11447[v11524] = v11548;
      int * v11449 = v11381->cache_dirty;
      v11449[v11524] = 0;
      int * v11451 = v11381->cache_age;
      v11451[v11524] = 1;
      int * v11453 = v11381->cache_age;
      int v11454 = v11453[v11524];
      int v11455 = v11453[v11498];
      int v11554 = v11455 + ((int)((unsigned int)(v11455 - v11454) >> 31));
      v11453[v11498] = v11554;
      int * v11457 = v11381->cache_age;
      int v11458 = v11457[v11499];
      int v11556 = v11458 + ((int)((unsigned int)(v11458 - v11454) >> 31));
      v11457[v11499] = v11556;
      int * v11460 = v11381->cache_age;
      v11460[v11524] = 0;
      v11463 = v11524;
    }
    int * v11464 = v11381->cache_vals;
    int v11559 = v11463 * 2;
    int v11465 = v11464[v11559];
    int v11560 = (v11463 * 2) + 1;
    int v11466 = v11464[v11560];
    int v11561 = (((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v11405 + ((~(((v11407 ^ -1) | (-(v11407 ^ -1))) >> 31)) & 2)) - (v11408 + ((~(((v11409 ^ -1) | (-(v11409 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11464[v11561] = v11465;
    int * v11468 = v11381->cache_vals;
    int v11564 = ((((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v11405 + ((~(((v11407 ^ -1) | (-(v11407 ^ -1))) >> 31)) & 2)) - (v11408 + ((~(((v11409 ^ -1) | (-(v11409 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11468[v11564] = v11466;
    int * v11470 = v11381->cache_tags;
    int v11567 = ((((int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v11405 + ((~(((v11407 ^ -1) | (-(v11407 ^ -1))) >> 31)) & 2)) - (v11408 + ((~(((v11409 ^ -1) | (-(v11409 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11568 = (int)((unsigned int)((int)((unsigned int)(v11385 + 4) >> 2)) >> 1);
    v11470[v11567] = v11568;
    int * v11472 = v11381->cache_dirty;
    v11472[v11567] = 0;
    int * v11474 = v11381->cache_age;
    v11474[v11567] = 1;
    int * v11476 = v11381->cache_age;
    int v11477 = v11476[v11567];
    int v11478 = v11476[v11496];
    int v11574 = v11478 + ((int)((unsigned int)(v11478 - v11477) >> 31));
    v11476[v11496] = v11574;
    int * v11480 = v11381->cache_age;
    int v11481 = v11480[v11497];
    int v11576 = v11481 + ((int)((unsigned int)(v11481 - v11477) >> 31));
    v11480[v11497] = v11576;
    int * v11483 = v11381->cache_age;
    v11483[v11567] = 0;
    v11486 = v11567;
  }
  int v11579 = (v11486 * 2) + (((int)((unsigned int)(v11385 + 4) >> 2)) & 1);
  int v11487 = v11393[v11579];
  int * v11488 = v11381->regs;
  v11488[18] = v11487;
  struct StateT * v11490 = slot_236(v11381);
  return v11490;
}

struct StateT * slot_45(struct StateT * v3303) {
  int v3304 = v3303->timer;
  int v3312 = v3304 + 1;
  v3303->timer = v3312;
  int * v3306 = v3303->regs;
  int v3307 = v3306[28];
  int v3308 = v3306[13];
  int v3317 = v3307 * v3308;
  v3306[18] = v3317;
  struct StateT * v3310 = slot_46(v3303);
  return v3310;
}

struct StateT * slot_218(struct StateT * v9485) {
  int v9486 = v9485->timer;
  int v9494 = v9486 + 1;
  v9485->timer = v9494;
  int * v9488 = v9485->regs;
  int v9489 = v9488[15];
  int v9490 = v9488[12];
  int v9498 = v9489 + v9490;
  v9488[12] = v9498;
  struct StateT * v9492 = slot_219(v9485);
  return v9492;
}

struct StateT * slot_220(struct StateT * v9517) {
  int * v9518 = v9517->saved_regs;
  int v9519 = v9518[17];
  int * v9520 = v9517->regs;
  int v9521 = v9520[6];
  bool v9562 = v9519 == v9521;
  struct StateT * v9556;
  if (v9562) {
    int v9522 = v9517->timer;
    int v9563 = v9522 + 15;
    v9517->timer = v9563;
    int * v9524 = v9517->saved_regs;
    int v9525 = v9524[5];
    int * v9526 = v9517->regs;
    v9526[5] = v9525;
    int * v9528 = v9517->saved_regs;
    int v9529 = v9528[16];
    int * v9530 = v9517->regs;
    v9530[16] = v9529;
    int * v9532 = v9517->saved_regs;
    int v9533 = v9532[17];
    int * v9534 = v9517->regs;
    v9534[17] = v9533;
    int * v9536 = v9517->saved_regs;
    int v9537 = v9536[12];
    int * v9538 = v9517->regs;
    v9538[12] = v9537;
    int * v9540 = v9517->saved_regs;
    int v9541 = v9540[13];
    int * v9542 = v9517->regs;
    v9542[13] = v9541;
    int * v9544 = v9517->saved_regs;
    int v9545 = v9544[15];
    int * v9546 = v9517->regs;
    v9546[15] = v9545;
    int * v9548 = v9517->saved_regs;
    int v9549 = v9548[14];
    int * v9550 = v9517->regs;
    v9550[14] = v9549;
    struct StateT * v9552 = slot_221(v9517);
    v9556 = v9552;
  } else {
    struct StateT * v9554 = slot_222(v9517);
    v9556 = v9554;
  }
  return v9556;
}

struct StateT * slot_134(struct StateT * v6931) {
  int v6932 = v6931->timer;
  int v6940 = v6932 + 1;
  v6931->timer = v6940;
  int * v6934 = v6931->regs;
  int v6935 = v6934[6];
  int v6936 = v6934[13];
  int v6945 = (((((int)((unsigned int)v6935 >> 16)) * ((int)((unsigned int)v6936 >> 16))) + ((int)((unsigned int)((v6935 & 65535) * ((int)((unsigned int)v6936 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6935 >> 16)) * (v6936 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6935 & 65535) * (v6936 & 65535)) >> 16)) + (((v6935 & 65535) * ((int)((unsigned int)v6936 >> 16))) & 65535)) + ((((int)((unsigned int)v6935 >> 16)) * (v6936 & 65535)) & 65535)) >> 16));
  v6934[8] = v6945;
  struct StateT * v6938 = slot_135(v6931);
  return v6938;
}

struct StateT * slot_175(struct StateT * v8686) {
  int v8687 = v8686->timer;
  int v8695 = v8687 + 1;
  v8686->timer = v8695;
  int * v8689 = v8686->regs;
  int v8690 = v8689[6];
  int v8691 = v8689[12];
  int v8700 = (((((int)((unsigned int)v8690 >> 16)) * ((int)((unsigned int)v8691 >> 16))) + ((int)((unsigned int)((v8690 & 65535) * ((int)((unsigned int)v8691 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8690 >> 16)) * (v8691 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8690 & 65535) * (v8691 & 65535)) >> 16)) + (((v8690 & 65535) * ((int)((unsigned int)v8691 >> 16))) & 65535)) + ((((int)((unsigned int)v8690 >> 16)) * (v8691 & 65535)) & 65535)) >> 16));
  v8689[5] = v8700;
  struct StateT * v8693 = slot_176(v8686);
  return v8693;
}

struct StateT * slot_69(struct StateT * v3756) {
  int * v3757 = v3756->saved_regs;
  int * v3758 = v3756->regs;
  int v3759 = v3758[5];
  v3757[5] = v3759;
  int v3761 = v3756->timer;
  int v3777 = v3761 + 1;
  v3756->timer = v3777;
  int * v3763 = v3756->regs;
  int v3764 = v3763[28];
  int v3765 = v3763[5];
  bool v3780 = (v3764 ^ -2147483648) < (v3765 ^ -2147483648);
  int v3768;
  if (v3780) {
    v3768 = 1;
  } else {
    v3768 = 0;
  }
  int * v3769 = v3756->regs;
  v3769[5] = v3768;
  struct StateT * v3771 = slot_70(v3756);
  return v3771;
}

struct StateT * slot_202(struct StateT * v9180) {
  int * v9181 = v9180->saved_regs;
  int * v9182 = v9180->regs;
  int v9183 = v9182[16];
  v9181[16] = v9183;
  int v9185 = v9180->timer;
  int v9197 = v9185 + 1;
  v9180->timer = v9197;
  int * v9187 = v9180->regs;
  int v9188 = v9187[17];
  int v9189 = v9187[16];
  int v9200 = v9188 & v9189;
  v9187[16] = v9200;
  struct StateT * v9191 = slot_203(v9180);
  return v9191;
}

struct StateT * slot_230(struct StateT * v10942) {
  int v10943 = v10942->timer;
  int v11053 = v10943 + 1;
  v10942->timer = v11053;
  int * v10945 = v10942->regs;
  int v10946 = v10945[2];
  int * v10947 = v10942->cache_tags;
  int v11057 = (((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2;
  int v10948 = v10947[v11057];
  int v11058 = ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10949 = v10947[v11058];
  int v11059 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2);
  int v10950 = v10947[v11059];
  int v11060 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10951 = v10947[v11060];
  int v10952 = v10942->timer;
  int v11061 = v10952 + ((100 ^ (((~(((v10950 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10950 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10948 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10948 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10949 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10949 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10950 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10950 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10942->timer = v11061;
  int * v10954 = v10942->cache_vals;
  bool v11062 = !(((~(((v10948 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10948 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10949 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10949 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v11047;
  if (v11062) {
    int * v10955 = v10942->cache_age;
    int v11064 = ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v10949 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10949 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v10956 = v10955[v11064];
    int v10957 = v10955[v11057];
    int v11065 = v10957 + ((int)((unsigned int)(v10957 - v10956) >> 31));
    v10955[v11057] = v11065;
    int * v10959 = v10942->cache_age;
    int v10960 = v10959[v11058];
    int v11067 = v10960 + ((int)((unsigned int)(v10960 - v10956) >> 31));
    v10959[v11058] = v11067;
    int * v10962 = v10942->cache_age;
    v10962[v11064] = 0;
    v11047 = v11064;
  } else {
    int * v10965 = v10942->cache_age;
    int v11071 = (((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2;
    int v10966 = v10965[v11071];
    int * v10967 = v10942->cache_tags;
    int v10968 = v10967[v11071];
    int v10969 = v10965[v11058];
    int v10970 = v10967[v11058];
    bool v11073 = !(((~(((v10950 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10950 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v11024;
    if (v11073) {
      int * v10971 = v10942->cache_age;
      int v11075 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v10972 = v10971[v11075];
      int v10973 = v10971[v11059];
      int v11076 = v10973 + ((int)((unsigned int)(v10973 - v10972) >> 31));
      v10971[v11059] = v11076;
      int * v10975 = v10942->cache_age;
      int v10976 = v10975[v11060];
      int v11078 = v10976 + ((int)((unsigned int)(v10976 - v10972) >> 31));
      v10975[v11060] = v11078;
      int * v10978 = v10942->cache_age;
      v10978[v11075] = 0;
      v11024 = v11075;
    } else {
      int * v10981 = v10942->cache_age;
      int v11082 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2);
      int v10982 = v10981[v11082];
      int * v10983 = v10942->cache_tags;
      int v10984 = v10983[v11082];
      int v10985 = v10981[v11060];
      int v10986 = v10983[v11060];
      int * v10987 = v10942->cache_dirty;
      int v11085 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10982 + ((~(((v10984 ^ -1) | (-(v10984 ^ -1))) >> 31)) & 2)) - (v10985 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10988 = v10987[v11085];
      bool v11086 = !(v10988 == 0);
      if (v11086) {
        int * v10989 = v10942->cache_tags;
        int v10990 = v10989[v11085];
        int * v10991 = v10942->cache_vals;
        int v11089 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10982 + ((~(((v10984 ^ -1) | (-(v10984 ^ -1))) >> 31)) & 2)) - (v10985 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10992 = v10991[v11089];
        int v11090 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10982 + ((~(((v10984 ^ -1) | (-(v10984 ^ -1))) >> 31)) & 2)) - (v10985 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10993 = v10991[v11090];
        int * v10994 = v10942->mem;
        int v11092 = v10990 * 2;
        v10994[v11092] = v10992;
        int * v10996 = v10942->mem;
        int v11095 = (v10990 * 2) + 1;
        v10996[v11095] = v10993;
        ;
      } else {
        ;
      }
      int * v11001 = v10942->mem;
      int v11100 = ((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) * 2;
      int v11002 = v11001[v11100];
      int v11101 = (((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) * 2) + 1;
      int v11003 = v11001[v11101];
      int * v11004 = v10942->cache_vals;
      int v11103 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10982 + ((~(((v10984 ^ -1) | (-(v10984 ^ -1))) >> 31)) & 2)) - (v10985 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11004[v11103] = v11002;
      int * v11006 = v10942->cache_vals;
      int v11106 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10982 + ((~(((v10984 ^ -1) | (-(v10984 ^ -1))) >> 31)) & 2)) - (v10985 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11006[v11106] = v11003;
      int * v11008 = v10942->cache_tags;
      int v11109 = (int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1);
      v11008[v11085] = v11109;
      int * v11010 = v10942->cache_dirty;
      v11010[v11085] = 0;
      int * v11012 = v10942->cache_age;
      v11012[v11085] = 1;
      int * v11014 = v10942->cache_age;
      int v11015 = v11014[v11085];
      int v11016 = v11014[v11059];
      int v11115 = v11016 + ((int)((unsigned int)(v11016 - v11015) >> 31));
      v11014[v11059] = v11115;
      int * v11018 = v10942->cache_age;
      int v11019 = v11018[v11060];
      int v11117 = v11019 + ((int)((unsigned int)(v11019 - v11015) >> 31));
      v11018[v11060] = v11117;
      int * v11021 = v10942->cache_age;
      v11021[v11085] = 0;
      v11024 = v11085;
    }
    int * v11025 = v10942->cache_vals;
    int v11120 = v11024 * 2;
    int v11026 = v11025[v11120];
    int v11121 = (v11024 * 2) + 1;
    int v11027 = v11025[v11121];
    int v11122 = (((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10966 + ((~(((v10968 ^ -1) | (-(v10968 ^ -1))) >> 31)) & 2)) - (v10969 + ((~(((v10970 ^ -1) | (-(v10970 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11025[v11122] = v11026;
    int * v11029 = v10942->cache_vals;
    int v11125 = ((((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10966 + ((~(((v10968 ^ -1) | (-(v10968 ^ -1))) >> 31)) & 2)) - (v10969 + ((~(((v10970 ^ -1) | (-(v10970 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11029[v11125] = v11027;
    int * v11031 = v10942->cache_tags;
    int v11128 = ((((int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10966 + ((~(((v10968 ^ -1) | (-(v10968 ^ -1))) >> 31)) & 2)) - (v10969 + ((~(((v10970 ^ -1) | (-(v10970 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11129 = (int)((unsigned int)((int)((unsigned int)(v10946 + 12) >> 2)) >> 1);
    v11031[v11128] = v11129;
    int * v11033 = v10942->cache_dirty;
    v11033[v11128] = 0;
    int * v11035 = v10942->cache_age;
    v11035[v11128] = 1;
    int * v11037 = v10942->cache_age;
    int v11038 = v11037[v11128];
    int v11039 = v11037[v11057];
    int v11135 = v11039 + ((int)((unsigned int)(v11039 - v11038) >> 31));
    v11037[v11057] = v11135;
    int * v11041 = v10942->cache_age;
    int v11042 = v11041[v11058];
    int v11137 = v11042 + ((int)((unsigned int)(v11042 - v11038) >> 31));
    v11041[v11058] = v11137;
    int * v11044 = v10942->cache_age;
    v11044[v11128] = 0;
    v11047 = v11128;
  }
  int v11140 = (v11047 * 2) + (((int)((unsigned int)(v10946 + 12) >> 2)) & 1);
  int v11048 = v10954[v11140];
  int * v11049 = v10942->regs;
  v11049[8] = v11048;
  struct StateT * v11051 = slot_232(v10942);
  return v11051;
}

struct StateT * slot_188(struct StateT * v8920) {
  int v8921 = v8920->timer;
  int v8929 = v8921 + 1;
  v8920->timer = v8929;
  int * v8923 = v8920->regs;
  int v8924 = v8923[29];
  int v8925 = v8923[7];
  int v8933 = v8924 + v8925;
  v8923[7] = v8933;
  struct StateT * v8927 = slot_189(v8920);
  return v8927;
}

struct StateT * slot_138(struct StateT * v6998) {
  int v6999 = v6998->timer;
  int v7007 = v6999 + 1;
  v6998->timer = v7007;
  int * v7001 = v6998->regs;
  int v7002 = v7001[28];
  int v7003 = v7001[17];
  int v7012 = v7002 + v7003;
  v7001[29] = v7012;
  struct StateT * v7005 = slot_139(v6998);
  return v7005;
}

struct StateT * slot_186(struct StateT * v8878) {
  int v8879 = v8878->timer;
  int v8887 = v8879 + 1;
  v8878->timer = v8887;
  int * v8881 = v8878->regs;
  int v8882 = v8881[30];
  int v8883 = v8881[5];
  int v8892 = v8882 + v8883;
  v8881[6] = v8892;
  struct StateT * v8885 = slot_187(v8878);
  return v8885;
}

struct StateT * slot_102(struct StateT * v5348) {
  int v5349 = v5348->timer;
  int v5357 = v5349 + 1;
  v5348->timer = v5357;
  int * v5351 = v5348->regs;
  int v5352 = v5351[7];
  int v5353 = v5351[6];
  int v5361 = v5352 + v5353;
  v5351[6] = v5361;
  struct StateT * v5355 = slot_103(v5348);
  return v5355;
}

struct StateT * slot_145(struct StateT * v7139) {
  int v7140 = v7139->timer;
  int v7148 = v7140 + 1;
  v7139->timer = v7148;
  int * v7142 = v7139->regs;
  int v7143 = v7142[29];
  int v7144 = v7142[5];
  int v7153 = v7143 + v7144;
  v7142[30] = v7153;
  struct StateT * v7146 = slot_146(v7139);
  return v7146;
}

struct StateT * slot_110(struct StateT * v5487) {
  int * v5488 = v5487->saved_regs;
  int * v5489 = v5487->regs;
  int v5490 = v5489[28];
  v5488[28] = v5490;
  int v5492 = v5487->timer;
  int v5508 = v5492 + 1;
  v5487->timer = v5508;
  int * v5494 = v5487->regs;
  int v5495 = v5494[7];
  int v5496 = v5494[29];
  bool v5512 = (v5495 ^ -2147483648) < (v5496 ^ -2147483648);
  int v5499;
  if (v5512) {
    v5499 = 1;
  } else {
    v5499 = 0;
  }
  int * v5500 = v5487->regs;
  v5500[28] = v5499;
  struct StateT * v5502 = slot_111(v5487);
  return v5502;
}

struct StateT * slot_196(struct StateT * v9076) {
  int v9077 = v9076->timer;
  int v9085 = v9077 + 1;
  v9076->timer = v9085;
  int * v9079 = v9076->regs;
  int v9080 = v9079[13];
  int v9081 = v9079[7];
  int v9089 = v9080 + v9081;
  v9079[13] = v9089;
  struct StateT * v9083 = slot_197(v9076);
  return v9083;
}

struct StateT * slot_208(struct StateT * v9309) {
  int v9310 = v9309->timer;
  int v9316 = v9310 + 1;
  v9309->timer = v9316;
  int * v9312 = v9309->regs;
  v9312[17] = 19;
  struct StateT * v9314 = slot_209(v9309);
  return v9314;
}

struct StateT * slot_172(struct StateT * v8640) {
  int v8641 = v8640->timer;
  int v8649 = v8641 + 1;
  v8640->timer = v8649;
  int * v8643 = v8640->regs;
  int v8644 = v8643[7];
  int v8645 = v8643[28];
  int v8653 = v8644 | v8645;
  v8643[7] = v8653;
  struct StateT * v8647 = slot_173(v8640);
  return v8647;
}

struct StateT * slot_131(struct StateT * v6880) {
  int v6881 = v6880->timer;
  int v6889 = v6881 + 1;
  v6880->timer = v6889;
  int * v6883 = v6880->regs;
  int v6884 = v6883[29];
  int v6885 = v6883[12];
  int v6894 = v6884 * v6885;
  v6883[28] = v6894;
  struct StateT * v6887 = slot_132(v6880);
  return v6887;
}

struct StateT * slot_8(struct StateT * v1697) {
  int v1698 = v1697->timer;
  int v1705 = v1698 + 1;
  v1697->timer = v1705;
  int * v1700 = v1697->regs;
  int v1701 = v1700[16];
  int v1708 = v1701 + -1;
  v1700[16] = v1708;
  struct StateT * v1703 = slot_9(v1697);
  return v1703;
}

struct StateT * slot_180(struct StateT * v8771) {
  int v8772 = v8771->timer;
  int v8780 = v8772 + 1;
  v8771->timer = v8780;
  int * v8774 = v8771->regs;
  int v8775 = v8774[11];
  int v8776 = v8774[13];
  int v8785 = v8775 * v8776;
  v8774[8] = v8785;
  struct StateT * v8778 = slot_181(v8771);
  return v8778;
}

struct StateT * slot_203(struct StateT * v9203) {
  int * v9204 = v9203->saved_regs;
  int * v9205 = v9203->regs;
  int v9206 = v9205[17];
  v9204[17] = v9206;
  int v9208 = v9203->timer;
  int v9219 = v9208 + 1;
  v9203->timer = v9219;
  int * v9210 = v9203->regs;
  int v9211 = v9210[17];
  int v9221 = (int)((unsigned int)v9211 >> 19);
  v9210[17] = v9221;
  struct StateT * v9213 = slot_204(v9203);
  return v9213;
}

struct StateT * slot_190(struct StateT * v8961) {
  int v8962 = v8961->timer;
  int v8970 = v8962 + 1;
  v8961->timer = v8970;
  int * v8964 = v8961->regs;
  int v8965 = v8964[6];
  int v8966 = v8964[17];
  int v8974 = v8965 + v8966;
  v8964[17] = v8974;
  struct StateT * v8968 = slot_191(v8961);
  return v8968;
}

struct StateT * slot_157(struct StateT * v7359) {
  int * v7360 = v7359->saved_regs;
  int * v7361 = v7359->regs;
  int v7362 = v7361[29];
  v7360[29] = v7362;
  int v7364 = v7359->timer;
  int v7376 = v7364 + 1;
  v7359->timer = v7376;
  int * v7366 = v7359->regs;
  int v7367 = v7366[7];
  int v7368 = v7366[16];
  int v7380 = v7367 & v7368;
  v7366[29] = v7380;
  struct StateT * v7370 = slot_158(v7359);
  return v7370;
}

struct StateT * slot_200(struct StateT * v9132) {
  int * v9133 = v9132->saved_regs;
  int * v9134 = v9132->regs;
  int v9135 = v9134[5];
  v9133[5] = v9135;
  int v9137 = v9132->timer;
  int v9153 = v9137 + 1;
  v9132->timer = v9153;
  int * v9139 = v9132->regs;
  int v9140 = v9139[17];
  int v9141 = v9139[6];
  bool v9157 = (v9140 ^ -2147483648) < (v9141 ^ -2147483648);
  int v9144;
  if (v9157) {
    v9144 = 1;
  } else {
    v9144 = 0;
  }
  int * v9145 = v9132->regs;
  v9145[5] = v9144;
  struct StateT * v9147 = slot_201(v9132);
  return v9147;
}

struct StateT * slot_243(struct StateT * v11865) {
  int v11866 = v11865->timer;
  int v11874 = v11866 + 1;
  v11865->timer = v11874;
  int * v11868 = v11865->regs;
  int v11869 = v11868[13];
  int v11870 = v11868[17];
  int v11879 = (((((int)((unsigned int)v11869 >> 16)) * ((int)((unsigned int)v11870 >> 16))) + ((int)((unsigned int)((v11869 & 65535) * ((int)((unsigned int)v11870 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v11869 >> 16)) * (v11870 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v11869 & 65535) * (v11870 & 65535)) >> 16)) + (((v11869 & 65535) * ((int)((unsigned int)v11870 >> 16))) & 65535)) + ((((int)((unsigned int)v11869 >> 16)) * (v11870 & 65535)) & 65535)) >> 16));
  v11868[5] = v11879;
  struct StateT * v11872 = slot_244(v11865);
  return v11872;
}

struct StateT * slot_173(struct StateT * v8656) {
  int v8657 = v8656->timer;
  int v8664 = v8657 + 1;
  v8656->timer = v8664;
  int * v8659 = v8656->regs;
  int v8660 = v8659[5];
  int v8667 = v8660 << 13;
  v8659[5] = v8667;
  struct StateT * v8662 = slot_174(v8656);
  return v8662;
}

struct StateT * slot_149(struct StateT * v7205) {
  int v7206 = v7205->timer;
  int v7218 = v7206 + 1;
  v7205->timer = v7218;
  int * v7208 = v7205->regs;
  int v7209 = v7208[6];
  int v7210 = v7208[7];
  bool v7222 = (v7209 ^ -2147483648) < (v7210 ^ -2147483648);
  int v7213;
  if (v7222) {
    v7213 = 1;
  } else {
    v7213 = 0;
  }
  int * v7214 = v7205->regs;
  v7214[6] = v7213;
  struct StateT * v7216 = slot_150(v7205);
  return v7216;
}

struct StateT * slot_5(struct StateT * v1276) {
  int v1277 = v1276->timer;
  int v1387 = v1277 + 1;
  v1276->timer = v1387;
  int * v1279 = v1276->regs;
  int v1280 = v1279[11];
  int * v1281 = v1276->cache_tags;
  int v1391 = (((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2;
  int v1282 = v1281[v1391];
  int v1392 = ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1283 = v1281[v1392];
  int v1393 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2);
  int v1284 = v1281[v1393];
  int v1394 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1285 = v1281[v1394];
  int v1286 = v1276->timer;
  int v1395 = v1286 + ((100 ^ (((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1276->timer = v1395;
  int * v1288 = v1276->cache_vals;
  bool v1396 = !(((~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) == 0);
  int v1381;
  if (v1396) {
    int * v1289 = v1276->cache_age;
    int v1398 = ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) & 1);
    int v1290 = v1289[v1398];
    int v1291 = v1289[v1391];
    int v1399 = v1291 + ((int)((unsigned int)(v1291 - v1290) >> 31));
    v1289[v1391] = v1399;
    int * v1293 = v1276->cache_age;
    int v1294 = v1293[v1392];
    int v1401 = v1294 + ((int)((unsigned int)(v1294 - v1290) >> 31));
    v1293[v1392] = v1401;
    int * v1296 = v1276->cache_age;
    v1296[v1398] = 0;
    v1381 = v1398;
  } else {
    int * v1299 = v1276->cache_age;
    int v1405 = (((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2;
    int v1300 = v1299[v1405];
    int * v1301 = v1276->cache_tags;
    int v1302 = v1301[v1405];
    int v1303 = v1299[v1392];
    int v1304 = v1301[v1392];
    bool v1407 = !(((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) == 0);
    int v1358;
    if (v1407) {
      int * v1305 = v1276->cache_age;
      int v1409 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) & 1);
      int v1306 = v1305[v1409];
      int v1307 = v1305[v1393];
      int v1410 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
      v1305[v1393] = v1410;
      int * v1309 = v1276->cache_age;
      int v1310 = v1309[v1394];
      int v1412 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
      v1309[v1394] = v1412;
      int * v1312 = v1276->cache_age;
      v1312[v1409] = 0;
      v1358 = v1409;
    } else {
      int * v1315 = v1276->cache_age;
      int v1416 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2);
      int v1316 = v1315[v1416];
      int * v1317 = v1276->cache_tags;
      int v1318 = v1317[v1416];
      int v1319 = v1315[v1394];
      int v1320 = v1317[v1394];
      int * v1321 = v1276->cache_dirty;
      int v1419 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1322 = v1321[v1419];
      bool v1420 = !(v1322 == 0);
      if (v1420) {
        int * v1323 = v1276->cache_tags;
        int v1324 = v1323[v1419];
        int * v1325 = v1276->cache_vals;
        int v1423 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1326 = v1325[v1423];
        int v1424 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1327 = v1325[v1424];
        int * v1328 = v1276->mem;
        int v1426 = v1324 * 2;
        v1328[v1426] = v1326;
        int * v1330 = v1276->mem;
        int v1429 = (v1324 * 2) + 1;
        v1330[v1429] = v1327;
        ;
      } else {
        ;
      }
      int * v1335 = v1276->mem;
      int v1434 = ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) * 2;
      int v1336 = v1335[v1434];
      int v1435 = (((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) * 2) + 1;
      int v1337 = v1335[v1435];
      int * v1338 = v1276->cache_vals;
      int v1437 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1338[v1437] = v1336;
      int * v1340 = v1276->cache_vals;
      int v1440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1340[v1440] = v1337;
      int * v1342 = v1276->cache_tags;
      int v1443 = (int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1);
      v1342[v1419] = v1443;
      int * v1344 = v1276->cache_dirty;
      v1344[v1419] = 0;
      int * v1346 = v1276->cache_age;
      v1346[v1419] = 1;
      int * v1348 = v1276->cache_age;
      int v1349 = v1348[v1419];
      int v1350 = v1348[v1393];
      int v1449 = v1350 + ((int)((unsigned int)(v1350 - v1349) >> 31));
      v1348[v1393] = v1449;
      int * v1352 = v1276->cache_age;
      int v1353 = v1352[v1394];
      int v1451 = v1353 + ((int)((unsigned int)(v1353 - v1349) >> 31));
      v1352[v1394] = v1451;
      int * v1355 = v1276->cache_age;
      v1355[v1419] = 0;
      v1358 = v1419;
    }
    int * v1359 = v1276->cache_vals;
    int v1454 = v1358 * 2;
    int v1360 = v1359[v1454];
    int v1455 = (v1358 * 2) + 1;
    int v1361 = v1359[v1455];
    int v1456 = (((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1359[v1456] = v1360;
    int * v1363 = v1276->cache_vals;
    int v1459 = ((((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1363[v1459] = v1361;
    int * v1365 = v1276->cache_tags;
    int v1462 = ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1463 = (int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1);
    v1365[v1462] = v1463;
    int * v1367 = v1276->cache_dirty;
    v1367[v1462] = 0;
    int * v1369 = v1276->cache_age;
    v1369[v1462] = 1;
    int * v1371 = v1276->cache_age;
    int v1372 = v1371[v1462];
    int v1373 = v1371[v1391];
    int v1469 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
    v1371[v1391] = v1469;
    int * v1375 = v1276->cache_age;
    int v1376 = v1375[v1392];
    int v1471 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
    v1375[v1392] = v1471;
    int * v1378 = v1276->cache_age;
    v1378[v1462] = 0;
    v1381 = v1462;
  }
  int v1474 = (v1381 * 2) + (((int)((unsigned int)v1280 >> 2)) & 1);
  int v1382 = v1288[v1474];
  int * v1383 = v1276->regs;
  v1383[14] = v1382;
  struct StateT * v1385 = slot_6(v1276);
  return v1385;
}

struct StateT * slot_104(struct StateT * v5381) {
  int v5382 = v5381->timer;
  int v5394 = v5382 + 1;
  v5381->timer = v5394;
  int * v5384 = v5381->regs;
  int v5385 = v5384[6];
  int v5386 = v5384[7];
  bool v5398 = (v5385 ^ -2147483648) < (v5386 ^ -2147483648);
  int v5389;
  if (v5398) {
    v5389 = 1;
  } else {
    v5389 = 0;
  }
  int * v5390 = v5381->regs;
  v5390[6] = v5389;
  struct StateT * v5392 = slot_105(v5381);
  return v5392;
}

struct StateT * slot_235(struct StateT * v11585) {
  int v11586 = v11585->timer;
  int v11592 = v11586 + 1;
  v11585->timer = v11592;
  int * v11588 = v11585->regs;
  v11588[17] = 19;
  struct StateT * v11590 = slot_237(v11585);
  return v11590;
}

struct StateT * slot_54(struct StateT * v3467) {
  int v3468 = v3467->timer;
  int v3480 = v3468 + 1;
  v3467->timer = v3480;
  int * v3470 = v3467->regs;
  int v3471 = v3470[29];
  int v3472 = v3470[8];
  bool v3484 = (v3471 ^ -2147483648) < (v3472 ^ -2147483648);
  int v3475;
  if (v3484) {
    v3475 = 1;
  } else {
    v3475 = 0;
  }
  int * v3476 = v3467->regs;
  v3476[6] = v3475;
  struct StateT * v3478 = slot_55(v3467);
  return v3478;
}

struct StateT * slot_26(struct StateT * v2306) {
  int v2307 = v2306->timer;
  int v2477 = v2307 + 1;
  v2306->timer = v2477;
  int * v2309 = v2306->regs;
  int v2310 = v2309[10];
  int v2311 = v2309[15];
  int * v2312 = v2306->cache_tags;
  int v2482 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2313 = v2312[v2482];
  int v2483 = ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2314 = v2312[v2483];
  int v2484 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2315 = v2312[v2484];
  int v2485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2316 = v2312[v2485];
  int v2317 = v2306->timer;
  int v2486 = v2317 + ((100 ^ (((~(((v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2306->timer = v2486;
  bool v2487 = !(((~(((v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2411;
  if (v2487) {
    int * v2319 = v2306->cache_age;
    int v2489 = ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2320 = v2319[v2489];
    int v2321 = v2319[v2482];
    int v2490 = v2321 + ((int)((unsigned int)(v2321 - v2320) >> 31));
    v2319[v2482] = v2490;
    int * v2323 = v2306->cache_age;
    int v2324 = v2323[v2483];
    int v2492 = v2324 + ((int)((unsigned int)(v2324 - v2320) >> 31));
    v2323[v2483] = v2492;
    int * v2326 = v2306->cache_age;
    v2326[v2489] = 0;
    v2411 = v2489;
  } else {
    int * v2329 = v2306->cache_age;
    int v2496 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2330 = v2329[v2496];
    int * v2331 = v2306->cache_tags;
    int v2332 = v2331[v2496];
    int v2333 = v2329[v2483];
    int v2334 = v2331[v2483];
    bool v2498 = !(((~(((v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2388;
    if (v2498) {
      int * v2335 = v2306->cache_age;
      int v2500 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2336 = v2335[v2500];
      int v2337 = v2335[v2484];
      int v2501 = v2337 + ((int)((unsigned int)(v2337 - v2336) >> 31));
      v2335[v2484] = v2501;
      int * v2339 = v2306->cache_age;
      int v2340 = v2339[v2485];
      int v2503 = v2340 + ((int)((unsigned int)(v2340 - v2336) >> 31));
      v2339[v2485] = v2503;
      int * v2342 = v2306->cache_age;
      v2342[v2500] = 0;
      v2388 = v2500;
    } else {
      int * v2345 = v2306->cache_age;
      int v2507 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2346 = v2345[v2507];
      int * v2347 = v2306->cache_tags;
      int v2348 = v2347[v2507];
      int v2349 = v2345[v2485];
      int v2350 = v2347[v2485];
      int * v2351 = v2306->cache_dirty;
      int v2510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2352 = v2351[v2510];
      bool v2511 = !(v2352 == 0);
      if (v2511) {
        int * v2353 = v2306->cache_tags;
        int v2354 = v2353[v2510];
        int * v2355 = v2306->cache_vals;
        int v2514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2356 = v2355[v2514];
        int v2515 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2357 = v2355[v2515];
        int * v2358 = v2306->mem;
        int v2517 = v2354 * 2;
        v2358[v2517] = v2356;
        int * v2360 = v2306->mem;
        int v2520 = (v2354 * 2) + 1;
        v2360[v2520] = v2357;
        ;
      } else {
        ;
      }
      int * v2365 = v2306->mem;
      int v2525 = ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2;
      int v2366 = v2365[v2525];
      int v2526 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2367 = v2365[v2526];
      int * v2368 = v2306->cache_vals;
      int v2528 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2368[v2528] = v2366;
      int * v2370 = v2306->cache_vals;
      int v2531 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2370[v2531] = v2367;
      int * v2372 = v2306->cache_tags;
      int v2534 = (int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1);
      v2372[v2510] = v2534;
      int * v2374 = v2306->cache_dirty;
      v2374[v2510] = 0;
      int * v2376 = v2306->cache_age;
      v2376[v2510] = 1;
      int * v2378 = v2306->cache_age;
      int v2379 = v2378[v2510];
      int v2380 = v2378[v2484];
      int v2540 = v2380 + ((int)((unsigned int)(v2380 - v2379) >> 31));
      v2378[v2484] = v2540;
      int * v2382 = v2306->cache_age;
      int v2383 = v2382[v2485];
      int v2542 = v2383 + ((int)((unsigned int)(v2383 - v2379) >> 31));
      v2382[v2485] = v2542;
      int * v2385 = v2306->cache_age;
      v2385[v2510] = 0;
      v2388 = v2510;
    }
    int * v2389 = v2306->cache_vals;
    int v2545 = v2388 * 2;
    int v2390 = v2389[v2545];
    int v2546 = (v2388 * 2) + 1;
    int v2391 = v2389[v2546];
    int v2547 = (((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2330 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2)) - (v2333 + ((~(((v2334 ^ -1) | (-(v2334 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2389[v2547] = v2390;
    int * v2393 = v2306->cache_vals;
    int v2550 = ((((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2330 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2)) - (v2333 + ((~(((v2334 ^ -1) | (-(v2334 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2393[v2550] = v2391;
    int * v2395 = v2306->cache_tags;
    int v2553 = ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2330 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2)) - (v2333 + ((~(((v2334 ^ -1) | (-(v2334 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2554 = (int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1);
    v2395[v2553] = v2554;
    int * v2397 = v2306->cache_dirty;
    v2397[v2553] = 0;
    int * v2399 = v2306->cache_age;
    v2399[v2553] = 1;
    int * v2401 = v2306->cache_age;
    int v2402 = v2401[v2553];
    int v2403 = v2401[v2482];
    int v2560 = v2403 + ((int)((unsigned int)(v2403 - v2402) >> 31));
    v2401[v2482] = v2560;
    int * v2405 = v2306->cache_age;
    int v2406 = v2405[v2483];
    int v2562 = v2406 + ((int)((unsigned int)(v2406 - v2402) >> 31));
    v2405[v2483] = v2562;
    int * v2408 = v2306->cache_age;
    v2408[v2553] = 0;
    v2411 = v2553;
  }
  int * v2412 = v2306->cache_vals;
  int v2565 = (v2411 * 2) + (((int)((unsigned int)(v2310 + 4) >> 2)) & 1);
  v2412[v2565] = v2311;
  int * v2414 = v2306->cache_tags;
  int v2415 = v2414[v2484];
  int v2416 = v2414[v2485];
  bool v2568 = !(((~(((v2415 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2415 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2470;
  if (v2568) {
    int * v2417 = v2306->cache_age;
    int v2570 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2418 = v2417[v2570];
    int v2419 = v2417[v2484];
    int v2571 = v2419 + ((int)((unsigned int)(v2419 - v2418) >> 31));
    v2417[v2484] = v2571;
    int * v2421 = v2306->cache_age;
    int v2422 = v2421[v2485];
    int v2573 = v2422 + ((int)((unsigned int)(v2422 - v2418) >> 31));
    v2421[v2485] = v2573;
    int * v2424 = v2306->cache_age;
    v2424[v2570] = 0;
    v2470 = v2570;
  } else {
    int * v2427 = v2306->cache_age;
    int v2577 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2428 = v2427[v2577];
    int * v2429 = v2306->cache_tags;
    int v2430 = v2429[v2577];
    int v2431 = v2427[v2485];
    int v2432 = v2429[v2485];
    int * v2433 = v2306->cache_dirty;
    int v2580 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2434 = v2433[v2580];
    bool v2581 = !(v2434 == 0);
    if (v2581) {
      int * v2435 = v2306->cache_tags;
      int v2436 = v2435[v2580];
      int * v2437 = v2306->cache_vals;
      int v2584 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2438 = v2437[v2584];
      int v2585 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2439 = v2437[v2585];
      int * v2440 = v2306->mem;
      int v2587 = v2436 * 2;
      v2440[v2587] = v2438;
      int * v2442 = v2306->mem;
      int v2590 = (v2436 * 2) + 1;
      v2442[v2590] = v2439;
      ;
    } else {
      ;
    }
    int * v2447 = v2306->mem;
    int v2595 = ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2;
    int v2448 = v2447[v2595];
    int v2596 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2449 = v2447[v2596];
    int * v2450 = v2306->cache_vals;
    int v2598 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2450[v2598] = v2448;
    int * v2452 = v2306->cache_vals;
    int v2601 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2452[v2601] = v2449;
    int * v2454 = v2306->cache_tags;
    int v2604 = (int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1);
    v2454[v2580] = v2604;
    int * v2456 = v2306->cache_dirty;
    v2456[v2580] = 0;
    int * v2458 = v2306->cache_age;
    v2458[v2580] = 1;
    int * v2460 = v2306->cache_age;
    int v2461 = v2460[v2580];
    int v2462 = v2460[v2484];
    int v2610 = v2462 + ((int)((unsigned int)(v2462 - v2461) >> 31));
    v2460[v2484] = v2610;
    int * v2464 = v2306->cache_age;
    int v2465 = v2464[v2485];
    int v2612 = v2465 + ((int)((unsigned int)(v2465 - v2461) >> 31));
    v2464[v2485] = v2612;
    int * v2467 = v2306->cache_age;
    v2467[v2580] = 0;
    v2470 = v2580;
  }
  int * v2471 = v2306->cache_vals;
  int v2615 = (v2470 * 2) + (((int)((unsigned int)(v2310 + 4) >> 2)) & 1);
  v2471[v2615] = v2311;
  int * v2473 = v2306->cache_dirty;
  v2473[v2470] = 1;
  struct StateT * v2475 = slot_27(v2306);
  return v2475;
}

struct StateT * slot_206(struct StateT * v9271) {
  int * v9272 = v9271->saved_regs;
  int * v9273 = v9271->regs;
  int v9274 = v9273[13];
  v9272[13] = v9274;
  int v9276 = v9271->timer;
  int v9287 = v9276 + 1;
  v9271->timer = v9287;
  int * v9278 = v9271->regs;
  int v9279 = v9278[5];
  int v9290 = v9279 << 13;
  v9278[13] = v9290;
  struct StateT * v9281 = slot_207(v9271);
  return v9281;
}

struct StateT * slot_227(struct StateT * v10587) {
  int v10588 = v10587->timer;
  int v10600 = v10588 + 1;
  v10587->timer = v10600;
  int * v10590 = v10587->regs;
  int v10591 = v10590[5];
  int v10592 = v10590[12];
  bool v10604 = (v10591 ^ -2147483648) < (v10592 ^ -2147483648);
  int v10595;
  if (v10604) {
    v10595 = 1;
  } else {
    v10595 = 0;
  }
  int * v10596 = v10587->regs;
  v10596[12] = v10595;
  struct StateT * v10598 = slot_229(v10587);
  return v10598;
}

struct StateT * slot_169(struct StateT * v8217) {
  int v8218 = v8217->timer;
  int v8226 = v8218 + 1;
  v8217->timer = v8226;
  int * v8220 = v8217->regs;
  int v8221 = v8220[6];
  int v8222 = v8220[5];
  int v8230 = v8221 + v8222;
  v8220[5] = v8230;
  struct StateT * v8224 = slot_170(v8217);
  return v8224;
}

struct StateT * slot_64(struct StateT * v3655) {
  int v3656 = v3655->timer;
  int v3660 = v3656 + 1;
  v3655->timer = v3660;
  struct StateT * v3658 = slot_65(v3655);
  return v3658;
}

struct StateT * slot_170(struct StateT * v8233) {
  int v8234 = v8233->timer;
  int v8344 = v8234 + 1;
  v8233->timer = v8344;
  int * v8236 = v8233->regs;
  int v8237 = v8236[11];
  int * v8238 = v8233->cache_tags;
  int v8348 = (((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2;
  int v8239 = v8238[v8348];
  int v8349 = ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8240 = v8238[v8349];
  int v8350 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2);
  int v8241 = v8238[v8350];
  int v8351 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8242 = v8238[v8351];
  int v8243 = v8233->timer;
  int v8352 = v8243 + ((100 ^ (((~(((v8241 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8241 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8239 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8239 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8240 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8240 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8241 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8241 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8233->timer = v8352;
  int * v8245 = v8233->cache_vals;
  bool v8353 = !(((~(((v8239 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8239 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8240 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8240 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v8338;
  if (v8353) {
    int * v8246 = v8233->cache_age;
    int v8355 = ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v8240 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8240 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v8247 = v8246[v8355];
    int v8248 = v8246[v8348];
    int v8356 = v8248 + ((int)((unsigned int)(v8248 - v8247) >> 31));
    v8246[v8348] = v8356;
    int * v8250 = v8233->cache_age;
    int v8251 = v8250[v8349];
    int v8358 = v8251 + ((int)((unsigned int)(v8251 - v8247) >> 31));
    v8250[v8349] = v8358;
    int * v8253 = v8233->cache_age;
    v8253[v8355] = 0;
    v8338 = v8355;
  } else {
    int * v8256 = v8233->cache_age;
    int v8362 = (((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2;
    int v8257 = v8256[v8362];
    int * v8258 = v8233->cache_tags;
    int v8259 = v8258[v8362];
    int v8260 = v8256[v8349];
    int v8261 = v8258[v8349];
    bool v8364 = !(((~(((v8241 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8241 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v8315;
    if (v8364) {
      int * v8262 = v8233->cache_age;
      int v8366 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))) | (-(v8242 ^ ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v8263 = v8262[v8366];
      int v8264 = v8262[v8350];
      int v8367 = v8264 + ((int)((unsigned int)(v8264 - v8263) >> 31));
      v8262[v8350] = v8367;
      int * v8266 = v8233->cache_age;
      int v8267 = v8266[v8351];
      int v8369 = v8267 + ((int)((unsigned int)(v8267 - v8263) >> 31));
      v8266[v8351] = v8369;
      int * v8269 = v8233->cache_age;
      v8269[v8366] = 0;
      v8315 = v8366;
    } else {
      int * v8272 = v8233->cache_age;
      int v8373 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2);
      int v8273 = v8272[v8373];
      int * v8274 = v8233->cache_tags;
      int v8275 = v8274[v8373];
      int v8276 = v8272[v8351];
      int v8277 = v8274[v8351];
      int * v8278 = v8233->cache_dirty;
      int v8376 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8273 + ((~(((v8275 ^ -1) | (-(v8275 ^ -1))) >> 31)) & 2)) - (v8276 + ((~(((v8277 ^ -1) | (-(v8277 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8279 = v8278[v8376];
      bool v8377 = !(v8279 == 0);
      if (v8377) {
        int * v8280 = v8233->cache_tags;
        int v8281 = v8280[v8376];
        int * v8282 = v8233->cache_vals;
        int v8380 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8273 + ((~(((v8275 ^ -1) | (-(v8275 ^ -1))) >> 31)) & 2)) - (v8276 + ((~(((v8277 ^ -1) | (-(v8277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8283 = v8282[v8380];
        int v8381 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8273 + ((~(((v8275 ^ -1) | (-(v8275 ^ -1))) >> 31)) & 2)) - (v8276 + ((~(((v8277 ^ -1) | (-(v8277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8284 = v8282[v8381];
        int * v8285 = v8233->mem;
        int v8383 = v8281 * 2;
        v8285[v8383] = v8283;
        int * v8287 = v8233->mem;
        int v8386 = (v8281 * 2) + 1;
        v8287[v8386] = v8284;
        ;
      } else {
        ;
      }
      int * v8292 = v8233->mem;
      int v8391 = ((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) * 2;
      int v8293 = v8292[v8391];
      int v8392 = (((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) * 2) + 1;
      int v8294 = v8292[v8392];
      int * v8295 = v8233->cache_vals;
      int v8394 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8273 + ((~(((v8275 ^ -1) | (-(v8275 ^ -1))) >> 31)) & 2)) - (v8276 + ((~(((v8277 ^ -1) | (-(v8277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8295[v8394] = v8293;
      int * v8297 = v8233->cache_vals;
      int v8397 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8273 + ((~(((v8275 ^ -1) | (-(v8275 ^ -1))) >> 31)) & 2)) - (v8276 + ((~(((v8277 ^ -1) | (-(v8277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8297[v8397] = v8294;
      int * v8299 = v8233->cache_tags;
      int v8400 = (int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1);
      v8299[v8376] = v8400;
      int * v8301 = v8233->cache_dirty;
      v8301[v8376] = 0;
      int * v8303 = v8233->cache_age;
      v8303[v8376] = 1;
      int * v8305 = v8233->cache_age;
      int v8306 = v8305[v8376];
      int v8307 = v8305[v8350];
      int v8406 = v8307 + ((int)((unsigned int)(v8307 - v8306) >> 31));
      v8305[v8350] = v8406;
      int * v8309 = v8233->cache_age;
      int v8310 = v8309[v8351];
      int v8408 = v8310 + ((int)((unsigned int)(v8310 - v8306) >> 31));
      v8309[v8351] = v8408;
      int * v8312 = v8233->cache_age;
      v8312[v8376] = 0;
      v8315 = v8376;
    }
    int * v8316 = v8233->cache_vals;
    int v8411 = v8315 * 2;
    int v8317 = v8316[v8411];
    int v8412 = (v8315 * 2) + 1;
    int v8318 = v8316[v8412];
    int v8413 = (((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8257 + ((~(((v8259 ^ -1) | (-(v8259 ^ -1))) >> 31)) & 2)) - (v8260 + ((~(((v8261 ^ -1) | (-(v8261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8316[v8413] = v8317;
    int * v8320 = v8233->cache_vals;
    int v8416 = ((((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8257 + ((~(((v8259 ^ -1) | (-(v8259 ^ -1))) >> 31)) & 2)) - (v8260 + ((~(((v8261 ^ -1) | (-(v8261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8320[v8416] = v8318;
    int * v8322 = v8233->cache_tags;
    int v8419 = ((((int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8257 + ((~(((v8259 ^ -1) | (-(v8259 ^ -1))) >> 31)) & 2)) - (v8260 + ((~(((v8261 ^ -1) | (-(v8261 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8420 = (int)((unsigned int)((int)((unsigned int)(v8237 + 32) >> 2)) >> 1);
    v8322[v8419] = v8420;
    int * v8324 = v8233->cache_dirty;
    v8324[v8419] = 0;
    int * v8326 = v8233->cache_age;
    v8326[v8419] = 1;
    int * v8328 = v8233->cache_age;
    int v8329 = v8328[v8419];
    int v8330 = v8328[v8348];
    int v8426 = v8330 + ((int)((unsigned int)(v8330 - v8329) >> 31));
    v8328[v8348] = v8426;
    int * v8332 = v8233->cache_age;
    int v8333 = v8332[v8349];
    int v8428 = v8333 + ((int)((unsigned int)(v8333 - v8329) >> 31));
    v8332[v8349] = v8428;
    int * v8335 = v8233->cache_age;
    v8335[v8419] = 0;
    v8338 = v8419;
  }
  int v8431 = (v8338 * 2) + (((int)((unsigned int)(v8237 + 32) >> 2)) & 1);
  int v8339 = v8245[v8431];
  int * v8340 = v8233->regs;
  v8340[6] = v8339;
  struct StateT * v8342 = slot_171(v8233);
  return v8342;
}

struct StateT * slot_14(struct StateT * v1796) {
  int v1797 = v1796->timer;
  int v1805 = v1797 + 1;
  v1796->timer = v1805;
  int * v1799 = v1796->regs;
  int v1800 = v1799[15];
  int v1801 = v1799[13];
  int v1810 = v1800 * v1801;
  v1799[29] = v1810;
  struct StateT * v1803 = slot_15(v1796);
  return v1803;
}

struct StateT * slot_53(struct StateT * v3451) {
  int v3452 = v3451->timer;
  int v3460 = v3452 + 1;
  v3451->timer = v3460;
  int * v3454 = v3451->regs;
  int v3455 = v3454[31];
  int v3456 = v3454[30];
  int v3464 = v3455 + v3456;
  v3454[30] = v3464;
  struct StateT * v3458 = slot_54(v3451);
  return v3458;
}

struct StateT * slot_80(struct StateT * v4585) {
  int v4586 = v4585->timer;
  int v4696 = v4586 + 1;
  v4585->timer = v4696;
  int * v4588 = v4585->regs;
  int v4589 = v4588[11];
  int * v4590 = v4585->cache_tags;
  int v4700 = (((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2;
  int v4591 = v4590[v4700];
  int v4701 = ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4592 = v4590[v4701];
  int v4702 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2);
  int v4593 = v4590[v4702];
  int v4703 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4594 = v4590[v4703];
  int v4595 = v4585->timer;
  int v4704 = v4595 + ((100 ^ (((~(((v4593 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4593 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4591 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4591 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4592 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4592 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4593 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4593 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4585->timer = v4704;
  int * v4597 = v4585->cache_vals;
  bool v4705 = !(((~(((v4591 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4591 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4592 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4592 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4690;
  if (v4705) {
    int * v4598 = v4585->cache_age;
    int v4707 = ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v4592 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4592 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4599 = v4598[v4707];
    int v4600 = v4598[v4700];
    int v4708 = v4600 + ((int)((unsigned int)(v4600 - v4599) >> 31));
    v4598[v4700] = v4708;
    int * v4602 = v4585->cache_age;
    int v4603 = v4602[v4701];
    int v4710 = v4603 + ((int)((unsigned int)(v4603 - v4599) >> 31));
    v4602[v4701] = v4710;
    int * v4605 = v4585->cache_age;
    v4605[v4707] = 0;
    v4690 = v4707;
  } else {
    int * v4608 = v4585->cache_age;
    int v4714 = (((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2;
    int v4609 = v4608[v4714];
    int * v4610 = v4585->cache_tags;
    int v4611 = v4610[v4714];
    int v4612 = v4608[v4701];
    int v4613 = v4610[v4701];
    bool v4716 = !(((~(((v4593 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4593 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v4667;
    if (v4716) {
      int * v4614 = v4585->cache_age;
      int v4718 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))) | (-(v4594 ^ ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v4615 = v4614[v4718];
      int v4616 = v4614[v4702];
      int v4719 = v4616 + ((int)((unsigned int)(v4616 - v4615) >> 31));
      v4614[v4702] = v4719;
      int * v4618 = v4585->cache_age;
      int v4619 = v4618[v4703];
      int v4721 = v4619 + ((int)((unsigned int)(v4619 - v4615) >> 31));
      v4618[v4703] = v4721;
      int * v4621 = v4585->cache_age;
      v4621[v4718] = 0;
      v4667 = v4718;
    } else {
      int * v4624 = v4585->cache_age;
      int v4725 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2);
      int v4625 = v4624[v4725];
      int * v4626 = v4585->cache_tags;
      int v4627 = v4626[v4725];
      int v4628 = v4624[v4703];
      int v4629 = v4626[v4703];
      int * v4630 = v4585->cache_dirty;
      int v4728 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4625 + ((~(((v4627 ^ -1) | (-(v4627 ^ -1))) >> 31)) & 2)) - (v4628 + ((~(((v4629 ^ -1) | (-(v4629 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4631 = v4630[v4728];
      bool v4729 = !(v4631 == 0);
      if (v4729) {
        int * v4632 = v4585->cache_tags;
        int v4633 = v4632[v4728];
        int * v4634 = v4585->cache_vals;
        int v4732 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4625 + ((~(((v4627 ^ -1) | (-(v4627 ^ -1))) >> 31)) & 2)) - (v4628 + ((~(((v4629 ^ -1) | (-(v4629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4635 = v4634[v4732];
        int v4733 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4625 + ((~(((v4627 ^ -1) | (-(v4627 ^ -1))) >> 31)) & 2)) - (v4628 + ((~(((v4629 ^ -1) | (-(v4629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4636 = v4634[v4733];
        int * v4637 = v4585->mem;
        int v4735 = v4633 * 2;
        v4637[v4735] = v4635;
        int * v4639 = v4585->mem;
        int v4738 = (v4633 * 2) + 1;
        v4639[v4738] = v4636;
        ;
      } else {
        ;
      }
      int * v4644 = v4585->mem;
      int v4743 = ((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) * 2;
      int v4645 = v4644[v4743];
      int v4744 = (((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4646 = v4644[v4744];
      int * v4647 = v4585->cache_vals;
      int v4746 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4625 + ((~(((v4627 ^ -1) | (-(v4627 ^ -1))) >> 31)) & 2)) - (v4628 + ((~(((v4629 ^ -1) | (-(v4629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4647[v4746] = v4645;
      int * v4649 = v4585->cache_vals;
      int v4749 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4625 + ((~(((v4627 ^ -1) | (-(v4627 ^ -1))) >> 31)) & 2)) - (v4628 + ((~(((v4629 ^ -1) | (-(v4629 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4649[v4749] = v4646;
      int * v4651 = v4585->cache_tags;
      int v4752 = (int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1);
      v4651[v4728] = v4752;
      int * v4653 = v4585->cache_dirty;
      v4653[v4728] = 0;
      int * v4655 = v4585->cache_age;
      v4655[v4728] = 1;
      int * v4657 = v4585->cache_age;
      int v4658 = v4657[v4728];
      int v4659 = v4657[v4702];
      int v4758 = v4659 + ((int)((unsigned int)(v4659 - v4658) >> 31));
      v4657[v4702] = v4758;
      int * v4661 = v4585->cache_age;
      int v4662 = v4661[v4703];
      int v4760 = v4662 + ((int)((unsigned int)(v4662 - v4658) >> 31));
      v4661[v4703] = v4760;
      int * v4664 = v4585->cache_age;
      v4664[v4728] = 0;
      v4667 = v4728;
    }
    int * v4668 = v4585->cache_vals;
    int v4763 = v4667 * 2;
    int v4669 = v4668[v4763];
    int v4764 = (v4667 * 2) + 1;
    int v4670 = v4668[v4764];
    int v4765 = (((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4668[v4765] = v4669;
    int * v4672 = v4585->cache_vals;
    int v4768 = ((((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4672[v4768] = v4670;
    int * v4674 = v4585->cache_tags;
    int v4771 = ((((int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4772 = (int)((unsigned int)((int)((unsigned int)(v4589 + 16) >> 2)) >> 1);
    v4674[v4771] = v4772;
    int * v4676 = v4585->cache_dirty;
    v4676[v4771] = 0;
    int * v4678 = v4585->cache_age;
    v4678[v4771] = 1;
    int * v4680 = v4585->cache_age;
    int v4681 = v4680[v4771];
    int v4682 = v4680[v4700];
    int v4778 = v4682 + ((int)((unsigned int)(v4682 - v4681) >> 31));
    v4680[v4700] = v4778;
    int * v4684 = v4585->cache_age;
    int v4685 = v4684[v4701];
    int v4780 = v4685 + ((int)((unsigned int)(v4685 - v4681) >> 31));
    v4684[v4701] = v4780;
    int * v4687 = v4585->cache_age;
    v4687[v4771] = 0;
    v4690 = v4771;
  }
  int v4783 = (v4690 * 2) + (((int)((unsigned int)(v4589 + 16) >> 2)) & 1);
  int v4691 = v4597[v4783];
  int * v4692 = v4585->regs;
  v4692[6] = v4691;
  struct StateT * v4694 = slot_81(v4585);
  return v4694;
}

struct StateT * slot_44(struct StateT * v3287) {
  int v3288 = v3287->timer;
  int v3296 = v3288 + 1;
  v3287->timer = v3296;
  int * v3290 = v3287->regs;
  int v3291 = v3290[5];
  int v3292 = v3290[29];
  int v3300 = v3291 | v3292;
  v3290[5] = v3300;
  struct StateT * v3294 = slot_45(v3287);
  return v3294;
}

struct StateT * slot_137(struct StateT * v6982) {
  int v6983 = v6982->timer;
  int v6991 = v6983 + 1;
  v6982->timer = v6991;
  int * v6985 = v6982->regs;
  int v6986 = v6985[6];
  int v6987 = v6985[12];
  int v6995 = v6986 * v6987;
  v6985[6] = v6995;
  struct StateT * v6989 = slot_138(v6982);
  return v6989;
}

struct StateT * slot_122(struct StateT * v6355) {
  int v6356 = v6355->timer;
  int v6368 = v6356 + 1;
  v6355->timer = v6368;
  int * v6358 = v6355->regs;
  int v6359 = v6358[28];
  int v6360 = v6358[5];
  bool v6372 = (v6359 ^ -2147483648) < (v6360 ^ -2147483648);
  int v6363;
  if (v6372) {
    v6363 = 1;
  } else {
    v6363 = 0;
  }
  int * v6364 = v6355->regs;
  v6364[5] = v6363;
  struct StateT * v6366 = slot_117(v6355);
  return v6366;
}

struct StateT * slot_99(struct StateT * v5290) {
  int v5291 = v5290->timer;
  int v5303 = v5291 + 1;
  v5290->timer = v5303;
  int * v5293 = v5290->regs;
  int v5294 = v5293[29];
  int v5295 = v5293[31];
  bool v5307 = (v5294 ^ -2147483648) < (v5295 ^ -2147483648);
  int v5298;
  if (v5307) {
    v5298 = 1;
  } else {
    v5298 = 0;
  }
  int * v5299 = v5290->regs;
  v5299[6] = v5298;
  struct StateT * v5301 = slot_100(v5290);
  return v5301;
}

struct StateT * slot_179(struct StateT * v8754) {
  int v8755 = v8754->timer;
  int v8763 = v8755 + 1;
  v8754->timer = v8763;
  int * v8757 = v8754->regs;
  int v8758 = v8757[6];
  int v8759 = v8757[13];
  int v8768 = (((((int)((unsigned int)v8758 >> 16)) * ((int)((unsigned int)v8759 >> 16))) + ((int)((unsigned int)((v8758 & 65535) * ((int)((unsigned int)v8759 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8758 >> 16)) * (v8759 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8758 & 65535) * (v8759 & 65535)) >> 16)) + (((v8758 & 65535) * ((int)((unsigned int)v8759 >> 16))) & 65535)) + ((((int)((unsigned int)v8758 >> 16)) * (v8759 & 65535)) & 65535)) >> 16));
  v8757[31] = v8768;
  struct StateT * v8761 = slot_180(v8754);
  return v8761;
}

struct StateT * slot_219(struct StateT * v9501) {
  int v9502 = v9501->timer;
  int v9510 = v9502 + 1;
  v9501->timer = v9510;
  int * v9504 = v9501->regs;
  int v9505 = v9504[12];
  int v9506 = v9504[14];
  int v9514 = v9505 + v9506;
  v9504[12] = v9514;
  struct StateT * v9508 = slot_220(v9501);
  return v9508;
}

struct StateT * slot_36(struct StateT * v3156) {
  int v3157 = v3156->timer;
  int v3165 = v3157 + 1;
  v3156->timer = v3165;
  int * v3159 = v3156->regs;
  int v3160 = v3159[5];
  int v3161 = v3159[6];
  int v3169 = v3160 + v3161;
  v3159[5] = v3169;
  struct StateT * v3163 = slot_37(v3156);
  return v3163;
}

struct StateT * slot_57(struct StateT * v3525) {
  int v3526 = v3525->timer;
  int v3534 = v3526 + 1;
  v3525->timer = v3534;
  int * v3528 = v3525->regs;
  int v3529 = v3528[30];
  int v3530 = v3528[6];
  int v3538 = v3529 + v3530;
  v3528[6] = v3538;
  struct StateT * v3532 = slot_58(v3525);
  return v3532;
}

struct StateT * slot_62(struct StateT * v3623) {
  int v3624 = v3623->timer;
  int v3632 = v3624 + 1;
  v3623->timer = v3632;
  int * v3626 = v3623->regs;
  int v3627 = v3626[7];
  int v3628 = v3626[28];
  int v3636 = v3627 + v3628;
  v3626[7] = v3636;
  struct StateT * v3630 = slot_63(v3623);
  return v3630;
}

struct StateT * slot_22(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1953 = v1945 + 1;
  v1944->timer = v1953;
  int * v1947 = v1944->regs;
  int v1948 = v1947[17];
  int v1949 = v1947[16];
  int v1958 = v1948 & v1949;
  v1947[15] = v1958;
  struct StateT * v1951 = slot_23(v1944);
  return v1951;
}

struct StateT * slot_139(struct StateT * v7015) {
  int v7016 = v7015->timer;
  int v7024 = v7016 + 1;
  v7015->timer = v7024;
  int * v7018 = v7015->regs;
  int v7019 = v7018[6];
  int v7020 = v7018[7];
  int v7029 = v7019 + v7020;
  v7018[17] = v7029;
  struct StateT * v7022 = slot_140(v7015);
  return v7022;
}

struct StateT * slot_221(struct StateT * v9596) {
  int v9597 = v9596->timer;
  int v9605 = v9597 + 1;
  v9596->timer = v9605;
  int * v9599 = v9596->regs;
  int v9600 = v9599[12];
  int v9601 = v9599[5];
  int v9609 = v9600 + v9601;
  v9599[5] = v9609;
  struct StateT * v9603 = slot_223(v9596);
  return v9603;
}

struct StateT * slot_23(struct StateT * v1961) {
  int v1962 = v1961->timer;
  int v1969 = v1962 + 1;
  v1961->timer = v1969;
  int * v1964 = v1961->regs;
  int v1965 = v1964[17];
  int v1972 = (int)((unsigned int)v1965 >> 19);
  v1964[17] = v1972;
  struct StateT * v1967 = slot_24(v1961);
  return v1967;
}

struct StateT * slot_153(struct StateT * v7287) {
  int v7288 = v7287->timer;
  int v7296 = v7288 + 1;
  v7287->timer = v7296;
  int * v7290 = v7287->regs;
  int v7291 = v7290[6];
  int v7292 = v7290[31];
  int v7300 = v7291 + v7292;
  v7290[6] = v7300;
  struct StateT * v7294 = slot_154(v7287);
  return v7294;
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

struct StateT * slot_86(struct StateT * v5056) {
  int v5057 = v5056->timer;
  int v5065 = v5057 + 1;
  v5056->timer = v5065;
  int * v5059 = v5056->regs;
  int v5060 = v5059[29];
  int v5061 = v5059[12];
  int v5070 = v5060 * v5061;
  v5059[28] = v5070;
  struct StateT * v5063 = slot_87(v5056);
  return v5063;
}

struct StateT * slot_129(struct StateT * v6847) {
  int v6848 = v6847->timer;
  int v6856 = v6848 + 1;
  v6847->timer = v6856;
  int * v6850 = v6847->regs;
  int v6851 = v6850[5];
  int v6852 = v6850[17];
  int v6860 = v6851 | v6852;
  v6850[5] = v6860;
  struct StateT * v6854 = slot_130(v6847);
  return v6854;
}

struct StateT * slot_158(struct StateT * v7383) {
  int * v7384 = v7383->saved_regs;
  int * v7385 = v7383->regs;
  int v7386 = v7385[7];
  v7384[7] = v7386;
  int v7388 = v7383->timer;
  int v7399 = v7388 + 1;
  v7383->timer = v7399;
  int * v7390 = v7383->regs;
  int v7391 = v7390[7];
  int v7401 = (int)((unsigned int)v7391 >> 19);
  v7390[7] = v7401;
  struct StateT * v7393 = slot_159(v7383);
  return v7393;
}

struct StateT * slot_100(struct StateT * v5315) {
  int v5316 = v5315->timer;
  int v5324 = v5316 + 1;
  v5315->timer = v5324;
  int * v5318 = v5315->regs;
  int v5319 = v5318[29];
  int v5320 = v5318[5];
  int v5329 = v5319 + v5320;
  v5318[30] = v5329;
  struct StateT * v5322 = slot_101(v5315);
  return v5322;
}

struct StateT * slot_127(struct StateT * v6817) {
  int v6818 = v6817->timer;
  int v6826 = v6818 + 1;
  v6817->timer = v6826;
  int * v6820 = v6817->regs;
  int v6821 = v6820[7];
  int v6822 = v6820[28];
  int v6830 = v6821 | v6822;
  v6820[7] = v6830;
  struct StateT * v6824 = slot_128(v6817);
  return v6824;
}

struct StateT * slot_217(struct StateT * v9454) {
  int * v9455 = v9454->saved_regs;
  int * v9456 = v9454->regs;
  int v9457 = v9456[14];
  v9455[14] = v9457;
  int v9459 = v9454->timer;
  int v9475 = v9459 + 1;
  v9454->timer = v9475;
  int * v9461 = v9454->regs;
  int v9462 = v9461[13];
  int v9463 = v9461[14];
  bool v9478 = (v9462 ^ -2147483648) < (v9463 ^ -2147483648);
  int v9466;
  if (v9478) {
    v9466 = 1;
  } else {
    v9466 = 0;
  }
  int * v9467 = v9454->regs;
  v9467[14] = v9466;
  struct StateT * v9469 = slot_218(v9454);
  return v9469;
}

struct StateT * slot_13(struct StateT * v1779) {
  int v1780 = v1779->timer;
  int v1788 = v1780 + 1;
  v1779->timer = v1788;
  int * v1782 = v1779->regs;
  int v1783 = v1782[14];
  int v1784 = v1782[13];
  int v1793 = (((((int)((unsigned int)v1783 >> 16)) * ((int)((unsigned int)v1784 >> 16))) + ((int)((unsigned int)((v1783 & 65535) * ((int)((unsigned int)v1784 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1783 >> 16)) * (v1784 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1783 & 65535) * (v1784 & 65535)) >> 16)) + (((v1783 & 65535) * ((int)((unsigned int)v1784 >> 16))) & 65535)) + ((((int)((unsigned int)v1783 >> 16)) * (v1784 & 65535)) & 65535)) >> 16));
  v1782[28] = v1793;
  struct StateT * v1786 = slot_14(v1779);
  return v1786;
}

struct StateT * slot_111(struct StateT * v5519) {
  int v5520 = v5519->timer;
  int v5528 = v5520 + 1;
  v5519->timer = v5528;
  int * v5522 = v5519->regs;
  int v5523 = v5522[5];
  int v5524 = v5522[28];
  int v5532 = v5523 + v5524;
  v5522[28] = v5532;
  struct StateT * v5526 = slot_112(v5519);
  return v5526;
}

struct StateT * slot_109(struct StateT * v5479) {
  int v5480 = v5479->timer;
  int v5484 = v5480 + 1;
  v5479->timer = v5484;
  struct StateT * v5482 = slot_110(v5479);
  return v5482;
}

struct StateT * slot_174(struct StateT * v8670) {
  int v8671 = v8670->timer;
  int v8679 = v8671 + 1;
  v8670->timer = v8679;
  int * v8673 = v8670->regs;
  int v8674 = v8673[5];
  int v8675 = v8673[17];
  int v8683 = v8674 | v8675;
  v8673[17] = v8683;
  struct StateT * v8677 = slot_175(v8670);
  return v8677;
}

struct StateT * slot_147(struct StateT * v7172) {
  int v7173 = v7172->timer;
  int v7181 = v7173 + 1;
  v7172->timer = v7181;
  int * v7175 = v7172->regs;
  int v7176 = v7175[7];
  int v7177 = v7175[6];
  int v7185 = v7176 + v7177;
  v7175[6] = v7185;
  struct StateT * v7179 = slot_148(v7172);
  return v7179;
}

struct StateT * slot_42(struct StateT * v3256) {
  int v3257 = v3256->timer;
  int v3265 = v3257 + 1;
  v3256->timer = v3265;
  int * v3259 = v3256->regs;
  int v3260 = v3259[7];
  int v3261 = v3259[13];
  int v3270 = (((((int)((unsigned int)v3260 >> 16)) * ((int)((unsigned int)v3261 >> 16))) + ((int)((unsigned int)((v3260 & 65535) * ((int)((unsigned int)v3261 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3260 >> 16)) * (v3261 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3260 & 65535) * (v3261 & 65535)) >> 16)) + (((v3260 & 65535) * ((int)((unsigned int)v3261 >> 16))) & 65535)) + ((((int)((unsigned int)v3260 >> 16)) * (v3261 & 65535)) & 65535)) >> 16));
  v3259[9] = v3270;
  struct StateT * v3263 = slot_43(v3256);
  return v3263;
}

struct StateT * slot_224(struct StateT * v9943) {
  int v9944 = v9943->timer;
  int v10114 = v9944 + 1;
  v9943->timer = v10114;
  int * v9946 = v9943->regs;
  int v9947 = v9946[10];
  int v9948 = v9946[12];
  int * v9949 = v9943->cache_tags;
  int v10119 = (((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2;
  int v9950 = v9949[v10119];
  int v10120 = ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9951 = v9949[v10120];
  int v10121 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2);
  int v9952 = v9949[v10121];
  int v10122 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9953 = v9949[v10122];
  int v9954 = v9943->timer;
  int v10123 = v9954 + ((100 ^ (((~(((v9952 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9952 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9950 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9950 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9951 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9951 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9952 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9952 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9943->timer = v10123;
  bool v10124 = !(((~(((v9950 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9950 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9951 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9951 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v10048;
  if (v10124) {
    int * v9956 = v9943->cache_age;
    int v10126 = ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v9951 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9951 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v9957 = v9956[v10126];
    int v9958 = v9956[v10119];
    int v10127 = v9958 + ((int)((unsigned int)(v9958 - v9957) >> 31));
    v9956[v10119] = v10127;
    int * v9960 = v9943->cache_age;
    int v9961 = v9960[v10120];
    int v10129 = v9961 + ((int)((unsigned int)(v9961 - v9957) >> 31));
    v9960[v10120] = v10129;
    int * v9963 = v9943->cache_age;
    v9963[v10126] = 0;
    v10048 = v10126;
  } else {
    int * v9966 = v9943->cache_age;
    int v10133 = (((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2;
    int v9967 = v9966[v10133];
    int * v9968 = v9943->cache_tags;
    int v9969 = v9968[v10133];
    int v9970 = v9966[v10120];
    int v9971 = v9968[v10120];
    bool v10135 = !(((~(((v9952 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9952 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v10025;
    if (v10135) {
      int * v9972 = v9943->cache_age;
      int v10137 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v9953 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v9973 = v9972[v10137];
      int v9974 = v9972[v10121];
      int v10138 = v9974 + ((int)((unsigned int)(v9974 - v9973) >> 31));
      v9972[v10121] = v10138;
      int * v9976 = v9943->cache_age;
      int v9977 = v9976[v10122];
      int v10140 = v9977 + ((int)((unsigned int)(v9977 - v9973) >> 31));
      v9976[v10122] = v10140;
      int * v9979 = v9943->cache_age;
      v9979[v10137] = 0;
      v10025 = v10137;
    } else {
      int * v9982 = v9943->cache_age;
      int v10144 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2);
      int v9983 = v9982[v10144];
      int * v9984 = v9943->cache_tags;
      int v9985 = v9984[v10144];
      int v9986 = v9982[v10122];
      int v9987 = v9984[v10122];
      int * v9988 = v9943->cache_dirty;
      int v10147 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9983 + ((~(((v9985 ^ -1) | (-(v9985 ^ -1))) >> 31)) & 2)) - (v9986 + ((~(((v9987 ^ -1) | (-(v9987 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9989 = v9988[v10147];
      bool v10148 = !(v9989 == 0);
      if (v10148) {
        int * v9990 = v9943->cache_tags;
        int v9991 = v9990[v10147];
        int * v9992 = v9943->cache_vals;
        int v10151 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9983 + ((~(((v9985 ^ -1) | (-(v9985 ^ -1))) >> 31)) & 2)) - (v9986 + ((~(((v9987 ^ -1) | (-(v9987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9993 = v9992[v10151];
        int v10152 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9983 + ((~(((v9985 ^ -1) | (-(v9985 ^ -1))) >> 31)) & 2)) - (v9986 + ((~(((v9987 ^ -1) | (-(v9987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9994 = v9992[v10152];
        int * v9995 = v9943->mem;
        int v10154 = v9991 * 2;
        v9995[v10154] = v9993;
        int * v9997 = v9943->mem;
        int v10157 = (v9991 * 2) + 1;
        v9997[v10157] = v9994;
        ;
      } else {
        ;
      }
      int * v10002 = v9943->mem;
      int v10162 = ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) * 2;
      int v10003 = v10002[v10162];
      int v10163 = (((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) * 2) + 1;
      int v10004 = v10002[v10163];
      int * v10005 = v9943->cache_vals;
      int v10165 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9983 + ((~(((v9985 ^ -1) | (-(v9985 ^ -1))) >> 31)) & 2)) - (v9986 + ((~(((v9987 ^ -1) | (-(v9987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10005[v10165] = v10003;
      int * v10007 = v9943->cache_vals;
      int v10168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9983 + ((~(((v9985 ^ -1) | (-(v9985 ^ -1))) >> 31)) & 2)) - (v9986 + ((~(((v9987 ^ -1) | (-(v9987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10007[v10168] = v10004;
      int * v10009 = v9943->cache_tags;
      int v10171 = (int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1);
      v10009[v10147] = v10171;
      int * v10011 = v9943->cache_dirty;
      v10011[v10147] = 0;
      int * v10013 = v9943->cache_age;
      v10013[v10147] = 1;
      int * v10015 = v9943->cache_age;
      int v10016 = v10015[v10147];
      int v10017 = v10015[v10121];
      int v10177 = v10017 + ((int)((unsigned int)(v10017 - v10016) >> 31));
      v10015[v10121] = v10177;
      int * v10019 = v9943->cache_age;
      int v10020 = v10019[v10122];
      int v10179 = v10020 + ((int)((unsigned int)(v10020 - v10016) >> 31));
      v10019[v10122] = v10179;
      int * v10022 = v9943->cache_age;
      v10022[v10147] = 0;
      v10025 = v10147;
    }
    int * v10026 = v9943->cache_vals;
    int v10182 = v10025 * 2;
    int v10027 = v10026[v10182];
    int v10183 = (v10025 * 2) + 1;
    int v10028 = v10026[v10183];
    int v10184 = (((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9967 + ((~(((v9969 ^ -1) | (-(v9969 ^ -1))) >> 31)) & 2)) - (v9970 + ((~(((v9971 ^ -1) | (-(v9971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10026[v10184] = v10027;
    int * v10030 = v9943->cache_vals;
    int v10187 = ((((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9967 + ((~(((v9969 ^ -1) | (-(v9969 ^ -1))) >> 31)) & 2)) - (v9970 + ((~(((v9971 ^ -1) | (-(v9971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10030[v10187] = v10028;
    int * v10032 = v9943->cache_tags;
    int v10190 = ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9967 + ((~(((v9969 ^ -1) | (-(v9969 ^ -1))) >> 31)) & 2)) - (v9970 + ((~(((v9971 ^ -1) | (-(v9971 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10191 = (int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1);
    v10032[v10190] = v10191;
    int * v10034 = v9943->cache_dirty;
    v10034[v10190] = 0;
    int * v10036 = v9943->cache_age;
    v10036[v10190] = 1;
    int * v10038 = v9943->cache_age;
    int v10039 = v10038[v10190];
    int v10040 = v10038[v10119];
    int v10197 = v10040 + ((int)((unsigned int)(v10040 - v10039) >> 31));
    v10038[v10119] = v10197;
    int * v10042 = v9943->cache_age;
    int v10043 = v10042[v10120];
    int v10199 = v10043 + ((int)((unsigned int)(v10043 - v10039) >> 31));
    v10042[v10120] = v10199;
    int * v10045 = v9943->cache_age;
    v10045[v10190] = 0;
    v10048 = v10190;
  }
  int * v10049 = v9943->cache_vals;
  int v10202 = (v10048 * 2) + (((int)((unsigned int)(v9947 + 4) >> 2)) & 1);
  v10049[v10202] = v9948;
  int * v10051 = v9943->cache_tags;
  int v10052 = v10051[v10121];
  int v10053 = v10051[v10122];
  bool v10205 = !(((~(((v10052 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v10052 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v10053 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v10053 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v10107;
  if (v10205) {
    int * v10054 = v9943->cache_age;
    int v10207 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10053 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))) | (-(v10053 ^ ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v10055 = v10054[v10207];
    int v10056 = v10054[v10121];
    int v10208 = v10056 + ((int)((unsigned int)(v10056 - v10055) >> 31));
    v10054[v10121] = v10208;
    int * v10058 = v9943->cache_age;
    int v10059 = v10058[v10122];
    int v10210 = v10059 + ((int)((unsigned int)(v10059 - v10055) >> 31));
    v10058[v10122] = v10210;
    int * v10061 = v9943->cache_age;
    v10061[v10207] = 0;
    v10107 = v10207;
  } else {
    int * v10064 = v9943->cache_age;
    int v10214 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2);
    int v10065 = v10064[v10214];
    int * v10066 = v9943->cache_tags;
    int v10067 = v10066[v10214];
    int v10068 = v10064[v10122];
    int v10069 = v10066[v10122];
    int * v10070 = v9943->cache_dirty;
    int v10217 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10071 = v10070[v10217];
    bool v10218 = !(v10071 == 0);
    if (v10218) {
      int * v10072 = v9943->cache_tags;
      int v10073 = v10072[v10217];
      int * v10074 = v9943->cache_vals;
      int v10221 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10075 = v10074[v10221];
      int v10222 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10076 = v10074[v10222];
      int * v10077 = v9943->mem;
      int v10224 = v10073 * 2;
      v10077[v10224] = v10075;
      int * v10079 = v9943->mem;
      int v10227 = (v10073 * 2) + 1;
      v10079[v10227] = v10076;
      ;
    } else {
      ;
    }
    int * v10084 = v9943->mem;
    int v10232 = ((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) * 2;
    int v10085 = v10084[v10232];
    int v10233 = (((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) * 2) + 1;
    int v10086 = v10084[v10233];
    int * v10087 = v9943->cache_vals;
    int v10235 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10087[v10235] = v10085;
    int * v10089 = v9943->cache_vals;
    int v10238 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10089[v10238] = v10086;
    int * v10091 = v9943->cache_tags;
    int v10241 = (int)((unsigned int)((int)((unsigned int)(v9947 + 4) >> 2)) >> 1);
    v10091[v10217] = v10241;
    int * v10093 = v9943->cache_dirty;
    v10093[v10217] = 0;
    int * v10095 = v9943->cache_age;
    v10095[v10217] = 1;
    int * v10097 = v9943->cache_age;
    int v10098 = v10097[v10217];
    int v10099 = v10097[v10121];
    int v10247 = v10099 + ((int)((unsigned int)(v10099 - v10098) >> 31));
    v10097[v10121] = v10247;
    int * v10101 = v9943->cache_age;
    int v10102 = v10101[v10122];
    int v10249 = v10102 + ((int)((unsigned int)(v10102 - v10098) >> 31));
    v10101[v10122] = v10249;
    int * v10104 = v9943->cache_age;
    v10104[v10217] = 0;
    v10107 = v10217;
  }
  int * v10108 = v9943->cache_vals;
  int v10252 = (v10107 * 2) + (((int)((unsigned int)(v9947 + 4) >> 2)) & 1);
  v10108[v10252] = v9948;
  int * v10110 = v9943->cache_dirty;
  v10110[v10107] = 1;
  struct StateT * v10112 = slot_226(v9943);
  return v10112;
}

struct StateT * slot_163(struct StateT * v7818) {
  int v7819 = v7818->timer;
  int v7827 = v7819 + 1;
  v7818->timer = v7827;
  int * v7821 = v7818->regs;
  int v7822 = v7821[7];
  int v7823 = v7821[16];
  int v7832 = v7822 & v7823;
  v7821[29] = v7832;
  struct StateT * v7825 = slot_165(v7818);
  return v7825;
}

struct StateT * slot_184(struct StateT * v8836) {
  int v8837 = v8836->timer;
  int v8845 = v8837 + 1;
  v8836->timer = v8845;
  int * v8839 = v8836->regs;
  int v8840 = v8839[12];
  int v8841 = v8839[7];
  int v8850 = v8840 + v8841;
  v8839[11] = v8850;
  struct StateT * v8843 = slot_185(v8836);
  return v8843;
}

struct StateT * slot_204(struct StateT * v9224) {
  int * v9225 = v9224->saved_regs;
  int * v9226 = v9224->regs;
  int v9227 = v9226[12];
  v9225[12] = v9227;
  int v9229 = v9224->timer;
  int v9245 = v9229 + 1;
  v9224->timer = v9245;
  int * v9231 = v9224->regs;
  int v9232 = v9231[5];
  int v9233 = v9231[12];
  bool v9248 = (v9232 ^ -2147483648) < (v9233 ^ -2147483648);
  int v9236;
  if (v9248) {
    v9236 = 1;
  } else {
    v9236 = 0;
  }
  int * v9237 = v9224->regs;
  v9237[12] = v9236;
  struct StateT * v9239 = slot_205(v9224);
  return v9239;
}

struct StateT * slot_194(struct StateT * v9027) {
  int v9028 = v9027->timer;
  int v9040 = v9028 + 1;
  v9027->timer = v9040;
  int * v9030 = v9027->regs;
  int v9031 = v9030[28];
  int v9032 = v9030[7];
  bool v9044 = (v9031 ^ -2147483648) < (v9032 ^ -2147483648);
  int v9035;
  if (v9044) {
    v9035 = 1;
  } else {
    v9035 = 0;
  }
  int * v9036 = v9027->regs;
  v9036[7] = v9035;
  struct StateT * v9038 = slot_195(v9027);
  return v9038;
}

struct StateT * slot_165(struct StateT * v8150) {
  int v8151 = v8150->timer;
  int v8158 = v8151 + 1;
  v8150->timer = v8158;
  int * v8153 = v8150->regs;
  int v8154 = v8153[7];
  int v8161 = (int)((unsigned int)v8154 >> 19);
  v8153[7] = v8161;
  struct StateT * v8156 = slot_167(v8150);
  return v8156;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v11986) {
  int v11987 = v11986->timer;
  int v11995 = v11987 + 1;
  v11986->timer = v11995;
  int * v11989 = v11986->regs;
  int v11990 = v11989[12];
  int v11991 = v11989[14];
  int v11999 = v11990 + v11991;
  v11989[12] = v11999;
  struct StateT * v11993 = slot_222(v11986);
  return v11993;
}

struct StateT * slot_117(struct StateT * v5679) {
  int v5680 = v5679->timer;
  int v5850 = v5680 + 1;
  v5679->timer = v5850;
  int * v5682 = v5679->regs;
  int v5683 = v5682[10];
  int v5684 = v5682[17];
  int * v5685 = v5679->cache_tags;
  int v5855 = (((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2;
  int v5686 = v5685[v5855];
  int v5856 = ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5687 = v5685[v5856];
  int v5857 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2);
  int v5688 = v5685[v5857];
  int v5858 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5689 = v5685[v5858];
  int v5690 = v5679->timer;
  int v5859 = v5690 + ((100 ^ (((~(((v5688 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5688 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5686 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5686 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5687 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5687 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5688 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5688 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5679->timer = v5859;
  bool v5860 = !(((~(((v5686 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5686 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5687 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5687 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v5784;
  if (v5860) {
    int * v5692 = v5679->cache_age;
    int v5862 = ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v5687 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5687 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v5693 = v5692[v5862];
    int v5694 = v5692[v5855];
    int v5863 = v5694 + ((int)((unsigned int)(v5694 - v5693) >> 31));
    v5692[v5855] = v5863;
    int * v5696 = v5679->cache_age;
    int v5697 = v5696[v5856];
    int v5865 = v5697 + ((int)((unsigned int)(v5697 - v5693) >> 31));
    v5696[v5856] = v5865;
    int * v5699 = v5679->cache_age;
    v5699[v5862] = 0;
    v5784 = v5862;
  } else {
    int * v5702 = v5679->cache_age;
    int v5869 = (((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2;
    int v5703 = v5702[v5869];
    int * v5704 = v5679->cache_tags;
    int v5705 = v5704[v5869];
    int v5706 = v5702[v5856];
    int v5707 = v5704[v5856];
    bool v5871 = !(((~(((v5688 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5688 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v5761;
    if (v5871) {
      int * v5708 = v5679->cache_age;
      int v5873 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5689 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v5709 = v5708[v5873];
      int v5710 = v5708[v5857];
      int v5874 = v5710 + ((int)((unsigned int)(v5710 - v5709) >> 31));
      v5708[v5857] = v5874;
      int * v5712 = v5679->cache_age;
      int v5713 = v5712[v5858];
      int v5876 = v5713 + ((int)((unsigned int)(v5713 - v5709) >> 31));
      v5712[v5858] = v5876;
      int * v5715 = v5679->cache_age;
      v5715[v5873] = 0;
      v5761 = v5873;
    } else {
      int * v5718 = v5679->cache_age;
      int v5880 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2);
      int v5719 = v5718[v5880];
      int * v5720 = v5679->cache_tags;
      int v5721 = v5720[v5880];
      int v5722 = v5718[v5858];
      int v5723 = v5720[v5858];
      int * v5724 = v5679->cache_dirty;
      int v5883 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5719 + ((~(((v5721 ^ -1) | (-(v5721 ^ -1))) >> 31)) & 2)) - (v5722 + ((~(((v5723 ^ -1) | (-(v5723 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5725 = v5724[v5883];
      bool v5884 = !(v5725 == 0);
      if (v5884) {
        int * v5726 = v5679->cache_tags;
        int v5727 = v5726[v5883];
        int * v5728 = v5679->cache_vals;
        int v5887 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5719 + ((~(((v5721 ^ -1) | (-(v5721 ^ -1))) >> 31)) & 2)) - (v5722 + ((~(((v5723 ^ -1) | (-(v5723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5729 = v5728[v5887];
        int v5888 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5719 + ((~(((v5721 ^ -1) | (-(v5721 ^ -1))) >> 31)) & 2)) - (v5722 + ((~(((v5723 ^ -1) | (-(v5723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5730 = v5728[v5888];
        int * v5731 = v5679->mem;
        int v5890 = v5727 * 2;
        v5731[v5890] = v5729;
        int * v5733 = v5679->mem;
        int v5893 = (v5727 * 2) + 1;
        v5733[v5893] = v5730;
        ;
      } else {
        ;
      }
      int * v5738 = v5679->mem;
      int v5898 = ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) * 2;
      int v5739 = v5738[v5898];
      int v5899 = (((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) * 2) + 1;
      int v5740 = v5738[v5899];
      int * v5741 = v5679->cache_vals;
      int v5901 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5719 + ((~(((v5721 ^ -1) | (-(v5721 ^ -1))) >> 31)) & 2)) - (v5722 + ((~(((v5723 ^ -1) | (-(v5723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5741[v5901] = v5739;
      int * v5743 = v5679->cache_vals;
      int v5904 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5719 + ((~(((v5721 ^ -1) | (-(v5721 ^ -1))) >> 31)) & 2)) - (v5722 + ((~(((v5723 ^ -1) | (-(v5723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5743[v5904] = v5740;
      int * v5745 = v5679->cache_tags;
      int v5907 = (int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1);
      v5745[v5883] = v5907;
      int * v5747 = v5679->cache_dirty;
      v5747[v5883] = 0;
      int * v5749 = v5679->cache_age;
      v5749[v5883] = 1;
      int * v5751 = v5679->cache_age;
      int v5752 = v5751[v5883];
      int v5753 = v5751[v5857];
      int v5913 = v5753 + ((int)((unsigned int)(v5753 - v5752) >> 31));
      v5751[v5857] = v5913;
      int * v5755 = v5679->cache_age;
      int v5756 = v5755[v5858];
      int v5915 = v5756 + ((int)((unsigned int)(v5756 - v5752) >> 31));
      v5755[v5858] = v5915;
      int * v5758 = v5679->cache_age;
      v5758[v5883] = 0;
      v5761 = v5883;
    }
    int * v5762 = v5679->cache_vals;
    int v5918 = v5761 * 2;
    int v5763 = v5762[v5918];
    int v5919 = (v5761 * 2) + 1;
    int v5764 = v5762[v5919];
    int v5920 = (((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5703 + ((~(((v5705 ^ -1) | (-(v5705 ^ -1))) >> 31)) & 2)) - (v5706 + ((~(((v5707 ^ -1) | (-(v5707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5762[v5920] = v5763;
    int * v5766 = v5679->cache_vals;
    int v5923 = ((((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5703 + ((~(((v5705 ^ -1) | (-(v5705 ^ -1))) >> 31)) & 2)) - (v5706 + ((~(((v5707 ^ -1) | (-(v5707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5766[v5923] = v5764;
    int * v5768 = v5679->cache_tags;
    int v5926 = ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5703 + ((~(((v5705 ^ -1) | (-(v5705 ^ -1))) >> 31)) & 2)) - (v5706 + ((~(((v5707 ^ -1) | (-(v5707 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5927 = (int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1);
    v5768[v5926] = v5927;
    int * v5770 = v5679->cache_dirty;
    v5770[v5926] = 0;
    int * v5772 = v5679->cache_age;
    v5772[v5926] = 1;
    int * v5774 = v5679->cache_age;
    int v5775 = v5774[v5926];
    int v5776 = v5774[v5855];
    int v5933 = v5776 + ((int)((unsigned int)(v5776 - v5775) >> 31));
    v5774[v5855] = v5933;
    int * v5778 = v5679->cache_age;
    int v5779 = v5778[v5856];
    int v5935 = v5779 + ((int)((unsigned int)(v5779 - v5775) >> 31));
    v5778[v5856] = v5935;
    int * v5781 = v5679->cache_age;
    v5781[v5926] = 0;
    v5784 = v5926;
  }
  int * v5785 = v5679->cache_vals;
  int v5938 = (v5784 * 2) + (((int)((unsigned int)(v5683 + 16) >> 2)) & 1);
  v5785[v5938] = v5684;
  int * v5787 = v5679->cache_tags;
  int v5788 = v5787[v5857];
  int v5789 = v5787[v5858];
  bool v5941 = !(((~(((v5788 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5788 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5789 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5789 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v5843;
  if (v5941) {
    int * v5790 = v5679->cache_age;
    int v5943 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5789 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))) | (-(v5789 ^ ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v5791 = v5790[v5943];
    int v5792 = v5790[v5857];
    int v5944 = v5792 + ((int)((unsigned int)(v5792 - v5791) >> 31));
    v5790[v5857] = v5944;
    int * v5794 = v5679->cache_age;
    int v5795 = v5794[v5858];
    int v5946 = v5795 + ((int)((unsigned int)(v5795 - v5791) >> 31));
    v5794[v5858] = v5946;
    int * v5797 = v5679->cache_age;
    v5797[v5943] = 0;
    v5843 = v5943;
  } else {
    int * v5800 = v5679->cache_age;
    int v5950 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2);
    int v5801 = v5800[v5950];
    int * v5802 = v5679->cache_tags;
    int v5803 = v5802[v5950];
    int v5804 = v5800[v5858];
    int v5805 = v5802[v5858];
    int * v5806 = v5679->cache_dirty;
    int v5953 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5801 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2)) - (v5804 + ((~(((v5805 ^ -1) | (-(v5805 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5807 = v5806[v5953];
    bool v5954 = !(v5807 == 0);
    if (v5954) {
      int * v5808 = v5679->cache_tags;
      int v5809 = v5808[v5953];
      int * v5810 = v5679->cache_vals;
      int v5957 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5801 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2)) - (v5804 + ((~(((v5805 ^ -1) | (-(v5805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5811 = v5810[v5957];
      int v5958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5801 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2)) - (v5804 + ((~(((v5805 ^ -1) | (-(v5805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5812 = v5810[v5958];
      int * v5813 = v5679->mem;
      int v5960 = v5809 * 2;
      v5813[v5960] = v5811;
      int * v5815 = v5679->mem;
      int v5963 = (v5809 * 2) + 1;
      v5815[v5963] = v5812;
      ;
    } else {
      ;
    }
    int * v5820 = v5679->mem;
    int v5968 = ((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) * 2;
    int v5821 = v5820[v5968];
    int v5969 = (((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) * 2) + 1;
    int v5822 = v5820[v5969];
    int * v5823 = v5679->cache_vals;
    int v5971 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5801 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2)) - (v5804 + ((~(((v5805 ^ -1) | (-(v5805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5823[v5971] = v5821;
    int * v5825 = v5679->cache_vals;
    int v5974 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5801 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2)) - (v5804 + ((~(((v5805 ^ -1) | (-(v5805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5825[v5974] = v5822;
    int * v5827 = v5679->cache_tags;
    int v5977 = (int)((unsigned int)((int)((unsigned int)(v5683 + 16) >> 2)) >> 1);
    v5827[v5953] = v5977;
    int * v5829 = v5679->cache_dirty;
    v5829[v5953] = 0;
    int * v5831 = v5679->cache_age;
    v5831[v5953] = 1;
    int * v5833 = v5679->cache_age;
    int v5834 = v5833[v5953];
    int v5835 = v5833[v5857];
    int v5983 = v5835 + ((int)((unsigned int)(v5835 - v5834) >> 31));
    v5833[v5857] = v5983;
    int * v5837 = v5679->cache_age;
    int v5838 = v5837[v5858];
    int v5985 = v5838 + ((int)((unsigned int)(v5838 - v5834) >> 31));
    v5837[v5858] = v5985;
    int * v5840 = v5679->cache_age;
    v5840[v5953] = 0;
    v5843 = v5953;
  }
  int * v5844 = v5679->cache_vals;
  int v5988 = (v5843 * 2) + (((int)((unsigned int)(v5683 + 16) >> 2)) & 1);
  v5844[v5988] = v5684;
  int * v5846 = v5679->cache_dirty;
  v5846[v5843] = 1;
  struct StateT * v5848 = slot_119(v5679);
  return v5848;
}

struct StateT * slot_249(struct StateT * v11970) {
  int v11971 = v11970->timer;
  int v11979 = v11971 + 1;
  v11970->timer = v11979;
  int * v11973 = v11970->regs;
  int v11974 = v11973[15];
  int v11975 = v11973[12];
  int v11983 = v11974 + v11975;
  v11973[12] = v11983;
  struct StateT * v11977 = slot_250(v11970);
  return v11977;
}

struct StateT * slot_90(struct StateT * v5124) {
  int v5125 = v5124->timer;
  int v5133 = v5125 + 1;
  v5124->timer = v5133;
  int * v5127 = v5124->regs;
  int v5128 = v5127[29];
  int v5129 = v5127[13];
  int v5138 = v5128 * v5129;
  v5127[9] = v5138;
  struct StateT * v5131 = slot_91(v5124);
  return v5131;
}

struct StateT * slot_11(struct StateT * v1745) {
  int v1746 = v1745->timer;
  int v1754 = v1746 + 1;
  v1745->timer = v1754;
  int * v1748 = v1745->regs;
  int v1749 = v1748[15];
  int v1750 = v1748[12];
  int v1759 = (((((int)((unsigned int)v1749 >> 16)) * ((int)((unsigned int)v1750 >> 16))) + ((int)((unsigned int)((v1749 & 65535) * ((int)((unsigned int)v1750 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1749 >> 16)) * (v1750 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1749 & 65535) * (v1750 & 65535)) >> 16)) + (((v1749 & 65535) * ((int)((unsigned int)v1750 >> 16))) & 65535)) + ((((int)((unsigned int)v1749 >> 16)) * (v1750 & 65535)) & 65535)) >> 16));
  v1748[6] = v1759;
  struct StateT * v1752 = slot_12(v1745);
  return v1752;
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