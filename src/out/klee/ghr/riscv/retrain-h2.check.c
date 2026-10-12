// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 512
#define HISTORY_BITS 2

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[512];
  int timer;
};

void ret_assert(bool);

struct StateG * slot_12(struct StateG * v417);
struct StateG * slot_120(struct StateG * v2424);
struct StateG * slot_43(struct StateG * v950);
struct StateG * slot_70(struct StateG * v1372);
struct StateG * slot_76(struct StateG * v1572);
struct StateG * slot_6(struct StateG * v278);
struct StateG * slot_92(struct StateG * v1868);
struct StateG * slot_55(struct StateG * v1107);
struct StateG * slot_31(struct StateG * v784);
struct StateG * slot_82(struct StateG * v1749);
struct StateG * slot_65(struct StateG * v1272);
struct StateG * slot_10(struct StateG * v396);
struct StateG * slot_74(struct StateG * v1492);
struct StateG * slot_91(struct StateG * v1854);
struct StateG * slot_107(struct StateG * v2084);
struct StateG * slot_136(struct StateG * v2724);
struct StateG * slot_58(struct StateG * v1146);
struct StateG * slot_89(struct StateG * v1826);
struct StateG * slot_66(struct StateG * v1292);
struct StateG * slot_84(struct StateG * v1770);
struct StateG * slot_28(struct StateG * v664);
struct StateG * slot_17(struct StateG * v479);
struct StateG * slot_49(struct StateG * v1029);
struct StateG * slot_50(struct StateG * v1042);
struct StateG * slot_37(struct StateG * v874);
struct StateG * slot_114(struct StateG * v2224);
struct StateG * slot_135(struct StateG * v2710);
struct StateG * slot_68(struct StateG * v1332);
struct StateG * slot_59(struct StateG * v1159);
struct StateG * slot_105(struct StateG * v2044);
struct StateG * slot_40(struct StateG * v908);
struct StateG * slot_27(struct StateG * v644);
struct StateG * slot_15(struct StateG * v452);
struct StateG * slot_48(struct StateG * v1016);
struct StateG * slot_77(struct StateG * v1611);
struct StateG * slot_85(struct StateG * v1778);
struct StateG * slot_75(struct StateG * v1532);
struct StateG * slot_56(struct StateG * v1120);
struct StateG * slot_72(struct StateG * v1412);
struct StateG * slot_34(struct StateG * v845);
struct StateG * slot_119(struct StateG * v2384);
struct StateG * slot_71(struct StateG * v1392);
struct StateG * slot_101(struct StateG * v1985);
struct StateG * slot_108(struct StateG * v2104);
struct StateG * slot_116(struct StateG * v2264);
struct StateG * slot_93(struct StateG * v1881);
struct StateG * slot_88(struct StateG * v1812);
struct StateG * slot_21(struct StateG * v531);
struct StateG * slot_96(struct StateG * v1920);
struct StateG * slot_45(struct StateG * v977);
struct StateG * slot_118(struct StateG * v2344);
struct StateG * slot_69(struct StateG * v1352);
struct StateG * slot_121(struct StateG * v2464);
struct StateG * slot_94(struct StateG * v1894);
struct StateG * slot_63(struct StateG * v1232);
struct StateG * slot_24(struct StateG * v584);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_125(struct StateG * v2592);
struct StateG * slot_102(struct StateG * v1998);
struct StateG * slot_126(struct StateG * v2605);
struct StateG * slot_110(struct StateG * v2144);
struct StateG * slot_79(struct StateG * v1689);
struct StateG * slot_41(struct StateG * v922);
struct StateG * slot_39(struct StateG * v900);
struct StateG * slot_131(struct StateG * v2660);
struct StateG * slot_8(struct StateG * v318);
struct StateG * slot_60(struct StateG * v1172);
struct StateG * slot_112(struct StateG * v2184);
struct StateG * slot_47(struct StateG * v1003);
struct StateG * slot_29(struct StateG * v704);
struct StateG * slot_16(struct StateG * v466);
struct StateG * slot_5(struct StateG * v258);
struct StateG * slot_113(struct StateG * v2204);
struct StateG * slot_104(struct StateG * v2024);
struct StateG * slot_7(struct StateG * v298);
struct StateG * slot_54(struct StateG * v1094);
struct StateG * slot_26(struct StateG * v624);
struct StateG * slot_103(struct StateG * v2011);
struct StateG * slot_19(struct StateG * v505);
struct StateG * slot_87(struct StateG * v1804);
struct StateG * slot_67(struct StateG * v1312);
struct StateG * slot_81(struct StateG * v1736);
struct StateG * slot_64(struct StateG * v1252);
struct StateG * slot_14(struct StateG * v438);
struct StateG * slot_53(struct StateG * v1081);
struct StateG * slot_95(struct StateG * v1907);
struct StateG * slot_80(struct StateG * v1728);
struct StateG * slot_44(struct StateG * v964);
struct StateG * slot_115(struct StateG * v2244);
struct StateG * slot_78(struct StateG * v1650);
struct StateG * slot_32(struct StateG * v824);
struct StateG * slot_122(struct StateG * v2504);
struct StateG * slot_99(struct StateG * v1959);
struct StateG * slot_33(struct StateG * v832);
struct StateG * slot_36(struct StateG * v866);
struct StateG * slot_57(struct StateG * v1133);
struct StateG * slot_62(struct StateG * v1212);
struct StateG * slot_22(struct StateG * v544);
struct StateG * slot_35(struct StateG * v858);
struct StateG * slot_51(struct StateG * v1055);
struct StateG * slot_52(struct StateG * v1068);
struct StateG * slot_83(struct StateG * v1762);
struct StateG * slot_25(struct StateG * v604);
struct StateG * slot_23(struct StateG * v564);
struct StateG * slot_2(struct StateG * v219);
struct StateG * slot_86(struct StateG * v1791);
struct StateG * slot_3(struct StateG * v232);
struct StateG * slot_123(struct StateG * v2544);
struct StateG * slot_73(struct StateG * v1452);
struct StateG * slot_100(struct StateG * v1972);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_97(struct StateG * v1933);
struct StateG * slot_13(struct StateG * v430);
struct StateG * slot_38(struct StateG * v887);
struct StateG * slot_106(struct StateG * v2064);
struct StateG * slot_111(struct StateG * v2164);
struct StateG * slot_98(struct StateG * v1946);
struct StateG * slot_109(struct StateG * v2124);
struct StateG * slot_42(struct StateG * v936);
struct StateG * slot_46(struct StateG * v990);
struct StateG * slot_20(struct StateG * v518);
struct StateG * slot_61(struct StateG * v1192);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_30(struct StateG * v744);
struct StateG * slot_4(struct StateG * v245);
struct StateG * slot_18(struct StateG * v492);
struct StateG * slot_9(struct StateG * v357);
struct StateG * slot_117(struct StateG * v2304);
struct StateG * slot_90(struct StateG * v1840);
struct StateG * slot_11(struct StateG * v404);
struct StateG * slot_12(struct StateG * v417) {
  int v418 = v417->timer;
  int v424 = v418 + 1;
  v417->timer = v424;
  int * v420 = v417->regs;
  v420[18] = 2;
  struct StateG * v422 = slot_10(v417);
  return v422;
}

struct StateG * slot_120(struct StateG * v2424) {
  int * v2425 = v2424->regs;
  int v2426 = v2425[16];
  int v2427 = v2425[17];
  bool v2447 = v2426 >= v2427;
  struct StateG * v2442;
  if (v2447) {
    int * v2428 = v2424->pht;
    v2428[5] = 1;
    struct StateG * v2430 = slot_131(v2424);
    v2442 = v2430;
  } else {
    int * v2432 = v2424->pht;
    v2432[5] = 0;
    int v2434 = v2424->timer;
    int v2456 = v2434 + 15;
    v2424->timer = v2456;
    int * v2436 = v2424->saved_regs;
    int v2437 = v2436[19];
    int * v2438 = v2424->regs;
    v2438[19] = v2437;
    struct StateG * v2440 = slot_125(v2424);
    v2442 = v2440;
  }
  return v2442;
}

