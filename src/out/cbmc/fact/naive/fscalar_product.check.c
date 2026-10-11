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

struct StateT * slot_12(struct StateT * v208);
struct StateT * slot_143(struct StateT * v2573);
struct StateT * slot_120(struct StateT * v2149);
struct StateT * slot_167(struct StateT * v2991);
struct StateT * slot_152(struct StateT * v2745);
struct StateT * slot_199(struct StateT * v3565);
struct StateT * slot_92(struct StateT * v1634);
struct StateT * slot_31(struct StateT * v546);
struct StateT * slot_160(struct StateT * v2873);
struct StateT * slot_65(struct StateT * v1177);
struct StateT * slot_10(struct StateT * v174);
struct StateT * slot_150(struct StateT * v2707);
struct StateT * slot_74(struct StateT * v1324);
struct StateT * slot_107(struct StateT * v1927);
struct StateT * slot_136(struct StateT * v2442);
struct StateT * slot_84(struct StateT * v1492);
struct StateT * slot_28(struct StateT * v491);
struct StateT * slot_155(struct StateT * v2790);
struct StateT * slot_177(struct StateT * v3180);
struct StateT * slot_17(struct StateT * v292);
struct StateT * slot_181(struct StateT * v3263);
struct StateT * slot_197(struct StateT * v3532);
struct StateT * slot_207(struct StateT * v3707);
struct StateT * slot_156(struct StateT * v2809);
struct StateT * slot_154(struct StateT * v2774);
struct StateT * slot_68(struct StateT * v1219);
struct StateT * slot_105(struct StateT * v1902);
struct StateT * slot_27(struct StateT * v475);
struct StateT * slot_164(struct StateT * v2941);
struct StateT * slot_15(struct StateT * v259);
struct StateT * slot_133(struct StateT * v2384);
struct StateT * slot_56(struct StateT * v993);
struct StateT * slot_34(struct StateT * v611);
struct StateT * slot_171(struct StateT * v3065);
struct StateT * slot_162(struct StateT * v2907);
struct StateT * slot_21(struct StateT * v365);
struct StateT * slot_118(struct StateT * v2119);
struct StateT * slot_121(struct StateT * v2166);
struct StateT * slot_144(struct StateT * v2589);
struct StateT * slot_201(struct StateT * v3597);
struct StateT * slot_94(struct StateT * v1675);
struct StateT * slot_63(struct StateT * v1123);
struct StateT * slot_146(struct StateT * v2611);
struct StateT * slot_24(struct StateT * v421);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v3502);
struct StateT * slot_125(struct StateT * v2234);
struct StateT * slot_148(struct StateT * v2669);
struct StateT * slot_126(struct StateT * v2251);
struct StateT * slot_79(struct StateT * v1408);
struct StateT * slot_41(struct StateT * v723);
struct StateT * slot_39(struct StateT * v689);
struct StateT * slot_142(struct StateT * v2556);
struct StateT * slot_60(struct StateT * v1066);
struct StateT * slot_112(struct StateT * v2020);
struct StateT * slot_47(struct StateT * v821);
struct StateT * slot_214(struct StateT * v3835);
struct StateT * slot_29(struct StateT * v510);
struct StateT * slot_16(struct StateT * v276);
struct StateT * slot_113(struct StateT * v2035);
struct StateT * slot_151(struct StateT * v2726);
struct StateT * slot_7(struct StateT * v130);
struct StateT * slot_124(struct StateT * v2217);
struct StateT * slot_191(struct StateT * v3444);
struct StateT * slot_103(struct StateT * v1848);
struct StateT * slot_128(struct StateT * v2284);
struct StateT * slot_19(struct StateT * v333);
struct StateT * slot_87(struct StateT * v1543);
struct StateT * slot_67(struct StateT * v1202);
struct StateT * slot_81(struct StateT * v1441);
struct StateT * slot_95(struct StateT * v1700);
struct StateT * slot_115(struct StateT * v2065);
struct StateT * slot_78(struct StateT * v1394);
struct StateT * slot_32(struct StateT * v570);
struct StateT * slot_205(struct StateT * v3669);
struct StateT * slot_193(struct StateT * v3475);
struct StateT * slot_176(struct StateT * v3164);
struct StateT * slot_189(struct StateT * v3404);
struct StateT * slot_33(struct StateT * v595);
struct StateT * slot_35(struct StateT * v626);
struct StateT * slot_210(struct StateT * v3764);
struct StateT * slot_166(struct StateT * v2975);
struct StateT * slot_51(struct StateT * v893);
struct StateT * slot_52(struct StateT * v910);
struct StateT * slot_83(struct StateT * v1475);
struct StateT * slot_25(struct StateT * v437);
struct StateT * slot_209(struct StateT * v3745);
struct StateT * slot_3(struct StateT * v54);
struct StateT * slot_123(struct StateT * v2200);
struct StateT * slot_73(struct StateT * v1310);
struct StateT * slot_198(struct StateT * v3549);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v3374);
struct StateT * slot_97(struct StateT * v1733);
struct StateT * slot_182(struct StateT * v3279);
struct StateT * slot_38(struct StateT * v672);
struct StateT * slot_178(struct StateT * v3197);
struct StateT * slot_106(struct StateT * v1886);
struct StateT * slot_98(struct StateT * v1749);
struct StateT * slot_159(struct StateT * v2857);
struct StateT * slot_46(struct StateT * v804);
struct StateT * slot_212(struct StateT * v3802);
struct StateT * slot_132(struct StateT * v2359);
struct StateT * slot_130(struct StateT * v2318);
struct StateT * slot_211(struct StateT * v3783);
struct StateT * slot_20(struct StateT * v349);
struct StateT * slot_141(struct StateT * v2540);
struct StateT * slot_61(struct StateT * v1091);
struct StateT * slot_30(struct StateT * v529);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_18(struct StateT * v308);
struct StateT * slot_9(struct StateT * v157);
struct StateT * slot_183(struct StateT * v3295);
struct StateT * slot_43(struct StateT * v757);
struct StateT * slot_70(struct StateT * v1257);
struct StateT * slot_168(struct StateT * v3007);
struct StateT * slot_76(struct StateT * v1359);
struct StateT * slot_6(struct StateT * v111);
struct StateT * slot_55(struct StateT * v976);
struct StateT * slot_213(struct StateT * v3821);
struct StateT * slot_82(struct StateT * v1458);
struct StateT * slot_161(struct StateT * v2890);
struct StateT * slot_185(struct StateT * v3349);
struct StateT * slot_91(struct StateT * v1618);
struct StateT * slot_58(struct StateT * v1025);
struct StateT * slot_89(struct StateT * v1576);
struct StateT * slot_66(struct StateT * v1161);
struct StateT * slot_140(struct StateT * v2515);
struct StateT * slot_49(struct StateT * v853);
struct StateT * slot_50(struct StateT * v869);
struct StateT * slot_37(struct StateT * v656);
struct StateT * slot_114(struct StateT * v2049);
struct StateT * slot_135(struct StateT * v2425);
struct StateT * slot_59(struct StateT * v1042);
struct StateT * slot_192(struct StateT * v3459);
struct StateT * slot_40(struct StateT * v706);
struct StateT * slot_48(struct StateT * v837);
struct StateT * slot_77(struct StateT * v1378);
struct StateT * slot_85(struct StateT * v1509);
struct StateT * slot_75(struct StateT * v1340);
struct StateT * slot_72(struct StateT * v1295);
struct StateT * slot_119(struct StateT * v2133);
struct StateT * slot_71(struct StateT * v1276);
struct StateT * slot_101(struct StateT * v1815);
struct StateT * slot_108(struct StateT * v1944);
struct StateT * slot_116(struct StateT * v2084);
struct StateT * slot_93(struct StateT * v1659);
struct StateT * slot_88(struct StateT * v1559);
struct StateT * slot_96(struct StateT * v1717);
struct StateT * slot_45(struct StateT * v787);
struct StateT * slot_134(struct StateT * v2400);
struct StateT * slot_175(struct StateT * v3148);
struct StateT * slot_69(struct StateT * v1233);
struct StateT * slot_202(struct StateT * v3613);
struct StateT * slot_188(struct StateT * v3390);
struct StateT * slot_138(struct StateT * v2474);
struct StateT * slot_186(struct StateT * v3333);
struct StateT * slot_102(struct StateT * v1831);
struct StateT * slot_145(struct StateT * v2627);
struct StateT * slot_110(struct StateT * v1982);
struct StateT * slot_196(struct StateT * v3516);
struct StateT * slot_208(struct StateT * v3726);
struct StateT * slot_172(struct StateT * v3082);
struct StateT * slot_131(struct StateT * v2343);
struct StateT * slot_8(struct StateT * v143);
struct StateT * slot_180(struct StateT * v3238);
struct StateT * slot_203(struct StateT * v3637);
struct StateT * slot_190(struct StateT * v3428);
struct StateT * slot_157(struct StateT * v2827);
struct StateT * slot_200(struct StateT * v3581);
struct StateT * slot_173(struct StateT * v3107);
struct StateT * slot_149(struct StateT * v2683);
struct StateT * slot_5(struct StateT * v92);
struct StateT * slot_104(struct StateT * v1864);
struct StateT * slot_54(struct StateT * v951);
struct StateT * slot_26(struct StateT * v456);
struct StateT * slot_206(struct StateT * v3688);
struct StateT * slot_169(struct StateT * v3023);
struct StateT * slot_64(struct StateT * v1139);
struct StateT * slot_170(struct StateT * v3040);
struct StateT * slot_14(struct StateT * v242);
struct StateT * slot_53(struct StateT * v935);
struct StateT * slot_80(struct StateT * v1424);
struct StateT * slot_44(struct StateT * v771);
struct StateT * slot_137(struct StateT * v2458);
struct StateT * slot_122(struct StateT * v2183);
struct StateT * slot_99(struct StateT * v1766);
struct StateT * slot_179(struct StateT * v3214);
struct StateT * slot_36(struct StateT * v640);
struct StateT * slot_57(struct StateT * v1009);
struct StateT * slot_62(struct StateT * v1107);
struct StateT * slot_22(struct StateT * v390);
struct StateT * slot_139(struct StateT * v2491);
struct StateT * slot_23(struct StateT * v407);
struct StateT * slot_153(struct StateT * v2760);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_86(struct StateT * v1526);
struct StateT * slot_129(struct StateT * v2301);
struct StateT * slot_158(struct StateT * v2843);
struct StateT * slot_100(struct StateT * v1790);
struct StateT * slot_127(struct StateT * v2268);
struct StateT * slot_13(struct StateT * v225);
struct StateT * slot_111(struct StateT * v2001);
struct StateT * slot_109(struct StateT * v1958);
struct StateT * slot_174(struct StateT * v3123);
struct StateT * slot_147(struct StateT * v2652);
struct StateT * slot_42(struct StateT * v740);
struct StateT * slot_163(struct StateT * v2924);
struct StateT * slot_184(struct StateT * v3311);
struct StateT * slot_204(struct StateT * v3653);
struct StateT * slot_194(struct StateT * v3488);
struct StateT * slot_165(struct StateT * v2958);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v2103);
struct StateT * slot_90(struct StateT * v1593);
struct StateT * slot_11(struct StateT * v191);
struct StateT * slot_12(struct StateT * v208) {
  int v209 = v208->timer;
  int v217 = v209 + 1;
  v208->timer = v217;
  int * v211 = v208->regs;
  int v212 = v211[14];
  int v213 = v211[13];
  int v222 = v212 * v213;
  v211[7] = v222;
  struct StateT * v215 = slot_13(v208);
  return v215;
}

struct StateT * slot_143(struct StateT * v2573) {
  int v2574 = v2573->timer;
  int v2582 = v2574 + 1;
  v2573->timer = v2582;
  int * v2576 = v2573->regs;
  int v2577 = v2576[6];
  int v2578 = v2576[31];
  int v2586 = v2577 + v2578;
  v2576[6] = v2586;
  struct StateT * v2580 = slot_144(v2573);
  return v2580;
}

struct StateT * slot_120(struct StateT * v2149) {
  int v2150 = v2149->timer;
  int v2158 = v2150 + 1;
  v2149->timer = v2158;
  int * v2152 = v2149->regs;
  int v2153 = v2152[6];
  int v2154 = v2152[12];
  int v2163 = (((((int)((unsigned int)v2153 >> 16)) * ((int)((unsigned int)v2154 >> 16))) + ((int)((unsigned int)((v2153 & 65535) * ((int)((unsigned int)v2154 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2153 >> 16)) * (v2154 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2153 & 65535) * (v2154 & 65535)) >> 16)) + (((v2153 & 65535) * ((int)((unsigned int)v2154 >> 16))) & 65535)) + ((((int)((unsigned int)v2153 >> 16)) * (v2154 & 65535)) & 65535)) >> 16));
  v2152[17] = v2163;
  struct StateT * v2156 = slot_121(v2149);
  return v2156;
}

struct StateT * slot_167(struct StateT * v2991) {
  int v2992 = v2991->timer;
  int v3000 = v2992 + 1;
  v2991->timer = v3000;
  int * v2994 = v2991->regs;
  int v2995 = v2994[6];
  int v2996 = v2994[12];
  int v3004 = v2995 * v2996;
  v2994[12] = v3004;
  struct StateT * v2998 = slot_168(v2991);
  return v2998;
}

struct StateT * slot_152(struct StateT * v2745) {
  int v2746 = v2745->timer;
  int v2753 = v2746 + 1;
  v2745->timer = v2753;
  int * v2748 = v2745->regs;
  int v2749 = v2748[28];
  int v2757 = (int)((unsigned int)v2749 >> 19);
  v2748[17] = v2757;
  struct StateT * v2751 = slot_153(v2745);
  return v2751;
}

struct StateT * slot_199(struct StateT * v3565) {
  int v3566 = v3565->timer;
  int v3574 = v3566 + 1;
  v3565->timer = v3574;
  int * v3568 = v3565->regs;
  int v3569 = v3568[15];
  int v3570 = v3568[5];
  int v3578 = v3569 + v3570;
  v3568[15] = v3578;
  struct StateT * v3572 = slot_200(v3565);
  return v3572;
}

struct StateT * slot_92(struct StateT * v1634) {
  int v1635 = v1634->timer;
  int v1647 = v1635 + 1;
  v1634->timer = v1647;
  int * v1637 = v1634->regs;
  int v1638 = v1637[17];
  int v1639 = v1637[6];
  bool v1651 = (v1638 ^ -2147483648) < (v1639 ^ -2147483648);
  int v1642;
  if (v1651) {
    v1642 = 1;
  } else {
    v1642 = 0;
  }
  int * v1643 = v1634->regs;
  v1643[28] = v1642;
  struct StateT * v1645 = slot_93(v1634);
  return v1645;
}

