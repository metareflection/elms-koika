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

struct StateT * slot_12(struct StateT * v215);
struct StateT * slot_43(struct StateT * v765);
struct StateT * slot_70(struct StateT * v1242);
struct StateT * slot_76(struct StateT * v1349);
struct StateT * slot_6(struct StateT * v106);
struct StateT * slot_47(struct StateT * v835);
struct StateT * slot_29(struct StateT * v517);
struct StateT * slot_55(struct StateT * v978);
struct StateT * slot_16(struct StateT * v285);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_31(struct StateT * v549);
struct StateT * slot_54(struct StateT * v959);
struct StateT * slot_26(struct StateT * v463);
struct StateT * slot_65(struct StateT * v1153);
struct StateT * slot_10(struct StateT * v182);
struct StateT * slot_74(struct StateT * v1312);
struct StateT * slot_19(struct StateT * v339);
struct StateT * slot_58(struct StateT * v1029);
struct StateT * slot_67(struct StateT * v1188);
struct StateT * slot_81(struct StateT * v1430);
struct StateT * slot_64(struct StateT * v1137);
struct StateT * slot_14(struct StateT * v253);
struct StateT * slot_53(struct StateT * v940);
struct StateT * slot_80(struct StateT * v1416);
struct StateT * slot_44(struct StateT * v781);
struct StateT * slot_66(struct StateT * v1169);
struct StateT * slot_78(struct StateT * v1381);
struct StateT * slot_28(struct StateT * v501);
struct StateT * slot_32(struct StateT * v568);
struct StateT * slot_17(struct StateT * v301);
struct StateT * slot_49(struct StateT * v873);
struct StateT * slot_33(struct StateT * v587);
struct StateT * slot_50(struct StateT * v889);
struct StateT * slot_36(struct StateT * v641);
struct StateT * slot_37(struct StateT * v657);
struct StateT * slot_57(struct StateT * v1013);
struct StateT * slot_68(struct StateT * v1207);
struct StateT * slot_59(struct StateT * v1045);
struct StateT * slot_40(struct StateT * v711);
struct StateT * slot_27(struct StateT * v482);
struct StateT * slot_15(struct StateT * v269);
struct StateT * slot_62(struct StateT * v1102);
struct StateT * slot_48(struct StateT * v854);
struct StateT * slot_77(struct StateT * v1365);
struct StateT * slot_22(struct StateT * v393);
struct StateT * slot_35(struct StateT * v625);
struct StateT * slot_75(struct StateT * v1330);
struct StateT * slot_56(struct StateT * v997);
struct StateT * slot_72(struct StateT * v1274);
struct StateT * slot_34(struct StateT * v606);
struct StateT * slot_71(struct StateT * v1258);
struct StateT * slot_51(struct StateT * v905);
struct StateT * slot_52(struct StateT * v921);
struct StateT * slot_25(struct StateT * v444);
struct StateT * slot_23(struct StateT * v409);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_21(struct StateT * v377);
struct StateT * slot_3(struct StateT * v53);
struct StateT * slot_45(struct StateT * v797);
struct StateT * slot_73(struct StateT * v1293);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_69(struct StateT * v1226);
struct StateT * slot_13(struct StateT * v234);
struct StateT * slot_38(struct StateT * v673);
struct StateT * slot_63(struct StateT * v1121);
struct StateT * slot_24(struct StateT * v425);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v749);
struct StateT * slot_46(struct StateT * v816);
struct StateT * slot_20(struct StateT * v358);
struct StateT * slot_61(struct StateT * v1083);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_79(struct StateT * v1397);
struct StateT * slot_41(struct StateT * v730);
struct StateT * slot_39(struct StateT * v692);
struct StateT * slot_8(struct StateT * v144);
struct StateT * slot_30(struct StateT * v533);
struct StateT * slot_60(struct StateT * v1064);
struct StateT * slot_4(struct StateT * v72);
struct StateT * slot_18(struct StateT * v320);
struct StateT * slot_9(struct StateT * v166);
struct StateT * slot_11(struct StateT * v196);
struct StateT * slot_12(struct StateT * v215) {
  int v216 = v215->timer;
  int v225 = v216 + 1;
  v215->timer = v225;
  int * v218 = v215->regs;
  int v219 = v218[11];
  int * v220 = v215->mem;
  int v229 = (int)((unsigned int)v219 >> 2);
  int v221 = v220[v229];
  v218[12] = v221;
  struct StateT * v223 = slot_13(v215);
  return v223;
}

struct StateT * slot_43(struct StateT * v765) {
  int v766 = v765->timer;
  int v774 = v766 + 1;
  v765->timer = v774;
  int * v768 = v765->regs;
  int v769 = v768[12];
  int v770 = v768[13];
  int v778 = v769 & v770;
  v768[12] = v778;
  struct StateT * v772 = slot_44(v765);
  return v772;
}

