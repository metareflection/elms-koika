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
struct StateT2 * slot_6(struct StateT2 * v588);
struct StateT2 * slot_5(struct StateT2 * v549);
struct StateT2 * slot_4(struct StateT2 * v510);
struct StateT2 * slot_2(struct StateT2 * v428);
struct StateT2 * slot_7(struct StateT2 * v1006);
struct StateT2 * slot_3(struct StateT2 * v470);
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
  bool v265 = v40 == v42;
  squared_assert(v265);
  squared_assume(v265);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v267 = v46 + 1;
  v45->timer = v267;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v269 = v49 + 1;
  v48->timer = v269;
  struct StateT * v51 = v38->a;
  int * v52 = v51->cache_tags;
  int v53 = v52[0];
  int v54 = v52[1];
  int v55 = v52[8];
  int v56 = v52[9];
  int v57 = v51->timer;
  int v276 = v57 + ((100 ^ (((~(((v55 ^ 10) | (-(v55 ^ 10))) >> 31)) | (~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31))) & 104)) ^ (((~(((v53 ^ 10) | (-(v53 ^ 10))) >> 31)) | (~(((v54 ^ 10) | (-(v54 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v55 ^ 10) | (-(v55 ^ 10))) >> 31)) | (~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31))) & 104)))));
  v51->timer = v276;
  int * v59 = v51->cache_vals;
  bool v277 = !(((~(((v53 ^ 10) | (-(v53 ^ 10))) >> 31)) | (~(((v54 ^ 10) | (-(v54 ^ 10))) >> 31))) == 0);
  int v152;
  if (v277) {
    int * v60 = v51->cache_age;
    int v279 = (~(((v54 ^ 10) | (-(v54 ^ 10))) >> 31)) & 1;
    int v61 = v60[v279];
    int v62 = v60[0];
    int v280 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
    v60[0] = v280;
    int * v64 = v51->cache_age;
    int v65 = v64[1];
    int v282 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
    v64[1] = v282;
    int * v67 = v51->cache_age;
    v67[v279] = 0;
    v152 = v279;
  } else {
    int * v70 = v51->cache_age;
    int v71 = v70[0];
    int * v72 = v51->cache_tags;
    int v73 = v72[0];
    int v74 = v70[1];
    int v75 = v72[1];
    bool v286 = !(((~(((v55 ^ 10) | (-(v55 ^ 10))) >> 31)) | (~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31))) == 0);
    int v129;
    if (v286) {
      int * v76 = v51->cache_age;
      int v288 = 8 + ((~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31)) & 1);
      int v77 = v76[v288];
      int v78 = v76[8];
      int v289 = v78 + ((int)((unsigned int)(v78 - v77) >> 31));
      v76[8] = v289;
      int * v80 = v51->cache_age;
      int v81 = v80[9];
      int v291 = v81 + ((int)((unsigned int)(v81 - v77) >> 31));
      v80[9] = v291;
      int * v83 = v51->cache_age;
      v83[v288] = 0;
      v129 = v288;
    } else {
      int * v86 = v51->cache_age;
      int v87 = v86[8];
      int * v88 = v51->cache_tags;
      int v89 = v88[8];
      int v90 = v86[9];
      int v91 = v88[9];
      int * v92 = v51->cache_dirty;
      int v296 = 8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v93 = v92[v296];
      bool v297 = !(v93 == 0);
      if (v297) {
        int * v94 = v51->cache_tags;
        int v95 = v94[v296];
        int * v96 = v51->cache_vals;
        int v300 = (8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v97 = v96[v300];
        int v301 = ((8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v98 = v96[v301];
        int * v99 = v51->mem;
        int v303 = v95 * 2;
        v99[v303] = v97;
        int * v101 = v51->mem;
        int v306 = (v95 * 2) + 1;
        v101[v306] = v98;
        ;
      } else {
        ;
      }
      int * v106 = v51->mem;
      int v107 = v106[20];
      int v108 = v106[21];
      int * v109 = v51->cache_vals;
      int v314 = (8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v109[v314] = v107;
      int * v111 = v51->cache_vals;
      int v317 = ((8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v111[v317] = v108;
      int * v113 = v51->cache_tags;
      v113[v296] = 10;
      int * v115 = v51->cache_dirty;
      v115[v296] = 0;
      int * v117 = v51->cache_age;
      v117[v296] = 1;
      int * v119 = v51->cache_age;
      int v120 = v119[v296];
      int v121 = v119[8];
      int v324 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[8] = v324;
      int * v123 = v51->cache_age;
      int v124 = v123[9];
      int v326 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[9] = v326;
      int * v126 = v51->cache_age;
      v126[v296] = 0;
      v129 = v296;
    }
    int * v130 = v51->cache_vals;
    int v329 = v129 * 2;
    int v131 = v130[v329];
    int v330 = (v129 * 2) + 1;
    int v132 = v130[v330];
    int v331 = ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v130[v331] = v131;
    int * v134 = v51->cache_vals;
    int v334 = (((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v134[v334] = v132;
    int * v136 = v51->cache_tags;
    int v337 = (((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v136[v337] = 10;
    int * v138 = v51->cache_dirty;
    v138[v337] = 0;
    int * v140 = v51->cache_age;
    v140[v337] = 1;
    int * v142 = v51->cache_age;
    int v143 = v142[v337];
    int v144 = v142[0];
    int v342 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[0] = v342;
    int * v146 = v51->cache_age;
    int v147 = v146[1];
    int v344 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[1] = v344;
    int * v149 = v51->cache_age;
    v149[v337] = 0;
    v152 = v337;
  }
  int v347 = v152 * 2;
  int v153 = v59[v347];
  int * v154 = v51->regs;
  v154[9] = v153;
  struct StateT * v156 = v38->b;
  int * v157 = v156->cache_tags;
  int v158 = v157[0];
  int v159 = v157[1];
  int v160 = v157[8];
  int v161 = v157[9];
  int v162 = v156->timer;
  int v352 = v162 + ((100 ^ (((~(((v160 ^ 10) | (-(v160 ^ 10))) >> 31)) | (~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31))) & 104)) ^ (((~(((v158 ^ 10) | (-(v158 ^ 10))) >> 31)) | (~(((v159 ^ 10) | (-(v159 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v160 ^ 10) | (-(v160 ^ 10))) >> 31)) | (~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31))) & 104)))));
  v156->timer = v352;
  int * v164 = v156->cache_vals;
  bool v353 = !(((~(((v158 ^ 10) | (-(v158 ^ 10))) >> 31)) | (~(((v159 ^ 10) | (-(v159 ^ 10))) >> 31))) == 0);
  int v257;
  if (v353) {
    int * v165 = v156->cache_age;
    int v355 = (~(((v159 ^ 10) | (-(v159 ^ 10))) >> 31)) & 1;
    int v166 = v165[v355];
    int v167 = v165[0];
    int v356 = v167 + ((int)((unsigned int)(v167 - v166) >> 31));
    v165[0] = v356;
    int * v169 = v156->cache_age;
    int v170 = v169[1];
    int v358 = v170 + ((int)((unsigned int)(v170 - v166) >> 31));
    v169[1] = v358;
    int * v172 = v156->cache_age;
    v172[v355] = 0;
    v257 = v355;
  } else {
    int * v175 = v156->cache_age;
    int v176 = v175[0];
    int * v177 = v156->cache_tags;
    int v178 = v177[0];
    int v179 = v175[1];
    int v180 = v177[1];
    bool v362 = !(((~(((v160 ^ 10) | (-(v160 ^ 10))) >> 31)) | (~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31))) == 0);
    int v234;
    if (v362) {
      int * v181 = v156->cache_age;
      int v364 = 8 + ((~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31)) & 1);
      int v182 = v181[v364];
      int v183 = v181[8];
      int v365 = v183 + ((int)((unsigned int)(v183 - v182) >> 31));
      v181[8] = v365;
      int * v185 = v156->cache_age;
      int v186 = v185[9];
      int v367 = v186 + ((int)((unsigned int)(v186 - v182) >> 31));
      v185[9] = v367;
      int * v188 = v156->cache_age;
      v188[v364] = 0;
      v234 = v364;
    } else {
      int * v191 = v156->cache_age;
      int v192 = v191[8];
      int * v193 = v156->cache_tags;
      int v194 = v193[8];
      int v195 = v191[9];
      int v196 = v193[9];
      int * v197 = v156->cache_dirty;
      int v372 = 8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v198 = v197[v372];
      bool v373 = !(v198 == 0);
      if (v373) {
        int * v199 = v156->cache_tags;
        int v200 = v199[v372];
        int * v201 = v156->cache_vals;
        int v376 = (8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v202 = v201[v376];
        int v377 = ((8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v203 = v201[v377];
        int * v204 = v156->mem;
        int v379 = v200 * 2;
        v204[v379] = v202;
        int * v206 = v156->mem;
        int v382 = (v200 * 2) + 1;
        v206[v382] = v203;
        ;
      } else {
        ;
      }
      int * v211 = v156->mem;
      int v212 = v211[20];
      int v213 = v211[21];
      int * v214 = v156->cache_vals;
      int v390 = (8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v214[v390] = v212;
      int * v216 = v156->cache_vals;
      int v393 = ((8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v216[v393] = v213;
      int * v218 = v156->cache_tags;
      v218[v372] = 10;
      int * v220 = v156->cache_dirty;
      v220[v372] = 0;
      int * v222 = v156->cache_age;
      v222[v372] = 1;
      int * v224 = v156->cache_age;
      int v225 = v224[v372];
      int v226 = v224[8];
      int v400 = v226 + ((int)((unsigned int)(v226 - v225) >> 31));
      v224[8] = v400;
      int * v228 = v156->cache_age;
      int v229 = v228[9];
      int v402 = v229 + ((int)((unsigned int)(v229 - v225) >> 31));
      v228[9] = v402;
      int * v231 = v156->cache_age;
      v231[v372] = 0;
      v234 = v372;
    }
    int * v235 = v156->cache_vals;
    int v405 = v234 * 2;
    int v236 = v235[v405];
    int v406 = (v234 * 2) + 1;
    int v237 = v235[v406];
    int v407 = ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v235[v407] = v236;
    int * v239 = v156->cache_vals;
    int v410 = (((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v239[v410] = v237;
    int * v241 = v156->cache_tags;
    int v413 = (((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v241[v413] = 10;
    int * v243 = v156->cache_dirty;
    v243[v413] = 0;
    int * v245 = v156->cache_age;
    v245[v413] = 1;
    int * v247 = v156->cache_age;
    int v248 = v247[v413];
    int v249 = v247[0];
    int v418 = v249 + ((int)((unsigned int)(v249 - v248) >> 31));
    v247[0] = v418;
    int * v251 = v156->cache_age;
    int v252 = v251[1];
    int v420 = v252 + ((int)((unsigned int)(v252 - v248) >> 31));
    v251[1] = v420;
    int * v254 = v156->cache_age;
    v254[v413] = 0;
    v257 = v413;
  }
  int v423 = v257 * 2;
  int v258 = v164[v423];
  int * v259 = v156->regs;
  v259[9] = v258;
  struct StateT2 * v261 = slot_2(v38);
  return v261;
}

struct StateT2 * slot_6(struct StateT2 * v588) {
  struct StateT * v589 = v588->a;
  int v590 = v589->timer;
  struct StateT * v591 = v588->b;
  int v592 = v591->timer;
  bool v819 = v590 == v592;
  squared_assert(v819);
  squared_assume(v819);
  struct StateT * v595 = v588->a;
  int v596 = v595->timer;
  int v821 = v596 + 1;
  v595->timer = v821;
  struct StateT * v598 = v588->b;
  int v599 = v598->timer;
  int v823 = v599 + 1;
  v598->timer = v823;
  struct StateT * v601 = v588->a;
  int * v602 = v601->regs;
  int v603 = v602[6];
  int * v604 = v601->cache_tags;
  int v828 = (((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2;
  int v605 = v604[v828];
  int v829 = ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + 1;
  int v606 = v604[v829];
  int v830 = 4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2);
  int v607 = v604[v830];
  int v831 = (4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v608 = v604[v831];
  int v609 = v601->timer;
  int v832 = v609 + ((100 ^ (((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) & 104)))));
  v601->timer = v832;
  int * v611 = v601->cache_vals;
  bool v833 = !(((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) == 0);
  int v704;
  if (v833) {
    int * v612 = v601->cache_age;
    int v835 = ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) & 1);
    int v613 = v612[v835];
    int v614 = v612[v828];
    int v836 = v614 + ((int)((unsigned int)(v614 - v613) >> 31));
    v612[v828] = v836;
    int * v616 = v601->cache_age;
    int v617 = v616[v829];
    int v838 = v617 + ((int)((unsigned int)(v617 - v613) >> 31));
    v616[v829] = v838;
    int * v619 = v601->cache_age;
    v619[v835] = 0;
    v704 = v835;
  } else {
    int * v622 = v601->cache_age;
    int v842 = (((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2;
    int v623 = v622[v842];
    int * v624 = v601->cache_tags;
    int v625 = v624[v842];
    int v626 = v622[v829];
    int v627 = v624[v829];
    bool v844 = !(((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) == 0);
    int v681;
    if (v844) {
      int * v628 = v601->cache_age;
      int v846 = (4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) & 1);
      int v629 = v628[v846];
      int v630 = v628[v830];
      int v847 = v630 + ((int)((unsigned int)(v630 - v629) >> 31));
      v628[v830] = v847;
      int * v632 = v601->cache_age;
      int v633 = v632[v831];
      int v849 = v633 + ((int)((unsigned int)(v633 - v629) >> 31));
      v632[v831] = v849;
      int * v635 = v601->cache_age;
      v635[v846] = 0;
      v681 = v846;
    } else {
      int * v638 = v601->cache_age;
      int v853 = 4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2);
      int v639 = v638[v853];
      int * v640 = v601->cache_tags;
      int v641 = v640[v853];
      int v642 = v638[v831];
      int v643 = v640[v831];
      int * v644 = v601->cache_dirty;
      int v856 = (4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v645 = v644[v856];
      bool v857 = !(v645 == 0);
      if (v857) {
        int * v646 = v601->cache_tags;
        int v647 = v646[v856];
        int * v648 = v601->cache_vals;
        int v860 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v649 = v648[v860];
        int v861 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v650 = v648[v861];
        int * v651 = v601->mem;
        int v863 = v647 * 2;
        v651[v863] = v649;
        int * v653 = v601->mem;
        int v866 = (v647 * 2) + 1;
        v653[v866] = v650;
        ;
      } else {
        ;
      }
      int * v658 = v601->mem;
      int v871 = ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) * 2;
      int v659 = v658[v871];
      int v872 = (((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) * 2) + 1;
      int v660 = v658[v872];
      int * v661 = v601->cache_vals;
      int v874 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v661[v874] = v659;
      int * v663 = v601->cache_vals;
      int v877 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v663[v877] = v660;
      int * v665 = v601->cache_tags;
      int v880 = (int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1);
      v665[v856] = v880;
      int * v667 = v601->cache_dirty;
      v667[v856] = 0;
      int * v669 = v601->cache_age;
      v669[v856] = 1;
      int * v671 = v601->cache_age;
      int v672 = v671[v856];
      int v673 = v671[v830];
      int v886 = v673 + ((int)((unsigned int)(v673 - v672) >> 31));
      v671[v830] = v886;
      int * v675 = v601->cache_age;
      int v676 = v675[v831];
      int v888 = v676 + ((int)((unsigned int)(v676 - v672) >> 31));
      v675[v831] = v888;
      int * v678 = v601->cache_age;
      v678[v856] = 0;
      v681 = v856;
    }
    int * v682 = v601->cache_vals;
    int v891 = v681 * 2;
    int v683 = v682[v891];
    int v892 = (v681 * 2) + 1;
    int v684 = v682[v892];
    int v893 = (((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v682[v893] = v683;
    int * v686 = v601->cache_vals;
    int v896 = ((((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v686[v896] = v684;
    int * v688 = v601->cache_tags;
    int v899 = ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v900 = (int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1);
    v688[v899] = v900;
    int * v690 = v601->cache_dirty;
    v690[v899] = 0;
    int * v692 = v601->cache_age;
    v692[v899] = 1;
    int * v694 = v601->cache_age;
    int v695 = v694[v899];
    int v696 = v694[v828];
    int v906 = v696 + ((int)((unsigned int)(v696 - v695) >> 31));
    v694[v828] = v906;
    int * v698 = v601->cache_age;
    int v699 = v698[v829];
    int v908 = v699 + ((int)((unsigned int)(v699 - v695) >> 31));
    v698[v829] = v908;
    int * v701 = v601->cache_age;
    v701[v899] = 0;
    v704 = v899;
  }
  int v911 = (v704 * 2) + (((int)((unsigned int)v603 >> 2)) & 1);
  int v705 = v611[v911];
  int * v706 = v601->regs;
  v706[7] = v705;
  struct StateT * v708 = v588->b;
  int * v709 = v708->regs;
  int v710 = v709[6];
  int * v711 = v708->cache_tags;
  int v918 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
  int v712 = v711[v918];
  int v919 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + 1;
  int v713 = v711[v919];
  int v920 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
  int v714 = v711[v920];
  int v921 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v715 = v711[v921];
  int v716 = v708->timer;
  int v922 = v716 + ((100 ^ (((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)))));
  v708->timer = v922;
  int * v718 = v708->cache_vals;
  bool v923 = !(((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
  int v811;
  if (v923) {
    int * v719 = v708->cache_age;
    int v925 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
    int v720 = v719[v925];
    int v721 = v719[v918];
    int v926 = v721 + ((int)((unsigned int)(v721 - v720) >> 31));
    v719[v918] = v926;
    int * v723 = v708->cache_age;
    int v724 = v723[v919];
    int v928 = v724 + ((int)((unsigned int)(v724 - v720) >> 31));
    v723[v919] = v928;
    int * v726 = v708->cache_age;
    v726[v925] = 0;
    v811 = v925;
  } else {
    int * v729 = v708->cache_age;
    int v932 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
    int v730 = v729[v932];
    int * v731 = v708->cache_tags;
    int v732 = v731[v932];
    int v733 = v729[v919];
    int v734 = v731[v919];
    bool v934 = !(((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
    int v788;
    if (v934) {
      int * v735 = v708->cache_age;
      int v936 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
      int v736 = v735[v936];
      int v737 = v735[v920];
      int v937 = v737 + ((int)((unsigned int)(v737 - v736) >> 31));
      v735[v920] = v937;
      int * v739 = v708->cache_age;
      int v740 = v739[v921];
      int v939 = v740 + ((int)((unsigned int)(v740 - v736) >> 31));
      v739[v921] = v939;
      int * v742 = v708->cache_age;
      v742[v936] = 0;
      v788 = v936;
    } else {
      int * v745 = v708->cache_age;
      int v943 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
      int v746 = v745[v943];
      int * v747 = v708->cache_tags;
      int v748 = v747[v943];
      int v749 = v745[v921];
      int v750 = v747[v921];
      int * v751 = v708->cache_dirty;
      int v946 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v752 = v751[v946];
      bool v947 = !(v752 == 0);
      if (v947) {
        int * v753 = v708->cache_tags;
        int v754 = v753[v946];
        int * v755 = v708->cache_vals;
        int v950 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v756 = v755[v950];
        int v951 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v757 = v755[v951];
        int * v758 = v708->mem;
        int v953 = v754 * 2;
        v758[v953] = v756;
        int * v760 = v708->mem;
        int v956 = (v754 * 2) + 1;
        v760[v956] = v757;
        ;
      } else {
        ;
      }
      int * v765 = v708->mem;
      int v961 = ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2;
      int v766 = v765[v961];
      int v962 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2) + 1;
      int v767 = v765[v962];
      int * v768 = v708->cache_vals;
      int v964 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v768[v964] = v766;
      int * v770 = v708->cache_vals;
      int v967 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v770[v967] = v767;
      int * v772 = v708->cache_tags;
      int v970 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
      v772[v946] = v970;
      int * v774 = v708->cache_dirty;
      v774[v946] = 0;
      int * v776 = v708->cache_age;
      v776[v946] = 1;
      int * v778 = v708->cache_age;
      int v779 = v778[v946];
      int v780 = v778[v920];
      int v976 = v780 + ((int)((unsigned int)(v780 - v779) >> 31));
      v778[v920] = v976;
      int * v782 = v708->cache_age;
      int v783 = v782[v921];
      int v978 = v783 + ((int)((unsigned int)(v783 - v779) >> 31));
      v782[v921] = v978;
      int * v785 = v708->cache_age;
      v785[v946] = 0;
      v788 = v946;
    }
    int * v789 = v708->cache_vals;
    int v981 = v788 * 2;
    int v790 = v789[v981];
    int v982 = (v788 * 2) + 1;
    int v791 = v789[v982];
    int v983 = (((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v789[v983] = v790;
    int * v793 = v708->cache_vals;
    int v986 = ((((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v793[v986] = v791;
    int * v795 = v708->cache_tags;
    int v989 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v990 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
    v795[v989] = v990;
    int * v797 = v708->cache_dirty;
    v797[v989] = 0;
    int * v799 = v708->cache_age;
    v799[v989] = 1;
    int * v801 = v708->cache_age;
    int v802 = v801[v989];
    int v803 = v801[v918];
    int v996 = v803 + ((int)((unsigned int)(v803 - v802) >> 31));
    v801[v918] = v996;
    int * v805 = v708->cache_age;
    int v806 = v805[v919];
    int v998 = v806 + ((int)((unsigned int)(v806 - v802) >> 31));
    v805[v919] = v998;
    int * v808 = v708->cache_age;
    v808[v989] = 0;
    v811 = v989;
  }
  int v1001 = (v811 * 2) + (((int)((unsigned int)v710 >> 2)) & 1);
  int v812 = v718[v1001];
  int * v813 = v708->regs;
  v813[7] = v812;
  struct StateT2 * v815 = slot_7(v588);
  return v815;
}

struct StateT2 * slot_5(struct StateT2 * v549) {
  struct StateT * v550 = v549->a;
  int v551 = v550->timer;
  struct StateT * v552 = v549->b;
  int v553 = v552->timer;
  bool v574 = v551 == v553;
  squared_assert(v574);
  squared_assume(v574);
  struct StateT * v556 = v549->a;
  int v557 = v556->timer;
  int v576 = v557 + 1;
  v556->timer = v576;
  struct StateT * v559 = v549->b;
  int v560 = v559->timer;
  int v578 = v560 + 1;
  v559->timer = v578;
  struct StateT * v562 = v549->a;
  int * v563 = v562->regs;
  int v564 = v563[6];
  int v582 = v564 << 2;
  v563[6] = v582;
  struct StateT * v566 = v549->b;
  int * v567 = v566->regs;
  int v568 = v567[6];
  int v585 = v568 << 2;
  v567[6] = v585;
  struct StateT2 * v570 = slot_6(v549);
  return v570;
}

struct StateT2 * slot_4(struct StateT2 * v510) {
  struct StateT * v511 = v510->a;
  int v512 = v511->timer;
  struct StateT * v513 = v510->b;
  int v514 = v513->timer;
  bool v535 = v512 == v514;
  squared_assert(v535);
  squared_assume(v535);
  struct StateT * v517 = v510->a;
  int v518 = v517->timer;
  int v537 = v518 + 1;
  v517->timer = v537;
  struct StateT * v520 = v510->b;
  int v521 = v520->timer;
  int v539 = v521 + 1;
  v520->timer = v539;
  struct StateT * v523 = v510->a;
  int * v524 = v523->regs;
  int v525 = v524[6];
  int v543 = v525 & 63;
  v524[6] = v543;
  struct StateT * v527 = v510->b;
  int * v528 = v527->regs;
  int v529 = v528[6];
  int v546 = v529 & 63;
  v528[6] = v546;
  struct StateT2 * v531 = slot_5(v510);
  return v531;
}

struct StateT2 * slot_2(struct StateT2 * v428) {
  struct StateT * v429 = v428->a;
  int v430 = v429->timer;
  struct StateT * v431 = v428->b;
  int v432 = v431->timer;
  bool v455 = v430 == v432;
  squared_assert(v455);
  squared_assume(v455);
  struct StateT * v435 = v428->a;
  int v436 = v435->timer;
  int v457 = v436 + 1;
  v435->timer = v457;
  struct StateT * v438 = v428->b;
  int v439 = v438->timer;
  int v459 = v439 + 1;
  v438->timer = v459;
  struct StateT * v441 = v428->a;
  int * v442 = v441->regs;
  int v443 = v442[5];
  int v444 = v442[9];
  int v464 = v443 ^ v444;
  v442[5] = v464;
  struct StateT * v446 = v428->b;
  int * v447 = v446->regs;
  int v448 = v447[5];
  int v449 = v447[9];
  int v467 = v448 ^ v449;
  v447[5] = v467;
  struct StateT2 * v451 = slot_3(v428);
  return v451;
}

struct StateT2 * slot_7(struct StateT2 * v1006) {
  struct StateT * v1007 = v1006->a;
  int v1008 = v1007->timer;
  struct StateT * v1009 = v1006->b;
  int v1010 = v1009->timer;
  bool v1032 = v1008 == v1010;
  squared_assert(v1032);
  squared_assume(v1032);
  struct StateT * v1013 = v1006->a;
  int v1014 = v1013->timer;
  int v1034 = v1014 + 1;
  v1013->timer = v1034;
  struct StateT * v1016 = v1006->b;
  int v1017 = v1016->timer;
  int v1036 = v1017 + 1;
  v1016->timer = v1036;
  struct StateT * v1019 = v1006->a;
  int * v1020 = v1019->regs;
  int v1021 = v1020[5];
  int v1022 = v1020[7];
  int v1041 = v1021 ^ v1022;
  v1020[5] = v1041;
  struct StateT * v1024 = v1006->b;
  int * v1025 = v1024->regs;
  int v1026 = v1025[5];
  int v1027 = v1025[7];
  int v1044 = v1026 ^ v1027;
  v1025[5] = v1044;
  return v1006;
}

struct StateT2 * slot_3(struct StateT2 * v470) {
  struct StateT * v471 = v470->a;
  int v472 = v471->timer;
  struct StateT * v473 = v470->b;
  int v474 = v473->timer;
  bool v495 = v472 == v474;
  squared_assert(v495);
  squared_assume(v495);
  struct StateT * v477 = v470->a;
  int v478 = v477->timer;
  int v497 = v478 + 1;
  v477->timer = v497;
  struct StateT * v480 = v470->b;
  int v481 = v480->timer;
  int v499 = v481 + 1;
  v480->timer = v499;
  struct StateT * v483 = v470->a;
  int * v484 = v483->regs;
  int v485 = v484[10];
  v484[6] = v485;
  struct StateT * v487 = v470->b;
  int * v488 = v487->regs;
  int v489 = v488[10];
  v488[6] = v489;
  struct StateT2 * v491 = slot_4(v470);
  return v491;
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
  v16[5] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[5] = 0;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  
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