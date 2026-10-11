// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * slot_12(struct StateT * v196);
struct StateT * slot_43(struct StateT * v720);
struct StateT * slot_6(struct StateT * v105);
struct StateT * slot_29(struct StateT * v459);
struct StateT * slot_16(struct StateT * v255);
struct StateT * slot_5(struct StateT * v91);
struct StateT * slot_7(struct StateT * v121);
struct StateT * slot_31(struct StateT * v497);
struct StateT * slot_26(struct StateT * v407);
struct StateT * slot_10(struct StateT * v165);
struct StateT * slot_19(struct StateT * v306);
struct StateT * slot_14(struct StateT * v225);
struct StateT * slot_44(struct StateT * v737);
struct StateT * slot_28(struct StateT * v440);
struct StateT * slot_32(struct StateT * v516);
struct StateT * slot_17(struct StateT * v272);
struct StateT * slot_33(struct StateT * v535);
struct StateT * slot_36(struct StateT * v588);
struct StateT * slot_37(struct StateT * v607);
struct StateT * slot_40(struct StateT * v664);
struct StateT * slot_27(struct StateT * v421);
struct StateT * slot_15(struct StateT * v239);
struct StateT * slot_22(struct StateT * v351);
struct StateT * slot_35(struct StateT * v569);
struct StateT * slot_34(struct StateT * v552);
struct StateT * slot_25(struct StateT * v393);
struct StateT * slot_23(struct StateT * v365);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_21(struct StateT * v337);
struct StateT * slot_3(struct StateT * v59);
struct StateT * slot_45(struct StateT * v754);
struct StateT * slot_1(struct StateT * v21);
struct StateT * slot_13(struct StateT * v212);
struct StateT * slot_38(struct StateT * v626);
struct StateT * slot_24(struct StateT * v379);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v701);
struct StateT * slot_46(struct StateT * v772);
struct StateT * slot_20(struct StateT * v323);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v682);
struct StateT * slot_39(struct StateT * v645);
struct StateT * slot_8(struct StateT * v135);
struct StateT * slot_30(struct StateT * v478);
struct StateT * slot_4(struct StateT * v78);
struct StateT * slot_18(struct StateT * v289);
struct StateT * slot_9(struct StateT * v150);
struct StateT * slot_11(struct StateT * v181);
struct StateT * slot_12(struct StateT * v196) {
  int v197 = v196->timer;
  int v205 = v197 + 1;
  v196->timer = v205;
  int * v199 = v196->regs;
  int v200 = v199[17];
  int v201 = v199[5];
  int v209 = v200 | v201;
  v199[17] = v209;
  struct StateT * v203 = slot_13(v196);
  return v203;
}

struct StateT * slot_43(struct StateT * v720) {
  int v721 = v720->timer;
  int v729 = v721 + 1;
  v720->timer = v729;
  int * v723 = v720->regs;
  int v724 = v723[10];
  int * v725 = v720->mem;
  int v733 = (int)((unsigned int)(v724 + 64) >> 2);
  v725[v733] = 0;
  struct StateT * v727 = slot_44(v720);
  return v727;
}

struct StateT * slot_6(struct StateT * v105) {
  int v106 = v105->timer;
  int v114 = v106 + 1;
  v105->timer = v114;
  int * v108 = v105->regs;
  int v109 = v108[13];
  int v110 = v108[16];
  int v118 = v109 & v110;
  v108[16] = v118;
  struct StateT * v112 = slot_7(v105);
  return v112;
}

struct StateT * slot_29(struct StateT * v459) {
  int v460 = v459->timer;
  int v469 = v460 + 1;
  v459->timer = v469;
  int * v462 = v459->regs;
  int v463 = v462[10];
  int v464 = v462[13];
  int * v465 = v459->mem;
  int v474 = (int)((unsigned int)(v463 + 8) >> 2);
  v465[v474] = v464;
  struct StateT * v467 = slot_30(v459);
  return v467;
}

struct StateT * slot_16(struct StateT * v255) {
  int v256 = v255->timer;
  int v264 = v256 + 1;
  v255->timer = v264;
  int * v258 = v255->regs;
  int v259 = v258[10];
  int * v260 = v255->mem;
  int v268 = (int)((unsigned int)(v259 + 32) >> 2);
  v260[v268] = 0;
  struct StateT * v262 = slot_17(v255);
  return v262;
}

