// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * v19(struct StateT * v20);
struct StateT * v25(struct StateT * v26);
struct StateT * v247(struct StateT * v248);
struct StateT * v466(struct StateT * v467);
struct StateT * v215(struct StateT * v216);
struct StateT * v278(struct StateT * v279);
struct StateT * v282(struct StateT * v283);
struct StateT * v270(struct StateT * v271);
struct StateT * v300(struct StateT * v301);
struct StateT * v31(struct StateT * v32);
struct StateT * v111(struct StateT * v112);
struct StateT * v452(struct StateT * v453);
struct StateT * v7(struct StateT * v8);
struct StateT * v35(struct StateT * v36);
struct StateT * v13(struct StateT * v14);
struct StateT * v49(struct StateT * v50);
struct StateT * v286(struct StateT * v287);
struct StateT * v187(struct StateT * v188);
struct StateT * v362(struct StateT * v363);
struct StateT * v201(struct StateT * v202);
struct StateT * v125(struct StateT * v126);
struct StateT * snippet(struct StateT * v0);
struct StateT * v438(struct StateT * v439);
struct StateT * v1(struct StateT * v2);
struct StateT * v376(struct StateT * v377);
struct StateT * v19(struct StateT * v20) {
  int v21 = v20->timer;
  int v935 = v21 + 1;
  v20->timer = v935;
  int * v23 = v20->regs;
  v23[15] = 16;
  struct StateT * v933 = v25(v20);
  return v933;
}

struct StateT * v25(struct StateT * v26) {
  int v27 = v26->timer;
  int v927 = v27 + 1;
  v26->timer = v927;
  int * v29 = v26->regs;
  v29[5] = 0;
  struct StateT * v925 = v31(v26);
  return v925;
}

struct StateT * v247(struct StateT * v248) {
  int v249 = v248->timer;
  int v259 = v249 + 1;
  v248->timer = v259;
  int * v251 = v248->regs;
  int v252 = v251[5];
  bool v262 = (v252 ^ -2147483648) < -2147483647;
  int v255;
  if (v262) {
    v255 = 1;
  } else {
    v255 = 0;
  }
  int * v256 = v248->regs;
  v256[11] = v255;
  return v248;
}

struct StateT * v466(struct StateT * v467) {
  int * v468 = v467->regs;
  int v469 = v468[14];
  int * v470 = v467->regs;
  int v471 = v470[15];
  bool v509 = v469 >= v471;
  struct StateT * v503;
  if (v509) {
    int v472 = v467->timer;
    int v510 = v472 + 15;
    v467->timer = v510;
    int * v474 = v467->saved_regs;
    int v475 = v474[6];
    int * v476 = v467->regs;
    v476[6] = v475;
    int * v478 = v467->saved_regs;
    int v479 = v478[7];
    int * v480 = v467->regs;
    v480[7] = v479;
    int * v482 = v467->saved_regs;
    int v483 = v482[8];
    int * v484 = v467->regs;
    v484[8] = v483;
    int * v486 = v467->saved_regs;
    int v487 = v486[9];
    int * v488 = v467->regs;
    v488[9] = v487;
    int * v490 = v467->saved_regs;
    int v491 = v490[16];
    int * v492 = v467->regs;
    v492[16] = v491;
    int * v494 = v467->saved_regs;
    int v495 = v494[5];
    int * v496 = v467->regs;
    v496[5] = v495;
    struct StateT * v498 = v247(v467);
    v503 = v498;
  } else {
    struct StateT * v501 = v270(v467);
    v503 = v501;
  }
  return v503;
}

struct StateT * v215(struct StateT * v216) {
  int * v217 = v216->regs;
  int v218 = v217[14];
  int * v219 = v216->regs;
  int v220 = v219[15];
  bool v728 = v218 >= v220;
  struct StateT * v722;
  if (v728) {
    int v221 = v216->timer;
    int v729 = v221 + 15;
    v216->timer = v729;
    int * v223 = v216->saved_regs;
    int v224 = v223[6];
    int * v225 = v216->regs;
    v225[6] = v224;
    int * v227 = v216->saved_regs;
    int v228 = v227[7];
    int * v229 = v216->regs;
    v229[7] = v228;
    int * v231 = v216->saved_regs;
    int v232 = v231[8];
    int * v233 = v216->regs;
    v233[8] = v232;
    int * v235 = v216->saved_regs;
    int v236 = v235[9];
    int * v237 = v216->regs;
    v237[9] = v236;
    int * v239 = v216->saved_regs;
    int v240 = v239[16];
    int * v241 = v216->regs;
    v241[16] = v240;
    int * v243 = v216->saved_regs;
    int v244 = v243[5];
    int * v245 = v216->regs;
    v245[5] = v244;
    struct StateT * v268 = v247(v216);
    v722 = v268;
  } else {
    struct StateT * v720 = v270(v216);
    v722 = v720;
  }
  return v722;
}

