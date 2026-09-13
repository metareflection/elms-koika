// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

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

struct StateT * v729(struct StateT * v730);
struct StateT * v457(struct StateT * v458);
struct StateT * v2326(struct StateT * v2327);
struct StateT * v641(struct StateT * v642);
struct StateT * v2132(struct StateT * v2133);
struct StateT * v3172(struct StateT * v3173);
struct StateT * v969(struct StateT * v970);
struct StateT * v1059(struct StateT * v1060);
struct StateT * v595(struct StateT * v596);
struct StateT * v979(struct StateT * v980);
struct StateT * v1840(struct StateT * v1841);
struct StateT * v661(struct StateT * v662);
struct StateT * v473(struct StateT * v474);
struct StateT * v2988(struct StateT * v2989);
struct StateT * v1866(struct StateT * v1867);
struct StateT * v165(struct StateT * v166);
struct StateT * v1910(struct StateT * v1911);
struct StateT * v1019(struct StateT * v1020);
struct StateT * v3006(struct StateT * v3007);
struct StateT * v3198(struct StateT * v3199);
struct StateT * v2490(struct StateT * v2491);
struct StateT * v2008(struct StateT * v2009);
struct StateT * v739(struct StateT * v740);
struct StateT * v347(struct StateT * v348);
struct StateT * v2694(struct StateT * v2695);
struct StateT * v2744(struct StateT * v2745);
struct StateT * v909(struct StateT * v910);
struct StateT * v3092(struct StateT * v3093);
struct StateT * v2594(struct StateT * v2595);
struct StateT * v1009(struct StateT * v1010);
struct StateT * v2812(struct StateT * v2813);
struct StateT * v2366(struct StateT * v2367);
struct StateT * v2822(struct StateT * v2823);
struct StateT * v307(struct StateT * v308);
struct StateT * v2576(struct StateT * v2577);
struct StateT * v799(struct StateT * v800);
struct StateT * v519(struct StateT * v520);
struct StateT * v769(struct StateT * v770);
struct StateT * v779(struct StateT * v780);
struct StateT * v2654(struct StateT * v2655);
struct StateT * v919(struct StateT * v920);
struct StateT * v2560(struct StateT * v2561);
struct StateT * v2908(struct StateT * v2909);
struct StateT * v3190(struct StateT * v3191);
struct StateT * v489(struct StateT * v490);
struct StateT * v509(struct StateT * v510);
struct StateT * v2402(struct StateT * v2403);
struct StateT * v2638(struct StateT * v2639);
struct StateT * v819(struct StateT * v820);
struct StateT * v2234(struct StateT * v2235);
struct StateT * v929(struct StateT * v930);
struct StateT * v2278(struct StateT * v2279);
struct StateT * v145(struct StateT * v146);
struct StateT * v2752(struct StateT * v2753);
struct StateT * v449(struct StateT * v450);
struct StateT * v2208(struct StateT * v2209);
struct StateT * v621(struct StateT * v622);
struct StateT * v2568(struct StateT * v2569);
struct StateT * v899(struct StateT * v900);
struct StateT * v397(struct StateT * v398);
struct StateT * v3236(struct StateT * v3237);
struct StateT * v1814(struct StateT * v1815);
struct StateT * v215(struct StateT * v216);
struct StateT * v39(struct StateT * v40);
struct StateT * v245(struct StateT * v246);
struct StateT * v195(struct StateT * v196);
struct StateT * v611(struct StateT * v612);
struct StateT * v2392(struct StateT * v2393);
struct StateT * v869(struct StateT * v870);
struct StateT * v463(struct StateT * v464);
struct StateT * v283(struct StateT * v284);
struct StateT * v2602(struct StateT * v2603);
struct StateT * v3082(struct StateT * v3083);
struct StateT * v2122(struct StateT * v2123);
struct StateT * v2586(struct StateT * v2587);
struct StateT * v2970(struct StateT * v2971);
struct StateT * v829(struct StateT * v830);
struct StateT * v697(struct StateT * v698);
struct StateT * v2016(struct StateT * v2017);
struct StateT * v2296(struct StateT * v2297);
struct StateT * v337(struct StateT * v338);
struct StateT * v313(struct StateT * v314);
struct StateT * v949(struct StateT * v950);
struct StateT * v989(struct StateT * v990);
struct StateT * v2962(struct StateT * v2963);
struct StateT * v1876(struct StateT * v1877);
struct StateT * v1804(struct StateT * v1805);
struct StateT * v2102(struct StateT * v2103);
struct StateT * v3112(struct StateT * v3113);
struct StateT * v2076(struct StateT * v2077);
struct StateT * v2286(struct StateT * v2287);
struct StateT * v2848(struct StateT * v2849);
struct StateT * v225(struct StateT * v226);
struct StateT * v59(struct StateT * v60);
struct StateT * v3102(struct StateT * v3103);
struct StateT * v2260(struct StateT * v2261);
struct StateT * v1794(struct StateT * v1795);
struct StateT * v2838(struct StateT * v2839);
struct StateT * v1902(struct StateT * v1903);
struct StateT * v525(struct StateT * v526);
struct StateT * v1892(struct StateT * v1893);
struct StateT * v939(struct StateT * v940);
struct StateT * v2550(struct StateT * v2551);
struct StateT * v2786(struct StateT * v2787);
struct StateT * v605(struct StateT * v606);
struct StateT * v2444(struct StateT * v2445);
struct StateT * v69(struct StateT * v70);
struct StateT * v859(struct StateT * v860);
struct StateT * v2462(struct StateT * v2463);
struct StateT * v1884(struct StateT * v1885);
struct StateT * v1824(struct StateT * v1825);
struct StateT * v99(struct StateT * v100);
struct StateT * v3256(struct StateT * v3257);
struct StateT * v839(struct StateT * v840);
struct StateT * v291(struct StateT * v292);
struct StateT * v2646(struct StateT * v2647);
struct StateT * v1948(struct StateT * v1949);
struct StateT * v1988(struct StateT * v1989);
struct StateT * v2778(struct StateT * v2779);
struct StateT * v2868(struct StateT * v2869);
struct StateT * v2804(struct StateT * v2805);
struct StateT * v585(struct StateT * v586);
struct StateT * v2060(struct StateT * v2061);
struct StateT * v3246(struct StateT * v3247);
struct StateT * v3128(struct StateT * v3129);
struct StateT * v483(struct StateT * v484);
struct StateT * v749(struct StateT * v750);
struct StateT * v2410(struct StateT * v2411);
struct StateT * v631(struct StateT * v632);
struct StateT * v2996(struct StateT * v2997);
struct StateT * v3120(struct StateT * v3121);
struct StateT * v321(struct StateT * v322);
struct StateT * v2480(struct StateT * v2481);
struct StateT * v1029(struct StateT * v1030);
struct StateT * v2428(struct StateT * v2429);
struct StateT * v2470(struct StateT * v2471);
struct StateT * v2954(struct StateT * v2955);
struct StateT * v1938(struct StateT * v1939);
struct StateT * v2620(struct StateT * v2621);
struct StateT * v29(struct StateT * v30);
struct StateT * v89(struct StateT * v90);
struct StateT * v2724(struct StateT * v2725);
struct StateT * v2376(struct StateT * v2377);
struct StateT * v3138(struct StateT * v3139);
struct StateT * v2918(struct StateT * v2919);
struct StateT * v705(struct StateT * v706);
struct StateT * v2628(struct StateT * v2629);
struct StateT * v2306(struct StateT * v2307);
struct StateT * v2142(struct StateT * v2143);
struct StateT * v79(struct StateT * v80);
struct StateT * v879(struct StateT * v880);
struct StateT * v2684(struct StateT * v2685);
struct StateT * v2172(struct StateT * v2173);
struct StateT * v721(struct StateT * v722);
struct StateT * v265(struct StateT * v266);
struct StateT * v2928(struct StateT * v2929);
struct StateT * v299(struct StateT * v300);
struct StateT * v2714(struct StateT * v2715);
struct StateT * v2218(struct StateT * v2219);
struct StateT * v713(struct StateT * v714);
struct StateT * v1049(struct StateT * v1050);
struct StateT * v2612(struct StateT * v2613);
struct StateT * v2796(struct StateT * v2797);
struct StateT * v271(struct StateT * v272);
struct StateT * v1067(struct StateT * v1068);
struct StateT * v19(struct StateT * v20);
struct StateT * v535(struct StateT * v536);
struct StateT * v2034(struct StateT * v2035);
struct StateT * v109(struct StateT * v110);
struct StateT * v2436(struct StateT * v2437);
struct StateT * v387(struct StateT * v388);
struct StateT * v2770(struct StateT * v2771);
struct StateT * v1958(struct StateT * v1959);
struct StateT * v691(struct StateT * v692);
struct StateT * v3014(struct StateT * v3015);
struct StateT * v3052(struct StateT * v3053);
struct StateT * v2936(struct StateT * v2937);
struct StateT * v3072(struct StateT * v3073);
struct StateT * v959(struct StateT * v960);
struct StateT * v1039(struct StateT * v1040);
struct StateT * v2050(struct StateT * v2051);
struct StateT * v1968(struct StateT * v1969);
struct StateT * v49(struct StateT * v50);
struct StateT * v1832(struct StateT * v1833);
struct StateT * v2540(struct StateT * v2541);
struct StateT * v1998(struct StateT * v1999);
struct StateT * v357(struct StateT * v358);
struct StateT * v175(struct StateT * v176);
struct StateT * v2042(struct StateT * v2043);
struct StateT * v255(struct StateT * v256);
struct StateT * v2182(struct StateT * v2183);
struct StateT * v2520(struct StateT * v2521);
struct StateT * v205(struct StateT * v206);
struct StateT * v423(struct StateT * v424);
struct StateT * v2530(struct StateT * v2531);
struct StateT * v377(struct StateT * v378);
struct StateT * v2980(struct StateT * v2981);
struct StateT * v681(struct StateT * v682);
struct StateT * v3206(struct StateT * v3207);
struct StateT * v759(struct StateT * v760);
struct StateT * v2094(struct StateT * v2095);
struct StateT * v2316(struct StateT * v2317);
struct StateT * v367(struct StateT * v368);
struct StateT * v185(struct StateT * v186);
struct StateT * v2858(struct StateT * v2859);
struct StateT * v415(struct StateT * v416);
struct StateT * v671(struct StateT * v672);
struct StateT * v2888(struct StateT * v2889);
struct StateT * v2086(struct StateT * v2087);
struct StateT * v2500(struct StateT * v2501);
struct StateT * v2226(struct StateT * v2227);
struct StateT * v9(struct StateT * v10);
struct StateT * v235(struct StateT * v236);
struct StateT * v2200(struct StateT * v2201);
struct StateT * v575(struct StateT * v576);
struct StateT * v139(struct StateT * v140);
struct StateT * v789(struct StateT * v790);
struct StateT * v3180(struct StateT * v3181);
struct StateT * v1918(struct StateT * v1919);
struct StateT * v2336(struct StateT * v2337);
struct StateT * v407(struct StateT * v408);
struct StateT * v2068(struct StateT * v2069);
struct StateT * v277(struct StateT * v278);
struct StateT * v2270(struct StateT * v2271);
struct StateT * v431(struct StateT * v432);
struct StateT * v2898(struct StateT * v2899);
struct StateT * v499(struct StateT * v500);
struct StateT * v2674(struct StateT * v2675);
struct StateT * v2760(struct StateT * v2761);
struct StateT * v2162(struct StateT * v2163);
struct StateT * v1978(struct StateT * v1979);
struct StateT * v2878(struct StateT * v2879);
struct StateT * v3154(struct StateT * v3155);
struct StateT * v1850(struct StateT * v1851);
struct StateT * v2252(struct StateT * v2253);
struct StateT * v3042(struct StateT * v3043);
struct StateT * v2454(struct StateT * v2455);
struct StateT * v3264(struct StateT * v3265);
struct StateT * v129(struct StateT * v130);
struct StateT * v3216(struct StateT * v3217);
struct StateT * v2384(struct StateT * v2385);
struct StateT * v3022(struct StateT * v3023);
struct StateT * v999(struct StateT * v1000);
struct StateT * v439(struct StateT * v440);
struct StateT * v3226(struct StateT * v3227);
struct StateT * v565(struct StateT * v566);
struct StateT * v809(struct StateT * v810);
struct StateT * v889(struct StateT * v890);
struct StateT * v545(struct StateT * v546);
struct StateT * v3164(struct StateT * v3165);
struct StateT * v2192(struct StateT * v2193);
struct StateT * v2734(struct StateT * v2735);
struct StateT * v3062(struct StateT * v3063);
struct StateT * v2152(struct StateT * v2153);
struct StateT * v2664(struct StateT * v2665);
struct StateT * v1858(struct StateT * v1859);
struct StateT * v2356(struct StateT * v2357);
struct StateT * v2944(struct StateT * v2945);
struct StateT * v651(struct StateT * v652);
struct StateT * v2112(struct StateT * v2113);
struct StateT * v119(struct StateT * v120);
struct StateT * v2418(struct StateT * v2419);
struct StateT * v155(struct StateT * v156);
struct StateT * v3146(struct StateT * v3147);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v2024(struct StateT * v2025);
struct StateT * v2704(struct StateT * v2705);
struct StateT * v2244(struct StateT * v2245);
struct StateT * v1784(struct StateT * v1785);
struct StateT * v327(struct StateT * v328);
struct StateT * v3032(struct StateT * v3033);
struct StateT * v2510(struct StateT * v2511);
struct StateT * v2346(struct StateT * v2347);
struct StateT * v1928(struct StateT * v1929);
struct StateT * v2830(struct StateT * v2831);
struct StateT * v555(struct StateT * v556);
struct StateT * v849(struct StateT * v850);
struct StateT * v729(struct StateT * v730) {
  int v731 = v730->timer;
  int v1465 = v731 + 1;
  v730->timer = v1465;
  int * v733 = v730->regs;
  int v734 = v733[21];
  int * v735 = v730->regs;
  int v736 = v735[15];
  int * v737 = v730->regs;
  int v1471 = v734 + v736;
  v737[15] = v1471;
  struct StateT * v1463 = v739(v730);
  return v1463;
}

struct StateT * v457(struct StateT * v458) {
  int v459 = v458->timer;
  int v5009 = v459 + 1;
  v458->timer = v5009;
  int * v461 = v458->regs;
  int v462 = v461[31];
  bool v5012 = (v462 ^ -2147483648) < -2147483648;
  struct StateT * v5007;
  if (v5012) {
    struct StateT * v1782 = v463(v458);
    v5007 = v1782;
  } else {
    struct StateT * v5005 = v1784(v458);
    v5007 = v5005;
  }
  return v5007;
}

struct StateT * v2326(struct StateT * v2327) {
  int v2328 = v2327->timer;
  int v4367 = v2328 + 1;
  v2327->timer = v4367;
  int * v2330 = v2327->regs;
  int v2331 = v2330[17];
  int * v2332 = v2327->regs;
  int v2333 = v2332[6];
  int * v2334 = v2327->regs;
  int v4374 = v2331 ^ v2333;
  v2334[8] = v4374;
  struct StateT * v4365 = v2336(v2327);
  return v4365;
}

struct StateT * v641(struct StateT * v642) {
  int v643 = v642->timer;
  int v1566 = v643 + 1;
  v642->timer = v1566;
  int * v645 = v642->regs;
  int v646 = v645[16];
  int * v647 = v642->regs;
  int v648 = v647[30];
  int * v649 = v642->regs;
  int v1572 = v646 + v648;
  v649[16] = v1572;
  struct StateT * v1564 = v651(v642);
  return v1564;
}

struct StateT * v2132(struct StateT * v2133) {
  int v2134 = v2133->timer;
  int v4594 = v2134 + 1;
  v2133->timer = v4594;
  int * v2136 = v2133->regs;
  int v2137 = v2136[27];
  int * v2138 = v2133->regs;
  int v2139 = v2138[9];
  int * v2140 = v2133->regs;
  int v4600 = v2137 ^ v2139;
  v2140[27] = v4600;
  struct StateT * v4592 = v2142(v2133);
  return v4592;
}

struct StateT * v3172(struct StateT * v3173) {
  int v3174 = v3173->timer;
  int v3387 = v3174 + 1;
  v3173->timer = v3387;
  int * v3176 = v3173->regs;
  int v3177 = v3176[6];
  int * v3178 = v3173->regs;
  int v3391 = v3177 << 18;
  v3178[6] = v3391;
  struct StateT * v3385 = v3180(v3173);
  return v3385;
}

struct StateT * v969(struct StateT * v970) {
  int v971 = v970->timer;
  int v1180 = v971 + 1;
  v970->timer = v1180;
  int * v973 = v970->regs;
  int v974 = v973[2];
  int * v975 = v970->mem;
  int v1184 = (int)((unsigned int)(v974 + 76) >> 2);
  int v976 = v975[v1184];
  int * v977 = v970->regs;
  v977[19] = v976;
  struct StateT * v1178 = v979(v970);
  return v1178;
}

struct StateT * v1059(struct StateT * v1060) {
  int v1061 = v1060->timer;
  int v1075 = v1061 + 1;
  v1060->timer = v1075;
  int * v1063 = v1060->regs;
  int v1064 = v1063[2];
  int * v1065 = v1060->regs;
  int v1079 = v1064 + 96;
  v1065[2] = v1079;
  struct StateT * v1073 = v1067(v1060);
  return v1073;
}

