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

struct StateT * slot_12(struct StateT * v182);
struct StateT * slot_143(struct StateT * v2016);
struct StateT * slot_120(struct StateT * v1694);
struct StateT * slot_167(struct StateT * v2352);
struct StateT * slot_152(struct StateT * v2142);
struct StateT * slot_199(struct StateT * v2800);
struct StateT * slot_92(struct StateT * v1302);
struct StateT * slot_31(struct StateT * v448);
struct StateT * slot_160(struct StateT * v2254);
struct StateT * slot_65(struct StateT * v924);
struct StateT * slot_10(struct StateT * v154);
struct StateT * slot_150(struct StateT * v2114);
struct StateT * slot_74(struct StateT * v1050);
struct StateT * slot_107(struct StateT * v1512);
struct StateT * slot_136(struct StateT * v1918);
struct StateT * slot_84(struct StateT * v1190);
struct StateT * slot_28(struct StateT * v406);
struct StateT * slot_155(struct StateT * v2184);
struct StateT * slot_177(struct StateT * v2492);
struct StateT * slot_17(struct StateT * v252);
struct StateT * slot_181(struct StateT * v2548);
struct StateT * slot_197(struct StateT * v2772);
struct StateT * slot_207(struct StateT * v2912);
struct StateT * slot_156(struct StateT * v2198);
struct StateT * slot_154(struct StateT * v2170);
struct StateT * slot_68(struct StateT * v966);
struct StateT * slot_105(struct StateT * v1484);
struct StateT * slot_27(struct StateT * v392);
struct StateT * slot_164(struct StateT * v2310);
struct StateT * slot_15(struct StateT * v224);
struct StateT * slot_133(struct StateT * v1876);
struct StateT * slot_56(struct StateT * v798);
struct StateT * slot_222(struct StateT * v3122);
struct StateT * slot_34(struct StateT * v490);
struct StateT * slot_171(struct StateT * v2408);
struct StateT * slot_162(struct StateT * v2282);
struct StateT * slot_21(struct StateT * v308);
struct StateT * slot_118(struct StateT * v1666);
struct StateT * slot_121(struct StateT * v1708);
struct StateT * slot_144(struct StateT * v2030);
struct StateT * slot_201(struct StateT * v2828);
struct StateT * slot_94(struct StateT * v1330);
struct StateT * slot_63(struct StateT * v896);
struct StateT * slot_146(struct StateT * v2058);
struct StateT * slot_24(struct StateT * v350);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v2744);
struct StateT * slot_125(struct StateT * v1764);
struct StateT * slot_148(struct StateT * v2086);
struct StateT * slot_126(struct StateT * v1778);
struct StateT * slot_223(struct StateT * v3136);
struct StateT * slot_79(struct StateT * v1120);
struct StateT * slot_41(struct StateT * v588);
struct StateT * slot_39(struct StateT * v560);
struct StateT * slot_142(struct StateT * v2002);
struct StateT * slot_60(struct StateT * v854);
struct StateT * slot_112(struct StateT * v1582);
struct StateT * slot_47(struct StateT * v672);
struct StateT * slot_214(struct StateT * v3010);
struct StateT * slot_29(struct StateT * v420);
struct StateT * slot_16(struct StateT * v238);
struct StateT * slot_113(struct StateT * v1596);
struct StateT * slot_151(struct StateT * v2128);
struct StateT * slot_7(struct StateT * v112);
struct StateT * slot_124(struct StateT * v1750);
struct StateT * slot_191(struct StateT * v2688);
struct StateT * slot_103(struct StateT * v1456);
struct StateT * slot_128(struct StateT * v1806);
struct StateT * slot_19(struct StateT * v280);
struct StateT * slot_87(struct StateT * v1232);
struct StateT * slot_67(struct StateT * v952);
struct StateT * slot_81(struct StateT * v1148);
struct StateT * slot_95(struct StateT * v1344);
struct StateT * slot_115(struct StateT * v1624);
struct StateT * slot_78(struct StateT * v1106);
struct StateT * slot_32(struct StateT * v462);
struct StateT * slot_205(struct StateT * v2884);
struct StateT * slot_193(struct StateT * v2716);
struct StateT * slot_176(struct StateT * v2478);
struct StateT * slot_189(struct StateT * v2660);
struct StateT * slot_33(struct StateT * v476);
struct StateT * slot_35(struct StateT * v504);
struct StateT * slot_210(struct StateT * v2954);
struct StateT * slot_166(struct StateT * v2338);
struct StateT * slot_51(struct StateT * v728);
struct StateT * slot_52(struct StateT * v742);
struct StateT * slot_83(struct StateT * v1176);
struct StateT * slot_25(struct StateT * v364);
struct StateT * slot_209(struct StateT * v2940);
struct StateT * slot_3(struct StateT * v52);
struct StateT * slot_123(struct StateT * v1736);
struct StateT * slot_73(struct StateT * v1036);
struct StateT * slot_198(struct StateT * v2786);
struct StateT * slot_1(struct StateT * v21);
struct StateT * slot_187(struct StateT * v2632);
struct StateT * slot_97(struct StateT * v1372);
struct StateT * slot_182(struct StateT * v2562);
struct StateT * slot_38(struct StateT * v546);
struct StateT * slot_178(struct StateT * v2506);
struct StateT * slot_106(struct StateT * v1498);
struct StateT * slot_98(struct StateT * v1386);
struct StateT * slot_159(struct StateT * v2240);
struct StateT * slot_46(struct StateT * v658);
struct StateT * slot_212(struct StateT * v2982);
struct StateT * slot_132(struct StateT * v1862);
struct StateT * slot_130(struct StateT * v1834);
struct StateT * slot_211(struct StateT * v2968);
struct StateT * slot_20(struct StateT * v294);
struct StateT * slot_141(struct StateT * v1988);
struct StateT * slot_61(struct StateT * v868);
struct StateT * slot_30(struct StateT * v434);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_18(struct StateT * v266);
struct StateT * slot_9(struct StateT * v140);
struct StateT * slot_183(struct StateT * v2576);
struct StateT * slot_43(struct StateT * v616);
struct StateT * slot_70(struct StateT * v994);
struct StateT * slot_168(struct StateT * v2366);
struct StateT * slot_76(struct StateT * v1078);
struct StateT * slot_6(struct StateT * v98);
struct StateT * slot_225(struct StateT * v3164);
struct StateT * slot_55(struct StateT * v784);
struct StateT * slot_213(struct StateT * v2996);
struct StateT * slot_82(struct StateT * v1162);
struct StateT * slot_161(struct StateT * v2268);
struct StateT * slot_185(struct StateT * v2604);
struct StateT * slot_91(struct StateT * v1288);
struct StateT * slot_58(struct StateT * v826);
struct StateT * slot_89(struct StateT * v1260);
struct StateT * slot_66(struct StateT * v938);
struct StateT * slot_140(struct StateT * v1974);
struct StateT * slot_49(struct StateT * v700);
struct StateT * slot_216(struct StateT * v3038);
struct StateT * slot_50(struct StateT * v714);
struct StateT * slot_37(struct StateT * v532);
struct StateT * slot_114(struct StateT * v1610);
struct StateT * slot_135(struct StateT * v1904);
struct StateT * slot_59(struct StateT * v840);
struct StateT * slot_192(struct StateT * v2702);
struct StateT * slot_40(struct StateT * v574);
struct StateT * slot_48(struct StateT * v686);
struct StateT * slot_77(struct StateT * v1092);
struct StateT * slot_85(struct StateT * v1204);
struct StateT * slot_75(struct StateT * v1064);
struct StateT * slot_72(struct StateT * v1022);
struct StateT * slot_119(struct StateT * v1680);
struct StateT * slot_71(struct StateT * v1008);
struct StateT * slot_101(struct StateT * v1428);
struct StateT * slot_108(struct StateT * v1526);
struct StateT * slot_116(struct StateT * v1638);
struct StateT * slot_93(struct StateT * v1316);
struct StateT * slot_88(struct StateT * v1246);
struct StateT * slot_96(struct StateT * v1358);
struct StateT * slot_215(struct StateT * v3024);
struct StateT * slot_45(struct StateT * v644);
struct StateT * slot_218(struct StateT * v3066);
struct StateT * slot_220(struct StateT * v3094);
struct StateT * slot_134(struct StateT * v1890);
struct StateT * slot_175(struct StateT * v2464);
struct StateT * slot_69(struct StateT * v980);
struct StateT * slot_202(struct StateT * v2842);
struct StateT * slot_188(struct StateT * v2646);
struct StateT * slot_138(struct StateT * v1946);
struct StateT * slot_186(struct StateT * v2618);
struct StateT * slot_102(struct StateT * v1442);
struct StateT * slot_145(struct StateT * v2044);
struct StateT * slot_110(struct StateT * v1554);
struct StateT * slot_196(struct StateT * v2758);
struct StateT * slot_208(struct StateT * v2926);
struct StateT * slot_172(struct StateT * v2422);
struct StateT * slot_131(struct StateT * v1848);
struct StateT * slot_8(struct StateT * v126);
struct StateT * slot_180(struct StateT * v2534);
struct StateT * slot_203(struct StateT * v2856);
struct StateT * slot_190(struct StateT * v2674);
struct StateT * slot_157(struct StateT * v2212);
struct StateT * slot_200(struct StateT * v2814);
struct StateT * slot_173(struct StateT * v2436);
struct StateT * slot_149(struct StateT * v2100);
struct StateT * slot_5(struct StateT * v85);
struct StateT * slot_104(struct StateT * v1470);
struct StateT * slot_54(struct StateT * v770);
struct StateT * slot_26(struct StateT * v378);
struct StateT * slot_206(struct StateT * v2898);
struct StateT * slot_169(struct StateT * v2380);
struct StateT * slot_64(struct StateT * v910);
struct StateT * slot_170(struct StateT * v2394);
struct StateT * slot_14(struct StateT * v210);
struct StateT * slot_53(struct StateT * v756);
struct StateT * slot_80(struct StateT * v1134);
struct StateT * slot_44(struct StateT * v630);
struct StateT * slot_137(struct StateT * v1932);
struct StateT * slot_122(struct StateT * v1722);
struct StateT * slot_99(struct StateT * v1400);
struct StateT * slot_179(struct StateT * v2520);
struct StateT * slot_219(struct StateT * v3080);
struct StateT * slot_36(struct StateT * v518);
struct StateT * slot_57(struct StateT * v812);
struct StateT * slot_62(struct StateT * v882);
struct StateT * slot_22(struct StateT * v322);
struct StateT * slot_139(struct StateT * v1960);
struct StateT * slot_221(struct StateT * v3108);
struct StateT * slot_23(struct StateT * v336);
struct StateT * slot_153(struct StateT * v2156);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_86(struct StateT * v1218);
struct StateT * slot_129(struct StateT * v1820);
struct StateT * slot_158(struct StateT * v2226);
struct StateT * slot_100(struct StateT * v1414);
struct StateT * slot_127(struct StateT * v1792);
struct StateT * slot_217(struct StateT * v3052);
struct StateT * slot_13(struct StateT * v196);
struct StateT * slot_111(struct StateT * v1568);
struct StateT * slot_109(struct StateT * v1540);
struct StateT * slot_174(struct StateT * v2450);
struct StateT * slot_147(struct StateT * v2072);
struct StateT * slot_42(struct StateT * v602);
struct StateT * slot_224(struct StateT * v3150);
struct StateT * slot_163(struct StateT * v2296);
struct StateT * slot_184(struct StateT * v2590);
struct StateT * slot_204(struct StateT * v2870);
struct StateT * slot_194(struct StateT * v2730);
struct StateT * slot_165(struct StateT * v2324);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v1652);
struct StateT * slot_90(struct StateT * v1274);
struct StateT * slot_11(struct StateT * v168);
struct StateT * slot_12(struct StateT * v182) {
  int v183 = v182->timer;
  int v190 = v183 + 1;
  v182->timer = v190;
  int * v185 = v182->regs;
  int v186 = v185[8];
  int v193 = v186 + 1;
  v185[8] = v193;
  struct StateT * v188 = slot_13(v182);
  return v188;
}

