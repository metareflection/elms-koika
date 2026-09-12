
#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#define BHT_SIZE 3
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
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
  int bht[BHT_SIZE];
};

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
  for (int i=0; i<BHT_SIZE; i++) {
    s->bht[i] = 0;
  }
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v211(struct StateT * v212);
struct StateT * v531(struct StateT * v532);
struct StateT * v15(struct StateT * v16);
struct StateT * v1108(struct StateT * v1109);
struct StateT * v640(struct StateT * v641);
struct StateT * v190(struct StateT * v191);
struct StateT * v379(struct StateT * v380);
struct StateT * v60(struct StateT * v61);
struct StateT * v1046(struct StateT * v1047);
struct StateT * v30(struct StateT * v31);
struct StateT * v948(struct StateT * v949);
struct StateT * v241(struct StateT * v242);
struct StateT * v9(struct StateT * v10);
struct StateT * v233(struct StateT * v234);
struct StateT * v54(struct StateT * v55);
struct StateT * v958(struct StateT * v959);
struct StateT * v200(struct StateT * v201);
struct StateT * v184(struct StateT * v185);
struct StateT * v21(struct StateT * v22);
struct StateT * v676(struct StateT * v677);
struct StateT * v46(struct StateT * v47);
struct StateT * v664(struct StateT * v665);
struct StateT * v984(struct StateT * v985);
struct StateT * v701(struct StateT * v702);
struct StateT * v652(struct StateT * v653);
struct StateT * v40(struct StateT * v41);
struct StateT * v255(struct StateT * v256);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v68(struct StateT * v69);
struct StateT * v249(struct StateT * v250);
struct StateT * v225(struct StateT * v226);
struct StateT * v317(struct StateT * v318);
struct StateT * v966(struct StateT * v967);
struct StateT * v126(struct StateT * v127);
struct StateT * v976(struct StateT * v977);
struct StateT * v211(struct StateT * v212) {
  int v213 = v212->timer;
  int v216 = v213 + 1;
  v212->timer = v216;return v212;
}

struct StateT * v531(struct StateT * v532) {
  int * v533 = v532->regs;
  int v534 = v533[11];
  int * v535 = v532->bht;
  bool v551 = !(v534 == 0);
  int v538 = (v551 ? 1 : 0);
  v535[2] = v538;
  struct StateT * v547 = (v551 ? ({
    int v540 = v532->timer;
    int v557 = v540 + 15;
    v532->timer = v557;struct StateT * v543 = v68(v532);
    v543;
  }) : ({
    struct StateT * v545 = v30(v532);
    v545;
  }));
  return v547;
}

struct StateT * v15(struct StateT * v16) {
  int v17 = v16->timer;
  int v1317 = v17 + 1;
  v16->timer = v1317;int * v19 = v16->bht;
  int v20 = v19[0];
  bool v1320 = !(v20 == 0);
  struct StateT * v1315 = (v1320 ? ({
    struct StateT * v946 = v21(v16);
    v946;
  }) : ({
    struct StateT * v1313 = v948(v16);
    v1313;
  }));
  return v1315;
}

struct StateT * v1108(struct StateT * v1109) {
  int * v1110 = v1109->regs;
  int v1111 = v1110[11];
  int * v1112 = v1109->bht;
  bool v1143 = 0 >= v1111;
  int v1115 = (v1143 ? 1 : 0);
  v1112[0] = v1115;
  struct StateT * v1139 = (v1143 ? ({
    int v1117 = v1109->timer;
    int v1149 = v1117 + 15;
    v1109->timer = v1149;int * v1119 = v1109->saved_regs;
    int v1120 = v1119[12];
    int * v1121 = v1109->regs;
    v1121[12] = v1120;
    int * v1123 = v1109->saved_regs;
    int v1124 = v1123[13];
    int * v1125 = v1109->regs;
    v1125[13] = v1124;
    int * v1127 = v1109->saved_regs;
    int v1128 = v1127[14];
    int * v1129 = v1109->regs;
    v1129[14] = v1128;
    int * v1131 = v1109->saved_regs;
    int v1132 = v1131[15];
    int * v1133 = v1109->regs;
    v1133[15] = v1132;
    struct StateT * v1135 = v30(v1109);
    v1135;
  }) : ({
    struct StateT * v1137 = v184(v1109);
    v1137;
  }));
  return v1139;
}

