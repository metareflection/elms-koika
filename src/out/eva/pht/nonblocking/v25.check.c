// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * slot_12(struct StateT * v518);
struct StateT * slot_6(struct StateT * v613);
struct StateT * slot_16(struct StateT * v679);
struct StateT * slot_5(struct StateT * v581);
struct StateT * slot_2(struct StateT * v78);
struct StateT * slot_7(struct StateT * v655);
struct StateT * slot_21(struct StateT * v1171);
struct StateT * slot_3(struct StateT * v492);
struct StateT * slot_10(struct StateT * v57);
struct StateT * slot_1(struct StateT * v41);
struct StateT * slot_19(struct StateT * v939);
struct StateT * slot_13(struct StateT * v560);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v597);
struct StateT * slot_17(struct StateT * v708);
struct StateT * slot_20(struct StateT * v1147);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v700);
struct StateT * slot_4(struct StateT * v539);
struct StateT * slot_15(struct StateT * v634);
struct StateT * slot_18(struct StateT * v732);
struct StateT * slot_9(struct StateT * v25);
struct StateT * slot_22(struct StateT * v534);
struct StateT * slot_11(struct StateT * v285);
struct StateT * slot_12(struct StateT * v518) {
  int v519 = v518->timer;
  int v527 = v519 + 1;
  v518->timer = v527;
  int * v521 = v518->reg_ready;
  v521[11] = v527;
  int * v523 = v518->regs;
  v523[11] = 0;
  struct StateT * v525 = slot_13(v518);
  return v525;
}

struct StateT * slot_6(struct StateT * v613) {
  int v614 = v613->timer;
  int v625 = v614 + 1;
  v613->timer = v625;
  int * v616 = v613->reg_ready;
  int v617 = v616[11];
  int * v618 = v613->regs;
  int v619 = v618[11];
  int v629 = (v617 + ((v614 - v617) & (~((v614 - v617) >> 31)))) + 1;
  v616[11] = v629;
  int * v621 = v613->regs;
  int v631 = v619 + 72;
  v621[11] = v631;
  struct StateT * v623 = slot_7(v613);
  return v623;
}

struct StateT * slot_16(struct StateT * v679) {
  int v680 = v679->timer;
  int v691 = v680 + 1;
  v679->timer = v691;
  int * v682 = v679->reg_ready;
  int v683 = v682[10];
  int * v684 = v679->regs;
  int v685 = v684[10];
  int v695 = (v683 + ((v680 - v683) & (~((v680 - v683) >> 31)))) + 1;
  v682[10] = v695;
  int * v687 = v679->regs;
  int v697 = (int)((unsigned int)v685 >> 26);
  v687[10] = v697;
  struct StateT * v689 = slot_17(v679);
  return v689;
}

struct StateT * slot_5(struct StateT * v581) {
  int v582 = v581->timer;
  int v590 = v582 + 1;
  v581->timer = v590;
  int * v584 = v581->reg_ready;
  v584[11] = v590;
  int * v586 = v581->regs;
  v586[11] = 0;
  struct StateT * v588 = slot_6(v581);
  return v588;
}