struct StateT * slot_31(struct StateT * v546) {
  int v547 = v546->timer;
  int v559 = v547 + 1;
  v546->timer = v559;
  int * v549 = v546->regs;
  int v550 = v549[5];
  int v551 = v549[6];
  bool v563 = (v550 ^ -2147483648) < (v551 ^ -2147483648);
  int v554;
  if (v563) {
    v554 = 1;
  } else {
    v554 = 0;
  }
  int * v555 = v546->regs;
  v555[5] = v554;
  struct StateT * v557 = slot_32(v546);
  return v557;
}

struct StateT * slot_160(struct StateT * v2873) {
  int v2874 = v2873->timer;
  int v2882 = v2874 + 1;
  v2873->timer = v2882;
  int * v2876 = v2873->regs;
  int v2877 = v2876[6];
  int v2878 = v2876[12];
  int v2887 = (((((int)((unsigned int)v2877 >> 16)) * ((int)((unsigned int)v2878 >> 16))) + ((int)((unsigned int)((v2877 & 65535) * ((int)((unsigned int)v2878 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2877 >> 16)) * (v2878 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2877 & 65535) * (v2878 & 65535)) >> 16)) + (((v2877 & 65535) * ((int)((unsigned int)v2878 >> 16))) & 65535)) + ((((int)((unsigned int)v2877 >> 16)) * (v2878 & 65535)) & 65535)) >> 16));
  v2876[5] = v2887;
  struct StateT * v2880 = slot_161(v2873);
  return v2880;
}

struct StateT * slot_65(struct StateT * v1177) {
  int v1178 = v1177->timer;
  int v1190 = v1178 + 1;
  v1177->timer = v1190;
  int * v1180 = v1177->regs;
  int v1181 = v1180[7];
  int v1182 = v1180[29];
  bool v1194 = (v1181 ^ -2147483648) < (v1182 ^ -2147483648);
  int v1185;
  if (v1194) {
    v1185 = 1;
  } else {
    v1185 = 0;
  }
  int * v1186 = v1177->regs;
  v1186[28] = v1185;
  struct StateT * v1188 = slot_66(v1177);
  return v1188;
}

struct StateT * slot_10(struct StateT * v174) {
  int v175 = v174->timer;
  int v183 = v175 + 1;
  v174->timer = v183;
  int * v177 = v174->regs;
  int v178 = v177[15];
  int v179 = v177[12];
  int v188 = v178 * v179;
  v177[5] = v188;
  struct StateT * v181 = slot_11(v174);
  return v181;
}

struct StateT * slot_150(struct StateT * v2707) {
  int v2708 = v2707->timer;
  int v2717 = v2708 + 1;
  v2707->timer = v2717;
  int * v2710 = v2707->regs;
  int v2711 = v2710[10];
  int v2712 = v2710[17];
  int * v2713 = v2707->mem;
  int v2722 = (int)((unsigned int)(v2711 + 24) >> 2);
  v2713[v2722] = v2712;
  struct StateT * v2715 = slot_151(v2707);
  return v2715;
}

struct StateT * slot_74(struct StateT * v1324) {
  int v1325 = v1324->timer;
  int v1333 = v1325 + 1;
  v1324->timer = v1333;
  int * v1327 = v1324->regs;
  int v1328 = v1327[6];
  int v1329 = v1327[5];
  int v1337 = v1328 + v1329;
  v1327[5] = v1337;
  struct StateT * v1331 = slot_75(v1324);
  return v1331;
}

struct StateT * slot_107(struct StateT * v1927) {
  int v1928 = v1927->timer;
  int v1936 = v1928 + 1;
  v1927->timer = v1936;
  int * v1930 = v1927->regs;
  int v1931 = v1930[7];
  int v1932 = v1930[16];
  int v1941 = v1931 & v1932;
  v1930[29] = v1941;
  struct StateT * v1934 = slot_108(v1927);
  return v1934;
}

struct StateT * slot_136(struct StateT * v2442) {
  int v2443 = v2442->timer;
  int v2451 = v2443 + 1;
  v2442->timer = v2451;
  int * v2445 = v2442->regs;
  int v2446 = v2445[8];
  int v2447 = v2445[6];
  int v2455 = v2446 + v2447;
  v2445[6] = v2455;
  struct StateT * v2449 = slot_137(v2442);
  return v2449;
}

struct StateT * slot_84(struct StateT * v1492) {
  int v1493 = v1492->timer;
  int v1501 = v1493 + 1;
  v1492->timer = v1501;
  int * v1495 = v1492->regs;
  int v1496 = v1495[6];
  int v1497 = v1495[13];
  int v1506 = (((((int)((unsigned int)v1496 >> 16)) * ((int)((unsigned int)v1497 >> 16))) + ((int)((unsigned int)((v1496 & 65535) * ((int)((unsigned int)v1497 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1496 >> 16)) * (v1497 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1496 & 65535) * (v1497 & 65535)) >> 16)) + (((v1496 & 65535) * ((int)((unsigned int)v1497 >> 16))) & 65535)) + ((((int)((unsigned int)v1496 >> 16)) * (v1497 & 65535)) & 65535)) >> 16));
  v1495[8] = v1506;
  struct StateT * v1499 = slot_85(v1492);
  return v1499;
}

struct StateT * slot_28(struct StateT * v491) {
  int v492 = v491->timer;
  int v501 = v492 + 1;
  v491->timer = v501;
  int * v494 = v491->regs;
  int v495 = v494[11];
  int * v496 = v491->mem;
  int v505 = (int)((unsigned int)(v495 + 8) >> 2);
  int v497 = v496[v505];
  v494[7] = v497;
  struct StateT * v499 = slot_29(v491);
  return v499;
}

struct StateT * slot_155(struct StateT * v2790) {
  int v2791 = v2790->timer;
  int v2800 = v2791 + 1;
  v2790->timer = v2800;
  int * v2793 = v2790->regs;
  int v2794 = v2793[11];
  int * v2795 = v2790->mem;
  int v2804 = (int)((unsigned int)(v2794 + 32) >> 2);
  int v2796 = v2795[v2804];
  v2793[6] = v2796;
  struct StateT * v2798 = slot_156(v2790);
  return v2798;
}

struct StateT * slot_177(struct StateT * v3180) {
  int v3181 = v3180->timer;
  int v3189 = v3181 + 1;
  v3180->timer = v3189;
  int * v3183 = v3180->regs;
  int v3184 = v3183[7];
  int v3185 = v3183[12];
  int v3194 = v3184 + v3185;
  v3183[28] = v3194;
  struct StateT * v3187 = slot_178(v3180);
  return v3187;
}

struct StateT * slot_17(struct StateT * v292) {
  int v293 = v292->timer;
  int v301 = v293 + 1;
  v292->timer = v301;
  int * v295 = v292->regs;
  int v296 = v295[5];
  int v297 = v295[17];
  int v305 = v296 + v297;
  v295[17] = v305;
  struct StateT * v299 = slot_18(v292);
  return v299;
}

struct StateT * slot_181(struct StateT * v3263) {
  int v3264 = v3263->timer;
  int v3272 = v3264 + 1;
  v3263->timer = v3272;
  int * v3266 = v3263->regs;
  int v3267 = v3266[13];
  int v3268 = v3266[7];
  int v3276 = v3267 + v3268;
  v3266[13] = v3276;
  struct StateT * v3270 = slot_182(v3263);
  return v3270;
}

struct StateT * slot_197(struct StateT * v3532) {
  int v3533 = v3532->timer;
  int v3541 = v3533 + 1;
  v3532->timer = v3541;
  int * v3535 = v3532->regs;
  int v3536 = v3535[13];
  int v3537 = v3535[17];
  int v3546 = (((((int)((unsigned int)v3536 >> 16)) * ((int)((unsigned int)v3537 >> 16))) + ((int)((unsigned int)((v3536 & 65535) * ((int)((unsigned int)v3537 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3536 >> 16)) * (v3537 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3536 & 65535) * (v3537 & 65535)) >> 16)) + (((v3536 & 65535) * ((int)((unsigned int)v3537 >> 16))) & 65535)) + ((((int)((unsigned int)v3536 >> 16)) * (v3537 & 65535)) & 65535)) >> 16));
  v3535[5] = v3546;
  struct StateT * v3539 = slot_198(v3532);
  return v3539;
}

struct StateT * slot_207(struct StateT * v3707) {
  int v3708 = v3707->timer;
  int v3717 = v3708 + 1;
  v3707->timer = v3717;
  int * v3710 = v3707->regs;
  int v3711 = v3710[10];
  int v3712 = v3710[11];
  int * v3713 = v3707->mem;
  int v3722 = (int)((unsigned int)(v3711 + 32) >> 2);
  v3713[v3722] = v3712;
  struct StateT * v3715 = slot_208(v3707);
  return v3715;
}

struct StateT * slot_156(struct StateT * v2809) {
  int v2810 = v2809->timer;
  int v2819 = v2810 + 1;
  v2809->timer = v2819;
  int * v2812 = v2809->regs;
  int v2813 = v2812[11];
  int * v2814 = v2809->mem;
  int v2823 = (int)((unsigned int)(v2813 + 36) >> 2);
  int v2815 = v2814[v2823];
  v2812[11] = v2815;
  struct StateT * v2817 = slot_157(v2809);
  return v2817;
}

struct StateT * slot_154(struct StateT * v2774) {
  int v2775 = v2774->timer;
  int v2783 = v2775 + 1;
  v2774->timer = v2783;
  int * v2777 = v2774->regs;
  int v2778 = v2777[6];
  int v2779 = v2777[5];
  int v2787 = v2778 + v2779;
  v2777[5] = v2787;
  struct StateT * v2781 = slot_155(v2774);
  return v2781;
}

struct StateT * slot_68(struct StateT * v1219) {
  int v1220 = v1219->timer;
  int v1227 = v1220 + 1;
  v1219->timer = v1227;
  int * v1222 = v1219->regs;
  int v1223 = v1222[7];
  int v1230 = (int)((unsigned int)v1223 >> 19);
  v1222[7] = v1230;
  struct StateT * v1225 = slot_69(v1219);
  return v1225;
}

struct StateT * slot_105(struct StateT * v1902) {
  int v1903 = v1902->timer;
  int v1915 = v1903 + 1;
  v1902->timer = v1915;
  int * v1905 = v1902->regs;
  int v1906 = v1905[7];
  int v1907 = v1905[29];
  bool v1919 = (v1906 ^ -2147483648) < (v1907 ^ -2147483648);
  int v1910;
  if (v1919) {
    v1910 = 1;
  } else {
    v1910 = 0;
  }
  int * v1911 = v1902->regs;
  v1911[28] = v1910;
  struct StateT * v1913 = slot_106(v1902);
  return v1913;
}

struct StateT * slot_27(struct StateT * v475) {
  int v476 = v475->timer;
  int v484 = v476 + 1;
  v475->timer = v484;
  int * v478 = v475->regs;
  int v479 = v478[6];
  int v480 = v478[5];
  int v488 = v479 + v480;
  v478[5] = v488;
  struct StateT * v482 = slot_28(v475);
  return v482;
}

struct StateT * slot_164(struct StateT * v2941) {
  int v2942 = v2941->timer;
  int v2950 = v2942 + 1;
  v2941->timer = v2950;
  int * v2944 = v2941->regs;
  int v2945 = v2944[6];
  int v2946 = v2944[13];
  int v2955 = (((((int)((unsigned int)v2945 >> 16)) * ((int)((unsigned int)v2946 >> 16))) + ((int)((unsigned int)((v2945 & 65535) * ((int)((unsigned int)v2946 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2945 >> 16)) * (v2946 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2945 & 65535) * (v2946 & 65535)) >> 16)) + (((v2945 & 65535) * ((int)((unsigned int)v2946 >> 16))) & 65535)) + ((((int)((unsigned int)v2945 >> 16)) * (v2946 & 65535)) & 65535)) >> 16));
  v2944[31] = v2955;
  struct StateT * v2948 = slot_165(v2941);
  return v2948;
}

struct StateT * slot_15(struct StateT * v259) {
  int v260 = v259->timer;
  int v268 = v260 + 1;
  v259->timer = v268;
  int * v262 = v259->regs;
  int v263 = v262[15];
  int v264 = v262[13];
  int v273 = (((((int)((unsigned int)v263 >> 16)) * ((int)((unsigned int)v264 >> 16))) + ((int)((unsigned int)((v263 & 65535) * ((int)((unsigned int)v264 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v263 >> 16)) * (v264 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v263 & 65535) * (v264 & 65535)) >> 16)) + (((v263 & 65535) * ((int)((unsigned int)v264 >> 16))) & 65535)) + ((((int)((unsigned int)v263 >> 16)) * (v264 & 65535)) & 65535)) >> 16));
  v262[30] = v273;
  struct StateT * v266 = slot_16(v259);
  return v266;
}

struct StateT * slot_133(struct StateT * v2384) {
  int v2385 = v2384->timer;
  int v2393 = v2385 + 1;
  v2384->timer = v2393;
  int * v2387 = v2384->regs;
  int v2388 = v2387[30];
  int v2389 = v2387[7];
  int v2397 = v2388 + v2389;
  v2387[7] = v2397;
  struct StateT * v2391 = slot_134(v2384);
  return v2391;
}

struct StateT * slot_56(struct StateT * v993) {
  int v994 = v993->timer;
  int v1002 = v994 + 1;
  v993->timer = v1002;
  int * v996 = v993->regs;
  int v997 = v996[9];
  int v998 = v996[6];
  int v1006 = v997 + v998;
  v996[6] = v1006;
  struct StateT * v1000 = slot_57(v993);
  return v1000;
}

struct StateT * slot_34(struct StateT * v611) {
  int v612 = v611->timer;
  int v619 = v612 + 1;
  v611->timer = v619;
  int * v614 = v611->regs;
  int v615 = v614[31];
  int v623 = (int)((unsigned int)v615 >> 19);
  v614[29] = v623;
  struct StateT * v617 = slot_35(v611);
  return v617;
}

struct StateT * slot_171(struct StateT * v3065) {
  int v3066 = v3065->timer;
  int v3074 = v3066 + 1;
  v3065->timer = v3074;
  int * v3068 = v3065->regs;
  int v3069 = v3068[30];
  int v3070 = v3068[5];
  int v3079 = v3069 + v3070;
  v3068[6] = v3079;
  struct StateT * v3072 = slot_172(v3065);
  return v3072;
}