struct StateT * v640(struct StateT * v641) {
  int * v642 = v641->saved_regs;
  int * v643 = v641->regs;
  int v644 = v643[11];
  v642[11] = v644;
  int v646 = v641->timer;
  int v779 = v646 + 1;
  v641->timer = v779;int * v648 = v641->regs;
  int v649 = v648[11];
  int * v650 = v641->regs;
  int v782 = v649 + -1;
  v650[11] = v782;
  struct StateT * v773 = v652(v641);
  return v773;
}

struct StateT * v190(struct StateT * v191) {
  int * v192 = v191->saved_regs;
  int * v193 = v191->regs;
  int v194 = v193[10];
  v192[10] = v194;
  int v196 = v191->timer;
  int v633 = v196 + 1;
  v191->timer = v633;int * v198 = v191->regs;
  v198[10] = 0;
  struct StateT * v627 = v200(v191);
  return v627;
}

struct StateT * v379(struct StateT * v380) {
  int * v381 = v380->regs;
  int v382 = v381[11];
  int * v383 = v380->bht;
  bool v407 = !(v382 == 0);
  int v386 = (v407 ? 1 : 0);
  v383[2] = v386;
  struct StateT * v403 = (v407 ? ({
    struct StateT * v389 = v184(v380);
    v389;
  }) : ({
    int v391 = v380->timer;
    int v415 = v391 + 15;
    v380->timer = v415;int * v393 = v380->saved_regs;
    int v394 = v393[14];
    int * v395 = v380->regs;
    v395[14] = v394;
    int * v397 = v380->saved_regs;
    int v398 = v397[15];
    int * v399 = v380->regs;
    v399[15] = v398;
    struct StateT * v401 = v30(v380);
    v401;
  }));
  return v403;
}

struct StateT * v60(struct StateT * v61) {
  int v62 = v61->timer;
  int v896 = v62 + 1;
  v61->timer = v896;int * v64 = v61->regs;
  int v65 = v64[13];
  int * v66 = v61->regs;
  v66[13] = v65;
  struct StateT * v894 = v68(v61);
  return v894;
}

struct StateT * v1046(struct StateT * v1047) {
  int * v1048 = v1047->saved_regs;
  int * v1049 = v1047->regs;
  int v1050 = v1049[15];
  v1048[15] = v1050;
  int v1052 = v1047->timer;
  int v1177 = v1052 + 1;
  v1047->timer = v1177;int * v1054 = v1047->regs;
  int v1055 = v1054[13];
  int * v1056 = v1047->cache_keys;
  int v1057 = v1056[0];
  bool v1182 = v1057 == ((int)((unsigned int)v1055 >> 2));
  int v1105 = (v1182 ? ({
    int * v1058 = v1047->cache_vals;
    int v1059 = v1058[0];
    v1059;
  }) : ({
    int * v1061 = v1047->cache_keys;
    int v1062 = v1061[1];
    bool v1187 = v1062 == ((int)((unsigned int)v1055 >> 2));
    int v1103 = (v1187 ? ({
      int * v1063 = v1047->cache_vals;
      int v1064 = v1063[1];
      int * v1065 = v1047->cache_keys;
      int * v1066 = v1047->cache_keys;
      int v1067 = v1066[0];
      v1065[1] = v1067;
      int * v1069 = v1047->cache_vals;
      int * v1070 = v1047->cache_vals;
      int v1071 = v1070[0];
      v1069[1] = v1071;
      int * v1073 = v1047->cache_keys;
      int v1196 = (int)((unsigned int)v1055 >> 2);
      v1073[0] = v1196;
      int * v1075 = v1047->cache_vals;
      v1075[0] = v1064;
      int v1077 = v1047->timer;
      int v1199 = v1077 + 1;
      v1047->timer = v1199;v1064;
    }) : ({
      int * v1080 = v1047->mem;
      int v1201 = (int)((unsigned int)v1055 >> 2);
      int v1081 = v1080[v1201];
      int * v1082 = v1047->mem;
      int * v1083 = v1047->cache_keys;
      int v1084 = v1083[1];
      int * v1085 = v1047->cache_vals;
      int v1086 = v1085[1];
      v1082[v1084] = v1086;
      int * v1088 = v1047->cache_keys;
      int * v1089 = v1047->cache_keys;
      int v1090 = v1089[0];
      v1088[1] = v1090;
      int * v1092 = v1047->cache_vals;
      int * v1093 = v1047->cache_vals;
      int v1094 = v1093[0];
      v1092[1] = v1094;
      int * v1096 = v1047->cache_keys;
      v1096[0] = v1201;
      int * v1098 = v1047->cache_vals;
      v1098[0] = v1081;
      int v1100 = v1047->timer;
      int v1216 = v1100 + 100;
      v1047->timer = v1216;v1081;
    }));
    v1103;
  }));
  int * v1106 = v1047->regs;
  v1106[15] = v1105;
  struct StateT * v1171 = v1108(v1047);
  return v1171;
}

