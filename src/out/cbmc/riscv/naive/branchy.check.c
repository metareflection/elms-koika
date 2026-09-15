// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]
#define NUM_REGS 32
#define MEM_SIZE 32
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
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
  int mem[32];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v212);
struct StateT * slot_43(struct StateT * v772);
struct StateT * slot_6(struct StateT * v101);
struct StateT * slot_47(struct StateT * v842);
struct StateT * slot_29(struct StateT * v519);
struct StateT * slot_55(struct StateT * v985);
struct StateT * slot_16(struct StateT * v281);
struct StateT * slot_5(struct StateT * v85);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_31(struct StateT * v551);
struct StateT * slot_54(struct StateT * v969);
struct StateT * slot_26(struct StateT * v461);
struct StateT * slot_10(struct StateT * v175);
struct StateT * slot_19(struct StateT * v339);
struct StateT * slot_58(struct StateT * v1042);
struct StateT * slot_14(struct StateT * v249);
struct StateT * slot_53(struct StateT * v952);
struct StateT * slot_44(struct StateT * v789);
struct StateT * slot_28(struct StateT * v502);
struct StateT * slot_32(struct StateT * v572);
struct StateT * slot_17(struct StateT * v302);
struct StateT * slot_49(struct StateT * v879);
struct StateT * slot_33(struct StateT * v592);
struct StateT * slot_50(struct StateT * v895);
struct StateT * slot_36(struct StateT * v641);
struct StateT * slot_37(struct StateT * v662);
struct StateT * slot_57(struct StateT * v1022);
struct StateT * slot_59(struct StateT * v1059);
struct StateT * slot_40(struct StateT * v715);
struct StateT * slot_27(struct StateT * v482);
struct StateT * slot_15(struct StateT * v265);
struct StateT * slot_62(struct StateT * v1112);
struct StateT * slot_48(struct StateT * v862);
struct StateT * slot_22(struct StateT * v392);
struct StateT * slot_35(struct StateT * v625);
struct StateT * slot_56(struct StateT * v1001);
struct StateT * slot_34(struct StateT * v609);
struct StateT * slot_51(struct StateT * v911);
struct StateT * slot_52(struct StateT * v932);
struct StateT * slot_25(struct StateT * v445);
struct StateT * slot_23(struct StateT * v412);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_21(struct StateT * v371);
struct StateT * slot_3(struct StateT * v52);
struct StateT * slot_45(struct StateT * v805);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v232);
struct StateT * slot_38(struct StateT * v682);
struct StateT * slot_24(struct StateT * v429);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v752);
struct StateT * slot_46(struct StateT * v821);
struct StateT * slot_20(struct StateT * v355);
struct StateT * slot_61(struct StateT * v1091);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v731);
struct StateT * slot_39(struct StateT * v699);
struct StateT * slot_8(struct StateT * v142);
struct StateT * slot_30(struct StateT * v535);
struct StateT * slot_60(struct StateT * v1075);
struct StateT * slot_4(struct StateT * v69);
struct StateT * slot_18(struct StateT * v322);
struct StateT * slot_9(struct StateT * v159);
struct StateT * slot_11(struct StateT * v191);
struct StateT * slot_12(struct StateT * v212) {
  int v213 = v212->timer;
  int v223 = v213 + 1;
  v212->timer = v223;
  int * v215 = v212->regs;
  int v216 = v215[5];
  int * v217 = v212->regs;
  int v218 = v217[7];
  int * v219 = v212->regs;
  int v229 = v216 ^ v218;
  v219[5] = v229;
  struct StateT * v221 = slot_13(v212);
  return v221;
}

struct StateT * slot_43(struct StateT * v772) {
  int v773 = v772->timer;
  int v781 = v773 + 1;
  v772->timer = v781;
  int * v775 = v772->regs;
  int v776 = v775[11];
  int * v777 = v772->regs;
  int v786 = (int)((unsigned int)v776 >> 10);
  v777[6] = v786;
  struct StateT * v779 = slot_44(v772);
  return v779;
}