struct StateT * slot_162(struct StateT * v2907) {
  int v2908 = v2907->timer;
  int v2916 = v2908 + 1;
  v2907->timer = v2916;
  int * v2910 = v2907->regs;
  int v2911 = v2910[11];
  int v2912 = v2910[12];
  int v2921 = (((((int)((unsigned int)v2911 >> 16)) * ((int)((unsigned int)v2912 >> 16))) + ((int)((unsigned int)((v2911 & 65535) * ((int)((unsigned int)v2912 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2911 >> 16)) * (v2912 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2911 & 65535) * (v2912 & 65535)) >> 16)) + (((v2911 & 65535) * ((int)((unsigned int)v2912 >> 16))) & 65535)) + ((((int)((unsigned int)v2911 >> 16)) * (v2912 & 65535)) & 65535)) >> 16));
  v2910[29] = v2921;
  struct StateT * v2914 = slot_163(v2907);
  return v2914;
}

struct StateT * slot_21(struct StateT * v365) {
  int v366 = v365->timer;
  int v378 = v366 + 1;
  v365->timer = v378;
  int * v368 = v365->regs;
  int v369 = v368[17];
  int v370 = v368[7];
  bool v382 = (v369 ^ -2147483648) < (v370 ^ -2147483648);
  int v373;
  if (v382) {
    v373 = 1;
  } else {
    v373 = 0;
  }
  int * v374 = v365->regs;
  v374[5] = v373;
  struct StateT * v376 = slot_22(v365);
  return v376;
}

struct StateT * slot_118(struct StateT * v2119) {
  int v2120 = v2119->timer;
  int v2127 = v2120 + 1;
  v2119->timer = v2127;
  int * v2122 = v2119->regs;
  int v2123 = v2122[5];
  int v2130 = v2123 << 13;
  v2122[5] = v2130;
  struct StateT * v2125 = slot_119(v2119);
  return v2125;
}

struct StateT * slot_121(struct StateT * v2166) {
  int v2167 = v2166->timer;
  int v2175 = v2167 + 1;
  v2166->timer = v2175;
  int * v2169 = v2166->regs;
  int v2170 = v2169[29];
  int v2171 = v2169[12];
  int v2180 = v2170 * v2171;
  v2169[28] = v2180;
  struct StateT * v2173 = slot_122(v2166);
  return v2173;
}

struct StateT * slot_144(struct StateT * v2589) {
  int v2590 = v2589->timer;
  int v2601 = v2590 + 1;
  v2589->timer = v2601;
  int * v2592 = v2589->regs;
  int v2593 = v2592[7];
  int v2594 = v2592[29];
  bool v2605 = v2593 == v2594;
  struct StateT * v2599;
  if (v2605) {
    struct StateT * v2595 = slot_146(v2589);
    v2599 = v2595;
  } else {
    struct StateT * v2597 = slot_145(v2589);
    v2599 = v2597;
  }
  return v2599;
}

struct StateT * slot_201(struct StateT * v3597) {
  int v3598 = v3597->timer;
  int v3606 = v3598 + 1;
  v3597->timer = v3606;
  int * v3600 = v3597->regs;
  int v3601 = v3600[12];
  int v3602 = v3600[17];
  int v3610 = v3601 * v3602;
  v3600[12] = v3610;
  struct StateT * v3604 = slot_202(v3597);
  return v3604;
}

struct StateT * slot_94(struct StateT * v1675) {
  int v1676 = v1675->timer;
  int v1688 = v1676 + 1;
  v1675->timer = v1688;
  int * v1678 = v1675->regs;
  int v1679 = v1678[29];
  int v1680 = v1678[31];
  bool v1692 = (v1679 ^ -2147483648) < (v1680 ^ -2147483648);
  int v1683;
  if (v1692) {
    v1683 = 1;
  } else {
    v1683 = 0;
  }
  int * v1684 = v1675->regs;
  v1684[6] = v1683;
  struct StateT * v1686 = slot_95(v1675);
  return v1686;
}

struct StateT * slot_63(struct StateT * v1123) {
  int v1124 = v1123->timer;
  int v1132 = v1124 + 1;
  v1123->timer = v1132;
  int * v1126 = v1123->regs;
  int v1127 = v1126[6];
  int v1128 = v1126[30];
  int v1136 = v1127 + v1128;
  v1126[6] = v1136;
  struct StateT * v1130 = slot_64(v1123);
  return v1130;
}

struct StateT * slot_146(struct StateT * v2611) {
  int v2612 = v2611->timer;
  int v2620 = v2612 + 1;
  v2611->timer = v2620;
  int * v2614 = v2611->regs;
  int v2615 = v2614[5];
  int v2616 = v2614[28];
  int v2624 = v2615 + v2616;
  v2614[28] = v2624;
  struct StateT * v2618 = slot_147(v2611);
  return v2618;
}

struct StateT * slot_24(struct StateT * v421) {
  int v422 = v421->timer;
  int v430 = v422 + 1;
  v421->timer = v430;
  int * v424 = v421->regs;
  int v425 = v424[28];
  int v426 = v424[5];
  int v434 = v425 + v426;
  v424[5] = v434;
  struct StateT * v428 = slot_25(v421);
  return v428;
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

struct StateT * slot_195(struct StateT * v3502) {
  int v3503 = v3502->timer;
  int v3510 = v3503 + 1;
  v3502->timer = v3510;
  int * v3505 = v3502->regs;
  int v3506 = v3505[12];
  int v3513 = v3506 << 13;
  v3505[12] = v3513;
  struct StateT * v3508 = slot_196(v3502);
  return v3508;
}

struct StateT * slot_125(struct StateT * v2234) {
  int v2235 = v2234->timer;
  int v2243 = v2235 + 1;
  v2234->timer = v2243;
  int * v2237 = v2234->regs;
  int v2238 = v2237[29];
  int v2239 = v2237[13];
  int v2248 = v2238 * v2239;
  v2237[9] = v2248;
  struct StateT * v2241 = slot_126(v2234);
  return v2241;
}

struct StateT * slot_148(struct StateT * v2669) {
  int v2670 = v2669->timer;
  int v2677 = v2670 + 1;
  v2669->timer = v2677;
  int * v2672 = v2669->regs;
  int v2673 = v2672[7];
  int v2680 = (int)((unsigned int)v2673 >> 19);
  v2672[7] = v2680;
  struct StateT * v2675 = slot_149(v2669);
  return v2675;
}

struct StateT * slot_126(struct StateT * v2251) {
  int v2252 = v2251->timer;
  int v2260 = v2252 + 1;
  v2251->timer = v2260;
  int * v2254 = v2251->regs;
  int v2255 = v2254[29];
  int v2256 = v2254[13];
  int v2265 = (((((int)((unsigned int)v2255 >> 16)) * ((int)((unsigned int)v2256 >> 16))) + ((int)((unsigned int)((v2255 & 65535) * ((int)((unsigned int)v2256 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2255 >> 16)) * (v2256 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2255 & 65535) * (v2256 & 65535)) >> 16)) + (((v2255 & 65535) * ((int)((unsigned int)v2256 >> 16))) & 65535)) + ((((int)((unsigned int)v2255 >> 16)) * (v2256 & 65535)) & 65535)) >> 16));
  v2254[18] = v2265;
  struct StateT * v2258 = slot_127(v2251);
  return v2258;
}

struct StateT * slot_79(struct StateT * v1408) {
  int v1409 = v1408->timer;
  int v1417 = v1409 + 1;
  v1408->timer = v1417;
  int * v1411 = v1408->regs;
  int v1412 = v1411[5];
  int v1413 = v1411[17];
  int v1421 = v1412 | v1413;
  v1411[5] = v1421;
  struct StateT * v1415 = slot_80(v1408);
  return v1415;
}

struct StateT * slot_41(struct StateT * v723) {
  int v724 = v723->timer;
  int v732 = v724 + 1;
  v723->timer = v732;
  int * v726 = v723->regs;
  int v727 = v726[7];
  int v728 = v726[13];
  int v737 = v727 * v728;
  v726[8] = v737;
  struct StateT * v730 = slot_42(v723);
  return v730;
}

struct StateT * slot_39(struct StateT * v689) {
  int v690 = v689->timer;
  int v698 = v690 + 1;
  v689->timer = v698;
  int * v692 = v689->regs;
  int v693 = v692[28];
  int v694 = v692[12];
  int v703 = v693 * v694;
  v692[30] = v703;
  struct StateT * v696 = slot_40(v689);
  return v696;
}

struct StateT * slot_142(struct StateT * v2556) {
  int v2557 = v2556->timer;
  int v2565 = v2557 + 1;
  v2556->timer = v2565;
  int * v2559 = v2556->regs;
  int v2560 = v2559[30];
  int v2561 = v2559[28];
  int v2570 = v2560 + v2561;
  v2559[7] = v2570;
  struct StateT * v2563 = slot_143(v2556);
  return v2563;
}

struct StateT * slot_60(struct StateT * v1066) {
  int v1067 = v1066->timer;
  int v1079 = v1067 + 1;
  v1066->timer = v1079;
  int * v1069 = v1066->regs;
  int v1070 = v1069[5];
  int v1071 = v1069[18];
  bool v1083 = (v1070 ^ -2147483648) < (v1071 ^ -2147483648);
  int v1074;
  if (v1083) {
    v1074 = 1;
  } else {
    v1074 = 0;
  }
  int * v1075 = v1066->regs;
  v1075[30] = v1074;
  struct StateT * v1077 = slot_61(v1066);
  return v1077;
}

struct StateT * slot_112(struct StateT * v2020) {
  int v2021 = v2020->timer;
  int v2028 = v2021 + 1;
  v2020->timer = v2028;
  int * v2023 = v2020->regs;
  int v2024 = v2023[28];
  int v2032 = (int)((unsigned int)v2024 >> 19);
  v2023[17] = v2032;
  struct StateT * v2026 = slot_113(v2020);
  return v2026;
}

struct StateT * slot_47(struct StateT * v821) {
  int v822 = v821->timer;
  int v830 = v822 + 1;
  v821->timer = v830;
  int * v824 = v821->regs;
  int v825 = v824[7];
  int v826 = v824[12];
  int v834 = v825 * v826;
  v824[7] = v834;
  struct StateT * v828 = slot_48(v821);
  return v828;
}

struct StateT * slot_214(struct StateT * v3835) {
  int v3836 = v3835->timer;
  int v3839 = v3836 + 1;
  v3835->timer = v3839;
  return v3835;
}

struct StateT * slot_29(struct StateT * v510) {
  int v511 = v510->timer;
  int v520 = v511 + 1;
  v510->timer = v520;
  int * v513 = v510->regs;
  int v514 = v513[11];
  int * v515 = v510->mem;
  int v524 = (int)((unsigned int)(v514 + 12) >> 2);
  int v516 = v515[v524];
  v513[28] = v516;
  struct StateT * v518 = slot_30(v510);
  return v518;
}

struct StateT * slot_16(struct StateT * v276) {
  int v277 = v276->timer;
  int v285 = v277 + 1;
  v276->timer = v285;
  int * v279 = v276->regs;
  int v280 = v279[14];
  int v281 = v279[12];
  int v289 = v280 * v281;
  v279[14] = v289;
  struct StateT * v283 = slot_17(v276);
  return v283;
}

struct StateT * slot_113(struct StateT * v2035) {
  int v2036 = v2035->timer;
  int v2043 = v2036 + 1;
  v2035->timer = v2043;
  int * v2038 = v2035->regs;
  int v2039 = v2038[28];
  int v2046 = v2039 << 13;
  v2038[28] = v2046;
  struct StateT * v2041 = slot_114(v2035);
  return v2041;
}

struct StateT * slot_151(struct StateT * v2726) {
  int v2727 = v2726->timer;
  int v2736 = v2727 + 1;
  v2726->timer = v2736;
  int * v2729 = v2726->regs;
  int v2730 = v2729[10];
  int v2731 = v2729[29];
  int * v2732 = v2726->mem;
  int v2741 = (int)((unsigned int)(v2730 + 28) >> 2);
  v2732[v2741] = v2731;
  struct StateT * v2734 = slot_152(v2726);
  return v2734;
}

struct StateT * slot_7(struct StateT * v130) {
  int v131 = v130->timer;
  int v137 = v131 + 1;
  v130->timer = v137;
  int * v133 = v130->regs;
  v133[16] = 524288;
  struct StateT * v135 = slot_8(v130);
  return v135;
}

struct StateT * slot_124(struct StateT * v2217) {
  int v2218 = v2217->timer;
  int v2226 = v2218 + 1;
  v2217->timer = v2226;
  int * v2220 = v2217->regs;
  int v2221 = v2220[6];
  int v2222 = v2220[13];
  int v2231 = (((((int)((unsigned int)v2221 >> 16)) * ((int)((unsigned int)v2222 >> 16))) + ((int)((unsigned int)((v2221 & 65535) * ((int)((unsigned int)v2222 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2221 >> 16)) * (v2222 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2221 & 65535) * (v2222 & 65535)) >> 16)) + (((v2221 & 65535) * ((int)((unsigned int)v2222 >> 16))) & 65535)) + ((((int)((unsigned int)v2221 >> 16)) * (v2222 & 65535)) & 65535)) >> 16));
  v2220[8] = v2231;
  struct StateT * v2224 = slot_125(v2217);
  return v2224;
}

struct StateT * slot_191(struct StateT * v3444) {
  int v3445 = v3444->timer;
  int v3452 = v3445 + 1;
  v3444->timer = v3452;
  int * v3447 = v3444->regs;
  int v3448 = v3447[5];
  int v3456 = v3448 << 13;
  v3447[13] = v3456;
  struct StateT * v3450 = slot_192(v3444);
  return v3450;
}

struct StateT * slot_103(struct StateT * v1848) {
  int v1849 = v1848->timer;
  int v1857 = v1849 + 1;
  v1848->timer = v1857;
  int * v1851 = v1848->regs;
  int v1852 = v1851[6];
  int v1853 = v1851[31];
  int v1861 = v1852 + v1853;
  v1851[6] = v1861;
  struct StateT * v1855 = slot_104(v1848);
  return v1855;
}

struct StateT * slot_128(struct StateT * v2284) {
  int v2285 = v2284->timer;
  int v2293 = v2285 + 1;
  v2284->timer = v2293;
  int * v2287 = v2284->regs;
  int v2288 = v2287[28];
  int v2289 = v2287[17];
  int v2298 = v2288 + v2289;
  v2287[29] = v2298;
  struct StateT * v2291 = slot_129(v2284);
  return v2291;
}

