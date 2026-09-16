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
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
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
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * v700);
struct StateT * slot_6(struct StateT * v75);
struct StateT * slot_16(struct StateT * v808);
struct StateT * slot_23(struct StateT * v1422);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v103);
struct StateT * slot_21(struct StateT * v1137);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_10(struct StateT * v645);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v852);
struct StateT * slot_13(struct StateT * v772);
struct StateT * slot_24(struct StateT * v1449);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v792);
struct StateT * slot_17(struct StateT * v816);
struct StateT * slot_20(struct StateT * v1109);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v360);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_18(struct StateT * v824);
struct StateT * slot_9(struct StateT * v388);
struct StateT * slot_22(struct StateT * v1394);
struct StateT * slot_11(struct StateT * v673);
struct StateT * slot_12(struct StateT * v700) {
  int * v701 = v700->regs;
  int v702 = v701[14];
  int * v703 = v700->regs;
  int v704 = v703[15];
  bool v741 = v702 >= v704;
  struct StateT * v735;
  if (v741) {
    int v705 = v700->timer;
    int v742 = v705 + 15;
    v700->timer = v742;
    int * v707 = v700->saved_regs;
    int v708 = v707[6];
    int * v709 = v700->regs;
    v709[6] = v708;
    int * v711 = v700->saved_regs;
    int v712 = v711[7];
    int * v713 = v700->regs;
    v713[7] = v712;
    int * v715 = v700->saved_regs;
    int v716 = v715[8];
    int * v717 = v700->regs;
    v717[8] = v716;
    int * v719 = v700->saved_regs;
    int v720 = v719[9];
    int * v721 = v700->regs;
    v721[9] = v720;
    int * v723 = v700->saved_regs;
    int v724 = v723[16];
    int * v725 = v700->regs;
    v725[16] = v724;
    int * v727 = v700->saved_regs;
    int v728 = v727[5];
    int * v729 = v700->regs;
    v729[5] = v728;
    struct StateT * v731 = slot_13(v700);
    v735 = v731;
  } else {
    struct StateT * v733 = slot_14(v700);
    v735 = v733;
  }
  return v735;
}

struct StateT * slot_6(struct StateT * v75) {
  int * v76 = v75->saved_regs;
  int * v77 = v75->regs;
  int v78 = v77[6];
  v76[6] = v78;
  int v80 = v75->timer;
  int v94 = v80 + 1;
  v75->timer = v94;
  int * v82 = v75->regs;
  int v83 = v82[12];
  int * v84 = v75->regs;
  int v85 = v84[14];
  int * v86 = v75->regs;
  int v100 = v83 + v85;
  v86[6] = v100;
  struct StateT * v88 = slot_7(v75);
  return v88;
}

struct StateT * slot_16(struct StateT * v808) {
  int v809 = v808->timer;
  int v813 = v809 + 1;
  v808->timer = v813;
  struct StateT * v811 = slot_17(v808);
  return v811;
}

