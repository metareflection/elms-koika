// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 129]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 128
#define HISTORY_BITS 4

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[128];
  int timer;
};

struct StateG * slot_12(struct StateG * v406);
struct StateG * slot_6(struct StateG * v94);
struct StateG * slot_25(struct StateG * v1276);
struct StateG * slot_16(struct StateG * v901);
struct StateG * slot_23(struct StateG * v1257);
struct StateG * slot_5(struct StateG * v74);
struct StateG * slot_2(struct StateG * v28);
struct StateG * slot_7(struct StateG * v118);
struct StateG * slot_21(struct StateG * v1176);
struct StateG * slot_3(struct StateG * v41);
struct StateG * slot_26(struct StateG * v1289);
struct StateG * slot_10(struct StateG * v365);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_19(struct StateG * v1135);
struct StateG * slot_13(struct StateG * v610);
struct StateG * slot_24(struct StateG * v1262);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_14(struct StateG * v821);
struct StateG * slot_17(struct StateG * v1105);
struct StateG * slot_20(struct StateG * v1155);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_8(struct StateG * v154);
struct StateG * slot_4(struct StateG * v54);
struct StateG * slot_15(struct StateG * v838);
struct StateG * slot_18(struct StateG * v1115);
struct StateG * slot_22(struct StateG * v1217);
struct StateG * slot_11(struct StateG * v382);
struct StateG * slot_12(struct StateG * v406) {
  int v407 = v406->timer;
  int v517 = v407 + 1;
  v406->timer = v517;
  int * v409 = v406->regs;
  int v410 = v409[5];
  int * v411 = v406->cache_tags;
  int v521 = (((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2;
  int v412 = v411[v521];
  int v522 = ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2) + 1;
  int v413 = v411[v522];
  int v523 = 4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2);
  int v414 = v411[v523];
  int v524 = (4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v415 = v411[v524];
  int v416 = v406->timer;
  int v525 = v416 + ((100 ^ (((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v412 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v412 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) | (~(((v413 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v413 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31))) & 104)))));
  v406->timer = v525;
  int * v418 = v406->cache_vals;
  bool v526 = !(((~(((v412 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v412 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) | (~(((v413 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v413 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31))) == 0);
  int v511;
  if (v526) {
    int * v419 = v406->cache_age;
    int v528 = ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2) + ((~(((v413 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v413 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) & 1);
    int v420 = v419[v528];
    int v421 = v419[v521];
    int v529 = v421 + ((int)((unsigned int)(v421 - v420) >> 31));
    v419[v521] = v529;
    int * v423 = v406->cache_age;
    int v424 = v423[v522];
    int v531 = v424 + ((int)((unsigned int)(v424 - v420) >> 31));
    v423[v522] = v531;
    int * v426 = v406->cache_age;
    v426[v528] = 0;
    v511 = v528;
  } else {
    int * v429 = v406->cache_age;
    int v535 = (((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2;
    int v430 = v429[v535];
    int * v431 = v406->cache_tags;
    int v432 = v431[v535];
    int v433 = v429[v522];
    int v434 = v431[v522];
    bool v537 = !(((~(((v414 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v414 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) | (~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31))) == 0);
    int v488;
    if (v537) {
      int * v435 = v406->cache_age;
      int v539 = (4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + ((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1))))) >> 31)) & 1);
      int v436 = v435[v539];
      int v437 = v435[v523];
      int v540 = v437 + ((int)((unsigned int)(v437 - v436) >> 31));
      v435[v523] = v540;
      int * v439 = v406->cache_age;
      int v440 = v439[v524];
      int v542 = v440 + ((int)((unsigned int)(v440 - v436) >> 31));
      v439[v524] = v542;
      int * v442 = v406->cache_age;
      v442[v539] = 0;
      v488 = v539;
    } else {
      int * v445 = v406->cache_age;
      int v546 = 4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2);
      int v446 = v445[v546];
      int * v447 = v406->cache_tags;
      int v448 = v447[v546];
      int v449 = v445[v524];
      int v450 = v447[v524];
      int * v451 = v406->cache_dirty;
      int v549 = (4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v452 = v451[v549];
      bool v550 = !(v452 == 0);
      if (v550) {
        int * v453 = v406->cache_tags;
        int v454 = v453[v549];
        int * v455 = v406->cache_vals;
        int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v456 = v455[v553];
        int v554 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v457 = v455[v554];
        int * v458 = v406->mem;
        int v556 = v454 * 2;
        v458[v556] = v456;
        int * v460 = v406->mem;
        int v559 = (v454 * 2) + 1;
        v460[v559] = v457;
        ;
      } else {
        ;
      }
      int * v465 = v406->mem;
      int v564 = ((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) * 2;
      int v466 = v465[v564];
      int v565 = (((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) * 2) + 1;
      int v467 = v465[v565];
      int * v468 = v406->cache_vals;
      int v567 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v468[v567] = v466;
      int * v470 = v406->cache_vals;
      int v570 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v449 + ((~(((v450 ^ -1) | (-(v450 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v470[v570] = v467;
      int * v472 = v406->cache_tags;
      int v573 = (int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1);
      v472[v549] = v573;
      int * v474 = v406->cache_dirty;
      v474[v549] = 0;
      int * v476 = v406->cache_age;
      v476[v549] = 1;
      int * v478 = v406->cache_age;
      int v479 = v478[v549];
      int v480 = v478[v523];
      int v579 = v480 + ((int)((unsigned int)(v480 - v479) >> 31));
      v478[v523] = v579;
      int * v482 = v406->cache_age;
      int v483 = v482[v524];
      int v581 = v483 + ((int)((unsigned int)(v483 - v479) >> 31));
      v482[v524] = v581;
      int * v485 = v406->cache_age;
      v485[v549] = 0;
      v488 = v549;
    }
    int * v489 = v406->cache_vals;
    int v584 = v488 * 2;
    int v490 = v489[v584];
    int v585 = (v488 * 2) + 1;
    int v491 = v489[v585];
    int v586 = (((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v489[v586] = v490;
    int * v493 = v406->cache_vals;
    int v589 = ((((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v493[v589] = v491;
    int * v495 = v406->cache_tags;
    int v592 = ((((int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1)) & 1) * 2) + ((((v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2)) - (v433 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v593 = (int)((unsigned int)((int)((unsigned int)v410 >> 2)) >> 1);
    v495[v592] = v593;
    int * v497 = v406->cache_dirty;
    v497[v592] = 0;
    int * v499 = v406->cache_age;
    v499[v592] = 1;
    int * v501 = v406->cache_age;
    int v502 = v501[v592];
    int v503 = v501[v521];
    int v599 = v503 + ((int)((unsigned int)(v503 - v502) >> 31));
    v501[v521] = v599;
    int * v505 = v406->cache_age;
    int v506 = v505[v522];
    int v601 = v506 + ((int)((unsigned int)(v506 - v502) >> 31));
    v505[v522] = v601;
    int * v508 = v406->cache_age;
    v508[v592] = 0;
    v511 = v592;
  }
  int v604 = (v511 * 2) + (((int)((unsigned int)v410 >> 2)) & 1);
  int v512 = v418[v604];
  int * v513 = v406->regs;
  v513[10] = v512;
  struct StateG * v515 = slot_14(v406);
  return v515;
}

struct StateG * slot_6(struct StateG * v94) {
  int * v95 = v94->saved_regs;
  int * v96 = v94->regs;
  int v97 = v96[5];
  v95[5] = v97;
  int v99 = v94->timer;
  int v111 = v99 + 1;
  v94->timer = v111;
  int * v101 = v94->regs;
  int v102 = v101[12];
  int v103 = v101[14];
  int v115 = v102 + v103;
  v101[5] = v115;
  struct StateG * v105 = slot_8(v94);
  return v105;
}

struct StateG * slot_25(struct StateG * v1276) {
  int v1277 = v1276->timer;
  int v1283 = v1277 + 1;
  v1276->timer = v1283;
  int * v1279 = v1276->regs;
  v1279[10] = 0;
  struct StateG * v1281 = slot_23(v1276);
  return v1281;
}

struct StateG * slot_16(struct StateG * v901) {
  int v902 = v901->timer;
  int v1012 = v902 + 1;
  v901->timer = v1012;
  int * v904 = v901->regs;
  int v905 = v904[6];
  int * v906 = v901->cache_tags;
  int v1016 = (((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2;
  int v907 = v906[v1016];
  int v1017 = ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2) + 1;
  int v908 = v906[v1017];
  int v1018 = 4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2);
  int v909 = v906[v1018];
  int v1019 = (4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v910 = v906[v1019];
  int v911 = v901->timer;
  int v1020 = v911 + ((100 ^ (((~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) | (~(((v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) | (~(((v908 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v908 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) | (~(((v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31))) & 104)))));
  v901->timer = v1020;
  int * v913 = v901->cache_vals;
  bool v1021 = !(((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) | (~(((v908 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v908 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31))) == 0);
  int v1006;
  if (v1021) {
    int * v914 = v901->cache_age;
    int v1023 = ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2) + ((~(((v908 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v908 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) & 1);
    int v915 = v914[v1023];
    int v916 = v914[v1016];
    int v1024 = v916 + ((int)((unsigned int)(v916 - v915) >> 31));
    v914[v1016] = v1024;
    int * v918 = v901->cache_age;
    int v919 = v918[v1017];
    int v1026 = v919 + ((int)((unsigned int)(v919 - v915) >> 31));
    v918[v1017] = v1026;
    int * v921 = v901->cache_age;
    v921[v1023] = 0;
    v1006 = v1023;
  } else {
    int * v924 = v901->cache_age;
    int v1030 = (((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2;
    int v925 = v924[v1030];
    int * v926 = v901->cache_tags;
    int v927 = v926[v1030];
    int v928 = v924[v1017];
    int v929 = v926[v1017];
    bool v1032 = !(((~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) | (~(((v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31))) == 0);
    int v983;
    if (v1032) {
      int * v930 = v901->cache_age;
      int v1034 = (4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + ((~(((v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))) | (-(v910 ^ ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1))))) >> 31)) & 1);
      int v931 = v930[v1034];
      int v932 = v930[v1018];
      int v1035 = v932 + ((int)((unsigned int)(v932 - v931) >> 31));
      v930[v1018] = v1035;
      int * v934 = v901->cache_age;
      int v935 = v934[v1019];
      int v1037 = v935 + ((int)((unsigned int)(v935 - v931) >> 31));
      v934[v1019] = v1037;
      int * v937 = v901->cache_age;
      v937[v1034] = 0;
      v983 = v1034;
    } else {
      int * v940 = v901->cache_age;
      int v1041 = 4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2);
      int v941 = v940[v1041];
      int * v942 = v901->cache_tags;
      int v943 = v942[v1041];
      int v944 = v940[v1019];
      int v945 = v942[v1019];
      int * v946 = v901->cache_dirty;
      int v1044 = (4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v944 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v947 = v946[v1044];
      bool v1045 = !(v947 == 0);
      if (v1045) {
        int * v948 = v901->cache_tags;
        int v949 = v948[v1044];
        int * v950 = v901->cache_vals;
        int v1048 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v944 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v951 = v950[v1048];
        int v1049 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v944 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v952 = v950[v1049];
        int * v953 = v901->mem;
        int v1051 = v949 * 2;
        v953[v1051] = v951;
        int * v955 = v901->mem;
        int v1054 = (v949 * 2) + 1;
        v955[v1054] = v952;
        ;
      } else {
        ;
      }
      int * v960 = v901->mem;
      int v1059 = ((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) * 2;
      int v961 = v960[v1059];
      int v1060 = (((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) * 2) + 1;
      int v962 = v960[v1060];
      int * v963 = v901->cache_vals;
      int v1062 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v944 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v963[v1062] = v961;
      int * v965 = v901->cache_vals;
      int v1065 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 3) * 2)) + ((((v941 + ((~(((v943 ^ -1) | (-(v943 ^ -1))) >> 31)) & 2)) - (v944 + ((~(((v945 ^ -1) | (-(v945 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v965[v1065] = v962;
      int * v967 = v901->cache_tags;
      int v1068 = (int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1);
      v967[v1044] = v1068;
      int * v969 = v901->cache_dirty;
      v969[v1044] = 0;
      int * v971 = v901->cache_age;
      v971[v1044] = 1;
      int * v973 = v901->cache_age;
      int v974 = v973[v1044];
      int v975 = v973[v1018];
      int v1074 = v975 + ((int)((unsigned int)(v975 - v974) >> 31));
      v973[v1018] = v1074;
      int * v977 = v901->cache_age;
      int v978 = v977[v1019];
      int v1076 = v978 + ((int)((unsigned int)(v978 - v974) >> 31));
      v977[v1019] = v1076;
      int * v980 = v901->cache_age;
      v980[v1044] = 0;
      v983 = v1044;
    }
    int * v984 = v901->cache_vals;
    int v1079 = v983 * 2;
    int v985 = v984[v1079];
    int v1080 = (v983 * 2) + 1;
    int v986 = v984[v1080];
    int v1081 = (((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v984[v1081] = v985;
    int * v988 = v901->cache_vals;
    int v1084 = ((((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v988[v1084] = v986;
    int * v990 = v901->cache_tags;
    int v1087 = ((((int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1)) & 1) * 2) + ((((v925 + ((~(((v927 ^ -1) | (-(v927 ^ -1))) >> 31)) & 2)) - (v928 + ((~(((v929 ^ -1) | (-(v929 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1088 = (int)((unsigned int)((int)((unsigned int)v905 >> 2)) >> 1);
    v990[v1087] = v1088;
    int * v992 = v901->cache_dirty;
    v992[v1087] = 0;
    int * v994 = v901->cache_age;
    v994[v1087] = 1;
    int * v996 = v901->cache_age;
    int v997 = v996[v1087];
    int v998 = v996[v1016];
    int v1094 = v998 + ((int)((unsigned int)(v998 - v997) >> 31));
    v996[v1016] = v1094;
    int * v1000 = v901->cache_age;
    int v1001 = v1000[v1017];
    int v1096 = v1001 + ((int)((unsigned int)(v1001 - v997) >> 31));
    v1000[v1017] = v1096;
    int * v1003 = v901->cache_age;
    v1003[v1087] = 0;
    v1006 = v1087;
  }
  int v1099 = (v1006 * 2) + (((int)((unsigned int)v905 >> 2)) & 1);
  int v1007 = v913[v1099];
  int * v1008 = v901->regs;
  v1008[11] = v1007;
  struct StateG * v1010 = slot_18(v901);
  return v1010;
}

struct StateG * slot_23(struct StateG * v1257) {
  int v1258 = v1257->timer;
  int v1261 = v1258 + 1;
  v1257->timer = v1261;
  return v1257;
}

struct StateG * slot_5(struct StateG * v74) {
  int * v75 = v74->saved_regs;
  int * v76 = v74->regs;
  int v77 = v76[10];
  v75[10] = v77;
  int v79 = v74->timer;
  int v89 = v79 + 1;
  v74->timer = v89;
  int * v81 = v74->regs;
  v81[10] = 1;
  struct StateG * v83 = slot_7(v74);
  return v83;
}

struct StateG * slot_2(struct StateG * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateG * v33 = slot_3(v28);
  return v33;
}

struct StateG * slot_7(struct StateG * v118) {
  int * v119 = v118->regs;
  int v120 = v119[14];
  int v121 = v119[15];
  bool v140 = v120 >= v121;
  struct StateG * v135;
  if (v140) {
    int * v122 = v118->pht;
    v122[0] = 1;
    v135 = v118;
  } else {
    int * v125 = v118->pht;
    v125[0] = 0;
    int v127 = v118->timer;
    int v146 = v127 + 15;
    v118->timer = v146;
    int * v129 = v118->saved_regs;
    int v130 = v129[10];
    int * v131 = v118->regs;
    v131[10] = v130;
    struct StateG * v133 = slot_10(v118);
    v135 = v133;
  }
  return v135;
}

struct StateG * slot_21(struct StateG * v1176) {
  int * v1177 = v1176->saved_regs;
  int v1178 = v1177[10];
  int * v1179 = v1176->regs;
  int v1180 = v1179[11];
  bool v1201 = !(v1178 == v1180);
  struct StateG * v1195;
  if (v1201) {
    int * v1181 = v1176->pht;
    v1181[16] = 1;
    struct StateG * v1183 = slot_23(v1176);
    v1195 = v1183;
  } else {
    int * v1185 = v1176->pht;
    v1185[16] = 0;
    int v1187 = v1176->timer;
    int v1210 = v1187 + 15;
    v1176->timer = v1210;
    int * v1189 = v1176->saved_regs;
    int v1190 = v1189[10];
    int * v1191 = v1176->regs;
    v1191[10] = v1190;
    struct StateG * v1193 = slot_24(v1176);
    v1195 = v1193;
  }
  return v1195;
}

struct StateG * slot_3(struct StateG * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateG * v46 = slot_4(v41);
  return v46;
}

struct StateG * slot_26(struct StateG * v1289) {
  int v1290 = v1289->timer;
  int v1294 = v1290 + 1;
  v1289->timer = v1294;
  struct StateG * v1292 = slot_4(v1289);
  return v1292;
}

struct StateG * slot_10(struct StateG * v365) {
  int v366 = v365->timer;
  int v374 = v366 + 1;
  v365->timer = v374;
  int * v368 = v365->regs;
  int v369 = v368[12];
  int v370 = v368[14];
  int v379 = v369 + v370;
  v368[5] = v379;
  struct StateG * v372 = slot_12(v365);
  return v372;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateG * v20 = slot_2(v15);
  return v20;
}

struct StateG * slot_19(struct StateG * v1135) {
  int * v1136 = v1135->saved_regs;
  int * v1137 = v1135->regs;
  int v1138 = v1137[10];
  v1136[10] = v1138;
  int v1140 = v1135->timer;
  int v1150 = v1140 + 1;
  v1135->timer = v1150;
  int * v1142 = v1135->regs;
  v1142[10] = 0;
  struct StateG * v1144 = slot_21(v1135);
  return v1144;
}

struct StateG * slot_13(struct StateG * v610) {
  int * v611 = v610->saved_regs;
  int * v612 = v610->regs;
  int v613 = v612[11];
  v611[11] = v613;
  int v615 = v610->timer;
  int v729 = v615 + 1;
  v610->timer = v729;
  int * v617 = v610->regs;
  int v618 = v617[6];
  int * v619 = v610->cache_tags;
  int v733 = (((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2;
  int v620 = v619[v733];
  int v734 = ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2) + 1;
  int v621 = v619[v734];
  int v735 = 4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2);
  int v622 = v619[v735];
  int v736 = (4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v623 = v619[v736];
  int v624 = v610->timer;
  int v737 = v624 + ((100 ^ (((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31))) & 104)))));
  v610->timer = v737;
  int * v626 = v610->cache_vals;
  bool v738 = !(((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31))) == 0);
  int v719;
  if (v738) {
    int * v627 = v610->cache_age;
    int v740 = ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2) + ((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) & 1);
    int v628 = v627[v740];
    int v629 = v627[v733];
    int v741 = v629 + ((int)((unsigned int)(v629 - v628) >> 31));
    v627[v733] = v741;
    int * v631 = v610->cache_age;
    int v632 = v631[v734];
    int v743 = v632 + ((int)((unsigned int)(v632 - v628) >> 31));
    v631[v734] = v743;
    int * v634 = v610->cache_age;
    v634[v740] = 0;
    v719 = v740;
  } else {
    int * v637 = v610->cache_age;
    int v747 = (((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2;
    int v638 = v637[v747];
    int * v639 = v610->cache_tags;
    int v640 = v639[v747];
    int v641 = v637[v734];
    int v642 = v639[v734];
    bool v749 = !(((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31))) == 0);
    int v696;
    if (v749) {
      int * v643 = v610->cache_age;
      int v751 = (4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + ((~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1))))) >> 31)) & 1);
      int v644 = v643[v751];
      int v645 = v643[v735];
      int v752 = v645 + ((int)((unsigned int)(v645 - v644) >> 31));
      v643[v735] = v752;
      int * v647 = v610->cache_age;
      int v648 = v647[v736];
      int v754 = v648 + ((int)((unsigned int)(v648 - v644) >> 31));
      v647[v736] = v754;
      int * v650 = v610->cache_age;
      v650[v751] = 0;
      v696 = v751;
    } else {
      int * v653 = v610->cache_age;
      int v758 = 4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2);
      int v654 = v653[v758];
      int * v655 = v610->cache_tags;
      int v656 = v655[v758];
      int v657 = v653[v736];
      int v658 = v655[v736];
      int * v659 = v610->cache_dirty;
      int v761 = (4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v660 = v659[v761];
      bool v762 = !(v660 == 0);
      if (v762) {
        int * v661 = v610->cache_tags;
        int v662 = v661[v761];
        int * v663 = v610->cache_vals;
        int v765 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v664 = v663[v765];
        int v766 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v665 = v663[v766];
        int * v666 = v610->mem;
        int v768 = v662 * 2;
        v666[v768] = v664;
        int * v668 = v610->mem;
        int v771 = (v662 * 2) + 1;
        v668[v771] = v665;
        ;
      } else {
        ;
      }
      int * v673 = v610->mem;
      int v776 = ((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) * 2;
      int v674 = v673[v776];
      int v777 = (((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) * 2) + 1;
      int v675 = v673[v777];
      int * v676 = v610->cache_vals;
      int v779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v676[v779] = v674;
      int * v678 = v610->cache_vals;
      int v782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v678[v782] = v675;
      int * v680 = v610->cache_tags;
      int v785 = (int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1);
      v680[v761] = v785;
      int * v682 = v610->cache_dirty;
      v682[v761] = 0;
      int * v684 = v610->cache_age;
      v684[v761] = 1;
      int * v686 = v610->cache_age;
      int v687 = v686[v761];
      int v688 = v686[v735];
      int v791 = v688 + ((int)((unsigned int)(v688 - v687) >> 31));
      v686[v735] = v791;
      int * v690 = v610->cache_age;
      int v691 = v690[v736];
      int v793 = v691 + ((int)((unsigned int)(v691 - v687) >> 31));
      v690[v736] = v793;
      int * v693 = v610->cache_age;
      v693[v761] = 0;
      v696 = v761;
    }
    int * v697 = v610->cache_vals;
    int v796 = v696 * 2;
    int v698 = v697[v796];
    int v797 = (v696 * 2) + 1;
    int v699 = v697[v797];
    int v798 = (((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v697[v798] = v698;
    int * v701 = v610->cache_vals;
    int v801 = ((((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v701[v801] = v699;
    int * v703 = v610->cache_tags;
    int v804 = ((((int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v805 = (int)((unsigned int)((int)((unsigned int)v618 >> 2)) >> 1);
    v703[v804] = v805;
    int * v705 = v610->cache_dirty;
    v705[v804] = 0;
    int * v707 = v610->cache_age;
    v707[v804] = 1;
    int * v709 = v610->cache_age;
    int v710 = v709[v804];
    int v711 = v709[v733];
    int v811 = v711 + ((int)((unsigned int)(v711 - v710) >> 31));
    v709[v733] = v811;
    int * v713 = v610->cache_age;
    int v714 = v713[v734];
    int v813 = v714 + ((int)((unsigned int)(v714 - v710) >> 31));
    v713[v734] = v813;
    int * v716 = v610->cache_age;
    v716[v804] = 0;
    v719 = v804;
  }
  int v816 = (v719 * 2) + (((int)((unsigned int)v618 >> 2)) & 1);
  int v720 = v626[v816];
  int * v721 = v610->regs;
  v721[11] = v720;
  struct StateG * v723 = slot_15(v610);
  return v723;
}

struct StateG * slot_24(struct StateG * v1262) {
  int v1263 = v1262->timer;
  int v1270 = v1263 + 1;
  v1262->timer = v1270;
  int * v1265 = v1262->regs;
  int v1266 = v1265[14];
  int v1273 = v1266 + 4;
  v1265[14] = v1273;
  struct StateG * v1268 = slot_26(v1262);
  return v1268;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateG * v7 = slot_1(v2);
  return v7;
}

struct StateG * slot_14(struct StateG * v821) {
  int v822 = v821->timer;
  int v830 = v822 + 1;
  v821->timer = v830;
  int * v824 = v821->regs;
  int v825 = v824[13];
  int v826 = v824[14];
  int v835 = v825 + v826;
  v824[6] = v835;
  struct StateG * v828 = slot_16(v821);
  return v828;
}

struct StateG * slot_17(struct StateG * v1105) {
  int v1106 = v1105->timer;
  int v1111 = v1106 + 1;
  v1105->timer = v1111;
  int * v1108 = v1105->regs;
  v1108[10] = 1;
  return v1105;
}

struct StateG * slot_20(struct StateG * v1155) {
  int * v1156 = v1155->saved_regs;
  int * v1157 = v1155->regs;
  int v1158 = v1157[14];
  v1156[14] = v1158;
  int v1160 = v1155->timer;
  int v1171 = v1160 + 1;
  v1155->timer = v1171;
  int * v1162 = v1155->regs;
  int v1163 = v1162[14];
  int v1173 = v1163 + 4;
  v1162[14] = v1173;
  struct StateG * v1165 = slot_22(v1155);
  return v1165;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_8(struct StateG * v154) {
  int * v155 = v154->saved_regs;
  int * v156 = v154->regs;
  int v157 = v156[10];
  v155[10] = v157;
  int v159 = v154->timer;
  int v273 = v159 + 1;
  v154->timer = v273;
  int * v161 = v154->regs;
  int v162 = v161[5];
  int * v163 = v154->cache_tags;
  int v277 = (((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2;
  int v164 = v163[v277];
  int v278 = ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + 1;
  int v165 = v163[v278];
  int v279 = 4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2);
  int v166 = v163[v279];
  int v280 = (4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v167 = v163[v280];
  int v168 = v154->timer;
  int v281 = v168 + ((100 ^ (((~(((v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) & 104)))));
  v154->timer = v281;
  int * v170 = v154->cache_vals;
  bool v282 = !(((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) == 0);
  int v263;
  if (v282) {
    int * v171 = v154->cache_age;
    int v284 = ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) & 1);
    int v172 = v171[v284];
    int v173 = v171[v277];
    int v285 = v173 + ((int)((unsigned int)(v173 - v172) >> 31));
    v171[v277] = v285;
    int * v175 = v154->cache_age;
    int v176 = v175[v278];
    int v287 = v176 + ((int)((unsigned int)(v176 - v172) >> 31));
    v175[v278] = v287;
    int * v178 = v154->cache_age;
    v178[v284] = 0;
    v263 = v284;
  } else {
    int * v181 = v154->cache_age;
    int v291 = (((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2;
    int v182 = v181[v291];
    int * v183 = v154->cache_tags;
    int v184 = v183[v291];
    int v185 = v181[v278];
    int v186 = v183[v278];
    bool v293 = !(((~(((v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) == 0);
    int v240;
    if (v293) {
      int * v187 = v154->cache_age;
      int v295 = (4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) & 1);
      int v188 = v187[v295];
      int v189 = v187[v279];
      int v296 = v189 + ((int)((unsigned int)(v189 - v188) >> 31));
      v187[v279] = v296;
      int * v191 = v154->cache_age;
      int v192 = v191[v280];
      int v298 = v192 + ((int)((unsigned int)(v192 - v188) >> 31));
      v191[v280] = v298;
      int * v194 = v154->cache_age;
      v194[v295] = 0;
      v240 = v295;
    } else {
      int * v197 = v154->cache_age;
      int v302 = 4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2);
      int v198 = v197[v302];
      int * v199 = v154->cache_tags;
      int v200 = v199[v302];
      int v201 = v197[v280];
      int v202 = v199[v280];
      int * v203 = v154->cache_dirty;
      int v305 = (4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v201 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v204 = v203[v305];
      bool v306 = !(v204 == 0);
      if (v306) {
        int * v205 = v154->cache_tags;
        int v206 = v205[v305];
        int * v207 = v154->cache_vals;
        int v309 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v201 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v208 = v207[v309];
        int v310 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v201 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v209 = v207[v310];
        int * v210 = v154->mem;
        int v312 = v206 * 2;
        v210[v312] = v208;
        int * v212 = v154->mem;
        int v315 = (v206 * 2) + 1;
        v212[v315] = v209;
        ;
      } else {
        ;
      }
      int * v217 = v154->mem;
      int v320 = ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) * 2;
      int v218 = v217[v320];
      int v321 = (((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) * 2) + 1;
      int v219 = v217[v321];
      int * v220 = v154->cache_vals;
      int v323 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v201 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v220[v323] = v218;
      int * v222 = v154->cache_vals;
      int v326 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v198 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2)) - (v201 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v222[v326] = v219;
      int * v224 = v154->cache_tags;
      int v329 = (int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1);
      v224[v305] = v329;
      int * v226 = v154->cache_dirty;
      v226[v305] = 0;
      int * v228 = v154->cache_age;
      v228[v305] = 1;
      int * v230 = v154->cache_age;
      int v231 = v230[v305];
      int v232 = v230[v279];
      int v335 = v232 + ((int)((unsigned int)(v232 - v231) >> 31));
      v230[v279] = v335;
      int * v234 = v154->cache_age;
      int v235 = v234[v280];
      int v337 = v235 + ((int)((unsigned int)(v235 - v231) >> 31));
      v234[v280] = v337;
      int * v237 = v154->cache_age;
      v237[v305] = 0;
      v240 = v305;
    }
    int * v241 = v154->cache_vals;
    int v340 = v240 * 2;
    int v242 = v241[v340];
    int v341 = (v240 * 2) + 1;
    int v243 = v241[v341];
    int v342 = (((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v185 + ((~(((v186 ^ -1) | (-(v186 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v241[v342] = v242;
    int * v245 = v154->cache_vals;
    int v345 = ((((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v185 + ((~(((v186 ^ -1) | (-(v186 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v245[v345] = v243;
    int * v247 = v154->cache_tags;
    int v348 = ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((((v182 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2)) - (v185 + ((~(((v186 ^ -1) | (-(v186 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v349 = (int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1);
    v247[v348] = v349;
    int * v249 = v154->cache_dirty;
    v249[v348] = 0;
    int * v251 = v154->cache_age;
    v251[v348] = 1;
    int * v253 = v154->cache_age;
    int v254 = v253[v348];
    int v255 = v253[v277];
    int v355 = v255 + ((int)((unsigned int)(v255 - v254) >> 31));
    v253[v277] = v355;
    int * v257 = v154->cache_age;
    int v258 = v257[v278];
    int v357 = v258 + ((int)((unsigned int)(v258 - v254) >> 31));
    v257[v278] = v357;
    int * v260 = v154->cache_age;
    v260[v348] = 0;
    v263 = v348;
  }
  int v360 = (v263 * 2) + (((int)((unsigned int)v162 >> 2)) & 1);
  int v264 = v170[v360];
  int * v265 = v154->regs;
  v265[10] = v264;
  struct StateG * v267 = slot_11(v154);
  return v267;
}

struct StateG * slot_4(struct StateG * v54) {
  int v55 = v54->timer;
  int v65 = v55 + 1;
  v54->timer = v65;
  int * v57 = v54->pht;
  int v58 = v57[0];
  bool v68 = !(v58 == 0);
  struct StateG * v63;
  if (v68) {
    struct StateG * v59 = slot_5(v54);
    v63 = v59;
  } else {
    struct StateG * v61 = slot_6(v54);
    v63 = v61;
  }
  return v63;
}

struct StateG * slot_15(struct StateG * v838) {
  int * v839 = v838->regs;
  int v840 = v839[14];
  int v841 = v839[15];
  bool v873 = v840 >= v841;
  struct StateG * v868;
  if (v873) {
    int * v842 = v838->pht;
    v842[0] = 1;
    int v844 = v838->timer;
    int v877 = v844 + 15;
    v838->timer = v877;
    int * v846 = v838->saved_regs;
    int v847 = v846[5];
    int * v848 = v838->regs;
    v848[5] = v847;
    int * v850 = v838->saved_regs;
    int v851 = v850[10];
    int * v852 = v838->regs;
    v852[10] = v851;
    int * v854 = v838->saved_regs;
    int v855 = v854[6];
    int * v856 = v838->regs;
    v856[6] = v855;
    int * v858 = v838->saved_regs;
    int v859 = v858[11];
    int * v860 = v838->regs;
    v860[11] = v859;
    struct StateG * v862 = slot_17(v838);
    v868 = v862;
  } else {
    int * v864 = v838->pht;
    v864[0] = 0;
    struct StateG * v866 = slot_18(v838);
    v868 = v866;
  }
  return v868;
}

struct StateG * slot_18(struct StateG * v1115) {
  int v1116 = v1115->timer;
  int v1126 = v1116 + 1;
  v1115->timer = v1126;
  int * v1118 = v1115->pht;
  int v1119 = v1118[16];
  bool v1129 = !(v1119 == 0);
  struct StateG * v1124;
  if (v1129) {
    struct StateG * v1120 = slot_19(v1115);
    v1124 = v1120;
  } else {
    struct StateG * v1122 = slot_20(v1115);
    v1124 = v1122;
  }
  return v1124;
}

struct StateG * slot_22(struct StateG * v1217) {
  int * v1218 = v1217->regs;
  int v1219 = v1218[10];
  int v1220 = v1218[11];
  bool v1240 = !(v1219 == v1220);
  struct StateG * v1235;
  if (v1240) {
    int * v1221 = v1217->pht;
    v1221[16] = 1;
    int v1223 = v1217->timer;
    int v1244 = v1223 + 15;
    v1217->timer = v1244;
    int * v1225 = v1217->saved_regs;
    int v1226 = v1225[14];
    int * v1227 = v1217->regs;
    v1227[14] = v1226;
    struct StateG * v1229 = slot_25(v1217);
    v1235 = v1229;
  } else {
    int * v1231 = v1217->pht;
    v1231[16] = 0;
    struct StateG * v1233 = slot_26(v1217);
    v1235 = v1233;
  }
  return v1235;
}

struct StateG * slot_11(struct StateG * v382) {
  int * v383 = v382->saved_regs;
  int * v384 = v382->regs;
  int v385 = v384[6];
  v383[6] = v385;
  int v387 = v382->timer;
  int v399 = v387 + 1;
  v382->timer = v399;
  int * v389 = v382->regs;
  int v390 = v389[13];
  int v391 = v389[14];
  int v403 = v390 + v391;
  v389[6] = v403;
  struct StateG * v393 = slot_13(v382);
  return v393;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}