struct StateT * slot_6(struct StateT * v101) {
  int v102 = v101->timer;
  int v112 = v102 + 1;
  v101->timer = v112;
  int * v104 = v101->regs;
  int v105 = v104[6];
  int * v106 = v101->mem;
  int v116 = (int)((unsigned int)v105 >> 2);
  int v107 = v106[v116];
  int * v108 = v101->regs;
  v108[7] = v107;
  struct StateT * v110 = slot_7(v101);
  return v110;
}

struct StateT * slot_47(struct StateT * v842) {
  int v843 = v842->timer;
  int v853 = v843 + 1;
  v842->timer = v853;
  int * v845 = v842->regs;
  int v846 = v845[5];
  int * v847 = v842->regs;
  int v848 = v847[7];
  int * v849 = v842->regs;
  int v859 = v846 ^ v848;
  v849[5] = v859;
  struct StateT * v851 = slot_48(v842);
  return v851;
}

struct StateT * slot_29(struct StateT * v519) {
  int v520 = v519->timer;
  int v528 = v520 + 1;
  v519->timer = v528;
  int * v522 = v519->regs;
  int v523 = v522[6];
  int * v524 = v519->regs;
  int v532 = v523 & 31;
  v524[6] = v532;
  struct StateT * v526 = slot_30(v519);
  return v526;
}

struct StateT * slot_55(struct StateT * v985) {
  int v986 = v985->timer;
  int v994 = v986 + 1;
  v985->timer = v994;
  int * v988 = v985->regs;
  int v989 = v988[6];
  int * v990 = v985->regs;
  int v998 = v989 << 2;
  v990[6] = v998;
  struct StateT * v992 = slot_56(v985);
  return v992;
}

struct StateT * slot_16(struct StateT * v281) {
  int v282 = v281->timer;
  int v292 = v282 + 1;
  v281->timer = v292;
  int * v284 = v281->regs;
  int v285 = v284[6];
  int * v286 = v281->mem;
  int v296 = (int)((unsigned int)v285 >> 2);
  int v287 = v286[v296];
  int * v288 = v281->regs;
  v288[7] = v287;
  struct StateT * v290 = slot_17(v281);
  return v290;
}

struct StateT * slot_5(struct StateT * v85) {
  int v86 = v85->timer;
  int v94 = v86 + 1;
  v85->timer = v94;
  int * v88 = v85->regs;
  int v89 = v88[6];
  int * v90 = v85->regs;
  int v98 = v89 << 2;
  v90[6] = v98;
  struct StateT * v92 = slot_6(v85);
  return v92;
}

struct StateT * slot_7(struct StateT * v122) {
  int v123 = v122->timer;
  int v133 = v123 + 1;
  v122->timer = v133;
  int * v125 = v122->regs;
  int v126 = v125[5];
  int * v127 = v122->regs;
  int v128 = v127[7];
  int * v129 = v122->regs;
  int v139 = v126 ^ v128;
  v129[5] = v139;
  struct StateT * v131 = slot_8(v122);
  return v131;
}

struct StateT * slot_31(struct StateT * v551) {
  int v552 = v551->timer;
  int v562 = v552 + 1;
  v551->timer = v562;
  int * v554 = v551->regs;
  int v555 = v554[6];
  int * v556 = v551->mem;
  int v566 = (int)((unsigned int)v555 >> 2);
  int v557 = v556[v566];
  int * v558 = v551->regs;
  v558[7] = v557;
  struct StateT * v560 = slot_32(v551);
  return v560;
}

struct StateT * slot_54(struct StateT * v969) {
  int v970 = v969->timer;
  int v978 = v970 + 1;
  v969->timer = v978;
  int * v972 = v969->regs;
  int v973 = v972[6];
  int * v974 = v969->regs;
  int v982 = v973 & 31;
  v974[6] = v982;
  struct StateT * v976 = slot_55(v969);
  return v976;
}

struct StateT * slot_26(struct StateT * v461) {
  int v462 = v461->timer;
  int v472 = v462 + 1;
  v461->timer = v472;
  int * v464 = v461->regs;
  int v465 = v464[6];
  int * v466 = v461->mem;
  int v476 = (int)((unsigned int)v465 >> 2);
  int v467 = v466[v476];
  int * v468 = v461->regs;
  v468[7] = v467;
  struct StateT * v470 = slot_27(v461);
  return v470;
}

