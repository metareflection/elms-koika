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

struct StateT * v19(struct StateT * v20);
struct StateT * v15(struct StateT * v16);
struct StateT * v457(struct StateT * v458);
struct StateT * v117(struct StateT * v118);
struct StateT * v37(struct StateT * v38);
struct StateT * v417(struct StateT * v418);
struct StateT * v269(struct StateT * v270);
struct StateT * v209(struct StateT * v210);
struct StateT * v565(struct StateT * v566);
struct StateT * v9(struct StateT * v10);
struct StateT * v359(struct StateT * v360);
struct StateT * v445(struct StateT * v446);
struct StateT * v627(struct StateT * v628);
struct StateT * v29(struct StateT * v30);
struct StateT * v179(struct StateT * v180);
struct StateT * v477(struct StateT * v478);
struct StateT * v291(struct StateT * v292);
struct StateT * v421(struct StateT * v422);
struct StateT * v301(struct StateT * v302);
struct StateT * v499(struct StateT * v500);
struct StateT * v237(struct StateT * v238);
struct StateT * v503(struct StateT * v504);
struct StateT * v201(struct StateT * v202);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v249(struct StateT * v250);
struct StateT * v644(struct StateT * v645);
struct StateT * v47(struct StateT * v48);
struct StateT * v433(struct StateT * v434);
struct StateT * v225(struct StateT * v226);
struct StateT * v275(struct StateT * v276);
struct StateT * v483(struct StateT * v484);
struct StateT * v213(struct StateT * v214);
struct StateT * v55(struct StateT * v56);
struct StateT * v295(struct StateT * v296);
struct StateT * v19(struct StateT * v20) {
  int * v21 = v20->saved_regs;
  int * v22 = v20->regs;
  int v23 = v22[12];
  v21[12] = v23;
  int v25 = v20->timer;
  int v1196 = v25 + 1;
  v20->timer = v1196;
  int * v27 = v20->regs;
  v27[12] = 0;
  struct StateT * v1190 = v29(v20);
  return v1190;
}

struct StateT * v15(struct StateT * v16) {
  int v17 = v16->timer;
  int v1203 = v17 + 1;
  v16->timer = v1203;
  struct StateT * v1201 = v19(v16);
  return v1201;
}

struct StateT * v457(struct StateT * v458) {
  int * v459 = v458->regs;
  int v460 = v459[14];
  int * v461 = v458->regs;
  int v462 = v461[15];
  bool v786 = !(v460 == v462);
  struct StateT * v780;
  if (v786) {
    int v463 = v458->timer;
    int v787 = v463 + 15;
    v458->timer = v787;
    int * v465 = v458->saved_regs;
    int v466 = v465[11];
    int * v467 = v458->regs;
    v467[11] = v466;
    int * v469 = v458->saved_regs;
    int v470 = v469[12];
    int * v471 = v458->regs;
    v471[12] = v470;
    int * v473 = v458->saved_regs;
    int v474 = v473[13];
    int * v475 = v458->regs;
    v475[13] = v474;
    struct StateT * v497 = v477(v458);
    v780 = v497;
  } else {
    struct StateT * v778 = v499(v458);
    v780 = v778;
  }
  return v780;
}

