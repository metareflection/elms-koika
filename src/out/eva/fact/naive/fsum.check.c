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

struct StateT * slot_12(struct StateT * v227);
struct StateT * slot_43(struct StateT * v807);
struct StateT * slot_6(struct StateT * v116);
struct StateT * slot_47(struct StateT * v882);
struct StateT * slot_29(struct StateT * v547);
struct StateT * slot_16(struct StateT * v297);
struct StateT * slot_5(struct StateT * v97);
struct StateT * slot_7(struct StateT * v132);
struct StateT * slot_31(struct StateT * v582);
struct StateT * slot_26(struct StateT * v490);
struct StateT * slot_10(struct StateT * v189);
struct StateT * slot_19(struct StateT * v357);
struct StateT * slot_14(struct StateT * v265);
struct StateT * slot_44(struct StateT * v825);
struct StateT * slot_28(struct StateT * v522);
struct StateT * slot_32(struct StateT * v601);
struct StateT * slot_17(struct StateT * v322);
struct StateT * slot_49(struct StateT * v917);
struct StateT * slot_33(struct StateT * v620);
struct StateT * slot_50(struct StateT * v936);
struct StateT * slot_36(struct StateT * v671);
struct StateT * slot_37(struct StateT * v696);
struct StateT * slot_40(struct StateT * v750);
struct StateT * slot_27(struct StateT * v506);
struct StateT * slot_15(struct StateT * v281);
struct StateT * slot_48(struct StateT * v898);
struct StateT * slot_22(struct StateT * v414);
struct StateT * slot_35(struct StateT * v655);
struct StateT * slot_34(struct StateT * v639);
struct StateT * slot_25(struct StateT * v471);
struct StateT * slot_23(struct StateT * v433);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_21(struct StateT * v395);
struct StateT * slot_3(struct StateT * v59);
struct StateT * slot_45(struct StateT * v841);
struct StateT * slot_1(struct StateT * v21);
struct StateT * slot_13(struct StateT * v246);
struct StateT * slot_38(struct StateT * v712);
struct StateT * slot_24(struct StateT * v452);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v788);
struct StateT * slot_46(struct StateT * v857);
struct StateT * slot_20(struct StateT * v376);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v769);
struct StateT * slot_39(struct StateT * v731);
struct StateT * slot_8(struct StateT * v148);
struct StateT * slot_30(struct StateT * v563);
struct StateT * slot_4(struct StateT * v78);
struct StateT * slot_18(struct StateT * v338);
struct StateT * slot_9(struct StateT * v173);
struct StateT * slot_11(struct StateT * v208);
struct StateT * slot_12(struct StateT * v227) {
  int v228 = v227->timer;
  int v237 = v228 + 1;
  v227->timer = v237;
  int * v230 = v227->regs;
  int v231 = v230[11];
  int * v232 = v227->mem;
  int v241 = (int)((unsigned int)(v231 + 8) >> 2);
  int v233 = v232[v241];
  v230[12] = v233;
  struct StateT * v235 = slot_13(v227);
  return v235;
}

struct StateT * slot_43(struct StateT * v807) {
  int v808 = v807->timer;
  int v817 = v808 + 1;
  v807->timer = v817;
  int * v810 = v807->regs;
  int v811 = v810[11];
  int * v812 = v807->mem;
  int v821 = (int)((unsigned int)(v811 + 32) >> 2);
  int v813 = v812[v821];
  v810[11] = v813;
  struct StateT * v815 = slot_44(v807);
  return v815;
}

struct StateT * slot_6(struct StateT * v116) {
  int v117 = v116->timer;
  int v125 = v117 + 1;
  v116->timer = v125;
  int * v119 = v116->regs;
  int v120 = v119[14];
  int v121 = v119[13];
  int v129 = v120 + v121;
  v119[13] = v129;
  struct StateT * v123 = slot_7(v116);
  return v123;
}

