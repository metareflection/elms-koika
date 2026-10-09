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

struct StateT * slot_12(struct StateT * v1323);
struct StateT * slot_6(struct StateT * v714);
struct StateT * slot_16(struct StateT * v1760);
struct StateT * slot_23(struct StateT * v949);
struct StateT * slot_5(struct StateT * v496);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v746);
struct StateT * slot_21(struct StateT * v510);
struct StateT * slot_3(struct StateT * v253);
struct StateT * slot_10(struct StateT * v1296);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v267);
struct StateT * slot_13(struct StateT * v1337);
struct StateT * slot_24(struct StateT * v1277);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1353);
struct StateT * slot_17(struct StateT * v1776);
struct StateT * slot_20(struct StateT * v293);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v1264);
struct StateT * slot_4(struct StateT * v280);
struct StateT * slot_15(struct StateT * v1556);
struct StateT * slot_18(struct StateT * v240);
struct StateT * slot_9(struct StateT * v1282);
struct StateT * slot_22(struct StateT * v730);
struct StateT * slot_11(struct StateT * v1309);
struct StateT * slot_12(struct StateT * v1323) {
  int v1324 = v1323->timer;
  int v1331 = v1324 + 1;
  v1323->timer = v1331;
  int * v1326 = v1323->regs;
  int v1327 = v1326[10];
  int v1334 = (int)((unsigned int)v1327 >> 26);
  v1326[10] = v1334;
  struct StateT * v1329 = slot_13(v1323);
  return v1329;
}

struct StateT * slot_6(struct StateT * v714) {
  int v715 = v714->timer;
  int v723 = v715 + 1;
  v714->timer = v723;
  int * v717 = v714->regs;
  int v718 = v717[11];
  int v719 = v717[10];
  int v727 = v718 + v719;
  v717[10] = v727;
  struct StateT * v721 = slot_7(v714);
  return v721;
}

struct StateT * slot_16(struct StateT * v1760) {
  int v1761 = v1760->timer;
  int v1769 = v1761 + 1;
  v1760->timer = v1769;
  int * v1763 = v1760->regs;
  int v1764 = v1763[11];
  int v1765 = v1763[10];
  int v1773 = v1764 & v1765;
  v1763[10] = v1773;
  struct StateT * v1767 = slot_17(v1760);
  return v1767;
}

