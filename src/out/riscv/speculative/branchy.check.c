// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]

#define NUM_REGS 32
#define MEM_SIZE 32
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
  int mem[32];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v464);
struct StateT * slot_43(struct StateT * v1528);
struct StateT * slot_6(struct StateT * v185);
struct StateT * slot_47(struct StateT * v1682);
struct StateT * slot_29(struct StateT * v1023);
struct StateT * slot_55(struct StateT * v1909);
struct StateT * slot_16(struct StateT * v533);
struct StateT * slot_5(struct StateT * v169);
struct StateT * slot_7(struct StateT * v290);
struct StateT * slot_31(struct StateT * v1055);
struct StateT * slot_54(struct StateT * v1893);
struct StateT * slot_26(struct StateT * v881);
struct StateT * slot_10(struct StateT * v343);
struct StateT * slot_19(struct StateT * v675);
struct StateT * slot_58(struct StateT * v2050);
struct StateT * slot_14(struct StateT * v501);
struct StateT * slot_53(struct StateT * v1876);
struct StateT * slot_44(struct StateT * v1545);
struct StateT * slot_28(struct StateT * v1006);
struct StateT * slot_32(struct StateT * v1160);
struct StateT * slot_17(struct StateT * v638);
struct StateT * slot_49(struct StateT * v1719);
struct StateT * slot_33(struct StateT * v1180);
struct StateT * slot_50(struct StateT * v1735);
struct StateT * slot_36(struct StateT * v1229);
struct StateT * slot_37(struct StateT * v1334);
struct StateT * slot_57(struct StateT * v2030);
struct StateT * slot_59(struct StateT * v2067);
struct StateT * slot_40(struct StateT * v1387);
struct StateT * slot_27(struct StateT * v986);
struct StateT * slot_15(struct StateT * v517);
struct StateT * slot_62(struct StateT * v2204);
struct StateT * slot_48(struct StateT * v1702);
struct StateT * slot_22(struct StateT * v812);
struct StateT * slot_35(struct StateT * v1213);
struct StateT * slot_56(struct StateT * v1925);
struct StateT * slot_34(struct StateT * v1197);
struct StateT * slot_51(struct StateT * v1751);
struct StateT * slot_52(struct StateT * v1856);
struct StateT * slot_25(struct StateT * v865);
struct StateT * slot_23(struct StateT * v832);
struct StateT * slot_2(struct StateT * v116);
struct StateT * slot_21(struct StateT * v707);
struct StateT * slot_3(struct StateT * v136);
struct StateT * slot_45(struct StateT * v1561);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v484);
struct StateT * slot_38(struct StateT * v1354);
struct StateT * slot_24(struct StateT * v849);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v1508);
struct StateT * slot_46(struct StateT * v1577);
struct StateT * slot_20(struct StateT * v691);
struct StateT * slot_61(struct StateT * v2099);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v1403);
struct StateT * slot_39(struct StateT * v1371);
struct StateT * slot_8(struct StateT * v310);
struct StateT * slot_30(struct StateT * v1039);
struct StateT * slot_60(struct StateT * v2083);
struct StateT * slot_4(struct StateT * v153);
struct StateT * slot_18(struct StateT * v658);
struct StateT * slot_9(struct StateT * v327);
struct StateT * slot_11(struct StateT * v359);
struct StateT * slot_12(struct StateT * v464) {
  int v465 = v464->timer;
  int v475 = v465 + 1;
  v464->timer = v475;
  int * v467 = v464->regs;
  int v468 = v467[5];
  int * v469 = v464->regs;
  int v470 = v469[7];
  int * v471 = v464->regs;
  int v481 = v468 ^ v470;
  v471[5] = v481;
  struct StateT * v473 = slot_13(v464);
  return v473;
}

struct StateT * slot_43(struct StateT * v1528) {
  int v1529 = v1528->timer;
  int v1537 = v1529 + 1;
  v1528->timer = v1537;
  int * v1531 = v1528->regs;
  int v1532 = v1531[11];
  int * v1533 = v1528->regs;
  int v1542 = (int)((unsigned int)v1532 >> 10);
  v1533[6] = v1542;
  struct StateT * v1535 = slot_44(v1528);
  return v1535;
}

struct StateT * slot_6(struct StateT * v185) {
  int v186 = v185->timer;
  int v244 = v186 + 1;
  v185->timer = v244;
  int * v188 = v185->regs;
  int v189 = v188[6];
  int * v190 = v185->cache_keys;
  int v191 = v190[0];
  bool v249 = v191 == ((int)((unsigned int)v189 >> 2));
  int v239;
  if (v249) {
    int * v192 = v185->cache_vals;
    int v193 = v192[0];
    v239 = v193;
  } else {
    int * v195 = v185->cache_keys;
    int v196 = v195[1];
    bool v254 = v196 == ((int)((unsigned int)v189 >> 2));
    int v237;
    if (v254) {
      int * v197 = v185->cache_vals;
      int v198 = v197[1];
      int * v199 = v185->cache_keys;
      int * v200 = v185->cache_keys;
      int v201 = v200[0];
      v199[1] = v201;
      int * v203 = v185->cache_vals;
      int * v204 = v185->cache_vals;
      int v205 = v204[0];
      v203[1] = v205;
      int * v207 = v185->cache_keys;
      int v263 = (int)((unsigned int)v189 >> 2);
      v207[0] = v263;
      int * v209 = v185->cache_vals;
      v209[0] = v198;
      int v211 = v185->timer;
      int v266 = v211 + 1;
      v185->timer = v266;
      v237 = v198;
    } else {
      int * v214 = v185->mem;
      int v268 = (int)((unsigned int)v189 >> 2);
      int v215 = v214[v268];
      int * v216 = v185->mem;
      int * v217 = v185->cache_keys;
      int v218 = v217[1];
      int * v219 = v185->cache_vals;
      int v220 = v219[1];
      v216[v218] = v220;
      int * v222 = v185->cache_keys;
      int * v223 = v185->cache_keys;
      int v224 = v223[0];
      v222[1] = v224;
      int * v226 = v185->cache_vals;
      int * v227 = v185->cache_vals;
      int v228 = v227[0];
      v226[1] = v228;
      int * v230 = v185->cache_keys;
      v230[0] = v268;
      int * v232 = v185->cache_vals;
      v232[0] = v215;
      int v234 = v185->timer;
      int v283 = v234 + 100;
      v185->timer = v283;
      v237 = v215;
    }
    v239 = v237;
  }
  int * v240 = v185->regs;
  v240[7] = v239;
  struct StateT * v242 = slot_7(v185);
  return v242;
}

struct StateT * slot_47(struct StateT * v1682) {
  int v1683 = v1682->timer;
  int v1693 = v1683 + 1;
  v1682->timer = v1693;
  int * v1685 = v1682->regs;
  int v1686 = v1685[5];
  int * v1687 = v1682->regs;
  int v1688 = v1687[7];
  int * v1689 = v1682->regs;
  int v1699 = v1686 ^ v1688;
  v1689[5] = v1699;
  struct StateT * v1691 = slot_48(v1682);
  return v1691;
}