struct StateT * v117(struct StateT * v118) {
  int * v119 = v118->saved_regs;
  int * v120 = v118->regs;
  int v121 = v120[15];
  v119[15] = v121;
  int v123 = v118->timer;
  int v1065 = v123 + 1;
  v118->timer = v1065;
  int * v125 = v118->regs;
  int v126 = v125[13];
  int * v127 = v118->cache_keys;
  int v128 = v127[0];
  bool v1070 = v128 == ((int)((unsigned int)v126 >> 2));
  int v176;
  if (v1070) {
    int * v129 = v118->cache_vals;
    int v130 = v129[0];
    v176 = v130;
  } else {
    int * v132 = v118->cache_keys;
    int v133 = v132[1];
    bool v1075 = v133 == ((int)((unsigned int)v126 >> 2));
    int v174;
    if (v1075) {
      int * v134 = v118->cache_vals;
      int v135 = v134[1];
      int * v136 = v118->cache_keys;
      int * v137 = v118->cache_keys;
      int v138 = v137[0];
      v136[1] = v138;
      int * v140 = v118->cache_vals;
      int * v141 = v118->cache_vals;
      int v142 = v141[0];
      v140[1] = v142;
      int * v144 = v118->cache_keys;
      int v1084 = (int)((unsigned int)v126 >> 2);
      v144[0] = v1084;
      int * v146 = v118->cache_vals;
      v146[0] = v135;
      int v148 = v118->timer;
      int v1087 = v148 + 1;
      v118->timer = v1087;
      v174 = v135;
    } else {
      int * v151 = v118->mem;
      int v1089 = (int)((unsigned int)v126 >> 2);
      int v152 = v151[v1089];
      int * v153 = v118->mem;
      int * v154 = v118->cache_keys;
      int v155 = v154[1];
      int * v156 = v118->cache_vals;
      int v157 = v156[1];
      v153[v155] = v157;
      int * v159 = v118->cache_keys;
      int * v160 = v118->cache_keys;
      int v161 = v160[0];
      v159[1] = v161;
      int * v163 = v118->cache_vals;
      int * v164 = v118->cache_vals;
      int v165 = v164[0];
      v163[1] = v165;
      int * v167 = v118->cache_keys;
      v167[0] = v1089;
      int * v169 = v118->cache_vals;
      v169[0] = v152;
      int v171 = v118->timer;
      int v1104 = v171 + 100;
      v118->timer = v1104;
      v174 = v152;
    }
    v176 = v174;
  }
  int * v177 = v118->regs;
  v177[15] = v176;
  struct StateT * v1059 = v179(v118);
  return v1059;
}

struct StateT * v37(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[13];
  v39[13] = v41;
  int v43 = v38->timer;
  int v1176 = v43 + 1;
  v38->timer = v1176;
  int * v45 = v38->regs;
  v45[13] = 0;
  struct StateT * v1170 = v47(v38);
  return v1170;
}

struct StateT * v417(struct StateT * v418) {
  int v419 = v418->timer;
  int v843 = v419 + 1;
  v418->timer = v843;
  struct StateT * v841 = v421(v418);
  return v841;
}

struct StateT * v269(struct StateT * v270) {
  int v271 = v270->timer;
  int v283 = v271 + 1;
  v270->timer = v283;
  int * v273 = v270->regs;
  v273[10] = 0;
  struct StateT * v281 = v275(v270);
  return v281;
}

struct StateT * v209(struct StateT * v210) {
  int v211 = v210->timer;
  int v1027 = v211 + 1;
  v210->timer = v1027;
  struct StateT * v1025 = v213(v210);
  return v1025;
}

