// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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

struct StateT * slot_12(struct StateT * v304);
struct StateT * slot_43(struct StateT * v742);
struct StateT * slot_6(struct StateT * v108);
struct StateT * slot_47(struct StateT * v792);
struct StateT * slot_29(struct StateT * v507);
struct StateT * slot_55(struct StateT * v932);
struct StateT * slot_16(struct StateT * v188);
struct StateT * slot_5(struct StateT * v92);
struct StateT * slot_7(struct StateT * v130);
struct StateT * slot_31(struct StateT * v552);
struct StateT * slot_54(struct StateT * v913);
struct StateT * slot_26(struct StateT * v492);
struct StateT * slot_65(struct StateT * v1076);
struct StateT * slot_10(struct StateT * v207);
struct StateT * slot_19(struct StateT * v285);
struct StateT * slot_58(struct StateT * v952);
struct StateT * slot_67(struct StateT * v1121);
struct StateT * slot_64(struct StateT * v1047);
struct StateT * slot_14(struct StateT * v397);
struct StateT * slot_53(struct StateT * v887);
struct StateT * slot_44(struct StateT * v777);
struct StateT * slot_66(struct StateT * v1102);
struct StateT * slot_28(struct StateT * v477);
struct StateT * slot_32(struct StateT * v587);
struct StateT * slot_17(struct StateT * v226);
struct StateT * slot_49(struct StateT * v837);
struct StateT * slot_33(struct StateT * v620);
struct StateT * slot_50(struct StateT * v872);
struct StateT * slot_36(struct StateT * v628);
struct StateT * slot_37(struct StateT * v647);
struct StateT * slot_57(struct StateT * v1000);
struct StateT * slot_59(struct StateT * v982);
struct StateT * slot_40(struct StateT * v667);
struct StateT * slot_27(struct StateT * v525);
struct StateT * slot_15(struct StateT * v430);
struct StateT * slot_62(struct StateT * v1061);
struct StateT * slot_48(struct StateT * v818);
struct StateT * slot_22(struct StateT * v382);
struct StateT * slot_35(struct StateT * v602);
struct StateT * slot_56(struct StateT * v967);
struct StateT * slot_34(struct StateT * v572);
struct StateT * slot_51(struct StateT * v905);
struct StateT * slot_52(struct StateT * v857);
struct StateT * slot_25(struct StateT * v457);
struct StateT * slot_23(struct StateT * v412);
struct StateT * slot_2(struct StateT * v39);
struct StateT * slot_21(struct StateT * v362);
struct StateT * slot_3(struct StateT * v58);
struct StateT * slot_45(struct StateT * v810);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_13(struct StateT * v342);
struct StateT * slot_38(struct StateT * v682);
struct StateT * slot_63(struct StateT * v1094);
struct StateT * slot_24(struct StateT * v438);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v723);
struct StateT * slot_46(struct StateT * v762);
struct StateT * slot_20(struct StateT * v323);
struct StateT * slot_61(struct StateT * v1027);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v697);
struct StateT * slot_39(struct StateT * v715);
struct StateT * slot_8(struct StateT * v152);
struct StateT * slot_30(struct StateT * v533);
struct StateT * slot_60(struct StateT * v1008);
struct StateT * slot_4(struct StateT * v76);
struct StateT * slot_18(struct StateT * v265);
struct StateT * slot_9(struct StateT * v168);
struct StateT * slot_11(struct StateT * v245);
struct StateT * slot_12(struct StateT * v304) {
  int v305 = v304->timer;
  int v314 = v305 + 1;
  v304->timer = v314;
  int * v307 = v304->regs;
  int v308 = v307[10];
  int v309 = v307[14];
  int * v310 = v304->mem;
  int v319 = (int)((unsigned int)(v308 + 4) >> 2);
  v310[v319] = v309;
  struct StateT * v312 = slot_13(v304);
  return v312;
}

