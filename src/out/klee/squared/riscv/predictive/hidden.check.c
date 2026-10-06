// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v1577);
struct StateT2 * slot_143(struct StateT2 * v6686);
struct StateT2 * slot_120(struct StateT2 * v5789);
struct StateT2 * slot_167(struct StateT2 * v7622);
struct StateT2 * slot_152(struct StateT2 * v7037);
struct StateT2 * slot_199(struct StateT2 * v8870);
struct StateT2 * slot_92(struct StateT2 * v4697);
struct StateT2 * slot_31(struct StateT2 * v2318);
struct StateT2 * slot_160(struct StateT2 * v7349);
struct StateT2 * slot_65(struct StateT2 * v3644);
struct StateT2 * slot_10(struct StateT2 * v1499);
struct StateT2 * slot_150(struct StateT2 * v6959);
struct StateT2 * slot_74(struct StateT2 * v3995);
struct StateT2 * slot_107(struct StateT2 * v5282);
struct StateT2 * slot_136(struct StateT2 * v6413);
struct StateT2 * slot_84(struct StateT2 * v4385);
struct StateT2 * slot_28(struct StateT2 * v2201);
struct StateT2 * slot_155(struct StateT2 * v7154);
struct StateT2 * slot_177(struct StateT2 * v8012);
struct StateT2 * slot_17(struct StateT2 * v1772);
struct StateT2 * slot_181(struct StateT2 * v8168);
struct StateT2 * slot_197(struct StateT2 * v8792);
struct StateT2 * slot_207(struct StateT2 * v9182);
struct StateT2 * slot_156(struct StateT2 * v7193);
struct StateT2 * slot_154(struct StateT2 * v7115);
struct StateT2 * slot_68(struct StateT2 * v3761);
struct StateT2 * slot_105(struct StateT2 * v5204);
struct StateT2 * slot_27(struct StateT2 * v2162);
struct StateT2 * slot_164(struct StateT2 * v7505);
struct StateT2 * slot_15(struct StateT2 * v1694);
struct StateT2 * slot_133(struct StateT2 * v6296);
struct StateT2 * slot_56(struct StateT2 * v3293);
struct StateT2 * slot_222(struct StateT2 * v9767);
struct StateT2 * slot_34(struct StateT2 * v2435);
struct StateT2 * slot_171(struct StateT2 * v7778);
struct StateT2 * slot_162(struct StateT2 * v7427);
struct StateT2 * slot_21(struct StateT2 * v1928);
struct StateT2 * slot_118(struct StateT2 * v5711);
struct StateT2 * slot_121(struct StateT2 * v5828);
struct StateT2 * slot_144(struct StateT2 * v6725);
struct StateT2 * slot_201(struct StateT2 * v8948);
struct StateT2 * slot_94(struct StateT2 * v4775);
struct StateT2 * slot_63(struct StateT2 * v3566);
struct StateT2 * slot_146(struct StateT2 * v6803);
struct StateT2 * slot_24(struct StateT2 * v2045);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_195(struct StateT2 * v8714);
struct StateT2 * slot_125(struct StateT2 * v5984);
struct StateT2 * slot_148(struct StateT2 * v6881);
struct StateT2 * slot_126(struct StateT2 * v6023);
struct StateT2 * slot_223(struct StateT2 * v9806);
struct StateT2 * slot_79(struct StateT2 * v4190);
struct StateT2 * slot_41(struct StateT2 * v2708);
struct StateT2 * slot_39(struct StateT2 * v2630);
struct StateT2 * slot_142(struct StateT2 * v6647);
struct StateT2 * slot_60(struct StateT2 * v3449);
struct StateT2 * slot_112(struct StateT2 * v5477);
struct StateT2 * slot_47(struct StateT2 * v2942);
struct StateT2 * slot_214(struct StateT2 * v9455);
struct StateT2 * slot_29(struct StateT2 * v2240);
struct StateT2 * slot_16(struct StateT2 * v1733);
struct StateT2 * slot_113(struct StateT2 * v5516);
struct StateT2 * slot_151(struct StateT2 * v6998);
struct StateT2 * slot_7(struct StateT2 * v1382);
struct StateT2 * slot_124(struct StateT2 * v5945);
struct StateT2 * slot_191(struct StateT2 * v8558);
struct StateT2 * slot_103(struct StateT2 * v5126);
struct StateT2 * slot_128(struct StateT2 * v6101);
struct StateT2 * slot_19(struct StateT2 * v1850);
struct StateT2 * slot_87(struct StateT2 * v4502);
struct StateT2 * slot_67(struct StateT2 * v3722);
struct StateT2 * slot_81(struct StateT2 * v4268);
struct StateT2 * slot_95(struct StateT2 * v4814);
struct StateT2 * slot_115(struct StateT2 * v5594);
struct StateT2 * slot_78(struct StateT2 * v4151);
struct StateT2 * slot_32(struct StateT2 * v2357);
struct StateT2 * slot_205(struct StateT2 * v9104);
struct StateT2 * slot_193(struct StateT2 * v8636);
struct StateT2 * slot_176(struct StateT2 * v7973);
struct StateT2 * slot_189(struct StateT2 * v8480);
struct StateT2 * slot_33(struct StateT2 * v2396);
struct StateT2 * slot_35(struct StateT2 * v2474);
struct StateT2 * slot_210(struct StateT2 * v9299);
struct StateT2 * slot_166(struct StateT2 * v7583);
struct StateT2 * slot_51(struct StateT2 * v3098);
struct StateT2 * slot_52(struct StateT2 * v3137);
struct StateT2 * slot_83(struct StateT2 * v4346);
struct StateT2 * slot_25(struct StateT2 * v2084);
struct StateT2 * slot_209(struct StateT2 * v9260);
struct StateT2 * slot_3(struct StateT2 * v850);
struct StateT2 * slot_123(struct StateT2 * v5906);
struct StateT2 * slot_73(struct StateT2 * v3956);
struct StateT2 * slot_198(struct StateT2 * v8831);
struct StateT2 * slot_1(struct StateT2 * v420);
struct StateT2 * slot_187(struct StateT2 * v8402);
struct StateT2 * slot_97(struct StateT2 * v4892);
struct StateT2 * slot_182(struct StateT2 * v8207);
struct StateT2 * slot_38(struct StateT2 * v2591);
struct StateT2 * slot_178(struct StateT2 * v8051);
struct StateT2 * slot_106(struct StateT2 * v5243);
struct StateT2 * slot_98(struct StateT2 * v4931);
struct StateT2 * slot_159(struct StateT2 * v7310);
struct StateT2 * slot_46(struct StateT2 * v2903);
struct StateT2 * slot_212(struct StateT2 * v9377);
struct StateT2 * slot_132(struct StateT2 * v6257);
struct StateT2 * slot_130(struct StateT2 * v6179);
struct StateT2 * slot_211(struct StateT2 * v9338);
struct StateT2 * slot_20(struct StateT2 * v1889);
struct StateT2 * slot_141(struct StateT2 * v6608);
struct StateT2 * slot_61(struct StateT2 * v3488);
struct StateT2 * slot_30(struct StateT2 * v2279);
struct StateT2 * slot_4(struct StateT2 * v889);
struct StateT2 * slot_18(struct StateT2 * v1811);
struct StateT2 * slot_9(struct StateT2 * v1460);
struct StateT2 * slot_183(struct StateT2 * v8246);
struct StateT2 * slot_43(struct StateT2 * v2786);
struct StateT2 * slot_70(struct StateT2 * v3839);
struct StateT2 * slot_168(struct StateT2 * v7661);
struct StateT2 * slot_76(struct StateT2 * v4073);
struct StateT2 * slot_6(struct StateT2 * v1343);
struct StateT2 * slot_225(struct StateT2 * v9884);
struct StateT2 * slot_55(struct StateT2 * v3254);
struct StateT2 * slot_213(struct StateT2 * v9416);
struct StateT2 * slot_82(struct StateT2 * v4307);
struct StateT2 * slot_161(struct StateT2 * v7388);
struct StateT2 * slot_185(struct StateT2 * v8324);
struct StateT2 * slot_91(struct StateT2 * v4658);
struct StateT2 * slot_58(struct StateT2 * v3371);
struct StateT2 * slot_89(struct StateT2 * v4580);
struct StateT2 * slot_66(struct StateT2 * v3683);
struct StateT2 * slot_140(struct StateT2 * v6569);
struct StateT2 * slot_49(struct StateT2 * v3020);
struct StateT2 * slot_216(struct StateT2 * v9533);
struct StateT2 * slot_50(struct StateT2 * v3059);
struct StateT2 * slot_37(struct StateT2 * v2552);
struct StateT2 * slot_114(struct StateT2 * v5555);
struct StateT2 * slot_135(struct StateT2 * v6374);
struct StateT2 * slot_59(struct StateT2 * v3410);
struct StateT2 * slot_192(struct StateT2 * v8597);
struct StateT2 * slot_40(struct StateT2 * v2669);
struct StateT2 * slot_48(struct StateT2 * v2981);
struct StateT2 * slot_77(struct StateT2 * v4112);
struct StateT2 * slot_85(struct StateT2 * v4424);
struct StateT2 * slot_75(struct StateT2 * v4034);
struct StateT2 * slot_72(struct StateT2 * v3917);
struct StateT2 * slot_119(struct StateT2 * v5750);
struct StateT2 * slot_71(struct StateT2 * v3878);
struct StateT2 * slot_101(struct StateT2 * v5048);
struct StateT2 * slot_108(struct StateT2 * v5321);
struct StateT2 * slot_116(struct StateT2 * v5633);
struct StateT2 * slot_93(struct StateT2 * v4736);
struct StateT2 * slot_88(struct StateT2 * v4541);
struct StateT2 * slot_96(struct StateT2 * v4853);
struct StateT2 * slot_215(struct StateT2 * v9494);
struct StateT2 * slot_45(struct StateT2 * v2864);
struct StateT2 * slot_218(struct StateT2 * v9611);
struct StateT2 * slot_220(struct StateT2 * v9689);
struct StateT2 * slot_134(struct StateT2 * v6335);
struct StateT2 * slot_175(struct StateT2 * v7934);
struct StateT2 * slot_69(struct StateT2 * v3800);
struct StateT2 * slot_202(struct StateT2 * v8987);
struct StateT2 * slot_188(struct StateT2 * v8441);
struct StateT2 * slot_138(struct StateT2 * v6491);
struct StateT2 * slot_186(struct StateT2 * v8363);
struct StateT2 * slot_102(struct StateT2 * v5087);
struct StateT2 * slot_145(struct StateT2 * v6764);
struct StateT2 * slot_110(struct StateT2 * v5399);
struct StateT2 * slot_196(struct StateT2 * v8753);
struct StateT2 * slot_208(struct StateT2 * v9221);
struct StateT2 * slot_172(struct StateT2 * v7817);
struct StateT2 * slot_131(struct StateT2 * v6218);
struct StateT2 * slot_8(struct StateT2 * v1421);
struct StateT2 * slot_180(struct StateT2 * v8129);
struct StateT2 * slot_203(struct StateT2 * v9026);
struct StateT2 * slot_190(struct StateT2 * v8519);
struct StateT2 * slot_157(struct StateT2 * v7232);
struct StateT2 * slot_200(struct StateT2 * v8909);
struct StateT2 * slot_173(struct StateT2 * v7856);
struct StateT2 * slot_149(struct StateT2 * v6920);
struct StateT2 * slot_5(struct StateT2 * v1307);
struct StateT2 * slot_104(struct StateT2 * v5165);
struct StateT2 * slot_54(struct StateT2 * v3215);
struct StateT2 * slot_26(struct StateT2 * v2123);
struct StateT2 * slot_206(struct StateT2 * v9143);
struct StateT2 * slot_169(struct StateT2 * v7700);
struct StateT2 * slot_64(struct StateT2 * v3605);
struct StateT2 * slot_170(struct StateT2 * v7739);
struct StateT2 * slot_14(struct StateT2 * v1655);
struct StateT2 * slot_53(struct StateT2 * v3176);
struct StateT2 * slot_80(struct StateT2 * v4229);
struct StateT2 * slot_44(struct StateT2 * v2825);
struct StateT2 * slot_137(struct StateT2 * v6452);
struct StateT2 * slot_122(struct StateT2 * v5867);
struct StateT2 * slot_99(struct StateT2 * v4970);
struct StateT2 * slot_179(struct StateT2 * v8090);
struct StateT2 * slot_219(struct StateT2 * v9650);
struct StateT2 * slot_36(struct StateT2 * v2513);
struct StateT2 * slot_57(struct StateT2 * v3332);
struct StateT2 * slot_62(struct StateT2 * v3527);
struct StateT2 * slot_22(struct StateT2 * v1967);
struct StateT2 * slot_139(struct StateT2 * v6530);
struct StateT2 * slot_221(struct StateT2 * v9728);
struct StateT2 * slot_23(struct StateT2 * v2006);
struct StateT2 * slot_153(struct StateT2 * v7076);
struct StateT2 * slot_2(struct StateT2 * v811);
struct StateT2 * slot_86(struct StateT2 * v4463);
struct StateT2 * slot_129(struct StateT2 * v6140);
struct StateT2 * slot_158(struct StateT2 * v7271);
struct StateT2 * slot_100(struct StateT2 * v5009);
struct StateT2 * slot_127(struct StateT2 * v6062);
struct StateT2 * slot_217(struct StateT2 * v9572);
struct StateT2 * slot_13(struct StateT2 * v1616);
struct StateT2 * slot_111(struct StateT2 * v5438);
struct StateT2 * slot_109(struct StateT2 * v5360);
struct StateT2 * slot_174(struct StateT2 * v7895);
struct StateT2 * slot_147(struct StateT2 * v6842);
struct StateT2 * slot_42(struct StateT2 * v2747);
struct StateT2 * slot_224(struct StateT2 * v9845);
struct StateT2 * slot_163(struct StateT2 * v7466);
struct StateT2 * slot_184(struct StateT2 * v8285);
struct StateT2 * slot_204(struct StateT2 * v9065);
struct StateT2 * slot_194(struct StateT2 * v8675);
struct StateT2 * slot_165(struct StateT2 * v7544);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_117(struct StateT2 * v5672);
struct StateT2 * slot_90(struct StateT2 * v4619);
struct StateT2 * slot_11(struct StateT2 * v1538);
struct StateT2 * slot_12(struct StateT2 * v1577) {
  struct StateT * v1578 = v1577->a;
  int v1579 = v1578->timer;
  struct StateT * v1580 = v1577->b;
  int v1581 = v1580->timer;
  bool v1602 = v1579 == v1581;
  squared_assert(v1602);
  squared_assume(v1602);
  struct StateT * v1584 = v1577->a;
  int v1585 = v1584->timer;
  int v1604 = v1585 + 1;
  v1584->timer = v1604;
  struct StateT * v1587 = v1577->b;
  int v1588 = v1587->timer;
  int v1606 = v1588 + 1;
  v1587->timer = v1606;
  struct StateT * v1590 = v1577->a;
  int * v1591 = v1590->regs;
  int v1592 = v1591[8];
  int v1610 = v1592 + 1;
  v1591[8] = v1610;
  struct StateT * v1594 = v1577->b;
  int * v1595 = v1594->regs;
  int v1596 = v1595[8];
  int v1613 = v1596 + 1;
  v1595[8] = v1613;
  struct StateT2 * v1598 = slot_13(v1577);
  return v1598;
}

struct StateT2 * slot_143(struct StateT2 * v6686) {
  struct StateT * v6687 = v6686->a;
  int v6688 = v6687->timer;
  struct StateT * v6689 = v6686->b;
  int v6690 = v6689->timer;
  bool v6711 = v6688 == v6690;
  squared_assert(v6711);
  squared_assume(v6711);
  struct StateT * v6693 = v6686->a;
  int v6694 = v6693->timer;
  int v6713 = v6694 + 1;
  v6693->timer = v6713;
  struct StateT * v6696 = v6686->b;
  int v6697 = v6696->timer;
  int v6715 = v6697 + 1;
  v6696->timer = v6715;
  struct StateT * v6699 = v6686->a;
  int * v6700 = v6699->regs;
  int v6701 = v6700[8];
  int v6719 = v6701 + 1;
  v6700[8] = v6719;
  struct StateT * v6703 = v6686->b;
  int * v6704 = v6703->regs;
  int v6705 = v6704[8];
  int v6722 = v6705 + 1;
  v6704[8] = v6722;
  struct StateT2 * v6707 = slot_144(v6686);
  return v6707;
}

struct StateT2 * slot_120(struct StateT2 * v5789) {
  struct StateT * v5790 = v5789->a;
  int v5791 = v5790->timer;
  struct StateT * v5792 = v5789->b;
  int v5793 = v5792->timer;
  bool v5814 = v5791 == v5793;
  squared_assert(v5814);
  squared_assume(v5814);
  struct StateT * v5796 = v5789->a;
  int v5797 = v5796->timer;
  int v5816 = v5797 + 1;
  v5796->timer = v5816;
  struct StateT * v5799 = v5789->b;
  int v5800 = v5799->timer;
  int v5818 = v5800 + 1;
  v5799->timer = v5818;
  struct StateT * v5802 = v5789->a;
  int * v5803 = v5802->regs;
  int v5804 = v5803[8];
  int v5822 = v5804 + 1;
  v5803[8] = v5822;
  struct StateT * v5806 = v5789->b;
  int * v5807 = v5806->regs;
  int v5808 = v5807[8];
  int v5825 = v5808 + 1;
  v5807[8] = v5825;
  struct StateT2 * v5810 = slot_121(v5789);
  return v5810;
}

struct StateT2 * slot_167(struct StateT2 * v7622) {
  struct StateT * v7623 = v7622->a;
  int v7624 = v7623->timer;
  struct StateT * v7625 = v7622->b;
  int v7626 = v7625->timer;
  bool v7647 = v7624 == v7626;
  squared_assert(v7647);
  squared_assume(v7647);
  struct StateT * v7629 = v7622->a;
  int v7630 = v7629->timer;
  int v7649 = v7630 + 1;
  v7629->timer = v7649;
  struct StateT * v7632 = v7622->b;
  int v7633 = v7632->timer;
  int v7651 = v7633 + 1;
  v7632->timer = v7651;
  struct StateT * v7635 = v7622->a;
  int * v7636 = v7635->regs;
  int v7637 = v7636[8];
  int v7655 = v7637 + 1;
  v7636[8] = v7655;
  struct StateT * v7639 = v7622->b;
  int * v7640 = v7639->regs;
  int v7641 = v7640[8];
  int v7658 = v7641 + 1;
  v7640[8] = v7658;
  struct StateT2 * v7643 = slot_168(v7622);
  return v7643;
}

struct StateT2 * slot_152(struct StateT2 * v7037) {
  struct StateT * v7038 = v7037->a;
  int v7039 = v7038->timer;
  struct StateT * v7040 = v7037->b;
  int v7041 = v7040->timer;
  bool v7062 = v7039 == v7041;
  squared_assert(v7062);
  squared_assume(v7062);
  struct StateT * v7044 = v7037->a;
  int v7045 = v7044->timer;
  int v7064 = v7045 + 1;
  v7044->timer = v7064;
  struct StateT * v7047 = v7037->b;
  int v7048 = v7047->timer;
  int v7066 = v7048 + 1;
  v7047->timer = v7066;
  struct StateT * v7050 = v7037->a;
  int * v7051 = v7050->regs;
  int v7052 = v7051[8];
  int v7070 = v7052 + 1;
  v7051[8] = v7070;
  struct StateT * v7054 = v7037->b;
  int * v7055 = v7054->regs;
  int v7056 = v7055[8];
  int v7073 = v7056 + 1;
  v7055[8] = v7073;
  struct StateT2 * v7058 = slot_153(v7037);
  return v7058;
}

struct StateT2 * slot_199(struct StateT2 * v8870) {
  struct StateT * v8871 = v8870->a;
  int v8872 = v8871->timer;
  struct StateT * v8873 = v8870->b;
  int v8874 = v8873->timer;
  bool v8895 = v8872 == v8874;
  squared_assert(v8895);
  squared_assume(v8895);
  struct StateT * v8877 = v8870->a;
  int v8878 = v8877->timer;
  int v8897 = v8878 + 1;
  v8877->timer = v8897;
  struct StateT * v8880 = v8870->b;
  int v8881 = v8880->timer;
  int v8899 = v8881 + 1;
  v8880->timer = v8899;
  struct StateT * v8883 = v8870->a;
  int * v8884 = v8883->regs;
  int v8885 = v8884[8];
  int v8903 = v8885 + 1;
  v8884[8] = v8903;
  struct StateT * v8887 = v8870->b;
  int * v8888 = v8887->regs;
  int v8889 = v8888[8];
  int v8906 = v8889 + 1;
  v8888[8] = v8906;
  struct StateT2 * v8891 = slot_200(v8870);
  return v8891;
}

struct StateT2 * slot_92(struct StateT2 * v4697) {
  struct StateT * v4698 = v4697->a;
  int v4699 = v4698->timer;
  struct StateT * v4700 = v4697->b;
  int v4701 = v4700->timer;
  bool v4722 = v4699 == v4701;
  squared_assert(v4722);
  squared_assume(v4722);
  struct StateT * v4704 = v4697->a;
  int v4705 = v4704->timer;
  int v4724 = v4705 + 1;
  v4704->timer = v4724;
  struct StateT * v4707 = v4697->b;
  int v4708 = v4707->timer;
  int v4726 = v4708 + 1;
  v4707->timer = v4726;
  struct StateT * v4710 = v4697->a;
  int * v4711 = v4710->regs;
  int v4712 = v4711[8];
  int v4730 = v4712 + 1;
  v4711[8] = v4730;
  struct StateT * v4714 = v4697->b;
  int * v4715 = v4714->regs;
  int v4716 = v4715[8];
  int v4733 = v4716 + 1;
  v4715[8] = v4733;
  struct StateT2 * v4718 = slot_93(v4697);
  return v4718;
}

struct StateT2 * slot_31(struct StateT2 * v2318) {
  struct StateT * v2319 = v2318->a;
  int v2320 = v2319->timer;
  struct StateT * v2321 = v2318->b;
  int v2322 = v2321->timer;
  bool v2343 = v2320 == v2322;
  squared_assert(v2343);
  squared_assume(v2343);
  struct StateT * v2325 = v2318->a;
  int v2326 = v2325->timer;
  int v2345 = v2326 + 1;
  v2325->timer = v2345;
  struct StateT * v2328 = v2318->b;
  int v2329 = v2328->timer;
  int v2347 = v2329 + 1;
  v2328->timer = v2347;
  struct StateT * v2331 = v2318->a;
  int * v2332 = v2331->regs;
  int v2333 = v2332[8];
  int v2351 = v2333 + 1;
  v2332[8] = v2351;
  struct StateT * v2335 = v2318->b;
  int * v2336 = v2335->regs;
  int v2337 = v2336[8];
  int v2354 = v2337 + 1;
  v2336[8] = v2354;
  struct StateT2 * v2339 = slot_32(v2318);
  return v2339;
}

struct StateT2 * slot_160(struct StateT2 * v7349) {
  struct StateT * v7350 = v7349->a;
  int v7351 = v7350->timer;
  struct StateT * v7352 = v7349->b;
  int v7353 = v7352->timer;
  bool v7374 = v7351 == v7353;
  squared_assert(v7374);
  squared_assume(v7374);
  struct StateT * v7356 = v7349->a;
  int v7357 = v7356->timer;
  int v7376 = v7357 + 1;
  v7356->timer = v7376;
  struct StateT * v7359 = v7349->b;
  int v7360 = v7359->timer;
  int v7378 = v7360 + 1;
  v7359->timer = v7378;
  struct StateT * v7362 = v7349->a;
  int * v7363 = v7362->regs;
  int v7364 = v7363[8];
  int v7382 = v7364 + 1;
  v7363[8] = v7382;
  struct StateT * v7366 = v7349->b;
  int * v7367 = v7366->regs;
  int v7368 = v7367[8];
  int v7385 = v7368 + 1;
  v7367[8] = v7385;
  struct StateT2 * v7370 = slot_161(v7349);
  return v7370;
}

struct StateT2 * slot_65(struct StateT2 * v3644) {
  struct StateT * v3645 = v3644->a;
  int v3646 = v3645->timer;
  struct StateT * v3647 = v3644->b;
  int v3648 = v3647->timer;
  bool v3669 = v3646 == v3648;
  squared_assert(v3669);
  squared_assume(v3669);
  struct StateT * v3651 = v3644->a;
  int v3652 = v3651->timer;
  int v3671 = v3652 + 1;
  v3651->timer = v3671;
  struct StateT * v3654 = v3644->b;
  int v3655 = v3654->timer;
  int v3673 = v3655 + 1;
  v3654->timer = v3673;
  struct StateT * v3657 = v3644->a;
  int * v3658 = v3657->regs;
  int v3659 = v3658[8];
  int v3677 = v3659 + 1;
  v3658[8] = v3677;
  struct StateT * v3661 = v3644->b;
  int * v3662 = v3661->regs;
  int v3663 = v3662[8];
  int v3680 = v3663 + 1;
  v3662[8] = v3680;
  struct StateT2 * v3665 = slot_66(v3644);
  return v3665;
}

struct StateT2 * slot_10(struct StateT2 * v1499) {
  struct StateT * v1500 = v1499->a;
  int v1501 = v1500->timer;
  struct StateT * v1502 = v1499->b;
  int v1503 = v1502->timer;
  bool v1524 = v1501 == v1503;
  squared_assert(v1524);
  squared_assume(v1524);
  struct StateT * v1506 = v1499->a;
  int v1507 = v1506->timer;
  int v1526 = v1507 + 1;
  v1506->timer = v1526;
  struct StateT * v1509 = v1499->b;
  int v1510 = v1509->timer;
  int v1528 = v1510 + 1;
  v1509->timer = v1528;
  struct StateT * v1512 = v1499->a;
  int * v1513 = v1512->regs;
  int v1514 = v1513[8];
  int v1532 = v1514 + 1;
  v1513[8] = v1532;
  struct StateT * v1516 = v1499->b;
  int * v1517 = v1516->regs;
  int v1518 = v1517[8];
  int v1535 = v1518 + 1;
  v1517[8] = v1535;
  struct StateT2 * v1520 = slot_11(v1499);
  return v1520;
}

struct StateT2 * slot_150(struct StateT2 * v6959) {
  struct StateT * v6960 = v6959->a;
  int v6961 = v6960->timer;
  struct StateT * v6962 = v6959->b;
  int v6963 = v6962->timer;
  bool v6984 = v6961 == v6963;
  squared_assert(v6984);
  squared_assume(v6984);
  struct StateT * v6966 = v6959->a;
  int v6967 = v6966->timer;
  int v6986 = v6967 + 1;
  v6966->timer = v6986;
  struct StateT * v6969 = v6959->b;
  int v6970 = v6969->timer;
  int v6988 = v6970 + 1;
  v6969->timer = v6988;
  struct StateT * v6972 = v6959->a;
  int * v6973 = v6972->regs;
  int v6974 = v6973[8];
  int v6992 = v6974 + 1;
  v6973[8] = v6992;
  struct StateT * v6976 = v6959->b;
  int * v6977 = v6976->regs;
  int v6978 = v6977[8];
  int v6995 = v6978 + 1;
  v6977[8] = v6995;
  struct StateT2 * v6980 = slot_151(v6959);
  return v6980;
}

struct StateT2 * slot_74(struct StateT2 * v3995) {
  struct StateT * v3996 = v3995->a;
  int v3997 = v3996->timer;
  struct StateT * v3998 = v3995->b;
  int v3999 = v3998->timer;
  bool v4020 = v3997 == v3999;
  squared_assert(v4020);
  squared_assume(v4020);
  struct StateT * v4002 = v3995->a;
  int v4003 = v4002->timer;
  int v4022 = v4003 + 1;
  v4002->timer = v4022;
  struct StateT * v4005 = v3995->b;
  int v4006 = v4005->timer;
  int v4024 = v4006 + 1;
  v4005->timer = v4024;
  struct StateT * v4008 = v3995->a;
  int * v4009 = v4008->regs;
  int v4010 = v4009[8];
  int v4028 = v4010 + 1;
  v4009[8] = v4028;
  struct StateT * v4012 = v3995->b;
  int * v4013 = v4012->regs;
  int v4014 = v4013[8];
  int v4031 = v4014 + 1;
  v4013[8] = v4031;
  struct StateT2 * v4016 = slot_75(v3995);
  return v4016;
}

struct StateT2 * slot_107(struct StateT2 * v5282) {
  struct StateT * v5283 = v5282->a;
  int v5284 = v5283->timer;
  struct StateT * v5285 = v5282->b;
  int v5286 = v5285->timer;
  bool v5307 = v5284 == v5286;
  squared_assert(v5307);
  squared_assume(v5307);
  struct StateT * v5289 = v5282->a;
  int v5290 = v5289->timer;
  int v5309 = v5290 + 1;
  v5289->timer = v5309;
  struct StateT * v5292 = v5282->b;
  int v5293 = v5292->timer;
  int v5311 = v5293 + 1;
  v5292->timer = v5311;
  struct StateT * v5295 = v5282->a;
  int * v5296 = v5295->regs;
  int v5297 = v5296[8];
  int v5315 = v5297 + 1;
  v5296[8] = v5315;
  struct StateT * v5299 = v5282->b;
  int * v5300 = v5299->regs;
  int v5301 = v5300[8];
  int v5318 = v5301 + 1;
  v5300[8] = v5318;
  struct StateT2 * v5303 = slot_108(v5282);
  return v5303;
}

struct StateT2 * slot_136(struct StateT2 * v6413) {
  struct StateT * v6414 = v6413->a;
  int v6415 = v6414->timer;
  struct StateT * v6416 = v6413->b;
  int v6417 = v6416->timer;
  bool v6438 = v6415 == v6417;
  squared_assert(v6438);
  squared_assume(v6438);
  struct StateT * v6420 = v6413->a;
  int v6421 = v6420->timer;
  int v6440 = v6421 + 1;
  v6420->timer = v6440;
  struct StateT * v6423 = v6413->b;
  int v6424 = v6423->timer;
  int v6442 = v6424 + 1;
  v6423->timer = v6442;
  struct StateT * v6426 = v6413->a;
  int * v6427 = v6426->regs;
  int v6428 = v6427[8];
  int v6446 = v6428 + 1;
  v6427[8] = v6446;
  struct StateT * v6430 = v6413->b;
  int * v6431 = v6430->regs;
  int v6432 = v6431[8];
  int v6449 = v6432 + 1;
  v6431[8] = v6449;
  struct StateT2 * v6434 = slot_137(v6413);
  return v6434;
}

struct StateT2 * slot_84(struct StateT2 * v4385) {
  struct StateT * v4386 = v4385->a;
  int v4387 = v4386->timer;
  struct StateT * v4388 = v4385->b;
  int v4389 = v4388->timer;
  bool v4410 = v4387 == v4389;
  squared_assert(v4410);
  squared_assume(v4410);
  struct StateT * v4392 = v4385->a;
  int v4393 = v4392->timer;
  int v4412 = v4393 + 1;
  v4392->timer = v4412;
  struct StateT * v4395 = v4385->b;
  int v4396 = v4395->timer;
  int v4414 = v4396 + 1;
  v4395->timer = v4414;
  struct StateT * v4398 = v4385->a;
  int * v4399 = v4398->regs;
  int v4400 = v4399[8];
  int v4418 = v4400 + 1;
  v4399[8] = v4418;
  struct StateT * v4402 = v4385->b;
  int * v4403 = v4402->regs;
  int v4404 = v4403[8];
  int v4421 = v4404 + 1;
  v4403[8] = v4421;
  struct StateT2 * v4406 = slot_85(v4385);
  return v4406;
}

struct StateT2 * slot_28(struct StateT2 * v2201) {
  struct StateT * v2202 = v2201->a;
  int v2203 = v2202->timer;
  struct StateT * v2204 = v2201->b;
  int v2205 = v2204->timer;
  bool v2226 = v2203 == v2205;
  squared_assert(v2226);
  squared_assume(v2226);
  struct StateT * v2208 = v2201->a;
  int v2209 = v2208->timer;
  int v2228 = v2209 + 1;
  v2208->timer = v2228;
  struct StateT * v2211 = v2201->b;
  int v2212 = v2211->timer;
  int v2230 = v2212 + 1;
  v2211->timer = v2230;
  struct StateT * v2214 = v2201->a;
  int * v2215 = v2214->regs;
  int v2216 = v2215[8];
  int v2234 = v2216 + 1;
  v2215[8] = v2234;
  struct StateT * v2218 = v2201->b;
  int * v2219 = v2218->regs;
  int v2220 = v2219[8];
  int v2237 = v2220 + 1;
  v2219[8] = v2237;
  struct StateT2 * v2222 = slot_29(v2201);
  return v2222;
}

struct StateT2 * slot_155(struct StateT2 * v7154) {
  struct StateT * v7155 = v7154->a;
  int v7156 = v7155->timer;
  struct StateT * v7157 = v7154->b;
  int v7158 = v7157->timer;
  bool v7179 = v7156 == v7158;
  squared_assert(v7179);
  squared_assume(v7179);
  struct StateT * v7161 = v7154->a;
  int v7162 = v7161->timer;
  int v7181 = v7162 + 1;
  v7161->timer = v7181;
  struct StateT * v7164 = v7154->b;
  int v7165 = v7164->timer;
  int v7183 = v7165 + 1;
  v7164->timer = v7183;
  struct StateT * v7167 = v7154->a;
  int * v7168 = v7167->regs;
  int v7169 = v7168[8];
  int v7187 = v7169 + 1;
  v7168[8] = v7187;
  struct StateT * v7171 = v7154->b;
  int * v7172 = v7171->regs;
  int v7173 = v7172[8];
  int v7190 = v7173 + 1;
  v7172[8] = v7190;
  struct StateT2 * v7175 = slot_156(v7154);
  return v7175;
}

struct StateT2 * slot_177(struct StateT2 * v8012) {
  struct StateT * v8013 = v8012->a;
  int v8014 = v8013->timer;
  struct StateT * v8015 = v8012->b;
  int v8016 = v8015->timer;
  bool v8037 = v8014 == v8016;
  squared_assert(v8037);
  squared_assume(v8037);
  struct StateT * v8019 = v8012->a;
  int v8020 = v8019->timer;
  int v8039 = v8020 + 1;
  v8019->timer = v8039;
  struct StateT * v8022 = v8012->b;
  int v8023 = v8022->timer;
  int v8041 = v8023 + 1;
  v8022->timer = v8041;
  struct StateT * v8025 = v8012->a;
  int * v8026 = v8025->regs;
  int v8027 = v8026[8];
  int v8045 = v8027 + 1;
  v8026[8] = v8045;
  struct StateT * v8029 = v8012->b;
  int * v8030 = v8029->regs;
  int v8031 = v8030[8];
  int v8048 = v8031 + 1;
  v8030[8] = v8048;
  struct StateT2 * v8033 = slot_178(v8012);
  return v8033;
}

struct StateT2 * slot_17(struct StateT2 * v1772) {
  struct StateT * v1773 = v1772->a;
  int v1774 = v1773->timer;
  struct StateT * v1775 = v1772->b;
  int v1776 = v1775->timer;
  bool v1797 = v1774 == v1776;
  squared_assert(v1797);
  squared_assume(v1797);
  struct StateT * v1779 = v1772->a;
  int v1780 = v1779->timer;
  int v1799 = v1780 + 1;
  v1779->timer = v1799;
  struct StateT * v1782 = v1772->b;
  int v1783 = v1782->timer;
  int v1801 = v1783 + 1;
  v1782->timer = v1801;
  struct StateT * v1785 = v1772->a;
  int * v1786 = v1785->regs;
  int v1787 = v1786[8];
  int v1805 = v1787 + 1;
  v1786[8] = v1805;
  struct StateT * v1789 = v1772->b;
  int * v1790 = v1789->regs;
  int v1791 = v1790[8];
  int v1808 = v1791 + 1;
  v1790[8] = v1808;
  struct StateT2 * v1793 = slot_18(v1772);
  return v1793;
}

struct StateT2 * slot_181(struct StateT2 * v8168) {
  struct StateT * v8169 = v8168->a;
  int v8170 = v8169->timer;
  struct StateT * v8171 = v8168->b;
  int v8172 = v8171->timer;
  bool v8193 = v8170 == v8172;
  squared_assert(v8193);
  squared_assume(v8193);
  struct StateT * v8175 = v8168->a;
  int v8176 = v8175->timer;
  int v8195 = v8176 + 1;
  v8175->timer = v8195;
  struct StateT * v8178 = v8168->b;
  int v8179 = v8178->timer;
  int v8197 = v8179 + 1;
  v8178->timer = v8197;
  struct StateT * v8181 = v8168->a;
  int * v8182 = v8181->regs;
  int v8183 = v8182[8];
  int v8201 = v8183 + 1;
  v8182[8] = v8201;
  struct StateT * v8185 = v8168->b;
  int * v8186 = v8185->regs;
  int v8187 = v8186[8];
  int v8204 = v8187 + 1;
  v8186[8] = v8204;
  struct StateT2 * v8189 = slot_182(v8168);
  return v8189;
}