struct StateT * v595(struct StateT * v596) {
  int v597 = v596->timer;
  int v1620 = v597 + 1;
  v596->timer = v1620;
  int * v599 = v596->regs;
  int v600 = v599[13];
  int * v601 = v596->regs;
  int v602 = v601[7];
  int * v603 = v596->regs;
  int v1626 = v600 + v602;
  v603[13] = v1626;
  struct StateT * v1618 = v605(v596);
  return v1618;
}

struct StateT * v979(struct StateT * v980) {
  int v981 = v980->timer;
  int v1168 = v981 + 1;
  v980->timer = v1168;
  int * v983 = v980->regs;
  int v984 = v983[2];
  int * v985 = v980->mem;
  int v1172 = (int)((unsigned int)(v984 + 72) >> 2);
  int v986 = v985[v1172];
  int * v987 = v980->regs;
  v987[20] = v986;
  struct StateT * v1166 = v989(v980);
  return v1166;
}

struct StateT * v1840(struct StateT * v1841) {
  int v1842 = v1841->timer;
  int v4929 = v1842 + 1;
  v1841->timer = v4929;
  int * v1844 = v1841->regs;
  int v1845 = v1844[15];
  int * v1846 = v1841->regs;
  int v1847 = v1846[9];
  int * v1848 = v1841->regs;
  int v4935 = v1845 | v1847;
  v1848[15] = v4935;
  struct StateT * v4927 = v1850(v1841);
  return v4927;
}

struct StateT * v661(struct StateT * v662) {
  int v663 = v662->timer;
  int v1543 = v663 + 1;
  v662->timer = v1543;
  int * v665 = v662->regs;
  int v666 = v665[24];
  int * v667 = v662->regs;
  int v668 = v667[30];
  int * v669 = v662->regs;
  int v1549 = v666 + v668;
  v669[24] = v1549;
  struct StateT * v1541 = v671(v662);
  return v1541;
}

struct StateT * v473(struct StateT * v474) {
  int v475 = v474->timer;
  int v1762 = v475 + 1;
  v474->timer = v1762;
  int * v477 = v474->regs;
  int v478 = v477[27];
  int * v479 = v474->regs;
  int v480 = v479[28];
  int * v481 = v474->regs;
  int v1768 = v478 + v480;
  v481[28] = v1768;
  struct StateT * v1760 = v483(v474);
  return v1760;
}

struct StateT * v2988(struct StateT * v2989) {
  int v2990 = v2989->timer;
  int v3599 = v2990 + 1;
  v2989->timer = v3599;
  int * v2992 = v2989->regs;
  int v2993 = v2992[6];
  int * v2994 = v2989->regs;
  int v3603 = v2993 << 13;
  v2994[6] = v3603;
  struct StateT * v3597 = v2996(v2989);
  return v3597;
}

struct StateT * v1866(struct StateT * v1867) {
  int v1868 = v1867->timer;
  int v4899 = v1868 + 1;
  v1867->timer = v4899;
  int * v1870 = v1867->regs;
  int v1871 = v1870[20];
  int * v1872 = v1867->regs;
  int v1873 = v1872[9];
  int * v1874 = v1867->regs;
  int v4905 = v1871 | v1873;
  v1874[9] = v4905;
  struct StateT * v4897 = v1876(v1867);
  return v4897;
}

struct StateT * v165(struct StateT * v166) {
  int v167 = v166->timer;
  int v5365 = v167 + 1;
  v166->timer = v5365;
  int * v169 = v166->regs;
  int v170 = v169[12];
  int * v171 = v166->mem;
  int v5369 = (int)((unsigned int)(v170 + 8) >> 2);
  int v172 = v171[v5369];
  int * v173 = v166->regs;
  v173[7] = v172;
  struct StateT * v5363 = v175(v166);
  return v5363;
}

struct StateT * v1910(struct StateT * v1911) {
  int v1912 = v1911->timer;
  int v4850 = v1912 + 1;
  v1911->timer = v4850;
  int * v1914 = v1911->regs;
  int v1915 = v1914[8];
  int * v1916 = v1911->regs;
  int v4854 = v1915 << 7;
  v1916[8] = v4854;
  struct StateT * v4848 = v1918(v1911);
  return v4848;
}

struct StateT * v1019(struct StateT * v1020) {
  int v1021 = v1020->timer;
  int v1120 = v1021 + 1;
  v1020->timer = v1120;
  int * v1023 = v1020->regs;
  int v1024 = v1023[2];
  int * v1025 = v1020->mem;
  int v1124 = (int)((unsigned int)(v1024 + 56) >> 2);
  int v1026 = v1025[v1124];
  int * v1027 = v1020->regs;
  v1027[24] = v1026;
  struct StateT * v1118 = v1029(v1020);
  return v1118;
}

struct StateT * v3006(struct StateT * v3007) {
  int v3008 = v3007->timer;
  int v3578 = v3008 + 1;
  v3007->timer = v3578;
  int * v3010 = v3007->regs;
  int v3011 = v3010[8];
  int * v3012 = v3007->regs;
  int v3583 = (int)((unsigned int)v3011 >> 19);
  v3012[9] = v3583;
  struct StateT * v3576 = v3014(v3007);
  return v3576;
}

struct StateT * v3198(struct StateT * v3199) {
  int v3200 = v3199->timer;
  int v3357 = v3200 + 1;
  v3199->timer = v3357;
  int * v3202 = v3199->regs;
  int v3203 = v3202[8];
  int * v3204 = v3199->regs;
  int v3361 = v3203 << 18;
  v3204[8] = v3361;
  struct StateT * v3355 = v3206(v3199);
  return v3355;
}

struct StateT * v2490(struct StateT * v2491) {
  int v2492 = v2491->timer;
  int v4176 = v2492 + 1;
  v2491->timer = v4176;
  int * v2494 = v2491->regs;
  int v2495 = v2494[11];
  int * v2496 = v2491->regs;
  int v2497 = v2496[16];
  int * v2498 = v2491->regs;
  int v4183 = v2495 ^ v2497;
  v2498[20] = v4183;
  struct StateT * v4174 = v2500(v2491);
  return v4174;
}

struct StateT * v2008(struct StateT * v2009) {
  int v2010 = v2009->timer;
  int v4737 = v2010 + 1;
  v2009->timer = v4737;
  int * v2012 = v2009->regs;
  int v2013 = v2012[15];
  int * v2014 = v2009->regs;
  int v4742 = (int)((unsigned int)v2013 >> 23);
  v2014[20] = v4742;
  struct StateT * v4735 = v2016(v2009);
  return v4735;
}

struct StateT * v739(struct StateT * v740) {
  int v741 = v740->timer;
  int v1454 = v741 + 1;
  v740->timer = v1454;
  int * v743 = v740->regs;
  int v744 = v743[11];
  int * v745 = v740->regs;
  int v746 = v745[6];
  int * v747 = v740->regs;
  int v1460 = v744 + v746;
  v747[11] = v1460;
  struct StateT * v1452 = v749(v740);
  return v1452;
}

struct StateT * v347(struct StateT * v348) {
  int v349 = v348->timer;
  int v5142 = v349 + 1;
  v348->timer = v5142;
  int * v351 = v348->regs;
  int v352 = v351[2];
  int * v353 = v348->regs;
  int v354 = v353[5];
  int * v355 = v348->mem;
  int v5148 = (int)((unsigned int)(v352 + 12) >> 2);
  v355[v5148] = v354;
  struct StateT * v5140 = v357(v348);
  return v5140;
}

struct StateT * v2694(struct StateT * v2695) {
  int v2696 = v2695->timer;
  int v3938 = v2696 + 1;
  v2695->timer = v3938;
  int * v2698 = v2695->regs;
  int v2699 = v2698[9];
  int * v2700 = v2695->regs;
  int v2701 = v2700[6];
  int * v2702 = v2695->regs;
  int v3945 = v2699 ^ v2701;
  v2702[16] = v3945;
  struct StateT * v3936 = v2704(v2695);
  return v3936;
}

struct StateT * v2744(struct StateT * v2745) {
  int v2746 = v2745->timer;
  int v3880 = v2746 + 1;
  v2745->timer = v3880;
  int * v2748 = v2745->regs;
  int v2749 = v2748[11];
  int * v2750 = v2745->regs;
  int v3885 = (int)((unsigned int)v2749 >> 23);
  v2750[9] = v3885;
  struct StateT * v3878 = v2752(v2745);
  return v3878;
}

struct StateT * v909(struct StateT * v910) {
  int v911 = v910->timer;
  int v1252 = v911 + 1;
  v910->timer = v1252;
  int * v913 = v910->regs;
  int v914 = v913[10];
  int * v915 = v910->regs;
  int v916 = v915[1];
  int * v917 = v910->mem;
  int v1258 = (int)((unsigned int)(v914 + 56) >> 2);
  v917[v1258] = v916;
  struct StateT * v1250 = v919(v910);
  return v1250;
}

struct StateT * v3092(struct StateT * v3093) {
  int v3094 = v3093->timer;
  int v3478 = v3094 + 1;
  v3093->timer = v3478;
  int * v3096 = v3093->regs;
  int v3097 = v3096[13];
  int * v3098 = v3093->regs;
  int v3099 = v3098[26];
  int * v3100 = v3093->regs;
  int v3485 = v3097 + v3099;
  v3100[6] = v3485;
  struct StateT * v3476 = v3102(v3093);
  return v3476;
}

struct StateT * v2594(struct StateT * v2595) {
  int v2596 = v2595->timer;
  int v4057 = v2596 + 1;
  v2595->timer = v4057;
  int * v2598 = v2595->regs;
  int v2599 = v2598[11];
  int * v2600 = v2595->regs;
  int v4061 = v2599 << 7;
  v2600[11] = v4061;
  struct StateT * v4055 = v2602(v2595);
  return v4055;
}

struct StateT * v1009(struct StateT * v1010) {
  int v1011 = v1010->timer;
  int v1132 = v1011 + 1;
  v1010->timer = v1132;
  int * v1013 = v1010->regs;
  int v1014 = v1013[2];
  int * v1015 = v1010->mem;
  int v1136 = (int)((unsigned int)(v1014 + 60) >> 2);
  int v1016 = v1015[v1136];
  int * v1017 = v1010->regs;
  v1017[23] = v1016;
  struct StateT * v1130 = v1019(v1010);
  return v1130;
}

struct StateT * v2812(struct StateT * v2813) {
  int v2814 = v2813->timer;
  int v3800 = v2814 + 1;
  v2813->timer = v3800;
  int * v2816 = v2813->regs;
  int v2817 = v2816[6];
  int * v2818 = v2813->regs;
  int v2819 = v2818[9];
  int * v2820 = v2813->regs;
  int v3806 = v2817 | v2819;
  v2820[6] = v3806;
  struct StateT * v3798 = v2822(v2813);
  return v3798;
}

struct StateT * v2366(struct StateT * v2367) {
  int v2368 = v2367->timer;
  int v4319 = v2368 + 1;
  v2367->timer = v4319;
  int * v2370 = v2367->regs;
  int v2371 = v2370[8];
  int * v2372 = v2367->regs;
  int v2373 = v2372[25];
  int * v2374 = v2367->regs;
  int v4326 = v2371 + v2373;
  v2374[5] = v4326;
  struct StateT * v4317 = v2376(v2367);
  return v4317;
}

struct StateT * v2822(struct StateT * v2823) {
  int v2824 = v2823->timer;
  int v3790 = v2824 + 1;
  v2823->timer = v3790;
  int * v2826 = v2823->regs;
  int v2827 = v2826[8];
  int * v2828 = v2823->regs;
  int v3795 = (int)((unsigned int)v2827 >> 23);
  v2828[9] = v3795;
  struct StateT * v3788 = v2830(v2823);
  return v3788;
}

struct StateT * v307(struct StateT * v308) {
  int v309 = v308->timer;
  int v5195 = v309 + 1;
  v308->timer = v5195;
  int * v311 = v308->regs;
  v311[22] = 1797283840;
  struct StateT * v5193 = v313(v308);
  return v5193;
}

struct StateT * v2576(struct StateT * v2577) {
  int v2578 = v2577->timer;
  int v4076 = v2578 + 1;
  v2577->timer = v4076;
  int * v2580 = v2577->regs;
  int v2581 = v2580[15];
  int * v2582 = v2577->regs;
  int v2583 = v2582[5];
  int * v2584 = v2577->regs;
  int v4082 = v2581 | v2583;
  v2584[15] = v4082;
  struct StateT * v4074 = v2586(v2577);
  return v4074;
}

struct StateT * v799(struct StateT * v800) {
  int v801 = v800->timer;
  int v1384 = v801 + 1;
  v800->timer = v1384;
  int * v803 = v800->regs;
  int v804 = v803[10];
  int * v805 = v800->regs;
  int v806 = v805[14];
  int * v807 = v800->mem;
  int v1390 = (int)((unsigned int)(v804 + 12) >> 2);
  v807[v1390] = v806;
  struct StateT * v1382 = v809(v800);
  return v1382;
}

struct StateT * v519(struct StateT * v520) {
  int v521 = v520->timer;
  int v1712 = v521 + 1;
  v520->timer = v1712;
  int * v523 = v520->regs;
  v523[6] = 857759744;
  struct StateT * v1710 = v525(v520);
  return v1710;
}

struct StateT * v769(struct StateT * v770) {
  int v771 = v770->timer;
  int v1420 = v771 + 1;
  v770->timer = v1420;
  int * v773 = v770->regs;
  int v774 = v773[10];
  int * v775 = v770->regs;
  int v776 = v775[15];
  int * v777 = v770->mem;
  int v1426 = (int)((unsigned int)v774 >> 2);
  v777[v1426] = v776;
  struct StateT * v1418 = v779(v770);
  return v1418;
}

struct StateT * v779(struct StateT * v780) {
  int v781 = v780->timer;
  int v1408 = v781 + 1;
  v780->timer = v1408;
  int * v783 = v780->regs;
  int v784 = v783[10];
  int * v785 = v780->regs;
  int v786 = v785[29];
  int * v787 = v780->mem;
  int v1414 = (int)((unsigned int)(v784 + 4) >> 2);
  v787[v1414] = v786;
  struct StateT * v1406 = v789(v780);
  return v1406;
}

struct StateT * v2654(struct StateT * v2655) {
  int v2656 = v2655->timer;
  int v3985 = v2656 + 1;
  v2655->timer = v3985;
  int * v2658 = v2655->regs;
  int v2659 = v2658[17];
  int * v2660 = v2655->regs;
  int v2661 = v2660[5];
  int * v2662 = v2655->regs;
  int v3992 = v2659 | v2661;
  v2662[6] = v3992;
  struct StateT * v3983 = v2664(v2655);
  return v3983;
}

struct StateT * v919(struct StateT * v920) {
  int v921 = v920->timer;
  int v1240 = v921 + 1;
  v920->timer = v1240;
  int * v923 = v920->regs;
  int v924 = v923[10];
  int * v925 = v920->regs;
  int v926 = v925[30];
  int * v927 = v920->mem;
  int v1246 = (int)((unsigned int)(v924 + 60) >> 2);
  v927[v1246] = v926;
  struct StateT * v1238 = v929(v920);
  return v1238;
}

struct StateT * v2560(struct StateT * v2561) {
  int v2562 = v2561->timer;
  int v4096 = v2562 + 1;
  v2561->timer = v4096;
  int * v2564 = v2561->regs;
  int v2565 = v2564[15];
  int * v2566 = v2561->regs;
  int v4101 = (int)((unsigned int)v2565 >> 25);
  v2566[5] = v4101;
  struct StateT * v4094 = v2568(v2561);
  return v4094;
}

struct StateT * v2908(struct StateT * v2909) {
  int v2910 = v2909->timer;
  int v3690 = v2910 + 1;
  v2909->timer = v3690;
  int * v2912 = v2909->regs;
  int v2913 = v2912[26];
  int * v2914 = v2909->regs;
  int v2915 = v2914[17];
  int * v2916 = v2909->regs;
  int v3697 = v2913 + v2915;
  v2916[6] = v3697;
  struct StateT * v3688 = v2918(v2909);
  return v3688;
}

struct StateT * v3190(struct StateT * v3191) {
  int v3192 = v3191->timer;
  int v3366 = v3192 + 1;
  v3191->timer = v3366;
  int * v3194 = v3191->regs;
  int v3195 = v3194[8];
  int * v3196 = v3191->regs;
  int v3371 = (int)((unsigned int)v3195 >> 14);
  v3196[9] = v3371;
  struct StateT * v3364 = v3198(v3191);
  return v3364;
}

struct StateT * v489(struct StateT * v490) {
  int v491 = v490->timer;
  int v1743 = v491 + 1;
  v490->timer = v1743;
  int * v493 = v490->regs;
  int v494 = v493[14];
  int * v495 = v490->regs;
  int v496 = v495[7];
  int * v497 = v490->regs;
  int v1749 = v494 + v496;
  v497[14] = v1749;
  struct StateT * v1741 = v499(v490);
  return v1741;
}

struct StateT * v509(struct StateT * v510) {
  int v511 = v510->timer;
  int v1720 = v511 + 1;
  v510->timer = v1720;
  int * v513 = v510->regs;
  int v514 = v513[12];
  int * v515 = v510->regs;
  int v516 = v515[6];
  int * v517 = v510->regs;
  int v1726 = v514 + v516;
  v517[12] = v1726;
  struct StateT * v1718 = v519(v510);
  return v1718;
}

struct StateT * v2402(struct StateT * v2403) {
  int v2404 = v2403->timer;
  int v4279 = v2404 + 1;
  v2403->timer = v4279;
  int * v2406 = v2403->regs;
  int v2407 = v2406[16];
  int * v2408 = v2403->regs;
  int v4284 = (int)((unsigned int)v2407 >> 14);
  v2408[6] = v4284;
  struct StateT * v4277 = v2410(v2403);
  return v4277;
}