struct StateT * v565(struct StateT * v566) {
  int * v567 = v566->saved_regs;
  int * v568 = v566->regs;
  int v569 = v568[15];
  v567[15] = v569;
  int v571 = v566->timer;
  int v677 = v571 + 1;
  v566->timer = v677;
  int * v573 = v566->regs;
  int v574 = v573[13];
  int * v575 = v566->cache_keys;
  int v576 = v575[0];
  bool v682 = v576 == ((int)((unsigned int)v574 >> 2));
  int v624;
  if (v682) {
    int * v577 = v566->cache_vals;
    int v578 = v577[0];
    v624 = v578;
  } else {
    int * v580 = v566->cache_keys;
    int v581 = v580[1];
    bool v687 = v581 == ((int)((unsigned int)v574 >> 2));
    int v622;
    if (v687) {
      int * v582 = v566->cache_vals;
      int v583 = v582[1];
      int * v584 = v566->cache_keys;
      int * v585 = v566->cache_keys;
      int v586 = v585[0];
      v584[1] = v586;
      int * v588 = v566->cache_vals;
      int * v589 = v566->cache_vals;
      int v590 = v589[0];
      v588[1] = v590;
      int * v592 = v566->cache_keys;
      int v696 = (int)((unsigned int)v574 >> 2);
      v592[0] = v696;
      int * v594 = v566->cache_vals;
      v594[0] = v583;
      int v596 = v566->timer;
      int v699 = v596 + 1;
      v566->timer = v699;
      v622 = v583;
    } else {
      int * v599 = v566->mem;
      int v701 = (int)((unsigned int)v574 >> 2);
      int v600 = v599[v701];
      int * v601 = v566->mem;
      int * v602 = v566->cache_keys;
      int v603 = v602[1];
      int * v604 = v566->cache_vals;
      int v605 = v604[1];
      v601[v603] = v605;
      int * v607 = v566->cache_keys;
      int * v608 = v566->cache_keys;
      int v609 = v608[0];
      v607[1] = v609;
      int * v611 = v566->cache_vals;
      int * v612 = v566->cache_vals;
      int v613 = v612[0];
      v611[1] = v613;
      int * v615 = v566->cache_keys;
      v615[0] = v701;
      int * v617 = v566->cache_vals;
      v617[0] = v600;
      int v619 = v566->timer;
      int v716 = v619 + 100;
      v566->timer = v716;
      v622 = v600;
    }
    v624 = v622;
  }
  int * v625 = v566->regs;
  v625[15] = v624;
  struct StateT * v671 = v627(v566);
  return v671;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v1208 = v11 + 1;
  v10->timer = v1208;
  int * v13 = v10->regs;
  v13[10] = 1;
  struct StateT * v1206 = v15(v10);
  return v1206;
}

struct StateT * v359(struct StateT * v360) {
  int v361 = v360->timer;
  int v848 = v361 + 1;
  v360->timer = v848;
  int * v363 = v360->regs;
  int v364 = v363[13];
  int * v365 = v360->cache_keys;
  int v366 = v365[0];
  bool v853 = v366 == ((int)((unsigned int)v364 >> 2));
  int v414;
  if (v853) {
    int * v367 = v360->cache_vals;
    int v368 = v367[0];
    v414 = v368;
  } else {
    int * v370 = v360->cache_keys;
    int v371 = v370[1];
    bool v858 = v371 == ((int)((unsigned int)v364 >> 2));
    int v412;
    if (v858) {
      int * v372 = v360->cache_vals;
      int v373 = v372[1];
      int * v374 = v360->cache_keys;
      int * v375 = v360->cache_keys;
      int v376 = v375[0];
      v374[1] = v376;
      int * v378 = v360->cache_vals;
      int * v379 = v360->cache_vals;
      int v380 = v379[0];
      v378[1] = v380;
      int * v382 = v360->cache_keys;
      int v867 = (int)((unsigned int)v364 >> 2);
      v382[0] = v867;
      int * v384 = v360->cache_vals;
      v384[0] = v373;
      int v386 = v360->timer;
      int v870 = v386 + 1;
      v360->timer = v870;
      v412 = v373;
    } else {
      int * v389 = v360->mem;
      int v872 = (int)((unsigned int)v364 >> 2);
      int v390 = v389[v872];
      int * v391 = v360->mem;
      int * v392 = v360->cache_keys;
      int v393 = v392[1];
      int * v394 = v360->cache_vals;
      int v395 = v394[1];
      v391[v393] = v395;
      int * v397 = v360->cache_keys;
      int * v398 = v360->cache_keys;
      int v399 = v398[0];
      v397[1] = v399;
      int * v401 = v360->cache_vals;
      int * v402 = v360->cache_vals;
      int v403 = v402[0];
      v401[1] = v403;
      int * v405 = v360->cache_keys;
      v405[0] = v872;
      int * v407 = v360->cache_vals;
      v407[0] = v390;
      int v409 = v360->timer;
      int v887 = v409 + 100;
      v360->timer = v887;
      v412 = v390;
    }
    v414 = v412;
  }
  int * v415 = v360->regs;
  v415[15] = v414;
  struct StateT * v846 = v417(v360);
  return v846;
}