struct StateT * slot_10(struct StateT * v175) {
  int v176 = v175->timer;
  int v184 = v176 + 1;
  v175->timer = v184;
  int * v178 = v175->regs;
  int v179 = v178[6];
  int * v180 = v175->regs;
  int v188 = v179 << 2;
  v180[6] = v188;
  struct StateT * v182 = slot_11(v175);
  return v182;
}

struct StateT * slot_19(struct StateT * v339) {
  int v340 = v339->timer;
  int v348 = v340 + 1;
  v339->timer = v348;
  int * v342 = v339->regs;
  int v343 = v342[6];
  int * v344 = v339->regs;
  int v352 = v343 & 31;
  v344[6] = v352;
  struct StateT * v346 = slot_20(v339);
  return v346;
}

struct StateT * slot_58(struct StateT * v1042) {
  int v1043 = v1042->timer;
  int v1051 = v1043 + 1;
  v1042->timer = v1051;
  int * v1045 = v1042->regs;
  int v1046 = v1045[11];
  int * v1047 = v1042->regs;
  int v1056 = (int)((unsigned int)v1046 >> 25);
  v1047[6] = v1056;
  struct StateT * v1049 = slot_59(v1042);
  return v1049;
}

struct StateT * slot_14(struct StateT * v249) {
  int v250 = v249->timer;
  int v258 = v250 + 1;
  v249->timer = v258;
  int * v252 = v249->regs;
  int v253 = v252[6];
  int * v254 = v249->regs;
  int v262 = v253 & 31;
  v254[6] = v262;
  struct StateT * v256 = slot_15(v249);
  return v256;
}

struct StateT * slot_53(struct StateT * v952) {
  int v953 = v952->timer;
  int v961 = v953 + 1;
  v952->timer = v961;
  int * v955 = v952->regs;
  int v956 = v955[11];
  int * v957 = v952->regs;
  int v966 = (int)((unsigned int)v956 >> 20);
  v957[6] = v966;
  struct StateT * v959 = slot_54(v952);
  return v959;
}

struct StateT * slot_44(struct StateT * v789) {
  int v790 = v789->timer;
  int v798 = v790 + 1;
  v789->timer = v798;
  int * v792 = v789->regs;
  int v793 = v792[6];
  int * v794 = v789->regs;
  int v802 = v793 & 31;
  v794[6] = v802;
  struct StateT * v796 = slot_45(v789);
  return v796;
}

struct StateT * slot_28(struct StateT * v502) {
  int v503 = v502->timer;
  int v511 = v503 + 1;
  v502->timer = v511;
  int * v505 = v502->regs;
  int v506 = v505[10];
  int * v507 = v502->regs;
  int v516 = (int)((unsigned int)v506 >> 25);
  v507[6] = v516;
  struct StateT * v509 = slot_29(v502);
  return v509;
}

struct StateT * slot_32(struct StateT * v572) {
  int v573 = v572->timer;
  int v583 = v573 + 1;
  v572->timer = v583;
  int * v575 = v572->regs;
  int v576 = v575[5];
  int * v577 = v572->regs;
  int v578 = v577[7];
  int * v579 = v572->regs;
  int v589 = v576 ^ v578;
  v579[5] = v589;
  struct StateT * v581 = slot_33(v572);
  return v581;
}

struct StateT * slot_17(struct StateT * v302) {
  int v303 = v302->timer;
  int v313 = v303 + 1;
  v302->timer = v313;
  int * v305 = v302->regs;
  int v306 = v305[5];
  int * v307 = v302->regs;
  int v308 = v307[7];
  int * v309 = v302->regs;
  int v319 = v306 ^ v308;
  v309[5] = v319;
  struct StateT * v311 = slot_18(v302);
  return v311;
}

struct StateT * slot_49(struct StateT * v879) {
  int v880 = v879->timer;
  int v888 = v880 + 1;
  v879->timer = v888;
  int * v882 = v879->regs;
  int v883 = v882[6];
  int * v884 = v879->regs;
  int v892 = v883 & 31;
  v884[6] = v892;
  struct StateT * v886 = slot_50(v879);
  return v886;
}

