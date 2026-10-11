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

struct StateT * slot_12(struct StateT * v182);
struct StateT * slot_43(struct StateT * v715);
struct StateT * slot_6(struct StateT * v92);
struct StateT * slot_47(struct StateT * v784);
struct StateT * slot_29(struct StateT * v461);
struct StateT * slot_55(struct StateT * v915);
struct StateT * slot_16(struct StateT * v246);
struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_7(struct StateT * v105);
struct StateT * slot_31(struct StateT * v499);
struct StateT * slot_54(struct StateT * v901);
struct StateT * slot_26(struct StateT * v410);
struct StateT * slot_10(struct StateT * v156);
struct StateT * slot_19(struct StateT * v297);
struct StateT * slot_58(struct StateT * v962);
struct StateT * slot_14(struct StateT * v220);
struct StateT * slot_53(struct StateT * v886);
struct StateT * slot_44(struct StateT * v734);
struct StateT * slot_28(struct StateT * v448);
struct StateT * slot_32(struct StateT * v518);
struct StateT * slot_17(struct StateT * v259);
struct StateT * slot_49(struct StateT * v822);
struct StateT * slot_33(struct StateT * v537);
struct StateT * slot_50(struct StateT * v841);
struct StateT * slot_36(struct StateT * v588);
struct StateT * slot_37(struct StateT * v607);
struct StateT * slot_57(struct StateT * v943);
struct StateT * slot_59(struct StateT * v981);
struct StateT * slot_40(struct StateT * v664);
struct StateT * slot_27(struct StateT * v429);
struct StateT * slot_15(struct StateT * v233);
struct StateT * slot_62(struct StateT * v1038);
struct StateT * slot_48(struct StateT * v803);
struct StateT * slot_22(struct StateT * v336);
struct StateT * slot_35(struct StateT * v575);
struct StateT * slot_56(struct StateT * v929);
struct StateT * slot_34(struct StateT * v556);
struct StateT * slot_51(struct StateT * v854);
struct StateT * slot_52(struct StateT * v873);
struct StateT * slot_25(struct StateT * v391);
struct StateT * slot_23(struct StateT * v355);
struct StateT * slot_2(struct StateT * v35);
struct StateT * slot_21(struct StateT * v323);
struct StateT * slot_3(struct StateT * v48);
struct StateT * slot_45(struct StateT * v747);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_13(struct StateT * v201);
struct StateT * slot_38(struct StateT * v626);
struct StateT * slot_63(struct StateT * v1052);
struct StateT * slot_24(struct StateT * v374);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v702);
struct StateT * slot_46(struct StateT * v765);
struct StateT * slot_20(struct StateT * v310);
struct StateT * slot_61(struct StateT * v1019);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v683);
struct StateT * slot_39(struct StateT * v645);
struct StateT * slot_8(struct StateT * v124);
struct StateT * slot_30(struct StateT * v480);
struct StateT * slot_60(struct StateT * v1000);
struct StateT * slot_4(struct StateT * v67);
struct StateT * slot_18(struct StateT * v278);
struct StateT * slot_9(struct StateT * v143);
struct StateT * slot_11(struct StateT * v169);
struct StateT * slot_12(struct StateT * v182) {
  int v183 = v182->timer;
  int v192 = v183 + 1;
  v182->timer = v192;
  int * v185 = v182->regs;
  int v186 = v185[10];
  int v187 = v185[13];
  int * v188 = v182->mem;
  int v197 = (int)((unsigned int)(v186 + 40) >> 2);
  v188[v197] = v187;
  struct StateT * v190 = slot_13(v182);
  return v190;
}

struct StateT * slot_43(struct StateT * v715) {
  int v716 = v715->timer;
  int v725 = v716 + 1;
  v715->timer = v725;
  int * v718 = v715->regs;
  int v719 = v718[10];
  int v720 = v718[13];
  int * v721 = v715->mem;
  int v730 = (int)((unsigned int)(v719 + 36) >> 2);
  v721[v730] = v720;
  struct StateT * v723 = slot_44(v715);
  return v723;
}