struct StateT * v30(struct StateT * v31) {
  int v32 = v31->timer;
  int v35 = v32 + 1;
  v31->timer = v35;return v31;
}

struct StateT * v948(struct StateT * v949) {
  int * v950 = v949->saved_regs;
  int * v951 = v949->regs;
  int v952 = v951[12];
  v950[12] = v952;
  int v954 = v949->timer;
  int v1308 = v954 + 1;
  v949->timer = v1308;int * v956 = v949->regs;
  v956[12] = 0;
  struct StateT * v1302 = v958(v949);
  return v1302;
}

struct StateT * v241(struct StateT * v242) {
  int v243 = v242->timer;
  int v578 = v243 + 1;
  v242->timer = v578;int * v245 = v242->regs;
  int v246 = v245[13];
  int * v247 = v242->regs;
  int v582 = v246 + 4;
  v247[13] = v582;
  struct StateT * v576 = v249(v242);
  return v576;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v1328 = v11 + 1;
  v10->timer = v1328;int * v13 = v10->regs;
  v13[10] = 1;
  struct StateT * v1326 = v15(v10);
  return v1326;
}

struct StateT * v233(struct StateT * v234) {
  int v235 = v234->timer;
  int v587 = v235 + 1;
  v234->timer = v587;int * v237 = v234->regs;
  int v238 = v237[12];
  int * v239 = v234->regs;
  int v591 = v238 + 4;
  v239[12] = v591;
  struct StateT * v585 = v241(v234);
  return v585;
}

struct StateT * v54(struct StateT * v55) {
  int v56 = v55->timer;
  int v905 = v56 + 1;
  v55->timer = v905;int * v58 = v55->regs;
  v58[13] = 0;
  struct StateT * v903 = v60(v55);
  return v903;
}

struct StateT * v958(struct StateT * v959) {
  int v960 = v959->timer;
  int v1295 = v960 + 1;
  v959->timer = v1295;int * v962 = v959->regs;
  int v963 = v962[12];
  int * v964 = v959->regs;
  int v1299 = v963 + 16;
  v964[12] = v1299;
  struct StateT * v1293 = v966(v959);
  return v1293;
}

struct StateT * v200(struct StateT * v201) {
  int * v202 = v201->regs;
  int v203 = v202[14];
  int * v204 = v201->regs;
  int v205 = v204[15];
  int * v206 = v201->bht;
  bool v611 = !(v203 == v205);
  int v209 = (v611 ? 1 : 0);
  v206[1] = v209;
  struct StateT * v605 = (v611 ? ({
    struct StateT * v217 = v211(v201);
    v217;
  }) : ({
    int v219 = v201->timer;
    int v619 = v219 + 15;
    v201->timer = v619;int * v221 = v201->saved_regs;
    int v222 = v221[10];
    int * v223 = v201->regs;
    v223[10] = v222;
    struct StateT * v603 = v225(v201);
    v603;
  }));
  return v605;
}

struct StateT * v184(struct StateT * v185) {
  int v186 = v185->timer;
  int v789 = v186 + 1;
  v185->timer = v789;int * v188 = v185->bht;
  int v189 = v188[1];
  bool v792 = !(v189 == 0);
  struct StateT * v787 = (v792 ? ({
    struct StateT * v638 = v190(v185);
    v638;
  }) : ({
    struct StateT * v785 = v640(v185);
    v785;
  }));
  return v787;
}

struct StateT * v21(struct StateT * v22) {
  int * v23 = v22->regs;
  int v24 = v23[11];
  int * v25 = v22->bht;
  bool v934 = 0 >= v24;
  int v28 = (v934 ? 1 : 0);
  v25[0] = v28;
  struct StateT * v930 = (v934 ? ({
    struct StateT * v36 = v30(v22);
    v36;
  }) : ({
    int v38 = v22->timer;
    int v942 = v38 + 15;
    v22->timer = v942;struct StateT * v928 = v40(v22);
    v928;
  }));
  return v930;
}