struct StateT * slot_29(struct StateT * v1023) {
  int v1024 = v1023->timer;
  int v1032 = v1024 + 1;
  v1023->timer = v1032;
  int * v1026 = v1023->regs;
  int v1027 = v1026[6];
  int * v1028 = v1023->regs;
  int v1036 = v1027 & 31;
  v1028[6] = v1036;
  struct StateT * v1030 = slot_30(v1023);
  return v1030;
}

struct StateT * slot_55(struct StateT * v1909) {
  int v1910 = v1909->timer;
  int v1918 = v1910 + 1;
  v1909->timer = v1918;
  int * v1912 = v1909->regs;
  int v1913 = v1912[6];
  int * v1914 = v1909->regs;
  int v1922 = v1913 << 2;
  v1914[6] = v1922;
  struct StateT * v1916 = slot_56(v1909);
  return v1916;
}

struct StateT * slot_16(struct StateT * v533) {
  int v534 = v533->timer;
  int v592 = v534 + 1;
  v533->timer = v592;
  int * v536 = v533->regs;
  int v537 = v536[6];
  int * v538 = v533->cache_keys;
  int v539 = v538[0];
  bool v597 = v539 == ((int)((unsigned int)v537 >> 2));
  int v587;
  if (v597) {
    int * v540 = v533->cache_vals;
    int v541 = v540[0];
    v587 = v541;
  } else {
    int * v543 = v533->cache_keys;
    int v544 = v543[1];
    bool v602 = v544 == ((int)((unsigned int)v537 >> 2));
    int v585;
    if (v602) {
      int * v545 = v533->cache_vals;
      int v546 = v545[1];
      int * v547 = v533->cache_keys;
      int * v548 = v533->cache_keys;
      int v549 = v548[0];
      v547[1] = v549;
      int * v551 = v533->cache_vals;
      int * v552 = v533->cache_vals;
      int v553 = v552[0];
      v551[1] = v553;
      int * v555 = v533->cache_keys;
      int v611 = (int)((unsigned int)v537 >> 2);
      v555[0] = v611;
      int * v557 = v533->cache_vals;
      v557[0] = v546;
      int v559 = v533->timer;
      int v614 = v559 + 1;
      v533->timer = v614;
      v585 = v546;
    } else {
      int * v562 = v533->mem;
      int v616 = (int)((unsigned int)v537 >> 2);
      int v563 = v562[v616];
      int * v564 = v533->mem;
      int * v565 = v533->cache_keys;
      int v566 = v565[1];
      int * v567 = v533->cache_vals;
      int v568 = v567[1];
      v564[v566] = v568;
      int * v570 = v533->cache_keys;
      int * v571 = v533->cache_keys;
      int v572 = v571[0];
      v570[1] = v572;
      int * v574 = v533->cache_vals;
      int * v575 = v533->cache_vals;
      int v576 = v575[0];
      v574[1] = v576;
      int * v578 = v533->cache_keys;
      v578[0] = v616;
      int * v580 = v533->cache_vals;
      v580[0] = v563;
      int v582 = v533->timer;
      int v631 = v582 + 100;
      v533->timer = v631;
      v585 = v563;
    }
    v587 = v585;
  }
  int * v588 = v533->regs;
  v588[7] = v587;
  struct StateT * v590 = slot_17(v533);
  return v590;
}

struct StateT * slot_5(struct StateT * v169) {
  int v170 = v169->timer;
  int v178 = v170 + 1;
  v169->timer = v178;
  int * v172 = v169->regs;
  int v173 = v172[6];
  int * v174 = v169->regs;
  int v182 = v173 << 2;
  v174[6] = v182;
  struct StateT * v176 = slot_6(v169);
  return v176;
}

struct StateT * slot_7(struct StateT * v290) {
  int v291 = v290->timer;
  int v301 = v291 + 1;
  v290->timer = v301;
  int * v293 = v290->regs;
  int v294 = v293[5];
  int * v295 = v290->regs;
  int v296 = v295[7];
  int * v297 = v290->regs;
  int v307 = v294 ^ v296;
  v297[5] = v307;
  struct StateT * v299 = slot_8(v290);
  return v299;
}

struct StateT * slot_31(struct StateT * v1055) {
  int v1056 = v1055->timer;
  int v1114 = v1056 + 1;
  v1055->timer = v1114;
  int * v1058 = v1055->regs;
  int v1059 = v1058[6];
  int * v1060 = v1055->cache_keys;
  int v1061 = v1060[0];
  bool v1119 = v1061 == ((int)((unsigned int)v1059 >> 2));
  int v1109;
  if (v1119) {
    int * v1062 = v1055->cache_vals;
    int v1063 = v1062[0];
    v1109 = v1063;
  } else {
    int * v1065 = v1055->cache_keys;
    int v1066 = v1065[1];
    bool v1124 = v1066 == ((int)((unsigned int)v1059 >> 2));
    int v1107;
    if (v1124) {
      int * v1067 = v1055->cache_vals;
      int v1068 = v1067[1];
      int * v1069 = v1055->cache_keys;
      int * v1070 = v1055->cache_keys;
      int v1071 = v1070[0];
      v1069[1] = v1071;
      int * v1073 = v1055->cache_vals;
      int * v1074 = v1055->cache_vals;
      int v1075 = v1074[0];
      v1073[1] = v1075;
      int * v1077 = v1055->cache_keys;
      int v1133 = (int)((unsigned int)v1059 >> 2);
      v1077[0] = v1133;
      int * v1079 = v1055->cache_vals;
      v1079[0] = v1068;
      int v1081 = v1055->timer;
      int v1136 = v1081 + 1;
      v1055->timer = v1136;
      v1107 = v1068;
    } else {
      int * v1084 = v1055->mem;
      int v1138 = (int)((unsigned int)v1059 >> 2);
      int v1085 = v1084[v1138];
      int * v1086 = v1055->mem;
      int * v1087 = v1055->cache_keys;
      int v1088 = v1087[1];
      int * v1089 = v1055->cache_vals;
      int v1090 = v1089[1];
      v1086[v1088] = v1090;
      int * v1092 = v1055->cache_keys;
      int * v1093 = v1055->cache_keys;
      int v1094 = v1093[0];
      v1092[1] = v1094;
      int * v1096 = v1055->cache_vals;
      int * v1097 = v1055->cache_vals;
      int v1098 = v1097[0];
      v1096[1] = v1098;
      int * v1100 = v1055->cache_keys;
      v1100[0] = v1138;
      int * v1102 = v1055->cache_vals;
      v1102[0] = v1085;
      int v1104 = v1055->timer;
      int v1153 = v1104 + 100;
      v1055->timer = v1153;
      v1107 = v1085;
    }
    v1109 = v1107;
  }
  int * v1110 = v1055->regs;
  v1110[7] = v1109;
  struct StateT * v1112 = slot_32(v1055);
  return v1112;
}

struct StateT * slot_54(struct StateT * v1893) {
  int v1894 = v1893->timer;
  int v1902 = v1894 + 1;
  v1893->timer = v1902;
  int * v1896 = v1893->regs;
  int v1897 = v1896[6];
  int * v1898 = v1893->regs;
  int v1906 = v1897 & 31;
  v1898[6] = v1906;
  struct StateT * v1900 = slot_55(v1893);
  return v1900;
}

