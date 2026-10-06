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

struct StateT * slot_12(struct StateT * v732);
struct StateT * slot_6(struct StateT * v265);
struct StateT * slot_16(struct StateT * v791);
struct StateT * slot_5(struct StateT * v251);
struct StateT * slot_2(struct StateT * v206);
struct StateT * slot_7(struct StateT * v469);
struct StateT * slot_21(struct StateT * v1054);
struct StateT * slot_3(struct StateT * v222);
struct StateT * slot_10(struct StateT * v514);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1026);
struct StateT * slot_13(struct StateT * v748);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v763);
struct StateT * slot_17(struct StateT * v995);
struct StateT * slot_20(struct StateT * v1040);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v485);
struct StateT * slot_4(struct StateT * v237);
struct StateT * slot_15(struct StateT * v777);
struct StateT * slot_18(struct StateT * v1011);
struct StateT * slot_9(struct StateT * v500);
struct StateT * slot_22(struct StateT * v1258);
struct StateT * slot_11(struct StateT * v528);
struct StateT * slot_12(struct StateT * v732) {
  int v733 = v732->timer;
  int v741 = v733 + 1;
  v732->timer = v741;
  int * v735 = v732->regs;
  int v736 = v735[5];
  int v737 = v735[7];
  int v745 = v736 ^ v737;
  v735[5] = v745;
  struct StateT * v739 = slot_13(v732);
  return v739;
}

