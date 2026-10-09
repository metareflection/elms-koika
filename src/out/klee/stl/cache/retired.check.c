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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v578);
struct StateT * slot_6(struct StateT * v366);
struct StateT * slot_5(struct StateT * v358);
struct StateT * slot_4(struct StateT * v350);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_7(struct StateT * v374);
struct StateT * slot_3(struct StateT * v342);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[6];
  int v28 = v21 + 80;
  v20[6] = v28;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_8(struct StateT * v578) {
  int v579 = v578->timer;
  int v688 = v579 + 1;
  v578->timer = v688;
  int * v581 = v578->regs;
  int v582 = v581[11];
  int * v583 = v578->cache_tags;
  int v692 = (((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2;
  int v584 = v583[v692];
  int v693 = ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2) + 1;
  int v585 = v583[v693];
  int v694 = 4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2);
  int v586 = v583[v694];
  int v695 = (4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v587 = v583[v695];
  int v588 = v578->timer;
  int v696 = v588 + ((100 ^ (((~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) | (~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) | (~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) | (~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31))) & 104)))));
  v578->timer = v696;
  int * v590 = v578->cache_vals;
  bool v697 = !(((~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) | (~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31))) == 0);
  int v683;
  if (v697) {
    int * v591 = v578->cache_age;
    int v699 = ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2) + ((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) & 1);
    int v592 = v591[v699];
    int v593 = v591[v692];
    int v700 = v593 + ((int)((unsigned int)(v593 - v592) >> 31));
    v591[v692] = v700;
    int * v595 = v578->cache_age;
    int v596 = v595[v693];
    int v702 = v596 + ((int)((unsigned int)(v596 - v592) >> 31));
    v595[v693] = v702;
    int * v598 = v578->cache_age;
    v598[v699] = 0;
    v683 = v699;
  } else {
    int * v601 = v578->cache_age;
    int v706 = (((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2;
    int v602 = v601[v706];
    int * v603 = v578->cache_tags;
    int v604 = v603[v706];
    int v605 = v601[v693];
    int v606 = v603[v693];
    bool v708 = !(((~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) | (~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31))) == 0);
    int v660;
    if (v708) {
      int * v607 = v578->cache_age;
      int v710 = (4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + ((~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1))))) >> 31)) & 1);
      int v608 = v607[v710];
      int v609 = v607[v694];
      int v711 = v609 + ((int)((unsigned int)(v609 - v608) >> 31));
      v607[v694] = v711;
      int * v611 = v578->cache_age;
      int v612 = v611[v695];
      int v713 = v612 + ((int)((unsigned int)(v612 - v608) >> 31));
      v611[v695] = v713;
      int * v614 = v578->cache_age;
      v614[v710] = 0;
      v660 = v710;
    } else {
      int * v617 = v578->cache_age;
      int v717 = 4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2);
      int v618 = v617[v717];
      int * v619 = v578->cache_tags;
      int v620 = v619[v717];
      int v621 = v617[v695];
      int v622 = v619[v695];
      int * v623 = v578->cache_dirty;
      int v720 = (4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v624 = v623[v720];
      bool v721 = !(v624 == 0);
      if (v721) {
        int * v625 = v578->cache_tags;
        int v626 = v625[v720];
        int * v627 = v578->cache_vals;
        int v724 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v628 = v627[v724];
        int v725 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v629 = v627[v725];
        int * v630 = v578->mem;
        int v727 = v626 * 2;
        v630[v727] = v628;
        int * v632 = v578->mem;
        int v730 = (v626 * 2) + 1;
        v632[v730] = v629;
        ;
      } else {
        ;
      }
      int * v637 = v578->mem;
      int v735 = ((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) * 2;
      int v638 = v637[v735];
      int v736 = (((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) * 2) + 1;
      int v639 = v637[v736];
      int * v640 = v578->cache_vals;
      int v738 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v640[v738] = v638;
      int * v642 = v578->cache_vals;
      int v741 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 3) * 2)) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v642[v741] = v639;
      int * v644 = v578->cache_tags;
      int v744 = (int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1);
      v644[v720] = v744;
      int * v646 = v578->cache_dirty;
      v646[v720] = 0;
      int * v648 = v578->cache_age;
      v648[v720] = 1;
      int * v650 = v578->cache_age;
      int v651 = v650[v720];
      int v652 = v650[v694];
      int v750 = v652 + ((int)((unsigned int)(v652 - v651) >> 31));
      v650[v694] = v750;
      int * v654 = v578->cache_age;
      int v655 = v654[v695];
      int v752 = v655 + ((int)((unsigned int)(v655 - v651) >> 31));
      v654[v695] = v752;
      int * v657 = v578->cache_age;
      v657[v720] = 0;
      v660 = v720;
    }
    int * v661 = v578->cache_vals;
    int v755 = v660 * 2;
    int v662 = v661[v755];
    int v756 = (v660 * 2) + 1;
    int v663 = v661[v756];
    int v757 = (((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v605 + ((~(((v606 ^ -1) | (-(v606 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v661[v757] = v662;
    int * v665 = v578->cache_vals;
    int v760 = ((((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v605 + ((~(((v606 ^ -1) | (-(v606 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v665[v760] = v663;
    int * v667 = v578->cache_tags;
    int v763 = ((((int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1)) & 1) * 2) + ((((v602 + ((~(((v604 ^ -1) | (-(v604 ^ -1))) >> 31)) & 2)) - (v605 + ((~(((v606 ^ -1) | (-(v606 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v764 = (int)((unsigned int)((int)((unsigned int)v582 >> 2)) >> 1);
    v667[v763] = v764;
    int * v669 = v578->cache_dirty;
    v669[v763] = 0;
    int * v671 = v578->cache_age;
    v671[v763] = 1;
    int * v673 = v578->cache_age;
    int v674 = v673[v763];
    int v675 = v673[v692];
    int v770 = v675 + ((int)((unsigned int)(v675 - v674) >> 31));
    v673[v692] = v770;
    int * v677 = v578->cache_age;
    int v678 = v677[v693];
    int v772 = v678 + ((int)((unsigned int)(v678 - v674) >> 31));
    v677[v693] = v772;
    int * v680 = v578->cache_age;
    v680[v763] = 0;
    v683 = v763;
  }
  int v775 = (v683 * 2) + (((int)((unsigned int)v582 >> 2)) & 1);
  int v684 = v590[v775];
  int * v685 = v578->regs;
  v685[12] = v684;
  return v578;
}

struct StateT * slot_6(struct StateT * v366) {
  int v367 = v366->timer;
  int v371 = v367 + 1;
  v366->timer = v371;
  struct StateT * v369 = slot_7(v366);
  return v369;
}

struct StateT * slot_5(struct StateT * v358) {
  int v359 = v358->timer;
  int v363 = v359 + 1;
  v358->timer = v363;
  struct StateT * v361 = slot_6(v358);
  return v361;
}

struct StateT * slot_4(struct StateT * v350) {
  int v351 = v350->timer;
  int v355 = v351 + 1;
  v350->timer = v355;
  struct StateT * v353 = slot_5(v350);
  return v353;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v201 = v32 + 1;
  v31->timer = v201;
  int * v34 = v31->regs;
  int v35 = v34[6];
  int * v36 = v31->cache_tags;
  int v205 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
  int v37 = v36[v205];
  int v206 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + 1;
  int v38 = v36[v206];
  int v207 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
  int v39 = v36[v207];
  int v208 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v40 = v36[v208];
  int v41 = v31->timer;
  int v209 = v41 + ((100 ^ (((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)))));
  v31->timer = v209;
  bool v210 = !(((~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v135;
  if (v210) {
    int * v43 = v31->cache_age;
    int v212 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v44 = v43[v212];
    int v45 = v43[v205];
    int v213 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
    v43[v205] = v213;
    int * v47 = v31->cache_age;
    int v48 = v47[v206];
    int v215 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
    v47[v206] = v215;
    int * v50 = v31->cache_age;
    v50[v212] = 0;
    v135 = v212;
  } else {
    int * v53 = v31->cache_age;
    int v219 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
    int v54 = v53[v219];
    int * v55 = v31->cache_tags;
    int v56 = v55[v219];
    int v57 = v53[v206];
    int v58 = v55[v206];
    bool v221 = !(((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
    int v112;
    if (v221) {
      int * v59 = v31->cache_age;
      int v223 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
      int v60 = v59[v223];
      int v61 = v59[v207];
      int v224 = v61 + ((int)((unsigned int)(v61 - v60) >> 31));
      v59[v207] = v224;
      int * v63 = v31->cache_age;
      int v64 = v63[v208];
      int v226 = v64 + ((int)((unsigned int)(v64 - v60) >> 31));
      v63[v208] = v226;
      int * v66 = v31->cache_age;
      v66[v223] = 0;
      v112 = v223;
    } else {
      int * v69 = v31->cache_age;
      int v230 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
      int v70 = v69[v230];
      int * v71 = v31->cache_tags;
      int v72 = v71[v230];
      int v73 = v69[v208];
      int v74 = v71[v208];
      int * v75 = v31->cache_dirty;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v76 = v75[v233];
      bool v234 = !(v76 == 0);
      if (v234) {
        int * v77 = v31->cache_tags;
        int v78 = v77[v233];
        int * v79 = v31->cache_vals;
        int v237 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v80 = v79[v237];
        int v238 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v81 = v79[v238];
        int * v82 = v31->mem;
        int v240 = v78 * 2;
        v82[v240] = v80;
        int * v84 = v31->mem;
        int v243 = (v78 * 2) + 1;
        v84[v243] = v81;
        ;
      } else {
        ;
      }
      int * v89 = v31->mem;
      int v248 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
      int v90 = v89[v248];
      int v249 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
      int v91 = v89[v249];
      int * v92 = v31->cache_vals;
      int v251 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v251] = v90;
      int * v94 = v31->cache_vals;
      int v254 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v254] = v91;
      int * v96 = v31->cache_tags;
      int v257 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
      v96[v233] = v257;
      int * v98 = v31->cache_dirty;
      v98[v233] = 0;
      int * v100 = v31->cache_age;
      v100[v233] = 1;
      int * v102 = v31->cache_age;
      int v103 = v102[v233];
      int v104 = v102[v207];
      int v263 = v104 + ((int)((unsigned int)(v104 - v103) >> 31));
      v102[v207] = v263;
      int * v106 = v31->cache_age;
      int v107 = v106[v208];
      int v265 = v107 + ((int)((unsigned int)(v107 - v103) >> 31));
      v106[v208] = v265;
      int * v109 = v31->cache_age;
      v109[v233] = 0;
      v112 = v233;
    }
    int * v113 = v31->cache_vals;
    int v268 = v112 * 2;
    int v114 = v113[v268];
    int v269 = (v112 * 2) + 1;
    int v115 = v113[v269];
    int v270 = (((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v113[v270] = v114;
    int * v117 = v31->cache_vals;
    int v273 = ((((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v117[v273] = v115;
    int * v119 = v31->cache_tags;
    int v276 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v277 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v119[v276] = v277;
    int * v121 = v31->cache_dirty;
    v121[v276] = 0;
    int * v123 = v31->cache_age;
    v123[v276] = 1;
    int * v125 = v31->cache_age;
    int v126 = v125[v276];
    int v127 = v125[v205];
    int v283 = v127 + ((int)((unsigned int)(v127 - v126) >> 31));
    v125[v205] = v283;
    int * v129 = v31->cache_age;
    int v130 = v129[v206];
    int v285 = v130 + ((int)((unsigned int)(v130 - v126) >> 31));
    v129[v206] = v285;
    int * v132 = v31->cache_age;
    v132[v276] = 0;
    v135 = v276;
  }
  int * v136 = v31->cache_vals;
  int v288 = (v135 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v136[v288] = 0;
  int * v138 = v31->cache_tags;
  int v139 = v138[v207];
  int v140 = v138[v208];
  bool v291 = !(((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v194;
  if (v291) {
    int * v141 = v31->cache_age;
    int v293 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v142 = v141[v293];
    int v143 = v141[v207];
    int v294 = v143 + ((int)((unsigned int)(v143 - v142) >> 31));
    v141[v207] = v294;
    int * v145 = v31->cache_age;
    int v146 = v145[v208];
    int v296 = v146 + ((int)((unsigned int)(v146 - v142) >> 31));
    v145[v208] = v296;
    int * v148 = v31->cache_age;
    v148[v293] = 0;
    v194 = v293;
  } else {
    int * v151 = v31->cache_age;
    int v299 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
    int v152 = v151[v299];
    int * v153 = v31->cache_tags;
    int v154 = v153[v299];
    int v155 = v151[v208];
    int v156 = v153[v208];
    int * v157 = v31->cache_dirty;
    int v302 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v158 = v157[v302];
    bool v303 = !(v158 == 0);
    if (v303) {
      int * v159 = v31->cache_tags;
      int v160 = v159[v302];
      int * v161 = v31->cache_vals;
      int v306 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v162 = v161[v306];
      int v307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v163 = v161[v307];
      int * v164 = v31->mem;
      int v309 = v160 * 2;
      v164[v309] = v162;
      int * v166 = v31->mem;
      int v312 = (v160 * 2) + 1;
      v166[v312] = v163;
      ;
    } else {
      ;
    }
    int * v171 = v31->mem;
    int v317 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
    int v172 = v171[v317];
    int v318 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
    int v173 = v171[v318];
    int * v174 = v31->cache_vals;
    int v320 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v174[v320] = v172;
    int * v176 = v31->cache_vals;
    int v323 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v176[v323] = v173;
    int * v178 = v31->cache_tags;
    int v326 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v178[v302] = v326;
    int * v180 = v31->cache_dirty;
    v180[v302] = 0;
    int * v182 = v31->cache_age;
    v182[v302] = 1;
    int * v184 = v31->cache_age;
    int v185 = v184[v302];
    int v186 = v184[v207];
    int v331 = v186 + ((int)((unsigned int)(v186 - v185) >> 31));
    v184[v207] = v331;
    int * v188 = v31->cache_age;
    int v189 = v188[v208];
    int v333 = v189 + ((int)((unsigned int)(v189 - v185) >> 31));
    v188[v208] = v333;
    int * v191 = v31->cache_age;
    v191[v302] = 0;
    v194 = v302;
  }
  int * v195 = v31->cache_vals;
  int v336 = (v194 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v195[v336] = 0;
  int * v197 = v31->cache_dirty;
  v197[v194] = 1;
  struct StateT * v199 = slot_3(v31);
  return v199;
}

struct StateT * slot_7(struct StateT * v374) {
  int v375 = v374->timer;
  int v485 = v375 + 1;
  v374->timer = v485;
  int * v377 = v374->regs;
  int v378 = v377[6];
  int * v379 = v374->cache_tags;
  int v489 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2;
  int v380 = v379[v489];
  int v490 = ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + 1;
  int v381 = v379[v490];
  int v491 = 4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2);
  int v382 = v379[v491];
  int v492 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v383 = v379[v492];
  int v384 = v374->timer;
  int v493 = v384 + ((100 ^ (((~(((v382 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v382 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v380 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v380 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v382 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v382 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) & 104)))));
  v374->timer = v493;
  int * v386 = v374->cache_vals;
  bool v494 = !(((~(((v380 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v380 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) == 0);
  int v479;
  if (v494) {
    int * v387 = v374->cache_age;
    int v496 = ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) & 1);
    int v388 = v387[v496];
    int v389 = v387[v489];
    int v497 = v389 + ((int)((unsigned int)(v389 - v388) >> 31));
    v387[v489] = v497;
    int * v391 = v374->cache_age;
    int v392 = v391[v490];
    int v499 = v392 + ((int)((unsigned int)(v392 - v388) >> 31));
    v391[v490] = v499;
    int * v394 = v374->cache_age;
    v394[v496] = 0;
    v479 = v496;
  } else {
    int * v397 = v374->cache_age;
    int v503 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2;
    int v398 = v397[v503];
    int * v399 = v374->cache_tags;
    int v400 = v399[v503];
    int v401 = v397[v490];
    int v402 = v399[v490];
    bool v505 = !(((~(((v382 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v382 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) == 0);
    int v456;
    if (v505) {
      int * v403 = v374->cache_age;
      int v507 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) & 1);
      int v404 = v403[v507];
      int v405 = v403[v491];
      int v508 = v405 + ((int)((unsigned int)(v405 - v404) >> 31));
      v403[v491] = v508;
      int * v407 = v374->cache_age;
      int v408 = v407[v492];
      int v510 = v408 + ((int)((unsigned int)(v408 - v404) >> 31));
      v407[v492] = v510;
      int * v410 = v374->cache_age;
      v410[v507] = 0;
      v456 = v507;
    } else {
      int * v413 = v374->cache_age;
      int v514 = 4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2);
      int v414 = v413[v514];
      int * v415 = v374->cache_tags;
      int v416 = v415[v514];
      int v417 = v413[v492];
      int v418 = v415[v492];
      int * v419 = v374->cache_dirty;
      int v517 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v420 = v419[v517];
      bool v518 = !(v420 == 0);
      if (v518) {
        int * v421 = v374->cache_tags;
        int v422 = v421[v517];
        int * v423 = v374->cache_vals;
        int v521 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v424 = v423[v521];
        int v522 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v425 = v423[v522];
        int * v426 = v374->mem;
        int v524 = v422 * 2;
        v426[v524] = v424;
        int * v428 = v374->mem;
        int v527 = (v422 * 2) + 1;
        v428[v527] = v425;
        ;
      } else {
        ;
      }
      int * v433 = v374->mem;
      int v532 = ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) * 2;
      int v434 = v433[v532];
      int v533 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) * 2) + 1;
      int v435 = v433[v533];
      int * v436 = v374->cache_vals;
      int v535 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v436[v535] = v434;
      int * v438 = v374->cache_vals;
      int v538 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v414 + ((~(((v416 ^ -1) | (-(v416 ^ -1))) >> 31)) & 2)) - (v417 + ((~(((v418 ^ -1) | (-(v418 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v438[v538] = v435;
      int * v440 = v374->cache_tags;
      int v541 = (int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1);
      v440[v517] = v541;
      int * v442 = v374->cache_dirty;
      v442[v517] = 0;
      int * v444 = v374->cache_age;
      v444[v517] = 1;
      int * v446 = v374->cache_age;
      int v447 = v446[v517];
      int v448 = v446[v491];
      int v547 = v448 + ((int)((unsigned int)(v448 - v447) >> 31));
      v446[v491] = v547;
      int * v450 = v374->cache_age;
      int v451 = v450[v492];
      int v549 = v451 + ((int)((unsigned int)(v451 - v447) >> 31));
      v450[v492] = v549;
      int * v453 = v374->cache_age;
      v453[v517] = 0;
      v456 = v517;
    }
    int * v457 = v374->cache_vals;
    int v552 = v456 * 2;
    int v458 = v457[v552];
    int v553 = (v456 * 2) + 1;
    int v459 = v457[v553];
    int v554 = (((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v457[v554] = v458;
    int * v461 = v374->cache_vals;
    int v557 = ((((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v461[v557] = v459;
    int * v463 = v374->cache_tags;
    int v560 = ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((((v398 + ((~(((v400 ^ -1) | (-(v400 ^ -1))) >> 31)) & 2)) - (v401 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v561 = (int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1);
    v463[v560] = v561;
    int * v465 = v374->cache_dirty;
    v465[v560] = 0;
    int * v467 = v374->cache_age;
    v467[v560] = 1;
    int * v469 = v374->cache_age;
    int v470 = v469[v560];
    int v471 = v469[v489];
    int v567 = v471 + ((int)((unsigned int)(v471 - v470) >> 31));
    v469[v489] = v567;
    int * v473 = v374->cache_age;
    int v474 = v473[v490];
    int v569 = v474 + ((int)((unsigned int)(v474 - v470) >> 31));
    v473[v490] = v569;
    int * v476 = v374->cache_age;
    v476[v560] = 0;
    v479 = v560;
  }
  int v572 = (v479 * 2) + (((int)((unsigned int)v378 >> 2)) & 1);
  int v480 = v386[v572];
  int * v481 = v374->regs;
  v481[11] = v480;
  struct StateT * v483 = slot_8(v374);
  return v483;
}

struct StateT * slot_3(struct StateT * v342) {
  int v343 = v342->timer;
  int v347 = v343 + 1;
  v342->timer = v347;
  struct StateT * v345 = slot_4(v342);
  return v345;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[6] = v14;
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
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}