struct StateT * v445(struct StateT * v446) {
  int * v447 = v446->saved_regs;
  int * v448 = v446->regs;
  int v449 = v448[13];
  v447[13] = v449;
  int v451 = v446->timer;
  int v811 = v451 + 1;
  v446->timer = v811;
  int * v453 = v446->regs;
  int v454 = v453[13];
  int * v455 = v446->regs;
  int v814 = v454 + 4;
  v455[13] = v814;
  struct StateT * v805 = v457(v446);
  return v805;
}

struct StateT * v627(struct StateT * v628) {
  int * v629 = v628->regs;
  int v630 = v629[11];
  bool v656 = !(v630 == 0);
  struct StateT * v652;
  if (v656) {
    struct StateT * v632 = v417(v628);
    v652 = v632;
  } else {
    int v634 = v628->timer;
    int v659 = v634 + 15;
    v628->timer = v659;
    int * v636 = v628->saved_regs;
    int v637 = v636[14];
    int * v638 = v628->regs;
    v638[14] = v637;
    int * v640 = v628->saved_regs;
    int v641 = v640[15];
    int * v642 = v628->regs;
    v642[15] = v641;
    struct StateT * v650 = v644(v628);
    v652 = v650;
  }
  return v652;
}

struct StateT * v29(struct StateT * v30) {
  int v31 = v30->timer;
  int v1183 = v31 + 1;
  v30->timer = v1183;
  int * v33 = v30->regs;
  int v34 = v33[12];
  int * v35 = v30->regs;
  int v1187 = v34 + 16;
  v35[12] = v1187;
  struct StateT * v1181 = v37(v30);
  return v1181;
}

struct StateT * v179(struct StateT * v180) {
  int * v181 = v180->regs;
  int v182 = v181[11];
  bool v1036 = 0 >= v182;
  struct StateT * v1032;
  if (v1036) {
    int v183 = v180->timer;
    int v1037 = v183 + 15;
    v180->timer = v1037;
    int * v185 = v180->saved_regs;
    int v186 = v185[12];
    int * v187 = v180->regs;
    v187[12] = v186;
    int * v189 = v180->saved_regs;
    int v190 = v189[13];
    int * v191 = v180->regs;
    v191[13] = v190;
    int * v193 = v180->saved_regs;
    int v194 = v193[14];
    int * v195 = v180->regs;
    v195[14] = v194;
    int * v197 = v180->saved_regs;
    int v198 = v197[15];
    int * v199 = v180->regs;
    v199[15] = v198;
    struct StateT * v207 = v201(v180);
    v1032 = v207;
  } else {
    struct StateT * v1030 = v209(v180);
    v1032 = v1030;
  }
  return v1032;
}

struct StateT * v477(struct StateT * v478) {
  int v479 = v478->timer;
  int v491 = v479 + 1;
  v478->timer = v491;
  int * v481 = v478->regs;
  v481[10] = 0;
  struct StateT * v489 = v483(v478);
  return v489;
}

struct StateT * v291(struct StateT * v292) {
  int v293 = v292->timer;
  int v959 = v293 + 1;
  v292->timer = v959;
  struct StateT * v957 = v295(v292);
  return v957;
}

struct StateT * v421(struct StateT * v422) {
  int * v423 = v422->saved_regs;
  int * v424 = v422->regs;
  int v425 = v424[11];
  v423[11] = v425;
  int v427 = v422->timer;
  int v835 = v427 + 1;
  v422->timer = v835;
  int * v429 = v422->regs;
  int v430 = v429[11];
  int * v431 = v422->regs;
  int v838 = v430 + -1;
  v431[11] = v838;
  struct StateT * v829 = v433(v422);
  return v829;
}