struct StateT2 * slot_197(struct StateT2 * v8792) {
  struct StateT * v8793 = v8792->a;
  int v8794 = v8793->timer;
  struct StateT * v8795 = v8792->b;
  int v8796 = v8795->timer;
  bool v8817 = v8794 == v8796;
  squared_assert(v8817);
  squared_assume(v8817);
  struct StateT * v8799 = v8792->a;
  int v8800 = v8799->timer;
  int v8819 = v8800 + 1;
  v8799->timer = v8819;
  struct StateT * v8802 = v8792->b;
  int v8803 = v8802->timer;
  int v8821 = v8803 + 1;
  v8802->timer = v8821;
  struct StateT * v8805 = v8792->a;
  int * v8806 = v8805->regs;
  int v8807 = v8806[8];
  int v8825 = v8807 + 1;
  v8806[8] = v8825;
  struct StateT * v8809 = v8792->b;
  int * v8810 = v8809->regs;
  int v8811 = v8810[8];
  int v8828 = v8811 + 1;
  v8810[8] = v8828;
  struct StateT2 * v8813 = slot_198(v8792);
  return v8813;
}

struct StateT2 * slot_207(struct StateT2 * v9182) {
  struct StateT * v9183 = v9182->a;
  int v9184 = v9183->timer;
  struct StateT * v9185 = v9182->b;
  int v9186 = v9185->timer;
  bool v9207 = v9184 == v9186;
  squared_assert(v9207);
  squared_assume(v9207);
  struct StateT * v9189 = v9182->a;
  int v9190 = v9189->timer;
  int v9209 = v9190 + 1;
  v9189->timer = v9209;
  struct StateT * v9192 = v9182->b;
  int v9193 = v9192->timer;
  int v9211 = v9193 + 1;
  v9192->timer = v9211;
  struct StateT * v9195 = v9182->a;
  int * v9196 = v9195->regs;
  int v9197 = v9196[8];
  int v9215 = v9197 + 1;
  v9196[8] = v9215;
  struct StateT * v9199 = v9182->b;
  int * v9200 = v9199->regs;
  int v9201 = v9200[8];
  int v9218 = v9201 + 1;
  v9200[8] = v9218;
  struct StateT2 * v9203 = slot_208(v9182);
  return v9203;
}

struct StateT2 * slot_156(struct StateT2 * v7193) {
  struct StateT * v7194 = v7193->a;
  int v7195 = v7194->timer;
  struct StateT * v7196 = v7193->b;
  int v7197 = v7196->timer;
  bool v7218 = v7195 == v7197;
  squared_assert(v7218);
  squared_assume(v7218);
  struct StateT * v7200 = v7193->a;
  int v7201 = v7200->timer;
  int v7220 = v7201 + 1;
  v7200->timer = v7220;
  struct StateT * v7203 = v7193->b;
  int v7204 = v7203->timer;
  int v7222 = v7204 + 1;
  v7203->timer = v7222;
  struct StateT * v7206 = v7193->a;
  int * v7207 = v7206->regs;
  int v7208 = v7207[8];
  int v7226 = v7208 + 1;
  v7207[8] = v7226;
  struct StateT * v7210 = v7193->b;
  int * v7211 = v7210->regs;
  int v7212 = v7211[8];
  int v7229 = v7212 + 1;
  v7211[8] = v7229;
  struct StateT2 * v7214 = slot_157(v7193);
  return v7214;
}

struct StateT2 * slot_154(struct StateT2 * v7115) {
  struct StateT * v7116 = v7115->a;
  int v7117 = v7116->timer;
  struct StateT * v7118 = v7115->b;
  int v7119 = v7118->timer;
  bool v7140 = v7117 == v7119;
  squared_assert(v7140);
  squared_assume(v7140);
  struct StateT * v7122 = v7115->a;
  int v7123 = v7122->timer;
  int v7142 = v7123 + 1;
  v7122->timer = v7142;
  struct StateT * v7125 = v7115->b;
  int v7126 = v7125->timer;
  int v7144 = v7126 + 1;
  v7125->timer = v7144;
  struct StateT * v7128 = v7115->a;
  int * v7129 = v7128->regs;
  int v7130 = v7129[8];
  int v7148 = v7130 + 1;
  v7129[8] = v7148;
  struct StateT * v7132 = v7115->b;
  int * v7133 = v7132->regs;
  int v7134 = v7133[8];
  int v7151 = v7134 + 1;
  v7133[8] = v7151;
  struct StateT2 * v7136 = slot_155(v7115);
  return v7136;
}

struct StateT2 * slot_68(struct StateT2 * v3761) {
  struct StateT * v3762 = v3761->a;
  int v3763 = v3762->timer;
  struct StateT * v3764 = v3761->b;
  int v3765 = v3764->timer;
  bool v3786 = v3763 == v3765;
  squared_assert(v3786);
  squared_assume(v3786);
  struct StateT * v3768 = v3761->a;
  int v3769 = v3768->timer;
  int v3788 = v3769 + 1;
  v3768->timer = v3788;
  struct StateT * v3771 = v3761->b;
  int v3772 = v3771->timer;
  int v3790 = v3772 + 1;
  v3771->timer = v3790;
  struct StateT * v3774 = v3761->a;
  int * v3775 = v3774->regs;
  int v3776 = v3775[8];
  int v3794 = v3776 + 1;
  v3775[8] = v3794;
  struct StateT * v3778 = v3761->b;
  int * v3779 = v3778->regs;
  int v3780 = v3779[8];
  int v3797 = v3780 + 1;
  v3779[8] = v3797;
  struct StateT2 * v3782 = slot_69(v3761);
  return v3782;
}

struct StateT2 * slot_105(struct StateT2 * v5204) {
  struct StateT * v5205 = v5204->a;
  int v5206 = v5205->timer;
  struct StateT * v5207 = v5204->b;
  int v5208 = v5207->timer;
  bool v5229 = v5206 == v5208;
  squared_assert(v5229);
  squared_assume(v5229);
  struct StateT * v5211 = v5204->a;
  int v5212 = v5211->timer;
  int v5231 = v5212 + 1;
  v5211->timer = v5231;
  struct StateT * v5214 = v5204->b;
  int v5215 = v5214->timer;
  int v5233 = v5215 + 1;
  v5214->timer = v5233;
  struct StateT * v5217 = v5204->a;
  int * v5218 = v5217->regs;
  int v5219 = v5218[8];
  int v5237 = v5219 + 1;
  v5218[8] = v5237;
  struct StateT * v5221 = v5204->b;
  int * v5222 = v5221->regs;
  int v5223 = v5222[8];
  int v5240 = v5223 + 1;
  v5222[8] = v5240;
  struct StateT2 * v5225 = slot_106(v5204);
  return v5225;
}

struct StateT2 * slot_27(struct StateT2 * v2162) {
  struct StateT * v2163 = v2162->a;
  int v2164 = v2163->timer;
  struct StateT * v2165 = v2162->b;
  int v2166 = v2165->timer;
  bool v2187 = v2164 == v2166;
  squared_assert(v2187);
  squared_assume(v2187);
  struct StateT * v2169 = v2162->a;
  int v2170 = v2169->timer;
  int v2189 = v2170 + 1;
  v2169->timer = v2189;
  struct StateT * v2172 = v2162->b;
  int v2173 = v2172->timer;
  int v2191 = v2173 + 1;
  v2172->timer = v2191;
  struct StateT * v2175 = v2162->a;
  int * v2176 = v2175->regs;
  int v2177 = v2176[8];
  int v2195 = v2177 + 1;
  v2176[8] = v2195;
  struct StateT * v2179 = v2162->b;
  int * v2180 = v2179->regs;
  int v2181 = v2180[8];
  int v2198 = v2181 + 1;
  v2180[8] = v2198;
  struct StateT2 * v2183 = slot_28(v2162);
  return v2183;
}

struct StateT2 * slot_164(struct StateT2 * v7505) {
  struct StateT * v7506 = v7505->a;
  int v7507 = v7506->timer;
  struct StateT * v7508 = v7505->b;
  int v7509 = v7508->timer;
  bool v7530 = v7507 == v7509;
  squared_assert(v7530);
  squared_assume(v7530);
  struct StateT * v7512 = v7505->a;
  int v7513 = v7512->timer;
  int v7532 = v7513 + 1;
  v7512->timer = v7532;
  struct StateT * v7515 = v7505->b;
  int v7516 = v7515->timer;
  int v7534 = v7516 + 1;
  v7515->timer = v7534;
  struct StateT * v7518 = v7505->a;
  int * v7519 = v7518->regs;
  int v7520 = v7519[8];
  int v7538 = v7520 + 1;
  v7519[8] = v7538;
  struct StateT * v7522 = v7505->b;
  int * v7523 = v7522->regs;
  int v7524 = v7523[8];
  int v7541 = v7524 + 1;
  v7523[8] = v7541;
  struct StateT2 * v7526 = slot_165(v7505);
  return v7526;
}

struct StateT2 * slot_15(struct StateT2 * v1694) {
  struct StateT * v1695 = v1694->a;
  int v1696 = v1695->timer;
  struct StateT * v1697 = v1694->b;
  int v1698 = v1697->timer;
  bool v1719 = v1696 == v1698;
  squared_assert(v1719);
  squared_assume(v1719);
  struct StateT * v1701 = v1694->a;
  int v1702 = v1701->timer;
  int v1721 = v1702 + 1;
  v1701->timer = v1721;
  struct StateT * v1704 = v1694->b;
  int v1705 = v1704->timer;
  int v1723 = v1705 + 1;
  v1704->timer = v1723;
  struct StateT * v1707 = v1694->a;
  int * v1708 = v1707->regs;
  int v1709 = v1708[8];
  int v1727 = v1709 + 1;
  v1708[8] = v1727;
  struct StateT * v1711 = v1694->b;
  int * v1712 = v1711->regs;
  int v1713 = v1712[8];
  int v1730 = v1713 + 1;
  v1712[8] = v1730;
  struct StateT2 * v1715 = slot_16(v1694);
  return v1715;
}

struct StateT2 * slot_133(struct StateT2 * v6296) {
  struct StateT * v6297 = v6296->a;
  int v6298 = v6297->timer;
  struct StateT * v6299 = v6296->b;
  int v6300 = v6299->timer;
  bool v6321 = v6298 == v6300;
  squared_assert(v6321);
  squared_assume(v6321);
  struct StateT * v6303 = v6296->a;
  int v6304 = v6303->timer;
  int v6323 = v6304 + 1;
  v6303->timer = v6323;
  struct StateT * v6306 = v6296->b;
  int v6307 = v6306->timer;
  int v6325 = v6307 + 1;
  v6306->timer = v6325;
  struct StateT * v6309 = v6296->a;
  int * v6310 = v6309->regs;
  int v6311 = v6310[8];
  int v6329 = v6311 + 1;
  v6310[8] = v6329;
  struct StateT * v6313 = v6296->b;
  int * v6314 = v6313->regs;
  int v6315 = v6314[8];
  int v6332 = v6315 + 1;
  v6314[8] = v6332;
  struct StateT2 * v6317 = slot_134(v6296);
  return v6317;
}

struct StateT2 * slot_56(struct StateT2 * v3293) {
  struct StateT * v3294 = v3293->a;
  int v3295 = v3294->timer;
  struct StateT * v3296 = v3293->b;
  int v3297 = v3296->timer;
  bool v3318 = v3295 == v3297;
  squared_assert(v3318);
  squared_assume(v3318);
  struct StateT * v3300 = v3293->a;
  int v3301 = v3300->timer;
  int v3320 = v3301 + 1;
  v3300->timer = v3320;
  struct StateT * v3303 = v3293->b;
  int v3304 = v3303->timer;
  int v3322 = v3304 + 1;
  v3303->timer = v3322;
  struct StateT * v3306 = v3293->a;
  int * v3307 = v3306->regs;
  int v3308 = v3307[8];
  int v3326 = v3308 + 1;
  v3307[8] = v3326;
  struct StateT * v3310 = v3293->b;
  int * v3311 = v3310->regs;
  int v3312 = v3311[8];
  int v3329 = v3312 + 1;
  v3311[8] = v3329;
  struct StateT2 * v3314 = slot_57(v3293);
  return v3314;
}

struct StateT2 * slot_222(struct StateT2 * v9767) {
  struct StateT * v9768 = v9767->a;
  int v9769 = v9768->timer;
  struct StateT * v9770 = v9767->b;
  int v9771 = v9770->timer;
  bool v9792 = v9769 == v9771;
  squared_assert(v9792);
  squared_assume(v9792);
  struct StateT * v9774 = v9767->a;
  int v9775 = v9774->timer;
  int v9794 = v9775 + 1;
  v9774->timer = v9794;
  struct StateT * v9777 = v9767->b;
  int v9778 = v9777->timer;
  int v9796 = v9778 + 1;
  v9777->timer = v9796;
  struct StateT * v9780 = v9767->a;
  int * v9781 = v9780->regs;
  int v9782 = v9781[8];
  int v9800 = v9782 + 1;
  v9781[8] = v9800;
  struct StateT * v9784 = v9767->b;
  int * v9785 = v9784->regs;
  int v9786 = v9785[8];
  int v9803 = v9786 + 1;
  v9785[8] = v9803;
  struct StateT2 * v9788 = slot_223(v9767);
  return v9788;
}

struct StateT2 * slot_34(struct StateT2 * v2435) {
  struct StateT * v2436 = v2435->a;
  int v2437 = v2436->timer;
  struct StateT * v2438 = v2435->b;
  int v2439 = v2438->timer;
  bool v2460 = v2437 == v2439;
  squared_assert(v2460);
  squared_assume(v2460);
  struct StateT * v2442 = v2435->a;
  int v2443 = v2442->timer;
  int v2462 = v2443 + 1;
  v2442->timer = v2462;
  struct StateT * v2445 = v2435->b;
  int v2446 = v2445->timer;
  int v2464 = v2446 + 1;
  v2445->timer = v2464;
  struct StateT * v2448 = v2435->a;
  int * v2449 = v2448->regs;
  int v2450 = v2449[8];
  int v2468 = v2450 + 1;
  v2449[8] = v2468;
  struct StateT * v2452 = v2435->b;
  int * v2453 = v2452->regs;
  int v2454 = v2453[8];
  int v2471 = v2454 + 1;
  v2453[8] = v2471;
  struct StateT2 * v2456 = slot_35(v2435);
  return v2456;
}

struct StateT2 * slot_171(struct StateT2 * v7778) {
  struct StateT * v7779 = v7778->a;
  int v7780 = v7779->timer;
  struct StateT * v7781 = v7778->b;
  int v7782 = v7781->timer;
  bool v7803 = v7780 == v7782;
  squared_assert(v7803);
  squared_assume(v7803);
  struct StateT * v7785 = v7778->a;
  int v7786 = v7785->timer;
  int v7805 = v7786 + 1;
  v7785->timer = v7805;
  struct StateT * v7788 = v7778->b;
  int v7789 = v7788->timer;
  int v7807 = v7789 + 1;
  v7788->timer = v7807;
  struct StateT * v7791 = v7778->a;
  int * v7792 = v7791->regs;
  int v7793 = v7792[8];
  int v7811 = v7793 + 1;
  v7792[8] = v7811;
  struct StateT * v7795 = v7778->b;
  int * v7796 = v7795->regs;
  int v7797 = v7796[8];
  int v7814 = v7797 + 1;
  v7796[8] = v7814;
  struct StateT2 * v7799 = slot_172(v7778);
  return v7799;
}

struct StateT2 * slot_162(struct StateT2 * v7427) {
  struct StateT * v7428 = v7427->a;
  int v7429 = v7428->timer;
  struct StateT * v7430 = v7427->b;
  int v7431 = v7430->timer;
  bool v7452 = v7429 == v7431;
  squared_assert(v7452);
  squared_assume(v7452);
  struct StateT * v7434 = v7427->a;
  int v7435 = v7434->timer;
  int v7454 = v7435 + 1;
  v7434->timer = v7454;
  struct StateT * v7437 = v7427->b;
  int v7438 = v7437->timer;
  int v7456 = v7438 + 1;
  v7437->timer = v7456;
  struct StateT * v7440 = v7427->a;
  int * v7441 = v7440->regs;
  int v7442 = v7441[8];
  int v7460 = v7442 + 1;
  v7441[8] = v7460;
  struct StateT * v7444 = v7427->b;
  int * v7445 = v7444->regs;
  int v7446 = v7445[8];
  int v7463 = v7446 + 1;
  v7445[8] = v7463;
  struct StateT2 * v7448 = slot_163(v7427);
  return v7448;
}

struct StateT2 * slot_21(struct StateT2 * v1928) {
  struct StateT * v1929 = v1928->a;
  int v1930 = v1929->timer;
  struct StateT * v1931 = v1928->b;
  int v1932 = v1931->timer;
  bool v1953 = v1930 == v1932;
  squared_assert(v1953);
  squared_assume(v1953);
  struct StateT * v1935 = v1928->a;
  int v1936 = v1935->timer;
  int v1955 = v1936 + 1;
  v1935->timer = v1955;
  struct StateT * v1938 = v1928->b;
  int v1939 = v1938->timer;
  int v1957 = v1939 + 1;
  v1938->timer = v1957;
  struct StateT * v1941 = v1928->a;
  int * v1942 = v1941->regs;
  int v1943 = v1942[8];
  int v1961 = v1943 + 1;
  v1942[8] = v1961;
  struct StateT * v1945 = v1928->b;
  int * v1946 = v1945->regs;
  int v1947 = v1946[8];
  int v1964 = v1947 + 1;
  v1946[8] = v1964;
  struct StateT2 * v1949 = slot_22(v1928);
  return v1949;
}

struct StateT2 * slot_118(struct StateT2 * v5711) {
  struct StateT * v5712 = v5711->a;
  int v5713 = v5712->timer;
  struct StateT * v5714 = v5711->b;
  int v5715 = v5714->timer;
  bool v5736 = v5713 == v5715;
  squared_assert(v5736);
  squared_assume(v5736);
  struct StateT * v5718 = v5711->a;
  int v5719 = v5718->timer;
  int v5738 = v5719 + 1;
  v5718->timer = v5738;
  struct StateT * v5721 = v5711->b;
  int v5722 = v5721->timer;
  int v5740 = v5722 + 1;
  v5721->timer = v5740;
  struct StateT * v5724 = v5711->a;
  int * v5725 = v5724->regs;
  int v5726 = v5725[8];
  int v5744 = v5726 + 1;
  v5725[8] = v5744;
  struct StateT * v5728 = v5711->b;
  int * v5729 = v5728->regs;
  int v5730 = v5729[8];
  int v5747 = v5730 + 1;
  v5729[8] = v5747;
  struct StateT2 * v5732 = slot_119(v5711);
  return v5732;
}

struct StateT2 * slot_121(struct StateT2 * v5828) {
  struct StateT * v5829 = v5828->a;
  int v5830 = v5829->timer;
  struct StateT * v5831 = v5828->b;
  int v5832 = v5831->timer;
  bool v5853 = v5830 == v5832;
  squared_assert(v5853);
  squared_assume(v5853);
  struct StateT * v5835 = v5828->a;
  int v5836 = v5835->timer;
  int v5855 = v5836 + 1;
  v5835->timer = v5855;
  struct StateT * v5838 = v5828->b;
  int v5839 = v5838->timer;
  int v5857 = v5839 + 1;
  v5838->timer = v5857;
  struct StateT * v5841 = v5828->a;
  int * v5842 = v5841->regs;
  int v5843 = v5842[8];
  int v5861 = v5843 + 1;
  v5842[8] = v5861;
  struct StateT * v5845 = v5828->b;
  int * v5846 = v5845->regs;
  int v5847 = v5846[8];
  int v5864 = v5847 + 1;
  v5846[8] = v5864;
  struct StateT2 * v5849 = slot_122(v5828);
  return v5849;
}

struct StateT2 * slot_144(struct StateT2 * v6725) {
  struct StateT * v6726 = v6725->a;
  int v6727 = v6726->timer;
  struct StateT * v6728 = v6725->b;
  int v6729 = v6728->timer;
  bool v6750 = v6727 == v6729;
  squared_assert(v6750);
  squared_assume(v6750);
  struct StateT * v6732 = v6725->a;
  int v6733 = v6732->timer;
  int v6752 = v6733 + 1;
  v6732->timer = v6752;
  struct StateT * v6735 = v6725->b;
  int v6736 = v6735->timer;
  int v6754 = v6736 + 1;
  v6735->timer = v6754;
  struct StateT * v6738 = v6725->a;
  int * v6739 = v6738->regs;
  int v6740 = v6739[8];
  int v6758 = v6740 + 1;
  v6739[8] = v6758;
  struct StateT * v6742 = v6725->b;
  int * v6743 = v6742->regs;
  int v6744 = v6743[8];
  int v6761 = v6744 + 1;
  v6743[8] = v6761;
  struct StateT2 * v6746 = slot_145(v6725);
  return v6746;
}

struct StateT2 * slot_201(struct StateT2 * v8948) {
  struct StateT * v8949 = v8948->a;
  int v8950 = v8949->timer;
  struct StateT * v8951 = v8948->b;
  int v8952 = v8951->timer;
  bool v8973 = v8950 == v8952;
  squared_assert(v8973);
  squared_assume(v8973);
  struct StateT * v8955 = v8948->a;
  int v8956 = v8955->timer;
  int v8975 = v8956 + 1;
  v8955->timer = v8975;
  struct StateT * v8958 = v8948->b;
  int v8959 = v8958->timer;
  int v8977 = v8959 + 1;
  v8958->timer = v8977;
  struct StateT * v8961 = v8948->a;
  int * v8962 = v8961->regs;
  int v8963 = v8962[8];
  int v8981 = v8963 + 1;
  v8962[8] = v8981;
  struct StateT * v8965 = v8948->b;
  int * v8966 = v8965->regs;
  int v8967 = v8966[8];
  int v8984 = v8967 + 1;
  v8966[8] = v8984;
  struct StateT2 * v8969 = slot_202(v8948);
  return v8969;
}

struct StateT2 * slot_94(struct StateT2 * v4775) {
  struct StateT * v4776 = v4775->a;
  int v4777 = v4776->timer;
  struct StateT * v4778 = v4775->b;
  int v4779 = v4778->timer;
  bool v4800 = v4777 == v4779;
  squared_assert(v4800);
  squared_assume(v4800);
  struct StateT * v4782 = v4775->a;
  int v4783 = v4782->timer;
  int v4802 = v4783 + 1;
  v4782->timer = v4802;
  struct StateT * v4785 = v4775->b;
  int v4786 = v4785->timer;
  int v4804 = v4786 + 1;
  v4785->timer = v4804;
  struct StateT * v4788 = v4775->a;
  int * v4789 = v4788->regs;
  int v4790 = v4789[8];
  int v4808 = v4790 + 1;
  v4789[8] = v4808;
  struct StateT * v4792 = v4775->b;
  int * v4793 = v4792->regs;
  int v4794 = v4793[8];
  int v4811 = v4794 + 1;
  v4793[8] = v4811;
  struct StateT2 * v4796 = slot_95(v4775);
  return v4796;
}

struct StateT2 * slot_63(struct StateT2 * v3566) {
  struct StateT * v3567 = v3566->a;
  int v3568 = v3567->timer;
  struct StateT * v3569 = v3566->b;
  int v3570 = v3569->timer;
  bool v3591 = v3568 == v3570;
  squared_assert(v3591);
  squared_assume(v3591);
  struct StateT * v3573 = v3566->a;
  int v3574 = v3573->timer;
  int v3593 = v3574 + 1;
  v3573->timer = v3593;
  struct StateT * v3576 = v3566->b;
  int v3577 = v3576->timer;
  int v3595 = v3577 + 1;
  v3576->timer = v3595;
  struct StateT * v3579 = v3566->a;
  int * v3580 = v3579->regs;
  int v3581 = v3580[8];
  int v3599 = v3581 + 1;
  v3580[8] = v3599;
  struct StateT * v3583 = v3566->b;
  int * v3584 = v3583->regs;
  int v3585 = v3584[8];
  int v3602 = v3585 + 1;
  v3584[8] = v3602;
  struct StateT2 * v3587 = slot_64(v3566);
  return v3587;
}

struct StateT2 * slot_146(struct StateT2 * v6803) {
  struct StateT * v6804 = v6803->a;
  int v6805 = v6804->timer;
  struct StateT * v6806 = v6803->b;
  int v6807 = v6806->timer;
  bool v6828 = v6805 == v6807;
  squared_assert(v6828);
  squared_assume(v6828);
  struct StateT * v6810 = v6803->a;
  int v6811 = v6810->timer;
  int v6830 = v6811 + 1;
  v6810->timer = v6830;
  struct StateT * v6813 = v6803->b;
  int v6814 = v6813->timer;
  int v6832 = v6814 + 1;
  v6813->timer = v6832;
  struct StateT * v6816 = v6803->a;
  int * v6817 = v6816->regs;
  int v6818 = v6817[8];
  int v6836 = v6818 + 1;
  v6817[8] = v6836;
  struct StateT * v6820 = v6803->b;
  int * v6821 = v6820->regs;
  int v6822 = v6821[8];
  int v6839 = v6822 + 1;
  v6821[8] = v6839;
  struct StateT2 * v6824 = slot_147(v6803);
  return v6824;
}