struct StateT * slot_19(struct StateT * v333) {
  int v334 = v333->timer;
  int v342 = v334 + 1;
  v333->timer = v342;
  int * v336 = v333->regs;
  int v337 = v336[7];
  int v338 = v336[17];
  int v346 = v337 + v338;
  v336[17] = v346;
  struct StateT * v340 = slot_20(v333);
  return v340;
}

struct StateT * slot_87(struct StateT * v1543) {
  int v1544 = v1543->timer;
  int v1552 = v1544 + 1;
  v1543->timer = v1552;
  int * v1546 = v1543->regs;
  int v1547 = v1546[6];
  int v1548 = v1546[12];
  int v1556 = v1547 * v1548;
  v1546[6] = v1556;
  struct StateT * v1550 = slot_88(v1543);
  return v1550;
}

struct StateT * slot_67(struct StateT * v1202) {
  int v1203 = v1202->timer;
  int v1211 = v1203 + 1;
  v1202->timer = v1211;
  int * v1205 = v1202->regs;
  int v1206 = v1205[7];
  int v1207 = v1205[16];
  int v1216 = v1206 & v1207;
  v1205[29] = v1216;
  struct StateT * v1209 = slot_68(v1202);
  return v1209;
}

struct StateT * slot_81(struct StateT * v1441) {
  int v1442 = v1441->timer;
  int v1450 = v1442 + 1;
  v1441->timer = v1450;
  int * v1444 = v1441->regs;
  int v1445 = v1444[29];
  int v1446 = v1444[12];
  int v1455 = v1445 * v1446;
  v1444[28] = v1455;
  struct StateT * v1448 = slot_82(v1441);
  return v1448;
}

struct StateT * slot_95(struct StateT * v1700) {
  int v1701 = v1700->timer;
  int v1709 = v1701 + 1;
  v1700->timer = v1709;
  int * v1703 = v1700->regs;
  int v1704 = v1703[29];
  int v1705 = v1703[5];
  int v1714 = v1704 + v1705;
  v1703[30] = v1714;
  struct StateT * v1707 = slot_96(v1700);
  return v1707;
}

struct StateT * slot_115(struct StateT * v2065) {
  int v2066 = v2065->timer;
  int v2075 = v2066 + 1;
  v2065->timer = v2075;
  int * v2068 = v2065->regs;
  int v2069 = v2068[11];
  int * v2070 = v2065->mem;
  int v2079 = (int)((unsigned int)(v2069 + 24) >> 2);
  int v2071 = v2070[v2079];
  v2068[6] = v2071;
  struct StateT * v2073 = slot_116(v2065);
  return v2073;
}

struct StateT * slot_78(struct StateT * v1394) {
  int v1395 = v1394->timer;
  int v1402 = v1395 + 1;
  v1394->timer = v1402;
  int * v1397 = v1394->regs;
  int v1398 = v1397[5];
  int v1405 = v1398 << 13;
  v1397[5] = v1405;
  struct StateT * v1400 = slot_79(v1394);
  return v1400;
}

struct StateT * slot_32(struct StateT * v570) {
  int v571 = v570->timer;
  int v583 = v571 + 1;
  v570->timer = v583;
  int * v573 = v570->regs;
  int v574 = v573[31];
  int v575 = v573[29];
  bool v587 = (v574 ^ -2147483648) < (v575 ^ -2147483648);
  int v578;
  if (v587) {
    v578 = 1;
  } else {
    v578 = 0;
  }
  int * v579 = v570->regs;
  v579[6] = v578;
  struct StateT * v581 = slot_33(v570);
  return v581;
}

struct StateT * slot_205(struct StateT * v3669) {
  int v3670 = v3669->timer;
  int v3679 = v3670 + 1;
  v3669->timer = v3679;
  int * v3672 = v3669->regs;
  int v3673 = v3672[10];
  int v3674 = v3672[13];
  int * v3675 = v3669->mem;
  int v3684 = (int)((unsigned int)v3673 >> 2);
  v3675[v3684] = v3674;
  struct StateT * v3677 = slot_206(v3669);
  return v3677;
}

struct StateT * slot_193(struct StateT * v3475) {
  int v3476 = v3475->timer;
  int v3482 = v3476 + 1;
  v3475->timer = v3482;
  int * v3478 = v3475->regs;
  v3478[17] = 19;
  struct StateT * v3480 = slot_194(v3475);
  return v3480;
}

struct StateT * slot_176(struct StateT * v3164) {
  int v3165 = v3164->timer;
  int v3173 = v3165 + 1;
  v3164->timer = v3173;
  int * v3167 = v3164->regs;
  int v3168 = v3167[31];
  int v3169 = v3167[12];
  int v3177 = v3168 + v3169;
  v3167[12] = v3177;
  struct StateT * v3171 = slot_177(v3164);
  return v3171;
}

struct StateT * slot_189(struct StateT * v3404) {
  int v3405 = v3404->timer;
  int v3417 = v3405 + 1;
  v3404->timer = v3417;
  int * v3407 = v3404->regs;
  int v3408 = v3407[5];
  int v3409 = v3407[12];
  bool v3421 = (v3408 ^ -2147483648) < (v3409 ^ -2147483648);
  int v3412;
  if (v3421) {
    v3412 = 1;
  } else {
    v3412 = 0;
  }
  int * v3413 = v3404->regs;
  v3413[12] = v3412;
  struct StateT * v3415 = slot_190(v3404);
  return v3415;
}

struct StateT * slot_33(struct StateT * v595) {
  int v596 = v595->timer;
  int v604 = v596 + 1;
  v595->timer = v604;
  int * v598 = v595->regs;
  int v599 = v598[30];
  int v600 = v598[5];
  int v608 = v599 + v600;
  v598[5] = v608;
  struct StateT * v602 = slot_34(v595);
  return v602;
}

struct StateT * slot_35(struct StateT * v626) {
  int v627 = v626->timer;
  int v634 = v627 + 1;
  v626->timer = v634;
  int * v629 = v626->regs;
  int v630 = v629[31];
  int v637 = v630 << 13;
  v629[31] = v637;
  struct StateT * v632 = slot_36(v626);
  return v632;
}

struct StateT * slot_210(struct StateT * v3764) {
  int v3765 = v3764->timer;
  int v3774 = v3765 + 1;
  v3764->timer = v3774;
  int * v3767 = v3764->regs;
  int v3768 = v3767[2];
  int * v3769 = v3764->mem;
  int v3778 = (int)((unsigned int)(v3768 + 8) >> 2);
  int v3770 = v3769[v3778];
  v3767[9] = v3770;
  struct StateT * v3772 = slot_211(v3764);
  return v3772;
}

struct StateT * slot_166(struct StateT * v2975) {
  int v2976 = v2975->timer;
  int v2984 = v2976 + 1;
  v2975->timer = v2984;
  int * v2978 = v2975->regs;
  int v2979 = v2978[11];
  int v2980 = v2978[13];
  int v2988 = (((((int)((unsigned int)v2979 >> 16)) * ((int)((unsigned int)v2980 >> 16))) + ((int)((unsigned int)((v2979 & 65535) * ((int)((unsigned int)v2980 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2979 >> 16)) * (v2980 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2979 & 65535) * (v2980 & 65535)) >> 16)) + (((v2979 & 65535) * ((int)((unsigned int)v2980 >> 16))) & 65535)) + ((((int)((unsigned int)v2979 >> 16)) * (v2980 & 65535)) & 65535)) >> 16));
  v2978[13] = v2988;
  struct StateT * v2982 = slot_167(v2975);
  return v2982;
}

struct StateT * slot_51(struct StateT * v893) {
  int v894 = v893->timer;
  int v902 = v894 + 1;
  v893->timer = v902;
  int * v896 = v893->regs;
  int v897 = v896[8];
  int v898 = v896[6];
  int v907 = v897 + v898;
  v896[29] = v907;
  struct StateT * v900 = slot_52(v893);
  return v900;
}

struct StateT * slot_52(struct StateT * v910) {
  int v911 = v910->timer;
  int v923 = v911 + 1;
  v910->timer = v923;
  int * v913 = v910->regs;
  int v914 = v913[17];
  int v915 = v913[7];
  bool v927 = (v914 ^ -2147483648) < (v915 ^ -2147483648);
  int v918;
  if (v927) {
    v918 = 1;
  } else {
    v918 = 0;
  }
  int * v919 = v910->regs;
  v919[28] = v918;
  struct StateT * v921 = slot_53(v910);
  return v921;
}

struct StateT * slot_83(struct StateT * v1475) {
  int v1476 = v1475->timer;
  int v1484 = v1476 + 1;
  v1475->timer = v1484;
  int * v1478 = v1475->regs;
  int v1479 = v1478[6];
  int v1480 = v1478[13];
  int v1489 = v1479 * v1480;
  v1478[31] = v1489;
  struct StateT * v1482 = slot_84(v1475);
  return v1482;
}

struct StateT * slot_25(struct StateT * v437) {
  int v438 = v437->timer;
  int v447 = v438 + 1;
  v437->timer = v447;
  int * v440 = v437->regs;
  int v441 = v440[10];
  int v442 = v440[14];
  int * v443 = v437->mem;
  int v452 = (int)((unsigned int)v441 >> 2);
  v443[v452] = v442;
  struct StateT * v445 = slot_26(v437);
  return v445;
}

struct StateT * slot_209(struct StateT * v3745) {
  int v3746 = v3745->timer;
  int v3755 = v3746 + 1;
  v3745->timer = v3755;
  int * v3748 = v3745->regs;
  int v3749 = v3748[2];
  int * v3750 = v3745->mem;
  int v3759 = (int)((unsigned int)(v3749 + 12) >> 2);
  int v3751 = v3750[v3759];
  v3748[8] = v3751;
  struct StateT * v3753 = slot_210(v3745);
  return v3753;
}

struct StateT * slot_3(struct StateT * v54) {
  int v55 = v54->timer;
  int v64 = v55 + 1;
  v54->timer = v64;
  int * v57 = v54->regs;
  int v58 = v57[2];
  int v59 = v57[18];
  int * v60 = v54->mem;
  int v69 = (int)((unsigned int)(v58 + 4) >> 2);
  v60[v69] = v59;
  struct StateT * v62 = slot_4(v54);
  return v62;
}

struct StateT * slot_123(struct StateT * v2200) {
  int v2201 = v2200->timer;
  int v2209 = v2201 + 1;
  v2200->timer = v2209;
  int * v2203 = v2200->regs;
  int v2204 = v2203[6];
  int v2205 = v2203[13];
  int v2214 = v2204 * v2205;
  v2203[31] = v2214;
  struct StateT * v2207 = slot_124(v2200);
  return v2207;
}

struct StateT * slot_73(struct StateT * v1310) {
  int v1311 = v1310->timer;
  int v1318 = v1311 + 1;
  v1310->timer = v1318;
  int * v1313 = v1310->regs;
  int v1314 = v1313[28];
  int v1321 = v1314 << 13;
  v1313[28] = v1321;
  struct StateT * v1316 = slot_74(v1310);
  return v1316;
}

struct StateT * slot_198(struct StateT * v3549) {
  int v3550 = v3549->timer;
  int v3558 = v3550 + 1;
  v3549->timer = v3558;
  int * v3552 = v3549->regs;
  int v3553 = v3552[13];
  int v3554 = v3552[17];
  int v3562 = v3553 * v3554;
  v3552[13] = v3562;
  struct StateT * v3556 = slot_199(v3549);
  return v3556;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v26 = v17 + 1;
  v16->timer = v26;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->mem;
  int v31 = (int)((unsigned int)(v20 + 12) >> 2);
  v22[v31] = v21;
  struct StateT * v24 = slot_2(v16);
  return v24;
}

struct StateT * slot_187(struct StateT * v3374) {
  int v3375 = v3374->timer;
  int v3383 = v3375 + 1;
  v3374->timer = v3383;
  int * v3377 = v3374->regs;
  int v3378 = v3377[17];
  int v3379 = v3377[16];
  int v3387 = v3378 & v3379;
  v3377[16] = v3387;
  struct StateT * v3381 = slot_188(v3374);
  return v3381;
}

struct StateT * slot_97(struct StateT * v1733) {
  int v1734 = v1733->timer;
  int v1742 = v1734 + 1;
  v1733->timer = v1742;
  int * v1736 = v1733->regs;
  int v1737 = v1736[7];
  int v1738 = v1736[6];
  int v1746 = v1737 + v1738;
  v1736[6] = v1746;
  struct StateT * v1740 = slot_98(v1733);
  return v1740;
}

struct StateT * slot_182(struct StateT * v3279) {
  int v3280 = v3279->timer;
  int v3288 = v3280 + 1;
  v3279->timer = v3288;
  int * v3282 = v3279->regs;
  int v3283 = v3282[17];
  int v3284 = v3282[5];
  int v3292 = v3283 + v3284;
  v3282[17] = v3292;
  struct StateT * v3286 = slot_183(v3279);
  return v3286;
}

struct StateT * slot_38(struct StateT * v672) {
  int v673 = v672->timer;
  int v681 = v673 + 1;
  v672->timer = v681;
  int * v675 = v672->regs;
  int v676 = v675[7];
  int v677 = v675[12];
  int v686 = (((((int)((unsigned int)v676 >> 16)) * ((int)((unsigned int)v677 >> 16))) + ((int)((unsigned int)((v676 & 65535) * ((int)((unsigned int)v677 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v676 >> 16)) * (v677 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v676 & 65535) * (v677 & 65535)) >> 16)) + (((v676 & 65535) * ((int)((unsigned int)v677 >> 16))) & 65535)) + ((((int)((unsigned int)v676 >> 16)) * (v677 & 65535)) & 65535)) >> 16));
  v675[6] = v686;
  struct StateT * v679 = slot_39(v672);
  return v679;
}

struct StateT * slot_178(struct StateT * v3197) {
  int v3198 = v3197->timer;
  int v3206 = v3198 + 1;
  v3197->timer = v3206;
  int * v3200 = v3197->regs;
  int v3201 = v3200[8];
  int v3202 = v3200[28];
  int v3211 = v3201 + v3202;
  v3200[12] = v3211;
  struct StateT * v3204 = slot_179(v3197);
  return v3204;
}

struct StateT * slot_106(struct StateT * v1886) {
  int v1887 = v1886->timer;
  int v1895 = v1887 + 1;
  v1886->timer = v1895;
  int * v1889 = v1886->regs;
  int v1890 = v1889[5];
  int v1891 = v1889[28];
  int v1899 = v1890 + v1891;
  v1889[28] = v1899;
  struct StateT * v1893 = slot_107(v1886);
  return v1893;
}

