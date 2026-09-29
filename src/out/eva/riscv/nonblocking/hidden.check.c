// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * slot_12(struct StateT * v795);
struct StateT * slot_143(struct StateT * v3546);
struct StateT * slot_120(struct StateT * v3063);
struct StateT * slot_167(struct StateT * v4050);
struct StateT * slot_152(struct StateT * v3735);
struct StateT * slot_199(struct StateT * v4722);
struct StateT * slot_92(struct StateT * v2475);
struct StateT * slot_31(struct StateT * v1194);
struct StateT * slot_160(struct StateT * v3903);
struct StateT * slot_65(struct StateT * v1908);
struct StateT * slot_10(struct StateT * v753);
struct StateT * slot_150(struct StateT * v3693);
struct StateT * slot_74(struct StateT * v2097);
struct StateT * slot_107(struct StateT * v2790);
struct StateT * slot_136(struct StateT * v3399);
struct StateT * slot_84(struct StateT * v2307);
struct StateT * slot_28(struct StateT * v1131);
struct StateT * slot_155(struct StateT * v3798);
struct StateT * slot_177(struct StateT * v4260);
struct StateT * slot_17(struct StateT * v900);
struct StateT * slot_181(struct StateT * v4344);
struct StateT * slot_197(struct StateT * v4680);
struct StateT * slot_207(struct StateT * v4890);
struct StateT * slot_156(struct StateT * v3819);
struct StateT * slot_154(struct StateT * v3777);
struct StateT * slot_68(struct StateT * v1971);
struct StateT * slot_105(struct StateT * v2748);
struct StateT * slot_27(struct StateT * v1110);
struct StateT * slot_164(struct StateT * v3987);
struct StateT * slot_15(struct StateT * v858);
struct StateT * slot_133(struct StateT * v3336);
struct StateT * slot_56(struct StateT * v1719);
struct StateT * slot_222(struct StateT * v5205);
struct StateT * slot_34(struct StateT * v1257);
struct StateT * slot_171(struct StateT * v4134);
struct StateT * slot_162(struct StateT * v3945);
struct StateT * slot_21(struct StateT * v984);
struct StateT * slot_118(struct StateT * v3021);
struct StateT * slot_121(struct StateT * v3084);
struct StateT * slot_144(struct StateT * v3567);
struct StateT * slot_201(struct StateT * v4764);
struct StateT * slot_94(struct StateT * v2517);
struct StateT * slot_63(struct StateT * v1866);
struct StateT * slot_146(struct StateT * v3609);
struct StateT * slot_24(struct StateT * v1047);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v4638);
struct StateT * slot_125(struct StateT * v3168);
struct StateT * slot_148(struct StateT * v3651);
struct StateT * slot_126(struct StateT * v3189);
struct StateT * slot_223(struct StateT * v5226);
struct StateT * slot_79(struct StateT * v2202);
struct StateT * slot_41(struct StateT * v1404);
struct StateT * slot_39(struct StateT * v1362);
struct StateT * slot_142(struct StateT * v3525);
struct StateT * slot_60(struct StateT * v1803);
struct StateT * slot_112(struct StateT * v2895);
struct StateT * slot_47(struct StateT * v1530);
struct StateT * slot_214(struct StateT * v5037);
struct StateT * slot_29(struct StateT * v1152);
struct StateT * slot_16(struct StateT * v879);
struct StateT * slot_113(struct StateT * v2916);
struct StateT * slot_151(struct StateT * v3714);
struct StateT * slot_7(struct StateT * v690);
struct StateT * slot_124(struct StateT * v3147);
struct StateT * slot_191(struct StateT * v4554);
struct StateT * slot_103(struct StateT * v2706);
struct StateT * slot_128(struct StateT * v3231);
struct StateT * slot_19(struct StateT * v942);
struct StateT * slot_87(struct StateT * v2370);
struct StateT * slot_67(struct StateT * v1950);
struct StateT * slot_81(struct StateT * v2244);
struct StateT * slot_95(struct StateT * v2538);
struct StateT * slot_115(struct StateT * v2958);
struct StateT * slot_78(struct StateT * v2181);
struct StateT * slot_32(struct StateT * v1215);
struct StateT * slot_205(struct StateT * v4848);
struct StateT * slot_193(struct StateT * v4596);
struct StateT * slot_176(struct StateT * v4239);
struct StateT * slot_189(struct StateT * v4512);
struct StateT * slot_33(struct StateT * v1236);
struct StateT * slot_35(struct StateT * v1278);
struct StateT * slot_210(struct StateT * v4953);
struct StateT * slot_166(struct StateT * v4029);
struct StateT * slot_51(struct StateT * v1614);
struct StateT * slot_52(struct StateT * v1635);
struct StateT * slot_83(struct StateT * v2286);
struct StateT * slot_25(struct StateT * v1068);
struct StateT * slot_209(struct StateT * v4932);
struct StateT * slot_3(struct StateT * v424);
struct StateT * slot_123(struct StateT * v3126);
struct StateT * slot_73(struct StateT * v2076);
struct StateT * slot_198(struct StateT * v4701);
struct StateT * slot_1(struct StateT * v210);
struct StateT * slot_187(struct StateT * v4470);
struct StateT * slot_97(struct StateT * v2580);
struct StateT * slot_182(struct StateT * v4365);
struct StateT * slot_38(struct StateT * v1341);
struct StateT * slot_178(struct StateT * v4281);
struct StateT * slot_106(struct StateT * v2769);
struct StateT * slot_98(struct StateT * v2601);
struct StateT * slot_159(struct StateT * v3882);
struct StateT * slot_46(struct StateT * v1509);
struct StateT * slot_212(struct StateT * v4995);
struct StateT * slot_132(struct StateT * v3315);
struct StateT * slot_130(struct StateT * v3273);
struct StateT * slot_211(struct StateT * v4974);
struct StateT * slot_20(struct StateT * v963);
struct StateT * slot_141(struct StateT * v3504);
struct StateT * slot_61(struct StateT * v1824);
struct StateT * slot_30(struct StateT * v1173);
struct StateT * slot_4(struct StateT * v445);
struct StateT * slot_18(struct StateT * v921);
struct StateT * slot_9(struct StateT * v732);
struct StateT * slot_183(struct StateT * v4386);
struct StateT * slot_43(struct StateT * v1446);
struct StateT * slot_70(struct StateT * v2013);
struct StateT * slot_168(struct StateT * v4071);
struct StateT * slot_76(struct StateT * v2139);
struct StateT * slot_6(struct StateT * v669);
struct StateT * slot_225(struct StateT * v5268);
struct StateT * slot_55(struct StateT * v1698);
struct StateT * slot_213(struct StateT * v5016);
struct StateT * slot_82(struct StateT * v2265);
struct StateT * slot_161(struct StateT * v3924);
struct StateT * slot_185(struct StateT * v4428);
struct StateT * slot_91(struct StateT * v2454);
struct StateT * slot_58(struct StateT * v1761);
struct StateT * slot_89(struct StateT * v2412);
struct StateT * slot_66(struct StateT * v1929);
struct StateT * slot_140(struct StateT * v3483);
struct StateT * slot_49(struct StateT * v1572);
struct StateT * slot_216(struct StateT * v5079);
struct StateT * slot_50(struct StateT * v1593);
struct StateT * slot_37(struct StateT * v1320);
struct StateT * slot_114(struct StateT * v2937);
struct StateT * slot_135(struct StateT * v3378);
struct StateT * slot_59(struct StateT * v1782);
struct StateT * slot_192(struct StateT * v4575);
struct StateT * slot_40(struct StateT * v1383);
struct StateT * slot_48(struct StateT * v1551);
struct StateT * slot_77(struct StateT * v2160);
struct StateT * slot_85(struct StateT * v2328);
struct StateT * slot_75(struct StateT * v2118);
struct StateT * slot_72(struct StateT * v2055);
struct StateT * slot_119(struct StateT * v3042);
struct StateT * slot_71(struct StateT * v2034);
struct StateT * slot_101(struct StateT * v2664);
struct StateT * slot_108(struct StateT * v2811);
struct StateT * slot_116(struct StateT * v2979);
struct StateT * slot_93(struct StateT * v2496);
struct StateT * slot_88(struct StateT * v2391);
struct StateT * slot_96(struct StateT * v2559);
struct StateT * slot_215(struct StateT * v5058);
struct StateT * slot_45(struct StateT * v1488);
struct StateT * slot_218(struct StateT * v5121);
struct StateT * slot_220(struct StateT * v5163);
struct StateT * slot_134(struct StateT * v3357);
struct StateT * slot_175(struct StateT * v4218);
struct StateT * slot_69(struct StateT * v1992);
struct StateT * slot_202(struct StateT * v4785);
struct StateT * slot_188(struct StateT * v4491);
struct StateT * slot_138(struct StateT * v3441);
struct StateT * slot_186(struct StateT * v4449);
struct StateT * slot_102(struct StateT * v2685);
struct StateT * slot_145(struct StateT * v3588);
struct StateT * slot_110(struct StateT * v2853);
struct StateT * slot_196(struct StateT * v4659);
struct StateT * slot_208(struct StateT * v4911);
struct StateT * slot_172(struct StateT * v4155);
struct StateT * slot_131(struct StateT * v3294);
struct StateT * slot_8(struct StateT * v711);
struct StateT * slot_180(struct StateT * v4323);
struct StateT * slot_203(struct StateT * v4806);
struct StateT * slot_190(struct StateT * v4533);
struct StateT * slot_157(struct StateT * v3840);
struct StateT * slot_200(struct StateT * v4743);
struct StateT * slot_173(struct StateT * v4176);
struct StateT * slot_149(struct StateT * v3672);
struct StateT * slot_5(struct StateT * v653);
struct StateT * slot_104(struct StateT * v2727);
struct StateT * slot_54(struct StateT * v1677);
struct StateT * slot_26(struct StateT * v1089);
struct StateT * slot_206(struct StateT * v4869);
struct StateT * slot_169(struct StateT * v4092);
struct StateT * slot_64(struct StateT * v1887);
struct StateT * slot_170(struct StateT * v4113);
struct StateT * slot_14(struct StateT * v837);
struct StateT * slot_53(struct StateT * v1656);
struct StateT * slot_80(struct StateT * v2223);
struct StateT * slot_44(struct StateT * v1467);
struct StateT * slot_137(struct StateT * v3420);
struct StateT * slot_122(struct StateT * v3105);
struct StateT * slot_99(struct StateT * v2622);
struct StateT * slot_179(struct StateT * v4302);
struct StateT * slot_219(struct StateT * v5142);
struct StateT * slot_36(struct StateT * v1299);
struct StateT * slot_57(struct StateT * v1740);
struct StateT * slot_62(struct StateT * v1845);
struct StateT * slot_22(struct StateT * v1005);
struct StateT * slot_139(struct StateT * v3462);
struct StateT * slot_221(struct StateT * v5184);
struct StateT * slot_23(struct StateT * v1026);
struct StateT * slot_153(struct StateT * v3756);
struct StateT * slot_2(struct StateT * v403);
struct StateT * slot_86(struct StateT * v2349);
struct StateT * slot_129(struct StateT * v3252);
struct StateT * slot_158(struct StateT * v3861);
struct StateT * slot_100(struct StateT * v2643);
struct StateT * slot_127(struct StateT * v3210);
struct StateT * slot_217(struct StateT * v5100);
struct StateT * slot_13(struct StateT * v816);
struct StateT * slot_111(struct StateT * v2874);
struct StateT * slot_109(struct StateT * v2832);
struct StateT * slot_174(struct StateT * v4197);
struct StateT * slot_147(struct StateT * v3630);
struct StateT * slot_42(struct StateT * v1425);
struct StateT * slot_224(struct StateT * v5247);
struct StateT * slot_163(struct StateT * v3966);
struct StateT * slot_184(struct StateT * v4407);
struct StateT * slot_204(struct StateT * v4827);
struct StateT * slot_194(struct StateT * v4617);
struct StateT * slot_165(struct StateT * v4008);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v3000);
struct StateT * slot_90(struct StateT * v2433);
struct StateT * slot_11(struct StateT * v774);
struct StateT * slot_12(struct StateT * v795) {
  int v796 = v795->timer;
  int v807 = v796 + 1;
  v795->timer = v807;
  int * v798 = v795->reg_ready;
  int v799 = v798[8];
  int * v800 = v795->regs;
  int v801 = v800[8];
  int v811 = (v799 + ((v796 - v799) & (~((v796 - v799) >> 31)))) + 1;
  v798[8] = v811;
  int * v803 = v795->regs;
  int v813 = v801 + 1;
  v803[8] = v813;
  struct StateT * v805 = slot_13(v795);
  return v805;
}

struct StateT * slot_143(struct StateT * v3546) {
  int v3547 = v3546->timer;
  int v3558 = v3547 + 1;
  v3546->timer = v3558;
  int * v3549 = v3546->reg_ready;
  int v3550 = v3549[8];
  int * v3551 = v3546->regs;
  int v3552 = v3551[8];
  int v3562 = (v3550 + ((v3547 - v3550) & (~((v3547 - v3550) >> 31)))) + 1;
  v3549[8] = v3562;
  int * v3554 = v3546->regs;
  int v3564 = v3552 + 1;
  v3554[8] = v3564;
  struct StateT * v3556 = slot_144(v3546);
  return v3556;
}

struct StateT * slot_120(struct StateT * v3063) {
  int v3064 = v3063->timer;
  int v3075 = v3064 + 1;
  v3063->timer = v3075;
  int * v3066 = v3063->reg_ready;
  int v3067 = v3066[8];
  int * v3068 = v3063->regs;
  int v3069 = v3068[8];
  int v3079 = (v3067 + ((v3064 - v3067) & (~((v3064 - v3067) >> 31)))) + 1;
  v3066[8] = v3079;
  int * v3071 = v3063->regs;
  int v3081 = v3069 + 1;
  v3071[8] = v3081;
  struct StateT * v3073 = slot_121(v3063);
  return v3073;
}

struct StateT * slot_167(struct StateT * v4050) {
  int v4051 = v4050->timer;
  int v4062 = v4051 + 1;
  v4050->timer = v4062;
  int * v4053 = v4050->reg_ready;
  int v4054 = v4053[8];
  int * v4055 = v4050->regs;
  int v4056 = v4055[8];
  int v4066 = (v4054 + ((v4051 - v4054) & (~((v4051 - v4054) >> 31)))) + 1;
  v4053[8] = v4066;
  int * v4058 = v4050->regs;
  int v4068 = v4056 + 1;
  v4058[8] = v4068;
  struct StateT * v4060 = slot_168(v4050);
  return v4060;
}

struct StateT * slot_152(struct StateT * v3735) {
  int v3736 = v3735->timer;
  int v3747 = v3736 + 1;
  v3735->timer = v3747;
  int * v3738 = v3735->reg_ready;
  int v3739 = v3738[8];
  int * v3740 = v3735->regs;
  int v3741 = v3740[8];
  int v3751 = (v3739 + ((v3736 - v3739) & (~((v3736 - v3739) >> 31)))) + 1;
  v3738[8] = v3751;
  int * v3743 = v3735->regs;
  int v3753 = v3741 + 1;
  v3743[8] = v3753;
  struct StateT * v3745 = slot_153(v3735);
  return v3745;
}

struct StateT * slot_199(struct StateT * v4722) {
  int v4723 = v4722->timer;
  int v4734 = v4723 + 1;
  v4722->timer = v4734;
  int * v4725 = v4722->reg_ready;
  int v4726 = v4725[8];
  int * v4727 = v4722->regs;
  int v4728 = v4727[8];
  int v4738 = (v4726 + ((v4723 - v4726) & (~((v4723 - v4726) >> 31)))) + 1;
  v4725[8] = v4738;
  int * v4730 = v4722->regs;
  int v4740 = v4728 + 1;
  v4730[8] = v4740;
  struct StateT * v4732 = slot_200(v4722);
  return v4732;
}

struct StateT * slot_92(struct StateT * v2475) {
  int v2476 = v2475->timer;
  int v2487 = v2476 + 1;
  v2475->timer = v2487;
  int * v2478 = v2475->reg_ready;
  int v2479 = v2478[8];
  int * v2480 = v2475->regs;
  int v2481 = v2480[8];
  int v2491 = (v2479 + ((v2476 - v2479) & (~((v2476 - v2479) >> 31)))) + 1;
  v2478[8] = v2491;
  int * v2483 = v2475->regs;
  int v2493 = v2481 + 1;
  v2483[8] = v2493;
  struct StateT * v2485 = slot_93(v2475);
  return v2485;
}

struct StateT * slot_31(struct StateT * v1194) {
  int v1195 = v1194->timer;
  int v1206 = v1195 + 1;
  v1194->timer = v1206;
  int * v1197 = v1194->reg_ready;
  int v1198 = v1197[8];
  int * v1199 = v1194->regs;
  int v1200 = v1199[8];
  int v1210 = (v1198 + ((v1195 - v1198) & (~((v1195 - v1198) >> 31)))) + 1;
  v1197[8] = v1210;
  int * v1202 = v1194->regs;
  int v1212 = v1200 + 1;
  v1202[8] = v1212;
  struct StateT * v1204 = slot_32(v1194);
  return v1204;
}

struct StateT * slot_160(struct StateT * v3903) {
  int v3904 = v3903->timer;
  int v3915 = v3904 + 1;
  v3903->timer = v3915;
  int * v3906 = v3903->reg_ready;
  int v3907 = v3906[8];
  int * v3908 = v3903->regs;
  int v3909 = v3908[8];
  int v3919 = (v3907 + ((v3904 - v3907) & (~((v3904 - v3907) >> 31)))) + 1;
  v3906[8] = v3919;
  int * v3911 = v3903->regs;
  int v3921 = v3909 + 1;
  v3911[8] = v3921;
  struct StateT * v3913 = slot_161(v3903);
  return v3913;
}

struct StateT * slot_65(struct StateT * v1908) {
  int v1909 = v1908->timer;
  int v1920 = v1909 + 1;
  v1908->timer = v1920;
  int * v1911 = v1908->reg_ready;
  int v1912 = v1911[8];
  int * v1913 = v1908->regs;
  int v1914 = v1913[8];
  int v1924 = (v1912 + ((v1909 - v1912) & (~((v1909 - v1912) >> 31)))) + 1;
  v1911[8] = v1924;
  int * v1916 = v1908->regs;
  int v1926 = v1914 + 1;
  v1916[8] = v1926;
  struct StateT * v1918 = slot_66(v1908);
  return v1918;
}

struct StateT * slot_10(struct StateT * v753) {
  int v754 = v753->timer;
  int v765 = v754 + 1;
  v753->timer = v765;
  int * v756 = v753->reg_ready;
  int v757 = v756[8];
  int * v758 = v753->regs;
  int v759 = v758[8];
  int v769 = (v757 + ((v754 - v757) & (~((v754 - v757) >> 31)))) + 1;
  v756[8] = v769;
  int * v761 = v753->regs;
  int v771 = v759 + 1;
  v761[8] = v771;
  struct StateT * v763 = slot_11(v753);
  return v763;
}

struct StateT * slot_150(struct StateT * v3693) {
  int v3694 = v3693->timer;
  int v3705 = v3694 + 1;
  v3693->timer = v3705;
  int * v3696 = v3693->reg_ready;
  int v3697 = v3696[8];
  int * v3698 = v3693->regs;
  int v3699 = v3698[8];
  int v3709 = (v3697 + ((v3694 - v3697) & (~((v3694 - v3697) >> 31)))) + 1;
  v3696[8] = v3709;
  int * v3701 = v3693->regs;
  int v3711 = v3699 + 1;
  v3701[8] = v3711;
  struct StateT * v3703 = slot_151(v3693);
  return v3703;
}

struct StateT * slot_74(struct StateT * v2097) {
  int v2098 = v2097->timer;
  int v2109 = v2098 + 1;
  v2097->timer = v2109;
  int * v2100 = v2097->reg_ready;
  int v2101 = v2100[8];
  int * v2102 = v2097->regs;
  int v2103 = v2102[8];
  int v2113 = (v2101 + ((v2098 - v2101) & (~((v2098 - v2101) >> 31)))) + 1;
  v2100[8] = v2113;
  int * v2105 = v2097->regs;
  int v2115 = v2103 + 1;
  v2105[8] = v2115;
  struct StateT * v2107 = slot_75(v2097);
  return v2107;
}

struct StateT * slot_107(struct StateT * v2790) {
  int v2791 = v2790->timer;
  int v2802 = v2791 + 1;
  v2790->timer = v2802;
  int * v2793 = v2790->reg_ready;
  int v2794 = v2793[8];
  int * v2795 = v2790->regs;
  int v2796 = v2795[8];
  int v2806 = (v2794 + ((v2791 - v2794) & (~((v2791 - v2794) >> 31)))) + 1;
  v2793[8] = v2806;
  int * v2798 = v2790->regs;
  int v2808 = v2796 + 1;
  v2798[8] = v2808;
  struct StateT * v2800 = slot_108(v2790);
  return v2800;
}

struct StateT * slot_136(struct StateT * v3399) {
  int v3400 = v3399->timer;
  int v3411 = v3400 + 1;
  v3399->timer = v3411;
  int * v3402 = v3399->reg_ready;
  int v3403 = v3402[8];
  int * v3404 = v3399->regs;
  int v3405 = v3404[8];
  int v3415 = (v3403 + ((v3400 - v3403) & (~((v3400 - v3403) >> 31)))) + 1;
  v3402[8] = v3415;
  int * v3407 = v3399->regs;
  int v3417 = v3405 + 1;
  v3407[8] = v3417;
  struct StateT * v3409 = slot_137(v3399);
  return v3409;
}

struct StateT * slot_84(struct StateT * v2307) {
  int v2308 = v2307->timer;
  int v2319 = v2308 + 1;
  v2307->timer = v2319;
  int * v2310 = v2307->reg_ready;
  int v2311 = v2310[8];
  int * v2312 = v2307->regs;
  int v2313 = v2312[8];
  int v2323 = (v2311 + ((v2308 - v2311) & (~((v2308 - v2311) >> 31)))) + 1;
  v2310[8] = v2323;
  int * v2315 = v2307->regs;
  int v2325 = v2313 + 1;
  v2315[8] = v2325;
  struct StateT * v2317 = slot_85(v2307);
  return v2317;
}

