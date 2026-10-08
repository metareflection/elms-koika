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

struct StateT * slot_12(struct StateT * v789);
struct StateT * slot_34(struct StateT * v2679);
struct StateT * slot_6(struct StateT * v486);
struct StateT * slot_29(struct StateT * v2431);
struct StateT * slot_16(struct StateT * v1052);
struct StateT * slot_5(struct StateT * v279);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v509);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_26(struct StateT * v1881);
struct StateT * slot_10(struct StateT * v768);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1300);
struct StateT * slot_13(struct StateT * v813);
struct StateT * slot_24(struct StateT * v1844);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1020);
struct StateT * slot_28(struct StateT * v2224);
struct StateT * slot_32(struct StateT * v2460);
struct StateT * slot_20(struct StateT * v1619);
struct StateT * slot_33(struct StateT * v2468);
struct StateT * slot_37(struct StateT * v3035);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_39(struct StateT * v3048);
struct StateT * slot_8(struct StateT * v530);
struct StateT * slot_30(struct StateT * v2436);
struct StateT * slot_4(struct StateT * v256);
struct StateT * slot_15(struct StateT * v1044);
struct StateT * slot_18(struct StateT * v1279);
struct StateT * slot_22(struct StateT * v1632);
struct StateT * slot_35(struct StateT * v2695);
struct StateT * slot_12(struct StateT * v789) {
  int v790 = v789->timer;
  int v803 = v790 + 1;
  v789->timer = v803;
  int * v792 = v789->reg_ready;
  int v793 = v792[14];
  int * v794 = v789->regs;
  int v795 = v794[14];
  int v796 = v792[10];
  int v797 = v794[10];
  int v808 = (v796 + (((v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) - v796) & (~(((v793 + ((v790 - v793) & (~((v790 - v793) >> 31)))) - v796) >> 31)))) + 1;
  v792[10] = v808;
  int * v799 = v789->regs;
  int v810 = v795 + v797;
  v799[10] = v810;
  struct StateT * v801 = slot_13(v789);
  return v801;
}

struct StateT * slot_34(struct StateT * v2679) {
  int v2680 = v2679->timer;
  int v2688 = v2680 + 1;
  v2679->timer = v2688;
  int * v2682 = v2679->reg_ready;
  v2682[10] = v2688;
  int * v2684 = v2679->regs;
  v2684[10] = 0;
  struct StateT * v2686 = slot_19(v2679);
  return v2686;
}

struct StateT * slot_6(struct StateT * v486) {
  int * v487 = v486->saved_regs;
  int * v488 = v486->regs;
  int v489 = v488[14];
  v487[14] = v489;
  int v491 = v486->timer;
  int v503 = v491 + 1;
  v486->timer = v503;
  int * v493 = v486->reg_ready;
  v493[14] = v503;
  int * v495 = v486->regs;
  v495[14] = 0;
  struct StateT * v497 = slot_7(v486);
  return v497;
}

struct StateT * slot_29(struct StateT * v2431) {
  int v2432 = v2431->timer;
  int v2435 = v2432 + 1;
  v2431->timer = v2435;
  return v2431;
}

struct StateT * slot_16(struct StateT * v1052) {
  int * v1053 = v1052->regs;
  int v1054 = v1053[13];
  bool v1161 = !(v1054 == 0);
  struct StateT * v1157;
  if (v1161) {
    int v1055 = v1052->timer;
    int v1162 = v1055 + 15;
    v1052->timer = v1162;
    int * v1057 = v1052->reg_ready;
    int v1058 = v1052->timer;
    v1057[0] = v1058;
    int * v1060 = v1052->reg_ready;
    int v1061 = v1052->timer;
    v1060[1] = v1061;
    int * v1063 = v1052->reg_ready;
    int v1064 = v1052->timer;
    v1063[2] = v1064;
    int * v1066 = v1052->reg_ready;
    int v1067 = v1052->timer;
    v1066[3] = v1067;
    int * v1069 = v1052->reg_ready;
    int v1070 = v1052->timer;
    v1069[4] = v1070;
    int * v1072 = v1052->reg_ready;
    int v1073 = v1052->timer;
    v1072[5] = v1073;
    int * v1075 = v1052->reg_ready;
    int v1076 = v1052->timer;
    v1075[6] = v1076;
    int * v1078 = v1052->reg_ready;
    int v1079 = v1052->timer;
    v1078[7] = v1079;
    int * v1081 = v1052->reg_ready;
    int v1082 = v1052->timer;
    v1081[8] = v1082;
    int * v1084 = v1052->reg_ready;
    int v1085 = v1052->timer;
    v1084[9] = v1085;
    int * v1087 = v1052->reg_ready;
    int v1088 = v1052->timer;
    v1087[10] = v1088;
    int * v1090 = v1052->reg_ready;
    int v1091 = v1052->timer;
    v1090[11] = v1091;
    int * v1093 = v1052->reg_ready;
    int v1094 = v1052->timer;
    v1093[12] = v1094;
    int * v1096 = v1052->reg_ready;
    int v1097 = v1052->timer;
    v1096[13] = v1097;
    int * v1099 = v1052->reg_ready;
    int v1100 = v1052->timer;
    v1099[14] = v1100;
    int * v1102 = v1052->reg_ready;
    int v1103 = v1052->timer;
    v1102[15] = v1103;
    int * v1105 = v1052->reg_ready;
    int v1106 = v1052->timer;
    v1105[16] = v1106;
    int * v1108 = v1052->reg_ready;
    int v1109 = v1052->timer;
    v1108[17] = v1109;
    int * v1111 = v1052->reg_ready;
    int v1112 = v1052->timer;
    v1111[18] = v1112;
    int * v1114 = v1052->reg_ready;
    int v1115 = v1052->timer;
    v1114[19] = v1115;
    int * v1117 = v1052->reg_ready;
    int v1118 = v1052->timer;
    v1117[20] = v1118;
    int * v1120 = v1052->reg_ready;
    int v1121 = v1052->timer;
    v1120[21] = v1121;
    int * v1123 = v1052->reg_ready;
    int v1124 = v1052->timer;
    v1123[22] = v1124;
    int * v1126 = v1052->reg_ready;
    int v1127 = v1052->timer;
    v1126[23] = v1127;
    int * v1129 = v1052->reg_ready;
    int v1130 = v1052->timer;
    v1129[24] = v1130;
    int * v1132 = v1052->reg_ready;
    int v1133 = v1052->timer;
    v1132[25] = v1133;
    int * v1135 = v1052->reg_ready;
    int v1136 = v1052->timer;
    v1135[26] = v1136;
    int * v1138 = v1052->reg_ready;
    int v1139 = v1052->timer;
    v1138[27] = v1139;
    int * v1141 = v1052->reg_ready;
    int v1142 = v1052->timer;
    v1141[28] = v1142;
    int * v1144 = v1052->reg_ready;
    int v1145 = v1052->timer;
    v1144[29] = v1145;
    int * v1147 = v1052->reg_ready;
    int v1148 = v1052->timer;
    v1147[30] = v1148;
    int * v1150 = v1052->reg_ready;
    int v1151 = v1052->timer;
    v1150[31] = v1151;
    struct StateT * v1153 = slot_34(v1052);
    v1157 = v1153;
  } else {
    struct StateT * v1155 = slot_18(v1052);
    v1157 = v1155;
  }
  return v1157;
}