struct StateT * slot_6(struct StateT * v92) {
  int v93 = v92->timer;
  int v99 = v93 + 1;
  v92->timer = v99;
  int * v95 = v92->regs;
  v95[16] = 12;
  struct StateT * v97 = slot_7(v92);
  return v97;
}

struct StateT * slot_47(struct StateT * v784) {
  int v785 = v784->timer;
  int v794 = v785 + 1;
  v784->timer = v794;
  int * v787 = v784->regs;
  int v788 = v787[2];
  int v789 = v787[8];
  int * v790 = v784->mem;
  int v799 = (int)((unsigned int)(v788 + 64) >> 2);
  v790[v799] = v789;
  struct StateT * v792 = slot_48(v784);
  return v792;
}

struct StateT * slot_29(struct StateT * v461) {
  int v462 = v461->timer;
  int v471 = v462 + 1;
  v461->timer = v471;
  int * v464 = v461->regs;
  int v465 = v464[10];
  int v466 = v464[13];
  int * v467 = v461->mem;
  int v476 = (int)((unsigned int)(v465 + 28) >> 2);
  v467[v476] = v466;
  struct StateT * v469 = slot_30(v461);
  return v469;
}

struct StateT * slot_55(struct StateT * v915) {
  int v916 = v915->timer;
  int v923 = v916 + 1;
  v915->timer = v923;
  int * v918 = v915->regs;
  int v919 = v918[12];
  int v926 = v919 + -718;
  v918[12] = v926;
  struct StateT * v921 = slot_56(v915);
  return v921;
}

struct StateT * slot_16(struct StateT * v246) {
  int v247 = v246->timer;
  int v253 = v247 + 1;
  v246->timer = v253;
  int * v249 = v246->regs;
  v249[29] = 2;
  struct StateT * v251 = slot_17(v246);
  return v251;
}

struct StateT * slot_5(struct StateT * v80) {
  int v81 = v80->timer;
  int v87 = v81 + 1;
  v80->timer = v87;
  int * v83 = v80->regs;
  v83[15] = 15;
  struct StateT * v85 = slot_6(v80);
  return v85;
}

struct StateT * slot_7(struct StateT * v105) {
  int v106 = v105->timer;
  int v115 = v106 + 1;
  v105->timer = v115;
  int * v108 = v105->regs;
  int v109 = v108[10];
  int v110 = v108[13];
  int * v111 = v105->mem;
  int v120 = (int)((unsigned int)(v109 + 20) >> 2);
  v111[v120] = v110;
  struct StateT * v113 = slot_8(v105);
  return v113;
}

struct StateT * slot_31(struct StateT * v499) {
  int v500 = v499->timer;
  int v509 = v500 + 1;
  v499->timer = v509;
  int * v502 = v499->regs;
  int v503 = v502[2];
  int v504 = v502[16];
  int * v505 = v499->mem;
  int v514 = (int)((unsigned int)(v503 + 28) >> 2);
  v505[v514] = v504;
  struct StateT * v507 = slot_32(v499);
  return v507;
}

struct StateT * slot_54(struct StateT * v901) {
  int v902 = v901->timer;
  int v909 = v902 + 1;
  v901->timer = v909;
  int * v904 = v901->regs;
  int v905 = v904[13];
  int v912 = v905 + 1134;
  v904[13] = v912;
  struct StateT * v907 = slot_55(v901);
  return v907;
}

struct StateT * slot_26(struct StateT * v410) {
  int v411 = v410->timer;
  int v420 = v411 + 1;
  v410->timer = v420;
  int * v413 = v410->regs;
  int v414 = v413[2];
  int v415 = v413[14];
  int * v416 = v410->mem;
  int v425 = (int)((unsigned int)(v414 + 20) >> 2);
  v416[v425] = v415;
  struct StateT * v418 = slot_27(v410);
  return v418;
}