struct StateT2 * slot_24(struct StateT2 * v2045) {
  struct StateT * v2046 = v2045->a;
  int v2047 = v2046->timer;
  struct StateT * v2048 = v2045->b;
  int v2049 = v2048->timer;
  bool v2070 = v2047 == v2049;
  squared_assert(v2070);
  squared_assume(v2070);
  struct StateT * v2052 = v2045->a;
  int v2053 = v2052->timer;
  int v2072 = v2053 + 1;
  v2052->timer = v2072;
  struct StateT * v2055 = v2045->b;
  int v2056 = v2055->timer;
  int v2074 = v2056 + 1;
  v2055->timer = v2074;
  struct StateT * v2058 = v2045->a;
  int * v2059 = v2058->regs;
  int v2060 = v2059[8];
  int v2078 = v2060 + 1;
  v2059[8] = v2078;
  struct StateT * v2062 = v2045->b;
  int * v2063 = v2062->regs;
  int v2064 = v2063[8];
  int v2081 = v2064 + 1;
  v2063[8] = v2081;
  struct StateT2 * v2066 = slot_25(v2045);
  return v2066;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v233 = v4 == v6;
  squared_assert(v233);
  squared_assume(v233);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v235 = v10 + 1;
  v9->timer = v235;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v237 = v13 + 1;
  v12->timer = v237;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int * v18 = v15->cache_tags;
  int v242 = (((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2;
  int v19 = v18[v242];
  int v243 = ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2) + 1;
  int v20 = v18[v243];
  int v244 = 4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2);
  int v21 = v18[v244];
  int v245 = (4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v22 = v18[v245];
  int v23 = v15->timer;
  int v246 = v23 + ((100 ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v19 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) | (~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v246;
  int * v25 = v15->cache_vals;
  bool v247 = !(((~(((v19 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v19 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) | (~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31))) == 0);
  int v118;
  if (v247) {
    int * v26 = v15->cache_age;
    int v249 = ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2) + ((~(((v20 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v20 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) & 1);
    int v27 = v26[v249];
    int v28 = v26[v242];
    int v250 = v28 + ((int)((unsigned int)(v28 - v27) >> 31));
    v26[v242] = v250;
    int * v30 = v15->cache_age;
    int v31 = v30[v243];
    int v252 = v31 + ((int)((unsigned int)(v31 - v27) >> 31));
    v30[v243] = v252;
    int * v33 = v15->cache_age;
    v33[v249] = 0;
    v118 = v249;
  } else {
    int * v36 = v15->cache_age;
    int v256 = (((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2;
    int v37 = v36[v256];
    int * v38 = v15->cache_tags;
    int v39 = v38[v256];
    int v40 = v36[v243];
    int v41 = v38[v243];
    bool v258 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31))) == 0);
    int v95;
    if (v258) {
      int * v42 = v15->cache_age;
      int v260 = (4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1))))) >> 31)) & 1);
      int v43 = v42[v260];
      int v44 = v42[v244];
      int v261 = v44 + ((int)((unsigned int)(v44 - v43) >> 31));
      v42[v244] = v261;
      int * v46 = v15->cache_age;
      int v47 = v46[v245];
      int v263 = v47 + ((int)((unsigned int)(v47 - v43) >> 31));
      v46[v245] = v263;
      int * v49 = v15->cache_age;
      v49[v260] = 0;
      v95 = v260;
    } else {
      int * v52 = v15->cache_age;
      int v267 = 4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2);
      int v53 = v52[v267];
      int * v54 = v15->cache_tags;
      int v55 = v54[v267];
      int v56 = v52[v245];
      int v57 = v54[v245];
      int * v58 = v15->cache_dirty;
      int v270 = (4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v59 = v58[v270];
      bool v271 = !(v59 == 0);
      if (v271) {
        int * v60 = v15->cache_tags;
        int v61 = v60[v270];
        int * v62 = v15->cache_vals;
        int v274 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63 = v62[v274];
        int v275 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v64 = v62[v275];
        int * v65 = v15->mem;
        int v277 = v61 * 2;
        v65[v277] = v63;
        int * v67 = v15->mem;
        int v280 = (v61 * 2) + 1;
        v67[v280] = v64;
        ;
      } else {
        ;
      }
      int * v72 = v15->mem;
      int v285 = ((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) * 2;
      int v73 = v72[v285];
      int v286 = (((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) * 2) + 1;
      int v74 = v72[v286];
      int * v75 = v15->cache_vals;
      int v288 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v75[v288] = v73;
      int * v77 = v15->cache_vals;
      int v291 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v77[v291] = v74;
      int * v79 = v15->cache_tags;
      int v294 = (int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1);
      v79[v270] = v294;
      int * v81 = v15->cache_dirty;
      v81[v270] = 0;
      int * v83 = v15->cache_age;
      v83[v270] = 1;
      int * v85 = v15->cache_age;
      int v86 = v85[v270];
      int v87 = v85[v244];
      int v300 = v87 + ((int)((unsigned int)(v87 - v86) >> 31));
      v85[v244] = v300;
      int * v89 = v15->cache_age;
      int v90 = v89[v245];
      int v302 = v90 + ((int)((unsigned int)(v90 - v86) >> 31));
      v89[v245] = v302;
      int * v92 = v15->cache_age;
      v92[v270] = 0;
      v95 = v270;
    }
    int * v96 = v15->cache_vals;
    int v305 = v95 * 2;
    int v97 = v96[v305];
    int v306 = (v95 * 2) + 1;
    int v98 = v96[v306];
    int v307 = (((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2) + ((((v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v96[v307] = v97;
    int * v100 = v15->cache_vals;
    int v310 = ((((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2) + ((((v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v100[v310] = v98;
    int * v102 = v15->cache_tags;
    int v313 = ((((int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1)) & 1) * 2) + ((((v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v314 = (int)((unsigned int)((int)((unsigned int)v17 >> 2)) >> 1);
    v102[v313] = v314;
    int * v104 = v15->cache_dirty;
    v104[v313] = 0;
    int * v106 = v15->cache_age;
    v106[v313] = 1;
    int * v108 = v15->cache_age;
    int v109 = v108[v313];
    int v110 = v108[v242];
    int v320 = v110 + ((int)((unsigned int)(v110 - v109) >> 31));
    v108[v242] = v320;
    int * v112 = v15->cache_age;
    int v113 = v112[v243];
    int v322 = v113 + ((int)((unsigned int)(v113 - v109) >> 31));
    v112[v243] = v322;
    int * v115 = v15->cache_age;
    v115[v313] = 0;
    v118 = v313;
  }
  int v325 = (v118 * 2) + (((int)((unsigned int)v17 >> 2)) & 1);
  int v119 = v25[v325];
  int * v120 = v15->regs;
  v120[5] = v119;
  struct StateT * v122 = v2->b;
  int * v123 = v122->regs;
  int v124 = v123[10];
  int * v125 = v122->cache_tags;
  int v332 = (((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2;
  int v126 = v125[v332];
  int v333 = ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2) + 1;
  int v127 = v125[v333];
  int v334 = 4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2);
  int v128 = v125[v334];
  int v335 = (4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v129 = v125[v335];
  int v130 = v122->timer;
  int v336 = v130 + ((100 ^ (((~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) | (~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) | (~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) | (~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31))) & 104)))));
  v122->timer = v336;
  int * v132 = v122->cache_vals;
  bool v337 = !(((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) | (~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31))) == 0);
  int v225;
  if (v337) {
    int * v133 = v122->cache_age;
    int v339 = ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2) + ((~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) & 1);
    int v134 = v133[v339];
    int v135 = v133[v332];
    int v340 = v135 + ((int)((unsigned int)(v135 - v134) >> 31));
    v133[v332] = v340;
    int * v137 = v122->cache_age;
    int v138 = v137[v333];
    int v342 = v138 + ((int)((unsigned int)(v138 - v134) >> 31));
    v137[v333] = v342;
    int * v140 = v122->cache_age;
    v140[v339] = 0;
    v225 = v339;
  } else {
    int * v143 = v122->cache_age;
    int v346 = (((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2;
    int v144 = v143[v346];
    int * v145 = v122->cache_tags;
    int v146 = v145[v346];
    int v147 = v143[v333];
    int v148 = v145[v333];
    bool v348 = !(((~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) | (~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31))) == 0);
    int v202;
    if (v348) {
      int * v149 = v122->cache_age;
      int v350 = (4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + ((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1))))) >> 31)) & 1);
      int v150 = v149[v350];
      int v151 = v149[v334];
      int v351 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
      v149[v334] = v351;
      int * v153 = v122->cache_age;
      int v154 = v153[v335];
      int v353 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
      v153[v335] = v353;
      int * v156 = v122->cache_age;
      v156[v350] = 0;
      v202 = v350;
    } else {
      int * v159 = v122->cache_age;
      int v357 = 4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2);
      int v160 = v159[v357];
      int * v161 = v122->cache_tags;
      int v162 = v161[v357];
      int v163 = v159[v335];
      int v164 = v161[v335];
      int * v165 = v122->cache_dirty;
      int v360 = (4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v166 = v165[v360];
      bool v361 = !(v166 == 0);
      if (v361) {
        int * v167 = v122->cache_tags;
        int v168 = v167[v360];
        int * v169 = v122->cache_vals;
        int v364 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v170 = v169[v364];
        int v365 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v171 = v169[v365];
        int * v172 = v122->mem;
        int v367 = v168 * 2;
        v172[v367] = v170;
        int * v174 = v122->mem;
        int v370 = (v168 * 2) + 1;
        v174[v370] = v171;
        ;
      } else {
        ;
      }
      int * v179 = v122->mem;
      int v375 = ((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) * 2;
      int v180 = v179[v375];
      int v376 = (((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) * 2) + 1;
      int v181 = v179[v376];
      int * v182 = v122->cache_vals;
      int v378 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v182[v378] = v180;
      int * v184 = v122->cache_vals;
      int v381 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v163 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v184[v381] = v181;
      int * v186 = v122->cache_tags;
      int v384 = (int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1);
      v186[v360] = v384;
      int * v188 = v122->cache_dirty;
      v188[v360] = 0;
      int * v190 = v122->cache_age;
      v190[v360] = 1;
      int * v192 = v122->cache_age;
      int v193 = v192[v360];
      int v194 = v192[v334];
      int v390 = v194 + ((int)((unsigned int)(v194 - v193) >> 31));
      v192[v334] = v390;
      int * v196 = v122->cache_age;
      int v197 = v196[v335];
      int v392 = v197 + ((int)((unsigned int)(v197 - v193) >> 31));
      v196[v335] = v392;
      int * v199 = v122->cache_age;
      v199[v360] = 0;
      v202 = v360;
    }
    int * v203 = v122->cache_vals;
    int v395 = v202 * 2;
    int v204 = v203[v395];
    int v396 = (v202 * 2) + 1;
    int v205 = v203[v396];
    int v397 = (((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v203[v397] = v204;
    int * v207 = v122->cache_vals;
    int v400 = ((((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v207[v400] = v205;
    int * v209 = v122->cache_tags;
    int v403 = ((((int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1)) & 1) * 2) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v404 = (int)((unsigned int)((int)((unsigned int)v124 >> 2)) >> 1);
    v209[v403] = v404;
    int * v211 = v122->cache_dirty;
    v211[v403] = 0;
    int * v213 = v122->cache_age;
    v213[v403] = 1;
    int * v215 = v122->cache_age;
    int v216 = v215[v403];
    int v217 = v215[v332];
    int v410 = v217 + ((int)((unsigned int)(v217 - v216) >> 31));
    v215[v332] = v410;
    int * v219 = v122->cache_age;
    int v220 = v219[v333];
    int v412 = v220 + ((int)((unsigned int)(v220 - v216) >> 31));
    v219[v333] = v412;
    int * v222 = v122->cache_age;
    v222[v403] = 0;
    v225 = v403;
  }
  int v415 = (v225 * 2) + (((int)((unsigned int)v124 >> 2)) & 1);
  int v226 = v132[v415];
  int * v227 = v122->regs;
  v227[5] = v226;
  struct StateT2 * v229 = slot_1(v2);
  return v229;
}

struct StateT2 * slot_195(struct StateT2 * v8714) {
  struct StateT * v8715 = v8714->a;
  int v8716 = v8715->timer;
  struct StateT * v8717 = v8714->b;
  int v8718 = v8717->timer;
  bool v8739 = v8716 == v8718;
  squared_assert(v8739);
  squared_assume(v8739);
  struct StateT * v8721 = v8714->a;
  int v8722 = v8721->timer;
  int v8741 = v8722 + 1;
  v8721->timer = v8741;
  struct StateT * v8724 = v8714->b;
  int v8725 = v8724->timer;
  int v8743 = v8725 + 1;
  v8724->timer = v8743;
  struct StateT * v8727 = v8714->a;
  int * v8728 = v8727->regs;
  int v8729 = v8728[8];
  int v8747 = v8729 + 1;
  v8728[8] = v8747;
  struct StateT * v8731 = v8714->b;
  int * v8732 = v8731->regs;
  int v8733 = v8732[8];
  int v8750 = v8733 + 1;
  v8732[8] = v8750;
  struct StateT2 * v8735 = slot_196(v8714);
  return v8735;
}

struct StateT2 * slot_125(struct StateT2 * v5984) {
  struct StateT * v5985 = v5984->a;
  int v5986 = v5985->timer;
  struct StateT * v5987 = v5984->b;
  int v5988 = v5987->timer;
  bool v6009 = v5986 == v5988;
  squared_assert(v6009);
  squared_assume(v6009);
  struct StateT * v5991 = v5984->a;
  int v5992 = v5991->timer;
  int v6011 = v5992 + 1;
  v5991->timer = v6011;
  struct StateT * v5994 = v5984->b;
  int v5995 = v5994->timer;
  int v6013 = v5995 + 1;
  v5994->timer = v6013;
  struct StateT * v5997 = v5984->a;
  int * v5998 = v5997->regs;
  int v5999 = v5998[8];
  int v6017 = v5999 + 1;
  v5998[8] = v6017;
  struct StateT * v6001 = v5984->b;
  int * v6002 = v6001->regs;
  int v6003 = v6002[8];
  int v6020 = v6003 + 1;
  v6002[8] = v6020;
  struct StateT2 * v6005 = slot_126(v5984);
  return v6005;
}

struct StateT2 * slot_148(struct StateT2 * v6881) {
  struct StateT * v6882 = v6881->a;
  int v6883 = v6882->timer;
  struct StateT * v6884 = v6881->b;
  int v6885 = v6884->timer;
  bool v6906 = v6883 == v6885;
  squared_assert(v6906);
  squared_assume(v6906);
  struct StateT * v6888 = v6881->a;
  int v6889 = v6888->timer;
  int v6908 = v6889 + 1;
  v6888->timer = v6908;
  struct StateT * v6891 = v6881->b;
  int v6892 = v6891->timer;
  int v6910 = v6892 + 1;
  v6891->timer = v6910;
  struct StateT * v6894 = v6881->a;
  int * v6895 = v6894->regs;
  int v6896 = v6895[8];
  int v6914 = v6896 + 1;
  v6895[8] = v6914;
  struct StateT * v6898 = v6881->b;
  int * v6899 = v6898->regs;
  int v6900 = v6899[8];
  int v6917 = v6900 + 1;
  v6899[8] = v6917;
  struct StateT2 * v6902 = slot_149(v6881);
  return v6902;
}

struct StateT2 * slot_126(struct StateT2 * v6023) {
  struct StateT * v6024 = v6023->a;
  int v6025 = v6024->timer;
  struct StateT * v6026 = v6023->b;
  int v6027 = v6026->timer;
  bool v6048 = v6025 == v6027;
  squared_assert(v6048);
  squared_assume(v6048);
  struct StateT * v6030 = v6023->a;
  int v6031 = v6030->timer;
  int v6050 = v6031 + 1;
  v6030->timer = v6050;
  struct StateT * v6033 = v6023->b;
  int v6034 = v6033->timer;
  int v6052 = v6034 + 1;
  v6033->timer = v6052;
  struct StateT * v6036 = v6023->a;
  int * v6037 = v6036->regs;
  int v6038 = v6037[8];
  int v6056 = v6038 + 1;
  v6037[8] = v6056;
  struct StateT * v6040 = v6023->b;
  int * v6041 = v6040->regs;
  int v6042 = v6041[8];
  int v6059 = v6042 + 1;
  v6041[8] = v6059;
  struct StateT2 * v6044 = slot_127(v6023);
  return v6044;
}

struct StateT2 * slot_223(struct StateT2 * v9806) {
  struct StateT * v9807 = v9806->a;
  int v9808 = v9807->timer;
  struct StateT * v9809 = v9806->b;
  int v9810 = v9809->timer;
  bool v9831 = v9808 == v9810;
  squared_assert(v9831);
  squared_assume(v9831);
  struct StateT * v9813 = v9806->a;
  int v9814 = v9813->timer;
  int v9833 = v9814 + 1;
  v9813->timer = v9833;
  struct StateT * v9816 = v9806->b;
  int v9817 = v9816->timer;
  int v9835 = v9817 + 1;
  v9816->timer = v9835;
  struct StateT * v9819 = v9806->a;
  int * v9820 = v9819->regs;
  int v9821 = v9820[8];
  int v9839 = v9821 + 1;
  v9820[8] = v9839;
  struct StateT * v9823 = v9806->b;
  int * v9824 = v9823->regs;
  int v9825 = v9824[8];
  int v9842 = v9825 + 1;
  v9824[8] = v9842;
  struct StateT2 * v9827 = slot_224(v9806);
  return v9827;
}

struct StateT2 * slot_79(struct StateT2 * v4190) {
  struct StateT * v4191 = v4190->a;
  int v4192 = v4191->timer;
  struct StateT * v4193 = v4190->b;
  int v4194 = v4193->timer;
  bool v4215 = v4192 == v4194;
  squared_assert(v4215);
  squared_assume(v4215);
  struct StateT * v4197 = v4190->a;
  int v4198 = v4197->timer;
  int v4217 = v4198 + 1;
  v4197->timer = v4217;
  struct StateT * v4200 = v4190->b;
  int v4201 = v4200->timer;
  int v4219 = v4201 + 1;
  v4200->timer = v4219;
  struct StateT * v4203 = v4190->a;
  int * v4204 = v4203->regs;
  int v4205 = v4204[8];
  int v4223 = v4205 + 1;
  v4204[8] = v4223;
  struct StateT * v4207 = v4190->b;
  int * v4208 = v4207->regs;
  int v4209 = v4208[8];
  int v4226 = v4209 + 1;
  v4208[8] = v4226;
  struct StateT2 * v4211 = slot_80(v4190);
  return v4211;
}

struct StateT2 * slot_41(struct StateT2 * v2708) {
  struct StateT * v2709 = v2708->a;
  int v2710 = v2709->timer;
  struct StateT * v2711 = v2708->b;
  int v2712 = v2711->timer;
  bool v2733 = v2710 == v2712;
  squared_assert(v2733);
  squared_assume(v2733);
  struct StateT * v2715 = v2708->a;
  int v2716 = v2715->timer;
  int v2735 = v2716 + 1;
  v2715->timer = v2735;
  struct StateT * v2718 = v2708->b;
  int v2719 = v2718->timer;
  int v2737 = v2719 + 1;
  v2718->timer = v2737;
  struct StateT * v2721 = v2708->a;
  int * v2722 = v2721->regs;
  int v2723 = v2722[8];
  int v2741 = v2723 + 1;
  v2722[8] = v2741;
  struct StateT * v2725 = v2708->b;
  int * v2726 = v2725->regs;
  int v2727 = v2726[8];
  int v2744 = v2727 + 1;
  v2726[8] = v2744;
  struct StateT2 * v2729 = slot_42(v2708);
  return v2729;
}

struct StateT2 * slot_39(struct StateT2 * v2630) {
  struct StateT * v2631 = v2630->a;
  int v2632 = v2631->timer;
  struct StateT * v2633 = v2630->b;
  int v2634 = v2633->timer;
  bool v2655 = v2632 == v2634;
  squared_assert(v2655);
  squared_assume(v2655);
  struct StateT * v2637 = v2630->a;
  int v2638 = v2637->timer;
  int v2657 = v2638 + 1;
  v2637->timer = v2657;
  struct StateT * v2640 = v2630->b;
  int v2641 = v2640->timer;
  int v2659 = v2641 + 1;
  v2640->timer = v2659;
  struct StateT * v2643 = v2630->a;
  int * v2644 = v2643->regs;
  int v2645 = v2644[8];
  int v2663 = v2645 + 1;
  v2644[8] = v2663;
  struct StateT * v2647 = v2630->b;
  int * v2648 = v2647->regs;
  int v2649 = v2648[8];
  int v2666 = v2649 + 1;
  v2648[8] = v2666;
  struct StateT2 * v2651 = slot_40(v2630);
  return v2651;
}

struct StateT2 * slot_142(struct StateT2 * v6647) {
  struct StateT * v6648 = v6647->a;
  int v6649 = v6648->timer;
  struct StateT * v6650 = v6647->b;
  int v6651 = v6650->timer;
  bool v6672 = v6649 == v6651;
  squared_assert(v6672);
  squared_assume(v6672);
  struct StateT * v6654 = v6647->a;
  int v6655 = v6654->timer;
  int v6674 = v6655 + 1;
  v6654->timer = v6674;
  struct StateT * v6657 = v6647->b;
  int v6658 = v6657->timer;
  int v6676 = v6658 + 1;
  v6657->timer = v6676;
  struct StateT * v6660 = v6647->a;
  int * v6661 = v6660->regs;
  int v6662 = v6661[8];
  int v6680 = v6662 + 1;
  v6661[8] = v6680;
  struct StateT * v6664 = v6647->b;
  int * v6665 = v6664->regs;
  int v6666 = v6665[8];
  int v6683 = v6666 + 1;
  v6665[8] = v6683;
  struct StateT2 * v6668 = slot_143(v6647);
  return v6668;
}

struct StateT2 * slot_60(struct StateT2 * v3449) {
  struct StateT * v3450 = v3449->a;
  int v3451 = v3450->timer;
  struct StateT * v3452 = v3449->b;
  int v3453 = v3452->timer;
  bool v3474 = v3451 == v3453;
  squared_assert(v3474);
  squared_assume(v3474);
  struct StateT * v3456 = v3449->a;
  int v3457 = v3456->timer;
  int v3476 = v3457 + 1;
  v3456->timer = v3476;
  struct StateT * v3459 = v3449->b;
  int v3460 = v3459->timer;
  int v3478 = v3460 + 1;
  v3459->timer = v3478;
  struct StateT * v3462 = v3449->a;
  int * v3463 = v3462->regs;
  int v3464 = v3463[8];
  int v3482 = v3464 + 1;
  v3463[8] = v3482;
  struct StateT * v3466 = v3449->b;
  int * v3467 = v3466->regs;
  int v3468 = v3467[8];
  int v3485 = v3468 + 1;
  v3467[8] = v3485;
  struct StateT2 * v3470 = slot_61(v3449);
  return v3470;
}

struct StateT2 * slot_112(struct StateT2 * v5477) {
  struct StateT * v5478 = v5477->a;
  int v5479 = v5478->timer;
  struct StateT * v5480 = v5477->b;
  int v5481 = v5480->timer;
  bool v5502 = v5479 == v5481;
  squared_assert(v5502);
  squared_assume(v5502);
  struct StateT * v5484 = v5477->a;
  int v5485 = v5484->timer;
  int v5504 = v5485 + 1;
  v5484->timer = v5504;
  struct StateT * v5487 = v5477->b;
  int v5488 = v5487->timer;
  int v5506 = v5488 + 1;
  v5487->timer = v5506;
  struct StateT * v5490 = v5477->a;
  int * v5491 = v5490->regs;
  int v5492 = v5491[8];
  int v5510 = v5492 + 1;
  v5491[8] = v5510;
  struct StateT * v5494 = v5477->b;
  int * v5495 = v5494->regs;
  int v5496 = v5495[8];
  int v5513 = v5496 + 1;
  v5495[8] = v5513;
  struct StateT2 * v5498 = slot_113(v5477);
  return v5498;
}

struct StateT2 * slot_47(struct StateT2 * v2942) {
  struct StateT * v2943 = v2942->a;
  int v2944 = v2943->timer;
  struct StateT * v2945 = v2942->b;
  int v2946 = v2945->timer;
  bool v2967 = v2944 == v2946;
  squared_assert(v2967);
  squared_assume(v2967);
  struct StateT * v2949 = v2942->a;
  int v2950 = v2949->timer;
  int v2969 = v2950 + 1;
  v2949->timer = v2969;
  struct StateT * v2952 = v2942->b;
  int v2953 = v2952->timer;
  int v2971 = v2953 + 1;
  v2952->timer = v2971;
  struct StateT * v2955 = v2942->a;
  int * v2956 = v2955->regs;
  int v2957 = v2956[8];
  int v2975 = v2957 + 1;
  v2956[8] = v2975;
  struct StateT * v2959 = v2942->b;
  int * v2960 = v2959->regs;
  int v2961 = v2960[8];
  int v2978 = v2961 + 1;
  v2960[8] = v2978;
  struct StateT2 * v2963 = slot_48(v2942);
  return v2963;
}

struct StateT2 * slot_214(struct StateT2 * v9455) {
  struct StateT * v9456 = v9455->a;
  int v9457 = v9456->timer;
  struct StateT * v9458 = v9455->b;
  int v9459 = v9458->timer;
  bool v9480 = v9457 == v9459;
  squared_assert(v9480);
  squared_assume(v9480);
  struct StateT * v9462 = v9455->a;
  int v9463 = v9462->timer;
  int v9482 = v9463 + 1;
  v9462->timer = v9482;
  struct StateT * v9465 = v9455->b;
  int v9466 = v9465->timer;
  int v9484 = v9466 + 1;
  v9465->timer = v9484;
  struct StateT * v9468 = v9455->a;
  int * v9469 = v9468->regs;
  int v9470 = v9469[8];
  int v9488 = v9470 + 1;
  v9469[8] = v9488;
  struct StateT * v9472 = v9455->b;
  int * v9473 = v9472->regs;
  int v9474 = v9473[8];
  int v9491 = v9474 + 1;
  v9473[8] = v9491;
  struct StateT2 * v9476 = slot_215(v9455);
  return v9476;
}

struct StateT2 * slot_29(struct StateT2 * v2240) {
  struct StateT * v2241 = v2240->a;
  int v2242 = v2241->timer;
  struct StateT * v2243 = v2240->b;
  int v2244 = v2243->timer;
  bool v2265 = v2242 == v2244;
  squared_assert(v2265);
  squared_assume(v2265);
  struct StateT * v2247 = v2240->a;
  int v2248 = v2247->timer;
  int v2267 = v2248 + 1;
  v2247->timer = v2267;
  struct StateT * v2250 = v2240->b;
  int v2251 = v2250->timer;
  int v2269 = v2251 + 1;
  v2250->timer = v2269;
  struct StateT * v2253 = v2240->a;
  int * v2254 = v2253->regs;
  int v2255 = v2254[8];
  int v2273 = v2255 + 1;
  v2254[8] = v2273;
  struct StateT * v2257 = v2240->b;
  int * v2258 = v2257->regs;
  int v2259 = v2258[8];
  int v2276 = v2259 + 1;
  v2258[8] = v2276;
  struct StateT2 * v2261 = slot_30(v2240);
  return v2261;
}

struct StateT2 * slot_16(struct StateT2 * v1733) {
  struct StateT * v1734 = v1733->a;
  int v1735 = v1734->timer;
  struct StateT * v1736 = v1733->b;
  int v1737 = v1736->timer;
  bool v1758 = v1735 == v1737;
  squared_assert(v1758);
  squared_assume(v1758);
  struct StateT * v1740 = v1733->a;
  int v1741 = v1740->timer;
  int v1760 = v1741 + 1;
  v1740->timer = v1760;
  struct StateT * v1743 = v1733->b;
  int v1744 = v1743->timer;
  int v1762 = v1744 + 1;
  v1743->timer = v1762;
  struct StateT * v1746 = v1733->a;
  int * v1747 = v1746->regs;
  int v1748 = v1747[8];
  int v1766 = v1748 + 1;
  v1747[8] = v1766;
  struct StateT * v1750 = v1733->b;
  int * v1751 = v1750->regs;
  int v1752 = v1751[8];
  int v1769 = v1752 + 1;
  v1751[8] = v1769;
  struct StateT2 * v1754 = slot_17(v1733);
  return v1754;
}

struct StateT2 * slot_113(struct StateT2 * v5516) {
  struct StateT * v5517 = v5516->a;
  int v5518 = v5517->timer;
  struct StateT * v5519 = v5516->b;
  int v5520 = v5519->timer;
  bool v5541 = v5518 == v5520;
  squared_assert(v5541);
  squared_assume(v5541);
  struct StateT * v5523 = v5516->a;
  int v5524 = v5523->timer;
  int v5543 = v5524 + 1;
  v5523->timer = v5543;
  struct StateT * v5526 = v5516->b;
  int v5527 = v5526->timer;
  int v5545 = v5527 + 1;
  v5526->timer = v5545;
  struct StateT * v5529 = v5516->a;
  int * v5530 = v5529->regs;
  int v5531 = v5530[8];
  int v5549 = v5531 + 1;
  v5530[8] = v5549;
  struct StateT * v5533 = v5516->b;
  int * v5534 = v5533->regs;
  int v5535 = v5534[8];
  int v5552 = v5535 + 1;
  v5534[8] = v5552;
  struct StateT2 * v5537 = slot_114(v5516);
  return v5537;
}

struct StateT2 * slot_151(struct StateT2 * v6998) {
  struct StateT * v6999 = v6998->a;
  int v7000 = v6999->timer;
  struct StateT * v7001 = v6998->b;
  int v7002 = v7001->timer;
  bool v7023 = v7000 == v7002;
  squared_assert(v7023);
  squared_assume(v7023);
  struct StateT * v7005 = v6998->a;
  int v7006 = v7005->timer;
  int v7025 = v7006 + 1;
  v7005->timer = v7025;
  struct StateT * v7008 = v6998->b;
  int v7009 = v7008->timer;
  int v7027 = v7009 + 1;
  v7008->timer = v7027;
  struct StateT * v7011 = v6998->a;
  int * v7012 = v7011->regs;
  int v7013 = v7012[8];
  int v7031 = v7013 + 1;
  v7012[8] = v7031;
  struct StateT * v7015 = v6998->b;
  int * v7016 = v7015->regs;
  int v7017 = v7016[8];
  int v7034 = v7017 + 1;
  v7016[8] = v7034;
  struct StateT2 * v7019 = slot_152(v6998);
  return v7019;
}

struct StateT2 * slot_7(struct StateT2 * v1382) {
  struct StateT * v1383 = v1382->a;
  int v1384 = v1383->timer;
  struct StateT * v1385 = v1382->b;
  int v1386 = v1385->timer;
  bool v1407 = v1384 == v1386;
  squared_assert(v1407);
  squared_assume(v1407);
  struct StateT * v1389 = v1382->a;
  int v1390 = v1389->timer;
  int v1409 = v1390 + 1;
  v1389->timer = v1409;
  struct StateT * v1392 = v1382->b;
  int v1393 = v1392->timer;
  int v1411 = v1393 + 1;
  v1392->timer = v1411;
  struct StateT * v1395 = v1382->a;
  int * v1396 = v1395->regs;
  int v1397 = v1396[8];
  int v1415 = v1397 + 1;
  v1396[8] = v1415;
  struct StateT * v1399 = v1382->b;
  int * v1400 = v1399->regs;
  int v1401 = v1400[8];
  int v1418 = v1401 + 1;
  v1400[8] = v1418;
  struct StateT2 * v1403 = slot_8(v1382);
  return v1403;
}

struct StateT2 * slot_124(struct StateT2 * v5945) {
  struct StateT * v5946 = v5945->a;
  int v5947 = v5946->timer;
  struct StateT * v5948 = v5945->b;
  int v5949 = v5948->timer;
  bool v5970 = v5947 == v5949;
  squared_assert(v5970);
  squared_assume(v5970);
  struct StateT * v5952 = v5945->a;
  int v5953 = v5952->timer;
  int v5972 = v5953 + 1;
  v5952->timer = v5972;
  struct StateT * v5955 = v5945->b;
  int v5956 = v5955->timer;
  int v5974 = v5956 + 1;
  v5955->timer = v5974;
  struct StateT * v5958 = v5945->a;
  int * v5959 = v5958->regs;
  int v5960 = v5959[8];
  int v5978 = v5960 + 1;
  v5959[8] = v5978;
  struct StateT * v5962 = v5945->b;
  int * v5963 = v5962->regs;
  int v5964 = v5963[8];
  int v5981 = v5964 + 1;
  v5963[8] = v5981;
  struct StateT2 * v5966 = slot_125(v5945);
  return v5966;
}

struct StateT2 * slot_191(struct StateT2 * v8558) {
  struct StateT * v8559 = v8558->a;
  int v8560 = v8559->timer;
  struct StateT * v8561 = v8558->b;
  int v8562 = v8561->timer;
  bool v8583 = v8560 == v8562;
  squared_assert(v8583);
  squared_assume(v8583);
  struct StateT * v8565 = v8558->a;
  int v8566 = v8565->timer;
  int v8585 = v8566 + 1;
  v8565->timer = v8585;
  struct StateT * v8568 = v8558->b;
  int v8569 = v8568->timer;
  int v8587 = v8569 + 1;
  v8568->timer = v8587;
  struct StateT * v8571 = v8558->a;
  int * v8572 = v8571->regs;
  int v8573 = v8572[8];
  int v8591 = v8573 + 1;
  v8572[8] = v8591;
  struct StateT * v8575 = v8558->b;
  int * v8576 = v8575->regs;
  int v8577 = v8576[8];
  int v8594 = v8577 + 1;
  v8576[8] = v8594;
  struct StateT2 * v8579 = slot_192(v8558);
  return v8579;
}

struct StateT2 * slot_103(struct StateT2 * v5126) {
  struct StateT * v5127 = v5126->a;
  int v5128 = v5127->timer;
  struct StateT * v5129 = v5126->b;
  int v5130 = v5129->timer;
  bool v5151 = v5128 == v5130;
  squared_assert(v5151);
  squared_assume(v5151);
  struct StateT * v5133 = v5126->a;
  int v5134 = v5133->timer;
  int v5153 = v5134 + 1;
  v5133->timer = v5153;
  struct StateT * v5136 = v5126->b;
  int v5137 = v5136->timer;
  int v5155 = v5137 + 1;
  v5136->timer = v5155;
  struct StateT * v5139 = v5126->a;
  int * v5140 = v5139->regs;
  int v5141 = v5140[8];
  int v5159 = v5141 + 1;
  v5140[8] = v5159;
  struct StateT * v5143 = v5126->b;
  int * v5144 = v5143->regs;
  int v5145 = v5144[8];
  int v5162 = v5145 + 1;
  v5144[8] = v5162;
  struct StateT2 * v5147 = slot_104(v5126);
  return v5147;
}

struct StateT2 * slot_128(struct StateT2 * v6101) {
  struct StateT * v6102 = v6101->a;
  int v6103 = v6102->timer;
  struct StateT * v6104 = v6101->b;
  int v6105 = v6104->timer;
  bool v6126 = v6103 == v6105;
  squared_assert(v6126);
  squared_assume(v6126);
  struct StateT * v6108 = v6101->a;
  int v6109 = v6108->timer;
  int v6128 = v6109 + 1;
  v6108->timer = v6128;
  struct StateT * v6111 = v6101->b;
  int v6112 = v6111->timer;
  int v6130 = v6112 + 1;
  v6111->timer = v6130;
  struct StateT * v6114 = v6101->a;
  int * v6115 = v6114->regs;
  int v6116 = v6115[8];
  int v6134 = v6116 + 1;
  v6115[8] = v6134;
  struct StateT * v6118 = v6101->b;
  int * v6119 = v6118->regs;
  int v6120 = v6119[8];
  int v6137 = v6120 + 1;
  v6119[8] = v6137;
  struct StateT2 * v6122 = slot_129(v6101);
  return v6122;
}

struct StateT2 * slot_19(struct StateT2 * v1850) {
  struct StateT * v1851 = v1850->a;
  int v1852 = v1851->timer;
  struct StateT * v1853 = v1850->b;
  int v1854 = v1853->timer;
  bool v1875 = v1852 == v1854;
  squared_assert(v1875);
  squared_assume(v1875);
  struct StateT * v1857 = v1850->a;
  int v1858 = v1857->timer;
  int v1877 = v1858 + 1;
  v1857->timer = v1877;
  struct StateT * v1860 = v1850->b;
  int v1861 = v1860->timer;
  int v1879 = v1861 + 1;
  v1860->timer = v1879;
  struct StateT * v1863 = v1850->a;
  int * v1864 = v1863->regs;
  int v1865 = v1864[8];
  int v1883 = v1865 + 1;
  v1864[8] = v1883;
  struct StateT * v1867 = v1850->b;
  int * v1868 = v1867->regs;
  int v1869 = v1868[8];
  int v1886 = v1869 + 1;
  v1868[8] = v1886;
  struct StateT2 * v1871 = slot_20(v1850);
  return v1871;
}

struct StateT2 * slot_87(struct StateT2 * v4502) {
  struct StateT * v4503 = v4502->a;
  int v4504 = v4503->timer;
  struct StateT * v4505 = v4502->b;
  int v4506 = v4505->timer;
  bool v4527 = v4504 == v4506;
  squared_assert(v4527);
  squared_assume(v4527);
  struct StateT * v4509 = v4502->a;
  int v4510 = v4509->timer;
  int v4529 = v4510 + 1;
  v4509->timer = v4529;
  struct StateT * v4512 = v4502->b;
  int v4513 = v4512->timer;
  int v4531 = v4513 + 1;
  v4512->timer = v4531;
  struct StateT * v4515 = v4502->a;
  int * v4516 = v4515->regs;
  int v4517 = v4516[8];
  int v4535 = v4517 + 1;
  v4516[8] = v4535;
  struct StateT * v4519 = v4502->b;
  int * v4520 = v4519->regs;
  int v4521 = v4520[8];
  int v4538 = v4521 + 1;
  v4520[8] = v4538;
  struct StateT2 * v4523 = slot_88(v4502);
  return v4523;
}

struct StateT2 * slot_67(struct StateT2 * v3722) {
  struct StateT * v3723 = v3722->a;
  int v3724 = v3723->timer;
  struct StateT * v3725 = v3722->b;
  int v3726 = v3725->timer;
  bool v3747 = v3724 == v3726;
  squared_assert(v3747);
  squared_assume(v3747);
  struct StateT * v3729 = v3722->a;
  int v3730 = v3729->timer;
  int v3749 = v3730 + 1;
  v3729->timer = v3749;
  struct StateT * v3732 = v3722->b;
  int v3733 = v3732->timer;
  int v3751 = v3733 + 1;
  v3732->timer = v3751;
  struct StateT * v3735 = v3722->a;
  int * v3736 = v3735->regs;
  int v3737 = v3736[8];
  int v3755 = v3737 + 1;
  v3736[8] = v3755;
  struct StateT * v3739 = v3722->b;
  int * v3740 = v3739->regs;
  int v3741 = v3740[8];
  int v3758 = v3741 + 1;
  v3740[8] = v3758;
  struct StateT2 * v3743 = slot_68(v3722);
  return v3743;
}

struct StateT2 * slot_81(struct StateT2 * v4268) {
  struct StateT * v4269 = v4268->a;
  int v4270 = v4269->timer;
  struct StateT * v4271 = v4268->b;
  int v4272 = v4271->timer;
  bool v4293 = v4270 == v4272;
  squared_assert(v4293);
  squared_assume(v4293);
  struct StateT * v4275 = v4268->a;
  int v4276 = v4275->timer;
  int v4295 = v4276 + 1;
  v4275->timer = v4295;
  struct StateT * v4278 = v4268->b;
  int v4279 = v4278->timer;
  int v4297 = v4279 + 1;
  v4278->timer = v4297;
  struct StateT * v4281 = v4268->a;
  int * v4282 = v4281->regs;
  int v4283 = v4282[8];
  int v4301 = v4283 + 1;
  v4282[8] = v4301;
  struct StateT * v4285 = v4268->b;
  int * v4286 = v4285->regs;
  int v4287 = v4286[8];
  int v4304 = v4287 + 1;
  v4286[8] = v4304;
  struct StateT2 * v4289 = slot_82(v4268);
  return v4289;
}

struct StateT2 * slot_95(struct StateT2 * v4814) {
  struct StateT * v4815 = v4814->a;
  int v4816 = v4815->timer;
  struct StateT * v4817 = v4814->b;
  int v4818 = v4817->timer;
  bool v4839 = v4816 == v4818;
  squared_assert(v4839);
  squared_assume(v4839);
  struct StateT * v4821 = v4814->a;
  int v4822 = v4821->timer;
  int v4841 = v4822 + 1;
  v4821->timer = v4841;
  struct StateT * v4824 = v4814->b;
  int v4825 = v4824->timer;
  int v4843 = v4825 + 1;
  v4824->timer = v4843;
  struct StateT * v4827 = v4814->a;
  int * v4828 = v4827->regs;
  int v4829 = v4828[8];
  int v4847 = v4829 + 1;
  v4828[8] = v4847;
  struct StateT * v4831 = v4814->b;
  int * v4832 = v4831->regs;
  int v4833 = v4832[8];
  int v4850 = v4833 + 1;
  v4832[8] = v4850;
  struct StateT2 * v4835 = slot_96(v4814);
  return v4835;
}

struct StateT2 * slot_115(struct StateT2 * v5594) {
  struct StateT * v5595 = v5594->a;
  int v5596 = v5595->timer;
  struct StateT * v5597 = v5594->b;
  int v5598 = v5597->timer;
  bool v5619 = v5596 == v5598;
  squared_assert(v5619);
  squared_assume(v5619);
  struct StateT * v5601 = v5594->a;
  int v5602 = v5601->timer;
  int v5621 = v5602 + 1;
  v5601->timer = v5621;
  struct StateT * v5604 = v5594->b;
  int v5605 = v5604->timer;
  int v5623 = v5605 + 1;
  v5604->timer = v5623;
  struct StateT * v5607 = v5594->a;
  int * v5608 = v5607->regs;
  int v5609 = v5608[8];
  int v5627 = v5609 + 1;
  v5608[8] = v5627;
  struct StateT * v5611 = v5594->b;
  int * v5612 = v5611->regs;
  int v5613 = v5612[8];
  int v5630 = v5613 + 1;
  v5612[8] = v5630;
  struct StateT2 * v5615 = slot_116(v5594);
  return v5615;
}

struct StateT2 * slot_78(struct StateT2 * v4151) {
  struct StateT * v4152 = v4151->a;
  int v4153 = v4152->timer;
  struct StateT * v4154 = v4151->b;
  int v4155 = v4154->timer;
  bool v4176 = v4153 == v4155;
  squared_assert(v4176);
  squared_assume(v4176);
  struct StateT * v4158 = v4151->a;
  int v4159 = v4158->timer;
  int v4178 = v4159 + 1;
  v4158->timer = v4178;
  struct StateT * v4161 = v4151->b;
  int v4162 = v4161->timer;
  int v4180 = v4162 + 1;
  v4161->timer = v4180;
  struct StateT * v4164 = v4151->a;
  int * v4165 = v4164->regs;
  int v4166 = v4165[8];
  int v4184 = v4166 + 1;
  v4165[8] = v4184;
  struct StateT * v4168 = v4151->b;
  int * v4169 = v4168->regs;
  int v4170 = v4169[8];
  int v4187 = v4170 + 1;
  v4169[8] = v4187;
  struct StateT2 * v4172 = slot_79(v4151);
  return v4172;
}

struct StateT2 * slot_32(struct StateT2 * v2357) {
  struct StateT * v2358 = v2357->a;
  int v2359 = v2358->timer;
  struct StateT * v2360 = v2357->b;
  int v2361 = v2360->timer;
  bool v2382 = v2359 == v2361;
  squared_assert(v2382);
  squared_assume(v2382);
  struct StateT * v2364 = v2357->a;
  int v2365 = v2364->timer;
  int v2384 = v2365 + 1;
  v2364->timer = v2384;
  struct StateT * v2367 = v2357->b;
  int v2368 = v2367->timer;
  int v2386 = v2368 + 1;
  v2367->timer = v2386;
  struct StateT * v2370 = v2357->a;
  int * v2371 = v2370->regs;
  int v2372 = v2371[8];
  int v2390 = v2372 + 1;
  v2371[8] = v2390;
  struct StateT * v2374 = v2357->b;
  int * v2375 = v2374->regs;
  int v2376 = v2375[8];
  int v2393 = v2376 + 1;
  v2375[8] = v2393;
  struct StateT2 * v2378 = slot_33(v2357);
  return v2378;
}

struct StateT2 * slot_205(struct StateT2 * v9104) {
  struct StateT * v9105 = v9104->a;
  int v9106 = v9105->timer;
  struct StateT * v9107 = v9104->b;
  int v9108 = v9107->timer;
  bool v9129 = v9106 == v9108;
  squared_assert(v9129);
  squared_assume(v9129);
  struct StateT * v9111 = v9104->a;
  int v9112 = v9111->timer;
  int v9131 = v9112 + 1;
  v9111->timer = v9131;
  struct StateT * v9114 = v9104->b;
  int v9115 = v9114->timer;
  int v9133 = v9115 + 1;
  v9114->timer = v9133;
  struct StateT * v9117 = v9104->a;
  int * v9118 = v9117->regs;
  int v9119 = v9118[8];
  int v9137 = v9119 + 1;
  v9118[8] = v9137;
  struct StateT * v9121 = v9104->b;
  int * v9122 = v9121->regs;
  int v9123 = v9122[8];
  int v9140 = v9123 + 1;
  v9122[8] = v9140;
  struct StateT2 * v9125 = slot_206(v9104);
  return v9125;
}

struct StateT2 * slot_193(struct StateT2 * v8636) {
  struct StateT * v8637 = v8636->a;
  int v8638 = v8637->timer;
  struct StateT * v8639 = v8636->b;
  int v8640 = v8639->timer;
  bool v8661 = v8638 == v8640;
  squared_assert(v8661);
  squared_assume(v8661);
  struct StateT * v8643 = v8636->a;
  int v8644 = v8643->timer;
  int v8663 = v8644 + 1;
  v8643->timer = v8663;
  struct StateT * v8646 = v8636->b;
  int v8647 = v8646->timer;
  int v8665 = v8647 + 1;
  v8646->timer = v8665;
  struct StateT * v8649 = v8636->a;
  int * v8650 = v8649->regs;
  int v8651 = v8650[8];
  int v8669 = v8651 + 1;
  v8650[8] = v8669;
  struct StateT * v8653 = v8636->b;
  int * v8654 = v8653->regs;
  int v8655 = v8654[8];
  int v8672 = v8655 + 1;
  v8654[8] = v8672;
  struct StateT2 * v8657 = slot_194(v8636);
  return v8657;
}

struct StateT2 * slot_176(struct StateT2 * v7973) {
  struct StateT * v7974 = v7973->a;
  int v7975 = v7974->timer;
  struct StateT * v7976 = v7973->b;
  int v7977 = v7976->timer;
  bool v7998 = v7975 == v7977;
  squared_assert(v7998);
  squared_assume(v7998);
  struct StateT * v7980 = v7973->a;
  int v7981 = v7980->timer;
  int v8000 = v7981 + 1;
  v7980->timer = v8000;
  struct StateT * v7983 = v7973->b;
  int v7984 = v7983->timer;
  int v8002 = v7984 + 1;
  v7983->timer = v8002;
  struct StateT * v7986 = v7973->a;
  int * v7987 = v7986->regs;
  int v7988 = v7987[8];
  int v8006 = v7988 + 1;
  v7987[8] = v8006;
  struct StateT * v7990 = v7973->b;
  int * v7991 = v7990->regs;
  int v7992 = v7991[8];
  int v8009 = v7992 + 1;
  v7991[8] = v8009;
  struct StateT2 * v7994 = slot_177(v7973);
  return v7994;
}

struct StateT2 * slot_189(struct StateT2 * v8480) {
  struct StateT * v8481 = v8480->a;
  int v8482 = v8481->timer;
  struct StateT * v8483 = v8480->b;
  int v8484 = v8483->timer;
  bool v8505 = v8482 == v8484;
  squared_assert(v8505);
  squared_assume(v8505);
  struct StateT * v8487 = v8480->a;
  int v8488 = v8487->timer;
  int v8507 = v8488 + 1;
  v8487->timer = v8507;
  struct StateT * v8490 = v8480->b;
  int v8491 = v8490->timer;
  int v8509 = v8491 + 1;
  v8490->timer = v8509;
  struct StateT * v8493 = v8480->a;
  int * v8494 = v8493->regs;
  int v8495 = v8494[8];
  int v8513 = v8495 + 1;
  v8494[8] = v8513;
  struct StateT * v8497 = v8480->b;
  int * v8498 = v8497->regs;
  int v8499 = v8498[8];
  int v8516 = v8499 + 1;
  v8498[8] = v8516;
  struct StateT2 * v8501 = slot_190(v8480);
  return v8501;
}

struct StateT2 * slot_33(struct StateT2 * v2396) {
  struct StateT * v2397 = v2396->a;
  int v2398 = v2397->timer;
  struct StateT * v2399 = v2396->b;
  int v2400 = v2399->timer;
  bool v2421 = v2398 == v2400;
  squared_assert(v2421);
  squared_assume(v2421);
  struct StateT * v2403 = v2396->a;
  int v2404 = v2403->timer;
  int v2423 = v2404 + 1;
  v2403->timer = v2423;
  struct StateT * v2406 = v2396->b;
  int v2407 = v2406->timer;
  int v2425 = v2407 + 1;
  v2406->timer = v2425;
  struct StateT * v2409 = v2396->a;
  int * v2410 = v2409->regs;
  int v2411 = v2410[8];
  int v2429 = v2411 + 1;
  v2410[8] = v2429;
  struct StateT * v2413 = v2396->b;
  int * v2414 = v2413->regs;
  int v2415 = v2414[8];
  int v2432 = v2415 + 1;
  v2414[8] = v2432;
  struct StateT2 * v2417 = slot_34(v2396);
  return v2417;
}

struct StateT2 * slot_35(struct StateT2 * v2474) {
  struct StateT * v2475 = v2474->a;
  int v2476 = v2475->timer;
  struct StateT * v2477 = v2474->b;
  int v2478 = v2477->timer;
  bool v2499 = v2476 == v2478;
  squared_assert(v2499);
  squared_assume(v2499);
  struct StateT * v2481 = v2474->a;
  int v2482 = v2481->timer;
  int v2501 = v2482 + 1;
  v2481->timer = v2501;
  struct StateT * v2484 = v2474->b;
  int v2485 = v2484->timer;
  int v2503 = v2485 + 1;
  v2484->timer = v2503;
  struct StateT * v2487 = v2474->a;
  int * v2488 = v2487->regs;
  int v2489 = v2488[8];
  int v2507 = v2489 + 1;
  v2488[8] = v2507;
  struct StateT * v2491 = v2474->b;
  int * v2492 = v2491->regs;
  int v2493 = v2492[8];
  int v2510 = v2493 + 1;
  v2492[8] = v2510;
  struct StateT2 * v2495 = slot_36(v2474);
  return v2495;
}

struct StateT2 * slot_210(struct StateT2 * v9299) {
  struct StateT * v9300 = v9299->a;
  int v9301 = v9300->timer;
  struct StateT * v9302 = v9299->b;
  int v9303 = v9302->timer;
  bool v9324 = v9301 == v9303;
  squared_assert(v9324);
  squared_assume(v9324);
  struct StateT * v9306 = v9299->a;
  int v9307 = v9306->timer;
  int v9326 = v9307 + 1;
  v9306->timer = v9326;
  struct StateT * v9309 = v9299->b;
  int v9310 = v9309->timer;
  int v9328 = v9310 + 1;
  v9309->timer = v9328;
  struct StateT * v9312 = v9299->a;
  int * v9313 = v9312->regs;
  int v9314 = v9313[8];
  int v9332 = v9314 + 1;
  v9313[8] = v9332;
  struct StateT * v9316 = v9299->b;
  int * v9317 = v9316->regs;
  int v9318 = v9317[8];
  int v9335 = v9318 + 1;
  v9317[8] = v9335;
  struct StateT2 * v9320 = slot_211(v9299);
  return v9320;
}

struct StateT2 * slot_166(struct StateT2 * v7583) {
  struct StateT * v7584 = v7583->a;
  int v7585 = v7584->timer;
  struct StateT * v7586 = v7583->b;
  int v7587 = v7586->timer;
  bool v7608 = v7585 == v7587;
  squared_assert(v7608);
  squared_assume(v7608);
  struct StateT * v7590 = v7583->a;
  int v7591 = v7590->timer;
  int v7610 = v7591 + 1;
  v7590->timer = v7610;
  struct StateT * v7593 = v7583->b;
  int v7594 = v7593->timer;
  int v7612 = v7594 + 1;
  v7593->timer = v7612;
  struct StateT * v7596 = v7583->a;
  int * v7597 = v7596->regs;
  int v7598 = v7597[8];
  int v7616 = v7598 + 1;
  v7597[8] = v7616;
  struct StateT * v7600 = v7583->b;
  int * v7601 = v7600->regs;
  int v7602 = v7601[8];
  int v7619 = v7602 + 1;
  v7601[8] = v7619;
  struct StateT2 * v7604 = slot_167(v7583);
  return v7604;
}

struct StateT2 * slot_51(struct StateT2 * v3098) {
  struct StateT * v3099 = v3098->a;
  int v3100 = v3099->timer;
  struct StateT * v3101 = v3098->b;
  int v3102 = v3101->timer;
  bool v3123 = v3100 == v3102;
  squared_assert(v3123);
  squared_assume(v3123);
  struct StateT * v3105 = v3098->a;
  int v3106 = v3105->timer;
  int v3125 = v3106 + 1;
  v3105->timer = v3125;
  struct StateT * v3108 = v3098->b;
  int v3109 = v3108->timer;
  int v3127 = v3109 + 1;
  v3108->timer = v3127;
  struct StateT * v3111 = v3098->a;
  int * v3112 = v3111->regs;
  int v3113 = v3112[8];
  int v3131 = v3113 + 1;
  v3112[8] = v3131;
  struct StateT * v3115 = v3098->b;
  int * v3116 = v3115->regs;
  int v3117 = v3116[8];
  int v3134 = v3117 + 1;
  v3116[8] = v3134;
  struct StateT2 * v3119 = slot_52(v3098);
  return v3119;
}

struct StateT2 * slot_52(struct StateT2 * v3137) {
  struct StateT * v3138 = v3137->a;
  int v3139 = v3138->timer;
  struct StateT * v3140 = v3137->b;
  int v3141 = v3140->timer;
  bool v3162 = v3139 == v3141;
  squared_assert(v3162);
  squared_assume(v3162);
  struct StateT * v3144 = v3137->a;
  int v3145 = v3144->timer;
  int v3164 = v3145 + 1;
  v3144->timer = v3164;
  struct StateT * v3147 = v3137->b;
  int v3148 = v3147->timer;
  int v3166 = v3148 + 1;
  v3147->timer = v3166;
  struct StateT * v3150 = v3137->a;
  int * v3151 = v3150->regs;
  int v3152 = v3151[8];
  int v3170 = v3152 + 1;
  v3151[8] = v3170;
  struct StateT * v3154 = v3137->b;
  int * v3155 = v3154->regs;
  int v3156 = v3155[8];
  int v3173 = v3156 + 1;
  v3155[8] = v3173;
  struct StateT2 * v3158 = slot_53(v3137);
  return v3158;
}

struct StateT2 * slot_83(struct StateT2 * v4346) {
  struct StateT * v4347 = v4346->a;
  int v4348 = v4347->timer;
  struct StateT * v4349 = v4346->b;
  int v4350 = v4349->timer;
  bool v4371 = v4348 == v4350;
  squared_assert(v4371);
  squared_assume(v4371);
  struct StateT * v4353 = v4346->a;
  int v4354 = v4353->timer;
  int v4373 = v4354 + 1;
  v4353->timer = v4373;
  struct StateT * v4356 = v4346->b;
  int v4357 = v4356->timer;
  int v4375 = v4357 + 1;
  v4356->timer = v4375;
  struct StateT * v4359 = v4346->a;
  int * v4360 = v4359->regs;
  int v4361 = v4360[8];
  int v4379 = v4361 + 1;
  v4360[8] = v4379;
  struct StateT * v4363 = v4346->b;
  int * v4364 = v4363->regs;
  int v4365 = v4364[8];
  int v4382 = v4365 + 1;
  v4364[8] = v4382;
  struct StateT2 * v4367 = slot_84(v4346);
  return v4367;
}

struct StateT2 * slot_25(struct StateT2 * v2084) {
  struct StateT * v2085 = v2084->a;
  int v2086 = v2085->timer;
  struct StateT * v2087 = v2084->b;
  int v2088 = v2087->timer;
  bool v2109 = v2086 == v2088;
  squared_assert(v2109);
  squared_assume(v2109);
  struct StateT * v2091 = v2084->a;
  int v2092 = v2091->timer;
  int v2111 = v2092 + 1;
  v2091->timer = v2111;
  struct StateT * v2094 = v2084->b;
  int v2095 = v2094->timer;
  int v2113 = v2095 + 1;
  v2094->timer = v2113;
  struct StateT * v2097 = v2084->a;
  int * v2098 = v2097->regs;
  int v2099 = v2098[8];
  int v2117 = v2099 + 1;
  v2098[8] = v2117;
  struct StateT * v2101 = v2084->b;
  int * v2102 = v2101->regs;
  int v2103 = v2102[8];
  int v2120 = v2103 + 1;
  v2102[8] = v2120;
  struct StateT2 * v2105 = slot_26(v2084);
  return v2105;
}

struct StateT2 * slot_209(struct StateT2 * v9260) {
  struct StateT * v9261 = v9260->a;
  int v9262 = v9261->timer;
  struct StateT * v9263 = v9260->b;
  int v9264 = v9263->timer;
  bool v9285 = v9262 == v9264;
  squared_assert(v9285);
  squared_assume(v9285);
  struct StateT * v9267 = v9260->a;
  int v9268 = v9267->timer;
  int v9287 = v9268 + 1;
  v9267->timer = v9287;
  struct StateT * v9270 = v9260->b;
  int v9271 = v9270->timer;
  int v9289 = v9271 + 1;
  v9270->timer = v9289;
  struct StateT * v9273 = v9260->a;
  int * v9274 = v9273->regs;
  int v9275 = v9274[8];
  int v9293 = v9275 + 1;
  v9274[8] = v9293;
  struct StateT * v9277 = v9260->b;
  int * v9278 = v9277->regs;
  int v9279 = v9278[8];
  int v9296 = v9279 + 1;
  v9278[8] = v9296;
  struct StateT2 * v9281 = slot_210(v9260);
  return v9281;
}

struct StateT2 * slot_3(struct StateT2 * v850) {
  struct StateT * v851 = v850->a;
  int v852 = v851->timer;
  struct StateT * v853 = v850->b;
  int v854 = v853->timer;
  bool v875 = v852 == v854;
  squared_assert(v875);
  squared_assume(v875);
  struct StateT * v857 = v850->a;
  int v858 = v857->timer;
  int v877 = v858 + 1;
  v857->timer = v877;
  struct StateT * v860 = v850->b;
  int v861 = v860->timer;
  int v879 = v861 + 1;
  v860->timer = v879;
  struct StateT * v863 = v850->a;
  int * v864 = v863->regs;
  int v865 = v864[6];
  int v883 = v865 << 2;
  v864[6] = v883;
  struct StateT * v867 = v850->b;
  int * v868 = v867->regs;
  int v869 = v868[6];
  int v886 = v869 << 2;
  v868[6] = v886;
  struct StateT2 * v871 = slot_4(v850);
  return v871;
}

struct StateT2 * slot_123(struct StateT2 * v5906) {
  struct StateT * v5907 = v5906->a;
  int v5908 = v5907->timer;
  struct StateT * v5909 = v5906->b;
  int v5910 = v5909->timer;
  bool v5931 = v5908 == v5910;
  squared_assert(v5931);
  squared_assume(v5931);
  struct StateT * v5913 = v5906->a;
  int v5914 = v5913->timer;
  int v5933 = v5914 + 1;
  v5913->timer = v5933;
  struct StateT * v5916 = v5906->b;
  int v5917 = v5916->timer;
  int v5935 = v5917 + 1;
  v5916->timer = v5935;
  struct StateT * v5919 = v5906->a;
  int * v5920 = v5919->regs;
  int v5921 = v5920[8];
  int v5939 = v5921 + 1;
  v5920[8] = v5939;
  struct StateT * v5923 = v5906->b;
  int * v5924 = v5923->regs;
  int v5925 = v5924[8];
  int v5942 = v5925 + 1;
  v5924[8] = v5942;
  struct StateT2 * v5927 = slot_124(v5906);
  return v5927;
}

struct StateT2 * slot_73(struct StateT2 * v3956) {
  struct StateT * v3957 = v3956->a;
  int v3958 = v3957->timer;
  struct StateT * v3959 = v3956->b;
  int v3960 = v3959->timer;
  bool v3981 = v3958 == v3960;
  squared_assert(v3981);
  squared_assume(v3981);
  struct StateT * v3963 = v3956->a;
  int v3964 = v3963->timer;
  int v3983 = v3964 + 1;
  v3963->timer = v3983;
  struct StateT * v3966 = v3956->b;
  int v3967 = v3966->timer;
  int v3985 = v3967 + 1;
  v3966->timer = v3985;
  struct StateT * v3969 = v3956->a;
  int * v3970 = v3969->regs;
  int v3971 = v3970[8];
  int v3989 = v3971 + 1;
  v3970[8] = v3989;
  struct StateT * v3973 = v3956->b;
  int * v3974 = v3973->regs;
  int v3975 = v3974[8];
  int v3992 = v3975 + 1;
  v3974[8] = v3992;
  struct StateT2 * v3977 = slot_74(v3956);
  return v3977;
}

struct StateT2 * slot_198(struct StateT2 * v8831) {
  struct StateT * v8832 = v8831->a;
  int v8833 = v8832->timer;
  struct StateT * v8834 = v8831->b;
  int v8835 = v8834->timer;
  bool v8856 = v8833 == v8835;
  squared_assert(v8856);
  squared_assume(v8856);
  struct StateT * v8838 = v8831->a;
  int v8839 = v8838->timer;
  int v8858 = v8839 + 1;
  v8838->timer = v8858;
  struct StateT * v8841 = v8831->b;
  int v8842 = v8841->timer;
  int v8860 = v8842 + 1;
  v8841->timer = v8860;
  struct StateT * v8844 = v8831->a;
  int * v8845 = v8844->regs;
  int v8846 = v8845[8];
  int v8864 = v8846 + 1;
  v8845[8] = v8864;
  struct StateT * v8848 = v8831->b;
  int * v8849 = v8848->regs;
  int v8850 = v8849[8];
  int v8867 = v8850 + 1;
  v8849[8] = v8867;
  struct StateT2 * v8852 = slot_199(v8831);
  return v8852;
}

struct StateT2 * slot_1(struct StateT2 * v420) {
  struct StateT * v421 = v420->a;
  int v422 = v421->timer;
  struct StateT * v423 = v420->b;
  int v424 = v423->timer;
  bool v647 = v422 == v424;
  squared_assert(v647);
  squared_assume(v647);
  struct StateT * v427 = v420->a;
  int v428 = v427->timer;
  int v649 = v428 + 1;
  v427->timer = v649;
  struct StateT * v430 = v420->b;
  int v431 = v430->timer;
  int v651 = v431 + 1;
  v430->timer = v651;
  struct StateT * v433 = v420->a;
  int * v434 = v433->cache_tags;
  int v435 = v434[0];
  int v436 = v434[1];
  int v437 = v434[8];
  int v438 = v434[9];
  int v439 = v433->timer;
  int v658 = v439 + ((100 ^ (((~(((v437 ^ 10) | (-(v437 ^ 10))) >> 31)) | (~(((v438 ^ 10) | (-(v438 ^ 10))) >> 31))) & 104)) ^ (((~(((v435 ^ 10) | (-(v435 ^ 10))) >> 31)) | (~(((v436 ^ 10) | (-(v436 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v437 ^ 10) | (-(v437 ^ 10))) >> 31)) | (~(((v438 ^ 10) | (-(v438 ^ 10))) >> 31))) & 104)))));
  v433->timer = v658;
  int * v441 = v433->cache_vals;
  bool v659 = !(((~(((v435 ^ 10) | (-(v435 ^ 10))) >> 31)) | (~(((v436 ^ 10) | (-(v436 ^ 10))) >> 31))) == 0);
  int v534;
  if (v659) {
    int * v442 = v433->cache_age;
    int v661 = (~(((v436 ^ 10) | (-(v436 ^ 10))) >> 31)) & 1;
    int v443 = v442[v661];
    int v444 = v442[0];
    int v662 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[0] = v662;
    int * v446 = v433->cache_age;
    int v447 = v446[1];
    int v664 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[1] = v664;
    int * v449 = v433->cache_age;
    v449[v661] = 0;
    v534 = v661;
  } else {
    int * v452 = v433->cache_age;
    int v453 = v452[0];
    int * v454 = v433->cache_tags;
    int v455 = v454[0];
    int v456 = v452[1];
    int v457 = v454[1];
    bool v668 = !(((~(((v437 ^ 10) | (-(v437 ^ 10))) >> 31)) | (~(((v438 ^ 10) | (-(v438 ^ 10))) >> 31))) == 0);
    int v511;
    if (v668) {
      int * v458 = v433->cache_age;
      int v670 = 8 + ((~(((v438 ^ 10) | (-(v438 ^ 10))) >> 31)) & 1);
      int v459 = v458[v670];
      int v460 = v458[8];
      int v671 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
      v458[8] = v671;
      int * v462 = v433->cache_age;
      int v463 = v462[9];
      int v673 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
      v462[9] = v673;
      int * v465 = v433->cache_age;
      v465[v670] = 0;
      v511 = v670;
    } else {
      int * v468 = v433->cache_age;
      int v469 = v468[8];
      int * v470 = v433->cache_tags;
      int v471 = v470[8];
      int v472 = v468[9];
      int v473 = v470[9];
      int * v474 = v433->cache_dirty;
      int v678 = 8 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v475 = v474[v678];
      bool v679 = !(v475 == 0);
      if (v679) {
        int * v476 = v433->cache_tags;
        int v477 = v476[v678];
        int * v478 = v433->cache_vals;
        int v682 = (8 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v479 = v478[v682];
        int v683 = ((8 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v480 = v478[v683];
        int * v481 = v433->mem;
        int v685 = v477 * 2;
        v481[v685] = v479;
        int * v483 = v433->mem;
        int v688 = (v477 * 2) + 1;
        v483[v688] = v480;
        ;
      } else {
        ;
      }
      int * v488 = v433->mem;
      int v489 = v488[20];
      int v490 = v488[21];
      int * v491 = v433->cache_vals;
      int v696 = (8 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v491[v696] = v489;
      int * v493 = v433->cache_vals;
      int v699 = ((8 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v493[v699] = v490;
      int * v495 = v433->cache_tags;
      v495[v678] = 10;
      int * v497 = v433->cache_dirty;
      v497[v678] = 0;
      int * v499 = v433->cache_age;
      v499[v678] = 1;
      int * v501 = v433->cache_age;
      int v502 = v501[v678];
      int v503 = v501[8];
      int v706 = v503 + ((int)((unsigned int)(v503 - v502) >> 31));
      v501[8] = v706;
      int * v505 = v433->cache_age;
      int v506 = v505[9];
      int v708 = v506 + ((int)((unsigned int)(v506 - v502) >> 31));
      v505[9] = v708;
      int * v508 = v433->cache_age;
      v508[v678] = 0;
      v511 = v678;
    }
    int * v512 = v433->cache_vals;
    int v711 = v511 * 2;
    int v513 = v512[v711];
    int v712 = (v511 * 2) + 1;
    int v514 = v512[v712];
    int v713 = ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v512[v713] = v513;
    int * v516 = v433->cache_vals;
    int v716 = (((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v516[v716] = v514;
    int * v518 = v433->cache_tags;
    int v719 = (((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v518[v719] = 10;
    int * v520 = v433->cache_dirty;
    v520[v719] = 0;
    int * v522 = v433->cache_age;
    v522[v719] = 1;
    int * v524 = v433->cache_age;
    int v525 = v524[v719];
    int v526 = v524[0];
    int v724 = v526 + ((int)((unsigned int)(v526 - v525) >> 31));
    v524[0] = v724;
    int * v528 = v433->cache_age;
    int v529 = v528[1];
    int v726 = v529 + ((int)((unsigned int)(v529 - v525) >> 31));
    v528[1] = v726;
    int * v531 = v433->cache_age;
    v531[v719] = 0;
    v534 = v719;
  }
  int v729 = v534 * 2;
  int v535 = v441[v729];
  int * v536 = v433->regs;
  v536[6] = v535;
  struct StateT * v538 = v420->b;
  int * v539 = v538->cache_tags;
  int v540 = v539[0];
  int v541 = v539[1];
  int v542 = v539[8];
  int v543 = v539[9];
  int v544 = v538->timer;
  int v735 = v544 + ((100 ^ (((~(((v542 ^ 10) | (-(v542 ^ 10))) >> 31)) | (~(((v543 ^ 10) | (-(v543 ^ 10))) >> 31))) & 104)) ^ (((~(((v540 ^ 10) | (-(v540 ^ 10))) >> 31)) | (~(((v541 ^ 10) | (-(v541 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v542 ^ 10) | (-(v542 ^ 10))) >> 31)) | (~(((v543 ^ 10) | (-(v543 ^ 10))) >> 31))) & 104)))));
  v538->timer = v735;
  int * v546 = v538->cache_vals;
  bool v736 = !(((~(((v540 ^ 10) | (-(v540 ^ 10))) >> 31)) | (~(((v541 ^ 10) | (-(v541 ^ 10))) >> 31))) == 0);
  int v639;
  if (v736) {
    int * v547 = v538->cache_age;
    int v738 = (~(((v541 ^ 10) | (-(v541 ^ 10))) >> 31)) & 1;
    int v548 = v547[v738];
    int v549 = v547[0];
    int v739 = v549 + ((int)((unsigned int)(v549 - v548) >> 31));
    v547[0] = v739;
    int * v551 = v538->cache_age;
    int v552 = v551[1];
    int v741 = v552 + ((int)((unsigned int)(v552 - v548) >> 31));
    v551[1] = v741;
    int * v554 = v538->cache_age;
    v554[v738] = 0;
    v639 = v738;
  } else {
    int * v557 = v538->cache_age;
    int v558 = v557[0];
    int * v559 = v538->cache_tags;
    int v560 = v559[0];
    int v561 = v557[1];
    int v562 = v559[1];
    bool v745 = !(((~(((v542 ^ 10) | (-(v542 ^ 10))) >> 31)) | (~(((v543 ^ 10) | (-(v543 ^ 10))) >> 31))) == 0);
    int v616;
    if (v745) {
      int * v563 = v538->cache_age;
      int v747 = 8 + ((~(((v543 ^ 10) | (-(v543 ^ 10))) >> 31)) & 1);
      int v564 = v563[v747];
      int v565 = v563[8];
      int v748 = v565 + ((int)((unsigned int)(v565 - v564) >> 31));
      v563[8] = v748;
      int * v567 = v538->cache_age;
      int v568 = v567[9];
      int v750 = v568 + ((int)((unsigned int)(v568 - v564) >> 31));
      v567[9] = v750;
      int * v570 = v538->cache_age;
      v570[v747] = 0;
      v616 = v747;
    } else {
      int * v573 = v538->cache_age;
      int v574 = v573[8];
      int * v575 = v538->cache_tags;
      int v576 = v575[8];
      int v577 = v573[9];
      int v578 = v575[9];
      int * v579 = v538->cache_dirty;
      int v755 = 8 + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v580 = v579[v755];
      bool v756 = !(v580 == 0);
      if (v756) {
        int * v581 = v538->cache_tags;
        int v582 = v581[v755];
        int * v583 = v538->cache_vals;
        int v759 = (8 + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v584 = v583[v759];
        int v760 = ((8 + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v585 = v583[v760];
        int * v586 = v538->mem;
        int v762 = v582 * 2;
        v586[v762] = v584;
        int * v588 = v538->mem;
        int v765 = (v582 * 2) + 1;
        v588[v765] = v585;
        ;
      } else {
        ;
      }
      int * v593 = v538->mem;
      int v594 = v593[20];
      int v595 = v593[21];
      int * v596 = v538->cache_vals;
      int v773 = (8 + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v596[v773] = v594;
      int * v598 = v538->cache_vals;
      int v776 = ((8 + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v598[v776] = v595;
      int * v600 = v538->cache_tags;
      v600[v755] = 10;
      int * v602 = v538->cache_dirty;
      v602[v755] = 0;
      int * v604 = v538->cache_age;
      v604[v755] = 1;
      int * v606 = v538->cache_age;
      int v607 = v606[v755];
      int v608 = v606[8];
      int v783 = v608 + ((int)((unsigned int)(v608 - v607) >> 31));
      v606[8] = v783;
      int * v610 = v538->cache_age;
      int v611 = v610[9];
      int v785 = v611 + ((int)((unsigned int)(v611 - v607) >> 31));
      v610[9] = v785;
      int * v613 = v538->cache_age;
      v613[v755] = 0;
      v616 = v755;
    }
    int * v617 = v538->cache_vals;
    int v788 = v616 * 2;
    int v618 = v617[v788];
    int v789 = (v616 * 2) + 1;
    int v619 = v617[v789];
    int v790 = ((((v558 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v617[v790] = v618;
    int * v621 = v538->cache_vals;
    int v793 = (((((v558 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v621[v793] = v619;
    int * v623 = v538->cache_tags;
    int v796 = (((v558 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v623[v796] = 10;
    int * v625 = v538->cache_dirty;
    v625[v796] = 0;
    int * v627 = v538->cache_age;
    v627[v796] = 1;
    int * v629 = v538->cache_age;
    int v630 = v629[v796];
    int v631 = v629[0];
    int v801 = v631 + ((int)((unsigned int)(v631 - v630) >> 31));
    v629[0] = v801;
    int * v633 = v538->cache_age;
    int v634 = v633[1];
    int v803 = v634 + ((int)((unsigned int)(v634 - v630) >> 31));
    v633[1] = v803;
    int * v636 = v538->cache_age;
    v636[v796] = 0;
    v639 = v796;
  }
  int v806 = v639 * 2;
  int v640 = v546[v806];
  int * v641 = v538->regs;
  v641[6] = v640;
  struct StateT2 * v643 = slot_2(v420);
  return v643;
}

struct StateT2 * slot_187(struct StateT2 * v8402) {
  struct StateT * v8403 = v8402->a;
  int v8404 = v8403->timer;
  struct StateT * v8405 = v8402->b;
  int v8406 = v8405->timer;
  bool v8427 = v8404 == v8406;
  squared_assert(v8427);
  squared_assume(v8427);
  struct StateT * v8409 = v8402->a;
  int v8410 = v8409->timer;
  int v8429 = v8410 + 1;
  v8409->timer = v8429;
  struct StateT * v8412 = v8402->b;
  int v8413 = v8412->timer;
  int v8431 = v8413 + 1;
  v8412->timer = v8431;
  struct StateT * v8415 = v8402->a;
  int * v8416 = v8415->regs;
  int v8417 = v8416[8];
  int v8435 = v8417 + 1;
  v8416[8] = v8435;
  struct StateT * v8419 = v8402->b;
  int * v8420 = v8419->regs;
  int v8421 = v8420[8];
  int v8438 = v8421 + 1;
  v8420[8] = v8438;
  struct StateT2 * v8423 = slot_188(v8402);
  return v8423;
}

struct StateT2 * slot_97(struct StateT2 * v4892) {
  struct StateT * v4893 = v4892->a;
  int v4894 = v4893->timer;
  struct StateT * v4895 = v4892->b;
  int v4896 = v4895->timer;
  bool v4917 = v4894 == v4896;
  squared_assert(v4917);
  squared_assume(v4917);
  struct StateT * v4899 = v4892->a;
  int v4900 = v4899->timer;
  int v4919 = v4900 + 1;
  v4899->timer = v4919;
  struct StateT * v4902 = v4892->b;
  int v4903 = v4902->timer;
  int v4921 = v4903 + 1;
  v4902->timer = v4921;
  struct StateT * v4905 = v4892->a;
  int * v4906 = v4905->regs;
  int v4907 = v4906[8];
  int v4925 = v4907 + 1;
  v4906[8] = v4925;
  struct StateT * v4909 = v4892->b;
  int * v4910 = v4909->regs;
  int v4911 = v4910[8];
  int v4928 = v4911 + 1;
  v4910[8] = v4928;
  struct StateT2 * v4913 = slot_98(v4892);
  return v4913;
}

struct StateT2 * slot_182(struct StateT2 * v8207) {
  struct StateT * v8208 = v8207->a;
  int v8209 = v8208->timer;
  struct StateT * v8210 = v8207->b;
  int v8211 = v8210->timer;
  bool v8232 = v8209 == v8211;
  squared_assert(v8232);
  squared_assume(v8232);
  struct StateT * v8214 = v8207->a;
  int v8215 = v8214->timer;
  int v8234 = v8215 + 1;
  v8214->timer = v8234;
  struct StateT * v8217 = v8207->b;
  int v8218 = v8217->timer;
  int v8236 = v8218 + 1;
  v8217->timer = v8236;
  struct StateT * v8220 = v8207->a;
  int * v8221 = v8220->regs;
  int v8222 = v8221[8];
  int v8240 = v8222 + 1;
  v8221[8] = v8240;
  struct StateT * v8224 = v8207->b;
  int * v8225 = v8224->regs;
  int v8226 = v8225[8];
  int v8243 = v8226 + 1;
  v8225[8] = v8243;
  struct StateT2 * v8228 = slot_183(v8207);
  return v8228;
}

struct StateT2 * slot_38(struct StateT2 * v2591) {
  struct StateT * v2592 = v2591->a;
  int v2593 = v2592->timer;
  struct StateT * v2594 = v2591->b;
  int v2595 = v2594->timer;
  bool v2616 = v2593 == v2595;
  squared_assert(v2616);
  squared_assume(v2616);
  struct StateT * v2598 = v2591->a;
  int v2599 = v2598->timer;
  int v2618 = v2599 + 1;
  v2598->timer = v2618;
  struct StateT * v2601 = v2591->b;
  int v2602 = v2601->timer;
  int v2620 = v2602 + 1;
  v2601->timer = v2620;
  struct StateT * v2604 = v2591->a;
  int * v2605 = v2604->regs;
  int v2606 = v2605[8];
  int v2624 = v2606 + 1;
  v2605[8] = v2624;
  struct StateT * v2608 = v2591->b;
  int * v2609 = v2608->regs;
  int v2610 = v2609[8];
  int v2627 = v2610 + 1;
  v2609[8] = v2627;
  struct StateT2 * v2612 = slot_39(v2591);
  return v2612;
}

struct StateT2 * slot_178(struct StateT2 * v8051) {
  struct StateT * v8052 = v8051->a;
  int v8053 = v8052->timer;
  struct StateT * v8054 = v8051->b;
  int v8055 = v8054->timer;
  bool v8076 = v8053 == v8055;
  squared_assert(v8076);
  squared_assume(v8076);
  struct StateT * v8058 = v8051->a;
  int v8059 = v8058->timer;
  int v8078 = v8059 + 1;
  v8058->timer = v8078;
  struct StateT * v8061 = v8051->b;
  int v8062 = v8061->timer;
  int v8080 = v8062 + 1;
  v8061->timer = v8080;
  struct StateT * v8064 = v8051->a;
  int * v8065 = v8064->regs;
  int v8066 = v8065[8];
  int v8084 = v8066 + 1;
  v8065[8] = v8084;
  struct StateT * v8068 = v8051->b;
  int * v8069 = v8068->regs;
  int v8070 = v8069[8];
  int v8087 = v8070 + 1;
  v8069[8] = v8087;
  struct StateT2 * v8072 = slot_179(v8051);
  return v8072;
}

struct StateT2 * slot_106(struct StateT2 * v5243) {
  struct StateT * v5244 = v5243->a;
  int v5245 = v5244->timer;
  struct StateT * v5246 = v5243->b;
  int v5247 = v5246->timer;
  bool v5268 = v5245 == v5247;
  squared_assert(v5268);
  squared_assume(v5268);
  struct StateT * v5250 = v5243->a;
  int v5251 = v5250->timer;
  int v5270 = v5251 + 1;
  v5250->timer = v5270;
  struct StateT * v5253 = v5243->b;
  int v5254 = v5253->timer;
  int v5272 = v5254 + 1;
  v5253->timer = v5272;
  struct StateT * v5256 = v5243->a;
  int * v5257 = v5256->regs;
  int v5258 = v5257[8];
  int v5276 = v5258 + 1;
  v5257[8] = v5276;
  struct StateT * v5260 = v5243->b;
  int * v5261 = v5260->regs;
  int v5262 = v5261[8];
  int v5279 = v5262 + 1;
  v5261[8] = v5279;
  struct StateT2 * v5264 = slot_107(v5243);
  return v5264;
}

struct StateT2 * slot_98(struct StateT2 * v4931) {
  struct StateT * v4932 = v4931->a;
  int v4933 = v4932->timer;
  struct StateT * v4934 = v4931->b;
  int v4935 = v4934->timer;
  bool v4956 = v4933 == v4935;
  squared_assert(v4956);
  squared_assume(v4956);
  struct StateT * v4938 = v4931->a;
  int v4939 = v4938->timer;
  int v4958 = v4939 + 1;
  v4938->timer = v4958;
  struct StateT * v4941 = v4931->b;
  int v4942 = v4941->timer;
  int v4960 = v4942 + 1;
  v4941->timer = v4960;
  struct StateT * v4944 = v4931->a;
  int * v4945 = v4944->regs;
  int v4946 = v4945[8];
  int v4964 = v4946 + 1;
  v4945[8] = v4964;
  struct StateT * v4948 = v4931->b;
  int * v4949 = v4948->regs;
  int v4950 = v4949[8];
  int v4967 = v4950 + 1;
  v4949[8] = v4967;
  struct StateT2 * v4952 = slot_99(v4931);
  return v4952;
}

struct StateT2 * slot_159(struct StateT2 * v7310) {
  struct StateT * v7311 = v7310->a;
  int v7312 = v7311->timer;
  struct StateT * v7313 = v7310->b;
  int v7314 = v7313->timer;
  bool v7335 = v7312 == v7314;
  squared_assert(v7335);
  squared_assume(v7335);
  struct StateT * v7317 = v7310->a;
  int v7318 = v7317->timer;
  int v7337 = v7318 + 1;
  v7317->timer = v7337;
  struct StateT * v7320 = v7310->b;
  int v7321 = v7320->timer;
  int v7339 = v7321 + 1;
  v7320->timer = v7339;
  struct StateT * v7323 = v7310->a;
  int * v7324 = v7323->regs;
  int v7325 = v7324[8];
  int v7343 = v7325 + 1;
  v7324[8] = v7343;
  struct StateT * v7327 = v7310->b;
  int * v7328 = v7327->regs;
  int v7329 = v7328[8];
  int v7346 = v7329 + 1;
  v7328[8] = v7346;
  struct StateT2 * v7331 = slot_160(v7310);
  return v7331;
}

struct StateT2 * slot_46(struct StateT2 * v2903) {
  struct StateT * v2904 = v2903->a;
  int v2905 = v2904->timer;
  struct StateT * v2906 = v2903->b;
  int v2907 = v2906->timer;
  bool v2928 = v2905 == v2907;
  squared_assert(v2928);
  squared_assume(v2928);
  struct StateT * v2910 = v2903->a;
  int v2911 = v2910->timer;
  int v2930 = v2911 + 1;
  v2910->timer = v2930;
  struct StateT * v2913 = v2903->b;
  int v2914 = v2913->timer;
  int v2932 = v2914 + 1;
  v2913->timer = v2932;
  struct StateT * v2916 = v2903->a;
  int * v2917 = v2916->regs;
  int v2918 = v2917[8];
  int v2936 = v2918 + 1;
  v2917[8] = v2936;
  struct StateT * v2920 = v2903->b;
  int * v2921 = v2920->regs;
  int v2922 = v2921[8];
  int v2939 = v2922 + 1;
  v2921[8] = v2939;
  struct StateT2 * v2924 = slot_47(v2903);
  return v2924;
}

struct StateT2 * slot_212(struct StateT2 * v9377) {
  struct StateT * v9378 = v9377->a;
  int v9379 = v9378->timer;
  struct StateT * v9380 = v9377->b;
  int v9381 = v9380->timer;
  bool v9402 = v9379 == v9381;
  squared_assert(v9402);
  squared_assume(v9402);
  struct StateT * v9384 = v9377->a;
  int v9385 = v9384->timer;
  int v9404 = v9385 + 1;
  v9384->timer = v9404;
  struct StateT * v9387 = v9377->b;
  int v9388 = v9387->timer;
  int v9406 = v9388 + 1;
  v9387->timer = v9406;
  struct StateT * v9390 = v9377->a;
  int * v9391 = v9390->regs;
  int v9392 = v9391[8];
  int v9410 = v9392 + 1;
  v9391[8] = v9410;
  struct StateT * v9394 = v9377->b;
  int * v9395 = v9394->regs;
  int v9396 = v9395[8];
  int v9413 = v9396 + 1;
  v9395[8] = v9413;
  struct StateT2 * v9398 = slot_213(v9377);
  return v9398;
}

struct StateT2 * slot_132(struct StateT2 * v6257) {
  struct StateT * v6258 = v6257->a;
  int v6259 = v6258->timer;
  struct StateT * v6260 = v6257->b;
  int v6261 = v6260->timer;
  bool v6282 = v6259 == v6261;
  squared_assert(v6282);
  squared_assume(v6282);
  struct StateT * v6264 = v6257->a;
  int v6265 = v6264->timer;
  int v6284 = v6265 + 1;
  v6264->timer = v6284;
  struct StateT * v6267 = v6257->b;
  int v6268 = v6267->timer;
  int v6286 = v6268 + 1;
  v6267->timer = v6286;
  struct StateT * v6270 = v6257->a;
  int * v6271 = v6270->regs;
  int v6272 = v6271[8];
  int v6290 = v6272 + 1;
  v6271[8] = v6290;
  struct StateT * v6274 = v6257->b;
  int * v6275 = v6274->regs;
  int v6276 = v6275[8];
  int v6293 = v6276 + 1;
  v6275[8] = v6293;
  struct StateT2 * v6278 = slot_133(v6257);
  return v6278;
}

struct StateT2 * slot_130(struct StateT2 * v6179) {
  struct StateT * v6180 = v6179->a;
  int v6181 = v6180->timer;
  struct StateT * v6182 = v6179->b;
  int v6183 = v6182->timer;
  bool v6204 = v6181 == v6183;
  squared_assert(v6204);
  squared_assume(v6204);
  struct StateT * v6186 = v6179->a;
  int v6187 = v6186->timer;
  int v6206 = v6187 + 1;
  v6186->timer = v6206;
  struct StateT * v6189 = v6179->b;
  int v6190 = v6189->timer;
  int v6208 = v6190 + 1;
  v6189->timer = v6208;
  struct StateT * v6192 = v6179->a;
  int * v6193 = v6192->regs;
  int v6194 = v6193[8];
  int v6212 = v6194 + 1;
  v6193[8] = v6212;
  struct StateT * v6196 = v6179->b;
  int * v6197 = v6196->regs;
  int v6198 = v6197[8];
  int v6215 = v6198 + 1;
  v6197[8] = v6215;
  struct StateT2 * v6200 = slot_131(v6179);
  return v6200;
}

struct StateT2 * slot_211(struct StateT2 * v9338) {
  struct StateT * v9339 = v9338->a;
  int v9340 = v9339->timer;
  struct StateT * v9341 = v9338->b;
  int v9342 = v9341->timer;
  bool v9363 = v9340 == v9342;
  squared_assert(v9363);
  squared_assume(v9363);
  struct StateT * v9345 = v9338->a;
  int v9346 = v9345->timer;
  int v9365 = v9346 + 1;
  v9345->timer = v9365;
  struct StateT * v9348 = v9338->b;
  int v9349 = v9348->timer;
  int v9367 = v9349 + 1;
  v9348->timer = v9367;
  struct StateT * v9351 = v9338->a;
  int * v9352 = v9351->regs;
  int v9353 = v9352[8];
  int v9371 = v9353 + 1;
  v9352[8] = v9371;
  struct StateT * v9355 = v9338->b;
  int * v9356 = v9355->regs;
  int v9357 = v9356[8];
  int v9374 = v9357 + 1;
  v9356[8] = v9374;
  struct StateT2 * v9359 = slot_212(v9338);
  return v9359;
}

struct StateT2 * slot_20(struct StateT2 * v1889) {
  struct StateT * v1890 = v1889->a;
  int v1891 = v1890->timer;
  struct StateT * v1892 = v1889->b;
  int v1893 = v1892->timer;
  bool v1914 = v1891 == v1893;
  squared_assert(v1914);
  squared_assume(v1914);
  struct StateT * v1896 = v1889->a;
  int v1897 = v1896->timer;
  int v1916 = v1897 + 1;
  v1896->timer = v1916;
  struct StateT * v1899 = v1889->b;
  int v1900 = v1899->timer;
  int v1918 = v1900 + 1;
  v1899->timer = v1918;
  struct StateT * v1902 = v1889->a;
  int * v1903 = v1902->regs;
  int v1904 = v1903[8];
  int v1922 = v1904 + 1;
  v1903[8] = v1922;
  struct StateT * v1906 = v1889->b;
  int * v1907 = v1906->regs;
  int v1908 = v1907[8];
  int v1925 = v1908 + 1;
  v1907[8] = v1925;
  struct StateT2 * v1910 = slot_21(v1889);
  return v1910;
}

struct StateT2 * slot_141(struct StateT2 * v6608) {
  struct StateT * v6609 = v6608->a;
  int v6610 = v6609->timer;
  struct StateT * v6611 = v6608->b;
  int v6612 = v6611->timer;
  bool v6633 = v6610 == v6612;
  squared_assert(v6633);
  squared_assume(v6633);
  struct StateT * v6615 = v6608->a;
  int v6616 = v6615->timer;
  int v6635 = v6616 + 1;
  v6615->timer = v6635;
  struct StateT * v6618 = v6608->b;
  int v6619 = v6618->timer;
  int v6637 = v6619 + 1;
  v6618->timer = v6637;
  struct StateT * v6621 = v6608->a;
  int * v6622 = v6621->regs;
  int v6623 = v6622[8];
  int v6641 = v6623 + 1;
  v6622[8] = v6641;
  struct StateT * v6625 = v6608->b;
  int * v6626 = v6625->regs;
  int v6627 = v6626[8];
  int v6644 = v6627 + 1;
  v6626[8] = v6644;
  struct StateT2 * v6629 = slot_142(v6608);
  return v6629;
}

struct StateT2 * slot_61(struct StateT2 * v3488) {
  struct StateT * v3489 = v3488->a;
  int v3490 = v3489->timer;
  struct StateT * v3491 = v3488->b;
  int v3492 = v3491->timer;
  bool v3513 = v3490 == v3492;
  squared_assert(v3513);
  squared_assume(v3513);
  struct StateT * v3495 = v3488->a;
  int v3496 = v3495->timer;
  int v3515 = v3496 + 1;
  v3495->timer = v3515;
  struct StateT * v3498 = v3488->b;
  int v3499 = v3498->timer;
  int v3517 = v3499 + 1;
  v3498->timer = v3517;
  struct StateT * v3501 = v3488->a;
  int * v3502 = v3501->regs;
  int v3503 = v3502[8];
  int v3521 = v3503 + 1;
  v3502[8] = v3521;
  struct StateT * v3505 = v3488->b;
  int * v3506 = v3505->regs;
  int v3507 = v3506[8];
  int v3524 = v3507 + 1;
  v3506[8] = v3524;
  struct StateT2 * v3509 = slot_62(v3488);
  return v3509;
}

struct StateT2 * slot_30(struct StateT2 * v2279) {
  struct StateT * v2280 = v2279->a;
  int v2281 = v2280->timer;
  struct StateT * v2282 = v2279->b;
  int v2283 = v2282->timer;
  bool v2304 = v2281 == v2283;
  squared_assert(v2304);
  squared_assume(v2304);
  struct StateT * v2286 = v2279->a;
  int v2287 = v2286->timer;
  int v2306 = v2287 + 1;
  v2286->timer = v2306;
  struct StateT * v2289 = v2279->b;
  int v2290 = v2289->timer;
  int v2308 = v2290 + 1;
  v2289->timer = v2308;
  struct StateT * v2292 = v2279->a;
  int * v2293 = v2292->regs;
  int v2294 = v2293[8];
  int v2312 = v2294 + 1;
  v2293[8] = v2312;
  struct StateT * v2296 = v2279->b;
  int * v2297 = v2296->regs;
  int v2298 = v2297[8];
  int v2315 = v2298 + 1;
  v2297[8] = v2315;
  struct StateT2 * v2300 = slot_31(v2279);
  return v2300;
}

struct StateT2 * slot_4(struct StateT2 * v889) {
  struct StateT * v890 = v889->a;
  int v891 = v890->timer;
  struct StateT * v892 = v889->b;
  int v893 = v892->timer;
  bool v1120 = v891 == v893;
  squared_assert(v1120);
  squared_assume(v1120);
  struct StateT * v896 = v889->a;
  int v897 = v896->timer;
  int v1122 = v897 + 1;
  v896->timer = v1122;
  struct StateT * v899 = v889->b;
  int v900 = v899->timer;
  int v1124 = v900 + 1;
  v899->timer = v1124;
  struct StateT * v902 = v889->a;
  int * v903 = v902->regs;
  int v904 = v903[6];
  int * v905 = v902->cache_tags;
  int v1129 = (((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2;
  int v906 = v905[v1129];
  int v1130 = ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2) + 1;
  int v907 = v905[v1130];
  int v1131 = 4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2);
  int v908 = v905[v1131];
  int v1132 = (4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v909 = v905[v1132];
  int v910 = v902->timer;
  int v1133 = v910 + ((100 ^ (((~(((v908 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v908 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) | (~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) | (~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v908 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v908 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) | (~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31))) & 104)))));
  v902->timer = v1133;
  int * v912 = v902->cache_vals;
  bool v1134 = !(((~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) | (~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31))) == 0);
  int v1005;
  if (v1134) {
    int * v913 = v902->cache_age;
    int v1136 = ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2) + ((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) & 1);
    int v914 = v913[v1136];
    int v915 = v913[v1129];
    int v1137 = v915 + ((int)((unsigned int)(v915 - v914) >> 31));
    v913[v1129] = v1137;
    int * v917 = v902->cache_age;
    int v918 = v917[v1130];
    int v1139 = v918 + ((int)((unsigned int)(v918 - v914) >> 31));
    v917[v1130] = v1139;
    int * v920 = v902->cache_age;
    v920[v1136] = 0;
    v1005 = v1136;
  } else {
    int * v923 = v902->cache_age;
    int v1143 = (((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2;
    int v924 = v923[v1143];
    int * v925 = v902->cache_tags;
    int v926 = v925[v1143];
    int v927 = v923[v1130];
    int v928 = v925[v1130];
    bool v1145 = !(((~(((v908 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v908 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) | (~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31))) == 0);
    int v982;
    if (v1145) {
      int * v929 = v902->cache_age;
      int v1147 = (4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + ((~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1))))) >> 31)) & 1);
      int v930 = v929[v1147];
      int v931 = v929[v1131];
      int v1148 = v931 + ((int)((unsigned int)(v931 - v930) >> 31));
      v929[v1131] = v1148;
      int * v933 = v902->cache_age;
      int v934 = v933[v1132];
      int v1150 = v934 + ((int)((unsigned int)(v934 - v930) >> 31));
      v933[v1132] = v1150;
      int * v936 = v902->cache_age;
      v936[v1147] = 0;
      v982 = v1147;
    } else {
      int * v939 = v902->cache_age;
      int v1154 = 4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2);
      int v940 = v939[v1154];
      int * v941 = v902->cache_tags;
      int v942 = v941[v1154];
      int v943 = v939[v1132];
      int v944 = v941[v1132];
      int * v945 = v902->cache_dirty;
      int v1157 = (4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + ((((v940 + ((~(((v942 ^ -1) | (-(v942 ^ -1))) >> 31)) & 2)) - (v943 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v946 = v945[v1157];
      bool v1158 = !(v946 == 0);
      if (v1158) {
        int * v947 = v902->cache_tags;
        int v948 = v947[v1157];
        int * v949 = v902->cache_vals;
        int v1161 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + ((((v940 + ((~(((v942 ^ -1) | (-(v942 ^ -1))) >> 31)) & 2)) - (v943 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v950 = v949[v1161];
        int v1162 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + ((((v940 + ((~(((v942 ^ -1) | (-(v942 ^ -1))) >> 31)) & 2)) - (v943 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v951 = v949[v1162];
        int * v952 = v902->mem;
        int v1164 = v948 * 2;
        v952[v1164] = v950;
        int * v954 = v902->mem;
        int v1167 = (v948 * 2) + 1;
        v954[v1167] = v951;
        ;
      } else {
        ;
      }
      int * v959 = v902->mem;
      int v1172 = ((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) * 2;
      int v960 = v959[v1172];
      int v1173 = (((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) * 2) + 1;
      int v961 = v959[v1173];
      int * v962 = v902->cache_vals;
      int v1175 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + ((((v940 + ((~(((v942 ^ -1) | (-(v942 ^ -1))) >> 31)) & 2)) - (v943 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v962[v1175] = v960;
      int * v964 = v902->cache_vals;
      int v1178 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 3) * 2)) + ((((v940 + ((~(((v942 ^ -1) | (-(v942 ^ -1))) >> 31)) & 2)) - (v943 + ((~(((v944 ^ -1) | (-(v944 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v964[v1178] = v961;
      int * v966 = v902->cache_tags;
      int v1181 = (int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1);
      v966[v1157] = v1181;
      int * v968 = v902->cache_dirty;
      v968[v1157] = 0;
      int * v970 = v902->cache_age;
      v970[v1157] = 1;
      int * v972 = v902->cache_age;
      int v973 = v972[v1157];
      int v974 = v972[v1131];
      int v1187 = v974 + ((int)((unsigned int)(v974 - v973) >> 31));
      v972[v1131] = v1187;
      int * v976 = v902->cache_age;
      int v977 = v976[v1132];
      int v1189 = v977 + ((int)((unsigned int)(v977 - v973) >> 31));
      v976[v1132] = v1189;
      int * v979 = v902->cache_age;
      v979[v1157] = 0;
      v982 = v1157;
    }
    int * v983 = v902->cache_vals;
    int v1192 = v982 * 2;
    int v984 = v983[v1192];
    int v1193 = (v982 * 2) + 1;
    int v985 = v983[v1193];
    int v1194 = (((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2) + ((((v924 + ((~(((v926 ^ -1) | (-(v926 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v928 ^ -1) | (-(v928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v983[v1194] = v984;
    int * v987 = v902->cache_vals;
    int v1197 = ((((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2) + ((((v924 + ((~(((v926 ^ -1) | (-(v926 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v928 ^ -1) | (-(v928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v987[v1197] = v985;
    int * v989 = v902->cache_tags;
    int v1200 = ((((int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1)) & 1) * 2) + ((((v924 + ((~(((v926 ^ -1) | (-(v926 ^ -1))) >> 31)) & 2)) - (v927 + ((~(((v928 ^ -1) | (-(v928 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1201 = (int)((unsigned int)((int)((unsigned int)v904 >> 2)) >> 1);
    v989[v1200] = v1201;
    int * v991 = v902->cache_dirty;
    v991[v1200] = 0;
    int * v993 = v902->cache_age;
    v993[v1200] = 1;
    int * v995 = v902->cache_age;
    int v996 = v995[v1200];
    int v997 = v995[v1129];
    int v1207 = v997 + ((int)((unsigned int)(v997 - v996) >> 31));
    v995[v1129] = v1207;
    int * v999 = v902->cache_age;
    int v1000 = v999[v1130];
    int v1209 = v1000 + ((int)((unsigned int)(v1000 - v996) >> 31));
    v999[v1130] = v1209;
    int * v1002 = v902->cache_age;
    v1002[v1200] = 0;
    v1005 = v1200;
  }
  int v1212 = (v1005 * 2) + (((int)((unsigned int)v904 >> 2)) & 1);
  int v1006 = v912[v1212];
  int * v1007 = v902->regs;
  v1007[7] = v1006;
  struct StateT * v1009 = v889->b;
  int * v1010 = v1009->regs;
  int v1011 = v1010[6];
  int * v1012 = v1009->cache_tags;
  int v1219 = (((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2;
  int v1013 = v1012[v1219];
  int v1220 = ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1014 = v1012[v1220];
  int v1221 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2);
  int v1015 = v1012[v1221];
  int v1222 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1016 = v1012[v1222];
  int v1017 = v1009->timer;
  int v1223 = v1017 + ((100 ^ (((~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1014 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1014 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1009->timer = v1223;
  int * v1019 = v1009->cache_vals;
  bool v1224 = !(((~(((v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1013 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1014 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1014 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) == 0);
  int v1112;
  if (v1224) {
    int * v1020 = v1009->cache_age;
    int v1226 = ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((~(((v1014 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1014 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) & 1);
    int v1021 = v1020[v1226];
    int v1022 = v1020[v1219];
    int v1227 = v1022 + ((int)((unsigned int)(v1022 - v1021) >> 31));
    v1020[v1219] = v1227;
    int * v1024 = v1009->cache_age;
    int v1025 = v1024[v1220];
    int v1229 = v1025 + ((int)((unsigned int)(v1025 - v1021) >> 31));
    v1024[v1220] = v1229;
    int * v1027 = v1009->cache_age;
    v1027[v1226] = 0;
    v1112 = v1226;
  } else {
    int * v1030 = v1009->cache_age;
    int v1233 = (((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2;
    int v1031 = v1030[v1233];
    int * v1032 = v1009->cache_tags;
    int v1033 = v1032[v1233];
    int v1034 = v1030[v1220];
    int v1035 = v1032[v1220];
    bool v1235 = !(((~(((v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1015 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) | (~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31))) == 0);
    int v1089;
    if (v1235) {
      int * v1036 = v1009->cache_age;
      int v1237 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))) | (-(v1016 ^ ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1))))) >> 31)) & 1);
      int v1037 = v1036[v1237];
      int v1038 = v1036[v1221];
      int v1238 = v1038 + ((int)((unsigned int)(v1038 - v1037) >> 31));
      v1036[v1221] = v1238;
      int * v1040 = v1009->cache_age;
      int v1041 = v1040[v1222];
      int v1240 = v1041 + ((int)((unsigned int)(v1041 - v1037) >> 31));
      v1040[v1222] = v1240;
      int * v1043 = v1009->cache_age;
      v1043[v1237] = 0;
      v1089 = v1237;
    } else {
      int * v1046 = v1009->cache_age;
      int v1244 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2);
      int v1047 = v1046[v1244];
      int * v1048 = v1009->cache_tags;
      int v1049 = v1048[v1244];
      int v1050 = v1046[v1222];
      int v1051 = v1048[v1222];
      int * v1052 = v1009->cache_dirty;
      int v1247 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1047 + ((~(((v1049 ^ -1) | (-(v1049 ^ -1))) >> 31)) & 2)) - (v1050 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1053 = v1052[v1247];
      bool v1248 = !(v1053 == 0);
      if (v1248) {
        int * v1054 = v1009->cache_tags;
        int v1055 = v1054[v1247];
        int * v1056 = v1009->cache_vals;
        int v1251 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1047 + ((~(((v1049 ^ -1) | (-(v1049 ^ -1))) >> 31)) & 2)) - (v1050 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1057 = v1056[v1251];
        int v1252 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1047 + ((~(((v1049 ^ -1) | (-(v1049 ^ -1))) >> 31)) & 2)) - (v1050 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1058 = v1056[v1252];
        int * v1059 = v1009->mem;
        int v1254 = v1055 * 2;
        v1059[v1254] = v1057;
        int * v1061 = v1009->mem;
        int v1257 = (v1055 * 2) + 1;
        v1061[v1257] = v1058;
        ;
      } else {
        ;
      }
      int * v1066 = v1009->mem;
      int v1262 = ((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) * 2;
      int v1067 = v1066[v1262];
      int v1263 = (((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) * 2) + 1;
      int v1068 = v1066[v1263];
      int * v1069 = v1009->cache_vals;
      int v1265 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1047 + ((~(((v1049 ^ -1) | (-(v1049 ^ -1))) >> 31)) & 2)) - (v1050 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1069[v1265] = v1067;
      int * v1071 = v1009->cache_vals;
      int v1268 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 3) * 2)) + ((((v1047 + ((~(((v1049 ^ -1) | (-(v1049 ^ -1))) >> 31)) & 2)) - (v1050 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1071[v1268] = v1068;
      int * v1073 = v1009->cache_tags;
      int v1271 = (int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1);
      v1073[v1247] = v1271;
      int * v1075 = v1009->cache_dirty;
      v1075[v1247] = 0;
      int * v1077 = v1009->cache_age;
      v1077[v1247] = 1;
      int * v1079 = v1009->cache_age;
      int v1080 = v1079[v1247];
      int v1081 = v1079[v1221];
      int v1277 = v1081 + ((int)((unsigned int)(v1081 - v1080) >> 31));
      v1079[v1221] = v1277;
      int * v1083 = v1009->cache_age;
      int v1084 = v1083[v1222];
      int v1279 = v1084 + ((int)((unsigned int)(v1084 - v1080) >> 31));
      v1083[v1222] = v1279;
      int * v1086 = v1009->cache_age;
      v1086[v1247] = 0;
      v1089 = v1247;
    }
    int * v1090 = v1009->cache_vals;
    int v1282 = v1089 * 2;
    int v1091 = v1090[v1282];
    int v1283 = (v1089 * 2) + 1;
    int v1092 = v1090[v1283];
    int v1284 = (((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1090[v1284] = v1091;
    int * v1094 = v1009->cache_vals;
    int v1287 = ((((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1094[v1287] = v1092;
    int * v1096 = v1009->cache_tags;
    int v1290 = ((((int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1)) & 1) * 2) + ((((v1031 + ((~(((v1033 ^ -1) | (-(v1033 ^ -1))) >> 31)) & 2)) - (v1034 + ((~(((v1035 ^ -1) | (-(v1035 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1291 = (int)((unsigned int)((int)((unsigned int)v1011 >> 2)) >> 1);
    v1096[v1290] = v1291;
    int * v1098 = v1009->cache_dirty;
    v1098[v1290] = 0;
    int * v1100 = v1009->cache_age;
    v1100[v1290] = 1;
    int * v1102 = v1009->cache_age;
    int v1103 = v1102[v1290];
    int v1104 = v1102[v1219];
    int v1297 = v1104 + ((int)((unsigned int)(v1104 - v1103) >> 31));
    v1102[v1219] = v1297;
    int * v1106 = v1009->cache_age;
    int v1107 = v1106[v1220];
    int v1299 = v1107 + ((int)((unsigned int)(v1107 - v1103) >> 31));
    v1106[v1220] = v1299;
    int * v1109 = v1009->cache_age;
    v1109[v1290] = 0;
    v1112 = v1290;
  }
  int v1302 = (v1112 * 2) + (((int)((unsigned int)v1011 >> 2)) & 1);
  int v1113 = v1019[v1302];
  int * v1114 = v1009->regs;
  v1114[7] = v1113;
  struct StateT2 * v1116 = slot_5(v889);
  return v1116;
}

struct StateT2 * slot_18(struct StateT2 * v1811) {
  struct StateT * v1812 = v1811->a;
  int v1813 = v1812->timer;
  struct StateT * v1814 = v1811->b;
  int v1815 = v1814->timer;
  bool v1836 = v1813 == v1815;
  squared_assert(v1836);
  squared_assume(v1836);
  struct StateT * v1818 = v1811->a;
  int v1819 = v1818->timer;
  int v1838 = v1819 + 1;
  v1818->timer = v1838;
  struct StateT * v1821 = v1811->b;
  int v1822 = v1821->timer;
  int v1840 = v1822 + 1;
  v1821->timer = v1840;
  struct StateT * v1824 = v1811->a;
  int * v1825 = v1824->regs;
  int v1826 = v1825[8];
  int v1844 = v1826 + 1;
  v1825[8] = v1844;
  struct StateT * v1828 = v1811->b;
  int * v1829 = v1828->regs;
  int v1830 = v1829[8];
  int v1847 = v1830 + 1;
  v1829[8] = v1847;
  struct StateT2 * v1832 = slot_19(v1811);
  return v1832;
}

struct StateT2 * slot_9(struct StateT2 * v1460) {
  struct StateT * v1461 = v1460->a;
  int v1462 = v1461->timer;
  struct StateT * v1463 = v1460->b;
  int v1464 = v1463->timer;
  bool v1485 = v1462 == v1464;
  squared_assert(v1485);
  squared_assume(v1485);
  struct StateT * v1467 = v1460->a;
  int v1468 = v1467->timer;
  int v1487 = v1468 + 1;
  v1467->timer = v1487;
  struct StateT * v1470 = v1460->b;
  int v1471 = v1470->timer;
  int v1489 = v1471 + 1;
  v1470->timer = v1489;
  struct StateT * v1473 = v1460->a;
  int * v1474 = v1473->regs;
  int v1475 = v1474[8];
  int v1493 = v1475 + 1;
  v1474[8] = v1493;
  struct StateT * v1477 = v1460->b;
  int * v1478 = v1477->regs;
  int v1479 = v1478[8];
  int v1496 = v1479 + 1;
  v1478[8] = v1496;
  struct StateT2 * v1481 = slot_10(v1460);
  return v1481;
}

struct StateT2 * slot_183(struct StateT2 * v8246) {
  struct StateT * v8247 = v8246->a;
  int v8248 = v8247->timer;
  struct StateT * v8249 = v8246->b;
  int v8250 = v8249->timer;
  bool v8271 = v8248 == v8250;
  squared_assert(v8271);
  squared_assume(v8271);
  struct StateT * v8253 = v8246->a;
  int v8254 = v8253->timer;
  int v8273 = v8254 + 1;
  v8253->timer = v8273;
  struct StateT * v8256 = v8246->b;
  int v8257 = v8256->timer;
  int v8275 = v8257 + 1;
  v8256->timer = v8275;
  struct StateT * v8259 = v8246->a;
  int * v8260 = v8259->regs;
  int v8261 = v8260[8];
  int v8279 = v8261 + 1;
  v8260[8] = v8279;
  struct StateT * v8263 = v8246->b;
  int * v8264 = v8263->regs;
  int v8265 = v8264[8];
  int v8282 = v8265 + 1;
  v8264[8] = v8282;
  struct StateT2 * v8267 = slot_184(v8246);
  return v8267;
}

struct StateT2 * slot_43(struct StateT2 * v2786) {
  struct StateT * v2787 = v2786->a;
  int v2788 = v2787->timer;
  struct StateT * v2789 = v2786->b;
  int v2790 = v2789->timer;
  bool v2811 = v2788 == v2790;
  squared_assert(v2811);
  squared_assume(v2811);
  struct StateT * v2793 = v2786->a;
  int v2794 = v2793->timer;
  int v2813 = v2794 + 1;
  v2793->timer = v2813;
  struct StateT * v2796 = v2786->b;
  int v2797 = v2796->timer;
  int v2815 = v2797 + 1;
  v2796->timer = v2815;
  struct StateT * v2799 = v2786->a;
  int * v2800 = v2799->regs;
  int v2801 = v2800[8];
  int v2819 = v2801 + 1;
  v2800[8] = v2819;
  struct StateT * v2803 = v2786->b;
  int * v2804 = v2803->regs;
  int v2805 = v2804[8];
  int v2822 = v2805 + 1;
  v2804[8] = v2822;
  struct StateT2 * v2807 = slot_44(v2786);
  return v2807;
}

struct StateT2 * slot_70(struct StateT2 * v3839) {
  struct StateT * v3840 = v3839->a;
  int v3841 = v3840->timer;
  struct StateT * v3842 = v3839->b;
  int v3843 = v3842->timer;
  bool v3864 = v3841 == v3843;
  squared_assert(v3864);
  squared_assume(v3864);
  struct StateT * v3846 = v3839->a;
  int v3847 = v3846->timer;
  int v3866 = v3847 + 1;
  v3846->timer = v3866;
  struct StateT * v3849 = v3839->b;
  int v3850 = v3849->timer;
  int v3868 = v3850 + 1;
  v3849->timer = v3868;
  struct StateT * v3852 = v3839->a;
  int * v3853 = v3852->regs;
  int v3854 = v3853[8];
  int v3872 = v3854 + 1;
  v3853[8] = v3872;
  struct StateT * v3856 = v3839->b;
  int * v3857 = v3856->regs;
  int v3858 = v3857[8];
  int v3875 = v3858 + 1;
  v3857[8] = v3875;
  struct StateT2 * v3860 = slot_71(v3839);
  return v3860;
}

struct StateT2 * slot_168(struct StateT2 * v7661) {
  struct StateT * v7662 = v7661->a;
  int v7663 = v7662->timer;
  struct StateT * v7664 = v7661->b;
  int v7665 = v7664->timer;
  bool v7686 = v7663 == v7665;
  squared_assert(v7686);
  squared_assume(v7686);
  struct StateT * v7668 = v7661->a;
  int v7669 = v7668->timer;
  int v7688 = v7669 + 1;
  v7668->timer = v7688;
  struct StateT * v7671 = v7661->b;
  int v7672 = v7671->timer;
  int v7690 = v7672 + 1;
  v7671->timer = v7690;
  struct StateT * v7674 = v7661->a;
  int * v7675 = v7674->regs;
  int v7676 = v7675[8];
  int v7694 = v7676 + 1;
  v7675[8] = v7694;
  struct StateT * v7678 = v7661->b;
  int * v7679 = v7678->regs;
  int v7680 = v7679[8];
  int v7697 = v7680 + 1;
  v7679[8] = v7697;
  struct StateT2 * v7682 = slot_169(v7661);
  return v7682;
}

struct StateT2 * slot_76(struct StateT2 * v4073) {
  struct StateT * v4074 = v4073->a;
  int v4075 = v4074->timer;
  struct StateT * v4076 = v4073->b;
  int v4077 = v4076->timer;
  bool v4098 = v4075 == v4077;
  squared_assert(v4098);
  squared_assume(v4098);
  struct StateT * v4080 = v4073->a;
  int v4081 = v4080->timer;
  int v4100 = v4081 + 1;
  v4080->timer = v4100;
  struct StateT * v4083 = v4073->b;
  int v4084 = v4083->timer;
  int v4102 = v4084 + 1;
  v4083->timer = v4102;
  struct StateT * v4086 = v4073->a;
  int * v4087 = v4086->regs;
  int v4088 = v4087[8];
  int v4106 = v4088 + 1;
  v4087[8] = v4106;
  struct StateT * v4090 = v4073->b;
  int * v4091 = v4090->regs;
  int v4092 = v4091[8];
  int v4109 = v4092 + 1;
  v4091[8] = v4109;
  struct StateT2 * v4094 = slot_77(v4073);
  return v4094;
}

struct StateT2 * slot_6(struct StateT2 * v1343) {
  struct StateT * v1344 = v1343->a;
  int v1345 = v1344->timer;
  struct StateT * v1346 = v1343->b;
  int v1347 = v1346->timer;
  bool v1368 = v1345 == v1347;
  squared_assert(v1368);
  squared_assume(v1368);
  struct StateT * v1350 = v1343->a;
  int v1351 = v1350->timer;
  int v1370 = v1351 + 1;
  v1350->timer = v1370;
  struct StateT * v1353 = v1343->b;
  int v1354 = v1353->timer;
  int v1372 = v1354 + 1;
  v1353->timer = v1372;
  struct StateT * v1356 = v1343->a;
  int * v1357 = v1356->regs;
  int v1358 = v1357[8];
  int v1376 = v1358 + 1;
  v1357[8] = v1376;
  struct StateT * v1360 = v1343->b;
  int * v1361 = v1360->regs;
  int v1362 = v1361[8];
  int v1379 = v1362 + 1;
  v1361[8] = v1379;
  struct StateT2 * v1364 = slot_7(v1343);
  return v1364;
}

struct StateT2 * slot_225(struct StateT2 * v9884) {
  struct StateT * v9885 = v9884->a;
  int v9886 = v9885->timer;
  struct StateT * v9887 = v9884->b;
  int v9888 = v9887->timer;
  bool v9908 = v9886 == v9888;
  squared_assert(v9908);
  squared_assume(v9908);
  struct StateT * v9891 = v9884->a;
  int v9892 = v9891->timer;
  int v9910 = v9892 + 1;
  v9891->timer = v9910;
  struct StateT * v9894 = v9884->b;
  int v9895 = v9894->timer;
  int v9912 = v9895 + 1;
  v9894->timer = v9912;
  struct StateT * v9897 = v9884->a;
  int * v9898 = v9897->regs;
  int v9899 = v9898[8];
  int v9916 = v9899 + 1;
  v9898[8] = v9916;
  struct StateT * v9901 = v9884->b;
  int * v9902 = v9901->regs;
  int v9903 = v9902[8];
  int v9919 = v9903 + 1;
  v9902[8] = v9919;
  return v9884;
}

struct StateT2 * slot_55(struct StateT2 * v3254) {
  struct StateT * v3255 = v3254->a;
  int v3256 = v3255->timer;
  struct StateT * v3257 = v3254->b;
  int v3258 = v3257->timer;
  bool v3279 = v3256 == v3258;
  squared_assert(v3279);
  squared_assume(v3279);
  struct StateT * v3261 = v3254->a;
  int v3262 = v3261->timer;
  int v3281 = v3262 + 1;
  v3261->timer = v3281;
  struct StateT * v3264 = v3254->b;
  int v3265 = v3264->timer;
  int v3283 = v3265 + 1;
  v3264->timer = v3283;
  struct StateT * v3267 = v3254->a;
  int * v3268 = v3267->regs;
  int v3269 = v3268[8];
  int v3287 = v3269 + 1;
  v3268[8] = v3287;
  struct StateT * v3271 = v3254->b;
  int * v3272 = v3271->regs;
  int v3273 = v3272[8];
  int v3290 = v3273 + 1;
  v3272[8] = v3290;
  struct StateT2 * v3275 = slot_56(v3254);
  return v3275;
}

struct StateT2 * slot_213(struct StateT2 * v9416) {
  struct StateT * v9417 = v9416->a;
  int v9418 = v9417->timer;
  struct StateT * v9419 = v9416->b;
  int v9420 = v9419->timer;
  bool v9441 = v9418 == v9420;
  squared_assert(v9441);
  squared_assume(v9441);
  struct StateT * v9423 = v9416->a;
  int v9424 = v9423->timer;
  int v9443 = v9424 + 1;
  v9423->timer = v9443;
  struct StateT * v9426 = v9416->b;
  int v9427 = v9426->timer;
  int v9445 = v9427 + 1;
  v9426->timer = v9445;
  struct StateT * v9429 = v9416->a;
  int * v9430 = v9429->regs;
  int v9431 = v9430[8];
  int v9449 = v9431 + 1;
  v9430[8] = v9449;
  struct StateT * v9433 = v9416->b;
  int * v9434 = v9433->regs;
  int v9435 = v9434[8];
  int v9452 = v9435 + 1;
  v9434[8] = v9452;
  struct StateT2 * v9437 = slot_214(v9416);
  return v9437;
}

struct StateT2 * slot_82(struct StateT2 * v4307) {
  struct StateT * v4308 = v4307->a;
  int v4309 = v4308->timer;
  struct StateT * v4310 = v4307->b;
  int v4311 = v4310->timer;
  bool v4332 = v4309 == v4311;
  squared_assert(v4332);
  squared_assume(v4332);
  struct StateT * v4314 = v4307->a;
  int v4315 = v4314->timer;
  int v4334 = v4315 + 1;
  v4314->timer = v4334;
  struct StateT * v4317 = v4307->b;
  int v4318 = v4317->timer;
  int v4336 = v4318 + 1;
  v4317->timer = v4336;
  struct StateT * v4320 = v4307->a;
  int * v4321 = v4320->regs;
  int v4322 = v4321[8];
  int v4340 = v4322 + 1;
  v4321[8] = v4340;
  struct StateT * v4324 = v4307->b;
  int * v4325 = v4324->regs;
  int v4326 = v4325[8];
  int v4343 = v4326 + 1;
  v4325[8] = v4343;
  struct StateT2 * v4328 = slot_83(v4307);
  return v4328;
}

struct StateT2 * slot_161(struct StateT2 * v7388) {
  struct StateT * v7389 = v7388->a;
  int v7390 = v7389->timer;
  struct StateT * v7391 = v7388->b;
  int v7392 = v7391->timer;
  bool v7413 = v7390 == v7392;
  squared_assert(v7413);
  squared_assume(v7413);
  struct StateT * v7395 = v7388->a;
  int v7396 = v7395->timer;
  int v7415 = v7396 + 1;
  v7395->timer = v7415;
  struct StateT * v7398 = v7388->b;
  int v7399 = v7398->timer;
  int v7417 = v7399 + 1;
  v7398->timer = v7417;
  struct StateT * v7401 = v7388->a;
  int * v7402 = v7401->regs;
  int v7403 = v7402[8];
  int v7421 = v7403 + 1;
  v7402[8] = v7421;
  struct StateT * v7405 = v7388->b;
  int * v7406 = v7405->regs;
  int v7407 = v7406[8];
  int v7424 = v7407 + 1;
  v7406[8] = v7424;
  struct StateT2 * v7409 = slot_162(v7388);
  return v7409;
}

struct StateT2 * slot_185(struct StateT2 * v8324) {
  struct StateT * v8325 = v8324->a;
  int v8326 = v8325->timer;
  struct StateT * v8327 = v8324->b;
  int v8328 = v8327->timer;
  bool v8349 = v8326 == v8328;
  squared_assert(v8349);
  squared_assume(v8349);
  struct StateT * v8331 = v8324->a;
  int v8332 = v8331->timer;
  int v8351 = v8332 + 1;
  v8331->timer = v8351;
  struct StateT * v8334 = v8324->b;
  int v8335 = v8334->timer;
  int v8353 = v8335 + 1;
  v8334->timer = v8353;
  struct StateT * v8337 = v8324->a;
  int * v8338 = v8337->regs;
  int v8339 = v8338[8];
  int v8357 = v8339 + 1;
  v8338[8] = v8357;
  struct StateT * v8341 = v8324->b;
  int * v8342 = v8341->regs;
  int v8343 = v8342[8];
  int v8360 = v8343 + 1;
  v8342[8] = v8360;
  struct StateT2 * v8345 = slot_186(v8324);
  return v8345;
}

struct StateT2 * slot_91(struct StateT2 * v4658) {
  struct StateT * v4659 = v4658->a;
  int v4660 = v4659->timer;
  struct StateT * v4661 = v4658->b;
  int v4662 = v4661->timer;
  bool v4683 = v4660 == v4662;
  squared_assert(v4683);
  squared_assume(v4683);
  struct StateT * v4665 = v4658->a;
  int v4666 = v4665->timer;
  int v4685 = v4666 + 1;
  v4665->timer = v4685;
  struct StateT * v4668 = v4658->b;
  int v4669 = v4668->timer;
  int v4687 = v4669 + 1;
  v4668->timer = v4687;
  struct StateT * v4671 = v4658->a;
  int * v4672 = v4671->regs;
  int v4673 = v4672[8];
  int v4691 = v4673 + 1;
  v4672[8] = v4691;
  struct StateT * v4675 = v4658->b;
  int * v4676 = v4675->regs;
  int v4677 = v4676[8];
  int v4694 = v4677 + 1;
  v4676[8] = v4694;
  struct StateT2 * v4679 = slot_92(v4658);
  return v4679;
}

struct StateT2 * slot_58(struct StateT2 * v3371) {
  struct StateT * v3372 = v3371->a;
  int v3373 = v3372->timer;
  struct StateT * v3374 = v3371->b;
  int v3375 = v3374->timer;
  bool v3396 = v3373 == v3375;
  squared_assert(v3396);
  squared_assume(v3396);
  struct StateT * v3378 = v3371->a;
  int v3379 = v3378->timer;
  int v3398 = v3379 + 1;
  v3378->timer = v3398;
  struct StateT * v3381 = v3371->b;
  int v3382 = v3381->timer;
  int v3400 = v3382 + 1;
  v3381->timer = v3400;
  struct StateT * v3384 = v3371->a;
  int * v3385 = v3384->regs;
  int v3386 = v3385[8];
  int v3404 = v3386 + 1;
  v3385[8] = v3404;
  struct StateT * v3388 = v3371->b;
  int * v3389 = v3388->regs;
  int v3390 = v3389[8];
  int v3407 = v3390 + 1;
  v3389[8] = v3407;
  struct StateT2 * v3392 = slot_59(v3371);
  return v3392;
}

struct StateT2 * slot_89(struct StateT2 * v4580) {
  struct StateT * v4581 = v4580->a;
  int v4582 = v4581->timer;
  struct StateT * v4583 = v4580->b;
  int v4584 = v4583->timer;
  bool v4605 = v4582 == v4584;
  squared_assert(v4605);
  squared_assume(v4605);
  struct StateT * v4587 = v4580->a;
  int v4588 = v4587->timer;
  int v4607 = v4588 + 1;
  v4587->timer = v4607;
  struct StateT * v4590 = v4580->b;
  int v4591 = v4590->timer;
  int v4609 = v4591 + 1;
  v4590->timer = v4609;
  struct StateT * v4593 = v4580->a;
  int * v4594 = v4593->regs;
  int v4595 = v4594[8];
  int v4613 = v4595 + 1;
  v4594[8] = v4613;
  struct StateT * v4597 = v4580->b;
  int * v4598 = v4597->regs;
  int v4599 = v4598[8];
  int v4616 = v4599 + 1;
  v4598[8] = v4616;
  struct StateT2 * v4601 = slot_90(v4580);
  return v4601;
}

struct StateT2 * slot_66(struct StateT2 * v3683) {
  struct StateT * v3684 = v3683->a;
  int v3685 = v3684->timer;
  struct StateT * v3686 = v3683->b;
  int v3687 = v3686->timer;
  bool v3708 = v3685 == v3687;
  squared_assert(v3708);
  squared_assume(v3708);
  struct StateT * v3690 = v3683->a;
  int v3691 = v3690->timer;
  int v3710 = v3691 + 1;
  v3690->timer = v3710;
  struct StateT * v3693 = v3683->b;
  int v3694 = v3693->timer;
  int v3712 = v3694 + 1;
  v3693->timer = v3712;
  struct StateT * v3696 = v3683->a;
  int * v3697 = v3696->regs;
  int v3698 = v3697[8];
  int v3716 = v3698 + 1;
  v3697[8] = v3716;
  struct StateT * v3700 = v3683->b;
  int * v3701 = v3700->regs;
  int v3702 = v3701[8];
  int v3719 = v3702 + 1;
  v3701[8] = v3719;
  struct StateT2 * v3704 = slot_67(v3683);
  return v3704;
}

struct StateT2 * slot_140(struct StateT2 * v6569) {
  struct StateT * v6570 = v6569->a;
  int v6571 = v6570->timer;
  struct StateT * v6572 = v6569->b;
  int v6573 = v6572->timer;
  bool v6594 = v6571 == v6573;
  squared_assert(v6594);
  squared_assume(v6594);
  struct StateT * v6576 = v6569->a;
  int v6577 = v6576->timer;
  int v6596 = v6577 + 1;
  v6576->timer = v6596;
  struct StateT * v6579 = v6569->b;
  int v6580 = v6579->timer;
  int v6598 = v6580 + 1;
  v6579->timer = v6598;
  struct StateT * v6582 = v6569->a;
  int * v6583 = v6582->regs;
  int v6584 = v6583[8];
  int v6602 = v6584 + 1;
  v6583[8] = v6602;
  struct StateT * v6586 = v6569->b;
  int * v6587 = v6586->regs;
  int v6588 = v6587[8];
  int v6605 = v6588 + 1;
  v6587[8] = v6605;
  struct StateT2 * v6590 = slot_141(v6569);
  return v6590;
}

struct StateT2 * slot_49(struct StateT2 * v3020) {
  struct StateT * v3021 = v3020->a;
  int v3022 = v3021->timer;
  struct StateT * v3023 = v3020->b;
  int v3024 = v3023->timer;
  bool v3045 = v3022 == v3024;
  squared_assert(v3045);
  squared_assume(v3045);
  struct StateT * v3027 = v3020->a;
  int v3028 = v3027->timer;
  int v3047 = v3028 + 1;
  v3027->timer = v3047;
  struct StateT * v3030 = v3020->b;
  int v3031 = v3030->timer;
  int v3049 = v3031 + 1;
  v3030->timer = v3049;
  struct StateT * v3033 = v3020->a;
  int * v3034 = v3033->regs;
  int v3035 = v3034[8];
  int v3053 = v3035 + 1;
  v3034[8] = v3053;
  struct StateT * v3037 = v3020->b;
  int * v3038 = v3037->regs;
  int v3039 = v3038[8];
  int v3056 = v3039 + 1;
  v3038[8] = v3056;
  struct StateT2 * v3041 = slot_50(v3020);
  return v3041;
}

struct StateT2 * slot_216(struct StateT2 * v9533) {
  struct StateT * v9534 = v9533->a;
  int v9535 = v9534->timer;
  struct StateT * v9536 = v9533->b;
  int v9537 = v9536->timer;
  bool v9558 = v9535 == v9537;
  squared_assert(v9558);
  squared_assume(v9558);
  struct StateT * v9540 = v9533->a;
  int v9541 = v9540->timer;
  int v9560 = v9541 + 1;
  v9540->timer = v9560;
  struct StateT * v9543 = v9533->b;
  int v9544 = v9543->timer;
  int v9562 = v9544 + 1;
  v9543->timer = v9562;
  struct StateT * v9546 = v9533->a;
  int * v9547 = v9546->regs;
  int v9548 = v9547[8];
  int v9566 = v9548 + 1;
  v9547[8] = v9566;
  struct StateT * v9550 = v9533->b;
  int * v9551 = v9550->regs;
  int v9552 = v9551[8];
  int v9569 = v9552 + 1;
  v9551[8] = v9569;
  struct StateT2 * v9554 = slot_217(v9533);
  return v9554;
}

struct StateT2 * slot_50(struct StateT2 * v3059) {
  struct StateT * v3060 = v3059->a;
  int v3061 = v3060->timer;
  struct StateT * v3062 = v3059->b;
  int v3063 = v3062->timer;
  bool v3084 = v3061 == v3063;
  squared_assert(v3084);
  squared_assume(v3084);
  struct StateT * v3066 = v3059->a;
  int v3067 = v3066->timer;
  int v3086 = v3067 + 1;
  v3066->timer = v3086;
  struct StateT * v3069 = v3059->b;
  int v3070 = v3069->timer;
  int v3088 = v3070 + 1;
  v3069->timer = v3088;
  struct StateT * v3072 = v3059->a;
  int * v3073 = v3072->regs;
  int v3074 = v3073[8];
  int v3092 = v3074 + 1;
  v3073[8] = v3092;
  struct StateT * v3076 = v3059->b;
  int * v3077 = v3076->regs;
  int v3078 = v3077[8];
  int v3095 = v3078 + 1;
  v3077[8] = v3095;
  struct StateT2 * v3080 = slot_51(v3059);
  return v3080;
}

struct StateT2 * slot_37(struct StateT2 * v2552) {
  struct StateT * v2553 = v2552->a;
  int v2554 = v2553->timer;
  struct StateT * v2555 = v2552->b;
  int v2556 = v2555->timer;
  bool v2577 = v2554 == v2556;
  squared_assert(v2577);
  squared_assume(v2577);
  struct StateT * v2559 = v2552->a;
  int v2560 = v2559->timer;
  int v2579 = v2560 + 1;
  v2559->timer = v2579;
  struct StateT * v2562 = v2552->b;
  int v2563 = v2562->timer;
  int v2581 = v2563 + 1;
  v2562->timer = v2581;
  struct StateT * v2565 = v2552->a;
  int * v2566 = v2565->regs;
  int v2567 = v2566[8];
  int v2585 = v2567 + 1;
  v2566[8] = v2585;
  struct StateT * v2569 = v2552->b;
  int * v2570 = v2569->regs;
  int v2571 = v2570[8];
  int v2588 = v2571 + 1;
  v2570[8] = v2588;
  struct StateT2 * v2573 = slot_38(v2552);
  return v2573;
}

struct StateT2 * slot_114(struct StateT2 * v5555) {
  struct StateT * v5556 = v5555->a;
  int v5557 = v5556->timer;
  struct StateT * v5558 = v5555->b;
  int v5559 = v5558->timer;
  bool v5580 = v5557 == v5559;
  squared_assert(v5580);
  squared_assume(v5580);
  struct StateT * v5562 = v5555->a;
  int v5563 = v5562->timer;
  int v5582 = v5563 + 1;
  v5562->timer = v5582;
  struct StateT * v5565 = v5555->b;
  int v5566 = v5565->timer;
  int v5584 = v5566 + 1;
  v5565->timer = v5584;
  struct StateT * v5568 = v5555->a;
  int * v5569 = v5568->regs;
  int v5570 = v5569[8];
  int v5588 = v5570 + 1;
  v5569[8] = v5588;
  struct StateT * v5572 = v5555->b;
  int * v5573 = v5572->regs;
  int v5574 = v5573[8];
  int v5591 = v5574 + 1;
  v5573[8] = v5591;
  struct StateT2 * v5576 = slot_115(v5555);
  return v5576;
}

struct StateT2 * slot_135(struct StateT2 * v6374) {
  struct StateT * v6375 = v6374->a;
  int v6376 = v6375->timer;
  struct StateT * v6377 = v6374->b;
  int v6378 = v6377->timer;
  bool v6399 = v6376 == v6378;
  squared_assert(v6399);
  squared_assume(v6399);
  struct StateT * v6381 = v6374->a;
  int v6382 = v6381->timer;
  int v6401 = v6382 + 1;
  v6381->timer = v6401;
  struct StateT * v6384 = v6374->b;
  int v6385 = v6384->timer;
  int v6403 = v6385 + 1;
  v6384->timer = v6403;
  struct StateT * v6387 = v6374->a;
  int * v6388 = v6387->regs;
  int v6389 = v6388[8];
  int v6407 = v6389 + 1;
  v6388[8] = v6407;
  struct StateT * v6391 = v6374->b;
  int * v6392 = v6391->regs;
  int v6393 = v6392[8];
  int v6410 = v6393 + 1;
  v6392[8] = v6410;
  struct StateT2 * v6395 = slot_136(v6374);
  return v6395;
}

struct StateT2 * slot_59(struct StateT2 * v3410) {
  struct StateT * v3411 = v3410->a;
  int v3412 = v3411->timer;
  struct StateT * v3413 = v3410->b;
  int v3414 = v3413->timer;
  bool v3435 = v3412 == v3414;
  squared_assert(v3435);
  squared_assume(v3435);
  struct StateT * v3417 = v3410->a;
  int v3418 = v3417->timer;
  int v3437 = v3418 + 1;
  v3417->timer = v3437;
  struct StateT * v3420 = v3410->b;
  int v3421 = v3420->timer;
  int v3439 = v3421 + 1;
  v3420->timer = v3439;
  struct StateT * v3423 = v3410->a;
  int * v3424 = v3423->regs;
  int v3425 = v3424[8];
  int v3443 = v3425 + 1;
  v3424[8] = v3443;
  struct StateT * v3427 = v3410->b;
  int * v3428 = v3427->regs;
  int v3429 = v3428[8];
  int v3446 = v3429 + 1;
  v3428[8] = v3446;
  struct StateT2 * v3431 = slot_60(v3410);
  return v3431;
}

struct StateT2 * slot_192(struct StateT2 * v8597) {
  struct StateT * v8598 = v8597->a;
  int v8599 = v8598->timer;
  struct StateT * v8600 = v8597->b;
  int v8601 = v8600->timer;
  bool v8622 = v8599 == v8601;
  squared_assert(v8622);
  squared_assume(v8622);
  struct StateT * v8604 = v8597->a;
  int v8605 = v8604->timer;
  int v8624 = v8605 + 1;
  v8604->timer = v8624;
  struct StateT * v8607 = v8597->b;
  int v8608 = v8607->timer;
  int v8626 = v8608 + 1;
  v8607->timer = v8626;
  struct StateT * v8610 = v8597->a;
  int * v8611 = v8610->regs;
  int v8612 = v8611[8];
  int v8630 = v8612 + 1;
  v8611[8] = v8630;
  struct StateT * v8614 = v8597->b;
  int * v8615 = v8614->regs;
  int v8616 = v8615[8];
  int v8633 = v8616 + 1;
  v8615[8] = v8633;
  struct StateT2 * v8618 = slot_193(v8597);
  return v8618;
}

struct StateT2 * slot_40(struct StateT2 * v2669) {
  struct StateT * v2670 = v2669->a;
  int v2671 = v2670->timer;
  struct StateT * v2672 = v2669->b;
  int v2673 = v2672->timer;
  bool v2694 = v2671 == v2673;
  squared_assert(v2694);
  squared_assume(v2694);
  struct StateT * v2676 = v2669->a;
  int v2677 = v2676->timer;
  int v2696 = v2677 + 1;
  v2676->timer = v2696;
  struct StateT * v2679 = v2669->b;
  int v2680 = v2679->timer;
  int v2698 = v2680 + 1;
  v2679->timer = v2698;
  struct StateT * v2682 = v2669->a;
  int * v2683 = v2682->regs;
  int v2684 = v2683[8];
  int v2702 = v2684 + 1;
  v2683[8] = v2702;
  struct StateT * v2686 = v2669->b;
  int * v2687 = v2686->regs;
  int v2688 = v2687[8];
  int v2705 = v2688 + 1;
  v2687[8] = v2705;
  struct StateT2 * v2690 = slot_41(v2669);
  return v2690;
}

struct StateT2 * slot_48(struct StateT2 * v2981) {
  struct StateT * v2982 = v2981->a;
  int v2983 = v2982->timer;
  struct StateT * v2984 = v2981->b;
  int v2985 = v2984->timer;
  bool v3006 = v2983 == v2985;
  squared_assert(v3006);
  squared_assume(v3006);
  struct StateT * v2988 = v2981->a;
  int v2989 = v2988->timer;
  int v3008 = v2989 + 1;
  v2988->timer = v3008;
  struct StateT * v2991 = v2981->b;
  int v2992 = v2991->timer;
  int v3010 = v2992 + 1;
  v2991->timer = v3010;
  struct StateT * v2994 = v2981->a;
  int * v2995 = v2994->regs;
  int v2996 = v2995[8];
  int v3014 = v2996 + 1;
  v2995[8] = v3014;
  struct StateT * v2998 = v2981->b;
  int * v2999 = v2998->regs;
  int v3000 = v2999[8];
  int v3017 = v3000 + 1;
  v2999[8] = v3017;
  struct StateT2 * v3002 = slot_49(v2981);
  return v3002;
}

struct StateT2 * slot_77(struct StateT2 * v4112) {
  struct StateT * v4113 = v4112->a;
  int v4114 = v4113->timer;
  struct StateT * v4115 = v4112->b;
  int v4116 = v4115->timer;
  bool v4137 = v4114 == v4116;
  squared_assert(v4137);
  squared_assume(v4137);
  struct StateT * v4119 = v4112->a;
  int v4120 = v4119->timer;
  int v4139 = v4120 + 1;
  v4119->timer = v4139;
  struct StateT * v4122 = v4112->b;
  int v4123 = v4122->timer;
  int v4141 = v4123 + 1;
  v4122->timer = v4141;
  struct StateT * v4125 = v4112->a;
  int * v4126 = v4125->regs;
  int v4127 = v4126[8];
  int v4145 = v4127 + 1;
  v4126[8] = v4145;
  struct StateT * v4129 = v4112->b;
  int * v4130 = v4129->regs;
  int v4131 = v4130[8];
  int v4148 = v4131 + 1;
  v4130[8] = v4148;
  struct StateT2 * v4133 = slot_78(v4112);
  return v4133;
}

struct StateT2 * slot_85(struct StateT2 * v4424) {
  struct StateT * v4425 = v4424->a;
  int v4426 = v4425->timer;
  struct StateT * v4427 = v4424->b;
  int v4428 = v4427->timer;
  bool v4449 = v4426 == v4428;
  squared_assert(v4449);
  squared_assume(v4449);
  struct StateT * v4431 = v4424->a;
  int v4432 = v4431->timer;
  int v4451 = v4432 + 1;
  v4431->timer = v4451;
  struct StateT * v4434 = v4424->b;
  int v4435 = v4434->timer;
  int v4453 = v4435 + 1;
  v4434->timer = v4453;
  struct StateT * v4437 = v4424->a;
  int * v4438 = v4437->regs;
  int v4439 = v4438[8];
  int v4457 = v4439 + 1;
  v4438[8] = v4457;
  struct StateT * v4441 = v4424->b;
  int * v4442 = v4441->regs;
  int v4443 = v4442[8];
  int v4460 = v4443 + 1;
  v4442[8] = v4460;
  struct StateT2 * v4445 = slot_86(v4424);
  return v4445;
}

struct StateT2 * slot_75(struct StateT2 * v4034) {
  struct StateT * v4035 = v4034->a;
  int v4036 = v4035->timer;
  struct StateT * v4037 = v4034->b;
  int v4038 = v4037->timer;
  bool v4059 = v4036 == v4038;
  squared_assert(v4059);
  squared_assume(v4059);
  struct StateT * v4041 = v4034->a;
  int v4042 = v4041->timer;
  int v4061 = v4042 + 1;
  v4041->timer = v4061;
  struct StateT * v4044 = v4034->b;
  int v4045 = v4044->timer;
  int v4063 = v4045 + 1;
  v4044->timer = v4063;
  struct StateT * v4047 = v4034->a;
  int * v4048 = v4047->regs;
  int v4049 = v4048[8];
  int v4067 = v4049 + 1;
  v4048[8] = v4067;
  struct StateT * v4051 = v4034->b;
  int * v4052 = v4051->regs;
  int v4053 = v4052[8];
  int v4070 = v4053 + 1;
  v4052[8] = v4070;
  struct StateT2 * v4055 = slot_76(v4034);
  return v4055;
}

struct StateT2 * slot_72(struct StateT2 * v3917) {
  struct StateT * v3918 = v3917->a;
  int v3919 = v3918->timer;
  struct StateT * v3920 = v3917->b;
  int v3921 = v3920->timer;
  bool v3942 = v3919 == v3921;
  squared_assert(v3942);
  squared_assume(v3942);
  struct StateT * v3924 = v3917->a;
  int v3925 = v3924->timer;
  int v3944 = v3925 + 1;
  v3924->timer = v3944;
  struct StateT * v3927 = v3917->b;
  int v3928 = v3927->timer;
  int v3946 = v3928 + 1;
  v3927->timer = v3946;
  struct StateT * v3930 = v3917->a;
  int * v3931 = v3930->regs;
  int v3932 = v3931[8];
  int v3950 = v3932 + 1;
  v3931[8] = v3950;
  struct StateT * v3934 = v3917->b;
  int * v3935 = v3934->regs;
  int v3936 = v3935[8];
  int v3953 = v3936 + 1;
  v3935[8] = v3953;
  struct StateT2 * v3938 = slot_73(v3917);
  return v3938;
}

struct StateT2 * slot_119(struct StateT2 * v5750) {
  struct StateT * v5751 = v5750->a;
  int v5752 = v5751->timer;
  struct StateT * v5753 = v5750->b;
  int v5754 = v5753->timer;
  bool v5775 = v5752 == v5754;
  squared_assert(v5775);
  squared_assume(v5775);
  struct StateT * v5757 = v5750->a;
  int v5758 = v5757->timer;
  int v5777 = v5758 + 1;
  v5757->timer = v5777;
  struct StateT * v5760 = v5750->b;
  int v5761 = v5760->timer;
  int v5779 = v5761 + 1;
  v5760->timer = v5779;
  struct StateT * v5763 = v5750->a;
  int * v5764 = v5763->regs;
  int v5765 = v5764[8];
  int v5783 = v5765 + 1;
  v5764[8] = v5783;
  struct StateT * v5767 = v5750->b;
  int * v5768 = v5767->regs;
  int v5769 = v5768[8];
  int v5786 = v5769 + 1;
  v5768[8] = v5786;
  struct StateT2 * v5771 = slot_120(v5750);
  return v5771;
}

struct StateT2 * slot_71(struct StateT2 * v3878) {
  struct StateT * v3879 = v3878->a;
  int v3880 = v3879->timer;
  struct StateT * v3881 = v3878->b;
  int v3882 = v3881->timer;
  bool v3903 = v3880 == v3882;
  squared_assert(v3903);
  squared_assume(v3903);
  struct StateT * v3885 = v3878->a;
  int v3886 = v3885->timer;
  int v3905 = v3886 + 1;
  v3885->timer = v3905;
  struct StateT * v3888 = v3878->b;
  int v3889 = v3888->timer;
  int v3907 = v3889 + 1;
  v3888->timer = v3907;
  struct StateT * v3891 = v3878->a;
  int * v3892 = v3891->regs;
  int v3893 = v3892[8];
  int v3911 = v3893 + 1;
  v3892[8] = v3911;
  struct StateT * v3895 = v3878->b;
  int * v3896 = v3895->regs;
  int v3897 = v3896[8];
  int v3914 = v3897 + 1;
  v3896[8] = v3914;
  struct StateT2 * v3899 = slot_72(v3878);
  return v3899;
}

struct StateT2 * slot_101(struct StateT2 * v5048) {
  struct StateT * v5049 = v5048->a;
  int v5050 = v5049->timer;
  struct StateT * v5051 = v5048->b;
  int v5052 = v5051->timer;
  bool v5073 = v5050 == v5052;
  squared_assert(v5073);
  squared_assume(v5073);
  struct StateT * v5055 = v5048->a;
  int v5056 = v5055->timer;
  int v5075 = v5056 + 1;
  v5055->timer = v5075;
  struct StateT * v5058 = v5048->b;
  int v5059 = v5058->timer;
  int v5077 = v5059 + 1;
  v5058->timer = v5077;
  struct StateT * v5061 = v5048->a;
  int * v5062 = v5061->regs;
  int v5063 = v5062[8];
  int v5081 = v5063 + 1;
  v5062[8] = v5081;
  struct StateT * v5065 = v5048->b;
  int * v5066 = v5065->regs;
  int v5067 = v5066[8];
  int v5084 = v5067 + 1;
  v5066[8] = v5084;
  struct StateT2 * v5069 = slot_102(v5048);
  return v5069;
}

struct StateT2 * slot_108(struct StateT2 * v5321) {
  struct StateT * v5322 = v5321->a;
  int v5323 = v5322->timer;
  struct StateT * v5324 = v5321->b;
  int v5325 = v5324->timer;
  bool v5346 = v5323 == v5325;
  squared_assert(v5346);
  squared_assume(v5346);
  struct StateT * v5328 = v5321->a;
  int v5329 = v5328->timer;
  int v5348 = v5329 + 1;
  v5328->timer = v5348;
  struct StateT * v5331 = v5321->b;
  int v5332 = v5331->timer;
  int v5350 = v5332 + 1;
  v5331->timer = v5350;
  struct StateT * v5334 = v5321->a;
  int * v5335 = v5334->regs;
  int v5336 = v5335[8];
  int v5354 = v5336 + 1;
  v5335[8] = v5354;
  struct StateT * v5338 = v5321->b;
  int * v5339 = v5338->regs;
  int v5340 = v5339[8];
  int v5357 = v5340 + 1;
  v5339[8] = v5357;
  struct StateT2 * v5342 = slot_109(v5321);
  return v5342;
}

struct StateT2 * slot_116(struct StateT2 * v5633) {
  struct StateT * v5634 = v5633->a;
  int v5635 = v5634->timer;
  struct StateT * v5636 = v5633->b;
  int v5637 = v5636->timer;
  bool v5658 = v5635 == v5637;
  squared_assert(v5658);
  squared_assume(v5658);
  struct StateT * v5640 = v5633->a;
  int v5641 = v5640->timer;
  int v5660 = v5641 + 1;
  v5640->timer = v5660;
  struct StateT * v5643 = v5633->b;
  int v5644 = v5643->timer;
  int v5662 = v5644 + 1;
  v5643->timer = v5662;
  struct StateT * v5646 = v5633->a;
  int * v5647 = v5646->regs;
  int v5648 = v5647[8];
  int v5666 = v5648 + 1;
  v5647[8] = v5666;
  struct StateT * v5650 = v5633->b;
  int * v5651 = v5650->regs;
  int v5652 = v5651[8];
  int v5669 = v5652 + 1;
  v5651[8] = v5669;
  struct StateT2 * v5654 = slot_117(v5633);
  return v5654;
}

struct StateT2 * slot_93(struct StateT2 * v4736) {
  struct StateT * v4737 = v4736->a;
  int v4738 = v4737->timer;
  struct StateT * v4739 = v4736->b;
  int v4740 = v4739->timer;
  bool v4761 = v4738 == v4740;
  squared_assert(v4761);
  squared_assume(v4761);
  struct StateT * v4743 = v4736->a;
  int v4744 = v4743->timer;
  int v4763 = v4744 + 1;
  v4743->timer = v4763;
  struct StateT * v4746 = v4736->b;
  int v4747 = v4746->timer;
  int v4765 = v4747 + 1;
  v4746->timer = v4765;
  struct StateT * v4749 = v4736->a;
  int * v4750 = v4749->regs;
  int v4751 = v4750[8];
  int v4769 = v4751 + 1;
  v4750[8] = v4769;
  struct StateT * v4753 = v4736->b;
  int * v4754 = v4753->regs;
  int v4755 = v4754[8];
  int v4772 = v4755 + 1;
  v4754[8] = v4772;
  struct StateT2 * v4757 = slot_94(v4736);
  return v4757;
}

struct StateT2 * slot_88(struct StateT2 * v4541) {
  struct StateT * v4542 = v4541->a;
  int v4543 = v4542->timer;
  struct StateT * v4544 = v4541->b;
  int v4545 = v4544->timer;
  bool v4566 = v4543 == v4545;
  squared_assert(v4566);
  squared_assume(v4566);
  struct StateT * v4548 = v4541->a;
  int v4549 = v4548->timer;
  int v4568 = v4549 + 1;
  v4548->timer = v4568;
  struct StateT * v4551 = v4541->b;
  int v4552 = v4551->timer;
  int v4570 = v4552 + 1;
  v4551->timer = v4570;
  struct StateT * v4554 = v4541->a;
  int * v4555 = v4554->regs;
  int v4556 = v4555[8];
  int v4574 = v4556 + 1;
  v4555[8] = v4574;
  struct StateT * v4558 = v4541->b;
  int * v4559 = v4558->regs;
  int v4560 = v4559[8];
  int v4577 = v4560 + 1;
  v4559[8] = v4577;
  struct StateT2 * v4562 = slot_89(v4541);
  return v4562;
}

struct StateT2 * slot_96(struct StateT2 * v4853) {
  struct StateT * v4854 = v4853->a;
  int v4855 = v4854->timer;
  struct StateT * v4856 = v4853->b;
  int v4857 = v4856->timer;
  bool v4878 = v4855 == v4857;
  squared_assert(v4878);
  squared_assume(v4878);
  struct StateT * v4860 = v4853->a;
  int v4861 = v4860->timer;
  int v4880 = v4861 + 1;
  v4860->timer = v4880;
  struct StateT * v4863 = v4853->b;
  int v4864 = v4863->timer;
  int v4882 = v4864 + 1;
  v4863->timer = v4882;
  struct StateT * v4866 = v4853->a;
  int * v4867 = v4866->regs;
  int v4868 = v4867[8];
  int v4886 = v4868 + 1;
  v4867[8] = v4886;
  struct StateT * v4870 = v4853->b;
  int * v4871 = v4870->regs;
  int v4872 = v4871[8];
  int v4889 = v4872 + 1;
  v4871[8] = v4889;
  struct StateT2 * v4874 = slot_97(v4853);
  return v4874;
}

struct StateT2 * slot_215(struct StateT2 * v9494) {
  struct StateT * v9495 = v9494->a;
  int v9496 = v9495->timer;
  struct StateT * v9497 = v9494->b;
  int v9498 = v9497->timer;
  bool v9519 = v9496 == v9498;
  squared_assert(v9519);
  squared_assume(v9519);
  struct StateT * v9501 = v9494->a;
  int v9502 = v9501->timer;
  int v9521 = v9502 + 1;
  v9501->timer = v9521;
  struct StateT * v9504 = v9494->b;
  int v9505 = v9504->timer;
  int v9523 = v9505 + 1;
  v9504->timer = v9523;
  struct StateT * v9507 = v9494->a;
  int * v9508 = v9507->regs;
  int v9509 = v9508[8];
  int v9527 = v9509 + 1;
  v9508[8] = v9527;
  struct StateT * v9511 = v9494->b;
  int * v9512 = v9511->regs;
  int v9513 = v9512[8];
  int v9530 = v9513 + 1;
  v9512[8] = v9530;
  struct StateT2 * v9515 = slot_216(v9494);
  return v9515;
}

struct StateT2 * slot_45(struct StateT2 * v2864) {
  struct StateT * v2865 = v2864->a;
  int v2866 = v2865->timer;
  struct StateT * v2867 = v2864->b;
  int v2868 = v2867->timer;
  bool v2889 = v2866 == v2868;
  squared_assert(v2889);
  squared_assume(v2889);
  struct StateT * v2871 = v2864->a;
  int v2872 = v2871->timer;
  int v2891 = v2872 + 1;
  v2871->timer = v2891;
  struct StateT * v2874 = v2864->b;
  int v2875 = v2874->timer;
  int v2893 = v2875 + 1;
  v2874->timer = v2893;
  struct StateT * v2877 = v2864->a;
  int * v2878 = v2877->regs;
  int v2879 = v2878[8];
  int v2897 = v2879 + 1;
  v2878[8] = v2897;
  struct StateT * v2881 = v2864->b;
  int * v2882 = v2881->regs;
  int v2883 = v2882[8];
  int v2900 = v2883 + 1;
  v2882[8] = v2900;
  struct StateT2 * v2885 = slot_46(v2864);
  return v2885;
}

struct StateT2 * slot_218(struct StateT2 * v9611) {
  struct StateT * v9612 = v9611->a;
  int v9613 = v9612->timer;
  struct StateT * v9614 = v9611->b;
  int v9615 = v9614->timer;
  bool v9636 = v9613 == v9615;
  squared_assert(v9636);
  squared_assume(v9636);
  struct StateT * v9618 = v9611->a;
  int v9619 = v9618->timer;
  int v9638 = v9619 + 1;
  v9618->timer = v9638;
  struct StateT * v9621 = v9611->b;
  int v9622 = v9621->timer;
  int v9640 = v9622 + 1;
  v9621->timer = v9640;
  struct StateT * v9624 = v9611->a;
  int * v9625 = v9624->regs;
  int v9626 = v9625[8];
  int v9644 = v9626 + 1;
  v9625[8] = v9644;
  struct StateT * v9628 = v9611->b;
  int * v9629 = v9628->regs;
  int v9630 = v9629[8];
  int v9647 = v9630 + 1;
  v9629[8] = v9647;
  struct StateT2 * v9632 = slot_219(v9611);
  return v9632;
}

struct StateT2 * slot_220(struct StateT2 * v9689) {
  struct StateT * v9690 = v9689->a;
  int v9691 = v9690->timer;
  struct StateT * v9692 = v9689->b;
  int v9693 = v9692->timer;
  bool v9714 = v9691 == v9693;
  squared_assert(v9714);
  squared_assume(v9714);
  struct StateT * v9696 = v9689->a;
  int v9697 = v9696->timer;
  int v9716 = v9697 + 1;
  v9696->timer = v9716;
  struct StateT * v9699 = v9689->b;
  int v9700 = v9699->timer;
  int v9718 = v9700 + 1;
  v9699->timer = v9718;
  struct StateT * v9702 = v9689->a;
  int * v9703 = v9702->regs;
  int v9704 = v9703[8];
  int v9722 = v9704 + 1;
  v9703[8] = v9722;
  struct StateT * v9706 = v9689->b;
  int * v9707 = v9706->regs;
  int v9708 = v9707[8];
  int v9725 = v9708 + 1;
  v9707[8] = v9725;
  struct StateT2 * v9710 = slot_221(v9689);
  return v9710;
}

struct StateT2 * slot_134(struct StateT2 * v6335) {
  struct StateT * v6336 = v6335->a;
  int v6337 = v6336->timer;
  struct StateT * v6338 = v6335->b;
  int v6339 = v6338->timer;
  bool v6360 = v6337 == v6339;
  squared_assert(v6360);
  squared_assume(v6360);
  struct StateT * v6342 = v6335->a;
  int v6343 = v6342->timer;
  int v6362 = v6343 + 1;
  v6342->timer = v6362;
  struct StateT * v6345 = v6335->b;
  int v6346 = v6345->timer;
  int v6364 = v6346 + 1;
  v6345->timer = v6364;
  struct StateT * v6348 = v6335->a;
  int * v6349 = v6348->regs;
  int v6350 = v6349[8];
  int v6368 = v6350 + 1;
  v6349[8] = v6368;
  struct StateT * v6352 = v6335->b;
  int * v6353 = v6352->regs;
  int v6354 = v6353[8];
  int v6371 = v6354 + 1;
  v6353[8] = v6371;
  struct StateT2 * v6356 = slot_135(v6335);
  return v6356;
}

struct StateT2 * slot_175(struct StateT2 * v7934) {
  struct StateT * v7935 = v7934->a;
  int v7936 = v7935->timer;
  struct StateT * v7937 = v7934->b;
  int v7938 = v7937->timer;
  bool v7959 = v7936 == v7938;
  squared_assert(v7959);
  squared_assume(v7959);
  struct StateT * v7941 = v7934->a;
  int v7942 = v7941->timer;
  int v7961 = v7942 + 1;
  v7941->timer = v7961;
  struct StateT * v7944 = v7934->b;
  int v7945 = v7944->timer;
  int v7963 = v7945 + 1;
  v7944->timer = v7963;
  struct StateT * v7947 = v7934->a;
  int * v7948 = v7947->regs;
  int v7949 = v7948[8];
  int v7967 = v7949 + 1;
  v7948[8] = v7967;
  struct StateT * v7951 = v7934->b;
  int * v7952 = v7951->regs;
  int v7953 = v7952[8];
  int v7970 = v7953 + 1;
  v7952[8] = v7970;
  struct StateT2 * v7955 = slot_176(v7934);
  return v7955;
}

struct StateT2 * slot_69(struct StateT2 * v3800) {
  struct StateT * v3801 = v3800->a;
  int v3802 = v3801->timer;
  struct StateT * v3803 = v3800->b;
  int v3804 = v3803->timer;
  bool v3825 = v3802 == v3804;
  squared_assert(v3825);
  squared_assume(v3825);
  struct StateT * v3807 = v3800->a;
  int v3808 = v3807->timer;
  int v3827 = v3808 + 1;
  v3807->timer = v3827;
  struct StateT * v3810 = v3800->b;
  int v3811 = v3810->timer;
  int v3829 = v3811 + 1;
  v3810->timer = v3829;
  struct StateT * v3813 = v3800->a;
  int * v3814 = v3813->regs;
  int v3815 = v3814[8];
  int v3833 = v3815 + 1;
  v3814[8] = v3833;
  struct StateT * v3817 = v3800->b;
  int * v3818 = v3817->regs;
  int v3819 = v3818[8];
  int v3836 = v3819 + 1;
  v3818[8] = v3836;
  struct StateT2 * v3821 = slot_70(v3800);
  return v3821;
}

struct StateT2 * slot_202(struct StateT2 * v8987) {
  struct StateT * v8988 = v8987->a;
  int v8989 = v8988->timer;
  struct StateT * v8990 = v8987->b;
  int v8991 = v8990->timer;
  bool v9012 = v8989 == v8991;
  squared_assert(v9012);
  squared_assume(v9012);
  struct StateT * v8994 = v8987->a;
  int v8995 = v8994->timer;
  int v9014 = v8995 + 1;
  v8994->timer = v9014;
  struct StateT * v8997 = v8987->b;
  int v8998 = v8997->timer;
  int v9016 = v8998 + 1;
  v8997->timer = v9016;
  struct StateT * v9000 = v8987->a;
  int * v9001 = v9000->regs;
  int v9002 = v9001[8];
  int v9020 = v9002 + 1;
  v9001[8] = v9020;
  struct StateT * v9004 = v8987->b;
  int * v9005 = v9004->regs;
  int v9006 = v9005[8];
  int v9023 = v9006 + 1;
  v9005[8] = v9023;
  struct StateT2 * v9008 = slot_203(v8987);
  return v9008;
}

struct StateT2 * slot_188(struct StateT2 * v8441) {
  struct StateT * v8442 = v8441->a;
  int v8443 = v8442->timer;
  struct StateT * v8444 = v8441->b;
  int v8445 = v8444->timer;
  bool v8466 = v8443 == v8445;
  squared_assert(v8466);
  squared_assume(v8466);
  struct StateT * v8448 = v8441->a;
  int v8449 = v8448->timer;
  int v8468 = v8449 + 1;
  v8448->timer = v8468;
  struct StateT * v8451 = v8441->b;
  int v8452 = v8451->timer;
  int v8470 = v8452 + 1;
  v8451->timer = v8470;
  struct StateT * v8454 = v8441->a;
  int * v8455 = v8454->regs;
  int v8456 = v8455[8];
  int v8474 = v8456 + 1;
  v8455[8] = v8474;
  struct StateT * v8458 = v8441->b;
  int * v8459 = v8458->regs;
  int v8460 = v8459[8];
  int v8477 = v8460 + 1;
  v8459[8] = v8477;
  struct StateT2 * v8462 = slot_189(v8441);
  return v8462;
}

struct StateT2 * slot_138(struct StateT2 * v6491) {
  struct StateT * v6492 = v6491->a;
  int v6493 = v6492->timer;
  struct StateT * v6494 = v6491->b;
  int v6495 = v6494->timer;
  bool v6516 = v6493 == v6495;
  squared_assert(v6516);
  squared_assume(v6516);
  struct StateT * v6498 = v6491->a;
  int v6499 = v6498->timer;
  int v6518 = v6499 + 1;
  v6498->timer = v6518;
  struct StateT * v6501 = v6491->b;
  int v6502 = v6501->timer;
  int v6520 = v6502 + 1;
  v6501->timer = v6520;
  struct StateT * v6504 = v6491->a;
  int * v6505 = v6504->regs;
  int v6506 = v6505[8];
  int v6524 = v6506 + 1;
  v6505[8] = v6524;
  struct StateT * v6508 = v6491->b;
  int * v6509 = v6508->regs;
  int v6510 = v6509[8];
  int v6527 = v6510 + 1;
  v6509[8] = v6527;
  struct StateT2 * v6512 = slot_139(v6491);
  return v6512;
}

struct StateT2 * slot_186(struct StateT2 * v8363) {
  struct StateT * v8364 = v8363->a;
  int v8365 = v8364->timer;
  struct StateT * v8366 = v8363->b;
  int v8367 = v8366->timer;
  bool v8388 = v8365 == v8367;
  squared_assert(v8388);
  squared_assume(v8388);
  struct StateT * v8370 = v8363->a;
  int v8371 = v8370->timer;
  int v8390 = v8371 + 1;
  v8370->timer = v8390;
  struct StateT * v8373 = v8363->b;
  int v8374 = v8373->timer;
  int v8392 = v8374 + 1;
  v8373->timer = v8392;
  struct StateT * v8376 = v8363->a;
  int * v8377 = v8376->regs;
  int v8378 = v8377[8];
  int v8396 = v8378 + 1;
  v8377[8] = v8396;
  struct StateT * v8380 = v8363->b;
  int * v8381 = v8380->regs;
  int v8382 = v8381[8];
  int v8399 = v8382 + 1;
  v8381[8] = v8399;
  struct StateT2 * v8384 = slot_187(v8363);
  return v8384;
}

struct StateT2 * slot_102(struct StateT2 * v5087) {
  struct StateT * v5088 = v5087->a;
  int v5089 = v5088->timer;
  struct StateT * v5090 = v5087->b;
  int v5091 = v5090->timer;
  bool v5112 = v5089 == v5091;
  squared_assert(v5112);
  squared_assume(v5112);
  struct StateT * v5094 = v5087->a;
  int v5095 = v5094->timer;
  int v5114 = v5095 + 1;
  v5094->timer = v5114;
  struct StateT * v5097 = v5087->b;
  int v5098 = v5097->timer;
  int v5116 = v5098 + 1;
  v5097->timer = v5116;
  struct StateT * v5100 = v5087->a;
  int * v5101 = v5100->regs;
  int v5102 = v5101[8];
  int v5120 = v5102 + 1;
  v5101[8] = v5120;
  struct StateT * v5104 = v5087->b;
  int * v5105 = v5104->regs;
  int v5106 = v5105[8];
  int v5123 = v5106 + 1;
  v5105[8] = v5123;
  struct StateT2 * v5108 = slot_103(v5087);
  return v5108;
}

struct StateT2 * slot_145(struct StateT2 * v6764) {
  struct StateT * v6765 = v6764->a;
  int v6766 = v6765->timer;
  struct StateT * v6767 = v6764->b;
  int v6768 = v6767->timer;
  bool v6789 = v6766 == v6768;
  squared_assert(v6789);
  squared_assume(v6789);
  struct StateT * v6771 = v6764->a;
  int v6772 = v6771->timer;
  int v6791 = v6772 + 1;
  v6771->timer = v6791;
  struct StateT * v6774 = v6764->b;
  int v6775 = v6774->timer;
  int v6793 = v6775 + 1;
  v6774->timer = v6793;
  struct StateT * v6777 = v6764->a;
  int * v6778 = v6777->regs;
  int v6779 = v6778[8];
  int v6797 = v6779 + 1;
  v6778[8] = v6797;
  struct StateT * v6781 = v6764->b;
  int * v6782 = v6781->regs;
  int v6783 = v6782[8];
  int v6800 = v6783 + 1;
  v6782[8] = v6800;
  struct StateT2 * v6785 = slot_146(v6764);
  return v6785;
}

struct StateT2 * slot_110(struct StateT2 * v5399) {
  struct StateT * v5400 = v5399->a;
  int v5401 = v5400->timer;
  struct StateT * v5402 = v5399->b;
  int v5403 = v5402->timer;
  bool v5424 = v5401 == v5403;
  squared_assert(v5424);
  squared_assume(v5424);
  struct StateT * v5406 = v5399->a;
  int v5407 = v5406->timer;
  int v5426 = v5407 + 1;
  v5406->timer = v5426;
  struct StateT * v5409 = v5399->b;
  int v5410 = v5409->timer;
  int v5428 = v5410 + 1;
  v5409->timer = v5428;
  struct StateT * v5412 = v5399->a;
  int * v5413 = v5412->regs;
  int v5414 = v5413[8];
  int v5432 = v5414 + 1;
  v5413[8] = v5432;
  struct StateT * v5416 = v5399->b;
  int * v5417 = v5416->regs;
  int v5418 = v5417[8];
  int v5435 = v5418 + 1;
  v5417[8] = v5435;
  struct StateT2 * v5420 = slot_111(v5399);
  return v5420;
}

struct StateT2 * slot_196(struct StateT2 * v8753) {
  struct StateT * v8754 = v8753->a;
  int v8755 = v8754->timer;
  struct StateT * v8756 = v8753->b;
  int v8757 = v8756->timer;
  bool v8778 = v8755 == v8757;
  squared_assert(v8778);
  squared_assume(v8778);
  struct StateT * v8760 = v8753->a;
  int v8761 = v8760->timer;
  int v8780 = v8761 + 1;
  v8760->timer = v8780;
  struct StateT * v8763 = v8753->b;
  int v8764 = v8763->timer;
  int v8782 = v8764 + 1;
  v8763->timer = v8782;
  struct StateT * v8766 = v8753->a;
  int * v8767 = v8766->regs;
  int v8768 = v8767[8];
  int v8786 = v8768 + 1;
  v8767[8] = v8786;
  struct StateT * v8770 = v8753->b;
  int * v8771 = v8770->regs;
  int v8772 = v8771[8];
  int v8789 = v8772 + 1;
  v8771[8] = v8789;
  struct StateT2 * v8774 = slot_197(v8753);
  return v8774;
}

struct StateT2 * slot_208(struct StateT2 * v9221) {
  struct StateT * v9222 = v9221->a;
  int v9223 = v9222->timer;
  struct StateT * v9224 = v9221->b;
  int v9225 = v9224->timer;
  bool v9246 = v9223 == v9225;
  squared_assert(v9246);
  squared_assume(v9246);
  struct StateT * v9228 = v9221->a;
  int v9229 = v9228->timer;
  int v9248 = v9229 + 1;
  v9228->timer = v9248;
  struct StateT * v9231 = v9221->b;
  int v9232 = v9231->timer;
  int v9250 = v9232 + 1;
  v9231->timer = v9250;
  struct StateT * v9234 = v9221->a;
  int * v9235 = v9234->regs;
  int v9236 = v9235[8];
  int v9254 = v9236 + 1;
  v9235[8] = v9254;
  struct StateT * v9238 = v9221->b;
  int * v9239 = v9238->regs;
  int v9240 = v9239[8];
  int v9257 = v9240 + 1;
  v9239[8] = v9257;
  struct StateT2 * v9242 = slot_209(v9221);
  return v9242;
}

struct StateT2 * slot_172(struct StateT2 * v7817) {
  struct StateT * v7818 = v7817->a;
  int v7819 = v7818->timer;
  struct StateT * v7820 = v7817->b;
  int v7821 = v7820->timer;
  bool v7842 = v7819 == v7821;
  squared_assert(v7842);
  squared_assume(v7842);
  struct StateT * v7824 = v7817->a;
  int v7825 = v7824->timer;
  int v7844 = v7825 + 1;
  v7824->timer = v7844;
  struct StateT * v7827 = v7817->b;
  int v7828 = v7827->timer;
  int v7846 = v7828 + 1;
  v7827->timer = v7846;
  struct StateT * v7830 = v7817->a;
  int * v7831 = v7830->regs;
  int v7832 = v7831[8];
  int v7850 = v7832 + 1;
  v7831[8] = v7850;
  struct StateT * v7834 = v7817->b;
  int * v7835 = v7834->regs;
  int v7836 = v7835[8];
  int v7853 = v7836 + 1;
  v7835[8] = v7853;
  struct StateT2 * v7838 = slot_173(v7817);
  return v7838;
}

struct StateT2 * slot_131(struct StateT2 * v6218) {
  struct StateT * v6219 = v6218->a;
  int v6220 = v6219->timer;
  struct StateT * v6221 = v6218->b;
  int v6222 = v6221->timer;
  bool v6243 = v6220 == v6222;
  squared_assert(v6243);
  squared_assume(v6243);
  struct StateT * v6225 = v6218->a;
  int v6226 = v6225->timer;
  int v6245 = v6226 + 1;
  v6225->timer = v6245;
  struct StateT * v6228 = v6218->b;
  int v6229 = v6228->timer;
  int v6247 = v6229 + 1;
  v6228->timer = v6247;
  struct StateT * v6231 = v6218->a;
  int * v6232 = v6231->regs;
  int v6233 = v6232[8];
  int v6251 = v6233 + 1;
  v6232[8] = v6251;
  struct StateT * v6235 = v6218->b;
  int * v6236 = v6235->regs;
  int v6237 = v6236[8];
  int v6254 = v6237 + 1;
  v6236[8] = v6254;
  struct StateT2 * v6239 = slot_132(v6218);
  return v6239;
}

struct StateT2 * slot_8(struct StateT2 * v1421) {
  struct StateT * v1422 = v1421->a;
  int v1423 = v1422->timer;
  struct StateT * v1424 = v1421->b;
  int v1425 = v1424->timer;
  bool v1446 = v1423 == v1425;
  squared_assert(v1446);
  squared_assume(v1446);
  struct StateT * v1428 = v1421->a;
  int v1429 = v1428->timer;
  int v1448 = v1429 + 1;
  v1428->timer = v1448;
  struct StateT * v1431 = v1421->b;
  int v1432 = v1431->timer;
  int v1450 = v1432 + 1;
  v1431->timer = v1450;
  struct StateT * v1434 = v1421->a;
  int * v1435 = v1434->regs;
  int v1436 = v1435[8];
  int v1454 = v1436 + 1;
  v1435[8] = v1454;
  struct StateT * v1438 = v1421->b;
  int * v1439 = v1438->regs;
  int v1440 = v1439[8];
  int v1457 = v1440 + 1;
  v1439[8] = v1457;
  struct StateT2 * v1442 = slot_9(v1421);
  return v1442;
}

struct StateT2 * slot_180(struct StateT2 * v8129) {
  struct StateT * v8130 = v8129->a;
  int v8131 = v8130->timer;
  struct StateT * v8132 = v8129->b;
  int v8133 = v8132->timer;
  bool v8154 = v8131 == v8133;
  squared_assert(v8154);
  squared_assume(v8154);
  struct StateT * v8136 = v8129->a;
  int v8137 = v8136->timer;
  int v8156 = v8137 + 1;
  v8136->timer = v8156;
  struct StateT * v8139 = v8129->b;
  int v8140 = v8139->timer;
  int v8158 = v8140 + 1;
  v8139->timer = v8158;
  struct StateT * v8142 = v8129->a;
  int * v8143 = v8142->regs;
  int v8144 = v8143[8];
  int v8162 = v8144 + 1;
  v8143[8] = v8162;
  struct StateT * v8146 = v8129->b;
  int * v8147 = v8146->regs;
  int v8148 = v8147[8];
  int v8165 = v8148 + 1;
  v8147[8] = v8165;
  struct StateT2 * v8150 = slot_181(v8129);
  return v8150;
}

struct StateT2 * slot_203(struct StateT2 * v9026) {
  struct StateT * v9027 = v9026->a;
  int v9028 = v9027->timer;
  struct StateT * v9029 = v9026->b;
  int v9030 = v9029->timer;
  bool v9051 = v9028 == v9030;
  squared_assert(v9051);
  squared_assume(v9051);
  struct StateT * v9033 = v9026->a;
  int v9034 = v9033->timer;
  int v9053 = v9034 + 1;
  v9033->timer = v9053;
  struct StateT * v9036 = v9026->b;
  int v9037 = v9036->timer;
  int v9055 = v9037 + 1;
  v9036->timer = v9055;
  struct StateT * v9039 = v9026->a;
  int * v9040 = v9039->regs;
  int v9041 = v9040[8];
  int v9059 = v9041 + 1;
  v9040[8] = v9059;
  struct StateT * v9043 = v9026->b;
  int * v9044 = v9043->regs;
  int v9045 = v9044[8];
  int v9062 = v9045 + 1;
  v9044[8] = v9062;
  struct StateT2 * v9047 = slot_204(v9026);
  return v9047;
}

struct StateT2 * slot_190(struct StateT2 * v8519) {
  struct StateT * v8520 = v8519->a;
  int v8521 = v8520->timer;
  struct StateT * v8522 = v8519->b;
  int v8523 = v8522->timer;
  bool v8544 = v8521 == v8523;
  squared_assert(v8544);
  squared_assume(v8544);
  struct StateT * v8526 = v8519->a;
  int v8527 = v8526->timer;
  int v8546 = v8527 + 1;
  v8526->timer = v8546;
  struct StateT * v8529 = v8519->b;
  int v8530 = v8529->timer;
  int v8548 = v8530 + 1;
  v8529->timer = v8548;
  struct StateT * v8532 = v8519->a;
  int * v8533 = v8532->regs;
  int v8534 = v8533[8];
  int v8552 = v8534 + 1;
  v8533[8] = v8552;
  struct StateT * v8536 = v8519->b;
  int * v8537 = v8536->regs;
  int v8538 = v8537[8];
  int v8555 = v8538 + 1;
  v8537[8] = v8555;
  struct StateT2 * v8540 = slot_191(v8519);
  return v8540;
}

struct StateT2 * slot_157(struct StateT2 * v7232) {
  struct StateT * v7233 = v7232->a;
  int v7234 = v7233->timer;
  struct StateT * v7235 = v7232->b;
  int v7236 = v7235->timer;
  bool v7257 = v7234 == v7236;
  squared_assert(v7257);
  squared_assume(v7257);
  struct StateT * v7239 = v7232->a;
  int v7240 = v7239->timer;
  int v7259 = v7240 + 1;
  v7239->timer = v7259;
  struct StateT * v7242 = v7232->b;
  int v7243 = v7242->timer;
  int v7261 = v7243 + 1;
  v7242->timer = v7261;
  struct StateT * v7245 = v7232->a;
  int * v7246 = v7245->regs;
  int v7247 = v7246[8];
  int v7265 = v7247 + 1;
  v7246[8] = v7265;
  struct StateT * v7249 = v7232->b;
  int * v7250 = v7249->regs;
  int v7251 = v7250[8];
  int v7268 = v7251 + 1;
  v7250[8] = v7268;
  struct StateT2 * v7253 = slot_158(v7232);
  return v7253;
}

struct StateT2 * slot_200(struct StateT2 * v8909) {
  struct StateT * v8910 = v8909->a;
  int v8911 = v8910->timer;
  struct StateT * v8912 = v8909->b;
  int v8913 = v8912->timer;
  bool v8934 = v8911 == v8913;
  squared_assert(v8934);
  squared_assume(v8934);
  struct StateT * v8916 = v8909->a;
  int v8917 = v8916->timer;
  int v8936 = v8917 + 1;
  v8916->timer = v8936;
  struct StateT * v8919 = v8909->b;
  int v8920 = v8919->timer;
  int v8938 = v8920 + 1;
  v8919->timer = v8938;
  struct StateT * v8922 = v8909->a;
  int * v8923 = v8922->regs;
  int v8924 = v8923[8];
  int v8942 = v8924 + 1;
  v8923[8] = v8942;
  struct StateT * v8926 = v8909->b;
  int * v8927 = v8926->regs;
  int v8928 = v8927[8];
  int v8945 = v8928 + 1;
  v8927[8] = v8945;
  struct StateT2 * v8930 = slot_201(v8909);
  return v8930;
}

struct StateT2 * slot_173(struct StateT2 * v7856) {
  struct StateT * v7857 = v7856->a;
  int v7858 = v7857->timer;
  struct StateT * v7859 = v7856->b;
  int v7860 = v7859->timer;
  bool v7881 = v7858 == v7860;
  squared_assert(v7881);
  squared_assume(v7881);
  struct StateT * v7863 = v7856->a;
  int v7864 = v7863->timer;
  int v7883 = v7864 + 1;
  v7863->timer = v7883;
  struct StateT * v7866 = v7856->b;
  int v7867 = v7866->timer;
  int v7885 = v7867 + 1;
  v7866->timer = v7885;
  struct StateT * v7869 = v7856->a;
  int * v7870 = v7869->regs;
  int v7871 = v7870[8];
  int v7889 = v7871 + 1;
  v7870[8] = v7889;
  struct StateT * v7873 = v7856->b;
  int * v7874 = v7873->regs;
  int v7875 = v7874[8];
  int v7892 = v7875 + 1;
  v7874[8] = v7892;
  struct StateT2 * v7877 = slot_174(v7856);
  return v7877;
}

struct StateT2 * slot_149(struct StateT2 * v6920) {
  struct StateT * v6921 = v6920->a;
  int v6922 = v6921->timer;
  struct StateT * v6923 = v6920->b;
  int v6924 = v6923->timer;
  bool v6945 = v6922 == v6924;
  squared_assert(v6945);
  squared_assume(v6945);
  struct StateT * v6927 = v6920->a;
  int v6928 = v6927->timer;
  int v6947 = v6928 + 1;
  v6927->timer = v6947;
  struct StateT * v6930 = v6920->b;
  int v6931 = v6930->timer;
  int v6949 = v6931 + 1;
  v6930->timer = v6949;
  struct StateT * v6933 = v6920->a;
  int * v6934 = v6933->regs;
  int v6935 = v6934[8];
  int v6953 = v6935 + 1;
  v6934[8] = v6953;
  struct StateT * v6937 = v6920->b;
  int * v6938 = v6937->regs;
  int v6939 = v6938[8];
  int v6956 = v6939 + 1;
  v6938[8] = v6956;
  struct StateT2 * v6941 = slot_150(v6920);
  return v6941;
}

struct StateT2 * slot_5(struct StateT2 * v1307) {
  struct StateT * v1308 = v1307->a;
  int v1309 = v1308->timer;
  struct StateT * v1310 = v1307->b;
  int v1311 = v1310->timer;
  bool v1330 = v1309 == v1311;
  squared_assert(v1330);
  squared_assume(v1330);
  struct StateT * v1314 = v1307->a;
  int v1315 = v1314->timer;
  int v1332 = v1315 + 1;
  v1314->timer = v1332;
  struct StateT * v1317 = v1307->b;
  int v1318 = v1317->timer;
  int v1334 = v1318 + 1;
  v1317->timer = v1334;
  struct StateT * v1320 = v1307->a;
  int * v1321 = v1320->regs;
  v1321[8] = 0;
  struct StateT * v1323 = v1307->b;
  int * v1324 = v1323->regs;
  v1324[8] = 0;
  struct StateT2 * v1326 = slot_6(v1307);
  return v1326;
}

struct StateT2 * slot_104(struct StateT2 * v5165) {
  struct StateT * v5166 = v5165->a;
  int v5167 = v5166->timer;
  struct StateT * v5168 = v5165->b;
  int v5169 = v5168->timer;
  bool v5190 = v5167 == v5169;
  squared_assert(v5190);
  squared_assume(v5190);
  struct StateT * v5172 = v5165->a;
  int v5173 = v5172->timer;
  int v5192 = v5173 + 1;
  v5172->timer = v5192;
  struct StateT * v5175 = v5165->b;
  int v5176 = v5175->timer;
  int v5194 = v5176 + 1;
  v5175->timer = v5194;
  struct StateT * v5178 = v5165->a;
  int * v5179 = v5178->regs;
  int v5180 = v5179[8];
  int v5198 = v5180 + 1;
  v5179[8] = v5198;
  struct StateT * v5182 = v5165->b;
  int * v5183 = v5182->regs;
  int v5184 = v5183[8];
  int v5201 = v5184 + 1;
  v5183[8] = v5201;
  struct StateT2 * v5186 = slot_105(v5165);
  return v5186;
}

struct StateT2 * slot_54(struct StateT2 * v3215) {
  struct StateT * v3216 = v3215->a;
  int v3217 = v3216->timer;
  struct StateT * v3218 = v3215->b;
  int v3219 = v3218->timer;
  bool v3240 = v3217 == v3219;
  squared_assert(v3240);
  squared_assume(v3240);
  struct StateT * v3222 = v3215->a;
  int v3223 = v3222->timer;
  int v3242 = v3223 + 1;
  v3222->timer = v3242;
  struct StateT * v3225 = v3215->b;
  int v3226 = v3225->timer;
  int v3244 = v3226 + 1;
  v3225->timer = v3244;
  struct StateT * v3228 = v3215->a;
  int * v3229 = v3228->regs;
  int v3230 = v3229[8];
  int v3248 = v3230 + 1;
  v3229[8] = v3248;
  struct StateT * v3232 = v3215->b;
  int * v3233 = v3232->regs;
  int v3234 = v3233[8];
  int v3251 = v3234 + 1;
  v3233[8] = v3251;
  struct StateT2 * v3236 = slot_55(v3215);
  return v3236;
}

struct StateT2 * slot_26(struct StateT2 * v2123) {
  struct StateT * v2124 = v2123->a;
  int v2125 = v2124->timer;
  struct StateT * v2126 = v2123->b;
  int v2127 = v2126->timer;
  bool v2148 = v2125 == v2127;
  squared_assert(v2148);
  squared_assume(v2148);
  struct StateT * v2130 = v2123->a;
  int v2131 = v2130->timer;
  int v2150 = v2131 + 1;
  v2130->timer = v2150;
  struct StateT * v2133 = v2123->b;
  int v2134 = v2133->timer;
  int v2152 = v2134 + 1;
  v2133->timer = v2152;
  struct StateT * v2136 = v2123->a;
  int * v2137 = v2136->regs;
  int v2138 = v2137[8];
  int v2156 = v2138 + 1;
  v2137[8] = v2156;
  struct StateT * v2140 = v2123->b;
  int * v2141 = v2140->regs;
  int v2142 = v2141[8];
  int v2159 = v2142 + 1;
  v2141[8] = v2159;
  struct StateT2 * v2144 = slot_27(v2123);
  return v2144;
}

struct StateT2 * slot_206(struct StateT2 * v9143) {
  struct StateT * v9144 = v9143->a;
  int v9145 = v9144->timer;
  struct StateT * v9146 = v9143->b;
  int v9147 = v9146->timer;
  bool v9168 = v9145 == v9147;
  squared_assert(v9168);
  squared_assume(v9168);
  struct StateT * v9150 = v9143->a;
  int v9151 = v9150->timer;
  int v9170 = v9151 + 1;
  v9150->timer = v9170;
  struct StateT * v9153 = v9143->b;
  int v9154 = v9153->timer;
  int v9172 = v9154 + 1;
  v9153->timer = v9172;
  struct StateT * v9156 = v9143->a;
  int * v9157 = v9156->regs;
  int v9158 = v9157[8];
  int v9176 = v9158 + 1;
  v9157[8] = v9176;
  struct StateT * v9160 = v9143->b;
  int * v9161 = v9160->regs;
  int v9162 = v9161[8];
  int v9179 = v9162 + 1;
  v9161[8] = v9179;
  struct StateT2 * v9164 = slot_207(v9143);
  return v9164;
}

struct StateT2 * slot_169(struct StateT2 * v7700) {
  struct StateT * v7701 = v7700->a;
  int v7702 = v7701->timer;
  struct StateT * v7703 = v7700->b;
  int v7704 = v7703->timer;
  bool v7725 = v7702 == v7704;
  squared_assert(v7725);
  squared_assume(v7725);
  struct StateT * v7707 = v7700->a;
  int v7708 = v7707->timer;
  int v7727 = v7708 + 1;
  v7707->timer = v7727;
  struct StateT * v7710 = v7700->b;
  int v7711 = v7710->timer;
  int v7729 = v7711 + 1;
  v7710->timer = v7729;
  struct StateT * v7713 = v7700->a;
  int * v7714 = v7713->regs;
  int v7715 = v7714[8];
  int v7733 = v7715 + 1;
  v7714[8] = v7733;
  struct StateT * v7717 = v7700->b;
  int * v7718 = v7717->regs;
  int v7719 = v7718[8];
  int v7736 = v7719 + 1;
  v7718[8] = v7736;
  struct StateT2 * v7721 = slot_170(v7700);
  return v7721;
}

struct StateT2 * slot_64(struct StateT2 * v3605) {
  struct StateT * v3606 = v3605->a;
  int v3607 = v3606->timer;
  struct StateT * v3608 = v3605->b;
  int v3609 = v3608->timer;
  bool v3630 = v3607 == v3609;
  squared_assert(v3630);
  squared_assume(v3630);
  struct StateT * v3612 = v3605->a;
  int v3613 = v3612->timer;
  int v3632 = v3613 + 1;
  v3612->timer = v3632;
  struct StateT * v3615 = v3605->b;
  int v3616 = v3615->timer;
  int v3634 = v3616 + 1;
  v3615->timer = v3634;
  struct StateT * v3618 = v3605->a;
  int * v3619 = v3618->regs;
  int v3620 = v3619[8];
  int v3638 = v3620 + 1;
  v3619[8] = v3638;
  struct StateT * v3622 = v3605->b;
  int * v3623 = v3622->regs;
  int v3624 = v3623[8];
  int v3641 = v3624 + 1;
  v3623[8] = v3641;
  struct StateT2 * v3626 = slot_65(v3605);
  return v3626;
}

struct StateT2 * slot_170(struct StateT2 * v7739) {
  struct StateT * v7740 = v7739->a;
  int v7741 = v7740->timer;
  struct StateT * v7742 = v7739->b;
  int v7743 = v7742->timer;
  bool v7764 = v7741 == v7743;
  squared_assert(v7764);
  squared_assume(v7764);
  struct StateT * v7746 = v7739->a;
  int v7747 = v7746->timer;
  int v7766 = v7747 + 1;
  v7746->timer = v7766;
  struct StateT * v7749 = v7739->b;
  int v7750 = v7749->timer;
  int v7768 = v7750 + 1;
  v7749->timer = v7768;
  struct StateT * v7752 = v7739->a;
  int * v7753 = v7752->regs;
  int v7754 = v7753[8];
  int v7772 = v7754 + 1;
  v7753[8] = v7772;
  struct StateT * v7756 = v7739->b;
  int * v7757 = v7756->regs;
  int v7758 = v7757[8];
  int v7775 = v7758 + 1;
  v7757[8] = v7775;
  struct StateT2 * v7760 = slot_171(v7739);
  return v7760;
}

struct StateT2 * slot_14(struct StateT2 * v1655) {
  struct StateT * v1656 = v1655->a;
  int v1657 = v1656->timer;
  struct StateT * v1658 = v1655->b;
  int v1659 = v1658->timer;
  bool v1680 = v1657 == v1659;
  squared_assert(v1680);
  squared_assume(v1680);
  struct StateT * v1662 = v1655->a;
  int v1663 = v1662->timer;
  int v1682 = v1663 + 1;
  v1662->timer = v1682;
  struct StateT * v1665 = v1655->b;
  int v1666 = v1665->timer;
  int v1684 = v1666 + 1;
  v1665->timer = v1684;
  struct StateT * v1668 = v1655->a;
  int * v1669 = v1668->regs;
  int v1670 = v1669[8];
  int v1688 = v1670 + 1;
  v1669[8] = v1688;
  struct StateT * v1672 = v1655->b;
  int * v1673 = v1672->regs;
  int v1674 = v1673[8];
  int v1691 = v1674 + 1;
  v1673[8] = v1691;
  struct StateT2 * v1676 = slot_15(v1655);
  return v1676;
}

struct StateT2 * slot_53(struct StateT2 * v3176) {
  struct StateT * v3177 = v3176->a;
  int v3178 = v3177->timer;
  struct StateT * v3179 = v3176->b;
  int v3180 = v3179->timer;
  bool v3201 = v3178 == v3180;
  squared_assert(v3201);
  squared_assume(v3201);
  struct StateT * v3183 = v3176->a;
  int v3184 = v3183->timer;
  int v3203 = v3184 + 1;
  v3183->timer = v3203;
  struct StateT * v3186 = v3176->b;
  int v3187 = v3186->timer;
  int v3205 = v3187 + 1;
  v3186->timer = v3205;
  struct StateT * v3189 = v3176->a;
  int * v3190 = v3189->regs;
  int v3191 = v3190[8];
  int v3209 = v3191 + 1;
  v3190[8] = v3209;
  struct StateT * v3193 = v3176->b;
  int * v3194 = v3193->regs;
  int v3195 = v3194[8];
  int v3212 = v3195 + 1;
  v3194[8] = v3212;
  struct StateT2 * v3197 = slot_54(v3176);
  return v3197;
}

struct StateT2 * slot_80(struct StateT2 * v4229) {
  struct StateT * v4230 = v4229->a;
  int v4231 = v4230->timer;
  struct StateT * v4232 = v4229->b;
  int v4233 = v4232->timer;
  bool v4254 = v4231 == v4233;
  squared_assert(v4254);
  squared_assume(v4254);
  struct StateT * v4236 = v4229->a;
  int v4237 = v4236->timer;
  int v4256 = v4237 + 1;
  v4236->timer = v4256;
  struct StateT * v4239 = v4229->b;
  int v4240 = v4239->timer;
  int v4258 = v4240 + 1;
  v4239->timer = v4258;
  struct StateT * v4242 = v4229->a;
  int * v4243 = v4242->regs;
  int v4244 = v4243[8];
  int v4262 = v4244 + 1;
  v4243[8] = v4262;
  struct StateT * v4246 = v4229->b;
  int * v4247 = v4246->regs;
  int v4248 = v4247[8];
  int v4265 = v4248 + 1;
  v4247[8] = v4265;
  struct StateT2 * v4250 = slot_81(v4229);
  return v4250;
}

struct StateT2 * slot_44(struct StateT2 * v2825) {
  struct StateT * v2826 = v2825->a;
  int v2827 = v2826->timer;
  struct StateT * v2828 = v2825->b;
  int v2829 = v2828->timer;
  bool v2850 = v2827 == v2829;
  squared_assert(v2850);
  squared_assume(v2850);
  struct StateT * v2832 = v2825->a;
  int v2833 = v2832->timer;
  int v2852 = v2833 + 1;
  v2832->timer = v2852;
  struct StateT * v2835 = v2825->b;
  int v2836 = v2835->timer;
  int v2854 = v2836 + 1;
  v2835->timer = v2854;
  struct StateT * v2838 = v2825->a;
  int * v2839 = v2838->regs;
  int v2840 = v2839[8];
  int v2858 = v2840 + 1;
  v2839[8] = v2858;
  struct StateT * v2842 = v2825->b;
  int * v2843 = v2842->regs;
  int v2844 = v2843[8];
  int v2861 = v2844 + 1;
  v2843[8] = v2861;
  struct StateT2 * v2846 = slot_45(v2825);
  return v2846;
}

struct StateT2 * slot_137(struct StateT2 * v6452) {
  struct StateT * v6453 = v6452->a;
  int v6454 = v6453->timer;
  struct StateT * v6455 = v6452->b;
  int v6456 = v6455->timer;
  bool v6477 = v6454 == v6456;
  squared_assert(v6477);
  squared_assume(v6477);
  struct StateT * v6459 = v6452->a;
  int v6460 = v6459->timer;
  int v6479 = v6460 + 1;
  v6459->timer = v6479;
  struct StateT * v6462 = v6452->b;
  int v6463 = v6462->timer;
  int v6481 = v6463 + 1;
  v6462->timer = v6481;
  struct StateT * v6465 = v6452->a;
  int * v6466 = v6465->regs;
  int v6467 = v6466[8];
  int v6485 = v6467 + 1;
  v6466[8] = v6485;
  struct StateT * v6469 = v6452->b;
  int * v6470 = v6469->regs;
  int v6471 = v6470[8];
  int v6488 = v6471 + 1;
  v6470[8] = v6488;
  struct StateT2 * v6473 = slot_138(v6452);
  return v6473;
}

struct StateT2 * slot_122(struct StateT2 * v5867) {
  struct StateT * v5868 = v5867->a;
  int v5869 = v5868->timer;
  struct StateT * v5870 = v5867->b;
  int v5871 = v5870->timer;
  bool v5892 = v5869 == v5871;
  squared_assert(v5892);
  squared_assume(v5892);
  struct StateT * v5874 = v5867->a;
  int v5875 = v5874->timer;
  int v5894 = v5875 + 1;
  v5874->timer = v5894;
  struct StateT * v5877 = v5867->b;
  int v5878 = v5877->timer;
  int v5896 = v5878 + 1;
  v5877->timer = v5896;
  struct StateT * v5880 = v5867->a;
  int * v5881 = v5880->regs;
  int v5882 = v5881[8];
  int v5900 = v5882 + 1;
  v5881[8] = v5900;
  struct StateT * v5884 = v5867->b;
  int * v5885 = v5884->regs;
  int v5886 = v5885[8];
  int v5903 = v5886 + 1;
  v5885[8] = v5903;
  struct StateT2 * v5888 = slot_123(v5867);
  return v5888;
}

struct StateT2 * slot_99(struct StateT2 * v4970) {
  struct StateT * v4971 = v4970->a;
  int v4972 = v4971->timer;
  struct StateT * v4973 = v4970->b;
  int v4974 = v4973->timer;
  bool v4995 = v4972 == v4974;
  squared_assert(v4995);
  squared_assume(v4995);
  struct StateT * v4977 = v4970->a;
  int v4978 = v4977->timer;
  int v4997 = v4978 + 1;
  v4977->timer = v4997;
  struct StateT * v4980 = v4970->b;
  int v4981 = v4980->timer;
  int v4999 = v4981 + 1;
  v4980->timer = v4999;
  struct StateT * v4983 = v4970->a;
  int * v4984 = v4983->regs;
  int v4985 = v4984[8];
  int v5003 = v4985 + 1;
  v4984[8] = v5003;
  struct StateT * v4987 = v4970->b;
  int * v4988 = v4987->regs;
  int v4989 = v4988[8];
  int v5006 = v4989 + 1;
  v4988[8] = v5006;
  struct StateT2 * v4991 = slot_100(v4970);
  return v4991;
}

struct StateT2 * slot_179(struct StateT2 * v8090) {
  struct StateT * v8091 = v8090->a;
  int v8092 = v8091->timer;
  struct StateT * v8093 = v8090->b;
  int v8094 = v8093->timer;
  bool v8115 = v8092 == v8094;
  squared_assert(v8115);
  squared_assume(v8115);
  struct StateT * v8097 = v8090->a;
  int v8098 = v8097->timer;
  int v8117 = v8098 + 1;
  v8097->timer = v8117;
  struct StateT * v8100 = v8090->b;
  int v8101 = v8100->timer;
  int v8119 = v8101 + 1;
  v8100->timer = v8119;
  struct StateT * v8103 = v8090->a;
  int * v8104 = v8103->regs;
  int v8105 = v8104[8];
  int v8123 = v8105 + 1;
  v8104[8] = v8123;
  struct StateT * v8107 = v8090->b;
  int * v8108 = v8107->regs;
  int v8109 = v8108[8];
  int v8126 = v8109 + 1;
  v8108[8] = v8126;
  struct StateT2 * v8111 = slot_180(v8090);
  return v8111;
}

struct StateT2 * slot_219(struct StateT2 * v9650) {
  struct StateT * v9651 = v9650->a;
  int v9652 = v9651->timer;
  struct StateT * v9653 = v9650->b;
  int v9654 = v9653->timer;
  bool v9675 = v9652 == v9654;
  squared_assert(v9675);
  squared_assume(v9675);
  struct StateT * v9657 = v9650->a;
  int v9658 = v9657->timer;
  int v9677 = v9658 + 1;
  v9657->timer = v9677;
  struct StateT * v9660 = v9650->b;
  int v9661 = v9660->timer;
  int v9679 = v9661 + 1;
  v9660->timer = v9679;
  struct StateT * v9663 = v9650->a;
  int * v9664 = v9663->regs;
  int v9665 = v9664[8];
  int v9683 = v9665 + 1;
  v9664[8] = v9683;
  struct StateT * v9667 = v9650->b;
  int * v9668 = v9667->regs;
  int v9669 = v9668[8];
  int v9686 = v9669 + 1;
  v9668[8] = v9686;
  struct StateT2 * v9671 = slot_220(v9650);
  return v9671;
}

struct StateT2 * slot_36(struct StateT2 * v2513) {
  struct StateT * v2514 = v2513->a;
  int v2515 = v2514->timer;
  struct StateT * v2516 = v2513->b;
  int v2517 = v2516->timer;
  bool v2538 = v2515 == v2517;
  squared_assert(v2538);
  squared_assume(v2538);
  struct StateT * v2520 = v2513->a;
  int v2521 = v2520->timer;
  int v2540 = v2521 + 1;
  v2520->timer = v2540;
  struct StateT * v2523 = v2513->b;
  int v2524 = v2523->timer;
  int v2542 = v2524 + 1;
  v2523->timer = v2542;
  struct StateT * v2526 = v2513->a;
  int * v2527 = v2526->regs;
  int v2528 = v2527[8];
  int v2546 = v2528 + 1;
  v2527[8] = v2546;
  struct StateT * v2530 = v2513->b;
  int * v2531 = v2530->regs;
  int v2532 = v2531[8];
  int v2549 = v2532 + 1;
  v2531[8] = v2549;
  struct StateT2 * v2534 = slot_37(v2513);
  return v2534;
}

struct StateT2 * slot_57(struct StateT2 * v3332) {
  struct StateT * v3333 = v3332->a;
  int v3334 = v3333->timer;
  struct StateT * v3335 = v3332->b;
  int v3336 = v3335->timer;
  bool v3357 = v3334 == v3336;
  squared_assert(v3357);
  squared_assume(v3357);
  struct StateT * v3339 = v3332->a;
  int v3340 = v3339->timer;
  int v3359 = v3340 + 1;
  v3339->timer = v3359;
  struct StateT * v3342 = v3332->b;
  int v3343 = v3342->timer;
  int v3361 = v3343 + 1;
  v3342->timer = v3361;
  struct StateT * v3345 = v3332->a;
  int * v3346 = v3345->regs;
  int v3347 = v3346[8];
  int v3365 = v3347 + 1;
  v3346[8] = v3365;
  struct StateT * v3349 = v3332->b;
  int * v3350 = v3349->regs;
  int v3351 = v3350[8];
  int v3368 = v3351 + 1;
  v3350[8] = v3368;
  struct StateT2 * v3353 = slot_58(v3332);
  return v3353;
}

struct StateT2 * slot_62(struct StateT2 * v3527) {
  struct StateT * v3528 = v3527->a;
  int v3529 = v3528->timer;
  struct StateT * v3530 = v3527->b;
  int v3531 = v3530->timer;
  bool v3552 = v3529 == v3531;
  squared_assert(v3552);
  squared_assume(v3552);
  struct StateT * v3534 = v3527->a;
  int v3535 = v3534->timer;
  int v3554 = v3535 + 1;
  v3534->timer = v3554;
  struct StateT * v3537 = v3527->b;
  int v3538 = v3537->timer;
  int v3556 = v3538 + 1;
  v3537->timer = v3556;
  struct StateT * v3540 = v3527->a;
  int * v3541 = v3540->regs;
  int v3542 = v3541[8];
  int v3560 = v3542 + 1;
  v3541[8] = v3560;
  struct StateT * v3544 = v3527->b;
  int * v3545 = v3544->regs;
  int v3546 = v3545[8];
  int v3563 = v3546 + 1;
  v3545[8] = v3563;
  struct StateT2 * v3548 = slot_63(v3527);
  return v3548;
}

struct StateT2 * slot_22(struct StateT2 * v1967) {
  struct StateT * v1968 = v1967->a;
  int v1969 = v1968->timer;
  struct StateT * v1970 = v1967->b;
  int v1971 = v1970->timer;
  bool v1992 = v1969 == v1971;
  squared_assert(v1992);
  squared_assume(v1992);
  struct StateT * v1974 = v1967->a;
  int v1975 = v1974->timer;
  int v1994 = v1975 + 1;
  v1974->timer = v1994;
  struct StateT * v1977 = v1967->b;
  int v1978 = v1977->timer;
  int v1996 = v1978 + 1;
  v1977->timer = v1996;
  struct StateT * v1980 = v1967->a;
  int * v1981 = v1980->regs;
  int v1982 = v1981[8];
  int v2000 = v1982 + 1;
  v1981[8] = v2000;
  struct StateT * v1984 = v1967->b;
  int * v1985 = v1984->regs;
  int v1986 = v1985[8];
  int v2003 = v1986 + 1;
  v1985[8] = v2003;
  struct StateT2 * v1988 = slot_23(v1967);
  return v1988;
}

struct StateT2 * slot_139(struct StateT2 * v6530) {
  struct StateT * v6531 = v6530->a;
  int v6532 = v6531->timer;
  struct StateT * v6533 = v6530->b;
  int v6534 = v6533->timer;
  bool v6555 = v6532 == v6534;
  squared_assert(v6555);
  squared_assume(v6555);
  struct StateT * v6537 = v6530->a;
  int v6538 = v6537->timer;
  int v6557 = v6538 + 1;
  v6537->timer = v6557;
  struct StateT * v6540 = v6530->b;
  int v6541 = v6540->timer;
  int v6559 = v6541 + 1;
  v6540->timer = v6559;
  struct StateT * v6543 = v6530->a;
  int * v6544 = v6543->regs;
  int v6545 = v6544[8];
  int v6563 = v6545 + 1;
  v6544[8] = v6563;
  struct StateT * v6547 = v6530->b;
  int * v6548 = v6547->regs;
  int v6549 = v6548[8];
  int v6566 = v6549 + 1;
  v6548[8] = v6566;
  struct StateT2 * v6551 = slot_140(v6530);
  return v6551;
}

struct StateT2 * slot_221(struct StateT2 * v9728) {
  struct StateT * v9729 = v9728->a;
  int v9730 = v9729->timer;
  struct StateT * v9731 = v9728->b;
  int v9732 = v9731->timer;
  bool v9753 = v9730 == v9732;
  squared_assert(v9753);
  squared_assume(v9753);
  struct StateT * v9735 = v9728->a;
  int v9736 = v9735->timer;
  int v9755 = v9736 + 1;
  v9735->timer = v9755;
  struct StateT * v9738 = v9728->b;
  int v9739 = v9738->timer;
  int v9757 = v9739 + 1;
  v9738->timer = v9757;
  struct StateT * v9741 = v9728->a;
  int * v9742 = v9741->regs;
  int v9743 = v9742[8];
  int v9761 = v9743 + 1;
  v9742[8] = v9761;
  struct StateT * v9745 = v9728->b;
  int * v9746 = v9745->regs;
  int v9747 = v9746[8];
  int v9764 = v9747 + 1;
  v9746[8] = v9764;
  struct StateT2 * v9749 = slot_222(v9728);
  return v9749;
}

struct StateT2 * slot_23(struct StateT2 * v2006) {
  struct StateT * v2007 = v2006->a;
  int v2008 = v2007->timer;
  struct StateT * v2009 = v2006->b;
  int v2010 = v2009->timer;
  bool v2031 = v2008 == v2010;
  squared_assert(v2031);
  squared_assume(v2031);
  struct StateT * v2013 = v2006->a;
  int v2014 = v2013->timer;
  int v2033 = v2014 + 1;
  v2013->timer = v2033;
  struct StateT * v2016 = v2006->b;
  int v2017 = v2016->timer;
  int v2035 = v2017 + 1;
  v2016->timer = v2035;
  struct StateT * v2019 = v2006->a;
  int * v2020 = v2019->regs;
  int v2021 = v2020[8];
  int v2039 = v2021 + 1;
  v2020[8] = v2039;
  struct StateT * v2023 = v2006->b;
  int * v2024 = v2023->regs;
  int v2025 = v2024[8];
  int v2042 = v2025 + 1;
  v2024[8] = v2042;
  struct StateT2 * v2027 = slot_24(v2006);
  return v2027;
}

struct StateT2 * slot_153(struct StateT2 * v7076) {
  struct StateT * v7077 = v7076->a;
  int v7078 = v7077->timer;
  struct StateT * v7079 = v7076->b;
  int v7080 = v7079->timer;
  bool v7101 = v7078 == v7080;
  squared_assert(v7101);
  squared_assume(v7101);
  struct StateT * v7083 = v7076->a;
  int v7084 = v7083->timer;
  int v7103 = v7084 + 1;
  v7083->timer = v7103;
  struct StateT * v7086 = v7076->b;
  int v7087 = v7086->timer;
  int v7105 = v7087 + 1;
  v7086->timer = v7105;
  struct StateT * v7089 = v7076->a;
  int * v7090 = v7089->regs;
  int v7091 = v7090[8];
  int v7109 = v7091 + 1;
  v7090[8] = v7109;
  struct StateT * v7093 = v7076->b;
  int * v7094 = v7093->regs;
  int v7095 = v7094[8];
  int v7112 = v7095 + 1;
  v7094[8] = v7112;
  struct StateT2 * v7097 = slot_154(v7076);
  return v7097;
}

struct StateT2 * slot_2(struct StateT2 * v811) {
  struct StateT * v812 = v811->a;
  int v813 = v812->timer;
  struct StateT * v814 = v811->b;
  int v815 = v814->timer;
  bool v836 = v813 == v815;
  squared_assert(v836);
  squared_assume(v836);
  struct StateT * v818 = v811->a;
  int v819 = v818->timer;
  int v838 = v819 + 1;
  v818->timer = v838;
  struct StateT * v821 = v811->b;
  int v822 = v821->timer;
  int v840 = v822 + 1;
  v821->timer = v840;
  struct StateT * v824 = v811->a;
  int * v825 = v824->regs;
  int v826 = v825[6];
  int v844 = v826 & 7;
  v825[6] = v844;
  struct StateT * v828 = v811->b;
  int * v829 = v828->regs;
  int v830 = v829[6];
  int v847 = v830 & 7;
  v829[6] = v847;
  struct StateT2 * v832 = slot_3(v811);
  return v832;
}

struct StateT2 * slot_86(struct StateT2 * v4463) {
  struct StateT * v4464 = v4463->a;
  int v4465 = v4464->timer;
  struct StateT * v4466 = v4463->b;
  int v4467 = v4466->timer;
  bool v4488 = v4465 == v4467;
  squared_assert(v4488);
  squared_assume(v4488);
  struct StateT * v4470 = v4463->a;
  int v4471 = v4470->timer;
  int v4490 = v4471 + 1;
  v4470->timer = v4490;
  struct StateT * v4473 = v4463->b;
  int v4474 = v4473->timer;
  int v4492 = v4474 + 1;
  v4473->timer = v4492;
  struct StateT * v4476 = v4463->a;
  int * v4477 = v4476->regs;
  int v4478 = v4477[8];
  int v4496 = v4478 + 1;
  v4477[8] = v4496;
  struct StateT * v4480 = v4463->b;
  int * v4481 = v4480->regs;
  int v4482 = v4481[8];
  int v4499 = v4482 + 1;
  v4481[8] = v4499;
  struct StateT2 * v4484 = slot_87(v4463);
  return v4484;
}

struct StateT2 * slot_129(struct StateT2 * v6140) {
  struct StateT * v6141 = v6140->a;
  int v6142 = v6141->timer;
  struct StateT * v6143 = v6140->b;
  int v6144 = v6143->timer;
  bool v6165 = v6142 == v6144;
  squared_assert(v6165);
  squared_assume(v6165);
  struct StateT * v6147 = v6140->a;
  int v6148 = v6147->timer;
  int v6167 = v6148 + 1;
  v6147->timer = v6167;
  struct StateT * v6150 = v6140->b;
  int v6151 = v6150->timer;
  int v6169 = v6151 + 1;
  v6150->timer = v6169;
  struct StateT * v6153 = v6140->a;
  int * v6154 = v6153->regs;
  int v6155 = v6154[8];
  int v6173 = v6155 + 1;
  v6154[8] = v6173;
  struct StateT * v6157 = v6140->b;
  int * v6158 = v6157->regs;
  int v6159 = v6158[8];
  int v6176 = v6159 + 1;
  v6158[8] = v6176;
  struct StateT2 * v6161 = slot_130(v6140);
  return v6161;
}

struct StateT2 * slot_158(struct StateT2 * v7271) {
  struct StateT * v7272 = v7271->a;
  int v7273 = v7272->timer;
  struct StateT * v7274 = v7271->b;
  int v7275 = v7274->timer;
  bool v7296 = v7273 == v7275;
  squared_assert(v7296);
  squared_assume(v7296);
  struct StateT * v7278 = v7271->a;
  int v7279 = v7278->timer;
  int v7298 = v7279 + 1;
  v7278->timer = v7298;
  struct StateT * v7281 = v7271->b;
  int v7282 = v7281->timer;
  int v7300 = v7282 + 1;
  v7281->timer = v7300;
  struct StateT * v7284 = v7271->a;
  int * v7285 = v7284->regs;
  int v7286 = v7285[8];
  int v7304 = v7286 + 1;
  v7285[8] = v7304;
  struct StateT * v7288 = v7271->b;
  int * v7289 = v7288->regs;
  int v7290 = v7289[8];
  int v7307 = v7290 + 1;
  v7289[8] = v7307;
  struct StateT2 * v7292 = slot_159(v7271);
  return v7292;
}

struct StateT2 * slot_100(struct StateT2 * v5009) {
  struct StateT * v5010 = v5009->a;
  int v5011 = v5010->timer;
  struct StateT * v5012 = v5009->b;
  int v5013 = v5012->timer;
  bool v5034 = v5011 == v5013;
  squared_assert(v5034);
  squared_assume(v5034);
  struct StateT * v5016 = v5009->a;
  int v5017 = v5016->timer;
  int v5036 = v5017 + 1;
  v5016->timer = v5036;
  struct StateT * v5019 = v5009->b;
  int v5020 = v5019->timer;
  int v5038 = v5020 + 1;
  v5019->timer = v5038;
  struct StateT * v5022 = v5009->a;
  int * v5023 = v5022->regs;
  int v5024 = v5023[8];
  int v5042 = v5024 + 1;
  v5023[8] = v5042;
  struct StateT * v5026 = v5009->b;
  int * v5027 = v5026->regs;
  int v5028 = v5027[8];
  int v5045 = v5028 + 1;
  v5027[8] = v5045;
  struct StateT2 * v5030 = slot_101(v5009);
  return v5030;
}

struct StateT2 * slot_127(struct StateT2 * v6062) {
  struct StateT * v6063 = v6062->a;
  int v6064 = v6063->timer;
  struct StateT * v6065 = v6062->b;
  int v6066 = v6065->timer;
  bool v6087 = v6064 == v6066;
  squared_assert(v6087);
  squared_assume(v6087);
  struct StateT * v6069 = v6062->a;
  int v6070 = v6069->timer;
  int v6089 = v6070 + 1;
  v6069->timer = v6089;
  struct StateT * v6072 = v6062->b;
  int v6073 = v6072->timer;
  int v6091 = v6073 + 1;
  v6072->timer = v6091;
  struct StateT * v6075 = v6062->a;
  int * v6076 = v6075->regs;
  int v6077 = v6076[8];
  int v6095 = v6077 + 1;
  v6076[8] = v6095;
  struct StateT * v6079 = v6062->b;
  int * v6080 = v6079->regs;
  int v6081 = v6080[8];
  int v6098 = v6081 + 1;
  v6080[8] = v6098;
  struct StateT2 * v6083 = slot_128(v6062);
  return v6083;
}

struct StateT2 * slot_217(struct StateT2 * v9572) {
  struct StateT * v9573 = v9572->a;
  int v9574 = v9573->timer;
  struct StateT * v9575 = v9572->b;
  int v9576 = v9575->timer;
  bool v9597 = v9574 == v9576;
  squared_assert(v9597);
  squared_assume(v9597);
  struct StateT * v9579 = v9572->a;
  int v9580 = v9579->timer;
  int v9599 = v9580 + 1;
  v9579->timer = v9599;
  struct StateT * v9582 = v9572->b;
  int v9583 = v9582->timer;
  int v9601 = v9583 + 1;
  v9582->timer = v9601;
  struct StateT * v9585 = v9572->a;
  int * v9586 = v9585->regs;
  int v9587 = v9586[8];
  int v9605 = v9587 + 1;
  v9586[8] = v9605;
  struct StateT * v9589 = v9572->b;
  int * v9590 = v9589->regs;
  int v9591 = v9590[8];
  int v9608 = v9591 + 1;
  v9590[8] = v9608;
  struct StateT2 * v9593 = slot_218(v9572);
  return v9593;
}

struct StateT2 * slot_13(struct StateT2 * v1616) {
  struct StateT * v1617 = v1616->a;
  int v1618 = v1617->timer;
  struct StateT * v1619 = v1616->b;
  int v1620 = v1619->timer;
  bool v1641 = v1618 == v1620;
  squared_assert(v1641);
  squared_assume(v1641);
  struct StateT * v1623 = v1616->a;
  int v1624 = v1623->timer;
  int v1643 = v1624 + 1;
  v1623->timer = v1643;
  struct StateT * v1626 = v1616->b;
  int v1627 = v1626->timer;
  int v1645 = v1627 + 1;
  v1626->timer = v1645;
  struct StateT * v1629 = v1616->a;
  int * v1630 = v1629->regs;
  int v1631 = v1630[8];
  int v1649 = v1631 + 1;
  v1630[8] = v1649;
  struct StateT * v1633 = v1616->b;
  int * v1634 = v1633->regs;
  int v1635 = v1634[8];
  int v1652 = v1635 + 1;
  v1634[8] = v1652;
  struct StateT2 * v1637 = slot_14(v1616);
  return v1637;
}

struct StateT2 * slot_111(struct StateT2 * v5438) {
  struct StateT * v5439 = v5438->a;
  int v5440 = v5439->timer;
  struct StateT * v5441 = v5438->b;
  int v5442 = v5441->timer;
  bool v5463 = v5440 == v5442;
  squared_assert(v5463);
  squared_assume(v5463);
  struct StateT * v5445 = v5438->a;
  int v5446 = v5445->timer;
  int v5465 = v5446 + 1;
  v5445->timer = v5465;
  struct StateT * v5448 = v5438->b;
  int v5449 = v5448->timer;
  int v5467 = v5449 + 1;
  v5448->timer = v5467;
  struct StateT * v5451 = v5438->a;
  int * v5452 = v5451->regs;
  int v5453 = v5452[8];
  int v5471 = v5453 + 1;
  v5452[8] = v5471;
  struct StateT * v5455 = v5438->b;
  int * v5456 = v5455->regs;
  int v5457 = v5456[8];
  int v5474 = v5457 + 1;
  v5456[8] = v5474;
  struct StateT2 * v5459 = slot_112(v5438);
  return v5459;
}

struct StateT2 * slot_109(struct StateT2 * v5360) {
  struct StateT * v5361 = v5360->a;
  int v5362 = v5361->timer;
  struct StateT * v5363 = v5360->b;
  int v5364 = v5363->timer;
  bool v5385 = v5362 == v5364;
  squared_assert(v5385);
  squared_assume(v5385);
  struct StateT * v5367 = v5360->a;
  int v5368 = v5367->timer;
  int v5387 = v5368 + 1;
  v5367->timer = v5387;
  struct StateT * v5370 = v5360->b;
  int v5371 = v5370->timer;
  int v5389 = v5371 + 1;
  v5370->timer = v5389;
  struct StateT * v5373 = v5360->a;
  int * v5374 = v5373->regs;
  int v5375 = v5374[8];
  int v5393 = v5375 + 1;
  v5374[8] = v5393;
  struct StateT * v5377 = v5360->b;
  int * v5378 = v5377->regs;
  int v5379 = v5378[8];
  int v5396 = v5379 + 1;
  v5378[8] = v5396;
  struct StateT2 * v5381 = slot_110(v5360);
  return v5381;
}

struct StateT2 * slot_174(struct StateT2 * v7895) {
  struct StateT * v7896 = v7895->a;
  int v7897 = v7896->timer;
  struct StateT * v7898 = v7895->b;
  int v7899 = v7898->timer;
  bool v7920 = v7897 == v7899;
  squared_assert(v7920);
  squared_assume(v7920);
  struct StateT * v7902 = v7895->a;
  int v7903 = v7902->timer;
  int v7922 = v7903 + 1;
  v7902->timer = v7922;
  struct StateT * v7905 = v7895->b;
  int v7906 = v7905->timer;
  int v7924 = v7906 + 1;
  v7905->timer = v7924;
  struct StateT * v7908 = v7895->a;
  int * v7909 = v7908->regs;
  int v7910 = v7909[8];
  int v7928 = v7910 + 1;
  v7909[8] = v7928;
  struct StateT * v7912 = v7895->b;
  int * v7913 = v7912->regs;
  int v7914 = v7913[8];
  int v7931 = v7914 + 1;
  v7913[8] = v7931;
  struct StateT2 * v7916 = slot_175(v7895);
  return v7916;
}

struct StateT2 * slot_147(struct StateT2 * v6842) {
  struct StateT * v6843 = v6842->a;
  int v6844 = v6843->timer;
  struct StateT * v6845 = v6842->b;
  int v6846 = v6845->timer;
  bool v6867 = v6844 == v6846;
  squared_assert(v6867);
  squared_assume(v6867);
  struct StateT * v6849 = v6842->a;
  int v6850 = v6849->timer;
  int v6869 = v6850 + 1;
  v6849->timer = v6869;
  struct StateT * v6852 = v6842->b;
  int v6853 = v6852->timer;
  int v6871 = v6853 + 1;
  v6852->timer = v6871;
  struct StateT * v6855 = v6842->a;
  int * v6856 = v6855->regs;
  int v6857 = v6856[8];
  int v6875 = v6857 + 1;
  v6856[8] = v6875;
  struct StateT * v6859 = v6842->b;
  int * v6860 = v6859->regs;
  int v6861 = v6860[8];
  int v6878 = v6861 + 1;
  v6860[8] = v6878;
  struct StateT2 * v6863 = slot_148(v6842);
  return v6863;
}

struct StateT2 * slot_42(struct StateT2 * v2747) {
  struct StateT * v2748 = v2747->a;
  int v2749 = v2748->timer;
  struct StateT * v2750 = v2747->b;
  int v2751 = v2750->timer;
  bool v2772 = v2749 == v2751;
  squared_assert(v2772);
  squared_assume(v2772);
  struct StateT * v2754 = v2747->a;
  int v2755 = v2754->timer;
  int v2774 = v2755 + 1;
  v2754->timer = v2774;
  struct StateT * v2757 = v2747->b;
  int v2758 = v2757->timer;
  int v2776 = v2758 + 1;
  v2757->timer = v2776;
  struct StateT * v2760 = v2747->a;
  int * v2761 = v2760->regs;
  int v2762 = v2761[8];
  int v2780 = v2762 + 1;
  v2761[8] = v2780;
  struct StateT * v2764 = v2747->b;
  int * v2765 = v2764->regs;
  int v2766 = v2765[8];
  int v2783 = v2766 + 1;
  v2765[8] = v2783;
  struct StateT2 * v2768 = slot_43(v2747);
  return v2768;
}

struct StateT2 * slot_224(struct StateT2 * v9845) {
  struct StateT * v9846 = v9845->a;
  int v9847 = v9846->timer;
  struct StateT * v9848 = v9845->b;
  int v9849 = v9848->timer;
  bool v9870 = v9847 == v9849;
  squared_assert(v9870);
  squared_assume(v9870);
  struct StateT * v9852 = v9845->a;
  int v9853 = v9852->timer;
  int v9872 = v9853 + 1;
  v9852->timer = v9872;
  struct StateT * v9855 = v9845->b;
  int v9856 = v9855->timer;
  int v9874 = v9856 + 1;
  v9855->timer = v9874;
  struct StateT * v9858 = v9845->a;
  int * v9859 = v9858->regs;
  int v9860 = v9859[8];
  int v9878 = v9860 + 1;
  v9859[8] = v9878;
  struct StateT * v9862 = v9845->b;
  int * v9863 = v9862->regs;
  int v9864 = v9863[8];
  int v9881 = v9864 + 1;
  v9863[8] = v9881;
  struct StateT2 * v9866 = slot_225(v9845);
  return v9866;
}

struct StateT2 * slot_163(struct StateT2 * v7466) {
  struct StateT * v7467 = v7466->a;
  int v7468 = v7467->timer;
  struct StateT * v7469 = v7466->b;
  int v7470 = v7469->timer;
  bool v7491 = v7468 == v7470;
  squared_assert(v7491);
  squared_assume(v7491);
  struct StateT * v7473 = v7466->a;
  int v7474 = v7473->timer;
  int v7493 = v7474 + 1;
  v7473->timer = v7493;
  struct StateT * v7476 = v7466->b;
  int v7477 = v7476->timer;
  int v7495 = v7477 + 1;
  v7476->timer = v7495;
  struct StateT * v7479 = v7466->a;
  int * v7480 = v7479->regs;
  int v7481 = v7480[8];
  int v7499 = v7481 + 1;
  v7480[8] = v7499;
  struct StateT * v7483 = v7466->b;
  int * v7484 = v7483->regs;
  int v7485 = v7484[8];
  int v7502 = v7485 + 1;
  v7484[8] = v7502;
  struct StateT2 * v7487 = slot_164(v7466);
  return v7487;
}

struct StateT2 * slot_184(struct StateT2 * v8285) {
  struct StateT * v8286 = v8285->a;
  int v8287 = v8286->timer;
  struct StateT * v8288 = v8285->b;
  int v8289 = v8288->timer;
  bool v8310 = v8287 == v8289;
  squared_assert(v8310);
  squared_assume(v8310);
  struct StateT * v8292 = v8285->a;
  int v8293 = v8292->timer;
  int v8312 = v8293 + 1;
  v8292->timer = v8312;
  struct StateT * v8295 = v8285->b;
  int v8296 = v8295->timer;
  int v8314 = v8296 + 1;
  v8295->timer = v8314;
  struct StateT * v8298 = v8285->a;
  int * v8299 = v8298->regs;
  int v8300 = v8299[8];
  int v8318 = v8300 + 1;
  v8299[8] = v8318;
  struct StateT * v8302 = v8285->b;
  int * v8303 = v8302->regs;
  int v8304 = v8303[8];
  int v8321 = v8304 + 1;
  v8303[8] = v8321;
  struct StateT2 * v8306 = slot_185(v8285);
  return v8306;
}

struct StateT2 * slot_204(struct StateT2 * v9065) {
  struct StateT * v9066 = v9065->a;
  int v9067 = v9066->timer;
  struct StateT * v9068 = v9065->b;
  int v9069 = v9068->timer;
  bool v9090 = v9067 == v9069;
  squared_assert(v9090);
  squared_assume(v9090);
  struct StateT * v9072 = v9065->a;
  int v9073 = v9072->timer;
  int v9092 = v9073 + 1;
  v9072->timer = v9092;
  struct StateT * v9075 = v9065->b;
  int v9076 = v9075->timer;
  int v9094 = v9076 + 1;
  v9075->timer = v9094;
  struct StateT * v9078 = v9065->a;
  int * v9079 = v9078->regs;
  int v9080 = v9079[8];
  int v9098 = v9080 + 1;
  v9079[8] = v9098;
  struct StateT * v9082 = v9065->b;
  int * v9083 = v9082->regs;
  int v9084 = v9083[8];
  int v9101 = v9084 + 1;
  v9083[8] = v9101;
  struct StateT2 * v9086 = slot_205(v9065);
  return v9086;
}

struct StateT2 * slot_194(struct StateT2 * v8675) {
  struct StateT * v8676 = v8675->a;
  int v8677 = v8676->timer;
  struct StateT * v8678 = v8675->b;
  int v8679 = v8678->timer;
  bool v8700 = v8677 == v8679;
  squared_assert(v8700);
  squared_assume(v8700);
  struct StateT * v8682 = v8675->a;
  int v8683 = v8682->timer;
  int v8702 = v8683 + 1;
  v8682->timer = v8702;
  struct StateT * v8685 = v8675->b;
  int v8686 = v8685->timer;
  int v8704 = v8686 + 1;
  v8685->timer = v8704;
  struct StateT * v8688 = v8675->a;
  int * v8689 = v8688->regs;
  int v8690 = v8689[8];
  int v8708 = v8690 + 1;
  v8689[8] = v8708;
  struct StateT * v8692 = v8675->b;
  int * v8693 = v8692->regs;
  int v8694 = v8693[8];
  int v8711 = v8694 + 1;
  v8693[8] = v8711;
  struct StateT2 * v8696 = slot_195(v8675);
  return v8696;
}

struct StateT2 * slot_165(struct StateT2 * v7544) {
  struct StateT * v7545 = v7544->a;
  int v7546 = v7545->timer;
  struct StateT * v7547 = v7544->b;
  int v7548 = v7547->timer;
  bool v7569 = v7546 == v7548;
  squared_assert(v7569);
  squared_assume(v7569);
  struct StateT * v7551 = v7544->a;
  int v7552 = v7551->timer;
  int v7571 = v7552 + 1;
  v7551->timer = v7571;
  struct StateT * v7554 = v7544->b;
  int v7555 = v7554->timer;
  int v7573 = v7555 + 1;
  v7554->timer = v7573;
  struct StateT * v7557 = v7544->a;
  int * v7558 = v7557->regs;
  int v7559 = v7558[8];
  int v7577 = v7559 + 1;
  v7558[8] = v7577;
  struct StateT * v7561 = v7544->b;
  int * v7562 = v7561->regs;
  int v7563 = v7562[8];
  int v7580 = v7563 + 1;
  v7562[8] = v7580;
  struct StateT2 * v7565 = slot_166(v7544);
  return v7565;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_117(struct StateT2 * v5672) {
  struct StateT * v5673 = v5672->a;
  int v5674 = v5673->timer;
  struct StateT * v5675 = v5672->b;
  int v5676 = v5675->timer;
  bool v5697 = v5674 == v5676;
  squared_assert(v5697);
  squared_assume(v5697);
  struct StateT * v5679 = v5672->a;
  int v5680 = v5679->timer;
  int v5699 = v5680 + 1;
  v5679->timer = v5699;
  struct StateT * v5682 = v5672->b;
  int v5683 = v5682->timer;
  int v5701 = v5683 + 1;
  v5682->timer = v5701;
  struct StateT * v5685 = v5672->a;
  int * v5686 = v5685->regs;
  int v5687 = v5686[8];
  int v5705 = v5687 + 1;
  v5686[8] = v5705;
  struct StateT * v5689 = v5672->b;
  int * v5690 = v5689->regs;
  int v5691 = v5690[8];
  int v5708 = v5691 + 1;
  v5690[8] = v5708;
  struct StateT2 * v5693 = slot_118(v5672);
  return v5693;
}

struct StateT2 * slot_90(struct StateT2 * v4619) {
  struct StateT * v4620 = v4619->a;
  int v4621 = v4620->timer;
  struct StateT * v4622 = v4619->b;
  int v4623 = v4622->timer;
  bool v4644 = v4621 == v4623;
  squared_assert(v4644);
  squared_assume(v4644);
  struct StateT * v4626 = v4619->a;
  int v4627 = v4626->timer;
  int v4646 = v4627 + 1;
  v4626->timer = v4646;
  struct StateT * v4629 = v4619->b;
  int v4630 = v4629->timer;
  int v4648 = v4630 + 1;
  v4629->timer = v4648;
  struct StateT * v4632 = v4619->a;
  int * v4633 = v4632->regs;
  int v4634 = v4633[8];
  int v4652 = v4634 + 1;
  v4633[8] = v4652;
  struct StateT * v4636 = v4619->b;
  int * v4637 = v4636->regs;
  int v4638 = v4637[8];
  int v4655 = v4638 + 1;
  v4637[8] = v4655;
  struct StateT2 * v4640 = slot_91(v4619);
  return v4640;
}

struct StateT2 * slot_11(struct StateT2 * v1538) {
  struct StateT * v1539 = v1538->a;
  int v1540 = v1539->timer;
  struct StateT * v1541 = v1538->b;
  int v1542 = v1541->timer;
  bool v1563 = v1540 == v1542;
  squared_assert(v1563);
  squared_assume(v1563);
  struct StateT * v1545 = v1538->a;
  int v1546 = v1545->timer;
  int v1565 = v1546 + 1;
  v1545->timer = v1565;
  struct StateT * v1548 = v1538->b;
  int v1549 = v1548->timer;
  int v1567 = v1549 + 1;
  v1548->timer = v1567;
  struct StateT * v1551 = v1538->a;
  int * v1552 = v1551->regs;
  int v1553 = v1552[8];
  int v1571 = v1553 + 1;
  v1552[8] = v1571;
  struct StateT * v1555 = v1538->b;
  int * v1556 = v1555->regs;
  int v1557 = v1556[8];
  int v1574 = v1557 + 1;
  v1556[8] = v1574;
  struct StateT2 * v1559 = slot_12(v1538);
  return v1559;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}