struct StateT * slot_43(struct StateT * v742) {
  int v743 = v742->timer;
  int v753 = v743 + 1;
  v742->timer = v753;
  int * v745 = v742->regs;
  int v746 = v745[12];
  bool v756 = !(v746 == 0);
  struct StateT * v751;
  if (v756) {
    struct StateT * v747 = slot_46(v742);
    v751 = v747;
  } else {
    struct StateT * v749 = slot_44(v742);
    v751 = v749;
  }
  return v751;
}

struct StateT * slot_6(struct StateT * v108) {
  int v109 = v108->timer;
  int v120 = v109 + 1;
  v108->timer = v120;
  int * v111 = v108->regs;
  int v112 = v111[12];
  bool v123 = -2147483648 < (v112 ^ -2147483648);
  int v115;
  if (v123) {
    v115 = 1;
  } else {
    v115 = 0;
  }
  int * v116 = v108->regs;
  v116[12] = v115;
  struct StateT * v118 = slot_7(v108);
  return v118;
}

struct StateT * slot_47(struct StateT * v792) {
  int v793 = v792->timer;
  int v802 = v793 + 1;
  v792->timer = v802;
  int * v795 = v792->regs;
  int v796 = v795[13];
  int * v797 = v792->mem;
  int v806 = (int)((unsigned int)v796 >> 2);
  int v798 = v797[v806];
  v795[13] = v798;
  struct StateT * v800 = slot_48(v792);
  return v800;
}

struct StateT * slot_29(struct StateT * v507) {
  int v508 = v507->timer;
  int v517 = v508 + 1;
  v507->timer = v517;
  int * v510 = v507->regs;
  int v511 = v510[13];
  int * v512 = v507->mem;
  int v521 = (int)((unsigned int)v511 >> 2);
  int v513 = v512[v521];
  v510[13] = v513;
  struct StateT * v515 = slot_30(v507);
  return v515;
}

struct StateT * slot_55(struct StateT * v932) {
  int v933 = v932->timer;
  int v943 = v933 + 1;
  v932->timer = v943;
  int * v935 = v932->regs;
  int v936 = v935[12];
  bool v946 = !(v936 == 0);
  struct StateT * v941;
  if (v946) {
    struct StateT * v937 = slot_58(v932);
    v941 = v937;
  } else {
    struct StateT * v939 = slot_56(v932);
    v941 = v939;
  }
  return v941;
}

struct StateT * slot_16(struct StateT * v188) {
  int v189 = v188->timer;
  int v198 = v189 + 1;
  v188->timer = v198;
  int * v191 = v188->regs;
  int v192 = v191[11];
  int * v193 = v188->mem;
  int v202 = (int)((unsigned int)v192 >> 2);
  int v194 = v193[v202];
  v191[15] = v194;
  struct StateT * v196 = slot_17(v188);
  return v196;
}

struct StateT * slot_5(struct StateT * v92) {
  int v93 = v92->timer;
  int v101 = v93 + 1;
  v92->timer = v101;
  int * v95 = v92->regs;
  int v96 = v95[14];
  int v97 = v95[13];
  int v105 = v96 ^ v97;
  v95[13] = v105;
  struct StateT * v99 = slot_6(v92);
  return v99;
}

struct StateT * slot_7(struct StateT * v130) {
  int v131 = v130->timer;
  int v142 = v131 + 1;
  v130->timer = v142;
  int * v133 = v130->regs;
  int v134 = v133[13];
  bool v145 = -2147483648 < (v134 ^ -2147483648);
  int v137;
  if (v145) {
    v137 = 1;
  } else {
    v137 = 0;
  }
  int * v138 = v130->regs;
  v138[13] = v137;
  struct StateT * v140 = slot_8(v130);
  return v140;
}

struct StateT * slot_31(struct StateT * v552) {
  int v553 = v552->timer;
  int v563 = v553 + 1;
  v552->timer = v563;
  int * v555 = v552->regs;
  int v556 = v555[12];
  bool v566 = !(v556 == 0);
  struct StateT * v561;
  if (v566) {
    struct StateT * v557 = slot_34(v552);
    v561 = v557;
  } else {
    struct StateT * v559 = slot_32(v552);
    v561 = v559;
  }
  return v561;
}

