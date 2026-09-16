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
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v1278);
struct StateT * slot_9(struct StateT * v1270);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v1020);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
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

struct StateT * slot_8(struct StateT * v1278) {
  int v1279 = v1278->timer;
  int v1287 = v1279 + 1;
  v1278->timer = v1287;
  int * v1281 = v1278->regs;
  int v1282 = v1281[6];
  int * v1283 = v1278->regs;
  int v1291 = v1282 + 4;
  v1283[6] = v1291;
  struct StateT * v1285 = slot_9(v1278);
  return v1285;
}

struct StateT * slot_9(struct StateT * v1270) {
  int v1271 = v1270->timer;
  int v1275 = v1271 + 1;
  v1270->timer = v1275;
  struct StateT * v1273 = slot_3(v1270);
  return v1273;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v1020) {
  int v1021 = v1020->timer;
  int v1154 = v1021 + 1;
  v1020->timer = v1154;
  int * v1023 = v1020->regs;
  int v1024 = v1023[6];
  int * v1025 = v1020->cache_tags;
  int v1158 = (((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2;
  int v1026 = v1025[v1158];
  int * v1027 = v1020->cache_tags;
  int v1160 = ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1028 = v1027[v1160];
  int * v1029 = v1020->cache_tags;
  int v1162 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2);
  int v1030 = v1029[v1162];
  int * v1031 = v1020->cache_tags;
  int v1164 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1032 = v1031[v1164];
  int v1033 = v1020->timer;
  int v1165 = v1033 + ((100 ^ (((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) | (~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) | (~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1020->timer = v1165;
  int * v1035 = v1020->cache_vals;
  bool v1166 = !(((~(((v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31))) == 0);
  int v1148;
  if (v1166) {
    int * v1036 = v1020->cache_age;
    int v1168 = ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2) + ((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) & 1);
    int v1037 = v1036[v1168];
    int * v1038 = v1020->cache_age;
    int v1039 = v1038[v1158];
    int * v1040 = v1020->cache_age;
    int v1171 = v1039 + ((int)((unsigned int)(v1039 - v1037) >> 31));
    v1040[v1158] = v1171;
    int * v1042 = v1020->cache_age;
    int v1043 = v1042[v1160];
    int * v1044 = v1020->cache_age;
    int v1174 = v1043 + ((int)((unsigned int)(v1043 - v1037) >> 31));
    v1044[v1160] = v1174;
    int * v1046 = v1020->cache_age;
    v1046[v1168] = 0;
    v1148 = v1168;
  } else {
    int * v1049 = v1020->cache_age;
    int v1178 = (((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2;
    int v1050 = v1049[v1178];
    int * v1051 = v1020->cache_tags;
    int v1052 = v1051[v1178];
    int * v1053 = v1020->cache_age;
    int v1054 = v1053[v1160];
    int * v1055 = v1020->cache_tags;
    int v1056 = v1055[v1160];
    bool v1182 = !(((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) | (~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31))) == 0);
    int v1120;
    if (v1182) {
      int * v1057 = v1020->cache_age;
      int v1184 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1))))) >> 31)) & 1);
      int v1058 = v1057[v1184];
      int * v1059 = v1020->cache_age;
      int v1060 = v1059[v1162];
      int * v1061 = v1020->cache_age;
      int v1187 = v1060 + ((int)((unsigned int)(v1060 - v1058) >> 31));
      v1061[v1162] = v1187;
      int * v1063 = v1020->cache_age;
      int v1064 = v1063[v1164];
      int * v1065 = v1020->cache_age;
      int v1190 = v1064 + ((int)((unsigned int)(v1064 - v1058) >> 31));
      v1065[v1164] = v1190;
      int * v1067 = v1020->cache_age;
      v1067[v1184] = 0;
      v1120 = v1184;
    } else {
      int * v1070 = v1020->cache_age;
      int v1194 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2);
      int v1071 = v1070[v1194];
      int * v1072 = v1020->cache_tags;
      int v1073 = v1072[v1194];
      int * v1074 = v1020->cache_age;
      int v1075 = v1074[v1164];
      int * v1076 = v1020->cache_tags;
      int v1077 = v1076[v1164];
      int * v1078 = v1020->cache_dirty;
      int v1199 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1079 = v1078[v1199];
      bool v1200 = !(v1079 == 0);
      if (v1200) {
        int * v1080 = v1020->cache_tags;
        int v1081 = v1080[v1199];
        int * v1082 = v1020->cache_vals;
        int v1203 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1083 = v1082[v1203];
        int * v1084 = v1020->cache_vals;
        int v1205 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1085 = v1084[v1205];
        int * v1086 = v1020->mem;
        int v1207 = v1081 * 2;
        v1086[v1207] = v1083;
        int * v1088 = v1020->mem;
        int v1210 = (v1081 * 2) + 1;
        v1088[v1210] = v1085;
        ;
      } else {
        ;
      }
      int * v1093 = v1020->mem;
      int v1215 = ((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) * 2;
      int v1094 = v1093[v1215];
      int * v1095 = v1020->mem;
      int v1217 = (((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) * 2) + 1;
      int v1096 = v1095[v1217];
      int * v1097 = v1020->cache_vals;
      int v1219 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1097[v1219] = v1094;
      int * v1099 = v1020->cache_vals;
      int v1222 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1077 ^ -1) | (-(v1077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1099[v1222] = v1096;
      int * v1101 = v1020->cache_tags;
      int v1225 = (int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1);
      v1101[v1199] = v1225;
      int * v1103 = v1020->cache_dirty;
      v1103[v1199] = 0;
      int * v1105 = v1020->cache_age;
      v1105[v1199] = 1;
      int * v1107 = v1020->cache_age;
      int v1108 = v1107[v1199];
      int * v1109 = v1020->cache_age;
      int v1110 = v1109[v1162];
      int * v1111 = v1020->cache_age;
      int v1233 = v1110 + ((int)((unsigned int)(v1110 - v1108) >> 31));
      v1111[v1162] = v1233;
      int * v1113 = v1020->cache_age;
      int v1114 = v1113[v1164];
      int * v1115 = v1020->cache_age;
      int v1236 = v1114 + ((int)((unsigned int)(v1114 - v1108) >> 31));
      v1115[v1164] = v1236;
      int * v1117 = v1020->cache_age;
      v1117[v1199] = 0;
      v1120 = v1199;
    }
    int * v1121 = v1020->cache_vals;
    int v1239 = v1120 * 2;
    int v1122 = v1121[v1239];
    int * v1123 = v1020->cache_vals;
    int v1241 = (v1120 * 2) + 1;
    int v1124 = v1123[v1241];
    int * v1125 = v1020->cache_vals;
    int v1243 = (((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2) + ((((v1050 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2)) - (v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1125[v1243] = v1122;
    int * v1127 = v1020->cache_vals;
    int v1246 = ((((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2) + ((((v1050 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2)) - (v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1127[v1246] = v1124;
    int * v1129 = v1020->cache_tags;
    int v1249 = ((((int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1)) & 1) * 2) + ((((v1050 + ((~(((v1052 ^ -1) | (-(v1052 ^ -1))) >> 31)) & 2)) - (v1054 + ((~(((v1056 ^ -1) | (-(v1056 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1250 = (int)((unsigned int)((int)((unsigned int)v1024 >> 2)) >> 1);
    v1129[v1249] = v1250;
    int * v1131 = v1020->cache_dirty;
    v1131[v1249] = 0;
    int * v1133 = v1020->cache_age;
    v1133[v1249] = 1;
    int * v1135 = v1020->cache_age;
    int v1136 = v1135[v1249];
    int * v1137 = v1020->cache_age;
    int v1138 = v1137[v1158];
    int * v1139 = v1020->cache_age;
    int v1258 = v1138 + ((int)((unsigned int)(v1138 - v1136) >> 31));
    v1139[v1158] = v1258;
    int * v1141 = v1020->cache_age;
    int v1142 = v1141[v1160];
    int * v1143 = v1020->cache_age;
    int v1261 = v1142 + ((int)((unsigned int)(v1142 - v1136) >> 31));
    v1143[v1160] = v1261;
    int * v1145 = v1020->cache_age;
    v1145[v1249] = 0;
    v1148 = v1249;
  }
  int v1264 = (v1148 * 2) + (((int)((unsigned int)v1024 >> 2)) & 1);
  int v1149 = v1035[v1264];
  int * v1150 = v1020->regs;
  v1150[11] = v1149;
  struct StateT * v1152 = slot_8(v1020);
  return v1152;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[8];
  v42[8] = v44;
  int v46 = v41->timer;
  int v574 = v46 + 1;
  v41->timer = v574;
  int * v48 = v41->regs;
  int v49 = v48[9];
  int * v50 = v41->regs;
  int v51 = v50[6];
  int * v52 = v41->regs;
  int v580 = v49 + v51;
  v52[8] = v580;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[5];
  v54[5] = v56;
  int v58 = v41->timer;
  int v585 = v58 + 1;
  v41->timer = v585;
  int * v60 = v41->regs;
  int v61 = v60[8];
  int * v62 = v41->cache_tags;
  int v588 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
  int v63 = v62[v588];
  int * v64 = v41->cache_tags;
  int v590 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + 1;
  int v65 = v64[v590];
  int * v66 = v41->cache_tags;
  int v592 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
  int v67 = v66[v592];
  int * v68 = v41->cache_tags;
  int v594 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v69 = v68[v594];
  int v70 = v41->timer;
  int v595 = v70 + ((100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)))));
  v41->timer = v595;
  int * v72 = v41->cache_vals;
  bool v596 = !(((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
  int v185;
  if (v596) {
    int * v73 = v41->cache_age;
    int v598 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
    int v74 = v73[v598];
    int * v75 = v41->cache_age;
    int v76 = v75[v588];
    int * v77 = v41->cache_age;
    int v601 = v76 + ((int)((unsigned int)(v76 - v74) >> 31));
    v77[v588] = v601;
    int * v79 = v41->cache_age;
    int v80 = v79[v590];
    int * v81 = v41->cache_age;
    int v604 = v80 + ((int)((unsigned int)(v80 - v74) >> 31));
    v81[v590] = v604;
    int * v83 = v41->cache_age;
    v83[v598] = 0;
    v185 = v598;
  } else {
    int * v86 = v41->cache_age;
    int v608 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
    int v87 = v86[v608];
    int * v88 = v41->cache_tags;
    int v89 = v88[v608];
    int * v90 = v41->cache_age;
    int v91 = v90[v590];
    int * v92 = v41->cache_tags;
    int v93 = v92[v590];
    bool v612 = !(((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
    int v157;
    if (v612) {
      int * v94 = v41->cache_age;
      int v614 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
      int v95 = v94[v614];
      int * v96 = v41->cache_age;
      int v97 = v96[v592];
      int * v98 = v41->cache_age;
      int v617 = v97 + ((int)((unsigned int)(v97 - v95) >> 31));
      v98[v592] = v617;
      int * v100 = v41->cache_age;
      int v101 = v100[v594];
      int * v102 = v41->cache_age;
      int v620 = v101 + ((int)((unsigned int)(v101 - v95) >> 31));
      v102[v594] = v620;
      int * v104 = v41->cache_age;
      v104[v614] = 0;
      v157 = v614;
    } else {
      int * v107 = v41->cache_age;
      int v624 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
      int v108 = v107[v624];
      int * v109 = v41->cache_tags;
      int v110 = v109[v624];
      int * v111 = v41->cache_age;
      int v112 = v111[v594];
      int * v113 = v41->cache_tags;
      int v114 = v113[v594];
      int * v115 = v41->cache_dirty;
      int v629 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v116 = v115[v629];
      bool v630 = !(v116 == 0);
      if (v630) {
        int * v117 = v41->cache_tags;
        int v118 = v117[v629];
        int * v119 = v41->cache_vals;
        int v633 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v120 = v119[v633];
        int * v121 = v41->cache_vals;
        int v635 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v122 = v121[v635];
        int * v123 = v41->mem;
        int v637 = v118 * 2;
        v123[v637] = v120;
        int * v125 = v41->mem;
        int v640 = (v118 * 2) + 1;
        v125[v640] = v122;
        ;
      } else {
        ;
      }
      int * v130 = v41->mem;
      int v645 = ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2;
      int v131 = v130[v645];
      int * v132 = v41->mem;
      int v647 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2) + 1;
      int v133 = v132[v647];
      int * v134 = v41->cache_vals;
      int v649 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v134[v649] = v131;
      int * v136 = v41->cache_vals;
      int v652 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v136[v652] = v133;
      int * v138 = v41->cache_tags;
      int v655 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
      v138[v629] = v655;
      int * v140 = v41->cache_dirty;
      v140[v629] = 0;
      int * v142 = v41->cache_age;
      v142[v629] = 1;
      int * v144 = v41->cache_age;
      int v145 = v144[v629];
      int * v146 = v41->cache_age;
      int v147 = v146[v592];
      int * v148 = v41->cache_age;
      int v663 = v147 + ((int)((unsigned int)(v147 - v145) >> 31));
      v148[v592] = v663;
      int * v150 = v41->cache_age;
      int v151 = v150[v594];
      int * v152 = v41->cache_age;
      int v666 = v151 + ((int)((unsigned int)(v151 - v145) >> 31));
      v152[v594] = v666;
      int * v154 = v41->cache_age;
      v154[v629] = 0;
      v157 = v629;
    }
    int * v158 = v41->cache_vals;
    int v669 = v157 * 2;
    int v159 = v158[v669];
    int * v160 = v41->cache_vals;
    int v671 = (v157 * 2) + 1;
    int v161 = v160[v671];
    int * v162 = v41->cache_vals;
    int v673 = (((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v162[v673] = v159;
    int * v164 = v41->cache_vals;
    int v676 = ((((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v676] = v161;
    int * v166 = v41->cache_tags;
    int v679 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v680 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
    v166[v679] = v680;
    int * v168 = v41->cache_dirty;
    v168[v679] = 0;
    int * v170 = v41->cache_age;
    v170[v679] = 1;
    int * v172 = v41->cache_age;
    int v173 = v172[v679];
    int * v174 = v41->cache_age;
    int v175 = v174[v588];
    int * v176 = v41->cache_age;
    int v688 = v175 + ((int)((unsigned int)(v175 - v173) >> 31));
    v176[v588] = v688;
    int * v178 = v41->cache_age;
    int v179 = v178[v590];
    int * v180 = v41->cache_age;
    int v691 = v179 + ((int)((unsigned int)(v179 - v173) >> 31));
    v180[v590] = v691;
    int * v182 = v41->cache_age;
    v182[v679] = 0;
    v185 = v679;
  }
  int v694 = (v185 * 2) + (((int)((unsigned int)v61 >> 2)) & 1);
  int v186 = v72[v694];
  int * v187 = v41->regs;
  v187[5] = v186;
  int * v189 = v41->regs;
  int v190 = v189[6];
  int * v191 = v41->regs;
  int v192 = v191[7];
  bool v700 = v190 >= v192;
  struct StateT * v568;
  if (v700) {
    int v193 = v41->timer;
    int v701 = v193 + 15;
    v41->timer = v701;
    int * v195 = v41->saved_regs;
    int v196 = v195[8];
    int * v197 = v41->regs;
    v197[8] = v196;
    int * v199 = v41->saved_regs;
    int v200 = v199[5];
    int * v201 = v41->regs;
    v201[5] = v200;
    v568 = v41;
  } else {
    int v204 = v41->timer;
    int v708 = v204 + 1;
    v41->timer = v708;
    int * v206 = v41->regs;
    int v207 = v206[6];
    int * v208 = v41->regs;
    int v209 = v208[5];
    int * v210 = v41->saved_regs;
    int * v211 = v41->regs;
    int v212 = v211[11];
    v210[11] = v212;
    int v214 = v41->timer;
    int v715 = v214 + 1;
    v41->timer = v715;
    int * v216 = v41->regs;
    int v217 = v216[6];
    int * v218 = v41->cache_tags;
    int v718 = (((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2;
    int v219 = v218[v718];
    int * v220 = v41->cache_tags;
    int v720 = ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2) + 1;
    int v221 = v220[v720];
    int * v222 = v41->cache_tags;
    int v722 = 4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2);
    int v223 = v222[v722];
    int * v224 = v41->cache_tags;
    int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v225 = v224[v724];
    int v226 = v41->timer;
    int v725 = v226 + ((100 ^ (((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v219 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v219 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) | (~(((v221 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v221 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31))) & 104)))));
    v41->timer = v725;
    int * v228 = v41->cache_vals;
    bool v726 = !(((~(((v219 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v219 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) | (~(((v221 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v221 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31))) == 0);
    int v341;
    if (v726) {
      int * v229 = v41->cache_age;
      int v728 = ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2) + ((~(((v221 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v221 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) & 1);
      int v230 = v229[v728];
      int * v231 = v41->cache_age;
      int v232 = v231[v718];
      int * v233 = v41->cache_age;
      int v731 = v232 + ((int)((unsigned int)(v232 - v230) >> 31));
      v233[v718] = v731;
      int * v235 = v41->cache_age;
      int v236 = v235[v720];
      int * v237 = v41->cache_age;
      int v734 = v236 + ((int)((unsigned int)(v236 - v230) >> 31));
      v237[v720] = v734;
      int * v239 = v41->cache_age;
      v239[v728] = 0;
      v341 = v728;
    } else {
      int * v242 = v41->cache_age;
      int v738 = (((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2;
      int v243 = v242[v738];
      int * v244 = v41->cache_tags;
      int v245 = v244[v738];
      int * v246 = v41->cache_age;
      int v247 = v246[v720];
      int * v248 = v41->cache_tags;
      int v249 = v248[v720];
      bool v742 = !(((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31))) == 0);
      int v313;
      if (v742) {
        int * v250 = v41->cache_age;
        int v744 = (4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + ((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1))))) >> 31)) & 1);
        int v251 = v250[v744];
        int * v252 = v41->cache_age;
        int v253 = v252[v722];
        int * v254 = v41->cache_age;
        int v747 = v253 + ((int)((unsigned int)(v253 - v251) >> 31));
        v254[v722] = v747;
        int * v256 = v41->cache_age;
        int v257 = v256[v724];
        int * v258 = v41->cache_age;
        int v750 = v257 + ((int)((unsigned int)(v257 - v251) >> 31));
        v258[v724] = v750;
        int * v260 = v41->cache_age;
        v260[v744] = 0;
        v313 = v744;
      } else {
        int * v263 = v41->cache_age;
        int v754 = 4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2);
        int v264 = v263[v754];
        int * v265 = v41->cache_tags;
        int v266 = v265[v754];
        int * v267 = v41->cache_age;
        int v268 = v267[v724];
        int * v269 = v41->cache_tags;
        int v270 = v269[v724];
        int * v271 = v41->cache_dirty;
        int v759 = (4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + ((((v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2)) - (v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v272 = v271[v759];
        bool v760 = !(v272 == 0);
        if (v760) {
          int * v273 = v41->cache_tags;
          int v274 = v273[v759];
          int * v275 = v41->cache_vals;
          int v763 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + ((((v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2)) - (v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v276 = v275[v763];
          int * v277 = v41->cache_vals;
          int v765 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + ((((v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2)) - (v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v278 = v277[v765];
          int * v279 = v41->mem;
          int v767 = v274 * 2;
          v279[v767] = v276;
          int * v281 = v41->mem;
          int v770 = (v274 * 2) + 1;
          v281[v770] = v278;
          ;
        } else {
          ;
        }
        int * v286 = v41->mem;
        int v775 = ((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) * 2;
        int v287 = v286[v775];
        int * v288 = v41->mem;
        int v777 = (((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) * 2) + 1;
        int v289 = v288[v777];
        int * v290 = v41->cache_vals;
        int v779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + ((((v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2)) - (v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v290[v779] = v287;
        int * v292 = v41->cache_vals;
        int v782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 3) * 2)) + ((((v264 + ((~(((v266 ^ -1) | (-(v266 ^ -1))) >> 31)) & 2)) - (v268 + ((~(((v270 ^ -1) | (-(v270 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v292[v782] = v289;
        int * v294 = v41->cache_tags;
        int v785 = (int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1);
        v294[v759] = v785;
        int * v296 = v41->cache_dirty;
        v296[v759] = 0;
        int * v298 = v41->cache_age;
        v298[v759] = 1;
        int * v300 = v41->cache_age;
        int v301 = v300[v759];
        int * v302 = v41->cache_age;
        int v303 = v302[v722];
        int * v304 = v41->cache_age;
        int v793 = v303 + ((int)((unsigned int)(v303 - v301) >> 31));
        v304[v722] = v793;
        int * v306 = v41->cache_age;
        int v307 = v306[v724];
        int * v308 = v41->cache_age;
        int v796 = v307 + ((int)((unsigned int)(v307 - v301) >> 31));
        v308[v724] = v796;
        int * v310 = v41->cache_age;
        v310[v759] = 0;
        v313 = v759;
      }
      int * v314 = v41->cache_vals;
      int v799 = v313 * 2;
      int v315 = v314[v799];
      int * v316 = v41->cache_vals;
      int v801 = (v313 * 2) + 1;
      int v317 = v316[v801];
      int * v318 = v41->cache_vals;
      int v803 = (((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2) + ((((v243 + ((~(((v245 ^ -1) | (-(v245 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v318[v803] = v315;
      int * v320 = v41->cache_vals;
      int v806 = ((((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2) + ((((v243 + ((~(((v245 ^ -1) | (-(v245 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v320[v806] = v317;
      int * v322 = v41->cache_tags;
      int v809 = ((((int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1)) & 1) * 2) + ((((v243 + ((~(((v245 ^ -1) | (-(v245 ^ -1))) >> 31)) & 2)) - (v247 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v810 = (int)((unsigned int)((int)((unsigned int)v217 >> 2)) >> 1);
      v322[v809] = v810;
      int * v324 = v41->cache_dirty;
      v324[v809] = 0;
      int * v326 = v41->cache_age;
      v326[v809] = 1;
      int * v328 = v41->cache_age;
      int v329 = v328[v809];
      int * v330 = v41->cache_age;
      int v331 = v330[v718];
      int * v332 = v41->cache_age;
      int v818 = v331 + ((int)((unsigned int)(v331 - v329) >> 31));
      v332[v718] = v818;
      int * v334 = v41->cache_age;
      int v335 = v334[v720];
      int * v336 = v41->cache_age;
      int v821 = v335 + ((int)((unsigned int)(v335 - v329) >> 31));
      v336[v720] = v821;
      int * v338 = v41->cache_age;
      v338[v809] = 0;
      v341 = v809;
    }
    int v824 = (v341 * 2) + (((int)((unsigned int)v217 >> 2)) & 1);
    int v342 = v228[v824];
    int * v343 = v41->regs;
    v343[11] = v342;
    int * v345 = v41->saved_regs;
    int * v346 = v41->regs;
    int v347 = v346[6];
    v345[6] = v347;
    int v349 = v41->timer;
    int v830 = v349 + 1;
    v41->timer = v830;
    int * v351 = v41->regs;
    int v352 = v351[6];
    int * v353 = v41->regs;
    int v833 = v352 + 4;
    v353[6] = v833;
    int * v355 = v41->cache_tags;
    int v835 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2;
    int v356 = v355[v835];
    int * v357 = v41->cache_tags;
    int v837 = ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + 1;
    int v358 = v357[v837];
    int * v359 = v41->cache_tags;
    int v839 = 4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2);
    int v360 = v359[v839];
    int * v361 = v41->cache_tags;
    int v841 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v362 = v361[v841];
    int v363 = v41->timer;
    int v842 = v363 + ((100 ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) & 104)))));
    v41->timer = v842;
    bool v843 = !(((~(((v356 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v356 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) == 0);
    int v477;
    if (v843) {
      int * v365 = v41->cache_age;
      int v845 = ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((~(((v358 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v358 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) & 1);
      int v366 = v365[v845];
      int * v367 = v41->cache_age;
      int v368 = v367[v835];
      int * v369 = v41->cache_age;
      int v848 = v368 + ((int)((unsigned int)(v368 - v366) >> 31));
      v369[v835] = v848;
      int * v371 = v41->cache_age;
      int v372 = v371[v837];
      int * v373 = v41->cache_age;
      int v851 = v372 + ((int)((unsigned int)(v372 - v366) >> 31));
      v373[v837] = v851;
      int * v375 = v41->cache_age;
      v375[v845] = 0;
      v477 = v845;
    } else {
      int * v378 = v41->cache_age;
      int v855 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2;
      int v379 = v378[v855];
      int * v380 = v41->cache_tags;
      int v381 = v380[v855];
      int * v382 = v41->cache_age;
      int v383 = v382[v837];
      int * v384 = v41->cache_tags;
      int v385 = v384[v837];
      bool v859 = !(((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) == 0);
      int v449;
      if (v859) {
        int * v386 = v41->cache_age;
        int v861 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) & 1);
        int v387 = v386[v861];
        int * v388 = v41->cache_age;
        int v389 = v388[v839];
        int * v390 = v41->cache_age;
        int v864 = v389 + ((int)((unsigned int)(v389 - v387) >> 31));
        v390[v839] = v864;
        int * v392 = v41->cache_age;
        int v393 = v392[v841];
        int * v394 = v41->cache_age;
        int v867 = v393 + ((int)((unsigned int)(v393 - v387) >> 31));
        v394[v841] = v867;
        int * v396 = v41->cache_age;
        v396[v861] = 0;
        v449 = v861;
      } else {
        int * v399 = v41->cache_age;
        int v871 = 4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2);
        int v400 = v399[v871];
        int * v401 = v41->cache_tags;
        int v402 = v401[v871];
        int * v403 = v41->cache_age;
        int v404 = v403[v841];
        int * v405 = v41->cache_tags;
        int v406 = v405[v841];
        int * v407 = v41->cache_dirty;
        int v876 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v408 = v407[v876];
        bool v877 = !(v408 == 0);
        if (v877) {
          int * v409 = v41->cache_tags;
          int v410 = v409[v876];
          int * v411 = v41->cache_vals;
          int v880 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v412 = v411[v880];
          int * v413 = v41->cache_vals;
          int v882 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v414 = v413[v882];
          int * v415 = v41->mem;
          int v884 = v410 * 2;
          v415[v884] = v412;
          int * v417 = v41->mem;
          int v887 = (v410 * 2) + 1;
          v417[v887] = v414;
          ;
        } else {
          ;
        }
        int * v422 = v41->mem;
        int v892 = ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2;
        int v423 = v422[v892];
        int * v424 = v41->mem;
        int v894 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2) + 1;
        int v425 = v424[v894];
        int * v426 = v41->cache_vals;
        int v896 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v426[v896] = v423;
        int * v428 = v41->cache_vals;
        int v899 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v400 + ((~(((v402 ^ -1) | (-(v402 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v428[v899] = v425;
        int * v430 = v41->cache_tags;
        int v902 = (int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1);
        v430[v876] = v902;
        int * v432 = v41->cache_dirty;
        v432[v876] = 0;
        int * v434 = v41->cache_age;
        v434[v876] = 1;
        int * v436 = v41->cache_age;
        int v437 = v436[v876];
        int * v438 = v41->cache_age;
        int v439 = v438[v839];
        int * v440 = v41->cache_age;
        int v910 = v439 + ((int)((unsigned int)(v439 - v437) >> 31));
        v440[v839] = v910;
        int * v442 = v41->cache_age;
        int v443 = v442[v841];
        int * v444 = v41->cache_age;
        int v913 = v443 + ((int)((unsigned int)(v443 - v437) >> 31));
        v444[v841] = v913;
        int * v446 = v41->cache_age;
        v446[v876] = 0;
        v449 = v876;
      }
      int * v450 = v41->cache_vals;
      int v916 = v449 * 2;
      int v451 = v450[v916];
      int * v452 = v41->cache_vals;
      int v918 = (v449 * 2) + 1;
      int v453 = v452[v918];
      int * v454 = v41->cache_vals;
      int v920 = (((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v454[v920] = v451;
      int * v456 = v41->cache_vals;
      int v923 = ((((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v456[v923] = v453;
      int * v458 = v41->cache_tags;
      int v926 = ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v927 = (int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1);
      v458[v926] = v927;
      int * v460 = v41->cache_dirty;
      v460[v926] = 0;
      int * v462 = v41->cache_age;
      v462[v926] = 1;
      int * v464 = v41->cache_age;
      int v465 = v464[v926];
      int * v466 = v41->cache_age;
      int v467 = v466[v835];
      int * v468 = v41->cache_age;
      int v935 = v467 + ((int)((unsigned int)(v467 - v465) >> 31));
      v468[v835] = v935;
      int * v470 = v41->cache_age;
      int v471 = v470[v837];
      int * v472 = v41->cache_age;
      int v938 = v471 + ((int)((unsigned int)(v471 - v465) >> 31));
      v472[v837] = v938;
      int * v474 = v41->cache_age;
      v474[v926] = 0;
      v477 = v926;
    }
    int * v478 = v41->cache_vals;
    int v941 = (v477 * 2) + (((int)((unsigned int)v207 >> 2)) & 1);
    v478[v941] = v209;
    int * v480 = v41->cache_tags;
    int v481 = v480[v839];
    int * v482 = v41->cache_tags;
    int v483 = v482[v841];
    bool v945 = !(((~(((v481 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v481 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) | (~(((v483 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v483 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31))) == 0);
    int v547;
    if (v945) {
      int * v484 = v41->cache_age;
      int v947 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((~(((v483 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))) | (-(v483 ^ ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1))))) >> 31)) & 1);
      int v485 = v484[v947];
      int * v486 = v41->cache_age;
      int v487 = v486[v839];
      int * v488 = v41->cache_age;
      int v950 = v487 + ((int)((unsigned int)(v487 - v485) >> 31));
      v488[v839] = v950;
      int * v490 = v41->cache_age;
      int v491 = v490[v841];
      int * v492 = v41->cache_age;
      int v953 = v491 + ((int)((unsigned int)(v491 - v485) >> 31));
      v492[v841] = v953;
      int * v494 = v41->cache_age;
      v494[v947] = 0;
      v547 = v947;
    } else {
      int * v497 = v41->cache_age;
      int v957 = 4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2);
      int v498 = v497[v957];
      int * v499 = v41->cache_tags;
      int v500 = v499[v957];
      int * v501 = v41->cache_age;
      int v502 = v501[v841];
      int * v503 = v41->cache_tags;
      int v504 = v503[v841];
      int * v505 = v41->cache_dirty;
      int v962 = (4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v506 = v505[v962];
      bool v963 = !(v506 == 0);
      if (v963) {
        int * v507 = v41->cache_tags;
        int v508 = v507[v962];
        int * v509 = v41->cache_vals;
        int v966 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v510 = v509[v966];
        int * v511 = v41->cache_vals;
        int v968 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v512 = v511[v968];
        int * v513 = v41->mem;
        int v970 = v508 * 2;
        v513[v970] = v510;
        int * v515 = v41->mem;
        int v973 = (v508 * 2) + 1;
        v515[v973] = v512;
        ;
      } else {
        ;
      }
      int * v520 = v41->mem;
      int v978 = ((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2;
      int v521 = v520[v978];
      int * v522 = v41->mem;
      int v980 = (((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) * 2) + 1;
      int v523 = v522[v980];
      int * v524 = v41->cache_vals;
      int v982 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v524[v982] = v521;
      int * v526 = v41->cache_vals;
      int v985 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1)) & 3) * 2)) + ((((v498 + ((~(((v500 ^ -1) | (-(v500 ^ -1))) >> 31)) & 2)) - (v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v526[v985] = v523;
      int * v528 = v41->cache_tags;
      int v988 = (int)((unsigned int)((int)((unsigned int)v207 >> 2)) >> 1);
      v528[v962] = v988;
      int * v530 = v41->cache_dirty;
      v530[v962] = 0;
      int * v532 = v41->cache_age;
      v532[v962] = 1;
      int * v534 = v41->cache_age;
      int v535 = v534[v962];
      int * v536 = v41->cache_age;
      int v537 = v536[v839];
      int * v538 = v41->cache_age;
      int v996 = v537 + ((int)((unsigned int)(v537 - v535) >> 31));
      v538[v839] = v996;
      int * v540 = v41->cache_age;
      int v541 = v540[v841];
      int * v542 = v41->cache_age;
      int v999 = v541 + ((int)((unsigned int)(v541 - v535) >> 31));
      v542[v841] = v999;
      int * v544 = v41->cache_age;
      v544[v962] = 0;
      v547 = v962;
    }
    int * v548 = v41->cache_vals;
    int v1002 = (v547 * 2) + (((int)((unsigned int)v207 >> 2)) & 1);
    v548[v1002] = v209;
    int * v550 = v41->cache_dirty;
    v550[v547] = 1;
    bool v1006 = ((int)((unsigned int)v217 >> 2)) == ((int)((unsigned int)v207 >> 2));
    struct StateT * v566;
    if (v1006) {
      int v552 = v41->timer;
      int v1007 = v552 + 15;
      v41->timer = v1007;
      int * v554 = v41->saved_regs;
      int v555 = v554[11];
      int * v556 = v41->regs;
      v556[11] = v555;
      int * v558 = v41->saved_regs;
      int v559 = v558[6];
      int * v560 = v41->regs;
      v560[6] = v559;
      struct StateT * v562 = slot_7(v41);
      v566 = v562;
    } else {
      struct StateT * v564 = slot_9(v41);
      v566 = v564;
    }
    v568 = v566;
  }
  return v568;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}