struct StateT * slot_98(struct StateT * v1749) {
  int v1750 = v1749->timer;
  int v1758 = v1750 + 1;
  v1749->timer = v1758;
  int * v1752 = v1749->regs;
  int v1753 = v1752[9];
  int v1754 = v1752[6];
  int v1763 = v1753 + v1754;
  v1752[5] = v1763;
  struct StateT * v1756 = slot_99(v1749);
  return v1756;
}

struct StateT * slot_159(struct StateT * v2857) {
  int v2858 = v2857->timer;
  int v2866 = v2858 + 1;
  v2857->timer = v2866;
  int * v2860 = v2857->regs;
  int v2861 = v2860[5];
  int v2862 = v2860[17];
  int v2870 = v2861 | v2862;
  v2860[17] = v2870;
  struct StateT * v2864 = slot_160(v2857);
  return v2864;
}

struct StateT * slot_46(struct StateT * v804) {
  int v805 = v804->timer;
  int v813 = v805 + 1;
  v804->timer = v813;
  int * v807 = v804->regs;
  int v808 = v807[28];
  int v809 = v807[13];
  int v818 = (((((int)((unsigned int)v808 >> 16)) * ((int)((unsigned int)v809 >> 16))) + ((int)((unsigned int)((v808 & 65535) * ((int)((unsigned int)v809 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v808 >> 16)) * (v809 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v808 & 65535) * (v809 & 65535)) >> 16)) + (((v808 & 65535) * ((int)((unsigned int)v809 >> 16))) & 65535)) + ((((int)((unsigned int)v808 >> 16)) * (v809 & 65535)) & 65535)) >> 16));
  v807[19] = v818;
  struct StateT * v811 = slot_47(v804);
  return v811;
}

struct StateT * slot_212(struct StateT * v3802) {
  int v3803 = v3802->timer;
  int v3812 = v3803 + 1;
  v3802->timer = v3812;
  int * v3805 = v3802->regs;
  int v3806 = v3805[2];
  int * v3807 = v3802->mem;
  int v3816 = (int)((unsigned int)v3806 >> 2);
  int v3808 = v3807[v3816];
  v3805[19] = v3808;
  struct StateT * v3810 = slot_213(v3802);
  return v3810;
}

struct StateT * slot_132(struct StateT * v2359) {
  int v2360 = v2359->timer;
  int v2372 = v2360 + 1;
  v2359->timer = v2372;
  int * v2362 = v2359->regs;
  int v2363 = v2362[17];
  int v2364 = v2362[6];
  bool v2376 = (v2363 ^ -2147483648) < (v2364 ^ -2147483648);
  int v2367;
  if (v2376) {
    v2367 = 1;
  } else {
    v2367 = 0;
  }
  int * v2368 = v2359->regs;
  v2368[28] = v2367;
  struct StateT * v2370 = slot_133(v2359);
  return v2370;
}

struct StateT * slot_130(struct StateT * v2318) {
  int v2319 = v2318->timer;
  int v2331 = v2319 + 1;
  v2318->timer = v2331;
  int * v2321 = v2318->regs;
  int v2322 = v2321[29];
  int v2323 = v2321[28];
  bool v2335 = (v2322 ^ -2147483648) < (v2323 ^ -2147483648);
  int v2326;
  if (v2335) {
    v2326 = 1;
  } else {
    v2326 = 0;
  }
  int * v2327 = v2318->regs;
  v2327[7] = v2326;
  struct StateT * v2329 = slot_131(v2318);
  return v2329;
}

struct StateT * slot_211(struct StateT * v3783) {
  int v3784 = v3783->timer;
  int v3793 = v3784 + 1;
  v3783->timer = v3793;
  int * v3786 = v3783->regs;
  int v3787 = v3786[2];
  int * v3788 = v3783->mem;
  int v3797 = (int)((unsigned int)(v3787 + 4) >> 2);
  int v3789 = v3788[v3797];
  v3786[18] = v3789;
  struct StateT * v3791 = slot_212(v3783);
  return v3791;
}

struct StateT * slot_20(struct StateT * v349) {
  int v350 = v349->timer;
  int v358 = v350 + 1;
  v349->timer = v358;
  int * v352 = v349->regs;
  int v353 = v352[6];
  int v354 = v352[15];
  int v362 = v353 + v354;
  v352[6] = v362;
  struct StateT * v356 = slot_21(v349);
  return v356;
}

struct StateT * slot_141(struct StateT * v2540) {
  int v2541 = v2540->timer;
  int v2549 = v2541 + 1;
  v2540->timer = v2549;
  int * v2543 = v2540->regs;
  int v2544 = v2543[18];
  int v2545 = v2543[6];
  int v2553 = v2544 + v2545;
  v2543[6] = v2553;
  struct StateT * v2547 = slot_142(v2540);
  return v2547;
}

struct StateT * slot_61(struct StateT * v1091) {
  int v1092 = v1091->timer;
  int v1100 = v1092 + 1;
  v1091->timer = v1100;
  int * v1094 = v1091->regs;
  int v1095 = v1094[19];
  int v1096 = v1094[6];
  int v1104 = v1095 + v1096;
  v1094[6] = v1104;
  struct StateT * v1098 = slot_62(v1091);
  return v1098;
}

struct StateT * slot_30(struct StateT * v529) {
  int v530 = v529->timer;
  int v538 = v530 + 1;
  v529->timer = v538;
  int * v532 = v529->regs;
  int v533 = v532[29];
  int v534 = v532[5];
  int v543 = v533 + v534;
  v532[31] = v543;
  struct StateT * v536 = slot_31(v529);
  return v536;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v83 = v74 + 1;
  v73->timer = v83;
  int * v76 = v73->regs;
  int v77 = v76[2];
  int v78 = v76[19];
  int * v79 = v73->mem;
  int v88 = (int)((unsigned int)v77 >> 2);
  v79[v88] = v78;
  struct StateT * v81 = slot_5(v73);
  return v81;
}

struct StateT * slot_18(struct StateT * v308) {
  int v309 = v308->timer;
  int v321 = v309 + 1;
  v308->timer = v321;
  int * v311 = v308->regs;
  int v312 = v311[17];
  int v313 = v311[5];
  bool v325 = (v312 ^ -2147483648) < (v313 ^ -2147483648);
  int v316;
  if (v325) {
    v316 = 1;
  } else {
    v316 = 0;
  }
  int * v317 = v308->regs;
  v317[15] = v316;
  struct StateT * v319 = slot_19(v308);
  return v319;
}

struct StateT * slot_9(struct StateT * v157) {
  int v158 = v157->timer;
  int v166 = v158 + 1;
  v157->timer = v166;
  int * v160 = v157->regs;
  int v161 = v160[14];
  int v162 = v160[12];
  int v171 = (((((int)((unsigned int)v161 >> 16)) * ((int)((unsigned int)v162 >> 16))) + ((int)((unsigned int)((v161 & 65535) * ((int)((unsigned int)v162 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v161 >> 16)) * (v162 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v161 & 65535) * (v162 & 65535)) >> 16)) + (((v161 & 65535) * ((int)((unsigned int)v162 >> 16))) & 65535)) + ((((int)((unsigned int)v161 >> 16)) * (v162 & 65535)) & 65535)) >> 16));
  v160[17] = v171;
  struct StateT * v164 = slot_10(v157);
  return v164;
}

struct StateT * slot_183(struct StateT * v3295) {
  int v3296 = v3295->timer;
  int v3304 = v3296 + 1;
  v3295->timer = v3304;
  int * v3298 = v3295->regs;
  int v3299 = v3298[13];
  int v3300 = v3298[28];
  int v3308 = v3299 + v3300;
  v3298[13] = v3308;
  struct StateT * v3302 = slot_184(v3295);
  return v3302;
}

struct StateT * slot_43(struct StateT * v757) {
  int v758 = v757->timer;
  int v765 = v758 + 1;
  v757->timer = v765;
  int * v760 = v757->regs;
  int v761 = v760[5];
  int v768 = v761 << 13;
  v760[5] = v768;
  struct StateT * v763 = slot_44(v757);
  return v763;
}

struct StateT * slot_70(struct StateT * v1257) {
  int v1258 = v1257->timer;
  int v1267 = v1258 + 1;
  v1257->timer = v1267;
  int * v1260 = v1257->regs;
  int v1261 = v1260[10];
  int v1262 = v1260[17];
  int * v1263 = v1257->mem;
  int v1272 = (int)((unsigned int)(v1261 + 8) >> 2);
  v1263[v1272] = v1262;
  struct StateT * v1265 = slot_71(v1257);
  return v1265;
}

struct StateT * slot_168(struct StateT * v3007) {
  int v3008 = v3007->timer;
  int v3016 = v3008 + 1;
  v3007->timer = v3016;
  int * v3010 = v3007->regs;
  int v3011 = v3010[28];
  int v3012 = v3010[5];
  int v3020 = v3011 + v3012;
  v3010[5] = v3020;
  struct StateT * v3014 = slot_169(v3007);
  return v3014;
}

struct StateT * slot_76(struct StateT * v1359) {
  int v1360 = v1359->timer;
  int v1369 = v1360 + 1;
  v1359->timer = v1369;
  int * v1362 = v1359->regs;
  int v1363 = v1362[11];
  int * v1364 = v1359->mem;
  int v1373 = (int)((unsigned int)(v1363 + 20) >> 2);
  int v1365 = v1364[v1373];
  v1362[29] = v1365;
  struct StateT * v1367 = slot_77(v1359);
  return v1367;
}

struct StateT * slot_6(struct StateT * v111) {
  int v112 = v111->timer;
  int v121 = v112 + 1;
  v111->timer = v121;
  int * v114 = v111->regs;
  int v115 = v114[11];
  int * v116 = v111->mem;
  int v125 = (int)((unsigned int)(v115 + 4) >> 2);
  int v117 = v116[v125];
  v114[15] = v117;
  struct StateT * v119 = slot_7(v111);
  return v119;
}

struct StateT * slot_55(struct StateT * v976) {
  int v977 = v976->timer;
  int v985 = v977 + 1;
  v976->timer = v985;
  int * v979 = v976->regs;
  int v980 = v979[29];
  int v981 = v979[5];
  int v990 = v980 + v981;
  v979[7] = v990;
  struct StateT * v983 = slot_56(v976);
  return v983;
}

struct StateT * slot_213(struct StateT * v3821) {
  int v3822 = v3821->timer;
  int v3829 = v3822 + 1;
  v3821->timer = v3829;
  int * v3824 = v3821->regs;
  int v3825 = v3824[2];
  int v3832 = v3825 + 16;
  v3824[2] = v3832;
  struct StateT * v3827 = slot_214(v3821);
  return v3827;
}

struct StateT * slot_82(struct StateT * v1458) {
  int v1459 = v1458->timer;
  int v1467 = v1459 + 1;
  v1458->timer = v1467;
  int * v1461 = v1458->regs;
  int v1462 = v1461[29];
  int v1463 = v1461[12];
  int v1472 = (((((int)((unsigned int)v1462 >> 16)) * ((int)((unsigned int)v1463 >> 16))) + ((int)((unsigned int)((v1462 & 65535) * ((int)((unsigned int)v1463 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1462 >> 16)) * (v1463 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1462 & 65535) * (v1463 & 65535)) >> 16)) + (((v1462 & 65535) * ((int)((unsigned int)v1463 >> 16))) & 65535)) + ((((int)((unsigned int)v1462 >> 16)) * (v1463 & 65535)) & 65535)) >> 16));
  v1461[30] = v1472;
  struct StateT * v1465 = slot_83(v1458);
  return v1465;
}

struct StateT * slot_161(struct StateT * v2890) {
  int v2891 = v2890->timer;
  int v2899 = v2891 + 1;
  v2890->timer = v2899;
  int * v2893 = v2890->regs;
  int v2894 = v2893[11];
  int v2895 = v2893[12];
  int v2904 = v2894 * v2895;
  v2893[28] = v2904;
  struct StateT * v2897 = slot_162(v2890);
  return v2897;
}

struct StateT * slot_185(struct StateT * v3349) {
  int v3350 = v3349->timer;
  int v3362 = v3350 + 1;
  v3349->timer = v3362;
  int * v3352 = v3349->regs;
  int v3353 = v3352[17];
  int v3354 = v3352[6];
  bool v3366 = (v3353 ^ -2147483648) < (v3354 ^ -2147483648);
  int v3357;
  if (v3366) {
    v3357 = 1;
  } else {
    v3357 = 0;
  }
  int * v3358 = v3349->regs;
  v3358[5] = v3357;
  struct StateT * v3360 = slot_186(v3349);
  return v3360;
}

struct StateT * slot_91(struct StateT * v1618) {
  int v1619 = v1618->timer;
  int v1627 = v1619 + 1;
  v1618->timer = v1627;
  int * v1621 = v1618->regs;
  int v1622 = v1621[31];
  int v1623 = v1621[29];
  int v1631 = v1622 + v1623;
  v1621[29] = v1631;
  struct StateT * v1625 = slot_92(v1618);
  return v1625;
}

struct StateT * slot_58(struct StateT * v1025) {
  int v1026 = v1025->timer;
  int v1034 = v1026 + 1;
  v1025->timer = v1034;
  int * v1028 = v1025->regs;
  int v1029 = v1028[18];
  int v1030 = v1028[6];
  int v1039 = v1029 + v1030;
  v1028[5] = v1039;
  struct StateT * v1032 = slot_59(v1025);
  return v1032;
}

struct StateT * slot_89(struct StateT * v1576) {
  int v1577 = v1576->timer;
  int v1585 = v1577 + 1;
  v1576->timer = v1585;
  int * v1579 = v1576->regs;
  int v1580 = v1579[6];
  int v1581 = v1579[7];
  int v1590 = v1580 + v1581;
  v1579[17] = v1590;
  struct StateT * v1583 = slot_90(v1576);
  return v1583;
}

struct StateT * slot_66(struct StateT * v1161) {
  int v1162 = v1161->timer;
  int v1170 = v1162 + 1;
  v1161->timer = v1170;
  int * v1164 = v1161->regs;
  int v1165 = v1164[5];
  int v1166 = v1164[28];
  int v1174 = v1165 + v1166;
  v1164[28] = v1174;
  struct StateT * v1168 = slot_67(v1161);
  return v1168;
}

struct StateT * slot_140(struct StateT * v2515) {
  int v2516 = v2515->timer;
  int v2528 = v2516 + 1;
  v2515->timer = v2528;
  int * v2518 = v2515->regs;
  int v2519 = v2518[5];
  int v2520 = v2518[9];
  bool v2532 = (v2519 ^ -2147483648) < (v2520 ^ -2147483648);
  int v2523;
  if (v2532) {
    v2523 = 1;
  } else {
    v2523 = 0;
  }
  int * v2524 = v2515->regs;
  v2524[31] = v2523;
  struct StateT * v2526 = slot_141(v2515);
  return v2526;
}