struct StateT * slot_143(struct StateT * v2016) {
  int v2017 = v2016->timer;
  int v2024 = v2017 + 1;
  v2016->timer = v2024;
  int * v2019 = v2016->regs;
  int v2020 = v2019[8];
  int v2027 = v2020 + 1;
  v2019[8] = v2027;
  struct StateT * v2022 = slot_144(v2016);
  return v2022;
}

struct StateT * slot_120(struct StateT * v1694) {
  int v1695 = v1694->timer;
  int v1702 = v1695 + 1;
  v1694->timer = v1702;
  int * v1697 = v1694->regs;
  int v1698 = v1697[8];
  int v1705 = v1698 + 1;
  v1697[8] = v1705;
  struct StateT * v1700 = slot_121(v1694);
  return v1700;
}

struct StateT * slot_167(struct StateT * v2352) {
  int v2353 = v2352->timer;
  int v2360 = v2353 + 1;
  v2352->timer = v2360;
  int * v2355 = v2352->regs;
  int v2356 = v2355[8];
  int v2363 = v2356 + 1;
  v2355[8] = v2363;
  struct StateT * v2358 = slot_168(v2352);
  return v2358;
}

struct StateT * slot_152(struct StateT * v2142) {
  int v2143 = v2142->timer;
  int v2150 = v2143 + 1;
  v2142->timer = v2150;
  int * v2145 = v2142->regs;
  int v2146 = v2145[8];
  int v2153 = v2146 + 1;
  v2145[8] = v2153;
  struct StateT * v2148 = slot_153(v2142);
  return v2148;
}

struct StateT * slot_199(struct StateT * v2800) {
  int v2801 = v2800->timer;
  int v2808 = v2801 + 1;
  v2800->timer = v2808;
  int * v2803 = v2800->regs;
  int v2804 = v2803[8];
  int v2811 = v2804 + 1;
  v2803[8] = v2811;
  struct StateT * v2806 = slot_200(v2800);
  return v2806;
}

struct StateT * slot_92(struct StateT * v1302) {
  int v1303 = v1302->timer;
  int v1310 = v1303 + 1;
  v1302->timer = v1310;
  int * v1305 = v1302->regs;
  int v1306 = v1305[8];
  int v1313 = v1306 + 1;
  v1305[8] = v1313;
  struct StateT * v1308 = slot_93(v1302);
  return v1308;
}

struct StateT * slot_31(struct StateT * v448) {
  int v449 = v448->timer;
  int v456 = v449 + 1;
  v448->timer = v456;
  int * v451 = v448->regs;
  int v452 = v451[8];
  int v459 = v452 + 1;
  v451[8] = v459;
  struct StateT * v454 = slot_32(v448);
  return v454;
}

struct StateT * slot_160(struct StateT * v2254) {
  int v2255 = v2254->timer;
  int v2262 = v2255 + 1;
  v2254->timer = v2262;
  int * v2257 = v2254->regs;
  int v2258 = v2257[8];
  int v2265 = v2258 + 1;
  v2257[8] = v2265;
  struct StateT * v2260 = slot_161(v2254);
  return v2260;
}

struct StateT * slot_65(struct StateT * v924) {
  int v925 = v924->timer;
  int v932 = v925 + 1;
  v924->timer = v932;
  int * v927 = v924->regs;
  int v928 = v927[8];
  int v935 = v928 + 1;
  v927[8] = v935;
  struct StateT * v930 = slot_66(v924);
  return v930;
}

struct StateT * slot_10(struct StateT * v154) {
  int v155 = v154->timer;
  int v162 = v155 + 1;
  v154->timer = v162;
  int * v157 = v154->regs;
  int v158 = v157[8];
  int v165 = v158 + 1;
  v157[8] = v165;
  struct StateT * v160 = slot_11(v154);
  return v160;
}

struct StateT * slot_150(struct StateT * v2114) {
  int v2115 = v2114->timer;
  int v2122 = v2115 + 1;
  v2114->timer = v2122;
  int * v2117 = v2114->regs;
  int v2118 = v2117[8];
  int v2125 = v2118 + 1;
  v2117[8] = v2125;
  struct StateT * v2120 = slot_151(v2114);
  return v2120;
}

struct StateT * slot_74(struct StateT * v1050) {
  int v1051 = v1050->timer;
  int v1058 = v1051 + 1;
  v1050->timer = v1058;
  int * v1053 = v1050->regs;
  int v1054 = v1053[8];
  int v1061 = v1054 + 1;
  v1053[8] = v1061;
  struct StateT * v1056 = slot_75(v1050);
  return v1056;
}

struct StateT * slot_107(struct StateT * v1512) {
  int v1513 = v1512->timer;
  int v1520 = v1513 + 1;
  v1512->timer = v1520;
  int * v1515 = v1512->regs;
  int v1516 = v1515[8];
  int v1523 = v1516 + 1;
  v1515[8] = v1523;
  struct StateT * v1518 = slot_108(v1512);
  return v1518;
}

struct StateT * slot_136(struct StateT * v1918) {
  int v1919 = v1918->timer;
  int v1926 = v1919 + 1;
  v1918->timer = v1926;
  int * v1921 = v1918->regs;
  int v1922 = v1921[8];
  int v1929 = v1922 + 1;
  v1921[8] = v1929;
  struct StateT * v1924 = slot_137(v1918);
  return v1924;
}

struct StateT * slot_84(struct StateT * v1190) {
  int v1191 = v1190->timer;
  int v1198 = v1191 + 1;
  v1190->timer = v1198;
  int * v1193 = v1190->regs;
  int v1194 = v1193[8];
  int v1201 = v1194 + 1;
  v1193[8] = v1201;
  struct StateT * v1196 = slot_85(v1190);
  return v1196;
}

struct StateT * slot_28(struct StateT * v406) {
  int v407 = v406->timer;
  int v414 = v407 + 1;
  v406->timer = v414;
  int * v409 = v406->regs;
  int v410 = v409[8];
  int v417 = v410 + 1;
  v409[8] = v417;
  struct StateT * v412 = slot_29(v406);
  return v412;
}

struct StateT * slot_155(struct StateT * v2184) {
  int v2185 = v2184->timer;
  int v2192 = v2185 + 1;
  v2184->timer = v2192;
  int * v2187 = v2184->regs;
  int v2188 = v2187[8];
  int v2195 = v2188 + 1;
  v2187[8] = v2195;
  struct StateT * v2190 = slot_156(v2184);
  return v2190;
}

struct StateT * slot_177(struct StateT * v2492) {
  int v2493 = v2492->timer;
  int v2500 = v2493 + 1;
  v2492->timer = v2500;
  int * v2495 = v2492->regs;
  int v2496 = v2495[8];
  int v2503 = v2496 + 1;
  v2495[8] = v2503;
  struct StateT * v2498 = slot_178(v2492);
  return v2498;
}

struct StateT * slot_17(struct StateT * v252) {
  int v253 = v252->timer;
  int v260 = v253 + 1;
  v252->timer = v260;
  int * v255 = v252->regs;
  int v256 = v255[8];
  int v263 = v256 + 1;
  v255[8] = v263;
  struct StateT * v258 = slot_18(v252);
  return v258;
}

struct StateT * slot_181(struct StateT * v2548) {
  int v2549 = v2548->timer;
  int v2556 = v2549 + 1;
  v2548->timer = v2556;
  int * v2551 = v2548->regs;
  int v2552 = v2551[8];
  int v2559 = v2552 + 1;
  v2551[8] = v2559;
  struct StateT * v2554 = slot_182(v2548);
  return v2554;
}

struct StateT * slot_197(struct StateT * v2772) {
  int v2773 = v2772->timer;
  int v2780 = v2773 + 1;
  v2772->timer = v2780;
  int * v2775 = v2772->regs;
  int v2776 = v2775[8];
  int v2783 = v2776 + 1;
  v2775[8] = v2783;
  struct StateT * v2778 = slot_198(v2772);
  return v2778;
}

struct StateT * slot_207(struct StateT * v2912) {
  int v2913 = v2912->timer;
  int v2920 = v2913 + 1;
  v2912->timer = v2920;
  int * v2915 = v2912->regs;
  int v2916 = v2915[8];
  int v2923 = v2916 + 1;
  v2915[8] = v2923;
  struct StateT * v2918 = slot_208(v2912);
  return v2918;
}

struct StateT * slot_156(struct StateT * v2198) {
  int v2199 = v2198->timer;
  int v2206 = v2199 + 1;
  v2198->timer = v2206;
  int * v2201 = v2198->regs;
  int v2202 = v2201[8];
  int v2209 = v2202 + 1;
  v2201[8] = v2209;
  struct StateT * v2204 = slot_157(v2198);
  return v2204;
}

struct StateT * slot_154(struct StateT * v2170) {
  int v2171 = v2170->timer;
  int v2178 = v2171 + 1;
  v2170->timer = v2178;
  int * v2173 = v2170->regs;
  int v2174 = v2173[8];
  int v2181 = v2174 + 1;
  v2173[8] = v2181;
  struct StateT * v2176 = slot_155(v2170);
  return v2176;
}

struct StateT * slot_68(struct StateT * v966) {
  int v967 = v966->timer;
  int v974 = v967 + 1;
  v966->timer = v974;
  int * v969 = v966->regs;
  int v970 = v969[8];
  int v977 = v970 + 1;
  v969[8] = v977;
  struct StateT * v972 = slot_69(v966);
  return v972;
}

struct StateT * slot_105(struct StateT * v1484) {
  int v1485 = v1484->timer;
  int v1492 = v1485 + 1;
  v1484->timer = v1492;
  int * v1487 = v1484->regs;
  int v1488 = v1487[8];
  int v1495 = v1488 + 1;
  v1487[8] = v1495;
  struct StateT * v1490 = slot_106(v1484);
  return v1490;
}

struct StateT * slot_27(struct StateT * v392) {
  int v393 = v392->timer;
  int v400 = v393 + 1;
  v392->timer = v400;
  int * v395 = v392->regs;
  int v396 = v395[8];
  int v403 = v396 + 1;
  v395[8] = v403;
  struct StateT * v398 = slot_28(v392);
  return v398;
}

struct StateT * slot_164(struct StateT * v2310) {
  int v2311 = v2310->timer;
  int v2318 = v2311 + 1;
  v2310->timer = v2318;
  int * v2313 = v2310->regs;
  int v2314 = v2313[8];
  int v2321 = v2314 + 1;
  v2313[8] = v2321;
  struct StateT * v2316 = slot_165(v2310);
  return v2316;
}

struct StateT * slot_15(struct StateT * v224) {
  int v225 = v224->timer;
  int v232 = v225 + 1;
  v224->timer = v232;
  int * v227 = v224->regs;
  int v228 = v227[8];
  int v235 = v228 + 1;
  v227[8] = v235;
  struct StateT * v230 = slot_16(v224);
  return v230;
}

struct StateT * slot_133(struct StateT * v1876) {
  int v1877 = v1876->timer;
  int v1884 = v1877 + 1;
  v1876->timer = v1884;
  int * v1879 = v1876->regs;
  int v1880 = v1879[8];
  int v1887 = v1880 + 1;
  v1879[8] = v1887;
  struct StateT * v1882 = slot_134(v1876);
  return v1882;
}

struct StateT * slot_56(struct StateT * v798) {
  int v799 = v798->timer;
  int v806 = v799 + 1;
  v798->timer = v806;
  int * v801 = v798->regs;
  int v802 = v801[8];
  int v809 = v802 + 1;
  v801[8] = v809;
  struct StateT * v804 = slot_57(v798);
  return v804;
}