struct StateT * slot_54(struct StateT * v913) {
  int v914 = v913->timer;
  int v923 = v914 + 1;
  v913->timer = v923;
  int * v916 = v913->regs;
  int v917 = v916[10];
  int v918 = v916[13];
  int * v919 = v913->mem;
  int v928 = (int)((unsigned int)(v917 + 28) >> 2);
  v919[v928] = v918;
  struct StateT * v921 = slot_55(v913);
  return v921;
}

struct StateT * slot_26(struct StateT * v492) {
  int v493 = v492->timer;
  int v500 = v493 + 1;
  v492->timer = v500;
  int * v495 = v492->regs;
  int v496 = v495[10];
  int v504 = v496 + 12;
  v495[13] = v504;
  struct StateT * v498 = slot_27(v492);
  return v498;
}

struct StateT * slot_65(struct StateT * v1076) {
  int v1077 = v1076->timer;
  int v1086 = v1077 + 1;
  v1076->timer = v1086;
  int * v1079 = v1076->regs;
  int v1080 = v1079[11];
  int * v1081 = v1076->mem;
  int v1090 = (int)((unsigned int)v1080 >> 2);
  int v1082 = v1081[v1090];
  v1079[11] = v1082;
  struct StateT * v1084 = slot_66(v1076);
  return v1084;
}

struct StateT * slot_10(struct StateT * v207) {
  int v208 = v207->timer;
  int v217 = v208 + 1;
  v207->timer = v217;
  int * v210 = v207->regs;
  int v211 = v210[10];
  int v212 = v210[15];
  int * v213 = v207->mem;
  int v222 = (int)((unsigned int)v211 >> 2);
  v213[v222] = v212;
  struct StateT * v215 = slot_11(v207);
  return v215;
}

struct StateT * slot_19(struct StateT * v285) {
  int v286 = v285->timer;
  int v295 = v286 + 1;
  v285->timer = v295;
  int * v288 = v285->regs;
  int v289 = v288[11];
  int * v290 = v285->mem;
  int v299 = (int)((unsigned int)(v289 + 4) >> 2);
  int v291 = v290[v299];
  v288[14] = v291;
  struct StateT * v293 = slot_20(v285);
  return v293;
}

struct StateT * slot_58(struct StateT * v952) {
  int v953 = v952->timer;
  int v960 = v953 + 1;
  v952->timer = v960;
  int * v955 = v952->regs;
  int v956 = v955[11];
  int v964 = v956 + 32;
  v955[13] = v964;
  struct StateT * v958 = slot_59(v952);
  return v958;
}

struct StateT * slot_67(struct StateT * v1121) {
  int v1122 = v1121->timer;
  int v1125 = v1122 + 1;
  v1121->timer = v1125;
  return v1121;
}

struct StateT * slot_64(struct StateT * v1047) {
  int v1048 = v1047->timer;
  int v1055 = v1048 + 1;
  v1047->timer = v1055;
  int * v1050 = v1047->regs;
  int v1051 = v1050[11];
  int v1058 = v1051 + 36;
  v1050[11] = v1058;
  struct StateT * v1053 = slot_65(v1047);
  return v1053;
}

struct StateT * slot_14(struct StateT * v397) {
  int v398 = v397->timer;
  int v405 = v398 + 1;
  v397->timer = v405;
  int * v400 = v397->regs;
  int v401 = v400[10];
  int v409 = v401 + 8;
  v400[13] = v409;
  struct StateT * v403 = slot_15(v397);
  return v403;
}

struct StateT * slot_53(struct StateT * v887) {
  int v888 = v887->timer;
  int v897 = v888 + 1;
  v887->timer = v897;
  int * v890 = v887->regs;
  int v891 = v890[13];
  int * v892 = v887->mem;
  int v901 = (int)((unsigned int)v891 >> 2);
  int v893 = v892[v901];
  v890[13] = v893;
  struct StateT * v895 = slot_54(v887);
  return v895;
}