struct StateT * slot_70(struct StateT * v1242) {
  int v1243 = v1242->timer;
  int v1251 = v1243 + 1;
  v1242->timer = v1251;
  int * v1245 = v1242->regs;
  int v1246 = v1245[12];
  int v1247 = v1245[13];
  int v1255 = v1246 & v1247;
  v1245[12] = v1255;
  struct StateT * v1249 = slot_71(v1242);
  return v1249;
}

struct StateT * slot_76(struct StateT * v1349) {
  int v1350 = v1349->timer;
  int v1358 = v1350 + 1;
  v1349->timer = v1358;
  int * v1352 = v1349->regs;
  int v1353 = v1352[11];
  int v1354 = v1352[12];
  int v1362 = v1353 ^ v1354;
  v1352[11] = v1362;
  struct StateT * v1356 = slot_77(v1349);
  return v1356;
}

struct StateT * slot_6(struct StateT * v106) {
  int v107 = v106->timer;
  int v115 = v107 + 1;
  v106->timer = v115;
  int * v109 = v106->regs;
  int v110 = v109[15];
  int v111 = v109[13];
  int v119 = v110 ^ v111;
  v109[13] = v119;
  struct StateT * v113 = slot_7(v106);
  return v113;
}

struct StateT * slot_47(struct StateT * v835) {
  int v836 = v835->timer;
  int v845 = v836 + 1;
  v835->timer = v845;
  int * v838 = v835->regs;
  int v839 = v838[2];
  int * v840 = v835->mem;
  int v849 = (int)((unsigned int)(v839 + 12) >> 2);
  int v841 = v840[v849];
  v838[13] = v841;
  struct StateT * v843 = slot_48(v835);
  return v843;
}

struct StateT * slot_29(struct StateT * v517) {
  int v518 = v517->timer;
  int v526 = v518 + 1;
  v517->timer = v526;
  int * v520 = v517->regs;
  int v521 = v520[12];
  int v522 = v520[13];
  int v530 = v521 & v522;
  v520[12] = v530;
  struct StateT * v524 = slot_30(v517);
  return v524;
}

struct StateT * slot_55(struct StateT * v978) {
  int v979 = v978->timer;
  int v988 = v979 + 1;
  v978->timer = v988;
  int * v981 = v978->regs;
  int v982 = v981[10];
  int * v983 = v978->mem;
  int v992 = (int)((unsigned int)(v982 + 28) >> 2);
  int v984 = v983[v992];
  v981[15] = v984;
  struct StateT * v986 = slot_56(v978);
  return v986;
}

struct StateT * slot_16(struct StateT * v285) {
  int v286 = v285->timer;
  int v294 = v286 + 1;
  v285->timer = v294;
  int * v288 = v285->regs;
  int v289 = v288[12];
  int v290 = v288[14];
  int v298 = v289 ^ v290;
  v288[12] = v298;
  struct StateT * v292 = slot_17(v285);
  return v292;
}

struct StateT * slot_5(struct StateT * v90) {
  int v91 = v90->timer;
  int v99 = v91 + 1;
  v90->timer = v99;
  int * v93 = v90->regs;
  int v94 = v93[14];
  int v95 = v93[12];
  int v103 = v94 ^ v95;
  v93[12] = v103;
  struct StateT * v97 = slot_6(v90);
  return v97;
}

struct StateT * slot_7(struct StateT * v122) {
  int v123 = v122->timer;
  int v134 = v123 + 1;
  v122->timer = v134;
  int * v125 = v122->regs;
  int v126 = v125[12];
  bool v137 = -2147483648 < (v126 ^ -2147483648);
  int v129;
  if (v137) {
    v129 = 1;
  } else {
    v129 = 0;
  }
  int * v130 = v122->regs;
  v130[12] = v129;
  struct StateT * v132 = slot_8(v122);
  return v132;
}

struct StateT * slot_31(struct StateT * v549) {
  int v550 = v549->timer;
  int v559 = v550 + 1;
  v549->timer = v559;
  int * v552 = v549->regs;
  int v553 = v552[10];
  int v554 = v552[12];
  int * v555 = v549->mem;
  int v564 = (int)((unsigned int)(v553 + 8) >> 2);
  v555[v564] = v554;
  struct StateT * v557 = slot_32(v549);
  return v557;
}

struct StateT * slot_54(struct StateT * v959) {
  int v960 = v959->timer;
  int v969 = v960 + 1;
  v959->timer = v969;
  int * v962 = v959->regs;
  int v963 = v962[2];
  int * v964 = v959->mem;
  int v973 = (int)((unsigned int)(v963 + 12) >> 2);
  int v965 = v964[v973];
  v962[13] = v965;
  struct StateT * v967 = slot_55(v959);
  return v967;
}