struct StateT * slot_33(struct StateT * v592) {
  int v593 = v592->timer;
  int v601 = v593 + 1;
  v592->timer = v601;
  int * v595 = v592->regs;
  int v596 = v595[11];
  int * v597 = v592->regs;
  v597[6] = v596;
  struct StateT * v599 = slot_34(v592);
  return v599;
}

struct StateT * slot_50(struct StateT * v895) {
  int v896 = v895->timer;
  int v904 = v896 + 1;
  v895->timer = v904;
  int * v898 = v895->regs;
  int v899 = v898[6];
  int * v900 = v895->regs;
  int v908 = v899 << 2;
  v900[6] = v908;
  struct StateT * v902 = slot_51(v895);
  return v902;
}

struct StateT * slot_36(struct StateT * v641) {
  int v642 = v641->timer;
  int v652 = v642 + 1;
  v641->timer = v652;
  int * v644 = v641->regs;
  int v645 = v644[6];
  int * v646 = v641->mem;
  int v656 = (int)((unsigned int)v645 >> 2);
  int v647 = v646[v656];
  int * v648 = v641->regs;
  v648[7] = v647;
  struct StateT * v650 = slot_37(v641);
  return v650;
}

struct StateT * slot_37(struct StateT * v662) {
  int v663 = v662->timer;
  int v673 = v663 + 1;
  v662->timer = v673;
  int * v665 = v662->regs;
  int v666 = v665[5];
  int * v667 = v662->regs;
  int v668 = v667[7];
  int * v669 = v662->regs;
  int v679 = v666 ^ v668;
  v669[5] = v679;
  struct StateT * v671 = slot_38(v662);
  return v671;
}

struct StateT * slot_57(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1033 = v1023 + 1;
  v1022->timer = v1033;
  int * v1025 = v1022->regs;
  int v1026 = v1025[5];
  int * v1027 = v1022->regs;
  int v1028 = v1027[7];
  int * v1029 = v1022->regs;
  int v1039 = v1026 ^ v1028;
  v1029[5] = v1039;
  struct StateT * v1031 = slot_58(v1022);
  return v1031;
}

struct StateT * slot_59(struct StateT * v1059) {
  int v1060 = v1059->timer;
  int v1068 = v1060 + 1;
  v1059->timer = v1068;
  int * v1062 = v1059->regs;
  int v1063 = v1062[6];
  int * v1064 = v1059->regs;
  int v1072 = v1063 & 31;
  v1064[6] = v1072;
  struct StateT * v1066 = slot_60(v1059);
  return v1066;
}

struct StateT * slot_40(struct StateT * v715) {
  int v716 = v715->timer;
  int v724 = v716 + 1;
  v715->timer = v724;
  int * v718 = v715->regs;
  int v719 = v718[6];
  int * v720 = v715->regs;
  int v728 = v719 << 2;
  v720[6] = v728;
  struct StateT * v722 = slot_41(v715);
  return v722;
}

struct StateT * slot_27(struct StateT * v482) {
  int v483 = v482->timer;
  int v493 = v483 + 1;
  v482->timer = v493;
  int * v485 = v482->regs;
  int v486 = v485[5];
  int * v487 = v482->regs;
  int v488 = v487[7];
  int * v489 = v482->regs;
  int v499 = v486 ^ v488;
  v489[5] = v499;
  struct StateT * v491 = slot_28(v482);
  return v491;
}

struct StateT * slot_15(struct StateT * v265) {
  int v266 = v265->timer;
  int v274 = v266 + 1;
  v265->timer = v274;
  int * v268 = v265->regs;
  int v269 = v268[6];
  int * v270 = v265->regs;
  int v278 = v269 << 2;
  v270[6] = v278;
  struct StateT * v272 = slot_16(v265);
  return v272;
}

struct StateT * slot_62(struct StateT * v1112) {
  int v1113 = v1112->timer;
  int v1122 = v1113 + 1;
  v1112->timer = v1122;
  int * v1115 = v1112->regs;
  int v1116 = v1115[5];
  int * v1117 = v1112->regs;
  int v1118 = v1117[7];
  int * v1119 = v1112->regs;
  int v1128 = v1116 ^ v1118;
  v1119[5] = v1128;
  return v1112;
}