struct StateT * slot_44(struct StateT * v777) {
  int v778 = v777->timer;
  int v785 = v778 + 1;
  v777->timer = v785;
  int * v780 = v777->regs;
  int v781 = v780[10];
  int v789 = v781 + 24;
  v780[13] = v789;
  struct StateT * v783 = slot_45(v777);
  return v783;
}

struct StateT * slot_66(struct StateT * v1102) {
  int v1103 = v1102->timer;
  int v1112 = v1103 + 1;
  v1102->timer = v1112;
  int * v1105 = v1102->regs;
  int v1106 = v1105[10];
  int v1107 = v1105[11];
  int * v1108 = v1102->mem;
  int v1117 = (int)((unsigned int)(v1106 + 36) >> 2);
  v1108[v1117] = v1107;
  struct StateT * v1110 = slot_67(v1102);
  return v1110;
}

struct StateT * slot_28(struct StateT * v477) {
  int v478 = v477->timer;
  int v485 = v478 + 1;
  v477->timer = v485;
  int * v480 = v477->regs;
  int v481 = v480[11];
  int v489 = v481 + 12;
  v480[13] = v489;
  struct StateT * v483 = slot_29(v477);
  return v483;
}

struct StateT * slot_32(struct StateT * v587) {
  int v588 = v587->timer;
  int v595 = v588 + 1;
  v587->timer = v595;
  int * v590 = v587->regs;
  int v591 = v590[10];
  int v599 = v591 + 16;
  v590[13] = v599;
  struct StateT * v593 = slot_33(v587);
  return v593;
}

struct StateT * slot_17(struct StateT * v226) {
  int v227 = v226->timer;
  int v236 = v227 + 1;
  v226->timer = v236;
  int * v229 = v226->regs;
  int v230 = v229[10];
  int v231 = v229[15];
  int * v232 = v226->mem;
  int v241 = (int)((unsigned int)v230 >> 2);
  v232[v241] = v231;
  struct StateT * v234 = slot_18(v226);
  return v234;
}

struct StateT * slot_49(struct StateT * v837) {
  int v838 = v837->timer;
  int v848 = v838 + 1;
  v837->timer = v848;
  int * v840 = v837->regs;
  int v841 = v840[12];
  bool v851 = !(v841 == 0);
  struct StateT * v846;
  if (v851) {
    struct StateT * v842 = slot_52(v837);
    v846 = v842;
  } else {
    struct StateT * v844 = slot_50(v837);
    v846 = v844;
  }
  return v846;
}

struct StateT * slot_33(struct StateT * v620) {
  int v621 = v620->timer;
  int v625 = v621 + 1;
  v620->timer = v625;
  struct StateT * v623 = slot_35(v620);
  return v623;
}

struct StateT * slot_50(struct StateT * v872) {
  int v873 = v872->timer;
  int v880 = v873 + 1;
  v872->timer = v880;
  int * v875 = v872->regs;
  int v876 = v875[10];
  int v884 = v876 + 28;
  v875[13] = v884;
  struct StateT * v878 = slot_51(v872);
  return v878;
}

struct StateT * slot_36(struct StateT * v628) {
  int v629 = v628->timer;
  int v638 = v629 + 1;
  v628->timer = v638;
  int * v631 = v628->regs;
  int v632 = v631[10];
  int v633 = v631[13];
  int * v634 = v628->mem;
  int v643 = (int)((unsigned int)(v632 + 16) >> 2);
  v634[v643] = v633;
  struct StateT * v636 = slot_37(v628);
  return v636;
}