struct StateT * v676(struct StateT * v677) {
  int * v678 = v677->regs;
  int v679 = v678[14];
  int * v680 = v677->regs;
  int v681 = v680[15];
  int * v682 = v677->bht;
  bool v725 = !(v679 == v681);
  int v685 = (v725 ? 1 : 0);
  v682[1] = v685;
  struct StateT * v719 = (v725 ? ({
    int v687 = v677->timer;
    int v731 = v687 + 15;
    v677->timer = v731;int * v689 = v677->saved_regs;
    int v690 = v689[11];
    int * v691 = v677->regs;
    v691[11] = v690;
    int * v693 = v677->saved_regs;
    int v694 = v693[12];
    int * v695 = v677->regs;
    v695[12] = v694;
    int * v697 = v677->saved_regs;
    int v698 = v697[13];
    int * v699 = v677->regs;
    v699[13] = v698;
    struct StateT * v715 = v701(v677);
    v715;
  }) : ({
    struct StateT * v717 = v249(v677);
    v717;
  }));
  return v719;
}

struct StateT * v46(struct StateT * v47) {
  int v48 = v47->timer;
  int v913 = v48 + 1;
  v47->timer = v913;int * v50 = v47->regs;
  int v51 = v50[12];
  int * v52 = v47->regs;
  int v917 = v51 + 16;
  v52[12] = v917;
  struct StateT * v911 = v54(v47);
  return v911;
}

struct StateT * v664(struct StateT * v665) {
  int * v666 = v665->saved_regs;
  int * v667 = v665->regs;
  int v668 = v667[13];
  v666[13] = v668;
  int v670 = v665->timer;
  int v755 = v670 + 1;
  v665->timer = v755;int * v672 = v665->regs;
  int v673 = v672[13];
  int * v674 = v665->regs;
  int v758 = v673 + 4;
  v674[13] = v758;
  struct StateT * v749 = v676(v665);
  return v749;
}

struct StateT * v984(struct StateT * v985) {
  int * v986 = v985->saved_regs;
  int * v987 = v985->regs;
  int v988 = v987[14];
  v986[14] = v988;
  int v990 = v985->timer;
  int v1228 = v990 + 1;
  v985->timer = v1228;int * v992 = v985->regs;
  int v993 = v992[12];
  int * v994 = v985->cache_keys;
  int v995 = v994[0];
  bool v1233 = v995 == ((int)((unsigned int)v993 >> 2));
  int v1043 = (v1233 ? ({
    int * v996 = v985->cache_vals;
    int v997 = v996[0];
    v997;
  }) : ({
    int * v999 = v985->cache_keys;
    int v1000 = v999[1];
    bool v1238 = v1000 == ((int)((unsigned int)v993 >> 2));
    int v1041 = (v1238 ? ({
      int * v1001 = v985->cache_vals;
      int v1002 = v1001[1];
      int * v1003 = v985->cache_keys;
      int * v1004 = v985->cache_keys;
      int v1005 = v1004[0];
      v1003[1] = v1005;
      int * v1007 = v985->cache_vals;
      int * v1008 = v985->cache_vals;
      int v1009 = v1008[0];
      v1007[1] = v1009;
      int * v1011 = v985->cache_keys;
      int v1247 = (int)((unsigned int)v993 >> 2);
      v1011[0] = v1247;
      int * v1013 = v985->cache_vals;
      v1013[0] = v1002;
      int v1015 = v985->timer;
      int v1250 = v1015 + 1;
      v985->timer = v1250;v1002;
    }) : ({
      int * v1018 = v985->mem;
      int v1252 = (int)((unsigned int)v993 >> 2);
      int v1019 = v1018[v1252];
      int * v1020 = v985->mem;
      int * v1021 = v985->cache_keys;
      int v1022 = v1021[1];
      int * v1023 = v985->cache_vals;
      int v1024 = v1023[1];
      v1020[v1022] = v1024;
      int * v1026 = v985->cache_keys;
      int * v1027 = v985->cache_keys;
      int v1028 = v1027[0];
      v1026[1] = v1028;
      int * v1030 = v985->cache_vals;
      int * v1031 = v985->cache_vals;
      int v1032 = v1031[0];
      v1030[1] = v1032;
      int * v1034 = v985->cache_keys;
      v1034[0] = v1252;
      int * v1036 = v985->cache_vals;
      v1036[0] = v1019;
      int v1038 = v985->timer;
      int v1267 = v1038 + 100;
      v985->timer = v1267;v1019;
    }));
    v1041;
  }));
  int * v1044 = v985->regs;
  v1044[14] = v1043;
  struct StateT * v1222 = v1046(v985);
  return v1222;
}