struct StateT * slot_48(struct StateT * v862) {
  int v863 = v862->timer;
  int v871 = v863 + 1;
  v862->timer = v871;
  int * v865 = v862->regs;
  int v866 = v865[11];
  int * v867 = v862->regs;
  int v876 = (int)((unsigned int)v866 >> 15);
  v867[6] = v876;
  struct StateT * v869 = slot_49(v862);
  return v869;
}

struct StateT * slot_22(struct StateT * v392) {
  int v393 = v392->timer;
  int v403 = v393 + 1;
  v392->timer = v403;
  int * v395 = v392->regs;
  int v396 = v395[5];
  int * v397 = v392->regs;
  int v398 = v397[7];
  int * v399 = v392->regs;
  int v409 = v396 ^ v398;
  v399[5] = v409;
  struct StateT * v401 = slot_23(v392);
  return v401;
}

struct StateT * slot_35(struct StateT * v625) {
  int v626 = v625->timer;
  int v634 = v626 + 1;
  v625->timer = v634;
  int * v628 = v625->regs;
  int v629 = v628[6];
  int * v630 = v625->regs;
  int v638 = v629 << 2;
  v630[6] = v638;
  struct StateT * v632 = slot_36(v625);
  return v632;
}

struct StateT * slot_56(struct StateT * v1001) {
  int v1002 = v1001->timer;
  int v1012 = v1002 + 1;
  v1001->timer = v1012;
  int * v1004 = v1001->regs;
  int v1005 = v1004[6];
  int * v1006 = v1001->mem;
  int v1016 = (int)((unsigned int)v1005 >> 2);
  int v1007 = v1006[v1016];
  int * v1008 = v1001->regs;
  v1008[7] = v1007;
  struct StateT * v1010 = slot_57(v1001);
  return v1010;
}

struct StateT * slot_34(struct StateT * v609) {
  int v610 = v609->timer;
  int v618 = v610 + 1;
  v609->timer = v618;
  int * v612 = v609->regs;
  int v613 = v612[6];
  int * v614 = v609->regs;
  int v622 = v613 & 31;
  v614[6] = v622;
  struct StateT * v616 = slot_35(v609);
  return v616;
}

struct StateT * slot_51(struct StateT * v911) {
  int v912 = v911->timer;
  int v922 = v912 + 1;
  v911->timer = v922;
  int * v914 = v911->regs;
  int v915 = v914[6];
  int * v916 = v911->mem;
  int v926 = (int)((unsigned int)v915 >> 2);
  int v917 = v916[v926];
  int * v918 = v911->regs;
  v918[7] = v917;
  struct StateT * v920 = slot_52(v911);
  return v920;
}

struct StateT * slot_52(struct StateT * v932) {
  int v933 = v932->timer;
  int v943 = v933 + 1;
  v932->timer = v943;
  int * v935 = v932->regs;
  int v936 = v935[5];
  int * v937 = v932->regs;
  int v938 = v937[7];
  int * v939 = v932->regs;
  int v949 = v936 ^ v938;
  v939[5] = v949;
  struct StateT * v941 = slot_53(v932);
  return v941;
}

struct StateT * slot_25(struct StateT * v445) {
  int v446 = v445->timer;
  int v454 = v446 + 1;
  v445->timer = v454;
  int * v448 = v445->regs;
  int v449 = v448[6];
  int * v450 = v445->regs;
  int v458 = v449 << 2;
  v450[6] = v458;
  struct StateT * v452 = slot_26(v445);
  return v452;
}

struct StateT * slot_23(struct StateT * v412) {
  int v413 = v412->timer;
  int v421 = v413 + 1;
  v412->timer = v421;
  int * v415 = v412->regs;
  int v416 = v415[10];
  int * v417 = v412->regs;
  int v426 = (int)((unsigned int)v416 >> 20);
  v417[6] = v426;
  struct StateT * v419 = slot_24(v412);
  return v419;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v43 = v33 + 1;
  v32->timer = v43;
  int * v35 = v32->regs;
  int v36 = v35[5];
  int * v37 = v32->regs;
  int v38 = v37[9];
  int * v39 = v32->regs;
  int v49 = v36 ^ v38;
  v39[5] = v49;
  struct StateT * v41 = slot_3(v32);
  return v41;
}

