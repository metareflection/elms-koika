// verify: leak (CBMC should report VERIFICATION FAILED)

#define NUM_REGS 32
#define MEM_SIZE 30
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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_34(struct StateT * v930);
struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_29(struct StateT * v833);
struct StateT * slot_16(struct StateT * v470);
struct StateT * slot_23(struct StateT * v669);
struct StateT * slot_5(struct StateT * v76);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v112);
struct StateT * slot_31(struct StateT * v904);
struct StateT * slot_3(struct StateT * v40);
struct StateT * slot_26(struct StateT * v779);
struct StateT * slot_10(struct StateT * v388);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_19(struct StateT * v539);
struct StateT * slot_13(struct StateT * v401);
struct StateT * slot_24(struct StateT * v674);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v424);
struct StateT * slot_28(struct StateT * v810);
struct StateT * slot_32(struct StateT * v917);
struct StateT * slot_17(struct StateT * v518);
struct StateT * slot_20(struct StateT * v544);
struct StateT * slot_33(struct StateT * v925);
struct StateT * slot_36(struct StateT * v1042);
struct StateT * slot_37(struct StateT * v1154);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v224);
struct StateT * slot_27(struct StateT * v787);
struct StateT * slot_30(struct StateT * v856);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_15(struct StateT * v447);
struct StateT * slot_18(struct StateT * v531);
struct StateT * slot_9(struct StateT * v336);
struct StateT * slot_22(struct StateT * v564);
struct StateT * slot_11(struct StateT * v393);
struct StateT * slot_34(struct StateT * v930) {
  int * v931 = v930->saved_regs;
  int * v932 = v930->regs;
  int v933 = v932[14];
  v931[14] = v933;
  int v935 = v930->timer;
  int v997 = v935 + 1;
  v930->timer = v997;
  int * v937 = v930->regs;
  int v938 = v937[12];
  int * v939 = v930->cache_keys;
  int v940 = v939[0];
  bool v1002 = v940 == ((int)((unsigned int)v938 >> 2));
  int v988;
  if (v1002) {
    int * v941 = v930->cache_vals;
    int v942 = v941[0];
    v988 = v942;
  } else {
    int * v944 = v930->cache_keys;
    int v945 = v944[1];
    bool v1007 = v945 == ((int)((unsigned int)v938 >> 2));
    int v986;
    if (v1007) {
      int * v946 = v930->cache_vals;
      int v947 = v946[1];
      int * v948 = v930->cache_keys;
      int * v949 = v930->cache_keys;
      int v950 = v949[0];
      v948[1] = v950;
      int * v952 = v930->cache_vals;
      int * v953 = v930->cache_vals;
      int v954 = v953[0];
      v952[1] = v954;
      int * v956 = v930->cache_keys;
      int v1016 = (int)((unsigned int)v938 >> 2);
      v956[0] = v1016;
      int * v958 = v930->cache_vals;
      v958[0] = v947;
      int v960 = v930->timer;
      int v1019 = v960 + 1;
      v930->timer = v1019;
      v986 = v947;
    } else {
      int * v963 = v930->mem;
      int v1021 = (int)((unsigned int)v938 >> 2);
      int v964 = v963[v1021];
      int * v965 = v930->mem;
      int * v966 = v930->cache_keys;
      int v967 = v966[1];
      int * v968 = v930->cache_vals;
      int v969 = v968[1];
      v965[v967] = v969;
      int * v971 = v930->cache_keys;
      int * v972 = v930->cache_keys;
      int v973 = v972[0];
      v971[1] = v973;
      int * v975 = v930->cache_vals;
      int * v976 = v930->cache_vals;
      int v977 = v976[0];
      v975[1] = v977;
      int * v979 = v930->cache_keys;
      v979[0] = v1021;
      int * v981 = v930->cache_vals;
      v981[0] = v964;
      int v983 = v930->timer;
      int v1036 = v983 + 100;
      v930->timer = v1036;
      v986 = v964;
    }
    v988 = v986;
  }
  int * v989 = v930->regs;
  v989[14] = v988;
  struct StateT * v991 = slot_36(v930);
  return v991;
}

struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v105 = v97 + 1;
  v96->timer = v105;
  int * v99 = v96->regs;
  int v100 = v99[13];
  int * v101 = v96->regs;
  v101[13] = v100;
  struct StateT * v103 = slot_7(v96);
  return v103;
}

struct StateT * slot_29(struct StateT * v833) {
  int * v834 = v833->saved_regs;
  int * v835 = v833->regs;
  int v836 = v835[13];
  v834[13] = v836;
  int v838 = v833->timer;
  int v850 = v838 + 1;
  v833->timer = v850;
  int * v840 = v833->regs;
  int v841 = v840[13];
  int * v842 = v833->regs;
  int v853 = v841 + 4;
  v842[13] = v853;
  struct StateT * v844 = slot_30(v833);
  return v844;
}

struct StateT * slot_16(struct StateT * v470) {
  int * v471 = v470->regs;
  int v472 = v471[14];
  int * v473 = v470->regs;
  int v474 = v473[15];
  bool v499 = !(v472 == v474);
  struct StateT * v493;
  if (v499) {
    int v475 = v470->timer;
    int v500 = v475 + 15;
    v470->timer = v500;
    int * v477 = v470->saved_regs;
    int v478 = v477[11];
    int * v479 = v470->regs;
    v479[11] = v478;
    int * v481 = v470->saved_regs;
    int v482 = v481[12];
    int * v483 = v470->regs;
    v483[12] = v482;
    int * v485 = v470->saved_regs;
    int v486 = v485[13];
    int * v487 = v470->regs;
    v487[13] = v486;
    struct StateT * v489 = slot_17(v470);
    v493 = v489;
  } else {
    struct StateT * v491 = slot_18(v470);
    v493 = v491;
  }
  return v493;
}

struct StateT * slot_23(struct StateT * v669) {
  int v670 = v669->timer;
  int v673 = v670 + 1;
  v669->timer = v673;
  return v669;
}

struct StateT * slot_5(struct StateT * v76) {
  int * v77 = v76->saved_regs;
  int * v78 = v76->regs;
  int v79 = v78[13];
  v77[13] = v79;
  int v81 = v76->timer;
  int v91 = v81 + 1;
  v76->timer = v91;
  int * v83 = v76->regs;
  v83[13] = 0;
  struct StateT * v85 = slot_6(v76);
  return v85;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v37 = v33 + 1;
  v32->timer = v37;
  struct StateT * v35 = slot_3(v32);
  return v35;
}

struct StateT * slot_7(struct StateT * v112) {
  int * v113 = v112->saved_regs;
  int * v114 = v112->regs;
  int v115 = v114[14];
  v113[14] = v115;
  int v117 = v112->timer;
  int v179 = v117 + 1;
  v112->timer = v179;
  int * v119 = v112->regs;
  int v120 = v119[12];
  int * v121 = v112->cache_keys;
  int v122 = v121[0];
  bool v184 = v122 == ((int)((unsigned int)v120 >> 2));
  int v170;
  if (v184) {
    int * v123 = v112->cache_vals;
    int v124 = v123[0];
    v170 = v124;
  } else {
    int * v126 = v112->cache_keys;
    int v127 = v126[1];
    bool v189 = v127 == ((int)((unsigned int)v120 >> 2));
    int v168;
    if (v189) {
      int * v128 = v112->cache_vals;
      int v129 = v128[1];
      int * v130 = v112->cache_keys;
      int * v131 = v112->cache_keys;
      int v132 = v131[0];
      v130[1] = v132;
      int * v134 = v112->cache_vals;
      int * v135 = v112->cache_vals;
      int v136 = v135[0];
      v134[1] = v136;
      int * v138 = v112->cache_keys;
      int v198 = (int)((unsigned int)v120 >> 2);
      v138[0] = v198;
      int * v140 = v112->cache_vals;
      v140[0] = v129;
      int v142 = v112->timer;
      int v201 = v142 + 1;
      v112->timer = v201;
      v168 = v129;
    } else {
      int * v145 = v112->mem;
      int v203 = (int)((unsigned int)v120 >> 2);
      int v146 = v145[v203];
      int * v147 = v112->mem;
      int * v148 = v112->cache_keys;
      int v149 = v148[1];
      int * v150 = v112->cache_vals;
      int v151 = v150[1];
      v147[v149] = v151;
      int * v153 = v112->cache_keys;
      int * v154 = v112->cache_keys;
      int v155 = v154[0];
      v153[1] = v155;
      int * v157 = v112->cache_vals;
      int * v158 = v112->cache_vals;
      int v159 = v158[0];
      v157[1] = v159;
      int * v161 = v112->cache_keys;
      v161[0] = v203;
      int * v163 = v112->cache_vals;
      v163[0] = v146;
      int v165 = v112->timer;
      int v218 = v165 + 100;
      v112->timer = v218;
      v168 = v146;
    }
    v170 = v168;
  }
  int * v171 = v112->regs;
  v171[14] = v170;
  struct StateT * v173 = slot_8(v112);
  return v173;
}

