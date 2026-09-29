// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * slot_12(struct StateT * v802);
struct StateT * slot_6(struct StateT * v298);
struct StateT * slot_16(struct StateT * v890);
struct StateT * slot_5(struct StateT * v277);
struct StateT * slot_2(struct StateT * v210);
struct StateT * slot_7(struct StateT * v506);
struct StateT * slot_21(struct StateT * v1186);
struct StateT * slot_3(struct StateT * v234);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1144);
struct StateT * slot_13(struct StateT * v826);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v848);
struct StateT * slot_17(struct StateT * v1098);
struct StateT * slot_20(struct StateT * v1165);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v530);
struct StateT * slot_4(struct StateT * v256);
struct StateT * slot_15(struct StateT * v869);
struct StateT * slot_18(struct StateT * v1122);
struct StateT * slot_9(struct StateT * v552);
struct StateT * slot_22(struct StateT * v1394);
struct StateT * slot_11(struct StateT * v594);
struct StateT * slot_12(struct StateT * v802) {
  int v803 = v802->timer;
  int v816 = v803 + 1;
  v802->timer = v816;
  int * v805 = v802->reg_ready;
  int v806 = v805[5];
  int * v807 = v802->regs;
  int v808 = v807[5];
  int v809 = v805[7];
  int v810 = v807[7];
  int v821 = (v809 + (((v806 + ((v803 - v806) & (~((v803 - v806) >> 31)))) - v809) & (~(((v806 + ((v803 - v806) & (~((v803 - v806) >> 31)))) - v809) >> 31)))) + 1;
  v805[5] = v821;
  int * v812 = v802->regs;
  int v823 = v808 ^ v810;
  v812[5] = v823;
  struct StateT * v814 = slot_13(v802);
  return v814;
}