struct StateT * v301(struct StateT * v302) {
  int v303 = v302->timer;
  int v896 = v303 + 1;
  v302->timer = v896;
  int * v305 = v302->regs;
  int v306 = v305[12];
  int * v307 = v302->cache_keys;
  int v308 = v307[0];
  bool v901 = v308 == ((int)((unsigned int)v306 >> 2));
  int v356;
  if (v901) {
    int * v309 = v302->cache_vals;
    int v310 = v309[0];
    v356 = v310;
  } else {
    int * v312 = v302->cache_keys;
    int v313 = v312[1];
    bool v906 = v313 == ((int)((unsigned int)v306 >> 2));
    int v354;
    if (v906) {
      int * v314 = v302->cache_vals;
      int v315 = v314[1];
      int * v316 = v302->cache_keys;
      int * v317 = v302->cache_keys;
      int v318 = v317[0];
      v316[1] = v318;
      int * v320 = v302->cache_vals;
      int * v321 = v302->cache_vals;
      int v322 = v321[0];
      v320[1] = v322;
      int * v324 = v302->cache_keys;
      int v915 = (int)((unsigned int)v306 >> 2);
      v324[0] = v915;
      int * v326 = v302->cache_vals;
      v326[0] = v315;
      int v328 = v302->timer;
      int v918 = v328 + 1;
      v302->timer = v918;
      v354 = v315;
    } else {
      int * v331 = v302->mem;
      int v920 = (int)((unsigned int)v306 >> 2);
      int v332 = v331[v920];
      int * v333 = v302->mem;
      int * v334 = v302->cache_keys;
      int v335 = v334[1];
      int * v336 = v302->cache_vals;
      int v337 = v336[1];
      v333[v335] = v337;
      int * v339 = v302->cache_keys;
      int * v340 = v302->cache_keys;
      int v341 = v340[0];
      v339[1] = v341;
      int * v343 = v302->cache_vals;
      int * v344 = v302->cache_vals;
      int v345 = v344[0];
      v343[1] = v345;
      int * v347 = v302->cache_keys;
      v347[0] = v920;
      int * v349 = v302->cache_vals;
      v349[0] = v332;
      int v351 = v302->timer;
      int v935 = v351 + 100;
      v302->timer = v935;
      v354 = v332;
    }
    v356 = v354;
  }
  int * v357 = v302->regs;
  v357[14] = v356;
  struct StateT * v894 = v359(v302);
  return v894;
}

struct StateT * v499(struct StateT * v500) {
  int v501 = v500->timer;
  int v775 = v501 + 1;
  v500->timer = v775;
  struct StateT * v773 = v503(v500);
  return v773;
}

struct StateT * v237(struct StateT * v238) {
  int * v239 = v238->saved_regs;
  int * v240 = v238->regs;
  int v241 = v240[13];
  v239[13] = v241;
  int v243 = v238->timer;
  int v995 = v243 + 1;
  v238->timer = v995;
  int * v245 = v238->regs;
  int v246 = v245[13];
  int * v247 = v238->regs;
  int v998 = v246 + 4;
  v247[13] = v998;
  struct StateT * v989 = v249(v238);
  return v989;
}

struct StateT * v503(struct StateT * v504) {
  int * v505 = v504->saved_regs;
  int * v506 = v504->regs;
  int v507 = v506[14];
  v505[14] = v507;
  int v509 = v504->timer;
  int v728 = v509 + 1;
  v504->timer = v728;
  int * v511 = v504->regs;
  int v512 = v511[12];
  int * v513 = v504->cache_keys;
  int v514 = v513[0];
  bool v733 = v514 == ((int)((unsigned int)v512 >> 2));
  int v562;
  if (v733) {
    int * v515 = v504->cache_vals;
    int v516 = v515[0];
    v562 = v516;
  } else {
    int * v518 = v504->cache_keys;
    int v519 = v518[1];
    bool v738 = v519 == ((int)((unsigned int)v512 >> 2));
    int v560;
    if (v738) {
      int * v520 = v504->cache_vals;
      int v521 = v520[1];
      int * v522 = v504->cache_keys;
      int * v523 = v504->cache_keys;
      int v524 = v523[0];
      v522[1] = v524;
      int * v526 = v504->cache_vals;
      int * v527 = v504->cache_vals;
      int v528 = v527[0];
      v526[1] = v528;
      int * v530 = v504->cache_keys;
      int v747 = (int)((unsigned int)v512 >> 2);
      v530[0] = v747;
      int * v532 = v504->cache_vals;
      v532[0] = v521;
      int v534 = v504->timer;
      int v750 = v534 + 1;
      v504->timer = v750;
      v560 = v521;
    } else {
      int * v537 = v504->mem;
      int v752 = (int)((unsigned int)v512 >> 2);
      int v538 = v537[v752];
      int * v539 = v504->mem;
      int * v540 = v504->cache_keys;
      int v541 = v540[1];
      int * v542 = v504->cache_vals;
      int v543 = v542[1];
      v539[v541] = v543;
      int * v545 = v504->cache_keys;
      int * v546 = v504->cache_keys;
      int v547 = v546[0];
      v545[1] = v547;
      int * v549 = v504->cache_vals;
      int * v550 = v504->cache_vals;
      int v551 = v550[0];
      v549[1] = v551;
      int * v553 = v504->cache_keys;
      v553[0] = v752;
      int * v555 = v504->cache_vals;
      v555[0] = v538;
      int v557 = v504->timer;
      int v767 = v557 + 100;
      v504->timer = v767;
      v560 = v538;
    }
    v562 = v560;
  }
  int * v563 = v504->regs;
  v563[14] = v562;
  struct StateT * v722 = v565(v504);
  return v722;
}