struct StateT * slot_6(struct StateT * v265) {
  int v266 = v265->timer;
  int v376 = v266 + 1;
  v265->timer = v376;
  int * v268 = v265->regs;
  int v269 = v268[6];
  int * v270 = v265->cache_tags;
  int v380 = (((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2;
  int v271 = v270[v380];
  int v381 = ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + 1;
  int v272 = v270[v381];
  int v382 = 4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2);
  int v273 = v270[v382];
  int v383 = (4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v274 = v270[v383];
  int v275 = v265->timer;
  int v384 = v275 + ((100 ^ (((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) & 104)))));
  v265->timer = v384;
  int * v277 = v265->cache_vals;
  bool v385 = !(((~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) == 0);
  int v370;
  if (v385) {
    int * v278 = v265->cache_age;
    int v387 = ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) & 1);
    int v279 = v278[v387];
    int v280 = v278[v380];
    int v388 = v280 + ((int)((unsigned int)(v280 - v279) >> 31));
    v278[v380] = v388;
    int * v282 = v265->cache_age;
    int v283 = v282[v381];
    int v390 = v283 + ((int)((unsigned int)(v283 - v279) >> 31));
    v282[v381] = v390;
    int * v285 = v265->cache_age;
    v285[v387] = 0;
    v370 = v387;
  } else {
    int * v288 = v265->cache_age;
    int v394 = (((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2;
    int v289 = v288[v394];
    int * v290 = v265->cache_tags;
    int v291 = v290[v394];
    int v292 = v288[v381];
    int v293 = v290[v381];
    bool v396 = !(((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) == 0);
    int v347;
    if (v396) {
      int * v294 = v265->cache_age;
      int v398 = (4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) & 1);
      int v295 = v294[v398];
      int v296 = v294[v382];
      int v399 = v296 + ((int)((unsigned int)(v296 - v295) >> 31));
      v294[v382] = v399;
      int * v298 = v265->cache_age;
      int v299 = v298[v383];
      int v401 = v299 + ((int)((unsigned int)(v299 - v295) >> 31));
      v298[v383] = v401;
      int * v301 = v265->cache_age;
      v301[v398] = 0;
      v347 = v398;
    } else {
      int * v304 = v265->cache_age;
      int v405 = 4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2);
      int v305 = v304[v405];
      int * v306 = v265->cache_tags;
      int v307 = v306[v405];
      int v308 = v304[v383];
      int v309 = v306[v383];
      int * v310 = v265->cache_dirty;
      int v408 = (4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v311 = v310[v408];
      bool v409 = !(v311 == 0);
      if (v409) {
        int * v312 = v265->cache_tags;
        int v313 = v312[v408];
        int * v314 = v265->cache_vals;
        int v412 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v315 = v314[v412];
        int v413 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316 = v314[v413];
        int * v317 = v265->mem;
        int v415 = v313 * 2;
        v317[v415] = v315;
        int * v319 = v265->mem;
        int v418 = (v313 * 2) + 1;
        v319[v418] = v316;
        ;
      } else {
        ;
      }
      int * v324 = v265->mem;
      int v423 = ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) * 2;
      int v325 = v324[v423];
      int v424 = (((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) * 2) + 1;
      int v326 = v324[v424];
      int * v327 = v265->cache_vals;
      int v426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v327[v426] = v325;
      int * v329 = v265->cache_vals;
      int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v329[v429] = v326;
      int * v331 = v265->cache_tags;
      int v432 = (int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1);
      v331[v408] = v432;
      int * v333 = v265->cache_dirty;
      v333[v408] = 0;
      int * v335 = v265->cache_age;
      v335[v408] = 1;
      int * v337 = v265->cache_age;
      int v338 = v337[v408];
      int v339 = v337[v382];
      int v438 = v339 + ((int)((unsigned int)(v339 - v338) >> 31));
      v337[v382] = v438;
      int * v341 = v265->cache_age;
      int v342 = v341[v383];
      int v440 = v342 + ((int)((unsigned int)(v342 - v338) >> 31));
      v341[v383] = v440;
      int * v344 = v265->cache_age;
      v344[v408] = 0;
      v347 = v408;
    }
    int * v348 = v265->cache_vals;
    int v443 = v347 * 2;
    int v349 = v348[v443];
    int v444 = (v347 * 2) + 1;
    int v350 = v348[v444];
    int v445 = (((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((((v289 + ((~(((v291 ^ -1) | (-(v291 ^ -1))) >> 31)) & 2)) - (v292 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v348[v445] = v349;
    int * v352 = v265->cache_vals;
    int v448 = ((((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((((v289 + ((~(((v291 ^ -1) | (-(v291 ^ -1))) >> 31)) & 2)) - (v292 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v352[v448] = v350;
    int * v354 = v265->cache_tags;
    int v451 = ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((((v289 + ((~(((v291 ^ -1) | (-(v291 ^ -1))) >> 31)) & 2)) - (v292 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v452 = (int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1);
    v354[v451] = v452;
    int * v356 = v265->cache_dirty;
    v356[v451] = 0;
    int * v358 = v265->cache_age;
    v358[v451] = 1;
    int * v360 = v265->cache_age;
    int v361 = v360[v451];
    int v362 = v360[v380];
    int v458 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
    v360[v380] = v458;
    int * v364 = v265->cache_age;
    int v365 = v364[v381];
    int v460 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
    v364[v381] = v460;
    int * v367 = v265->cache_age;
    v367[v451] = 0;
    v370 = v451;
  }
  int v463 = (v370 * 2) + (((int)((unsigned int)v269 >> 2)) & 1);
  int v371 = v277[v463];
  int * v372 = v265->regs;
  v372[7] = v371;
  struct StateT * v374 = slot_7(v265);
  return v374;
}

struct StateT * slot_16(struct StateT * v791) {
  int v792 = v791->timer;
  int v902 = v792 + 1;
  v791->timer = v902;
  int * v794 = v791->regs;
  int v795 = v794[6];
  int * v796 = v791->cache_tags;
  int v906 = (((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2;
  int v797 = v796[v906];
  int v907 = ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + 1;
  int v798 = v796[v907];
  int v908 = 4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2);
  int v799 = v796[v908];
  int v909 = (4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v800 = v796[v909];
  int v801 = v791->timer;
  int v910 = v801 + ((100 ^ (((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) & 104)))));
  v791->timer = v910;
  int * v803 = v791->cache_vals;
  bool v911 = !(((~(((v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v797 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) == 0);
  int v896;
  if (v911) {
    int * v804 = v791->cache_age;
    int v913 = ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) & 1);
    int v805 = v804[v913];
    int v806 = v804[v906];
    int v914 = v806 + ((int)((unsigned int)(v806 - v805) >> 31));
    v804[v906] = v914;
    int * v808 = v791->cache_age;
    int v809 = v808[v907];
    int v916 = v809 + ((int)((unsigned int)(v809 - v805) >> 31));
    v808[v907] = v916;
    int * v811 = v791->cache_age;
    v811[v913] = 0;
    v896 = v913;
  } else {
    int * v814 = v791->cache_age;
    int v920 = (((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2;
    int v815 = v814[v920];
    int * v816 = v791->cache_tags;
    int v817 = v816[v920];
    int v818 = v814[v907];
    int v819 = v816[v907];
    bool v922 = !(((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) | (~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31))) == 0);
    int v873;
    if (v922) {
      int * v820 = v791->cache_age;
      int v924 = (4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1))))) >> 31)) & 1);
      int v821 = v820[v924];
      int v822 = v820[v908];
      int v925 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
      v820[v908] = v925;
      int * v824 = v791->cache_age;
      int v825 = v824[v909];
      int v927 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
      v824[v909] = v927;
      int * v827 = v791->cache_age;
      v827[v924] = 0;
      v873 = v924;
    } else {
      int * v830 = v791->cache_age;
      int v931 = 4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2);
      int v831 = v830[v931];
      int * v832 = v791->cache_tags;
      int v833 = v832[v931];
      int v834 = v830[v909];
      int v835 = v832[v909];
      int * v836 = v791->cache_dirty;
      int v934 = (4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v837 = v836[v934];
      bool v935 = !(v837 == 0);
      if (v935) {
        int * v838 = v791->cache_tags;
        int v839 = v838[v934];
        int * v840 = v791->cache_vals;
        int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v841 = v840[v938];
        int v939 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v842 = v840[v939];
        int * v843 = v791->mem;
        int v941 = v839 * 2;
        v843[v941] = v841;
        int * v845 = v791->mem;
        int v944 = (v839 * 2) + 1;
        v845[v944] = v842;
        ;
      } else {
        ;
      }
      int * v850 = v791->mem;
      int v949 = ((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) * 2;
      int v851 = v850[v949];
      int v950 = (((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) * 2) + 1;
      int v852 = v850[v950];
      int * v853 = v791->cache_vals;
      int v952 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v853[v952] = v851;
      int * v855 = v791->cache_vals;
      int v955 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 3) * 2)) + ((((v831 + ((~(((v833 ^ -1) | (-(v833 ^ -1))) >> 31)) & 2)) - (v834 + ((~(((v835 ^ -1) | (-(v835 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v855[v955] = v852;
      int * v857 = v791->cache_tags;
      int v958 = (int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1);
      v857[v934] = v958;
      int * v859 = v791->cache_dirty;
      v859[v934] = 0;
      int * v861 = v791->cache_age;
      v861[v934] = 1;
      int * v863 = v791->cache_age;
      int v864 = v863[v934];
      int v865 = v863[v908];
      int v964 = v865 + ((int)((unsigned int)(v865 - v864) >> 31));
      v863[v908] = v964;
      int * v867 = v791->cache_age;
      int v868 = v867[v909];
      int v966 = v868 + ((int)((unsigned int)(v868 - v864) >> 31));
      v867[v909] = v966;
      int * v870 = v791->cache_age;
      v870[v934] = 0;
      v873 = v934;
    }
    int * v874 = v791->cache_vals;
    int v969 = v873 * 2;
    int v875 = v874[v969];
    int v970 = (v873 * 2) + 1;
    int v876 = v874[v970];
    int v971 = (((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v874[v971] = v875;
    int * v878 = v791->cache_vals;
    int v974 = ((((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v878[v974] = v876;
    int * v880 = v791->cache_tags;
    int v977 = ((((int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1)) & 1) * 2) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v978 = (int)((unsigned int)((int)((unsigned int)v795 >> 2)) >> 1);
    v880[v977] = v978;
    int * v882 = v791->cache_dirty;
    v882[v977] = 0;
    int * v884 = v791->cache_age;
    v884[v977] = 1;
    int * v886 = v791->cache_age;
    int v887 = v886[v977];
    int v888 = v886[v906];
    int v984 = v888 + ((int)((unsigned int)(v888 - v887) >> 31));
    v886[v906] = v984;
    int * v890 = v791->cache_age;
    int v891 = v890[v907];
    int v986 = v891 + ((int)((unsigned int)(v891 - v887) >> 31));
    v890[v907] = v986;
    int * v893 = v791->cache_age;
    v893[v977] = 0;
    v896 = v977;
  }
  int v989 = (v896 * 2) + (((int)((unsigned int)v795 >> 2)) & 1);
  int v897 = v803[v989];
  int * v898 = v791->regs;
  v898[7] = v897;
  struct StateT * v900 = slot_17(v791);
  return v900;
}

struct StateT * slot_5(struct StateT * v251) {
  int v252 = v251->timer;
  int v259 = v252 + 1;
  v251->timer = v259;
  int * v254 = v251->regs;
  int v255 = v254[6];
  int v262 = v255 << 2;
  v254[6] = v262;
  struct StateT * v257 = slot_6(v251);
  return v257;
}

struct StateT * slot_2(struct StateT * v206) {
  int v207 = v206->timer;
  int v215 = v207 + 1;
  v206->timer = v215;
  int * v209 = v206->regs;
  int v210 = v209[5];
  int v211 = v209[9];
  int v219 = v210 ^ v211;
  v209[5] = v219;
  struct StateT * v213 = slot_3(v206);
  return v213;
}

struct StateT * slot_7(struct StateT * v469) {
  int v470 = v469->timer;
  int v478 = v470 + 1;
  v469->timer = v478;
  int * v472 = v469->regs;
  int v473 = v472[5];
  int v474 = v472[7];
  int v482 = v473 ^ v474;
  v472[5] = v482;
  struct StateT * v476 = slot_8(v469);
  return v476;
}

struct StateT * slot_21(struct StateT * v1054) {
  int v1055 = v1054->timer;
  int v1165 = v1055 + 1;
  v1054->timer = v1165;
  int * v1057 = v1054->regs;
  int v1058 = v1057[6];
  int * v1059 = v1054->cache_tags;
  int v1169 = (((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2;
  int v1060 = v1059[v1169];
  int v1170 = ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1061 = v1059[v1170];
  int v1171 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2);
  int v1062 = v1059[v1171];
  int v1172 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1063 = v1059[v1172];
  int v1064 = v1054->timer;
  int v1173 = v1064 + ((100 ^ (((~(((v1062 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1062 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) | (~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1062 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1062 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) | (~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1054->timer = v1173;
  int * v1066 = v1054->cache_vals;
  bool v1174 = !(((~(((v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31))) == 0);
  int v1159;
  if (v1174) {
    int * v1067 = v1054->cache_age;
    int v1176 = ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2) + ((~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) & 1);
    int v1068 = v1067[v1176];
    int v1069 = v1067[v1169];
    int v1177 = v1069 + ((int)((unsigned int)(v1069 - v1068) >> 31));
    v1067[v1169] = v1177;
    int * v1071 = v1054->cache_age;
    int v1072 = v1071[v1170];
    int v1179 = v1072 + ((int)((unsigned int)(v1072 - v1068) >> 31));
    v1071[v1170] = v1179;
    int * v1074 = v1054->cache_age;
    v1074[v1176] = 0;
    v1159 = v1176;
  } else {
    int * v1077 = v1054->cache_age;
    int v1183 = (((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2;
    int v1078 = v1077[v1183];
    int * v1079 = v1054->cache_tags;
    int v1080 = v1079[v1183];
    int v1081 = v1077[v1170];
    int v1082 = v1079[v1170];
    bool v1185 = !(((~(((v1062 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1062 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) | (~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31))) == 0);
    int v1136;
    if (v1185) {
      int * v1083 = v1054->cache_age;
      int v1187 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))) | (-(v1063 ^ ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1))))) >> 31)) & 1);
      int v1084 = v1083[v1187];
      int v1085 = v1083[v1171];
      int v1188 = v1085 + ((int)((unsigned int)(v1085 - v1084) >> 31));
      v1083[v1171] = v1188;
      int * v1087 = v1054->cache_age;
      int v1088 = v1087[v1172];
      int v1190 = v1088 + ((int)((unsigned int)(v1088 - v1084) >> 31));
      v1087[v1172] = v1190;
      int * v1090 = v1054->cache_age;
      v1090[v1187] = 0;
      v1136 = v1187;
    } else {
      int * v1093 = v1054->cache_age;
      int v1194 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2);
      int v1094 = v1093[v1194];
      int * v1095 = v1054->cache_tags;
      int v1096 = v1095[v1194];
      int v1097 = v1093[v1172];
      int v1098 = v1095[v1172];
      int * v1099 = v1054->cache_dirty;
      int v1197 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1100 = v1099[v1197];
      bool v1198 = !(v1100 == 0);
      if (v1198) {
        int * v1101 = v1054->cache_tags;
        int v1102 = v1101[v1197];
        int * v1103 = v1054->cache_vals;
        int v1201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1104 = v1103[v1201];
        int v1202 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1105 = v1103[v1202];
        int * v1106 = v1054->mem;
        int v1204 = v1102 * 2;
        v1106[v1204] = v1104;
        int * v1108 = v1054->mem;
        int v1207 = (v1102 * 2) + 1;
        v1108[v1207] = v1105;
        ;
      } else {
        ;
      }
      int * v1113 = v1054->mem;
      int v1212 = ((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) * 2;
      int v1114 = v1113[v1212];
      int v1213 = (((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) * 2) + 1;
      int v1115 = v1113[v1213];
      int * v1116 = v1054->cache_vals;
      int v1215 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1116[v1215] = v1114;
      int * v1118 = v1054->cache_vals;
      int v1218 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 3) * 2)) + ((((v1094 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1098 ^ -1) | (-(v1098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1118[v1218] = v1115;
      int * v1120 = v1054->cache_tags;
      int v1221 = (int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1);
      v1120[v1197] = v1221;
      int * v1122 = v1054->cache_dirty;
      v1122[v1197] = 0;
      int * v1124 = v1054->cache_age;
      v1124[v1197] = 1;
      int * v1126 = v1054->cache_age;
      int v1127 = v1126[v1197];
      int v1128 = v1126[v1171];
      int v1227 = v1128 + ((int)((unsigned int)(v1128 - v1127) >> 31));
      v1126[v1171] = v1227;
      int * v1130 = v1054->cache_age;
      int v1131 = v1130[v1172];
      int v1229 = v1131 + ((int)((unsigned int)(v1131 - v1127) >> 31));
      v1130[v1172] = v1229;
      int * v1133 = v1054->cache_age;
      v1133[v1197] = 0;
      v1136 = v1197;
    }
    int * v1137 = v1054->cache_vals;
    int v1232 = v1136 * 2;
    int v1138 = v1137[v1232];
    int v1233 = (v1136 * 2) + 1;
    int v1139 = v1137[v1233];
    int v1234 = (((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2) + ((((v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2)) - (v1081 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1137[v1234] = v1138;
    int * v1141 = v1054->cache_vals;
    int v1237 = ((((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2) + ((((v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2)) - (v1081 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1141[v1237] = v1139;
    int * v1143 = v1054->cache_tags;
    int v1240 = ((((int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1)) & 1) * 2) + ((((v1078 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2)) - (v1081 + ((~(((v1082 ^ -1) | (-(v1082 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1241 = (int)((unsigned int)((int)((unsigned int)v1058 >> 2)) >> 1);
    v1143[v1240] = v1241;
    int * v1145 = v1054->cache_dirty;
    v1145[v1240] = 0;
    int * v1147 = v1054->cache_age;
    v1147[v1240] = 1;
    int * v1149 = v1054->cache_age;
    int v1150 = v1149[v1240];
    int v1151 = v1149[v1169];
    int v1247 = v1151 + ((int)((unsigned int)(v1151 - v1150) >> 31));
    v1149[v1169] = v1247;
    int * v1153 = v1054->cache_age;
    int v1154 = v1153[v1170];
    int v1249 = v1154 + ((int)((unsigned int)(v1154 - v1150) >> 31));
    v1153[v1170] = v1249;
    int * v1156 = v1054->cache_age;
    v1156[v1240] = 0;
    v1159 = v1240;
  }
  int v1252 = (v1159 * 2) + (((int)((unsigned int)v1058 >> 2)) & 1);
  int v1160 = v1066[v1252];
  int * v1161 = v1054->regs;
  v1161[7] = v1160;
  struct StateT * v1163 = slot_22(v1054);
  return v1163;
}

struct StateT * slot_3(struct StateT * v222) {
  int v223 = v222->timer;
  int v230 = v223 + 1;
  v222->timer = v230;
  int * v225 = v222->regs;
  int v226 = v225[10];
  v225[6] = v226;
  struct StateT * v228 = slot_4(v222);
  return v228;
}

struct StateT * slot_10(struct StateT * v514) {
  int v515 = v514->timer;
  int v522 = v515 + 1;
  v514->timer = v522;
  int * v517 = v514->regs;
  int v518 = v517[6];
  int v525 = v518 << 2;
  v517[6] = v525;
  struct StateT * v520 = slot_11(v514);
  return v520;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v124 = v16 + 1;
  v15->timer = v124;
  int * v18 = v15->cache_tags;
  int v19 = v18[0];
  int v20 = v18[1];
  int v21 = v18[8];
  int v22 = v18[9];
  int v23 = v15->timer;
  int v130 = v23 + ((100 ^ (((~(((v21 ^ 10) | (-(v21 ^ 10))) >> 31)) | (~(((v22 ^ 10) | (-(v22 ^ 10))) >> 31))) & 104)) ^ (((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v21 ^ 10) | (-(v21 ^ 10))) >> 31)) | (~(((v22 ^ 10) | (-(v22 ^ 10))) >> 31))) & 104)))));
  v15->timer = v130;
  int * v25 = v15->cache_vals;
  bool v131 = !(((~(((v19 ^ 10) | (-(v19 ^ 10))) >> 31)) | (~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31))) == 0);
  int v118;
  if (v131) {
    int * v26 = v15->cache_age;
    int v133 = (~(((v20 ^ 10) | (-(v20 ^ 10))) >> 31)) & 1;
    int v27 = v26[v133];
    int v28 = v26[0];
    int v134 = v28 + ((int)((unsigned int)(v28 - v27) >> 31));
    v26[0] = v134;
    int * v30 = v15->cache_age;
    int v31 = v30[1];
    int v136 = v31 + ((int)((unsigned int)(v31 - v27) >> 31));
    v30[1] = v136;
    int * v33 = v15->cache_age;
    v33[v133] = 0;
    v118 = v133;
  } else {
    int * v36 = v15->cache_age;
    int v37 = v36[0];
    int * v38 = v15->cache_tags;
    int v39 = v38[0];
    int v40 = v36[1];
    int v41 = v38[1];
    bool v140 = !(((~(((v21 ^ 10) | (-(v21 ^ 10))) >> 31)) | (~(((v22 ^ 10) | (-(v22 ^ 10))) >> 31))) == 0);
    int v95;
    if (v140) {
      int * v42 = v15->cache_age;
      int v142 = 8 + ((~(((v22 ^ 10) | (-(v22 ^ 10))) >> 31)) & 1);
      int v43 = v42[v142];
      int v44 = v42[8];
      int v143 = v44 + ((int)((unsigned int)(v44 - v43) >> 31));
      v42[8] = v143;
      int * v46 = v15->cache_age;
      int v47 = v46[9];
      int v145 = v47 + ((int)((unsigned int)(v47 - v43) >> 31));
      v46[9] = v145;
      int * v49 = v15->cache_age;
      v49[v142] = 0;
      v95 = v142;
    } else {
      int * v52 = v15->cache_age;
      int v53 = v52[8];
      int * v54 = v15->cache_tags;
      int v55 = v54[8];
      int v56 = v52[9];
      int v57 = v54[9];
      int * v58 = v15->cache_dirty;
      int v150 = 8 + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v59 = v58[v150];
      bool v151 = !(v59 == 0);
      if (v151) {
        int * v60 = v15->cache_tags;
        int v61 = v60[v150];
        int * v62 = v15->cache_vals;
        int v154 = (8 + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63 = v62[v154];
        int v155 = ((8 + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v64 = v62[v155];
        int * v65 = v15->mem;
        int v157 = v61 * 2;
        v65[v157] = v63;
        int * v67 = v15->mem;
        int v160 = (v61 * 2) + 1;
        v67[v160] = v64;
        ;
      } else {
        ;
      }
      int * v72 = v15->mem;
      int v73 = v72[20];
      int v74 = v72[21];
      int * v75 = v15->cache_vals;
      int v168 = (8 + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v75[v168] = v73;
      int * v77 = v15->cache_vals;
      int v171 = ((8 + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v56 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v77[v171] = v74;
      int * v79 = v15->cache_tags;
      v79[v150] = 10;
      int * v81 = v15->cache_dirty;
      v81[v150] = 0;
      int * v83 = v15->cache_age;
      v83[v150] = 1;
      int * v85 = v15->cache_age;
      int v86 = v85[v150];
      int v87 = v85[8];
      int v178 = v87 + ((int)((unsigned int)(v87 - v86) >> 31));
      v85[8] = v178;
      int * v89 = v15->cache_age;
      int v90 = v89[9];
      int v180 = v90 + ((int)((unsigned int)(v90 - v86) >> 31));
      v89[9] = v180;
      int * v92 = v15->cache_age;
      v92[v150] = 0;
      v95 = v150;
    }
    int * v96 = v15->cache_vals;
    int v183 = v95 * 2;
    int v97 = v96[v183];
    int v184 = (v95 * 2) + 1;
    int v98 = v96[v184];
    int v185 = ((((v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v96[v185] = v97;
    int * v100 = v15->cache_vals;
    int v188 = (((((v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v100[v188] = v98;
    int * v102 = v15->cache_tags;
    int v191 = (((v37 + ((~(((v39 ^ -1) | (-(v39 ^ -1))) >> 31)) & 2)) - (v40 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v102[v191] = 10;
    int * v104 = v15->cache_dirty;
    v104[v191] = 0;
    int * v106 = v15->cache_age;
    v106[v191] = 1;
    int * v108 = v15->cache_age;
    int v109 = v108[v191];
    int v110 = v108[0];
    int v196 = v110 + ((int)((unsigned int)(v110 - v109) >> 31));
    v108[0] = v196;
    int * v112 = v15->cache_age;
    int v113 = v112[1];
    int v198 = v113 + ((int)((unsigned int)(v113 - v109) >> 31));
    v112[1] = v198;
    int * v115 = v15->cache_age;
    v115[v191] = 0;
    v118 = v191;
  }
  int v201 = v118 * 2;
  int v119 = v25[v201];
  int * v120 = v15->regs;
  v120[9] = v119;
  struct StateT * v122 = slot_2(v15);
  return v122;
}

struct StateT * slot_19(struct StateT * v1026) {
  int v1027 = v1026->timer;
  int v1034 = v1027 + 1;
  v1026->timer = v1034;
  int * v1029 = v1026->regs;
  int v1030 = v1029[6];
  int v1037 = v1030 & 63;
  v1029[6] = v1037;
  struct StateT * v1032 = slot_20(v1026);
  return v1032;
}

struct StateT * slot_13(struct StateT * v748) {
  int v749 = v748->timer;
  int v756 = v749 + 1;
  v748->timer = v756;
  int * v751 = v748->regs;
  int v752 = v751[10];
  int v760 = (int)((unsigned int)v752 >> 16);
  v751[6] = v760;
  struct StateT * v754 = slot_14(v748);
  return v754;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[5] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v763) {
  int v764 = v763->timer;
  int v771 = v764 + 1;
  v763->timer = v771;
  int * v766 = v763->regs;
  int v767 = v766[6];
  int v774 = v767 & 63;
  v766[6] = v774;
  struct StateT * v769 = slot_15(v763);
  return v769;
}

struct StateT * slot_17(struct StateT * v995) {
  int v996 = v995->timer;
  int v1004 = v996 + 1;
  v995->timer = v1004;
  int * v998 = v995->regs;
  int v999 = v998[5];
  int v1000 = v998[7];
  int v1008 = v999 ^ v1000;
  v998[5] = v1008;
  struct StateT * v1002 = slot_18(v995);
  return v1002;
}

struct StateT * slot_20(struct StateT * v1040) {
  int v1041 = v1040->timer;
  int v1048 = v1041 + 1;
  v1040->timer = v1048;
  int * v1043 = v1040->regs;
  int v1044 = v1043[6];
  int v1051 = v1044 << 2;
  v1043[6] = v1051;
  struct StateT * v1046 = slot_21(v1040);
  return v1046;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v485) {
  int v486 = v485->timer;
  int v493 = v486 + 1;
  v485->timer = v493;
  int * v488 = v485->regs;
  int v489 = v488[10];
  int v497 = (int)((unsigned int)v489 >> 8);
  v488[6] = v497;
  struct StateT * v491 = slot_9(v485);
  return v491;
}

struct StateT * slot_4(struct StateT * v237) {
  int v238 = v237->timer;
  int v245 = v238 + 1;
  v237->timer = v245;
  int * v240 = v237->regs;
  int v241 = v240[6];
  int v248 = v241 & 63;
  v240[6] = v248;
  struct StateT * v243 = slot_5(v237);
  return v243;
}

struct StateT * slot_15(struct StateT * v777) {
  int v778 = v777->timer;
  int v785 = v778 + 1;
  v777->timer = v785;
  int * v780 = v777->regs;
  int v781 = v780[6];
  int v788 = v781 << 2;
  v780[6] = v788;
  struct StateT * v783 = slot_16(v777);
  return v783;
}

struct StateT * slot_18(struct StateT * v1011) {
  int v1012 = v1011->timer;
  int v1019 = v1012 + 1;
  v1011->timer = v1019;
  int * v1014 = v1011->regs;
  int v1015 = v1014[10];
  int v1023 = (int)((unsigned int)v1015 >> 24);
  v1014[6] = v1023;
  struct StateT * v1017 = slot_19(v1011);
  return v1017;
}

struct StateT * slot_9(struct StateT * v500) {
  int v501 = v500->timer;
  int v508 = v501 + 1;
  v500->timer = v508;
  int * v503 = v500->regs;
  int v504 = v503[6];
  int v511 = v504 & 63;
  v503[6] = v511;
  struct StateT * v506 = slot_10(v500);
  return v506;
}

struct StateT * slot_22(struct StateT * v1258) {
  int v1259 = v1258->timer;
  int v1266 = v1259 + 1;
  v1258->timer = v1266;
  int * v1261 = v1258->regs;
  int v1262 = v1261[5];
  int v1263 = v1261[7];
  int v1270 = v1262 ^ v1263;
  v1261[5] = v1270;
  return v1258;
}

struct StateT * slot_11(struct StateT * v528) {
  int v529 = v528->timer;
  int v639 = v529 + 1;
  v528->timer = v639;
  int * v531 = v528->regs;
  int v532 = v531[6];
  int * v533 = v528->cache_tags;
  int v643 = (((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2;
  int v534 = v533[v643];
  int v644 = ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2) + 1;
  int v535 = v533[v644];
  int v645 = 4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2);
  int v536 = v533[v645];
  int v646 = (4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v537 = v533[v646];
  int v538 = v528->timer;
  int v647 = v538 + ((100 ^ (((~(((v536 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v536 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) | (~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) | (~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v536 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v536 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) | (~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31))) & 104)))));
  v528->timer = v647;
  int * v540 = v528->cache_vals;
  bool v648 = !(((~(((v534 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v534 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) | (~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31))) == 0);
  int v633;
  if (v648) {
    int * v541 = v528->cache_age;
    int v650 = ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2) + ((~(((v535 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v535 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) & 1);
    int v542 = v541[v650];
    int v543 = v541[v643];
    int v651 = v543 + ((int)((unsigned int)(v543 - v542) >> 31));
    v541[v643] = v651;
    int * v545 = v528->cache_age;
    int v546 = v545[v644];
    int v653 = v546 + ((int)((unsigned int)(v546 - v542) >> 31));
    v545[v644] = v653;
    int * v548 = v528->cache_age;
    v548[v650] = 0;
    v633 = v650;
  } else {
    int * v551 = v528->cache_age;
    int v657 = (((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2;
    int v552 = v551[v657];
    int * v553 = v528->cache_tags;
    int v554 = v553[v657];
    int v555 = v551[v644];
    int v556 = v553[v644];
    bool v659 = !(((~(((v536 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v536 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) | (~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31))) == 0);
    int v610;
    if (v659) {
      int * v557 = v528->cache_age;
      int v661 = (4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + ((~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1))))) >> 31)) & 1);
      int v558 = v557[v661];
      int v559 = v557[v645];
      int v662 = v559 + ((int)((unsigned int)(v559 - v558) >> 31));
      v557[v645] = v662;
      int * v561 = v528->cache_age;
      int v562 = v561[v646];
      int v664 = v562 + ((int)((unsigned int)(v562 - v558) >> 31));
      v561[v646] = v664;
      int * v564 = v528->cache_age;
      v564[v661] = 0;
      v610 = v661;
    } else {
      int * v567 = v528->cache_age;
      int v668 = 4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2);
      int v568 = v567[v668];
      int * v569 = v528->cache_tags;
      int v570 = v569[v668];
      int v571 = v567[v646];
      int v572 = v569[v646];
      int * v573 = v528->cache_dirty;
      int v671 = (4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v574 = v573[v671];
      bool v672 = !(v574 == 0);
      if (v672) {
        int * v575 = v528->cache_tags;
        int v576 = v575[v671];
        int * v577 = v528->cache_vals;
        int v675 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v578 = v577[v675];
        int v676 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v579 = v577[v676];
        int * v580 = v528->mem;
        int v678 = v576 * 2;
        v580[v678] = v578;
        int * v582 = v528->mem;
        int v681 = (v576 * 2) + 1;
        v582[v681] = v579;
        ;
      } else {
        ;
      }
      int * v587 = v528->mem;
      int v686 = ((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) * 2;
      int v588 = v587[v686];
      int v687 = (((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) * 2) + 1;
      int v589 = v587[v687];
      int * v590 = v528->cache_vals;
      int v689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v590[v689] = v588;
      int * v592 = v528->cache_vals;
      int v692 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 3) * 2)) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v592[v692] = v589;
      int * v594 = v528->cache_tags;
      int v695 = (int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1);
      v594[v671] = v695;
      int * v596 = v528->cache_dirty;
      v596[v671] = 0;
      int * v598 = v528->cache_age;
      v598[v671] = 1;
      int * v600 = v528->cache_age;
      int v601 = v600[v671];
      int v602 = v600[v645];
      int v701 = v602 + ((int)((unsigned int)(v602 - v601) >> 31));
      v600[v645] = v701;
      int * v604 = v528->cache_age;
      int v605 = v604[v646];
      int v703 = v605 + ((int)((unsigned int)(v605 - v601) >> 31));
      v604[v646] = v703;
      int * v607 = v528->cache_age;
      v607[v671] = 0;
      v610 = v671;
    }
    int * v611 = v528->cache_vals;
    int v706 = v610 * 2;
    int v612 = v611[v706];
    int v707 = (v610 * 2) + 1;
    int v613 = v611[v707];
    int v708 = (((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v555 + ((~(((v556 ^ -1) | (-(v556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v611[v708] = v612;
    int * v615 = v528->cache_vals;
    int v711 = ((((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v555 + ((~(((v556 ^ -1) | (-(v556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v615[v711] = v613;
    int * v617 = v528->cache_tags;
    int v714 = ((((int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1)) & 1) * 2) + ((((v552 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2)) - (v555 + ((~(((v556 ^ -1) | (-(v556 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v715 = (int)((unsigned int)((int)((unsigned int)v532 >> 2)) >> 1);
    v617[v714] = v715;
    int * v619 = v528->cache_dirty;
    v619[v714] = 0;
    int * v621 = v528->cache_age;
    v621[v714] = 1;
    int * v623 = v528->cache_age;
    int v624 = v623[v714];
    int v625 = v623[v643];
    int v721 = v625 + ((int)((unsigned int)(v625 - v624) >> 31));
    v623[v643] = v721;
    int * v627 = v528->cache_age;
    int v628 = v627[v644];
    int v723 = v628 + ((int)((unsigned int)(v628 - v624) >> 31));
    v627[v644] = v723;
    int * v630 = v528->cache_age;
    v630[v714] = 0;
    v633 = v714;
  }
  int v726 = (v633 * 2) + (((int)((unsigned int)v532 >> 2)) & 1);
  int v634 = v540[v726];
  int * v635 = v528->regs;
  v635[7] = v634;
  struct StateT * v637 = slot_12(v528);
  return v637;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}