struct StateT * slot_222(struct StateT * v3122) {
  int v3123 = v3122->timer;
  int v3130 = v3123 + 1;
  v3122->timer = v3130;
  int * v3125 = v3122->regs;
  int v3126 = v3125[8];
  int v3133 = v3126 + 1;
  v3125[8] = v3133;
  struct StateT * v3128 = slot_223(v3122);
  return v3128;
}

struct StateT * slot_34(struct StateT * v490) {
  int v491 = v490->timer;
  int v498 = v491 + 1;
  v490->timer = v498;
  int * v493 = v490->regs;
  int v494 = v493[8];
  int v501 = v494 + 1;
  v493[8] = v501;
  struct StateT * v496 = slot_35(v490);
  return v496;
}

struct StateT * slot_171(struct StateT * v2408) {
  int v2409 = v2408->timer;
  int v2416 = v2409 + 1;
  v2408->timer = v2416;
  int * v2411 = v2408->regs;
  int v2412 = v2411[8];
  int v2419 = v2412 + 1;
  v2411[8] = v2419;
  struct StateT * v2414 = slot_172(v2408);
  return v2414;
}

struct StateT * slot_162(struct StateT * v2282) {
  int v2283 = v2282->timer;
  int v2290 = v2283 + 1;
  v2282->timer = v2290;
  int * v2285 = v2282->regs;
  int v2286 = v2285[8];
  int v2293 = v2286 + 1;
  v2285[8] = v2293;
  struct StateT * v2288 = slot_163(v2282);
  return v2288;
}

struct StateT * slot_21(struct StateT * v308) {
  int v309 = v308->timer;
  int v316 = v309 + 1;
  v308->timer = v316;
  int * v311 = v308->regs;
  int v312 = v311[8];
  int v319 = v312 + 1;
  v311[8] = v319;
  struct StateT * v314 = slot_22(v308);
  return v314;
}

struct StateT * slot_118(struct StateT * v1666) {
  int v1667 = v1666->timer;
  int v1674 = v1667 + 1;
  v1666->timer = v1674;
  int * v1669 = v1666->regs;
  int v1670 = v1669[8];
  int v1677 = v1670 + 1;
  v1669[8] = v1677;
  struct StateT * v1672 = slot_119(v1666);
  return v1672;
}

struct StateT * slot_121(struct StateT * v1708) {
  int v1709 = v1708->timer;
  int v1716 = v1709 + 1;
  v1708->timer = v1716;
  int * v1711 = v1708->regs;
  int v1712 = v1711[8];
  int v1719 = v1712 + 1;
  v1711[8] = v1719;
  struct StateT * v1714 = slot_122(v1708);
  return v1714;
}

struct StateT * slot_144(struct StateT * v2030) {
  int v2031 = v2030->timer;
  int v2038 = v2031 + 1;
  v2030->timer = v2038;
  int * v2033 = v2030->regs;
  int v2034 = v2033[8];
  int v2041 = v2034 + 1;
  v2033[8] = v2041;
  struct StateT * v2036 = slot_145(v2030);
  return v2036;
}

struct StateT * slot_201(struct StateT * v2828) {
  int v2829 = v2828->timer;
  int v2836 = v2829 + 1;
  v2828->timer = v2836;
  int * v2831 = v2828->regs;
  int v2832 = v2831[8];
  int v2839 = v2832 + 1;
  v2831[8] = v2839;
  struct StateT * v2834 = slot_202(v2828);
  return v2834;
}

struct StateT * slot_94(struct StateT * v1330) {
  int v1331 = v1330->timer;
  int v1338 = v1331 + 1;
  v1330->timer = v1338;
  int * v1333 = v1330->regs;
  int v1334 = v1333[8];
  int v1341 = v1334 + 1;
  v1333[8] = v1341;
  struct StateT * v1336 = slot_95(v1330);
  return v1336;
}

struct StateT * slot_63(struct StateT * v896) {
  int v897 = v896->timer;
  int v904 = v897 + 1;
  v896->timer = v904;
  int * v899 = v896->regs;
  int v900 = v899[8];
  int v907 = v900 + 1;
  v899[8] = v907;
  struct StateT * v902 = slot_64(v896);
  return v902;
}

struct StateT * slot_146(struct StateT * v2058) {
  int v2059 = v2058->timer;
  int v2066 = v2059 + 1;
  v2058->timer = v2066;
  int * v2061 = v2058->regs;
  int v2062 = v2061[8];
  int v2069 = v2062 + 1;
  v2061[8] = v2069;
  struct StateT * v2064 = slot_147(v2058);
  return v2064;
}

struct StateT * slot_24(struct StateT * v350) {
  int v351 = v350->timer;
  int v358 = v351 + 1;
  v350->timer = v358;
  int * v353 = v350->regs;
  int v354 = v353[8];
  int v361 = v354 + 1;
  v353[8] = v361;
  struct StateT * v356 = slot_25(v350);
  return v356;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->mem;
  int v16 = (int)((unsigned int)v6 >> 2);
  int v8 = v7[v16];
  v5[5] = v8;
  struct StateT * v10 = slot_1(v2);
  return v10;
}

struct StateT * slot_195(struct StateT * v2744) {
  int v2745 = v2744->timer;
  int v2752 = v2745 + 1;
  v2744->timer = v2752;
  int * v2747 = v2744->regs;
  int v2748 = v2747[8];
  int v2755 = v2748 + 1;
  v2747[8] = v2755;
  struct StateT * v2750 = slot_196(v2744);
  return v2750;
}

struct StateT * slot_125(struct StateT * v1764) {
  int v1765 = v1764->timer;
  int v1772 = v1765 + 1;
  v1764->timer = v1772;
  int * v1767 = v1764->regs;
  int v1768 = v1767[8];
  int v1775 = v1768 + 1;
  v1767[8] = v1775;
  struct StateT * v1770 = slot_126(v1764);
  return v1770;
}

struct StateT * slot_148(struct StateT * v2086) {
  int v2087 = v2086->timer;
  int v2094 = v2087 + 1;
  v2086->timer = v2094;
  int * v2089 = v2086->regs;
  int v2090 = v2089[8];
  int v2097 = v2090 + 1;
  v2089[8] = v2097;
  struct StateT * v2092 = slot_149(v2086);
  return v2092;
}

struct StateT * slot_126(struct StateT * v1778) {
  int v1779 = v1778->timer;
  int v1786 = v1779 + 1;
  v1778->timer = v1786;
  int * v1781 = v1778->regs;
  int v1782 = v1781[8];
  int v1789 = v1782 + 1;
  v1781[8] = v1789;
  struct StateT * v1784 = slot_127(v1778);
  return v1784;
}

struct StateT * slot_223(struct StateT * v3136) {
  int v3137 = v3136->timer;
  int v3144 = v3137 + 1;
  v3136->timer = v3144;
  int * v3139 = v3136->regs;
  int v3140 = v3139[8];
  int v3147 = v3140 + 1;
  v3139[8] = v3147;
  struct StateT * v3142 = slot_224(v3136);
  return v3142;
}

struct StateT * slot_79(struct StateT * v1120) {
  int v1121 = v1120->timer;
  int v1128 = v1121 + 1;
  v1120->timer = v1128;
  int * v1123 = v1120->regs;
  int v1124 = v1123[8];
  int v1131 = v1124 + 1;
  v1123[8] = v1131;
  struct StateT * v1126 = slot_80(v1120);
  return v1126;
}

struct StateT * slot_41(struct StateT * v588) {
  int v589 = v588->timer;
  int v596 = v589 + 1;
  v588->timer = v596;
  int * v591 = v588->regs;
  int v592 = v591[8];
  int v599 = v592 + 1;
  v591[8] = v599;
  struct StateT * v594 = slot_42(v588);
  return v594;
}

struct StateT * slot_39(struct StateT * v560) {
  int v561 = v560->timer;
  int v568 = v561 + 1;
  v560->timer = v568;
  int * v563 = v560->regs;
  int v564 = v563[8];
  int v571 = v564 + 1;
  v563[8] = v571;
  struct StateT * v566 = slot_40(v560);
  return v566;
}

struct StateT * slot_142(struct StateT * v2002) {
  int v2003 = v2002->timer;
  int v2010 = v2003 + 1;
  v2002->timer = v2010;
  int * v2005 = v2002->regs;
  int v2006 = v2005[8];
  int v2013 = v2006 + 1;
  v2005[8] = v2013;
  struct StateT * v2008 = slot_143(v2002);
  return v2008;
}

struct StateT * slot_60(struct StateT * v854) {
  int v855 = v854->timer;
  int v862 = v855 + 1;
  v854->timer = v862;
  int * v857 = v854->regs;
  int v858 = v857[8];
  int v865 = v858 + 1;
  v857[8] = v865;
  struct StateT * v860 = slot_61(v854);
  return v860;
}

struct StateT * slot_112(struct StateT * v1582) {
  int v1583 = v1582->timer;
  int v1590 = v1583 + 1;
  v1582->timer = v1590;
  int * v1585 = v1582->regs;
  int v1586 = v1585[8];
  int v1593 = v1586 + 1;
  v1585[8] = v1593;
  struct StateT * v1588 = slot_113(v1582);
  return v1588;
}

struct StateT * slot_47(struct StateT * v672) {
  int v673 = v672->timer;
  int v680 = v673 + 1;
  v672->timer = v680;
  int * v675 = v672->regs;
  int v676 = v675[8];
  int v683 = v676 + 1;
  v675[8] = v683;
  struct StateT * v678 = slot_48(v672);
  return v678;
}

struct StateT * slot_214(struct StateT * v3010) {
  int v3011 = v3010->timer;
  int v3018 = v3011 + 1;
  v3010->timer = v3018;
  int * v3013 = v3010->regs;
  int v3014 = v3013[8];
  int v3021 = v3014 + 1;
  v3013[8] = v3021;
  struct StateT * v3016 = slot_215(v3010);
  return v3016;
}

struct StateT * slot_29(struct StateT * v420) {
  int v421 = v420->timer;
  int v428 = v421 + 1;
  v420->timer = v428;
  int * v423 = v420->regs;
  int v424 = v423[8];
  int v431 = v424 + 1;
  v423[8] = v431;
  struct StateT * v426 = slot_30(v420);
  return v426;
}

struct StateT * slot_16(struct StateT * v238) {
  int v239 = v238->timer;
  int v246 = v239 + 1;
  v238->timer = v246;
  int * v241 = v238->regs;
  int v242 = v241[8];
  int v249 = v242 + 1;
  v241[8] = v249;
  struct StateT * v244 = slot_17(v238);
  return v244;
}

struct StateT * slot_113(struct StateT * v1596) {
  int v1597 = v1596->timer;
  int v1604 = v1597 + 1;
  v1596->timer = v1604;
  int * v1599 = v1596->regs;
  int v1600 = v1599[8];
  int v1607 = v1600 + 1;
  v1599[8] = v1607;
  struct StateT * v1602 = slot_114(v1596);
  return v1602;
}

struct StateT * slot_151(struct StateT * v2128) {
  int v2129 = v2128->timer;
  int v2136 = v2129 + 1;
  v2128->timer = v2136;
  int * v2131 = v2128->regs;
  int v2132 = v2131[8];
  int v2139 = v2132 + 1;
  v2131[8] = v2139;
  struct StateT * v2134 = slot_152(v2128);
  return v2134;
}

struct StateT * slot_7(struct StateT * v112) {
  int v113 = v112->timer;
  int v120 = v113 + 1;
  v112->timer = v120;
  int * v115 = v112->regs;
  int v116 = v115[8];
  int v123 = v116 + 1;
  v115[8] = v123;
  struct StateT * v118 = slot_8(v112);
  return v118;
}

struct StateT * slot_124(struct StateT * v1750) {
  int v1751 = v1750->timer;
  int v1758 = v1751 + 1;
  v1750->timer = v1758;
  int * v1753 = v1750->regs;
  int v1754 = v1753[8];
  int v1761 = v1754 + 1;
  v1753[8] = v1761;
  struct StateT * v1756 = slot_125(v1750);
  return v1756;
}