struct StateT * slot_21(struct StateT * v371) {
  int v372 = v371->timer;
  int v382 = v372 + 1;
  v371->timer = v382;
  int * v374 = v371->regs;
  int v375 = v374[6];
  int * v376 = v371->mem;
  int v386 = (int)((unsigned int)v375 >> 2);
  int v377 = v376[v386];
  int * v378 = v371->regs;
  v378[7] = v377;
  struct StateT * v380 = slot_22(v371);
  return v380;
}

struct StateT * slot_3(struct StateT * v52) {
  int v53 = v52->timer;
  int v61 = v53 + 1;
  v52->timer = v61;
  int * v55 = v52->regs;
  int v56 = v55[10];
  int * v57 = v52->regs;
  v57[6] = v56;
  struct StateT * v59 = slot_4(v52);
  return v59;
}

struct StateT * slot_45(struct StateT * v805) {
  int v806 = v805->timer;
  int v814 = v806 + 1;
  v805->timer = v814;
  int * v808 = v805->regs;
  int v809 = v808[6];
  int * v810 = v805->regs;
  int v818 = v809 << 2;
  v810[6] = v818;
  struct StateT * v812 = slot_46(v805);
  return v812;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v24 = v16 + 1;
  v15->timer = v24;
  int * v18 = v15->mem;
  int v19 = v18[20];
  int * v20 = v15->regs;
  v20[9] = v19;
  struct StateT * v22 = slot_2(v15);
  return v22;
}

struct StateT * slot_13(struct StateT * v232) {
  int v233 = v232->timer;
  int v241 = v233 + 1;
  v232->timer = v241;
  int * v235 = v232->regs;
  int v236 = v235[10];
  int * v237 = v232->regs;
  int v246 = (int)((unsigned int)v236 >> 10);
  v237[6] = v246;
  struct StateT * v239 = slot_14(v232);
  return v239;
}

struct StateT * slot_38(struct StateT * v682) {
  int v683 = v682->timer;
  int v691 = v683 + 1;
  v682->timer = v691;
  int * v685 = v682->regs;
  int v686 = v685[11];
  int * v687 = v682->regs;
  int v696 = (int)((unsigned int)v686 >> 5);
  v687[6] = v696;
  struct StateT * v689 = slot_39(v682);
  return v689;
}