struct StateG * slot_43(struct StateG * v950) {
  int v951 = v950->timer;
  int v958 = v951 + 1;
  v950->timer = v958;
  int * v953 = v950->regs;
  int v954 = v953[1];
  bool v961 = v954 == 24;
  ret_assert(v961);
  struct StateG * v956 = slot_47(v950);
  return v956;
}

struct StateG * slot_70(struct StateG * v1372) {
  int * v1373 = v1372->saved_regs;
  int * v1374 = v1372->regs;
  int v1375 = v1374[18];
  v1373[18] = v1375;
  int v1377 = v1372->timer;
  int v1387 = v1377 + 1;
  v1372->timer = v1387;
  int * v1379 = v1372->regs;
  v1379[18] = 2;
  struct StateG * v1381 = slot_78(v1372);
  return v1381;
}

struct StateG * slot_76(struct StateG * v1572) {
  int * v1573 = v1572->regs;
  int v1574 = v1573[16];
  int v1575 = v1573[17];
  bool v1595 = v1574 < v1575;
  struct StateG * v1590;
  if (v1595) {
    int * v1576 = v1572->pht;
    v1576[1] = 1;
    struct StateG * v1578 = slot_80(v1572);
    v1590 = v1578;
  } else {
    int * v1580 = v1572->pht;
    v1580[1] = 0;
    int v1582 = v1572->timer;
    int v1603 = v1582 + 15;
    v1572->timer = v1603;
    int * v1584 = v1572->saved_regs;
    int v1585 = v1584[18];
    int * v1586 = v1572->regs;
    v1586[18] = v1585;
    struct StateG * v1588 = slot_81(v1572);
    v1590 = v1588;
  }
  return v1590;
}

struct StateG * slot_6(struct StateG * v278) {
  int * v279 = v278->saved_regs;
  int * v280 = v278->regs;
  int v281 = v280[18];
  v279[18] = v281;
  int v283 = v278->timer;
  int v293 = v283 + 1;
  v278->timer = v293;
  int * v285 = v278->regs;
  v285[18] = 2;
  struct StateG * v287 = slot_8(v278);
  return v287;
}

struct StateG * slot_92(struct StateG * v1868) {
  int v1869 = v1868->timer;
  int v1875 = v1869 + 1;
  v1868->timer = v1875;
  int * v1871 = v1868->regs;
  v1871[1] = 36;
  struct StateG * v1873 = slot_96(v1868);
  return v1873;
}

struct StateG * slot_55(struct StateG * v1107) {
  int v1108 = v1107->timer;
  int v1114 = v1108 + 1;
  v1107->timer = v1114;
  int * v1110 = v1107->regs;
  v1110[1] = 36;
  struct StateG * v1112 = slot_59(v1107);
  return v1112;
}

struct StateG * slot_31(struct StateG * v784) {
  int * v785 = v784->regs;
  int v786 = v785[16];
  int v787 = v785[17];
  bool v807 = v786 >= v787;
  struct StateG * v802;
  if (v807) {
    int * v788 = v784->pht;
    v788[4] = 1;
    int v790 = v784->timer;
    int v811 = v790 + 15;
    v784->timer = v811;
    int * v792 = v784->saved_regs;
    int v793 = v792[19];
    int * v794 = v784->regs;
    v794[19] = v793;
    struct StateG * v796 = slot_38(v784);
    v802 = v796;
  } else {
    int * v798 = v784->pht;
    v798[4] = 0;
    struct StateG * v800 = slot_39(v784);
    v802 = v800;
  }
  return v802;
}

struct StateG * slot_82(struct StateG * v1749) {
  int v1750 = v1749->timer;
  int v1756 = v1750 + 1;
  v1749->timer = v1756;
  int * v1752 = v1749->regs;
  v1752[18] = 2;
  struct StateG * v1754 = slot_80(v1749);
  return v1754;
}

struct StateG * slot_65(struct StateG * v1272) {
  int * v1273 = v1272->saved_regs;
  int * v1274 = v1272->regs;
  int v1275 = v1274[18];
  v1273[18] = v1275;
  int v1277 = v1272->timer;
  int v1287 = v1277 + 1;
  v1272->timer = v1287;
  int * v1279 = v1272->regs;
  v1279[18] = 1;
  struct StateG * v1281 = slot_73(v1272);
  return v1281;
}

struct StateG * slot_10(struct StateG * v396) {
  int v397 = v396->timer;
  int v401 = v397 + 1;
  v396->timer = v401;
  struct StateG * v399 = slot_14(v396);
  return v399;
}

struct StateG * slot_74(struct StateG * v1492) {
  int * v1493 = v1492->regs;
  int v1494 = v1493[16];
  int v1495 = v1493[17];
  bool v1515 = v1494 < v1495;
  struct StateG * v1510;
  if (v1515) {
    int * v1496 = v1492->pht;
    v1496[2] = 1;
    struct StateG * v1498 = slot_84(v1492);
    v1510 = v1498;
  } else {
    int * v1500 = v1492->pht;
    v1500[2] = 0;
    int v1502 = v1492->timer;
    int v1524 = v1502 + 15;
    v1492->timer = v1524;
    int * v1504 = v1492->saved_regs;
    int v1505 = v1504[18];
    int * v1506 = v1492->regs;
    v1506[18] = v1505;
    struct StateG * v1508 = slot_85(v1492);
    v1510 = v1508;
  }
  return v1510;
}

struct StateG * slot_91(struct StateG * v1854) {
  int v1855 = v1854->timer;
  int v1862 = v1855 + 1;
  v1854->timer = v1862;
  int * v1857 = v1854->regs;
  int v1858 = v1857[1];
  bool v1865 = v1858 == 36;
  ret_assert(v1865);
  struct StateG * v1860 = slot_95(v1854);
  return v1860;
}

struct StateG * slot_107(struct StateG * v2084) {
  int v2085 = v2084->timer;
  int v2095 = v2085 + 1;
  v2084->timer = v2095;
  int * v2087 = v2084->pht;
  int v2088 = v2087[4];
  bool v2098 = !(v2088 == 0);
  struct StateG * v2093;
  if (v2098) {
    struct StateG * v2089 = slot_114(v2084);
    v2093 = v2089;
  } else {
    struct StateG * v2091 = slot_115(v2084);
    v2093 = v2091;
  }
  return v2093;
}

struct StateG * slot_136(struct StateG * v2724) {
  int v2725 = v2724->timer;
  int v2728 = v2725 + 1;
  v2724->timer = v2728;
  return v2724;
}

struct StateG * slot_58(struct StateG * v1146) {
  int v1147 = v1146->timer;
  int v1153 = v1147 + 1;
  v1146->timer = v1153;
  int * v1149 = v1146->regs;
  v1149[17] = 10;
  struct StateG * v1151 = slot_62(v1146);
  return v1151;
}

struct StateG * slot_89(struct StateG * v1826) {
  int v1827 = v1826->timer;
  int v1834 = v1827 + 1;
  v1826->timer = v1834;
  int * v1829 = v1826->regs;
  int v1830 = v1829[1];
  bool v1837 = v1830 == 36;
  ret_assert(v1837);
  struct StateG * v1832 = slot_93(v1826);
  return v1832;
}

struct StateG * slot_66(struct StateG * v1292) {
  int * v1293 = v1292->saved_regs;
  int * v1294 = v1292->regs;
  int v1295 = v1294[18];
  v1293[18] = v1295;
  int v1297 = v1292->timer;
  int v1307 = v1297 + 1;
  v1292->timer = v1307;
  int * v1299 = v1292->regs;
  v1299[18] = 2;
  struct StateG * v1301 = slot_74(v1292);
  return v1301;
}

