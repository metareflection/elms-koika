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

struct StateT * slot_12(struct StateT * v1334);
struct StateT * slot_43(struct StateT * v4559);
struct StateT * slot_70(struct StateT * v7356);
struct StateT * slot_76(struct StateT * v8050);
struct StateT * slot_6(struct StateT * v1226);
struct StateT * slot_47(struct StateT * v4632);
struct StateT * slot_29(struct StateT * v2602);
struct StateT * slot_55(struct StateT * v5741);
struct StateT * slot_16(struct StateT * v1397);
struct StateT * slot_5(struct StateT * v1022);
struct StateT * slot_7(struct StateT * v1241);
struct StateT * slot_31(struct StateT * v2634);
struct StateT * slot_54(struct StateT * v5717);
struct StateT * slot_26(struct StateT * v2537);
struct StateT * slot_65(struct StateT * v7071);
struct StateT * slot_10(struct StateT * v1307);
struct StateT * slot_74(struct StateT * v7420);
struct StateT * slot_19(struct StateT * v1454);
struct StateT * slot_58(struct StateT * v5798);
struct StateT * slot_67(struct StateT * v7290);
struct StateT * slot_64(struct StateT * v6867);
struct StateT * slot_14(struct StateT * v1366);
struct StateT * slot_53(struct StateT * v5701);
struct StateT * slot_44(struct StateT * v4575);
struct StateT * slot_66(struct StateT * v7275);
struct StateT * slot_28(struct StateT * v2586);
struct StateT * slot_32(struct StateT * v2650);
struct StateT * slot_17(struct StateT * v1422);
struct StateT * slot_49(struct StateT * v4963);
struct StateT * slot_33(struct StateT * v2965);
struct StateT * slot_50(struct StateT * v5278);
struct StateT * slot_36(struct StateT * v3688);
struct StateT * slot_37(struct StateT * v3892);
struct StateT * slot_57(struct StateT * v5782);
struct StateT * slot_68(struct StateT * v7306);
struct StateT * slot_59(struct StateT * v5814);
struct StateT * slot_40(struct StateT * v4504);
struct StateT * slot_27(struct StateT * v2561);
struct StateT * slot_15(struct StateT * v1381);
struct StateT * slot_62(struct StateT * v6460);
struct StateT * slot_48(struct StateT * v4648);
struct StateT * slot_22(struct StateT * v2098);
struct StateT * slot_35(struct StateT * v3484);
struct StateT * slot_75(struct StateT * v7735);
struct StateT * slot_56(struct StateT * v5766);
struct StateT * slot_72(struct StateT * v7388);
struct StateT * slot_34(struct StateT * v3280);
struct StateT * slot_71(struct StateT * v7372);
struct StateT * slot_51(struct StateT * v5482);
struct StateT * slot_52(struct StateT * v5686);
struct StateT * slot_25(struct StateT * v2521);
struct StateT * slot_23(struct StateT * v2302);
struct StateT * slot_2(struct StateT * v410);
struct StateT * slot_21(struct StateT * v1783);
struct StateT * slot_3(struct StateT * v614);
struct StateT * slot_45(struct StateT * v4600);
struct StateT * slot_73(struct StateT * v7404);
struct StateT * slot_1(struct StateT * v206);
struct StateT * slot_69(struct StateT * v7331);
struct StateT * slot_13(struct StateT * v1350);
struct StateT * slot_38(struct StateT * v4096);
struct StateT * slot_63(struct StateT * v6664);
struct StateT * slot_24(struct StateT * v2506);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v4535);
struct StateT * slot_46(struct StateT * v4616);
struct StateT * slot_20(struct StateT * v1468);
struct StateT * slot_61(struct StateT * v6145);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v4519);
struct StateT * slot_39(struct StateT * v4300);
struct StateT * slot_8(struct StateT * v1266);
struct StateT * slot_30(struct StateT * v2618);
struct StateT * slot_60(struct StateT * v5830);
struct StateT * slot_4(struct StateT * v818);
struct StateT * slot_18(struct StateT * v1438);
struct StateT * slot_9(struct StateT * v1283);
struct StateT * slot_11(struct StateT * v1320);
struct StateT * slot_12(struct StateT * v1334) {
  int v1335 = v1334->timer;
  int v1343 = v1335 + 1;
  v1334->timer = v1343;
  int * v1337 = v1334->regs;
  int v1338 = v1337[13];
  int v1339 = v1337[12];
  int v1347 = v1338 + v1339;
  v1337[13] = v1347;
  struct StateT * v1341 = slot_13(v1334);
  return v1341;
}

struct StateT * slot_43(struct StateT * v4559) {
  int v4560 = v4559->timer;
  int v4568 = v4560 + 1;
  v4559->timer = v4568;
  int * v4562 = v4559->regs;
  int v4563 = v4562[14];
  int v4564 = v4562[16];
  int v4572 = v4563 - v4564;
  v4562[14] = v4572;
  struct StateT * v4566 = slot_44(v4559);
  return v4566;
}

struct StateT * slot_70(struct StateT * v7356) {
  int v7357 = v7356->timer;
  int v7365 = v7357 + 1;
  v7356->timer = v7365;
  int * v7359 = v7356->regs;
  int v7360 = v7359[11];
  int v7361 = v7359[15];
  int v7369 = v7360 - v7361;
  v7359[11] = v7369;
  struct StateT * v7363 = slot_71(v7356);
  return v7363;
}

struct StateT * slot_76(struct StateT * v8050) {
  int v8051 = v8050->timer;
  int v8054 = v8051 + 1;
  v8050->timer = v8054;
  return v8050;
}

struct StateT * slot_6(struct StateT * v1226) {
  int v1227 = v1226->timer;
  int v1234 = v1227 + 1;
  v1226->timer = v1234;
  int * v1229 = v1226->regs;
  int v1230 = v1229[12];
  int v1238 = v1230 + -8;
  v1229[5] = v1238;
  struct StateT * v1232 = slot_7(v1226);
  return v1232;
}

struct StateT * slot_47(struct StateT * v4632) {
  int v4633 = v4632->timer;
  int v4641 = v4633 + 1;
  v4632->timer = v4641;
  int * v4635 = v4632->regs;
  int v4636 = v4635[13];
  int v4637 = v4635[16];
  int v4645 = v4636 - v4637;
  v4635[13] = v4645;
  struct StateT * v4639 = slot_48(v4632);
  return v4639;
}

struct StateT * slot_29(struct StateT * v2602) {
  int v2603 = v2602->timer;
  int v2611 = v2603 + 1;
  v2602->timer = v2611;
  int * v2605 = v2602->regs;
  int v2606 = v2605[15];
  int v2607 = v2605[16];
  int v2615 = v2606 - v2607;
  v2605[15] = v2615;
  struct StateT * v2609 = slot_30(v2602);
  return v2609;
}

struct StateT * slot_55(struct StateT * v5741) {
  int v5742 = v5741->timer;
  int v5754 = v5742 + 1;
  v5741->timer = v5754;
  int * v5744 = v5741->regs;
  int v5745 = v5744[15];
  int v5746 = v5744[17];
  bool v5758 = (v5745 ^ -2147483648) < (v5746 ^ -2147483648);
  int v5749;
  if (v5758) {
    v5749 = 1;
  } else {
    v5749 = 0;
  }
  int * v5750 = v5741->regs;
  v5750[16] = v5749;
  struct StateT * v5752 = slot_56(v5741);
  return v5752;
}

struct StateT * slot_16(struct StateT * v1397) {
  int v1398 = v1397->timer;
  int v1410 = v1398 + 1;
  v1397->timer = v1410;
  int * v1400 = v1397->regs;
  int v1401 = v1400[15];
  int v1402 = v1400[7];
  bool v1414 = (v1401 ^ -2147483648) < (v1402 ^ -2147483648);
  int v1405;
  if (v1414) {
    v1405 = 1;
  } else {
    v1405 = 0;
  }
  int * v1406 = v1397->regs;
  v1406[5] = v1405;
  struct StateT * v1408 = slot_17(v1397);
  return v1408;
}