struct StateT * slot_24(struct StateT * v429) {
  int v430 = v429->timer;
  int v438 = v430 + 1;
  v429->timer = v438;
  int * v432 = v429->regs;
  int v433 = v432[6];
  int * v434 = v429->regs;
  int v442 = v433 & 31;
  v434[6] = v442;
  struct StateT * v436 = slot_25(v429);
  return v436;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_42(struct StateT * v752) {
  int v753 = v752->timer;
  int v763 = v753 + 1;
  v752->timer = v763;
  int * v755 = v752->regs;
  int v756 = v755[5];
  int * v757 = v752->regs;
  int v758 = v757[7];
  int * v759 = v752->regs;
  int v769 = v756 ^ v758;
  v759[5] = v769;
  struct StateT * v761 = slot_43(v752);
  return v761;
}

struct StateT * slot_46(struct StateT * v821) {
  int v822 = v821->timer;
  int v832 = v822 + 1;
  v821->timer = v832;
  int * v824 = v821->regs;
  int v825 = v824[6];
  int * v826 = v821->mem;
  int v836 = (int)((unsigned int)v825 >> 2);
  int v827 = v826[v836];
  int * v828 = v821->regs;
  v828[7] = v827;
  struct StateT * v830 = slot_47(v821);
  return v830;
}

struct StateT * slot_20(struct StateT * v355) {
  int v356 = v355->timer;
  int v364 = v356 + 1;
  v355->timer = v364;
  int * v358 = v355->regs;
  int v359 = v358[6];
  int * v360 = v355->regs;
  int v368 = v359 << 2;
  v360[6] = v368;
  struct StateT * v362 = slot_21(v355);
  return v362;
}

struct StateT * slot_61(struct StateT * v1091) {
  int v1092 = v1091->timer;
  int v1102 = v1092 + 1;
  v1091->timer = v1102;
  int * v1094 = v1091->regs;
  int v1095 = v1094[6];
  int * v1096 = v1091->mem;
  int v1106 = (int)((unsigned int)v1095 >> 2);
  int v1097 = v1096[v1106];
  int * v1098 = v1091->regs;
  v1098[7] = v1097;
  struct StateT * v1100 = slot_62(v1091);
  return v1100;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v731) {
  int v732 = v731->timer;
  int v742 = v732 + 1;
  v731->timer = v742;
  int * v734 = v731->regs;
  int v735 = v734[6];
  int * v736 = v731->mem;
  int v746 = (int)((unsigned int)v735 >> 2);
  int v737 = v736[v746];
  int * v738 = v731->regs;
  v738[7] = v737;
  struct StateT * v740 = slot_42(v731);
  return v740;
}

struct StateT * slot_39(struct StateT * v699) {
  int v700 = v699->timer;
  int v708 = v700 + 1;
  v699->timer = v708;
  int * v702 = v699->regs;
  int v703 = v702[6];
  int * v704 = v699->regs;
  int v712 = v703 & 31;
  v704[6] = v712;
  struct StateT * v706 = slot_40(v699);
  return v706;
}

struct StateT * slot_8(struct StateT * v142) {
  int v143 = v142->timer;
  int v151 = v143 + 1;
  v142->timer = v151;
  int * v145 = v142->regs;
  int v146 = v145[10];
  int * v147 = v142->regs;
  int v156 = (int)((unsigned int)v146 >> 5);
  v147[6] = v156;
  struct StateT * v149 = slot_9(v142);
  return v149;
}

struct StateT * slot_30(struct StateT * v535) {
  int v536 = v535->timer;
  int v544 = v536 + 1;
  v535->timer = v544;
  int * v538 = v535->regs;
  int v539 = v538[6];
  int * v540 = v535->regs;
  int v548 = v539 << 2;
  v540[6] = v548;
  struct StateT * v542 = slot_31(v535);
  return v542;
}

struct StateT * slot_60(struct StateT * v1075) {
  int v1076 = v1075->timer;
  int v1084 = v1076 + 1;
  v1075->timer = v1084;
  int * v1078 = v1075->regs;
  int v1079 = v1078[6];
  int * v1080 = v1075->regs;
  int v1088 = v1079 << 2;
  v1080[6] = v1088;
  struct StateT * v1082 = slot_61(v1075);
  return v1082;
}

struct StateT * slot_4(struct StateT * v69) {
  int v70 = v69->timer;
  int v78 = v70 + 1;
  v69->timer = v78;
  int * v72 = v69->regs;
  int v73 = v72[6];
  int * v74 = v69->regs;
  int v82 = v73 & 31;
  v74[6] = v82;
  struct StateT * v76 = slot_5(v69);
  return v76;
}

struct StateT * slot_18(struct StateT * v322) {
  int v323 = v322->timer;
  int v331 = v323 + 1;
  v322->timer = v331;
  int * v325 = v322->regs;
  int v326 = v325[10];
  int * v327 = v322->regs;
  int v336 = (int)((unsigned int)v326 >> 15);
  v327[6] = v336;
  struct StateT * v329 = slot_19(v322);
  return v329;
}

struct StateT * slot_9(struct StateT * v159) {
  int v160 = v159->timer;
  int v168 = v160 + 1;
  v159->timer = v168;
  int * v162 = v159->regs;
  int v163 = v162[6];
  int * v164 = v159->regs;
  int v172 = v163 & 31;
  v164[6] = v172;
  struct StateT * v166 = slot_10(v159);
  return v166;
}

struct StateT * slot_11(struct StateT * v191) {
  int v192 = v191->timer;
  int v202 = v192 + 1;
  v191->timer = v202;
  int * v194 = v191->regs;
  int v195 = v194[6];
  int * v196 = v191->mem;
  int v206 = (int)((unsigned int)v195 >> 2);
  int v197 = v196[v206];
  int * v198 = v191->regs;
  v198[7] = v197;
  struct StateT * v200 = slot_12(v191);
  return v200;
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
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  int i11 = bounded(0, 1073741823);
  s1.regs[11] = i11;
  s2.regs[11] = i11;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}