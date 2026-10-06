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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v693);
struct StateT2 * slot_6(struct StateT2 * v634);
struct StateT2 * slot_5(struct StateT2 * v570);
struct StateT2 * slot_4(struct StateT2 * v516);
struct StateT2 * slot_2(struct StateT2 * v456);
struct StateT2 * slot_3(struct StateT2 * v492);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v269 = v40 == v42;
  squared_assert(v269);
  squared_assume(v269);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v271 = v46 + 1;
  v45->timer = v271;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v273 = v49 + 1;
  v48->timer = v273;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  int v53 = v52[12];
  int * v54 = v51->cache_tags;
  int v278 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2;
  int v55 = v54[v278];
  int v279 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + 1;
  int v56 = v54[v279];
  int v280 = 4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2);
  int v57 = v54[v280];
  int v281 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v58 = v54[v281];
  int v59 = v51->timer;
  int v282 = v59 + ((100 ^ (((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & 104)))));
  v51->timer = v282;
  int * v61 = v51->cache_vals;
  bool v283 = !(((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) == 0);
  int v154;
  if (v283) {
    int * v62 = v51->cache_age;
    int v285 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) & 1);
    int v63 = v62[v285];
    int v64 = v62[v278];
    int v286 = v64 + ((int)((unsigned int)(v64 - v63) >> 31));
    v62[v278] = v286;
    int * v66 = v51->cache_age;
    int v67 = v66[v279];
    int v288 = v67 + ((int)((unsigned int)(v67 - v63) >> 31));
    v66[v279] = v288;
    int * v69 = v51->cache_age;
    v69[v285] = 0;
    v154 = v285;
  } else {
    int * v72 = v51->cache_age;
    int v292 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2;
    int v73 = v72[v292];
    int * v74 = v51->cache_tags;
    int v75 = v74[v292];
    int v76 = v72[v279];
    int v77 = v74[v279];
    bool v294 = !(((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) == 0);
    int v131;
    if (v294) {
      int * v78 = v51->cache_age;
      int v296 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) & 1);
      int v79 = v78[v296];
      int v80 = v78[v280];
      int v297 = v80 + ((int)((unsigned int)(v80 - v79) >> 31));
      v78[v280] = v297;
      int * v82 = v51->cache_age;
      int v83 = v82[v281];
      int v299 = v83 + ((int)((unsigned int)(v83 - v79) >> 31));
      v82[v281] = v299;
      int * v85 = v51->cache_age;
      v85[v296] = 0;
      v131 = v296;
    } else {
      int * v88 = v51->cache_age;
      int v303 = 4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2);
      int v89 = v88[v303];
      int * v90 = v51->cache_tags;
      int v91 = v90[v303];
      int v92 = v88[v281];
      int v93 = v90[v281];
      int * v94 = v51->cache_dirty;
      int v306 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v89 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v95 = v94[v306];
      bool v307 = !(v95 == 0);
      if (v307) {
        int * v96 = v51->cache_tags;
        int v97 = v96[v306];
        int * v98 = v51->cache_vals;
        int v310 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v89 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v99 = v98[v310];
        int v311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v89 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v100 = v98[v311];
        int * v101 = v51->mem;
        int v313 = v97 * 2;
        v101[v313] = v99;
        int * v103 = v51->mem;
        int v316 = (v97 * 2) + 1;
        v103[v316] = v100;
        ;
      } else {
        ;
      }
      int * v108 = v51->mem;
      int v321 = ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) * 2;
      int v109 = v108[v321];
      int v322 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) * 2) + 1;
      int v110 = v108[v322];
      int * v111 = v51->cache_vals;
      int v324 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v89 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v111[v324] = v109;
      int * v113 = v51->cache_vals;
      int v327 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v89 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2)) - (v92 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v113[v327] = v110;
      int * v115 = v51->cache_tags;
      int v330 = (int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1);
      v115[v306] = v330;
      int * v117 = v51->cache_dirty;
      v117[v306] = 0;
      int * v119 = v51->cache_age;
      v119[v306] = 1;
      int * v121 = v51->cache_age;
      int v122 = v121[v306];
      int v123 = v121[v280];
      int v336 = v123 + ((int)((unsigned int)(v123 - v122) >> 31));
      v121[v280] = v336;
      int * v125 = v51->cache_age;
      int v126 = v125[v281];
      int v338 = v126 + ((int)((unsigned int)(v126 - v122) >> 31));
      v125[v281] = v338;
      int * v128 = v51->cache_age;
      v128[v306] = 0;
      v131 = v306;
    }
    int * v132 = v51->cache_vals;
    int v341 = v131 * 2;
    int v133 = v132[v341];
    int v342 = (v131 * 2) + 1;
    int v134 = v132[v342];
    int v343 = (((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v132[v343] = v133;
    int * v136 = v51->cache_vals;
    int v346 = ((((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v136[v346] = v134;
    int * v138 = v51->cache_tags;
    int v349 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v350 = (int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1);
    v138[v349] = v350;
    int * v140 = v51->cache_dirty;
    v140[v349] = 0;
    int * v142 = v51->cache_age;
    v142[v349] = 1;
    int * v144 = v51->cache_age;
    int v145 = v144[v349];
    int v146 = v144[v278];
    int v356 = v146 + ((int)((unsigned int)(v146 - v145) >> 31));
    v144[v278] = v356;
    int * v148 = v51->cache_age;
    int v149 = v148[v279];
    int v358 = v149 + ((int)((unsigned int)(v149 - v145) >> 31));
    v148[v279] = v358;
    int * v151 = v51->cache_age;
    v151[v349] = 0;
    v154 = v349;
  }
  int v361 = (v154 * 2) + (((int)((unsigned int)v53 >> 2)) & 1);
  int v155 = v61[v361];
  int * v156 = v51->regs;
  v156[16] = v155;
  struct StateT * v158 = v38->b;
  int * v159 = v158->regs;
  int v160 = v159[12];
  int * v161 = v158->cache_tags;
  int v368 = (((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2;
  int v162 = v161[v368];
  int v369 = ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2) + 1;
  int v163 = v161[v369];
  int v370 = 4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2);
  int v164 = v161[v370];
  int v371 = (4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v165 = v161[v371];
  int v166 = v158->timer;
  int v372 = v166 + ((100 ^ (((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v162 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v162 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31))) & 104)))));
  v158->timer = v372;
  int * v168 = v158->cache_vals;
  bool v373 = !(((~(((v162 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v162 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31))) == 0);
  int v261;
  if (v373) {
    int * v169 = v158->cache_age;
    int v375 = ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2) + ((~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) & 1);
    int v170 = v169[v375];
    int v171 = v169[v368];
    int v376 = v171 + ((int)((unsigned int)(v171 - v170) >> 31));
    v169[v368] = v376;
    int * v173 = v158->cache_age;
    int v174 = v173[v369];
    int v378 = v174 + ((int)((unsigned int)(v174 - v170) >> 31));
    v173[v369] = v378;
    int * v176 = v158->cache_age;
    v176[v375] = 0;
    v261 = v375;
  } else {
    int * v179 = v158->cache_age;
    int v382 = (((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2;
    int v180 = v179[v382];
    int * v181 = v158->cache_tags;
    int v182 = v181[v382];
    int v183 = v179[v369];
    int v184 = v181[v369];
    bool v384 = !(((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31))) == 0);
    int v238;
    if (v384) {
      int * v185 = v158->cache_age;
      int v386 = (4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + ((~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1))))) >> 31)) & 1);
      int v186 = v185[v386];
      int v187 = v185[v370];
      int v387 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
      v185[v370] = v387;
      int * v189 = v158->cache_age;
      int v190 = v189[v371];
      int v389 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
      v189[v371] = v389;
      int * v192 = v158->cache_age;
      v192[v386] = 0;
      v238 = v386;
    } else {
      int * v195 = v158->cache_age;
      int v393 = 4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2);
      int v196 = v195[v393];
      int * v197 = v158->cache_tags;
      int v198 = v197[v393];
      int v199 = v195[v371];
      int v200 = v197[v371];
      int * v201 = v158->cache_dirty;
      int v396 = (4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v202 = v201[v396];
      bool v397 = !(v202 == 0);
      if (v397) {
        int * v203 = v158->cache_tags;
        int v204 = v203[v396];
        int * v205 = v158->cache_vals;
        int v400 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v206 = v205[v400];
        int v401 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v207 = v205[v401];
        int * v208 = v158->mem;
        int v403 = v204 * 2;
        v208[v403] = v206;
        int * v210 = v158->mem;
        int v406 = (v204 * 2) + 1;
        v210[v406] = v207;
        ;
      } else {
        ;
      }
      int * v215 = v158->mem;
      int v411 = ((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) * 2;
      int v216 = v215[v411];
      int v412 = (((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) * 2) + 1;
      int v217 = v215[v412];
      int * v218 = v158->cache_vals;
      int v414 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v218[v414] = v216;
      int * v220 = v158->cache_vals;
      int v417 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v220[v417] = v217;
      int * v222 = v158->cache_tags;
      int v420 = (int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1);
      v222[v396] = v420;
      int * v224 = v158->cache_dirty;
      v224[v396] = 0;
      int * v226 = v158->cache_age;
      v226[v396] = 1;
      int * v228 = v158->cache_age;
      int v229 = v228[v396];
      int v230 = v228[v370];
      int v426 = v230 + ((int)((unsigned int)(v230 - v229) >> 31));
      v228[v370] = v426;
      int * v232 = v158->cache_age;
      int v233 = v232[v371];
      int v428 = v233 + ((int)((unsigned int)(v233 - v229) >> 31));
      v232[v371] = v428;
      int * v235 = v158->cache_age;
      v235[v396] = 0;
      v238 = v396;
    }
    int * v239 = v158->cache_vals;
    int v431 = v238 * 2;
    int v240 = v239[v431];
    int v432 = (v238 * 2) + 1;
    int v241 = v239[v432];
    int v433 = (((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2) + ((((v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2)) - (v183 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v239[v433] = v240;
    int * v243 = v158->cache_vals;
    int v436 = ((((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2) + ((((v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2)) - (v183 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v243[v436] = v241;
    int * v245 = v158->cache_tags;
    int v439 = ((((int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1)) & 1) * 2) + ((((v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2)) - (v183 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v440 = (int)((unsigned int)((int)((unsigned int)v160 >> 2)) >> 1);
    v245[v439] = v440;
    int * v247 = v158->cache_dirty;
    v247[v439] = 0;
    int * v249 = v158->cache_age;
    v249[v439] = 1;
    int * v251 = v158->cache_age;
    int v252 = v251[v439];
    int v253 = v251[v368];
    int v446 = v253 + ((int)((unsigned int)(v253 - v252) >> 31));
    v251[v368] = v446;
    int * v255 = v158->cache_age;
    int v256 = v255[v369];
    int v448 = v256 + ((int)((unsigned int)(v256 - v252) >> 31));
    v255[v369] = v448;
    int * v258 = v158->cache_age;
    v258[v439] = 0;
    v261 = v439;
  }
  int v451 = (v261 * 2) + (((int)((unsigned int)v160 >> 2)) & 1);
  int v262 = v168[v451];
  int * v263 = v158->regs;
  v263[16] = v262;
  struct StateT2 * v265 = slot_2(v38);
  return v265;
}

struct StateT2 * slot_8(struct StateT2 * v693) {
  struct StateT * v694 = v693->a;
  int v695 = v694->timer;
  struct StateT * v696 = v693->b;
  int v697 = v696->timer;
  bool v711 = v695 == v697;
  squared_assert(v711);
  squared_assume(v711);
  struct StateT * v700 = v693->a;
  int v701 = v700->timer;
  int v713 = v701 + 1;
  v700->timer = v713;
  struct StateT * v703 = v693->b;
  int v704 = v703->timer;
  int v715 = v704 + 1;
  v703->timer = v715;
  return v693;
}

struct StateT2 * slot_6(struct StateT2 * v634) {
  struct StateT * v635 = v634->a;
  int v636 = v635->timer;
  struct StateT * v637 = v634->b;
  int v638 = v637->timer;
  bool v657 = v636 == v638;
  squared_assert(v657);
  squared_assume(v657);
  struct StateT * v641 = v634->a;
  int v642 = v641->timer;
  int v659 = v642 + 1;
  v641->timer = v659;
  struct StateT * v644 = v634->b;
  int v645 = v644->timer;
  int v661 = v645 + 1;
  v644->timer = v661;
  struct StateT * v647 = v634->a;
  int * v648 = v647->regs;
  v648[18] = 2;
  struct StateT * v650 = v634->b;
  int * v651 = v650->regs;
  v651[18] = 2;
  struct StateT2 * v653 = slot_8(v634);
  return v653;
}

struct StateT2 * slot_5(struct StateT2 * v570) {
  struct StateT * v571 = v570->a;
  int v572 = v571->timer;
  struct StateT * v573 = v570->b;
  int v574 = v573->timer;
  bool v609 = v572 == v574;
  squared_assert(v609);
  squared_assume(v609);
  struct StateT * v577 = v570->a;
  int * v578 = v577->regs;
  int v579 = v578[16];
  int v580 = v578[17];
  struct StateT * v581 = v570->b;
  int * v582 = v581->regs;
  int v583 = v582[16];
  int v584 = v582[17];
  bool v616 = (v579 < v580) == (v583 < v584);
  squared_diverged(v616);
  squared_assume(v616);
  bool v617 = v579 < v580;
  struct StateT2 * v605;
  if (v617) {
    struct StateT * v587 = v570->a;
    int v588 = v587->timer;
    int v619 = v588 + 15;
    v587->timer = v619;
    int * v590 = v587->saved_regs;
    int v591 = v590[18];
    int * v592 = v587->regs;
    v592[18] = v591;
    struct StateT * v594 = v570->b;
    int v595 = v594->timer;
    int v625 = v595 + 15;
    v594->timer = v625;
    int * v597 = v594->saved_regs;
    int v598 = v597[18];
    int * v599 = v594->regs;
    v599[18] = v598;
    struct StateT2 * v601 = slot_6(v570);
    v605 = v601;
  } else {
    struct StateT2 * v603 = slot_8(v570);
    v605 = v603;
  }
  return v605;
}

struct StateT2 * slot_4(struct StateT2 * v516) {
  struct StateT * v517 = v516->a;
  int v518 = v517->timer;
  struct StateT * v519 = v516->b;
  int v520 = v519->timer;
  bool v549 = v518 == v520;
  squared_assert(v549);
  squared_assume(v549);
  struct StateT * v523 = v516->a;
  int * v524 = v523->saved_regs;
  int * v525 = v523->regs;
  int v526 = v525[18];
  v524[18] = v526;
  struct StateT * v528 = v516->b;
  int * v529 = v528->saved_regs;
  int * v530 = v528->regs;
  int v531 = v530[18];
  v529[18] = v531;
  struct StateT * v533 = v516->a;
  int v534 = v533->timer;
  int v560 = v534 + 1;
  v533->timer = v560;
  struct StateT * v536 = v516->b;
  int v537 = v536->timer;
  int v562 = v537 + 1;
  v536->timer = v562;
  struct StateT * v539 = v516->a;
  int * v540 = v539->regs;
  v540[18] = 1;
  struct StateT * v542 = v516->b;
  int * v543 = v542->regs;
  v543[18] = 1;
  struct StateT2 * v545 = slot_5(v516);
  return v545;
}

struct StateT2 * slot_2(struct StateT2 * v456) {
  struct StateT * v457 = v456->a;
  int v458 = v457->timer;
  struct StateT * v459 = v456->b;
  int v460 = v459->timer;
  bool v479 = v458 == v460;
  squared_assert(v479);
  squared_assume(v479);
  struct StateT * v463 = v456->a;
  int v464 = v463->timer;
  int v481 = v464 + 1;
  v463->timer = v481;
  struct StateT * v466 = v456->b;
  int v467 = v466->timer;
  int v483 = v467 + 1;
  v466->timer = v483;
  struct StateT * v469 = v456->a;
  int * v470 = v469->regs;
  v470[17] = 10;
  struct StateT * v472 = v456->b;
  int * v473 = v472->regs;
  v473[17] = 10;
  struct StateT2 * v475 = slot_3(v456);
  return v475;
}

struct StateT2 * slot_3(struct StateT2 * v492) {
  struct StateT * v493 = v492->a;
  int v494 = v493->timer;
  struct StateT * v495 = v492->b;
  int v496 = v495->timer;
  bool v509 = v494 == v496;
  squared_assert(v509);
  squared_assume(v509);
  struct StateT * v499 = v492->a;
  int v500 = v499->timer;
  int v511 = v500 + 1;
  v499->timer = v511;
  struct StateT * v502 = v492->b;
  int v503 = v502->timer;
  int v513 = v503 + 1;
  v502->timer = v513;
  struct StateT2 * v505 = slot_4(v492);
  return v505;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[12] = 80;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 80;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}