struct StateT * v701(struct StateT * v702) {
  int v703 = v702->timer;
  int v709 = v703 + 1;
  v702->timer = v709;int * v705 = v702->regs;
  v705[10] = 0;
  struct StateT * v707 = v211(v702);
  return v707;
}

struct StateT * v652(struct StateT * v653) {
  int * v654 = v653->saved_regs;
  int * v655 = v653->regs;
  int v656 = v655[12];
  v654[12] = v656;
  int v658 = v653->timer;
  int v767 = v658 + 1;
  v653->timer = v767;int * v660 = v653->regs;
  int v661 = v660[12];
  int * v662 = v653->regs;
  int v770 = v661 + 4;
  v662[12] = v770;
  struct StateT * v761 = v664(v653);
  return v761;
}

struct StateT * v40(struct StateT * v41) {
  int v42 = v41->timer;
  int v922 = v42 + 1;
  v41->timer = v922;int * v44 = v41->regs;
  v44[12] = 0;
  struct StateT * v920 = v46(v41);
  return v920;
}

struct StateT * v255(struct StateT * v256) {
  int * v257 = v256->saved_regs;
  int * v258 = v256->regs;
  int v259 = v258[14];
  v257[14] = v259;
  int v261 = v256->timer;
  int v484 = v261 + 1;
  v256->timer = v484;int * v263 = v256->regs;
  int v264 = v263[12];
  int * v265 = v256->cache_keys;
  int v266 = v265[0];
  bool v489 = v266 == ((int)((unsigned int)v264 >> 2));
  int v314 = (v489 ? ({
    int * v267 = v256->cache_vals;
    int v268 = v267[0];
    v268;
  }) : ({
    int * v270 = v256->cache_keys;
    int v271 = v270[1];
    bool v494 = v271 == ((int)((unsigned int)v264 >> 2));
    int v312 = (v494 ? ({
      int * v272 = v256->cache_vals;
      int v273 = v272[1];
      int * v274 = v256->cache_keys;
      int * v275 = v256->cache_keys;
      int v276 = v275[0];
      v274[1] = v276;
      int * v278 = v256->cache_vals;
      int * v279 = v256->cache_vals;
      int v280 = v279[0];
      v278[1] = v280;
      int * v282 = v256->cache_keys;
      int v503 = (int)((unsigned int)v264 >> 2);
      v282[0] = v503;
      int * v284 = v256->cache_vals;
      v284[0] = v273;
      int v286 = v256->timer;
      int v506 = v286 + 1;
      v256->timer = v506;v273;
    }) : ({
      int * v289 = v256->mem;
      int v508 = (int)((unsigned int)v264 >> 2);
      int v290 = v289[v508];
      int * v291 = v256->mem;
      int * v292 = v256->cache_keys;
      int v293 = v292[1];
      int * v294 = v256->cache_vals;
      int v295 = v294[1];
      v291[v293] = v295;
      int * v297 = v256->cache_keys;
      int * v298 = v256->cache_keys;
      int v299 = v298[0];
      v297[1] = v299;
      int * v301 = v256->cache_vals;
      int * v302 = v256->cache_vals;
      int v303 = v302[0];
      v301[1] = v303;
      int * v305 = v256->cache_keys;
      v305[0] = v508;
      int * v307 = v256->cache_vals;
      v307[0] = v290;
      int v309 = v256->timer;
      int v523 = v309 + 100;
      v256->timer = v523;v290;
    }));
    v312;
  }));
  int * v315 = v256->regs;
  v315[14] = v314;
  struct StateT * v478 = v317(v256);
  return v478;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1344 = v1(v0);
  return v1344;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v1336 = v3 + 1;
  v2->timer = v1336;int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v1334 = v9(v2);
  return v1334;
}