struct StateT * slot_26(struct StateT * v463) {
  int v464 = v463->timer;
  int v473 = v464 + 1;
  v463->timer = v473;
  int * v466 = v463->regs;
  int v467 = v466[2];
  int * v468 = v463->mem;
  int v477 = (int)((unsigned int)(v467 + 12) >> 2);
  int v469 = v468[v477];
  v466[13] = v469;
  struct StateT * v471 = slot_27(v463);
  return v471;
}

struct StateT * slot_65(struct StateT * v1153) {
  int v1154 = v1153->timer;
  int v1162 = v1154 + 1;
  v1153->timer = v1162;
  int * v1156 = v1153->regs;
  int v1157 = v1156[12];
  int v1158 = v1156[15];
  int v1166 = v1157 ^ v1158;
  v1156[12] = v1166;
  struct StateT * v1160 = slot_66(v1153);
  return v1160;
}

struct StateT * slot_10(struct StateT * v182) {
  int v183 = v182->timer;
  int v190 = v183 + 1;
  v182->timer = v190;
  int * v185 = v182->regs;
  int v186 = v185[12];
  int v193 = -v186;
  v185[12] = v193;
  struct StateT * v188 = slot_11(v182);
  return v188;
}

struct StateT * slot_74(struct StateT * v1312) {
  int v1313 = v1312->timer;
  int v1322 = v1313 + 1;
  v1312->timer = v1322;
  int * v1315 = v1312->regs;
  int v1316 = v1315[11];
  int * v1317 = v1312->mem;
  int v1326 = (int)((unsigned int)(v1316 + 36) >> 2);
  int v1318 = v1317[v1326];
  v1315[11] = v1318;
  struct StateT * v1320 = slot_75(v1312);
  return v1320;
}

struct StateT * slot_19(struct StateT * v339) {
  int v340 = v339->timer;
  int v349 = v340 + 1;
  v339->timer = v349;
  int * v342 = v339->regs;
  int v343 = v342[2];
  int * v344 = v339->mem;
  int v353 = (int)((unsigned int)(v343 + 12) >> 2);
  int v345 = v344[v353];
  v342[13] = v345;
  struct StateT * v347 = slot_20(v339);
  return v347;
}

struct StateT * slot_58(struct StateT * v1029) {
  int v1030 = v1029->timer;
  int v1038 = v1030 + 1;
  v1029->timer = v1038;
  int * v1032 = v1029->regs;
  int v1033 = v1032[12];
  int v1034 = v1032[14];
  int v1042 = v1033 ^ v1034;
  v1032[12] = v1042;
  struct StateT * v1036 = slot_59(v1029);
  return v1036;
}

struct StateT * slot_67(struct StateT * v1188) {
  int v1189 = v1188->timer;
  int v1198 = v1189 + 1;
  v1188->timer = v1198;
  int * v1191 = v1188->regs;
  int v1192 = v1191[11];
  int * v1193 = v1188->mem;
  int v1202 = (int)((unsigned int)(v1192 + 32) >> 2);
  int v1194 = v1193[v1202];
  v1191[12] = v1194;
  struct StateT * v1196 = slot_68(v1188);
  return v1196;
}

struct StateT * slot_81(struct StateT * v1430) {
  int v1431 = v1430->timer;
  int v1434 = v1431 + 1;
  v1430->timer = v1434;
  return v1430;
}

struct StateT * slot_64(struct StateT * v1137) {
  int v1138 = v1137->timer;
  int v1146 = v1138 + 1;
  v1137->timer = v1146;
  int * v1140 = v1137->regs;
  int v1141 = v1140[12];
  int v1142 = v1140[13];
  int v1150 = v1141 & v1142;
  v1140[12] = v1150;
  struct StateT * v1144 = slot_65(v1137);
  return v1144;
}

struct StateT * slot_14(struct StateT * v253) {
  int v254 = v253->timer;
  int v262 = v254 + 1;
  v253->timer = v262;
  int * v256 = v253->regs;
  int v257 = v256[12];
  int v258 = v256[14];
  int v266 = v257 ^ v258;
  v256[12] = v266;
  struct StateT * v260 = slot_15(v253);
  return v260;
}

struct StateT * slot_53(struct StateT * v940) {
  int v941 = v940->timer;
  int v950 = v941 + 1;
  v940->timer = v950;
  int * v943 = v940->regs;
  int v944 = v943[11];
  int * v945 = v940->mem;
  int v954 = (int)((unsigned int)(v944 + 24) >> 2);
  int v946 = v945[v954];
  v943[12] = v946;
  struct StateT * v948 = slot_54(v940);
  return v948;
}

struct StateT * slot_80(struct StateT * v1416) {
  int v1417 = v1416->timer;
  int v1424 = v1417 + 1;
  v1416->timer = v1424;
  int * v1419 = v1416->regs;
  int v1420 = v1419[2];
  int v1427 = v1420 + 16;
  v1419[2] = v1427;
  struct StateT * v1422 = slot_81(v1416);
  return v1422;
}

