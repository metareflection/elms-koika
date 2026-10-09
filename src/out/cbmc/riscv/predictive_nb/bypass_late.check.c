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

struct StateT * slot_5(struct StateT * v100);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_7(struct StateT * v145);
struct StateT * slot_3(struct StateT * v48);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v693);
struct StateT * slot_1(struct StateT * v24);
struct StateT * slot_8(struct StateT * v464);
struct StateT * slot_4(struct StateT * v77);
struct StateT * slot_9(struct StateT * v672);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v100) {
  int * v101 = v100->regs;
  int v102 = v101[5];
  int v103 = v101[9];
  bool v128 = v102 >= v103;
  struct StateT * v123;
  if (v128) {
    int v104 = v100->timer;
    int v129 = v104 + 15;
    v100->timer = v129;
    int * v106 = v100->saved_regs;
    int v107 = v106[6];
    int * v108 = v100->regs;
    v108[6] = v107;
    int * v110 = v100->saved_regs;
    int v111 = v110[7];
    int * v112 = v100->regs;
    v112[7] = v111;
    int * v114 = v100->reg_ready;
    int v115 = v100->timer;
    v114[6] = v115;
    int * v117 = v100->reg_ready;
    int v118 = v100->timer;
    v117[7] = v118;
    v123 = v100;
  } else {
    struct StateT * v121 = slot_7(v100);
    v123 = v121;
  }
  return v123;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v45 = v41 + 1;
  v40->timer = v45;
  struct StateT * v43 = slot_3(v40);
  return v43;
}

