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

struct StateT * slot_6(struct StateT * v284);
struct StateT * slot_5(struct StateT * v73);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v838);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v319);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_9(struct StateT * v634);
struct StateT * slot_11(struct StateT * v852);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v284) {
  int * v285 = v284->regs;
  int v286 = v285[6];
  int v287 = v285[7];
  bool v306 = v286 >= v287;
  struct StateT * v301;
  if (v306) {
    int v288 = v284->timer;
    int v307 = v288 + 15;
    v284->timer = v307;
    int * v290 = v284->saved_regs;
    int v291 = v290[8];
    int * v292 = v284->regs;
    v292[8] = v291;
    int * v294 = v284->saved_regs;
    int v295 = v294[5];
    int * v296 = v284->regs;
    v296[5] = v295;
    v301 = v284;
  } else {
    struct StateT * v299 = slot_8(v284);
    v301 = v299;
  }
  return v301;
}

struct StateT * slot_5(struct StateT * v73) {
  int * v74 = v73->saved_regs;
  int * v75 = v73->regs;
  int v76 = v75[5];
  v74[5] = v76;
  int v78 = v73->timer;
  int v192 = v78 + 1;
  v73->timer = v192;
  int * v80 = v73->regs;
  int v81 = v80[8];
  int * v82 = v73->cache_tags;
  int v196 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
  int v83 = v82[v196];
  int v197 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + 1;
  int v84 = v82[v197];
  int v198 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
  int v85 = v82[v198];
  int v199 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v86 = v82[v199];
  int v87 = v73->timer;
  int v200 = v87 + ((100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)))));
  v73->timer = v200;
  int * v89 = v73->cache_vals;
  bool v201 = !(((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
  int v182;
  if (v201) {
    int * v90 = v73->cache_age;
    int v203 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
    int v91 = v90[v203];
    int v92 = v90[v196];
    int v204 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
    v90[v196] = v204;
    int * v94 = v73->cache_age;
    int v95 = v94[v197];
    int v206 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
    v94[v197] = v206;
    int * v97 = v73->cache_age;
    v97[v203] = 0;
    v182 = v203;
  } else {
    int * v100 = v73->cache_age;
    int v210 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
    int v101 = v100[v210];
    int * v102 = v73->cache_tags;
    int v103 = v102[v210];
    int v104 = v100[v197];
    int v105 = v102[v197];
    bool v212 = !(((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
    int v159;
    if (v212) {
      int * v106 = v73->cache_age;
      int v214 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
      int v107 = v106[v214];
      int v108 = v106[v198];
      int v215 = v108 + ((int)((unsigned int)(v108 - v107) >> 31));
      v106[v198] = v215;
      int * v110 = v73->cache_age;
      int v111 = v110[v199];
      int v217 = v111 + ((int)((unsigned int)(v111 - v107) >> 31));
      v110[v199] = v217;
      int * v113 = v73->cache_age;
      v113[v214] = 0;
      v159 = v214;
    } else {
      int * v116 = v73->cache_age;
      int v221 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
      int v117 = v116[v221];
      int * v118 = v73->cache_tags;
      int v119 = v118[v221];
      int v120 = v116[v199];
      int v121 = v118[v199];
      int * v122 = v73->cache_dirty;
      int v224 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v123 = v122[v224];
      bool v225 = !(v123 == 0);
      if (v225) {
        int * v124 = v73->cache_tags;
        int v125 = v124[v224];
        int * v126 = v73->cache_vals;
        int v228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v127 = v126[v228];
        int v229 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v128 = v126[v229];
        int * v129 = v73->mem;
        int v231 = v125 * 2;
        v129[v231] = v127;
        int * v131 = v73->mem;
        int v234 = (v125 * 2) + 1;
        v131[v234] = v128;
        ;
      } else {
        ;
      }
      int * v136 = v73->mem;
      int v239 = ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2;
      int v137 = v136[v239];
      int v240 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2) + 1;
      int v138 = v136[v240];
      int * v139 = v73->cache_vals;
      int v242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v139[v242] = v137;
      int * v141 = v73->cache_vals;
      int v245 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v141[v245] = v138;
      int * v143 = v73->cache_tags;
      int v248 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
      v143[v224] = v248;
      int * v145 = v73->cache_dirty;
      v145[v224] = 0;
      int * v147 = v73->cache_age;
      v147[v224] = 1;
      int * v149 = v73->cache_age;
      int v150 = v149[v224];
      int v151 = v149[v198];
      int v254 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
      v149[v198] = v254;
      int * v153 = v73->cache_age;
      int v154 = v153[v199];
      int v256 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
      v153[v199] = v256;
      int * v156 = v73->cache_age;
      v156[v224] = 0;
      v159 = v224;
    }
    int * v160 = v73->cache_vals;
    int v259 = v159 * 2;
    int v161 = v160[v259];
    int v260 = (v159 * 2) + 1;
    int v162 = v160[v260];
    int v261 = (((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v261] = v161;
    int * v164 = v73->cache_vals;
    int v264 = ((((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v264] = v162;
    int * v166 = v73->cache_tags;
    int v267 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v268 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
    v166[v267] = v268;
    int * v168 = v73->cache_dirty;
    v168[v267] = 0;
    int * v170 = v73->cache_age;
    v170[v267] = 1;
    int * v172 = v73->cache_age;
    int v173 = v172[v267];
    int v174 = v172[v196];
    int v274 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
    v172[v196] = v274;
    int * v176 = v73->cache_age;
    int v177 = v176[v197];
    int v276 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
    v176[v197] = v276;
    int * v179 = v73->cache_age;
    v179[v267] = 0;
    v182 = v267;
  }
  int v279 = (v182 * 2) + (((int)((unsigned int)v81 >> 2)) & 1);
  int v183 = v89[v279];
  int * v184 = v73->regs;
  v184[5] = v183;
  struct StateT * v186 = slot_6(v73);
  return v186;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v838) {
  int v839 = v838->timer;
  int v846 = v839 + 1;
  v838->timer = v846;
  int * v841 = v838->regs;
  int v842 = v841[6];
  int v849 = v842 + 4;
  v841[6] = v849;
  struct StateT * v844 = slot_11(v838);
  return v844;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v319) {
  int v320 = v319->timer;
  int v490 = v320 + 1;
  v319->timer = v490;
  int * v322 = v319->regs;
  int v323 = v322[6];
  int v324 = v322[5];
  int * v325 = v319->cache_tags;
  int v495 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2;
  int v326 = v325[v495];
  int v496 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + 1;
  int v327 = v325[v496];
  int v497 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
  int v328 = v325[v497];
  int v498 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v329 = v325[v498];
  int v330 = v319->timer;
  int v499 = v330 + ((100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & 104)))));
  v319->timer = v499;
  bool v500 = !(((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
  int v424;
  if (v500) {
    int * v332 = v319->cache_age;
    int v502 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
    int v333 = v332[v502];
    int v334 = v332[v495];
    int v503 = v334 + ((int)((unsigned int)(v334 - v333) >> 31));
    v332[v495] = v503;
    int * v336 = v319->cache_age;
    int v337 = v336[v496];
    int v505 = v337 + ((int)((unsigned int)(v337 - v333) >> 31));
    v336[v496] = v505;
    int * v339 = v319->cache_age;
    v339[v502] = 0;
    v424 = v502;
  } else {
    int * v342 = v319->cache_age;
    int v509 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2;
    int v343 = v342[v509];
    int * v344 = v319->cache_tags;
    int v345 = v344[v509];
    int v346 = v342[v496];
    int v347 = v344[v496];
    bool v511 = !(((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
    int v401;
    if (v511) {
      int * v348 = v319->cache_age;
      int v513 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
      int v349 = v348[v513];
      int v350 = v348[v497];
      int v514 = v350 + ((int)((unsigned int)(v350 - v349) >> 31));
      v348[v497] = v514;
      int * v352 = v319->cache_age;
      int v353 = v352[v498];
      int v516 = v353 + ((int)((unsigned int)(v353 - v349) >> 31));
      v352[v498] = v516;
      int * v355 = v319->cache_age;
      v355[v513] = 0;
      v401 = v513;
    } else {
      int * v358 = v319->cache_age;
      int v520 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
      int v359 = v358[v520];
      int * v360 = v319->cache_tags;
      int v361 = v360[v520];
      int v362 = v358[v498];
      int v363 = v360[v498];
      int * v364 = v319->cache_dirty;
      int v523 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v365 = v364[v523];
      bool v524 = !(v365 == 0);
      if (v524) {
        int * v366 = v319->cache_tags;
        int v367 = v366[v523];
        int * v368 = v319->cache_vals;
        int v527 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v369 = v368[v527];
        int v528 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v370 = v368[v528];
        int * v371 = v319->mem;
        int v530 = v367 * 2;
        v371[v530] = v369;
        int * v373 = v319->mem;
        int v533 = (v367 * 2) + 1;
        v373[v533] = v370;
        ;
      } else {
        ;
      }
      int * v378 = v319->mem;
      int v538 = ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2;
      int v379 = v378[v538];
      int v539 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2) + 1;
      int v380 = v378[v539];
      int * v381 = v319->cache_vals;
      int v541 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v381[v541] = v379;
      int * v383 = v319->cache_vals;
      int v544 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v383[v544] = v380;
      int * v385 = v319->cache_tags;
      int v547 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
      v385[v523] = v547;
      int * v387 = v319->cache_dirty;
      v387[v523] = 0;
      int * v389 = v319->cache_age;
      v389[v523] = 1;
      int * v391 = v319->cache_age;
      int v392 = v391[v523];
      int v393 = v391[v497];
      int v553 = v393 + ((int)((unsigned int)(v393 - v392) >> 31));
      v391[v497] = v553;
      int * v395 = v319->cache_age;
      int v396 = v395[v498];
      int v555 = v396 + ((int)((unsigned int)(v396 - v392) >> 31));
      v395[v498] = v555;
      int * v398 = v319->cache_age;
      v398[v523] = 0;
      v401 = v523;
    }
    int * v402 = v319->cache_vals;
    int v558 = v401 * 2;
    int v403 = v402[v558];
    int v559 = (v401 * 2) + 1;
    int v404 = v402[v559];
    int v560 = (((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v402[v560] = v403;
    int * v406 = v319->cache_vals;
    int v563 = ((((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v406[v563] = v404;
    int * v408 = v319->cache_tags;
    int v566 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v567 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
    v408[v566] = v567;
    int * v410 = v319->cache_dirty;
    v410[v566] = 0;
    int * v412 = v319->cache_age;
    v412[v566] = 1;
    int * v414 = v319->cache_age;
    int v415 = v414[v566];
    int v416 = v414[v495];
    int v573 = v416 + ((int)((unsigned int)(v416 - v415) >> 31));
    v414[v495] = v573;
    int * v418 = v319->cache_age;
    int v419 = v418[v496];
    int v575 = v419 + ((int)((unsigned int)(v419 - v415) >> 31));
    v418[v496] = v575;
    int * v421 = v319->cache_age;
    v421[v566] = 0;
    v424 = v566;
  }
  int * v425 = v319->cache_vals;
  int v578 = (v424 * 2) + (((int)((unsigned int)v323 >> 2)) & 1);
  v425[v578] = v324;
  int * v427 = v319->cache_tags;
  int v428 = v427[v497];
  int v429 = v427[v498];
  bool v581 = !(((~(((v428 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v428 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
  int v483;
  if (v581) {
    int * v430 = v319->cache_age;
    int v583 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
    int v431 = v430[v583];
    int v432 = v430[v497];
    int v584 = v432 + ((int)((unsigned int)(v432 - v431) >> 31));
    v430[v497] = v584;
    int * v434 = v319->cache_age;
    int v435 = v434[v498];
    int v586 = v435 + ((int)((unsigned int)(v435 - v431) >> 31));
    v434[v498] = v586;
    int * v437 = v319->cache_age;
    v437[v583] = 0;
    v483 = v583;
  } else {
    int * v440 = v319->cache_age;
    int v590 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
    int v441 = v440[v590];
    int * v442 = v319->cache_tags;
    int v443 = v442[v590];
    int v444 = v440[v498];
    int v445 = v442[v498];
    int * v446 = v319->cache_dirty;
    int v593 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v447 = v446[v593];
    bool v594 = !(v447 == 0);
    if (v594) {
      int * v448 = v319->cache_tags;
      int v449 = v448[v593];
      int * v450 = v319->cache_vals;
      int v597 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v451 = v450[v597];
      int v598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v452 = v450[v598];
      int * v453 = v319->mem;
      int v600 = v449 * 2;
      v453[v600] = v451;
      int * v455 = v319->mem;
      int v603 = (v449 * 2) + 1;
      v455[v603] = v452;
      ;
    } else {
      ;
    }
    int * v460 = v319->mem;
    int v608 = ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2;
    int v461 = v460[v608];
    int v609 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2) + 1;
    int v462 = v460[v609];
    int * v463 = v319->cache_vals;
    int v611 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v463[v611] = v461;
    int * v465 = v319->cache_vals;
    int v614 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v465[v614] = v462;
    int * v467 = v319->cache_tags;
    int v617 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
    v467[v593] = v617;
    int * v469 = v319->cache_dirty;
    v469[v593] = 0;
    int * v471 = v319->cache_age;
    v471[v593] = 1;
    int * v473 = v319->cache_age;
    int v474 = v473[v593];
    int v475 = v473[v497];
    int v623 = v475 + ((int)((unsigned int)(v475 - v474) >> 31));
    v473[v497] = v623;
    int * v477 = v319->cache_age;
    int v478 = v477[v498];
    int v625 = v478 + ((int)((unsigned int)(v478 - v474) >> 31));
    v477[v498] = v625;
    int * v480 = v319->cache_age;
    v480[v593] = 0;
    v483 = v593;
  }
  int * v484 = v319->cache_vals;
  int v628 = (v483 * 2) + (((int)((unsigned int)v323 >> 2)) & 1);
  v484[v628] = v324;
  int * v486 = v319->cache_dirty;
  v486[v483] = 1;
  struct StateT * v488 = slot_9(v319);
  return v488;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[8];
  v50[8] = v52;
  int v54 = v49->timer;
  int v66 = v54 + 1;
  v49->timer = v66;
  int * v56 = v49->regs;
  int v57 = v56[9];
  int v58 = v56[6];
  int v70 = v57 + v58;
  v56[8] = v70;
  struct StateT * v60 = slot_5(v49);
  return v60;
}

struct StateT * slot_9(struct StateT * v634) {
  int v635 = v634->timer;
  int v745 = v635 + 1;
  v634->timer = v745;
  int * v637 = v634->regs;
  int v638 = v637[6];
  int * v639 = v634->cache_tags;
  int v749 = (((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2;
  int v640 = v639[v749];
  int v750 = ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + 1;
  int v641 = v639[v750];
  int v751 = 4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2);
  int v642 = v639[v751];
  int v752 = (4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v643 = v639[v752];
  int v644 = v634->timer;
  int v753 = v644 + ((100 ^ (((~(((v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) & 104)))));
  v634->timer = v753;
  int * v646 = v634->cache_vals;
  bool v754 = !(((~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) == 0);
  int v739;
  if (v754) {
    int * v647 = v634->cache_age;
    int v756 = ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) & 1);
    int v648 = v647[v756];
    int v649 = v647[v749];
    int v757 = v649 + ((int)((unsigned int)(v649 - v648) >> 31));
    v647[v749] = v757;
    int * v651 = v634->cache_age;
    int v652 = v651[v750];
    int v759 = v652 + ((int)((unsigned int)(v652 - v648) >> 31));
    v651[v750] = v759;
    int * v654 = v634->cache_age;
    v654[v756] = 0;
    v739 = v756;
  } else {
    int * v657 = v634->cache_age;
    int v763 = (((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2;
    int v658 = v657[v763];
    int * v659 = v634->cache_tags;
    int v660 = v659[v763];
    int v661 = v657[v750];
    int v662 = v659[v750];
    bool v765 = !(((~(((v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) == 0);
    int v716;
    if (v765) {
      int * v663 = v634->cache_age;
      int v767 = (4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) & 1);
      int v664 = v663[v767];
      int v665 = v663[v751];
      int v768 = v665 + ((int)((unsigned int)(v665 - v664) >> 31));
      v663[v751] = v768;
      int * v667 = v634->cache_age;
      int v668 = v667[v752];
      int v770 = v668 + ((int)((unsigned int)(v668 - v664) >> 31));
      v667[v752] = v770;
      int * v670 = v634->cache_age;
      v670[v767] = 0;
      v716 = v767;
    } else {
      int * v673 = v634->cache_age;
      int v774 = 4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2);
      int v674 = v673[v774];
      int * v675 = v634->cache_tags;
      int v676 = v675[v774];
      int v677 = v673[v752];
      int v678 = v675[v752];
      int * v679 = v634->cache_dirty;
      int v777 = (4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v680 = v679[v777];
      bool v778 = !(v680 == 0);
      if (v778) {
        int * v681 = v634->cache_tags;
        int v682 = v681[v777];
        int * v683 = v634->cache_vals;
        int v781 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v684 = v683[v781];
        int v782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v685 = v683[v782];
        int * v686 = v634->mem;
        int v784 = v682 * 2;
        v686[v784] = v684;
        int * v688 = v634->mem;
        int v787 = (v682 * 2) + 1;
        v688[v787] = v685;
        ;
      } else {
        ;
      }
      int * v693 = v634->mem;
      int v792 = ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) * 2;
      int v694 = v693[v792];
      int v793 = (((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) * 2) + 1;
      int v695 = v693[v793];
      int * v696 = v634->cache_vals;
      int v795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v696[v795] = v694;
      int * v698 = v634->cache_vals;
      int v798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v698[v798] = v695;
      int * v700 = v634->cache_tags;
      int v801 = (int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1);
      v700[v777] = v801;
      int * v702 = v634->cache_dirty;
      v702[v777] = 0;
      int * v704 = v634->cache_age;
      v704[v777] = 1;
      int * v706 = v634->cache_age;
      int v707 = v706[v777];
      int v708 = v706[v751];
      int v807 = v708 + ((int)((unsigned int)(v708 - v707) >> 31));
      v706[v751] = v807;
      int * v710 = v634->cache_age;
      int v711 = v710[v752];
      int v809 = v711 + ((int)((unsigned int)(v711 - v707) >> 31));
      v710[v752] = v809;
      int * v713 = v634->cache_age;
      v713[v777] = 0;
      v716 = v777;
    }
    int * v717 = v634->cache_vals;
    int v812 = v716 * 2;
    int v718 = v717[v812];
    int v813 = (v716 * 2) + 1;
    int v719 = v717[v813];
    int v814 = (((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((((v658 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2)) - (v661 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v717[v814] = v718;
    int * v721 = v634->cache_vals;
    int v817 = ((((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((((v658 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2)) - (v661 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v721[v817] = v719;
    int * v723 = v634->cache_tags;
    int v820 = ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((((v658 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2)) - (v661 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v821 = (int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1);
    v723[v820] = v821;
    int * v725 = v634->cache_dirty;
    v725[v820] = 0;
    int * v727 = v634->cache_age;
    v727[v820] = 1;
    int * v729 = v634->cache_age;
    int v730 = v729[v820];
    int v731 = v729[v749];
    int v827 = v731 + ((int)((unsigned int)(v731 - v730) >> 31));
    v729[v749] = v827;
    int * v733 = v634->cache_age;
    int v734 = v733[v750];
    int v829 = v734 + ((int)((unsigned int)(v734 - v730) >> 31));
    v733[v750] = v829;
    int * v736 = v634->cache_age;
    v736[v820] = 0;
    v739 = v820;
  }
  int v832 = (v739 * 2) + (((int)((unsigned int)v638 >> 2)) & 1);
  int v740 = v646[v832];
  int * v741 = v634->regs;
  v741[11] = v740;
  struct StateT * v743 = slot_10(v634);
  return v743;
}

struct StateT * slot_11(struct StateT * v852) {
  int v853 = v852->timer;
  int v857 = v853 + 1;
  v852->timer = v857;
  struct StateT * v855 = slot_3(v852);
  return v855;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
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