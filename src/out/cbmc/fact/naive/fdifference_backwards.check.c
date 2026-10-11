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

struct StateT * slot_12(struct StateT * v224);
struct StateT * slot_43(struct StateT * v785);
struct StateT * slot_70(struct StateT * v1288);
struct StateT * slot_76(struct StateT * v1390);
struct StateT * slot_6(struct StateT * v116);
struct StateT * slot_47(struct StateT * v858);
struct StateT * slot_29(struct StateT * v530);
struct StateT * slot_55(struct StateT * v1005);
struct StateT * slot_16(struct StateT * v287);
struct StateT * slot_5(struct StateT * v97);
struct StateT * slot_7(struct StateT * v131);
struct StateT * slot_31(struct StateT * v562);
struct StateT * slot_54(struct StateT * v981);
struct StateT * slot_26(struct StateT * v465);
struct StateT * slot_65(struct StateT * v1188);
struct StateT * slot_10(struct StateT * v197);
struct StateT * slot_74(struct StateT * v1352);
struct StateT * slot_19(struct StateT * v344);
struct StateT * slot_58(struct StateT * v1062);
struct StateT * slot_67(struct StateT * v1222);
struct StateT * slot_64(struct StateT * v1169);
struct StateT * slot_14(struct StateT * v256);
struct StateT * slot_53(struct StateT * v965);
struct StateT * slot_44(struct StateT * v801);
struct StateT * slot_66(struct StateT * v1207);
struct StateT * slot_28(struct StateT * v514);
struct StateT * slot_32(struct StateT * v578);
struct StateT * slot_17(struct StateT * v312);
struct StateT * slot_49(struct StateT * v893);
struct StateT * slot_33(struct StateT * v597);
struct StateT * slot_50(struct StateT * v912);
struct StateT * slot_36(struct StateT * v654);
struct StateT * slot_37(struct StateT * v673);
struct StateT * slot_57(struct StateT * v1046);
struct StateT * slot_68(struct StateT * v1238);
struct StateT * slot_59(struct StateT * v1078);
struct StateT * slot_40(struct StateT * v730);
struct StateT * slot_27(struct StateT * v489);
struct StateT * slot_15(struct StateT * v271);
struct StateT * slot_62(struct StateT * v1132);
struct StateT * slot_48(struct StateT * v874);
struct StateT * slot_22(struct StateT * v396);
struct StateT * slot_35(struct StateT * v635);
struct StateT * slot_75(struct StateT * v1371);
struct StateT * slot_56(struct StateT * v1030);
struct StateT * slot_72(struct StateT * v1320);
struct StateT * slot_34(struct StateT * v616);
struct StateT * slot_71(struct StateT * v1304);
struct StateT * slot_51(struct StateT * v931);
struct StateT * slot_52(struct StateT * v950);
struct StateT * slot_25(struct StateT * v449);
struct StateT * slot_23(struct StateT * v415);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_21(struct StateT * v377);
struct StateT * slot_3(struct StateT * v59);
struct StateT * slot_45(struct StateT * v826);
struct StateT * slot_73(struct StateT * v1336);
struct StateT * slot_1(struct StateT * v21);
struct StateT * slot_69(struct StateT * v1263);
struct StateT * slot_13(struct StateT * v240);
struct StateT * slot_38(struct StateT * v692);
struct StateT * slot_63(struct StateT * v1151);
struct StateT * slot_24(struct StateT * v434);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v761);
struct StateT * slot_46(struct StateT * v842);
struct StateT * slot_20(struct StateT * v358);
struct StateT * slot_61(struct StateT * v1113);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v745);
struct StateT * slot_39(struct StateT * v711);
struct StateT * slot_8(struct StateT * v156);
struct StateT * slot_30(struct StateT * v546);
struct StateT * slot_60(struct StateT * v1094);
struct StateT * slot_4(struct StateT * v78);
struct StateT * slot_18(struct StateT * v328);
struct StateT * slot_9(struct StateT * v173);
struct StateT * slot_11(struct StateT * v210);
struct StateT * slot_12(struct StateT * v224) {
  int v225 = v224->timer;
  int v233 = v225 + 1;
  v224->timer = v233;
  int * v227 = v224->regs;
  int v228 = v227[13];
  int v229 = v227[12];
  int v237 = v228 + v229;
  v227[13] = v237;
  struct StateT * v231 = slot_13(v224);
  return v231;
}

