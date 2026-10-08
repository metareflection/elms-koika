// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT * slot_12(struct StateT * v561);
struct StateT * slot_14(struct StateT * v591);
struct StateT * slot_6(struct StateT * v275);
struct StateT * slot_16(struct StateT * v998);
struct StateT * slot_5(struct StateT * v72);
struct StateT * slot_17(struct StateT * v1014);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_7(struct StateT * v478);
struct StateT * slot_21(struct StateT * v1378);
struct StateT * slot_3(struct StateT * v43);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v527);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_8(struct StateT * v486);
struct StateT * slot_19(struct StateT * v1063);
struct StateT * slot_4(struct StateT * v59);
struct StateT * slot_13(struct StateT * v575);
struct StateT * slot_15(struct StateT * v794);
struct StateT * slot_9(struct StateT * v507);
struct StateT * slot_11(struct StateT * v541);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v561) {
  int v562 = v561->timer;
  int v569 = v562 + 1;
  v561->timer = v569;
  int * v564 = v561->regs;
  int v565 = v564[10];
  int v572 = (int)((unsigned int)v565 >> 26);
  v564[10] = v572;
  struct StateT * v567 = slot_13(v561);
  return v567;
}

struct StateT * slot_14(struct StateT * v591) {
  int v592 = v591->timer;
  int v702 = v592 + 1;
  v591->timer = v702;
  int * v594 = v591->regs;
  int v595 = v594[10];
  int * v596 = v591->cache_tags;
  int v706 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
  int v597 = v596[v706];
  int v707 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + 1;
  int v598 = v596[v707];
  int v708 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
  int v599 = v596[v708];
  int v709 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v600 = v596[v709];
  int v601 = v591->timer;
  int v710 = v601 + ((100 ^ (((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) & 104)))));
  v591->timer = v710;
  int * v603 = v591->cache_vals;
  bool v711 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
  int v696;
  if (v711) {
    int * v604 = v591->cache_age;
    int v713 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
    int v605 = v604[v713];
    int v606 = v604[v706];
    int v714 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
    v604[v706] = v714;
    int * v608 = v591->cache_age;
    int v609 = v608[v707];
    int v716 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
    v608[v707] = v716;
    int * v611 = v591->cache_age;
    v611[v713] = 0;
    v696 = v713;
  } else {
    int * v614 = v591->cache_age;
    int v720 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2;
    int v615 = v614[v720];
    int * v616 = v591->cache_tags;
    int v617 = v616[v720];
    int v618 = v614[v707];
    int v619 = v616[v707];
    bool v722 = !(((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) | (~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31))) == 0);
    int v673;
    if (v722) {
      int * v620 = v591->cache_age;
      int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1))))) >> 31)) & 1);
      int v621 = v620[v724];
      int v622 = v620[v708];
      int v725 = v622 + ((int)((unsigned int)(v622 - v621) >> 31));
      v620[v708] = v725;
      int * v624 = v591->cache_age;
      int v625 = v624[v709];
      int v727 = v625 + ((int)((unsigned int)(v625 - v621) >> 31));
      v624[v709] = v727;
      int * v627 = v591->cache_age;
      v627[v724] = 0;
      v673 = v724;
    } else {
      int * v630 = v591->cache_age;
      int v731 = 4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2);
      int v631 = v630[v731];
      int * v632 = v591->cache_tags;
      int v633 = v632[v731];
      int v634 = v630[v709];
      int v635 = v632[v709];
      int * v636 = v591->cache_dirty;
      int v734 = (4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v637 = v636[v734];
      bool v735 = !(v637 == 0);
      if (v735) {
        int * v638 = v591->cache_tags;
        int v639 = v638[v734];
        int * v640 = v591->cache_vals;
        int v738 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v641 = v640[v738];
        int v739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v642 = v640[v739];
        int * v643 = v591->mem;
        int v741 = v639 * 2;
        v643[v741] = v641;
        int * v645 = v591->mem;
        int v744 = (v639 * 2) + 1;
        v645[v744] = v642;
        ;
      } else {
        ;
      }
      int * v650 = v591->mem;
      int v749 = ((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2;
      int v651 = v650[v749];
      int v750 = (((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) * 2) + 1;
      int v652 = v650[v750];
      int * v653 = v591->cache_vals;
      int v752 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v653[v752] = v651;
      int * v655 = v591->cache_vals;
      int v755 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 3) * 2)) + ((((v631 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2)) - (v634 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v655[v755] = v652;
      int * v657 = v591->cache_tags;
      int v758 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
      v657[v734] = v758;
      int * v659 = v591->cache_dirty;
      v659[v734] = 0;
      int * v661 = v591->cache_age;
      v661[v734] = 1;
      int * v663 = v591->cache_age;
      int v664 = v663[v734];
      int v665 = v663[v708];
      int v764 = v665 + ((int)((unsigned int)(v665 - v664) >> 31));
      v663[v708] = v764;
      int * v667 = v591->cache_age;
      int v668 = v667[v709];
      int v766 = v668 + ((int)((unsigned int)(v668 - v664) >> 31));
      v667[v709] = v766;
      int * v670 = v591->cache_age;
      v670[v734] = 0;
      v673 = v734;
    }
    int * v674 = v591->cache_vals;
    int v769 = v673 * 2;
    int v675 = v674[v769];
    int v770 = (v673 * 2) + 1;
    int v676 = v674[v770];
    int v771 = (((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v674[v771] = v675;
    int * v678 = v591->cache_vals;
    int v774 = ((((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v678[v774] = v676;
    int * v680 = v591->cache_tags;
    int v777 = ((((int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1)) & 1) * 2) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v778 = (int)((unsigned int)((int)((unsigned int)v595 >> 2)) >> 1);
    v680[v777] = v778;
    int * v682 = v591->cache_dirty;
    v682[v777] = 0;
    int * v684 = v591->cache_age;
    v684[v777] = 1;
    int * v686 = v591->cache_age;
    int v687 = v686[v777];
    int v688 = v686[v706];
    int v784 = v688 + ((int)((unsigned int)(v688 - v687) >> 31));
    v686[v706] = v784;
    int * v690 = v591->cache_age;
    int v691 = v690[v707];
    int v786 = v691 + ((int)((unsigned int)(v691 - v687) >> 31));
    v690[v707] = v786;
    int * v693 = v591->cache_age;
    v693[v777] = 0;
    v696 = v777;
  }
  int v789 = (v696 * 2) + (((int)((unsigned int)v595 >> 2)) & 1);
  int v697 = v603[v789];
  int * v698 = v591->regs;
  v698[10] = v697;
  struct StateT * v700 = slot_15(v591);
  return v700;
}

struct StateT * slot_6(struct StateT * v275) {
  int v276 = v275->timer;
  int v386 = v276 + 1;
  v275->timer = v386;
  int * v278 = v275->regs;
  int v279 = v278[11];
  int * v280 = v275->cache_tags;
  int v390 = (((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2;
  int v281 = v280[v390];
  int v391 = ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + 1;
  int v282 = v280[v391];
  int v392 = 4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2);
  int v283 = v280[v392];
  int v393 = (4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v284 = v280[v393];
  int v285 = v275->timer;
  int v394 = v285 + ((100 ^ (((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) & 104)))));
  v275->timer = v394;
  int * v287 = v275->cache_vals;
  bool v395 = !(((~(((v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v281 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) == 0);
  int v380;
  if (v395) {
    int * v288 = v275->cache_age;
    int v397 = ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((~(((v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v282 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) & 1);
    int v289 = v288[v397];
    int v290 = v288[v390];
    int v398 = v290 + ((int)((unsigned int)(v290 - v289) >> 31));
    v288[v390] = v398;
    int * v292 = v275->cache_age;
    int v293 = v292[v391];
    int v400 = v293 + ((int)((unsigned int)(v293 - v289) >> 31));
    v292[v391] = v400;
    int * v295 = v275->cache_age;
    v295[v397] = 0;
    v380 = v397;
  } else {
    int * v298 = v275->cache_age;
    int v404 = (((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2;
    int v299 = v298[v404];
    int * v300 = v275->cache_tags;
    int v301 = v300[v404];
    int v302 = v298[v391];
    int v303 = v300[v391];
    bool v406 = !(((~(((v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v283 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) | (~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31))) == 0);
    int v357;
    if (v406) {
      int * v304 = v275->cache_age;
      int v408 = (4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((~(((v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))) | (-(v284 ^ ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1))))) >> 31)) & 1);
      int v305 = v304[v408];
      int v306 = v304[v392];
      int v409 = v306 + ((int)((unsigned int)(v306 - v305) >> 31));
      v304[v392] = v409;
      int * v308 = v275->cache_age;
      int v309 = v308[v393];
      int v411 = v309 + ((int)((unsigned int)(v309 - v305) >> 31));
      v308[v393] = v411;
      int * v311 = v275->cache_age;
      v311[v408] = 0;
      v357 = v408;
    } else {
      int * v314 = v275->cache_age;
      int v415 = 4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2);
      int v315 = v314[v415];
      int * v316 = v275->cache_tags;
      int v317 = v316[v415];
      int v318 = v314[v393];
      int v319 = v316[v393];
      int * v320 = v275->cache_dirty;
      int v418 = (4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v321 = v320[v418];
      bool v419 = !(v321 == 0);
      if (v419) {
        int * v322 = v275->cache_tags;
        int v323 = v322[v418];
        int * v324 = v275->cache_vals;
        int v422 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v325 = v324[v422];
        int v423 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v326 = v324[v423];
        int * v327 = v275->mem;
        int v425 = v323 * 2;
        v327[v425] = v325;
        int * v329 = v275->mem;
        int v428 = (v323 * 2) + 1;
        v329[v428] = v326;
        ;
      } else {
        ;
      }
      int * v334 = v275->mem;
      int v433 = ((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) * 2;
      int v335 = v334[v433];
      int v434 = (((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) * 2) + 1;
      int v336 = v334[v434];
      int * v337 = v275->cache_vals;
      int v436 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v337[v436] = v335;
      int * v339 = v275->cache_vals;
      int v439 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 3) * 2)) + ((((v315 + ((~(((v317 ^ -1) | (-(v317 ^ -1))) >> 31)) & 2)) - (v318 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v339[v439] = v336;
      int * v341 = v275->cache_tags;
      int v442 = (int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1);
      v341[v418] = v442;
      int * v343 = v275->cache_dirty;
      v343[v418] = 0;
      int * v345 = v275->cache_age;
      v345[v418] = 1;
      int * v347 = v275->cache_age;
      int v348 = v347[v418];
      int v349 = v347[v392];
      int v448 = v349 + ((int)((unsigned int)(v349 - v348) >> 31));
      v347[v392] = v448;
      int * v351 = v275->cache_age;
      int v352 = v351[v393];
      int v450 = v352 + ((int)((unsigned int)(v352 - v348) >> 31));
      v351[v393] = v450;
      int * v354 = v275->cache_age;
      v354[v418] = 0;
      v357 = v418;
    }
    int * v358 = v275->cache_vals;
    int v453 = v357 * 2;
    int v359 = v358[v453];
    int v454 = (v357 * 2) + 1;
    int v360 = v358[v454];
    int v455 = (((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v358[v455] = v359;
    int * v362 = v275->cache_vals;
    int v458 = ((((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v362[v458] = v360;
    int * v364 = v275->cache_tags;
    int v461 = ((((int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1)) & 1) * 2) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v462 = (int)((unsigned int)((int)((unsigned int)v279 >> 2)) >> 1);
    v364[v461] = v462;
    int * v366 = v275->cache_dirty;
    v366[v461] = 0;
    int * v368 = v275->cache_age;
    v368[v461] = 1;
    int * v370 = v275->cache_age;
    int v371 = v370[v461];
    int v372 = v370[v390];
    int v468 = v372 + ((int)((unsigned int)(v372 - v371) >> 31));
    v370[v390] = v468;
    int * v374 = v275->cache_age;
    int v375 = v374[v391];
    int v470 = v375 + ((int)((unsigned int)(v375 - v371) >> 31));
    v374[v391] = v470;
    int * v377 = v275->cache_age;
    v377[v461] = 0;
    v380 = v461;
  }
  int v473 = (v380 * 2) + (((int)((unsigned int)v279 >> 2)) & 1);
  int v381 = v287[v473];
  int * v382 = v275->regs;
  v382[11] = v381;
  struct StateT * v384 = slot_7(v275);
  return v384;
}

struct StateT * slot_16(struct StateT * v998) {
  int v999 = v998->timer;
  int v1007 = v999 + 1;
  v998->timer = v1007;
  int * v1001 = v998->regs;
  int v1002 = v1001[11];
  int v1003 = v1001[10];
  int v1011 = v1002 & v1003;
  v1001[10] = v1011;
  struct StateT * v1005 = slot_17(v998);
  return v1005;
}

struct StateT * slot_5(struct StateT * v72) {
  int v73 = v72->timer;
  int v183 = v73 + 1;
  v72->timer = v183;
  int * v75 = v72->regs;
  int v76 = v75[10];
  int * v77 = v72->cache_tags;
  int v187 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2;
  int v78 = v77[v187];
  int v188 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + 1;
  int v79 = v77[v188];
  int v189 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
  int v80 = v77[v189];
  int v190 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v81 = v77[v190];
  int v82 = v72->timer;
  int v191 = v82 + ((100 ^ (((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & 104)))));
  v72->timer = v191;
  int * v84 = v72->cache_vals;
  bool v192 = !(((~(((v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v78 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
  int v177;
  if (v192) {
    int * v85 = v72->cache_age;
    int v194 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
    int v86 = v85[v194];
    int v87 = v85[v187];
    int v195 = v87 + ((int)((unsigned int)(v87 - v86) >> 31));
    v85[v187] = v195;
    int * v89 = v72->cache_age;
    int v90 = v89[v188];
    int v197 = v90 + ((int)((unsigned int)(v90 - v86) >> 31));
    v89[v188] = v197;
    int * v92 = v72->cache_age;
    v92[v194] = 0;
    v177 = v194;
  } else {
    int * v95 = v72->cache_age;
    int v201 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2;
    int v96 = v95[v201];
    int * v97 = v72->cache_tags;
    int v98 = v97[v201];
    int v99 = v95[v188];
    int v100 = v97[v188];
    bool v203 = !(((~(((v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v80 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
    int v154;
    if (v203) {
      int * v101 = v72->cache_age;
      int v205 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((~(((v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v81 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
      int v102 = v101[v205];
      int v103 = v101[v189];
      int v206 = v103 + ((int)((unsigned int)(v103 - v102) >> 31));
      v101[v189] = v206;
      int * v105 = v72->cache_age;
      int v106 = v105[v190];
      int v208 = v106 + ((int)((unsigned int)(v106 - v102) >> 31));
      v105[v190] = v208;
      int * v108 = v72->cache_age;
      v108[v205] = 0;
      v154 = v205;
    } else {
      int * v111 = v72->cache_age;
      int v212 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
      int v112 = v111[v212];
      int * v113 = v72->cache_tags;
      int v114 = v113[v212];
      int v115 = v111[v190];
      int v116 = v113[v190];
      int * v117 = v72->cache_dirty;
      int v215 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v118 = v117[v215];
      bool v216 = !(v118 == 0);
      if (v216) {
        int * v119 = v72->cache_tags;
        int v120 = v119[v215];
        int * v121 = v72->cache_vals;
        int v219 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v122 = v121[v219];
        int v220 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v123 = v121[v220];
        int * v124 = v72->mem;
        int v222 = v120 * 2;
        v124[v222] = v122;
        int * v126 = v72->mem;
        int v225 = (v120 * 2) + 1;
        v126[v225] = v123;
        ;
      } else {
        ;
      }
      int * v131 = v72->mem;
      int v230 = ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2;
      int v132 = v131[v230];
      int v231 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2) + 1;
      int v133 = v131[v231];
      int * v134 = v72->cache_vals;
      int v233 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v134[v233] = v132;
      int * v136 = v72->cache_vals;
      int v236 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v115 + ((~(((v116 ^ -1) | (-(v116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v136[v236] = v133;
      int * v138 = v72->cache_tags;
      int v239 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
      v138[v215] = v239;
      int * v140 = v72->cache_dirty;
      v140[v215] = 0;
      int * v142 = v72->cache_age;
      v142[v215] = 1;
      int * v144 = v72->cache_age;
      int v145 = v144[v215];
      int v146 = v144[v189];
      int v245 = v146 + ((int)((unsigned int)(v146 - v145) >> 31));
      v144[v189] = v245;
      int * v148 = v72->cache_age;
      int v149 = v148[v190];
      int v247 = v149 + ((int)((unsigned int)(v149 - v145) >> 31));
      v148[v190] = v247;
      int * v151 = v72->cache_age;
      v151[v215] = 0;
      v154 = v215;
    }
    int * v155 = v72->cache_vals;
    int v250 = v154 * 2;
    int v156 = v155[v250];
    int v251 = (v154 * 2) + 1;
    int v157 = v155[v251];
    int v252 = (((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v155[v252] = v156;
    int * v159 = v72->cache_vals;
    int v255 = ((((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v159[v255] = v157;
    int * v161 = v72->cache_tags;
    int v258 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v259 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
    v161[v258] = v259;
    int * v163 = v72->cache_dirty;
    v163[v258] = 0;
    int * v165 = v72->cache_age;
    v165[v258] = 1;
    int * v167 = v72->cache_age;
    int v168 = v167[v258];
    int v169 = v167[v187];
    int v265 = v169 + ((int)((unsigned int)(v169 - v168) >> 31));
    v167[v187] = v265;
    int * v171 = v72->cache_age;
    int v172 = v171[v188];
    int v267 = v172 + ((int)((unsigned int)(v172 - v168) >> 31));
    v171[v188] = v267;
    int * v174 = v72->cache_age;
    v174[v258] = 0;
    v177 = v258;
  }
  int v270 = (v177 * 2) + (((int)((unsigned int)v76 >> 2)) & 1);
  int v178 = v84[v270];
  int * v179 = v72->regs;
  v179[10] = v178;
  struct StateT * v181 = slot_6(v72);
  return v181;
}

struct StateT * slot_17(struct StateT * v1014) {
  int * v1015 = v1014->saved_regs;
  int v1016 = v1015[10];
  int v1017 = v1015[11];
  bool v1041 = (v1016 ^ -2147483648) >= (v1017 ^ -2147483648);
  struct StateT * v1036;
  if (v1041) {
    int v1018 = v1014->timer;
    int v1042 = v1018 + 15;
    v1014->timer = v1042;
    int * v1020 = v1014->saved_regs;
    int v1021 = v1020[10];
    int * v1022 = v1014->regs;
    v1022[10] = v1021;
    int * v1024 = v1014->saved_regs;
    int v1025 = v1024[11];
    int * v1026 = v1014->regs;
    v1026[11] = v1025;
    int * v1028 = v1014->saved_regs;
    int v1029 = v1028[12];
    int * v1030 = v1014->regs;
    v1030[12] = v1029;
    struct StateT * v1032 = slot_21(v1014);
    v1036 = v1032;
  } else {
    struct StateT * v1034 = slot_19(v1014);
    v1036 = v1034;
  }
  return v1036;
}

struct StateT * slot_2(struct StateT * v29) {
  int v30 = v29->timer;
  int v37 = v30 + 1;
  v29->timer = v37;
  int * v32 = v29->regs;
  int v33 = v32[11];
  int v40 = v33 + 72;
  v32[11] = v40;
  struct StateT * v35 = slot_3(v29);
  return v35;
}

struct StateT * slot_7(struct StateT * v478) {
  int v479 = v478->timer;
  int v483 = v479 + 1;
  v478->timer = v483;
  struct StateT * v481 = slot_8(v478);
  return v481;
}

struct StateT * slot_21(struct StateT * v1378) {
  int v1379 = v1378->timer;
  int v1382 = v1379 + 1;
  v1378->timer = v1382;
  return v1378;
}

struct StateT * slot_3(struct StateT * v43) {
  int v44 = v43->timer;
  int v52 = v44 + 1;
  v43->timer = v52;
  int * v46 = v43->regs;
  int v47 = v46[11];
  int v48 = v46[10];
  int v56 = v47 + v48;
  v46[10] = v56;
  struct StateT * v50 = slot_4(v43);
  return v50;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v527) {
  int v528 = v527->timer;
  int v535 = v528 + 1;
  v527->timer = v535;
  int * v530 = v527->regs;
  int v531 = v530[11];
  int v538 = v531 + 4;
  v530[11] = v538;
  struct StateT * v533 = slot_11(v527);
  return v533;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v23 = v17 + 1;
  v16->timer = v23;
  int * v19 = v16->regs;
  v19[11] = 0;
  struct StateT * v21 = slot_2(v16);
  return v21;
}

struct StateT * slot_8(struct StateT * v486) {
  int * v487 = v486->saved_regs;
  int * v488 = v486->regs;
  int v489 = v488[10];
  v487[10] = v489;
  int v491 = v486->timer;
  int v502 = v491 + 1;
  v486->timer = v502;
  int * v493 = v486->regs;
  int v494 = v493[10];
  int v504 = v494 << 29;
  v493[10] = v504;
  struct StateT * v496 = slot_9(v486);
  return v496;
}

struct StateT * slot_19(struct StateT * v1063) {
  int v1064 = v1063->timer;
  int v1234 = v1064 + 1;
  v1063->timer = v1234;
  int * v1066 = v1063->regs;
  int v1067 = v1066[12];
  int v1068 = v1066[10];
  int * v1069 = v1063->cache_tags;
  int v1239 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1070 = v1069[v1239];
  int v1240 = ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1071 = v1069[v1240];
  int v1241 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1072 = v1069[v1241];
  int v1242 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1073 = v1069[v1242];
  int v1074 = v1063->timer;
  int v1243 = v1074 + ((100 ^ (((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1063->timer = v1243;
  bool v1244 = !(((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1168;
  if (v1244) {
    int * v1076 = v1063->cache_age;
    int v1246 = ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1077 = v1076[v1246];
    int v1078 = v1076[v1239];
    int v1247 = v1078 + ((int)((unsigned int)(v1078 - v1077) >> 31));
    v1076[v1239] = v1247;
    int * v1080 = v1063->cache_age;
    int v1081 = v1080[v1240];
    int v1249 = v1081 + ((int)((unsigned int)(v1081 - v1077) >> 31));
    v1080[v1240] = v1249;
    int * v1083 = v1063->cache_age;
    v1083[v1246] = 0;
    v1168 = v1246;
  } else {
    int * v1086 = v1063->cache_age;
    int v1253 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1087 = v1086[v1253];
    int * v1088 = v1063->cache_tags;
    int v1089 = v1088[v1253];
    int v1090 = v1086[v1240];
    int v1091 = v1088[v1240];
    bool v1255 = !(((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1145;
    if (v1255) {
      int * v1092 = v1063->cache_age;
      int v1257 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1093 = v1092[v1257];
      int v1094 = v1092[v1241];
      int v1258 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
      v1092[v1241] = v1258;
      int * v1096 = v1063->cache_age;
      int v1097 = v1096[v1242];
      int v1260 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
      v1096[v1242] = v1260;
      int * v1099 = v1063->cache_age;
      v1099[v1257] = 0;
      v1145 = v1257;
    } else {
      int * v1102 = v1063->cache_age;
      int v1264 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1103 = v1102[v1264];
      int * v1104 = v1063->cache_tags;
      int v1105 = v1104[v1264];
      int v1106 = v1102[v1242];
      int v1107 = v1104[v1242];
      int * v1108 = v1063->cache_dirty;
      int v1267 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1109 = v1108[v1267];
      bool v1268 = !(v1109 == 0);
      if (v1268) {
        int * v1110 = v1063->cache_tags;
        int v1111 = v1110[v1267];
        int * v1112 = v1063->cache_vals;
        int v1271 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1113 = v1112[v1271];
        int v1272 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1114 = v1112[v1272];
        int * v1115 = v1063->mem;
        int v1274 = v1111 * 2;
        v1115[v1274] = v1113;
        int * v1117 = v1063->mem;
        int v1277 = (v1111 * 2) + 1;
        v1117[v1277] = v1114;
        ;
      } else {
        ;
      }
      int * v1122 = v1063->mem;
      int v1282 = ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2;
      int v1123 = v1122[v1282];
      int v1283 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1124 = v1122[v1283];
      int * v1125 = v1063->cache_vals;
      int v1285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1125[v1285] = v1123;
      int * v1127 = v1063->cache_vals;
      int v1288 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1127[v1288] = v1124;
      int * v1129 = v1063->cache_tags;
      int v1291 = (int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1);
      v1129[v1267] = v1291;
      int * v1131 = v1063->cache_dirty;
      v1131[v1267] = 0;
      int * v1133 = v1063->cache_age;
      v1133[v1267] = 1;
      int * v1135 = v1063->cache_age;
      int v1136 = v1135[v1267];
      int v1137 = v1135[v1241];
      int v1297 = v1137 + ((int)((unsigned int)(v1137 - v1136) >> 31));
      v1135[v1241] = v1297;
      int * v1139 = v1063->cache_age;
      int v1140 = v1139[v1242];
      int v1299 = v1140 + ((int)((unsigned int)(v1140 - v1136) >> 31));
      v1139[v1242] = v1299;
      int * v1142 = v1063->cache_age;
      v1142[v1267] = 0;
      v1145 = v1267;
    }
    int * v1146 = v1063->cache_vals;
    int v1302 = v1145 * 2;
    int v1147 = v1146[v1302];
    int v1303 = (v1145 * 2) + 1;
    int v1148 = v1146[v1303];
    int v1304 = (((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1146[v1304] = v1147;
    int * v1150 = v1063->cache_vals;
    int v1307 = ((((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1150[v1307] = v1148;
    int * v1152 = v1063->cache_tags;
    int v1310 = ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1311 = (int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1);
    v1152[v1310] = v1311;
    int * v1154 = v1063->cache_dirty;
    v1154[v1310] = 0;
    int * v1156 = v1063->cache_age;
    v1156[v1310] = 1;
    int * v1158 = v1063->cache_age;
    int v1159 = v1158[v1310];
    int v1160 = v1158[v1239];
    int v1317 = v1160 + ((int)((unsigned int)(v1160 - v1159) >> 31));
    v1158[v1239] = v1317;
    int * v1162 = v1063->cache_age;
    int v1163 = v1162[v1240];
    int v1319 = v1163 + ((int)((unsigned int)(v1163 - v1159) >> 31));
    v1162[v1240] = v1319;
    int * v1165 = v1063->cache_age;
    v1165[v1310] = 0;
    v1168 = v1310;
  }
  int * v1169 = v1063->cache_vals;
  int v1322 = (v1168 * 2) + (((int)((unsigned int)(v1067 + 68) >> 2)) & 1);
  v1169[v1322] = v1068;
  int * v1171 = v1063->cache_tags;
  int v1172 = v1171[v1241];
  int v1173 = v1171[v1242];
  bool v1325 = !(((~(((v1172 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1172 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1227;
  if (v1325) {
    int * v1174 = v1063->cache_age;
    int v1327 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))) | (-(v1173 ^ ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1175 = v1174[v1327];
    int v1176 = v1174[v1241];
    int v1328 = v1176 + ((int)((unsigned int)(v1176 - v1175) >> 31));
    v1174[v1241] = v1328;
    int * v1178 = v1063->cache_age;
    int v1179 = v1178[v1242];
    int v1330 = v1179 + ((int)((unsigned int)(v1179 - v1175) >> 31));
    v1178[v1242] = v1330;
    int * v1181 = v1063->cache_age;
    v1181[v1327] = 0;
    v1227 = v1327;
  } else {
    int * v1184 = v1063->cache_age;
    int v1334 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1185 = v1184[v1334];
    int * v1186 = v1063->cache_tags;
    int v1187 = v1186[v1334];
    int v1188 = v1184[v1242];
    int v1189 = v1186[v1242];
    int * v1190 = v1063->cache_dirty;
    int v1337 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1191 = v1190[v1337];
    bool v1338 = !(v1191 == 0);
    if (v1338) {
      int * v1192 = v1063->cache_tags;
      int v1193 = v1192[v1337];
      int * v1194 = v1063->cache_vals;
      int v1341 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1195 = v1194[v1341];
      int v1342 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1196 = v1194[v1342];
      int * v1197 = v1063->mem;
      int v1344 = v1193 * 2;
      v1197[v1344] = v1195;
      int * v1199 = v1063->mem;
      int v1347 = (v1193 * 2) + 1;
      v1199[v1347] = v1196;
      ;
    } else {
      ;
    }
    int * v1204 = v1063->mem;
    int v1352 = ((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2;
    int v1205 = v1204[v1352];
    int v1353 = (((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1206 = v1204[v1353];
    int * v1207 = v1063->cache_vals;
    int v1355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1207[v1355] = v1205;
    int * v1209 = v1063->cache_vals;
    int v1358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1185 + ((~(((v1187 ^ -1) | (-(v1187 ^ -1))) >> 31)) & 2)) - (v1188 + ((~(((v1189 ^ -1) | (-(v1189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1209[v1358] = v1206;
    int * v1211 = v1063->cache_tags;
    int v1361 = (int)((unsigned int)((int)((unsigned int)(v1067 + 68) >> 2)) >> 1);
    v1211[v1337] = v1361;
    int * v1213 = v1063->cache_dirty;
    v1213[v1337] = 0;
    int * v1215 = v1063->cache_age;
    v1215[v1337] = 1;
    int * v1217 = v1063->cache_age;
    int v1218 = v1217[v1337];
    int v1219 = v1217[v1241];
    int v1367 = v1219 + ((int)((unsigned int)(v1219 - v1218) >> 31));
    v1217[v1241] = v1367;
    int * v1221 = v1063->cache_age;
    int v1222 = v1221[v1242];
    int v1369 = v1222 + ((int)((unsigned int)(v1222 - v1218) >> 31));
    v1221[v1242] = v1369;
    int * v1224 = v1063->cache_age;
    v1224[v1337] = 0;
    v1227 = v1337;
  }
  int * v1228 = v1063->cache_vals;
  int v1372 = (v1227 * 2) + (((int)((unsigned int)(v1067 + 68) >> 2)) & 1);
  v1228[v1372] = v1068;
  int * v1230 = v1063->cache_dirty;
  v1230[v1227] = 1;
  struct StateT * v1232 = slot_21(v1063);
  return v1232;
}

struct StateT * slot_4(struct StateT * v59) {
  int v60 = v59->timer;
  int v66 = v60 + 1;
  v59->timer = v66;
  int * v62 = v59->regs;
  v62[11] = 0;
  struct StateT * v64 = slot_5(v59);
  return v64;
}

struct StateT * slot_13(struct StateT * v575) {
  int v576 = v575->timer;
  int v584 = v576 + 1;
  v575->timer = v584;
  int * v578 = v575->regs;
  int v579 = v578[11];
  int v580 = v578[10];
  int v588 = v579 + v580;
  v578[10] = v588;
  struct StateT * v582 = slot_14(v575);
  return v582;
}

struct StateT * slot_15(struct StateT * v794) {
  int v795 = v794->timer;
  int v905 = v795 + 1;
  v794->timer = v905;
  int * v797 = v794->regs;
  int v798 = v797[12];
  int * v799 = v794->cache_tags;
  int v909 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2;
  int v800 = v799[v909];
  int v910 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v801 = v799[v910];
  int v911 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2);
  int v802 = v799[v911];
  int v912 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v803 = v799[v912];
  int v804 = v794->timer;
  int v913 = v804 + ((100 ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v794->timer = v913;
  int * v806 = v794->cache_vals;
  bool v914 = !(((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v899;
  if (v914) {
    int * v807 = v794->cache_age;
    int v916 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v808 = v807[v916];
    int v809 = v807[v909];
    int v917 = v809 + ((int)((unsigned int)(v809 - v808) >> 31));
    v807[v909] = v917;
    int * v811 = v794->cache_age;
    int v812 = v811[v910];
    int v919 = v812 + ((int)((unsigned int)(v812 - v808) >> 31));
    v811[v910] = v919;
    int * v814 = v794->cache_age;
    v814[v916] = 0;
    v899 = v916;
  } else {
    int * v817 = v794->cache_age;
    int v923 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2;
    int v818 = v817[v923];
    int * v819 = v794->cache_tags;
    int v820 = v819[v923];
    int v821 = v817[v910];
    int v822 = v819[v910];
    bool v925 = !(((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v876;
    if (v925) {
      int * v823 = v794->cache_age;
      int v927 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v824 = v823[v927];
      int v825 = v823[v911];
      int v928 = v825 + ((int)((unsigned int)(v825 - v824) >> 31));
      v823[v911] = v928;
      int * v827 = v794->cache_age;
      int v828 = v827[v912];
      int v930 = v828 + ((int)((unsigned int)(v828 - v824) >> 31));
      v827[v912] = v930;
      int * v830 = v794->cache_age;
      v830[v927] = 0;
      v876 = v927;
    } else {
      int * v833 = v794->cache_age;
      int v934 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2);
      int v834 = v833[v934];
      int * v835 = v794->cache_tags;
      int v836 = v835[v934];
      int v837 = v833[v912];
      int v838 = v835[v912];
      int * v839 = v794->cache_dirty;
      int v937 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v840 = v839[v937];
      bool v938 = !(v840 == 0);
      if (v938) {
        int * v841 = v794->cache_tags;
        int v842 = v841[v937];
        int * v843 = v794->cache_vals;
        int v941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v844 = v843[v941];
        int v942 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v845 = v843[v942];
        int * v846 = v794->mem;
        int v944 = v842 * 2;
        v846[v944] = v844;
        int * v848 = v794->mem;
        int v947 = (v842 * 2) + 1;
        v848[v947] = v845;
        ;
      } else {
        ;
      }
      int * v853 = v794->mem;
      int v952 = ((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) * 2;
      int v854 = v853[v952];
      int v953 = (((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) * 2) + 1;
      int v855 = v853[v953];
      int * v856 = v794->cache_vals;
      int v955 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v856[v955] = v854;
      int * v858 = v794->cache_vals;
      int v958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v858[v958] = v855;
      int * v860 = v794->cache_tags;
      int v961 = (int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1);
      v860[v937] = v961;
      int * v862 = v794->cache_dirty;
      v862[v937] = 0;
      int * v864 = v794->cache_age;
      v864[v937] = 1;
      int * v866 = v794->cache_age;
      int v867 = v866[v937];
      int v868 = v866[v911];
      int v967 = v868 + ((int)((unsigned int)(v868 - v867) >> 31));
      v866[v911] = v967;
      int * v870 = v794->cache_age;
      int v871 = v870[v912];
      int v969 = v871 + ((int)((unsigned int)(v871 - v867) >> 31));
      v870[v912] = v969;
      int * v873 = v794->cache_age;
      v873[v937] = 0;
      v876 = v937;
    }
    int * v877 = v794->cache_vals;
    int v972 = v876 * 2;
    int v878 = v877[v972];
    int v973 = (v876 * 2) + 1;
    int v879 = v877[v973];
    int v974 = (((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v877[v974] = v878;
    int * v881 = v794->cache_vals;
    int v977 = ((((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v881[v977] = v879;
    int * v883 = v794->cache_tags;
    int v980 = ((((int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v821 + ((~(((v822 ^ -1) | (-(v822 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v981 = (int)((unsigned int)((int)((unsigned int)(v798 + 68) >> 2)) >> 1);
    v883[v980] = v981;
    int * v885 = v794->cache_dirty;
    v885[v980] = 0;
    int * v887 = v794->cache_age;
    v887[v980] = 1;
    int * v889 = v794->cache_age;
    int v890 = v889[v980];
    int v891 = v889[v909];
    int v987 = v891 + ((int)((unsigned int)(v891 - v890) >> 31));
    v889[v909] = v987;
    int * v893 = v794->cache_age;
    int v894 = v893[v910];
    int v989 = v894 + ((int)((unsigned int)(v894 - v890) >> 31));
    v893[v910] = v989;
    int * v896 = v794->cache_age;
    v896[v980] = 0;
    v899 = v980;
  }
  int v992 = (v899 * 2) + (((int)((unsigned int)(v798 + 68) >> 2)) & 1);
  int v900 = v806[v992];
  int * v901 = v794->regs;
  v901[11] = v900;
  struct StateT * v903 = slot_16(v794);
  return v903;
}

struct StateT * slot_9(struct StateT * v507) {
  int * v508 = v507->saved_regs;
  int * v509 = v507->regs;
  int v510 = v509[11];
  v508[11] = v510;
  int v512 = v507->timer;
  int v522 = v512 + 1;
  v507->timer = v522;
  int * v514 = v507->regs;
  v514[11] = 0;
  struct StateT * v516 = slot_10(v507);
  return v516;
}

struct StateT * slot_11(struct StateT * v541) {
  int * v542 = v541->saved_regs;
  int * v543 = v541->regs;
  int v544 = v543[12];
  v542[12] = v544;
  int v546 = v541->timer;
  int v556 = v546 + 1;
  v541->timer = v556;
  int * v548 = v541->regs;
  v548[12] = 0;
  struct StateT * v550 = slot_12(v541);
  return v550;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v13 = v6 << 2;
  v5[10] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
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