struct StateT * v2638(struct StateT * v2639) {
  int v2640 = v2639->timer;
  int v4006 = v2640 + 1;
  v2639->timer = v4006;
  int * v2642 = v2639->regs;
  int v2643 = v2642[17];
  int * v2644 = v2639->regs;
  int v4011 = (int)((unsigned int)v2643 >> 25);
  v2644[5] = v4011;
  struct StateT * v4004 = v2646(v2639);
  return v4004;
}

struct StateT * v819(struct StateT * v820) {
  int v821 = v820->timer;
  int v1360 = v821 + 1;
  v820->timer = v1360;
  int * v823 = v820->regs;
  int v824 = v823[10];
  int * v825 = v820->regs;
  int v826 = v825[11];
  int * v827 = v820->mem;
  int v1366 = (int)((unsigned int)(v824 + 20) >> 2);
  v827[v1366] = v826;
  struct StateT * v1358 = v829(v820);
  return v1358;
}

struct StateT * v2234(struct StateT * v2235) {
  int v2236 = v2235->timer;
  int v4475 = v2236 + 1;
  v2235->timer = v4475;
  int * v2238 = v2235->regs;
  int v2239 = v2238[8];
  int * v2240 = v2235->regs;
  int v2241 = v2240[20];
  int * v2242 = v2235->regs;
  int v4481 = v2239 | v2241;
  v2242[8] = v4481;
  struct StateT * v4473 = v2244(v2235);
  return v4473;
}

struct StateT * v929(struct StateT * v930) {
  int v931 = v930->timer;
  int v1228 = v931 + 1;
  v930->timer = v1228;
  int * v933 = v930->regs;
  int v934 = v933[2];
  int * v935 = v930->mem;
  int v1232 = (int)((unsigned int)(v934 + 92) >> 2);
  int v936 = v935[v1232];
  int * v937 = v930->regs;
  v937[1] = v936;
  struct StateT * v1226 = v939(v930);
  return v1226;
}

struct StateT * v2278(struct StateT * v2279) {
  int v2280 = v2279->timer;
  int v4426 = v2280 + 1;
  v2279->timer = v4426;
  int * v2282 = v2279->regs;
  int v2283 = v2282[18];
  int * v2284 = v2279->regs;
  int v4430 = v2283 << 13;
  v2284[18] = v4430;
  struct StateT * v4424 = v2286(v2279);
  return v4424;
}

struct StateT * v145(struct StateT * v146) {
  int v147 = v146->timer;
  int v5389 = v147 + 1;
  v146->timer = v5389;
  int * v149 = v146->regs;
  int v150 = v149[12];
  int * v151 = v146->mem;
  int v5393 = (int)((unsigned int)v150 >> 2);
  int v152 = v151[v5393];
  int * v153 = v146->regs;
  v153[29] = v152;
  struct StateT * v5387 = v155(v146);
  return v5387;
}

struct StateT * v2752(struct StateT * v2753) {
  int v2754 = v2753->timer;
  int v3871 = v2754 + 1;
  v2753->timer = v3871;
  int * v2756 = v2753->regs;
  int v2757 = v2756[11];
  int * v2758 = v2753->regs;
  int v3875 = v2757 << 9;
  v2758[11] = v3875;
  struct StateT * v3869 = v2760(v2753);
  return v3869;
}

struct StateT * v449(struct StateT * v450) {
  int v451 = v450->timer;
  int v5020 = v451 + 1;
  v450->timer = v5020;
  int * v453 = v450->regs;
  int v454 = v453[15];
  int * v455 = v450->regs;
  v455[13] = v454;
  struct StateT * v5018 = v457(v450);
  return v5018;
}

struct StateT * v2208(struct StateT * v2209) {
  int v2210 = v2209->timer;
  int v4505 = v2210 + 1;
  v2209->timer = v4505;
  int * v2212 = v2209->regs;
  int v2213 = v2212[15];
  int * v2214 = v2209->regs;
  int v2215 = v2214[20];
  int * v2216 = v2209->regs;
  int v4511 = v2213 | v2215;
  v2216[15] = v4511;
  struct StateT * v4503 = v2218(v2209);
  return v4503;
}

struct StateT * v621(struct StateT * v622) {
  int v623 = v622->timer;
  int v1589 = v623 + 1;
  v622->timer = v1589;
  int * v625 = v622->regs;
  int v626 = v625[17];
  int * v627 = v622->regs;
  int v628 = v627[30];
  int * v629 = v622->regs;
  int v1595 = v626 + v628;
  v629[17] = v1595;
  struct StateT * v1587 = v631(v622);
  return v1587;
}

struct StateT * v2568(struct StateT * v2569) {
  int v2570 = v2569->timer;
  int v4087 = v2570 + 1;
  v2569->timer = v4087;
  int * v2572 = v2569->regs;
  int v2573 = v2572[15];
  int * v2574 = v2569->regs;
  int v4091 = v2573 << 7;
  v2574[15] = v4091;
  struct StateT * v4085 = v2576(v2569);
  return v4085;
}

struct StateT * v899(struct StateT * v900) {
  int v901 = v900->timer;
  int v1264 = v901 + 1;
  v900->timer = v1264;
  int * v903 = v900->regs;
  int v904 = v903[10];
  int * v905 = v900->regs;
  int v906 = v905[24];
  int * v907 = v900->mem;
  int v1270 = (int)((unsigned int)(v904 + 52) >> 2);
  v907[v1270] = v906;
  struct StateT * v1262 = v909(v900);
  return v1262;
}

struct StateT * v397(struct StateT * v398) {
  int v399 = v398->timer;
  int v5082 = v399 + 1;
  v398->timer = v5082;
  int * v401 = v398->regs;
  int v402 = v401[2];
  int * v403 = v398->regs;
  int v404 = v403[6];
  int * v405 = v398->mem;
  int v5088 = (int)((unsigned int)(v402 + 8) >> 2);
  v405[v5088] = v404;
  struct StateT * v5080 = v407(v398);
  return v5080;
}

struct StateT * v3236(struct StateT * v3237) {
  int v3238 = v3237->timer;
  int v3312 = v3238 + 1;
  v3237->timer = v3312;
  int * v3240 = v3237->regs;
  int v3241 = v3240[19];
  int * v3242 = v3237->regs;
  int v3243 = v3242[6];
  int * v3244 = v3237->regs;
  int v3318 = v3241 ^ v3243;
  v3244[19] = v3318;
  struct StateT * v3310 = v3246(v3237);
  return v3310;
}

struct StateT * v1814(struct StateT * v1815) {
  int v1816 = v1815->timer;
  int v4959 = v1816 + 1;
  v1815->timer = v4959;
  int * v1818 = v1815->regs;
  int v1819 = v1818[22];
  int * v1820 = v1815->regs;
  int v1821 = v1820[17];
  int * v1822 = v1815->regs;
  int v4966 = v1819 + v1821;
  v1822[8] = v4966;
  struct StateT * v4957 = v1824(v1815);
  return v4957;
}

struct StateT * v215(struct StateT * v216) {
  int v217 = v216->timer;
  int v5305 = v217 + 1;
  v216->timer = v5305;
  int * v219 = v216->regs;
  int v220 = v219[12];
  int * v221 = v216->mem;
  int v5309 = (int)((unsigned int)(v220 + 28) >> 2);
  int v222 = v221[v5309];
  int * v223 = v216->regs;
  v223[1] = v222;
  struct StateT * v5303 = v225(v216);
  return v5303;
}

struct StateT * v39(struct StateT * v40) {
  int v41 = v40->timer;
  int v5517 = v41 + 1;
  v40->timer = v5517;
  int * v43 = v40->regs;
  int v44 = v43[2];
  int * v45 = v40->regs;
  int v46 = v45[18];
  int * v47 = v40->mem;
  int v5523 = (int)((unsigned int)(v44 + 80) >> 2);
  v47[v5523] = v46;
  struct StateT * v5515 = v49(v40);
  return v5515;
}

struct StateT * v245(struct StateT * v246) {
  int v247 = v246->timer;
  int v5269 = v247 + 1;
  v246->timer = v5269;
  int * v249 = v246->regs;
  int v250 = v249[11];
  int * v251 = v246->mem;
  int v5273 = (int)((unsigned int)(v250 + 8) >> 2);
  int v252 = v251[v5273];
  int * v253 = v246->regs;
  v253[26] = v252;
  struct StateT * v5267 = v255(v246);
  return v5267;
}

struct StateT * v195(struct StateT * v196) {
  int v197 = v196->timer;
  int v5329 = v197 + 1;
  v196->timer = v5329;
  int * v199 = v196->regs;
  int v200 = v199[12];
  int * v201 = v196->mem;
  int v5333 = (int)((unsigned int)(v200 + 20) >> 2);
  int v202 = v201[v5333];
  int * v203 = v196->regs;
  v203[16] = v202;
  struct StateT * v5327 = v205(v196);
  return v5327;
}

struct StateT * v611(struct StateT * v612) {
  int v613 = v612->timer;
  int v1600 = v613 + 1;
  v612->timer = v1600;
  int * v615 = v612->regs;
  int v616 = v615[2];
  int * v617 = v612->mem;
  int v1604 = (int)((unsigned int)(v616 + 28) >> 2);
  int v618 = v617[v1604];
  int * v619 = v612->regs;
  v619[30] = v618;
  struct StateT * v1598 = v621(v612);
  return v1598;
}

struct StateT * v2392(struct StateT * v2393) {
  int v2394 = v2393->timer;
  int v4289 = v2394 + 1;
  v2393->timer = v4289;
  int * v2396 = v2393->regs;
  int v2397 = v2396[15];
  int * v2398 = v2393->regs;
  int v2399 = v2398[6];
  int * v2400 = v2393->regs;
  int v4295 = v2397 | v2399;
  v2400[15] = v4295;
  struct StateT * v4287 = v2402(v2393);
  return v4287;
}

struct StateT * v869(struct StateT * v870) {
  int v871 = v870->timer;
  int v1300 = v871 + 1;
  v870->timer = v1300;
  int * v873 = v870->regs;
  int v874 = v873[10];
  int * v875 = v870->regs;
  int v876 = v875[7];
  int * v877 = v870->mem;
  int v1306 = (int)((unsigned int)(v874 + 40) >> 2);
  v877[v1306] = v876;
  struct StateT * v1298 = v879(v870);
  return v1298;
}

struct StateT * v463(struct StateT * v464) {
  int v465 = v464->timer;
  int v1773 = v465 + 1;
  v464->timer = v1773;
  int * v467 = v464->regs;
  int v468 = v467[23];
  int * v469 = v464->regs;
  int v470 = v469[29];
  int * v471 = v464->regs;
  int v1779 = v468 + v470;
  v471[29] = v1779;
  struct StateT * v1771 = v473(v464);
  return v1771;
}

struct StateT * v283(struct StateT * v284) {
  int v285 = v284->timer;
  int v5223 = v285 + 1;
  v284->timer = v5223;
  int * v287 = v284->regs;
  int v288 = v287[12];
  int * v289 = v284->regs;
  int v5228 = v288 + -1947;
  v289[21] = v5228;
  struct StateT * v5221 = v291(v284);
  return v5221;
}

struct StateT * v2602(struct StateT * v2603) {
  int v2604 = v2603->timer;
  int v4046 = v2604 + 1;
  v2603->timer = v4046;
  int * v2606 = v2603->regs;
  int v2607 = v2606[11];
  int * v2608 = v2603->regs;
  int v2609 = v2608[5];
  int * v2610 = v2603->regs;
  int v4052 = v2607 | v2609;
  v2610[11] = v4052;
  struct StateT * v4044 = v2612(v2603);
  return v4044;
}

struct StateT * v3082(struct StateT * v3083) {
  int v3084 = v3083->timer;
  int v3490 = v3084 + 1;
  v3083->timer = v3490;
  int * v3086 = v3083->regs;
  int v3087 = v3086[12];
  int * v3088 = v3083->regs;
  int v3089 = v3088[25];
  int * v3090 = v3083->regs;
  int v3497 = v3087 + v3089;
  v3090[15] = v3497;
  struct StateT * v3488 = v3092(v3083);
  return v3488;
}

struct StateT * v2122(struct StateT * v2123) {
  int v2124 = v2123->timer;
  int v4605 = v2124 + 1;
  v2123->timer = v4605;
  int * v2126 = v2123->regs;
  int v2127 = v2126[24];
  int * v2128 = v2123->regs;
  int v2129 = v2128[8];
  int * v2130 = v2123->regs;
  int v4611 = v2127 ^ v2129;
  v2130[24] = v4611;
  struct StateT * v4603 = v2132(v2123);
  return v4603;
}

struct StateT * v2586(struct StateT * v2587) {
  int v2588 = v2587->timer;
  int v4066 = v2588 + 1;
  v2587->timer = v4066;
  int * v2590 = v2587->regs;
  int v2591 = v2590[11];
  int * v2592 = v2587->regs;
  int v4071 = (int)((unsigned int)v2591 >> 25);
  v2592[5] = v4071;
  struct StateT * v4064 = v2594(v2587);
  return v4064;
}

struct StateT * v2970(struct StateT * v2971) {
  int v2972 = v2971->timer;
  int v3618 = v2972 + 1;
  v2971->timer = v3618;
  int * v2974 = v2971->regs;
  int v2975 = v2974[15];
  int * v2976 = v2971->regs;
  int v2977 = v2976[9];
  int * v2978 = v2971->regs;
  int v3624 = v2975 | v2977;
  v2978[15] = v3624;
  struct StateT * v3616 = v2980(v2971);
  return v3616;
}

struct StateT * v829(struct StateT * v830) {
  int v831 = v830->timer;
  int v1348 = v831 + 1;
  v830->timer = v1348;
  int * v833 = v830->regs;
  int v834 = v833[10];
  int * v835 = v830->regs;
  int v836 = v835[5];
  int * v837 = v830->mem;
  int v1354 = (int)((unsigned int)(v834 + 24) >> 2);
  v837[v1354] = v836;
  struct StateT * v1346 = v839(v830);
  return v1346;
}

struct StateT * v697(struct StateT * v698) {
  int v699 = v698->timer;
  int v1503 = v699 + 1;
  v698->timer = v1503;
  int * v701 = v698->regs;
  int v702 = v701[15];
  int * v703 = v698->regs;
  int v1507 = v702 + -1947;
  v703[15] = v1507;
  struct StateT * v1501 = v705(v698);
  return v1501;
}

struct StateT * v2016(struct StateT * v2017) {
  int v2018 = v2017->timer;
  int v4728 = v2018 + 1;
  v2017->timer = v4728;
  int * v2020 = v2017->regs;
  int v2021 = v2020[15];
  int * v2022 = v2017->regs;
  int v4732 = v2021 << 9;
  v2022[15] = v4732;
  struct StateT * v4726 = v2024(v2017);
  return v4726;
}

struct StateT * v2296(struct StateT * v2297) {
  int v2298 = v2297->timer;
  int v4402 = v2298 + 1;
  v2297->timer = v4402;
  int * v2300 = v2297->regs;
  int v2301 = v2300[16];
  int * v2302 = v2297->regs;
  int v2303 = v2302[15];
  int * v2304 = v2297->regs;
  int v4409 = v2301 ^ v2303;
  v2304[9] = v4409;
  struct StateT * v4400 = v2306(v2297);
  return v4400;
}

struct StateT * v337(struct StateT * v338) {
  int v339 = v338->timer;
  int v5154 = v339 + 1;
  v338->timer = v5154;
  int * v341 = v338->regs;
  int v342 = v341[2];
  int * v343 = v338->regs;
  int v344 = v343[25];
  int * v345 = v338->mem;
  int v5160 = (int)((unsigned int)(v342 + 16) >> 2);
  v345[v5160] = v344;
  struct StateT * v5152 = v347(v338);
  return v5152;
}

struct StateT * v313(struct StateT * v314) {
  int v315 = v314->timer;
  int v5186 = v315 + 1;
  v314->timer = v5186;
  int * v317 = v314->regs;
  int v318 = v317[22];
  int * v319 = v314->regs;
  int v5190 = v318 + 1396;
  v319[22] = v5190;
  struct StateT * v5184 = v321(v314);
  return v5184;
}

struct StateT * v949(struct StateT * v950) {
  int v951 = v950->timer;
  int v1204 = v951 + 1;
  v950->timer = v1204;
  int * v953 = v950->regs;
  int v954 = v953[2];
  int * v955 = v950->mem;
  int v1208 = (int)((unsigned int)(v954 + 84) >> 2);
  int v956 = v955[v1208];
  int * v957 = v950->regs;
  v957[9] = v956;
  struct StateT * v1202 = v959(v950);
  return v1202;
}

struct StateT * v989(struct StateT * v990) {
  int v991 = v990->timer;
  int v1156 = v991 + 1;
  v990->timer = v1156;
  int * v993 = v990->regs;
  int v994 = v993[2];
  int * v995 = v990->mem;
  int v1160 = (int)((unsigned int)(v994 + 68) >> 2);
  int v996 = v995[v1160];
  int * v997 = v990->regs;
  v997[21] = v996;
  struct StateT * v1154 = v999(v990);
  return v1154;
}

struct StateT * v2962(struct StateT * v2963) {
  int v2964 = v2963->timer;
  int v3629 = v2964 + 1;
  v2963->timer = v3629;
  int * v2966 = v2963->regs;
  int v2967 = v2966[15];
  int * v2968 = v2963->regs;
  int v3633 = v2967 << 13;
  v2968[15] = v3633;
  struct StateT * v3627 = v2970(v2963);
  return v3627;
}

