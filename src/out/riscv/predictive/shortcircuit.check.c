// verify: leak (CBMC should report VERIFICATION FAILED)

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

struct StateT * slot_6(struct StateT * v90);
struct StateT * slot_29(struct StateT * v882);
struct StateT * slot_25(struct StateT * v841);
struct StateT * slot_16(struct StateT * v484);
struct StateT * slot_23(struct StateT * v673);
struct StateT * slot_5(struct StateT * v62);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v202);
struct StateT * slot_21(struct StateT * v533);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_26(struct StateT * v851);
struct StateT * slot_10(struct StateT * v398);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v416);
struct StateT * slot_24(struct StateT * v785);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v439);
struct StateT * slot_28(struct StateT * v859);
struct StateT * slot_17(struct StateT * v492);
struct StateT * slot_20(struct StateT * v505);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v230);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_15(struct StateT * v471);
struct StateT * slot_18(struct StateT * v497);
struct StateT * slot_9(struct StateT * v342);
struct StateT * slot_22(struct StateT * v645);
struct StateT * slot_11(struct StateT * v408);
struct StateT * slot_6(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[10];
  v91[10] = v93;
  int v95 = v90->timer;
  int v157 = v95 + 1;
  v90->timer = v157;
  int * v97 = v90->regs;
  int v98 = v97[5];
  int * v99 = v90->cache_keys;
  int v100 = v99[0];
  bool v162 = v100 == ((int)((unsigned int)v98 >> 2));
  int v148;
  if (v162) {
    int * v101 = v90->cache_vals;
    int v102 = v101[0];
    v148 = v102;
  } else {
    int * v104 = v90->cache_keys;
    int v105 = v104[1];
    bool v167 = v105 == ((int)((unsigned int)v98 >> 2));
    int v146;
    if (v167) {
      int * v106 = v90->cache_vals;
      int v107 = v106[1];
      int * v108 = v90->cache_keys;
      int * v109 = v90->cache_keys;
      int v110 = v109[0];
      v108[1] = v110;
      int * v112 = v90->cache_vals;
      int * v113 = v90->cache_vals;
      int v114 = v113[0];
      v112[1] = v114;
      int * v116 = v90->cache_keys;
      int v176 = (int)((unsigned int)v98 >> 2);
      v116[0] = v176;
      int * v118 = v90->cache_vals;
      v118[0] = v107;
      int v120 = v90->timer;
      int v179 = v120 + 1;
      v90->timer = v179;
      v146 = v107;
    } else {
      int * v123 = v90->mem;
      int v181 = (int)((unsigned int)v98 >> 2);
      int v124 = v123[v181];
      int * v125 = v90->mem;
      int * v126 = v90->cache_keys;
      int v127 = v126[1];
      int * v128 = v90->cache_vals;
      int v129 = v128[1];
      v125[v127] = v129;
      int * v131 = v90->cache_keys;
      int * v132 = v90->cache_keys;
      int v133 = v132[0];
      v131[1] = v133;
      int * v135 = v90->cache_vals;
      int * v136 = v90->cache_vals;
      int v137 = v136[0];
      v135[1] = v137;
      int * v139 = v90->cache_keys;
      v139[0] = v181;
      int * v141 = v90->cache_vals;
      v141[0] = v124;
      int v143 = v90->timer;
      int v196 = v143 + 100;
      v90->timer = v196;
      v146 = v124;
    }
    v148 = v146;
  }
  int * v149 = v90->regs;
  v149[10] = v148;
  struct StateT * v151 = slot_7(v90);
  return v151;
}

struct StateT * slot_29(struct StateT * v882) {
  int * v883 = v882->regs;
  int v884 = v883[10];
  int * v885 = v882->regs;
  int v886 = v885[11];
  bool v903 = !(v884 == v886);
  struct StateT * v897;
  if (v903) {
    int v887 = v882->timer;
    int v904 = v887 + 15;
    v882->timer = v904;
    int * v889 = v882->saved_regs;
    int v890 = v889[14];
    int * v891 = v882->regs;
    v891[14] = v890;
    struct StateT * v893 = slot_15(v882);
    v897 = v893;
  } else {
    struct StateT * v895 = slot_16(v882);
    v897 = v895;
  }
  return v897;
}