struct StateT * slot_49(struct StateT * v853) {
  int v854 = v853->timer;
  int v862 = v854 + 1;
  v853->timer = v862;
  int * v856 = v853->regs;
  int v857 = v856[7];
  int v858 = v856[17];
  int v866 = v857 + v858;
  v856[17] = v866;
  struct StateT * v860 = slot_50(v853);
  return v860;
}

struct StateT * slot_50(struct StateT * v869) {
  int v870 = v869->timer;
  int v882 = v870 + 1;
  v869->timer = v882;
  int * v872 = v869->regs;
  int v873 = v872[6];
  int v874 = v872[30];
  bool v886 = (v873 ^ -2147483648) < (v874 ^ -2147483648);
  int v877;
  if (v886) {
    v877 = 1;
  } else {
    v877 = 0;
  }
  int * v878 = v869->regs;
  v878[30] = v877;
  struct StateT * v880 = slot_51(v869);
  return v880;
}

struct StateT * slot_37(struct StateT * v656) {
  int v657 = v656->timer;
  int v665 = v657 + 1;
  v656->timer = v665;
  int * v659 = v656->regs;
  int v660 = v659[17];
  int v661 = v659[31];
  int v669 = v660 | v661;
  v659[17] = v669;
  struct StateT * v663 = slot_38(v656);
  return v663;
}

struct StateT * slot_114(struct StateT * v2049) {
  int v2050 = v2049->timer;
  int v2058 = v2050 + 1;
  v2049->timer = v2058;
  int * v2052 = v2049->regs;
  int v2053 = v2052[6];
  int v2054 = v2052[5];
  int v2062 = v2053 + v2054;
  v2052[5] = v2062;
  struct StateT * v2056 = slot_115(v2049);
  return v2056;
}

struct StateT * slot_135(struct StateT * v2425) {
  int v2426 = v2425->timer;
  int v2434 = v2426 + 1;
  v2425->timer = v2434;
  int * v2428 = v2425->regs;
  int v2429 = v2428[29];
  int v2430 = v2428[5];
  int v2439 = v2429 + v2430;
  v2428[30] = v2439;
  struct StateT * v2432 = slot_136(v2425);
  return v2432;
}

struct StateT * slot_59(struct StateT * v1042) {
  int v1043 = v1042->timer;
  int v1055 = v1043 + 1;
  v1042->timer = v1055;
  int * v1045 = v1042->regs;
  int v1046 = v1045[6];
  int v1047 = v1045[30];
  bool v1059 = (v1046 ^ -2147483648) < (v1047 ^ -2147483648);
  int v1050;
  if (v1059) {
    v1050 = 1;
  } else {
    v1050 = 0;
  }
  int * v1051 = v1042->regs;
  v1051[6] = v1050;
  struct StateT * v1053 = slot_60(v1042);
  return v1053;
}

struct StateT * slot_192(struct StateT * v3459) {
  int v3460 = v3459->timer;
  int v3468 = v3460 + 1;
  v3459->timer = v3468;
  int * v3462 = v3459->regs;
  int v3463 = v3462[17];
  int v3464 = v3462[13];
  int v3472 = v3463 | v3464;
  v3462[13] = v3472;
  struct StateT * v3466 = slot_193(v3459);
  return v3466;
}

struct StateT * slot_40(struct StateT * v706) {
  int v707 = v706->timer;
  int v715 = v707 + 1;
  v706->timer = v715;
  int * v709 = v706->regs;
  int v710 = v709[28];
  int v711 = v709[12];
  int v720 = (((((int)((unsigned int)v710 >> 16)) * ((int)((unsigned int)v711 >> 16))) + ((int)((unsigned int)((v710 & 65535) * ((int)((unsigned int)v711 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v710 >> 16)) * (v711 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v710 & 65535) * (v711 & 65535)) >> 16)) + (((v710 & 65535) * ((int)((unsigned int)v711 >> 16))) & 65535)) + ((((int)((unsigned int)v710 >> 16)) * (v711 & 65535)) & 65535)) >> 16));
  v709[31] = v720;
  struct StateT * v713 = slot_41(v706);
  return v713;
}

struct StateT * slot_48(struct StateT * v837) {
  int v838 = v837->timer;
  int v846 = v838 + 1;
  v837->timer = v846;
  int * v840 = v837->regs;
  int v841 = v840[30];
  int v842 = v840[6];
  int v850 = v841 + v842;
  v840[6] = v850;
  struct StateT * v844 = slot_49(v837);
  return v844;
}

struct StateT * slot_77(struct StateT * v1378) {
  int v1379 = v1378->timer;
  int v1387 = v1379 + 1;
  v1378->timer = v1387;
  int * v1381 = v1378->regs;
  int v1382 = v1381[7];
  int v1383 = v1381[28];
  int v1391 = v1382 | v1383;
  v1381[7] = v1391;
  struct StateT * v1385 = slot_78(v1378);
  return v1385;
}

struct StateT * slot_85(struct StateT * v1509) {
  int v1510 = v1509->timer;
  int v1518 = v1510 + 1;
  v1509->timer = v1518;
  int * v1512 = v1509->regs;
  int v1513 = v1512[29];
  int v1514 = v1512[13];
  int v1523 = v1513 * v1514;
  v1512[9] = v1523;
  struct StateT * v1516 = slot_86(v1509);
  return v1516;
}

struct StateT * slot_75(struct StateT * v1340) {
  int v1341 = v1340->timer;
  int v1350 = v1341 + 1;
  v1340->timer = v1350;
  int * v1343 = v1340->regs;
  int v1344 = v1343[11];
  int * v1345 = v1340->mem;
  int v1354 = (int)((unsigned int)(v1344 + 16) >> 2);
  int v1346 = v1345[v1354];
  v1343[6] = v1346;
  struct StateT * v1348 = slot_76(v1340);
  return v1348;
}

struct StateT * slot_72(struct StateT * v1295) {
  int v1296 = v1295->timer;
  int v1303 = v1296 + 1;
  v1295->timer = v1303;
  int * v1298 = v1295->regs;
  int v1299 = v1298[28];
  int v1307 = (int)((unsigned int)v1299 >> 19);
  v1298[17] = v1307;
  struct StateT * v1301 = slot_73(v1295);
  return v1301;
}

struct StateT * slot_119(struct StateT * v2133) {
  int v2134 = v2133->timer;
  int v2142 = v2134 + 1;
  v2133->timer = v2142;
  int * v2136 = v2133->regs;
  int v2137 = v2136[5];
  int v2138 = v2136[17];
  int v2146 = v2137 | v2138;
  v2136[5] = v2146;
  struct StateT * v2140 = slot_120(v2133);
  return v2140;
}

struct StateT * slot_71(struct StateT * v1276) {
  int v1277 = v1276->timer;
  int v1286 = v1277 + 1;
  v1276->timer = v1286;
  int * v1279 = v1276->regs;
  int v1280 = v1279[10];
  int v1281 = v1279[29];
  int * v1282 = v1276->mem;
  int v1291 = (int)((unsigned int)(v1280 + 12) >> 2);
  v1282[v1291] = v1281;
  struct StateT * v1284 = slot_72(v1276);
  return v1284;
}

struct StateT * slot_101(struct StateT * v1815) {
  int v1816 = v1815->timer;
  int v1824 = v1816 + 1;
  v1815->timer = v1824;
  int * v1818 = v1815->regs;
  int v1819 = v1818[18];
  int v1820 = v1818[6];
  int v1828 = v1819 + v1820;
  v1818[6] = v1828;
  struct StateT * v1822 = slot_102(v1815);
  return v1822;
}

struct StateT * slot_108(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1952 = v1945 + 1;
  v1944->timer = v1952;
  int * v1947 = v1944->regs;
  int v1948 = v1947[7];
  int v1955 = (int)((unsigned int)v1948 >> 19);
  v1947[7] = v1955;
  struct StateT * v1950 = slot_109(v1944);
  return v1950;
}

struct StateT * slot_116(struct StateT * v2084) {
  int v2085 = v2084->timer;
  int v2094 = v2085 + 1;
  v2084->timer = v2094;
  int * v2087 = v2084->regs;
  int v2088 = v2087[11];
  int * v2089 = v2084->mem;
  int v2098 = (int)((unsigned int)(v2088 + 28) >> 2);
  int v2090 = v2089[v2098];
  v2087[29] = v2090;
  struct StateT * v2092 = slot_117(v2084);
  return v2092;
}

struct StateT * slot_93(struct StateT * v1659) {
  int v1660 = v1659->timer;
  int v1668 = v1660 + 1;
  v1659->timer = v1668;
  int * v1662 = v1659->regs;
  int v1663 = v1662[30];
  int v1664 = v1662[7];
  int v1672 = v1663 + v1664;
  v1662[7] = v1672;
  struct StateT * v1666 = slot_94(v1659);
  return v1666;
}

struct StateT * slot_88(struct StateT * v1559) {
  int v1560 = v1559->timer;
  int v1568 = v1560 + 1;
  v1559->timer = v1568;
  int * v1562 = v1559->regs;
  int v1563 = v1562[28];
  int v1564 = v1562[17];
  int v1573 = v1563 + v1564;
  v1562[29] = v1573;
  struct StateT * v1566 = slot_89(v1559);
  return v1566;
}

struct StateT * slot_96(struct StateT * v1717) {
  int v1718 = v1717->timer;
  int v1726 = v1718 + 1;
  v1717->timer = v1726;
  int * v1720 = v1717->regs;
  int v1721 = v1720[8];
  int v1722 = v1720[6];
  int v1730 = v1721 + v1722;
  v1720[6] = v1730;
  struct StateT * v1724 = slot_97(v1717);
  return v1724;
}

struct StateT * slot_45(struct StateT * v787) {
  int v788 = v787->timer;
  int v796 = v788 + 1;
  v787->timer = v796;
  int * v790 = v787->regs;
  int v791 = v790[28];
  int v792 = v790[13];
  int v801 = v791 * v792;
  v790[18] = v801;
  struct StateT * v794 = slot_46(v787);
  return v794;
}

struct StateT * slot_134(struct StateT * v2400) {
  int v2401 = v2400->timer;
  int v2413 = v2401 + 1;
  v2400->timer = v2413;
  int * v2403 = v2400->regs;
  int v2404 = v2403[29];
  int v2405 = v2403[31];
  bool v2417 = (v2404 ^ -2147483648) < (v2405 ^ -2147483648);
  int v2408;
  if (v2417) {
    v2408 = 1;
  } else {
    v2408 = 0;
  }
  int * v2409 = v2400->regs;
  v2409[6] = v2408;
  struct StateT * v2411 = slot_135(v2400);
  return v2411;
}

struct StateT * slot_175(struct StateT * v3148) {
  int v3149 = v3148->timer;
  int v3157 = v3149 + 1;
  v3148->timer = v3157;
  int * v3151 = v3148->regs;
  int v3152 = v3151[6];
  int v3153 = v3151[17];
  int v3161 = v3152 + v3153;
  v3151[17] = v3161;
  struct StateT * v3155 = slot_176(v3148);
  return v3155;
}

struct StateT * slot_69(struct StateT * v1233) {
  int v1234 = v1233->timer;
  int v1246 = v1234 + 1;
  v1233->timer = v1246;
  int * v1236 = v1233->regs;
  int v1237 = v1236[28];
  int v1238 = v1236[5];
  bool v1250 = (v1237 ^ -2147483648) < (v1238 ^ -2147483648);
  int v1241;
  if (v1250) {
    v1241 = 1;
  } else {
    v1241 = 0;
  }
  int * v1242 = v1233->regs;
  v1242[5] = v1241;
  struct StateT * v1244 = slot_70(v1233);
  return v1244;
}

struct StateT * slot_202(struct StateT * v3613) {
  int v3614 = v3613->timer;
  int v3626 = v3614 + 1;
  v3613->timer = v3626;
  int * v3616 = v3613->regs;
  int v3617 = v3616[13];
  int v3618 = v3616[14];
  bool v3630 = (v3617 ^ -2147483648) < (v3618 ^ -2147483648);
  int v3621;
  if (v3630) {
    v3621 = 1;
  } else {
    v3621 = 0;
  }
  int * v3622 = v3613->regs;
  v3622[14] = v3621;
  struct StateT * v3624 = slot_203(v3613);
  return v3624;
}

struct StateT * slot_188(struct StateT * v3390) {
  int v3391 = v3390->timer;
  int v3398 = v3391 + 1;
  v3390->timer = v3398;
  int * v3393 = v3390->regs;
  int v3394 = v3393[17];
  int v3401 = (int)((unsigned int)v3394 >> 19);
  v3393[17] = v3401;
  struct StateT * v3396 = slot_189(v3390);
  return v3396;
}

struct StateT * slot_138(struct StateT * v2474) {
  int v2475 = v2474->timer;
  int v2483 = v2475 + 1;
  v2474->timer = v2483;
  int * v2477 = v2474->regs;
  int v2478 = v2477[9];
  int v2479 = v2477[6];
  int v2488 = v2478 + v2479;
  v2477[5] = v2488;
  struct StateT * v2481 = slot_139(v2474);
  return v2481;
}

struct StateT * slot_186(struct StateT * v3333) {
  int v3334 = v3333->timer;
  int v3342 = v3334 + 1;
  v3333->timer = v3342;
  int * v3336 = v3333->regs;
  int v3337 = v3336[12];
  int v3338 = v3336[5];
  int v3346 = v3337 + v3338;
  v3336[5] = v3346;
  struct StateT * v3340 = slot_187(v3333);
  return v3340;
}

struct StateT * slot_102(struct StateT * v1831) {
  int v1832 = v1831->timer;
  int v1840 = v1832 + 1;
  v1831->timer = v1840;
  int * v1834 = v1831->regs;
  int v1835 = v1834[30];
  int v1836 = v1834[28];
  int v1845 = v1835 + v1836;
  v1834[7] = v1845;
  struct StateT * v1838 = slot_103(v1831);
  return v1838;
}

struct StateT * slot_145(struct StateT * v2627) {
  int v2628 = v2627->timer;
  int v2640 = v2628 + 1;
  v2627->timer = v2640;
  int * v2630 = v2627->regs;
  int v2631 = v2630[7];
  int v2632 = v2630[29];
  bool v2644 = (v2631 ^ -2147483648) < (v2632 ^ -2147483648);
  int v2635;
  if (v2644) {
    v2635 = 1;
  } else {
    v2635 = 0;
  }
  int * v2636 = v2627->regs;
  v2636[28] = v2635;
  struct StateT * v2638 = slot_146(v2627);
  return v2638;
}