struct StateG * slot_84(struct StateG * v1770) {
  int v1771 = v1770->timer;
  int v1775 = v1771 + 1;
  v1770->timer = v1775;
  struct StateG * v1773 = slot_90(v1770);
  return v1773;
}

struct StateG * slot_28(struct StateG * v664) {
  int * v665 = v664->regs;
  int v666 = v665[16];
  int v667 = v665[17];
  bool v687 = v666 >= v667;
  struct StateG * v682;
  if (v687) {
    int * v668 = v664->pht;
    v668[5] = 1;
    struct StateG * v670 = slot_32(v664);
    v682 = v670;
  } else {
    int * v672 = v664->pht;
    v672[5] = 0;
    int v674 = v664->timer;
    int v696 = v674 + 15;
    v664->timer = v696;
    int * v676 = v664->saved_regs;
    int v677 = v676[19];
    int * v678 = v664->regs;
    v678[19] = v677;
    struct StateG * v680 = slot_33(v664);
    v682 = v680;
  }
  return v682;
}

struct StateG * slot_17(struct StateG * v479) {
  int v480 = v479->timer;
  int v486 = v480 + 1;
  v479->timer = v486;
  int * v482 = v479->regs;
  v482[1] = 16;
  struct StateG * v484 = slot_19(v479);
  return v484;
}

struct StateG * slot_49(struct StateG * v1029) {
  int v1030 = v1029->timer;
  int v1036 = v1030 + 1;
  v1029->timer = v1036;
  int * v1032 = v1029->regs;
  v1032[1] = 28;
  struct StateG * v1034 = slot_53(v1029);
  return v1034;
}

struct StateG * slot_50(struct StateG * v1042) {
  int v1043 = v1042->timer;
  int v1049 = v1043 + 1;
  v1042->timer = v1049;
  int * v1045 = v1042->regs;
  v1045[1] = 28;
  struct StateG * v1047 = slot_54(v1042);
  return v1047;
}

struct StateG * slot_37(struct StateG * v874) {
  int v875 = v874->timer;
  int v881 = v875 + 1;
  v874->timer = v881;
  int * v877 = v874->regs;
  v877[19] = 1;
  struct StateG * v879 = slot_39(v874);
  return v879;
}

struct StateG * slot_114(struct StateG * v2224) {
  int * v2225 = v2224->saved_regs;
  int * v2226 = v2224->regs;
  int v2227 = v2226[19];
  v2225[19] = v2227;
  int v2229 = v2224->timer;
  int v2239 = v2229 + 1;
  v2224->timer = v2239;
  int * v2231 = v2224->regs;
  v2231[19] = 2;
  struct StateG * v2233 = slot_122(v2224);
  return v2233;
}

struct StateG * slot_135(struct StateG * v2710) {
  int v2711 = v2710->timer;
  int v2718 = v2711 + 1;
  v2710->timer = v2718;
  int * v2713 = v2710->regs;
  int v2714 = v2713[1];
  bool v2721 = v2714 == 44;
  ret_assert(v2721);
  struct StateG * v2716 = slot_136(v2710);
  return v2716;
}

struct StateG * slot_68(struct StateG * v1332) {
  int * v1333 = v1332->saved_regs;
  int * v1334 = v1332->regs;
  int v1335 = v1334[18];
  v1333[18] = v1335;
  int v1337 = v1332->timer;
  int v1347 = v1337 + 1;
  v1332->timer = v1347;
  int * v1339 = v1332->regs;
  v1339[18] = 2;
  struct StateG * v1341 = slot_76(v1332);
  return v1341;
}

struct StateG * slot_59(struct StateG * v1159) {
  int v1160 = v1159->timer;
  int v1166 = v1160 + 1;
  v1159->timer = v1166;
  int * v1162 = v1159->regs;
  v1162[17] = 10;
  struct StateG * v1164 = slot_63(v1159);
  return v1164;
}

struct StateG * slot_105(struct StateG * v2044) {
  int v2045 = v2044->timer;
  int v2055 = v2045 + 1;
  v2044->timer = v2055;
  int * v2047 = v2044->pht;
  int v2048 = v2047[6];
  bool v2058 = !(v2048 == 0);
  struct StateG * v2053;
  if (v2058) {
    struct StateG * v2049 = slot_110(v2044);
    v2053 = v2049;
  } else {
    struct StateG * v2051 = slot_111(v2044);
    v2053 = v2051;
  }
  return v2053;
}

struct StateG * slot_40(struct StateG * v908) {
  int v909 = v908->timer;
  int v916 = v909 + 1;
  v908->timer = v916;
  int * v911 = v908->regs;
  int v912 = v911[1];
  bool v919 = v912 == 24;
  ret_assert(v919);
  struct StateG * v914 = slot_44(v908);
  return v914;
}

struct StateG * slot_27(struct StateG * v644) {
  int * v645 = v644->saved_regs;
  int * v646 = v644->regs;
  int v647 = v646[19];
  v645[19] = v647;
  int v649 = v644->timer;
  int v659 = v649 + 1;
  v644->timer = v659;
  int * v651 = v644->regs;
  v651[19] = 1;
  struct StateG * v653 = slot_31(v644);
  return v653;
}

struct StateG * slot_15(struct StateG * v452) {
  int v453 = v452->timer;
  int v460 = v453 + 1;
  v452->timer = v460;
  int * v455 = v452->regs;
  int v456 = v455[1];
  bool v463 = v456 == 16;
  ret_assert(v463);
  struct StateG * v458 = slot_17(v452);
  return v458;
}

struct StateG * slot_48(struct StateG * v1016) {
  int v1017 = v1016->timer;
  int v1023 = v1017 + 1;
  v1016->timer = v1023;
  int * v1019 = v1016->regs;
  v1019[1] = 28;
  struct StateG * v1021 = slot_52(v1016);
  return v1021;
}

struct StateG * slot_77(struct StateG * v1611) {
  int * v1612 = v1611->regs;
  int v1613 = v1612[16];
  int v1614 = v1612[17];
  bool v1634 = v1613 < v1614;
  struct StateG * v1629;
  if (v1634) {
    int * v1615 = v1611->pht;
    v1615[1] = 1;
    int v1617 = v1611->timer;
    int v1637 = v1617 + 15;
    v1611->timer = v1637;
    int * v1619 = v1611->saved_regs;
    int v1620 = v1619[18];
    int * v1621 = v1611->regs;
    v1621[18] = v1620;
    struct StateG * v1623 = slot_82(v1611);
    v1629 = v1623;
  } else {
    int * v1625 = v1611->pht;
    v1625[1] = 0;
    struct StateG * v1627 = slot_83(v1611);
    v1629 = v1627;
  }
  return v1629;
}

struct StateG * slot_85(struct StateG * v1778) {
  int v1779 = v1778->timer;
  int v1785 = v1779 + 1;
  v1778->timer = v1785;
  int * v1781 = v1778->regs;
  v1781[18] = 1;
  struct StateG * v1783 = slot_87(v1778);
  return v1783;
}

struct StateG * slot_75(struct StateG * v1532) {
  int * v1533 = v1532->regs;
  int v1534 = v1533[16];
  int v1535 = v1533[17];
  bool v1555 = v1534 < v1535;
  struct StateG * v1550;
  if (v1555) {
    int * v1536 = v1532->pht;
    v1536[2] = 1;
    int v1538 = v1532->timer;
    int v1559 = v1538 + 15;
    v1532->timer = v1559;
    int * v1540 = v1532->saved_regs;
    int v1541 = v1540[18];
    int * v1542 = v1532->regs;
    v1542[18] = v1541;
    struct StateG * v1544 = slot_86(v1532);
    v1550 = v1544;
  } else {
    int * v1546 = v1532->pht;
    v1546[2] = 0;
    struct StateG * v1548 = slot_87(v1532);
    v1550 = v1548;
  }
  return v1550;
}