struct StateT * slot_31(struct StateT * v904) {
  int v905 = v904->timer;
  int v911 = v905 + 1;
  v904->timer = v911;
  int * v907 = v904->regs;
  v907[10] = 0;
  struct StateT * v909 = slot_33(v904);
  return v909;
}

struct StateT * slot_3(struct StateT * v40) {
  int * v41 = v40->saved_regs;
  int * v42 = v40->regs;
  int v43 = v42[12];
  v41[12] = v43;
  int v45 = v40->timer;
  int v55 = v45 + 1;
  v40->timer = v55;
  int * v47 = v40->regs;
  v47[12] = 0;
  struct StateT * v49 = slot_4(v40);
  return v49;
}

struct StateT * slot_26(struct StateT * v779) {
  int v780 = v779->timer;
  int v784 = v780 + 1;
  v779->timer = v784;
  struct StateT * v782 = slot_27(v779);
  return v782;
}

struct StateT * slot_10(struct StateT * v388) {
  int v389 = v388->timer;
  int v392 = v389 + 1;
  v388->timer = v392;
  return v388;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[10] = 1;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_19(struct StateT * v539) {
  int v540 = v539->timer;
  int v543 = v540 + 1;
  v539->timer = v543;
  return v539;
}

struct StateT * slot_13(struct StateT * v401) {
  int * v402 = v401->saved_regs;
  int * v403 = v401->regs;
  int v404 = v403[11];
  v402[11] = v404;
  int v406 = v401->timer;
  int v418 = v406 + 1;
  v401->timer = v418;
  int * v408 = v401->regs;
  int v409 = v408[11];
  int * v410 = v401->regs;
  int v421 = v409 + -1;
  v410[11] = v421;
  struct StateT * v412 = slot_14(v401);
  return v412;
}

struct StateT * slot_24(struct StateT * v674) {
  int v675 = v674->timer;
  int v733 = v675 + 1;
  v674->timer = v733;
  int * v677 = v674->regs;
  int v678 = v677[13];
  int * v679 = v674->cache_keys;
  int v680 = v679[0];
  bool v738 = v680 == ((int)((unsigned int)v678 >> 2));
  int v728;
  if (v738) {
    int * v681 = v674->cache_vals;
    int v682 = v681[0];
    v728 = v682;
  } else {
    int * v684 = v674->cache_keys;
    int v685 = v684[1];
    bool v743 = v685 == ((int)((unsigned int)v678 >> 2));
    int v726;
    if (v743) {
      int * v686 = v674->cache_vals;
      int v687 = v686[1];
      int * v688 = v674->cache_keys;
      int * v689 = v674->cache_keys;
      int v690 = v689[0];
      v688[1] = v690;
      int * v692 = v674->cache_vals;
      int * v693 = v674->cache_vals;
      int v694 = v693[0];
      v692[1] = v694;
      int * v696 = v674->cache_keys;
      int v752 = (int)((unsigned int)v678 >> 2);
      v696[0] = v752;
      int * v698 = v674->cache_vals;
      v698[0] = v687;
      int v700 = v674->timer;
      int v755 = v700 + 1;
      v674->timer = v755;
      v726 = v687;
    } else {
      int * v703 = v674->mem;
      int v757 = (int)((unsigned int)v678 >> 2);
      int v704 = v703[v757];
      int * v705 = v674->mem;
      int * v706 = v674->cache_keys;
      int v707 = v706[1];
      int * v708 = v674->cache_vals;
      int v709 = v708[1];
      v705[v707] = v709;
      int * v711 = v674->cache_keys;
      int * v712 = v674->cache_keys;
      int v713 = v712[0];
      v711[1] = v713;
      int * v715 = v674->cache_vals;
      int * v716 = v674->cache_vals;
      int v717 = v716[0];
      v715[1] = v717;
      int * v719 = v674->cache_keys;
      v719[0] = v757;
      int * v721 = v674->cache_vals;
      v721[0] = v704;
      int v723 = v674->timer;
      int v772 = v723 + 100;
      v674->timer = v772;
      v726 = v704;
    }
    v728 = v726;
  }
  int * v729 = v674->regs;
  v729[15] = v728;
  struct StateT * v731 = slot_26(v674);
  return v731;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v424) {
  int * v425 = v424->saved_regs;
  int * v426 = v424->regs;
  int v427 = v426[12];
  v425[12] = v427;
  int v429 = v424->timer;
  int v441 = v429 + 1;
  v424->timer = v441;
  int * v431 = v424->regs;
  int v432 = v431[12];
  int * v433 = v424->regs;
  int v444 = v432 + 4;
  v433[12] = v444;
  struct StateT * v435 = slot_15(v424);
  return v435;
}

struct StateT * slot_28(struct StateT * v810) {
  int * v811 = v810->saved_regs;
  int * v812 = v810->regs;
  int v813 = v812[12];
  v811[12] = v813;
  int v815 = v810->timer;
  int v827 = v815 + 1;
  v810->timer = v827;
  int * v817 = v810->regs;
  int v818 = v817[12];
  int * v819 = v810->regs;
  int v830 = v818 + 4;
  v819[12] = v830;
  struct StateT * v821 = slot_29(v810);
  return v821;
}

struct StateT * slot_32(struct StateT * v917) {
  int v918 = v917->timer;
  int v922 = v918 + 1;
  v917->timer = v922;
  struct StateT * v920 = slot_34(v917);
  return v920;
}

struct StateT * slot_17(struct StateT * v518) {
  int v519 = v518->timer;
  int v525 = v519 + 1;
  v518->timer = v525;
  int * v521 = v518->regs;
  v521[10] = 0;
  struct StateT * v523 = slot_19(v518);
  return v523;
}

struct StateT * slot_20(struct StateT * v544) {
  int * v545 = v544->regs;
  int v546 = v545[11];
  bool v557 = !(v546 == 0);
  struct StateT * v553;
  if (v557) {
    int v547 = v544->timer;
    int v558 = v547 + 15;
    v544->timer = v558;
    struct StateT * v549 = slot_22(v544);
    v553 = v549;
  } else {
    struct StateT * v551 = slot_23(v544);
    v553 = v551;
  }
  return v553;
}

struct StateT * slot_33(struct StateT * v925) {
  int v926 = v925->timer;
  int v929 = v926 + 1;
  v925->timer = v929;
  return v925;
}

struct StateT * slot_36(struct StateT * v1042) {
  int * v1043 = v1042->saved_regs;
  int * v1044 = v1042->regs;
  int v1045 = v1044[15];
  v1043[15] = v1045;
  int v1047 = v1042->timer;
  int v1109 = v1047 + 1;
  v1042->timer = v1109;
  int * v1049 = v1042->regs;
  int v1050 = v1049[13];
  int * v1051 = v1042->cache_keys;
  int v1052 = v1051[0];
  bool v1114 = v1052 == ((int)((unsigned int)v1050 >> 2));
  int v1100;
  if (v1114) {
    int * v1053 = v1042->cache_vals;
    int v1054 = v1053[0];
    v1100 = v1054;
  } else {
    int * v1056 = v1042->cache_keys;
    int v1057 = v1056[1];
    bool v1119 = v1057 == ((int)((unsigned int)v1050 >> 2));
    int v1098;
    if (v1119) {
      int * v1058 = v1042->cache_vals;
      int v1059 = v1058[1];
      int * v1060 = v1042->cache_keys;
      int * v1061 = v1042->cache_keys;
      int v1062 = v1061[0];
      v1060[1] = v1062;
      int * v1064 = v1042->cache_vals;
      int * v1065 = v1042->cache_vals;
      int v1066 = v1065[0];
      v1064[1] = v1066;
      int * v1068 = v1042->cache_keys;
      int v1128 = (int)((unsigned int)v1050 >> 2);
      v1068[0] = v1128;
      int * v1070 = v1042->cache_vals;
      v1070[0] = v1059;
      int v1072 = v1042->timer;
      int v1131 = v1072 + 1;
      v1042->timer = v1131;
      v1098 = v1059;
    } else {
      int * v1075 = v1042->mem;
      int v1133 = (int)((unsigned int)v1050 >> 2);
      int v1076 = v1075[v1133];
      int * v1077 = v1042->mem;
      int * v1078 = v1042->cache_keys;
      int v1079 = v1078[1];
      int * v1080 = v1042->cache_vals;
      int v1081 = v1080[1];
      v1077[v1079] = v1081;
      int * v1083 = v1042->cache_keys;
      int * v1084 = v1042->cache_keys;
      int v1085 = v1084[0];
      v1083[1] = v1085;
      int * v1087 = v1042->cache_vals;
      int * v1088 = v1042->cache_vals;
      int v1089 = v1088[0];
      v1087[1] = v1089;
      int * v1091 = v1042->cache_keys;
      v1091[0] = v1133;
      int * v1093 = v1042->cache_vals;
      v1093[0] = v1076;
      int v1095 = v1042->timer;
      int v1148 = v1095 + 100;
      v1042->timer = v1148;
      v1098 = v1076;
    }
    v1100 = v1098;
  }
  int * v1101 = v1042->regs;
  v1101[15] = v1100;
  struct StateT * v1103 = slot_37(v1042);
  return v1103;
}

struct StateT * slot_37(struct StateT * v1154) {
  int * v1155 = v1154->regs;
  int v1156 = v1155[11];
  bool v1175 = !(v1156 == 0);
  struct StateT * v1171;
  if (v1175) {
    struct StateT * v1157 = slot_26(v1154);
    v1171 = v1157;
  } else {
    int v1159 = v1154->timer;
    int v1178 = v1159 + 15;
    v1154->timer = v1178;
    int * v1161 = v1154->saved_regs;
    int v1162 = v1161[14];
    int * v1163 = v1154->regs;
    v1163[14] = v1162;
    int * v1165 = v1154->saved_regs;
    int v1166 = v1165[15];
    int * v1167 = v1154->regs;
    v1167[15] = v1166;
    struct StateT * v1169 = slot_23(v1154);
    v1171 = v1169;
  }
  return v1171;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v224) {
  int * v225 = v224->saved_regs;
  int * v226 = v224->regs;
  int v227 = v226[15];
  v225[15] = v227;
  int v229 = v224->timer;
  int v291 = v229 + 1;
  v224->timer = v291;
  int * v231 = v224->regs;
  int v232 = v231[13];
  int * v233 = v224->cache_keys;
  int v234 = v233[0];
  bool v296 = v234 == ((int)((unsigned int)v232 >> 2));
  int v282;
  if (v296) {
    int * v235 = v224->cache_vals;
    int v236 = v235[0];
    v282 = v236;
  } else {
    int * v238 = v224->cache_keys;
    int v239 = v238[1];
    bool v301 = v239 == ((int)((unsigned int)v232 >> 2));
    int v280;
    if (v301) {
      int * v240 = v224->cache_vals;
      int v241 = v240[1];
      int * v242 = v224->cache_keys;
      int * v243 = v224->cache_keys;
      int v244 = v243[0];
      v242[1] = v244;
      int * v246 = v224->cache_vals;
      int * v247 = v224->cache_vals;
      int v248 = v247[0];
      v246[1] = v248;
      int * v250 = v224->cache_keys;
      int v310 = (int)((unsigned int)v232 >> 2);
      v250[0] = v310;
      int * v252 = v224->cache_vals;
      v252[0] = v241;
      int v254 = v224->timer;
      int v313 = v254 + 1;
      v224->timer = v313;
      v280 = v241;
    } else {
      int * v257 = v224->mem;
      int v315 = (int)((unsigned int)v232 >> 2);
      int v258 = v257[v315];
      int * v259 = v224->mem;
      int * v260 = v224->cache_keys;
      int v261 = v260[1];
      int * v262 = v224->cache_vals;
      int v263 = v262[1];
      v259[v261] = v263;
      int * v265 = v224->cache_keys;
      int * v266 = v224->cache_keys;
      int v267 = v266[0];
      v265[1] = v267;
      int * v269 = v224->cache_vals;
      int * v270 = v224->cache_vals;
      int v271 = v270[0];
      v269[1] = v271;
      int * v273 = v224->cache_keys;
      v273[0] = v315;
      int * v275 = v224->cache_vals;
      v275[0] = v258;
      int v277 = v224->timer;
      int v330 = v277 + 100;
      v224->timer = v330;
      v280 = v258;
    }
    v282 = v280;
  }
  int * v283 = v224->regs;
  v283[15] = v282;
  struct StateT * v285 = slot_9(v224);
  return v285;
}

struct StateT * slot_27(struct StateT * v787) {
  int * v788 = v787->saved_regs;
  int * v789 = v787->regs;
  int v790 = v789[11];
  v788[11] = v790;
  int v792 = v787->timer;
  int v804 = v792 + 1;
  v787->timer = v804;
  int * v794 = v787->regs;
  int v795 = v794[11];
  int * v796 = v787->regs;
  int v807 = v795 + -1;
  v796[11] = v807;
  struct StateT * v798 = slot_28(v787);
  return v798;
}

struct StateT * slot_30(struct StateT * v856) {
  int * v857 = v856->regs;
  int v858 = v857[14];
  int * v859 = v856->regs;
  int v860 = v859[15];
  bool v885 = !(v858 == v860);
  struct StateT * v879;
  if (v885) {
    int v861 = v856->timer;
    int v886 = v861 + 15;
    v856->timer = v886;
    int * v863 = v856->saved_regs;
    int v864 = v863[11];
    int * v865 = v856->regs;
    v865[11] = v864;
    int * v867 = v856->saved_regs;
    int v868 = v867[12];
    int * v869 = v856->regs;
    v869[12] = v868;
    int * v871 = v856->saved_regs;
    int v872 = v871[13];
    int * v873 = v856->regs;
    v873[13] = v872;
    struct StateT * v875 = slot_31(v856);
    v879 = v875;
  } else {
    struct StateT * v877 = slot_32(v856);
    v879 = v877;
  }
  return v879;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v69 = v61 + 1;
  v60->timer = v69;
  int * v63 = v60->regs;
  int v64 = v63[12];
  int * v65 = v60->regs;
  int v73 = v64 + 16;
  v65[12] = v73;
  struct StateT * v67 = slot_5(v60);
  return v67;
}

struct StateT * slot_15(struct StateT * v447) {
  int * v448 = v447->saved_regs;
  int * v449 = v447->regs;
  int v450 = v449[13];
  v448[13] = v450;
  int v452 = v447->timer;
  int v464 = v452 + 1;
  v447->timer = v464;
  int * v454 = v447->regs;
  int v455 = v454[13];
  int * v456 = v447->regs;
  int v467 = v455 + 4;
  v456[13] = v467;
  struct StateT * v458 = slot_16(v447);
  return v458;
}

struct StateT * slot_18(struct StateT * v531) {
  int v532 = v531->timer;
  int v536 = v532 + 1;
  v531->timer = v536;
  struct StateT * v534 = slot_20(v531);
  return v534;
}

struct StateT * slot_9(struct StateT * v336) {
  int * v337 = v336->regs;
  int v338 = v337[11];
  bool v365 = 0 >= v338;
  struct StateT * v361;
  if (v365) {
    int v339 = v336->timer;
    int v366 = v339 + 15;
    v336->timer = v366;
    int * v341 = v336->saved_regs;
    int v342 = v341[12];
    int * v343 = v336->regs;
    v343[12] = v342;
    int * v345 = v336->saved_regs;
    int v346 = v345[13];
    int * v347 = v336->regs;
    v347[13] = v346;
    int * v349 = v336->saved_regs;
    int v350 = v349[14];
    int * v351 = v336->regs;
    v351[14] = v350;
    int * v353 = v336->saved_regs;
    int v354 = v353[15];
    int * v355 = v336->regs;
    v355[15] = v354;
    struct StateT * v357 = slot_10(v336);
    v361 = v357;
  } else {
    struct StateT * v359 = slot_11(v336);
    v361 = v359;
  }
  return v361;
}

struct StateT * slot_22(struct StateT * v564) {
  int v565 = v564->timer;
  int v623 = v565 + 1;
  v564->timer = v623;
  int * v567 = v564->regs;
  int v568 = v567[12];
  int * v569 = v564->cache_keys;
  int v570 = v569[0];
  bool v628 = v570 == ((int)((unsigned int)v568 >> 2));
  int v618;
  if (v628) {
    int * v571 = v564->cache_vals;
    int v572 = v571[0];
    v618 = v572;
  } else {
    int * v574 = v564->cache_keys;
    int v575 = v574[1];
    bool v633 = v575 == ((int)((unsigned int)v568 >> 2));
    int v616;
    if (v633) {
      int * v576 = v564->cache_vals;
      int v577 = v576[1];
      int * v578 = v564->cache_keys;
      int * v579 = v564->cache_keys;
      int v580 = v579[0];
      v578[1] = v580;
      int * v582 = v564->cache_vals;
      int * v583 = v564->cache_vals;
      int v584 = v583[0];
      v582[1] = v584;
      int * v586 = v564->cache_keys;
      int v642 = (int)((unsigned int)v568 >> 2);
      v586[0] = v642;
      int * v588 = v564->cache_vals;
      v588[0] = v577;
      int v590 = v564->timer;
      int v645 = v590 + 1;
      v564->timer = v645;
      v616 = v577;
    } else {
      int * v593 = v564->mem;
      int v647 = (int)((unsigned int)v568 >> 2);
      int v594 = v593[v647];
      int * v595 = v564->mem;
      int * v596 = v564->cache_keys;
      int v597 = v596[1];
      int * v598 = v564->cache_vals;
      int v599 = v598[1];
      v595[v597] = v599;
      int * v601 = v564->cache_keys;
      int * v602 = v564->cache_keys;
      int v603 = v602[0];
      v601[1] = v603;
      int * v605 = v564->cache_vals;
      int * v606 = v564->cache_vals;
      int v607 = v606[0];
      v605[1] = v607;
      int * v609 = v564->cache_keys;
      v609[0] = v647;
      int * v611 = v564->cache_vals;
      v611[0] = v594;
      int v613 = v564->timer;
      int v662 = v613 + 100;
      v564->timer = v662;
      v616 = v594;
    }
    v618 = v616;
  }
  int * v619 = v564->regs;
  v619[14] = v618;
  struct StateT * v621 = slot_24(v564);
  return v621;
}

struct StateT * slot_11(struct StateT * v393) {
  int v394 = v393->timer;
  int v398 = v394 + 1;
  v393->timer = v398;
  struct StateT * v396 = slot_13(v393);
  return v396;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}