struct StateT * v1876(struct StateT * v1877) {
  int v1878 = v1877->timer;
  int v4889 = v1878 + 1;
  v1877->timer = v4889;
  int * v1880 = v1877->regs;
  int v1881 = v1880[18];
  int * v1882 = v1877->regs;
  int v4894 = (int)((unsigned int)v1881 >> 25);
  v1882[20] = v4894;
  struct StateT * v4887 = v1884(v1877);
  return v4887;
}

struct StateT * v1804(struct StateT * v1805) {
  int v1806 = v1805->timer;
  int v4971 = v1806 + 1;
  v1805->timer = v4971;
  int * v1808 = v1805->regs;
  int v1809 = v1808[19];
  int * v1810 = v1805->regs;
  int v1811 = v1810[5];
  int * v1812 = v1805->regs;
  int v4978 = v1809 + v1811;
  v1812[18] = v4978;
  struct StateT * v4969 = v1814(v1805);
  return v4969;
}

struct StateT * v2102(struct StateT * v2103) {
  int v2104 = v2103->timer;
  int v4627 = v2104 + 1;
  v2103->timer = v4627;
  int * v2106 = v2103->regs;
  int v2107 = v2106[18];
  int * v2108 = v2103->regs;
  int v2109 = v2108[20];
  int * v2110 = v2103->regs;
  int v4633 = v2107 | v2109;
  v2110[18] = v4633;
  struct StateT * v4625 = v2112(v2103);
  return v4625;
}

struct StateT * v3112(struct StateT * v3113) {
  int v3114 = v3113->timer;
  int v3456 = v3114 + 1;
  v3113->timer = v3456;
  int * v3116 = v3113->regs;
  int v3117 = v3116[11];
  int * v3118 = v3113->regs;
  int v3461 = (int)((unsigned int)v3117 >> 14);
  v3118[9] = v3461;
  struct StateT * v3454 = v3120(v3113);
  return v3454;
}

struct StateT * v2076(struct StateT * v2077) {
  int v2078 = v2077->timer;
  int v4657 = v2078 + 1;
  v2077->timer = v4657;
  int * v2080 = v2077->regs;
  int v2081 = v2080[9];
  int * v2082 = v2077->regs;
  int v2083 = v2082[20];
  int * v2084 = v2077->regs;
  int v4663 = v2081 | v2083;
  v2084[9] = v4663;
  struct StateT * v4655 = v2086(v2077);
  return v4655;
}

struct StateT * v2286(struct StateT * v2287) {
  int v2288 = v2287->timer;
  int v4414 = v2288 + 1;
  v2287->timer = v4414;
  int * v2290 = v2287->regs;
  int v2291 = v2290[18];
  int * v2292 = v2287->regs;
  int v2293 = v2292[9];
  int * v2294 = v2287->regs;
  int v4421 = v2291 | v2293;
  v2294[6] = v4421;
  struct StateT * v4412 = v2296(v2287);
  return v4412;
}

struct StateT * v2848(struct StateT * v2849) {
  int v2850 = v2849->timer;
  int v3759 = v2850 + 1;
  v2849->timer = v3759;
  int * v2852 = v2849->regs;
  int v2853 = v2852[27];
  int * v2854 = v2849->regs;
  int v2855 = v2854[11];
  int * v2856 = v2849->regs;
  int v3765 = v2853 ^ v2855;
  v2856[27] = v3765;
  struct StateT * v3757 = v2858(v2849);
  return v3757;
}

struct StateT * v225(struct StateT * v226) {
  int v227 = v226->timer;
  int v5293 = v227 + 1;
  v226->timer = v5293;
  int * v229 = v226->regs;
  int v230 = v229[11];
  int * v231 = v226->mem;
  int v5297 = (int)((unsigned int)v230 >> 2);
  int v232 = v231[v5297];
  int * v233 = v226->regs;
  v233[5] = v232;
  struct StateT * v5291 = v235(v226);
  return v5291;
}

struct StateT * v59(struct StateT * v60) {
  int v61 = v60->timer;
  int v5493 = v61 + 1;
  v60->timer = v5493;
  int * v63 = v60->regs;
  int v64 = v63[2];
  int * v65 = v60->regs;
  int v66 = v65[20];
  int * v67 = v60->mem;
  int v5499 = (int)((unsigned int)(v64 + 72) >> 2);
  v67[v5499] = v66;
  struct StateT * v5491 = v69(v60);
  return v5491;
}

struct StateT * v3102(struct StateT * v3103) {
  int v3104 = v3103->timer;
  int v3466 = v3104 + 1;
  v3103->timer = v3466;
  int * v3106 = v3103->regs;
  int v3107 = v3106[1];
  int * v3108 = v3103->regs;
  int v3109 = v3108[24];
  int * v3110 = v3103->regs;
  int v3473 = v3107 + v3109;
  v3110[8] = v3473;
  struct StateT * v3464 = v3112(v3103);
  return v3464;
}

struct StateT * v2260(struct StateT * v2261) {
  int v2262 = v2261->timer;
  int v4445 = v2262 + 1;
  v2261->timer = v4445;
  int * v2264 = v2261->regs;
  int v2265 = v2264[9];
  int * v2266 = v2261->regs;
  int v2267 = v2266[20];
  int * v2268 = v2261->regs;
  int v4451 = v2265 | v2267;
  v2268[20] = v4451;
  struct StateT * v4443 = v2270(v2261);
  return v4443;
}

struct StateT * v1794(struct StateT * v1795) {
  int v1796 = v1795->timer;
  int v4983 = v1796 + 1;
  v1795->timer = v4983;
  int * v1798 = v1795->regs;
  int v1799 = v1798[11];
  int * v1800 = v1795->regs;
  int v1801 = v1800[23];
  int * v1802 = v1795->regs;
  int v4990 = v1799 + v1801;
  v1802[20] = v4990;
  struct StateT * v4981 = v1804(v1795);
  return v4981;
}

struct StateT * v2838(struct StateT * v2839) {
  int v2840 = v2839->timer;
  int v3770 = v2840 + 1;
  v2839->timer = v3770;
  int * v2842 = v2839->regs;
  int v2843 = v2842[8];
  int * v2844 = v2839->regs;
  int v2845 = v2844[9];
  int * v2846 = v2839->regs;
  int v3776 = v2843 | v2845;
  v2846[8] = v3776;
  struct StateT * v3768 = v2848(v2839);
  return v3768;
}

struct StateT * v1902(struct StateT * v1903) {
  int v1904 = v1903->timer;
  int v4859 = v1904 + 1;
  v1903->timer = v4859;
  int * v1906 = v1903->regs;
  int v1907 = v1906[8];
  int * v1908 = v1903->regs;
  int v4864 = (int)((unsigned int)v1907 >> 25);
  v1908[20] = v4864;
  struct StateT * v4857 = v1910(v1903);
  return v4857;
}

struct StateT * v525(struct StateT * v526) {
  int v527 = v526->timer;
  int v1700 = v527 + 1;
  v526->timer = v1700;
  int * v529 = v526->regs;
  int v530 = v529[2];
  int * v531 = v526->mem;
  int v1704 = (int)((unsigned int)(v530 + 12) >> 2);
  int v532 = v531[v1704];
  int * v533 = v526->regs;
  v533[7] = v532;
  struct StateT * v1698 = v535(v526);
  return v1698;
}

struct StateT * v1892(struct StateT * v1893) {
  int v1894 = v1893->timer;
  int v4869 = v1894 + 1;
  v1893->timer = v4869;
  int * v1896 = v1893->regs;
  int v1897 = v1896[18];
  int * v1898 = v1893->regs;
  int v1899 = v1898[20];
  int * v1900 = v1893->regs;
  int v4875 = v1897 | v1899;
  v1900[18] = v4875;
  struct StateT * v4867 = v1902(v1893);
  return v4867;
}

struct StateT * v939(struct StateT * v940) {
  int v941 = v940->timer;
  int v1216 = v941 + 1;
  v940->timer = v1216;
  int * v943 = v940->regs;
  int v944 = v943[2];
  int * v945 = v940->mem;
  int v1220 = (int)((unsigned int)(v944 + 88) >> 2);
  int v946 = v945[v1220];
  int * v947 = v940->regs;
  v947[8] = v946;
  struct StateT * v1214 = v949(v940);
  return v1214;
}

struct StateT * v2550(struct StateT * v2551) {
  int v2552 = v2551->timer;
  int v4106 = v2552 + 1;
  v2551->timer = v4106;
  int * v2554 = v2551->regs;
  int v2555 = v2554[22];
  int * v2556 = v2551->regs;
  int v2557 = v2556[1];
  int * v2558 = v2551->regs;
  int v4113 = v2555 + v2557;
  v2558[17] = v4113;
  struct StateT * v4104 = v2560(v2551);
  return v4104;
}

struct StateT * v2786(struct StateT * v2787) {
  int v2788 = v2787->timer;
  int v3830 = v2788 + 1;
  v2787->timer = v3830;
  int * v2790 = v2787->regs;
  int v2791 = v2790[15];
  int * v2792 = v2787->regs;
  int v2793 = v2792[9];
  int * v2794 = v2787->regs;
  int v3836 = v2791 | v2793;
  v2794[15] = v3836;
  struct StateT * v3828 = v2796(v2787);
  return v3828;
}

struct StateT * v605(struct StateT * v606) {
  int v607 = v606->timer;
  int v1612 = v607 + 1;
  v606->timer = v1612;
  int * v609 = v606->regs;
  v609[7] = 2036477952;
  struct StateT * v1610 = v611(v606);
  return v1610;
}

struct StateT * v2444(struct StateT * v2445) {
  int v2446 = v2445->timer;
  int v4229 = v2446 + 1;
  v2445->timer = v4229;
  int * v2448 = v2445->regs;
  int v2449 = v2448[17];
  int * v2450 = v2445->regs;
  int v2451 = v2450[6];
  int * v2452 = v2445->regs;
  int v4235 = v2449 | v2451;
  v2452[17] = v4235;
  struct StateT * v4227 = v2454(v2445);
  return v4227;
}

struct StateT * v69(struct StateT * v70) {
  int v71 = v70->timer;
  int v5481 = v71 + 1;
  v70->timer = v5481;
  int * v73 = v70->regs;
  int v74 = v73[2];
  int * v75 = v70->regs;
  int v76 = v75[21];
  int * v77 = v70->mem;
  int v5487 = (int)((unsigned int)(v74 + 68) >> 2);
  v77[v5487] = v76;
  struct StateT * v5479 = v79(v70);
  return v5479;
}

struct StateT * v859(struct StateT * v860) {
  int v861 = v860->timer;
  int v1312 = v861 + 1;
  v860->timer = v1312;
  int * v863 = v860->regs;
  int v864 = v863[10];
  int * v865 = v860->regs;
  int v866 = v865[13];
  int * v867 = v860->mem;
  int v1318 = (int)((unsigned int)(v864 + 36) >> 2);
  v867[v1318] = v866;
  struct StateT * v1310 = v869(v860);
  return v1310;
}

struct StateT * v2462(struct StateT * v2463) {
  int v2464 = v2463->timer;
  int v4210 = v2464 + 1;
  v2463->timer = v4210;
  int * v2466 = v2463->regs;
  int v2467 = v2466[5];
  int * v2468 = v2463->regs;
  int v4214 = v2467 << 18;
  v2468[5] = v4214;
  struct StateT * v4208 = v2470(v2463);
  return v4208;
}

struct StateT * v1884(struct StateT * v1885) {
  int v1886 = v1885->timer;
  int v4880 = v1886 + 1;
  v1885->timer = v4880;
  int * v1888 = v1885->regs;
  int v1889 = v1888[18];
  int * v1890 = v1885->regs;
  int v4884 = v1889 << 7;
  v1890[18] = v4884;
  struct StateT * v4878 = v1892(v1885);
  return v4878;
}

struct StateT * v1824(struct StateT * v1825) {
  int v1826 = v1825->timer;
  int v4949 = v1826 + 1;
  v1825->timer = v4949;
  int * v1828 = v1825->regs;
  int v1829 = v1828[15];
  int * v1830 = v1825->regs;
  int v4954 = (int)((unsigned int)v1829 >> 25);
  v1830[9] = v4954;
  struct StateT * v4947 = v1832(v1825);
  return v4947;
}

struct StateT * v99(struct StateT * v100) {
  int v101 = v100->timer;
  int v5445 = v101 + 1;
  v100->timer = v5445;
  int * v103 = v100->regs;
  int v104 = v103[2];
  int * v105 = v100->regs;
  int v106 = v105[24];
  int * v107 = v100->mem;
  int v5451 = (int)((unsigned int)(v104 + 56) >> 2);
  v107[v5451] = v106;
  struct StateT * v5443 = v109(v100);
  return v5443;
}

struct StateT * v3256(struct StateT * v3257) {
  int v3258 = v3257->timer;
  int v3292 = v3258 + 1;
  v3257->timer = v3292;
  int * v3260 = v3257->regs;
  int v3261 = v3260[30];
  int * v3262 = v3257->regs;
  int v3296 = v3261 + 1;
  v3262[30] = v3296;
  struct StateT * v3290 = v3264(v3257);
  return v3290;
}

struct StateT * v839(struct StateT * v840) {
  int v841 = v840->timer;
  int v1336 = v841 + 1;
  v840->timer = v1336;
  int * v843 = v840->regs;
  int v844 = v843[10];
  int * v845 = v840->regs;
  int v846 = v845[25];
  int * v847 = v840->mem;
  int v1342 = (int)((unsigned int)(v844 + 28) >> 2);
  v847[v1342] = v846;
  struct StateT * v1334 = v849(v840);
  return v1334;
}

struct StateT * v291(struct StateT * v292) {
  int v293 = v292->timer;
  int v5213 = v293 + 1;
  v292->timer = v5213;
  int * v295 = v292->regs;
  int v296 = v295[13];
  int * v297 = v292->regs;
  int v5218 = v296 + 1134;
  v297[11] = v5218;
  struct StateT * v5211 = v299(v292);
  return v5211;
}

struct StateT * v2646(struct StateT * v2647) {
  int v2648 = v2647->timer;
  int v3997 = v2648 + 1;
  v2647->timer = v3997;
  int * v2650 = v2647->regs;
  int v2651 = v2650[17];
  int * v2652 = v2647->regs;
  int v4001 = v2651 << 7;
  v2652[17] = v4001;
  struct StateT * v3995 = v2654(v2647);
  return v3995;
}

struct StateT * v1948(struct StateT * v1949) {
  int v1950 = v1949->timer;
  int v4806 = v1950 + 1;
  v1949->timer = v4806;
  int * v1952 = v1949->regs;
  int v1953 = v1952[1];
  int * v1954 = v1949->regs;
  int v1955 = v1954[18];
  int * v1956 = v1949->regs;
  int v4812 = v1953 ^ v1955;
  v1956[1] = v4812;
  struct StateT * v4804 = v1958(v1949);
  return v4804;
}

struct StateT * v1988(struct StateT * v1989) {
  int v1990 = v1989->timer;
  int v4759 = v1990 + 1;
  v1989->timer = v4759;
  int * v1992 = v1989->regs;
  int v1993 = v1992[1];
  int * v1994 = v1989->regs;
  int v1995 = v1994[19];
  int * v1996 = v1989->regs;
  int v4766 = v1993 + v1995;
  v1996[9] = v4766;
  struct StateT * v4757 = v1998(v1989);
  return v4757;
}

struct StateT * v2778(struct StateT * v2779) {
  int v2780 = v2779->timer;
  int v3841 = v2780 + 1;
  v2779->timer = v3841;
  int * v2782 = v2779->regs;
  int v2783 = v2782[15];
  int * v2784 = v2779->regs;
  int v3845 = v2783 << 9;
  v2784[15] = v3845;
  struct StateT * v3839 = v2786(v2779);
  return v3839;
}

struct StateT * v2868(struct StateT * v2869) {
  int v2870 = v2869->timer;
  int v3737 = v2870 + 1;
  v2869->timer = v3737;
  int * v2872 = v2869->regs;
  int v2873 = v2872[26];
  int * v2874 = v2869->regs;
  int v2875 = v2874[6];
  int * v2876 = v2869->regs;
  int v3743 = v2873 ^ v2875;
  v2876[26] = v3743;
  struct StateT * v3735 = v2878(v2869);
  return v3735;
}

struct StateT * v2804(struct StateT * v2805) {
  int v2806 = v2805->timer;
  int v3811 = v2806 + 1;
  v2805->timer = v3811;
  int * v2808 = v2805->regs;
  int v2809 = v2808[6];
  int * v2810 = v2805->regs;
  int v3815 = v2809 << 9;
  v2810[6] = v3815;
  struct StateT * v3809 = v2812(v2805);
  return v3809;
}

struct StateT * v585(struct StateT * v586) {
  int v587 = v586->timer;
  int v1631 = v587 + 1;
  v586->timer = v1631;
  int * v589 = v586->regs;
  int v590 = v589[2];
  int * v591 = v586->mem;
  int v1635 = (int)((unsigned int)(v590 + 24) >> 2);
  int v592 = v591[v1635];
  int * v593 = v586->regs;
  v593[7] = v592;
  struct StateT * v1629 = v595(v586);
  return v1629;
}

struct StateT * v2060(struct StateT * v2061) {
  int v2062 = v2061->timer;
  int v4677 = v2062 + 1;
  v2061->timer = v4677;
  int * v2064 = v2061->regs;
  int v2065 = v2064[9];
  int * v2066 = v2061->regs;
  int v4682 = (int)((unsigned int)v2065 >> 23);
  v2066[20] = v4682;
  struct StateT * v4675 = v2068(v2061);
  return v4675;
}