struct StateT * slot_25(struct StateT * v841) {
  int v842 = v841->timer;
  int v847 = v842 + 1;
  v841->timer = v847;
  int * v844 = v841->regs;
  v844[10] = 1;
  return v841;
}

struct StateT * slot_16(struct StateT * v484) {
  int v485 = v484->timer;
  int v489 = v485 + 1;
  v484->timer = v489;
  struct StateT * v487 = slot_18(v484);
  return v487;
}

struct StateT * slot_23(struct StateT * v673) {
  int * v674 = v673->saved_regs;
  int * v675 = v673->regs;
  int v676 = v675[11];
  v674[11] = v676;
  int v678 = v673->timer;
  int v740 = v678 + 1;
  v673->timer = v740;
  int * v680 = v673->regs;
  int v681 = v680[6];
  int * v682 = v673->cache_keys;
  int v683 = v682[0];
  bool v745 = v683 == ((int)((unsigned int)v681 >> 2));
  int v731;
  if (v745) {
    int * v684 = v673->cache_vals;
    int v685 = v684[0];
    v731 = v685;
  } else {
    int * v687 = v673->cache_keys;
    int v688 = v687[1];
    bool v750 = v688 == ((int)((unsigned int)v681 >> 2));
    int v729;
    if (v750) {
      int * v689 = v673->cache_vals;
      int v690 = v689[1];
      int * v691 = v673->cache_keys;
      int * v692 = v673->cache_keys;
      int v693 = v692[0];
      v691[1] = v693;
      int * v695 = v673->cache_vals;
      int * v696 = v673->cache_vals;
      int v697 = v696[0];
      v695[1] = v697;
      int * v699 = v673->cache_keys;
      int v759 = (int)((unsigned int)v681 >> 2);
      v699[0] = v759;
      int * v701 = v673->cache_vals;
      v701[0] = v690;
      int v703 = v673->timer;
      int v762 = v703 + 1;
      v673->timer = v762;
      v729 = v690;
    } else {
      int * v706 = v673->mem;
      int v764 = (int)((unsigned int)v681 >> 2);
      int v707 = v706[v764];
      int * v708 = v673->mem;
      int * v709 = v673->cache_keys;
      int v710 = v709[1];
      int * v711 = v673->cache_vals;
      int v712 = v711[1];
      v708[v710] = v712;
      int * v714 = v673->cache_keys;
      int * v715 = v673->cache_keys;
      int v716 = v715[0];
      v714[1] = v716;
      int * v718 = v673->cache_vals;
      int * v719 = v673->cache_vals;
      int v720 = v719[0];
      v718[1] = v720;
      int * v722 = v673->cache_keys;
      v722[0] = v764;
      int * v724 = v673->cache_vals;
      v724[0] = v707;
      int v726 = v673->timer;
      int v779 = v726 + 100;
      v673->timer = v779;
      v729 = v707;
    }
    v731 = v729;
  }
  int * v732 = v673->regs;
  v732[11] = v731;
  struct StateT * v734 = slot_24(v673);
  return v734;
}

