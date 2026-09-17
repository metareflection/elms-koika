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
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * slot_12(struct StateT * v977);
struct StateT * slot_6(struct StateT * v363);
struct StateT * slot_16(struct StateT * v1081);
struct StateT * slot_5(struct StateT * v339);
struct StateT * slot_2(struct StateT * v259);
struct StateT * slot_7(struct StateT * v618);
struct StateT * slot_21(struct StateT * v1440);
struct StateT * slot_3(struct StateT * v290);
struct StateT * slot_10(struct StateT * v698);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_19(struct StateT * v1392);
struct StateT * slot_13(struct StateT * v1008);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1033);
struct StateT * slot_17(struct StateT * v1336);
struct StateT * slot_20(struct StateT * v1416);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v649);
struct StateT * slot_4(struct StateT * v315);
struct StateT * slot_15(struct StateT * v1057);
struct StateT * slot_18(struct StateT * v1367);
struct StateT * slot_9(struct StateT * v674);
struct StateT * slot_22(struct StateT * v1695);
struct StateT * slot_11(struct StateT * v722);
struct StateT * slot_12(struct StateT * v977) {
  int v978 = v977->timer;
  int v979 = v977->timer;
  int v995 = v979 + 1;
  v977->timer = v995;
  int * v981 = v977->reg_ready;
  int v982 = v981[5];
  int * v983 = v977->regs;
  int v984 = v983[5];
  int * v985 = v977->reg_ready;
  int v986 = v985[7];
  int * v987 = v977->regs;
  int v988 = v987[7];
  int * v989 = v977->reg_ready;
  int v1003 = (v986 + (((v982 + ((v978 - v982) & (~((v978 - v982) >> 31)))) - v986) & (~(((v982 + ((v978 - v982) & (~((v978 - v982) >> 31)))) - v986) >> 31)))) + 1;
  v989[5] = v1003;
  int * v991 = v977->regs;
  int v1005 = v984 ^ v988;
  v991[5] = v1005;
  struct StateT * v993 = slot_13(v977);
  return v993;
}