struct StateT * slot_191(struct StateT * v2688) {
  int v2689 = v2688->timer;
  int v2696 = v2689 + 1;
  v2688->timer = v2696;
  int * v2691 = v2688->regs;
  int v2692 = v2691[8];
  int v2699 = v2692 + 1;
  v2691[8] = v2699;
  struct StateT * v2694 = slot_192(v2688);
  return v2694;
}

struct StateT * slot_103(struct StateT * v1456) {
  int v1457 = v1456->timer;
  int v1464 = v1457 + 1;
  v1456->timer = v1464;
  int * v1459 = v1456->regs;
  int v1460 = v1459[8];
  int v1467 = v1460 + 1;
  v1459[8] = v1467;
  struct StateT * v1462 = slot_104(v1456);
  return v1462;
}

struct StateT * slot_128(struct StateT * v1806) {
  int v1807 = v1806->timer;
  int v1814 = v1807 + 1;
  v1806->timer = v1814;
  int * v1809 = v1806->regs;
  int v1810 = v1809[8];
  int v1817 = v1810 + 1;
  v1809[8] = v1817;
  struct StateT * v1812 = slot_129(v1806);
  return v1812;
}

struct StateT * slot_19(struct StateT * v280) {
  int v281 = v280->timer;
  int v288 = v281 + 1;
  v280->timer = v288;
  int * v283 = v280->regs;
  int v284 = v283[8];
  int v291 = v284 + 1;
  v283[8] = v291;
  struct StateT * v286 = slot_20(v280);
  return v286;
}

struct StateT * slot_87(struct StateT * v1232) {
  int v1233 = v1232->timer;
  int v1240 = v1233 + 1;
  v1232->timer = v1240;
  int * v1235 = v1232->regs;
  int v1236 = v1235[8];
  int v1243 = v1236 + 1;
  v1235[8] = v1243;
  struct StateT * v1238 = slot_88(v1232);
  return v1238;
}

struct StateT * slot_67(struct StateT * v952) {
  int v953 = v952->timer;
  int v960 = v953 + 1;
  v952->timer = v960;
  int * v955 = v952->regs;
  int v956 = v955[8];
  int v963 = v956 + 1;
  v955[8] = v963;
  struct StateT * v958 = slot_68(v952);
  return v958;
}

struct StateT * slot_81(struct StateT * v1148) {
  int v1149 = v1148->timer;
  int v1156 = v1149 + 1;
  v1148->timer = v1156;
  int * v1151 = v1148->regs;
  int v1152 = v1151[8];
  int v1159 = v1152 + 1;
  v1151[8] = v1159;
  struct StateT * v1154 = slot_82(v1148);
  return v1154;
}

struct StateT * slot_95(struct StateT * v1344) {
  int v1345 = v1344->timer;
  int v1352 = v1345 + 1;
  v1344->timer = v1352;
  int * v1347 = v1344->regs;
  int v1348 = v1347[8];
  int v1355 = v1348 + 1;
  v1347[8] = v1355;
  struct StateT * v1350 = slot_96(v1344);
  return v1350;
}

struct StateT * slot_115(struct StateT * v1624) {
  int v1625 = v1624->timer;
  int v1632 = v1625 + 1;
  v1624->timer = v1632;
  int * v1627 = v1624->regs;
  int v1628 = v1627[8];
  int v1635 = v1628 + 1;
  v1627[8] = v1635;
  struct StateT * v1630 = slot_116(v1624);
  return v1630;
}

struct StateT * slot_78(struct StateT * v1106) {
  int v1107 = v1106->timer;
  int v1114 = v1107 + 1;
  v1106->timer = v1114;
  int * v1109 = v1106->regs;
  int v1110 = v1109[8];
  int v1117 = v1110 + 1;
  v1109[8] = v1117;
  struct StateT * v1112 = slot_79(v1106);
  return v1112;
}

struct StateT * slot_32(struct StateT * v462) {
  int v463 = v462->timer;
  int v470 = v463 + 1;
  v462->timer = v470;
  int * v465 = v462->regs;
  int v466 = v465[8];
  int v473 = v466 + 1;
  v465[8] = v473;
  struct StateT * v468 = slot_33(v462);
  return v468;
}

struct StateT * slot_205(struct StateT * v2884) {
  int v2885 = v2884->timer;
  int v2892 = v2885 + 1;
  v2884->timer = v2892;
  int * v2887 = v2884->regs;
  int v2888 = v2887[8];
  int v2895 = v2888 + 1;
  v2887[8] = v2895;
  struct StateT * v2890 = slot_206(v2884);
  return v2890;
}

struct StateT * slot_193(struct StateT * v2716) {
  int v2717 = v2716->timer;
  int v2724 = v2717 + 1;
  v2716->timer = v2724;
  int * v2719 = v2716->regs;
  int v2720 = v2719[8];
  int v2727 = v2720 + 1;
  v2719[8] = v2727;
  struct StateT * v2722 = slot_194(v2716);
  return v2722;
}

struct StateT * slot_176(struct StateT * v2478) {
  int v2479 = v2478->timer;
  int v2486 = v2479 + 1;
  v2478->timer = v2486;
  int * v2481 = v2478->regs;
  int v2482 = v2481[8];
  int v2489 = v2482 + 1;
  v2481[8] = v2489;
  struct StateT * v2484 = slot_177(v2478);
  return v2484;
}

struct StateT * slot_189(struct StateT * v2660) {
  int v2661 = v2660->timer;
  int v2668 = v2661 + 1;
  v2660->timer = v2668;
  int * v2663 = v2660->regs;
  int v2664 = v2663[8];
  int v2671 = v2664 + 1;
  v2663[8] = v2671;
  struct StateT * v2666 = slot_190(v2660);
  return v2666;
}

struct StateT * slot_33(struct StateT * v476) {
  int v477 = v476->timer;
  int v484 = v477 + 1;
  v476->timer = v484;
  int * v479 = v476->regs;
  int v480 = v479[8];
  int v487 = v480 + 1;
  v479[8] = v487;
  struct StateT * v482 = slot_34(v476);
  return v482;
}

struct StateT * slot_35(struct StateT * v504) {
  int v505 = v504->timer;
  int v512 = v505 + 1;
  v504->timer = v512;
  int * v507 = v504->regs;
  int v508 = v507[8];
  int v515 = v508 + 1;
  v507[8] = v515;
  struct StateT * v510 = slot_36(v504);
  return v510;
}

struct StateT * slot_210(struct StateT * v2954) {
  int v2955 = v2954->timer;
  int v2962 = v2955 + 1;
  v2954->timer = v2962;
  int * v2957 = v2954->regs;
  int v2958 = v2957[8];
  int v2965 = v2958 + 1;
  v2957[8] = v2965;
  struct StateT * v2960 = slot_211(v2954);
  return v2960;
}

struct StateT * slot_166(struct StateT * v2338) {
  int v2339 = v2338->timer;
  int v2346 = v2339 + 1;
  v2338->timer = v2346;
  int * v2341 = v2338->regs;
  int v2342 = v2341[8];
  int v2349 = v2342 + 1;
  v2341[8] = v2349;
  struct StateT * v2344 = slot_167(v2338);
  return v2344;
}

struct StateT * slot_51(struct StateT * v728) {
  int v729 = v728->timer;
  int v736 = v729 + 1;
  v728->timer = v736;
  int * v731 = v728->regs;
  int v732 = v731[8];
  int v739 = v732 + 1;
  v731[8] = v739;
  struct StateT * v734 = slot_52(v728);
  return v734;
}

struct StateT * slot_52(struct StateT * v742) {
  int v743 = v742->timer;
  int v750 = v743 + 1;
  v742->timer = v750;
  int * v745 = v742->regs;
  int v746 = v745[8];
  int v753 = v746 + 1;
  v745[8] = v753;
  struct StateT * v748 = slot_53(v742);
  return v748;
}

struct StateT * slot_83(struct StateT * v1176) {
  int v1177 = v1176->timer;
  int v1184 = v1177 + 1;
  v1176->timer = v1184;
  int * v1179 = v1176->regs;
  int v1180 = v1179[8];
  int v1187 = v1180 + 1;
  v1179[8] = v1187;
  struct StateT * v1182 = slot_84(v1176);
  return v1182;
}

struct StateT * slot_25(struct StateT * v364) {
  int v365 = v364->timer;
  int v372 = v365 + 1;
  v364->timer = v372;
  int * v367 = v364->regs;
  int v368 = v367[8];
  int v375 = v368 + 1;
  v367[8] = v375;
  struct StateT * v370 = slot_26(v364);
  return v370;
}

struct StateT * slot_209(struct StateT * v2940) {
  int v2941 = v2940->timer;
  int v2948 = v2941 + 1;
  v2940->timer = v2948;
  int * v2943 = v2940->regs;
  int v2944 = v2943[8];
  int v2951 = v2944 + 1;
  v2943[8] = v2951;
  struct StateT * v2946 = slot_210(v2940);
  return v2946;
}

struct StateT * slot_3(struct StateT * v52) {
  int v53 = v52->timer;
  int v60 = v53 + 1;
  v52->timer = v60;
  int * v55 = v52->regs;
  int v56 = v55[6];
  int v63 = v56 << 2;
  v55[6] = v63;
  struct StateT * v58 = slot_4(v52);
  return v58;
}

struct StateT * slot_123(struct StateT * v1736) {
  int v1737 = v1736->timer;
  int v1744 = v1737 + 1;
  v1736->timer = v1744;
  int * v1739 = v1736->regs;
  int v1740 = v1739[8];
  int v1747 = v1740 + 1;
  v1739[8] = v1747;
  struct StateT * v1742 = slot_124(v1736);
  return v1742;
}

struct StateT * slot_73(struct StateT * v1036) {
  int v1037 = v1036->timer;
  int v1044 = v1037 + 1;
  v1036->timer = v1044;
  int * v1039 = v1036->regs;
  int v1040 = v1039[8];
  int v1047 = v1040 + 1;
  v1039[8] = v1047;
  struct StateT * v1042 = slot_74(v1036);
  return v1042;
}

struct StateT * slot_198(struct StateT * v2786) {
  int v2787 = v2786->timer;
  int v2794 = v2787 + 1;
  v2786->timer = v2794;
  int * v2789 = v2786->regs;
  int v2790 = v2789[8];
  int v2797 = v2790 + 1;
  v2789[8] = v2797;
  struct StateT * v2792 = slot_199(v2786);
  return v2792;
}

struct StateT * slot_1(struct StateT * v21) {
  int v22 = v21->timer;
  int v30 = v22 + 1;
  v21->timer = v30;
  int * v24 = v21->mem;
  int v25 = v24[20];
  int * v26 = v21->regs;
  v26[6] = v25;
  struct StateT * v28 = slot_2(v21);
  return v28;
}

struct StateT * slot_187(struct StateT * v2632) {
  int v2633 = v2632->timer;
  int v2640 = v2633 + 1;
  v2632->timer = v2640;
  int * v2635 = v2632->regs;
  int v2636 = v2635[8];
  int v2643 = v2636 + 1;
  v2635[8] = v2643;
  struct StateT * v2638 = slot_188(v2632);
  return v2638;
}

struct StateT * slot_97(struct StateT * v1372) {
  int v1373 = v1372->timer;
  int v1380 = v1373 + 1;
  v1372->timer = v1380;
  int * v1375 = v1372->regs;
  int v1376 = v1375[8];
  int v1383 = v1376 + 1;
  v1375[8] = v1383;
  struct StateT * v1378 = slot_98(v1372);
  return v1378;
}

struct StateT * slot_182(struct StateT * v2562) {
  int v2563 = v2562->timer;
  int v2570 = v2563 + 1;
  v2562->timer = v2570;
  int * v2565 = v2562->regs;
  int v2566 = v2565[8];
  int v2573 = v2566 + 1;
  v2565[8] = v2573;
  struct StateT * v2568 = slot_183(v2562);
  return v2568;
}

