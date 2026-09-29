// verify: clean (Eva should report untainted: Valid) [unroll 65]
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

struct StateT * slot_12(struct StateT * v592);
struct StateT * slot_6(struct StateT * v75);
struct StateT * slot_16(struct StateT * v696);
struct StateT * slot_23(struct StateT * v1206);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v99);
struct StateT * slot_21(struct StateT * v971);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_10(struct StateT * v545);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v662);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v682);
struct StateT * slot_20(struct StateT * v947);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_12(struct StateT * v592) {
  int * v593 = v592->regs;
  int v594 = v593[14];
  int v595 = v593[15];
  bool v631 = v594 >= v595;
  struct StateT * v626;
  if (v631) {
    int v596 = v592->timer;
    int v632 = v596 + 15;
    v592->timer = v632;
    int * v598 = v592->saved_regs;
    int v599 = v598[6];
    int * v600 = v592->regs;
    v600[6] = v599;
    int * v602 = v592->saved_regs;
    int v603 = v602[7];
    int * v604 = v592->regs;
    v604[7] = v603;
    int * v606 = v592->saved_regs;
    int v607 = v606[8];
    int * v608 = v592->regs;
    v608[8] = v607;
    int * v610 = v592->saved_regs;
    int v611 = v610[9];
    int * v612 = v592->regs;
    v612[9] = v611;
    int * v614 = v592->saved_regs;
    int v615 = v614[16];
    int * v616 = v592->regs;
    v616[16] = v615;
    int * v618 = v592->saved_regs;
    int v619 = v618[5];
    int * v620 = v592->regs;
    v620[5] = v619;
    struct StateT * v622 = slot_13(v592);
    v626 = v622;
  } else {
    struct StateT * v624 = slot_14(v592);
    v626 = v624;
  }
  return v626;
}

struct StateT * slot_6(struct StateT * v75) {
  int * v76 = v75->saved_regs;
  int * v77 = v75->regs;
  int v78 = v77[6];
  v76[6] = v78;
  int v80 = v75->timer;
  int v92 = v80 + 1;
  v75->timer = v92;
  int * v82 = v75->regs;
  int v83 = v82[12];
  int v84 = v82[14];
  int v96 = v83 + v84;
  v82[6] = v96;
  struct StateT * v86 = slot_7(v75);
  return v86;
}

struct StateT * slot_16(struct StateT * v696) {
  int v697 = v696->timer;
  int v701 = v697 + 1;
  v696->timer = v701;
  struct StateT * v699 = slot_5(v696);
  return v699;
}