struct StateT * v68(struct StateT * v69) {
  int v70 = v69->timer;
  int v848 = v70 + 1;
  v69->timer = v848;int * v72 = v69->regs;
  int v73 = v72[12];
  int * v74 = v69->cache_keys;
  int v75 = v74[0];
  bool v853 = v75 == ((int)((unsigned int)v73 >> 2));
  int v123 = (v853 ? ({
    int * v76 = v69->cache_vals;
    int v77 = v76[0];
    v77;
  }) : ({
    int * v79 = v69->cache_keys;
    int v80 = v79[1];
    bool v858 = v80 == ((int)((unsigned int)v73 >> 2));
    int v121 = (v858 ? ({
      int * v81 = v69->cache_vals;
      int v82 = v81[1];
      int * v83 = v69->cache_keys;
      int * v84 = v69->cache_keys;
      int v85 = v84[0];
      v83[1] = v85;
      int * v87 = v69->cache_vals;
      int * v88 = v69->cache_vals;
      int v89 = v88[0];
      v87[1] = v89;
      int * v91 = v69->cache_keys;
      int v867 = (int)((unsigned int)v73 >> 2);
      v91[0] = v867;
      int * v93 = v69->cache_vals;
      v93[0] = v82;
      int v95 = v69->timer;
      int v870 = v95 + 1;
      v69->timer = v870;v82;
    }) : ({
      int * v98 = v69->mem;
      int v872 = (int)((unsigned int)v73 >> 2);
      int v99 = v98[v872];
      int * v100 = v69->mem;
      int * v101 = v69->cache_keys;
      int v102 = v101[1];
      int * v103 = v69->cache_vals;
      int v104 = v103[1];
      v100[v102] = v104;
      int * v106 = v69->cache_keys;
      int * v107 = v69->cache_keys;
      int v108 = v107[0];
      v106[1] = v108;
      int * v110 = v69->cache_vals;
      int * v111 = v69->cache_vals;
      int v112 = v111[0];
      v110[1] = v112;
      int * v114 = v69->cache_keys;
      v114[0] = v872;
      int * v116 = v69->cache_vals;
      v116[0] = v99;
      int v118 = v69->timer;
      int v887 = v118 + 100;
      v69->timer = v887;v99;
    }));
    v121;
  }));
  int * v124 = v69->regs;
  v124[14] = v123;
  struct StateT * v846 = v126(v69);
  return v846;
}

struct StateT * v249(struct StateT * v250) {
  int v251 = v250->timer;
  int v567 = v251 + 1;
  v250->timer = v567;int * v253 = v250->bht;
  int v254 = v253[2];
  bool v570 = !(v254 == 0);
  struct StateT * v565 = (v570 ? ({
    struct StateT * v529 = v255(v250);
    v529;
  }) : ({
    struct StateT * v563 = v531(v250);
    v563;
  }));
  return v565;
}

struct StateT * v225(struct StateT * v226) {
  int v227 = v226->timer;
  int v596 = v227 + 1;
  v226->timer = v596;int * v229 = v226->regs;
  int v230 = v229[11];
  int * v231 = v226->regs;
  int v600 = v230 + -1;
  v231[11] = v600;
  struct StateT * v594 = v233(v226);
  return v594;
}

struct StateT * v317(struct StateT * v318) {
  int * v319 = v318->saved_regs;
  int * v320 = v318->regs;
  int v321 = v320[15];
  v319[15] = v321;
  int v323 = v318->timer;
  int v433 = v323 + 1;
  v318->timer = v433;int * v325 = v318->regs;
  int v326 = v325[13];
  int * v327 = v318->cache_keys;
  int v328 = v327[0];
  bool v438 = v328 == ((int)((unsigned int)v326 >> 2));
  int v376 = (v438 ? ({
    int * v329 = v318->cache_vals;
    int v330 = v329[0];
    v330;
  }) : ({
    int * v332 = v318->cache_keys;
    int v333 = v332[1];
    bool v443 = v333 == ((int)((unsigned int)v326 >> 2));
    int v374 = (v443 ? ({
      int * v334 = v318->cache_vals;
      int v335 = v334[1];
      int * v336 = v318->cache_keys;
      int * v337 = v318->cache_keys;
      int v338 = v337[0];
      v336[1] = v338;
      int * v340 = v318->cache_vals;
      int * v341 = v318->cache_vals;
      int v342 = v341[0];
      v340[1] = v342;
      int * v344 = v318->cache_keys;
      int v452 = (int)((unsigned int)v326 >> 2);
      v344[0] = v452;
      int * v346 = v318->cache_vals;
      v346[0] = v335;
      int v348 = v318->timer;
      int v455 = v348 + 1;
      v318->timer = v455;v335;
    }) : ({
      int * v351 = v318->mem;
      int v457 = (int)((unsigned int)v326 >> 2);
      int v352 = v351[v457];
      int * v353 = v318->mem;
      int * v354 = v318->cache_keys;
      int v355 = v354[1];
      int * v356 = v318->cache_vals;
      int v357 = v356[1];
      v353[v355] = v357;
      int * v359 = v318->cache_keys;
      int * v360 = v318->cache_keys;
      int v361 = v360[0];
      v359[1] = v361;
      int * v363 = v318->cache_vals;
      int * v364 = v318->cache_vals;
      int v365 = v364[0];
      v363[1] = v365;
      int * v367 = v318->cache_keys;
      v367[0] = v457;
      int * v369 = v318->cache_vals;
      v369[0] = v352;
      int v371 = v318->timer;
      int v472 = v371 + 100;
      v318->timer = v472;v352;
    }));
    v374;
  }));
  int * v377 = v318->regs;
  v377[15] = v376;
  struct StateT * v427 = v379(v318);
  return v427;
}