struct StateT * slot_5(struct StateT * v91) {
  int v92 = v91->timer;
  int v99 = v92 + 1;
  v91->timer = v99;
  int * v94 = v91->regs;
  int v95 = v94[16];
  int v102 = v95 + -4;
  v94[16] = v102;
  struct StateT * v97 = slot_6(v91);
  return v97;
}

struct StateT * slot_7(struct StateT * v121) {
  int v122 = v121->timer;
  int v129 = v122 + 1;
  v121->timer = v129;
  int * v124 = v121->regs;
  int v125 = v124[13];
  int v132 = (int)((unsigned int)v125 >> 12);
  v124[13] = v132;
  struct StateT * v127 = slot_8(v121);
  return v127;
}

struct StateT * slot_31(struct StateT * v497) {
  int v498 = v497->timer;
  int v507 = v498 + 1;
  v497->timer = v507;
  int * v500 = v497->regs;
  int v501 = v500[10];
  int v502 = v500[17];
  int * v503 = v497->mem;
  int v512 = (int)((unsigned int)(v501 + 16) >> 2);
  v503[v512] = v502;
  struct StateT * v505 = slot_32(v497);
  return v505;
}

struct StateT * slot_26(struct StateT * v407) {
  int v408 = v407->timer;
  int v415 = v408 + 1;
  v407->timer = v415;
  int * v410 = v407->regs;
  int v411 = v410[17];
  int v418 = v411 & -1009;
  v410[17] = v418;
  struct StateT * v413 = slot_27(v407);
  return v413;
}

struct StateT * slot_10(struct StateT * v165) {
  int v166 = v165->timer;
  int v174 = v166 + 1;
  v165->timer = v174;
  int * v168 = v165->regs;
  int v169 = v168[13];
  int v170 = v168[17];
  int v178 = v169 | v170;
  v168[13] = v178;
  struct StateT * v172 = slot_11(v165);
  return v172;
}

struct StateT * slot_19(struct StateT * v306) {
  int v307 = v306->timer;
  int v315 = v307 + 1;
  v306->timer = v315;
  int * v309 = v306->regs;
  int v310 = v309[10];
  int * v311 = v306->mem;
  int v319 = (int)((unsigned int)(v310 + 44) >> 2);
  v311[v319] = 0;
  struct StateT * v313 = slot_20(v306);
  return v313;
}

struct StateT * slot_14(struct StateT * v225) {
  int v226 = v225->timer;
  int v233 = v226 + 1;
  v225->timer = v233;
  int * v228 = v225->regs;
  int v229 = v228[5];
  int v236 = v229 + -1;
  v228[5] = v236;
  struct StateT * v231 = slot_15(v225);
  return v231;
}

struct StateT * slot_44(struct StateT * v737) {
  int v738 = v737->timer;
  int v746 = v738 + 1;
  v737->timer = v746;
  int * v740 = v737->regs;
  int v741 = v740[10];
  int * v742 = v737->mem;
  int v750 = (int)((unsigned int)(v741 + 68) >> 2);
  v742[v750] = 0;
  struct StateT * v744 = slot_45(v737);
  return v744;
}

struct StateT * slot_28(struct StateT * v440) {
  int v441 = v440->timer;
  int v450 = v441 + 1;
  v440->timer = v450;
  int * v443 = v440->regs;
  int v444 = v443[10];
  int v445 = v443[16];
  int * v446 = v440->mem;
  int v455 = (int)((unsigned int)(v444 + 4) >> 2);
  v446[v455] = v445;
  struct StateT * v448 = slot_29(v440);
  return v448;
}

struct StateT * slot_32(struct StateT * v516) {
  int v517 = v516->timer;
  int v526 = v517 + 1;
  v516->timer = v526;
  int * v519 = v516->regs;
  int v520 = v519[10];
  int v521 = v519[15];
  int * v522 = v516->mem;
  int v531 = (int)((unsigned int)(v520 + 20) >> 2);
  v522[v531] = v521;
  struct StateT * v524 = slot_33(v516);
  return v524;
}