struct StateT * v278(struct StateT * v279) {
  int v280 = v279->timer;
  int v708 = v280 + 1;
  v279->timer = v708;
  struct StateT * v706 = v282(v279);
  return v706;
}

struct StateT * v282(struct StateT * v283) {
  int v284 = v283->timer;
  int v703 = v284 + 1;
  v283->timer = v703;
  struct StateT * v701 = v286(v283);
  return v701;
}

struct StateT * v270(struct StateT * v271) {
  int v272 = v271->timer;
  int v713 = v272 + 1;
  v271->timer = v713;
  int * v274 = v271->regs;
  int v275 = v274[14];
  int * v276 = v271->regs;
  int v717 = v275 + 4;
  v276[14] = v717;
  struct StateT * v711 = v278(v271);
  return v711;
}

struct StateT * v300(struct StateT * v301) {
  int * v302 = v301->saved_regs;
  int * v303 = v301->regs;
  int v304 = v303[7];
  v302[7] = v304;
  int v306 = v301->timer;
  int v641 = v306 + 1;
  v301->timer = v641;
  int * v308 = v301->regs;
  int v309 = v308[6];
  int * v310 = v301->cache_keys;
  int v311 = v310[0];
  bool v646 = v311 == ((int)((unsigned int)v309 >> 2));
  int v359;
  if (v646) {
    int * v312 = v301->cache_vals;
    int v313 = v312[0];
    v359 = v313;
  } else {
    int * v315 = v301->cache_keys;
    int v316 = v315[1];
    bool v651 = v316 == ((int)((unsigned int)v309 >> 2));
    int v357;
    if (v651) {
      int * v317 = v301->cache_vals;
      int v318 = v317[1];
      int * v319 = v301->cache_keys;
      int * v320 = v301->cache_keys;
      int v321 = v320[0];
      v319[1] = v321;
      int * v323 = v301->cache_vals;
      int * v324 = v301->cache_vals;
      int v325 = v324[0];
      v323[1] = v325;
      int * v327 = v301->cache_keys;
      int v660 = (int)((unsigned int)v309 >> 2);
      v327[0] = v660;
      int * v329 = v301->cache_vals;
      v329[0] = v318;
      int v331 = v301->timer;
      int v663 = v331 + 1;
      v301->timer = v663;
      v357 = v318;
    } else {
      int * v334 = v301->mem;
      int v665 = (int)((unsigned int)v309 >> 2);
      int v335 = v334[v665];
      int * v336 = v301->mem;
      int * v337 = v301->cache_keys;
      int v338 = v337[1];
      int * v339 = v301->cache_vals;
      int v340 = v339[1];
      v336[v338] = v340;
      int * v342 = v301->cache_keys;
      int * v343 = v301->cache_keys;
      int v344 = v343[0];
      v342[1] = v344;
      int * v346 = v301->cache_vals;
      int * v347 = v301->cache_vals;
      int v348 = v347[0];
      v346[1] = v348;
      int * v350 = v301->cache_keys;
      v350[0] = v665;
      int * v352 = v301->cache_vals;
      v352[0] = v335;
      int v354 = v301->timer;
      int v680 = v354 + 100;
      v301->timer = v680;
      v357 = v335;
    }
    v359 = v357;
  }
  int * v360 = v301->regs;
  v360[7] = v359;
  struct StateT * v635 = v362(v301);
  return v635;
}

struct StateT * v31(struct StateT * v32) {
  int v33 = v32->timer;
  int v922 = v33 + 1;
  v32->timer = v922;
  struct StateT * v920 = v35(v32);
  return v920;
}