struct StateG * slot_56(struct StateG * v1120) {
  int v1121 = v1120->timer;
  int v1127 = v1121 + 1;
  v1120->timer = v1127;
  int * v1123 = v1120->regs;
  v1123[17] = 10;
  struct StateG * v1125 = slot_60(v1120);
  return v1125;
}

struct StateG * slot_72(struct StateG * v1412) {
  int * v1413 = v1412->regs;
  int v1414 = v1413[16];
  int v1415 = v1413[17];
  bool v1435 = v1414 < v1415;
  struct StateG * v1430;
  if (v1435) {
    int * v1416 = v1412->pht;
    v1416[3] = 1;
    struct StateG * v1418 = slot_80(v1412);
    v1430 = v1418;
  } else {
    int * v1420 = v1412->pht;
    v1420[3] = 0;
    int v1422 = v1412->timer;
    int v1444 = v1422 + 15;
    v1412->timer = v1444;
    int * v1424 = v1412->saved_regs;
    int v1425 = v1424[18];
    int * v1426 = v1412->regs;
    v1426[18] = v1425;
    struct StateG * v1428 = slot_81(v1412);
    v1430 = v1428;
  }
  return v1430;
}

struct StateG * slot_34(struct StateG * v845) {
  int v846 = v845->timer;
  int v852 = v846 + 1;
  v845->timer = v852;
  int * v848 = v845->regs;
  v848[19] = 2;
  struct StateG * v850 = slot_32(v845);
  return v850;
}

struct StateG * slot_119(struct StateG * v2384) {
  int * v2385 = v2384->regs;
  int v2386 = v2385[16];
  int v2387 = v2385[17];
  bool v2407 = v2386 >= v2387;
  struct StateG * v2402;
  if (v2407) {
    int * v2388 = v2384->pht;
    v2388[6] = 1;
    int v2390 = v2384->timer;
    int v2411 = v2390 + 15;
    v2384->timer = v2411;
    int * v2392 = v2384->saved_regs;
    int v2393 = v2392[19];
    int * v2394 = v2384->regs;
    v2394[19] = v2393;
    struct StateG * v2396 = slot_126(v2384);
    v2402 = v2396;
  } else {
    int * v2398 = v2384->pht;
    v2398[6] = 0;
    struct StateG * v2400 = slot_131(v2384);
    v2402 = v2400;
  }
  return v2402;
}

struct StateG * slot_71(struct StateG * v1392) {
  int * v1393 = v1392->saved_regs;
  int * v1394 = v1392->regs;
  int v1395 = v1394[18];
  v1393[18] = v1395;
  int v1397 = v1392->timer;
  int v1407 = v1397 + 1;
  v1392->timer = v1407;
  int * v1399 = v1392->regs;
  v1399[18] = 1;
  struct StateG * v1401 = slot_79(v1392);
  return v1401;
}

struct StateG * slot_101(struct StateG * v1985) {
  int v1986 = v1985->timer;
  int v1992 = v1986 + 1;
  v1985->timer = v1992;
  int * v1988 = v1985->regs;
  v1988[17] = 10;
  struct StateG * v1990 = slot_105(v1985);
  return v1990;
}

struct StateG * slot_108(struct StateG * v2104) {
  int * v2105 = v2104->saved_regs;
  int * v2106 = v2104->regs;
  int v2107 = v2106[19];
  v2105[19] = v2107;
  int v2109 = v2104->timer;
  int v2119 = v2109 + 1;
  v2104->timer = v2119;
  int * v2111 = v2104->regs;
  v2111[19] = 2;
  struct StateG * v2113 = slot_116(v2104);
  return v2113;
}

struct StateG * slot_116(struct StateG * v2264) {
  int * v2265 = v2264->regs;
  int v2266 = v2265[16];
  int v2267 = v2265[17];
  bool v2287 = v2266 >= v2267;
  struct StateG * v2282;
  if (v2287) {
    int * v2268 = v2264->pht;
    v2268[7] = 1;
    struct StateG * v2270 = slot_131(v2264);
    v2282 = v2270;
  } else {
    int * v2272 = v2264->pht;
    v2272[7] = 0;
    int v2274 = v2264->timer;
    int v2296 = v2274 + 15;
    v2264->timer = v2296;
    int * v2276 = v2264->saved_regs;
    int v2277 = v2276[19];
    int * v2278 = v2264->regs;
    v2278[19] = v2277;
    struct StateG * v2280 = slot_125(v2264);
    v2282 = v2280;
  }
  return v2282;
}

struct StateG * slot_93(struct StateG * v1881) {
  int v1882 = v1881->timer;
  int v1888 = v1882 + 1;
  v1881->timer = v1888;
  int * v1884 = v1881->regs;
  v1884[1] = 36;
  struct StateG * v1886 = slot_97(v1881);
  return v1886;
}

struct StateG * slot_88(struct StateG * v1812) {
  int v1813 = v1812->timer;
  int v1820 = v1813 + 1;
  v1812->timer = v1820;
  int * v1815 = v1812->regs;
  int v1816 = v1815[1];
  bool v1823 = v1816 == 36;
  ret_assert(v1823);
  struct StateG * v1818 = slot_92(v1812);
  return v1818;
}

struct StateG * slot_21(struct StateG * v531) {
  int v532 = v531->timer;
  int v538 = v532 + 1;
  v531->timer = v538;
  int * v534 = v531->regs;
  v534[17] = 10;
  struct StateG * v536 = slot_23(v531);
  return v536;
}

struct StateG * slot_96(struct StateG * v1920) {
  int v1921 = v1920->timer;
  int v1927 = v1921 + 1;
  v1920->timer = v1927;
  int * v1923 = v1920->regs;
  v1923[1] = 44;
  struct StateG * v1925 = slot_100(v1920);
  return v1925;
}

struct StateG * slot_45(struct StateG * v977) {
  int v978 = v977->timer;
  int v984 = v978 + 1;
  v977->timer = v984;
  int * v980 = v977->regs;
  v980[16] = 20;
  struct StateG * v982 = slot_49(v977);
  return v982;
}

struct StateG * slot_118(struct StateG * v2344) {
  int * v2345 = v2344->regs;
  int v2346 = v2345[16];
  int v2347 = v2345[17];
  bool v2367 = v2346 >= v2347;
  struct StateG * v2362;
  if (v2367) {
    int * v2348 = v2344->pht;
    v2348[6] = 1;
    struct StateG * v2350 = slot_131(v2344);
    v2362 = v2350;
  } else {
    int * v2352 = v2344->pht;
    v2352[6] = 0;
    int v2354 = v2344->timer;
    int v2376 = v2354 + 15;
    v2344->timer = v2376;
    int * v2356 = v2344->saved_regs;
    int v2357 = v2356[19];
    int * v2358 = v2344->regs;
    v2358[19] = v2357;
    struct StateG * v2360 = slot_125(v2344);
    v2362 = v2360;
  }
  return v2362;
}

struct StateG * slot_69(struct StateG * v1352) {
  int * v1353 = v1352->saved_regs;
  int * v1354 = v1352->regs;
  int v1355 = v1354[18];
  v1353[18] = v1355;
  int v1357 = v1352->timer;
  int v1367 = v1357 + 1;
  v1352->timer = v1367;
  int * v1359 = v1352->regs;
  v1359[18] = 1;
  struct StateG * v1361 = slot_77(v1352);
  return v1361;
}