struct StateT * slot_6(struct StateT * v298) {
  int v299 = v298->timer;
  int v411 = v299 + 1;
  v298->timer = v411;
  int * v301 = v298->reg_ready;
  int v302 = v301[6];
  int * v303 = v298->regs;
  int v304 = v303[6];
  int * v305 = v298->cache_tags;
  int v416 = (((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2;
  int v306 = v305[v416];
  int v417 = ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2) + 1;
  int v307 = v305[v417];
  int v418 = 4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2);
  int v308 = v305[v418];
  int v419 = (4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v309 = v305[v419];
  int * v310 = v298->cache_vals;
  bool v420 = !(((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) | (~(((v307 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v307 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31))) == 0);
  int v403;
  if (v420) {
    int * v311 = v298->cache_age;
    int v422 = ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2) + ((~(((v307 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v307 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) & 1);
    int v312 = v311[v422];
    int v313 = v311[v416];
    int v423 = v313 + ((int)((unsigned int)(v313 - v312) >> 31));
    v311[v416] = v423;
    int * v315 = v298->cache_age;
    int v316 = v315[v417];
    int v425 = v316 + ((int)((unsigned int)(v316 - v312) >> 31));
    v315[v417] = v425;
    int * v318 = v298->cache_age;
    v318[v422] = 0;
    v403 = v422;
  } else {
    int * v321 = v298->cache_age;
    int v429 = (((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2;
    int v322 = v321[v429];
    int * v323 = v298->cache_tags;
    int v324 = v323[v429];
    int v325 = v321[v417];
    int v326 = v323[v417];
    bool v431 = !(((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31))) == 0);
    int v380;
    if (v431) {
      int * v327 = v298->cache_age;
      int v433 = (4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + ((~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) & 1);
      int v328 = v327[v433];
      int v329 = v327[v418];
      int v434 = v329 + ((int)((unsigned int)(v329 - v328) >> 31));
      v327[v418] = v434;
      int * v331 = v298->cache_age;
      int v332 = v331[v419];
      int v436 = v332 + ((int)((unsigned int)(v332 - v328) >> 31));
      v331[v419] = v436;
      int * v334 = v298->cache_age;
      v334[v433] = 0;
      v380 = v433;
    } else {
      int * v337 = v298->cache_age;
      int v440 = 4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2);
      int v338 = v337[v440];
      int * v339 = v298->cache_tags;
      int v340 = v339[v440];
      int v341 = v337[v419];
      int v342 = v339[v419];
      int * v343 = v298->cache_dirty;
      int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v341 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v344 = v343[v443];
      bool v444 = !(v344 == 0);
      if (v444) {
        int * v345 = v298->cache_tags;
        int v346 = v345[v443];
        int * v347 = v298->cache_vals;
        int v447 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v341 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v348 = v347[v447];
        int v448 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v341 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v349 = v347[v448];
        int * v350 = v298->mem;
        int v450 = v346 * 2;
        v350[v450] = v348;
        int * v352 = v298->mem;
        int v453 = (v346 * 2) + 1;
        v352[v453] = v349;
        ;
      } else {
        ;
      }
      int * v357 = v298->mem;
      int v458 = ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) * 2;
      int v358 = v357[v458];
      int v459 = (((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) * 2) + 1;
      int v359 = v357[v459];
      int * v360 = v298->cache_vals;
      int v461 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v341 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v360[v461] = v358;
      int * v362 = v298->cache_vals;
      int v464 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 3) * 2)) + ((((v338 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2)) - (v341 + ((~(((v342 ^ -1) | (-(v342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v362[v464] = v359;
      int * v364 = v298->cache_tags;
      int v467 = (int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1);
      v364[v443] = v467;
      int * v366 = v298->cache_dirty;
      v366[v443] = 0;
      int * v368 = v298->cache_age;
      v368[v443] = 1;
      int * v370 = v298->cache_age;
      int v371 = v370[v443];
      int v372 = v370[v418];
      int v473 = v372 + ((int)((unsigned int)(v372 - v371) >> 31));
      v370[v418] = v473;
      int * v374 = v298->cache_age;
      int v375 = v374[v419];
      int v475 = v375 + ((int)((unsigned int)(v375 - v371) >> 31));
      v374[v419] = v475;
      int * v377 = v298->cache_age;
      v377[v443] = 0;
      v380 = v443;
    }
    int * v381 = v298->cache_vals;
    int v478 = v380 * 2;
    int v382 = v381[v478];
    int v479 = (v380 * 2) + 1;
    int v383 = v381[v479];
    int v480 = (((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v381[v480] = v382;
    int * v385 = v298->cache_vals;
    int v483 = ((((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v385[v483] = v383;
    int * v387 = v298->cache_tags;
    int v486 = ((((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1)) & 1) * 2) + ((((v322 + ((~(((v324 ^ -1) | (-(v324 ^ -1))) >> 31)) & 2)) - (v325 + ((~(((v326 ^ -1) | (-(v326 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v487 = (int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1);
    v387[v486] = v487;
    int * v389 = v298->cache_dirty;
    v389[v486] = 0;
    int * v391 = v298->cache_age;
    v391[v486] = 1;
    int * v393 = v298->cache_age;
    int v394 = v393[v486];
    int v395 = v393[v416];
    int v493 = v395 + ((int)((unsigned int)(v395 - v394) >> 31));
    v393[v416] = v493;
    int * v397 = v298->cache_age;
    int v398 = v397[v417];
    int v495 = v398 + ((int)((unsigned int)(v398 - v394) >> 31));
    v397[v417] = v495;
    int * v400 = v298->cache_age;
    v400[v486] = 0;
    v403 = v486;
  }
  int v498 = (v403 * 2) + (((int)((unsigned int)v304 >> 2)) & 1);
  int v404 = v310[v498];
  int * v405 = v298->reg_ready;
  int v501 = ((v302 + ((v299 - v302) & (~((v299 - v302) >> 31)))) + 1) + ((100 ^ (((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v306 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v306 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) | (~(((v307 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v307 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v304 >> 2)) >> 1))))) >> 31))) & 104)))));
  v405[7] = v501;
  int * v407 = v298->regs;
  v407[7] = v404;
  struct StateT * v409 = slot_7(v298);
  return v409;
}

struct StateT * slot_16(struct StateT * v890) {
  int v891 = v890->timer;
  int v1003 = v891 + 1;
  v890->timer = v1003;
  int * v893 = v890->reg_ready;
  int v894 = v893[6];
  int * v895 = v890->regs;
  int v896 = v895[6];
  int * v897 = v890->cache_tags;
  int v1008 = (((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2;
  int v898 = v897[v1008];
  int v1009 = ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + 1;
  int v899 = v897[v1009];
  int v1010 = 4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2);
  int v900 = v897[v1010];
  int v1011 = (4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v901 = v897[v1011];
  int * v902 = v890->cache_vals;
  bool v1012 = !(((~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) == 0);
  int v995;
  if (v1012) {
    int * v903 = v890->cache_age;
    int v1014 = ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) & 1);
    int v904 = v903[v1014];
    int v905 = v903[v1008];
    int v1015 = v905 + ((int)((unsigned int)(v905 - v904) >> 31));
    v903[v1008] = v1015;
    int * v907 = v890->cache_age;
    int v908 = v907[v1009];
    int v1017 = v908 + ((int)((unsigned int)(v908 - v904) >> 31));
    v907[v1009] = v1017;
    int * v910 = v890->cache_age;
    v910[v1014] = 0;
    v995 = v1014;
  } else {
    int * v913 = v890->cache_age;
    int v1021 = (((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2;
    int v914 = v913[v1021];
    int * v915 = v890->cache_tags;
    int v916 = v915[v1021];
    int v917 = v913[v1009];
    int v918 = v915[v1009];
    bool v1023 = !(((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) == 0);
    int v972;
    if (v1023) {
      int * v919 = v890->cache_age;
      int v1025 = (4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) & 1);
      int v920 = v919[v1025];
      int v921 = v919[v1010];
      int v1026 = v921 + ((int)((unsigned int)(v921 - v920) >> 31));
      v919[v1010] = v1026;
      int * v923 = v890->cache_age;
      int v924 = v923[v1011];
      int v1028 = v924 + ((int)((unsigned int)(v924 - v920) >> 31));
      v923[v1011] = v1028;
      int * v926 = v890->cache_age;
      v926[v1025] = 0;
      v972 = v1025;
    } else {
      int * v929 = v890->cache_age;
      int v1032 = 4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2);
      int v930 = v929[v1032];
      int * v931 = v890->cache_tags;
      int v932 = v931[v1032];
      int v933 = v929[v1011];
      int v934 = v931[v1011];
      int * v935 = v890->cache_dirty;
      int v1035 = (4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v936 = v935[v1035];
      bool v1036 = !(v936 == 0);
      if (v1036) {
        int * v937 = v890->cache_tags;
        int v938 = v937[v1035];
        int * v939 = v890->cache_vals;
        int v1039 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v940 = v939[v1039];
        int v1040 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v941 = v939[v1040];
        int * v942 = v890->mem;
        int v1042 = v938 * 2;
        v942[v1042] = v940;
        int * v944 = v890->mem;
        int v1045 = (v938 * 2) + 1;
        v944[v1045] = v941;
        ;
      } else {
        ;
      }
      int * v949 = v890->mem;
      int v1050 = ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) * 2;
      int v950 = v949[v1050];
      int v1051 = (((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) * 2) + 1;
      int v951 = v949[v1051];
      int * v952 = v890->cache_vals;
      int v1053 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v952[v1053] = v950;
      int * v954 = v890->cache_vals;
      int v1056 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2)) - (v933 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v954[v1056] = v951;
      int * v956 = v890->cache_tags;
      int v1059 = (int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1);
      v956[v1035] = v1059;
      int * v958 = v890->cache_dirty;
      v958[v1035] = 0;
      int * v960 = v890->cache_age;
      v960[v1035] = 1;
      int * v962 = v890->cache_age;
      int v963 = v962[v1035];
      int v964 = v962[v1010];
      int v1065 = v964 + ((int)((unsigned int)(v964 - v963) >> 31));
      v962[v1010] = v1065;
      int * v966 = v890->cache_age;
      int v967 = v966[v1011];
      int v1067 = v967 + ((int)((unsigned int)(v967 - v963) >> 31));
      v966[v1011] = v1067;
      int * v969 = v890->cache_age;
      v969[v1035] = 0;
      v972 = v1035;
    }
    int * v973 = v890->cache_vals;
    int v1070 = v972 * 2;
    int v974 = v973[v1070];
    int v1071 = (v972 * 2) + 1;
    int v975 = v973[v1071];
    int v1072 = (((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((((v914 + ((~(((v916 ^ -1) | (-(v916 ^ -1))) >> 31)) & 2)) - (v917 + ((~(((v918 ^ -1) | (-(v918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v973[v1072] = v974;
    int * v977 = v890->cache_vals;
    int v1075 = ((((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((((v914 + ((~(((v916 ^ -1) | (-(v916 ^ -1))) >> 31)) & 2)) - (v917 + ((~(((v918 ^ -1) | (-(v918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v977[v1075] = v975;
    int * v979 = v890->cache_tags;
    int v1078 = ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((((v914 + ((~(((v916 ^ -1) | (-(v916 ^ -1))) >> 31)) & 2)) - (v917 + ((~(((v918 ^ -1) | (-(v918 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1079 = (int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1);
    v979[v1078] = v1079;
    int * v981 = v890->cache_dirty;
    v981[v1078] = 0;
    int * v983 = v890->cache_age;
    v983[v1078] = 1;
    int * v985 = v890->cache_age;
    int v986 = v985[v1078];
    int v987 = v985[v1008];
    int v1085 = v987 + ((int)((unsigned int)(v987 - v986) >> 31));
    v985[v1008] = v1085;
    int * v989 = v890->cache_age;
    int v990 = v989[v1009];
    int v1087 = v990 + ((int)((unsigned int)(v990 - v986) >> 31));
    v989[v1009] = v1087;
    int * v992 = v890->cache_age;
    v992[v1078] = 0;
    v995 = v1078;
  }
  int v1090 = (v995 * 2) + (((int)((unsigned int)v896 >> 2)) & 1);
  int v996 = v902[v1090];
  int * v997 = v890->reg_ready;
  int v1093 = ((v894 + ((v891 - v894) & (~((v891 - v894) >> 31)))) + 1) + ((100 ^ (((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) & 104)))));
  v997[7] = v1093;
  int * v999 = v890->regs;
  v999[7] = v996;
  struct StateT * v1001 = slot_17(v890);
  return v1001;
}

struct StateT * slot_5(struct StateT * v277) {
  int v278 = v277->timer;
  int v289 = v278 + 1;
  v277->timer = v289;
  int * v280 = v277->reg_ready;
  int v281 = v280[6];
  int * v282 = v277->regs;
  int v283 = v282[6];
  int v293 = (v281 + ((v278 - v281) & (~((v278 - v281) >> 31)))) + 1;
  v280[6] = v293;
  int * v285 = v277->regs;
  int v295 = v283 << 2;
  v285[6] = v295;
  struct StateT * v287 = slot_6(v277);
  return v287;
}

struct StateT * slot_2(struct StateT * v210) {
  int v211 = v210->timer;
  int v224 = v211 + 1;
  v210->timer = v224;
  int * v213 = v210->reg_ready;
  int v214 = v213[5];
  int * v215 = v210->regs;
  int v216 = v215[5];
  int v217 = v213[9];
  int v218 = v215[9];
  int v229 = (v217 + (((v214 + ((v211 - v214) & (~((v211 - v214) >> 31)))) - v217) & (~(((v214 + ((v211 - v214) & (~((v211 - v214) >> 31)))) - v217) >> 31)))) + 1;
  v213[5] = v229;
  int * v220 = v210->regs;
  int v231 = v216 ^ v218;
  v220[5] = v231;
  struct StateT * v222 = slot_3(v210);
  return v222;
}

struct StateT * slot_7(struct StateT * v506) {
  int v507 = v506->timer;
  int v520 = v507 + 1;
  v506->timer = v520;
  int * v509 = v506->reg_ready;
  int v510 = v509[5];
  int * v511 = v506->regs;
  int v512 = v511[5];
  int v513 = v509[7];
  int v514 = v511[7];
  int v525 = (v513 + (((v510 + ((v507 - v510) & (~((v507 - v510) >> 31)))) - v513) & (~(((v510 + ((v507 - v510) & (~((v507 - v510) >> 31)))) - v513) >> 31)))) + 1;
  v509[5] = v525;
  int * v516 = v506->regs;
  int v527 = v512 ^ v514;
  v516[5] = v527;
  struct StateT * v518 = slot_8(v506);
  return v518;
}

struct StateT * slot_21(struct StateT * v1186) {
  int v1187 = v1186->timer;
  int v1299 = v1187 + 1;
  v1186->timer = v1299;
  int * v1189 = v1186->reg_ready;
  int v1190 = v1189[6];
  int * v1191 = v1186->regs;
  int v1192 = v1191[6];
  int * v1193 = v1186->cache_tags;
  int v1304 = (((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2;
  int v1194 = v1193[v1304];
  int v1305 = ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1195 = v1193[v1305];
  int v1306 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2);
  int v1196 = v1193[v1306];
  int v1307 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1197 = v1193[v1307];
  int * v1198 = v1186->cache_vals;
  bool v1308 = !(((~(((v1194 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1194 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) | (~(((v1195 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1195 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31))) == 0);
  int v1291;
  if (v1308) {
    int * v1199 = v1186->cache_age;
    int v1310 = ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2) + ((~(((v1195 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1195 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) & 1);
    int v1200 = v1199[v1310];
    int v1201 = v1199[v1304];
    int v1311 = v1201 + ((int)((unsigned int)(v1201 - v1200) >> 31));
    v1199[v1304] = v1311;
    int * v1203 = v1186->cache_age;
    int v1204 = v1203[v1305];
    int v1313 = v1204 + ((int)((unsigned int)(v1204 - v1200) >> 31));
    v1203[v1305] = v1313;
    int * v1206 = v1186->cache_age;
    v1206[v1310] = 0;
    v1291 = v1310;
  } else {
    int * v1209 = v1186->cache_age;
    int v1317 = (((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2;
    int v1210 = v1209[v1317];
    int * v1211 = v1186->cache_tags;
    int v1212 = v1211[v1317];
    int v1213 = v1209[v1305];
    int v1214 = v1211[v1305];
    bool v1319 = !(((~(((v1196 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1196 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) | (~(((v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31))) == 0);
    int v1268;
    if (v1319) {
      int * v1215 = v1186->cache_age;
      int v1321 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) & 1);
      int v1216 = v1215[v1321];
      int v1217 = v1215[v1306];
      int v1322 = v1217 + ((int)((unsigned int)(v1217 - v1216) >> 31));
      v1215[v1306] = v1322;
      int * v1219 = v1186->cache_age;
      int v1220 = v1219[v1307];
      int v1324 = v1220 + ((int)((unsigned int)(v1220 - v1216) >> 31));
      v1219[v1307] = v1324;
      int * v1222 = v1186->cache_age;
      v1222[v1321] = 0;
      v1268 = v1321;
    } else {
      int * v1225 = v1186->cache_age;
      int v1328 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2);
      int v1226 = v1225[v1328];
      int * v1227 = v1186->cache_tags;
      int v1228 = v1227[v1328];
      int v1229 = v1225[v1307];
      int v1230 = v1227[v1307];
      int * v1231 = v1186->cache_dirty;
      int v1331 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + ((((v1226 + ((~(((v1228 ^ -1) | (-(v1228 ^ -1))) >> 31)) & 2)) - (v1229 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1232 = v1231[v1331];
      bool v1332 = !(v1232 == 0);
      if (v1332) {
        int * v1233 = v1186->cache_tags;
        int v1234 = v1233[v1331];
        int * v1235 = v1186->cache_vals;
        int v1335 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + ((((v1226 + ((~(((v1228 ^ -1) | (-(v1228 ^ -1))) >> 31)) & 2)) - (v1229 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1236 = v1235[v1335];
        int v1336 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + ((((v1226 + ((~(((v1228 ^ -1) | (-(v1228 ^ -1))) >> 31)) & 2)) - (v1229 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1237 = v1235[v1336];
        int * v1238 = v1186->mem;
        int v1338 = v1234 * 2;
        v1238[v1338] = v1236;
        int * v1240 = v1186->mem;
        int v1341 = (v1234 * 2) + 1;
        v1240[v1341] = v1237;
        ;
      } else {
        ;
      }
      int * v1245 = v1186->mem;
      int v1346 = ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) * 2;
      int v1246 = v1245[v1346];
      int v1347 = (((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) * 2) + 1;
      int v1247 = v1245[v1347];
      int * v1248 = v1186->cache_vals;
      int v1349 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + ((((v1226 + ((~(((v1228 ^ -1) | (-(v1228 ^ -1))) >> 31)) & 2)) - (v1229 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1248[v1349] = v1246;
      int * v1250 = v1186->cache_vals;
      int v1352 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 3) * 2)) + ((((v1226 + ((~(((v1228 ^ -1) | (-(v1228 ^ -1))) >> 31)) & 2)) - (v1229 + ((~(((v1230 ^ -1) | (-(v1230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1250[v1352] = v1247;
      int * v1252 = v1186->cache_tags;
      int v1355 = (int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1);
      v1252[v1331] = v1355;
      int * v1254 = v1186->cache_dirty;
      v1254[v1331] = 0;
      int * v1256 = v1186->cache_age;
      v1256[v1331] = 1;
      int * v1258 = v1186->cache_age;
      int v1259 = v1258[v1331];
      int v1260 = v1258[v1306];
      int v1361 = v1260 + ((int)((unsigned int)(v1260 - v1259) >> 31));
      v1258[v1306] = v1361;
      int * v1262 = v1186->cache_age;
      int v1263 = v1262[v1307];
      int v1363 = v1263 + ((int)((unsigned int)(v1263 - v1259) >> 31));
      v1262[v1307] = v1363;
      int * v1265 = v1186->cache_age;
      v1265[v1331] = 0;
      v1268 = v1331;
    }
    int * v1269 = v1186->cache_vals;
    int v1366 = v1268 * 2;
    int v1270 = v1269[v1366];
    int v1367 = (v1268 * 2) + 1;
    int v1271 = v1269[v1367];
    int v1368 = (((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2) + ((((v1210 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2)) - (v1213 + ((~(((v1214 ^ -1) | (-(v1214 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1269[v1368] = v1270;
    int * v1273 = v1186->cache_vals;
    int v1371 = ((((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2) + ((((v1210 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2)) - (v1213 + ((~(((v1214 ^ -1) | (-(v1214 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1273[v1371] = v1271;
    int * v1275 = v1186->cache_tags;
    int v1374 = ((((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1)) & 1) * 2) + ((((v1210 + ((~(((v1212 ^ -1) | (-(v1212 ^ -1))) >> 31)) & 2)) - (v1213 + ((~(((v1214 ^ -1) | (-(v1214 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1375 = (int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1);
    v1275[v1374] = v1375;
    int * v1277 = v1186->cache_dirty;
    v1277[v1374] = 0;
    int * v1279 = v1186->cache_age;
    v1279[v1374] = 1;
    int * v1281 = v1186->cache_age;
    int v1282 = v1281[v1374];
    int v1283 = v1281[v1304];
    int v1381 = v1283 + ((int)((unsigned int)(v1283 - v1282) >> 31));
    v1281[v1304] = v1381;
    int * v1285 = v1186->cache_age;
    int v1286 = v1285[v1305];
    int v1383 = v1286 + ((int)((unsigned int)(v1286 - v1282) >> 31));
    v1285[v1305] = v1383;
    int * v1288 = v1186->cache_age;
    v1288[v1374] = 0;
    v1291 = v1374;
  }
  int v1386 = (v1291 * 2) + (((int)((unsigned int)v1192 >> 2)) & 1);
  int v1292 = v1198[v1386];
  int * v1293 = v1186->reg_ready;
  int v1389 = ((v1190 + ((v1187 - v1190) & (~((v1187 - v1190) >> 31)))) + 1) + ((100 ^ (((~(((v1196 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1196 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) | (~(((v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1194 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1194 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) | (~(((v1195 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1195 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1196 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1196 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31)) | (~(((v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))) | (-(v1197 ^ ((int)((unsigned int)((int)((unsigned int)v1192 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1293[7] = v1389;
  int * v1295 = v1186->regs;
  v1295[7] = v1292;
  struct StateT * v1297 = slot_22(v1186);
  return v1297;
}

struct StateT * slot_3(struct StateT * v234) {
  int v235 = v234->timer;
  int v246 = v235 + 1;
  v234->timer = v246;
  int * v237 = v234->reg_ready;
  int v238 = v237[10];
  int * v239 = v234->regs;
  int v240 = v239[10];
  int v251 = (v238 + ((v235 - v238) & (~((v235 - v238) >> 31)))) + 1;
  v237[6] = v251;
  int * v242 = v234->regs;
  v242[6] = v240;
  struct StateT * v244 = slot_4(v234);
  return v244;
}

struct StateT * slot_10(struct StateT * v573) {
  int v574 = v573->timer;
  int v585 = v574 + 1;
  v573->timer = v585;
  int * v576 = v573->reg_ready;
  int v577 = v576[6];
  int * v578 = v573->regs;
  int v579 = v578[6];
  int v589 = (v577 + ((v574 - v577) & (~((v574 - v577) >> 31)))) + 1;
  v576[6] = v589;
  int * v581 = v573->regs;
  int v591 = v579 << 2;
  v581[6] = v591;
  struct StateT * v583 = slot_11(v573);
  return v583;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v127 = v19 + 1;
  v18->timer = v127;
  int * v21 = v18->cache_tags;
  int v22 = v21[0];
  int v23 = v21[1];
  int v24 = v21[8];
  int v25 = v21[9];
  int * v26 = v18->cache_vals;
  bool v133 = !(((~(((v22 ^ 10) | (-(v22 ^ 10))) >> 31)) | (~(((v23 ^ 10) | (-(v23 ^ 10))) >> 31))) == 0);
  int v119;
  if (v133) {
    int * v27 = v18->cache_age;
    int v135 = (~(((v23 ^ 10) | (-(v23 ^ 10))) >> 31)) & 1;
    int v28 = v27[v135];
    int v29 = v27[0];
    int v136 = v29 + ((int)((unsigned int)(v29 - v28) >> 31));
    v27[0] = v136;
    int * v31 = v18->cache_age;
    int v32 = v31[1];
    int v138 = v32 + ((int)((unsigned int)(v32 - v28) >> 31));
    v31[1] = v138;
    int * v34 = v18->cache_age;
    v34[v135] = 0;
    v119 = v135;
  } else {
    int * v37 = v18->cache_age;
    int v38 = v37[0];
    int * v39 = v18->cache_tags;
    int v40 = v39[0];
    int v41 = v37[1];
    int v42 = v39[1];
    bool v142 = !(((~(((v24 ^ 10) | (-(v24 ^ 10))) >> 31)) | (~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31))) == 0);
    int v96;
    if (v142) {
      int * v43 = v18->cache_age;
      int v144 = 8 + ((~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31)) & 1);
      int v44 = v43[v144];
      int v45 = v43[8];
      int v145 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
      v43[8] = v145;
      int * v47 = v18->cache_age;
      int v48 = v47[9];
      int v147 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
      v47[9] = v147;
      int * v50 = v18->cache_age;
      v50[v144] = 0;
      v96 = v144;
    } else {
      int * v53 = v18->cache_age;
      int v54 = v53[8];
      int * v55 = v18->cache_tags;
      int v56 = v55[8];
      int v57 = v53[9];
      int v58 = v55[9];
      int * v59 = v18->cache_dirty;
      int v152 = 8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v60 = v59[v152];
      bool v153 = !(v60 == 0);
      if (v153) {
        int * v61 = v18->cache_tags;
        int v62 = v61[v152];
        int * v63 = v18->cache_vals;
        int v156 = (8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v64 = v63[v156];
        int v157 = ((8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v65 = v63[v157];
        int * v66 = v18->mem;
        int v159 = v62 * 2;
        v66[v159] = v64;
        int * v68 = v18->mem;
        int v162 = (v62 * 2) + 1;
        v68[v162] = v65;
        ;
      } else {
        ;
      }
      int * v73 = v18->mem;
      int v74 = v73[20];
      int v75 = v73[21];
      int * v76 = v18->cache_vals;
      int v170 = (8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v76[v170] = v74;
      int * v78 = v18->cache_vals;
      int v173 = ((8 + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v78[v173] = v75;
      int * v80 = v18->cache_tags;
      v80[v152] = 10;
      int * v82 = v18->cache_dirty;
      v82[v152] = 0;
      int * v84 = v18->cache_age;
      v84[v152] = 1;
      int * v86 = v18->cache_age;
      int v87 = v86[v152];
      int v88 = v86[8];
      int v180 = v88 + ((int)((unsigned int)(v88 - v87) >> 31));
      v86[8] = v180;
      int * v90 = v18->cache_age;
      int v91 = v90[9];
      int v182 = v91 + ((int)((unsigned int)(v91 - v87) >> 31));
      v90[9] = v182;
      int * v93 = v18->cache_age;
      v93[v152] = 0;
      v96 = v152;
    }
    int * v97 = v18->cache_vals;
    int v185 = v96 * 2;
    int v98 = v97[v185];
    int v186 = (v96 * 2) + 1;
    int v99 = v97[v186];
    int v187 = ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v97[v187] = v98;
    int * v101 = v18->cache_vals;
    int v190 = (((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v101[v190] = v99;
    int * v103 = v18->cache_tags;
    int v193 = (((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v103[v193] = 10;
    int * v105 = v18->cache_dirty;
    v105[v193] = 0;
    int * v107 = v18->cache_age;
    v107[v193] = 1;
    int * v109 = v18->cache_age;
    int v110 = v109[v193];
    int v111 = v109[0];
    int v198 = v111 + ((int)((unsigned int)(v111 - v110) >> 31));
    v109[0] = v198;
    int * v113 = v18->cache_age;
    int v114 = v113[1];
    int v200 = v114 + ((int)((unsigned int)(v114 - v110) >> 31));
    v113[1] = v200;
    int * v116 = v18->cache_age;
    v116[v193] = 0;
    v119 = v193;
  }
  int v203 = v119 * 2;
  int v120 = v26[v203];
  int * v121 = v18->reg_ready;
  int v205 = (v19 + 1) + ((100 ^ (((~(((v24 ^ 10) | (-(v24 ^ 10))) >> 31)) | (~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31))) & 104)) ^ (((~(((v22 ^ 10) | (-(v22 ^ 10))) >> 31)) | (~(((v23 ^ 10) | (-(v23 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v24 ^ 10) | (-(v24 ^ 10))) >> 31)) | (~(((v25 ^ 10) | (-(v25 ^ 10))) >> 31))) & 104)))));
  v121[9] = v205;
  int * v123 = v18->regs;
  v123[9] = v120;
  struct StateT * v125 = slot_2(v18);
  return v125;
}

struct StateT * slot_19(struct StateT * v1144) {
  int v1145 = v1144->timer;
  int v1156 = v1145 + 1;
  v1144->timer = v1156;
  int * v1147 = v1144->reg_ready;
  int v1148 = v1147[6];
  int * v1149 = v1144->regs;
  int v1150 = v1149[6];
  int v1160 = (v1148 + ((v1145 - v1148) & (~((v1145 - v1148) >> 31)))) + 1;
  v1147[6] = v1160;
  int * v1152 = v1144->regs;
  int v1162 = v1150 & 63;
  v1152[6] = v1162;
  struct StateT * v1154 = slot_20(v1144);
  return v1154;
}

struct StateT * slot_13(struct StateT * v826) {
  int v827 = v826->timer;
  int v838 = v827 + 1;
  v826->timer = v838;
  int * v829 = v826->reg_ready;
  int v830 = v829[10];
  int * v831 = v826->regs;
  int v832 = v831[10];
  int v843 = (v830 + ((v827 - v830) & (~((v827 - v830) >> 31)))) + 1;
  v829[6] = v843;
  int * v834 = v826->regs;
  int v845 = (int)((unsigned int)v832 >> 16);
  v834[6] = v845;
  struct StateT * v836 = slot_14(v826);
  return v836;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[5] = v11;
  int * v7 = v2->regs;
  v7[5] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v848) {
  int v849 = v848->timer;
  int v860 = v849 + 1;
  v848->timer = v860;
  int * v851 = v848->reg_ready;
  int v852 = v851[6];
  int * v853 = v848->regs;
  int v854 = v853[6];
  int v864 = (v852 + ((v849 - v852) & (~((v849 - v852) >> 31)))) + 1;
  v851[6] = v864;
  int * v856 = v848->regs;
  int v866 = v854 & 63;
  v856[6] = v866;
  struct StateT * v858 = slot_15(v848);
  return v858;
}

struct StateT * slot_17(struct StateT * v1098) {
  int v1099 = v1098->timer;
  int v1112 = v1099 + 1;
  v1098->timer = v1112;
  int * v1101 = v1098->reg_ready;
  int v1102 = v1101[5];
  int * v1103 = v1098->regs;
  int v1104 = v1103[5];
  int v1105 = v1101[7];
  int v1106 = v1103[7];
  int v1117 = (v1105 + (((v1102 + ((v1099 - v1102) & (~((v1099 - v1102) >> 31)))) - v1105) & (~(((v1102 + ((v1099 - v1102) & (~((v1099 - v1102) >> 31)))) - v1105) >> 31)))) + 1;
  v1101[5] = v1117;
  int * v1108 = v1098->regs;
  int v1119 = v1104 ^ v1106;
  v1108[5] = v1119;
  struct StateT * v1110 = slot_18(v1098);
  return v1110;
}

struct StateT * slot_20(struct StateT * v1165) {
  int v1166 = v1165->timer;
  int v1177 = v1166 + 1;
  v1165->timer = v1177;
  int * v1168 = v1165->reg_ready;
  int v1169 = v1168[6];
  int * v1170 = v1165->regs;
  int v1171 = v1170[6];
  int v1181 = (v1169 + ((v1166 - v1169) & (~((v1166 - v1169) >> 31)))) + 1;
  v1168[6] = v1181;
  int * v1173 = v1165->regs;
  int v1183 = v1171 << 2;
  v1173[6] = v1183;
  struct StateT * v1175 = slot_21(v1165);
  return v1175;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1415 = v1->timer;
  int * v1416 = v1->reg_ready;
  int v1417 = v1416[0];
  int v1548 = v1417 + ((v1415 - v1417) & (~((v1415 - v1417) >> 31)));
  v1->timer = v1548;
  int v1419 = v1->timer;
  int * v1420 = v1->reg_ready;
  int v1421 = v1420[1];
  int v1551 = v1421 + ((v1419 - v1421) & (~((v1419 - v1421) >> 31)));
  v1->timer = v1551;
  int v1423 = v1->timer;
  int * v1424 = v1->reg_ready;
  int v1425 = v1424[2];
  int v1554 = v1425 + ((v1423 - v1425) & (~((v1423 - v1425) >> 31)));
  v1->timer = v1554;
  int v1427 = v1->timer;
  int * v1428 = v1->reg_ready;
  int v1429 = v1428[3];
  int v1557 = v1429 + ((v1427 - v1429) & (~((v1427 - v1429) >> 31)));
  v1->timer = v1557;
  int v1431 = v1->timer;
  int * v1432 = v1->reg_ready;
  int v1433 = v1432[4];
  int v1560 = v1433 + ((v1431 - v1433) & (~((v1431 - v1433) >> 31)));
  v1->timer = v1560;
  int v1435 = v1->timer;
  int * v1436 = v1->reg_ready;
  int v1437 = v1436[5];
  int v1563 = v1437 + ((v1435 - v1437) & (~((v1435 - v1437) >> 31)));
  v1->timer = v1563;
  int v1439 = v1->timer;
  int * v1440 = v1->reg_ready;
  int v1441 = v1440[6];
  int v1566 = v1441 + ((v1439 - v1441) & (~((v1439 - v1441) >> 31)));
  v1->timer = v1566;
  int v1443 = v1->timer;
  int * v1444 = v1->reg_ready;
  int v1445 = v1444[7];
  int v1569 = v1445 + ((v1443 - v1445) & (~((v1443 - v1445) >> 31)));
  v1->timer = v1569;
  int v1447 = v1->timer;
  int * v1448 = v1->reg_ready;
  int v1449 = v1448[8];
  int v1572 = v1449 + ((v1447 - v1449) & (~((v1447 - v1449) >> 31)));
  v1->timer = v1572;
  int v1451 = v1->timer;
  int * v1452 = v1->reg_ready;
  int v1453 = v1452[9];
  int v1575 = v1453 + ((v1451 - v1453) & (~((v1451 - v1453) >> 31)));
  v1->timer = v1575;
  int v1455 = v1->timer;
  int * v1456 = v1->reg_ready;
  int v1457 = v1456[10];
  int v1578 = v1457 + ((v1455 - v1457) & (~((v1455 - v1457) >> 31)));
  v1->timer = v1578;
  int v1459 = v1->timer;
  int * v1460 = v1->reg_ready;
  int v1461 = v1460[11];
  int v1581 = v1461 + ((v1459 - v1461) & (~((v1459 - v1461) >> 31)));
  v1->timer = v1581;
  int v1463 = v1->timer;
  int * v1464 = v1->reg_ready;
  int v1465 = v1464[12];
  int v1584 = v1465 + ((v1463 - v1465) & (~((v1463 - v1465) >> 31)));
  v1->timer = v1584;
  int v1467 = v1->timer;
  int * v1468 = v1->reg_ready;
  int v1469 = v1468[13];
  int v1587 = v1469 + ((v1467 - v1469) & (~((v1467 - v1469) >> 31)));
  v1->timer = v1587;
  int v1471 = v1->timer;
  int * v1472 = v1->reg_ready;
  int v1473 = v1472[14];
  int v1590 = v1473 + ((v1471 - v1473) & (~((v1471 - v1473) >> 31)));
  v1->timer = v1590;
  int v1475 = v1->timer;
  int * v1476 = v1->reg_ready;
  int v1477 = v1476[15];
  int v1593 = v1477 + ((v1475 - v1477) & (~((v1475 - v1477) >> 31)));
  v1->timer = v1593;
  int v1479 = v1->timer;
  int * v1480 = v1->reg_ready;
  int v1481 = v1480[16];
  int v1596 = v1481 + ((v1479 - v1481) & (~((v1479 - v1481) >> 31)));
  v1->timer = v1596;
  int v1483 = v1->timer;
  int * v1484 = v1->reg_ready;
  int v1485 = v1484[17];
  int v1599 = v1485 + ((v1483 - v1485) & (~((v1483 - v1485) >> 31)));
  v1->timer = v1599;
  int v1487 = v1->timer;
  int * v1488 = v1->reg_ready;
  int v1489 = v1488[18];
  int v1602 = v1489 + ((v1487 - v1489) & (~((v1487 - v1489) >> 31)));
  v1->timer = v1602;
  int v1491 = v1->timer;
  int * v1492 = v1->reg_ready;
  int v1493 = v1492[19];
  int v1605 = v1493 + ((v1491 - v1493) & (~((v1491 - v1493) >> 31)));
  v1->timer = v1605;
  int v1495 = v1->timer;
  int * v1496 = v1->reg_ready;
  int v1497 = v1496[20];
  int v1608 = v1497 + ((v1495 - v1497) & (~((v1495 - v1497) >> 31)));
  v1->timer = v1608;
  int v1499 = v1->timer;
  int * v1500 = v1->reg_ready;
  int v1501 = v1500[21];
  int v1611 = v1501 + ((v1499 - v1501) & (~((v1499 - v1501) >> 31)));
  v1->timer = v1611;
  int v1503 = v1->timer;
  int * v1504 = v1->reg_ready;
  int v1505 = v1504[22];
  int v1614 = v1505 + ((v1503 - v1505) & (~((v1503 - v1505) >> 31)));
  v1->timer = v1614;
  int v1507 = v1->timer;
  int * v1508 = v1->reg_ready;
  int v1509 = v1508[23];
  int v1617 = v1509 + ((v1507 - v1509) & (~((v1507 - v1509) >> 31)));
  v1->timer = v1617;
  int v1511 = v1->timer;
  int * v1512 = v1->reg_ready;
  int v1513 = v1512[24];
  int v1620 = v1513 + ((v1511 - v1513) & (~((v1511 - v1513) >> 31)));
  v1->timer = v1620;
  int v1515 = v1->timer;
  int * v1516 = v1->reg_ready;
  int v1517 = v1516[25];
  int v1623 = v1517 + ((v1515 - v1517) & (~((v1515 - v1517) >> 31)));
  v1->timer = v1623;
  int v1519 = v1->timer;
  int * v1520 = v1->reg_ready;
  int v1521 = v1520[26];
  int v1626 = v1521 + ((v1519 - v1521) & (~((v1519 - v1521) >> 31)));
  v1->timer = v1626;
  int v1523 = v1->timer;
  int * v1524 = v1->reg_ready;
  int v1525 = v1524[27];
  int v1629 = v1525 + ((v1523 - v1525) & (~((v1523 - v1525) >> 31)));
  v1->timer = v1629;
  int v1527 = v1->timer;
  int * v1528 = v1->reg_ready;
  int v1529 = v1528[28];
  int v1632 = v1529 + ((v1527 - v1529) & (~((v1527 - v1529) >> 31)));
  v1->timer = v1632;
  int v1531 = v1->timer;
  int * v1532 = v1->reg_ready;
  int v1533 = v1532[29];
  int v1635 = v1533 + ((v1531 - v1533) & (~((v1531 - v1533) >> 31)));
  v1->timer = v1635;
  int v1535 = v1->timer;
  int * v1536 = v1->reg_ready;
  int v1537 = v1536[30];
  int v1638 = v1537 + ((v1535 - v1537) & (~((v1535 - v1537) >> 31)));
  v1->timer = v1638;
  int v1539 = v1->timer;
  int * v1540 = v1->reg_ready;
  int v1541 = v1540[31];
  int v1641 = v1541 + ((v1539 - v1541) & (~((v1539 - v1541) >> 31)));
  v1->timer = v1641;
  return v1;
}

struct StateT * slot_8(struct StateT * v530) {
  int v531 = v530->timer;
  int v542 = v531 + 1;
  v530->timer = v542;
  int * v533 = v530->reg_ready;
  int v534 = v533[10];
  int * v535 = v530->regs;
  int v536 = v535[10];
  int v547 = (v534 + ((v531 - v534) & (~((v531 - v534) >> 31)))) + 1;
  v533[6] = v547;
  int * v538 = v530->regs;
  int v549 = (int)((unsigned int)v536 >> 8);
  v538[6] = v549;
  struct StateT * v540 = slot_9(v530);
  return v540;
}

struct StateT * slot_4(struct StateT * v256) {
  int v257 = v256->timer;
  int v268 = v257 + 1;
  v256->timer = v268;
  int * v259 = v256->reg_ready;
  int v260 = v259[6];
  int * v261 = v256->regs;
  int v262 = v261[6];
  int v272 = (v260 + ((v257 - v260) & (~((v257 - v260) >> 31)))) + 1;
  v259[6] = v272;
  int * v264 = v256->regs;
  int v274 = v262 & 63;
  v264[6] = v274;
  struct StateT * v266 = slot_5(v256);
  return v266;
}

struct StateT * slot_15(struct StateT * v869) {
  int v870 = v869->timer;
  int v881 = v870 + 1;
  v869->timer = v881;
  int * v872 = v869->reg_ready;
  int v873 = v872[6];
  int * v874 = v869->regs;
  int v875 = v874[6];
  int v885 = (v873 + ((v870 - v873) & (~((v870 - v873) >> 31)))) + 1;
  v872[6] = v885;
  int * v877 = v869->regs;
  int v887 = v875 << 2;
  v877[6] = v887;
  struct StateT * v879 = slot_16(v869);
  return v879;
}

struct StateT * slot_18(struct StateT * v1122) {
  int v1123 = v1122->timer;
  int v1134 = v1123 + 1;
  v1122->timer = v1134;
  int * v1125 = v1122->reg_ready;
  int v1126 = v1125[10];
  int * v1127 = v1122->regs;
  int v1128 = v1127[10];
  int v1139 = (v1126 + ((v1123 - v1126) & (~((v1123 - v1126) >> 31)))) + 1;
  v1125[6] = v1139;
  int * v1130 = v1122->regs;
  int v1141 = (int)((unsigned int)v1128 >> 24);
  v1130[6] = v1141;
  struct StateT * v1132 = slot_19(v1122);
  return v1132;
}

struct StateT * slot_9(struct StateT * v552) {
  int v553 = v552->timer;
  int v564 = v553 + 1;
  v552->timer = v564;
  int * v555 = v552->reg_ready;
  int v556 = v555[6];
  int * v557 = v552->regs;
  int v558 = v557[6];
  int v568 = (v556 + ((v553 - v556) & (~((v553 - v556) >> 31)))) + 1;
  v555[6] = v568;
  int * v560 = v552->regs;
  int v570 = v558 & 63;
  v560[6] = v570;
  struct StateT * v562 = slot_10(v552);
  return v562;
}

struct StateT * slot_22(struct StateT * v1394) {
  int v1395 = v1394->timer;
  int v1407 = v1395 + 1;
  v1394->timer = v1407;
  int * v1397 = v1394->reg_ready;
  int v1398 = v1397[5];
  int * v1399 = v1394->regs;
  int v1400 = v1399[5];
  int v1401 = v1397[7];
  int v1402 = v1399[7];
  int v1412 = (v1401 + (((v1398 + ((v1395 - v1398) & (~((v1395 - v1398) >> 31)))) - v1401) & (~(((v1398 + ((v1395 - v1398) & (~((v1395 - v1398) >> 31)))) - v1401) >> 31)))) + 1;
  v1397[5] = v1412;
  int * v1404 = v1394->regs;
  int v1414 = v1400 ^ v1402;
  v1404[5] = v1414;
  return v1394;
}

struct StateT * slot_11(struct StateT * v594) {
  int v595 = v594->timer;
  int v707 = v595 + 1;
  v594->timer = v707;
  int * v597 = v594->reg_ready;
  int v598 = v597[6];
  int * v599 = v594->regs;
  int v600 = v599[6];
  int * v601 = v594->cache_tags;
  int v712 = (((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2;
  int v602 = v601[v712];
  int v713 = ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + 1;
  int v603 = v601[v713];
  int v714 = 4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2);
  int v604 = v601[v714];
  int v715 = (4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v605 = v601[v715];
  int * v606 = v594->cache_vals;
  bool v716 = !(((~(((v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) == 0);
  int v699;
  if (v716) {
    int * v607 = v594->cache_age;
    int v718 = ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) & 1);
    int v608 = v607[v718];
    int v609 = v607[v712];
    int v719 = v609 + ((int)((unsigned int)(v609 - v608) >> 31));
    v607[v712] = v719;
    int * v611 = v594->cache_age;
    int v612 = v611[v713];
    int v721 = v612 + ((int)((unsigned int)(v612 - v608) >> 31));
    v611[v713] = v721;
    int * v614 = v594->cache_age;
    v614[v718] = 0;
    v699 = v718;
  } else {
    int * v617 = v594->cache_age;
    int v725 = (((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2;
    int v618 = v617[v725];
    int * v619 = v594->cache_tags;
    int v620 = v619[v725];
    int v621 = v617[v713];
    int v622 = v619[v713];
    bool v727 = !(((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) == 0);
    int v676;
    if (v727) {
      int * v623 = v594->cache_age;
      int v729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) & 1);
      int v624 = v623[v729];
      int v625 = v623[v714];
      int v730 = v625 + ((int)((unsigned int)(v625 - v624) >> 31));
      v623[v714] = v730;
      int * v627 = v594->cache_age;
      int v628 = v627[v715];
      int v732 = v628 + ((int)((unsigned int)(v628 - v624) >> 31));
      v627[v715] = v732;
      int * v630 = v594->cache_age;
      v630[v729] = 0;
      v676 = v729;
    } else {
      int * v633 = v594->cache_age;
      int v736 = 4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2);
      int v634 = v633[v736];
      int * v635 = v594->cache_tags;
      int v636 = v635[v736];
      int v637 = v633[v715];
      int v638 = v635[v715];
      int * v639 = v594->cache_dirty;
      int v739 = (4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v640 = v639[v739];
      bool v740 = !(v640 == 0);
      if (v740) {
        int * v641 = v594->cache_tags;
        int v642 = v641[v739];
        int * v643 = v594->cache_vals;
        int v743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v644 = v643[v743];
        int v744 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v645 = v643[v744];
        int * v646 = v594->mem;
        int v746 = v642 * 2;
        v646[v746] = v644;
        int * v648 = v594->mem;
        int v749 = (v642 * 2) + 1;
        v648[v749] = v645;
        ;
      } else {
        ;
      }
      int * v653 = v594->mem;
      int v754 = ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) * 2;
      int v654 = v653[v754];
      int v755 = (((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) * 2) + 1;
      int v655 = v653[v755];
      int * v656 = v594->cache_vals;
      int v757 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v656[v757] = v654;
      int * v658 = v594->cache_vals;
      int v760 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 3) * 2)) + ((((v634 + ((~(((v636 ^ -1) | (-(v636 ^ -1))) >> 31)) & 2)) - (v637 + ((~(((v638 ^ -1) | (-(v638 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v658[v760] = v655;
      int * v660 = v594->cache_tags;
      int v763 = (int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1);
      v660[v739] = v763;
      int * v662 = v594->cache_dirty;
      v662[v739] = 0;
      int * v664 = v594->cache_age;
      v664[v739] = 1;
      int * v666 = v594->cache_age;
      int v667 = v666[v739];
      int v668 = v666[v714];
      int v769 = v668 + ((int)((unsigned int)(v668 - v667) >> 31));
      v666[v714] = v769;
      int * v670 = v594->cache_age;
      int v671 = v670[v715];
      int v771 = v671 + ((int)((unsigned int)(v671 - v667) >> 31));
      v670[v715] = v771;
      int * v673 = v594->cache_age;
      v673[v739] = 0;
      v676 = v739;
    }
    int * v677 = v594->cache_vals;
    int v774 = v676 * 2;
    int v678 = v677[v774];
    int v775 = (v676 * 2) + 1;
    int v679 = v677[v775];
    int v776 = (((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v677[v776] = v678;
    int * v681 = v594->cache_vals;
    int v779 = ((((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v681[v779] = v679;
    int * v683 = v594->cache_tags;
    int v782 = ((((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1)) & 1) * 2) + ((((v618 + ((~(((v620 ^ -1) | (-(v620 ^ -1))) >> 31)) & 2)) - (v621 + ((~(((v622 ^ -1) | (-(v622 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v783 = (int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1);
    v683[v782] = v783;
    int * v685 = v594->cache_dirty;
    v685[v782] = 0;
    int * v687 = v594->cache_age;
    v687[v782] = 1;
    int * v689 = v594->cache_age;
    int v690 = v689[v782];
    int v691 = v689[v712];
    int v789 = v691 + ((int)((unsigned int)(v691 - v690) >> 31));
    v689[v712] = v789;
    int * v693 = v594->cache_age;
    int v694 = v693[v713];
    int v791 = v694 + ((int)((unsigned int)(v694 - v690) >> 31));
    v693[v713] = v791;
    int * v696 = v594->cache_age;
    v696[v782] = 0;
    v699 = v782;
  }
  int v794 = (v699 * 2) + (((int)((unsigned int)v600 >> 2)) & 1);
  int v700 = v606[v794];
  int * v701 = v594->reg_ready;
  int v797 = ((v598 + ((v595 - v598) & (~((v595 - v598) >> 31)))) + 1) + ((100 ^ (((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v602 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v603 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v604 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31)) | (~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v600 >> 2)) >> 1))))) >> 31))) & 104)))));
  v701[7] = v797;
  int * v703 = v594->regs;
  v703[7] = v700;
  struct StateT * v705 = slot_12(v594);
  return v705;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}