struct StateT * slot_26(struct StateT * v881) {
  int v882 = v881->timer;
  int v940 = v882 + 1;
  v881->timer = v940;
  int * v884 = v881->regs;
  int v885 = v884[6];
  int * v886 = v881->cache_keys;
  int v887 = v886[0];
  bool v945 = v887 == ((int)((unsigned int)v885 >> 2));
  int v935;
  if (v945) {
    int * v888 = v881->cache_vals;
    int v889 = v888[0];
    v935 = v889;
  } else {
    int * v891 = v881->cache_keys;
    int v892 = v891[1];
    bool v950 = v892 == ((int)((unsigned int)v885 >> 2));
    int v933;
    if (v950) {
      int * v893 = v881->cache_vals;
      int v894 = v893[1];
      int * v895 = v881->cache_keys;
      int * v896 = v881->cache_keys;
      int v897 = v896[0];
      v895[1] = v897;
      int * v899 = v881->cache_vals;
      int * v900 = v881->cache_vals;
      int v901 = v900[0];
      v899[1] = v901;
      int * v903 = v881->cache_keys;
      int v959 = (int)((unsigned int)v885 >> 2);
      v903[0] = v959;
      int * v905 = v881->cache_vals;
      v905[0] = v894;
      int v907 = v881->timer;
      int v962 = v907 + 1;
      v881->timer = v962;
      v933 = v894;
    } else {
      int * v910 = v881->mem;
      int v964 = (int)((unsigned int)v885 >> 2);
      int v911 = v910[v964];
      int * v912 = v881->mem;
      int * v913 = v881->cache_keys;
      int v914 = v913[1];
      int * v915 = v881->cache_vals;
      int v916 = v915[1];
      v912[v914] = v916;
      int * v918 = v881->cache_keys;
      int * v919 = v881->cache_keys;
      int v920 = v919[0];
      v918[1] = v920;
      int * v922 = v881->cache_vals;
      int * v923 = v881->cache_vals;
      int v924 = v923[0];
      v922[1] = v924;
      int * v926 = v881->cache_keys;
      v926[0] = v964;
      int * v928 = v881->cache_vals;
      v928[0] = v911;
      int v930 = v881->timer;
      int v979 = v930 + 100;
      v881->timer = v979;
      v933 = v911;
    }
    v935 = v933;
  }
  int * v936 = v881->regs;
  v936[7] = v935;
  struct StateT * v938 = slot_27(v881);
  return v938;
}

struct StateT * slot_10(struct StateT * v343) {
  int v344 = v343->timer;
  int v352 = v344 + 1;
  v343->timer = v352;
  int * v346 = v343->regs;
  int v347 = v346[6];
  int * v348 = v343->regs;
  int v356 = v347 << 2;
  v348[6] = v356;
  struct StateT * v350 = slot_11(v343);
  return v350;
}

struct StateT * slot_19(struct StateT * v675) {
  int v676 = v675->timer;
  int v684 = v676 + 1;
  v675->timer = v684;
  int * v678 = v675->regs;
  int v679 = v678[6];
  int * v680 = v675->regs;
  int v688 = v679 & 31;
  v680[6] = v688;
  struct StateT * v682 = slot_20(v675);
  return v682;
}

struct StateT * slot_58(struct StateT * v2050) {
  int v2051 = v2050->timer;
  int v2059 = v2051 + 1;
  v2050->timer = v2059;
  int * v2053 = v2050->regs;
  int v2054 = v2053[11];
  int * v2055 = v2050->regs;
  int v2064 = (int)((unsigned int)v2054 >> 25);
  v2055[6] = v2064;
  struct StateT * v2057 = slot_59(v2050);
  return v2057;
}

struct StateT * slot_14(struct StateT * v501) {
  int v502 = v501->timer;
  int v510 = v502 + 1;
  v501->timer = v510;
  int * v504 = v501->regs;
  int v505 = v504[6];
  int * v506 = v501->regs;
  int v514 = v505 & 31;
  v506[6] = v514;
  struct StateT * v508 = slot_15(v501);
  return v508;
}

struct StateT * slot_53(struct StateT * v1876) {
  int v1877 = v1876->timer;
  int v1885 = v1877 + 1;
  v1876->timer = v1885;
  int * v1879 = v1876->regs;
  int v1880 = v1879[11];
  int * v1881 = v1876->regs;
  int v1890 = (int)((unsigned int)v1880 >> 20);
  v1881[6] = v1890;
  struct StateT * v1883 = slot_54(v1876);
  return v1883;
}

struct StateT * slot_44(struct StateT * v1545) {
  int v1546 = v1545->timer;
  int v1554 = v1546 + 1;
  v1545->timer = v1554;
  int * v1548 = v1545->regs;
  int v1549 = v1548[6];
  int * v1550 = v1545->regs;
  int v1558 = v1549 & 31;
  v1550[6] = v1558;
  struct StateT * v1552 = slot_45(v1545);
  return v1552;
}

struct StateT * slot_28(struct StateT * v1006) {
  int v1007 = v1006->timer;
  int v1015 = v1007 + 1;
  v1006->timer = v1015;
  int * v1009 = v1006->regs;
  int v1010 = v1009[10];
  int * v1011 = v1006->regs;
  int v1020 = (int)((unsigned int)v1010 >> 25);
  v1011[6] = v1020;
  struct StateT * v1013 = slot_29(v1006);
  return v1013;
}

struct StateT * slot_32(struct StateT * v1160) {
  int v1161 = v1160->timer;
  int v1171 = v1161 + 1;
  v1160->timer = v1171;
  int * v1163 = v1160->regs;
  int v1164 = v1163[5];
  int * v1165 = v1160->regs;
  int v1166 = v1165[7];
  int * v1167 = v1160->regs;
  int v1177 = v1164 ^ v1166;
  v1167[5] = v1177;
  struct StateT * v1169 = slot_33(v1160);
  return v1169;
}

struct StateT * slot_17(struct StateT * v638) {
  int v639 = v638->timer;
  int v649 = v639 + 1;
  v638->timer = v649;
  int * v641 = v638->regs;
  int v642 = v641[5];
  int * v643 = v638->regs;
  int v644 = v643[7];
  int * v645 = v638->regs;
  int v655 = v642 ^ v644;
  v645[5] = v655;
  struct StateT * v647 = slot_18(v638);
  return v647;
}

struct StateT * slot_49(struct StateT * v1719) {
  int v1720 = v1719->timer;
  int v1728 = v1720 + 1;
  v1719->timer = v1728;
  int * v1722 = v1719->regs;
  int v1723 = v1722[6];
  int * v1724 = v1719->regs;
  int v1732 = v1723 & 31;
  v1724[6] = v1732;
  struct StateT * v1726 = slot_50(v1719);
  return v1726;
}

struct StateT * slot_33(struct StateT * v1180) {
  int v1181 = v1180->timer;
  int v1189 = v1181 + 1;
  v1180->timer = v1189;
  int * v1183 = v1180->regs;
  int v1184 = v1183[11];
  int * v1185 = v1180->regs;
  v1185[6] = v1184;
  struct StateT * v1187 = slot_34(v1180);
  return v1187;
}