struct StateT * slot_44(struct StateT * v781) {
  int v782 = v781->timer;
  int v790 = v782 + 1;
  v781->timer = v790;
  int * v784 = v781->regs;
  int v785 = v784[12];
  int v786 = v784[14];
  int v794 = v785 ^ v786;
  v784[12] = v794;
  struct StateT * v788 = slot_45(v781);
  return v788;
}

struct StateT * slot_66(struct StateT * v1169) {
  int v1170 = v1169->timer;
  int v1179 = v1170 + 1;
  v1169->timer = v1179;
  int * v1172 = v1169->regs;
  int v1173 = v1172[10];
  int v1174 = v1172[12];
  int * v1175 = v1169->mem;
  int v1184 = (int)((unsigned int)(v1173 + 28) >> 2);
  v1175[v1184] = v1174;
  struct StateT * v1177 = slot_67(v1169);
  return v1177;
}

struct StateT * slot_78(struct StateT * v1381) {
  int v1382 = v1381->timer;
  int v1390 = v1382 + 1;
  v1381->timer = v1390;
  int * v1384 = v1381->regs;
  int v1385 = v1384[11];
  int v1386 = v1384[12];
  int v1394 = v1385 ^ v1386;
  v1384[11] = v1394;
  struct StateT * v1388 = slot_79(v1381);
  return v1388;
}

struct StateT * slot_28(struct StateT * v501) {
  int v502 = v501->timer;
  int v510 = v502 + 1;
  v501->timer = v510;
  int * v504 = v501->regs;
  int v505 = v504[12];
  int v506 = v504[14];
  int v514 = v505 ^ v506;
  v504[12] = v514;
  struct StateT * v508 = slot_29(v501);
  return v508;
}

struct StateT * slot_32(struct StateT * v568) {
  int v569 = v568->timer;
  int v578 = v569 + 1;
  v568->timer = v578;
  int * v571 = v568->regs;
  int v572 = v571[11];
  int * v573 = v568->mem;
  int v582 = (int)((unsigned int)(v572 + 12) >> 2);
  int v574 = v573[v582];
  v571[12] = v574;
  struct StateT * v576 = slot_33(v568);
  return v576;
}

struct StateT * slot_17(struct StateT * v301) {
  int v302 = v301->timer;
  int v311 = v302 + 1;
  v301->timer = v311;
  int * v304 = v301->regs;
  int v305 = v304[10];
  int v306 = v304[12];
  int * v307 = v301->mem;
  int v316 = (int)((unsigned int)v305 >> 2);
  v307[v316] = v306;
  struct StateT * v309 = slot_18(v301);
  return v309;
}

struct StateT * slot_49(struct StateT * v873) {
  int v874 = v873->timer;
  int v882 = v874 + 1;
  v873->timer = v882;
  int * v876 = v873->regs;
  int v877 = v876[12];
  int v878 = v876[15];
  int v886 = v877 ^ v878;
  v876[12] = v886;
  struct StateT * v880 = slot_50(v873);
  return v880;
}

struct StateT * slot_33(struct StateT * v587) {
  int v588 = v587->timer;
  int v597 = v588 + 1;
  v587->timer = v597;
  int * v590 = v587->regs;
  int v591 = v590[2];
  int * v592 = v587->mem;
  int v601 = (int)((unsigned int)(v591 + 12) >> 2);
  int v593 = v592[v601];
  v590[13] = v593;
  struct StateT * v595 = slot_34(v587);
  return v595;
}

struct StateT * slot_50(struct StateT * v889) {
  int v890 = v889->timer;
  int v898 = v890 + 1;
  v889->timer = v898;
  int * v892 = v889->regs;
  int v893 = v892[12];
  int v894 = v892[13];
  int v902 = v893 & v894;
  v892[12] = v902;
  struct StateT * v896 = slot_51(v889);
  return v896;
}

struct StateT * slot_36(struct StateT * v641) {
  int v642 = v641->timer;
  int v650 = v642 + 1;
  v641->timer = v650;
  int * v644 = v641->regs;
  int v645 = v644[12];
  int v646 = v644[13];
  int v654 = v645 & v646;
  v644[12] = v654;
  struct StateT * v648 = slot_37(v641);
  return v648;
}

struct StateT * slot_37(struct StateT * v657) {
  int v658 = v657->timer;
  int v666 = v658 + 1;
  v657->timer = v666;
  int * v660 = v657->regs;
  int v661 = v660[12];
  int v662 = v660[15];
  int v670 = v661 ^ v662;
  v660[12] = v670;
  struct StateT * v664 = slot_38(v657);
  return v664;
}

struct StateT * slot_57(struct StateT * v1013) {
  int v1014 = v1013->timer;
  int v1022 = v1014 + 1;
  v1013->timer = v1022;
  int * v1016 = v1013->regs;
  int v1017 = v1016[12];
  int v1018 = v1016[13];
  int v1026 = v1017 & v1018;
  v1016[12] = v1026;
  struct StateT * v1020 = slot_58(v1013);
  return v1020;
}