struct StateT * slot_10(struct StateT * v156) {
  int v157 = v156->timer;
  int v163 = v157 + 1;
  v156->timer = v163;
  int * v159 = v156->regs;
  v159[5] = 6;
  struct StateT * v161 = slot_11(v156);
  return v161;
}

struct StateT * slot_19(struct StateT * v297) {
  int v298 = v297->timer;
  int v304 = v298 + 1;
  v297->timer = v304;
  int * v300 = v297->regs;
  v300[30] = 7;
  struct StateT * v302 = slot_20(v297);
  return v302;
}

struct StateT * slot_58(struct StateT * v962) {
  int v963 = v962->timer;
  int v972 = v963 + 1;
  v962->timer = v972;
  int * v965 = v962->regs;
  int v966 = v965[10];
  int v967 = v965[13];
  int * v968 = v962->mem;
  int v977 = (int)((unsigned int)(v966 + 4) >> 2);
  v968[v977] = v967;
  struct StateT * v970 = slot_59(v962);
  return v970;
}

struct StateT * slot_14(struct StateT * v220) {
  int v221 = v220->timer;
  int v227 = v221 + 1;
  v220->timer = v227;
  int * v223 = v220->regs;
  v223[7] = 8;
  struct StateT * v225 = slot_15(v220);
  return v225;
}

struct StateT * slot_53(struct StateT * v886) {
  int v887 = v886->timer;
  int v894 = v887 + 1;
  v886->timer = v894;
  int * v889 = v886->regs;
  int v890 = v889[15];
  int v898 = v890 + -1947;
  v889[14] = v898;
  struct StateT * v892 = slot_54(v886);
  return v892;
}

struct StateT * slot_44(struct StateT * v734) {
  int v735 = v734->timer;
  int v741 = v735 + 1;
  v734->timer = v741;
  int * v737 = v734->regs;
  v737[13] = 857759744;
  struct StateT * v739 = slot_45(v734);
  return v739;
}

struct StateT * slot_28(struct StateT * v448) {
  int v449 = v448->timer;
  int v455 = v449 + 1;
  v448->timer = v455;
  int * v451 = v448->regs;
  v451[12] = 14;
  struct StateT * v453 = slot_29(v448);
  return v453;
}

struct StateT * slot_32(struct StateT * v518) {
  int v519 = v518->timer;
  int v528 = v519 + 1;
  v518->timer = v528;
  int * v521 = v518->regs;
  int v522 = v521[2];
  int v523 = v521[17];
  int * v524 = v518->mem;
  int v533 = (int)((unsigned int)(v522 + 32) >> 2);
  v524[v533] = v523;
  struct StateT * v526 = slot_33(v518);
  return v526;
}

struct StateT * slot_17(struct StateT * v259) {
  int v260 = v259->timer;
  int v269 = v260 + 1;
  v259->timer = v269;
  int * v262 = v259->regs;
  int v263 = v262[10];
  int v264 = v262[13];
  int * v265 = v259->mem;
  int v274 = (int)((unsigned int)(v263 + 60) >> 2);
  v265[v274] = v264;
  struct StateT * v267 = slot_18(v259);
  return v267;
}

struct StateT * slot_49(struct StateT * v822) {
  int v823 = v822->timer;
  int v832 = v823 + 1;
  v822->timer = v832;
  int * v825 = v822->regs;
  int v826 = v825[2];
  int v827 = v825[14];
  int * v828 = v822->mem;
  int v837 = (int)((unsigned int)(v826 + 72) >> 2);
  v828[v837] = v827;
  struct StateT * v830 = slot_50(v822);
  return v830;
}

struct StateT * slot_33(struct StateT * v537) {
  int v538 = v537->timer;
  int v547 = v538 + 1;
  v537->timer = v547;
  int * v540 = v537->regs;
  int v541 = v540[2];
  int v542 = v540[5];
  int * v543 = v537->mem;
  int v552 = (int)((unsigned int)(v541 + 36) >> 2);
  v543[v552] = v542;
  struct StateT * v545 = slot_34(v537);
  return v545;
}

