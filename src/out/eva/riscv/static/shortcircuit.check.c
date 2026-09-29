// verify: leak (Eva should report untainted: unknown) [unroll 65]
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

struct StateT * slot_14(struct StateT * v625);
struct StateT * slot_6(struct StateT * v86);
struct StateT * slot_16(struct StateT * v668);
struct StateT * slot_5(struct StateT * v62);
struct StateT * slot_17(struct StateT * v676);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v297);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v586);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v321);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_13(struct StateT * v604);
struct StateT * slot_15(struct StateT * v655);
struct StateT * slot_9(struct StateT * v532);
struct StateT * slot_11(struct StateT * v596);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v625) {
  int * v626 = v625->regs;
  int v627 = v626[10];
  int v628 = v626[11];
  bool v644 = !(v627 == v628);
  struct StateT * v639;
  if (v644) {
    int v629 = v625->timer;
    int v645 = v629 + 15;
    v625->timer = v645;
    int * v631 = v625->saved_regs;
    int v632 = v631[14];
    int * v633 = v625->regs;
    v633[14] = v632;
    struct StateT * v635 = slot_15(v625);
    v639 = v635;
  } else {
    struct StateT * v637 = slot_16(v625);
    v639 = v637;
  }
  return v639;
}

struct StateT * slot_6(struct StateT * v86) {
  int * v87 = v86->saved_regs;
  int * v88 = v86->regs;
  int v89 = v88[10];
  v87[10] = v89;
  int v91 = v86->timer;
  int v205 = v91 + 1;
  v86->timer = v205;
  int * v93 = v86->regs;
  int v94 = v93[5];
  int * v95 = v86->cache_tags;
  int v209 = (((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2;
  int v96 = v95[v209];
  int v210 = ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + 1;
  int v97 = v95[v210];
  int v211 = 4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2);
  int v98 = v95[v211];
  int v212 = (4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v99 = v95[v212];
  int v100 = v86->timer;
  int v213 = v100 + ((100 ^ (((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) & 104)))));
  v86->timer = v213;
  int * v102 = v86->cache_vals;
  bool v214 = !(((~(((v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v96 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) == 0);
  int v195;
  if (v214) {
    int * v103 = v86->cache_age;
    int v216 = ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((~(((v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v97 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) & 1);
    int v104 = v103[v216];
    int v105 = v103[v209];
    int v217 = v105 + ((int)((unsigned int)(v105 - v104) >> 31));
    v103[v209] = v217;
    int * v107 = v86->cache_age;
    int v108 = v107[v210];
    int v219 = v108 + ((int)((unsigned int)(v108 - v104) >> 31));
    v107[v210] = v219;
    int * v110 = v86->cache_age;
    v110[v216] = 0;
    v195 = v216;
  } else {
    int * v113 = v86->cache_age;
    int v223 = (((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2;
    int v114 = v113[v223];
    int * v115 = v86->cache_tags;
    int v116 = v115[v223];
    int v117 = v113[v210];
    int v118 = v115[v210];
    bool v225 = !(((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31))) == 0);
    int v172;
    if (v225) {
      int * v119 = v86->cache_age;
      int v227 = (4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1))))) >> 31)) & 1);
      int v120 = v119[v227];
      int v121 = v119[v211];
      int v228 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[v211] = v228;
      int * v123 = v86->cache_age;
      int v124 = v123[v212];
      int v230 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[v212] = v230;
      int * v126 = v86->cache_age;
      v126[v227] = 0;
      v172 = v227;
    } else {
      int * v129 = v86->cache_age;
      int v234 = 4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2);
      int v130 = v129[v234];
      int * v131 = v86->cache_tags;
      int v132 = v131[v234];
      int v133 = v129[v212];
      int v134 = v131[v212];
      int * v135 = v86->cache_dirty;
      int v237 = (4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v136 = v135[v237];
      bool v238 = !(v136 == 0);
      if (v238) {
        int * v137 = v86->cache_tags;
        int v138 = v137[v237];
        int * v139 = v86->cache_vals;
        int v241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v140 = v139[v241];
        int v242 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v141 = v139[v242];
        int * v142 = v86->mem;
        int v244 = v138 * 2;
        v142[v244] = v140;
        int * v144 = v86->mem;
        int v247 = (v138 * 2) + 1;
        v144[v247] = v141;
        ;
      } else {
        ;
      }
      int * v149 = v86->mem;
      int v252 = ((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) * 2;
      int v150 = v149[v252];
      int v253 = (((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) * 2) + 1;
      int v151 = v149[v253];
      int * v152 = v86->cache_vals;
      int v255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v152[v255] = v150;
      int * v154 = v86->cache_vals;
      int v258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 3) * 2)) + ((((v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2)) - (v133 + ((~(((v134 ^ -1) | (-(v134 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v154[v258] = v151;
      int * v156 = v86->cache_tags;
      int v261 = (int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1);
      v156[v237] = v261;
      int * v158 = v86->cache_dirty;
      v158[v237] = 0;
      int * v160 = v86->cache_age;
      v160[v237] = 1;
      int * v162 = v86->cache_age;
      int v163 = v162[v237];
      int v164 = v162[v211];
      int v267 = v164 + ((int)((unsigned int)(v164 - v163) >> 31));
      v162[v211] = v267;
      int * v166 = v86->cache_age;
      int v167 = v166[v212];
      int v269 = v167 + ((int)((unsigned int)(v167 - v163) >> 31));
      v166[v212] = v269;
      int * v169 = v86->cache_age;
      v169[v237] = 0;
      v172 = v237;
    }
    int * v173 = v86->cache_vals;
    int v272 = v172 * 2;
    int v174 = v173[v272];
    int v273 = (v172 * 2) + 1;
    int v175 = v173[v273];
    int v274 = (((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v173[v274] = v174;
    int * v177 = v86->cache_vals;
    int v277 = ((((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v177[v277] = v175;
    int * v179 = v86->cache_tags;
    int v280 = ((((int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1)) & 1) * 2) + ((((v114 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2)) - (v117 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v281 = (int)((unsigned int)((int)((unsigned int)v94 >> 2)) >> 1);
    v179[v280] = v281;
    int * v181 = v86->cache_dirty;
    v181[v280] = 0;
    int * v183 = v86->cache_age;
    v183[v280] = 1;
    int * v185 = v86->cache_age;
    int v186 = v185[v280];
    int v187 = v185[v209];
    int v287 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
    v185[v209] = v287;
    int * v189 = v86->cache_age;
    int v190 = v189[v210];
    int v289 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
    v189[v210] = v289;
    int * v192 = v86->cache_age;
    v192[v280] = 0;
    v195 = v280;
  }
  int v292 = (v195 * 2) + (((int)((unsigned int)v94 >> 2)) & 1);
  int v196 = v102[v292];
  int * v197 = v86->regs;
  v197[10] = v196;
  struct StateT * v199 = slot_7(v86);
  return v199;
}

struct StateT * slot_16(struct StateT * v668) {
  int v669 = v668->timer;
  int v673 = v669 + 1;
  v668->timer = v673;
  struct StateT * v671 = slot_4(v668);
  return v671;
}

struct StateT * slot_5(struct StateT * v62) {
  int * v63 = v62->saved_regs;
  int * v64 = v62->regs;
  int v65 = v64[5];
  v63[5] = v65;
  int v67 = v62->timer;
  int v79 = v67 + 1;
  v62->timer = v79;
  int * v69 = v62->regs;
  int v70 = v69[12];
  int v71 = v69[14];
  int v83 = v70 + v71;
  v69[5] = v83;
  struct StateT * v73 = slot_6(v62);
  return v73;
}

struct StateT * slot_17(struct StateT * v676) {
  int v677 = v676->timer;
  int v680 = v677 + 1;
  v676->timer = v680;
  return v676;
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

struct StateT * slot_7(struct StateT * v297) {
  int * v298 = v297->saved_regs;
  int * v299 = v297->regs;
  int v300 = v299[6];
  v298[6] = v300;
  int v302 = v297->timer;
  int v314 = v302 + 1;
  v297->timer = v314;
  int * v304 = v297->regs;
  int v305 = v304[13];
  int v306 = v304[14];
  int v318 = v305 + v306;
  v304[6] = v318;
  struct StateT * v308 = slot_8(v297);
  return v308;
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

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v586) {
  int v587 = v586->timer;
  int v592 = v587 + 1;
  v586->timer = v592;
  int * v589 = v586->regs;
  v589[10] = 1;
  return v586;
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

struct StateT * slot_8(struct StateT * v321) {
  int * v322 = v321->saved_regs;
  int * v323 = v321->regs;
  int v324 = v323[11];
  v322[11] = v324;
  int v326 = v321->timer;
  int v440 = v326 + 1;
  v321->timer = v440;
  int * v328 = v321->regs;
  int v329 = v328[6];
  int * v330 = v321->cache_tags;
  int v444 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2;
  int v331 = v330[v444];
  int v445 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + 1;
  int v332 = v330[v445];
  int v446 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
  int v333 = v330[v446];
  int v447 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v334 = v330[v447];
  int v335 = v321->timer;
  int v448 = v335 + ((100 ^ (((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) & 104)))));
  v321->timer = v448;
  int * v337 = v321->cache_vals;
  bool v449 = !(((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
  int v430;
  if (v449) {
    int * v338 = v321->cache_age;
    int v451 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
    int v339 = v338[v451];
    int v340 = v338[v444];
    int v452 = v340 + ((int)((unsigned int)(v340 - v339) >> 31));
    v338[v444] = v452;
    int * v342 = v321->cache_age;
    int v343 = v342[v445];
    int v454 = v343 + ((int)((unsigned int)(v343 - v339) >> 31));
    v342[v445] = v454;
    int * v345 = v321->cache_age;
    v345[v451] = 0;
    v430 = v451;
  } else {
    int * v348 = v321->cache_age;
    int v458 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2;
    int v349 = v348[v458];
    int * v350 = v321->cache_tags;
    int v351 = v350[v458];
    int v352 = v348[v445];
    int v353 = v350[v445];
    bool v460 = !(((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31))) == 0);
    int v407;
    if (v460) {
      int * v354 = v321->cache_age;
      int v462 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1))))) >> 31)) & 1);
      int v355 = v354[v462];
      int v356 = v354[v446];
      int v463 = v356 + ((int)((unsigned int)(v356 - v355) >> 31));
      v354[v446] = v463;
      int * v358 = v321->cache_age;
      int v359 = v358[v447];
      int v465 = v359 + ((int)((unsigned int)(v359 - v355) >> 31));
      v358[v447] = v465;
      int * v361 = v321->cache_age;
      v361[v462] = 0;
      v407 = v462;
    } else {
      int * v364 = v321->cache_age;
      int v469 = 4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2);
      int v365 = v364[v469];
      int * v366 = v321->cache_tags;
      int v367 = v366[v469];
      int v368 = v364[v447];
      int v369 = v366[v447];
      int * v370 = v321->cache_dirty;
      int v472 = (4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v371 = v370[v472];
      bool v473 = !(v371 == 0);
      if (v473) {
        int * v372 = v321->cache_tags;
        int v373 = v372[v472];
        int * v374 = v321->cache_vals;
        int v476 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v375 = v374[v476];
        int v477 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v376 = v374[v477];
        int * v377 = v321->mem;
        int v479 = v373 * 2;
        v377[v479] = v375;
        int * v379 = v321->mem;
        int v482 = (v373 * 2) + 1;
        v379[v482] = v376;
        ;
      } else {
        ;
      }
      int * v384 = v321->mem;
      int v487 = ((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2;
      int v385 = v384[v487];
      int v488 = (((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) * 2) + 1;
      int v386 = v384[v488];
      int * v387 = v321->cache_vals;
      int v490 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v387[v490] = v385;
      int * v389 = v321->cache_vals;
      int v493 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 3) * 2)) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v389[v493] = v386;
      int * v391 = v321->cache_tags;
      int v496 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
      v391[v472] = v496;
      int * v393 = v321->cache_dirty;
      v393[v472] = 0;
      int * v395 = v321->cache_age;
      v395[v472] = 1;
      int * v397 = v321->cache_age;
      int v398 = v397[v472];
      int v399 = v397[v446];
      int v502 = v399 + ((int)((unsigned int)(v399 - v398) >> 31));
      v397[v446] = v502;
      int * v401 = v321->cache_age;
      int v402 = v401[v447];
      int v504 = v402 + ((int)((unsigned int)(v402 - v398) >> 31));
      v401[v447] = v504;
      int * v404 = v321->cache_age;
      v404[v472] = 0;
      v407 = v472;
    }
    int * v408 = v321->cache_vals;
    int v507 = v407 * 2;
    int v409 = v408[v507];
    int v508 = (v407 * 2) + 1;
    int v410 = v408[v508];
    int v509 = (((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v408[v509] = v409;
    int * v412 = v321->cache_vals;
    int v512 = ((((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v412[v512] = v410;
    int * v414 = v321->cache_tags;
    int v515 = ((((int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1)) & 1) * 2) + ((((v349 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2)) - (v352 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v516 = (int)((unsigned int)((int)((unsigned int)v329 >> 2)) >> 1);
    v414[v515] = v516;
    int * v416 = v321->cache_dirty;
    v416[v515] = 0;
    int * v418 = v321->cache_age;
    v418[v515] = 1;
    int * v420 = v321->cache_age;
    int v421 = v420[v515];
    int v422 = v420[v444];
    int v522 = v422 + ((int)((unsigned int)(v422 - v421) >> 31));
    v420[v444] = v522;
    int * v424 = v321->cache_age;
    int v425 = v424[v445];
    int v524 = v425 + ((int)((unsigned int)(v425 - v421) >> 31));
    v424[v445] = v524;
    int * v427 = v321->cache_age;
    v427[v515] = 0;
    v430 = v515;
  }
  int v527 = (v430 * 2) + (((int)((unsigned int)v329 >> 2)) & 1);
  int v431 = v337[v527];
  int * v432 = v321->regs;
  v432[11] = v431;
  struct StateT * v434 = slot_9(v321);
  return v434;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v59 = v55 + 1;
  v54->timer = v59;
  struct StateT * v57 = slot_5(v54);
  return v57;
}

struct StateT * slot_13(struct StateT * v604) {
  int * v605 = v604->saved_regs;
  int * v606 = v604->regs;
  int v607 = v606[14];
  v605[14] = v607;
  int v609 = v604->timer;
  int v620 = v609 + 1;
  v604->timer = v620;
  int * v611 = v604->regs;
  int v612 = v611[14];
  int v622 = v612 + 4;
  v611[14] = v622;
  struct StateT * v614 = slot_14(v604);
  return v614;
}

struct StateT * slot_15(struct StateT * v655) {
  int v656 = v655->timer;
  int v662 = v656 + 1;
  v655->timer = v662;
  int * v658 = v655->regs;
  v658[10] = 0;
  struct StateT * v660 = slot_17(v655);
  return v660;
}

struct StateT * slot_9(struct StateT * v532) {
  int * v533 = v532->regs;
  int v534 = v533[14];
  int v535 = v533[15];
  bool v563 = v534 >= v535;
  struct StateT * v558;
  if (v563) {
    int v536 = v532->timer;
    int v564 = v536 + 15;
    v532->timer = v564;
    int * v538 = v532->saved_regs;
    int v539 = v538[5];
    int * v540 = v532->regs;
    v540[5] = v539;
    int * v542 = v532->saved_regs;
    int v543 = v542[10];
    int * v544 = v532->regs;
    v544[10] = v543;
    int * v546 = v532->saved_regs;
    int v547 = v546[6];
    int * v548 = v532->regs;
    v548[6] = v547;
    int * v550 = v532->saved_regs;
    int v551 = v550[11];
    int * v552 = v532->regs;
    v552[11] = v551;
    struct StateT * v554 = slot_10(v532);
    v558 = v554;
  } else {
    struct StateT * v556 = slot_11(v532);
    v558 = v556;
  }
  return v558;
}

struct StateT * slot_11(struct StateT * v596) {
  int v597 = v596->timer;
  int v601 = v597 + 1;
  v596->timer = v601;
  struct StateT * v599 = slot_13(v596);
  return v599;
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