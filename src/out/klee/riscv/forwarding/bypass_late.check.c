// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

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

struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v115);
struct StateT * slot_3(struct StateT * v38);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1095);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v877);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_9(struct StateT * v1081);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v80) {
  int * v81 = v80->regs;
  int v82 = v81[5];
  int v83 = v81[9];
  bool v102 = v82 >= v83;
  struct StateT * v97;
  if (v102) {
    int v84 = v80->timer;
    int v103 = v84 + 15;
    v80->timer = v103;
    int * v86 = v80->saved_regs;
    int v87 = v86[6];
    int * v88 = v80->regs;
    v88[6] = v87;
    int * v90 = v80->saved_regs;
    int v91 = v90[7];
    int * v92 = v80->regs;
    v92[7] = v91;
    v97 = v80;
  } else {
    struct StateT * v95 = slot_7(v80);
    v97 = v95;
  }
  return v97;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v35 = v31 + 1;
  v30->timer = v35;
  struct StateT * v33 = slot_3(v30);
  return v33;
}

struct StateT * slot_7(struct StateT * v115) {
  int v116 = v115->timer;
  int v532 = v116 + 1;
  v115->timer = v532;
  int * v118 = v115->regs;
  int v119 = v118[6];
  int v120 = v118[7];
  int * v121 = v115->saved_regs;
  int v122 = v118[11];
  v121[11] = v122;
  int v124 = v115->timer;
  int v539 = v124 + 1;
  v115->timer = v539;
  int * v126 = v115->regs;
  int v127 = v126[6];
  int * v128 = v115->cache_tags;
  int v542 = (((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2;
  int v129 = v128[v542];
  int v543 = ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2) + 1;
  int v130 = v128[v543];
  int v544 = 4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2);
  int v131 = v128[v544];
  int v545 = (4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v132 = v128[v545];
  int v133 = v115->timer;
  int v546 = v133 + ((100 ^ (((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) | (~(((v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) | (~(((v130 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v130 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) | (~(((v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31))) & 104)))));
  v115->timer = v546;
  int * v135 = v115->cache_vals;
  bool v547 = !(((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) | (~(((v130 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v130 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31))) == 0);
  int v228;
  if (v547) {
    int * v136 = v115->cache_age;
    int v549 = ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2) + ((~(((v130 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v130 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) & 1);
    int v137 = v136[v549];
    int v138 = v136[v542];
    int v550 = v138 + ((int)((unsigned int)(v138 - v137) >> 31));
    v136[v542] = v550;
    int * v140 = v115->cache_age;
    int v141 = v140[v543];
    int v552 = v141 + ((int)((unsigned int)(v141 - v137) >> 31));
    v140[v543] = v552;
    int * v143 = v115->cache_age;
    v143[v549] = 0;
    v228 = v549;
  } else {
    int * v146 = v115->cache_age;
    int v556 = (((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2;
    int v147 = v146[v556];
    int * v148 = v115->cache_tags;
    int v149 = v148[v556];
    int v150 = v146[v543];
    int v151 = v148[v543];
    bool v558 = !(((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) | (~(((v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31))) == 0);
    int v205;
    if (v558) {
      int * v152 = v115->cache_age;
      int v560 = (4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + ((~(((v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))) | (-(v132 ^ ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1))))) >> 31)) & 1);
      int v153 = v152[v560];
      int v154 = v152[v544];
      int v561 = v154 + ((int)((unsigned int)(v154 - v153) >> 31));
      v152[v544] = v561;
      int * v156 = v115->cache_age;
      int v157 = v156[v545];
      int v563 = v157 + ((int)((unsigned int)(v157 - v153) >> 31));
      v156[v545] = v563;
      int * v159 = v115->cache_age;
      v159[v560] = 0;
      v205 = v560;
    } else {
      int * v162 = v115->cache_age;
      int v567 = 4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2);
      int v163 = v162[v567];
      int * v164 = v115->cache_tags;
      int v165 = v164[v567];
      int v166 = v162[v545];
      int v167 = v164[v545];
      int * v168 = v115->cache_dirty;
      int v570 = (4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v169 = v168[v570];
      bool v571 = !(v169 == 0);
      if (v571) {
        int * v170 = v115->cache_tags;
        int v171 = v170[v570];
        int * v172 = v115->cache_vals;
        int v574 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v173 = v172[v574];
        int v575 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174 = v172[v575];
        int * v175 = v115->mem;
        int v577 = v171 * 2;
        v175[v577] = v173;
        int * v177 = v115->mem;
        int v580 = (v171 * 2) + 1;
        v177[v580] = v174;
        ;
      } else {
        ;
      }
      int * v182 = v115->mem;
      int v585 = ((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) * 2;
      int v183 = v182[v585];
      int v586 = (((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) * 2) + 1;
      int v184 = v182[v586];
      int * v185 = v115->cache_vals;
      int v588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v185[v588] = v183;
      int * v187 = v115->cache_vals;
      int v591 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v187[v591] = v184;
      int * v189 = v115->cache_tags;
      int v594 = (int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1);
      v189[v570] = v594;
      int * v191 = v115->cache_dirty;
      v191[v570] = 0;
      int * v193 = v115->cache_age;
      v193[v570] = 1;
      int * v195 = v115->cache_age;
      int v196 = v195[v570];
      int v197 = v195[v544];
      int v600 = v197 + ((int)((unsigned int)(v197 - v196) >> 31));
      v195[v544] = v600;
      int * v199 = v115->cache_age;
      int v200 = v199[v545];
      int v602 = v200 + ((int)((unsigned int)(v200 - v196) >> 31));
      v199[v545] = v602;
      int * v202 = v115->cache_age;
      v202[v570] = 0;
      v205 = v570;
    }
    int * v206 = v115->cache_vals;
    int v605 = v205 * 2;
    int v207 = v206[v605];
    int v606 = (v205 * 2) + 1;
    int v208 = v206[v606];
    int v607 = (((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v206[v607] = v207;
    int * v210 = v115->cache_vals;
    int v610 = ((((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v210[v610] = v208;
    int * v212 = v115->cache_tags;
    int v613 = ((((int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v614 = (int)((unsigned int)((int)((unsigned int)v127 >> 2)) >> 1);
    v212[v613] = v614;
    int * v214 = v115->cache_dirty;
    v214[v613] = 0;
    int * v216 = v115->cache_age;
    v216[v613] = 1;
    int * v218 = v115->cache_age;
    int v219 = v218[v613];
    int v220 = v218[v542];
    int v620 = v220 + ((int)((unsigned int)(v220 - v219) >> 31));
    v218[v542] = v620;
    int * v222 = v115->cache_age;
    int v223 = v222[v543];
    int v622 = v223 + ((int)((unsigned int)(v223 - v219) >> 31));
    v222[v543] = v622;
    int * v225 = v115->cache_age;
    v225[v613] = 0;
    v228 = v613;
  }
  int v625 = (v228 * 2) + (((int)((unsigned int)v127 >> 2)) & 1);
  int v229 = v135[v625];
  int * v230 = v115->regs;
  v230[11] = v229;
  int v232 = v115->timer;
  int v628 = v232 + 1;
  v115->timer = v628;
  int * v234 = v115->regs;
  int v235 = v234[11];
  int v630 = v235 << 2;
  v234[11] = v630;
  int * v237 = v115->saved_regs;
  int * v238 = v115->regs;
  int v239 = v238[12];
  v237[12] = v239;
  int v241 = v115->timer;
  int v635 = v241 + 1;
  v115->timer = v635;
  int * v243 = v115->regs;
  int v244 = v243[11];
  bool v637 = (((int)((unsigned int)v119 >> 2)) & 3) == (((int)((unsigned int)v244 >> 2)) & 3);
  int v351;
  if (v637) {
    int v245 = v115->timer;
    int v638 = v245 + 1;
    v115->timer = v638;
    v351 = v120;
  } else {
    int * v248 = v115->cache_tags;
    int v641 = (((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2;
    int v249 = v248[v641];
    int v642 = ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2) + 1;
    int v250 = v248[v642];
    int v643 = 4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2);
    int v251 = v248[v643];
    int v644 = (4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v252 = v248[v644];
    int v253 = v115->timer;
    int v645 = v253 + ((100 ^ (((~(((v251 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v251 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) | (~(((v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v249 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v249 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) | (~(((v250 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v250 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v251 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v251 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) | (~(((v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31))) & 104)))));
    v115->timer = v645;
    int * v255 = v115->cache_vals;
    bool v646 = !(((~(((v249 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v249 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) | (~(((v250 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v250 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31))) == 0);
    int v348;
    if (v646) {
      int * v256 = v115->cache_age;
      int v648 = ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2) + ((~(((v250 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v250 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) & 1);
      int v257 = v256[v648];
      int v258 = v256[v641];
      int v649 = v258 + ((int)((unsigned int)(v258 - v257) >> 31));
      v256[v641] = v649;
      int * v260 = v115->cache_age;
      int v261 = v260[v642];
      int v651 = v261 + ((int)((unsigned int)(v261 - v257) >> 31));
      v260[v642] = v651;
      int * v263 = v115->cache_age;
      v263[v648] = 0;
      v348 = v648;
    } else {
      int * v266 = v115->cache_age;
      int v655 = (((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2;
      int v267 = v266[v655];
      int * v268 = v115->cache_tags;
      int v269 = v268[v655];
      int v270 = v266[v642];
      int v271 = v268[v642];
      bool v657 = !(((~(((v251 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v251 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) | (~(((v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31))) == 0);
      int v325;
      if (v657) {
        int * v272 = v115->cache_age;
        int v659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + ((~(((v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))) | (-(v252 ^ ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1))))) >> 31)) & 1);
        int v273 = v272[v659];
        int v274 = v272[v643];
        int v660 = v274 + ((int)((unsigned int)(v274 - v273) >> 31));
        v272[v643] = v660;
        int * v276 = v115->cache_age;
        int v277 = v276[v644];
        int v662 = v277 + ((int)((unsigned int)(v277 - v273) >> 31));
        v276[v644] = v662;
        int * v279 = v115->cache_age;
        v279[v659] = 0;
        v325 = v659;
      } else {
        int * v282 = v115->cache_age;
        int v666 = 4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2);
        int v283 = v282[v666];
        int * v284 = v115->cache_tags;
        int v285 = v284[v666];
        int v286 = v282[v644];
        int v287 = v284[v644];
        int * v288 = v115->cache_dirty;
        int v669 = (4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v289 = v288[v669];
        bool v670 = !(v289 == 0);
        if (v670) {
          int * v290 = v115->cache_tags;
          int v291 = v290[v669];
          int * v292 = v115->cache_vals;
          int v673 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v293 = v292[v673];
          int v674 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v294 = v292[v674];
          int * v295 = v115->mem;
          int v676 = v291 * 2;
          v295[v676] = v293;
          int * v297 = v115->mem;
          int v679 = (v291 * 2) + 1;
          v297[v679] = v294;
          ;
        } else {
          ;
        }
        int * v302 = v115->mem;
        int v684 = ((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) * 2;
        int v303 = v302[v684];
        int v685 = (((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) * 2) + 1;
        int v304 = v302[v685];
        int * v305 = v115->cache_vals;
        int v687 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v305[v687] = v303;
        int * v307 = v115->cache_vals;
        int v690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 3) * 2)) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v307[v690] = v304;
        int * v309 = v115->cache_tags;
        int v693 = (int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1);
        v309[v669] = v693;
        int * v311 = v115->cache_dirty;
        v311[v669] = 0;
        int * v313 = v115->cache_age;
        v313[v669] = 1;
        int * v315 = v115->cache_age;
        int v316 = v315[v669];
        int v317 = v315[v643];
        int v699 = v317 + ((int)((unsigned int)(v317 - v316) >> 31));
        v315[v643] = v699;
        int * v319 = v115->cache_age;
        int v320 = v319[v644];
        int v701 = v320 + ((int)((unsigned int)(v320 - v316) >> 31));
        v319[v644] = v701;
        int * v322 = v115->cache_age;
        v322[v669] = 0;
        v325 = v669;
      }
      int * v326 = v115->cache_vals;
      int v704 = v325 * 2;
      int v327 = v326[v704];
      int v705 = (v325 * 2) + 1;
      int v328 = v326[v705];
      int v706 = (((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2) + ((((v267 + ((~(((v269 ^ -1) | (-(v269 ^ -1))) >> 31)) & 2)) - (v270 + ((~(((v271 ^ -1) | (-(v271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v326[v706] = v327;
      int * v330 = v115->cache_vals;
      int v709 = ((((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2) + ((((v267 + ((~(((v269 ^ -1) | (-(v269 ^ -1))) >> 31)) & 2)) - (v270 + ((~(((v271 ^ -1) | (-(v271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v709] = v328;
      int * v332 = v115->cache_tags;
      int v712 = ((((int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1)) & 1) * 2) + ((((v267 + ((~(((v269 ^ -1) | (-(v269 ^ -1))) >> 31)) & 2)) - (v270 + ((~(((v271 ^ -1) | (-(v271 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v713 = (int)((unsigned int)((int)((unsigned int)v244 >> 2)) >> 1);
      v332[v712] = v713;
      int * v334 = v115->cache_dirty;
      v334[v712] = 0;
      int * v336 = v115->cache_age;
      v336[v712] = 1;
      int * v338 = v115->cache_age;
      int v339 = v338[v712];
      int v340 = v338[v641];
      int v719 = v340 + ((int)((unsigned int)(v340 - v339) >> 31));
      v338[v641] = v719;
      int * v342 = v115->cache_age;
      int v343 = v342[v642];
      int v721 = v343 + ((int)((unsigned int)(v343 - v339) >> 31));
      v342[v642] = v721;
      int * v345 = v115->cache_age;
      v345[v712] = 0;
      v348 = v712;
    }
    int v724 = (v348 * 2) + (((int)((unsigned int)v244 >> 2)) & 1);
    int v349 = v255[v724];
    v351 = v349;
  }
  int * v352 = v115->regs;
  v352[12] = v351;
  int * v354 = v115->cache_tags;
  int v729 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2;
  int v355 = v354[v729];
  int v730 = ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + 1;
  int v356 = v354[v730];
  int v731 = 4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2);
  int v357 = v354[v731];
  int v732 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v358 = v354[v732];
  int v359 = v115->timer;
  int v733 = v359 + ((100 ^ (((~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) & 104)))));
  v115->timer = v733;
  bool v734 = !(((~(((v355 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v355 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) == 0);
  int v453;
  if (v734) {
    int * v361 = v115->cache_age;
    int v736 = ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) & 1);
    int v362 = v361[v736];
    int v363 = v361[v729];
    int v737 = v363 + ((int)((unsigned int)(v363 - v362) >> 31));
    v361[v729] = v737;
    int * v365 = v115->cache_age;
    int v366 = v365[v730];
    int v739 = v366 + ((int)((unsigned int)(v366 - v362) >> 31));
    v365[v730] = v739;
    int * v368 = v115->cache_age;
    v368[v736] = 0;
    v453 = v736;
  } else {
    int * v371 = v115->cache_age;
    int v743 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2;
    int v372 = v371[v743];
    int * v373 = v115->cache_tags;
    int v374 = v373[v743];
    int v375 = v371[v730];
    int v376 = v373[v730];
    bool v745 = !(((~(((v357 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v357 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) == 0);
    int v430;
    if (v745) {
      int * v377 = v115->cache_age;
      int v747 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) & 1);
      int v378 = v377[v747];
      int v379 = v377[v731];
      int v748 = v379 + ((int)((unsigned int)(v379 - v378) >> 31));
      v377[v731] = v748;
      int * v381 = v115->cache_age;
      int v382 = v381[v732];
      int v750 = v382 + ((int)((unsigned int)(v382 - v378) >> 31));
      v381[v732] = v750;
      int * v384 = v115->cache_age;
      v384[v747] = 0;
      v430 = v747;
    } else {
      int * v387 = v115->cache_age;
      int v754 = 4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2);
      int v388 = v387[v754];
      int * v389 = v115->cache_tags;
      int v390 = v389[v754];
      int v391 = v387[v732];
      int v392 = v389[v732];
      int * v393 = v115->cache_dirty;
      int v757 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2)) - (v391 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v394 = v393[v757];
      bool v758 = !(v394 == 0);
      if (v758) {
        int * v395 = v115->cache_tags;
        int v396 = v395[v757];
        int * v397 = v115->cache_vals;
        int v761 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2)) - (v391 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v398 = v397[v761];
        int v762 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2)) - (v391 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v399 = v397[v762];
        int * v400 = v115->mem;
        int v764 = v396 * 2;
        v400[v764] = v398;
        int * v402 = v115->mem;
        int v767 = (v396 * 2) + 1;
        v402[v767] = v399;
        ;
      } else {
        ;
      }
      int * v407 = v115->mem;
      int v772 = ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2;
      int v408 = v407[v772];
      int v773 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2) + 1;
      int v409 = v407[v773];
      int * v410 = v115->cache_vals;
      int v775 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2)) - (v391 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v410[v775] = v408;
      int * v412 = v115->cache_vals;
      int v778 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v388 + ((~(((v390 ^ -1) | (-(v390 ^ -1))) >> 31)) & 2)) - (v391 + ((~(((v392 ^ -1) | (-(v392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v412[v778] = v409;
      int * v414 = v115->cache_tags;
      int v781 = (int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1);
      v414[v757] = v781;
      int * v416 = v115->cache_dirty;
      v416[v757] = 0;
      int * v418 = v115->cache_age;
      v418[v757] = 1;
      int * v420 = v115->cache_age;
      int v421 = v420[v757];
      int v422 = v420[v731];
      int v787 = v422 + ((int)((unsigned int)(v422 - v421) >> 31));
      v420[v731] = v787;
      int * v424 = v115->cache_age;
      int v425 = v424[v732];
      int v789 = v425 + ((int)((unsigned int)(v425 - v421) >> 31));
      v424[v732] = v789;
      int * v427 = v115->cache_age;
      v427[v757] = 0;
      v430 = v757;
    }
    int * v431 = v115->cache_vals;
    int v792 = v430 * 2;
    int v432 = v431[v792];
    int v793 = (v430 * 2) + 1;
    int v433 = v431[v793];
    int v794 = (((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v431[v794] = v432;
    int * v435 = v115->cache_vals;
    int v797 = ((((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v435[v797] = v433;
    int * v437 = v115->cache_tags;
    int v800 = ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 1) * 2) + ((((v372 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2)) - (v375 + ((~(((v376 ^ -1) | (-(v376 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v801 = (int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1);
    v437[v800] = v801;
    int * v439 = v115->cache_dirty;
    v439[v800] = 0;
    int * v441 = v115->cache_age;
    v441[v800] = 1;
    int * v443 = v115->cache_age;
    int v444 = v443[v800];
    int v445 = v443[v729];
    int v807 = v445 + ((int)((unsigned int)(v445 - v444) >> 31));
    v443[v729] = v807;
    int * v447 = v115->cache_age;
    int v448 = v447[v730];
    int v809 = v448 + ((int)((unsigned int)(v448 - v444) >> 31));
    v447[v730] = v809;
    int * v450 = v115->cache_age;
    v450[v800] = 0;
    v453 = v800;
  }
  int * v454 = v115->cache_vals;
  int v812 = (v453 * 2) + (((int)((unsigned int)v119 >> 2)) & 1);
  v454[v812] = v120;
  int * v456 = v115->cache_tags;
  int v457 = v456[v731];
  int v458 = v456[v732];
  bool v815 = !(((~(((v457 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v457 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) | (~(((v458 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v458 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31))) == 0);
  int v512;
  if (v815) {
    int * v459 = v115->cache_age;
    int v817 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((~(((v458 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))) | (-(v458 ^ ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1))))) >> 31)) & 1);
    int v460 = v459[v817];
    int v461 = v459[v731];
    int v818 = v461 + ((int)((unsigned int)(v461 - v460) >> 31));
    v459[v731] = v818;
    int * v463 = v115->cache_age;
    int v464 = v463[v732];
    int v820 = v464 + ((int)((unsigned int)(v464 - v460) >> 31));
    v463[v732] = v820;
    int * v466 = v115->cache_age;
    v466[v817] = 0;
    v512 = v817;
  } else {
    int * v469 = v115->cache_age;
    int v824 = 4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2);
    int v470 = v469[v824];
    int * v471 = v115->cache_tags;
    int v472 = v471[v824];
    int v473 = v469[v732];
    int v474 = v471[v732];
    int * v475 = v115->cache_dirty;
    int v827 = (4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v476 = v475[v827];
    bool v828 = !(v476 == 0);
    if (v828) {
      int * v477 = v115->cache_tags;
      int v478 = v477[v827];
      int * v479 = v115->cache_vals;
      int v831 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v480 = v479[v831];
      int v832 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v481 = v479[v832];
      int * v482 = v115->mem;
      int v834 = v478 * 2;
      v482[v834] = v480;
      int * v484 = v115->mem;
      int v837 = (v478 * 2) + 1;
      v484[v837] = v481;
      ;
    } else {
      ;
    }
    int * v489 = v115->mem;
    int v842 = ((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2;
    int v490 = v489[v842];
    int v843 = (((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) * 2) + 1;
    int v491 = v489[v843];
    int * v492 = v115->cache_vals;
    int v845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v492[v845] = v490;
    int * v494 = v115->cache_vals;
    int v848 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1)) & 3) * 2)) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v473 + ((~(((v474 ^ -1) | (-(v474 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v494[v848] = v491;
    int * v496 = v115->cache_tags;
    int v851 = (int)((unsigned int)((int)((unsigned int)v119 >> 2)) >> 1);
    v496[v827] = v851;
    int * v498 = v115->cache_dirty;
    v498[v827] = 0;
    int * v500 = v115->cache_age;
    v500[v827] = 1;
    int * v502 = v115->cache_age;
    int v503 = v502[v827];
    int v504 = v502[v731];
    int v857 = v504 + ((int)((unsigned int)(v504 - v503) >> 31));
    v502[v731] = v857;
    int * v506 = v115->cache_age;
    int v507 = v506[v732];
    int v859 = v507 + ((int)((unsigned int)(v507 - v503) >> 31));
    v506[v732] = v859;
    int * v509 = v115->cache_age;
    v509[v827] = 0;
    v512 = v827;
  }
  int * v513 = v115->cache_vals;
  int v862 = (v512 * 2) + (((int)((unsigned int)v119 >> 2)) & 1);
  v513[v862] = v120;
  int * v515 = v115->cache_dirty;
  v515[v512] = 1;
  bool v866 = (((int)((unsigned int)v127 >> 2)) == ((int)((unsigned int)v119 >> 2))) | (((((int)((unsigned int)v244 >> 2)) & 3) == (((int)((unsigned int)v119 >> 2)) & 3)) & (!(((int)((unsigned int)v244 >> 2)) == ((int)((unsigned int)v119 >> 2)))));
  struct StateT * v530;
  if (v866) {
    int v517 = v115->timer;
    int v867 = v517 + 15;
    v115->timer = v867;
    int * v519 = v115->saved_regs;
    int v520 = v519[11];
    int * v521 = v115->regs;
    v521[11] = v520;
    int * v523 = v115->saved_regs;
    int v524 = v523[12];
    int * v525 = v115->regs;
    v525[12] = v524;
    struct StateT * v527 = slot_8(v115);
    v530 = v527;
  } else {
    v530 = v115;
  }
  return v530;
}

struct StateT * slot_3(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[6];
  v39[6] = v41;
  int v43 = v38->timer;
  int v54 = v43 + 1;
  v38->timer = v54;
  int * v45 = v38->regs;
  int v46 = v45[5];
  int v57 = v46 + 80;
  v45[6] = v57;
  struct StateT * v48 = slot_4(v38);
  return v48;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v1095) {
  int v1096 = v1095->timer;
  int v1205 = v1096 + 1;
  v1095->timer = v1205;
  int * v1098 = v1095->regs;
  int v1099 = v1098[11];
  int * v1100 = v1095->cache_tags;
  int v1209 = (((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2;
  int v1101 = v1100[v1209];
  int v1210 = ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1102 = v1100[v1210];
  int v1211 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2);
  int v1103 = v1100[v1211];
  int v1212 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1104 = v1100[v1212];
  int v1105 = v1095->timer;
  int v1213 = v1105 + ((100 ^ (((~(((v1103 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1103 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) | (~(((v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1103 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1103 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) | (~(((v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1095->timer = v1213;
  int * v1107 = v1095->cache_vals;
  bool v1214 = !(((~(((v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1101 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) | (~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31))) == 0);
  int v1200;
  if (v1214) {
    int * v1108 = v1095->cache_age;
    int v1216 = ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2) + ((~(((v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1102 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) & 1);
    int v1109 = v1108[v1216];
    int v1110 = v1108[v1209];
    int v1217 = v1110 + ((int)((unsigned int)(v1110 - v1109) >> 31));
    v1108[v1209] = v1217;
    int * v1112 = v1095->cache_age;
    int v1113 = v1112[v1210];
    int v1219 = v1113 + ((int)((unsigned int)(v1113 - v1109) >> 31));
    v1112[v1210] = v1219;
    int * v1115 = v1095->cache_age;
    v1115[v1216] = 0;
    v1200 = v1216;
  } else {
    int * v1118 = v1095->cache_age;
    int v1223 = (((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2;
    int v1119 = v1118[v1223];
    int * v1120 = v1095->cache_tags;
    int v1121 = v1120[v1223];
    int v1122 = v1118[v1210];
    int v1123 = v1120[v1210];
    bool v1225 = !(((~(((v1103 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1103 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) | (~(((v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31))) == 0);
    int v1177;
    if (v1225) {
      int * v1124 = v1095->cache_age;
      int v1227 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))) | (-(v1104 ^ ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1))))) >> 31)) & 1);
      int v1125 = v1124[v1227];
      int v1126 = v1124[v1211];
      int v1228 = v1126 + ((int)((unsigned int)(v1126 - v1125) >> 31));
      v1124[v1211] = v1228;
      int * v1128 = v1095->cache_age;
      int v1129 = v1128[v1212];
      int v1230 = v1129 + ((int)((unsigned int)(v1129 - v1125) >> 31));
      v1128[v1212] = v1230;
      int * v1131 = v1095->cache_age;
      v1131[v1227] = 0;
      v1177 = v1227;
    } else {
      int * v1134 = v1095->cache_age;
      int v1234 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2);
      int v1135 = v1134[v1234];
      int * v1136 = v1095->cache_tags;
      int v1137 = v1136[v1234];
      int v1138 = v1134[v1212];
      int v1139 = v1136[v1212];
      int * v1140 = v1095->cache_dirty;
      int v1237 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + ((((v1135 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1141 = v1140[v1237];
      bool v1238 = !(v1141 == 0);
      if (v1238) {
        int * v1142 = v1095->cache_tags;
        int v1143 = v1142[v1237];
        int * v1144 = v1095->cache_vals;
        int v1241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + ((((v1135 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1145 = v1144[v1241];
        int v1242 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + ((((v1135 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1146 = v1144[v1242];
        int * v1147 = v1095->mem;
        int v1244 = v1143 * 2;
        v1147[v1244] = v1145;
        int * v1149 = v1095->mem;
        int v1247 = (v1143 * 2) + 1;
        v1149[v1247] = v1146;
        ;
      } else {
        ;
      }
      int * v1154 = v1095->mem;
      int v1252 = ((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) * 2;
      int v1155 = v1154[v1252];
      int v1253 = (((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) * 2) + 1;
      int v1156 = v1154[v1253];
      int * v1157 = v1095->cache_vals;
      int v1255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + ((((v1135 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1157[v1255] = v1155;
      int * v1159 = v1095->cache_vals;
      int v1258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 3) * 2)) + ((((v1135 + ((~(((v1137 ^ -1) | (-(v1137 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1159[v1258] = v1156;
      int * v1161 = v1095->cache_tags;
      int v1261 = (int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1);
      v1161[v1237] = v1261;
      int * v1163 = v1095->cache_dirty;
      v1163[v1237] = 0;
      int * v1165 = v1095->cache_age;
      v1165[v1237] = 1;
      int * v1167 = v1095->cache_age;
      int v1168 = v1167[v1237];
      int v1169 = v1167[v1211];
      int v1267 = v1169 + ((int)((unsigned int)(v1169 - v1168) >> 31));
      v1167[v1211] = v1267;
      int * v1171 = v1095->cache_age;
      int v1172 = v1171[v1212];
      int v1269 = v1172 + ((int)((unsigned int)(v1172 - v1168) >> 31));
      v1171[v1212] = v1269;
      int * v1174 = v1095->cache_age;
      v1174[v1237] = 0;
      v1177 = v1237;
    }
    int * v1178 = v1095->cache_vals;
    int v1272 = v1177 * 2;
    int v1179 = v1178[v1272];
    int v1273 = (v1177 * 2) + 1;
    int v1180 = v1178[v1273];
    int v1274 = (((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1178[v1274] = v1179;
    int * v1182 = v1095->cache_vals;
    int v1277 = ((((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1182[v1277] = v1180;
    int * v1184 = v1095->cache_tags;
    int v1280 = ((((int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1)) & 1) * 2) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1281 = (int)((unsigned int)((int)((unsigned int)v1099 >> 2)) >> 1);
    v1184[v1280] = v1281;
    int * v1186 = v1095->cache_dirty;
    v1186[v1280] = 0;
    int * v1188 = v1095->cache_age;
    v1188[v1280] = 1;
    int * v1190 = v1095->cache_age;
    int v1191 = v1190[v1280];
    int v1192 = v1190[v1209];
    int v1287 = v1192 + ((int)((unsigned int)(v1192 - v1191) >> 31));
    v1190[v1209] = v1287;
    int * v1194 = v1095->cache_age;
    int v1195 = v1194[v1210];
    int v1289 = v1195 + ((int)((unsigned int)(v1195 - v1191) >> 31));
    v1194[v1210] = v1289;
    int * v1197 = v1095->cache_age;
    v1197[v1280] = 0;
    v1200 = v1280;
  }
  int v1292 = (v1200 * 2) + (((int)((unsigned int)v1099 >> 2)) & 1);
  int v1201 = v1107[v1292];
  int * v1202 = v1095->regs;
  v1202[12] = v1201;
  return v1095;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[9] = 32;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_8(struct StateT * v877) {
  int v878 = v877->timer;
  int v988 = v878 + 1;
  v877->timer = v988;
  int * v880 = v877->regs;
  int v881 = v880[6];
  int * v882 = v877->cache_tags;
  int v992 = (((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2;
  int v883 = v882[v992];
  int v993 = ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + 1;
  int v884 = v882[v993];
  int v994 = 4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2);
  int v885 = v882[v994];
  int v995 = (4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v886 = v882[v995];
  int v887 = v877->timer;
  int v996 = v887 + ((100 ^ (((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) & 104)))));
  v877->timer = v996;
  int * v889 = v877->cache_vals;
  bool v997 = !(((~(((v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) == 0);
  int v982;
  if (v997) {
    int * v890 = v877->cache_age;
    int v999 = ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) & 1);
    int v891 = v890[v999];
    int v892 = v890[v992];
    int v1000 = v892 + ((int)((unsigned int)(v892 - v891) >> 31));
    v890[v992] = v1000;
    int * v894 = v877->cache_age;
    int v895 = v894[v993];
    int v1002 = v895 + ((int)((unsigned int)(v895 - v891) >> 31));
    v894[v993] = v1002;
    int * v897 = v877->cache_age;
    v897[v999] = 0;
    v982 = v999;
  } else {
    int * v900 = v877->cache_age;
    int v1006 = (((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2;
    int v901 = v900[v1006];
    int * v902 = v877->cache_tags;
    int v903 = v902[v1006];
    int v904 = v900[v993];
    int v905 = v902[v993];
    bool v1008 = !(((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) == 0);
    int v959;
    if (v1008) {
      int * v906 = v877->cache_age;
      int v1010 = (4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) & 1);
      int v907 = v906[v1010];
      int v908 = v906[v994];
      int v1011 = v908 + ((int)((unsigned int)(v908 - v907) >> 31));
      v906[v994] = v1011;
      int * v910 = v877->cache_age;
      int v911 = v910[v995];
      int v1013 = v911 + ((int)((unsigned int)(v911 - v907) >> 31));
      v910[v995] = v1013;
      int * v913 = v877->cache_age;
      v913[v1010] = 0;
      v959 = v1010;
    } else {
      int * v916 = v877->cache_age;
      int v1017 = 4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2);
      int v917 = v916[v1017];
      int * v918 = v877->cache_tags;
      int v919 = v918[v1017];
      int v920 = v916[v995];
      int v921 = v918[v995];
      int * v922 = v877->cache_dirty;
      int v1020 = (4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v923 = v922[v1020];
      bool v1021 = !(v923 == 0);
      if (v1021) {
        int * v924 = v877->cache_tags;
        int v925 = v924[v1020];
        int * v926 = v877->cache_vals;
        int v1024 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v927 = v926[v1024];
        int v1025 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v928 = v926[v1025];
        int * v929 = v877->mem;
        int v1027 = v925 * 2;
        v929[v1027] = v927;
        int * v931 = v877->mem;
        int v1030 = (v925 * 2) + 1;
        v931[v1030] = v928;
        ;
      } else {
        ;
      }
      int * v936 = v877->mem;
      int v1035 = ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) * 2;
      int v937 = v936[v1035];
      int v1036 = (((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) * 2) + 1;
      int v938 = v936[v1036];
      int * v939 = v877->cache_vals;
      int v1038 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v939[v1038] = v937;
      int * v941 = v877->cache_vals;
      int v1041 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v941[v1041] = v938;
      int * v943 = v877->cache_tags;
      int v1044 = (int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1);
      v943[v1020] = v1044;
      int * v945 = v877->cache_dirty;
      v945[v1020] = 0;
      int * v947 = v877->cache_age;
      v947[v1020] = 1;
      int * v949 = v877->cache_age;
      int v950 = v949[v1020];
      int v951 = v949[v994];
      int v1050 = v951 + ((int)((unsigned int)(v951 - v950) >> 31));
      v949[v994] = v1050;
      int * v953 = v877->cache_age;
      int v954 = v953[v995];
      int v1052 = v954 + ((int)((unsigned int)(v954 - v950) >> 31));
      v953[v995] = v1052;
      int * v956 = v877->cache_age;
      v956[v1020] = 0;
      v959 = v1020;
    }
    int * v960 = v877->cache_vals;
    int v1055 = v959 * 2;
    int v961 = v960[v1055];
    int v1056 = (v959 * 2) + 1;
    int v962 = v960[v1056];
    int v1057 = (((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((((v901 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2)) - (v904 + ((~(((v905 ^ -1) | (-(v905 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v960[v1057] = v961;
    int * v964 = v877->cache_vals;
    int v1060 = ((((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((((v901 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2)) - (v904 + ((~(((v905 ^ -1) | (-(v905 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v964[v1060] = v962;
    int * v966 = v877->cache_tags;
    int v1063 = ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((((v901 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2)) - (v904 + ((~(((v905 ^ -1) | (-(v905 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1064 = (int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1);
    v966[v1063] = v1064;
    int * v968 = v877->cache_dirty;
    v968[v1063] = 0;
    int * v970 = v877->cache_age;
    v970[v1063] = 1;
    int * v972 = v877->cache_age;
    int v973 = v972[v1063];
    int v974 = v972[v992];
    int v1070 = v974 + ((int)((unsigned int)(v974 - v973) >> 31));
    v972[v992] = v1070;
    int * v976 = v877->cache_age;
    int v977 = v976[v993];
    int v1072 = v977 + ((int)((unsigned int)(v977 - v973) >> 31));
    v976[v993] = v1072;
    int * v979 = v877->cache_age;
    v979[v1063] = 0;
    v982 = v1063;
  }
  int v1075 = (v982 * 2) + (((int)((unsigned int)v881 >> 2)) & 1);
  int v983 = v889[v1075];
  int * v984 = v877->regs;
  v984[11] = v983;
  struct StateT * v986 = slot_9(v877);
  return v986;
}

struct StateT * slot_4(struct StateT * v60) {
  int * v61 = v60->saved_regs;
  int * v62 = v60->regs;
  int v63 = v62[7];
  v61[7] = v63;
  int v65 = v60->timer;
  int v75 = v65 + 1;
  v60->timer = v75;
  int * v67 = v60->regs;
  v67[7] = 0;
  struct StateT * v69 = slot_5(v60);
  return v69;
}

struct StateT * slot_9(struct StateT * v1081) {
  int v1082 = v1081->timer;
  int v1089 = v1082 + 1;
  v1081->timer = v1089;
  int * v1084 = v1081->regs;
  int v1085 = v1084[11];
  int v1092 = v1085 << 2;
  v1084[11] = v1092;
  struct StateT * v1087 = slot_10(v1081);
  return v1087;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}