struct StateT * slot_7(struct StateT * v145) {
  int v146 = v145->timer;
  int v319 = v146 + 1;
  v145->timer = v319;
  int * v148 = v145->reg_ready;
  int * v150 = v145->regs;
  int v151 = v150[6];
  int v153 = v150[7];
  int * v154 = v145->cache_tags;
  int v325 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2;
  int v155 = v154[v325];
  int v326 = ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + 1;
  int v156 = v154[v326];
  int v327 = 4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2);
  int v157 = v154[v327];
  int v328 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v158 = v154[v328];
  int v159 = v145->timer;
  int v329 = v159 + ((100 ^ (((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) & 104)))));
  v145->timer = v329;
  bool v330 = !(((~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) == 0);
  int v253;
  if (v330) {
    int * v161 = v145->cache_age;
    int v332 = ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) & 1);
    int v162 = v161[v332];
    int v163 = v161[v325];
    int v333 = v163 + ((int)((unsigned int)(v163 - v162) >> 31));
    v161[v325] = v333;
    int * v165 = v145->cache_age;
    int v166 = v165[v326];
    int v335 = v166 + ((int)((unsigned int)(v166 - v162) >> 31));
    v165[v326] = v335;
    int * v168 = v145->cache_age;
    v168[v332] = 0;
    v253 = v332;
  } else {
    int * v171 = v145->cache_age;
    int v339 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2;
    int v172 = v171[v339];
    int * v173 = v145->cache_tags;
    int v174 = v173[v339];
    int v175 = v171[v326];
    int v176 = v173[v326];
    bool v341 = !(((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) == 0);
    int v230;
    if (v341) {
      int * v177 = v145->cache_age;
      int v343 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) & 1);
      int v178 = v177[v343];
      int v179 = v177[v327];
      int v344 = v179 + ((int)((unsigned int)(v179 - v178) >> 31));
      v177[v327] = v344;
      int * v181 = v145->cache_age;
      int v182 = v181[v328];
      int v346 = v182 + ((int)((unsigned int)(v182 - v178) >> 31));
      v181[v328] = v346;
      int * v184 = v145->cache_age;
      v184[v343] = 0;
      v230 = v343;
    } else {
      int * v187 = v145->cache_age;
      int v350 = 4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2);
      int v188 = v187[v350];
      int * v189 = v145->cache_tags;
      int v190 = v189[v350];
      int v191 = v187[v328];
      int v192 = v189[v328];
      int * v193 = v145->cache_dirty;
      int v353 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v194 = v193[v353];
      bool v354 = !(v194 == 0);
      if (v354) {
        int * v195 = v145->cache_tags;
        int v196 = v195[v353];
        int * v197 = v145->cache_vals;
        int v357 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v198 = v197[v357];
        int v358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v199 = v197[v358];
        int * v200 = v145->mem;
        int v360 = v196 * 2;
        v200[v360] = v198;
        int * v202 = v145->mem;
        int v363 = (v196 * 2) + 1;
        v202[v363] = v199;
        ;
      } else {
        ;
      }
      int * v207 = v145->mem;
      int v368 = ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) * 2;
      int v208 = v207[v368];
      int v369 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) * 2) + 1;
      int v209 = v207[v369];
      int * v210 = v145->cache_vals;
      int v371 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v210[v371] = v208;
      int * v212 = v145->cache_vals;
      int v374 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v212[v374] = v209;
      int * v214 = v145->cache_tags;
      int v377 = (int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1);
      v214[v353] = v377;
      int * v216 = v145->cache_dirty;
      v216[v353] = 0;
      int * v218 = v145->cache_age;
      v218[v353] = 1;
      int * v220 = v145->cache_age;
      int v221 = v220[v353];
      int v222 = v220[v327];
      int v383 = v222 + ((int)((unsigned int)(v222 - v221) >> 31));
      v220[v327] = v383;
      int * v224 = v145->cache_age;
      int v225 = v224[v328];
      int v385 = v225 + ((int)((unsigned int)(v225 - v221) >> 31));
      v224[v328] = v385;
      int * v227 = v145->cache_age;
      v227[v353] = 0;
      v230 = v353;
    }
    int * v231 = v145->cache_vals;
    int v388 = v230 * 2;
    int v232 = v231[v388];
    int v389 = (v230 * 2) + 1;
    int v233 = v231[v389];
    int v390 = (((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((((v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2)) - (v175 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v231[v390] = v232;
    int * v235 = v145->cache_vals;
    int v393 = ((((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((((v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2)) - (v175 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v235[v393] = v233;
    int * v237 = v145->cache_tags;
    int v396 = ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((((v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2)) - (v175 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v397 = (int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1);
    v237[v396] = v397;
    int * v239 = v145->cache_dirty;
    v239[v396] = 0;
    int * v241 = v145->cache_age;
    v241[v396] = 1;
    int * v243 = v145->cache_age;
    int v244 = v243[v396];
    int v245 = v243[v325];
    int v403 = v245 + ((int)((unsigned int)(v245 - v244) >> 31));
    v243[v325] = v403;
    int * v247 = v145->cache_age;
    int v248 = v247[v326];
    int v405 = v248 + ((int)((unsigned int)(v248 - v244) >> 31));
    v247[v326] = v405;
    int * v250 = v145->cache_age;
    v250[v396] = 0;
    v253 = v396;
  }
  int * v254 = v145->cache_vals;
  int v408 = (v253 * 2) + (((int)((unsigned int)v151 >> 2)) & 1);
  v254[v408] = v153;
  int * v256 = v145->cache_tags;
  int v257 = v256[v327];
  int v258 = v256[v328];
  bool v411 = !(((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v258 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v258 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) == 0);
  int v312;
  if (v411) {
    int * v259 = v145->cache_age;
    int v413 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((~(((v258 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v258 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) & 1);
    int v260 = v259[v413];
    int v261 = v259[v327];
    int v414 = v261 + ((int)((unsigned int)(v261 - v260) >> 31));
    v259[v327] = v414;
    int * v263 = v145->cache_age;
    int v264 = v263[v328];
    int v416 = v264 + ((int)((unsigned int)(v264 - v260) >> 31));
    v263[v328] = v416;
    int * v266 = v145->cache_age;
    v266[v413] = 0;
    v312 = v413;
  } else {
    int * v269 = v145->cache_age;
    int v420 = 4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2);
    int v270 = v269[v420];
    int * v271 = v145->cache_tags;
    int v272 = v271[v420];
    int v273 = v269[v328];
    int v274 = v271[v328];
    int * v275 = v145->cache_dirty;
    int v423 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v273 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v276 = v275[v423];
    bool v424 = !(v276 == 0);
    if (v424) {
      int * v277 = v145->cache_tags;
      int v278 = v277[v423];
      int * v279 = v145->cache_vals;
      int v427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v273 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v280 = v279[v427];
      int v428 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v273 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v281 = v279[v428];
      int * v282 = v145->mem;
      int v430 = v278 * 2;
      v282[v430] = v280;
      int * v284 = v145->mem;
      int v433 = (v278 * 2) + 1;
      v284[v433] = v281;
      ;
    } else {
      ;
    }
    int * v289 = v145->mem;
    int v438 = ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) * 2;
    int v290 = v289[v438];
    int v439 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) * 2) + 1;
    int v291 = v289[v439];
    int * v292 = v145->cache_vals;
    int v441 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v273 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v292[v441] = v290;
    int * v294 = v145->cache_vals;
    int v444 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v270 + ((~(((v272 ^ -1) | (-(v272 ^ -1))) >> 31)) & 2)) - (v273 + ((~(((v274 ^ -1) | (-(v274 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v294[v444] = v291;
    int * v296 = v145->cache_tags;
    int v447 = (int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1);
    v296[v423] = v447;
    int * v298 = v145->cache_dirty;
    v298[v423] = 0;
    int * v300 = v145->cache_age;
    v300[v423] = 1;
    int * v302 = v145->cache_age;
    int v303 = v302[v423];
    int v304 = v302[v327];
    int v453 = v304 + ((int)((unsigned int)(v304 - v303) >> 31));
    v302[v327] = v453;
    int * v306 = v145->cache_age;
    int v307 = v306[v328];
    int v455 = v307 + ((int)((unsigned int)(v307 - v303) >> 31));
    v306[v328] = v455;
    int * v309 = v145->cache_age;
    v309[v423] = 0;
    v312 = v423;
  }
  int * v313 = v145->cache_vals;
  int v458 = (v312 * 2) + (((int)((unsigned int)v151 >> 2)) & 1);
  v313[v458] = v153;
  int * v315 = v145->cache_dirty;
  v315[v312] = 1;
  struct StateT * v317 = slot_8(v145);
  return v317;
}

struct StateT * slot_3(struct StateT * v48) {
  int * v49 = v48->saved_regs;
  int * v50 = v48->regs;
  int v51 = v50[6];
  v49[6] = v51;
  int v53 = v48->timer;
  int v68 = v53 + 1;
  v48->timer = v68;
  int * v55 = v48->reg_ready;
  int v56 = v55[5];
  int * v57 = v48->regs;
  int v58 = v57[5];
  int v72 = (v56 + ((v53 - v56) & (~((v53 - v56) >> 31)))) + 1;
  v55[6] = v72;
  int * v60 = v48->regs;
  int v74 = v58 + 80;
  v60[6] = v74;
  struct StateT * v62 = slot_4(v48);
  return v62;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v898 = v1->timer;
  int * v899 = v1->reg_ready;
  int v900 = v899[0];
  int v1031 = v900 + ((v898 - v900) & (~((v898 - v900) >> 31)));
  v1->timer = v1031;
  int v902 = v1->timer;
  int * v903 = v1->reg_ready;
  int v904 = v903[1];
  int v1034 = v904 + ((v902 - v904) & (~((v902 - v904) >> 31)));
  v1->timer = v1034;
  int v906 = v1->timer;
  int * v907 = v1->reg_ready;
  int v908 = v907[2];
  int v1037 = v908 + ((v906 - v908) & (~((v906 - v908) >> 31)));
  v1->timer = v1037;
  int v910 = v1->timer;
  int * v911 = v1->reg_ready;
  int v912 = v911[3];
  int v1040 = v912 + ((v910 - v912) & (~((v910 - v912) >> 31)));
  v1->timer = v1040;
  int v914 = v1->timer;
  int * v915 = v1->reg_ready;
  int v916 = v915[4];
  int v1043 = v916 + ((v914 - v916) & (~((v914 - v916) >> 31)));
  v1->timer = v1043;
  int v918 = v1->timer;
  int * v919 = v1->reg_ready;
  int v920 = v919[5];
  int v1046 = v920 + ((v918 - v920) & (~((v918 - v920) >> 31)));
  v1->timer = v1046;
  int v922 = v1->timer;
  int * v923 = v1->reg_ready;
  int v924 = v923[6];
  int v1049 = v924 + ((v922 - v924) & (~((v922 - v924) >> 31)));
  v1->timer = v1049;
  int v926 = v1->timer;
  int * v927 = v1->reg_ready;
  int v928 = v927[7];
  int v1052 = v928 + ((v926 - v928) & (~((v926 - v928) >> 31)));
  v1->timer = v1052;
  int v930 = v1->timer;
  int * v931 = v1->reg_ready;
  int v932 = v931[8];
  int v1055 = v932 + ((v930 - v932) & (~((v930 - v932) >> 31)));
  v1->timer = v1055;
  int v934 = v1->timer;
  int * v935 = v1->reg_ready;
  int v936 = v935[9];
  int v1058 = v936 + ((v934 - v936) & (~((v934 - v936) >> 31)));
  v1->timer = v1058;
  int v938 = v1->timer;
  int * v939 = v1->reg_ready;
  int v940 = v939[10];
  int v1061 = v940 + ((v938 - v940) & (~((v938 - v940) >> 31)));
  v1->timer = v1061;
  int v942 = v1->timer;
  int * v943 = v1->reg_ready;
  int v944 = v943[11];
  int v1064 = v944 + ((v942 - v944) & (~((v942 - v944) >> 31)));
  v1->timer = v1064;
  int v946 = v1->timer;
  int * v947 = v1->reg_ready;
  int v948 = v947[12];
  int v1067 = v948 + ((v946 - v948) & (~((v946 - v948) >> 31)));
  v1->timer = v1067;
  int v950 = v1->timer;
  int * v951 = v1->reg_ready;
  int v952 = v951[13];
  int v1070 = v952 + ((v950 - v952) & (~((v950 - v952) >> 31)));
  v1->timer = v1070;
  int v954 = v1->timer;
  int * v955 = v1->reg_ready;
  int v956 = v955[14];
  int v1073 = v956 + ((v954 - v956) & (~((v954 - v956) >> 31)));
  v1->timer = v1073;
  int v958 = v1->timer;
  int * v959 = v1->reg_ready;
  int v960 = v959[15];
  int v1076 = v960 + ((v958 - v960) & (~((v958 - v960) >> 31)));
  v1->timer = v1076;
  int v962 = v1->timer;
  int * v963 = v1->reg_ready;
  int v964 = v963[16];
  int v1079 = v964 + ((v962 - v964) & (~((v962 - v964) >> 31)));
  v1->timer = v1079;
  int v966 = v1->timer;
  int * v967 = v1->reg_ready;
  int v968 = v967[17];
  int v1082 = v968 + ((v966 - v968) & (~((v966 - v968) >> 31)));
  v1->timer = v1082;
  int v970 = v1->timer;
  int * v971 = v1->reg_ready;
  int v972 = v971[18];
  int v1085 = v972 + ((v970 - v972) & (~((v970 - v972) >> 31)));
  v1->timer = v1085;
  int v974 = v1->timer;
  int * v975 = v1->reg_ready;
  int v976 = v975[19];
  int v1088 = v976 + ((v974 - v976) & (~((v974 - v976) >> 31)));
  v1->timer = v1088;
  int v978 = v1->timer;
  int * v979 = v1->reg_ready;
  int v980 = v979[20];
  int v1091 = v980 + ((v978 - v980) & (~((v978 - v980) >> 31)));
  v1->timer = v1091;
  int v982 = v1->timer;
  int * v983 = v1->reg_ready;
  int v984 = v983[21];
  int v1094 = v984 + ((v982 - v984) & (~((v982 - v984) >> 31)));
  v1->timer = v1094;
  int v986 = v1->timer;
  int * v987 = v1->reg_ready;
  int v988 = v987[22];
  int v1097 = v988 + ((v986 - v988) & (~((v986 - v988) >> 31)));
  v1->timer = v1097;
  int v990 = v1->timer;
  int * v991 = v1->reg_ready;
  int v992 = v991[23];
  int v1100 = v992 + ((v990 - v992) & (~((v990 - v992) >> 31)));
  v1->timer = v1100;
  int v994 = v1->timer;
  int * v995 = v1->reg_ready;
  int v996 = v995[24];
  int v1103 = v996 + ((v994 - v996) & (~((v994 - v996) >> 31)));
  v1->timer = v1103;
  int v998 = v1->timer;
  int * v999 = v1->reg_ready;
  int v1000 = v999[25];
  int v1106 = v1000 + ((v998 - v1000) & (~((v998 - v1000) >> 31)));
  v1->timer = v1106;
  int v1002 = v1->timer;
  int * v1003 = v1->reg_ready;
  int v1004 = v1003[26];
  int v1109 = v1004 + ((v1002 - v1004) & (~((v1002 - v1004) >> 31)));
  v1->timer = v1109;
  int v1006 = v1->timer;
  int * v1007 = v1->reg_ready;
  int v1008 = v1007[27];
  int v1112 = v1008 + ((v1006 - v1008) & (~((v1006 - v1008) >> 31)));
  v1->timer = v1112;
  int v1010 = v1->timer;
  int * v1011 = v1->reg_ready;
  int v1012 = v1011[28];
  int v1115 = v1012 + ((v1010 - v1012) & (~((v1010 - v1012) >> 31)));
  v1->timer = v1115;
  int v1014 = v1->timer;
  int * v1015 = v1->reg_ready;
  int v1016 = v1015[29];
  int v1118 = v1016 + ((v1014 - v1016) & (~((v1014 - v1016) >> 31)));
  v1->timer = v1118;
  int v1018 = v1->timer;
  int * v1019 = v1->reg_ready;
  int v1020 = v1019[30];
  int v1121 = v1020 + ((v1018 - v1020) & (~((v1018 - v1020) >> 31)));
  v1->timer = v1121;
  int v1022 = v1->timer;
  int * v1023 = v1->reg_ready;
  int v1024 = v1023[31];
  int v1124 = v1024 + ((v1022 - v1024) & (~((v1022 - v1024) >> 31)));
  v1->timer = v1124;
  return v1;
}

struct StateT * slot_10(struct StateT * v693) {
  int v694 = v693->timer;
  int v805 = v694 + 1;
  v693->timer = v805;
  int * v696 = v693->reg_ready;
  int v697 = v696[11];
  int * v698 = v693->regs;
  int v699 = v698[11];
  int * v700 = v693->cache_tags;
  int v810 = (((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2;
  int v701 = v700[v810];
  int v811 = ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2) + 1;
  int v702 = v700[v811];
  int v812 = 4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2);
  int v703 = v700[v812];
  int v813 = (4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v704 = v700[v813];
  int * v705 = v693->cache_vals;
  bool v814 = !(((~(((v701 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v701 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) | (~(((v702 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v702 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31))) == 0);
  int v798;
  if (v814) {
    int * v706 = v693->cache_age;
    int v816 = ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2) + ((~(((v702 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v702 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) & 1);
    int v707 = v706[v816];
    int v708 = v706[v810];
    int v817 = v708 + ((int)((unsigned int)(v708 - v707) >> 31));
    v706[v810] = v817;
    int * v710 = v693->cache_age;
    int v711 = v710[v811];
    int v819 = v711 + ((int)((unsigned int)(v711 - v707) >> 31));
    v710[v811] = v819;
    int * v713 = v693->cache_age;
    v713[v816] = 0;
    v798 = v816;
  } else {
    int * v716 = v693->cache_age;
    int v823 = (((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2;
    int v717 = v716[v823];
    int * v718 = v693->cache_tags;
    int v719 = v718[v823];
    int v720 = v716[v811];
    int v721 = v718[v811];
    bool v825 = !(((~(((v703 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v703 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) | (~(((v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31))) == 0);
    int v775;
    if (v825) {
      int * v722 = v693->cache_age;
      int v827 = (4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + ((~(((v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) & 1);
      int v723 = v722[v827];
      int v724 = v722[v812];
      int v828 = v724 + ((int)((unsigned int)(v724 - v723) >> 31));
      v722[v812] = v828;
      int * v726 = v693->cache_age;
      int v727 = v726[v813];
      int v830 = v727 + ((int)((unsigned int)(v727 - v723) >> 31));
      v726[v813] = v830;
      int * v729 = v693->cache_age;
      v729[v827] = 0;
      v775 = v827;
    } else {
      int * v732 = v693->cache_age;
      int v834 = 4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2);
      int v733 = v732[v834];
      int * v734 = v693->cache_tags;
      int v735 = v734[v834];
      int v736 = v732[v813];
      int v737 = v734[v813];
      int * v738 = v693->cache_dirty;
      int v837 = (4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v739 = v738[v837];
      bool v838 = !(v739 == 0);
      if (v838) {
        int * v740 = v693->cache_tags;
        int v741 = v740[v837];
        int * v742 = v693->cache_vals;
        int v841 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v743 = v742[v841];
        int v842 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v744 = v742[v842];
        int * v745 = v693->mem;
        int v844 = v741 * 2;
        v745[v844] = v743;
        int * v747 = v693->mem;
        int v847 = (v741 * 2) + 1;
        v747[v847] = v744;
        ;
      } else {
        ;
      }
      int * v752 = v693->mem;
      int v852 = ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) * 2;
      int v753 = v752[v852];
      int v853 = (((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) * 2) + 1;
      int v754 = v752[v853];
      int * v755 = v693->cache_vals;
      int v855 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v755[v855] = v753;
      int * v757 = v693->cache_vals;
      int v858 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 3) * 2)) + ((((v733 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2)) - (v736 + ((~(((v737 ^ -1) | (-(v737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v757[v858] = v754;
      int * v759 = v693->cache_tags;
      int v861 = (int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1);
      v759[v837] = v861;
      int * v761 = v693->cache_dirty;
      v761[v837] = 0;
      int * v763 = v693->cache_age;
      v763[v837] = 1;
      int * v765 = v693->cache_age;
      int v766 = v765[v837];
      int v767 = v765[v812];
      int v867 = v767 + ((int)((unsigned int)(v767 - v766) >> 31));
      v765[v812] = v867;
      int * v769 = v693->cache_age;
      int v770 = v769[v813];
      int v869 = v770 + ((int)((unsigned int)(v770 - v766) >> 31));
      v769[v813] = v869;
      int * v772 = v693->cache_age;
      v772[v837] = 0;
      v775 = v837;
    }
    int * v776 = v693->cache_vals;
    int v872 = v775 * 2;
    int v777 = v776[v872];
    int v873 = (v775 * 2) + 1;
    int v778 = v776[v873];
    int v874 = (((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2) + ((((v717 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2)) - (v720 + ((~(((v721 ^ -1) | (-(v721 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v776[v874] = v777;
    int * v780 = v693->cache_vals;
    int v877 = ((((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2) + ((((v717 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2)) - (v720 + ((~(((v721 ^ -1) | (-(v721 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v780[v877] = v778;
    int * v782 = v693->cache_tags;
    int v880 = ((((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1)) & 1) * 2) + ((((v717 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2)) - (v720 + ((~(((v721 ^ -1) | (-(v721 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v881 = (int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1);
    v782[v880] = v881;
    int * v784 = v693->cache_dirty;
    v784[v880] = 0;
    int * v786 = v693->cache_age;
    v786[v880] = 1;
    int * v788 = v693->cache_age;
    int v789 = v788[v880];
    int v790 = v788[v810];
    int v887 = v790 + ((int)((unsigned int)(v790 - v789) >> 31));
    v788[v810] = v887;
    int * v792 = v693->cache_age;
    int v793 = v792[v811];
    int v889 = v793 + ((int)((unsigned int)(v793 - v789) >> 31));
    v792[v811] = v889;
    int * v795 = v693->cache_age;
    v795[v880] = 0;
    v798 = v880;
  }
  int v892 = (v798 * 2) + (((int)((unsigned int)v699 >> 2)) & 1);
  int v799 = v705[v892];
  int * v800 = v693->reg_ready;
  int v895 = ((v697 + ((v694 - v697) & (~((v694 - v697) >> 31)))) + 1) + ((100 ^ (((~(((v703 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v703 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) | (~(((v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v701 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v701 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) | (~(((v702 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v702 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v703 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v703 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31)) | (~(((v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))) | (-(v704 ^ ((int)((unsigned int)((int)((unsigned int)v699 >> 2)) >> 1))))) >> 31))) & 104)))));
  v800[12] = v895;
  int * v802 = v693->regs;
  v802[12] = v799;
  return v693;
}

struct StateT * slot_1(struct StateT * v24) {
  int v25 = v24->timer;
  int v33 = v25 + 1;
  v24->timer = v33;
  int * v27 = v24->reg_ready;
  v27[9] = v33;
  int * v29 = v24->regs;
  v29[9] = 32;
  struct StateT * v31 = slot_2(v24);
  return v31;
}

struct StateT * slot_8(struct StateT * v464) {
  int v465 = v464->timer;
  int v577 = v465 + 1;
  v464->timer = v577;
  int * v467 = v464->reg_ready;
  int v468 = v467[6];
  int * v469 = v464->regs;
  int v470 = v469[6];
  int * v471 = v464->cache_tags;
  int v582 = (((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2;
  int v472 = v471[v582];
  int v583 = ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2) + 1;
  int v473 = v471[v583];
  int v584 = 4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2);
  int v474 = v471[v584];
  int v585 = (4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v475 = v471[v585];
  int * v476 = v464->cache_vals;
  bool v586 = !(((~(((v472 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v472 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) | (~(((v473 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v473 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31))) == 0);
  int v569;
  if (v586) {
    int * v477 = v464->cache_age;
    int v588 = ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2) + ((~(((v473 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v473 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) & 1);
    int v478 = v477[v588];
    int v479 = v477[v582];
    int v589 = v479 + ((int)((unsigned int)(v479 - v478) >> 31));
    v477[v582] = v589;
    int * v481 = v464->cache_age;
    int v482 = v481[v583];
    int v591 = v482 + ((int)((unsigned int)(v482 - v478) >> 31));
    v481[v583] = v591;
    int * v484 = v464->cache_age;
    v484[v588] = 0;
    v569 = v588;
  } else {
    int * v487 = v464->cache_age;
    int v595 = (((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2;
    int v488 = v487[v595];
    int * v489 = v464->cache_tags;
    int v490 = v489[v595];
    int v491 = v487[v583];
    int v492 = v489[v583];
    bool v597 = !(((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) | (~(((v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31))) == 0);
    int v546;
    if (v597) {
      int * v493 = v464->cache_age;
      int v599 = (4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + ((~(((v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) & 1);
      int v494 = v493[v599];
      int v495 = v493[v584];
      int v600 = v495 + ((int)((unsigned int)(v495 - v494) >> 31));
      v493[v584] = v600;
      int * v497 = v464->cache_age;
      int v498 = v497[v585];
      int v602 = v498 + ((int)((unsigned int)(v498 - v494) >> 31));
      v497[v585] = v602;
      int * v500 = v464->cache_age;
      v500[v599] = 0;
      v546 = v599;
    } else {
      int * v503 = v464->cache_age;
      int v606 = 4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2);
      int v504 = v503[v606];
      int * v505 = v464->cache_tags;
      int v506 = v505[v606];
      int v507 = v503[v585];
      int v508 = v505[v585];
      int * v509 = v464->cache_dirty;
      int v609 = (4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + ((((v504 + ((~(((v506 ^ -1) | (-(v506 ^ -1))) >> 31)) & 2)) - (v507 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v510 = v509[v609];
      bool v610 = !(v510 == 0);
      if (v610) {
        int * v511 = v464->cache_tags;
        int v512 = v511[v609];
        int * v513 = v464->cache_vals;
        int v613 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + ((((v504 + ((~(((v506 ^ -1) | (-(v506 ^ -1))) >> 31)) & 2)) - (v507 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v514 = v513[v613];
        int v614 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + ((((v504 + ((~(((v506 ^ -1) | (-(v506 ^ -1))) >> 31)) & 2)) - (v507 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v515 = v513[v614];
        int * v516 = v464->mem;
        int v616 = v512 * 2;
        v516[v616] = v514;
        int * v518 = v464->mem;
        int v619 = (v512 * 2) + 1;
        v518[v619] = v515;
        ;
      } else {
        ;
      }
      int * v523 = v464->mem;
      int v624 = ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) * 2;
      int v524 = v523[v624];
      int v625 = (((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) * 2) + 1;
      int v525 = v523[v625];
      int * v526 = v464->cache_vals;
      int v627 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + ((((v504 + ((~(((v506 ^ -1) | (-(v506 ^ -1))) >> 31)) & 2)) - (v507 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v526[v627] = v524;
      int * v528 = v464->cache_vals;
      int v630 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 3) * 2)) + ((((v504 + ((~(((v506 ^ -1) | (-(v506 ^ -1))) >> 31)) & 2)) - (v507 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v528[v630] = v525;
      int * v530 = v464->cache_tags;
      int v633 = (int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1);
      v530[v609] = v633;
      int * v532 = v464->cache_dirty;
      v532[v609] = 0;
      int * v534 = v464->cache_age;
      v534[v609] = 1;
      int * v536 = v464->cache_age;
      int v537 = v536[v609];
      int v538 = v536[v584];
      int v639 = v538 + ((int)((unsigned int)(v538 - v537) >> 31));
      v536[v584] = v639;
      int * v540 = v464->cache_age;
      int v541 = v540[v585];
      int v641 = v541 + ((int)((unsigned int)(v541 - v537) >> 31));
      v540[v585] = v641;
      int * v543 = v464->cache_age;
      v543[v609] = 0;
      v546 = v609;
    }
    int * v547 = v464->cache_vals;
    int v644 = v546 * 2;
    int v548 = v547[v644];
    int v645 = (v546 * 2) + 1;
    int v549 = v547[v645];
    int v646 = (((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v491 + ((~(((v492 ^ -1) | (-(v492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v547[v646] = v548;
    int * v551 = v464->cache_vals;
    int v649 = ((((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v491 + ((~(((v492 ^ -1) | (-(v492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v551[v649] = v549;
    int * v553 = v464->cache_tags;
    int v652 = ((((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1)) & 1) * 2) + ((((v488 + ((~(((v490 ^ -1) | (-(v490 ^ -1))) >> 31)) & 2)) - (v491 + ((~(((v492 ^ -1) | (-(v492 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v653 = (int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1);
    v553[v652] = v653;
    int * v555 = v464->cache_dirty;
    v555[v652] = 0;
    int * v557 = v464->cache_age;
    v557[v652] = 1;
    int * v559 = v464->cache_age;
    int v560 = v559[v652];
    int v561 = v559[v582];
    int v659 = v561 + ((int)((unsigned int)(v561 - v560) >> 31));
    v559[v582] = v659;
    int * v563 = v464->cache_age;
    int v564 = v563[v583];
    int v661 = v564 + ((int)((unsigned int)(v564 - v560) >> 31));
    v563[v583] = v661;
    int * v566 = v464->cache_age;
    v566[v652] = 0;
    v569 = v652;
  }
  int v664 = (v569 * 2) + (((int)((unsigned int)v470 >> 2)) & 1);
  int v570 = v476[v664];
  int * v571 = v464->reg_ready;
  int v667 = ((v468 + ((v465 - v468) & (~((v465 - v468) >> 31)))) + 1) + ((100 ^ (((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) | (~(((v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v472 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v472 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) | (~(((v473 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v473 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31)) | (~(((v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))) | (-(v475 ^ ((int)((unsigned int)((int)((unsigned int)v470 >> 2)) >> 1))))) >> 31))) & 104)))));
  v571[11] = v667;
  int * v573 = v464->regs;
  v573[11] = v570;
  struct StateT * v575 = slot_9(v464);
  return v575;
}

struct StateT * slot_4(struct StateT * v77) {
  int * v78 = v77->saved_regs;
  int * v79 = v77->regs;
  int v80 = v79[7];
  v78[7] = v80;
  int v82 = v77->timer;
  int v94 = v82 + 1;
  v77->timer = v94;
  int * v84 = v77->reg_ready;
  v84[7] = v94;
  int * v86 = v77->regs;
  v86[7] = 0;
  struct StateT * v88 = slot_5(v77);
  return v88;
}

struct StateT * slot_9(struct StateT * v672) {
  int v673 = v672->timer;
  int v684 = v673 + 1;
  v672->timer = v684;
  int * v675 = v672->reg_ready;
  int v676 = v675[11];
  int * v677 = v672->regs;
  int v678 = v677[11];
  int v688 = (v676 + ((v673 - v676) & (~((v673 - v676) >> 31)))) + 1;
  v675[11] = v688;
  int * v680 = v672->regs;
  int v690 = v678 << 2;
  v680[11] = v690;
  struct StateT * v682 = slot_10(v672);
  return v682;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v19 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[5] = v19;
  int * v10 = v2->regs;
  int v21 = v8 & 28;
  v10[5] = v21;
  struct StateT * v12 = slot_1(v2);
  return v12;
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