struct StateT * slot_68(struct StateT * v1207) {
  int v1208 = v1207->timer;
  int v1217 = v1208 + 1;
  v1207->timer = v1217;
  int * v1210 = v1207->regs;
  int v1211 = v1210[2];
  int * v1212 = v1207->mem;
  int v1221 = (int)((unsigned int)(v1211 + 12) >> 2);
  int v1213 = v1212[v1221];
  v1210[13] = v1213;
  struct StateT * v1215 = slot_69(v1207);
  return v1215;
}

struct StateT * slot_59(struct StateT * v1045) {
  int v1046 = v1045->timer;
  int v1055 = v1046 + 1;
  v1045->timer = v1055;
  int * v1048 = v1045->regs;
  int v1049 = v1048[10];
  int v1050 = v1048[12];
  int * v1051 = v1045->mem;
  int v1060 = (int)((unsigned int)(v1049 + 24) >> 2);
  v1051[v1060] = v1050;
  struct StateT * v1053 = slot_60(v1045);
  return v1053;
}

struct StateT * slot_40(struct StateT * v711) {
  int v712 = v711->timer;
  int v721 = v712 + 1;
  v711->timer = v721;
  int * v714 = v711->regs;
  int v715 = v714[2];
  int * v716 = v711->mem;
  int v725 = (int)((unsigned int)(v715 + 12) >> 2);
  int v717 = v716[v725];
  v714[13] = v717;
  struct StateT * v719 = slot_41(v711);
  return v719;
}

struct StateT * slot_27(struct StateT * v482) {
  int v483 = v482->timer;
  int v492 = v483 + 1;
  v482->timer = v492;
  int * v485 = v482->regs;
  int v486 = v485[10];
  int * v487 = v482->mem;
  int v496 = (int)((unsigned int)(v486 + 12) >> 2);
  int v488 = v487[v496];
  v485[15] = v488;
  struct StateT * v490 = slot_28(v482);
  return v490;
}

struct StateT * slot_15(struct StateT * v269) {
  int v270 = v269->timer;
  int v278 = v270 + 1;
  v269->timer = v278;
  int * v272 = v269->regs;
  int v273 = v272[12];
  int v274 = v272[13];
  int v282 = v273 & v274;
  v272[12] = v282;
  struct StateT * v276 = slot_16(v269);
  return v276;
}

struct StateT * slot_62(struct StateT * v1102) {
  int v1103 = v1102->timer;
  int v1112 = v1103 + 1;
  v1102->timer = v1112;
  int * v1105 = v1102->regs;
  int v1106 = v1105[10];
  int * v1107 = v1102->mem;
  int v1116 = (int)((unsigned int)(v1106 + 32) >> 2);
  int v1108 = v1107[v1116];
  v1105[14] = v1108;
  struct StateT * v1110 = slot_63(v1102);
  return v1110;
}

struct StateT * slot_48(struct StateT * v854) {
  int v855 = v854->timer;
  int v864 = v855 + 1;
  v854->timer = v864;
  int * v857 = v854->regs;
  int v858 = v857[10];
  int * v859 = v854->mem;
  int v868 = (int)((unsigned int)(v858 + 24) >> 2);
  int v860 = v859[v868];
  v857[14] = v860;
  struct StateT * v862 = slot_49(v854);
  return v862;
}

struct StateT * slot_77(struct StateT * v1365) {
  int v1366 = v1365->timer;
  int v1374 = v1366 + 1;
  v1365->timer = v1374;
  int * v1368 = v1365->regs;
  int v1369 = v1368[11];
  int v1370 = v1368[13];
  int v1378 = v1369 & v1370;
  v1368[11] = v1378;
  struct StateT * v1372 = slot_78(v1365);
  return v1372;
}

struct StateT * slot_22(struct StateT * v393) {
  int v394 = v393->timer;
  int v402 = v394 + 1;
  v393->timer = v402;
  int * v396 = v393->regs;
  int v397 = v396[12];
  int v398 = v396[13];
  int v406 = v397 & v398;
  v396[12] = v406;
  struct StateT * v400 = slot_23(v393);
  return v400;
}

struct StateT * slot_35(struct StateT * v625) {
  int v626 = v625->timer;
  int v634 = v626 + 1;
  v625->timer = v634;
  int * v628 = v625->regs;
  int v629 = v628[12];
  int v630 = v628[15];
  int v638 = v629 ^ v630;
  v628[12] = v638;
  struct StateT * v632 = slot_36(v625);
  return v632;
}

struct StateT * slot_75(struct StateT * v1330) {
  int v1331 = v1330->timer;
  int v1340 = v1331 + 1;
  v1330->timer = v1340;
  int * v1333 = v1330->regs;
  int v1334 = v1333[2];
  int * v1335 = v1330->mem;
  int v1344 = (int)((unsigned int)(v1334 + 12) >> 2);
  int v1336 = v1335[v1344];
  v1333[13] = v1336;
  struct StateT * v1338 = slot_76(v1330);
  return v1338;
}