struct StateT * v111(struct StateT * v112) {
  int * v113 = v112->saved_regs;
  int * v114 = v112->regs;
  int v115 = v114[8];
  v113[8] = v115;
  int v117 = v112->timer;
  int v845 = v117 + 1;
  v112->timer = v845;
  int * v119 = v112->regs;
  int v120 = v119[13];
  int * v121 = v112->regs;
  int v122 = v121[14];
  int * v123 = v112->regs;
  int v851 = v120 + v122;
  v123[8] = v851;
  struct StateT * v839 = v125(v112);
  return v839;
}

struct StateT * v452(struct StateT * v453) {
  int * v454 = v453->saved_regs;
  int * v455 = v453->regs;
  int v456 = v455[5];
  v454[5] = v456;
  int v458 = v453->timer;
  int v546 = v458 + 1;
  v453->timer = v546;
  int * v460 = v453->regs;
  int v461 = v460[5];
  int * v462 = v453->regs;
  int v463 = v462[16];
  int * v464 = v453->regs;
  int v551 = v461 | v463;
  v464[5] = v551;
  struct StateT * v540 = v466(v453);
  return v540;
}

struct StateT * v7(struct StateT * v8) {
  int v9 = v8->timer;
  int v951 = v9 + 1;
  v8->timer = v951;
  int * v11 = v8->regs;
  v11[13] = 80;
  struct StateT * v949 = v13(v8);
  return v949;
}

struct StateT * v35(struct StateT * v36) {
  int * v37 = v36->saved_regs;
  int * v38 = v36->regs;
  int v39 = v38[6];
  v37[6] = v39;
  int v41 = v36->timer;
  int v911 = v41 + 1;
  v36->timer = v911;
  int * v43 = v36->regs;
  int v44 = v43[12];
  int * v45 = v36->regs;
  int v46 = v45[14];
  int * v47 = v36->regs;
  int v917 = v44 + v46;
  v47[6] = v917;
  struct StateT * v905 = v49(v36);
  return v905;
}

struct StateT * v13(struct StateT * v14) {
  int v15 = v14->timer;
  int v943 = v15 + 1;
  v14->timer = v943;
  int * v17 = v14->regs;
  v17[14] = 0;
  struct StateT * v941 = v19(v14);
  return v941;
}

struct StateT * v49(struct StateT * v50) {
  int * v51 = v50->saved_regs;
  int * v52 = v50->regs;
  int v53 = v52[7];
  v51[7] = v53;
  int v55 = v50->timer;
  int v860 = v55 + 1;
  v50->timer = v860;
  int * v57 = v50->regs;
  int v58 = v57[6];
  int * v59 = v50->cache_keys;
  int v60 = v59[0];
  bool v865 = v60 == ((int)((unsigned int)v58 >> 2));
  int v108;
  if (v865) {
    int * v61 = v50->cache_vals;
    int v62 = v61[0];
    v108 = v62;
  } else {
    int * v64 = v50->cache_keys;
    int v65 = v64[1];
    bool v870 = v65 == ((int)((unsigned int)v58 >> 2));
    int v106;
    if (v870) {
      int * v66 = v50->cache_vals;
      int v67 = v66[1];
      int * v68 = v50->cache_keys;
      int * v69 = v50->cache_keys;
      int v70 = v69[0];
      v68[1] = v70;
      int * v72 = v50->cache_vals;
      int * v73 = v50->cache_vals;
      int v74 = v73[0];
      v72[1] = v74;
      int * v76 = v50->cache_keys;
      int v879 = (int)((unsigned int)v58 >> 2);
      v76[0] = v879;
      int * v78 = v50->cache_vals;
      v78[0] = v67;
      int v80 = v50->timer;
      int v882 = v80 + 1;
      v50->timer = v882;
      v106 = v67;
    } else {
      int * v83 = v50->mem;
      int v884 = (int)((unsigned int)v58 >> 2);
      int v84 = v83[v884];
      int * v85 = v50->mem;
      int * v86 = v50->cache_keys;
      int v87 = v86[1];
      int * v88 = v50->cache_vals;
      int v89 = v88[1];
      v85[v87] = v89;
      int * v91 = v50->cache_keys;
      int * v92 = v50->cache_keys;
      int v93 = v92[0];
      v91[1] = v93;
      int * v95 = v50->cache_vals;
      int * v96 = v50->cache_vals;
      int v97 = v96[0];
      v95[1] = v97;
      int * v99 = v50->cache_keys;
      v99[0] = v884;
      int * v101 = v50->cache_vals;
      v101[0] = v84;
      int v103 = v50->timer;
      int v899 = v103 + 100;
      v50->timer = v899;
      v106 = v84;
    }
    v108 = v106;
  }
  int * v109 = v50->regs;
  v109[7] = v108;
  struct StateT * v854 = v111(v50);
  return v854;
}

