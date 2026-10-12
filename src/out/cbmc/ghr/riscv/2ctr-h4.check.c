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

struct StateG * snippet(struct StateG * v0);
struct StateG * slot_1(struct StateG * v22);
struct StateG * slot_8(struct StateG * v702);
struct StateG * slot_6(struct StateG * v477);
struct StateG * slot_5(struct StateG * v463);
struct StateG * slot_4(struct StateG * v259);
struct StateG * slot_9(struct StateG * v903);
struct StateG * slot_2(struct StateG * v48);
struct StateG * slot_7(struct StateG * v491);
struct StateG * slot_0(struct StateG * v2);
struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_1(struct StateG * v22) {
  int * v23 = v22->regs;
  int v24 = v23[10];
  bool v38 = v24 == 0;
  struct StateG * v34;
  if (v38) {
    int * v25 = v22->pht;
    v25[0] = 1;
    v34 = v22;
  } else {
    int * v28 = v22->pht;
    v28[0] = 0;
    int v30 = v22->timer;
    int v44 = v30 + 15;
    v22->timer = v44;
    struct StateG * v32 = slot_4(v22);
    v34 = v32;
  }
  return v34;
}

struct StateG * slot_8(struct StateG * v702) {
  int v703 = v702->timer;
  int v812 = v703 + 1;
  v702->timer = v812;
  int * v705 = v702->regs;
  int v706 = v705[11];
  int * v707 = v702->cache_tags;
  int v816 = (((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2;
  int v708 = v707[v816];
  int v817 = ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v709 = v707[v817];
  int v818 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2);
  int v710 = v707[v818];
  int v819 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v711 = v707[v819];
  int v712 = v702->timer;
  int v820 = v712 + ((100 ^ (((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v708 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v708 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v702->timer = v820;
  int * v714 = v702->cache_vals;
  bool v821 = !(((~(((v708 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v708 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v807;
  if (v821) {
    int * v715 = v702->cache_age;
    int v823 = ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v709 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v709 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v716 = v715[v823];
    int v717 = v715[v816];
    int v824 = v717 + ((int)((unsigned int)(v717 - v716) >> 31));
    v715[v816] = v824;
    int * v719 = v702->cache_age;
    int v720 = v719[v817];
    int v826 = v720 + ((int)((unsigned int)(v720 - v716) >> 31));
    v719[v817] = v826;
    int * v722 = v702->cache_age;
    v722[v823] = 0;
    v807 = v823;
  } else {
    int * v725 = v702->cache_age;
    int v830 = (((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2;
    int v726 = v725[v830];
    int * v727 = v702->cache_tags;
    int v728 = v727[v830];
    int v729 = v725[v817];
    int v730 = v727[v817];
    bool v832 = !(((~(((v710 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v710 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v784;
    if (v832) {
      int * v731 = v702->cache_age;
      int v834 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))) | (-(v711 ^ ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v732 = v731[v834];
      int v733 = v731[v818];
      int v835 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
      v731[v818] = v835;
      int * v735 = v702->cache_age;
      int v736 = v735[v819];
      int v837 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
      v735[v819] = v837;
      int * v738 = v702->cache_age;
      v738[v834] = 0;
      v784 = v834;
    } else {
      int * v741 = v702->cache_age;
      int v841 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2);
      int v742 = v741[v841];
      int * v743 = v702->cache_tags;
      int v744 = v743[v841];
      int v745 = v741[v819];
      int v746 = v743[v819];
      int * v747 = v702->cache_dirty;
      int v844 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v748 = v747[v844];
      bool v845 = !(v748 == 0);
      if (v845) {
        int * v749 = v702->cache_tags;
        int v750 = v749[v844];
        int * v751 = v702->cache_vals;
        int v848 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v752 = v751[v848];
        int v849 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v753 = v751[v849];
        int * v754 = v702->mem;
        int v851 = v750 * 2;
        v754[v851] = v752;
        int * v756 = v702->mem;
        int v854 = (v750 * 2) + 1;
        v756[v854] = v753;
        ;
      } else {
        ;
      }
      int * v761 = v702->mem;
      int v859 = ((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) * 2;
      int v762 = v761[v859];
      int v860 = (((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) * 2) + 1;
      int v763 = v761[v860];
      int * v764 = v702->cache_vals;
      int v862 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v764[v862] = v762;
      int * v766 = v702->cache_vals;
      int v865 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v742 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2)) - (v745 + ((~(((v746 ^ -1) | (-(v746 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v766[v865] = v763;
      int * v768 = v702->cache_tags;
      int v868 = (int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1);
      v768[v844] = v868;
      int * v770 = v702->cache_dirty;
      v770[v844] = 0;
      int * v772 = v702->cache_age;
      v772[v844] = 1;
      int * v774 = v702->cache_age;
      int v775 = v774[v844];
      int v776 = v774[v818];
      int v874 = v776 + ((int)((unsigned int)(v776 - v775) >> 31));
      v774[v818] = v874;
      int * v778 = v702->cache_age;
      int v779 = v778[v819];
      int v876 = v779 + ((int)((unsigned int)(v779 - v775) >> 31));
      v778[v819] = v876;
      int * v781 = v702->cache_age;
      v781[v844] = 0;
      v784 = v844;
    }
    int * v785 = v702->cache_vals;
    int v879 = v784 * 2;
    int v786 = v785[v879];
    int v880 = (v784 * 2) + 1;
    int v787 = v785[v880];
    int v881 = (((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v726 + ((~(((v728 ^ -1) | (-(v728 ^ -1))) >> 31)) & 2)) - (v729 + ((~(((v730 ^ -1) | (-(v730 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v785[v881] = v786;
    int * v789 = v702->cache_vals;
    int v884 = ((((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v726 + ((~(((v728 ^ -1) | (-(v728 ^ -1))) >> 31)) & 2)) - (v729 + ((~(((v730 ^ -1) | (-(v730 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v789[v884] = v787;
    int * v791 = v702->cache_tags;
    int v887 = ((((int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v726 + ((~(((v728 ^ -1) | (-(v728 ^ -1))) >> 31)) & 2)) - (v729 + ((~(((v730 ^ -1) | (-(v730 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v888 = (int)((unsigned int)((int)((unsigned int)(v706 + 16) >> 2)) >> 1);
    v791[v887] = v888;
    int * v793 = v702->cache_dirty;
    v793[v887] = 0;
    int * v795 = v702->cache_age;
    v795[v887] = 1;
    int * v797 = v702->cache_age;
    int v798 = v797[v887];
    int v799 = v797[v816];
    int v894 = v799 + ((int)((unsigned int)(v799 - v798) >> 31));
    v797[v816] = v894;
    int * v801 = v702->cache_age;
    int v802 = v801[v817];
    int v896 = v802 + ((int)((unsigned int)(v802 - v798) >> 31));
    v801[v817] = v896;
    int * v804 = v702->cache_age;
    v804[v887] = 0;
    v807 = v887;
  }
  int v899 = (v807 * 2) + (((int)((unsigned int)(v706 + 16) >> 2)) & 1);
  int v808 = v714[v899];
  int * v809 = v702->regs;
  v809[12] = v808;
  return v702;
}

struct StateG * slot_6(struct StateG * v477) {
  int v478 = v477->timer;
  int v485 = v478 + 1;
  v477->timer = v485;
  int * v480 = v477->regs;
  int v481 = v480[11];
  int v488 = v481 << 2;
  v480[11] = v488;
  struct StateG * v483 = slot_8(v477);
  return v483;
}

struct StateG * slot_5(struct StateG * v463) {
  int v464 = v463->timer;
  int v471 = v464 + 1;
  v463->timer = v471;
  int * v466 = v463->regs;
  int v467 = v466[11];
  int v474 = v467 << 2;
  v466[11] = v474;
  struct StateG * v469 = slot_7(v463);
  return v469;
}

struct StateG * slot_4(struct StateG * v259) {
  int v260 = v259->timer;
  int v370 = v260 + 1;
  v259->timer = v370;
  int * v262 = v259->regs;
  int v263 = v262[10];
  int * v264 = v259->cache_tags;
  int v374 = (((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2;
  int v265 = v264[v374];
  int v375 = ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2) + 1;
  int v266 = v264[v375];
  int v376 = 4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2);
  int v267 = v264[v376];
  int v377 = (4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v268 = v264[v377];
  int v269 = v259->timer;
  int v378 = v269 + ((100 ^ (((~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) | (~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) | (~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) | (~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31))) & 104)))));
  v259->timer = v378;
  int * v271 = v259->cache_vals;
  bool v379 = !(((~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) | (~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31))) == 0);
  int v364;
  if (v379) {
    int * v272 = v259->cache_age;
    int v381 = ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2) + ((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) & 1);
    int v273 = v272[v381];
    int v274 = v272[v374];
    int v382 = v274 + ((int)((unsigned int)(v274 - v273) >> 31));
    v272[v374] = v382;
    int * v276 = v259->cache_age;
    int v277 = v276[v375];
    int v384 = v277 + ((int)((unsigned int)(v277 - v273) >> 31));
    v276[v375] = v384;
    int * v279 = v259->cache_age;
    v279[v381] = 0;
    v364 = v381;
  } else {
    int * v282 = v259->cache_age;
    int v388 = (((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2;
    int v283 = v282[v388];
    int * v284 = v259->cache_tags;
    int v285 = v284[v388];
    int v286 = v282[v375];
    int v287 = v284[v375];
    bool v390 = !(((~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) | (~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31))) == 0);
    int v341;
    if (v390) {
      int * v288 = v259->cache_age;
      int v392 = (4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + ((~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1))))) >> 31)) & 1);
      int v289 = v288[v392];
      int v290 = v288[v376];
      int v393 = v290 + ((int)((unsigned int)(v290 - v289) >> 31));
      v288[v376] = v393;
      int * v292 = v259->cache_age;
      int v293 = v292[v377];
      int v395 = v293 + ((int)((unsigned int)(v293 - v289) >> 31));
      v292[v377] = v395;
      int * v295 = v259->cache_age;
      v295[v392] = 0;
      v341 = v392;
    } else {
      int * v298 = v259->cache_age;
      int v399 = 4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2);
      int v299 = v298[v399];
      int * v300 = v259->cache_tags;
      int v301 = v300[v399];
      int v302 = v298[v377];
      int v303 = v300[v377];
      int * v304 = v259->cache_dirty;
      int v402 = (4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v305 = v304[v402];
      bool v403 = !(v305 == 0);
      if (v403) {
        int * v306 = v259->cache_tags;
        int v307 = v306[v402];
        int * v308 = v259->cache_vals;
        int v406 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v309 = v308[v406];
        int v407 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v310 = v308[v407];
        int * v311 = v259->mem;
        int v409 = v307 * 2;
        v311[v409] = v309;
        int * v313 = v259->mem;
        int v412 = (v307 * 2) + 1;
        v313[v412] = v310;
        ;
      } else {
        ;
      }
      int * v318 = v259->mem;
      int v417 = ((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) * 2;
      int v319 = v318[v417];
      int v418 = (((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) * 2) + 1;
      int v320 = v318[v418];
      int * v321 = v259->cache_vals;
      int v420 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v321[v420] = v319;
      int * v323 = v259->cache_vals;
      int v423 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 3) * 2)) + ((((v299 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2)) - (v302 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v323[v423] = v320;
      int * v325 = v259->cache_tags;
      int v426 = (int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1);
      v325[v402] = v426;
      int * v327 = v259->cache_dirty;
      v327[v402] = 0;
      int * v329 = v259->cache_age;
      v329[v402] = 1;
      int * v331 = v259->cache_age;
      int v332 = v331[v402];
      int v333 = v331[v376];
      int v432 = v333 + ((int)((unsigned int)(v333 - v332) >> 31));
      v331[v376] = v432;
      int * v335 = v259->cache_age;
      int v336 = v335[v377];
      int v434 = v336 + ((int)((unsigned int)(v336 - v332) >> 31));
      v335[v377] = v434;
      int * v338 = v259->cache_age;
      v338[v402] = 0;
      v341 = v402;
    }
    int * v342 = v259->cache_vals;
    int v437 = v341 * 2;
    int v343 = v342[v437];
    int v438 = (v341 * 2) + 1;
    int v344 = v342[v438];
    int v439 = (((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v342[v439] = v343;
    int * v346 = v259->cache_vals;
    int v442 = ((((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v346[v442] = v344;
    int * v348 = v259->cache_tags;
    int v445 = ((((int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1)) & 1) * 2) + ((((v283 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2)) - (v286 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v446 = (int)((unsigned int)((int)((unsigned int)v263 >> 2)) >> 1);
    v348[v445] = v446;
    int * v350 = v259->cache_dirty;
    v350[v445] = 0;
    int * v352 = v259->cache_age;
    v352[v445] = 1;
    int * v354 = v259->cache_age;
    int v355 = v354[v445];
    int v356 = v354[v374];
    int v452 = v356 + ((int)((unsigned int)(v356 - v355) >> 31));
    v354[v374] = v452;
    int * v358 = v259->cache_age;
    int v359 = v358[v375];
    int v454 = v359 + ((int)((unsigned int)(v359 - v355) >> 31));
    v358[v375] = v454;
    int * v361 = v259->cache_age;
    v361[v445] = 0;
    v364 = v445;
  }
  int v457 = (v364 * 2) + (((int)((unsigned int)v263 >> 2)) & 1);
  int v365 = v271[v457];
  int * v366 = v259->regs;
  v366[11] = v365;
  struct StateG * v368 = slot_6(v259);
  return v368;
}

struct StateG * slot_9(struct StateG * v903) {
  int * v904 = v903->regs;
  int v905 = v904[10];
  bool v926 = v905 == 0;
  struct StateG * v922;
  if (v926) {
    int * v906 = v903->pht;
    v906[0] = 1;
    int v908 = v903->timer;
    int v930 = v908 + 15;
    v903->timer = v930;
    int * v910 = v903->saved_regs;
    int v911 = v910[11];
    int * v912 = v903->regs;
    v912[11] = v911;
    int * v914 = v903->saved_regs;
    int v915 = v914[12];
    int * v916 = v903->regs;
    v916[12] = v915;
    v922 = v903;
  } else {
    int * v919 = v903->pht;
    v919[0] = 0;
    v922 = v903;
  }
  return v922;
}

struct StateG * slot_2(struct StateG * v48) {
  int * v49 = v48->saved_regs;
  int * v50 = v48->regs;
  int v51 = v50[11];
  v49[11] = v51;
  int v53 = v48->timer;
  int v167 = v53 + 1;
  v48->timer = v167;
  int * v55 = v48->regs;
  int v56 = v55[10];
  int * v57 = v48->cache_tags;
  int v171 = (((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2;
  int v58 = v57[v171];
  int v172 = ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + 1;
  int v59 = v57[v172];
  int v173 = 4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2);
  int v60 = v57[v173];
  int v174 = (4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v61 = v57[v174];
  int v62 = v48->timer;
  int v175 = v62 + ((100 ^ (((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) & 104)))));
  v48->timer = v175;
  int * v64 = v48->cache_vals;
  bool v176 = !(((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) == 0);
  int v157;
  if (v176) {
    int * v65 = v48->cache_age;
    int v178 = ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((~(((v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v59 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) & 1);
    int v66 = v65[v178];
    int v67 = v65[v171];
    int v179 = v67 + ((int)((unsigned int)(v67 - v66) >> 31));
    v65[v171] = v179;
    int * v69 = v48->cache_age;
    int v70 = v69[v172];
    int v181 = v70 + ((int)((unsigned int)(v70 - v66) >> 31));
    v69[v172] = v181;
    int * v72 = v48->cache_age;
    v72[v178] = 0;
    v157 = v178;
  } else {
    int * v75 = v48->cache_age;
    int v185 = (((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2;
    int v76 = v75[v185];
    int * v77 = v48->cache_tags;
    int v78 = v77[v185];
    int v79 = v75[v172];
    int v80 = v77[v172];
    bool v187 = !(((~(((v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v60 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) | (~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31))) == 0);
    int v134;
    if (v187) {
      int * v81 = v48->cache_age;
      int v189 = (4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((~(((v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))) | (-(v61 ^ ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1))))) >> 31)) & 1);
      int v82 = v81[v189];
      int v83 = v81[v173];
      int v190 = v83 + ((int)((unsigned int)(v83 - v82) >> 31));
      v81[v173] = v190;
      int * v85 = v48->cache_age;
      int v86 = v85[v174];
      int v192 = v86 + ((int)((unsigned int)(v86 - v82) >> 31));
      v85[v174] = v192;
      int * v88 = v48->cache_age;
      v88[v189] = 0;
      v134 = v189;
    } else {
      int * v91 = v48->cache_age;
      int v196 = 4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2);
      int v92 = v91[v196];
      int * v93 = v48->cache_tags;
      int v94 = v93[v196];
      int v95 = v91[v174];
      int v96 = v93[v174];
      int * v97 = v48->cache_dirty;
      int v199 = (4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v98 = v97[v199];
      bool v200 = !(v98 == 0);
      if (v200) {
        int * v99 = v48->cache_tags;
        int v100 = v99[v199];
        int * v101 = v48->cache_vals;
        int v203 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v102 = v101[v203];
        int v204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v103 = v101[v204];
        int * v104 = v48->mem;
        int v206 = v100 * 2;
        v104[v206] = v102;
        int * v106 = v48->mem;
        int v209 = (v100 * 2) + 1;
        v106[v209] = v103;
        ;
      } else {
        ;
      }
      int * v111 = v48->mem;
      int v214 = ((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) * 2;
      int v112 = v111[v214];
      int v215 = (((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) * 2) + 1;
      int v113 = v111[v215];
      int * v114 = v48->cache_vals;
      int v217 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v114[v217] = v112;
      int * v116 = v48->cache_vals;
      int v220 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 3) * 2)) + ((((v92 + ((~(((v94 ^ -1) | (-(v94 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v96 ^ -1) | (-(v96 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v116[v220] = v113;
      int * v118 = v48->cache_tags;
      int v223 = (int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1);
      v118[v199] = v223;
      int * v120 = v48->cache_dirty;
      v120[v199] = 0;
      int * v122 = v48->cache_age;
      v122[v199] = 1;
      int * v124 = v48->cache_age;
      int v125 = v124[v199];
      int v126 = v124[v173];
      int v229 = v126 + ((int)((unsigned int)(v126 - v125) >> 31));
      v124[v173] = v229;
      int * v128 = v48->cache_age;
      int v129 = v128[v174];
      int v231 = v129 + ((int)((unsigned int)(v129 - v125) >> 31));
      v128[v174] = v231;
      int * v131 = v48->cache_age;
      v131[v199] = 0;
      v134 = v199;
    }
    int * v135 = v48->cache_vals;
    int v234 = v134 * 2;
    int v136 = v135[v234];
    int v235 = (v134 * 2) + 1;
    int v137 = v135[v235];
    int v236 = (((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((((v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v135[v236] = v136;
    int * v139 = v48->cache_vals;
    int v239 = ((((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((((v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v139[v239] = v137;
    int * v141 = v48->cache_tags;
    int v242 = ((((int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1)) & 1) * 2) + ((((v76 + ((~(((v78 ^ -1) | (-(v78 ^ -1))) >> 31)) & 2)) - (v79 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v243 = (int)((unsigned int)((int)((unsigned int)v56 >> 2)) >> 1);
    v141[v242] = v243;
    int * v143 = v48->cache_dirty;
    v143[v242] = 0;
    int * v145 = v48->cache_age;
    v145[v242] = 1;
    int * v147 = v48->cache_age;
    int v148 = v147[v242];
    int v149 = v147[v171];
    int v249 = v149 + ((int)((unsigned int)(v149 - v148) >> 31));
    v147[v171] = v249;
    int * v151 = v48->cache_age;
    int v152 = v151[v172];
    int v251 = v152 + ((int)((unsigned int)(v152 - v148) >> 31));
    v151[v172] = v251;
    int * v154 = v48->cache_age;
    v154[v242] = 0;
    v157 = v242;
  }
  int v254 = (v157 * 2) + (((int)((unsigned int)v56 >> 2)) & 1);
  int v158 = v64[v254];
  int * v159 = v48->regs;
  v159[11] = v158;
  struct StateG * v161 = slot_5(v48);
  return v161;
}

struct StateG * slot_7(struct StateG * v491) {
  int * v492 = v491->saved_regs;
  int * v493 = v491->regs;
  int v494 = v493[12];
  v492[12] = v494;
  int v496 = v491->timer;
  int v610 = v496 + 1;
  v491->timer = v610;
  int * v498 = v491->regs;
  int v499 = v498[11];
  int * v500 = v491->cache_tags;
  int v614 = (((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2;
  int v501 = v500[v614];
  int v615 = ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v502 = v500[v615];
  int v616 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2);
  int v503 = v500[v616];
  int v617 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v504 = v500[v617];
  int v505 = v491->timer;
  int v618 = v505 + ((100 ^ (((~(((v503 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v503 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v501 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v501 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v502 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v502 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v503 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v503 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v491->timer = v618;
  int * v507 = v491->cache_vals;
  bool v619 = !(((~(((v501 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v501 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v502 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v502 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v600;
  if (v619) {
    int * v508 = v491->cache_age;
    int v621 = ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v502 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v502 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v509 = v508[v621];
    int v510 = v508[v614];
    int v622 = v510 + ((int)((unsigned int)(v510 - v509) >> 31));
    v508[v614] = v622;
    int * v512 = v491->cache_age;
    int v513 = v512[v615];
    int v624 = v513 + ((int)((unsigned int)(v513 - v509) >> 31));
    v512[v615] = v624;
    int * v515 = v491->cache_age;
    v515[v621] = 0;
    v600 = v621;
  } else {
    int * v518 = v491->cache_age;
    int v628 = (((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2;
    int v519 = v518[v628];
    int * v520 = v491->cache_tags;
    int v521 = v520[v628];
    int v522 = v518[v615];
    int v523 = v520[v615];
    bool v630 = !(((~(((v503 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v503 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v577;
    if (v630) {
      int * v524 = v491->cache_age;
      int v632 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))) | (-(v504 ^ ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v525 = v524[v632];
      int v526 = v524[v616];
      int v633 = v526 + ((int)((unsigned int)(v526 - v525) >> 31));
      v524[v616] = v633;
      int * v528 = v491->cache_age;
      int v529 = v528[v617];
      int v635 = v529 + ((int)((unsigned int)(v529 - v525) >> 31));
      v528[v617] = v635;
      int * v531 = v491->cache_age;
      v531[v632] = 0;
      v577 = v632;
    } else {
      int * v534 = v491->cache_age;
      int v639 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2);
      int v535 = v534[v639];
      int * v536 = v491->cache_tags;
      int v537 = v536[v639];
      int v538 = v534[v617];
      int v539 = v536[v617];
      int * v540 = v491->cache_dirty;
      int v642 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2)) - (v538 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v541 = v540[v642];
      bool v643 = !(v541 == 0);
      if (v643) {
        int * v542 = v491->cache_tags;
        int v543 = v542[v642];
        int * v544 = v491->cache_vals;
        int v646 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2)) - (v538 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v545 = v544[v646];
        int v647 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2)) - (v538 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v546 = v544[v647];
        int * v547 = v491->mem;
        int v649 = v543 * 2;
        v547[v649] = v545;
        int * v549 = v491->mem;
        int v652 = (v543 * 2) + 1;
        v549[v652] = v546;
        ;
      } else {
        ;
      }
      int * v554 = v491->mem;
      int v657 = ((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) * 2;
      int v555 = v554[v657];
      int v658 = (((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) * 2) + 1;
      int v556 = v554[v658];
      int * v557 = v491->cache_vals;
      int v660 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2)) - (v538 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v557[v660] = v555;
      int * v559 = v491->cache_vals;
      int v663 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v535 + ((~(((v537 ^ -1) | (-(v537 ^ -1))) >> 31)) & 2)) - (v538 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v559[v663] = v556;
      int * v561 = v491->cache_tags;
      int v666 = (int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1);
      v561[v642] = v666;
      int * v563 = v491->cache_dirty;
      v563[v642] = 0;
      int * v565 = v491->cache_age;
      v565[v642] = 1;
      int * v567 = v491->cache_age;
      int v568 = v567[v642];
      int v569 = v567[v616];
      int v672 = v569 + ((int)((unsigned int)(v569 - v568) >> 31));
      v567[v616] = v672;
      int * v571 = v491->cache_age;
      int v572 = v571[v617];
      int v674 = v572 + ((int)((unsigned int)(v572 - v568) >> 31));
      v571[v617] = v674;
      int * v574 = v491->cache_age;
      v574[v642] = 0;
      v577 = v642;
    }
    int * v578 = v491->cache_vals;
    int v677 = v577 * 2;
    int v579 = v578[v677];
    int v678 = (v577 * 2) + 1;
    int v580 = v578[v678];
    int v679 = (((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v522 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v578[v679] = v579;
    int * v582 = v491->cache_vals;
    int v682 = ((((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v522 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v582[v682] = v580;
    int * v584 = v491->cache_tags;
    int v685 = ((((int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v519 + ((~(((v521 ^ -1) | (-(v521 ^ -1))) >> 31)) & 2)) - (v522 + ((~(((v523 ^ -1) | (-(v523 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v686 = (int)((unsigned int)((int)((unsigned int)(v499 + 16) >> 2)) >> 1);
    v584[v685] = v686;
    int * v586 = v491->cache_dirty;
    v586[v685] = 0;
    int * v588 = v491->cache_age;
    v588[v685] = 1;
    int * v590 = v491->cache_age;
    int v591 = v590[v685];
    int v592 = v590[v614];
    int v692 = v592 + ((int)((unsigned int)(v592 - v591) >> 31));
    v590[v614] = v692;
    int * v594 = v491->cache_age;
    int v595 = v594[v615];
    int v694 = v595 + ((int)((unsigned int)(v595 - v591) >> 31));
    v594[v615] = v694;
    int * v597 = v491->cache_age;
    v597[v685] = 0;
    v600 = v685;
  }
  int v697 = (v600 * 2) + (((int)((unsigned int)(v499 + 16) >> 2)) & 1);
  int v601 = v507[v697];
  int * v602 = v491->regs;
  v602[12] = v601;
  struct StateG * v604 = slot_9(v491);
  return v604;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v13 = v3 + 1;
  v2->timer = v13;
  int * v5 = v2->pht;
  int v6 = v5[0];
  bool v16 = !(v6 == 0);
  struct StateG * v11;
  if (v16) {
    struct StateG * v7 = slot_1(v2);
    v11 = v7;
  } else {
    struct StateG * v9 = slot_2(v2);
    v11 = v9;
  }
  return v11;
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