struct StateT * slot_56(struct StateT * v997) {
  int v998 = v997->timer;
  int v1006 = v998 + 1;
  v997->timer = v1006;
  int * v1000 = v997->regs;
  int v1001 = v1000[12];
  int v1002 = v1000[14];
  int v1010 = v1001 ^ v1002;
  v1000[12] = v1010;
  struct StateT * v1004 = slot_57(v997);
  return v1004;
}

struct StateT * slot_72(struct StateT * v1274) {
  int v1275 = v1274->timer;
  int v1284 = v1275 + 1;
  v1274->timer = v1284;
  int * v1277 = v1274->regs;
  int v1278 = v1277[10];
  int v1279 = v1277[12];
  int * v1280 = v1274->mem;
  int v1289 = (int)((unsigned int)(v1278 + 32) >> 2);
  v1280[v1289] = v1279;
  struct StateT * v1282 = slot_73(v1274);
  return v1282;
}

struct StateT * slot_34(struct StateT * v606) {
  int v607 = v606->timer;
  int v616 = v607 + 1;
  v606->timer = v616;
  int * v609 = v606->regs;
  int v610 = v609[10];
  int * v611 = v606->mem;
  int v620 = (int)((unsigned int)(v610 + 16) >> 2);
  int v612 = v611[v620];
  v609[14] = v612;
  struct StateT * v614 = slot_35(v606);
  return v614;
}

struct StateT * slot_71(struct StateT * v1258) {
  int v1259 = v1258->timer;
  int v1267 = v1259 + 1;
  v1258->timer = v1267;
  int * v1261 = v1258->regs;
  int v1262 = v1261[12];
  int v1263 = v1261[14];
  int v1271 = v1262 ^ v1263;
  v1261[12] = v1271;
  struct StateT * v1265 = slot_72(v1258);
  return v1265;
}

struct StateT * slot_51(struct StateT * v905) {
  int v906 = v905->timer;
  int v914 = v906 + 1;
  v905->timer = v914;
  int * v908 = v905->regs;
  int v909 = v908[12];
  int v910 = v908[15];
  int v918 = v909 ^ v910;
  v908[12] = v918;
  struct StateT * v912 = slot_52(v905);
  return v912;
}

struct StateT * slot_52(struct StateT * v921) {
  int v922 = v921->timer;
  int v931 = v922 + 1;
  v921->timer = v931;
  int * v924 = v921->regs;
  int v925 = v924[10];
  int v926 = v924[12];
  int * v927 = v921->mem;
  int v936 = (int)((unsigned int)(v925 + 20) >> 2);
  v927[v936] = v926;
  struct StateT * v929 = slot_53(v921);
  return v929;
}

struct StateT * slot_25(struct StateT * v444) {
  int v445 = v444->timer;
  int v454 = v445 + 1;
  v444->timer = v454;
  int * v447 = v444->regs;
  int v448 = v447[11];
  int * v449 = v444->mem;
  int v458 = (int)((unsigned int)(v448 + 8) >> 2);
  int v450 = v449[v458];
  v447[12] = v450;
  struct StateT * v452 = slot_26(v444);
  return v452;
}

struct StateT * slot_23(struct StateT * v409) {
  int v410 = v409->timer;
  int v418 = v410 + 1;
  v409->timer = v418;
  int * v412 = v409->regs;
  int v413 = v412[12];
  int v414 = v412[15];
  int v422 = v413 ^ v414;
  v412[12] = v422;
  struct StateT * v416 = slot_24(v409);
  return v416;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v44 = v35 + 1;
  v34->timer = v44;
  int * v37 = v34->regs;
  int v38 = v37[10];
  int * v39 = v34->mem;
  int v48 = (int)((unsigned int)v38 >> 2);
  int v40 = v39[v48];
  v37[14] = v40;
  struct StateT * v42 = slot_3(v34);
  return v42;
}

struct StateT * slot_21(struct StateT * v377) {
  int v378 = v377->timer;
  int v386 = v378 + 1;
  v377->timer = v386;
  int * v380 = v377->regs;
  int v381 = v380[12];
  int v382 = v380[15];
  int v390 = v381 ^ v382;
  v380[12] = v390;
  struct StateT * v384 = slot_22(v377);
  return v384;
}

struct StateT * slot_3(struct StateT * v53) {
  int v54 = v53->timer;
  int v63 = v54 + 1;
  v53->timer = v63;
  int * v56 = v53->regs;
  int v57 = v56[10];
  int * v58 = v53->mem;
  int v67 = (int)((unsigned int)(v57 + 4) >> 2);
  int v59 = v58[v67];
  v56[15] = v59;
  struct StateT * v61 = slot_4(v53);
  return v61;
}