struct StateT * slot_50(struct StateT * v1735) {
  int v1736 = v1735->timer;
  int v1744 = v1736 + 1;
  v1735->timer = v1744;
  int * v1738 = v1735->regs;
  int v1739 = v1738[6];
  int * v1740 = v1735->regs;
  int v1748 = v1739 << 2;
  v1740[6] = v1748;
  struct StateT * v1742 = slot_51(v1735);
  return v1742;
}

struct StateT * slot_36(struct StateT * v1229) {
  int v1230 = v1229->timer;
  int v1288 = v1230 + 1;
  v1229->timer = v1288;
  int * v1232 = v1229->regs;
  int v1233 = v1232[6];
  int * v1234 = v1229->cache_keys;
  int v1235 = v1234[0];
  bool v1293 = v1235 == ((int)((unsigned int)v1233 >> 2));
  int v1283;
  if (v1293) {
    int * v1236 = v1229->cache_vals;
    int v1237 = v1236[0];
    v1283 = v1237;
  } else {
    int * v1239 = v1229->cache_keys;
    int v1240 = v1239[1];
    bool v1298 = v1240 == ((int)((unsigned int)v1233 >> 2));
    int v1281;
    if (v1298) {
      int * v1241 = v1229->cache_vals;
      int v1242 = v1241[1];
      int * v1243 = v1229->cache_keys;
      int * v1244 = v1229->cache_keys;
      int v1245 = v1244[0];
      v1243[1] = v1245;
      int * v1247 = v1229->cache_vals;
      int * v1248 = v1229->cache_vals;
      int v1249 = v1248[0];
      v1247[1] = v1249;
      int * v1251 = v1229->cache_keys;
      int v1307 = (int)((unsigned int)v1233 >> 2);
      v1251[0] = v1307;
      int * v1253 = v1229->cache_vals;
      v1253[0] = v1242;
      int v1255 = v1229->timer;
      int v1310 = v1255 + 1;
      v1229->timer = v1310;
      v1281 = v1242;
    } else {
      int * v1258 = v1229->mem;
      int v1312 = (int)((unsigned int)v1233 >> 2);
      int v1259 = v1258[v1312];
      int * v1260 = v1229->mem;
      int * v1261 = v1229->cache_keys;
      int v1262 = v1261[1];
      int * v1263 = v1229->cache_vals;
      int v1264 = v1263[1];
      v1260[v1262] = v1264;
      int * v1266 = v1229->cache_keys;
      int * v1267 = v1229->cache_keys;
      int v1268 = v1267[0];
      v1266[1] = v1268;
      int * v1270 = v1229->cache_vals;
      int * v1271 = v1229->cache_vals;
      int v1272 = v1271[0];
      v1270[1] = v1272;
      int * v1274 = v1229->cache_keys;
      v1274[0] = v1312;
      int * v1276 = v1229->cache_vals;
      v1276[0] = v1259;
      int v1278 = v1229->timer;
      int v1327 = v1278 + 100;
      v1229->timer = v1327;
      v1281 = v1259;
    }
    v1283 = v1281;
  }
  int * v1284 = v1229->regs;
  v1284[7] = v1283;
  struct StateT * v1286 = slot_37(v1229);
  return v1286;
}

struct StateT * slot_37(struct StateT * v1334) {
  int v1335 = v1334->timer;
  int v1345 = v1335 + 1;
  v1334->timer = v1345;
  int * v1337 = v1334->regs;
  int v1338 = v1337[5];
  int * v1339 = v1334->regs;
  int v1340 = v1339[7];
  int * v1341 = v1334->regs;
  int v1351 = v1338 ^ v1340;
  v1341[5] = v1351;
  struct StateT * v1343 = slot_38(v1334);
  return v1343;
}

struct StateT * slot_57(struct StateT * v2030) {
  int v2031 = v2030->timer;
  int v2041 = v2031 + 1;
  v2030->timer = v2041;
  int * v2033 = v2030->regs;
  int v2034 = v2033[5];
  int * v2035 = v2030->regs;
  int v2036 = v2035[7];
  int * v2037 = v2030->regs;
  int v2047 = v2034 ^ v2036;
  v2037[5] = v2047;
  struct StateT * v2039 = slot_58(v2030);
  return v2039;
}

struct StateT * slot_59(struct StateT * v2067) {
  int v2068 = v2067->timer;
  int v2076 = v2068 + 1;
  v2067->timer = v2076;
  int * v2070 = v2067->regs;
  int v2071 = v2070[6];
  int * v2072 = v2067->regs;
  int v2080 = v2071 & 31;
  v2072[6] = v2080;
  struct StateT * v2074 = slot_60(v2067);
  return v2074;
}

struct StateT * slot_40(struct StateT * v1387) {
  int v1388 = v1387->timer;
  int v1396 = v1388 + 1;
  v1387->timer = v1396;
  int * v1390 = v1387->regs;
  int v1391 = v1390[6];
  int * v1392 = v1387->regs;
  int v1400 = v1391 << 2;
  v1392[6] = v1400;
  struct StateT * v1394 = slot_41(v1387);
  return v1394;
}

struct StateT * slot_27(struct StateT * v986) {
  int v987 = v986->timer;
  int v997 = v987 + 1;
  v986->timer = v997;
  int * v989 = v986->regs;
  int v990 = v989[5];
  int * v991 = v986->regs;
  int v992 = v991[7];
  int * v993 = v986->regs;
  int v1003 = v990 ^ v992;
  v993[5] = v1003;
  struct StateT * v995 = slot_28(v986);
  return v995;
}

struct StateT * slot_15(struct StateT * v517) {
  int v518 = v517->timer;
  int v526 = v518 + 1;
  v517->timer = v526;
  int * v520 = v517->regs;
  int v521 = v520[6];
  int * v522 = v517->regs;
  int v530 = v521 << 2;
  v522[6] = v530;
  struct StateT * v524 = slot_16(v517);
  return v524;
}

struct StateT * slot_62(struct StateT * v2204) {
  int v2205 = v2204->timer;
  int v2214 = v2205 + 1;
  v2204->timer = v2214;
  int * v2207 = v2204->regs;
  int v2208 = v2207[5];
  int * v2209 = v2204->regs;
  int v2210 = v2209[7];
  int * v2211 = v2204->regs;
  int v2220 = v2208 ^ v2210;
  v2211[5] = v2220;
  return v2204;
}

struct StateT * slot_48(struct StateT * v1702) {
  int v1703 = v1702->timer;
  int v1711 = v1703 + 1;
  v1702->timer = v1711;
  int * v1705 = v1702->regs;
  int v1706 = v1705[11];
  int * v1707 = v1702->regs;
  int v1716 = (int)((unsigned int)v1706 >> 15);
  v1707[6] = v1716;
  struct StateT * v1709 = slot_49(v1702);
  return v1709;
}

struct StateT * slot_22(struct StateT * v812) {
  int v813 = v812->timer;
  int v823 = v813 + 1;
  v812->timer = v823;
  int * v815 = v812->regs;
  int v816 = v815[5];
  int * v817 = v812->regs;
  int v818 = v817[7];
  int * v819 = v812->regs;
  int v829 = v816 ^ v818;
  v819[5] = v829;
  struct StateT * v821 = slot_23(v812);
  return v821;
}