struct StateT * slot_2(struct StateT * v78) {
  int v79 = v78->timer;
  int v191 = v79 + 1;
  v78->timer = v191;
  int * v81 = v78->reg_ready;
  int v82 = v81[11];
  int * v83 = v78->regs;
  int v84 = v83[11];
  int * v85 = v78->cache_tags;
  int v196 = (((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2;
  int v86 = v85[v196];
  int v197 = ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2) + 1;
  int v87 = v85[v197];
  int v198 = 4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2);
  int v88 = v85[v198];
  int v199 = (4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v89 = v85[v199];
  int * v90 = v78->cache_vals;
  bool v200 = !(((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31))) == 0);
  int v183;
  if (v200) {
    int * v91 = v78->cache_age;
    int v202 = ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2) + ((~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) & 1);
    int v92 = v91[v202];
    int v93 = v91[v196];
    int v203 = v93 + ((int)((unsigned int)(v93 - v92) >> 31));
    v91[v196] = v203;
    int * v95 = v78->cache_age;
    int v96 = v95[v197];
    int v205 = v96 + ((int)((unsigned int)(v96 - v92) >> 31));
    v95[v197] = v205;
    int * v98 = v78->cache_age;
    v98[v202] = 0;
    v183 = v202;
  } else {
    int * v101 = v78->cache_age;
    int v209 = (((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2;
    int v102 = v101[v209];
    int * v103 = v78->cache_tags;
    int v104 = v103[v209];
    int v105 = v101[v197];
    int v106 = v103[v197];
    bool v211 = !(((~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31))) == 0);
    int v160;
    if (v211) {
      int * v107 = v78->cache_age;
      int v213 = (4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + ((~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) & 1);
      int v108 = v107[v213];
      int v109 = v107[v198];
      int v214 = v109 + ((int)((unsigned int)(v109 - v108) >> 31));
      v107[v198] = v214;
      int * v111 = v78->cache_age;
      int v112 = v111[v199];
      int v216 = v112 + ((int)((unsigned int)(v112 - v108) >> 31));
      v111[v199] = v216;
      int * v114 = v78->cache_age;
      v114[v213] = 0;
      v160 = v213;
    } else {
      int * v117 = v78->cache_age;
      int v220 = 4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2);
      int v118 = v117[v220];
      int * v119 = v78->cache_tags;
      int v120 = v119[v220];
      int v121 = v117[v199];
      int v122 = v119[v199];
      int * v123 = v78->cache_dirty;
      int v223 = (4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v124 = v123[v223];
      bool v224 = !(v124 == 0);
      if (v224) {
        int * v125 = v78->cache_tags;
        int v126 = v125[v223];
        int * v127 = v78->cache_vals;
        int v227 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v128 = v127[v227];
        int v228 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v129 = v127[v228];
        int * v130 = v78->mem;
        int v230 = v126 * 2;
        v130[v230] = v128;
        int * v132 = v78->mem;
        int v233 = (v126 * 2) + 1;
        v132[v233] = v129;
        ;
      } else {
        ;
      }
      int * v137 = v78->mem;
      int v238 = ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) * 2;
      int v138 = v137[v238];
      int v239 = (((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) * 2) + 1;
      int v139 = v137[v239];
      int * v140 = v78->cache_vals;
      int v241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v140[v241] = v138;
      int * v142 = v78->cache_vals;
      int v244 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 3) * 2)) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v142[v244] = v139;
      int * v144 = v78->cache_tags;
      int v247 = (int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1);
      v144[v223] = v247;
      int * v146 = v78->cache_dirty;
      v146[v223] = 0;
      int * v148 = v78->cache_age;
      v148[v223] = 1;
      int * v150 = v78->cache_age;
      int v151 = v150[v223];
      int v152 = v150[v198];
      int v253 = v152 + ((int)((unsigned int)(v152 - v151) >> 31));
      v150[v198] = v253;
      int * v154 = v78->cache_age;
      int v155 = v154[v199];
      int v255 = v155 + ((int)((unsigned int)(v155 - v151) >> 31));
      v154[v199] = v255;
      int * v157 = v78->cache_age;
      v157[v223] = 0;
      v160 = v223;
    }
    int * v161 = v78->cache_vals;
    int v258 = v160 * 2;
    int v162 = v161[v258];
    int v259 = (v160 * 2) + 1;
    int v163 = v161[v259];
    int v260 = (((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v161[v260] = v162;
    int * v165 = v78->cache_vals;
    int v263 = ((((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v165[v263] = v163;
    int * v167 = v78->cache_tags;
    int v266 = ((((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1)) & 1) * 2) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v267 = (int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1);
    v167[v266] = v267;
    int * v169 = v78->cache_dirty;
    v169[v266] = 0;
    int * v171 = v78->cache_age;
    v171[v266] = 1;
    int * v173 = v78->cache_age;
    int v174 = v173[v266];
    int v175 = v173[v196];
    int v273 = v175 + ((int)((unsigned int)(v175 - v174) >> 31));
    v173[v196] = v273;
    int * v177 = v78->cache_age;
    int v178 = v177[v197];
    int v275 = v178 + ((int)((unsigned int)(v178 - v174) >> 31));
    v177[v197] = v275;
    int * v180 = v78->cache_age;
    v180[v266] = 0;
    v183 = v266;
  }
  int v278 = (v183 * 2) + (((int)((unsigned int)v84 >> 2)) & 1);
  int v184 = v90[v278];
  int * v185 = v78->reg_ready;
  int v280 = ((v82 + ((v79 - v82) & (~((v79 - v82) >> 31)))) + 1) + ((100 ^ (((~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) | (~(((v87 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v87 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31)) | (~(((v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))) | (-(v89 ^ ((int)((unsigned int)((int)((unsigned int)v84 >> 2)) >> 1))))) >> 31))) & 104)))));
  v185[11] = v280;
  int * v187 = v78->regs;
  v187[11] = v184;
  struct StateT * v189 = slot_3(v78);
  return v189;
}

struct StateT * slot_7(struct StateT * v655) {
  int v656 = v655->timer;
  int v669 = v656 + 1;
  v655->timer = v669;
  int * v658 = v655->reg_ready;
  int v659 = v658[11];
  int * v660 = v655->regs;
  int v661 = v660[11];
  int v662 = v658[10];
  int v663 = v660[10];
  int v674 = (v662 + (((v659 + ((v656 - v659) & (~((v656 - v659) >> 31)))) - v662) & (~(((v659 + ((v656 - v659) & (~((v656 - v659) >> 31)))) - v662) >> 31)))) + 1;
  v658[10] = v674;
  int * v665 = v655->regs;
  int v676 = v661 + v663;
  v665[10] = v676;
  struct StateT * v667 = slot_8(v655);
  return v667;
}

struct StateT * slot_21(struct StateT * v1171) {
  int v1172 = v1171->timer;
  int v1345 = v1172 + 1;
  v1171->timer = v1345;
  int * v1174 = v1171->reg_ready;
  int * v1176 = v1171->regs;
  int v1177 = v1176[12];
  int v1179 = v1176[10];
  int * v1180 = v1171->cache_tags;
  int v1351 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1181 = v1180[v1351];
  int v1352 = ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1182 = v1180[v1352];
  int v1353 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1183 = v1180[v1353];
  int v1354 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1184 = v1180[v1354];
  int v1185 = v1171->timer;
  int v1355 = v1185 + ((100 ^ (((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1171->timer = v1355;
  bool v1356 = !(((~(((v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1181 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1279;
  if (v1356) {
    int * v1187 = v1171->cache_age;
    int v1358 = ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1182 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1188 = v1187[v1358];
    int v1189 = v1187[v1351];
    int v1359 = v1189 + ((int)((unsigned int)(v1189 - v1188) >> 31));
    v1187[v1351] = v1359;
    int * v1191 = v1171->cache_age;
    int v1192 = v1191[v1352];
    int v1361 = v1192 + ((int)((unsigned int)(v1192 - v1188) >> 31));
    v1191[v1352] = v1361;
    int * v1194 = v1171->cache_age;
    v1194[v1358] = 0;
    v1279 = v1358;
  } else {
    int * v1197 = v1171->cache_age;
    int v1365 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1198 = v1197[v1365];
    int * v1199 = v1171->cache_tags;
    int v1200 = v1199[v1365];
    int v1201 = v1197[v1352];
    int v1202 = v1199[v1352];
    bool v1367 = !(((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1256;
    if (v1367) {
      int * v1203 = v1171->cache_age;
      int v1369 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1204 = v1203[v1369];
      int v1205 = v1203[v1353];
      int v1370 = v1205 + ((int)((unsigned int)(v1205 - v1204) >> 31));
      v1203[v1353] = v1370;
      int * v1207 = v1171->cache_age;
      int v1208 = v1207[v1354];
      int v1372 = v1208 + ((int)((unsigned int)(v1208 - v1204) >> 31));
      v1207[v1354] = v1372;
      int * v1210 = v1171->cache_age;
      v1210[v1369] = 0;
      v1256 = v1369;
    } else {
      int * v1213 = v1171->cache_age;
      int v1376 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1214 = v1213[v1376];
      int * v1215 = v1171->cache_tags;
      int v1216 = v1215[v1376];
      int v1217 = v1213[v1354];
      int v1218 = v1215[v1354];
      int * v1219 = v1171->cache_dirty;
      int v1379 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1220 = v1219[v1379];
      bool v1380 = !(v1220 == 0);
      if (v1380) {
        int * v1221 = v1171->cache_tags;
        int v1222 = v1221[v1379];
        int * v1223 = v1171->cache_vals;
        int v1383 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1224 = v1223[v1383];
        int v1384 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1225 = v1223[v1384];
        int * v1226 = v1171->mem;
        int v1386 = v1222 * 2;
        v1226[v1386] = v1224;
        int * v1228 = v1171->mem;
        int v1389 = (v1222 * 2) + 1;
        v1228[v1389] = v1225;
        ;
      } else {
        ;
      }
      int * v1233 = v1171->mem;
      int v1394 = ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2;
      int v1234 = v1233[v1394];
      int v1395 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1235 = v1233[v1395];
      int * v1236 = v1171->cache_vals;
      int v1397 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1236[v1397] = v1234;
      int * v1238 = v1171->cache_vals;
      int v1400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1214 + ((~(((v1216 ^ -1) | (-(v1216 ^ -1))) >> 31)) & 2)) - (v1217 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1238[v1400] = v1235;
      int * v1240 = v1171->cache_tags;
      int v1403 = (int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1);
      v1240[v1379] = v1403;
      int * v1242 = v1171->cache_dirty;
      v1242[v1379] = 0;
      int * v1244 = v1171->cache_age;
      v1244[v1379] = 1;
      int * v1246 = v1171->cache_age;
      int v1247 = v1246[v1379];
      int v1248 = v1246[v1353];
      int v1409 = v1248 + ((int)((unsigned int)(v1248 - v1247) >> 31));
      v1246[v1353] = v1409;
      int * v1250 = v1171->cache_age;
      int v1251 = v1250[v1354];
      int v1411 = v1251 + ((int)((unsigned int)(v1251 - v1247) >> 31));
      v1250[v1354] = v1411;
      int * v1253 = v1171->cache_age;
      v1253[v1379] = 0;
      v1256 = v1379;
    }
    int * v1257 = v1171->cache_vals;
    int v1414 = v1256 * 2;
    int v1258 = v1257[v1414];
    int v1415 = (v1256 * 2) + 1;
    int v1259 = v1257[v1415];
    int v1416 = (((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1198 + ((~(((v1200 ^ -1) | (-(v1200 ^ -1))) >> 31)) & 2)) - (v1201 + ((~(((v1202 ^ -1) | (-(v1202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1257[v1416] = v1258;
    int * v1261 = v1171->cache_vals;
    int v1419 = ((((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1198 + ((~(((v1200 ^ -1) | (-(v1200 ^ -1))) >> 31)) & 2)) - (v1201 + ((~(((v1202 ^ -1) | (-(v1202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1261[v1419] = v1259;
    int * v1263 = v1171->cache_tags;
    int v1422 = ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1198 + ((~(((v1200 ^ -1) | (-(v1200 ^ -1))) >> 31)) & 2)) - (v1201 + ((~(((v1202 ^ -1) | (-(v1202 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1423 = (int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1);
    v1263[v1422] = v1423;
    int * v1265 = v1171->cache_dirty;
    v1265[v1422] = 0;
    int * v1267 = v1171->cache_age;
    v1267[v1422] = 1;
    int * v1269 = v1171->cache_age;
    int v1270 = v1269[v1422];
    int v1271 = v1269[v1351];
    int v1429 = v1271 + ((int)((unsigned int)(v1271 - v1270) >> 31));
    v1269[v1351] = v1429;
    int * v1273 = v1171->cache_age;
    int v1274 = v1273[v1352];
    int v1431 = v1274 + ((int)((unsigned int)(v1274 - v1270) >> 31));
    v1273[v1352] = v1431;
    int * v1276 = v1171->cache_age;
    v1276[v1422] = 0;
    v1279 = v1422;
  }
  int * v1280 = v1171->cache_vals;
  int v1434 = (v1279 * 2) + (((int)((unsigned int)(v1177 + 68) >> 2)) & 1);
  v1280[v1434] = v1179;
  int * v1282 = v1171->cache_tags;
  int v1283 = v1282[v1353];
  int v1284 = v1282[v1354];
  bool v1437 = !(((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1338;
  if (v1437) {
    int * v1285 = v1171->cache_age;
    int v1439 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1286 = v1285[v1439];
    int v1287 = v1285[v1353];
    int v1440 = v1287 + ((int)((unsigned int)(v1287 - v1286) >> 31));
    v1285[v1353] = v1440;
    int * v1289 = v1171->cache_age;
    int v1290 = v1289[v1354];
    int v1442 = v1290 + ((int)((unsigned int)(v1290 - v1286) >> 31));
    v1289[v1354] = v1442;
    int * v1292 = v1171->cache_age;
    v1292[v1439] = 0;
    v1338 = v1439;
  } else {
    int * v1295 = v1171->cache_age;
    int v1446 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1296 = v1295[v1446];
    int * v1297 = v1171->cache_tags;
    int v1298 = v1297[v1446];
    int v1299 = v1295[v1354];
    int v1300 = v1297[v1354];
    int * v1301 = v1171->cache_dirty;
    int v1449 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1302 = v1301[v1449];
    bool v1450 = !(v1302 == 0);
    if (v1450) {
      int * v1303 = v1171->cache_tags;
      int v1304 = v1303[v1449];
      int * v1305 = v1171->cache_vals;
      int v1453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1306 = v1305[v1453];
      int v1454 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1307 = v1305[v1454];
      int * v1308 = v1171->mem;
      int v1456 = v1304 * 2;
      v1308[v1456] = v1306;
      int * v1310 = v1171->mem;
      int v1459 = (v1304 * 2) + 1;
      v1310[v1459] = v1307;
      ;
    } else {
      ;
    }
    int * v1315 = v1171->mem;
    int v1464 = ((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2;
    int v1316 = v1315[v1464];
    int v1465 = (((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1317 = v1315[v1465];
    int * v1318 = v1171->cache_vals;
    int v1467 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1318[v1467] = v1316;
    int * v1320 = v1171->cache_vals;
    int v1470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1320[v1470] = v1317;
    int * v1322 = v1171->cache_tags;
    int v1473 = (int)((unsigned int)((int)((unsigned int)(v1177 + 68) >> 2)) >> 1);
    v1322[v1449] = v1473;
    int * v1324 = v1171->cache_dirty;
    v1324[v1449] = 0;
    int * v1326 = v1171->cache_age;
    v1326[v1449] = 1;
    int * v1328 = v1171->cache_age;
    int v1329 = v1328[v1449];
    int v1330 = v1328[v1353];
    int v1479 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
    v1328[v1353] = v1479;
    int * v1332 = v1171->cache_age;
    int v1333 = v1332[v1354];
    int v1481 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
    v1332[v1354] = v1481;
    int * v1335 = v1171->cache_age;
    v1335[v1449] = 0;
    v1338 = v1449;
  }
  int * v1339 = v1171->cache_vals;
  int v1484 = (v1338 * 2) + (((int)((unsigned int)(v1177 + 68) >> 2)) & 1);
  v1339[v1484] = v1179;
  int * v1341 = v1171->cache_dirty;
  v1341[v1338] = 1;
  struct StateT * v1343 = slot_22(v1171);
  return v1343;
}

struct StateT * slot_3(struct StateT * v492) {
  int v493 = v492->timer;
  int v507 = v493 + 1;
  v492->timer = v507;
  int * v495 = v492->reg_ready;
  int * v497 = v492->regs;
  int v498 = v497[10];
  int v500 = v497[11];
  bool v512 = (v498 ^ -2147483648) >= (v500 ^ -2147483648);
  struct StateT * v505;
  if (v512) {
    struct StateT * v501 = slot_22(v492);
    v505 = v501;
  } else {
    struct StateT * v503 = slot_4(v492);
    v505 = v503;
  }
  return v505;
}

struct StateT * slot_10(struct StateT * v57) {
  int v58 = v57->timer;
  int v69 = v58 + 1;
  v57->timer = v69;
  int * v60 = v57->reg_ready;
  int v61 = v60[10];
  int * v62 = v57->regs;
  int v63 = v62[10];
  int v73 = (v61 + ((v58 - v61) & (~((v58 - v61) >> 31)))) + 1;
  v60[10] = v73;
  int * v65 = v57->regs;
  int v75 = v63 + 72;
  v65[10] = v75;
  struct StateT * v67 = slot_11(v57);
  return v67;
}

struct StateT * slot_1(struct StateT * v41) {
  int v42 = v41->timer;
  int v50 = v42 + 1;
  v41->timer = v50;
  int * v44 = v41->reg_ready;
  v44[11] = v50;
  int * v46 = v41->regs;
  v46[11] = 0;
  struct StateT * v48 = slot_2(v41);
  return v48;
}

struct StateT * slot_19(struct StateT * v939) {
  int v940 = v939->timer;
  int v1052 = v940 + 1;
  v939->timer = v1052;
  int * v942 = v939->reg_ready;
  int v943 = v942[12];
  int * v944 = v939->regs;
  int v945 = v944[12];
  int * v946 = v939->cache_tags;
  int v1057 = (((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2;
  int v947 = v946[v1057];
  int v1058 = ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v948 = v946[v1058];
  int v1059 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2);
  int v949 = v946[v1059];
  int v1060 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v950 = v946[v1060];
  int * v951 = v939->cache_vals;
  bool v1061 = !(((~(((v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1044;
  if (v1061) {
    int * v952 = v939->cache_age;
    int v1063 = ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v953 = v952[v1063];
    int v954 = v952[v1057];
    int v1064 = v954 + ((int)((unsigned int)(v954 - v953) >> 31));
    v952[v1057] = v1064;
    int * v956 = v939->cache_age;
    int v957 = v956[v1058];
    int v1066 = v957 + ((int)((unsigned int)(v957 - v953) >> 31));
    v956[v1058] = v1066;
    int * v959 = v939->cache_age;
    v959[v1063] = 0;
    v1044 = v1063;
  } else {
    int * v962 = v939->cache_age;
    int v1070 = (((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2;
    int v963 = v962[v1070];
    int * v964 = v939->cache_tags;
    int v965 = v964[v1070];
    int v966 = v962[v1058];
    int v967 = v964[v1058];
    bool v1072 = !(((~(((v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1021;
    if (v1072) {
      int * v968 = v939->cache_age;
      int v1074 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v969 = v968[v1074];
      int v970 = v968[v1059];
      int v1075 = v970 + ((int)((unsigned int)(v970 - v969) >> 31));
      v968[v1059] = v1075;
      int * v972 = v939->cache_age;
      int v973 = v972[v1060];
      int v1077 = v973 + ((int)((unsigned int)(v973 - v969) >> 31));
      v972[v1060] = v1077;
      int * v975 = v939->cache_age;
      v975[v1074] = 0;
      v1021 = v1074;
    } else {
      int * v978 = v939->cache_age;
      int v1081 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2);
      int v979 = v978[v1081];
      int * v980 = v939->cache_tags;
      int v981 = v980[v1081];
      int v982 = v978[v1060];
      int v983 = v980[v1060];
      int * v984 = v939->cache_dirty;
      int v1084 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v985 = v984[v1084];
      bool v1085 = !(v985 == 0);
      if (v1085) {
        int * v986 = v939->cache_tags;
        int v987 = v986[v1084];
        int * v988 = v939->cache_vals;
        int v1088 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v989 = v988[v1088];
        int v1089 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v990 = v988[v1089];
        int * v991 = v939->mem;
        int v1091 = v987 * 2;
        v991[v1091] = v989;
        int * v993 = v939->mem;
        int v1094 = (v987 * 2) + 1;
        v993[v1094] = v990;
        ;
      } else {
        ;
      }
      int * v998 = v939->mem;
      int v1099 = ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) * 2;
      int v999 = v998[v1099];
      int v1100 = (((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1000 = v998[v1100];
      int * v1001 = v939->cache_vals;
      int v1102 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1001[v1102] = v999;
      int * v1003 = v939->cache_vals;
      int v1105 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1003[v1105] = v1000;
      int * v1005 = v939->cache_tags;
      int v1108 = (int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1);
      v1005[v1084] = v1108;
      int * v1007 = v939->cache_dirty;
      v1007[v1084] = 0;
      int * v1009 = v939->cache_age;
      v1009[v1084] = 1;
      int * v1011 = v939->cache_age;
      int v1012 = v1011[v1084];
      int v1013 = v1011[v1059];
      int v1114 = v1013 + ((int)((unsigned int)(v1013 - v1012) >> 31));
      v1011[v1059] = v1114;
      int * v1015 = v939->cache_age;
      int v1016 = v1015[v1060];
      int v1116 = v1016 + ((int)((unsigned int)(v1016 - v1012) >> 31));
      v1015[v1060] = v1116;
      int * v1018 = v939->cache_age;
      v1018[v1084] = 0;
      v1021 = v1084;
    }
    int * v1022 = v939->cache_vals;
    int v1119 = v1021 * 2;
    int v1023 = v1022[v1119];
    int v1120 = (v1021 * 2) + 1;
    int v1024 = v1022[v1120];
    int v1121 = (((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v967 ^ -1) | (-(v967 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1022[v1121] = v1023;
    int * v1026 = v939->cache_vals;
    int v1124 = ((((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v967 ^ -1) | (-(v967 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1026[v1124] = v1024;
    int * v1028 = v939->cache_tags;
    int v1127 = ((((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v963 + ((~(((v965 ^ -1) | (-(v965 ^ -1))) >> 31)) & 2)) - (v966 + ((~(((v967 ^ -1) | (-(v967 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1128 = (int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1);
    v1028[v1127] = v1128;
    int * v1030 = v939->cache_dirty;
    v1030[v1127] = 0;
    int * v1032 = v939->cache_age;
    v1032[v1127] = 1;
    int * v1034 = v939->cache_age;
    int v1035 = v1034[v1127];
    int v1036 = v1034[v1057];
    int v1134 = v1036 + ((int)((unsigned int)(v1036 - v1035) >> 31));
    v1034[v1057] = v1134;
    int * v1038 = v939->cache_age;
    int v1039 = v1038[v1058];
    int v1136 = v1039 + ((int)((unsigned int)(v1039 - v1035) >> 31));
    v1038[v1058] = v1136;
    int * v1041 = v939->cache_age;
    v1041[v1127] = 0;
    v1044 = v1127;
  }
  int v1139 = (v1044 * 2) + (((int)((unsigned int)(v945 + 68) >> 2)) & 1);
  int v1045 = v951[v1139];
  int * v1046 = v939->reg_ready;
  int v1142 = ((v943 + ((v940 - v943) & (~((v940 - v943) >> 31)))) + 1) + ((100 ^ (((~(((v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v947 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v948 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v949 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))) | (-(v950 ^ ((int)((unsigned int)((int)((unsigned int)(v945 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1046[11] = v1142;
  int * v1048 = v939->regs;
  v1048[11] = v1045;
  struct StateT * v1050 = slot_20(v939);
  return v1050;
}

struct StateT * slot_13(struct StateT * v560) {
  int v561 = v560->timer;
  int v572 = v561 + 1;
  v560->timer = v572;
  int * v563 = v560->reg_ready;
  int v564 = v563[11];
  int * v565 = v560->regs;
  int v566 = v565[11];
  int v576 = (v564 + ((v561 - v564) & (~((v561 - v564) >> 31)))) + 1;
  v563[11] = v576;
  int * v568 = v560->regs;
  int v578 = v566 + 4;
  v568[11] = v578;
  struct StateT * v570 = slot_14(v560);
  return v570;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v15 = v3 + 1;
  v2->timer = v15;
  int * v5 = v2->reg_ready;
  int * v7 = v2->regs;
  int v8 = v7[10];
  bool v19 = v8 == 0;
  struct StateT * v13;
  if (v19) {
    struct StateT * v9 = slot_9(v2);
    v13 = v9;
  } else {
    struct StateT * v11 = slot_1(v2);
    v13 = v11;
  }
  return v13;
}

struct StateT * slot_14(struct StateT * v597) {
  int v598 = v597->timer;
  int v606 = v598 + 1;
  v597->timer = v606;
  int * v600 = v597->reg_ready;
  v600[12] = v606;
  int * v602 = v597->regs;
  v602[12] = 0;
  struct StateT * v604 = slot_15(v597);
  return v604;
}

struct StateT * slot_17(struct StateT * v708) {
  int v709 = v708->timer;
  int v722 = v709 + 1;
  v708->timer = v722;
  int * v711 = v708->reg_ready;
  int v712 = v711[11];
  int * v713 = v708->regs;
  int v714 = v713[11];
  int v715 = v711[10];
  int v716 = v713[10];
  int v727 = (v715 + (((v712 + ((v709 - v712) & (~((v709 - v712) >> 31)))) - v715) & (~(((v712 + ((v709 - v712) & (~((v709 - v712) >> 31)))) - v715) >> 31)))) + 1;
  v711[10] = v727;
  int * v718 = v708->regs;
  int v729 = v714 + v716;
  v718[10] = v729;
  struct StateT * v720 = slot_18(v708);
  return v720;
}

struct StateT * slot_20(struct StateT * v1147) {
  int v1148 = v1147->timer;
  int v1161 = v1148 + 1;
  v1147->timer = v1161;
  int * v1150 = v1147->reg_ready;
  int v1151 = v1150[11];
  int * v1152 = v1147->regs;
  int v1153 = v1152[11];
  int v1154 = v1150[10];
  int v1155 = v1152[10];
  int v1166 = (v1154 + (((v1151 + ((v1148 - v1151) & (~((v1148 - v1151) >> 31)))) - v1154) & (~(((v1151 + ((v1148 - v1151) & (~((v1148 - v1151) >> 31)))) - v1154) >> 31)))) + 1;
  v1150[10] = v1166;
  int * v1157 = v1147->regs;
  int v1168 = v1153 & v1155;
  v1157[10] = v1168;
  struct StateT * v1159 = slot_21(v1147);
  return v1159;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1490 = v1->timer;
  int * v1491 = v1->reg_ready;
  int v1492 = v1491[0];
  int v1623 = v1492 + ((v1490 - v1492) & (~((v1490 - v1492) >> 31)));
  v1->timer = v1623;
  int v1494 = v1->timer;
  int * v1495 = v1->reg_ready;
  int v1496 = v1495[1];
  int v1626 = v1496 + ((v1494 - v1496) & (~((v1494 - v1496) >> 31)));
  v1->timer = v1626;
  int v1498 = v1->timer;
  int * v1499 = v1->reg_ready;
  int v1500 = v1499[2];
  int v1629 = v1500 + ((v1498 - v1500) & (~((v1498 - v1500) >> 31)));
  v1->timer = v1629;
  int v1502 = v1->timer;
  int * v1503 = v1->reg_ready;
  int v1504 = v1503[3];
  int v1632 = v1504 + ((v1502 - v1504) & (~((v1502 - v1504) >> 31)));
  v1->timer = v1632;
  int v1506 = v1->timer;
  int * v1507 = v1->reg_ready;
  int v1508 = v1507[4];
  int v1635 = v1508 + ((v1506 - v1508) & (~((v1506 - v1508) >> 31)));
  v1->timer = v1635;
  int v1510 = v1->timer;
  int * v1511 = v1->reg_ready;
  int v1512 = v1511[5];
  int v1638 = v1512 + ((v1510 - v1512) & (~((v1510 - v1512) >> 31)));
  v1->timer = v1638;
  int v1514 = v1->timer;
  int * v1515 = v1->reg_ready;
  int v1516 = v1515[6];
  int v1641 = v1516 + ((v1514 - v1516) & (~((v1514 - v1516) >> 31)));
  v1->timer = v1641;
  int v1518 = v1->timer;
  int * v1519 = v1->reg_ready;
  int v1520 = v1519[7];
  int v1644 = v1520 + ((v1518 - v1520) & (~((v1518 - v1520) >> 31)));
  v1->timer = v1644;
  int v1522 = v1->timer;
  int * v1523 = v1->reg_ready;
  int v1524 = v1523[8];
  int v1647 = v1524 + ((v1522 - v1524) & (~((v1522 - v1524) >> 31)));
  v1->timer = v1647;
  int v1526 = v1->timer;
  int * v1527 = v1->reg_ready;
  int v1528 = v1527[9];
  int v1650 = v1528 + ((v1526 - v1528) & (~((v1526 - v1528) >> 31)));
  v1->timer = v1650;
  int v1530 = v1->timer;
  int * v1531 = v1->reg_ready;
  int v1532 = v1531[10];
  int v1653 = v1532 + ((v1530 - v1532) & (~((v1530 - v1532) >> 31)));
  v1->timer = v1653;
  int v1534 = v1->timer;
  int * v1535 = v1->reg_ready;
  int v1536 = v1535[11];
  int v1656 = v1536 + ((v1534 - v1536) & (~((v1534 - v1536) >> 31)));
  v1->timer = v1656;
  int v1538 = v1->timer;
  int * v1539 = v1->reg_ready;
  int v1540 = v1539[12];
  int v1659 = v1540 + ((v1538 - v1540) & (~((v1538 - v1540) >> 31)));
  v1->timer = v1659;
  int v1542 = v1->timer;
  int * v1543 = v1->reg_ready;
  int v1544 = v1543[13];
  int v1662 = v1544 + ((v1542 - v1544) & (~((v1542 - v1544) >> 31)));
  v1->timer = v1662;
  int v1546 = v1->timer;
  int * v1547 = v1->reg_ready;
  int v1548 = v1547[14];
  int v1665 = v1548 + ((v1546 - v1548) & (~((v1546 - v1548) >> 31)));
  v1->timer = v1665;
  int v1550 = v1->timer;
  int * v1551 = v1->reg_ready;
  int v1552 = v1551[15];
  int v1668 = v1552 + ((v1550 - v1552) & (~((v1550 - v1552) >> 31)));
  v1->timer = v1668;
  int v1554 = v1->timer;
  int * v1555 = v1->reg_ready;
  int v1556 = v1555[16];
  int v1671 = v1556 + ((v1554 - v1556) & (~((v1554 - v1556) >> 31)));
  v1->timer = v1671;
  int v1558 = v1->timer;
  int * v1559 = v1->reg_ready;
  int v1560 = v1559[17];
  int v1674 = v1560 + ((v1558 - v1560) & (~((v1558 - v1560) >> 31)));
  v1->timer = v1674;
  int v1562 = v1->timer;
  int * v1563 = v1->reg_ready;
  int v1564 = v1563[18];
  int v1677 = v1564 + ((v1562 - v1564) & (~((v1562 - v1564) >> 31)));
  v1->timer = v1677;
  int v1566 = v1->timer;
  int * v1567 = v1->reg_ready;
  int v1568 = v1567[19];
  int v1680 = v1568 + ((v1566 - v1568) & (~((v1566 - v1568) >> 31)));
  v1->timer = v1680;
  int v1570 = v1->timer;
  int * v1571 = v1->reg_ready;
  int v1572 = v1571[20];
  int v1683 = v1572 + ((v1570 - v1572) & (~((v1570 - v1572) >> 31)));
  v1->timer = v1683;
  int v1574 = v1->timer;
  int * v1575 = v1->reg_ready;
  int v1576 = v1575[21];
  int v1686 = v1576 + ((v1574 - v1576) & (~((v1574 - v1576) >> 31)));
  v1->timer = v1686;
  int v1578 = v1->timer;
  int * v1579 = v1->reg_ready;
  int v1580 = v1579[22];
  int v1689 = v1580 + ((v1578 - v1580) & (~((v1578 - v1580) >> 31)));
  v1->timer = v1689;
  int v1582 = v1->timer;
  int * v1583 = v1->reg_ready;
  int v1584 = v1583[23];
  int v1692 = v1584 + ((v1582 - v1584) & (~((v1582 - v1584) >> 31)));
  v1->timer = v1692;
  int v1586 = v1->timer;
  int * v1587 = v1->reg_ready;
  int v1588 = v1587[24];
  int v1695 = v1588 + ((v1586 - v1588) & (~((v1586 - v1588) >> 31)));
  v1->timer = v1695;
  int v1590 = v1->timer;
  int * v1591 = v1->reg_ready;
  int v1592 = v1591[25];
  int v1698 = v1592 + ((v1590 - v1592) & (~((v1590 - v1592) >> 31)));
  v1->timer = v1698;
  int v1594 = v1->timer;
  int * v1595 = v1->reg_ready;
  int v1596 = v1595[26];
  int v1701 = v1596 + ((v1594 - v1596) & (~((v1594 - v1596) >> 31)));
  v1->timer = v1701;
  int v1598 = v1->timer;
  int * v1599 = v1->reg_ready;
  int v1600 = v1599[27];
  int v1704 = v1600 + ((v1598 - v1600) & (~((v1598 - v1600) >> 31)));
  v1->timer = v1704;
  int v1602 = v1->timer;
  int * v1603 = v1->reg_ready;
  int v1604 = v1603[28];
  int v1707 = v1604 + ((v1602 - v1604) & (~((v1602 - v1604) >> 31)));
  v1->timer = v1707;
  int v1606 = v1->timer;
  int * v1607 = v1->reg_ready;
  int v1608 = v1607[29];
  int v1710 = v1608 + ((v1606 - v1608) & (~((v1606 - v1608) >> 31)));
  v1->timer = v1710;
  int v1610 = v1->timer;
  int * v1611 = v1->reg_ready;
  int v1612 = v1611[30];
  int v1713 = v1612 + ((v1610 - v1612) & (~((v1610 - v1612) >> 31)));
  v1->timer = v1713;
  int v1614 = v1->timer;
  int * v1615 = v1->reg_ready;
  int v1616 = v1615[31];
  int v1716 = v1616 + ((v1614 - v1616) & (~((v1614 - v1616) >> 31)));
  v1->timer = v1716;
  return v1;
}

struct StateT * slot_8(struct StateT * v700) {
  int v701 = v700->timer;
  int v705 = v701 + 1;
  v700->timer = v705;
  struct StateT * v703 = slot_11(v700);
  return v703;
}

struct StateT * slot_4(struct StateT * v539) {
  int v540 = v539->timer;
  int v551 = v540 + 1;
  v539->timer = v551;
  int * v542 = v539->reg_ready;
  int v543 = v542[10];
  int * v544 = v539->regs;
  int v545 = v544[10];
  int v555 = (v543 + ((v540 - v543) & (~((v540 - v543) >> 31)))) + 1;
  v542[10] = v555;
  int * v547 = v539->regs;
  int v557 = v545 << 2;
  v547[10] = v557;
  struct StateT * v549 = slot_5(v539);
  return v549;
}

struct StateT * slot_15(struct StateT * v634) {
  int v635 = v634->timer;
  int v646 = v635 + 1;
  v634->timer = v646;
  int * v637 = v634->reg_ready;
  int v638 = v637[10];
  int * v639 = v634->regs;
  int v640 = v639[10];
  int v650 = (v638 + ((v635 - v638) & (~((v635 - v638) >> 31)))) + 1;
  v637[10] = v650;
  int * v642 = v634->regs;
  int v652 = v640 << 29;
  v642[10] = v652;
  struct StateT * v644 = slot_16(v634);
  return v644;
}

struct StateT * slot_18(struct StateT * v732) {
  int v733 = v732->timer;
  int v845 = v733 + 1;
  v732->timer = v845;
  int * v735 = v732->reg_ready;
  int v736 = v735[10];
  int * v737 = v732->regs;
  int v738 = v737[10];
  int * v739 = v732->cache_tags;
  int v850 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2;
  int v740 = v739[v850];
  int v851 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + 1;
  int v741 = v739[v851];
  int v852 = 4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2);
  int v742 = v739[v852];
  int v853 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v743 = v739[v853];
  int * v744 = v732->cache_vals;
  bool v854 = !(((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) == 0);
  int v837;
  if (v854) {
    int * v745 = v732->cache_age;
    int v856 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) & 1);
    int v746 = v745[v856];
    int v747 = v745[v850];
    int v857 = v747 + ((int)((unsigned int)(v747 - v746) >> 31));
    v745[v850] = v857;
    int * v749 = v732->cache_age;
    int v750 = v749[v851];
    int v859 = v750 + ((int)((unsigned int)(v750 - v746) >> 31));
    v749[v851] = v859;
    int * v752 = v732->cache_age;
    v752[v856] = 0;
    v837 = v856;
  } else {
    int * v755 = v732->cache_age;
    int v863 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2;
    int v756 = v755[v863];
    int * v757 = v732->cache_tags;
    int v758 = v757[v863];
    int v759 = v755[v851];
    int v760 = v757[v851];
    bool v865 = !(((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) == 0);
    int v814;
    if (v865) {
      int * v761 = v732->cache_age;
      int v867 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) & 1);
      int v762 = v761[v867];
      int v763 = v761[v852];
      int v868 = v763 + ((int)((unsigned int)(v763 - v762) >> 31));
      v761[v852] = v868;
      int * v765 = v732->cache_age;
      int v766 = v765[v853];
      int v870 = v766 + ((int)((unsigned int)(v766 - v762) >> 31));
      v765[v853] = v870;
      int * v768 = v732->cache_age;
      v768[v867] = 0;
      v814 = v867;
    } else {
      int * v771 = v732->cache_age;
      int v874 = 4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2);
      int v772 = v771[v874];
      int * v773 = v732->cache_tags;
      int v774 = v773[v874];
      int v775 = v771[v853];
      int v776 = v773[v853];
      int * v777 = v732->cache_dirty;
      int v877 = (4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v778 = v777[v877];
      bool v878 = !(v778 == 0);
      if (v878) {
        int * v779 = v732->cache_tags;
        int v780 = v779[v877];
        int * v781 = v732->cache_vals;
        int v881 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v782 = v781[v881];
        int v882 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v783 = v781[v882];
        int * v784 = v732->mem;
        int v884 = v780 * 2;
        v784[v884] = v782;
        int * v786 = v732->mem;
        int v887 = (v780 * 2) + 1;
        v786[v887] = v783;
        ;
      } else {
        ;
      }
      int * v791 = v732->mem;
      int v892 = ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) * 2;
      int v792 = v791[v892];
      int v893 = (((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) * 2) + 1;
      int v793 = v791[v893];
      int * v794 = v732->cache_vals;
      int v895 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v794[v895] = v792;
      int * v796 = v732->cache_vals;
      int v898 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 3) * 2)) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v796[v898] = v793;
      int * v798 = v732->cache_tags;
      int v901 = (int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1);
      v798[v877] = v901;
      int * v800 = v732->cache_dirty;
      v800[v877] = 0;
      int * v802 = v732->cache_age;
      v802[v877] = 1;
      int * v804 = v732->cache_age;
      int v805 = v804[v877];
      int v806 = v804[v852];
      int v907 = v806 + ((int)((unsigned int)(v806 - v805) >> 31));
      v804[v852] = v907;
      int * v808 = v732->cache_age;
      int v809 = v808[v853];
      int v909 = v809 + ((int)((unsigned int)(v809 - v805) >> 31));
      v808[v853] = v909;
      int * v811 = v732->cache_age;
      v811[v877] = 0;
      v814 = v877;
    }
    int * v815 = v732->cache_vals;
    int v912 = v814 * 2;
    int v816 = v815[v912];
    int v913 = (v814 * 2) + 1;
    int v817 = v815[v913];
    int v914 = (((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v815[v914] = v816;
    int * v819 = v732->cache_vals;
    int v917 = ((((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v819[v917] = v817;
    int * v821 = v732->cache_tags;
    int v920 = ((((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1)) & 1) * 2) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v921 = (int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1);
    v821[v920] = v921;
    int * v823 = v732->cache_dirty;
    v823[v920] = 0;
    int * v825 = v732->cache_age;
    v825[v920] = 1;
    int * v827 = v732->cache_age;
    int v828 = v827[v920];
    int v829 = v827[v850];
    int v927 = v829 + ((int)((unsigned int)(v829 - v828) >> 31));
    v827[v850] = v927;
    int * v831 = v732->cache_age;
    int v832 = v831[v851];
    int v929 = v832 + ((int)((unsigned int)(v832 - v828) >> 31));
    v831[v851] = v929;
    int * v834 = v732->cache_age;
    v834[v920] = 0;
    v837 = v920;
  }
  int v932 = (v837 * 2) + (((int)((unsigned int)v738 >> 2)) & 1);
  int v838 = v744[v932];
  int * v839 = v732->reg_ready;
  int v934 = ((v736 + ((v733 - v736) & (~((v733 - v736) >> 31)))) + 1) + ((100 ^ (((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31)) | (~(((v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))) | (-(v743 ^ ((int)((unsigned int)((int)((unsigned int)v738 >> 2)) >> 1))))) >> 31))) & 104)))));
  v839[10] = v934;
  int * v841 = v732->regs;
  v841[10] = v838;
  struct StateT * v843 = slot_19(v732);
  return v843;
}

struct StateT * slot_9(struct StateT * v25) {
  int v26 = v25->timer;
  int v34 = v26 + 1;
  v25->timer = v34;
  int * v28 = v25->reg_ready;
  v28[10] = v34;
  int * v30 = v25->regs;
  v30[10] = 0;
  struct StateT * v32 = slot_10(v25);
  return v32;
}

struct StateT * slot_22(struct StateT * v534) {
  int v535 = v534->timer;
  int v538 = v535 + 1;
  v534->timer = v538;
  return v534;
}

struct StateT * slot_11(struct StateT * v285) {
  int v286 = v285->timer;
  int v398 = v286 + 1;
  v285->timer = v398;
  int * v288 = v285->reg_ready;
  int v289 = v288[10];
  int * v290 = v285->regs;
  int v291 = v290[10];
  int * v292 = v285->cache_tags;
  int v403 = (((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2;
  int v293 = v292[v403];
  int v404 = ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2) + 1;
  int v294 = v292[v404];
  int v405 = 4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2);
  int v295 = v292[v405];
  int v406 = (4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v296 = v292[v406];
  int * v297 = v285->cache_vals;
  bool v407 = !(((~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) | (~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31))) == 0);
  int v390;
  if (v407) {
    int * v298 = v285->cache_age;
    int v409 = ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2) + ((~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) & 1);
    int v299 = v298[v409];
    int v300 = v298[v403];
    int v410 = v300 + ((int)((unsigned int)(v300 - v299) >> 31));
    v298[v403] = v410;
    int * v302 = v285->cache_age;
    int v303 = v302[v404];
    int v412 = v303 + ((int)((unsigned int)(v303 - v299) >> 31));
    v302[v404] = v412;
    int * v305 = v285->cache_age;
    v305[v409] = 0;
    v390 = v409;
  } else {
    int * v308 = v285->cache_age;
    int v416 = (((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2;
    int v309 = v308[v416];
    int * v310 = v285->cache_tags;
    int v311 = v310[v416];
    int v312 = v308[v404];
    int v313 = v310[v404];
    bool v418 = !(((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) | (~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31))) == 0);
    int v367;
    if (v418) {
      int * v314 = v285->cache_age;
      int v420 = (4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + ((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) & 1);
      int v315 = v314[v420];
      int v316 = v314[v405];
      int v421 = v316 + ((int)((unsigned int)(v316 - v315) >> 31));
      v314[v405] = v421;
      int * v318 = v285->cache_age;
      int v319 = v318[v406];
      int v423 = v319 + ((int)((unsigned int)(v319 - v315) >> 31));
      v318[v406] = v423;
      int * v321 = v285->cache_age;
      v321[v420] = 0;
      v367 = v420;
    } else {
      int * v324 = v285->cache_age;
      int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2);
      int v325 = v324[v427];
      int * v326 = v285->cache_tags;
      int v327 = v326[v427];
      int v328 = v324[v406];
      int v329 = v326[v406];
      int * v330 = v285->cache_dirty;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v331 = v330[v430];
      bool v431 = !(v331 == 0);
      if (v431) {
        int * v332 = v285->cache_tags;
        int v333 = v332[v430];
        int * v334 = v285->cache_vals;
        int v434 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v335 = v334[v434];
        int v435 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v336 = v334[v435];
        int * v337 = v285->mem;
        int v437 = v333 * 2;
        v337[v437] = v335;
        int * v339 = v285->mem;
        int v440 = (v333 * 2) + 1;
        v339[v440] = v336;
        ;
      } else {
        ;
      }
      int * v344 = v285->mem;
      int v445 = ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) * 2;
      int v345 = v344[v445];
      int v446 = (((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) * 2) + 1;
      int v346 = v344[v446];
      int * v347 = v285->cache_vals;
      int v448 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v347[v448] = v345;
      int * v349 = v285->cache_vals;
      int v451 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 3) * 2)) + ((((v325 + ((~(((v327 ^ -1) | (-(v327 ^ -1))) >> 31)) & 2)) - (v328 + ((~(((v329 ^ -1) | (-(v329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v349[v451] = v346;
      int * v351 = v285->cache_tags;
      int v454 = (int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1);
      v351[v430] = v454;
      int * v353 = v285->cache_dirty;
      v353[v430] = 0;
      int * v355 = v285->cache_age;
      v355[v430] = 1;
      int * v357 = v285->cache_age;
      int v358 = v357[v430];
      int v359 = v357[v405];
      int v460 = v359 + ((int)((unsigned int)(v359 - v358) >> 31));
      v357[v405] = v460;
      int * v361 = v285->cache_age;
      int v362 = v361[v406];
      int v462 = v362 + ((int)((unsigned int)(v362 - v358) >> 31));
      v361[v406] = v462;
      int * v364 = v285->cache_age;
      v364[v430] = 0;
      v367 = v430;
    }
    int * v368 = v285->cache_vals;
    int v465 = v367 * 2;
    int v369 = v368[v465];
    int v466 = (v367 * 2) + 1;
    int v370 = v368[v466];
    int v467 = (((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v368[v467] = v369;
    int * v372 = v285->cache_vals;
    int v470 = ((((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v372[v470] = v370;
    int * v374 = v285->cache_tags;
    int v473 = ((((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1)) & 1) * 2) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v474 = (int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1);
    v374[v473] = v474;
    int * v376 = v285->cache_dirty;
    v376[v473] = 0;
    int * v378 = v285->cache_age;
    v378[v473] = 1;
    int * v380 = v285->cache_age;
    int v381 = v380[v473];
    int v382 = v380[v403];
    int v480 = v382 + ((int)((unsigned int)(v382 - v381) >> 31));
    v380[v403] = v480;
    int * v384 = v285->cache_age;
    int v385 = v384[v404];
    int v482 = v385 + ((int)((unsigned int)(v385 - v381) >> 31));
    v384[v404] = v482;
    int * v387 = v285->cache_age;
    v387[v473] = 0;
    v390 = v473;
  }
  int v485 = (v390 * 2) + (((int)((unsigned int)v291 >> 2)) & 1);
  int v391 = v297[v485];
  int * v392 = v285->reg_ready;
  int v487 = ((v289 + ((v286 - v289) & (~((v286 - v289) >> 31)))) + 1) + ((100 ^ (((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) | (~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v293 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v293 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) | (~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31)) | (~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v291 >> 2)) >> 1))))) >> 31))) & 104)))));
  v392[10] = v487;
  int * v394 = v285->regs;
  v394[10] = v391;
  struct StateT * v396 = slot_12(v285);
  return v396;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}