struct StateT * slot_47(struct StateT * v882) {
  int v883 = v882->timer;
  int v891 = v883 + 1;
  v882->timer = v891;
  int * v885 = v882->regs;
  int v886 = v885[12];
  int v887 = v885[13];
  int v895 = v886 + v887;
  v885[12] = v895;
  struct StateT * v889 = slot_48(v882);
  return v889;
}

struct StateT * slot_29(struct StateT * v547) {
  int v548 = v547->timer;
  int v556 = v548 + 1;
  v547->timer = v556;
  int * v550 = v547->regs;
  int v551 = v550[13];
  int v552 = v550[14];
  int v560 = v551 + v552;
  v550[13] = v560;
  struct StateT * v554 = slot_30(v547);
  return v554;
}

struct StateT * slot_16(struct StateT * v297) {
  int v298 = v297->timer;
  int v310 = v298 + 1;
  v297->timer = v310;
  int * v300 = v297->regs;
  int v301 = v300[12];
  int v302 = v300[16];
  bool v314 = (v301 ^ -2147483648) < (v302 ^ -2147483648);
  int v305;
  if (v314) {
    v305 = 1;
  } else {
    v305 = 0;
  }
  int * v306 = v297->regs;
  v306[14] = v305;
  struct StateT * v308 = slot_17(v297);
  return v308;
}

struct StateT * slot_5(struct StateT * v97) {
  int v98 = v97->timer;
  int v107 = v98 + 1;
  v97->timer = v107;
  int * v100 = v97->regs;
  int v101 = v100[10];
  int * v102 = v97->mem;
  int v111 = (int)((unsigned int)(v101 + 12) >> 2);
  int v103 = v102[v111];
  v100[17] = v103;
  struct StateT * v105 = slot_6(v97);
  return v105;
}

struct StateT * slot_7(struct StateT * v132) {
  int v133 = v132->timer;
  int v141 = v133 + 1;
  v132->timer = v141;
  int * v135 = v132->regs;
  int v136 = v135[15];
  int v137 = v135[12];
  int v145 = v136 + v137;
  v135[12] = v145;
  struct StateT * v139 = slot_8(v132);
  return v139;
}

struct StateT * slot_31(struct StateT * v582) {
  int v583 = v582->timer;
  int v592 = v583 + 1;
  v582->timer = v592;
  int * v585 = v582->regs;
  int v586 = v585[10];
  int v587 = v585[13];
  int * v588 = v582->mem;
  int v597 = (int)((unsigned int)(v586 + 20) >> 2);
  v588[v597] = v587;
  struct StateT * v590 = slot_32(v582);
  return v590;
}

struct StateT * slot_26(struct StateT * v490) {
  int v491 = v490->timer;
  int v499 = v491 + 1;
  v490->timer = v499;
  int * v493 = v490->regs;
  int v494 = v493[14];
  int v495 = v493[13];
  int v503 = v494 + v495;
  v493[13] = v503;
  struct StateT * v497 = slot_27(v490);
  return v497;
}

struct StateT * slot_10(struct StateT * v189) {
  int v190 = v189->timer;
  int v199 = v190 + 1;
  v189->timer = v199;
  int * v192 = v189->regs;
  int v193 = v192[10];
  int v194 = v192[12];
  int * v195 = v189->mem;
  int v204 = (int)((unsigned int)v193 >> 2);
  v195[v204] = v194;
  struct StateT * v197 = slot_11(v189);
  return v197;
}

struct StateT * slot_19(struct StateT * v357) {
  int v358 = v357->timer;
  int v367 = v358 + 1;
  v357->timer = v367;
  int * v360 = v357->regs;
  int v361 = v360[10];
  int v362 = v360[13];
  int * v363 = v357->mem;
  int v372 = (int)((unsigned int)(v361 + 12) >> 2);
  v363[v372] = v362;
  struct StateT * v365 = slot_20(v357);
  return v365;
}

struct StateT * slot_14(struct StateT * v265) {
  int v266 = v265->timer;
  int v274 = v266 + 1;
  v265->timer = v274;
  int * v268 = v265->regs;
  int v269 = v268[16];
  int v270 = v268[12];
  int v278 = v269 + v270;
  v268[12] = v278;
  struct StateT * v272 = slot_15(v265);
  return v272;
}