struct StateT * slot_23(struct StateT * v1422) {
  int * v1423 = v1422->saved_regs;
  int * v1424 = v1422->regs;
  int v1425 = v1424[5];
  v1423[5] = v1425;
  int v1427 = v1422->timer;
  int v1441 = v1427 + 1;
  v1422->timer = v1441;
  int * v1429 = v1422->regs;
  int v1430 = v1429[5];
  int * v1431 = v1422->regs;
  int v1432 = v1431[16];
  int * v1433 = v1422->regs;
  int v1446 = v1430 | v1432;
  v1433[5] = v1446;
  struct StateT * v1435 = slot_24(v1422);
  return v1435;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v72 = v68 + 1;
  v67->timer = v72;
  struct StateT * v70 = slot_6(v67);
  return v70;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v103) {
  int * v104 = v103->saved_regs;
  int * v105 = v103->regs;
  int v106 = v105[7];
  v104[7] = v106;
  int v108 = v103->timer;
  int v245 = v108 + 1;
  v103->timer = v245;
  int * v110 = v103->regs;
  int v111 = v110[6];
  int * v112 = v103->cache_tags;
  int v249 = (((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2;
  int v113 = v112[v249];
  int * v114 = v103->cache_tags;
  int v251 = ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + 1;
  int v115 = v114[v251];
  int * v116 = v103->cache_tags;
  int v253 = 4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2);
  int v117 = v116[v253];
  int * v118 = v103->cache_tags;
  int v255 = (4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v119 = v118[v255];
  int v120 = v103->timer;
  int v256 = v120 + ((100 ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) & 104)))));
  v103->timer = v256;
  int * v122 = v103->cache_vals;
  bool v257 = !(((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) == 0);
  int v235;
  if (v257) {
    int * v123 = v103->cache_age;
    int v259 = ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) & 1);
    int v124 = v123[v259];
    int * v125 = v103->cache_age;
    int v126 = v125[v249];
    int * v127 = v103->cache_age;
    int v262 = v126 + ((int)((unsigned int)(v126 - v124) >> 31));
    v127[v249] = v262;
    int * v129 = v103->cache_age;
    int v130 = v129[v251];
    int * v131 = v103->cache_age;
    int v265 = v130 + ((int)((unsigned int)(v130 - v124) >> 31));
    v131[v251] = v265;
    int * v133 = v103->cache_age;
    v133[v259] = 0;
    v235 = v259;
  } else {
    int * v136 = v103->cache_age;
    int v269 = (((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2;
    int v137 = v136[v269];
    int * v138 = v103->cache_tags;
    int v139 = v138[v269];
    int * v140 = v103->cache_age;
    int v141 = v140[v251];
    int * v142 = v103->cache_tags;
    int v143 = v142[v251];
    bool v273 = !(((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31))) == 0);
    int v207;
    if (v273) {
      int * v144 = v103->cache_age;
      int v275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1))))) >> 31)) & 1);
      int v145 = v144[v275];
      int * v146 = v103->cache_age;
      int v147 = v146[v253];
      int * v148 = v103->cache_age;
      int v278 = v147 + ((int)((unsigned int)(v147 - v145) >> 31));
      v148[v253] = v278;
      int * v150 = v103->cache_age;
      int v151 = v150[v255];
      int * v152 = v103->cache_age;
      int v281 = v151 + ((int)((unsigned int)(v151 - v145) >> 31));
      v152[v255] = v281;
      int * v154 = v103->cache_age;
      v154[v275] = 0;
      v207 = v275;
    } else {
      int * v157 = v103->cache_age;
      int v285 = 4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2);
      int v158 = v157[v285];
      int * v159 = v103->cache_tags;
      int v160 = v159[v285];
      int * v161 = v103->cache_age;
      int v162 = v161[v255];
      int * v163 = v103->cache_tags;
      int v164 = v163[v255];
      int * v165 = v103->cache_dirty;
      int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v166 = v165[v290];
      bool v291 = !(v166 == 0);
      if (v291) {
        int * v167 = v103->cache_tags;
        int v168 = v167[v290];
        int * v169 = v103->cache_vals;
        int v294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v170 = v169[v294];
        int * v171 = v103->cache_vals;
        int v296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v172 = v171[v296];
        int * v173 = v103->mem;
        int v298 = v168 * 2;
        v173[v298] = v170;
        int * v175 = v103->mem;
        int v301 = (v168 * 2) + 1;
        v175[v301] = v172;
        ;
      } else {
        ;
      }
      int * v180 = v103->mem;
      int v306 = ((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) * 2;
      int v181 = v180[v306];
      int * v182 = v103->mem;
      int v308 = (((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) * 2) + 1;
      int v183 = v182[v308];
      int * v184 = v103->cache_vals;
      int v310 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v184[v310] = v181;
      int * v186 = v103->cache_vals;
      int v313 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 3) * 2)) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v162 + ((~(((v164 ^ -1) | (-(v164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v186[v313] = v183;
      int * v188 = v103->cache_tags;
      int v316 = (int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1);
      v188[v290] = v316;
      int * v190 = v103->cache_dirty;
      v190[v290] = 0;
      int * v192 = v103->cache_age;
      v192[v290] = 1;
      int * v194 = v103->cache_age;
      int v195 = v194[v290];
      int * v196 = v103->cache_age;
      int v197 = v196[v253];
      int * v198 = v103->cache_age;
      int v324 = v197 + ((int)((unsigned int)(v197 - v195) >> 31));
      v198[v253] = v324;
      int * v200 = v103->cache_age;
      int v201 = v200[v255];
      int * v202 = v103->cache_age;
      int v327 = v201 + ((int)((unsigned int)(v201 - v195) >> 31));
      v202[v255] = v327;
      int * v204 = v103->cache_age;
      v204[v290] = 0;
      v207 = v290;
    }
    int * v208 = v103->cache_vals;
    int v330 = v207 * 2;
    int v209 = v208[v330];
    int * v210 = v103->cache_vals;
    int v332 = (v207 * 2) + 1;
    int v211 = v210[v332];
    int * v212 = v103->cache_vals;
    int v334 = (((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((((v137 + ((~(((v139 ^ -1) | (-(v139 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v212[v334] = v209;
    int * v214 = v103->cache_vals;
    int v337 = ((((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((((v137 + ((~(((v139 ^ -1) | (-(v139 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v214[v337] = v211;
    int * v216 = v103->cache_tags;
    int v340 = ((((int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1)) & 1) * 2) + ((((v137 + ((~(((v139 ^ -1) | (-(v139 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v143 ^ -1) | (-(v143 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v341 = (int)((unsigned int)((int)((unsigned int)v111 >> 2)) >> 1);
    v216[v340] = v341;
    int * v218 = v103->cache_dirty;
    v218[v340] = 0;
    int * v220 = v103->cache_age;
    v220[v340] = 1;
    int * v222 = v103->cache_age;
    int v223 = v222[v340];
    int * v224 = v103->cache_age;
    int v225 = v224[v249];
    int * v226 = v103->cache_age;
    int v349 = v225 + ((int)((unsigned int)(v225 - v223) >> 31));
    v226[v249] = v349;
    int * v228 = v103->cache_age;
    int v229 = v228[v251];
    int * v230 = v103->cache_age;
    int v352 = v229 + ((int)((unsigned int)(v229 - v223) >> 31));
    v230[v251] = v352;
    int * v232 = v103->cache_age;
    v232[v340] = 0;
    v235 = v340;
  }
  int v355 = (v235 * 2) + (((int)((unsigned int)v111 >> 2)) & 1);
  int v236 = v122[v355];
  int * v237 = v103->regs;
  v237[7] = v236;
  struct StateT * v239 = slot_8(v103);
  return v239;
}

struct StateT * slot_21(struct StateT * v1137) {
  int * v1138 = v1137->saved_regs;
  int * v1139 = v1137->regs;
  int v1140 = v1139[9];
  v1138[9] = v1140;
  int v1142 = v1137->timer;
  int v1279 = v1142 + 1;
  v1137->timer = v1279;
  int * v1144 = v1137->regs;
  int v1145 = v1144[8];
  int * v1146 = v1137->cache_tags;
  int v1283 = (((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2;
  int v1147 = v1146[v1283];
  int * v1148 = v1137->cache_tags;
  int v1285 = ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1149 = v1148[v1285];
  int * v1150 = v1137->cache_tags;
  int v1287 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2);
  int v1151 = v1150[v1287];
  int * v1152 = v1137->cache_tags;
  int v1289 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1153 = v1152[v1289];
  int v1154 = v1137->timer;
  int v1290 = v1154 + ((100 ^ (((~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) | (~(((v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) | (~(((v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1137->timer = v1290;
  int * v1156 = v1137->cache_vals;
  bool v1291 = !(((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31))) == 0);
  int v1269;
  if (v1291) {
    int * v1157 = v1137->cache_age;
    int v1293 = ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2) + ((~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) & 1);
    int v1158 = v1157[v1293];
    int * v1159 = v1137->cache_age;
    int v1160 = v1159[v1283];
    int * v1161 = v1137->cache_age;
    int v1296 = v1160 + ((int)((unsigned int)(v1160 - v1158) >> 31));
    v1161[v1283] = v1296;
    int * v1163 = v1137->cache_age;
    int v1164 = v1163[v1285];
    int * v1165 = v1137->cache_age;
    int v1299 = v1164 + ((int)((unsigned int)(v1164 - v1158) >> 31));
    v1165[v1285] = v1299;
    int * v1167 = v1137->cache_age;
    v1167[v1293] = 0;
    v1269 = v1293;
  } else {
    int * v1170 = v1137->cache_age;
    int v1303 = (((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2;
    int v1171 = v1170[v1303];
    int * v1172 = v1137->cache_tags;
    int v1173 = v1172[v1303];
    int * v1174 = v1137->cache_age;
    int v1175 = v1174[v1285];
    int * v1176 = v1137->cache_tags;
    int v1177 = v1176[v1285];
    bool v1307 = !(((~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) | (~(((v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31))) == 0);
    int v1241;
    if (v1307) {
      int * v1178 = v1137->cache_age;
      int v1309 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))) | (-(v1153 ^ ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1))))) >> 31)) & 1);
      int v1179 = v1178[v1309];
      int * v1180 = v1137->cache_age;
      int v1181 = v1180[v1287];
      int * v1182 = v1137->cache_age;
      int v1312 = v1181 + ((int)((unsigned int)(v1181 - v1179) >> 31));
      v1182[v1287] = v1312;
      int * v1184 = v1137->cache_age;
      int v1185 = v1184[v1289];
      int * v1186 = v1137->cache_age;
      int v1315 = v1185 + ((int)((unsigned int)(v1185 - v1179) >> 31));
      v1186[v1289] = v1315;
      int * v1188 = v1137->cache_age;
      v1188[v1309] = 0;
      v1241 = v1309;
    } else {
      int * v1191 = v1137->cache_age;
      int v1319 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2);
      int v1192 = v1191[v1319];
      int * v1193 = v1137->cache_tags;
      int v1194 = v1193[v1319];
      int * v1195 = v1137->cache_age;
      int v1196 = v1195[v1289];
      int * v1197 = v1137->cache_tags;
      int v1198 = v1197[v1289];
      int * v1199 = v1137->cache_dirty;
      int v1324 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1198 ^ -1) | (-(v1198 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1200 = v1199[v1324];
      bool v1325 = !(v1200 == 0);
      if (v1325) {
        int * v1201 = v1137->cache_tags;
        int v1202 = v1201[v1324];
        int * v1203 = v1137->cache_vals;
        int v1328 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1198 ^ -1) | (-(v1198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1204 = v1203[v1328];
        int * v1205 = v1137->cache_vals;
        int v1330 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1198 ^ -1) | (-(v1198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1206 = v1205[v1330];
        int * v1207 = v1137->mem;
        int v1332 = v1202 * 2;
        v1207[v1332] = v1204;
        int * v1209 = v1137->mem;
        int v1335 = (v1202 * 2) + 1;
        v1209[v1335] = v1206;
        ;
      } else {
        ;
      }
      int * v1214 = v1137->mem;
      int v1340 = ((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) * 2;
      int v1215 = v1214[v1340];
      int * v1216 = v1137->mem;
      int v1342 = (((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) * 2) + 1;
      int v1217 = v1216[v1342];
      int * v1218 = v1137->cache_vals;
      int v1344 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1198 ^ -1) | (-(v1198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1218[v1344] = v1215;
      int * v1220 = v1137->cache_vals;
      int v1347 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 3) * 2)) + ((((v1192 + ((~(((v1194 ^ -1) | (-(v1194 ^ -1))) >> 31)) & 2)) - (v1196 + ((~(((v1198 ^ -1) | (-(v1198 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1220[v1347] = v1217;
      int * v1222 = v1137->cache_tags;
      int v1350 = (int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1);
      v1222[v1324] = v1350;
      int * v1224 = v1137->cache_dirty;
      v1224[v1324] = 0;
      int * v1226 = v1137->cache_age;
      v1226[v1324] = 1;
      int * v1228 = v1137->cache_age;
      int v1229 = v1228[v1324];
      int * v1230 = v1137->cache_age;
      int v1231 = v1230[v1287];
      int * v1232 = v1137->cache_age;
      int v1358 = v1231 + ((int)((unsigned int)(v1231 - v1229) >> 31));
      v1232[v1287] = v1358;
      int * v1234 = v1137->cache_age;
      int v1235 = v1234[v1289];
      int * v1236 = v1137->cache_age;
      int v1361 = v1235 + ((int)((unsigned int)(v1235 - v1229) >> 31));
      v1236[v1289] = v1361;
      int * v1238 = v1137->cache_age;
      v1238[v1324] = 0;
      v1241 = v1324;
    }
    int * v1242 = v1137->cache_vals;
    int v1364 = v1241 * 2;
    int v1243 = v1242[v1364];
    int * v1244 = v1137->cache_vals;
    int v1366 = (v1241 * 2) + 1;
    int v1245 = v1244[v1366];
    int * v1246 = v1137->cache_vals;
    int v1368 = (((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2) + ((((v1171 + ((~(((v1173 ^ -1) | (-(v1173 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1177 ^ -1) | (-(v1177 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1246[v1368] = v1243;
    int * v1248 = v1137->cache_vals;
    int v1371 = ((((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2) + ((((v1171 + ((~(((v1173 ^ -1) | (-(v1173 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1177 ^ -1) | (-(v1177 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1248[v1371] = v1245;
    int * v1250 = v1137->cache_tags;
    int v1374 = ((((int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1)) & 1) * 2) + ((((v1171 + ((~(((v1173 ^ -1) | (-(v1173 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1177 ^ -1) | (-(v1177 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1375 = (int)((unsigned int)((int)((unsigned int)v1145 >> 2)) >> 1);
    v1250[v1374] = v1375;
    int * v1252 = v1137->cache_dirty;
    v1252[v1374] = 0;
    int * v1254 = v1137->cache_age;
    v1254[v1374] = 1;
    int * v1256 = v1137->cache_age;
    int v1257 = v1256[v1374];
    int * v1258 = v1137->cache_age;
    int v1259 = v1258[v1283];
    int * v1260 = v1137->cache_age;
    int v1383 = v1259 + ((int)((unsigned int)(v1259 - v1257) >> 31));
    v1260[v1283] = v1383;
    int * v1262 = v1137->cache_age;
    int v1263 = v1262[v1285];
    int * v1264 = v1137->cache_age;
    int v1386 = v1263 + ((int)((unsigned int)(v1263 - v1257) >> 31));
    v1264[v1285] = v1386;
    int * v1266 = v1137->cache_age;
    v1266[v1374] = 0;
    v1269 = v1374;
  }
  int v1389 = (v1269 * 2) + (((int)((unsigned int)v1145 >> 2)) & 1);
  int v1270 = v1156[v1389];
  int * v1271 = v1137->regs;
  v1271[9] = v1270;
  struct StateT * v1273 = slot_22(v1137);
  return v1273;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * slot_10(struct StateT * v645) {
  int * v646 = v645->saved_regs;
  int * v647 = v645->regs;
  int v648 = v647[16];
  v646[16] = v648;
  int v650 = v645->timer;
  int v664 = v650 + 1;
  v645->timer = v664;
  int * v652 = v645->regs;
  int v653 = v652[7];
  int * v654 = v645->regs;
  int v655 = v654[9];
  int * v656 = v645->regs;
  int v670 = v653 ^ v655;
  v656[16] = v670;
  struct StateT * v658 = slot_11(v645);
  return v658;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_19(struct StateT * v852) {
  int * v853 = v852->saved_regs;
  int * v854 = v852->regs;
  int v855 = v854[7];
  v853[7] = v855;
  int v857 = v852->timer;
  int v994 = v857 + 1;
  v852->timer = v994;
  int * v859 = v852->regs;
  int v860 = v859[6];
  int * v861 = v852->cache_tags;
  int v998 = (((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2;
  int v862 = v861[v998];
  int * v863 = v852->cache_tags;
  int v1000 = ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + 1;
  int v864 = v863[v1000];
  int * v865 = v852->cache_tags;
  int v1002 = 4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2);
  int v866 = v865[v1002];
  int * v867 = v852->cache_tags;
  int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v868 = v867[v1004];
  int v869 = v852->timer;
  int v1005 = v869 + ((100 ^ (((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) & 104)))));
  v852->timer = v1005;
  int * v871 = v852->cache_vals;
  bool v1006 = !(((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) == 0);
  int v984;
  if (v1006) {
    int * v872 = v852->cache_age;
    int v1008 = ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) & 1);
    int v873 = v872[v1008];
    int * v874 = v852->cache_age;
    int v875 = v874[v998];
    int * v876 = v852->cache_age;
    int v1011 = v875 + ((int)((unsigned int)(v875 - v873) >> 31));
    v876[v998] = v1011;
    int * v878 = v852->cache_age;
    int v879 = v878[v1000];
    int * v880 = v852->cache_age;
    int v1014 = v879 + ((int)((unsigned int)(v879 - v873) >> 31));
    v880[v1000] = v1014;
    int * v882 = v852->cache_age;
    v882[v1008] = 0;
    v984 = v1008;
  } else {
    int * v885 = v852->cache_age;
    int v1018 = (((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2;
    int v886 = v885[v1018];
    int * v887 = v852->cache_tags;
    int v888 = v887[v1018];
    int * v889 = v852->cache_age;
    int v890 = v889[v1000];
    int * v891 = v852->cache_tags;
    int v892 = v891[v1000];
    bool v1022 = !(((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31))) == 0);
    int v956;
    if (v1022) {
      int * v893 = v852->cache_age;
      int v1024 = (4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1))))) >> 31)) & 1);
      int v894 = v893[v1024];
      int * v895 = v852->cache_age;
      int v896 = v895[v1002];
      int * v897 = v852->cache_age;
      int v1027 = v896 + ((int)((unsigned int)(v896 - v894) >> 31));
      v897[v1002] = v1027;
      int * v899 = v852->cache_age;
      int v900 = v899[v1004];
      int * v901 = v852->cache_age;
      int v1030 = v900 + ((int)((unsigned int)(v900 - v894) >> 31));
      v901[v1004] = v1030;
      int * v903 = v852->cache_age;
      v903[v1024] = 0;
      v956 = v1024;
    } else {
      int * v906 = v852->cache_age;
      int v1034 = 4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2);
      int v907 = v906[v1034];
      int * v908 = v852->cache_tags;
      int v909 = v908[v1034];
      int * v910 = v852->cache_age;
      int v911 = v910[v1004];
      int * v912 = v852->cache_tags;
      int v913 = v912[v1004];
      int * v914 = v852->cache_dirty;
      int v1039 = (4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v915 = v914[v1039];
      bool v1040 = !(v915 == 0);
      if (v1040) {
        int * v916 = v852->cache_tags;
        int v917 = v916[v1039];
        int * v918 = v852->cache_vals;
        int v1043 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v919 = v918[v1043];
        int * v920 = v852->cache_vals;
        int v1045 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v921 = v920[v1045];
        int * v922 = v852->mem;
        int v1047 = v917 * 2;
        v922[v1047] = v919;
        int * v924 = v852->mem;
        int v1050 = (v917 * 2) + 1;
        v924[v1050] = v921;
        ;
      } else {
        ;
      }
      int * v929 = v852->mem;
      int v1055 = ((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) * 2;
      int v930 = v929[v1055];
      int * v931 = v852->mem;
      int v1057 = (((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) * 2) + 1;
      int v932 = v931[v1057];
      int * v933 = v852->cache_vals;
      int v1059 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v933[v1059] = v930;
      int * v935 = v852->cache_vals;
      int v1062 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 3) * 2)) + ((((v907 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2)) - (v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v935[v1062] = v932;
      int * v937 = v852->cache_tags;
      int v1065 = (int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1);
      v937[v1039] = v1065;
      int * v939 = v852->cache_dirty;
      v939[v1039] = 0;
      int * v941 = v852->cache_age;
      v941[v1039] = 1;
      int * v943 = v852->cache_age;
      int v944 = v943[v1039];
      int * v945 = v852->cache_age;
      int v946 = v945[v1002];
      int * v947 = v852->cache_age;
      int v1073 = v946 + ((int)((unsigned int)(v946 - v944) >> 31));
      v947[v1002] = v1073;
      int * v949 = v852->cache_age;
      int v950 = v949[v1004];
      int * v951 = v852->cache_age;
      int v1076 = v950 + ((int)((unsigned int)(v950 - v944) >> 31));
      v951[v1004] = v1076;
      int * v953 = v852->cache_age;
      v953[v1039] = 0;
      v956 = v1039;
    }
    int * v957 = v852->cache_vals;
    int v1079 = v956 * 2;
    int v958 = v957[v1079];
    int * v959 = v852->cache_vals;
    int v1081 = (v956 * 2) + 1;
    int v960 = v959[v1081];
    int * v961 = v852->cache_vals;
    int v1083 = (((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((((v886 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v961[v1083] = v958;
    int * v963 = v852->cache_vals;
    int v1086 = ((((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((((v886 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v963[v1086] = v960;
    int * v965 = v852->cache_tags;
    int v1089 = ((((int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1)) & 1) * 2) + ((((v886 + ((~(((v888 ^ -1) | (-(v888 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v892 ^ -1) | (-(v892 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1090 = (int)((unsigned int)((int)((unsigned int)v860 >> 2)) >> 1);
    v965[v1089] = v1090;
    int * v967 = v852->cache_dirty;
    v967[v1089] = 0;
    int * v969 = v852->cache_age;
    v969[v1089] = 1;
    int * v971 = v852->cache_age;
    int v972 = v971[v1089];
    int * v973 = v852->cache_age;
    int v974 = v973[v998];
    int * v975 = v852->cache_age;
    int v1098 = v974 + ((int)((unsigned int)(v974 - v972) >> 31));
    v975[v998] = v1098;
    int * v977 = v852->cache_age;
    int v978 = v977[v1000];
    int * v979 = v852->cache_age;
    int v1101 = v978 + ((int)((unsigned int)(v978 - v972) >> 31));
    v979[v1000] = v1101;
    int * v981 = v852->cache_age;
    v981[v1089] = 0;
    v984 = v1089;
  }
  int v1104 = (v984 * 2) + (((int)((unsigned int)v860 >> 2)) & 1);
  int v985 = v871[v1104];
  int * v986 = v852->regs;
  v986[7] = v985;
  struct StateT * v988 = slot_20(v852);
  return v988;
}

struct StateT * slot_13(struct StateT * v772) {
  int v773 = v772->timer;
  int v783 = v773 + 1;
  v772->timer = v783;
  int * v775 = v772->regs;
  int v776 = v775[5];
  bool v786 = (v776 ^ -2147483648) < -2147483647;
  int v779;
  if (v786) {
    v779 = 1;
  } else {
    v779 = 0;
  }
  int * v780 = v772->regs;
  v780[11] = v779;
  return v772;
}

struct StateT * slot_24(struct StateT * v1449) {
  int * v1450 = v1449->regs;
  int v1451 = v1450[14];
  int * v1452 = v1449->regs;
  int v1453 = v1452[15];
  bool v1490 = v1451 >= v1453;
  struct StateT * v1484;
  if (v1490) {
    int v1454 = v1449->timer;
    int v1491 = v1454 + 15;
    v1449->timer = v1491;
    int * v1456 = v1449->saved_regs;
    int v1457 = v1456[6];
    int * v1458 = v1449->regs;
    v1458[6] = v1457;
    int * v1460 = v1449->saved_regs;
    int v1461 = v1460[7];
    int * v1462 = v1449->regs;
    v1462[7] = v1461;
    int * v1464 = v1449->saved_regs;
    int v1465 = v1464[8];
    int * v1466 = v1449->regs;
    v1466[8] = v1465;
    int * v1468 = v1449->saved_regs;
    int v1469 = v1468[9];
    int * v1470 = v1449->regs;
    v1470[9] = v1469;
    int * v1472 = v1449->saved_regs;
    int v1473 = v1472[16];
    int * v1474 = v1449->regs;
    v1474[16] = v1473;
    int * v1476 = v1449->saved_regs;
    int v1477 = v1476[5];
    int * v1478 = v1449->regs;
    v1478[5] = v1477;
    struct StateT * v1480 = slot_13(v1449);
    v1484 = v1480;
  } else {
    struct StateT * v1482 = slot_14(v1449);
    v1484 = v1482;
  }
  return v1484;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v792) {
  int v793 = v792->timer;
  int v801 = v793 + 1;
  v792->timer = v801;
  int * v795 = v792->regs;
  int v796 = v795[14];
  int * v797 = v792->regs;
  int v805 = v796 + 4;
  v797[14] = v805;
  struct StateT * v799 = slot_16(v792);
  return v799;
}

struct StateT * slot_17(struct StateT * v816) {
  int v817 = v816->timer;
  int v821 = v817 + 1;
  v816->timer = v821;
  struct StateT * v819 = slot_18(v816);
  return v819;
}

struct StateT * slot_20(struct StateT * v1109) {
  int * v1110 = v1109->saved_regs;
  int * v1111 = v1109->regs;
  int v1112 = v1111[8];
  v1110[8] = v1112;
  int v1114 = v1109->timer;
  int v1128 = v1114 + 1;
  v1109->timer = v1128;
  int * v1116 = v1109->regs;
  int v1117 = v1116[13];
  int * v1118 = v1109->regs;
  int v1119 = v1118[14];
  int * v1120 = v1109->regs;
  int v1134 = v1117 + v1119;
  v1120[8] = v1134;
  struct StateT * v1122 = slot_21(v1109);
  return v1122;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v360) {
  int * v361 = v360->saved_regs;
  int * v362 = v360->regs;
  int v363 = v362[8];
  v361[8] = v363;
  int v365 = v360->timer;
  int v379 = v365 + 1;
  v360->timer = v379;
  int * v367 = v360->regs;
  int v368 = v367[13];
  int * v369 = v360->regs;
  int v370 = v369[14];
  int * v371 = v360->regs;
  int v385 = v368 + v370;
  v371[8] = v385;
  struct StateT * v373 = slot_9(v360);
  return v373;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_18(struct StateT * v824) {
  int * v825 = v824->saved_regs;
  int * v826 = v824->regs;
  int v827 = v826[6];
  v825[6] = v827;
  int v829 = v824->timer;
  int v843 = v829 + 1;
  v824->timer = v843;
  int * v831 = v824->regs;
  int v832 = v831[12];
  int * v833 = v824->regs;
  int v834 = v833[14];
  int * v835 = v824->regs;
  int v849 = v832 + v834;
  v835[6] = v849;
  struct StateT * v837 = slot_19(v824);
  return v837;
}

struct StateT * slot_9(struct StateT * v388) {
  int * v389 = v388->saved_regs;
  int * v390 = v388->regs;
  int v391 = v390[9];
  v389[9] = v391;
  int v393 = v388->timer;
  int v530 = v393 + 1;
  v388->timer = v530;
  int * v395 = v388->regs;
  int v396 = v395[8];
  int * v397 = v388->cache_tags;
  int v534 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2;
  int v398 = v397[v534];
  int * v399 = v388->cache_tags;
  int v536 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + 1;
  int v400 = v399[v536];
  int * v401 = v388->cache_tags;
  int v538 = 4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2);
  int v402 = v401[v538];
  int * v403 = v388->cache_tags;
  int v540 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v404 = v403[v540];
  int v405 = v388->timer;
  int v541 = v405 + ((100 ^ (((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) & 104)))));
  v388->timer = v541;
  int * v407 = v388->cache_vals;
  bool v542 = !(((~(((v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v398 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) == 0);
  int v520;
  if (v542) {
    int * v408 = v388->cache_age;
    int v544 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) & 1);
    int v409 = v408[v544];
    int * v410 = v388->cache_age;
    int v411 = v410[v534];
    int * v412 = v388->cache_age;
    int v547 = v411 + ((int)((unsigned int)(v411 - v409) >> 31));
    v412[v534] = v547;
    int * v414 = v388->cache_age;
    int v415 = v414[v536];
    int * v416 = v388->cache_age;
    int v550 = v415 + ((int)((unsigned int)(v415 - v409) >> 31));
    v416[v536] = v550;
    int * v418 = v388->cache_age;
    v418[v544] = 0;
    v520 = v544;
  } else {
    int * v421 = v388->cache_age;
    int v554 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2;
    int v422 = v421[v554];
    int * v423 = v388->cache_tags;
    int v424 = v423[v554];
    int * v425 = v388->cache_age;
    int v426 = v425[v536];
    int * v427 = v388->cache_tags;
    int v428 = v427[v536];
    bool v558 = !(((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31))) == 0);
    int v492;
    if (v558) {
      int * v429 = v388->cache_age;
      int v560 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1))))) >> 31)) & 1);
      int v430 = v429[v560];
      int * v431 = v388->cache_age;
      int v432 = v431[v538];
      int * v433 = v388->cache_age;
      int v563 = v432 + ((int)((unsigned int)(v432 - v430) >> 31));
      v433[v538] = v563;
      int * v435 = v388->cache_age;
      int v436 = v435[v540];
      int * v437 = v388->cache_age;
      int v566 = v436 + ((int)((unsigned int)(v436 - v430) >> 31));
      v437[v540] = v566;
      int * v439 = v388->cache_age;
      v439[v560] = 0;
      v492 = v560;
    } else {
      int * v442 = v388->cache_age;
      int v570 = 4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2);
      int v443 = v442[v570];
      int * v444 = v388->cache_tags;
      int v445 = v444[v570];
      int * v446 = v388->cache_age;
      int v447 = v446[v540];
      int * v448 = v388->cache_tags;
      int v449 = v448[v540];
      int * v450 = v388->cache_dirty;
      int v575 = (4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v451 = v450[v575];
      bool v576 = !(v451 == 0);
      if (v576) {
        int * v452 = v388->cache_tags;
        int v453 = v452[v575];
        int * v454 = v388->cache_vals;
        int v579 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v455 = v454[v579];
        int * v456 = v388->cache_vals;
        int v581 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v457 = v456[v581];
        int * v458 = v388->mem;
        int v583 = v453 * 2;
        v458[v583] = v455;
        int * v460 = v388->mem;
        int v586 = (v453 * 2) + 1;
        v460[v586] = v457;
        ;
      } else {
        ;
      }
      int * v465 = v388->mem;
      int v591 = ((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) * 2;
      int v466 = v465[v591];
      int * v467 = v388->mem;
      int v593 = (((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) * 2) + 1;
      int v468 = v467[v593];
      int * v469 = v388->cache_vals;
      int v595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v469[v595] = v466;
      int * v471 = v388->cache_vals;
      int v598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 3) * 2)) + ((((v443 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v471[v598] = v468;
      int * v473 = v388->cache_tags;
      int v601 = (int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1);
      v473[v575] = v601;
      int * v475 = v388->cache_dirty;
      v475[v575] = 0;
      int * v477 = v388->cache_age;
      v477[v575] = 1;
      int * v479 = v388->cache_age;
      int v480 = v479[v575];
      int * v481 = v388->cache_age;
      int v482 = v481[v538];
      int * v483 = v388->cache_age;
      int v609 = v482 + ((int)((unsigned int)(v482 - v480) >> 31));
      v483[v538] = v609;
      int * v485 = v388->cache_age;
      int v486 = v485[v540];
      int * v487 = v388->cache_age;
      int v612 = v486 + ((int)((unsigned int)(v486 - v480) >> 31));
      v487[v540] = v612;
      int * v489 = v388->cache_age;
      v489[v575] = 0;
      v492 = v575;
    }
    int * v493 = v388->cache_vals;
    int v615 = v492 * 2;
    int v494 = v493[v615];
    int * v495 = v388->cache_vals;
    int v617 = (v492 * 2) + 1;
    int v496 = v495[v617];
    int * v497 = v388->cache_vals;
    int v619 = (((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v422 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v497[v619] = v494;
    int * v499 = v388->cache_vals;
    int v622 = ((((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v422 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v499[v622] = v496;
    int * v501 = v388->cache_tags;
    int v625 = ((((int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1)) & 1) * 2) + ((((v422 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2)) - (v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v626 = (int)((unsigned int)((int)((unsigned int)v396 >> 2)) >> 1);
    v501[v625] = v626;
    int * v503 = v388->cache_dirty;
    v503[v625] = 0;
    int * v505 = v388->cache_age;
    v505[v625] = 1;
    int * v507 = v388->cache_age;
    int v508 = v507[v625];
    int * v509 = v388->cache_age;
    int v510 = v509[v534];
    int * v511 = v388->cache_age;
    int v634 = v510 + ((int)((unsigned int)(v510 - v508) >> 31));
    v511[v534] = v634;
    int * v513 = v388->cache_age;
    int v514 = v513[v536];
    int * v515 = v388->cache_age;
    int v637 = v514 + ((int)((unsigned int)(v514 - v508) >> 31));
    v515[v536] = v637;
    int * v517 = v388->cache_age;
    v517[v625] = 0;
    v520 = v625;
  }
  int v640 = (v520 * 2) + (((int)((unsigned int)v396 >> 2)) & 1);
  int v521 = v407[v640];
  int * v522 = v388->regs;
  v522[9] = v521;
  struct StateT * v524 = slot_10(v388);
  return v524;
}

struct StateT * slot_22(struct StateT * v1394) {
  int * v1395 = v1394->saved_regs;
  int * v1396 = v1394->regs;
  int v1397 = v1396[16];
  v1395[16] = v1397;
  int v1399 = v1394->timer;
  int v1413 = v1399 + 1;
  v1394->timer = v1413;
  int * v1401 = v1394->regs;
  int v1402 = v1401[7];
  int * v1403 = v1394->regs;
  int v1404 = v1403[9];
  int * v1405 = v1394->regs;
  int v1419 = v1402 ^ v1404;
  v1405[16] = v1419;
  struct StateT * v1407 = slot_23(v1394);
  return v1407;
}

struct StateT * slot_11(struct StateT * v673) {
  int * v674 = v673->saved_regs;
  int * v675 = v673->regs;
  int v676 = v675[5];
  v674[5] = v676;
  int v678 = v673->timer;
  int v692 = v678 + 1;
  v673->timer = v692;
  int * v680 = v673->regs;
  int v681 = v680[5];
  int * v682 = v673->regs;
  int v683 = v682[16];
  int * v684 = v673->regs;
  int v697 = v681 | v683;
  v684[5] = v697;
  struct StateT * v686 = slot_12(v673);
  return v686;
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

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}