struct StateT * slot_23(struct StateT * v1206) {
  int * v1207 = v1206->saved_regs;
  int * v1208 = v1206->regs;
  int v1209 = v1208[5];
  v1207[5] = v1209;
  int v1211 = v1206->timer;
  int v1223 = v1211 + 1;
  v1206->timer = v1223;
  int * v1213 = v1206->regs;
  int v1214 = v1213[5];
  int v1215 = v1213[16];
  int v1226 = v1214 | v1215;
  v1213[5] = v1226;
  struct StateT * v1217 = slot_12(v1206);
  return v1217;
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

struct StateT * slot_7(struct StateT * v99) {
  int * v100 = v99->saved_regs;
  int * v101 = v99->regs;
  int v102 = v101[7];
  v100[7] = v102;
  int v104 = v99->timer;
  int v218 = v104 + 1;
  v99->timer = v218;
  int * v106 = v99->regs;
  int v107 = v106[6];
  int * v108 = v99->cache_tags;
  int v222 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
  int v109 = v108[v222];
  int v223 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + 1;
  int v110 = v108[v223];
  int v224 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
  int v111 = v108[v224];
  int v225 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v112 = v108[v225];
  int v113 = v99->timer;
  int v226 = v113 + ((100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)))));
  v99->timer = v226;
  int * v115 = v99->cache_vals;
  bool v227 = !(((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
  int v208;
  if (v227) {
    int * v116 = v99->cache_age;
    int v229 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((~(((v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v110 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
    int v117 = v116[v229];
    int v118 = v116[v222];
    int v230 = v118 + ((int)((unsigned int)(v118 - v117) >> 31));
    v116[v222] = v230;
    int * v120 = v99->cache_age;
    int v121 = v120[v223];
    int v232 = v121 + ((int)((unsigned int)(v121 - v117) >> 31));
    v120[v223] = v232;
    int * v123 = v99->cache_age;
    v123[v229] = 0;
    v208 = v229;
  } else {
    int * v126 = v99->cache_age;
    int v236 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
    int v127 = v126[v236];
    int * v128 = v99->cache_tags;
    int v129 = v128[v236];
    int v130 = v126[v223];
    int v131 = v128[v223];
    bool v238 = !(((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
    int v185;
    if (v238) {
      int * v132 = v99->cache_age;
      int v240 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
      int v133 = v132[v240];
      int v134 = v132[v224];
      int v241 = v134 + ((int)((unsigned int)(v134 - v133) >> 31));
      v132[v224] = v241;
      int * v136 = v99->cache_age;
      int v137 = v136[v225];
      int v243 = v137 + ((int)((unsigned int)(v137 - v133) >> 31));
      v136[v225] = v243;
      int * v139 = v99->cache_age;
      v139[v240] = 0;
      v185 = v240;
    } else {
      int * v142 = v99->cache_age;
      int v247 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
      int v143 = v142[v247];
      int * v144 = v99->cache_tags;
      int v145 = v144[v247];
      int v146 = v142[v225];
      int v147 = v144[v225];
      int * v148 = v99->cache_dirty;
      int v250 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v149 = v148[v250];
      bool v251 = !(v149 == 0);
      if (v251) {
        int * v150 = v99->cache_tags;
        int v151 = v150[v250];
        int * v152 = v99->cache_vals;
        int v254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v153 = v152[v254];
        int v255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v154 = v152[v255];
        int * v155 = v99->mem;
        int v257 = v151 * 2;
        v155[v257] = v153;
        int * v157 = v99->mem;
        int v260 = (v151 * 2) + 1;
        v157[v260] = v154;
        ;
      } else {
        ;
      }
      int * v162 = v99->mem;
      int v265 = ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2;
      int v163 = v162[v265];
      int v266 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2) + 1;
      int v164 = v162[v266];
      int * v165 = v99->cache_vals;
      int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v165[v268] = v163;
      int * v167 = v99->cache_vals;
      int v271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2)) - (v146 + ((~(((v147 ^ -1) | (-(v147 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v167[v271] = v164;
      int * v169 = v99->cache_tags;
      int v274 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
      v169[v250] = v274;
      int * v171 = v99->cache_dirty;
      v171[v250] = 0;
      int * v173 = v99->cache_age;
      v173[v250] = 1;
      int * v175 = v99->cache_age;
      int v176 = v175[v250];
      int v177 = v175[v224];
      int v280 = v177 + ((int)((unsigned int)(v177 - v176) >> 31));
      v175[v224] = v280;
      int * v179 = v99->cache_age;
      int v180 = v179[v225];
      int v282 = v180 + ((int)((unsigned int)(v180 - v176) >> 31));
      v179[v225] = v282;
      int * v182 = v99->cache_age;
      v182[v250] = 0;
      v185 = v250;
    }
    int * v186 = v99->cache_vals;
    int v285 = v185 * 2;
    int v187 = v186[v285];
    int v286 = (v185 * 2) + 1;
    int v188 = v186[v286];
    int v287 = (((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186[v287] = v187;
    int * v190 = v99->cache_vals;
    int v290 = ((((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190[v290] = v188;
    int * v192 = v99->cache_tags;
    int v293 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v127 + ((~(((v129 ^ -1) | (-(v129 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v131 ^ -1) | (-(v131 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v294 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
    v192[v293] = v294;
    int * v194 = v99->cache_dirty;
    v194[v293] = 0;
    int * v196 = v99->cache_age;
    v196[v293] = 1;
    int * v198 = v99->cache_age;
    int v199 = v198[v293];
    int v200 = v198[v222];
    int v300 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
    v198[v222] = v300;
    int * v202 = v99->cache_age;
    int v203 = v202[v223];
    int v302 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
    v202[v223] = v302;
    int * v205 = v99->cache_age;
    v205[v293] = 0;
    v208 = v293;
  }
  int v305 = (v208 * 2) + (((int)((unsigned int)v107 >> 2)) & 1);
  int v209 = v115[v305];
  int * v210 = v99->regs;
  v210[7] = v209;
  struct StateT * v212 = slot_20(v99);
  return v212;
}

struct StateT * slot_21(struct StateT * v971) {
  int * v972 = v971->saved_regs;
  int * v973 = v971->regs;
  int v974 = v973[9];
  v972[9] = v974;
  int v976 = v971->timer;
  int v1090 = v976 + 1;
  v971->timer = v1090;
  int * v978 = v971->regs;
  int v979 = v978[8];
  int * v980 = v971->cache_tags;
  int v1094 = (((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2;
  int v981 = v980[v1094];
  int v1095 = ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2) + 1;
  int v982 = v980[v1095];
  int v1096 = 4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2);
  int v983 = v980[v1096];
  int v1097 = (4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v984 = v980[v1097];
  int v985 = v971->timer;
  int v1098 = v985 + ((100 ^ (((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v981 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v981 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) | (~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31))) & 104)))));
  v971->timer = v1098;
  int * v987 = v971->cache_vals;
  bool v1099 = !(((~(((v981 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v981 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) | (~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31))) == 0);
  int v1080;
  if (v1099) {
    int * v988 = v971->cache_age;
    int v1101 = ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2) + ((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) & 1);
    int v989 = v988[v1101];
    int v990 = v988[v1094];
    int v1102 = v990 + ((int)((unsigned int)(v990 - v989) >> 31));
    v988[v1094] = v1102;
    int * v992 = v971->cache_age;
    int v993 = v992[v1095];
    int v1104 = v993 + ((int)((unsigned int)(v993 - v989) >> 31));
    v992[v1095] = v1104;
    int * v995 = v971->cache_age;
    v995[v1101] = 0;
    v1080 = v1101;
  } else {
    int * v998 = v971->cache_age;
    int v1108 = (((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2;
    int v999 = v998[v1108];
    int * v1000 = v971->cache_tags;
    int v1001 = v1000[v1108];
    int v1002 = v998[v1095];
    int v1003 = v1000[v1095];
    bool v1110 = !(((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31))) == 0);
    int v1057;
    if (v1110) {
      int * v1004 = v971->cache_age;
      int v1112 = (4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + ((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1))))) >> 31)) & 1);
      int v1005 = v1004[v1112];
      int v1006 = v1004[v1096];
      int v1113 = v1006 + ((int)((unsigned int)(v1006 - v1005) >> 31));
      v1004[v1096] = v1113;
      int * v1008 = v971->cache_age;
      int v1009 = v1008[v1097];
      int v1115 = v1009 + ((int)((unsigned int)(v1009 - v1005) >> 31));
      v1008[v1097] = v1115;
      int * v1011 = v971->cache_age;
      v1011[v1112] = 0;
      v1057 = v1112;
    } else {
      int * v1014 = v971->cache_age;
      int v1119 = 4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2);
      int v1015 = v1014[v1119];
      int * v1016 = v971->cache_tags;
      int v1017 = v1016[v1119];
      int v1018 = v1014[v1097];
      int v1019 = v1016[v1097];
      int * v1020 = v971->cache_dirty;
      int v1122 = (4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1021 = v1020[v1122];
      bool v1123 = !(v1021 == 0);
      if (v1123) {
        int * v1022 = v971->cache_tags;
        int v1023 = v1022[v1122];
        int * v1024 = v971->cache_vals;
        int v1126 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1025 = v1024[v1126];
        int v1127 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1026 = v1024[v1127];
        int * v1027 = v971->mem;
        int v1129 = v1023 * 2;
        v1027[v1129] = v1025;
        int * v1029 = v971->mem;
        int v1132 = (v1023 * 2) + 1;
        v1029[v1132] = v1026;
        ;
      } else {
        ;
      }
      int * v1034 = v971->mem;
      int v1137 = ((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) * 2;
      int v1035 = v1034[v1137];
      int v1138 = (((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) * 2) + 1;
      int v1036 = v1034[v1138];
      int * v1037 = v971->cache_vals;
      int v1140 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1037[v1140] = v1035;
      int * v1039 = v971->cache_vals;
      int v1143 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 3) * 2)) + ((((v1015 + ((~(((v1017 ^ -1) | (-(v1017 ^ -1))) >> 31)) & 2)) - (v1018 + ((~(((v1019 ^ -1) | (-(v1019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1039[v1143] = v1036;
      int * v1041 = v971->cache_tags;
      int v1146 = (int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1);
      v1041[v1122] = v1146;
      int * v1043 = v971->cache_dirty;
      v1043[v1122] = 0;
      int * v1045 = v971->cache_age;
      v1045[v1122] = 1;
      int * v1047 = v971->cache_age;
      int v1048 = v1047[v1122];
      int v1049 = v1047[v1096];
      int v1152 = v1049 + ((int)((unsigned int)(v1049 - v1048) >> 31));
      v1047[v1096] = v1152;
      int * v1051 = v971->cache_age;
      int v1052 = v1051[v1097];
      int v1154 = v1052 + ((int)((unsigned int)(v1052 - v1048) >> 31));
      v1051[v1097] = v1154;
      int * v1054 = v971->cache_age;
      v1054[v1122] = 0;
      v1057 = v1122;
    }
    int * v1058 = v971->cache_vals;
    int v1157 = v1057 * 2;
    int v1059 = v1058[v1157];
    int v1158 = (v1057 * 2) + 1;
    int v1060 = v1058[v1158];
    int v1159 = (((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2) + ((((v999 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2)) - (v1002 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1058[v1159] = v1059;
    int * v1062 = v971->cache_vals;
    int v1162 = ((((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2) + ((((v999 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2)) - (v1002 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1062[v1162] = v1060;
    int * v1064 = v971->cache_tags;
    int v1165 = ((((int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1)) & 1) * 2) + ((((v999 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2)) - (v1002 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1166 = (int)((unsigned int)((int)((unsigned int)v979 >> 2)) >> 1);
    v1064[v1165] = v1166;
    int * v1066 = v971->cache_dirty;
    v1066[v1165] = 0;
    int * v1068 = v971->cache_age;
    v1068[v1165] = 1;
    int * v1070 = v971->cache_age;
    int v1071 = v1070[v1165];
    int v1072 = v1070[v1094];
    int v1172 = v1072 + ((int)((unsigned int)(v1072 - v1071) >> 31));
    v1070[v1094] = v1172;
    int * v1074 = v971->cache_age;
    int v1075 = v1074[v1095];
    int v1174 = v1075 + ((int)((unsigned int)(v1075 - v1071) >> 31));
    v1074[v1095] = v1174;
    int * v1077 = v971->cache_age;
    v1077[v1165] = 0;
    v1080 = v1165;
  }
  int v1177 = (v1080 * 2) + (((int)((unsigned int)v979 >> 2)) & 1);
  int v1081 = v987[v1177];
  int * v1082 = v971->regs;
  v1082[9] = v1081;
  struct StateT * v1084 = slot_10(v971);
  return v1084;
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

struct StateT * slot_10(struct StateT * v545) {
  int * v546 = v545->saved_regs;
  int * v547 = v545->regs;
  int v548 = v547[16];
  v546[16] = v548;
  int v550 = v545->timer;
  int v562 = v550 + 1;
  v545->timer = v562;
  int * v552 = v545->regs;
  int v553 = v552[7];
  int v554 = v552[9];
  int v566 = v553 ^ v554;
  v552[16] = v566;
  struct StateT * v556 = slot_23(v545);
  return v556;
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

struct StateT * slot_13(struct StateT * v662) {
  int v663 = v662->timer;
  int v673 = v663 + 1;
  v662->timer = v673;
  int * v665 = v662->regs;
  int v666 = v665[5];
  bool v676 = (v666 ^ -2147483648) < -2147483647;
  int v669;
  if (v676) {
    v669 = 1;
  } else {
    v669 = 0;
  }
  int * v670 = v662->regs;
  v670[11] = v669;
  return v662;
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

struct StateT * slot_14(struct StateT * v682) {
  int v683 = v682->timer;
  int v690 = v683 + 1;
  v682->timer = v690;
  int * v685 = v682->regs;
  int v686 = v685[14];
  int v693 = v686 + 4;
  v685[14] = v693;
  struct StateT * v688 = slot_16(v682);
  return v688;
}

struct StateT * slot_20(struct StateT * v947) {
  int * v948 = v947->saved_regs;
  int * v949 = v947->regs;
  int v950 = v949[8];
  v948[8] = v950;
  int v952 = v947->timer;
  int v964 = v952 + 1;
  v947->timer = v964;
  int * v954 = v947->regs;
  int v955 = v954[13];
  int v956 = v954[14];
  int v968 = v955 + v956;
  v954[8] = v968;
  struct StateT * v958 = slot_21(v947);
  return v958;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}