struct StateT * slot_110(struct StateT * v1982) {
  int v1983 = v1982->timer;
  int v1992 = v1983 + 1;
  v1982->timer = v1992;
  int * v1985 = v1982->regs;
  int v1986 = v1985[10];
  int v1987 = v1985[17];
  int * v1988 = v1982->mem;
  int v1997 = (int)((unsigned int)(v1986 + 16) >> 2);
  v1988[v1997] = v1987;
  struct StateT * v1990 = slot_111(v1982);
  return v1990;
}

struct StateT * slot_196(struct StateT * v3516) {
  int v3517 = v3516->timer;
  int v3525 = v3517 + 1;
  v3516->timer = v3525;
  int * v3519 = v3516->regs;
  int v3520 = v3519[12];
  int v3521 = v3519[5];
  int v3529 = v3520 | v3521;
  v3519[12] = v3529;
  struct StateT * v3523 = slot_197(v3516);
  return v3523;
}

struct StateT * slot_208(struct StateT * v3726) {
  int v3727 = v3726->timer;
  int v3736 = v3727 + 1;
  v3726->timer = v3736;
  int * v3729 = v3726->regs;
  int v3730 = v3729[10];
  int v3731 = v3729[16];
  int * v3732 = v3726->mem;
  int v3741 = (int)((unsigned int)(v3730 + 36) >> 2);
  v3732[v3741] = v3731;
  struct StateT * v3734 = slot_209(v3726);
  return v3734;
}

struct StateT * slot_172(struct StateT * v3082) {
  int v3083 = v3082->timer;
  int v3095 = v3083 + 1;
  v3082->timer = v3095;
  int * v3085 = v3082->regs;
  int v3086 = v3085[11];
  int v3087 = v3085[12];
  bool v3099 = (v3086 ^ -2147483648) < (v3087 ^ -2147483648);
  int v3090;
  if (v3099) {
    v3090 = 1;
  } else {
    v3090 = 0;
  }
  int * v3091 = v3082->regs;
  v3091[5] = v3090;
  struct StateT * v3093 = slot_173(v3082);
  return v3093;
}

struct StateT * slot_131(struct StateT * v2343) {
  int v2344 = v2343->timer;
  int v2352 = v2344 + 1;
  v2343->timer = v2352;
  int * v2346 = v2343->regs;
  int v2347 = v2346[31];
  int v2348 = v2346[29];
  int v2356 = v2347 + v2348;
  v2346[29] = v2356;
  struct StateT * v2350 = slot_132(v2343);
  return v2350;
}

struct StateT * slot_8(struct StateT * v143) {
  int v144 = v143->timer;
  int v151 = v144 + 1;
  v143->timer = v151;
  int * v146 = v143->regs;
  int v147 = v146[16];
  int v154 = v147 + -1;
  v146[16] = v154;
  struct StateT * v149 = slot_9(v143);
  return v149;
}

struct StateT * slot_180(struct StateT * v3238) {
  int v3239 = v3238->timer;
  int v3251 = v3239 + 1;
  v3238->timer = v3251;
  int * v3241 = v3238->regs;
  int v3242 = v3241[12];
  int v3243 = v3241[8];
  bool v3255 = (v3242 ^ -2147483648) < (v3243 ^ -2147483648);
  int v3246;
  if (v3255) {
    v3246 = 1;
  } else {
    v3246 = 0;
  }
  int * v3247 = v3238->regs;
  v3247[28] = v3246;
  struct StateT * v3249 = slot_181(v3238);
  return v3249;
}

struct StateT * slot_203(struct StateT * v3637) {
  int v3638 = v3637->timer;
  int v3646 = v3638 + 1;
  v3637->timer = v3646;
  int * v3640 = v3637->regs;
  int v3641 = v3640[15];
  int v3642 = v3640[12];
  int v3650 = v3641 + v3642;
  v3640[12] = v3650;
  struct StateT * v3644 = slot_204(v3637);
  return v3644;
}

struct StateT * slot_190(struct StateT * v3428) {
  int v3429 = v3428->timer;
  int v3437 = v3429 + 1;
  v3428->timer = v3437;
  int * v3431 = v3428->regs;
  int v3432 = v3431[13];
  int v3433 = v3431[12];
  int v3441 = v3432 + v3433;
  v3431[12] = v3441;
  struct StateT * v3435 = slot_191(v3428);
  return v3435;
}

struct StateT * slot_157(struct StateT * v2827) {
  int v2828 = v2827->timer;
  int v2836 = v2828 + 1;
  v2827->timer = v2836;
  int * v2830 = v2827->regs;
  int v2831 = v2830[7];
  int v2832 = v2830[28];
  int v2840 = v2831 | v2832;
  v2830[7] = v2840;
  struct StateT * v2834 = slot_158(v2827);
  return v2834;
}

struct StateT * slot_200(struct StateT * v3581) {
  int v3582 = v3581->timer;
  int v3590 = v3582 + 1;
  v3581->timer = v3590;
  int * v3584 = v3581->regs;
  int v3585 = v3584[14];
  int v3586 = v3584[13];
  int v3594 = v3585 + v3586;
  v3584[13] = v3594;
  struct StateT * v3588 = slot_201(v3581);
  return v3588;
}

struct StateT * slot_173(struct StateT * v3107) {
  int v3108 = v3107->timer;
  int v3116 = v3108 + 1;
  v3107->timer = v3116;
  int * v3110 = v3107->regs;
  int v3111 = v3110[29];
  int v3112 = v3110[7];
  int v3120 = v3111 + v3112;
  v3110[7] = v3120;
  struct StateT * v3114 = slot_174(v3107);
  return v3114;
}

struct StateT * slot_149(struct StateT * v2683) {
  int v2684 = v2683->timer;
  int v2696 = v2684 + 1;
  v2683->timer = v2696;
  int * v2686 = v2683->regs;
  int v2687 = v2686[28];
  int v2688 = v2686[5];
  bool v2700 = (v2687 ^ -2147483648) < (v2688 ^ -2147483648);
  int v2691;
  if (v2700) {
    v2691 = 1;
  } else {
    v2691 = 0;
  }
  int * v2692 = v2683->regs;
  v2692[5] = v2691;
  struct StateT * v2694 = slot_150(v2683);
  return v2694;
}

struct StateT * slot_5(struct StateT * v92) {
  int v93 = v92->timer;
  int v102 = v93 + 1;
  v92->timer = v102;
  int * v95 = v92->regs;
  int v96 = v95[11];
  int * v97 = v92->mem;
  int v106 = (int)((unsigned int)v96 >> 2);
  int v98 = v97[v106];
  v95[14] = v98;
  struct StateT * v100 = slot_6(v92);
  return v100;
}

struct StateT * slot_104(struct StateT * v1864) {
  int v1865 = v1864->timer;
  int v1876 = v1865 + 1;
  v1864->timer = v1876;
  int * v1867 = v1864->regs;
  int v1868 = v1867[7];
  int v1869 = v1867[29];
  bool v1880 = v1868 == v1869;
  struct StateT * v1874;
  if (v1880) {
    struct StateT * v1870 = slot_106(v1864);
    v1874 = v1870;
  } else {
    struct StateT * v1872 = slot_105(v1864);
    v1874 = v1872;
  }
  return v1874;
}

struct StateT * slot_54(struct StateT * v951) {
  int v952 = v951->timer;
  int v964 = v952 + 1;
  v951->timer = v964;
  int * v954 = v951->regs;
  int v955 = v954[29];
  int v956 = v954[8];
  bool v968 = (v955 ^ -2147483648) < (v956 ^ -2147483648);
  int v959;
  if (v968) {
    v959 = 1;
  } else {
    v959 = 0;
  }
  int * v960 = v951->regs;
  v960[6] = v959;
  struct StateT * v962 = slot_55(v951);
  return v962;
}

struct StateT * slot_26(struct StateT * v456) {
  int v457 = v456->timer;
  int v466 = v457 + 1;
  v456->timer = v466;
  int * v459 = v456->regs;
  int v460 = v459[10];
  int v461 = v459[15];
  int * v462 = v456->mem;
  int v471 = (int)((unsigned int)(v460 + 4) >> 2);
  v462[v471] = v461;
  struct StateT * v464 = slot_27(v456);
  return v464;
}

struct StateT * slot_206(struct StateT * v3688) {
  int v3689 = v3688->timer;
  int v3698 = v3689 + 1;
  v3688->timer = v3698;
  int * v3691 = v3688->regs;
  int v3692 = v3691[10];
  int v3693 = v3691[12];
  int * v3694 = v3688->mem;
  int v3703 = (int)((unsigned int)(v3692 + 4) >> 2);
  v3694[v3703] = v3693;
  struct StateT * v3696 = slot_207(v3688);
  return v3696;
}

struct StateT * slot_169(struct StateT * v3023) {
  int v3024 = v3023->timer;
  int v3032 = v3024 + 1;
  v3023->timer = v3032;
  int * v3026 = v3023->regs;
  int v3027 = v3026[12];
  int v3028 = v3026[7];
  int v3037 = v3027 + v3028;
  v3026[11] = v3037;
  struct StateT * v3030 = slot_170(v3023);
  return v3030;
}

struct StateT * slot_64(struct StateT * v1139) {
  int v1140 = v1139->timer;
  int v1151 = v1140 + 1;
  v1139->timer = v1151;
  int * v1142 = v1139->regs;
  int v1143 = v1142[7];
  int v1144 = v1142[29];
  bool v1155 = v1143 == v1144;
  struct StateT * v1149;
  if (v1155) {
    struct StateT * v1145 = slot_66(v1139);
    v1149 = v1145;
  } else {
    struct StateT * v1147 = slot_65(v1139);
    v1149 = v1147;
  }
  return v1149;
}

struct StateT * slot_170(struct StateT * v3040) {
  int v3041 = v3040->timer;
  int v3053 = v3041 + 1;
  v3040->timer = v3053;
  int * v3043 = v3040->regs;
  int v3044 = v3043[5];
  int v3045 = v3043[28];
  bool v3057 = (v3044 ^ -2147483648) < (v3045 ^ -2147483648);
  int v3048;
  if (v3057) {
    v3048 = 1;
  } else {
    v3048 = 0;
  }
  int * v3049 = v3040->regs;
  v3049[7] = v3048;
  struct StateT * v3051 = slot_171(v3040);
  return v3051;
}

struct StateT * slot_14(struct StateT * v242) {
  int v243 = v242->timer;
  int v251 = v243 + 1;
  v242->timer = v251;
  int * v245 = v242->regs;
  int v246 = v245[15];
  int v247 = v245[13];
  int v256 = v246 * v247;
  v245[29] = v256;
  struct StateT * v249 = slot_15(v242);
  return v249;
}

struct StateT * slot_53(struct StateT * v935) {
  int v936 = v935->timer;
  int v944 = v936 + 1;
  v935->timer = v944;
  int * v938 = v935->regs;
  int v939 = v938[31];
  int v940 = v938[30];
  int v948 = v939 + v940;
  v938[30] = v948;
  struct StateT * v942 = slot_54(v935);
  return v942;
}

struct StateT * slot_80(struct StateT * v1424) {
  int v1425 = v1424->timer;
  int v1433 = v1425 + 1;
  v1424->timer = v1433;
  int * v1427 = v1424->regs;
  int v1428 = v1427[6];
  int v1429 = v1427[12];
  int v1438 = (((((int)((unsigned int)v1428 >> 16)) * ((int)((unsigned int)v1429 >> 16))) + ((int)((unsigned int)((v1428 & 65535) * ((int)((unsigned int)v1429 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1428 >> 16)) * (v1429 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1428 & 65535) * (v1429 & 65535)) >> 16)) + (((v1428 & 65535) * ((int)((unsigned int)v1429 >> 16))) & 65535)) + ((((int)((unsigned int)v1428 >> 16)) * (v1429 & 65535)) & 65535)) >> 16));
  v1427[17] = v1438;
  struct StateT * v1431 = slot_81(v1424);
  return v1431;
}

struct StateT * slot_44(struct StateT * v771) {
  int v772 = v771->timer;
  int v780 = v772 + 1;
  v771->timer = v780;
  int * v774 = v771->regs;
  int v775 = v774[5];
  int v776 = v774[29];
  int v784 = v775 | v776;
  v774[5] = v784;
  struct StateT * v778 = slot_45(v771);
  return v778;
}

struct StateT * slot_137(struct StateT * v2458) {
  int v2459 = v2458->timer;
  int v2467 = v2459 + 1;
  v2458->timer = v2467;
  int * v2461 = v2458->regs;
  int v2462 = v2461[7];
  int v2463 = v2461[6];
  int v2471 = v2462 + v2463;
  v2461[6] = v2471;
  struct StateT * v2465 = slot_138(v2458);
  return v2465;
}

struct StateT * slot_122(struct StateT * v2183) {
  int v2184 = v2183->timer;
  int v2192 = v2184 + 1;
  v2183->timer = v2192;
  int * v2186 = v2183->regs;
  int v2187 = v2186[29];
  int v2188 = v2186[12];
  int v2197 = (((((int)((unsigned int)v2187 >> 16)) * ((int)((unsigned int)v2188 >> 16))) + ((int)((unsigned int)((v2187 & 65535) * ((int)((unsigned int)v2188 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2187 >> 16)) * (v2188 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2187 & 65535) * (v2188 & 65535)) >> 16)) + (((v2187 & 65535) * ((int)((unsigned int)v2188 >> 16))) & 65535)) + ((((int)((unsigned int)v2187 >> 16)) * (v2188 & 65535)) & 65535)) >> 16));
  v2186[30] = v2197;
  struct StateT * v2190 = slot_123(v2183);
  return v2190;
}

struct StateT * slot_99(struct StateT * v1766) {
  int v1767 = v1766->timer;
  int v1779 = v1767 + 1;
  v1766->timer = v1779;
  int * v1769 = v1766->regs;
  int v1770 = v1769[6];
  int v1771 = v1769[7];
  bool v1783 = (v1770 ^ -2147483648) < (v1771 ^ -2147483648);
  int v1774;
  if (v1783) {
    v1774 = 1;
  } else {
    v1774 = 0;
  }
  int * v1775 = v1766->regs;
  v1775[6] = v1774;
  struct StateT * v1777 = slot_100(v1766);
  return v1777;
}

