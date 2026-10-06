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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v822);
struct StateT * slot_6(struct StateT * v593);
struct StateT * slot_5(struct StateT * v577);
struct StateT * slot_4(struct StateT * v258);
struct StateT * slot_2(struct StateT * v226);
struct StateT * slot_7(struct StateT * v614);
struct StateT * slot_3(struct StateT * v242);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1027 = v1->timer;
  int * v1028 = v1->reg_ready;
  int v1029 = v1028[0];
  int v1160 = v1029 + ((v1027 - v1029) & (~((v1027 - v1029) >> 31)));
  v1->timer = v1160;
  int v1031 = v1->timer;
  int * v1032 = v1->reg_ready;
  int v1033 = v1032[1];
  int v1163 = v1033 + ((v1031 - v1033) & (~((v1031 - v1033) >> 31)));
  v1->timer = v1163;
  int v1035 = v1->timer;
  int * v1036 = v1->reg_ready;
  int v1037 = v1036[2];
  int v1166 = v1037 + ((v1035 - v1037) & (~((v1035 - v1037) >> 31)));
  v1->timer = v1166;
  int v1039 = v1->timer;
  int * v1040 = v1->reg_ready;
  int v1041 = v1040[3];
  int v1169 = v1041 + ((v1039 - v1041) & (~((v1039 - v1041) >> 31)));
  v1->timer = v1169;
  int v1043 = v1->timer;
  int * v1044 = v1->reg_ready;
  int v1045 = v1044[4];
  int v1172 = v1045 + ((v1043 - v1045) & (~((v1043 - v1045) >> 31)));
  v1->timer = v1172;
  int v1047 = v1->timer;
  int * v1048 = v1->reg_ready;
  int v1049 = v1048[5];
  int v1175 = v1049 + ((v1047 - v1049) & (~((v1047 - v1049) >> 31)));
  v1->timer = v1175;
  int v1051 = v1->timer;
  int * v1052 = v1->reg_ready;
  int v1053 = v1052[6];
  int v1178 = v1053 + ((v1051 - v1053) & (~((v1051 - v1053) >> 31)));
  v1->timer = v1178;
  int v1055 = v1->timer;
  int * v1056 = v1->reg_ready;
  int v1057 = v1056[7];
  int v1181 = v1057 + ((v1055 - v1057) & (~((v1055 - v1057) >> 31)));
  v1->timer = v1181;
  int v1059 = v1->timer;
  int * v1060 = v1->reg_ready;
  int v1061 = v1060[8];
  int v1184 = v1061 + ((v1059 - v1061) & (~((v1059 - v1061) >> 31)));
  v1->timer = v1184;
  int v1063 = v1->timer;
  int * v1064 = v1->reg_ready;
  int v1065 = v1064[9];
  int v1187 = v1065 + ((v1063 - v1065) & (~((v1063 - v1065) >> 31)));
  v1->timer = v1187;
  int v1067 = v1->timer;
  int * v1068 = v1->reg_ready;
  int v1069 = v1068[10];
  int v1190 = v1069 + ((v1067 - v1069) & (~((v1067 - v1069) >> 31)));
  v1->timer = v1190;
  int v1071 = v1->timer;
  int * v1072 = v1->reg_ready;
  int v1073 = v1072[11];
  int v1193 = v1073 + ((v1071 - v1073) & (~((v1071 - v1073) >> 31)));
  v1->timer = v1193;
  int v1075 = v1->timer;
  int * v1076 = v1->reg_ready;
  int v1077 = v1076[12];
  int v1196 = v1077 + ((v1075 - v1077) & (~((v1075 - v1077) >> 31)));
  v1->timer = v1196;
  int v1079 = v1->timer;
  int * v1080 = v1->reg_ready;
  int v1081 = v1080[13];
  int v1199 = v1081 + ((v1079 - v1081) & (~((v1079 - v1081) >> 31)));
  v1->timer = v1199;
  int v1083 = v1->timer;
  int * v1084 = v1->reg_ready;
  int v1085 = v1084[14];
  int v1202 = v1085 + ((v1083 - v1085) & (~((v1083 - v1085) >> 31)));
  v1->timer = v1202;
  int v1087 = v1->timer;
  int * v1088 = v1->reg_ready;
  int v1089 = v1088[15];
  int v1205 = v1089 + ((v1087 - v1089) & (~((v1087 - v1089) >> 31)));
  v1->timer = v1205;
  int v1091 = v1->timer;
  int * v1092 = v1->reg_ready;
  int v1093 = v1092[16];
  int v1208 = v1093 + ((v1091 - v1093) & (~((v1091 - v1093) >> 31)));
  v1->timer = v1208;
  int v1095 = v1->timer;
  int * v1096 = v1->reg_ready;
  int v1097 = v1096[17];
  int v1211 = v1097 + ((v1095 - v1097) & (~((v1095 - v1097) >> 31)));
  v1->timer = v1211;
  int v1099 = v1->timer;
  int * v1100 = v1->reg_ready;
  int v1101 = v1100[18];
  int v1214 = v1101 + ((v1099 - v1101) & (~((v1099 - v1101) >> 31)));
  v1->timer = v1214;
  int v1103 = v1->timer;
  int * v1104 = v1->reg_ready;
  int v1105 = v1104[19];
  int v1217 = v1105 + ((v1103 - v1105) & (~((v1103 - v1105) >> 31)));
  v1->timer = v1217;
  int v1107 = v1->timer;
  int * v1108 = v1->reg_ready;
  int v1109 = v1108[20];
  int v1220 = v1109 + ((v1107 - v1109) & (~((v1107 - v1109) >> 31)));
  v1->timer = v1220;
  int v1111 = v1->timer;
  int * v1112 = v1->reg_ready;
  int v1113 = v1112[21];
  int v1223 = v1113 + ((v1111 - v1113) & (~((v1111 - v1113) >> 31)));
  v1->timer = v1223;
  int v1115 = v1->timer;
  int * v1116 = v1->reg_ready;
  int v1117 = v1116[22];
  int v1226 = v1117 + ((v1115 - v1117) & (~((v1115 - v1117) >> 31)));
  v1->timer = v1226;
  int v1119 = v1->timer;
  int * v1120 = v1->reg_ready;
  int v1121 = v1120[23];
  int v1229 = v1121 + ((v1119 - v1121) & (~((v1119 - v1121) >> 31)));
  v1->timer = v1229;
  int v1123 = v1->timer;
  int * v1124 = v1->reg_ready;
  int v1125 = v1124[24];
  int v1232 = v1125 + ((v1123 - v1125) & (~((v1123 - v1125) >> 31)));
  v1->timer = v1232;
  int v1127 = v1->timer;
  int * v1128 = v1->reg_ready;
  int v1129 = v1128[25];
  int v1235 = v1129 + ((v1127 - v1129) & (~((v1127 - v1129) >> 31)));
  v1->timer = v1235;
  int v1131 = v1->timer;
  int * v1132 = v1->reg_ready;
  int v1133 = v1132[26];
  int v1238 = v1133 + ((v1131 - v1133) & (~((v1131 - v1133) >> 31)));
  v1->timer = v1238;
  int v1135 = v1->timer;
  int * v1136 = v1->reg_ready;
  int v1137 = v1136[27];
  int v1241 = v1137 + ((v1135 - v1137) & (~((v1135 - v1137) >> 31)));
  v1->timer = v1241;
  int v1139 = v1->timer;
  int * v1140 = v1->reg_ready;
  int v1141 = v1140[28];
  int v1244 = v1141 + ((v1139 - v1141) & (~((v1139 - v1141) >> 31)));
  v1->timer = v1244;
  int v1143 = v1->timer;
  int * v1144 = v1->reg_ready;
  int v1145 = v1144[29];
  int v1247 = v1145 + ((v1143 - v1145) & (~((v1143 - v1145) >> 31)));
  v1->timer = v1247;
  int v1147 = v1->timer;
  int * v1148 = v1->reg_ready;
  int v1149 = v1148[30];
  int v1250 = v1149 + ((v1147 - v1149) & (~((v1147 - v1149) >> 31)));
  v1->timer = v1250;
  int v1151 = v1->timer;
  int * v1152 = v1->reg_ready;
  int v1153 = v1152[31];
  int v1253 = v1153 + ((v1151 - v1153) & (~((v1151 - v1153) >> 31)));
  v1->timer = v1253;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[6];
  int * v23 = v18->regs;
  int v24 = v23[6];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v221 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[5] = v221;
  int * v127 = v18->regs;
  v127[5] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v822) {
  int v823 = v822->timer;
  int v934 = v823 + 1;
  v822->timer = v934;
  int * v825 = v822->reg_ready;
  int v826 = v825[11];
  int * v827 = v822->regs;
  int v828 = v827[11];
  int * v829 = v822->cache_tags;
  int v939 = (((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2;
  int v830 = v829[v939];
  int v940 = ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2) + 1;
  int v831 = v829[v940];
  int v941 = 4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2);
  int v832 = v829[v941];
  int v942 = (4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v833 = v829[v942];
  int * v834 = v822->cache_vals;
  bool v943 = !(((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) | (~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31))) == 0);
  int v927;
  if (v943) {
    int * v835 = v822->cache_age;
    int v945 = ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2) + ((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) & 1);
    int v836 = v835[v945];
    int v837 = v835[v939];
    int v946 = v837 + ((int)((unsigned int)(v837 - v836) >> 31));
    v835[v939] = v946;
    int * v839 = v822->cache_age;
    int v840 = v839[v940];
    int v948 = v840 + ((int)((unsigned int)(v840 - v836) >> 31));
    v839[v940] = v948;
    int * v842 = v822->cache_age;
    v842[v945] = 0;
    v927 = v945;
  } else {
    int * v845 = v822->cache_age;
    int v952 = (((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2;
    int v846 = v845[v952];
    int * v847 = v822->cache_tags;
    int v848 = v847[v952];
    int v849 = v845[v940];
    int v850 = v847[v940];
    bool v954 = !(((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) | (~(((v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31))) == 0);
    int v904;
    if (v954) {
      int * v851 = v822->cache_age;
      int v956 = (4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + ((~(((v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) & 1);
      int v852 = v851[v956];
      int v853 = v851[v941];
      int v957 = v853 + ((int)((unsigned int)(v853 - v852) >> 31));
      v851[v941] = v957;
      int * v855 = v822->cache_age;
      int v856 = v855[v942];
      int v959 = v856 + ((int)((unsigned int)(v856 - v852) >> 31));
      v855[v942] = v959;
      int * v858 = v822->cache_age;
      v858[v956] = 0;
      v904 = v956;
    } else {
      int * v861 = v822->cache_age;
      int v963 = 4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2);
      int v862 = v861[v963];
      int * v863 = v822->cache_tags;
      int v864 = v863[v963];
      int v865 = v861[v942];
      int v866 = v863[v942];
      int * v867 = v822->cache_dirty;
      int v966 = (4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + ((((v862 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2)) - (v865 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v868 = v867[v966];
      bool v967 = !(v868 == 0);
      if (v967) {
        int * v869 = v822->cache_tags;
        int v870 = v869[v966];
        int * v871 = v822->cache_vals;
        int v970 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + ((((v862 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2)) - (v865 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v872 = v871[v970];
        int v971 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + ((((v862 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2)) - (v865 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v873 = v871[v971];
        int * v874 = v822->mem;
        int v973 = v870 * 2;
        v874[v973] = v872;
        int * v876 = v822->mem;
        int v976 = (v870 * 2) + 1;
        v876[v976] = v873;
        ;
      } else {
        ;
      }
      int * v881 = v822->mem;
      int v981 = ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) * 2;
      int v882 = v881[v981];
      int v982 = (((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) * 2) + 1;
      int v883 = v881[v982];
      int * v884 = v822->cache_vals;
      int v984 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + ((((v862 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2)) - (v865 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v884[v984] = v882;
      int * v886 = v822->cache_vals;
      int v987 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 3) * 2)) + ((((v862 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2)) - (v865 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v886[v987] = v883;
      int * v888 = v822->cache_tags;
      int v990 = (int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1);
      v888[v966] = v990;
      int * v890 = v822->cache_dirty;
      v890[v966] = 0;
      int * v892 = v822->cache_age;
      v892[v966] = 1;
      int * v894 = v822->cache_age;
      int v895 = v894[v966];
      int v896 = v894[v941];
      int v996 = v896 + ((int)((unsigned int)(v896 - v895) >> 31));
      v894[v941] = v996;
      int * v898 = v822->cache_age;
      int v899 = v898[v942];
      int v998 = v899 + ((int)((unsigned int)(v899 - v895) >> 31));
      v898[v942] = v998;
      int * v901 = v822->cache_age;
      v901[v966] = 0;
      v904 = v966;
    }
    int * v905 = v822->cache_vals;
    int v1001 = v904 * 2;
    int v906 = v905[v1001];
    int v1002 = (v904 * 2) + 1;
    int v907 = v905[v1002];
    int v1003 = (((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v905[v1003] = v906;
    int * v909 = v822->cache_vals;
    int v1006 = ((((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v909[v1006] = v907;
    int * v911 = v822->cache_tags;
    int v1009 = ((((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1)) & 1) * 2) + ((((v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2)) - (v849 + ((~(((v850 ^ -1) | (-(v850 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1010 = (int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1);
    v911[v1009] = v1010;
    int * v913 = v822->cache_dirty;
    v913[v1009] = 0;
    int * v915 = v822->cache_age;
    v915[v1009] = 1;
    int * v917 = v822->cache_age;
    int v918 = v917[v1009];
    int v919 = v917[v939];
    int v1016 = v919 + ((int)((unsigned int)(v919 - v918) >> 31));
    v917[v939] = v1016;
    int * v921 = v822->cache_age;
    int v922 = v921[v940];
    int v1018 = v922 + ((int)((unsigned int)(v922 - v918) >> 31));
    v921[v940] = v1018;
    int * v924 = v822->cache_age;
    v924[v1009] = 0;
    v927 = v1009;
  }
  int v1021 = (v927 * 2) + (((int)((unsigned int)v828 >> 2)) & 1);
  int v928 = v834[v1021];
  int * v929 = v822->reg_ready;
  int v1024 = ((v826 + ((v823 - v826) & (~((v823 - v826) >> 31)))) + 1) + ((100 ^ (((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) | (~(((v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) | (~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31)) | (~(((v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))) | (-(v833 ^ ((int)((unsigned int)((int)((unsigned int)v828 >> 2)) >> 1))))) >> 31))) & 104)))));
  v929[12] = v1024;
  int * v931 = v822->regs;
  v931[12] = v928;
  return v822;
}

struct StateT * slot_6(struct StateT * v593) {
  int v594 = v593->timer;
  int v605 = v594 + 1;
  v593->timer = v605;
  int * v596 = v593->reg_ready;
  int v597 = v596[7];
  int * v598 = v593->regs;
  int v599 = v598[7];
  int v609 = (v597 + ((v594 - v597) & (~((v594 - v597) >> 31)))) + 1;
  v596[7] = v609;
  int * v601 = v593->regs;
  int v611 = v599 + 1;
  v601[7] = v611;
  struct StateT * v603 = slot_7(v593);
  return v603;
}

struct StateT * slot_5(struct StateT * v577) {
  int v578 = v577->timer;
  int v586 = v578 + 1;
  v577->timer = v586;
  int * v580 = v577->reg_ready;
  v580[7] = v586;
  int * v582 = v577->regs;
  v582[7] = 0;
  struct StateT * v584 = slot_6(v577);
  return v584;
}

struct StateT * slot_4(struct StateT * v258) {
  int v259 = v258->timer;
  int v432 = v259 + 1;
  v258->timer = v432;
  int * v261 = v258->reg_ready;
  int * v263 = v258->regs;
  int v264 = v263[8];
  int v266 = v263[5];
  int * v267 = v258->cache_tags;
  int v438 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2;
  int v268 = v267[v438];
  int v439 = ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + 1;
  int v269 = v267[v439];
  int v440 = 4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2);
  int v270 = v267[v440];
  int v441 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v271 = v267[v441];
  int v272 = v258->timer;
  int v442 = v272 + ((100 ^ (((~(((v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v269 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v269 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) & 104)))));
  v258->timer = v442;
  bool v443 = !(((~(((v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v268 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v269 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v269 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) == 0);
  int v366;
  if (v443) {
    int * v274 = v258->cache_age;
    int v445 = ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((~(((v269 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v269 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) & 1);
    int v275 = v274[v445];
    int v276 = v274[v438];
    int v446 = v276 + ((int)((unsigned int)(v276 - v275) >> 31));
    v274[v438] = v446;
    int * v278 = v258->cache_age;
    int v279 = v278[v439];
    int v448 = v279 + ((int)((unsigned int)(v279 - v275) >> 31));
    v278[v439] = v448;
    int * v281 = v258->cache_age;
    v281[v445] = 0;
    v366 = v445;
  } else {
    int * v284 = v258->cache_age;
    int v452 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2;
    int v285 = v284[v452];
    int * v286 = v258->cache_tags;
    int v287 = v286[v452];
    int v288 = v284[v439];
    int v289 = v286[v439];
    bool v454 = !(((~(((v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v270 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) == 0);
    int v343;
    if (v454) {
      int * v290 = v258->cache_age;
      int v456 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) & 1);
      int v291 = v290[v456];
      int v292 = v290[v440];
      int v457 = v292 + ((int)((unsigned int)(v292 - v291) >> 31));
      v290[v440] = v457;
      int * v294 = v258->cache_age;
      int v295 = v294[v441];
      int v459 = v295 + ((int)((unsigned int)(v295 - v291) >> 31));
      v294[v441] = v459;
      int * v297 = v258->cache_age;
      v297[v456] = 0;
      v343 = v456;
    } else {
      int * v300 = v258->cache_age;
      int v463 = 4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2);
      int v301 = v300[v463];
      int * v302 = v258->cache_tags;
      int v303 = v302[v463];
      int v304 = v300[v441];
      int v305 = v302[v441];
      int * v306 = v258->cache_dirty;
      int v466 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v307 = v306[v466];
      bool v467 = !(v307 == 0);
      if (v467) {
        int * v308 = v258->cache_tags;
        int v309 = v308[v466];
        int * v310 = v258->cache_vals;
        int v470 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v311 = v310[v470];
        int v471 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v312 = v310[v471];
        int * v313 = v258->mem;
        int v473 = v309 * 2;
        v313[v473] = v311;
        int * v315 = v258->mem;
        int v476 = (v309 * 2) + 1;
        v315[v476] = v312;
        ;
      } else {
        ;
      }
      int * v320 = v258->mem;
      int v481 = ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) * 2;
      int v321 = v320[v481];
      int v482 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) * 2) + 1;
      int v322 = v320[v482];
      int * v323 = v258->cache_vals;
      int v484 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v323[v484] = v321;
      int * v325 = v258->cache_vals;
      int v487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v301 + ((~(((v303 ^ -1) | (-(v303 ^ -1))) >> 31)) & 2)) - (v304 + ((~(((v305 ^ -1) | (-(v305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v325[v487] = v322;
      int * v327 = v258->cache_tags;
      int v490 = (int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1);
      v327[v466] = v490;
      int * v329 = v258->cache_dirty;
      v329[v466] = 0;
      int * v331 = v258->cache_age;
      v331[v466] = 1;
      int * v333 = v258->cache_age;
      int v334 = v333[v466];
      int v335 = v333[v440];
      int v496 = v335 + ((int)((unsigned int)(v335 - v334) >> 31));
      v333[v440] = v496;
      int * v337 = v258->cache_age;
      int v338 = v337[v441];
      int v498 = v338 + ((int)((unsigned int)(v338 - v334) >> 31));
      v337[v441] = v498;
      int * v340 = v258->cache_age;
      v340[v466] = 0;
      v343 = v466;
    }
    int * v344 = v258->cache_vals;
    int v501 = v343 * 2;
    int v345 = v344[v501];
    int v502 = (v343 * 2) + 1;
    int v346 = v344[v502];
    int v503 = (((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v344[v503] = v345;
    int * v348 = v258->cache_vals;
    int v506 = ((((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v348[v506] = v346;
    int * v350 = v258->cache_tags;
    int v509 = ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 1) * 2) + ((((v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2)) - (v288 + ((~(((v289 ^ -1) | (-(v289 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v510 = (int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1);
    v350[v509] = v510;
    int * v352 = v258->cache_dirty;
    v352[v509] = 0;
    int * v354 = v258->cache_age;
    v354[v509] = 1;
    int * v356 = v258->cache_age;
    int v357 = v356[v509];
    int v358 = v356[v438];
    int v516 = v358 + ((int)((unsigned int)(v358 - v357) >> 31));
    v356[v438] = v516;
    int * v360 = v258->cache_age;
    int v361 = v360[v439];
    int v518 = v361 + ((int)((unsigned int)(v361 - v357) >> 31));
    v360[v439] = v518;
    int * v363 = v258->cache_age;
    v363[v509] = 0;
    v366 = v509;
  }
  int * v367 = v258->cache_vals;
  int v521 = (v366 * 2) + (((int)((unsigned int)v264 >> 2)) & 1);
  v367[v521] = v266;
  int * v369 = v258->cache_tags;
  int v370 = v369[v440];
  int v371 = v369[v441];
  bool v524 = !(((~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) | (~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31))) == 0);
  int v425;
  if (v524) {
    int * v372 = v258->cache_age;
    int v526 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1))))) >> 31)) & 1);
    int v373 = v372[v526];
    int v374 = v372[v440];
    int v527 = v374 + ((int)((unsigned int)(v374 - v373) >> 31));
    v372[v440] = v527;
    int * v376 = v258->cache_age;
    int v377 = v376[v441];
    int v529 = v377 + ((int)((unsigned int)(v377 - v373) >> 31));
    v376[v441] = v529;
    int * v379 = v258->cache_age;
    v379[v526] = 0;
    v425 = v526;
  } else {
    int * v382 = v258->cache_age;
    int v533 = 4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2);
    int v383 = v382[v533];
    int * v384 = v258->cache_tags;
    int v385 = v384[v533];
    int v386 = v382[v441];
    int v387 = v384[v441];
    int * v388 = v258->cache_dirty;
    int v536 = (4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v389 = v388[v536];
    bool v537 = !(v389 == 0);
    if (v537) {
      int * v390 = v258->cache_tags;
      int v391 = v390[v536];
      int * v392 = v258->cache_vals;
      int v540 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v393 = v392[v540];
      int v541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v394 = v392[v541];
      int * v395 = v258->mem;
      int v543 = v391 * 2;
      v395[v543] = v393;
      int * v397 = v258->mem;
      int v546 = (v391 * 2) + 1;
      v397[v546] = v394;
      ;
    } else {
      ;
    }
    int * v402 = v258->mem;
    int v551 = ((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) * 2;
    int v403 = v402[v551];
    int v552 = (((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) * 2) + 1;
    int v404 = v402[v552];
    int * v405 = v258->cache_vals;
    int v554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v405[v554] = v403;
    int * v407 = v258->cache_vals;
    int v557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1)) & 3) * 2)) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v407[v557] = v404;
    int * v409 = v258->cache_tags;
    int v560 = (int)((unsigned int)((int)((unsigned int)v264 >> 2)) >> 1);
    v409[v536] = v560;
    int * v411 = v258->cache_dirty;
    v411[v536] = 0;
    int * v413 = v258->cache_age;
    v413[v536] = 1;
    int * v415 = v258->cache_age;
    int v416 = v415[v536];
    int v417 = v415[v440];
    int v566 = v417 + ((int)((unsigned int)(v417 - v416) >> 31));
    v415[v440] = v566;
    int * v419 = v258->cache_age;
    int v420 = v419[v441];
    int v568 = v420 + ((int)((unsigned int)(v420 - v416) >> 31));
    v419[v441] = v568;
    int * v422 = v258->cache_age;
    v422[v536] = 0;
    v425 = v536;
  }
  int * v426 = v258->cache_vals;
  int v571 = (v425 * 2) + (((int)((unsigned int)v264 >> 2)) & 1);
  v426[v571] = v266;
  int * v428 = v258->cache_dirty;
  v428[v425] = 1;
  struct StateT * v430 = slot_5(v258);
  return v430;
}

struct StateT * slot_2(struct StateT * v226) {
  int v227 = v226->timer;
  int v235 = v227 + 1;
  v226->timer = v235;
  int * v229 = v226->reg_ready;
  v229[8] = v235;
  int * v231 = v226->regs;
  v231[8] = 96;
  struct StateT * v233 = slot_3(v226);
  return v233;
}

struct StateT * slot_7(struct StateT * v614) {
  int v615 = v614->timer;
  int v727 = v615 + 1;
  v614->timer = v727;
  int * v617 = v614->reg_ready;
  int v618 = v617[9];
  int * v619 = v614->regs;
  int v620 = v619[9];
  int * v621 = v614->cache_tags;
  int v732 = (((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2;
  int v622 = v621[v732];
  int v733 = ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + 1;
  int v623 = v621[v733];
  int v734 = 4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2);
  int v624 = v621[v734];
  int v735 = (4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v625 = v621[v735];
  int * v626 = v614->cache_vals;
  bool v736 = !(((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) == 0);
  int v719;
  if (v736) {
    int * v627 = v614->cache_age;
    int v738 = ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) & 1);
    int v628 = v627[v738];
    int v629 = v627[v732];
    int v739 = v629 + ((int)((unsigned int)(v629 - v628) >> 31));
    v627[v732] = v739;
    int * v631 = v614->cache_age;
    int v632 = v631[v733];
    int v741 = v632 + ((int)((unsigned int)(v632 - v628) >> 31));
    v631[v733] = v741;
    int * v634 = v614->cache_age;
    v634[v738] = 0;
    v719 = v738;
  } else {
    int * v637 = v614->cache_age;
    int v745 = (((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2;
    int v638 = v637[v745];
    int * v639 = v614->cache_tags;
    int v640 = v639[v745];
    int v641 = v637[v733];
    int v642 = v639[v733];
    bool v747 = !(((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) == 0);
    int v696;
    if (v747) {
      int * v643 = v614->cache_age;
      int v749 = (4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) & 1);
      int v644 = v643[v749];
      int v645 = v643[v734];
      int v750 = v645 + ((int)((unsigned int)(v645 - v644) >> 31));
      v643[v734] = v750;
      int * v647 = v614->cache_age;
      int v648 = v647[v735];
      int v752 = v648 + ((int)((unsigned int)(v648 - v644) >> 31));
      v647[v735] = v752;
      int * v650 = v614->cache_age;
      v650[v749] = 0;
      v696 = v749;
    } else {
      int * v653 = v614->cache_age;
      int v756 = 4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2);
      int v654 = v653[v756];
      int * v655 = v614->cache_tags;
      int v656 = v655[v756];
      int v657 = v653[v735];
      int v658 = v655[v735];
      int * v659 = v614->cache_dirty;
      int v759 = (4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v660 = v659[v759];
      bool v760 = !(v660 == 0);
      if (v760) {
        int * v661 = v614->cache_tags;
        int v662 = v661[v759];
        int * v663 = v614->cache_vals;
        int v763 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v664 = v663[v763];
        int v764 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v665 = v663[v764];
        int * v666 = v614->mem;
        int v766 = v662 * 2;
        v666[v766] = v664;
        int * v668 = v614->mem;
        int v769 = (v662 * 2) + 1;
        v668[v769] = v665;
        ;
      } else {
        ;
      }
      int * v673 = v614->mem;
      int v774 = ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) * 2;
      int v674 = v673[v774];
      int v775 = (((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) * 2) + 1;
      int v675 = v673[v775];
      int * v676 = v614->cache_vals;
      int v777 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v676[v777] = v674;
      int * v678 = v614->cache_vals;
      int v780 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 3) * 2)) + ((((v654 + ((~(((v656 ^ -1) | (-(v656 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v658 ^ -1) | (-(v658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v678[v780] = v675;
      int * v680 = v614->cache_tags;
      int v783 = (int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1);
      v680[v759] = v783;
      int * v682 = v614->cache_dirty;
      v682[v759] = 0;
      int * v684 = v614->cache_age;
      v684[v759] = 1;
      int * v686 = v614->cache_age;
      int v687 = v686[v759];
      int v688 = v686[v734];
      int v789 = v688 + ((int)((unsigned int)(v688 - v687) >> 31));
      v686[v734] = v789;
      int * v690 = v614->cache_age;
      int v691 = v690[v735];
      int v791 = v691 + ((int)((unsigned int)(v691 - v687) >> 31));
      v690[v735] = v791;
      int * v693 = v614->cache_age;
      v693[v759] = 0;
      v696 = v759;
    }
    int * v697 = v614->cache_vals;
    int v794 = v696 * 2;
    int v698 = v697[v794];
    int v795 = (v696 * 2) + 1;
    int v699 = v697[v795];
    int v796 = (((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v697[v796] = v698;
    int * v701 = v614->cache_vals;
    int v799 = ((((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v701[v799] = v699;
    int * v703 = v614->cache_tags;
    int v802 = ((((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1)) & 1) * 2) + ((((v638 + ((~(((v640 ^ -1) | (-(v640 ^ -1))) >> 31)) & 2)) - (v641 + ((~(((v642 ^ -1) | (-(v642 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v803 = (int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1);
    v703[v802] = v803;
    int * v705 = v614->cache_dirty;
    v705[v802] = 0;
    int * v707 = v614->cache_age;
    v707[v802] = 1;
    int * v709 = v614->cache_age;
    int v710 = v709[v802];
    int v711 = v709[v732];
    int v809 = v711 + ((int)((unsigned int)(v711 - v710) >> 31));
    v709[v732] = v809;
    int * v713 = v614->cache_age;
    int v714 = v713[v733];
    int v811 = v714 + ((int)((unsigned int)(v714 - v710) >> 31));
    v713[v733] = v811;
    int * v716 = v614->cache_age;
    v716[v802] = 0;
    v719 = v802;
  }
  int v814 = (v719 * 2) + (((int)((unsigned int)v620 >> 2)) & 1);
  int v720 = v626[v814];
  int * v721 = v614->reg_ready;
  int v817 = ((v618 + ((v615 - v618) & (~((v615 - v618) >> 31)))) + 1) + ((100 ^ (((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v623 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v624 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31)) | (~(((v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))) | (-(v625 ^ ((int)((unsigned int)((int)((unsigned int)v620 >> 2)) >> 1))))) >> 31))) & 104)))));
  v721[11] = v817;
  int * v723 = v614->regs;
  v723[11] = v720;
  struct StateT * v725 = slot_8(v614);
  return v725;
}

struct StateT * slot_3(struct StateT * v242) {
  int v243 = v242->timer;
  int v251 = v243 + 1;
  v242->timer = v251;
  int * v245 = v242->reg_ready;
  v245[9] = v251;
  int * v247 = v242->regs;
  v247[9] = 0;
  struct StateT * v249 = slot_4(v242);
  return v249;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[6] = v11;
  int * v7 = v2->regs;
  v7[6] = 80;
  struct StateT * v9 = slot_1(v2);
  return v9;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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