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
struct StateT * slot_143(struct StateT * v7013);
struct StateT * slot_120(struct StateT * v6589);
struct StateT * slot_167(struct StateT * v8393);
struct StateT * slot_152(struct StateT * v7777);
struct StateT * slot_199(struct StateT * v8967);
struct StateT * slot_92(struct StateT * v5112);
struct StateT * slot_31(struct StateT * v3062);
struct StateT * slot_160(struct StateT * v8275);
struct StateT * slot_65(struct StateT * v3693);
struct StateT * slot_10(struct StateT * v1728);
struct StateT * slot_150(struct StateT * v7147);
struct StateT * slot_74(struct StateT * v4432);
struct StateT * slot_107(struct StateT * v5405);
struct StateT * slot_136(struct StateT * v6882);
struct StateT * slot_84(struct StateT * v4970);
struct StateT * slot_28(struct StateT * v2637);
struct StateT * slot_155(struct StateT * v7822);
struct StateT * slot_177(struct StateT * v8582);
struct StateT * slot_17(struct StateT * v1846);
struct StateT * slot_181(struct StateT * v8665);
struct StateT * slot_197(struct StateT * v8934);
struct StateT * slot_207(struct StateT * v9701);
struct StateT * slot_156(struct StateT * v8026);
struct StateT * slot_154(struct StateT * v7806);
struct StateT * slot_68(struct StateT * v3735);
struct StateT * slot_105(struct StateT * v5380);
struct StateT * slot_27(struct StateT * v2621);
struct StateT * slot_164(struct StateT * v8343);
struct StateT * slot_15(struct StateT * v1813);
struct StateT * slot_133(struct StateT * v6824);
struct StateT * slot_56(struct StateT * v3509);
struct StateT * slot_34(struct StateT * v3127);
struct StateT * slot_171(struct StateT * v8467);
struct StateT * slot_162(struct StateT * v8309);
struct StateT * slot_21(struct StateT * v1919);
struct StateT * slot_118(struct StateT * v6559);
struct StateT * slot_121(struct StateT * v6606);
struct StateT * slot_144(struct StateT * v7029);
struct StateT * slot_201(struct StateT * v8999);
struct StateT * slot_94(struct StateT * v5153);
struct StateT * slot_63(struct StateT * v3639);
struct StateT * slot_146(struct StateT * v7051);
struct StateT * slot_24(struct StateT * v1975);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v8904);
struct StateT * slot_125(struct StateT * v6674);
struct StateT * slot_148(struct StateT * v7109);
struct StateT * slot_126(struct StateT * v6691);
struct StateT * slot_79(struct StateT * v4886);
struct StateT * slot_41(struct StateT * v3239);
struct StateT * slot_39(struct StateT * v3205);
struct StateT * slot_142(struct StateT * v6996);
struct StateT * slot_60(struct StateT * v3582);
struct StateT * slot_112(struct StateT * v6090);
struct StateT * slot_47(struct StateT * v3337);
struct StateT * slot_214(struct StateT * v11161);
struct StateT * slot_29(struct StateT * v2841);
struct StateT * slot_16(struct StateT * v1830);
struct StateT * slot_113(struct StateT * v6105);
struct StateT * slot_151(struct StateT * v7462);
struct StateT * slot_7(struct StateT * v1684);
struct StateT * slot_124(struct StateT * v6657);
struct StateT * slot_191(struct StateT * v8846);
struct StateT * slot_103(struct StateT * v5326);
struct StateT * slot_128(struct StateT * v6724);
struct StateT * slot_19(struct StateT * v1887);
struct StateT * slot_87(struct StateT * v5021);
struct StateT * slot_67(struct StateT * v3718);
struct StateT * slot_81(struct StateT * v4919);
struct StateT * slot_95(struct StateT * v5178);
struct StateT * slot_115(struct StateT * v6135);
struct StateT * slot_78(struct StateT * v4872);
struct StateT * slot_32(struct StateT * v3086);
struct StateT * slot_205(struct StateT * v9071);
struct StateT * slot_193(struct StateT * v8877);
struct StateT * slot_176(struct StateT * v8566);
struct StateT * slot_189(struct StateT * v8806);
struct StateT * slot_33(struct StateT * v3111);
struct StateT * slot_35(struct StateT * v3142);
struct StateT * slot_210(struct StateT * v10535);
struct StateT * slot_166(struct StateT * v8377);
struct StateT * slot_51(struct StateT * v3409);
struct StateT * slot_52(struct StateT * v3426);
struct StateT * slot_83(struct StateT * v4953);
struct StateT * slot_25(struct StateT * v1991);
struct StateT * slot_209(struct StateT * v10331);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_123(struct StateT * v6640);
struct StateT * slot_73(struct StateT * v4418);
struct StateT * slot_198(struct StateT * v8951);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v8776);
struct StateT * slot_97(struct StateT * v5211);
struct StateT * slot_182(struct StateT * v8681);
struct StateT * slot_38(struct StateT * v3188);
struct StateT * slot_178(struct StateT * v8599);
struct StateT * slot_106(struct StateT * v5364);
struct StateT * slot_98(struct StateT * v5227);
struct StateT * slot_159(struct StateT * v8259);
struct StateT * slot_46(struct StateT * v3320);
struct StateT * slot_212(struct StateT * v10943);
struct StateT * slot_132(struct StateT * v6799);
struct StateT * slot_130(struct StateT * v6758);
struct StateT * slot_211(struct StateT * v10739);
struct StateT * slot_20(struct StateT * v1903);
struct StateT * slot_141(struct StateT * v6980);
struct StateT * slot_61(struct StateT * v3607);
struct StateT * slot_30(struct StateT * v3045);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_18(struct StateT * v1862);
struct StateT * slot_9(struct StateT * v1711);
struct StateT * slot_183(struct StateT * v8697);
struct StateT * slot_43(struct StateT * v3273);
struct StateT * slot_70(struct StateT * v3773);
struct StateT * slot_168(struct StateT * v8409);
struct StateT * slot_76(struct StateT * v4652);
struct StateT * slot_6(struct StateT * v1480);
struct StateT * slot_55(struct StateT * v3492);
struct StateT * slot_213(struct StateT * v11147);
struct StateT * slot_82(struct StateT * v4936);
struct StateT * slot_161(struct StateT * v8292);
struct StateT * slot_185(struct StateT * v8751);
struct StateT * slot_91(struct StateT * v5096);
struct StateT * slot_58(struct StateT * v3541);
struct StateT * slot_89(struct StateT * v5054);
struct StateT * slot_66(struct StateT * v3677);
struct StateT * slot_140(struct StateT * v6955);
struct StateT * slot_49(struct StateT * v3369);
struct StateT * slot_50(struct StateT * v3385);
struct StateT * slot_37(struct StateT * v3172);
struct StateT * slot_114(struct StateT * v6119);
struct StateT * slot_135(struct StateT * v6865);
struct StateT * slot_59(struct StateT * v3558);
struct StateT * slot_192(struct StateT * v8861);
struct StateT * slot_40(struct StateT * v3222);
struct StateT * slot_48(struct StateT * v3353);
struct StateT * slot_77(struct StateT * v4856);
struct StateT * slot_85(struct StateT * v4987);
struct StateT * slot_75(struct StateT * v4448);
struct StateT * slot_72(struct StateT * v4403);
struct StateT * slot_119(struct StateT * v6573);
struct StateT * slot_71(struct StateT * v4088);
struct StateT * slot_101(struct StateT * v5293);
struct StateT * slot_108(struct StateT * v5422);
struct StateT * slot_116(struct StateT * v6339);
struct StateT * slot_93(struct StateT * v5137);
struct StateT * slot_88(struct StateT * v5037);
struct StateT * slot_96(struct StateT * v5195);
struct StateT * slot_45(struct StateT * v3303);
struct StateT * slot_134(struct StateT * v6840);
struct StateT * slot_175(struct StateT * v8550);
struct StateT * slot_69(struct StateT * v3749);
struct StateT * slot_202(struct StateT * v9015);
struct StateT * slot_188(struct StateT * v8792);
struct StateT * slot_138(struct StateT * v6914);
struct StateT * slot_186(struct StateT * v8735);
struct StateT * slot_102(struct StateT * v5309);
struct StateT * slot_145(struct StateT * v7067);
struct StateT * slot_110(struct StateT * v5460);
struct StateT * slot_196(struct StateT * v8918);
struct StateT * slot_208(struct StateT * v10016);
struct StateT * slot_172(struct StateT * v8484);
struct StateT * slot_131(struct StateT * v6783);
struct StateT * slot_8(struct StateT * v1697);
struct StateT * slot_180(struct StateT * v8640);
struct StateT * slot_203(struct StateT * v9039);
struct StateT * slot_190(struct StateT * v8830);
struct StateT * slot_157(struct StateT * v8229);
struct StateT * slot_200(struct StateT * v8983);
struct StateT * slot_173(struct StateT * v8509);
struct StateT * slot_149(struct StateT * v7123);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_104(struct StateT * v5342);
struct StateT * slot_54(struct StateT * v3467);
struct StateT * slot_26(struct StateT * v2306);
struct StateT * slot_206(struct StateT * v9386);
struct StateT * slot_169(struct StateT * v8425);
struct StateT * slot_64(struct StateT * v3655);
struct StateT * slot_170(struct StateT * v8442);
struct StateT * slot_14(struct StateT * v1796);
struct StateT * slot_53(struct StateT * v3451);
struct StateT * slot_80(struct StateT * v4902);
struct StateT * slot_44(struct StateT * v3287);
struct StateT * slot_137(struct StateT * v6898);
struct StateT * slot_122(struct StateT * v6623);
struct StateT * slot_99(struct StateT * v5244);
struct StateT * slot_179(struct StateT * v8616);
struct StateT * slot_36(struct StateT * v3156);
struct StateT * slot_57(struct StateT * v3525);
struct StateT * slot_62(struct StateT * v3623);
struct StateT * slot_22(struct StateT * v1944);
struct StateT * slot_139(struct StateT * v6931);
struct StateT * slot_23(struct StateT * v1961);
struct StateT * slot_153(struct StateT * v7792);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v5004);
struct StateT * slot_129(struct StateT * v6741);
struct StateT * slot_158(struct StateT * v8245);
struct StateT * slot_100(struct StateT * v5268);
struct StateT * slot_127(struct StateT * v6708);
struct StateT * slot_13(struct StateT * v1779);
struct StateT * slot_111(struct StateT * v5775);
struct StateT * slot_109(struct StateT * v5436);
struct StateT * slot_174(struct StateT * v8525);
struct StateT * slot_147(struct StateT * v7092);
struct StateT * slot_42(struct StateT * v3256);
struct StateT * slot_163(struct StateT * v8326);
struct StateT * slot_184(struct StateT * v8713);
struct StateT * slot_204(struct StateT * v9055);
struct StateT * slot_194(struct StateT * v8890);
struct StateT * slot_165(struct StateT * v8360);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v6543);
struct StateT * slot_90(struct StateT * v5071);
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

struct StateT * slot_143(struct StateT * v7013) {
  int v7014 = v7013->timer;
  int v7022 = v7014 + 1;
  v7013->timer = v7022;
  int * v7016 = v7013->regs;
  int v7017 = v7016[6];
  int v7018 = v7016[31];
  int v7026 = v7017 + v7018;
  v7016[6] = v7026;
  struct StateT * v7020 = slot_144(v7013);
  return v7020;
}

struct StateT * slot_120(struct StateT * v6589) {
  int v6590 = v6589->timer;
  int v6598 = v6590 + 1;
  v6589->timer = v6598;
  int * v6592 = v6589->regs;
  int v6593 = v6592[6];
  int v6594 = v6592[12];
  int v6603 = (((((int)((unsigned int)v6593 >> 16)) * ((int)((unsigned int)v6594 >> 16))) + ((int)((unsigned int)((v6593 & 65535) * ((int)((unsigned int)v6594 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6593 >> 16)) * (v6594 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6593 & 65535) * (v6594 & 65535)) >> 16)) + (((v6593 & 65535) * ((int)((unsigned int)v6594 >> 16))) & 65535)) + ((((int)((unsigned int)v6593 >> 16)) * (v6594 & 65535)) & 65535)) >> 16));
  v6592[17] = v6603;
  struct StateT * v6596 = slot_121(v6589);
  return v6596;
}

struct StateT * slot_167(struct StateT * v8393) {
  int v8394 = v8393->timer;
  int v8402 = v8394 + 1;
  v8393->timer = v8402;
  int * v8396 = v8393->regs;
  int v8397 = v8396[6];
  int v8398 = v8396[12];
  int v8406 = v8397 * v8398;
  v8396[12] = v8406;
  struct StateT * v8400 = slot_168(v8393);
  return v8400;
}

struct StateT * slot_152(struct StateT * v7777) {
  int v7778 = v7777->timer;
  int v7785 = v7778 + 1;
  v7777->timer = v7785;
  int * v7780 = v7777->regs;
  int v7781 = v7780[28];
  int v7789 = (int)((unsigned int)v7781 >> 19);
  v7780[17] = v7789;
  struct StateT * v7783 = slot_153(v7777);
  return v7783;
}

struct StateT * slot_199(struct StateT * v8967) {
  int v8968 = v8967->timer;
  int v8976 = v8968 + 1;
  v8967->timer = v8976;
  int * v8970 = v8967->regs;
  int v8971 = v8970[15];
  int v8972 = v8970[5];
  int v8980 = v8971 + v8972;
  v8970[15] = v8980;
  struct StateT * v8974 = slot_200(v8967);
  return v8974;
}

struct StateT * slot_92(struct StateT * v5112) {
  int v5113 = v5112->timer;
  int v5125 = v5113 + 1;
  v5112->timer = v5125;
  int * v5115 = v5112->regs;
  int v5116 = v5115[17];
  int v5117 = v5115[6];
  bool v5129 = (v5116 ^ -2147483648) < (v5117 ^ -2147483648);
  int v5120;
  if (v5129) {
    v5120 = 1;
  } else {
    v5120 = 0;
  }
  int * v5121 = v5112->regs;
  v5121[28] = v5120;
  struct StateT * v5123 = slot_93(v5112);
  return v5123;
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

struct StateT * slot_160(struct StateT * v8275) {
  int v8276 = v8275->timer;
  int v8284 = v8276 + 1;
  v8275->timer = v8284;
  int * v8278 = v8275->regs;
  int v8279 = v8278[6];
  int v8280 = v8278[12];
  int v8289 = (((((int)((unsigned int)v8279 >> 16)) * ((int)((unsigned int)v8280 >> 16))) + ((int)((unsigned int)((v8279 & 65535) * ((int)((unsigned int)v8280 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8279 >> 16)) * (v8280 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8279 & 65535) * (v8280 & 65535)) >> 16)) + (((v8279 & 65535) * ((int)((unsigned int)v8280 >> 16))) & 65535)) + ((((int)((unsigned int)v8279 >> 16)) * (v8280 & 65535)) & 65535)) >> 16));
  v8278[5] = v8289;
  struct StateT * v8282 = slot_161(v8275);
  return v8282;
}