struct StateG * slot_121(struct StateG * v2464) {
  int * v2465 = v2464->regs;
  int v2466 = v2465[16];
  int v2467 = v2465[17];
  bool v2487 = v2466 >= v2467;
  struct StateG * v2482;
  if (v2487) {
    int * v2468 = v2464->pht;
    v2468[5] = 1;
    int v2470 = v2464->timer;
    int v2491 = v2470 + 15;
    v2464->timer = v2491;
    int * v2472 = v2464->saved_regs;
    int v2473 = v2472[19];
    int * v2474 = v2464->regs;
    v2474[19] = v2473;
    struct StateG * v2476 = slot_126(v2464);
    v2482 = v2476;
  } else {
    int * v2478 = v2464->pht;
    v2478[5] = 0;
    struct StateG * v2480 = slot_131(v2464);
    v2482 = v2480;
  }
  return v2482;
}

struct StateG * slot_94(struct StateG * v1894) {
  int v1895 = v1894->timer;
  int v1901 = v1895 + 1;
  v1894->timer = v1901;
  int * v1897 = v1894->regs;
  v1897[1] = 36;
  struct StateG * v1899 = slot_98(v1894);
  return v1899;
}

struct StateG * slot_63(struct StateG * v1232) {
  int v1233 = v1232->timer;
  int v1243 = v1233 + 1;
  v1232->timer = v1243;
  int * v1235 = v1232->pht;
  int v1236 = v1235[0];
  bool v1246 = !(v1236 == 0);
  struct StateG * v1241;
  if (v1246) {
    struct StateG * v1237 = slot_70(v1232);
    v1241 = v1237;
  } else {
    struct StateG * v1239 = slot_71(v1232);
    v1241 = v1239;
  }
  return v1241;
}

struct StateG * slot_24(struct StateG * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[19];
  v585[19] = v587;
  int v589 = v584->timer;
  int v599 = v589 + 1;
  v584->timer = v599;
  int * v591 = v584->regs;
  v591[19] = 2;
  struct StateG * v593 = slot_28(v584);
  return v593;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 80;
  struct StateG * v7 = slot_1(v2);
  return v7;
}

struct StateG * slot_125(struct StateG * v2592) {
  int v2593 = v2592->timer;
  int v2599 = v2593 + 1;
  v2592->timer = v2599;
  int * v2595 = v2592->regs;
  v2595[19] = 1;
  struct StateG * v2597 = slot_131(v2592);
  return v2597;
}

struct StateG * slot_102(struct StateG * v1998) {
  int v1999 = v1998->timer;
  int v2005 = v1999 + 1;
  v1998->timer = v2005;
  int * v2001 = v1998->regs;
  v2001[17] = 10;
  struct StateG * v2003 = slot_106(v1998);
  return v2003;
}

struct StateG * slot_126(struct StateG * v2605) {
  int v2606 = v2605->timer;
  int v2612 = v2606 + 1;
  v2605->timer = v2612;
  int * v2608 = v2605->regs;
  v2608[19] = 2;
  struct StateG * v2610 = slot_131(v2605);
  return v2610;
}

struct StateG * slot_110(struct StateG * v2144) {
  int * v2145 = v2144->saved_regs;
  int * v2146 = v2144->regs;
  int v2147 = v2146[19];
  v2145[19] = v2147;
  int v2149 = v2144->timer;
  int v2159 = v2149 + 1;
  v2144->timer = v2159;
  int * v2151 = v2144->regs;
  v2151[19] = 2;
  struct StateG * v2153 = slot_118(v2144);
  return v2153;
}

struct StateG * slot_79(struct StateG * v1689) {
  int * v1690 = v1689->regs;
  int v1691 = v1690[16];
  int v1692 = v1690[17];
  bool v1712 = v1691 < v1692;
  struct StateG * v1707;
  if (v1712) {
    int * v1693 = v1689->pht;
    v1693[0] = 1;
    int v1695 = v1689->timer;
    int v1716 = v1695 + 15;
    v1689->timer = v1716;
    int * v1697 = v1689->saved_regs;
    int v1698 = v1697[18];
    int * v1699 = v1689->regs;
    v1699[18] = v1698;
    struct StateG * v1701 = slot_86(v1689);
    v1707 = v1701;
  } else {
    int * v1703 = v1689->pht;
    v1703[0] = 0;
    struct StateG * v1705 = slot_87(v1689);
    v1707 = v1705;
  }
  return v1707;
}

struct StateG * slot_41(struct StateG * v922) {
  int v923 = v922->timer;
  int v930 = v923 + 1;
  v922->timer = v930;
  int * v925 = v922->regs;
  int v926 = v925[1];
  bool v933 = v926 == 24;
  ret_assert(v933);
  struct StateG * v928 = slot_45(v922);
  return v928;
}

struct StateG * slot_39(struct StateG * v900) {
  int v901 = v900->timer;
  int v905 = v901 + 1;
  v900->timer = v905;
  struct StateG * v903 = slot_43(v900);
  return v903;
}

struct StateG * slot_131(struct StateG * v2660) {
  int v2661 = v2660->timer;
  int v2665 = v2661 + 1;
  v2660->timer = v2665;
  struct StateG * v2663 = slot_135(v2660);
  return v2663;
}

struct StateG * slot_8(struct StateG * v318) {
  int * v319 = v318->regs;
  int v320 = v319[16];
  int v321 = v319[17];
  bool v341 = v320 < v321;
  struct StateG * v336;
  if (v341) {
    int * v322 = v318->pht;
    v322[0] = 1;
    struct StateG * v324 = slot_10(v318);
    v336 = v324;
  } else {
    int * v326 = v318->pht;
    v326[0] = 0;
    int v328 = v318->timer;
    int v349 = v328 + 15;
    v318->timer = v349;
    int * v330 = v318->saved_regs;
    int v331 = v330[18];
    int * v332 = v318->regs;
    v332[18] = v331;
    struct StateG * v334 = slot_11(v318);
    v336 = v334;
  }
  return v336;
}

struct StateG * slot_60(struct StateG * v1172) {
  int v1173 = v1172->timer;
  int v1183 = v1173 + 1;
  v1172->timer = v1183;
  int * v1175 = v1172->pht;
  int v1176 = v1175[3];
  bool v1186 = !(v1176 == 0);
  struct StateG * v1181;
  if (v1186) {
    struct StateG * v1177 = slot_64(v1172);
    v1181 = v1177;
  } else {
    struct StateG * v1179 = slot_65(v1172);
    v1181 = v1179;
  }
  return v1181;
}

struct StateG * slot_112(struct StateG * v2184) {
  int * v2185 = v2184->saved_regs;
  int * v2186 = v2184->regs;
  int v2187 = v2186[19];
  v2185[19] = v2187;
  int v2189 = v2184->timer;
  int v2199 = v2189 + 1;
  v2184->timer = v2199;
  int * v2191 = v2184->regs;
  v2191[19] = 2;
  struct StateG * v2193 = slot_120(v2184);
  return v2193;
}

struct StateG * slot_47(struct StateG * v1003) {
  int v1004 = v1003->timer;
  int v1010 = v1004 + 1;
  v1003->timer = v1010;
  int * v1006 = v1003->regs;
  v1006[16] = 20;
  struct StateG * v1008 = slot_51(v1003);
  return v1008;
}

struct StateG * slot_29(struct StateG * v704) {
  int * v705 = v704->regs;
  int v706 = v705[16];
  int v707 = v705[17];
  bool v727 = v706 >= v707;
  struct StateG * v722;
  if (v727) {
    int * v708 = v704->pht;
    v708[5] = 1;
    int v710 = v704->timer;
    int v731 = v710 + 15;
    v704->timer = v731;
    int * v712 = v704->saved_regs;
    int v713 = v712[19];
    int * v714 = v704->regs;
    v714[19] = v713;
    struct StateG * v716 = slot_34(v704);
    v722 = v716;
  } else {
    int * v718 = v704->pht;
    v718[5] = 0;
    struct StateG * v720 = slot_35(v704);
    v722 = v720;
  }
  return v722;
}

struct StateG * slot_16(struct StateG * v466) {
  int v467 = v466->timer;
  int v473 = v467 + 1;
  v466->timer = v473;
  int * v469 = v466->regs;
  v469[1] = 16;
  struct StateG * v471 = slot_18(v466);
  return v471;
}