struct StateT * slot_17(struct StateT * v272) {
  int v273 = v272->timer;
  int v281 = v273 + 1;
  v272->timer = v281;
  int * v275 = v272->regs;
  int v276 = v275[10];
  int * v277 = v272->mem;
  int v285 = (int)((unsigned int)(v276 + 36) >> 2);
  v277[v285] = 0;
  struct StateT * v279 = slot_18(v272);
  return v279;
}

struct StateT * slot_33(struct StateT * v535) {
  int v536 = v535->timer;
  int v544 = v536 + 1;
  v535->timer = v544;
  int * v538 = v535->regs;
  int v539 = v538[10];
  int * v540 = v535->mem;
  int v548 = (int)((unsigned int)(v539 + 24) >> 2);
  v540[v548] = 0;
  struct StateT * v542 = slot_34(v535);
  return v542;
}

struct StateT * slot_36(struct StateT * v588) {
  int v589 = v588->timer;
  int v598 = v589 + 1;
  v588->timer = v598;
  int * v591 = v588->regs;
  int v592 = v591[11];
  int * v593 = v588->mem;
  int v602 = (int)((unsigned int)(v592 + 20) >> 2);
  int v594 = v593[v602];
  v591[13] = v594;
  struct StateT * v596 = slot_37(v588);
  return v596;
}

struct StateT * slot_37(struct StateT * v607) {
  int v608 = v607->timer;
  int v617 = v608 + 1;
  v607->timer = v617;
  int * v610 = v607->regs;
  int v611 = v610[10];
  int v612 = v610[12];
  int * v613 = v607->mem;
  int v622 = (int)((unsigned int)(v611 + 48) >> 2);
  v613[v622] = v612;
  struct StateT * v615 = slot_38(v607);
  return v615;
}

struct StateT * slot_40(struct StateT * v664) {
  int v665 = v664->timer;
  int v674 = v665 + 1;
  v664->timer = v674;
  int * v667 = v664->regs;
  int v668 = v667[11];
  int * v669 = v664->mem;
  int v678 = (int)((unsigned int)(v668 + 28) >> 2);
  int v670 = v669[v678];
  v667[11] = v670;
  struct StateT * v672 = slot_41(v664);
  return v672;
}

struct StateT * slot_27(struct StateT * v421) {
  int v422 = v421->timer;
  int v431 = v422 + 1;
  v421->timer = v431;
  int * v424 = v421->regs;
  int v425 = v424[10];
  int v426 = v424[12];
  int * v427 = v421->mem;
  int v436 = (int)((unsigned int)v425 >> 2);
  v427[v436] = v426;
  struct StateT * v429 = slot_28(v421);
  return v429;
}

struct StateT * slot_15(struct StateT * v239) {
  int v240 = v239->timer;
  int v248 = v240 + 1;
  v239->timer = v248;
  int * v242 = v239->regs;
  int v243 = v242[13];
  int v244 = v242[5];
  int v252 = v243 & v244;
  v242[13] = v252;
  struct StateT * v246 = slot_16(v239);
  return v246;
}

struct StateT * slot_22(struct StateT * v351) {
  int v352 = v351->timer;
  int v359 = v352 + 1;
  v351->timer = v359;
  int * v354 = v351->regs;
  int v355 = v354[15];
  int v362 = v355 << 4;
  v354[15] = v362;
  struct StateT * v357 = slot_23(v351);
  return v357;
}

struct StateT * slot_35(struct StateT * v569) {
  int v570 = v569->timer;
  int v579 = v570 + 1;
  v569->timer = v579;
  int * v572 = v569->regs;
  int v573 = v572[11];
  int * v574 = v569->mem;
  int v583 = (int)((unsigned int)(v573 + 16) >> 2);
  int v575 = v574[v583];
  v572[12] = v575;
  struct StateT * v577 = slot_36(v569);
  return v577;
}

struct StateT * slot_34(struct StateT * v552) {
  int v553 = v552->timer;
  int v561 = v553 + 1;
  v552->timer = v561;
  int * v555 = v552->regs;
  int v556 = v555[10];
  int * v557 = v552->mem;
  int v565 = (int)((unsigned int)(v556 + 28) >> 2);
  v557[v565] = 0;
  struct StateT * v559 = slot_35(v552);
  return v559;
}