struct StateT * slot_5(struct StateT * v62) {
  int * v63 = v62->saved_regs;
  int * v64 = v62->regs;
  int v65 = v64[5];
  v63[5] = v65;
  int v67 = v62->timer;
  int v81 = v67 + 1;
  v62->timer = v81;
  int * v69 = v62->regs;
  int v70 = v69[12];
  int * v71 = v62->regs;
  int v72 = v71[14];
  int * v73 = v62->regs;
  int v87 = v70 + v72;
  v73[5] = v87;
  struct StateT * v75 = slot_6(v62);
  return v75;
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

struct StateT * slot_7(struct StateT * v202) {
  int * v203 = v202->saved_regs;
  int * v204 = v202->regs;
  int v205 = v204[6];
  v203[6] = v205;
  int v207 = v202->timer;
  int v221 = v207 + 1;
  v202->timer = v221;
  int * v209 = v202->regs;
  int v210 = v209[13];
  int * v211 = v202->regs;
  int v212 = v211[14];
  int * v213 = v202->regs;
  int v227 = v210 + v212;
  v213[6] = v227;
  struct StateT * v215 = slot_8(v202);
  return v215;
}

struct StateT * slot_21(struct StateT * v533) {
  int * v534 = v533->saved_regs;
  int * v535 = v533->regs;
  int v536 = v535[10];
  v534[10] = v536;
  int v538 = v533->timer;
  int v600 = v538 + 1;
  v533->timer = v600;
  int * v540 = v533->regs;
  int v541 = v540[5];
  int * v542 = v533->cache_keys;
  int v543 = v542[0];
  bool v605 = v543 == ((int)((unsigned int)v541 >> 2));
  int v591;
  if (v605) {
    int * v544 = v533->cache_vals;
    int v545 = v544[0];
    v591 = v545;
  } else {
    int * v547 = v533->cache_keys;
    int v548 = v547[1];
    bool v610 = v548 == ((int)((unsigned int)v541 >> 2));
    int v589;
    if (v610) {
      int * v549 = v533->cache_vals;
      int v550 = v549[1];
      int * v551 = v533->cache_keys;
      int * v552 = v533->cache_keys;
      int v553 = v552[0];
      v551[1] = v553;
      int * v555 = v533->cache_vals;
      int * v556 = v533->cache_vals;
      int v557 = v556[0];
      v555[1] = v557;
      int * v559 = v533->cache_keys;
      int v619 = (int)((unsigned int)v541 >> 2);
      v559[0] = v619;
      int * v561 = v533->cache_vals;
      v561[0] = v550;
      int v563 = v533->timer;
      int v622 = v563 + 1;
      v533->timer = v622;
      v589 = v550;
    } else {
      int * v566 = v533->mem;
      int v624 = (int)((unsigned int)v541 >> 2);
      int v567 = v566[v624];
      int * v568 = v533->mem;
      int * v569 = v533->cache_keys;
      int v570 = v569[1];
      int * v571 = v533->cache_vals;
      int v572 = v571[1];
      v568[v570] = v572;
      int * v574 = v533->cache_keys;
      int * v575 = v533->cache_keys;
      int v576 = v575[0];
      v574[1] = v576;
      int * v578 = v533->cache_vals;
      int * v579 = v533->cache_vals;
      int v580 = v579[0];
      v578[1] = v580;
      int * v582 = v533->cache_keys;
      v582[0] = v624;
      int * v584 = v533->cache_vals;
      v584[0] = v567;
      int v586 = v533->timer;
      int v639 = v586 + 100;
      v533->timer = v639;
      v589 = v567;
    }
    v591 = v589;
  }
  int * v592 = v533->regs;
  v592[10] = v591;
  struct StateT * v594 = slot_22(v533);
  return v594;
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

struct StateT * slot_26(struct StateT * v851) {
  int v852 = v851->timer;
  int v856 = v852 + 1;
  v851->timer = v856;
  struct StateT * v854 = slot_28(v851);
  return v854;
}

struct StateT * slot_10(struct StateT * v398) {
  int v399 = v398->timer;
  int v404 = v399 + 1;
  v398->timer = v404;
  int * v401 = v398->regs;
  v401[10] = 1;
  return v398;
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

struct StateT * slot_13(struct StateT * v416) {
  int * v417 = v416->saved_regs;
  int * v418 = v416->regs;
  int v419 = v418[14];
  v417[14] = v419;
  int v421 = v416->timer;
  int v433 = v421 + 1;
  v416->timer = v433;
  int * v423 = v416->regs;
  int v424 = v423[14];
  int * v425 = v416->regs;
  int v436 = v424 + 4;
  v425[14] = v436;
  struct StateT * v427 = slot_14(v416);
  return v427;
}

struct StateT * slot_24(struct StateT * v785) {
  int * v786 = v785->regs;
  int v787 = v786[14];
  int * v788 = v785->regs;
  int v789 = v788[15];
  bool v818 = v787 >= v789;
  struct StateT * v812;
  if (v818) {
    int v790 = v785->timer;
    int v819 = v790 + 15;
    v785->timer = v819;
    int * v792 = v785->saved_regs;
    int v793 = v792[5];
    int * v794 = v785->regs;
    v794[5] = v793;
    int * v796 = v785->saved_regs;
    int v797 = v796[10];
    int * v798 = v785->regs;
    v798[10] = v797;
    int * v800 = v785->saved_regs;
    int v801 = v800[6];
    int * v802 = v785->regs;
    v802[6] = v801;
    int * v804 = v785->saved_regs;
    int v805 = v804[11];
    int * v806 = v785->regs;
    v806[11] = v805;
    struct StateT * v808 = slot_25(v785);
    v812 = v808;
  } else {
    struct StateT * v810 = slot_26(v785);
    v812 = v810;
  }
  return v812;
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

struct StateT * slot_14(struct StateT * v439) {
  int * v440 = v439->regs;
  int v441 = v440[10];
  int * v442 = v439->regs;
  int v443 = v442[11];
  bool v460 = !(v441 == v443);
  struct StateT * v454;
  if (v460) {
    int v444 = v439->timer;
    int v461 = v444 + 15;
    v439->timer = v461;
    int * v446 = v439->saved_regs;
    int v447 = v446[14];
    int * v448 = v439->regs;
    v448[14] = v447;
    struct StateT * v450 = slot_15(v439);
    v454 = v450;
  } else {
    struct StateT * v452 = slot_16(v439);
    v454 = v452;
  }
  return v454;
}

struct StateT * slot_28(struct StateT * v859) {
  int * v860 = v859->saved_regs;
  int * v861 = v859->regs;
  int v862 = v861[14];
  v860[14] = v862;
  int v864 = v859->timer;
  int v876 = v864 + 1;
  v859->timer = v876;
  int * v866 = v859->regs;
  int v867 = v866[14];
  int * v868 = v859->regs;
  int v879 = v867 + 4;
  v868[14] = v879;
  struct StateT * v870 = slot_29(v859);
  return v870;
}

struct StateT * slot_17(struct StateT * v492) {
  int v493 = v492->timer;
  int v496 = v493 + 1;
  v492->timer = v496;
  return v492;
}

struct StateT * slot_20(struct StateT * v505) {
  int * v506 = v505->saved_regs;
  int * v507 = v505->regs;
  int v508 = v507[5];
  v506[5] = v508;
  int v510 = v505->timer;
  int v524 = v510 + 1;
  v505->timer = v524;
  int * v512 = v505->regs;
  int v513 = v512[12];
  int * v514 = v505->regs;
  int v515 = v514[14];
  int * v516 = v505->regs;
  int v530 = v513 + v515;
  v516[5] = v530;
  struct StateT * v518 = slot_21(v505);
  return v518;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v230) {
  int * v231 = v230->saved_regs;
  int * v232 = v230->regs;
  int v233 = v232[11];
  v231[11] = v233;
  int v235 = v230->timer;
  int v297 = v235 + 1;
  v230->timer = v297;
  int * v237 = v230->regs;
  int v238 = v237[6];
  int * v239 = v230->cache_keys;
  int v240 = v239[0];
  bool v302 = v240 == ((int)((unsigned int)v238 >> 2));
  int v288;
  if (v302) {
    int * v241 = v230->cache_vals;
    int v242 = v241[0];
    v288 = v242;
  } else {
    int * v244 = v230->cache_keys;
    int v245 = v244[1];
    bool v307 = v245 == ((int)((unsigned int)v238 >> 2));
    int v286;
    if (v307) {
      int * v246 = v230->cache_vals;
      int v247 = v246[1];
      int * v248 = v230->cache_keys;
      int * v249 = v230->cache_keys;
      int v250 = v249[0];
      v248[1] = v250;
      int * v252 = v230->cache_vals;
      int * v253 = v230->cache_vals;
      int v254 = v253[0];
      v252[1] = v254;
      int * v256 = v230->cache_keys;
      int v316 = (int)((unsigned int)v238 >> 2);
      v256[0] = v316;
      int * v258 = v230->cache_vals;
      v258[0] = v247;
      int v260 = v230->timer;
      int v319 = v260 + 1;
      v230->timer = v319;
      v286 = v247;
    } else {
      int * v263 = v230->mem;
      int v321 = (int)((unsigned int)v238 >> 2);
      int v264 = v263[v321];
      int * v265 = v230->mem;
      int * v266 = v230->cache_keys;
      int v267 = v266[1];
      int * v268 = v230->cache_vals;
      int v269 = v268[1];
      v265[v267] = v269;
      int * v271 = v230->cache_keys;
      int * v272 = v230->cache_keys;
      int v273 = v272[0];
      v271[1] = v273;
      int * v275 = v230->cache_vals;
      int * v276 = v230->cache_vals;
      int v277 = v276[0];
      v275[1] = v277;
      int * v279 = v230->cache_keys;
      v279[0] = v321;
      int * v281 = v230->cache_vals;
      v281[0] = v264;
      int v283 = v230->timer;
      int v336 = v283 + 100;
      v230->timer = v336;
      v286 = v264;
    }
    v288 = v286;
  }
  int * v289 = v230->regs;
  v289[11] = v288;
  struct StateT * v291 = slot_9(v230);
  return v291;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v59 = v55 + 1;
  v54->timer = v59;
  struct StateT * v57 = slot_5(v54);
  return v57;
}

struct StateT * slot_15(struct StateT * v471) {
  int v472 = v471->timer;
  int v478 = v472 + 1;
  v471->timer = v478;
  int * v474 = v471->regs;
  v474[10] = 0;
  struct StateT * v476 = slot_17(v471);
  return v476;
}

struct StateT * slot_18(struct StateT * v497) {
  int v498 = v497->timer;
  int v502 = v498 + 1;
  v497->timer = v502;
  struct StateT * v500 = slot_20(v497);
  return v500;
}

struct StateT * slot_9(struct StateT * v342) {
  int * v343 = v342->regs;
  int v344 = v343[14];
  int * v345 = v342->regs;
  int v346 = v345[15];
  bool v375 = v344 >= v346;
  struct StateT * v369;
  if (v375) {
    int v347 = v342->timer;
    int v376 = v347 + 15;
    v342->timer = v376;
    int * v349 = v342->saved_regs;
    int v350 = v349[5];
    int * v351 = v342->regs;
    v351[5] = v350;
    int * v353 = v342->saved_regs;
    int v354 = v353[10];
    int * v355 = v342->regs;
    v355[10] = v354;
    int * v357 = v342->saved_regs;
    int v358 = v357[6];
    int * v359 = v342->regs;
    v359[6] = v358;
    int * v361 = v342->saved_regs;
    int v362 = v361[11];
    int * v363 = v342->regs;
    v363[11] = v362;
    struct StateT * v365 = slot_10(v342);
    v369 = v365;
  } else {
    struct StateT * v367 = slot_11(v342);
    v369 = v367;
  }
  return v369;
}

struct StateT * slot_22(struct StateT * v645) {
  int * v646 = v645->saved_regs;
  int * v647 = v645->regs;
  int v648 = v647[6];
  v646[6] = v648;
  int v650 = v645->timer;
  int v664 = v650 + 1;
  v645->timer = v664;
  int * v652 = v645->regs;
  int v653 = v652[13];
  int * v654 = v645->regs;
  int v655 = v654[14];
  int * v656 = v645->regs;
  int v670 = v653 + v655;
  v656[6] = v670;
  struct StateT * v658 = slot_23(v645);
  return v658;
}

struct StateT * slot_11(struct StateT * v408) {
  int v409 = v408->timer;
  int v413 = v409 + 1;
  v408->timer = v413;
  struct StateT * v411 = slot_13(v408);
  return v411;
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