struct StateG * slot_5(struct StateG * v258) {
  int v259 = v258->timer;
  int v269 = v259 + 1;
  v258->timer = v269;
  int * v261 = v258->pht;
  int v262 = v261[0];
  bool v272 = !(v262 == 0);
  struct StateG * v267;
  if (v272) {
    struct StateG * v263 = slot_6(v258);
    v267 = v263;
  } else {
    struct StateG * v265 = slot_7(v258);
    v267 = v265;
  }
  return v267;
}

struct StateG * slot_113(struct StateG * v2204) {
  int * v2205 = v2204->saved_regs;
  int * v2206 = v2204->regs;
  int v2207 = v2206[19];
  v2205[19] = v2207;
  int v2209 = v2204->timer;
  int v2219 = v2209 + 1;
  v2204->timer = v2219;
  int * v2211 = v2204->regs;
  v2211[19] = 1;
  struct StateG * v2213 = slot_121(v2204);
  return v2213;
}

struct StateG * slot_104(struct StateG * v2024) {
  int v2025 = v2024->timer;
  int v2035 = v2025 + 1;
  v2024->timer = v2035;
  int * v2027 = v2024->pht;
  int v2028 = v2027[7];
  bool v2038 = !(v2028 == 0);
  struct StateG * v2033;
  if (v2038) {
    struct StateG * v2029 = slot_108(v2024);
    v2033 = v2029;
  } else {
    struct StateG * v2031 = slot_109(v2024);
    v2033 = v2031;
  }
  return v2033;
}

struct StateG * slot_7(struct StateG * v298) {
  int * v299 = v298->saved_regs;
  int * v300 = v298->regs;
  int v301 = v300[18];
  v299[18] = v301;
  int v303 = v298->timer;
  int v313 = v303 + 1;
  v298->timer = v313;
  int * v305 = v298->regs;
  v305[18] = 1;
  struct StateG * v307 = slot_9(v298);
  return v307;
}

struct StateG * slot_54(struct StateG * v1094) {
  int v1095 = v1094->timer;
  int v1101 = v1095 + 1;
  v1094->timer = v1101;
  int * v1097 = v1094->regs;
  v1097[1] = 36;
  struct StateG * v1099 = slot_58(v1094);
  return v1099;
}

struct StateG * slot_26(struct StateG * v624) {
  int * v625 = v624->saved_regs;
  int * v626 = v624->regs;
  int v627 = v626[19];
  v625[19] = v627;
  int v629 = v624->timer;
  int v639 = v629 + 1;
  v624->timer = v639;
  int * v631 = v624->regs;
  v631[19] = 2;
  struct StateG * v633 = slot_30(v624);
  return v633;
}

struct StateG * slot_103(struct StateG * v2011) {
  int v2012 = v2011->timer;
  int v2018 = v2012 + 1;
  v2011->timer = v2018;
  int * v2014 = v2011->regs;
  v2014[17] = 10;
  struct StateG * v2016 = slot_107(v2011);
  return v2016;
}

struct StateG * slot_19(struct StateG * v505) {
  int v506 = v505->timer;
  int v512 = v506 + 1;
  v505->timer = v512;
  int * v508 = v505->regs;
  v508[1] = 24;
  struct StateG * v510 = slot_21(v505);
  return v510;
}

struct StateG * slot_87(struct StateG * v1804) {
  int v1805 = v1804->timer;
  int v1809 = v1805 + 1;
  v1804->timer = v1809;
  struct StateG * v1807 = slot_91(v1804);
  return v1807;
}

struct StateG * slot_67(struct StateG * v1312) {
  int * v1313 = v1312->saved_regs;
  int * v1314 = v1312->regs;
  int v1315 = v1314[18];
  v1313[18] = v1315;
  int v1317 = v1312->timer;
  int v1327 = v1317 + 1;
  v1312->timer = v1327;
  int * v1319 = v1312->regs;
  v1319[18] = 1;
  struct StateG * v1321 = slot_75(v1312);
  return v1321;
}

struct StateG * slot_81(struct StateG * v1736) {
  int v1737 = v1736->timer;
  int v1743 = v1737 + 1;
  v1736->timer = v1743;
  int * v1739 = v1736->regs;
  v1739[18] = 1;
  struct StateG * v1741 = slot_83(v1736);
  return v1741;
}

struct StateG * slot_64(struct StateG * v1252) {
  int * v1253 = v1252->saved_regs;
  int * v1254 = v1252->regs;
  int v1255 = v1254[18];
  v1253[18] = v1255;
  int v1257 = v1252->timer;
  int v1267 = v1257 + 1;
  v1252->timer = v1267;
  int * v1259 = v1252->regs;
  v1259[18] = 2;
  struct StateG * v1261 = slot_72(v1252);
  return v1261;
}

struct StateG * slot_14(struct StateG * v438) {
  int v439 = v438->timer;
  int v446 = v439 + 1;
  v438->timer = v446;
  int * v441 = v438->regs;
  int v442 = v441[1];
  bool v449 = v442 == 16;
  ret_assert(v449);
  struct StateG * v444 = slot_16(v438);
  return v444;
}

struct StateG * slot_53(struct StateG * v1081) {
  int v1082 = v1081->timer;
  int v1088 = v1082 + 1;
  v1081->timer = v1088;
  int * v1084 = v1081->regs;
  v1084[1] = 36;
  struct StateG * v1086 = slot_57(v1081);
  return v1086;
}

struct StateG * slot_95(struct StateG * v1907) {
  int v1908 = v1907->timer;
  int v1914 = v1908 + 1;
  v1907->timer = v1914;
  int * v1910 = v1907->regs;
  v1910[1] = 36;
  struct StateG * v1912 = slot_99(v1907);
  return v1912;
}

struct StateG * slot_80(struct StateG * v1728) {
  int v1729 = v1728->timer;
  int v1733 = v1729 + 1;
  v1728->timer = v1733;
  struct StateG * v1731 = slot_88(v1728);
  return v1731;
}

struct StateG * slot_44(struct StateG * v964) {
  int v965 = v964->timer;
  int v971 = v965 + 1;
  v964->timer = v971;
  int * v967 = v964->regs;
  v967[16] = 20;
  struct StateG * v969 = slot_48(v964);
  return v969;
}

struct StateG * slot_115(struct StateG * v2244) {
  int * v2245 = v2244->saved_regs;
  int * v2246 = v2244->regs;
  int v2247 = v2246[19];
  v2245[19] = v2247;
  int v2249 = v2244->timer;
  int v2259 = v2249 + 1;
  v2244->timer = v2259;
  int * v2251 = v2244->regs;
  v2251[19] = 1;
  struct StateG * v2253 = slot_123(v2244);
  return v2253;
}

struct StateG * slot_78(struct StateG * v1650) {
  int * v1651 = v1650->regs;
  int v1652 = v1651[16];
  int v1653 = v1651[17];
  bool v1673 = v1652 < v1653;
  struct StateG * v1668;
  if (v1673) {
    int * v1654 = v1650->pht;
    v1654[0] = 1;
    struct StateG * v1656 = slot_84(v1650);
    v1668 = v1656;
  } else {
    int * v1658 = v1650->pht;
    v1658[0] = 0;
    int v1660 = v1650->timer;
    int v1681 = v1660 + 15;
    v1650->timer = v1681;
    int * v1662 = v1650->saved_regs;
    int v1663 = v1662[18];
    int * v1664 = v1650->regs;
    v1664[18] = v1663;
    struct StateG * v1666 = slot_85(v1650);
    v1668 = v1666;
  }
  return v1668;
}

struct StateG * slot_32(struct StateG * v824) {
  int v825 = v824->timer;
  int v829 = v825 + 1;
  v824->timer = v829;
  struct StateG * v827 = slot_40(v824);
  return v827;
}