struct StateT * slot_25(struct StateT * v393) {
  int v394 = v393->timer;
  int v401 = v394 + 1;
  v393->timer = v401;
  int * v396 = v393->regs;
  int v397 = v396[15];
  int v404 = (int)((unsigned int)v397 >> 28);
  v396[15] = v404;
  struct StateT * v399 = slot_26(v393);
  return v399;
}

struct StateT * slot_23(struct StateT * v365) {
  int v366 = v365->timer;
  int v373 = v366 + 1;
  v365->timer = v373;
  int * v368 = v365->regs;
  int v369 = v368[12];
  int v376 = (int)((unsigned int)v369 >> 4);
  v368[12] = v376;
  struct StateT * v371 = slot_24(v365);
  return v371;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v50 = v41 + 1;
  v40->timer = v50;
  int * v43 = v40->regs;
  int v44 = v43[11];
  int * v45 = v40->mem;
  int v54 = (int)((unsigned int)(v44 + 8) >> 2);
  int v46 = v45[v54];
  v43[14] = v46;
  struct StateT * v48 = slot_3(v40);
  return v48;
}

struct StateT * slot_21(struct StateT * v337) {
  int v338 = v337->timer;
  int v345 = v338 + 1;
  v337->timer = v345;
  int * v340 = v337->regs;
  int v341 = v340[14];
  int v348 = v341 << 8;
  v340[14] = v348;
  struct StateT * v343 = slot_22(v337);
  return v343;
}

struct StateT * slot_3(struct StateT * v59) {
  int v60 = v59->timer;
  int v69 = v60 + 1;
  v59->timer = v69;
  int * v62 = v59->regs;
  int v63 = v62[11];
  int * v64 = v59->mem;
  int v73 = (int)((unsigned int)(v63 + 12) >> 2);
  int v65 = v64[v73];
  v62[15] = v65;
  struct StateT * v67 = slot_4(v59);
  return v67;
}

struct StateT * slot_45(struct StateT * v754) {
  int v755 = v754->timer;
  int v764 = v755 + 1;
  v754->timer = v764;
  int * v757 = v754->regs;
  int v758 = v757[10];
  int * v759 = v754->mem;
  int v768 = (int)((unsigned int)(v758 + 88) >> 2);
  int v760 = v759[v768];
  int v769 = (v760 & (~(255 << (((v758 + 88) & 3) << 3)))) | (0 << (((v758 + 88) & 3) << 3));
  v759[v768] = v769;
  struct StateT * v762 = slot_46(v754);
  return v762;
}

struct StateT * slot_1(struct StateT * v21) {
  int v22 = v21->timer;
  int v31 = v22 + 1;
  v21->timer = v31;
  int * v24 = v21->regs;
  int v25 = v24[11];
  int * v26 = v21->mem;
  int v35 = (int)((unsigned int)(v25 + 4) >> 2);
  int v27 = v26[v35];
  v24[13] = v27;
  struct StateT * v29 = slot_2(v21);
  return v29;
}

struct StateT * slot_13(struct StateT * v212) {
  int v213 = v212->timer;
  int v219 = v213 + 1;
  v212->timer = v219;
  int * v215 = v212->regs;
  v215[5] = -4128768;
  struct StateT * v217 = slot_14(v212);
  return v217;
}

struct StateT * slot_38(struct StateT * v626) {
  int v627 = v626->timer;
  int v636 = v627 + 1;
  v626->timer = v636;
  int * v629 = v626->regs;
  int v630 = v629[10];
  int v631 = v629[13];
  int * v632 = v626->mem;
  int v641 = (int)((unsigned int)(v630 + 52) >> 2);
  v632[v641] = v631;
  struct StateT * v634 = slot_39(v626);
  return v634;
}

struct StateT * slot_24(struct StateT * v379) {
  int v380 = v379->timer;
  int v387 = v380 + 1;
  v379->timer = v387;
  int * v382 = v379->regs;
  int v383 = v382[14];
  int v390 = (int)((unsigned int)v383 >> 20);
  v382[14] = v390;
  struct StateT * v385 = slot_25(v379);
  return v385;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[11];
  int * v7 = v2->mem;
  int v16 = (int)((unsigned int)v6 >> 2);
  int v8 = v7[v16];
  v5[12] = v8;
  struct StateT * v10 = slot_1(v2);
  return v10;
}

