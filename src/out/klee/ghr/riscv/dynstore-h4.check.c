// verify: clean (KLEE should report no failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 128
#define HISTORY_BITS 4

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

struct StateG * slot_12(struct StateG * v904);
struct StateG * slot_14(struct StateG * v1122);
struct StateG * slot_5(struct StateG * v89);
struct StateG * slot_2(struct StateG * v28);
struct StateG * slot_7(struct StateG * v113);
struct StateG * slot_3(struct StateG * v41);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_10(struct StateG * v545);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_8(struct StateG * v130);
struct StateG * slot_4(struct StateG * v61);
struct StateG * slot_13(struct StateG * v1108);
struct StateG * slot_9(struct StateG * v341);
struct StateG * slot_11(struct StateG * v589);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_12(struct StateG * v904) {
  int v905 = v904->timer;
  int v1015 = v905 + 1;
  v904->timer = v1015;
  int * v907 = v904->regs;
  int v908 = v907[6];
  int * v909 = v904->cache_tags;
  int v1019 = (((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2;
  int v910 = v909[v1019];
  int v1020 = ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2) + 1;
  int v911 = v909[v1020];
  int v1021 = 4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2);
  int v912 = v909[v1021];
  int v1022 = (4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v913 = v909[v1022];
  int v914 = v904->timer;
  int v1023 = v914 + ((100 ^ (((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v910 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v910 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) | (~(((v911 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v911 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31))) & 104)))));
  v904->timer = v1023;
  int * v916 = v904->cache_vals;
  bool v1024 = !(((~(((v910 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v910 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) | (~(((v911 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v911 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31))) == 0);
  int v1009;
  if (v1024) {
    int * v917 = v904->cache_age;
    int v1026 = ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2) + ((~(((v911 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v911 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) & 1);
    int v918 = v917[v1026];
    int v919 = v917[v1019];
    int v1027 = v919 + ((int)((unsigned int)(v919 - v918) >> 31));
    v917[v1019] = v1027;
    int * v921 = v904->cache_age;
    int v922 = v921[v1020];
    int v1029 = v922 + ((int)((unsigned int)(v922 - v918) >> 31));
    v921[v1020] = v1029;
    int * v924 = v904->cache_age;
    v924[v1026] = 0;
    v1009 = v1026;
  } else {
    int * v927 = v904->cache_age;
    int v1033 = (((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2;
    int v928 = v927[v1033];
    int * v929 = v904->cache_tags;
    int v930 = v929[v1033];
    int v931 = v927[v1020];
    int v932 = v929[v1020];
    bool v1035 = !(((~(((v912 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v912 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) | (~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31))) == 0);
    int v986;
    if (v1035) {
      int * v933 = v904->cache_age;
      int v1037 = (4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + ((~(((v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))) | (-(v913 ^ ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1))))) >> 31)) & 1);
      int v934 = v933[v1037];
      int v935 = v933[v1021];
      int v1038 = v935 + ((int)((unsigned int)(v935 - v934) >> 31));
      v933[v1021] = v1038;
      int * v937 = v904->cache_age;
      int v938 = v937[v1022];
      int v1040 = v938 + ((int)((unsigned int)(v938 - v934) >> 31));
      v937[v1022] = v1040;
      int * v940 = v904->cache_age;
      v940[v1037] = 0;
      v986 = v1037;
    } else {
      int * v943 = v904->cache_age;
      int v1044 = 4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2);
      int v944 = v943[v1044];
      int * v945 = v904->cache_tags;
      int v946 = v945[v1044];
      int v947 = v943[v1022];
      int v948 = v945[v1022];
      int * v949 = v904->cache_dirty;
      int v1047 = (4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v947 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v950 = v949[v1047];
      bool v1048 = !(v950 == 0);
      if (v1048) {
        int * v951 = v904->cache_tags;
        int v952 = v951[v1047];
        int * v953 = v904->cache_vals;
        int v1051 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v947 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v954 = v953[v1051];
        int v1052 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v947 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v955 = v953[v1052];
        int * v956 = v904->mem;
        int v1054 = v952 * 2;
        v956[v1054] = v954;
        int * v958 = v904->mem;
        int v1057 = (v952 * 2) + 1;
        v958[v1057] = v955;
        ;
      } else {
        ;
      }
      int * v963 = v904->mem;
      int v1062 = ((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) * 2;
      int v964 = v963[v1062];
      int v1063 = (((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) * 2) + 1;
      int v965 = v963[v1063];
      int * v966 = v904->cache_vals;
      int v1065 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v947 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v966[v1065] = v964;
      int * v968 = v904->cache_vals;
      int v1068 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 3) * 2)) + ((((v944 + ((~(((v946 ^ -1) | (-(v946 ^ -1))) >> 31)) & 2)) - (v947 + ((~(((v948 ^ -1) | (-(v948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v968[v1068] = v965;
      int * v970 = v904->cache_tags;
      int v1071 = (int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1);
      v970[v1047] = v1071;
      int * v972 = v904->cache_dirty;
      v972[v1047] = 0;
      int * v974 = v904->cache_age;
      v974[v1047] = 1;
      int * v976 = v904->cache_age;
      int v977 = v976[v1047];
      int v978 = v976[v1021];
      int v1077 = v978 + ((int)((unsigned int)(v978 - v977) >> 31));
      v976[v1021] = v1077;
      int * v980 = v904->cache_age;
      int v981 = v980[v1022];
      int v1079 = v981 + ((int)((unsigned int)(v981 - v977) >> 31));
      v980[v1022] = v1079;
      int * v983 = v904->cache_age;
      v983[v1047] = 0;
      v986 = v1047;
    }
    int * v987 = v904->cache_vals;
    int v1082 = v986 * 2;
    int v988 = v987[v1082];
    int v1083 = (v986 * 2) + 1;
    int v989 = v987[v1083];
    int v1084 = (((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2) + ((((v928 + ((~(((v930 ^ -1) | (-(v930 ^ -1))) >> 31)) & 2)) - (v931 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v987[v1084] = v988;
    int * v991 = v904->cache_vals;
    int v1087 = ((((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2) + ((((v928 + ((~(((v930 ^ -1) | (-(v930 ^ -1))) >> 31)) & 2)) - (v931 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v991[v1087] = v989;
    int * v993 = v904->cache_tags;
    int v1090 = ((((int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1)) & 1) * 2) + ((((v928 + ((~(((v930 ^ -1) | (-(v930 ^ -1))) >> 31)) & 2)) - (v931 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1091 = (int)((unsigned int)((int)((unsigned int)v908 >> 2)) >> 1);
    v993[v1090] = v1091;
    int * v995 = v904->cache_dirty;
    v995[v1090] = 0;
    int * v997 = v904->cache_age;
    v997[v1090] = 1;
    int * v999 = v904->cache_age;
    int v1000 = v999[v1090];
    int v1001 = v999[v1019];
    int v1097 = v1001 + ((int)((unsigned int)(v1001 - v1000) >> 31));
    v999[v1019] = v1097;
    int * v1003 = v904->cache_age;
    int v1004 = v1003[v1020];
    int v1099 = v1004 + ((int)((unsigned int)(v1004 - v1000) >> 31));
    v1003[v1020] = v1099;
    int * v1006 = v904->cache_age;
    v1006[v1090] = 0;
    v1009 = v1090;
  }
  int v1102 = (v1009 * 2) + (((int)((unsigned int)v908 >> 2)) & 1);
  int v1010 = v916[v1102];
  int * v1011 = v904->regs;
  v1011[11] = v1010;
  struct StateG * v1013 = slot_13(v904);
  return v1013;
}

struct StateG * slot_14(struct StateG * v1122) {
  int v1123 = v1122->timer;
  int v1127 = v1123 + 1;
  v1122->timer = v1127;
  struct StateG * v1125 = slot_3(v1122);
  return v1125;
}

struct StateG * slot_5(struct StateG * v89) {
  int * v90 = v89->saved_regs;
  int * v91 = v89->regs;
  int v92 = v91[8];
  v90[8] = v92;
  int v94 = v89->timer;
  int v106 = v94 + 1;
  v89->timer = v106;
  int * v96 = v89->regs;
  int v97 = v96[9];
  int v98 = v96[6];
  int v110 = v97 + v98;
  v96[8] = v110;
  struct StateG * v100 = slot_8(v89);
  return v100;
}

struct StateG * slot_2(struct StateG * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateG * v33 = slot_3(v28);
  return v33;
}

struct StateG * slot_7(struct StateG * v113) {
  int v114 = v113->timer;
  int v122 = v114 + 1;
  v113->timer = v122;
  int * v116 = v113->regs;
  int v117 = v116[9];
  int v118 = v116[6];
  int v127 = v117 + v118;
  v116[8] = v127;
  struct StateG * v120 = slot_9(v113);
  return v120;
}

struct StateG * slot_3(struct StateG * v41) {
  int v42 = v41->timer;
  int v52 = v42 + 1;
  v41->timer = v52;
  int * v44 = v41->pht;
  int v45 = v44[0];
  bool v55 = !(v45 == 0);
  struct StateG * v50;
  if (v55) {
    struct StateG * v46 = slot_4(v41);
    v50 = v46;
  } else {
    struct StateG * v48 = slot_5(v41);
    v50 = v48;
  }
  return v50;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_10(struct StateG * v545) {
  int * v546 = v545->regs;
  int v547 = v546[6];
  int v548 = v546[7];
  bool v571 = v547 >= v548;
  struct StateG * v566;
  if (v571) {
    int * v549 = v545->pht;
    v549[0] = 1;
    int v551 = v545->timer;
    int v575 = v551 + 15;
    v545->timer = v575;
    int * v553 = v545->saved_regs;
    int v554 = v553[8];
    int * v555 = v545->regs;
    v555[8] = v554;
    int * v557 = v545->saved_regs;
    int v558 = v557[5];
    int * v559 = v545->regs;
    v559[5] = v558;
    v566 = v545;
  } else {
    int * v562 = v545->pht;
    v562[0] = 0;
    struct StateG * v564 = slot_11(v545);
    v566 = v564;
  }
  return v566;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateG * v20 = slot_2(v15);
  return v20;
}

struct StateG * slot_8(struct StateG * v130) {
  int * v131 = v130->saved_regs;
  int * v132 = v130->regs;
  int v133 = v132[5];
  v131[5] = v133;
  int v135 = v130->timer;
  int v249 = v135 + 1;
  v130->timer = v249;
  int * v137 = v130->regs;
  int v138 = v137[8];
  int * v139 = v130->cache_tags;
  int v253 = (((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2;
  int v140 = v139[v253];
  int v254 = ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + 1;
  int v141 = v139[v254];
  int v255 = 4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2);
  int v142 = v139[v255];
  int v256 = (4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v143 = v139[v256];
  int v144 = v130->timer;
  int v257 = v144 + ((100 ^ (((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) & 104)))));
  v130->timer = v257;
  int * v146 = v130->cache_vals;
  bool v258 = !(((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) == 0);
  int v239;
  if (v258) {
    int * v147 = v130->cache_age;
    int v260 = ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) & 1);
    int v148 = v147[v260];
    int v149 = v147[v253];
    int v261 = v149 + ((int)((unsigned int)(v149 - v148) >> 31));
    v147[v253] = v261;
    int * v151 = v130->cache_age;
    int v152 = v151[v254];
    int v263 = v152 + ((int)((unsigned int)(v152 - v148) >> 31));
    v151[v254] = v263;
    int * v154 = v130->cache_age;
    v154[v260] = 0;
    v239 = v260;
  } else {
    int * v157 = v130->cache_age;
    int v267 = (((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2;
    int v158 = v157[v267];
    int * v159 = v130->cache_tags;
    int v160 = v159[v267];
    int v161 = v157[v254];
    int v162 = v159[v254];
    bool v269 = !(((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) == 0);
    int v216;
    if (v269) {
      int * v163 = v130->cache_age;
      int v271 = (4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) & 1);
      int v164 = v163[v271];
      int v165 = v163[v255];
      int v272 = v165 + ((int)((unsigned int)(v165 - v164) >> 31));
      v163[v255] = v272;
      int * v167 = v130->cache_age;
      int v168 = v167[v256];
      int v274 = v168 + ((int)((unsigned int)(v168 - v164) >> 31));
      v167[v256] = v274;
      int * v170 = v130->cache_age;
      v170[v271] = 0;
      v216 = v271;
    } else {
      int * v173 = v130->cache_age;
      int v278 = 4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2);
      int v174 = v173[v278];
      int * v175 = v130->cache_tags;
      int v176 = v175[v278];
      int v177 = v173[v256];
      int v178 = v175[v256];
      int * v179 = v130->cache_dirty;
      int v281 = (4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v180 = v179[v281];
      bool v282 = !(v180 == 0);
      if (v282) {
        int * v181 = v130->cache_tags;
        int v182 = v181[v281];
        int * v183 = v130->cache_vals;
        int v285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v184 = v183[v285];
        int v286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v185 = v183[v286];
        int * v186 = v130->mem;
        int v288 = v182 * 2;
        v186[v288] = v184;
        int * v188 = v130->mem;
        int v291 = (v182 * 2) + 1;
        v188[v291] = v185;
        ;
      } else {
        ;
      }
      int * v193 = v130->mem;
      int v296 = ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) * 2;
      int v194 = v193[v296];
      int v297 = (((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) * 2) + 1;
      int v195 = v193[v297];
      int * v196 = v130->cache_vals;
      int v299 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v196[v299] = v194;
      int * v198 = v130->cache_vals;
      int v302 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v198[v302] = v195;
      int * v200 = v130->cache_tags;
      int v305 = (int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1);
      v200[v281] = v305;
      int * v202 = v130->cache_dirty;
      v202[v281] = 0;
      int * v204 = v130->cache_age;
      v204[v281] = 1;
      int * v206 = v130->cache_age;
      int v207 = v206[v281];
      int v208 = v206[v255];
      int v311 = v208 + ((int)((unsigned int)(v208 - v207) >> 31));
      v206[v255] = v311;
      int * v210 = v130->cache_age;
      int v211 = v210[v256];
      int v313 = v211 + ((int)((unsigned int)(v211 - v207) >> 31));
      v210[v256] = v313;
      int * v213 = v130->cache_age;
      v213[v281] = 0;
      v216 = v281;
    }
    int * v217 = v130->cache_vals;
    int v316 = v216 * 2;
    int v218 = v217[v316];
    int v317 = (v216 * 2) + 1;
    int v219 = v217[v317];
    int v318 = (((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v217[v318] = v218;
    int * v221 = v130->cache_vals;
    int v321 = ((((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v221[v321] = v219;
    int * v223 = v130->cache_tags;
    int v324 = ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v325 = (int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1);
    v223[v324] = v325;
    int * v225 = v130->cache_dirty;
    v225[v324] = 0;
    int * v227 = v130->cache_age;
    v227[v324] = 1;
    int * v229 = v130->cache_age;
    int v230 = v229[v324];
    int v231 = v229[v253];
    int v331 = v231 + ((int)((unsigned int)(v231 - v230) >> 31));
    v229[v253] = v331;
    int * v233 = v130->cache_age;
    int v234 = v233[v254];
    int v333 = v234 + ((int)((unsigned int)(v234 - v230) >> 31));
    v233[v254] = v333;
    int * v236 = v130->cache_age;
    v236[v324] = 0;
    v239 = v324;
  }
  int v336 = (v239 * 2) + (((int)((unsigned int)v138 >> 2)) & 1);
  int v240 = v146[v336];
  int * v241 = v130->regs;
  v241[5] = v240;
  struct StateG * v243 = slot_10(v130);
  return v243;
}

struct StateG * slot_4(struct StateG * v61) {
  int * v62 = v61->regs;
  int v63 = v62[6];
  int v64 = v62[7];
  bool v79 = v63 >= v64;
  struct StateG * v74;
  if (v79) {
    int * v65 = v61->pht;
    v65[0] = 1;
    v74 = v61;
  } else {
    int * v68 = v61->pht;
    v68[0] = 0;
    int v70 = v61->timer;
    int v85 = v70 + 15;
    v61->timer = v85;
    struct StateG * v72 = slot_7(v61);
    v74 = v72;
  }
  return v74;
}

struct StateG * slot_13(struct StateG * v1108) {
  int v1109 = v1108->timer;
  int v1116 = v1109 + 1;
  v1108->timer = v1116;
  int * v1111 = v1108->regs;
  int v1112 = v1111[6];
  int v1119 = v1112 + 4;
  v1111[6] = v1119;
  struct StateG * v1114 = slot_14(v1108);
  return v1114;
}

struct StateG * slot_9(struct StateG * v341) {
  int v342 = v341->timer;
  int v452 = v342 + 1;
  v341->timer = v452;
  int * v344 = v341->regs;
  int v345 = v344[8];
  int * v346 = v341->cache_tags;
  int v456 = (((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2;
  int v347 = v346[v456];
  int v457 = ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + 1;
  int v348 = v346[v457];
  int v458 = 4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2);
  int v349 = v346[v458];
  int v459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v350 = v346[v459];
  int v351 = v341->timer;
  int v460 = v351 + ((100 ^ (((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) & 104)))));
  v341->timer = v460;
  int * v353 = v341->cache_vals;
  bool v461 = !(((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) == 0);
  int v446;
  if (v461) {
    int * v354 = v341->cache_age;
    int v463 = ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) & 1);
    int v355 = v354[v463];
    int v356 = v354[v456];
    int v464 = v356 + ((int)((unsigned int)(v356 - v355) >> 31));
    v354[v456] = v464;
    int * v358 = v341->cache_age;
    int v359 = v358[v457];
    int v466 = v359 + ((int)((unsigned int)(v359 - v355) >> 31));
    v358[v457] = v466;
    int * v361 = v341->cache_age;
    v361[v463] = 0;
    v446 = v463;
  } else {
    int * v364 = v341->cache_age;
    int v470 = (((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2;
    int v365 = v364[v470];
    int * v366 = v341->cache_tags;
    int v367 = v366[v470];
    int v368 = v364[v457];
    int v369 = v366[v457];
    bool v472 = !(((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) == 0);
    int v423;
    if (v472) {
      int * v370 = v341->cache_age;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) & 1);
      int v371 = v370[v474];
      int v372 = v370[v458];
      int v475 = v372 + ((int)((unsigned int)(v372 - v371) >> 31));
      v370[v458] = v475;
      int * v374 = v341->cache_age;
      int v375 = v374[v459];
      int v477 = v375 + ((int)((unsigned int)(v375 - v371) >> 31));
      v374[v459] = v477;
      int * v377 = v341->cache_age;
      v377[v474] = 0;
      v423 = v474;
    } else {
      int * v380 = v341->cache_age;
      int v481 = 4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2);
      int v381 = v380[v481];
      int * v382 = v341->cache_tags;
      int v383 = v382[v481];
      int v384 = v380[v459];
      int v385 = v382[v459];
      int * v386 = v341->cache_dirty;
      int v484 = (4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v387 = v386[v484];
      bool v485 = !(v387 == 0);
      if (v485) {
        int * v388 = v341->cache_tags;
        int v389 = v388[v484];
        int * v390 = v341->cache_vals;
        int v488 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v391 = v390[v488];
        int v489 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v392 = v390[v489];
        int * v393 = v341->mem;
        int v491 = v389 * 2;
        v393[v491] = v391;
        int * v395 = v341->mem;
        int v494 = (v389 * 2) + 1;
        v395[v494] = v392;
        ;
      } else {
        ;
      }
      int * v400 = v341->mem;
      int v499 = ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) * 2;
      int v401 = v400[v499];
      int v500 = (((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) * 2) + 1;
      int v402 = v400[v500];
      int * v403 = v341->cache_vals;
      int v502 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v403[v502] = v401;
      int * v405 = v341->cache_vals;
      int v505 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v405[v505] = v402;
      int * v407 = v341->cache_tags;
      int v508 = (int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1);
      v407[v484] = v508;
      int * v409 = v341->cache_dirty;
      v409[v484] = 0;
      int * v411 = v341->cache_age;
      v411[v484] = 1;
      int * v413 = v341->cache_age;
      int v414 = v413[v484];
      int v415 = v413[v458];
      int v514 = v415 + ((int)((unsigned int)(v415 - v414) >> 31));
      v413[v458] = v514;
      int * v417 = v341->cache_age;
      int v418 = v417[v459];
      int v516 = v418 + ((int)((unsigned int)(v418 - v414) >> 31));
      v417[v459] = v516;
      int * v420 = v341->cache_age;
      v420[v484] = 0;
      v423 = v484;
    }
    int * v424 = v341->cache_vals;
    int v519 = v423 * 2;
    int v425 = v424[v519];
    int v520 = (v423 * 2) + 1;
    int v426 = v424[v520];
    int v521 = (((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v424[v521] = v425;
    int * v428 = v341->cache_vals;
    int v524 = ((((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v428[v524] = v426;
    int * v430 = v341->cache_tags;
    int v527 = ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v528 = (int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1);
    v430[v527] = v528;
    int * v432 = v341->cache_dirty;
    v432[v527] = 0;
    int * v434 = v341->cache_age;
    v434[v527] = 1;
    int * v436 = v341->cache_age;
    int v437 = v436[v527];
    int v438 = v436[v456];
    int v534 = v438 + ((int)((unsigned int)(v438 - v437) >> 31));
    v436[v456] = v534;
    int * v440 = v341->cache_age;
    int v441 = v440[v457];
    int v536 = v441 + ((int)((unsigned int)(v441 - v437) >> 31));
    v440[v457] = v536;
    int * v443 = v341->cache_age;
    v443[v527] = 0;
    v446 = v527;
  }
  int v539 = (v446 * 2) + (((int)((unsigned int)v345 >> 2)) & 1);
  int v447 = v353[v539];
  int * v448 = v341->regs;
  v448[5] = v447;
  struct StateG * v450 = slot_11(v341);
  return v450;
}

struct StateG * slot_11(struct StateG * v589) {
  int v590 = v589->timer;
  int v760 = v590 + 1;
  v589->timer = v760;
  int * v592 = v589->regs;
  int v593 = v592[6];
  int v594 = v592[5];
  int * v595 = v589->cache_tags;
  int v765 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2;
  int v596 = v595[v765];
  int v766 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + 1;
  int v597 = v595[v766];
  int v767 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
  int v598 = v595[v767];
  int v768 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v599 = v595[v768];
  int v600 = v589->timer;
  int v769 = v600 + ((100 ^ (((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) & 104)))));
  v589->timer = v769;
  bool v770 = !(((~(((v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v596 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
  int v694;
  if (v770) {
    int * v602 = v589->cache_age;
    int v772 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((~(((v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v597 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
    int v603 = v602[v772];
    int v604 = v602[v765];
    int v773 = v604 + ((int)((unsigned int)(v604 - v603) >> 31));
    v602[v765] = v773;
    int * v606 = v589->cache_age;
    int v607 = v606[v766];
    int v775 = v607 + ((int)((unsigned int)(v607 - v603) >> 31));
    v606[v766] = v775;
    int * v609 = v589->cache_age;
    v609[v772] = 0;
    v694 = v772;
  } else {
    int * v612 = v589->cache_age;
    int v779 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2;
    int v613 = v612[v779];
    int * v614 = v589->cache_tags;
    int v615 = v614[v779];
    int v616 = v612[v766];
    int v617 = v614[v766];
    bool v781 = !(((~(((v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v598 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
    int v671;
    if (v781) {
      int * v618 = v589->cache_age;
      int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((~(((v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v599 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
      int v619 = v618[v783];
      int v620 = v618[v767];
      int v784 = v620 + ((int)((unsigned int)(v620 - v619) >> 31));
      v618[v767] = v784;
      int * v622 = v589->cache_age;
      int v623 = v622[v768];
      int v786 = v623 + ((int)((unsigned int)(v623 - v619) >> 31));
      v622[v768] = v786;
      int * v625 = v589->cache_age;
      v625[v783] = 0;
      v671 = v783;
    } else {
      int * v628 = v589->cache_age;
      int v790 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
      int v629 = v628[v790];
      int * v630 = v589->cache_tags;
      int v631 = v630[v790];
      int v632 = v628[v768];
      int v633 = v630[v768];
      int * v634 = v589->cache_dirty;
      int v793 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v635 = v634[v793];
      bool v794 = !(v635 == 0);
      if (v794) {
        int * v636 = v589->cache_tags;
        int v637 = v636[v793];
        int * v638 = v589->cache_vals;
        int v797 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v639 = v638[v797];
        int v798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v640 = v638[v798];
        int * v641 = v589->mem;
        int v800 = v637 * 2;
        v641[v800] = v639;
        int * v643 = v589->mem;
        int v803 = (v637 * 2) + 1;
        v643[v803] = v640;
        ;
      } else {
        ;
      }
      int * v648 = v589->mem;
      int v808 = ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2;
      int v649 = v648[v808];
      int v809 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2) + 1;
      int v650 = v648[v809];
      int * v651 = v589->cache_vals;
      int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v651[v811] = v649;
      int * v653 = v589->cache_vals;
      int v814 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v629 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2)) - (v632 + ((~(((v633 ^ -1) | (-(v633 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v653[v814] = v650;
      int * v655 = v589->cache_tags;
      int v817 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
      v655[v793] = v817;
      int * v657 = v589->cache_dirty;
      v657[v793] = 0;
      int * v659 = v589->cache_age;
      v659[v793] = 1;
      int * v661 = v589->cache_age;
      int v662 = v661[v793];
      int v663 = v661[v767];
      int v823 = v663 + ((int)((unsigned int)(v663 - v662) >> 31));
      v661[v767] = v823;
      int * v665 = v589->cache_age;
      int v666 = v665[v768];
      int v825 = v666 + ((int)((unsigned int)(v666 - v662) >> 31));
      v665[v768] = v825;
      int * v668 = v589->cache_age;
      v668[v793] = 0;
      v671 = v793;
    }
    int * v672 = v589->cache_vals;
    int v828 = v671 * 2;
    int v673 = v672[v828];
    int v829 = (v671 * 2) + 1;
    int v674 = v672[v829];
    int v830 = (((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v672[v830] = v673;
    int * v676 = v589->cache_vals;
    int v833 = ((((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v676[v833] = v674;
    int * v678 = v589->cache_tags;
    int v836 = ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 1) * 2) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v837 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
    v678[v836] = v837;
    int * v680 = v589->cache_dirty;
    v680[v836] = 0;
    int * v682 = v589->cache_age;
    v682[v836] = 1;
    int * v684 = v589->cache_age;
    int v685 = v684[v836];
    int v686 = v684[v765];
    int v843 = v686 + ((int)((unsigned int)(v686 - v685) >> 31));
    v684[v765] = v843;
    int * v688 = v589->cache_age;
    int v689 = v688[v766];
    int v845 = v689 + ((int)((unsigned int)(v689 - v685) >> 31));
    v688[v766] = v845;
    int * v691 = v589->cache_age;
    v691[v836] = 0;
    v694 = v836;
  }
  int * v695 = v589->cache_vals;
  int v848 = (v694 * 2) + (((int)((unsigned int)v593 >> 2)) & 1);
  v695[v848] = v594;
  int * v697 = v589->cache_tags;
  int v698 = v697[v767];
  int v699 = v697[v768];
  bool v851 = !(((~(((v698 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v698 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) | (~(((v699 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v699 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31))) == 0);
  int v753;
  if (v851) {
    int * v700 = v589->cache_age;
    int v853 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((~(((v699 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))) | (-(v699 ^ ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1))))) >> 31)) & 1);
    int v701 = v700[v853];
    int v702 = v700[v767];
    int v854 = v702 + ((int)((unsigned int)(v702 - v701) >> 31));
    v700[v767] = v854;
    int * v704 = v589->cache_age;
    int v705 = v704[v768];
    int v856 = v705 + ((int)((unsigned int)(v705 - v701) >> 31));
    v704[v768] = v856;
    int * v707 = v589->cache_age;
    v707[v853] = 0;
    v753 = v853;
  } else {
    int * v710 = v589->cache_age;
    int v860 = 4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2);
    int v711 = v710[v860];
    int * v712 = v589->cache_tags;
    int v713 = v712[v860];
    int v714 = v710[v768];
    int v715 = v712[v768];
    int * v716 = v589->cache_dirty;
    int v863 = (4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v717 = v716[v863];
    bool v864 = !(v717 == 0);
    if (v864) {
      int * v718 = v589->cache_tags;
      int v719 = v718[v863];
      int * v720 = v589->cache_vals;
      int v867 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v721 = v720[v867];
      int v868 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v722 = v720[v868];
      int * v723 = v589->mem;
      int v870 = v719 * 2;
      v723[v870] = v721;
      int * v725 = v589->mem;
      int v873 = (v719 * 2) + 1;
      v725[v873] = v722;
      ;
    } else {
      ;
    }
    int * v730 = v589->mem;
    int v878 = ((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2;
    int v731 = v730[v878];
    int v879 = (((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) * 2) + 1;
    int v732 = v730[v879];
    int * v733 = v589->cache_vals;
    int v881 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v733[v881] = v731;
    int * v735 = v589->cache_vals;
    int v884 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1)) & 3) * 2)) + ((((v711 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2)) - (v714 + ((~(((v715 ^ -1) | (-(v715 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v735[v884] = v732;
    int * v737 = v589->cache_tags;
    int v887 = (int)((unsigned int)((int)((unsigned int)v593 >> 2)) >> 1);
    v737[v863] = v887;
    int * v739 = v589->cache_dirty;
    v739[v863] = 0;
    int * v741 = v589->cache_age;
    v741[v863] = 1;
    int * v743 = v589->cache_age;
    int v744 = v743[v863];
    int v745 = v743[v767];
    int v893 = v745 + ((int)((unsigned int)(v745 - v744) >> 31));
    v743[v767] = v893;
    int * v747 = v589->cache_age;
    int v748 = v747[v768];
    int v895 = v748 + ((int)((unsigned int)(v748 - v744) >> 31));
    v747[v768] = v895;
    int * v750 = v589->cache_age;
    v750[v863] = 0;
    v753 = v863;
  }
  int * v754 = v589->cache_vals;
  int v898 = (v753 * 2) + (((int)((unsigned int)v593 >> 2)) & 1);
  v754[v898] = v594;
  int * v756 = v589->cache_dirty;
  v756[v753] = 1;
  struct StateG * v758 = slot_12(v589);
  return v758;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
  struct StateG * v7 = slot_1(v2);
  return v7;
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