struct StateT * slot_38(struct StateT * v546) {
  int v547 = v546->timer;
  int v554 = v547 + 1;
  v546->timer = v554;
  int * v549 = v546->regs;
  int v550 = v549[8];
  int v557 = v550 + 1;
  v549[8] = v557;
  struct StateT * v552 = slot_39(v546);
  return v552;
}

struct StateT * slot_178(struct StateT * v2506) {
  int v2507 = v2506->timer;
  int v2514 = v2507 + 1;
  v2506->timer = v2514;
  int * v2509 = v2506->regs;
  int v2510 = v2509[8];
  int v2517 = v2510 + 1;
  v2509[8] = v2517;
  struct StateT * v2512 = slot_179(v2506);
  return v2512;
}

struct StateT * slot_106(struct StateT * v1498) {
  int v1499 = v1498->timer;
  int v1506 = v1499 + 1;
  v1498->timer = v1506;
  int * v1501 = v1498->regs;
  int v1502 = v1501[8];
  int v1509 = v1502 + 1;
  v1501[8] = v1509;
  struct StateT * v1504 = slot_107(v1498);
  return v1504;
}

struct StateT * slot_98(struct StateT * v1386) {
  int v1387 = v1386->timer;
  int v1394 = v1387 + 1;
  v1386->timer = v1394;
  int * v1389 = v1386->regs;
  int v1390 = v1389[8];
  int v1397 = v1390 + 1;
  v1389[8] = v1397;
  struct StateT * v1392 = slot_99(v1386);
  return v1392;
}

struct StateT * slot_159(struct StateT * v2240) {
  int v2241 = v2240->timer;
  int v2248 = v2241 + 1;
  v2240->timer = v2248;
  int * v2243 = v2240->regs;
  int v2244 = v2243[8];
  int v2251 = v2244 + 1;
  v2243[8] = v2251;
  struct StateT * v2246 = slot_160(v2240);
  return v2246;
}

struct StateT * slot_46(struct StateT * v658) {
  int v659 = v658->timer;
  int v666 = v659 + 1;
  v658->timer = v666;
  int * v661 = v658->regs;
  int v662 = v661[8];
  int v669 = v662 + 1;
  v661[8] = v669;
  struct StateT * v664 = slot_47(v658);
  return v664;
}

struct StateT * slot_212(struct StateT * v2982) {
  int v2983 = v2982->timer;
  int v2990 = v2983 + 1;
  v2982->timer = v2990;
  int * v2985 = v2982->regs;
  int v2986 = v2985[8];
  int v2993 = v2986 + 1;
  v2985[8] = v2993;
  struct StateT * v2988 = slot_213(v2982);
  return v2988;
}

struct StateT * slot_132(struct StateT * v1862) {
  int v1863 = v1862->timer;
  int v1870 = v1863 + 1;
  v1862->timer = v1870;
  int * v1865 = v1862->regs;
  int v1866 = v1865[8];
  int v1873 = v1866 + 1;
  v1865[8] = v1873;
  struct StateT * v1868 = slot_133(v1862);
  return v1868;
}

struct StateT * slot_130(struct StateT * v1834) {
  int v1835 = v1834->timer;
  int v1842 = v1835 + 1;
  v1834->timer = v1842;
  int * v1837 = v1834->regs;
  int v1838 = v1837[8];
  int v1845 = v1838 + 1;
  v1837[8] = v1845;
  struct StateT * v1840 = slot_131(v1834);
  return v1840;
}

struct StateT * slot_211(struct StateT * v2968) {
  int v2969 = v2968->timer;
  int v2976 = v2969 + 1;
  v2968->timer = v2976;
  int * v2971 = v2968->regs;
  int v2972 = v2971[8];
  int v2979 = v2972 + 1;
  v2971[8] = v2979;
  struct StateT * v2974 = slot_212(v2968);
  return v2974;
}

struct StateT * slot_20(struct StateT * v294) {
  int v295 = v294->timer;
  int v302 = v295 + 1;
  v294->timer = v302;
  int * v297 = v294->regs;
  int v298 = v297[8];
  int v305 = v298 + 1;
  v297[8] = v305;
  struct StateT * v300 = slot_21(v294);
  return v300;
}

struct StateT * slot_141(struct StateT * v1988) {
  int v1989 = v1988->timer;
  int v1996 = v1989 + 1;
  v1988->timer = v1996;
  int * v1991 = v1988->regs;
  int v1992 = v1991[8];
  int v1999 = v1992 + 1;
  v1991[8] = v1999;
  struct StateT * v1994 = slot_142(v1988);
  return v1994;
}

struct StateT * slot_61(struct StateT * v868) {
  int v869 = v868->timer;
  int v876 = v869 + 1;
  v868->timer = v876;
  int * v871 = v868->regs;
  int v872 = v871[8];
  int v879 = v872 + 1;
  v871[8] = v879;
  struct StateT * v874 = slot_62(v868);
  return v874;
}

struct StateT * slot_30(struct StateT * v434) {
  int v435 = v434->timer;
  int v442 = v435 + 1;
  v434->timer = v442;
  int * v437 = v434->regs;
  int v438 = v437[8];
  int v445 = v438 + 1;
  v437[8] = v445;
  struct StateT * v440 = slot_31(v434);
  return v440;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v76 = v67 + 1;
  v66->timer = v76;
  int * v69 = v66->regs;
  int v70 = v69[6];
  int * v71 = v66->mem;
  int v80 = (int)((unsigned int)v70 >> 2);
  int v72 = v71[v80];
  v69[7] = v72;
  struct StateT * v74 = slot_5(v66);
  return v74;
}

struct StateT * slot_18(struct StateT * v266) {
  int v267 = v266->timer;
  int v274 = v267 + 1;
  v266->timer = v274;
  int * v269 = v266->regs;
  int v270 = v269[8];
  int v277 = v270 + 1;
  v269[8] = v277;
  struct StateT * v272 = slot_19(v266);
  return v272;
}

struct StateT * slot_9(struct StateT * v140) {
  int v141 = v140->timer;
  int v148 = v141 + 1;
  v140->timer = v148;
  int * v143 = v140->regs;
  int v144 = v143[8];
  int v151 = v144 + 1;
  v143[8] = v151;
  struct StateT * v146 = slot_10(v140);
  return v146;
}

struct StateT * slot_183(struct StateT * v2576) {
  int v2577 = v2576->timer;
  int v2584 = v2577 + 1;
  v2576->timer = v2584;
  int * v2579 = v2576->regs;
  int v2580 = v2579[8];
  int v2587 = v2580 + 1;
  v2579[8] = v2587;
  struct StateT * v2582 = slot_184(v2576);
  return v2582;
}

struct StateT * slot_43(struct StateT * v616) {
  int v617 = v616->timer;
  int v624 = v617 + 1;
  v616->timer = v624;
  int * v619 = v616->regs;
  int v620 = v619[8];
  int v627 = v620 + 1;
  v619[8] = v627;
  struct StateT * v622 = slot_44(v616);
  return v622;
}

struct StateT * slot_70(struct StateT * v994) {
  int v995 = v994->timer;
  int v1002 = v995 + 1;
  v994->timer = v1002;
  int * v997 = v994->regs;
  int v998 = v997[8];
  int v1005 = v998 + 1;
  v997[8] = v1005;
  struct StateT * v1000 = slot_71(v994);
  return v1000;
}

struct StateT * slot_168(struct StateT * v2366) {
  int v2367 = v2366->timer;
  int v2374 = v2367 + 1;
  v2366->timer = v2374;
  int * v2369 = v2366->regs;
  int v2370 = v2369[8];
  int v2377 = v2370 + 1;
  v2369[8] = v2377;
  struct StateT * v2372 = slot_169(v2366);
  return v2372;
}

struct StateT * slot_76(struct StateT * v1078) {
  int v1079 = v1078->timer;
  int v1086 = v1079 + 1;
  v1078->timer = v1086;
  int * v1081 = v1078->regs;
  int v1082 = v1081[8];
  int v1089 = v1082 + 1;
  v1081[8] = v1089;
  struct StateT * v1084 = slot_77(v1078);
  return v1084;
}

struct StateT * slot_6(struct StateT * v98) {
  int v99 = v98->timer;
  int v106 = v99 + 1;
  v98->timer = v106;
  int * v101 = v98->regs;
  int v102 = v101[8];
  int v109 = v102 + 1;
  v101[8] = v109;
  struct StateT * v104 = slot_7(v98);
  return v104;
}

struct StateT * slot_225(struct StateT * v3164) {
  int v3165 = v3164->timer;
  int v3171 = v3165 + 1;
  v3164->timer = v3171;
  int * v3167 = v3164->regs;
  int v3168 = v3167[8];
  int v3174 = v3168 + 1;
  v3167[8] = v3174;
  return v3164;
}

struct StateT * slot_55(struct StateT * v784) {
  int v785 = v784->timer;
  int v792 = v785 + 1;
  v784->timer = v792;
  int * v787 = v784->regs;
  int v788 = v787[8];
  int v795 = v788 + 1;
  v787[8] = v795;
  struct StateT * v790 = slot_56(v784);
  return v790;
}

struct StateT * slot_213(struct StateT * v2996) {
  int v2997 = v2996->timer;
  int v3004 = v2997 + 1;
  v2996->timer = v3004;
  int * v2999 = v2996->regs;
  int v3000 = v2999[8];
  int v3007 = v3000 + 1;
  v2999[8] = v3007;
  struct StateT * v3002 = slot_214(v2996);
  return v3002;
}

struct StateT * slot_82(struct StateT * v1162) {
  int v1163 = v1162->timer;
  int v1170 = v1163 + 1;
  v1162->timer = v1170;
  int * v1165 = v1162->regs;
  int v1166 = v1165[8];
  int v1173 = v1166 + 1;
  v1165[8] = v1173;
  struct StateT * v1168 = slot_83(v1162);
  return v1168;
}

struct StateT * slot_161(struct StateT * v2268) {
  int v2269 = v2268->timer;
  int v2276 = v2269 + 1;
  v2268->timer = v2276;
  int * v2271 = v2268->regs;
  int v2272 = v2271[8];
  int v2279 = v2272 + 1;
  v2271[8] = v2279;
  struct StateT * v2274 = slot_162(v2268);
  return v2274;
}

struct StateT * slot_185(struct StateT * v2604) {
  int v2605 = v2604->timer;
  int v2612 = v2605 + 1;
  v2604->timer = v2612;
  int * v2607 = v2604->regs;
  int v2608 = v2607[8];
  int v2615 = v2608 + 1;
  v2607[8] = v2615;
  struct StateT * v2610 = slot_186(v2604);
  return v2610;
}

struct StateT * slot_91(struct StateT * v1288) {
  int v1289 = v1288->timer;
  int v1296 = v1289 + 1;
  v1288->timer = v1296;
  int * v1291 = v1288->regs;
  int v1292 = v1291[8];
  int v1299 = v1292 + 1;
  v1291[8] = v1299;
  struct StateT * v1294 = slot_92(v1288);
  return v1294;
}

struct StateT * slot_58(struct StateT * v826) {
  int v827 = v826->timer;
  int v834 = v827 + 1;
  v826->timer = v834;
  int * v829 = v826->regs;
  int v830 = v829[8];
  int v837 = v830 + 1;
  v829[8] = v837;
  struct StateT * v832 = slot_59(v826);
  return v832;
}

struct StateT * slot_89(struct StateT * v1260) {
  int v1261 = v1260->timer;
  int v1268 = v1261 + 1;
  v1260->timer = v1268;
  int * v1263 = v1260->regs;
  int v1264 = v1263[8];
  int v1271 = v1264 + 1;
  v1263[8] = v1271;
  struct StateT * v1266 = slot_90(v1260);
  return v1266;
}

struct StateT * slot_66(struct StateT * v938) {
  int v939 = v938->timer;
  int v946 = v939 + 1;
  v938->timer = v946;
  int * v941 = v938->regs;
  int v942 = v941[8];
  int v949 = v942 + 1;
  v941[8] = v949;
  struct StateT * v944 = slot_67(v938);
  return v944;
}