struct StateT * slot_42(struct StateT * v701) {
  int v702 = v701->timer;
  int v711 = v702 + 1;
  v701->timer = v711;
  int * v704 = v701->regs;
  int v705 = v704[10];
  int v706 = v704[11];
  int * v707 = v701->mem;
  int v716 = (int)((unsigned int)(v705 + 60) >> 2);
  v707[v716] = v706;
  struct StateT * v709 = slot_43(v701);
  return v709;
}

struct StateT * slot_46(struct StateT * v772) {
  int v773 = v772->timer;
  int v776 = v773 + 1;
  v772->timer = v776;
  return v772;
}

struct StateT * slot_20(struct StateT * v323) {
  int v324 = v323->timer;
  int v331 = v324 + 1;
  v323->timer = v331;
  int * v326 = v323->regs;
  int v327 = v326[12];
  int v334 = v327 << 4;
  v326[12] = v334;
  struct StateT * v329 = slot_21(v323);
  return v329;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v682) {
  int v683 = v682->timer;
  int v692 = v683 + 1;
  v682->timer = v692;
  int * v685 = v682->regs;
  int v686 = v685[10];
  int v687 = v685[12];
  int * v688 = v682->mem;
  int v697 = (int)((unsigned int)(v686 + 56) >> 2);
  v688[v697] = v687;
  struct StateT * v690 = slot_42(v682);
  return v690;
}

struct StateT * slot_39(struct StateT * v645) {
  int v646 = v645->timer;
  int v655 = v646 + 1;
  v645->timer = v655;
  int * v648 = v645->regs;
  int v649 = v648[11];
  int * v650 = v645->mem;
  int v659 = (int)((unsigned int)(v649 + 24) >> 2);
  int v651 = v650[v659];
  v648[12] = v651;
  struct StateT * v653 = slot_40(v645);
  return v653;
}

struct StateT * slot_8(struct StateT * v135) {
  int v136 = v135->timer;
  int v143 = v136 + 1;
  v135->timer = v143;
  int * v138 = v135->regs;
  int v139 = v138[14];
  int v147 = v139 << 20;
  v138[17] = v147;
  struct StateT * v141 = slot_9(v135);
  return v141;
}

struct StateT * slot_30(struct StateT * v478) {
  int v479 = v478->timer;
  int v488 = v479 + 1;
  v478->timer = v488;
  int * v481 = v478->regs;
  int v482 = v481[10];
  int v483 = v481[14];
  int * v484 = v478->mem;
  int v493 = (int)((unsigned int)(v482 + 12) >> 2);
  v484[v493] = v483;
  struct StateT * v486 = slot_31(v478);
  return v486;
}

struct StateT * slot_4(struct StateT * v78) {
  int v79 = v78->timer;
  int v85 = v79 + 1;
  v78->timer = v85;
  int * v81 = v78->regs;
  v81[16] = 4096;
  struct StateT * v83 = slot_5(v78);
  return v83;
}

struct StateT * slot_18(struct StateT * v289) {
  int v290 = v289->timer;
  int v298 = v290 + 1;
  v289->timer = v298;
  int * v292 = v289->regs;
  int v293 = v292[10];
  int * v294 = v289->mem;
  int v302 = (int)((unsigned int)(v293 + 40) >> 2);
  v294[v302] = 0;
  struct StateT * v296 = slot_19(v289);
  return v296;
}

struct StateT * slot_9(struct StateT * v150) {
  int v151 = v150->timer;
  int v158 = v151 + 1;
  v150->timer = v158;
  int * v153 = v150->regs;
  int v154 = v153[15];
  int v162 = v154 << 8;
  v153[5] = v162;
  struct StateT * v156 = slot_10(v150);
  return v156;
}

struct StateT * slot_11(struct StateT * v181) {
  int v182 = v181->timer;
  int v189 = v182 + 1;
  v181->timer = v189;
  int * v184 = v181->regs;
  int v185 = v184[14];
  int v193 = (int)((unsigned int)v185 >> 24);
  v184[17] = v193;
  struct StateT * v187 = slot_12(v181);
  return v187;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, 24 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 8 words read by the callee: the address is public
  s1.regs[11] = 96;
  s2.regs[11] = 96;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[24 + i] = secret(0, 20);
    s2.mem[24 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}