struct StateT * v3246(struct StateT * v3247) {
  int v3248 = v3247->timer;
  int v3301 = v3248 + 1;
  v3247->timer = v3301;
  int * v3250 = v3247->regs;
  int v3251 = v3250[22];
  int * v3252 = v3247->regs;
  int v3253 = v3252[8];
  int * v3254 = v3247->regs;
  int v3307 = v3251 ^ v3253;
  v3254[22] = v3307;
  struct StateT * v3299 = v3256(v3247);
  return v3299;
}

struct StateT * v3128(struct StateT * v3129) {
  int v3130 = v3129->timer;
  int v3436 = v3130 + 1;
  v3129->timer = v3436;
  int * v3132 = v3129->regs;
  int v3133 = v3132[11];
  int * v3134 = v3129->regs;
  int v3135 = v3134[9];
  int * v3136 = v3129->regs;
  int v3442 = v3133 | v3135;
  v3136[11] = v3442;
  struct StateT * v3434 = v3138(v3129);
  return v3434;
}

struct StateT * v483(struct StateT * v484) {
  int v485 = v484->timer;
  int v1754 = v485 + 1;
  v484->timer = v1754;
  int * v487 = v484->regs;
  v487[15] = 1634762752;
  struct StateT * v1752 = v489(v484);
  return v1752;
}

struct StateT * v749(struct StateT * v750) {
  int v751 = v750->timer;
  int v1443 = v751 + 1;
  v750->timer = v1443;
  int * v753 = v750->regs;
  int v754 = v753[19];
  int * v755 = v750->regs;
  int v756 = v755[7];
  int * v757 = v750->regs;
  int v1449 = v754 + v756;
  v757[7] = v1449;
  struct StateT * v1441 = v759(v750);
  return v1441;
}

struct StateT * v2410(struct StateT * v2411) {
  int v2412 = v2411->timer;
  int v4270 = v2412 + 1;
  v2411->timer = v4270;
  int * v2414 = v2411->regs;
  int v2415 = v2414[16];
  int * v2416 = v2411->regs;
  int v4274 = v2415 << 18;
  v2416[16] = v4274;
  struct StateT * v4268 = v2418(v2411);
  return v4268;
}

struct StateT * v631(struct StateT * v632) {
  int v633 = v632->timer;
  int v1577 = v633 + 1;
  v632->timer = v1577;
  int * v635 = v632->regs;
  int v636 = v635[2];
  int * v637 = v632->mem;
  int v1581 = (int)((unsigned int)(v636 + 32) >> 2);
  int v638 = v637[v1581];
  int * v639 = v632->regs;
  v639[30] = v638;
  struct StateT * v1575 = v641(v632);
  return v1575;
}

struct StateT * v2996(struct StateT * v2997) {
  int v2998 = v2997->timer;
  int v3588 = v2998 + 1;
  v2997->timer = v3588;
  int * v3000 = v2997->regs;
  int v3001 = v3000[6];
  int * v3002 = v2997->regs;
  int v3003 = v3002[9];
  int * v3004 = v2997->regs;
  int v3594 = v3001 | v3003;
  v3004[6] = v3594;
  struct StateT * v3586 = v3006(v2997);
  return v3586;
}

struct StateT * v3120(struct StateT * v3121) {
  int v3122 = v3121->timer;
  int v3447 = v3122 + 1;
  v3121->timer = v3447;
  int * v3124 = v3121->regs;
  int v3125 = v3124[11];
  int * v3126 = v3121->regs;
  int v3451 = v3125 << 18;
  v3126[11] = v3451;
  struct StateT * v3445 = v3128(v3121);
  return v3445;
}

struct StateT * v321(struct StateT * v322) {
  int v323 = v322->timer;
  int v5178 = v323 + 1;
  v322->timer = v5178;
  int * v325 = v322->regs;
  v325[31] = 9;
  struct StateT * v5176 = v327(v322);
  return v5176;
}

struct StateT * v2480(struct StateT * v2481) {
  int v2482 = v2481->timer;
  int v4188 = v2482 + 1;
  v2481->timer = v4188;
  int * v2484 = v2481->regs;
  int v2485 = v2484[21];
  int * v2486 = v2481->regs;
  int v2487 = v2486[15];
  int * v2488 = v2481->regs;
  int v4194 = v2485 ^ v2487;
  v2488[21] = v4194;
  struct StateT * v4186 = v2490(v2481);
  return v4186;
}

struct StateT * v1029(struct StateT * v1030) {
  int v1031 = v1030->timer;
  int v1108 = v1031 + 1;
  v1030->timer = v1108;
  int * v1033 = v1030->regs;
  int v1034 = v1033[2];
  int * v1035 = v1030->mem;
  int v1112 = (int)((unsigned int)(v1034 + 52) >> 2);
  int v1036 = v1035[v1112];
  int * v1037 = v1030->regs;
  v1037[25] = v1036;
  struct StateT * v1106 = v1039(v1030);
  return v1106;
}

struct StateT * v2428(struct StateT * v2429) {
  int v2430 = v2429->timer;
  int v4249 = v2430 + 1;
  v2429->timer = v4249;
  int * v2432 = v2429->regs;
  int v2433 = v2432[17];
  int * v2434 = v2429->regs;
  int v4254 = (int)((unsigned int)v2433 >> 14);
  v2434[6] = v4254;
  struct StateT * v4247 = v2436(v2429);
  return v4247;
}

struct StateT * v2470(struct StateT * v2471) {
  int v2472 = v2471->timer;
  int v4199 = v2472 + 1;
  v2471->timer = v4199;
  int * v2474 = v2471->regs;
  int v2475 = v2474[5];
  int * v2476 = v2471->regs;
  int v2477 = v2476[6];
  int * v2478 = v2471->regs;
  int v4205 = v2475 | v2477;
  v2478[5] = v4205;
  struct StateT * v4197 = v2480(v2471);
  return v4197;
}

struct StateT * v2954(struct StateT * v2955) {
  int v2956 = v2955->timer;
  int v3638 = v2956 + 1;
  v2955->timer = v3638;
  int * v2958 = v2955->regs;
  int v2959 = v2958[15];
  int * v2960 = v2955->regs;
  int v3643 = (int)((unsigned int)v2959 >> 19);
  v2960[9] = v3643;
  struct StateT * v3636 = v2962(v2955);
  return v3636;
}

struct StateT * v1938(struct StateT * v1939) {
  int v1940 = v1939->timer;
  int v4817 = v1940 + 1;
  v1939->timer = v4817;
  int * v1942 = v1939->regs;
  int v1943 = v1942[13];
  int * v1944 = v1939->regs;
  int v1945 = v1944[9];
  int * v1946 = v1939->regs;
  int v4823 = v1943 ^ v1945;
  v1946[13] = v4823;
  struct StateT * v4815 = v1948(v1939);
  return v4815;
}

struct StateT * v2620(struct StateT * v2621) {
  int v2622 = v2621->timer;
  int v4027 = v2622 + 1;
  v2621->timer = v4027;
  int * v2624 = v2621->regs;
  int v2625 = v2624[16];
  int * v2626 = v2621->regs;
  int v4031 = v2625 << 7;
  v2626[16] = v4031;
  struct StateT * v4025 = v2628(v2621);
  return v4025;
}

struct StateT * v29(struct StateT * v30) {
  int v31 = v30->timer;
  int v5529 = v31 + 1;
  v30->timer = v5529;
  int * v33 = v30->regs;
  int v34 = v33[2];
  int * v35 = v30->regs;
  int v36 = v35[9];
  int * v37 = v30->mem;
  int v5535 = (int)((unsigned int)(v34 + 84) >> 2);
  v37[v5535] = v36;
  struct StateT * v5527 = v39(v30);
  return v5527;
}

struct StateT * v89(struct StateT * v90) {
  int v91 = v90->timer;
  int v5457 = v91 + 1;
  v90->timer = v5457;
  int * v93 = v90->regs;
  int v94 = v93[2];
  int * v95 = v90->regs;
  int v96 = v95[23];
  int * v97 = v90->mem;
  int v5463 = (int)((unsigned int)(v94 + 60) >> 2);
  v97[v5463] = v96;
  struct StateT * v5455 = v99(v90);
  return v5455;
}

struct StateT * v2724(struct StateT * v2725) {
  int v2726 = v2725->timer;
  int v3902 = v2726 + 1;
  v2725->timer = v3902;
  int * v2728 = v2725->regs;
  int v2729 = v2728[17];
  int * v2730 = v2725->regs;
  int v2731 = v2730[19];
  int * v2732 = v2725->regs;
  int v3909 = v2729 + v2731;
  v2732[6] = v3909;
  struct StateT * v3900 = v2734(v2725);
  return v3900;
}

struct StateT * v2376(struct StateT * v2377) {
  int v2378 = v2377->timer;
  int v4309 = v2378 + 1;
  v2377->timer = v4309;
  int * v2380 = v2377->regs;
  int v2381 = v2380[15];
  int * v2382 = v2377->regs;
  int v4314 = (int)((unsigned int)v2381 >> 14);
  v2382[6] = v4314;
  struct StateT * v4307 = v2384(v2377);
  return v4307;
}

struct StateT * v3138(struct StateT * v3139) {
  int v3140 = v3139->timer;
  int v3426 = v3140 + 1;
  v3139->timer = v3426;
  int * v3142 = v3139->regs;
  int v3143 = v3142[15];
  int * v3144 = v3139->regs;
  int v3431 = (int)((unsigned int)v3143 >> 14);
  v3144[9] = v3431;
  struct StateT * v3424 = v3146(v3139);
  return v3424;
}

struct StateT * v2918(struct StateT * v2919) {
  int v2920 = v2919->timer;
  int v3678 = v2920 + 1;
  v2919->timer = v3678;
  int * v2922 = v2919->regs;
  int v2923 = v2922[24];
  int * v2924 = v2919->regs;
  int v2925 = v2924[16];
  int * v2926 = v2919->regs;
  int v3685 = v2923 + v2925;
  v2926[8] = v3685;
  struct StateT * v3676 = v2928(v2919);
  return v3676;
}

struct StateT * v705(struct StateT * v706) {
  int v707 = v706->timer;
  int v1494 = v707 + 1;
  v706->timer = v1494;
  int * v709 = v706->regs;
  int v710 = v709[6];
  int * v711 = v706->regs;
  int v1498 = v710 + 1134;
  v711[6] = v1498;
  struct StateT * v1492 = v713(v706);
  return v1492;
}

struct StateT * v2628(struct StateT * v2629) {
  int v2630 = v2629->timer;
  int v4016 = v2630 + 1;
  v2629->timer = v4016;
  int * v2632 = v2629->regs;
  int v2633 = v2632[16];
  int * v2634 = v2629->regs;
  int v2635 = v2634[5];
  int * v2636 = v2629->regs;
  int v4022 = v2633 | v2635;
  v2636[16] = v4022;
  struct StateT * v4014 = v2638(v2629);
  return v4014;
}

struct StateT * v2306(struct StateT * v2307) {
  int v2308 = v2307->timer;
  int v4391 = v2308 + 1;
  v2307->timer = v4391;
  int * v2310 = v2307->regs;
  int v2311 = v2310[23];
  int * v2312 = v2307->regs;
  int v2313 = v2312[8];
  int * v2314 = v2307->regs;
  int v4397 = v2311 ^ v2313;
  v2314[23] = v4397;
  struct StateT * v4389 = v2316(v2307);
  return v4389;
}

struct StateT * v2142(struct StateT * v2143) {
  int v2144 = v2143->timer;
  int v4583 = v2144 + 1;
  v2143->timer = v4583;
  int * v2146 = v2143->regs;
  int v2147 = v2146[25];
  int * v2148 = v2143->regs;
  int v2149 = v2148[18];
  int * v2150 = v2143->regs;
  int v4589 = v2147 ^ v2149;
  v2150[25] = v4589;
  struct StateT * v4581 = v2152(v2143);
  return v4581;
}

struct StateT * v79(struct StateT * v80) {
  int v81 = v80->timer;
  int v5469 = v81 + 1;
  v80->timer = v5469;
  int * v83 = v80->regs;
  int v84 = v83[2];
  int * v85 = v80->regs;
  int v86 = v85[22];
  int * v87 = v80->mem;
  int v5475 = (int)((unsigned int)(v84 + 64) >> 2);
  v87[v5475] = v86;
  struct StateT * v5467 = v89(v80);
  return v5467;
}

struct StateT * v879(struct StateT * v880) {
  int v881 = v880->timer;
  int v1288 = v881 + 1;
  v880->timer = v1288;
  int * v883 = v880->regs;
  int v884 = v883[10];
  int * v885 = v880->regs;
  int v886 = v885[17];
  int * v887 = v880->mem;
  int v1294 = (int)((unsigned int)(v884 + 44) >> 2);
  v887[v1294] = v886;
  struct StateT * v1286 = v889(v880);
  return v1286;
}

struct StateT * v2684(struct StateT * v2685) {
  int v2686 = v2685->timer;
  int v3950 = v2686 + 1;
  v2685->timer = v3950;
  int * v2688 = v2685->regs;
  int v2689 = v2688[8];
  int * v2690 = v2685->regs;
  int v2691 = v2690[16];
  int * v2692 = v2685->regs;
  int v3957 = v2689 ^ v2691;
  v2692[17] = v3957;
  struct StateT * v3948 = v2694(v2685);
  return v3948;
}

struct StateT * v2172(struct StateT * v2173) {
  int v2174 = v2173->timer;
  int v4547 = v2174 + 1;
  v2173->timer = v4547;
  int * v2176 = v2173->regs;
  int v2177 = v2176[27];
  int * v2178 = v2173->regs;
  int v2179 = v2178[1];
  int * v2180 = v2173->regs;
  int v4554 = v2177 + v2179;
  v2180[9] = v4554;
  struct StateT * v4545 = v2182(v2173);
  return v4545;
}

struct StateT * v721(struct StateT * v722) {
  int v723 = v722->timer;
  int v1476 = v723 + 1;
  v722->timer = v1476;
  int * v725 = v722->regs;
  int v726 = v725[30];
  int * v727 = v722->regs;
  int v1480 = v726 + 1396;
  v727[30] = v1480;
  struct StateT * v1474 = v729(v722);
  return v1474;
}

struct StateT * v265(struct StateT * v266) {
  int v267 = v266->timer;
  int v5249 = v267 + 1;
  v266->timer = v5249;
  int * v269 = v266->regs;
  v269[12] = 1634762752;
  struct StateT * v5247 = v271(v266);
  return v5247;
}

struct StateT * v2928(struct StateT * v2929) {
  int v2930 = v2929->timer;
  int v3668 = v2930 + 1;
  v2929->timer = v3668;
  int * v2932 = v2929->regs;
  int v2933 = v2932[11];
  int * v2934 = v2929->regs;
  int v3673 = (int)((unsigned int)v2933 >> 19);
  v2934[9] = v3673;
  struct StateT * v3666 = v2936(v2929);
  return v3666;
}

struct StateT * v299(struct StateT * v300) {
  int v301 = v300->timer;
  int v5203 = v301 + 1;
  v300->timer = v5203;
  int * v303 = v300->regs;
  int v304 = v303[14];
  int * v305 = v300->regs;
  int v5208 = v304 + -718;
  v305[19] = v5208;
  struct StateT * v5201 = v307(v300);
  return v5201;
}

struct StateT * v2714(struct StateT * v2715) {
  int v2716 = v2715->timer;
  int v3914 = v2716 + 1;
  v2715->timer = v3914;
  int * v2718 = v2715->regs;
  int v2719 = v2718[5];
  int * v2720 = v2715->regs;
  int v2721 = v2720[20];
  int * v2722 = v2715->regs;
  int v3921 = v2719 + v2721;
  v2722[15] = v3921;
  struct StateT * v3912 = v2724(v2715);
  return v3912;
}

struct StateT * v2218(struct StateT * v2219) {
  int v2220 = v2219->timer;
  int v4495 = v2220 + 1;
  v2219->timer = v4495;
  int * v2222 = v2219->regs;
  int v2223 = v2222[8];
  int * v2224 = v2219->regs;
  int v4500 = (int)((unsigned int)v2223 >> 19);
  v2224[20] = v4500;
  struct StateT * v4493 = v2226(v2219);
  return v4493;
}

struct StateT * v713(struct StateT * v714) {
  int v715 = v714->timer;
  int v1485 = v715 + 1;
  v714->timer = v1485;
  int * v717 = v714->regs;
  int v718 = v717[7];
  int * v719 = v714->regs;
  int v1489 = v718 + -718;
  v719[7] = v1489;
  struct StateT * v1483 = v721(v714);
  return v1483;
}

struct StateT * v1049(struct StateT * v1050) {
  int v1051 = v1050->timer;
  int v1084 = v1051 + 1;
  v1050->timer = v1084;
  int * v1053 = v1050->regs;
  int v1054 = v1053[2];
  int * v1055 = v1050->mem;
  int v1088 = (int)((unsigned int)(v1054 + 44) >> 2);
  int v1056 = v1055[v1088];
  int * v1057 = v1050->regs;
  v1057[27] = v1056;
  struct StateT * v1082 = v1059(v1050);
  return v1082;
}

struct StateT * v2612(struct StateT * v2613) {
  int v2614 = v2613->timer;
  int v4036 = v2614 + 1;
  v2613->timer = v4036;
  int * v2616 = v2613->regs;
  int v2617 = v2616[16];
  int * v2618 = v2613->regs;
  int v4041 = (int)((unsigned int)v2617 >> 25);
  v2618[5] = v4041;
  struct StateT * v4034 = v2620(v2613);
  return v4034;
}