struct StateT * slot_140(struct StateT * v1974) {
  int v1975 = v1974->timer;
  int v1982 = v1975 + 1;
  v1974->timer = v1982;
  int * v1977 = v1974->regs;
  int v1978 = v1977[8];
  int v1985 = v1978 + 1;
  v1977[8] = v1985;
  struct StateT * v1980 = slot_141(v1974);
  return v1980;
}

struct StateT * slot_49(struct StateT * v700) {
  int v701 = v700->timer;
  int v708 = v701 + 1;
  v700->timer = v708;
  int * v703 = v700->regs;
  int v704 = v703[8];
  int v711 = v704 + 1;
  v703[8] = v711;
  struct StateT * v706 = slot_50(v700);
  return v706;
}

struct StateT * slot_216(struct StateT * v3038) {
  int v3039 = v3038->timer;
  int v3046 = v3039 + 1;
  v3038->timer = v3046;
  int * v3041 = v3038->regs;
  int v3042 = v3041[8];
  int v3049 = v3042 + 1;
  v3041[8] = v3049;
  struct StateT * v3044 = slot_217(v3038);
  return v3044;
}

struct StateT * slot_50(struct StateT * v714) {
  int v715 = v714->timer;
  int v722 = v715 + 1;
  v714->timer = v722;
  int * v717 = v714->regs;
  int v718 = v717[8];
  int v725 = v718 + 1;
  v717[8] = v725;
  struct StateT * v720 = slot_51(v714);
  return v720;
}

struct StateT * slot_37(struct StateT * v532) {
  int v533 = v532->timer;
  int v540 = v533 + 1;
  v532->timer = v540;
  int * v535 = v532->regs;
  int v536 = v535[8];
  int v543 = v536 + 1;
  v535[8] = v543;
  struct StateT * v538 = slot_38(v532);
  return v538;
}

struct StateT * slot_114(struct StateT * v1610) {
  int v1611 = v1610->timer;
  int v1618 = v1611 + 1;
  v1610->timer = v1618;
  int * v1613 = v1610->regs;
  int v1614 = v1613[8];
  int v1621 = v1614 + 1;
  v1613[8] = v1621;
  struct StateT * v1616 = slot_115(v1610);
  return v1616;
}

struct StateT * slot_135(struct StateT * v1904) {
  int v1905 = v1904->timer;
  int v1912 = v1905 + 1;
  v1904->timer = v1912;
  int * v1907 = v1904->regs;
  int v1908 = v1907[8];
  int v1915 = v1908 + 1;
  v1907[8] = v1915;
  struct StateT * v1910 = slot_136(v1904);
  return v1910;
}

struct StateT * slot_59(struct StateT * v840) {
  int v841 = v840->timer;
  int v848 = v841 + 1;
  v840->timer = v848;
  int * v843 = v840->regs;
  int v844 = v843[8];
  int v851 = v844 + 1;
  v843[8] = v851;
  struct StateT * v846 = slot_60(v840);
  return v846;
}

struct StateT * slot_192(struct StateT * v2702) {
  int v2703 = v2702->timer;
  int v2710 = v2703 + 1;
  v2702->timer = v2710;
  int * v2705 = v2702->regs;
  int v2706 = v2705[8];
  int v2713 = v2706 + 1;
  v2705[8] = v2713;
  struct StateT * v2708 = slot_193(v2702);
  return v2708;
}

struct StateT * slot_40(struct StateT * v574) {
  int v575 = v574->timer;
  int v582 = v575 + 1;
  v574->timer = v582;
  int * v577 = v574->regs;
  int v578 = v577[8];
  int v585 = v578 + 1;
  v577[8] = v585;
  struct StateT * v580 = slot_41(v574);
  return v580;
}

struct StateT * slot_48(struct StateT * v686) {
  int v687 = v686->timer;
  int v694 = v687 + 1;
  v686->timer = v694;
  int * v689 = v686->regs;
  int v690 = v689[8];
  int v697 = v690 + 1;
  v689[8] = v697;
  struct StateT * v692 = slot_49(v686);
  return v692;
}

struct StateT * slot_77(struct StateT * v1092) {
  int v1093 = v1092->timer;
  int v1100 = v1093 + 1;
  v1092->timer = v1100;
  int * v1095 = v1092->regs;
  int v1096 = v1095[8];
  int v1103 = v1096 + 1;
  v1095[8] = v1103;
  struct StateT * v1098 = slot_78(v1092);
  return v1098;
}

struct StateT * slot_85(struct StateT * v1204) {
  int v1205 = v1204->timer;
  int v1212 = v1205 + 1;
  v1204->timer = v1212;
  int * v1207 = v1204->regs;
  int v1208 = v1207[8];
  int v1215 = v1208 + 1;
  v1207[8] = v1215;
  struct StateT * v1210 = slot_86(v1204);
  return v1210;
}

struct StateT * slot_75(struct StateT * v1064) {
  int v1065 = v1064->timer;
  int v1072 = v1065 + 1;
  v1064->timer = v1072;
  int * v1067 = v1064->regs;
  int v1068 = v1067[8];
  int v1075 = v1068 + 1;
  v1067[8] = v1075;
  struct StateT * v1070 = slot_76(v1064);
  return v1070;
}

struct StateT * slot_72(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1030 = v1023 + 1;
  v1022->timer = v1030;
  int * v1025 = v1022->regs;
  int v1026 = v1025[8];
  int v1033 = v1026 + 1;
  v1025[8] = v1033;
  struct StateT * v1028 = slot_73(v1022);
  return v1028;
}

struct StateT * slot_119(struct StateT * v1680) {
  int v1681 = v1680->timer;
  int v1688 = v1681 + 1;
  v1680->timer = v1688;
  int * v1683 = v1680->regs;
  int v1684 = v1683[8];
  int v1691 = v1684 + 1;
  v1683[8] = v1691;
  struct StateT * v1686 = slot_120(v1680);
  return v1686;
}

struct StateT * slot_71(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v1016 = v1009 + 1;
  v1008->timer = v1016;
  int * v1011 = v1008->regs;
  int v1012 = v1011[8];
  int v1019 = v1012 + 1;
  v1011[8] = v1019;
  struct StateT * v1014 = slot_72(v1008);
  return v1014;
}

struct StateT * slot_101(struct StateT * v1428) {
  int v1429 = v1428->timer;
  int v1436 = v1429 + 1;
  v1428->timer = v1436;
  int * v1431 = v1428->regs;
  int v1432 = v1431[8];
  int v1439 = v1432 + 1;
  v1431[8] = v1439;
  struct StateT * v1434 = slot_102(v1428);
  return v1434;
}

struct StateT * slot_108(struct StateT * v1526) {
  int v1527 = v1526->timer;
  int v1534 = v1527 + 1;
  v1526->timer = v1534;
  int * v1529 = v1526->regs;
  int v1530 = v1529[8];
  int v1537 = v1530 + 1;
  v1529[8] = v1537;
  struct StateT * v1532 = slot_109(v1526);
  return v1532;
}

struct StateT * slot_116(struct StateT * v1638) {
  int v1639 = v1638->timer;
  int v1646 = v1639 + 1;
  v1638->timer = v1646;
  int * v1641 = v1638->regs;
  int v1642 = v1641[8];
  int v1649 = v1642 + 1;
  v1641[8] = v1649;
  struct StateT * v1644 = slot_117(v1638);
  return v1644;
}

struct StateT * slot_93(struct StateT * v1316) {
  int v1317 = v1316->timer;
  int v1324 = v1317 + 1;
  v1316->timer = v1324;
  int * v1319 = v1316->regs;
  int v1320 = v1319[8];
  int v1327 = v1320 + 1;
  v1319[8] = v1327;
  struct StateT * v1322 = slot_94(v1316);
  return v1322;
}

struct StateT * slot_88(struct StateT * v1246) {
  int v1247 = v1246->timer;
  int v1254 = v1247 + 1;
  v1246->timer = v1254;
  int * v1249 = v1246->regs;
  int v1250 = v1249[8];
  int v1257 = v1250 + 1;
  v1249[8] = v1257;
  struct StateT * v1252 = slot_89(v1246);
  return v1252;
}

struct StateT * slot_96(struct StateT * v1358) {
  int v1359 = v1358->timer;
  int v1366 = v1359 + 1;
  v1358->timer = v1366;
  int * v1361 = v1358->regs;
  int v1362 = v1361[8];
  int v1369 = v1362 + 1;
  v1361[8] = v1369;
  struct StateT * v1364 = slot_97(v1358);
  return v1364;
}

struct StateT * slot_215(struct StateT * v3024) {
  int v3025 = v3024->timer;
  int v3032 = v3025 + 1;
  v3024->timer = v3032;
  int * v3027 = v3024->regs;
  int v3028 = v3027[8];
  int v3035 = v3028 + 1;
  v3027[8] = v3035;
  struct StateT * v3030 = slot_216(v3024);
  return v3030;
}

struct StateT * slot_45(struct StateT * v644) {
  int v645 = v644->timer;
  int v652 = v645 + 1;
  v644->timer = v652;
  int * v647 = v644->regs;
  int v648 = v647[8];
  int v655 = v648 + 1;
  v647[8] = v655;
  struct StateT * v650 = slot_46(v644);
  return v650;
}

struct StateT * slot_218(struct StateT * v3066) {
  int v3067 = v3066->timer;
  int v3074 = v3067 + 1;
  v3066->timer = v3074;
  int * v3069 = v3066->regs;
  int v3070 = v3069[8];
  int v3077 = v3070 + 1;
  v3069[8] = v3077;
  struct StateT * v3072 = slot_219(v3066);
  return v3072;
}

struct StateT * slot_220(struct StateT * v3094) {
  int v3095 = v3094->timer;
  int v3102 = v3095 + 1;
  v3094->timer = v3102;
  int * v3097 = v3094->regs;
  int v3098 = v3097[8];
  int v3105 = v3098 + 1;
  v3097[8] = v3105;
  struct StateT * v3100 = slot_221(v3094);
  return v3100;
}

struct StateT * slot_134(struct StateT * v1890) {
  int v1891 = v1890->timer;
  int v1898 = v1891 + 1;
  v1890->timer = v1898;
  int * v1893 = v1890->regs;
  int v1894 = v1893[8];
  int v1901 = v1894 + 1;
  v1893[8] = v1901;
  struct StateT * v1896 = slot_135(v1890);
  return v1896;
}

struct StateT * slot_175(struct StateT * v2464) {
  int v2465 = v2464->timer;
  int v2472 = v2465 + 1;
  v2464->timer = v2472;
  int * v2467 = v2464->regs;
  int v2468 = v2467[8];
  int v2475 = v2468 + 1;
  v2467[8] = v2475;
  struct StateT * v2470 = slot_176(v2464);
  return v2470;
}

struct StateT * slot_69(struct StateT * v980) {
  int v981 = v980->timer;
  int v988 = v981 + 1;
  v980->timer = v988;
  int * v983 = v980->regs;
  int v984 = v983[8];
  int v991 = v984 + 1;
  v983[8] = v991;
  struct StateT * v986 = slot_70(v980);
  return v986;
}

struct StateT * slot_202(struct StateT * v2842) {
  int v2843 = v2842->timer;
  int v2850 = v2843 + 1;
  v2842->timer = v2850;
  int * v2845 = v2842->regs;
  int v2846 = v2845[8];
  int v2853 = v2846 + 1;
  v2845[8] = v2853;
  struct StateT * v2848 = slot_203(v2842);
  return v2848;
}

struct StateT * slot_188(struct StateT * v2646) {
  int v2647 = v2646->timer;
  int v2654 = v2647 + 1;
  v2646->timer = v2654;
  int * v2649 = v2646->regs;
  int v2650 = v2649[8];
  int v2657 = v2650 + 1;
  v2649[8] = v2657;
  struct StateT * v2652 = slot_189(v2646);
  return v2652;
}