struct StateT * slot_65(struct StateT * v3693) {
  int v3694 = v3693->timer;
  int v3706 = v3694 + 1;
  v3693->timer = v3706;
  int * v3696 = v3693->regs;
  int v3697 = v3696[7];
  int v3698 = v3696[29];
  bool v3710 = (v3697 ^ -2147483648) < (v3698 ^ -2147483648);
  int v3701;
  if (v3710) {
    v3701 = 1;
  } else {
    v3701 = 0;
  }
  int * v3702 = v3693->regs;
  v3702[28] = v3701;
  struct StateT * v3704 = slot_66(v3693);
  return v3704;
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

struct StateT * slot_150(struct StateT * v7147) {
  int v7148 = v7147->timer;
  int v7318 = v7148 + 1;
  v7147->timer = v7318;
  int * v7150 = v7147->regs;
  int v7151 = v7150[10];
  int v7152 = v7150[17];
  int * v7153 = v7147->cache_tags;
  int v7323 = (((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2;
  int v7154 = v7153[v7323];
  int v7324 = ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7155 = v7153[v7324];
  int v7325 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2);
  int v7156 = v7153[v7325];
  int v7326 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7157 = v7153[v7326];
  int v7158 = v7147->timer;
  int v7327 = v7158 + ((100 ^ (((~(((v7156 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7156 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7154 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7154 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7155 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7155 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7156 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7156 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7147->timer = v7327;
  bool v7328 = !(((~(((v7154 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7154 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7155 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7155 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v7252;
  if (v7328) {
    int * v7160 = v7147->cache_age;
    int v7330 = ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v7155 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7155 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v7161 = v7160[v7330];
    int v7162 = v7160[v7323];
    int v7331 = v7162 + ((int)((unsigned int)(v7162 - v7161) >> 31));
    v7160[v7323] = v7331;
    int * v7164 = v7147->cache_age;
    int v7165 = v7164[v7324];
    int v7333 = v7165 + ((int)((unsigned int)(v7165 - v7161) >> 31));
    v7164[v7324] = v7333;
    int * v7167 = v7147->cache_age;
    v7167[v7330] = 0;
    v7252 = v7330;
  } else {
    int * v7170 = v7147->cache_age;
    int v7337 = (((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2;
    int v7171 = v7170[v7337];
    int * v7172 = v7147->cache_tags;
    int v7173 = v7172[v7337];
    int v7174 = v7170[v7324];
    int v7175 = v7172[v7324];
    bool v7339 = !(((~(((v7156 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7156 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v7229;
    if (v7339) {
      int * v7176 = v7147->cache_age;
      int v7341 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7157 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v7177 = v7176[v7341];
      int v7178 = v7176[v7325];
      int v7342 = v7178 + ((int)((unsigned int)(v7178 - v7177) >> 31));
      v7176[v7325] = v7342;
      int * v7180 = v7147->cache_age;
      int v7181 = v7180[v7326];
      int v7344 = v7181 + ((int)((unsigned int)(v7181 - v7177) >> 31));
      v7180[v7326] = v7344;
      int * v7183 = v7147->cache_age;
      v7183[v7341] = 0;
      v7229 = v7341;
    } else {
      int * v7186 = v7147->cache_age;
      int v7348 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2);
      int v7187 = v7186[v7348];
      int * v7188 = v7147->cache_tags;
      int v7189 = v7188[v7348];
      int v7190 = v7186[v7326];
      int v7191 = v7188[v7326];
      int * v7192 = v7147->cache_dirty;
      int v7351 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7187 + ((~(((v7189 ^ -1) | (-(v7189 ^ -1))) >> 31)) & 2)) - (v7190 + ((~(((v7191 ^ -1) | (-(v7191 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7193 = v7192[v7351];
      bool v7352 = !(v7193 == 0);
      if (v7352) {
        int * v7194 = v7147->cache_tags;
        int v7195 = v7194[v7351];
        int * v7196 = v7147->cache_vals;
        int v7355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7187 + ((~(((v7189 ^ -1) | (-(v7189 ^ -1))) >> 31)) & 2)) - (v7190 + ((~(((v7191 ^ -1) | (-(v7191 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7197 = v7196[v7355];
        int v7356 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7187 + ((~(((v7189 ^ -1) | (-(v7189 ^ -1))) >> 31)) & 2)) - (v7190 + ((~(((v7191 ^ -1) | (-(v7191 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7198 = v7196[v7356];
        int * v7199 = v7147->mem;
        int v7358 = v7195 * 2;
        v7199[v7358] = v7197;
        int * v7201 = v7147->mem;
        int v7361 = (v7195 * 2) + 1;
        v7201[v7361] = v7198;
        ;
      } else {
        ;
      }
      int * v7206 = v7147->mem;
      int v7366 = ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) * 2;
      int v7207 = v7206[v7366];
      int v7367 = (((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) * 2) + 1;
      int v7208 = v7206[v7367];
      int * v7209 = v7147->cache_vals;
      int v7369 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7187 + ((~(((v7189 ^ -1) | (-(v7189 ^ -1))) >> 31)) & 2)) - (v7190 + ((~(((v7191 ^ -1) | (-(v7191 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7209[v7369] = v7207;
      int * v7211 = v7147->cache_vals;
      int v7372 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7187 + ((~(((v7189 ^ -1) | (-(v7189 ^ -1))) >> 31)) & 2)) - (v7190 + ((~(((v7191 ^ -1) | (-(v7191 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7211[v7372] = v7208;
      int * v7213 = v7147->cache_tags;
      int v7375 = (int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1);
      v7213[v7351] = v7375;
      int * v7215 = v7147->cache_dirty;
      v7215[v7351] = 0;
      int * v7217 = v7147->cache_age;
      v7217[v7351] = 1;
      int * v7219 = v7147->cache_age;
      int v7220 = v7219[v7351];
      int v7221 = v7219[v7325];
      int v7381 = v7221 + ((int)((unsigned int)(v7221 - v7220) >> 31));
      v7219[v7325] = v7381;
      int * v7223 = v7147->cache_age;
      int v7224 = v7223[v7326];
      int v7383 = v7224 + ((int)((unsigned int)(v7224 - v7220) >> 31));
      v7223[v7326] = v7383;
      int * v7226 = v7147->cache_age;
      v7226[v7351] = 0;
      v7229 = v7351;
    }
    int * v7230 = v7147->cache_vals;
    int v7386 = v7229 * 2;
    int v7231 = v7230[v7386];
    int v7387 = (v7229 * 2) + 1;
    int v7232 = v7230[v7387];
    int v7388 = (((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7171 + ((~(((v7173 ^ -1) | (-(v7173 ^ -1))) >> 31)) & 2)) - (v7174 + ((~(((v7175 ^ -1) | (-(v7175 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7230[v7388] = v7231;
    int * v7234 = v7147->cache_vals;
    int v7391 = ((((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7171 + ((~(((v7173 ^ -1) | (-(v7173 ^ -1))) >> 31)) & 2)) - (v7174 + ((~(((v7175 ^ -1) | (-(v7175 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7234[v7391] = v7232;
    int * v7236 = v7147->cache_tags;
    int v7394 = ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7171 + ((~(((v7173 ^ -1) | (-(v7173 ^ -1))) >> 31)) & 2)) - (v7174 + ((~(((v7175 ^ -1) | (-(v7175 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7395 = (int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1);
    v7236[v7394] = v7395;
    int * v7238 = v7147->cache_dirty;
    v7238[v7394] = 0;
    int * v7240 = v7147->cache_age;
    v7240[v7394] = 1;
    int * v7242 = v7147->cache_age;
    int v7243 = v7242[v7394];
    int v7244 = v7242[v7323];
    int v7401 = v7244 + ((int)((unsigned int)(v7244 - v7243) >> 31));
    v7242[v7323] = v7401;
    int * v7246 = v7147->cache_age;
    int v7247 = v7246[v7324];
    int v7403 = v7247 + ((int)((unsigned int)(v7247 - v7243) >> 31));
    v7246[v7324] = v7403;
    int * v7249 = v7147->cache_age;
    v7249[v7394] = 0;
    v7252 = v7394;
  }
  int * v7253 = v7147->cache_vals;
  int v7406 = (v7252 * 2) + (((int)((unsigned int)(v7151 + 24) >> 2)) & 1);
  v7253[v7406] = v7152;
  int * v7255 = v7147->cache_tags;
  int v7256 = v7255[v7325];
  int v7257 = v7255[v7326];
  bool v7409 = !(((~(((v7256 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7256 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7257 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7257 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v7311;
  if (v7409) {
    int * v7258 = v7147->cache_age;
    int v7411 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7257 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))) | (-(v7257 ^ ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v7259 = v7258[v7411];
    int v7260 = v7258[v7325];
    int v7412 = v7260 + ((int)((unsigned int)(v7260 - v7259) >> 31));
    v7258[v7325] = v7412;
    int * v7262 = v7147->cache_age;
    int v7263 = v7262[v7326];
    int v7414 = v7263 + ((int)((unsigned int)(v7263 - v7259) >> 31));
    v7262[v7326] = v7414;
    int * v7265 = v7147->cache_age;
    v7265[v7411] = 0;
    v7311 = v7411;
  } else {
    int * v7268 = v7147->cache_age;
    int v7418 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2);
    int v7269 = v7268[v7418];
    int * v7270 = v7147->cache_tags;
    int v7271 = v7270[v7418];
    int v7272 = v7268[v7326];
    int v7273 = v7270[v7326];
    int * v7274 = v7147->cache_dirty;
    int v7421 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7269 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2)) - (v7272 + ((~(((v7273 ^ -1) | (-(v7273 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7275 = v7274[v7421];
    bool v7422 = !(v7275 == 0);
    if (v7422) {
      int * v7276 = v7147->cache_tags;
      int v7277 = v7276[v7421];
      int * v7278 = v7147->cache_vals;
      int v7425 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7269 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2)) - (v7272 + ((~(((v7273 ^ -1) | (-(v7273 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7279 = v7278[v7425];
      int v7426 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7269 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2)) - (v7272 + ((~(((v7273 ^ -1) | (-(v7273 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7280 = v7278[v7426];
      int * v7281 = v7147->mem;
      int v7428 = v7277 * 2;
      v7281[v7428] = v7279;
      int * v7283 = v7147->mem;
      int v7431 = (v7277 * 2) + 1;
      v7283[v7431] = v7280;
      ;
    } else {
      ;
    }
    int * v7288 = v7147->mem;
    int v7436 = ((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) * 2;
    int v7289 = v7288[v7436];
    int v7437 = (((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) * 2) + 1;
    int v7290 = v7288[v7437];
    int * v7291 = v7147->cache_vals;
    int v7439 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7269 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2)) - (v7272 + ((~(((v7273 ^ -1) | (-(v7273 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7291[v7439] = v7289;
    int * v7293 = v7147->cache_vals;
    int v7442 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7269 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2)) - (v7272 + ((~(((v7273 ^ -1) | (-(v7273 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7293[v7442] = v7290;
    int * v7295 = v7147->cache_tags;
    int v7445 = (int)((unsigned int)((int)((unsigned int)(v7151 + 24) >> 2)) >> 1);
    v7295[v7421] = v7445;
    int * v7297 = v7147->cache_dirty;
    v7297[v7421] = 0;
    int * v7299 = v7147->cache_age;
    v7299[v7421] = 1;
    int * v7301 = v7147->cache_age;
    int v7302 = v7301[v7421];
    int v7303 = v7301[v7325];
    int v7451 = v7303 + ((int)((unsigned int)(v7303 - v7302) >> 31));
    v7301[v7325] = v7451;
    int * v7305 = v7147->cache_age;
    int v7306 = v7305[v7326];
    int v7453 = v7306 + ((int)((unsigned int)(v7306 - v7302) >> 31));
    v7305[v7326] = v7453;
    int * v7308 = v7147->cache_age;
    v7308[v7421] = 0;
    v7311 = v7421;
  }
  int * v7312 = v7147->cache_vals;
  int v7456 = (v7311 * 2) + (((int)((unsigned int)(v7151 + 24) >> 2)) & 1);
  v7312[v7456] = v7152;
  int * v7314 = v7147->cache_dirty;
  v7314[v7311] = 1;
  struct StateT * v7316 = slot_151(v7147);
  return v7316;
}

struct StateT * slot_74(struct StateT * v4432) {
  int v4433 = v4432->timer;
  int v4441 = v4433 + 1;
  v4432->timer = v4441;
  int * v4435 = v4432->regs;
  int v4436 = v4435[6];
  int v4437 = v4435[5];
  int v4445 = v4436 + v4437;
  v4435[5] = v4445;
  struct StateT * v4439 = slot_75(v4432);
  return v4439;
}

struct StateT * slot_107(struct StateT * v5405) {
  int v5406 = v5405->timer;
  int v5414 = v5406 + 1;
  v5405->timer = v5414;
  int * v5408 = v5405->regs;
  int v5409 = v5408[7];
  int v5410 = v5408[16];
  int v5419 = v5409 & v5410;
  v5408[29] = v5419;
  struct StateT * v5412 = slot_108(v5405);
  return v5412;
}

struct StateT * slot_136(struct StateT * v6882) {
  int v6883 = v6882->timer;
  int v6891 = v6883 + 1;
  v6882->timer = v6891;
  int * v6885 = v6882->regs;
  int v6886 = v6885[8];
  int v6887 = v6885[6];
  int v6895 = v6886 + v6887;
  v6885[6] = v6895;
  struct StateT * v6889 = slot_137(v6882);
  return v6889;
}

struct StateT * slot_84(struct StateT * v4970) {
  int v4971 = v4970->timer;
  int v4979 = v4971 + 1;
  v4970->timer = v4979;
  int * v4973 = v4970->regs;
  int v4974 = v4973[6];
  int v4975 = v4973[13];
  int v4984 = (((((int)((unsigned int)v4974 >> 16)) * ((int)((unsigned int)v4975 >> 16))) + ((int)((unsigned int)((v4974 & 65535) * ((int)((unsigned int)v4975 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4974 >> 16)) * (v4975 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4974 & 65535) * (v4975 & 65535)) >> 16)) + (((v4974 & 65535) * ((int)((unsigned int)v4975 >> 16))) & 65535)) + ((((int)((unsigned int)v4974 >> 16)) * (v4975 & 65535)) & 65535)) >> 16));
  v4973[8] = v4984;
  struct StateT * v4977 = slot_85(v4970);
  return v4977;
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

struct StateT * slot_155(struct StateT * v7822) {
  int v7823 = v7822->timer;
  int v7933 = v7823 + 1;
  v7822->timer = v7933;
  int * v7825 = v7822->regs;
  int v7826 = v7825[11];
  int * v7827 = v7822->cache_tags;
  int v7937 = (((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2;
  int v7828 = v7827[v7937];
  int v7938 = ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7829 = v7827[v7938];
  int v7939 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2);
  int v7830 = v7827[v7939];
  int v7940 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7831 = v7827[v7940];
  int v7832 = v7822->timer;
  int v7941 = v7832 + ((100 ^ (((~(((v7830 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7830 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7828 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7828 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7829 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7829 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7830 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7830 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7822->timer = v7941;
  int * v7834 = v7822->cache_vals;
  bool v7942 = !(((~(((v7828 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7828 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7829 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7829 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v7927;
  if (v7942) {
    int * v7835 = v7822->cache_age;
    int v7944 = ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v7829 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7829 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v7836 = v7835[v7944];
    int v7837 = v7835[v7937];
    int v7945 = v7837 + ((int)((unsigned int)(v7837 - v7836) >> 31));
    v7835[v7937] = v7945;
    int * v7839 = v7822->cache_age;
    int v7840 = v7839[v7938];
    int v7947 = v7840 + ((int)((unsigned int)(v7840 - v7836) >> 31));
    v7839[v7938] = v7947;
    int * v7842 = v7822->cache_age;
    v7842[v7944] = 0;
    v7927 = v7944;
  } else {
    int * v7845 = v7822->cache_age;
    int v7951 = (((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2;
    int v7846 = v7845[v7951];
    int * v7847 = v7822->cache_tags;
    int v7848 = v7847[v7951];
    int v7849 = v7845[v7938];
    int v7850 = v7847[v7938];
    bool v7953 = !(((~(((v7830 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7830 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v7904;
    if (v7953) {
      int * v7851 = v7822->cache_age;
      int v7955 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))) | (-(v7831 ^ ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v7852 = v7851[v7955];
      int v7853 = v7851[v7939];
      int v7956 = v7853 + ((int)((unsigned int)(v7853 - v7852) >> 31));
      v7851[v7939] = v7956;
      int * v7855 = v7822->cache_age;
      int v7856 = v7855[v7940];
      int v7958 = v7856 + ((int)((unsigned int)(v7856 - v7852) >> 31));
      v7855[v7940] = v7958;
      int * v7858 = v7822->cache_age;
      v7858[v7955] = 0;
      v7904 = v7955;
    } else {
      int * v7861 = v7822->cache_age;
      int v7962 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2);
      int v7862 = v7861[v7962];
      int * v7863 = v7822->cache_tags;
      int v7864 = v7863[v7962];
      int v7865 = v7861[v7940];
      int v7866 = v7863[v7940];
      int * v7867 = v7822->cache_dirty;
      int v7965 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7862 + ((~(((v7864 ^ -1) | (-(v7864 ^ -1))) >> 31)) & 2)) - (v7865 + ((~(((v7866 ^ -1) | (-(v7866 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7868 = v7867[v7965];
      bool v7966 = !(v7868 == 0);
      if (v7966) {
        int * v7869 = v7822->cache_tags;
        int v7870 = v7869[v7965];
        int * v7871 = v7822->cache_vals;
        int v7969 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7862 + ((~(((v7864 ^ -1) | (-(v7864 ^ -1))) >> 31)) & 2)) - (v7865 + ((~(((v7866 ^ -1) | (-(v7866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7872 = v7871[v7969];
        int v7970 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7862 + ((~(((v7864 ^ -1) | (-(v7864 ^ -1))) >> 31)) & 2)) - (v7865 + ((~(((v7866 ^ -1) | (-(v7866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7873 = v7871[v7970];
        int * v7874 = v7822->mem;
        int v7972 = v7870 * 2;
        v7874[v7972] = v7872;
        int * v7876 = v7822->mem;
        int v7975 = (v7870 * 2) + 1;
        v7876[v7975] = v7873;
        ;
      } else {
        ;
      }
      int * v7881 = v7822->mem;
      int v7980 = ((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) * 2;
      int v7882 = v7881[v7980];
      int v7981 = (((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) * 2) + 1;
      int v7883 = v7881[v7981];
      int * v7884 = v7822->cache_vals;
      int v7983 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7862 + ((~(((v7864 ^ -1) | (-(v7864 ^ -1))) >> 31)) & 2)) - (v7865 + ((~(((v7866 ^ -1) | (-(v7866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7884[v7983] = v7882;
      int * v7886 = v7822->cache_vals;
      int v7986 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7862 + ((~(((v7864 ^ -1) | (-(v7864 ^ -1))) >> 31)) & 2)) - (v7865 + ((~(((v7866 ^ -1) | (-(v7866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7886[v7986] = v7883;
      int * v7888 = v7822->cache_tags;
      int v7989 = (int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1);
      v7888[v7965] = v7989;
      int * v7890 = v7822->cache_dirty;
      v7890[v7965] = 0;
      int * v7892 = v7822->cache_age;
      v7892[v7965] = 1;
      int * v7894 = v7822->cache_age;
      int v7895 = v7894[v7965];
      int v7896 = v7894[v7939];
      int v7995 = v7896 + ((int)((unsigned int)(v7896 - v7895) >> 31));
      v7894[v7939] = v7995;
      int * v7898 = v7822->cache_age;
      int v7899 = v7898[v7940];
      int v7997 = v7899 + ((int)((unsigned int)(v7899 - v7895) >> 31));
      v7898[v7940] = v7997;
      int * v7901 = v7822->cache_age;
      v7901[v7965] = 0;
      v7904 = v7965;
    }
    int * v7905 = v7822->cache_vals;
    int v8000 = v7904 * 2;
    int v7906 = v7905[v8000];
    int v8001 = (v7904 * 2) + 1;
    int v7907 = v7905[v8001];
    int v8002 = (((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7846 + ((~(((v7848 ^ -1) | (-(v7848 ^ -1))) >> 31)) & 2)) - (v7849 + ((~(((v7850 ^ -1) | (-(v7850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7905[v8002] = v7906;
    int * v7909 = v7822->cache_vals;
    int v8005 = ((((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7846 + ((~(((v7848 ^ -1) | (-(v7848 ^ -1))) >> 31)) & 2)) - (v7849 + ((~(((v7850 ^ -1) | (-(v7850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7909[v8005] = v7907;
    int * v7911 = v7822->cache_tags;
    int v8008 = ((((int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7846 + ((~(((v7848 ^ -1) | (-(v7848 ^ -1))) >> 31)) & 2)) - (v7849 + ((~(((v7850 ^ -1) | (-(v7850 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8009 = (int)((unsigned int)((int)((unsigned int)(v7826 + 32) >> 2)) >> 1);
    v7911[v8008] = v8009;
    int * v7913 = v7822->cache_dirty;
    v7913[v8008] = 0;
    int * v7915 = v7822->cache_age;
    v7915[v8008] = 1;
    int * v7917 = v7822->cache_age;
    int v7918 = v7917[v8008];
    int v7919 = v7917[v7937];
    int v8015 = v7919 + ((int)((unsigned int)(v7919 - v7918) >> 31));
    v7917[v7937] = v8015;
    int * v7921 = v7822->cache_age;
    int v7922 = v7921[v7938];
    int v8017 = v7922 + ((int)((unsigned int)(v7922 - v7918) >> 31));
    v7921[v7938] = v8017;
    int * v7924 = v7822->cache_age;
    v7924[v8008] = 0;
    v7927 = v8008;
  }
  int v8020 = (v7927 * 2) + (((int)((unsigned int)(v7826 + 32) >> 2)) & 1);
  int v7928 = v7834[v8020];
  int * v7929 = v7822->regs;
  v7929[6] = v7928;
  struct StateT * v7931 = slot_156(v7822);
  return v7931;
}

struct StateT * slot_177(struct StateT * v8582) {
  int v8583 = v8582->timer;
  int v8591 = v8583 + 1;
  v8582->timer = v8591;
  int * v8585 = v8582->regs;
  int v8586 = v8585[7];
  int v8587 = v8585[12];
  int v8596 = v8586 + v8587;
  v8585[28] = v8596;
  struct StateT * v8589 = slot_178(v8582);
  return v8589;
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

struct StateT * slot_181(struct StateT * v8665) {
  int v8666 = v8665->timer;
  int v8674 = v8666 + 1;
  v8665->timer = v8674;
  int * v8668 = v8665->regs;
  int v8669 = v8668[13];
  int v8670 = v8668[7];
  int v8678 = v8669 + v8670;
  v8668[13] = v8678;
  struct StateT * v8672 = slot_182(v8665);
  return v8672;
}

struct StateT * slot_197(struct StateT * v8934) {
  int v8935 = v8934->timer;
  int v8943 = v8935 + 1;
  v8934->timer = v8943;
  int * v8937 = v8934->regs;
  int v8938 = v8937[13];
  int v8939 = v8937[17];
  int v8948 = (((((int)((unsigned int)v8938 >> 16)) * ((int)((unsigned int)v8939 >> 16))) + ((int)((unsigned int)((v8938 & 65535) * ((int)((unsigned int)v8939 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8938 >> 16)) * (v8939 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8938 & 65535) * (v8939 & 65535)) >> 16)) + (((v8938 & 65535) * ((int)((unsigned int)v8939 >> 16))) & 65535)) + ((((int)((unsigned int)v8938 >> 16)) * (v8939 & 65535)) & 65535)) >> 16));
  v8937[5] = v8948;
  struct StateT * v8941 = slot_198(v8934);
  return v8941;
}

struct StateT * slot_207(struct StateT * v9701) {
  int v9702 = v9701->timer;
  int v9872 = v9702 + 1;
  v9701->timer = v9872;
  int * v9704 = v9701->regs;
  int v9705 = v9704[10];
  int v9706 = v9704[11];
  int * v9707 = v9701->cache_tags;
  int v9877 = (((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2;
  int v9708 = v9707[v9877];
  int v9878 = ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9709 = v9707[v9878];
  int v9879 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2);
  int v9710 = v9707[v9879];
  int v9880 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9711 = v9707[v9880];
  int v9712 = v9701->timer;
  int v9881 = v9712 + ((100 ^ (((~(((v9710 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9710 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9708 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9708 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9709 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9709 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9710 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9710 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9701->timer = v9881;
  bool v9882 = !(((~(((v9708 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9708 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9709 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9709 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v9806;
  if (v9882) {
    int * v9714 = v9701->cache_age;
    int v9884 = ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v9709 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9709 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v9715 = v9714[v9884];
    int v9716 = v9714[v9877];
    int v9885 = v9716 + ((int)((unsigned int)(v9716 - v9715) >> 31));
    v9714[v9877] = v9885;
    int * v9718 = v9701->cache_age;
    int v9719 = v9718[v9878];
    int v9887 = v9719 + ((int)((unsigned int)(v9719 - v9715) >> 31));
    v9718[v9878] = v9887;
    int * v9721 = v9701->cache_age;
    v9721[v9884] = 0;
    v9806 = v9884;
  } else {
    int * v9724 = v9701->cache_age;
    int v9891 = (((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2;
    int v9725 = v9724[v9891];
    int * v9726 = v9701->cache_tags;
    int v9727 = v9726[v9891];
    int v9728 = v9724[v9878];
    int v9729 = v9726[v9878];
    bool v9893 = !(((~(((v9710 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9710 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v9783;
    if (v9893) {
      int * v9730 = v9701->cache_age;
      int v9895 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9711 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v9731 = v9730[v9895];
      int v9732 = v9730[v9879];
      int v9896 = v9732 + ((int)((unsigned int)(v9732 - v9731) >> 31));
      v9730[v9879] = v9896;
      int * v9734 = v9701->cache_age;
      int v9735 = v9734[v9880];
      int v9898 = v9735 + ((int)((unsigned int)(v9735 - v9731) >> 31));
      v9734[v9880] = v9898;
      int * v9737 = v9701->cache_age;
      v9737[v9895] = 0;
      v9783 = v9895;
    } else {
      int * v9740 = v9701->cache_age;
      int v9902 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2);
      int v9741 = v9740[v9902];
      int * v9742 = v9701->cache_tags;
      int v9743 = v9742[v9902];
      int v9744 = v9740[v9880];
      int v9745 = v9742[v9880];
      int * v9746 = v9701->cache_dirty;
      int v9905 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9741 + ((~(((v9743 ^ -1) | (-(v9743 ^ -1))) >> 31)) & 2)) - (v9744 + ((~(((v9745 ^ -1) | (-(v9745 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9747 = v9746[v9905];
      bool v9906 = !(v9747 == 0);
      if (v9906) {
        int * v9748 = v9701->cache_tags;
        int v9749 = v9748[v9905];
        int * v9750 = v9701->cache_vals;
        int v9909 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9741 + ((~(((v9743 ^ -1) | (-(v9743 ^ -1))) >> 31)) & 2)) - (v9744 + ((~(((v9745 ^ -1) | (-(v9745 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9751 = v9750[v9909];
        int v9910 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9741 + ((~(((v9743 ^ -1) | (-(v9743 ^ -1))) >> 31)) & 2)) - (v9744 + ((~(((v9745 ^ -1) | (-(v9745 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9752 = v9750[v9910];
        int * v9753 = v9701->mem;
        int v9912 = v9749 * 2;
        v9753[v9912] = v9751;
        int * v9755 = v9701->mem;
        int v9915 = (v9749 * 2) + 1;
        v9755[v9915] = v9752;
        ;
      } else {
        ;
      }
      int * v9760 = v9701->mem;
      int v9920 = ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) * 2;
      int v9761 = v9760[v9920];
      int v9921 = (((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) * 2) + 1;
      int v9762 = v9760[v9921];
      int * v9763 = v9701->cache_vals;
      int v9923 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9741 + ((~(((v9743 ^ -1) | (-(v9743 ^ -1))) >> 31)) & 2)) - (v9744 + ((~(((v9745 ^ -1) | (-(v9745 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9763[v9923] = v9761;
      int * v9765 = v9701->cache_vals;
      int v9926 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9741 + ((~(((v9743 ^ -1) | (-(v9743 ^ -1))) >> 31)) & 2)) - (v9744 + ((~(((v9745 ^ -1) | (-(v9745 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9765[v9926] = v9762;
      int * v9767 = v9701->cache_tags;
      int v9929 = (int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1);
      v9767[v9905] = v9929;
      int * v9769 = v9701->cache_dirty;
      v9769[v9905] = 0;
      int * v9771 = v9701->cache_age;
      v9771[v9905] = 1;
      int * v9773 = v9701->cache_age;
      int v9774 = v9773[v9905];
      int v9775 = v9773[v9879];
      int v9935 = v9775 + ((int)((unsigned int)(v9775 - v9774) >> 31));
      v9773[v9879] = v9935;
      int * v9777 = v9701->cache_age;
      int v9778 = v9777[v9880];
      int v9937 = v9778 + ((int)((unsigned int)(v9778 - v9774) >> 31));
      v9777[v9880] = v9937;
      int * v9780 = v9701->cache_age;
      v9780[v9905] = 0;
      v9783 = v9905;
    }
    int * v9784 = v9701->cache_vals;
    int v9940 = v9783 * 2;
    int v9785 = v9784[v9940];
    int v9941 = (v9783 * 2) + 1;
    int v9786 = v9784[v9941];
    int v9942 = (((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v9725 + ((~(((v9727 ^ -1) | (-(v9727 ^ -1))) >> 31)) & 2)) - (v9728 + ((~(((v9729 ^ -1) | (-(v9729 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9784[v9942] = v9785;
    int * v9788 = v9701->cache_vals;
    int v9945 = ((((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v9725 + ((~(((v9727 ^ -1) | (-(v9727 ^ -1))) >> 31)) & 2)) - (v9728 + ((~(((v9729 ^ -1) | (-(v9729 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9788[v9945] = v9786;
    int * v9790 = v9701->cache_tags;
    int v9948 = ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v9725 + ((~(((v9727 ^ -1) | (-(v9727 ^ -1))) >> 31)) & 2)) - (v9728 + ((~(((v9729 ^ -1) | (-(v9729 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9949 = (int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1);
    v9790[v9948] = v9949;
    int * v9792 = v9701->cache_dirty;
    v9792[v9948] = 0;
    int * v9794 = v9701->cache_age;
    v9794[v9948] = 1;
    int * v9796 = v9701->cache_age;
    int v9797 = v9796[v9948];
    int v9798 = v9796[v9877];
    int v9955 = v9798 + ((int)((unsigned int)(v9798 - v9797) >> 31));
    v9796[v9877] = v9955;
    int * v9800 = v9701->cache_age;
    int v9801 = v9800[v9878];
    int v9957 = v9801 + ((int)((unsigned int)(v9801 - v9797) >> 31));
    v9800[v9878] = v9957;
    int * v9803 = v9701->cache_age;
    v9803[v9948] = 0;
    v9806 = v9948;
  }
  int * v9807 = v9701->cache_vals;
  int v9960 = (v9806 * 2) + (((int)((unsigned int)(v9705 + 32) >> 2)) & 1);
  v9807[v9960] = v9706;
  int * v9809 = v9701->cache_tags;
  int v9810 = v9809[v9879];
  int v9811 = v9809[v9880];
  bool v9963 = !(((~(((v9810 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9810 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v9811 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9811 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v9865;
  if (v9963) {
    int * v9812 = v9701->cache_age;
    int v9965 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9811 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))) | (-(v9811 ^ ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v9813 = v9812[v9965];
    int v9814 = v9812[v9879];
    int v9966 = v9814 + ((int)((unsigned int)(v9814 - v9813) >> 31));
    v9812[v9879] = v9966;
    int * v9816 = v9701->cache_age;
    int v9817 = v9816[v9880];
    int v9968 = v9817 + ((int)((unsigned int)(v9817 - v9813) >> 31));
    v9816[v9880] = v9968;
    int * v9819 = v9701->cache_age;
    v9819[v9965] = 0;
    v9865 = v9965;
  } else {
    int * v9822 = v9701->cache_age;
    int v9972 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2);
    int v9823 = v9822[v9972];
    int * v9824 = v9701->cache_tags;
    int v9825 = v9824[v9972];
    int v9826 = v9822[v9880];
    int v9827 = v9824[v9880];
    int * v9828 = v9701->cache_dirty;
    int v9975 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9823 + ((~(((v9825 ^ -1) | (-(v9825 ^ -1))) >> 31)) & 2)) - (v9826 + ((~(((v9827 ^ -1) | (-(v9827 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9829 = v9828[v9975];
    bool v9976 = !(v9829 == 0);
    if (v9976) {
      int * v9830 = v9701->cache_tags;
      int v9831 = v9830[v9975];
      int * v9832 = v9701->cache_vals;
      int v9979 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9823 + ((~(((v9825 ^ -1) | (-(v9825 ^ -1))) >> 31)) & 2)) - (v9826 + ((~(((v9827 ^ -1) | (-(v9827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9833 = v9832[v9979];
      int v9980 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9823 + ((~(((v9825 ^ -1) | (-(v9825 ^ -1))) >> 31)) & 2)) - (v9826 + ((~(((v9827 ^ -1) | (-(v9827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9834 = v9832[v9980];
      int * v9835 = v9701->mem;
      int v9982 = v9831 * 2;
      v9835[v9982] = v9833;
      int * v9837 = v9701->mem;
      int v9985 = (v9831 * 2) + 1;
      v9837[v9985] = v9834;
      ;
    } else {
      ;
    }
    int * v9842 = v9701->mem;
    int v9990 = ((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) * 2;
    int v9843 = v9842[v9990];
    int v9991 = (((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) * 2) + 1;
    int v9844 = v9842[v9991];
    int * v9845 = v9701->cache_vals;
    int v9993 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9823 + ((~(((v9825 ^ -1) | (-(v9825 ^ -1))) >> 31)) & 2)) - (v9826 + ((~(((v9827 ^ -1) | (-(v9827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9845[v9993] = v9843;
    int * v9847 = v9701->cache_vals;
    int v9996 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v9823 + ((~(((v9825 ^ -1) | (-(v9825 ^ -1))) >> 31)) & 2)) - (v9826 + ((~(((v9827 ^ -1) | (-(v9827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9847[v9996] = v9844;
    int * v9849 = v9701->cache_tags;
    int v9999 = (int)((unsigned int)((int)((unsigned int)(v9705 + 32) >> 2)) >> 1);
    v9849[v9975] = v9999;
    int * v9851 = v9701->cache_dirty;
    v9851[v9975] = 0;
    int * v9853 = v9701->cache_age;
    v9853[v9975] = 1;
    int * v9855 = v9701->cache_age;
    int v9856 = v9855[v9975];
    int v9857 = v9855[v9879];
    int v10005 = v9857 + ((int)((unsigned int)(v9857 - v9856) >> 31));
    v9855[v9879] = v10005;
    int * v9859 = v9701->cache_age;
    int v9860 = v9859[v9880];
    int v10007 = v9860 + ((int)((unsigned int)(v9860 - v9856) >> 31));
    v9859[v9880] = v10007;
    int * v9862 = v9701->cache_age;
    v9862[v9975] = 0;
    v9865 = v9975;
  }
  int * v9866 = v9701->cache_vals;
  int v10010 = (v9865 * 2) + (((int)((unsigned int)(v9705 + 32) >> 2)) & 1);
  v9866[v10010] = v9706;
  int * v9868 = v9701->cache_dirty;
  v9868[v9865] = 1;
  struct StateT * v9870 = slot_208(v9701);
  return v9870;
}

struct StateT * slot_156(struct StateT * v8026) {
  int v8027 = v8026->timer;
  int v8137 = v8027 + 1;
  v8026->timer = v8137;
  int * v8029 = v8026->regs;
  int v8030 = v8029[11];
  int * v8031 = v8026->cache_tags;
  int v8141 = (((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2;
  int v8032 = v8031[v8141];
  int v8142 = ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8033 = v8031[v8142];
  int v8143 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2);
  int v8034 = v8031[v8143];
  int v8144 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8035 = v8031[v8144];
  int v8036 = v8026->timer;
  int v8145 = v8036 + ((100 ^ (((~(((v8034 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8034 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8032 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8032 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8033 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8033 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8034 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8034 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8026->timer = v8145;
  int * v8038 = v8026->cache_vals;
  bool v8146 = !(((~(((v8032 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8032 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8033 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8033 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v8131;
  if (v8146) {
    int * v8039 = v8026->cache_age;
    int v8148 = ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v8033 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8033 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v8040 = v8039[v8148];
    int v8041 = v8039[v8141];
    int v8149 = v8041 + ((int)((unsigned int)(v8041 - v8040) >> 31));
    v8039[v8141] = v8149;
    int * v8043 = v8026->cache_age;
    int v8044 = v8043[v8142];
    int v8151 = v8044 + ((int)((unsigned int)(v8044 - v8040) >> 31));
    v8043[v8142] = v8151;
    int * v8046 = v8026->cache_age;
    v8046[v8148] = 0;
    v8131 = v8148;
  } else {
    int * v8049 = v8026->cache_age;
    int v8155 = (((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2;
    int v8050 = v8049[v8155];
    int * v8051 = v8026->cache_tags;
    int v8052 = v8051[v8155];
    int v8053 = v8049[v8142];
    int v8054 = v8051[v8142];
    bool v8157 = !(((~(((v8034 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8034 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v8108;
    if (v8157) {
      int * v8055 = v8026->cache_age;
      int v8159 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))) | (-(v8035 ^ ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v8056 = v8055[v8159];
      int v8057 = v8055[v8143];
      int v8160 = v8057 + ((int)((unsigned int)(v8057 - v8056) >> 31));
      v8055[v8143] = v8160;
      int * v8059 = v8026->cache_age;
      int v8060 = v8059[v8144];
      int v8162 = v8060 + ((int)((unsigned int)(v8060 - v8056) >> 31));
      v8059[v8144] = v8162;
      int * v8062 = v8026->cache_age;
      v8062[v8159] = 0;
      v8108 = v8159;
    } else {
      int * v8065 = v8026->cache_age;
      int v8166 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2);
      int v8066 = v8065[v8166];
      int * v8067 = v8026->cache_tags;
      int v8068 = v8067[v8166];
      int v8069 = v8065[v8144];
      int v8070 = v8067[v8144];
      int * v8071 = v8026->cache_dirty;
      int v8169 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8066 + ((~(((v8068 ^ -1) | (-(v8068 ^ -1))) >> 31)) & 2)) - (v8069 + ((~(((v8070 ^ -1) | (-(v8070 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8072 = v8071[v8169];
      bool v8170 = !(v8072 == 0);
      if (v8170) {
        int * v8073 = v8026->cache_tags;
        int v8074 = v8073[v8169];
        int * v8075 = v8026->cache_vals;
        int v8173 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8066 + ((~(((v8068 ^ -1) | (-(v8068 ^ -1))) >> 31)) & 2)) - (v8069 + ((~(((v8070 ^ -1) | (-(v8070 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8076 = v8075[v8173];
        int v8174 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8066 + ((~(((v8068 ^ -1) | (-(v8068 ^ -1))) >> 31)) & 2)) - (v8069 + ((~(((v8070 ^ -1) | (-(v8070 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8077 = v8075[v8174];
        int * v8078 = v8026->mem;
        int v8176 = v8074 * 2;
        v8078[v8176] = v8076;
        int * v8080 = v8026->mem;
        int v8179 = (v8074 * 2) + 1;
        v8080[v8179] = v8077;
        ;
      } else {
        ;
      }
      int * v8085 = v8026->mem;
      int v8184 = ((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) * 2;
      int v8086 = v8085[v8184];
      int v8185 = (((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) * 2) + 1;
      int v8087 = v8085[v8185];
      int * v8088 = v8026->cache_vals;
      int v8187 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8066 + ((~(((v8068 ^ -1) | (-(v8068 ^ -1))) >> 31)) & 2)) - (v8069 + ((~(((v8070 ^ -1) | (-(v8070 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8088[v8187] = v8086;
      int * v8090 = v8026->cache_vals;
      int v8190 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8066 + ((~(((v8068 ^ -1) | (-(v8068 ^ -1))) >> 31)) & 2)) - (v8069 + ((~(((v8070 ^ -1) | (-(v8070 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8090[v8190] = v8087;
      int * v8092 = v8026->cache_tags;
      int v8193 = (int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1);
      v8092[v8169] = v8193;
      int * v8094 = v8026->cache_dirty;
      v8094[v8169] = 0;
      int * v8096 = v8026->cache_age;
      v8096[v8169] = 1;
      int * v8098 = v8026->cache_age;
      int v8099 = v8098[v8169];
      int v8100 = v8098[v8143];
      int v8199 = v8100 + ((int)((unsigned int)(v8100 - v8099) >> 31));
      v8098[v8143] = v8199;
      int * v8102 = v8026->cache_age;
      int v8103 = v8102[v8144];
      int v8201 = v8103 + ((int)((unsigned int)(v8103 - v8099) >> 31));
      v8102[v8144] = v8201;
      int * v8105 = v8026->cache_age;
      v8105[v8169] = 0;
      v8108 = v8169;
    }
    int * v8109 = v8026->cache_vals;
    int v8204 = v8108 * 2;
    int v8110 = v8109[v8204];
    int v8205 = (v8108 * 2) + 1;
    int v8111 = v8109[v8205];
    int v8206 = (((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8050 + ((~(((v8052 ^ -1) | (-(v8052 ^ -1))) >> 31)) & 2)) - (v8053 + ((~(((v8054 ^ -1) | (-(v8054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8109[v8206] = v8110;
    int * v8113 = v8026->cache_vals;
    int v8209 = ((((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8050 + ((~(((v8052 ^ -1) | (-(v8052 ^ -1))) >> 31)) & 2)) - (v8053 + ((~(((v8054 ^ -1) | (-(v8054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8113[v8209] = v8111;
    int * v8115 = v8026->cache_tags;
    int v8212 = ((((int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8050 + ((~(((v8052 ^ -1) | (-(v8052 ^ -1))) >> 31)) & 2)) - (v8053 + ((~(((v8054 ^ -1) | (-(v8054 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8213 = (int)((unsigned int)((int)((unsigned int)(v8030 + 36) >> 2)) >> 1);
    v8115[v8212] = v8213;
    int * v8117 = v8026->cache_dirty;
    v8117[v8212] = 0;
    int * v8119 = v8026->cache_age;
    v8119[v8212] = 1;
    int * v8121 = v8026->cache_age;
    int v8122 = v8121[v8212];
    int v8123 = v8121[v8141];
    int v8219 = v8123 + ((int)((unsigned int)(v8123 - v8122) >> 31));
    v8121[v8141] = v8219;
    int * v8125 = v8026->cache_age;
    int v8126 = v8125[v8142];
    int v8221 = v8126 + ((int)((unsigned int)(v8126 - v8122) >> 31));
    v8125[v8142] = v8221;
    int * v8128 = v8026->cache_age;
    v8128[v8212] = 0;
    v8131 = v8212;
  }
  int v8224 = (v8131 * 2) + (((int)((unsigned int)(v8030 + 36) >> 2)) & 1);
  int v8132 = v8038[v8224];
  int * v8133 = v8026->regs;
  v8133[11] = v8132;
  struct StateT * v8135 = slot_157(v8026);
  return v8135;
}

struct StateT * slot_154(struct StateT * v7806) {
  int v7807 = v7806->timer;
  int v7815 = v7807 + 1;
  v7806->timer = v7815;
  int * v7809 = v7806->regs;
  int v7810 = v7809[6];
  int v7811 = v7809[5];
  int v7819 = v7810 + v7811;
  v7809[5] = v7819;
  struct StateT * v7813 = slot_155(v7806);
  return v7813;
}

struct StateT * slot_68(struct StateT * v3735) {
  int v3736 = v3735->timer;
  int v3743 = v3736 + 1;
  v3735->timer = v3743;
  int * v3738 = v3735->regs;
  int v3739 = v3738[7];
  int v3746 = (int)((unsigned int)v3739 >> 19);
  v3738[7] = v3746;
  struct StateT * v3741 = slot_69(v3735);
  return v3741;
}

struct StateT * slot_105(struct StateT * v5380) {
  int v5381 = v5380->timer;
  int v5393 = v5381 + 1;
  v5380->timer = v5393;
  int * v5383 = v5380->regs;
  int v5384 = v5383[7];
  int v5385 = v5383[29];
  bool v5397 = (v5384 ^ -2147483648) < (v5385 ^ -2147483648);
  int v5388;
  if (v5397) {
    v5388 = 1;
  } else {
    v5388 = 0;
  }
  int * v5389 = v5380->regs;
  v5389[28] = v5388;
  struct StateT * v5391 = slot_106(v5380);
  return v5391;
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

struct StateT * slot_164(struct StateT * v8343) {
  int v8344 = v8343->timer;
  int v8352 = v8344 + 1;
  v8343->timer = v8352;
  int * v8346 = v8343->regs;
  int v8347 = v8346[6];
  int v8348 = v8346[13];
  int v8357 = (((((int)((unsigned int)v8347 >> 16)) * ((int)((unsigned int)v8348 >> 16))) + ((int)((unsigned int)((v8347 & 65535) * ((int)((unsigned int)v8348 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8347 >> 16)) * (v8348 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8347 & 65535) * (v8348 & 65535)) >> 16)) + (((v8347 & 65535) * ((int)((unsigned int)v8348 >> 16))) & 65535)) + ((((int)((unsigned int)v8347 >> 16)) * (v8348 & 65535)) & 65535)) >> 16));
  v8346[31] = v8357;
  struct StateT * v8350 = slot_165(v8343);
  return v8350;
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

struct StateT * slot_133(struct StateT * v6824) {
  int v6825 = v6824->timer;
  int v6833 = v6825 + 1;
  v6824->timer = v6833;
  int * v6827 = v6824->regs;
  int v6828 = v6827[30];
  int v6829 = v6827[7];
  int v6837 = v6828 + v6829;
  v6827[7] = v6837;
  struct StateT * v6831 = slot_134(v6824);
  return v6831;
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

struct StateT * slot_171(struct StateT * v8467) {
  int v8468 = v8467->timer;
  int v8476 = v8468 + 1;
  v8467->timer = v8476;
  int * v8470 = v8467->regs;
  int v8471 = v8470[30];
  int v8472 = v8470[5];
  int v8481 = v8471 + v8472;
  v8470[6] = v8481;
  struct StateT * v8474 = slot_172(v8467);
  return v8474;
}

struct StateT * slot_162(struct StateT * v8309) {
  int v8310 = v8309->timer;
  int v8318 = v8310 + 1;
  v8309->timer = v8318;
  int * v8312 = v8309->regs;
  int v8313 = v8312[11];
  int v8314 = v8312[12];
  int v8323 = (((((int)((unsigned int)v8313 >> 16)) * ((int)((unsigned int)v8314 >> 16))) + ((int)((unsigned int)((v8313 & 65535) * ((int)((unsigned int)v8314 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8313 >> 16)) * (v8314 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8313 & 65535) * (v8314 & 65535)) >> 16)) + (((v8313 & 65535) * ((int)((unsigned int)v8314 >> 16))) & 65535)) + ((((int)((unsigned int)v8313 >> 16)) * (v8314 & 65535)) & 65535)) >> 16));
  v8312[29] = v8323;
  struct StateT * v8316 = slot_163(v8309);
  return v8316;
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

struct StateT * slot_118(struct StateT * v6559) {
  int v6560 = v6559->timer;
  int v6567 = v6560 + 1;
  v6559->timer = v6567;
  int * v6562 = v6559->regs;
  int v6563 = v6562[5];
  int v6570 = v6563 << 13;
  v6562[5] = v6570;
  struct StateT * v6565 = slot_119(v6559);
  return v6565;
}

struct StateT * slot_121(struct StateT * v6606) {
  int v6607 = v6606->timer;
  int v6615 = v6607 + 1;
  v6606->timer = v6615;
  int * v6609 = v6606->regs;
  int v6610 = v6609[29];
  int v6611 = v6609[12];
  int v6620 = v6610 * v6611;
  v6609[28] = v6620;
  struct StateT * v6613 = slot_122(v6606);
  return v6613;
}

struct StateT * slot_144(struct StateT * v7029) {
  int v7030 = v7029->timer;
  int v7041 = v7030 + 1;
  v7029->timer = v7041;
  int * v7032 = v7029->regs;
  int v7033 = v7032[7];
  int v7034 = v7032[29];
  bool v7045 = v7033 == v7034;
  struct StateT * v7039;
  if (v7045) {
    struct StateT * v7035 = slot_146(v7029);
    v7039 = v7035;
  } else {
    struct StateT * v7037 = slot_145(v7029);
    v7039 = v7037;
  }
  return v7039;
}

struct StateT * slot_201(struct StateT * v8999) {
  int v9000 = v8999->timer;
  int v9008 = v9000 + 1;
  v8999->timer = v9008;
  int * v9002 = v8999->regs;
  int v9003 = v9002[12];
  int v9004 = v9002[17];
  int v9012 = v9003 * v9004;
  v9002[12] = v9012;
  struct StateT * v9006 = slot_202(v8999);
  return v9006;
}

struct StateT * slot_94(struct StateT * v5153) {
  int v5154 = v5153->timer;
  int v5166 = v5154 + 1;
  v5153->timer = v5166;
  int * v5156 = v5153->regs;
  int v5157 = v5156[29];
  int v5158 = v5156[31];
  bool v5170 = (v5157 ^ -2147483648) < (v5158 ^ -2147483648);
  int v5161;
  if (v5170) {
    v5161 = 1;
  } else {
    v5161 = 0;
  }
  int * v5162 = v5153->regs;
  v5162[6] = v5161;
  struct StateT * v5164 = slot_95(v5153);
  return v5164;
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

struct StateT * slot_146(struct StateT * v7051) {
  int v7052 = v7051->timer;
  int v7060 = v7052 + 1;
  v7051->timer = v7060;
  int * v7054 = v7051->regs;
  int v7055 = v7054[5];
  int v7056 = v7054[28];
  int v7064 = v7055 + v7056;
  v7054[28] = v7064;
  struct StateT * v7058 = slot_147(v7051);
  return v7058;
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

struct StateT * slot_195(struct StateT * v8904) {
  int v8905 = v8904->timer;
  int v8912 = v8905 + 1;
  v8904->timer = v8912;
  int * v8907 = v8904->regs;
  int v8908 = v8907[12];
  int v8915 = v8908 << 13;
  v8907[12] = v8915;
  struct StateT * v8910 = slot_196(v8904);
  return v8910;
}

struct StateT * slot_125(struct StateT * v6674) {
  int v6675 = v6674->timer;
  int v6683 = v6675 + 1;
  v6674->timer = v6683;
  int * v6677 = v6674->regs;
  int v6678 = v6677[29];
  int v6679 = v6677[13];
  int v6688 = v6678 * v6679;
  v6677[9] = v6688;
  struct StateT * v6681 = slot_126(v6674);
  return v6681;
}

struct StateT * slot_148(struct StateT * v7109) {
  int v7110 = v7109->timer;
  int v7117 = v7110 + 1;
  v7109->timer = v7117;
  int * v7112 = v7109->regs;
  int v7113 = v7112[7];
  int v7120 = (int)((unsigned int)v7113 >> 19);
  v7112[7] = v7120;
  struct StateT * v7115 = slot_149(v7109);
  return v7115;
}

struct StateT * slot_126(struct StateT * v6691) {
  int v6692 = v6691->timer;
  int v6700 = v6692 + 1;
  v6691->timer = v6700;
  int * v6694 = v6691->regs;
  int v6695 = v6694[29];
  int v6696 = v6694[13];
  int v6705 = (((((int)((unsigned int)v6695 >> 16)) * ((int)((unsigned int)v6696 >> 16))) + ((int)((unsigned int)((v6695 & 65535) * ((int)((unsigned int)v6696 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6695 >> 16)) * (v6696 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6695 & 65535) * (v6696 & 65535)) >> 16)) + (((v6695 & 65535) * ((int)((unsigned int)v6696 >> 16))) & 65535)) + ((((int)((unsigned int)v6695 >> 16)) * (v6696 & 65535)) & 65535)) >> 16));
  v6694[18] = v6705;
  struct StateT * v6698 = slot_127(v6691);
  return v6698;
}

struct StateT * slot_79(struct StateT * v4886) {
  int v4887 = v4886->timer;
  int v4895 = v4887 + 1;
  v4886->timer = v4895;
  int * v4889 = v4886->regs;
  int v4890 = v4889[5];
  int v4891 = v4889[17];
  int v4899 = v4890 | v4891;
  v4889[5] = v4899;
  struct StateT * v4893 = slot_80(v4886);
  return v4893;
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

struct StateT * slot_142(struct StateT * v6996) {
  int v6997 = v6996->timer;
  int v7005 = v6997 + 1;
  v6996->timer = v7005;
  int * v6999 = v6996->regs;
  int v7000 = v6999[30];
  int v7001 = v6999[28];
  int v7010 = v7000 + v7001;
  v6999[7] = v7010;
  struct StateT * v7003 = slot_143(v6996);
  return v7003;
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

struct StateT * slot_112(struct StateT * v6090) {
  int v6091 = v6090->timer;
  int v6098 = v6091 + 1;
  v6090->timer = v6098;
  int * v6093 = v6090->regs;
  int v6094 = v6093[28];
  int v6102 = (int)((unsigned int)v6094 >> 19);
  v6093[17] = v6102;
  struct StateT * v6096 = slot_113(v6090);
  return v6096;
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

struct StateT * slot_214(struct StateT * v11161) {
  int v11162 = v11161->timer;
  int v11165 = v11162 + 1;
  v11161->timer = v11165;
  return v11161;
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

struct StateT * slot_113(struct StateT * v6105) {
  int v6106 = v6105->timer;
  int v6113 = v6106 + 1;
  v6105->timer = v6113;
  int * v6108 = v6105->regs;
  int v6109 = v6108[28];
  int v6116 = v6109 << 13;
  v6108[28] = v6116;
  struct StateT * v6111 = slot_114(v6105);
  return v6111;
}

struct StateT * slot_151(struct StateT * v7462) {
  int v7463 = v7462->timer;
  int v7633 = v7463 + 1;
  v7462->timer = v7633;
  int * v7465 = v7462->regs;
  int v7466 = v7465[10];
  int v7467 = v7465[29];
  int * v7468 = v7462->cache_tags;
  int v7638 = (((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2;
  int v7469 = v7468[v7638];
  int v7639 = ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7470 = v7468[v7639];
  int v7640 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2);
  int v7471 = v7468[v7640];
  int v7641 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7472 = v7468[v7641];
  int v7473 = v7462->timer;
  int v7642 = v7473 + ((100 ^ (((~(((v7471 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7471 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7469 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7469 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7470 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7470 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7471 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7471 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7462->timer = v7642;
  bool v7643 = !(((~(((v7469 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7469 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7470 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7470 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v7567;
  if (v7643) {
    int * v7475 = v7462->cache_age;
    int v7645 = ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v7470 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7470 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7476 = v7475[v7645];
    int v7477 = v7475[v7638];
    int v7646 = v7477 + ((int)((unsigned int)(v7477 - v7476) >> 31));
    v7475[v7638] = v7646;
    int * v7479 = v7462->cache_age;
    int v7480 = v7479[v7639];
    int v7648 = v7480 + ((int)((unsigned int)(v7480 - v7476) >> 31));
    v7479[v7639] = v7648;
    int * v7482 = v7462->cache_age;
    v7482[v7645] = 0;
    v7567 = v7645;
  } else {
    int * v7485 = v7462->cache_age;
    int v7652 = (((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2;
    int v7486 = v7485[v7652];
    int * v7487 = v7462->cache_tags;
    int v7488 = v7487[v7652];
    int v7489 = v7485[v7639];
    int v7490 = v7487[v7639];
    bool v7654 = !(((~(((v7471 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7471 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v7544;
    if (v7654) {
      int * v7491 = v7462->cache_age;
      int v7656 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7472 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v7492 = v7491[v7656];
      int v7493 = v7491[v7640];
      int v7657 = v7493 + ((int)((unsigned int)(v7493 - v7492) >> 31));
      v7491[v7640] = v7657;
      int * v7495 = v7462->cache_age;
      int v7496 = v7495[v7641];
      int v7659 = v7496 + ((int)((unsigned int)(v7496 - v7492) >> 31));
      v7495[v7641] = v7659;
      int * v7498 = v7462->cache_age;
      v7498[v7656] = 0;
      v7544 = v7656;
    } else {
      int * v7501 = v7462->cache_age;
      int v7663 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2);
      int v7502 = v7501[v7663];
      int * v7503 = v7462->cache_tags;
      int v7504 = v7503[v7663];
      int v7505 = v7501[v7641];
      int v7506 = v7503[v7641];
      int * v7507 = v7462->cache_dirty;
      int v7666 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7502 + ((~(((v7504 ^ -1) | (-(v7504 ^ -1))) >> 31)) & 2)) - (v7505 + ((~(((v7506 ^ -1) | (-(v7506 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7508 = v7507[v7666];
      bool v7667 = !(v7508 == 0);
      if (v7667) {
        int * v7509 = v7462->cache_tags;
        int v7510 = v7509[v7666];
        int * v7511 = v7462->cache_vals;
        int v7670 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7502 + ((~(((v7504 ^ -1) | (-(v7504 ^ -1))) >> 31)) & 2)) - (v7505 + ((~(((v7506 ^ -1) | (-(v7506 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7512 = v7511[v7670];
        int v7671 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7502 + ((~(((v7504 ^ -1) | (-(v7504 ^ -1))) >> 31)) & 2)) - (v7505 + ((~(((v7506 ^ -1) | (-(v7506 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7513 = v7511[v7671];
        int * v7514 = v7462->mem;
        int v7673 = v7510 * 2;
        v7514[v7673] = v7512;
        int * v7516 = v7462->mem;
        int v7676 = (v7510 * 2) + 1;
        v7516[v7676] = v7513;
        ;
      } else {
        ;
      }
      int * v7521 = v7462->mem;
      int v7681 = ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) * 2;
      int v7522 = v7521[v7681];
      int v7682 = (((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) * 2) + 1;
      int v7523 = v7521[v7682];
      int * v7524 = v7462->cache_vals;
      int v7684 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7502 + ((~(((v7504 ^ -1) | (-(v7504 ^ -1))) >> 31)) & 2)) - (v7505 + ((~(((v7506 ^ -1) | (-(v7506 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7524[v7684] = v7522;
      int * v7526 = v7462->cache_vals;
      int v7687 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7502 + ((~(((v7504 ^ -1) | (-(v7504 ^ -1))) >> 31)) & 2)) - (v7505 + ((~(((v7506 ^ -1) | (-(v7506 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7526[v7687] = v7523;
      int * v7528 = v7462->cache_tags;
      int v7690 = (int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1);
      v7528[v7666] = v7690;
      int * v7530 = v7462->cache_dirty;
      v7530[v7666] = 0;
      int * v7532 = v7462->cache_age;
      v7532[v7666] = 1;
      int * v7534 = v7462->cache_age;
      int v7535 = v7534[v7666];
      int v7536 = v7534[v7640];
      int v7696 = v7536 + ((int)((unsigned int)(v7536 - v7535) >> 31));
      v7534[v7640] = v7696;
      int * v7538 = v7462->cache_age;
      int v7539 = v7538[v7641];
      int v7698 = v7539 + ((int)((unsigned int)(v7539 - v7535) >> 31));
      v7538[v7641] = v7698;
      int * v7541 = v7462->cache_age;
      v7541[v7666] = 0;
      v7544 = v7666;
    }
    int * v7545 = v7462->cache_vals;
    int v7701 = v7544 * 2;
    int v7546 = v7545[v7701];
    int v7702 = (v7544 * 2) + 1;
    int v7547 = v7545[v7702];
    int v7703 = (((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7486 + ((~(((v7488 ^ -1) | (-(v7488 ^ -1))) >> 31)) & 2)) - (v7489 + ((~(((v7490 ^ -1) | (-(v7490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7545[v7703] = v7546;
    int * v7549 = v7462->cache_vals;
    int v7706 = ((((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7486 + ((~(((v7488 ^ -1) | (-(v7488 ^ -1))) >> 31)) & 2)) - (v7489 + ((~(((v7490 ^ -1) | (-(v7490 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7549[v7706] = v7547;
    int * v7551 = v7462->cache_tags;
    int v7709 = ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7486 + ((~(((v7488 ^ -1) | (-(v7488 ^ -1))) >> 31)) & 2)) - (v7489 + ((~(((v7490 ^ -1) | (-(v7490 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7710 = (int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1);
    v7551[v7709] = v7710;
    int * v7553 = v7462->cache_dirty;
    v7553[v7709] = 0;
    int * v7555 = v7462->cache_age;
    v7555[v7709] = 1;
    int * v7557 = v7462->cache_age;
    int v7558 = v7557[v7709];
    int v7559 = v7557[v7638];
    int v7716 = v7559 + ((int)((unsigned int)(v7559 - v7558) >> 31));
    v7557[v7638] = v7716;
    int * v7561 = v7462->cache_age;
    int v7562 = v7561[v7639];
    int v7718 = v7562 + ((int)((unsigned int)(v7562 - v7558) >> 31));
    v7561[v7639] = v7718;
    int * v7564 = v7462->cache_age;
    v7564[v7709] = 0;
    v7567 = v7709;
  }
  int * v7568 = v7462->cache_vals;
  int v7721 = (v7567 * 2) + (((int)((unsigned int)(v7466 + 28) >> 2)) & 1);
  v7568[v7721] = v7467;
  int * v7570 = v7462->cache_tags;
  int v7571 = v7570[v7640];
  int v7572 = v7570[v7641];
  bool v7724 = !(((~(((v7571 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7571 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7572 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7572 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v7626;
  if (v7724) {
    int * v7573 = v7462->cache_age;
    int v7726 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7572 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))) | (-(v7572 ^ ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7574 = v7573[v7726];
    int v7575 = v7573[v7640];
    int v7727 = v7575 + ((int)((unsigned int)(v7575 - v7574) >> 31));
    v7573[v7640] = v7727;
    int * v7577 = v7462->cache_age;
    int v7578 = v7577[v7641];
    int v7729 = v7578 + ((int)((unsigned int)(v7578 - v7574) >> 31));
    v7577[v7641] = v7729;
    int * v7580 = v7462->cache_age;
    v7580[v7726] = 0;
    v7626 = v7726;
  } else {
    int * v7583 = v7462->cache_age;
    int v7733 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2);
    int v7584 = v7583[v7733];
    int * v7585 = v7462->cache_tags;
    int v7586 = v7585[v7733];
    int v7587 = v7583[v7641];
    int v7588 = v7585[v7641];
    int * v7589 = v7462->cache_dirty;
    int v7736 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7584 + ((~(((v7586 ^ -1) | (-(v7586 ^ -1))) >> 31)) & 2)) - (v7587 + ((~(((v7588 ^ -1) | (-(v7588 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7590 = v7589[v7736];
    bool v7737 = !(v7590 == 0);
    if (v7737) {
      int * v7591 = v7462->cache_tags;
      int v7592 = v7591[v7736];
      int * v7593 = v7462->cache_vals;
      int v7740 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7584 + ((~(((v7586 ^ -1) | (-(v7586 ^ -1))) >> 31)) & 2)) - (v7587 + ((~(((v7588 ^ -1) | (-(v7588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7594 = v7593[v7740];
      int v7741 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7584 + ((~(((v7586 ^ -1) | (-(v7586 ^ -1))) >> 31)) & 2)) - (v7587 + ((~(((v7588 ^ -1) | (-(v7588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7595 = v7593[v7741];
      int * v7596 = v7462->mem;
      int v7743 = v7592 * 2;
      v7596[v7743] = v7594;
      int * v7598 = v7462->mem;
      int v7746 = (v7592 * 2) + 1;
      v7598[v7746] = v7595;
      ;
    } else {
      ;
    }
    int * v7603 = v7462->mem;
    int v7751 = ((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) * 2;
    int v7604 = v7603[v7751];
    int v7752 = (((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) * 2) + 1;
    int v7605 = v7603[v7752];
    int * v7606 = v7462->cache_vals;
    int v7754 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7584 + ((~(((v7586 ^ -1) | (-(v7586 ^ -1))) >> 31)) & 2)) - (v7587 + ((~(((v7588 ^ -1) | (-(v7588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7606[v7754] = v7604;
    int * v7608 = v7462->cache_vals;
    int v7757 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7584 + ((~(((v7586 ^ -1) | (-(v7586 ^ -1))) >> 31)) & 2)) - (v7587 + ((~(((v7588 ^ -1) | (-(v7588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7608[v7757] = v7605;
    int * v7610 = v7462->cache_tags;
    int v7760 = (int)((unsigned int)((int)((unsigned int)(v7466 + 28) >> 2)) >> 1);
    v7610[v7736] = v7760;
    int * v7612 = v7462->cache_dirty;
    v7612[v7736] = 0;
    int * v7614 = v7462->cache_age;
    v7614[v7736] = 1;
    int * v7616 = v7462->cache_age;
    int v7617 = v7616[v7736];
    int v7618 = v7616[v7640];
    int v7766 = v7618 + ((int)((unsigned int)(v7618 - v7617) >> 31));
    v7616[v7640] = v7766;
    int * v7620 = v7462->cache_age;
    int v7621 = v7620[v7641];
    int v7768 = v7621 + ((int)((unsigned int)(v7621 - v7617) >> 31));
    v7620[v7641] = v7768;
    int * v7623 = v7462->cache_age;
    v7623[v7736] = 0;
    v7626 = v7736;
  }
  int * v7627 = v7462->cache_vals;
  int v7771 = (v7626 * 2) + (((int)((unsigned int)(v7466 + 28) >> 2)) & 1);
  v7627[v7771] = v7467;
  int * v7629 = v7462->cache_dirty;
  v7629[v7626] = 1;
  struct StateT * v7631 = slot_152(v7462);
  return v7631;
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

struct StateT * slot_124(struct StateT * v6657) {
  int v6658 = v6657->timer;
  int v6666 = v6658 + 1;
  v6657->timer = v6666;
  int * v6660 = v6657->regs;
  int v6661 = v6660[6];
  int v6662 = v6660[13];
  int v6671 = (((((int)((unsigned int)v6661 >> 16)) * ((int)((unsigned int)v6662 >> 16))) + ((int)((unsigned int)((v6661 & 65535) * ((int)((unsigned int)v6662 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6661 >> 16)) * (v6662 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6661 & 65535) * (v6662 & 65535)) >> 16)) + (((v6661 & 65535) * ((int)((unsigned int)v6662 >> 16))) & 65535)) + ((((int)((unsigned int)v6661 >> 16)) * (v6662 & 65535)) & 65535)) >> 16));
  v6660[8] = v6671;
  struct StateT * v6664 = slot_125(v6657);
  return v6664;
}

struct StateT * slot_191(struct StateT * v8846) {
  int v8847 = v8846->timer;
  int v8854 = v8847 + 1;
  v8846->timer = v8854;
  int * v8849 = v8846->regs;
  int v8850 = v8849[5];
  int v8858 = v8850 << 13;
  v8849[13] = v8858;
  struct StateT * v8852 = slot_192(v8846);
  return v8852;
}

struct StateT * slot_103(struct StateT * v5326) {
  int v5327 = v5326->timer;
  int v5335 = v5327 + 1;
  v5326->timer = v5335;
  int * v5329 = v5326->regs;
  int v5330 = v5329[6];
  int v5331 = v5329[31];
  int v5339 = v5330 + v5331;
  v5329[6] = v5339;
  struct StateT * v5333 = slot_104(v5326);
  return v5333;
}

struct StateT * slot_128(struct StateT * v6724) {
  int v6725 = v6724->timer;
  int v6733 = v6725 + 1;
  v6724->timer = v6733;
  int * v6727 = v6724->regs;
  int v6728 = v6727[28];
  int v6729 = v6727[17];
  int v6738 = v6728 + v6729;
  v6727[29] = v6738;
  struct StateT * v6731 = slot_129(v6724);
  return v6731;
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

struct StateT * slot_87(struct StateT * v5021) {
  int v5022 = v5021->timer;
  int v5030 = v5022 + 1;
  v5021->timer = v5030;
  int * v5024 = v5021->regs;
  int v5025 = v5024[6];
  int v5026 = v5024[12];
  int v5034 = v5025 * v5026;
  v5024[6] = v5034;
  struct StateT * v5028 = slot_88(v5021);
  return v5028;
}

struct StateT * slot_67(struct StateT * v3718) {
  int v3719 = v3718->timer;
  int v3727 = v3719 + 1;
  v3718->timer = v3727;
  int * v3721 = v3718->regs;
  int v3722 = v3721[7];
  int v3723 = v3721[16];
  int v3732 = v3722 & v3723;
  v3721[29] = v3732;
  struct StateT * v3725 = slot_68(v3718);
  return v3725;
}

struct StateT * slot_81(struct StateT * v4919) {
  int v4920 = v4919->timer;
  int v4928 = v4920 + 1;
  v4919->timer = v4928;
  int * v4922 = v4919->regs;
  int v4923 = v4922[29];
  int v4924 = v4922[12];
  int v4933 = v4923 * v4924;
  v4922[28] = v4933;
  struct StateT * v4926 = slot_82(v4919);
  return v4926;
}

struct StateT * slot_95(struct StateT * v5178) {
  int v5179 = v5178->timer;
  int v5187 = v5179 + 1;
  v5178->timer = v5187;
  int * v5181 = v5178->regs;
  int v5182 = v5181[29];
  int v5183 = v5181[5];
  int v5192 = v5182 + v5183;
  v5181[30] = v5192;
  struct StateT * v5185 = slot_96(v5178);
  return v5185;
}

struct StateT * slot_115(struct StateT * v6135) {
  int v6136 = v6135->timer;
  int v6246 = v6136 + 1;
  v6135->timer = v6246;
  int * v6138 = v6135->regs;
  int v6139 = v6138[11];
  int * v6140 = v6135->cache_tags;
  int v6250 = (((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2;
  int v6141 = v6140[v6250];
  int v6251 = ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6142 = v6140[v6251];
  int v6252 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2);
  int v6143 = v6140[v6252];
  int v6253 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6144 = v6140[v6253];
  int v6145 = v6135->timer;
  int v6254 = v6145 + ((100 ^ (((~(((v6143 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6143 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6141 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6141 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6142 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6142 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6143 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6143 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6135->timer = v6254;
  int * v6147 = v6135->cache_vals;
  bool v6255 = !(((~(((v6141 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6141 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6142 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6142 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v6240;
  if (v6255) {
    int * v6148 = v6135->cache_age;
    int v6257 = ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v6142 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6142 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v6149 = v6148[v6257];
    int v6150 = v6148[v6250];
    int v6258 = v6150 + ((int)((unsigned int)(v6150 - v6149) >> 31));
    v6148[v6250] = v6258;
    int * v6152 = v6135->cache_age;
    int v6153 = v6152[v6251];
    int v6260 = v6153 + ((int)((unsigned int)(v6153 - v6149) >> 31));
    v6152[v6251] = v6260;
    int * v6155 = v6135->cache_age;
    v6155[v6257] = 0;
    v6240 = v6257;
  } else {
    int * v6158 = v6135->cache_age;
    int v6264 = (((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2;
    int v6159 = v6158[v6264];
    int * v6160 = v6135->cache_tags;
    int v6161 = v6160[v6264];
    int v6162 = v6158[v6251];
    int v6163 = v6160[v6251];
    bool v6266 = !(((~(((v6143 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6143 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v6217;
    if (v6266) {
      int * v6164 = v6135->cache_age;
      int v6268 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))) | (-(v6144 ^ ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v6165 = v6164[v6268];
      int v6166 = v6164[v6252];
      int v6269 = v6166 + ((int)((unsigned int)(v6166 - v6165) >> 31));
      v6164[v6252] = v6269;
      int * v6168 = v6135->cache_age;
      int v6169 = v6168[v6253];
      int v6271 = v6169 + ((int)((unsigned int)(v6169 - v6165) >> 31));
      v6168[v6253] = v6271;
      int * v6171 = v6135->cache_age;
      v6171[v6268] = 0;
      v6217 = v6268;
    } else {
      int * v6174 = v6135->cache_age;
      int v6275 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2);
      int v6175 = v6174[v6275];
      int * v6176 = v6135->cache_tags;
      int v6177 = v6176[v6275];
      int v6178 = v6174[v6253];
      int v6179 = v6176[v6253];
      int * v6180 = v6135->cache_dirty;
      int v6278 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6175 + ((~(((v6177 ^ -1) | (-(v6177 ^ -1))) >> 31)) & 2)) - (v6178 + ((~(((v6179 ^ -1) | (-(v6179 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6181 = v6180[v6278];
      bool v6279 = !(v6181 == 0);
      if (v6279) {
        int * v6182 = v6135->cache_tags;
        int v6183 = v6182[v6278];
        int * v6184 = v6135->cache_vals;
        int v6282 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6175 + ((~(((v6177 ^ -1) | (-(v6177 ^ -1))) >> 31)) & 2)) - (v6178 + ((~(((v6179 ^ -1) | (-(v6179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6185 = v6184[v6282];
        int v6283 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6175 + ((~(((v6177 ^ -1) | (-(v6177 ^ -1))) >> 31)) & 2)) - (v6178 + ((~(((v6179 ^ -1) | (-(v6179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6186 = v6184[v6283];
        int * v6187 = v6135->mem;
        int v6285 = v6183 * 2;
        v6187[v6285] = v6185;
        int * v6189 = v6135->mem;
        int v6288 = (v6183 * 2) + 1;
        v6189[v6288] = v6186;
        ;
      } else {
        ;
      }
      int * v6194 = v6135->mem;
      int v6293 = ((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) * 2;
      int v6195 = v6194[v6293];
      int v6294 = (((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) * 2) + 1;
      int v6196 = v6194[v6294];
      int * v6197 = v6135->cache_vals;
      int v6296 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6175 + ((~(((v6177 ^ -1) | (-(v6177 ^ -1))) >> 31)) & 2)) - (v6178 + ((~(((v6179 ^ -1) | (-(v6179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6197[v6296] = v6195;
      int * v6199 = v6135->cache_vals;
      int v6299 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v6175 + ((~(((v6177 ^ -1) | (-(v6177 ^ -1))) >> 31)) & 2)) - (v6178 + ((~(((v6179 ^ -1) | (-(v6179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6199[v6299] = v6196;
      int * v6201 = v6135->cache_tags;
      int v6302 = (int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1);
      v6201[v6278] = v6302;
      int * v6203 = v6135->cache_dirty;
      v6203[v6278] = 0;
      int * v6205 = v6135->cache_age;
      v6205[v6278] = 1;
      int * v6207 = v6135->cache_age;
      int v6208 = v6207[v6278];
      int v6209 = v6207[v6252];
      int v6308 = v6209 + ((int)((unsigned int)(v6209 - v6208) >> 31));
      v6207[v6252] = v6308;
      int * v6211 = v6135->cache_age;
      int v6212 = v6211[v6253];
      int v6310 = v6212 + ((int)((unsigned int)(v6212 - v6208) >> 31));
      v6211[v6253] = v6310;
      int * v6214 = v6135->cache_age;
      v6214[v6278] = 0;
      v6217 = v6278;
    }
    int * v6218 = v6135->cache_vals;
    int v6313 = v6217 * 2;
    int v6219 = v6218[v6313];
    int v6314 = (v6217 * 2) + 1;
    int v6220 = v6218[v6314];
    int v6315 = (((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v6159 + ((~(((v6161 ^ -1) | (-(v6161 ^ -1))) >> 31)) & 2)) - (v6162 + ((~(((v6163 ^ -1) | (-(v6163 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6218[v6315] = v6219;
    int * v6222 = v6135->cache_vals;
    int v6318 = ((((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v6159 + ((~(((v6161 ^ -1) | (-(v6161 ^ -1))) >> 31)) & 2)) - (v6162 + ((~(((v6163 ^ -1) | (-(v6163 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6222[v6318] = v6220;
    int * v6224 = v6135->cache_tags;
    int v6321 = ((((int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v6159 + ((~(((v6161 ^ -1) | (-(v6161 ^ -1))) >> 31)) & 2)) - (v6162 + ((~(((v6163 ^ -1) | (-(v6163 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6322 = (int)((unsigned int)((int)((unsigned int)(v6139 + 24) >> 2)) >> 1);
    v6224[v6321] = v6322;
    int * v6226 = v6135->cache_dirty;
    v6226[v6321] = 0;
    int * v6228 = v6135->cache_age;
    v6228[v6321] = 1;
    int * v6230 = v6135->cache_age;
    int v6231 = v6230[v6321];
    int v6232 = v6230[v6250];
    int v6328 = v6232 + ((int)((unsigned int)(v6232 - v6231) >> 31));
    v6230[v6250] = v6328;
    int * v6234 = v6135->cache_age;
    int v6235 = v6234[v6251];
    int v6330 = v6235 + ((int)((unsigned int)(v6235 - v6231) >> 31));
    v6234[v6251] = v6330;
    int * v6237 = v6135->cache_age;
    v6237[v6321] = 0;
    v6240 = v6321;
  }
  int v6333 = (v6240 * 2) + (((int)((unsigned int)(v6139 + 24) >> 2)) & 1);
  int v6241 = v6147[v6333];
  int * v6242 = v6135->regs;
  v6242[6] = v6241;
  struct StateT * v6244 = slot_116(v6135);
  return v6244;
}

struct StateT * slot_78(struct StateT * v4872) {
  int v4873 = v4872->timer;
  int v4880 = v4873 + 1;
  v4872->timer = v4880;
  int * v4875 = v4872->regs;
  int v4876 = v4875[5];
  int v4883 = v4876 << 13;
  v4875[5] = v4883;
  struct StateT * v4878 = slot_79(v4872);
  return v4878;
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

struct StateT * slot_205(struct StateT * v9071) {
  int v9072 = v9071->timer;
  int v9242 = v9072 + 1;
  v9071->timer = v9242;
  int * v9074 = v9071->regs;
  int v9075 = v9074[10];
  int v9076 = v9074[13];
  int * v9077 = v9071->cache_tags;
  int v9247 = (((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2;
  int v9078 = v9077[v9247];
  int v9248 = ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9079 = v9077[v9248];
  int v9249 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2);
  int v9080 = v9077[v9249];
  int v9250 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9081 = v9077[v9250];
  int v9082 = v9071->timer;
  int v9251 = v9082 + ((100 ^ (((~(((v9080 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9080 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) | (~(((v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9078 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9078 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) | (~(((v9079 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9079 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9080 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9080 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) | (~(((v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31))) & 104)))));
  v9071->timer = v9251;
  bool v9252 = !(((~(((v9078 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9078 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) | (~(((v9079 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9079 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31))) == 0);
  int v9176;
  if (v9252) {
    int * v9084 = v9071->cache_age;
    int v9254 = ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2) + ((~(((v9079 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9079 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) & 1);
    int v9085 = v9084[v9254];
    int v9086 = v9084[v9247];
    int v9255 = v9086 + ((int)((unsigned int)(v9086 - v9085) >> 31));
    v9084[v9247] = v9255;
    int * v9088 = v9071->cache_age;
    int v9089 = v9088[v9248];
    int v9257 = v9089 + ((int)((unsigned int)(v9089 - v9085) >> 31));
    v9088[v9248] = v9257;
    int * v9091 = v9071->cache_age;
    v9091[v9254] = 0;
    v9176 = v9254;
  } else {
    int * v9094 = v9071->cache_age;
    int v9261 = (((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2;
    int v9095 = v9094[v9261];
    int * v9096 = v9071->cache_tags;
    int v9097 = v9096[v9261];
    int v9098 = v9094[v9248];
    int v9099 = v9096[v9248];
    bool v9263 = !(((~(((v9080 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9080 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) | (~(((v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31))) == 0);
    int v9153;
    if (v9263) {
      int * v9100 = v9071->cache_age;
      int v9265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9081 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) & 1);
      int v9101 = v9100[v9265];
      int v9102 = v9100[v9249];
      int v9266 = v9102 + ((int)((unsigned int)(v9102 - v9101) >> 31));
      v9100[v9249] = v9266;
      int * v9104 = v9071->cache_age;
      int v9105 = v9104[v9250];
      int v9268 = v9105 + ((int)((unsigned int)(v9105 - v9101) >> 31));
      v9104[v9250] = v9268;
      int * v9107 = v9071->cache_age;
      v9107[v9265] = 0;
      v9153 = v9265;
    } else {
      int * v9110 = v9071->cache_age;
      int v9272 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2);
      int v9111 = v9110[v9272];
      int * v9112 = v9071->cache_tags;
      int v9113 = v9112[v9272];
      int v9114 = v9110[v9250];
      int v9115 = v9112[v9250];
      int * v9116 = v9071->cache_dirty;
      int v9275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9111 + ((~(((v9113 ^ -1) | (-(v9113 ^ -1))) >> 31)) & 2)) - (v9114 + ((~(((v9115 ^ -1) | (-(v9115 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9117 = v9116[v9275];
      bool v9276 = !(v9117 == 0);
      if (v9276) {
        int * v9118 = v9071->cache_tags;
        int v9119 = v9118[v9275];
        int * v9120 = v9071->cache_vals;
        int v9279 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9111 + ((~(((v9113 ^ -1) | (-(v9113 ^ -1))) >> 31)) & 2)) - (v9114 + ((~(((v9115 ^ -1) | (-(v9115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9121 = v9120[v9279];
        int v9280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9111 + ((~(((v9113 ^ -1) | (-(v9113 ^ -1))) >> 31)) & 2)) - (v9114 + ((~(((v9115 ^ -1) | (-(v9115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9122 = v9120[v9280];
        int * v9123 = v9071->mem;
        int v9282 = v9119 * 2;
        v9123[v9282] = v9121;
        int * v9125 = v9071->mem;
        int v9285 = (v9119 * 2) + 1;
        v9125[v9285] = v9122;
        ;
      } else {
        ;
      }
      int * v9130 = v9071->mem;
      int v9290 = ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) * 2;
      int v9131 = v9130[v9290];
      int v9291 = (((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) * 2) + 1;
      int v9132 = v9130[v9291];
      int * v9133 = v9071->cache_vals;
      int v9293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9111 + ((~(((v9113 ^ -1) | (-(v9113 ^ -1))) >> 31)) & 2)) - (v9114 + ((~(((v9115 ^ -1) | (-(v9115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9133[v9293] = v9131;
      int * v9135 = v9071->cache_vals;
      int v9296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9111 + ((~(((v9113 ^ -1) | (-(v9113 ^ -1))) >> 31)) & 2)) - (v9114 + ((~(((v9115 ^ -1) | (-(v9115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9135[v9296] = v9132;
      int * v9137 = v9071->cache_tags;
      int v9299 = (int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1);
      v9137[v9275] = v9299;
      int * v9139 = v9071->cache_dirty;
      v9139[v9275] = 0;
      int * v9141 = v9071->cache_age;
      v9141[v9275] = 1;
      int * v9143 = v9071->cache_age;
      int v9144 = v9143[v9275];
      int v9145 = v9143[v9249];
      int v9305 = v9145 + ((int)((unsigned int)(v9145 - v9144) >> 31));
      v9143[v9249] = v9305;
      int * v9147 = v9071->cache_age;
      int v9148 = v9147[v9250];
      int v9307 = v9148 + ((int)((unsigned int)(v9148 - v9144) >> 31));
      v9147[v9250] = v9307;
      int * v9150 = v9071->cache_age;
      v9150[v9275] = 0;
      v9153 = v9275;
    }
    int * v9154 = v9071->cache_vals;
    int v9310 = v9153 * 2;
    int v9155 = v9154[v9310];
    int v9311 = (v9153 * 2) + 1;
    int v9156 = v9154[v9311];
    int v9312 = (((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2) + ((((v9095 + ((~(((v9097 ^ -1) | (-(v9097 ^ -1))) >> 31)) & 2)) - (v9098 + ((~(((v9099 ^ -1) | (-(v9099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9154[v9312] = v9155;
    int * v9158 = v9071->cache_vals;
    int v9315 = ((((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2) + ((((v9095 + ((~(((v9097 ^ -1) | (-(v9097 ^ -1))) >> 31)) & 2)) - (v9098 + ((~(((v9099 ^ -1) | (-(v9099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9158[v9315] = v9156;
    int * v9160 = v9071->cache_tags;
    int v9318 = ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 1) * 2) + ((((v9095 + ((~(((v9097 ^ -1) | (-(v9097 ^ -1))) >> 31)) & 2)) - (v9098 + ((~(((v9099 ^ -1) | (-(v9099 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9319 = (int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1);
    v9160[v9318] = v9319;
    int * v9162 = v9071->cache_dirty;
    v9162[v9318] = 0;
    int * v9164 = v9071->cache_age;
    v9164[v9318] = 1;
    int * v9166 = v9071->cache_age;
    int v9167 = v9166[v9318];
    int v9168 = v9166[v9247];
    int v9325 = v9168 + ((int)((unsigned int)(v9168 - v9167) >> 31));
    v9166[v9247] = v9325;
    int * v9170 = v9071->cache_age;
    int v9171 = v9170[v9248];
    int v9327 = v9171 + ((int)((unsigned int)(v9171 - v9167) >> 31));
    v9170[v9248] = v9327;
    int * v9173 = v9071->cache_age;
    v9173[v9318] = 0;
    v9176 = v9318;
  }
  int * v9177 = v9071->cache_vals;
  int v9330 = (v9176 * 2) + (((int)((unsigned int)v9075 >> 2)) & 1);
  v9177[v9330] = v9076;
  int * v9179 = v9071->cache_tags;
  int v9180 = v9179[v9249];
  int v9181 = v9179[v9250];
  bool v9333 = !(((~(((v9180 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9180 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) | (~(((v9181 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9181 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31))) == 0);
  int v9235;
  if (v9333) {
    int * v9182 = v9071->cache_age;
    int v9335 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9181 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))) | (-(v9181 ^ ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1))))) >> 31)) & 1);
    int v9183 = v9182[v9335];
    int v9184 = v9182[v9249];
    int v9336 = v9184 + ((int)((unsigned int)(v9184 - v9183) >> 31));
    v9182[v9249] = v9336;
    int * v9186 = v9071->cache_age;
    int v9187 = v9186[v9250];
    int v9338 = v9187 + ((int)((unsigned int)(v9187 - v9183) >> 31));
    v9186[v9250] = v9338;
    int * v9189 = v9071->cache_age;
    v9189[v9335] = 0;
    v9235 = v9335;
  } else {
    int * v9192 = v9071->cache_age;
    int v9342 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2);
    int v9193 = v9192[v9342];
    int * v9194 = v9071->cache_tags;
    int v9195 = v9194[v9342];
    int v9196 = v9192[v9250];
    int v9197 = v9194[v9250];
    int * v9198 = v9071->cache_dirty;
    int v9345 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9193 + ((~(((v9195 ^ -1) | (-(v9195 ^ -1))) >> 31)) & 2)) - (v9196 + ((~(((v9197 ^ -1) | (-(v9197 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9199 = v9198[v9345];
    bool v9346 = !(v9199 == 0);
    if (v9346) {
      int * v9200 = v9071->cache_tags;
      int v9201 = v9200[v9345];
      int * v9202 = v9071->cache_vals;
      int v9349 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9193 + ((~(((v9195 ^ -1) | (-(v9195 ^ -1))) >> 31)) & 2)) - (v9196 + ((~(((v9197 ^ -1) | (-(v9197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9203 = v9202[v9349];
      int v9350 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9193 + ((~(((v9195 ^ -1) | (-(v9195 ^ -1))) >> 31)) & 2)) - (v9196 + ((~(((v9197 ^ -1) | (-(v9197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9204 = v9202[v9350];
      int * v9205 = v9071->mem;
      int v9352 = v9201 * 2;
      v9205[v9352] = v9203;
      int * v9207 = v9071->mem;
      int v9355 = (v9201 * 2) + 1;
      v9207[v9355] = v9204;
      ;
    } else {
      ;
    }
    int * v9212 = v9071->mem;
    int v9360 = ((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) * 2;
    int v9213 = v9212[v9360];
    int v9361 = (((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) * 2) + 1;
    int v9214 = v9212[v9361];
    int * v9215 = v9071->cache_vals;
    int v9363 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9193 + ((~(((v9195 ^ -1) | (-(v9195 ^ -1))) >> 31)) & 2)) - (v9196 + ((~(((v9197 ^ -1) | (-(v9197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9215[v9363] = v9213;
    int * v9217 = v9071->cache_vals;
    int v9366 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1)) & 3) * 2)) + ((((v9193 + ((~(((v9195 ^ -1) | (-(v9195 ^ -1))) >> 31)) & 2)) - (v9196 + ((~(((v9197 ^ -1) | (-(v9197 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9217[v9366] = v9214;
    int * v9219 = v9071->cache_tags;
    int v9369 = (int)((unsigned int)((int)((unsigned int)v9075 >> 2)) >> 1);
    v9219[v9345] = v9369;
    int * v9221 = v9071->cache_dirty;
    v9221[v9345] = 0;
    int * v9223 = v9071->cache_age;
    v9223[v9345] = 1;
    int * v9225 = v9071->cache_age;
    int v9226 = v9225[v9345];
    int v9227 = v9225[v9249];
    int v9375 = v9227 + ((int)((unsigned int)(v9227 - v9226) >> 31));
    v9225[v9249] = v9375;
    int * v9229 = v9071->cache_age;
    int v9230 = v9229[v9250];
    int v9377 = v9230 + ((int)((unsigned int)(v9230 - v9226) >> 31));
    v9229[v9250] = v9377;
    int * v9232 = v9071->cache_age;
    v9232[v9345] = 0;
    v9235 = v9345;
  }
  int * v9236 = v9071->cache_vals;
  int v9380 = (v9235 * 2) + (((int)((unsigned int)v9075 >> 2)) & 1);
  v9236[v9380] = v9076;
  int * v9238 = v9071->cache_dirty;
  v9238[v9235] = 1;
  struct StateT * v9240 = slot_206(v9071);
  return v9240;
}

struct StateT * slot_193(struct StateT * v8877) {
  int v8878 = v8877->timer;
  int v8884 = v8878 + 1;
  v8877->timer = v8884;
  int * v8880 = v8877->regs;
  v8880[17] = 19;
  struct StateT * v8882 = slot_194(v8877);
  return v8882;
}

struct StateT * slot_176(struct StateT * v8566) {
  int v8567 = v8566->timer;
  int v8575 = v8567 + 1;
  v8566->timer = v8575;
  int * v8569 = v8566->regs;
  int v8570 = v8569[31];
  int v8571 = v8569[12];
  int v8579 = v8570 + v8571;
  v8569[12] = v8579;
  struct StateT * v8573 = slot_177(v8566);
  return v8573;
}

struct StateT * slot_189(struct StateT * v8806) {
  int v8807 = v8806->timer;
  int v8819 = v8807 + 1;
  v8806->timer = v8819;
  int * v8809 = v8806->regs;
  int v8810 = v8809[5];
  int v8811 = v8809[12];
  bool v8823 = (v8810 ^ -2147483648) < (v8811 ^ -2147483648);
  int v8814;
  if (v8823) {
    v8814 = 1;
  } else {
    v8814 = 0;
  }
  int * v8815 = v8806->regs;
  v8815[12] = v8814;
  struct StateT * v8817 = slot_190(v8806);
  return v8817;
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

struct StateT * slot_210(struct StateT * v10535) {
  int v10536 = v10535->timer;
  int v10646 = v10536 + 1;
  v10535->timer = v10646;
  int * v10538 = v10535->regs;
  int v10539 = v10538[2];
  int * v10540 = v10535->cache_tags;
  int v10650 = (((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2;
  int v10541 = v10540[v10650];
  int v10651 = ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10542 = v10540[v10651];
  int v10652 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2);
  int v10543 = v10540[v10652];
  int v10653 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10544 = v10540[v10653];
  int v10545 = v10535->timer;
  int v10654 = v10545 + ((100 ^ (((~(((v10543 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10543 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10541 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10541 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v10542 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10542 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10543 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10543 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10535->timer = v10654;
  int * v10547 = v10535->cache_vals;
  bool v10655 = !(((~(((v10541 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10541 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v10542 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10542 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v10640;
  if (v10655) {
    int * v10548 = v10535->cache_age;
    int v10657 = ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v10542 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10542 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v10549 = v10548[v10657];
    int v10550 = v10548[v10650];
    int v10658 = v10550 + ((int)((unsigned int)(v10550 - v10549) >> 31));
    v10548[v10650] = v10658;
    int * v10552 = v10535->cache_age;
    int v10553 = v10552[v10651];
    int v10660 = v10553 + ((int)((unsigned int)(v10553 - v10549) >> 31));
    v10552[v10651] = v10660;
    int * v10555 = v10535->cache_age;
    v10555[v10657] = 0;
    v10640 = v10657;
  } else {
    int * v10558 = v10535->cache_age;
    int v10664 = (((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2;
    int v10559 = v10558[v10664];
    int * v10560 = v10535->cache_tags;
    int v10561 = v10560[v10664];
    int v10562 = v10558[v10651];
    int v10563 = v10560[v10651];
    bool v10666 = !(((~(((v10543 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10543 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v10617;
    if (v10666) {
      int * v10564 = v10535->cache_age;
      int v10668 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))) | (-(v10544 ^ ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v10565 = v10564[v10668];
      int v10566 = v10564[v10652];
      int v10669 = v10566 + ((int)((unsigned int)(v10566 - v10565) >> 31));
      v10564[v10652] = v10669;
      int * v10568 = v10535->cache_age;
      int v10569 = v10568[v10653];
      int v10671 = v10569 + ((int)((unsigned int)(v10569 - v10565) >> 31));
      v10568[v10653] = v10671;
      int * v10571 = v10535->cache_age;
      v10571[v10668] = 0;
      v10617 = v10668;
    } else {
      int * v10574 = v10535->cache_age;
      int v10675 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2);
      int v10575 = v10574[v10675];
      int * v10576 = v10535->cache_tags;
      int v10577 = v10576[v10675];
      int v10578 = v10574[v10653];
      int v10579 = v10576[v10653];
      int * v10580 = v10535->cache_dirty;
      int v10678 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v10575 + ((~(((v10577 ^ -1) | (-(v10577 ^ -1))) >> 31)) & 2)) - (v10578 + ((~(((v10579 ^ -1) | (-(v10579 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10581 = v10580[v10678];
      bool v10679 = !(v10581 == 0);
      if (v10679) {
        int * v10582 = v10535->cache_tags;
        int v10583 = v10582[v10678];
        int * v10584 = v10535->cache_vals;
        int v10682 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v10575 + ((~(((v10577 ^ -1) | (-(v10577 ^ -1))) >> 31)) & 2)) - (v10578 + ((~(((v10579 ^ -1) | (-(v10579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10585 = v10584[v10682];
        int v10683 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v10575 + ((~(((v10577 ^ -1) | (-(v10577 ^ -1))) >> 31)) & 2)) - (v10578 + ((~(((v10579 ^ -1) | (-(v10579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10586 = v10584[v10683];
        int * v10587 = v10535->mem;
        int v10685 = v10583 * 2;
        v10587[v10685] = v10585;
        int * v10589 = v10535->mem;
        int v10688 = (v10583 * 2) + 1;
        v10589[v10688] = v10586;
        ;
      } else {
        ;
      }
      int * v10594 = v10535->mem;
      int v10693 = ((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) * 2;
      int v10595 = v10594[v10693];
      int v10694 = (((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) * 2) + 1;
      int v10596 = v10594[v10694];
      int * v10597 = v10535->cache_vals;
      int v10696 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v10575 + ((~(((v10577 ^ -1) | (-(v10577 ^ -1))) >> 31)) & 2)) - (v10578 + ((~(((v10579 ^ -1) | (-(v10579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10597[v10696] = v10595;
      int * v10599 = v10535->cache_vals;
      int v10699 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v10575 + ((~(((v10577 ^ -1) | (-(v10577 ^ -1))) >> 31)) & 2)) - (v10578 + ((~(((v10579 ^ -1) | (-(v10579 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10599[v10699] = v10596;
      int * v10601 = v10535->cache_tags;
      int v10702 = (int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1);
      v10601[v10678] = v10702;
      int * v10603 = v10535->cache_dirty;
      v10603[v10678] = 0;
      int * v10605 = v10535->cache_age;
      v10605[v10678] = 1;
      int * v10607 = v10535->cache_age;
      int v10608 = v10607[v10678];
      int v10609 = v10607[v10652];
      int v10708 = v10609 + ((int)((unsigned int)(v10609 - v10608) >> 31));
      v10607[v10652] = v10708;
      int * v10611 = v10535->cache_age;
      int v10612 = v10611[v10653];
      int v10710 = v10612 + ((int)((unsigned int)(v10612 - v10608) >> 31));
      v10611[v10653] = v10710;
      int * v10614 = v10535->cache_age;
      v10614[v10678] = 0;
      v10617 = v10678;
    }
    int * v10618 = v10535->cache_vals;
    int v10713 = v10617 * 2;
    int v10619 = v10618[v10713];
    int v10714 = (v10617 * 2) + 1;
    int v10620 = v10618[v10714];
    int v10715 = (((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v10559 + ((~(((v10561 ^ -1) | (-(v10561 ^ -1))) >> 31)) & 2)) - (v10562 + ((~(((v10563 ^ -1) | (-(v10563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10618[v10715] = v10619;
    int * v10622 = v10535->cache_vals;
    int v10718 = ((((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v10559 + ((~(((v10561 ^ -1) | (-(v10561 ^ -1))) >> 31)) & 2)) - (v10562 + ((~(((v10563 ^ -1) | (-(v10563 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10622[v10718] = v10620;
    int * v10624 = v10535->cache_tags;
    int v10721 = ((((int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v10559 + ((~(((v10561 ^ -1) | (-(v10561 ^ -1))) >> 31)) & 2)) - (v10562 + ((~(((v10563 ^ -1) | (-(v10563 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10722 = (int)((unsigned int)((int)((unsigned int)(v10539 + 8) >> 2)) >> 1);
    v10624[v10721] = v10722;
    int * v10626 = v10535->cache_dirty;
    v10626[v10721] = 0;
    int * v10628 = v10535->cache_age;
    v10628[v10721] = 1;
    int * v10630 = v10535->cache_age;
    int v10631 = v10630[v10721];
    int v10632 = v10630[v10650];
    int v10728 = v10632 + ((int)((unsigned int)(v10632 - v10631) >> 31));
    v10630[v10650] = v10728;
    int * v10634 = v10535->cache_age;
    int v10635 = v10634[v10651];
    int v10730 = v10635 + ((int)((unsigned int)(v10635 - v10631) >> 31));
    v10634[v10651] = v10730;
    int * v10637 = v10535->cache_age;
    v10637[v10721] = 0;
    v10640 = v10721;
  }
  int v10733 = (v10640 * 2) + (((int)((unsigned int)(v10539 + 8) >> 2)) & 1);
  int v10641 = v10547[v10733];
  int * v10642 = v10535->regs;
  v10642[9] = v10641;
  struct StateT * v10644 = slot_211(v10535);
  return v10644;
}

struct StateT * slot_166(struct StateT * v8377) {
  int v8378 = v8377->timer;
  int v8386 = v8378 + 1;
  v8377->timer = v8386;
  int * v8380 = v8377->regs;
  int v8381 = v8380[11];
  int v8382 = v8380[13];
  int v8390 = (((((int)((unsigned int)v8381 >> 16)) * ((int)((unsigned int)v8382 >> 16))) + ((int)((unsigned int)((v8381 & 65535) * ((int)((unsigned int)v8382 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v8381 >> 16)) * (v8382 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v8381 & 65535) * (v8382 & 65535)) >> 16)) + (((v8381 & 65535) * ((int)((unsigned int)v8382 >> 16))) & 65535)) + ((((int)((unsigned int)v8381 >> 16)) * (v8382 & 65535)) & 65535)) >> 16));
  v8380[13] = v8390;
  struct StateT * v8384 = slot_167(v8377);
  return v8384;
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

struct StateT * slot_83(struct StateT * v4953) {
  int v4954 = v4953->timer;
  int v4962 = v4954 + 1;
  v4953->timer = v4962;
  int * v4956 = v4953->regs;
  int v4957 = v4956[6];
  int v4958 = v4956[13];
  int v4967 = v4957 * v4958;
  v4956[31] = v4967;
  struct StateT * v4960 = slot_84(v4953);
  return v4960;
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

struct StateT * slot_209(struct StateT * v10331) {
  int v10332 = v10331->timer;
  int v10442 = v10332 + 1;
  v10331->timer = v10442;
  int * v10334 = v10331->regs;
  int v10335 = v10334[2];
  int * v10336 = v10331->cache_tags;
  int v10446 = (((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2;
  int v10337 = v10336[v10446];
  int v10447 = ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10338 = v10336[v10447];
  int v10448 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2);
  int v10339 = v10336[v10448];
  int v10449 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10340 = v10336[v10449];
  int v10341 = v10331->timer;
  int v10450 = v10341 + ((100 ^ (((~(((v10339 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10339 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10337 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10337 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10338 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10338 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10339 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10339 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10331->timer = v10450;
  int * v10343 = v10331->cache_vals;
  bool v10451 = !(((~(((v10337 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10337 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10338 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10338 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v10436;
  if (v10451) {
    int * v10344 = v10331->cache_age;
    int v10453 = ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v10338 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10338 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v10345 = v10344[v10453];
    int v10346 = v10344[v10446];
    int v10454 = v10346 + ((int)((unsigned int)(v10346 - v10345) >> 31));
    v10344[v10446] = v10454;
    int * v10348 = v10331->cache_age;
    int v10349 = v10348[v10447];
    int v10456 = v10349 + ((int)((unsigned int)(v10349 - v10345) >> 31));
    v10348[v10447] = v10456;
    int * v10351 = v10331->cache_age;
    v10351[v10453] = 0;
    v10436 = v10453;
  } else {
    int * v10354 = v10331->cache_age;
    int v10460 = (((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2;
    int v10355 = v10354[v10460];
    int * v10356 = v10331->cache_tags;
    int v10357 = v10356[v10460];
    int v10358 = v10354[v10447];
    int v10359 = v10356[v10447];
    bool v10462 = !(((~(((v10339 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10339 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v10413;
    if (v10462) {
      int * v10360 = v10331->cache_age;
      int v10464 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))) | (-(v10340 ^ ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v10361 = v10360[v10464];
      int v10362 = v10360[v10448];
      int v10465 = v10362 + ((int)((unsigned int)(v10362 - v10361) >> 31));
      v10360[v10448] = v10465;
      int * v10364 = v10331->cache_age;
      int v10365 = v10364[v10449];
      int v10467 = v10365 + ((int)((unsigned int)(v10365 - v10361) >> 31));
      v10364[v10449] = v10467;
      int * v10367 = v10331->cache_age;
      v10367[v10464] = 0;
      v10413 = v10464;
    } else {
      int * v10370 = v10331->cache_age;
      int v10471 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2);
      int v10371 = v10370[v10471];
      int * v10372 = v10331->cache_tags;
      int v10373 = v10372[v10471];
      int v10374 = v10370[v10449];
      int v10375 = v10372[v10449];
      int * v10376 = v10331->cache_dirty;
      int v10474 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10371 + ((~(((v10373 ^ -1) | (-(v10373 ^ -1))) >> 31)) & 2)) - (v10374 + ((~(((v10375 ^ -1) | (-(v10375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10377 = v10376[v10474];
      bool v10475 = !(v10377 == 0);
      if (v10475) {
        int * v10378 = v10331->cache_tags;
        int v10379 = v10378[v10474];
        int * v10380 = v10331->cache_vals;
        int v10478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10371 + ((~(((v10373 ^ -1) | (-(v10373 ^ -1))) >> 31)) & 2)) - (v10374 + ((~(((v10375 ^ -1) | (-(v10375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10381 = v10380[v10478];
        int v10479 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10371 + ((~(((v10373 ^ -1) | (-(v10373 ^ -1))) >> 31)) & 2)) - (v10374 + ((~(((v10375 ^ -1) | (-(v10375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10382 = v10380[v10479];
        int * v10383 = v10331->mem;
        int v10481 = v10379 * 2;
        v10383[v10481] = v10381;
        int * v10385 = v10331->mem;
        int v10484 = (v10379 * 2) + 1;
        v10385[v10484] = v10382;
        ;
      } else {
        ;
      }
      int * v10390 = v10331->mem;
      int v10489 = ((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) * 2;
      int v10391 = v10390[v10489];
      int v10490 = (((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) * 2) + 1;
      int v10392 = v10390[v10490];
      int * v10393 = v10331->cache_vals;
      int v10492 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10371 + ((~(((v10373 ^ -1) | (-(v10373 ^ -1))) >> 31)) & 2)) - (v10374 + ((~(((v10375 ^ -1) | (-(v10375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10393[v10492] = v10391;
      int * v10395 = v10331->cache_vals;
      int v10495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10371 + ((~(((v10373 ^ -1) | (-(v10373 ^ -1))) >> 31)) & 2)) - (v10374 + ((~(((v10375 ^ -1) | (-(v10375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10395[v10495] = v10392;
      int * v10397 = v10331->cache_tags;
      int v10498 = (int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1);
      v10397[v10474] = v10498;
      int * v10399 = v10331->cache_dirty;
      v10399[v10474] = 0;
      int * v10401 = v10331->cache_age;
      v10401[v10474] = 1;
      int * v10403 = v10331->cache_age;
      int v10404 = v10403[v10474];
      int v10405 = v10403[v10448];
      int v10504 = v10405 + ((int)((unsigned int)(v10405 - v10404) >> 31));
      v10403[v10448] = v10504;
      int * v10407 = v10331->cache_age;
      int v10408 = v10407[v10449];
      int v10506 = v10408 + ((int)((unsigned int)(v10408 - v10404) >> 31));
      v10407[v10449] = v10506;
      int * v10410 = v10331->cache_age;
      v10410[v10474] = 0;
      v10413 = v10474;
    }
    int * v10414 = v10331->cache_vals;
    int v10509 = v10413 * 2;
    int v10415 = v10414[v10509];
    int v10510 = (v10413 * 2) + 1;
    int v10416 = v10414[v10510];
    int v10511 = (((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10355 + ((~(((v10357 ^ -1) | (-(v10357 ^ -1))) >> 31)) & 2)) - (v10358 + ((~(((v10359 ^ -1) | (-(v10359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10414[v10511] = v10415;
    int * v10418 = v10331->cache_vals;
    int v10514 = ((((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10355 + ((~(((v10357 ^ -1) | (-(v10357 ^ -1))) >> 31)) & 2)) - (v10358 + ((~(((v10359 ^ -1) | (-(v10359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10418[v10514] = v10416;
    int * v10420 = v10331->cache_tags;
    int v10517 = ((((int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10355 + ((~(((v10357 ^ -1) | (-(v10357 ^ -1))) >> 31)) & 2)) - (v10358 + ((~(((v10359 ^ -1) | (-(v10359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10518 = (int)((unsigned int)((int)((unsigned int)(v10335 + 12) >> 2)) >> 1);
    v10420[v10517] = v10518;
    int * v10422 = v10331->cache_dirty;
    v10422[v10517] = 0;
    int * v10424 = v10331->cache_age;
    v10424[v10517] = 1;
    int * v10426 = v10331->cache_age;
    int v10427 = v10426[v10517];
    int v10428 = v10426[v10446];
    int v10524 = v10428 + ((int)((unsigned int)(v10428 - v10427) >> 31));
    v10426[v10446] = v10524;
    int * v10430 = v10331->cache_age;
    int v10431 = v10430[v10447];
    int v10526 = v10431 + ((int)((unsigned int)(v10431 - v10427) >> 31));
    v10430[v10447] = v10526;
    int * v10433 = v10331->cache_age;
    v10433[v10517] = 0;
    v10436 = v10517;
  }
  int v10529 = (v10436 * 2) + (((int)((unsigned int)(v10335 + 12) >> 2)) & 1);
  int v10437 = v10343[v10529];
  int * v10438 = v10331->regs;
  v10438[8] = v10437;
  struct StateT * v10440 = slot_210(v10331);
  return v10440;
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

struct StateT * slot_123(struct StateT * v6640) {
  int v6641 = v6640->timer;
  int v6649 = v6641 + 1;
  v6640->timer = v6649;
  int * v6643 = v6640->regs;
  int v6644 = v6643[6];
  int v6645 = v6643[13];
  int v6654 = v6644 * v6645;
  v6643[31] = v6654;
  struct StateT * v6647 = slot_124(v6640);
  return v6647;
}

struct StateT * slot_73(struct StateT * v4418) {
  int v4419 = v4418->timer;
  int v4426 = v4419 + 1;
  v4418->timer = v4426;
  int * v4421 = v4418->regs;
  int v4422 = v4421[28];
  int v4429 = v4422 << 13;
  v4421[28] = v4429;
  struct StateT * v4424 = slot_74(v4418);
  return v4424;
}

struct StateT * slot_198(struct StateT * v8951) {
  int v8952 = v8951->timer;
  int v8960 = v8952 + 1;
  v8951->timer = v8960;
  int * v8954 = v8951->regs;
  int v8955 = v8954[13];
  int v8956 = v8954[17];
  int v8964 = v8955 * v8956;
  v8954[13] = v8964;
  struct StateT * v8958 = slot_199(v8951);
  return v8958;
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

struct StateT * slot_187(struct StateT * v8776) {
  int v8777 = v8776->timer;
  int v8785 = v8777 + 1;
  v8776->timer = v8785;
  int * v8779 = v8776->regs;
  int v8780 = v8779[17];
  int v8781 = v8779[16];
  int v8789 = v8780 & v8781;
  v8779[16] = v8789;
  struct StateT * v8783 = slot_188(v8776);
  return v8783;
}

struct StateT * slot_97(struct StateT * v5211) {
  int v5212 = v5211->timer;
  int v5220 = v5212 + 1;
  v5211->timer = v5220;
  int * v5214 = v5211->regs;
  int v5215 = v5214[7];
  int v5216 = v5214[6];
  int v5224 = v5215 + v5216;
  v5214[6] = v5224;
  struct StateT * v5218 = slot_98(v5211);
  return v5218;
}

struct StateT * slot_182(struct StateT * v8681) {
  int v8682 = v8681->timer;
  int v8690 = v8682 + 1;
  v8681->timer = v8690;
  int * v8684 = v8681->regs;
  int v8685 = v8684[17];
  int v8686 = v8684[5];
  int v8694 = v8685 + v8686;
  v8684[17] = v8694;
  struct StateT * v8688 = slot_183(v8681);
  return v8688;
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

struct StateT * slot_178(struct StateT * v8599) {
  int v8600 = v8599->timer;
  int v8608 = v8600 + 1;
  v8599->timer = v8608;
  int * v8602 = v8599->regs;
  int v8603 = v8602[8];
  int v8604 = v8602[28];
  int v8613 = v8603 + v8604;
  v8602[12] = v8613;
  struct StateT * v8606 = slot_179(v8599);
  return v8606;
}

struct StateT * slot_106(struct StateT * v5364) {
  int v5365 = v5364->timer;
  int v5373 = v5365 + 1;
  v5364->timer = v5373;
  int * v5367 = v5364->regs;
  int v5368 = v5367[5];
  int v5369 = v5367[28];
  int v5377 = v5368 + v5369;
  v5367[28] = v5377;
  struct StateT * v5371 = slot_107(v5364);
  return v5371;
}

struct StateT * slot_98(struct StateT * v5227) {
  int v5228 = v5227->timer;
  int v5236 = v5228 + 1;
  v5227->timer = v5236;
  int * v5230 = v5227->regs;
  int v5231 = v5230[9];
  int v5232 = v5230[6];
  int v5241 = v5231 + v5232;
  v5230[5] = v5241;
  struct StateT * v5234 = slot_99(v5227);
  return v5234;
}

struct StateT * slot_159(struct StateT * v8259) {
  int v8260 = v8259->timer;
  int v8268 = v8260 + 1;
  v8259->timer = v8268;
  int * v8262 = v8259->regs;
  int v8263 = v8262[5];
  int v8264 = v8262[17];
  int v8272 = v8263 | v8264;
  v8262[17] = v8272;
  struct StateT * v8266 = slot_160(v8259);
  return v8266;
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

struct StateT * slot_212(struct StateT * v10943) {
  int v10944 = v10943->timer;
  int v11054 = v10944 + 1;
  v10943->timer = v11054;
  int * v10946 = v10943->regs;
  int v10947 = v10946[2];
  int * v10948 = v10943->cache_tags;
  int v11058 = (((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2;
  int v10949 = v10948[v11058];
  int v11059 = ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2) + 1;
  int v10950 = v10948[v11059];
  int v11060 = 4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2);
  int v10951 = v10948[v11060];
  int v11061 = (4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10952 = v10948[v11061];
  int v10953 = v10943->timer;
  int v11062 = v10953 + ((100 ^ (((~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) | (~(((v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10949 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10949 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) | (~(((v10950 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10950 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) | (~(((v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31))) & 104)))));
  v10943->timer = v11062;
  int * v10955 = v10943->cache_vals;
  bool v11063 = !(((~(((v10949 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10949 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) | (~(((v10950 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10950 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31))) == 0);
  int v11048;
  if (v11063) {
    int * v10956 = v10943->cache_age;
    int v11065 = ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2) + ((~(((v10950 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10950 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) & 1);
    int v10957 = v10956[v11065];
    int v10958 = v10956[v11058];
    int v11066 = v10958 + ((int)((unsigned int)(v10958 - v10957) >> 31));
    v10956[v11058] = v11066;
    int * v10960 = v10943->cache_age;
    int v10961 = v10960[v11059];
    int v11068 = v10961 + ((int)((unsigned int)(v10961 - v10957) >> 31));
    v10960[v11059] = v11068;
    int * v10963 = v10943->cache_age;
    v10963[v11065] = 0;
    v11048 = v11065;
  } else {
    int * v10966 = v10943->cache_age;
    int v11072 = (((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2;
    int v10967 = v10966[v11072];
    int * v10968 = v10943->cache_tags;
    int v10969 = v10968[v11072];
    int v10970 = v10966[v11059];
    int v10971 = v10968[v11059];
    bool v11074 = !(((~(((v10951 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10951 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) | (~(((v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31))) == 0);
    int v11025;
    if (v11074) {
      int * v10972 = v10943->cache_age;
      int v11076 = (4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + ((~(((v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))) | (-(v10952 ^ ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1))))) >> 31)) & 1);
      int v10973 = v10972[v11076];
      int v10974 = v10972[v11060];
      int v11077 = v10974 + ((int)((unsigned int)(v10974 - v10973) >> 31));
      v10972[v11060] = v11077;
      int * v10976 = v10943->cache_age;
      int v10977 = v10976[v11061];
      int v11079 = v10977 + ((int)((unsigned int)(v10977 - v10973) >> 31));
      v10976[v11061] = v11079;
      int * v10979 = v10943->cache_age;
      v10979[v11076] = 0;
      v11025 = v11076;
    } else {
      int * v10982 = v10943->cache_age;
      int v11083 = 4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2);
      int v10983 = v10982[v11083];
      int * v10984 = v10943->cache_tags;
      int v10985 = v10984[v11083];
      int v10986 = v10982[v11061];
      int v10987 = v10984[v11061];
      int * v10988 = v10943->cache_dirty;
      int v11086 = (4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + ((((v10983 + ((~(((v10985 ^ -1) | (-(v10985 ^ -1))) >> 31)) & 2)) - (v10986 + ((~(((v10987 ^ -1) | (-(v10987 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10989 = v10988[v11086];
      bool v11087 = !(v10989 == 0);
      if (v11087) {
        int * v10990 = v10943->cache_tags;
        int v10991 = v10990[v11086];
        int * v10992 = v10943->cache_vals;
        int v11090 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + ((((v10983 + ((~(((v10985 ^ -1) | (-(v10985 ^ -1))) >> 31)) & 2)) - (v10986 + ((~(((v10987 ^ -1) | (-(v10987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10993 = v10992[v11090];
        int v11091 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + ((((v10983 + ((~(((v10985 ^ -1) | (-(v10985 ^ -1))) >> 31)) & 2)) - (v10986 + ((~(((v10987 ^ -1) | (-(v10987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10994 = v10992[v11091];
        int * v10995 = v10943->mem;
        int v11093 = v10991 * 2;
        v10995[v11093] = v10993;
        int * v10997 = v10943->mem;
        int v11096 = (v10991 * 2) + 1;
        v10997[v11096] = v10994;
        ;
      } else {
        ;
      }
      int * v11002 = v10943->mem;
      int v11101 = ((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) * 2;
      int v11003 = v11002[v11101];
      int v11102 = (((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) * 2) + 1;
      int v11004 = v11002[v11102];
      int * v11005 = v10943->cache_vals;
      int v11104 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + ((((v10983 + ((~(((v10985 ^ -1) | (-(v10985 ^ -1))) >> 31)) & 2)) - (v10986 + ((~(((v10987 ^ -1) | (-(v10987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11005[v11104] = v11003;
      int * v11007 = v10943->cache_vals;
      int v11107 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 3) * 2)) + ((((v10983 + ((~(((v10985 ^ -1) | (-(v10985 ^ -1))) >> 31)) & 2)) - (v10986 + ((~(((v10987 ^ -1) | (-(v10987 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11007[v11107] = v11004;
      int * v11009 = v10943->cache_tags;
      int v11110 = (int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1);
      v11009[v11086] = v11110;
      int * v11011 = v10943->cache_dirty;
      v11011[v11086] = 0;
      int * v11013 = v10943->cache_age;
      v11013[v11086] = 1;
      int * v11015 = v10943->cache_age;
      int v11016 = v11015[v11086];
      int v11017 = v11015[v11060];
      int v11116 = v11017 + ((int)((unsigned int)(v11017 - v11016) >> 31));
      v11015[v11060] = v11116;
      int * v11019 = v10943->cache_age;
      int v11020 = v11019[v11061];
      int v11118 = v11020 + ((int)((unsigned int)(v11020 - v11016) >> 31));
      v11019[v11061] = v11118;
      int * v11022 = v10943->cache_age;
      v11022[v11086] = 0;
      v11025 = v11086;
    }
    int * v11026 = v10943->cache_vals;
    int v11121 = v11025 * 2;
    int v11027 = v11026[v11121];
    int v11122 = (v11025 * 2) + 1;
    int v11028 = v11026[v11122];
    int v11123 = (((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2) + ((((v10967 + ((~(((v10969 ^ -1) | (-(v10969 ^ -1))) >> 31)) & 2)) - (v10970 + ((~(((v10971 ^ -1) | (-(v10971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11026[v11123] = v11027;
    int * v11030 = v10943->cache_vals;
    int v11126 = ((((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2) + ((((v10967 + ((~(((v10969 ^ -1) | (-(v10969 ^ -1))) >> 31)) & 2)) - (v10970 + ((~(((v10971 ^ -1) | (-(v10971 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11030[v11126] = v11028;
    int * v11032 = v10943->cache_tags;
    int v11129 = ((((int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1)) & 1) * 2) + ((((v10967 + ((~(((v10969 ^ -1) | (-(v10969 ^ -1))) >> 31)) & 2)) - (v10970 + ((~(((v10971 ^ -1) | (-(v10971 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11130 = (int)((unsigned int)((int)((unsigned int)v10947 >> 2)) >> 1);
    v11032[v11129] = v11130;
    int * v11034 = v10943->cache_dirty;
    v11034[v11129] = 0;
    int * v11036 = v10943->cache_age;
    v11036[v11129] = 1;
    int * v11038 = v10943->cache_age;
    int v11039 = v11038[v11129];
    int v11040 = v11038[v11058];
    int v11136 = v11040 + ((int)((unsigned int)(v11040 - v11039) >> 31));
    v11038[v11058] = v11136;
    int * v11042 = v10943->cache_age;
    int v11043 = v11042[v11059];
    int v11138 = v11043 + ((int)((unsigned int)(v11043 - v11039) >> 31));
    v11042[v11059] = v11138;
    int * v11045 = v10943->cache_age;
    v11045[v11129] = 0;
    v11048 = v11129;
  }
  int v11141 = (v11048 * 2) + (((int)((unsigned int)v10947 >> 2)) & 1);
  int v11049 = v10955[v11141];
  int * v11050 = v10943->regs;
  v11050[19] = v11049;
  struct StateT * v11052 = slot_213(v10943);
  return v11052;
}

struct StateT * slot_132(struct StateT * v6799) {
  int v6800 = v6799->timer;
  int v6812 = v6800 + 1;
  v6799->timer = v6812;
  int * v6802 = v6799->regs;
  int v6803 = v6802[17];
  int v6804 = v6802[6];
  bool v6816 = (v6803 ^ -2147483648) < (v6804 ^ -2147483648);
  int v6807;
  if (v6816) {
    v6807 = 1;
  } else {
    v6807 = 0;
  }
  int * v6808 = v6799->regs;
  v6808[28] = v6807;
  struct StateT * v6810 = slot_133(v6799);
  return v6810;
}

struct StateT * slot_130(struct StateT * v6758) {
  int v6759 = v6758->timer;
  int v6771 = v6759 + 1;
  v6758->timer = v6771;
  int * v6761 = v6758->regs;
  int v6762 = v6761[29];
  int v6763 = v6761[28];
  bool v6775 = (v6762 ^ -2147483648) < (v6763 ^ -2147483648);
  int v6766;
  if (v6775) {
    v6766 = 1;
  } else {
    v6766 = 0;
  }
  int * v6767 = v6758->regs;
  v6767[7] = v6766;
  struct StateT * v6769 = slot_131(v6758);
  return v6769;
}

struct StateT * slot_211(struct StateT * v10739) {
  int v10740 = v10739->timer;
  int v10850 = v10740 + 1;
  v10739->timer = v10850;
  int * v10742 = v10739->regs;
  int v10743 = v10742[2];
  int * v10744 = v10739->cache_tags;
  int v10854 = (((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2;
  int v10745 = v10744[v10854];
  int v10855 = ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10746 = v10744[v10855];
  int v10856 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2);
  int v10747 = v10744[v10856];
  int v10857 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10748 = v10744[v10857];
  int v10749 = v10739->timer;
  int v10858 = v10749 + ((100 ^ (((~(((v10747 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10747 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10745 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10745 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v10746 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10746 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10747 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10747 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10739->timer = v10858;
  int * v10751 = v10739->cache_vals;
  bool v10859 = !(((~(((v10745 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10745 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v10746 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10746 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v10844;
  if (v10859) {
    int * v10752 = v10739->cache_age;
    int v10861 = ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v10746 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10746 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v10753 = v10752[v10861];
    int v10754 = v10752[v10854];
    int v10862 = v10754 + ((int)((unsigned int)(v10754 - v10753) >> 31));
    v10752[v10854] = v10862;
    int * v10756 = v10739->cache_age;
    int v10757 = v10756[v10855];
    int v10864 = v10757 + ((int)((unsigned int)(v10757 - v10753) >> 31));
    v10756[v10855] = v10864;
    int * v10759 = v10739->cache_age;
    v10759[v10861] = 0;
    v10844 = v10861;
  } else {
    int * v10762 = v10739->cache_age;
    int v10868 = (((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2;
    int v10763 = v10762[v10868];
    int * v10764 = v10739->cache_tags;
    int v10765 = v10764[v10868];
    int v10766 = v10762[v10855];
    int v10767 = v10764[v10855];
    bool v10870 = !(((~(((v10747 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10747 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v10821;
    if (v10870) {
      int * v10768 = v10739->cache_age;
      int v10872 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))) | (-(v10748 ^ ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v10769 = v10768[v10872];
      int v10770 = v10768[v10856];
      int v10873 = v10770 + ((int)((unsigned int)(v10770 - v10769) >> 31));
      v10768[v10856] = v10873;
      int * v10772 = v10739->cache_age;
      int v10773 = v10772[v10857];
      int v10875 = v10773 + ((int)((unsigned int)(v10773 - v10769) >> 31));
      v10772[v10857] = v10875;
      int * v10775 = v10739->cache_age;
      v10775[v10872] = 0;
      v10821 = v10872;
    } else {
      int * v10778 = v10739->cache_age;
      int v10879 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2);
      int v10779 = v10778[v10879];
      int * v10780 = v10739->cache_tags;
      int v10781 = v10780[v10879];
      int v10782 = v10778[v10857];
      int v10783 = v10780[v10857];
      int * v10784 = v10739->cache_dirty;
      int v10882 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10779 + ((~(((v10781 ^ -1) | (-(v10781 ^ -1))) >> 31)) & 2)) - (v10782 + ((~(((v10783 ^ -1) | (-(v10783 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10785 = v10784[v10882];
      bool v10883 = !(v10785 == 0);
      if (v10883) {
        int * v10786 = v10739->cache_tags;
        int v10787 = v10786[v10882];
        int * v10788 = v10739->cache_vals;
        int v10886 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10779 + ((~(((v10781 ^ -1) | (-(v10781 ^ -1))) >> 31)) & 2)) - (v10782 + ((~(((v10783 ^ -1) | (-(v10783 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10789 = v10788[v10886];
        int v10887 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10779 + ((~(((v10781 ^ -1) | (-(v10781 ^ -1))) >> 31)) & 2)) - (v10782 + ((~(((v10783 ^ -1) | (-(v10783 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10790 = v10788[v10887];
        int * v10791 = v10739->mem;
        int v10889 = v10787 * 2;
        v10791[v10889] = v10789;
        int * v10793 = v10739->mem;
        int v10892 = (v10787 * 2) + 1;
        v10793[v10892] = v10790;
        ;
      } else {
        ;
      }
      int * v10798 = v10739->mem;
      int v10897 = ((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) * 2;
      int v10799 = v10798[v10897];
      int v10898 = (((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) * 2) + 1;
      int v10800 = v10798[v10898];
      int * v10801 = v10739->cache_vals;
      int v10900 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10779 + ((~(((v10781 ^ -1) | (-(v10781 ^ -1))) >> 31)) & 2)) - (v10782 + ((~(((v10783 ^ -1) | (-(v10783 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10801[v10900] = v10799;
      int * v10803 = v10739->cache_vals;
      int v10903 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v10779 + ((~(((v10781 ^ -1) | (-(v10781 ^ -1))) >> 31)) & 2)) - (v10782 + ((~(((v10783 ^ -1) | (-(v10783 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10803[v10903] = v10800;
      int * v10805 = v10739->cache_tags;
      int v10906 = (int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1);
      v10805[v10882] = v10906;
      int * v10807 = v10739->cache_dirty;
      v10807[v10882] = 0;
      int * v10809 = v10739->cache_age;
      v10809[v10882] = 1;
      int * v10811 = v10739->cache_age;
      int v10812 = v10811[v10882];
      int v10813 = v10811[v10856];
      int v10912 = v10813 + ((int)((unsigned int)(v10813 - v10812) >> 31));
      v10811[v10856] = v10912;
      int * v10815 = v10739->cache_age;
      int v10816 = v10815[v10857];
      int v10914 = v10816 + ((int)((unsigned int)(v10816 - v10812) >> 31));
      v10815[v10857] = v10914;
      int * v10818 = v10739->cache_age;
      v10818[v10882] = 0;
      v10821 = v10882;
    }
    int * v10822 = v10739->cache_vals;
    int v10917 = v10821 * 2;
    int v10823 = v10822[v10917];
    int v10918 = (v10821 * 2) + 1;
    int v10824 = v10822[v10918];
    int v10919 = (((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v10763 + ((~(((v10765 ^ -1) | (-(v10765 ^ -1))) >> 31)) & 2)) - (v10766 + ((~(((v10767 ^ -1) | (-(v10767 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10822[v10919] = v10823;
    int * v10826 = v10739->cache_vals;
    int v10922 = ((((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v10763 + ((~(((v10765 ^ -1) | (-(v10765 ^ -1))) >> 31)) & 2)) - (v10766 + ((~(((v10767 ^ -1) | (-(v10767 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10826[v10922] = v10824;
    int * v10828 = v10739->cache_tags;
    int v10925 = ((((int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v10763 + ((~(((v10765 ^ -1) | (-(v10765 ^ -1))) >> 31)) & 2)) - (v10766 + ((~(((v10767 ^ -1) | (-(v10767 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10926 = (int)((unsigned int)((int)((unsigned int)(v10743 + 4) >> 2)) >> 1);
    v10828[v10925] = v10926;
    int * v10830 = v10739->cache_dirty;
    v10830[v10925] = 0;
    int * v10832 = v10739->cache_age;
    v10832[v10925] = 1;
    int * v10834 = v10739->cache_age;
    int v10835 = v10834[v10925];
    int v10836 = v10834[v10854];
    int v10932 = v10836 + ((int)((unsigned int)(v10836 - v10835) >> 31));
    v10834[v10854] = v10932;
    int * v10838 = v10739->cache_age;
    int v10839 = v10838[v10855];
    int v10934 = v10839 + ((int)((unsigned int)(v10839 - v10835) >> 31));
    v10838[v10855] = v10934;
    int * v10841 = v10739->cache_age;
    v10841[v10925] = 0;
    v10844 = v10925;
  }
  int v10937 = (v10844 * 2) + (((int)((unsigned int)(v10743 + 4) >> 2)) & 1);
  int v10845 = v10751[v10937];
  int * v10846 = v10739->regs;
  v10846[18] = v10845;
  struct StateT * v10848 = slot_212(v10739);
  return v10848;
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

struct StateT * slot_141(struct StateT * v6980) {
  int v6981 = v6980->timer;
  int v6989 = v6981 + 1;
  v6980->timer = v6989;
  int * v6983 = v6980->regs;
  int v6984 = v6983[18];
  int v6985 = v6983[6];
  int v6993 = v6984 + v6985;
  v6983[6] = v6993;
  struct StateT * v6987 = slot_142(v6980);
  return v6987;
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

struct StateT * slot_183(struct StateT * v8697) {
  int v8698 = v8697->timer;
  int v8706 = v8698 + 1;
  v8697->timer = v8706;
  int * v8700 = v8697->regs;
  int v8701 = v8700[13];
  int v8702 = v8700[28];
  int v8710 = v8701 + v8702;
  v8700[13] = v8710;
  struct StateT * v8704 = slot_184(v8697);
  return v8704;
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

struct StateT * slot_70(struct StateT * v3773) {
  int v3774 = v3773->timer;
  int v3944 = v3774 + 1;
  v3773->timer = v3944;
  int * v3776 = v3773->regs;
  int v3777 = v3776[10];
  int v3778 = v3776[17];
  int * v3779 = v3773->cache_tags;
  int v3949 = (((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3780 = v3779[v3949];
  int v3950 = ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3781 = v3779[v3950];
  int v3951 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3782 = v3779[v3951];
  int v3952 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3783 = v3779[v3952];
  int v3784 = v3773->timer;
  int v3953 = v3784 + ((100 ^ (((~(((v3782 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3782 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3780 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3780 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3781 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3781 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3782 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3782 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3773->timer = v3953;
  bool v3954 = !(((~(((v3780 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3780 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3781 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3781 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3878;
  if (v3954) {
    int * v3786 = v3773->cache_age;
    int v3956 = ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3781 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3781 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3787 = v3786[v3956];
    int v3788 = v3786[v3949];
    int v3957 = v3788 + ((int)((unsigned int)(v3788 - v3787) >> 31));
    v3786[v3949] = v3957;
    int * v3790 = v3773->cache_age;
    int v3791 = v3790[v3950];
    int v3959 = v3791 + ((int)((unsigned int)(v3791 - v3787) >> 31));
    v3790[v3950] = v3959;
    int * v3793 = v3773->cache_age;
    v3793[v3956] = 0;
    v3878 = v3956;
  } else {
    int * v3796 = v3773->cache_age;
    int v3963 = (((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3797 = v3796[v3963];
    int * v3798 = v3773->cache_tags;
    int v3799 = v3798[v3963];
    int v3800 = v3796[v3950];
    int v3801 = v3798[v3950];
    bool v3965 = !(((~(((v3782 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3782 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3855;
    if (v3965) {
      int * v3802 = v3773->cache_age;
      int v3967 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3783 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3803 = v3802[v3967];
      int v3804 = v3802[v3951];
      int v3968 = v3804 + ((int)((unsigned int)(v3804 - v3803) >> 31));
      v3802[v3951] = v3968;
      int * v3806 = v3773->cache_age;
      int v3807 = v3806[v3952];
      int v3970 = v3807 + ((int)((unsigned int)(v3807 - v3803) >> 31));
      v3806[v3952] = v3970;
      int * v3809 = v3773->cache_age;
      v3809[v3967] = 0;
      v3855 = v3967;
    } else {
      int * v3812 = v3773->cache_age;
      int v3974 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3813 = v3812[v3974];
      int * v3814 = v3773->cache_tags;
      int v3815 = v3814[v3974];
      int v3816 = v3812[v3952];
      int v3817 = v3814[v3952];
      int * v3818 = v3773->cache_dirty;
      int v3977 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3813 + ((~(((v3815 ^ -1) | (-(v3815 ^ -1))) >> 31)) & 2)) - (v3816 + ((~(((v3817 ^ -1) | (-(v3817 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3819 = v3818[v3977];
      bool v3978 = !(v3819 == 0);
      if (v3978) {
        int * v3820 = v3773->cache_tags;
        int v3821 = v3820[v3977];
        int * v3822 = v3773->cache_vals;
        int v3981 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3813 + ((~(((v3815 ^ -1) | (-(v3815 ^ -1))) >> 31)) & 2)) - (v3816 + ((~(((v3817 ^ -1) | (-(v3817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3823 = v3822[v3981];
        int v3982 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3813 + ((~(((v3815 ^ -1) | (-(v3815 ^ -1))) >> 31)) & 2)) - (v3816 + ((~(((v3817 ^ -1) | (-(v3817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3824 = v3822[v3982];
        int * v3825 = v3773->mem;
        int v3984 = v3821 * 2;
        v3825[v3984] = v3823;
        int * v3827 = v3773->mem;
        int v3987 = (v3821 * 2) + 1;
        v3827[v3987] = v3824;
        ;
      } else {
        ;
      }
      int * v3832 = v3773->mem;
      int v3992 = ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) * 2;
      int v3833 = v3832[v3992];
      int v3993 = (((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3834 = v3832[v3993];
      int * v3835 = v3773->cache_vals;
      int v3995 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3813 + ((~(((v3815 ^ -1) | (-(v3815 ^ -1))) >> 31)) & 2)) - (v3816 + ((~(((v3817 ^ -1) | (-(v3817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3835[v3995] = v3833;
      int * v3837 = v3773->cache_vals;
      int v3998 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3813 + ((~(((v3815 ^ -1) | (-(v3815 ^ -1))) >> 31)) & 2)) - (v3816 + ((~(((v3817 ^ -1) | (-(v3817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3837[v3998] = v3834;
      int * v3839 = v3773->cache_tags;
      int v4001 = (int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1);
      v3839[v3977] = v4001;
      int * v3841 = v3773->cache_dirty;
      v3841[v3977] = 0;
      int * v3843 = v3773->cache_age;
      v3843[v3977] = 1;
      int * v3845 = v3773->cache_age;
      int v3846 = v3845[v3977];
      int v3847 = v3845[v3951];
      int v4007 = v3847 + ((int)((unsigned int)(v3847 - v3846) >> 31));
      v3845[v3951] = v4007;
      int * v3849 = v3773->cache_age;
      int v3850 = v3849[v3952];
      int v4009 = v3850 + ((int)((unsigned int)(v3850 - v3846) >> 31));
      v3849[v3952] = v4009;
      int * v3852 = v3773->cache_age;
      v3852[v3977] = 0;
      v3855 = v3977;
    }
    int * v3856 = v3773->cache_vals;
    int v4012 = v3855 * 2;
    int v3857 = v3856[v4012];
    int v4013 = (v3855 * 2) + 1;
    int v3858 = v3856[v4013];
    int v4014 = (((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3797 + ((~(((v3799 ^ -1) | (-(v3799 ^ -1))) >> 31)) & 2)) - (v3800 + ((~(((v3801 ^ -1) | (-(v3801 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3856[v4014] = v3857;
    int * v3860 = v3773->cache_vals;
    int v4017 = ((((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3797 + ((~(((v3799 ^ -1) | (-(v3799 ^ -1))) >> 31)) & 2)) - (v3800 + ((~(((v3801 ^ -1) | (-(v3801 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3860[v4017] = v3858;
    int * v3862 = v3773->cache_tags;
    int v4020 = ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3797 + ((~(((v3799 ^ -1) | (-(v3799 ^ -1))) >> 31)) & 2)) - (v3800 + ((~(((v3801 ^ -1) | (-(v3801 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4021 = (int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1);
    v3862[v4020] = v4021;
    int * v3864 = v3773->cache_dirty;
    v3864[v4020] = 0;
    int * v3866 = v3773->cache_age;
    v3866[v4020] = 1;
    int * v3868 = v3773->cache_age;
    int v3869 = v3868[v4020];
    int v3870 = v3868[v3949];
    int v4027 = v3870 + ((int)((unsigned int)(v3870 - v3869) >> 31));
    v3868[v3949] = v4027;
    int * v3872 = v3773->cache_age;
    int v3873 = v3872[v3950];
    int v4029 = v3873 + ((int)((unsigned int)(v3873 - v3869) >> 31));
    v3872[v3950] = v4029;
    int * v3875 = v3773->cache_age;
    v3875[v4020] = 0;
    v3878 = v4020;
  }
  int * v3879 = v3773->cache_vals;
  int v4032 = (v3878 * 2) + (((int)((unsigned int)(v3777 + 8) >> 2)) & 1);
  v3879[v4032] = v3778;
  int * v3881 = v3773->cache_tags;
  int v3882 = v3881[v3951];
  int v3883 = v3881[v3952];
  bool v4035 = !(((~(((v3882 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3882 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3883 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3883 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3937;
  if (v4035) {
    int * v3884 = v3773->cache_age;
    int v4037 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3883 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))) | (-(v3883 ^ ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3885 = v3884[v4037];
    int v3886 = v3884[v3951];
    int v4038 = v3886 + ((int)((unsigned int)(v3886 - v3885) >> 31));
    v3884[v3951] = v4038;
    int * v3888 = v3773->cache_age;
    int v3889 = v3888[v3952];
    int v4040 = v3889 + ((int)((unsigned int)(v3889 - v3885) >> 31));
    v3888[v3952] = v4040;
    int * v3891 = v3773->cache_age;
    v3891[v4037] = 0;
    v3937 = v4037;
  } else {
    int * v3894 = v3773->cache_age;
    int v4044 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2);
    int v3895 = v3894[v4044];
    int * v3896 = v3773->cache_tags;
    int v3897 = v3896[v4044];
    int v3898 = v3894[v3952];
    int v3899 = v3896[v3952];
    int * v3900 = v3773->cache_dirty;
    int v4047 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3901 = v3900[v4047];
    bool v4048 = !(v3901 == 0);
    if (v4048) {
      int * v3902 = v3773->cache_tags;
      int v3903 = v3902[v4047];
      int * v3904 = v3773->cache_vals;
      int v4051 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3905 = v3904[v4051];
      int v4052 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3906 = v3904[v4052];
      int * v3907 = v3773->mem;
      int v4054 = v3903 * 2;
      v3907[v4054] = v3905;
      int * v3909 = v3773->mem;
      int v4057 = (v3903 * 2) + 1;
      v3909[v4057] = v3906;
      ;
    } else {
      ;
    }
    int * v3914 = v3773->mem;
    int v4062 = ((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) * 2;
    int v3915 = v3914[v4062];
    int v4063 = (((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) * 2) + 1;
    int v3916 = v3914[v4063];
    int * v3917 = v3773->cache_vals;
    int v4065 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3917[v4065] = v3915;
    int * v3919 = v3773->cache_vals;
    int v4068 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3895 + ((~(((v3897 ^ -1) | (-(v3897 ^ -1))) >> 31)) & 2)) - (v3898 + ((~(((v3899 ^ -1) | (-(v3899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3919[v4068] = v3916;
    int * v3921 = v3773->cache_tags;
    int v4071 = (int)((unsigned int)((int)((unsigned int)(v3777 + 8) >> 2)) >> 1);
    v3921[v4047] = v4071;
    int * v3923 = v3773->cache_dirty;
    v3923[v4047] = 0;
    int * v3925 = v3773->cache_age;
    v3925[v4047] = 1;
    int * v3927 = v3773->cache_age;
    int v3928 = v3927[v4047];
    int v3929 = v3927[v3951];
    int v4077 = v3929 + ((int)((unsigned int)(v3929 - v3928) >> 31));
    v3927[v3951] = v4077;
    int * v3931 = v3773->cache_age;
    int v3932 = v3931[v3952];
    int v4079 = v3932 + ((int)((unsigned int)(v3932 - v3928) >> 31));
    v3931[v3952] = v4079;
    int * v3934 = v3773->cache_age;
    v3934[v4047] = 0;
    v3937 = v4047;
  }
  int * v3938 = v3773->cache_vals;
  int v4082 = (v3937 * 2) + (((int)((unsigned int)(v3777 + 8) >> 2)) & 1);
  v3938[v4082] = v3778;
  int * v3940 = v3773->cache_dirty;
  v3940[v3937] = 1;
  struct StateT * v3942 = slot_71(v3773);
  return v3942;
}

struct StateT * slot_168(struct StateT * v8409) {
  int v8410 = v8409->timer;
  int v8418 = v8410 + 1;
  v8409->timer = v8418;
  int * v8412 = v8409->regs;
  int v8413 = v8412[28];
  int v8414 = v8412[5];
  int v8422 = v8413 + v8414;
  v8412[5] = v8422;
  struct StateT * v8416 = slot_169(v8409);
  return v8416;
}

struct StateT * slot_76(struct StateT * v4652) {
  int v4653 = v4652->timer;
  int v4763 = v4653 + 1;
  v4652->timer = v4763;
  int * v4655 = v4652->regs;
  int v4656 = v4655[11];
  int * v4657 = v4652->cache_tags;
  int v4767 = (((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2;
  int v4658 = v4657[v4767];
  int v4768 = ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4659 = v4657[v4768];
  int v4769 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2);
  int v4660 = v4657[v4769];
  int v4770 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4661 = v4657[v4770];
  int v4662 = v4652->timer;
  int v4771 = v4662 + ((100 ^ (((~(((v4660 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4660 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4659 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4659 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4660 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4660 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4652->timer = v4771;
  int * v4664 = v4652->cache_vals;
  bool v4772 = !(((~(((v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4659 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4659 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v4757;
  if (v4772) {
    int * v4665 = v4652->cache_age;
    int v4774 = ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v4659 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4659 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v4666 = v4665[v4774];
    int v4667 = v4665[v4767];
    int v4775 = v4667 + ((int)((unsigned int)(v4667 - v4666) >> 31));
    v4665[v4767] = v4775;
    int * v4669 = v4652->cache_age;
    int v4670 = v4669[v4768];
    int v4777 = v4670 + ((int)((unsigned int)(v4670 - v4666) >> 31));
    v4669[v4768] = v4777;
    int * v4672 = v4652->cache_age;
    v4672[v4774] = 0;
    v4757 = v4774;
  } else {
    int * v4675 = v4652->cache_age;
    int v4781 = (((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2;
    int v4676 = v4675[v4781];
    int * v4677 = v4652->cache_tags;
    int v4678 = v4677[v4781];
    int v4679 = v4675[v4768];
    int v4680 = v4677[v4768];
    bool v4783 = !(((~(((v4660 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4660 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v4734;
    if (v4783) {
      int * v4681 = v4652->cache_age;
      int v4785 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))) | (-(v4661 ^ ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v4682 = v4681[v4785];
      int v4683 = v4681[v4769];
      int v4786 = v4683 + ((int)((unsigned int)(v4683 - v4682) >> 31));
      v4681[v4769] = v4786;
      int * v4685 = v4652->cache_age;
      int v4686 = v4685[v4770];
      int v4788 = v4686 + ((int)((unsigned int)(v4686 - v4682) >> 31));
      v4685[v4770] = v4788;
      int * v4688 = v4652->cache_age;
      v4688[v4785] = 0;
      v4734 = v4785;
    } else {
      int * v4691 = v4652->cache_age;
      int v4792 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2);
      int v4692 = v4691[v4792];
      int * v4693 = v4652->cache_tags;
      int v4694 = v4693[v4792];
      int v4695 = v4691[v4770];
      int v4696 = v4693[v4770];
      int * v4697 = v4652->cache_dirty;
      int v4795 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4692 + ((~(((v4694 ^ -1) | (-(v4694 ^ -1))) >> 31)) & 2)) - (v4695 + ((~(((v4696 ^ -1) | (-(v4696 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4698 = v4697[v4795];
      bool v4796 = !(v4698 == 0);
      if (v4796) {
        int * v4699 = v4652->cache_tags;
        int v4700 = v4699[v4795];
        int * v4701 = v4652->cache_vals;
        int v4799 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4692 + ((~(((v4694 ^ -1) | (-(v4694 ^ -1))) >> 31)) & 2)) - (v4695 + ((~(((v4696 ^ -1) | (-(v4696 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4702 = v4701[v4799];
        int v4800 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4692 + ((~(((v4694 ^ -1) | (-(v4694 ^ -1))) >> 31)) & 2)) - (v4695 + ((~(((v4696 ^ -1) | (-(v4696 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4703 = v4701[v4800];
        int * v4704 = v4652->mem;
        int v4802 = v4700 * 2;
        v4704[v4802] = v4702;
        int * v4706 = v4652->mem;
        int v4805 = (v4700 * 2) + 1;
        v4706[v4805] = v4703;
        ;
      } else {
        ;
      }
      int * v4711 = v4652->mem;
      int v4810 = ((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) * 2;
      int v4712 = v4711[v4810];
      int v4811 = (((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) * 2) + 1;
      int v4713 = v4711[v4811];
      int * v4714 = v4652->cache_vals;
      int v4813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4692 + ((~(((v4694 ^ -1) | (-(v4694 ^ -1))) >> 31)) & 2)) - (v4695 + ((~(((v4696 ^ -1) | (-(v4696 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4714[v4813] = v4712;
      int * v4716 = v4652->cache_vals;
      int v4816 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4692 + ((~(((v4694 ^ -1) | (-(v4694 ^ -1))) >> 31)) & 2)) - (v4695 + ((~(((v4696 ^ -1) | (-(v4696 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4716[v4816] = v4713;
      int * v4718 = v4652->cache_tags;
      int v4819 = (int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1);
      v4718[v4795] = v4819;
      int * v4720 = v4652->cache_dirty;
      v4720[v4795] = 0;
      int * v4722 = v4652->cache_age;
      v4722[v4795] = 1;
      int * v4724 = v4652->cache_age;
      int v4725 = v4724[v4795];
      int v4726 = v4724[v4769];
      int v4825 = v4726 + ((int)((unsigned int)(v4726 - v4725) >> 31));
      v4724[v4769] = v4825;
      int * v4728 = v4652->cache_age;
      int v4729 = v4728[v4770];
      int v4827 = v4729 + ((int)((unsigned int)(v4729 - v4725) >> 31));
      v4728[v4770] = v4827;
      int * v4731 = v4652->cache_age;
      v4731[v4795] = 0;
      v4734 = v4795;
    }
    int * v4735 = v4652->cache_vals;
    int v4830 = v4734 * 2;
    int v4736 = v4735[v4830];
    int v4831 = (v4734 * 2) + 1;
    int v4737 = v4735[v4831];
    int v4832 = (((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4676 + ((~(((v4678 ^ -1) | (-(v4678 ^ -1))) >> 31)) & 2)) - (v4679 + ((~(((v4680 ^ -1) | (-(v4680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4735[v4832] = v4736;
    int * v4739 = v4652->cache_vals;
    int v4835 = ((((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4676 + ((~(((v4678 ^ -1) | (-(v4678 ^ -1))) >> 31)) & 2)) - (v4679 + ((~(((v4680 ^ -1) | (-(v4680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4739[v4835] = v4737;
    int * v4741 = v4652->cache_tags;
    int v4838 = ((((int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4676 + ((~(((v4678 ^ -1) | (-(v4678 ^ -1))) >> 31)) & 2)) - (v4679 + ((~(((v4680 ^ -1) | (-(v4680 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4839 = (int)((unsigned int)((int)((unsigned int)(v4656 + 20) >> 2)) >> 1);
    v4741[v4838] = v4839;
    int * v4743 = v4652->cache_dirty;
    v4743[v4838] = 0;
    int * v4745 = v4652->cache_age;
    v4745[v4838] = 1;
    int * v4747 = v4652->cache_age;
    int v4748 = v4747[v4838];
    int v4749 = v4747[v4767];
    int v4845 = v4749 + ((int)((unsigned int)(v4749 - v4748) >> 31));
    v4747[v4767] = v4845;
    int * v4751 = v4652->cache_age;
    int v4752 = v4751[v4768];
    int v4847 = v4752 + ((int)((unsigned int)(v4752 - v4748) >> 31));
    v4751[v4768] = v4847;
    int * v4754 = v4652->cache_age;
    v4754[v4838] = 0;
    v4757 = v4838;
  }
  int v4850 = (v4757 * 2) + (((int)((unsigned int)(v4656 + 20) >> 2)) & 1);
  int v4758 = v4664[v4850];
  int * v4759 = v4652->regs;
  v4759[29] = v4758;
  struct StateT * v4761 = slot_77(v4652);
  return v4761;
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

struct StateT * slot_213(struct StateT * v11147) {
  int v11148 = v11147->timer;
  int v11155 = v11148 + 1;
  v11147->timer = v11155;
  int * v11150 = v11147->regs;
  int v11151 = v11150[2];
  int v11158 = v11151 + 16;
  v11150[2] = v11158;
  struct StateT * v11153 = slot_214(v11147);
  return v11153;
}

struct StateT * slot_82(struct StateT * v4936) {
  int v4937 = v4936->timer;
  int v4945 = v4937 + 1;
  v4936->timer = v4945;
  int * v4939 = v4936->regs;
  int v4940 = v4939[29];
  int v4941 = v4939[12];
  int v4950 = (((((int)((unsigned int)v4940 >> 16)) * ((int)((unsigned int)v4941 >> 16))) + ((int)((unsigned int)((v4940 & 65535) * ((int)((unsigned int)v4941 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4940 >> 16)) * (v4941 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4940 & 65535) * (v4941 & 65535)) >> 16)) + (((v4940 & 65535) * ((int)((unsigned int)v4941 >> 16))) & 65535)) + ((((int)((unsigned int)v4940 >> 16)) * (v4941 & 65535)) & 65535)) >> 16));
  v4939[30] = v4950;
  struct StateT * v4943 = slot_83(v4936);
  return v4943;
}

struct StateT * slot_161(struct StateT * v8292) {
  int v8293 = v8292->timer;
  int v8301 = v8293 + 1;
  v8292->timer = v8301;
  int * v8295 = v8292->regs;
  int v8296 = v8295[11];
  int v8297 = v8295[12];
  int v8306 = v8296 * v8297;
  v8295[28] = v8306;
  struct StateT * v8299 = slot_162(v8292);
  return v8299;
}

struct StateT * slot_185(struct StateT * v8751) {
  int v8752 = v8751->timer;
  int v8764 = v8752 + 1;
  v8751->timer = v8764;
  int * v8754 = v8751->regs;
  int v8755 = v8754[17];
  int v8756 = v8754[6];
  bool v8768 = (v8755 ^ -2147483648) < (v8756 ^ -2147483648);
  int v8759;
  if (v8768) {
    v8759 = 1;
  } else {
    v8759 = 0;
  }
  int * v8760 = v8751->regs;
  v8760[5] = v8759;
  struct StateT * v8762 = slot_186(v8751);
  return v8762;
}

struct StateT * slot_91(struct StateT * v5096) {
  int v5097 = v5096->timer;
  int v5105 = v5097 + 1;
  v5096->timer = v5105;
  int * v5099 = v5096->regs;
  int v5100 = v5099[31];
  int v5101 = v5099[29];
  int v5109 = v5100 + v5101;
  v5099[29] = v5109;
  struct StateT * v5103 = slot_92(v5096);
  return v5103;
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

struct StateT * slot_89(struct StateT * v5054) {
  int v5055 = v5054->timer;
  int v5063 = v5055 + 1;
  v5054->timer = v5063;
  int * v5057 = v5054->regs;
  int v5058 = v5057[6];
  int v5059 = v5057[7];
  int v5068 = v5058 + v5059;
  v5057[17] = v5068;
  struct StateT * v5061 = slot_90(v5054);
  return v5061;
}

struct StateT * slot_66(struct StateT * v3677) {
  int v3678 = v3677->timer;
  int v3686 = v3678 + 1;
  v3677->timer = v3686;
  int * v3680 = v3677->regs;
  int v3681 = v3680[5];
  int v3682 = v3680[28];
  int v3690 = v3681 + v3682;
  v3680[28] = v3690;
  struct StateT * v3684 = slot_67(v3677);
  return v3684;
}

struct StateT * slot_140(struct StateT * v6955) {
  int v6956 = v6955->timer;
  int v6968 = v6956 + 1;
  v6955->timer = v6968;
  int * v6958 = v6955->regs;
  int v6959 = v6958[5];
  int v6960 = v6958[9];
  bool v6972 = (v6959 ^ -2147483648) < (v6960 ^ -2147483648);
  int v6963;
  if (v6972) {
    v6963 = 1;
  } else {
    v6963 = 0;
  }
  int * v6964 = v6955->regs;
  v6964[31] = v6963;
  struct StateT * v6966 = slot_141(v6955);
  return v6966;
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

struct StateT * slot_114(struct StateT * v6119) {
  int v6120 = v6119->timer;
  int v6128 = v6120 + 1;
  v6119->timer = v6128;
  int * v6122 = v6119->regs;
  int v6123 = v6122[6];
  int v6124 = v6122[5];
  int v6132 = v6123 + v6124;
  v6122[5] = v6132;
  struct StateT * v6126 = slot_115(v6119);
  return v6126;
}

struct StateT * slot_135(struct StateT * v6865) {
  int v6866 = v6865->timer;
  int v6874 = v6866 + 1;
  v6865->timer = v6874;
  int * v6868 = v6865->regs;
  int v6869 = v6868[29];
  int v6870 = v6868[5];
  int v6879 = v6869 + v6870;
  v6868[30] = v6879;
  struct StateT * v6872 = slot_136(v6865);
  return v6872;
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

struct StateT * slot_192(struct StateT * v8861) {
  int v8862 = v8861->timer;
  int v8870 = v8862 + 1;
  v8861->timer = v8870;
  int * v8864 = v8861->regs;
  int v8865 = v8864[17];
  int v8866 = v8864[13];
  int v8874 = v8865 | v8866;
  v8864[13] = v8874;
  struct StateT * v8868 = slot_193(v8861);
  return v8868;
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

struct StateT * slot_77(struct StateT * v4856) {
  int v4857 = v4856->timer;
  int v4865 = v4857 + 1;
  v4856->timer = v4865;
  int * v4859 = v4856->regs;
  int v4860 = v4859[7];
  int v4861 = v4859[28];
  int v4869 = v4860 | v4861;
  v4859[7] = v4869;
  struct StateT * v4863 = slot_78(v4856);
  return v4863;
}

struct StateT * slot_85(struct StateT * v4987) {
  int v4988 = v4987->timer;
  int v4996 = v4988 + 1;
  v4987->timer = v4996;
  int * v4990 = v4987->regs;
  int v4991 = v4990[29];
  int v4992 = v4990[13];
  int v5001 = v4991 * v4992;
  v4990[9] = v5001;
  struct StateT * v4994 = slot_86(v4987);
  return v4994;
}

struct StateT * slot_75(struct StateT * v4448) {
  int v4449 = v4448->timer;
  int v4559 = v4449 + 1;
  v4448->timer = v4559;
  int * v4451 = v4448->regs;
  int v4452 = v4451[11];
  int * v4453 = v4448->cache_tags;
  int v4563 = (((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2;
  int v4454 = v4453[v4563];
  int v4564 = ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4455 = v4453[v4564];
  int v4565 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2);
  int v4456 = v4453[v4565];
  int v4566 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4457 = v4453[v4566];
  int v4458 = v4448->timer;
  int v4567 = v4458 + ((100 ^ (((~(((v4456 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4456 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4454 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4454 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4455 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4455 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4456 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4456 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4448->timer = v4567;
  int * v4460 = v4448->cache_vals;
  bool v4568 = !(((~(((v4454 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4454 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4455 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4455 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4553;
  if (v4568) {
    int * v4461 = v4448->cache_age;
    int v4570 = ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v4455 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4455 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4462 = v4461[v4570];
    int v4463 = v4461[v4563];
    int v4571 = v4463 + ((int)((unsigned int)(v4463 - v4462) >> 31));
    v4461[v4563] = v4571;
    int * v4465 = v4448->cache_age;
    int v4466 = v4465[v4564];
    int v4573 = v4466 + ((int)((unsigned int)(v4466 - v4462) >> 31));
    v4465[v4564] = v4573;
    int * v4468 = v4448->cache_age;
    v4468[v4570] = 0;
    v4553 = v4570;
  } else {
    int * v4471 = v4448->cache_age;
    int v4577 = (((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2;
    int v4472 = v4471[v4577];
    int * v4473 = v4448->cache_tags;
    int v4474 = v4473[v4577];
    int v4475 = v4471[v4564];
    int v4476 = v4473[v4564];
    bool v4579 = !(((~(((v4456 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4456 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v4530;
    if (v4579) {
      int * v4477 = v4448->cache_age;
      int v4581 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))) | (-(v4457 ^ ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v4478 = v4477[v4581];
      int v4479 = v4477[v4565];
      int v4582 = v4479 + ((int)((unsigned int)(v4479 - v4478) >> 31));
      v4477[v4565] = v4582;
      int * v4481 = v4448->cache_age;
      int v4482 = v4481[v4566];
      int v4584 = v4482 + ((int)((unsigned int)(v4482 - v4478) >> 31));
      v4481[v4566] = v4584;
      int * v4484 = v4448->cache_age;
      v4484[v4581] = 0;
      v4530 = v4581;
    } else {
      int * v4487 = v4448->cache_age;
      int v4588 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2);
      int v4488 = v4487[v4588];
      int * v4489 = v4448->cache_tags;
      int v4490 = v4489[v4588];
      int v4491 = v4487[v4566];
      int v4492 = v4489[v4566];
      int * v4493 = v4448->cache_dirty;
      int v4591 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4488 + ((~(((v4490 ^ -1) | (-(v4490 ^ -1))) >> 31)) & 2)) - (v4491 + ((~(((v4492 ^ -1) | (-(v4492 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4494 = v4493[v4591];
      bool v4592 = !(v4494 == 0);
      if (v4592) {
        int * v4495 = v4448->cache_tags;
        int v4496 = v4495[v4591];
        int * v4497 = v4448->cache_vals;
        int v4595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4488 + ((~(((v4490 ^ -1) | (-(v4490 ^ -1))) >> 31)) & 2)) - (v4491 + ((~(((v4492 ^ -1) | (-(v4492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4498 = v4497[v4595];
        int v4596 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4488 + ((~(((v4490 ^ -1) | (-(v4490 ^ -1))) >> 31)) & 2)) - (v4491 + ((~(((v4492 ^ -1) | (-(v4492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4499 = v4497[v4596];
        int * v4500 = v4448->mem;
        int v4598 = v4496 * 2;
        v4500[v4598] = v4498;
        int * v4502 = v4448->mem;
        int v4601 = (v4496 * 2) + 1;
        v4502[v4601] = v4499;
        ;
      } else {
        ;
      }
      int * v4507 = v4448->mem;
      int v4606 = ((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) * 2;
      int v4508 = v4507[v4606];
      int v4607 = (((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4509 = v4507[v4607];
      int * v4510 = v4448->cache_vals;
      int v4609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4488 + ((~(((v4490 ^ -1) | (-(v4490 ^ -1))) >> 31)) & 2)) - (v4491 + ((~(((v4492 ^ -1) | (-(v4492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4510[v4609] = v4508;
      int * v4512 = v4448->cache_vals;
      int v4612 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4488 + ((~(((v4490 ^ -1) | (-(v4490 ^ -1))) >> 31)) & 2)) - (v4491 + ((~(((v4492 ^ -1) | (-(v4492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4512[v4612] = v4509;
      int * v4514 = v4448->cache_tags;
      int v4615 = (int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1);
      v4514[v4591] = v4615;
      int * v4516 = v4448->cache_dirty;
      v4516[v4591] = 0;
      int * v4518 = v4448->cache_age;
      v4518[v4591] = 1;
      int * v4520 = v4448->cache_age;
      int v4521 = v4520[v4591];
      int v4522 = v4520[v4565];
      int v4621 = v4522 + ((int)((unsigned int)(v4522 - v4521) >> 31));
      v4520[v4565] = v4621;
      int * v4524 = v4448->cache_age;
      int v4525 = v4524[v4566];
      int v4623 = v4525 + ((int)((unsigned int)(v4525 - v4521) >> 31));
      v4524[v4566] = v4623;
      int * v4527 = v4448->cache_age;
      v4527[v4591] = 0;
      v4530 = v4591;
    }
    int * v4531 = v4448->cache_vals;
    int v4626 = v4530 * 2;
    int v4532 = v4531[v4626];
    int v4627 = (v4530 * 2) + 1;
    int v4533 = v4531[v4627];
    int v4628 = (((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4472 + ((~(((v4474 ^ -1) | (-(v4474 ^ -1))) >> 31)) & 2)) - (v4475 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4531[v4628] = v4532;
    int * v4535 = v4448->cache_vals;
    int v4631 = ((((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4472 + ((~(((v4474 ^ -1) | (-(v4474 ^ -1))) >> 31)) & 2)) - (v4475 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4535[v4631] = v4533;
    int * v4537 = v4448->cache_tags;
    int v4634 = ((((int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4472 + ((~(((v4474 ^ -1) | (-(v4474 ^ -1))) >> 31)) & 2)) - (v4475 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4635 = (int)((unsigned int)((int)((unsigned int)(v4452 + 16) >> 2)) >> 1);
    v4537[v4634] = v4635;
    int * v4539 = v4448->cache_dirty;
    v4539[v4634] = 0;
    int * v4541 = v4448->cache_age;
    v4541[v4634] = 1;
    int * v4543 = v4448->cache_age;
    int v4544 = v4543[v4634];
    int v4545 = v4543[v4563];
    int v4641 = v4545 + ((int)((unsigned int)(v4545 - v4544) >> 31));
    v4543[v4563] = v4641;
    int * v4547 = v4448->cache_age;
    int v4548 = v4547[v4564];
    int v4643 = v4548 + ((int)((unsigned int)(v4548 - v4544) >> 31));
    v4547[v4564] = v4643;
    int * v4550 = v4448->cache_age;
    v4550[v4634] = 0;
    v4553 = v4634;
  }
  int v4646 = (v4553 * 2) + (((int)((unsigned int)(v4452 + 16) >> 2)) & 1);
  int v4554 = v4460[v4646];
  int * v4555 = v4448->regs;
  v4555[6] = v4554;
  struct StateT * v4557 = slot_76(v4448);
  return v4557;
}

struct StateT * slot_72(struct StateT * v4403) {
  int v4404 = v4403->timer;
  int v4411 = v4404 + 1;
  v4403->timer = v4411;
  int * v4406 = v4403->regs;
  int v4407 = v4406[28];
  int v4415 = (int)((unsigned int)v4407 >> 19);
  v4406[17] = v4415;
  struct StateT * v4409 = slot_73(v4403);
  return v4409;
}

struct StateT * slot_119(struct StateT * v6573) {
  int v6574 = v6573->timer;
  int v6582 = v6574 + 1;
  v6573->timer = v6582;
  int * v6576 = v6573->regs;
  int v6577 = v6576[5];
  int v6578 = v6576[17];
  int v6586 = v6577 | v6578;
  v6576[5] = v6586;
  struct StateT * v6580 = slot_120(v6573);
  return v6580;
}

struct StateT * slot_71(struct StateT * v4088) {
  int v4089 = v4088->timer;
  int v4259 = v4089 + 1;
  v4088->timer = v4259;
  int * v4091 = v4088->regs;
  int v4092 = v4091[10];
  int v4093 = v4091[29];
  int * v4094 = v4088->cache_tags;
  int v4264 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2;
  int v4095 = v4094[v4264];
  int v4265 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4096 = v4094[v4265];
  int v4266 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2);
  int v4097 = v4094[v4266];
  int v4267 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4098 = v4094[v4267];
  int v4099 = v4088->timer;
  int v4268 = v4099 + ((100 ^ (((~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4088->timer = v4268;
  bool v4269 = !(((~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4193;
  if (v4269) {
    int * v4101 = v4088->cache_age;
    int v4271 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4102 = v4101[v4271];
    int v4103 = v4101[v4264];
    int v4272 = v4103 + ((int)((unsigned int)(v4103 - v4102) >> 31));
    v4101[v4264] = v4272;
    int * v4105 = v4088->cache_age;
    int v4106 = v4105[v4265];
    int v4274 = v4106 + ((int)((unsigned int)(v4106 - v4102) >> 31));
    v4105[v4265] = v4274;
    int * v4108 = v4088->cache_age;
    v4108[v4271] = 0;
    v4193 = v4271;
  } else {
    int * v4111 = v4088->cache_age;
    int v4278 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2;
    int v4112 = v4111[v4278];
    int * v4113 = v4088->cache_tags;
    int v4114 = v4113[v4278];
    int v4115 = v4111[v4265];
    int v4116 = v4113[v4265];
    bool v4280 = !(((~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v4170;
    if (v4280) {
      int * v4117 = v4088->cache_age;
      int v4282 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4098 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v4118 = v4117[v4282];
      int v4119 = v4117[v4266];
      int v4283 = v4119 + ((int)((unsigned int)(v4119 - v4118) >> 31));
      v4117[v4266] = v4283;
      int * v4121 = v4088->cache_age;
      int v4122 = v4121[v4267];
      int v4285 = v4122 + ((int)((unsigned int)(v4122 - v4118) >> 31));
      v4121[v4267] = v4285;
      int * v4124 = v4088->cache_age;
      v4124[v4282] = 0;
      v4170 = v4282;
    } else {
      int * v4127 = v4088->cache_age;
      int v4289 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2);
      int v4128 = v4127[v4289];
      int * v4129 = v4088->cache_tags;
      int v4130 = v4129[v4289];
      int v4131 = v4127[v4267];
      int v4132 = v4129[v4267];
      int * v4133 = v4088->cache_dirty;
      int v4292 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4134 = v4133[v4292];
      bool v4293 = !(v4134 == 0);
      if (v4293) {
        int * v4135 = v4088->cache_tags;
        int v4136 = v4135[v4292];
        int * v4137 = v4088->cache_vals;
        int v4296 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4138 = v4137[v4296];
        int v4297 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4139 = v4137[v4297];
        int * v4140 = v4088->mem;
        int v4299 = v4136 * 2;
        v4140[v4299] = v4138;
        int * v4142 = v4088->mem;
        int v4302 = (v4136 * 2) + 1;
        v4142[v4302] = v4139;
        ;
      } else {
        ;
      }
      int * v4147 = v4088->mem;
      int v4307 = ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) * 2;
      int v4148 = v4147[v4307];
      int v4308 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) * 2) + 1;
      int v4149 = v4147[v4308];
      int * v4150 = v4088->cache_vals;
      int v4310 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4150[v4310] = v4148;
      int * v4152 = v4088->cache_vals;
      int v4313 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4152[v4313] = v4149;
      int * v4154 = v4088->cache_tags;
      int v4316 = (int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1);
      v4154[v4292] = v4316;
      int * v4156 = v4088->cache_dirty;
      v4156[v4292] = 0;
      int * v4158 = v4088->cache_age;
      v4158[v4292] = 1;
      int * v4160 = v4088->cache_age;
      int v4161 = v4160[v4292];
      int v4162 = v4160[v4266];
      int v4322 = v4162 + ((int)((unsigned int)(v4162 - v4161) >> 31));
      v4160[v4266] = v4322;
      int * v4164 = v4088->cache_age;
      int v4165 = v4164[v4267];
      int v4324 = v4165 + ((int)((unsigned int)(v4165 - v4161) >> 31));
      v4164[v4267] = v4324;
      int * v4167 = v4088->cache_age;
      v4167[v4292] = 0;
      v4170 = v4292;
    }
    int * v4171 = v4088->cache_vals;
    int v4327 = v4170 * 2;
    int v4172 = v4171[v4327];
    int v4328 = (v4170 * 2) + 1;
    int v4173 = v4171[v4328];
    int v4329 = (((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4171[v4329] = v4172;
    int * v4175 = v4088->cache_vals;
    int v4332 = ((((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4175[v4332] = v4173;
    int * v4177 = v4088->cache_tags;
    int v4335 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4336 = (int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1);
    v4177[v4335] = v4336;
    int * v4179 = v4088->cache_dirty;
    v4179[v4335] = 0;
    int * v4181 = v4088->cache_age;
    v4181[v4335] = 1;
    int * v4183 = v4088->cache_age;
    int v4184 = v4183[v4335];
    int v4185 = v4183[v4264];
    int v4342 = v4185 + ((int)((unsigned int)(v4185 - v4184) >> 31));
    v4183[v4264] = v4342;
    int * v4187 = v4088->cache_age;
    int v4188 = v4187[v4265];
    int v4344 = v4188 + ((int)((unsigned int)(v4188 - v4184) >> 31));
    v4187[v4265] = v4344;
    int * v4190 = v4088->cache_age;
    v4190[v4335] = 0;
    v4193 = v4335;
  }
  int * v4194 = v4088->cache_vals;
  int v4347 = (v4193 * 2) + (((int)((unsigned int)(v4092 + 12) >> 2)) & 1);
  v4194[v4347] = v4093;
  int * v4196 = v4088->cache_tags;
  int v4197 = v4196[v4266];
  int v4198 = v4196[v4267];
  bool v4350 = !(((~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4198 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4198 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4252;
  if (v4350) {
    int * v4199 = v4088->cache_age;
    int v4352 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4198 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))) | (-(v4198 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4200 = v4199[v4352];
    int v4201 = v4199[v4266];
    int v4353 = v4201 + ((int)((unsigned int)(v4201 - v4200) >> 31));
    v4199[v4266] = v4353;
    int * v4203 = v4088->cache_age;
    int v4204 = v4203[v4267];
    int v4355 = v4204 + ((int)((unsigned int)(v4204 - v4200) >> 31));
    v4203[v4267] = v4355;
    int * v4206 = v4088->cache_age;
    v4206[v4352] = 0;
    v4252 = v4352;
  } else {
    int * v4209 = v4088->cache_age;
    int v4359 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2);
    int v4210 = v4209[v4359];
    int * v4211 = v4088->cache_tags;
    int v4212 = v4211[v4359];
    int v4213 = v4209[v4267];
    int v4214 = v4211[v4267];
    int * v4215 = v4088->cache_dirty;
    int v4362 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4210 + ((~(((v4212 ^ -1) | (-(v4212 ^ -1))) >> 31)) & 2)) - (v4213 + ((~(((v4214 ^ -1) | (-(v4214 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4216 = v4215[v4362];
    bool v4363 = !(v4216 == 0);
    if (v4363) {
      int * v4217 = v4088->cache_tags;
      int v4218 = v4217[v4362];
      int * v4219 = v4088->cache_vals;
      int v4366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4210 + ((~(((v4212 ^ -1) | (-(v4212 ^ -1))) >> 31)) & 2)) - (v4213 + ((~(((v4214 ^ -1) | (-(v4214 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4220 = v4219[v4366];
      int v4367 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4210 + ((~(((v4212 ^ -1) | (-(v4212 ^ -1))) >> 31)) & 2)) - (v4213 + ((~(((v4214 ^ -1) | (-(v4214 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4221 = v4219[v4367];
      int * v4222 = v4088->mem;
      int v4369 = v4218 * 2;
      v4222[v4369] = v4220;
      int * v4224 = v4088->mem;
      int v4372 = (v4218 * 2) + 1;
      v4224[v4372] = v4221;
      ;
    } else {
      ;
    }
    int * v4229 = v4088->mem;
    int v4377 = ((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) * 2;
    int v4230 = v4229[v4377];
    int v4378 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) * 2) + 1;
    int v4231 = v4229[v4378];
    int * v4232 = v4088->cache_vals;
    int v4380 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4210 + ((~(((v4212 ^ -1) | (-(v4212 ^ -1))) >> 31)) & 2)) - (v4213 + ((~(((v4214 ^ -1) | (-(v4214 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4232[v4380] = v4230;
    int * v4234 = v4088->cache_vals;
    int v4383 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4210 + ((~(((v4212 ^ -1) | (-(v4212 ^ -1))) >> 31)) & 2)) - (v4213 + ((~(((v4214 ^ -1) | (-(v4214 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4234[v4383] = v4231;
    int * v4236 = v4088->cache_tags;
    int v4386 = (int)((unsigned int)((int)((unsigned int)(v4092 + 12) >> 2)) >> 1);
    v4236[v4362] = v4386;
    int * v4238 = v4088->cache_dirty;
    v4238[v4362] = 0;
    int * v4240 = v4088->cache_age;
    v4240[v4362] = 1;
    int * v4242 = v4088->cache_age;
    int v4243 = v4242[v4362];
    int v4244 = v4242[v4266];
    int v4392 = v4244 + ((int)((unsigned int)(v4244 - v4243) >> 31));
    v4242[v4266] = v4392;
    int * v4246 = v4088->cache_age;
    int v4247 = v4246[v4267];
    int v4394 = v4247 + ((int)((unsigned int)(v4247 - v4243) >> 31));
    v4246[v4267] = v4394;
    int * v4249 = v4088->cache_age;
    v4249[v4362] = 0;
    v4252 = v4362;
  }
  int * v4253 = v4088->cache_vals;
  int v4397 = (v4252 * 2) + (((int)((unsigned int)(v4092 + 12) >> 2)) & 1);
  v4253[v4397] = v4093;
  int * v4255 = v4088->cache_dirty;
  v4255[v4252] = 1;
  struct StateT * v4257 = slot_72(v4088);
  return v4257;
}

struct StateT * slot_101(struct StateT * v5293) {
  int v5294 = v5293->timer;
  int v5302 = v5294 + 1;
  v5293->timer = v5302;
  int * v5296 = v5293->regs;
  int v5297 = v5296[18];
  int v5298 = v5296[6];
  int v5306 = v5297 + v5298;
  v5296[6] = v5306;
  struct StateT * v5300 = slot_102(v5293);
  return v5300;
}

struct StateT * slot_108(struct StateT * v5422) {
  int v5423 = v5422->timer;
  int v5430 = v5423 + 1;
  v5422->timer = v5430;
  int * v5425 = v5422->regs;
  int v5426 = v5425[7];
  int v5433 = (int)((unsigned int)v5426 >> 19);
  v5425[7] = v5433;
  struct StateT * v5428 = slot_109(v5422);
  return v5428;
}

struct StateT * slot_116(struct StateT * v6339) {
  int v6340 = v6339->timer;
  int v6450 = v6340 + 1;
  v6339->timer = v6450;
  int * v6342 = v6339->regs;
  int v6343 = v6342[11];
  int * v6344 = v6339->cache_tags;
  int v6454 = (((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2;
  int v6345 = v6344[v6454];
  int v6455 = ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6346 = v6344[v6455];
  int v6456 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2);
  int v6347 = v6344[v6456];
  int v6457 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6348 = v6344[v6457];
  int v6349 = v6339->timer;
  int v6458 = v6349 + ((100 ^ (((~(((v6347 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6347 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6345 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6345 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6346 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6346 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6347 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6347 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6339->timer = v6458;
  int * v6351 = v6339->cache_vals;
  bool v6459 = !(((~(((v6345 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6345 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6346 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6346 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v6444;
  if (v6459) {
    int * v6352 = v6339->cache_age;
    int v6461 = ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v6346 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6346 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v6353 = v6352[v6461];
    int v6354 = v6352[v6454];
    int v6462 = v6354 + ((int)((unsigned int)(v6354 - v6353) >> 31));
    v6352[v6454] = v6462;
    int * v6356 = v6339->cache_age;
    int v6357 = v6356[v6455];
    int v6464 = v6357 + ((int)((unsigned int)(v6357 - v6353) >> 31));
    v6356[v6455] = v6464;
    int * v6359 = v6339->cache_age;
    v6359[v6461] = 0;
    v6444 = v6461;
  } else {
    int * v6362 = v6339->cache_age;
    int v6468 = (((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2;
    int v6363 = v6362[v6468];
    int * v6364 = v6339->cache_tags;
    int v6365 = v6364[v6468];
    int v6366 = v6362[v6455];
    int v6367 = v6364[v6455];
    bool v6470 = !(((~(((v6347 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6347 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v6421;
    if (v6470) {
      int * v6368 = v6339->cache_age;
      int v6472 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))) | (-(v6348 ^ ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v6369 = v6368[v6472];
      int v6370 = v6368[v6456];
      int v6473 = v6370 + ((int)((unsigned int)(v6370 - v6369) >> 31));
      v6368[v6456] = v6473;
      int * v6372 = v6339->cache_age;
      int v6373 = v6372[v6457];
      int v6475 = v6373 + ((int)((unsigned int)(v6373 - v6369) >> 31));
      v6372[v6457] = v6475;
      int * v6375 = v6339->cache_age;
      v6375[v6472] = 0;
      v6421 = v6472;
    } else {
      int * v6378 = v6339->cache_age;
      int v6479 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2);
      int v6379 = v6378[v6479];
      int * v6380 = v6339->cache_tags;
      int v6381 = v6380[v6479];
      int v6382 = v6378[v6457];
      int v6383 = v6380[v6457];
      int * v6384 = v6339->cache_dirty;
      int v6482 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6379 + ((~(((v6381 ^ -1) | (-(v6381 ^ -1))) >> 31)) & 2)) - (v6382 + ((~(((v6383 ^ -1) | (-(v6383 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6385 = v6384[v6482];
      bool v6483 = !(v6385 == 0);
      if (v6483) {
        int * v6386 = v6339->cache_tags;
        int v6387 = v6386[v6482];
        int * v6388 = v6339->cache_vals;
        int v6486 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6379 + ((~(((v6381 ^ -1) | (-(v6381 ^ -1))) >> 31)) & 2)) - (v6382 + ((~(((v6383 ^ -1) | (-(v6383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6389 = v6388[v6486];
        int v6487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6379 + ((~(((v6381 ^ -1) | (-(v6381 ^ -1))) >> 31)) & 2)) - (v6382 + ((~(((v6383 ^ -1) | (-(v6383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6390 = v6388[v6487];
        int * v6391 = v6339->mem;
        int v6489 = v6387 * 2;
        v6391[v6489] = v6389;
        int * v6393 = v6339->mem;
        int v6492 = (v6387 * 2) + 1;
        v6393[v6492] = v6390;
        ;
      } else {
        ;
      }
      int * v6398 = v6339->mem;
      int v6497 = ((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) * 2;
      int v6399 = v6398[v6497];
      int v6498 = (((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) * 2) + 1;
      int v6400 = v6398[v6498];
      int * v6401 = v6339->cache_vals;
      int v6500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6379 + ((~(((v6381 ^ -1) | (-(v6381 ^ -1))) >> 31)) & 2)) - (v6382 + ((~(((v6383 ^ -1) | (-(v6383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6401[v6500] = v6399;
      int * v6403 = v6339->cache_vals;
      int v6503 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6379 + ((~(((v6381 ^ -1) | (-(v6381 ^ -1))) >> 31)) & 2)) - (v6382 + ((~(((v6383 ^ -1) | (-(v6383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6403[v6503] = v6400;
      int * v6405 = v6339->cache_tags;
      int v6506 = (int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1);
      v6405[v6482] = v6506;
      int * v6407 = v6339->cache_dirty;
      v6407[v6482] = 0;
      int * v6409 = v6339->cache_age;
      v6409[v6482] = 1;
      int * v6411 = v6339->cache_age;
      int v6412 = v6411[v6482];
      int v6413 = v6411[v6456];
      int v6512 = v6413 + ((int)((unsigned int)(v6413 - v6412) >> 31));
      v6411[v6456] = v6512;
      int * v6415 = v6339->cache_age;
      int v6416 = v6415[v6457];
      int v6514 = v6416 + ((int)((unsigned int)(v6416 - v6412) >> 31));
      v6415[v6457] = v6514;
      int * v6418 = v6339->cache_age;
      v6418[v6482] = 0;
      v6421 = v6482;
    }
    int * v6422 = v6339->cache_vals;
    int v6517 = v6421 * 2;
    int v6423 = v6422[v6517];
    int v6518 = (v6421 * 2) + 1;
    int v6424 = v6422[v6518];
    int v6519 = (((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6363 + ((~(((v6365 ^ -1) | (-(v6365 ^ -1))) >> 31)) & 2)) - (v6366 + ((~(((v6367 ^ -1) | (-(v6367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6422[v6519] = v6423;
    int * v6426 = v6339->cache_vals;
    int v6522 = ((((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6363 + ((~(((v6365 ^ -1) | (-(v6365 ^ -1))) >> 31)) & 2)) - (v6366 + ((~(((v6367 ^ -1) | (-(v6367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6426[v6522] = v6424;
    int * v6428 = v6339->cache_tags;
    int v6525 = ((((int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6363 + ((~(((v6365 ^ -1) | (-(v6365 ^ -1))) >> 31)) & 2)) - (v6366 + ((~(((v6367 ^ -1) | (-(v6367 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6526 = (int)((unsigned int)((int)((unsigned int)(v6343 + 28) >> 2)) >> 1);
    v6428[v6525] = v6526;
    int * v6430 = v6339->cache_dirty;
    v6430[v6525] = 0;
    int * v6432 = v6339->cache_age;
    v6432[v6525] = 1;
    int * v6434 = v6339->cache_age;
    int v6435 = v6434[v6525];
    int v6436 = v6434[v6454];
    int v6532 = v6436 + ((int)((unsigned int)(v6436 - v6435) >> 31));
    v6434[v6454] = v6532;
    int * v6438 = v6339->cache_age;
    int v6439 = v6438[v6455];
    int v6534 = v6439 + ((int)((unsigned int)(v6439 - v6435) >> 31));
    v6438[v6455] = v6534;
    int * v6441 = v6339->cache_age;
    v6441[v6525] = 0;
    v6444 = v6525;
  }
  int v6537 = (v6444 * 2) + (((int)((unsigned int)(v6343 + 28) >> 2)) & 1);
  int v6445 = v6351[v6537];
  int * v6446 = v6339->regs;
  v6446[29] = v6445;
  struct StateT * v6448 = slot_117(v6339);
  return v6448;
}

struct StateT * slot_93(struct StateT * v5137) {
  int v5138 = v5137->timer;
  int v5146 = v5138 + 1;
  v5137->timer = v5146;
  int * v5140 = v5137->regs;
  int v5141 = v5140[30];
  int v5142 = v5140[7];
  int v5150 = v5141 + v5142;
  v5140[7] = v5150;
  struct StateT * v5144 = slot_94(v5137);
  return v5144;
}

struct StateT * slot_88(struct StateT * v5037) {
  int v5038 = v5037->timer;
  int v5046 = v5038 + 1;
  v5037->timer = v5046;
  int * v5040 = v5037->regs;
  int v5041 = v5040[28];
  int v5042 = v5040[17];
  int v5051 = v5041 + v5042;
  v5040[29] = v5051;
  struct StateT * v5044 = slot_89(v5037);
  return v5044;
}

struct StateT * slot_96(struct StateT * v5195) {
  int v5196 = v5195->timer;
  int v5204 = v5196 + 1;
  v5195->timer = v5204;
  int * v5198 = v5195->regs;
  int v5199 = v5198[8];
  int v5200 = v5198[6];
  int v5208 = v5199 + v5200;
  v5198[6] = v5208;
  struct StateT * v5202 = slot_97(v5195);
  return v5202;
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

struct StateT * slot_134(struct StateT * v6840) {
  int v6841 = v6840->timer;
  int v6853 = v6841 + 1;
  v6840->timer = v6853;
  int * v6843 = v6840->regs;
  int v6844 = v6843[29];
  int v6845 = v6843[31];
  bool v6857 = (v6844 ^ -2147483648) < (v6845 ^ -2147483648);
  int v6848;
  if (v6857) {
    v6848 = 1;
  } else {
    v6848 = 0;
  }
  int * v6849 = v6840->regs;
  v6849[6] = v6848;
  struct StateT * v6851 = slot_135(v6840);
  return v6851;
}

struct StateT * slot_175(struct StateT * v8550) {
  int v8551 = v8550->timer;
  int v8559 = v8551 + 1;
  v8550->timer = v8559;
  int * v8553 = v8550->regs;
  int v8554 = v8553[6];
  int v8555 = v8553[17];
  int v8563 = v8554 + v8555;
  v8553[17] = v8563;
  struct StateT * v8557 = slot_176(v8550);
  return v8557;
}

struct StateT * slot_69(struct StateT * v3749) {
  int v3750 = v3749->timer;
  int v3762 = v3750 + 1;
  v3749->timer = v3762;
  int * v3752 = v3749->regs;
  int v3753 = v3752[28];
  int v3754 = v3752[5];
  bool v3766 = (v3753 ^ -2147483648) < (v3754 ^ -2147483648);
  int v3757;
  if (v3766) {
    v3757 = 1;
  } else {
    v3757 = 0;
  }
  int * v3758 = v3749->regs;
  v3758[5] = v3757;
  struct StateT * v3760 = slot_70(v3749);
  return v3760;
}

struct StateT * slot_202(struct StateT * v9015) {
  int v9016 = v9015->timer;
  int v9028 = v9016 + 1;
  v9015->timer = v9028;
  int * v9018 = v9015->regs;
  int v9019 = v9018[13];
  int v9020 = v9018[14];
  bool v9032 = (v9019 ^ -2147483648) < (v9020 ^ -2147483648);
  int v9023;
  if (v9032) {
    v9023 = 1;
  } else {
    v9023 = 0;
  }
  int * v9024 = v9015->regs;
  v9024[14] = v9023;
  struct StateT * v9026 = slot_203(v9015);
  return v9026;
}

struct StateT * slot_188(struct StateT * v8792) {
  int v8793 = v8792->timer;
  int v8800 = v8793 + 1;
  v8792->timer = v8800;
  int * v8795 = v8792->regs;
  int v8796 = v8795[17];
  int v8803 = (int)((unsigned int)v8796 >> 19);
  v8795[17] = v8803;
  struct StateT * v8798 = slot_189(v8792);
  return v8798;
}

struct StateT * slot_138(struct StateT * v6914) {
  int v6915 = v6914->timer;
  int v6923 = v6915 + 1;
  v6914->timer = v6923;
  int * v6917 = v6914->regs;
  int v6918 = v6917[9];
  int v6919 = v6917[6];
  int v6928 = v6918 + v6919;
  v6917[5] = v6928;
  struct StateT * v6921 = slot_139(v6914);
  return v6921;
}

struct StateT * slot_186(struct StateT * v8735) {
  int v8736 = v8735->timer;
  int v8744 = v8736 + 1;
  v8735->timer = v8744;
  int * v8738 = v8735->regs;
  int v8739 = v8738[12];
  int v8740 = v8738[5];
  int v8748 = v8739 + v8740;
  v8738[5] = v8748;
  struct StateT * v8742 = slot_187(v8735);
  return v8742;
}

struct StateT * slot_102(struct StateT * v5309) {
  int v5310 = v5309->timer;
  int v5318 = v5310 + 1;
  v5309->timer = v5318;
  int * v5312 = v5309->regs;
  int v5313 = v5312[30];
  int v5314 = v5312[28];
  int v5323 = v5313 + v5314;
  v5312[7] = v5323;
  struct StateT * v5316 = slot_103(v5309);
  return v5316;
}

struct StateT * slot_145(struct StateT * v7067) {
  int v7068 = v7067->timer;
  int v7080 = v7068 + 1;
  v7067->timer = v7080;
  int * v7070 = v7067->regs;
  int v7071 = v7070[7];
  int v7072 = v7070[29];
  bool v7084 = (v7071 ^ -2147483648) < (v7072 ^ -2147483648);
  int v7075;
  if (v7084) {
    v7075 = 1;
  } else {
    v7075 = 0;
  }
  int * v7076 = v7067->regs;
  v7076[28] = v7075;
  struct StateT * v7078 = slot_146(v7067);
  return v7078;
}

struct StateT * slot_110(struct StateT * v5460) {
  int v5461 = v5460->timer;
  int v5631 = v5461 + 1;
  v5460->timer = v5631;
  int * v5463 = v5460->regs;
  int v5464 = v5463[10];
  int v5465 = v5463[17];
  int * v5466 = v5460->cache_tags;
  int v5636 = (((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2;
  int v5467 = v5466[v5636];
  int v5637 = ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5468 = v5466[v5637];
  int v5638 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2);
  int v5469 = v5466[v5638];
  int v5639 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5470 = v5466[v5639];
  int v5471 = v5460->timer;
  int v5640 = v5471 + ((100 ^ (((~(((v5469 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5469 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5467 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5467 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5468 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5468 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5469 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5469 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5460->timer = v5640;
  bool v5641 = !(((~(((v5467 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5467 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5468 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5468 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v5565;
  if (v5641) {
    int * v5473 = v5460->cache_age;
    int v5643 = ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v5468 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5468 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v5474 = v5473[v5643];
    int v5475 = v5473[v5636];
    int v5644 = v5475 + ((int)((unsigned int)(v5475 - v5474) >> 31));
    v5473[v5636] = v5644;
    int * v5477 = v5460->cache_age;
    int v5478 = v5477[v5637];
    int v5646 = v5478 + ((int)((unsigned int)(v5478 - v5474) >> 31));
    v5477[v5637] = v5646;
    int * v5480 = v5460->cache_age;
    v5480[v5643] = 0;
    v5565 = v5643;
  } else {
    int * v5483 = v5460->cache_age;
    int v5650 = (((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2;
    int v5484 = v5483[v5650];
    int * v5485 = v5460->cache_tags;
    int v5486 = v5485[v5650];
    int v5487 = v5483[v5637];
    int v5488 = v5485[v5637];
    bool v5652 = !(((~(((v5469 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5469 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v5542;
    if (v5652) {
      int * v5489 = v5460->cache_age;
      int v5654 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5470 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v5490 = v5489[v5654];
      int v5491 = v5489[v5638];
      int v5655 = v5491 + ((int)((unsigned int)(v5491 - v5490) >> 31));
      v5489[v5638] = v5655;
      int * v5493 = v5460->cache_age;
      int v5494 = v5493[v5639];
      int v5657 = v5494 + ((int)((unsigned int)(v5494 - v5490) >> 31));
      v5493[v5639] = v5657;
      int * v5496 = v5460->cache_age;
      v5496[v5654] = 0;
      v5542 = v5654;
    } else {
      int * v5499 = v5460->cache_age;
      int v5661 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2);
      int v5500 = v5499[v5661];
      int * v5501 = v5460->cache_tags;
      int v5502 = v5501[v5661];
      int v5503 = v5499[v5639];
      int v5504 = v5501[v5639];
      int * v5505 = v5460->cache_dirty;
      int v5664 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5500 + ((~(((v5502 ^ -1) | (-(v5502 ^ -1))) >> 31)) & 2)) - (v5503 + ((~(((v5504 ^ -1) | (-(v5504 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5506 = v5505[v5664];
      bool v5665 = !(v5506 == 0);
      if (v5665) {
        int * v5507 = v5460->cache_tags;
        int v5508 = v5507[v5664];
        int * v5509 = v5460->cache_vals;
        int v5668 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5500 + ((~(((v5502 ^ -1) | (-(v5502 ^ -1))) >> 31)) & 2)) - (v5503 + ((~(((v5504 ^ -1) | (-(v5504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5510 = v5509[v5668];
        int v5669 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5500 + ((~(((v5502 ^ -1) | (-(v5502 ^ -1))) >> 31)) & 2)) - (v5503 + ((~(((v5504 ^ -1) | (-(v5504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5511 = v5509[v5669];
        int * v5512 = v5460->mem;
        int v5671 = v5508 * 2;
        v5512[v5671] = v5510;
        int * v5514 = v5460->mem;
        int v5674 = (v5508 * 2) + 1;
        v5514[v5674] = v5511;
        ;
      } else {
        ;
      }
      int * v5519 = v5460->mem;
      int v5679 = ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) * 2;
      int v5520 = v5519[v5679];
      int v5680 = (((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) * 2) + 1;
      int v5521 = v5519[v5680];
      int * v5522 = v5460->cache_vals;
      int v5682 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5500 + ((~(((v5502 ^ -1) | (-(v5502 ^ -1))) >> 31)) & 2)) - (v5503 + ((~(((v5504 ^ -1) | (-(v5504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5522[v5682] = v5520;
      int * v5524 = v5460->cache_vals;
      int v5685 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5500 + ((~(((v5502 ^ -1) | (-(v5502 ^ -1))) >> 31)) & 2)) - (v5503 + ((~(((v5504 ^ -1) | (-(v5504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5524[v5685] = v5521;
      int * v5526 = v5460->cache_tags;
      int v5688 = (int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1);
      v5526[v5664] = v5688;
      int * v5528 = v5460->cache_dirty;
      v5528[v5664] = 0;
      int * v5530 = v5460->cache_age;
      v5530[v5664] = 1;
      int * v5532 = v5460->cache_age;
      int v5533 = v5532[v5664];
      int v5534 = v5532[v5638];
      int v5694 = v5534 + ((int)((unsigned int)(v5534 - v5533) >> 31));
      v5532[v5638] = v5694;
      int * v5536 = v5460->cache_age;
      int v5537 = v5536[v5639];
      int v5696 = v5537 + ((int)((unsigned int)(v5537 - v5533) >> 31));
      v5536[v5639] = v5696;
      int * v5539 = v5460->cache_age;
      v5539[v5664] = 0;
      v5542 = v5664;
    }
    int * v5543 = v5460->cache_vals;
    int v5699 = v5542 * 2;
    int v5544 = v5543[v5699];
    int v5700 = (v5542 * 2) + 1;
    int v5545 = v5543[v5700];
    int v5701 = (((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5484 + ((~(((v5486 ^ -1) | (-(v5486 ^ -1))) >> 31)) & 2)) - (v5487 + ((~(((v5488 ^ -1) | (-(v5488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5543[v5701] = v5544;
    int * v5547 = v5460->cache_vals;
    int v5704 = ((((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5484 + ((~(((v5486 ^ -1) | (-(v5486 ^ -1))) >> 31)) & 2)) - (v5487 + ((~(((v5488 ^ -1) | (-(v5488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5547[v5704] = v5545;
    int * v5549 = v5460->cache_tags;
    int v5707 = ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5484 + ((~(((v5486 ^ -1) | (-(v5486 ^ -1))) >> 31)) & 2)) - (v5487 + ((~(((v5488 ^ -1) | (-(v5488 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5708 = (int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1);
    v5549[v5707] = v5708;
    int * v5551 = v5460->cache_dirty;
    v5551[v5707] = 0;
    int * v5553 = v5460->cache_age;
    v5553[v5707] = 1;
    int * v5555 = v5460->cache_age;
    int v5556 = v5555[v5707];
    int v5557 = v5555[v5636];
    int v5714 = v5557 + ((int)((unsigned int)(v5557 - v5556) >> 31));
    v5555[v5636] = v5714;
    int * v5559 = v5460->cache_age;
    int v5560 = v5559[v5637];
    int v5716 = v5560 + ((int)((unsigned int)(v5560 - v5556) >> 31));
    v5559[v5637] = v5716;
    int * v5562 = v5460->cache_age;
    v5562[v5707] = 0;
    v5565 = v5707;
  }
  int * v5566 = v5460->cache_vals;
  int v5719 = (v5565 * 2) + (((int)((unsigned int)(v5464 + 16) >> 2)) & 1);
  v5566[v5719] = v5465;
  int * v5568 = v5460->cache_tags;
  int v5569 = v5568[v5638];
  int v5570 = v5568[v5639];
  bool v5722 = !(((~(((v5569 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5569 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5570 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5570 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v5624;
  if (v5722) {
    int * v5571 = v5460->cache_age;
    int v5724 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5570 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))) | (-(v5570 ^ ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v5572 = v5571[v5724];
    int v5573 = v5571[v5638];
    int v5725 = v5573 + ((int)((unsigned int)(v5573 - v5572) >> 31));
    v5571[v5638] = v5725;
    int * v5575 = v5460->cache_age;
    int v5576 = v5575[v5639];
    int v5727 = v5576 + ((int)((unsigned int)(v5576 - v5572) >> 31));
    v5575[v5639] = v5727;
    int * v5578 = v5460->cache_age;
    v5578[v5724] = 0;
    v5624 = v5724;
  } else {
    int * v5581 = v5460->cache_age;
    int v5731 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2);
    int v5582 = v5581[v5731];
    int * v5583 = v5460->cache_tags;
    int v5584 = v5583[v5731];
    int v5585 = v5581[v5639];
    int v5586 = v5583[v5639];
    int * v5587 = v5460->cache_dirty;
    int v5734 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5582 + ((~(((v5584 ^ -1) | (-(v5584 ^ -1))) >> 31)) & 2)) - (v5585 + ((~(((v5586 ^ -1) | (-(v5586 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5588 = v5587[v5734];
    bool v5735 = !(v5588 == 0);
    if (v5735) {
      int * v5589 = v5460->cache_tags;
      int v5590 = v5589[v5734];
      int * v5591 = v5460->cache_vals;
      int v5738 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5582 + ((~(((v5584 ^ -1) | (-(v5584 ^ -1))) >> 31)) & 2)) - (v5585 + ((~(((v5586 ^ -1) | (-(v5586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5592 = v5591[v5738];
      int v5739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5582 + ((~(((v5584 ^ -1) | (-(v5584 ^ -1))) >> 31)) & 2)) - (v5585 + ((~(((v5586 ^ -1) | (-(v5586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5593 = v5591[v5739];
      int * v5594 = v5460->mem;
      int v5741 = v5590 * 2;
      v5594[v5741] = v5592;
      int * v5596 = v5460->mem;
      int v5744 = (v5590 * 2) + 1;
      v5596[v5744] = v5593;
      ;
    } else {
      ;
    }
    int * v5601 = v5460->mem;
    int v5749 = ((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) * 2;
    int v5602 = v5601[v5749];
    int v5750 = (((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) * 2) + 1;
    int v5603 = v5601[v5750];
    int * v5604 = v5460->cache_vals;
    int v5752 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5582 + ((~(((v5584 ^ -1) | (-(v5584 ^ -1))) >> 31)) & 2)) - (v5585 + ((~(((v5586 ^ -1) | (-(v5586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5604[v5752] = v5602;
    int * v5606 = v5460->cache_vals;
    int v5755 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5582 + ((~(((v5584 ^ -1) | (-(v5584 ^ -1))) >> 31)) & 2)) - (v5585 + ((~(((v5586 ^ -1) | (-(v5586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5606[v5755] = v5603;
    int * v5608 = v5460->cache_tags;
    int v5758 = (int)((unsigned int)((int)((unsigned int)(v5464 + 16) >> 2)) >> 1);
    v5608[v5734] = v5758;
    int * v5610 = v5460->cache_dirty;
    v5610[v5734] = 0;
    int * v5612 = v5460->cache_age;
    v5612[v5734] = 1;
    int * v5614 = v5460->cache_age;
    int v5615 = v5614[v5734];
    int v5616 = v5614[v5638];
    int v5764 = v5616 + ((int)((unsigned int)(v5616 - v5615) >> 31));
    v5614[v5638] = v5764;
    int * v5618 = v5460->cache_age;
    int v5619 = v5618[v5639];
    int v5766 = v5619 + ((int)((unsigned int)(v5619 - v5615) >> 31));
    v5618[v5639] = v5766;
    int * v5621 = v5460->cache_age;
    v5621[v5734] = 0;
    v5624 = v5734;
  }
  int * v5625 = v5460->cache_vals;
  int v5769 = (v5624 * 2) + (((int)((unsigned int)(v5464 + 16) >> 2)) & 1);
  v5625[v5769] = v5465;
  int * v5627 = v5460->cache_dirty;
  v5627[v5624] = 1;
  struct StateT * v5629 = slot_111(v5460);
  return v5629;
}

struct StateT * slot_196(struct StateT * v8918) {
  int v8919 = v8918->timer;
  int v8927 = v8919 + 1;
  v8918->timer = v8927;
  int * v8921 = v8918->regs;
  int v8922 = v8921[12];
  int v8923 = v8921[5];
  int v8931 = v8922 | v8923;
  v8921[12] = v8931;
  struct StateT * v8925 = slot_197(v8918);
  return v8925;
}

struct StateT * slot_208(struct StateT * v10016) {
  int v10017 = v10016->timer;
  int v10187 = v10017 + 1;
  v10016->timer = v10187;
  int * v10019 = v10016->regs;
  int v10020 = v10019[10];
  int v10021 = v10019[16];
  int * v10022 = v10016->cache_tags;
  int v10192 = (((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2;
  int v10023 = v10022[v10192];
  int v10193 = ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10024 = v10022[v10193];
  int v10194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2);
  int v10025 = v10022[v10194];
  int v10195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10026 = v10022[v10195];
  int v10027 = v10016->timer;
  int v10196 = v10027 + ((100 ^ (((~(((v10025 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10025 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10023 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10023 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10024 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10024 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10025 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10025 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10016->timer = v10196;
  bool v10197 = !(((~(((v10023 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10023 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10024 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10024 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v10121;
  if (v10197) {
    int * v10029 = v10016->cache_age;
    int v10199 = ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v10024 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10024 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v10030 = v10029[v10199];
    int v10031 = v10029[v10192];
    int v10200 = v10031 + ((int)((unsigned int)(v10031 - v10030) >> 31));
    v10029[v10192] = v10200;
    int * v10033 = v10016->cache_age;
    int v10034 = v10033[v10193];
    int v10202 = v10034 + ((int)((unsigned int)(v10034 - v10030) >> 31));
    v10033[v10193] = v10202;
    int * v10036 = v10016->cache_age;
    v10036[v10199] = 0;
    v10121 = v10199;
  } else {
    int * v10039 = v10016->cache_age;
    int v10206 = (((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2;
    int v10040 = v10039[v10206];
    int * v10041 = v10016->cache_tags;
    int v10042 = v10041[v10206];
    int v10043 = v10039[v10193];
    int v10044 = v10041[v10193];
    bool v10208 = !(((~(((v10025 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10025 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v10098;
    if (v10208) {
      int * v10045 = v10016->cache_age;
      int v10210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10026 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v10046 = v10045[v10210];
      int v10047 = v10045[v10194];
      int v10211 = v10047 + ((int)((unsigned int)(v10047 - v10046) >> 31));
      v10045[v10194] = v10211;
      int * v10049 = v10016->cache_age;
      int v10050 = v10049[v10195];
      int v10213 = v10050 + ((int)((unsigned int)(v10050 - v10046) >> 31));
      v10049[v10195] = v10213;
      int * v10052 = v10016->cache_age;
      v10052[v10210] = 0;
      v10098 = v10210;
    } else {
      int * v10055 = v10016->cache_age;
      int v10217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2);
      int v10056 = v10055[v10217];
      int * v10057 = v10016->cache_tags;
      int v10058 = v10057[v10217];
      int v10059 = v10055[v10195];
      int v10060 = v10057[v10195];
      int * v10061 = v10016->cache_dirty;
      int v10220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10056 + ((~(((v10058 ^ -1) | (-(v10058 ^ -1))) >> 31)) & 2)) - (v10059 + ((~(((v10060 ^ -1) | (-(v10060 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10062 = v10061[v10220];
      bool v10221 = !(v10062 == 0);
      if (v10221) {
        int * v10063 = v10016->cache_tags;
        int v10064 = v10063[v10220];
        int * v10065 = v10016->cache_vals;
        int v10224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10056 + ((~(((v10058 ^ -1) | (-(v10058 ^ -1))) >> 31)) & 2)) - (v10059 + ((~(((v10060 ^ -1) | (-(v10060 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10066 = v10065[v10224];
        int v10225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10056 + ((~(((v10058 ^ -1) | (-(v10058 ^ -1))) >> 31)) & 2)) - (v10059 + ((~(((v10060 ^ -1) | (-(v10060 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10067 = v10065[v10225];
        int * v10068 = v10016->mem;
        int v10227 = v10064 * 2;
        v10068[v10227] = v10066;
        int * v10070 = v10016->mem;
        int v10230 = (v10064 * 2) + 1;
        v10070[v10230] = v10067;
        ;
      } else {
        ;
      }
      int * v10075 = v10016->mem;
      int v10235 = ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) * 2;
      int v10076 = v10075[v10235];
      int v10236 = (((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) * 2) + 1;
      int v10077 = v10075[v10236];
      int * v10078 = v10016->cache_vals;
      int v10238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10056 + ((~(((v10058 ^ -1) | (-(v10058 ^ -1))) >> 31)) & 2)) - (v10059 + ((~(((v10060 ^ -1) | (-(v10060 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10078[v10238] = v10076;
      int * v10080 = v10016->cache_vals;
      int v10241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10056 + ((~(((v10058 ^ -1) | (-(v10058 ^ -1))) >> 31)) & 2)) - (v10059 + ((~(((v10060 ^ -1) | (-(v10060 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10080[v10241] = v10077;
      int * v10082 = v10016->cache_tags;
      int v10244 = (int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1);
      v10082[v10220] = v10244;
      int * v10084 = v10016->cache_dirty;
      v10084[v10220] = 0;
      int * v10086 = v10016->cache_age;
      v10086[v10220] = 1;
      int * v10088 = v10016->cache_age;
      int v10089 = v10088[v10220];
      int v10090 = v10088[v10194];
      int v10250 = v10090 + ((int)((unsigned int)(v10090 - v10089) >> 31));
      v10088[v10194] = v10250;
      int * v10092 = v10016->cache_age;
      int v10093 = v10092[v10195];
      int v10252 = v10093 + ((int)((unsigned int)(v10093 - v10089) >> 31));
      v10092[v10195] = v10252;
      int * v10095 = v10016->cache_age;
      v10095[v10220] = 0;
      v10098 = v10220;
    }
    int * v10099 = v10016->cache_vals;
    int v10255 = v10098 * 2;
    int v10100 = v10099[v10255];
    int v10256 = (v10098 * 2) + 1;
    int v10101 = v10099[v10256];
    int v10257 = (((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10040 + ((~(((v10042 ^ -1) | (-(v10042 ^ -1))) >> 31)) & 2)) - (v10043 + ((~(((v10044 ^ -1) | (-(v10044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10099[v10257] = v10100;
    int * v10103 = v10016->cache_vals;
    int v10260 = ((((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10040 + ((~(((v10042 ^ -1) | (-(v10042 ^ -1))) >> 31)) & 2)) - (v10043 + ((~(((v10044 ^ -1) | (-(v10044 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10103[v10260] = v10101;
    int * v10105 = v10016->cache_tags;
    int v10263 = ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v10040 + ((~(((v10042 ^ -1) | (-(v10042 ^ -1))) >> 31)) & 2)) - (v10043 + ((~(((v10044 ^ -1) | (-(v10044 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10264 = (int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1);
    v10105[v10263] = v10264;
    int * v10107 = v10016->cache_dirty;
    v10107[v10263] = 0;
    int * v10109 = v10016->cache_age;
    v10109[v10263] = 1;
    int * v10111 = v10016->cache_age;
    int v10112 = v10111[v10263];
    int v10113 = v10111[v10192];
    int v10270 = v10113 + ((int)((unsigned int)(v10113 - v10112) >> 31));
    v10111[v10192] = v10270;
    int * v10115 = v10016->cache_age;
    int v10116 = v10115[v10193];
    int v10272 = v10116 + ((int)((unsigned int)(v10116 - v10112) >> 31));
    v10115[v10193] = v10272;
    int * v10118 = v10016->cache_age;
    v10118[v10263] = 0;
    v10121 = v10263;
  }
  int * v10122 = v10016->cache_vals;
  int v10275 = (v10121 * 2) + (((int)((unsigned int)(v10020 + 36) >> 2)) & 1);
  v10122[v10275] = v10021;
  int * v10124 = v10016->cache_tags;
  int v10125 = v10124[v10194];
  int v10126 = v10124[v10195];
  bool v10278 = !(((~(((v10125 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10125 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v10126 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10126 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v10180;
  if (v10278) {
    int * v10127 = v10016->cache_age;
    int v10280 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10126 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))) | (-(v10126 ^ ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v10128 = v10127[v10280];
    int v10129 = v10127[v10194];
    int v10281 = v10129 + ((int)((unsigned int)(v10129 - v10128) >> 31));
    v10127[v10194] = v10281;
    int * v10131 = v10016->cache_age;
    int v10132 = v10131[v10195];
    int v10283 = v10132 + ((int)((unsigned int)(v10132 - v10128) >> 31));
    v10131[v10195] = v10283;
    int * v10134 = v10016->cache_age;
    v10134[v10280] = 0;
    v10180 = v10280;
  } else {
    int * v10137 = v10016->cache_age;
    int v10287 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2);
    int v10138 = v10137[v10287];
    int * v10139 = v10016->cache_tags;
    int v10140 = v10139[v10287];
    int v10141 = v10137[v10195];
    int v10142 = v10139[v10195];
    int * v10143 = v10016->cache_dirty;
    int v10290 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10138 + ((~(((v10140 ^ -1) | (-(v10140 ^ -1))) >> 31)) & 2)) - (v10141 + ((~(((v10142 ^ -1) | (-(v10142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10144 = v10143[v10290];
    bool v10291 = !(v10144 == 0);
    if (v10291) {
      int * v10145 = v10016->cache_tags;
      int v10146 = v10145[v10290];
      int * v10147 = v10016->cache_vals;
      int v10294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10138 + ((~(((v10140 ^ -1) | (-(v10140 ^ -1))) >> 31)) & 2)) - (v10141 + ((~(((v10142 ^ -1) | (-(v10142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10148 = v10147[v10294];
      int v10295 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10138 + ((~(((v10140 ^ -1) | (-(v10140 ^ -1))) >> 31)) & 2)) - (v10141 + ((~(((v10142 ^ -1) | (-(v10142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10149 = v10147[v10295];
      int * v10150 = v10016->mem;
      int v10297 = v10146 * 2;
      v10150[v10297] = v10148;
      int * v10152 = v10016->mem;
      int v10300 = (v10146 * 2) + 1;
      v10152[v10300] = v10149;
      ;
    } else {
      ;
    }
    int * v10157 = v10016->mem;
    int v10305 = ((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) * 2;
    int v10158 = v10157[v10305];
    int v10306 = (((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) * 2) + 1;
    int v10159 = v10157[v10306];
    int * v10160 = v10016->cache_vals;
    int v10308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10138 + ((~(((v10140 ^ -1) | (-(v10140 ^ -1))) >> 31)) & 2)) - (v10141 + ((~(((v10142 ^ -1) | (-(v10142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10160[v10308] = v10158;
    int * v10162 = v10016->cache_vals;
    int v10311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v10138 + ((~(((v10140 ^ -1) | (-(v10140 ^ -1))) >> 31)) & 2)) - (v10141 + ((~(((v10142 ^ -1) | (-(v10142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10162[v10311] = v10159;
    int * v10164 = v10016->cache_tags;
    int v10314 = (int)((unsigned int)((int)((unsigned int)(v10020 + 36) >> 2)) >> 1);
    v10164[v10290] = v10314;
    int * v10166 = v10016->cache_dirty;
    v10166[v10290] = 0;
    int * v10168 = v10016->cache_age;
    v10168[v10290] = 1;
    int * v10170 = v10016->cache_age;
    int v10171 = v10170[v10290];
    int v10172 = v10170[v10194];
    int v10320 = v10172 + ((int)((unsigned int)(v10172 - v10171) >> 31));
    v10170[v10194] = v10320;
    int * v10174 = v10016->cache_age;
    int v10175 = v10174[v10195];
    int v10322 = v10175 + ((int)((unsigned int)(v10175 - v10171) >> 31));
    v10174[v10195] = v10322;
    int * v10177 = v10016->cache_age;
    v10177[v10290] = 0;
    v10180 = v10290;
  }
  int * v10181 = v10016->cache_vals;
  int v10325 = (v10180 * 2) + (((int)((unsigned int)(v10020 + 36) >> 2)) & 1);
  v10181[v10325] = v10021;
  int * v10183 = v10016->cache_dirty;
  v10183[v10180] = 1;
  struct StateT * v10185 = slot_209(v10016);
  return v10185;
}

struct StateT * slot_172(struct StateT * v8484) {
  int v8485 = v8484->timer;
  int v8497 = v8485 + 1;
  v8484->timer = v8497;
  int * v8487 = v8484->regs;
  int v8488 = v8487[11];
  int v8489 = v8487[12];
  bool v8501 = (v8488 ^ -2147483648) < (v8489 ^ -2147483648);
  int v8492;
  if (v8501) {
    v8492 = 1;
  } else {
    v8492 = 0;
  }
  int * v8493 = v8484->regs;
  v8493[5] = v8492;
  struct StateT * v8495 = slot_173(v8484);
  return v8495;
}

struct StateT * slot_131(struct StateT * v6783) {
  int v6784 = v6783->timer;
  int v6792 = v6784 + 1;
  v6783->timer = v6792;
  int * v6786 = v6783->regs;
  int v6787 = v6786[31];
  int v6788 = v6786[29];
  int v6796 = v6787 + v6788;
  v6786[29] = v6796;
  struct StateT * v6790 = slot_132(v6783);
  return v6790;
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

struct StateT * slot_180(struct StateT * v8640) {
  int v8641 = v8640->timer;
  int v8653 = v8641 + 1;
  v8640->timer = v8653;
  int * v8643 = v8640->regs;
  int v8644 = v8643[12];
  int v8645 = v8643[8];
  bool v8657 = (v8644 ^ -2147483648) < (v8645 ^ -2147483648);
  int v8648;
  if (v8657) {
    v8648 = 1;
  } else {
    v8648 = 0;
  }
  int * v8649 = v8640->regs;
  v8649[28] = v8648;
  struct StateT * v8651 = slot_181(v8640);
  return v8651;
}

struct StateT * slot_203(struct StateT * v9039) {
  int v9040 = v9039->timer;
  int v9048 = v9040 + 1;
  v9039->timer = v9048;
  int * v9042 = v9039->regs;
  int v9043 = v9042[15];
  int v9044 = v9042[12];
  int v9052 = v9043 + v9044;
  v9042[12] = v9052;
  struct StateT * v9046 = slot_204(v9039);
  return v9046;
}

struct StateT * slot_190(struct StateT * v8830) {
  int v8831 = v8830->timer;
  int v8839 = v8831 + 1;
  v8830->timer = v8839;
  int * v8833 = v8830->regs;
  int v8834 = v8833[13];
  int v8835 = v8833[12];
  int v8843 = v8834 + v8835;
  v8833[12] = v8843;
  struct StateT * v8837 = slot_191(v8830);
  return v8837;
}

struct StateT * slot_157(struct StateT * v8229) {
  int v8230 = v8229->timer;
  int v8238 = v8230 + 1;
  v8229->timer = v8238;
  int * v8232 = v8229->regs;
  int v8233 = v8232[7];
  int v8234 = v8232[28];
  int v8242 = v8233 | v8234;
  v8232[7] = v8242;
  struct StateT * v8236 = slot_158(v8229);
  return v8236;
}

struct StateT * slot_200(struct StateT * v8983) {
  int v8984 = v8983->timer;
  int v8992 = v8984 + 1;
  v8983->timer = v8992;
  int * v8986 = v8983->regs;
  int v8987 = v8986[14];
  int v8988 = v8986[13];
  int v8996 = v8987 + v8988;
  v8986[13] = v8996;
  struct StateT * v8990 = slot_201(v8983);
  return v8990;
}

struct StateT * slot_173(struct StateT * v8509) {
  int v8510 = v8509->timer;
  int v8518 = v8510 + 1;
  v8509->timer = v8518;
  int * v8512 = v8509->regs;
  int v8513 = v8512[29];
  int v8514 = v8512[7];
  int v8522 = v8513 + v8514;
  v8512[7] = v8522;
  struct StateT * v8516 = slot_174(v8509);
  return v8516;
}

struct StateT * slot_149(struct StateT * v7123) {
  int v7124 = v7123->timer;
  int v7136 = v7124 + 1;
  v7123->timer = v7136;
  int * v7126 = v7123->regs;
  int v7127 = v7126[28];
  int v7128 = v7126[5];
  bool v7140 = (v7127 ^ -2147483648) < (v7128 ^ -2147483648);
  int v7131;
  if (v7140) {
    v7131 = 1;
  } else {
    v7131 = 0;
  }
  int * v7132 = v7123->regs;
  v7132[5] = v7131;
  struct StateT * v7134 = slot_150(v7123);
  return v7134;
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

struct StateT * slot_104(struct StateT * v5342) {
  int v5343 = v5342->timer;
  int v5354 = v5343 + 1;
  v5342->timer = v5354;
  int * v5345 = v5342->regs;
  int v5346 = v5345[7];
  int v5347 = v5345[29];
  bool v5358 = v5346 == v5347;
  struct StateT * v5352;
  if (v5358) {
    struct StateT * v5348 = slot_106(v5342);
    v5352 = v5348;
  } else {
    struct StateT * v5350 = slot_105(v5342);
    v5352 = v5350;
  }
  return v5352;
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

struct StateT * slot_206(struct StateT * v9386) {
  int v9387 = v9386->timer;
  int v9557 = v9387 + 1;
  v9386->timer = v9557;
  int * v9389 = v9386->regs;
  int v9390 = v9389[10];
  int v9391 = v9389[12];
  int * v9392 = v9386->cache_tags;
  int v9562 = (((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2;
  int v9393 = v9392[v9562];
  int v9563 = ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9394 = v9392[v9563];
  int v9564 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2);
  int v9395 = v9392[v9564];
  int v9565 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9396 = v9392[v9565];
  int v9397 = v9386->timer;
  int v9566 = v9397 + ((100 ^ (((~(((v9395 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9395 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9393 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9393 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9394 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9394 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9395 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9395 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9386->timer = v9566;
  bool v9567 = !(((~(((v9393 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9393 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9394 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9394 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v9491;
  if (v9567) {
    int * v9399 = v9386->cache_age;
    int v9569 = ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v9394 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9394 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v9400 = v9399[v9569];
    int v9401 = v9399[v9562];
    int v9570 = v9401 + ((int)((unsigned int)(v9401 - v9400) >> 31));
    v9399[v9562] = v9570;
    int * v9403 = v9386->cache_age;
    int v9404 = v9403[v9563];
    int v9572 = v9404 + ((int)((unsigned int)(v9404 - v9400) >> 31));
    v9403[v9563] = v9572;
    int * v9406 = v9386->cache_age;
    v9406[v9569] = 0;
    v9491 = v9569;
  } else {
    int * v9409 = v9386->cache_age;
    int v9576 = (((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2;
    int v9410 = v9409[v9576];
    int * v9411 = v9386->cache_tags;
    int v9412 = v9411[v9576];
    int v9413 = v9409[v9563];
    int v9414 = v9411[v9563];
    bool v9578 = !(((~(((v9395 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9395 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v9468;
    if (v9578) {
      int * v9415 = v9386->cache_age;
      int v9580 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9396 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v9416 = v9415[v9580];
      int v9417 = v9415[v9564];
      int v9581 = v9417 + ((int)((unsigned int)(v9417 - v9416) >> 31));
      v9415[v9564] = v9581;
      int * v9419 = v9386->cache_age;
      int v9420 = v9419[v9565];
      int v9583 = v9420 + ((int)((unsigned int)(v9420 - v9416) >> 31));
      v9419[v9565] = v9583;
      int * v9422 = v9386->cache_age;
      v9422[v9580] = 0;
      v9468 = v9580;
    } else {
      int * v9425 = v9386->cache_age;
      int v9587 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2);
      int v9426 = v9425[v9587];
      int * v9427 = v9386->cache_tags;
      int v9428 = v9427[v9587];
      int v9429 = v9425[v9565];
      int v9430 = v9427[v9565];
      int * v9431 = v9386->cache_dirty;
      int v9590 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9426 + ((~(((v9428 ^ -1) | (-(v9428 ^ -1))) >> 31)) & 2)) - (v9429 + ((~(((v9430 ^ -1) | (-(v9430 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9432 = v9431[v9590];
      bool v9591 = !(v9432 == 0);
      if (v9591) {
        int * v9433 = v9386->cache_tags;
        int v9434 = v9433[v9590];
        int * v9435 = v9386->cache_vals;
        int v9594 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9426 + ((~(((v9428 ^ -1) | (-(v9428 ^ -1))) >> 31)) & 2)) - (v9429 + ((~(((v9430 ^ -1) | (-(v9430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9436 = v9435[v9594];
        int v9595 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9426 + ((~(((v9428 ^ -1) | (-(v9428 ^ -1))) >> 31)) & 2)) - (v9429 + ((~(((v9430 ^ -1) | (-(v9430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9437 = v9435[v9595];
        int * v9438 = v9386->mem;
        int v9597 = v9434 * 2;
        v9438[v9597] = v9436;
        int * v9440 = v9386->mem;
        int v9600 = (v9434 * 2) + 1;
        v9440[v9600] = v9437;
        ;
      } else {
        ;
      }
      int * v9445 = v9386->mem;
      int v9605 = ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) * 2;
      int v9446 = v9445[v9605];
      int v9606 = (((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) * 2) + 1;
      int v9447 = v9445[v9606];
      int * v9448 = v9386->cache_vals;
      int v9608 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9426 + ((~(((v9428 ^ -1) | (-(v9428 ^ -1))) >> 31)) & 2)) - (v9429 + ((~(((v9430 ^ -1) | (-(v9430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9448[v9608] = v9446;
      int * v9450 = v9386->cache_vals;
      int v9611 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9426 + ((~(((v9428 ^ -1) | (-(v9428 ^ -1))) >> 31)) & 2)) - (v9429 + ((~(((v9430 ^ -1) | (-(v9430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9450[v9611] = v9447;
      int * v9452 = v9386->cache_tags;
      int v9614 = (int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1);
      v9452[v9590] = v9614;
      int * v9454 = v9386->cache_dirty;
      v9454[v9590] = 0;
      int * v9456 = v9386->cache_age;
      v9456[v9590] = 1;
      int * v9458 = v9386->cache_age;
      int v9459 = v9458[v9590];
      int v9460 = v9458[v9564];
      int v9620 = v9460 + ((int)((unsigned int)(v9460 - v9459) >> 31));
      v9458[v9564] = v9620;
      int * v9462 = v9386->cache_age;
      int v9463 = v9462[v9565];
      int v9622 = v9463 + ((int)((unsigned int)(v9463 - v9459) >> 31));
      v9462[v9565] = v9622;
      int * v9465 = v9386->cache_age;
      v9465[v9590] = 0;
      v9468 = v9590;
    }
    int * v9469 = v9386->cache_vals;
    int v9625 = v9468 * 2;
    int v9470 = v9469[v9625];
    int v9626 = (v9468 * 2) + 1;
    int v9471 = v9469[v9626];
    int v9627 = (((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9410 + ((~(((v9412 ^ -1) | (-(v9412 ^ -1))) >> 31)) & 2)) - (v9413 + ((~(((v9414 ^ -1) | (-(v9414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9469[v9627] = v9470;
    int * v9473 = v9386->cache_vals;
    int v9630 = ((((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9410 + ((~(((v9412 ^ -1) | (-(v9412 ^ -1))) >> 31)) & 2)) - (v9413 + ((~(((v9414 ^ -1) | (-(v9414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9473[v9630] = v9471;
    int * v9475 = v9386->cache_tags;
    int v9633 = ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9410 + ((~(((v9412 ^ -1) | (-(v9412 ^ -1))) >> 31)) & 2)) - (v9413 + ((~(((v9414 ^ -1) | (-(v9414 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9634 = (int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1);
    v9475[v9633] = v9634;
    int * v9477 = v9386->cache_dirty;
    v9477[v9633] = 0;
    int * v9479 = v9386->cache_age;
    v9479[v9633] = 1;
    int * v9481 = v9386->cache_age;
    int v9482 = v9481[v9633];
    int v9483 = v9481[v9562];
    int v9640 = v9483 + ((int)((unsigned int)(v9483 - v9482) >> 31));
    v9481[v9562] = v9640;
    int * v9485 = v9386->cache_age;
    int v9486 = v9485[v9563];
    int v9642 = v9486 + ((int)((unsigned int)(v9486 - v9482) >> 31));
    v9485[v9563] = v9642;
    int * v9488 = v9386->cache_age;
    v9488[v9633] = 0;
    v9491 = v9633;
  }
  int * v9492 = v9386->cache_vals;
  int v9645 = (v9491 * 2) + (((int)((unsigned int)(v9390 + 4) >> 2)) & 1);
  v9492[v9645] = v9391;
  int * v9494 = v9386->cache_tags;
  int v9495 = v9494[v9564];
  int v9496 = v9494[v9565];
  bool v9648 = !(((~(((v9495 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9495 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9496 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9496 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v9550;
  if (v9648) {
    int * v9497 = v9386->cache_age;
    int v9650 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9496 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))) | (-(v9496 ^ ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v9498 = v9497[v9650];
    int v9499 = v9497[v9564];
    int v9651 = v9499 + ((int)((unsigned int)(v9499 - v9498) >> 31));
    v9497[v9564] = v9651;
    int * v9501 = v9386->cache_age;
    int v9502 = v9501[v9565];
    int v9653 = v9502 + ((int)((unsigned int)(v9502 - v9498) >> 31));
    v9501[v9565] = v9653;
    int * v9504 = v9386->cache_age;
    v9504[v9650] = 0;
    v9550 = v9650;
  } else {
    int * v9507 = v9386->cache_age;
    int v9657 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2);
    int v9508 = v9507[v9657];
    int * v9509 = v9386->cache_tags;
    int v9510 = v9509[v9657];
    int v9511 = v9507[v9565];
    int v9512 = v9509[v9565];
    int * v9513 = v9386->cache_dirty;
    int v9660 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9508 + ((~(((v9510 ^ -1) | (-(v9510 ^ -1))) >> 31)) & 2)) - (v9511 + ((~(((v9512 ^ -1) | (-(v9512 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9514 = v9513[v9660];
    bool v9661 = !(v9514 == 0);
    if (v9661) {
      int * v9515 = v9386->cache_tags;
      int v9516 = v9515[v9660];
      int * v9517 = v9386->cache_vals;
      int v9664 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9508 + ((~(((v9510 ^ -1) | (-(v9510 ^ -1))) >> 31)) & 2)) - (v9511 + ((~(((v9512 ^ -1) | (-(v9512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9518 = v9517[v9664];
      int v9665 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9508 + ((~(((v9510 ^ -1) | (-(v9510 ^ -1))) >> 31)) & 2)) - (v9511 + ((~(((v9512 ^ -1) | (-(v9512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9519 = v9517[v9665];
      int * v9520 = v9386->mem;
      int v9667 = v9516 * 2;
      v9520[v9667] = v9518;
      int * v9522 = v9386->mem;
      int v9670 = (v9516 * 2) + 1;
      v9522[v9670] = v9519;
      ;
    } else {
      ;
    }
    int * v9527 = v9386->mem;
    int v9675 = ((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) * 2;
    int v9528 = v9527[v9675];
    int v9676 = (((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) * 2) + 1;
    int v9529 = v9527[v9676];
    int * v9530 = v9386->cache_vals;
    int v9678 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9508 + ((~(((v9510 ^ -1) | (-(v9510 ^ -1))) >> 31)) & 2)) - (v9511 + ((~(((v9512 ^ -1) | (-(v9512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9530[v9678] = v9528;
    int * v9532 = v9386->cache_vals;
    int v9681 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9508 + ((~(((v9510 ^ -1) | (-(v9510 ^ -1))) >> 31)) & 2)) - (v9511 + ((~(((v9512 ^ -1) | (-(v9512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9532[v9681] = v9529;
    int * v9534 = v9386->cache_tags;
    int v9684 = (int)((unsigned int)((int)((unsigned int)(v9390 + 4) >> 2)) >> 1);
    v9534[v9660] = v9684;
    int * v9536 = v9386->cache_dirty;
    v9536[v9660] = 0;
    int * v9538 = v9386->cache_age;
    v9538[v9660] = 1;
    int * v9540 = v9386->cache_age;
    int v9541 = v9540[v9660];
    int v9542 = v9540[v9564];
    int v9690 = v9542 + ((int)((unsigned int)(v9542 - v9541) >> 31));
    v9540[v9564] = v9690;
    int * v9544 = v9386->cache_age;
    int v9545 = v9544[v9565];
    int v9692 = v9545 + ((int)((unsigned int)(v9545 - v9541) >> 31));
    v9544[v9565] = v9692;
    int * v9547 = v9386->cache_age;
    v9547[v9660] = 0;
    v9550 = v9660;
  }
  int * v9551 = v9386->cache_vals;
  int v9695 = (v9550 * 2) + (((int)((unsigned int)(v9390 + 4) >> 2)) & 1);
  v9551[v9695] = v9391;
  int * v9553 = v9386->cache_dirty;
  v9553[v9550] = 1;
  struct StateT * v9555 = slot_207(v9386);
  return v9555;
}

struct StateT * slot_169(struct StateT * v8425) {
  int v8426 = v8425->timer;
  int v8434 = v8426 + 1;
  v8425->timer = v8434;
  int * v8428 = v8425->regs;
  int v8429 = v8428[12];
  int v8430 = v8428[7];
  int v8439 = v8429 + v8430;
  v8428[11] = v8439;
  struct StateT * v8432 = slot_170(v8425);
  return v8432;
}

struct StateT * slot_64(struct StateT * v3655) {
  int v3656 = v3655->timer;
  int v3667 = v3656 + 1;
  v3655->timer = v3667;
  int * v3658 = v3655->regs;
  int v3659 = v3658[7];
  int v3660 = v3658[29];
  bool v3671 = v3659 == v3660;
  struct StateT * v3665;
  if (v3671) {
    struct StateT * v3661 = slot_66(v3655);
    v3665 = v3661;
  } else {
    struct StateT * v3663 = slot_65(v3655);
    v3665 = v3663;
  }
  return v3665;
}

struct StateT * slot_170(struct StateT * v8442) {
  int v8443 = v8442->timer;
  int v8455 = v8443 + 1;
  v8442->timer = v8455;
  int * v8445 = v8442->regs;
  int v8446 = v8445[5];
  int v8447 = v8445[28];
  bool v8459 = (v8446 ^ -2147483648) < (v8447 ^ -2147483648);
  int v8450;
  if (v8459) {
    v8450 = 1;
  } else {
    v8450 = 0;
  }
  int * v8451 = v8442->regs;
  v8451[7] = v8450;
  struct StateT * v8453 = slot_171(v8442);
  return v8453;
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

struct StateT * slot_80(struct StateT * v4902) {
  int v4903 = v4902->timer;
  int v4911 = v4903 + 1;
  v4902->timer = v4911;
  int * v4905 = v4902->regs;
  int v4906 = v4905[6];
  int v4907 = v4905[12];
  int v4916 = (((((int)((unsigned int)v4906 >> 16)) * ((int)((unsigned int)v4907 >> 16))) + ((int)((unsigned int)((v4906 & 65535) * ((int)((unsigned int)v4907 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4906 >> 16)) * (v4907 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4906 & 65535) * (v4907 & 65535)) >> 16)) + (((v4906 & 65535) * ((int)((unsigned int)v4907 >> 16))) & 65535)) + ((((int)((unsigned int)v4906 >> 16)) * (v4907 & 65535)) & 65535)) >> 16));
  v4905[17] = v4916;
  struct StateT * v4909 = slot_81(v4902);
  return v4909;
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

struct StateT * slot_137(struct StateT * v6898) {
  int v6899 = v6898->timer;
  int v6907 = v6899 + 1;
  v6898->timer = v6907;
  int * v6901 = v6898->regs;
  int v6902 = v6901[7];
  int v6903 = v6901[6];
  int v6911 = v6902 + v6903;
  v6901[6] = v6911;
  struct StateT * v6905 = slot_138(v6898);
  return v6905;
}

struct StateT * slot_122(struct StateT * v6623) {
  int v6624 = v6623->timer;
  int v6632 = v6624 + 1;
  v6623->timer = v6632;
  int * v6626 = v6623->regs;
  int v6627 = v6626[29];
  int v6628 = v6626[12];
  int v6637 = (((((int)((unsigned int)v6627 >> 16)) * ((int)((unsigned int)v6628 >> 16))) + ((int)((unsigned int)((v6627 & 65535) * ((int)((unsigned int)v6628 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6627 >> 16)) * (v6628 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6627 & 65535) * (v6628 & 65535)) >> 16)) + (((v6627 & 65535) * ((int)((unsigned int)v6628 >> 16))) & 65535)) + ((((int)((unsigned int)v6627 >> 16)) * (v6628 & 65535)) & 65535)) >> 16));
  v6626[30] = v6637;
  struct StateT * v6630 = slot_123(v6623);
  return v6630;
}

struct StateT * slot_99(struct StateT * v5244) {
  int v5245 = v5244->timer;
  int v5257 = v5245 + 1;
  v5244->timer = v5257;
  int * v5247 = v5244->regs;
  int v5248 = v5247[6];
  int v5249 = v5247[7];
  bool v5261 = (v5248 ^ -2147483648) < (v5249 ^ -2147483648);
  int v5252;
  if (v5261) {
    v5252 = 1;
  } else {
    v5252 = 0;
  }
  int * v5253 = v5244->regs;
  v5253[6] = v5252;
  struct StateT * v5255 = slot_100(v5244);
  return v5255;
}

struct StateT * slot_179(struct StateT * v8616) {
  int v8617 = v8616->timer;
  int v8629 = v8617 + 1;
  v8616->timer = v8629;
  int * v8619 = v8616->regs;
  int v8620 = v8619[28];
  int v8621 = v8619[7];
  bool v8633 = (v8620 ^ -2147483648) < (v8621 ^ -2147483648);
  int v8624;
  if (v8633) {
    v8624 = 1;
  } else {
    v8624 = 0;
  }
  int * v8625 = v8616->regs;
  v8625[7] = v8624;
  struct StateT * v8627 = slot_180(v8616);
  return v8627;
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

struct StateT * slot_139(struct StateT * v6931) {
  int v6932 = v6931->timer;
  int v6944 = v6932 + 1;
  v6931->timer = v6944;
  int * v6934 = v6931->regs;
  int v6935 = v6934[6];
  int v6936 = v6934[7];
  bool v6948 = (v6935 ^ -2147483648) < (v6936 ^ -2147483648);
  int v6939;
  if (v6948) {
    v6939 = 1;
  } else {
    v6939 = 0;
  }
  int * v6940 = v6931->regs;
  v6940[6] = v6939;
  struct StateT * v6942 = slot_140(v6931);
  return v6942;
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

struct StateT * slot_153(struct StateT * v7792) {
  int v7793 = v7792->timer;
  int v7800 = v7793 + 1;
  v7792->timer = v7800;
  int * v7795 = v7792->regs;
  int v7796 = v7795[28];
  int v7803 = v7796 << 13;
  v7795[28] = v7803;
  struct StateT * v7798 = slot_154(v7792);
  return v7798;
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

struct StateT * slot_86(struct StateT * v5004) {
  int v5005 = v5004->timer;
  int v5013 = v5005 + 1;
  v5004->timer = v5013;
  int * v5007 = v5004->regs;
  int v5008 = v5007[29];
  int v5009 = v5007[13];
  int v5018 = (((((int)((unsigned int)v5008 >> 16)) * ((int)((unsigned int)v5009 >> 16))) + ((int)((unsigned int)((v5008 & 65535) * ((int)((unsigned int)v5009 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v5008 >> 16)) * (v5009 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v5008 & 65535) * (v5009 & 65535)) >> 16)) + (((v5008 & 65535) * ((int)((unsigned int)v5009 >> 16))) & 65535)) + ((((int)((unsigned int)v5008 >> 16)) * (v5009 & 65535)) & 65535)) >> 16));
  v5007[18] = v5018;
  struct StateT * v5011 = slot_87(v5004);
  return v5011;
}

struct StateT * slot_129(struct StateT * v6741) {
  int v6742 = v6741->timer;
  int v6750 = v6742 + 1;
  v6741->timer = v6750;
  int * v6744 = v6741->regs;
  int v6745 = v6744[6];
  int v6746 = v6744[7];
  int v6755 = v6745 + v6746;
  v6744[17] = v6755;
  struct StateT * v6748 = slot_130(v6741);
  return v6748;
}

struct StateT * slot_158(struct StateT * v8245) {
  int v8246 = v8245->timer;
  int v8253 = v8246 + 1;
  v8245->timer = v8253;
  int * v8248 = v8245->regs;
  int v8249 = v8248[5];
  int v8256 = v8249 << 13;
  v8248[5] = v8256;
  struct StateT * v8251 = slot_159(v8245);
  return v8251;
}

struct StateT * slot_100(struct StateT * v5268) {
  int v5269 = v5268->timer;
  int v5281 = v5269 + 1;
  v5268->timer = v5281;
  int * v5271 = v5268->regs;
  int v5272 = v5271[5];
  int v5273 = v5271[9];
  bool v5285 = (v5272 ^ -2147483648) < (v5273 ^ -2147483648);
  int v5276;
  if (v5285) {
    v5276 = 1;
  } else {
    v5276 = 0;
  }
  int * v5277 = v5268->regs;
  v5277[31] = v5276;
  struct StateT * v5279 = slot_101(v5268);
  return v5279;
}

struct StateT * slot_127(struct StateT * v6708) {
  int v6709 = v6708->timer;
  int v6717 = v6709 + 1;
  v6708->timer = v6717;
  int * v6711 = v6708->regs;
  int v6712 = v6711[6];
  int v6713 = v6711[12];
  int v6721 = v6712 * v6713;
  v6711[6] = v6721;
  struct StateT * v6715 = slot_128(v6708);
  return v6715;
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

struct StateT * slot_111(struct StateT * v5775) {
  int v5776 = v5775->timer;
  int v5946 = v5776 + 1;
  v5775->timer = v5946;
  int * v5778 = v5775->regs;
  int v5779 = v5778[10];
  int v5780 = v5778[29];
  int * v5781 = v5775->cache_tags;
  int v5951 = (((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2;
  int v5782 = v5781[v5951];
  int v5952 = ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5783 = v5781[v5952];
  int v5953 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2);
  int v5784 = v5781[v5953];
  int v5954 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5785 = v5781[v5954];
  int v5786 = v5775->timer;
  int v5955 = v5786 + ((100 ^ (((~(((v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5775->timer = v5955;
  bool v5956 = !(((~(((v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5880;
  if (v5956) {
    int * v5788 = v5775->cache_age;
    int v5958 = ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5789 = v5788[v5958];
    int v5790 = v5788[v5951];
    int v5959 = v5790 + ((int)((unsigned int)(v5790 - v5789) >> 31));
    v5788[v5951] = v5959;
    int * v5792 = v5775->cache_age;
    int v5793 = v5792[v5952];
    int v5961 = v5793 + ((int)((unsigned int)(v5793 - v5789) >> 31));
    v5792[v5952] = v5961;
    int * v5795 = v5775->cache_age;
    v5795[v5958] = 0;
    v5880 = v5958;
  } else {
    int * v5798 = v5775->cache_age;
    int v5965 = (((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2;
    int v5799 = v5798[v5965];
    int * v5800 = v5775->cache_tags;
    int v5801 = v5800[v5965];
    int v5802 = v5798[v5952];
    int v5803 = v5800[v5952];
    bool v5967 = !(((~(((v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v5857;
    if (v5967) {
      int * v5804 = v5775->cache_age;
      int v5969 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v5805 = v5804[v5969];
      int v5806 = v5804[v5953];
      int v5970 = v5806 + ((int)((unsigned int)(v5806 - v5805) >> 31));
      v5804[v5953] = v5970;
      int * v5808 = v5775->cache_age;
      int v5809 = v5808[v5954];
      int v5972 = v5809 + ((int)((unsigned int)(v5809 - v5805) >> 31));
      v5808[v5954] = v5972;
      int * v5811 = v5775->cache_age;
      v5811[v5969] = 0;
      v5857 = v5969;
    } else {
      int * v5814 = v5775->cache_age;
      int v5976 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2);
      int v5815 = v5814[v5976];
      int * v5816 = v5775->cache_tags;
      int v5817 = v5816[v5976];
      int v5818 = v5814[v5954];
      int v5819 = v5816[v5954];
      int * v5820 = v5775->cache_dirty;
      int v5979 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5815 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2)) - (v5818 + ((~(((v5819 ^ -1) | (-(v5819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5821 = v5820[v5979];
      bool v5980 = !(v5821 == 0);
      if (v5980) {
        int * v5822 = v5775->cache_tags;
        int v5823 = v5822[v5979];
        int * v5824 = v5775->cache_vals;
        int v5983 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5815 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2)) - (v5818 + ((~(((v5819 ^ -1) | (-(v5819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5825 = v5824[v5983];
        int v5984 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5815 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2)) - (v5818 + ((~(((v5819 ^ -1) | (-(v5819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5826 = v5824[v5984];
        int * v5827 = v5775->mem;
        int v5986 = v5823 * 2;
        v5827[v5986] = v5825;
        int * v5829 = v5775->mem;
        int v5989 = (v5823 * 2) + 1;
        v5829[v5989] = v5826;
        ;
      } else {
        ;
      }
      int * v5834 = v5775->mem;
      int v5994 = ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) * 2;
      int v5835 = v5834[v5994];
      int v5995 = (((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) * 2) + 1;
      int v5836 = v5834[v5995];
      int * v5837 = v5775->cache_vals;
      int v5997 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5815 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2)) - (v5818 + ((~(((v5819 ^ -1) | (-(v5819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5837[v5997] = v5835;
      int * v5839 = v5775->cache_vals;
      int v6000 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5815 + ((~(((v5817 ^ -1) | (-(v5817 ^ -1))) >> 31)) & 2)) - (v5818 + ((~(((v5819 ^ -1) | (-(v5819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5839[v6000] = v5836;
      int * v5841 = v5775->cache_tags;
      int v6003 = (int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1);
      v5841[v5979] = v6003;
      int * v5843 = v5775->cache_dirty;
      v5843[v5979] = 0;
      int * v5845 = v5775->cache_age;
      v5845[v5979] = 1;
      int * v5847 = v5775->cache_age;
      int v5848 = v5847[v5979];
      int v5849 = v5847[v5953];
      int v6009 = v5849 + ((int)((unsigned int)(v5849 - v5848) >> 31));
      v5847[v5953] = v6009;
      int * v5851 = v5775->cache_age;
      int v5852 = v5851[v5954];
      int v6011 = v5852 + ((int)((unsigned int)(v5852 - v5848) >> 31));
      v5851[v5954] = v6011;
      int * v5854 = v5775->cache_age;
      v5854[v5979] = 0;
      v5857 = v5979;
    }
    int * v5858 = v5775->cache_vals;
    int v6014 = v5857 * 2;
    int v5859 = v5858[v6014];
    int v6015 = (v5857 * 2) + 1;
    int v5860 = v5858[v6015];
    int v6016 = (((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5799 + ((~(((v5801 ^ -1) | (-(v5801 ^ -1))) >> 31)) & 2)) - (v5802 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5858[v6016] = v5859;
    int * v5862 = v5775->cache_vals;
    int v6019 = ((((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5799 + ((~(((v5801 ^ -1) | (-(v5801 ^ -1))) >> 31)) & 2)) - (v5802 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5862[v6019] = v5860;
    int * v5864 = v5775->cache_tags;
    int v6022 = ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5799 + ((~(((v5801 ^ -1) | (-(v5801 ^ -1))) >> 31)) & 2)) - (v5802 + ((~(((v5803 ^ -1) | (-(v5803 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6023 = (int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1);
    v5864[v6022] = v6023;
    int * v5866 = v5775->cache_dirty;
    v5866[v6022] = 0;
    int * v5868 = v5775->cache_age;
    v5868[v6022] = 1;
    int * v5870 = v5775->cache_age;
    int v5871 = v5870[v6022];
    int v5872 = v5870[v5951];
    int v6029 = v5872 + ((int)((unsigned int)(v5872 - v5871) >> 31));
    v5870[v5951] = v6029;
    int * v5874 = v5775->cache_age;
    int v5875 = v5874[v5952];
    int v6031 = v5875 + ((int)((unsigned int)(v5875 - v5871) >> 31));
    v5874[v5952] = v6031;
    int * v5877 = v5775->cache_age;
    v5877[v6022] = 0;
    v5880 = v6022;
  }
  int * v5881 = v5775->cache_vals;
  int v6034 = (v5880 * 2) + (((int)((unsigned int)(v5779 + 20) >> 2)) & 1);
  v5881[v6034] = v5780;
  int * v5883 = v5775->cache_tags;
  int v5884 = v5883[v5953];
  int v5885 = v5883[v5954];
  bool v6037 = !(((~(((v5884 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5884 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5885 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5885 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5939;
  if (v6037) {
    int * v5886 = v5775->cache_age;
    int v6039 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5885 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))) | (-(v5885 ^ ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5887 = v5886[v6039];
    int v5888 = v5886[v5953];
    int v6040 = v5888 + ((int)((unsigned int)(v5888 - v5887) >> 31));
    v5886[v5953] = v6040;
    int * v5890 = v5775->cache_age;
    int v5891 = v5890[v5954];
    int v6042 = v5891 + ((int)((unsigned int)(v5891 - v5887) >> 31));
    v5890[v5954] = v6042;
    int * v5893 = v5775->cache_age;
    v5893[v6039] = 0;
    v5939 = v6039;
  } else {
    int * v5896 = v5775->cache_age;
    int v6046 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2);
    int v5897 = v5896[v6046];
    int * v5898 = v5775->cache_tags;
    int v5899 = v5898[v6046];
    int v5900 = v5896[v5954];
    int v5901 = v5898[v5954];
    int * v5902 = v5775->cache_dirty;
    int v6049 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5897 + ((~(((v5899 ^ -1) | (-(v5899 ^ -1))) >> 31)) & 2)) - (v5900 + ((~(((v5901 ^ -1) | (-(v5901 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5903 = v5902[v6049];
    bool v6050 = !(v5903 == 0);
    if (v6050) {
      int * v5904 = v5775->cache_tags;
      int v5905 = v5904[v6049];
      int * v5906 = v5775->cache_vals;
      int v6053 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5897 + ((~(((v5899 ^ -1) | (-(v5899 ^ -1))) >> 31)) & 2)) - (v5900 + ((~(((v5901 ^ -1) | (-(v5901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5907 = v5906[v6053];
      int v6054 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5897 + ((~(((v5899 ^ -1) | (-(v5899 ^ -1))) >> 31)) & 2)) - (v5900 + ((~(((v5901 ^ -1) | (-(v5901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5908 = v5906[v6054];
      int * v5909 = v5775->mem;
      int v6056 = v5905 * 2;
      v5909[v6056] = v5907;
      int * v5911 = v5775->mem;
      int v6059 = (v5905 * 2) + 1;
      v5911[v6059] = v5908;
      ;
    } else {
      ;
    }
    int * v5916 = v5775->mem;
    int v6064 = ((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) * 2;
    int v5917 = v5916[v6064];
    int v6065 = (((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) * 2) + 1;
    int v5918 = v5916[v6065];
    int * v5919 = v5775->cache_vals;
    int v6067 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5897 + ((~(((v5899 ^ -1) | (-(v5899 ^ -1))) >> 31)) & 2)) - (v5900 + ((~(((v5901 ^ -1) | (-(v5901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5919[v6067] = v5917;
    int * v5921 = v5775->cache_vals;
    int v6070 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5897 + ((~(((v5899 ^ -1) | (-(v5899 ^ -1))) >> 31)) & 2)) - (v5900 + ((~(((v5901 ^ -1) | (-(v5901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5921[v6070] = v5918;
    int * v5923 = v5775->cache_tags;
    int v6073 = (int)((unsigned int)((int)((unsigned int)(v5779 + 20) >> 2)) >> 1);
    v5923[v6049] = v6073;
    int * v5925 = v5775->cache_dirty;
    v5925[v6049] = 0;
    int * v5927 = v5775->cache_age;
    v5927[v6049] = 1;
    int * v5929 = v5775->cache_age;
    int v5930 = v5929[v6049];
    int v5931 = v5929[v5953];
    int v6079 = v5931 + ((int)((unsigned int)(v5931 - v5930) >> 31));
    v5929[v5953] = v6079;
    int * v5933 = v5775->cache_age;
    int v5934 = v5933[v5954];
    int v6081 = v5934 + ((int)((unsigned int)(v5934 - v5930) >> 31));
    v5933[v5954] = v6081;
    int * v5936 = v5775->cache_age;
    v5936[v6049] = 0;
    v5939 = v6049;
  }
  int * v5940 = v5775->cache_vals;
  int v6084 = (v5939 * 2) + (((int)((unsigned int)(v5779 + 20) >> 2)) & 1);
  v5940[v6084] = v5780;
  int * v5942 = v5775->cache_dirty;
  v5942[v5939] = 1;
  struct StateT * v5944 = slot_112(v5775);
  return v5944;
}

struct StateT * slot_109(struct StateT * v5436) {
  int v5437 = v5436->timer;
  int v5449 = v5437 + 1;
  v5436->timer = v5449;
  int * v5439 = v5436->regs;
  int v5440 = v5439[28];
  int v5441 = v5439[5];
  bool v5453 = (v5440 ^ -2147483648) < (v5441 ^ -2147483648);
  int v5444;
  if (v5453) {
    v5444 = 1;
  } else {
    v5444 = 0;
  }
  int * v5445 = v5436->regs;
  v5445[5] = v5444;
  struct StateT * v5447 = slot_110(v5436);
  return v5447;
}

struct StateT * slot_174(struct StateT * v8525) {
  int v8526 = v8525->timer;
  int v8538 = v8526 + 1;
  v8525->timer = v8538;
  int * v8528 = v8525->regs;
  int v8529 = v8528[6];
  int v8530 = v8528[30];
  bool v8542 = (v8529 ^ -2147483648) < (v8530 ^ -2147483648);
  int v8533;
  if (v8542) {
    v8533 = 1;
  } else {
    v8533 = 0;
  }
  int * v8534 = v8525->regs;
  v8534[12] = v8533;
  struct StateT * v8536 = slot_175(v8525);
  return v8536;
}

struct StateT * slot_147(struct StateT * v7092) {
  int v7093 = v7092->timer;
  int v7101 = v7093 + 1;
  v7092->timer = v7101;
  int * v7095 = v7092->regs;
  int v7096 = v7095[7];
  int v7097 = v7095[16];
  int v7106 = v7096 & v7097;
  v7095[29] = v7106;
  struct StateT * v7099 = slot_148(v7092);
  return v7099;
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

struct StateT * slot_163(struct StateT * v8326) {
  int v8327 = v8326->timer;
  int v8335 = v8327 + 1;
  v8326->timer = v8335;
  int * v8329 = v8326->regs;
  int v8330 = v8329[6];
  int v8331 = v8329[13];
  int v8340 = v8330 * v8331;
  v8329[30] = v8340;
  struct StateT * v8333 = slot_164(v8326);
  return v8333;
}

struct StateT * slot_184(struct StateT * v8713) {
  int v8714 = v8713->timer;
  int v8725 = v8714 + 1;
  v8713->timer = v8725;
  int * v8716 = v8713->regs;
  int v8717 = v8716[17];
  int v8718 = v8716[6];
  bool v8729 = v8717 == v8718;
  struct StateT * v8723;
  if (v8729) {
    struct StateT * v8719 = slot_186(v8713);
    v8723 = v8719;
  } else {
    struct StateT * v8721 = slot_185(v8713);
    v8723 = v8721;
  }
  return v8723;
}

struct StateT * slot_204(struct StateT * v9055) {
  int v9056 = v9055->timer;
  int v9064 = v9056 + 1;
  v9055->timer = v9064;
  int * v9058 = v9055->regs;
  int v9059 = v9058[12];
  int v9060 = v9058[14];
  int v9068 = v9059 + v9060;
  v9058[12] = v9068;
  struct StateT * v9062 = slot_205(v9055);
  return v9062;
}

struct StateT * slot_194(struct StateT * v8890) {
  int v8891 = v8890->timer;
  int v8898 = v8891 + 1;
  v8890->timer = v8898;
  int * v8893 = v8890->regs;
  int v8894 = v8893[5];
  int v8901 = (int)((unsigned int)v8894 >> 19);
  v8893[5] = v8901;
  struct StateT * v8896 = slot_195(v8890);
  return v8896;
}

struct StateT * slot_165(struct StateT * v8360) {
  int v8361 = v8360->timer;
  int v8369 = v8361 + 1;
  v8360->timer = v8369;
  int * v8363 = v8360->regs;
  int v8364 = v8363[11];
  int v8365 = v8363[13];
  int v8374 = v8364 * v8365;
  v8363[8] = v8374;
  struct StateT * v8367 = slot_166(v8360);
  return v8367;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v6543) {
  int v6544 = v6543->timer;
  int v6552 = v6544 + 1;
  v6543->timer = v6552;
  int * v6546 = v6543->regs;
  int v6547 = v6546[7];
  int v6548 = v6546[28];
  int v6556 = v6547 | v6548;
  v6546[7] = v6556;
  struct StateT * v6550 = slot_118(v6543);
  return v6550;
}

struct StateT * slot_90(struct StateT * v5071) {
  int v5072 = v5071->timer;
  int v5084 = v5072 + 1;
  v5071->timer = v5084;
  int * v5074 = v5071->regs;
  int v5075 = v5074[29];
  int v5076 = v5074[28];
  bool v5088 = (v5075 ^ -2147483648) < (v5076 ^ -2147483648);
  int v5079;
  if (v5088) {
    v5079 = 1;
  } else {
    v5079 = 0;
  }
  int * v5080 = v5071->regs;
  v5080[7] = v5079;
  struct StateT * v5082 = slot_91(v5071);
  return v5082;
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