struct StateT * slot_23(struct StateT * v949) {
  int v950 = v949->timer;
  int v1120 = v950 + 1;
  v949->timer = v1120;
  int * v952 = v949->regs;
  int v953 = v952[11];
  int v954 = v952[10];
  int * v955 = v949->cache_tags;
  int v1125 = (((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2;
  int v956 = v955[v1125];
  int v1126 = ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v957 = v955[v1126];
  int v1127 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2);
  int v958 = v955[v1127];
  int v1128 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v959 = v955[v1128];
  int v960 = v949->timer;
  int v1129 = v960 + ((100 ^ (((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v956 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v956 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v957 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v957 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v949->timer = v1129;
  bool v1130 = !(((~(((v956 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v956 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v957 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v957 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1054;
  if (v1130) {
    int * v962 = v949->cache_age;
    int v1132 = ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v957 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v957 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v963 = v962[v1132];
    int v964 = v962[v1125];
    int v1133 = v964 + ((int)((unsigned int)(v964 - v963) >> 31));
    v962[v1125] = v1133;
    int * v966 = v949->cache_age;
    int v967 = v966[v1126];
    int v1135 = v967 + ((int)((unsigned int)(v967 - v963) >> 31));
    v966[v1126] = v1135;
    int * v969 = v949->cache_age;
    v969[v1132] = 0;
    v1054 = v1132;
  } else {
    int * v972 = v949->cache_age;
    int v1139 = (((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2;
    int v973 = v972[v1139];
    int * v974 = v949->cache_tags;
    int v975 = v974[v1139];
    int v976 = v972[v1126];
    int v977 = v974[v1126];
    bool v1141 = !(((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1031;
    if (v1141) {
      int * v978 = v949->cache_age;
      int v1143 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v979 = v978[v1143];
      int v980 = v978[v1127];
      int v1144 = v980 + ((int)((unsigned int)(v980 - v979) >> 31));
      v978[v1127] = v1144;
      int * v982 = v949->cache_age;
      int v983 = v982[v1128];
      int v1146 = v983 + ((int)((unsigned int)(v983 - v979) >> 31));
      v982[v1128] = v1146;
      int * v985 = v949->cache_age;
      v985[v1143] = 0;
      v1031 = v1143;
    } else {
      int * v988 = v949->cache_age;
      int v1150 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2);
      int v989 = v988[v1150];
      int * v990 = v949->cache_tags;
      int v991 = v990[v1150];
      int v992 = v988[v1128];
      int v993 = v990[v1128];
      int * v994 = v949->cache_dirty;
      int v1153 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v992 + ((~(((v993 ^ -1) | (-(v993 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v995 = v994[v1153];
      bool v1154 = !(v995 == 0);
      if (v1154) {
        int * v996 = v949->cache_tags;
        int v997 = v996[v1153];
        int * v998 = v949->cache_vals;
        int v1157 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v992 + ((~(((v993 ^ -1) | (-(v993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v999 = v998[v1157];
        int v1158 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v992 + ((~(((v993 ^ -1) | (-(v993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1000 = v998[v1158];
        int * v1001 = v949->mem;
        int v1160 = v997 * 2;
        v1001[v1160] = v999;
        int * v1003 = v949->mem;
        int v1163 = (v997 * 2) + 1;
        v1003[v1163] = v1000;
        ;
      } else {
        ;
      }
      int * v1008 = v949->mem;
      int v1168 = ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) * 2;
      int v1009 = v1008[v1168];
      int v1169 = (((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1010 = v1008[v1169];
      int * v1011 = v949->cache_vals;
      int v1171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v992 + ((~(((v993 ^ -1) | (-(v993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1011[v1171] = v1009;
      int * v1013 = v949->cache_vals;
      int v1174 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v989 + ((~(((v991 ^ -1) | (-(v991 ^ -1))) >> 31)) & 2)) - (v992 + ((~(((v993 ^ -1) | (-(v993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1013[v1174] = v1010;
      int * v1015 = v949->cache_tags;
      int v1177 = (int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1);
      v1015[v1153] = v1177;
      int * v1017 = v949->cache_dirty;
      v1017[v1153] = 0;
      int * v1019 = v949->cache_age;
      v1019[v1153] = 1;
      int * v1021 = v949->cache_age;
      int v1022 = v1021[v1153];
      int v1023 = v1021[v1127];
      int v1183 = v1023 + ((int)((unsigned int)(v1023 - v1022) >> 31));
      v1021[v1127] = v1183;
      int * v1025 = v949->cache_age;
      int v1026 = v1025[v1128];
      int v1185 = v1026 + ((int)((unsigned int)(v1026 - v1022) >> 31));
      v1025[v1128] = v1185;
      int * v1028 = v949->cache_age;
      v1028[v1153] = 0;
      v1031 = v1153;
    }
    int * v1032 = v949->cache_vals;
    int v1188 = v1031 * 2;
    int v1033 = v1032[v1188];
    int v1189 = (v1031 * 2) + 1;
    int v1034 = v1032[v1189];
    int v1190 = (((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v973 + ((~(((v975 ^ -1) | (-(v975 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v977 ^ -1) | (-(v977 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1032[v1190] = v1033;
    int * v1036 = v949->cache_vals;
    int v1193 = ((((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v973 + ((~(((v975 ^ -1) | (-(v975 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v977 ^ -1) | (-(v977 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1036[v1193] = v1034;
    int * v1038 = v949->cache_tags;
    int v1196 = ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v973 + ((~(((v975 ^ -1) | (-(v975 ^ -1))) >> 31)) & 2)) - (v976 + ((~(((v977 ^ -1) | (-(v977 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1197 = (int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1);
    v1038[v1196] = v1197;
    int * v1040 = v949->cache_dirty;
    v1040[v1196] = 0;
    int * v1042 = v949->cache_age;
    v1042[v1196] = 1;
    int * v1044 = v949->cache_age;
    int v1045 = v1044[v1196];
    int v1046 = v1044[v1125];
    int v1203 = v1046 + ((int)((unsigned int)(v1046 - v1045) >> 31));
    v1044[v1125] = v1203;
    int * v1048 = v949->cache_age;
    int v1049 = v1048[v1126];
    int v1205 = v1049 + ((int)((unsigned int)(v1049 - v1045) >> 31));
    v1048[v1126] = v1205;
    int * v1051 = v949->cache_age;
    v1051[v1196] = 0;
    v1054 = v1196;
  }
  int * v1055 = v949->cache_vals;
  int v1208 = (v1054 * 2) + (((int)((unsigned int)(v953 + 68) >> 2)) & 1);
  v1055[v1208] = v954;
  int * v1057 = v949->cache_tags;
  int v1058 = v1057[v1127];
  int v1059 = v1057[v1128];
  bool v1211 = !(((~(((v1058 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v1058 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1113;
  if (v1211) {
    int * v1060 = v949->cache_age;
    int v1213 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1061 = v1060[v1213];
    int v1062 = v1060[v1127];
    int v1214 = v1062 + ((int)((unsigned int)(v1062 - v1061) >> 31));
    v1060[v1127] = v1214;
    int * v1064 = v949->cache_age;
    int v1065 = v1064[v1128];
    int v1216 = v1065 + ((int)((unsigned int)(v1065 - v1061) >> 31));
    v1064[v1128] = v1216;
    int * v1067 = v949->cache_age;
    v1067[v1213] = 0;
    v1113 = v1213;
  } else {
    int * v1070 = v949->cache_age;
    int v1220 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1071 = v1070[v1220];
    int * v1072 = v949->cache_tags;
    int v1073 = v1072[v1220];
    int v1074 = v1070[v1128];
    int v1075 = v1072[v1128];
    int * v1076 = v949->cache_dirty;
    int v1223 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1074 + ((~(((v1075 ^ -1) | (-(v1075 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1077 = v1076[v1223];
    bool v1224 = !(v1077 == 0);
    if (v1224) {
      int * v1078 = v949->cache_tags;
      int v1079 = v1078[v1223];
      int * v1080 = v949->cache_vals;
      int v1227 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1074 + ((~(((v1075 ^ -1) | (-(v1075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1081 = v1080[v1227];
      int v1228 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1074 + ((~(((v1075 ^ -1) | (-(v1075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1082 = v1080[v1228];
      int * v1083 = v949->mem;
      int v1230 = v1079 * 2;
      v1083[v1230] = v1081;
      int * v1085 = v949->mem;
      int v1233 = (v1079 * 2) + 1;
      v1085[v1233] = v1082;
      ;
    } else {
      ;
    }
    int * v1090 = v949->mem;
    int v1238 = ((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) * 2;
    int v1091 = v1090[v1238];
    int v1239 = (((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1092 = v1090[v1239];
    int * v1093 = v949->cache_vals;
    int v1241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1074 + ((~(((v1075 ^ -1) | (-(v1075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1093[v1241] = v1091;
    int * v1095 = v949->cache_vals;
    int v1244 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1071 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2)) - (v1074 + ((~(((v1075 ^ -1) | (-(v1075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1095[v1244] = v1092;
    int * v1097 = v949->cache_tags;
    int v1247 = (int)((unsigned int)((int)((unsigned int)(v953 + 68) >> 2)) >> 1);
    v1097[v1223] = v1247;
    int * v1099 = v949->cache_dirty;
    v1099[v1223] = 0;
    int * v1101 = v949->cache_age;
    v1101[v1223] = 1;
    int * v1103 = v949->cache_age;
    int v1104 = v1103[v1223];
    int v1105 = v1103[v1127];
    int v1253 = v1105 + ((int)((unsigned int)(v1105 - v1104) >> 31));
    v1103[v1127] = v1253;
    int * v1107 = v949->cache_age;
    int v1108 = v1107[v1128];
    int v1255 = v1108 + ((int)((unsigned int)(v1108 - v1104) >> 31));
    v1107[v1128] = v1255;
    int * v1110 = v949->cache_age;
    v1110[v1223] = 0;
    v1113 = v1223;
  }
  int * v1114 = v949->cache_vals;
  int v1258 = (v1113 * 2) + (((int)((unsigned int)(v953 + 68) >> 2)) & 1);
  v1114[v1258] = v954;
  int * v1116 = v949->cache_dirty;
  v1116[v1113] = 1;
  struct StateT * v1118 = slot_24(v949);
  return v1118;
}

struct StateT * slot_5(struct StateT * v496) {
  int v497 = v496->timer;
  int v504 = v497 + 1;
  v496->timer = v504;
  int * v499 = v496->regs;
  int v500 = v499[11];
  int v507 = v500 + 72;
  v499[11] = v507;
  struct StateT * v502 = slot_6(v496);
  return v502;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v230 = v219 + 1;
  v218->timer = v230;
  int * v221 = v218->regs;
  int v222 = v221[10];
  int v223 = v221[11];
  bool v234 = (v222 ^ -2147483648) >= (v223 ^ -2147483648);
  struct StateT * v228;
  if (v234) {
    struct StateT * v224 = slot_18(v218);
    v228 = v224;
  } else {
    struct StateT * v226 = slot_3(v218);
    v228 = v226;
  }
  return v228;
}

struct StateT * slot_7(struct StateT * v746) {
  int v747 = v746->timer;
  int v857 = v747 + 1;
  v746->timer = v857;
  int * v749 = v746->regs;
  int v750 = v749[10];
  int * v751 = v746->cache_tags;
  int v861 = (((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2;
  int v752 = v751[v861];
  int v862 = ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2) + 1;
  int v753 = v751[v862];
  int v863 = 4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2);
  int v754 = v751[v863];
  int v864 = (4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v755 = v751[v864];
  int v756 = v746->timer;
  int v865 = v756 + ((100 ^ (((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) | (~(((v753 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v753 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31))) & 104)))));
  v746->timer = v865;
  int * v758 = v746->cache_vals;
  bool v866 = !(((~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) | (~(((v753 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v753 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31))) == 0);
  int v851;
  if (v866) {
    int * v759 = v746->cache_age;
    int v868 = ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2) + ((~(((v753 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v753 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) & 1);
    int v760 = v759[v868];
    int v761 = v759[v861];
    int v869 = v761 + ((int)((unsigned int)(v761 - v760) >> 31));
    v759[v861] = v869;
    int * v763 = v746->cache_age;
    int v764 = v763[v862];
    int v871 = v764 + ((int)((unsigned int)(v764 - v760) >> 31));
    v763[v862] = v871;
    int * v766 = v746->cache_age;
    v766[v868] = 0;
    v851 = v868;
  } else {
    int * v769 = v746->cache_age;
    int v875 = (((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2;
    int v770 = v769[v875];
    int * v771 = v746->cache_tags;
    int v772 = v771[v875];
    int v773 = v769[v862];
    int v774 = v771[v862];
    bool v877 = !(((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31))) == 0);
    int v828;
    if (v877) {
      int * v775 = v746->cache_age;
      int v879 = (4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + ((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1))))) >> 31)) & 1);
      int v776 = v775[v879];
      int v777 = v775[v863];
      int v880 = v777 + ((int)((unsigned int)(v777 - v776) >> 31));
      v775[v863] = v880;
      int * v779 = v746->cache_age;
      int v780 = v779[v864];
      int v882 = v780 + ((int)((unsigned int)(v780 - v776) >> 31));
      v779[v864] = v882;
      int * v782 = v746->cache_age;
      v782[v879] = 0;
      v828 = v879;
    } else {
      int * v785 = v746->cache_age;
      int v886 = 4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2);
      int v786 = v785[v886];
      int * v787 = v746->cache_tags;
      int v788 = v787[v886];
      int v789 = v785[v864];
      int v790 = v787[v864];
      int * v791 = v746->cache_dirty;
      int v889 = (4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v792 = v791[v889];
      bool v890 = !(v792 == 0);
      if (v890) {
        int * v793 = v746->cache_tags;
        int v794 = v793[v889];
        int * v795 = v746->cache_vals;
        int v893 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v796 = v795[v893];
        int v894 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v797 = v795[v894];
        int * v798 = v746->mem;
        int v896 = v794 * 2;
        v798[v896] = v796;
        int * v800 = v746->mem;
        int v899 = (v794 * 2) + 1;
        v800[v899] = v797;
        ;
      } else {
        ;
      }
      int * v805 = v746->mem;
      int v904 = ((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) * 2;
      int v806 = v805[v904];
      int v905 = (((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) * 2) + 1;
      int v807 = v805[v905];
      int * v808 = v746->cache_vals;
      int v907 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v808[v907] = v806;
      int * v810 = v746->cache_vals;
      int v910 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 3) * 2)) + ((((v786 + ((~(((v788 ^ -1) | (-(v788 ^ -1))) >> 31)) & 2)) - (v789 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v810[v910] = v807;
      int * v812 = v746->cache_tags;
      int v913 = (int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1);
      v812[v889] = v913;
      int * v814 = v746->cache_dirty;
      v814[v889] = 0;
      int * v816 = v746->cache_age;
      v816[v889] = 1;
      int * v818 = v746->cache_age;
      int v819 = v818[v889];
      int v820 = v818[v863];
      int v919 = v820 + ((int)((unsigned int)(v820 - v819) >> 31));
      v818[v863] = v919;
      int * v822 = v746->cache_age;
      int v823 = v822[v864];
      int v921 = v823 + ((int)((unsigned int)(v823 - v819) >> 31));
      v822[v864] = v921;
      int * v825 = v746->cache_age;
      v825[v889] = 0;
      v828 = v889;
    }
    int * v829 = v746->cache_vals;
    int v924 = v828 * 2;
    int v830 = v829[v924];
    int v925 = (v828 * 2) + 1;
    int v831 = v829[v925];
    int v926 = (((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2) + ((((v770 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v829[v926] = v830;
    int * v833 = v746->cache_vals;
    int v929 = ((((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2) + ((((v770 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v833[v929] = v831;
    int * v835 = v746->cache_tags;
    int v932 = ((((int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1)) & 1) * 2) + ((((v770 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2)) - (v773 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v933 = (int)((unsigned int)((int)((unsigned int)v750 >> 2)) >> 1);
    v835[v932] = v933;
    int * v837 = v746->cache_dirty;
    v837[v932] = 0;
    int * v839 = v746->cache_age;
    v839[v932] = 1;
    int * v841 = v746->cache_age;
    int v842 = v841[v932];
    int v843 = v841[v861];
    int v939 = v843 + ((int)((unsigned int)(v843 - v842) >> 31));
    v841[v861] = v939;
    int * v845 = v746->cache_age;
    int v846 = v845[v862];
    int v941 = v846 + ((int)((unsigned int)(v846 - v842) >> 31));
    v845[v862] = v941;
    int * v848 = v746->cache_age;
    v848[v932] = 0;
    v851 = v932;
  }
  int v944 = (v851 * 2) + (((int)((unsigned int)v750 >> 2)) & 1);
  int v852 = v758[v944];
  int * v853 = v746->regs;
  v853[10] = v852;
  struct StateT * v855 = slot_8(v746);
  return v855;
}

struct StateT * slot_21(struct StateT * v510) {
  int v511 = v510->timer;
  int v621 = v511 + 1;
  v510->timer = v621;
  int * v513 = v510->regs;
  int v514 = v513[11];
  int * v515 = v510->cache_tags;
  int v625 = (((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2;
  int v516 = v515[v625];
  int v626 = ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v517 = v515[v626];
  int v627 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2);
  int v518 = v515[v627];
  int v628 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v519 = v515[v628];
  int v520 = v510->timer;
  int v629 = v520 + ((100 ^ (((~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v517 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v517 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v510->timer = v629;
  int * v522 = v510->cache_vals;
  bool v630 = !(((~(((v516 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v516 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v517 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v517 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v615;
  if (v630) {
    int * v523 = v510->cache_age;
    int v632 = ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v517 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v517 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v524 = v523[v632];
    int v525 = v523[v625];
    int v633 = v525 + ((int)((unsigned int)(v525 - v524) >> 31));
    v523[v625] = v633;
    int * v527 = v510->cache_age;
    int v528 = v527[v626];
    int v635 = v528 + ((int)((unsigned int)(v528 - v524) >> 31));
    v527[v626] = v635;
    int * v530 = v510->cache_age;
    v530[v632] = 0;
    v615 = v632;
  } else {
    int * v533 = v510->cache_age;
    int v639 = (((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2;
    int v534 = v533[v639];
    int * v535 = v510->cache_tags;
    int v536 = v535[v639];
    int v537 = v533[v626];
    int v538 = v535[v626];
    bool v641 = !(((~(((v518 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v518 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v592;
    if (v641) {
      int * v539 = v510->cache_age;
      int v643 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v540 = v539[v643];
      int v541 = v539[v627];
      int v644 = v541 + ((int)((unsigned int)(v541 - v540) >> 31));
      v539[v627] = v644;
      int * v543 = v510->cache_age;
      int v544 = v543[v628];
      int v646 = v544 + ((int)((unsigned int)(v544 - v540) >> 31));
      v543[v628] = v646;
      int * v546 = v510->cache_age;
      v546[v643] = 0;
      v592 = v643;
    } else {
      int * v549 = v510->cache_age;
      int v650 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2);
      int v550 = v549[v650];
      int * v551 = v510->cache_tags;
      int v552 = v551[v650];
      int v553 = v549[v628];
      int v554 = v551[v628];
      int * v555 = v510->cache_dirty;
      int v653 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v550 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2)) - (v553 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v556 = v555[v653];
      bool v654 = !(v556 == 0);
      if (v654) {
        int * v557 = v510->cache_tags;
        int v558 = v557[v653];
        int * v559 = v510->cache_vals;
        int v657 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v550 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2)) - (v553 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v560 = v559[v657];
        int v658 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v550 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2)) - (v553 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v561 = v559[v658];
        int * v562 = v510->mem;
        int v660 = v558 * 2;
        v562[v660] = v560;
        int * v564 = v510->mem;
        int v663 = (v558 * 2) + 1;
        v564[v663] = v561;
        ;
      } else {
        ;
      }
      int * v569 = v510->mem;
      int v668 = ((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) * 2;
      int v570 = v569[v668];
      int v669 = (((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) * 2) + 1;
      int v571 = v569[v669];
      int * v572 = v510->cache_vals;
      int v671 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v550 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2)) - (v553 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v572[v671] = v570;
      int * v574 = v510->cache_vals;
      int v674 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v550 + ((~(((v552 ^ -1) | (-(v552 ^ -1))) >> 31)) & 2)) - (v553 + ((~(((v554 ^ -1) | (-(v554 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v574[v674] = v571;
      int * v576 = v510->cache_tags;
      int v677 = (int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1);
      v576[v653] = v677;
      int * v578 = v510->cache_dirty;
      v578[v653] = 0;
      int * v580 = v510->cache_age;
      v580[v653] = 1;
      int * v582 = v510->cache_age;
      int v583 = v582[v653];
      int v584 = v582[v627];
      int v683 = v584 + ((int)((unsigned int)(v584 - v583) >> 31));
      v582[v627] = v683;
      int * v586 = v510->cache_age;
      int v587 = v586[v628];
      int v685 = v587 + ((int)((unsigned int)(v587 - v583) >> 31));
      v586[v628] = v685;
      int * v589 = v510->cache_age;
      v589[v653] = 0;
      v592 = v653;
    }
    int * v593 = v510->cache_vals;
    int v688 = v592 * 2;
    int v594 = v593[v688];
    int v689 = (v592 * 2) + 1;
    int v595 = v593[v689];
    int v690 = (((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v534 + ((~(((v536 ^ -1) | (-(v536 ^ -1))) >> 31)) & 2)) - (v537 + ((~(((v538 ^ -1) | (-(v538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v593[v690] = v594;
    int * v597 = v510->cache_vals;
    int v693 = ((((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v534 + ((~(((v536 ^ -1) | (-(v536 ^ -1))) >> 31)) & 2)) - (v537 + ((~(((v538 ^ -1) | (-(v538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v597[v693] = v595;
    int * v599 = v510->cache_tags;
    int v696 = ((((int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v534 + ((~(((v536 ^ -1) | (-(v536 ^ -1))) >> 31)) & 2)) - (v537 + ((~(((v538 ^ -1) | (-(v538 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v697 = (int)((unsigned int)((int)((unsigned int)(v514 + 68) >> 2)) >> 1);
    v599[v696] = v697;
    int * v601 = v510->cache_dirty;
    v601[v696] = 0;
    int * v603 = v510->cache_age;
    v603[v696] = 1;
    int * v605 = v510->cache_age;
    int v606 = v605[v696];
    int v607 = v605[v625];
    int v703 = v607 + ((int)((unsigned int)(v607 - v606) >> 31));
    v605[v625] = v703;
    int * v609 = v510->cache_age;
    int v610 = v609[v626];
    int v705 = v610 + ((int)((unsigned int)(v610 - v606) >> 31));
    v609[v626] = v705;
    int * v612 = v510->cache_age;
    v612[v696] = 0;
    v615 = v696;
  }
  int v708 = (v615 * 2) + (((int)((unsigned int)(v514 + 68) >> 2)) & 1);
  int v616 = v522[v708];
  int * v617 = v510->regs;
  v617[12] = v616;
  struct StateT * v619 = slot_22(v510);
  return v619;
}

struct StateT * slot_3(struct StateT * v253) {
  int v254 = v253->timer;
  int v261 = v254 + 1;
  v253->timer = v261;
  int * v256 = v253->regs;
  int v257 = v256[10];
  int v264 = v257 << 2;
  v256[10] = v264;
  struct StateT * v259 = slot_4(v253);
  return v259;
}

struct StateT * slot_10(struct StateT * v1296) {
  int v1297 = v1296->timer;
  int v1303 = v1297 + 1;
  v1296->timer = v1303;
  int * v1299 = v1296->regs;
  v1299[12] = 0;
  struct StateT * v1301 = slot_11(v1296);
  return v1301;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[11];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[11] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_19(struct StateT * v267) {
  int v268 = v267->timer;
  int v274 = v268 + 1;
  v267->timer = v274;
  int * v270 = v267->regs;
  v270[11] = 0;
  struct StateT * v272 = slot_20(v267);
  return v272;
}

struct StateT * slot_13(struct StateT * v1337) {
  int v1338 = v1337->timer;
  int v1346 = v1338 + 1;
  v1337->timer = v1346;
  int * v1340 = v1337->regs;
  int v1341 = v1340[11];
  int v1342 = v1340[10];
  int v1350 = v1341 + v1342;
  v1340[10] = v1350;
  struct StateT * v1344 = slot_14(v1337);
  return v1344;
}

struct StateT * slot_24(struct StateT * v1277) {
  int v1278 = v1277->timer;
  int v1281 = v1278 + 1;
  v1277->timer = v1281;
  return v1277;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[11] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v1353) {
  int v1354 = v1353->timer;
  int v1464 = v1354 + 1;
  v1353->timer = v1464;
  int * v1356 = v1353->regs;
  int v1357 = v1356[10];
  int * v1358 = v1353->cache_tags;
  int v1468 = (((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2;
  int v1359 = v1358[v1468];
  int v1469 = ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1360 = v1358[v1469];
  int v1470 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2);
  int v1361 = v1358[v1470];
  int v1471 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1362 = v1358[v1471];
  int v1363 = v1353->timer;
  int v1472 = v1363 + ((100 ^ (((~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) | (~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1359 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1359 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) | (~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) | (~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1353->timer = v1472;
  int * v1365 = v1353->cache_vals;
  bool v1473 = !(((~(((v1359 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1359 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) | (~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31))) == 0);
  int v1458;
  if (v1473) {
    int * v1366 = v1353->cache_age;
    int v1475 = ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2) + ((~(((v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1360 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) & 1);
    int v1367 = v1366[v1475];
    int v1368 = v1366[v1468];
    int v1476 = v1368 + ((int)((unsigned int)(v1368 - v1367) >> 31));
    v1366[v1468] = v1476;
    int * v1370 = v1353->cache_age;
    int v1371 = v1370[v1469];
    int v1478 = v1371 + ((int)((unsigned int)(v1371 - v1367) >> 31));
    v1370[v1469] = v1478;
    int * v1373 = v1353->cache_age;
    v1373[v1475] = 0;
    v1458 = v1475;
  } else {
    int * v1376 = v1353->cache_age;
    int v1482 = (((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2;
    int v1377 = v1376[v1482];
    int * v1378 = v1353->cache_tags;
    int v1379 = v1378[v1482];
    int v1380 = v1376[v1469];
    int v1381 = v1378[v1469];
    bool v1484 = !(((~(((v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1361 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) | (~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31))) == 0);
    int v1435;
    if (v1484) {
      int * v1382 = v1353->cache_age;
      int v1486 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))) | (-(v1362 ^ ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1))))) >> 31)) & 1);
      int v1383 = v1382[v1486];
      int v1384 = v1382[v1470];
      int v1487 = v1384 + ((int)((unsigned int)(v1384 - v1383) >> 31));
      v1382[v1470] = v1487;
      int * v1386 = v1353->cache_age;
      int v1387 = v1386[v1471];
      int v1489 = v1387 + ((int)((unsigned int)(v1387 - v1383) >> 31));
      v1386[v1471] = v1489;
      int * v1389 = v1353->cache_age;
      v1389[v1486] = 0;
      v1435 = v1486;
    } else {
      int * v1392 = v1353->cache_age;
      int v1493 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2);
      int v1393 = v1392[v1493];
      int * v1394 = v1353->cache_tags;
      int v1395 = v1394[v1493];
      int v1396 = v1392[v1471];
      int v1397 = v1394[v1471];
      int * v1398 = v1353->cache_dirty;
      int v1496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1399 = v1398[v1496];
      bool v1497 = !(v1399 == 0);
      if (v1497) {
        int * v1400 = v1353->cache_tags;
        int v1401 = v1400[v1496];
        int * v1402 = v1353->cache_vals;
        int v1500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1403 = v1402[v1500];
        int v1501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1404 = v1402[v1501];
        int * v1405 = v1353->mem;
        int v1503 = v1401 * 2;
        v1405[v1503] = v1403;
        int * v1407 = v1353->mem;
        int v1506 = (v1401 * 2) + 1;
        v1407[v1506] = v1404;
        ;
      } else {
        ;
      }
      int * v1412 = v1353->mem;
      int v1511 = ((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) * 2;
      int v1413 = v1412[v1511];
      int v1512 = (((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) * 2) + 1;
      int v1414 = v1412[v1512];
      int * v1415 = v1353->cache_vals;
      int v1514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1415[v1514] = v1413;
      int * v1417 = v1353->cache_vals;
      int v1517 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 3) * 2)) + ((((v1393 + ((~(((v1395 ^ -1) | (-(v1395 ^ -1))) >> 31)) & 2)) - (v1396 + ((~(((v1397 ^ -1) | (-(v1397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1417[v1517] = v1414;
      int * v1419 = v1353->cache_tags;
      int v1520 = (int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1);
      v1419[v1496] = v1520;
      int * v1421 = v1353->cache_dirty;
      v1421[v1496] = 0;
      int * v1423 = v1353->cache_age;
      v1423[v1496] = 1;
      int * v1425 = v1353->cache_age;
      int v1426 = v1425[v1496];
      int v1427 = v1425[v1470];
      int v1526 = v1427 + ((int)((unsigned int)(v1427 - v1426) >> 31));
      v1425[v1470] = v1526;
      int * v1429 = v1353->cache_age;
      int v1430 = v1429[v1471];
      int v1528 = v1430 + ((int)((unsigned int)(v1430 - v1426) >> 31));
      v1429[v1471] = v1528;
      int * v1432 = v1353->cache_age;
      v1432[v1496] = 0;
      v1435 = v1496;
    }
    int * v1436 = v1353->cache_vals;
    int v1531 = v1435 * 2;
    int v1437 = v1436[v1531];
    int v1532 = (v1435 * 2) + 1;
    int v1438 = v1436[v1532];
    int v1533 = (((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2) + ((((v1377 + ((~(((v1379 ^ -1) | (-(v1379 ^ -1))) >> 31)) & 2)) - (v1380 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1436[v1533] = v1437;
    int * v1440 = v1353->cache_vals;
    int v1536 = ((((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2) + ((((v1377 + ((~(((v1379 ^ -1) | (-(v1379 ^ -1))) >> 31)) & 2)) - (v1380 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1440[v1536] = v1438;
    int * v1442 = v1353->cache_tags;
    int v1539 = ((((int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1)) & 1) * 2) + ((((v1377 + ((~(((v1379 ^ -1) | (-(v1379 ^ -1))) >> 31)) & 2)) - (v1380 + ((~(((v1381 ^ -1) | (-(v1381 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1540 = (int)((unsigned int)((int)((unsigned int)v1357 >> 2)) >> 1);
    v1442[v1539] = v1540;
    int * v1444 = v1353->cache_dirty;
    v1444[v1539] = 0;
    int * v1446 = v1353->cache_age;
    v1446[v1539] = 1;
    int * v1448 = v1353->cache_age;
    int v1449 = v1448[v1539];
    int v1450 = v1448[v1468];
    int v1546 = v1450 + ((int)((unsigned int)(v1450 - v1449) >> 31));
    v1448[v1468] = v1546;
    int * v1452 = v1353->cache_age;
    int v1453 = v1452[v1469];
    int v1548 = v1453 + ((int)((unsigned int)(v1453 - v1449) >> 31));
    v1452[v1469] = v1548;
    int * v1455 = v1353->cache_age;
    v1455[v1539] = 0;
    v1458 = v1539;
  }
  int v1551 = (v1458 * 2) + (((int)((unsigned int)v1357 >> 2)) & 1);
  int v1459 = v1365[v1551];
  int * v1460 = v1353->regs;
  v1460[10] = v1459;
  struct StateT * v1462 = slot_15(v1353);
  return v1462;
}

struct StateT * slot_17(struct StateT * v1776) {
  int v1777 = v1776->timer;
  int v1947 = v1777 + 1;
  v1776->timer = v1947;
  int * v1779 = v1776->regs;
  int v1780 = v1779[12];
  int v1781 = v1779[10];
  int * v1782 = v1776->cache_tags;
  int v1952 = (((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1783 = v1782[v1952];
  int v1953 = ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1784 = v1782[v1953];
  int v1954 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1785 = v1782[v1954];
  int v1955 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1786 = v1782[v1955];
  int v1787 = v1776->timer;
  int v1956 = v1787 + ((100 ^ (((~(((v1785 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1785 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1785 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1785 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1776->timer = v1956;
  bool v1957 = !(((~(((v1783 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1783 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1881;
  if (v1957) {
    int * v1789 = v1776->cache_age;
    int v1959 = ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1784 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1784 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1790 = v1789[v1959];
    int v1791 = v1789[v1952];
    int v1960 = v1791 + ((int)((unsigned int)(v1791 - v1790) >> 31));
    v1789[v1952] = v1960;
    int * v1793 = v1776->cache_age;
    int v1794 = v1793[v1953];
    int v1962 = v1794 + ((int)((unsigned int)(v1794 - v1790) >> 31));
    v1793[v1953] = v1962;
    int * v1796 = v1776->cache_age;
    v1796[v1959] = 0;
    v1881 = v1959;
  } else {
    int * v1799 = v1776->cache_age;
    int v1966 = (((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1800 = v1799[v1966];
    int * v1801 = v1776->cache_tags;
    int v1802 = v1801[v1966];
    int v1803 = v1799[v1953];
    int v1804 = v1801[v1953];
    bool v1968 = !(((~(((v1785 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1785 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1858;
    if (v1968) {
      int * v1805 = v1776->cache_age;
      int v1970 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1786 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1806 = v1805[v1970];
      int v1807 = v1805[v1954];
      int v1971 = v1807 + ((int)((unsigned int)(v1807 - v1806) >> 31));
      v1805[v1954] = v1971;
      int * v1809 = v1776->cache_age;
      int v1810 = v1809[v1955];
      int v1973 = v1810 + ((int)((unsigned int)(v1810 - v1806) >> 31));
      v1809[v1955] = v1973;
      int * v1812 = v1776->cache_age;
      v1812[v1970] = 0;
      v1858 = v1970;
    } else {
      int * v1815 = v1776->cache_age;
      int v1977 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1816 = v1815[v1977];
      int * v1817 = v1776->cache_tags;
      int v1818 = v1817[v1977];
      int v1819 = v1815[v1955];
      int v1820 = v1817[v1955];
      int * v1821 = v1776->cache_dirty;
      int v1980 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1816 + ((~(((v1818 ^ -1) | (-(v1818 ^ -1))) >> 31)) & 2)) - (v1819 + ((~(((v1820 ^ -1) | (-(v1820 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1822 = v1821[v1980];
      bool v1981 = !(v1822 == 0);
      if (v1981) {
        int * v1823 = v1776->cache_tags;
        int v1824 = v1823[v1980];
        int * v1825 = v1776->cache_vals;
        int v1984 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1816 + ((~(((v1818 ^ -1) | (-(v1818 ^ -1))) >> 31)) & 2)) - (v1819 + ((~(((v1820 ^ -1) | (-(v1820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1826 = v1825[v1984];
        int v1985 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1816 + ((~(((v1818 ^ -1) | (-(v1818 ^ -1))) >> 31)) & 2)) - (v1819 + ((~(((v1820 ^ -1) | (-(v1820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1827 = v1825[v1985];
        int * v1828 = v1776->mem;
        int v1987 = v1824 * 2;
        v1828[v1987] = v1826;
        int * v1830 = v1776->mem;
        int v1990 = (v1824 * 2) + 1;
        v1830[v1990] = v1827;
        ;
      } else {
        ;
      }
      int * v1835 = v1776->mem;
      int v1995 = ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) * 2;
      int v1836 = v1835[v1995];
      int v1996 = (((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1837 = v1835[v1996];
      int * v1838 = v1776->cache_vals;
      int v1998 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1816 + ((~(((v1818 ^ -1) | (-(v1818 ^ -1))) >> 31)) & 2)) - (v1819 + ((~(((v1820 ^ -1) | (-(v1820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1838[v1998] = v1836;
      int * v1840 = v1776->cache_vals;
      int v2001 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1816 + ((~(((v1818 ^ -1) | (-(v1818 ^ -1))) >> 31)) & 2)) - (v1819 + ((~(((v1820 ^ -1) | (-(v1820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1840[v2001] = v1837;
      int * v1842 = v1776->cache_tags;
      int v2004 = (int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1);
      v1842[v1980] = v2004;
      int * v1844 = v1776->cache_dirty;
      v1844[v1980] = 0;
      int * v1846 = v1776->cache_age;
      v1846[v1980] = 1;
      int * v1848 = v1776->cache_age;
      int v1849 = v1848[v1980];
      int v1850 = v1848[v1954];
      int v2010 = v1850 + ((int)((unsigned int)(v1850 - v1849) >> 31));
      v1848[v1954] = v2010;
      int * v1852 = v1776->cache_age;
      int v1853 = v1852[v1955];
      int v2012 = v1853 + ((int)((unsigned int)(v1853 - v1849) >> 31));
      v1852[v1955] = v2012;
      int * v1855 = v1776->cache_age;
      v1855[v1980] = 0;
      v1858 = v1980;
    }
    int * v1859 = v1776->cache_vals;
    int v2015 = v1858 * 2;
    int v1860 = v1859[v2015];
    int v2016 = (v1858 * 2) + 1;
    int v1861 = v1859[v2016];
    int v2017 = (((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1800 + ((~(((v1802 ^ -1) | (-(v1802 ^ -1))) >> 31)) & 2)) - (v1803 + ((~(((v1804 ^ -1) | (-(v1804 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1859[v2017] = v1860;
    int * v1863 = v1776->cache_vals;
    int v2020 = ((((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1800 + ((~(((v1802 ^ -1) | (-(v1802 ^ -1))) >> 31)) & 2)) - (v1803 + ((~(((v1804 ^ -1) | (-(v1804 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1863[v2020] = v1861;
    int * v1865 = v1776->cache_tags;
    int v2023 = ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1800 + ((~(((v1802 ^ -1) | (-(v1802 ^ -1))) >> 31)) & 2)) - (v1803 + ((~(((v1804 ^ -1) | (-(v1804 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2024 = (int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1);
    v1865[v2023] = v2024;
    int * v1867 = v1776->cache_dirty;
    v1867[v2023] = 0;
    int * v1869 = v1776->cache_age;
    v1869[v2023] = 1;
    int * v1871 = v1776->cache_age;
    int v1872 = v1871[v2023];
    int v1873 = v1871[v1952];
    int v2030 = v1873 + ((int)((unsigned int)(v1873 - v1872) >> 31));
    v1871[v1952] = v2030;
    int * v1875 = v1776->cache_age;
    int v1876 = v1875[v1953];
    int v2032 = v1876 + ((int)((unsigned int)(v1876 - v1872) >> 31));
    v1875[v1953] = v2032;
    int * v1878 = v1776->cache_age;
    v1878[v2023] = 0;
    v1881 = v2023;
  }
  int * v1882 = v1776->cache_vals;
  int v2035 = (v1881 * 2) + (((int)((unsigned int)(v1780 + 68) >> 2)) & 1);
  v1882[v2035] = v1781;
  int * v1884 = v1776->cache_tags;
  int v1885 = v1884[v1954];
  int v1886 = v1884[v1955];
  bool v2038 = !(((~(((v1885 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1885 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1886 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1886 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1940;
  if (v2038) {
    int * v1887 = v1776->cache_age;
    int v2040 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1886 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))) | (-(v1886 ^ ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1888 = v1887[v2040];
    int v1889 = v1887[v1954];
    int v2041 = v1889 + ((int)((unsigned int)(v1889 - v1888) >> 31));
    v1887[v1954] = v2041;
    int * v1891 = v1776->cache_age;
    int v1892 = v1891[v1955];
    int v2043 = v1892 + ((int)((unsigned int)(v1892 - v1888) >> 31));
    v1891[v1955] = v2043;
    int * v1894 = v1776->cache_age;
    v1894[v2040] = 0;
    v1940 = v2040;
  } else {
    int * v1897 = v1776->cache_age;
    int v2047 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1898 = v1897[v2047];
    int * v1899 = v1776->cache_tags;
    int v1900 = v1899[v2047];
    int v1901 = v1897[v1955];
    int v1902 = v1899[v1955];
    int * v1903 = v1776->cache_dirty;
    int v2050 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1904 = v1903[v2050];
    bool v2051 = !(v1904 == 0);
    if (v2051) {
      int * v1905 = v1776->cache_tags;
      int v1906 = v1905[v2050];
      int * v1907 = v1776->cache_vals;
      int v2054 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1908 = v1907[v2054];
      int v2055 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1909 = v1907[v2055];
      int * v1910 = v1776->mem;
      int v2057 = v1906 * 2;
      v1910[v2057] = v1908;
      int * v1912 = v1776->mem;
      int v2060 = (v1906 * 2) + 1;
      v1912[v2060] = v1909;
      ;
    } else {
      ;
    }
    int * v1917 = v1776->mem;
    int v2065 = ((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) * 2;
    int v1918 = v1917[v2065];
    int v2066 = (((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1919 = v1917[v2066];
    int * v1920 = v1776->cache_vals;
    int v2068 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1920[v2068] = v1918;
    int * v1922 = v1776->cache_vals;
    int v2071 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1898 + ((~(((v1900 ^ -1) | (-(v1900 ^ -1))) >> 31)) & 2)) - (v1901 + ((~(((v1902 ^ -1) | (-(v1902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1922[v2071] = v1919;
    int * v1924 = v1776->cache_tags;
    int v2074 = (int)((unsigned int)((int)((unsigned int)(v1780 + 68) >> 2)) >> 1);
    v1924[v2050] = v2074;
    int * v1926 = v1776->cache_dirty;
    v1926[v2050] = 0;
    int * v1928 = v1776->cache_age;
    v1928[v2050] = 1;
    int * v1930 = v1776->cache_age;
    int v1931 = v1930[v2050];
    int v1932 = v1930[v1954];
    int v2080 = v1932 + ((int)((unsigned int)(v1932 - v1931) >> 31));
    v1930[v1954] = v2080;
    int * v1934 = v1776->cache_age;
    int v1935 = v1934[v1955];
    int v2082 = v1935 + ((int)((unsigned int)(v1935 - v1931) >> 31));
    v1934[v1955] = v2082;
    int * v1937 = v1776->cache_age;
    v1937[v2050] = 0;
    v1940 = v2050;
  }
  int * v1941 = v1776->cache_vals;
  int v2085 = (v1940 * 2) + (((int)((unsigned int)(v1780 + 68) >> 2)) & 1);
  v1941[v2085] = v1781;
  int * v1943 = v1776->cache_dirty;
  v1943[v1940] = 1;
  struct StateT * v1945 = slot_18(v1776);
  return v1945;
}

struct StateT * slot_20(struct StateT * v293) {
  int v294 = v293->timer;
  int v404 = v294 + 1;
  v293->timer = v404;
  int * v296 = v293->regs;
  int v297 = v296[10];
  int * v298 = v293->cache_tags;
  int v408 = (((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2;
  int v299 = v298[v408];
  int v409 = ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v300 = v298[v409];
  int v410 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2);
  int v301 = v298[v410];
  int v411 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v302 = v298[v411];
  int v303 = v293->timer;
  int v412 = v303 + ((100 ^ (((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v300 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v300 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v293->timer = v412;
  int * v305 = v293->cache_vals;
  bool v413 = !(((~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v300 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v300 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v398;
  if (v413) {
    int * v306 = v293->cache_age;
    int v415 = ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v300 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v300 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v307 = v306[v415];
    int v308 = v306[v408];
    int v416 = v308 + ((int)((unsigned int)(v308 - v307) >> 31));
    v306[v408] = v416;
    int * v310 = v293->cache_age;
    int v311 = v310[v409];
    int v418 = v311 + ((int)((unsigned int)(v311 - v307) >> 31));
    v310[v409] = v418;
    int * v313 = v293->cache_age;
    v313[v415] = 0;
    v398 = v415;
  } else {
    int * v316 = v293->cache_age;
    int v422 = (((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2;
    int v317 = v316[v422];
    int * v318 = v293->cache_tags;
    int v319 = v318[v422];
    int v320 = v316[v409];
    int v321 = v318[v409];
    bool v424 = !(((~(((v301 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v301 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v375;
    if (v424) {
      int * v322 = v293->cache_age;
      int v426 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v323 = v322[v426];
      int v324 = v322[v410];
      int v427 = v324 + ((int)((unsigned int)(v324 - v323) >> 31));
      v322[v410] = v427;
      int * v326 = v293->cache_age;
      int v327 = v326[v411];
      int v429 = v327 + ((int)((unsigned int)(v327 - v323) >> 31));
      v326[v411] = v429;
      int * v329 = v293->cache_age;
      v329[v426] = 0;
      v375 = v426;
    } else {
      int * v332 = v293->cache_age;
      int v433 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2);
      int v333 = v332[v433];
      int * v334 = v293->cache_tags;
      int v335 = v334[v433];
      int v336 = v332[v411];
      int v337 = v334[v411];
      int * v338 = v293->cache_dirty;
      int v436 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v339 = v338[v436];
      bool v437 = !(v339 == 0);
      if (v437) {
        int * v340 = v293->cache_tags;
        int v341 = v340[v436];
        int * v342 = v293->cache_vals;
        int v440 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v343 = v342[v440];
        int v441 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v344 = v342[v441];
        int * v345 = v293->mem;
        int v443 = v341 * 2;
        v345[v443] = v343;
        int * v347 = v293->mem;
        int v446 = (v341 * 2) + 1;
        v347[v446] = v344;
        ;
      } else {
        ;
      }
      int * v352 = v293->mem;
      int v451 = ((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) * 2;
      int v353 = v352[v451];
      int v452 = (((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) * 2) + 1;
      int v354 = v352[v452];
      int * v355 = v293->cache_vals;
      int v454 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v355[v454] = v353;
      int * v357 = v293->cache_vals;
      int v457 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v333 + ((~(((v335 ^ -1) | (-(v335 ^ -1))) >> 31)) & 2)) - (v336 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v357[v457] = v354;
      int * v359 = v293->cache_tags;
      int v460 = (int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1);
      v359[v436] = v460;
      int * v361 = v293->cache_dirty;
      v361[v436] = 0;
      int * v363 = v293->cache_age;
      v363[v436] = 1;
      int * v365 = v293->cache_age;
      int v366 = v365[v436];
      int v367 = v365[v410];
      int v466 = v367 + ((int)((unsigned int)(v367 - v366) >> 31));
      v365[v410] = v466;
      int * v369 = v293->cache_age;
      int v370 = v369[v411];
      int v468 = v370 + ((int)((unsigned int)(v370 - v366) >> 31));
      v369[v411] = v468;
      int * v372 = v293->cache_age;
      v372[v436] = 0;
      v375 = v436;
    }
    int * v376 = v293->cache_vals;
    int v471 = v375 * 2;
    int v377 = v376[v471];
    int v472 = (v375 * 2) + 1;
    int v378 = v376[v472];
    int v473 = (((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v376[v473] = v377;
    int * v380 = v293->cache_vals;
    int v476 = ((((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v380[v476] = v378;
    int * v382 = v293->cache_tags;
    int v479 = ((((int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v317 + ((~(((v319 ^ -1) | (-(v319 ^ -1))) >> 31)) & 2)) - (v320 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v480 = (int)((unsigned int)((int)((unsigned int)(v297 + 4) >> 2)) >> 1);
    v382[v479] = v480;
    int * v384 = v293->cache_dirty;
    v384[v479] = 0;
    int * v386 = v293->cache_age;
    v386[v479] = 1;
    int * v388 = v293->cache_age;
    int v389 = v388[v479];
    int v390 = v388[v408];
    int v486 = v390 + ((int)((unsigned int)(v390 - v389) >> 31));
    v388[v408] = v486;
    int * v392 = v293->cache_age;
    int v393 = v392[v409];
    int v488 = v393 + ((int)((unsigned int)(v393 - v389) >> 31));
    v392[v409] = v488;
    int * v395 = v293->cache_age;
    v395[v479] = 0;
    v398 = v479;
  }
  int v491 = (v398 * 2) + (((int)((unsigned int)(v297 + 4) >> 2)) & 1);
  int v399 = v305[v491];
  int * v400 = v293->regs;
  v400[10] = v399;
  struct StateT * v402 = slot_21(v293);
  return v402;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v1264) {
  int v1265 = v1264->timer;
  int v1271 = v1265 + 1;
  v1264->timer = v1271;
  int * v1267 = v1264->regs;
  v1267[11] = 0;
  struct StateT * v1269 = slot_9(v1264);
  return v1269;
}

struct StateT * slot_4(struct StateT * v280) {
  int v281 = v280->timer;
  int v287 = v281 + 1;
  v280->timer = v287;
  int * v283 = v280->regs;
  v283[11] = 0;
  struct StateT * v285 = slot_5(v280);
  return v285;
}

struct StateT * slot_15(struct StateT * v1556) {
  int v1557 = v1556->timer;
  int v1667 = v1557 + 1;
  v1556->timer = v1667;
  int * v1559 = v1556->regs;
  int v1560 = v1559[12];
  int * v1561 = v1556->cache_tags;
  int v1671 = (((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1562 = v1561[v1671];
  int v1672 = ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1563 = v1561[v1672];
  int v1673 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1564 = v1561[v1673];
  int v1674 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1565 = v1561[v1674];
  int v1566 = v1556->timer;
  int v1675 = v1566 + ((100 ^ (((~(((v1564 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1564 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1562 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1562 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1563 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1563 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1564 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1564 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1556->timer = v1675;
  int * v1568 = v1556->cache_vals;
  bool v1676 = !(((~(((v1562 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1562 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1563 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1563 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1661;
  if (v1676) {
    int * v1569 = v1556->cache_age;
    int v1678 = ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1563 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1563 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1570 = v1569[v1678];
    int v1571 = v1569[v1671];
    int v1679 = v1571 + ((int)((unsigned int)(v1571 - v1570) >> 31));
    v1569[v1671] = v1679;
    int * v1573 = v1556->cache_age;
    int v1574 = v1573[v1672];
    int v1681 = v1574 + ((int)((unsigned int)(v1574 - v1570) >> 31));
    v1573[v1672] = v1681;
    int * v1576 = v1556->cache_age;
    v1576[v1678] = 0;
    v1661 = v1678;
  } else {
    int * v1579 = v1556->cache_age;
    int v1685 = (((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1580 = v1579[v1685];
    int * v1581 = v1556->cache_tags;
    int v1582 = v1581[v1685];
    int v1583 = v1579[v1672];
    int v1584 = v1581[v1672];
    bool v1687 = !(((~(((v1564 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1564 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1638;
    if (v1687) {
      int * v1585 = v1556->cache_age;
      int v1689 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))) | (-(v1565 ^ ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1586 = v1585[v1689];
      int v1587 = v1585[v1673];
      int v1690 = v1587 + ((int)((unsigned int)(v1587 - v1586) >> 31));
      v1585[v1673] = v1690;
      int * v1589 = v1556->cache_age;
      int v1590 = v1589[v1674];
      int v1692 = v1590 + ((int)((unsigned int)(v1590 - v1586) >> 31));
      v1589[v1674] = v1692;
      int * v1592 = v1556->cache_age;
      v1592[v1689] = 0;
      v1638 = v1689;
    } else {
      int * v1595 = v1556->cache_age;
      int v1696 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1596 = v1595[v1696];
      int * v1597 = v1556->cache_tags;
      int v1598 = v1597[v1696];
      int v1599 = v1595[v1674];
      int v1600 = v1597[v1674];
      int * v1601 = v1556->cache_dirty;
      int v1699 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1596 + ((~(((v1598 ^ -1) | (-(v1598 ^ -1))) >> 31)) & 2)) - (v1599 + ((~(((v1600 ^ -1) | (-(v1600 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1602 = v1601[v1699];
      bool v1700 = !(v1602 == 0);
      if (v1700) {
        int * v1603 = v1556->cache_tags;
        int v1604 = v1603[v1699];
        int * v1605 = v1556->cache_vals;
        int v1703 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1596 + ((~(((v1598 ^ -1) | (-(v1598 ^ -1))) >> 31)) & 2)) - (v1599 + ((~(((v1600 ^ -1) | (-(v1600 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1606 = v1605[v1703];
        int v1704 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1596 + ((~(((v1598 ^ -1) | (-(v1598 ^ -1))) >> 31)) & 2)) - (v1599 + ((~(((v1600 ^ -1) | (-(v1600 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1607 = v1605[v1704];
        int * v1608 = v1556->mem;
        int v1706 = v1604 * 2;
        v1608[v1706] = v1606;
        int * v1610 = v1556->mem;
        int v1709 = (v1604 * 2) + 1;
        v1610[v1709] = v1607;
        ;
      } else {
        ;
      }
      int * v1615 = v1556->mem;
      int v1714 = ((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) * 2;
      int v1616 = v1615[v1714];
      int v1715 = (((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1617 = v1615[v1715];
      int * v1618 = v1556->cache_vals;
      int v1717 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1596 + ((~(((v1598 ^ -1) | (-(v1598 ^ -1))) >> 31)) & 2)) - (v1599 + ((~(((v1600 ^ -1) | (-(v1600 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1618[v1717] = v1616;
      int * v1620 = v1556->cache_vals;
      int v1720 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1596 + ((~(((v1598 ^ -1) | (-(v1598 ^ -1))) >> 31)) & 2)) - (v1599 + ((~(((v1600 ^ -1) | (-(v1600 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1620[v1720] = v1617;
      int * v1622 = v1556->cache_tags;
      int v1723 = (int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1);
      v1622[v1699] = v1723;
      int * v1624 = v1556->cache_dirty;
      v1624[v1699] = 0;
      int * v1626 = v1556->cache_age;
      v1626[v1699] = 1;
      int * v1628 = v1556->cache_age;
      int v1629 = v1628[v1699];
      int v1630 = v1628[v1673];
      int v1729 = v1630 + ((int)((unsigned int)(v1630 - v1629) >> 31));
      v1628[v1673] = v1729;
      int * v1632 = v1556->cache_age;
      int v1633 = v1632[v1674];
      int v1731 = v1633 + ((int)((unsigned int)(v1633 - v1629) >> 31));
      v1632[v1674] = v1731;
      int * v1635 = v1556->cache_age;
      v1635[v1699] = 0;
      v1638 = v1699;
    }
    int * v1639 = v1556->cache_vals;
    int v1734 = v1638 * 2;
    int v1640 = v1639[v1734];
    int v1735 = (v1638 * 2) + 1;
    int v1641 = v1639[v1735];
    int v1736 = (((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1580 + ((~(((v1582 ^ -1) | (-(v1582 ^ -1))) >> 31)) & 2)) - (v1583 + ((~(((v1584 ^ -1) | (-(v1584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1639[v1736] = v1640;
    int * v1643 = v1556->cache_vals;
    int v1739 = ((((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1580 + ((~(((v1582 ^ -1) | (-(v1582 ^ -1))) >> 31)) & 2)) - (v1583 + ((~(((v1584 ^ -1) | (-(v1584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1643[v1739] = v1641;
    int * v1645 = v1556->cache_tags;
    int v1742 = ((((int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1580 + ((~(((v1582 ^ -1) | (-(v1582 ^ -1))) >> 31)) & 2)) - (v1583 + ((~(((v1584 ^ -1) | (-(v1584 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1743 = (int)((unsigned int)((int)((unsigned int)(v1560 + 68) >> 2)) >> 1);
    v1645[v1742] = v1743;
    int * v1647 = v1556->cache_dirty;
    v1647[v1742] = 0;
    int * v1649 = v1556->cache_age;
    v1649[v1742] = 1;
    int * v1651 = v1556->cache_age;
    int v1652 = v1651[v1742];
    int v1653 = v1651[v1671];
    int v1749 = v1653 + ((int)((unsigned int)(v1653 - v1652) >> 31));
    v1651[v1671] = v1749;
    int * v1655 = v1556->cache_age;
    int v1656 = v1655[v1672];
    int v1751 = v1656 + ((int)((unsigned int)(v1656 - v1652) >> 31));
    v1655[v1672] = v1751;
    int * v1658 = v1556->cache_age;
    v1658[v1742] = 0;
    v1661 = v1742;
  }
  int v1754 = (v1661 * 2) + (((int)((unsigned int)(v1560 + 68) >> 2)) & 1);
  int v1662 = v1568[v1754];
  int * v1663 = v1556->regs;
  v1663[11] = v1662;
  struct StateT * v1665 = slot_16(v1556);
  return v1665;
}

struct StateT * slot_18(struct StateT * v240) {
  int v241 = v240->timer;
  int v247 = v241 + 1;
  v240->timer = v247;
  int * v243 = v240->regs;
  v243[10] = 0;
  struct StateT * v245 = slot_19(v240);
  return v245;
}

struct StateT * slot_9(struct StateT * v1282) {
  int v1283 = v1282->timer;
  int v1290 = v1283 + 1;
  v1282->timer = v1290;
  int * v1285 = v1282->regs;
  int v1286 = v1285[11];
  int v1293 = v1286 + 4;
  v1285[11] = v1293;
  struct StateT * v1288 = slot_10(v1282);
  return v1288;
}

struct StateT * slot_22(struct StateT * v730) {
  int v731 = v730->timer;
  int v739 = v731 + 1;
  v730->timer = v739;
  int * v733 = v730->regs;
  int v734 = v733[12];
  int v735 = v733[10];
  int v743 = v734 & v735;
  v733[10] = v743;
  struct StateT * v737 = slot_23(v730);
  return v737;
}

struct StateT * slot_11(struct StateT * v1309) {
  int v1310 = v1309->timer;
  int v1317 = v1310 + 1;
  v1309->timer = v1317;
  int * v1312 = v1309->regs;
  int v1313 = v1312[10];
  int v1320 = v1313 << 29;
  v1312[10] = v1320;
  struct StateT * v1315 = slot_12(v1309);
  return v1315;
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