struct StateT * slot_35(struct StateT * v1213) {
  int v1214 = v1213->timer;
  int v1222 = v1214 + 1;
  v1213->timer = v1222;
  int * v1216 = v1213->regs;
  int v1217 = v1216[6];
  int * v1218 = v1213->regs;
  int v1226 = v1217 << 2;
  v1218[6] = v1226;
  struct StateT * v1220 = slot_36(v1213);
  return v1220;
}

struct StateT * slot_56(struct StateT * v1925) {
  int v1926 = v1925->timer;
  int v1984 = v1926 + 1;
  v1925->timer = v1984;
  int * v1928 = v1925->regs;
  int v1929 = v1928[6];
  int * v1930 = v1925->cache_keys;
  int v1931 = v1930[0];
  bool v1989 = v1931 == ((int)((unsigned int)v1929 >> 2));
  int v1979;
  if (v1989) {
    int * v1932 = v1925->cache_vals;
    int v1933 = v1932[0];
    v1979 = v1933;
  } else {
    int * v1935 = v1925->cache_keys;
    int v1936 = v1935[1];
    bool v1994 = v1936 == ((int)((unsigned int)v1929 >> 2));
    int v1977;
    if (v1994) {
      int * v1937 = v1925->cache_vals;
      int v1938 = v1937[1];
      int * v1939 = v1925->cache_keys;
      int * v1940 = v1925->cache_keys;
      int v1941 = v1940[0];
      v1939[1] = v1941;
      int * v1943 = v1925->cache_vals;
      int * v1944 = v1925->cache_vals;
      int v1945 = v1944[0];
      v1943[1] = v1945;
      int * v1947 = v1925->cache_keys;
      int v2003 = (int)((unsigned int)v1929 >> 2);
      v1947[0] = v2003;
      int * v1949 = v1925->cache_vals;
      v1949[0] = v1938;
      int v1951 = v1925->timer;
      int v2006 = v1951 + 1;
      v1925->timer = v2006;
      v1977 = v1938;
    } else {
      int * v1954 = v1925->mem;
      int v2008 = (int)((unsigned int)v1929 >> 2);
      int v1955 = v1954[v2008];
      int * v1956 = v1925->mem;
      int * v1957 = v1925->cache_keys;
      int v1958 = v1957[1];
      int * v1959 = v1925->cache_vals;
      int v1960 = v1959[1];
      v1956[v1958] = v1960;
      int * v1962 = v1925->cache_keys;
      int * v1963 = v1925->cache_keys;
      int v1964 = v1963[0];
      v1962[1] = v1964;
      int * v1966 = v1925->cache_vals;
      int * v1967 = v1925->cache_vals;
      int v1968 = v1967[0];
      v1966[1] = v1968;
      int * v1970 = v1925->cache_keys;
      v1970[0] = v2008;
      int * v1972 = v1925->cache_vals;
      v1972[0] = v1955;
      int v1974 = v1925->timer;
      int v2023 = v1974 + 100;
      v1925->timer = v2023;
      v1977 = v1955;
    }
    v1979 = v1977;
  }
  int * v1980 = v1925->regs;
  v1980[7] = v1979;
  struct StateT * v1982 = slot_57(v1925);
  return v1982;
}

struct StateT * slot_34(struct StateT * v1197) {
  int v1198 = v1197->timer;
  int v1206 = v1198 + 1;
  v1197->timer = v1206;
  int * v1200 = v1197->regs;
  int v1201 = v1200[6];
  int * v1202 = v1197->regs;
  int v1210 = v1201 & 31;
  v1202[6] = v1210;
  struct StateT * v1204 = slot_35(v1197);
  return v1204;
}

struct StateT * slot_51(struct StateT * v1751) {
  int v1752 = v1751->timer;
  int v1810 = v1752 + 1;
  v1751->timer = v1810;
  int * v1754 = v1751->regs;
  int v1755 = v1754[6];
  int * v1756 = v1751->cache_keys;
  int v1757 = v1756[0];
  bool v1815 = v1757 == ((int)((unsigned int)v1755 >> 2));
  int v1805;
  if (v1815) {
    int * v1758 = v1751->cache_vals;
    int v1759 = v1758[0];
    v1805 = v1759;
  } else {
    int * v1761 = v1751->cache_keys;
    int v1762 = v1761[1];
    bool v1820 = v1762 == ((int)((unsigned int)v1755 >> 2));
    int v1803;
    if (v1820) {
      int * v1763 = v1751->cache_vals;
      int v1764 = v1763[1];
      int * v1765 = v1751->cache_keys;
      int * v1766 = v1751->cache_keys;
      int v1767 = v1766[0];
      v1765[1] = v1767;
      int * v1769 = v1751->cache_vals;
      int * v1770 = v1751->cache_vals;
      int v1771 = v1770[0];
      v1769[1] = v1771;
      int * v1773 = v1751->cache_keys;
      int v1829 = (int)((unsigned int)v1755 >> 2);
      v1773[0] = v1829;
      int * v1775 = v1751->cache_vals;
      v1775[0] = v1764;
      int v1777 = v1751->timer;
      int v1832 = v1777 + 1;
      v1751->timer = v1832;
      v1803 = v1764;
    } else {
      int * v1780 = v1751->mem;
      int v1834 = (int)((unsigned int)v1755 >> 2);
      int v1781 = v1780[v1834];
      int * v1782 = v1751->mem;
      int * v1783 = v1751->cache_keys;
      int v1784 = v1783[1];
      int * v1785 = v1751->cache_vals;
      int v1786 = v1785[1];
      v1782[v1784] = v1786;
      int * v1788 = v1751->cache_keys;
      int * v1789 = v1751->cache_keys;
      int v1790 = v1789[0];
      v1788[1] = v1790;
      int * v1792 = v1751->cache_vals;
      int * v1793 = v1751->cache_vals;
      int v1794 = v1793[0];
      v1792[1] = v1794;
      int * v1796 = v1751->cache_keys;
      v1796[0] = v1834;
      int * v1798 = v1751->cache_vals;
      v1798[0] = v1781;
      int v1800 = v1751->timer;
      int v1849 = v1800 + 100;
      v1751->timer = v1849;
      v1803 = v1781;
    }
    v1805 = v1803;
  }
  int * v1806 = v1751->regs;
  v1806[7] = v1805;
  struct StateT * v1808 = slot_52(v1751);
  return v1808;
}

struct StateT * slot_52(struct StateT * v1856) {
  int v1857 = v1856->timer;
  int v1867 = v1857 + 1;
  v1856->timer = v1867;
  int * v1859 = v1856->regs;
  int v1860 = v1859[5];
  int * v1861 = v1856->regs;
  int v1862 = v1861[7];
  int * v1863 = v1856->regs;
  int v1873 = v1860 ^ v1862;
  v1863[5] = v1873;
  struct StateT * v1865 = slot_53(v1856);
  return v1865;
}

struct StateT * slot_25(struct StateT * v865) {
  int v866 = v865->timer;
  int v874 = v866 + 1;
  v865->timer = v874;
  int * v868 = v865->regs;
  int v869 = v868[6];
  int * v870 = v865->regs;
  int v878 = v869 << 2;
  v870[6] = v878;
  struct StateT * v872 = slot_26(v865);
  return v872;
}