struct StateT * slot_6(struct StateT * v363) {
  int v364 = v363->timer;
  int v365 = v363->timer;
  int v500 = v365 + 1;
  v363->timer = v500;
  int * v367 = v363->reg_ready;
  int v368 = v367[6];
  int * v369 = v363->regs;
  int v370 = v369[6];
  int * v371 = v363->cache_tags;
  int v505 = (((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2;
  int v372 = v371[v505];
  int * v373 = v363->cache_tags;
  int v507 = ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2) + 1;
  int v374 = v373[v507];
  int * v375 = v363->cache_tags;
  int v509 = 4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2);
  int v376 = v375[v509];
  int * v377 = v363->cache_tags;
  int v511 = (4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v378 = v377[v511];
  int * v379 = v363->cache_vals;
  bool v512 = !(((~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) | (~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31))) == 0);
  int v492;
  if (v512) {
    int * v380 = v363->cache_age;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2) + ((~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) & 1);
    int v381 = v380[v514];
    int * v382 = v363->cache_age;
    int v383 = v382[v505];
    int * v384 = v363->cache_age;
    int v517 = v383 + ((int)((unsigned int)(v383 - v381) >> 31));
    v384[v505] = v517;
    int * v386 = v363->cache_age;
    int v387 = v386[v507];
    int * v388 = v363->cache_age;
    int v520 = v387 + ((int)((unsigned int)(v387 - v381) >> 31));
    v388[v507] = v520;
    int * v390 = v363->cache_age;
    v390[v514] = 0;
    v492 = v514;
  } else {
    int * v393 = v363->cache_age;
    int v524 = (((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2;
    int v394 = v393[v524];
    int * v395 = v363->cache_tags;
    int v396 = v395[v524];
    int * v397 = v363->cache_age;
    int v398 = v397[v507];
    int * v399 = v363->cache_tags;
    int v400 = v399[v507];
    bool v528 = !(((~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) | (~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31))) == 0);
    int v464;
    if (v528) {
      int * v401 = v363->cache_age;
      int v530 = (4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + ((~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) & 1);
      int v402 = v401[v530];
      int * v403 = v363->cache_age;
      int v404 = v403[v509];
      int * v405 = v363->cache_age;
      int v533 = v404 + ((int)((unsigned int)(v404 - v402) >> 31));
      v405[v509] = v533;
      int * v407 = v363->cache_age;
      int v408 = v407[v511];
      int * v409 = v363->cache_age;
      int v536 = v408 + ((int)((unsigned int)(v408 - v402) >> 31));
      v409[v511] = v536;
      int * v411 = v363->cache_age;
      v411[v530] = 0;
      v464 = v530;
    } else {
      int * v414 = v363->cache_age;
      int v540 = 4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2);
      int v415 = v414[v540];
      int * v416 = v363->cache_tags;
      int v417 = v416[v540];
      int * v418 = v363->cache_age;
      int v419 = v418[v511];
      int * v420 = v363->cache_tags;
      int v421 = v420[v511];
      int * v422 = v363->cache_dirty;
      int v545 = (4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v423 = v422[v545];
      bool v546 = !(v423 == 0);
      if (v546) {
        int * v424 = v363->cache_tags;
        int v425 = v424[v545];
        int * v426 = v363->cache_vals;
        int v549 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v427 = v426[v549];
        int * v428 = v363->cache_vals;
        int v551 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v429 = v428[v551];
        int * v430 = v363->mem;
        int v553 = v425 * 2;
        v430[v553] = v427;
        int * v432 = v363->mem;
        int v556 = (v425 * 2) + 1;
        v432[v556] = v429;
        ;
      } else {
        ;
      }
      int * v437 = v363->mem;
      int v561 = ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) * 2;
      int v438 = v437[v561];
      int * v439 = v363->mem;
      int v563 = (((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) * 2) + 1;
      int v440 = v439[v563];
      int * v441 = v363->cache_vals;
      int v565 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v441[v565] = v438;
      int * v443 = v363->cache_vals;
      int v568 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 3) * 2)) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v443[v568] = v440;
      int * v445 = v363->cache_tags;
      int v571 = (int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1);
      v445[v545] = v571;
      int * v447 = v363->cache_dirty;
      v447[v545] = 0;
      int * v449 = v363->cache_age;
      v449[v545] = 1;
      int * v451 = v363->cache_age;
      int v452 = v451[v545];
      int * v453 = v363->cache_age;
      int v454 = v453[v509];
      int * v455 = v363->cache_age;
      int v579 = v454 + ((int)((unsigned int)(v454 - v452) >> 31));
      v455[v509] = v579;
      int * v457 = v363->cache_age;
      int v458 = v457[v511];
      int * v459 = v363->cache_age;
      int v582 = v458 + ((int)((unsigned int)(v458 - v452) >> 31));
      v459[v511] = v582;
      int * v461 = v363->cache_age;
      v461[v545] = 0;
      v464 = v545;
    }
    int * v465 = v363->cache_vals;
    int v585 = v464 * 2;
    int v466 = v465[v585];
    int * v467 = v363->cache_vals;
    int v587 = (v464 * 2) + 1;
    int v468 = v467[v587];
    int * v469 = v363->cache_vals;
    int v589 = (((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2) + ((((v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v469[v589] = v466;
    int * v471 = v363->cache_vals;
    int v592 = ((((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2) + ((((v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v471[v592] = v468;
    int * v473 = v363->cache_tags;
    int v595 = ((((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1)) & 1) * 2) + ((((v394 + ((~(((v396 ^ -1) | (-(v396 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v596 = (int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1);
    v473[v595] = v596;
    int * v475 = v363->cache_dirty;
    v475[v595] = 0;
    int * v477 = v363->cache_age;
    v477[v595] = 1;
    int * v479 = v363->cache_age;
    int v480 = v479[v595];
    int * v481 = v363->cache_age;
    int v482 = v481[v505];
    int * v483 = v363->cache_age;
    int v604 = v482 + ((int)((unsigned int)(v482 - v480) >> 31));
    v483[v505] = v604;
    int * v485 = v363->cache_age;
    int v486 = v485[v507];
    int * v487 = v363->cache_age;
    int v607 = v486 + ((int)((unsigned int)(v486 - v480) >> 31));
    v487[v507] = v607;
    int * v489 = v363->cache_age;
    v489[v595] = 0;
    v492 = v595;
  }
  int v610 = (v492 * 2) + (((int)((unsigned int)v370 >> 2)) & 1);
  int v493 = v379[v610];
  int * v494 = v363->reg_ready;
  int v613 = ((v368 + ((v364 - v368) & (~((v364 - v368) >> 31)))) + 1) + ((100 ^ (((~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) | (~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) | (~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v376 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v376 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31)) | (~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)v370 >> 2)) >> 1))))) >> 31))) & 104)))));
  v494[7] = v613;
  int * v496 = v363->regs;
  v496[7] = v493;
  struct StateT * v498 = slot_7(v363);
  return v498;
}

struct StateT * slot_16(struct StateT * v1081) {
  int v1082 = v1081->timer;
  int v1083 = v1081->timer;
  int v1218 = v1083 + 1;
  v1081->timer = v1218;
  int * v1085 = v1081->reg_ready;
  int v1086 = v1085[6];
  int * v1087 = v1081->regs;
  int v1088 = v1087[6];
  int * v1089 = v1081->cache_tags;
  int v1223 = (((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2;
  int v1090 = v1089[v1223];
  int * v1091 = v1081->cache_tags;
  int v1225 = ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1092 = v1091[v1225];
  int * v1093 = v1081->cache_tags;
  int v1227 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2);
  int v1094 = v1093[v1227];
  int * v1095 = v1081->cache_tags;
  int v1229 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1096 = v1095[v1229];
  int * v1097 = v1081->cache_vals;
  bool v1230 = !(((~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) | (~(((v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31))) == 0);
  int v1210;
  if (v1230) {
    int * v1098 = v1081->cache_age;
    int v1232 = ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2) + ((~(((v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) & 1);
    int v1099 = v1098[v1232];
    int * v1100 = v1081->cache_age;
    int v1101 = v1100[v1223];
    int * v1102 = v1081->cache_age;
    int v1235 = v1101 + ((int)((unsigned int)(v1101 - v1099) >> 31));
    v1102[v1223] = v1235;
    int * v1104 = v1081->cache_age;
    int v1105 = v1104[v1225];
    int * v1106 = v1081->cache_age;
    int v1238 = v1105 + ((int)((unsigned int)(v1105 - v1099) >> 31));
    v1106[v1225] = v1238;
    int * v1108 = v1081->cache_age;
    v1108[v1232] = 0;
    v1210 = v1232;
  } else {
    int * v1111 = v1081->cache_age;
    int v1242 = (((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2;
    int v1112 = v1111[v1242];
    int * v1113 = v1081->cache_tags;
    int v1114 = v1113[v1242];
    int * v1115 = v1081->cache_age;
    int v1116 = v1115[v1225];
    int * v1117 = v1081->cache_tags;
    int v1118 = v1117[v1225];
    bool v1246 = !(((~(((v1094 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1094 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) | (~(((v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31))) == 0);
    int v1182;
    if (v1246) {
      int * v1119 = v1081->cache_age;
      int v1248 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) & 1);
      int v1120 = v1119[v1248];
      int * v1121 = v1081->cache_age;
      int v1122 = v1121[v1227];
      int * v1123 = v1081->cache_age;
      int v1251 = v1122 + ((int)((unsigned int)(v1122 - v1120) >> 31));
      v1123[v1227] = v1251;
      int * v1125 = v1081->cache_age;
      int v1126 = v1125[v1229];
      int * v1127 = v1081->cache_age;
      int v1254 = v1126 + ((int)((unsigned int)(v1126 - v1120) >> 31));
      v1127[v1229] = v1254;
      int * v1129 = v1081->cache_age;
      v1129[v1248] = 0;
      v1182 = v1248;
    } else {
      int * v1132 = v1081->cache_age;
      int v1258 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2);
      int v1133 = v1132[v1258];
      int * v1134 = v1081->cache_tags;
      int v1135 = v1134[v1258];
      int * v1136 = v1081->cache_age;
      int v1137 = v1136[v1229];
      int * v1138 = v1081->cache_tags;
      int v1139 = v1138[v1229];
      int * v1140 = v1081->cache_dirty;
      int v1263 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1141 = v1140[v1263];
      bool v1264 = !(v1141 == 0);
      if (v1264) {
        int * v1142 = v1081->cache_tags;
        int v1143 = v1142[v1263];
        int * v1144 = v1081->cache_vals;
        int v1267 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1145 = v1144[v1267];
        int * v1146 = v1081->cache_vals;
        int v1269 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1147 = v1146[v1269];
        int * v1148 = v1081->mem;
        int v1271 = v1143 * 2;
        v1148[v1271] = v1145;
        int * v1150 = v1081->mem;
        int v1274 = (v1143 * 2) + 1;
        v1150[v1274] = v1147;
        ;
      } else {
        ;
      }
      int * v1155 = v1081->mem;
      int v1279 = ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) * 2;
      int v1156 = v1155[v1279];
      int * v1157 = v1081->mem;
      int v1281 = (((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) * 2) + 1;
      int v1158 = v1157[v1281];
      int * v1159 = v1081->cache_vals;
      int v1283 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1159[v1283] = v1156;
      int * v1161 = v1081->cache_vals;
      int v1286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 3) * 2)) + ((((v1133 + ((~(((v1135 ^ -1) | (-(v1135 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1139 ^ -1) | (-(v1139 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1161[v1286] = v1158;
      int * v1163 = v1081->cache_tags;
      int v1289 = (int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1);
      v1163[v1263] = v1289;
      int * v1165 = v1081->cache_dirty;
      v1165[v1263] = 0;
      int * v1167 = v1081->cache_age;
      v1167[v1263] = 1;
      int * v1169 = v1081->cache_age;
      int v1170 = v1169[v1263];
      int * v1171 = v1081->cache_age;
      int v1172 = v1171[v1227];
      int * v1173 = v1081->cache_age;
      int v1297 = v1172 + ((int)((unsigned int)(v1172 - v1170) >> 31));
      v1173[v1227] = v1297;
      int * v1175 = v1081->cache_age;
      int v1176 = v1175[v1229];
      int * v1177 = v1081->cache_age;
      int v1300 = v1176 + ((int)((unsigned int)(v1176 - v1170) >> 31));
      v1177[v1229] = v1300;
      int * v1179 = v1081->cache_age;
      v1179[v1263] = 0;
      v1182 = v1263;
    }
    int * v1183 = v1081->cache_vals;
    int v1303 = v1182 * 2;
    int v1184 = v1183[v1303];
    int * v1185 = v1081->cache_vals;
    int v1305 = (v1182 * 2) + 1;
    int v1186 = v1185[v1305];
    int * v1187 = v1081->cache_vals;
    int v1307 = (((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2) + ((((v1112 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2)) - (v1116 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1187[v1307] = v1184;
    int * v1189 = v1081->cache_vals;
    int v1310 = ((((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2) + ((((v1112 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2)) - (v1116 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1189[v1310] = v1186;
    int * v1191 = v1081->cache_tags;
    int v1313 = ((((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1)) & 1) * 2) + ((((v1112 + ((~(((v1114 ^ -1) | (-(v1114 ^ -1))) >> 31)) & 2)) - (v1116 + ((~(((v1118 ^ -1) | (-(v1118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1314 = (int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1);
    v1191[v1313] = v1314;
    int * v1193 = v1081->cache_dirty;
    v1193[v1313] = 0;
    int * v1195 = v1081->cache_age;
    v1195[v1313] = 1;
    int * v1197 = v1081->cache_age;
    int v1198 = v1197[v1313];
    int * v1199 = v1081->cache_age;
    int v1200 = v1199[v1223];
    int * v1201 = v1081->cache_age;
    int v1322 = v1200 + ((int)((unsigned int)(v1200 - v1198) >> 31));
    v1201[v1223] = v1322;
    int * v1203 = v1081->cache_age;
    int v1204 = v1203[v1225];
    int * v1205 = v1081->cache_age;
    int v1325 = v1204 + ((int)((unsigned int)(v1204 - v1198) >> 31));
    v1205[v1225] = v1325;
    int * v1207 = v1081->cache_age;
    v1207[v1313] = 0;
    v1210 = v1313;
  }
  int v1328 = (v1210 * 2) + (((int)((unsigned int)v1088 >> 2)) & 1);
  int v1211 = v1097[v1328];
  int * v1212 = v1081->reg_ready;
  int v1331 = ((v1086 + ((v1082 - v1086) & (~((v1082 - v1086) >> 31)))) + 1) + ((100 ^ (((~(((v1094 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1094 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) | (~(((v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) | (~(((v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1092 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1094 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1094 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31)) | (~(((v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))) | (-(v1096 ^ ((int)((unsigned int)((int)((unsigned int)v1088 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1212[7] = v1331;
  int * v1214 = v1081->regs;
  v1214[7] = v1211;
  struct StateT * v1216 = slot_17(v1081);
  return v1216;
}

struct StateT * slot_5(struct StateT * v339) {
  int v340 = v339->timer;
  int v341 = v339->timer;
  int v353 = v341 + 1;
  v339->timer = v353;
  int * v343 = v339->reg_ready;
  int v344 = v343[6];
  int * v345 = v339->regs;
  int v346 = v345[6];
  int * v347 = v339->reg_ready;
  int v358 = (v344 + ((v340 - v344) & (~((v340 - v344) >> 31)))) + 1;
  v347[6] = v358;
  int * v349 = v339->regs;
  int v360 = v346 << 2;
  v349[6] = v360;
  struct StateT * v351 = slot_6(v339);
  return v351;
}

struct StateT * slot_2(struct StateT * v259) {
  int v260 = v259->timer;
  int v261 = v259->timer;
  int v277 = v261 + 1;
  v259->timer = v277;
  int * v263 = v259->reg_ready;
  int v264 = v263[5];
  int * v265 = v259->regs;
  int v266 = v265[5];
  int * v267 = v259->reg_ready;
  int v268 = v267[9];
  int * v269 = v259->regs;
  int v270 = v269[9];
  int * v271 = v259->reg_ready;
  int v285 = (v268 + (((v264 + ((v260 - v264) & (~((v260 - v264) >> 31)))) - v268) & (~(((v264 + ((v260 - v264) & (~((v260 - v264) >> 31)))) - v268) >> 31)))) + 1;
  v271[5] = v285;
  int * v273 = v259->regs;
  int v287 = v266 ^ v270;
  v273[5] = v287;
  struct StateT * v275 = slot_3(v259);
  return v275;
}

struct StateT * slot_7(struct StateT * v618) {
  int v619 = v618->timer;
  int v620 = v618->timer;
  int v636 = v620 + 1;
  v618->timer = v636;
  int * v622 = v618->reg_ready;
  int v623 = v622[5];
  int * v624 = v618->regs;
  int v625 = v624[5];
  int * v626 = v618->reg_ready;
  int v627 = v626[7];
  int * v628 = v618->regs;
  int v629 = v628[7];
  int * v630 = v618->reg_ready;
  int v644 = (v627 + (((v623 + ((v619 - v623) & (~((v619 - v623) >> 31)))) - v627) & (~(((v623 + ((v619 - v623) & (~((v619 - v623) >> 31)))) - v627) >> 31)))) + 1;
  v630[5] = v644;
  int * v632 = v618->regs;
  int v646 = v625 ^ v629;
  v632[5] = v646;
  struct StateT * v634 = slot_8(v618);
  return v634;
}

struct StateT * slot_21(struct StateT * v1440) {
  int v1441 = v1440->timer;
  int v1442 = v1440->timer;
  int v1577 = v1442 + 1;
  v1440->timer = v1577;
  int * v1444 = v1440->reg_ready;
  int v1445 = v1444[6];
  int * v1446 = v1440->regs;
  int v1447 = v1446[6];
  int * v1448 = v1440->cache_tags;
  int v1582 = (((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2;
  int v1449 = v1448[v1582];
  int * v1450 = v1440->cache_tags;
  int v1584 = ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1451 = v1450[v1584];
  int * v1452 = v1440->cache_tags;
  int v1586 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2);
  int v1453 = v1452[v1586];
  int * v1454 = v1440->cache_tags;
  int v1588 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1455 = v1454[v1588];
  int * v1456 = v1440->cache_vals;
  bool v1589 = !(((~(((v1449 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1449 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) | (~(((v1451 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1451 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31))) == 0);
  int v1569;
  if (v1589) {
    int * v1457 = v1440->cache_age;
    int v1591 = ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2) + ((~(((v1451 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1451 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) & 1);
    int v1458 = v1457[v1591];
    int * v1459 = v1440->cache_age;
    int v1460 = v1459[v1582];
    int * v1461 = v1440->cache_age;
    int v1594 = v1460 + ((int)((unsigned int)(v1460 - v1458) >> 31));
    v1461[v1582] = v1594;
    int * v1463 = v1440->cache_age;
    int v1464 = v1463[v1584];
    int * v1465 = v1440->cache_age;
    int v1597 = v1464 + ((int)((unsigned int)(v1464 - v1458) >> 31));
    v1465[v1584] = v1597;
    int * v1467 = v1440->cache_age;
    v1467[v1591] = 0;
    v1569 = v1591;
  } else {
    int * v1470 = v1440->cache_age;
    int v1601 = (((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2;
    int v1471 = v1470[v1601];
    int * v1472 = v1440->cache_tags;
    int v1473 = v1472[v1601];
    int * v1474 = v1440->cache_age;
    int v1475 = v1474[v1584];
    int * v1476 = v1440->cache_tags;
    int v1477 = v1476[v1584];
    bool v1605 = !(((~(((v1453 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1453 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) | (~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31))) == 0);
    int v1541;
    if (v1605) {
      int * v1478 = v1440->cache_age;
      int v1607 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) & 1);
      int v1479 = v1478[v1607];
      int * v1480 = v1440->cache_age;
      int v1481 = v1480[v1586];
      int * v1482 = v1440->cache_age;
      int v1610 = v1481 + ((int)((unsigned int)(v1481 - v1479) >> 31));
      v1482[v1586] = v1610;
      int * v1484 = v1440->cache_age;
      int v1485 = v1484[v1588];
      int * v1486 = v1440->cache_age;
      int v1613 = v1485 + ((int)((unsigned int)(v1485 - v1479) >> 31));
      v1486[v1588] = v1613;
      int * v1488 = v1440->cache_age;
      v1488[v1607] = 0;
      v1541 = v1607;
    } else {
      int * v1491 = v1440->cache_age;
      int v1617 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2);
      int v1492 = v1491[v1617];
      int * v1493 = v1440->cache_tags;
      int v1494 = v1493[v1617];
      int * v1495 = v1440->cache_age;
      int v1496 = v1495[v1588];
      int * v1497 = v1440->cache_tags;
      int v1498 = v1497[v1588];
      int * v1499 = v1440->cache_dirty;
      int v1622 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1496 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1500 = v1499[v1622];
      bool v1623 = !(v1500 == 0);
      if (v1623) {
        int * v1501 = v1440->cache_tags;
        int v1502 = v1501[v1622];
        int * v1503 = v1440->cache_vals;
        int v1626 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1496 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1504 = v1503[v1626];
        int * v1505 = v1440->cache_vals;
        int v1628 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1496 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1506 = v1505[v1628];
        int * v1507 = v1440->mem;
        int v1630 = v1502 * 2;
        v1507[v1630] = v1504;
        int * v1509 = v1440->mem;
        int v1633 = (v1502 * 2) + 1;
        v1509[v1633] = v1506;
        ;
      } else {
        ;
      }
      int * v1514 = v1440->mem;
      int v1638 = ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) * 2;
      int v1515 = v1514[v1638];
      int * v1516 = v1440->mem;
      int v1640 = (((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) * 2) + 1;
      int v1517 = v1516[v1640];
      int * v1518 = v1440->cache_vals;
      int v1642 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1496 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1518[v1642] = v1515;
      int * v1520 = v1440->cache_vals;
      int v1645 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 3) * 2)) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1496 + ((~(((v1498 ^ -1) | (-(v1498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1520[v1645] = v1517;
      int * v1522 = v1440->cache_tags;
      int v1648 = (int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1);
      v1522[v1622] = v1648;
      int * v1524 = v1440->cache_dirty;
      v1524[v1622] = 0;
      int * v1526 = v1440->cache_age;
      v1526[v1622] = 1;
      int * v1528 = v1440->cache_age;
      int v1529 = v1528[v1622];
      int * v1530 = v1440->cache_age;
      int v1531 = v1530[v1586];
      int * v1532 = v1440->cache_age;
      int v1656 = v1531 + ((int)((unsigned int)(v1531 - v1529) >> 31));
      v1532[v1586] = v1656;
      int * v1534 = v1440->cache_age;
      int v1535 = v1534[v1588];
      int * v1536 = v1440->cache_age;
      int v1659 = v1535 + ((int)((unsigned int)(v1535 - v1529) >> 31));
      v1536[v1588] = v1659;
      int * v1538 = v1440->cache_age;
      v1538[v1622] = 0;
      v1541 = v1622;
    }
    int * v1542 = v1440->cache_vals;
    int v1662 = v1541 * 2;
    int v1543 = v1542[v1662];
    int * v1544 = v1440->cache_vals;
    int v1664 = (v1541 * 2) + 1;
    int v1545 = v1544[v1664];
    int * v1546 = v1440->cache_vals;
    int v1666 = (((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2) + ((((v1471 + ((~(((v1473 ^ -1) | (-(v1473 ^ -1))) >> 31)) & 2)) - (v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1546[v1666] = v1543;
    int * v1548 = v1440->cache_vals;
    int v1669 = ((((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2) + ((((v1471 + ((~(((v1473 ^ -1) | (-(v1473 ^ -1))) >> 31)) & 2)) - (v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1548[v1669] = v1545;
    int * v1550 = v1440->cache_tags;
    int v1672 = ((((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1)) & 1) * 2) + ((((v1471 + ((~(((v1473 ^ -1) | (-(v1473 ^ -1))) >> 31)) & 2)) - (v1475 + ((~(((v1477 ^ -1) | (-(v1477 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1673 = (int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1);
    v1550[v1672] = v1673;
    int * v1552 = v1440->cache_dirty;
    v1552[v1672] = 0;
    int * v1554 = v1440->cache_age;
    v1554[v1672] = 1;
    int * v1556 = v1440->cache_age;
    int v1557 = v1556[v1672];
    int * v1558 = v1440->cache_age;
    int v1559 = v1558[v1582];
    int * v1560 = v1440->cache_age;
    int v1681 = v1559 + ((int)((unsigned int)(v1559 - v1557) >> 31));
    v1560[v1582] = v1681;
    int * v1562 = v1440->cache_age;
    int v1563 = v1562[v1584];
    int * v1564 = v1440->cache_age;
    int v1684 = v1563 + ((int)((unsigned int)(v1563 - v1557) >> 31));
    v1564[v1584] = v1684;
    int * v1566 = v1440->cache_age;
    v1566[v1672] = 0;
    v1569 = v1672;
  }
  int v1687 = (v1569 * 2) + (((int)((unsigned int)v1447 >> 2)) & 1);
  int v1570 = v1456[v1687];
  int * v1571 = v1440->reg_ready;
  int v1690 = ((v1445 + ((v1441 - v1445) & (~((v1441 - v1445) >> 31)))) + 1) + ((100 ^ (((~(((v1453 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1453 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) | (~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1449 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1449 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) | (~(((v1451 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1451 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1453 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1453 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31)) | (~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1447 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1571[7] = v1690;
  int * v1573 = v1440->regs;
  v1573[7] = v1570;
  struct StateT * v1575 = slot_22(v1440);
  return v1575;
}

struct StateT * slot_3(struct StateT * v290) {
  int v291 = v290->timer;
  int v292 = v290->timer;
  int v304 = v292 + 1;
  v290->timer = v304;
  int * v294 = v290->reg_ready;
  int v295 = v294[10];
  int * v296 = v290->regs;
  int v297 = v296[10];
  int * v298 = v290->reg_ready;
  int v310 = (v295 + ((v291 - v295) & (~((v291 - v295) >> 31)))) + 1;
  v298[6] = v310;
  int * v300 = v290->regs;
  v300[6] = v297;
  struct StateT * v302 = slot_4(v290);
  return v302;
}

struct StateT * slot_10(struct StateT * v698) {
  int v699 = v698->timer;
  int v700 = v698->timer;
  int v712 = v700 + 1;
  v698->timer = v712;
  int * v702 = v698->reg_ready;
  int v703 = v702[6];
  int * v704 = v698->regs;
  int v705 = v704[6];
  int * v706 = v698->reg_ready;
  int v717 = (v703 + ((v699 - v703) & (~((v699 - v703) >> 31)))) + 1;
  v706[6] = v717;
  int * v708 = v698->regs;
  int v719 = v705 << 2;
  v708[6] = v719;
  struct StateT * v710 = slot_11(v698);
  return v710;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v153 = v22 + 1;
  v20->timer = v153;
  int * v24 = v20->cache_tags;
  int v25 = v24[0];
  int * v26 = v20->cache_tags;
  int v27 = v26[1];
  int * v28 = v20->cache_tags;
  int v29 = v28[8];
  int * v30 = v20->cache_tags;
  int v31 = v30[9];
  int * v32 = v20->cache_vals;
  bool v162 = !(((~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31)) | (~(((v27 ^ 10) | (-(v27 ^ 10))) >> 31))) == 0);
  int v145;
  if (v162) {
    int * v33 = v20->cache_age;
    int v164 = (~(((v27 ^ 10) | (-(v27 ^ 10))) >> 31)) & 1;
    int v34 = v33[v164];
    int * v35 = v20->cache_age;
    int v36 = v35[0];
    int * v37 = v20->cache_age;
    int v167 = v36 + ((int)((unsigned int)(v36 - v34) >> 31));
    v37[0] = v167;
    int * v39 = v20->cache_age;
    int v40 = v39[1];
    int * v41 = v20->cache_age;
    int v170 = v40 + ((int)((unsigned int)(v40 - v34) >> 31));
    v41[1] = v170;
    int * v43 = v20->cache_age;
    v43[v164] = 0;
    v145 = v164;
  } else {
    int * v46 = v20->cache_age;
    int v47 = v46[0];
    int * v48 = v20->cache_tags;
    int v49 = v48[0];
    int * v50 = v20->cache_age;
    int v51 = v50[1];
    int * v52 = v20->cache_tags;
    int v53 = v52[1];
    bool v176 = !(((~(((v29 ^ 10) | (-(v29 ^ 10))) >> 31)) | (~(((v31 ^ 10) | (-(v31 ^ 10))) >> 31))) == 0);
    int v117;
    if (v176) {
      int * v54 = v20->cache_age;
      int v178 = 8 + ((~(((v31 ^ 10) | (-(v31 ^ 10))) >> 31)) & 1);
      int v55 = v54[v178];
      int * v56 = v20->cache_age;
      int v57 = v56[8];
      int * v58 = v20->cache_age;
      int v181 = v57 + ((int)((unsigned int)(v57 - v55) >> 31));
      v58[8] = v181;
      int * v60 = v20->cache_age;
      int v61 = v60[9];
      int * v62 = v20->cache_age;
      int v184 = v61 + ((int)((unsigned int)(v61 - v55) >> 31));
      v62[9] = v184;
      int * v64 = v20->cache_age;
      v64[v178] = 0;
      v117 = v178;
    } else {
      int * v67 = v20->cache_age;
      int v68 = v67[8];
      int * v69 = v20->cache_tags;
      int v70 = v69[8];
      int * v71 = v20->cache_age;
      int v72 = v71[9];
      int * v73 = v20->cache_tags;
      int v74 = v73[9];
      int * v75 = v20->cache_dirty;
      int v191 = 8 + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v76 = v75[v191];
      bool v192 = !(v76 == 0);
      if (v192) {
        int * v77 = v20->cache_tags;
        int v78 = v77[v191];
        int * v79 = v20->cache_vals;
        int v195 = (8 + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v80 = v79[v195];
        int * v81 = v20->cache_vals;
        int v197 = ((8 + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v82 = v81[v197];
        int * v83 = v20->mem;
        int v199 = v78 * 2;
        v83[v199] = v80;
        int * v85 = v20->mem;
        int v202 = (v78 * 2) + 1;
        v85[v202] = v82;
        ;
      } else {
        ;
      }
      int * v90 = v20->mem;
      int v91 = v90[20];
      int * v92 = v20->mem;
      int v93 = v92[21];
      int * v94 = v20->cache_vals;
      int v211 = (8 + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v94[v211] = v91;
      int * v96 = v20->cache_vals;
      int v214 = ((8 + ((((v68 + ((~(((v70 ^ -1) | (-(v70 ^ -1))) >> 31)) & 2)) - (v72 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v96[v214] = v93;
      int * v98 = v20->cache_tags;
      v98[v191] = 10;
      int * v100 = v20->cache_dirty;
      v100[v191] = 0;
      int * v102 = v20->cache_age;
      v102[v191] = 1;
      int * v104 = v20->cache_age;
      int v105 = v104[v191];
      int * v106 = v20->cache_age;
      int v107 = v106[8];
      int * v108 = v20->cache_age;
      int v223 = v107 + ((int)((unsigned int)(v107 - v105) >> 31));
      v108[8] = v223;
      int * v110 = v20->cache_age;
      int v111 = v110[9];
      int * v112 = v20->cache_age;
      int v226 = v111 + ((int)((unsigned int)(v111 - v105) >> 31));
      v112[9] = v226;
      int * v114 = v20->cache_age;
      v114[v191] = 0;
      v117 = v191;
    }
    int * v118 = v20->cache_vals;
    int v229 = v117 * 2;
    int v119 = v118[v229];
    int * v120 = v20->cache_vals;
    int v231 = (v117 * 2) + 1;
    int v121 = v120[v231];
    int * v122 = v20->cache_vals;
    int v233 = ((((v47 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2)) - (v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v122[v233] = v119;
    int * v124 = v20->cache_vals;
    int v236 = (((((v47 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2)) - (v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v124[v236] = v121;
    int * v126 = v20->cache_tags;
    int v239 = (((v47 + ((~(((v49 ^ -1) | (-(v49 ^ -1))) >> 31)) & 2)) - (v51 + ((~(((v53 ^ -1) | (-(v53 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v126[v239] = 10;
    int * v128 = v20->cache_dirty;
    v128[v239] = 0;
    int * v130 = v20->cache_age;
    v130[v239] = 1;
    int * v132 = v20->cache_age;
    int v133 = v132[v239];
    int * v134 = v20->cache_age;
    int v135 = v134[0];
    int * v136 = v20->cache_age;
    int v246 = v135 + ((int)((unsigned int)(v135 - v133) >> 31));
    v136[0] = v246;
    int * v138 = v20->cache_age;
    int v139 = v138[1];
    int * v140 = v20->cache_age;
    int v249 = v139 + ((int)((unsigned int)(v139 - v133) >> 31));
    v140[1] = v249;
    int * v142 = v20->cache_age;
    v142[v239] = 0;
    v145 = v239;
  }
  int v252 = v145 * 2;
  int v146 = v32[v252];
  int * v147 = v20->reg_ready;
  int v254 = (v21 + 1) + ((100 ^ (((~(((v29 ^ 10) | (-(v29 ^ 10))) >> 31)) | (~(((v31 ^ 10) | (-(v31 ^ 10))) >> 31))) & 104)) ^ (((~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31)) | (~(((v27 ^ 10) | (-(v27 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v29 ^ 10) | (-(v29 ^ 10))) >> 31)) | (~(((v31 ^ 10) | (-(v31 ^ 10))) >> 31))) & 104)))));
  v147[9] = v254;
  int * v149 = v20->regs;
  v149[9] = v146;
  struct StateT * v151 = slot_2(v20);
  return v151;
}

struct StateT * slot_19(struct StateT * v1392) {
  int v1393 = v1392->timer;
  int v1394 = v1392->timer;
  int v1406 = v1394 + 1;
  v1392->timer = v1406;
  int * v1396 = v1392->reg_ready;
  int v1397 = v1396[6];
  int * v1398 = v1392->regs;
  int v1399 = v1398[6];
  int * v1400 = v1392->reg_ready;
  int v1411 = (v1397 + ((v1393 - v1397) & (~((v1393 - v1397) >> 31)))) + 1;
  v1400[6] = v1411;
  int * v1402 = v1392->regs;
  int v1413 = v1399 & 63;
  v1402[6] = v1413;
  struct StateT * v1404 = slot_20(v1392);
  return v1404;
}

struct StateT * slot_13(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v1010 = v1008->timer;
  int v1022 = v1010 + 1;
  v1008->timer = v1022;
  int * v1012 = v1008->reg_ready;
  int v1013 = v1012[10];
  int * v1014 = v1008->regs;
  int v1015 = v1014[10];
  int * v1016 = v1008->reg_ready;
  int v1028 = (v1013 + ((v1009 - v1013) & (~((v1009 - v1013) >> 31)))) + 1;
  v1016[6] = v1028;
  int * v1018 = v1008->regs;
  int v1030 = (int)((unsigned int)v1015 >> 16);
  v1018[6] = v1030;
  struct StateT * v1020 = slot_14(v1008);
  return v1020;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[5] = v15;
  int * v8 = v2->regs;
  v8[5] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
}

struct StateT * slot_14(struct StateT * v1033) {
  int v1034 = v1033->timer;
  int v1035 = v1033->timer;
  int v1047 = v1035 + 1;
  v1033->timer = v1047;
  int * v1037 = v1033->reg_ready;
  int v1038 = v1037[6];
  int * v1039 = v1033->regs;
  int v1040 = v1039[6];
  int * v1041 = v1033->reg_ready;
  int v1052 = (v1038 + ((v1034 - v1038) & (~((v1034 - v1038) >> 31)))) + 1;
  v1041[6] = v1052;
  int * v1043 = v1033->regs;
  int v1054 = v1040 & 63;
  v1043[6] = v1054;
  struct StateT * v1045 = slot_15(v1033);
  return v1045;
}

struct StateT * slot_17(struct StateT * v1336) {
  int v1337 = v1336->timer;
  int v1338 = v1336->timer;
  int v1354 = v1338 + 1;
  v1336->timer = v1354;
  int * v1340 = v1336->reg_ready;
  int v1341 = v1340[5];
  int * v1342 = v1336->regs;
  int v1343 = v1342[5];
  int * v1344 = v1336->reg_ready;
  int v1345 = v1344[7];
  int * v1346 = v1336->regs;
  int v1347 = v1346[7];
  int * v1348 = v1336->reg_ready;
  int v1362 = (v1345 + (((v1341 + ((v1337 - v1341) & (~((v1337 - v1341) >> 31)))) - v1345) & (~(((v1341 + ((v1337 - v1341) & (~((v1337 - v1341) >> 31)))) - v1345) >> 31)))) + 1;
  v1348[5] = v1362;
  int * v1350 = v1336->regs;
  int v1364 = v1343 ^ v1347;
  v1350[5] = v1364;
  struct StateT * v1352 = slot_18(v1336);
  return v1352;
}

struct StateT * slot_20(struct StateT * v1416) {
  int v1417 = v1416->timer;
  int v1418 = v1416->timer;
  int v1430 = v1418 + 1;
  v1416->timer = v1430;
  int * v1420 = v1416->reg_ready;
  int v1421 = v1420[6];
  int * v1422 = v1416->regs;
  int v1423 = v1422[6];
  int * v1424 = v1416->reg_ready;
  int v1435 = (v1421 + ((v1417 - v1421) & (~((v1417 - v1421) >> 31)))) + 1;
  v1424[6] = v1435;
  int * v1426 = v1416->regs;
  int v1437 = v1423 << 2;
  v1426[6] = v1437;
  struct StateT * v1428 = slot_21(v1416);
  return v1428;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1723 = v1->timer;
  int * v1724 = v1->reg_ready;
  int v1725 = v1724[0];
  int v1856 = v1725 + ((v1723 - v1725) & (~((v1723 - v1725) >> 31)));
  v1->timer = v1856;
  int v1727 = v1->timer;
  int * v1728 = v1->reg_ready;
  int v1729 = v1728[1];
  int v1859 = v1729 + ((v1727 - v1729) & (~((v1727 - v1729) >> 31)));
  v1->timer = v1859;
  int v1731 = v1->timer;
  int * v1732 = v1->reg_ready;
  int v1733 = v1732[2];
  int v1862 = v1733 + ((v1731 - v1733) & (~((v1731 - v1733) >> 31)));
  v1->timer = v1862;
  int v1735 = v1->timer;
  int * v1736 = v1->reg_ready;
  int v1737 = v1736[3];
  int v1865 = v1737 + ((v1735 - v1737) & (~((v1735 - v1737) >> 31)));
  v1->timer = v1865;
  int v1739 = v1->timer;
  int * v1740 = v1->reg_ready;
  int v1741 = v1740[4];
  int v1868 = v1741 + ((v1739 - v1741) & (~((v1739 - v1741) >> 31)));
  v1->timer = v1868;
  int v1743 = v1->timer;
  int * v1744 = v1->reg_ready;
  int v1745 = v1744[5];
  int v1871 = v1745 + ((v1743 - v1745) & (~((v1743 - v1745) >> 31)));
  v1->timer = v1871;
  int v1747 = v1->timer;
  int * v1748 = v1->reg_ready;
  int v1749 = v1748[6];
  int v1874 = v1749 + ((v1747 - v1749) & (~((v1747 - v1749) >> 31)));
  v1->timer = v1874;
  int v1751 = v1->timer;
  int * v1752 = v1->reg_ready;
  int v1753 = v1752[7];
  int v1877 = v1753 + ((v1751 - v1753) & (~((v1751 - v1753) >> 31)));
  v1->timer = v1877;
  int v1755 = v1->timer;
  int * v1756 = v1->reg_ready;
  int v1757 = v1756[8];
  int v1880 = v1757 + ((v1755 - v1757) & (~((v1755 - v1757) >> 31)));
  v1->timer = v1880;
  int v1759 = v1->timer;
  int * v1760 = v1->reg_ready;
  int v1761 = v1760[9];
  int v1883 = v1761 + ((v1759 - v1761) & (~((v1759 - v1761) >> 31)));
  v1->timer = v1883;
  int v1763 = v1->timer;
  int * v1764 = v1->reg_ready;
  int v1765 = v1764[10];
  int v1886 = v1765 + ((v1763 - v1765) & (~((v1763 - v1765) >> 31)));
  v1->timer = v1886;
  int v1767 = v1->timer;
  int * v1768 = v1->reg_ready;
  int v1769 = v1768[11];
  int v1889 = v1769 + ((v1767 - v1769) & (~((v1767 - v1769) >> 31)));
  v1->timer = v1889;
  int v1771 = v1->timer;
  int * v1772 = v1->reg_ready;
  int v1773 = v1772[12];
  int v1892 = v1773 + ((v1771 - v1773) & (~((v1771 - v1773) >> 31)));
  v1->timer = v1892;
  int v1775 = v1->timer;
  int * v1776 = v1->reg_ready;
  int v1777 = v1776[13];
  int v1895 = v1777 + ((v1775 - v1777) & (~((v1775 - v1777) >> 31)));
  v1->timer = v1895;
  int v1779 = v1->timer;
  int * v1780 = v1->reg_ready;
  int v1781 = v1780[14];
  int v1898 = v1781 + ((v1779 - v1781) & (~((v1779 - v1781) >> 31)));
  v1->timer = v1898;
  int v1783 = v1->timer;
  int * v1784 = v1->reg_ready;
  int v1785 = v1784[15];
  int v1901 = v1785 + ((v1783 - v1785) & (~((v1783 - v1785) >> 31)));
  v1->timer = v1901;
  int v1787 = v1->timer;
  int * v1788 = v1->reg_ready;
  int v1789 = v1788[16];
  int v1904 = v1789 + ((v1787 - v1789) & (~((v1787 - v1789) >> 31)));
  v1->timer = v1904;
  int v1791 = v1->timer;
  int * v1792 = v1->reg_ready;
  int v1793 = v1792[17];
  int v1907 = v1793 + ((v1791 - v1793) & (~((v1791 - v1793) >> 31)));
  v1->timer = v1907;
  int v1795 = v1->timer;
  int * v1796 = v1->reg_ready;
  int v1797 = v1796[18];
  int v1910 = v1797 + ((v1795 - v1797) & (~((v1795 - v1797) >> 31)));
  v1->timer = v1910;
  int v1799 = v1->timer;
  int * v1800 = v1->reg_ready;
  int v1801 = v1800[19];
  int v1913 = v1801 + ((v1799 - v1801) & (~((v1799 - v1801) >> 31)));
  v1->timer = v1913;
  int v1803 = v1->timer;
  int * v1804 = v1->reg_ready;
  int v1805 = v1804[20];
  int v1916 = v1805 + ((v1803 - v1805) & (~((v1803 - v1805) >> 31)));
  v1->timer = v1916;
  int v1807 = v1->timer;
  int * v1808 = v1->reg_ready;
  int v1809 = v1808[21];
  int v1919 = v1809 + ((v1807 - v1809) & (~((v1807 - v1809) >> 31)));
  v1->timer = v1919;
  int v1811 = v1->timer;
  int * v1812 = v1->reg_ready;
  int v1813 = v1812[22];
  int v1922 = v1813 + ((v1811 - v1813) & (~((v1811 - v1813) >> 31)));
  v1->timer = v1922;
  int v1815 = v1->timer;
  int * v1816 = v1->reg_ready;
  int v1817 = v1816[23];
  int v1925 = v1817 + ((v1815 - v1817) & (~((v1815 - v1817) >> 31)));
  v1->timer = v1925;
  int v1819 = v1->timer;
  int * v1820 = v1->reg_ready;
  int v1821 = v1820[24];
  int v1928 = v1821 + ((v1819 - v1821) & (~((v1819 - v1821) >> 31)));
  v1->timer = v1928;
  int v1823 = v1->timer;
  int * v1824 = v1->reg_ready;
  int v1825 = v1824[25];
  int v1931 = v1825 + ((v1823 - v1825) & (~((v1823 - v1825) >> 31)));
  v1->timer = v1931;
  int v1827 = v1->timer;
  int * v1828 = v1->reg_ready;
  int v1829 = v1828[26];
  int v1934 = v1829 + ((v1827 - v1829) & (~((v1827 - v1829) >> 31)));
  v1->timer = v1934;
  int v1831 = v1->timer;
  int * v1832 = v1->reg_ready;
  int v1833 = v1832[27];
  int v1937 = v1833 + ((v1831 - v1833) & (~((v1831 - v1833) >> 31)));
  v1->timer = v1937;
  int v1835 = v1->timer;
  int * v1836 = v1->reg_ready;
  int v1837 = v1836[28];
  int v1940 = v1837 + ((v1835 - v1837) & (~((v1835 - v1837) >> 31)));
  v1->timer = v1940;
  int v1839 = v1->timer;
  int * v1840 = v1->reg_ready;
  int v1841 = v1840[29];
  int v1943 = v1841 + ((v1839 - v1841) & (~((v1839 - v1841) >> 31)));
  v1->timer = v1943;
  int v1843 = v1->timer;
  int * v1844 = v1->reg_ready;
  int v1845 = v1844[30];
  int v1946 = v1845 + ((v1843 - v1845) & (~((v1843 - v1845) >> 31)));
  v1->timer = v1946;
  int v1847 = v1->timer;
  int * v1848 = v1->reg_ready;
  int v1849 = v1848[31];
  int v1949 = v1849 + ((v1847 - v1849) & (~((v1847 - v1849) >> 31)));
  v1->timer = v1949;
  return v1;
}

struct StateT * slot_8(struct StateT * v649) {
  int v650 = v649->timer;
  int v651 = v649->timer;
  int v663 = v651 + 1;
  v649->timer = v663;
  int * v653 = v649->reg_ready;
  int v654 = v653[10];
  int * v655 = v649->regs;
  int v656 = v655[10];
  int * v657 = v649->reg_ready;
  int v669 = (v654 + ((v650 - v654) & (~((v650 - v654) >> 31)))) + 1;
  v657[6] = v669;
  int * v659 = v649->regs;
  int v671 = (int)((unsigned int)v656 >> 8);
  v659[6] = v671;
  struct StateT * v661 = slot_9(v649);
  return v661;
}

struct StateT * slot_4(struct StateT * v315) {
  int v316 = v315->timer;
  int v317 = v315->timer;
  int v329 = v317 + 1;
  v315->timer = v329;
  int * v319 = v315->reg_ready;
  int v320 = v319[6];
  int * v321 = v315->regs;
  int v322 = v321[6];
  int * v323 = v315->reg_ready;
  int v334 = (v320 + ((v316 - v320) & (~((v316 - v320) >> 31)))) + 1;
  v323[6] = v334;
  int * v325 = v315->regs;
  int v336 = v322 & 63;
  v325[6] = v336;
  struct StateT * v327 = slot_5(v315);
  return v327;
}

struct StateT * slot_15(struct StateT * v1057) {
  int v1058 = v1057->timer;
  int v1059 = v1057->timer;
  int v1071 = v1059 + 1;
  v1057->timer = v1071;
  int * v1061 = v1057->reg_ready;
  int v1062 = v1061[6];
  int * v1063 = v1057->regs;
  int v1064 = v1063[6];
  int * v1065 = v1057->reg_ready;
  int v1076 = (v1062 + ((v1058 - v1062) & (~((v1058 - v1062) >> 31)))) + 1;
  v1065[6] = v1076;
  int * v1067 = v1057->regs;
  int v1078 = v1064 << 2;
  v1067[6] = v1078;
  struct StateT * v1069 = slot_16(v1057);
  return v1069;
}

struct StateT * slot_18(struct StateT * v1367) {
  int v1368 = v1367->timer;
  int v1369 = v1367->timer;
  int v1381 = v1369 + 1;
  v1367->timer = v1381;
  int * v1371 = v1367->reg_ready;
  int v1372 = v1371[10];
  int * v1373 = v1367->regs;
  int v1374 = v1373[10];
  int * v1375 = v1367->reg_ready;
  int v1387 = (v1372 + ((v1368 - v1372) & (~((v1368 - v1372) >> 31)))) + 1;
  v1375[6] = v1387;
  int * v1377 = v1367->regs;
  int v1389 = (int)((unsigned int)v1374 >> 24);
  v1377[6] = v1389;
  struct StateT * v1379 = slot_19(v1367);
  return v1379;
}

struct StateT * slot_9(struct StateT * v674) {
  int v675 = v674->timer;
  int v676 = v674->timer;
  int v688 = v676 + 1;
  v674->timer = v688;
  int * v678 = v674->reg_ready;
  int v679 = v678[6];
  int * v680 = v674->regs;
  int v681 = v680[6];
  int * v682 = v674->reg_ready;
  int v693 = (v679 + ((v675 - v679) & (~((v675 - v679) >> 31)))) + 1;
  v682[6] = v693;
  int * v684 = v674->regs;
  int v695 = v681 & 63;
  v684[6] = v695;
  struct StateT * v686 = slot_10(v674);
  return v686;
}

struct StateT * slot_22(struct StateT * v1695) {
  int v1696 = v1695->timer;
  int v1697 = v1695->timer;
  int v1712 = v1697 + 1;
  v1695->timer = v1712;
  int * v1699 = v1695->reg_ready;
  int v1700 = v1699[5];
  int * v1701 = v1695->regs;
  int v1702 = v1701[5];
  int * v1703 = v1695->reg_ready;
  int v1704 = v1703[7];
  int * v1705 = v1695->regs;
  int v1706 = v1705[7];
  int * v1707 = v1695->reg_ready;
  int v1720 = (v1704 + (((v1700 + ((v1696 - v1700) & (~((v1696 - v1700) >> 31)))) - v1704) & (~(((v1700 + ((v1696 - v1700) & (~((v1696 - v1700) >> 31)))) - v1704) >> 31)))) + 1;
  v1707[5] = v1720;
  int * v1709 = v1695->regs;
  int v1722 = v1702 ^ v1706;
  v1709[5] = v1722;
  return v1695;
}

struct StateT * slot_11(struct StateT * v722) {
  int v723 = v722->timer;
  int v724 = v722->timer;
  int v859 = v724 + 1;
  v722->timer = v859;
  int * v726 = v722->reg_ready;
  int v727 = v726[6];
  int * v728 = v722->regs;
  int v729 = v728[6];
  int * v730 = v722->cache_tags;
  int v864 = (((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2;
  int v731 = v730[v864];
  int * v732 = v722->cache_tags;
  int v866 = ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + 1;
  int v733 = v732[v866];
  int * v734 = v722->cache_tags;
  int v868 = 4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2);
  int v735 = v734[v868];
  int * v736 = v722->cache_tags;
  int v870 = (4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v737 = v736[v870];
  int * v738 = v722->cache_vals;
  bool v871 = !(((~(((v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) == 0);
  int v851;
  if (v871) {
    int * v739 = v722->cache_age;
    int v873 = ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) & 1);
    int v740 = v739[v873];
    int * v741 = v722->cache_age;
    int v742 = v741[v864];
    int * v743 = v722->cache_age;
    int v876 = v742 + ((int)((unsigned int)(v742 - v740) >> 31));
    v743[v864] = v876;
    int * v745 = v722->cache_age;
    int v746 = v745[v866];
    int * v747 = v722->cache_age;
    int v879 = v746 + ((int)((unsigned int)(v746 - v740) >> 31));
    v747[v866] = v879;
    int * v749 = v722->cache_age;
    v749[v873] = 0;
    v851 = v873;
  } else {
    int * v752 = v722->cache_age;
    int v883 = (((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2;
    int v753 = v752[v883];
    int * v754 = v722->cache_tags;
    int v755 = v754[v883];
    int * v756 = v722->cache_age;
    int v757 = v756[v866];
    int * v758 = v722->cache_tags;
    int v759 = v758[v866];
    bool v887 = !(((~(((v735 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v735 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) == 0);
    int v823;
    if (v887) {
      int * v760 = v722->cache_age;
      int v889 = (4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) & 1);
      int v761 = v760[v889];
      int * v762 = v722->cache_age;
      int v763 = v762[v868];
      int * v764 = v722->cache_age;
      int v892 = v763 + ((int)((unsigned int)(v763 - v761) >> 31));
      v764[v868] = v892;
      int * v766 = v722->cache_age;
      int v767 = v766[v870];
      int * v768 = v722->cache_age;
      int v895 = v767 + ((int)((unsigned int)(v767 - v761) >> 31));
      v768[v870] = v895;
      int * v770 = v722->cache_age;
      v770[v889] = 0;
      v823 = v889;
    } else {
      int * v773 = v722->cache_age;
      int v899 = 4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2);
      int v774 = v773[v899];
      int * v775 = v722->cache_tags;
      int v776 = v775[v899];
      int * v777 = v722->cache_age;
      int v778 = v777[v870];
      int * v779 = v722->cache_tags;
      int v780 = v779[v870];
      int * v781 = v722->cache_dirty;
      int v904 = (4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v774 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2)) - (v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v782 = v781[v904];
      bool v905 = !(v782 == 0);
      if (v905) {
        int * v783 = v722->cache_tags;
        int v784 = v783[v904];
        int * v785 = v722->cache_vals;
        int v908 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v774 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2)) - (v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v786 = v785[v908];
        int * v787 = v722->cache_vals;
        int v910 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v774 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2)) - (v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v788 = v787[v910];
        int * v789 = v722->mem;
        int v912 = v784 * 2;
        v789[v912] = v786;
        int * v791 = v722->mem;
        int v915 = (v784 * 2) + 1;
        v791[v915] = v788;
        ;
      } else {
        ;
      }
      int * v796 = v722->mem;
      int v920 = ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) * 2;
      int v797 = v796[v920];
      int * v798 = v722->mem;
      int v922 = (((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) * 2) + 1;
      int v799 = v798[v922];
      int * v800 = v722->cache_vals;
      int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v774 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2)) - (v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v800[v924] = v797;
      int * v802 = v722->cache_vals;
      int v927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 3) * 2)) + ((((v774 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2)) - (v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v802[v927] = v799;
      int * v804 = v722->cache_tags;
      int v930 = (int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1);
      v804[v904] = v930;
      int * v806 = v722->cache_dirty;
      v806[v904] = 0;
      int * v808 = v722->cache_age;
      v808[v904] = 1;
      int * v810 = v722->cache_age;
      int v811 = v810[v904];
      int * v812 = v722->cache_age;
      int v813 = v812[v868];
      int * v814 = v722->cache_age;
      int v938 = v813 + ((int)((unsigned int)(v813 - v811) >> 31));
      v814[v868] = v938;
      int * v816 = v722->cache_age;
      int v817 = v816[v870];
      int * v818 = v722->cache_age;
      int v941 = v817 + ((int)((unsigned int)(v817 - v811) >> 31));
      v818[v870] = v941;
      int * v820 = v722->cache_age;
      v820[v904] = 0;
      v823 = v904;
    }
    int * v824 = v722->cache_vals;
    int v944 = v823 * 2;
    int v825 = v824[v944];
    int * v826 = v722->cache_vals;
    int v946 = (v823 * 2) + 1;
    int v827 = v826[v946];
    int * v828 = v722->cache_vals;
    int v948 = (((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((((v753 + ((~(((v755 ^ -1) | (-(v755 ^ -1))) >> 31)) & 2)) - (v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v828[v948] = v825;
    int * v830 = v722->cache_vals;
    int v951 = ((((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((((v753 + ((~(((v755 ^ -1) | (-(v755 ^ -1))) >> 31)) & 2)) - (v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v830[v951] = v827;
    int * v832 = v722->cache_tags;
    int v954 = ((((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1)) & 1) * 2) + ((((v753 + ((~(((v755 ^ -1) | (-(v755 ^ -1))) >> 31)) & 2)) - (v757 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v955 = (int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1);
    v832[v954] = v955;
    int * v834 = v722->cache_dirty;
    v834[v954] = 0;
    int * v836 = v722->cache_age;
    v836[v954] = 1;
    int * v838 = v722->cache_age;
    int v839 = v838[v954];
    int * v840 = v722->cache_age;
    int v841 = v840[v864];
    int * v842 = v722->cache_age;
    int v963 = v841 + ((int)((unsigned int)(v841 - v839) >> 31));
    v842[v864] = v963;
    int * v844 = v722->cache_age;
    int v845 = v844[v866];
    int * v846 = v722->cache_age;
    int v966 = v845 + ((int)((unsigned int)(v845 - v839) >> 31));
    v846[v866] = v966;
    int * v848 = v722->cache_age;
    v848[v954] = 0;
    v851 = v954;
  }
  int v969 = (v851 * 2) + (((int)((unsigned int)v729 >> 2)) & 1);
  int v852 = v738[v969];
  int * v853 = v722->reg_ready;
  int v972 = ((v727 + ((v723 - v727) & (~((v723 - v727) >> 31)))) + 1) + ((100 ^ (((~(((v735 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v735 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v731 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v733 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v735 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v735 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31)) | (~(((v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))) | (-(v737 ^ ((int)((unsigned int)((int)((unsigned int)v729 >> 2)) >> 1))))) >> 31))) & 104)))));
  v853[7] = v972;
  int * v855 = v722->regs;
  v855[7] = v852;
  struct StateT * v857 = slot_12(v722);
  return v857;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
    s->reg_ready[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
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