struct StateT * slot_37(struct StateT * v647) {
  int v648 = v647->timer;
  int v658 = v648 + 1;
  v647->timer = v658;
  int * v650 = v647->regs;
  int v651 = v650[12];
  bool v661 = !(v651 == 0);
  struct StateT * v656;
  if (v661) {
    struct StateT * v652 = slot_40(v647);
    v656 = v652;
  } else {
    struct StateT * v654 = slot_38(v647);
    v656 = v654;
  }
  return v656;
}

struct StateT * slot_57(struct StateT * v1000) {
  int v1001 = v1000->timer;
  int v1005 = v1001 + 1;
  v1000->timer = v1005;
  struct StateT * v1003 = slot_59(v1000);
  return v1003;
}

struct StateT * slot_59(struct StateT * v982) {
  int v983 = v982->timer;
  int v992 = v983 + 1;
  v982->timer = v992;
  int * v985 = v982->regs;
  int v986 = v985[13];
  int * v987 = v982->mem;
  int v996 = (int)((unsigned int)v986 >> 2);
  int v988 = v987[v996];
  v985[13] = v988;
  struct StateT * v990 = slot_60(v982);
  return v990;
}

struct StateT * slot_40(struct StateT * v667) {
  int v668 = v667->timer;
  int v675 = v668 + 1;
  v667->timer = v675;
  int * v670 = v667->regs;
  int v671 = v670[11];
  int v679 = v671 + 20;
  v670[13] = v679;
  struct StateT * v673 = slot_41(v667);
  return v673;
}

struct StateT * slot_27(struct StateT * v525) {
  int v526 = v525->timer;
  int v530 = v526 + 1;
  v525->timer = v530;
  struct StateT * v528 = slot_29(v525);
  return v528;
}

struct StateT * slot_15(struct StateT * v430) {
  int v431 = v430->timer;
  int v435 = v431 + 1;
  v430->timer = v435;
  struct StateT * v433 = slot_23(v430);
  return v433;
}

struct StateT * slot_62(struct StateT * v1061) {
  int v1062 = v1061->timer;
  int v1069 = v1062 + 1;
  v1061->timer = v1069;
  int * v1064 = v1061->regs;
  int v1065 = v1064[10];
  int v1073 = v1065 + 36;
  v1064[11] = v1073;
  struct StateT * v1067 = slot_63(v1061);
  return v1067;
}

struct StateT * slot_48(struct StateT * v818) {
  int v819 = v818->timer;
  int v828 = v819 + 1;
  v818->timer = v828;
  int * v821 = v818->regs;
  int v822 = v821[10];
  int v823 = v821[13];
  int * v824 = v818->mem;
  int v833 = (int)((unsigned int)(v822 + 24) >> 2);
  v824[v833] = v823;
  struct StateT * v826 = slot_49(v818);
  return v826;
}

struct StateT * slot_22(struct StateT * v382) {
  int v383 = v382->timer;
  int v390 = v383 + 1;
  v382->timer = v390;
  int * v385 = v382->regs;
  int v386 = v385[11];
  int v394 = v386 + 8;
  v385[13] = v394;
  struct StateT * v388 = slot_23(v382);
  return v388;
}

struct StateT * slot_35(struct StateT * v602) {
  int v603 = v602->timer;
  int v612 = v603 + 1;
  v602->timer = v612;
  int * v605 = v602->regs;
  int v606 = v605[13];
  int * v607 = v602->mem;
  int v616 = (int)((unsigned int)v606 >> 2);
  int v608 = v607[v616];
  v605[13] = v608;
  struct StateT * v610 = slot_36(v602);
  return v610;
}

struct StateT * slot_56(struct StateT * v967) {
  int v968 = v967->timer;
  int v975 = v968 + 1;
  v967->timer = v975;
  int * v970 = v967->regs;
  int v971 = v970[10];
  int v979 = v971 + 32;
  v970[13] = v979;
  struct StateT * v973 = slot_57(v967);
  return v973;
}

struct StateT * slot_34(struct StateT * v572) {
  int v573 = v572->timer;
  int v580 = v573 + 1;
  v572->timer = v580;
  int * v575 = v572->regs;
  int v576 = v575[11];
  int v584 = v576 + 16;
  v575[13] = v584;
  struct StateT * v578 = slot_35(v572);
  return v578;
}