struct StateT * slot_23(struct StateT * v832) {
  int v833 = v832->timer;
  int v841 = v833 + 1;
  v832->timer = v841;
  int * v835 = v832->regs;
  int v836 = v835[10];
  int * v837 = v832->regs;
  int v846 = (int)((unsigned int)v836 >> 20);
  v837[6] = v846;
  struct StateT * v839 = slot_24(v832);
  return v839;
}

struct StateT * slot_2(struct StateT * v116) {
  int v117 = v116->timer;
  int v127 = v117 + 1;
  v116->timer = v127;
  int * v119 = v116->regs;
  int v120 = v119[5];
  int * v121 = v116->regs;
  int v122 = v121[9];
  int * v123 = v116->regs;
  int v133 = v120 ^ v122;
  v123[5] = v133;
  struct StateT * v125 = slot_3(v116);
  return v125;
}

struct StateT * slot_21(struct StateT * v707) {
  int v708 = v707->timer;
  int v766 = v708 + 1;
  v707->timer = v766;
  int * v710 = v707->regs;
  int v711 = v710[6];
  int * v712 = v707->cache_keys;
  int v713 = v712[0];
  bool v771 = v713 == ((int)((unsigned int)v711 >> 2));
  int v761;
  if (v771) {
    int * v714 = v707->cache_vals;
    int v715 = v714[0];
    v761 = v715;
  } else {
    int * v717 = v707->cache_keys;
    int v718 = v717[1];
    bool v776 = v718 == ((int)((unsigned int)v711 >> 2));
    int v759;
    if (v776) {
      int * v719 = v707->cache_vals;
      int v720 = v719[1];
      int * v721 = v707->cache_keys;
      int * v722 = v707->cache_keys;
      int v723 = v722[0];
      v721[1] = v723;
      int * v725 = v707->cache_vals;
      int * v726 = v707->cache_vals;
      int v727 = v726[0];
      v725[1] = v727;
      int * v729 = v707->cache_keys;
      int v785 = (int)((unsigned int)v711 >> 2);
      v729[0] = v785;
      int * v731 = v707->cache_vals;
      v731[0] = v720;
      int v733 = v707->timer;
      int v788 = v733 + 1;
      v707->timer = v788;
      v759 = v720;
    } else {
      int * v736 = v707->mem;
      int v790 = (int)((unsigned int)v711 >> 2);
      int v737 = v736[v790];
      int * v738 = v707->mem;
      int * v739 = v707->cache_keys;
      int v740 = v739[1];
      int * v741 = v707->cache_vals;
      int v742 = v741[1];
      v738[v740] = v742;
      int * v744 = v707->cache_keys;
      int * v745 = v707->cache_keys;
      int v746 = v745[0];
      v744[1] = v746;
      int * v748 = v707->cache_vals;
      int * v749 = v707->cache_vals;
      int v750 = v749[0];
      v748[1] = v750;
      int * v752 = v707->cache_keys;
      v752[0] = v790;
      int * v754 = v707->cache_vals;
      v754[0] = v737;
      int v756 = v707->timer;
      int v805 = v756 + 100;
      v707->timer = v805;
      v759 = v737;
    }
    v761 = v759;
  }
  int * v762 = v707->regs;
  v762[7] = v761;
  struct StateT * v764 = slot_22(v707);
  return v764;
}

struct StateT * slot_3(struct StateT * v136) {
  int v137 = v136->timer;
  int v145 = v137 + 1;
  v136->timer = v145;
  int * v139 = v136->regs;
  int v140 = v139[10];
  int * v141 = v136->regs;
  v141[6] = v140;
  struct StateT * v143 = slot_4(v136);
  return v143;
}

struct StateT * slot_45(struct StateT * v1561) {
  int v1562 = v1561->timer;
  int v1570 = v1562 + 1;
  v1561->timer = v1570;
  int * v1564 = v1561->regs;
  int v1565 = v1564[6];
  int * v1566 = v1561->regs;
  int v1574 = v1565 << 2;
  v1566[6] = v1574;
  struct StateT * v1568 = slot_46(v1561);
  return v1568;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v72 = v16 + 1;
  v15->timer = v72;
  int * v18 = v15->cache_keys;
  int v19 = v18[0];
  bool v75 = v19 == 20;
  int v67;
  if (v75) {
    int * v20 = v15->cache_vals;
    int v21 = v20[0];
    v67 = v21;
  } else {
    int * v23 = v15->cache_keys;
    int v24 = v23[1];
    bool v80 = v24 == 20;
    int v65;
    if (v80) {
      int * v25 = v15->cache_vals;
      int v26 = v25[1];
      int * v27 = v15->cache_keys;
      int * v28 = v15->cache_keys;
      int v29 = v28[0];
      v27[1] = v29;
      int * v31 = v15->cache_vals;
      int * v32 = v15->cache_vals;
      int v33 = v32[0];
      v31[1] = v33;
      int * v35 = v15->cache_keys;
      v35[0] = 20;
      int * v37 = v15->cache_vals;
      v37[0] = v26;
      int v39 = v15->timer;
      int v92 = v39 + 1;
      v15->timer = v92;
      v65 = v26;
    } else {
      int * v42 = v15->mem;
      int v43 = v42[20];
      int * v44 = v15->mem;
      int * v45 = v15->cache_keys;
      int v46 = v45[1];
      int * v47 = v15->cache_vals;
      int v48 = v47[1];
      v44[v46] = v48;
      int * v50 = v15->cache_keys;
      int * v51 = v15->cache_keys;
      int v52 = v51[0];
      v50[1] = v52;
      int * v54 = v15->cache_vals;
      int * v55 = v15->cache_vals;
      int v56 = v55[0];
      v54[1] = v56;
      int * v58 = v15->cache_keys;
      v58[0] = 20;
      int * v60 = v15->cache_vals;
      v60[0] = v43;
      int v62 = v15->timer;
      int v109 = v62 + 100;
      v15->timer = v109;
      v65 = v43;
    }
    v67 = v65;
  }
  int * v68 = v15->regs;
  v68[9] = v67;
  struct StateT * v70 = slot_2(v15);
  return v70;
}

struct StateT * slot_13(struct StateT * v484) {
  int v485 = v484->timer;
  int v493 = v485 + 1;
  v484->timer = v493;
  int * v487 = v484->regs;
  int v488 = v487[10];
  int * v489 = v484->regs;
  int v498 = (int)((unsigned int)v488 >> 10);
  v489[6] = v498;
  struct StateT * v491 = slot_14(v484);
  return v491;
}

struct StateT * slot_38(struct StateT * v1354) {
  int v1355 = v1354->timer;
  int v1363 = v1355 + 1;
  v1354->timer = v1363;
  int * v1357 = v1354->regs;
  int v1358 = v1357[11];
  int * v1359 = v1354->regs;
  int v1368 = (int)((unsigned int)v1358 >> 5);
  v1359[6] = v1368;
  struct StateT * v1361 = slot_39(v1354);
  return v1361;
}