struct StateT * v286(struct StateT * v287) {
  int * v288 = v287->saved_regs;
  int * v289 = v287->regs;
  int v290 = v289[6];
  v288[6] = v290;
  int v292 = v287->timer;
  int v692 = v292 + 1;
  v287->timer = v692;
  int * v294 = v287->regs;
  int v295 = v294[12];
  int * v296 = v287->regs;
  int v297 = v296[14];
  int * v298 = v287->regs;
  int v698 = v295 + v297;
  v298[6] = v698;
  struct StateT * v686 = v300(v287);
  return v686;
}

struct StateT * v187(struct StateT * v188) {
  int * v189 = v188->saved_regs;
  int * v190 = v188->regs;
  int v191 = v190[16];
  v189[16] = v191;
  int v193 = v188->timer;
  int v779 = v193 + 1;
  v188->timer = v779;
  int * v195 = v188->regs;
  int v196 = v195[7];
  int * v197 = v188->regs;
  int v198 = v197[9];
  int * v199 = v188->regs;
  int v785 = v196 ^ v198;
  v199[16] = v785;
  struct StateT * v773 = v201(v188);
  return v773;
}

struct StateT * v362(struct StateT * v363) {
  int * v364 = v363->saved_regs;
  int * v365 = v363->regs;
  int v366 = v365[8];
  v364[8] = v366;
  int v368 = v363->timer;
  int v626 = v368 + 1;
  v363->timer = v626;
  int * v370 = v363->regs;
  int v371 = v370[13];
  int * v372 = v363->regs;
  int v373 = v372[14];
  int * v374 = v363->regs;
  int v632 = v371 + v373;
  v374[8] = v632;
  struct StateT * v620 = v376(v363);
  return v620;
}

struct StateT * v201(struct StateT * v202) {
  int * v203 = v202->saved_regs;
  int * v204 = v202->regs;
  int v205 = v204[5];
  v203[5] = v205;
  int v207 = v202->timer;
  int v765 = v207 + 1;
  v202->timer = v765;
  int * v209 = v202->regs;
  int v210 = v209[5];
  int * v211 = v202->regs;
  int v212 = v211[16];
  int * v213 = v202->regs;
  int v770 = v210 | v212;
  v213[5] = v770;
  struct StateT * v759 = v215(v202);
  return v759;
}

struct StateT * v125(struct StateT * v126) {
  int * v127 = v126->saved_regs;
  int * v128 = v126->regs;
  int v129 = v128[9];
  v127[9] = v129;
  int v131 = v126->timer;
  int v794 = v131 + 1;
  v126->timer = v794;
  int * v133 = v126->regs;
  int v134 = v133[8];
  int * v135 = v126->cache_keys;
  int v136 = v135[0];
  bool v799 = v136 == ((int)((unsigned int)v134 >> 2));
  int v184;
  if (v799) {
    int * v137 = v126->cache_vals;
    int v138 = v137[0];
    v184 = v138;
  } else {
    int * v140 = v126->cache_keys;
    int v141 = v140[1];
    bool v804 = v141 == ((int)((unsigned int)v134 >> 2));
    int v182;
    if (v804) {
      int * v142 = v126->cache_vals;
      int v143 = v142[1];
      int * v144 = v126->cache_keys;
      int * v145 = v126->cache_keys;
      int v146 = v145[0];
      v144[1] = v146;
      int * v148 = v126->cache_vals;
      int * v149 = v126->cache_vals;
      int v150 = v149[0];
      v148[1] = v150;
      int * v152 = v126->cache_keys;
      int v813 = (int)((unsigned int)v134 >> 2);
      v152[0] = v813;
      int * v154 = v126->cache_vals;
      v154[0] = v143;
      int v156 = v126->timer;
      int v816 = v156 + 1;
      v126->timer = v816;
      v182 = v143;
    } else {
      int * v159 = v126->mem;
      int v818 = (int)((unsigned int)v134 >> 2);
      int v160 = v159[v818];
      int * v161 = v126->mem;
      int * v162 = v126->cache_keys;
      int v163 = v162[1];
      int * v164 = v126->cache_vals;
      int v165 = v164[1];
      v161[v163] = v165;
      int * v167 = v126->cache_keys;
      int * v168 = v126->cache_keys;
      int v169 = v168[0];
      v167[1] = v169;
      int * v171 = v126->cache_vals;
      int * v172 = v126->cache_vals;
      int v173 = v172[0];
      v171[1] = v173;
      int * v175 = v126->cache_keys;
      v175[0] = v818;
      int * v177 = v126->cache_vals;
      v177[0] = v160;
      int v179 = v126->timer;
      int v833 = v179 + 100;
      v126->timer = v833;
      v182 = v160;
    }
    v184 = v182;
  }
  int * v185 = v126->regs;
  v185[9] = v184;
  struct StateT * v788 = v187(v126);
  return v788;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v965 = v1(v0);
  return v965;
}