struct StateT * slot_28(struct StateT * v1131) {
  int v1132 = v1131->timer;
  int v1143 = v1132 + 1;
  v1131->timer = v1143;
  int * v1134 = v1131->reg_ready;
  int v1135 = v1134[8];
  int * v1136 = v1131->regs;
  int v1137 = v1136[8];
  int v1147 = (v1135 + ((v1132 - v1135) & (~((v1132 - v1135) >> 31)))) + 1;
  v1134[8] = v1147;
  int * v1139 = v1131->regs;
  int v1149 = v1137 + 1;
  v1139[8] = v1149;
  struct StateT * v1141 = slot_29(v1131);
  return v1141;
}

struct StateT * slot_155(struct StateT * v3798) {
  int v3799 = v3798->timer;
  int v3810 = v3799 + 1;
  v3798->timer = v3810;
  int * v3801 = v3798->reg_ready;
  int v3802 = v3801[8];
  int * v3803 = v3798->regs;
  int v3804 = v3803[8];
  int v3814 = (v3802 + ((v3799 - v3802) & (~((v3799 - v3802) >> 31)))) + 1;
  v3801[8] = v3814;
  int * v3806 = v3798->regs;
  int v3816 = v3804 + 1;
  v3806[8] = v3816;
  struct StateT * v3808 = slot_156(v3798);
  return v3808;
}

struct StateT * slot_177(struct StateT * v4260) {
  int v4261 = v4260->timer;
  int v4272 = v4261 + 1;
  v4260->timer = v4272;
  int * v4263 = v4260->reg_ready;
  int v4264 = v4263[8];
  int * v4265 = v4260->regs;
  int v4266 = v4265[8];
  int v4276 = (v4264 + ((v4261 - v4264) & (~((v4261 - v4264) >> 31)))) + 1;
  v4263[8] = v4276;
  int * v4268 = v4260->regs;
  int v4278 = v4266 + 1;
  v4268[8] = v4278;
  struct StateT * v4270 = slot_178(v4260);
  return v4270;
}

struct StateT * slot_17(struct StateT * v900) {
  int v901 = v900->timer;
  int v912 = v901 + 1;
  v900->timer = v912;
  int * v903 = v900->reg_ready;
  int v904 = v903[8];
  int * v905 = v900->regs;
  int v906 = v905[8];
  int v916 = (v904 + ((v901 - v904) & (~((v901 - v904) >> 31)))) + 1;
  v903[8] = v916;
  int * v908 = v900->regs;
  int v918 = v906 + 1;
  v908[8] = v918;
  struct StateT * v910 = slot_18(v900);
  return v910;
}

struct StateT * slot_181(struct StateT * v4344) {
  int v4345 = v4344->timer;
  int v4356 = v4345 + 1;
  v4344->timer = v4356;
  int * v4347 = v4344->reg_ready;
  int v4348 = v4347[8];
  int * v4349 = v4344->regs;
  int v4350 = v4349[8];
  int v4360 = (v4348 + ((v4345 - v4348) & (~((v4345 - v4348) >> 31)))) + 1;
  v4347[8] = v4360;
  int * v4352 = v4344->regs;
  int v4362 = v4350 + 1;
  v4352[8] = v4362;
  struct StateT * v4354 = slot_182(v4344);
  return v4354;
}

struct StateT * slot_197(struct StateT * v4680) {
  int v4681 = v4680->timer;
  int v4692 = v4681 + 1;
  v4680->timer = v4692;
  int * v4683 = v4680->reg_ready;
  int v4684 = v4683[8];
  int * v4685 = v4680->regs;
  int v4686 = v4685[8];
  int v4696 = (v4684 + ((v4681 - v4684) & (~((v4681 - v4684) >> 31)))) + 1;
  v4683[8] = v4696;
  int * v4688 = v4680->regs;
  int v4698 = v4686 + 1;
  v4688[8] = v4698;
  struct StateT * v4690 = slot_198(v4680);
  return v4690;
}

struct StateT * slot_207(struct StateT * v4890) {
  int v4891 = v4890->timer;
  int v4902 = v4891 + 1;
  v4890->timer = v4902;
  int * v4893 = v4890->reg_ready;
  int v4894 = v4893[8];
  int * v4895 = v4890->regs;
  int v4896 = v4895[8];
  int v4906 = (v4894 + ((v4891 - v4894) & (~((v4891 - v4894) >> 31)))) + 1;
  v4893[8] = v4906;
  int * v4898 = v4890->regs;
  int v4908 = v4896 + 1;
  v4898[8] = v4908;
  struct StateT * v4900 = slot_208(v4890);
  return v4900;
}

struct StateT * slot_156(struct StateT * v3819) {
  int v3820 = v3819->timer;
  int v3831 = v3820 + 1;
  v3819->timer = v3831;
  int * v3822 = v3819->reg_ready;
  int v3823 = v3822[8];
  int * v3824 = v3819->regs;
  int v3825 = v3824[8];
  int v3835 = (v3823 + ((v3820 - v3823) & (~((v3820 - v3823) >> 31)))) + 1;
  v3822[8] = v3835;
  int * v3827 = v3819->regs;
  int v3837 = v3825 + 1;
  v3827[8] = v3837;
  struct StateT * v3829 = slot_157(v3819);
  return v3829;
}

struct StateT * slot_154(struct StateT * v3777) {
  int v3778 = v3777->timer;
  int v3789 = v3778 + 1;
  v3777->timer = v3789;
  int * v3780 = v3777->reg_ready;
  int v3781 = v3780[8];
  int * v3782 = v3777->regs;
  int v3783 = v3782[8];
  int v3793 = (v3781 + ((v3778 - v3781) & (~((v3778 - v3781) >> 31)))) + 1;
  v3780[8] = v3793;
  int * v3785 = v3777->regs;
  int v3795 = v3783 + 1;
  v3785[8] = v3795;
  struct StateT * v3787 = slot_155(v3777);
  return v3787;
}

struct StateT * slot_68(struct StateT * v1971) {
  int v1972 = v1971->timer;
  int v1983 = v1972 + 1;
  v1971->timer = v1983;
  int * v1974 = v1971->reg_ready;
  int v1975 = v1974[8];
  int * v1976 = v1971->regs;
  int v1977 = v1976[8];
  int v1987 = (v1975 + ((v1972 - v1975) & (~((v1972 - v1975) >> 31)))) + 1;
  v1974[8] = v1987;
  int * v1979 = v1971->regs;
  int v1989 = v1977 + 1;
  v1979[8] = v1989;
  struct StateT * v1981 = slot_69(v1971);
  return v1981;
}

struct StateT * slot_105(struct StateT * v2748) {
  int v2749 = v2748->timer;
  int v2760 = v2749 + 1;
  v2748->timer = v2760;
  int * v2751 = v2748->reg_ready;
  int v2752 = v2751[8];
  int * v2753 = v2748->regs;
  int v2754 = v2753[8];
  int v2764 = (v2752 + ((v2749 - v2752) & (~((v2749 - v2752) >> 31)))) + 1;
  v2751[8] = v2764;
  int * v2756 = v2748->regs;
  int v2766 = v2754 + 1;
  v2756[8] = v2766;
  struct StateT * v2758 = slot_106(v2748);
  return v2758;
}

struct StateT * slot_27(struct StateT * v1110) {
  int v1111 = v1110->timer;
  int v1122 = v1111 + 1;
  v1110->timer = v1122;
  int * v1113 = v1110->reg_ready;
  int v1114 = v1113[8];
  int * v1115 = v1110->regs;
  int v1116 = v1115[8];
  int v1126 = (v1114 + ((v1111 - v1114) & (~((v1111 - v1114) >> 31)))) + 1;
  v1113[8] = v1126;
  int * v1118 = v1110->regs;
  int v1128 = v1116 + 1;
  v1118[8] = v1128;
  struct StateT * v1120 = slot_28(v1110);
  return v1120;
}

struct StateT * slot_164(struct StateT * v3987) {
  int v3988 = v3987->timer;
  int v3999 = v3988 + 1;
  v3987->timer = v3999;
  int * v3990 = v3987->reg_ready;
  int v3991 = v3990[8];
  int * v3992 = v3987->regs;
  int v3993 = v3992[8];
  int v4003 = (v3991 + ((v3988 - v3991) & (~((v3988 - v3991) >> 31)))) + 1;
  v3990[8] = v4003;
  int * v3995 = v3987->regs;
  int v4005 = v3993 + 1;
  v3995[8] = v4005;
  struct StateT * v3997 = slot_165(v3987);
  return v3997;
}

struct StateT * slot_15(struct StateT * v858) {
  int v859 = v858->timer;
  int v870 = v859 + 1;
  v858->timer = v870;
  int * v861 = v858->reg_ready;
  int v862 = v861[8];
  int * v863 = v858->regs;
  int v864 = v863[8];
  int v874 = (v862 + ((v859 - v862) & (~((v859 - v862) >> 31)))) + 1;
  v861[8] = v874;
  int * v866 = v858->regs;
  int v876 = v864 + 1;
  v866[8] = v876;
  struct StateT * v868 = slot_16(v858);
  return v868;
}

struct StateT * slot_133(struct StateT * v3336) {
  int v3337 = v3336->timer;
  int v3348 = v3337 + 1;
  v3336->timer = v3348;
  int * v3339 = v3336->reg_ready;
  int v3340 = v3339[8];
  int * v3341 = v3336->regs;
  int v3342 = v3341[8];
  int v3352 = (v3340 + ((v3337 - v3340) & (~((v3337 - v3340) >> 31)))) + 1;
  v3339[8] = v3352;
  int * v3344 = v3336->regs;
  int v3354 = v3342 + 1;
  v3344[8] = v3354;
  struct StateT * v3346 = slot_134(v3336);
  return v3346;
}

struct StateT * slot_56(struct StateT * v1719) {
  int v1720 = v1719->timer;
  int v1731 = v1720 + 1;
  v1719->timer = v1731;
  int * v1722 = v1719->reg_ready;
  int v1723 = v1722[8];
  int * v1724 = v1719->regs;
  int v1725 = v1724[8];
  int v1735 = (v1723 + ((v1720 - v1723) & (~((v1720 - v1723) >> 31)))) + 1;
  v1722[8] = v1735;
  int * v1727 = v1719->regs;
  int v1737 = v1725 + 1;
  v1727[8] = v1737;
  struct StateT * v1729 = slot_57(v1719);
  return v1729;
}

struct StateT * slot_222(struct StateT * v5205) {
  int v5206 = v5205->timer;
  int v5217 = v5206 + 1;
  v5205->timer = v5217;
  int * v5208 = v5205->reg_ready;
  int v5209 = v5208[8];
  int * v5210 = v5205->regs;
  int v5211 = v5210[8];
  int v5221 = (v5209 + ((v5206 - v5209) & (~((v5206 - v5209) >> 31)))) + 1;
  v5208[8] = v5221;
  int * v5213 = v5205->regs;
  int v5223 = v5211 + 1;
  v5213[8] = v5223;
  struct StateT * v5215 = slot_223(v5205);
  return v5215;
}

struct StateT * slot_34(struct StateT * v1257) {
  int v1258 = v1257->timer;
  int v1269 = v1258 + 1;
  v1257->timer = v1269;
  int * v1260 = v1257->reg_ready;
  int v1261 = v1260[8];
  int * v1262 = v1257->regs;
  int v1263 = v1262[8];
  int v1273 = (v1261 + ((v1258 - v1261) & (~((v1258 - v1261) >> 31)))) + 1;
  v1260[8] = v1273;
  int * v1265 = v1257->regs;
  int v1275 = v1263 + 1;
  v1265[8] = v1275;
  struct StateT * v1267 = slot_35(v1257);
  return v1267;
}

struct StateT * slot_171(struct StateT * v4134) {
  int v4135 = v4134->timer;
  int v4146 = v4135 + 1;
  v4134->timer = v4146;
  int * v4137 = v4134->reg_ready;
  int v4138 = v4137[8];
  int * v4139 = v4134->regs;
  int v4140 = v4139[8];
  int v4150 = (v4138 + ((v4135 - v4138) & (~((v4135 - v4138) >> 31)))) + 1;
  v4137[8] = v4150;
  int * v4142 = v4134->regs;
  int v4152 = v4140 + 1;
  v4142[8] = v4152;
  struct StateT * v4144 = slot_172(v4134);
  return v4144;
}

struct StateT * slot_162(struct StateT * v3945) {
  int v3946 = v3945->timer;
  int v3957 = v3946 + 1;
  v3945->timer = v3957;
  int * v3948 = v3945->reg_ready;
  int v3949 = v3948[8];
  int * v3950 = v3945->regs;
  int v3951 = v3950[8];
  int v3961 = (v3949 + ((v3946 - v3949) & (~((v3946 - v3949) >> 31)))) + 1;
  v3948[8] = v3961;
  int * v3953 = v3945->regs;
  int v3963 = v3951 + 1;
  v3953[8] = v3963;
  struct StateT * v3955 = slot_163(v3945);
  return v3955;
}

struct StateT * slot_21(struct StateT * v984) {
  int v985 = v984->timer;
  int v996 = v985 + 1;
  v984->timer = v996;
  int * v987 = v984->reg_ready;
  int v988 = v987[8];
  int * v989 = v984->regs;
  int v990 = v989[8];
  int v1000 = (v988 + ((v985 - v988) & (~((v985 - v988) >> 31)))) + 1;
  v987[8] = v1000;
  int * v992 = v984->regs;
  int v1002 = v990 + 1;
  v992[8] = v1002;
  struct StateT * v994 = slot_22(v984);
  return v994;
}

struct StateT * slot_118(struct StateT * v3021) {
  int v3022 = v3021->timer;
  int v3033 = v3022 + 1;
  v3021->timer = v3033;
  int * v3024 = v3021->reg_ready;
  int v3025 = v3024[8];
  int * v3026 = v3021->regs;
  int v3027 = v3026[8];
  int v3037 = (v3025 + ((v3022 - v3025) & (~((v3022 - v3025) >> 31)))) + 1;
  v3024[8] = v3037;
  int * v3029 = v3021->regs;
  int v3039 = v3027 + 1;
  v3029[8] = v3039;
  struct StateT * v3031 = slot_119(v3021);
  return v3031;
}

struct StateT * slot_121(struct StateT * v3084) {
  int v3085 = v3084->timer;
  int v3096 = v3085 + 1;
  v3084->timer = v3096;
  int * v3087 = v3084->reg_ready;
  int v3088 = v3087[8];
  int * v3089 = v3084->regs;
  int v3090 = v3089[8];
  int v3100 = (v3088 + ((v3085 - v3088) & (~((v3085 - v3088) >> 31)))) + 1;
  v3087[8] = v3100;
  int * v3092 = v3084->regs;
  int v3102 = v3090 + 1;
  v3092[8] = v3102;
  struct StateT * v3094 = slot_122(v3084);
  return v3094;
}

struct StateT * slot_144(struct StateT * v3567) {
  int v3568 = v3567->timer;
  int v3579 = v3568 + 1;
  v3567->timer = v3579;
  int * v3570 = v3567->reg_ready;
  int v3571 = v3570[8];
  int * v3572 = v3567->regs;
  int v3573 = v3572[8];
  int v3583 = (v3571 + ((v3568 - v3571) & (~((v3568 - v3571) >> 31)))) + 1;
  v3570[8] = v3583;
  int * v3575 = v3567->regs;
  int v3585 = v3573 + 1;
  v3575[8] = v3585;
  struct StateT * v3577 = slot_145(v3567);
  return v3577;
}

struct StateT * slot_201(struct StateT * v4764) {
  int v4765 = v4764->timer;
  int v4776 = v4765 + 1;
  v4764->timer = v4776;
  int * v4767 = v4764->reg_ready;
  int v4768 = v4767[8];
  int * v4769 = v4764->regs;
  int v4770 = v4769[8];
  int v4780 = (v4768 + ((v4765 - v4768) & (~((v4765 - v4768) >> 31)))) + 1;
  v4767[8] = v4780;
  int * v4772 = v4764->regs;
  int v4782 = v4770 + 1;
  v4772[8] = v4782;
  struct StateT * v4774 = slot_202(v4764);
  return v4774;
}

struct StateT * slot_94(struct StateT * v2517) {
  int v2518 = v2517->timer;
  int v2529 = v2518 + 1;
  v2517->timer = v2529;
  int * v2520 = v2517->reg_ready;
  int v2521 = v2520[8];
  int * v2522 = v2517->regs;
  int v2523 = v2522[8];
  int v2533 = (v2521 + ((v2518 - v2521) & (~((v2518 - v2521) >> 31)))) + 1;
  v2520[8] = v2533;
  int * v2525 = v2517->regs;
  int v2535 = v2523 + 1;
  v2525[8] = v2535;
  struct StateT * v2527 = slot_95(v2517);
  return v2527;
}

struct StateT * slot_63(struct StateT * v1866) {
  int v1867 = v1866->timer;
  int v1878 = v1867 + 1;
  v1866->timer = v1878;
  int * v1869 = v1866->reg_ready;
  int v1870 = v1869[8];
  int * v1871 = v1866->regs;
  int v1872 = v1871[8];
  int v1882 = (v1870 + ((v1867 - v1870) & (~((v1867 - v1870) >> 31)))) + 1;
  v1869[8] = v1882;
  int * v1874 = v1866->regs;
  int v1884 = v1872 + 1;
  v1874[8] = v1884;
  struct StateT * v1876 = slot_64(v1866);
  return v1876;
}

struct StateT * slot_146(struct StateT * v3609) {
  int v3610 = v3609->timer;
  int v3621 = v3610 + 1;
  v3609->timer = v3621;
  int * v3612 = v3609->reg_ready;
  int v3613 = v3612[8];
  int * v3614 = v3609->regs;
  int v3615 = v3614[8];
  int v3625 = (v3613 + ((v3610 - v3613) & (~((v3610 - v3613) >> 31)))) + 1;
  v3612[8] = v3625;
  int * v3617 = v3609->regs;
  int v3627 = v3615 + 1;
  v3617[8] = v3627;
  struct StateT * v3619 = slot_147(v3609);
  return v3619;
}