struct StateT * slot_50(struct StateT * v841) {
  int v842 = v841->timer;
  int v848 = v842 + 1;
  v841->timer = v848;
  int * v844 = v841->regs;
  v844[12] = 2036477952;
  struct StateT * v846 = slot_51(v841);
  return v846;
}

struct StateT * slot_36(struct StateT * v588) {
  int v589 = v588->timer;
  int v598 = v589 + 1;
  v588->timer = v598;
  int * v591 = v588->regs;
  int v592 = v591[10];
  int v593 = v591[13];
  int * v594 = v588->mem;
  int v603 = (int)((unsigned int)(v592 + 16) >> 2);
  v594[v603] = v593;
  struct StateT * v596 = slot_37(v588);
  return v596;
}

struct StateT * slot_37(struct StateT * v607) {
  int v608 = v607->timer;
  int v617 = v608 + 1;
  v607->timer = v617;
  int * v610 = v607->regs;
  int v611 = v610[11];
  int * v612 = v607->mem;
  int v621 = (int)((unsigned int)(v611 + 24) >> 2);
  int v613 = v612[v621];
  v610[13] = v613;
  struct StateT * v615 = slot_38(v607);
  return v615;
}

struct StateT * slot_57(struct StateT * v943) {
  int v944 = v943->timer;
  int v953 = v944 + 1;
  v943->timer = v953;
  int * v946 = v943->regs;
  int v947 = v946[10];
  int v948 = v946[14];
  int * v949 = v943->mem;
  int v958 = (int)((unsigned int)v947 >> 2);
  v949[v958] = v948;
  struct StateT * v951 = slot_58(v943);
  return v951;
}

struct StateT * slot_59(struct StateT * v981) {
  int v982 = v981->timer;
  int v991 = v982 + 1;
  v981->timer = v991;
  int * v984 = v981->regs;
  int v985 = v984[10];
  int v986 = v984[12];
  int * v987 = v981->mem;
  int v996 = (int)((unsigned int)(v985 + 8) >> 2);
  v987[v996] = v986;
  struct StateT * v989 = slot_60(v981);
  return v989;
}

struct StateT * slot_40(struct StateT * v664) {
  int v665 = v664->timer;
  int v674 = v665 + 1;
  v664->timer = v674;
  int * v667 = v664->regs;
  int v668 = v667[2];
  int v669 = v667[29];
  int * v670 = v664->mem;
  int v679 = (int)((unsigned int)(v668 + 52) >> 2);
  v670[v679] = v669;
  struct StateT * v672 = slot_41(v664);
  return v672;
}

struct StateT * slot_27(struct StateT * v429) {
  int v430 = v429->timer;
  int v439 = v430 + 1;
  v429->timer = v439;
  int * v432 = v429->regs;
  int v433 = v432[2];
  int v434 = v432[15];
  int * v435 = v429->mem;
  int v444 = (int)((unsigned int)(v433 + 24) >> 2);
  v435[v444] = v434;
  struct StateT * v437 = slot_28(v429);
  return v437;
}

struct StateT * slot_15(struct StateT * v233) {
  int v234 = v233->timer;
  int v240 = v234 + 1;
  v233->timer = v240;
  int * v236 = v233->regs;
  v236[28] = 13;
  struct StateT * v238 = slot_16(v233);
  return v238;
}

struct StateT * slot_62(struct StateT * v1038) {
  int v1039 = v1038->timer;
  int v1046 = v1039 + 1;
  v1038->timer = v1046;
  int * v1041 = v1038->regs;
  int v1042 = v1041[2];
  int v1049 = v1042 + 80;
  v1041[2] = v1049;
  struct StateT * v1044 = slot_63(v1038);
  return v1044;
}