struct StateT * v2796(struct StateT * v2797) {
  int v2798 = v2797->timer;
  int v3820 = v2798 + 1;
  v2797->timer = v3820;
  int * v2800 = v2797->regs;
  int v2801 = v2800[6];
  int * v2802 = v2797->regs;
  int v3825 = (int)((unsigned int)v2801 >> 23);
  v2802[9] = v3825;
  struct StateT * v3818 = v2804(v2797);
  return v3818;
}

struct StateT * v271(struct StateT * v272) {
  int v273 = v272->timer;
  int v5241 = v273 + 1;
  v272->timer = v5241;
  int * v275 = v272->regs;
  v275[13] = 857759744;
  struct StateT * v5239 = v277(v272);
  return v5239;
}

struct StateT * v1067(struct StateT * v1068) {
  int v1069 = v1068->timer;
  int v1072 = v1069 + 1;
  v1068->timer = v1072;
  return v1068;
}

struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v5541 = v21 + 1;
  v20->timer = v5541;
  int * v23 = v20->regs;
  int v24 = v23[2];
  int * v25 = v20->regs;
  int v26 = v25[8];
  int * v27 = v20->mem;
  int v5547 = (int)((unsigned int)(v24 + 88) >> 2);
  v27[v5547] = v26;
  struct StateT * v5539 = v29(v20);
  return v5539;
}

struct StateT * v535(struct StateT * v536) {
  int v537 = v536->timer;
  int v1689 = v537 + 1;
  v536->timer = v1689;
  int * v539 = v536->regs;
  int v540 = v539[5];
  int * v541 = v536->regs;
  int v542 = v541[7];
  int * v543 = v536->regs;
  int v1695 = v540 + v542;
  v543[5] = v1695;
  struct StateT * v1687 = v545(v536);
  return v1687;
}

struct StateT * v2034(struct StateT * v2035) {
  int v2036 = v2035->timer;
  int v4707 = v2036 + 1;
  v2035->timer = v4707;
  int * v2038 = v2035->regs;
  int v2039 = v2038[8];
  int * v2040 = v2035->regs;
  int v4712 = (int)((unsigned int)v2039 >> 23);
  v2040[20] = v4712;
  struct StateT * v4705 = v2042(v2035);
  return v4705;
}

struct StateT * v109(struct StateT * v110) {
  int v111 = v110->timer;
  int v5433 = v111 + 1;
  v110->timer = v5433;
  int * v113 = v110->regs;
  int v114 = v113[2];
  int * v115 = v110->regs;
  int v116 = v115[25];
  int * v117 = v110->mem;
  int v5439 = (int)((unsigned int)(v114 + 52) >> 2);
  v117[v5439] = v116;
  struct StateT * v5431 = v119(v110);
  return v5431;
}

struct StateT * v2436(struct StateT * v2437) {
  int v2438 = v2437->timer;
  int v4240 = v2438 + 1;
  v2437->timer = v4240;
  int * v2440 = v2437->regs;
  int v2441 = v2440[17];
  int * v2442 = v2437->regs;
  int v4244 = v2441 << 18;
  v2442[17] = v4244;
  struct StateT * v4238 = v2444(v2437);
  return v4238;
}

struct StateT * v387(struct StateT * v388) {
  int v389 = v388->timer;
  int v5094 = v389 + 1;
  v388->timer = v5094;
  int * v391 = v388->regs;
  int v392 = v391[2];
  int * v393 = v388->regs;
  int v394 = v393[17];
  int * v395 = v388->mem;
  int v5100 = (int)((unsigned int)(v392 + 28) >> 2);
  v395[v5100] = v394;
  struct StateT * v5092 = v397(v388);
  return v5092;
}

struct StateT * v2770(struct StateT * v2771) {
  int v2772 = v2771->timer;
  int v3850 = v2772 + 1;
  v2771->timer = v3850;
  int * v2774 = v2771->regs;
  int v2775 = v2774[15];
  int * v2776 = v2771->regs;
  int v3855 = (int)((unsigned int)v2775 >> 23);
  v2776[9] = v3855;
  struct StateT * v3848 = v2778(v2771);
  return v3848;
}

struct StateT * v1958(struct StateT * v1959) {
  int v1960 = v1959->timer;
  int v4795 = v1960 + 1;
  v1959->timer = v4795;
  int * v1962 = v1959->regs;
  int v1963 = v1962[14];
  int * v1964 = v1959->regs;
  int v1965 = v1964[8];
  int * v1966 = v1959->regs;
  int v4801 = v1963 ^ v1965;
  v1966[14] = v4801;
  struct StateT * v4793 = v1968(v1959);
  return v4793;
}

struct StateT * v691(struct StateT * v692) {
  int v693 = v692->timer;
  int v1512 = v693 + 1;
  v692->timer = v1512;
  int * v695 = v692->regs;
  v695[30] = 1797283840;
  struct StateT * v1510 = v697(v692);
  return v1510;
}

struct StateT * v3014(struct StateT * v3015) {
  int v3016 = v3015->timer;
  int v3569 = v3016 + 1;
  v3015->timer = v3569;
  int * v3018 = v3015->regs;
  int v3019 = v3018[8];
  int * v3020 = v3015->regs;
  int v3573 = v3019 << 13;
  v3020[8] = v3573;
  struct StateT * v3567 = v3022(v3015);
  return v3567;
}

struct StateT * v3052(struct StateT * v3053) {
  int v3054 = v3053->timer;
  int v3525 = v3054 + 1;
  v3053->timer = v3525;
  int * v3056 = v3053->regs;
  int v3057 = v3056[13];
  int * v3058 = v3053->regs;
  int v3059 = v3058[6];
  int * v3060 = v3053->regs;
  int v3531 = v3057 ^ v3059;
  v3060[13] = v3531;
  struct StateT * v3523 = v3062(v3053);
  return v3523;
}

struct StateT * v2936(struct StateT * v2937) {
  int v2938 = v2937->timer;
  int v3659 = v2938 + 1;
  v2937->timer = v3659;
  int * v2940 = v2937->regs;
  int v2941 = v2940[11];
  int * v2942 = v2937->regs;
  int v3663 = v2941 << 13;
  v2942[11] = v3663;
  struct StateT * v3657 = v2944(v2937);
  return v3657;
}

struct StateT * v3072(struct StateT * v3073) {
  int v3074 = v3073->timer;
  int v3502 = v3074 + 1;
  v3073->timer = v3502;
  int * v3076 = v3073->regs;
  int v3077 = v3076[14];
  int * v3078 = v3073->regs;
  int v3079 = v3078[27];
  int * v3080 = v3073->regs;
  int v3509 = v3077 + v3079;
  v3080[11] = v3509;
  struct StateT * v3500 = v3082(v3073);
  return v3500;
}

struct StateT * v959(struct StateT * v960) {
  int v961 = v960->timer;
  int v1192 = v961 + 1;
  v960->timer = v1192;
  int * v963 = v960->regs;
  int v964 = v963[2];
  int * v965 = v960->mem;
  int v1196 = (int)((unsigned int)(v964 + 80) >> 2);
  int v966 = v965[v1196];
  int * v967 = v960->regs;
  v967[18] = v966;
  struct StateT * v1190 = v969(v960);
  return v1190;
}

struct StateT * v1039(struct StateT * v1040) {
  int v1041 = v1040->timer;
  int v1096 = v1041 + 1;
  v1040->timer = v1096;
  int * v1043 = v1040->regs;
  int v1044 = v1043[2];
  int * v1045 = v1040->mem;
  int v1100 = (int)((unsigned int)(v1044 + 48) >> 2);
  int v1046 = v1045[v1100];
  int * v1047 = v1040->regs;
  v1047[26] = v1046;
  struct StateT * v1094 = v1049(v1040);
  return v1094;
}

struct StateT * v2050(struct StateT * v2051) {
  int v2052 = v2051->timer;
  int v4687 = v2052 + 1;
  v2051->timer = v4687;
  int * v2054 = v2051->regs;
  int v2055 = v2054[8];
  int * v2056 = v2051->regs;
  int v2057 = v2056[20];
  int * v2058 = v2051->regs;
  int v4693 = v2055 | v2057;
  v2058[8] = v4693;
  struct StateT * v4685 = v2060(v2051);
  return v4685;
}

struct StateT * v1968(struct StateT * v1969) {
  int v1970 = v1969->timer;
  int v4783 = v1970 + 1;
  v1969->timer = v4783;
  int * v1972 = v1969->regs;
  int v1973 = v1972[12];
  int * v1974 = v1969->regs;
  int v1975 = v1974[21];
  int * v1976 = v1969->regs;
  int v4790 = v1973 + v1975;
  v1976[15] = v4790;
  struct StateT * v4781 = v1978(v1969);
  return v4781;
}

struct StateT * v49(struct StateT * v50) {
  int v51 = v50->timer;
  int v5505 = v51 + 1;
  v50->timer = v5505;
  int * v53 = v50->regs;
  int v54 = v53[2];
  int * v55 = v50->regs;
  int v56 = v55[19];
  int * v57 = v50->mem;
  int v5511 = (int)((unsigned int)(v54 + 76) >> 2);
  v57[v5511] = v56;
  struct StateT * v5503 = v59(v50);
  return v5503;
}

struct StateT * v1832(struct StateT * v1833) {
  int v1834 = v1833->timer;
  int v4940 = v1834 + 1;
  v1833->timer = v4940;
  int * v1836 = v1833->regs;
  int v1837 = v1836[15];
  int * v1838 = v1833->regs;
  int v4944 = v1837 << 7;
  v1838[15] = v4944;
  struct StateT * v4938 = v1840(v1833);
  return v4938;
}

struct StateT * v2540(struct StateT * v2541) {
  int v2542 = v2541->timer;
  int v4118 = v2542 + 1;
  v2541->timer = v4118;
  int * v2544 = v2541->regs;
  int v2545 = v2544[19];
  int * v2546 = v2541->regs;
  int v2547 = v2546[13];
  int * v2548 = v2541->regs;
  int v4125 = v2545 + v2547;
  v2548[16] = v4125;
  struct StateT * v4116 = v2550(v2541);
  return v4116;
}

struct StateT * v1998(struct StateT * v1999) {
  int v2000 = v1999->timer;
  int v4747 = v2000 + 1;
  v1999->timer = v4747;
  int * v2002 = v1999->regs;
  int v2003 = v2002[14];
  int * v2004 = v1999->regs;
  int v2005 = v2004[22];
  int * v2006 = v1999->regs;
  int v4754 = v2003 + v2005;
  v2006[18] = v4754;
  struct StateT * v4745 = v2008(v1999);
  return v4745;
}

struct StateT * v357(struct StateT * v358) {
  int v359 = v358->timer;
  int v5130 = v359 + 1;
  v358->timer = v5130;
  int * v361 = v358->regs;
  int v362 = v361[2];
  int * v363 = v358->regs;
  int v364 = v363[1];
  int * v365 = v358->mem;
  int v5136 = (int)((unsigned int)(v362 + 40) >> 2);
  v365[v5136] = v364;
  struct StateT * v5128 = v367(v358);
  return v5128;
}

struct StateT * v175(struct StateT * v176) {
  int v177 = v176->timer;
  int v5353 = v177 + 1;
  v176->timer = v5353;
  int * v179 = v176->regs;
  int v180 = v179[12];
  int * v181 = v176->mem;
  int v5357 = (int)((unsigned int)(v180 + 12) >> 2);
  int v182 = v181[v5357];
  int * v183 = v176->regs;
  v183[6] = v182;
  struct StateT * v5351 = v185(v176);
  return v5351;
}

struct StateT * v2042(struct StateT * v2043) {
  int v2044 = v2043->timer;
  int v4698 = v2044 + 1;
  v2043->timer = v4698;
  int * v2046 = v2043->regs;
  int v2047 = v2046[8];
  int * v2048 = v2043->regs;
  int v4702 = v2047 << 9;
  v2048[8] = v4702;
  struct StateT * v4696 = v2050(v2043);
  return v4696;
}

struct StateT * v255(struct StateT * v256) {
  int v257 = v256->timer;
  int v5257 = v257 + 1;
  v256->timer = v5257;
  int * v259 = v256->regs;
  int v260 = v259[11];
  int * v261 = v256->mem;
  int v5261 = (int)((unsigned int)(v260 + 12) >> 2);
  int v262 = v261[v5261];
  int * v263 = v256->regs;
  v263[15] = v262;
  struct StateT * v5255 = v265(v256);
  return v5255;
}

struct StateT * v2182(struct StateT * v2183) {
  int v2184 = v2183->timer;
  int v4535 = v2184 + 1;
  v2183->timer = v4535;
  int * v2186 = v2183->regs;
  int v2187 = v2186[25];
  int * v2188 = v2183->regs;
  int v2189 = v2188[14];
  int * v2190 = v2183->regs;
  int v4542 = v2187 + v2189;
  v2190[18] = v4542;
  struct StateT * v4533 = v2192(v2183);
  return v4533;
}

struct StateT * v2520(struct StateT * v2521) {
  int v2522 = v2521->timer;
  int v4142 = v2522 + 1;
  v2521->timer = v4142;
  int * v2524 = v2521->regs;
  int v2525 = v2524[21];
  int * v2526 = v2521->regs;
  int v2527 = v2526[14];
  int * v2528 = v2521->regs;
  int v4149 = v2525 + v2527;
  v2528[15] = v4149;
  struct StateT * v4140 = v2530(v2521);
  return v4140;
}

struct StateT * v205(struct StateT * v206) {
  int v207 = v206->timer;
  int v5317 = v207 + 1;
  v206->timer = v5317;
  int * v209 = v206->regs;
  int v210 = v209[12];
  int * v211 = v206->mem;
  int v5321 = (int)((unsigned int)(v210 + 24) >> 2);
  int v212 = v211[v5321];
  int * v213 = v206->regs;
  v213[24] = v212;
  struct StateT * v5315 = v215(v206);
  return v5315;
}

struct StateT * v423(struct StateT * v424) {
  int v425 = v424->timer;
  int v5052 = v425 + 1;
  v424->timer = v5052;
  int * v427 = v424->regs;
  int v428 = v427[28];
  int * v429 = v424->regs;
  v429[27] = v428;
  struct StateT * v5050 = v431(v424);
  return v5050;
}

struct StateT * v2530(struct StateT * v2531) {
  int v2532 = v2531->timer;
  int v4130 = v2532 + 1;
  v2531->timer = v4130;
  int * v2534 = v2531->regs;
  int v2535 = v2534[20];
  int * v2536 = v2531->regs;
  int v2537 = v2536[12];
  int * v2538 = v2531->regs;
  int v4137 = v2535 + v2537;
  v2538[11] = v4137;
  struct StateT * v4128 = v2540(v2531);
  return v4128;
}

struct StateT * v377(struct StateT * v378) {
  int v379 = v378->timer;
  int v5106 = v379 + 1;
  v378->timer = v5106;
  int * v381 = v378->regs;
  int v382 = v381[2];
  int * v383 = v378->regs;
  int v384 = v383[16];
  int * v385 = v378->mem;
  int v5112 = (int)((unsigned int)(v382 + 32) >> 2);
  v385[v5112] = v384;
  struct StateT * v5104 = v387(v378);
  return v5104;
}

struct StateT * v2980(struct StateT * v2981) {
  int v2982 = v2981->timer;
  int v3608 = v2982 + 1;
  v2981->timer = v3608;
  int * v2984 = v2981->regs;
  int v2985 = v2984[6];
  int * v2986 = v2981->regs;
  int v3613 = (int)((unsigned int)v2985 >> 19);
  v2986[9] = v3613;
  struct StateT * v3606 = v2988(v2981);
  return v3606;
}

struct StateT * v681(struct StateT * v682) {
  int v683 = v682->timer;
  int v1520 = v683 + 1;
  v682->timer = v1520;
  int * v685 = v682->regs;
  int v686 = v685[1];
  int * v687 = v682->regs;
  int v688 = v687[30];
  int * v689 = v682->regs;
  int v1526 = v686 + v688;
  v689[1] = v1526;
  struct StateT * v1518 = v691(v682);
  return v1518;
}

struct StateT * v3206(struct StateT * v3207) {
  int v3208 = v3207->timer;
  int v3346 = v3208 + 1;
  v3207->timer = v3346;
  int * v3210 = v3207->regs;
  int v3211 = v3210[8];
  int * v3212 = v3207->regs;
  int v3213 = v3212[9];
  int * v3214 = v3207->regs;
  int v3352 = v3211 | v3213;
  v3214[8] = v3352;
  struct StateT * v3344 = v3216(v3207);
  return v3344;
}

struct StateT * v759(struct StateT * v760) {
  int v761 = v760->timer;
  int v1432 = v761 + 1;
  v760->timer = v1432;
  int * v763 = v760->regs;
  int v764 = v763[22];
  int * v765 = v760->regs;
  int v766 = v765[30];
  int * v767 = v760->regs;
  int v1438 = v764 + v766;
  v767[30] = v1438;
  struct StateT * v1430 = v769(v760);
  return v1430;
}

struct StateT * v2094(struct StateT * v2095) {
  int v2096 = v2095->timer;
  int v4638 = v2096 + 1;
  v2095->timer = v4638;
  int * v2098 = v2095->regs;
  int v2099 = v2098[18];
  int * v2100 = v2095->regs;
  int v4642 = v2099 << 9;
  v2100[18] = v4642;
  struct StateT * v4636 = v2102(v2095);
  return v4636;
}