struct StateT * slot_44(struct StateT * v825) {
  int v826 = v825->timer;
  int v834 = v826 + 1;
  v825->timer = v834;
  int * v828 = v825->regs;
  int v829 = v828[15];
  int v830 = v828[12];
  int v838 = v829 + v830;
  v828[12] = v838;
  struct StateT * v832 = slot_45(v825);
  return v832;
}

struct StateT * slot_28(struct StateT * v522) {
  int v523 = v522->timer;
  int v535 = v523 + 1;
  v522->timer = v535;
  int * v525 = v522->regs;
  int v526 = v525[12];
  int v527 = v525[15];
  bool v539 = (v526 ^ -2147483648) < (v527 ^ -2147483648);
  int v530;
  if (v539) {
    v530 = 1;
  } else {
    v530 = 0;
  }
  int * v531 = v522->regs;
  v531[14] = v530;
  struct StateT * v533 = slot_29(v522);
  return v533;
}

struct StateT * slot_32(struct StateT * v601) {
  int v602 = v601->timer;
  int v611 = v602 + 1;
  v601->timer = v611;
  int * v604 = v601->regs;
  int v605 = v604[11];
  int * v606 = v601->mem;
  int v615 = (int)((unsigned int)(v605 + 24) >> 2);
  int v607 = v606[v615];
  v604[12] = v607;
  struct StateT * v609 = slot_33(v601);
  return v609;
}

struct StateT * slot_17(struct StateT * v322) {
  int v323 = v322->timer;
  int v331 = v323 + 1;
  v322->timer = v331;
  int * v325 = v322->regs;
  int v326 = v325[13];
  int v327 = v325[14];
  int v335 = v326 + v327;
  v325[13] = v335;
  struct StateT * v329 = slot_18(v322);
  return v329;
}

struct StateT * slot_49(struct StateT * v917) {
  int v918 = v917->timer;
  int v927 = v918 + 1;
  v917->timer = v927;
  int * v920 = v917->regs;
  int v921 = v920[10];
  int v922 = v920[12];
  int * v923 = v917->mem;
  int v932 = (int)((unsigned int)(v921 + 36) >> 2);
  v923[v932] = v922;
  struct StateT * v925 = slot_50(v917);
  return v925;
}

struct StateT * slot_33(struct StateT * v620) {
  int v621 = v620->timer;
  int v630 = v621 + 1;
  v620->timer = v630;
  int * v623 = v620->regs;
  int v624 = v623[11];
  int * v625 = v620->mem;
  int v634 = (int)((unsigned int)(v624 + 28) >> 2);
  int v626 = v625[v634];
  v623[13] = v626;
  struct StateT * v628 = slot_34(v620);
  return v628;
}

struct StateT * slot_50(struct StateT * v936) {
  int v937 = v936->timer;
  int v940 = v937 + 1;
  v936->timer = v940;
  return v936;
}

struct StateT * slot_36(struct StateT * v671) {
  int v672 = v671->timer;
  int v684 = v672 + 1;
  v671->timer = v684;
  int * v674 = v671->regs;
  int v675 = v674[12];
  int v676 = v674[16];
  bool v688 = (v675 ^ -2147483648) < (v676 ^ -2147483648);
  int v679;
  if (v688) {
    v679 = 1;
  } else {
    v679 = 0;
  }
  int * v680 = v671->regs;
  v680[14] = v679;
  struct StateT * v682 = slot_37(v671);
  return v682;
}

struct StateT * slot_37(struct StateT * v696) {
  int v697 = v696->timer;
  int v705 = v697 + 1;
  v696->timer = v705;
  int * v699 = v696->regs;
  int v700 = v699[13];
  int v701 = v699[14];
  int v709 = v700 + v701;
  v699[13] = v709;
  struct StateT * v703 = slot_38(v696);
  return v703;
}