struct StateT * slot_138(struct StateT * v1946) {
  int v1947 = v1946->timer;
  int v1954 = v1947 + 1;
  v1946->timer = v1954;
  int * v1949 = v1946->regs;
  int v1950 = v1949[8];
  int v1957 = v1950 + 1;
  v1949[8] = v1957;
  struct StateT * v1952 = slot_139(v1946);
  return v1952;
}

struct StateT * slot_186(struct StateT * v2618) {
  int v2619 = v2618->timer;
  int v2626 = v2619 + 1;
  v2618->timer = v2626;
  int * v2621 = v2618->regs;
  int v2622 = v2621[8];
  int v2629 = v2622 + 1;
  v2621[8] = v2629;
  struct StateT * v2624 = slot_187(v2618);
  return v2624;
}

struct StateT * slot_102(struct StateT * v1442) {
  int v1443 = v1442->timer;
  int v1450 = v1443 + 1;
  v1442->timer = v1450;
  int * v1445 = v1442->regs;
  int v1446 = v1445[8];
  int v1453 = v1446 + 1;
  v1445[8] = v1453;
  struct StateT * v1448 = slot_103(v1442);
  return v1448;
}

struct StateT * slot_145(struct StateT * v2044) {
  int v2045 = v2044->timer;
  int v2052 = v2045 + 1;
  v2044->timer = v2052;
  int * v2047 = v2044->regs;
  int v2048 = v2047[8];
  int v2055 = v2048 + 1;
  v2047[8] = v2055;
  struct StateT * v2050 = slot_146(v2044);
  return v2050;
}

struct StateT * slot_110(struct StateT * v1554) {
  int v1555 = v1554->timer;
  int v1562 = v1555 + 1;
  v1554->timer = v1562;
  int * v1557 = v1554->regs;
  int v1558 = v1557[8];
  int v1565 = v1558 + 1;
  v1557[8] = v1565;
  struct StateT * v1560 = slot_111(v1554);
  return v1560;
}

struct StateT * slot_196(struct StateT * v2758) {
  int v2759 = v2758->timer;
  int v2766 = v2759 + 1;
  v2758->timer = v2766;
  int * v2761 = v2758->regs;
  int v2762 = v2761[8];
  int v2769 = v2762 + 1;
  v2761[8] = v2769;
  struct StateT * v2764 = slot_197(v2758);
  return v2764;
}

struct StateT * slot_208(struct StateT * v2926) {
  int v2927 = v2926->timer;
  int v2934 = v2927 + 1;
  v2926->timer = v2934;
  int * v2929 = v2926->regs;
  int v2930 = v2929[8];
  int v2937 = v2930 + 1;
  v2929[8] = v2937;
  struct StateT * v2932 = slot_209(v2926);
  return v2932;
}

struct StateT * slot_172(struct StateT * v2422) {
  int v2423 = v2422->timer;
  int v2430 = v2423 + 1;
  v2422->timer = v2430;
  int * v2425 = v2422->regs;
  int v2426 = v2425[8];
  int v2433 = v2426 + 1;
  v2425[8] = v2433;
  struct StateT * v2428 = slot_173(v2422);
  return v2428;
}

struct StateT * slot_131(struct StateT * v1848) {
  int v1849 = v1848->timer;
  int v1856 = v1849 + 1;
  v1848->timer = v1856;
  int * v1851 = v1848->regs;
  int v1852 = v1851[8];
  int v1859 = v1852 + 1;
  v1851[8] = v1859;
  struct StateT * v1854 = slot_132(v1848);
  return v1854;
}

struct StateT * slot_8(struct StateT * v126) {
  int v127 = v126->timer;
  int v134 = v127 + 1;
  v126->timer = v134;
  int * v129 = v126->regs;
  int v130 = v129[8];
  int v137 = v130 + 1;
  v129[8] = v137;
  struct StateT * v132 = slot_9(v126);
  return v132;
}

struct StateT * slot_180(struct StateT * v2534) {
  int v2535 = v2534->timer;
  int v2542 = v2535 + 1;
  v2534->timer = v2542;
  int * v2537 = v2534->regs;
  int v2538 = v2537[8];
  int v2545 = v2538 + 1;
  v2537[8] = v2545;
  struct StateT * v2540 = slot_181(v2534);
  return v2540;
}

struct StateT * slot_203(struct StateT * v2856) {
  int v2857 = v2856->timer;
  int v2864 = v2857 + 1;
  v2856->timer = v2864;
  int * v2859 = v2856->regs;
  int v2860 = v2859[8];
  int v2867 = v2860 + 1;
  v2859[8] = v2867;
  struct StateT * v2862 = slot_204(v2856);
  return v2862;
}

struct StateT * slot_190(struct StateT * v2674) {
  int v2675 = v2674->timer;
  int v2682 = v2675 + 1;
  v2674->timer = v2682;
  int * v2677 = v2674->regs;
  int v2678 = v2677[8];
  int v2685 = v2678 + 1;
  v2677[8] = v2685;
  struct StateT * v2680 = slot_191(v2674);
  return v2680;
}

struct StateT * slot_157(struct StateT * v2212) {
  int v2213 = v2212->timer;
  int v2220 = v2213 + 1;
  v2212->timer = v2220;
  int * v2215 = v2212->regs;
  int v2216 = v2215[8];
  int v2223 = v2216 + 1;
  v2215[8] = v2223;
  struct StateT * v2218 = slot_158(v2212);
  return v2218;
}

struct StateT * slot_200(struct StateT * v2814) {
  int v2815 = v2814->timer;
  int v2822 = v2815 + 1;
  v2814->timer = v2822;
  int * v2817 = v2814->regs;
  int v2818 = v2817[8];
  int v2825 = v2818 + 1;
  v2817[8] = v2825;
  struct StateT * v2820 = slot_201(v2814);
  return v2820;
}

struct StateT * slot_173(struct StateT * v2436) {
  int v2437 = v2436->timer;
  int v2444 = v2437 + 1;
  v2436->timer = v2444;
  int * v2439 = v2436->regs;
  int v2440 = v2439[8];
  int v2447 = v2440 + 1;
  v2439[8] = v2447;
  struct StateT * v2442 = slot_174(v2436);
  return v2442;
}

struct StateT * slot_149(struct StateT * v2100) {
  int v2101 = v2100->timer;
  int v2108 = v2101 + 1;
  v2100->timer = v2108;
  int * v2103 = v2100->regs;
  int v2104 = v2103[8];
  int v2111 = v2104 + 1;
  v2103[8] = v2111;
  struct StateT * v2106 = slot_150(v2100);
  return v2106;
}

struct StateT * slot_5(struct StateT * v85) {
  int v86 = v85->timer;
  int v92 = v86 + 1;
  v85->timer = v92;
  int * v88 = v85->regs;
  v88[8] = 0;
  struct StateT * v90 = slot_6(v85);
  return v90;
}

struct StateT * slot_104(struct StateT * v1470) {
  int v1471 = v1470->timer;
  int v1478 = v1471 + 1;
  v1470->timer = v1478;
  int * v1473 = v1470->regs;
  int v1474 = v1473[8];
  int v1481 = v1474 + 1;
  v1473[8] = v1481;
  struct StateT * v1476 = slot_105(v1470);
  return v1476;
}

struct StateT * slot_54(struct StateT * v770) {
  int v771 = v770->timer;
  int v778 = v771 + 1;
  v770->timer = v778;
  int * v773 = v770->regs;
  int v774 = v773[8];
  int v781 = v774 + 1;
  v773[8] = v781;
  struct StateT * v776 = slot_55(v770);
  return v776;
}

struct StateT * slot_26(struct StateT * v378) {
  int v379 = v378->timer;
  int v386 = v379 + 1;
  v378->timer = v386;
  int * v381 = v378->regs;
  int v382 = v381[8];
  int v389 = v382 + 1;
  v381[8] = v389;
  struct StateT * v384 = slot_27(v378);
  return v384;
}

struct StateT * slot_206(struct StateT * v2898) {
  int v2899 = v2898->timer;
  int v2906 = v2899 + 1;
  v2898->timer = v2906;
  int * v2901 = v2898->regs;
  int v2902 = v2901[8];
  int v2909 = v2902 + 1;
  v2901[8] = v2909;
  struct StateT * v2904 = slot_207(v2898);
  return v2904;
}

struct StateT * slot_169(struct StateT * v2380) {
  int v2381 = v2380->timer;
  int v2388 = v2381 + 1;
  v2380->timer = v2388;
  int * v2383 = v2380->regs;
  int v2384 = v2383[8];
  int v2391 = v2384 + 1;
  v2383[8] = v2391;
  struct StateT * v2386 = slot_170(v2380);
  return v2386;
}

struct StateT * slot_64(struct StateT * v910) {
  int v911 = v910->timer;
  int v918 = v911 + 1;
  v910->timer = v918;
  int * v913 = v910->regs;
  int v914 = v913[8];
  int v921 = v914 + 1;
  v913[8] = v921;
  struct StateT * v916 = slot_65(v910);
  return v916;
}

struct StateT * slot_170(struct StateT * v2394) {
  int v2395 = v2394->timer;
  int v2402 = v2395 + 1;
  v2394->timer = v2402;
  int * v2397 = v2394->regs;
  int v2398 = v2397[8];
  int v2405 = v2398 + 1;
  v2397[8] = v2405;
  struct StateT * v2400 = slot_171(v2394);
  return v2400;
}

struct StateT * slot_14(struct StateT * v210) {
  int v211 = v210->timer;
  int v218 = v211 + 1;
  v210->timer = v218;
  int * v213 = v210->regs;
  int v214 = v213[8];
  int v221 = v214 + 1;
  v213[8] = v221;
  struct StateT * v216 = slot_15(v210);
  return v216;
}

struct StateT * slot_53(struct StateT * v756) {
  int v757 = v756->timer;
  int v764 = v757 + 1;
  v756->timer = v764;
  int * v759 = v756->regs;
  int v760 = v759[8];
  int v767 = v760 + 1;
  v759[8] = v767;
  struct StateT * v762 = slot_54(v756);
  return v762;
}

struct StateT * slot_80(struct StateT * v1134) {
  int v1135 = v1134->timer;
  int v1142 = v1135 + 1;
  v1134->timer = v1142;
  int * v1137 = v1134->regs;
  int v1138 = v1137[8];
  int v1145 = v1138 + 1;
  v1137[8] = v1145;
  struct StateT * v1140 = slot_81(v1134);
  return v1140;
}

struct StateT * slot_44(struct StateT * v630) {
  int v631 = v630->timer;
  int v638 = v631 + 1;
  v630->timer = v638;
  int * v633 = v630->regs;
  int v634 = v633[8];
  int v641 = v634 + 1;
  v633[8] = v641;
  struct StateT * v636 = slot_45(v630);
  return v636;
}

struct StateT * slot_137(struct StateT * v1932) {
  int v1933 = v1932->timer;
  int v1940 = v1933 + 1;
  v1932->timer = v1940;
  int * v1935 = v1932->regs;
  int v1936 = v1935[8];
  int v1943 = v1936 + 1;
  v1935[8] = v1943;
  struct StateT * v1938 = slot_138(v1932);
  return v1938;
}

struct StateT * slot_122(struct StateT * v1722) {
  int v1723 = v1722->timer;
  int v1730 = v1723 + 1;
  v1722->timer = v1730;
  int * v1725 = v1722->regs;
  int v1726 = v1725[8];
  int v1733 = v1726 + 1;
  v1725[8] = v1733;
  struct StateT * v1728 = slot_123(v1722);
  return v1728;
}

struct StateT * slot_99(struct StateT * v1400) {
  int v1401 = v1400->timer;
  int v1408 = v1401 + 1;
  v1400->timer = v1408;
  int * v1403 = v1400->regs;
  int v1404 = v1403[8];
  int v1411 = v1404 + 1;
  v1403[8] = v1411;
  struct StateT * v1406 = slot_100(v1400);
  return v1406;
}