struct StateT * slot_48(struct StateT * v803) {
  int v804 = v803->timer;
  int v813 = v804 + 1;
  v803->timer = v813;
  int * v806 = v803->regs;
  int v807 = v806[2];
  int v808 = v806[12];
  int * v809 = v803->mem;
  int v818 = (int)((unsigned int)(v807 + 68) >> 2);
  v809[v818] = v808;
  struct StateT * v811 = slot_49(v803);
  return v811;
}

struct StateT * slot_22(struct StateT * v336) {
  int v337 = v336->timer;
  int v346 = v337 + 1;
  v336->timer = v346;
  int * v339 = v336->regs;
  int v340 = v339[10];
  int v341 = v339[13];
  int * v342 = v336->mem;
  int v351 = (int)((unsigned int)(v340 + 48) >> 2);
  v342[v351] = v341;
  struct StateT * v344 = slot_23(v336);
  return v344;
}

struct StateT * slot_35(struct StateT * v575) {
  int v576 = v575->timer;
  int v582 = v576 + 1;
  v575->timer = v582;
  int * v578 = v575->regs;
  v578[14] = 3;
  struct StateT * v580 = slot_36(v575);
  return v580;
}

struct StateT * slot_56(struct StateT * v929) {
  int v930 = v929->timer;
  int v937 = v930 + 1;
  v929->timer = v937;
  int * v932 = v929->regs;
  int v933 = v932[11];
  int v940 = v933 + 1396;
  v932[11] = v940;
  struct StateT * v935 = slot_57(v929);
  return v935;
}

struct StateT * slot_34(struct StateT * v556) {
  int v557 = v556->timer;
  int v566 = v557 + 1;
  v556->timer = v566;
  int * v559 = v556->regs;
  int v560 = v559[2];
  int v561 = v559[6];
  int * v562 = v556->mem;
  int v571 = (int)((unsigned int)(v560 + 40) >> 2);
  v562[v571] = v561;
  struct StateT * v564 = slot_35(v556);
  return v564;
}

struct StateT * slot_51(struct StateT * v854) {
  int v855 = v854->timer;
  int v864 = v855 + 1;
  v854->timer = v864;
  int * v857 = v854->regs;
  int v858 = v857[10];
  int v859 = v857[11];
  int * v860 = v854->mem;
  int v869 = (int)((unsigned int)(v858 + 56) >> 2);
  v860[v869] = v859;
  struct StateT * v862 = slot_52(v854);
  return v862;
}

struct StateT * slot_52(struct StateT * v873) {
  int v874 = v873->timer;
  int v880 = v874 + 1;
  v873->timer = v880;
  int * v876 = v873->regs;
  v876[11] = 1797283840;
  struct StateT * v878 = slot_53(v873);
  return v878;
}

struct StateT * slot_25(struct StateT * v391) {
  int v392 = v391->timer;
  int v401 = v392 + 1;
  v391->timer = v401;
  int * v394 = v391->regs;
  int v395 = v394[2];
  int v396 = v394[12];
  int * v397 = v391->mem;
  int v406 = (int)((unsigned int)(v395 + 16) >> 2);
  v397[v406] = v396;
  struct StateT * v399 = slot_26(v391);
  return v399;
}

struct StateT * slot_23(struct StateT * v355) {
  int v356 = v355->timer;
  int v365 = v356 + 1;
  v355->timer = v365;
  int * v358 = v355->regs;
  int v359 = v358[11];
  int * v360 = v355->mem;
  int v369 = (int)((unsigned int)(v359 + 16) >> 2);
  int v361 = v360[v369];
  v358[13] = v361;
  struct StateT * v363 = slot_24(v355);
  return v363;
}

struct StateT * slot_2(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[12] = 5;
  struct StateT * v40 = slot_3(v35);
  return v40;
}

struct StateT * slot_21(struct StateT * v323) {
  int v324 = v323->timer;
  int v330 = v324 + 1;
  v323->timer = v330;
  int * v326 = v323->regs;
  v326[8] = 9;
  struct StateT * v328 = slot_22(v323);
  return v328;
}