struct StateT * slot_179(struct StateT * v3214) {
  int v3215 = v3214->timer;
  int v3227 = v3215 + 1;
  v3214->timer = v3227;
  int * v3217 = v3214->regs;
  int v3218 = v3217[28];
  int v3219 = v3217[7];
  bool v3231 = (v3218 ^ -2147483648) < (v3219 ^ -2147483648);
  int v3222;
  if (v3231) {
    v3222 = 1;
  } else {
    v3222 = 0;
  }
  int * v3223 = v3214->regs;
  v3223[7] = v3222;
  struct StateT * v3225 = slot_180(v3214);
  return v3225;
}

struct StateT * slot_36(struct StateT * v640) {
  int v641 = v640->timer;
  int v649 = v641 + 1;
  v640->timer = v649;
  int * v643 = v640->regs;
  int v644 = v643[5];
  int v645 = v643[6];
  int v653 = v644 + v645;
  v643[5] = v653;
  struct StateT * v647 = slot_37(v640);
  return v647;
}

struct StateT * slot_57(struct StateT * v1009) {
  int v1010 = v1009->timer;
  int v1018 = v1010 + 1;
  v1009->timer = v1018;
  int * v1012 = v1009->regs;
  int v1013 = v1012[30];
  int v1014 = v1012[6];
  int v1022 = v1013 + v1014;
  v1012[6] = v1022;
  struct StateT * v1016 = slot_58(v1009);
  return v1016;
}

struct StateT * slot_62(struct StateT * v1107) {
  int v1108 = v1107->timer;
  int v1116 = v1108 + 1;
  v1107->timer = v1116;
  int * v1110 = v1107->regs;
  int v1111 = v1110[7];
  int v1112 = v1110[28];
  int v1120 = v1111 + v1112;
  v1110[7] = v1120;
  struct StateT * v1114 = slot_63(v1107);
  return v1114;
}

struct StateT * slot_22(struct StateT * v390) {
  int v391 = v390->timer;
  int v399 = v391 + 1;
  v390->timer = v399;
  int * v393 = v390->regs;
  int v394 = v393[17];
  int v395 = v393[16];
  int v404 = v394 & v395;
  v393[15] = v404;
  struct StateT * v397 = slot_23(v390);
  return v397;
}

struct StateT * slot_139(struct StateT * v2491) {
  int v2492 = v2491->timer;
  int v2504 = v2492 + 1;
  v2491->timer = v2504;
  int * v2494 = v2491->regs;
  int v2495 = v2494[6];
  int v2496 = v2494[7];
  bool v2508 = (v2495 ^ -2147483648) < (v2496 ^ -2147483648);
  int v2499;
  if (v2508) {
    v2499 = 1;
  } else {
    v2499 = 0;
  }
  int * v2500 = v2491->regs;
  v2500[6] = v2499;
  struct StateT * v2502 = slot_140(v2491);
  return v2502;
}

struct StateT * slot_23(struct StateT * v407) {
  int v408 = v407->timer;
  int v415 = v408 + 1;
  v407->timer = v415;
  int * v410 = v407->regs;
  int v411 = v410[17];
  int v418 = (int)((unsigned int)v411 >> 19);
  v410[17] = v418;
  struct StateT * v413 = slot_24(v407);
  return v413;
}

struct StateT * slot_153(struct StateT * v2760) {
  int v2761 = v2760->timer;
  int v2768 = v2761 + 1;
  v2760->timer = v2768;
  int * v2763 = v2760->regs;
  int v2764 = v2763[28];
  int v2771 = v2764 << 13;
  v2763[28] = v2771;
  struct StateT * v2766 = slot_154(v2760);
  return v2766;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v45 = v36 + 1;
  v35->timer = v45;
  int * v38 = v35->regs;
  int v39 = v38[2];
  int v40 = v38[9];
  int * v41 = v35->mem;
  int v50 = (int)((unsigned int)(v39 + 8) >> 2);
  v41[v50] = v40;
  struct StateT * v43 = slot_3(v35);
  return v43;
}

struct StateT * slot_86(struct StateT * v1526) {
  int v1527 = v1526->timer;
  int v1535 = v1527 + 1;
  v1526->timer = v1535;
  int * v1529 = v1526->regs;
  int v1530 = v1529[29];
  int v1531 = v1529[13];
  int v1540 = (((((int)((unsigned int)v1530 >> 16)) * ((int)((unsigned int)v1531 >> 16))) + ((int)((unsigned int)((v1530 & 65535) * ((int)((unsigned int)v1531 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1530 >> 16)) * (v1531 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1530 & 65535) * (v1531 & 65535)) >> 16)) + (((v1530 & 65535) * ((int)((unsigned int)v1531 >> 16))) & 65535)) + ((((int)((unsigned int)v1530 >> 16)) * (v1531 & 65535)) & 65535)) >> 16));
  v1529[18] = v1540;
  struct StateT * v1533 = slot_87(v1526);
  return v1533;
}

struct StateT * slot_129(struct StateT * v2301) {
  int v2302 = v2301->timer;
  int v2310 = v2302 + 1;
  v2301->timer = v2310;
  int * v2304 = v2301->regs;
  int v2305 = v2304[6];
  int v2306 = v2304[7];
  int v2315 = v2305 + v2306;
  v2304[17] = v2315;
  struct StateT * v2308 = slot_130(v2301);
  return v2308;
}

struct StateT * slot_158(struct StateT * v2843) {
  int v2844 = v2843->timer;
  int v2851 = v2844 + 1;
  v2843->timer = v2851;
  int * v2846 = v2843->regs;
  int v2847 = v2846[5];
  int v2854 = v2847 << 13;
  v2846[5] = v2854;
  struct StateT * v2849 = slot_159(v2843);
  return v2849;
}

struct StateT * slot_100(struct StateT * v1790) {
  int v1791 = v1790->timer;
  int v1803 = v1791 + 1;
  v1790->timer = v1803;
  int * v1793 = v1790->regs;
  int v1794 = v1793[5];
  int v1795 = v1793[9];
  bool v1807 = (v1794 ^ -2147483648) < (v1795 ^ -2147483648);
  int v1798;
  if (v1807) {
    v1798 = 1;
  } else {
    v1798 = 0;
  }
  int * v1799 = v1790->regs;
  v1799[31] = v1798;
  struct StateT * v1801 = slot_101(v1790);
  return v1801;
}

struct StateT * slot_127(struct StateT * v2268) {
  int v2269 = v2268->timer;
  int v2277 = v2269 + 1;
  v2268->timer = v2277;
  int * v2271 = v2268->regs;
  int v2272 = v2271[6];
  int v2273 = v2271[12];
  int v2281 = v2272 * v2273;
  v2271[6] = v2281;
  struct StateT * v2275 = slot_128(v2268);
  return v2275;
}

struct StateT * slot_13(struct StateT * v225) {
  int v226 = v225->timer;
  int v234 = v226 + 1;
  v225->timer = v234;
  int * v228 = v225->regs;
  int v229 = v228[14];
  int v230 = v228[13];
  int v239 = (((((int)((unsigned int)v229 >> 16)) * ((int)((unsigned int)v230 >> 16))) + ((int)((unsigned int)((v229 & 65535) * ((int)((unsigned int)v230 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v229 >> 16)) * (v230 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v229 & 65535) * (v230 & 65535)) >> 16)) + (((v229 & 65535) * ((int)((unsigned int)v230 >> 16))) & 65535)) + ((((int)((unsigned int)v229 >> 16)) * (v230 & 65535)) & 65535)) >> 16));
  v228[28] = v239;
  struct StateT * v232 = slot_14(v225);
  return v232;
}

struct StateT * slot_111(struct StateT * v2001) {
  int v2002 = v2001->timer;
  int v2011 = v2002 + 1;
  v2001->timer = v2011;
  int * v2004 = v2001->regs;
  int v2005 = v2004[10];
  int v2006 = v2004[29];
  int * v2007 = v2001->mem;
  int v2016 = (int)((unsigned int)(v2005 + 20) >> 2);
  v2007[v2016] = v2006;
  struct StateT * v2009 = slot_112(v2001);
  return v2009;
}

struct StateT * slot_109(struct StateT * v1958) {
  int v1959 = v1958->timer;
  int v1971 = v1959 + 1;
  v1958->timer = v1971;
  int * v1961 = v1958->regs;
  int v1962 = v1961[28];
  int v1963 = v1961[5];
  bool v1975 = (v1962 ^ -2147483648) < (v1963 ^ -2147483648);
  int v1966;
  if (v1975) {
    v1966 = 1;
  } else {
    v1966 = 0;
  }
  int * v1967 = v1958->regs;
  v1967[5] = v1966;
  struct StateT * v1969 = slot_110(v1958);
  return v1969;
}

struct StateT * slot_174(struct StateT * v3123) {
  int v3124 = v3123->timer;
  int v3136 = v3124 + 1;
  v3123->timer = v3136;
  int * v3126 = v3123->regs;
  int v3127 = v3126[6];
  int v3128 = v3126[30];
  bool v3140 = (v3127 ^ -2147483648) < (v3128 ^ -2147483648);
  int v3131;
  if (v3140) {
    v3131 = 1;
  } else {
    v3131 = 0;
  }
  int * v3132 = v3123->regs;
  v3132[12] = v3131;
  struct StateT * v3134 = slot_175(v3123);
  return v3134;
}

struct StateT * slot_147(struct StateT * v2652) {
  int v2653 = v2652->timer;
  int v2661 = v2653 + 1;
  v2652->timer = v2661;
  int * v2655 = v2652->regs;
  int v2656 = v2655[7];
  int v2657 = v2655[16];
  int v2666 = v2656 & v2657;
  v2655[29] = v2666;
  struct StateT * v2659 = slot_148(v2652);
  return v2659;
}

struct StateT * slot_42(struct StateT * v740) {
  int v741 = v740->timer;
  int v749 = v741 + 1;
  v740->timer = v749;
  int * v743 = v740->regs;
  int v744 = v743[7];
  int v745 = v743[13];
  int v754 = (((((int)((unsigned int)v744 >> 16)) * ((int)((unsigned int)v745 >> 16))) + ((int)((unsigned int)((v744 & 65535) * ((int)((unsigned int)v745 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v744 >> 16)) * (v745 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v744 & 65535) * (v745 & 65535)) >> 16)) + (((v744 & 65535) * ((int)((unsigned int)v745 >> 16))) & 65535)) + ((((int)((unsigned int)v744 >> 16)) * (v745 & 65535)) & 65535)) >> 16));
  v743[9] = v754;
  struct StateT * v747 = slot_43(v740);
  return v747;
}

struct StateT * slot_163(struct StateT * v2924) {
  int v2925 = v2924->timer;
  int v2933 = v2925 + 1;
  v2924->timer = v2933;
  int * v2927 = v2924->regs;
  int v2928 = v2927[6];
  int v2929 = v2927[13];
  int v2938 = v2928 * v2929;
  v2927[30] = v2938;
  struct StateT * v2931 = slot_164(v2924);
  return v2931;
}

struct StateT * slot_184(struct StateT * v3311) {
  int v3312 = v3311->timer;
  int v3323 = v3312 + 1;
  v3311->timer = v3323;
  int * v3314 = v3311->regs;
  int v3315 = v3314[17];
  int v3316 = v3314[6];
  bool v3327 = v3315 == v3316;
  struct StateT * v3321;
  if (v3327) {
    struct StateT * v3317 = slot_186(v3311);
    v3321 = v3317;
  } else {
    struct StateT * v3319 = slot_185(v3311);
    v3321 = v3319;
  }
  return v3321;
}

struct StateT * slot_204(struct StateT * v3653) {
  int v3654 = v3653->timer;
  int v3662 = v3654 + 1;
  v3653->timer = v3662;
  int * v3656 = v3653->regs;
  int v3657 = v3656[12];
  int v3658 = v3656[14];
  int v3666 = v3657 + v3658;
  v3656[12] = v3666;
  struct StateT * v3660 = slot_205(v3653);
  return v3660;
}

struct StateT * slot_194(struct StateT * v3488) {
  int v3489 = v3488->timer;
  int v3496 = v3489 + 1;
  v3488->timer = v3496;
  int * v3491 = v3488->regs;
  int v3492 = v3491[5];
  int v3499 = (int)((unsigned int)v3492 >> 19);
  v3491[5] = v3499;
  struct StateT * v3494 = slot_195(v3488);
  return v3494;
}

struct StateT * slot_165(struct StateT * v2958) {
  int v2959 = v2958->timer;
  int v2967 = v2959 + 1;
  v2958->timer = v2967;
  int * v2961 = v2958->regs;
  int v2962 = v2961[11];
  int v2963 = v2961[13];
  int v2972 = v2962 * v2963;
  v2961[8] = v2972;
  struct StateT * v2965 = slot_166(v2958);
  return v2965;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v2103) {
  int v2104 = v2103->timer;
  int v2112 = v2104 + 1;
  v2103->timer = v2112;
  int * v2106 = v2103->regs;
  int v2107 = v2106[7];
  int v2108 = v2106[28];
  int v2116 = v2107 | v2108;
  v2106[7] = v2116;
  struct StateT * v2110 = slot_118(v2103);
  return v2110;
}

struct StateT * slot_90(struct StateT * v1593) {
  int v1594 = v1593->timer;
  int v1606 = v1594 + 1;
  v1593->timer = v1606;
  int * v1596 = v1593->regs;
  int v1597 = v1596[29];
  int v1598 = v1596[28];
  bool v1610 = (v1597 ^ -2147483648) < (v1598 ^ -2147483648);
  int v1601;
  if (v1610) {
    v1601 = 1;
  } else {
    v1601 = 0;
  }
  int * v1602 = v1593->regs;
  v1602[7] = v1601;
  struct StateT * v1604 = slot_91(v1593);
  return v1604;
}

struct StateT * slot_11(struct StateT * v191) {
  int v192 = v191->timer;
  int v200 = v192 + 1;
  v191->timer = v200;
  int * v194 = v191->regs;
  int v195 = v194[15];
  int v196 = v194[12];
  int v205 = (((((int)((unsigned int)v195 >> 16)) * ((int)((unsigned int)v196 >> 16))) + ((int)((unsigned int)((v195 & 65535) * ((int)((unsigned int)v196 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v195 >> 16)) * (v196 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v195 & 65535) * (v196 & 65535)) >> 16)) + (((v195 & 65535) * ((int)((unsigned int)v196 >> 16))) & 65535)) + ((((int)((unsigned int)v195 >> 16)) * (v196 & 65535)) & 65535)) >> 16));
  v194[6] = v205;
  struct StateT * v198 = slot_12(v191);
  return v198;
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