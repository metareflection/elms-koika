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

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v1657);
struct StateT2 * slot_6(struct StateT2 * v1200);
struct StateT2 * slot_5(struct StateT2 * v1164);
struct StateT2 * slot_4(struct StateT2 * v528);
struct StateT2 * slot_2(struct StateT2 * v456);
struct StateT2 * slot_7(struct StateT2 * v1239);
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
  int v53 = v52[6];
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
  v156[5] = v155;
  struct StateT * v158 = v38->b;
  int * v159 = v158->regs;
  int v160 = v159[6];
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
  v263[5] = v262;
  struct StateT2 * v265 = slot_2(v38);
  return v265;
}

struct StateT2 * slot_8(struct StateT2 * v1657) {
  struct StateT * v1658 = v1657->a;
  int v1659 = v1658->timer;
  struct StateT * v1660 = v1657->b;
  int v1661 = v1660->timer;
  bool v1887 = v1659 == v1661;
  squared_assert(v1887);
  squared_assume(v1887);
  struct StateT * v1664 = v1657->a;
  int v1665 = v1664->timer;
  int v1889 = v1665 + 1;
  v1664->timer = v1889;
  struct StateT * v1667 = v1657->b;
  int v1668 = v1667->timer;
  int v1891 = v1668 + 1;
  v1667->timer = v1891;
  struct StateT * v1670 = v1657->a;
  int * v1671 = v1670->regs;
  int v1672 = v1671[11];
  int * v1673 = v1670->cache_tags;
  int v1896 = (((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2;
  int v1674 = v1673[v1896];
  int v1897 = ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1675 = v1673[v1897];
  int v1898 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2);
  int v1676 = v1673[v1898];
  int v1899 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1677 = v1673[v1899];
  int v1678 = v1670->timer;
  int v1900 = v1678 + ((100 ^ (((~(((v1676 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1676 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) | (~(((v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1674 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1674 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) | (~(((v1675 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1675 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1676 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1676 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) | (~(((v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1670->timer = v1900;
  int * v1680 = v1670->cache_vals;
  bool v1901 = !(((~(((v1674 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1674 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) | (~(((v1675 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1675 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31))) == 0);
  int v1773;
  if (v1901) {
    int * v1681 = v1670->cache_age;
    int v1903 = ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2) + ((~(((v1675 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1675 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) & 1);
    int v1682 = v1681[v1903];
    int v1683 = v1681[v1896];
    int v1904 = v1683 + ((int)((unsigned int)(v1683 - v1682) >> 31));
    v1681[v1896] = v1904;
    int * v1685 = v1670->cache_age;
    int v1686 = v1685[v1897];
    int v1906 = v1686 + ((int)((unsigned int)(v1686 - v1682) >> 31));
    v1685[v1897] = v1906;
    int * v1688 = v1670->cache_age;
    v1688[v1903] = 0;
    v1773 = v1903;
  } else {
    int * v1691 = v1670->cache_age;
    int v1910 = (((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2;
    int v1692 = v1691[v1910];
    int * v1693 = v1670->cache_tags;
    int v1694 = v1693[v1910];
    int v1695 = v1691[v1897];
    int v1696 = v1693[v1897];
    bool v1912 = !(((~(((v1676 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1676 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) | (~(((v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31))) == 0);
    int v1750;
    if (v1912) {
      int * v1697 = v1670->cache_age;
      int v1914 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))) | (-(v1677 ^ ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1))))) >> 31)) & 1);
      int v1698 = v1697[v1914];
      int v1699 = v1697[v1898];
      int v1915 = v1699 + ((int)((unsigned int)(v1699 - v1698) >> 31));
      v1697[v1898] = v1915;
      int * v1701 = v1670->cache_age;
      int v1702 = v1701[v1899];
      int v1917 = v1702 + ((int)((unsigned int)(v1702 - v1698) >> 31));
      v1701[v1899] = v1917;
      int * v1704 = v1670->cache_age;
      v1704[v1914] = 0;
      v1750 = v1914;
    } else {
      int * v1707 = v1670->cache_age;
      int v1921 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2);
      int v1708 = v1707[v1921];
      int * v1709 = v1670->cache_tags;
      int v1710 = v1709[v1921];
      int v1711 = v1707[v1899];
      int v1712 = v1709[v1899];
      int * v1713 = v1670->cache_dirty;
      int v1924 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + ((((v1708 + ((~(((v1710 ^ -1) | (-(v1710 ^ -1))) >> 31)) & 2)) - (v1711 + ((~(((v1712 ^ -1) | (-(v1712 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1714 = v1713[v1924];
      bool v1925 = !(v1714 == 0);
      if (v1925) {
        int * v1715 = v1670->cache_tags;
        int v1716 = v1715[v1924];
        int * v1717 = v1670->cache_vals;
        int v1928 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + ((((v1708 + ((~(((v1710 ^ -1) | (-(v1710 ^ -1))) >> 31)) & 2)) - (v1711 + ((~(((v1712 ^ -1) | (-(v1712 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1718 = v1717[v1928];
        int v1929 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + ((((v1708 + ((~(((v1710 ^ -1) | (-(v1710 ^ -1))) >> 31)) & 2)) - (v1711 + ((~(((v1712 ^ -1) | (-(v1712 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1719 = v1717[v1929];
        int * v1720 = v1670->mem;
        int v1931 = v1716 * 2;
        v1720[v1931] = v1718;
        int * v1722 = v1670->mem;
        int v1934 = (v1716 * 2) + 1;
        v1722[v1934] = v1719;
        ;
      } else {
        ;
      }
      int * v1727 = v1670->mem;
      int v1939 = ((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) * 2;
      int v1728 = v1727[v1939];
      int v1940 = (((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) * 2) + 1;
      int v1729 = v1727[v1940];
      int * v1730 = v1670->cache_vals;
      int v1942 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + ((((v1708 + ((~(((v1710 ^ -1) | (-(v1710 ^ -1))) >> 31)) & 2)) - (v1711 + ((~(((v1712 ^ -1) | (-(v1712 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1730[v1942] = v1728;
      int * v1732 = v1670->cache_vals;
      int v1945 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 3) * 2)) + ((((v1708 + ((~(((v1710 ^ -1) | (-(v1710 ^ -1))) >> 31)) & 2)) - (v1711 + ((~(((v1712 ^ -1) | (-(v1712 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1732[v1945] = v1729;
      int * v1734 = v1670->cache_tags;
      int v1948 = (int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1);
      v1734[v1924] = v1948;
      int * v1736 = v1670->cache_dirty;
      v1736[v1924] = 0;
      int * v1738 = v1670->cache_age;
      v1738[v1924] = 1;
      int * v1740 = v1670->cache_age;
      int v1741 = v1740[v1924];
      int v1742 = v1740[v1898];
      int v1954 = v1742 + ((int)((unsigned int)(v1742 - v1741) >> 31));
      v1740[v1898] = v1954;
      int * v1744 = v1670->cache_age;
      int v1745 = v1744[v1899];
      int v1956 = v1745 + ((int)((unsigned int)(v1745 - v1741) >> 31));
      v1744[v1899] = v1956;
      int * v1747 = v1670->cache_age;
      v1747[v1924] = 0;
      v1750 = v1924;
    }
    int * v1751 = v1670->cache_vals;
    int v1959 = v1750 * 2;
    int v1752 = v1751[v1959];
    int v1960 = (v1750 * 2) + 1;
    int v1753 = v1751[v1960];
    int v1961 = (((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2) + ((((v1692 + ((~(((v1694 ^ -1) | (-(v1694 ^ -1))) >> 31)) & 2)) - (v1695 + ((~(((v1696 ^ -1) | (-(v1696 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1751[v1961] = v1752;
    int * v1755 = v1670->cache_vals;
    int v1964 = ((((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2) + ((((v1692 + ((~(((v1694 ^ -1) | (-(v1694 ^ -1))) >> 31)) & 2)) - (v1695 + ((~(((v1696 ^ -1) | (-(v1696 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1755[v1964] = v1753;
    int * v1757 = v1670->cache_tags;
    int v1967 = ((((int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1)) & 1) * 2) + ((((v1692 + ((~(((v1694 ^ -1) | (-(v1694 ^ -1))) >> 31)) & 2)) - (v1695 + ((~(((v1696 ^ -1) | (-(v1696 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1968 = (int)((unsigned int)((int)((unsigned int)v1672 >> 2)) >> 1);
    v1757[v1967] = v1968;
    int * v1759 = v1670->cache_dirty;
    v1759[v1967] = 0;
    int * v1761 = v1670->cache_age;
    v1761[v1967] = 1;
    int * v1763 = v1670->cache_age;
    int v1764 = v1763[v1967];
    int v1765 = v1763[v1896];
    int v1974 = v1765 + ((int)((unsigned int)(v1765 - v1764) >> 31));
    v1763[v1896] = v1974;
    int * v1767 = v1670->cache_age;
    int v1768 = v1767[v1897];
    int v1976 = v1768 + ((int)((unsigned int)(v1768 - v1764) >> 31));
    v1767[v1897] = v1976;
    int * v1770 = v1670->cache_age;
    v1770[v1967] = 0;
    v1773 = v1967;
  }
  int v1979 = (v1773 * 2) + (((int)((unsigned int)v1672 >> 2)) & 1);
  int v1774 = v1680[v1979];
  int * v1775 = v1670->regs;
  v1775[12] = v1774;
  struct StateT * v1777 = v1657->b;
  int * v1778 = v1777->regs;
  int v1779 = v1778[11];
  int * v1780 = v1777->cache_tags;
  int v1986 = (((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2;
  int v1781 = v1780[v1986];
  int v1987 = ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1782 = v1780[v1987];
  int v1988 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2);
  int v1783 = v1780[v1988];
  int v1989 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1784 = v1780[v1989];
  int v1785 = v1777->timer;
  int v1990 = v1785 + ((100 ^ (((~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) | (~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) | (~(((v1782 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1782 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) | (~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1777->timer = v1990;
  int * v1787 = v1777->cache_vals;
  bool v1991 = !(((~(((v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1781 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) | (~(((v1782 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1782 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31))) == 0);
  int v1880;
  if (v1991) {
    int * v1788 = v1777->cache_age;
    int v1993 = ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2) + ((~(((v1782 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1782 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) & 1);
    int v1789 = v1788[v1993];
    int v1790 = v1788[v1986];
    int v1994 = v1790 + ((int)((unsigned int)(v1790 - v1789) >> 31));
    v1788[v1986] = v1994;
    int * v1792 = v1777->cache_age;
    int v1793 = v1792[v1987];
    int v1996 = v1793 + ((int)((unsigned int)(v1793 - v1789) >> 31));
    v1792[v1987] = v1996;
    int * v1795 = v1777->cache_age;
    v1795[v1993] = 0;
    v1880 = v1993;
  } else {
    int * v1798 = v1777->cache_age;
    int v2000 = (((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2;
    int v1799 = v1798[v2000];
    int * v1800 = v1777->cache_tags;
    int v1801 = v1800[v2000];
    int v1802 = v1798[v1987];
    int v1803 = v1800[v1987];
    bool v2002 = !(((~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) | (~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31))) == 0);
    int v1857;
    if (v2002) {
      int * v1804 = v1777->cache_age;
      int v2004 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1))))) >> 31)) & 1);
      int v1805 = v1804[v2004];
      int v1806 = v1804[v1988];
      int v2005 = v1806 + ((int)((unsigned int)(v1806 - v1805) >> 31));
      v1804[v1988] = v2005;
      int * v1808 = v1777->cache_age;
      int v1809 = v1808[v1989];
      int v2007 = v1809 + ((int)((unsigned int)(v1809 - v1805) >> 31));
      v1808[v1989] = v2007;
      int * v1811 = v1777->cache_age;
      v1811[v2004] = 0;
      v1857 = v2004;
    } else {
      int * v1814 = v1777->cache_age;
      int v2011 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2);
      int v1815 = v1814[v2011];
      int * v1816 = v1777->cache_tags;
      int v1817 = v1816[v2011];
      int v1818 = v1814[v1989];
      int v1819 = v1816[v1989];
      int * v1820 = v1777->cache_dirty;
      int v2014 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + ((((v1815 + ((~(((v1817 ^ -1) | (-(v1817 ^ -1))) >> 31)) & 2)) - (v1818 + ((~(((v1819 ^ -1) | (-(v1819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1821 = v1820[v2014];
      bool v2015 = !(v1821 == 0);
      if (v2015) {
        int * v1822 = v1777->cache_tags;
        int v1823 = v1822[v2014];
        int * v1824 = v1777->cache_vals;
        int v2018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + ((((v1815 + ((~(((v1817 ^ -1) | (-(v1817 ^ -1))) >> 31)) & 2)) - (v1818 + ((~(((v1819 ^ -1) | (-(v1819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1825 = v1824[v2018];
        int v2019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + ((((v1815 + ((~(((v1817 ^ -1) | (-(v1817 ^ -1))) >> 31)) & 2)) - (v1818 + ((~(((v1819 ^ -1) | (-(v1819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1826 = v1824[v2019];
        int * v1827 = v1777->mem;
        int v2021 = v1823 * 2;
        v1827[v2021] = v1825;
        int * v1829 = v1777->mem;
        int v2024 = (v1823 * 2) + 1;
        v1829[v2024] = v1826;
        ;
      } else {
        ;
      }
      int * v1834 = v1777->mem;
      int v2029 = ((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) * 2;
      int v1835 = v1834[v2029];
      int v2030 = (((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) * 2) + 1;
      int v1836 = v1834[v2030];
      int * v1837 = v1777->cache_vals;
      int v2032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + ((((v1815 + ((~(((v1817 ^ -1) | (-(v1817 ^ -1))) >> 31)) & 2)) - (v1818 + ((~(((v1819 ^ -1) | (-(v1819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1837[v2032] = v1835;
      int * v1839 = v1777->cache_vals;
      int v2035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 3) * 2)) + ((((v1815 + ((~(((v1817 ^ -1) | (-(v1817 ^ -1))) >> 31)) & 2)) - (v1818 + ((~(((v1819 ^ -1) | (-(v1819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1839[v2035] = v1836;
      int * v1841 = v1777->cache_tags;
      int v2038 = (int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1);
      v1841[v2014] = v2038;
      int * v1843 = v1777->cache_dirty;
      v1843[v2014] = 0;
      int * v1845 = v1777->cache_age;
      v1845[v2014] = 1;
      int * v1847 = v1777->cache_age;
      int v1848 = v1847[v2014];
      int v1849 = v1847[v1988];
      int v2044 = v1849 + ((int)((unsigned int)(v1849 - v1848) >> 31));
      v1847[v1988] = v2044;
      int * v1851 = v1777->cache_age;
      int v1852 = v1851[v1989];
      int v2046 = v1852 + ((int)((unsigned int)(v1852 - v1848) >> 31));
      v1851[v1989] = v2046;
      int * v1854 = v1777->cache_age;
      v1854[v2014] = 0;
      v1857 = v2014;
    }
    int * v1858 = v1777->cache_vals;
    int v2049 = v1857 * 2;
    int v1859 = v1858[v2049];
    int v2050 = (v1857 * 2) + 1;
    int v1860 = v1858[v2050];
    int v2051 = (((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2) + ((((v1799 + ((~(((v1801 ^ -1) | (-(v1801 ^ -1))) >> 31)) & 2)) - (v1802 + ((~(((v1803 ^ -1) | (-(v1803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1858[v2051] = v1859;
    int * v1862 = v1777->cache_vals;
    int v2054 = ((((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2) + ((((v1799 + ((~(((v1801 ^ -1) | (-(v1801 ^ -1))) >> 31)) & 2)) - (v1802 + ((~(((v1803 ^ -1) | (-(v1803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1862[v2054] = v1860;
    int * v1864 = v1777->cache_tags;
    int v2057 = ((((int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1)) & 1) * 2) + ((((v1799 + ((~(((v1801 ^ -1) | (-(v1801 ^ -1))) >> 31)) & 2)) - (v1802 + ((~(((v1803 ^ -1) | (-(v1803 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2058 = (int)((unsigned int)((int)((unsigned int)v1779 >> 2)) >> 1);
    v1864[v2057] = v2058;
    int * v1866 = v1777->cache_dirty;
    v1866[v2057] = 0;
    int * v1868 = v1777->cache_age;
    v1868[v2057] = 1;
    int * v1870 = v1777->cache_age;
    int v1871 = v1870[v2057];
    int v1872 = v1870[v1986];
    int v2064 = v1872 + ((int)((unsigned int)(v1872 - v1871) >> 31));
    v1870[v1986] = v2064;
    int * v1874 = v1777->cache_age;
    int v1875 = v1874[v1987];
    int v2066 = v1875 + ((int)((unsigned int)(v1875 - v1871) >> 31));
    v1874[v1987] = v2066;
    int * v1877 = v1777->cache_age;
    v1877[v2057] = 0;
    v1880 = v2057;
  }
  int v2069 = (v1880 * 2) + (((int)((unsigned int)v1779 >> 2)) & 1);
  int v1881 = v1787[v2069];
  int * v1882 = v1777->regs;
  v1882[12] = v1881;
  return v1657;
}

struct StateT2 * slot_6(struct StateT2 * v1200) {
  struct StateT * v1201 = v1200->a;
  int v1202 = v1201->timer;
  struct StateT * v1203 = v1200->b;
  int v1204 = v1203->timer;
  bool v1225 = v1202 == v1204;
  squared_assert(v1225);
  squared_assume(v1225);
  struct StateT * v1207 = v1200->a;
  int v1208 = v1207->timer;
  int v1227 = v1208 + 1;
  v1207->timer = v1227;
  struct StateT * v1210 = v1200->b;
  int v1211 = v1210->timer;
  int v1229 = v1211 + 1;
  v1210->timer = v1229;
  struct StateT * v1213 = v1200->a;
  int * v1214 = v1213->regs;
  int v1215 = v1214[7];
  int v1233 = v1215 + 1;
  v1214[7] = v1233;
  struct StateT * v1217 = v1200->b;
  int * v1218 = v1217->regs;
  int v1219 = v1218[7];
  int v1236 = v1219 + 1;
  v1218[7] = v1236;
  struct StateT2 * v1221 = slot_7(v1200);
  return v1221;
}

struct StateT2 * slot_5(struct StateT2 * v1164) {
  struct StateT * v1165 = v1164->a;
  int v1166 = v1165->timer;
  struct StateT * v1167 = v1164->b;
  int v1168 = v1167->timer;
  bool v1187 = v1166 == v1168;
  squared_assert(v1187);
  squared_assume(v1187);
  struct StateT * v1171 = v1164->a;
  int v1172 = v1171->timer;
  int v1189 = v1172 + 1;
  v1171->timer = v1189;
  struct StateT * v1174 = v1164->b;
  int v1175 = v1174->timer;
  int v1191 = v1175 + 1;
  v1174->timer = v1191;
  struct StateT * v1177 = v1164->a;
  int * v1178 = v1177->regs;
  v1178[7] = 0;
  struct StateT * v1180 = v1164->b;
  int * v1181 = v1180->regs;
  v1181[7] = 0;
  struct StateT2 * v1183 = slot_6(v1164);
  return v1183;
}

struct StateT2 * slot_4(struct StateT2 * v528) {
  struct StateT * v529 = v528->a;
  int v530 = v529->timer;
  struct StateT * v531 = v528->b;
  int v532 = v531->timer;
  bool v879 = v530 == v532;
  squared_assert(v879);
  squared_assume(v879);
  struct StateT * v535 = v528->a;
  int v536 = v535->timer;
  int v881 = v536 + 1;
  v535->timer = v881;
  struct StateT * v538 = v528->b;
  int v539 = v538->timer;
  int v883 = v539 + 1;
  v538->timer = v883;
  struct StateT * v541 = v528->a;
  int * v542 = v541->regs;
  int v543 = v542[8];
  int v544 = v542[5];
  int * v545 = v541->cache_tags;
  int v889 = (((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2;
  int v546 = v545[v889];
  int v890 = ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2) + 1;
  int v547 = v545[v890];
  int v891 = 4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2);
  int v548 = v545[v891];
  int v892 = (4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v549 = v545[v892];
  int v550 = v541->timer;
  int v893 = v550 + ((100 ^ (((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) | (~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31))) & 104)))));
  v541->timer = v893;
  bool v894 = !(((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) | (~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31))) == 0);
  int v644;
  if (v894) {
    int * v552 = v541->cache_age;
    int v896 = ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2) + ((~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) & 1);
    int v553 = v552[v896];
    int v554 = v552[v889];
    int v897 = v554 + ((int)((unsigned int)(v554 - v553) >> 31));
    v552[v889] = v897;
    int * v556 = v541->cache_age;
    int v557 = v556[v890];
    int v899 = v557 + ((int)((unsigned int)(v557 - v553) >> 31));
    v556[v890] = v899;
    int * v559 = v541->cache_age;
    v559[v896] = 0;
    v644 = v896;
  } else {
    int * v562 = v541->cache_age;
    int v903 = (((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2;
    int v563 = v562[v903];
    int * v564 = v541->cache_tags;
    int v565 = v564[v903];
    int v566 = v562[v890];
    int v567 = v564[v890];
    bool v905 = !(((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31))) == 0);
    int v621;
    if (v905) {
      int * v568 = v541->cache_age;
      int v907 = (4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) & 1);
      int v569 = v568[v907];
      int v570 = v568[v891];
      int v908 = v570 + ((int)((unsigned int)(v570 - v569) >> 31));
      v568[v891] = v908;
      int * v572 = v541->cache_age;
      int v573 = v572[v892];
      int v910 = v573 + ((int)((unsigned int)(v573 - v569) >> 31));
      v572[v892] = v910;
      int * v575 = v541->cache_age;
      v575[v907] = 0;
      v621 = v907;
    } else {
      int * v578 = v541->cache_age;
      int v914 = 4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2);
      int v579 = v578[v914];
      int * v580 = v541->cache_tags;
      int v581 = v580[v914];
      int v582 = v578[v892];
      int v583 = v580[v892];
      int * v584 = v541->cache_dirty;
      int v917 = (4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v579 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v585 = v584[v917];
      bool v918 = !(v585 == 0);
      if (v918) {
        int * v586 = v541->cache_tags;
        int v587 = v586[v917];
        int * v588 = v541->cache_vals;
        int v921 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v579 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v589 = v588[v921];
        int v922 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v579 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v590 = v588[v922];
        int * v591 = v541->mem;
        int v924 = v587 * 2;
        v591[v924] = v589;
        int * v593 = v541->mem;
        int v927 = (v587 * 2) + 1;
        v593[v927] = v590;
        ;
      } else {
        ;
      }
      int * v598 = v541->mem;
      int v932 = ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) * 2;
      int v599 = v598[v932];
      int v933 = (((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) * 2) + 1;
      int v600 = v598[v933];
      int * v601 = v541->cache_vals;
      int v935 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v579 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v601[v935] = v599;
      int * v603 = v541->cache_vals;
      int v938 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v579 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v603[v938] = v600;
      int * v605 = v541->cache_tags;
      int v941 = (int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1);
      v605[v917] = v941;
      int * v607 = v541->cache_dirty;
      v607[v917] = 0;
      int * v609 = v541->cache_age;
      v609[v917] = 1;
      int * v611 = v541->cache_age;
      int v612 = v611[v917];
      int v613 = v611[v891];
      int v947 = v613 + ((int)((unsigned int)(v613 - v612) >> 31));
      v611[v891] = v947;
      int * v615 = v541->cache_age;
      int v616 = v615[v892];
      int v949 = v616 + ((int)((unsigned int)(v616 - v612) >> 31));
      v615[v892] = v949;
      int * v618 = v541->cache_age;
      v618[v917] = 0;
      v621 = v917;
    }
    int * v622 = v541->cache_vals;
    int v952 = v621 * 2;
    int v623 = v622[v952];
    int v953 = (v621 * 2) + 1;
    int v624 = v622[v953];
    int v954 = (((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2) + ((((v563 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2)) - (v566 + ((~(((v567 ^ -1) | (-(v567 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v622[v954] = v623;
    int * v626 = v541->cache_vals;
    int v957 = ((((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2) + ((((v563 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2)) - (v566 + ((~(((v567 ^ -1) | (-(v567 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v626[v957] = v624;
    int * v628 = v541->cache_tags;
    int v960 = ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 1) * 2) + ((((v563 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2)) - (v566 + ((~(((v567 ^ -1) | (-(v567 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v961 = (int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1);
    v628[v960] = v961;
    int * v630 = v541->cache_dirty;
    v630[v960] = 0;
    int * v632 = v541->cache_age;
    v632[v960] = 1;
    int * v634 = v541->cache_age;
    int v635 = v634[v960];
    int v636 = v634[v889];
    int v967 = v636 + ((int)((unsigned int)(v636 - v635) >> 31));
    v634[v889] = v967;
    int * v638 = v541->cache_age;
    int v639 = v638[v890];
    int v969 = v639 + ((int)((unsigned int)(v639 - v635) >> 31));
    v638[v890] = v969;
    int * v641 = v541->cache_age;
    v641[v960] = 0;
    v644 = v960;
  }
  int * v645 = v541->cache_vals;
  int v972 = (v644 * 2) + (((int)((unsigned int)v543 >> 2)) & 1);
  v645[v972] = v544;
  int * v647 = v541->cache_tags;
  int v648 = v647[v891];
  int v649 = v647[v892];
  bool v975 = !(((~(((v648 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v648 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) | (~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31))) == 0);
  int v703;
  if (v975) {
    int * v650 = v541->cache_age;
    int v977 = (4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1))))) >> 31)) & 1);
    int v651 = v650[v977];
    int v652 = v650[v891];
    int v978 = v652 + ((int)((unsigned int)(v652 - v651) >> 31));
    v650[v891] = v978;
    int * v654 = v541->cache_age;
    int v655 = v654[v892];
    int v980 = v655 + ((int)((unsigned int)(v655 - v651) >> 31));
    v654[v892] = v980;
    int * v657 = v541->cache_age;
    v657[v977] = 0;
    v703 = v977;
  } else {
    int * v660 = v541->cache_age;
    int v984 = 4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2);
    int v661 = v660[v984];
    int * v662 = v541->cache_tags;
    int v663 = v662[v984];
    int v664 = v660[v892];
    int v665 = v662[v892];
    int * v666 = v541->cache_dirty;
    int v987 = (4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v667 = v666[v987];
    bool v988 = !(v667 == 0);
    if (v988) {
      int * v668 = v541->cache_tags;
      int v669 = v668[v987];
      int * v670 = v541->cache_vals;
      int v991 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v671 = v670[v991];
      int v992 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v672 = v670[v992];
      int * v673 = v541->mem;
      int v994 = v669 * 2;
      v673[v994] = v671;
      int * v675 = v541->mem;
      int v997 = (v669 * 2) + 1;
      v675[v997] = v672;
      ;
    } else {
      ;
    }
    int * v680 = v541->mem;
    int v1002 = ((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) * 2;
    int v681 = v680[v1002];
    int v1003 = (((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) * 2) + 1;
    int v682 = v680[v1003];
    int * v683 = v541->cache_vals;
    int v1005 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v683[v1005] = v681;
    int * v685 = v541->cache_vals;
    int v1008 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1)) & 3) * 2)) + ((((v661 + ((~(((v663 ^ -1) | (-(v663 ^ -1))) >> 31)) & 2)) - (v664 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v685[v1008] = v682;
    int * v687 = v541->cache_tags;
    int v1011 = (int)((unsigned int)((int)((unsigned int)v543 >> 2)) >> 1);
    v687[v987] = v1011;
    int * v689 = v541->cache_dirty;
    v689[v987] = 0;
    int * v691 = v541->cache_age;
    v691[v987] = 1;
    int * v693 = v541->cache_age;
    int v694 = v693[v987];
    int v695 = v693[v891];
    int v1017 = v695 + ((int)((unsigned int)(v695 - v694) >> 31));
    v693[v891] = v1017;
    int * v697 = v541->cache_age;
    int v698 = v697[v892];
    int v1019 = v698 + ((int)((unsigned int)(v698 - v694) >> 31));
    v697[v892] = v1019;
    int * v700 = v541->cache_age;
    v700[v987] = 0;
    v703 = v987;
  }
  int * v704 = v541->cache_vals;
  int v1022 = (v703 * 2) + (((int)((unsigned int)v543 >> 2)) & 1);
  v704[v1022] = v544;
  int * v706 = v541->cache_dirty;
  v706[v703] = 1;
  struct StateT * v708 = v528->b;
  int * v709 = v708->regs;
  int v710 = v709[8];
  int v711 = v709[5];
  int * v712 = v708->cache_tags;
  int v1029 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
  int v713 = v712[v1029];
  int v1030 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + 1;
  int v714 = v712[v1030];
  int v1031 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
  int v715 = v712[v1031];
  int v1032 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v716 = v712[v1032];
  int v717 = v708->timer;
  int v1033 = v717 + ((100 ^ (((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)))));
  v708->timer = v1033;
  bool v1034 = !(((~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
  int v811;
  if (v1034) {
    int * v719 = v708->cache_age;
    int v1036 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
    int v720 = v719[v1036];
    int v721 = v719[v1029];
    int v1037 = v721 + ((int)((unsigned int)(v721 - v720) >> 31));
    v719[v1029] = v1037;
    int * v723 = v708->cache_age;
    int v724 = v723[v1030];
    int v1039 = v724 + ((int)((unsigned int)(v724 - v720) >> 31));
    v723[v1030] = v1039;
    int * v726 = v708->cache_age;
    v726[v1036] = 0;
    v811 = v1036;
  } else {
    int * v729 = v708->cache_age;
    int v1043 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
    int v730 = v729[v1043];
    int * v731 = v708->cache_tags;
    int v732 = v731[v1043];
    int v733 = v729[v1030];
    int v734 = v731[v1030];
    bool v1045 = !(((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
    int v788;
    if (v1045) {
      int * v735 = v708->cache_age;
      int v1047 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((~(((v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v716 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
      int v736 = v735[v1047];
      int v737 = v735[v1031];
      int v1048 = v737 + ((int)((unsigned int)(v737 - v736) >> 31));
      v735[v1031] = v1048;
      int * v739 = v708->cache_age;
      int v740 = v739[v1032];
      int v1050 = v740 + ((int)((unsigned int)(v740 - v736) >> 31));
      v739[v1032] = v1050;
      int * v742 = v708->cache_age;
      v742[v1047] = 0;
      v788 = v1047;
    } else {
      int * v745 = v708->cache_age;
      int v1054 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
      int v746 = v745[v1054];
      int * v747 = v708->cache_tags;
      int v748 = v747[v1054];
      int v749 = v745[v1032];
      int v750 = v747[v1032];
      int * v751 = v708->cache_dirty;
      int v1057 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v752 = v751[v1057];
      bool v1058 = !(v752 == 0);
      if (v1058) {
        int * v753 = v708->cache_tags;
        int v754 = v753[v1057];
        int * v755 = v708->cache_vals;
        int v1061 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v756 = v755[v1061];
        int v1062 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v757 = v755[v1062];
        int * v758 = v708->mem;
        int v1064 = v754 * 2;
        v758[v1064] = v756;
        int * v760 = v708->mem;
        int v1067 = (v754 * 2) + 1;
        v760[v1067] = v757;
        ;
      } else {
        ;
      }
      int * v765 = v708->mem;
      int v1072 = ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2;
      int v766 = v765[v1072];
      int v1073 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2) + 1;
      int v767 = v765[v1073];
      int * v768 = v708->cache_vals;
      int v1075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v768[v1075] = v766;
      int * v770 = v708->cache_vals;
      int v1078 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v770[v1078] = v767;
      int * v772 = v708->cache_tags;
      int v1081 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
      v772[v1057] = v1081;
      int * v774 = v708->cache_dirty;
      v774[v1057] = 0;
      int * v776 = v708->cache_age;
      v776[v1057] = 1;
      int * v778 = v708->cache_age;
      int v779 = v778[v1057];
      int v780 = v778[v1031];
      int v1086 = v780 + ((int)((unsigned int)(v780 - v779) >> 31));
      v778[v1031] = v1086;
      int * v782 = v708->cache_age;
      int v783 = v782[v1032];
      int v1088 = v783 + ((int)((unsigned int)(v783 - v779) >> 31));
      v782[v1032] = v1088;
      int * v785 = v708->cache_age;
      v785[v1057] = 0;
      v788 = v1057;
    }
    int * v789 = v708->cache_vals;
    int v1091 = v788 * 2;
    int v790 = v789[v1091];
    int v1092 = (v788 * 2) + 1;
    int v791 = v789[v1092];
    int v1093 = (((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v789[v1093] = v790;
    int * v793 = v708->cache_vals;
    int v1096 = ((((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v793[v1096] = v791;
    int * v795 = v708->cache_tags;
    int v1099 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1100 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
    v795[v1099] = v1100;
    int * v797 = v708->cache_dirty;
    v797[v1099] = 0;
    int * v799 = v708->cache_age;
    v799[v1099] = 1;
    int * v801 = v708->cache_age;
    int v802 = v801[v1099];
    int v803 = v801[v1029];
    int v1105 = v803 + ((int)((unsigned int)(v803 - v802) >> 31));
    v801[v1029] = v1105;
    int * v805 = v708->cache_age;
    int v806 = v805[v1030];
    int v1107 = v806 + ((int)((unsigned int)(v806 - v802) >> 31));
    v805[v1030] = v1107;
    int * v808 = v708->cache_age;
    v808[v1099] = 0;
    v811 = v1099;
  }
  int * v812 = v708->cache_vals;
  int v1110 = (v811 * 2) + (((int)((unsigned int)v710 >> 2)) & 1);
  v812[v1110] = v711;
  int * v814 = v708->cache_tags;
  int v815 = v814[v1031];
  int v816 = v814[v1032];
  bool v1113 = !(((~(((v815 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v815 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v816 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v816 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
  int v870;
  if (v1113) {
    int * v817 = v708->cache_age;
    int v1115 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((~(((v816 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v816 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
    int v818 = v817[v1115];
    int v819 = v817[v1031];
    int v1116 = v819 + ((int)((unsigned int)(v819 - v818) >> 31));
    v817[v1031] = v1116;
    int * v821 = v708->cache_age;
    int v822 = v821[v1032];
    int v1118 = v822 + ((int)((unsigned int)(v822 - v818) >> 31));
    v821[v1032] = v1118;
    int * v824 = v708->cache_age;
    v824[v1115] = 0;
    v870 = v1115;
  } else {
    int * v827 = v708->cache_age;
    int v1122 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
    int v828 = v827[v1122];
    int * v829 = v708->cache_tags;
    int v830 = v829[v1122];
    int v831 = v827[v1032];
    int v832 = v829[v1032];
    int * v833 = v708->cache_dirty;
    int v1125 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v834 = v833[v1125];
    bool v1126 = !(v834 == 0);
    if (v1126) {
      int * v835 = v708->cache_tags;
      int v836 = v835[v1125];
      int * v837 = v708->cache_vals;
      int v1129 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v838 = v837[v1129];
      int v1130 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v839 = v837[v1130];
      int * v840 = v708->mem;
      int v1132 = v836 * 2;
      v840[v1132] = v838;
      int * v842 = v708->mem;
      int v1135 = (v836 * 2) + 1;
      v842[v1135] = v839;
      ;
    } else {
      ;
    }
    int * v847 = v708->mem;
    int v1140 = ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2;
    int v848 = v847[v1140];
    int v1141 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2) + 1;
    int v849 = v847[v1141];
    int * v850 = v708->cache_vals;
    int v1143 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v850[v1143] = v848;
    int * v852 = v708->cache_vals;
    int v1146 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v828 + ((~(((v830 ^ -1) | (-(v830 ^ -1))) >> 31)) & 2)) - (v831 + ((~(((v832 ^ -1) | (-(v832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v852[v1146] = v849;
    int * v854 = v708->cache_tags;
    int v1149 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
    v854[v1125] = v1149;
    int * v856 = v708->cache_dirty;
    v856[v1125] = 0;
    int * v858 = v708->cache_age;
    v858[v1125] = 1;
    int * v860 = v708->cache_age;
    int v861 = v860[v1125];
    int v862 = v860[v1031];
    int v1154 = v862 + ((int)((unsigned int)(v862 - v861) >> 31));
    v860[v1031] = v1154;
    int * v864 = v708->cache_age;
    int v865 = v864[v1032];
    int v1156 = v865 + ((int)((unsigned int)(v865 - v861) >> 31));
    v864[v1032] = v1156;
    int * v867 = v708->cache_age;
    v867[v1125] = 0;
    v870 = v1125;
  }
  int * v871 = v708->cache_vals;
  int v1159 = (v870 * 2) + (((int)((unsigned int)v710 >> 2)) & 1);
  v871[v1159] = v711;
  int * v873 = v708->cache_dirty;
  v873[v870] = 1;
  struct StateT2 * v875 = slot_5(v528);
  return v875;
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
  v470[8] = 96;
  struct StateT * v472 = v456->b;
  int * v473 = v472->regs;
  v473[8] = 96;
  struct StateT2 * v475 = slot_3(v456);
  return v475;
}

struct StateT2 * slot_7(struct StateT2 * v1239) {
  struct StateT * v1240 = v1239->a;
  int v1241 = v1240->timer;
  struct StateT * v1242 = v1239->b;
  int v1243 = v1242->timer;
  bool v1470 = v1241 == v1243;
  squared_assert(v1470);
  squared_assume(v1470);
  struct StateT * v1246 = v1239->a;
  int v1247 = v1246->timer;
  int v1472 = v1247 + 1;
  v1246->timer = v1472;
  struct StateT * v1249 = v1239->b;
  int v1250 = v1249->timer;
  int v1474 = v1250 + 1;
  v1249->timer = v1474;
  struct StateT * v1252 = v1239->a;
  int * v1253 = v1252->regs;
  int v1254 = v1253[9];
  int * v1255 = v1252->cache_tags;
  int v1479 = (((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2;
  int v1256 = v1255[v1479];
  int v1480 = ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1257 = v1255[v1480];
  int v1481 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2);
  int v1258 = v1255[v1481];
  int v1482 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1259 = v1255[v1482];
  int v1260 = v1252->timer;
  int v1483 = v1260 + ((100 ^ (((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1252->timer = v1483;
  int * v1262 = v1252->cache_vals;
  bool v1484 = !(((~(((v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) == 0);
  int v1355;
  if (v1484) {
    int * v1263 = v1252->cache_age;
    int v1486 = ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((~(((v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) & 1);
    int v1264 = v1263[v1486];
    int v1265 = v1263[v1479];
    int v1487 = v1265 + ((int)((unsigned int)(v1265 - v1264) >> 31));
    v1263[v1479] = v1487;
    int * v1267 = v1252->cache_age;
    int v1268 = v1267[v1480];
    int v1489 = v1268 + ((int)((unsigned int)(v1268 - v1264) >> 31));
    v1267[v1480] = v1489;
    int * v1270 = v1252->cache_age;
    v1270[v1486] = 0;
    v1355 = v1486;
  } else {
    int * v1273 = v1252->cache_age;
    int v1493 = (((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2;
    int v1274 = v1273[v1493];
    int * v1275 = v1252->cache_tags;
    int v1276 = v1275[v1493];
    int v1277 = v1273[v1480];
    int v1278 = v1275[v1480];
    bool v1495 = !(((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) == 0);
    int v1332;
    if (v1495) {
      int * v1279 = v1252->cache_age;
      int v1497 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) & 1);
      int v1280 = v1279[v1497];
      int v1281 = v1279[v1481];
      int v1498 = v1281 + ((int)((unsigned int)(v1281 - v1280) >> 31));
      v1279[v1481] = v1498;
      int * v1283 = v1252->cache_age;
      int v1284 = v1283[v1482];
      int v1500 = v1284 + ((int)((unsigned int)(v1284 - v1280) >> 31));
      v1283[v1482] = v1500;
      int * v1286 = v1252->cache_age;
      v1286[v1497] = 0;
      v1332 = v1497;
    } else {
      int * v1289 = v1252->cache_age;
      int v1504 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2);
      int v1290 = v1289[v1504];
      int * v1291 = v1252->cache_tags;
      int v1292 = v1291[v1504];
      int v1293 = v1289[v1482];
      int v1294 = v1291[v1482];
      int * v1295 = v1252->cache_dirty;
      int v1507 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1296 = v1295[v1507];
      bool v1508 = !(v1296 == 0);
      if (v1508) {
        int * v1297 = v1252->cache_tags;
        int v1298 = v1297[v1507];
        int * v1299 = v1252->cache_vals;
        int v1511 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1300 = v1299[v1511];
        int v1512 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1301 = v1299[v1512];
        int * v1302 = v1252->mem;
        int v1514 = v1298 * 2;
        v1302[v1514] = v1300;
        int * v1304 = v1252->mem;
        int v1517 = (v1298 * 2) + 1;
        v1304[v1517] = v1301;
        ;
      } else {
        ;
      }
      int * v1309 = v1252->mem;
      int v1522 = ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) * 2;
      int v1310 = v1309[v1522];
      int v1523 = (((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) * 2) + 1;
      int v1311 = v1309[v1523];
      int * v1312 = v1252->cache_vals;
      int v1525 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1312[v1525] = v1310;
      int * v1314 = v1252->cache_vals;
      int v1528 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1314[v1528] = v1311;
      int * v1316 = v1252->cache_tags;
      int v1531 = (int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1);
      v1316[v1507] = v1531;
      int * v1318 = v1252->cache_dirty;
      v1318[v1507] = 0;
      int * v1320 = v1252->cache_age;
      v1320[v1507] = 1;
      int * v1322 = v1252->cache_age;
      int v1323 = v1322[v1507];
      int v1324 = v1322[v1481];
      int v1537 = v1324 + ((int)((unsigned int)(v1324 - v1323) >> 31));
      v1322[v1481] = v1537;
      int * v1326 = v1252->cache_age;
      int v1327 = v1326[v1482];
      int v1539 = v1327 + ((int)((unsigned int)(v1327 - v1323) >> 31));
      v1326[v1482] = v1539;
      int * v1329 = v1252->cache_age;
      v1329[v1507] = 0;
      v1332 = v1507;
    }
    int * v1333 = v1252->cache_vals;
    int v1542 = v1332 * 2;
    int v1334 = v1333[v1542];
    int v1543 = (v1332 * 2) + 1;
    int v1335 = v1333[v1543];
    int v1544 = (((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((((v1274 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2)) - (v1277 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1333[v1544] = v1334;
    int * v1337 = v1252->cache_vals;
    int v1547 = ((((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((((v1274 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2)) - (v1277 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1337[v1547] = v1335;
    int * v1339 = v1252->cache_tags;
    int v1550 = ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((((v1274 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2)) - (v1277 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1551 = (int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1);
    v1339[v1550] = v1551;
    int * v1341 = v1252->cache_dirty;
    v1341[v1550] = 0;
    int * v1343 = v1252->cache_age;
    v1343[v1550] = 1;
    int * v1345 = v1252->cache_age;
    int v1346 = v1345[v1550];
    int v1347 = v1345[v1479];
    int v1557 = v1347 + ((int)((unsigned int)(v1347 - v1346) >> 31));
    v1345[v1479] = v1557;
    int * v1349 = v1252->cache_age;
    int v1350 = v1349[v1480];
    int v1559 = v1350 + ((int)((unsigned int)(v1350 - v1346) >> 31));
    v1349[v1480] = v1559;
    int * v1352 = v1252->cache_age;
    v1352[v1550] = 0;
    v1355 = v1550;
  }
  int v1562 = (v1355 * 2) + (((int)((unsigned int)v1254 >> 2)) & 1);
  int v1356 = v1262[v1562];
  int * v1357 = v1252->regs;
  v1357[11] = v1356;
  struct StateT * v1359 = v1239->b;
  int * v1360 = v1359->regs;
  int v1361 = v1360[9];
  int * v1362 = v1359->cache_tags;
  int v1569 = (((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2;
  int v1363 = v1362[v1569];
  int v1570 = ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1364 = v1362[v1570];
  int v1571 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2);
  int v1365 = v1362[v1571];
  int v1572 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1366 = v1362[v1572];
  int v1367 = v1359->timer;
  int v1573 = v1367 + ((100 ^ (((~(((v1365 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1365 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) | (~(((v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) | (~(((v1364 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1364 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1365 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1365 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) | (~(((v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1359->timer = v1573;
  int * v1369 = v1359->cache_vals;
  bool v1574 = !(((~(((v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1363 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) | (~(((v1364 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1364 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31))) == 0);
  int v1462;
  if (v1574) {
    int * v1370 = v1359->cache_age;
    int v1576 = ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2) + ((~(((v1364 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1364 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) & 1);
    int v1371 = v1370[v1576];
    int v1372 = v1370[v1569];
    int v1577 = v1372 + ((int)((unsigned int)(v1372 - v1371) >> 31));
    v1370[v1569] = v1577;
    int * v1374 = v1359->cache_age;
    int v1375 = v1374[v1570];
    int v1579 = v1375 + ((int)((unsigned int)(v1375 - v1371) >> 31));
    v1374[v1570] = v1579;
    int * v1377 = v1359->cache_age;
    v1377[v1576] = 0;
    v1462 = v1576;
  } else {
    int * v1380 = v1359->cache_age;
    int v1583 = (((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2;
    int v1381 = v1380[v1583];
    int * v1382 = v1359->cache_tags;
    int v1383 = v1382[v1583];
    int v1384 = v1380[v1570];
    int v1385 = v1382[v1570];
    bool v1585 = !(((~(((v1365 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1365 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) | (~(((v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31))) == 0);
    int v1439;
    if (v1585) {
      int * v1386 = v1359->cache_age;
      int v1587 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))) | (-(v1366 ^ ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1))))) >> 31)) & 1);
      int v1387 = v1386[v1587];
      int v1388 = v1386[v1571];
      int v1588 = v1388 + ((int)((unsigned int)(v1388 - v1387) >> 31));
      v1386[v1571] = v1588;
      int * v1390 = v1359->cache_age;
      int v1391 = v1390[v1572];
      int v1590 = v1391 + ((int)((unsigned int)(v1391 - v1387) >> 31));
      v1390[v1572] = v1590;
      int * v1393 = v1359->cache_age;
      v1393[v1587] = 0;
      v1439 = v1587;
    } else {
      int * v1396 = v1359->cache_age;
      int v1594 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2);
      int v1397 = v1396[v1594];
      int * v1398 = v1359->cache_tags;
      int v1399 = v1398[v1594];
      int v1400 = v1396[v1572];
      int v1401 = v1398[v1572];
      int * v1402 = v1359->cache_dirty;
      int v1597 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + ((((v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2)) - (v1400 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1403 = v1402[v1597];
      bool v1598 = !(v1403 == 0);
      if (v1598) {
        int * v1404 = v1359->cache_tags;
        int v1405 = v1404[v1597];
        int * v1406 = v1359->cache_vals;
        int v1601 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + ((((v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2)) - (v1400 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1407 = v1406[v1601];
        int v1602 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + ((((v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2)) - (v1400 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1408 = v1406[v1602];
        int * v1409 = v1359->mem;
        int v1604 = v1405 * 2;
        v1409[v1604] = v1407;
        int * v1411 = v1359->mem;
        int v1607 = (v1405 * 2) + 1;
        v1411[v1607] = v1408;
        ;
      } else {
        ;
      }
      int * v1416 = v1359->mem;
      int v1612 = ((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) * 2;
      int v1417 = v1416[v1612];
      int v1613 = (((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) * 2) + 1;
      int v1418 = v1416[v1613];
      int * v1419 = v1359->cache_vals;
      int v1615 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + ((((v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2)) - (v1400 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1419[v1615] = v1417;
      int * v1421 = v1359->cache_vals;
      int v1618 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 3) * 2)) + ((((v1397 + ((~(((v1399 ^ -1) | (-(v1399 ^ -1))) >> 31)) & 2)) - (v1400 + ((~(((v1401 ^ -1) | (-(v1401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1421[v1618] = v1418;
      int * v1423 = v1359->cache_tags;
      int v1621 = (int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1);
      v1423[v1597] = v1621;
      int * v1425 = v1359->cache_dirty;
      v1425[v1597] = 0;
      int * v1427 = v1359->cache_age;
      v1427[v1597] = 1;
      int * v1429 = v1359->cache_age;
      int v1430 = v1429[v1597];
      int v1431 = v1429[v1571];
      int v1627 = v1431 + ((int)((unsigned int)(v1431 - v1430) >> 31));
      v1429[v1571] = v1627;
      int * v1433 = v1359->cache_age;
      int v1434 = v1433[v1572];
      int v1629 = v1434 + ((int)((unsigned int)(v1434 - v1430) >> 31));
      v1433[v1572] = v1629;
      int * v1436 = v1359->cache_age;
      v1436[v1597] = 0;
      v1439 = v1597;
    }
    int * v1440 = v1359->cache_vals;
    int v1632 = v1439 * 2;
    int v1441 = v1440[v1632];
    int v1633 = (v1439 * 2) + 1;
    int v1442 = v1440[v1633];
    int v1634 = (((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2) + ((((v1381 + ((~(((v1383 ^ -1) | (-(v1383 ^ -1))) >> 31)) & 2)) - (v1384 + ((~(((v1385 ^ -1) | (-(v1385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1440[v1634] = v1441;
    int * v1444 = v1359->cache_vals;
    int v1637 = ((((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2) + ((((v1381 + ((~(((v1383 ^ -1) | (-(v1383 ^ -1))) >> 31)) & 2)) - (v1384 + ((~(((v1385 ^ -1) | (-(v1385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1444[v1637] = v1442;
    int * v1446 = v1359->cache_tags;
    int v1640 = ((((int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1)) & 1) * 2) + ((((v1381 + ((~(((v1383 ^ -1) | (-(v1383 ^ -1))) >> 31)) & 2)) - (v1384 + ((~(((v1385 ^ -1) | (-(v1385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1641 = (int)((unsigned int)((int)((unsigned int)v1361 >> 2)) >> 1);
    v1446[v1640] = v1641;
    int * v1448 = v1359->cache_dirty;
    v1448[v1640] = 0;
    int * v1450 = v1359->cache_age;
    v1450[v1640] = 1;
    int * v1452 = v1359->cache_age;
    int v1453 = v1452[v1640];
    int v1454 = v1452[v1569];
    int v1647 = v1454 + ((int)((unsigned int)(v1454 - v1453) >> 31));
    v1452[v1569] = v1647;
    int * v1456 = v1359->cache_age;
    int v1457 = v1456[v1570];
    int v1649 = v1457 + ((int)((unsigned int)(v1457 - v1453) >> 31));
    v1456[v1570] = v1649;
    int * v1459 = v1359->cache_age;
    v1459[v1640] = 0;
    v1462 = v1640;
  }
  int v1652 = (v1462 * 2) + (((int)((unsigned int)v1361 >> 2)) & 1);
  int v1463 = v1369[v1652];
  int * v1464 = v1359->regs;
  v1464[11] = v1463;
  struct StateT2 * v1466 = slot_8(v1239);
  return v1466;
}

struct StateT2 * slot_3(struct StateT2 * v492) {
  struct StateT * v493 = v492->a;
  int v494 = v493->timer;
  struct StateT * v495 = v492->b;
  int v496 = v495->timer;
  bool v515 = v494 == v496;
  squared_assert(v515);
  squared_assume(v515);
  struct StateT * v499 = v492->a;
  int v500 = v499->timer;
  int v517 = v500 + 1;
  v499->timer = v517;
  struct StateT * v502 = v492->b;
  int v503 = v502->timer;
  int v519 = v503 + 1;
  v502->timer = v519;
  struct StateT * v505 = v492->a;
  int * v506 = v505->regs;
  v506[9] = 0;
  struct StateT * v508 = v492->b;
  int * v509 = v508->regs;
  v509[9] = 0;
  struct StateT2 * v511 = slot_4(v492);
  return v511;
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
  v16[6] = 80;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[6] = 80;
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