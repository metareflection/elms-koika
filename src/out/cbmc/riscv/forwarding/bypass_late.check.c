// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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
#include <stdio.h>
#include <stdlib.h>

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

struct StateT * slot_5(struct StateT * v84);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v121);
struct StateT * slot_3(struct StateT * v40);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1315);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v1049);
struct StateT * slot_4(struct StateT * v64);
struct StateT * slot_9(struct StateT * v1299);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_5(struct StateT * v84) {
  int * v85 = v84->regs;
  int v86 = v85[5];
  int * v87 = v84->regs;
  int v88 = v87[9];
  bool v108 = v86 >= v88;
  struct StateT * v102;
  if (v108) {
    int v89 = v84->timer;
    int v109 = v89 + 15;
    v84->timer = v109;
    int * v91 = v84->saved_regs;
    int v92 = v91[6];
    int * v93 = v84->regs;
    v93[6] = v92;
    int * v95 = v84->saved_regs;
    int v96 = v95[7];
    int * v97 = v84->regs;
    v97[7] = v96;
    v102 = v84;
  } else {
    struct StateT * v100 = slot_7(v84);
    v102 = v100;
  }
  return v102;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v37 = v33 + 1;
  v32->timer = v37;
  struct StateT * v35 = slot_3(v32);
  return v35;
}