struct StateT * slot_45(struct StateT * v797) {
  int v798 = v797->timer;
  int v807 = v798 + 1;
  v797->timer = v807;
  int * v800 = v797->regs;
  int v801 = v800[10];
  int v802 = v800[12];
  int * v803 = v797->mem;
  int v812 = (int)((unsigned int)(v801 + 16) >> 2);
  v803[v812] = v802;
  struct StateT * v805 = slot_46(v797);
  return v805;
}

struct StateT * slot_73(struct StateT * v1293) {
  int v1294 = v1293->timer;
  int v1303 = v1294 + 1;
  v1293->timer = v1303;
  int * v1296 = v1293->regs;
  int v1297 = v1296[10];
  int * v1298 = v1293->mem;
  int v1307 = (int)((unsigned int)(v1297 + 36) >> 2);
  int v1299 = v1298[v1307];
  v1296[12] = v1299;
  struct StateT * v1301 = slot_74(v1293);
  return v1301;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v26 = v17 + 1;
  v16->timer = v26;
  int * v19 = v16->regs;
  int v20 = v19[12];
  int * v21 = v16->mem;
  int v30 = (int)((unsigned int)v20 >> 2);
  int v22 = v21[v30];
  v19[12] = v22;
  struct StateT * v24 = slot_2(v16);
  return v24;
}

struct StateT * slot_69(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1235 = v1227 + 1;
  v1226->timer = v1235;
  int * v1229 = v1226->regs;
  int v1230 = v1229[12];
  int v1231 = v1229[14];
  int v1239 = v1230 ^ v1231;
  v1229[12] = v1239;
  struct StateT * v1233 = slot_70(v1226);
  return v1233;
}

struct StateT * slot_13(struct StateT * v234) {
  int v235 = v234->timer;
  int v244 = v235 + 1;
  v234->timer = v244;
  int * v237 = v234->regs;
  int v238 = v237[2];
  int * v239 = v234->mem;
  int v248 = (int)((unsigned int)(v238 + 12) >> 2);
  int v240 = v239[v248];
  v237[13] = v240;
  struct StateT * v242 = slot_14(v234);
  return v242;
}

struct StateT * slot_38(struct StateT * v673) {
  int v674 = v673->timer;
  int v683 = v674 + 1;
  v673->timer = v683;
  int * v676 = v673->regs;
  int v677 = v676[10];
  int v678 = v676[12];
  int * v679 = v673->mem;
  int v688 = (int)((unsigned int)(v677 + 12) >> 2);
  v679[v688] = v678;
  struct StateT * v681 = slot_39(v673);
  return v681;
}

struct StateT * slot_63(struct StateT * v1121) {
  int v1122 = v1121->timer;
  int v1130 = v1122 + 1;
  v1121->timer = v1130;
  int * v1124 = v1121->regs;
  int v1125 = v1124[12];
  int v1126 = v1124[15];
  int v1134 = v1125 ^ v1126;
  v1124[12] = v1134;
  struct StateT * v1128 = slot_64(v1121);
  return v1128;
}