struct StateT * slot_51(struct StateT * v905) {
  int v906 = v905->timer;
  int v910 = v906 + 1;
  v905->timer = v910;
  struct StateT * v908 = slot_53(v905);
  return v908;
}

struct StateT * slot_52(struct StateT * v857) {
  int v858 = v857->timer;
  int v865 = v858 + 1;
  v857->timer = v865;
  int * v860 = v857->regs;
  int v861 = v860[11];
  int v869 = v861 + 28;
  v860[13] = v869;
  struct StateT * v863 = slot_53(v857);
  return v863;
}

struct StateT * slot_25(struct StateT * v457) {
  int v458 = v457->timer;
  int v468 = v458 + 1;
  v457->timer = v468;
  int * v460 = v457->regs;
  int v461 = v460[12];
  bool v471 = !(v461 == 0);
  struct StateT * v466;
  if (v471) {
    struct StateT * v462 = slot_28(v457);
    v466 = v462;
  } else {
    struct StateT * v464 = slot_26(v457);
    v466 = v464;
  }
  return v466;
}

struct StateT * slot_23(struct StateT * v412) {
  int v413 = v412->timer;
  int v422 = v413 + 1;
  v412->timer = v422;
  int * v415 = v412->regs;
  int v416 = v415[13];
  int * v417 = v412->mem;
  int v426 = (int)((unsigned int)v416 >> 2);
  int v418 = v417[v426];
  v415[13] = v418;
  struct StateT * v420 = slot_24(v412);
  return v420;
}

struct StateT * slot_2(struct StateT * v39) {
  int v40 = v39->timer;
  int v49 = v40 + 1;
  v39->timer = v49;
  int * v42 = v39->regs;
  int v43 = v42[10];
  int * v44 = v39->mem;
  int v53 = (int)((unsigned int)(v43 + 4) >> 2);
  int v45 = v44[v53];
  v42[14] = v45;
  struct StateT * v47 = slot_3(v39);
  return v47;
}

struct StateT * slot_21(struct StateT * v362) {
  int v363 = v362->timer;
  int v373 = v363 + 1;
  v362->timer = v373;
  int * v365 = v362->regs;
  int v366 = v365[12];
  bool v376 = v366 == 0;
  struct StateT * v371;
  if (v376) {
    struct StateT * v367 = slot_14(v362);
    v371 = v367;
  } else {
    struct StateT * v369 = slot_22(v362);
    v371 = v369;
  }
  return v371;
}

struct StateT * slot_3(struct StateT * v58) {
  int v59 = v58->timer;
  int v68 = v59 + 1;
  v58->timer = v68;
  int * v61 = v58->regs;
  int v62 = v61[13];
  int * v63 = v58->mem;
  int v72 = (int)((unsigned int)(v62 + 4) >> 2);
  int v64 = v63[v72];
  v61[13] = v64;
  struct StateT * v66 = slot_4(v58);
  return v66;
}