struct StateT * slot_7(struct StateT * v121) {
  int v122 = v121->timer;
  int v621 = v122 + 1;
  v121->timer = v621;
  int * v124 = v121->regs;
  int v125 = v124[6];
  int * v126 = v121->regs;
  int v127 = v126[7];
  int * v128 = v121->saved_regs;
  int * v129 = v121->regs;
  int v130 = v129[11];
  v128[11] = v130;
  int v132 = v121->timer;
  int v630 = v132 + 1;
  v121->timer = v630;
  int * v134 = v121->regs;
  int v135 = v134[6];
  int * v136 = v121->cache_tags;
  int v633 = (((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2;
  int v137 = v136[v633];
  int * v138 = v121->cache_tags;
  int v635 = ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2) + 1;
  int v139 = v138[v635];
  int * v140 = v121->cache_tags;
  int v637 = 4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2);
  int v141 = v140[v637];
  int * v142 = v121->cache_tags;
  int v639 = (4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v143 = v142[v639];
  int v144 = v121->timer;
  int v640 = v144 + ((100 ^ (((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) | (~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31))) & 104)))));
  v121->timer = v640;
  int * v146 = v121->cache_vals;
  bool v641 = !(((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) | (~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31))) == 0);
  int v259;
  if (v641) {
    int * v147 = v121->cache_age;
    int v643 = ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2) + ((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) & 1);
    int v148 = v147[v643];
    int * v149 = v121->cache_age;
    int v150 = v149[v633];
    int * v151 = v121->cache_age;
    int v646 = v150 + ((int)((unsigned int)(v150 - v148) >> 31));
    v151[v633] = v646;
    int * v153 = v121->cache_age;
    int v154 = v153[v635];
    int * v155 = v121->cache_age;
    int v649 = v154 + ((int)((unsigned int)(v154 - v148) >> 31));
    v155[v635] = v649;
    int * v157 = v121->cache_age;
    v157[v643] = 0;
    v259 = v643;
  } else {
    int * v160 = v121->cache_age;
    int v653 = (((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2;
    int v161 = v160[v653];
    int * v162 = v121->cache_tags;
    int v163 = v162[v653];
    int * v164 = v121->cache_age;
    int v165 = v164[v635];
    int * v166 = v121->cache_tags;
    int v167 = v166[v635];
    bool v657 = !(((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31))) == 0);
    int v231;
    if (v657) {
      int * v168 = v121->cache_age;
      int v659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + ((~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1))))) >> 31)) & 1);
      int v169 = v168[v659];
      int * v170 = v121->cache_age;
      int v171 = v170[v637];
      int * v172 = v121->cache_age;
      int v662 = v171 + ((int)((unsigned int)(v171 - v169) >> 31));
      v172[v637] = v662;
      int * v174 = v121->cache_age;
      int v175 = v174[v639];
      int * v176 = v121->cache_age;
      int v665 = v175 + ((int)((unsigned int)(v175 - v169) >> 31));
      v176[v639] = v665;
      int * v178 = v121->cache_age;
      v178[v659] = 0;
      v231 = v659;
    } else {
      int * v181 = v121->cache_age;
      int v669 = 4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2);
      int v182 = v181[v669];
      int * v183 = v121->cache_tags;
      int v184 = v183[v669];
      int * v185 = v121->cache_age;
      int v186 = v185[v639];
      int * v187 = v121->cache_tags;
      int v188 = v187[v639];
      int * v189 = v121->cache_dirty;
      int v674 = (4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v190 = v189[v674];
      bool v675 = !(v190 == 0);
      if (v675) {
        int * v191 = v121->cache_tags;
        int v192 = v191[v674];
        int * v193 = v121->cache_vals;
        int v678 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v194 = v193[v678];
        int * v195 = v121->cache_vals;
        int v680 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v196 = v195[v680];
        int * v197 = v121->mem;
        int v682 = v192 * 2;
        v197[v682] = v194;
        int * v199 = v121->mem;
        int v685 = (v192 * 2) + 1;
        v199[v685] = v196;
        ;
      } else {
        ;
      }
      int * v204 = v121->mem;
      int v690 = ((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) * 2;
      int v205 = v204[v690];
      int * v206 = v121->mem;
      int v692 = (((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) * 2) + 1;
      int v207 = v206[v692];
      int * v208 = v121->cache_vals;
      int v694 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v208[v694] = v205;
      int * v210 = v121->cache_vals;
      int v697 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 3) * 2)) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v210[v697] = v207;
      int * v212 = v121->cache_tags;
      int v700 = (int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1);
      v212[v674] = v700;
      int * v214 = v121->cache_dirty;
      v214[v674] = 0;
      int * v216 = v121->cache_age;
      v216[v674] = 1;
      int * v218 = v121->cache_age;
      int v219 = v218[v674];
      int * v220 = v121->cache_age;
      int v221 = v220[v637];
      int * v222 = v121->cache_age;
      int v708 = v221 + ((int)((unsigned int)(v221 - v219) >> 31));
      v222[v637] = v708;
      int * v224 = v121->cache_age;
      int v225 = v224[v639];
      int * v226 = v121->cache_age;
      int v711 = v225 + ((int)((unsigned int)(v225 - v219) >> 31));
      v226[v639] = v711;
      int * v228 = v121->cache_age;
      v228[v674] = 0;
      v231 = v674;
    }
    int * v232 = v121->cache_vals;
    int v714 = v231 * 2;
    int v233 = v232[v714];
    int * v234 = v121->cache_vals;
    int v716 = (v231 * 2) + 1;
    int v235 = v234[v716];
    int * v236 = v121->cache_vals;
    int v718 = (((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2) + ((((v161 + ((~(((v163 ^ -1) | (-(v163 ^ -1))) >> 31)) & 2)) - (v165 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v236[v718] = v233;
    int * v238 = v121->cache_vals;
    int v721 = ((((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2) + ((((v161 + ((~(((v163 ^ -1) | (-(v163 ^ -1))) >> 31)) & 2)) - (v165 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v238[v721] = v235;
    int * v240 = v121->cache_tags;
    int v724 = ((((int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1)) & 1) * 2) + ((((v161 + ((~(((v163 ^ -1) | (-(v163 ^ -1))) >> 31)) & 2)) - (v165 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v725 = (int)((unsigned int)((int)((unsigned int)v135 >> 2)) >> 1);
    v240[v724] = v725;
    int * v242 = v121->cache_dirty;
    v242[v724] = 0;
    int * v244 = v121->cache_age;
    v244[v724] = 1;
    int * v246 = v121->cache_age;
    int v247 = v246[v724];
    int * v248 = v121->cache_age;
    int v249 = v248[v633];
    int * v250 = v121->cache_age;
    int v733 = v249 + ((int)((unsigned int)(v249 - v247) >> 31));
    v250[v633] = v733;
    int * v252 = v121->cache_age;
    int v253 = v252[v635];
    int * v254 = v121->cache_age;
    int v736 = v253 + ((int)((unsigned int)(v253 - v247) >> 31));
    v254[v635] = v736;
    int * v256 = v121->cache_age;
    v256[v724] = 0;
    v259 = v724;
  }
  int v739 = (v259 * 2) + (((int)((unsigned int)v135 >> 2)) & 1);
  int v260 = v146[v739];
  int * v261 = v121->regs;
  v261[11] = v260;
  int v263 = v121->timer;
  int v742 = v263 + 1;
  v121->timer = v742;
  int * v265 = v121->regs;
  int v266 = v265[11];
  int * v267 = v121->regs;
  int v745 = v266 << 2;
  v267[11] = v745;
  int * v269 = v121->saved_regs;
  int * v270 = v121->regs;
  int v271 = v270[12];
  v269[12] = v271;
  int v273 = v121->timer;
  int v750 = v273 + 1;
  v121->timer = v750;
  int * v275 = v121->regs;
  int v276 = v275[11];
  bool v752 = (((int)((unsigned int)v125 >> 2)) & 3) == (((int)((unsigned int)v276 >> 2)) & 3);
  int v406;
  if (v752) {
    int v277 = v121->timer;
    int v753 = v277 + 1;
    v121->timer = v753;
    v406 = v127;
  } else {
    int * v280 = v121->cache_tags;
    int v756 = (((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2;
    int v281 = v280[v756];
    int * v282 = v121->cache_tags;
    int v758 = ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2) + 1;
    int v283 = v282[v758];
    int * v284 = v121->cache_tags;
    int v760 = 4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2);
    int v285 = v284[v760];
    int * v286 = v121->cache_tags;
    int v762 = (4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v287 = v286[v762];
    int v288 = v121->timer;
    int v763 = v288 + ((100 ^ (((~(((v285 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v285 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) | (~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) | (~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v285 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v285 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) | (~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31))) & 104)))));
    v121->timer = v763;
    int * v290 = v121->cache_vals;
    bool v764 = !(((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) | (~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31))) == 0);
    int v403;
    if (v764) {
      int * v291 = v121->cache_age;
      int v766 = ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2) + ((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) & 1);
      int v292 = v291[v766];
      int * v293 = v121->cache_age;
      int v294 = v293[v756];
      int * v295 = v121->cache_age;
      int v769 = v294 + ((int)((unsigned int)(v294 - v292) >> 31));
      v295[v756] = v769;
      int * v297 = v121->cache_age;
      int v298 = v297[v758];
      int * v299 = v121->cache_age;
      int v772 = v298 + ((int)((unsigned int)(v298 - v292) >> 31));
      v299[v758] = v772;
      int * v301 = v121->cache_age;
      v301[v766] = 0;
      v403 = v766;
    } else {
      int * v304 = v121->cache_age;
      int v776 = (((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2;
      int v305 = v304[v776];
      int * v306 = v121->cache_tags;
      int v307 = v306[v776];
      int * v308 = v121->cache_age;
      int v309 = v308[v758];
      int * v310 = v121->cache_tags;
      int v311 = v310[v758];
      bool v780 = !(((~(((v285 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v285 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) | (~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31))) == 0);
      int v375;
      if (v780) {
        int * v312 = v121->cache_age;
        int v782 = (4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + ((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1))))) >> 31)) & 1);
        int v313 = v312[v782];
        int * v314 = v121->cache_age;
        int v315 = v314[v760];
        int * v316 = v121->cache_age;
        int v785 = v315 + ((int)((unsigned int)(v315 - v313) >> 31));
        v316[v760] = v785;
        int * v318 = v121->cache_age;
        int v319 = v318[v762];
        int * v320 = v121->cache_age;
        int v788 = v319 + ((int)((unsigned int)(v319 - v313) >> 31));
        v320[v762] = v788;
        int * v322 = v121->cache_age;
        v322[v782] = 0;
        v375 = v782;
      } else {
        int * v325 = v121->cache_age;
        int v792 = 4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2);
        int v326 = v325[v792];
        int * v327 = v121->cache_tags;
        int v328 = v327[v792];
        int * v329 = v121->cache_age;
        int v330 = v329[v762];
        int * v331 = v121->cache_tags;
        int v332 = v331[v762];
        int * v333 = v121->cache_dirty;
        int v797 = (4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v334 = v333[v797];
        bool v798 = !(v334 == 0);
        if (v798) {
          int * v335 = v121->cache_tags;
          int v336 = v335[v797];
          int * v337 = v121->cache_vals;
          int v801 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v338 = v337[v801];
          int * v339 = v121->cache_vals;
          int v803 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v340 = v339[v803];
          int * v341 = v121->mem;
          int v805 = v336 * 2;
          v341[v805] = v338;
          int * v343 = v121->mem;
          int v808 = (v336 * 2) + 1;
          v343[v808] = v340;
          ;
        } else {
          ;
        }
        int * v348 = v121->mem;
        int v813 = ((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) * 2;
        int v349 = v348[v813];
        int * v350 = v121->mem;
        int v815 = (((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) * 2) + 1;
        int v351 = v350[v815];
        int * v352 = v121->cache_vals;
        int v817 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v352[v817] = v349;
        int * v354 = v121->cache_vals;
        int v820 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 3) * 2)) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v330 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v354[v820] = v351;
        int * v356 = v121->cache_tags;
        int v823 = (int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1);
        v356[v797] = v823;
        int * v358 = v121->cache_dirty;
        v358[v797] = 0;
        int * v360 = v121->cache_age;
        v360[v797] = 1;
        int * v362 = v121->cache_age;
        int v363 = v362[v797];
        int * v364 = v121->cache_age;
        int v365 = v364[v760];
        int * v366 = v121->cache_age;
        int v831 = v365 + ((int)((unsigned int)(v365 - v363) >> 31));
        v366[v760] = v831;
        int * v368 = v121->cache_age;
        int v369 = v368[v762];
        int * v370 = v121->cache_age;
        int v834 = v369 + ((int)((unsigned int)(v369 - v363) >> 31));
        v370[v762] = v834;
        int * v372 = v121->cache_age;
        v372[v797] = 0;
        v375 = v797;
      }
      int * v376 = v121->cache_vals;
      int v837 = v375 * 2;
      int v377 = v376[v837];
      int * v378 = v121->cache_vals;
      int v839 = (v375 * 2) + 1;
      int v379 = v378[v839];
      int * v380 = v121->cache_vals;
      int v841 = (((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v380[v841] = v377;
      int * v382 = v121->cache_vals;
      int v844 = ((((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v382[v844] = v379;
      int * v384 = v121->cache_tags;
      int v847 = ((((int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1)) & 1) * 2) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v848 = (int)((unsigned int)((int)((unsigned int)v276 >> 2)) >> 1);
      v384[v847] = v848;
      int * v386 = v121->cache_dirty;
      v386[v847] = 0;
      int * v388 = v121->cache_age;
      v388[v847] = 1;
      int * v390 = v121->cache_age;
      int v391 = v390[v847];
      int * v392 = v121->cache_age;
      int v393 = v392[v756];
      int * v394 = v121->cache_age;
      int v856 = v393 + ((int)((unsigned int)(v393 - v391) >> 31));
      v394[v756] = v856;
      int * v396 = v121->cache_age;
      int v397 = v396[v758];
      int * v398 = v121->cache_age;
      int v859 = v397 + ((int)((unsigned int)(v397 - v391) >> 31));
      v398[v758] = v859;
      int * v400 = v121->cache_age;
      v400[v847] = 0;
      v403 = v847;
    }
    int v862 = (v403 * 2) + (((int)((unsigned int)v276 >> 2)) & 1);
    int v404 = v290[v862];
    v406 = v404;
  }
  int * v407 = v121->regs;
  v407[12] = v406;
  int * v409 = v121->cache_tags;
  int v867 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2;
  int v410 = v409[v867];
  int * v411 = v121->cache_tags;
  int v869 = ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + 1;
  int v412 = v411[v869];
  int * v413 = v121->cache_tags;
  int v871 = 4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2);
  int v414 = v413[v871];
  int * v415 = v121->cache_tags;
  int v873 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v416 = v415[v873];
  int v417 = v121->timer;
  int v874 = v417 + ((100 ^ (((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v412 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v412 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) & 104)))));
  v121->timer = v874;
  bool v875 = !(((~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v412 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v412 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) == 0);
  int v531;
  if (v875) {
    int * v419 = v121->cache_age;
    int v877 = ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((~(((v412 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v412 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) & 1);
    int v420 = v419[v877];
    int * v421 = v121->cache_age;
    int v422 = v421[v867];
    int * v423 = v121->cache_age;
    int v880 = v422 + ((int)((unsigned int)(v422 - v420) >> 31));
    v423[v867] = v880;
    int * v425 = v121->cache_age;
    int v426 = v425[v869];
    int * v427 = v121->cache_age;
    int v883 = v426 + ((int)((unsigned int)(v426 - v420) >> 31));
    v427[v869] = v883;
    int * v429 = v121->cache_age;
    v429[v877] = 0;
    v531 = v877;
  } else {
    int * v432 = v121->cache_age;
    int v887 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2;
    int v433 = v432[v887];
    int * v434 = v121->cache_tags;
    int v435 = v434[v887];
    int * v436 = v121->cache_age;
    int v437 = v436[v869];
    int * v438 = v121->cache_tags;
    int v439 = v438[v869];
    bool v891 = !(((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) == 0);
    int v503;
    if (v891) {
      int * v440 = v121->cache_age;
      int v893 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) & 1);
      int v441 = v440[v893];
      int * v442 = v121->cache_age;
      int v443 = v442[v871];
      int * v444 = v121->cache_age;
      int v896 = v443 + ((int)((unsigned int)(v443 - v441) >> 31));
      v444[v871] = v896;
      int * v446 = v121->cache_age;
      int v447 = v446[v873];
      int * v448 = v121->cache_age;
      int v899 = v447 + ((int)((unsigned int)(v447 - v441) >> 31));
      v448[v873] = v899;
      int * v450 = v121->cache_age;
      v450[v893] = 0;
      v503 = v893;
    } else {
      int * v453 = v121->cache_age;
      int v903 = 4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2);
      int v454 = v453[v903];
      int * v455 = v121->cache_tags;
      int v456 = v455[v903];
      int * v457 = v121->cache_age;
      int v458 = v457[v873];
      int * v459 = v121->cache_tags;
      int v460 = v459[v873];
      int * v461 = v121->cache_dirty;
      int v908 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v462 = v461[v908];
      bool v909 = !(v462 == 0);
      if (v909) {
        int * v463 = v121->cache_tags;
        int v464 = v463[v908];
        int * v465 = v121->cache_vals;
        int v912 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v466 = v465[v912];
        int * v467 = v121->cache_vals;
        int v914 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v468 = v467[v914];
        int * v469 = v121->mem;
        int v916 = v464 * 2;
        v469[v916] = v466;
        int * v471 = v121->mem;
        int v919 = (v464 * 2) + 1;
        v471[v919] = v468;
        ;
      } else {
        ;
      }
      int * v476 = v121->mem;
      int v924 = ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2;
      int v477 = v476[v924];
      int * v478 = v121->mem;
      int v926 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2) + 1;
      int v479 = v478[v926];
      int * v480 = v121->cache_vals;
      int v928 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v480[v928] = v477;
      int * v482 = v121->cache_vals;
      int v931 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v454 + ((~(((v456 ^ -1) | (-(v456 ^ -1))) >> 31)) & 2)) - (v458 + ((~(((v460 ^ -1) | (-(v460 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v482[v931] = v479;
      int * v484 = v121->cache_tags;
      int v934 = (int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1);
      v484[v908] = v934;
      int * v486 = v121->cache_dirty;
      v486[v908] = 0;
      int * v488 = v121->cache_age;
      v488[v908] = 1;
      int * v490 = v121->cache_age;
      int v491 = v490[v908];
      int * v492 = v121->cache_age;
      int v493 = v492[v871];
      int * v494 = v121->cache_age;
      int v942 = v493 + ((int)((unsigned int)(v493 - v491) >> 31));
      v494[v871] = v942;
      int * v496 = v121->cache_age;
      int v497 = v496[v873];
      int * v498 = v121->cache_age;
      int v945 = v497 + ((int)((unsigned int)(v497 - v491) >> 31));
      v498[v873] = v945;
      int * v500 = v121->cache_age;
      v500[v908] = 0;
      v503 = v908;
    }
    int * v504 = v121->cache_vals;
    int v948 = v503 * 2;
    int v505 = v504[v948];
    int * v506 = v121->cache_vals;
    int v950 = (v503 * 2) + 1;
    int v507 = v506[v950];
    int * v508 = v121->cache_vals;
    int v952 = (((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v508[v952] = v505;
    int * v510 = v121->cache_vals;
    int v955 = ((((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v510[v955] = v507;
    int * v512 = v121->cache_tags;
    int v958 = ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v959 = (int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1);
    v512[v958] = v959;
    int * v514 = v121->cache_dirty;
    v514[v958] = 0;
    int * v516 = v121->cache_age;
    v516[v958] = 1;
    int * v518 = v121->cache_age;
    int v519 = v518[v958];
    int * v520 = v121->cache_age;
    int v521 = v520[v867];
    int * v522 = v121->cache_age;
    int v967 = v521 + ((int)((unsigned int)(v521 - v519) >> 31));
    v522[v867] = v967;
    int * v524 = v121->cache_age;
    int v525 = v524[v869];
    int * v526 = v121->cache_age;
    int v970 = v525 + ((int)((unsigned int)(v525 - v519) >> 31));
    v526[v869] = v970;
    int * v528 = v121->cache_age;
    v528[v958] = 0;
    v531 = v958;
  }
  int * v532 = v121->cache_vals;
  int v973 = (v531 * 2) + (((int)((unsigned int)v125 >> 2)) & 1);
  v532[v973] = v127;
  int * v534 = v121->cache_tags;
  int v535 = v534[v871];
  int * v536 = v121->cache_tags;
  int v537 = v536[v873];
  bool v977 = !(((~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) | (~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31))) == 0);
  int v601;
  if (v977) {
    int * v538 = v121->cache_age;
    int v979 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1))))) >> 31)) & 1);
    int v539 = v538[v979];
    int * v540 = v121->cache_age;
    int v541 = v540[v871];
    int * v542 = v121->cache_age;
    int v982 = v541 + ((int)((unsigned int)(v541 - v539) >> 31));
    v542[v871] = v982;
    int * v544 = v121->cache_age;
    int v545 = v544[v873];
    int * v546 = v121->cache_age;
    int v985 = v545 + ((int)((unsigned int)(v545 - v539) >> 31));
    v546[v873] = v985;
    int * v548 = v121->cache_age;
    v548[v979] = 0;
    v601 = v979;
  } else {
    int * v551 = v121->cache_age;
    int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2);
    int v552 = v551[v989];
    int * v553 = v121->cache_tags;
    int v554 = v553[v989];
    int * v555 = v121->cache_age;
    int v556 = v555[v873];
    int * v557 = v121->cache_tags;
    int v558 = v557[v873];
    int * v559 = v121->cache_dirty;
    int v994 = (4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v560 = v559[v994];
    bool v995 = !(v560 == 0);
    if (v995) {
      int * v561 = v121->cache_tags;
      int v562 = v561[v994];
      int * v563 = v121->cache_vals;
      int v998 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v564 = v563[v998];
      int * v565 = v121->cache_vals;
      int v1000 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v566 = v565[v1000];
      int * v567 = v121->mem;
      int v1002 = v562 * 2;
      v567[v1002] = v564;
      int * v569 = v121->mem;
      int v1005 = (v562 * 2) + 1;
      v569[v1005] = v566;
      ;
    } else {
      ;
    }
    int * v574 = v121->mem;
    int v1010 = ((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2;
    int v575 = v574[v1010];
    int * v576 = v121->mem;
    int v1012 = (((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) * 2) + 1;
    int v577 = v576[v1012];
    int * v578 = v121->cache_vals;
    int v1014 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v578[v1014] = v575;
    int * v580 = v121->cache_vals;
    int v1017 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1)) & 3) * 2)) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v580[v1017] = v577;
    int * v582 = v121->cache_tags;
    int v1020 = (int)((unsigned int)((int)((unsigned int)v125 >> 2)) >> 1);
    v582[v994] = v1020;
    int * v584 = v121->cache_dirty;
    v584[v994] = 0;
    int * v586 = v121->cache_age;
    v586[v994] = 1;
    int * v588 = v121->cache_age;
    int v589 = v588[v994];
    int * v590 = v121->cache_age;
    int v591 = v590[v871];
    int * v592 = v121->cache_age;
    int v1028 = v591 + ((int)((unsigned int)(v591 - v589) >> 31));
    v592[v871] = v1028;
    int * v594 = v121->cache_age;
    int v595 = v594[v873];
    int * v596 = v121->cache_age;
    int v1031 = v595 + ((int)((unsigned int)(v595 - v589) >> 31));
    v596[v873] = v1031;
    int * v598 = v121->cache_age;
    v598[v994] = 0;
    v601 = v994;
  }
  int * v602 = v121->cache_vals;
  int v1034 = (v601 * 2) + (((int)((unsigned int)v125 >> 2)) & 1);
  v602[v1034] = v127;
  int * v604 = v121->cache_dirty;
  v604[v601] = 1;
  bool v1038 = (((int)((unsigned int)v135 >> 2)) == ((int)((unsigned int)v125 >> 2))) | (((((int)((unsigned int)v276 >> 2)) & 3) == (((int)((unsigned int)v125 >> 2)) & 3)) & (!(((int)((unsigned int)v276 >> 2)) == ((int)((unsigned int)v125 >> 2)))));
  struct StateT * v619;
  if (v1038) {
    int v606 = v121->timer;
    int v1039 = v606 + 15;
    v121->timer = v1039;
    int * v608 = v121->saved_regs;
    int v609 = v608[11];
    int * v610 = v121->regs;
    v610[11] = v609;
    int * v612 = v121->saved_regs;
    int v613 = v612[12];
    int * v614 = v121->regs;
    v614[12] = v613;
    struct StateT * v616 = slot_8(v121);
    v619 = v616;
  } else {
    v619 = v121;
  }
  return v619;
}

struct StateT * slot_3(struct StateT * v40) {
  int * v41 = v40->saved_regs;
  int * v42 = v40->regs;
  int v43 = v42[6];
  v41[6] = v43;
  int v45 = v40->timer;
  int v57 = v45 + 1;
  v40->timer = v57;
  int * v47 = v40->regs;
  int v48 = v47[5];
  int * v49 = v40->regs;
  int v61 = v48 + 80;
  v49[6] = v61;
  struct StateT * v51 = slot_4(v40);
  return v51;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v1315) {
  int v1316 = v1315->timer;
  int v1448 = v1316 + 1;
  v1315->timer = v1448;
  int * v1318 = v1315->regs;
  int v1319 = v1318[11];
  int * v1320 = v1315->cache_tags;
  int v1452 = (((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2;
  int v1321 = v1320[v1452];
  int * v1322 = v1315->cache_tags;
  int v1454 = ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1323 = v1322[v1454];
  int * v1324 = v1315->cache_tags;
  int v1456 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2);
  int v1325 = v1324[v1456];
  int * v1326 = v1315->cache_tags;
  int v1458 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1327 = v1326[v1458];
  int v1328 = v1315->timer;
  int v1459 = v1328 + ((100 ^ (((~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) | (~(((v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1321 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1321 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) | (~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) | (~(((v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1315->timer = v1459;
  int * v1330 = v1315->cache_vals;
  bool v1460 = !(((~(((v1321 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1321 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) | (~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31))) == 0);
  int v1443;
  if (v1460) {
    int * v1331 = v1315->cache_age;
    int v1462 = ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2) + ((~(((v1323 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1323 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) & 1);
    int v1332 = v1331[v1462];
    int * v1333 = v1315->cache_age;
    int v1334 = v1333[v1452];
    int * v1335 = v1315->cache_age;
    int v1465 = v1334 + ((int)((unsigned int)(v1334 - v1332) >> 31));
    v1335[v1452] = v1465;
    int * v1337 = v1315->cache_age;
    int v1338 = v1337[v1454];
    int * v1339 = v1315->cache_age;
    int v1468 = v1338 + ((int)((unsigned int)(v1338 - v1332) >> 31));
    v1339[v1454] = v1468;
    int * v1341 = v1315->cache_age;
    v1341[v1462] = 0;
    v1443 = v1462;
  } else {
    int * v1344 = v1315->cache_age;
    int v1472 = (((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2;
    int v1345 = v1344[v1472];
    int * v1346 = v1315->cache_tags;
    int v1347 = v1346[v1472];
    int * v1348 = v1315->cache_age;
    int v1349 = v1348[v1454];
    int * v1350 = v1315->cache_tags;
    int v1351 = v1350[v1454];
    bool v1476 = !(((~(((v1325 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1325 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) | (~(((v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31))) == 0);
    int v1415;
    if (v1476) {
      int * v1352 = v1315->cache_age;
      int v1478 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))) | (-(v1327 ^ ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1))))) >> 31)) & 1);
      int v1353 = v1352[v1478];
      int * v1354 = v1315->cache_age;
      int v1355 = v1354[v1456];
      int * v1356 = v1315->cache_age;
      int v1481 = v1355 + ((int)((unsigned int)(v1355 - v1353) >> 31));
      v1356[v1456] = v1481;
      int * v1358 = v1315->cache_age;
      int v1359 = v1358[v1458];
      int * v1360 = v1315->cache_age;
      int v1484 = v1359 + ((int)((unsigned int)(v1359 - v1353) >> 31));
      v1360[v1458] = v1484;
      int * v1362 = v1315->cache_age;
      v1362[v1478] = 0;
      v1415 = v1478;
    } else {
      int * v1365 = v1315->cache_age;
      int v1488 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2);
      int v1366 = v1365[v1488];
      int * v1367 = v1315->cache_tags;
      int v1368 = v1367[v1488];
      int * v1369 = v1315->cache_age;
      int v1370 = v1369[v1458];
      int * v1371 = v1315->cache_tags;
      int v1372 = v1371[v1458];
      int * v1373 = v1315->cache_dirty;
      int v1493 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1370 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1374 = v1373[v1493];
      bool v1494 = !(v1374 == 0);
      if (v1494) {
        int * v1375 = v1315->cache_tags;
        int v1376 = v1375[v1493];
        int * v1377 = v1315->cache_vals;
        int v1497 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1370 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1378 = v1377[v1497];
        int * v1379 = v1315->cache_vals;
        int v1499 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1370 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1380 = v1379[v1499];
        int * v1381 = v1315->mem;
        int v1501 = v1376 * 2;
        v1381[v1501] = v1378;
        int * v1383 = v1315->mem;
        int v1504 = (v1376 * 2) + 1;
        v1383[v1504] = v1380;
        ;
      } else {
        ;
      }
      int * v1388 = v1315->mem;
      int v1509 = ((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) * 2;
      int v1389 = v1388[v1509];
      int * v1390 = v1315->mem;
      int v1511 = (((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) * 2) + 1;
      int v1391 = v1390[v1511];
      int * v1392 = v1315->cache_vals;
      int v1513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1370 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1392[v1513] = v1389;
      int * v1394 = v1315->cache_vals;
      int v1516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 3) * 2)) + ((((v1366 + ((~(((v1368 ^ -1) | (-(v1368 ^ -1))) >> 31)) & 2)) - (v1370 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1394[v1516] = v1391;
      int * v1396 = v1315->cache_tags;
      int v1519 = (int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1);
      v1396[v1493] = v1519;
      int * v1398 = v1315->cache_dirty;
      v1398[v1493] = 0;
      int * v1400 = v1315->cache_age;
      v1400[v1493] = 1;
      int * v1402 = v1315->cache_age;
      int v1403 = v1402[v1493];
      int * v1404 = v1315->cache_age;
      int v1405 = v1404[v1456];
      int * v1406 = v1315->cache_age;
      int v1527 = v1405 + ((int)((unsigned int)(v1405 - v1403) >> 31));
      v1406[v1456] = v1527;
      int * v1408 = v1315->cache_age;
      int v1409 = v1408[v1458];
      int * v1410 = v1315->cache_age;
      int v1530 = v1409 + ((int)((unsigned int)(v1409 - v1403) >> 31));
      v1410[v1458] = v1530;
      int * v1412 = v1315->cache_age;
      v1412[v1493] = 0;
      v1415 = v1493;
    }
    int * v1416 = v1315->cache_vals;
    int v1533 = v1415 * 2;
    int v1417 = v1416[v1533];
    int * v1418 = v1315->cache_vals;
    int v1535 = (v1415 * 2) + 1;
    int v1419 = v1418[v1535];
    int * v1420 = v1315->cache_vals;
    int v1537 = (((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2) + ((((v1345 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2)) - (v1349 + ((~(((v1351 ^ -1) | (-(v1351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1420[v1537] = v1417;
    int * v1422 = v1315->cache_vals;
    int v1540 = ((((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2) + ((((v1345 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2)) - (v1349 + ((~(((v1351 ^ -1) | (-(v1351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1422[v1540] = v1419;
    int * v1424 = v1315->cache_tags;
    int v1543 = ((((int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1)) & 1) * 2) + ((((v1345 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2)) - (v1349 + ((~(((v1351 ^ -1) | (-(v1351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1544 = (int)((unsigned int)((int)((unsigned int)v1319 >> 2)) >> 1);
    v1424[v1543] = v1544;
    int * v1426 = v1315->cache_dirty;
    v1426[v1543] = 0;
    int * v1428 = v1315->cache_age;
    v1428[v1543] = 1;
    int * v1430 = v1315->cache_age;
    int v1431 = v1430[v1543];
    int * v1432 = v1315->cache_age;
    int v1433 = v1432[v1452];
    int * v1434 = v1315->cache_age;
    int v1552 = v1433 + ((int)((unsigned int)(v1433 - v1431) >> 31));
    v1434[v1452] = v1552;
    int * v1436 = v1315->cache_age;
    int v1437 = v1436[v1454];
    int * v1438 = v1315->cache_age;
    int v1555 = v1437 + ((int)((unsigned int)(v1437 - v1431) >> 31));
    v1438[v1454] = v1555;
    int * v1440 = v1315->cache_age;
    v1440[v1543] = 0;
    v1443 = v1543;
  }
  int v1558 = (v1443 * 2) + (((int)((unsigned int)v1319 >> 2)) & 1);
  int v1444 = v1330[v1558];
  int * v1445 = v1315->regs;
  v1445[12] = v1444;
  return v1315;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v1049) {
  int v1050 = v1049->timer;
  int v1183 = v1050 + 1;
  v1049->timer = v1183;
  int * v1052 = v1049->regs;
  int v1053 = v1052[6];
  int * v1054 = v1049->cache_tags;
  int v1187 = (((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2;
  int v1055 = v1054[v1187];
  int * v1056 = v1049->cache_tags;
  int v1189 = ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1057 = v1056[v1189];
  int * v1058 = v1049->cache_tags;
  int v1191 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2);
  int v1059 = v1058[v1191];
  int * v1060 = v1049->cache_tags;
  int v1193 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1061 = v1060[v1193];
  int v1062 = v1049->timer;
  int v1194 = v1062 + ((100 ^ (((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1049->timer = v1194;
  int * v1064 = v1049->cache_vals;
  bool v1195 = !(((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) == 0);
  int v1177;
  if (v1195) {
    int * v1065 = v1049->cache_age;
    int v1197 = ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((~(((v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1057 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) & 1);
    int v1066 = v1065[v1197];
    int * v1067 = v1049->cache_age;
    int v1068 = v1067[v1187];
    int * v1069 = v1049->cache_age;
    int v1200 = v1068 + ((int)((unsigned int)(v1068 - v1066) >> 31));
    v1069[v1187] = v1200;
    int * v1071 = v1049->cache_age;
    int v1072 = v1071[v1189];
    int * v1073 = v1049->cache_age;
    int v1203 = v1072 + ((int)((unsigned int)(v1072 - v1066) >> 31));
    v1073[v1189] = v1203;
    int * v1075 = v1049->cache_age;
    v1075[v1197] = 0;
    v1177 = v1197;
  } else {
    int * v1078 = v1049->cache_age;
    int v1207 = (((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2;
    int v1079 = v1078[v1207];
    int * v1080 = v1049->cache_tags;
    int v1081 = v1080[v1207];
    int * v1082 = v1049->cache_age;
    int v1083 = v1082[v1189];
    int * v1084 = v1049->cache_tags;
    int v1085 = v1084[v1189];
    bool v1211 = !(((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31))) == 0);
    int v1149;
    if (v1211) {
      int * v1086 = v1049->cache_age;
      int v1213 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1))))) >> 31)) & 1);
      int v1087 = v1086[v1213];
      int * v1088 = v1049->cache_age;
      int v1089 = v1088[v1191];
      int * v1090 = v1049->cache_age;
      int v1216 = v1089 + ((int)((unsigned int)(v1089 - v1087) >> 31));
      v1090[v1191] = v1216;
      int * v1092 = v1049->cache_age;
      int v1093 = v1092[v1193];
      int * v1094 = v1049->cache_age;
      int v1219 = v1093 + ((int)((unsigned int)(v1093 - v1087) >> 31));
      v1094[v1193] = v1219;
      int * v1096 = v1049->cache_age;
      v1096[v1213] = 0;
      v1149 = v1213;
    } else {
      int * v1099 = v1049->cache_age;
      int v1223 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2);
      int v1100 = v1099[v1223];
      int * v1101 = v1049->cache_tags;
      int v1102 = v1101[v1223];
      int * v1103 = v1049->cache_age;
      int v1104 = v1103[v1193];
      int * v1105 = v1049->cache_tags;
      int v1106 = v1105[v1193];
      int * v1107 = v1049->cache_dirty;
      int v1228 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1108 = v1107[v1228];
      bool v1229 = !(v1108 == 0);
      if (v1229) {
        int * v1109 = v1049->cache_tags;
        int v1110 = v1109[v1228];
        int * v1111 = v1049->cache_vals;
        int v1232 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1112 = v1111[v1232];
        int * v1113 = v1049->cache_vals;
        int v1234 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1114 = v1113[v1234];
        int * v1115 = v1049->mem;
        int v1236 = v1110 * 2;
        v1115[v1236] = v1112;
        int * v1117 = v1049->mem;
        int v1239 = (v1110 * 2) + 1;
        v1117[v1239] = v1114;
        ;
      } else {
        ;
      }
      int * v1122 = v1049->mem;
      int v1244 = ((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) * 2;
      int v1123 = v1122[v1244];
      int * v1124 = v1049->mem;
      int v1246 = (((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) * 2) + 1;
      int v1125 = v1124[v1246];
      int * v1126 = v1049->cache_vals;
      int v1248 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1126[v1248] = v1123;
      int * v1128 = v1049->cache_vals;
      int v1251 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 3) * 2)) + ((((v1100 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2)) - (v1104 + ((~(((v1106 ^ -1) | (-(v1106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1128[v1251] = v1125;
      int * v1130 = v1049->cache_tags;
      int v1254 = (int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1);
      v1130[v1228] = v1254;
      int * v1132 = v1049->cache_dirty;
      v1132[v1228] = 0;
      int * v1134 = v1049->cache_age;
      v1134[v1228] = 1;
      int * v1136 = v1049->cache_age;
      int v1137 = v1136[v1228];
      int * v1138 = v1049->cache_age;
      int v1139 = v1138[v1191];
      int * v1140 = v1049->cache_age;
      int v1262 = v1139 + ((int)((unsigned int)(v1139 - v1137) >> 31));
      v1140[v1191] = v1262;
      int * v1142 = v1049->cache_age;
      int v1143 = v1142[v1193];
      int * v1144 = v1049->cache_age;
      int v1265 = v1143 + ((int)((unsigned int)(v1143 - v1137) >> 31));
      v1144[v1193] = v1265;
      int * v1146 = v1049->cache_age;
      v1146[v1228] = 0;
      v1149 = v1228;
    }
    int * v1150 = v1049->cache_vals;
    int v1268 = v1149 * 2;
    int v1151 = v1150[v1268];
    int * v1152 = v1049->cache_vals;
    int v1270 = (v1149 * 2) + 1;
    int v1153 = v1152[v1270];
    int * v1154 = v1049->cache_vals;
    int v1272 = (((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1154[v1272] = v1151;
    int * v1156 = v1049->cache_vals;
    int v1275 = ((((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1156[v1275] = v1153;
    int * v1158 = v1049->cache_tags;
    int v1278 = ((((int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1)) & 1) * 2) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1279 = (int)((unsigned int)((int)((unsigned int)v1053 >> 2)) >> 1);
    v1158[v1278] = v1279;
    int * v1160 = v1049->cache_dirty;
    v1160[v1278] = 0;
    int * v1162 = v1049->cache_age;
    v1162[v1278] = 1;
    int * v1164 = v1049->cache_age;
    int v1165 = v1164[v1278];
    int * v1166 = v1049->cache_age;
    int v1167 = v1166[v1187];
    int * v1168 = v1049->cache_age;
    int v1287 = v1167 + ((int)((unsigned int)(v1167 - v1165) >> 31));
    v1168[v1187] = v1287;
    int * v1170 = v1049->cache_age;
    int v1171 = v1170[v1189];
    int * v1172 = v1049->cache_age;
    int v1290 = v1171 + ((int)((unsigned int)(v1171 - v1165) >> 31));
    v1172[v1189] = v1290;
    int * v1174 = v1049->cache_age;
    v1174[v1278] = 0;
    v1177 = v1278;
  }
  int v1293 = (v1177 * 2) + (((int)((unsigned int)v1053 >> 2)) & 1);
  int v1178 = v1064[v1293];
  int * v1179 = v1049->regs;
  v1179[11] = v1178;
  struct StateT * v1181 = slot_9(v1049);
  return v1181;
}

struct StateT * slot_4(struct StateT * v64) {
  int * v65 = v64->saved_regs;
  int * v66 = v64->regs;
  int v67 = v66[7];
  v65[7] = v67;
  int v69 = v64->timer;
  int v79 = v69 + 1;
  v64->timer = v79;
  int * v71 = v64->regs;
  v71[7] = 0;
  struct StateT * v73 = slot_5(v64);
  return v73;
}

struct StateT * slot_9(struct StateT * v1299) {
  int v1300 = v1299->timer;
  int v1308 = v1300 + 1;
  v1299->timer = v1308;
  int * v1302 = v1299->regs;
  int v1303 = v1302[11];
  int * v1304 = v1299->regs;
  int v1312 = v1303 << 2;
  v1304[11] = v1312;
  struct StateT * v1306 = slot_10(v1299);
  return v1306;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
  struct StateT * v9 = slot_1(v2);
  return v9;
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