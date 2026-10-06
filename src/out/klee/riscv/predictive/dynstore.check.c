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

struct StateT * slot_12(struct StateT * v860);
struct StateT * slot_14(struct StateT * v892);
struct StateT * slot_6(struct StateT * v284);
struct StateT * slot_2(struct StateT * v28);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v838);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v319);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_9(struct StateT * v634);
struct StateT * slot_11(struct StateT * v852);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v860) {
  int v861 = v860->timer;
  int v865 = v861 + 1;
  v860->timer = v865;
  struct StateT * v863 = slot_4(v860);
  return v863;
}

struct StateT * slot_14(struct StateT * v892) {
  int * v893 = v892->saved_regs;
  int * v894 = v892->regs;
  int v895 = v894[5];
  v893[5] = v895;
  int v897 = v892->timer;
  int v1011 = v897 + 1;
  v892->timer = v1011;
  int * v899 = v892->regs;
  int v900 = v899[8];
  int * v901 = v892->cache_tags;
  int v1015 = (((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2;
  int v902 = v901[v1015];
  int v1016 = ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2) + 1;
  int v903 = v901[v1016];
  int v1017 = 4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2);
  int v904 = v901[v1017];
  int v1018 = (4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v905 = v901[v1018];
  int v906 = v892->timer;
  int v1019 = v906 + ((100 ^ (((~(((v904 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v904 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v902 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v902 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) | (~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v904 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v904 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31))) & 104)))));
  v892->timer = v1019;
  int * v908 = v892->cache_vals;
  bool v1020 = !(((~(((v902 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v902 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) | (~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31))) == 0);
  int v1001;
  if (v1020) {
    int * v909 = v892->cache_age;
    int v1022 = ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2) + ((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) & 1);
    int v910 = v909[v1022];
    int v911 = v909[v1015];
    int v1023 = v911 + ((int)((unsigned int)(v911 - v910) >> 31));
    v909[v1015] = v1023;
    int * v913 = v892->cache_age;
    int v914 = v913[v1016];
    int v1025 = v914 + ((int)((unsigned int)(v914 - v910) >> 31));
    v913[v1016] = v1025;
    int * v916 = v892->cache_age;
    v916[v1022] = 0;
    v1001 = v1022;
  } else {
    int * v919 = v892->cache_age;
    int v1029 = (((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2;
    int v920 = v919[v1029];
    int * v921 = v892->cache_tags;
    int v922 = v921[v1029];
    int v923 = v919[v1016];
    int v924 = v921[v1016];
    bool v1031 = !(((~(((v904 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v904 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31))) == 0);
    int v978;
    if (v1031) {
      int * v925 = v892->cache_age;
      int v1033 = (4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + ((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1))))) >> 31)) & 1);
      int v926 = v925[v1033];
      int v927 = v925[v1017];
      int v1034 = v927 + ((int)((unsigned int)(v927 - v926) >> 31));
      v925[v1017] = v1034;
      int * v929 = v892->cache_age;
      int v930 = v929[v1018];
      int v1036 = v930 + ((int)((unsigned int)(v930 - v926) >> 31));
      v929[v1018] = v1036;
      int * v932 = v892->cache_age;
      v932[v1033] = 0;
      v978 = v1033;
    } else {
      int * v935 = v892->cache_age;
      int v1040 = 4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2);
      int v936 = v935[v1040];
      int * v937 = v892->cache_tags;
      int v938 = v937[v1040];
      int v939 = v935[v1018];
      int v940 = v937[v1018];
      int * v941 = v892->cache_dirty;
      int v1043 = (4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v942 = v941[v1043];
      bool v1044 = !(v942 == 0);
      if (v1044) {
        int * v943 = v892->cache_tags;
        int v944 = v943[v1043];
        int * v945 = v892->cache_vals;
        int v1047 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v946 = v945[v1047];
        int v1048 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v947 = v945[v1048];
        int * v948 = v892->mem;
        int v1050 = v944 * 2;
        v948[v1050] = v946;
        int * v950 = v892->mem;
        int v1053 = (v944 * 2) + 1;
        v950[v1053] = v947;
        ;
      } else {
        ;
      }
      int * v955 = v892->mem;
      int v1058 = ((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) * 2;
      int v956 = v955[v1058];
      int v1059 = (((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) * 2) + 1;
      int v957 = v955[v1059];
      int * v958 = v892->cache_vals;
      int v1061 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v958[v1061] = v956;
      int * v960 = v892->cache_vals;
      int v1064 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v960[v1064] = v957;
      int * v962 = v892->cache_tags;
      int v1067 = (int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1);
      v962[v1043] = v1067;
      int * v964 = v892->cache_dirty;
      v964[v1043] = 0;
      int * v966 = v892->cache_age;
      v966[v1043] = 1;
      int * v968 = v892->cache_age;
      int v969 = v968[v1043];
      int v970 = v968[v1017];
      int v1073 = v970 + ((int)((unsigned int)(v970 - v969) >> 31));
      v968[v1017] = v1073;
      int * v972 = v892->cache_age;
      int v973 = v972[v1018];
      int v1075 = v973 + ((int)((unsigned int)(v973 - v969) >> 31));
      v972[v1018] = v1075;
      int * v975 = v892->cache_age;
      v975[v1043] = 0;
      v978 = v1043;
    }
    int * v979 = v892->cache_vals;
    int v1078 = v978 * 2;
    int v980 = v979[v1078];
    int v1079 = (v978 * 2) + 1;
    int v981 = v979[v1079];
    int v1080 = (((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2) + ((((v920 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2)) - (v923 + ((~(((v924 ^ -1) | (-(v924 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v979[v1080] = v980;
    int * v983 = v892->cache_vals;
    int v1083 = ((((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2) + ((((v920 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2)) - (v923 + ((~(((v924 ^ -1) | (-(v924 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v983[v1083] = v981;
    int * v985 = v892->cache_tags;
    int v1086 = ((((int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1)) & 1) * 2) + ((((v920 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2)) - (v923 + ((~(((v924 ^ -1) | (-(v924 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1087 = (int)((unsigned int)((int)((unsigned int)v900 >> 2)) >> 1);
    v985[v1086] = v1087;
    int * v987 = v892->cache_dirty;
    v987[v1086] = 0;
    int * v989 = v892->cache_age;
    v989[v1086] = 1;
    int * v991 = v892->cache_age;
    int v992 = v991[v1086];
    int v993 = v991[v1015];
    int v1093 = v993 + ((int)((unsigned int)(v993 - v992) >> 31));
    v991[v1015] = v1093;
    int * v995 = v892->cache_age;
    int v996 = v995[v1016];
    int v1095 = v996 + ((int)((unsigned int)(v996 - v992) >> 31));
    v995[v1016] = v1095;
    int * v998 = v892->cache_age;
    v998[v1086] = 0;
    v1001 = v1086;
  }
  int v1098 = (v1001 * 2) + (((int)((unsigned int)v900 >> 2)) & 1);
  int v1002 = v908[v1098];
  int * v1003 = v892->regs;
  v1003[5] = v1002;
  struct StateT * v1005 = slot_6(v892);
  return v1005;
}

struct StateT * slot_6(struct StateT * v284) {
  int * v285 = v284->regs;
  int v286 = v285[6];
  int v287 = v285[7];
  bool v306 = v286 >= v287;
  struct StateT * v301;
  if (v306) {
    int v288 = v284->timer;
    int v307 = v288 + 15;
    v284->timer = v307;
    int * v290 = v284->saved_regs;
    int v291 = v290[8];
    int * v292 = v284->regs;
    v292[8] = v291;
    int * v294 = v284->saved_regs;
    int v295 = v294[5];
    int * v296 = v284->regs;
    v296[5] = v295;
    v301 = v284;
  } else {
    struct StateT * v299 = slot_8(v284);
    v301 = v299;
  }
  return v301;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_12(v28);
  return v33;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v838) {
  int v839 = v838->timer;
  int v846 = v839 + 1;
  v838->timer = v846;
  int * v841 = v838->regs;
  int v842 = v841[6];
  int v849 = v842 + 4;
  v841[6] = v849;
  struct StateT * v844 = slot_11(v838);
  return v844;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v319) {
  int v320 = v319->timer;
  int v490 = v320 + 1;
  v319->timer = v490;
  int * v322 = v319->regs;
  int v323 = v322[6];
  int v324 = v322[5];
  int * v325 = v319->cache_tags;
  int v495 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2;
  int v326 = v325[v495];
  int v496 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + 1;
  int v327 = v325[v496];
  int v497 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
  int v328 = v325[v497];
  int v498 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v329 = v325[v498];
  int v330 = v319->timer;
  int v499 = v330 + ((100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & 104)))));
  v319->timer = v499;
  bool v500 = !(((~(((v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v326 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
  int v424;
  if (v500) {
    int * v332 = v319->cache_age;
    int v502 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
    int v333 = v332[v502];
    int v334 = v332[v495];
    int v503 = v334 + ((int)((unsigned int)(v334 - v333) >> 31));
    v332[v495] = v503;
    int * v336 = v319->cache_age;
    int v337 = v336[v496];
    int v505 = v337 + ((int)((unsigned int)(v337 - v333) >> 31));
    v336[v496] = v505;
    int * v339 = v319->cache_age;
    v339[v502] = 0;
    v424 = v502;
  } else {
    int * v342 = v319->cache_age;
    int v509 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2;
    int v343 = v342[v509];
    int * v344 = v319->cache_tags;
    int v345 = v344[v509];
    int v346 = v342[v496];
    int v347 = v344[v496];
    bool v511 = !(((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
    int v401;
    if (v511) {
      int * v348 = v319->cache_age;
      int v513 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
      int v349 = v348[v513];
      int v350 = v348[v497];
      int v514 = v350 + ((int)((unsigned int)(v350 - v349) >> 31));
      v348[v497] = v514;
      int * v352 = v319->cache_age;
      int v353 = v352[v498];
      int v516 = v353 + ((int)((unsigned int)(v353 - v349) >> 31));
      v352[v498] = v516;
      int * v355 = v319->cache_age;
      v355[v513] = 0;
      v401 = v513;
    } else {
      int * v358 = v319->cache_age;
      int v520 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
      int v359 = v358[v520];
      int * v360 = v319->cache_tags;
      int v361 = v360[v520];
      int v362 = v358[v498];
      int v363 = v360[v498];
      int * v364 = v319->cache_dirty;
      int v523 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v365 = v364[v523];
      bool v524 = !(v365 == 0);
      if (v524) {
        int * v366 = v319->cache_tags;
        int v367 = v366[v523];
        int * v368 = v319->cache_vals;
        int v527 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v369 = v368[v527];
        int v528 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v370 = v368[v528];
        int * v371 = v319->mem;
        int v530 = v367 * 2;
        v371[v530] = v369;
        int * v373 = v319->mem;
        int v533 = (v367 * 2) + 1;
        v373[v533] = v370;
        ;
      } else {
        ;
      }
      int * v378 = v319->mem;
      int v538 = ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2;
      int v379 = v378[v538];
      int v539 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2) + 1;
      int v380 = v378[v539];
      int * v381 = v319->cache_vals;
      int v541 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v381[v541] = v379;
      int * v383 = v319->cache_vals;
      int v544 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v359 + ((~(((v361 ^ -1) | (-(v361 ^ -1))) >> 31)) & 2)) - (v362 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v383[v544] = v380;
      int * v385 = v319->cache_tags;
      int v547 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
      v385[v523] = v547;
      int * v387 = v319->cache_dirty;
      v387[v523] = 0;
      int * v389 = v319->cache_age;
      v389[v523] = 1;
      int * v391 = v319->cache_age;
      int v392 = v391[v523];
      int v393 = v391[v497];
      int v553 = v393 + ((int)((unsigned int)(v393 - v392) >> 31));
      v391[v497] = v553;
      int * v395 = v319->cache_age;
      int v396 = v395[v498];
      int v555 = v396 + ((int)((unsigned int)(v396 - v392) >> 31));
      v395[v498] = v555;
      int * v398 = v319->cache_age;
      v398[v523] = 0;
      v401 = v523;
    }
    int * v402 = v319->cache_vals;
    int v558 = v401 * 2;
    int v403 = v402[v558];
    int v559 = (v401 * 2) + 1;
    int v404 = v402[v559];
    int v560 = (((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v402[v560] = v403;
    int * v406 = v319->cache_vals;
    int v563 = ((((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v406[v563] = v404;
    int * v408 = v319->cache_tags;
    int v566 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v343 + ((~(((v345 ^ -1) | (-(v345 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v567 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
    v408[v566] = v567;
    int * v410 = v319->cache_dirty;
    v410[v566] = 0;
    int * v412 = v319->cache_age;
    v412[v566] = 1;
    int * v414 = v319->cache_age;
    int v415 = v414[v566];
    int v416 = v414[v495];
    int v573 = v416 + ((int)((unsigned int)(v416 - v415) >> 31));
    v414[v495] = v573;
    int * v418 = v319->cache_age;
    int v419 = v418[v496];
    int v575 = v419 + ((int)((unsigned int)(v419 - v415) >> 31));
    v418[v496] = v575;
    int * v421 = v319->cache_age;
    v421[v566] = 0;
    v424 = v566;
  }
  int * v425 = v319->cache_vals;
  int v578 = (v424 * 2) + (((int)((unsigned int)v323 >> 2)) & 1);
  v425[v578] = v324;
  int * v427 = v319->cache_tags;
  int v428 = v427[v497];
  int v429 = v427[v498];
  bool v581 = !(((~(((v428 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v428 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
  int v483;
  if (v581) {
    int * v430 = v319->cache_age;
    int v583 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
    int v431 = v430[v583];
    int v432 = v430[v497];
    int v584 = v432 + ((int)((unsigned int)(v432 - v431) >> 31));
    v430[v497] = v584;
    int * v434 = v319->cache_age;
    int v435 = v434[v498];
    int v586 = v435 + ((int)((unsigned int)(v435 - v431) >> 31));
    v434[v498] = v586;
    int * v437 = v319->cache_age;
    v437[v583] = 0;
    v483 = v583;
  } else {
    int * v440 = v319->cache_age;
    int v590 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
    int v441 = v440[v590];
    int * v442 = v319->cache_tags;
    int v443 = v442[v590];
    int v444 = v440[v498];
    int v445 = v442[v498];
    int * v446 = v319->cache_dirty;
    int v593 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v447 = v446[v593];
    bool v594 = !(v447 == 0);
    if (v594) {
      int * v448 = v319->cache_tags;
      int v449 = v448[v593];
      int * v450 = v319->cache_vals;
      int v597 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v451 = v450[v597];
      int v598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v452 = v450[v598];
      int * v453 = v319->mem;
      int v600 = v449 * 2;
      v453[v600] = v451;
      int * v455 = v319->mem;
      int v603 = (v449 * 2) + 1;
      v455[v603] = v452;
      ;
    } else {
      ;
    }
    int * v460 = v319->mem;
    int v608 = ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2;
    int v461 = v460[v608];
    int v609 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2) + 1;
    int v462 = v460[v609];
    int * v463 = v319->cache_vals;
    int v611 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v463[v611] = v461;
    int * v465 = v319->cache_vals;
    int v614 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v441 + ((~(((v443 ^ -1) | (-(v443 ^ -1))) >> 31)) & 2)) - (v444 + ((~(((v445 ^ -1) | (-(v445 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v465[v614] = v462;
    int * v467 = v319->cache_tags;
    int v617 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
    v467[v593] = v617;
    int * v469 = v319->cache_dirty;
    v469[v593] = 0;
    int * v471 = v319->cache_age;
    v471[v593] = 1;
    int * v473 = v319->cache_age;
    int v474 = v473[v593];
    int v475 = v473[v497];
    int v623 = v475 + ((int)((unsigned int)(v475 - v474) >> 31));
    v473[v497] = v623;
    int * v477 = v319->cache_age;
    int v478 = v477[v498];
    int v625 = v478 + ((int)((unsigned int)(v478 - v474) >> 31));
    v477[v498] = v625;
    int * v480 = v319->cache_age;
    v480[v593] = 0;
    v483 = v593;
  }
  int * v484 = v319->cache_vals;
  int v628 = (v483 * 2) + (((int)((unsigned int)v323 >> 2)) & 1);
  v484[v628] = v324;
  int * v486 = v319->cache_dirty;
  v486[v483] = 1;
  struct StateT * v488 = slot_9(v319);
  return v488;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[8];
  v50[8] = v52;
  int v54 = v49->timer;
  int v66 = v54 + 1;
  v49->timer = v66;
  int * v56 = v49->regs;
  int v57 = v56[9];
  int v58 = v56[6];
  int v70 = v57 + v58;
  v56[8] = v70;
  struct StateT * v60 = slot_14(v49);
  return v60;
}

struct StateT * slot_9(struct StateT * v634) {
  int v635 = v634->timer;
  int v745 = v635 + 1;
  v634->timer = v745;
  int * v637 = v634->regs;
  int v638 = v637[6];
  int * v639 = v634->cache_tags;
  int v749 = (((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2;
  int v640 = v639[v749];
  int v750 = ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + 1;
  int v641 = v639[v750];
  int v751 = 4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2);
  int v642 = v639[v751];
  int v752 = (4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v643 = v639[v752];
  int v644 = v634->timer;
  int v753 = v644 + ((100 ^ (((~(((v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) & 104)))));
  v634->timer = v753;
  int * v646 = v634->cache_vals;
  bool v754 = !(((~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) == 0);
  int v739;
  if (v754) {
    int * v647 = v634->cache_age;
    int v756 = ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) & 1);
    int v648 = v647[v756];
    int v649 = v647[v749];
    int v757 = v649 + ((int)((unsigned int)(v649 - v648) >> 31));
    v647[v749] = v757;
    int * v651 = v634->cache_age;
    int v652 = v651[v750];
    int v759 = v652 + ((int)((unsigned int)(v652 - v648) >> 31));
    v651[v750] = v759;
    int * v654 = v634->cache_age;
    v654[v756] = 0;
    v739 = v756;
  } else {
    int * v657 = v634->cache_age;
    int v763 = (((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2;
    int v658 = v657[v763];
    int * v659 = v634->cache_tags;
    int v660 = v659[v763];
    int v661 = v657[v750];
    int v662 = v659[v750];
    bool v765 = !(((~(((v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v642 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) | (~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31))) == 0);
    int v716;
    if (v765) {
      int * v663 = v634->cache_age;
      int v767 = (4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((~(((v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))) | (-(v643 ^ ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1))))) >> 31)) & 1);
      int v664 = v663[v767];
      int v665 = v663[v751];
      int v768 = v665 + ((int)((unsigned int)(v665 - v664) >> 31));
      v663[v751] = v768;
      int * v667 = v634->cache_age;
      int v668 = v667[v752];
      int v770 = v668 + ((int)((unsigned int)(v668 - v664) >> 31));
      v667[v752] = v770;
      int * v670 = v634->cache_age;
      v670[v767] = 0;
      v716 = v767;
    } else {
      int * v673 = v634->cache_age;
      int v774 = 4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2);
      int v674 = v673[v774];
      int * v675 = v634->cache_tags;
      int v676 = v675[v774];
      int v677 = v673[v752];
      int v678 = v675[v752];
      int * v679 = v634->cache_dirty;
      int v777 = (4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v680 = v679[v777];
      bool v778 = !(v680 == 0);
      if (v778) {
        int * v681 = v634->cache_tags;
        int v682 = v681[v777];
        int * v683 = v634->cache_vals;
        int v781 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v684 = v683[v781];
        int v782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v685 = v683[v782];
        int * v686 = v634->mem;
        int v784 = v682 * 2;
        v686[v784] = v684;
        int * v688 = v634->mem;
        int v787 = (v682 * 2) + 1;
        v688[v787] = v685;
        ;
      } else {
        ;
      }
      int * v693 = v634->mem;
      int v792 = ((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) * 2;
      int v694 = v693[v792];
      int v793 = (((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) * 2) + 1;
      int v695 = v693[v793];
      int * v696 = v634->cache_vals;
      int v795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v696[v795] = v694;
      int * v698 = v634->cache_vals;
      int v798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 3) * 2)) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v698[v798] = v695;
      int * v700 = v634->cache_tags;
      int v801 = (int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1);
      v700[v777] = v801;
      int * v702 = v634->cache_dirty;
      v702[v777] = 0;
      int * v704 = v634->cache_age;
      v704[v777] = 1;
      int * v706 = v634->cache_age;
      int v707 = v706[v777];
      int v708 = v706[v751];
      int v807 = v708 + ((int)((unsigned int)(v708 - v707) >> 31));
      v706[v751] = v807;
      int * v710 = v634->cache_age;
      int v711 = v710[v752];
      int v809 = v711 + ((int)((unsigned int)(v711 - v707) >> 31));
      v710[v752] = v809;
      int * v713 = v634->cache_age;
      v713[v777] = 0;
      v716 = v777;
    }
    int * v717 = v634->cache_vals;
    int v812 = v716 * 2;
    int v718 = v717[v812];
    int v813 = (v716 * 2) + 1;
    int v719 = v717[v813];
    int v814 = (((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((((v658 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2)) - (v661 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v717[v814] = v718;
    int * v721 = v634->cache_vals;
    int v817 = ((((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((((v658 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2)) - (v661 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v721[v817] = v719;
    int * v723 = v634->cache_tags;
    int v820 = ((((int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1)) & 1) * 2) + ((((v658 + ((~(((v660 ^ -1) | (-(v660 ^ -1))) >> 31)) & 2)) - (v661 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v821 = (int)((unsigned int)((int)((unsigned int)v638 >> 2)) >> 1);
    v723[v820] = v821;
    int * v725 = v634->cache_dirty;
    v725[v820] = 0;
    int * v727 = v634->cache_age;
    v727[v820] = 1;
    int * v729 = v634->cache_age;
    int v730 = v729[v820];
    int v731 = v729[v749];
    int v827 = v731 + ((int)((unsigned int)(v731 - v730) >> 31));
    v729[v749] = v827;
    int * v733 = v634->cache_age;
    int v734 = v733[v750];
    int v829 = v734 + ((int)((unsigned int)(v734 - v730) >> 31));
    v733[v750] = v829;
    int * v736 = v634->cache_age;
    v736[v820] = 0;
    v739 = v820;
  }
  int v832 = (v739 * 2) + (((int)((unsigned int)v638 >> 2)) & 1);
  int v740 = v646[v832];
  int * v741 = v634->regs;
  v741[11] = v740;
  struct StateT * v743 = slot_10(v634);
  return v743;
}

struct StateT * slot_11(struct StateT * v852) {
  int v853 = v852->timer;
  int v857 = v853 + 1;
  v852->timer = v857;
  struct StateT * v855 = slot_12(v852);
  return v855;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
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