struct StateG * slot_122(struct StateG * v2504) {
  int * v2505 = v2504->regs;
  int v2506 = v2505[16];
  int v2507 = v2505[17];
  bool v2527 = v2506 >= v2507;
  struct StateG * v2522;
  if (v2527) {
    int * v2508 = v2504->pht;
    v2508[4] = 1;
    struct StateG * v2510 = slot_131(v2504);
    v2522 = v2510;
  } else {
    int * v2512 = v2504->pht;
    v2512[4] = 0;
    int v2514 = v2504->timer;
    int v2536 = v2514 + 15;
    v2504->timer = v2536;
    int * v2516 = v2504->saved_regs;
    int v2517 = v2516[19];
    int * v2518 = v2504->regs;
    v2518[19] = v2517;
    struct StateG * v2520 = slot_125(v2504);
    v2522 = v2520;
  }
  return v2522;
}

struct StateG * slot_99(struct StateG * v1959) {
  int v1960 = v1959->timer;
  int v1966 = v1960 + 1;
  v1959->timer = v1966;
  int * v1962 = v1959->regs;
  v1962[1] = 44;
  struct StateG * v1964 = slot_103(v1959);
  return v1964;
}

struct StateG * slot_33(struct StateG * v832) {
  int v833 = v832->timer;
  int v839 = v833 + 1;
  v832->timer = v839;
  int * v835 = v832->regs;
  v835[19] = 1;
  struct StateG * v837 = slot_35(v832);
  return v837;
}

struct StateG * slot_36(struct StateG * v866) {
  int v867 = v866->timer;
  int v871 = v867 + 1;
  v866->timer = v871;
  struct StateG * v869 = slot_42(v866);
  return v869;
}

struct StateG * slot_57(struct StateG * v1133) {
  int v1134 = v1133->timer;
  int v1140 = v1134 + 1;
  v1133->timer = v1140;
  int * v1136 = v1133->regs;
  v1136[17] = 10;
  struct StateG * v1138 = slot_61(v1133);
  return v1138;
}

struct StateG * slot_62(struct StateG * v1212) {
  int v1213 = v1212->timer;
  int v1223 = v1213 + 1;
  v1212->timer = v1223;
  int * v1215 = v1212->pht;
  int v1216 = v1215[1];
  bool v1226 = !(v1216 == 0);
  struct StateG * v1221;
  if (v1226) {
    struct StateG * v1217 = slot_68(v1212);
    v1221 = v1217;
  } else {
    struct StateG * v1219 = slot_69(v1212);
    v1221 = v1219;
  }
  return v1221;
}

struct StateG * slot_22(struct StateG * v544) {
  int v545 = v544->timer;
  int v555 = v545 + 1;
  v544->timer = v555;
  int * v547 = v544->pht;
  int v548 = v547[5];
  bool v558 = !(v548 == 0);
  struct StateG * v553;
  if (v558) {
    struct StateG * v549 = slot_24(v544);
    v553 = v549;
  } else {
    struct StateG * v551 = slot_25(v544);
    v553 = v551;
  }
  return v553;
}

struct StateG * slot_35(struct StateG * v858) {
  int v859 = v858->timer;
  int v863 = v859 + 1;
  v858->timer = v863;
  struct StateG * v861 = slot_41(v858);
  return v861;
}

struct StateG * slot_51(struct StateG * v1055) {
  int v1056 = v1055->timer;
  int v1062 = v1056 + 1;
  v1055->timer = v1062;
  int * v1058 = v1055->regs;
  v1058[1] = 28;
  struct StateG * v1060 = slot_55(v1055);
  return v1060;
}

struct StateG * slot_52(struct StateG * v1068) {
  int v1069 = v1068->timer;
  int v1075 = v1069 + 1;
  v1068->timer = v1075;
  int * v1071 = v1068->regs;
  v1071[1] = 36;
  struct StateG * v1073 = slot_56(v1068);
  return v1073;
}

struct StateG * slot_83(struct StateG * v1762) {
  int v1763 = v1762->timer;
  int v1767 = v1763 + 1;
  v1762->timer = v1767;
  struct StateG * v1765 = slot_89(v1762);
  return v1765;
}

struct StateG * slot_25(struct StateG * v604) {
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[19];
  v605[19] = v607;
  int v609 = v604->timer;
  int v619 = v609 + 1;
  v604->timer = v619;
  int * v611 = v604->regs;
  v611[19] = 1;
  struct StateG * v613 = slot_29(v604);
  return v613;
}

struct StateG * slot_23(struct StateG * v564) {
  int v565 = v564->timer;
  int v575 = v565 + 1;
  v564->timer = v575;
  int * v567 = v564->pht;
  int v568 = v567[4];
  bool v578 = !(v568 == 0);
  struct StateG * v573;
  if (v578) {
    struct StateG * v569 = slot_26(v564);
    v573 = v569;
  } else {
    struct StateG * v571 = slot_27(v564);
    v573 = v571;
  }
  return v573;
}

struct StateG * slot_2(struct StateG * v219) {
  int v220 = v219->timer;
  int v226 = v220 + 1;
  v219->timer = v226;
  int * v222 = v219->regs;
  v222[1] = 8;
  struct StateG * v224 = slot_3(v219);
  return v224;
}

struct StateG * slot_86(struct StateG * v1791) {
  int v1792 = v1791->timer;
  int v1798 = v1792 + 1;
  v1791->timer = v1798;
  int * v1794 = v1791->regs;
  v1794[18] = 2;
  struct StateG * v1796 = slot_84(v1791);
  return v1796;
}

struct StateG * slot_3(struct StateG * v232) {
  int v233 = v232->timer;
  int v239 = v233 + 1;
  v232->timer = v239;
  int * v235 = v232->regs;
  v235[1] = 16;
  struct StateG * v237 = slot_4(v232);
  return v237;
}

struct StateG * slot_123(struct StateG * v2544) {
  int * v2545 = v2544->regs;
  int v2546 = v2545[16];
  int v2547 = v2545[17];
  bool v2567 = v2546 >= v2547;
  struct StateG * v2562;
  if (v2567) {
    int * v2548 = v2544->pht;
    v2548[4] = 1;
    int v2550 = v2544->timer;
    int v2571 = v2550 + 15;
    v2544->timer = v2571;
    int * v2552 = v2544->saved_regs;
    int v2553 = v2552[19];
    int * v2554 = v2544->regs;
    v2554[19] = v2553;
    struct StateG * v2556 = slot_126(v2544);
    v2562 = v2556;
  } else {
    int * v2558 = v2544->pht;
    v2558[4] = 0;
    struct StateG * v2560 = slot_131(v2544);
    v2562 = v2560;
  }
  return v2562;
}

struct StateG * slot_73(struct StateG * v1452) {
  int * v1453 = v1452->regs;
  int v1454 = v1453[16];
  int v1455 = v1453[17];
  bool v1475 = v1454 < v1455;
  struct StateG * v1470;
  if (v1475) {
    int * v1456 = v1452->pht;
    v1456[3] = 1;
    int v1458 = v1452->timer;
    int v1479 = v1458 + 15;
    v1452->timer = v1479;
    int * v1460 = v1452->saved_regs;
    int v1461 = v1460[18];
    int * v1462 = v1452->regs;
    v1462[18] = v1461;
    struct StateG * v1464 = slot_82(v1452);
    v1470 = v1464;
  } else {
    int * v1466 = v1452->pht;
    v1466[3] = 0;
    struct StateG * v1468 = slot_83(v1452);
    v1470 = v1468;
  }
  return v1470;
}

struct StateG * slot_100(struct StateG * v1972) {
  int v1973 = v1972->timer;
  int v1979 = v1973 + 1;
  v1972->timer = v1979;
  int * v1975 = v1972->regs;
  v1975[17] = 10;
  struct StateG * v1977 = slot_104(v1972);
  return v1977;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[16] = v121;
  struct StateG * v124 = slot_2(v15);
  return v124;
}