struct StateT * v2316(struct StateT * v2317) {
  int v2318 = v2317->timer;
  int v4379 = v2318 + 1;
  v2317->timer = v4379;
  int * v2320 = v2317->regs;
  int v2321 = v2320[5];
  int * v2322 = v2317->regs;
  int v2323 = v2322[20];
  int * v2324 = v2317->regs;
  int v4386 = v2321 ^ v2323;
  v2324[18] = v4386;
  struct StateT * v4377 = v2326(v2317);
  return v4377;
}

struct StateT * v367(struct StateT * v368) {
  int v369 = v368->timer;
  int v5118 = v369 + 1;
  v368->timer = v5118;
  int * v371 = v368->regs;
  int v372 = v371[2];
  int * v373 = v368->regs;
  int v374 = v373[24];
  int * v375 = v368->mem;
  int v5124 = (int)((unsigned int)(v372 + 36) >> 2);
  v375[v5124] = v374;
  struct StateT * v5116 = v377(v368);
  return v5116;
}

struct StateT * v185(struct StateT * v186) {
  int v187 = v186->timer;
  int v5341 = v187 + 1;
  v186->timer = v5341;
  int * v189 = v186->regs;
  int v190 = v189[12];
  int * v191 = v186->mem;
  int v5345 = (int)((unsigned int)(v190 + 16) >> 2);
  int v192 = v191[v5345];
  int * v193 = v186->regs;
  v193[17] = v192;
  struct StateT * v5339 = v195(v186);
  return v5339;
}

struct StateT * v2858(struct StateT * v2859) {
  int v2860 = v2859->timer;
  int v3748 = v2860 + 1;
  v2859->timer = v3748;
  int * v2862 = v2859->regs;
  int v2863 = v2862[25];
  int * v2864 = v2859->regs;
  int v2865 = v2864[15];
  int * v2866 = v2859->regs;
  int v3754 = v2863 ^ v2865;
  v2866[25] = v3754;
  struct StateT * v3746 = v2868(v2859);
  return v3746;
}

struct StateT * v415(struct StateT * v416) {
  int v417 = v416->timer;
  int v5062 = v417 + 1;
  v416->timer = v5062;
  int * v419 = v416->regs;
  int v420 = v419[7];
  int * v421 = v416->regs;
  v421[14] = v420;
  struct StateT * v5060 = v423(v416);
  return v5060;
}

struct StateT * v671(struct StateT * v672) {
  int v673 = v672->timer;
  int v1531 = v673 + 1;
  v672->timer = v1531;
  int * v675 = v672->regs;
  int v676 = v675[2];
  int * v677 = v672->mem;
  int v1535 = (int)((unsigned int)(v676 + 40) >> 2);
  int v678 = v677[v1535];
  int * v679 = v672->regs;
  v679[30] = v678;
  struct StateT * v1529 = v681(v672);
  return v1529;
}

struct StateT * v2888(struct StateT * v2889) {
  int v2890 = v2889->timer;
  int v3714 = v2890 + 1;
  v2889->timer = v3714;
  int * v2892 = v2889->regs;
  int v2893 = v2892[27];
  int * v2894 = v2889->regs;
  int v2895 = v2894[23];
  int * v2896 = v2889->regs;
  int v3721 = v2893 + v2895;
  v2896[11] = v3721;
  struct StateT * v3712 = v2898(v2889);
  return v3712;
}

struct StateT * v2086(struct StateT * v2087) {
  int v2088 = v2087->timer;
  int v4647 = v2088 + 1;
  v2087->timer = v4647;
  int * v2090 = v2087->regs;
  int v2091 = v2090[18];
  int * v2092 = v2087->regs;
  int v4652 = (int)((unsigned int)v2091 >> 23);
  v2092[20] = v4652;
  struct StateT * v4645 = v2094(v2087);
  return v4645;
}

struct StateT * v2500(struct StateT * v2501) {
  int v2502 = v2501->timer;
  int v4165 = v2502 + 1;
  v2501->timer = v4165;
  int * v2504 = v2501->regs;
  int v2505 = v2504[19];
  int * v2506 = v2501->regs;
  int v2507 = v2506[17];
  int * v2508 = v2501->regs;
  int v4171 = v2505 ^ v2507;
  v2508[19] = v4171;
  struct StateT * v4163 = v2510(v2501);
  return v4163;
}

struct StateT * v2226(struct StateT * v2227) {
  int v2228 = v2227->timer;
  int v4486 = v2228 + 1;
  v2227->timer = v4486;
  int * v2230 = v2227->regs;
  int v2231 = v2230[8];
  int * v2232 = v2227->regs;
  int v4490 = v2231 << 13;
  v2232[8] = v4490;
  struct StateT * v4484 = v2234(v2227);
  return v4484;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v5553 = v11 + 1;
  v10->timer = v5553;
  int * v13 = v10->regs;
  int v14 = v13[2];
  int * v15 = v10->regs;
  int v16 = v15[1];
  int * v17 = v10->mem;
  int v5559 = (int)((unsigned int)(v14 + 92) >> 2);
  v17[v5559] = v16;
  struct StateT * v5551 = v19(v10);
  return v5551;
}

struct StateT * v235(struct StateT * v236) {
  int v237 = v236->timer;
  int v5281 = v237 + 1;
  v236->timer = v5281;
  int * v239 = v236->regs;
  int v240 = v239[11];
  int * v241 = v236->mem;
  int v5285 = (int)((unsigned int)(v240 + 4) >> 2);
  int v242 = v241[v5285];
  int * v243 = v236->regs;
  v243[25] = v242;
  struct StateT * v5279 = v245(v236);
  return v5279;
}

struct StateT * v2200(struct StateT * v2201) {
  int v2202 = v2201->timer;
  int v4516 = v2202 + 1;
  v2201->timer = v4516;
  int * v2204 = v2201->regs;
  int v2205 = v2204[15];
  int * v2206 = v2201->regs;
  int v4520 = v2205 << 13;
  v2206[15] = v4520;
  struct StateT * v4514 = v2208(v2201);
  return v4514;
}

struct StateT * v575(struct StateT * v576) {
  int v577 = v576->timer;
  int v1643 = v577 + 1;
  v576->timer = v1643;
  int * v579 = v576->regs;
  int v580 = v579[26];
  int * v581 = v576->regs;
  int v582 = v581[7];
  int * v583 = v576->regs;
  int v1649 = v580 + v582;
  v583[26] = v1649;
  struct StateT * v1641 = v585(v576);
  return v1641;
}

struct StateT * v139(struct StateT * v140) {
  int v141 = v140->timer;
  int v5401 = v141 + 1;
  v140->timer = v5401;
  int * v143 = v140->regs;
  v143[30] = 0;
  struct StateT * v5399 = v145(v140);
  return v5399;
}

struct StateT * v789(struct StateT * v790) {
  int v791 = v790->timer;
  int v1396 = v791 + 1;
  v790->timer = v1396;
  int * v793 = v790->regs;
  int v794 = v793[10];
  int * v795 = v790->regs;
  int v796 = v795[28];
  int * v797 = v790->mem;
  int v1402 = (int)((unsigned int)(v794 + 8) >> 2);
  v797[v1402] = v796;
  struct StateT * v1394 = v799(v790);
  return v1394;
}

struct StateT * v3180(struct StateT * v3181) {
  int v3182 = v3181->timer;
  int v3376 = v3182 + 1;
  v3181->timer = v3376;
  int * v3184 = v3181->regs;
  int v3185 = v3184[6];
  int * v3186 = v3181->regs;
  int v3187 = v3186[9];
  int * v3188 = v3181->regs;
  int v3382 = v3185 | v3187;
  v3188[6] = v3382;
  struct StateT * v3374 = v3190(v3181);
  return v3374;
}

struct StateT * v1918(struct StateT * v1919) {
  int v1920 = v1919->timer;
  int v4839 = v1920 + 1;
  v1919->timer = v4839;
  int * v1922 = v1919->regs;
  int v1923 = v1922[8];
  int * v1924 = v1919->regs;
  int v1925 = v1924[20];
  int * v1926 = v1919->regs;
  int v4845 = v1923 | v1925;
  v1926[8] = v4845;
  struct StateT * v4837 = v1928(v1919);
  return v4837;
}

struct StateT * v2336(struct StateT * v2337) {
  int v2338 = v2337->timer;
  int v4355 = v2338 + 1;
  v2337->timer = v4355;
  int * v2340 = v2337->regs;
  int v2341 = v2340[9];
  int * v2342 = v2337->regs;
  int v2343 = v2342[26];
  int * v2344 = v2337->regs;
  int v4362 = v2341 + v2343;
  v2344[15] = v4362;
  struct StateT * v4353 = v2346(v2337);
  return v4353;
}

struct StateT * v407(struct StateT * v408) {
  int v409 = v408->timer;
  int v5072 = v409 + 1;
  v408->timer = v5072;
  int * v411 = v408->regs;
  int v412 = v411[6];
  int * v413 = v408->regs;
  v413[12] = v412;
  struct StateT * v5070 = v415(v408);
  return v5070;
}

struct StateT * v2068(struct StateT * v2069) {
  int v2070 = v2069->timer;
  int v4668 = v2070 + 1;
  v2069->timer = v4668;
  int * v2072 = v2069->regs;
  int v2073 = v2072[9];
  int * v2074 = v2069->regs;
  int v4672 = v2073 << 9;
  v2074[9] = v4672;
  struct StateT * v4666 = v2076(v2069);
  return v4666;
}

struct StateT * v277(struct StateT * v278) {
  int v279 = v278->timer;
  int v5233 = v279 + 1;
  v278->timer = v5233;
  int * v281 = v278->regs;
  v281[14] = 2036477952;
  struct StateT * v5231 = v283(v278);
  return v5231;
}

struct StateT * v2270(struct StateT * v2271) {
  int v2272 = v2271->timer;
  int v4435 = v2272 + 1;
  v2271->timer = v4435;
  int * v2274 = v2271->regs;
  int v2275 = v2274[18];
  int * v2276 = v2271->regs;
  int v4440 = (int)((unsigned int)v2275 >> 19);
  v2276[9] = v4440;
  struct StateT * v4433 = v2278(v2271);
  return v4433;
}

struct StateT * v431(struct StateT * v432) {
  int v433 = v432->timer;
  int v5042 = v433 + 1;
  v432->timer = v5042;
  int * v435 = v432->regs;
  int v436 = v435[29];
  int * v437 = v432->regs;
  v437[23] = v436;
  struct StateT * v5040 = v439(v432);
  return v5040;
}

struct StateT * v2898(struct StateT * v2899) {
  int v2900 = v2899->timer;
  int v3702 = v2900 + 1;
  v2899->timer = v3702;
  int * v2902 = v2899->regs;
  int v2903 = v2902[25];
  int * v2904 = v2899->regs;
  int v2905 = v2904[5];
  int * v2906 = v2899->regs;
  int v3709 = v2903 + v2905;
  v2906[15] = v3709;
  struct StateT * v3700 = v2908(v2899);
  return v3700;
}

struct StateT * v499(struct StateT * v500) {
  int v501 = v500->timer;
  int v1731 = v501 + 1;
  v500->timer = v1731;
  int * v503 = v500->regs;
  int v504 = v503[2];
  int * v505 = v500->mem;
  int v1735 = (int)((unsigned int)(v504 + 8) >> 2);
  int v506 = v505[v1735];
  int * v507 = v500->regs;
  v507[6] = v506;
  struct StateT * v1729 = v509(v500);
  return v1729;
}

struct StateT * v2674(struct StateT * v2675) {
  int v2676 = v2675->timer;
  int v3962 = v2676 + 1;
  v2675->timer = v3962;
  int * v2678 = v2675->regs;
  int v2679 = v2678[18];
  int * v2680 = v2675->regs;
  int v2681 = v2680[11];
  int * v2682 = v2675->regs;
  int v3969 = v2679 ^ v2681;
  v2682[5] = v3969;
  struct StateT * v3960 = v2684(v2675);
  return v3960;
}

struct StateT * v2760(struct StateT * v2761) {
  int v2762 = v2761->timer;
  int v3860 = v2762 + 1;
  v2761->timer = v3860;
  int * v2764 = v2761->regs;
  int v2765 = v2764[11];
  int * v2766 = v2761->regs;
  int v2767 = v2766[9];
  int * v2768 = v2761->regs;
  int v3866 = v2765 | v2767;
  v2768[11] = v3866;
  struct StateT * v3858 = v2770(v2761);
  return v3858;
}

struct StateT * v2162(struct StateT * v2163) {
  int v2164 = v2163->timer;
  int v4559 = v2164 + 1;
  v2163->timer = v4559;
  int * v2166 = v2163->regs;
  int v2167 = v2166[24];
  int * v2168 = v2163->regs;
  int v2169 = v2168[13];
  int * v2170 = v2163->regs;
  int v4566 = v2167 + v2169;
  v2170[8] = v4566;
  struct StateT * v4557 = v2172(v2163);
  return v4557;
}

struct StateT * v1978(struct StateT * v1979) {
  int v1980 = v1979->timer;
  int v4771 = v1980 + 1;
  v1979->timer = v4771;
  int * v1982 = v1979->regs;
  int v1983 = v1982[13];
  int * v1984 = v1979->regs;
  int v1985 = v1984[11];
  int * v1986 = v1979->regs;
  int v4778 = v1983 + v1985;
  v1986[8] = v4778;
  struct StateT * v4769 = v1988(v1979);
  return v4769;
}

struct StateT * v2878(struct StateT * v2879) {
  int v2880 = v2879->timer;
  int v3726 = v2880 + 1;
  v2879->timer = v3726;
  int * v2882 = v2879->regs;
  int v2883 = v2882[24];
  int * v2884 = v2879->regs;
  int v2885 = v2884[8];
  int * v2886 = v2879->regs;
  int v3732 = v2883 ^ v2885;
  v2886[24] = v3732;
  struct StateT * v3724 = v2888(v2879);
  return v3724;
}

struct StateT * v3154(struct StateT * v3155) {
  int v3156 = v3155->timer;
  int v3406 = v3156 + 1;
  v3155->timer = v3406;
  int * v3158 = v3155->regs;
  int v3159 = v3158[15];
  int * v3160 = v3155->regs;
  int v3161 = v3160[9];
  int * v3162 = v3155->regs;
  int v3412 = v3159 | v3161;
  v3162[15] = v3412;
  struct StateT * v3404 = v3164(v3155);
  return v3404;
}

struct StateT * v1850(struct StateT * v1851) {
  int v1852 = v1851->timer;
  int v4919 = v1852 + 1;
  v1851->timer = v4919;
  int * v1854 = v1851->regs;
  int v1855 = v1854[20];
  int * v1856 = v1851->regs;
  int v4924 = (int)((unsigned int)v1855 >> 25);
  v1856[9] = v4924;
  struct StateT * v4917 = v1858(v1851);
  return v4917;
}

struct StateT * v2252(struct StateT * v2253) {
  int v2254 = v2253->timer;
  int v4456 = v2254 + 1;
  v2253->timer = v4456;
  int * v2256 = v2253->regs;
  int v2257 = v2256[9];
  int * v2258 = v2253->regs;
  int v4460 = v2257 << 13;
  v2258[9] = v4460;
  struct StateT * v4454 = v2260(v2253);
  return v4454;
}

struct StateT * v3042(struct StateT * v3043) {
  int v3044 = v3043->timer;
  int v3536 = v3044 + 1;
  v3043->timer = v3536;
  int * v3046 = v3043->regs;
  int v3047 = v3046[12];
  int * v3048 = v3043->regs;
  int v3049 = v3048[15];
  int * v3050 = v3043->regs;
  int v3542 = v3047 ^ v3049;
  v3050[12] = v3542;
  struct StateT * v3534 = v3052(v3043);
  return v3534;
}

struct StateT * v2454(struct StateT * v2455) {
  int v2456 = v2455->timer;
  int v4219 = v2456 + 1;
  v2455->timer = v4219;
  int * v2458 = v2455->regs;
  int v2459 = v2458[5];
  int * v2460 = v2455->regs;
  int v4224 = (int)((unsigned int)v2459 >> 14);
  v2460[6] = v4224;
  struct StateT * v4217 = v2462(v2455);
  return v4217;
}

struct StateT * v3264(struct StateT * v3265) {
  int v3266 = v3265->timer;
  int v3279 = v3266 + 1;
  v3265->timer = v3279;
  int * v3268 = v3265->regs;
  int v3269 = v3268[31];
  int * v3270 = v3265->regs;
  int v3271 = v3270[30];
  bool v3284 = (v3269 ^ -2147483648) >= (v3271 ^ -2147483648);
  struct StateT * v3277;
  if (v3284) {
    struct StateT * v3273 = v1784(v3265);
    v3277 = v3273;
  } else {
    struct StateT * v3275 = v463(v3265);
    v3277 = v3275;
  }
  return v3277;
}

struct StateT * v129(struct StateT * v130) {
  int v131 = v130->timer;
  int v5409 = v131 + 1;
  v130->timer = v5409;
  int * v133 = v130->regs;
  int v134 = v133[2];
  int * v135 = v130->regs;
  int v136 = v135[27];
  int * v137 = v130->mem;
  int v5415 = (int)((unsigned int)(v134 + 44) >> 2);
  v137[v5415] = v136;
  struct StateT * v5407 = v139(v130);
  return v5407;
}

struct StateT * v3216(struct StateT * v3217) {
  int v3218 = v3217->timer;
  int v3335 = v3218 + 1;
  v3217->timer = v3335;
  int * v3220 = v3217->regs;
  int v3221 = v3220[21];
  int * v3222 = v3217->regs;
  int v3223 = v3222[11];
  int * v3224 = v3217->regs;
  int v3341 = v3221 ^ v3223;
  v3224[21] = v3341;
  struct StateT * v3333 = v3226(v3217);
  return v3333;
}