struct StateT * v201(struct StateT * v202) {
  int v203 = v202->timer;
  int v206 = v203 + 1;
  v202->timer = v206;
  return v202;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1224 = v1(v0);
  return v1224;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v1216 = v3 + 1;
  v2->timer = v1216;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v1214 = v9(v2);
  return v1214;
}

struct StateT * v249(struct StateT * v250) {
  int * v251 = v250->regs;
  int v252 = v251[14];
  int * v253 = v250->regs;
  int v254 = v253[15];
  bool v970 = !(v252 == v254);
  struct StateT * v964;
  if (v970) {
    int v255 = v250->timer;
    int v971 = v255 + 15;
    v250->timer = v971;
    int * v257 = v250->saved_regs;
    int v258 = v257[11];
    int * v259 = v250->regs;
    v259[11] = v258;
    int * v261 = v250->saved_regs;
    int v262 = v261[12];
    int * v263 = v250->regs;
    v263[12] = v262;
    int * v265 = v250->saved_regs;
    int v266 = v265[13];
    int * v267 = v250->regs;
    v267[13] = v266;
    struct StateT * v289 = v269(v250);
    v964 = v289;
  } else {
    struct StateT * v962 = v291(v250);
    v964 = v962;
  }
  return v964;
}

struct StateT * v644(struct StateT * v645) {
  int v646 = v645->timer;
  int v649 = v646 + 1;
  v645->timer = v649;
  return v645;
}

struct StateT * v47(struct StateT * v48) {
  int v49 = v48->timer;
  int v1163 = v49 + 1;
  v48->timer = v1163;
  int * v51 = v48->regs;
  int v52 = v51[13];
  int * v53 = v48->regs;
  v53[13] = v52;
  struct StateT * v1161 = v55(v48);
  return v1161;
}

struct StateT * v433(struct StateT * v434) {
  int * v435 = v434->saved_regs;
  int * v436 = v434->regs;
  int v437 = v436[12];
  v435[12] = v437;
  int v439 = v434->timer;
  int v823 = v439 + 1;
  v434->timer = v823;
  int * v441 = v434->regs;
  int v442 = v441[12];
  int * v443 = v434->regs;
  int v826 = v442 + 4;
  v443[12] = v826;
  struct StateT * v817 = v445(v434);
  return v817;
}

struct StateT * v225(struct StateT * v226) {
  int * v227 = v226->saved_regs;
  int * v228 = v226->regs;
  int v229 = v228[12];
  v227[12] = v229;
  int v231 = v226->timer;
  int v1007 = v231 + 1;
  v226->timer = v1007;
  int * v233 = v226->regs;
  int v234 = v233[12];
  int * v235 = v226->regs;
  int v1010 = v234 + 4;
  v235[12] = v1010;
  struct StateT * v1001 = v237(v226);
  return v1001;
}

