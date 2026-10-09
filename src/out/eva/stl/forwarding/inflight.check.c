// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_4(struct StateT * v976);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_3(struct StateT * v772);
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

struct StateT * slot_4(struct StateT * v976) {
  int v977 = v976->timer;
  int v1086 = v977 + 1;
  v976->timer = v1086;
  int * v979 = v976->regs;
  int v980 = v979[11];
  int * v981 = v976->cache_tags;
  int v1090 = (((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2;
  int v982 = v981[v1090];
  int v1091 = ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + 1;
  int v983 = v981[v1091];
  int v1092 = 4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2);
  int v984 = v981[v1092];
  int v1093 = (4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v985 = v981[v1093];
  int v986 = v976->timer;
  int v1094 = v986 + ((100 ^ (((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) & 104)))));
  v976->timer = v1094;
  int * v988 = v976->cache_vals;
  bool v1095 = !(((~(((v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v982 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) == 0);
  int v1081;
  if (v1095) {
    int * v989 = v976->cache_age;
    int v1097 = ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) & 1);
    int v990 = v989[v1097];
    int v991 = v989[v1090];
    int v1098 = v991 + ((int)((unsigned int)(v991 - v990) >> 31));
    v989[v1090] = v1098;
    int * v993 = v976->cache_age;
    int v994 = v993[v1091];
    int v1100 = v994 + ((int)((unsigned int)(v994 - v990) >> 31));
    v993[v1091] = v1100;
    int * v996 = v976->cache_age;
    v996[v1097] = 0;
    v1081 = v1097;
  } else {
    int * v999 = v976->cache_age;
    int v1104 = (((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2;
    int v1000 = v999[v1104];
    int * v1001 = v976->cache_tags;
    int v1002 = v1001[v1104];
    int v1003 = v999[v1091];
    int v1004 = v1001[v1091];
    bool v1106 = !(((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) | (~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31))) == 0);
    int v1058;
    if (v1106) {
      int * v1005 = v976->cache_age;
      int v1108 = (4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1))))) >> 31)) & 1);
      int v1006 = v1005[v1108];
      int v1007 = v1005[v1092];
      int v1109 = v1007 + ((int)((unsigned int)(v1007 - v1006) >> 31));
      v1005[v1092] = v1109;
      int * v1009 = v976->cache_age;
      int v1010 = v1009[v1093];
      int v1111 = v1010 + ((int)((unsigned int)(v1010 - v1006) >> 31));
      v1009[v1093] = v1111;
      int * v1012 = v976->cache_age;
      v1012[v1108] = 0;
      v1058 = v1108;
    } else {
      int * v1015 = v976->cache_age;
      int v1115 = 4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2);
      int v1016 = v1015[v1115];
      int * v1017 = v976->cache_tags;
      int v1018 = v1017[v1115];
      int v1019 = v1015[v1093];
      int v1020 = v1017[v1093];
      int * v1021 = v976->cache_dirty;
      int v1118 = (4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1022 = v1021[v1118];
      bool v1119 = !(v1022 == 0);
      if (v1119) {
        int * v1023 = v976->cache_tags;
        int v1024 = v1023[v1118];
        int * v1025 = v976->cache_vals;
        int v1122 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1026 = v1025[v1122];
        int v1123 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1027 = v1025[v1123];
        int * v1028 = v976->mem;
        int v1125 = v1024 * 2;
        v1028[v1125] = v1026;
        int * v1030 = v976->mem;
        int v1128 = (v1024 * 2) + 1;
        v1030[v1128] = v1027;
        ;
      } else {
        ;
      }
      int * v1035 = v976->mem;
      int v1133 = ((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) * 2;
      int v1036 = v1035[v1133];
      int v1134 = (((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) * 2) + 1;
      int v1037 = v1035[v1134];
      int * v1038 = v976->cache_vals;
      int v1136 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1038[v1136] = v1036;
      int * v1040 = v976->cache_vals;
      int v1139 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1040[v1139] = v1037;
      int * v1042 = v976->cache_tags;
      int v1142 = (int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1);
      v1042[v1118] = v1142;
      int * v1044 = v976->cache_dirty;
      v1044[v1118] = 0;
      int * v1046 = v976->cache_age;
      v1046[v1118] = 1;
      int * v1048 = v976->cache_age;
      int v1049 = v1048[v1118];
      int v1050 = v1048[v1092];
      int v1148 = v1050 + ((int)((unsigned int)(v1050 - v1049) >> 31));
      v1048[v1092] = v1148;
      int * v1052 = v976->cache_age;
      int v1053 = v1052[v1093];
      int v1150 = v1053 + ((int)((unsigned int)(v1053 - v1049) >> 31));
      v1052[v1093] = v1150;
      int * v1055 = v976->cache_age;
      v1055[v1118] = 0;
      v1058 = v1118;
    }
    int * v1059 = v976->cache_vals;
    int v1153 = v1058 * 2;
    int v1060 = v1059[v1153];
    int v1154 = (v1058 * 2) + 1;
    int v1061 = v1059[v1154];
    int v1155 = (((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((((v1000 + ((~(((v1002 ^ -1) | (-(v1002 ^ -1))) >> 31)) & 2)) - (v1003 + ((~(((v1004 ^ -1) | (-(v1004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1059[v1155] = v1060;
    int * v1063 = v976->cache_vals;
    int v1158 = ((((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((((v1000 + ((~(((v1002 ^ -1) | (-(v1002 ^ -1))) >> 31)) & 2)) - (v1003 + ((~(((v1004 ^ -1) | (-(v1004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1063[v1158] = v1061;
    int * v1065 = v976->cache_tags;
    int v1161 = ((((int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1)) & 1) * 2) + ((((v1000 + ((~(((v1002 ^ -1) | (-(v1002 ^ -1))) >> 31)) & 2)) - (v1003 + ((~(((v1004 ^ -1) | (-(v1004 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1162 = (int)((unsigned int)((int)((unsigned int)v980 >> 2)) >> 1);
    v1065[v1161] = v1162;
    int * v1067 = v976->cache_dirty;
    v1067[v1161] = 0;
    int * v1069 = v976->cache_age;
    v1069[v1161] = 1;
    int * v1071 = v976->cache_age;
    int v1072 = v1071[v1161];
    int v1073 = v1071[v1090];
    int v1168 = v1073 + ((int)((unsigned int)(v1073 - v1072) >> 31));
    v1071[v1090] = v1168;
    int * v1075 = v976->cache_age;
    int v1076 = v1075[v1091];
    int v1170 = v1076 + ((int)((unsigned int)(v1076 - v1072) >> 31));
    v1075[v1091] = v1170;
    int * v1078 = v976->cache_age;
    v1078[v1161] = 0;
    v1081 = v1161;
  }
  int v1173 = (v1081 * 2) + (((int)((unsigned int)v980 >> 2)) & 1);
  int v1082 = v988[v1173];
  int * v1083 = v976->regs;
  v1083[12] = v1082;
  return v976;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v437 = v32 + 1;
  v31->timer = v437;
  int * v34 = v31->regs;
  int v35 = v34[6];
  int * v36 = v31->saved_regs;
  int v37 = v34[11];
  v36[11] = v37;
  int v39 = v31->timer;
  int v443 = v39 + 1;
  v31->timer = v443;
  int * v41 = v31->regs;
  int v42 = v41[6];
  int * v43 = v31->cache_tags;
  int v446 = (((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2;
  int v44 = v43[v446];
  int v447 = ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2) + 1;
  int v45 = v43[v447];
  int v448 = 4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2);
  int v46 = v43[v448];
  int v449 = (4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v47 = v43[v449];
  int v48 = v31->timer;
  int v450 = v48 + ((100 ^ (((~(((v46 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v46 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) | (~(((v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) | (~(((v45 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v45 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v46 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v46 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) | (~(((v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31))) & 104)))));
  v31->timer = v450;
  int * v50 = v31->cache_vals;
  bool v451 = !(((~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) | (~(((v45 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v45 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31))) == 0);
  int v143;
  if (v451) {
    int * v51 = v31->cache_age;
    int v453 = ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2) + ((~(((v45 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v45 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) & 1);
    int v52 = v51[v453];
    int v53 = v51[v446];
    int v454 = v53 + ((int)((unsigned int)(v53 - v52) >> 31));
    v51[v446] = v454;
    int * v55 = v31->cache_age;
    int v56 = v55[v447];
    int v456 = v56 + ((int)((unsigned int)(v56 - v52) >> 31));
    v55[v447] = v456;
    int * v58 = v31->cache_age;
    v58[v453] = 0;
    v143 = v453;
  } else {
    int * v61 = v31->cache_age;
    int v460 = (((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2;
    int v62 = v61[v460];
    int * v63 = v31->cache_tags;
    int v64 = v63[v460];
    int v65 = v61[v447];
    int v66 = v63[v447];
    bool v462 = !(((~(((v46 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v46 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) | (~(((v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31))) == 0);
    int v120;
    if (v462) {
      int * v67 = v31->cache_age;
      int v464 = (4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + ((~(((v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))) | (-(v47 ^ ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1))))) >> 31)) & 1);
      int v68 = v67[v464];
      int v69 = v67[v448];
      int v465 = v69 + ((int)((unsigned int)(v69 - v68) >> 31));
      v67[v448] = v465;
      int * v71 = v31->cache_age;
      int v72 = v71[v449];
      int v467 = v72 + ((int)((unsigned int)(v72 - v68) >> 31));
      v71[v449] = v467;
      int * v74 = v31->cache_age;
      v74[v464] = 0;
      v120 = v464;
    } else {
      int * v77 = v31->cache_age;
      int v471 = 4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2);
      int v78 = v77[v471];
      int * v79 = v31->cache_tags;
      int v80 = v79[v471];
      int v81 = v77[v449];
      int v82 = v79[v449];
      int * v83 = v31->cache_dirty;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v84 = v83[v474];
      bool v475 = !(v84 == 0);
      if (v475) {
        int * v85 = v31->cache_tags;
        int v86 = v85[v474];
        int * v87 = v31->cache_vals;
        int v478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v88 = v87[v478];
        int v479 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v89 = v87[v479];
        int * v90 = v31->mem;
        int v481 = v86 * 2;
        v90[v481] = v88;
        int * v92 = v31->mem;
        int v484 = (v86 * 2) + 1;
        v92[v484] = v89;
        ;
      } else {
        ;
      }
      int * v97 = v31->mem;
      int v489 = ((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) * 2;
      int v98 = v97[v489];
      int v490 = (((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) * 2) + 1;
      int v99 = v97[v490];
      int * v100 = v31->cache_vals;
      int v492 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v100[v492] = v98;
      int * v102 = v31->cache_vals;
      int v495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 3) * 2)) + ((((v78 + ((~(((v80 ^ -1) | (-(v80 ^ -1))) >> 31)) & 2)) - (v81 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v102[v495] = v99;
      int * v104 = v31->cache_tags;
      int v498 = (int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1);
      v104[v474] = v498;
      int * v106 = v31->cache_dirty;
      v106[v474] = 0;
      int * v108 = v31->cache_age;
      v108[v474] = 1;
      int * v110 = v31->cache_age;
      int v111 = v110[v474];
      int v112 = v110[v448];
      int v504 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
      v110[v448] = v504;
      int * v114 = v31->cache_age;
      int v115 = v114[v449];
      int v506 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
      v114[v449] = v506;
      int * v117 = v31->cache_age;
      v117[v474] = 0;
      v120 = v474;
    }
    int * v121 = v31->cache_vals;
    int v509 = v120 * 2;
    int v122 = v121[v509];
    int v510 = (v120 * 2) + 1;
    int v123 = v121[v510];
    int v511 = (((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v121[v511] = v122;
    int * v125 = v31->cache_vals;
    int v514 = ((((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v125[v514] = v123;
    int * v127 = v31->cache_tags;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1)) & 1) * 2) + ((((v62 + ((~(((v64 ^ -1) | (-(v64 ^ -1))) >> 31)) & 2)) - (v65 + ((~(((v66 ^ -1) | (-(v66 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v518 = (int)((unsigned int)((int)((unsigned int)v42 >> 2)) >> 1);
    v127[v517] = v518;
    int * v129 = v31->cache_dirty;
    v129[v517] = 0;
    int * v131 = v31->cache_age;
    v131[v517] = 1;
    int * v133 = v31->cache_age;
    int v134 = v133[v517];
    int v135 = v133[v446];
    int v524 = v135 + ((int)((unsigned int)(v135 - v134) >> 31));
    v133[v446] = v524;
    int * v137 = v31->cache_age;
    int v138 = v137[v447];
    int v526 = v138 + ((int)((unsigned int)(v138 - v134) >> 31));
    v137[v447] = v526;
    int * v140 = v31->cache_age;
    v140[v517] = 0;
    v143 = v517;
  }
  int v529 = (v143 * 2) + (((int)((unsigned int)v42 >> 2)) & 1);
  int v144 = v50[v529];
  int * v145 = v31->regs;
  v145[11] = v144;
  int * v147 = v31->saved_regs;
  int * v148 = v31->regs;
  int v149 = v148[12];
  v147[12] = v149;
  int v151 = v31->timer;
  int v536 = v151 + 1;
  v31->timer = v536;
  int * v153 = v31->regs;
  int v154 = v153[11];
  int * v155 = v31->cache_tags;
  int v539 = (((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2;
  int v156 = v155[v539];
  int v540 = ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2) + 1;
  int v157 = v155[v540];
  int v541 = 4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2);
  int v158 = v155[v541];
  int v542 = (4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v159 = v155[v542];
  int v160 = v31->timer;
  int v543 = v160 + ((100 ^ (((~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) | (~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31))) & 104)))));
  v31->timer = v543;
  int * v162 = v31->cache_vals;
  bool v544 = !(((~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) | (~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31))) == 0);
  int v255;
  if (v544) {
    int * v163 = v31->cache_age;
    int v546 = ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2) + ((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) & 1);
    int v164 = v163[v546];
    int v165 = v163[v539];
    int v547 = v165 + ((int)((unsigned int)(v165 - v164) >> 31));
    v163[v539] = v547;
    int * v167 = v31->cache_age;
    int v168 = v167[v540];
    int v549 = v168 + ((int)((unsigned int)(v168 - v164) >> 31));
    v167[v540] = v549;
    int * v170 = v31->cache_age;
    v170[v546] = 0;
    v255 = v546;
  } else {
    int * v173 = v31->cache_age;
    int v553 = (((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2;
    int v174 = v173[v553];
    int * v175 = v31->cache_tags;
    int v176 = v175[v553];
    int v177 = v173[v540];
    int v178 = v175[v540];
    bool v555 = !(((~(((v158 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v158 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31))) == 0);
    int v232;
    if (v555) {
      int * v179 = v31->cache_age;
      int v557 = (4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + ((~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1))))) >> 31)) & 1);
      int v180 = v179[v557];
      int v181 = v179[v541];
      int v558 = v181 + ((int)((unsigned int)(v181 - v180) >> 31));
      v179[v541] = v558;
      int * v183 = v31->cache_age;
      int v184 = v183[v542];
      int v560 = v184 + ((int)((unsigned int)(v184 - v180) >> 31));
      v183[v542] = v560;
      int * v186 = v31->cache_age;
      v186[v557] = 0;
      v232 = v557;
    } else {
      int * v189 = v31->cache_age;
      int v564 = 4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2);
      int v190 = v189[v564];
      int * v191 = v31->cache_tags;
      int v192 = v191[v564];
      int v193 = v189[v542];
      int v194 = v191[v542];
      int * v195 = v31->cache_dirty;
      int v567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + ((((v190 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2)) - (v193 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v196 = v195[v567];
      bool v568 = !(v196 == 0);
      if (v568) {
        int * v197 = v31->cache_tags;
        int v198 = v197[v567];
        int * v199 = v31->cache_vals;
        int v571 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + ((((v190 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2)) - (v193 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v200 = v199[v571];
        int v572 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + ((((v190 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2)) - (v193 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v201 = v199[v572];
        int * v202 = v31->mem;
        int v574 = v198 * 2;
        v202[v574] = v200;
        int * v204 = v31->mem;
        int v577 = (v198 * 2) + 1;
        v204[v577] = v201;
        ;
      } else {
        ;
      }
      int * v209 = v31->mem;
      int v582 = ((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) * 2;
      int v210 = v209[v582];
      int v583 = (((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) * 2) + 1;
      int v211 = v209[v583];
      int * v212 = v31->cache_vals;
      int v585 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + ((((v190 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2)) - (v193 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v212[v585] = v210;
      int * v214 = v31->cache_vals;
      int v588 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 3) * 2)) + ((((v190 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2)) - (v193 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v214[v588] = v211;
      int * v216 = v31->cache_tags;
      int v591 = (int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1);
      v216[v567] = v591;
      int * v218 = v31->cache_dirty;
      v218[v567] = 0;
      int * v220 = v31->cache_age;
      v220[v567] = 1;
      int * v222 = v31->cache_age;
      int v223 = v222[v567];
      int v224 = v222[v541];
      int v597 = v224 + ((int)((unsigned int)(v224 - v223) >> 31));
      v222[v541] = v597;
      int * v226 = v31->cache_age;
      int v227 = v226[v542];
      int v599 = v227 + ((int)((unsigned int)(v227 - v223) >> 31));
      v226[v542] = v599;
      int * v229 = v31->cache_age;
      v229[v567] = 0;
      v232 = v567;
    }
    int * v233 = v31->cache_vals;
    int v602 = v232 * 2;
    int v234 = v233[v602];
    int v603 = (v232 * 2) + 1;
    int v235 = v233[v603];
    int v604 = (((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v233[v604] = v234;
    int * v237 = v31->cache_vals;
    int v607 = ((((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v237[v607] = v235;
    int * v239 = v31->cache_tags;
    int v610 = ((((int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1)) & 1) * 2) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v611 = (int)((unsigned int)((int)((unsigned int)v154 >> 2)) >> 1);
    v239[v610] = v611;
    int * v241 = v31->cache_dirty;
    v241[v610] = 0;
    int * v243 = v31->cache_age;
    v243[v610] = 1;
    int * v245 = v31->cache_age;
    int v246 = v245[v610];
    int v247 = v245[v539];
    int v617 = v247 + ((int)((unsigned int)(v247 - v246) >> 31));
    v245[v539] = v617;
    int * v249 = v31->cache_age;
    int v250 = v249[v540];
    int v619 = v250 + ((int)((unsigned int)(v250 - v246) >> 31));
    v249[v540] = v619;
    int * v252 = v31->cache_age;
    v252[v610] = 0;
    v255 = v610;
  }
  int v622 = (v255 * 2) + (((int)((unsigned int)v154 >> 2)) & 1);
  int v256 = v162[v622];
  int * v257 = v31->regs;
  v257[12] = v256;
  int * v259 = v31->cache_tags;
  int v626 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
  int v260 = v259[v626];
  int v627 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + 1;
  int v261 = v259[v627];
  int v628 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
  int v262 = v259[v628];
  int v629 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v263 = v259[v629];
  int v264 = v31->timer;
  int v630 = v264 + ((100 ^ (((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)))));
  v31->timer = v630;
  bool v631 = !(((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v358;
  if (v631) {
    int * v266 = v31->cache_age;
    int v633 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v267 = v266[v633];
    int v268 = v266[v626];
    int v634 = v268 + ((int)((unsigned int)(v268 - v267) >> 31));
    v266[v626] = v634;
    int * v270 = v31->cache_age;
    int v271 = v270[v627];
    int v636 = v271 + ((int)((unsigned int)(v271 - v267) >> 31));
    v270[v627] = v636;
    int * v273 = v31->cache_age;
    v273[v633] = 0;
    v358 = v633;
  } else {
    int * v276 = v31->cache_age;
    int v640 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
    int v277 = v276[v640];
    int * v278 = v31->cache_tags;
    int v279 = v278[v640];
    int v280 = v276[v627];
    int v281 = v278[v627];
    bool v642 = !(((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
    int v335;
    if (v642) {
      int * v282 = v31->cache_age;
      int v644 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
      int v283 = v282[v644];
      int v284 = v282[v628];
      int v645 = v284 + ((int)((unsigned int)(v284 - v283) >> 31));
      v282[v628] = v645;
      int * v286 = v31->cache_age;
      int v287 = v286[v629];
      int v647 = v287 + ((int)((unsigned int)(v287 - v283) >> 31));
      v286[v629] = v647;
      int * v289 = v31->cache_age;
      v289[v644] = 0;
      v335 = v644;
    } else {
      int * v292 = v31->cache_age;
      int v651 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
      int v293 = v292[v651];
      int * v294 = v31->cache_tags;
      int v295 = v294[v651];
      int v296 = v292[v629];
      int v297 = v294[v629];
      int * v298 = v31->cache_dirty;
      int v654 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v299 = v298[v654];
      bool v655 = !(v299 == 0);
      if (v655) {
        int * v300 = v31->cache_tags;
        int v301 = v300[v654];
        int * v302 = v31->cache_vals;
        int v658 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v303 = v302[v658];
        int v659 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v304 = v302[v659];
        int * v305 = v31->mem;
        int v661 = v301 * 2;
        v305[v661] = v303;
        int * v307 = v31->mem;
        int v664 = (v301 * 2) + 1;
        v307[v664] = v304;
        ;
      } else {
        ;
      }
      int * v312 = v31->mem;
      int v669 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
      int v313 = v312[v669];
      int v670 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
      int v314 = v312[v670];
      int * v315 = v31->cache_vals;
      int v672 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v315[v672] = v313;
      int * v317 = v31->cache_vals;
      int v675 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v317[v675] = v314;
      int * v319 = v31->cache_tags;
      int v678 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
      v319[v654] = v678;
      int * v321 = v31->cache_dirty;
      v321[v654] = 0;
      int * v323 = v31->cache_age;
      v323[v654] = 1;
      int * v325 = v31->cache_age;
      int v326 = v325[v654];
      int v327 = v325[v628];
      int v684 = v327 + ((int)((unsigned int)(v327 - v326) >> 31));
      v325[v628] = v684;
      int * v329 = v31->cache_age;
      int v330 = v329[v629];
      int v686 = v330 + ((int)((unsigned int)(v330 - v326) >> 31));
      v329[v629] = v686;
      int * v332 = v31->cache_age;
      v332[v654] = 0;
      v335 = v654;
    }
    int * v336 = v31->cache_vals;
    int v689 = v335 * 2;
    int v337 = v336[v689];
    int v690 = (v335 * 2) + 1;
    int v338 = v336[v690];
    int v691 = (((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v336[v691] = v337;
    int * v340 = v31->cache_vals;
    int v694 = ((((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v340[v694] = v338;
    int * v342 = v31->cache_tags;
    int v697 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v698 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v342[v697] = v698;
    int * v344 = v31->cache_dirty;
    v344[v697] = 0;
    int * v346 = v31->cache_age;
    v346[v697] = 1;
    int * v348 = v31->cache_age;
    int v349 = v348[v697];
    int v350 = v348[v626];
    int v704 = v350 + ((int)((unsigned int)(v350 - v349) >> 31));
    v348[v626] = v704;
    int * v352 = v31->cache_age;
    int v353 = v352[v627];
    int v706 = v353 + ((int)((unsigned int)(v353 - v349) >> 31));
    v352[v627] = v706;
    int * v355 = v31->cache_age;
    v355[v697] = 0;
    v358 = v697;
  }
  int * v359 = v31->cache_vals;
  int v709 = (v358 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v359[v709] = 0;
  int * v361 = v31->cache_tags;
  int v362 = v361[v628];
  int v363 = v361[v629];
  bool v712 = !(((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v417;
  if (v712) {
    int * v364 = v31->cache_age;
    int v714 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v365 = v364[v714];
    int v366 = v364[v628];
    int v715 = v366 + ((int)((unsigned int)(v366 - v365) >> 31));
    v364[v628] = v715;
    int * v368 = v31->cache_age;
    int v369 = v368[v629];
    int v717 = v369 + ((int)((unsigned int)(v369 - v365) >> 31));
    v368[v629] = v717;
    int * v371 = v31->cache_age;
    v371[v714] = 0;
    v417 = v714;
  } else {
    int * v374 = v31->cache_age;
    int v720 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
    int v375 = v374[v720];
    int * v376 = v31->cache_tags;
    int v377 = v376[v720];
    int v378 = v374[v629];
    int v379 = v376[v629];
    int * v380 = v31->cache_dirty;
    int v723 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v375 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2)) - (v378 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v381 = v380[v723];
    bool v724 = !(v381 == 0);
    if (v724) {
      int * v382 = v31->cache_tags;
      int v383 = v382[v723];
      int * v384 = v31->cache_vals;
      int v727 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v375 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2)) - (v378 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v385 = v384[v727];
      int v728 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v375 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2)) - (v378 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v386 = v384[v728];
      int * v387 = v31->mem;
      int v730 = v383 * 2;
      v387[v730] = v385;
      int * v389 = v31->mem;
      int v733 = (v383 * 2) + 1;
      v389[v733] = v386;
      ;
    } else {
      ;
    }
    int * v394 = v31->mem;
    int v738 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
    int v395 = v394[v738];
    int v739 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
    int v396 = v394[v739];
    int * v397 = v31->cache_vals;
    int v741 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v375 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2)) - (v378 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v397[v741] = v395;
    int * v399 = v31->cache_vals;
    int v744 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v375 + ((~(((v377 ^ -1) | (-(v377 ^ -1))) >> 31)) & 2)) - (v378 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v399[v744] = v396;
    int * v401 = v31->cache_tags;
    int v747 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v401[v723] = v747;
    int * v403 = v31->cache_dirty;
    v403[v723] = 0;
    int * v405 = v31->cache_age;
    v405[v723] = 1;
    int * v407 = v31->cache_age;
    int v408 = v407[v723];
    int v409 = v407[v628];
    int v752 = v409 + ((int)((unsigned int)(v409 - v408) >> 31));
    v407[v628] = v752;
    int * v411 = v31->cache_age;
    int v412 = v411[v629];
    int v754 = v412 + ((int)((unsigned int)(v412 - v408) >> 31));
    v411[v629] = v754;
    int * v414 = v31->cache_age;
    v414[v723] = 0;
    v417 = v723;
  }
  int * v418 = v31->cache_vals;
  int v757 = (v417 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v418[v757] = 0;
  int * v420 = v31->cache_dirty;
  v420[v417] = 1;
  bool v761 = (((int)((unsigned int)v42 >> 2)) == ((int)((unsigned int)v35 >> 2))) | (((int)((unsigned int)v154 >> 2)) == ((int)((unsigned int)v35 >> 2)));
  struct StateT * v435;
  if (v761) {
    int v422 = v31->timer;
    int v762 = v422 + 15;
    v31->timer = v762;
    int * v424 = v31->saved_regs;
    int v425 = v424[11];
    int * v426 = v31->regs;
    v426[11] = v425;
    int * v428 = v31->saved_regs;
    int v429 = v428[12];
    int * v430 = v31->regs;
    v430[12] = v429;
    struct StateT * v432 = slot_3(v31);
    v435 = v432;
  } else {
    v435 = v31;
  }
  return v435;
}

struct StateT * slot_3(struct StateT * v772) {
  int v773 = v772->timer;
  int v883 = v773 + 1;
  v772->timer = v883;
  int * v775 = v772->regs;
  int v776 = v775[6];
  int * v777 = v772->cache_tags;
  int v887 = (((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2;
  int v778 = v777[v887];
  int v888 = ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + 1;
  int v779 = v777[v888];
  int v889 = 4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2);
  int v780 = v777[v889];
  int v890 = (4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v781 = v777[v890];
  int v782 = v772->timer;
  int v891 = v782 + ((100 ^ (((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) & 104)))));
  v772->timer = v891;
  int * v784 = v772->cache_vals;
  bool v892 = !(((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) == 0);
  int v877;
  if (v892) {
    int * v785 = v772->cache_age;
    int v894 = ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((~(((v779 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v779 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) & 1);
    int v786 = v785[v894];
    int v787 = v785[v887];
    int v895 = v787 + ((int)((unsigned int)(v787 - v786) >> 31));
    v785[v887] = v895;
    int * v789 = v772->cache_age;
    int v790 = v789[v888];
    int v897 = v790 + ((int)((unsigned int)(v790 - v786) >> 31));
    v789[v888] = v897;
    int * v792 = v772->cache_age;
    v792[v894] = 0;
    v877 = v894;
  } else {
    int * v795 = v772->cache_age;
    int v901 = (((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2;
    int v796 = v795[v901];
    int * v797 = v772->cache_tags;
    int v798 = v797[v901];
    int v799 = v795[v888];
    int v800 = v797[v888];
    bool v903 = !(((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31))) == 0);
    int v854;
    if (v903) {
      int * v801 = v772->cache_age;
      int v905 = (4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1))))) >> 31)) & 1);
      int v802 = v801[v905];
      int v803 = v801[v889];
      int v906 = v803 + ((int)((unsigned int)(v803 - v802) >> 31));
      v801[v889] = v906;
      int * v805 = v772->cache_age;
      int v806 = v805[v890];
      int v908 = v806 + ((int)((unsigned int)(v806 - v802) >> 31));
      v805[v890] = v908;
      int * v808 = v772->cache_age;
      v808[v905] = 0;
      v854 = v905;
    } else {
      int * v811 = v772->cache_age;
      int v912 = 4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2);
      int v812 = v811[v912];
      int * v813 = v772->cache_tags;
      int v814 = v813[v912];
      int v815 = v811[v890];
      int v816 = v813[v890];
      int * v817 = v772->cache_dirty;
      int v915 = (4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v818 = v817[v915];
      bool v916 = !(v818 == 0);
      if (v916) {
        int * v819 = v772->cache_tags;
        int v820 = v819[v915];
        int * v821 = v772->cache_vals;
        int v919 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v822 = v821[v919];
        int v920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v823 = v821[v920];
        int * v824 = v772->mem;
        int v922 = v820 * 2;
        v824[v922] = v822;
        int * v826 = v772->mem;
        int v925 = (v820 * 2) + 1;
        v826[v925] = v823;
        ;
      } else {
        ;
      }
      int * v831 = v772->mem;
      int v930 = ((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) * 2;
      int v832 = v831[v930];
      int v931 = (((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) * 2) + 1;
      int v833 = v831[v931];
      int * v834 = v772->cache_vals;
      int v933 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v834[v933] = v832;
      int * v836 = v772->cache_vals;
      int v936 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 3) * 2)) + ((((v812 + ((~(((v814 ^ -1) | (-(v814 ^ -1))) >> 31)) & 2)) - (v815 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v836[v936] = v833;
      int * v838 = v772->cache_tags;
      int v939 = (int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1);
      v838[v915] = v939;
      int * v840 = v772->cache_dirty;
      v840[v915] = 0;
      int * v842 = v772->cache_age;
      v842[v915] = 1;
      int * v844 = v772->cache_age;
      int v845 = v844[v915];
      int v846 = v844[v889];
      int v945 = v846 + ((int)((unsigned int)(v846 - v845) >> 31));
      v844[v889] = v945;
      int * v848 = v772->cache_age;
      int v849 = v848[v890];
      int v947 = v849 + ((int)((unsigned int)(v849 - v845) >> 31));
      v848[v890] = v947;
      int * v851 = v772->cache_age;
      v851[v915] = 0;
      v854 = v915;
    }
    int * v855 = v772->cache_vals;
    int v950 = v854 * 2;
    int v856 = v855[v950];
    int v951 = (v854 * 2) + 1;
    int v857 = v855[v951];
    int v952 = (((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v855[v952] = v856;
    int * v859 = v772->cache_vals;
    int v955 = ((((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v859[v955] = v857;
    int * v861 = v772->cache_tags;
    int v958 = ((((int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1)) & 1) * 2) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v959 = (int)((unsigned int)((int)((unsigned int)v776 >> 2)) >> 1);
    v861[v958] = v959;
    int * v863 = v772->cache_dirty;
    v863[v958] = 0;
    int * v865 = v772->cache_age;
    v865[v958] = 1;
    int * v867 = v772->cache_age;
    int v868 = v867[v958];
    int v869 = v867[v887];
    int v965 = v869 + ((int)((unsigned int)(v869 - v868) >> 31));
    v867[v887] = v965;
    int * v871 = v772->cache_age;
    int v872 = v871[v888];
    int v967 = v872 + ((int)((unsigned int)(v872 - v868) >> 31));
    v871[v888] = v967;
    int * v874 = v772->cache_age;
    v874[v958] = 0;
    v877 = v958;
  }
  int v970 = (v877 * 2) + (((int)((unsigned int)v776 >> 2)) & 1);
  int v878 = v784[v970];
  int * v879 = v772->regs;
  v879[11] = v878;
  struct StateT * v881 = slot_4(v772);
  return v881;
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