struct StateT * slot_40(struct StateT * v750) {
  int v751 = v750->timer;
  int v760 = v751 + 1;
  v750->timer = v760;
  int * v753 = v750->regs;
  int v754 = v753[10];
  int v755 = v753[12];
  int * v756 = v750->mem;
  int v765 = (int)((unsigned int)(v754 + 24) >> 2);
  v756[v765] = v755;
  struct StateT * v758 = slot_41(v750);
  return v758;
}

struct StateT * slot_27(struct StateT * v506) {
  int v507 = v506->timer;
  int v515 = v507 + 1;
  v506->timer = v515;
  int * v509 = v506->regs;
  int v510 = v509[15];
  int v511 = v509[12];
  int v519 = v510 + v511;
  v509[12] = v519;
  struct StateT * v513 = slot_28(v506);
  return v513;
}

struct StateT * slot_15(struct StateT * v281) {
  int v282 = v281->timer;
  int v290 = v282 + 1;
  v281->timer = v290;
  int * v284 = v281->regs;
  int v285 = v284[17];
  int v286 = v284[13];
  int v294 = v285 + v286;
  v284[13] = v294;
  struct StateT * v288 = slot_16(v281);
  return v288;
}

struct StateT * slot_48(struct StateT * v898) {
  int v899 = v898->timer;
  int v908 = v899 + 1;
  v898->timer = v908;
  int * v901 = v898->regs;
  int v902 = v901[10];
  int v903 = v901[11];
  int * v904 = v898->mem;
  int v913 = (int)((unsigned int)(v902 + 32) >> 2);
  v904[v913] = v903;
  struct StateT * v906 = slot_49(v898);
  return v906;
}

struct StateT * slot_22(struct StateT * v414) {
  int v415 = v414->timer;
  int v424 = v415 + 1;
  v414->timer = v424;
  int * v417 = v414->regs;
  int v418 = v417[10];
  int * v419 = v414->mem;
  int v428 = (int)((unsigned int)(v418 + 20) >> 2);
  int v420 = v419[v428];
  v417[14] = v420;
  struct StateT * v422 = slot_23(v414);
  return v422;
}

struct StateT * slot_35(struct StateT * v655) {
  int v656 = v655->timer;
  int v664 = v656 + 1;
  v655->timer = v664;
  int * v658 = v655->regs;
  int v659 = v658[17];
  int v660 = v658[13];
  int v668 = v659 + v660;
  v658[13] = v668;
  struct StateT * v662 = slot_36(v655);
  return v662;
}

struct StateT * slot_34(struct StateT * v639) {
  int v640 = v639->timer;
  int v648 = v640 + 1;
  v639->timer = v648;
  int * v642 = v639->regs;
  int v643 = v642[16];
  int v644 = v642[12];
  int v652 = v643 + v644;
  v642[12] = v652;
  struct StateT * v646 = slot_35(v639);
  return v646;
}

struct StateT * slot_25(struct StateT * v471) {
  int v472 = v471->timer;
  int v481 = v472 + 1;
  v471->timer = v481;
  int * v474 = v471->regs;
  int v475 = v474[10];
  int * v476 = v471->mem;
  int v485 = (int)((unsigned int)(v475 + 28) >> 2);
  int v477 = v476[v485];
  v474[17] = v477;
  struct StateT * v479 = slot_26(v471);
  return v479;
}

struct StateT * slot_23(struct StateT * v433) {
  int v434 = v433->timer;
  int v443 = v434 + 1;
  v433->timer = v443;
  int * v436 = v433->regs;
  int v437 = v436[10];
  int * v438 = v433->mem;
  int v447 = (int)((unsigned int)(v437 + 16) >> 2);
  int v439 = v438[v447];
  v436[15] = v439;
  struct StateT * v441 = slot_24(v433);
  return v441;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v50 = v41 + 1;
  v40->timer = v50;
  int * v43 = v40->regs;
  int v44 = v43[10];
  int * v45 = v40->mem;
  int v54 = (int)((unsigned int)(v44 + 4) >> 2);
  int v46 = v45[v54];
  v43[14] = v46;
  struct StateT * v48 = slot_3(v40);
  return v48;
}