struct StateT * v2384(struct StateT * v2385) {
  int v2386 = v2385->timer;
  int v4300 = v2386 + 1;
  v2385->timer = v4300;
  int * v2388 = v2385->regs;
  int v2389 = v2388[15];
  int * v2390 = v2385->regs;
  int v4304 = v2389 << 18;
  v2390[15] = v4304;
  struct StateT * v4298 = v2392(v2385);
  return v4298;
}

struct StateT * v3022(struct StateT * v3023) {
  int v3024 = v3023->timer;
  int v3558 = v3024 + 1;
  v3023->timer = v3558;
  int * v3026 = v3023->regs;
  int v3027 = v3026[8];
  int * v3028 = v3023->regs;
  int v3029 = v3028[9];
  int * v3030 = v3023->regs;
  int v3564 = v3027 | v3029;
  v3030[8] = v3564;
  struct StateT * v3556 = v3032(v3023);
  return v3556;
}

struct StateT * v999(struct StateT * v1000) {
  int v1001 = v1000->timer;
  int v1144 = v1001 + 1;
  v1000->timer = v1144;
  int * v1003 = v1000->regs;
  int v1004 = v1003[2];
  int * v1005 = v1000->mem;
  int v1148 = (int)((unsigned int)(v1004 + 64) >> 2);
  int v1006 = v1005[v1148];
  int * v1007 = v1000->regs;
  v1007[22] = v1006;
  struct StateT * v1142 = v1009(v1000);
  return v1142;
}

struct StateT * v439(struct StateT * v440) {
  int v441 = v440->timer;
  int v5030 = v441 + 1;
  v440->timer = v5030;
  int * v443 = v440->regs;
  int v444 = v443[2];
  int * v445 = v440->regs;
  int v446 = v445[15];
  int * v447 = v440->mem;
  int v5036 = (int)((unsigned int)(v444 + 24) >> 2);
  v447[v5036] = v446;
  struct StateT * v5028 = v449(v440);
  return v5028;
}

struct StateT * v3226(struct StateT * v3227) {
  int v3228 = v3227->timer;
  int v3323 = v3228 + 1;
  v3227->timer = v3323;
  int * v3230 = v3227->regs;
  int v3231 = v3230[20];
  int * v3232 = v3227->regs;
  int v3233 = v3232[15];
  int * v3234 = v3227->regs;
  int v3330 = v3231 ^ v3233;
  v3234[11] = v3330;
  struct StateT * v3321 = v3236(v3227);
  return v3321;
}

struct StateT * v565(struct StateT * v566) {
  int v567 = v566->timer;
  int v1654 = v567 + 1;
  v566->timer = v1654;
  int * v569 = v566->regs;
  int v570 = v569[2];
  int * v571 = v566->mem;
  int v1658 = (int)((unsigned int)(v570 + 20) >> 2);
  int v572 = v571[v1658];
  int * v573 = v566->regs;
  v573[7] = v572;
  struct StateT * v1652 = v575(v566);
  return v1652;
}

struct StateT * v809(struct StateT * v810) {
  int v811 = v810->timer;
  int v1372 = v811 + 1;
  v810->timer = v1372;
  int * v813 = v810->regs;
  int v814 = v813[10];
  int * v815 = v810->regs;
  int v816 = v815[12];
  int * v817 = v810->mem;
  int v1378 = (int)((unsigned int)(v814 + 16) >> 2);
  v817[v1378] = v816;
  struct StateT * v1370 = v819(v810);
  return v1370;
}

struct StateT * v889(struct StateT * v890) {
  int v891 = v890->timer;
  int v1276 = v891 + 1;
  v890->timer = v1276;
  int * v893 = v890->regs;
  int v894 = v893[10];
  int * v895 = v890->regs;
  int v896 = v895[16];
  int * v897 = v890->mem;
  int v1282 = (int)((unsigned int)(v894 + 48) >> 2);
  v897[v1282] = v896;
  struct StateT * v1274 = v899(v890);
  return v1274;
}

struct StateT * v545(struct StateT * v546) {
  int v547 = v546->timer;
  int v1677 = v547 + 1;
  v546->timer = v1677;
  int * v549 = v546->regs;
  int v550 = v549[2];
  int * v551 = v546->mem;
  int v1681 = (int)((unsigned int)(v550 + 16) >> 2);
  int v552 = v551[v1681];
  int * v553 = v546->regs;
  v553[7] = v552;
  struct StateT * v1675 = v555(v546);
  return v1675;
}

struct StateT * v3164(struct StateT * v3165) {
  int v3166 = v3165->timer;
  int v3396 = v3166 + 1;
  v3165->timer = v3396;
  int * v3168 = v3165->regs;
  int v3169 = v3168[6];
  int * v3170 = v3165->regs;
  int v3401 = (int)((unsigned int)v3169 >> 14);
  v3170[9] = v3401;
  struct StateT * v3394 = v3172(v3165);
  return v3394;
}

struct StateT * v2192(struct StateT * v2193) {
  int v2194 = v2193->timer;
  int v4525 = v2194 + 1;
  v2193->timer = v4525;
  int * v2196 = v2193->regs;
  int v2197 = v2196[15];
  int * v2198 = v2193->regs;
  int v4530 = (int)((unsigned int)v2197 >> 19);
  v2198[20] = v4530;
  struct StateT * v4523 = v2200(v2193);
  return v4523;
}

struct StateT * v2734(struct StateT * v2735) {
  int v2736 = v2735->timer;
  int v3890 = v2736 + 1;
  v2735->timer = v3890;
  int * v2738 = v2735->regs;
  int v2739 = v2738[16];
  int * v2740 = v2735->regs;
  int v2741 = v2740[22];
  int * v2742 = v2735->regs;
  int v3897 = v2739 + v2741;
  v2742[8] = v3897;
  struct StateT * v3888 = v2744(v2735);
  return v3888;
}

struct StateT * v3062(struct StateT * v3063) {
  int v3064 = v3063->timer;
  int v3514 = v3064 + 1;
  v3063->timer = v3514;
  int * v3066 = v3063->regs;
  int v3067 = v3066[1];
  int * v3068 = v3063->regs;
  int v3069 = v3068[8];
  int * v3070 = v3063->regs;
  int v3520 = v3067 ^ v3069;
  v3070[1] = v3520;
  struct StateT * v3512 = v3072(v3063);
  return v3512;
}

struct StateT * v2152(struct StateT * v2153) {
  int v2154 = v2153->timer;
  int v4571 = v2154 + 1;
  v2153->timer = v4571;
  int * v2156 = v2153->regs;
  int v2157 = v2156[26];
  int * v2158 = v2153->regs;
  int v2159 = v2158[12];
  int * v2160 = v2153->regs;
  int v4578 = v2157 + v2159;
  v2160[15] = v4578;
  struct StateT * v4569 = v2162(v2153);
  return v4569;
}

struct StateT * v2664(struct StateT * v2665) {
  int v2666 = v2665->timer;
  int v3974 = v2666 + 1;
  v2665->timer = v3974;
  int * v2668 = v2665->regs;
  int v2669 = v2668[23];
  int * v2670 = v2665->regs;
  int v2671 = v2670[15];
  int * v2672 = v2665->regs;
  int v3980 = v2669 ^ v2671;
  v2672[23] = v3980;
  struct StateT * v3972 = v2674(v2665);
  return v3972;
}

struct StateT * v1858(struct StateT * v1859) {
  int v1860 = v1859->timer;
  int v4910 = v1860 + 1;
  v1859->timer = v4910;
  int * v1862 = v1859->regs;
  int v1863 = v1862[20];
  int * v1864 = v1859->regs;
  int v4914 = v1863 << 7;
  v1864[20] = v4914;
  struct StateT * v4908 = v1866(v1859);
  return v4908;
}

struct StateT * v2356(struct StateT * v2357) {
  int v2358 = v2357->timer;
  int v4331 = v2358 + 1;
  v2357->timer = v4331;
  int * v2360 = v2357->regs;
  int v2361 = v2360[18];
  int * v2362 = v2357->regs;
  int v2363 = v2362[27];
  int * v2364 = v2357->regs;
  int v4338 = v2361 + v2363;
  v2364[17] = v4338;
  struct StateT * v4329 = v2366(v2357);
  return v4329;
}

struct StateT * v2944(struct StateT * v2945) {
  int v2946 = v2945->timer;
  int v3648 = v2946 + 1;
  v2945->timer = v3648;
  int * v2948 = v2945->regs;
  int v2949 = v2948[11];
  int * v2950 = v2945->regs;
  int v2951 = v2950[9];
  int * v2952 = v2945->regs;
  int v3654 = v2949 | v2951;
  v2952[11] = v3654;
  struct StateT * v3646 = v2954(v2945);
  return v3646;
}

struct StateT * v651(struct StateT * v652) {
  int v653 = v652->timer;
  int v1554 = v653 + 1;
  v652->timer = v1554;
  int * v655 = v652->regs;
  int v656 = v655[2];
  int * v657 = v652->mem;
  int v1558 = (int)((unsigned int)(v656 + 36) >> 2);
  int v658 = v657[v1558];
  int * v659 = v652->regs;
  v659[30] = v658;
  struct StateT * v1552 = v661(v652);
  return v1552;
}

struct StateT * v2112(struct StateT * v2113) {
  int v2114 = v2113->timer;
  int v4616 = v2114 + 1;
  v2113->timer = v4616;
  int * v2116 = v2113->regs;
  int v2117 = v2116[26];
  int * v2118 = v2113->regs;
  int v2119 = v2118[15];
  int * v2120 = v2113->regs;
  int v4622 = v2117 ^ v2119;
  v2120[26] = v4622;
  struct StateT * v4614 = v2122(v2113);
  return v4614;
}

struct StateT * v119(struct StateT * v120) {
  int v121 = v120->timer;
  int v5421 = v121 + 1;
  v120->timer = v5421;
  int * v123 = v120->regs;
  int v124 = v123[2];
  int * v125 = v120->regs;
  int v126 = v125[26];
  int * v127 = v120->mem;
  int v5427 = (int)((unsigned int)(v124 + 48) >> 2);
  v127[v5427] = v126;
  struct StateT * v5419 = v129(v120);
  return v5419;
}

struct StateT * v2418(struct StateT * v2419) {
  int v2420 = v2419->timer;
  int v4259 = v2420 + 1;
  v2419->timer = v4259;
  int * v2422 = v2419->regs;
  int v2423 = v2422[16];
  int * v2424 = v2419->regs;
  int v2425 = v2424[6];
  int * v2426 = v2419->regs;
  int v4265 = v2423 | v2425;
  v2426[16] = v4265;
  struct StateT * v4257 = v2428(v2419);
  return v4257;
}

struct StateT * v155(struct StateT * v156) {
  int v157 = v156->timer;
  int v5377 = v157 + 1;
  v156->timer = v5377;
  int * v159 = v156->regs;
  int v160 = v159[12];
  int * v161 = v156->mem;
  int v5381 = (int)((unsigned int)(v160 + 4) >> 2);
  int v162 = v161[v5381];
  int * v163 = v156->regs;
  v163[28] = v162;
  struct StateT * v5375 = v165(v156);
  return v5375;
}

struct StateT * v3146(struct StateT * v3147) {
  int v3148 = v3147->timer;
  int v3417 = v3148 + 1;
  v3147->timer = v3417;
  int * v3150 = v3147->regs;
  int v3151 = v3150[15];
  int * v3152 = v3147->regs;
  int v3421 = v3151 << 18;
  v3152[15] = v3421;
  struct StateT * v3415 = v3154(v3147);
  return v3415;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v5572 = v1(v0);
  return v5572;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v5565 = v3 + 1;
  v2->timer = v5565;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v5569 = v6 + -96;
  v7[2] = v5569;
  struct StateT * v5563 = v9(v2);
  return v5563;
}

struct StateT * v2024(struct StateT * v2025) {
  int v2026 = v2025->timer;
  int v4717 = v2026 + 1;
  v2025->timer = v4717;
  int * v2028 = v2025->regs;
  int v2029 = v2028[15];
  int * v2030 = v2025->regs;
  int v2031 = v2030[20];
  int * v2032 = v2025->regs;
  int v4723 = v2029 | v2031;
  v2032[15] = v4723;
  struct StateT * v4715 = v2034(v2025);
  return v4715;
}

struct StateT * v2704(struct StateT * v2705) {
  int v2706 = v2705->timer;
  int v3926 = v2706 + 1;
  v2705->timer = v3926;
  int * v2708 = v2705->regs;
  int v2709 = v2708[23];
  int * v2710 = v2705->regs;
  int v2711 = v2710[21];
  int * v2712 = v2705->regs;
  int v3933 = v2709 + v2711;
  v2712[11] = v3933;
  struct StateT * v3924 = v2714(v2705);
  return v3924;
}

struct StateT * v2244(struct StateT * v2245) {
  int v2246 = v2245->timer;
  int v4465 = v2246 + 1;
  v2245->timer = v4465;
  int * v2248 = v2245->regs;
  int v2249 = v2248[9];
  int * v2250 = v2245->regs;
  int v4470 = (int)((unsigned int)v2249 >> 19);
  v2250[20] = v4470;
  struct StateT * v4463 = v2252(v2245);
  return v4463;
}

struct StateT * v1784(struct StateT * v1785) {
  int v1786 = v1785->timer;
  int v4995 = v1786 + 1;
  v1785->timer = v4995;
  int * v1788 = v1785->regs;
  int v1789 = v1788[21];
  int * v1790 = v1785->regs;
  int v1791 = v1790[16];
  int * v1792 = v1785->regs;
  int v5002 = v1789 + v1791;
  v1792[15] = v5002;
  struct StateT * v4993 = v1794(v1785);
  return v4993;
}

struct StateT * v327(struct StateT * v328) {
  int v329 = v328->timer;
  int v5166 = v329 + 1;
  v328->timer = v5166;
  int * v331 = v328->regs;
  int v332 = v331[2];
  int * v333 = v328->regs;
  int v334 = v333[26];
  int * v335 = v328->mem;
  int v5172 = (int)((unsigned int)(v332 + 20) >> 2);
  v335[v5172] = v334;
  struct StateT * v5164 = v337(v328);
  return v5164;
}

struct StateT * v3032(struct StateT * v3033) {
  int v3034 = v3033->timer;
  int v3547 = v3034 + 1;
  v3033->timer = v3547;
  int * v3036 = v3033->regs;
  int v3037 = v3036[14];
  int * v3038 = v3033->regs;
  int v3039 = v3038[11];
  int * v3040 = v3033->regs;
  int v3553 = v3037 ^ v3039;
  v3040[14] = v3553;
  struct StateT * v3545 = v3042(v3033);
  return v3545;
}

struct StateT * v2510(struct StateT * v2511) {
  int v2512 = v2511->timer;
  int v4154 = v2512 + 1;
  v2511->timer = v4154;
  int * v2514 = v2511->regs;
  int v2515 = v2514[22];
  int * v2516 = v2511->regs;
  int v2517 = v2516[5];
  int * v2518 = v2511->regs;
  int v4160 = v2515 ^ v2517;
  v2518[22] = v4160;
  struct StateT * v4152 = v2520(v2511);
  return v4152;
}

struct StateT * v2346(struct StateT * v2347) {
  int v2348 = v2347->timer;
  int v4343 = v2348 + 1;
  v2347->timer = v4343;
  int * v2350 = v2347->regs;
  int v2351 = v2350[23];
  int * v2352 = v2347->regs;
  int v2353 = v2352[24];
  int * v2354 = v2347->regs;
  int v4350 = v2351 + v2353;
  v2354[16] = v4350;
  struct StateT * v4341 = v2356(v2347);
  return v4341;
}

struct StateT * v1928(struct StateT * v1929) {
  int v1930 = v1929->timer;
  int v4828 = v1930 + 1;
  v1929->timer = v4828;
  int * v1932 = v1929->regs;
  int v1933 = v1932[12];
  int * v1934 = v1929->regs;
  int v1935 = v1934[15];
  int * v1936 = v1929->regs;
  int v4834 = v1933 ^ v1935;
  v1936[12] = v4834;
  struct StateT * v4826 = v1938(v1929);
  return v4826;
}

struct StateT * v2830(struct StateT * v2831) {
  int v2832 = v2831->timer;
  int v3781 = v2832 + 1;
  v2831->timer = v3781;
  int * v2834 = v2831->regs;
  int v2835 = v2834[8];
  int * v2836 = v2831->regs;
  int v3785 = v2835 << 9;
  v2836[8] = v3785;
  struct StateT * v3779 = v2838(v2831);
  return v3779;
}

struct StateT * v555(struct StateT * v556) {
  int v557 = v556->timer;
  int v1666 = v557 + 1;
  v556->timer = v1666;
  int * v559 = v556->regs;
  int v560 = v559[25];
  int * v561 = v556->regs;
  int v562 = v561[7];
  int * v563 = v556->regs;
  int v1672 = v560 + v562;
  v563[25] = v1672;
  struct StateT * v1664 = v565(v556);
  return v1664;
}

struct StateT * v849(struct StateT * v850) {
  int v851 = v850->timer;
  int v1324 = v851 + 1;
  v850->timer = v1324;
  int * v853 = v850->regs;
  int v854 = v853[10];
  int * v855 = v850->regs;
  int v856 = v855[26];
  int * v857 = v850->mem;
  int v1330 = (int)((unsigned int)(v854 + 32) >> 2);
  v857[v1330] = v856;
  struct StateT * v1322 = v859(v850);
  return v1322;
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