struct StateT * slot_179(struct StateT * v2520) {
  int v2521 = v2520->timer;
  int v2528 = v2521 + 1;
  v2520->timer = v2528;
  int * v2523 = v2520->regs;
  int v2524 = v2523[8];
  int v2531 = v2524 + 1;
  v2523[8] = v2531;
  struct StateT * v2526 = slot_180(v2520);
  return v2526;
}

struct StateT * slot_219(struct StateT * v3080) {
  int v3081 = v3080->timer;
  int v3088 = v3081 + 1;
  v3080->timer = v3088;
  int * v3083 = v3080->regs;
  int v3084 = v3083[8];
  int v3091 = v3084 + 1;
  v3083[8] = v3091;
  struct StateT * v3086 = slot_220(v3080);
  return v3086;
}

struct StateT * slot_36(struct StateT * v518) {
  int v519 = v518->timer;
  int v526 = v519 + 1;
  v518->timer = v526;
  int * v521 = v518->regs;
  int v522 = v521[8];
  int v529 = v522 + 1;
  v521[8] = v529;
  struct StateT * v524 = slot_37(v518);
  return v524;
}

struct StateT * slot_57(struct StateT * v812) {
  int v813 = v812->timer;
  int v820 = v813 + 1;
  v812->timer = v820;
  int * v815 = v812->regs;
  int v816 = v815[8];
  int v823 = v816 + 1;
  v815[8] = v823;
  struct StateT * v818 = slot_58(v812);
  return v818;
}

struct StateT * slot_62(struct StateT * v882) {
  int v883 = v882->timer;
  int v890 = v883 + 1;
  v882->timer = v890;
  int * v885 = v882->regs;
  int v886 = v885[8];
  int v893 = v886 + 1;
  v885[8] = v893;
  struct StateT * v888 = slot_63(v882);
  return v888;
}

struct StateT * slot_22(struct StateT * v322) {
  int v323 = v322->timer;
  int v330 = v323 + 1;
  v322->timer = v330;
  int * v325 = v322->regs;
  int v326 = v325[8];
  int v333 = v326 + 1;
  v325[8] = v333;
  struct StateT * v328 = slot_23(v322);
  return v328;
}

struct StateT * slot_139(struct StateT * v1960) {
  int v1961 = v1960->timer;
  int v1968 = v1961 + 1;
  v1960->timer = v1968;
  int * v1963 = v1960->regs;
  int v1964 = v1963[8];
  int v1971 = v1964 + 1;
  v1963[8] = v1971;
  struct StateT * v1966 = slot_140(v1960);
  return v1966;
}

struct StateT * slot_221(struct StateT * v3108) {
  int v3109 = v3108->timer;
  int v3116 = v3109 + 1;
  v3108->timer = v3116;
  int * v3111 = v3108->regs;
  int v3112 = v3111[8];
  int v3119 = v3112 + 1;
  v3111[8] = v3119;
  struct StateT * v3114 = slot_222(v3108);
  return v3114;
}

struct StateT * slot_23(struct StateT * v336) {
  int v337 = v336->timer;
  int v344 = v337 + 1;
  v336->timer = v344;
  int * v339 = v336->regs;
  int v340 = v339[8];
  int v347 = v340 + 1;
  v339[8] = v347;
  struct StateT * v342 = slot_24(v336);
  return v342;
}

struct StateT * slot_153(struct StateT * v2156) {
  int v2157 = v2156->timer;
  int v2164 = v2157 + 1;
  v2156->timer = v2164;
  int * v2159 = v2156->regs;
  int v2160 = v2159[8];
  int v2167 = v2160 + 1;
  v2159[8] = v2167;
  struct StateT * v2162 = slot_154(v2156);
  return v2162;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v46 = v39 + 1;
  v38->timer = v46;
  int * v41 = v38->regs;
  int v42 = v41[6];
  int v49 = v42 & 7;
  v41[6] = v49;
  struct StateT * v44 = slot_3(v38);
  return v44;
}

struct StateT * slot_86(struct StateT * v1218) {
  int v1219 = v1218->timer;
  int v1226 = v1219 + 1;
  v1218->timer = v1226;
  int * v1221 = v1218->regs;
  int v1222 = v1221[8];
  int v1229 = v1222 + 1;
  v1221[8] = v1229;
  struct StateT * v1224 = slot_87(v1218);
  return v1224;
}

struct StateT * slot_129(struct StateT * v1820) {
  int v1821 = v1820->timer;
  int v1828 = v1821 + 1;
  v1820->timer = v1828;
  int * v1823 = v1820->regs;
  int v1824 = v1823[8];
  int v1831 = v1824 + 1;
  v1823[8] = v1831;
  struct StateT * v1826 = slot_130(v1820);
  return v1826;
}

struct StateT * slot_158(struct StateT * v2226) {
  int v2227 = v2226->timer;
  int v2234 = v2227 + 1;
  v2226->timer = v2234;
  int * v2229 = v2226->regs;
  int v2230 = v2229[8];
  int v2237 = v2230 + 1;
  v2229[8] = v2237;
  struct StateT * v2232 = slot_159(v2226);
  return v2232;
}

struct StateT * slot_100(struct StateT * v1414) {
  int v1415 = v1414->timer;
  int v1422 = v1415 + 1;
  v1414->timer = v1422;
  int * v1417 = v1414->regs;
  int v1418 = v1417[8];
  int v1425 = v1418 + 1;
  v1417[8] = v1425;
  struct StateT * v1420 = slot_101(v1414);
  return v1420;
}

struct StateT * slot_127(struct StateT * v1792) {
  int v1793 = v1792->timer;
  int v1800 = v1793 + 1;
  v1792->timer = v1800;
  int * v1795 = v1792->regs;
  int v1796 = v1795[8];
  int v1803 = v1796 + 1;
  v1795[8] = v1803;
  struct StateT * v1798 = slot_128(v1792);
  return v1798;
}

struct StateT * slot_217(struct StateT * v3052) {
  int v3053 = v3052->timer;
  int v3060 = v3053 + 1;
  v3052->timer = v3060;
  int * v3055 = v3052->regs;
  int v3056 = v3055[8];
  int v3063 = v3056 + 1;
  v3055[8] = v3063;
  struct StateT * v3058 = slot_218(v3052);
  return v3058;
}

struct StateT * slot_13(struct StateT * v196) {
  int v197 = v196->timer;
  int v204 = v197 + 1;
  v196->timer = v204;
  int * v199 = v196->regs;
  int v200 = v199[8];
  int v207 = v200 + 1;
  v199[8] = v207;
  struct StateT * v202 = slot_14(v196);
  return v202;
}

struct StateT * slot_111(struct StateT * v1568) {
  int v1569 = v1568->timer;
  int v1576 = v1569 + 1;
  v1568->timer = v1576;
  int * v1571 = v1568->regs;
  int v1572 = v1571[8];
  int v1579 = v1572 + 1;
  v1571[8] = v1579;
  struct StateT * v1574 = slot_112(v1568);
  return v1574;
}

struct StateT * slot_109(struct StateT * v1540) {
  int v1541 = v1540->timer;
  int v1548 = v1541 + 1;
  v1540->timer = v1548;
  int * v1543 = v1540->regs;
  int v1544 = v1543[8];
  int v1551 = v1544 + 1;
  v1543[8] = v1551;
  struct StateT * v1546 = slot_110(v1540);
  return v1546;
}

struct StateT * slot_174(struct StateT * v2450) {
  int v2451 = v2450->timer;
  int v2458 = v2451 + 1;
  v2450->timer = v2458;
  int * v2453 = v2450->regs;
  int v2454 = v2453[8];
  int v2461 = v2454 + 1;
  v2453[8] = v2461;
  struct StateT * v2456 = slot_175(v2450);
  return v2456;
}

struct StateT * slot_147(struct StateT * v2072) {
  int v2073 = v2072->timer;
  int v2080 = v2073 + 1;
  v2072->timer = v2080;
  int * v2075 = v2072->regs;
  int v2076 = v2075[8];
  int v2083 = v2076 + 1;
  v2075[8] = v2083;
  struct StateT * v2078 = slot_148(v2072);
  return v2078;
}

struct StateT * slot_42(struct StateT * v602) {
  int v603 = v602->timer;
  int v610 = v603 + 1;
  v602->timer = v610;
  int * v605 = v602->regs;
  int v606 = v605[8];
  int v613 = v606 + 1;
  v605[8] = v613;
  struct StateT * v608 = slot_43(v602);
  return v608;
}

struct StateT * slot_224(struct StateT * v3150) {
  int v3151 = v3150->timer;
  int v3158 = v3151 + 1;
  v3150->timer = v3158;
  int * v3153 = v3150->regs;
  int v3154 = v3153[8];
  int v3161 = v3154 + 1;
  v3153[8] = v3161;
  struct StateT * v3156 = slot_225(v3150);
  return v3156;
}

struct StateT * slot_163(struct StateT * v2296) {
  int v2297 = v2296->timer;
  int v2304 = v2297 + 1;
  v2296->timer = v2304;
  int * v2299 = v2296->regs;
  int v2300 = v2299[8];
  int v2307 = v2300 + 1;
  v2299[8] = v2307;
  struct StateT * v2302 = slot_164(v2296);
  return v2302;
}

struct StateT * slot_184(struct StateT * v2590) {
  int v2591 = v2590->timer;
  int v2598 = v2591 + 1;
  v2590->timer = v2598;
  int * v2593 = v2590->regs;
  int v2594 = v2593[8];
  int v2601 = v2594 + 1;
  v2593[8] = v2601;
  struct StateT * v2596 = slot_185(v2590);
  return v2596;
}

struct StateT * slot_204(struct StateT * v2870) {
  int v2871 = v2870->timer;
  int v2878 = v2871 + 1;
  v2870->timer = v2878;
  int * v2873 = v2870->regs;
  int v2874 = v2873[8];
  int v2881 = v2874 + 1;
  v2873[8] = v2881;
  struct StateT * v2876 = slot_205(v2870);
  return v2876;
}

struct StateT * slot_194(struct StateT * v2730) {
  int v2731 = v2730->timer;
  int v2738 = v2731 + 1;
  v2730->timer = v2738;
  int * v2733 = v2730->regs;
  int v2734 = v2733[8];
  int v2741 = v2734 + 1;
  v2733[8] = v2741;
  struct StateT * v2736 = slot_195(v2730);
  return v2736;
}

struct StateT * slot_165(struct StateT * v2324) {
  int v2325 = v2324->timer;
  int v2332 = v2325 + 1;
  v2324->timer = v2332;
  int * v2327 = v2324->regs;
  int v2328 = v2327[8];
  int v2335 = v2328 + 1;
  v2327[8] = v2335;
  struct StateT * v2330 = slot_166(v2324);
  return v2330;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v1652) {
  int v1653 = v1652->timer;
  int v1660 = v1653 + 1;
  v1652->timer = v1660;
  int * v1655 = v1652->regs;
  int v1656 = v1655[8];
  int v1663 = v1656 + 1;
  v1655[8] = v1663;
  struct StateT * v1658 = slot_118(v1652);
  return v1658;
}

struct StateT * slot_90(struct StateT * v1274) {
  int v1275 = v1274->timer;
  int v1282 = v1275 + 1;
  v1274->timer = v1282;
  int * v1277 = v1274->regs;
  int v1278 = v1277[8];
  int v1285 = v1278 + 1;
  v1277[8] = v1285;
  struct StateT * v1280 = slot_91(v1274);
  return v1280;
}

struct StateT * slot_11(struct StateT * v168) {
  int v169 = v168->timer;
  int v176 = v169 + 1;
  v168->timer = v176;
  int * v171 = v168->regs;
  int v172 = v171[8];
  int v179 = v172 + 1;
  v171[8] = v179;
  struct StateT * v174 = slot_12(v168);
  return v174;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
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