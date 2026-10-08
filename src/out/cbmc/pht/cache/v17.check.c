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

struct StateT * slot_12(struct StateT * v559);
struct StateT * slot_14(struct StateT * v589);
struct StateT * slot_6(struct StateT * v275);
struct StateT * slot_16(struct StateT * v996);
struct StateT * slot_5(struct StateT * v72);
struct StateT * slot_17(struct StateT * v1012);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_7(struct StateT * v478);
struct StateT * slot_3(struct StateT * v43);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v532);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_8(struct StateT * v505);
struct StateT * slot_4(struct StateT * v59);
struct StateT * slot_13(struct StateT * v573);
struct StateT * slot_15(struct StateT * v792);
struct StateT * slot_18(struct StateT * v500);
struct StateT * slot_9(struct StateT * v519);
struct StateT * slot_11(struct StateT * v546);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v559) {
  int v560 = v559->timer;
  int v567 = v560 + 1;
  v559->timer = v567;
  int * v562 = v559->regs;
  int v563 = v562[10];
  int v570 = (int)((unsigned int)v563 >> 26);
  v562[10] = v570;
  struct StateT * v565 = slot_13(v559);
  return v565;
}

struct StateT * slot_14(struct StateT * v589) {
  int v590 = v589->timer;
  int v700 = v590 + 1;
  v589->timer = v700;
  int * v592 = v589->regs;
  int v593 = v592[10];
  int * v594 = v589->cache_tags;
  int v704 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2;
  int v595 = v594[v704];
  int v705 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + 1;
  int v596 = v594[v705];
  int v706 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
  int v597 = v594[v706];
  int v707 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v598 = v594[v707];
  int v599 = v589->timer;
  int v708 = v599 + ((100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & 104)))));
  v589->timer = v708;
  int * v601 = v589->cache_vals;
  bool v709 = !(((~(((v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v595 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
  int v694;
  if (v709) {
    int * v602 = v589->cache_age;
    int v711 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
    int v603 = v602[v711];
    int v604 = v602[v704];
    int v712 = v604 + ((int)((unsigned int)(v604 - v603) >> 31));
    v602[v704] = v712;
    int * v606 = v589->cache_age;
    int v607 = v606[v705];
    int v714 = v607 + ((int)((unsigned int)(v607 - v603) >> 31));
    v606[v705] = v714;
    int * v609 = v589->cache_age;
    v609[v711] = 0;
    v694 = v711;
  } else {
    int * v612 = v589->cache_age;
    int v718 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2;
    int v613 = v612[v718];
    int * v614 = v589->cache_tags;
    int v615 = v614[v718];
    int v616 = v612[v705];
    int v617 = v614[v705];
    bool v720 = !(((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
    int v671;
    if (v720) {
      int * v618 = v589->cache_age;
      int v722 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
      int v619 = v618[v722];
      int v620 = v618[v706];
      int v723 = v620 + ((int)((unsigned int)(v620 - v619) >> 31));
      v618[v706] = v723;
      int * v622 = v589->cache_age;
      int v623 = v622[v707];
      int v725 = v623 + ((int)((unsigned int)(v623 - v619) >> 31));
      v622[v707] = v725;
      int * v625 = v589->cache_age;
      v625[v722] = 0;
      v671 = v722;
    } else {
      int * v628 = v589->cache_age;
      int v729 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
      int v629 = v628[v729];
      int * v630 = v589->cache_tags;
      int v631 = v630[v729];
      int v632 = v628[v707];
      int v633 = v630[v707];
      int * v634 = v589->cache_dirty;
      int v732 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v635 = v634[v732];
      bool v733 = !(v635 == 0);
      if (v733) {
        int * v636 = v589->cache_tags;
        int v637 = v636[v732];
        int * v638 = v589->cache_vals;
        int v736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v639 = v638[v736];
        int v737 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v640 = v638[v737];
        int * v641 = v589->mem;
        int v739 = v637 * 2;
        v641[v739] = v639;
        int * v643 = v589->mem;
        int v742 = (v637 * 2) + 1;
        v643[v742] = v640;
        ;
      } else {
        ;
      }
      int * v648 = v589->mem;
      int v747 = ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2;
      int v649 = v648[v747];
      int v748 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2) + 1;
      int v650 = v648[v748];
      int * v651 = v589->cache_vals;
      int v750 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v651[v750] = v649;
      int * v653 = v589->cache_vals;
      int v753 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v653[v753] = v650;
      int * v655 = v589->cache_tags;
      int v756 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
      v655[v732] = v756;
      int * v657 = v589->cache_dirty;
      v657[v732] = 0;
      int * v659 = v589->cache_age;
      v659[v732] = 1;
      int * v661 = v589->cache_age;
      int v662 = v661[v732];
      int v663 = v661[v706];
      int v762 = v663 + ((int)((unsigned int)(v663 - v662) >> 31));
      v661[v706] = v762;
      int * v665 = v589->cache_age;
      int v666 = v665[v707];
      int v764 = v666 + ((int)((unsigned int)(v666 - v662) >> 31));
      v665[v707] = v764;
      int * v668 = v589->cache_age;
      v668[v732] = 0;
      v671 = v732;
    }
    int * v672 = v589->cache_vals;
    int v767 = v671 * 2;
    int v673 = v672[v767];
    int v768 = (v671 * 2) + 1;
    int v674 = v672[v768];
    int v769 = (((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v672[v769] = v673;
    int * v676 = v589->cache_vals;
    int v772 = ((((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v676[v772] = v674;
    int * v678 = v589->cache_tags;
    int v775 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v776 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
    v678[v775] = v776;
    int * v680 = v589->cache_dirty;
    v680[v775] = 0;
    int * v682 = v589->cache_age;
    v682[v775] = 1;
    int * v684 = v589->cache_age;
    int v685 = v684[v775];
    int v686 = v684[v704];
    int v782 = v686 + ((int)((unsigned int)(v686 - v685) >> 31));
    v684[v704] = v782;
    int * v688 = v589->cache_age;
    int v689 = v688[v705];
    int v784 = v689 + ((int)((unsigned int)(v689 - v685) >> 31));
    v688[v705] = v784;
    int * v691 = v589->cache_age;
    v691[v775] = 0;
    v694 = v775;
  }
  int v787 = (v694 * 2) + (((int)((unsigned int)v593 >> 2)) & 1);
  int v695 = v601[v787];
  int * v696 = v589->regs;
  v696[10] = v695;
  struct StateT * v698 = slot_15(v589);
  return v698;
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

struct StateT * slot_16(struct StateT * v996) {
  int v997 = v996->timer;
  int v1005 = v997 + 1;
  v996->timer = v1005;
  int * v999 = v996->regs;
  int v1000 = v999[11];
  int v1001 = v999[10];
  int v1009 = v1000 & v1001;
  v999[10] = v1009;
  struct StateT * v1003 = slot_17(v996);
  return v1003;
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

struct StateT * slot_17(struct StateT * v1012) {
  int v1013 = v1012->timer;
  int v1183 = v1013 + 1;
  v1012->timer = v1183;
  int * v1015 = v1012->regs;
  int v1016 = v1015[12];
  int v1017 = v1015[10];
  int * v1018 = v1012->cache_tags;
  int v1188 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1019 = v1018[v1188];
  int v1189 = ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1020 = v1018[v1189];
  int v1190 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1021 = v1018[v1190];
  int v1191 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1022 = v1018[v1191];
  int v1023 = v1012->timer;
  int v1192 = v1023 + ((100 ^ (((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1012->timer = v1192;
  bool v1193 = !(((~(((v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1019 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1117;
  if (v1193) {
    int * v1025 = v1012->cache_age;
    int v1195 = ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1020 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1026 = v1025[v1195];
    int v1027 = v1025[v1188];
    int v1196 = v1027 + ((int)((unsigned int)(v1027 - v1026) >> 31));
    v1025[v1188] = v1196;
    int * v1029 = v1012->cache_age;
    int v1030 = v1029[v1189];
    int v1198 = v1030 + ((int)((unsigned int)(v1030 - v1026) >> 31));
    v1029[v1189] = v1198;
    int * v1032 = v1012->cache_age;
    v1032[v1195] = 0;
    v1117 = v1195;
  } else {
    int * v1035 = v1012->cache_age;
    int v1202 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1036 = v1035[v1202];
    int * v1037 = v1012->cache_tags;
    int v1038 = v1037[v1202];
    int v1039 = v1035[v1189];
    int v1040 = v1037[v1189];
    bool v1204 = !(((~(((v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1021 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1094;
    if (v1204) {
      int * v1041 = v1012->cache_age;
      int v1206 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1022 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1042 = v1041[v1206];
      int v1043 = v1041[v1190];
      int v1207 = v1043 + ((int)((unsigned int)(v1043 - v1042) >> 31));
      v1041[v1190] = v1207;
      int * v1045 = v1012->cache_age;
      int v1046 = v1045[v1191];
      int v1209 = v1046 + ((int)((unsigned int)(v1046 - v1042) >> 31));
      v1045[v1191] = v1209;
      int * v1048 = v1012->cache_age;
      v1048[v1206] = 0;
      v1094 = v1206;
    } else {
      int * v1051 = v1012->cache_age;
      int v1213 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1052 = v1051[v1213];
      int * v1053 = v1012->cache_tags;
      int v1054 = v1053[v1213];
      int v1055 = v1051[v1191];
      int v1056 = v1053[v1191];
      int * v1057 = v1012->cache_dirty;
      int v1216 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1058 = v1057[v1216];
      bool v1217 = !(v1058 == 0);
      if (v1217) {
        int * v1059 = v1012->cache_tags;
        int v1060 = v1059[v1216];
        int * v1061 = v1012->cache_vals;
        int v1220 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1062 = v1061[v1220];
        int v1221 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1063 = v1061[v1221];
        int * v1064 = v1012->mem;
        int v1223 = v1060 * 2;
        v1064[v1223] = v1062;
        int * v1066 = v1012->mem;
        int v1226 = (v1060 * 2) + 1;
        v1066[v1226] = v1063;
        ;
      } else {
        ;
      }
      int * v1071 = v1012->mem;
      int v1231 = ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2;
      int v1072 = v1071[v1231];
      int v1232 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1073 = v1071[v1232];
      int * v1074 = v1012->cache_vals;
      int v1234 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1074[v1234] = v1072;
      int * v1076 = v1012->cache_vals;
      int v1237 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1052 + ((~(((v1054 ^ -1) | (-(v1054 ^ -1))) >> 31)) & 2)) - (v1055 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1076[v1237] = v1073;
      int * v1078 = v1012->cache_tags;
      int v1240 = (int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1);
      v1078[v1216] = v1240;
      int * v1080 = v1012->cache_dirty;
      v1080[v1216] = 0;
      int * v1082 = v1012->cache_age;
      v1082[v1216] = 1;
      int * v1084 = v1012->cache_age;
      int v1085 = v1084[v1216];
      int v1086 = v1084[v1190];
      int v1246 = v1086 + ((int)((unsigned int)(v1086 - v1085) >> 31));
      v1084[v1190] = v1246;
      int * v1088 = v1012->cache_age;
      int v1089 = v1088[v1191];
      int v1248 = v1089 + ((int)((unsigned int)(v1089 - v1085) >> 31));
      v1088[v1191] = v1248;
      int * v1091 = v1012->cache_age;
      v1091[v1216] = 0;
      v1094 = v1216;
    }
    int * v1095 = v1012->cache_vals;
    int v1251 = v1094 * 2;
    int v1096 = v1095[v1251];
    int v1252 = (v1094 * 2) + 1;
    int v1097 = v1095[v1252];
    int v1253 = (((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1095[v1253] = v1096;
    int * v1099 = v1012->cache_vals;
    int v1256 = ((((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1099[v1256] = v1097;
    int * v1101 = v1012->cache_tags;
    int v1259 = ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1036 + ((~(((v1038 ^ -1) | (-(v1038 ^ -1))) >> 31)) & 2)) - (v1039 + ((~(((v1040 ^ -1) | (-(v1040 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1260 = (int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1);
    v1101[v1259] = v1260;
    int * v1103 = v1012->cache_dirty;
    v1103[v1259] = 0;
    int * v1105 = v1012->cache_age;
    v1105[v1259] = 1;
    int * v1107 = v1012->cache_age;
    int v1108 = v1107[v1259];
    int v1109 = v1107[v1188];
    int v1266 = v1109 + ((int)((unsigned int)(v1109 - v1108) >> 31));
    v1107[v1188] = v1266;
    int * v1111 = v1012->cache_age;
    int v1112 = v1111[v1189];
    int v1268 = v1112 + ((int)((unsigned int)(v1112 - v1108) >> 31));
    v1111[v1189] = v1268;
    int * v1114 = v1012->cache_age;
    v1114[v1259] = 0;
    v1117 = v1259;
  }
  int * v1118 = v1012->cache_vals;
  int v1271 = (v1117 * 2) + (((int)((unsigned int)(v1016 + 68) >> 2)) & 1);
  v1118[v1271] = v1017;
  int * v1120 = v1012->cache_tags;
  int v1121 = v1120[v1190];
  int v1122 = v1120[v1191];
  bool v1274 = !(((~(((v1121 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1121 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1176;
  if (v1274) {
    int * v1123 = v1012->cache_age;
    int v1276 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))) | (-(v1122 ^ ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1124 = v1123[v1276];
    int v1125 = v1123[v1190];
    int v1277 = v1125 + ((int)((unsigned int)(v1125 - v1124) >> 31));
    v1123[v1190] = v1277;
    int * v1127 = v1012->cache_age;
    int v1128 = v1127[v1191];
    int v1279 = v1128 + ((int)((unsigned int)(v1128 - v1124) >> 31));
    v1127[v1191] = v1279;
    int * v1130 = v1012->cache_age;
    v1130[v1276] = 0;
    v1176 = v1276;
  } else {
    int * v1133 = v1012->cache_age;
    int v1283 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1134 = v1133[v1283];
    int * v1135 = v1012->cache_tags;
    int v1136 = v1135[v1283];
    int v1137 = v1133[v1191];
    int v1138 = v1135[v1191];
    int * v1139 = v1012->cache_dirty;
    int v1286 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1140 = v1139[v1286];
    bool v1287 = !(v1140 == 0);
    if (v1287) {
      int * v1141 = v1012->cache_tags;
      int v1142 = v1141[v1286];
      int * v1143 = v1012->cache_vals;
      int v1290 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1144 = v1143[v1290];
      int v1291 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1145 = v1143[v1291];
      int * v1146 = v1012->mem;
      int v1293 = v1142 * 2;
      v1146[v1293] = v1144;
      int * v1148 = v1012->mem;
      int v1296 = (v1142 * 2) + 1;
      v1148[v1296] = v1145;
      ;
    } else {
      ;
    }
    int * v1153 = v1012->mem;
    int v1301 = ((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2;
    int v1154 = v1153[v1301];
    int v1302 = (((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1155 = v1153[v1302];
    int * v1156 = v1012->cache_vals;
    int v1304 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1156[v1304] = v1154;
    int * v1158 = v1012->cache_vals;
    int v1307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1137 + ((~(((v1138 ^ -1) | (-(v1138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1158[v1307] = v1155;
    int * v1160 = v1012->cache_tags;
    int v1310 = (int)((unsigned int)((int)((unsigned int)(v1016 + 68) >> 2)) >> 1);
    v1160[v1286] = v1310;
    int * v1162 = v1012->cache_dirty;
    v1162[v1286] = 0;
    int * v1164 = v1012->cache_age;
    v1164[v1286] = 1;
    int * v1166 = v1012->cache_age;
    int v1167 = v1166[v1286];
    int v1168 = v1166[v1190];
    int v1316 = v1168 + ((int)((unsigned int)(v1168 - v1167) >> 31));
    v1166[v1190] = v1316;
    int * v1170 = v1012->cache_age;
    int v1171 = v1170[v1191];
    int v1318 = v1171 + ((int)((unsigned int)(v1171 - v1167) >> 31));
    v1170[v1191] = v1318;
    int * v1173 = v1012->cache_age;
    v1173[v1286] = 0;
    v1176 = v1286;
  }
  int * v1177 = v1012->cache_vals;
  int v1321 = (v1176 * 2) + (((int)((unsigned int)(v1016 + 68) >> 2)) & 1);
  v1177[v1321] = v1017;
  int * v1179 = v1012->cache_dirty;
  v1179[v1176] = 1;
  struct StateT * v1181 = slot_18(v1012);
  return v1181;
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
  int v490 = v479 + 1;
  v478->timer = v490;
  int * v481 = v478->regs;
  int v482 = v481[10];
  int v483 = v481[11];
  bool v494 = (v482 ^ -2147483648) >= (v483 ^ -2147483648);
  struct StateT * v488;
  if (v494) {
    struct StateT * v484 = slot_18(v478);
    v488 = v484;
  } else {
    struct StateT * v486 = slot_8(v478);
    v488 = v486;
  }
  return v488;
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

struct StateT * slot_10(struct StateT * v532) {
  int v533 = v532->timer;
  int v540 = v533 + 1;
  v532->timer = v540;
  int * v535 = v532->regs;
  int v536 = v535[11];
  int v543 = v536 + 4;
  v535[11] = v543;
  struct StateT * v538 = slot_11(v532);
  return v538;
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

struct StateT * slot_8(struct StateT * v505) {
  int v506 = v505->timer;
  int v513 = v506 + 1;
  v505->timer = v513;
  int * v508 = v505->regs;
  int v509 = v508[10];
  int v516 = v509 << 29;
  v508[10] = v516;
  struct StateT * v511 = slot_9(v505);
  return v511;
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

struct StateT * slot_13(struct StateT * v573) {
  int v574 = v573->timer;
  int v582 = v574 + 1;
  v573->timer = v582;
  int * v576 = v573->regs;
  int v577 = v576[11];
  int v578 = v576[10];
  int v586 = v577 + v578;
  v576[10] = v586;
  struct StateT * v580 = slot_14(v573);
  return v580;
}

struct StateT * slot_15(struct StateT * v792) {
  int v793 = v792->timer;
  int v903 = v793 + 1;
  v792->timer = v903;
  int * v795 = v792->regs;
  int v796 = v795[12];
  int * v797 = v792->cache_tags;
  int v907 = (((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2;
  int v798 = v797[v907];
  int v908 = ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v799 = v797[v908];
  int v909 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2);
  int v800 = v797[v909];
  int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v801 = v797[v910];
  int v802 = v792->timer;
  int v911 = v802 + ((100 ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v792->timer = v911;
  int * v804 = v792->cache_vals;
  bool v912 = !(((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v897;
  if (v912) {
    int * v805 = v792->cache_age;
    int v914 = ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v806 = v805[v914];
    int v807 = v805[v907];
    int v915 = v807 + ((int)((unsigned int)(v807 - v806) >> 31));
    v805[v907] = v915;
    int * v809 = v792->cache_age;
    int v810 = v809[v908];
    int v917 = v810 + ((int)((unsigned int)(v810 - v806) >> 31));
    v809[v908] = v917;
    int * v812 = v792->cache_age;
    v812[v914] = 0;
    v897 = v914;
  } else {
    int * v815 = v792->cache_age;
    int v921 = (((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2;
    int v816 = v815[v921];
    int * v817 = v792->cache_tags;
    int v818 = v817[v921];
    int v819 = v815[v908];
    int v820 = v817[v908];
    bool v923 = !(((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v874;
    if (v923) {
      int * v821 = v792->cache_age;
      int v925 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v822 = v821[v925];
      int v823 = v821[v909];
      int v926 = v823 + ((int)((unsigned int)(v823 - v822) >> 31));
      v821[v909] = v926;
      int * v825 = v792->cache_age;
      int v826 = v825[v910];
      int v928 = v826 + ((int)((unsigned int)(v826 - v822) >> 31));
      v825[v910] = v928;
      int * v828 = v792->cache_age;
      v828[v925] = 0;
      v874 = v925;
    } else {
      int * v831 = v792->cache_age;
      int v932 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2);
      int v832 = v831[v932];
      int * v833 = v792->cache_tags;
      int v834 = v833[v932];
      int v835 = v831[v910];
      int v836 = v833[v910];
      int * v837 = v792->cache_dirty;
      int v935 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v838 = v837[v935];
      bool v936 = !(v838 == 0);
      if (v936) {
        int * v839 = v792->cache_tags;
        int v840 = v839[v935];
        int * v841 = v792->cache_vals;
        int v939 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v842 = v841[v939];
        int v940 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v843 = v841[v940];
        int * v844 = v792->mem;
        int v942 = v840 * 2;
        v844[v942] = v842;
        int * v846 = v792->mem;
        int v945 = (v840 * 2) + 1;
        v846[v945] = v843;
        ;
      } else {
        ;
      }
      int * v851 = v792->mem;
      int v950 = ((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) * 2;
      int v852 = v851[v950];
      int v951 = (((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) * 2) + 1;
      int v853 = v851[v951];
      int * v854 = v792->cache_vals;
      int v953 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v854[v953] = v852;
      int * v856 = v792->cache_vals;
      int v956 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v832 + ((~(((v834 ^ -1) | (-(v834 ^ -1))) >> 31)) & 2)) - (v835 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v856[v956] = v853;
      int * v858 = v792->cache_tags;
      int v959 = (int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1);
      v858[v935] = v959;
      int * v860 = v792->cache_dirty;
      v860[v935] = 0;
      int * v862 = v792->cache_age;
      v862[v935] = 1;
      int * v864 = v792->cache_age;
      int v865 = v864[v935];
      int v866 = v864[v909];
      int v965 = v866 + ((int)((unsigned int)(v866 - v865) >> 31));
      v864[v909] = v965;
      int * v868 = v792->cache_age;
      int v869 = v868[v910];
      int v967 = v869 + ((int)((unsigned int)(v869 - v865) >> 31));
      v868[v910] = v967;
      int * v871 = v792->cache_age;
      v871[v935] = 0;
      v874 = v935;
    }
    int * v875 = v792->cache_vals;
    int v970 = v874 * 2;
    int v876 = v875[v970];
    int v971 = (v874 * 2) + 1;
    int v877 = v875[v971];
    int v972 = (((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v816 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v875[v972] = v876;
    int * v879 = v792->cache_vals;
    int v975 = ((((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v816 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v879[v975] = v877;
    int * v881 = v792->cache_tags;
    int v978 = ((((int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v816 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v979 = (int)((unsigned int)((int)((unsigned int)(v796 + 68) >> 2)) >> 1);
    v881[v978] = v979;
    int * v883 = v792->cache_dirty;
    v883[v978] = 0;
    int * v885 = v792->cache_age;
    v885[v978] = 1;
    int * v887 = v792->cache_age;
    int v888 = v887[v978];
    int v889 = v887[v907];
    int v985 = v889 + ((int)((unsigned int)(v889 - v888) >> 31));
    v887[v907] = v985;
    int * v891 = v792->cache_age;
    int v892 = v891[v908];
    int v987 = v892 + ((int)((unsigned int)(v892 - v888) >> 31));
    v891[v908] = v987;
    int * v894 = v792->cache_age;
    v894[v978] = 0;
    v897 = v978;
  }
  int v990 = (v897 * 2) + (((int)((unsigned int)(v796 + 68) >> 2)) & 1);
  int v898 = v804[v990];
  int * v899 = v792->regs;
  v899[11] = v898;
  struct StateT * v901 = slot_16(v792);
  return v901;
}

struct StateT * slot_18(struct StateT * v500) {
  int v501 = v500->timer;
  int v504 = v501 + 1;
  v500->timer = v504;
  return v500;
}

struct StateT * slot_9(struct StateT * v519) {
  int v520 = v519->timer;
  int v526 = v520 + 1;
  v519->timer = v526;
  int * v522 = v519->regs;
  v522[11] = 0;
  struct StateT * v524 = slot_10(v519);
  return v524;
}

struct StateT * slot_11(struct StateT * v546) {
  int v547 = v546->timer;
  int v553 = v547 + 1;
  v546->timer = v553;
  int * v549 = v546->regs;
  v549[12] = 0;
  struct StateT * v551 = slot_12(v546);
  return v551;
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