struct StateT * slot_24(struct StateT * v849) {
  int v850 = v849->timer;
  int v858 = v850 + 1;
  v849->timer = v858;
  int * v852 = v849->regs;
  int v853 = v852[6];
  int * v854 = v849->regs;
  int v862 = v853 & 31;
  v854[6] = v862;
  struct StateT * v856 = slot_25(v849);
  return v856;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_42(struct StateT * v1508) {
  int v1509 = v1508->timer;
  int v1519 = v1509 + 1;
  v1508->timer = v1519;
  int * v1511 = v1508->regs;
  int v1512 = v1511[5];
  int * v1513 = v1508->regs;
  int v1514 = v1513[7];
  int * v1515 = v1508->regs;
  int v1525 = v1512 ^ v1514;
  v1515[5] = v1525;
  struct StateT * v1517 = slot_43(v1508);
  return v1517;
}

struct StateT * slot_46(struct StateT * v1577) {
  int v1578 = v1577->timer;
  int v1636 = v1578 + 1;
  v1577->timer = v1636;
  int * v1580 = v1577->regs;
  int v1581 = v1580[6];
  int * v1582 = v1577->cache_keys;
  int v1583 = v1582[0];
  bool v1641 = v1583 == ((int)((unsigned int)v1581 >> 2));
  int v1631;
  if (v1641) {
    int * v1584 = v1577->cache_vals;
    int v1585 = v1584[0];
    v1631 = v1585;
  } else {
    int * v1587 = v1577->cache_keys;
    int v1588 = v1587[1];
    bool v1646 = v1588 == ((int)((unsigned int)v1581 >> 2));
    int v1629;
    if (v1646) {
      int * v1589 = v1577->cache_vals;
      int v1590 = v1589[1];
      int * v1591 = v1577->cache_keys;
      int * v1592 = v1577->cache_keys;
      int v1593 = v1592[0];
      v1591[1] = v1593;
      int * v1595 = v1577->cache_vals;
      int * v1596 = v1577->cache_vals;
      int v1597 = v1596[0];
      v1595[1] = v1597;
      int * v1599 = v1577->cache_keys;
      int v1655 = (int)((unsigned int)v1581 >> 2);
      v1599[0] = v1655;
      int * v1601 = v1577->cache_vals;
      v1601[0] = v1590;
      int v1603 = v1577->timer;
      int v1658 = v1603 + 1;
      v1577->timer = v1658;
      v1629 = v1590;
    } else {
      int * v1606 = v1577->mem;
      int v1660 = (int)((unsigned int)v1581 >> 2);
      int v1607 = v1606[v1660];
      int * v1608 = v1577->mem;
      int * v1609 = v1577->cache_keys;
      int v1610 = v1609[1];
      int * v1611 = v1577->cache_vals;
      int v1612 = v1611[1];
      v1608[v1610] = v1612;
      int * v1614 = v1577->cache_keys;
      int * v1615 = v1577->cache_keys;
      int v1616 = v1615[0];
      v1614[1] = v1616;
      int * v1618 = v1577->cache_vals;
      int * v1619 = v1577->cache_vals;
      int v1620 = v1619[0];
      v1618[1] = v1620;
      int * v1622 = v1577->cache_keys;
      v1622[0] = v1660;
      int * v1624 = v1577->cache_vals;
      v1624[0] = v1607;
      int v1626 = v1577->timer;
      int v1675 = v1626 + 100;
      v1577->timer = v1675;
      v1629 = v1607;
    }
    v1631 = v1629;
  }
  int * v1632 = v1577->regs;
  v1632[7] = v1631;
  struct StateT * v1634 = slot_47(v1577);
  return v1634;
}

struct StateT * slot_20(struct StateT * v691) {
  int v692 = v691->timer;
  int v700 = v692 + 1;
  v691->timer = v700;
  int * v694 = v691->regs;
  int v695 = v694[6];
  int * v696 = v691->regs;
  int v704 = v695 << 2;
  v696[6] = v704;
  struct StateT * v698 = slot_21(v691);
  return v698;
}

struct StateT * slot_61(struct StateT * v2099) {
  int v2100 = v2099->timer;
  int v2158 = v2100 + 1;
  v2099->timer = v2158;
  int * v2102 = v2099->regs;
  int v2103 = v2102[6];
  int * v2104 = v2099->cache_keys;
  int v2105 = v2104[0];
  bool v2163 = v2105 == ((int)((unsigned int)v2103 >> 2));
  int v2153;
  if (v2163) {
    int * v2106 = v2099->cache_vals;
    int v2107 = v2106[0];
    v2153 = v2107;
  } else {
    int * v2109 = v2099->cache_keys;
    int v2110 = v2109[1];
    bool v2168 = v2110 == ((int)((unsigned int)v2103 >> 2));
    int v2151;
    if (v2168) {
      int * v2111 = v2099->cache_vals;
      int v2112 = v2111[1];
      int * v2113 = v2099->cache_keys;
      int * v2114 = v2099->cache_keys;
      int v2115 = v2114[0];
      v2113[1] = v2115;
      int * v2117 = v2099->cache_vals;
      int * v2118 = v2099->cache_vals;
      int v2119 = v2118[0];
      v2117[1] = v2119;
      int * v2121 = v2099->cache_keys;
      int v2177 = (int)((unsigned int)v2103 >> 2);
      v2121[0] = v2177;
      int * v2123 = v2099->cache_vals;
      v2123[0] = v2112;
      int v2125 = v2099->timer;
      int v2180 = v2125 + 1;
      v2099->timer = v2180;
      v2151 = v2112;
    } else {
      int * v2128 = v2099->mem;
      int v2182 = (int)((unsigned int)v2103 >> 2);
      int v2129 = v2128[v2182];
      int * v2130 = v2099->mem;
      int * v2131 = v2099->cache_keys;
      int v2132 = v2131[1];
      int * v2133 = v2099->cache_vals;
      int v2134 = v2133[1];
      v2130[v2132] = v2134;
      int * v2136 = v2099->cache_keys;
      int * v2137 = v2099->cache_keys;
      int v2138 = v2137[0];
      v2136[1] = v2138;
      int * v2140 = v2099->cache_vals;
      int * v2141 = v2099->cache_vals;
      int v2142 = v2141[0];
      v2140[1] = v2142;
      int * v2144 = v2099->cache_keys;
      v2144[0] = v2182;
      int * v2146 = v2099->cache_vals;
      v2146[0] = v2129;
      int v2148 = v2099->timer;
      int v2197 = v2148 + 100;
      v2099->timer = v2197;
      v2151 = v2129;
    }
    v2153 = v2151;
  }
  int * v2154 = v2099->regs;
  v2154[7] = v2153;
  struct StateT * v2156 = slot_62(v2099);
  return v2156;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v1403) {
  int v1404 = v1403->timer;
  int v1462 = v1404 + 1;
  v1403->timer = v1462;
  int * v1406 = v1403->regs;
  int v1407 = v1406[6];
  int * v1408 = v1403->cache_keys;
  int v1409 = v1408[0];
  bool v1467 = v1409 == ((int)((unsigned int)v1407 >> 2));
  int v1457;
  if (v1467) {
    int * v1410 = v1403->cache_vals;
    int v1411 = v1410[0];
    v1457 = v1411;
  } else {
    int * v1413 = v1403->cache_keys;
    int v1414 = v1413[1];
    bool v1472 = v1414 == ((int)((unsigned int)v1407 >> 2));
    int v1455;
    if (v1472) {
      int * v1415 = v1403->cache_vals;
      int v1416 = v1415[1];
      int * v1417 = v1403->cache_keys;
      int * v1418 = v1403->cache_keys;
      int v1419 = v1418[0];
      v1417[1] = v1419;
      int * v1421 = v1403->cache_vals;
      int * v1422 = v1403->cache_vals;
      int v1423 = v1422[0];
      v1421[1] = v1423;
      int * v1425 = v1403->cache_keys;
      int v1481 = (int)((unsigned int)v1407 >> 2);
      v1425[0] = v1481;
      int * v1427 = v1403->cache_vals;
      v1427[0] = v1416;
      int v1429 = v1403->timer;
      int v1484 = v1429 + 1;
      v1403->timer = v1484;
      v1455 = v1416;
    } else {
      int * v1432 = v1403->mem;
      int v1486 = (int)((unsigned int)v1407 >> 2);
      int v1433 = v1432[v1486];
      int * v1434 = v1403->mem;
      int * v1435 = v1403->cache_keys;
      int v1436 = v1435[1];
      int * v1437 = v1403->cache_vals;
      int v1438 = v1437[1];
      v1434[v1436] = v1438;
      int * v1440 = v1403->cache_keys;
      int * v1441 = v1403->cache_keys;
      int v1442 = v1441[0];
      v1440[1] = v1442;
      int * v1444 = v1403->cache_vals;
      int * v1445 = v1403->cache_vals;
      int v1446 = v1445[0];
      v1444[1] = v1446;
      int * v1448 = v1403->cache_keys;
      v1448[0] = v1486;
      int * v1450 = v1403->cache_vals;
      v1450[0] = v1433;
      int v1452 = v1403->timer;
      int v1501 = v1452 + 100;
      v1403->timer = v1501;
      v1455 = v1433;
    }
    v1457 = v1455;
  }
  int * v1458 = v1403->regs;
  v1458[7] = v1457;
  struct StateT * v1460 = slot_42(v1403);
  return v1460;
}

struct StateT * slot_39(struct StateT * v1371) {
  int v1372 = v1371->timer;
  int v1380 = v1372 + 1;
  v1371->timer = v1380;
  int * v1374 = v1371->regs;
  int v1375 = v1374[6];
  int * v1376 = v1371->regs;
  int v1384 = v1375 & 31;
  v1376[6] = v1384;
  struct StateT * v1378 = slot_40(v1371);
  return v1378;
}

struct StateT * slot_8(struct StateT * v310) {
  int v311 = v310->timer;
  int v319 = v311 + 1;
  v310->timer = v319;
  int * v313 = v310->regs;
  int v314 = v313[10];
  int * v315 = v310->regs;
  int v324 = (int)((unsigned int)v314 >> 5);
  v315[6] = v324;
  struct StateT * v317 = slot_9(v310);
  return v317;
}

struct StateT * slot_30(struct StateT * v1039) {
  int v1040 = v1039->timer;
  int v1048 = v1040 + 1;
  v1039->timer = v1048;
  int * v1042 = v1039->regs;
  int v1043 = v1042[6];
  int * v1044 = v1039->regs;
  int v1052 = v1043 << 2;
  v1044[6] = v1052;
  struct StateT * v1046 = slot_31(v1039);
  return v1046;
}

struct StateT * slot_60(struct StateT * v2083) {
  int v2084 = v2083->timer;
  int v2092 = v2084 + 1;
  v2083->timer = v2092;
  int * v2086 = v2083->regs;
  int v2087 = v2086[6];
  int * v2088 = v2083->regs;
  int v2096 = v2087 << 2;
  v2088[6] = v2096;
  struct StateT * v2090 = slot_61(v2083);
  return v2090;
}

struct StateT * slot_4(struct StateT * v153) {
  int v154 = v153->timer;
  int v162 = v154 + 1;
  v153->timer = v162;
  int * v156 = v153->regs;
  int v157 = v156[6];
  int * v158 = v153->regs;
  int v166 = v157 & 31;
  v158[6] = v166;
  struct StateT * v160 = slot_5(v153);
  return v160;
}

struct StateT * slot_18(struct StateT * v658) {
  int v659 = v658->timer;
  int v667 = v659 + 1;
  v658->timer = v667;
  int * v661 = v658->regs;
  int v662 = v661[10];
  int * v663 = v658->regs;
  int v672 = (int)((unsigned int)v662 >> 15);
  v663[6] = v672;
  struct StateT * v665 = slot_19(v658);
  return v665;
}

struct StateT * slot_9(struct StateT * v327) {
  int v328 = v327->timer;
  int v336 = v328 + 1;
  v327->timer = v336;
  int * v330 = v327->regs;
  int v331 = v330[6];
  int * v332 = v327->regs;
  int v340 = v331 & 31;
  v332[6] = v340;
  struct StateT * v334 = slot_10(v327);
  return v334;
}

struct StateT * slot_11(struct StateT * v359) {
  int v360 = v359->timer;
  int v418 = v360 + 1;
  v359->timer = v418;
  int * v362 = v359->regs;
  int v363 = v362[6];
  int * v364 = v359->cache_keys;
  int v365 = v364[0];
  bool v423 = v365 == ((int)((unsigned int)v363 >> 2));
  int v413;
  if (v423) {
    int * v366 = v359->cache_vals;
    int v367 = v366[0];
    v413 = v367;
  } else {
    int * v369 = v359->cache_keys;
    int v370 = v369[1];
    bool v428 = v370 == ((int)((unsigned int)v363 >> 2));
    int v411;
    if (v428) {
      int * v371 = v359->cache_vals;
      int v372 = v371[1];
      int * v373 = v359->cache_keys;
      int * v374 = v359->cache_keys;
      int v375 = v374[0];
      v373[1] = v375;
      int * v377 = v359->cache_vals;
      int * v378 = v359->cache_vals;
      int v379 = v378[0];
      v377[1] = v379;
      int * v381 = v359->cache_keys;
      int v437 = (int)((unsigned int)v363 >> 2);
      v381[0] = v437;
      int * v383 = v359->cache_vals;
      v383[0] = v372;
      int v385 = v359->timer;
      int v440 = v385 + 1;
      v359->timer = v440;
      v411 = v372;
    } else {
      int * v388 = v359->mem;
      int v442 = (int)((unsigned int)v363 >> 2);
      int v389 = v388[v442];
      int * v390 = v359->mem;
      int * v391 = v359->cache_keys;
      int v392 = v391[1];
      int * v393 = v359->cache_vals;
      int v394 = v393[1];
      v390[v392] = v394;
      int * v396 = v359->cache_keys;
      int * v397 = v359->cache_keys;
      int v398 = v397[0];
      v396[1] = v398;
      int * v400 = v359->cache_vals;
      int * v401 = v359->cache_vals;
      int v402 = v401[0];
      v400[1] = v402;
      int * v404 = v359->cache_keys;
      v404[0] = v442;
      int * v406 = v359->cache_vals;
      v406[0] = v389;
      int v408 = v359->timer;
      int v457 = v408 + 100;
      v359->timer = v457;
      v411 = v389;
    }
    v413 = v411;
  }
  int * v414 = v359->regs;
  v414[7] = v413;
  struct StateT * v416 = slot_12(v359);
  return v416;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  int i11 = bounded(0, 1073741823);
  s1.regs[11] = i11;
  s2.regs[11] = i11;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}