struct StateT * slot_21(struct StateT * v395) {
  int v396 = v395->timer;
  int v405 = v396 + 1;
  v395->timer = v405;
  int * v398 = v395->regs;
  int v399 = v398[11];
  int * v400 = v395->mem;
  int v409 = (int)((unsigned int)(v399 + 20) >> 2);
  int v401 = v400[v409];
  v398[13] = v401;
  struct StateT * v403 = slot_22(v395);
  return v403;
}

struct StateT * slot_3(struct StateT * v59) {
  int v60 = v59->timer;
  int v69 = v60 + 1;
  v59->timer = v69;
  int * v62 = v59->regs;
  int v63 = v62[10];
  int * v64 = v59->mem;
  int v73 = (int)((unsigned int)v63 >> 2);
  int v65 = v64[v73];
  v62[15] = v65;
  struct StateT * v67 = slot_4(v59);
  return v67;
}

struct StateT * slot_45(struct StateT * v841) {
  int v842 = v841->timer;
  int v850 = v842 + 1;
  v841->timer = v850;
  int * v844 = v841->regs;
  int v845 = v844[14];
  int v846 = v844[11];
  int v854 = v845 + v846;
  v844[11] = v854;
  struct StateT * v848 = slot_46(v841);
  return v848;
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

struct StateT * slot_13(struct StateT * v246) {
  int v247 = v246->timer;
  int v256 = v247 + 1;
  v246->timer = v256;
  int * v249 = v246->regs;
  int v250 = v249[11];
  int * v251 = v246->mem;
  int v260 = (int)((unsigned int)(v250 + 12) >> 2);
  int v252 = v251[v260];
  v249[13] = v252;
  struct StateT * v254 = slot_14(v246);
  return v254;
}

struct StateT * slot_38(struct StateT * v712) {
  int v713 = v712->timer;
  int v722 = v713 + 1;
  v712->timer = v722;
  int * v715 = v712->regs;
  int v716 = v715[10];
  int * v717 = v712->mem;
  int v726 = (int)((unsigned int)(v716 + 32) >> 2);
  int v718 = v717[v726];
  v715[14] = v718;
  struct StateT * v720 = slot_39(v712);
  return v720;
}

struct StateT * slot_24(struct StateT * v452) {
  int v453 = v452->timer;
  int v462 = v453 + 1;
  v452->timer = v462;
  int * v455 = v452->regs;
  int v456 = v455[10];
  int * v457 = v452->mem;
  int v466 = (int)((unsigned int)(v456 + 24) >> 2);
  int v458 = v457[v466];
  v455[16] = v458;
  struct StateT * v460 = slot_25(v452);
  return v460;
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

struct StateT * slot_42(struct StateT * v788) {
  int v789 = v788->timer;
  int v798 = v789 + 1;
  v788->timer = v798;
  int * v791 = v788->regs;
  int v792 = v791[11];
  int * v793 = v788->mem;
  int v802 = (int)((unsigned int)(v792 + 36) >> 2);
  int v794 = v793[v802];
  v791[12] = v794;
  struct StateT * v796 = slot_43(v788);
  return v796;
}

struct StateT * slot_46(struct StateT * v857) {
  int v858 = v857->timer;
  int v870 = v858 + 1;
  v857->timer = v870;
  int * v860 = v857->regs;
  int v861 = v860[11];
  int v862 = v860[14];
  bool v874 = (v861 ^ -2147483648) < (v862 ^ -2147483648);
  int v865;
  if (v874) {
    v865 = 1;
  } else {
    v865 = 0;
  }
  int * v866 = v857->regs;
  v866[13] = v865;
  struct StateT * v868 = slot_47(v857);
  return v868;
}

struct StateT * slot_20(struct StateT * v376) {
  int v377 = v376->timer;
  int v386 = v377 + 1;
  v376->timer = v386;
  int * v379 = v376->regs;
  int v380 = v379[11];
  int * v381 = v376->mem;
  int v390 = (int)((unsigned int)(v380 + 16) >> 2);
  int v382 = v381[v390];
  v379[12] = v382;
  struct StateT * v384 = slot_21(v376);
  return v384;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v769) {
  int v770 = v769->timer;
  int v779 = v770 + 1;
  v769->timer = v779;
  int * v772 = v769->regs;
  int v773 = v772[10];
  int v774 = v772[13];
  int * v775 = v769->mem;
  int v784 = (int)((unsigned int)(v773 + 28) >> 2);
  v775[v784] = v774;
  struct StateT * v777 = slot_42(v769);
  return v777;
}

struct StateT * slot_39(struct StateT * v731) {
  int v732 = v731->timer;
  int v741 = v732 + 1;
  v731->timer = v741;
  int * v734 = v731->regs;
  int v735 = v734[10];
  int * v736 = v731->mem;
  int v745 = (int)((unsigned int)(v735 + 36) >> 2);
  int v737 = v736[v745];
  v734[15] = v737;
  struct StateT * v739 = slot_40(v731);
  return v739;
}

struct StateT * slot_8(struct StateT * v148) {
  int v149 = v148->timer;
  int v161 = v149 + 1;
  v148->timer = v161;
  int * v151 = v148->regs;
  int v152 = v151[12];
  int v153 = v151[15];
  bool v165 = (v152 ^ -2147483648) < (v153 ^ -2147483648);
  int v156;
  if (v165) {
    v156 = 1;
  } else {
    v156 = 0;
  }
  int * v157 = v148->regs;
  v157[14] = v156;
  struct StateT * v159 = slot_9(v148);
  return v159;
}

struct StateT * slot_30(struct StateT * v563) {
  int v564 = v563->timer;
  int v573 = v564 + 1;
  v563->timer = v573;
  int * v566 = v563->regs;
  int v567 = v566[10];
  int v568 = v566[12];
  int * v569 = v563->mem;
  int v578 = (int)((unsigned int)(v567 + 16) >> 2);
  v569[v578] = v568;
  struct StateT * v571 = slot_31(v563);
  return v571;
}

struct StateT * slot_4(struct StateT * v78) {
  int v79 = v78->timer;
  int v88 = v79 + 1;
  v78->timer = v88;
  int * v81 = v78->regs;
  int v82 = v81[10];
  int * v83 = v78->mem;
  int v92 = (int)((unsigned int)(v82 + 8) >> 2);
  int v84 = v83[v92];
  v81[16] = v84;
  struct StateT * v86 = slot_5(v78);
  return v86;
}

struct StateT * slot_18(struct StateT * v338) {
  int v339 = v338->timer;
  int v348 = v339 + 1;
  v338->timer = v348;
  int * v341 = v338->regs;
  int v342 = v341[10];
  int v343 = v341[12];
  int * v344 = v338->mem;
  int v353 = (int)((unsigned int)(v342 + 8) >> 2);
  v344[v353] = v343;
  struct StateT * v346 = slot_19(v338);
  return v346;
}

struct StateT * slot_9(struct StateT * v173) {
  int v174 = v173->timer;
  int v182 = v174 + 1;
  v173->timer = v182;
  int * v176 = v173->regs;
  int v177 = v176[13];
  int v178 = v176[14];
  int v186 = v177 + v178;
  v176[13] = v186;
  struct StateT * v180 = slot_10(v173);
  return v180;
}

struct StateT * slot_11(struct StateT * v208) {
  int v209 = v208->timer;
  int v218 = v209 + 1;
  v208->timer = v218;
  int * v211 = v208->regs;
  int v212 = v211[10];
  int v213 = v211[13];
  int * v214 = v208->mem;
  int v223 = (int)((unsigned int)(v212 + 4) >> 2);
  v214[v223] = v213;
  struct StateT * v216 = slot_12(v208);
  return v216;
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
  
  // a10, 10 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}