struct StateT * slot_5(struct StateT * v279) {
  int v280 = v279->timer;
  int v392 = v280 + 1;
  v279->timer = v392;
  int * v282 = v279->reg_ready;
  int v283 = v282[12];
  int * v284 = v279->regs;
  int v285 = v284[12];
  int * v286 = v279->cache_tags;
  int v397 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2;
  int v287 = v286[v397];
  int v398 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v288 = v286[v398];
  int v399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2);
  int v289 = v286[v399];
  int v400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v290 = v286[v400];
  int * v291 = v279->cache_vals;
  bool v401 = !(((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v384;
  if (v401) {
    int * v292 = v279->cache_age;
    int v403 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v293 = v292[v403];
    int v294 = v292[v397];
    int v404 = v294 + ((int)((unsigned int)(v294 - v293) >> 31));
    v292[v397] = v404;
    int * v296 = v279->cache_age;
    int v297 = v296[v398];
    int v406 = v297 + ((int)((unsigned int)(v297 - v293) >> 31));
    v296[v398] = v406;
    int * v299 = v279->cache_age;
    v299[v403] = 0;
    v384 = v403;
  } else {
    int * v302 = v279->cache_age;
    int v410 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2;
    int v303 = v302[v410];
    int * v304 = v279->cache_tags;
    int v305 = v304[v410];
    int v306 = v302[v398];
    int v307 = v304[v398];
    bool v412 = !(((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v361;
    if (v412) {
      int * v308 = v279->cache_age;
      int v414 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v309 = v308[v414];
      int v310 = v308[v399];
      int v415 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
      v308[v399] = v415;
      int * v312 = v279->cache_age;
      int v313 = v312[v400];
      int v417 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
      v312[v400] = v417;
      int * v315 = v279->cache_age;
      v315[v414] = 0;
      v361 = v414;
    } else {
      int * v318 = v279->cache_age;
      int v421 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2);
      int v319 = v318[v421];
      int * v320 = v279->cache_tags;
      int v321 = v320[v421];
      int v322 = v318[v400];
      int v323 = v320[v400];
      int * v324 = v279->cache_dirty;
      int v424 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v325 = v324[v424];
      bool v425 = !(v325 == 0);
      if (v425) {
        int * v326 = v279->cache_tags;
        int v327 = v326[v424];
        int * v328 = v279->cache_vals;
        int v428 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v329 = v328[v428];
        int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v330 = v328[v429];
        int * v331 = v279->mem;
        int v431 = v327 * 2;
        v331[v431] = v329;
        int * v333 = v279->mem;
        int v434 = (v327 * 2) + 1;
        v333[v434] = v330;
        ;
      } else {
        ;
      }
      int * v338 = v279->mem;
      int v439 = ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) * 2;
      int v339 = v338[v439];
      int v440 = (((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) * 2) + 1;
      int v340 = v338[v440];
      int * v341 = v279->cache_vals;
      int v442 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v341[v442] = v339;
      int * v343 = v279->cache_vals;
      int v445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v343[v445] = v340;
      int * v345 = v279->cache_tags;
      int v448 = (int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1);
      v345[v424] = v448;
      int * v347 = v279->cache_dirty;
      v347[v424] = 0;
      int * v349 = v279->cache_age;
      v349[v424] = 1;
      int * v351 = v279->cache_age;
      int v352 = v351[v424];
      int v353 = v351[v399];
      int v454 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
      v351[v399] = v454;
      int * v355 = v279->cache_age;
      int v356 = v355[v400];
      int v456 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
      v355[v400] = v456;
      int * v358 = v279->cache_age;
      v358[v424] = 0;
      v361 = v424;
    }
    int * v362 = v279->cache_vals;
    int v459 = v361 * 2;
    int v363 = v362[v459];
    int v460 = (v361 * 2) + 1;
    int v364 = v362[v460];
    int v461 = (((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v362[v461] = v363;
    int * v366 = v279->cache_vals;
    int v464 = ((((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v366[v464] = v364;
    int * v368 = v279->cache_tags;
    int v467 = ((((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v303 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v468 = (int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1);
    v368[v467] = v468;
    int * v370 = v279->cache_dirty;
    v370[v467] = 0;
    int * v372 = v279->cache_age;
    v372[v467] = 1;
    int * v374 = v279->cache_age;
    int v375 = v374[v467];
    int v376 = v374[v397];
    int v474 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
    v374[v397] = v474;
    int * v378 = v279->cache_age;
    int v379 = v378[v398];
    int v476 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
    v378[v398] = v476;
    int * v381 = v279->cache_age;
    v381[v467] = 0;
    v384 = v467;
  }
  int v479 = (v384 * 2) + (((int)((unsigned int)(v285 + 68) >> 2)) & 1);
  int v385 = v291[v479];
  int * v386 = v279->reg_ready;
  int v481 = ((v283 + ((v280 - v283) & (~((v280 - v283) >> 31)))) + 1) + ((100 ^ (((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v287 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v288 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v289 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))) | (-(v290 ^ ((int)((unsigned int)((int)((unsigned int)(v285 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v386[12] = v481;
  int * v388 = v279->regs;
  v388[12] = v385;
  struct StateT * v390 = slot_6(v279);
  return v390;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v509) {
  int v510 = v509->timer;
  int v521 = v510 + 1;
  v509->timer = v521;
  int * v512 = v509->reg_ready;
  int v513 = v512[14];
  int * v514 = v509->regs;
  int v515 = v514[14];
  int v525 = (v513 + ((v510 - v513) & (~((v510 - v513) >> 31)))) + 1;
  v512[14] = v525;
  int * v517 = v509->regs;
  int v527 = v515 + 72;
  v517[14] = v527;
  struct StateT * v519 = slot_8(v509);
  return v519;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[13];
  v234[13] = v236;
  int v238 = v233->timer;
  int v250 = v238 + 1;
  v233->timer = v250;
  int * v240 = v233->reg_ready;
  v240[13] = v250;
  int * v242 = v233->regs;
  v242[13] = 0;
  struct StateT * v244 = slot_4(v233);
  return v244;
}

struct StateT * slot_26(struct StateT * v1881) {
  int v1882 = v1881->timer;
  int v1895 = v1882 + 1;
  v1881->timer = v1895;
  int * v1884 = v1881->reg_ready;
  int v1885 = v1884[14];
  int * v1886 = v1881->regs;
  int v1887 = v1886[14];
  int v1888 = v1884[10];
  int v1889 = v1886[10];
  int v1900 = (v1888 + (((v1885 + ((v1882 - v1885) & (~((v1882 - v1885) >> 31)))) - v1888) & (~(((v1885 + ((v1882 - v1885) & (~((v1882 - v1885) >> 31)))) - v1888) >> 31)))) + 1;
  v1884[10] = v1900;
  int * v1891 = v1881->regs;
  int v1902 = v1887 + v1889;
  v1891[10] = v1902;
  struct StateT * v1893 = slot_28(v1881);
  return v1893;
}

struct StateT * slot_10(struct StateT * v768) {
  int v769 = v768->timer;
  int v780 = v769 + 1;
  v768->timer = v780;
  int * v771 = v768->reg_ready;
  int v772 = v771[10];
  int * v773 = v768->regs;
  int v774 = v773[10];
  int v784 = (v772 + ((v769 - v772) & (~((v769 - v772) >> 31)))) + 1;
  v771[10] = v784;
  int * v776 = v768->regs;
  int v786 = v774 << 2;
  v776[10] = v786;
  struct StateT * v778 = slot_12(v768);
  return v778;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[11];
  int * v23 = v18->regs;
  int v24 = v23[11];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v220 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[11] = v220;
  int * v127 = v18->regs;
  v127[11] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_19(struct StateT * v1300) {
  int v1301 = v1300->timer;
  int v1474 = v1301 + 1;
  v1300->timer = v1474;
  int * v1303 = v1300->reg_ready;
  int * v1305 = v1300->regs;
  int v1306 = v1305[10];
  int v1308 = v1305[12];
  int * v1309 = v1300->cache_tags;
  int v1480 = (((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1310 = v1309[v1480];
  int v1481 = ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1311 = v1309[v1481];
  int v1482 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1312 = v1309[v1482];
  int v1483 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1313 = v1309[v1483];
  int v1314 = v1300->timer;
  int v1484 = v1314 + ((100 ^ (((~(((v1312 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1312 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1311 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1311 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1312 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1312 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1300->timer = v1484;
  bool v1485 = !(((~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1311 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1311 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1408;
  if (v1485) {
    int * v1316 = v1300->cache_age;
    int v1487 = ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1311 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1311 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1317 = v1316[v1487];
    int v1318 = v1316[v1480];
    int v1488 = v1318 + ((int)((unsigned int)(v1318 - v1317) >> 31));
    v1316[v1480] = v1488;
    int * v1320 = v1300->cache_age;
    int v1321 = v1320[v1481];
    int v1490 = v1321 + ((int)((unsigned int)(v1321 - v1317) >> 31));
    v1320[v1481] = v1490;
    int * v1323 = v1300->cache_age;
    v1323[v1487] = 0;
    v1408 = v1487;
  } else {
    int * v1326 = v1300->cache_age;
    int v1494 = (((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1327 = v1326[v1494];
    int * v1328 = v1300->cache_tags;
    int v1329 = v1328[v1494];
    int v1330 = v1326[v1481];
    int v1331 = v1328[v1481];
    bool v1496 = !(((~(((v1312 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1312 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1385;
    if (v1496) {
      int * v1332 = v1300->cache_age;
      int v1498 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1313 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1333 = v1332[v1498];
      int v1334 = v1332[v1482];
      int v1499 = v1334 + ((int)((unsigned int)(v1334 - v1333) >> 31));
      v1332[v1482] = v1499;
      int * v1336 = v1300->cache_age;
      int v1337 = v1336[v1483];
      int v1501 = v1337 + ((int)((unsigned int)(v1337 - v1333) >> 31));
      v1336[v1483] = v1501;
      int * v1339 = v1300->cache_age;
      v1339[v1498] = 0;
      v1385 = v1498;
    } else {
      int * v1342 = v1300->cache_age;
      int v1505 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1343 = v1342[v1505];
      int * v1344 = v1300->cache_tags;
      int v1345 = v1344[v1505];
      int v1346 = v1342[v1483];
      int v1347 = v1344[v1483];
      int * v1348 = v1300->cache_dirty;
      int v1508 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1343 + ((~(((v1345 ^ -1) | (-(v1345 ^ -1))) >> 31)) & 2)) - (v1346 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1349 = v1348[v1508];
      bool v1509 = !(v1349 == 0);
      if (v1509) {
        int * v1350 = v1300->cache_tags;
        int v1351 = v1350[v1508];
        int * v1352 = v1300->cache_vals;
        int v1512 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1343 + ((~(((v1345 ^ -1) | (-(v1345 ^ -1))) >> 31)) & 2)) - (v1346 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1353 = v1352[v1512];
        int v1513 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1343 + ((~(((v1345 ^ -1) | (-(v1345 ^ -1))) >> 31)) & 2)) - (v1346 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1354 = v1352[v1513];
        int * v1355 = v1300->mem;
        int v1515 = v1351 * 2;
        v1355[v1515] = v1353;
        int * v1357 = v1300->mem;
        int v1518 = (v1351 * 2) + 1;
        v1357[v1518] = v1354;
        ;
      } else {
        ;
      }
      int * v1362 = v1300->mem;
      int v1523 = ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) * 2;
      int v1363 = v1362[v1523];
      int v1524 = (((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1364 = v1362[v1524];
      int * v1365 = v1300->cache_vals;
      int v1526 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1343 + ((~(((v1345 ^ -1) | (-(v1345 ^ -1))) >> 31)) & 2)) - (v1346 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1365[v1526] = v1363;
      int * v1367 = v1300->cache_vals;
      int v1529 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1343 + ((~(((v1345 ^ -1) | (-(v1345 ^ -1))) >> 31)) & 2)) - (v1346 + ((~(((v1347 ^ -1) | (-(v1347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1367[v1529] = v1364;
      int * v1369 = v1300->cache_tags;
      int v1532 = (int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1);
      v1369[v1508] = v1532;
      int * v1371 = v1300->cache_dirty;
      v1371[v1508] = 0;
      int * v1373 = v1300->cache_age;
      v1373[v1508] = 1;
      int * v1375 = v1300->cache_age;
      int v1376 = v1375[v1508];
      int v1377 = v1375[v1482];
      int v1538 = v1377 + ((int)((unsigned int)(v1377 - v1376) >> 31));
      v1375[v1482] = v1538;
      int * v1379 = v1300->cache_age;
      int v1380 = v1379[v1483];
      int v1540 = v1380 + ((int)((unsigned int)(v1380 - v1376) >> 31));
      v1379[v1483] = v1540;
      int * v1382 = v1300->cache_age;
      v1382[v1508] = 0;
      v1385 = v1508;
    }
    int * v1386 = v1300->cache_vals;
    int v1543 = v1385 * 2;
    int v1387 = v1386[v1543];
    int v1544 = (v1385 * 2) + 1;
    int v1388 = v1386[v1544];
    int v1545 = (((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1327 + ((~(((v1329 ^ -1) | (-(v1329 ^ -1))) >> 31)) & 2)) - (v1330 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1386[v1545] = v1387;
    int * v1390 = v1300->cache_vals;
    int v1548 = ((((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1327 + ((~(((v1329 ^ -1) | (-(v1329 ^ -1))) >> 31)) & 2)) - (v1330 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1390[v1548] = v1388;
    int * v1392 = v1300->cache_tags;
    int v1551 = ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1327 + ((~(((v1329 ^ -1) | (-(v1329 ^ -1))) >> 31)) & 2)) - (v1330 + ((~(((v1331 ^ -1) | (-(v1331 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1552 = (int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1);
    v1392[v1551] = v1552;
    int * v1394 = v1300->cache_dirty;
    v1394[v1551] = 0;
    int * v1396 = v1300->cache_age;
    v1396[v1551] = 1;
    int * v1398 = v1300->cache_age;
    int v1399 = v1398[v1551];
    int v1400 = v1398[v1480];
    int v1558 = v1400 + ((int)((unsigned int)(v1400 - v1399) >> 31));
    v1398[v1480] = v1558;
    int * v1402 = v1300->cache_age;
    int v1403 = v1402[v1481];
    int v1560 = v1403 + ((int)((unsigned int)(v1403 - v1399) >> 31));
    v1402[v1481] = v1560;
    int * v1405 = v1300->cache_age;
    v1405[v1551] = 0;
    v1408 = v1551;
  }
  int * v1409 = v1300->cache_vals;
  int v1563 = (v1408 * 2) + (((int)((unsigned int)(v1306 + 68) >> 2)) & 1);
  v1409[v1563] = v1308;
  int * v1411 = v1300->cache_tags;
  int v1412 = v1411[v1482];
  int v1413 = v1411[v1483];
  bool v1566 = !(((~(((v1412 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1412 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1413 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1413 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1467;
  if (v1566) {
    int * v1414 = v1300->cache_age;
    int v1568 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1413 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))) | (-(v1413 ^ ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1415 = v1414[v1568];
    int v1416 = v1414[v1482];
    int v1569 = v1416 + ((int)((unsigned int)(v1416 - v1415) >> 31));
    v1414[v1482] = v1569;
    int * v1418 = v1300->cache_age;
    int v1419 = v1418[v1483];
    int v1571 = v1419 + ((int)((unsigned int)(v1419 - v1415) >> 31));
    v1418[v1483] = v1571;
    int * v1421 = v1300->cache_age;
    v1421[v1568] = 0;
    v1467 = v1568;
  } else {
    int * v1424 = v1300->cache_age;
    int v1575 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1425 = v1424[v1575];
    int * v1426 = v1300->cache_tags;
    int v1427 = v1426[v1575];
    int v1428 = v1424[v1483];
    int v1429 = v1426[v1483];
    int * v1430 = v1300->cache_dirty;
    int v1578 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1425 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2)) - (v1428 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1431 = v1430[v1578];
    bool v1579 = !(v1431 == 0);
    if (v1579) {
      int * v1432 = v1300->cache_tags;
      int v1433 = v1432[v1578];
      int * v1434 = v1300->cache_vals;
      int v1582 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1425 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2)) - (v1428 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1435 = v1434[v1582];
      int v1583 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1425 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2)) - (v1428 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1436 = v1434[v1583];
      int * v1437 = v1300->mem;
      int v1585 = v1433 * 2;
      v1437[v1585] = v1435;
      int * v1439 = v1300->mem;
      int v1588 = (v1433 * 2) + 1;
      v1439[v1588] = v1436;
      ;
    } else {
      ;
    }
    int * v1444 = v1300->mem;
    int v1593 = ((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) * 2;
    int v1445 = v1444[v1593];
    int v1594 = (((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1446 = v1444[v1594];
    int * v1447 = v1300->cache_vals;
    int v1596 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1425 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2)) - (v1428 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1447[v1596] = v1445;
    int * v1449 = v1300->cache_vals;
    int v1599 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1425 + ((~(((v1427 ^ -1) | (-(v1427 ^ -1))) >> 31)) & 2)) - (v1428 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1449[v1599] = v1446;
    int * v1451 = v1300->cache_tags;
    int v1602 = (int)((unsigned int)((int)((unsigned int)(v1306 + 68) >> 2)) >> 1);
    v1451[v1578] = v1602;
    int * v1453 = v1300->cache_dirty;
    v1453[v1578] = 0;
    int * v1455 = v1300->cache_age;
    v1455[v1578] = 1;
    int * v1457 = v1300->cache_age;
    int v1458 = v1457[v1578];
    int v1459 = v1457[v1482];
    int v1608 = v1459 + ((int)((unsigned int)(v1459 - v1458) >> 31));
    v1457[v1482] = v1608;
    int * v1461 = v1300->cache_age;
    int v1462 = v1461[v1483];
    int v1610 = v1462 + ((int)((unsigned int)(v1462 - v1458) >> 31));
    v1461[v1483] = v1610;
    int * v1464 = v1300->cache_age;
    v1464[v1578] = 0;
    v1467 = v1578;
  }
  int * v1468 = v1300->cache_vals;
  int v1613 = (v1467 * 2) + (((int)((unsigned int)(v1306 + 68) >> 2)) & 1);
  v1468[v1613] = v1308;
  int * v1470 = v1300->cache_dirty;
  v1470[v1467] = 1;
  struct StateT * v1472 = slot_29(v1300);
  return v1472;
}

struct StateT * slot_13(struct StateT * v813) {
  int v814 = v813->timer;
  int v926 = v814 + 1;
  v813->timer = v926;
  int * v816 = v813->reg_ready;
  int v817 = v816[10];
  int * v818 = v813->regs;
  int v819 = v818[10];
  int * v820 = v813->cache_tags;
  int v931 = (((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2;
  int v821 = v820[v931];
  int v932 = ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + 1;
  int v822 = v820[v932];
  int v933 = 4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2);
  int v823 = v820[v933];
  int v934 = (4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v824 = v820[v934];
  int * v825 = v813->cache_vals;
  bool v935 = !(((~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) == 0);
  int v918;
  if (v935) {
    int * v826 = v813->cache_age;
    int v937 = ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((~(((v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) & 1);
    int v827 = v826[v937];
    int v828 = v826[v931];
    int v938 = v828 + ((int)((unsigned int)(v828 - v827) >> 31));
    v826[v931] = v938;
    int * v830 = v813->cache_age;
    int v831 = v830[v932];
    int v940 = v831 + ((int)((unsigned int)(v831 - v827) >> 31));
    v830[v932] = v940;
    int * v833 = v813->cache_age;
    v833[v937] = 0;
    v918 = v937;
  } else {
    int * v836 = v813->cache_age;
    int v944 = (((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2;
    int v837 = v836[v944];
    int * v838 = v813->cache_tags;
    int v839 = v838[v944];
    int v840 = v836[v932];
    int v841 = v838[v932];
    bool v946 = !(((~(((v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) == 0);
    int v895;
    if (v946) {
      int * v842 = v813->cache_age;
      int v948 = (4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) & 1);
      int v843 = v842[v948];
      int v844 = v842[v933];
      int v949 = v844 + ((int)((unsigned int)(v844 - v843) >> 31));
      v842[v933] = v949;
      int * v846 = v813->cache_age;
      int v847 = v846[v934];
      int v951 = v847 + ((int)((unsigned int)(v847 - v843) >> 31));
      v846[v934] = v951;
      int * v849 = v813->cache_age;
      v849[v948] = 0;
      v895 = v948;
    } else {
      int * v852 = v813->cache_age;
      int v955 = 4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2);
      int v853 = v852[v955];
      int * v854 = v813->cache_tags;
      int v855 = v854[v955];
      int v856 = v852[v934];
      int v857 = v854[v934];
      int * v858 = v813->cache_dirty;
      int v958 = (4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v856 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v859 = v858[v958];
      bool v959 = !(v859 == 0);
      if (v959) {
        int * v860 = v813->cache_tags;
        int v861 = v860[v958];
        int * v862 = v813->cache_vals;
        int v962 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v856 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v863 = v862[v962];
        int v963 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v856 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v864 = v862[v963];
        int * v865 = v813->mem;
        int v965 = v861 * 2;
        v865[v965] = v863;
        int * v867 = v813->mem;
        int v968 = (v861 * 2) + 1;
        v867[v968] = v864;
        ;
      } else {
        ;
      }
      int * v872 = v813->mem;
      int v973 = ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) * 2;
      int v873 = v872[v973];
      int v974 = (((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) * 2) + 1;
      int v874 = v872[v974];
      int * v875 = v813->cache_vals;
      int v976 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v856 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v875[v976] = v873;
      int * v877 = v813->cache_vals;
      int v979 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v853 + ((~(((v855 ^ -1) | (-(v855 ^ -1))) >> 31)) & 2)) - (v856 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v877[v979] = v874;
      int * v879 = v813->cache_tags;
      int v982 = (int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1);
      v879[v958] = v982;
      int * v881 = v813->cache_dirty;
      v881[v958] = 0;
      int * v883 = v813->cache_age;
      v883[v958] = 1;
      int * v885 = v813->cache_age;
      int v886 = v885[v958];
      int v887 = v885[v933];
      int v988 = v887 + ((int)((unsigned int)(v887 - v886) >> 31));
      v885[v933] = v988;
      int * v889 = v813->cache_age;
      int v890 = v889[v934];
      int v990 = v890 + ((int)((unsigned int)(v890 - v886) >> 31));
      v889[v934] = v990;
      int * v892 = v813->cache_age;
      v892[v958] = 0;
      v895 = v958;
    }
    int * v896 = v813->cache_vals;
    int v993 = v895 * 2;
    int v897 = v896[v993];
    int v994 = (v895 * 2) + 1;
    int v898 = v896[v994];
    int v995 = (((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v896[v995] = v897;
    int * v900 = v813->cache_vals;
    int v998 = ((((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v900[v998] = v898;
    int * v902 = v813->cache_tags;
    int v1001 = ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1002 = (int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1);
    v902[v1001] = v1002;
    int * v904 = v813->cache_dirty;
    v904[v1001] = 0;
    int * v906 = v813->cache_age;
    v906[v1001] = 1;
    int * v908 = v813->cache_age;
    int v909 = v908[v1001];
    int v910 = v908[v931];
    int v1008 = v910 + ((int)((unsigned int)(v910 - v909) >> 31));
    v908[v931] = v1008;
    int * v912 = v813->cache_age;
    int v913 = v912[v932];
    int v1010 = v913 + ((int)((unsigned int)(v913 - v909) >> 31));
    v912[v932] = v1010;
    int * v915 = v813->cache_age;
    v915[v1001] = 0;
    v918 = v1001;
  }
  int v1013 = (v918 * 2) + (((int)((unsigned int)v819 >> 2)) & 1);
  int v919 = v825[v1013];
  int * v920 = v813->reg_ready;
  int v1015 = ((v817 + ((v814 - v817) & (~((v814 - v817) >> 31)))) + 1) + ((100 ^ (((~(((v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) & 104)))));
  v920[10] = v1015;
  int * v922 = v813->regs;
  v922[10] = v919;
  struct StateT * v924 = slot_14(v813);
  return v924;
}

struct StateT * slot_24(struct StateT * v1844) {
  int v1845 = v1844->timer;
  int v1856 = v1845 + 1;
  v1844->timer = v1856;
  int * v1847 = v1844->reg_ready;
  int v1848 = v1847[10];
  int * v1849 = v1844->regs;
  int v1850 = v1849[10];
  int v1860 = (v1848 + ((v1845 - v1848) & (~((v1845 - v1848) >> 31)))) + 1;
  v1847[10] = v1860;
  int * v1852 = v1844->regs;
  int v1862 = v1850 << 2;
  v1852[10] = v1862;
  struct StateT * v1854 = slot_26(v1844);
  return v1854;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[11] = v11;
  int * v7 = v2->regs;
  v7[11] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v1020) {
  int v1021 = v1020->timer;
  int v1034 = v1021 + 1;
  v1020->timer = v1034;
  int * v1023 = v1020->reg_ready;
  int v1024 = v1023[12];
  int * v1025 = v1020->regs;
  int v1026 = v1025[12];
  int v1027 = v1023[10];
  int v1028 = v1025[10];
  int v1039 = (v1027 + (((v1024 + ((v1021 - v1024) & (~((v1021 - v1024) >> 31)))) - v1027) & (~(((v1024 + ((v1021 - v1024) & (~((v1021 - v1024) >> 31)))) - v1027) >> 31)))) + 1;
  v1023[12] = v1039;
  int * v1030 = v1020->regs;
  int v1041 = v1026 & v1028;
  v1030[12] = v1041;
  struct StateT * v1032 = slot_15(v1020);
  return v1032;
}

struct StateT * slot_28(struct StateT * v2224) {
  int v2225 = v2224->timer;
  int v2337 = v2225 + 1;
  v2224->timer = v2337;
  int * v2227 = v2224->reg_ready;
  int v2228 = v2227[10];
  int * v2229 = v2224->regs;
  int v2230 = v2229[10];
  int * v2231 = v2224->cache_tags;
  int v2342 = (((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2;
  int v2232 = v2231[v2342];
  int v2343 = ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2233 = v2231[v2343];
  int v2344 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2);
  int v2234 = v2231[v2344];
  int v2345 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2235 = v2231[v2345];
  int * v2236 = v2224->cache_vals;
  bool v2346 = !(((~(((v2232 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2232 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) | (~(((v2233 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2233 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31))) == 0);
  int v2329;
  if (v2346) {
    int * v2237 = v2224->cache_age;
    int v2348 = ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2) + ((~(((v2233 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2233 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) & 1);
    int v2238 = v2237[v2348];
    int v2239 = v2237[v2342];
    int v2349 = v2239 + ((int)((unsigned int)(v2239 - v2238) >> 31));
    v2237[v2342] = v2349;
    int * v2241 = v2224->cache_age;
    int v2242 = v2241[v2343];
    int v2351 = v2242 + ((int)((unsigned int)(v2242 - v2238) >> 31));
    v2241[v2343] = v2351;
    int * v2244 = v2224->cache_age;
    v2244[v2348] = 0;
    v2329 = v2348;
  } else {
    int * v2247 = v2224->cache_age;
    int v2355 = (((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2;
    int v2248 = v2247[v2355];
    int * v2249 = v2224->cache_tags;
    int v2250 = v2249[v2355];
    int v2251 = v2247[v2343];
    int v2252 = v2249[v2343];
    bool v2357 = !(((~(((v2234 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2234 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) | (~(((v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31))) == 0);
    int v2306;
    if (v2357) {
      int * v2253 = v2224->cache_age;
      int v2359 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) & 1);
      int v2254 = v2253[v2359];
      int v2255 = v2253[v2344];
      int v2360 = v2255 + ((int)((unsigned int)(v2255 - v2254) >> 31));
      v2253[v2344] = v2360;
      int * v2257 = v2224->cache_age;
      int v2258 = v2257[v2345];
      int v2362 = v2258 + ((int)((unsigned int)(v2258 - v2254) >> 31));
      v2257[v2345] = v2362;
      int * v2260 = v2224->cache_age;
      v2260[v2359] = 0;
      v2306 = v2359;
    } else {
      int * v2263 = v2224->cache_age;
      int v2366 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2);
      int v2264 = v2263[v2366];
      int * v2265 = v2224->cache_tags;
      int v2266 = v2265[v2366];
      int v2267 = v2263[v2345];
      int v2268 = v2265[v2345];
      int * v2269 = v2224->cache_dirty;
      int v2369 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + ((((v2264 + ((~(((v2266 ^ -1) | (-(v2266 ^ -1))) >> 31)) & 2)) - (v2267 + ((~(((v2268 ^ -1) | (-(v2268 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2270 = v2269[v2369];
      bool v2370 = !(v2270 == 0);
      if (v2370) {
        int * v2271 = v2224->cache_tags;
        int v2272 = v2271[v2369];
        int * v2273 = v2224->cache_vals;
        int v2373 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + ((((v2264 + ((~(((v2266 ^ -1) | (-(v2266 ^ -1))) >> 31)) & 2)) - (v2267 + ((~(((v2268 ^ -1) | (-(v2268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2274 = v2273[v2373];
        int v2374 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + ((((v2264 + ((~(((v2266 ^ -1) | (-(v2266 ^ -1))) >> 31)) & 2)) - (v2267 + ((~(((v2268 ^ -1) | (-(v2268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2275 = v2273[v2374];
        int * v2276 = v2224->mem;
        int v2376 = v2272 * 2;
        v2276[v2376] = v2274;
        int * v2278 = v2224->mem;
        int v2379 = (v2272 * 2) + 1;
        v2278[v2379] = v2275;
        ;
      } else {
        ;
      }
      int * v2283 = v2224->mem;
      int v2384 = ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) * 2;
      int v2284 = v2283[v2384];
      int v2385 = (((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) * 2) + 1;
      int v2285 = v2283[v2385];
      int * v2286 = v2224->cache_vals;
      int v2387 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + ((((v2264 + ((~(((v2266 ^ -1) | (-(v2266 ^ -1))) >> 31)) & 2)) - (v2267 + ((~(((v2268 ^ -1) | (-(v2268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2286[v2387] = v2284;
      int * v2288 = v2224->cache_vals;
      int v2390 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 3) * 2)) + ((((v2264 + ((~(((v2266 ^ -1) | (-(v2266 ^ -1))) >> 31)) & 2)) - (v2267 + ((~(((v2268 ^ -1) | (-(v2268 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2288[v2390] = v2285;
      int * v2290 = v2224->cache_tags;
      int v2393 = (int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1);
      v2290[v2369] = v2393;
      int * v2292 = v2224->cache_dirty;
      v2292[v2369] = 0;
      int * v2294 = v2224->cache_age;
      v2294[v2369] = 1;
      int * v2296 = v2224->cache_age;
      int v2297 = v2296[v2369];
      int v2298 = v2296[v2344];
      int v2399 = v2298 + ((int)((unsigned int)(v2298 - v2297) >> 31));
      v2296[v2344] = v2399;
      int * v2300 = v2224->cache_age;
      int v2301 = v2300[v2345];
      int v2401 = v2301 + ((int)((unsigned int)(v2301 - v2297) >> 31));
      v2300[v2345] = v2401;
      int * v2303 = v2224->cache_age;
      v2303[v2369] = 0;
      v2306 = v2369;
    }
    int * v2307 = v2224->cache_vals;
    int v2404 = v2306 * 2;
    int v2308 = v2307[v2404];
    int v2405 = (v2306 * 2) + 1;
    int v2309 = v2307[v2405];
    int v2406 = (((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2) + ((((v2248 + ((~(((v2250 ^ -1) | (-(v2250 ^ -1))) >> 31)) & 2)) - (v2251 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2307[v2406] = v2308;
    int * v2311 = v2224->cache_vals;
    int v2409 = ((((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2) + ((((v2248 + ((~(((v2250 ^ -1) | (-(v2250 ^ -1))) >> 31)) & 2)) - (v2251 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2311[v2409] = v2309;
    int * v2313 = v2224->cache_tags;
    int v2412 = ((((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1)) & 1) * 2) + ((((v2248 + ((~(((v2250 ^ -1) | (-(v2250 ^ -1))) >> 31)) & 2)) - (v2251 + ((~(((v2252 ^ -1) | (-(v2252 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2413 = (int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1);
    v2313[v2412] = v2413;
    int * v2315 = v2224->cache_dirty;
    v2315[v2412] = 0;
    int * v2317 = v2224->cache_age;
    v2317[v2412] = 1;
    int * v2319 = v2224->cache_age;
    int v2320 = v2319[v2412];
    int v2321 = v2319[v2342];
    int v2419 = v2321 + ((int)((unsigned int)(v2321 - v2320) >> 31));
    v2319[v2342] = v2419;
    int * v2323 = v2224->cache_age;
    int v2324 = v2323[v2343];
    int v2421 = v2324 + ((int)((unsigned int)(v2324 - v2320) >> 31));
    v2323[v2343] = v2421;
    int * v2326 = v2224->cache_age;
    v2326[v2412] = 0;
    v2329 = v2412;
  }
  int v2424 = (v2329 * 2) + (((int)((unsigned int)v2230 >> 2)) & 1);
  int v2330 = v2236[v2424];
  int * v2331 = v2224->reg_ready;
  int v2426 = ((v2228 + ((v2225 - v2228) & (~((v2225 - v2228) >> 31)))) + 1) + ((100 ^ (((~(((v2234 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2234 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) | (~(((v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2232 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2232 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) | (~(((v2233 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2233 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2234 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2234 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31)) | (~(((v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))) | (-(v2235 ^ ((int)((unsigned int)((int)((unsigned int)v2230 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2331[10] = v2426;
  int * v2333 = v2224->regs;
  v2333[10] = v2330;
  struct StateT * v2335 = slot_30(v2224);
  return v2335;
}

struct StateT * slot_32(struct StateT * v2460) {
  int v2461 = v2460->timer;
  int v2465 = v2461 + 1;
  v2460->timer = v2465;
  struct StateT * v2463 = slot_33(v2460);
  return v2463;
}

struct StateT * slot_20(struct StateT * v1619) {
  int v1620 = v1619->timer;
  int v1624 = v1620 + 1;
  v1619->timer = v1624;
  struct StateT * v1622 = slot_22(v1619);
  return v1622;
}

struct StateT * slot_33(struct StateT * v2468) {
  int * v2469 = v2468->regs;
  int v2470 = v2469[13];
  bool v2577 = !(v2470 == 0);
  struct StateT * v2573;
  if (v2577) {
    int v2471 = v2468->timer;
    int v2578 = v2471 + 15;
    v2468->timer = v2578;
    int * v2473 = v2468->reg_ready;
    int v2474 = v2468->timer;
    v2473[0] = v2474;
    int * v2476 = v2468->reg_ready;
    int v2477 = v2468->timer;
    v2476[1] = v2477;
    int * v2479 = v2468->reg_ready;
    int v2480 = v2468->timer;
    v2479[2] = v2480;
    int * v2482 = v2468->reg_ready;
    int v2483 = v2468->timer;
    v2482[3] = v2483;
    int * v2485 = v2468->reg_ready;
    int v2486 = v2468->timer;
    v2485[4] = v2486;
    int * v2488 = v2468->reg_ready;
    int v2489 = v2468->timer;
    v2488[5] = v2489;
    int * v2491 = v2468->reg_ready;
    int v2492 = v2468->timer;
    v2491[6] = v2492;
    int * v2494 = v2468->reg_ready;
    int v2495 = v2468->timer;
    v2494[7] = v2495;
    int * v2497 = v2468->reg_ready;
    int v2498 = v2468->timer;
    v2497[8] = v2498;
    int * v2500 = v2468->reg_ready;
    int v2501 = v2468->timer;
    v2500[9] = v2501;
    int * v2503 = v2468->reg_ready;
    int v2504 = v2468->timer;
    v2503[10] = v2504;
    int * v2506 = v2468->reg_ready;
    int v2507 = v2468->timer;
    v2506[11] = v2507;
    int * v2509 = v2468->reg_ready;
    int v2510 = v2468->timer;
    v2509[12] = v2510;
    int * v2512 = v2468->reg_ready;
    int v2513 = v2468->timer;
    v2512[13] = v2513;
    int * v2515 = v2468->reg_ready;
    int v2516 = v2468->timer;
    v2515[14] = v2516;
    int * v2518 = v2468->reg_ready;
    int v2519 = v2468->timer;
    v2518[15] = v2519;
    int * v2521 = v2468->reg_ready;
    int v2522 = v2468->timer;
    v2521[16] = v2522;
    int * v2524 = v2468->reg_ready;
    int v2525 = v2468->timer;
    v2524[17] = v2525;
    int * v2527 = v2468->reg_ready;
    int v2528 = v2468->timer;
    v2527[18] = v2528;
    int * v2530 = v2468->reg_ready;
    int v2531 = v2468->timer;
    v2530[19] = v2531;
    int * v2533 = v2468->reg_ready;
    int v2534 = v2468->timer;
    v2533[20] = v2534;
    int * v2536 = v2468->reg_ready;
    int v2537 = v2468->timer;
    v2536[21] = v2537;
    int * v2539 = v2468->reg_ready;
    int v2540 = v2468->timer;
    v2539[22] = v2540;
    int * v2542 = v2468->reg_ready;
    int v2543 = v2468->timer;
    v2542[23] = v2543;
    int * v2545 = v2468->reg_ready;
    int v2546 = v2468->timer;
    v2545[24] = v2546;
    int * v2548 = v2468->reg_ready;
    int v2549 = v2468->timer;
    v2548[25] = v2549;
    int * v2551 = v2468->reg_ready;
    int v2552 = v2468->timer;
    v2551[26] = v2552;
    int * v2554 = v2468->reg_ready;
    int v2555 = v2468->timer;
    v2554[27] = v2555;
    int * v2557 = v2468->reg_ready;
    int v2558 = v2468->timer;
    v2557[28] = v2558;
    int * v2560 = v2468->reg_ready;
    int v2561 = v2468->timer;
    v2560[29] = v2561;
    int * v2563 = v2468->reg_ready;
    int v2564 = v2468->timer;
    v2563[30] = v2564;
    int * v2566 = v2468->reg_ready;
    int v2567 = v2468->timer;
    v2566[31] = v2567;
    struct StateT * v2569 = slot_34(v2468);
    v2573 = v2569;
  } else {
    struct StateT * v2571 = slot_35(v2468);
    v2573 = v2571;
  }
  return v2573;
}

struct StateT * slot_37(struct StateT * v3035) {
  int v3036 = v3035->timer;
  int v3040 = v3036 + 1;
  v3035->timer = v3040;
  struct StateT * v3038 = slot_39(v3035);
  return v3038;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v3260 = v1->timer;
  int * v3261 = v1->reg_ready;
  int v3262 = v3261[0];
  int v3393 = v3262 + ((v3260 - v3262) & (~((v3260 - v3262) >> 31)));
  v1->timer = v3393;
  int v3264 = v1->timer;
  int * v3265 = v1->reg_ready;
  int v3266 = v3265[1];
  int v3396 = v3266 + ((v3264 - v3266) & (~((v3264 - v3266) >> 31)));
  v1->timer = v3396;
  int v3268 = v1->timer;
  int * v3269 = v1->reg_ready;
  int v3270 = v3269[2];
  int v3399 = v3270 + ((v3268 - v3270) & (~((v3268 - v3270) >> 31)));
  v1->timer = v3399;
  int v3272 = v1->timer;
  int * v3273 = v1->reg_ready;
  int v3274 = v3273[3];
  int v3402 = v3274 + ((v3272 - v3274) & (~((v3272 - v3274) >> 31)));
  v1->timer = v3402;
  int v3276 = v1->timer;
  int * v3277 = v1->reg_ready;
  int v3278 = v3277[4];
  int v3405 = v3278 + ((v3276 - v3278) & (~((v3276 - v3278) >> 31)));
  v1->timer = v3405;
  int v3280 = v1->timer;
  int * v3281 = v1->reg_ready;
  int v3282 = v3281[5];
  int v3408 = v3282 + ((v3280 - v3282) & (~((v3280 - v3282) >> 31)));
  v1->timer = v3408;
  int v3284 = v1->timer;
  int * v3285 = v1->reg_ready;
  int v3286 = v3285[6];
  int v3411 = v3286 + ((v3284 - v3286) & (~((v3284 - v3286) >> 31)));
  v1->timer = v3411;
  int v3288 = v1->timer;
  int * v3289 = v1->reg_ready;
  int v3290 = v3289[7];
  int v3414 = v3290 + ((v3288 - v3290) & (~((v3288 - v3290) >> 31)));
  v1->timer = v3414;
  int v3292 = v1->timer;
  int * v3293 = v1->reg_ready;
  int v3294 = v3293[8];
  int v3417 = v3294 + ((v3292 - v3294) & (~((v3292 - v3294) >> 31)));
  v1->timer = v3417;
  int v3296 = v1->timer;
  int * v3297 = v1->reg_ready;
  int v3298 = v3297[9];
  int v3420 = v3298 + ((v3296 - v3298) & (~((v3296 - v3298) >> 31)));
  v1->timer = v3420;
  int v3300 = v1->timer;
  int * v3301 = v1->reg_ready;
  int v3302 = v3301[10];
  int v3423 = v3302 + ((v3300 - v3302) & (~((v3300 - v3302) >> 31)));
  v1->timer = v3423;
  int v3304 = v1->timer;
  int * v3305 = v1->reg_ready;
  int v3306 = v3305[11];
  int v3426 = v3306 + ((v3304 - v3306) & (~((v3304 - v3306) >> 31)));
  v1->timer = v3426;
  int v3308 = v1->timer;
  int * v3309 = v1->reg_ready;
  int v3310 = v3309[12];
  int v3429 = v3310 + ((v3308 - v3310) & (~((v3308 - v3310) >> 31)));
  v1->timer = v3429;
  int v3312 = v1->timer;
  int * v3313 = v1->reg_ready;
  int v3314 = v3313[13];
  int v3432 = v3314 + ((v3312 - v3314) & (~((v3312 - v3314) >> 31)));
  v1->timer = v3432;
  int v3316 = v1->timer;
  int * v3317 = v1->reg_ready;
  int v3318 = v3317[14];
  int v3435 = v3318 + ((v3316 - v3318) & (~((v3316 - v3318) >> 31)));
  v1->timer = v3435;
  int v3320 = v1->timer;
  int * v3321 = v1->reg_ready;
  int v3322 = v3321[15];
  int v3438 = v3322 + ((v3320 - v3322) & (~((v3320 - v3322) >> 31)));
  v1->timer = v3438;
  int v3324 = v1->timer;
  int * v3325 = v1->reg_ready;
  int v3326 = v3325[16];
  int v3441 = v3326 + ((v3324 - v3326) & (~((v3324 - v3326) >> 31)));
  v1->timer = v3441;
  int v3328 = v1->timer;
  int * v3329 = v1->reg_ready;
  int v3330 = v3329[17];
  int v3444 = v3330 + ((v3328 - v3330) & (~((v3328 - v3330) >> 31)));
  v1->timer = v3444;
  int v3332 = v1->timer;
  int * v3333 = v1->reg_ready;
  int v3334 = v3333[18];
  int v3447 = v3334 + ((v3332 - v3334) & (~((v3332 - v3334) >> 31)));
  v1->timer = v3447;
  int v3336 = v1->timer;
  int * v3337 = v1->reg_ready;
  int v3338 = v3337[19];
  int v3450 = v3338 + ((v3336 - v3338) & (~((v3336 - v3338) >> 31)));
  v1->timer = v3450;
  int v3340 = v1->timer;
  int * v3341 = v1->reg_ready;
  int v3342 = v3341[20];
  int v3453 = v3342 + ((v3340 - v3342) & (~((v3340 - v3342) >> 31)));
  v1->timer = v3453;
  int v3344 = v1->timer;
  int * v3345 = v1->reg_ready;
  int v3346 = v3345[21];
  int v3456 = v3346 + ((v3344 - v3346) & (~((v3344 - v3346) >> 31)));
  v1->timer = v3456;
  int v3348 = v1->timer;
  int * v3349 = v1->reg_ready;
  int v3350 = v3349[22];
  int v3459 = v3350 + ((v3348 - v3350) & (~((v3348 - v3350) >> 31)));
  v1->timer = v3459;
  int v3352 = v1->timer;
  int * v3353 = v1->reg_ready;
  int v3354 = v3353[23];
  int v3462 = v3354 + ((v3352 - v3354) & (~((v3352 - v3354) >> 31)));
  v1->timer = v3462;
  int v3356 = v1->timer;
  int * v3357 = v1->reg_ready;
  int v3358 = v3357[24];
  int v3465 = v3358 + ((v3356 - v3358) & (~((v3356 - v3358) >> 31)));
  v1->timer = v3465;
  int v3360 = v1->timer;
  int * v3361 = v1->reg_ready;
  int v3362 = v3361[25];
  int v3468 = v3362 + ((v3360 - v3362) & (~((v3360 - v3362) >> 31)));
  v1->timer = v3468;
  int v3364 = v1->timer;
  int * v3365 = v1->reg_ready;
  int v3366 = v3365[26];
  int v3471 = v3366 + ((v3364 - v3366) & (~((v3364 - v3366) >> 31)));
  v1->timer = v3471;
  int v3368 = v1->timer;
  int * v3369 = v1->reg_ready;
  int v3370 = v3369[27];
  int v3474 = v3370 + ((v3368 - v3370) & (~((v3368 - v3370) >> 31)));
  v1->timer = v3474;
  int v3372 = v1->timer;
  int * v3373 = v1->reg_ready;
  int v3374 = v3373[28];
  int v3477 = v3374 + ((v3372 - v3374) & (~((v3372 - v3374) >> 31)));
  v1->timer = v3477;
  int v3376 = v1->timer;
  int * v3377 = v1->reg_ready;
  int v3378 = v3377[29];
  int v3480 = v3378 + ((v3376 - v3378) & (~((v3376 - v3378) >> 31)));
  v1->timer = v3480;
  int v3380 = v1->timer;
  int * v3381 = v1->reg_ready;
  int v3382 = v3381[30];
  int v3483 = v3382 + ((v3380 - v3382) & (~((v3380 - v3382) >> 31)));
  v1->timer = v3483;
  int v3384 = v1->timer;
  int * v3385 = v1->reg_ready;
  int v3386 = v3385[31];
  int v3486 = v3386 + ((v3384 - v3386) & (~((v3384 - v3386) >> 31)));
  v1->timer = v3486;
  return v1;
}

struct StateT * slot_39(struct StateT * v3048) {
  int * v3049 = v3048->regs;
  int v3050 = v3049[10];
  int v3051 = v3049[11];
  bool v3159 = (v3050 ^ -2147483648) < (v3051 ^ -2147483648);
  struct StateT * v3154;
  if (v3159) {
    struct StateT * v3052 = slot_24(v3048);
    v3154 = v3052;
  } else {
    int v3054 = v3048->timer;
    int v3162 = v3054 + 15;
    v3048->timer = v3162;
    int * v3056 = v3048->reg_ready;
    int v3057 = v3048->timer;
    v3056[0] = v3057;
    int * v3059 = v3048->reg_ready;
    int v3060 = v3048->timer;
    v3059[1] = v3060;
    int * v3062 = v3048->reg_ready;
    int v3063 = v3048->timer;
    v3062[2] = v3063;
    int * v3065 = v3048->reg_ready;
    int v3066 = v3048->timer;
    v3065[3] = v3066;
    int * v3068 = v3048->reg_ready;
    int v3069 = v3048->timer;
    v3068[4] = v3069;
    int * v3071 = v3048->reg_ready;
    int v3072 = v3048->timer;
    v3071[5] = v3072;
    int * v3074 = v3048->reg_ready;
    int v3075 = v3048->timer;
    v3074[6] = v3075;
    int * v3077 = v3048->reg_ready;
    int v3078 = v3048->timer;
    v3077[7] = v3078;
    int * v3080 = v3048->reg_ready;
    int v3081 = v3048->timer;
    v3080[8] = v3081;
    int * v3083 = v3048->reg_ready;
    int v3084 = v3048->timer;
    v3083[9] = v3084;
    int * v3086 = v3048->reg_ready;
    int v3087 = v3048->timer;
    v3086[10] = v3087;
    int * v3089 = v3048->reg_ready;
    int v3090 = v3048->timer;
    v3089[11] = v3090;
    int * v3092 = v3048->reg_ready;
    int v3093 = v3048->timer;
    v3092[12] = v3093;
    int * v3095 = v3048->reg_ready;
    int v3096 = v3048->timer;
    v3095[13] = v3096;
    int * v3098 = v3048->reg_ready;
    int v3099 = v3048->timer;
    v3098[14] = v3099;
    int * v3101 = v3048->reg_ready;
    int v3102 = v3048->timer;
    v3101[15] = v3102;
    int * v3104 = v3048->reg_ready;
    int v3105 = v3048->timer;
    v3104[16] = v3105;
    int * v3107 = v3048->reg_ready;
    int v3108 = v3048->timer;
    v3107[17] = v3108;
    int * v3110 = v3048->reg_ready;
    int v3111 = v3048->timer;
    v3110[18] = v3111;
    int * v3113 = v3048->reg_ready;
    int v3114 = v3048->timer;
    v3113[19] = v3114;
    int * v3116 = v3048->reg_ready;
    int v3117 = v3048->timer;
    v3116[20] = v3117;
    int * v3119 = v3048->reg_ready;
    int v3120 = v3048->timer;
    v3119[21] = v3120;
    int * v3122 = v3048->reg_ready;
    int v3123 = v3048->timer;
    v3122[22] = v3123;
    int * v3125 = v3048->reg_ready;
    int v3126 = v3048->timer;
    v3125[23] = v3126;
    int * v3128 = v3048->reg_ready;
    int v3129 = v3048->timer;
    v3128[24] = v3129;
    int * v3131 = v3048->reg_ready;
    int v3132 = v3048->timer;
    v3131[25] = v3132;
    int * v3134 = v3048->reg_ready;
    int v3135 = v3048->timer;
    v3134[26] = v3135;
    int * v3137 = v3048->reg_ready;
    int v3138 = v3048->timer;
    v3137[27] = v3138;
    int * v3140 = v3048->reg_ready;
    int v3141 = v3048->timer;
    v3140[28] = v3141;
    int * v3143 = v3048->reg_ready;
    int v3144 = v3048->timer;
    v3143[29] = v3144;
    int * v3146 = v3048->reg_ready;
    int v3147 = v3048->timer;
    v3146[30] = v3147;
    int * v3149 = v3048->reg_ready;
    int v3150 = v3048->timer;
    v3149[31] = v3150;
    struct StateT * v3152 = slot_34(v3048);
    v3154 = v3152;
  }
  return v3154;
}

struct StateT * slot_8(struct StateT * v530) {
  int * v531 = v530->regs;
  int v532 = v531[10];
  int v533 = v531[11];
  bool v653 = (v532 ^ -2147483648) >= (v533 ^ -2147483648);
  struct StateT * v648;
  if (v653) {
    int v534 = v530->timer;
    int v654 = v534 + 15;
    v530->timer = v654;
    int * v536 = v530->saved_regs;
    int v537 = v536[13];
    int * v538 = v530->regs;
    v538[13] = v537;
    int * v540 = v530->saved_regs;
    int v541 = v540[12];
    int * v542 = v530->regs;
    v542[12] = v541;
    int * v544 = v530->saved_regs;
    int v545 = v544[14];
    int * v546 = v530->regs;
    v546[14] = v545;
    int * v548 = v530->reg_ready;
    int v549 = v530->timer;
    v548[0] = v549;
    int * v551 = v530->reg_ready;
    int v552 = v530->timer;
    v551[1] = v552;
    int * v554 = v530->reg_ready;
    int v555 = v530->timer;
    v554[2] = v555;
    int * v557 = v530->reg_ready;
    int v558 = v530->timer;
    v557[3] = v558;
    int * v560 = v530->reg_ready;
    int v561 = v530->timer;
    v560[4] = v561;
    int * v563 = v530->reg_ready;
    int v564 = v530->timer;
    v563[5] = v564;
    int * v566 = v530->reg_ready;
    int v567 = v530->timer;
    v566[6] = v567;
    int * v569 = v530->reg_ready;
    int v570 = v530->timer;
    v569[7] = v570;
    int * v572 = v530->reg_ready;
    int v573 = v530->timer;
    v572[8] = v573;
    int * v575 = v530->reg_ready;
    int v576 = v530->timer;
    v575[9] = v576;
    int * v578 = v530->reg_ready;
    int v579 = v530->timer;
    v578[10] = v579;
    int * v581 = v530->reg_ready;
    int v582 = v530->timer;
    v581[11] = v582;
    int * v584 = v530->reg_ready;
    int v585 = v530->timer;
    v584[12] = v585;
    int * v587 = v530->reg_ready;
    int v588 = v530->timer;
    v587[13] = v588;
    int * v590 = v530->reg_ready;
    int v591 = v530->timer;
    v590[14] = v591;
    int * v593 = v530->reg_ready;
    int v594 = v530->timer;
    v593[15] = v594;
    int * v596 = v530->reg_ready;
    int v597 = v530->timer;
    v596[16] = v597;
    int * v599 = v530->reg_ready;
    int v600 = v530->timer;
    v599[17] = v600;
    int * v602 = v530->reg_ready;
    int v603 = v530->timer;
    v602[18] = v603;
    int * v605 = v530->reg_ready;
    int v606 = v530->timer;
    v605[19] = v606;
    int * v608 = v530->reg_ready;
    int v609 = v530->timer;
    v608[20] = v609;
    int * v611 = v530->reg_ready;
    int v612 = v530->timer;
    v611[21] = v612;
    int * v614 = v530->reg_ready;
    int v615 = v530->timer;
    v614[22] = v615;
    int * v617 = v530->reg_ready;
    int v618 = v530->timer;
    v617[23] = v618;
    int * v620 = v530->reg_ready;
    int v621 = v530->timer;
    v620[24] = v621;
    int * v623 = v530->reg_ready;
    int v624 = v530->timer;
    v623[25] = v624;
    int * v626 = v530->reg_ready;
    int v627 = v530->timer;
    v626[26] = v627;
    int * v629 = v530->reg_ready;
    int v630 = v530->timer;
    v629[27] = v630;
    int * v632 = v530->reg_ready;
    int v633 = v530->timer;
    v632[28] = v633;
    int * v635 = v530->reg_ready;
    int v636 = v530->timer;
    v635[29] = v636;
    int * v638 = v530->reg_ready;
    int v639 = v530->timer;
    v638[30] = v639;
    int * v641 = v530->reg_ready;
    int v642 = v530->timer;
    v641[31] = v642;
    struct StateT * v644 = slot_29(v530);
    v648 = v644;
  } else {
    struct StateT * v646 = slot_10(v530);
    v648 = v646;
  }
  return v648;
}

struct StateT * slot_30(struct StateT * v2436) {
  int v2437 = v2436->timer;
  int v2450 = v2437 + 1;
  v2436->timer = v2450;
  int * v2439 = v2436->reg_ready;
  int v2440 = v2439[12];
  int * v2441 = v2436->regs;
  int v2442 = v2441[12];
  int v2443 = v2439[10];
  int v2444 = v2441[10];
  int v2455 = (v2443 + (((v2440 + ((v2437 - v2440) & (~((v2437 - v2440) >> 31)))) - v2443) & (~(((v2440 + ((v2437 - v2440) & (~((v2437 - v2440) >> 31)))) - v2443) >> 31)))) + 1;
  v2439[12] = v2455;
  int * v2446 = v2436->regs;
  int v2457 = v2442 & v2444;
  v2446[12] = v2457;
  struct StateT * v2448 = slot_32(v2436);
  return v2448;
}

struct StateT * slot_4(struct StateT * v256) {
  int * v257 = v256->saved_regs;
  int * v258 = v256->regs;
  int v259 = v258[12];
  v257[12] = v259;
  int v261 = v256->timer;
  int v273 = v261 + 1;
  v256->timer = v273;
  int * v263 = v256->reg_ready;
  v263[12] = v273;
  int * v265 = v256->regs;
  v265[12] = 0;
  struct StateT * v267 = slot_5(v256);
  return v267;
}

struct StateT * slot_15(struct StateT * v1044) {
  int v1045 = v1044->timer;
  int v1049 = v1045 + 1;
  v1044->timer = v1049;
  struct StateT * v1047 = slot_16(v1044);
  return v1047;
}

struct StateT * slot_18(struct StateT * v1279) {
  int v1280 = v1279->timer;
  int v1291 = v1280 + 1;
  v1279->timer = v1291;
  int * v1282 = v1279->reg_ready;
  int v1283 = v1282[13];
  int * v1284 = v1279->regs;
  int v1285 = v1284[13];
  int v1295 = (v1283 + ((v1280 - v1283) & (~((v1280 - v1283) >> 31)))) + 1;
  v1282[13] = v1295;
  int * v1287 = v1279->regs;
  int v1297 = v1285 + -1;
  v1287[13] = v1297;
  struct StateT * v1289 = slot_20(v1279);
  return v1289;
}

struct StateT * slot_22(struct StateT * v1632) {
  int * v1633 = v1632->regs;
  int v1634 = v1633[10];
  int v1635 = v1633[11];
  bool v1743 = (v1634 ^ -2147483648) < (v1635 ^ -2147483648);
  struct StateT * v1738;
  if (v1743) {
    int v1636 = v1632->timer;
    int v1744 = v1636 + 15;
    v1632->timer = v1744;
    int * v1638 = v1632->reg_ready;
    int v1639 = v1632->timer;
    v1638[0] = v1639;
    int * v1641 = v1632->reg_ready;
    int v1642 = v1632->timer;
    v1641[1] = v1642;
    int * v1644 = v1632->reg_ready;
    int v1645 = v1632->timer;
    v1644[2] = v1645;
    int * v1647 = v1632->reg_ready;
    int v1648 = v1632->timer;
    v1647[3] = v1648;
    int * v1650 = v1632->reg_ready;
    int v1651 = v1632->timer;
    v1650[4] = v1651;
    int * v1653 = v1632->reg_ready;
    int v1654 = v1632->timer;
    v1653[5] = v1654;
    int * v1656 = v1632->reg_ready;
    int v1657 = v1632->timer;
    v1656[6] = v1657;
    int * v1659 = v1632->reg_ready;
    int v1660 = v1632->timer;
    v1659[7] = v1660;
    int * v1662 = v1632->reg_ready;
    int v1663 = v1632->timer;
    v1662[8] = v1663;
    int * v1665 = v1632->reg_ready;
    int v1666 = v1632->timer;
    v1665[9] = v1666;
    int * v1668 = v1632->reg_ready;
    int v1669 = v1632->timer;
    v1668[10] = v1669;
    int * v1671 = v1632->reg_ready;
    int v1672 = v1632->timer;
    v1671[11] = v1672;
    int * v1674 = v1632->reg_ready;
    int v1675 = v1632->timer;
    v1674[12] = v1675;
    int * v1677 = v1632->reg_ready;
    int v1678 = v1632->timer;
    v1677[13] = v1678;
    int * v1680 = v1632->reg_ready;
    int v1681 = v1632->timer;
    v1680[14] = v1681;
    int * v1683 = v1632->reg_ready;
    int v1684 = v1632->timer;
    v1683[15] = v1684;
    int * v1686 = v1632->reg_ready;
    int v1687 = v1632->timer;
    v1686[16] = v1687;
    int * v1689 = v1632->reg_ready;
    int v1690 = v1632->timer;
    v1689[17] = v1690;
    int * v1692 = v1632->reg_ready;
    int v1693 = v1632->timer;
    v1692[18] = v1693;
    int * v1695 = v1632->reg_ready;
    int v1696 = v1632->timer;
    v1695[19] = v1696;
    int * v1698 = v1632->reg_ready;
    int v1699 = v1632->timer;
    v1698[20] = v1699;
    int * v1701 = v1632->reg_ready;
    int v1702 = v1632->timer;
    v1701[21] = v1702;
    int * v1704 = v1632->reg_ready;
    int v1705 = v1632->timer;
    v1704[22] = v1705;
    int * v1707 = v1632->reg_ready;
    int v1708 = v1632->timer;
    v1707[23] = v1708;
    int * v1710 = v1632->reg_ready;
    int v1711 = v1632->timer;
    v1710[24] = v1711;
    int * v1713 = v1632->reg_ready;
    int v1714 = v1632->timer;
    v1713[25] = v1714;
    int * v1716 = v1632->reg_ready;
    int v1717 = v1632->timer;
    v1716[26] = v1717;
    int * v1719 = v1632->reg_ready;
    int v1720 = v1632->timer;
    v1719[27] = v1720;
    int * v1722 = v1632->reg_ready;
    int v1723 = v1632->timer;
    v1722[28] = v1723;
    int * v1725 = v1632->reg_ready;
    int v1726 = v1632->timer;
    v1725[29] = v1726;
    int * v1728 = v1632->reg_ready;
    int v1729 = v1632->timer;
    v1728[30] = v1729;
    int * v1731 = v1632->reg_ready;
    int v1732 = v1632->timer;
    v1731[31] = v1732;
    struct StateT * v1734 = slot_24(v1632);
    v1738 = v1734;
  } else {
    struct StateT * v1736 = slot_34(v1632);
    v1738 = v1736;
  }
  return v1738;
}

struct StateT * slot_35(struct StateT * v2695) {
  int v2696 = v2695->timer;
  int v2707 = v2696 + 1;
  v2695->timer = v2707;
  int * v2698 = v2695->reg_ready;
  int v2699 = v2698[13];
  int * v2700 = v2695->regs;
  int v2701 = v2700[13];
  int v2711 = (v2699 + ((v2696 - v2699) & (~((v2696 - v2699) >> 31)))) + 1;
  v2698[13] = v2711;
  int * v2703 = v2695->regs;
  int v2713 = v2701 + -1;
  v2703[13] = v2713;
  struct StateT * v2705 = slot_37(v2695);
  return v2705;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}