struct StateT * slot_3(struct StateT * v48) {
  int v49 = v48->timer;
  int v58 = v49 + 1;
  v48->timer = v58;
  int * v51 = v48->regs;
  int v52 = v51[11];
  int * v53 = v48->mem;
  int v62 = (int)((unsigned int)v52 >> 2);
  int v54 = v53[v62];
  v51[13] = v54;
  struct StateT * v56 = slot_4(v48);
  return v56;
}

struct StateT * slot_45(struct StateT * v747) {
  int v748 = v747->timer;
  int v757 = v748 + 1;
  v747->timer = v757;
  int * v750 = v747->regs;
  int v751 = v750[11];
  int * v752 = v747->mem;
  int v761 = (int)((unsigned int)(v751 + 28) >> 2);
  int v753 = v752[v761];
  v750[11] = v753;
  struct StateT * v755 = slot_46(v747);
  return v755;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v26 = v17 + 1;
  v16->timer = v26;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->mem;
  int v31 = (int)((unsigned int)(v20 + 76) >> 2);
  v22[v31] = v21;
  struct StateT * v24 = slot_2(v16);
  return v24;
}

struct StateT * slot_13(struct StateT * v201) {
  int v202 = v201->timer;
  int v211 = v202 + 1;
  v201->timer = v211;
  int * v204 = v201->regs;
  int v205 = v204[11];
  int * v206 = v201->mem;
  int v215 = (int)((unsigned int)(v205 + 8) >> 2);
  int v207 = v206[v215];
  v204[13] = v207;
  struct StateT * v209 = slot_14(v201);
  return v209;
}

struct StateT * slot_38(struct StateT * v626) {
  int v627 = v626->timer;
  int v636 = v627 + 1;
  v626->timer = v636;
  int * v629 = v626->regs;
  int v630 = v629[2];
  int v631 = v629[7];
  int * v632 = v626->mem;
  int v641 = (int)((unsigned int)(v630 + 44) >> 2);
  v632[v641] = v631;
  struct StateT * v634 = slot_39(v626);
  return v634;
}

struct StateT * slot_63(struct StateT * v1052) {
  int v1053 = v1052->timer;
  int v1056 = v1053 + 1;
  v1052->timer = v1056;
  return v1052;
}