struct StateT * slot_45(struct StateT * v810) {
  int v811 = v810->timer;
  int v815 = v811 + 1;
  v810->timer = v815;
  struct StateT * v813 = slot_47(v810);
  return v813;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v30 = v21 + 1;
  v20->timer = v30;
  int * v23 = v20->regs;
  int v24 = v23[10];
  int * v25 = v20->mem;
  int v34 = (int)((unsigned int)v24 >> 2);
  int v26 = v25[v34];
  v23[15] = v26;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_13(struct StateT * v342) {
  int v343 = v342->timer;
  int v353 = v343 + 1;
  v342->timer = v353;
  int * v345 = v342->regs;
  int v346 = v345[12];
  bool v356 = !(v346 == 0);
  struct StateT * v351;
  if (v356) {
    struct StateT * v347 = slot_22(v342);
    v351 = v347;
  } else {
    struct StateT * v349 = slot_14(v342);
    v351 = v349;
  }
  return v351;
}

struct StateT * slot_38(struct StateT * v682) {
  int v683 = v682->timer;
  int v690 = v683 + 1;
  v682->timer = v690;
  int * v685 = v682->regs;
  int v686 = v685[10];
  int v694 = v686 + 20;
  v685[13] = v694;
  struct StateT * v688 = slot_39(v682);
  return v688;
}

struct StateT * slot_63(struct StateT * v1094) {
  int v1095 = v1094->timer;
  int v1099 = v1095 + 1;
  v1094->timer = v1099;
  struct StateT * v1097 = slot_65(v1094);
  return v1097;
}

struct StateT * slot_24(struct StateT * v438) {
  int v439 = v438->timer;
  int v448 = v439 + 1;
  v438->timer = v448;
  int * v441 = v438->regs;
  int v442 = v441[10];
  int v443 = v441[13];
  int * v444 = v438->mem;
  int v453 = (int)((unsigned int)(v442 + 8) >> 2);
  v444[v453] = v443;
  struct StateT * v446 = slot_25(v438);
  return v446;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->mem;
  int v16 = (int)((unsigned int)v6 >> 2);
  int v8 = v7[v16];
  v5[12] = v8;
  struct StateT * v10 = slot_1(v2);
  return v10;
}

struct StateT * slot_42(struct StateT * v723) {
  int v724 = v723->timer;
  int v733 = v724 + 1;
  v723->timer = v733;
  int * v726 = v723->regs;
  int v727 = v726[10];
  int v728 = v726[13];
  int * v729 = v723->mem;
  int v738 = (int)((unsigned int)(v727 + 20) >> 2);
  v729[v738] = v728;
  struct StateT * v731 = slot_43(v723);
  return v731;
}

struct StateT * slot_46(struct StateT * v762) {
  int v763 = v762->timer;
  int v770 = v763 + 1;
  v762->timer = v770;
  int * v765 = v762->regs;
  int v766 = v765[11];
  int v774 = v766 + 24;
  v765[13] = v774;
  struct StateT * v768 = slot_47(v762);
  return v768;
}

struct StateT * slot_20(struct StateT * v323) {
  int v324 = v323->timer;
  int v333 = v324 + 1;
  v323->timer = v333;
  int * v326 = v323->regs;
  int v327 = v326[10];
  int v328 = v326[14];
  int * v329 = v323->mem;
  int v338 = (int)((unsigned int)(v327 + 4) >> 2);
  v329[v338] = v328;
  struct StateT * v331 = slot_21(v323);
  return v331;
}

struct StateT * slot_61(struct StateT * v1027) {
  int v1028 = v1027->timer;
  int v1038 = v1028 + 1;
  v1027->timer = v1038;
  int * v1030 = v1027->regs;
  int v1031 = v1030[12];
  bool v1041 = !(v1031 == 0);
  struct StateT * v1036;
  if (v1041) {
    struct StateT * v1032 = slot_64(v1027);
    v1036 = v1032;
  } else {
    struct StateT * v1034 = slot_62(v1027);
    v1036 = v1034;
  }
  return v1036;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v697) {
  int v698 = v697->timer;
  int v707 = v698 + 1;
  v697->timer = v707;
  int * v700 = v697->regs;
  int v701 = v700[13];
  int * v702 = v697->mem;
  int v711 = (int)((unsigned int)v701 >> 2);
  int v703 = v702[v711];
  v700[13] = v703;
  struct StateT * v705 = slot_42(v697);
  return v705;
}

struct StateT * slot_39(struct StateT * v715) {
  int v716 = v715->timer;
  int v720 = v716 + 1;
  v715->timer = v720;
  struct StateT * v718 = slot_41(v715);
  return v718;
}

struct StateT * slot_8(struct StateT * v152) {
  int v153 = v152->timer;
  int v161 = v153 + 1;
  v152->timer = v161;
  int * v155 = v152->regs;
  int v156 = v155[12];
  int v157 = v155[13];
  int v165 = v156 & v157;
  v155[12] = v165;
  struct StateT * v159 = slot_9(v152);
  return v159;
}

struct StateT * slot_30(struct StateT * v533) {
  int v534 = v533->timer;
  int v543 = v534 + 1;
  v533->timer = v543;
  int * v536 = v533->regs;
  int v537 = v536[10];
  int v538 = v536[13];
  int * v539 = v533->mem;
  int v548 = (int)((unsigned int)(v537 + 12) >> 2);
  v539[v548] = v538;
  struct StateT * v541 = slot_31(v533);
  return v541;
}

struct StateT * slot_60(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v1018 = v1009 + 1;
  v1008->timer = v1018;
  int * v1011 = v1008->regs;
  int v1012 = v1011[10];
  int v1013 = v1011[13];
  int * v1014 = v1008->mem;
  int v1023 = (int)((unsigned int)(v1012 + 32) >> 2);
  v1014[v1023] = v1013;
  struct StateT * v1016 = slot_61(v1008);
  return v1016;
}

struct StateT * slot_4(struct StateT * v76) {
  int v77 = v76->timer;
  int v85 = v77 + 1;
  v76->timer = v85;
  int * v79 = v76->regs;
  int v80 = v79[15];
  int v81 = v79[12];
  int v89 = v80 ^ v81;
  v79[12] = v89;
  struct StateT * v83 = slot_5(v76);
  return v83;
}

struct StateT * slot_18(struct StateT * v265) {
  int v266 = v265->timer;
  int v276 = v266 + 1;
  v265->timer = v276;
  int * v268 = v265->regs;
  int v269 = v268[12];
  bool v279 = v269 == 0;
  struct StateT * v274;
  if (v279) {
    struct StateT * v270 = slot_12(v265);
    v274 = v270;
  } else {
    struct StateT * v272 = slot_19(v265);
    v274 = v272;
  }
  return v274;
}

struct StateT * slot_9(struct StateT * v168) {
  int v169 = v168->timer;
  int v179 = v169 + 1;
  v168->timer = v179;
  int * v171 = v168->regs;
  int v172 = v171[12];
  bool v182 = !(v172 == 0);
  struct StateT * v177;
  if (v182) {
    struct StateT * v173 = slot_16(v168);
    v177 = v173;
  } else {
    struct StateT * v175 = slot_10(v168);
    v177 = v175;
  }
  return v177;
}

struct StateT * slot_11(struct StateT * v245) {
  int v246 = v245->timer;
  int v256 = v246 + 1;
  v245->timer = v256;
  int * v248 = v245->regs;
  int v249 = v248[12];
  bool v259 = !(v249 == 0);
  struct StateT * v254;
  if (v259) {
    struct StateT * v250 = slot_19(v245);
    v254 = v250;
  } else {
    struct StateT * v252 = slot_12(v245);
    v254 = v252;
  }
  return v254;
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
  
  // a10, 10 words: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  // a12, 10 words: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  // a13, 10 words: the address is public
  s1.regs[13] = 120;
  s2.regs[13] = 120;
  // its contents, public: the same draw in both states
  for (int i=0; i<10; i++) {
    int v = bounded(0, 1);
    s1.mem[20 + i] = v;
    s2.mem[20 + i] = v;
  }
  // its contents, public: the same draw in both states
  for (int i=0; i<10; i++) {
    int v = bounded(0, 1);
    s1.mem[30 + i] = v;
    s2.mem[30 + i] = v;
  }
  
  // a10's contents, secret: a different draw in each state. f[0] and
  // f[1] are what the comparisons read, so they draw against
  // 1 and the rest against 20.
  s1.mem[0] = secret(0, 1);
  s2.mem[0] = secret(0, 1);
  s1.mem[1] = secret(0, 1);
  s2.mem[1] = secret(0, 1);
  for (int i=2; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: the value copied in, drawn separately
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