struct StateT * slot_43(struct StateT * v785) {
  int v786 = v785->timer;
  int v794 = v786 + 1;
  v785->timer = v794;
  int * v788 = v785->regs;
  int v789 = v788[14];
  int v790 = v788[16];
  int v798 = v789 - v790;
  v788[14] = v798;
  struct StateT * v792 = slot_44(v785);
  return v792;
}

struct StateT * slot_70(struct StateT * v1288) {
  int v1289 = v1288->timer;
  int v1297 = v1289 + 1;
  v1288->timer = v1297;
  int * v1291 = v1288->regs;
  int v1292 = v1291[11];
  int v1293 = v1291[15];
  int v1301 = v1292 - v1293;
  v1291[11] = v1301;
  struct StateT * v1295 = slot_71(v1288);
  return v1295;
}

struct StateT * slot_76(struct StateT * v1390) {
  int v1391 = v1390->timer;
  int v1394 = v1391 + 1;
  v1390->timer = v1394;
  return v1390;
}

struct StateT * slot_6(struct StateT * v116) {
  int v117 = v116->timer;
  int v124 = v117 + 1;
  v116->timer = v124;
  int * v119 = v116->regs;
  int v120 = v119[12];
  int v128 = v120 + -8;
  v119[5] = v128;
  struct StateT * v122 = slot_7(v116);
  return v122;
}

struct StateT * slot_47(struct StateT * v858) {
  int v859 = v858->timer;
  int v867 = v859 + 1;
  v858->timer = v867;
  int * v861 = v858->regs;
  int v862 = v861[13];
  int v863 = v861[16];
  int v871 = v862 - v863;
  v861[13] = v871;
  struct StateT * v865 = slot_48(v858);
  return v865;
}

struct StateT * slot_29(struct StateT * v530) {
  int v531 = v530->timer;
  int v539 = v531 + 1;
  v530->timer = v539;
  int * v533 = v530->regs;
  int v534 = v533[15];
  int v535 = v533[16];
  int v543 = v534 - v535;
  v533[15] = v543;
  struct StateT * v537 = slot_30(v530);
  return v537;
}

struct StateT * slot_55(struct StateT * v1005) {
  int v1006 = v1005->timer;
  int v1018 = v1006 + 1;
  v1005->timer = v1018;
  int * v1008 = v1005->regs;
  int v1009 = v1008[15];
  int v1010 = v1008[17];
  bool v1022 = (v1009 ^ -2147483648) < (v1010 ^ -2147483648);
  int v1013;
  if (v1022) {
    v1013 = 1;
  } else {
    v1013 = 0;
  }
  int * v1014 = v1005->regs;
  v1014[16] = v1013;
  struct StateT * v1016 = slot_56(v1005);
  return v1016;
}