struct StateT * v966(struct StateT * v967) {
  int * v968 = v967->saved_regs;
  int * v969 = v967->regs;
  int v970 = v969[13];
  v968[13] = v970;
  int v972 = v967->timer;
  int v1288 = v972 + 1;
  v967->timer = v1288;int * v974 = v967->regs;
  v974[13] = 0;
  struct StateT * v1282 = v976(v967);
  return v1282;
}

struct StateT * v126(struct StateT * v127) {
  int v128 = v127->timer;
  int v800 = v128 + 1;
  v127->timer = v800;int * v130 = v127->regs;
  int v131 = v130[13];
  int * v132 = v127->cache_keys;
  int v133 = v132[0];
  bool v805 = v133 == ((int)((unsigned int)v131 >> 2));
  int v181 = (v805 ? ({
    int * v134 = v127->cache_vals;
    int v135 = v134[0];
    v135;
  }) : ({
    int * v137 = v127->cache_keys;
    int v138 = v137[1];
    bool v810 = v138 == ((int)((unsigned int)v131 >> 2));
    int v179 = (v810 ? ({
      int * v139 = v127->cache_vals;
      int v140 = v139[1];
      int * v141 = v127->cache_keys;
      int * v142 = v127->cache_keys;
      int v143 = v142[0];
      v141[1] = v143;
      int * v145 = v127->cache_vals;
      int * v146 = v127->cache_vals;
      int v147 = v146[0];
      v145[1] = v147;
      int * v149 = v127->cache_keys;
      int v819 = (int)((unsigned int)v131 >> 2);
      v149[0] = v819;
      int * v151 = v127->cache_vals;
      v151[0] = v140;
      int v153 = v127->timer;
      int v822 = v153 + 1;
      v127->timer = v822;v140;
    }) : ({
      int * v156 = v127->mem;
      int v824 = (int)((unsigned int)v131 >> 2);
      int v157 = v156[v824];
      int * v158 = v127->mem;
      int * v159 = v127->cache_keys;
      int v160 = v159[1];
      int * v161 = v127->cache_vals;
      int v162 = v161[1];
      v158[v160] = v162;
      int * v164 = v127->cache_keys;
      int * v165 = v127->cache_keys;
      int v166 = v165[0];
      v164[1] = v166;
      int * v168 = v127->cache_vals;
      int * v169 = v127->cache_vals;
      int v170 = v169[0];
      v168[1] = v170;
      int * v172 = v127->cache_keys;
      v172[0] = v824;
      int * v174 = v127->cache_vals;
      v174[0] = v157;
      int v176 = v127->timer;
      int v839 = v176 + 100;
      v127->timer = v839;v157;
    }));
    v179;
  }));
  int * v182 = v127->regs;
  v182[15] = v181;
  struct StateT * v798 = v184(v127);
  return v798;
}

struct StateT * v976(struct StateT * v977) {
  int v978 = v977->timer;
  int v1275 = v978 + 1;
  v977->timer = v1275;int * v980 = v977->regs;
  int v981 = v980[13];
  int * v982 = v977->regs;
  v982[13] = v981;
  struct StateT * v1273 = v984(v977);
  return v1273;
}



/*****************************************
End of C Generated Code
*******************************************/

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