struct StateT * slot_24(struct StateT * v374) {
  int v375 = v374->timer;
  int v383 = v375 + 1;
  v374->timer = v383;
  int * v377 = v374->regs;
  int v378 = v377[2];
  int * v379 = v374->mem;
  int v387 = (int)((unsigned int)(v378 + 12) >> 2);
  v379[v387] = 0;
  struct StateT * v381 = slot_25(v374);
  return v381;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -80;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_42(struct StateT * v702) {
  int v703 = v702->timer;
  int v709 = v703 + 1;
  v702->timer = v709;
  int * v705 = v702->regs;
  v705[15] = 1634762752;
  struct StateT * v707 = slot_43(v702);
  return v707;
}

struct StateT * slot_46(struct StateT * v765) {
  int v766 = v765->timer;
  int v775 = v766 + 1;
  v765->timer = v775;
  int * v768 = v765->regs;
  int v769 = v768[2];
  int v770 = v768[31];
  int * v771 = v765->mem;
  int v780 = (int)((unsigned int)(v769 + 60) >> 2);
  v771[v780] = v770;
  struct StateT * v773 = slot_47(v765);
  return v773;
}

struct StateT * slot_20(struct StateT * v310) {
  int v311 = v310->timer;
  int v317 = v311 + 1;
  v310->timer = v317;
  int * v313 = v310->regs;
  v313[31] = 4;
  struct StateT * v315 = slot_21(v310);
  return v315;
}

struct StateT * slot_61(struct StateT * v1019) {
  int v1020 = v1019->timer;
  int v1029 = v1020 + 1;
  v1019->timer = v1029;
  int * v1022 = v1019->regs;
  int v1023 = v1022[2];
  int * v1024 = v1019->mem;
  int v1033 = (int)((unsigned int)(v1023 + 76) >> 2);
  int v1025 = v1024[v1033];
  v1022[8] = v1025;
  struct StateT * v1027 = slot_62(v1019);
  return v1027;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v683) {
  int v684 = v683->timer;
  int v693 = v684 + 1;
  v683->timer = v693;
  int * v686 = v683->regs;
  int v687 = v686[2];
  int v688 = v686[30];
  int * v689 = v683->mem;
  int v698 = (int)((unsigned int)(v687 + 56) >> 2);
  v689[v698] = v688;
  struct StateT * v691 = slot_42(v683);
  return v691;
}

struct StateT * slot_39(struct StateT * v645) {
  int v646 = v645->timer;
  int v655 = v646 + 1;
  v645->timer = v655;
  int * v648 = v645->regs;
  int v649 = v648[2];
  int v650 = v648[28];
  int * v651 = v645->mem;
  int v660 = (int)((unsigned int)(v649 + 48) >> 2);
  v651[v660] = v650;
  struct StateT * v653 = slot_40(v645);
  return v653;
}

struct StateT * slot_8(struct StateT * v124) {
  int v125 = v124->timer;
  int v134 = v125 + 1;
  v124->timer = v134;
  int * v127 = v124->regs;
  int v128 = v127[11];
  int * v129 = v124->mem;
  int v138 = (int)((unsigned int)(v128 + 4) >> 2);
  int v130 = v129[v138];
  v127[13] = v130;
  struct StateT * v132 = slot_9(v124);
  return v132;
}

struct StateT * slot_30(struct StateT * v480) {
  int v481 = v480->timer;
  int v490 = v481 + 1;
  v480->timer = v490;
  int * v483 = v480->regs;
  int v484 = v483[11];
  int * v485 = v480->mem;
  int v494 = (int)((unsigned int)(v484 + 20) >> 2);
  int v486 = v485[v494];
  v483[13] = v486;
  struct StateT * v488 = slot_31(v480);
  return v488;
}

struct StateT * slot_60(struct StateT * v1000) {
  int v1001 = v1000->timer;
  int v1010 = v1001 + 1;
  v1000->timer = v1010;
  int * v1003 = v1000->regs;
  int v1004 = v1003[10];
  int v1005 = v1003[11];
  int * v1006 = v1000->mem;
  int v1015 = (int)((unsigned int)(v1004 + 12) >> 2);
  v1006[v1015] = v1005;
  struct StateT * v1008 = slot_61(v1000);
  return v1008;
}

struct StateT * slot_4(struct StateT * v67) {
  int v68 = v67->timer;
  int v74 = v68 + 1;
  v67->timer = v74;
  int * v70 = v67->regs;
  v70[14] = 10;
  struct StateT * v72 = slot_5(v67);
  return v72;
}

struct StateT * slot_18(struct StateT * v278) {
  int v279 = v278->timer;
  int v288 = v279 + 1;
  v278->timer = v288;
  int * v281 = v278->regs;
  int v282 = v281[11];
  int * v283 = v278->mem;
  int v292 = (int)((unsigned int)(v282 + 12) >> 2);
  int v284 = v283[v292];
  v281[13] = v284;
  struct StateT * v286 = slot_19(v278);
  return v286;
}

struct StateT * slot_9(struct StateT * v143) {
  int v144 = v143->timer;
  int v150 = v144 + 1;
  v143->timer = v150;
  int * v146 = v143->regs;
  v146[17] = 1;
  struct StateT * v148 = slot_10(v143);
  return v148;
}

struct StateT * slot_11(struct StateT * v169) {
  int v170 = v169->timer;
  int v176 = v170 + 1;
  v169->timer = v176;
  int * v172 = v169->regs;
  v172[6] = 11;
  struct StateT * v174 = slot_12(v169);
  return v174;
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
  
  // a10, 16 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 8 words read by the callee: the address is public
  s1.regs[11] = 64;
  s2.regs[11] = 64;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = secret(0, 20);
    s2.mem[16 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}