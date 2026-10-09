// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_6(struct StateT2 * v1721);
struct StateT2 * slot_5(struct StateT2 * v1678);
struct StateT2 * slot_4(struct StateT2 * v1288);
struct StateT2 * slot_2(struct StateT2 * v645);
struct StateT2 * slot_7(struct StateT2 * v2139);
struct StateT2 * slot_3(struct StateT2 * v681);
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
  bool v387 = v40 == v42;
  squared_assert(v387);
  squared_assume(v387);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v389 = v46 + 1;
  v45->timer = v389;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v391 = v49 + 1;
  v48->timer = v391;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  int v53 = v52[5];
  int * v54 = v51->cache_tags;
  int v55 = v54[0];
  int v56 = v54[1];
  int v57 = v54[8];
  int v58 = v54[9];
  int v59 = v51->timer;
  int v400 = v59 + ((100 ^ (((~(((v57 ^ 6) | (-(v57 ^ 6))) >> 31)) | (~(((v58 ^ 6) | (-(v58 ^ 6))) >> 31))) & 104)) ^ (((~(((v55 ^ 6) | (-(v55 ^ 6))) >> 31)) | (~(((v56 ^ 6) | (-(v56 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v57 ^ 6) | (-(v57 ^ 6))) >> 31)) | (~(((v58 ^ 6) | (-(v58 ^ 6))) >> 31))) & 104)))));
  v51->timer = v400;
  bool v401 = !(((~(((v55 ^ 6) | (-(v55 ^ 6))) >> 31)) | (~(((v56 ^ 6) | (-(v56 ^ 6))) >> 31))) == 0);
  int v153;
  if (v401) {
    int * v61 = v51->cache_age;
    int v403 = (~(((v56 ^ 6) | (-(v56 ^ 6))) >> 31)) & 1;
    int v62 = v61[v403];
    int v63 = v61[0];
    int v404 = v63 + ((int)((unsigned int)(v63 - v62) >> 31));
    v61[0] = v404;
    int * v65 = v51->cache_age;
    int v66 = v65[1];
    int v406 = v66 + ((int)((unsigned int)(v66 - v62) >> 31));
    v65[1] = v406;
    int * v68 = v51->cache_age;
    v68[v403] = 0;
    v153 = v403;
  } else {
    int * v71 = v51->cache_age;
    int v72 = v71[0];
    int * v73 = v51->cache_tags;
    int v74 = v73[0];
    int v75 = v71[1];
    int v76 = v73[1];
    bool v410 = !(((~(((v57 ^ 6) | (-(v57 ^ 6))) >> 31)) | (~(((v58 ^ 6) | (-(v58 ^ 6))) >> 31))) == 0);
    int v130;
    if (v410) {
      int * v77 = v51->cache_age;
      int v412 = 8 + ((~(((v58 ^ 6) | (-(v58 ^ 6))) >> 31)) & 1);
      int v78 = v77[v412];
      int v79 = v77[8];
      int v413 = v79 + ((int)((unsigned int)(v79 - v78) >> 31));
      v77[8] = v413;
      int * v81 = v51->cache_age;
      int v82 = v81[9];
      int v415 = v82 + ((int)((unsigned int)(v82 - v78) >> 31));
      v81[9] = v415;
      int * v84 = v51->cache_age;
      v84[v412] = 0;
      v130 = v412;
    } else {
      int * v87 = v51->cache_age;
      int v88 = v87[8];
      int * v89 = v51->cache_tags;
      int v90 = v89[8];
      int v91 = v87[9];
      int v92 = v89[9];
      int * v93 = v51->cache_dirty;
      int v420 = 8 + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v94 = v93[v420];
      bool v421 = !(v94 == 0);
      if (v421) {
        int * v95 = v51->cache_tags;
        int v96 = v95[v420];
        int * v97 = v51->cache_vals;
        int v424 = (8 + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v98 = v97[v424];
        int v425 = ((8 + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v99 = v97[v425];
        int * v100 = v51->mem;
        int v427 = v96 * 2;
        v100[v427] = v98;
        int * v102 = v51->mem;
        int v430 = (v96 * 2) + 1;
        v102[v430] = v99;
        ;
      } else {
        ;
      }
      int * v107 = v51->mem;
      int v108 = v107[12];
      int v109 = v107[13];
      int * v110 = v51->cache_vals;
      int v438 = (8 + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v110[v438] = v108;
      int * v112 = v51->cache_vals;
      int v441 = ((8 + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v112[v441] = v109;
      int * v114 = v51->cache_tags;
      v114[v420] = 6;
      int * v116 = v51->cache_dirty;
      v116[v420] = 0;
      int * v118 = v51->cache_age;
      v118[v420] = 1;
      int * v120 = v51->cache_age;
      int v121 = v120[v420];
      int v122 = v120[8];
      int v448 = v122 + ((int)((unsigned int)(v122 - v121) >> 31));
      v120[8] = v448;
      int * v124 = v51->cache_age;
      int v125 = v124[9];
      int v450 = v125 + ((int)((unsigned int)(v125 - v121) >> 31));
      v124[9] = v450;
      int * v127 = v51->cache_age;
      v127[v420] = 0;
      v130 = v420;
    }
    int * v131 = v51->cache_vals;
    int v453 = v130 * 2;
    int v132 = v131[v453];
    int v454 = (v130 * 2) + 1;
    int v133 = v131[v454];
    int v455 = ((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v75 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v131[v455] = v132;
    int * v135 = v51->cache_vals;
    int v458 = (((((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v75 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v135[v458] = v133;
    int * v137 = v51->cache_tags;
    int v461 = (((v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2)) - (v75 + ((~(((v76 ^ -1) | (-(v76 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v137[v461] = 6;
    int * v139 = v51->cache_dirty;
    v139[v461] = 0;
    int * v141 = v51->cache_age;
    v141[v461] = 1;
    int * v143 = v51->cache_age;
    int v144 = v143[v461];
    int v145 = v143[0];
    int v466 = v145 + ((int)((unsigned int)(v145 - v144) >> 31));
    v143[0] = v466;
    int * v147 = v51->cache_age;
    int v148 = v147[1];
    int v468 = v148 + ((int)((unsigned int)(v148 - v144) >> 31));
    v147[1] = v468;
    int * v150 = v51->cache_age;
    v150[v461] = 0;
    v153 = v461;
  }
  int * v154 = v51->cache_vals;
  int v471 = (v153 * 2) + 1;
  v154[v471] = v53;
  int * v156 = v51->cache_tags;
  int v157 = v156[8];
  int v158 = v156[9];
  bool v474 = !(((~(((v157 ^ 6) | (-(v157 ^ 6))) >> 31)) | (~(((v158 ^ 6) | (-(v158 ^ 6))) >> 31))) == 0);
  int v212;
  if (v474) {
    int * v159 = v51->cache_age;
    int v476 = 8 + ((~(((v158 ^ 6) | (-(v158 ^ 6))) >> 31)) & 1);
    int v160 = v159[v476];
    int v161 = v159[8];
    int v477 = v161 + ((int)((unsigned int)(v161 - v160) >> 31));
    v159[8] = v477;
    int * v163 = v51->cache_age;
    int v164 = v163[9];
    int v479 = v164 + ((int)((unsigned int)(v164 - v160) >> 31));
    v163[9] = v479;
    int * v166 = v51->cache_age;
    v166[v476] = 0;
    v212 = v476;
  } else {
    int * v169 = v51->cache_age;
    int v170 = v169[8];
    int * v171 = v51->cache_tags;
    int v172 = v171[8];
    int v173 = v169[9];
    int v174 = v171[9];
    int * v175 = v51->cache_dirty;
    int v484 = 8 + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v176 = v175[v484];
    bool v485 = !(v176 == 0);
    if (v485) {
      int * v177 = v51->cache_tags;
      int v178 = v177[v484];
      int * v179 = v51->cache_vals;
      int v488 = (8 + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v180 = v179[v488];
      int v489 = ((8 + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v181 = v179[v489];
      int * v182 = v51->mem;
      int v491 = v178 * 2;
      v182[v491] = v180;
      int * v184 = v51->mem;
      int v494 = (v178 * 2) + 1;
      v184[v494] = v181;
      ;
    } else {
      ;
    }
    int * v189 = v51->mem;
    int v190 = v189[12];
    int v191 = v189[13];
    int * v192 = v51->cache_vals;
    int v502 = (8 + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v192[v502] = v190;
    int * v194 = v51->cache_vals;
    int v505 = ((8 + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v194[v505] = v191;
    int * v196 = v51->cache_tags;
    v196[v484] = 6;
    int * v198 = v51->cache_dirty;
    v198[v484] = 0;
    int * v200 = v51->cache_age;
    v200[v484] = 1;
    int * v202 = v51->cache_age;
    int v203 = v202[v484];
    int v204 = v202[8];
    int v512 = v204 + ((int)((unsigned int)(v204 - v203) >> 31));
    v202[8] = v512;
    int * v206 = v51->cache_age;
    int v207 = v206[9];
    int v514 = v207 + ((int)((unsigned int)(v207 - v203) >> 31));
    v206[9] = v514;
    int * v209 = v51->cache_age;
    v209[v484] = 0;
    v212 = v484;
  }
  int * v213 = v51->cache_vals;
  int v517 = (v212 * 2) + 1;
  v213[v517] = v53;
  int * v215 = v51->cache_dirty;
  v215[v212] = 1;
  struct StateT * v217 = v38->b;
  int * v218 = v217->regs;
  int v219 = v218[5];
  int * v220 = v217->cache_tags;
  int v221 = v220[0];
  int v222 = v220[1];
  int v223 = v220[8];
  int v224 = v220[9];
  int v225 = v217->timer;
  int v523 = v225 + ((100 ^ (((~(((v223 ^ 6) | (-(v223 ^ 6))) >> 31)) | (~(((v224 ^ 6) | (-(v224 ^ 6))) >> 31))) & 104)) ^ (((~(((v221 ^ 6) | (-(v221 ^ 6))) >> 31)) | (~(((v222 ^ 6) | (-(v222 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v223 ^ 6) | (-(v223 ^ 6))) >> 31)) | (~(((v224 ^ 6) | (-(v224 ^ 6))) >> 31))) & 104)))));
  v217->timer = v523;
  bool v524 = !(((~(((v221 ^ 6) | (-(v221 ^ 6))) >> 31)) | (~(((v222 ^ 6) | (-(v222 ^ 6))) >> 31))) == 0);
  int v319;
  if (v524) {
    int * v227 = v217->cache_age;
    int v526 = (~(((v222 ^ 6) | (-(v222 ^ 6))) >> 31)) & 1;
    int v228 = v227[v526];
    int v229 = v227[0];
    int v527 = v229 + ((int)((unsigned int)(v229 - v228) >> 31));
    v227[0] = v527;
    int * v231 = v217->cache_age;
    int v232 = v231[1];
    int v529 = v232 + ((int)((unsigned int)(v232 - v228) >> 31));
    v231[1] = v529;
    int * v234 = v217->cache_age;
    v234[v526] = 0;
    v319 = v526;
  } else {
    int * v237 = v217->cache_age;
    int v238 = v237[0];
    int * v239 = v217->cache_tags;
    int v240 = v239[0];
    int v241 = v237[1];
    int v242 = v239[1];
    bool v533 = !(((~(((v223 ^ 6) | (-(v223 ^ 6))) >> 31)) | (~(((v224 ^ 6) | (-(v224 ^ 6))) >> 31))) == 0);
    int v296;
    if (v533) {
      int * v243 = v217->cache_age;
      int v535 = 8 + ((~(((v224 ^ 6) | (-(v224 ^ 6))) >> 31)) & 1);
      int v244 = v243[v535];
      int v245 = v243[8];
      int v536 = v245 + ((int)((unsigned int)(v245 - v244) >> 31));
      v243[8] = v536;
      int * v247 = v217->cache_age;
      int v248 = v247[9];
      int v538 = v248 + ((int)((unsigned int)(v248 - v244) >> 31));
      v247[9] = v538;
      int * v250 = v217->cache_age;
      v250[v535] = 0;
      v296 = v535;
    } else {
      int * v253 = v217->cache_age;
      int v254 = v253[8];
      int * v255 = v217->cache_tags;
      int v256 = v255[8];
      int v257 = v253[9];
      int v258 = v255[9];
      int * v259 = v217->cache_dirty;
      int v543 = 8 + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v260 = v259[v543];
      bool v544 = !(v260 == 0);
      if (v544) {
        int * v261 = v217->cache_tags;
        int v262 = v261[v543];
        int * v263 = v217->cache_vals;
        int v547 = (8 + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v264 = v263[v547];
        int v548 = ((8 + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v265 = v263[v548];
        int * v266 = v217->mem;
        int v550 = v262 * 2;
        v266[v550] = v264;
        int * v268 = v217->mem;
        int v553 = (v262 * 2) + 1;
        v268[v553] = v265;
        ;
      } else {
        ;
      }
      int * v273 = v217->mem;
      int v274 = v273[12];
      int v275 = v273[13];
      int * v276 = v217->cache_vals;
      int v561 = (8 + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v276[v561] = v274;
      int * v278 = v217->cache_vals;
      int v564 = ((8 + ((((v254 + ((~(((v256 ^ -1) | (-(v256 ^ -1))) >> 31)) & 2)) - (v257 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v278[v564] = v275;
      int * v280 = v217->cache_tags;
      v280[v543] = 6;
      int * v282 = v217->cache_dirty;
      v282[v543] = 0;
      int * v284 = v217->cache_age;
      v284[v543] = 1;
      int * v286 = v217->cache_age;
      int v287 = v286[v543];
      int v288 = v286[8];
      int v571 = v288 + ((int)((unsigned int)(v288 - v287) >> 31));
      v286[8] = v571;
      int * v290 = v217->cache_age;
      int v291 = v290[9];
      int v573 = v291 + ((int)((unsigned int)(v291 - v287) >> 31));
      v290[9] = v573;
      int * v293 = v217->cache_age;
      v293[v543] = 0;
      v296 = v543;
    }
    int * v297 = v217->cache_vals;
    int v576 = v296 * 2;
    int v298 = v297[v576];
    int v577 = (v296 * 2) + 1;
    int v299 = v297[v577];
    int v578 = ((((v238 + ((~(((v240 ^ -1) | (-(v240 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v297[v578] = v298;
    int * v301 = v217->cache_vals;
    int v581 = (((((v238 + ((~(((v240 ^ -1) | (-(v240 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v301[v581] = v299;
    int * v303 = v217->cache_tags;
    int v584 = (((v238 + ((~(((v240 ^ -1) | (-(v240 ^ -1))) >> 31)) & 2)) - (v241 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v303[v584] = 6;
    int * v305 = v217->cache_dirty;
    v305[v584] = 0;
    int * v307 = v217->cache_age;
    v307[v584] = 1;
    int * v309 = v217->cache_age;
    int v310 = v309[v584];
    int v311 = v309[0];
    int v589 = v311 + ((int)((unsigned int)(v311 - v310) >> 31));
    v309[0] = v589;
    int * v313 = v217->cache_age;
    int v314 = v313[1];
    int v591 = v314 + ((int)((unsigned int)(v314 - v310) >> 31));
    v313[1] = v591;
    int * v316 = v217->cache_age;
    v316[v584] = 0;
    v319 = v584;
  }
  int * v320 = v217->cache_vals;
  int v594 = (v319 * 2) + 1;
  v320[v594] = v219;
  int * v322 = v217->cache_tags;
  int v323 = v322[8];
  int v324 = v322[9];
  bool v597 = !(((~(((v323 ^ 6) | (-(v323 ^ 6))) >> 31)) | (~(((v324 ^ 6) | (-(v324 ^ 6))) >> 31))) == 0);
  int v378;
  if (v597) {
    int * v325 = v217->cache_age;
    int v599 = 8 + ((~(((v324 ^ 6) | (-(v324 ^ 6))) >> 31)) & 1);
    int v326 = v325[v599];
    int v327 = v325[8];
    int v600 = v327 + ((int)((unsigned int)(v327 - v326) >> 31));
    v325[8] = v600;
    int * v329 = v217->cache_age;
    int v330 = v329[9];
    int v602 = v330 + ((int)((unsigned int)(v330 - v326) >> 31));
    v329[9] = v602;
    int * v332 = v217->cache_age;
    v332[v599] = 0;
    v378 = v599;
  } else {
    int * v335 = v217->cache_age;
    int v336 = v335[8];
    int * v337 = v217->cache_tags;
    int v338 = v337[8];
    int v339 = v335[9];
    int v340 = v337[9];
    int * v341 = v217->cache_dirty;
    int v607 = 8 + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v342 = v341[v607];
    bool v608 = !(v342 == 0);
    if (v608) {
      int * v343 = v217->cache_tags;
      int v344 = v343[v607];
      int * v345 = v217->cache_vals;
      int v611 = (8 + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v346 = v345[v611];
      int v612 = ((8 + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v347 = v345[v612];
      int * v348 = v217->mem;
      int v614 = v344 * 2;
      v348[v614] = v346;
      int * v350 = v217->mem;
      int v617 = (v344 * 2) + 1;
      v350[v617] = v347;
      ;
    } else {
      ;
    }
    int * v355 = v217->mem;
    int v356 = v355[12];
    int v357 = v355[13];
    int * v358 = v217->cache_vals;
    int v625 = (8 + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v358[v625] = v356;
    int * v360 = v217->cache_vals;
    int v628 = ((8 + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v360[v628] = v357;
    int * v362 = v217->cache_tags;
    v362[v607] = 6;
    int * v364 = v217->cache_dirty;
    v364[v607] = 0;
    int * v366 = v217->cache_age;
    v366[v607] = 1;
    int * v368 = v217->cache_age;
    int v369 = v368[v607];
    int v370 = v368[8];
    int v635 = v370 + ((int)((unsigned int)(v370 - v369) >> 31));
    v368[8] = v635;
    int * v372 = v217->cache_age;
    int v373 = v372[9];
    int v637 = v373 + ((int)((unsigned int)(v373 - v369) >> 31));
    v372[9] = v637;
    int * v375 = v217->cache_age;
    v375[v607] = 0;
    v378 = v607;
  }
  int * v379 = v217->cache_vals;
  int v640 = (v378 * 2) + 1;
  v379[v640] = v219;
  int * v381 = v217->cache_dirty;
  v381[v378] = 1;
  struct StateT2 * v383 = slot_2(v38);
  return v383;
}

struct StateT2 * slot_6(struct StateT2 * v1721) {
  struct StateT * v1722 = v1721->a;
  int v1723 = v1722->timer;
  struct StateT * v1724 = v1721->b;
  int v1725 = v1724->timer;
  bool v1952 = v1723 == v1725;
  squared_assert(v1952);
  squared_assume(v1952);
  struct StateT * v1728 = v1721->a;
  int v1729 = v1728->timer;
  int v1954 = v1729 + 1;
  v1728->timer = v1954;
  struct StateT * v1731 = v1721->b;
  int v1732 = v1731->timer;
  int v1956 = v1732 + 1;
  v1731->timer = v1956;
  struct StateT * v1734 = v1721->a;
  int * v1735 = v1734->regs;
  int v1736 = v1735[9];
  int * v1737 = v1734->cache_tags;
  int v1961 = (((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2;
  int v1738 = v1737[v1961];
  int v1962 = ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1739 = v1737[v1962];
  int v1963 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2);
  int v1740 = v1737[v1963];
  int v1964 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1741 = v1737[v1964];
  int v1742 = v1734->timer;
  int v1965 = v1742 + ((100 ^ (((~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) | (~(((v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) | (~(((v1739 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1739 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) | (~(((v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1734->timer = v1965;
  int * v1744 = v1734->cache_vals;
  bool v1966 = !(((~(((v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1738 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) | (~(((v1739 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1739 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31))) == 0);
  int v1837;
  if (v1966) {
    int * v1745 = v1734->cache_age;
    int v1968 = ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2) + ((~(((v1739 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1739 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) & 1);
    int v1746 = v1745[v1968];
    int v1747 = v1745[v1961];
    int v1969 = v1747 + ((int)((unsigned int)(v1747 - v1746) >> 31));
    v1745[v1961] = v1969;
    int * v1749 = v1734->cache_age;
    int v1750 = v1749[v1962];
    int v1971 = v1750 + ((int)((unsigned int)(v1750 - v1746) >> 31));
    v1749[v1962] = v1971;
    int * v1752 = v1734->cache_age;
    v1752[v1968] = 0;
    v1837 = v1968;
  } else {
    int * v1755 = v1734->cache_age;
    int v1975 = (((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2;
    int v1756 = v1755[v1975];
    int * v1757 = v1734->cache_tags;
    int v1758 = v1757[v1975];
    int v1759 = v1755[v1962];
    int v1760 = v1757[v1962];
    bool v1977 = !(((~(((v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1740 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) | (~(((v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31))) == 0);
    int v1814;
    if (v1977) {
      int * v1761 = v1734->cache_age;
      int v1979 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))) | (-(v1741 ^ ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1))))) >> 31)) & 1);
      int v1762 = v1761[v1979];
      int v1763 = v1761[v1963];
      int v1980 = v1763 + ((int)((unsigned int)(v1763 - v1762) >> 31));
      v1761[v1963] = v1980;
      int * v1765 = v1734->cache_age;
      int v1766 = v1765[v1964];
      int v1982 = v1766 + ((int)((unsigned int)(v1766 - v1762) >> 31));
      v1765[v1964] = v1982;
      int * v1768 = v1734->cache_age;
      v1768[v1979] = 0;
      v1814 = v1979;
    } else {
      int * v1771 = v1734->cache_age;
      int v1986 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2);
      int v1772 = v1771[v1986];
      int * v1773 = v1734->cache_tags;
      int v1774 = v1773[v1986];
      int v1775 = v1771[v1964];
      int v1776 = v1773[v1964];
      int * v1777 = v1734->cache_dirty;
      int v1989 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + ((((v1772 + ((~(((v1774 ^ -1) | (-(v1774 ^ -1))) >> 31)) & 2)) - (v1775 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1778 = v1777[v1989];
      bool v1990 = !(v1778 == 0);
      if (v1990) {
        int * v1779 = v1734->cache_tags;
        int v1780 = v1779[v1989];
        int * v1781 = v1734->cache_vals;
        int v1993 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + ((((v1772 + ((~(((v1774 ^ -1) | (-(v1774 ^ -1))) >> 31)) & 2)) - (v1775 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1782 = v1781[v1993];
        int v1994 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + ((((v1772 + ((~(((v1774 ^ -1) | (-(v1774 ^ -1))) >> 31)) & 2)) - (v1775 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1783 = v1781[v1994];
        int * v1784 = v1734->mem;
        int v1996 = v1780 * 2;
        v1784[v1996] = v1782;
        int * v1786 = v1734->mem;
        int v1999 = (v1780 * 2) + 1;
        v1786[v1999] = v1783;
        ;
      } else {
        ;
      }
      int * v1791 = v1734->mem;
      int v2004 = ((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) * 2;
      int v1792 = v1791[v2004];
      int v2005 = (((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) * 2) + 1;
      int v1793 = v1791[v2005];
      int * v1794 = v1734->cache_vals;
      int v2007 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + ((((v1772 + ((~(((v1774 ^ -1) | (-(v1774 ^ -1))) >> 31)) & 2)) - (v1775 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1794[v2007] = v1792;
      int * v1796 = v1734->cache_vals;
      int v2010 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 3) * 2)) + ((((v1772 + ((~(((v1774 ^ -1) | (-(v1774 ^ -1))) >> 31)) & 2)) - (v1775 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1796[v2010] = v1793;
      int * v1798 = v1734->cache_tags;
      int v2013 = (int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1);
      v1798[v1989] = v2013;
      int * v1800 = v1734->cache_dirty;
      v1800[v1989] = 0;
      int * v1802 = v1734->cache_age;
      v1802[v1989] = 1;
      int * v1804 = v1734->cache_age;
      int v1805 = v1804[v1989];
      int v1806 = v1804[v1963];
      int v2019 = v1806 + ((int)((unsigned int)(v1806 - v1805) >> 31));
      v1804[v1963] = v2019;
      int * v1808 = v1734->cache_age;
      int v1809 = v1808[v1964];
      int v2021 = v1809 + ((int)((unsigned int)(v1809 - v1805) >> 31));
      v1808[v1964] = v2021;
      int * v1811 = v1734->cache_age;
      v1811[v1989] = 0;
      v1814 = v1989;
    }
    int * v1815 = v1734->cache_vals;
    int v2024 = v1814 * 2;
    int v1816 = v1815[v2024];
    int v2025 = (v1814 * 2) + 1;
    int v1817 = v1815[v2025];
    int v2026 = (((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2) + ((((v1756 + ((~(((v1758 ^ -1) | (-(v1758 ^ -1))) >> 31)) & 2)) - (v1759 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1815[v2026] = v1816;
    int * v1819 = v1734->cache_vals;
    int v2029 = ((((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2) + ((((v1756 + ((~(((v1758 ^ -1) | (-(v1758 ^ -1))) >> 31)) & 2)) - (v1759 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1819[v2029] = v1817;
    int * v1821 = v1734->cache_tags;
    int v2032 = ((((int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1)) & 1) * 2) + ((((v1756 + ((~(((v1758 ^ -1) | (-(v1758 ^ -1))) >> 31)) & 2)) - (v1759 + ((~(((v1760 ^ -1) | (-(v1760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2033 = (int)((unsigned int)((int)((unsigned int)v1736 >> 2)) >> 1);
    v1821[v2032] = v2033;
    int * v1823 = v1734->cache_dirty;
    v1823[v2032] = 0;
    int * v1825 = v1734->cache_age;
    v1825[v2032] = 1;
    int * v1827 = v1734->cache_age;
    int v1828 = v1827[v2032];
    int v1829 = v1827[v1961];
    int v2039 = v1829 + ((int)((unsigned int)(v1829 - v1828) >> 31));
    v1827[v1961] = v2039;
    int * v1831 = v1734->cache_age;
    int v1832 = v1831[v1962];
    int v2041 = v1832 + ((int)((unsigned int)(v1832 - v1828) >> 31));
    v1831[v1962] = v2041;
    int * v1834 = v1734->cache_age;
    v1834[v2032] = 0;
    v1837 = v2032;
  }
  int v2044 = (v1837 * 2) + (((int)((unsigned int)v1736 >> 2)) & 1);
  int v1838 = v1744[v2044];
  int * v1839 = v1734->regs;
  v1839[11] = v1838;
  struct StateT * v1841 = v1721->b;
  int * v1842 = v1841->regs;
  int v1843 = v1842[9];
  int * v1844 = v1841->cache_tags;
  int v2051 = (((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2;
  int v1845 = v1844[v2051];
  int v2052 = ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1846 = v1844[v2052];
  int v2053 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2);
  int v1847 = v1844[v2053];
  int v2054 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1848 = v1844[v2054];
  int v1849 = v1841->timer;
  int v2055 = v1849 + ((100 ^ (((~(((v1847 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1847 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) | (~(((v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1845 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1845 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) | (~(((v1846 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1846 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1847 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1847 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) | (~(((v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1841->timer = v2055;
  int * v1851 = v1841->cache_vals;
  bool v2056 = !(((~(((v1845 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1845 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) | (~(((v1846 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1846 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31))) == 0);
  int v1944;
  if (v2056) {
    int * v1852 = v1841->cache_age;
    int v2058 = ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2) + ((~(((v1846 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1846 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) & 1);
    int v1853 = v1852[v2058];
    int v1854 = v1852[v2051];
    int v2059 = v1854 + ((int)((unsigned int)(v1854 - v1853) >> 31));
    v1852[v2051] = v2059;
    int * v1856 = v1841->cache_age;
    int v1857 = v1856[v2052];
    int v2061 = v1857 + ((int)((unsigned int)(v1857 - v1853) >> 31));
    v1856[v2052] = v2061;
    int * v1859 = v1841->cache_age;
    v1859[v2058] = 0;
    v1944 = v2058;
  } else {
    int * v1862 = v1841->cache_age;
    int v2065 = (((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2;
    int v1863 = v1862[v2065];
    int * v1864 = v1841->cache_tags;
    int v1865 = v1864[v2065];
    int v1866 = v1862[v2052];
    int v1867 = v1864[v2052];
    bool v2067 = !(((~(((v1847 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1847 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) | (~(((v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31))) == 0);
    int v1921;
    if (v2067) {
      int * v1868 = v1841->cache_age;
      int v2069 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))) | (-(v1848 ^ ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1))))) >> 31)) & 1);
      int v1869 = v1868[v2069];
      int v1870 = v1868[v2053];
      int v2070 = v1870 + ((int)((unsigned int)(v1870 - v1869) >> 31));
      v1868[v2053] = v2070;
      int * v1872 = v1841->cache_age;
      int v1873 = v1872[v2054];
      int v2072 = v1873 + ((int)((unsigned int)(v1873 - v1869) >> 31));
      v1872[v2054] = v2072;
      int * v1875 = v1841->cache_age;
      v1875[v2069] = 0;
      v1921 = v2069;
    } else {
      int * v1878 = v1841->cache_age;
      int v2076 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2);
      int v1879 = v1878[v2076];
      int * v1880 = v1841->cache_tags;
      int v1881 = v1880[v2076];
      int v1882 = v1878[v2054];
      int v1883 = v1880[v2054];
      int * v1884 = v1841->cache_dirty;
      int v2079 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + ((((v1879 + ((~(((v1881 ^ -1) | (-(v1881 ^ -1))) >> 31)) & 2)) - (v1882 + ((~(((v1883 ^ -1) | (-(v1883 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1885 = v1884[v2079];
      bool v2080 = !(v1885 == 0);
      if (v2080) {
        int * v1886 = v1841->cache_tags;
        int v1887 = v1886[v2079];
        int * v1888 = v1841->cache_vals;
        int v2083 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + ((((v1879 + ((~(((v1881 ^ -1) | (-(v1881 ^ -1))) >> 31)) & 2)) - (v1882 + ((~(((v1883 ^ -1) | (-(v1883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1889 = v1888[v2083];
        int v2084 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + ((((v1879 + ((~(((v1881 ^ -1) | (-(v1881 ^ -1))) >> 31)) & 2)) - (v1882 + ((~(((v1883 ^ -1) | (-(v1883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1890 = v1888[v2084];
        int * v1891 = v1841->mem;
        int v2086 = v1887 * 2;
        v1891[v2086] = v1889;
        int * v1893 = v1841->mem;
        int v2089 = (v1887 * 2) + 1;
        v1893[v2089] = v1890;
        ;
      } else {
        ;
      }
      int * v1898 = v1841->mem;
      int v2094 = ((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) * 2;
      int v1899 = v1898[v2094];
      int v2095 = (((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) * 2) + 1;
      int v1900 = v1898[v2095];
      int * v1901 = v1841->cache_vals;
      int v2097 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + ((((v1879 + ((~(((v1881 ^ -1) | (-(v1881 ^ -1))) >> 31)) & 2)) - (v1882 + ((~(((v1883 ^ -1) | (-(v1883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1901[v2097] = v1899;
      int * v1903 = v1841->cache_vals;
      int v2100 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 3) * 2)) + ((((v1879 + ((~(((v1881 ^ -1) | (-(v1881 ^ -1))) >> 31)) & 2)) - (v1882 + ((~(((v1883 ^ -1) | (-(v1883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1903[v2100] = v1900;
      int * v1905 = v1841->cache_tags;
      int v2103 = (int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1);
      v1905[v2079] = v2103;
      int * v1907 = v1841->cache_dirty;
      v1907[v2079] = 0;
      int * v1909 = v1841->cache_age;
      v1909[v2079] = 1;
      int * v1911 = v1841->cache_age;
      int v1912 = v1911[v2079];
      int v1913 = v1911[v2053];
      int v2109 = v1913 + ((int)((unsigned int)(v1913 - v1912) >> 31));
      v1911[v2053] = v2109;
      int * v1915 = v1841->cache_age;
      int v1916 = v1915[v2054];
      int v2111 = v1916 + ((int)((unsigned int)(v1916 - v1912) >> 31));
      v1915[v2054] = v2111;
      int * v1918 = v1841->cache_age;
      v1918[v2079] = 0;
      v1921 = v2079;
    }
    int * v1922 = v1841->cache_vals;
    int v2114 = v1921 * 2;
    int v1923 = v1922[v2114];
    int v2115 = (v1921 * 2) + 1;
    int v1924 = v1922[v2115];
    int v2116 = (((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2) + ((((v1863 + ((~(((v1865 ^ -1) | (-(v1865 ^ -1))) >> 31)) & 2)) - (v1866 + ((~(((v1867 ^ -1) | (-(v1867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1922[v2116] = v1923;
    int * v1926 = v1841->cache_vals;
    int v2119 = ((((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2) + ((((v1863 + ((~(((v1865 ^ -1) | (-(v1865 ^ -1))) >> 31)) & 2)) - (v1866 + ((~(((v1867 ^ -1) | (-(v1867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1926[v2119] = v1924;
    int * v1928 = v1841->cache_tags;
    int v2122 = ((((int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1)) & 1) * 2) + ((((v1863 + ((~(((v1865 ^ -1) | (-(v1865 ^ -1))) >> 31)) & 2)) - (v1866 + ((~(((v1867 ^ -1) | (-(v1867 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2123 = (int)((unsigned int)((int)((unsigned int)v1843 >> 2)) >> 1);
    v1928[v2122] = v2123;
    int * v1930 = v1841->cache_dirty;
    v1930[v2122] = 0;
    int * v1932 = v1841->cache_age;
    v1932[v2122] = 1;
    int * v1934 = v1841->cache_age;
    int v1935 = v1934[v2122];
    int v1936 = v1934[v2051];
    int v2129 = v1936 + ((int)((unsigned int)(v1936 - v1935) >> 31));
    v1934[v2051] = v2129;
    int * v1938 = v1841->cache_age;
    int v1939 = v1938[v2052];
    int v2131 = v1939 + ((int)((unsigned int)(v1939 - v1935) >> 31));
    v1938[v2052] = v2131;
    int * v1941 = v1841->cache_age;
    v1941[v2122] = 0;
    v1944 = v2122;
  }
  int v2134 = (v1944 * 2) + (((int)((unsigned int)v1843 >> 2)) & 1);
  int v1945 = v1851[v2134];
  int * v1946 = v1841->regs;
  v1946[11] = v1945;
  struct StateT2 * v1948 = slot_7(v1721);
  return v1948;
}

struct StateT2 * slot_5(struct StateT2 * v1678) {
  struct StateT * v1679 = v1678->a;
  int v1680 = v1679->timer;
  struct StateT * v1681 = v1678->b;
  int v1682 = v1681->timer;
  bool v1705 = v1680 == v1682;
  squared_assert(v1705);
  squared_assume(v1705);
  struct StateT * v1685 = v1678->a;
  int v1686 = v1685->timer;
  int v1707 = v1686 + 1;
  v1685->timer = v1707;
  struct StateT * v1688 = v1678->b;
  int v1689 = v1688->timer;
  int v1709 = v1689 + 1;
  v1688->timer = v1709;
  struct StateT * v1691 = v1678->a;
  int * v1692 = v1691->regs;
  int v1693 = v1692[10];
  int v1694 = v1692[8];
  int v1715 = v1693 & v1694;
  v1692[9] = v1715;
  struct StateT * v1696 = v1678->b;
  int * v1697 = v1696->regs;
  int v1698 = v1697[10];
  int v1699 = v1697[8];
  int v1718 = v1698 & v1699;
  v1697[9] = v1718;
  struct StateT2 * v1701 = slot_6(v1678);
  return v1701;
}

struct StateT2 * slot_4(struct StateT2 * v1288) {
  struct StateT * v1289 = v1288->a;
  int v1290 = v1289->timer;
  struct StateT * v1291 = v1288->b;
  int v1292 = v1291->timer;
  bool v1515 = v1290 == v1292;
  squared_assert(v1515);
  squared_assume(v1515);
  struct StateT * v1295 = v1288->a;
  int v1296 = v1295->timer;
  int v1517 = v1296 + 1;
  v1295->timer = v1517;
  struct StateT * v1298 = v1288->b;
  int v1299 = v1298->timer;
  int v1519 = v1299 + 1;
  v1298->timer = v1519;
  struct StateT * v1301 = v1288->a;
  int * v1302 = v1301->cache_tags;
  int v1303 = v1302[0];
  int v1304 = v1302[1];
  int v1305 = v1302[8];
  int v1306 = v1302[9];
  int v1307 = v1301->timer;
  int v1526 = v1307 + ((100 ^ (((~(((v1305 ^ 6) | (-(v1305 ^ 6))) >> 31)) | (~(((v1306 ^ 6) | (-(v1306 ^ 6))) >> 31))) & 104)) ^ (((~(((v1303 ^ 6) | (-(v1303 ^ 6))) >> 31)) | (~(((v1304 ^ 6) | (-(v1304 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v1305 ^ 6) | (-(v1305 ^ 6))) >> 31)) | (~(((v1306 ^ 6) | (-(v1306 ^ 6))) >> 31))) & 104)))));
  v1301->timer = v1526;
  int * v1309 = v1301->cache_vals;
  bool v1527 = !(((~(((v1303 ^ 6) | (-(v1303 ^ 6))) >> 31)) | (~(((v1304 ^ 6) | (-(v1304 ^ 6))) >> 31))) == 0);
  int v1402;
  if (v1527) {
    int * v1310 = v1301->cache_age;
    int v1529 = (~(((v1304 ^ 6) | (-(v1304 ^ 6))) >> 31)) & 1;
    int v1311 = v1310[v1529];
    int v1312 = v1310[0];
    int v1530 = v1312 + ((int)((unsigned int)(v1312 - v1311) >> 31));
    v1310[0] = v1530;
    int * v1314 = v1301->cache_age;
    int v1315 = v1314[1];
    int v1532 = v1315 + ((int)((unsigned int)(v1315 - v1311) >> 31));
    v1314[1] = v1532;
    int * v1317 = v1301->cache_age;
    v1317[v1529] = 0;
    v1402 = v1529;
  } else {
    int * v1320 = v1301->cache_age;
    int v1321 = v1320[0];
    int * v1322 = v1301->cache_tags;
    int v1323 = v1322[0];
    int v1324 = v1320[1];
    int v1325 = v1322[1];
    bool v1536 = !(((~(((v1305 ^ 6) | (-(v1305 ^ 6))) >> 31)) | (~(((v1306 ^ 6) | (-(v1306 ^ 6))) >> 31))) == 0);
    int v1379;
    if (v1536) {
      int * v1326 = v1301->cache_age;
      int v1538 = 8 + ((~(((v1306 ^ 6) | (-(v1306 ^ 6))) >> 31)) & 1);
      int v1327 = v1326[v1538];
      int v1328 = v1326[8];
      int v1539 = v1328 + ((int)((unsigned int)(v1328 - v1327) >> 31));
      v1326[8] = v1539;
      int * v1330 = v1301->cache_age;
      int v1331 = v1330[9];
      int v1541 = v1331 + ((int)((unsigned int)(v1331 - v1327) >> 31));
      v1330[9] = v1541;
      int * v1333 = v1301->cache_age;
      v1333[v1538] = 0;
      v1379 = v1538;
    } else {
      int * v1336 = v1301->cache_age;
      int v1337 = v1336[8];
      int * v1338 = v1301->cache_tags;
      int v1339 = v1338[8];
      int v1340 = v1336[9];
      int v1341 = v1338[9];
      int * v1342 = v1301->cache_dirty;
      int v1546 = 8 + ((((v1337 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2)) - (v1340 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1343 = v1342[v1546];
      bool v1547 = !(v1343 == 0);
      if (v1547) {
        int * v1344 = v1301->cache_tags;
        int v1345 = v1344[v1546];
        int * v1346 = v1301->cache_vals;
        int v1550 = (8 + ((((v1337 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2)) - (v1340 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1347 = v1346[v1550];
        int v1551 = ((8 + ((((v1337 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2)) - (v1340 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1348 = v1346[v1551];
        int * v1349 = v1301->mem;
        int v1553 = v1345 * 2;
        v1349[v1553] = v1347;
        int * v1351 = v1301->mem;
        int v1556 = (v1345 * 2) + 1;
        v1351[v1556] = v1348;
        ;
      } else {
        ;
      }
      int * v1356 = v1301->mem;
      int v1357 = v1356[12];
      int v1358 = v1356[13];
      int * v1359 = v1301->cache_vals;
      int v1564 = (8 + ((((v1337 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2)) - (v1340 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1359[v1564] = v1357;
      int * v1361 = v1301->cache_vals;
      int v1567 = ((8 + ((((v1337 + ((~(((v1339 ^ -1) | (-(v1339 ^ -1))) >> 31)) & 2)) - (v1340 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1361[v1567] = v1358;
      int * v1363 = v1301->cache_tags;
      v1363[v1546] = 6;
      int * v1365 = v1301->cache_dirty;
      v1365[v1546] = 0;
      int * v1367 = v1301->cache_age;
      v1367[v1546] = 1;
      int * v1369 = v1301->cache_age;
      int v1370 = v1369[v1546];
      int v1371 = v1369[8];
      int v1574 = v1371 + ((int)((unsigned int)(v1371 - v1370) >> 31));
      v1369[8] = v1574;
      int * v1373 = v1301->cache_age;
      int v1374 = v1373[9];
      int v1576 = v1374 + ((int)((unsigned int)(v1374 - v1370) >> 31));
      v1373[9] = v1576;
      int * v1376 = v1301->cache_age;
      v1376[v1546] = 0;
      v1379 = v1546;
    }
    int * v1380 = v1301->cache_vals;
    int v1579 = v1379 * 2;
    int v1381 = v1380[v1579];
    int v1580 = (v1379 * 2) + 1;
    int v1382 = v1380[v1580];
    int v1581 = ((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1380[v1581] = v1381;
    int * v1384 = v1301->cache_vals;
    int v1584 = (((((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1384[v1584] = v1382;
    int * v1386 = v1301->cache_tags;
    int v1587 = (((v1321 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2)) - (v1324 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1386[v1587] = 6;
    int * v1388 = v1301->cache_dirty;
    v1388[v1587] = 0;
    int * v1390 = v1301->cache_age;
    v1390[v1587] = 1;
    int * v1392 = v1301->cache_age;
    int v1393 = v1392[v1587];
    int v1394 = v1392[0];
    int v1592 = v1394 + ((int)((unsigned int)(v1394 - v1393) >> 31));
    v1392[0] = v1592;
    int * v1396 = v1301->cache_age;
    int v1397 = v1396[1];
    int v1594 = v1397 + ((int)((unsigned int)(v1397 - v1393) >> 31));
    v1396[1] = v1594;
    int * v1399 = v1301->cache_age;
    v1399[v1587] = 0;
    v1402 = v1587;
  }
  int v1597 = (v1402 * 2) + 1;
  int v1403 = v1309[v1597];
  int * v1404 = v1301->regs;
  v1404[8] = v1403;
  struct StateT * v1406 = v1288->b;
  int * v1407 = v1406->cache_tags;
  int v1408 = v1407[0];
  int v1409 = v1407[1];
  int v1410 = v1407[8];
  int v1411 = v1407[9];
  int v1412 = v1406->timer;
  int v1602 = v1412 + ((100 ^ (((~(((v1410 ^ 6) | (-(v1410 ^ 6))) >> 31)) | (~(((v1411 ^ 6) | (-(v1411 ^ 6))) >> 31))) & 104)) ^ (((~(((v1408 ^ 6) | (-(v1408 ^ 6))) >> 31)) | (~(((v1409 ^ 6) | (-(v1409 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v1410 ^ 6) | (-(v1410 ^ 6))) >> 31)) | (~(((v1411 ^ 6) | (-(v1411 ^ 6))) >> 31))) & 104)))));
  v1406->timer = v1602;
  int * v1414 = v1406->cache_vals;
  bool v1603 = !(((~(((v1408 ^ 6) | (-(v1408 ^ 6))) >> 31)) | (~(((v1409 ^ 6) | (-(v1409 ^ 6))) >> 31))) == 0);
  int v1507;
  if (v1603) {
    int * v1415 = v1406->cache_age;
    int v1605 = (~(((v1409 ^ 6) | (-(v1409 ^ 6))) >> 31)) & 1;
    int v1416 = v1415[v1605];
    int v1417 = v1415[0];
    int v1606 = v1417 + ((int)((unsigned int)(v1417 - v1416) >> 31));
    v1415[0] = v1606;
    int * v1419 = v1406->cache_age;
    int v1420 = v1419[1];
    int v1608 = v1420 + ((int)((unsigned int)(v1420 - v1416) >> 31));
    v1419[1] = v1608;
    int * v1422 = v1406->cache_age;
    v1422[v1605] = 0;
    v1507 = v1605;
  } else {
    int * v1425 = v1406->cache_age;
    int v1426 = v1425[0];
    int * v1427 = v1406->cache_tags;
    int v1428 = v1427[0];
    int v1429 = v1425[1];
    int v1430 = v1427[1];
    bool v1612 = !(((~(((v1410 ^ 6) | (-(v1410 ^ 6))) >> 31)) | (~(((v1411 ^ 6) | (-(v1411 ^ 6))) >> 31))) == 0);
    int v1484;
    if (v1612) {
      int * v1431 = v1406->cache_age;
      int v1614 = 8 + ((~(((v1411 ^ 6) | (-(v1411 ^ 6))) >> 31)) & 1);
      int v1432 = v1431[v1614];
      int v1433 = v1431[8];
      int v1615 = v1433 + ((int)((unsigned int)(v1433 - v1432) >> 31));
      v1431[8] = v1615;
      int * v1435 = v1406->cache_age;
      int v1436 = v1435[9];
      int v1617 = v1436 + ((int)((unsigned int)(v1436 - v1432) >> 31));
      v1435[9] = v1617;
      int * v1438 = v1406->cache_age;
      v1438[v1614] = 0;
      v1484 = v1614;
    } else {
      int * v1441 = v1406->cache_age;
      int v1442 = v1441[8];
      int * v1443 = v1406->cache_tags;
      int v1444 = v1443[8];
      int v1445 = v1441[9];
      int v1446 = v1443[9];
      int * v1447 = v1406->cache_dirty;
      int v1622 = 8 + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1448 = v1447[v1622];
      bool v1623 = !(v1448 == 0);
      if (v1623) {
        int * v1449 = v1406->cache_tags;
        int v1450 = v1449[v1622];
        int * v1451 = v1406->cache_vals;
        int v1626 = (8 + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1452 = v1451[v1626];
        int v1627 = ((8 + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1453 = v1451[v1627];
        int * v1454 = v1406->mem;
        int v1629 = v1450 * 2;
        v1454[v1629] = v1452;
        int * v1456 = v1406->mem;
        int v1632 = (v1450 * 2) + 1;
        v1456[v1632] = v1453;
        ;
      } else {
        ;
      }
      int * v1461 = v1406->mem;
      int v1462 = v1461[12];
      int v1463 = v1461[13];
      int * v1464 = v1406->cache_vals;
      int v1640 = (8 + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1464[v1640] = v1462;
      int * v1466 = v1406->cache_vals;
      int v1643 = ((8 + ((((v1442 + ((~(((v1444 ^ -1) | (-(v1444 ^ -1))) >> 31)) & 2)) - (v1445 + ((~(((v1446 ^ -1) | (-(v1446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1466[v1643] = v1463;
      int * v1468 = v1406->cache_tags;
      v1468[v1622] = 6;
      int * v1470 = v1406->cache_dirty;
      v1470[v1622] = 0;
      int * v1472 = v1406->cache_age;
      v1472[v1622] = 1;
      int * v1474 = v1406->cache_age;
      int v1475 = v1474[v1622];
      int v1476 = v1474[8];
      int v1650 = v1476 + ((int)((unsigned int)(v1476 - v1475) >> 31));
      v1474[8] = v1650;
      int * v1478 = v1406->cache_age;
      int v1479 = v1478[9];
      int v1652 = v1479 + ((int)((unsigned int)(v1479 - v1475) >> 31));
      v1478[9] = v1652;
      int * v1481 = v1406->cache_age;
      v1481[v1622] = 0;
      v1484 = v1622;
    }
    int * v1485 = v1406->cache_vals;
    int v1655 = v1484 * 2;
    int v1486 = v1485[v1655];
    int v1656 = (v1484 * 2) + 1;
    int v1487 = v1485[v1656];
    int v1657 = ((((v1426 + ((~(((v1428 ^ -1) | (-(v1428 ^ -1))) >> 31)) & 2)) - (v1429 + ((~(((v1430 ^ -1) | (-(v1430 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1485[v1657] = v1486;
    int * v1489 = v1406->cache_vals;
    int v1660 = (((((v1426 + ((~(((v1428 ^ -1) | (-(v1428 ^ -1))) >> 31)) & 2)) - (v1429 + ((~(((v1430 ^ -1) | (-(v1430 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1489[v1660] = v1487;
    int * v1491 = v1406->cache_tags;
    int v1663 = (((v1426 + ((~(((v1428 ^ -1) | (-(v1428 ^ -1))) >> 31)) & 2)) - (v1429 + ((~(((v1430 ^ -1) | (-(v1430 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1491[v1663] = 6;
    int * v1493 = v1406->cache_dirty;
    v1493[v1663] = 0;
    int * v1495 = v1406->cache_age;
    v1495[v1663] = 1;
    int * v1497 = v1406->cache_age;
    int v1498 = v1497[v1663];
    int v1499 = v1497[0];
    int v1668 = v1499 + ((int)((unsigned int)(v1499 - v1498) >> 31));
    v1497[0] = v1668;
    int * v1501 = v1406->cache_age;
    int v1502 = v1501[1];
    int v1670 = v1502 + ((int)((unsigned int)(v1502 - v1498) >> 31));
    v1501[1] = v1670;
    int * v1504 = v1406->cache_age;
    v1504[v1663] = 0;
    v1507 = v1663;
  }
  int v1673 = (v1507 * 2) + 1;
  int v1508 = v1414[v1673];
  int * v1509 = v1406->regs;
  v1509[8] = v1508;
  struct StateT2 * v1511 = slot_5(v1288);
  return v1511;
}

struct StateT2 * slot_2(struct StateT2 * v645) {
  struct StateT * v646 = v645->a;
  int v647 = v646->timer;
  struct StateT * v648 = v645->b;
  int v649 = v648->timer;
  bool v668 = v647 == v649;
  squared_assert(v668);
  squared_assume(v668);
  struct StateT * v652 = v645->a;
  int v653 = v652->timer;
  int v670 = v653 + 1;
  v652->timer = v670;
  struct StateT * v655 = v645->b;
  int v656 = v655->timer;
  int v672 = v656 + 1;
  v655->timer = v672;
  struct StateT * v658 = v645->a;
  int * v659 = v658->regs;
  v659[7] = 28;
  struct StateT * v661 = v645->b;
  int * v662 = v661->regs;
  v662[7] = 28;
  struct StateT2 * v664 = slot_3(v645);
  return v664;
}

struct StateT2 * slot_7(struct StateT2 * v2139) {
  struct StateT * v2140 = v2139->a;
  int v2141 = v2140->timer;
  struct StateT * v2142 = v2139->b;
  int v2143 = v2142->timer;
  bool v2369 = v2141 == v2143;
  squared_assert(v2369);
  squared_assume(v2369);
  struct StateT * v2146 = v2139->a;
  int v2147 = v2146->timer;
  int v2371 = v2147 + 1;
  v2146->timer = v2371;
  struct StateT * v2149 = v2139->b;
  int v2150 = v2149->timer;
  int v2373 = v2150 + 1;
  v2149->timer = v2373;
  struct StateT * v2152 = v2139->a;
  int * v2153 = v2152->regs;
  int v2154 = v2153[11];
  int * v2155 = v2152->cache_tags;
  int v2378 = (((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2;
  int v2156 = v2155[v2378];
  int v2379 = ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2157 = v2155[v2379];
  int v2380 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2);
  int v2158 = v2155[v2380];
  int v2381 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2159 = v2155[v2381];
  int v2160 = v2152->timer;
  int v2382 = v2160 + ((100 ^ (((~(((v2158 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2158 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) | (~(((v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2156 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2156 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) | (~(((v2157 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2157 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2158 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2158 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) | (~(((v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2152->timer = v2382;
  int * v2162 = v2152->cache_vals;
  bool v2383 = !(((~(((v2156 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2156 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) | (~(((v2157 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2157 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31))) == 0);
  int v2255;
  if (v2383) {
    int * v2163 = v2152->cache_age;
    int v2385 = ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2) + ((~(((v2157 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2157 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) & 1);
    int v2164 = v2163[v2385];
    int v2165 = v2163[v2378];
    int v2386 = v2165 + ((int)((unsigned int)(v2165 - v2164) >> 31));
    v2163[v2378] = v2386;
    int * v2167 = v2152->cache_age;
    int v2168 = v2167[v2379];
    int v2388 = v2168 + ((int)((unsigned int)(v2168 - v2164) >> 31));
    v2167[v2379] = v2388;
    int * v2170 = v2152->cache_age;
    v2170[v2385] = 0;
    v2255 = v2385;
  } else {
    int * v2173 = v2152->cache_age;
    int v2392 = (((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2;
    int v2174 = v2173[v2392];
    int * v2175 = v2152->cache_tags;
    int v2176 = v2175[v2392];
    int v2177 = v2173[v2379];
    int v2178 = v2175[v2379];
    bool v2394 = !(((~(((v2158 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2158 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) | (~(((v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31))) == 0);
    int v2232;
    if (v2394) {
      int * v2179 = v2152->cache_age;
      int v2396 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))) | (-(v2159 ^ ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1))))) >> 31)) & 1);
      int v2180 = v2179[v2396];
      int v2181 = v2179[v2380];
      int v2397 = v2181 + ((int)((unsigned int)(v2181 - v2180) >> 31));
      v2179[v2380] = v2397;
      int * v2183 = v2152->cache_age;
      int v2184 = v2183[v2381];
      int v2399 = v2184 + ((int)((unsigned int)(v2184 - v2180) >> 31));
      v2183[v2381] = v2399;
      int * v2186 = v2152->cache_age;
      v2186[v2396] = 0;
      v2232 = v2396;
    } else {
      int * v2189 = v2152->cache_age;
      int v2403 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2);
      int v2190 = v2189[v2403];
      int * v2191 = v2152->cache_tags;
      int v2192 = v2191[v2403];
      int v2193 = v2189[v2381];
      int v2194 = v2191[v2381];
      int * v2195 = v2152->cache_dirty;
      int v2406 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + ((((v2190 + ((~(((v2192 ^ -1) | (-(v2192 ^ -1))) >> 31)) & 2)) - (v2193 + ((~(((v2194 ^ -1) | (-(v2194 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2196 = v2195[v2406];
      bool v2407 = !(v2196 == 0);
      if (v2407) {
        int * v2197 = v2152->cache_tags;
        int v2198 = v2197[v2406];
        int * v2199 = v2152->cache_vals;
        int v2410 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + ((((v2190 + ((~(((v2192 ^ -1) | (-(v2192 ^ -1))) >> 31)) & 2)) - (v2193 + ((~(((v2194 ^ -1) | (-(v2194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2200 = v2199[v2410];
        int v2411 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + ((((v2190 + ((~(((v2192 ^ -1) | (-(v2192 ^ -1))) >> 31)) & 2)) - (v2193 + ((~(((v2194 ^ -1) | (-(v2194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2201 = v2199[v2411];
        int * v2202 = v2152->mem;
        int v2413 = v2198 * 2;
        v2202[v2413] = v2200;
        int * v2204 = v2152->mem;
        int v2416 = (v2198 * 2) + 1;
        v2204[v2416] = v2201;
        ;
      } else {
        ;
      }
      int * v2209 = v2152->mem;
      int v2421 = ((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) * 2;
      int v2210 = v2209[v2421];
      int v2422 = (((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) * 2) + 1;
      int v2211 = v2209[v2422];
      int * v2212 = v2152->cache_vals;
      int v2424 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + ((((v2190 + ((~(((v2192 ^ -1) | (-(v2192 ^ -1))) >> 31)) & 2)) - (v2193 + ((~(((v2194 ^ -1) | (-(v2194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2212[v2424] = v2210;
      int * v2214 = v2152->cache_vals;
      int v2427 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 3) * 2)) + ((((v2190 + ((~(((v2192 ^ -1) | (-(v2192 ^ -1))) >> 31)) & 2)) - (v2193 + ((~(((v2194 ^ -1) | (-(v2194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2214[v2427] = v2211;
      int * v2216 = v2152->cache_tags;
      int v2430 = (int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1);
      v2216[v2406] = v2430;
      int * v2218 = v2152->cache_dirty;
      v2218[v2406] = 0;
      int * v2220 = v2152->cache_age;
      v2220[v2406] = 1;
      int * v2222 = v2152->cache_age;
      int v2223 = v2222[v2406];
      int v2224 = v2222[v2380];
      int v2436 = v2224 + ((int)((unsigned int)(v2224 - v2223) >> 31));
      v2222[v2380] = v2436;
      int * v2226 = v2152->cache_age;
      int v2227 = v2226[v2381];
      int v2438 = v2227 + ((int)((unsigned int)(v2227 - v2223) >> 31));
      v2226[v2381] = v2438;
      int * v2229 = v2152->cache_age;
      v2229[v2406] = 0;
      v2232 = v2406;
    }
    int * v2233 = v2152->cache_vals;
    int v2441 = v2232 * 2;
    int v2234 = v2233[v2441];
    int v2442 = (v2232 * 2) + 1;
    int v2235 = v2233[v2442];
    int v2443 = (((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2) + ((((v2174 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2)) - (v2177 + ((~(((v2178 ^ -1) | (-(v2178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2233[v2443] = v2234;
    int * v2237 = v2152->cache_vals;
    int v2446 = ((((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2) + ((((v2174 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2)) - (v2177 + ((~(((v2178 ^ -1) | (-(v2178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2237[v2446] = v2235;
    int * v2239 = v2152->cache_tags;
    int v2449 = ((((int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1)) & 1) * 2) + ((((v2174 + ((~(((v2176 ^ -1) | (-(v2176 ^ -1))) >> 31)) & 2)) - (v2177 + ((~(((v2178 ^ -1) | (-(v2178 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2450 = (int)((unsigned int)((int)((unsigned int)v2154 >> 2)) >> 1);
    v2239[v2449] = v2450;
    int * v2241 = v2152->cache_dirty;
    v2241[v2449] = 0;
    int * v2243 = v2152->cache_age;
    v2243[v2449] = 1;
    int * v2245 = v2152->cache_age;
    int v2246 = v2245[v2449];
    int v2247 = v2245[v2378];
    int v2456 = v2247 + ((int)((unsigned int)(v2247 - v2246) >> 31));
    v2245[v2378] = v2456;
    int * v2249 = v2152->cache_age;
    int v2250 = v2249[v2379];
    int v2458 = v2250 + ((int)((unsigned int)(v2250 - v2246) >> 31));
    v2249[v2379] = v2458;
    int * v2252 = v2152->cache_age;
    v2252[v2449] = 0;
    v2255 = v2449;
  }
  int v2461 = (v2255 * 2) + (((int)((unsigned int)v2154 >> 2)) & 1);
  int v2256 = v2162[v2461];
  int * v2257 = v2152->regs;
  v2257[12] = v2256;
  struct StateT * v2259 = v2139->b;
  int * v2260 = v2259->regs;
  int v2261 = v2260[11];
  int * v2262 = v2259->cache_tags;
  int v2468 = (((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2;
  int v2263 = v2262[v2468];
  int v2469 = ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2264 = v2262[v2469];
  int v2470 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2);
  int v2265 = v2262[v2470];
  int v2471 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2266 = v2262[v2471];
  int v2267 = v2259->timer;
  int v2472 = v2267 + ((100 ^ (((~(((v2265 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2265 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) | (~(((v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2263 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2263 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) | (~(((v2264 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2264 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2265 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2265 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) | (~(((v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2259->timer = v2472;
  int * v2269 = v2259->cache_vals;
  bool v2473 = !(((~(((v2263 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2263 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) | (~(((v2264 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2264 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31))) == 0);
  int v2362;
  if (v2473) {
    int * v2270 = v2259->cache_age;
    int v2475 = ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2) + ((~(((v2264 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2264 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) & 1);
    int v2271 = v2270[v2475];
    int v2272 = v2270[v2468];
    int v2476 = v2272 + ((int)((unsigned int)(v2272 - v2271) >> 31));
    v2270[v2468] = v2476;
    int * v2274 = v2259->cache_age;
    int v2275 = v2274[v2469];
    int v2478 = v2275 + ((int)((unsigned int)(v2275 - v2271) >> 31));
    v2274[v2469] = v2478;
    int * v2277 = v2259->cache_age;
    v2277[v2475] = 0;
    v2362 = v2475;
  } else {
    int * v2280 = v2259->cache_age;
    int v2482 = (((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2;
    int v2281 = v2280[v2482];
    int * v2282 = v2259->cache_tags;
    int v2283 = v2282[v2482];
    int v2284 = v2280[v2469];
    int v2285 = v2282[v2469];
    bool v2484 = !(((~(((v2265 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2265 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) | (~(((v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31))) == 0);
    int v2339;
    if (v2484) {
      int * v2286 = v2259->cache_age;
      int v2486 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))) | (-(v2266 ^ ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1))))) >> 31)) & 1);
      int v2287 = v2286[v2486];
      int v2288 = v2286[v2470];
      int v2487 = v2288 + ((int)((unsigned int)(v2288 - v2287) >> 31));
      v2286[v2470] = v2487;
      int * v2290 = v2259->cache_age;
      int v2291 = v2290[v2471];
      int v2489 = v2291 + ((int)((unsigned int)(v2291 - v2287) >> 31));
      v2290[v2471] = v2489;
      int * v2293 = v2259->cache_age;
      v2293[v2486] = 0;
      v2339 = v2486;
    } else {
      int * v2296 = v2259->cache_age;
      int v2493 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2);
      int v2297 = v2296[v2493];
      int * v2298 = v2259->cache_tags;
      int v2299 = v2298[v2493];
      int v2300 = v2296[v2471];
      int v2301 = v2298[v2471];
      int * v2302 = v2259->cache_dirty;
      int v2496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + ((((v2297 + ((~(((v2299 ^ -1) | (-(v2299 ^ -1))) >> 31)) & 2)) - (v2300 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2303 = v2302[v2496];
      bool v2497 = !(v2303 == 0);
      if (v2497) {
        int * v2304 = v2259->cache_tags;
        int v2305 = v2304[v2496];
        int * v2306 = v2259->cache_vals;
        int v2500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + ((((v2297 + ((~(((v2299 ^ -1) | (-(v2299 ^ -1))) >> 31)) & 2)) - (v2300 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2307 = v2306[v2500];
        int v2501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + ((((v2297 + ((~(((v2299 ^ -1) | (-(v2299 ^ -1))) >> 31)) & 2)) - (v2300 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2308 = v2306[v2501];
        int * v2309 = v2259->mem;
        int v2503 = v2305 * 2;
        v2309[v2503] = v2307;
        int * v2311 = v2259->mem;
        int v2506 = (v2305 * 2) + 1;
        v2311[v2506] = v2308;
        ;
      } else {
        ;
      }
      int * v2316 = v2259->mem;
      int v2511 = ((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) * 2;
      int v2317 = v2316[v2511];
      int v2512 = (((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) * 2) + 1;
      int v2318 = v2316[v2512];
      int * v2319 = v2259->cache_vals;
      int v2514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + ((((v2297 + ((~(((v2299 ^ -1) | (-(v2299 ^ -1))) >> 31)) & 2)) - (v2300 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2319[v2514] = v2317;
      int * v2321 = v2259->cache_vals;
      int v2517 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 3) * 2)) + ((((v2297 + ((~(((v2299 ^ -1) | (-(v2299 ^ -1))) >> 31)) & 2)) - (v2300 + ((~(((v2301 ^ -1) | (-(v2301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2321[v2517] = v2318;
      int * v2323 = v2259->cache_tags;
      int v2520 = (int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1);
      v2323[v2496] = v2520;
      int * v2325 = v2259->cache_dirty;
      v2325[v2496] = 0;
      int * v2327 = v2259->cache_age;
      v2327[v2496] = 1;
      int * v2329 = v2259->cache_age;
      int v2330 = v2329[v2496];
      int v2331 = v2329[v2470];
      int v2526 = v2331 + ((int)((unsigned int)(v2331 - v2330) >> 31));
      v2329[v2470] = v2526;
      int * v2333 = v2259->cache_age;
      int v2334 = v2333[v2471];
      int v2528 = v2334 + ((int)((unsigned int)(v2334 - v2330) >> 31));
      v2333[v2471] = v2528;
      int * v2336 = v2259->cache_age;
      v2336[v2496] = 0;
      v2339 = v2496;
    }
    int * v2340 = v2259->cache_vals;
    int v2531 = v2339 * 2;
    int v2341 = v2340[v2531];
    int v2532 = (v2339 * 2) + 1;
    int v2342 = v2340[v2532];
    int v2533 = (((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2) + ((((v2281 + ((~(((v2283 ^ -1) | (-(v2283 ^ -1))) >> 31)) & 2)) - (v2284 + ((~(((v2285 ^ -1) | (-(v2285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2340[v2533] = v2341;
    int * v2344 = v2259->cache_vals;
    int v2536 = ((((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2) + ((((v2281 + ((~(((v2283 ^ -1) | (-(v2283 ^ -1))) >> 31)) & 2)) - (v2284 + ((~(((v2285 ^ -1) | (-(v2285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2344[v2536] = v2342;
    int * v2346 = v2259->cache_tags;
    int v2539 = ((((int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1)) & 1) * 2) + ((((v2281 + ((~(((v2283 ^ -1) | (-(v2283 ^ -1))) >> 31)) & 2)) - (v2284 + ((~(((v2285 ^ -1) | (-(v2285 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2540 = (int)((unsigned int)((int)((unsigned int)v2261 >> 2)) >> 1);
    v2346[v2539] = v2540;
    int * v2348 = v2259->cache_dirty;
    v2348[v2539] = 0;
    int * v2350 = v2259->cache_age;
    v2350[v2539] = 1;
    int * v2352 = v2259->cache_age;
    int v2353 = v2352[v2539];
    int v2354 = v2352[v2468];
    int v2546 = v2354 + ((int)((unsigned int)(v2354 - v2353) >> 31));
    v2352[v2468] = v2546;
    int * v2356 = v2259->cache_age;
    int v2357 = v2356[v2469];
    int v2548 = v2357 + ((int)((unsigned int)(v2357 - v2353) >> 31));
    v2356[v2469] = v2548;
    int * v2359 = v2259->cache_age;
    v2359[v2539] = 0;
    v2362 = v2539;
  }
  int v2551 = (v2362 * 2) + (((int)((unsigned int)v2261 >> 2)) & 1);
  int v2363 = v2269[v2551];
  int * v2364 = v2259->regs;
  v2364[12] = v2363;
  return v2139;
}

struct StateT2 * slot_3(struct StateT2 * v681) {
  struct StateT * v682 = v681->a;
  int v683 = v682->timer;
  struct StateT * v684 = v681->b;
  int v685 = v684->timer;
  bool v1030 = v683 == v685;
  squared_assert(v1030);
  squared_assume(v1030);
  struct StateT * v688 = v681->a;
  int v689 = v688->timer;
  int v1032 = v689 + 1;
  v688->timer = v1032;
  struct StateT * v691 = v681->b;
  int v692 = v691->timer;
  int v1034 = v692 + 1;
  v691->timer = v1034;
  struct StateT * v694 = v681->a;
  int * v695 = v694->regs;
  int v696 = v695[7];
  int * v697 = v694->cache_tags;
  int v698 = v697[0];
  int v699 = v697[1];
  int v700 = v697[8];
  int v701 = v697[9];
  int v702 = v694->timer;
  int v1043 = v702 + ((100 ^ (((~(((v700 ^ 6) | (-(v700 ^ 6))) >> 31)) | (~(((v701 ^ 6) | (-(v701 ^ 6))) >> 31))) & 104)) ^ (((~(((v698 ^ 6) | (-(v698 ^ 6))) >> 31)) | (~(((v699 ^ 6) | (-(v699 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v700 ^ 6) | (-(v700 ^ 6))) >> 31)) | (~(((v701 ^ 6) | (-(v701 ^ 6))) >> 31))) & 104)))));
  v694->timer = v1043;
  bool v1044 = !(((~(((v698 ^ 6) | (-(v698 ^ 6))) >> 31)) | (~(((v699 ^ 6) | (-(v699 ^ 6))) >> 31))) == 0);
  int v796;
  if (v1044) {
    int * v704 = v694->cache_age;
    int v1046 = (~(((v699 ^ 6) | (-(v699 ^ 6))) >> 31)) & 1;
    int v705 = v704[v1046];
    int v706 = v704[0];
    int v1047 = v706 + ((int)((unsigned int)(v706 - v705) >> 31));
    v704[0] = v1047;
    int * v708 = v694->cache_age;
    int v709 = v708[1];
    int v1049 = v709 + ((int)((unsigned int)(v709 - v705) >> 31));
    v708[1] = v1049;
    int * v711 = v694->cache_age;
    v711[v1046] = 0;
    v796 = v1046;
  } else {
    int * v714 = v694->cache_age;
    int v715 = v714[0];
    int * v716 = v694->cache_tags;
    int v717 = v716[0];
    int v718 = v714[1];
    int v719 = v716[1];
    bool v1053 = !(((~(((v700 ^ 6) | (-(v700 ^ 6))) >> 31)) | (~(((v701 ^ 6) | (-(v701 ^ 6))) >> 31))) == 0);
    int v773;
    if (v1053) {
      int * v720 = v694->cache_age;
      int v1055 = 8 + ((~(((v701 ^ 6) | (-(v701 ^ 6))) >> 31)) & 1);
      int v721 = v720[v1055];
      int v722 = v720[8];
      int v1056 = v722 + ((int)((unsigned int)(v722 - v721) >> 31));
      v720[8] = v1056;
      int * v724 = v694->cache_age;
      int v725 = v724[9];
      int v1058 = v725 + ((int)((unsigned int)(v725 - v721) >> 31));
      v724[9] = v1058;
      int * v727 = v694->cache_age;
      v727[v1055] = 0;
      v773 = v1055;
    } else {
      int * v730 = v694->cache_age;
      int v731 = v730[8];
      int * v732 = v694->cache_tags;
      int v733 = v732[8];
      int v734 = v730[9];
      int v735 = v732[9];
      int * v736 = v694->cache_dirty;
      int v1063 = 8 + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v737 = v736[v1063];
      bool v1064 = !(v737 == 0);
      if (v1064) {
        int * v738 = v694->cache_tags;
        int v739 = v738[v1063];
        int * v740 = v694->cache_vals;
        int v1067 = (8 + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v741 = v740[v1067];
        int v1068 = ((8 + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v742 = v740[v1068];
        int * v743 = v694->mem;
        int v1070 = v739 * 2;
        v743[v1070] = v741;
        int * v745 = v694->mem;
        int v1073 = (v739 * 2) + 1;
        v745[v1073] = v742;
        ;
      } else {
        ;
      }
      int * v750 = v694->mem;
      int v751 = v750[12];
      int v752 = v750[13];
      int * v753 = v694->cache_vals;
      int v1081 = (8 + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v753[v1081] = v751;
      int * v755 = v694->cache_vals;
      int v1084 = ((8 + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v755[v1084] = v752;
      int * v757 = v694->cache_tags;
      v757[v1063] = 6;
      int * v759 = v694->cache_dirty;
      v759[v1063] = 0;
      int * v761 = v694->cache_age;
      v761[v1063] = 1;
      int * v763 = v694->cache_age;
      int v764 = v763[v1063];
      int v765 = v763[8];
      int v1091 = v765 + ((int)((unsigned int)(v765 - v764) >> 31));
      v763[8] = v1091;
      int * v767 = v694->cache_age;
      int v768 = v767[9];
      int v1093 = v768 + ((int)((unsigned int)(v768 - v764) >> 31));
      v767[9] = v1093;
      int * v770 = v694->cache_age;
      v770[v1063] = 0;
      v773 = v1063;
    }
    int * v774 = v694->cache_vals;
    int v1096 = v773 * 2;
    int v775 = v774[v1096];
    int v1097 = (v773 * 2) + 1;
    int v776 = v774[v1097];
    int v1098 = ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v774[v1098] = v775;
    int * v778 = v694->cache_vals;
    int v1101 = (((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v778[v1101] = v776;
    int * v780 = v694->cache_tags;
    int v1104 = (((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v780[v1104] = 6;
    int * v782 = v694->cache_dirty;
    v782[v1104] = 0;
    int * v784 = v694->cache_age;
    v784[v1104] = 1;
    int * v786 = v694->cache_age;
    int v787 = v786[v1104];
    int v788 = v786[0];
    int v1109 = v788 + ((int)((unsigned int)(v788 - v787) >> 31));
    v786[0] = v1109;
    int * v790 = v694->cache_age;
    int v791 = v790[1];
    int v1111 = v791 + ((int)((unsigned int)(v791 - v787) >> 31));
    v790[1] = v1111;
    int * v793 = v694->cache_age;
    v793[v1104] = 0;
    v796 = v1104;
  }
  int * v797 = v694->cache_vals;
  int v1114 = (v796 * 2) + 1;
  v797[v1114] = v696;
  int * v799 = v694->cache_tags;
  int v800 = v799[8];
  int v801 = v799[9];
  bool v1117 = !(((~(((v800 ^ 6) | (-(v800 ^ 6))) >> 31)) | (~(((v801 ^ 6) | (-(v801 ^ 6))) >> 31))) == 0);
  int v855;
  if (v1117) {
    int * v802 = v694->cache_age;
    int v1119 = 8 + ((~(((v801 ^ 6) | (-(v801 ^ 6))) >> 31)) & 1);
    int v803 = v802[v1119];
    int v804 = v802[8];
    int v1120 = v804 + ((int)((unsigned int)(v804 - v803) >> 31));
    v802[8] = v1120;
    int * v806 = v694->cache_age;
    int v807 = v806[9];
    int v1122 = v807 + ((int)((unsigned int)(v807 - v803) >> 31));
    v806[9] = v1122;
    int * v809 = v694->cache_age;
    v809[v1119] = 0;
    v855 = v1119;
  } else {
    int * v812 = v694->cache_age;
    int v813 = v812[8];
    int * v814 = v694->cache_tags;
    int v815 = v814[8];
    int v816 = v812[9];
    int v817 = v814[9];
    int * v818 = v694->cache_dirty;
    int v1127 = 8 + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v819 = v818[v1127];
    bool v1128 = !(v819 == 0);
    if (v1128) {
      int * v820 = v694->cache_tags;
      int v821 = v820[v1127];
      int * v822 = v694->cache_vals;
      int v1131 = (8 + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v823 = v822[v1131];
      int v1132 = ((8 + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v824 = v822[v1132];
      int * v825 = v694->mem;
      int v1134 = v821 * 2;
      v825[v1134] = v823;
      int * v827 = v694->mem;
      int v1137 = (v821 * 2) + 1;
      v827[v1137] = v824;
      ;
    } else {
      ;
    }
    int * v832 = v694->mem;
    int v833 = v832[12];
    int v834 = v832[13];
    int * v835 = v694->cache_vals;
    int v1145 = (8 + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v835[v1145] = v833;
    int * v837 = v694->cache_vals;
    int v1148 = ((8 + ((((v813 + ((~(((v815 ^ -1) | (-(v815 ^ -1))) >> 31)) & 2)) - (v816 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v837[v1148] = v834;
    int * v839 = v694->cache_tags;
    v839[v1127] = 6;
    int * v841 = v694->cache_dirty;
    v841[v1127] = 0;
    int * v843 = v694->cache_age;
    v843[v1127] = 1;
    int * v845 = v694->cache_age;
    int v846 = v845[v1127];
    int v847 = v845[8];
    int v1155 = v847 + ((int)((unsigned int)(v847 - v846) >> 31));
    v845[8] = v1155;
    int * v849 = v694->cache_age;
    int v850 = v849[9];
    int v1157 = v850 + ((int)((unsigned int)(v850 - v846) >> 31));
    v849[9] = v1157;
    int * v852 = v694->cache_age;
    v852[v1127] = 0;
    v855 = v1127;
  }
  int * v856 = v694->cache_vals;
  int v1160 = (v855 * 2) + 1;
  v856[v1160] = v696;
  int * v858 = v694->cache_dirty;
  v858[v855] = 1;
  struct StateT * v860 = v681->b;
  int * v861 = v860->regs;
  int v862 = v861[7];
  int * v863 = v860->cache_tags;
  int v864 = v863[0];
  int v865 = v863[1];
  int v866 = v863[8];
  int v867 = v863[9];
  int v868 = v860->timer;
  int v1166 = v868 + ((100 ^ (((~(((v866 ^ 6) | (-(v866 ^ 6))) >> 31)) | (~(((v867 ^ 6) | (-(v867 ^ 6))) >> 31))) & 104)) ^ (((~(((v864 ^ 6) | (-(v864 ^ 6))) >> 31)) | (~(((v865 ^ 6) | (-(v865 ^ 6))) >> 31))) & (1 ^ (100 ^ (((~(((v866 ^ 6) | (-(v866 ^ 6))) >> 31)) | (~(((v867 ^ 6) | (-(v867 ^ 6))) >> 31))) & 104)))));
  v860->timer = v1166;
  bool v1167 = !(((~(((v864 ^ 6) | (-(v864 ^ 6))) >> 31)) | (~(((v865 ^ 6) | (-(v865 ^ 6))) >> 31))) == 0);
  int v962;
  if (v1167) {
    int * v870 = v860->cache_age;
    int v1169 = (~(((v865 ^ 6) | (-(v865 ^ 6))) >> 31)) & 1;
    int v871 = v870[v1169];
    int v872 = v870[0];
    int v1170 = v872 + ((int)((unsigned int)(v872 - v871) >> 31));
    v870[0] = v1170;
    int * v874 = v860->cache_age;
    int v875 = v874[1];
    int v1172 = v875 + ((int)((unsigned int)(v875 - v871) >> 31));
    v874[1] = v1172;
    int * v877 = v860->cache_age;
    v877[v1169] = 0;
    v962 = v1169;
  } else {
    int * v880 = v860->cache_age;
    int v881 = v880[0];
    int * v882 = v860->cache_tags;
    int v883 = v882[0];
    int v884 = v880[1];
    int v885 = v882[1];
    bool v1176 = !(((~(((v866 ^ 6) | (-(v866 ^ 6))) >> 31)) | (~(((v867 ^ 6) | (-(v867 ^ 6))) >> 31))) == 0);
    int v939;
    if (v1176) {
      int * v886 = v860->cache_age;
      int v1178 = 8 + ((~(((v867 ^ 6) | (-(v867 ^ 6))) >> 31)) & 1);
      int v887 = v886[v1178];
      int v888 = v886[8];
      int v1179 = v888 + ((int)((unsigned int)(v888 - v887) >> 31));
      v886[8] = v1179;
      int * v890 = v860->cache_age;
      int v891 = v890[9];
      int v1181 = v891 + ((int)((unsigned int)(v891 - v887) >> 31));
      v890[9] = v1181;
      int * v893 = v860->cache_age;
      v893[v1178] = 0;
      v939 = v1178;
    } else {
      int * v896 = v860->cache_age;
      int v897 = v896[8];
      int * v898 = v860->cache_tags;
      int v899 = v898[8];
      int v900 = v896[9];
      int v901 = v898[9];
      int * v902 = v860->cache_dirty;
      int v1186 = 8 + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v903 = v902[v1186];
      bool v1187 = !(v903 == 0);
      if (v1187) {
        int * v904 = v860->cache_tags;
        int v905 = v904[v1186];
        int * v906 = v860->cache_vals;
        int v1190 = (8 + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v907 = v906[v1190];
        int v1191 = ((8 + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v908 = v906[v1191];
        int * v909 = v860->mem;
        int v1193 = v905 * 2;
        v909[v1193] = v907;
        int * v911 = v860->mem;
        int v1196 = (v905 * 2) + 1;
        v911[v1196] = v908;
        ;
      } else {
        ;
      }
      int * v916 = v860->mem;
      int v917 = v916[12];
      int v918 = v916[13];
      int * v919 = v860->cache_vals;
      int v1204 = (8 + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v919[v1204] = v917;
      int * v921 = v860->cache_vals;
      int v1207 = ((8 + ((((v897 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2)) - (v900 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v921[v1207] = v918;
      int * v923 = v860->cache_tags;
      v923[v1186] = 6;
      int * v925 = v860->cache_dirty;
      v925[v1186] = 0;
      int * v927 = v860->cache_age;
      v927[v1186] = 1;
      int * v929 = v860->cache_age;
      int v930 = v929[v1186];
      int v931 = v929[8];
      int v1214 = v931 + ((int)((unsigned int)(v931 - v930) >> 31));
      v929[8] = v1214;
      int * v933 = v860->cache_age;
      int v934 = v933[9];
      int v1216 = v934 + ((int)((unsigned int)(v934 - v930) >> 31));
      v933[9] = v1216;
      int * v936 = v860->cache_age;
      v936[v1186] = 0;
      v939 = v1186;
    }
    int * v940 = v860->cache_vals;
    int v1219 = v939 * 2;
    int v941 = v940[v1219];
    int v1220 = (v939 * 2) + 1;
    int v942 = v940[v1220];
    int v1221 = ((((v881 + ((~(((v883 ^ -1) | (-(v883 ^ -1))) >> 31)) & 2)) - (v884 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v940[v1221] = v941;
    int * v944 = v860->cache_vals;
    int v1224 = (((((v881 + ((~(((v883 ^ -1) | (-(v883 ^ -1))) >> 31)) & 2)) - (v884 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v944[v1224] = v942;
    int * v946 = v860->cache_tags;
    int v1227 = (((v881 + ((~(((v883 ^ -1) | (-(v883 ^ -1))) >> 31)) & 2)) - (v884 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v946[v1227] = 6;
    int * v948 = v860->cache_dirty;
    v948[v1227] = 0;
    int * v950 = v860->cache_age;
    v950[v1227] = 1;
    int * v952 = v860->cache_age;
    int v953 = v952[v1227];
    int v954 = v952[0];
    int v1232 = v954 + ((int)((unsigned int)(v954 - v953) >> 31));
    v952[0] = v1232;
    int * v956 = v860->cache_age;
    int v957 = v956[1];
    int v1234 = v957 + ((int)((unsigned int)(v957 - v953) >> 31));
    v956[1] = v1234;
    int * v959 = v860->cache_age;
    v959[v1227] = 0;
    v962 = v1227;
  }
  int * v963 = v860->cache_vals;
  int v1237 = (v962 * 2) + 1;
  v963[v1237] = v862;
  int * v965 = v860->cache_tags;
  int v966 = v965[8];
  int v967 = v965[9];
  bool v1240 = !(((~(((v966 ^ 6) | (-(v966 ^ 6))) >> 31)) | (~(((v967 ^ 6) | (-(v967 ^ 6))) >> 31))) == 0);
  int v1021;
  if (v1240) {
    int * v968 = v860->cache_age;
    int v1242 = 8 + ((~(((v967 ^ 6) | (-(v967 ^ 6))) >> 31)) & 1);
    int v969 = v968[v1242];
    int v970 = v968[8];
    int v1243 = v970 + ((int)((unsigned int)(v970 - v969) >> 31));
    v968[8] = v1243;
    int * v972 = v860->cache_age;
    int v973 = v972[9];
    int v1245 = v973 + ((int)((unsigned int)(v973 - v969) >> 31));
    v972[9] = v1245;
    int * v975 = v860->cache_age;
    v975[v1242] = 0;
    v1021 = v1242;
  } else {
    int * v978 = v860->cache_age;
    int v979 = v978[8];
    int * v980 = v860->cache_tags;
    int v981 = v980[8];
    int v982 = v978[9];
    int v983 = v980[9];
    int * v984 = v860->cache_dirty;
    int v1250 = 8 + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v985 = v984[v1250];
    bool v1251 = !(v985 == 0);
    if (v1251) {
      int * v986 = v860->cache_tags;
      int v987 = v986[v1250];
      int * v988 = v860->cache_vals;
      int v1254 = (8 + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v989 = v988[v1254];
      int v1255 = ((8 + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v990 = v988[v1255];
      int * v991 = v860->mem;
      int v1257 = v987 * 2;
      v991[v1257] = v989;
      int * v993 = v860->mem;
      int v1260 = (v987 * 2) + 1;
      v993[v1260] = v990;
      ;
    } else {
      ;
    }
    int * v998 = v860->mem;
    int v999 = v998[12];
    int v1000 = v998[13];
    int * v1001 = v860->cache_vals;
    int v1268 = (8 + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1001[v1268] = v999;
    int * v1003 = v860->cache_vals;
    int v1271 = ((8 + ((((v979 + ((~(((v981 ^ -1) | (-(v981 ^ -1))) >> 31)) & 2)) - (v982 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1003[v1271] = v1000;
    int * v1005 = v860->cache_tags;
    v1005[v1250] = 6;
    int * v1007 = v860->cache_dirty;
    v1007[v1250] = 0;
    int * v1009 = v860->cache_age;
    v1009[v1250] = 1;
    int * v1011 = v860->cache_age;
    int v1012 = v1011[v1250];
    int v1013 = v1011[8];
    int v1278 = v1013 + ((int)((unsigned int)(v1013 - v1012) >> 31));
    v1011[8] = v1278;
    int * v1015 = v860->cache_age;
    int v1016 = v1015[9];
    int v1280 = v1016 + ((int)((unsigned int)(v1016 - v1012) >> 31));
    v1015[9] = v1280;
    int * v1018 = v860->cache_age;
    v1018[v1250] = 0;
    v1021 = v1250;
  }
  int * v1022 = v860->cache_vals;
  int v1283 = (v1021 * 2) + 1;
  v1022[v1283] = v862;
  int * v1024 = v860->cache_dirty;
  v1024[v1021] = 1;
  struct StateT2 * v1026 = slot_4(v681);
  return v1026;
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
  v16[5] = -1;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[5] = -1;
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
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}