struct StateT * slot_5(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1133 = v1023 + 1;
  v1022->timer = v1133;
  int * v1025 = v1022->regs;
  int v1026 = v1025[10];
  int * v1027 = v1022->cache_tags;
  int v1137 = (((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2;
  int v1028 = v1027[v1137];
  int v1138 = ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1029 = v1027[v1138];
  int v1139 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2);
  int v1030 = v1027[v1139];
  int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1031 = v1027[v1140];
  int v1032 = v1022->timer;
  int v1141 = v1032 + ((100 ^ (((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1022->timer = v1141;
  int * v1034 = v1022->cache_vals;
  bool v1142 = !(((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v1127;
  if (v1142) {
    int * v1035 = v1022->cache_age;
    int v1144 = ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1029 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v1036 = v1035[v1144];
    int v1037 = v1035[v1137];
    int v1145 = v1037 + ((int)((unsigned int)(v1037 - v1036) >> 31));
    v1035[v1137] = v1145;
    int * v1039 = v1022->cache_age;
    int v1040 = v1039[v1138];
    int v1147 = v1040 + ((int)((unsigned int)(v1040 - v1036) >> 31));
    v1039[v1138] = v1147;
    int * v1042 = v1022->cache_age;
    v1042[v1144] = 0;
    v1127 = v1144;
  } else {
    int * v1045 = v1022->cache_age;
    int v1151 = (((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2;
    int v1046 = v1045[v1151];
    int * v1047 = v1022->cache_tags;
    int v1048 = v1047[v1151];
    int v1049 = v1045[v1138];
    int v1050 = v1047[v1138];
    bool v1153 = !(((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v1104;
    if (v1153) {
      int * v1051 = v1022->cache_age;
      int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v1052 = v1051[v1155];
      int v1053 = v1051[v1139];
      int v1156 = v1053 + ((int)((unsigned int)(v1053 - v1052) >> 31));
      v1051[v1139] = v1156;
      int * v1055 = v1022->cache_age;
      int v1056 = v1055[v1140];
      int v1158 = v1056 + ((int)((unsigned int)(v1056 - v1052) >> 31));
      v1055[v1140] = v1158;
      int * v1058 = v1022->cache_age;
      v1058[v1155] = 0;
      v1104 = v1155;
    } else {
      int * v1061 = v1022->cache_age;
      int v1162 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2);
      int v1062 = v1061[v1162];
      int * v1063 = v1022->cache_tags;
      int v1064 = v1063[v1162];
      int v1065 = v1061[v1140];
      int v1066 = v1063[v1140];
      int * v1067 = v1022->cache_dirty;
      int v1165 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1068 = v1067[v1165];
      bool v1166 = !(v1068 == 0);
      if (v1166) {
        int * v1069 = v1022->cache_tags;
        int v1070 = v1069[v1165];
        int * v1071 = v1022->cache_vals;
        int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1072 = v1071[v1169];
        int v1170 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1073 = v1071[v1170];
        int * v1074 = v1022->mem;
        int v1172 = v1070 * 2;
        v1074[v1172] = v1072;
        int * v1076 = v1022->mem;
        int v1175 = (v1070 * 2) + 1;
        v1076[v1175] = v1073;
        ;
      } else {
        ;
      }
      int * v1081 = v1022->mem;
      int v1180 = ((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) * 2;
      int v1082 = v1081[v1180];
      int v1181 = (((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) * 2) + 1;
      int v1083 = v1081[v1181];
      int * v1084 = v1022->cache_vals;
      int v1183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1084[v1183] = v1082;
      int * v1086 = v1022->cache_vals;
      int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1086[v1186] = v1083;
      int * v1088 = v1022->cache_tags;
      int v1189 = (int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1);
      v1088[v1165] = v1189;
      int * v1090 = v1022->cache_dirty;
      v1090[v1165] = 0;
      int * v1092 = v1022->cache_age;
      v1092[v1165] = 1;
      int * v1094 = v1022->cache_age;
      int v1095 = v1094[v1165];
      int v1096 = v1094[v1139];
      int v1195 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
      v1094[v1139] = v1195;
      int * v1098 = v1022->cache_age;
      int v1099 = v1098[v1140];
      int v1197 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
      v1098[v1140] = v1197;
      int * v1101 = v1022->cache_age;
      v1101[v1165] = 0;
      v1104 = v1165;
    }
    int * v1105 = v1022->cache_vals;
    int v1200 = v1104 * 2;
    int v1106 = v1105[v1200];
    int v1201 = (v1104 * 2) + 1;
    int v1107 = v1105[v1201];
    int v1202 = (((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1105[v1202] = v1106;
    int * v1109 = v1022->cache_vals;
    int v1205 = ((((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1109[v1205] = v1107;
    int * v1111 = v1022->cache_tags;
    int v1208 = ((((int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1209 = (int)((unsigned int)((int)((unsigned int)(v1026 + 12) >> 2)) >> 1);
    v1111[v1208] = v1209;
    int * v1113 = v1022->cache_dirty;
    v1113[v1208] = 0;
    int * v1115 = v1022->cache_age;
    v1115[v1208] = 1;
    int * v1117 = v1022->cache_age;
    int v1118 = v1117[v1208];
    int v1119 = v1117[v1137];
    int v1215 = v1119 + ((int)((unsigned int)(v1119 - v1118) >> 31));
    v1117[v1137] = v1215;
    int * v1121 = v1022->cache_age;
    int v1122 = v1121[v1138];
    int v1217 = v1122 + ((int)((unsigned int)(v1122 - v1118) >> 31));
    v1121[v1138] = v1217;
    int * v1124 = v1022->cache_age;
    v1124[v1208] = 0;
    v1127 = v1208;
  }
  int v1220 = (v1127 * 2) + (((int)((unsigned int)(v1026 + 12) >> 2)) & 1);
  int v1128 = v1034[v1220];
  int * v1129 = v1022->regs;
  v1129[17] = v1128;
  struct StateT * v1131 = slot_6(v1022);
  return v1131;
}

struct StateT * slot_7(struct StateT * v1241) {
  int v1242 = v1241->timer;
  int v1254 = v1242 + 1;
  v1241->timer = v1254;
  int * v1244 = v1241->regs;
  int v1245 = v1244[5];
  int v1246 = v1244[12];
  bool v1258 = (v1245 ^ -2147483648) < (v1246 ^ -2147483648);
  int v1249;
  if (v1258) {
    v1249 = 1;
  } else {
    v1249 = 0;
  }
  int * v1250 = v1241->regs;
  v1250[6] = v1249;
  struct StateT * v1252 = slot_8(v1241);
  return v1252;
}

struct StateT * slot_31(struct StateT * v2634) {
  int v2635 = v2634->timer;
  int v2643 = v2635 + 1;
  v2634->timer = v2643;
  int * v2637 = v2634->regs;
  int v2638 = v2637[13];
  int v2639 = v2637[5];
  int v2647 = v2638 - v2639;
  v2637[13] = v2647;
  struct StateT * v2641 = slot_32(v2634);
  return v2641;
}

struct StateT * slot_54(struct StateT * v5717) {
  int v5718 = v5717->timer;
  int v5730 = v5718 + 1;
  v5717->timer = v5730;
  int * v5720 = v5717->regs;
  int v5721 = v5720[15];
  int v5722 = v5720[13];
  bool v5734 = (v5721 ^ -2147483648) < (v5722 ^ -2147483648);
  int v5725;
  if (v5734) {
    v5725 = 1;
  } else {
    v5725 = 0;
  }
  int * v5726 = v5717->regs;
  v5726[13] = v5725;
  struct StateT * v5728 = slot_55(v5717);
  return v5728;
}

struct StateT * slot_26(struct StateT * v2537) {
  int v2538 = v2537->timer;
  int v2550 = v2538 + 1;
  v2537->timer = v2550;
  int * v2540 = v2537->regs;
  int v2541 = v2540[15];
  int v2542 = v2540[13];
  bool v2554 = (v2541 ^ -2147483648) < (v2542 ^ -2147483648);
  int v2545;
  if (v2554) {
    v2545 = 1;
  } else {
    v2545 = 0;
  }
  int * v2546 = v2537->regs;
  v2546[13] = v2545;
  struct StateT * v2548 = slot_27(v2537);
  return v2548;
}

struct StateT * slot_65(struct StateT * v7071) {
  int v7072 = v7071->timer;
  int v7182 = v7072 + 1;
  v7071->timer = v7182;
  int * v7074 = v7071->regs;
  int v7075 = v7074[10];
  int * v7076 = v7071->cache_tags;
  int v7186 = (((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2;
  int v7077 = v7076[v7186];
  int v7187 = ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7078 = v7076[v7187];
  int v7188 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2);
  int v7079 = v7076[v7188];
  int v7189 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7080 = v7076[v7189];
  int v7081 = v7071->timer;
  int v7190 = v7081 + ((100 ^ (((~(((v7079 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7079 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7077 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7077 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7078 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7078 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7079 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7079 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7071->timer = v7190;
  int * v7083 = v7071->cache_vals;
  bool v7191 = !(((~(((v7077 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7077 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7078 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7078 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7176;
  if (v7191) {
    int * v7084 = v7071->cache_age;
    int v7193 = ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v7078 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7078 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7085 = v7084[v7193];
    int v7086 = v7084[v7186];
    int v7194 = v7086 + ((int)((unsigned int)(v7086 - v7085) >> 31));
    v7084[v7186] = v7194;
    int * v7088 = v7071->cache_age;
    int v7089 = v7088[v7187];
    int v7196 = v7089 + ((int)((unsigned int)(v7089 - v7085) >> 31));
    v7088[v7187] = v7196;
    int * v7091 = v7071->cache_age;
    v7091[v7193] = 0;
    v7176 = v7193;
  } else {
    int * v7094 = v7071->cache_age;
    int v7200 = (((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2;
    int v7095 = v7094[v7200];
    int * v7096 = v7071->cache_tags;
    int v7097 = v7096[v7200];
    int v7098 = v7094[v7187];
    int v7099 = v7096[v7187];
    bool v7202 = !(((~(((v7079 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7079 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v7153;
    if (v7202) {
      int * v7100 = v7071->cache_age;
      int v7204 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))) | (-(v7080 ^ ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v7101 = v7100[v7204];
      int v7102 = v7100[v7188];
      int v7205 = v7102 + ((int)((unsigned int)(v7102 - v7101) >> 31));
      v7100[v7188] = v7205;
      int * v7104 = v7071->cache_age;
      int v7105 = v7104[v7189];
      int v7207 = v7105 + ((int)((unsigned int)(v7105 - v7101) >> 31));
      v7104[v7189] = v7207;
      int * v7107 = v7071->cache_age;
      v7107[v7204] = 0;
      v7153 = v7204;
    } else {
      int * v7110 = v7071->cache_age;
      int v7211 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2);
      int v7111 = v7110[v7211];
      int * v7112 = v7071->cache_tags;
      int v7113 = v7112[v7211];
      int v7114 = v7110[v7189];
      int v7115 = v7112[v7189];
      int * v7116 = v7071->cache_dirty;
      int v7214 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7111 + ((~(((v7113 ^ -1) | (-(v7113 ^ -1))) >> 31)) & 2)) - (v7114 + ((~(((v7115 ^ -1) | (-(v7115 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7117 = v7116[v7214];
      bool v7215 = !(v7117 == 0);
      if (v7215) {
        int * v7118 = v7071->cache_tags;
        int v7119 = v7118[v7214];
        int * v7120 = v7071->cache_vals;
        int v7218 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7111 + ((~(((v7113 ^ -1) | (-(v7113 ^ -1))) >> 31)) & 2)) - (v7114 + ((~(((v7115 ^ -1) | (-(v7115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7121 = v7120[v7218];
        int v7219 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7111 + ((~(((v7113 ^ -1) | (-(v7113 ^ -1))) >> 31)) & 2)) - (v7114 + ((~(((v7115 ^ -1) | (-(v7115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7122 = v7120[v7219];
        int * v7123 = v7071->mem;
        int v7221 = v7119 * 2;
        v7123[v7221] = v7121;
        int * v7125 = v7071->mem;
        int v7224 = (v7119 * 2) + 1;
        v7125[v7224] = v7122;
        ;
      } else {
        ;
      }
      int * v7130 = v7071->mem;
      int v7229 = ((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) * 2;
      int v7131 = v7130[v7229];
      int v7230 = (((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) * 2) + 1;
      int v7132 = v7130[v7230];
      int * v7133 = v7071->cache_vals;
      int v7232 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7111 + ((~(((v7113 ^ -1) | (-(v7113 ^ -1))) >> 31)) & 2)) - (v7114 + ((~(((v7115 ^ -1) | (-(v7115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7133[v7232] = v7131;
      int * v7135 = v7071->cache_vals;
      int v7235 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7111 + ((~(((v7113 ^ -1) | (-(v7113 ^ -1))) >> 31)) & 2)) - (v7114 + ((~(((v7115 ^ -1) | (-(v7115 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7135[v7235] = v7132;
      int * v7137 = v7071->cache_tags;
      int v7238 = (int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1);
      v7137[v7214] = v7238;
      int * v7139 = v7071->cache_dirty;
      v7139[v7214] = 0;
      int * v7141 = v7071->cache_age;
      v7141[v7214] = 1;
      int * v7143 = v7071->cache_age;
      int v7144 = v7143[v7214];
      int v7145 = v7143[v7188];
      int v7244 = v7145 + ((int)((unsigned int)(v7145 - v7144) >> 31));
      v7143[v7188] = v7244;
      int * v7147 = v7071->cache_age;
      int v7148 = v7147[v7189];
      int v7246 = v7148 + ((int)((unsigned int)(v7148 - v7144) >> 31));
      v7147[v7189] = v7246;
      int * v7150 = v7071->cache_age;
      v7150[v7214] = 0;
      v7153 = v7214;
    }
    int * v7154 = v7071->cache_vals;
    int v7249 = v7153 * 2;
    int v7155 = v7154[v7249];
    int v7250 = (v7153 * 2) + 1;
    int v7156 = v7154[v7250];
    int v7251 = (((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7095 + ((~(((v7097 ^ -1) | (-(v7097 ^ -1))) >> 31)) & 2)) - (v7098 + ((~(((v7099 ^ -1) | (-(v7099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7154[v7251] = v7155;
    int * v7158 = v7071->cache_vals;
    int v7254 = ((((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7095 + ((~(((v7097 ^ -1) | (-(v7097 ^ -1))) >> 31)) & 2)) - (v7098 + ((~(((v7099 ^ -1) | (-(v7099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7158[v7254] = v7156;
    int * v7160 = v7071->cache_tags;
    int v7257 = ((((int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7095 + ((~(((v7097 ^ -1) | (-(v7097 ^ -1))) >> 31)) & 2)) - (v7098 + ((~(((v7099 ^ -1) | (-(v7099 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7258 = (int)((unsigned int)((int)((unsigned int)(v7075 + 36) >> 2)) >> 1);
    v7160[v7257] = v7258;
    int * v7162 = v7071->cache_dirty;
    v7162[v7257] = 0;
    int * v7164 = v7071->cache_age;
    v7164[v7257] = 1;
    int * v7166 = v7071->cache_age;
    int v7167 = v7166[v7257];
    int v7168 = v7166[v7186];
    int v7264 = v7168 + ((int)((unsigned int)(v7168 - v7167) >> 31));
    v7166[v7186] = v7264;
    int * v7170 = v7071->cache_age;
    int v7171 = v7170[v7187];
    int v7266 = v7171 + ((int)((unsigned int)(v7171 - v7167) >> 31));
    v7170[v7187] = v7266;
    int * v7173 = v7071->cache_age;
    v7173[v7257] = 0;
    v7176 = v7257;
  }
  int v7269 = (v7176 * 2) + (((int)((unsigned int)(v7075 + 36) >> 2)) & 1);
  int v7177 = v7083[v7269];
  int * v7178 = v7071->regs;
  v7178[15] = v7177;
  struct StateT * v7180 = slot_66(v7071);
  return v7180;
}

struct StateT * slot_10(struct StateT * v1307) {
  int v1308 = v1307->timer;
  int v1314 = v1308 + 1;
  v1307->timer = v1314;
  int * v1310 = v1307->regs;
  v1310[12] = 4194304;
  struct StateT * v1312 = slot_11(v1307);
  return v1312;
}

struct StateT * slot_74(struct StateT * v7420) {
  int v7421 = v7420->timer;
  int v7591 = v7421 + 1;
  v7420->timer = v7591;
  int * v7423 = v7420->regs;
  int v7424 = v7423[10];
  int v7425 = v7423[14];
  int * v7426 = v7420->cache_tags;
  int v7596 = (((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2;
  int v7427 = v7426[v7596];
  int v7597 = ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7428 = v7426[v7597];
  int v7598 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2);
  int v7429 = v7426[v7598];
  int v7599 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7430 = v7426[v7599];
  int v7431 = v7420->timer;
  int v7600 = v7431 + ((100 ^ (((~(((v7429 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7429 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7427 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7427 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7428 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7428 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7429 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7429 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7420->timer = v7600;
  bool v7601 = !(((~(((v7427 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7427 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7428 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7428 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v7525;
  if (v7601) {
    int * v7433 = v7420->cache_age;
    int v7603 = ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v7428 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7428 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v7434 = v7433[v7603];
    int v7435 = v7433[v7596];
    int v7604 = v7435 + ((int)((unsigned int)(v7435 - v7434) >> 31));
    v7433[v7596] = v7604;
    int * v7437 = v7420->cache_age;
    int v7438 = v7437[v7597];
    int v7606 = v7438 + ((int)((unsigned int)(v7438 - v7434) >> 31));
    v7437[v7597] = v7606;
    int * v7440 = v7420->cache_age;
    v7440[v7603] = 0;
    v7525 = v7603;
  } else {
    int * v7443 = v7420->cache_age;
    int v7610 = (((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2;
    int v7444 = v7443[v7610];
    int * v7445 = v7420->cache_tags;
    int v7446 = v7445[v7610];
    int v7447 = v7443[v7597];
    int v7448 = v7445[v7597];
    bool v7612 = !(((~(((v7429 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7429 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v7502;
    if (v7612) {
      int * v7449 = v7420->cache_age;
      int v7614 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7430 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v7450 = v7449[v7614];
      int v7451 = v7449[v7598];
      int v7615 = v7451 + ((int)((unsigned int)(v7451 - v7450) >> 31));
      v7449[v7598] = v7615;
      int * v7453 = v7420->cache_age;
      int v7454 = v7453[v7599];
      int v7617 = v7454 + ((int)((unsigned int)(v7454 - v7450) >> 31));
      v7453[v7599] = v7617;
      int * v7456 = v7420->cache_age;
      v7456[v7614] = 0;
      v7502 = v7614;
    } else {
      int * v7459 = v7420->cache_age;
      int v7621 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2);
      int v7460 = v7459[v7621];
      int * v7461 = v7420->cache_tags;
      int v7462 = v7461[v7621];
      int v7463 = v7459[v7599];
      int v7464 = v7461[v7599];
      int * v7465 = v7420->cache_dirty;
      int v7624 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7460 + ((~(((v7462 ^ -1) | (-(v7462 ^ -1))) >> 31)) & 2)) - (v7463 + ((~(((v7464 ^ -1) | (-(v7464 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7466 = v7465[v7624];
      bool v7625 = !(v7466 == 0);
      if (v7625) {
        int * v7467 = v7420->cache_tags;
        int v7468 = v7467[v7624];
        int * v7469 = v7420->cache_vals;
        int v7628 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7460 + ((~(((v7462 ^ -1) | (-(v7462 ^ -1))) >> 31)) & 2)) - (v7463 + ((~(((v7464 ^ -1) | (-(v7464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7470 = v7469[v7628];
        int v7629 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7460 + ((~(((v7462 ^ -1) | (-(v7462 ^ -1))) >> 31)) & 2)) - (v7463 + ((~(((v7464 ^ -1) | (-(v7464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7471 = v7469[v7629];
        int * v7472 = v7420->mem;
        int v7631 = v7468 * 2;
        v7472[v7631] = v7470;
        int * v7474 = v7420->mem;
        int v7634 = (v7468 * 2) + 1;
        v7474[v7634] = v7471;
        ;
      } else {
        ;
      }
      int * v7479 = v7420->mem;
      int v7639 = ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) * 2;
      int v7480 = v7479[v7639];
      int v7640 = (((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) * 2) + 1;
      int v7481 = v7479[v7640];
      int * v7482 = v7420->cache_vals;
      int v7642 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7460 + ((~(((v7462 ^ -1) | (-(v7462 ^ -1))) >> 31)) & 2)) - (v7463 + ((~(((v7464 ^ -1) | (-(v7464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7482[v7642] = v7480;
      int * v7484 = v7420->cache_vals;
      int v7645 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7460 + ((~(((v7462 ^ -1) | (-(v7462 ^ -1))) >> 31)) & 2)) - (v7463 + ((~(((v7464 ^ -1) | (-(v7464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7484[v7645] = v7481;
      int * v7486 = v7420->cache_tags;
      int v7648 = (int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1);
      v7486[v7624] = v7648;
      int * v7488 = v7420->cache_dirty;
      v7488[v7624] = 0;
      int * v7490 = v7420->cache_age;
      v7490[v7624] = 1;
      int * v7492 = v7420->cache_age;
      int v7493 = v7492[v7624];
      int v7494 = v7492[v7598];
      int v7654 = v7494 + ((int)((unsigned int)(v7494 - v7493) >> 31));
      v7492[v7598] = v7654;
      int * v7496 = v7420->cache_age;
      int v7497 = v7496[v7599];
      int v7656 = v7497 + ((int)((unsigned int)(v7497 - v7493) >> 31));
      v7496[v7599] = v7656;
      int * v7499 = v7420->cache_age;
      v7499[v7624] = 0;
      v7502 = v7624;
    }
    int * v7503 = v7420->cache_vals;
    int v7659 = v7502 * 2;
    int v7504 = v7503[v7659];
    int v7660 = (v7502 * 2) + 1;
    int v7505 = v7503[v7660];
    int v7661 = (((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7503[v7661] = v7504;
    int * v7507 = v7420->cache_vals;
    int v7664 = ((((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7507[v7664] = v7505;
    int * v7509 = v7420->cache_tags;
    int v7667 = ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7668 = (int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1);
    v7509[v7667] = v7668;
    int * v7511 = v7420->cache_dirty;
    v7511[v7667] = 0;
    int * v7513 = v7420->cache_age;
    v7513[v7667] = 1;
    int * v7515 = v7420->cache_age;
    int v7516 = v7515[v7667];
    int v7517 = v7515[v7596];
    int v7674 = v7517 + ((int)((unsigned int)(v7517 - v7516) >> 31));
    v7515[v7596] = v7674;
    int * v7519 = v7420->cache_age;
    int v7520 = v7519[v7597];
    int v7676 = v7520 + ((int)((unsigned int)(v7520 - v7516) >> 31));
    v7519[v7597] = v7676;
    int * v7522 = v7420->cache_age;
    v7522[v7667] = 0;
    v7525 = v7667;
  }
  int * v7526 = v7420->cache_vals;
  int v7679 = (v7525 * 2) + (((int)((unsigned int)(v7424 + 32) >> 2)) & 1);
  v7526[v7679] = v7425;
  int * v7528 = v7420->cache_tags;
  int v7529 = v7528[v7598];
  int v7530 = v7528[v7599];
  bool v7682 = !(((~(((v7529 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7529 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7530 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7530 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v7584;
  if (v7682) {
    int * v7531 = v7420->cache_age;
    int v7684 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7530 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))) | (-(v7530 ^ ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v7532 = v7531[v7684];
    int v7533 = v7531[v7598];
    int v7685 = v7533 + ((int)((unsigned int)(v7533 - v7532) >> 31));
    v7531[v7598] = v7685;
    int * v7535 = v7420->cache_age;
    int v7536 = v7535[v7599];
    int v7687 = v7536 + ((int)((unsigned int)(v7536 - v7532) >> 31));
    v7535[v7599] = v7687;
    int * v7538 = v7420->cache_age;
    v7538[v7684] = 0;
    v7584 = v7684;
  } else {
    int * v7541 = v7420->cache_age;
    int v7691 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2);
    int v7542 = v7541[v7691];
    int * v7543 = v7420->cache_tags;
    int v7544 = v7543[v7691];
    int v7545 = v7541[v7599];
    int v7546 = v7543[v7599];
    int * v7547 = v7420->cache_dirty;
    int v7694 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7542 + ((~(((v7544 ^ -1) | (-(v7544 ^ -1))) >> 31)) & 2)) - (v7545 + ((~(((v7546 ^ -1) | (-(v7546 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7548 = v7547[v7694];
    bool v7695 = !(v7548 == 0);
    if (v7695) {
      int * v7549 = v7420->cache_tags;
      int v7550 = v7549[v7694];
      int * v7551 = v7420->cache_vals;
      int v7698 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7542 + ((~(((v7544 ^ -1) | (-(v7544 ^ -1))) >> 31)) & 2)) - (v7545 + ((~(((v7546 ^ -1) | (-(v7546 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7552 = v7551[v7698];
      int v7699 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7542 + ((~(((v7544 ^ -1) | (-(v7544 ^ -1))) >> 31)) & 2)) - (v7545 + ((~(((v7546 ^ -1) | (-(v7546 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7553 = v7551[v7699];
      int * v7554 = v7420->mem;
      int v7701 = v7550 * 2;
      v7554[v7701] = v7552;
      int * v7556 = v7420->mem;
      int v7704 = (v7550 * 2) + 1;
      v7556[v7704] = v7553;
      ;
    } else {
      ;
    }
    int * v7561 = v7420->mem;
    int v7709 = ((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) * 2;
    int v7562 = v7561[v7709];
    int v7710 = (((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) * 2) + 1;
    int v7563 = v7561[v7710];
    int * v7564 = v7420->cache_vals;
    int v7712 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7542 + ((~(((v7544 ^ -1) | (-(v7544 ^ -1))) >> 31)) & 2)) - (v7545 + ((~(((v7546 ^ -1) | (-(v7546 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7564[v7712] = v7562;
    int * v7566 = v7420->cache_vals;
    int v7715 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7542 + ((~(((v7544 ^ -1) | (-(v7544 ^ -1))) >> 31)) & 2)) - (v7545 + ((~(((v7546 ^ -1) | (-(v7546 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7566[v7715] = v7563;
    int * v7568 = v7420->cache_tags;
    int v7718 = (int)((unsigned int)((int)((unsigned int)(v7424 + 32) >> 2)) >> 1);
    v7568[v7694] = v7718;
    int * v7570 = v7420->cache_dirty;
    v7570[v7694] = 0;
    int * v7572 = v7420->cache_age;
    v7572[v7694] = 1;
    int * v7574 = v7420->cache_age;
    int v7575 = v7574[v7694];
    int v7576 = v7574[v7598];
    int v7724 = v7576 + ((int)((unsigned int)(v7576 - v7575) >> 31));
    v7574[v7598] = v7724;
    int * v7578 = v7420->cache_age;
    int v7579 = v7578[v7599];
    int v7726 = v7579 + ((int)((unsigned int)(v7579 - v7575) >> 31));
    v7578[v7599] = v7726;
    int * v7581 = v7420->cache_age;
    v7581[v7694] = 0;
    v7584 = v7694;
  }
  int * v7585 = v7420->cache_vals;
  int v7729 = (v7584 * 2) + (((int)((unsigned int)(v7424 + 32) >> 2)) & 1);
  v7585[v7729] = v7425;
  int * v7587 = v7420->cache_dirty;
  v7587[v7584] = 1;
  struct StateT * v7589 = slot_75(v7420);
  return v7589;
}

struct StateT * slot_19(struct StateT * v1454) {
  int v1455 = v1454->timer;
  int v1462 = v1455 + 1;
  v1454->timer = v1462;
  int * v1457 = v1454->regs;
  int v1458 = v1457[13];
  int v1465 = v1458 + -1;
  v1457[13] = v1465;
  struct StateT * v1460 = slot_20(v1454);
  return v1460;
}

struct StateT * slot_58(struct StateT * v5798) {
  int v5799 = v5798->timer;
  int v5807 = v5799 + 1;
  v5798->timer = v5807;
  int * v5801 = v5798->regs;
  int v5802 = v5801[14];
  int v5803 = v5801[13];
  int v5811 = v5802 + v5803;
  v5801[13] = v5811;
  struct StateT * v5805 = slot_59(v5798);
  return v5805;
}

struct StateT * slot_67(struct StateT * v7290) {
  int v7291 = v7290->timer;
  int v7299 = v7291 + 1;
  v7290->timer = v7299;
  int * v7293 = v7290->regs;
  int v7294 = v7293[11];
  int v7295 = v7293[12];
  int v7303 = v7294 + v7295;
  v7293[11] = v7303;
  struct StateT * v7297 = slot_68(v7290);
  return v7297;
}

struct StateT * slot_64(struct StateT * v6867) {
  int v6868 = v6867->timer;
  int v6978 = v6868 + 1;
  v6867->timer = v6978;
  int * v6870 = v6867->regs;
  int v6871 = v6870[10];
  int * v6872 = v6867->cache_tags;
  int v6982 = (((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2;
  int v6873 = v6872[v6982];
  int v6983 = ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6874 = v6872[v6983];
  int v6984 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2);
  int v6875 = v6872[v6984];
  int v6985 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6876 = v6872[v6985];
  int v6877 = v6867->timer;
  int v6986 = v6877 + ((100 ^ (((~(((v6875 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6875 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6873 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6873 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6874 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6874 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6875 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6875 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6867->timer = v6986;
  int * v6879 = v6867->cache_vals;
  bool v6987 = !(((~(((v6873 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6873 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6874 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6874 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v6972;
  if (v6987) {
    int * v6880 = v6867->cache_age;
    int v6989 = ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v6874 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6874 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v6881 = v6880[v6989];
    int v6882 = v6880[v6982];
    int v6990 = v6882 + ((int)((unsigned int)(v6882 - v6881) >> 31));
    v6880[v6982] = v6990;
    int * v6884 = v6867->cache_age;
    int v6885 = v6884[v6983];
    int v6992 = v6885 + ((int)((unsigned int)(v6885 - v6881) >> 31));
    v6884[v6983] = v6992;
    int * v6887 = v6867->cache_age;
    v6887[v6989] = 0;
    v6972 = v6989;
  } else {
    int * v6890 = v6867->cache_age;
    int v6996 = (((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2;
    int v6891 = v6890[v6996];
    int * v6892 = v6867->cache_tags;
    int v6893 = v6892[v6996];
    int v6894 = v6890[v6983];
    int v6895 = v6892[v6983];
    bool v6998 = !(((~(((v6875 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6875 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v6949;
    if (v6998) {
      int * v6896 = v6867->cache_age;
      int v7000 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))) | (-(v6876 ^ ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v6897 = v6896[v7000];
      int v6898 = v6896[v6984];
      int v7001 = v6898 + ((int)((unsigned int)(v6898 - v6897) >> 31));
      v6896[v6984] = v7001;
      int * v6900 = v6867->cache_age;
      int v6901 = v6900[v6985];
      int v7003 = v6901 + ((int)((unsigned int)(v6901 - v6897) >> 31));
      v6900[v6985] = v7003;
      int * v6903 = v6867->cache_age;
      v6903[v7000] = 0;
      v6949 = v7000;
    } else {
      int * v6906 = v6867->cache_age;
      int v7007 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2);
      int v6907 = v6906[v7007];
      int * v6908 = v6867->cache_tags;
      int v6909 = v6908[v7007];
      int v6910 = v6906[v6985];
      int v6911 = v6908[v6985];
      int * v6912 = v6867->cache_dirty;
      int v7010 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6907 + ((~(((v6909 ^ -1) | (-(v6909 ^ -1))) >> 31)) & 2)) - (v6910 + ((~(((v6911 ^ -1) | (-(v6911 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6913 = v6912[v7010];
      bool v7011 = !(v6913 == 0);
      if (v7011) {
        int * v6914 = v6867->cache_tags;
        int v6915 = v6914[v7010];
        int * v6916 = v6867->cache_vals;
        int v7014 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6907 + ((~(((v6909 ^ -1) | (-(v6909 ^ -1))) >> 31)) & 2)) - (v6910 + ((~(((v6911 ^ -1) | (-(v6911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6917 = v6916[v7014];
        int v7015 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6907 + ((~(((v6909 ^ -1) | (-(v6909 ^ -1))) >> 31)) & 2)) - (v6910 + ((~(((v6911 ^ -1) | (-(v6911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6918 = v6916[v7015];
        int * v6919 = v6867->mem;
        int v7017 = v6915 * 2;
        v6919[v7017] = v6917;
        int * v6921 = v6867->mem;
        int v7020 = (v6915 * 2) + 1;
        v6921[v7020] = v6918;
        ;
      } else {
        ;
      }
      int * v6926 = v6867->mem;
      int v7025 = ((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) * 2;
      int v6927 = v6926[v7025];
      int v7026 = (((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) * 2) + 1;
      int v6928 = v6926[v7026];
      int * v6929 = v6867->cache_vals;
      int v7028 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6907 + ((~(((v6909 ^ -1) | (-(v6909 ^ -1))) >> 31)) & 2)) - (v6910 + ((~(((v6911 ^ -1) | (-(v6911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6929[v7028] = v6927;
      int * v6931 = v6867->cache_vals;
      int v7031 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6907 + ((~(((v6909 ^ -1) | (-(v6909 ^ -1))) >> 31)) & 2)) - (v6910 + ((~(((v6911 ^ -1) | (-(v6911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6931[v7031] = v6928;
      int * v6933 = v6867->cache_tags;
      int v7034 = (int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1);
      v6933[v7010] = v7034;
      int * v6935 = v6867->cache_dirty;
      v6935[v7010] = 0;
      int * v6937 = v6867->cache_age;
      v6937[v7010] = 1;
      int * v6939 = v6867->cache_age;
      int v6940 = v6939[v7010];
      int v6941 = v6939[v6984];
      int v7040 = v6941 + ((int)((unsigned int)(v6941 - v6940) >> 31));
      v6939[v6984] = v7040;
      int * v6943 = v6867->cache_age;
      int v6944 = v6943[v6985];
      int v7042 = v6944 + ((int)((unsigned int)(v6944 - v6940) >> 31));
      v6943[v6985] = v7042;
      int * v6946 = v6867->cache_age;
      v6946[v7010] = 0;
      v6949 = v7010;
    }
    int * v6950 = v6867->cache_vals;
    int v7045 = v6949 * 2;
    int v6951 = v6950[v7045];
    int v7046 = (v6949 * 2) + 1;
    int v6952 = v6950[v7046];
    int v7047 = (((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6891 + ((~(((v6893 ^ -1) | (-(v6893 ^ -1))) >> 31)) & 2)) - (v6894 + ((~(((v6895 ^ -1) | (-(v6895 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6950[v7047] = v6951;
    int * v6954 = v6867->cache_vals;
    int v7050 = ((((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6891 + ((~(((v6893 ^ -1) | (-(v6893 ^ -1))) >> 31)) & 2)) - (v6894 + ((~(((v6895 ^ -1) | (-(v6895 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6954[v7050] = v6952;
    int * v6956 = v6867->cache_tags;
    int v7053 = ((((int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6891 + ((~(((v6893 ^ -1) | (-(v6893 ^ -1))) >> 31)) & 2)) - (v6894 + ((~(((v6895 ^ -1) | (-(v6895 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7054 = (int)((unsigned int)((int)((unsigned int)(v6871 + 32) >> 2)) >> 1);
    v6956[v7053] = v7054;
    int * v6958 = v6867->cache_dirty;
    v6958[v7053] = 0;
    int * v6960 = v6867->cache_age;
    v6960[v7053] = 1;
    int * v6962 = v6867->cache_age;
    int v6963 = v6962[v7053];
    int v6964 = v6962[v6982];
    int v7060 = v6964 + ((int)((unsigned int)(v6964 - v6963) >> 31));
    v6962[v6982] = v7060;
    int * v6966 = v6867->cache_age;
    int v6967 = v6966[v6983];
    int v7062 = v6967 + ((int)((unsigned int)(v6967 - v6963) >> 31));
    v6966[v6983] = v7062;
    int * v6969 = v6867->cache_age;
    v6969[v7053] = 0;
    v6972 = v7053;
  }
  int v7065 = (v6972 * 2) + (((int)((unsigned int)(v6871 + 32) >> 2)) & 1);
  int v6973 = v6879[v7065];
  int * v6974 = v6867->regs;
  v6974[14] = v6973;
  struct StateT * v6976 = slot_65(v6867);
  return v6976;
}

struct StateT * slot_14(struct StateT * v1366) {
  int v1367 = v1366->timer;
  int v1374 = v1367 + 1;
  v1366->timer = v1374;
  int * v1369 = v1366->regs;
  int v1370 = v1369[7];
  int v1378 = v1370 + -144;
  v1369[15] = v1378;
  struct StateT * v1372 = slot_15(v1366);
  return v1372;
}

struct StateT * slot_53(struct StateT * v5701) {
  int v5702 = v5701->timer;
  int v5710 = v5702 + 1;
  v5701->timer = v5710;
  int * v5704 = v5701->regs;
  int v5705 = v5704[14];
  int v5706 = v5704[12];
  int v5714 = v5705 + v5706;
  v5704[14] = v5714;
  struct StateT * v5708 = slot_54(v5701);
  return v5708;
}

struct StateT * slot_44(struct StateT * v4575) {
  int v4576 = v4575->timer;
  int v4588 = v4576 + 1;
  v4575->timer = v4588;
  int * v4578 = v4575->regs;
  int v4579 = v4578[6];
  int v4580 = v4578[15];
  bool v4592 = (v4579 ^ -2147483648) < (v4580 ^ -2147483648);
  int v4583;
  if (v4592) {
    v4583 = 1;
  } else {
    v4583 = 0;
  }
  int * v4584 = v4575->regs;
  v4584[16] = v4583;
  struct StateT * v4586 = slot_45(v4575);
  return v4586;
}

struct StateT * slot_66(struct StateT * v7275) {
  int v7276 = v7275->timer;
  int v7283 = v7276 + 1;
  v7275->timer = v7283;
  int * v7278 = v7275->regs;
  int v7279 = v7278[13];
  int v7287 = v7279 + -8;
  v7278[16] = v7287;
  struct StateT * v7281 = slot_67(v7275);
  return v7281;
}

struct StateT * slot_28(struct StateT * v2586) {
  int v2587 = v2586->timer;
  int v2595 = v2587 + 1;
  v2586->timer = v2595;
  int * v2589 = v2586->regs;
  int v2590 = v2589[14];
  int v2591 = v2589[17];
  int v2599 = v2590 - v2591;
  v2589[14] = v2599;
  struct StateT * v2593 = slot_29(v2586);
  return v2593;
}

struct StateT * slot_32(struct StateT * v2650) {
  int v2651 = v2650->timer;
  int v2821 = v2651 + 1;
  v2650->timer = v2821;
  int * v2653 = v2650->regs;
  int v2654 = v2653[10];
  int v2655 = v2653[15];
  int * v2656 = v2650->cache_tags;
  int v2826 = (((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2657 = v2656[v2826];
  int v2827 = ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2658 = v2656[v2827];
  int v2828 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2659 = v2656[v2828];
  int v2829 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2660 = v2656[v2829];
  int v2661 = v2650->timer;
  int v2830 = v2661 + ((100 ^ (((~(((v2659 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2659 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2657 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2657 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2658 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2658 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2659 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2659 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2650->timer = v2830;
  bool v2831 = !(((~(((v2657 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2657 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2658 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2658 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2755;
  if (v2831) {
    int * v2663 = v2650->cache_age;
    int v2833 = ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2658 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2658 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2664 = v2663[v2833];
    int v2665 = v2663[v2826];
    int v2834 = v2665 + ((int)((unsigned int)(v2665 - v2664) >> 31));
    v2663[v2826] = v2834;
    int * v2667 = v2650->cache_age;
    int v2668 = v2667[v2827];
    int v2836 = v2668 + ((int)((unsigned int)(v2668 - v2664) >> 31));
    v2667[v2827] = v2836;
    int * v2670 = v2650->cache_age;
    v2670[v2833] = 0;
    v2755 = v2833;
  } else {
    int * v2673 = v2650->cache_age;
    int v2840 = (((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2674 = v2673[v2840];
    int * v2675 = v2650->cache_tags;
    int v2676 = v2675[v2840];
    int v2677 = v2673[v2827];
    int v2678 = v2675[v2827];
    bool v2842 = !(((~(((v2659 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2659 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2732;
    if (v2842) {
      int * v2679 = v2650->cache_age;
      int v2844 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2660 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2680 = v2679[v2844];
      int v2681 = v2679[v2828];
      int v2845 = v2681 + ((int)((unsigned int)(v2681 - v2680) >> 31));
      v2679[v2828] = v2845;
      int * v2683 = v2650->cache_age;
      int v2684 = v2683[v2829];
      int v2847 = v2684 + ((int)((unsigned int)(v2684 - v2680) >> 31));
      v2683[v2829] = v2847;
      int * v2686 = v2650->cache_age;
      v2686[v2844] = 0;
      v2732 = v2844;
    } else {
      int * v2689 = v2650->cache_age;
      int v2851 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2690 = v2689[v2851];
      int * v2691 = v2650->cache_tags;
      int v2692 = v2691[v2851];
      int v2693 = v2689[v2829];
      int v2694 = v2691[v2829];
      int * v2695 = v2650->cache_dirty;
      int v2854 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2690 + ((~(((v2692 ^ -1) | (-(v2692 ^ -1))) >> 31)) & 2)) - (v2693 + ((~(((v2694 ^ -1) | (-(v2694 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2696 = v2695[v2854];
      bool v2855 = !(v2696 == 0);
      if (v2855) {
        int * v2697 = v2650->cache_tags;
        int v2698 = v2697[v2854];
        int * v2699 = v2650->cache_vals;
        int v2858 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2690 + ((~(((v2692 ^ -1) | (-(v2692 ^ -1))) >> 31)) & 2)) - (v2693 + ((~(((v2694 ^ -1) | (-(v2694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2700 = v2699[v2858];
        int v2859 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2690 + ((~(((v2692 ^ -1) | (-(v2692 ^ -1))) >> 31)) & 2)) - (v2693 + ((~(((v2694 ^ -1) | (-(v2694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2701 = v2699[v2859];
        int * v2702 = v2650->mem;
        int v2861 = v2698 * 2;
        v2702[v2861] = v2700;
        int * v2704 = v2650->mem;
        int v2864 = (v2698 * 2) + 1;
        v2704[v2864] = v2701;
        ;
      } else {
        ;
      }
      int * v2709 = v2650->mem;
      int v2869 = ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) * 2;
      int v2710 = v2709[v2869];
      int v2870 = (((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2711 = v2709[v2870];
      int * v2712 = v2650->cache_vals;
      int v2872 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2690 + ((~(((v2692 ^ -1) | (-(v2692 ^ -1))) >> 31)) & 2)) - (v2693 + ((~(((v2694 ^ -1) | (-(v2694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2712[v2872] = v2710;
      int * v2714 = v2650->cache_vals;
      int v2875 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2690 + ((~(((v2692 ^ -1) | (-(v2692 ^ -1))) >> 31)) & 2)) - (v2693 + ((~(((v2694 ^ -1) | (-(v2694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2714[v2875] = v2711;
      int * v2716 = v2650->cache_tags;
      int v2878 = (int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1);
      v2716[v2854] = v2878;
      int * v2718 = v2650->cache_dirty;
      v2718[v2854] = 0;
      int * v2720 = v2650->cache_age;
      v2720[v2854] = 1;
      int * v2722 = v2650->cache_age;
      int v2723 = v2722[v2854];
      int v2724 = v2722[v2828];
      int v2884 = v2724 + ((int)((unsigned int)(v2724 - v2723) >> 31));
      v2722[v2828] = v2884;
      int * v2726 = v2650->cache_age;
      int v2727 = v2726[v2829];
      int v2886 = v2727 + ((int)((unsigned int)(v2727 - v2723) >> 31));
      v2726[v2829] = v2886;
      int * v2729 = v2650->cache_age;
      v2729[v2854] = 0;
      v2732 = v2854;
    }
    int * v2733 = v2650->cache_vals;
    int v2889 = v2732 * 2;
    int v2734 = v2733[v2889];
    int v2890 = (v2732 * 2) + 1;
    int v2735 = v2733[v2890];
    int v2891 = (((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2674 + ((~(((v2676 ^ -1) | (-(v2676 ^ -1))) >> 31)) & 2)) - (v2677 + ((~(((v2678 ^ -1) | (-(v2678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2733[v2891] = v2734;
    int * v2737 = v2650->cache_vals;
    int v2894 = ((((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2674 + ((~(((v2676 ^ -1) | (-(v2676 ^ -1))) >> 31)) & 2)) - (v2677 + ((~(((v2678 ^ -1) | (-(v2678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2737[v2894] = v2735;
    int * v2739 = v2650->cache_tags;
    int v2897 = ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2674 + ((~(((v2676 ^ -1) | (-(v2676 ^ -1))) >> 31)) & 2)) - (v2677 + ((~(((v2678 ^ -1) | (-(v2678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2898 = (int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1);
    v2739[v2897] = v2898;
    int * v2741 = v2650->cache_dirty;
    v2741[v2897] = 0;
    int * v2743 = v2650->cache_age;
    v2743[v2897] = 1;
    int * v2745 = v2650->cache_age;
    int v2746 = v2745[v2897];
    int v2747 = v2745[v2826];
    int v2904 = v2747 + ((int)((unsigned int)(v2747 - v2746) >> 31));
    v2745[v2826] = v2904;
    int * v2749 = v2650->cache_age;
    int v2750 = v2749[v2827];
    int v2906 = v2750 + ((int)((unsigned int)(v2750 - v2746) >> 31));
    v2749[v2827] = v2906;
    int * v2752 = v2650->cache_age;
    v2752[v2897] = 0;
    v2755 = v2897;
  }
  int * v2756 = v2650->cache_vals;
  int v2909 = (v2755 * 2) + (((int)((unsigned int)(v2654 + 8) >> 2)) & 1);
  v2756[v2909] = v2655;
  int * v2758 = v2650->cache_tags;
  int v2759 = v2758[v2828];
  int v2760 = v2758[v2829];
  bool v2912 = !(((~(((v2759 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2759 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2760 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2760 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2814;
  if (v2912) {
    int * v2761 = v2650->cache_age;
    int v2914 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2760 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))) | (-(v2760 ^ ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2762 = v2761[v2914];
    int v2763 = v2761[v2828];
    int v2915 = v2763 + ((int)((unsigned int)(v2763 - v2762) >> 31));
    v2761[v2828] = v2915;
    int * v2765 = v2650->cache_age;
    int v2766 = v2765[v2829];
    int v2917 = v2766 + ((int)((unsigned int)(v2766 - v2762) >> 31));
    v2765[v2829] = v2917;
    int * v2768 = v2650->cache_age;
    v2768[v2914] = 0;
    v2814 = v2914;
  } else {
    int * v2771 = v2650->cache_age;
    int v2921 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2);
    int v2772 = v2771[v2921];
    int * v2773 = v2650->cache_tags;
    int v2774 = v2773[v2921];
    int v2775 = v2771[v2829];
    int v2776 = v2773[v2829];
    int * v2777 = v2650->cache_dirty;
    int v2924 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2778 = v2777[v2924];
    bool v2925 = !(v2778 == 0);
    if (v2925) {
      int * v2779 = v2650->cache_tags;
      int v2780 = v2779[v2924];
      int * v2781 = v2650->cache_vals;
      int v2928 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2782 = v2781[v2928];
      int v2929 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2783 = v2781[v2929];
      int * v2784 = v2650->mem;
      int v2931 = v2780 * 2;
      v2784[v2931] = v2782;
      int * v2786 = v2650->mem;
      int v2934 = (v2780 * 2) + 1;
      v2786[v2934] = v2783;
      ;
    } else {
      ;
    }
    int * v2791 = v2650->mem;
    int v2939 = ((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) * 2;
    int v2792 = v2791[v2939];
    int v2940 = (((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) * 2) + 1;
    int v2793 = v2791[v2940];
    int * v2794 = v2650->cache_vals;
    int v2942 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2794[v2942] = v2792;
    int * v2796 = v2650->cache_vals;
    int v2945 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2796[v2945] = v2793;
    int * v2798 = v2650->cache_tags;
    int v2948 = (int)((unsigned int)((int)((unsigned int)(v2654 + 8) >> 2)) >> 1);
    v2798[v2924] = v2948;
    int * v2800 = v2650->cache_dirty;
    v2800[v2924] = 0;
    int * v2802 = v2650->cache_age;
    v2802[v2924] = 1;
    int * v2804 = v2650->cache_age;
    int v2805 = v2804[v2924];
    int v2806 = v2804[v2828];
    int v2954 = v2806 + ((int)((unsigned int)(v2806 - v2805) >> 31));
    v2804[v2828] = v2954;
    int * v2808 = v2650->cache_age;
    int v2809 = v2808[v2829];
    int v2956 = v2809 + ((int)((unsigned int)(v2809 - v2805) >> 31));
    v2808[v2829] = v2956;
    int * v2811 = v2650->cache_age;
    v2811[v2924] = 0;
    v2814 = v2924;
  }
  int * v2815 = v2650->cache_vals;
  int v2959 = (v2814 * 2) + (((int)((unsigned int)(v2654 + 8) >> 2)) & 1);
  v2815[v2959] = v2655;
  int * v2817 = v2650->cache_dirty;
  v2817[v2814] = 1;
  struct StateT * v2819 = slot_33(v2650);
  return v2819;
}

struct StateT * slot_17(struct StateT * v1422) {
  int v1423 = v1422->timer;
  int v1431 = v1423 + 1;
  v1422->timer = v1431;
  int * v1425 = v1422->regs;
  int v1426 = v1425[13];
  int v1427 = v1425[14];
  int v1435 = v1426 - v1427;
  v1425[13] = v1435;
  struct StateT * v1429 = slot_18(v1422);
  return v1429;
}

struct StateT * slot_49(struct StateT * v4963) {
  int v4964 = v4963->timer;
  int v5134 = v4964 + 1;
  v4963->timer = v5134;
  int * v4966 = v4963->regs;
  int v4967 = v4966[10];
  int v4968 = v4966[13];
  int * v4969 = v4963->cache_tags;
  int v5139 = (((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2;
  int v4970 = v4969[v5139];
  int v5140 = ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4971 = v4969[v5140];
  int v5141 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2);
  int v4972 = v4969[v5141];
  int v5142 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4973 = v4969[v5142];
  int v4974 = v4963->timer;
  int v5143 = v4974 + ((100 ^ (((~(((v4972 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4972 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4970 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4970 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4971 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4971 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4972 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4972 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4963->timer = v5143;
  bool v5144 = !(((~(((v4970 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4970 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4971 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4971 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5068;
  if (v5144) {
    int * v4976 = v4963->cache_age;
    int v5146 = ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v4971 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4971 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v4977 = v4976[v5146];
    int v4978 = v4976[v5139];
    int v5147 = v4978 + ((int)((unsigned int)(v4978 - v4977) >> 31));
    v4976[v5139] = v5147;
    int * v4980 = v4963->cache_age;
    int v4981 = v4980[v5140];
    int v5149 = v4981 + ((int)((unsigned int)(v4981 - v4977) >> 31));
    v4980[v5140] = v5149;
    int * v4983 = v4963->cache_age;
    v4983[v5146] = 0;
    v5068 = v5146;
  } else {
    int * v4986 = v4963->cache_age;
    int v5153 = (((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2;
    int v4987 = v4986[v5153];
    int * v4988 = v4963->cache_tags;
    int v4989 = v4988[v5153];
    int v4990 = v4986[v5140];
    int v4991 = v4988[v5140];
    bool v5155 = !(((~(((v4972 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4972 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v5045;
    if (v5155) {
      int * v4992 = v4963->cache_age;
      int v5157 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v4973 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v4993 = v4992[v5157];
      int v4994 = v4992[v5141];
      int v5158 = v4994 + ((int)((unsigned int)(v4994 - v4993) >> 31));
      v4992[v5141] = v5158;
      int * v4996 = v4963->cache_age;
      int v4997 = v4996[v5142];
      int v5160 = v4997 + ((int)((unsigned int)(v4997 - v4993) >> 31));
      v4996[v5142] = v5160;
      int * v4999 = v4963->cache_age;
      v4999[v5157] = 0;
      v5045 = v5157;
    } else {
      int * v5002 = v4963->cache_age;
      int v5164 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2);
      int v5003 = v5002[v5164];
      int * v5004 = v4963->cache_tags;
      int v5005 = v5004[v5164];
      int v5006 = v5002[v5142];
      int v5007 = v5004[v5142];
      int * v5008 = v4963->cache_dirty;
      int v5167 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5003 + ((~(((v5005 ^ -1) | (-(v5005 ^ -1))) >> 31)) & 2)) - (v5006 + ((~(((v5007 ^ -1) | (-(v5007 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5009 = v5008[v5167];
      bool v5168 = !(v5009 == 0);
      if (v5168) {
        int * v5010 = v4963->cache_tags;
        int v5011 = v5010[v5167];
        int * v5012 = v4963->cache_vals;
        int v5171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5003 + ((~(((v5005 ^ -1) | (-(v5005 ^ -1))) >> 31)) & 2)) - (v5006 + ((~(((v5007 ^ -1) | (-(v5007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5013 = v5012[v5171];
        int v5172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5003 + ((~(((v5005 ^ -1) | (-(v5005 ^ -1))) >> 31)) & 2)) - (v5006 + ((~(((v5007 ^ -1) | (-(v5007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5014 = v5012[v5172];
        int * v5015 = v4963->mem;
        int v5174 = v5011 * 2;
        v5015[v5174] = v5013;
        int * v5017 = v4963->mem;
        int v5177 = (v5011 * 2) + 1;
        v5017[v5177] = v5014;
        ;
      } else {
        ;
      }
      int * v5022 = v4963->mem;
      int v5182 = ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) * 2;
      int v5023 = v5022[v5182];
      int v5183 = (((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) * 2) + 1;
      int v5024 = v5022[v5183];
      int * v5025 = v4963->cache_vals;
      int v5185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5003 + ((~(((v5005 ^ -1) | (-(v5005 ^ -1))) >> 31)) & 2)) - (v5006 + ((~(((v5007 ^ -1) | (-(v5007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5025[v5185] = v5023;
      int * v5027 = v4963->cache_vals;
      int v5188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5003 + ((~(((v5005 ^ -1) | (-(v5005 ^ -1))) >> 31)) & 2)) - (v5006 + ((~(((v5007 ^ -1) | (-(v5007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5027[v5188] = v5024;
      int * v5029 = v4963->cache_tags;
      int v5191 = (int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1);
      v5029[v5167] = v5191;
      int * v5031 = v4963->cache_dirty;
      v5031[v5167] = 0;
      int * v5033 = v4963->cache_age;
      v5033[v5167] = 1;
      int * v5035 = v4963->cache_age;
      int v5036 = v5035[v5167];
      int v5037 = v5035[v5141];
      int v5197 = v5037 + ((int)((unsigned int)(v5037 - v5036) >> 31));
      v5035[v5141] = v5197;
      int * v5039 = v4963->cache_age;
      int v5040 = v5039[v5142];
      int v5199 = v5040 + ((int)((unsigned int)(v5040 - v5036) >> 31));
      v5039[v5142] = v5199;
      int * v5042 = v4963->cache_age;
      v5042[v5167] = 0;
      v5045 = v5167;
    }
    int * v5046 = v4963->cache_vals;
    int v5202 = v5045 * 2;
    int v5047 = v5046[v5202];
    int v5203 = (v5045 * 2) + 1;
    int v5048 = v5046[v5203];
    int v5204 = (((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4987 + ((~(((v4989 ^ -1) | (-(v4989 ^ -1))) >> 31)) & 2)) - (v4990 + ((~(((v4991 ^ -1) | (-(v4991 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5046[v5204] = v5047;
    int * v5050 = v4963->cache_vals;
    int v5207 = ((((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4987 + ((~(((v4989 ^ -1) | (-(v4989 ^ -1))) >> 31)) & 2)) - (v4990 + ((~(((v4991 ^ -1) | (-(v4991 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5050[v5207] = v5048;
    int * v5052 = v4963->cache_tags;
    int v5210 = ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4987 + ((~(((v4989 ^ -1) | (-(v4989 ^ -1))) >> 31)) & 2)) - (v4990 + ((~(((v4991 ^ -1) | (-(v4991 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5211 = (int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1);
    v5052[v5210] = v5211;
    int * v5054 = v4963->cache_dirty;
    v5054[v5210] = 0;
    int * v5056 = v4963->cache_age;
    v5056[v5210] = 1;
    int * v5058 = v4963->cache_age;
    int v5059 = v5058[v5210];
    int v5060 = v5058[v5139];
    int v5217 = v5060 + ((int)((unsigned int)(v5060 - v5059) >> 31));
    v5058[v5139] = v5217;
    int * v5062 = v4963->cache_age;
    int v5063 = v5062[v5140];
    int v5219 = v5063 + ((int)((unsigned int)(v5063 - v5059) >> 31));
    v5062[v5140] = v5219;
    int * v5065 = v4963->cache_age;
    v5065[v5210] = 0;
    v5068 = v5210;
  }
  int * v5069 = v4963->cache_vals;
  int v5222 = (v5068 * 2) + (((int)((unsigned int)(v4967 + 20) >> 2)) & 1);
  v5069[v5222] = v4968;
  int * v5071 = v4963->cache_tags;
  int v5072 = v5071[v5141];
  int v5073 = v5071[v5142];
  bool v5225 = !(((~(((v5072 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v5072 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5073 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v5073 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5127;
  if (v5225) {
    int * v5074 = v4963->cache_age;
    int v5227 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5073 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))) | (-(v5073 ^ ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5075 = v5074[v5227];
    int v5076 = v5074[v5141];
    int v5228 = v5076 + ((int)((unsigned int)(v5076 - v5075) >> 31));
    v5074[v5141] = v5228;
    int * v5078 = v4963->cache_age;
    int v5079 = v5078[v5142];
    int v5230 = v5079 + ((int)((unsigned int)(v5079 - v5075) >> 31));
    v5078[v5142] = v5230;
    int * v5081 = v4963->cache_age;
    v5081[v5227] = 0;
    v5127 = v5227;
  } else {
    int * v5084 = v4963->cache_age;
    int v5234 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2);
    int v5085 = v5084[v5234];
    int * v5086 = v4963->cache_tags;
    int v5087 = v5086[v5234];
    int v5088 = v5084[v5142];
    int v5089 = v5086[v5142];
    int * v5090 = v4963->cache_dirty;
    int v5237 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5085 + ((~(((v5087 ^ -1) | (-(v5087 ^ -1))) >> 31)) & 2)) - (v5088 + ((~(((v5089 ^ -1) | (-(v5089 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5091 = v5090[v5237];
    bool v5238 = !(v5091 == 0);
    if (v5238) {
      int * v5092 = v4963->cache_tags;
      int v5093 = v5092[v5237];
      int * v5094 = v4963->cache_vals;
      int v5241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5085 + ((~(((v5087 ^ -1) | (-(v5087 ^ -1))) >> 31)) & 2)) - (v5088 + ((~(((v5089 ^ -1) | (-(v5089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5095 = v5094[v5241];
      int v5242 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5085 + ((~(((v5087 ^ -1) | (-(v5087 ^ -1))) >> 31)) & 2)) - (v5088 + ((~(((v5089 ^ -1) | (-(v5089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5096 = v5094[v5242];
      int * v5097 = v4963->mem;
      int v5244 = v5093 * 2;
      v5097[v5244] = v5095;
      int * v5099 = v4963->mem;
      int v5247 = (v5093 * 2) + 1;
      v5099[v5247] = v5096;
      ;
    } else {
      ;
    }
    int * v5104 = v4963->mem;
    int v5252 = ((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) * 2;
    int v5105 = v5104[v5252];
    int v5253 = (((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) * 2) + 1;
    int v5106 = v5104[v5253];
    int * v5107 = v4963->cache_vals;
    int v5255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5085 + ((~(((v5087 ^ -1) | (-(v5087 ^ -1))) >> 31)) & 2)) - (v5088 + ((~(((v5089 ^ -1) | (-(v5089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5107[v5255] = v5105;
    int * v5109 = v4963->cache_vals;
    int v5258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5085 + ((~(((v5087 ^ -1) | (-(v5087 ^ -1))) >> 31)) & 2)) - (v5088 + ((~(((v5089 ^ -1) | (-(v5089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5109[v5258] = v5106;
    int * v5111 = v4963->cache_tags;
    int v5261 = (int)((unsigned int)((int)((unsigned int)(v4967 + 20) >> 2)) >> 1);
    v5111[v5237] = v5261;
    int * v5113 = v4963->cache_dirty;
    v5113[v5237] = 0;
    int * v5115 = v4963->cache_age;
    v5115[v5237] = 1;
    int * v5117 = v4963->cache_age;
    int v5118 = v5117[v5237];
    int v5119 = v5117[v5141];
    int v5267 = v5119 + ((int)((unsigned int)(v5119 - v5118) >> 31));
    v5117[v5141] = v5267;
    int * v5121 = v4963->cache_age;
    int v5122 = v5121[v5142];
    int v5269 = v5122 + ((int)((unsigned int)(v5122 - v5118) >> 31));
    v5121[v5142] = v5269;
    int * v5124 = v4963->cache_age;
    v5124[v5237] = 0;
    v5127 = v5237;
  }
  int * v5128 = v4963->cache_vals;
  int v5272 = (v5127 * 2) + (((int)((unsigned int)(v4967 + 20) >> 2)) & 1);
  v5128[v5272] = v4968;
  int * v5130 = v4963->cache_dirty;
  v5130[v5127] = 1;
  struct StateT * v5132 = slot_50(v4963);
  return v5132;
}

struct StateT * slot_33(struct StateT * v2965) {
  int v2966 = v2965->timer;
  int v3136 = v2966 + 1;
  v2965->timer = v3136;
  int * v2968 = v2965->regs;
  int v2969 = v2968[10];
  int v2970 = v2968[13];
  int * v2971 = v2965->cache_tags;
  int v3141 = (((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2972 = v2971[v3141];
  int v3142 = ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2973 = v2971[v3142];
  int v3143 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2974 = v2971[v3143];
  int v3144 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2975 = v2971[v3144];
  int v2976 = v2965->timer;
  int v3145 = v2976 + ((100 ^ (((~(((v2974 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2974 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2972 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2972 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2973 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2973 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2974 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2974 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2965->timer = v3145;
  bool v3146 = !(((~(((v2972 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2972 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2973 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2973 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3070;
  if (v3146) {
    int * v2978 = v2965->cache_age;
    int v3148 = ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2973 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2973 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2979 = v2978[v3148];
    int v2980 = v2978[v3141];
    int v3149 = v2980 + ((int)((unsigned int)(v2980 - v2979) >> 31));
    v2978[v3141] = v3149;
    int * v2982 = v2965->cache_age;
    int v2983 = v2982[v3142];
    int v3151 = v2983 + ((int)((unsigned int)(v2983 - v2979) >> 31));
    v2982[v3142] = v3151;
    int * v2985 = v2965->cache_age;
    v2985[v3148] = 0;
    v3070 = v3148;
  } else {
    int * v2988 = v2965->cache_age;
    int v3155 = (((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2989 = v2988[v3155];
    int * v2990 = v2965->cache_tags;
    int v2991 = v2990[v3155];
    int v2992 = v2988[v3142];
    int v2993 = v2990[v3142];
    bool v3157 = !(((~(((v2974 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2974 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3047;
    if (v3157) {
      int * v2994 = v2965->cache_age;
      int v3159 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2995 = v2994[v3159];
      int v2996 = v2994[v3143];
      int v3160 = v2996 + ((int)((unsigned int)(v2996 - v2995) >> 31));
      v2994[v3143] = v3160;
      int * v2998 = v2965->cache_age;
      int v2999 = v2998[v3144];
      int v3162 = v2999 + ((int)((unsigned int)(v2999 - v2995) >> 31));
      v2998[v3144] = v3162;
      int * v3001 = v2965->cache_age;
      v3001[v3159] = 0;
      v3047 = v3159;
    } else {
      int * v3004 = v2965->cache_age;
      int v3166 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3005 = v3004[v3166];
      int * v3006 = v2965->cache_tags;
      int v3007 = v3006[v3166];
      int v3008 = v3004[v3144];
      int v3009 = v3006[v3144];
      int * v3010 = v2965->cache_dirty;
      int v3169 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3005 + ((~(((v3007 ^ -1) | (-(v3007 ^ -1))) >> 31)) & 2)) - (v3008 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3011 = v3010[v3169];
      bool v3170 = !(v3011 == 0);
      if (v3170) {
        int * v3012 = v2965->cache_tags;
        int v3013 = v3012[v3169];
        int * v3014 = v2965->cache_vals;
        int v3173 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3005 + ((~(((v3007 ^ -1) | (-(v3007 ^ -1))) >> 31)) & 2)) - (v3008 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3015 = v3014[v3173];
        int v3174 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3005 + ((~(((v3007 ^ -1) | (-(v3007 ^ -1))) >> 31)) & 2)) - (v3008 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3016 = v3014[v3174];
        int * v3017 = v2965->mem;
        int v3176 = v3013 * 2;
        v3017[v3176] = v3015;
        int * v3019 = v2965->mem;
        int v3179 = (v3013 * 2) + 1;
        v3019[v3179] = v3016;
        ;
      } else {
        ;
      }
      int * v3024 = v2965->mem;
      int v3184 = ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) * 2;
      int v3025 = v3024[v3184];
      int v3185 = (((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3026 = v3024[v3185];
      int * v3027 = v2965->cache_vals;
      int v3187 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3005 + ((~(((v3007 ^ -1) | (-(v3007 ^ -1))) >> 31)) & 2)) - (v3008 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3027[v3187] = v3025;
      int * v3029 = v2965->cache_vals;
      int v3190 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3005 + ((~(((v3007 ^ -1) | (-(v3007 ^ -1))) >> 31)) & 2)) - (v3008 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3029[v3190] = v3026;
      int * v3031 = v2965->cache_tags;
      int v3193 = (int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1);
      v3031[v3169] = v3193;
      int * v3033 = v2965->cache_dirty;
      v3033[v3169] = 0;
      int * v3035 = v2965->cache_age;
      v3035[v3169] = 1;
      int * v3037 = v2965->cache_age;
      int v3038 = v3037[v3169];
      int v3039 = v3037[v3143];
      int v3199 = v3039 + ((int)((unsigned int)(v3039 - v3038) >> 31));
      v3037[v3143] = v3199;
      int * v3041 = v2965->cache_age;
      int v3042 = v3041[v3144];
      int v3201 = v3042 + ((int)((unsigned int)(v3042 - v3038) >> 31));
      v3041[v3144] = v3201;
      int * v3044 = v2965->cache_age;
      v3044[v3169] = 0;
      v3047 = v3169;
    }
    int * v3048 = v2965->cache_vals;
    int v3204 = v3047 * 2;
    int v3049 = v3048[v3204];
    int v3205 = (v3047 * 2) + 1;
    int v3050 = v3048[v3205];
    int v3206 = (((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2989 + ((~(((v2991 ^ -1) | (-(v2991 ^ -1))) >> 31)) & 2)) - (v2992 + ((~(((v2993 ^ -1) | (-(v2993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3048[v3206] = v3049;
    int * v3052 = v2965->cache_vals;
    int v3209 = ((((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2989 + ((~(((v2991 ^ -1) | (-(v2991 ^ -1))) >> 31)) & 2)) - (v2992 + ((~(((v2993 ^ -1) | (-(v2993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3052[v3209] = v3050;
    int * v3054 = v2965->cache_tags;
    int v3212 = ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2989 + ((~(((v2991 ^ -1) | (-(v2991 ^ -1))) >> 31)) & 2)) - (v2992 + ((~(((v2993 ^ -1) | (-(v2993 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3213 = (int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1);
    v3054[v3212] = v3213;
    int * v3056 = v2965->cache_dirty;
    v3056[v3212] = 0;
    int * v3058 = v2965->cache_age;
    v3058[v3212] = 1;
    int * v3060 = v2965->cache_age;
    int v3061 = v3060[v3212];
    int v3062 = v3060[v3141];
    int v3219 = v3062 + ((int)((unsigned int)(v3062 - v3061) >> 31));
    v3060[v3141] = v3219;
    int * v3064 = v2965->cache_age;
    int v3065 = v3064[v3142];
    int v3221 = v3065 + ((int)((unsigned int)(v3065 - v3061) >> 31));
    v3064[v3142] = v3221;
    int * v3067 = v2965->cache_age;
    v3067[v3212] = 0;
    v3070 = v3212;
  }
  int * v3071 = v2965->cache_vals;
  int v3224 = (v3070 * 2) + (((int)((unsigned int)(v2969 + 12) >> 2)) & 1);
  v3071[v3224] = v2970;
  int * v3073 = v2965->cache_tags;
  int v3074 = v3073[v3143];
  int v3075 = v3073[v3144];
  bool v3227 = !(((~(((v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3129;
  if (v3227) {
    int * v3076 = v2965->cache_age;
    int v3229 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3077 = v3076[v3229];
    int v3078 = v3076[v3143];
    int v3230 = v3078 + ((int)((unsigned int)(v3078 - v3077) >> 31));
    v3076[v3143] = v3230;
    int * v3080 = v2965->cache_age;
    int v3081 = v3080[v3144];
    int v3232 = v3081 + ((int)((unsigned int)(v3081 - v3077) >> 31));
    v3080[v3144] = v3232;
    int * v3083 = v2965->cache_age;
    v3083[v3229] = 0;
    v3129 = v3229;
  } else {
    int * v3086 = v2965->cache_age;
    int v3236 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2);
    int v3087 = v3086[v3236];
    int * v3088 = v2965->cache_tags;
    int v3089 = v3088[v3236];
    int v3090 = v3086[v3144];
    int v3091 = v3088[v3144];
    int * v3092 = v2965->cache_dirty;
    int v3239 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3087 + ((~(((v3089 ^ -1) | (-(v3089 ^ -1))) >> 31)) & 2)) - (v3090 + ((~(((v3091 ^ -1) | (-(v3091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3093 = v3092[v3239];
    bool v3240 = !(v3093 == 0);
    if (v3240) {
      int * v3094 = v2965->cache_tags;
      int v3095 = v3094[v3239];
      int * v3096 = v2965->cache_vals;
      int v3243 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3087 + ((~(((v3089 ^ -1) | (-(v3089 ^ -1))) >> 31)) & 2)) - (v3090 + ((~(((v3091 ^ -1) | (-(v3091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3097 = v3096[v3243];
      int v3244 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3087 + ((~(((v3089 ^ -1) | (-(v3089 ^ -1))) >> 31)) & 2)) - (v3090 + ((~(((v3091 ^ -1) | (-(v3091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3098 = v3096[v3244];
      int * v3099 = v2965->mem;
      int v3246 = v3095 * 2;
      v3099[v3246] = v3097;
      int * v3101 = v2965->mem;
      int v3249 = (v3095 * 2) + 1;
      v3101[v3249] = v3098;
      ;
    } else {
      ;
    }
    int * v3106 = v2965->mem;
    int v3254 = ((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) * 2;
    int v3107 = v3106[v3254];
    int v3255 = (((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) * 2) + 1;
    int v3108 = v3106[v3255];
    int * v3109 = v2965->cache_vals;
    int v3257 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3087 + ((~(((v3089 ^ -1) | (-(v3089 ^ -1))) >> 31)) & 2)) - (v3090 + ((~(((v3091 ^ -1) | (-(v3091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3109[v3257] = v3107;
    int * v3111 = v2965->cache_vals;
    int v3260 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3087 + ((~(((v3089 ^ -1) | (-(v3089 ^ -1))) >> 31)) & 2)) - (v3090 + ((~(((v3091 ^ -1) | (-(v3091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3111[v3260] = v3108;
    int * v3113 = v2965->cache_tags;
    int v3263 = (int)((unsigned int)((int)((unsigned int)(v2969 + 12) >> 2)) >> 1);
    v3113[v3239] = v3263;
    int * v3115 = v2965->cache_dirty;
    v3115[v3239] = 0;
    int * v3117 = v2965->cache_age;
    v3117[v3239] = 1;
    int * v3119 = v2965->cache_age;
    int v3120 = v3119[v3239];
    int v3121 = v3119[v3143];
    int v3269 = v3121 + ((int)((unsigned int)(v3121 - v3120) >> 31));
    v3119[v3143] = v3269;
    int * v3123 = v2965->cache_age;
    int v3124 = v3123[v3144];
    int v3271 = v3124 + ((int)((unsigned int)(v3124 - v3120) >> 31));
    v3123[v3144] = v3271;
    int * v3126 = v2965->cache_age;
    v3126[v3239] = 0;
    v3129 = v3239;
  }
  int * v3130 = v2965->cache_vals;
  int v3274 = (v3129 * 2) + (((int)((unsigned int)(v2969 + 12) >> 2)) & 1);
  v3130[v3274] = v2970;
  int * v3132 = v2965->cache_dirty;
  v3132[v3129] = 1;
  struct StateT * v3134 = slot_34(v2965);
  return v3134;
}

struct StateT * slot_50(struct StateT * v5278) {
  int v5279 = v5278->timer;
  int v5389 = v5279 + 1;
  v5278->timer = v5389;
  int * v5281 = v5278->regs;
  int v5282 = v5281[11];
  int * v5283 = v5278->cache_tags;
  int v5393 = (((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2;
  int v5284 = v5283[v5393];
  int v5394 = ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5285 = v5283[v5394];
  int v5395 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2);
  int v5286 = v5283[v5395];
  int v5396 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5287 = v5283[v5396];
  int v5288 = v5278->timer;
  int v5397 = v5288 + ((100 ^ (((~(((v5286 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5286 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5284 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5284 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5285 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5285 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5286 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5286 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5278->timer = v5397;
  int * v5290 = v5278->cache_vals;
  bool v5398 = !(((~(((v5284 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5284 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5285 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5285 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5383;
  if (v5398) {
    int * v5291 = v5278->cache_age;
    int v5400 = ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v5285 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5285 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5292 = v5291[v5400];
    int v5293 = v5291[v5393];
    int v5401 = v5293 + ((int)((unsigned int)(v5293 - v5292) >> 31));
    v5291[v5393] = v5401;
    int * v5295 = v5278->cache_age;
    int v5296 = v5295[v5394];
    int v5403 = v5296 + ((int)((unsigned int)(v5296 - v5292) >> 31));
    v5295[v5394] = v5403;
    int * v5298 = v5278->cache_age;
    v5298[v5400] = 0;
    v5383 = v5400;
  } else {
    int * v5301 = v5278->cache_age;
    int v5407 = (((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2;
    int v5302 = v5301[v5407];
    int * v5303 = v5278->cache_tags;
    int v5304 = v5303[v5407];
    int v5305 = v5301[v5394];
    int v5306 = v5303[v5394];
    bool v5409 = !(((~(((v5286 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5286 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v5360;
    if (v5409) {
      int * v5307 = v5278->cache_age;
      int v5411 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))) | (-(v5287 ^ ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v5308 = v5307[v5411];
      int v5309 = v5307[v5395];
      int v5412 = v5309 + ((int)((unsigned int)(v5309 - v5308) >> 31));
      v5307[v5395] = v5412;
      int * v5311 = v5278->cache_age;
      int v5312 = v5311[v5396];
      int v5414 = v5312 + ((int)((unsigned int)(v5312 - v5308) >> 31));
      v5311[v5396] = v5414;
      int * v5314 = v5278->cache_age;
      v5314[v5411] = 0;
      v5360 = v5411;
    } else {
      int * v5317 = v5278->cache_age;
      int v5418 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2);
      int v5318 = v5317[v5418];
      int * v5319 = v5278->cache_tags;
      int v5320 = v5319[v5418];
      int v5321 = v5317[v5396];
      int v5322 = v5319[v5396];
      int * v5323 = v5278->cache_dirty;
      int v5421 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5318 + ((~(((v5320 ^ -1) | (-(v5320 ^ -1))) >> 31)) & 2)) - (v5321 + ((~(((v5322 ^ -1) | (-(v5322 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5324 = v5323[v5421];
      bool v5422 = !(v5324 == 0);
      if (v5422) {
        int * v5325 = v5278->cache_tags;
        int v5326 = v5325[v5421];
        int * v5327 = v5278->cache_vals;
        int v5425 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5318 + ((~(((v5320 ^ -1) | (-(v5320 ^ -1))) >> 31)) & 2)) - (v5321 + ((~(((v5322 ^ -1) | (-(v5322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5328 = v5327[v5425];
        int v5426 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5318 + ((~(((v5320 ^ -1) | (-(v5320 ^ -1))) >> 31)) & 2)) - (v5321 + ((~(((v5322 ^ -1) | (-(v5322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5329 = v5327[v5426];
        int * v5330 = v5278->mem;
        int v5428 = v5326 * 2;
        v5330[v5428] = v5328;
        int * v5332 = v5278->mem;
        int v5431 = (v5326 * 2) + 1;
        v5332[v5431] = v5329;
        ;
      } else {
        ;
      }
      int * v5337 = v5278->mem;
      int v5436 = ((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) * 2;
      int v5338 = v5337[v5436];
      int v5437 = (((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) * 2) + 1;
      int v5339 = v5337[v5437];
      int * v5340 = v5278->cache_vals;
      int v5439 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5318 + ((~(((v5320 ^ -1) | (-(v5320 ^ -1))) >> 31)) & 2)) - (v5321 + ((~(((v5322 ^ -1) | (-(v5322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5340[v5439] = v5338;
      int * v5342 = v5278->cache_vals;
      int v5442 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5318 + ((~(((v5320 ^ -1) | (-(v5320 ^ -1))) >> 31)) & 2)) - (v5321 + ((~(((v5322 ^ -1) | (-(v5322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5342[v5442] = v5339;
      int * v5344 = v5278->cache_tags;
      int v5445 = (int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1);
      v5344[v5421] = v5445;
      int * v5346 = v5278->cache_dirty;
      v5346[v5421] = 0;
      int * v5348 = v5278->cache_age;
      v5348[v5421] = 1;
      int * v5350 = v5278->cache_age;
      int v5351 = v5350[v5421];
      int v5352 = v5350[v5395];
      int v5451 = v5352 + ((int)((unsigned int)(v5352 - v5351) >> 31));
      v5350[v5395] = v5451;
      int * v5354 = v5278->cache_age;
      int v5355 = v5354[v5396];
      int v5453 = v5355 + ((int)((unsigned int)(v5355 - v5351) >> 31));
      v5354[v5396] = v5453;
      int * v5357 = v5278->cache_age;
      v5357[v5421] = 0;
      v5360 = v5421;
    }
    int * v5361 = v5278->cache_vals;
    int v5456 = v5360 * 2;
    int v5362 = v5361[v5456];
    int v5457 = (v5360 * 2) + 1;
    int v5363 = v5361[v5457];
    int v5458 = (((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5302 + ((~(((v5304 ^ -1) | (-(v5304 ^ -1))) >> 31)) & 2)) - (v5305 + ((~(((v5306 ^ -1) | (-(v5306 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5361[v5458] = v5362;
    int * v5365 = v5278->cache_vals;
    int v5461 = ((((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5302 + ((~(((v5304 ^ -1) | (-(v5304 ^ -1))) >> 31)) & 2)) - (v5305 + ((~(((v5306 ^ -1) | (-(v5306 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5365[v5461] = v5363;
    int * v5367 = v5278->cache_tags;
    int v5464 = ((((int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5302 + ((~(((v5304 ^ -1) | (-(v5304 ^ -1))) >> 31)) & 2)) - (v5305 + ((~(((v5306 ^ -1) | (-(v5306 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5465 = (int)((unsigned int)((int)((unsigned int)(v5282 + 24) >> 2)) >> 1);
    v5367[v5464] = v5465;
    int * v5369 = v5278->cache_dirty;
    v5369[v5464] = 0;
    int * v5371 = v5278->cache_age;
    v5371[v5464] = 1;
    int * v5373 = v5278->cache_age;
    int v5374 = v5373[v5464];
    int v5375 = v5373[v5393];
    int v5471 = v5375 + ((int)((unsigned int)(v5375 - v5374) >> 31));
    v5373[v5393] = v5471;
    int * v5377 = v5278->cache_age;
    int v5378 = v5377[v5394];
    int v5473 = v5378 + ((int)((unsigned int)(v5378 - v5374) >> 31));
    v5377[v5394] = v5473;
    int * v5380 = v5278->cache_age;
    v5380[v5464] = 0;
    v5383 = v5464;
  }
  int v5476 = (v5383 * 2) + (((int)((unsigned int)(v5282 + 24) >> 2)) & 1);
  int v5384 = v5290[v5476];
  int * v5385 = v5278->regs;
  v5385[13] = v5384;
  struct StateT * v5387 = slot_51(v5278);
  return v5387;
}

struct StateT * slot_36(struct StateT * v3688) {
  int v3689 = v3688->timer;
  int v3799 = v3689 + 1;
  v3688->timer = v3799;
  int * v3691 = v3688->regs;
  int v3692 = v3691[10];
  int * v3693 = v3688->cache_tags;
  int v3803 = (((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2;
  int v3694 = v3693[v3803];
  int v3804 = ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3695 = v3693[v3804];
  int v3805 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2);
  int v3696 = v3693[v3805];
  int v3806 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3697 = v3693[v3806];
  int v3698 = v3688->timer;
  int v3807 = v3698 + ((100 ^ (((~(((v3696 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3696 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3694 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3694 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3695 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3695 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3696 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3696 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3688->timer = v3807;
  int * v3700 = v3688->cache_vals;
  bool v3808 = !(((~(((v3694 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3694 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3695 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3695 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v3793;
  if (v3808) {
    int * v3701 = v3688->cache_age;
    int v3810 = ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v3695 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3695 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v3702 = v3701[v3810];
    int v3703 = v3701[v3803];
    int v3811 = v3703 + ((int)((unsigned int)(v3703 - v3702) >> 31));
    v3701[v3803] = v3811;
    int * v3705 = v3688->cache_age;
    int v3706 = v3705[v3804];
    int v3813 = v3706 + ((int)((unsigned int)(v3706 - v3702) >> 31));
    v3705[v3804] = v3813;
    int * v3708 = v3688->cache_age;
    v3708[v3810] = 0;
    v3793 = v3810;
  } else {
    int * v3711 = v3688->cache_age;
    int v3817 = (((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2;
    int v3712 = v3711[v3817];
    int * v3713 = v3688->cache_tags;
    int v3714 = v3713[v3817];
    int v3715 = v3711[v3804];
    int v3716 = v3713[v3804];
    bool v3819 = !(((~(((v3696 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3696 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v3770;
    if (v3819) {
      int * v3717 = v3688->cache_age;
      int v3821 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))) | (-(v3697 ^ ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v3718 = v3717[v3821];
      int v3719 = v3717[v3805];
      int v3822 = v3719 + ((int)((unsigned int)(v3719 - v3718) >> 31));
      v3717[v3805] = v3822;
      int * v3721 = v3688->cache_age;
      int v3722 = v3721[v3806];
      int v3824 = v3722 + ((int)((unsigned int)(v3722 - v3718) >> 31));
      v3721[v3806] = v3824;
      int * v3724 = v3688->cache_age;
      v3724[v3821] = 0;
      v3770 = v3821;
    } else {
      int * v3727 = v3688->cache_age;
      int v3828 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2);
      int v3728 = v3727[v3828];
      int * v3729 = v3688->cache_tags;
      int v3730 = v3729[v3828];
      int v3731 = v3727[v3806];
      int v3732 = v3729[v3806];
      int * v3733 = v3688->cache_dirty;
      int v3831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3728 + ((~(((v3730 ^ -1) | (-(v3730 ^ -1))) >> 31)) & 2)) - (v3731 + ((~(((v3732 ^ -1) | (-(v3732 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3734 = v3733[v3831];
      bool v3832 = !(v3734 == 0);
      if (v3832) {
        int * v3735 = v3688->cache_tags;
        int v3736 = v3735[v3831];
        int * v3737 = v3688->cache_vals;
        int v3835 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3728 + ((~(((v3730 ^ -1) | (-(v3730 ^ -1))) >> 31)) & 2)) - (v3731 + ((~(((v3732 ^ -1) | (-(v3732 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3738 = v3737[v3835];
        int v3836 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3728 + ((~(((v3730 ^ -1) | (-(v3730 ^ -1))) >> 31)) & 2)) - (v3731 + ((~(((v3732 ^ -1) | (-(v3732 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3739 = v3737[v3836];
        int * v3740 = v3688->mem;
        int v3838 = v3736 * 2;
        v3740[v3838] = v3738;
        int * v3742 = v3688->mem;
        int v3841 = (v3736 * 2) + 1;
        v3742[v3841] = v3739;
        ;
      } else {
        ;
      }
      int * v3747 = v3688->mem;
      int v3846 = ((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) * 2;
      int v3748 = v3747[v3846];
      int v3847 = (((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) * 2) + 1;
      int v3749 = v3747[v3847];
      int * v3750 = v3688->cache_vals;
      int v3849 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3728 + ((~(((v3730 ^ -1) | (-(v3730 ^ -1))) >> 31)) & 2)) - (v3731 + ((~(((v3732 ^ -1) | (-(v3732 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3750[v3849] = v3748;
      int * v3752 = v3688->cache_vals;
      int v3852 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3728 + ((~(((v3730 ^ -1) | (-(v3730 ^ -1))) >> 31)) & 2)) - (v3731 + ((~(((v3732 ^ -1) | (-(v3732 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3752[v3852] = v3749;
      int * v3754 = v3688->cache_tags;
      int v3855 = (int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1);
      v3754[v3831] = v3855;
      int * v3756 = v3688->cache_dirty;
      v3756[v3831] = 0;
      int * v3758 = v3688->cache_age;
      v3758[v3831] = 1;
      int * v3760 = v3688->cache_age;
      int v3761 = v3760[v3831];
      int v3762 = v3760[v3805];
      int v3861 = v3762 + ((int)((unsigned int)(v3762 - v3761) >> 31));
      v3760[v3805] = v3861;
      int * v3764 = v3688->cache_age;
      int v3765 = v3764[v3806];
      int v3863 = v3765 + ((int)((unsigned int)(v3765 - v3761) >> 31));
      v3764[v3806] = v3863;
      int * v3767 = v3688->cache_age;
      v3767[v3831] = 0;
      v3770 = v3831;
    }
    int * v3771 = v3688->cache_vals;
    int v3866 = v3770 * 2;
    int v3772 = v3771[v3866];
    int v3867 = (v3770 * 2) + 1;
    int v3773 = v3771[v3867];
    int v3868 = (((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3712 + ((~(((v3714 ^ -1) | (-(v3714 ^ -1))) >> 31)) & 2)) - (v3715 + ((~(((v3716 ^ -1) | (-(v3716 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3771[v3868] = v3772;
    int * v3775 = v3688->cache_vals;
    int v3871 = ((((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3712 + ((~(((v3714 ^ -1) | (-(v3714 ^ -1))) >> 31)) & 2)) - (v3715 + ((~(((v3716 ^ -1) | (-(v3716 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3775[v3871] = v3773;
    int * v3777 = v3688->cache_tags;
    int v3874 = ((((int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3712 + ((~(((v3714 ^ -1) | (-(v3714 ^ -1))) >> 31)) & 2)) - (v3715 + ((~(((v3716 ^ -1) | (-(v3716 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3875 = (int)((unsigned int)((int)((unsigned int)(v3692 + 16) >> 2)) >> 1);
    v3777[v3874] = v3875;
    int * v3779 = v3688->cache_dirty;
    v3779[v3874] = 0;
    int * v3781 = v3688->cache_age;
    v3781[v3874] = 1;
    int * v3783 = v3688->cache_age;
    int v3784 = v3783[v3874];
    int v3785 = v3783[v3803];
    int v3881 = v3785 + ((int)((unsigned int)(v3785 - v3784) >> 31));
    v3783[v3803] = v3881;
    int * v3787 = v3688->cache_age;
    int v3788 = v3787[v3804];
    int v3883 = v3788 + ((int)((unsigned int)(v3788 - v3784) >> 31));
    v3787[v3804] = v3883;
    int * v3790 = v3688->cache_age;
    v3790[v3874] = 0;
    v3793 = v3874;
  }
  int v3886 = (v3793 * 2) + (((int)((unsigned int)(v3692 + 16) >> 2)) & 1);
  int v3794 = v3700[v3886];
  int * v3795 = v3688->regs;
  v3795[15] = v3794;
  struct StateT * v3797 = slot_37(v3688);
  return v3797;
}

struct StateT * slot_37(struct StateT * v3892) {
  int v3893 = v3892->timer;
  int v4003 = v3893 + 1;
  v3892->timer = v4003;
  int * v3895 = v3892->regs;
  int v3896 = v3895[10];
  int * v3897 = v3892->cache_tags;
  int v4007 = (((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2;
  int v3898 = v3897[v4007];
  int v4008 = ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3899 = v3897[v4008];
  int v4009 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2);
  int v3900 = v3897[v4009];
  int v4010 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3901 = v3897[v4010];
  int v3902 = v3892->timer;
  int v4011 = v3902 + ((100 ^ (((~(((v3900 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3900 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3898 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3898 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3899 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3899 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3900 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3900 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3892->timer = v4011;
  int * v3904 = v3892->cache_vals;
  bool v4012 = !(((~(((v3898 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3898 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3899 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3899 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v3997;
  if (v4012) {
    int * v3905 = v3892->cache_age;
    int v4014 = ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v3899 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3899 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v3906 = v3905[v4014];
    int v3907 = v3905[v4007];
    int v4015 = v3907 + ((int)((unsigned int)(v3907 - v3906) >> 31));
    v3905[v4007] = v4015;
    int * v3909 = v3892->cache_age;
    int v3910 = v3909[v4008];
    int v4017 = v3910 + ((int)((unsigned int)(v3910 - v3906) >> 31));
    v3909[v4008] = v4017;
    int * v3912 = v3892->cache_age;
    v3912[v4014] = 0;
    v3997 = v4014;
  } else {
    int * v3915 = v3892->cache_age;
    int v4021 = (((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2;
    int v3916 = v3915[v4021];
    int * v3917 = v3892->cache_tags;
    int v3918 = v3917[v4021];
    int v3919 = v3915[v4008];
    int v3920 = v3917[v4008];
    bool v4023 = !(((~(((v3900 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3900 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v3974;
    if (v4023) {
      int * v3921 = v3892->cache_age;
      int v4025 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))) | (-(v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v3922 = v3921[v4025];
      int v3923 = v3921[v4009];
      int v4026 = v3923 + ((int)((unsigned int)(v3923 - v3922) >> 31));
      v3921[v4009] = v4026;
      int * v3925 = v3892->cache_age;
      int v3926 = v3925[v4010];
      int v4028 = v3926 + ((int)((unsigned int)(v3926 - v3922) >> 31));
      v3925[v4010] = v4028;
      int * v3928 = v3892->cache_age;
      v3928[v4025] = 0;
      v3974 = v4025;
    } else {
      int * v3931 = v3892->cache_age;
      int v4032 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2);
      int v3932 = v3931[v4032];
      int * v3933 = v3892->cache_tags;
      int v3934 = v3933[v4032];
      int v3935 = v3931[v4010];
      int v3936 = v3933[v4010];
      int * v3937 = v3892->cache_dirty;
      int v4035 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3932 + ((~(((v3934 ^ -1) | (-(v3934 ^ -1))) >> 31)) & 2)) - (v3935 + ((~(((v3936 ^ -1) | (-(v3936 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3938 = v3937[v4035];
      bool v4036 = !(v3938 == 0);
      if (v4036) {
        int * v3939 = v3892->cache_tags;
        int v3940 = v3939[v4035];
        int * v3941 = v3892->cache_vals;
        int v4039 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3932 + ((~(((v3934 ^ -1) | (-(v3934 ^ -1))) >> 31)) & 2)) - (v3935 + ((~(((v3936 ^ -1) | (-(v3936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3942 = v3941[v4039];
        int v4040 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3932 + ((~(((v3934 ^ -1) | (-(v3934 ^ -1))) >> 31)) & 2)) - (v3935 + ((~(((v3936 ^ -1) | (-(v3936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3943 = v3941[v4040];
        int * v3944 = v3892->mem;
        int v4042 = v3940 * 2;
        v3944[v4042] = v3942;
        int * v3946 = v3892->mem;
        int v4045 = (v3940 * 2) + 1;
        v3946[v4045] = v3943;
        ;
      } else {
        ;
      }
      int * v3951 = v3892->mem;
      int v4050 = ((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) * 2;
      int v3952 = v3951[v4050];
      int v4051 = (((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) * 2) + 1;
      int v3953 = v3951[v4051];
      int * v3954 = v3892->cache_vals;
      int v4053 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3932 + ((~(((v3934 ^ -1) | (-(v3934 ^ -1))) >> 31)) & 2)) - (v3935 + ((~(((v3936 ^ -1) | (-(v3936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3954[v4053] = v3952;
      int * v3956 = v3892->cache_vals;
      int v4056 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3932 + ((~(((v3934 ^ -1) | (-(v3934 ^ -1))) >> 31)) & 2)) - (v3935 + ((~(((v3936 ^ -1) | (-(v3936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3956[v4056] = v3953;
      int * v3958 = v3892->cache_tags;
      int v4059 = (int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1);
      v3958[v4035] = v4059;
      int * v3960 = v3892->cache_dirty;
      v3960[v4035] = 0;
      int * v3962 = v3892->cache_age;
      v3962[v4035] = 1;
      int * v3964 = v3892->cache_age;
      int v3965 = v3964[v4035];
      int v3966 = v3964[v4009];
      int v4065 = v3966 + ((int)((unsigned int)(v3966 - v3965) >> 31));
      v3964[v4009] = v4065;
      int * v3968 = v3892->cache_age;
      int v3969 = v3968[v4010];
      int v4067 = v3969 + ((int)((unsigned int)(v3969 - v3965) >> 31));
      v3968[v4010] = v4067;
      int * v3971 = v3892->cache_age;
      v3971[v4035] = 0;
      v3974 = v4035;
    }
    int * v3975 = v3892->cache_vals;
    int v4070 = v3974 * 2;
    int v3976 = v3975[v4070];
    int v4071 = (v3974 * 2) + 1;
    int v3977 = v3975[v4071];
    int v4072 = (((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3916 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2)) - (v3919 + ((~(((v3920 ^ -1) | (-(v3920 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3975[v4072] = v3976;
    int * v3979 = v3892->cache_vals;
    int v4075 = ((((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3916 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2)) - (v3919 + ((~(((v3920 ^ -1) | (-(v3920 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3979[v4075] = v3977;
    int * v3981 = v3892->cache_tags;
    int v4078 = ((((int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3916 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2)) - (v3919 + ((~(((v3920 ^ -1) | (-(v3920 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4079 = (int)((unsigned int)((int)((unsigned int)(v3896 + 20) >> 2)) >> 1);
    v3981[v4078] = v4079;
    int * v3983 = v3892->cache_dirty;
    v3983[v4078] = 0;
    int * v3985 = v3892->cache_age;
    v3985[v4078] = 1;
    int * v3987 = v3892->cache_age;
    int v3988 = v3987[v4078];
    int v3989 = v3987[v4007];
    int v4085 = v3989 + ((int)((unsigned int)(v3989 - v3988) >> 31));
    v3987[v4007] = v4085;
    int * v3991 = v3892->cache_age;
    int v3992 = v3991[v4008];
    int v4087 = v3992 + ((int)((unsigned int)(v3992 - v3988) >> 31));
    v3991[v4008] = v4087;
    int * v3994 = v3892->cache_age;
    v3994[v4078] = 0;
    v3997 = v4078;
  }
  int v4090 = (v3997 * 2) + (((int)((unsigned int)(v3896 + 20) >> 2)) & 1);
  int v3998 = v3904[v4090];
  int * v3999 = v3892->regs;
  v3999[16] = v3998;
  struct StateT * v4001 = slot_38(v3892);
  return v4001;
}

struct StateT * slot_57(struct StateT * v5782) {
  int v5783 = v5782->timer;
  int v5791 = v5783 + 1;
  v5782->timer = v5791;
  int * v5785 = v5782->regs;
  int v5786 = v5785[15];
  int v5787 = v5785[17];
  int v5795 = v5786 - v5787;
  v5785[15] = v5795;
  struct StateT * v5789 = slot_58(v5782);
  return v5789;
}

struct StateT * slot_68(struct StateT * v7306) {
  int v7307 = v7306->timer;
  int v7319 = v7307 + 1;
  v7306->timer = v7319;
  int * v7309 = v7306->regs;
  int v7310 = v7309[16];
  int v7311 = v7309[13];
  bool v7323 = (v7310 ^ -2147483648) < (v7311 ^ -2147483648);
  int v7314;
  if (v7323) {
    v7314 = 1;
  } else {
    v7314 = 0;
  }
  int * v7315 = v7306->regs;
  v7315[12] = v7314;
  struct StateT * v7317 = slot_69(v7306);
  return v7317;
}

struct StateT * slot_59(struct StateT * v5814) {
  int v5815 = v5814->timer;
  int v5823 = v5815 + 1;
  v5814->timer = v5823;
  int * v5817 = v5814->regs;
  int v5818 = v5817[13];
  int v5819 = v5817[16];
  int v5827 = v5818 - v5819;
  v5817[13] = v5827;
  struct StateT * v5821 = slot_60(v5814);
  return v5821;
}

struct StateT * slot_40(struct StateT * v4504) {
  int v4505 = v4504->timer;
  int v4512 = v4505 + 1;
  v4504->timer = v4512;
  int * v4507 = v4504->regs;
  int v4508 = v4507[13];
  int v4516 = v4508 + -8;
  v4507[6] = v4516;
  struct StateT * v4510 = slot_41(v4504);
  return v4510;
}

struct StateT * slot_27(struct StateT * v2561) {
  int v2562 = v2561->timer;
  int v2574 = v2562 + 1;
  v2561->timer = v2574;
  int * v2564 = v2561->regs;
  int v2565 = v2564[15];
  int v2566 = v2564[16];
  bool v2578 = (v2565 ^ -2147483648) < (v2566 ^ -2147483648);
  int v2569;
  if (v2578) {
    v2569 = 1;
  } else {
    v2569 = 0;
  }
  int * v2570 = v2561->regs;
  v2570[5] = v2569;
  struct StateT * v2572 = slot_28(v2561);
  return v2572;
}

struct StateT * slot_15(struct StateT * v1381) {
  int v1382 = v1381->timer;
  int v1390 = v1382 + 1;
  v1381->timer = v1390;
  int * v1384 = v1381->regs;
  int v1385 = v1384[13];
  int v1386 = v1384[6];
  int v1394 = v1385 + v1386;
  v1384[13] = v1394;
  struct StateT * v1388 = slot_16(v1381);
  return v1388;
}

struct StateT * slot_62(struct StateT * v6460) {
  int v6461 = v6460->timer;
  int v6571 = v6461 + 1;
  v6460->timer = v6571;
  int * v6463 = v6460->regs;
  int v6464 = v6463[11];
  int * v6465 = v6460->cache_tags;
  int v6575 = (((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2;
  int v6466 = v6465[v6575];
  int v6576 = ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6467 = v6465[v6576];
  int v6577 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2);
  int v6468 = v6465[v6577];
  int v6578 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6469 = v6465[v6578];
  int v6470 = v6460->timer;
  int v6579 = v6470 + ((100 ^ (((~(((v6468 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6468 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6466 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6466 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6467 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6467 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6468 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6468 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6460->timer = v6579;
  int * v6472 = v6460->cache_vals;
  bool v6580 = !(((~(((v6466 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6466 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6467 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6467 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v6565;
  if (v6580) {
    int * v6473 = v6460->cache_age;
    int v6582 = ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v6467 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6467 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v6474 = v6473[v6582];
    int v6475 = v6473[v6575];
    int v6583 = v6475 + ((int)((unsigned int)(v6475 - v6474) >> 31));
    v6473[v6575] = v6583;
    int * v6477 = v6460->cache_age;
    int v6478 = v6477[v6576];
    int v6585 = v6478 + ((int)((unsigned int)(v6478 - v6474) >> 31));
    v6477[v6576] = v6585;
    int * v6480 = v6460->cache_age;
    v6480[v6582] = 0;
    v6565 = v6582;
  } else {
    int * v6483 = v6460->cache_age;
    int v6589 = (((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2;
    int v6484 = v6483[v6589];
    int * v6485 = v6460->cache_tags;
    int v6486 = v6485[v6589];
    int v6487 = v6483[v6576];
    int v6488 = v6485[v6576];
    bool v6591 = !(((~(((v6468 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6468 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v6542;
    if (v6591) {
      int * v6489 = v6460->cache_age;
      int v6593 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))) | (-(v6469 ^ ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v6490 = v6489[v6593];
      int v6491 = v6489[v6577];
      int v6594 = v6491 + ((int)((unsigned int)(v6491 - v6490) >> 31));
      v6489[v6577] = v6594;
      int * v6493 = v6460->cache_age;
      int v6494 = v6493[v6578];
      int v6596 = v6494 + ((int)((unsigned int)(v6494 - v6490) >> 31));
      v6493[v6578] = v6596;
      int * v6496 = v6460->cache_age;
      v6496[v6593] = 0;
      v6542 = v6593;
    } else {
      int * v6499 = v6460->cache_age;
      int v6600 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2);
      int v6500 = v6499[v6600];
      int * v6501 = v6460->cache_tags;
      int v6502 = v6501[v6600];
      int v6503 = v6499[v6578];
      int v6504 = v6501[v6578];
      int * v6505 = v6460->cache_dirty;
      int v6603 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6500 + ((~(((v6502 ^ -1) | (-(v6502 ^ -1))) >> 31)) & 2)) - (v6503 + ((~(((v6504 ^ -1) | (-(v6504 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6506 = v6505[v6603];
      bool v6604 = !(v6506 == 0);
      if (v6604) {
        int * v6507 = v6460->cache_tags;
        int v6508 = v6507[v6603];
        int * v6509 = v6460->cache_vals;
        int v6607 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6500 + ((~(((v6502 ^ -1) | (-(v6502 ^ -1))) >> 31)) & 2)) - (v6503 + ((~(((v6504 ^ -1) | (-(v6504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6510 = v6509[v6607];
        int v6608 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6500 + ((~(((v6502 ^ -1) | (-(v6502 ^ -1))) >> 31)) & 2)) - (v6503 + ((~(((v6504 ^ -1) | (-(v6504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6511 = v6509[v6608];
        int * v6512 = v6460->mem;
        int v6610 = v6508 * 2;
        v6512[v6610] = v6510;
        int * v6514 = v6460->mem;
        int v6613 = (v6508 * 2) + 1;
        v6514[v6613] = v6511;
        ;
      } else {
        ;
      }
      int * v6519 = v6460->mem;
      int v6618 = ((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) * 2;
      int v6520 = v6519[v6618];
      int v6619 = (((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) * 2) + 1;
      int v6521 = v6519[v6619];
      int * v6522 = v6460->cache_vals;
      int v6621 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6500 + ((~(((v6502 ^ -1) | (-(v6502 ^ -1))) >> 31)) & 2)) - (v6503 + ((~(((v6504 ^ -1) | (-(v6504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6522[v6621] = v6520;
      int * v6524 = v6460->cache_vals;
      int v6624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6500 + ((~(((v6502 ^ -1) | (-(v6502 ^ -1))) >> 31)) & 2)) - (v6503 + ((~(((v6504 ^ -1) | (-(v6504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6524[v6624] = v6521;
      int * v6526 = v6460->cache_tags;
      int v6627 = (int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1);
      v6526[v6603] = v6627;
      int * v6528 = v6460->cache_dirty;
      v6528[v6603] = 0;
      int * v6530 = v6460->cache_age;
      v6530[v6603] = 1;
      int * v6532 = v6460->cache_age;
      int v6533 = v6532[v6603];
      int v6534 = v6532[v6577];
      int v6633 = v6534 + ((int)((unsigned int)(v6534 - v6533) >> 31));
      v6532[v6577] = v6633;
      int * v6536 = v6460->cache_age;
      int v6537 = v6536[v6578];
      int v6635 = v6537 + ((int)((unsigned int)(v6537 - v6533) >> 31));
      v6536[v6578] = v6635;
      int * v6539 = v6460->cache_age;
      v6539[v6603] = 0;
      v6542 = v6603;
    }
    int * v6543 = v6460->cache_vals;
    int v6638 = v6542 * 2;
    int v6544 = v6543[v6638];
    int v6639 = (v6542 * 2) + 1;
    int v6545 = v6543[v6639];
    int v6640 = (((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6484 + ((~(((v6486 ^ -1) | (-(v6486 ^ -1))) >> 31)) & 2)) - (v6487 + ((~(((v6488 ^ -1) | (-(v6488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6543[v6640] = v6544;
    int * v6547 = v6460->cache_vals;
    int v6643 = ((((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6484 + ((~(((v6486 ^ -1) | (-(v6486 ^ -1))) >> 31)) & 2)) - (v6487 + ((~(((v6488 ^ -1) | (-(v6488 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6547[v6643] = v6545;
    int * v6549 = v6460->cache_tags;
    int v6646 = ((((int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6484 + ((~(((v6486 ^ -1) | (-(v6486 ^ -1))) >> 31)) & 2)) - (v6487 + ((~(((v6488 ^ -1) | (-(v6488 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6647 = (int)((unsigned int)((int)((unsigned int)(v6464 + 32) >> 2)) >> 1);
    v6549[v6646] = v6647;
    int * v6551 = v6460->cache_dirty;
    v6551[v6646] = 0;
    int * v6553 = v6460->cache_age;
    v6553[v6646] = 1;
    int * v6555 = v6460->cache_age;
    int v6556 = v6555[v6646];
    int v6557 = v6555[v6575];
    int v6653 = v6557 + ((int)((unsigned int)(v6557 - v6556) >> 31));
    v6555[v6575] = v6653;
    int * v6559 = v6460->cache_age;
    int v6560 = v6559[v6576];
    int v6655 = v6560 + ((int)((unsigned int)(v6560 - v6556) >> 31));
    v6559[v6576] = v6655;
    int * v6562 = v6460->cache_age;
    v6562[v6646] = 0;
    v6565 = v6646;
  }
  int v6658 = (v6565 * 2) + (((int)((unsigned int)(v6464 + 32) >> 2)) & 1);
  int v6566 = v6472[v6658];
  int * v6567 = v6460->regs;
  v6567[13] = v6566;
  struct StateT * v6569 = slot_63(v6460);
  return v6569;
}

struct StateT * slot_48(struct StateT * v4648) {
  int v4649 = v4648->timer;
  int v4819 = v4649 + 1;
  v4648->timer = v4819;
  int * v4651 = v4648->regs;
  int v4652 = v4651[10];
  int v4653 = v4651[15];
  int * v4654 = v4648->cache_tags;
  int v4824 = (((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2;
  int v4655 = v4654[v4824];
  int v4825 = ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4656 = v4654[v4825];
  int v4826 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2);
  int v4657 = v4654[v4826];
  int v4827 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4658 = v4654[v4827];
  int v4659 = v4648->timer;
  int v4828 = v4659 + ((100 ^ (((~(((v4657 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4657 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4656 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4656 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4657 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4657 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4648->timer = v4828;
  bool v4829 = !(((~(((v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4656 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4656 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4753;
  if (v4829) {
    int * v4661 = v4648->cache_age;
    int v4831 = ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v4656 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4656 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4662 = v4661[v4831];
    int v4663 = v4661[v4824];
    int v4832 = v4663 + ((int)((unsigned int)(v4663 - v4662) >> 31));
    v4661[v4824] = v4832;
    int * v4665 = v4648->cache_age;
    int v4666 = v4665[v4825];
    int v4834 = v4666 + ((int)((unsigned int)(v4666 - v4662) >> 31));
    v4665[v4825] = v4834;
    int * v4668 = v4648->cache_age;
    v4668[v4831] = 0;
    v4753 = v4831;
  } else {
    int * v4671 = v4648->cache_age;
    int v4838 = (((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2;
    int v4672 = v4671[v4838];
    int * v4673 = v4648->cache_tags;
    int v4674 = v4673[v4838];
    int v4675 = v4671[v4825];
    int v4676 = v4673[v4825];
    bool v4840 = !(((~(((v4657 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4657 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v4730;
    if (v4840) {
      int * v4677 = v4648->cache_age;
      int v4842 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4658 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v4678 = v4677[v4842];
      int v4679 = v4677[v4826];
      int v4843 = v4679 + ((int)((unsigned int)(v4679 - v4678) >> 31));
      v4677[v4826] = v4843;
      int * v4681 = v4648->cache_age;
      int v4682 = v4681[v4827];
      int v4845 = v4682 + ((int)((unsigned int)(v4682 - v4678) >> 31));
      v4681[v4827] = v4845;
      int * v4684 = v4648->cache_age;
      v4684[v4842] = 0;
      v4730 = v4842;
    } else {
      int * v4687 = v4648->cache_age;
      int v4849 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2);
      int v4688 = v4687[v4849];
      int * v4689 = v4648->cache_tags;
      int v4690 = v4689[v4849];
      int v4691 = v4687[v4827];
      int v4692 = v4689[v4827];
      int * v4693 = v4648->cache_dirty;
      int v4852 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4688 + ((~(((v4690 ^ -1) | (-(v4690 ^ -1))) >> 31)) & 2)) - (v4691 + ((~(((v4692 ^ -1) | (-(v4692 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4694 = v4693[v4852];
      bool v4853 = !(v4694 == 0);
      if (v4853) {
        int * v4695 = v4648->cache_tags;
        int v4696 = v4695[v4852];
        int * v4697 = v4648->cache_vals;
        int v4856 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4688 + ((~(((v4690 ^ -1) | (-(v4690 ^ -1))) >> 31)) & 2)) - (v4691 + ((~(((v4692 ^ -1) | (-(v4692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4698 = v4697[v4856];
        int v4857 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4688 + ((~(((v4690 ^ -1) | (-(v4690 ^ -1))) >> 31)) & 2)) - (v4691 + ((~(((v4692 ^ -1) | (-(v4692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4699 = v4697[v4857];
        int * v4700 = v4648->mem;
        int v4859 = v4696 * 2;
        v4700[v4859] = v4698;
        int * v4702 = v4648->mem;
        int v4862 = (v4696 * 2) + 1;
        v4702[v4862] = v4699;
        ;
      } else {
        ;
      }
      int * v4707 = v4648->mem;
      int v4867 = ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) * 2;
      int v4708 = v4707[v4867];
      int v4868 = (((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4709 = v4707[v4868];
      int * v4710 = v4648->cache_vals;
      int v4870 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4688 + ((~(((v4690 ^ -1) | (-(v4690 ^ -1))) >> 31)) & 2)) - (v4691 + ((~(((v4692 ^ -1) | (-(v4692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4710[v4870] = v4708;
      int * v4712 = v4648->cache_vals;
      int v4873 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4688 + ((~(((v4690 ^ -1) | (-(v4690 ^ -1))) >> 31)) & 2)) - (v4691 + ((~(((v4692 ^ -1) | (-(v4692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4712[v4873] = v4709;
      int * v4714 = v4648->cache_tags;
      int v4876 = (int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1);
      v4714[v4852] = v4876;
      int * v4716 = v4648->cache_dirty;
      v4716[v4852] = 0;
      int * v4718 = v4648->cache_age;
      v4718[v4852] = 1;
      int * v4720 = v4648->cache_age;
      int v4721 = v4720[v4852];
      int v4722 = v4720[v4826];
      int v4882 = v4722 + ((int)((unsigned int)(v4722 - v4721) >> 31));
      v4720[v4826] = v4882;
      int * v4724 = v4648->cache_age;
      int v4725 = v4724[v4827];
      int v4884 = v4725 + ((int)((unsigned int)(v4725 - v4721) >> 31));
      v4724[v4827] = v4884;
      int * v4727 = v4648->cache_age;
      v4727[v4852] = 0;
      v4730 = v4852;
    }
    int * v4731 = v4648->cache_vals;
    int v4887 = v4730 * 2;
    int v4732 = v4731[v4887];
    int v4888 = (v4730 * 2) + 1;
    int v4733 = v4731[v4888];
    int v4889 = (((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4672 + ((~(((v4674 ^ -1) | (-(v4674 ^ -1))) >> 31)) & 2)) - (v4675 + ((~(((v4676 ^ -1) | (-(v4676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4731[v4889] = v4732;
    int * v4735 = v4648->cache_vals;
    int v4892 = ((((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4672 + ((~(((v4674 ^ -1) | (-(v4674 ^ -1))) >> 31)) & 2)) - (v4675 + ((~(((v4676 ^ -1) | (-(v4676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4735[v4892] = v4733;
    int * v4737 = v4648->cache_tags;
    int v4895 = ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4672 + ((~(((v4674 ^ -1) | (-(v4674 ^ -1))) >> 31)) & 2)) - (v4675 + ((~(((v4676 ^ -1) | (-(v4676 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4896 = (int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1);
    v4737[v4895] = v4896;
    int * v4739 = v4648->cache_dirty;
    v4739[v4895] = 0;
    int * v4741 = v4648->cache_age;
    v4741[v4895] = 1;
    int * v4743 = v4648->cache_age;
    int v4744 = v4743[v4895];
    int v4745 = v4743[v4824];
    int v4902 = v4745 + ((int)((unsigned int)(v4745 - v4744) >> 31));
    v4743[v4824] = v4902;
    int * v4747 = v4648->cache_age;
    int v4748 = v4747[v4825];
    int v4904 = v4748 + ((int)((unsigned int)(v4748 - v4744) >> 31));
    v4747[v4825] = v4904;
    int * v4750 = v4648->cache_age;
    v4750[v4895] = 0;
    v4753 = v4895;
  }
  int * v4754 = v4648->cache_vals;
  int v4907 = (v4753 * 2) + (((int)((unsigned int)(v4652 + 16) >> 2)) & 1);
  v4754[v4907] = v4653;
  int * v4756 = v4648->cache_tags;
  int v4757 = v4756[v4826];
  int v4758 = v4756[v4827];
  bool v4910 = !(((~(((v4757 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4757 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4758 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4758 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4812;
  if (v4910) {
    int * v4759 = v4648->cache_age;
    int v4912 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4758 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))) | (-(v4758 ^ ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4760 = v4759[v4912];
    int v4761 = v4759[v4826];
    int v4913 = v4761 + ((int)((unsigned int)(v4761 - v4760) >> 31));
    v4759[v4826] = v4913;
    int * v4763 = v4648->cache_age;
    int v4764 = v4763[v4827];
    int v4915 = v4764 + ((int)((unsigned int)(v4764 - v4760) >> 31));
    v4763[v4827] = v4915;
    int * v4766 = v4648->cache_age;
    v4766[v4912] = 0;
    v4812 = v4912;
  } else {
    int * v4769 = v4648->cache_age;
    int v4919 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2);
    int v4770 = v4769[v4919];
    int * v4771 = v4648->cache_tags;
    int v4772 = v4771[v4919];
    int v4773 = v4769[v4827];
    int v4774 = v4771[v4827];
    int * v4775 = v4648->cache_dirty;
    int v4922 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4770 + ((~(((v4772 ^ -1) | (-(v4772 ^ -1))) >> 31)) & 2)) - (v4773 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4776 = v4775[v4922];
    bool v4923 = !(v4776 == 0);
    if (v4923) {
      int * v4777 = v4648->cache_tags;
      int v4778 = v4777[v4922];
      int * v4779 = v4648->cache_vals;
      int v4926 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4770 + ((~(((v4772 ^ -1) | (-(v4772 ^ -1))) >> 31)) & 2)) - (v4773 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4780 = v4779[v4926];
      int v4927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4770 + ((~(((v4772 ^ -1) | (-(v4772 ^ -1))) >> 31)) & 2)) - (v4773 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4781 = v4779[v4927];
      int * v4782 = v4648->mem;
      int v4929 = v4778 * 2;
      v4782[v4929] = v4780;
      int * v4784 = v4648->mem;
      int v4932 = (v4778 * 2) + 1;
      v4784[v4932] = v4781;
      ;
    } else {
      ;
    }
    int * v4789 = v4648->mem;
    int v4937 = ((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) * 2;
    int v4790 = v4789[v4937];
    int v4938 = (((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) * 2) + 1;
    int v4791 = v4789[v4938];
    int * v4792 = v4648->cache_vals;
    int v4940 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4770 + ((~(((v4772 ^ -1) | (-(v4772 ^ -1))) >> 31)) & 2)) - (v4773 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4792[v4940] = v4790;
    int * v4794 = v4648->cache_vals;
    int v4943 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4770 + ((~(((v4772 ^ -1) | (-(v4772 ^ -1))) >> 31)) & 2)) - (v4773 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4794[v4943] = v4791;
    int * v4796 = v4648->cache_tags;
    int v4946 = (int)((unsigned int)((int)((unsigned int)(v4652 + 16) >> 2)) >> 1);
    v4796[v4922] = v4946;
    int * v4798 = v4648->cache_dirty;
    v4798[v4922] = 0;
    int * v4800 = v4648->cache_age;
    v4800[v4922] = 1;
    int * v4802 = v4648->cache_age;
    int v4803 = v4802[v4922];
    int v4804 = v4802[v4826];
    int v4952 = v4804 + ((int)((unsigned int)(v4804 - v4803) >> 31));
    v4802[v4826] = v4952;
    int * v4806 = v4648->cache_age;
    int v4807 = v4806[v4827];
    int v4954 = v4807 + ((int)((unsigned int)(v4807 - v4803) >> 31));
    v4806[v4827] = v4954;
    int * v4809 = v4648->cache_age;
    v4809[v4922] = 0;
    v4812 = v4922;
  }
  int * v4813 = v4648->cache_vals;
  int v4957 = (v4812 * 2) + (((int)((unsigned int)(v4652 + 16) >> 2)) & 1);
  v4813[v4957] = v4653;
  int * v4815 = v4648->cache_dirty;
  v4815[v4812] = 1;
  struct StateT * v4817 = slot_49(v4648);
  return v4817;
}

struct StateT * slot_22(struct StateT * v2098) {
  int v2099 = v2098->timer;
  int v2209 = v2099 + 1;
  v2098->timer = v2209;
  int * v2101 = v2098->regs;
  int v2102 = v2101[11];
  int * v2103 = v2098->cache_tags;
  int v2213 = (((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2104 = v2103[v2213];
  int v2214 = ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2105 = v2103[v2214];
  int v2215 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2106 = v2103[v2215];
  int v2216 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2107 = v2103[v2216];
  int v2108 = v2098->timer;
  int v2217 = v2108 + ((100 ^ (((~(((v2106 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2106 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2104 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2104 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2105 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2105 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2106 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2106 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2098->timer = v2217;
  int * v2110 = v2098->cache_vals;
  bool v2218 = !(((~(((v2104 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2104 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2105 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2105 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2203;
  if (v2218) {
    int * v2111 = v2098->cache_age;
    int v2220 = ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2105 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2105 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2112 = v2111[v2220];
    int v2113 = v2111[v2213];
    int v2221 = v2113 + ((int)((unsigned int)(v2113 - v2112) >> 31));
    v2111[v2213] = v2221;
    int * v2115 = v2098->cache_age;
    int v2116 = v2115[v2214];
    int v2223 = v2116 + ((int)((unsigned int)(v2116 - v2112) >> 31));
    v2115[v2214] = v2223;
    int * v2118 = v2098->cache_age;
    v2118[v2220] = 0;
    v2203 = v2220;
  } else {
    int * v2121 = v2098->cache_age;
    int v2227 = (((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2122 = v2121[v2227];
    int * v2123 = v2098->cache_tags;
    int v2124 = v2123[v2227];
    int v2125 = v2121[v2214];
    int v2126 = v2123[v2214];
    bool v2229 = !(((~(((v2106 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2106 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2180;
    if (v2229) {
      int * v2127 = v2098->cache_age;
      int v2231 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))) | (-(v2107 ^ ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2128 = v2127[v2231];
      int v2129 = v2127[v2215];
      int v2232 = v2129 + ((int)((unsigned int)(v2129 - v2128) >> 31));
      v2127[v2215] = v2232;
      int * v2131 = v2098->cache_age;
      int v2132 = v2131[v2216];
      int v2234 = v2132 + ((int)((unsigned int)(v2132 - v2128) >> 31));
      v2131[v2216] = v2234;
      int * v2134 = v2098->cache_age;
      v2134[v2231] = 0;
      v2180 = v2231;
    } else {
      int * v2137 = v2098->cache_age;
      int v2238 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2138 = v2137[v2238];
      int * v2139 = v2098->cache_tags;
      int v2140 = v2139[v2238];
      int v2141 = v2137[v2216];
      int v2142 = v2139[v2216];
      int * v2143 = v2098->cache_dirty;
      int v2241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2144 = v2143[v2241];
      bool v2242 = !(v2144 == 0);
      if (v2242) {
        int * v2145 = v2098->cache_tags;
        int v2146 = v2145[v2241];
        int * v2147 = v2098->cache_vals;
        int v2245 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2148 = v2147[v2245];
        int v2246 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2149 = v2147[v2246];
        int * v2150 = v2098->mem;
        int v2248 = v2146 * 2;
        v2150[v2248] = v2148;
        int * v2152 = v2098->mem;
        int v2251 = (v2146 * 2) + 1;
        v2152[v2251] = v2149;
        ;
      } else {
        ;
      }
      int * v2157 = v2098->mem;
      int v2256 = ((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) * 2;
      int v2158 = v2157[v2256];
      int v2257 = (((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2159 = v2157[v2257];
      int * v2160 = v2098->cache_vals;
      int v2259 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2160[v2259] = v2158;
      int * v2162 = v2098->cache_vals;
      int v2262 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2138 + ((~(((v2140 ^ -1) | (-(v2140 ^ -1))) >> 31)) & 2)) - (v2141 + ((~(((v2142 ^ -1) | (-(v2142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2162[v2262] = v2159;
      int * v2164 = v2098->cache_tags;
      int v2265 = (int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1);
      v2164[v2241] = v2265;
      int * v2166 = v2098->cache_dirty;
      v2166[v2241] = 0;
      int * v2168 = v2098->cache_age;
      v2168[v2241] = 1;
      int * v2170 = v2098->cache_age;
      int v2171 = v2170[v2241];
      int v2172 = v2170[v2215];
      int v2271 = v2172 + ((int)((unsigned int)(v2172 - v2171) >> 31));
      v2170[v2215] = v2271;
      int * v2174 = v2098->cache_age;
      int v2175 = v2174[v2216];
      int v2273 = v2175 + ((int)((unsigned int)(v2175 - v2171) >> 31));
      v2174[v2216] = v2273;
      int * v2177 = v2098->cache_age;
      v2177[v2241] = 0;
      v2180 = v2241;
    }
    int * v2181 = v2098->cache_vals;
    int v2276 = v2180 * 2;
    int v2182 = v2181[v2276];
    int v2277 = (v2180 * 2) + 1;
    int v2183 = v2181[v2277];
    int v2278 = (((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2122 + ((~(((v2124 ^ -1) | (-(v2124 ^ -1))) >> 31)) & 2)) - (v2125 + ((~(((v2126 ^ -1) | (-(v2126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2181[v2278] = v2182;
    int * v2185 = v2098->cache_vals;
    int v2281 = ((((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2122 + ((~(((v2124 ^ -1) | (-(v2124 ^ -1))) >> 31)) & 2)) - (v2125 + ((~(((v2126 ^ -1) | (-(v2126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2185[v2281] = v2183;
    int * v2187 = v2098->cache_tags;
    int v2284 = ((((int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2122 + ((~(((v2124 ^ -1) | (-(v2124 ^ -1))) >> 31)) & 2)) - (v2125 + ((~(((v2126 ^ -1) | (-(v2126 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2285 = (int)((unsigned int)((int)((unsigned int)(v2102 + 8) >> 2)) >> 1);
    v2187[v2284] = v2285;
    int * v2189 = v2098->cache_dirty;
    v2189[v2284] = 0;
    int * v2191 = v2098->cache_age;
    v2191[v2284] = 1;
    int * v2193 = v2098->cache_age;
    int v2194 = v2193[v2284];
    int v2195 = v2193[v2213];
    int v2291 = v2195 + ((int)((unsigned int)(v2195 - v2194) >> 31));
    v2193[v2213] = v2291;
    int * v2197 = v2098->cache_age;
    int v2198 = v2197[v2214];
    int v2293 = v2198 + ((int)((unsigned int)(v2198 - v2194) >> 31));
    v2197[v2214] = v2293;
    int * v2200 = v2098->cache_age;
    v2200[v2284] = 0;
    v2203 = v2284;
  }
  int v2296 = (v2203 * 2) + (((int)((unsigned int)(v2102 + 8) >> 2)) & 1);
  int v2204 = v2110[v2296];
  int * v2205 = v2098->regs;
  v2205[13] = v2204;
  struct StateT * v2207 = slot_23(v2098);
  return v2207;
}

struct StateT * slot_35(struct StateT * v3484) {
  int v3485 = v3484->timer;
  int v3595 = v3485 + 1;
  v3484->timer = v3595;
  int * v3487 = v3484->regs;
  int v3488 = v3487[11];
  int * v3489 = v3484->cache_tags;
  int v3599 = (((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2;
  int v3490 = v3489[v3599];
  int v3600 = ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3491 = v3489[v3600];
  int v3601 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2);
  int v3492 = v3489[v3601];
  int v3602 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3493 = v3489[v3602];
  int v3494 = v3484->timer;
  int v3603 = v3494 + ((100 ^ (((~(((v3492 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3492 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3490 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3490 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3491 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3491 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3492 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3492 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3484->timer = v3603;
  int * v3496 = v3484->cache_vals;
  bool v3604 = !(((~(((v3490 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3490 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3491 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3491 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v3589;
  if (v3604) {
    int * v3497 = v3484->cache_age;
    int v3606 = ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v3491 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3491 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v3498 = v3497[v3606];
    int v3499 = v3497[v3599];
    int v3607 = v3499 + ((int)((unsigned int)(v3499 - v3498) >> 31));
    v3497[v3599] = v3607;
    int * v3501 = v3484->cache_age;
    int v3502 = v3501[v3600];
    int v3609 = v3502 + ((int)((unsigned int)(v3502 - v3498) >> 31));
    v3501[v3600] = v3609;
    int * v3504 = v3484->cache_age;
    v3504[v3606] = 0;
    v3589 = v3606;
  } else {
    int * v3507 = v3484->cache_age;
    int v3613 = (((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2;
    int v3508 = v3507[v3613];
    int * v3509 = v3484->cache_tags;
    int v3510 = v3509[v3613];
    int v3511 = v3507[v3600];
    int v3512 = v3509[v3600];
    bool v3615 = !(((~(((v3492 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3492 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v3566;
    if (v3615) {
      int * v3513 = v3484->cache_age;
      int v3617 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))) | (-(v3493 ^ ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v3514 = v3513[v3617];
      int v3515 = v3513[v3601];
      int v3618 = v3515 + ((int)((unsigned int)(v3515 - v3514) >> 31));
      v3513[v3601] = v3618;
      int * v3517 = v3484->cache_age;
      int v3518 = v3517[v3602];
      int v3620 = v3518 + ((int)((unsigned int)(v3518 - v3514) >> 31));
      v3517[v3602] = v3620;
      int * v3520 = v3484->cache_age;
      v3520[v3617] = 0;
      v3566 = v3617;
    } else {
      int * v3523 = v3484->cache_age;
      int v3624 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2);
      int v3524 = v3523[v3624];
      int * v3525 = v3484->cache_tags;
      int v3526 = v3525[v3624];
      int v3527 = v3523[v3602];
      int v3528 = v3525[v3602];
      int * v3529 = v3484->cache_dirty;
      int v3627 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3524 + ((~(((v3526 ^ -1) | (-(v3526 ^ -1))) >> 31)) & 2)) - (v3527 + ((~(((v3528 ^ -1) | (-(v3528 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3530 = v3529[v3627];
      bool v3628 = !(v3530 == 0);
      if (v3628) {
        int * v3531 = v3484->cache_tags;
        int v3532 = v3531[v3627];
        int * v3533 = v3484->cache_vals;
        int v3631 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3524 + ((~(((v3526 ^ -1) | (-(v3526 ^ -1))) >> 31)) & 2)) - (v3527 + ((~(((v3528 ^ -1) | (-(v3528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3534 = v3533[v3631];
        int v3632 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3524 + ((~(((v3526 ^ -1) | (-(v3526 ^ -1))) >> 31)) & 2)) - (v3527 + ((~(((v3528 ^ -1) | (-(v3528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3535 = v3533[v3632];
        int * v3536 = v3484->mem;
        int v3634 = v3532 * 2;
        v3536[v3634] = v3534;
        int * v3538 = v3484->mem;
        int v3637 = (v3532 * 2) + 1;
        v3538[v3637] = v3535;
        ;
      } else {
        ;
      }
      int * v3543 = v3484->mem;
      int v3642 = ((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) * 2;
      int v3544 = v3543[v3642];
      int v3643 = (((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) * 2) + 1;
      int v3545 = v3543[v3643];
      int * v3546 = v3484->cache_vals;
      int v3645 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3524 + ((~(((v3526 ^ -1) | (-(v3526 ^ -1))) >> 31)) & 2)) - (v3527 + ((~(((v3528 ^ -1) | (-(v3528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3546[v3645] = v3544;
      int * v3548 = v3484->cache_vals;
      int v3648 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3524 + ((~(((v3526 ^ -1) | (-(v3526 ^ -1))) >> 31)) & 2)) - (v3527 + ((~(((v3528 ^ -1) | (-(v3528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3548[v3648] = v3545;
      int * v3550 = v3484->cache_tags;
      int v3651 = (int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1);
      v3550[v3627] = v3651;
      int * v3552 = v3484->cache_dirty;
      v3552[v3627] = 0;
      int * v3554 = v3484->cache_age;
      v3554[v3627] = 1;
      int * v3556 = v3484->cache_age;
      int v3557 = v3556[v3627];
      int v3558 = v3556[v3601];
      int v3657 = v3558 + ((int)((unsigned int)(v3558 - v3557) >> 31));
      v3556[v3601] = v3657;
      int * v3560 = v3484->cache_age;
      int v3561 = v3560[v3602];
      int v3659 = v3561 + ((int)((unsigned int)(v3561 - v3557) >> 31));
      v3560[v3602] = v3659;
      int * v3563 = v3484->cache_age;
      v3563[v3627] = 0;
      v3566 = v3627;
    }
    int * v3567 = v3484->cache_vals;
    int v3662 = v3566 * 2;
    int v3568 = v3567[v3662];
    int v3663 = (v3566 * 2) + 1;
    int v3569 = v3567[v3663];
    int v3664 = (((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3508 + ((~(((v3510 ^ -1) | (-(v3510 ^ -1))) >> 31)) & 2)) - (v3511 + ((~(((v3512 ^ -1) | (-(v3512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3567[v3664] = v3568;
    int * v3571 = v3484->cache_vals;
    int v3667 = ((((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3508 + ((~(((v3510 ^ -1) | (-(v3510 ^ -1))) >> 31)) & 2)) - (v3511 + ((~(((v3512 ^ -1) | (-(v3512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3571[v3667] = v3569;
    int * v3573 = v3484->cache_tags;
    int v3670 = ((((int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3508 + ((~(((v3510 ^ -1) | (-(v3510 ^ -1))) >> 31)) & 2)) - (v3511 + ((~(((v3512 ^ -1) | (-(v3512 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3671 = (int)((unsigned int)((int)((unsigned int)(v3488 + 20) >> 2)) >> 1);
    v3573[v3670] = v3671;
    int * v3575 = v3484->cache_dirty;
    v3575[v3670] = 0;
    int * v3577 = v3484->cache_age;
    v3577[v3670] = 1;
    int * v3579 = v3484->cache_age;
    int v3580 = v3579[v3670];
    int v3581 = v3579[v3599];
    int v3677 = v3581 + ((int)((unsigned int)(v3581 - v3580) >> 31));
    v3579[v3599] = v3677;
    int * v3583 = v3484->cache_age;
    int v3584 = v3583[v3600];
    int v3679 = v3584 + ((int)((unsigned int)(v3584 - v3580) >> 31));
    v3583[v3600] = v3679;
    int * v3586 = v3484->cache_age;
    v3586[v3670] = 0;
    v3589 = v3670;
  }
  int v3682 = (v3589 * 2) + (((int)((unsigned int)(v3488 + 20) >> 2)) & 1);
  int v3590 = v3496[v3682];
  int * v3591 = v3484->regs;
  v3591[14] = v3590;
  struct StateT * v3593 = slot_36(v3484);
  return v3593;
}

struct StateT * slot_75(struct StateT * v7735) {
  int v7736 = v7735->timer;
  int v7906 = v7736 + 1;
  v7735->timer = v7906;
  int * v7738 = v7735->regs;
  int v7739 = v7738[10];
  int v7740 = v7738[11];
  int * v7741 = v7735->cache_tags;
  int v7911 = (((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2;
  int v7742 = v7741[v7911];
  int v7912 = ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7743 = v7741[v7912];
  int v7913 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2);
  int v7744 = v7741[v7913];
  int v7914 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7745 = v7741[v7914];
  int v7746 = v7735->timer;
  int v7915 = v7746 + ((100 ^ (((~(((v7744 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7744 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7742 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7742 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7743 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7743 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7744 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7744 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7735->timer = v7915;
  bool v7916 = !(((~(((v7742 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7742 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7743 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7743 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7840;
  if (v7916) {
    int * v7748 = v7735->cache_age;
    int v7918 = ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v7743 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7743 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7749 = v7748[v7918];
    int v7750 = v7748[v7911];
    int v7919 = v7750 + ((int)((unsigned int)(v7750 - v7749) >> 31));
    v7748[v7911] = v7919;
    int * v7752 = v7735->cache_age;
    int v7753 = v7752[v7912];
    int v7921 = v7753 + ((int)((unsigned int)(v7753 - v7749) >> 31));
    v7752[v7912] = v7921;
    int * v7755 = v7735->cache_age;
    v7755[v7918] = 0;
    v7840 = v7918;
  } else {
    int * v7758 = v7735->cache_age;
    int v7925 = (((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2;
    int v7759 = v7758[v7925];
    int * v7760 = v7735->cache_tags;
    int v7761 = v7760[v7925];
    int v7762 = v7758[v7912];
    int v7763 = v7760[v7912];
    bool v7927 = !(((~(((v7744 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7744 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v7817;
    if (v7927) {
      int * v7764 = v7735->cache_age;
      int v7929 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7745 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v7765 = v7764[v7929];
      int v7766 = v7764[v7913];
      int v7930 = v7766 + ((int)((unsigned int)(v7766 - v7765) >> 31));
      v7764[v7913] = v7930;
      int * v7768 = v7735->cache_age;
      int v7769 = v7768[v7914];
      int v7932 = v7769 + ((int)((unsigned int)(v7769 - v7765) >> 31));
      v7768[v7914] = v7932;
      int * v7771 = v7735->cache_age;
      v7771[v7929] = 0;
      v7817 = v7929;
    } else {
      int * v7774 = v7735->cache_age;
      int v7936 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2);
      int v7775 = v7774[v7936];
      int * v7776 = v7735->cache_tags;
      int v7777 = v7776[v7936];
      int v7778 = v7774[v7914];
      int v7779 = v7776[v7914];
      int * v7780 = v7735->cache_dirty;
      int v7939 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7775 + ((~(((v7777 ^ -1) | (-(v7777 ^ -1))) >> 31)) & 2)) - (v7778 + ((~(((v7779 ^ -1) | (-(v7779 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7781 = v7780[v7939];
      bool v7940 = !(v7781 == 0);
      if (v7940) {
        int * v7782 = v7735->cache_tags;
        int v7783 = v7782[v7939];
        int * v7784 = v7735->cache_vals;
        int v7943 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7775 + ((~(((v7777 ^ -1) | (-(v7777 ^ -1))) >> 31)) & 2)) - (v7778 + ((~(((v7779 ^ -1) | (-(v7779 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7785 = v7784[v7943];
        int v7944 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7775 + ((~(((v7777 ^ -1) | (-(v7777 ^ -1))) >> 31)) & 2)) - (v7778 + ((~(((v7779 ^ -1) | (-(v7779 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7786 = v7784[v7944];
        int * v7787 = v7735->mem;
        int v7946 = v7783 * 2;
        v7787[v7946] = v7785;
        int * v7789 = v7735->mem;
        int v7949 = (v7783 * 2) + 1;
        v7789[v7949] = v7786;
        ;
      } else {
        ;
      }
      int * v7794 = v7735->mem;
      int v7954 = ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) * 2;
      int v7795 = v7794[v7954];
      int v7955 = (((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) * 2) + 1;
      int v7796 = v7794[v7955];
      int * v7797 = v7735->cache_vals;
      int v7957 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7775 + ((~(((v7777 ^ -1) | (-(v7777 ^ -1))) >> 31)) & 2)) - (v7778 + ((~(((v7779 ^ -1) | (-(v7779 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7797[v7957] = v7795;
      int * v7799 = v7735->cache_vals;
      int v7960 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7775 + ((~(((v7777 ^ -1) | (-(v7777 ^ -1))) >> 31)) & 2)) - (v7778 + ((~(((v7779 ^ -1) | (-(v7779 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7799[v7960] = v7796;
      int * v7801 = v7735->cache_tags;
      int v7963 = (int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1);
      v7801[v7939] = v7963;
      int * v7803 = v7735->cache_dirty;
      v7803[v7939] = 0;
      int * v7805 = v7735->cache_age;
      v7805[v7939] = 1;
      int * v7807 = v7735->cache_age;
      int v7808 = v7807[v7939];
      int v7809 = v7807[v7913];
      int v7969 = v7809 + ((int)((unsigned int)(v7809 - v7808) >> 31));
      v7807[v7913] = v7969;
      int * v7811 = v7735->cache_age;
      int v7812 = v7811[v7914];
      int v7971 = v7812 + ((int)((unsigned int)(v7812 - v7808) >> 31));
      v7811[v7914] = v7971;
      int * v7814 = v7735->cache_age;
      v7814[v7939] = 0;
      v7817 = v7939;
    }
    int * v7818 = v7735->cache_vals;
    int v7974 = v7817 * 2;
    int v7819 = v7818[v7974];
    int v7975 = (v7817 * 2) + 1;
    int v7820 = v7818[v7975];
    int v7976 = (((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7818[v7976] = v7819;
    int * v7822 = v7735->cache_vals;
    int v7979 = ((((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7822[v7979] = v7820;
    int * v7824 = v7735->cache_tags;
    int v7982 = ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7983 = (int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1);
    v7824[v7982] = v7983;
    int * v7826 = v7735->cache_dirty;
    v7826[v7982] = 0;
    int * v7828 = v7735->cache_age;
    v7828[v7982] = 1;
    int * v7830 = v7735->cache_age;
    int v7831 = v7830[v7982];
    int v7832 = v7830[v7911];
    int v7989 = v7832 + ((int)((unsigned int)(v7832 - v7831) >> 31));
    v7830[v7911] = v7989;
    int * v7834 = v7735->cache_age;
    int v7835 = v7834[v7912];
    int v7991 = v7835 + ((int)((unsigned int)(v7835 - v7831) >> 31));
    v7834[v7912] = v7991;
    int * v7837 = v7735->cache_age;
    v7837[v7982] = 0;
    v7840 = v7982;
  }
  int * v7841 = v7735->cache_vals;
  int v7994 = (v7840 * 2) + (((int)((unsigned int)(v7739 + 36) >> 2)) & 1);
  v7841[v7994] = v7740;
  int * v7843 = v7735->cache_tags;
  int v7844 = v7843[v7913];
  int v7845 = v7843[v7914];
  bool v7997 = !(((~(((v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7844 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7899;
  if (v7997) {
    int * v7846 = v7735->cache_age;
    int v7999 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))) | (-(v7845 ^ ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7847 = v7846[v7999];
    int v7848 = v7846[v7913];
    int v8000 = v7848 + ((int)((unsigned int)(v7848 - v7847) >> 31));
    v7846[v7913] = v8000;
    int * v7850 = v7735->cache_age;
    int v7851 = v7850[v7914];
    int v8002 = v7851 + ((int)((unsigned int)(v7851 - v7847) >> 31));
    v7850[v7914] = v8002;
    int * v7853 = v7735->cache_age;
    v7853[v7999] = 0;
    v7899 = v7999;
  } else {
    int * v7856 = v7735->cache_age;
    int v8006 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2);
    int v7857 = v7856[v8006];
    int * v7858 = v7735->cache_tags;
    int v7859 = v7858[v8006];
    int v7860 = v7856[v7914];
    int v7861 = v7858[v7914];
    int * v7862 = v7735->cache_dirty;
    int v8009 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7857 + ((~(((v7859 ^ -1) | (-(v7859 ^ -1))) >> 31)) & 2)) - (v7860 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7863 = v7862[v8009];
    bool v8010 = !(v7863 == 0);
    if (v8010) {
      int * v7864 = v7735->cache_tags;
      int v7865 = v7864[v8009];
      int * v7866 = v7735->cache_vals;
      int v8013 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7857 + ((~(((v7859 ^ -1) | (-(v7859 ^ -1))) >> 31)) & 2)) - (v7860 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7867 = v7866[v8013];
      int v8014 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7857 + ((~(((v7859 ^ -1) | (-(v7859 ^ -1))) >> 31)) & 2)) - (v7860 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7868 = v7866[v8014];
      int * v7869 = v7735->mem;
      int v8016 = v7865 * 2;
      v7869[v8016] = v7867;
      int * v7871 = v7735->mem;
      int v8019 = (v7865 * 2) + 1;
      v7871[v8019] = v7868;
      ;
    } else {
      ;
    }
    int * v7876 = v7735->mem;
    int v8024 = ((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) * 2;
    int v7877 = v7876[v8024];
    int v8025 = (((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) * 2) + 1;
    int v7878 = v7876[v8025];
    int * v7879 = v7735->cache_vals;
    int v8027 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7857 + ((~(((v7859 ^ -1) | (-(v7859 ^ -1))) >> 31)) & 2)) - (v7860 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7879[v8027] = v7877;
    int * v7881 = v7735->cache_vals;
    int v8030 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7857 + ((~(((v7859 ^ -1) | (-(v7859 ^ -1))) >> 31)) & 2)) - (v7860 + ((~(((v7861 ^ -1) | (-(v7861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7881[v8030] = v7878;
    int * v7883 = v7735->cache_tags;
    int v8033 = (int)((unsigned int)((int)((unsigned int)(v7739 + 36) >> 2)) >> 1);
    v7883[v8009] = v8033;
    int * v7885 = v7735->cache_dirty;
    v7885[v8009] = 0;
    int * v7887 = v7735->cache_age;
    v7887[v8009] = 1;
    int * v7889 = v7735->cache_age;
    int v7890 = v7889[v8009];
    int v7891 = v7889[v7913];
    int v8039 = v7891 + ((int)((unsigned int)(v7891 - v7890) >> 31));
    v7889[v7913] = v8039;
    int * v7893 = v7735->cache_age;
    int v7894 = v7893[v7914];
    int v8041 = v7894 + ((int)((unsigned int)(v7894 - v7890) >> 31));
    v7893[v7914] = v8041;
    int * v7896 = v7735->cache_age;
    v7896[v8009] = 0;
    v7899 = v8009;
  }
  int * v7900 = v7735->cache_vals;
  int v8044 = (v7899 * 2) + (((int)((unsigned int)(v7739 + 36) >> 2)) & 1);
  v7900[v8044] = v7740;
  int * v7902 = v7735->cache_dirty;
  v7902[v7899] = 1;
  struct StateT * v7904 = slot_76(v7735);
  return v7904;
}

struct StateT * slot_56(struct StateT * v5766) {
  int v5767 = v5766->timer;
  int v5775 = v5767 + 1;
  v5766->timer = v5775;
  int * v5769 = v5766->regs;
  int v5770 = v5769[14];
  int v5771 = v5769[5];
  int v5779 = v5770 - v5771;
  v5769[14] = v5779;
  struct StateT * v5773 = slot_57(v5766);
  return v5773;
}

struct StateT * slot_72(struct StateT * v7388) {
  int v7389 = v7388->timer;
  int v7397 = v7389 + 1;
  v7388->timer = v7397;
  int * v7391 = v7388->regs;
  int v7392 = v7391[11];
  int v7393 = v7391[12];
  int v7401 = v7392 + v7393;
  v7391[11] = v7401;
  struct StateT * v7395 = slot_73(v7388);
  return v7395;
}

struct StateT * slot_34(struct StateT * v3280) {
  int v3281 = v3280->timer;
  int v3391 = v3281 + 1;
  v3280->timer = v3391;
  int * v3283 = v3280->regs;
  int v3284 = v3283[11];
  int * v3285 = v3280->cache_tags;
  int v3395 = (((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2;
  int v3286 = v3285[v3395];
  int v3396 = ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3287 = v3285[v3396];
  int v3397 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2);
  int v3288 = v3285[v3397];
  int v3398 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3289 = v3285[v3398];
  int v3290 = v3280->timer;
  int v3399 = v3290 + ((100 ^ (((~(((v3288 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3288 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3286 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3286 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3287 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3287 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3288 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3288 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3280->timer = v3399;
  int * v3292 = v3280->cache_vals;
  bool v3400 = !(((~(((v3286 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3286 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3287 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3287 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v3385;
  if (v3400) {
    int * v3293 = v3280->cache_age;
    int v3402 = ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v3287 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3287 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v3294 = v3293[v3402];
    int v3295 = v3293[v3395];
    int v3403 = v3295 + ((int)((unsigned int)(v3295 - v3294) >> 31));
    v3293[v3395] = v3403;
    int * v3297 = v3280->cache_age;
    int v3298 = v3297[v3396];
    int v3405 = v3298 + ((int)((unsigned int)(v3298 - v3294) >> 31));
    v3297[v3396] = v3405;
    int * v3300 = v3280->cache_age;
    v3300[v3402] = 0;
    v3385 = v3402;
  } else {
    int * v3303 = v3280->cache_age;
    int v3409 = (((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2;
    int v3304 = v3303[v3409];
    int * v3305 = v3280->cache_tags;
    int v3306 = v3305[v3409];
    int v3307 = v3303[v3396];
    int v3308 = v3305[v3396];
    bool v3411 = !(((~(((v3288 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3288 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v3362;
    if (v3411) {
      int * v3309 = v3280->cache_age;
      int v3413 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v3310 = v3309[v3413];
      int v3311 = v3309[v3397];
      int v3414 = v3311 + ((int)((unsigned int)(v3311 - v3310) >> 31));
      v3309[v3397] = v3414;
      int * v3313 = v3280->cache_age;
      int v3314 = v3313[v3398];
      int v3416 = v3314 + ((int)((unsigned int)(v3314 - v3310) >> 31));
      v3313[v3398] = v3416;
      int * v3316 = v3280->cache_age;
      v3316[v3413] = 0;
      v3362 = v3413;
    } else {
      int * v3319 = v3280->cache_age;
      int v3420 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2);
      int v3320 = v3319[v3420];
      int * v3321 = v3280->cache_tags;
      int v3322 = v3321[v3420];
      int v3323 = v3319[v3398];
      int v3324 = v3321[v3398];
      int * v3325 = v3280->cache_dirty;
      int v3423 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3320 + ((~(((v3322 ^ -1) | (-(v3322 ^ -1))) >> 31)) & 2)) - (v3323 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3326 = v3325[v3423];
      bool v3424 = !(v3326 == 0);
      if (v3424) {
        int * v3327 = v3280->cache_tags;
        int v3328 = v3327[v3423];
        int * v3329 = v3280->cache_vals;
        int v3427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3320 + ((~(((v3322 ^ -1) | (-(v3322 ^ -1))) >> 31)) & 2)) - (v3323 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3330 = v3329[v3427];
        int v3428 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3320 + ((~(((v3322 ^ -1) | (-(v3322 ^ -1))) >> 31)) & 2)) - (v3323 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3331 = v3329[v3428];
        int * v3332 = v3280->mem;
        int v3430 = v3328 * 2;
        v3332[v3430] = v3330;
        int * v3334 = v3280->mem;
        int v3433 = (v3328 * 2) + 1;
        v3334[v3433] = v3331;
        ;
      } else {
        ;
      }
      int * v3339 = v3280->mem;
      int v3438 = ((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) * 2;
      int v3340 = v3339[v3438];
      int v3439 = (((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) * 2) + 1;
      int v3341 = v3339[v3439];
      int * v3342 = v3280->cache_vals;
      int v3441 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3320 + ((~(((v3322 ^ -1) | (-(v3322 ^ -1))) >> 31)) & 2)) - (v3323 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3342[v3441] = v3340;
      int * v3344 = v3280->cache_vals;
      int v3444 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3320 + ((~(((v3322 ^ -1) | (-(v3322 ^ -1))) >> 31)) & 2)) - (v3323 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3344[v3444] = v3341;
      int * v3346 = v3280->cache_tags;
      int v3447 = (int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1);
      v3346[v3423] = v3447;
      int * v3348 = v3280->cache_dirty;
      v3348[v3423] = 0;
      int * v3350 = v3280->cache_age;
      v3350[v3423] = 1;
      int * v3352 = v3280->cache_age;
      int v3353 = v3352[v3423];
      int v3354 = v3352[v3397];
      int v3453 = v3354 + ((int)((unsigned int)(v3354 - v3353) >> 31));
      v3352[v3397] = v3453;
      int * v3356 = v3280->cache_age;
      int v3357 = v3356[v3398];
      int v3455 = v3357 + ((int)((unsigned int)(v3357 - v3353) >> 31));
      v3356[v3398] = v3455;
      int * v3359 = v3280->cache_age;
      v3359[v3423] = 0;
      v3362 = v3423;
    }
    int * v3363 = v3280->cache_vals;
    int v3458 = v3362 * 2;
    int v3364 = v3363[v3458];
    int v3459 = (v3362 * 2) + 1;
    int v3365 = v3363[v3459];
    int v3460 = (((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3304 + ((~(((v3306 ^ -1) | (-(v3306 ^ -1))) >> 31)) & 2)) - (v3307 + ((~(((v3308 ^ -1) | (-(v3308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3363[v3460] = v3364;
    int * v3367 = v3280->cache_vals;
    int v3463 = ((((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3304 + ((~(((v3306 ^ -1) | (-(v3306 ^ -1))) >> 31)) & 2)) - (v3307 + ((~(((v3308 ^ -1) | (-(v3308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3367[v3463] = v3365;
    int * v3369 = v3280->cache_tags;
    int v3466 = ((((int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3304 + ((~(((v3306 ^ -1) | (-(v3306 ^ -1))) >> 31)) & 2)) - (v3307 + ((~(((v3308 ^ -1) | (-(v3308 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3467 = (int)((unsigned int)((int)((unsigned int)(v3284 + 16) >> 2)) >> 1);
    v3369[v3466] = v3467;
    int * v3371 = v3280->cache_dirty;
    v3371[v3466] = 0;
    int * v3373 = v3280->cache_age;
    v3373[v3466] = 1;
    int * v3375 = v3280->cache_age;
    int v3376 = v3375[v3466];
    int v3377 = v3375[v3395];
    int v3473 = v3377 + ((int)((unsigned int)(v3377 - v3376) >> 31));
    v3375[v3395] = v3473;
    int * v3379 = v3280->cache_age;
    int v3380 = v3379[v3396];
    int v3475 = v3380 + ((int)((unsigned int)(v3380 - v3376) >> 31));
    v3379[v3396] = v3475;
    int * v3382 = v3280->cache_age;
    v3382[v3466] = 0;
    v3385 = v3466;
  }
  int v3478 = (v3385 * 2) + (((int)((unsigned int)(v3284 + 16) >> 2)) & 1);
  int v3386 = v3292[v3478];
  int * v3387 = v3280->regs;
  v3387[13] = v3386;
  struct StateT * v3389 = slot_35(v3280);
  return v3389;
}

struct StateT * slot_71(struct StateT * v7372) {
  int v7373 = v7372->timer;
  int v7381 = v7373 + 1;
  v7372->timer = v7381;
  int * v7375 = v7372->regs;
  int v7376 = v7375[16];
  int v7377 = v7375[14];
  int v7385 = v7376 - v7377;
  v7375[14] = v7385;
  struct StateT * v7379 = slot_72(v7372);
  return v7379;
}

struct StateT * slot_51(struct StateT * v5482) {
  int v5483 = v5482->timer;
  int v5593 = v5483 + 1;
  v5482->timer = v5593;
  int * v5485 = v5482->regs;
  int v5486 = v5485[11];
  int * v5487 = v5482->cache_tags;
  int v5597 = (((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2;
  int v5488 = v5487[v5597];
  int v5598 = ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5489 = v5487[v5598];
  int v5599 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2);
  int v5490 = v5487[v5599];
  int v5600 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5491 = v5487[v5600];
  int v5492 = v5482->timer;
  int v5601 = v5492 + ((100 ^ (((~(((v5490 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5490 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5488 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5488 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5489 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5489 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5490 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5490 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5482->timer = v5601;
  int * v5494 = v5482->cache_vals;
  bool v5602 = !(((~(((v5488 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5488 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5489 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5489 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v5587;
  if (v5602) {
    int * v5495 = v5482->cache_age;
    int v5604 = ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v5489 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5489 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v5496 = v5495[v5604];
    int v5497 = v5495[v5597];
    int v5605 = v5497 + ((int)((unsigned int)(v5497 - v5496) >> 31));
    v5495[v5597] = v5605;
    int * v5499 = v5482->cache_age;
    int v5500 = v5499[v5598];
    int v5607 = v5500 + ((int)((unsigned int)(v5500 - v5496) >> 31));
    v5499[v5598] = v5607;
    int * v5502 = v5482->cache_age;
    v5502[v5604] = 0;
    v5587 = v5604;
  } else {
    int * v5505 = v5482->cache_age;
    int v5611 = (((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2;
    int v5506 = v5505[v5611];
    int * v5507 = v5482->cache_tags;
    int v5508 = v5507[v5611];
    int v5509 = v5505[v5598];
    int v5510 = v5507[v5598];
    bool v5613 = !(((~(((v5490 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5490 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v5564;
    if (v5613) {
      int * v5511 = v5482->cache_age;
      int v5615 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))) | (-(v5491 ^ ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v5512 = v5511[v5615];
      int v5513 = v5511[v5599];
      int v5616 = v5513 + ((int)((unsigned int)(v5513 - v5512) >> 31));
      v5511[v5599] = v5616;
      int * v5515 = v5482->cache_age;
      int v5516 = v5515[v5600];
      int v5618 = v5516 + ((int)((unsigned int)(v5516 - v5512) >> 31));
      v5515[v5600] = v5618;
      int * v5518 = v5482->cache_age;
      v5518[v5615] = 0;
      v5564 = v5615;
    } else {
      int * v5521 = v5482->cache_age;
      int v5622 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2);
      int v5522 = v5521[v5622];
      int * v5523 = v5482->cache_tags;
      int v5524 = v5523[v5622];
      int v5525 = v5521[v5600];
      int v5526 = v5523[v5600];
      int * v5527 = v5482->cache_dirty;
      int v5625 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5522 + ((~(((v5524 ^ -1) | (-(v5524 ^ -1))) >> 31)) & 2)) - (v5525 + ((~(((v5526 ^ -1) | (-(v5526 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5528 = v5527[v5625];
      bool v5626 = !(v5528 == 0);
      if (v5626) {
        int * v5529 = v5482->cache_tags;
        int v5530 = v5529[v5625];
        int * v5531 = v5482->cache_vals;
        int v5629 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5522 + ((~(((v5524 ^ -1) | (-(v5524 ^ -1))) >> 31)) & 2)) - (v5525 + ((~(((v5526 ^ -1) | (-(v5526 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5532 = v5531[v5629];
        int v5630 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5522 + ((~(((v5524 ^ -1) | (-(v5524 ^ -1))) >> 31)) & 2)) - (v5525 + ((~(((v5526 ^ -1) | (-(v5526 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5533 = v5531[v5630];
        int * v5534 = v5482->mem;
        int v5632 = v5530 * 2;
        v5534[v5632] = v5532;
        int * v5536 = v5482->mem;
        int v5635 = (v5530 * 2) + 1;
        v5536[v5635] = v5533;
        ;
      } else {
        ;
      }
      int * v5541 = v5482->mem;
      int v5640 = ((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) * 2;
      int v5542 = v5541[v5640];
      int v5641 = (((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) * 2) + 1;
      int v5543 = v5541[v5641];
      int * v5544 = v5482->cache_vals;
      int v5643 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5522 + ((~(((v5524 ^ -1) | (-(v5524 ^ -1))) >> 31)) & 2)) - (v5525 + ((~(((v5526 ^ -1) | (-(v5526 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5544[v5643] = v5542;
      int * v5546 = v5482->cache_vals;
      int v5646 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5522 + ((~(((v5524 ^ -1) | (-(v5524 ^ -1))) >> 31)) & 2)) - (v5525 + ((~(((v5526 ^ -1) | (-(v5526 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5546[v5646] = v5543;
      int * v5548 = v5482->cache_tags;
      int v5649 = (int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1);
      v5548[v5625] = v5649;
      int * v5550 = v5482->cache_dirty;
      v5550[v5625] = 0;
      int * v5552 = v5482->cache_age;
      v5552[v5625] = 1;
      int * v5554 = v5482->cache_age;
      int v5555 = v5554[v5625];
      int v5556 = v5554[v5599];
      int v5655 = v5556 + ((int)((unsigned int)(v5556 - v5555) >> 31));
      v5554[v5599] = v5655;
      int * v5558 = v5482->cache_age;
      int v5559 = v5558[v5600];
      int v5657 = v5559 + ((int)((unsigned int)(v5559 - v5555) >> 31));
      v5558[v5600] = v5657;
      int * v5561 = v5482->cache_age;
      v5561[v5625] = 0;
      v5564 = v5625;
    }
    int * v5565 = v5482->cache_vals;
    int v5660 = v5564 * 2;
    int v5566 = v5565[v5660];
    int v5661 = (v5564 * 2) + 1;
    int v5567 = v5565[v5661];
    int v5662 = (((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5506 + ((~(((v5508 ^ -1) | (-(v5508 ^ -1))) >> 31)) & 2)) - (v5509 + ((~(((v5510 ^ -1) | (-(v5510 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5565[v5662] = v5566;
    int * v5569 = v5482->cache_vals;
    int v5665 = ((((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5506 + ((~(((v5508 ^ -1) | (-(v5508 ^ -1))) >> 31)) & 2)) - (v5509 + ((~(((v5510 ^ -1) | (-(v5510 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5569[v5665] = v5567;
    int * v5571 = v5482->cache_tags;
    int v5668 = ((((int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5506 + ((~(((v5508 ^ -1) | (-(v5508 ^ -1))) >> 31)) & 2)) - (v5509 + ((~(((v5510 ^ -1) | (-(v5510 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5669 = (int)((unsigned int)((int)((unsigned int)(v5486 + 28) >> 2)) >> 1);
    v5571[v5668] = v5669;
    int * v5573 = v5482->cache_dirty;
    v5573[v5668] = 0;
    int * v5575 = v5482->cache_age;
    v5575[v5668] = 1;
    int * v5577 = v5482->cache_age;
    int v5578 = v5577[v5668];
    int v5579 = v5577[v5597];
    int v5675 = v5579 + ((int)((unsigned int)(v5579 - v5578) >> 31));
    v5577[v5597] = v5675;
    int * v5581 = v5482->cache_age;
    int v5582 = v5581[v5598];
    int v5677 = v5582 + ((int)((unsigned int)(v5582 - v5578) >> 31));
    v5581[v5598] = v5677;
    int * v5584 = v5482->cache_age;
    v5584[v5668] = 0;
    v5587 = v5668;
  }
  int v5680 = (v5587 * 2) + (((int)((unsigned int)(v5486 + 28) >> 2)) & 1);
  int v5588 = v5494[v5680];
  int * v5589 = v5482->regs;
  v5589[14] = v5588;
  struct StateT * v5591 = slot_52(v5482);
  return v5591;
}

struct StateT * slot_52(struct StateT * v5686) {
  int v5687 = v5686->timer;
  int v5694 = v5687 + 1;
  v5686->timer = v5694;
  int * v5689 = v5686->regs;
  int v5690 = v5689[13];
  int v5698 = v5690 + -8;
  v5689[15] = v5698;
  struct StateT * v5692 = slot_53(v5686);
  return v5692;
}

struct StateT * slot_25(struct StateT * v2521) {
  int v2522 = v2521->timer;
  int v2530 = v2522 + 1;
  v2521->timer = v2530;
  int * v2524 = v2521->regs;
  int v2525 = v2524[14];
  int v2526 = v2524[12];
  int v2534 = v2525 + v2526;
  v2524[14] = v2534;
  struct StateT * v2528 = slot_26(v2521);
  return v2528;
}

struct StateT * slot_23(struct StateT * v2302) {
  int v2303 = v2302->timer;
  int v2413 = v2303 + 1;
  v2302->timer = v2413;
  int * v2305 = v2302->regs;
  int v2306 = v2305[11];
  int * v2307 = v2302->cache_tags;
  int v2417 = (((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2308 = v2307[v2417];
  int v2418 = ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2309 = v2307[v2418];
  int v2419 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2310 = v2307[v2419];
  int v2420 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2311 = v2307[v2420];
  int v2312 = v2302->timer;
  int v2421 = v2312 + ((100 ^ (((~(((v2310 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2310 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2308 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2308 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2309 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2309 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2310 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2310 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2302->timer = v2421;
  int * v2314 = v2302->cache_vals;
  bool v2422 = !(((~(((v2308 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2308 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2309 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2309 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2407;
  if (v2422) {
    int * v2315 = v2302->cache_age;
    int v2424 = ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2309 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2309 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2316 = v2315[v2424];
    int v2317 = v2315[v2417];
    int v2425 = v2317 + ((int)((unsigned int)(v2317 - v2316) >> 31));
    v2315[v2417] = v2425;
    int * v2319 = v2302->cache_age;
    int v2320 = v2319[v2418];
    int v2427 = v2320 + ((int)((unsigned int)(v2320 - v2316) >> 31));
    v2319[v2418] = v2427;
    int * v2322 = v2302->cache_age;
    v2322[v2424] = 0;
    v2407 = v2424;
  } else {
    int * v2325 = v2302->cache_age;
    int v2431 = (((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2326 = v2325[v2431];
    int * v2327 = v2302->cache_tags;
    int v2328 = v2327[v2431];
    int v2329 = v2325[v2418];
    int v2330 = v2327[v2418];
    bool v2433 = !(((~(((v2310 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2310 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v2384;
    if (v2433) {
      int * v2331 = v2302->cache_age;
      int v2435 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))) | (-(v2311 ^ ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2332 = v2331[v2435];
      int v2333 = v2331[v2419];
      int v2436 = v2333 + ((int)((unsigned int)(v2333 - v2332) >> 31));
      v2331[v2419] = v2436;
      int * v2335 = v2302->cache_age;
      int v2336 = v2335[v2420];
      int v2438 = v2336 + ((int)((unsigned int)(v2336 - v2332) >> 31));
      v2335[v2420] = v2438;
      int * v2338 = v2302->cache_age;
      v2338[v2435] = 0;
      v2384 = v2435;
    } else {
      int * v2341 = v2302->cache_age;
      int v2442 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2);
      int v2342 = v2341[v2442];
      int * v2343 = v2302->cache_tags;
      int v2344 = v2343[v2442];
      int v2345 = v2341[v2420];
      int v2346 = v2343[v2420];
      int * v2347 = v2302->cache_dirty;
      int v2445 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2342 + ((~(((v2344 ^ -1) | (-(v2344 ^ -1))) >> 31)) & 2)) - (v2345 + ((~(((v2346 ^ -1) | (-(v2346 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2348 = v2347[v2445];
      bool v2446 = !(v2348 == 0);
      if (v2446) {
        int * v2349 = v2302->cache_tags;
        int v2350 = v2349[v2445];
        int * v2351 = v2302->cache_vals;
        int v2449 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2342 + ((~(((v2344 ^ -1) | (-(v2344 ^ -1))) >> 31)) & 2)) - (v2345 + ((~(((v2346 ^ -1) | (-(v2346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2352 = v2351[v2449];
        int v2450 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2342 + ((~(((v2344 ^ -1) | (-(v2344 ^ -1))) >> 31)) & 2)) - (v2345 + ((~(((v2346 ^ -1) | (-(v2346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2353 = v2351[v2450];
        int * v2354 = v2302->mem;
        int v2452 = v2350 * 2;
        v2354[v2452] = v2352;
        int * v2356 = v2302->mem;
        int v2455 = (v2350 * 2) + 1;
        v2356[v2455] = v2353;
        ;
      } else {
        ;
      }
      int * v2361 = v2302->mem;
      int v2460 = ((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) * 2;
      int v2362 = v2361[v2460];
      int v2461 = (((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) * 2) + 1;
      int v2363 = v2361[v2461];
      int * v2364 = v2302->cache_vals;
      int v2463 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2342 + ((~(((v2344 ^ -1) | (-(v2344 ^ -1))) >> 31)) & 2)) - (v2345 + ((~(((v2346 ^ -1) | (-(v2346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2364[v2463] = v2362;
      int * v2366 = v2302->cache_vals;
      int v2466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2342 + ((~(((v2344 ^ -1) | (-(v2344 ^ -1))) >> 31)) & 2)) - (v2345 + ((~(((v2346 ^ -1) | (-(v2346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2366[v2466] = v2363;
      int * v2368 = v2302->cache_tags;
      int v2469 = (int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1);
      v2368[v2445] = v2469;
      int * v2370 = v2302->cache_dirty;
      v2370[v2445] = 0;
      int * v2372 = v2302->cache_age;
      v2372[v2445] = 1;
      int * v2374 = v2302->cache_age;
      int v2375 = v2374[v2445];
      int v2376 = v2374[v2419];
      int v2475 = v2376 + ((int)((unsigned int)(v2376 - v2375) >> 31));
      v2374[v2419] = v2475;
      int * v2378 = v2302->cache_age;
      int v2379 = v2378[v2420];
      int v2477 = v2379 + ((int)((unsigned int)(v2379 - v2375) >> 31));
      v2378[v2420] = v2477;
      int * v2381 = v2302->cache_age;
      v2381[v2445] = 0;
      v2384 = v2445;
    }
    int * v2385 = v2302->cache_vals;
    int v2480 = v2384 * 2;
    int v2386 = v2385[v2480];
    int v2481 = (v2384 * 2) + 1;
    int v2387 = v2385[v2481];
    int v2482 = (((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2326 + ((~(((v2328 ^ -1) | (-(v2328 ^ -1))) >> 31)) & 2)) - (v2329 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2385[v2482] = v2386;
    int * v2389 = v2302->cache_vals;
    int v2485 = ((((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2326 + ((~(((v2328 ^ -1) | (-(v2328 ^ -1))) >> 31)) & 2)) - (v2329 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2389[v2485] = v2387;
    int * v2391 = v2302->cache_tags;
    int v2488 = ((((int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2326 + ((~(((v2328 ^ -1) | (-(v2328 ^ -1))) >> 31)) & 2)) - (v2329 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2489 = (int)((unsigned int)((int)((unsigned int)(v2306 + 12) >> 2)) >> 1);
    v2391[v2488] = v2489;
    int * v2393 = v2302->cache_dirty;
    v2393[v2488] = 0;
    int * v2395 = v2302->cache_age;
    v2395[v2488] = 1;
    int * v2397 = v2302->cache_age;
    int v2398 = v2397[v2488];
    int v2399 = v2397[v2417];
    int v2495 = v2399 + ((int)((unsigned int)(v2399 - v2398) >> 31));
    v2397[v2417] = v2495;
    int * v2401 = v2302->cache_age;
    int v2402 = v2401[v2418];
    int v2497 = v2402 + ((int)((unsigned int)(v2402 - v2398) >> 31));
    v2401[v2418] = v2497;
    int * v2404 = v2302->cache_age;
    v2404[v2488] = 0;
    v2407 = v2488;
  }
  int v2500 = (v2407 * 2) + (((int)((unsigned int)(v2306 + 12) >> 2)) & 1);
  int v2408 = v2314[v2500];
  int * v2409 = v2302->regs;
  v2409[14] = v2408;
  struct StateT * v2411 = slot_24(v2302);
  return v2411;
}

struct StateT * slot_2(struct StateT * v410) {
  int v411 = v410->timer;
  int v521 = v411 + 1;
  v410->timer = v521;
  int * v413 = v410->regs;
  int v414 = v413[10];
  int * v415 = v410->cache_tags;
  int v525 = (((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2;
  int v416 = v415[v525];
  int v526 = ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2) + 1;
  int v417 = v415[v526];
  int v527 = 4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2);
  int v418 = v415[v527];
  int v528 = (4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v419 = v415[v528];
  int v420 = v410->timer;
  int v529 = v420 + ((100 ^ (((~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) | (~(((v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) | (~(((v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31))) & 104)))));
  v410->timer = v529;
  int * v422 = v410->cache_vals;
  bool v530 = !(((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) | (~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31))) == 0);
  int v515;
  if (v530) {
    int * v423 = v410->cache_age;
    int v532 = ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2) + ((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) & 1);
    int v424 = v423[v532];
    int v425 = v423[v525];
    int v533 = v425 + ((int)((unsigned int)(v425 - v424) >> 31));
    v423[v525] = v533;
    int * v427 = v410->cache_age;
    int v428 = v427[v526];
    int v535 = v428 + ((int)((unsigned int)(v428 - v424) >> 31));
    v427[v526] = v535;
    int * v430 = v410->cache_age;
    v430[v532] = 0;
    v515 = v532;
  } else {
    int * v433 = v410->cache_age;
    int v539 = (((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2;
    int v434 = v433[v539];
    int * v435 = v410->cache_tags;
    int v436 = v435[v539];
    int v437 = v433[v526];
    int v438 = v435[v526];
    bool v541 = !(((~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) | (~(((v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31))) == 0);
    int v492;
    if (v541) {
      int * v439 = v410->cache_age;
      int v543 = (4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + ((~(((v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))) | (-(v419 ^ ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1))))) >> 31)) & 1);
      int v440 = v439[v543];
      int v441 = v439[v527];
      int v544 = v441 + ((int)((unsigned int)(v441 - v440) >> 31));
      v439[v527] = v544;
      int * v443 = v410->cache_age;
      int v444 = v443[v528];
      int v546 = v444 + ((int)((unsigned int)(v444 - v440) >> 31));
      v443[v528] = v546;
      int * v446 = v410->cache_age;
      v446[v543] = 0;
      v492 = v543;
    } else {
      int * v449 = v410->cache_age;
      int v550 = 4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2);
      int v450 = v449[v550];
      int * v451 = v410->cache_tags;
      int v452 = v451[v550];
      int v453 = v449[v528];
      int v454 = v451[v528];
      int * v455 = v410->cache_dirty;
      int v553 = (4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v456 = v455[v553];
      bool v554 = !(v456 == 0);
      if (v554) {
        int * v457 = v410->cache_tags;
        int v458 = v457[v553];
        int * v459 = v410->cache_vals;
        int v557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v460 = v459[v557];
        int v558 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v461 = v459[v558];
        int * v462 = v410->mem;
        int v560 = v458 * 2;
        v462[v560] = v460;
        int * v464 = v410->mem;
        int v563 = (v458 * 2) + 1;
        v464[v563] = v461;
        ;
      } else {
        ;
      }
      int * v469 = v410->mem;
      int v568 = ((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) * 2;
      int v470 = v469[v568];
      int v569 = (((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) * 2) + 1;
      int v471 = v469[v569];
      int * v472 = v410->cache_vals;
      int v571 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v472[v571] = v470;
      int * v474 = v410->cache_vals;
      int v574 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 3) * 2)) + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v474[v574] = v471;
      int * v476 = v410->cache_tags;
      int v577 = (int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1);
      v476[v553] = v577;
      int * v478 = v410->cache_dirty;
      v478[v553] = 0;
      int * v480 = v410->cache_age;
      v480[v553] = 1;
      int * v482 = v410->cache_age;
      int v483 = v482[v553];
      int v484 = v482[v527];
      int v583 = v484 + ((int)((unsigned int)(v484 - v483) >> 31));
      v482[v527] = v583;
      int * v486 = v410->cache_age;
      int v487 = v486[v528];
      int v585 = v487 + ((int)((unsigned int)(v487 - v483) >> 31));
      v486[v528] = v585;
      int * v489 = v410->cache_age;
      v489[v553] = 0;
      v492 = v553;
    }
    int * v493 = v410->cache_vals;
    int v588 = v492 * 2;
    int v494 = v493[v588];
    int v589 = (v492 * 2) + 1;
    int v495 = v493[v589];
    int v590 = (((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2) + ((((v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v493[v590] = v494;
    int * v497 = v410->cache_vals;
    int v593 = ((((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2) + ((((v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v497[v593] = v495;
    int * v499 = v410->cache_tags;
    int v596 = ((((int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1)) & 1) * 2) + ((((v434 + ((~(((v436 ^ -1) | (-(v436 ^ -1))) >> 31)) & 2)) - (v437 + ((~(((v438 ^ -1) | (-(v438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v597 = (int)((unsigned int)((int)((unsigned int)v414 >> 2)) >> 1);
    v499[v596] = v597;
    int * v501 = v410->cache_dirty;
    v501[v596] = 0;
    int * v503 = v410->cache_age;
    v503[v596] = 1;
    int * v505 = v410->cache_age;
    int v506 = v505[v596];
    int v507 = v505[v525];
    int v603 = v507 + ((int)((unsigned int)(v507 - v506) >> 31));
    v505[v525] = v603;
    int * v509 = v410->cache_age;
    int v510 = v509[v526];
    int v605 = v510 + ((int)((unsigned int)(v510 - v506) >> 31));
    v509[v526] = v605;
    int * v512 = v410->cache_age;
    v512[v596] = 0;
    v515 = v596;
  }
  int v608 = (v515 * 2) + (((int)((unsigned int)v414 >> 2)) & 1);
  int v516 = v422[v608];
  int * v517 = v410->regs;
  v517[14] = v516;
  struct StateT * v519 = slot_3(v410);
  return v519;
}

struct StateT * slot_21(struct StateT * v1783) {
  int v1784 = v1783->timer;
  int v1954 = v1784 + 1;
  v1783->timer = v1954;
  int * v1786 = v1783->regs;
  int v1787 = v1786[10];
  int v1788 = v1786[13];
  int * v1789 = v1783->cache_tags;
  int v1959 = (((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1790 = v1789[v1959];
  int v1960 = ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1791 = v1789[v1960];
  int v1961 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1792 = v1789[v1961];
  int v1962 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1793 = v1789[v1962];
  int v1794 = v1783->timer;
  int v1963 = v1794 + ((100 ^ (((~(((v1792 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1792 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1790 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1790 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1791 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1791 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1792 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1792 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1783->timer = v1963;
  bool v1964 = !(((~(((v1790 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1790 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1791 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1791 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1888;
  if (v1964) {
    int * v1796 = v1783->cache_age;
    int v1966 = ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1791 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1791 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1797 = v1796[v1966];
    int v1798 = v1796[v1959];
    int v1967 = v1798 + ((int)((unsigned int)(v1798 - v1797) >> 31));
    v1796[v1959] = v1967;
    int * v1800 = v1783->cache_age;
    int v1801 = v1800[v1960];
    int v1969 = v1801 + ((int)((unsigned int)(v1801 - v1797) >> 31));
    v1800[v1960] = v1969;
    int * v1803 = v1783->cache_age;
    v1803[v1966] = 0;
    v1888 = v1966;
  } else {
    int * v1806 = v1783->cache_age;
    int v1973 = (((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1807 = v1806[v1973];
    int * v1808 = v1783->cache_tags;
    int v1809 = v1808[v1973];
    int v1810 = v1806[v1960];
    int v1811 = v1808[v1960];
    bool v1975 = !(((~(((v1792 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1792 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1865;
    if (v1975) {
      int * v1812 = v1783->cache_age;
      int v1977 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1793 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1813 = v1812[v1977];
      int v1814 = v1812[v1961];
      int v1978 = v1814 + ((int)((unsigned int)(v1814 - v1813) >> 31));
      v1812[v1961] = v1978;
      int * v1816 = v1783->cache_age;
      int v1817 = v1816[v1962];
      int v1980 = v1817 + ((int)((unsigned int)(v1817 - v1813) >> 31));
      v1816[v1962] = v1980;
      int * v1819 = v1783->cache_age;
      v1819[v1977] = 0;
      v1865 = v1977;
    } else {
      int * v1822 = v1783->cache_age;
      int v1984 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1823 = v1822[v1984];
      int * v1824 = v1783->cache_tags;
      int v1825 = v1824[v1984];
      int v1826 = v1822[v1962];
      int v1827 = v1824[v1962];
      int * v1828 = v1783->cache_dirty;
      int v1987 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1823 + ((~(((v1825 ^ -1) | (-(v1825 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1827 ^ -1) | (-(v1827 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1829 = v1828[v1987];
      bool v1988 = !(v1829 == 0);
      if (v1988) {
        int * v1830 = v1783->cache_tags;
        int v1831 = v1830[v1987];
        int * v1832 = v1783->cache_vals;
        int v1991 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1823 + ((~(((v1825 ^ -1) | (-(v1825 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1827 ^ -1) | (-(v1827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1833 = v1832[v1991];
        int v1992 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1823 + ((~(((v1825 ^ -1) | (-(v1825 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1827 ^ -1) | (-(v1827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1834 = v1832[v1992];
        int * v1835 = v1783->mem;
        int v1994 = v1831 * 2;
        v1835[v1994] = v1833;
        int * v1837 = v1783->mem;
        int v1997 = (v1831 * 2) + 1;
        v1837[v1997] = v1834;
        ;
      } else {
        ;
      }
      int * v1842 = v1783->mem;
      int v2002 = ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) * 2;
      int v1843 = v1842[v2002];
      int v2003 = (((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1844 = v1842[v2003];
      int * v1845 = v1783->cache_vals;
      int v2005 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1823 + ((~(((v1825 ^ -1) | (-(v1825 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1827 ^ -1) | (-(v1827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1845[v2005] = v1843;
      int * v1847 = v1783->cache_vals;
      int v2008 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1823 + ((~(((v1825 ^ -1) | (-(v1825 ^ -1))) >> 31)) & 2)) - (v1826 + ((~(((v1827 ^ -1) | (-(v1827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1847[v2008] = v1844;
      int * v1849 = v1783->cache_tags;
      int v2011 = (int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1);
      v1849[v1987] = v2011;
      int * v1851 = v1783->cache_dirty;
      v1851[v1987] = 0;
      int * v1853 = v1783->cache_age;
      v1853[v1987] = 1;
      int * v1855 = v1783->cache_age;
      int v1856 = v1855[v1987];
      int v1857 = v1855[v1961];
      int v2017 = v1857 + ((int)((unsigned int)(v1857 - v1856) >> 31));
      v1855[v1961] = v2017;
      int * v1859 = v1783->cache_age;
      int v1860 = v1859[v1962];
      int v2019 = v1860 + ((int)((unsigned int)(v1860 - v1856) >> 31));
      v1859[v1962] = v2019;
      int * v1862 = v1783->cache_age;
      v1862[v1987] = 0;
      v1865 = v1987;
    }
    int * v1866 = v1783->cache_vals;
    int v2022 = v1865 * 2;
    int v1867 = v1866[v2022];
    int v2023 = (v1865 * 2) + 1;
    int v1868 = v1866[v2023];
    int v2024 = (((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1866[v2024] = v1867;
    int * v1870 = v1783->cache_vals;
    int v2027 = ((((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1870[v2027] = v1868;
    int * v1872 = v1783->cache_tags;
    int v2030 = ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1807 + ((~(((v1809 ^ -1) | (-(v1809 ^ -1))) >> 31)) & 2)) - (v1810 + ((~(((v1811 ^ -1) | (-(v1811 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2031 = (int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1);
    v1872[v2030] = v2031;
    int * v1874 = v1783->cache_dirty;
    v1874[v2030] = 0;
    int * v1876 = v1783->cache_age;
    v1876[v2030] = 1;
    int * v1878 = v1783->cache_age;
    int v1879 = v1878[v2030];
    int v1880 = v1878[v1959];
    int v2037 = v1880 + ((int)((unsigned int)(v1880 - v1879) >> 31));
    v1878[v1959] = v2037;
    int * v1882 = v1783->cache_age;
    int v1883 = v1882[v1960];
    int v2039 = v1883 + ((int)((unsigned int)(v1883 - v1879) >> 31));
    v1882[v1960] = v2039;
    int * v1885 = v1783->cache_age;
    v1885[v2030] = 0;
    v1888 = v2030;
  }
  int * v1889 = v1783->cache_vals;
  int v2042 = (v1888 * 2) + (((int)((unsigned int)(v1787 + 4) >> 2)) & 1);
  v1889[v2042] = v1788;
  int * v1891 = v1783->cache_tags;
  int v1892 = v1891[v1961];
  int v1893 = v1891[v1962];
  bool v2045 = !(((~(((v1892 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1892 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1893 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1893 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1947;
  if (v2045) {
    int * v1894 = v1783->cache_age;
    int v2047 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1893 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))) | (-(v1893 ^ ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1895 = v1894[v2047];
    int v1896 = v1894[v1961];
    int v2048 = v1896 + ((int)((unsigned int)(v1896 - v1895) >> 31));
    v1894[v1961] = v2048;
    int * v1898 = v1783->cache_age;
    int v1899 = v1898[v1962];
    int v2050 = v1899 + ((int)((unsigned int)(v1899 - v1895) >> 31));
    v1898[v1962] = v2050;
    int * v1901 = v1783->cache_age;
    v1901[v2047] = 0;
    v1947 = v2047;
  } else {
    int * v1904 = v1783->cache_age;
    int v2054 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2);
    int v1905 = v1904[v2054];
    int * v1906 = v1783->cache_tags;
    int v1907 = v1906[v2054];
    int v1908 = v1904[v1962];
    int v1909 = v1906[v1962];
    int * v1910 = v1783->cache_dirty;
    int v2057 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1905 + ((~(((v1907 ^ -1) | (-(v1907 ^ -1))) >> 31)) & 2)) - (v1908 + ((~(((v1909 ^ -1) | (-(v1909 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1911 = v1910[v2057];
    bool v2058 = !(v1911 == 0);
    if (v2058) {
      int * v1912 = v1783->cache_tags;
      int v1913 = v1912[v2057];
      int * v1914 = v1783->cache_vals;
      int v2061 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1905 + ((~(((v1907 ^ -1) | (-(v1907 ^ -1))) >> 31)) & 2)) - (v1908 + ((~(((v1909 ^ -1) | (-(v1909 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1915 = v1914[v2061];
      int v2062 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1905 + ((~(((v1907 ^ -1) | (-(v1907 ^ -1))) >> 31)) & 2)) - (v1908 + ((~(((v1909 ^ -1) | (-(v1909 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1916 = v1914[v2062];
      int * v1917 = v1783->mem;
      int v2064 = v1913 * 2;
      v1917[v2064] = v1915;
      int * v1919 = v1783->mem;
      int v2067 = (v1913 * 2) + 1;
      v1919[v2067] = v1916;
      ;
    } else {
      ;
    }
    int * v1924 = v1783->mem;
    int v2072 = ((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) * 2;
    int v1925 = v1924[v2072];
    int v2073 = (((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) * 2) + 1;
    int v1926 = v1924[v2073];
    int * v1927 = v1783->cache_vals;
    int v2075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1905 + ((~(((v1907 ^ -1) | (-(v1907 ^ -1))) >> 31)) & 2)) - (v1908 + ((~(((v1909 ^ -1) | (-(v1909 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1927[v2075] = v1925;
    int * v1929 = v1783->cache_vals;
    int v2078 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1905 + ((~(((v1907 ^ -1) | (-(v1907 ^ -1))) >> 31)) & 2)) - (v1908 + ((~(((v1909 ^ -1) | (-(v1909 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1929[v2078] = v1926;
    int * v1931 = v1783->cache_tags;
    int v2081 = (int)((unsigned int)((int)((unsigned int)(v1787 + 4) >> 2)) >> 1);
    v1931[v2057] = v2081;
    int * v1933 = v1783->cache_dirty;
    v1933[v2057] = 0;
    int * v1935 = v1783->cache_age;
    v1935[v2057] = 1;
    int * v1937 = v1783->cache_age;
    int v1938 = v1937[v2057];
    int v1939 = v1937[v1961];
    int v2087 = v1939 + ((int)((unsigned int)(v1939 - v1938) >> 31));
    v1937[v1961] = v2087;
    int * v1941 = v1783->cache_age;
    int v1942 = v1941[v1962];
    int v2089 = v1942 + ((int)((unsigned int)(v1942 - v1938) >> 31));
    v1941[v1962] = v2089;
    int * v1944 = v1783->cache_age;
    v1944[v2057] = 0;
    v1947 = v2057;
  }
  int * v1948 = v1783->cache_vals;
  int v2092 = (v1947 * 2) + (((int)((unsigned int)(v1787 + 4) >> 2)) & 1);
  v1948[v2092] = v1788;
  int * v1950 = v1783->cache_dirty;
  v1950[v1947] = 1;
  struct StateT * v1952 = slot_22(v1783);
  return v1952;
}

struct StateT * slot_3(struct StateT * v614) {
  int v615 = v614->timer;
  int v725 = v615 + 1;
  v614->timer = v725;
  int * v617 = v614->regs;
  int v618 = v617[10];
  int * v619 = v614->cache_tags;
  int v729 = (((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2;
  int v620 = v619[v729];
  int v730 = ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v621 = v619[v730];
  int v731 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2);
  int v622 = v619[v731];
  int v732 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v623 = v619[v732];
  int v624 = v614->timer;
  int v733 = v624 + ((100 ^ (((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v614->timer = v733;
  int * v626 = v614->cache_vals;
  bool v734 = !(((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v719;
  if (v734) {
    int * v627 = v614->cache_age;
    int v736 = ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v628 = v627[v736];
    int v629 = v627[v729];
    int v737 = v629 + ((int)((unsigned int)(v629 - v628) >> 31));
    v627[v729] = v737;
    int * v631 = v614->cache_age;
    int v632 = v631[v730];
    int v739 = v632 + ((int)((unsigned int)(v632 - v628) >> 31));
    v631[v730] = v739;
    int * v634 = v614->cache_age;
    v634[v736] = 0;
    v719 = v736;
  } else {
    int * v637 = v614->cache_age;
    int v743 = (((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2;
    int v638 = v637[v743];
    int * v639 = v614->cache_tags;
    int v640 = v639[v743];
    int v641 = v637[v730];
    int v642 = v639[v730];
    bool v745 = !(((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v696;
    if (v745) {
      int * v643 = v614->cache_age;
      int v747 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v644 = v643[v747];
      int v645 = v643[v731];
      int v748 = v645 + ((int)((unsigned int)(v645 - v644) >> 31));
      v643[v731] = v748;
      int * v647 = v614->cache_age;
      int v648 = v647[v732];
      int v750 = v648 + ((int)((unsigned int)(v648 - v644) >> 31));
      v647[v732] = v750;
      int * v650 = v614->cache_age;
      v650[v747] = 0;
      v696 = v747;
    } else {
      int * v653 = v614->cache_age;
      int v754 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2);
      int v654 = v653[v754];
      int * v655 = v614->cache_tags;
      int v656 = v655[v754];
      int v657 = v653[v732];
      int v658 = v655[v732];
      int * v659 = v614->cache_dirty;
      int v757 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v660 = v659[v757];
      bool v758 = !(v660 == 0);
      if (v758) {
        int * v661 = v614->cache_tags;
        int v662 = v661[v757];
        int * v663 = v614->cache_vals;
        int v761 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v664 = v663[v761];
        int v762 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v665 = v663[v762];
        int * v666 = v614->mem;
        int v764 = v662 * 2;
        v666[v764] = v664;
        int * v668 = v614->mem;
        int v767 = (v662 * 2) + 1;
        v668[v767] = v665;
        ;
      } else {
        ;
      }
      int * v673 = v614->mem;
      int v772 = ((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) * 2;
      int v674 = v673[v772];
      int v773 = (((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) * 2) + 1;
      int v675 = v673[v773];
      int * v676 = v614->cache_vals;
      int v775 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v676[v775] = v674;
      int * v678 = v614->cache_vals;
      int v778 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v678[v778] = v675;
      int * v680 = v614->cache_tags;
      int v781 = (int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1);
      v680[v757] = v781;
      int * v682 = v614->cache_dirty;
      v682[v757] = 0;
      int * v684 = v614->cache_age;
      v684[v757] = 1;
      int * v686 = v614->cache_age;
      int v687 = v686[v757];
      int v688 = v686[v731];
      int v787 = v688 + ((int)((unsigned int)(v688 - v687) >> 31));
      v686[v731] = v787;
      int * v690 = v614->cache_age;
      int v691 = v690[v732];
      int v789 = v691 + ((int)((unsigned int)(v691 - v687) >> 31));
      v690[v732] = v789;
      int * v693 = v614->cache_age;
      v693[v757] = 0;
      v696 = v757;
    }
    int * v697 = v614->cache_vals;
    int v792 = v696 * 2;
    int v698 = v697[v792];
    int v793 = (v696 * 2) + 1;
    int v699 = v697[v793];
    int v794 = (((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v697[v794] = v698;
    int * v701 = v614->cache_vals;
    int v797 = ((((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v701[v797] = v699;
    int * v703 = v614->cache_tags;
    int v800 = ((((int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v801 = (int)((unsigned int)((int)((unsigned int)(v618 + 4) >> 2)) >> 1);
    v703[v800] = v801;
    int * v705 = v614->cache_dirty;
    v705[v800] = 0;
    int * v707 = v614->cache_age;
    v707[v800] = 1;
    int * v709 = v614->cache_age;
    int v710 = v709[v800];
    int v711 = v709[v729];
    int v807 = v711 + ((int)((unsigned int)(v711 - v710) >> 31));
    v709[v729] = v807;
    int * v713 = v614->cache_age;
    int v714 = v713[v730];
    int v809 = v714 + ((int)((unsigned int)(v714 - v710) >> 31));
    v713[v730] = v809;
    int * v716 = v614->cache_age;
    v716[v800] = 0;
    v719 = v800;
  }
  int v812 = (v719 * 2) + (((int)((unsigned int)(v618 + 4) >> 2)) & 1);
  int v720 = v626[v812];
  int * v721 = v614->regs;
  v721[15] = v720;
  struct StateT * v723 = slot_4(v614);
  return v723;
}

struct StateT * slot_45(struct StateT * v4600) {
  int v4601 = v4600->timer;
  int v4609 = v4601 + 1;
  v4600->timer = v4609;
  int * v4603 = v4600->regs;
  int v4604 = v4603[6];
  int v4605 = v4603[15];
  int v4613 = v4604 - v4605;
  v4603[15] = v4613;
  struct StateT * v4607 = slot_46(v4600);
  return v4607;
}

struct StateT * slot_73(struct StateT * v7404) {
  int v7405 = v7404->timer;
  int v7413 = v7405 + 1;
  v7404->timer = v7413;
  int * v7407 = v7404->regs;
  int v7408 = v7407[11];
  int v7409 = v7407[13];
  int v7417 = v7408 - v7409;
  v7407[11] = v7417;
  struct StateT * v7411 = slot_74(v7404);
  return v7411;
}

struct StateT * slot_1(struct StateT * v206) {
  int v207 = v206->timer;
  int v317 = v207 + 1;
  v206->timer = v317;
  int * v209 = v206->regs;
  int v210 = v209[11];
  int * v211 = v206->cache_tags;
  int v321 = (((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2;
  int v212 = v211[v321];
  int v322 = ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v213 = v211[v322];
  int v323 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2);
  int v214 = v211[v323];
  int v324 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v215 = v211[v324];
  int v216 = v206->timer;
  int v325 = v216 + ((100 ^ (((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v206->timer = v325;
  int * v218 = v206->cache_vals;
  bool v326 = !(((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v311;
  if (v326) {
    int * v219 = v206->cache_age;
    int v328 = ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v220 = v219[v328];
    int v221 = v219[v321];
    int v329 = v221 + ((int)((unsigned int)(v221 - v220) >> 31));
    v219[v321] = v329;
    int * v223 = v206->cache_age;
    int v224 = v223[v322];
    int v331 = v224 + ((int)((unsigned int)(v224 - v220) >> 31));
    v223[v322] = v331;
    int * v226 = v206->cache_age;
    v226[v328] = 0;
    v311 = v328;
  } else {
    int * v229 = v206->cache_age;
    int v335 = (((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2;
    int v230 = v229[v335];
    int * v231 = v206->cache_tags;
    int v232 = v231[v335];
    int v233 = v229[v322];
    int v234 = v231[v322];
    bool v337 = !(((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v288;
    if (v337) {
      int * v235 = v206->cache_age;
      int v339 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))) | (-(v215 ^ ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v236 = v235[v339];
      int v237 = v235[v323];
      int v340 = v237 + ((int)((unsigned int)(v237 - v236) >> 31));
      v235[v323] = v340;
      int * v239 = v206->cache_age;
      int v240 = v239[v324];
      int v342 = v240 + ((int)((unsigned int)(v240 - v236) >> 31));
      v239[v324] = v342;
      int * v242 = v206->cache_age;
      v242[v339] = 0;
      v288 = v339;
    } else {
      int * v245 = v206->cache_age;
      int v346 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2);
      int v246 = v245[v346];
      int * v247 = v206->cache_tags;
      int v248 = v247[v346];
      int v249 = v245[v324];
      int v250 = v247[v324];
      int * v251 = v206->cache_dirty;
      int v349 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v252 = v251[v349];
      bool v350 = !(v252 == 0);
      if (v350) {
        int * v253 = v206->cache_tags;
        int v254 = v253[v349];
        int * v255 = v206->cache_vals;
        int v353 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v256 = v255[v353];
        int v354 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v257 = v255[v354];
        int * v258 = v206->mem;
        int v356 = v254 * 2;
        v258[v356] = v256;
        int * v260 = v206->mem;
        int v359 = (v254 * 2) + 1;
        v260[v359] = v257;
        ;
      } else {
        ;
      }
      int * v265 = v206->mem;
      int v364 = ((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) * 2;
      int v266 = v265[v364];
      int v365 = (((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) * 2) + 1;
      int v267 = v265[v365];
      int * v268 = v206->cache_vals;
      int v367 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v268[v367] = v266;
      int * v270 = v206->cache_vals;
      int v370 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v246 + ((~(((v248 ^ -1) | (-(v248 ^ -1))) >> 31)) & 2)) - (v249 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v270[v370] = v267;
      int * v272 = v206->cache_tags;
      int v373 = (int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1);
      v272[v349] = v373;
      int * v274 = v206->cache_dirty;
      v274[v349] = 0;
      int * v276 = v206->cache_age;
      v276[v349] = 1;
      int * v278 = v206->cache_age;
      int v279 = v278[v349];
      int v280 = v278[v323];
      int v379 = v280 + ((int)((unsigned int)(v280 - v279) >> 31));
      v278[v323] = v379;
      int * v282 = v206->cache_age;
      int v283 = v282[v324];
      int v381 = v283 + ((int)((unsigned int)(v283 - v279) >> 31));
      v282[v324] = v381;
      int * v285 = v206->cache_age;
      v285[v349] = 0;
      v288 = v349;
    }
    int * v289 = v206->cache_vals;
    int v384 = v288 * 2;
    int v290 = v289[v384];
    int v385 = (v288 * 2) + 1;
    int v291 = v289[v385];
    int v386 = (((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v289[v386] = v290;
    int * v293 = v206->cache_vals;
    int v389 = ((((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v293[v389] = v291;
    int * v295 = v206->cache_tags;
    int v392 = ((((int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v230 + ((~(((v232 ^ -1) | (-(v232 ^ -1))) >> 31)) & 2)) - (v233 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v393 = (int)((unsigned int)((int)((unsigned int)(v210 + 4) >> 2)) >> 1);
    v295[v392] = v393;
    int * v297 = v206->cache_dirty;
    v297[v392] = 0;
    int * v299 = v206->cache_age;
    v299[v392] = 1;
    int * v301 = v206->cache_age;
    int v302 = v301[v392];
    int v303 = v301[v321];
    int v399 = v303 + ((int)((unsigned int)(v303 - v302) >> 31));
    v301[v321] = v399;
    int * v305 = v206->cache_age;
    int v306 = v305[v322];
    int v401 = v306 + ((int)((unsigned int)(v306 - v302) >> 31));
    v305[v322] = v401;
    int * v308 = v206->cache_age;
    v308[v392] = 0;
    v311 = v392;
  }
  int v404 = (v311 * 2) + (((int)((unsigned int)(v210 + 4) >> 2)) & 1);
  int v312 = v218[v404];
  int * v313 = v206->regs;
  v313[13] = v312;
  struct StateT * v315 = slot_2(v206);
  return v315;
}

struct StateT * slot_69(struct StateT * v7331) {
  int v7332 = v7331->timer;
  int v7344 = v7332 + 1;
  v7331->timer = v7344;
  int * v7334 = v7331->regs;
  int v7335 = v7334[16];
  int v7336 = v7334[14];
  bool v7348 = (v7335 ^ -2147483648) < (v7336 ^ -2147483648);
  int v7339;
  if (v7348) {
    v7339 = 1;
  } else {
    v7339 = 0;
  }
  int * v7340 = v7331->regs;
  v7340[13] = v7339;
  struct StateT * v7342 = slot_70(v7331);
  return v7342;
}

struct StateT * slot_13(struct StateT * v1350) {
  int v1351 = v1350->timer;
  int v1359 = v1351 + 1;
  v1350->timer = v1359;
  int * v1353 = v1350->regs;
  int v1354 = v1353[13];
  int v1355 = v1353[15];
  int v1363 = v1354 - v1355;
  v1353[13] = v1363;
  struct StateT * v1357 = slot_14(v1350);
  return v1357;
}

struct StateT * slot_38(struct StateT * v4096) {
  int v4097 = v4096->timer;
  int v4207 = v4097 + 1;
  v4096->timer = v4207;
  int * v4099 = v4096->regs;
  int v4100 = v4099[10];
  int * v4101 = v4096->cache_tags;
  int v4211 = (((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2;
  int v4102 = v4101[v4211];
  int v4212 = ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4103 = v4101[v4212];
  int v4213 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2);
  int v4104 = v4101[v4213];
  int v4214 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4105 = v4101[v4214];
  int v4106 = v4096->timer;
  int v4215 = v4106 + ((100 ^ (((~(((v4104 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4104 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4102 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4102 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4103 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4103 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4104 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4104 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4096->timer = v4215;
  int * v4108 = v4096->cache_vals;
  bool v4216 = !(((~(((v4102 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4102 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4103 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4103 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v4201;
  if (v4216) {
    int * v4109 = v4096->cache_age;
    int v4218 = ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v4103 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4103 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v4110 = v4109[v4218];
    int v4111 = v4109[v4211];
    int v4219 = v4111 + ((int)((unsigned int)(v4111 - v4110) >> 31));
    v4109[v4211] = v4219;
    int * v4113 = v4096->cache_age;
    int v4114 = v4113[v4212];
    int v4221 = v4114 + ((int)((unsigned int)(v4114 - v4110) >> 31));
    v4113[v4212] = v4221;
    int * v4116 = v4096->cache_age;
    v4116[v4218] = 0;
    v4201 = v4218;
  } else {
    int * v4119 = v4096->cache_age;
    int v4225 = (((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2;
    int v4120 = v4119[v4225];
    int * v4121 = v4096->cache_tags;
    int v4122 = v4121[v4225];
    int v4123 = v4119[v4212];
    int v4124 = v4121[v4212];
    bool v4227 = !(((~(((v4104 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4104 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v4178;
    if (v4227) {
      int * v4125 = v4096->cache_age;
      int v4229 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))) | (-(v4105 ^ ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v4126 = v4125[v4229];
      int v4127 = v4125[v4213];
      int v4230 = v4127 + ((int)((unsigned int)(v4127 - v4126) >> 31));
      v4125[v4213] = v4230;
      int * v4129 = v4096->cache_age;
      int v4130 = v4129[v4214];
      int v4232 = v4130 + ((int)((unsigned int)(v4130 - v4126) >> 31));
      v4129[v4214] = v4232;
      int * v4132 = v4096->cache_age;
      v4132[v4229] = 0;
      v4178 = v4229;
    } else {
      int * v4135 = v4096->cache_age;
      int v4236 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2);
      int v4136 = v4135[v4236];
      int * v4137 = v4096->cache_tags;
      int v4138 = v4137[v4236];
      int v4139 = v4135[v4214];
      int v4140 = v4137[v4214];
      int * v4141 = v4096->cache_dirty;
      int v4239 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4136 + ((~(((v4138 ^ -1) | (-(v4138 ^ -1))) >> 31)) & 2)) - (v4139 + ((~(((v4140 ^ -1) | (-(v4140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4142 = v4141[v4239];
      bool v4240 = !(v4142 == 0);
      if (v4240) {
        int * v4143 = v4096->cache_tags;
        int v4144 = v4143[v4239];
        int * v4145 = v4096->cache_vals;
        int v4243 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4136 + ((~(((v4138 ^ -1) | (-(v4138 ^ -1))) >> 31)) & 2)) - (v4139 + ((~(((v4140 ^ -1) | (-(v4140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4146 = v4145[v4243];
        int v4244 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4136 + ((~(((v4138 ^ -1) | (-(v4138 ^ -1))) >> 31)) & 2)) - (v4139 + ((~(((v4140 ^ -1) | (-(v4140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4147 = v4145[v4244];
        int * v4148 = v4096->mem;
        int v4246 = v4144 * 2;
        v4148[v4246] = v4146;
        int * v4150 = v4096->mem;
        int v4249 = (v4144 * 2) + 1;
        v4150[v4249] = v4147;
        ;
      } else {
        ;
      }
      int * v4155 = v4096->mem;
      int v4254 = ((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) * 2;
      int v4156 = v4155[v4254];
      int v4255 = (((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) * 2) + 1;
      int v4157 = v4155[v4255];
      int * v4158 = v4096->cache_vals;
      int v4257 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4136 + ((~(((v4138 ^ -1) | (-(v4138 ^ -1))) >> 31)) & 2)) - (v4139 + ((~(((v4140 ^ -1) | (-(v4140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4158[v4257] = v4156;
      int * v4160 = v4096->cache_vals;
      int v4260 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4136 + ((~(((v4138 ^ -1) | (-(v4138 ^ -1))) >> 31)) & 2)) - (v4139 + ((~(((v4140 ^ -1) | (-(v4140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4160[v4260] = v4157;
      int * v4162 = v4096->cache_tags;
      int v4263 = (int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1);
      v4162[v4239] = v4263;
      int * v4164 = v4096->cache_dirty;
      v4164[v4239] = 0;
      int * v4166 = v4096->cache_age;
      v4166[v4239] = 1;
      int * v4168 = v4096->cache_age;
      int v4169 = v4168[v4239];
      int v4170 = v4168[v4213];
      int v4269 = v4170 + ((int)((unsigned int)(v4170 - v4169) >> 31));
      v4168[v4213] = v4269;
      int * v4172 = v4096->cache_age;
      int v4173 = v4172[v4214];
      int v4271 = v4173 + ((int)((unsigned int)(v4173 - v4169) >> 31));
      v4172[v4214] = v4271;
      int * v4175 = v4096->cache_age;
      v4175[v4239] = 0;
      v4178 = v4239;
    }
    int * v4179 = v4096->cache_vals;
    int v4274 = v4178 * 2;
    int v4180 = v4179[v4274];
    int v4275 = (v4178 * 2) + 1;
    int v4181 = v4179[v4275];
    int v4276 = (((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4120 + ((~(((v4122 ^ -1) | (-(v4122 ^ -1))) >> 31)) & 2)) - (v4123 + ((~(((v4124 ^ -1) | (-(v4124 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4179[v4276] = v4180;
    int * v4183 = v4096->cache_vals;
    int v4279 = ((((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4120 + ((~(((v4122 ^ -1) | (-(v4122 ^ -1))) >> 31)) & 2)) - (v4123 + ((~(((v4124 ^ -1) | (-(v4124 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4183[v4279] = v4181;
    int * v4185 = v4096->cache_tags;
    int v4282 = ((((int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4120 + ((~(((v4122 ^ -1) | (-(v4122 ^ -1))) >> 31)) & 2)) - (v4123 + ((~(((v4124 ^ -1) | (-(v4124 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4283 = (int)((unsigned int)((int)((unsigned int)(v4100 + 24) >> 2)) >> 1);
    v4185[v4282] = v4283;
    int * v4187 = v4096->cache_dirty;
    v4187[v4282] = 0;
    int * v4189 = v4096->cache_age;
    v4189[v4282] = 1;
    int * v4191 = v4096->cache_age;
    int v4192 = v4191[v4282];
    int v4193 = v4191[v4211];
    int v4289 = v4193 + ((int)((unsigned int)(v4193 - v4192) >> 31));
    v4191[v4211] = v4289;
    int * v4195 = v4096->cache_age;
    int v4196 = v4195[v4212];
    int v4291 = v4196 + ((int)((unsigned int)(v4196 - v4192) >> 31));
    v4195[v4212] = v4291;
    int * v4198 = v4096->cache_age;
    v4198[v4282] = 0;
    v4201 = v4282;
  }
  int v4294 = (v4201 * 2) + (((int)((unsigned int)(v4100 + 24) >> 2)) & 1);
  int v4202 = v4108[v4294];
  int * v4203 = v4096->regs;
  v4203[17] = v4202;
  struct StateT * v4205 = slot_39(v4096);
  return v4205;
}

struct StateT * slot_63(struct StateT * v6664) {
  int v6665 = v6664->timer;
  int v6775 = v6665 + 1;
  v6664->timer = v6775;
  int * v6667 = v6664->regs;
  int v6668 = v6667[11];
  int * v6669 = v6664->cache_tags;
  int v6779 = (((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2;
  int v6670 = v6669[v6779];
  int v6780 = ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6671 = v6669[v6780];
  int v6781 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2);
  int v6672 = v6669[v6781];
  int v6782 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6673 = v6669[v6782];
  int v6674 = v6664->timer;
  int v6783 = v6674 + ((100 ^ (((~(((v6672 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6672 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6670 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6670 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6671 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6671 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6672 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6672 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6664->timer = v6783;
  int * v6676 = v6664->cache_vals;
  bool v6784 = !(((~(((v6670 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6670 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6671 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6671 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v6769;
  if (v6784) {
    int * v6677 = v6664->cache_age;
    int v6786 = ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v6671 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6671 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v6678 = v6677[v6786];
    int v6679 = v6677[v6779];
    int v6787 = v6679 + ((int)((unsigned int)(v6679 - v6678) >> 31));
    v6677[v6779] = v6787;
    int * v6681 = v6664->cache_age;
    int v6682 = v6681[v6780];
    int v6789 = v6682 + ((int)((unsigned int)(v6682 - v6678) >> 31));
    v6681[v6780] = v6789;
    int * v6684 = v6664->cache_age;
    v6684[v6786] = 0;
    v6769 = v6786;
  } else {
    int * v6687 = v6664->cache_age;
    int v6793 = (((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2;
    int v6688 = v6687[v6793];
    int * v6689 = v6664->cache_tags;
    int v6690 = v6689[v6793];
    int v6691 = v6687[v6780];
    int v6692 = v6689[v6780];
    bool v6795 = !(((~(((v6672 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6672 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v6746;
    if (v6795) {
      int * v6693 = v6664->cache_age;
      int v6797 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))) | (-(v6673 ^ ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v6694 = v6693[v6797];
      int v6695 = v6693[v6781];
      int v6798 = v6695 + ((int)((unsigned int)(v6695 - v6694) >> 31));
      v6693[v6781] = v6798;
      int * v6697 = v6664->cache_age;
      int v6698 = v6697[v6782];
      int v6800 = v6698 + ((int)((unsigned int)(v6698 - v6694) >> 31));
      v6697[v6782] = v6800;
      int * v6700 = v6664->cache_age;
      v6700[v6797] = 0;
      v6746 = v6797;
    } else {
      int * v6703 = v6664->cache_age;
      int v6804 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2);
      int v6704 = v6703[v6804];
      int * v6705 = v6664->cache_tags;
      int v6706 = v6705[v6804];
      int v6707 = v6703[v6782];
      int v6708 = v6705[v6782];
      int * v6709 = v6664->cache_dirty;
      int v6807 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6704 + ((~(((v6706 ^ -1) | (-(v6706 ^ -1))) >> 31)) & 2)) - (v6707 + ((~(((v6708 ^ -1) | (-(v6708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6710 = v6709[v6807];
      bool v6808 = !(v6710 == 0);
      if (v6808) {
        int * v6711 = v6664->cache_tags;
        int v6712 = v6711[v6807];
        int * v6713 = v6664->cache_vals;
        int v6811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6704 + ((~(((v6706 ^ -1) | (-(v6706 ^ -1))) >> 31)) & 2)) - (v6707 + ((~(((v6708 ^ -1) | (-(v6708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6714 = v6713[v6811];
        int v6812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6704 + ((~(((v6706 ^ -1) | (-(v6706 ^ -1))) >> 31)) & 2)) - (v6707 + ((~(((v6708 ^ -1) | (-(v6708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6715 = v6713[v6812];
        int * v6716 = v6664->mem;
        int v6814 = v6712 * 2;
        v6716[v6814] = v6714;
        int * v6718 = v6664->mem;
        int v6817 = (v6712 * 2) + 1;
        v6718[v6817] = v6715;
        ;
      } else {
        ;
      }
      int * v6723 = v6664->mem;
      int v6822 = ((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) * 2;
      int v6724 = v6723[v6822];
      int v6823 = (((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) * 2) + 1;
      int v6725 = v6723[v6823];
      int * v6726 = v6664->cache_vals;
      int v6825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6704 + ((~(((v6706 ^ -1) | (-(v6706 ^ -1))) >> 31)) & 2)) - (v6707 + ((~(((v6708 ^ -1) | (-(v6708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6726[v6825] = v6724;
      int * v6728 = v6664->cache_vals;
      int v6828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6704 + ((~(((v6706 ^ -1) | (-(v6706 ^ -1))) >> 31)) & 2)) - (v6707 + ((~(((v6708 ^ -1) | (-(v6708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6728[v6828] = v6725;
      int * v6730 = v6664->cache_tags;
      int v6831 = (int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1);
      v6730[v6807] = v6831;
      int * v6732 = v6664->cache_dirty;
      v6732[v6807] = 0;
      int * v6734 = v6664->cache_age;
      v6734[v6807] = 1;
      int * v6736 = v6664->cache_age;
      int v6737 = v6736[v6807];
      int v6738 = v6736[v6781];
      int v6837 = v6738 + ((int)((unsigned int)(v6738 - v6737) >> 31));
      v6736[v6781] = v6837;
      int * v6740 = v6664->cache_age;
      int v6741 = v6740[v6782];
      int v6839 = v6741 + ((int)((unsigned int)(v6741 - v6737) >> 31));
      v6740[v6782] = v6839;
      int * v6743 = v6664->cache_age;
      v6743[v6807] = 0;
      v6746 = v6807;
    }
    int * v6747 = v6664->cache_vals;
    int v6842 = v6746 * 2;
    int v6748 = v6747[v6842];
    int v6843 = (v6746 * 2) + 1;
    int v6749 = v6747[v6843];
    int v6844 = (((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v6688 + ((~(((v6690 ^ -1) | (-(v6690 ^ -1))) >> 31)) & 2)) - (v6691 + ((~(((v6692 ^ -1) | (-(v6692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6747[v6844] = v6748;
    int * v6751 = v6664->cache_vals;
    int v6847 = ((((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v6688 + ((~(((v6690 ^ -1) | (-(v6690 ^ -1))) >> 31)) & 2)) - (v6691 + ((~(((v6692 ^ -1) | (-(v6692 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6751[v6847] = v6749;
    int * v6753 = v6664->cache_tags;
    int v6850 = ((((int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v6688 + ((~(((v6690 ^ -1) | (-(v6690 ^ -1))) >> 31)) & 2)) - (v6691 + ((~(((v6692 ^ -1) | (-(v6692 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6851 = (int)((unsigned int)((int)((unsigned int)(v6668 + 36) >> 2)) >> 1);
    v6753[v6850] = v6851;
    int * v6755 = v6664->cache_dirty;
    v6755[v6850] = 0;
    int * v6757 = v6664->cache_age;
    v6757[v6850] = 1;
    int * v6759 = v6664->cache_age;
    int v6760 = v6759[v6850];
    int v6761 = v6759[v6779];
    int v6857 = v6761 + ((int)((unsigned int)(v6761 - v6760) >> 31));
    v6759[v6779] = v6857;
    int * v6763 = v6664->cache_age;
    int v6764 = v6763[v6780];
    int v6859 = v6764 + ((int)((unsigned int)(v6764 - v6760) >> 31));
    v6763[v6780] = v6859;
    int * v6766 = v6664->cache_age;
    v6766[v6850] = 0;
    v6769 = v6850;
  }
  int v6862 = (v6769 * 2) + (((int)((unsigned int)(v6668 + 36) >> 2)) & 1);
  int v6770 = v6676[v6862];
  int * v6771 = v6664->regs;
  v6771[11] = v6770;
  struct StateT * v6773 = slot_64(v6664);
  return v6773;
}

struct StateT * slot_24(struct StateT * v2506) {
  int v2507 = v2506->timer;
  int v2514 = v2507 + 1;
  v2506->timer = v2514;
  int * v2509 = v2506->regs;
  int v2510 = v2509[13];
  int v2518 = v2510 + -8;
  v2509[15] = v2518;
  struct StateT * v2512 = slot_25(v2506);
  return v2512;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v113 = v3 + 1;
  v2->timer = v113;
  int * v5 = v2->regs;
  int v6 = v5[11];
  int * v7 = v2->cache_tags;
  int v117 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v117];
  int v118 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9 = v7[v118];
  int v119 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v10 = v7[v119];
  int v120 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11 = v7[v120];
  int v12 = v2->timer;
  int v121 = v12 + ((100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v121;
  int * v14 = v2->cache_vals;
  bool v122 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v107;
  if (v122) {
    int * v15 = v2->cache_age;
    int v124 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v16 = v15[v124];
    int v17 = v15[v117];
    int v125 = v17 + ((int)((unsigned int)(v17 - v16) >> 31));
    v15[v117] = v125;
    int * v19 = v2->cache_age;
    int v20 = v19[v118];
    int v127 = v20 + ((int)((unsigned int)(v20 - v16) >> 31));
    v19[v118] = v127;
    int * v22 = v2->cache_age;
    v22[v124] = 0;
    v107 = v124;
  } else {
    int * v25 = v2->cache_age;
    int v131 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v26 = v25[v131];
    int * v27 = v2->cache_tags;
    int v28 = v27[v131];
    int v29 = v25[v118];
    int v30 = v27[v118];
    bool v133 = !(((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v84;
    if (v133) {
      int * v31 = v2->cache_age;
      int v135 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v32 = v31[v135];
      int v33 = v31[v119];
      int v136 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
      v31[v119] = v136;
      int * v35 = v2->cache_age;
      int v36 = v35[v120];
      int v138 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
      v35[v120] = v138;
      int * v38 = v2->cache_age;
      v38[v135] = 0;
      v84 = v135;
    } else {
      int * v41 = v2->cache_age;
      int v142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v42 = v41[v142];
      int * v43 = v2->cache_tags;
      int v44 = v43[v142];
      int v45 = v41[v120];
      int v46 = v43[v120];
      int * v47 = v2->cache_dirty;
      int v145 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v48 = v47[v145];
      bool v146 = !(v48 == 0);
      if (v146) {
        int * v49 = v2->cache_tags;
        int v50 = v49[v145];
        int * v51 = v2->cache_vals;
        int v149 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v52 = v51[v149];
        int v150 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v53 = v51[v150];
        int * v54 = v2->mem;
        int v152 = v50 * 2;
        v54[v152] = v52;
        int * v56 = v2->mem;
        int v155 = (v50 * 2) + 1;
        v56[v155] = v53;
        ;
      } else {
        ;
      }
      int * v61 = v2->mem;
      int v160 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v62 = v61[v160];
      int v161 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v63 = v61[v161];
      int * v64 = v2->cache_vals;
      int v163 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v64[v163] = v62;
      int * v66 = v2->cache_vals;
      int v166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v66[v166] = v63;
      int * v68 = v2->cache_tags;
      int v169 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v68[v145] = v169;
      int * v70 = v2->cache_dirty;
      v70[v145] = 0;
      int * v72 = v2->cache_age;
      v72[v145] = 1;
      int * v74 = v2->cache_age;
      int v75 = v74[v145];
      int v76 = v74[v119];
      int v175 = v76 + ((int)((unsigned int)(v76 - v75) >> 31));
      v74[v119] = v175;
      int * v78 = v2->cache_age;
      int v79 = v78[v120];
      int v177 = v79 + ((int)((unsigned int)(v79 - v75) >> 31));
      v78[v120] = v177;
      int * v81 = v2->cache_age;
      v81[v145] = 0;
      v84 = v145;
    }
    int * v85 = v2->cache_vals;
    int v180 = v84 * 2;
    int v86 = v85[v180];
    int v181 = (v84 * 2) + 1;
    int v87 = v85[v181];
    int v182 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v85[v182] = v86;
    int * v89 = v2->cache_vals;
    int v185 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v89[v185] = v87;
    int * v91 = v2->cache_tags;
    int v188 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v189 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v91[v188] = v189;
    int * v93 = v2->cache_dirty;
    v93[v188] = 0;
    int * v95 = v2->cache_age;
    v95[v188] = 1;
    int * v97 = v2->cache_age;
    int v98 = v97[v188];
    int v99 = v97[v117];
    int v195 = v99 + ((int)((unsigned int)(v99 - v98) >> 31));
    v97[v117] = v195;
    int * v101 = v2->cache_age;
    int v102 = v101[v118];
    int v197 = v102 + ((int)((unsigned int)(v102 - v98) >> 31));
    v101[v118] = v197;
    int * v104 = v2->cache_age;
    v104[v188] = 0;
    v107 = v188;
  }
  int v200 = (v107 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v108 = v14[v200];
  int * v109 = v2->regs;
  v109[12] = v108;
  struct StateT * v111 = slot_1(v2);
  return v111;
}

struct StateT * slot_42(struct StateT * v4535) {
  int v4536 = v4535->timer;
  int v4548 = v4536 + 1;
  v4535->timer = v4548;
  int * v4538 = v4535->regs;
  int v4539 = v4538[6];
  int v4540 = v4538[13];
  bool v4552 = (v4539 ^ -2147483648) < (v4540 ^ -2147483648);
  int v4543;
  if (v4552) {
    v4543 = 1;
  } else {
    v4543 = 0;
  }
  int * v4544 = v4535->regs;
  v4544[13] = v4543;
  struct StateT * v4546 = slot_43(v4535);
  return v4546;
}

struct StateT * slot_46(struct StateT * v4616) {
  int v4617 = v4616->timer;
  int v4625 = v4617 + 1;
  v4616->timer = v4625;
  int * v4619 = v4616->regs;
  int v4620 = v4619[14];
  int v4621 = v4619[13];
  int v4629 = v4620 + v4621;
  v4619[13] = v4629;
  struct StateT * v4623 = slot_47(v4616);
  return v4623;
}

struct StateT * slot_20(struct StateT * v1468) {
  int v1469 = v1468->timer;
  int v1639 = v1469 + 1;
  v1468->timer = v1639;
  int * v1471 = v1468->regs;
  int v1472 = v1471[10];
  int v1473 = v1471[15];
  int * v1474 = v1468->cache_tags;
  int v1644 = (((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2;
  int v1475 = v1474[v1644];
  int v1645 = ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1476 = v1474[v1645];
  int v1646 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2);
  int v1477 = v1474[v1646];
  int v1647 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1478 = v1474[v1647];
  int v1479 = v1468->timer;
  int v1648 = v1479 + ((100 ^ (((~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) | (~(((v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) | (~(((v1476 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1476 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) | (~(((v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1468->timer = v1648;
  bool v1649 = !(((~(((v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1475 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) | (~(((v1476 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1476 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31))) == 0);
  int v1573;
  if (v1649) {
    int * v1481 = v1468->cache_age;
    int v1651 = ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2) + ((~(((v1476 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1476 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) & 1);
    int v1482 = v1481[v1651];
    int v1483 = v1481[v1644];
    int v1652 = v1483 + ((int)((unsigned int)(v1483 - v1482) >> 31));
    v1481[v1644] = v1652;
    int * v1485 = v1468->cache_age;
    int v1486 = v1485[v1645];
    int v1654 = v1486 + ((int)((unsigned int)(v1486 - v1482) >> 31));
    v1485[v1645] = v1654;
    int * v1488 = v1468->cache_age;
    v1488[v1651] = 0;
    v1573 = v1651;
  } else {
    int * v1491 = v1468->cache_age;
    int v1658 = (((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2;
    int v1492 = v1491[v1658];
    int * v1493 = v1468->cache_tags;
    int v1494 = v1493[v1658];
    int v1495 = v1491[v1645];
    int v1496 = v1493[v1645];
    bool v1660 = !(((~(((v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1477 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) | (~(((v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31))) == 0);
    int v1550;
    if (v1660) {
      int * v1497 = v1468->cache_age;
      int v1662 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1478 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) & 1);
      int v1498 = v1497[v1662];
      int v1499 = v1497[v1646];
      int v1663 = v1499 + ((int)((unsigned int)(v1499 - v1498) >> 31));
      v1497[v1646] = v1663;
      int * v1501 = v1468->cache_age;
      int v1502 = v1501[v1647];
      int v1665 = v1502 + ((int)((unsigned int)(v1502 - v1498) >> 31));
      v1501[v1647] = v1665;
      int * v1504 = v1468->cache_age;
      v1504[v1662] = 0;
      v1550 = v1662;
    } else {
      int * v1507 = v1468->cache_age;
      int v1669 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2);
      int v1508 = v1507[v1669];
      int * v1509 = v1468->cache_tags;
      int v1510 = v1509[v1669];
      int v1511 = v1507[v1647];
      int v1512 = v1509[v1647];
      int * v1513 = v1468->cache_dirty;
      int v1672 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1508 + ((~(((v1510 ^ -1) | (-(v1510 ^ -1))) >> 31)) & 2)) - (v1511 + ((~(((v1512 ^ -1) | (-(v1512 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1514 = v1513[v1672];
      bool v1673 = !(v1514 == 0);
      if (v1673) {
        int * v1515 = v1468->cache_tags;
        int v1516 = v1515[v1672];
        int * v1517 = v1468->cache_vals;
        int v1676 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1508 + ((~(((v1510 ^ -1) | (-(v1510 ^ -1))) >> 31)) & 2)) - (v1511 + ((~(((v1512 ^ -1) | (-(v1512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1518 = v1517[v1676];
        int v1677 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1508 + ((~(((v1510 ^ -1) | (-(v1510 ^ -1))) >> 31)) & 2)) - (v1511 + ((~(((v1512 ^ -1) | (-(v1512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1519 = v1517[v1677];
        int * v1520 = v1468->mem;
        int v1679 = v1516 * 2;
        v1520[v1679] = v1518;
        int * v1522 = v1468->mem;
        int v1682 = (v1516 * 2) + 1;
        v1522[v1682] = v1519;
        ;
      } else {
        ;
      }
      int * v1527 = v1468->mem;
      int v1687 = ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) * 2;
      int v1528 = v1527[v1687];
      int v1688 = (((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) * 2) + 1;
      int v1529 = v1527[v1688];
      int * v1530 = v1468->cache_vals;
      int v1690 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1508 + ((~(((v1510 ^ -1) | (-(v1510 ^ -1))) >> 31)) & 2)) - (v1511 + ((~(((v1512 ^ -1) | (-(v1512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1530[v1690] = v1528;
      int * v1532 = v1468->cache_vals;
      int v1693 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1508 + ((~(((v1510 ^ -1) | (-(v1510 ^ -1))) >> 31)) & 2)) - (v1511 + ((~(((v1512 ^ -1) | (-(v1512 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1532[v1693] = v1529;
      int * v1534 = v1468->cache_tags;
      int v1696 = (int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1);
      v1534[v1672] = v1696;
      int * v1536 = v1468->cache_dirty;
      v1536[v1672] = 0;
      int * v1538 = v1468->cache_age;
      v1538[v1672] = 1;
      int * v1540 = v1468->cache_age;
      int v1541 = v1540[v1672];
      int v1542 = v1540[v1646];
      int v1702 = v1542 + ((int)((unsigned int)(v1542 - v1541) >> 31));
      v1540[v1646] = v1702;
      int * v1544 = v1468->cache_age;
      int v1545 = v1544[v1647];
      int v1704 = v1545 + ((int)((unsigned int)(v1545 - v1541) >> 31));
      v1544[v1647] = v1704;
      int * v1547 = v1468->cache_age;
      v1547[v1672] = 0;
      v1550 = v1672;
    }
    int * v1551 = v1468->cache_vals;
    int v1707 = v1550 * 2;
    int v1552 = v1551[v1707];
    int v1708 = (v1550 * 2) + 1;
    int v1553 = v1551[v1708];
    int v1709 = (((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1495 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1551[v1709] = v1552;
    int * v1555 = v1468->cache_vals;
    int v1712 = ((((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1495 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1555[v1712] = v1553;
    int * v1557 = v1468->cache_tags;
    int v1715 = ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 1) * 2) + ((((v1492 + ((~(((v1494 ^ -1) | (-(v1494 ^ -1))) >> 31)) & 2)) - (v1495 + ((~(((v1496 ^ -1) | (-(v1496 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1716 = (int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1);
    v1557[v1715] = v1716;
    int * v1559 = v1468->cache_dirty;
    v1559[v1715] = 0;
    int * v1561 = v1468->cache_age;
    v1561[v1715] = 1;
    int * v1563 = v1468->cache_age;
    int v1564 = v1563[v1715];
    int v1565 = v1563[v1644];
    int v1722 = v1565 + ((int)((unsigned int)(v1565 - v1564) >> 31));
    v1563[v1644] = v1722;
    int * v1567 = v1468->cache_age;
    int v1568 = v1567[v1645];
    int v1724 = v1568 + ((int)((unsigned int)(v1568 - v1564) >> 31));
    v1567[v1645] = v1724;
    int * v1570 = v1468->cache_age;
    v1570[v1715] = 0;
    v1573 = v1715;
  }
  int * v1574 = v1468->cache_vals;
  int v1727 = (v1573 * 2) + (((int)((unsigned int)v1472 >> 2)) & 1);
  v1574[v1727] = v1473;
  int * v1576 = v1468->cache_tags;
  int v1577 = v1576[v1646];
  int v1578 = v1576[v1647];
  bool v1730 = !(((~(((v1577 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1577 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) | (~(((v1578 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1578 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31))) == 0);
  int v1632;
  if (v1730) {
    int * v1579 = v1468->cache_age;
    int v1732 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1578 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))) | (-(v1578 ^ ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1))))) >> 31)) & 1);
    int v1580 = v1579[v1732];
    int v1581 = v1579[v1646];
    int v1733 = v1581 + ((int)((unsigned int)(v1581 - v1580) >> 31));
    v1579[v1646] = v1733;
    int * v1583 = v1468->cache_age;
    int v1584 = v1583[v1647];
    int v1735 = v1584 + ((int)((unsigned int)(v1584 - v1580) >> 31));
    v1583[v1647] = v1735;
    int * v1586 = v1468->cache_age;
    v1586[v1732] = 0;
    v1632 = v1732;
  } else {
    int * v1589 = v1468->cache_age;
    int v1739 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2);
    int v1590 = v1589[v1739];
    int * v1591 = v1468->cache_tags;
    int v1592 = v1591[v1739];
    int v1593 = v1589[v1647];
    int v1594 = v1591[v1647];
    int * v1595 = v1468->cache_dirty;
    int v1742 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1590 + ((~(((v1592 ^ -1) | (-(v1592 ^ -1))) >> 31)) & 2)) - (v1593 + ((~(((v1594 ^ -1) | (-(v1594 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1596 = v1595[v1742];
    bool v1743 = !(v1596 == 0);
    if (v1743) {
      int * v1597 = v1468->cache_tags;
      int v1598 = v1597[v1742];
      int * v1599 = v1468->cache_vals;
      int v1746 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1590 + ((~(((v1592 ^ -1) | (-(v1592 ^ -1))) >> 31)) & 2)) - (v1593 + ((~(((v1594 ^ -1) | (-(v1594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1600 = v1599[v1746];
      int v1747 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1590 + ((~(((v1592 ^ -1) | (-(v1592 ^ -1))) >> 31)) & 2)) - (v1593 + ((~(((v1594 ^ -1) | (-(v1594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1601 = v1599[v1747];
      int * v1602 = v1468->mem;
      int v1749 = v1598 * 2;
      v1602[v1749] = v1600;
      int * v1604 = v1468->mem;
      int v1752 = (v1598 * 2) + 1;
      v1604[v1752] = v1601;
      ;
    } else {
      ;
    }
    int * v1609 = v1468->mem;
    int v1757 = ((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) * 2;
    int v1610 = v1609[v1757];
    int v1758 = (((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) * 2) + 1;
    int v1611 = v1609[v1758];
    int * v1612 = v1468->cache_vals;
    int v1760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1590 + ((~(((v1592 ^ -1) | (-(v1592 ^ -1))) >> 31)) & 2)) - (v1593 + ((~(((v1594 ^ -1) | (-(v1594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1612[v1760] = v1610;
    int * v1614 = v1468->cache_vals;
    int v1763 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1)) & 3) * 2)) + ((((v1590 + ((~(((v1592 ^ -1) | (-(v1592 ^ -1))) >> 31)) & 2)) - (v1593 + ((~(((v1594 ^ -1) | (-(v1594 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1614[v1763] = v1611;
    int * v1616 = v1468->cache_tags;
    int v1766 = (int)((unsigned int)((int)((unsigned int)v1472 >> 2)) >> 1);
    v1616[v1742] = v1766;
    int * v1618 = v1468->cache_dirty;
    v1618[v1742] = 0;
    int * v1620 = v1468->cache_age;
    v1620[v1742] = 1;
    int * v1622 = v1468->cache_age;
    int v1623 = v1622[v1742];
    int v1624 = v1622[v1646];
    int v1772 = v1624 + ((int)((unsigned int)(v1624 - v1623) >> 31));
    v1622[v1646] = v1772;
    int * v1626 = v1468->cache_age;
    int v1627 = v1626[v1647];
    int v1774 = v1627 + ((int)((unsigned int)(v1627 - v1623) >> 31));
    v1626[v1647] = v1774;
    int * v1629 = v1468->cache_age;
    v1629[v1742] = 0;
    v1632 = v1742;
  }
  int * v1633 = v1468->cache_vals;
  int v1777 = (v1632 * 2) + (((int)((unsigned int)v1472 >> 2)) & 1);
  v1633[v1777] = v1473;
  int * v1635 = v1468->cache_dirty;
  v1635[v1632] = 1;
  struct StateT * v1637 = slot_21(v1468);
  return v1637;
}

struct StateT * slot_61(struct StateT * v6145) {
  int v6146 = v6145->timer;
  int v6316 = v6146 + 1;
  v6145->timer = v6316;
  int * v6148 = v6145->regs;
  int v6149 = v6148[10];
  int v6150 = v6148[13];
  int * v6151 = v6145->cache_tags;
  int v6321 = (((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2;
  int v6152 = v6151[v6321];
  int v6322 = ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6153 = v6151[v6322];
  int v6323 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2);
  int v6154 = v6151[v6323];
  int v6324 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6155 = v6151[v6324];
  int v6156 = v6145->timer;
  int v6325 = v6156 + ((100 ^ (((~(((v6154 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6154 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6152 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6152 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6153 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6153 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6154 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6154 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6145->timer = v6325;
  bool v6326 = !(((~(((v6152 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6152 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6153 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6153 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v6250;
  if (v6326) {
    int * v6158 = v6145->cache_age;
    int v6328 = ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v6153 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6153 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v6159 = v6158[v6328];
    int v6160 = v6158[v6321];
    int v6329 = v6160 + ((int)((unsigned int)(v6160 - v6159) >> 31));
    v6158[v6321] = v6329;
    int * v6162 = v6145->cache_age;
    int v6163 = v6162[v6322];
    int v6331 = v6163 + ((int)((unsigned int)(v6163 - v6159) >> 31));
    v6162[v6322] = v6331;
    int * v6165 = v6145->cache_age;
    v6165[v6328] = 0;
    v6250 = v6328;
  } else {
    int * v6168 = v6145->cache_age;
    int v6335 = (((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2;
    int v6169 = v6168[v6335];
    int * v6170 = v6145->cache_tags;
    int v6171 = v6170[v6335];
    int v6172 = v6168[v6322];
    int v6173 = v6170[v6322];
    bool v6337 = !(((~(((v6154 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6154 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v6227;
    if (v6337) {
      int * v6174 = v6145->cache_age;
      int v6339 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6155 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v6175 = v6174[v6339];
      int v6176 = v6174[v6323];
      int v6340 = v6176 + ((int)((unsigned int)(v6176 - v6175) >> 31));
      v6174[v6323] = v6340;
      int * v6178 = v6145->cache_age;
      int v6179 = v6178[v6324];
      int v6342 = v6179 + ((int)((unsigned int)(v6179 - v6175) >> 31));
      v6178[v6324] = v6342;
      int * v6181 = v6145->cache_age;
      v6181[v6339] = 0;
      v6227 = v6339;
    } else {
      int * v6184 = v6145->cache_age;
      int v6346 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2);
      int v6185 = v6184[v6346];
      int * v6186 = v6145->cache_tags;
      int v6187 = v6186[v6346];
      int v6188 = v6184[v6324];
      int v6189 = v6186[v6324];
      int * v6190 = v6145->cache_dirty;
      int v6349 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6185 + ((~(((v6187 ^ -1) | (-(v6187 ^ -1))) >> 31)) & 2)) - (v6188 + ((~(((v6189 ^ -1) | (-(v6189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6191 = v6190[v6349];
      bool v6350 = !(v6191 == 0);
      if (v6350) {
        int * v6192 = v6145->cache_tags;
        int v6193 = v6192[v6349];
        int * v6194 = v6145->cache_vals;
        int v6353 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6185 + ((~(((v6187 ^ -1) | (-(v6187 ^ -1))) >> 31)) & 2)) - (v6188 + ((~(((v6189 ^ -1) | (-(v6189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6195 = v6194[v6353];
        int v6354 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6185 + ((~(((v6187 ^ -1) | (-(v6187 ^ -1))) >> 31)) & 2)) - (v6188 + ((~(((v6189 ^ -1) | (-(v6189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6196 = v6194[v6354];
        int * v6197 = v6145->mem;
        int v6356 = v6193 * 2;
        v6197[v6356] = v6195;
        int * v6199 = v6145->mem;
        int v6359 = (v6193 * 2) + 1;
        v6199[v6359] = v6196;
        ;
      } else {
        ;
      }
      int * v6204 = v6145->mem;
      int v6364 = ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) * 2;
      int v6205 = v6204[v6364];
      int v6365 = (((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) * 2) + 1;
      int v6206 = v6204[v6365];
      int * v6207 = v6145->cache_vals;
      int v6367 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6185 + ((~(((v6187 ^ -1) | (-(v6187 ^ -1))) >> 31)) & 2)) - (v6188 + ((~(((v6189 ^ -1) | (-(v6189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6207[v6367] = v6205;
      int * v6209 = v6145->cache_vals;
      int v6370 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6185 + ((~(((v6187 ^ -1) | (-(v6187 ^ -1))) >> 31)) & 2)) - (v6188 + ((~(((v6189 ^ -1) | (-(v6189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6209[v6370] = v6206;
      int * v6211 = v6145->cache_tags;
      int v6373 = (int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1);
      v6211[v6349] = v6373;
      int * v6213 = v6145->cache_dirty;
      v6213[v6349] = 0;
      int * v6215 = v6145->cache_age;
      v6215[v6349] = 1;
      int * v6217 = v6145->cache_age;
      int v6218 = v6217[v6349];
      int v6219 = v6217[v6323];
      int v6379 = v6219 + ((int)((unsigned int)(v6219 - v6218) >> 31));
      v6217[v6323] = v6379;
      int * v6221 = v6145->cache_age;
      int v6222 = v6221[v6324];
      int v6381 = v6222 + ((int)((unsigned int)(v6222 - v6218) >> 31));
      v6221[v6324] = v6381;
      int * v6224 = v6145->cache_age;
      v6224[v6349] = 0;
      v6227 = v6349;
    }
    int * v6228 = v6145->cache_vals;
    int v6384 = v6227 * 2;
    int v6229 = v6228[v6384];
    int v6385 = (v6227 * 2) + 1;
    int v6230 = v6228[v6385];
    int v6386 = (((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6228[v6386] = v6229;
    int * v6232 = v6145->cache_vals;
    int v6389 = ((((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6232[v6389] = v6230;
    int * v6234 = v6145->cache_tags;
    int v6392 = ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6393 = (int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1);
    v6234[v6392] = v6393;
    int * v6236 = v6145->cache_dirty;
    v6236[v6392] = 0;
    int * v6238 = v6145->cache_age;
    v6238[v6392] = 1;
    int * v6240 = v6145->cache_age;
    int v6241 = v6240[v6392];
    int v6242 = v6240[v6321];
    int v6399 = v6242 + ((int)((unsigned int)(v6242 - v6241) >> 31));
    v6240[v6321] = v6399;
    int * v6244 = v6145->cache_age;
    int v6245 = v6244[v6322];
    int v6401 = v6245 + ((int)((unsigned int)(v6245 - v6241) >> 31));
    v6244[v6322] = v6401;
    int * v6247 = v6145->cache_age;
    v6247[v6392] = 0;
    v6250 = v6392;
  }
  int * v6251 = v6145->cache_vals;
  int v6404 = (v6250 * 2) + (((int)((unsigned int)(v6149 + 28) >> 2)) & 1);
  v6251[v6404] = v6150;
  int * v6253 = v6145->cache_tags;
  int v6254 = v6253[v6323];
  int v6255 = v6253[v6324];
  bool v6407 = !(((~(((v6254 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6254 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6255 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6255 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v6309;
  if (v6407) {
    int * v6256 = v6145->cache_age;
    int v6409 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6255 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))) | (-(v6255 ^ ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v6257 = v6256[v6409];
    int v6258 = v6256[v6323];
    int v6410 = v6258 + ((int)((unsigned int)(v6258 - v6257) >> 31));
    v6256[v6323] = v6410;
    int * v6260 = v6145->cache_age;
    int v6261 = v6260[v6324];
    int v6412 = v6261 + ((int)((unsigned int)(v6261 - v6257) >> 31));
    v6260[v6324] = v6412;
    int * v6263 = v6145->cache_age;
    v6263[v6409] = 0;
    v6309 = v6409;
  } else {
    int * v6266 = v6145->cache_age;
    int v6416 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2);
    int v6267 = v6266[v6416];
    int * v6268 = v6145->cache_tags;
    int v6269 = v6268[v6416];
    int v6270 = v6266[v6324];
    int v6271 = v6268[v6324];
    int * v6272 = v6145->cache_dirty;
    int v6419 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6267 + ((~(((v6269 ^ -1) | (-(v6269 ^ -1))) >> 31)) & 2)) - (v6270 + ((~(((v6271 ^ -1) | (-(v6271 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6273 = v6272[v6419];
    bool v6420 = !(v6273 == 0);
    if (v6420) {
      int * v6274 = v6145->cache_tags;
      int v6275 = v6274[v6419];
      int * v6276 = v6145->cache_vals;
      int v6423 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6267 + ((~(((v6269 ^ -1) | (-(v6269 ^ -1))) >> 31)) & 2)) - (v6270 + ((~(((v6271 ^ -1) | (-(v6271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6277 = v6276[v6423];
      int v6424 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6267 + ((~(((v6269 ^ -1) | (-(v6269 ^ -1))) >> 31)) & 2)) - (v6270 + ((~(((v6271 ^ -1) | (-(v6271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6278 = v6276[v6424];
      int * v6279 = v6145->mem;
      int v6426 = v6275 * 2;
      v6279[v6426] = v6277;
      int * v6281 = v6145->mem;
      int v6429 = (v6275 * 2) + 1;
      v6281[v6429] = v6278;
      ;
    } else {
      ;
    }
    int * v6286 = v6145->mem;
    int v6434 = ((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) * 2;
    int v6287 = v6286[v6434];
    int v6435 = (((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) * 2) + 1;
    int v6288 = v6286[v6435];
    int * v6289 = v6145->cache_vals;
    int v6437 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6267 + ((~(((v6269 ^ -1) | (-(v6269 ^ -1))) >> 31)) & 2)) - (v6270 + ((~(((v6271 ^ -1) | (-(v6271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6289[v6437] = v6287;
    int * v6291 = v6145->cache_vals;
    int v6440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6267 + ((~(((v6269 ^ -1) | (-(v6269 ^ -1))) >> 31)) & 2)) - (v6270 + ((~(((v6271 ^ -1) | (-(v6271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6291[v6440] = v6288;
    int * v6293 = v6145->cache_tags;
    int v6443 = (int)((unsigned int)((int)((unsigned int)(v6149 + 28) >> 2)) >> 1);
    v6293[v6419] = v6443;
    int * v6295 = v6145->cache_dirty;
    v6295[v6419] = 0;
    int * v6297 = v6145->cache_age;
    v6297[v6419] = 1;
    int * v6299 = v6145->cache_age;
    int v6300 = v6299[v6419];
    int v6301 = v6299[v6323];
    int v6449 = v6301 + ((int)((unsigned int)(v6301 - v6300) >> 31));
    v6299[v6323] = v6449;
    int * v6303 = v6145->cache_age;
    int v6304 = v6303[v6324];
    int v6451 = v6304 + ((int)((unsigned int)(v6304 - v6300) >> 31));
    v6303[v6324] = v6451;
    int * v6306 = v6145->cache_age;
    v6306[v6419] = 0;
    v6309 = v6419;
  }
  int * v6310 = v6145->cache_vals;
  int v6454 = (v6309 * 2) + (((int)((unsigned int)(v6149 + 28) >> 2)) & 1);
  v6310[v6454] = v6150;
  int * v6312 = v6145->cache_dirty;
  v6312[v6309] = 1;
  struct StateT * v6314 = slot_62(v6145);
  return v6314;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v4519) {
  int v4520 = v4519->timer;
  int v4528 = v4520 + 1;
  v4519->timer = v4528;
  int * v4522 = v4519->regs;
  int v4523 = v4522[14];
  int v4524 = v4522[12];
  int v4532 = v4523 + v4524;
  v4522[14] = v4532;
  struct StateT * v4526 = slot_42(v4519);
  return v4526;
}

struct StateT * slot_39(struct StateT * v4300) {
  int v4301 = v4300->timer;
  int v4411 = v4301 + 1;
  v4300->timer = v4411;
  int * v4303 = v4300->regs;
  int v4304 = v4303[10];
  int * v4305 = v4300->cache_tags;
  int v4415 = (((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2;
  int v4306 = v4305[v4415];
  int v4416 = ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4307 = v4305[v4416];
  int v4417 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2);
  int v4308 = v4305[v4417];
  int v4418 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4309 = v4305[v4418];
  int v4310 = v4300->timer;
  int v4419 = v4310 + ((100 ^ (((~(((v4308 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4308 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4306 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4306 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4307 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4307 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4308 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4308 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4300->timer = v4419;
  int * v4312 = v4300->cache_vals;
  bool v4420 = !(((~(((v4306 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4306 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4307 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4307 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v4405;
  if (v4420) {
    int * v4313 = v4300->cache_age;
    int v4422 = ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v4307 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4307 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v4314 = v4313[v4422];
    int v4315 = v4313[v4415];
    int v4423 = v4315 + ((int)((unsigned int)(v4315 - v4314) >> 31));
    v4313[v4415] = v4423;
    int * v4317 = v4300->cache_age;
    int v4318 = v4317[v4416];
    int v4425 = v4318 + ((int)((unsigned int)(v4318 - v4314) >> 31));
    v4317[v4416] = v4425;
    int * v4320 = v4300->cache_age;
    v4320[v4422] = 0;
    v4405 = v4422;
  } else {
    int * v4323 = v4300->cache_age;
    int v4429 = (((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2;
    int v4324 = v4323[v4429];
    int * v4325 = v4300->cache_tags;
    int v4326 = v4325[v4429];
    int v4327 = v4323[v4416];
    int v4328 = v4325[v4416];
    bool v4431 = !(((~(((v4308 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4308 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v4382;
    if (v4431) {
      int * v4329 = v4300->cache_age;
      int v4433 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))) | (-(v4309 ^ ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v4330 = v4329[v4433];
      int v4331 = v4329[v4417];
      int v4434 = v4331 + ((int)((unsigned int)(v4331 - v4330) >> 31));
      v4329[v4417] = v4434;
      int * v4333 = v4300->cache_age;
      int v4334 = v4333[v4418];
      int v4436 = v4334 + ((int)((unsigned int)(v4334 - v4330) >> 31));
      v4333[v4418] = v4436;
      int * v4336 = v4300->cache_age;
      v4336[v4433] = 0;
      v4382 = v4433;
    } else {
      int * v4339 = v4300->cache_age;
      int v4440 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2);
      int v4340 = v4339[v4440];
      int * v4341 = v4300->cache_tags;
      int v4342 = v4341[v4440];
      int v4343 = v4339[v4418];
      int v4344 = v4341[v4418];
      int * v4345 = v4300->cache_dirty;
      int v4443 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4340 + ((~(((v4342 ^ -1) | (-(v4342 ^ -1))) >> 31)) & 2)) - (v4343 + ((~(((v4344 ^ -1) | (-(v4344 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4346 = v4345[v4443];
      bool v4444 = !(v4346 == 0);
      if (v4444) {
        int * v4347 = v4300->cache_tags;
        int v4348 = v4347[v4443];
        int * v4349 = v4300->cache_vals;
        int v4447 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4340 + ((~(((v4342 ^ -1) | (-(v4342 ^ -1))) >> 31)) & 2)) - (v4343 + ((~(((v4344 ^ -1) | (-(v4344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4350 = v4349[v4447];
        int v4448 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4340 + ((~(((v4342 ^ -1) | (-(v4342 ^ -1))) >> 31)) & 2)) - (v4343 + ((~(((v4344 ^ -1) | (-(v4344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4351 = v4349[v4448];
        int * v4352 = v4300->mem;
        int v4450 = v4348 * 2;
        v4352[v4450] = v4350;
        int * v4354 = v4300->mem;
        int v4453 = (v4348 * 2) + 1;
        v4354[v4453] = v4351;
        ;
      } else {
        ;
      }
      int * v4359 = v4300->mem;
      int v4458 = ((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) * 2;
      int v4360 = v4359[v4458];
      int v4459 = (((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) * 2) + 1;
      int v4361 = v4359[v4459];
      int * v4362 = v4300->cache_vals;
      int v4461 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4340 + ((~(((v4342 ^ -1) | (-(v4342 ^ -1))) >> 31)) & 2)) - (v4343 + ((~(((v4344 ^ -1) | (-(v4344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4362[v4461] = v4360;
      int * v4364 = v4300->cache_vals;
      int v4464 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4340 + ((~(((v4342 ^ -1) | (-(v4342 ^ -1))) >> 31)) & 2)) - (v4343 + ((~(((v4344 ^ -1) | (-(v4344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4364[v4464] = v4361;
      int * v4366 = v4300->cache_tags;
      int v4467 = (int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1);
      v4366[v4443] = v4467;
      int * v4368 = v4300->cache_dirty;
      v4368[v4443] = 0;
      int * v4370 = v4300->cache_age;
      v4370[v4443] = 1;
      int * v4372 = v4300->cache_age;
      int v4373 = v4372[v4443];
      int v4374 = v4372[v4417];
      int v4473 = v4374 + ((int)((unsigned int)(v4374 - v4373) >> 31));
      v4372[v4417] = v4473;
      int * v4376 = v4300->cache_age;
      int v4377 = v4376[v4418];
      int v4475 = v4377 + ((int)((unsigned int)(v4377 - v4373) >> 31));
      v4376[v4418] = v4475;
      int * v4379 = v4300->cache_age;
      v4379[v4443] = 0;
      v4382 = v4443;
    }
    int * v4383 = v4300->cache_vals;
    int v4478 = v4382 * 2;
    int v4384 = v4383[v4478];
    int v4479 = (v4382 * 2) + 1;
    int v4385 = v4383[v4479];
    int v4480 = (((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4324 + ((~(((v4326 ^ -1) | (-(v4326 ^ -1))) >> 31)) & 2)) - (v4327 + ((~(((v4328 ^ -1) | (-(v4328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4383[v4480] = v4384;
    int * v4387 = v4300->cache_vals;
    int v4483 = ((((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4324 + ((~(((v4326 ^ -1) | (-(v4326 ^ -1))) >> 31)) & 2)) - (v4327 + ((~(((v4328 ^ -1) | (-(v4328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4387[v4483] = v4385;
    int * v4389 = v4300->cache_tags;
    int v4486 = ((((int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4324 + ((~(((v4326 ^ -1) | (-(v4326 ^ -1))) >> 31)) & 2)) - (v4327 + ((~(((v4328 ^ -1) | (-(v4328 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4487 = (int)((unsigned int)((int)((unsigned int)(v4304 + 28) >> 2)) >> 1);
    v4389[v4486] = v4487;
    int * v4391 = v4300->cache_dirty;
    v4391[v4486] = 0;
    int * v4393 = v4300->cache_age;
    v4393[v4486] = 1;
    int * v4395 = v4300->cache_age;
    int v4396 = v4395[v4486];
    int v4397 = v4395[v4415];
    int v4493 = v4397 + ((int)((unsigned int)(v4397 - v4396) >> 31));
    v4395[v4415] = v4493;
    int * v4399 = v4300->cache_age;
    int v4400 = v4399[v4416];
    int v4495 = v4400 + ((int)((unsigned int)(v4400 - v4396) >> 31));
    v4399[v4416] = v4495;
    int * v4402 = v4300->cache_age;
    v4402[v4486] = 0;
    v4405 = v4486;
  }
  int v4498 = (v4405 * 2) + (((int)((unsigned int)(v4304 + 28) >> 2)) & 1);
  int v4406 = v4312[v4498];
  int * v4407 = v4300->regs;
  v4407[5] = v4406;
  struct StateT * v4409 = slot_40(v4300);
  return v4409;
}

struct StateT * slot_8(struct StateT * v1266) {
  int v1267 = v1266->timer;
  int v1275 = v1267 + 1;
  v1266->timer = v1275;
  int * v1269 = v1266->regs;
  int v1270 = v1269[5];
  int v1271 = v1269[14];
  int v1280 = v1270 - v1271;
  v1269[7] = v1280;
  struct StateT * v1273 = slot_9(v1266);
  return v1273;
}

struct StateT * slot_30(struct StateT * v2618) {
  int v2619 = v2618->timer;
  int v2627 = v2619 + 1;
  v2618->timer = v2627;
  int * v2621 = v2618->regs;
  int v2622 = v2621[14];
  int v2623 = v2621[13];
  int v2631 = v2622 + v2623;
  v2621[13] = v2631;
  struct StateT * v2625 = slot_31(v2618);
  return v2625;
}

struct StateT * slot_60(struct StateT * v5830) {
  int v5831 = v5830->timer;
  int v6001 = v5831 + 1;
  v5830->timer = v6001;
  int * v5833 = v5830->regs;
  int v5834 = v5833[10];
  int v5835 = v5833[15];
  int * v5836 = v5830->cache_tags;
  int v6006 = (((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2;
  int v5837 = v5836[v6006];
  int v6007 = ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5838 = v5836[v6007];
  int v6008 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2);
  int v5839 = v5836[v6008];
  int v6009 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5840 = v5836[v6009];
  int v5841 = v5830->timer;
  int v6010 = v5841 + ((100 ^ (((~(((v5839 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5839 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5837 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5837 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5838 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5838 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5839 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5839 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5830->timer = v6010;
  bool v6011 = !(((~(((v5837 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5837 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5838 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5838 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5935;
  if (v6011) {
    int * v5843 = v5830->cache_age;
    int v6013 = ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v5838 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5838 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5844 = v5843[v6013];
    int v5845 = v5843[v6006];
    int v6014 = v5845 + ((int)((unsigned int)(v5845 - v5844) >> 31));
    v5843[v6006] = v6014;
    int * v5847 = v5830->cache_age;
    int v5848 = v5847[v6007];
    int v6016 = v5848 + ((int)((unsigned int)(v5848 - v5844) >> 31));
    v5847[v6007] = v6016;
    int * v5850 = v5830->cache_age;
    v5850[v6013] = 0;
    v5935 = v6013;
  } else {
    int * v5853 = v5830->cache_age;
    int v6020 = (((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2;
    int v5854 = v5853[v6020];
    int * v5855 = v5830->cache_tags;
    int v5856 = v5855[v6020];
    int v5857 = v5853[v6007];
    int v5858 = v5855[v6007];
    bool v6022 = !(((~(((v5839 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5839 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v5912;
    if (v6022) {
      int * v5859 = v5830->cache_age;
      int v6024 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5840 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v5860 = v5859[v6024];
      int v5861 = v5859[v6008];
      int v6025 = v5861 + ((int)((unsigned int)(v5861 - v5860) >> 31));
      v5859[v6008] = v6025;
      int * v5863 = v5830->cache_age;
      int v5864 = v5863[v6009];
      int v6027 = v5864 + ((int)((unsigned int)(v5864 - v5860) >> 31));
      v5863[v6009] = v6027;
      int * v5866 = v5830->cache_age;
      v5866[v6024] = 0;
      v5912 = v6024;
    } else {
      int * v5869 = v5830->cache_age;
      int v6031 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2);
      int v5870 = v5869[v6031];
      int * v5871 = v5830->cache_tags;
      int v5872 = v5871[v6031];
      int v5873 = v5869[v6009];
      int v5874 = v5871[v6009];
      int * v5875 = v5830->cache_dirty;
      int v6034 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5870 + ((~(((v5872 ^ -1) | (-(v5872 ^ -1))) >> 31)) & 2)) - (v5873 + ((~(((v5874 ^ -1) | (-(v5874 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5876 = v5875[v6034];
      bool v6035 = !(v5876 == 0);
      if (v6035) {
        int * v5877 = v5830->cache_tags;
        int v5878 = v5877[v6034];
        int * v5879 = v5830->cache_vals;
        int v6038 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5870 + ((~(((v5872 ^ -1) | (-(v5872 ^ -1))) >> 31)) & 2)) - (v5873 + ((~(((v5874 ^ -1) | (-(v5874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5880 = v5879[v6038];
        int v6039 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5870 + ((~(((v5872 ^ -1) | (-(v5872 ^ -1))) >> 31)) & 2)) - (v5873 + ((~(((v5874 ^ -1) | (-(v5874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5881 = v5879[v6039];
        int * v5882 = v5830->mem;
        int v6041 = v5878 * 2;
        v5882[v6041] = v5880;
        int * v5884 = v5830->mem;
        int v6044 = (v5878 * 2) + 1;
        v5884[v6044] = v5881;
        ;
      } else {
        ;
      }
      int * v5889 = v5830->mem;
      int v6049 = ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) * 2;
      int v5890 = v5889[v6049];
      int v6050 = (((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) * 2) + 1;
      int v5891 = v5889[v6050];
      int * v5892 = v5830->cache_vals;
      int v6052 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5870 + ((~(((v5872 ^ -1) | (-(v5872 ^ -1))) >> 31)) & 2)) - (v5873 + ((~(((v5874 ^ -1) | (-(v5874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5892[v6052] = v5890;
      int * v5894 = v5830->cache_vals;
      int v6055 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5870 + ((~(((v5872 ^ -1) | (-(v5872 ^ -1))) >> 31)) & 2)) - (v5873 + ((~(((v5874 ^ -1) | (-(v5874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5894[v6055] = v5891;
      int * v5896 = v5830->cache_tags;
      int v6058 = (int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1);
      v5896[v6034] = v6058;
      int * v5898 = v5830->cache_dirty;
      v5898[v6034] = 0;
      int * v5900 = v5830->cache_age;
      v5900[v6034] = 1;
      int * v5902 = v5830->cache_age;
      int v5903 = v5902[v6034];
      int v5904 = v5902[v6008];
      int v6064 = v5904 + ((int)((unsigned int)(v5904 - v5903) >> 31));
      v5902[v6008] = v6064;
      int * v5906 = v5830->cache_age;
      int v5907 = v5906[v6009];
      int v6066 = v5907 + ((int)((unsigned int)(v5907 - v5903) >> 31));
      v5906[v6009] = v6066;
      int * v5909 = v5830->cache_age;
      v5909[v6034] = 0;
      v5912 = v6034;
    }
    int * v5913 = v5830->cache_vals;
    int v6069 = v5912 * 2;
    int v5914 = v5913[v6069];
    int v6070 = (v5912 * 2) + 1;
    int v5915 = v5913[v6070];
    int v6071 = (((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5854 + ((~(((v5856 ^ -1) | (-(v5856 ^ -1))) >> 31)) & 2)) - (v5857 + ((~(((v5858 ^ -1) | (-(v5858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5913[v6071] = v5914;
    int * v5917 = v5830->cache_vals;
    int v6074 = ((((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5854 + ((~(((v5856 ^ -1) | (-(v5856 ^ -1))) >> 31)) & 2)) - (v5857 + ((~(((v5858 ^ -1) | (-(v5858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5917[v6074] = v5915;
    int * v5919 = v5830->cache_tags;
    int v6077 = ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5854 + ((~(((v5856 ^ -1) | (-(v5856 ^ -1))) >> 31)) & 2)) - (v5857 + ((~(((v5858 ^ -1) | (-(v5858 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6078 = (int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1);
    v5919[v6077] = v6078;
    int * v5921 = v5830->cache_dirty;
    v5921[v6077] = 0;
    int * v5923 = v5830->cache_age;
    v5923[v6077] = 1;
    int * v5925 = v5830->cache_age;
    int v5926 = v5925[v6077];
    int v5927 = v5925[v6006];
    int v6084 = v5927 + ((int)((unsigned int)(v5927 - v5926) >> 31));
    v5925[v6006] = v6084;
    int * v5929 = v5830->cache_age;
    int v5930 = v5929[v6007];
    int v6086 = v5930 + ((int)((unsigned int)(v5930 - v5926) >> 31));
    v5929[v6007] = v6086;
    int * v5932 = v5830->cache_age;
    v5932[v6077] = 0;
    v5935 = v6077;
  }
  int * v5936 = v5830->cache_vals;
  int v6089 = (v5935 * 2) + (((int)((unsigned int)(v5834 + 24) >> 2)) & 1);
  v5936[v6089] = v5835;
  int * v5938 = v5830->cache_tags;
  int v5939 = v5938[v6008];
  int v5940 = v5938[v6009];
  bool v6092 = !(((~(((v5939 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5939 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5940 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5940 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5994;
  if (v6092) {
    int * v5941 = v5830->cache_age;
    int v6094 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5940 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))) | (-(v5940 ^ ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5942 = v5941[v6094];
    int v5943 = v5941[v6008];
    int v6095 = v5943 + ((int)((unsigned int)(v5943 - v5942) >> 31));
    v5941[v6008] = v6095;
    int * v5945 = v5830->cache_age;
    int v5946 = v5945[v6009];
    int v6097 = v5946 + ((int)((unsigned int)(v5946 - v5942) >> 31));
    v5945[v6009] = v6097;
    int * v5948 = v5830->cache_age;
    v5948[v6094] = 0;
    v5994 = v6094;
  } else {
    int * v5951 = v5830->cache_age;
    int v6101 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2);
    int v5952 = v5951[v6101];
    int * v5953 = v5830->cache_tags;
    int v5954 = v5953[v6101];
    int v5955 = v5951[v6009];
    int v5956 = v5953[v6009];
    int * v5957 = v5830->cache_dirty;
    int v6104 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5952 + ((~(((v5954 ^ -1) | (-(v5954 ^ -1))) >> 31)) & 2)) - (v5955 + ((~(((v5956 ^ -1) | (-(v5956 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5958 = v5957[v6104];
    bool v6105 = !(v5958 == 0);
    if (v6105) {
      int * v5959 = v5830->cache_tags;
      int v5960 = v5959[v6104];
      int * v5961 = v5830->cache_vals;
      int v6108 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5952 + ((~(((v5954 ^ -1) | (-(v5954 ^ -1))) >> 31)) & 2)) - (v5955 + ((~(((v5956 ^ -1) | (-(v5956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5962 = v5961[v6108];
      int v6109 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5952 + ((~(((v5954 ^ -1) | (-(v5954 ^ -1))) >> 31)) & 2)) - (v5955 + ((~(((v5956 ^ -1) | (-(v5956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5963 = v5961[v6109];
      int * v5964 = v5830->mem;
      int v6111 = v5960 * 2;
      v5964[v6111] = v5962;
      int * v5966 = v5830->mem;
      int v6114 = (v5960 * 2) + 1;
      v5966[v6114] = v5963;
      ;
    } else {
      ;
    }
    int * v5971 = v5830->mem;
    int v6119 = ((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) * 2;
    int v5972 = v5971[v6119];
    int v6120 = (((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) * 2) + 1;
    int v5973 = v5971[v6120];
    int * v5974 = v5830->cache_vals;
    int v6122 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5952 + ((~(((v5954 ^ -1) | (-(v5954 ^ -1))) >> 31)) & 2)) - (v5955 + ((~(((v5956 ^ -1) | (-(v5956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5974[v6122] = v5972;
    int * v5976 = v5830->cache_vals;
    int v6125 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5952 + ((~(((v5954 ^ -1) | (-(v5954 ^ -1))) >> 31)) & 2)) - (v5955 + ((~(((v5956 ^ -1) | (-(v5956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5976[v6125] = v5973;
    int * v5978 = v5830->cache_tags;
    int v6128 = (int)((unsigned int)((int)((unsigned int)(v5834 + 24) >> 2)) >> 1);
    v5978[v6104] = v6128;
    int * v5980 = v5830->cache_dirty;
    v5980[v6104] = 0;
    int * v5982 = v5830->cache_age;
    v5982[v6104] = 1;
    int * v5984 = v5830->cache_age;
    int v5985 = v5984[v6104];
    int v5986 = v5984[v6008];
    int v6134 = v5986 + ((int)((unsigned int)(v5986 - v5985) >> 31));
    v5984[v6008] = v6134;
    int * v5988 = v5830->cache_age;
    int v5989 = v5988[v6009];
    int v6136 = v5989 + ((int)((unsigned int)(v5989 - v5985) >> 31));
    v5988[v6009] = v6136;
    int * v5991 = v5830->cache_age;
    v5991[v6104] = 0;
    v5994 = v6104;
  }
  int * v5995 = v5830->cache_vals;
  int v6139 = (v5994 * 2) + (((int)((unsigned int)(v5834 + 24) >> 2)) & 1);
  v5995[v6139] = v5835;
  int * v5997 = v5830->cache_dirty;
  v5997[v5994] = 1;
  struct StateT * v5999 = slot_61(v5830);
  return v5999;
}

struct StateT * slot_4(struct StateT * v818) {
  int v819 = v818->timer;
  int v929 = v819 + 1;
  v818->timer = v929;
  int * v821 = v818->regs;
  int v822 = v821[10];
  int * v823 = v818->cache_tags;
  int v933 = (((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2;
  int v824 = v823[v933];
  int v934 = ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v825 = v823[v934];
  int v935 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2);
  int v826 = v823[v935];
  int v936 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v827 = v823[v936];
  int v828 = v818->timer;
  int v937 = v828 + ((100 ^ (((~(((v826 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v826 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v825 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v825 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v826 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v826 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v818->timer = v937;
  int * v830 = v818->cache_vals;
  bool v938 = !(((~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v825 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v825 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v923;
  if (v938) {
    int * v831 = v818->cache_age;
    int v940 = ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v825 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v825 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v832 = v831[v940];
    int v833 = v831[v933];
    int v941 = v833 + ((int)((unsigned int)(v833 - v832) >> 31));
    v831[v933] = v941;
    int * v835 = v818->cache_age;
    int v836 = v835[v934];
    int v943 = v836 + ((int)((unsigned int)(v836 - v832) >> 31));
    v835[v934] = v943;
    int * v838 = v818->cache_age;
    v838[v940] = 0;
    v923 = v940;
  } else {
    int * v841 = v818->cache_age;
    int v947 = (((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2;
    int v842 = v841[v947];
    int * v843 = v818->cache_tags;
    int v844 = v843[v947];
    int v845 = v841[v934];
    int v846 = v843[v934];
    bool v949 = !(((~(((v826 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v826 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v900;
    if (v949) {
      int * v847 = v818->cache_age;
      int v951 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))) | (-(v827 ^ ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v848 = v847[v951];
      int v849 = v847[v935];
      int v952 = v849 + ((int)((unsigned int)(v849 - v848) >> 31));
      v847[v935] = v952;
      int * v851 = v818->cache_age;
      int v852 = v851[v936];
      int v954 = v852 + ((int)((unsigned int)(v852 - v848) >> 31));
      v851[v936] = v954;
      int * v854 = v818->cache_age;
      v854[v951] = 0;
      v900 = v951;
    } else {
      int * v857 = v818->cache_age;
      int v958 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2);
      int v858 = v857[v958];
      int * v859 = v818->cache_tags;
      int v860 = v859[v958];
      int v861 = v857[v936];
      int v862 = v859[v936];
      int * v863 = v818->cache_dirty;
      int v961 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v864 = v863[v961];
      bool v962 = !(v864 == 0);
      if (v962) {
        int * v865 = v818->cache_tags;
        int v866 = v865[v961];
        int * v867 = v818->cache_vals;
        int v965 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v868 = v867[v965];
        int v966 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v869 = v867[v966];
        int * v870 = v818->mem;
        int v968 = v866 * 2;
        v870[v968] = v868;
        int * v872 = v818->mem;
        int v971 = (v866 * 2) + 1;
        v872[v971] = v869;
        ;
      } else {
        ;
      }
      int * v877 = v818->mem;
      int v976 = ((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) * 2;
      int v878 = v877[v976];
      int v977 = (((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) * 2) + 1;
      int v879 = v877[v977];
      int * v880 = v818->cache_vals;
      int v979 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v880[v979] = v878;
      int * v882 = v818->cache_vals;
      int v982 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v858 + ((~(((v860 ^ -1) | (-(v860 ^ -1))) >> 31)) & 2)) - (v861 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v882[v982] = v879;
      int * v884 = v818->cache_tags;
      int v985 = (int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1);
      v884[v961] = v985;
      int * v886 = v818->cache_dirty;
      v886[v961] = 0;
      int * v888 = v818->cache_age;
      v888[v961] = 1;
      int * v890 = v818->cache_age;
      int v891 = v890[v961];
      int v892 = v890[v935];
      int v991 = v892 + ((int)((unsigned int)(v892 - v891) >> 31));
      v890[v935] = v991;
      int * v894 = v818->cache_age;
      int v895 = v894[v936];
      int v993 = v895 + ((int)((unsigned int)(v895 - v891) >> 31));
      v894[v936] = v993;
      int * v897 = v818->cache_age;
      v897[v961] = 0;
      v900 = v961;
    }
    int * v901 = v818->cache_vals;
    int v996 = v900 * 2;
    int v902 = v901[v996];
    int v997 = (v900 * 2) + 1;
    int v903 = v901[v997];
    int v998 = (((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v845 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v901[v998] = v902;
    int * v905 = v818->cache_vals;
    int v1001 = ((((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v845 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v905[v1001] = v903;
    int * v907 = v818->cache_tags;
    int v1004 = ((((int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v845 + ((~(((v846 ^ -1) | (-(v846 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1005 = (int)((unsigned int)((int)((unsigned int)(v822 + 8) >> 2)) >> 1);
    v907[v1004] = v1005;
    int * v909 = v818->cache_dirty;
    v909[v1004] = 0;
    int * v911 = v818->cache_age;
    v911[v1004] = 1;
    int * v913 = v818->cache_age;
    int v914 = v913[v1004];
    int v915 = v913[v933];
    int v1011 = v915 + ((int)((unsigned int)(v915 - v914) >> 31));
    v913[v933] = v1011;
    int * v917 = v818->cache_age;
    int v918 = v917[v934];
    int v1013 = v918 + ((int)((unsigned int)(v918 - v914) >> 31));
    v917[v934] = v1013;
    int * v920 = v818->cache_age;
    v920[v1004] = 0;
    v923 = v1004;
  }
  int v1016 = (v923 * 2) + (((int)((unsigned int)(v822 + 8) >> 2)) & 1);
  int v924 = v830[v1016];
  int * v925 = v818->regs;
  v925[16] = v924;
  struct StateT * v927 = slot_5(v818);
  return v927;
}

struct StateT * slot_18(struct StateT * v1438) {
  int v1439 = v1438->timer;
  int v1447 = v1439 + 1;
  v1438->timer = v1447;
  int * v1441 = v1438->regs;
  int v1442 = v1441[13];
  int v1443 = v1441[5];
  int v1451 = v1442 + v1443;
  v1441[13] = v1451;
  struct StateT * v1445 = slot_19(v1438);
  return v1445;
}

struct StateT * slot_9(struct StateT * v1283) {
  int v1284 = v1283->timer;
  int v1296 = v1284 + 1;
  v1283->timer = v1296;
  int * v1286 = v1283->regs;
  int v1287 = v1286[5];
  int v1288 = v1286[14];
  bool v1300 = (v1287 ^ -2147483648) < (v1288 ^ -2147483648);
  int v1291;
  if (v1300) {
    v1291 = 1;
  } else {
    v1291 = 0;
  }
  int * v1292 = v1283->regs;
  v1292[14] = v1291;
  struct StateT * v1294 = slot_10(v1283);
  return v1294;
}

struct StateT * slot_11(struct StateT * v1320) {
  int v1321 = v1320->timer;
  int v1328 = v1321 + 1;
  v1320->timer = v1328;
  int * v1323 = v1320->regs;
  int v1324 = v1323[12];
  int v1331 = v1324 + -1;
  v1323[12] = v1331;
  struct StateT * v1326 = slot_12(v1320);
  return v1326;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, 10 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}