struct StateT * v438(struct StateT * v439) {
  int * v440 = v439->saved_regs;
  int * v441 = v439->regs;
  int v442 = v441[16];
  v440[16] = v442;
  int v444 = v439->timer;
  int v560 = v444 + 1;
  v439->timer = v560;
  int * v446 = v439->regs;
  int v447 = v446[7];
  int * v448 = v439->regs;
  int v449 = v448[9];
  int * v450 = v439->regs;
  int v566 = v447 ^ v449;
  v450[16] = v566;
  struct StateT * v554 = v452(v439);
  return v554;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v959 = v3 + 1;
  v2->timer = v959;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v957 = v7(v2);
  return v957;
}

struct StateT * v376(struct StateT * v377) {
  int * v378 = v377->saved_regs;
  int * v379 = v377->regs;
  int v380 = v379[9];
  v378[9] = v380;
  int v382 = v377->timer;
  int v575 = v382 + 1;
  v377->timer = v575;
  int * v384 = v377->regs;
  int v385 = v384[8];
  int * v386 = v377->cache_keys;
  int v387 = v386[0];
  bool v580 = v387 == ((int)((unsigned int)v385 >> 2));
  int v435;
  if (v580) {
    int * v388 = v377->cache_vals;
    int v389 = v388[0];
    v435 = v389;
  } else {
    int * v391 = v377->cache_keys;
    int v392 = v391[1];
    bool v585 = v392 == ((int)((unsigned int)v385 >> 2));
    int v433;
    if (v585) {
      int * v393 = v377->cache_vals;
      int v394 = v393[1];
      int * v395 = v377->cache_keys;
      int * v396 = v377->cache_keys;
      int v397 = v396[0];
      v395[1] = v397;
      int * v399 = v377->cache_vals;
      int * v400 = v377->cache_vals;
      int v401 = v400[0];
      v399[1] = v401;
      int * v403 = v377->cache_keys;
      int v594 = (int)((unsigned int)v385 >> 2);
      v403[0] = v594;
      int * v405 = v377->cache_vals;
      v405[0] = v394;
      int v407 = v377->timer;
      int v597 = v407 + 1;
      v377->timer = v597;
      v433 = v394;
    } else {
      int * v410 = v377->mem;
      int v599 = (int)((unsigned int)v385 >> 2);
      int v411 = v410[v599];
      int * v412 = v377->mem;
      int * v413 = v377->cache_keys;
      int v414 = v413[1];
      int * v415 = v377->cache_vals;
      int v416 = v415[1];
      v412[v414] = v416;
      int * v418 = v377->cache_keys;
      int * v419 = v377->cache_keys;
      int v420 = v419[0];
      v418[1] = v420;
      int * v422 = v377->cache_vals;
      int * v423 = v377->cache_vals;
      int v424 = v423[0];
      v422[1] = v424;
      int * v426 = v377->cache_keys;
      v426[0] = v599;
      int * v428 = v377->cache_vals;
      v428[0] = v411;
      int v430 = v377->timer;
      int v614 = v430 + 100;
      v377->timer = v614;
      v433 = v411;
    }
    v435 = v433;
  }
  int * v436 = v377->regs;
  v436[9] = v435;
  struct StateT * v569 = v438(v377);
  return v569;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}