struct StateT * slot_16(struct StateT * v287) {
  int v288 = v287->timer;
  int v300 = v288 + 1;
  v287->timer = v300;
  int * v290 = v287->regs;
  int v291 = v290[15];
  int v292 = v290[7];
  bool v304 = (v291 ^ -2147483648) < (v292 ^ -2147483648);
  int v295;
  if (v304) {
    v295 = 1;
  } else {
    v295 = 0;
  }
  int * v296 = v287->regs;
  v296[5] = v295;
  struct StateT * v298 = slot_17(v287);
  return v298;
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

struct StateT * slot_7(struct StateT * v131) {
  int v132 = v131->timer;
  int v144 = v132 + 1;
  v131->timer = v144;
  int * v134 = v131->regs;
  int v135 = v134[5];
  int v136 = v134[12];
  bool v148 = (v135 ^ -2147483648) < (v136 ^ -2147483648);
  int v139;
  if (v148) {
    v139 = 1;
  } else {
    v139 = 0;
  }
  int * v140 = v131->regs;
  v140[6] = v139;
  struct StateT * v142 = slot_8(v131);
  return v142;
}

struct StateT * slot_31(struct StateT * v562) {
  int v563 = v562->timer;
  int v571 = v563 + 1;
  v562->timer = v571;
  int * v565 = v562->regs;
  int v566 = v565[13];
  int v567 = v565[5];
  int v575 = v566 - v567;
  v565[13] = v575;
  struct StateT * v569 = slot_32(v562);
  return v569;
}

struct StateT * slot_54(struct StateT * v981) {
  int v982 = v981->timer;
  int v994 = v982 + 1;
  v981->timer = v994;
  int * v984 = v981->regs;
  int v985 = v984[15];
  int v986 = v984[13];
  bool v998 = (v985 ^ -2147483648) < (v986 ^ -2147483648);
  int v989;
  if (v998) {
    v989 = 1;
  } else {
    v989 = 0;
  }
  int * v990 = v981->regs;
  v990[13] = v989;
  struct StateT * v992 = slot_55(v981);
  return v992;
}

struct StateT * slot_26(struct StateT * v465) {
  int v466 = v465->timer;
  int v478 = v466 + 1;
  v465->timer = v478;
  int * v468 = v465->regs;
  int v469 = v468[15];
  int v470 = v468[13];
  bool v482 = (v469 ^ -2147483648) < (v470 ^ -2147483648);
  int v473;
  if (v482) {
    v473 = 1;
  } else {
    v473 = 0;
  }
  int * v474 = v465->regs;
  v474[13] = v473;
  struct StateT * v476 = slot_27(v465);
  return v476;
}

struct StateT * slot_65(struct StateT * v1188) {
  int v1189 = v1188->timer;
  int v1198 = v1189 + 1;
  v1188->timer = v1198;
  int * v1191 = v1188->regs;
  int v1192 = v1191[10];
  int * v1193 = v1188->mem;
  int v1202 = (int)((unsigned int)(v1192 + 36) >> 2);
  int v1194 = v1193[v1202];
  v1191[15] = v1194;
  struct StateT * v1196 = slot_66(v1188);
  return v1196;
}

struct StateT * slot_10(struct StateT * v197) {
  int v198 = v197->timer;
  int v204 = v198 + 1;
  v197->timer = v204;
  int * v200 = v197->regs;
  v200[12] = 4194304;
  struct StateT * v202 = slot_11(v197);
  return v202;
}

struct StateT * slot_74(struct StateT * v1352) {
  int v1353 = v1352->timer;
  int v1362 = v1353 + 1;
  v1352->timer = v1362;
  int * v1355 = v1352->regs;
  int v1356 = v1355[10];
  int v1357 = v1355[14];
  int * v1358 = v1352->mem;
  int v1367 = (int)((unsigned int)(v1356 + 32) >> 2);
  v1358[v1367] = v1357;
  struct StateT * v1360 = slot_75(v1352);
  return v1360;
}

struct StateT * slot_19(struct StateT * v344) {
  int v345 = v344->timer;
  int v352 = v345 + 1;
  v344->timer = v352;
  int * v347 = v344->regs;
  int v348 = v347[13];
  int v355 = v348 + -1;
  v347[13] = v355;
  struct StateT * v350 = slot_20(v344);
  return v350;
}

struct StateT * slot_58(struct StateT * v1062) {
  int v1063 = v1062->timer;
  int v1071 = v1063 + 1;
  v1062->timer = v1071;
  int * v1065 = v1062->regs;
  int v1066 = v1065[14];
  int v1067 = v1065[13];
  int v1075 = v1066 + v1067;
  v1065[13] = v1075;
  struct StateT * v1069 = slot_59(v1062);
  return v1069;
}

struct StateT * slot_67(struct StateT * v1222) {
  int v1223 = v1222->timer;
  int v1231 = v1223 + 1;
  v1222->timer = v1231;
  int * v1225 = v1222->regs;
  int v1226 = v1225[11];
  int v1227 = v1225[12];
  int v1235 = v1226 + v1227;
  v1225[11] = v1235;
  struct StateT * v1229 = slot_68(v1222);
  return v1229;
}

struct StateT * slot_64(struct StateT * v1169) {
  int v1170 = v1169->timer;
  int v1179 = v1170 + 1;
  v1169->timer = v1179;
  int * v1172 = v1169->regs;
  int v1173 = v1172[10];
  int * v1174 = v1169->mem;
  int v1183 = (int)((unsigned int)(v1173 + 32) >> 2);
  int v1175 = v1174[v1183];
  v1172[14] = v1175;
  struct StateT * v1177 = slot_65(v1169);
  return v1177;
}

struct StateT * slot_14(struct StateT * v256) {
  int v257 = v256->timer;
  int v264 = v257 + 1;
  v256->timer = v264;
  int * v259 = v256->regs;
  int v260 = v259[7];
  int v268 = v260 + -144;
  v259[15] = v268;
  struct StateT * v262 = slot_15(v256);
  return v262;
}

struct StateT * slot_53(struct StateT * v965) {
  int v966 = v965->timer;
  int v974 = v966 + 1;
  v965->timer = v974;
  int * v968 = v965->regs;
  int v969 = v968[14];
  int v970 = v968[12];
  int v978 = v969 + v970;
  v968[14] = v978;
  struct StateT * v972 = slot_54(v965);
  return v972;
}

struct StateT * slot_44(struct StateT * v801) {
  int v802 = v801->timer;
  int v814 = v802 + 1;
  v801->timer = v814;
  int * v804 = v801->regs;
  int v805 = v804[6];
  int v806 = v804[15];
  bool v818 = (v805 ^ -2147483648) < (v806 ^ -2147483648);
  int v809;
  if (v818) {
    v809 = 1;
  } else {
    v809 = 0;
  }
  int * v810 = v801->regs;
  v810[16] = v809;
  struct StateT * v812 = slot_45(v801);
  return v812;
}

struct StateT * slot_66(struct StateT * v1207) {
  int v1208 = v1207->timer;
  int v1215 = v1208 + 1;
  v1207->timer = v1215;
  int * v1210 = v1207->regs;
  int v1211 = v1210[13];
  int v1219 = v1211 + -8;
  v1210[16] = v1219;
  struct StateT * v1213 = slot_67(v1207);
  return v1213;
}

struct StateT * slot_28(struct StateT * v514) {
  int v515 = v514->timer;
  int v523 = v515 + 1;
  v514->timer = v523;
  int * v517 = v514->regs;
  int v518 = v517[14];
  int v519 = v517[17];
  int v527 = v518 - v519;
  v517[14] = v527;
  struct StateT * v521 = slot_29(v514);
  return v521;
}

struct StateT * slot_32(struct StateT * v578) {
  int v579 = v578->timer;
  int v588 = v579 + 1;
  v578->timer = v588;
  int * v581 = v578->regs;
  int v582 = v581[10];
  int v583 = v581[15];
  int * v584 = v578->mem;
  int v593 = (int)((unsigned int)(v582 + 8) >> 2);
  v584[v593] = v583;
  struct StateT * v586 = slot_33(v578);
  return v586;
}

struct StateT * slot_17(struct StateT * v312) {
  int v313 = v312->timer;
  int v321 = v313 + 1;
  v312->timer = v321;
  int * v315 = v312->regs;
  int v316 = v315[13];
  int v317 = v315[14];
  int v325 = v316 - v317;
  v315[13] = v325;
  struct StateT * v319 = slot_18(v312);
  return v319;
}

struct StateT * slot_49(struct StateT * v893) {
  int v894 = v893->timer;
  int v903 = v894 + 1;
  v893->timer = v903;
  int * v896 = v893->regs;
  int v897 = v896[10];
  int v898 = v896[13];
  int * v899 = v893->mem;
  int v908 = (int)((unsigned int)(v897 + 20) >> 2);
  v899[v908] = v898;
  struct StateT * v901 = slot_50(v893);
  return v901;
}

struct StateT * slot_33(struct StateT * v597) {
  int v598 = v597->timer;
  int v607 = v598 + 1;
  v597->timer = v607;
  int * v600 = v597->regs;
  int v601 = v600[10];
  int v602 = v600[13];
  int * v603 = v597->mem;
  int v612 = (int)((unsigned int)(v601 + 12) >> 2);
  v603[v612] = v602;
  struct StateT * v605 = slot_34(v597);
  return v605;
}

struct StateT * slot_50(struct StateT * v912) {
  int v913 = v912->timer;
  int v922 = v913 + 1;
  v912->timer = v922;
  int * v915 = v912->regs;
  int v916 = v915[11];
  int * v917 = v912->mem;
  int v926 = (int)((unsigned int)(v916 + 24) >> 2);
  int v918 = v917[v926];
  v915[13] = v918;
  struct StateT * v920 = slot_51(v912);
  return v920;
}

struct StateT * slot_36(struct StateT * v654) {
  int v655 = v654->timer;
  int v664 = v655 + 1;
  v654->timer = v664;
  int * v657 = v654->regs;
  int v658 = v657[10];
  int * v659 = v654->mem;
  int v668 = (int)((unsigned int)(v658 + 16) >> 2);
  int v660 = v659[v668];
  v657[15] = v660;
  struct StateT * v662 = slot_37(v654);
  return v662;
}

struct StateT * slot_37(struct StateT * v673) {
  int v674 = v673->timer;
  int v683 = v674 + 1;
  v673->timer = v683;
  int * v676 = v673->regs;
  int v677 = v676[10];
  int * v678 = v673->mem;
  int v687 = (int)((unsigned int)(v677 + 20) >> 2);
  int v679 = v678[v687];
  v676[16] = v679;
  struct StateT * v681 = slot_38(v673);
  return v681;
}

struct StateT * slot_57(struct StateT * v1046) {
  int v1047 = v1046->timer;
  int v1055 = v1047 + 1;
  v1046->timer = v1055;
  int * v1049 = v1046->regs;
  int v1050 = v1049[15];
  int v1051 = v1049[17];
  int v1059 = v1050 - v1051;
  v1049[15] = v1059;
  struct StateT * v1053 = slot_58(v1046);
  return v1053;
}

struct StateT * slot_68(struct StateT * v1238) {
  int v1239 = v1238->timer;
  int v1251 = v1239 + 1;
  v1238->timer = v1251;
  int * v1241 = v1238->regs;
  int v1242 = v1241[16];
  int v1243 = v1241[13];
  bool v1255 = (v1242 ^ -2147483648) < (v1243 ^ -2147483648);
  int v1246;
  if (v1255) {
    v1246 = 1;
  } else {
    v1246 = 0;
  }
  int * v1247 = v1238->regs;
  v1247[12] = v1246;
  struct StateT * v1249 = slot_69(v1238);
  return v1249;
}

struct StateT * slot_59(struct StateT * v1078) {
  int v1079 = v1078->timer;
  int v1087 = v1079 + 1;
  v1078->timer = v1087;
  int * v1081 = v1078->regs;
  int v1082 = v1081[13];
  int v1083 = v1081[16];
  int v1091 = v1082 - v1083;
  v1081[13] = v1091;
  struct StateT * v1085 = slot_60(v1078);
  return v1085;
}

struct StateT * slot_40(struct StateT * v730) {
  int v731 = v730->timer;
  int v738 = v731 + 1;
  v730->timer = v738;
  int * v733 = v730->regs;
  int v734 = v733[13];
  int v742 = v734 + -8;
  v733[6] = v742;
  struct StateT * v736 = slot_41(v730);
  return v736;
}

struct StateT * slot_27(struct StateT * v489) {
  int v490 = v489->timer;
  int v502 = v490 + 1;
  v489->timer = v502;
  int * v492 = v489->regs;
  int v493 = v492[15];
  int v494 = v492[16];
  bool v506 = (v493 ^ -2147483648) < (v494 ^ -2147483648);
  int v497;
  if (v506) {
    v497 = 1;
  } else {
    v497 = 0;
  }
  int * v498 = v489->regs;
  v498[5] = v497;
  struct StateT * v500 = slot_28(v489);
  return v500;
}

struct StateT * slot_15(struct StateT * v271) {
  int v272 = v271->timer;
  int v280 = v272 + 1;
  v271->timer = v280;
  int * v274 = v271->regs;
  int v275 = v274[13];
  int v276 = v274[6];
  int v284 = v275 + v276;
  v274[13] = v284;
  struct StateT * v278 = slot_16(v271);
  return v278;
}

struct StateT * slot_62(struct StateT * v1132) {
  int v1133 = v1132->timer;
  int v1142 = v1133 + 1;
  v1132->timer = v1142;
  int * v1135 = v1132->regs;
  int v1136 = v1135[11];
  int * v1137 = v1132->mem;
  int v1146 = (int)((unsigned int)(v1136 + 32) >> 2);
  int v1138 = v1137[v1146];
  v1135[13] = v1138;
  struct StateT * v1140 = slot_63(v1132);
  return v1140;
}

struct StateT * slot_48(struct StateT * v874) {
  int v875 = v874->timer;
  int v884 = v875 + 1;
  v874->timer = v884;
  int * v877 = v874->regs;
  int v878 = v877[10];
  int v879 = v877[15];
  int * v880 = v874->mem;
  int v889 = (int)((unsigned int)(v878 + 16) >> 2);
  v880[v889] = v879;
  struct StateT * v882 = slot_49(v874);
  return v882;
}

struct StateT * slot_22(struct StateT * v396) {
  int v397 = v396->timer;
  int v406 = v397 + 1;
  v396->timer = v406;
  int * v399 = v396->regs;
  int v400 = v399[11];
  int * v401 = v396->mem;
  int v410 = (int)((unsigned int)(v400 + 8) >> 2);
  int v402 = v401[v410];
  v399[13] = v402;
  struct StateT * v404 = slot_23(v396);
  return v404;
}

struct StateT * slot_35(struct StateT * v635) {
  int v636 = v635->timer;
  int v645 = v636 + 1;
  v635->timer = v645;
  int * v638 = v635->regs;
  int v639 = v638[11];
  int * v640 = v635->mem;
  int v649 = (int)((unsigned int)(v639 + 20) >> 2);
  int v641 = v640[v649];
  v638[14] = v641;
  struct StateT * v643 = slot_36(v635);
  return v643;
}

struct StateT * slot_75(struct StateT * v1371) {
  int v1372 = v1371->timer;
  int v1381 = v1372 + 1;
  v1371->timer = v1381;
  int * v1374 = v1371->regs;
  int v1375 = v1374[10];
  int v1376 = v1374[11];
  int * v1377 = v1371->mem;
  int v1386 = (int)((unsigned int)(v1375 + 36) >> 2);
  v1377[v1386] = v1376;
  struct StateT * v1379 = slot_76(v1371);
  return v1379;
}

struct StateT * slot_56(struct StateT * v1030) {
  int v1031 = v1030->timer;
  int v1039 = v1031 + 1;
  v1030->timer = v1039;
  int * v1033 = v1030->regs;
  int v1034 = v1033[14];
  int v1035 = v1033[5];
  int v1043 = v1034 - v1035;
  v1033[14] = v1043;
  struct StateT * v1037 = slot_57(v1030);
  return v1037;
}

struct StateT * slot_72(struct StateT * v1320) {
  int v1321 = v1320->timer;
  int v1329 = v1321 + 1;
  v1320->timer = v1329;
  int * v1323 = v1320->regs;
  int v1324 = v1323[11];
  int v1325 = v1323[12];
  int v1333 = v1324 + v1325;
  v1323[11] = v1333;
  struct StateT * v1327 = slot_73(v1320);
  return v1327;
}

struct StateT * slot_34(struct StateT * v616) {
  int v617 = v616->timer;
  int v626 = v617 + 1;
  v616->timer = v626;
  int * v619 = v616->regs;
  int v620 = v619[11];
  int * v621 = v616->mem;
  int v630 = (int)((unsigned int)(v620 + 16) >> 2);
  int v622 = v621[v630];
  v619[13] = v622;
  struct StateT * v624 = slot_35(v616);
  return v624;
}

struct StateT * slot_71(struct StateT * v1304) {
  int v1305 = v1304->timer;
  int v1313 = v1305 + 1;
  v1304->timer = v1313;
  int * v1307 = v1304->regs;
  int v1308 = v1307[16];
  int v1309 = v1307[14];
  int v1317 = v1308 - v1309;
  v1307[14] = v1317;
  struct StateT * v1311 = slot_72(v1304);
  return v1311;
}

struct StateT * slot_51(struct StateT * v931) {
  int v932 = v931->timer;
  int v941 = v932 + 1;
  v931->timer = v941;
  int * v934 = v931->regs;
  int v935 = v934[11];
  int * v936 = v931->mem;
  int v945 = (int)((unsigned int)(v935 + 28) >> 2);
  int v937 = v936[v945];
  v934[14] = v937;
  struct StateT * v939 = slot_52(v931);
  return v939;
}

struct StateT * slot_52(struct StateT * v950) {
  int v951 = v950->timer;
  int v958 = v951 + 1;
  v950->timer = v958;
  int * v953 = v950->regs;
  int v954 = v953[13];
  int v962 = v954 + -8;
  v953[15] = v962;
  struct StateT * v956 = slot_53(v950);
  return v956;
}

struct StateT * slot_25(struct StateT * v449) {
  int v450 = v449->timer;
  int v458 = v450 + 1;
  v449->timer = v458;
  int * v452 = v449->regs;
  int v453 = v452[14];
  int v454 = v452[12];
  int v462 = v453 + v454;
  v452[14] = v462;
  struct StateT * v456 = slot_26(v449);
  return v456;
}

struct StateT * slot_23(struct StateT * v415) {
  int v416 = v415->timer;
  int v425 = v416 + 1;
  v415->timer = v425;
  int * v418 = v415->regs;
  int v419 = v418[11];
  int * v420 = v415->mem;
  int v429 = (int)((unsigned int)(v419 + 12) >> 2);
  int v421 = v420[v429];
  v418[14] = v421;
  struct StateT * v423 = slot_24(v415);
  return v423;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v50 = v41 + 1;
  v40->timer = v50;
  int * v43 = v40->regs;
  int v44 = v43[10];
  int * v45 = v40->mem;
  int v54 = (int)((unsigned int)v44 >> 2);
  int v46 = v45[v54];
  v43[14] = v46;
  struct StateT * v48 = slot_3(v40);
  return v48;
}

struct StateT * slot_21(struct StateT * v377) {
  int v378 = v377->timer;
  int v387 = v378 + 1;
  v377->timer = v387;
  int * v380 = v377->regs;
  int v381 = v380[10];
  int v382 = v380[13];
  int * v383 = v377->mem;
  int v392 = (int)((unsigned int)(v381 + 4) >> 2);
  v383[v392] = v382;
  struct StateT * v385 = slot_22(v377);
  return v385;
}

struct StateT * slot_3(struct StateT * v59) {
  int v60 = v59->timer;
  int v69 = v60 + 1;
  v59->timer = v69;
  int * v62 = v59->regs;
  int v63 = v62[10];
  int * v64 = v59->mem;
  int v73 = (int)((unsigned int)(v63 + 4) >> 2);
  int v65 = v64[v73];
  v62[15] = v65;
  struct StateT * v67 = slot_4(v59);
  return v67;
}

struct StateT * slot_45(struct StateT * v826) {
  int v827 = v826->timer;
  int v835 = v827 + 1;
  v826->timer = v835;
  int * v829 = v826->regs;
  int v830 = v829[6];
  int v831 = v829[15];
  int v839 = v830 - v831;
  v829[15] = v839;
  struct StateT * v833 = slot_46(v826);
  return v833;
}

struct StateT * slot_73(struct StateT * v1336) {
  int v1337 = v1336->timer;
  int v1345 = v1337 + 1;
  v1336->timer = v1345;
  int * v1339 = v1336->regs;
  int v1340 = v1339[11];
  int v1341 = v1339[13];
  int v1349 = v1340 - v1341;
  v1339[11] = v1349;
  struct StateT * v1343 = slot_74(v1336);
  return v1343;
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

struct StateT * slot_69(struct StateT * v1263) {
  int v1264 = v1263->timer;
  int v1276 = v1264 + 1;
  v1263->timer = v1276;
  int * v1266 = v1263->regs;
  int v1267 = v1266[16];
  int v1268 = v1266[14];
  bool v1280 = (v1267 ^ -2147483648) < (v1268 ^ -2147483648);
  int v1271;
  if (v1280) {
    v1271 = 1;
  } else {
    v1271 = 0;
  }
  int * v1272 = v1263->regs;
  v1272[13] = v1271;
  struct StateT * v1274 = slot_70(v1263);
  return v1274;
}

struct StateT * slot_13(struct StateT * v240) {
  int v241 = v240->timer;
  int v249 = v241 + 1;
  v240->timer = v249;
  int * v243 = v240->regs;
  int v244 = v243[13];
  int v245 = v243[15];
  int v253 = v244 - v245;
  v243[13] = v253;
  struct StateT * v247 = slot_14(v240);
  return v247;
}

struct StateT * slot_38(struct StateT * v692) {
  int v693 = v692->timer;
  int v702 = v693 + 1;
  v692->timer = v702;
  int * v695 = v692->regs;
  int v696 = v695[10];
  int * v697 = v692->mem;
  int v706 = (int)((unsigned int)(v696 + 24) >> 2);
  int v698 = v697[v706];
  v695[17] = v698;
  struct StateT * v700 = slot_39(v692);
  return v700;
}

struct StateT * slot_63(struct StateT * v1151) {
  int v1152 = v1151->timer;
  int v1161 = v1152 + 1;
  v1151->timer = v1161;
  int * v1154 = v1151->regs;
  int v1155 = v1154[11];
  int * v1156 = v1151->mem;
  int v1165 = (int)((unsigned int)(v1155 + 36) >> 2);
  int v1157 = v1156[v1165];
  v1154[11] = v1157;
  struct StateT * v1159 = slot_64(v1151);
  return v1159;
}

struct StateT * slot_24(struct StateT * v434) {
  int v435 = v434->timer;
  int v442 = v435 + 1;
  v434->timer = v442;
  int * v437 = v434->regs;
  int v438 = v437[13];
  int v446 = v438 + -8;
  v437[15] = v446;
  struct StateT * v440 = slot_25(v434);
  return v440;
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

struct StateT * slot_42(struct StateT * v761) {
  int v762 = v761->timer;
  int v774 = v762 + 1;
  v761->timer = v774;
  int * v764 = v761->regs;
  int v765 = v764[6];
  int v766 = v764[13];
  bool v778 = (v765 ^ -2147483648) < (v766 ^ -2147483648);
  int v769;
  if (v778) {
    v769 = 1;
  } else {
    v769 = 0;
  }
  int * v770 = v761->regs;
  v770[13] = v769;
  struct StateT * v772 = slot_43(v761);
  return v772;
}

struct StateT * slot_46(struct StateT * v842) {
  int v843 = v842->timer;
  int v851 = v843 + 1;
  v842->timer = v851;
  int * v845 = v842->regs;
  int v846 = v845[14];
  int v847 = v845[13];
  int v855 = v846 + v847;
  v845[13] = v855;
  struct StateT * v849 = slot_47(v842);
  return v849;
}

struct StateT * slot_20(struct StateT * v358) {
  int v359 = v358->timer;
  int v368 = v359 + 1;
  v358->timer = v368;
  int * v361 = v358->regs;
  int v362 = v361[10];
  int v363 = v361[15];
  int * v364 = v358->mem;
  int v373 = (int)((unsigned int)v362 >> 2);
  v364[v373] = v363;
  struct StateT * v366 = slot_21(v358);
  return v366;
}

struct StateT * slot_61(struct StateT * v1113) {
  int v1114 = v1113->timer;
  int v1123 = v1114 + 1;
  v1113->timer = v1123;
  int * v1116 = v1113->regs;
  int v1117 = v1116[10];
  int v1118 = v1116[13];
  int * v1119 = v1113->mem;
  int v1128 = (int)((unsigned int)(v1117 + 28) >> 2);
  v1119[v1128] = v1118;
  struct StateT * v1121 = slot_62(v1113);
  return v1121;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v745) {
  int v746 = v745->timer;
  int v754 = v746 + 1;
  v745->timer = v754;
  int * v748 = v745->regs;
  int v749 = v748[14];
  int v750 = v748[12];
  int v758 = v749 + v750;
  v748[14] = v758;
  struct StateT * v752 = slot_42(v745);
  return v752;
}

struct StateT * slot_39(struct StateT * v711) {
  int v712 = v711->timer;
  int v721 = v712 + 1;
  v711->timer = v721;
  int * v714 = v711->regs;
  int v715 = v714[10];
  int * v716 = v711->mem;
  int v725 = (int)((unsigned int)(v715 + 28) >> 2);
  int v717 = v716[v725];
  v714[5] = v717;
  struct StateT * v719 = slot_40(v711);
  return v719;
}

struct StateT * slot_8(struct StateT * v156) {
  int v157 = v156->timer;
  int v165 = v157 + 1;
  v156->timer = v165;
  int * v159 = v156->regs;
  int v160 = v159[5];
  int v161 = v159[14];
  int v170 = v160 - v161;
  v159[7] = v170;
  struct StateT * v163 = slot_9(v156);
  return v163;
}

struct StateT * slot_30(struct StateT * v546) {
  int v547 = v546->timer;
  int v555 = v547 + 1;
  v546->timer = v555;
  int * v549 = v546->regs;
  int v550 = v549[14];
  int v551 = v549[13];
  int v559 = v550 + v551;
  v549[13] = v559;
  struct StateT * v553 = slot_31(v546);
  return v553;
}

struct StateT * slot_60(struct StateT * v1094) {
  int v1095 = v1094->timer;
  int v1104 = v1095 + 1;
  v1094->timer = v1104;
  int * v1097 = v1094->regs;
  int v1098 = v1097[10];
  int v1099 = v1097[15];
  int * v1100 = v1094->mem;
  int v1109 = (int)((unsigned int)(v1098 + 24) >> 2);
  v1100[v1109] = v1099;
  struct StateT * v1102 = slot_61(v1094);
  return v1102;
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

struct StateT * slot_18(struct StateT * v328) {
  int v329 = v328->timer;
  int v337 = v329 + 1;
  v328->timer = v337;
  int * v331 = v328->regs;
  int v332 = v331[13];
  int v333 = v331[5];
  int v341 = v332 + v333;
  v331[13] = v341;
  struct StateT * v335 = slot_19(v328);
  return v335;
}

struct StateT * slot_9(struct StateT * v173) {
  int v174 = v173->timer;
  int v186 = v174 + 1;
  v173->timer = v186;
  int * v176 = v173->regs;
  int v177 = v176[5];
  int v178 = v176[14];
  bool v190 = (v177 ^ -2147483648) < (v178 ^ -2147483648);
  int v181;
  if (v190) {
    v181 = 1;
  } else {
    v181 = 0;
  }
  int * v182 = v173->regs;
  v182[14] = v181;
  struct StateT * v184 = slot_10(v173);
  return v184;
}

struct StateT * slot_11(struct StateT * v210) {
  int v211 = v210->timer;
  int v218 = v211 + 1;
  v210->timer = v218;
  int * v213 = v210->regs;
  int v214 = v213[12];
  int v221 = v214 + -1;
  v213[12] = v221;
  struct StateT * v216 = slot_12(v210);
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