struct StateT * v275(struct StateT * v276) {
  int v277 = v276->timer;
  int v280 = v277 + 1;
  v276->timer = v280;
  return v276;
}

struct StateT * v483(struct StateT * v484) {
  int v485 = v484->timer;
  int v488 = v485 + 1;
  v484->timer = v488;
  return v484;
}

struct StateT * v213(struct StateT * v214) {
  int * v215 = v214->saved_regs;
  int * v216 = v214->regs;
  int v217 = v216[11];
  v215[11] = v217;
  int v219 = v214->timer;
  int v1019 = v219 + 1;
  v214->timer = v1019;
  int * v221 = v214->regs;
  int v222 = v221[11];
  int * v223 = v214->regs;
  int v1022 = v222 + -1;
  v223[11] = v1022;
  struct StateT * v1013 = v225(v214);
  return v1013;
}

struct StateT * v55(struct StateT * v56) {
  int * v57 = v56->saved_regs;
  int * v58 = v56->regs;
  int v59 = v58[14];
  v57[14] = v59;
  int v61 = v56->timer;
  int v1116 = v61 + 1;
  v56->timer = v1116;
  int * v63 = v56->regs;
  int v64 = v63[12];
  int * v65 = v56->cache_keys;
  int v66 = v65[0];
  bool v1121 = v66 == ((int)((unsigned int)v64 >> 2));
  int v114;
  if (v1121) {
    int * v67 = v56->cache_vals;
    int v68 = v67[0];
    v114 = v68;
  } else {
    int * v70 = v56->cache_keys;
    int v71 = v70[1];
    bool v1126 = v71 == ((int)((unsigned int)v64 >> 2));
    int v112;
    if (v1126) {
      int * v72 = v56->cache_vals;
      int v73 = v72[1];
      int * v74 = v56->cache_keys;
      int * v75 = v56->cache_keys;
      int v76 = v75[0];
      v74[1] = v76;
      int * v78 = v56->cache_vals;
      int * v79 = v56->cache_vals;
      int v80 = v79[0];
      v78[1] = v80;
      int * v82 = v56->cache_keys;
      int v1135 = (int)((unsigned int)v64 >> 2);
      v82[0] = v1135;
      int * v84 = v56->cache_vals;
      v84[0] = v73;
      int v86 = v56->timer;
      int v1138 = v86 + 1;
      v56->timer = v1138;
      v112 = v73;
    } else {
      int * v89 = v56->mem;
      int v1140 = (int)((unsigned int)v64 >> 2);
      int v90 = v89[v1140];
      int * v91 = v56->mem;
      int * v92 = v56->cache_keys;
      int v93 = v92[1];
      int * v94 = v56->cache_vals;
      int v95 = v94[1];
      v91[v93] = v95;
      int * v97 = v56->cache_keys;
      int * v98 = v56->cache_keys;
      int v99 = v98[0];
      v97[1] = v99;
      int * v101 = v56->cache_vals;
      int * v102 = v56->cache_vals;
      int v103 = v102[0];
      v101[1] = v103;
      int * v105 = v56->cache_keys;
      v105[0] = v1140;
      int * v107 = v56->cache_vals;
      v107[0] = v90;
      int v109 = v56->timer;
      int v1155 = v109 + 100;
      v56->timer = v1155;
      v112 = v90;
    }
    v114 = v112;
  }
  int * v115 = v56->regs;
  v115[14] = v114;
  struct StateT * v1110 = v117(v56);
  return v1110;
}

struct StateT * v295(struct StateT * v296) {
  int * v297 = v296->regs;
  int v298 = v297[11];
  bool v950 = !(v298 == 0);
  struct StateT * v946;
  if (v950) {
    int v299 = v296->timer;
    int v951 = v299 + 15;
    v296->timer = v951;
    struct StateT * v942 = v301(v296);
    v946 = v942;
  } else {
    struct StateT * v944 = v644(v296);
    v946 = v944;
  }
  return v946;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = bounded(0, 20);
    s2.mem[0 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}