struct StateT * slot_24(struct StateT * v1047) {
  int v1048 = v1047->timer;
  int v1059 = v1048 + 1;
  v1047->timer = v1059;
  int * v1050 = v1047->reg_ready;
  int v1051 = v1050[8];
  int * v1052 = v1047->regs;
  int v1053 = v1052[8];
  int v1063 = (v1051 + ((v1048 - v1051) & (~((v1048 - v1051) >> 31)))) + 1;
  v1050[8] = v1063;
  int * v1055 = v1047->regs;
  int v1065 = v1053 + 1;
  v1055[8] = v1065;
  struct StateT * v1057 = slot_25(v1047);
  return v1057;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v115 = v3 + 1;
  v2->timer = v115;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int * v9 = v2->cache_tags;
  int v120 = (((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2;
  int v10 = v9[v120];
  int v121 = ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2) + 1;
  int v11 = v9[v121];
  int v122 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2);
  int v12 = v9[v122];
  int v123 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13 = v9[v123];
  int * v14 = v2->cache_vals;
  bool v124 = !(((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31))) == 0);
  int v107;
  if (v124) {
    int * v15 = v2->cache_age;
    int v126 = ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2) + ((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) & 1);
    int v16 = v15[v126];
    int v17 = v15[v120];
    int v127 = v17 + ((int)((unsigned int)(v17 - v16) >> 31));
    v15[v120] = v127;
    int * v19 = v2->cache_age;
    int v20 = v19[v121];
    int v129 = v20 + ((int)((unsigned int)(v20 - v16) >> 31));
    v19[v121] = v129;
    int * v22 = v2->cache_age;
    v22[v126] = 0;
    v107 = v126;
  } else {
    int * v25 = v2->cache_age;
    int v133 = (((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2;
    int v26 = v25[v133];
    int * v27 = v2->cache_tags;
    int v28 = v27[v133];
    int v29 = v25[v121];
    int v30 = v27[v121];
    bool v135 = !(((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) | (~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31))) == 0);
    int v84;
    if (v135) {
      int * v31 = v2->cache_age;
      int v137 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + ((~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) & 1);
      int v32 = v31[v137];
      int v33 = v31[v122];
      int v138 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
      v31[v122] = v138;
      int * v35 = v2->cache_age;
      int v36 = v35[v123];
      int v140 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
      v35[v123] = v140;
      int * v38 = v2->cache_age;
      v38[v137] = 0;
      v84 = v137;
    } else {
      int * v41 = v2->cache_age;
      int v144 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2);
      int v42 = v41[v144];
      int * v43 = v2->cache_tags;
      int v44 = v43[v144];
      int v45 = v41[v123];
      int v46 = v43[v123];
      int * v47 = v2->cache_dirty;
      int v147 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v48 = v47[v147];
      bool v148 = !(v48 == 0);
      if (v148) {
        int * v49 = v2->cache_tags;
        int v50 = v49[v147];
        int * v51 = v2->cache_vals;
        int v151 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v52 = v51[v151];
        int v152 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v53 = v51[v152];
        int * v54 = v2->mem;
        int v154 = v50 * 2;
        v54[v154] = v52;
        int * v56 = v2->mem;
        int v157 = (v50 * 2) + 1;
        v56[v157] = v53;
        ;
      } else {
        ;
      }
      int * v61 = v2->mem;
      int v162 = ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) * 2;
      int v62 = v61[v162];
      int v163 = (((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) * 2) + 1;
      int v63 = v61[v163];
      int * v64 = v2->cache_vals;
      int v165 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v64[v165] = v62;
      int * v66 = v2->cache_vals;
      int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v66[v168] = v63;
      int * v68 = v2->cache_tags;
      int v171 = (int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1);
      v68[v147] = v171;
      int * v70 = v2->cache_dirty;
      v70[v147] = 0;
      int * v72 = v2->cache_age;
      v72[v147] = 1;
      int * v74 = v2->cache_age;
      int v75 = v74[v147];
      int v76 = v74[v122];
      int v177 = v76 + ((int)((unsigned int)(v76 - v75) >> 31));
      v74[v122] = v177;
      int * v78 = v2->cache_age;
      int v79 = v78[v123];
      int v179 = v79 + ((int)((unsigned int)(v79 - v75) >> 31));
      v78[v123] = v179;
      int * v81 = v2->cache_age;
      v81[v147] = 0;
      v84 = v147;
    }
    int * v85 = v2->cache_vals;
    int v182 = v84 * 2;
    int v86 = v85[v182];
    int v183 = (v84 * 2) + 1;
    int v87 = v85[v183];
    int v184 = (((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v85[v184] = v86;
    int * v89 = v2->cache_vals;
    int v187 = ((((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v89[v187] = v87;
    int * v91 = v2->cache_tags;
    int v190 = ((((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v191 = (int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1);
    v91[v190] = v191;
    int * v93 = v2->cache_dirty;
    v93[v190] = 0;
    int * v95 = v2->cache_age;
    v95[v190] = 1;
    int * v97 = v2->cache_age;
    int v98 = v97[v190];
    int v99 = v97[v120];
    int v197 = v99 + ((int)((unsigned int)(v99 - v98) >> 31));
    v97[v120] = v197;
    int * v101 = v2->cache_age;
    int v102 = v101[v121];
    int v199 = v102 + ((int)((unsigned int)(v102 - v98) >> 31));
    v101[v121] = v199;
    int * v104 = v2->cache_age;
    v104[v190] = 0;
    v107 = v190;
  }
  int v202 = (v107 * 2) + (((int)((unsigned int)v8 >> 2)) & 1);
  int v108 = v14[v202];
  int * v109 = v2->reg_ready;
  int v205 = ((v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1) + ((100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) | (~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31)) | (~(((v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))) | (-(v13 ^ ((int)((unsigned int)((int)((unsigned int)v8 >> 2)) >> 1))))) >> 31))) & 104)))));
  v109[5] = v205;
  int * v111 = v2->regs;
  v111[5] = v108;
  struct StateT * v113 = slot_1(v2);
  return v113;
}

struct StateT * slot_195(struct StateT * v4638) {
  int v4639 = v4638->timer;
  int v4650 = v4639 + 1;
  v4638->timer = v4650;
  int * v4641 = v4638->reg_ready;
  int v4642 = v4641[8];
  int * v4643 = v4638->regs;
  int v4644 = v4643[8];
  int v4654 = (v4642 + ((v4639 - v4642) & (~((v4639 - v4642) >> 31)))) + 1;
  v4641[8] = v4654;
  int * v4646 = v4638->regs;
  int v4656 = v4644 + 1;
  v4646[8] = v4656;
  struct StateT * v4648 = slot_196(v4638);
  return v4648;
}

struct StateT * slot_125(struct StateT * v3168) {
  int v3169 = v3168->timer;
  int v3180 = v3169 + 1;
  v3168->timer = v3180;
  int * v3171 = v3168->reg_ready;
  int v3172 = v3171[8];
  int * v3173 = v3168->regs;
  int v3174 = v3173[8];
  int v3184 = (v3172 + ((v3169 - v3172) & (~((v3169 - v3172) >> 31)))) + 1;
  v3171[8] = v3184;
  int * v3176 = v3168->regs;
  int v3186 = v3174 + 1;
  v3176[8] = v3186;
  struct StateT * v3178 = slot_126(v3168);
  return v3178;
}

struct StateT * slot_148(struct StateT * v3651) {
  int v3652 = v3651->timer;
  int v3663 = v3652 + 1;
  v3651->timer = v3663;
  int * v3654 = v3651->reg_ready;
  int v3655 = v3654[8];
  int * v3656 = v3651->regs;
  int v3657 = v3656[8];
  int v3667 = (v3655 + ((v3652 - v3655) & (~((v3652 - v3655) >> 31)))) + 1;
  v3654[8] = v3667;
  int * v3659 = v3651->regs;
  int v3669 = v3657 + 1;
  v3659[8] = v3669;
  struct StateT * v3661 = slot_149(v3651);
  return v3661;
}

struct StateT * slot_126(struct StateT * v3189) {
  int v3190 = v3189->timer;
  int v3201 = v3190 + 1;
  v3189->timer = v3201;
  int * v3192 = v3189->reg_ready;
  int v3193 = v3192[8];
  int * v3194 = v3189->regs;
  int v3195 = v3194[8];
  int v3205 = (v3193 + ((v3190 - v3193) & (~((v3190 - v3193) >> 31)))) + 1;
  v3192[8] = v3205;
  int * v3197 = v3189->regs;
  int v3207 = v3195 + 1;
  v3197[8] = v3207;
  struct StateT * v3199 = slot_127(v3189);
  return v3199;
}

struct StateT * slot_223(struct StateT * v5226) {
  int v5227 = v5226->timer;
  int v5238 = v5227 + 1;
  v5226->timer = v5238;
  int * v5229 = v5226->reg_ready;
  int v5230 = v5229[8];
  int * v5231 = v5226->regs;
  int v5232 = v5231[8];
  int v5242 = (v5230 + ((v5227 - v5230) & (~((v5227 - v5230) >> 31)))) + 1;
  v5229[8] = v5242;
  int * v5234 = v5226->regs;
  int v5244 = v5232 + 1;
  v5234[8] = v5244;
  struct StateT * v5236 = slot_224(v5226);
  return v5236;
}

struct StateT * slot_79(struct StateT * v2202) {
  int v2203 = v2202->timer;
  int v2214 = v2203 + 1;
  v2202->timer = v2214;
  int * v2205 = v2202->reg_ready;
  int v2206 = v2205[8];
  int * v2207 = v2202->regs;
  int v2208 = v2207[8];
  int v2218 = (v2206 + ((v2203 - v2206) & (~((v2203 - v2206) >> 31)))) + 1;
  v2205[8] = v2218;
  int * v2210 = v2202->regs;
  int v2220 = v2208 + 1;
  v2210[8] = v2220;
  struct StateT * v2212 = slot_80(v2202);
  return v2212;
}

struct StateT * slot_41(struct StateT * v1404) {
  int v1405 = v1404->timer;
  int v1416 = v1405 + 1;
  v1404->timer = v1416;
  int * v1407 = v1404->reg_ready;
  int v1408 = v1407[8];
  int * v1409 = v1404->regs;
  int v1410 = v1409[8];
  int v1420 = (v1408 + ((v1405 - v1408) & (~((v1405 - v1408) >> 31)))) + 1;
  v1407[8] = v1420;
  int * v1412 = v1404->regs;
  int v1422 = v1410 + 1;
  v1412[8] = v1422;
  struct StateT * v1414 = slot_42(v1404);
  return v1414;
}

struct StateT * slot_39(struct StateT * v1362) {
  int v1363 = v1362->timer;
  int v1374 = v1363 + 1;
  v1362->timer = v1374;
  int * v1365 = v1362->reg_ready;
  int v1366 = v1365[8];
  int * v1367 = v1362->regs;
  int v1368 = v1367[8];
  int v1378 = (v1366 + ((v1363 - v1366) & (~((v1363 - v1366) >> 31)))) + 1;
  v1365[8] = v1378;
  int * v1370 = v1362->regs;
  int v1380 = v1368 + 1;
  v1370[8] = v1380;
  struct StateT * v1372 = slot_40(v1362);
  return v1372;
}

struct StateT * slot_142(struct StateT * v3525) {
  int v3526 = v3525->timer;
  int v3537 = v3526 + 1;
  v3525->timer = v3537;
  int * v3528 = v3525->reg_ready;
  int v3529 = v3528[8];
  int * v3530 = v3525->regs;
  int v3531 = v3530[8];
  int v3541 = (v3529 + ((v3526 - v3529) & (~((v3526 - v3529) >> 31)))) + 1;
  v3528[8] = v3541;
  int * v3533 = v3525->regs;
  int v3543 = v3531 + 1;
  v3533[8] = v3543;
  struct StateT * v3535 = slot_143(v3525);
  return v3535;
}

struct StateT * slot_60(struct StateT * v1803) {
  int v1804 = v1803->timer;
  int v1815 = v1804 + 1;
  v1803->timer = v1815;
  int * v1806 = v1803->reg_ready;
  int v1807 = v1806[8];
  int * v1808 = v1803->regs;
  int v1809 = v1808[8];
  int v1819 = (v1807 + ((v1804 - v1807) & (~((v1804 - v1807) >> 31)))) + 1;
  v1806[8] = v1819;
  int * v1811 = v1803->regs;
  int v1821 = v1809 + 1;
  v1811[8] = v1821;
  struct StateT * v1813 = slot_61(v1803);
  return v1813;
}

struct StateT * slot_112(struct StateT * v2895) {
  int v2896 = v2895->timer;
  int v2907 = v2896 + 1;
  v2895->timer = v2907;
  int * v2898 = v2895->reg_ready;
  int v2899 = v2898[8];
  int * v2900 = v2895->regs;
  int v2901 = v2900[8];
  int v2911 = (v2899 + ((v2896 - v2899) & (~((v2896 - v2899) >> 31)))) + 1;
  v2898[8] = v2911;
  int * v2903 = v2895->regs;
  int v2913 = v2901 + 1;
  v2903[8] = v2913;
  struct StateT * v2905 = slot_113(v2895);
  return v2905;
}

struct StateT * slot_47(struct StateT * v1530) {
  int v1531 = v1530->timer;
  int v1542 = v1531 + 1;
  v1530->timer = v1542;
  int * v1533 = v1530->reg_ready;
  int v1534 = v1533[8];
  int * v1535 = v1530->regs;
  int v1536 = v1535[8];
  int v1546 = (v1534 + ((v1531 - v1534) & (~((v1531 - v1534) >> 31)))) + 1;
  v1533[8] = v1546;
  int * v1538 = v1530->regs;
  int v1548 = v1536 + 1;
  v1538[8] = v1548;
  struct StateT * v1540 = slot_48(v1530);
  return v1540;
}

struct StateT * slot_214(struct StateT * v5037) {
  int v5038 = v5037->timer;
  int v5049 = v5038 + 1;
  v5037->timer = v5049;
  int * v5040 = v5037->reg_ready;
  int v5041 = v5040[8];
  int * v5042 = v5037->regs;
  int v5043 = v5042[8];
  int v5053 = (v5041 + ((v5038 - v5041) & (~((v5038 - v5041) >> 31)))) + 1;
  v5040[8] = v5053;
  int * v5045 = v5037->regs;
  int v5055 = v5043 + 1;
  v5045[8] = v5055;
  struct StateT * v5047 = slot_215(v5037);
  return v5047;
}

struct StateT * slot_29(struct StateT * v1152) {
  int v1153 = v1152->timer;
  int v1164 = v1153 + 1;
  v1152->timer = v1164;
  int * v1155 = v1152->reg_ready;
  int v1156 = v1155[8];
  int * v1157 = v1152->regs;
  int v1158 = v1157[8];
  int v1168 = (v1156 + ((v1153 - v1156) & (~((v1153 - v1156) >> 31)))) + 1;
  v1155[8] = v1168;
  int * v1160 = v1152->regs;
  int v1170 = v1158 + 1;
  v1160[8] = v1170;
  struct StateT * v1162 = slot_30(v1152);
  return v1162;
}

struct StateT * slot_16(struct StateT * v879) {
  int v880 = v879->timer;
  int v891 = v880 + 1;
  v879->timer = v891;
  int * v882 = v879->reg_ready;
  int v883 = v882[8];
  int * v884 = v879->regs;
  int v885 = v884[8];
  int v895 = (v883 + ((v880 - v883) & (~((v880 - v883) >> 31)))) + 1;
  v882[8] = v895;
  int * v887 = v879->regs;
  int v897 = v885 + 1;
  v887[8] = v897;
  struct StateT * v889 = slot_17(v879);
  return v889;
}

struct StateT * slot_113(struct StateT * v2916) {
  int v2917 = v2916->timer;
  int v2928 = v2917 + 1;
  v2916->timer = v2928;
  int * v2919 = v2916->reg_ready;
  int v2920 = v2919[8];
  int * v2921 = v2916->regs;
  int v2922 = v2921[8];
  int v2932 = (v2920 + ((v2917 - v2920) & (~((v2917 - v2920) >> 31)))) + 1;
  v2919[8] = v2932;
  int * v2924 = v2916->regs;
  int v2934 = v2922 + 1;
  v2924[8] = v2934;
  struct StateT * v2926 = slot_114(v2916);
  return v2926;
}

struct StateT * slot_151(struct StateT * v3714) {
  int v3715 = v3714->timer;
  int v3726 = v3715 + 1;
  v3714->timer = v3726;
  int * v3717 = v3714->reg_ready;
  int v3718 = v3717[8];
  int * v3719 = v3714->regs;
  int v3720 = v3719[8];
  int v3730 = (v3718 + ((v3715 - v3718) & (~((v3715 - v3718) >> 31)))) + 1;
  v3717[8] = v3730;
  int * v3722 = v3714->regs;
  int v3732 = v3720 + 1;
  v3722[8] = v3732;
  struct StateT * v3724 = slot_152(v3714);
  return v3724;
}

struct StateT * slot_7(struct StateT * v690) {
  int v691 = v690->timer;
  int v702 = v691 + 1;
  v690->timer = v702;
  int * v693 = v690->reg_ready;
  int v694 = v693[8];
  int * v695 = v690->regs;
  int v696 = v695[8];
  int v706 = (v694 + ((v691 - v694) & (~((v691 - v694) >> 31)))) + 1;
  v693[8] = v706;
  int * v698 = v690->regs;
  int v708 = v696 + 1;
  v698[8] = v708;
  struct StateT * v700 = slot_8(v690);
  return v700;
}

struct StateT * slot_124(struct StateT * v3147) {
  int v3148 = v3147->timer;
  int v3159 = v3148 + 1;
  v3147->timer = v3159;
  int * v3150 = v3147->reg_ready;
  int v3151 = v3150[8];
  int * v3152 = v3147->regs;
  int v3153 = v3152[8];
  int v3163 = (v3151 + ((v3148 - v3151) & (~((v3148 - v3151) >> 31)))) + 1;
  v3150[8] = v3163;
  int * v3155 = v3147->regs;
  int v3165 = v3153 + 1;
  v3155[8] = v3165;
  struct StateT * v3157 = slot_125(v3147);
  return v3157;
}

struct StateT * slot_191(struct StateT * v4554) {
  int v4555 = v4554->timer;
  int v4566 = v4555 + 1;
  v4554->timer = v4566;
  int * v4557 = v4554->reg_ready;
  int v4558 = v4557[8];
  int * v4559 = v4554->regs;
  int v4560 = v4559[8];
  int v4570 = (v4558 + ((v4555 - v4558) & (~((v4555 - v4558) >> 31)))) + 1;
  v4557[8] = v4570;
  int * v4562 = v4554->regs;
  int v4572 = v4560 + 1;
  v4562[8] = v4572;
  struct StateT * v4564 = slot_192(v4554);
  return v4564;
}

struct StateT * slot_103(struct StateT * v2706) {
  int v2707 = v2706->timer;
  int v2718 = v2707 + 1;
  v2706->timer = v2718;
  int * v2709 = v2706->reg_ready;
  int v2710 = v2709[8];
  int * v2711 = v2706->regs;
  int v2712 = v2711[8];
  int v2722 = (v2710 + ((v2707 - v2710) & (~((v2707 - v2710) >> 31)))) + 1;
  v2709[8] = v2722;
  int * v2714 = v2706->regs;
  int v2724 = v2712 + 1;
  v2714[8] = v2724;
  struct StateT * v2716 = slot_104(v2706);
  return v2716;
}

struct StateT * slot_128(struct StateT * v3231) {
  int v3232 = v3231->timer;
  int v3243 = v3232 + 1;
  v3231->timer = v3243;
  int * v3234 = v3231->reg_ready;
  int v3235 = v3234[8];
  int * v3236 = v3231->regs;
  int v3237 = v3236[8];
  int v3247 = (v3235 + ((v3232 - v3235) & (~((v3232 - v3235) >> 31)))) + 1;
  v3234[8] = v3247;
  int * v3239 = v3231->regs;
  int v3249 = v3237 + 1;
  v3239[8] = v3249;
  struct StateT * v3241 = slot_129(v3231);
  return v3241;
}

struct StateT * slot_19(struct StateT * v942) {
  int v943 = v942->timer;
  int v954 = v943 + 1;
  v942->timer = v954;
  int * v945 = v942->reg_ready;
  int v946 = v945[8];
  int * v947 = v942->regs;
  int v948 = v947[8];
  int v958 = (v946 + ((v943 - v946) & (~((v943 - v946) >> 31)))) + 1;
  v945[8] = v958;
  int * v950 = v942->regs;
  int v960 = v948 + 1;
  v950[8] = v960;
  struct StateT * v952 = slot_20(v942);
  return v952;
}

struct StateT * slot_87(struct StateT * v2370) {
  int v2371 = v2370->timer;
  int v2382 = v2371 + 1;
  v2370->timer = v2382;
  int * v2373 = v2370->reg_ready;
  int v2374 = v2373[8];
  int * v2375 = v2370->regs;
  int v2376 = v2375[8];
  int v2386 = (v2374 + ((v2371 - v2374) & (~((v2371 - v2374) >> 31)))) + 1;
  v2373[8] = v2386;
  int * v2378 = v2370->regs;
  int v2388 = v2376 + 1;
  v2378[8] = v2388;
  struct StateT * v2380 = slot_88(v2370);
  return v2380;
}

struct StateT * slot_67(struct StateT * v1950) {
  int v1951 = v1950->timer;
  int v1962 = v1951 + 1;
  v1950->timer = v1962;
  int * v1953 = v1950->reg_ready;
  int v1954 = v1953[8];
  int * v1955 = v1950->regs;
  int v1956 = v1955[8];
  int v1966 = (v1954 + ((v1951 - v1954) & (~((v1951 - v1954) >> 31)))) + 1;
  v1953[8] = v1966;
  int * v1958 = v1950->regs;
  int v1968 = v1956 + 1;
  v1958[8] = v1968;
  struct StateT * v1960 = slot_68(v1950);
  return v1960;
}

struct StateT * slot_81(struct StateT * v2244) {
  int v2245 = v2244->timer;
  int v2256 = v2245 + 1;
  v2244->timer = v2256;
  int * v2247 = v2244->reg_ready;
  int v2248 = v2247[8];
  int * v2249 = v2244->regs;
  int v2250 = v2249[8];
  int v2260 = (v2248 + ((v2245 - v2248) & (~((v2245 - v2248) >> 31)))) + 1;
  v2247[8] = v2260;
  int * v2252 = v2244->regs;
  int v2262 = v2250 + 1;
  v2252[8] = v2262;
  struct StateT * v2254 = slot_82(v2244);
  return v2254;
}

struct StateT * slot_95(struct StateT * v2538) {
  int v2539 = v2538->timer;
  int v2550 = v2539 + 1;
  v2538->timer = v2550;
  int * v2541 = v2538->reg_ready;
  int v2542 = v2541[8];
  int * v2543 = v2538->regs;
  int v2544 = v2543[8];
  int v2554 = (v2542 + ((v2539 - v2542) & (~((v2539 - v2542) >> 31)))) + 1;
  v2541[8] = v2554;
  int * v2546 = v2538->regs;
  int v2556 = v2544 + 1;
  v2546[8] = v2556;
  struct StateT * v2548 = slot_96(v2538);
  return v2548;
}

struct StateT * slot_115(struct StateT * v2958) {
  int v2959 = v2958->timer;
  int v2970 = v2959 + 1;
  v2958->timer = v2970;
  int * v2961 = v2958->reg_ready;
  int v2962 = v2961[8];
  int * v2963 = v2958->regs;
  int v2964 = v2963[8];
  int v2974 = (v2962 + ((v2959 - v2962) & (~((v2959 - v2962) >> 31)))) + 1;
  v2961[8] = v2974;
  int * v2966 = v2958->regs;
  int v2976 = v2964 + 1;
  v2966[8] = v2976;
  struct StateT * v2968 = slot_116(v2958);
  return v2968;
}

struct StateT * slot_78(struct StateT * v2181) {
  int v2182 = v2181->timer;
  int v2193 = v2182 + 1;
  v2181->timer = v2193;
  int * v2184 = v2181->reg_ready;
  int v2185 = v2184[8];
  int * v2186 = v2181->regs;
  int v2187 = v2186[8];
  int v2197 = (v2185 + ((v2182 - v2185) & (~((v2182 - v2185) >> 31)))) + 1;
  v2184[8] = v2197;
  int * v2189 = v2181->regs;
  int v2199 = v2187 + 1;
  v2189[8] = v2199;
  struct StateT * v2191 = slot_79(v2181);
  return v2191;
}

struct StateT * slot_32(struct StateT * v1215) {
  int v1216 = v1215->timer;
  int v1227 = v1216 + 1;
  v1215->timer = v1227;
  int * v1218 = v1215->reg_ready;
  int v1219 = v1218[8];
  int * v1220 = v1215->regs;
  int v1221 = v1220[8];
  int v1231 = (v1219 + ((v1216 - v1219) & (~((v1216 - v1219) >> 31)))) + 1;
  v1218[8] = v1231;
  int * v1223 = v1215->regs;
  int v1233 = v1221 + 1;
  v1223[8] = v1233;
  struct StateT * v1225 = slot_33(v1215);
  return v1225;
}

struct StateT * slot_205(struct StateT * v4848) {
  int v4849 = v4848->timer;
  int v4860 = v4849 + 1;
  v4848->timer = v4860;
  int * v4851 = v4848->reg_ready;
  int v4852 = v4851[8];
  int * v4853 = v4848->regs;
  int v4854 = v4853[8];
  int v4864 = (v4852 + ((v4849 - v4852) & (~((v4849 - v4852) >> 31)))) + 1;
  v4851[8] = v4864;
  int * v4856 = v4848->regs;
  int v4866 = v4854 + 1;
  v4856[8] = v4866;
  struct StateT * v4858 = slot_206(v4848);
  return v4858;
}

struct StateT * slot_193(struct StateT * v4596) {
  int v4597 = v4596->timer;
  int v4608 = v4597 + 1;
  v4596->timer = v4608;
  int * v4599 = v4596->reg_ready;
  int v4600 = v4599[8];
  int * v4601 = v4596->regs;
  int v4602 = v4601[8];
  int v4612 = (v4600 + ((v4597 - v4600) & (~((v4597 - v4600) >> 31)))) + 1;
  v4599[8] = v4612;
  int * v4604 = v4596->regs;
  int v4614 = v4602 + 1;
  v4604[8] = v4614;
  struct StateT * v4606 = slot_194(v4596);
  return v4606;
}

struct StateT * slot_176(struct StateT * v4239) {
  int v4240 = v4239->timer;
  int v4251 = v4240 + 1;
  v4239->timer = v4251;
  int * v4242 = v4239->reg_ready;
  int v4243 = v4242[8];
  int * v4244 = v4239->regs;
  int v4245 = v4244[8];
  int v4255 = (v4243 + ((v4240 - v4243) & (~((v4240 - v4243) >> 31)))) + 1;
  v4242[8] = v4255;
  int * v4247 = v4239->regs;
  int v4257 = v4245 + 1;
  v4247[8] = v4257;
  struct StateT * v4249 = slot_177(v4239);
  return v4249;
}

struct StateT * slot_189(struct StateT * v4512) {
  int v4513 = v4512->timer;
  int v4524 = v4513 + 1;
  v4512->timer = v4524;
  int * v4515 = v4512->reg_ready;
  int v4516 = v4515[8];
  int * v4517 = v4512->regs;
  int v4518 = v4517[8];
  int v4528 = (v4516 + ((v4513 - v4516) & (~((v4513 - v4516) >> 31)))) + 1;
  v4515[8] = v4528;
  int * v4520 = v4512->regs;
  int v4530 = v4518 + 1;
  v4520[8] = v4530;
  struct StateT * v4522 = slot_190(v4512);
  return v4522;
}

struct StateT * slot_33(struct StateT * v1236) {
  int v1237 = v1236->timer;
  int v1248 = v1237 + 1;
  v1236->timer = v1248;
  int * v1239 = v1236->reg_ready;
  int v1240 = v1239[8];
  int * v1241 = v1236->regs;
  int v1242 = v1241[8];
  int v1252 = (v1240 + ((v1237 - v1240) & (~((v1237 - v1240) >> 31)))) + 1;
  v1239[8] = v1252;
  int * v1244 = v1236->regs;
  int v1254 = v1242 + 1;
  v1244[8] = v1254;
  struct StateT * v1246 = slot_34(v1236);
  return v1246;
}

struct StateT * slot_35(struct StateT * v1278) {
  int v1279 = v1278->timer;
  int v1290 = v1279 + 1;
  v1278->timer = v1290;
  int * v1281 = v1278->reg_ready;
  int v1282 = v1281[8];
  int * v1283 = v1278->regs;
  int v1284 = v1283[8];
  int v1294 = (v1282 + ((v1279 - v1282) & (~((v1279 - v1282) >> 31)))) + 1;
  v1281[8] = v1294;
  int * v1286 = v1278->regs;
  int v1296 = v1284 + 1;
  v1286[8] = v1296;
  struct StateT * v1288 = slot_36(v1278);
  return v1288;
}

struct StateT * slot_210(struct StateT * v4953) {
  int v4954 = v4953->timer;
  int v4965 = v4954 + 1;
  v4953->timer = v4965;
  int * v4956 = v4953->reg_ready;
  int v4957 = v4956[8];
  int * v4958 = v4953->regs;
  int v4959 = v4958[8];
  int v4969 = (v4957 + ((v4954 - v4957) & (~((v4954 - v4957) >> 31)))) + 1;
  v4956[8] = v4969;
  int * v4961 = v4953->regs;
  int v4971 = v4959 + 1;
  v4961[8] = v4971;
  struct StateT * v4963 = slot_211(v4953);
  return v4963;
}

struct StateT * slot_166(struct StateT * v4029) {
  int v4030 = v4029->timer;
  int v4041 = v4030 + 1;
  v4029->timer = v4041;
  int * v4032 = v4029->reg_ready;
  int v4033 = v4032[8];
  int * v4034 = v4029->regs;
  int v4035 = v4034[8];
  int v4045 = (v4033 + ((v4030 - v4033) & (~((v4030 - v4033) >> 31)))) + 1;
  v4032[8] = v4045;
  int * v4037 = v4029->regs;
  int v4047 = v4035 + 1;
  v4037[8] = v4047;
  struct StateT * v4039 = slot_167(v4029);
  return v4039;
}

struct StateT * slot_51(struct StateT * v1614) {
  int v1615 = v1614->timer;
  int v1626 = v1615 + 1;
  v1614->timer = v1626;
  int * v1617 = v1614->reg_ready;
  int v1618 = v1617[8];
  int * v1619 = v1614->regs;
  int v1620 = v1619[8];
  int v1630 = (v1618 + ((v1615 - v1618) & (~((v1615 - v1618) >> 31)))) + 1;
  v1617[8] = v1630;
  int * v1622 = v1614->regs;
  int v1632 = v1620 + 1;
  v1622[8] = v1632;
  struct StateT * v1624 = slot_52(v1614);
  return v1624;
}

struct StateT * slot_52(struct StateT * v1635) {
  int v1636 = v1635->timer;
  int v1647 = v1636 + 1;
  v1635->timer = v1647;
  int * v1638 = v1635->reg_ready;
  int v1639 = v1638[8];
  int * v1640 = v1635->regs;
  int v1641 = v1640[8];
  int v1651 = (v1639 + ((v1636 - v1639) & (~((v1636 - v1639) >> 31)))) + 1;
  v1638[8] = v1651;
  int * v1643 = v1635->regs;
  int v1653 = v1641 + 1;
  v1643[8] = v1653;
  struct StateT * v1645 = slot_53(v1635);
  return v1645;
}

struct StateT * slot_83(struct StateT * v2286) {
  int v2287 = v2286->timer;
  int v2298 = v2287 + 1;
  v2286->timer = v2298;
  int * v2289 = v2286->reg_ready;
  int v2290 = v2289[8];
  int * v2291 = v2286->regs;
  int v2292 = v2291[8];
  int v2302 = (v2290 + ((v2287 - v2290) & (~((v2287 - v2290) >> 31)))) + 1;
  v2289[8] = v2302;
  int * v2294 = v2286->regs;
  int v2304 = v2292 + 1;
  v2294[8] = v2304;
  struct StateT * v2296 = slot_84(v2286);
  return v2296;
}

struct StateT * slot_25(struct StateT * v1068) {
  int v1069 = v1068->timer;
  int v1080 = v1069 + 1;
  v1068->timer = v1080;
  int * v1071 = v1068->reg_ready;
  int v1072 = v1071[8];
  int * v1073 = v1068->regs;
  int v1074 = v1073[8];
  int v1084 = (v1072 + ((v1069 - v1072) & (~((v1069 - v1072) >> 31)))) + 1;
  v1071[8] = v1084;
  int * v1076 = v1068->regs;
  int v1086 = v1074 + 1;
  v1076[8] = v1086;
  struct StateT * v1078 = slot_26(v1068);
  return v1078;
}

struct StateT * slot_209(struct StateT * v4932) {
  int v4933 = v4932->timer;
  int v4944 = v4933 + 1;
  v4932->timer = v4944;
  int * v4935 = v4932->reg_ready;
  int v4936 = v4935[8];
  int * v4937 = v4932->regs;
  int v4938 = v4937[8];
  int v4948 = (v4936 + ((v4933 - v4936) & (~((v4933 - v4936) >> 31)))) + 1;
  v4935[8] = v4948;
  int * v4940 = v4932->regs;
  int v4950 = v4938 + 1;
  v4940[8] = v4950;
  struct StateT * v4942 = slot_210(v4932);
  return v4942;
}

struct StateT * slot_3(struct StateT * v424) {
  int v425 = v424->timer;
  int v436 = v425 + 1;
  v424->timer = v436;
  int * v427 = v424->reg_ready;
  int v428 = v427[6];
  int * v429 = v424->regs;
  int v430 = v429[6];
  int v440 = (v428 + ((v425 - v428) & (~((v425 - v428) >> 31)))) + 1;
  v427[6] = v440;
  int * v432 = v424->regs;
  int v442 = v430 << 2;
  v432[6] = v442;
  struct StateT * v434 = slot_4(v424);
  return v434;
}

struct StateT * slot_123(struct StateT * v3126) {
  int v3127 = v3126->timer;
  int v3138 = v3127 + 1;
  v3126->timer = v3138;
  int * v3129 = v3126->reg_ready;
  int v3130 = v3129[8];
  int * v3131 = v3126->regs;
  int v3132 = v3131[8];
  int v3142 = (v3130 + ((v3127 - v3130) & (~((v3127 - v3130) >> 31)))) + 1;
  v3129[8] = v3142;
  int * v3134 = v3126->regs;
  int v3144 = v3132 + 1;
  v3134[8] = v3144;
  struct StateT * v3136 = slot_124(v3126);
  return v3136;
}

struct StateT * slot_73(struct StateT * v2076) {
  int v2077 = v2076->timer;
  int v2088 = v2077 + 1;
  v2076->timer = v2088;
  int * v2079 = v2076->reg_ready;
  int v2080 = v2079[8];
  int * v2081 = v2076->regs;
  int v2082 = v2081[8];
  int v2092 = (v2080 + ((v2077 - v2080) & (~((v2077 - v2080) >> 31)))) + 1;
  v2079[8] = v2092;
  int * v2084 = v2076->regs;
  int v2094 = v2082 + 1;
  v2084[8] = v2094;
  struct StateT * v2086 = slot_74(v2076);
  return v2086;
}

struct StateT * slot_198(struct StateT * v4701) {
  int v4702 = v4701->timer;
  int v4713 = v4702 + 1;
  v4701->timer = v4713;
  int * v4704 = v4701->reg_ready;
  int v4705 = v4704[8];
  int * v4706 = v4701->regs;
  int v4707 = v4706[8];
  int v4717 = (v4705 + ((v4702 - v4705) & (~((v4702 - v4705) >> 31)))) + 1;
  v4704[8] = v4717;
  int * v4709 = v4701->regs;
  int v4719 = v4707 + 1;
  v4709[8] = v4719;
  struct StateT * v4711 = slot_199(v4701);
  return v4711;
}

struct StateT * slot_1(struct StateT * v210) {
  int v211 = v210->timer;
  int v319 = v211 + 1;
  v210->timer = v319;
  int * v213 = v210->cache_tags;
  int v214 = v213[0];
  int v215 = v213[1];
  int v216 = v213[8];
  int v217 = v213[9];
  int * v218 = v210->cache_vals;
  bool v325 = !(((~(((v214 ^ 10) | (-(v214 ^ 10))) >> 31)) | (~(((v215 ^ 10) | (-(v215 ^ 10))) >> 31))) == 0);
  int v311;
  if (v325) {
    int * v219 = v210->cache_age;
    int v327 = (~(((v215 ^ 10) | (-(v215 ^ 10))) >> 31)) & 1;
    int v220 = v219[v327];
    int v221 = v219[0];
    int v328 = v221 + ((int)((unsigned int)(v221 - v220) >> 31));
    v219[0] = v328;
    int * v223 = v210->cache_age;
    int v224 = v223[1];
    int v330 = v224 + ((int)((unsigned int)(v224 - v220) >> 31));
    v223[1] = v330;
    int * v226 = v210->cache_age;
    v226[v327] = 0;
    v311 = v327;
  } else {
    int * v229 = v210->cache_age;
    int v230 = v229[0];
    int * v231 = v210->cache_tags;
    int v232 = v231[0];
    int v233 = v229[1];
    int v234 = v231[1];
    bool v334 = !(((~(((v216 ^ 10) | (-(v216 ^ 10))) >> 31)) | (~(((v217 ^ 10) | (-(v217 ^ 10))) >> 31))) == 0);
    int v288;
    if (v334) {
      int * v235 = v210->cache_age;
      int v336 = 8 + ((~(((v217 ^ 10) | (-(v217 ^ 10))) >> 31)) & 1);
      int v236 = v235[v336];
      int v237 = v235[8];
      int v337 = v237 + ((int)((unsigned int)(v237 - v236) >> 31));
      v235[8] = v337;
      int * v239 = v210->cache_age;
      int v240 = v239[9];
      int v339 = v240 + ((int)((unsigned int)(v240 - v236) >> 31));
      v239[9] = v339;
      int * v242 = v210->cache_age;
      v242[v336] = 0;
      v288 = v336;
    } else {
      int * v245 = v210->cache_age;
      int v246 = v245[8];
      int * v247 = v210->cache_tags;
      int v248 = v247[8];
      int v249 = v245[9];
      int v250 = v247[9];
      int * v251 = v210->cache_dirty;
      int v344 = 8 + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v252 = v251[v344];
      bool v345 = !(v252 == 0);
      if (v345) {
        int * v253 = v210->cache_tags;
        int v254 = v253[v344];
        int * v255 = v210->cache_vals;
        int v348 = (8 + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v256 = v255[v348];
        int v349 = ((8 + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v257 = v255[v349];
        int * v258 = v210->mem;
        int v351 = v254 * 2;
        v258[v351] = v256;
        int * v260 = v210->mem;
        int v354 = (v254 * 2) + 1;
        v260[v354] = v257;
        ;
      } else {
        ;
      }
      int * v265 = v210->mem;
      int v266 = v265[20];
      int v267 = v265[21];
      int * v268 = v210->cache_vals;
      int v362 = (8 + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v268[v362] = v266;
      int * v270 = v210->cache_vals;
      int v365 = ((8 + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v270[v365] = v267;
      int * v272 = v210->cache_tags;
      v272[v344] = 10;
      int * v274 = v210->cache_dirty;
      v274[v344] = 0;
      int * v276 = v210->cache_age;
      v276[v344] = 1;
      int * v278 = v210->cache_age;
      int v279 = v278[v344];
      int v280 = v278[8];
      int v372 = v280 + ((int)((unsigned int)(v280 - v279) >> 31));
      v278[8] = v372;
      int * v282 = v210->cache_age;
      int v283 = v282[9];
      int v374 = v283 + ((int)((unsigned int)(v283 - v279) >> 31));
      v282[9] = v374;
      int * v285 = v210->cache_age;
      v285[v344] = 0;
      v288 = v344;
    }
    int * v289 = v210->cache_vals;
    int v377 = v288 * 2;
    int v290 = v289[v377];
    int v378 = (v288 * 2) + 1;
    int v291 = v289[v378];
    int v379 = ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v289[v379] = v290;
    int * v293 = v210->cache_vals;
    int v382 = (((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v293[v382] = v291;
    int * v295 = v210->cache_tags;
    int v385 = (((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v295[v385] = 10;
    int * v297 = v210->cache_dirty;
    v297[v385] = 0;
    int * v299 = v210->cache_age;
    v299[v385] = 1;
    int * v301 = v210->cache_age;
    int v302 = v301[v385];
    int v303 = v301[0];
    int v390 = v303 + ((int)((unsigned int)(v303 - v302) >> 31));
    v301[0] = v390;
    int * v305 = v210->cache_age;
    int v306 = v305[1];
    int v392 = v306 + ((int)((unsigned int)(v306 - v302) >> 31));
    v305[1] = v392;
    int * v308 = v210->cache_age;
    v308[v385] = 0;
    v311 = v385;
  }
  int v395 = v311 * 2;
  int v312 = v218[v395];
  int * v313 = v210->reg_ready;
  int v398 = (v211 + 1) + ((100 ^ (((~(((v216 ^ 10) | (-(v216 ^ 10))) >> 31)) | (~(((v217 ^ 10) | (-(v217 ^ 10))) >> 31))) & 104)) ^ (((~(((v214 ^ 10) | (-(v214 ^ 10))) >> 31)) | (~(((v215 ^ 10) | (-(v215 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v216 ^ 10) | (-(v216 ^ 10))) >> 31)) | (~(((v217 ^ 10) | (-(v217 ^ 10))) >> 31))) & 104)))));
  v313[6] = v398;
  int * v315 = v210->regs;
  v315[6] = v312;
  struct StateT * v317 = slot_2(v210);
  return v317;
}

struct StateT * slot_187(struct StateT * v4470) {
  int v4471 = v4470->timer;
  int v4482 = v4471 + 1;
  v4470->timer = v4482;
  int * v4473 = v4470->reg_ready;
  int v4474 = v4473[8];
  int * v4475 = v4470->regs;
  int v4476 = v4475[8];
  int v4486 = (v4474 + ((v4471 - v4474) & (~((v4471 - v4474) >> 31)))) + 1;
  v4473[8] = v4486;
  int * v4478 = v4470->regs;
  int v4488 = v4476 + 1;
  v4478[8] = v4488;
  struct StateT * v4480 = slot_188(v4470);
  return v4480;
}

struct StateT * slot_97(struct StateT * v2580) {
  int v2581 = v2580->timer;
  int v2592 = v2581 + 1;
  v2580->timer = v2592;
  int * v2583 = v2580->reg_ready;
  int v2584 = v2583[8];
  int * v2585 = v2580->regs;
  int v2586 = v2585[8];
  int v2596 = (v2584 + ((v2581 - v2584) & (~((v2581 - v2584) >> 31)))) + 1;
  v2583[8] = v2596;
  int * v2588 = v2580->regs;
  int v2598 = v2586 + 1;
  v2588[8] = v2598;
  struct StateT * v2590 = slot_98(v2580);
  return v2590;
}

struct StateT * slot_182(struct StateT * v4365) {
  int v4366 = v4365->timer;
  int v4377 = v4366 + 1;
  v4365->timer = v4377;
  int * v4368 = v4365->reg_ready;
  int v4369 = v4368[8];
  int * v4370 = v4365->regs;
  int v4371 = v4370[8];
  int v4381 = (v4369 + ((v4366 - v4369) & (~((v4366 - v4369) >> 31)))) + 1;
  v4368[8] = v4381;
  int * v4373 = v4365->regs;
  int v4383 = v4371 + 1;
  v4373[8] = v4383;
  struct StateT * v4375 = slot_183(v4365);
  return v4375;
}

struct StateT * slot_38(struct StateT * v1341) {
  int v1342 = v1341->timer;
  int v1353 = v1342 + 1;
  v1341->timer = v1353;
  int * v1344 = v1341->reg_ready;
  int v1345 = v1344[8];
  int * v1346 = v1341->regs;
  int v1347 = v1346[8];
  int v1357 = (v1345 + ((v1342 - v1345) & (~((v1342 - v1345) >> 31)))) + 1;
  v1344[8] = v1357;
  int * v1349 = v1341->regs;
  int v1359 = v1347 + 1;
  v1349[8] = v1359;
  struct StateT * v1351 = slot_39(v1341);
  return v1351;
}

struct StateT * slot_178(struct StateT * v4281) {
  int v4282 = v4281->timer;
  int v4293 = v4282 + 1;
  v4281->timer = v4293;
  int * v4284 = v4281->reg_ready;
  int v4285 = v4284[8];
  int * v4286 = v4281->regs;
  int v4287 = v4286[8];
  int v4297 = (v4285 + ((v4282 - v4285) & (~((v4282 - v4285) >> 31)))) + 1;
  v4284[8] = v4297;
  int * v4289 = v4281->regs;
  int v4299 = v4287 + 1;
  v4289[8] = v4299;
  struct StateT * v4291 = slot_179(v4281);
  return v4291;
}

struct StateT * slot_106(struct StateT * v2769) {
  int v2770 = v2769->timer;
  int v2781 = v2770 + 1;
  v2769->timer = v2781;
  int * v2772 = v2769->reg_ready;
  int v2773 = v2772[8];
  int * v2774 = v2769->regs;
  int v2775 = v2774[8];
  int v2785 = (v2773 + ((v2770 - v2773) & (~((v2770 - v2773) >> 31)))) + 1;
  v2772[8] = v2785;
  int * v2777 = v2769->regs;
  int v2787 = v2775 + 1;
  v2777[8] = v2787;
  struct StateT * v2779 = slot_107(v2769);
  return v2779;
}

struct StateT * slot_98(struct StateT * v2601) {
  int v2602 = v2601->timer;
  int v2613 = v2602 + 1;
  v2601->timer = v2613;
  int * v2604 = v2601->reg_ready;
  int v2605 = v2604[8];
  int * v2606 = v2601->regs;
  int v2607 = v2606[8];
  int v2617 = (v2605 + ((v2602 - v2605) & (~((v2602 - v2605) >> 31)))) + 1;
  v2604[8] = v2617;
  int * v2609 = v2601->regs;
  int v2619 = v2607 + 1;
  v2609[8] = v2619;
  struct StateT * v2611 = slot_99(v2601);
  return v2611;
}

struct StateT * slot_159(struct StateT * v3882) {
  int v3883 = v3882->timer;
  int v3894 = v3883 + 1;
  v3882->timer = v3894;
  int * v3885 = v3882->reg_ready;
  int v3886 = v3885[8];
  int * v3887 = v3882->regs;
  int v3888 = v3887[8];
  int v3898 = (v3886 + ((v3883 - v3886) & (~((v3883 - v3886) >> 31)))) + 1;
  v3885[8] = v3898;
  int * v3890 = v3882->regs;
  int v3900 = v3888 + 1;
  v3890[8] = v3900;
  struct StateT * v3892 = slot_160(v3882);
  return v3892;
}

struct StateT * slot_46(struct StateT * v1509) {
  int v1510 = v1509->timer;
  int v1521 = v1510 + 1;
  v1509->timer = v1521;
  int * v1512 = v1509->reg_ready;
  int v1513 = v1512[8];
  int * v1514 = v1509->regs;
  int v1515 = v1514[8];
  int v1525 = (v1513 + ((v1510 - v1513) & (~((v1510 - v1513) >> 31)))) + 1;
  v1512[8] = v1525;
  int * v1517 = v1509->regs;
  int v1527 = v1515 + 1;
  v1517[8] = v1527;
  struct StateT * v1519 = slot_47(v1509);
  return v1519;
}

struct StateT * slot_212(struct StateT * v4995) {
  int v4996 = v4995->timer;
  int v5007 = v4996 + 1;
  v4995->timer = v5007;
  int * v4998 = v4995->reg_ready;
  int v4999 = v4998[8];
  int * v5000 = v4995->regs;
  int v5001 = v5000[8];
  int v5011 = (v4999 + ((v4996 - v4999) & (~((v4996 - v4999) >> 31)))) + 1;
  v4998[8] = v5011;
  int * v5003 = v4995->regs;
  int v5013 = v5001 + 1;
  v5003[8] = v5013;
  struct StateT * v5005 = slot_213(v4995);
  return v5005;
}

struct StateT * slot_132(struct StateT * v3315) {
  int v3316 = v3315->timer;
  int v3327 = v3316 + 1;
  v3315->timer = v3327;
  int * v3318 = v3315->reg_ready;
  int v3319 = v3318[8];
  int * v3320 = v3315->regs;
  int v3321 = v3320[8];
  int v3331 = (v3319 + ((v3316 - v3319) & (~((v3316 - v3319) >> 31)))) + 1;
  v3318[8] = v3331;
  int * v3323 = v3315->regs;
  int v3333 = v3321 + 1;
  v3323[8] = v3333;
  struct StateT * v3325 = slot_133(v3315);
  return v3325;
}

struct StateT * slot_130(struct StateT * v3273) {
  int v3274 = v3273->timer;
  int v3285 = v3274 + 1;
  v3273->timer = v3285;
  int * v3276 = v3273->reg_ready;
  int v3277 = v3276[8];
  int * v3278 = v3273->regs;
  int v3279 = v3278[8];
  int v3289 = (v3277 + ((v3274 - v3277) & (~((v3274 - v3277) >> 31)))) + 1;
  v3276[8] = v3289;
  int * v3281 = v3273->regs;
  int v3291 = v3279 + 1;
  v3281[8] = v3291;
  struct StateT * v3283 = slot_131(v3273);
  return v3283;
}

struct StateT * slot_211(struct StateT * v4974) {
  int v4975 = v4974->timer;
  int v4986 = v4975 + 1;
  v4974->timer = v4986;
  int * v4977 = v4974->reg_ready;
  int v4978 = v4977[8];
  int * v4979 = v4974->regs;
  int v4980 = v4979[8];
  int v4990 = (v4978 + ((v4975 - v4978) & (~((v4975 - v4978) >> 31)))) + 1;
  v4977[8] = v4990;
  int * v4982 = v4974->regs;
  int v4992 = v4980 + 1;
  v4982[8] = v4992;
  struct StateT * v4984 = slot_212(v4974);
  return v4984;
}

struct StateT * slot_20(struct StateT * v963) {
  int v964 = v963->timer;
  int v975 = v964 + 1;
  v963->timer = v975;
  int * v966 = v963->reg_ready;
  int v967 = v966[8];
  int * v968 = v963->regs;
  int v969 = v968[8];
  int v979 = (v967 + ((v964 - v967) & (~((v964 - v967) >> 31)))) + 1;
  v966[8] = v979;
  int * v971 = v963->regs;
  int v981 = v969 + 1;
  v971[8] = v981;
  struct StateT * v973 = slot_21(v963);
  return v973;
}

struct StateT * slot_141(struct StateT * v3504) {
  int v3505 = v3504->timer;
  int v3516 = v3505 + 1;
  v3504->timer = v3516;
  int * v3507 = v3504->reg_ready;
  int v3508 = v3507[8];
  int * v3509 = v3504->regs;
  int v3510 = v3509[8];
  int v3520 = (v3508 + ((v3505 - v3508) & (~((v3505 - v3508) >> 31)))) + 1;
  v3507[8] = v3520;
  int * v3512 = v3504->regs;
  int v3522 = v3510 + 1;
  v3512[8] = v3522;
  struct StateT * v3514 = slot_142(v3504);
  return v3514;
}

struct StateT * slot_61(struct StateT * v1824) {
  int v1825 = v1824->timer;
  int v1836 = v1825 + 1;
  v1824->timer = v1836;
  int * v1827 = v1824->reg_ready;
  int v1828 = v1827[8];
  int * v1829 = v1824->regs;
  int v1830 = v1829[8];
  int v1840 = (v1828 + ((v1825 - v1828) & (~((v1825 - v1828) >> 31)))) + 1;
  v1827[8] = v1840;
  int * v1832 = v1824->regs;
  int v1842 = v1830 + 1;
  v1832[8] = v1842;
  struct StateT * v1834 = slot_62(v1824);
  return v1834;
}

struct StateT * slot_30(struct StateT * v1173) {
  int v1174 = v1173->timer;
  int v1185 = v1174 + 1;
  v1173->timer = v1185;
  int * v1176 = v1173->reg_ready;
  int v1177 = v1176[8];
  int * v1178 = v1173->regs;
  int v1179 = v1178[8];
  int v1189 = (v1177 + ((v1174 - v1177) & (~((v1174 - v1177) >> 31)))) + 1;
  v1176[8] = v1189;
  int * v1181 = v1173->regs;
  int v1191 = v1179 + 1;
  v1181[8] = v1191;
  struct StateT * v1183 = slot_31(v1173);
  return v1183;
}

struct StateT * slot_4(struct StateT * v445) {
  int v446 = v445->timer;
  int v558 = v446 + 1;
  v445->timer = v558;
  int * v448 = v445->reg_ready;
  int v449 = v448[6];
  int * v450 = v445->regs;
  int v451 = v450[6];
  int * v452 = v445->cache_tags;
  int v563 = (((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2;
  int v453 = v452[v563];
  int v564 = ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + 1;
  int v454 = v452[v564];
  int v565 = 4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2);
  int v455 = v452[v565];
  int v566 = (4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v456 = v452[v566];
  int * v457 = v445->cache_vals;
  bool v567 = !(((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) == 0);
  int v550;
  if (v567) {
    int * v458 = v445->cache_age;
    int v569 = ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) & 1);
    int v459 = v458[v569];
    int v460 = v458[v563];
    int v570 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
    v458[v563] = v570;
    int * v462 = v445->cache_age;
    int v463 = v462[v564];
    int v572 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
    v462[v564] = v572;
    int * v465 = v445->cache_age;
    v465[v569] = 0;
    v550 = v569;
  } else {
    int * v468 = v445->cache_age;
    int v576 = (((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2;
    int v469 = v468[v576];
    int * v470 = v445->cache_tags;
    int v471 = v470[v576];
    int v472 = v468[v564];
    int v473 = v470[v564];
    bool v578 = !(((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) == 0);
    int v527;
    if (v578) {
      int * v474 = v445->cache_age;
      int v580 = (4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) & 1);
      int v475 = v474[v580];
      int v476 = v474[v565];
      int v581 = v476 + ((int)((unsigned int)(v476 - v475) >> 31));
      v474[v565] = v581;
      int * v478 = v445->cache_age;
      int v479 = v478[v566];
      int v583 = v479 + ((int)((unsigned int)(v479 - v475) >> 31));
      v478[v566] = v583;
      int * v481 = v445->cache_age;
      v481[v580] = 0;
      v527 = v580;
    } else {
      int * v484 = v445->cache_age;
      int v587 = 4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2);
      int v485 = v484[v587];
      int * v486 = v445->cache_tags;
      int v487 = v486[v587];
      int v488 = v484[v566];
      int v489 = v486[v566];
      int * v490 = v445->cache_dirty;
      int v590 = (4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v491 = v490[v590];
      bool v591 = !(v491 == 0);
      if (v591) {
        int * v492 = v445->cache_tags;
        int v493 = v492[v590];
        int * v494 = v445->cache_vals;
        int v594 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v495 = v494[v594];
        int v595 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v496 = v494[v595];
        int * v497 = v445->mem;
        int v597 = v493 * 2;
        v497[v597] = v495;
        int * v499 = v445->mem;
        int v600 = (v493 * 2) + 1;
        v499[v600] = v496;
        ;
      } else {
        ;
      }
      int * v504 = v445->mem;
      int v605 = ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) * 2;
      int v505 = v504[v605];
      int v606 = (((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) * 2) + 1;
      int v506 = v504[v606];
      int * v507 = v445->cache_vals;
      int v608 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v507[v608] = v505;
      int * v509 = v445->cache_vals;
      int v611 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 3) * 2)) + ((((v485 + ((~(((v487 ^ -1) | (-(v487 ^ -1))) >> 31)) & 2)) - (v488 + ((~(((v489 ^ -1) | (-(v489 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v509[v611] = v506;
      int * v511 = v445->cache_tags;
      int v614 = (int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1);
      v511[v590] = v614;
      int * v513 = v445->cache_dirty;
      v513[v590] = 0;
      int * v515 = v445->cache_age;
      v515[v590] = 1;
      int * v517 = v445->cache_age;
      int v518 = v517[v590];
      int v519 = v517[v565];
      int v620 = v519 + ((int)((unsigned int)(v519 - v518) >> 31));
      v517[v565] = v620;
      int * v521 = v445->cache_age;
      int v522 = v521[v566];
      int v622 = v522 + ((int)((unsigned int)(v522 - v518) >> 31));
      v521[v566] = v622;
      int * v524 = v445->cache_age;
      v524[v590] = 0;
      v527 = v590;
    }
    int * v528 = v445->cache_vals;
    int v625 = v527 * 2;
    int v529 = v528[v625];
    int v626 = (v527 * 2) + 1;
    int v530 = v528[v626];
    int v627 = (((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v528[v627] = v529;
    int * v532 = v445->cache_vals;
    int v630 = ((((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v532[v630] = v530;
    int * v534 = v445->cache_tags;
    int v633 = ((((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1)) & 1) * 2) + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v634 = (int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1);
    v534[v633] = v634;
    int * v536 = v445->cache_dirty;
    v536[v633] = 0;
    int * v538 = v445->cache_age;
    v538[v633] = 1;
    int * v540 = v445->cache_age;
    int v541 = v540[v633];
    int v542 = v540[v563];
    int v640 = v542 + ((int)((unsigned int)(v542 - v541) >> 31));
    v540[v563] = v640;
    int * v544 = v445->cache_age;
    int v545 = v544[v564];
    int v642 = v545 + ((int)((unsigned int)(v545 - v541) >> 31));
    v544[v564] = v642;
    int * v547 = v445->cache_age;
    v547[v633] = 0;
    v550 = v633;
  }
  int v645 = (v550 * 2) + (((int)((unsigned int)v451 >> 2)) & 1);
  int v551 = v457[v645];
  int * v552 = v445->reg_ready;
  int v648 = ((v449 + ((v446 - v449) & (~((v446 - v449) >> 31)))) + 1) + ((100 ^ (((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v453 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v455 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v451 >> 2)) >> 1))))) >> 31))) & 104)))));
  v552[7] = v648;
  int * v554 = v445->regs;
  v554[7] = v551;
  struct StateT * v556 = slot_5(v445);
  return v556;
}

struct StateT * slot_18(struct StateT * v921) {
  int v922 = v921->timer;
  int v933 = v922 + 1;
  v921->timer = v933;
  int * v924 = v921->reg_ready;
  int v925 = v924[8];
  int * v926 = v921->regs;
  int v927 = v926[8];
  int v937 = (v925 + ((v922 - v925) & (~((v922 - v925) >> 31)))) + 1;
  v924[8] = v937;
  int * v929 = v921->regs;
  int v939 = v927 + 1;
  v929[8] = v939;
  struct StateT * v931 = slot_19(v921);
  return v931;
}

struct StateT * slot_9(struct StateT * v732) {
  int v733 = v732->timer;
  int v744 = v733 + 1;
  v732->timer = v744;
  int * v735 = v732->reg_ready;
  int v736 = v735[8];
  int * v737 = v732->regs;
  int v738 = v737[8];
  int v748 = (v736 + ((v733 - v736) & (~((v733 - v736) >> 31)))) + 1;
  v735[8] = v748;
  int * v740 = v732->regs;
  int v750 = v738 + 1;
  v740[8] = v750;
  struct StateT * v742 = slot_10(v732);
  return v742;
}

struct StateT * slot_183(struct StateT * v4386) {
  int v4387 = v4386->timer;
  int v4398 = v4387 + 1;
  v4386->timer = v4398;
  int * v4389 = v4386->reg_ready;
  int v4390 = v4389[8];
  int * v4391 = v4386->regs;
  int v4392 = v4391[8];
  int v4402 = (v4390 + ((v4387 - v4390) & (~((v4387 - v4390) >> 31)))) + 1;
  v4389[8] = v4402;
  int * v4394 = v4386->regs;
  int v4404 = v4392 + 1;
  v4394[8] = v4404;
  struct StateT * v4396 = slot_184(v4386);
  return v4396;
}

struct StateT * slot_43(struct StateT * v1446) {
  int v1447 = v1446->timer;
  int v1458 = v1447 + 1;
  v1446->timer = v1458;
  int * v1449 = v1446->reg_ready;
  int v1450 = v1449[8];
  int * v1451 = v1446->regs;
  int v1452 = v1451[8];
  int v1462 = (v1450 + ((v1447 - v1450) & (~((v1447 - v1450) >> 31)))) + 1;
  v1449[8] = v1462;
  int * v1454 = v1446->regs;
  int v1464 = v1452 + 1;
  v1454[8] = v1464;
  struct StateT * v1456 = slot_44(v1446);
  return v1456;
}

struct StateT * slot_70(struct StateT * v2013) {
  int v2014 = v2013->timer;
  int v2025 = v2014 + 1;
  v2013->timer = v2025;
  int * v2016 = v2013->reg_ready;
  int v2017 = v2016[8];
  int * v2018 = v2013->regs;
  int v2019 = v2018[8];
  int v2029 = (v2017 + ((v2014 - v2017) & (~((v2014 - v2017) >> 31)))) + 1;
  v2016[8] = v2029;
  int * v2021 = v2013->regs;
  int v2031 = v2019 + 1;
  v2021[8] = v2031;
  struct StateT * v2023 = slot_71(v2013);
  return v2023;
}

struct StateT * slot_168(struct StateT * v4071) {
  int v4072 = v4071->timer;
  int v4083 = v4072 + 1;
  v4071->timer = v4083;
  int * v4074 = v4071->reg_ready;
  int v4075 = v4074[8];
  int * v4076 = v4071->regs;
  int v4077 = v4076[8];
  int v4087 = (v4075 + ((v4072 - v4075) & (~((v4072 - v4075) >> 31)))) + 1;
  v4074[8] = v4087;
  int * v4079 = v4071->regs;
  int v4089 = v4077 + 1;
  v4079[8] = v4089;
  struct StateT * v4081 = slot_169(v4071);
  return v4081;
}

struct StateT * slot_76(struct StateT * v2139) {
  int v2140 = v2139->timer;
  int v2151 = v2140 + 1;
  v2139->timer = v2151;
  int * v2142 = v2139->reg_ready;
  int v2143 = v2142[8];
  int * v2144 = v2139->regs;
  int v2145 = v2144[8];
  int v2155 = (v2143 + ((v2140 - v2143) & (~((v2140 - v2143) >> 31)))) + 1;
  v2142[8] = v2155;
  int * v2147 = v2139->regs;
  int v2157 = v2145 + 1;
  v2147[8] = v2157;
  struct StateT * v2149 = slot_77(v2139);
  return v2149;
}

struct StateT * slot_6(struct StateT * v669) {
  int v670 = v669->timer;
  int v681 = v670 + 1;
  v669->timer = v681;
  int * v672 = v669->reg_ready;
  int v673 = v672[8];
  int * v674 = v669->regs;
  int v675 = v674[8];
  int v685 = (v673 + ((v670 - v673) & (~((v670 - v673) >> 31)))) + 1;
  v672[8] = v685;
  int * v677 = v669->regs;
  int v687 = v675 + 1;
  v677[8] = v687;
  struct StateT * v679 = slot_7(v669);
  return v679;
}

struct StateT * slot_225(struct StateT * v5268) {
  int v5269 = v5268->timer;
  int v5279 = v5269 + 1;
  v5268->timer = v5279;
  int * v5271 = v5268->reg_ready;
  int v5272 = v5271[8];
  int * v5273 = v5268->regs;
  int v5274 = v5273[8];
  int v5283 = (v5272 + ((v5269 - v5272) & (~((v5269 - v5272) >> 31)))) + 1;
  v5271[8] = v5283;
  int * v5276 = v5268->regs;
  int v5285 = v5274 + 1;
  v5276[8] = v5285;
  return v5268;
}

struct StateT * slot_55(struct StateT * v1698) {
  int v1699 = v1698->timer;
  int v1710 = v1699 + 1;
  v1698->timer = v1710;
  int * v1701 = v1698->reg_ready;
  int v1702 = v1701[8];
  int * v1703 = v1698->regs;
  int v1704 = v1703[8];
  int v1714 = (v1702 + ((v1699 - v1702) & (~((v1699 - v1702) >> 31)))) + 1;
  v1701[8] = v1714;
  int * v1706 = v1698->regs;
  int v1716 = v1704 + 1;
  v1706[8] = v1716;
  struct StateT * v1708 = slot_56(v1698);
  return v1708;
}

struct StateT * slot_213(struct StateT * v5016) {
  int v5017 = v5016->timer;
  int v5028 = v5017 + 1;
  v5016->timer = v5028;
  int * v5019 = v5016->reg_ready;
  int v5020 = v5019[8];
  int * v5021 = v5016->regs;
  int v5022 = v5021[8];
  int v5032 = (v5020 + ((v5017 - v5020) & (~((v5017 - v5020) >> 31)))) + 1;
  v5019[8] = v5032;
  int * v5024 = v5016->regs;
  int v5034 = v5022 + 1;
  v5024[8] = v5034;
  struct StateT * v5026 = slot_214(v5016);
  return v5026;
}

struct StateT * slot_82(struct StateT * v2265) {
  int v2266 = v2265->timer;
  int v2277 = v2266 + 1;
  v2265->timer = v2277;
  int * v2268 = v2265->reg_ready;
  int v2269 = v2268[8];
  int * v2270 = v2265->regs;
  int v2271 = v2270[8];
  int v2281 = (v2269 + ((v2266 - v2269) & (~((v2266 - v2269) >> 31)))) + 1;
  v2268[8] = v2281;
  int * v2273 = v2265->regs;
  int v2283 = v2271 + 1;
  v2273[8] = v2283;
  struct StateT * v2275 = slot_83(v2265);
  return v2275;
}

struct StateT * slot_161(struct StateT * v3924) {
  int v3925 = v3924->timer;
  int v3936 = v3925 + 1;
  v3924->timer = v3936;
  int * v3927 = v3924->reg_ready;
  int v3928 = v3927[8];
  int * v3929 = v3924->regs;
  int v3930 = v3929[8];
  int v3940 = (v3928 + ((v3925 - v3928) & (~((v3925 - v3928) >> 31)))) + 1;
  v3927[8] = v3940;
  int * v3932 = v3924->regs;
  int v3942 = v3930 + 1;
  v3932[8] = v3942;
  struct StateT * v3934 = slot_162(v3924);
  return v3934;
}

struct StateT * slot_185(struct StateT * v4428) {
  int v4429 = v4428->timer;
  int v4440 = v4429 + 1;
  v4428->timer = v4440;
  int * v4431 = v4428->reg_ready;
  int v4432 = v4431[8];
  int * v4433 = v4428->regs;
  int v4434 = v4433[8];
  int v4444 = (v4432 + ((v4429 - v4432) & (~((v4429 - v4432) >> 31)))) + 1;
  v4431[8] = v4444;
  int * v4436 = v4428->regs;
  int v4446 = v4434 + 1;
  v4436[8] = v4446;
  struct StateT * v4438 = slot_186(v4428);
  return v4438;
}

struct StateT * slot_91(struct StateT * v2454) {
  int v2455 = v2454->timer;
  int v2466 = v2455 + 1;
  v2454->timer = v2466;
  int * v2457 = v2454->reg_ready;
  int v2458 = v2457[8];
  int * v2459 = v2454->regs;
  int v2460 = v2459[8];
  int v2470 = (v2458 + ((v2455 - v2458) & (~((v2455 - v2458) >> 31)))) + 1;
  v2457[8] = v2470;
  int * v2462 = v2454->regs;
  int v2472 = v2460 + 1;
  v2462[8] = v2472;
  struct StateT * v2464 = slot_92(v2454);
  return v2464;
}

struct StateT * slot_58(struct StateT * v1761) {
  int v1762 = v1761->timer;
  int v1773 = v1762 + 1;
  v1761->timer = v1773;
  int * v1764 = v1761->reg_ready;
  int v1765 = v1764[8];
  int * v1766 = v1761->regs;
  int v1767 = v1766[8];
  int v1777 = (v1765 + ((v1762 - v1765) & (~((v1762 - v1765) >> 31)))) + 1;
  v1764[8] = v1777;
  int * v1769 = v1761->regs;
  int v1779 = v1767 + 1;
  v1769[8] = v1779;
  struct StateT * v1771 = slot_59(v1761);
  return v1771;
}

struct StateT * slot_89(struct StateT * v2412) {
  int v2413 = v2412->timer;
  int v2424 = v2413 + 1;
  v2412->timer = v2424;
  int * v2415 = v2412->reg_ready;
  int v2416 = v2415[8];
  int * v2417 = v2412->regs;
  int v2418 = v2417[8];
  int v2428 = (v2416 + ((v2413 - v2416) & (~((v2413 - v2416) >> 31)))) + 1;
  v2415[8] = v2428;
  int * v2420 = v2412->regs;
  int v2430 = v2418 + 1;
  v2420[8] = v2430;
  struct StateT * v2422 = slot_90(v2412);
  return v2422;
}

struct StateT * slot_66(struct StateT * v1929) {
  int v1930 = v1929->timer;
  int v1941 = v1930 + 1;
  v1929->timer = v1941;
  int * v1932 = v1929->reg_ready;
  int v1933 = v1932[8];
  int * v1934 = v1929->regs;
  int v1935 = v1934[8];
  int v1945 = (v1933 + ((v1930 - v1933) & (~((v1930 - v1933) >> 31)))) + 1;
  v1932[8] = v1945;
  int * v1937 = v1929->regs;
  int v1947 = v1935 + 1;
  v1937[8] = v1947;
  struct StateT * v1939 = slot_67(v1929);
  return v1939;
}

struct StateT * slot_140(struct StateT * v3483) {
  int v3484 = v3483->timer;
  int v3495 = v3484 + 1;
  v3483->timer = v3495;
  int * v3486 = v3483->reg_ready;
  int v3487 = v3486[8];
  int * v3488 = v3483->regs;
  int v3489 = v3488[8];
  int v3499 = (v3487 + ((v3484 - v3487) & (~((v3484 - v3487) >> 31)))) + 1;
  v3486[8] = v3499;
  int * v3491 = v3483->regs;
  int v3501 = v3489 + 1;
  v3491[8] = v3501;
  struct StateT * v3493 = slot_141(v3483);
  return v3493;
}

struct StateT * slot_49(struct StateT * v1572) {
  int v1573 = v1572->timer;
  int v1584 = v1573 + 1;
  v1572->timer = v1584;
  int * v1575 = v1572->reg_ready;
  int v1576 = v1575[8];
  int * v1577 = v1572->regs;
  int v1578 = v1577[8];
  int v1588 = (v1576 + ((v1573 - v1576) & (~((v1573 - v1576) >> 31)))) + 1;
  v1575[8] = v1588;
  int * v1580 = v1572->regs;
  int v1590 = v1578 + 1;
  v1580[8] = v1590;
  struct StateT * v1582 = slot_50(v1572);
  return v1582;
}

struct StateT * slot_216(struct StateT * v5079) {
  int v5080 = v5079->timer;
  int v5091 = v5080 + 1;
  v5079->timer = v5091;
  int * v5082 = v5079->reg_ready;
  int v5083 = v5082[8];
  int * v5084 = v5079->regs;
  int v5085 = v5084[8];
  int v5095 = (v5083 + ((v5080 - v5083) & (~((v5080 - v5083) >> 31)))) + 1;
  v5082[8] = v5095;
  int * v5087 = v5079->regs;
  int v5097 = v5085 + 1;
  v5087[8] = v5097;
  struct StateT * v5089 = slot_217(v5079);
  return v5089;
}

struct StateT * slot_50(struct StateT * v1593) {
  int v1594 = v1593->timer;
  int v1605 = v1594 + 1;
  v1593->timer = v1605;
  int * v1596 = v1593->reg_ready;
  int v1597 = v1596[8];
  int * v1598 = v1593->regs;
  int v1599 = v1598[8];
  int v1609 = (v1597 + ((v1594 - v1597) & (~((v1594 - v1597) >> 31)))) + 1;
  v1596[8] = v1609;
  int * v1601 = v1593->regs;
  int v1611 = v1599 + 1;
  v1601[8] = v1611;
  struct StateT * v1603 = slot_51(v1593);
  return v1603;
}

struct StateT * slot_37(struct StateT * v1320) {
  int v1321 = v1320->timer;
  int v1332 = v1321 + 1;
  v1320->timer = v1332;
  int * v1323 = v1320->reg_ready;
  int v1324 = v1323[8];
  int * v1325 = v1320->regs;
  int v1326 = v1325[8];
  int v1336 = (v1324 + ((v1321 - v1324) & (~((v1321 - v1324) >> 31)))) + 1;
  v1323[8] = v1336;
  int * v1328 = v1320->regs;
  int v1338 = v1326 + 1;
  v1328[8] = v1338;
  struct StateT * v1330 = slot_38(v1320);
  return v1330;
}

struct StateT * slot_114(struct StateT * v2937) {
  int v2938 = v2937->timer;
  int v2949 = v2938 + 1;
  v2937->timer = v2949;
  int * v2940 = v2937->reg_ready;
  int v2941 = v2940[8];
  int * v2942 = v2937->regs;
  int v2943 = v2942[8];
  int v2953 = (v2941 + ((v2938 - v2941) & (~((v2938 - v2941) >> 31)))) + 1;
  v2940[8] = v2953;
  int * v2945 = v2937->regs;
  int v2955 = v2943 + 1;
  v2945[8] = v2955;
  struct StateT * v2947 = slot_115(v2937);
  return v2947;
}

struct StateT * slot_135(struct StateT * v3378) {
  int v3379 = v3378->timer;
  int v3390 = v3379 + 1;
  v3378->timer = v3390;
  int * v3381 = v3378->reg_ready;
  int v3382 = v3381[8];
  int * v3383 = v3378->regs;
  int v3384 = v3383[8];
  int v3394 = (v3382 + ((v3379 - v3382) & (~((v3379 - v3382) >> 31)))) + 1;
  v3381[8] = v3394;
  int * v3386 = v3378->regs;
  int v3396 = v3384 + 1;
  v3386[8] = v3396;
  struct StateT * v3388 = slot_136(v3378);
  return v3388;
}

struct StateT * slot_59(struct StateT * v1782) {
  int v1783 = v1782->timer;
  int v1794 = v1783 + 1;
  v1782->timer = v1794;
  int * v1785 = v1782->reg_ready;
  int v1786 = v1785[8];
  int * v1787 = v1782->regs;
  int v1788 = v1787[8];
  int v1798 = (v1786 + ((v1783 - v1786) & (~((v1783 - v1786) >> 31)))) + 1;
  v1785[8] = v1798;
  int * v1790 = v1782->regs;
  int v1800 = v1788 + 1;
  v1790[8] = v1800;
  struct StateT * v1792 = slot_60(v1782);
  return v1792;
}

struct StateT * slot_192(struct StateT * v4575) {
  int v4576 = v4575->timer;
  int v4587 = v4576 + 1;
  v4575->timer = v4587;
  int * v4578 = v4575->reg_ready;
  int v4579 = v4578[8];
  int * v4580 = v4575->regs;
  int v4581 = v4580[8];
  int v4591 = (v4579 + ((v4576 - v4579) & (~((v4576 - v4579) >> 31)))) + 1;
  v4578[8] = v4591;
  int * v4583 = v4575->regs;
  int v4593 = v4581 + 1;
  v4583[8] = v4593;
  struct StateT * v4585 = slot_193(v4575);
  return v4585;
}

struct StateT * slot_40(struct StateT * v1383) {
  int v1384 = v1383->timer;
  int v1395 = v1384 + 1;
  v1383->timer = v1395;
  int * v1386 = v1383->reg_ready;
  int v1387 = v1386[8];
  int * v1388 = v1383->regs;
  int v1389 = v1388[8];
  int v1399 = (v1387 + ((v1384 - v1387) & (~((v1384 - v1387) >> 31)))) + 1;
  v1386[8] = v1399;
  int * v1391 = v1383->regs;
  int v1401 = v1389 + 1;
  v1391[8] = v1401;
  struct StateT * v1393 = slot_41(v1383);
  return v1393;
}

struct StateT * slot_48(struct StateT * v1551) {
  int v1552 = v1551->timer;
  int v1563 = v1552 + 1;
  v1551->timer = v1563;
  int * v1554 = v1551->reg_ready;
  int v1555 = v1554[8];
  int * v1556 = v1551->regs;
  int v1557 = v1556[8];
  int v1567 = (v1555 + ((v1552 - v1555) & (~((v1552 - v1555) >> 31)))) + 1;
  v1554[8] = v1567;
  int * v1559 = v1551->regs;
  int v1569 = v1557 + 1;
  v1559[8] = v1569;
  struct StateT * v1561 = slot_49(v1551);
  return v1561;
}

struct StateT * slot_77(struct StateT * v2160) {
  int v2161 = v2160->timer;
  int v2172 = v2161 + 1;
  v2160->timer = v2172;
  int * v2163 = v2160->reg_ready;
  int v2164 = v2163[8];
  int * v2165 = v2160->regs;
  int v2166 = v2165[8];
  int v2176 = (v2164 + ((v2161 - v2164) & (~((v2161 - v2164) >> 31)))) + 1;
  v2163[8] = v2176;
  int * v2168 = v2160->regs;
  int v2178 = v2166 + 1;
  v2168[8] = v2178;
  struct StateT * v2170 = slot_78(v2160);
  return v2170;
}

struct StateT * slot_85(struct StateT * v2328) {
  int v2329 = v2328->timer;
  int v2340 = v2329 + 1;
  v2328->timer = v2340;
  int * v2331 = v2328->reg_ready;
  int v2332 = v2331[8];
  int * v2333 = v2328->regs;
  int v2334 = v2333[8];
  int v2344 = (v2332 + ((v2329 - v2332) & (~((v2329 - v2332) >> 31)))) + 1;
  v2331[8] = v2344;
  int * v2336 = v2328->regs;
  int v2346 = v2334 + 1;
  v2336[8] = v2346;
  struct StateT * v2338 = slot_86(v2328);
  return v2338;
}

struct StateT * slot_75(struct StateT * v2118) {
  int v2119 = v2118->timer;
  int v2130 = v2119 + 1;
  v2118->timer = v2130;
  int * v2121 = v2118->reg_ready;
  int v2122 = v2121[8];
  int * v2123 = v2118->regs;
  int v2124 = v2123[8];
  int v2134 = (v2122 + ((v2119 - v2122) & (~((v2119 - v2122) >> 31)))) + 1;
  v2121[8] = v2134;
  int * v2126 = v2118->regs;
  int v2136 = v2124 + 1;
  v2126[8] = v2136;
  struct StateT * v2128 = slot_76(v2118);
  return v2128;
}

struct StateT * slot_72(struct StateT * v2055) {
  int v2056 = v2055->timer;
  int v2067 = v2056 + 1;
  v2055->timer = v2067;
  int * v2058 = v2055->reg_ready;
  int v2059 = v2058[8];
  int * v2060 = v2055->regs;
  int v2061 = v2060[8];
  int v2071 = (v2059 + ((v2056 - v2059) & (~((v2056 - v2059) >> 31)))) + 1;
  v2058[8] = v2071;
  int * v2063 = v2055->regs;
  int v2073 = v2061 + 1;
  v2063[8] = v2073;
  struct StateT * v2065 = slot_73(v2055);
  return v2065;
}

struct StateT * slot_119(struct StateT * v3042) {
  int v3043 = v3042->timer;
  int v3054 = v3043 + 1;
  v3042->timer = v3054;
  int * v3045 = v3042->reg_ready;
  int v3046 = v3045[8];
  int * v3047 = v3042->regs;
  int v3048 = v3047[8];
  int v3058 = (v3046 + ((v3043 - v3046) & (~((v3043 - v3046) >> 31)))) + 1;
  v3045[8] = v3058;
  int * v3050 = v3042->regs;
  int v3060 = v3048 + 1;
  v3050[8] = v3060;
  struct StateT * v3052 = slot_120(v3042);
  return v3052;
}

struct StateT * slot_71(struct StateT * v2034) {
  int v2035 = v2034->timer;
  int v2046 = v2035 + 1;
  v2034->timer = v2046;
  int * v2037 = v2034->reg_ready;
  int v2038 = v2037[8];
  int * v2039 = v2034->regs;
  int v2040 = v2039[8];
  int v2050 = (v2038 + ((v2035 - v2038) & (~((v2035 - v2038) >> 31)))) + 1;
  v2037[8] = v2050;
  int * v2042 = v2034->regs;
  int v2052 = v2040 + 1;
  v2042[8] = v2052;
  struct StateT * v2044 = slot_72(v2034);
  return v2044;
}

struct StateT * slot_101(struct StateT * v2664) {
  int v2665 = v2664->timer;
  int v2676 = v2665 + 1;
  v2664->timer = v2676;
  int * v2667 = v2664->reg_ready;
  int v2668 = v2667[8];
  int * v2669 = v2664->regs;
  int v2670 = v2669[8];
  int v2680 = (v2668 + ((v2665 - v2668) & (~((v2665 - v2668) >> 31)))) + 1;
  v2667[8] = v2680;
  int * v2672 = v2664->regs;
  int v2682 = v2670 + 1;
  v2672[8] = v2682;
  struct StateT * v2674 = slot_102(v2664);
  return v2674;
}

struct StateT * slot_108(struct StateT * v2811) {
  int v2812 = v2811->timer;
  int v2823 = v2812 + 1;
  v2811->timer = v2823;
  int * v2814 = v2811->reg_ready;
  int v2815 = v2814[8];
  int * v2816 = v2811->regs;
  int v2817 = v2816[8];
  int v2827 = (v2815 + ((v2812 - v2815) & (~((v2812 - v2815) >> 31)))) + 1;
  v2814[8] = v2827;
  int * v2819 = v2811->regs;
  int v2829 = v2817 + 1;
  v2819[8] = v2829;
  struct StateT * v2821 = slot_109(v2811);
  return v2821;
}

struct StateT * slot_116(struct StateT * v2979) {
  int v2980 = v2979->timer;
  int v2991 = v2980 + 1;
  v2979->timer = v2991;
  int * v2982 = v2979->reg_ready;
  int v2983 = v2982[8];
  int * v2984 = v2979->regs;
  int v2985 = v2984[8];
  int v2995 = (v2983 + ((v2980 - v2983) & (~((v2980 - v2983) >> 31)))) + 1;
  v2982[8] = v2995;
  int * v2987 = v2979->regs;
  int v2997 = v2985 + 1;
  v2987[8] = v2997;
  struct StateT * v2989 = slot_117(v2979);
  return v2989;
}

struct StateT * slot_93(struct StateT * v2496) {
  int v2497 = v2496->timer;
  int v2508 = v2497 + 1;
  v2496->timer = v2508;
  int * v2499 = v2496->reg_ready;
  int v2500 = v2499[8];
  int * v2501 = v2496->regs;
  int v2502 = v2501[8];
  int v2512 = (v2500 + ((v2497 - v2500) & (~((v2497 - v2500) >> 31)))) + 1;
  v2499[8] = v2512;
  int * v2504 = v2496->regs;
  int v2514 = v2502 + 1;
  v2504[8] = v2514;
  struct StateT * v2506 = slot_94(v2496);
  return v2506;
}

struct StateT * slot_88(struct StateT * v2391) {
  int v2392 = v2391->timer;
  int v2403 = v2392 + 1;
  v2391->timer = v2403;
  int * v2394 = v2391->reg_ready;
  int v2395 = v2394[8];
  int * v2396 = v2391->regs;
  int v2397 = v2396[8];
  int v2407 = (v2395 + ((v2392 - v2395) & (~((v2392 - v2395) >> 31)))) + 1;
  v2394[8] = v2407;
  int * v2399 = v2391->regs;
  int v2409 = v2397 + 1;
  v2399[8] = v2409;
  struct StateT * v2401 = slot_89(v2391);
  return v2401;
}

struct StateT * slot_96(struct StateT * v2559) {
  int v2560 = v2559->timer;
  int v2571 = v2560 + 1;
  v2559->timer = v2571;
  int * v2562 = v2559->reg_ready;
  int v2563 = v2562[8];
  int * v2564 = v2559->regs;
  int v2565 = v2564[8];
  int v2575 = (v2563 + ((v2560 - v2563) & (~((v2560 - v2563) >> 31)))) + 1;
  v2562[8] = v2575;
  int * v2567 = v2559->regs;
  int v2577 = v2565 + 1;
  v2567[8] = v2577;
  struct StateT * v2569 = slot_97(v2559);
  return v2569;
}

struct StateT * slot_215(struct StateT * v5058) {
  int v5059 = v5058->timer;
  int v5070 = v5059 + 1;
  v5058->timer = v5070;
  int * v5061 = v5058->reg_ready;
  int v5062 = v5061[8];
  int * v5063 = v5058->regs;
  int v5064 = v5063[8];
  int v5074 = (v5062 + ((v5059 - v5062) & (~((v5059 - v5062) >> 31)))) + 1;
  v5061[8] = v5074;
  int * v5066 = v5058->regs;
  int v5076 = v5064 + 1;
  v5066[8] = v5076;
  struct StateT * v5068 = slot_216(v5058);
  return v5068;
}

struct StateT * slot_45(struct StateT * v1488) {
  int v1489 = v1488->timer;
  int v1500 = v1489 + 1;
  v1488->timer = v1500;
  int * v1491 = v1488->reg_ready;
  int v1492 = v1491[8];
  int * v1493 = v1488->regs;
  int v1494 = v1493[8];
  int v1504 = (v1492 + ((v1489 - v1492) & (~((v1489 - v1492) >> 31)))) + 1;
  v1491[8] = v1504;
  int * v1496 = v1488->regs;
  int v1506 = v1494 + 1;
  v1496[8] = v1506;
  struct StateT * v1498 = slot_46(v1488);
  return v1498;
}

struct StateT * slot_218(struct StateT * v5121) {
  int v5122 = v5121->timer;
  int v5133 = v5122 + 1;
  v5121->timer = v5133;
  int * v5124 = v5121->reg_ready;
  int v5125 = v5124[8];
  int * v5126 = v5121->regs;
  int v5127 = v5126[8];
  int v5137 = (v5125 + ((v5122 - v5125) & (~((v5122 - v5125) >> 31)))) + 1;
  v5124[8] = v5137;
  int * v5129 = v5121->regs;
  int v5139 = v5127 + 1;
  v5129[8] = v5139;
  struct StateT * v5131 = slot_219(v5121);
  return v5131;
}

struct StateT * slot_220(struct StateT * v5163) {
  int v5164 = v5163->timer;
  int v5175 = v5164 + 1;
  v5163->timer = v5175;
  int * v5166 = v5163->reg_ready;
  int v5167 = v5166[8];
  int * v5168 = v5163->regs;
  int v5169 = v5168[8];
  int v5179 = (v5167 + ((v5164 - v5167) & (~((v5164 - v5167) >> 31)))) + 1;
  v5166[8] = v5179;
  int * v5171 = v5163->regs;
  int v5181 = v5169 + 1;
  v5171[8] = v5181;
  struct StateT * v5173 = slot_221(v5163);
  return v5173;
}

struct StateT * slot_134(struct StateT * v3357) {
  int v3358 = v3357->timer;
  int v3369 = v3358 + 1;
  v3357->timer = v3369;
  int * v3360 = v3357->reg_ready;
  int v3361 = v3360[8];
  int * v3362 = v3357->regs;
  int v3363 = v3362[8];
  int v3373 = (v3361 + ((v3358 - v3361) & (~((v3358 - v3361) >> 31)))) + 1;
  v3360[8] = v3373;
  int * v3365 = v3357->regs;
  int v3375 = v3363 + 1;
  v3365[8] = v3375;
  struct StateT * v3367 = slot_135(v3357);
  return v3367;
}

struct StateT * slot_175(struct StateT * v4218) {
  int v4219 = v4218->timer;
  int v4230 = v4219 + 1;
  v4218->timer = v4230;
  int * v4221 = v4218->reg_ready;
  int v4222 = v4221[8];
  int * v4223 = v4218->regs;
  int v4224 = v4223[8];
  int v4234 = (v4222 + ((v4219 - v4222) & (~((v4219 - v4222) >> 31)))) + 1;
  v4221[8] = v4234;
  int * v4226 = v4218->regs;
  int v4236 = v4224 + 1;
  v4226[8] = v4236;
  struct StateT * v4228 = slot_176(v4218);
  return v4228;
}

struct StateT * slot_69(struct StateT * v1992) {
  int v1993 = v1992->timer;
  int v2004 = v1993 + 1;
  v1992->timer = v2004;
  int * v1995 = v1992->reg_ready;
  int v1996 = v1995[8];
  int * v1997 = v1992->regs;
  int v1998 = v1997[8];
  int v2008 = (v1996 + ((v1993 - v1996) & (~((v1993 - v1996) >> 31)))) + 1;
  v1995[8] = v2008;
  int * v2000 = v1992->regs;
  int v2010 = v1998 + 1;
  v2000[8] = v2010;
  struct StateT * v2002 = slot_70(v1992);
  return v2002;
}

struct StateT * slot_202(struct StateT * v4785) {
  int v4786 = v4785->timer;
  int v4797 = v4786 + 1;
  v4785->timer = v4797;
  int * v4788 = v4785->reg_ready;
  int v4789 = v4788[8];
  int * v4790 = v4785->regs;
  int v4791 = v4790[8];
  int v4801 = (v4789 + ((v4786 - v4789) & (~((v4786 - v4789) >> 31)))) + 1;
  v4788[8] = v4801;
  int * v4793 = v4785->regs;
  int v4803 = v4791 + 1;
  v4793[8] = v4803;
  struct StateT * v4795 = slot_203(v4785);
  return v4795;
}

struct StateT * slot_188(struct StateT * v4491) {
  int v4492 = v4491->timer;
  int v4503 = v4492 + 1;
  v4491->timer = v4503;
  int * v4494 = v4491->reg_ready;
  int v4495 = v4494[8];
  int * v4496 = v4491->regs;
  int v4497 = v4496[8];
  int v4507 = (v4495 + ((v4492 - v4495) & (~((v4492 - v4495) >> 31)))) + 1;
  v4494[8] = v4507;
  int * v4499 = v4491->regs;
  int v4509 = v4497 + 1;
  v4499[8] = v4509;
  struct StateT * v4501 = slot_189(v4491);
  return v4501;
}

struct StateT * slot_138(struct StateT * v3441) {
  int v3442 = v3441->timer;
  int v3453 = v3442 + 1;
  v3441->timer = v3453;
  int * v3444 = v3441->reg_ready;
  int v3445 = v3444[8];
  int * v3446 = v3441->regs;
  int v3447 = v3446[8];
  int v3457 = (v3445 + ((v3442 - v3445) & (~((v3442 - v3445) >> 31)))) + 1;
  v3444[8] = v3457;
  int * v3449 = v3441->regs;
  int v3459 = v3447 + 1;
  v3449[8] = v3459;
  struct StateT * v3451 = slot_139(v3441);
  return v3451;
}

struct StateT * slot_186(struct StateT * v4449) {
  int v4450 = v4449->timer;
  int v4461 = v4450 + 1;
  v4449->timer = v4461;
  int * v4452 = v4449->reg_ready;
  int v4453 = v4452[8];
  int * v4454 = v4449->regs;
  int v4455 = v4454[8];
  int v4465 = (v4453 + ((v4450 - v4453) & (~((v4450 - v4453) >> 31)))) + 1;
  v4452[8] = v4465;
  int * v4457 = v4449->regs;
  int v4467 = v4455 + 1;
  v4457[8] = v4467;
  struct StateT * v4459 = slot_187(v4449);
  return v4459;
}

struct StateT * slot_102(struct StateT * v2685) {
  int v2686 = v2685->timer;
  int v2697 = v2686 + 1;
  v2685->timer = v2697;
  int * v2688 = v2685->reg_ready;
  int v2689 = v2688[8];
  int * v2690 = v2685->regs;
  int v2691 = v2690[8];
  int v2701 = (v2689 + ((v2686 - v2689) & (~((v2686 - v2689) >> 31)))) + 1;
  v2688[8] = v2701;
  int * v2693 = v2685->regs;
  int v2703 = v2691 + 1;
  v2693[8] = v2703;
  struct StateT * v2695 = slot_103(v2685);
  return v2695;
}

struct StateT * slot_145(struct StateT * v3588) {
  int v3589 = v3588->timer;
  int v3600 = v3589 + 1;
  v3588->timer = v3600;
  int * v3591 = v3588->reg_ready;
  int v3592 = v3591[8];
  int * v3593 = v3588->regs;
  int v3594 = v3593[8];
  int v3604 = (v3592 + ((v3589 - v3592) & (~((v3589 - v3592) >> 31)))) + 1;
  v3591[8] = v3604;
  int * v3596 = v3588->regs;
  int v3606 = v3594 + 1;
  v3596[8] = v3606;
  struct StateT * v3598 = slot_146(v3588);
  return v3598;
}

struct StateT * slot_110(struct StateT * v2853) {
  int v2854 = v2853->timer;
  int v2865 = v2854 + 1;
  v2853->timer = v2865;
  int * v2856 = v2853->reg_ready;
  int v2857 = v2856[8];
  int * v2858 = v2853->regs;
  int v2859 = v2858[8];
  int v2869 = (v2857 + ((v2854 - v2857) & (~((v2854 - v2857) >> 31)))) + 1;
  v2856[8] = v2869;
  int * v2861 = v2853->regs;
  int v2871 = v2859 + 1;
  v2861[8] = v2871;
  struct StateT * v2863 = slot_111(v2853);
  return v2863;
}

struct StateT * slot_196(struct StateT * v4659) {
  int v4660 = v4659->timer;
  int v4671 = v4660 + 1;
  v4659->timer = v4671;
  int * v4662 = v4659->reg_ready;
  int v4663 = v4662[8];
  int * v4664 = v4659->regs;
  int v4665 = v4664[8];
  int v4675 = (v4663 + ((v4660 - v4663) & (~((v4660 - v4663) >> 31)))) + 1;
  v4662[8] = v4675;
  int * v4667 = v4659->regs;
  int v4677 = v4665 + 1;
  v4667[8] = v4677;
  struct StateT * v4669 = slot_197(v4659);
  return v4669;
}

struct StateT * slot_208(struct StateT * v4911) {
  int v4912 = v4911->timer;
  int v4923 = v4912 + 1;
  v4911->timer = v4923;
  int * v4914 = v4911->reg_ready;
  int v4915 = v4914[8];
  int * v4916 = v4911->regs;
  int v4917 = v4916[8];
  int v4927 = (v4915 + ((v4912 - v4915) & (~((v4912 - v4915) >> 31)))) + 1;
  v4914[8] = v4927;
  int * v4919 = v4911->regs;
  int v4929 = v4917 + 1;
  v4919[8] = v4929;
  struct StateT * v4921 = slot_209(v4911);
  return v4921;
}

struct StateT * slot_172(struct StateT * v4155) {
  int v4156 = v4155->timer;
  int v4167 = v4156 + 1;
  v4155->timer = v4167;
  int * v4158 = v4155->reg_ready;
  int v4159 = v4158[8];
  int * v4160 = v4155->regs;
  int v4161 = v4160[8];
  int v4171 = (v4159 + ((v4156 - v4159) & (~((v4156 - v4159) >> 31)))) + 1;
  v4158[8] = v4171;
  int * v4163 = v4155->regs;
  int v4173 = v4161 + 1;
  v4163[8] = v4173;
  struct StateT * v4165 = slot_173(v4155);
  return v4165;
}

struct StateT * slot_131(struct StateT * v3294) {
  int v3295 = v3294->timer;
  int v3306 = v3295 + 1;
  v3294->timer = v3306;
  int * v3297 = v3294->reg_ready;
  int v3298 = v3297[8];
  int * v3299 = v3294->regs;
  int v3300 = v3299[8];
  int v3310 = (v3298 + ((v3295 - v3298) & (~((v3295 - v3298) >> 31)))) + 1;
  v3297[8] = v3310;
  int * v3302 = v3294->regs;
  int v3312 = v3300 + 1;
  v3302[8] = v3312;
  struct StateT * v3304 = slot_132(v3294);
  return v3304;
}

struct StateT * slot_8(struct StateT * v711) {
  int v712 = v711->timer;
  int v723 = v712 + 1;
  v711->timer = v723;
  int * v714 = v711->reg_ready;
  int v715 = v714[8];
  int * v716 = v711->regs;
  int v717 = v716[8];
  int v727 = (v715 + ((v712 - v715) & (~((v712 - v715) >> 31)))) + 1;
  v714[8] = v727;
  int * v719 = v711->regs;
  int v729 = v717 + 1;
  v719[8] = v729;
  struct StateT * v721 = slot_9(v711);
  return v721;
}

struct StateT * slot_180(struct StateT * v4323) {
  int v4324 = v4323->timer;
  int v4335 = v4324 + 1;
  v4323->timer = v4335;
  int * v4326 = v4323->reg_ready;
  int v4327 = v4326[8];
  int * v4328 = v4323->regs;
  int v4329 = v4328[8];
  int v4339 = (v4327 + ((v4324 - v4327) & (~((v4324 - v4327) >> 31)))) + 1;
  v4326[8] = v4339;
  int * v4331 = v4323->regs;
  int v4341 = v4329 + 1;
  v4331[8] = v4341;
  struct StateT * v4333 = slot_181(v4323);
  return v4333;
}

struct StateT * slot_203(struct StateT * v4806) {
  int v4807 = v4806->timer;
  int v4818 = v4807 + 1;
  v4806->timer = v4818;
  int * v4809 = v4806->reg_ready;
  int v4810 = v4809[8];
  int * v4811 = v4806->regs;
  int v4812 = v4811[8];
  int v4822 = (v4810 + ((v4807 - v4810) & (~((v4807 - v4810) >> 31)))) + 1;
  v4809[8] = v4822;
  int * v4814 = v4806->regs;
  int v4824 = v4812 + 1;
  v4814[8] = v4824;
  struct StateT * v4816 = slot_204(v4806);
  return v4816;
}

struct StateT * slot_190(struct StateT * v4533) {
  int v4534 = v4533->timer;
  int v4545 = v4534 + 1;
  v4533->timer = v4545;
  int * v4536 = v4533->reg_ready;
  int v4537 = v4536[8];
  int * v4538 = v4533->regs;
  int v4539 = v4538[8];
  int v4549 = (v4537 + ((v4534 - v4537) & (~((v4534 - v4537) >> 31)))) + 1;
  v4536[8] = v4549;
  int * v4541 = v4533->regs;
  int v4551 = v4539 + 1;
  v4541[8] = v4551;
  struct StateT * v4543 = slot_191(v4533);
  return v4543;
}

struct StateT * slot_157(struct StateT * v3840) {
  int v3841 = v3840->timer;
  int v3852 = v3841 + 1;
  v3840->timer = v3852;
  int * v3843 = v3840->reg_ready;
  int v3844 = v3843[8];
  int * v3845 = v3840->regs;
  int v3846 = v3845[8];
  int v3856 = (v3844 + ((v3841 - v3844) & (~((v3841 - v3844) >> 31)))) + 1;
  v3843[8] = v3856;
  int * v3848 = v3840->regs;
  int v3858 = v3846 + 1;
  v3848[8] = v3858;
  struct StateT * v3850 = slot_158(v3840);
  return v3850;
}

struct StateT * slot_200(struct StateT * v4743) {
  int v4744 = v4743->timer;
  int v4755 = v4744 + 1;
  v4743->timer = v4755;
  int * v4746 = v4743->reg_ready;
  int v4747 = v4746[8];
  int * v4748 = v4743->regs;
  int v4749 = v4748[8];
  int v4759 = (v4747 + ((v4744 - v4747) & (~((v4744 - v4747) >> 31)))) + 1;
  v4746[8] = v4759;
  int * v4751 = v4743->regs;
  int v4761 = v4749 + 1;
  v4751[8] = v4761;
  struct StateT * v4753 = slot_201(v4743);
  return v4753;
}

struct StateT * slot_173(struct StateT * v4176) {
  int v4177 = v4176->timer;
  int v4188 = v4177 + 1;
  v4176->timer = v4188;
  int * v4179 = v4176->reg_ready;
  int v4180 = v4179[8];
  int * v4181 = v4176->regs;
  int v4182 = v4181[8];
  int v4192 = (v4180 + ((v4177 - v4180) & (~((v4177 - v4180) >> 31)))) + 1;
  v4179[8] = v4192;
  int * v4184 = v4176->regs;
  int v4194 = v4182 + 1;
  v4184[8] = v4194;
  struct StateT * v4186 = slot_174(v4176);
  return v4186;
}

struct StateT * slot_149(struct StateT * v3672) {
  int v3673 = v3672->timer;
  int v3684 = v3673 + 1;
  v3672->timer = v3684;
  int * v3675 = v3672->reg_ready;
  int v3676 = v3675[8];
  int * v3677 = v3672->regs;
  int v3678 = v3677[8];
  int v3688 = (v3676 + ((v3673 - v3676) & (~((v3673 - v3676) >> 31)))) + 1;
  v3675[8] = v3688;
  int * v3680 = v3672->regs;
  int v3690 = v3678 + 1;
  v3680[8] = v3690;
  struct StateT * v3682 = slot_150(v3672);
  return v3682;
}

struct StateT * slot_5(struct StateT * v653) {
  int v654 = v653->timer;
  int v662 = v654 + 1;
  v653->timer = v662;
  int * v656 = v653->reg_ready;
  v656[8] = v662;
  int * v658 = v653->regs;
  v658[8] = 0;
  struct StateT * v660 = slot_6(v653);
  return v660;
}

struct StateT * slot_104(struct StateT * v2727) {
  int v2728 = v2727->timer;
  int v2739 = v2728 + 1;
  v2727->timer = v2739;
  int * v2730 = v2727->reg_ready;
  int v2731 = v2730[8];
  int * v2732 = v2727->regs;
  int v2733 = v2732[8];
  int v2743 = (v2731 + ((v2728 - v2731) & (~((v2728 - v2731) >> 31)))) + 1;
  v2730[8] = v2743;
  int * v2735 = v2727->regs;
  int v2745 = v2733 + 1;
  v2735[8] = v2745;
  struct StateT * v2737 = slot_105(v2727);
  return v2737;
}

struct StateT * slot_54(struct StateT * v1677) {
  int v1678 = v1677->timer;
  int v1689 = v1678 + 1;
  v1677->timer = v1689;
  int * v1680 = v1677->reg_ready;
  int v1681 = v1680[8];
  int * v1682 = v1677->regs;
  int v1683 = v1682[8];
  int v1693 = (v1681 + ((v1678 - v1681) & (~((v1678 - v1681) >> 31)))) + 1;
  v1680[8] = v1693;
  int * v1685 = v1677->regs;
  int v1695 = v1683 + 1;
  v1685[8] = v1695;
  struct StateT * v1687 = slot_55(v1677);
  return v1687;
}

struct StateT * slot_26(struct StateT * v1089) {
  int v1090 = v1089->timer;
  int v1101 = v1090 + 1;
  v1089->timer = v1101;
  int * v1092 = v1089->reg_ready;
  int v1093 = v1092[8];
  int * v1094 = v1089->regs;
  int v1095 = v1094[8];
  int v1105 = (v1093 + ((v1090 - v1093) & (~((v1090 - v1093) >> 31)))) + 1;
  v1092[8] = v1105;
  int * v1097 = v1089->regs;
  int v1107 = v1095 + 1;
  v1097[8] = v1107;
  struct StateT * v1099 = slot_27(v1089);
  return v1099;
}

struct StateT * slot_206(struct StateT * v4869) {
  int v4870 = v4869->timer;
  int v4881 = v4870 + 1;
  v4869->timer = v4881;
  int * v4872 = v4869->reg_ready;
  int v4873 = v4872[8];
  int * v4874 = v4869->regs;
  int v4875 = v4874[8];
  int v4885 = (v4873 + ((v4870 - v4873) & (~((v4870 - v4873) >> 31)))) + 1;
  v4872[8] = v4885;
  int * v4877 = v4869->regs;
  int v4887 = v4875 + 1;
  v4877[8] = v4887;
  struct StateT * v4879 = slot_207(v4869);
  return v4879;
}

struct StateT * slot_169(struct StateT * v4092) {
  int v4093 = v4092->timer;
  int v4104 = v4093 + 1;
  v4092->timer = v4104;
  int * v4095 = v4092->reg_ready;
  int v4096 = v4095[8];
  int * v4097 = v4092->regs;
  int v4098 = v4097[8];
  int v4108 = (v4096 + ((v4093 - v4096) & (~((v4093 - v4096) >> 31)))) + 1;
  v4095[8] = v4108;
  int * v4100 = v4092->regs;
  int v4110 = v4098 + 1;
  v4100[8] = v4110;
  struct StateT * v4102 = slot_170(v4092);
  return v4102;
}

struct StateT * slot_64(struct StateT * v1887) {
  int v1888 = v1887->timer;
  int v1899 = v1888 + 1;
  v1887->timer = v1899;
  int * v1890 = v1887->reg_ready;
  int v1891 = v1890[8];
  int * v1892 = v1887->regs;
  int v1893 = v1892[8];
  int v1903 = (v1891 + ((v1888 - v1891) & (~((v1888 - v1891) >> 31)))) + 1;
  v1890[8] = v1903;
  int * v1895 = v1887->regs;
  int v1905 = v1893 + 1;
  v1895[8] = v1905;
  struct StateT * v1897 = slot_65(v1887);
  return v1897;
}

struct StateT * slot_170(struct StateT * v4113) {
  int v4114 = v4113->timer;
  int v4125 = v4114 + 1;
  v4113->timer = v4125;
  int * v4116 = v4113->reg_ready;
  int v4117 = v4116[8];
  int * v4118 = v4113->regs;
  int v4119 = v4118[8];
  int v4129 = (v4117 + ((v4114 - v4117) & (~((v4114 - v4117) >> 31)))) + 1;
  v4116[8] = v4129;
  int * v4121 = v4113->regs;
  int v4131 = v4119 + 1;
  v4121[8] = v4131;
  struct StateT * v4123 = slot_171(v4113);
  return v4123;
}

struct StateT * slot_14(struct StateT * v837) {
  int v838 = v837->timer;
  int v849 = v838 + 1;
  v837->timer = v849;
  int * v840 = v837->reg_ready;
  int v841 = v840[8];
  int * v842 = v837->regs;
  int v843 = v842[8];
  int v853 = (v841 + ((v838 - v841) & (~((v838 - v841) >> 31)))) + 1;
  v840[8] = v853;
  int * v845 = v837->regs;
  int v855 = v843 + 1;
  v845[8] = v855;
  struct StateT * v847 = slot_15(v837);
  return v847;
}

struct StateT * slot_53(struct StateT * v1656) {
  int v1657 = v1656->timer;
  int v1668 = v1657 + 1;
  v1656->timer = v1668;
  int * v1659 = v1656->reg_ready;
  int v1660 = v1659[8];
  int * v1661 = v1656->regs;
  int v1662 = v1661[8];
  int v1672 = (v1660 + ((v1657 - v1660) & (~((v1657 - v1660) >> 31)))) + 1;
  v1659[8] = v1672;
  int * v1664 = v1656->regs;
  int v1674 = v1662 + 1;
  v1664[8] = v1674;
  struct StateT * v1666 = slot_54(v1656);
  return v1666;
}

struct StateT * slot_80(struct StateT * v2223) {
  int v2224 = v2223->timer;
  int v2235 = v2224 + 1;
  v2223->timer = v2235;
  int * v2226 = v2223->reg_ready;
  int v2227 = v2226[8];
  int * v2228 = v2223->regs;
  int v2229 = v2228[8];
  int v2239 = (v2227 + ((v2224 - v2227) & (~((v2224 - v2227) >> 31)))) + 1;
  v2226[8] = v2239;
  int * v2231 = v2223->regs;
  int v2241 = v2229 + 1;
  v2231[8] = v2241;
  struct StateT * v2233 = slot_81(v2223);
  return v2233;
}

struct StateT * slot_44(struct StateT * v1467) {
  int v1468 = v1467->timer;
  int v1479 = v1468 + 1;
  v1467->timer = v1479;
  int * v1470 = v1467->reg_ready;
  int v1471 = v1470[8];
  int * v1472 = v1467->regs;
  int v1473 = v1472[8];
  int v1483 = (v1471 + ((v1468 - v1471) & (~((v1468 - v1471) >> 31)))) + 1;
  v1470[8] = v1483;
  int * v1475 = v1467->regs;
  int v1485 = v1473 + 1;
  v1475[8] = v1485;
  struct StateT * v1477 = slot_45(v1467);
  return v1477;
}

struct StateT * slot_137(struct StateT * v3420) {
  int v3421 = v3420->timer;
  int v3432 = v3421 + 1;
  v3420->timer = v3432;
  int * v3423 = v3420->reg_ready;
  int v3424 = v3423[8];
  int * v3425 = v3420->regs;
  int v3426 = v3425[8];
  int v3436 = (v3424 + ((v3421 - v3424) & (~((v3421 - v3424) >> 31)))) + 1;
  v3423[8] = v3436;
  int * v3428 = v3420->regs;
  int v3438 = v3426 + 1;
  v3428[8] = v3438;
  struct StateT * v3430 = slot_138(v3420);
  return v3430;
}

struct StateT * slot_122(struct StateT * v3105) {
  int v3106 = v3105->timer;
  int v3117 = v3106 + 1;
  v3105->timer = v3117;
  int * v3108 = v3105->reg_ready;
  int v3109 = v3108[8];
  int * v3110 = v3105->regs;
  int v3111 = v3110[8];
  int v3121 = (v3109 + ((v3106 - v3109) & (~((v3106 - v3109) >> 31)))) + 1;
  v3108[8] = v3121;
  int * v3113 = v3105->regs;
  int v3123 = v3111 + 1;
  v3113[8] = v3123;
  struct StateT * v3115 = slot_123(v3105);
  return v3115;
}

struct StateT * slot_99(struct StateT * v2622) {
  int v2623 = v2622->timer;
  int v2634 = v2623 + 1;
  v2622->timer = v2634;
  int * v2625 = v2622->reg_ready;
  int v2626 = v2625[8];
  int * v2627 = v2622->regs;
  int v2628 = v2627[8];
  int v2638 = (v2626 + ((v2623 - v2626) & (~((v2623 - v2626) >> 31)))) + 1;
  v2625[8] = v2638;
  int * v2630 = v2622->regs;
  int v2640 = v2628 + 1;
  v2630[8] = v2640;
  struct StateT * v2632 = slot_100(v2622);
  return v2632;
}

struct StateT * slot_179(struct StateT * v4302) {
  int v4303 = v4302->timer;
  int v4314 = v4303 + 1;
  v4302->timer = v4314;
  int * v4305 = v4302->reg_ready;
  int v4306 = v4305[8];
  int * v4307 = v4302->regs;
  int v4308 = v4307[8];
  int v4318 = (v4306 + ((v4303 - v4306) & (~((v4303 - v4306) >> 31)))) + 1;
  v4305[8] = v4318;
  int * v4310 = v4302->regs;
  int v4320 = v4308 + 1;
  v4310[8] = v4320;
  struct StateT * v4312 = slot_180(v4302);
  return v4312;
}

struct StateT * slot_219(struct StateT * v5142) {
  int v5143 = v5142->timer;
  int v5154 = v5143 + 1;
  v5142->timer = v5154;
  int * v5145 = v5142->reg_ready;
  int v5146 = v5145[8];
  int * v5147 = v5142->regs;
  int v5148 = v5147[8];
  int v5158 = (v5146 + ((v5143 - v5146) & (~((v5143 - v5146) >> 31)))) + 1;
  v5145[8] = v5158;
  int * v5150 = v5142->regs;
  int v5160 = v5148 + 1;
  v5150[8] = v5160;
  struct StateT * v5152 = slot_220(v5142);
  return v5152;
}

struct StateT * slot_36(struct StateT * v1299) {
  int v1300 = v1299->timer;
  int v1311 = v1300 + 1;
  v1299->timer = v1311;
  int * v1302 = v1299->reg_ready;
  int v1303 = v1302[8];
  int * v1304 = v1299->regs;
  int v1305 = v1304[8];
  int v1315 = (v1303 + ((v1300 - v1303) & (~((v1300 - v1303) >> 31)))) + 1;
  v1302[8] = v1315;
  int * v1307 = v1299->regs;
  int v1317 = v1305 + 1;
  v1307[8] = v1317;
  struct StateT * v1309 = slot_37(v1299);
  return v1309;
}

struct StateT * slot_57(struct StateT * v1740) {
  int v1741 = v1740->timer;
  int v1752 = v1741 + 1;
  v1740->timer = v1752;
  int * v1743 = v1740->reg_ready;
  int v1744 = v1743[8];
  int * v1745 = v1740->regs;
  int v1746 = v1745[8];
  int v1756 = (v1744 + ((v1741 - v1744) & (~((v1741 - v1744) >> 31)))) + 1;
  v1743[8] = v1756;
  int * v1748 = v1740->regs;
  int v1758 = v1746 + 1;
  v1748[8] = v1758;
  struct StateT * v1750 = slot_58(v1740);
  return v1750;
}

struct StateT * slot_62(struct StateT * v1845) {
  int v1846 = v1845->timer;
  int v1857 = v1846 + 1;
  v1845->timer = v1857;
  int * v1848 = v1845->reg_ready;
  int v1849 = v1848[8];
  int * v1850 = v1845->regs;
  int v1851 = v1850[8];
  int v1861 = (v1849 + ((v1846 - v1849) & (~((v1846 - v1849) >> 31)))) + 1;
  v1848[8] = v1861;
  int * v1853 = v1845->regs;
  int v1863 = v1851 + 1;
  v1853[8] = v1863;
  struct StateT * v1855 = slot_63(v1845);
  return v1855;
}

struct StateT * slot_22(struct StateT * v1005) {
  int v1006 = v1005->timer;
  int v1017 = v1006 + 1;
  v1005->timer = v1017;
  int * v1008 = v1005->reg_ready;
  int v1009 = v1008[8];
  int * v1010 = v1005->regs;
  int v1011 = v1010[8];
  int v1021 = (v1009 + ((v1006 - v1009) & (~((v1006 - v1009) >> 31)))) + 1;
  v1008[8] = v1021;
  int * v1013 = v1005->regs;
  int v1023 = v1011 + 1;
  v1013[8] = v1023;
  struct StateT * v1015 = slot_23(v1005);
  return v1015;
}

struct StateT * slot_139(struct StateT * v3462) {
  int v3463 = v3462->timer;
  int v3474 = v3463 + 1;
  v3462->timer = v3474;
  int * v3465 = v3462->reg_ready;
  int v3466 = v3465[8];
  int * v3467 = v3462->regs;
  int v3468 = v3467[8];
  int v3478 = (v3466 + ((v3463 - v3466) & (~((v3463 - v3466) >> 31)))) + 1;
  v3465[8] = v3478;
  int * v3470 = v3462->regs;
  int v3480 = v3468 + 1;
  v3470[8] = v3480;
  struct StateT * v3472 = slot_140(v3462);
  return v3472;
}

struct StateT * slot_221(struct StateT * v5184) {
  int v5185 = v5184->timer;
  int v5196 = v5185 + 1;
  v5184->timer = v5196;
  int * v5187 = v5184->reg_ready;
  int v5188 = v5187[8];
  int * v5189 = v5184->regs;
  int v5190 = v5189[8];
  int v5200 = (v5188 + ((v5185 - v5188) & (~((v5185 - v5188) >> 31)))) + 1;
  v5187[8] = v5200;
  int * v5192 = v5184->regs;
  int v5202 = v5190 + 1;
  v5192[8] = v5202;
  struct StateT * v5194 = slot_222(v5184);
  return v5194;
}

struct StateT * slot_23(struct StateT * v1026) {
  int v1027 = v1026->timer;
  int v1038 = v1027 + 1;
  v1026->timer = v1038;
  int * v1029 = v1026->reg_ready;
  int v1030 = v1029[8];
  int * v1031 = v1026->regs;
  int v1032 = v1031[8];
  int v1042 = (v1030 + ((v1027 - v1030) & (~((v1027 - v1030) >> 31)))) + 1;
  v1029[8] = v1042;
  int * v1034 = v1026->regs;
  int v1044 = v1032 + 1;
  v1034[8] = v1044;
  struct StateT * v1036 = slot_24(v1026);
  return v1036;
}

struct StateT * slot_153(struct StateT * v3756) {
  int v3757 = v3756->timer;
  int v3768 = v3757 + 1;
  v3756->timer = v3768;
  int * v3759 = v3756->reg_ready;
  int v3760 = v3759[8];
  int * v3761 = v3756->regs;
  int v3762 = v3761[8];
  int v3772 = (v3760 + ((v3757 - v3760) & (~((v3757 - v3760) >> 31)))) + 1;
  v3759[8] = v3772;
  int * v3764 = v3756->regs;
  int v3774 = v3762 + 1;
  v3764[8] = v3774;
  struct StateT * v3766 = slot_154(v3756);
  return v3766;
}

struct StateT * slot_2(struct StateT * v403) {
  int v404 = v403->timer;
  int v415 = v404 + 1;
  v403->timer = v415;
  int * v406 = v403->reg_ready;
  int v407 = v406[6];
  int * v408 = v403->regs;
  int v409 = v408[6];
  int v419 = (v407 + ((v404 - v407) & (~((v404 - v407) >> 31)))) + 1;
  v406[6] = v419;
  int * v411 = v403->regs;
  int v421 = v409 & 7;
  v411[6] = v421;
  struct StateT * v413 = slot_3(v403);
  return v413;
}

struct StateT * slot_86(struct StateT * v2349) {
  int v2350 = v2349->timer;
  int v2361 = v2350 + 1;
  v2349->timer = v2361;
  int * v2352 = v2349->reg_ready;
  int v2353 = v2352[8];
  int * v2354 = v2349->regs;
  int v2355 = v2354[8];
  int v2365 = (v2353 + ((v2350 - v2353) & (~((v2350 - v2353) >> 31)))) + 1;
  v2352[8] = v2365;
  int * v2357 = v2349->regs;
  int v2367 = v2355 + 1;
  v2357[8] = v2367;
  struct StateT * v2359 = slot_87(v2349);
  return v2359;
}

struct StateT * slot_129(struct StateT * v3252) {
  int v3253 = v3252->timer;
  int v3264 = v3253 + 1;
  v3252->timer = v3264;
  int * v3255 = v3252->reg_ready;
  int v3256 = v3255[8];
  int * v3257 = v3252->regs;
  int v3258 = v3257[8];
  int v3268 = (v3256 + ((v3253 - v3256) & (~((v3253 - v3256) >> 31)))) + 1;
  v3255[8] = v3268;
  int * v3260 = v3252->regs;
  int v3270 = v3258 + 1;
  v3260[8] = v3270;
  struct StateT * v3262 = slot_130(v3252);
  return v3262;
}

struct StateT * slot_158(struct StateT * v3861) {
  int v3862 = v3861->timer;
  int v3873 = v3862 + 1;
  v3861->timer = v3873;
  int * v3864 = v3861->reg_ready;
  int v3865 = v3864[8];
  int * v3866 = v3861->regs;
  int v3867 = v3866[8];
  int v3877 = (v3865 + ((v3862 - v3865) & (~((v3862 - v3865) >> 31)))) + 1;
  v3864[8] = v3877;
  int * v3869 = v3861->regs;
  int v3879 = v3867 + 1;
  v3869[8] = v3879;
  struct StateT * v3871 = slot_159(v3861);
  return v3871;
}

struct StateT * slot_100(struct StateT * v2643) {
  int v2644 = v2643->timer;
  int v2655 = v2644 + 1;
  v2643->timer = v2655;
  int * v2646 = v2643->reg_ready;
  int v2647 = v2646[8];
  int * v2648 = v2643->regs;
  int v2649 = v2648[8];
  int v2659 = (v2647 + ((v2644 - v2647) & (~((v2644 - v2647) >> 31)))) + 1;
  v2646[8] = v2659;
  int * v2651 = v2643->regs;
  int v2661 = v2649 + 1;
  v2651[8] = v2661;
  struct StateT * v2653 = slot_101(v2643);
  return v2653;
}

struct StateT * slot_127(struct StateT * v3210) {
  int v3211 = v3210->timer;
  int v3222 = v3211 + 1;
  v3210->timer = v3222;
  int * v3213 = v3210->reg_ready;
  int v3214 = v3213[8];
  int * v3215 = v3210->regs;
  int v3216 = v3215[8];
  int v3226 = (v3214 + ((v3211 - v3214) & (~((v3211 - v3214) >> 31)))) + 1;
  v3213[8] = v3226;
  int * v3218 = v3210->regs;
  int v3228 = v3216 + 1;
  v3218[8] = v3228;
  struct StateT * v3220 = slot_128(v3210);
  return v3220;
}

struct StateT * slot_217(struct StateT * v5100) {
  int v5101 = v5100->timer;
  int v5112 = v5101 + 1;
  v5100->timer = v5112;
  int * v5103 = v5100->reg_ready;
  int v5104 = v5103[8];
  int * v5105 = v5100->regs;
  int v5106 = v5105[8];
  int v5116 = (v5104 + ((v5101 - v5104) & (~((v5101 - v5104) >> 31)))) + 1;
  v5103[8] = v5116;
  int * v5108 = v5100->regs;
  int v5118 = v5106 + 1;
  v5108[8] = v5118;
  struct StateT * v5110 = slot_218(v5100);
  return v5110;
}

struct StateT * slot_13(struct StateT * v816) {
  int v817 = v816->timer;
  int v828 = v817 + 1;
  v816->timer = v828;
  int * v819 = v816->reg_ready;
  int v820 = v819[8];
  int * v821 = v816->regs;
  int v822 = v821[8];
  int v832 = (v820 + ((v817 - v820) & (~((v817 - v820) >> 31)))) + 1;
  v819[8] = v832;
  int * v824 = v816->regs;
  int v834 = v822 + 1;
  v824[8] = v834;
  struct StateT * v826 = slot_14(v816);
  return v826;
}

struct StateT * slot_111(struct StateT * v2874) {
  int v2875 = v2874->timer;
  int v2886 = v2875 + 1;
  v2874->timer = v2886;
  int * v2877 = v2874->reg_ready;
  int v2878 = v2877[8];
  int * v2879 = v2874->regs;
  int v2880 = v2879[8];
  int v2890 = (v2878 + ((v2875 - v2878) & (~((v2875 - v2878) >> 31)))) + 1;
  v2877[8] = v2890;
  int * v2882 = v2874->regs;
  int v2892 = v2880 + 1;
  v2882[8] = v2892;
  struct StateT * v2884 = slot_112(v2874);
  return v2884;
}

struct StateT * slot_109(struct StateT * v2832) {
  int v2833 = v2832->timer;
  int v2844 = v2833 + 1;
  v2832->timer = v2844;
  int * v2835 = v2832->reg_ready;
  int v2836 = v2835[8];
  int * v2837 = v2832->regs;
  int v2838 = v2837[8];
  int v2848 = (v2836 + ((v2833 - v2836) & (~((v2833 - v2836) >> 31)))) + 1;
  v2835[8] = v2848;
  int * v2840 = v2832->regs;
  int v2850 = v2838 + 1;
  v2840[8] = v2850;
  struct StateT * v2842 = slot_110(v2832);
  return v2842;
}

struct StateT * slot_174(struct StateT * v4197) {
  int v4198 = v4197->timer;
  int v4209 = v4198 + 1;
  v4197->timer = v4209;
  int * v4200 = v4197->reg_ready;
  int v4201 = v4200[8];
  int * v4202 = v4197->regs;
  int v4203 = v4202[8];
  int v4213 = (v4201 + ((v4198 - v4201) & (~((v4198 - v4201) >> 31)))) + 1;
  v4200[8] = v4213;
  int * v4205 = v4197->regs;
  int v4215 = v4203 + 1;
  v4205[8] = v4215;
  struct StateT * v4207 = slot_175(v4197);
  return v4207;
}

struct StateT * slot_147(struct StateT * v3630) {
  int v3631 = v3630->timer;
  int v3642 = v3631 + 1;
  v3630->timer = v3642;
  int * v3633 = v3630->reg_ready;
  int v3634 = v3633[8];
  int * v3635 = v3630->regs;
  int v3636 = v3635[8];
  int v3646 = (v3634 + ((v3631 - v3634) & (~((v3631 - v3634) >> 31)))) + 1;
  v3633[8] = v3646;
  int * v3638 = v3630->regs;
  int v3648 = v3636 + 1;
  v3638[8] = v3648;
  struct StateT * v3640 = slot_148(v3630);
  return v3640;
}

struct StateT * slot_42(struct StateT * v1425) {
  int v1426 = v1425->timer;
  int v1437 = v1426 + 1;
  v1425->timer = v1437;
  int * v1428 = v1425->reg_ready;
  int v1429 = v1428[8];
  int * v1430 = v1425->regs;
  int v1431 = v1430[8];
  int v1441 = (v1429 + ((v1426 - v1429) & (~((v1426 - v1429) >> 31)))) + 1;
  v1428[8] = v1441;
  int * v1433 = v1425->regs;
  int v1443 = v1431 + 1;
  v1433[8] = v1443;
  struct StateT * v1435 = slot_43(v1425);
  return v1435;
}

struct StateT * slot_224(struct StateT * v5247) {
  int v5248 = v5247->timer;
  int v5259 = v5248 + 1;
  v5247->timer = v5259;
  int * v5250 = v5247->reg_ready;
  int v5251 = v5250[8];
  int * v5252 = v5247->regs;
  int v5253 = v5252[8];
  int v5263 = (v5251 + ((v5248 - v5251) & (~((v5248 - v5251) >> 31)))) + 1;
  v5250[8] = v5263;
  int * v5255 = v5247->regs;
  int v5265 = v5253 + 1;
  v5255[8] = v5265;
  struct StateT * v5257 = slot_225(v5247);
  return v5257;
}

struct StateT * slot_163(struct StateT * v3966) {
  int v3967 = v3966->timer;
  int v3978 = v3967 + 1;
  v3966->timer = v3978;
  int * v3969 = v3966->reg_ready;
  int v3970 = v3969[8];
  int * v3971 = v3966->regs;
  int v3972 = v3971[8];
  int v3982 = (v3970 + ((v3967 - v3970) & (~((v3967 - v3970) >> 31)))) + 1;
  v3969[8] = v3982;
  int * v3974 = v3966->regs;
  int v3984 = v3972 + 1;
  v3974[8] = v3984;
  struct StateT * v3976 = slot_164(v3966);
  return v3976;
}

struct StateT * slot_184(struct StateT * v4407) {
  int v4408 = v4407->timer;
  int v4419 = v4408 + 1;
  v4407->timer = v4419;
  int * v4410 = v4407->reg_ready;
  int v4411 = v4410[8];
  int * v4412 = v4407->regs;
  int v4413 = v4412[8];
  int v4423 = (v4411 + ((v4408 - v4411) & (~((v4408 - v4411) >> 31)))) + 1;
  v4410[8] = v4423;
  int * v4415 = v4407->regs;
  int v4425 = v4413 + 1;
  v4415[8] = v4425;
  struct StateT * v4417 = slot_185(v4407);
  return v4417;
}

struct StateT * slot_204(struct StateT * v4827) {
  int v4828 = v4827->timer;
  int v4839 = v4828 + 1;
  v4827->timer = v4839;
  int * v4830 = v4827->reg_ready;
  int v4831 = v4830[8];
  int * v4832 = v4827->regs;
  int v4833 = v4832[8];
  int v4843 = (v4831 + ((v4828 - v4831) & (~((v4828 - v4831) >> 31)))) + 1;
  v4830[8] = v4843;
  int * v4835 = v4827->regs;
  int v4845 = v4833 + 1;
  v4835[8] = v4845;
  struct StateT * v4837 = slot_205(v4827);
  return v4837;
}

struct StateT * slot_194(struct StateT * v4617) {
  int v4618 = v4617->timer;
  int v4629 = v4618 + 1;
  v4617->timer = v4629;
  int * v4620 = v4617->reg_ready;
  int v4621 = v4620[8];
  int * v4622 = v4617->regs;
  int v4623 = v4622[8];
  int v4633 = (v4621 + ((v4618 - v4621) & (~((v4618 - v4621) >> 31)))) + 1;
  v4620[8] = v4633;
  int * v4625 = v4617->regs;
  int v4635 = v4623 + 1;
  v4625[8] = v4635;
  struct StateT * v4627 = slot_195(v4617);
  return v4627;
}

struct StateT * slot_165(struct StateT * v4008) {
  int v4009 = v4008->timer;
  int v4020 = v4009 + 1;
  v4008->timer = v4020;
  int * v4011 = v4008->reg_ready;
  int v4012 = v4011[8];
  int * v4013 = v4008->regs;
  int v4014 = v4013[8];
  int v4024 = (v4012 + ((v4009 - v4012) & (~((v4009 - v4012) >> 31)))) + 1;
  v4011[8] = v4024;
  int * v4016 = v4008->regs;
  int v4026 = v4014 + 1;
  v4016[8] = v4026;
  struct StateT * v4018 = slot_166(v4008);
  return v4018;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v5286 = v1->timer;
  int * v5287 = v1->reg_ready;
  int v5288 = v5287[0];
  int v5419 = v5288 + ((v5286 - v5288) & (~((v5286 - v5288) >> 31)));
  v1->timer = v5419;
  int v5290 = v1->timer;
  int * v5291 = v1->reg_ready;
  int v5292 = v5291[1];
  int v5422 = v5292 + ((v5290 - v5292) & (~((v5290 - v5292) >> 31)));
  v1->timer = v5422;
  int v5294 = v1->timer;
  int * v5295 = v1->reg_ready;
  int v5296 = v5295[2];
  int v5425 = v5296 + ((v5294 - v5296) & (~((v5294 - v5296) >> 31)));
  v1->timer = v5425;
  int v5298 = v1->timer;
  int * v5299 = v1->reg_ready;
  int v5300 = v5299[3];
  int v5428 = v5300 + ((v5298 - v5300) & (~((v5298 - v5300) >> 31)));
  v1->timer = v5428;
  int v5302 = v1->timer;
  int * v5303 = v1->reg_ready;
  int v5304 = v5303[4];
  int v5431 = v5304 + ((v5302 - v5304) & (~((v5302 - v5304) >> 31)));
  v1->timer = v5431;
  int v5306 = v1->timer;
  int * v5307 = v1->reg_ready;
  int v5308 = v5307[5];
  int v5434 = v5308 + ((v5306 - v5308) & (~((v5306 - v5308) >> 31)));
  v1->timer = v5434;
  int v5310 = v1->timer;
  int * v5311 = v1->reg_ready;
  int v5312 = v5311[6];
  int v5437 = v5312 + ((v5310 - v5312) & (~((v5310 - v5312) >> 31)));
  v1->timer = v5437;
  int v5314 = v1->timer;
  int * v5315 = v1->reg_ready;
  int v5316 = v5315[7];
  int v5440 = v5316 + ((v5314 - v5316) & (~((v5314 - v5316) >> 31)));
  v1->timer = v5440;
  int v5318 = v1->timer;
  int * v5319 = v1->reg_ready;
  int v5320 = v5319[8];
  int v5443 = v5320 + ((v5318 - v5320) & (~((v5318 - v5320) >> 31)));
  v1->timer = v5443;
  int v5322 = v1->timer;
  int * v5323 = v1->reg_ready;
  int v5324 = v5323[9];
  int v5446 = v5324 + ((v5322 - v5324) & (~((v5322 - v5324) >> 31)));
  v1->timer = v5446;
  int v5326 = v1->timer;
  int * v5327 = v1->reg_ready;
  int v5328 = v5327[10];
  int v5449 = v5328 + ((v5326 - v5328) & (~((v5326 - v5328) >> 31)));
  v1->timer = v5449;
  int v5330 = v1->timer;
  int * v5331 = v1->reg_ready;
  int v5332 = v5331[11];
  int v5452 = v5332 + ((v5330 - v5332) & (~((v5330 - v5332) >> 31)));
  v1->timer = v5452;
  int v5334 = v1->timer;
  int * v5335 = v1->reg_ready;
  int v5336 = v5335[12];
  int v5455 = v5336 + ((v5334 - v5336) & (~((v5334 - v5336) >> 31)));
  v1->timer = v5455;
  int v5338 = v1->timer;
  int * v5339 = v1->reg_ready;
  int v5340 = v5339[13];
  int v5458 = v5340 + ((v5338 - v5340) & (~((v5338 - v5340) >> 31)));
  v1->timer = v5458;
  int v5342 = v1->timer;
  int * v5343 = v1->reg_ready;
  int v5344 = v5343[14];
  int v5461 = v5344 + ((v5342 - v5344) & (~((v5342 - v5344) >> 31)));
  v1->timer = v5461;
  int v5346 = v1->timer;
  int * v5347 = v1->reg_ready;
  int v5348 = v5347[15];
  int v5464 = v5348 + ((v5346 - v5348) & (~((v5346 - v5348) >> 31)));
  v1->timer = v5464;
  int v5350 = v1->timer;
  int * v5351 = v1->reg_ready;
  int v5352 = v5351[16];
  int v5467 = v5352 + ((v5350 - v5352) & (~((v5350 - v5352) >> 31)));
  v1->timer = v5467;
  int v5354 = v1->timer;
  int * v5355 = v1->reg_ready;
  int v5356 = v5355[17];
  int v5470 = v5356 + ((v5354 - v5356) & (~((v5354 - v5356) >> 31)));
  v1->timer = v5470;
  int v5358 = v1->timer;
  int * v5359 = v1->reg_ready;
  int v5360 = v5359[18];
  int v5473 = v5360 + ((v5358 - v5360) & (~((v5358 - v5360) >> 31)));
  v1->timer = v5473;
  int v5362 = v1->timer;
  int * v5363 = v1->reg_ready;
  int v5364 = v5363[19];
  int v5476 = v5364 + ((v5362 - v5364) & (~((v5362 - v5364) >> 31)));
  v1->timer = v5476;
  int v5366 = v1->timer;
  int * v5367 = v1->reg_ready;
  int v5368 = v5367[20];
  int v5479 = v5368 + ((v5366 - v5368) & (~((v5366 - v5368) >> 31)));
  v1->timer = v5479;
  int v5370 = v1->timer;
  int * v5371 = v1->reg_ready;
  int v5372 = v5371[21];
  int v5482 = v5372 + ((v5370 - v5372) & (~((v5370 - v5372) >> 31)));
  v1->timer = v5482;
  int v5374 = v1->timer;
  int * v5375 = v1->reg_ready;
  int v5376 = v5375[22];
  int v5485 = v5376 + ((v5374 - v5376) & (~((v5374 - v5376) >> 31)));
  v1->timer = v5485;
  int v5378 = v1->timer;
  int * v5379 = v1->reg_ready;
  int v5380 = v5379[23];
  int v5488 = v5380 + ((v5378 - v5380) & (~((v5378 - v5380) >> 31)));
  v1->timer = v5488;
  int v5382 = v1->timer;
  int * v5383 = v1->reg_ready;
  int v5384 = v5383[24];
  int v5491 = v5384 + ((v5382 - v5384) & (~((v5382 - v5384) >> 31)));
  v1->timer = v5491;
  int v5386 = v1->timer;
  int * v5387 = v1->reg_ready;
  int v5388 = v5387[25];
  int v5494 = v5388 + ((v5386 - v5388) & (~((v5386 - v5388) >> 31)));
  v1->timer = v5494;
  int v5390 = v1->timer;
  int * v5391 = v1->reg_ready;
  int v5392 = v5391[26];
  int v5497 = v5392 + ((v5390 - v5392) & (~((v5390 - v5392) >> 31)));
  v1->timer = v5497;
  int v5394 = v1->timer;
  int * v5395 = v1->reg_ready;
  int v5396 = v5395[27];
  int v5500 = v5396 + ((v5394 - v5396) & (~((v5394 - v5396) >> 31)));
  v1->timer = v5500;
  int v5398 = v1->timer;
  int * v5399 = v1->reg_ready;
  int v5400 = v5399[28];
  int v5503 = v5400 + ((v5398 - v5400) & (~((v5398 - v5400) >> 31)));
  v1->timer = v5503;
  int v5402 = v1->timer;
  int * v5403 = v1->reg_ready;
  int v5404 = v5403[29];
  int v5506 = v5404 + ((v5402 - v5404) & (~((v5402 - v5404) >> 31)));
  v1->timer = v5506;
  int v5406 = v1->timer;
  int * v5407 = v1->reg_ready;
  int v5408 = v5407[30];
  int v5509 = v5408 + ((v5406 - v5408) & (~((v5406 - v5408) >> 31)));
  v1->timer = v5509;
  int v5410 = v1->timer;
  int * v5411 = v1->reg_ready;
  int v5412 = v5411[31];
  int v5512 = v5412 + ((v5410 - v5412) & (~((v5410 - v5412) >> 31)));
  v1->timer = v5512;
  return v1;
}

struct StateT * slot_117(struct StateT * v3000) {
  int v3001 = v3000->timer;
  int v3012 = v3001 + 1;
  v3000->timer = v3012;
  int * v3003 = v3000->reg_ready;
  int v3004 = v3003[8];
  int * v3005 = v3000->regs;
  int v3006 = v3005[8];
  int v3016 = (v3004 + ((v3001 - v3004) & (~((v3001 - v3004) >> 31)))) + 1;
  v3003[8] = v3016;
  int * v3008 = v3000->regs;
  int v3018 = v3006 + 1;
  v3008[8] = v3018;
  struct StateT * v3010 = slot_118(v3000);
  return v3010;
}

struct StateT * slot_90(struct StateT * v2433) {
  int v2434 = v2433->timer;
  int v2445 = v2434 + 1;
  v2433->timer = v2445;
  int * v2436 = v2433->reg_ready;
  int v2437 = v2436[8];
  int * v2438 = v2433->regs;
  int v2439 = v2438[8];
  int v2449 = (v2437 + ((v2434 - v2437) & (~((v2434 - v2437) >> 31)))) + 1;
  v2436[8] = v2449;
  int * v2441 = v2433->regs;
  int v2451 = v2439 + 1;
  v2441[8] = v2451;
  struct StateT * v2443 = slot_91(v2433);
  return v2443;
}

struct StateT * slot_11(struct StateT * v774) {
  int v775 = v774->timer;
  int v786 = v775 + 1;
  v774->timer = v786;
  int * v777 = v774->reg_ready;
  int v778 = v777[8];
  int * v779 = v774->regs;
  int v780 = v779[8];
  int v790 = (v778 + ((v775 - v778) & (~((v775 - v778) >> 31)))) + 1;
  v777[8] = v790;
  int * v782 = v774->regs;
  int v792 = v780 + 1;
  v782[8] = v792;
  struct StateT * v784 = slot_12(v774);
  return v784;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}