struct StateG * slot_97(struct StateG * v1933) {
  int v1934 = v1933->timer;
  int v1940 = v1934 + 1;
  v1933->timer = v1940;
  int * v1936 = v1933->regs;
  v1936[1] = 44;
  struct StateG * v1938 = slot_101(v1933);
  return v1938;
}

struct StateG * slot_13(struct StateG * v430) {
  int v431 = v430->timer;
  int v435 = v431 + 1;
  v430->timer = v435;
  struct StateG * v433 = slot_15(v430);
  return v433;
}

struct StateG * slot_38(struct StateG * v887) {
  int v888 = v887->timer;
  int v894 = v888 + 1;
  v887->timer = v894;
  int * v890 = v887->regs;
  v890[19] = 2;
  struct StateG * v892 = slot_36(v887);
  return v892;
}

struct StateG * slot_106(struct StateG * v2064) {
  int v2065 = v2064->timer;
  int v2075 = v2065 + 1;
  v2064->timer = v2075;
  int * v2067 = v2064->pht;
  int v2068 = v2067[5];
  bool v2078 = !(v2068 == 0);
  struct StateG * v2073;
  if (v2078) {
    struct StateG * v2069 = slot_112(v2064);
    v2073 = v2069;
  } else {
    struct StateG * v2071 = slot_113(v2064);
    v2073 = v2071;
  }
  return v2073;
}

struct StateG * slot_111(struct StateG * v2164) {
  int * v2165 = v2164->saved_regs;
  int * v2166 = v2164->regs;
  int v2167 = v2166[19];
  v2165[19] = v2167;
  int v2169 = v2164->timer;
  int v2179 = v2169 + 1;
  v2164->timer = v2179;
  int * v2171 = v2164->regs;
  v2171[19] = 1;
  struct StateG * v2173 = slot_119(v2164);
  return v2173;
}

struct StateG * slot_98(struct StateG * v1946) {
  int v1947 = v1946->timer;
  int v1953 = v1947 + 1;
  v1946->timer = v1953;
  int * v1949 = v1946->regs;
  v1949[1] = 44;
  struct StateG * v1951 = slot_102(v1946);
  return v1951;
}

struct StateG * slot_109(struct StateG * v2124) {
  int * v2125 = v2124->saved_regs;
  int * v2126 = v2124->regs;
  int v2127 = v2126[19];
  v2125[19] = v2127;
  int v2129 = v2124->timer;
  int v2139 = v2129 + 1;
  v2124->timer = v2139;
  int * v2131 = v2124->regs;
  v2131[19] = 1;
  struct StateG * v2133 = slot_117(v2124);
  return v2133;
}

struct StateG * slot_42(struct StateG * v936) {
  int v937 = v936->timer;
  int v944 = v937 + 1;
  v936->timer = v944;
  int * v939 = v936->regs;
  int v940 = v939[1];
  bool v947 = v940 == 24;
  ret_assert(v947);
  struct StateG * v942 = slot_46(v936);
  return v942;
}

struct StateG * slot_46(struct StateG * v990) {
  int v991 = v990->timer;
  int v997 = v991 + 1;
  v990->timer = v997;
  int * v993 = v990->regs;
  v993[16] = 20;
  struct StateG * v995 = slot_50(v990);
  return v995;
}

struct StateG * slot_20(struct StateG * v518) {
  int v519 = v518->timer;
  int v525 = v519 + 1;
  v518->timer = v525;
  int * v521 = v518->regs;
  v521[17] = 10;
  struct StateG * v523 = slot_22(v518);
  return v523;
}

struct StateG * slot_61(struct StateG * v1192) {
  int v1193 = v1192->timer;
  int v1203 = v1193 + 1;
  v1192->timer = v1203;
  int * v1195 = v1192->pht;
  int v1196 = v1195[2];
  bool v1206 = !(v1196 == 0);
  struct StateG * v1201;
  if (v1206) {
    struct StateG * v1197 = slot_66(v1192);
    v1201 = v1197;
  } else {
    struct StateG * v1199 = slot_67(v1192);
    v1201 = v1199;
  }
  return v1201;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_30(struct StateG * v744) {
  int * v745 = v744->regs;
  int v746 = v745[16];
  int v747 = v745[17];
  bool v767 = v746 >= v747;
  struct StateG * v762;
  if (v767) {
    int * v748 = v744->pht;
    v748[4] = 1;
    struct StateG * v750 = slot_36(v744);
    v762 = v750;
  } else {
    int * v752 = v744->pht;
    v752[4] = 0;
    int v754 = v744->timer;
    int v776 = v754 + 15;
    v744->timer = v776;
    int * v756 = v744->saved_regs;
    int v757 = v756[19];
    int * v758 = v744->regs;
    v758[19] = v757;
    struct StateG * v760 = slot_37(v744);
    v762 = v760;
  }
  return v762;
}

struct StateG * slot_4(struct StateG * v245) {
  int v246 = v245->timer;
  int v252 = v246 + 1;
  v245->timer = v252;
  int * v248 = v245->regs;
  v248[17] = 10;
  struct StateG * v250 = slot_5(v245);
  return v250;
}

struct StateG * slot_18(struct StateG * v492) {
  int v493 = v492->timer;
  int v499 = v493 + 1;
  v492->timer = v499;
  int * v495 = v492->regs;
  v495[1] = 24;
  struct StateG * v497 = slot_20(v492);
  return v497;
}

struct StateG * slot_9(struct StateG * v357) {
  int * v358 = v357->regs;
  int v359 = v358[16];
  int v360 = v358[17];
  bool v380 = v359 < v360;
  struct StateG * v375;
  if (v380) {
    int * v361 = v357->pht;
    v361[0] = 1;
    int v363 = v357->timer;
    int v384 = v363 + 15;
    v357->timer = v384;
    int * v365 = v357->saved_regs;
    int v366 = v365[18];
    int * v367 = v357->regs;
    v367[18] = v366;
    struct StateG * v369 = slot_12(v357);
    v375 = v369;
  } else {
    int * v371 = v357->pht;
    v371[0] = 0;
    struct StateG * v373 = slot_13(v357);
    v375 = v373;
  }
  return v375;
}

struct StateG * slot_117(struct StateG * v2304) {
  int * v2305 = v2304->regs;
  int v2306 = v2305[16];
  int v2307 = v2305[17];
  bool v2327 = v2306 >= v2307;
  struct StateG * v2322;
  if (v2327) {
    int * v2308 = v2304->pht;
    v2308[7] = 1;
    int v2310 = v2304->timer;
    int v2331 = v2310 + 15;
    v2304->timer = v2331;
    int * v2312 = v2304->saved_regs;
    int v2313 = v2312[19];
    int * v2314 = v2304->regs;
    v2314[19] = v2313;
    struct StateG * v2316 = slot_126(v2304);
    v2322 = v2316;
  } else {
    int * v2318 = v2304->pht;
    v2318[7] = 0;
    struct StateG * v2320 = slot_131(v2304);
    v2322 = v2320;
  }
  return v2322;
}

struct StateG * slot_90(struct StateG * v1840) {
  int v1841 = v1840->timer;
  int v1848 = v1841 + 1;
  v1840->timer = v1848;
  int * v1843 = v1840->regs;
  int v1844 = v1843[1];
  bool v1851 = v1844 == 36;
  ret_assert(v1851);
  struct StateG * v1846 = slot_94(v1840);
  return v1846;
}

struct StateG * slot_11(struct StateG * v404) {
  int v405 = v404->timer;
  int v411 = v405 + 1;
  v404->timer = v411;
  int * v407 = v404->regs;
  v407[18] = 1;
  struct StateG * v409 = slot_13(v404);
  return v409;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

void ret_assert(bool c) { koika_assert(c, "return address"); }

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
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
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}