struct StateT * slot_24(struct StateT * v425) {
  int v426 = v425->timer;
  int v435 = v426 + 1;
  v425->timer = v435;
  int * v428 = v425->regs;
  int v429 = v428[10];
  int v430 = v428[12];
  int * v431 = v425->mem;
  int v440 = (int)((unsigned int)(v429 + 4) >> 2);
  v431[v440] = v430;
  struct StateT * v433 = slot_25(v425);
  return v433;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -16;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_42(struct StateT * v749) {
  int v750 = v749->timer;
  int v758 = v750 + 1;
  v749->timer = v758;
  int * v752 = v749->regs;
  int v753 = v752[12];
  int v754 = v752[14];
  int v762 = v753 ^ v754;
  v752[12] = v762;
  struct StateT * v756 = slot_43(v749);
  return v756;
}

struct StateT * slot_46(struct StateT * v816) {
  int v817 = v816->timer;
  int v826 = v817 + 1;
  v816->timer = v826;
  int * v819 = v816->regs;
  int v820 = v819[11];
  int * v821 = v816->mem;
  int v830 = (int)((unsigned int)(v820 + 20) >> 2);
  int v822 = v821[v830];
  v819[12] = v822;
  struct StateT * v824 = slot_47(v816);
  return v824;
}

struct StateT * slot_20(struct StateT * v358) {
  int v359 = v358->timer;
  int v368 = v359 + 1;
  v358->timer = v368;
  int * v361 = v358->regs;
  int v362 = v361[10];
  int * v363 = v358->mem;
  int v372 = (int)((unsigned int)(v362 + 8) >> 2);
  int v364 = v363[v372];
  v361[14] = v364;
  struct StateT * v366 = slot_21(v358);
  return v366;
}

struct StateT * slot_61(struct StateT * v1083) {
  int v1084 = v1083->timer;
  int v1093 = v1084 + 1;
  v1083->timer = v1093;
  int * v1086 = v1083->regs;
  int v1087 = v1086[2];
  int * v1088 = v1083->mem;
  int v1097 = (int)((unsigned int)(v1087 + 12) >> 2);
  int v1089 = v1088[v1097];
  v1086[13] = v1089;
  struct StateT * v1091 = slot_62(v1083);
  return v1091;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_79(struct StateT * v1397) {
  int v1398 = v1397->timer;
  int v1407 = v1398 + 1;
  v1397->timer = v1407;
  int * v1400 = v1397->regs;
  int v1401 = v1400[10];
  int v1402 = v1400[11];
  int * v1403 = v1397->mem;
  int v1412 = (int)((unsigned int)(v1401 + 36) >> 2);
  v1403[v1412] = v1402;
  struct StateT * v1405 = slot_80(v1397);
  return v1405;
}

struct StateT * slot_41(struct StateT * v730) {
  int v731 = v730->timer;
  int v740 = v731 + 1;
  v730->timer = v740;
  int * v733 = v730->regs;
  int v734 = v733[10];
  int * v735 = v730->mem;
  int v744 = (int)((unsigned int)(v734 + 20) >> 2);
  int v736 = v735[v744];
  v733[15] = v736;
  struct StateT * v738 = slot_42(v730);
  return v738;
}

struct StateT * slot_39(struct StateT * v692) {
  int v693 = v692->timer;
  int v702 = v693 + 1;
  v692->timer = v702;
  int * v695 = v692->regs;
  int v696 = v695[11];
  int * v697 = v692->mem;
  int v706 = (int)((unsigned int)(v696 + 16) >> 2);
  int v698 = v697[v706];
  v695[12] = v698;
  struct StateT * v700 = slot_40(v692);
  return v700;
}

struct StateT * slot_8(struct StateT * v144) {
  int v145 = v144->timer;
  int v156 = v145 + 1;
  v144->timer = v156;
  int * v147 = v144->regs;
  int v148 = v147[13];
  bool v159 = -2147483648 < (v148 ^ -2147483648);
  int v151;
  if (v159) {
    v151 = 1;
  } else {
    v151 = 0;
  }
  int * v152 = v144->regs;
  v152[13] = v151;
  struct StateT * v154 = slot_9(v144);
  return v154;
}

struct StateT * slot_30(struct StateT * v533) {
  int v534 = v533->timer;
  int v542 = v534 + 1;
  v533->timer = v542;
  int * v536 = v533->regs;
  int v537 = v536[12];
  int v538 = v536[14];
  int v546 = v537 ^ v538;
  v536[12] = v546;
  struct StateT * v540 = slot_31(v533);
  return v540;
}

struct StateT * slot_60(struct StateT * v1064) {
  int v1065 = v1064->timer;
  int v1074 = v1065 + 1;
  v1064->timer = v1074;
  int * v1067 = v1064->regs;
  int v1068 = v1067[11];
  int * v1069 = v1064->mem;
  int v1078 = (int)((unsigned int)(v1068 + 28) >> 2);
  int v1070 = v1069[v1078];
  v1067[12] = v1070;
  struct StateT * v1072 = slot_61(v1064);
  return v1072;
}

struct StateT * slot_4(struct StateT * v72) {
  int v73 = v72->timer;
  int v82 = v73 + 1;
  v72->timer = v82;
  int * v75 = v72->regs;
  int v76 = v75[13];
  int * v77 = v72->mem;
  int v86 = (int)((unsigned int)(v76 + 4) >> 2);
  int v78 = v77[v86];
  v75[13] = v78;
  struct StateT * v80 = slot_5(v72);
  return v80;
}

struct StateT * slot_18(struct StateT * v320) {
  int v321 = v320->timer;
  int v330 = v321 + 1;
  v320->timer = v330;
  int * v323 = v320->regs;
  int v324 = v323[11];
  int * v325 = v320->mem;
  int v334 = (int)((unsigned int)(v324 + 4) >> 2);
  int v326 = v325[v334];
  v323[12] = v326;
  struct StateT * v328 = slot_19(v320);
  return v328;
}

struct StateT * slot_9(struct StateT * v166) {
  int v167 = v166->timer;
  int v175 = v167 + 1;
  v166->timer = v175;
  int * v169 = v166->regs;
  int v170 = v169[12];
  int v171 = v169[13];
  int v179 = v170 & v171;
  v169[12] = v179;
  struct StateT * v173 = slot_10(v166);
  return v173;
}

struct StateT * slot_11(struct StateT * v196) {
  int v197 = v196->timer;
  int v206 = v197 + 1;
  v196->timer = v206;
  int * v199 = v196->regs;
  int v200 = v199[2];
  int v201 = v199[12];
  int * v202 = v196->mem;
  int v211 = (int)((unsigned int)(v200 + 12) >> 2);
  v202[v211] = v201;
  struct StateT * v204 = slot_12(v196);
  return v204;
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