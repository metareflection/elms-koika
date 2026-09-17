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
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v27);
struct StateT * slot_8(struct StateT * v787);
struct StateT * slot_6(struct StateT * v508);
struct StateT * slot_5(struct StateT * v116);
struct StateT * slot_4(struct StateT * v98);
struct StateT * slot_2(struct StateT * v45);
struct StateT * slot_7(struct StateT * v763);
struct StateT * slot_3(struct StateT * v73);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1039 = v1->timer;
  int * v1040 = v1->reg_ready;
  int v1041 = v1040[0];
  int v1172 = v1041 + ((v1039 - v1041) & (~((v1039 - v1041) >> 31)));
  v1->timer = v1172;
  int v1043 = v1->timer;
  int * v1044 = v1->reg_ready;
  int v1045 = v1044[1];
  int v1175 = v1045 + ((v1043 - v1045) & (~((v1043 - v1045) >> 31)));
  v1->timer = v1175;
  int v1047 = v1->timer;
  int * v1048 = v1->reg_ready;
  int v1049 = v1048[2];
  int v1178 = v1049 + ((v1047 - v1049) & (~((v1047 - v1049) >> 31)));
  v1->timer = v1178;
  int v1051 = v1->timer;
  int * v1052 = v1->reg_ready;
  int v1053 = v1052[3];
  int v1181 = v1053 + ((v1051 - v1053) & (~((v1051 - v1053) >> 31)));
  v1->timer = v1181;
  int v1055 = v1->timer;
  int * v1056 = v1->reg_ready;
  int v1057 = v1056[4];
  int v1184 = v1057 + ((v1055 - v1057) & (~((v1055 - v1057) >> 31)));
  v1->timer = v1184;
  int v1059 = v1->timer;
  int * v1060 = v1->reg_ready;
  int v1061 = v1060[5];
  int v1187 = v1061 + ((v1059 - v1061) & (~((v1059 - v1061) >> 31)));
  v1->timer = v1187;
  int v1063 = v1->timer;
  int * v1064 = v1->reg_ready;
  int v1065 = v1064[6];
  int v1190 = v1065 + ((v1063 - v1065) & (~((v1063 - v1065) >> 31)));
  v1->timer = v1190;
  int v1067 = v1->timer;
  int * v1068 = v1->reg_ready;
  int v1069 = v1068[7];
  int v1193 = v1069 + ((v1067 - v1069) & (~((v1067 - v1069) >> 31)));
  v1->timer = v1193;
  int v1071 = v1->timer;
  int * v1072 = v1->reg_ready;
  int v1073 = v1072[8];
  int v1196 = v1073 + ((v1071 - v1073) & (~((v1071 - v1073) >> 31)));
  v1->timer = v1196;
  int v1075 = v1->timer;
  int * v1076 = v1->reg_ready;
  int v1077 = v1076[9];
  int v1199 = v1077 + ((v1075 - v1077) & (~((v1075 - v1077) >> 31)));
  v1->timer = v1199;
  int v1079 = v1->timer;
  int * v1080 = v1->reg_ready;
  int v1081 = v1080[10];
  int v1202 = v1081 + ((v1079 - v1081) & (~((v1079 - v1081) >> 31)));
  v1->timer = v1202;
  int v1083 = v1->timer;
  int * v1084 = v1->reg_ready;
  int v1085 = v1084[11];
  int v1205 = v1085 + ((v1083 - v1085) & (~((v1083 - v1085) >> 31)));
  v1->timer = v1205;
  int v1087 = v1->timer;
  int * v1088 = v1->reg_ready;
  int v1089 = v1088[12];
  int v1208 = v1089 + ((v1087 - v1089) & (~((v1087 - v1089) >> 31)));
  v1->timer = v1208;
  int v1091 = v1->timer;
  int * v1092 = v1->reg_ready;
  int v1093 = v1092[13];
  int v1211 = v1093 + ((v1091 - v1093) & (~((v1091 - v1093) >> 31)));
  v1->timer = v1211;
  int v1095 = v1->timer;
  int * v1096 = v1->reg_ready;
  int v1097 = v1096[14];
  int v1214 = v1097 + ((v1095 - v1097) & (~((v1095 - v1097) >> 31)));
  v1->timer = v1214;
  int v1099 = v1->timer;
  int * v1100 = v1->reg_ready;
  int v1101 = v1100[15];
  int v1217 = v1101 + ((v1099 - v1101) & (~((v1099 - v1101) >> 31)));
  v1->timer = v1217;
  int v1103 = v1->timer;
  int * v1104 = v1->reg_ready;
  int v1105 = v1104[16];
  int v1220 = v1105 + ((v1103 - v1105) & (~((v1103 - v1105) >> 31)));
  v1->timer = v1220;
  int v1107 = v1->timer;
  int * v1108 = v1->reg_ready;
  int v1109 = v1108[17];
  int v1223 = v1109 + ((v1107 - v1109) & (~((v1107 - v1109) >> 31)));
  v1->timer = v1223;
  int v1111 = v1->timer;
  int * v1112 = v1->reg_ready;
  int v1113 = v1112[18];
  int v1226 = v1113 + ((v1111 - v1113) & (~((v1111 - v1113) >> 31)));
  v1->timer = v1226;
  int v1115 = v1->timer;
  int * v1116 = v1->reg_ready;
  int v1117 = v1116[19];
  int v1229 = v1117 + ((v1115 - v1117) & (~((v1115 - v1117) >> 31)));
  v1->timer = v1229;
  int v1119 = v1->timer;
  int * v1120 = v1->reg_ready;
  int v1121 = v1120[20];
  int v1232 = v1121 + ((v1119 - v1121) & (~((v1119 - v1121) >> 31)));
  v1->timer = v1232;
  int v1123 = v1->timer;
  int * v1124 = v1->reg_ready;
  int v1125 = v1124[21];
  int v1235 = v1125 + ((v1123 - v1125) & (~((v1123 - v1125) >> 31)));
  v1->timer = v1235;
  int v1127 = v1->timer;
  int * v1128 = v1->reg_ready;
  int v1129 = v1128[22];
  int v1238 = v1129 + ((v1127 - v1129) & (~((v1127 - v1129) >> 31)));
  v1->timer = v1238;
  int v1131 = v1->timer;
  int * v1132 = v1->reg_ready;
  int v1133 = v1132[23];
  int v1241 = v1133 + ((v1131 - v1133) & (~((v1131 - v1133) >> 31)));
  v1->timer = v1241;
  int v1135 = v1->timer;
  int * v1136 = v1->reg_ready;
  int v1137 = v1136[24];
  int v1244 = v1137 + ((v1135 - v1137) & (~((v1135 - v1137) >> 31)));
  v1->timer = v1244;
  int v1139 = v1->timer;
  int * v1140 = v1->reg_ready;
  int v1141 = v1140[25];
  int v1247 = v1141 + ((v1139 - v1141) & (~((v1139 - v1141) >> 31)));
  v1->timer = v1247;
  int v1143 = v1->timer;
  int * v1144 = v1->reg_ready;
  int v1145 = v1144[26];
  int v1250 = v1145 + ((v1143 - v1145) & (~((v1143 - v1145) >> 31)));
  v1->timer = v1250;
  int v1147 = v1->timer;
  int * v1148 = v1->reg_ready;
  int v1149 = v1148[27];
  int v1253 = v1149 + ((v1147 - v1149) & (~((v1147 - v1149) >> 31)));
  v1->timer = v1253;
  int v1151 = v1->timer;
  int * v1152 = v1->reg_ready;
  int v1153 = v1152[28];
  int v1256 = v1153 + ((v1151 - v1153) & (~((v1151 - v1153) >> 31)));
  v1->timer = v1256;
  int v1155 = v1->timer;
  int * v1156 = v1->reg_ready;
  int v1157 = v1156[29];
  int v1259 = v1157 + ((v1155 - v1157) & (~((v1155 - v1157) >> 31)));
  v1->timer = v1259;
  int v1159 = v1->timer;
  int * v1160 = v1->reg_ready;
  int v1161 = v1160[30];
  int v1262 = v1161 + ((v1159 - v1161) & (~((v1159 - v1161) >> 31)));
  v1->timer = v1262;
  int v1163 = v1->timer;
  int * v1164 = v1->reg_ready;
  int v1165 = v1164[31];
  int v1265 = v1165 + ((v1163 - v1165) & (~((v1163 - v1165) >> 31)));
  v1->timer = v1265;
  return v1;
}

struct StateT * slot_1(struct StateT * v27) {
  int v28 = v27->timer;
  int v29 = v27->timer;
  int v37 = v29 + 1;
  v27->timer = v37;
  int * v31 = v27->reg_ready;
  int v40 = v28 + 1;
  v31[9] = v40;
  int * v33 = v27->regs;
  v33[9] = 32;
  struct StateT * v35 = slot_2(v27);
  return v35;
}

struct StateT * slot_8(struct StateT * v787) {
  int v788 = v787->timer;
  int v789 = v787->timer;
  int v923 = v789 + 1;
  v787->timer = v923;
  int * v791 = v787->reg_ready;
  int v792 = v791[11];
  int * v793 = v787->regs;
  int v794 = v793[11];
  int * v795 = v787->cache_tags;
  int v928 = (((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2;
  int v796 = v795[v928];
  int * v797 = v787->cache_tags;
  int v930 = ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2) + 1;
  int v798 = v797[v930];
  int * v799 = v787->cache_tags;
  int v932 = 4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2);
  int v800 = v799[v932];
  int * v801 = v787->cache_tags;
  int v934 = (4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v802 = v801[v934];
  int * v803 = v787->cache_vals;
  bool v935 = !(((~(((v796 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v796 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) | (~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31))) == 0);
  int v916;
  if (v935) {
    int * v804 = v787->cache_age;
    int v937 = ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2) + ((~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) & 1);
    int v805 = v804[v937];
    int * v806 = v787->cache_age;
    int v807 = v806[v928];
    int * v808 = v787->cache_age;
    int v940 = v807 + ((int)((unsigned int)(v807 - v805) >> 31));
    v808[v928] = v940;
    int * v810 = v787->cache_age;
    int v811 = v810[v930];
    int * v812 = v787->cache_age;
    int v943 = v811 + ((int)((unsigned int)(v811 - v805) >> 31));
    v812[v930] = v943;
    int * v814 = v787->cache_age;
    v814[v937] = 0;
    v916 = v937;
  } else {
    int * v817 = v787->cache_age;
    int v947 = (((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2;
    int v818 = v817[v947];
    int * v819 = v787->cache_tags;
    int v820 = v819[v947];
    int * v821 = v787->cache_age;
    int v822 = v821[v930];
    int * v823 = v787->cache_tags;
    int v824 = v823[v930];
    bool v951 = !(((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) | (~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31))) == 0);
    int v888;
    if (v951) {
      int * v825 = v787->cache_age;
      int v953 = (4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + ((~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) & 1);
      int v826 = v825[v953];
      int * v827 = v787->cache_age;
      int v828 = v827[v932];
      int * v829 = v787->cache_age;
      int v956 = v828 + ((int)((unsigned int)(v828 - v826) >> 31));
      v829[v932] = v956;
      int * v831 = v787->cache_age;
      int v832 = v831[v934];
      int * v833 = v787->cache_age;
      int v959 = v832 + ((int)((unsigned int)(v832 - v826) >> 31));
      v833[v934] = v959;
      int * v835 = v787->cache_age;
      v835[v953] = 0;
      v888 = v953;
    } else {
      int * v838 = v787->cache_age;
      int v963 = 4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2);
      int v839 = v838[v963];
      int * v840 = v787->cache_tags;
      int v841 = v840[v963];
      int * v842 = v787->cache_age;
      int v843 = v842[v934];
      int * v844 = v787->cache_tags;
      int v845 = v844[v934];
      int * v846 = v787->cache_dirty;
      int v968 = (4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v847 = v846[v968];
      bool v969 = !(v847 == 0);
      if (v969) {
        int * v848 = v787->cache_tags;
        int v849 = v848[v968];
        int * v850 = v787->cache_vals;
        int v972 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v851 = v850[v972];
        int * v852 = v787->cache_vals;
        int v974 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v853 = v852[v974];
        int * v854 = v787->mem;
        int v976 = v849 * 2;
        v854[v976] = v851;
        int * v856 = v787->mem;
        int v979 = (v849 * 2) + 1;
        v856[v979] = v853;
        ;
      } else {
        ;
      }
      int * v861 = v787->mem;
      int v984 = ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) * 2;
      int v862 = v861[v984];
      int * v863 = v787->mem;
      int v986 = (((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) * 2) + 1;
      int v864 = v863[v986];
      int * v865 = v787->cache_vals;
      int v988 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v865[v988] = v862;
      int * v867 = v787->cache_vals;
      int v991 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 3) * 2)) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v845 ^ -1) | (-(v845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v867[v991] = v864;
      int * v869 = v787->cache_tags;
      int v994 = (int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1);
      v869[v968] = v994;
      int * v871 = v787->cache_dirty;
      v871[v968] = 0;
      int * v873 = v787->cache_age;
      v873[v968] = 1;
      int * v875 = v787->cache_age;
      int v876 = v875[v968];
      int * v877 = v787->cache_age;
      int v878 = v877[v932];
      int * v879 = v787->cache_age;
      int v1002 = v878 + ((int)((unsigned int)(v878 - v876) >> 31));
      v879[v932] = v1002;
      int * v881 = v787->cache_age;
      int v882 = v881[v934];
      int * v883 = v787->cache_age;
      int v1005 = v882 + ((int)((unsigned int)(v882 - v876) >> 31));
      v883[v934] = v1005;
      int * v885 = v787->cache_age;
      v885[v968] = 0;
      v888 = v968;
    }
    int * v889 = v787->cache_vals;
    int v1008 = v888 * 2;
    int v890 = v889[v1008];
    int * v891 = v787->cache_vals;
    int v1010 = (v888 * 2) + 1;
    int v892 = v891[v1010];
    int * v893 = v787->cache_vals;
    int v1012 = (((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v893[v1012] = v890;
    int * v895 = v787->cache_vals;
    int v1015 = ((((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v895[v1015] = v892;
    int * v897 = v787->cache_tags;
    int v1018 = ((((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1)) & 1) * 2) + ((((v818 + ((~(((v820 ^ -1) | (-(v820 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1019 = (int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1);
    v897[v1018] = v1019;
    int * v899 = v787->cache_dirty;
    v899[v1018] = 0;
    int * v901 = v787->cache_age;
    v901[v1018] = 1;
    int * v903 = v787->cache_age;
    int v904 = v903[v1018];
    int * v905 = v787->cache_age;
    int v906 = v905[v928];
    int * v907 = v787->cache_age;
    int v1027 = v906 + ((int)((unsigned int)(v906 - v904) >> 31));
    v907[v928] = v1027;
    int * v909 = v787->cache_age;
    int v910 = v909[v930];
    int * v911 = v787->cache_age;
    int v1030 = v910 + ((int)((unsigned int)(v910 - v904) >> 31));
    v911[v930] = v1030;
    int * v913 = v787->cache_age;
    v913[v1018] = 0;
    v916 = v1018;
  }
  int v1033 = (v916 * 2) + (((int)((unsigned int)v794 >> 2)) & 1);
  int v917 = v803[v1033];
  int * v918 = v787->reg_ready;
  int v1036 = ((v792 + ((v788 - v792) & (~((v788 - v792) >> 31)))) + 1) + ((100 ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) | (~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v796 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v796 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) | (~(((v798 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v798 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v800 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v800 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31)) | (~(((v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))) | (-(v802 ^ ((int)((unsigned int)((int)((unsigned int)v794 >> 2)) >> 1))))) >> 31))) & 104)))));
  v918[12] = v1036;
  int * v920 = v787->regs;
  v920[12] = v917;
  return v787;
}

struct StateT * slot_6(struct StateT * v508) {
  int v509 = v508->timer;
  int v510 = v508->timer;
  int v645 = v510 + 1;
  v508->timer = v645;
  int * v512 = v508->reg_ready;
  int v513 = v512[6];
  int * v514 = v508->regs;
  int v515 = v514[6];
  int * v516 = v508->cache_tags;
  int v650 = (((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2;
  int v517 = v516[v650];
  int * v518 = v508->cache_tags;
  int v652 = ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2) + 1;
  int v519 = v518[v652];
  int * v520 = v508->cache_tags;
  int v654 = 4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2);
  int v521 = v520[v654];
  int * v522 = v508->cache_tags;
  int v656 = (4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v523 = v522[v656];
  int * v524 = v508->cache_vals;
  bool v657 = !(((~(((v517 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v517 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) | (~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31))) == 0);
  int v637;
  if (v657) {
    int * v525 = v508->cache_age;
    int v659 = ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2) + ((~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) & 1);
    int v526 = v525[v659];
    int * v527 = v508->cache_age;
    int v528 = v527[v650];
    int * v529 = v508->cache_age;
    int v662 = v528 + ((int)((unsigned int)(v528 - v526) >> 31));
    v529[v650] = v662;
    int * v531 = v508->cache_age;
    int v532 = v531[v652];
    int * v533 = v508->cache_age;
    int v665 = v532 + ((int)((unsigned int)(v532 - v526) >> 31));
    v533[v652] = v665;
    int * v535 = v508->cache_age;
    v535[v659] = 0;
    v637 = v659;
  } else {
    int * v538 = v508->cache_age;
    int v669 = (((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2;
    int v539 = v538[v669];
    int * v540 = v508->cache_tags;
    int v541 = v540[v669];
    int * v542 = v508->cache_age;
    int v543 = v542[v652];
    int * v544 = v508->cache_tags;
    int v545 = v544[v652];
    bool v673 = !(((~(((v521 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v521 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) | (~(((v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31))) == 0);
    int v609;
    if (v673) {
      int * v546 = v508->cache_age;
      int v675 = (4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + ((~(((v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) & 1);
      int v547 = v546[v675];
      int * v548 = v508->cache_age;
      int v549 = v548[v654];
      int * v550 = v508->cache_age;
      int v678 = v549 + ((int)((unsigned int)(v549 - v547) >> 31));
      v550[v654] = v678;
      int * v552 = v508->cache_age;
      int v553 = v552[v656];
      int * v554 = v508->cache_age;
      int v681 = v553 + ((int)((unsigned int)(v553 - v547) >> 31));
      v554[v656] = v681;
      int * v556 = v508->cache_age;
      v556[v675] = 0;
      v609 = v675;
    } else {
      int * v559 = v508->cache_age;
      int v685 = 4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2);
      int v560 = v559[v685];
      int * v561 = v508->cache_tags;
      int v562 = v561[v685];
      int * v563 = v508->cache_age;
      int v564 = v563[v656];
      int * v565 = v508->cache_tags;
      int v566 = v565[v656];
      int * v567 = v508->cache_dirty;
      int v690 = (4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v568 = v567[v690];
      bool v691 = !(v568 == 0);
      if (v691) {
        int * v569 = v508->cache_tags;
        int v570 = v569[v690];
        int * v571 = v508->cache_vals;
        int v694 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v572 = v571[v694];
        int * v573 = v508->cache_vals;
        int v696 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v574 = v573[v696];
        int * v575 = v508->mem;
        int v698 = v570 * 2;
        v575[v698] = v572;
        int * v577 = v508->mem;
        int v701 = (v570 * 2) + 1;
        v577[v701] = v574;
        ;
      } else {
        ;
      }
      int * v582 = v508->mem;
      int v706 = ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) * 2;
      int v583 = v582[v706];
      int * v584 = v508->mem;
      int v708 = (((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) * 2) + 1;
      int v585 = v584[v708];
      int * v586 = v508->cache_vals;
      int v710 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v586[v710] = v583;
      int * v588 = v508->cache_vals;
      int v713 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 3) * 2)) + ((((v560 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v588[v713] = v585;
      int * v590 = v508->cache_tags;
      int v716 = (int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1);
      v590[v690] = v716;
      int * v592 = v508->cache_dirty;
      v592[v690] = 0;
      int * v594 = v508->cache_age;
      v594[v690] = 1;
      int * v596 = v508->cache_age;
      int v597 = v596[v690];
      int * v598 = v508->cache_age;
      int v599 = v598[v654];
      int * v600 = v508->cache_age;
      int v724 = v599 + ((int)((unsigned int)(v599 - v597) >> 31));
      v600[v654] = v724;
      int * v602 = v508->cache_age;
      int v603 = v602[v656];
      int * v604 = v508->cache_age;
      int v727 = v603 + ((int)((unsigned int)(v603 - v597) >> 31));
      v604[v656] = v727;
      int * v606 = v508->cache_age;
      v606[v690] = 0;
      v609 = v690;
    }
    int * v610 = v508->cache_vals;
    int v730 = v609 * 2;
    int v611 = v610[v730];
    int * v612 = v508->cache_vals;
    int v732 = (v609 * 2) + 1;
    int v613 = v612[v732];
    int * v614 = v508->cache_vals;
    int v734 = (((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2) + ((((v539 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2)) - (v543 + ((~(((v545 ^ -1) | (-(v545 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v614[v734] = v611;
    int * v616 = v508->cache_vals;
    int v737 = ((((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2) + ((((v539 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2)) - (v543 + ((~(((v545 ^ -1) | (-(v545 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v616[v737] = v613;
    int * v618 = v508->cache_tags;
    int v740 = ((((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1)) & 1) * 2) + ((((v539 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2)) - (v543 + ((~(((v545 ^ -1) | (-(v545 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v741 = (int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1);
    v618[v740] = v741;
    int * v620 = v508->cache_dirty;
    v620[v740] = 0;
    int * v622 = v508->cache_age;
    v622[v740] = 1;
    int * v624 = v508->cache_age;
    int v625 = v624[v740];
    int * v626 = v508->cache_age;
    int v627 = v626[v650];
    int * v628 = v508->cache_age;
    int v749 = v627 + ((int)((unsigned int)(v627 - v625) >> 31));
    v628[v650] = v749;
    int * v630 = v508->cache_age;
    int v631 = v630[v652];
    int * v632 = v508->cache_age;
    int v752 = v631 + ((int)((unsigned int)(v631 - v625) >> 31));
    v632[v652] = v752;
    int * v634 = v508->cache_age;
    v634[v740] = 0;
    v637 = v740;
  }
  int v755 = (v637 * 2) + (((int)((unsigned int)v515 >> 2)) & 1);
  int v638 = v524[v755];
  int * v639 = v508->reg_ready;
  int v758 = ((v513 + ((v509 - v513) & (~((v509 - v513) >> 31)))) + 1) + ((100 ^ (((~(((v521 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v521 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) | (~(((v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v517 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v517 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) | (~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v521 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v521 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31)) | (~(((v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))) | (-(v523 ^ ((int)((unsigned int)((int)((unsigned int)v515 >> 2)) >> 1))))) >> 31))) & 104)))));
  v639[11] = v758;
  int * v641 = v508->regs;
  v641[11] = v638;
  struct StateT * v643 = slot_7(v508);
  return v643;
}

struct StateT * slot_5(struct StateT * v116) {
  int v117 = v116->timer;
  int v118 = v116->timer;
  int v327 = v118 + 1;
  v116->timer = v327;
  int * v120 = v116->reg_ready;
  int v121 = v120[6];
  int * v122 = v116->regs;
  int v123 = v122[6];
  int * v124 = v116->reg_ready;
  int v125 = v124[7];
  int * v126 = v116->regs;
  int v127 = v126[7];
  int * v128 = v116->cache_tags;
  int v335 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2;
  int v129 = v128[v335];
  int * v130 = v116->cache_tags;
  int v337 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + 1;
  int v131 = v130[v337];
  int * v132 = v116->cache_tags;
  int v339 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
  int v133 = v132[v339];
  int * v134 = v116->cache_tags;
  int v341 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v135 = v134[v341];
  int v136 = v116->timer;
  int v342 = v136 + ((100 ^ (((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & 104)))));
  v116->timer = v342;
  bool v343 = !(((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
  int v250;
  if (v343) {
    int * v138 = v116->cache_age;
    int v345 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
    int v139 = v138[v345];
    int * v140 = v116->cache_age;
    int v141 = v140[v335];
    int * v142 = v116->cache_age;
    int v348 = v141 + ((int)((unsigned int)(v141 - v139) >> 31));
    v142[v335] = v348;
    int * v144 = v116->cache_age;
    int v145 = v144[v337];
    int * v146 = v116->cache_age;
    int v351 = v145 + ((int)((unsigned int)(v145 - v139) >> 31));
    v146[v337] = v351;
    int * v148 = v116->cache_age;
    v148[v345] = 0;
    v250 = v345;
  } else {
    int * v151 = v116->cache_age;
    int v355 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2;
    int v152 = v151[v355];
    int * v153 = v116->cache_tags;
    int v154 = v153[v355];
    int * v155 = v116->cache_age;
    int v156 = v155[v337];
    int * v157 = v116->cache_tags;
    int v158 = v157[v337];
    bool v359 = !(((~(((v133 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v133 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
    int v222;
    if (v359) {
      int * v159 = v116->cache_age;
      int v361 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
      int v160 = v159[v361];
      int * v161 = v116->cache_age;
      int v162 = v161[v339];
      int * v163 = v116->cache_age;
      int v364 = v162 + ((int)((unsigned int)(v162 - v160) >> 31));
      v163[v339] = v364;
      int * v165 = v116->cache_age;
      int v166 = v165[v341];
      int * v167 = v116->cache_age;
      int v367 = v166 + ((int)((unsigned int)(v166 - v160) >> 31));
      v167[v341] = v367;
      int * v169 = v116->cache_age;
      v169[v361] = 0;
      v222 = v361;
    } else {
      int * v172 = v116->cache_age;
      int v371 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
      int v173 = v172[v371];
      int * v174 = v116->cache_tags;
      int v175 = v174[v371];
      int * v176 = v116->cache_age;
      int v177 = v176[v341];
      int * v178 = v116->cache_tags;
      int v179 = v178[v341];
      int * v180 = v116->cache_dirty;
      int v376 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v181 = v180[v376];
      bool v377 = !(v181 == 0);
      if (v377) {
        int * v182 = v116->cache_tags;
        int v183 = v182[v376];
        int * v184 = v116->cache_vals;
        int v380 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v185 = v184[v380];
        int * v186 = v116->cache_vals;
        int v382 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v187 = v186[v382];
        int * v188 = v116->mem;
        int v384 = v183 * 2;
        v188[v384] = v185;
        int * v190 = v116->mem;
        int v387 = (v183 * 2) + 1;
        v190[v387] = v187;
        ;
      } else {
        ;
      }
      int * v195 = v116->mem;
      int v392 = ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2;
      int v196 = v195[v392];
      int * v197 = v116->mem;
      int v394 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2) + 1;
      int v198 = v197[v394];
      int * v199 = v116->cache_vals;
      int v396 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v199[v396] = v196;
      int * v201 = v116->cache_vals;
      int v399 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v173 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v179 ^ -1) | (-(v179 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v201[v399] = v198;
      int * v203 = v116->cache_tags;
      int v402 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
      v203[v376] = v402;
      int * v205 = v116->cache_dirty;
      v205[v376] = 0;
      int * v207 = v116->cache_age;
      v207[v376] = 1;
      int * v209 = v116->cache_age;
      int v210 = v209[v376];
      int * v211 = v116->cache_age;
      int v212 = v211[v339];
      int * v213 = v116->cache_age;
      int v410 = v212 + ((int)((unsigned int)(v212 - v210) >> 31));
      v213[v339] = v410;
      int * v215 = v116->cache_age;
      int v216 = v215[v341];
      int * v217 = v116->cache_age;
      int v413 = v216 + ((int)((unsigned int)(v216 - v210) >> 31));
      v217[v341] = v413;
      int * v219 = v116->cache_age;
      v219[v376] = 0;
      v222 = v376;
    }
    int * v223 = v116->cache_vals;
    int v416 = v222 * 2;
    int v224 = v223[v416];
    int * v225 = v116->cache_vals;
    int v418 = (v222 * 2) + 1;
    int v226 = v225[v418];
    int * v227 = v116->cache_vals;
    int v420 = (((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v227[v420] = v224;
    int * v229 = v116->cache_vals;
    int v423 = ((((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v229[v423] = v226;
    int * v231 = v116->cache_tags;
    int v426 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v427 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
    v231[v426] = v427;
    int * v233 = v116->cache_dirty;
    v233[v426] = 0;
    int * v235 = v116->cache_age;
    v235[v426] = 1;
    int * v237 = v116->cache_age;
    int v238 = v237[v426];
    int * v239 = v116->cache_age;
    int v240 = v239[v335];
    int * v241 = v116->cache_age;
    int v435 = v240 + ((int)((unsigned int)(v240 - v238) >> 31));
    v241[v335] = v435;
    int * v243 = v116->cache_age;
    int v244 = v243[v337];
    int * v245 = v116->cache_age;
    int v438 = v244 + ((int)((unsigned int)(v244 - v238) >> 31));
    v245[v337] = v438;
    int * v247 = v116->cache_age;
    v247[v426] = 0;
    v250 = v426;
  }
  int * v251 = v116->cache_vals;
  int v441 = (v250 * 2) + (((int)((unsigned int)v123 >> 2)) & 1);
  v251[v441] = v127;
  int * v253 = v116->cache_tags;
  int v254 = v253[v339];
  int * v255 = v116->cache_tags;
  int v256 = v255[v341];
  bool v445 = !(((~(((v254 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v254 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v256 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v256 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
  int v320;
  if (v445) {
    int * v257 = v116->cache_age;
    int v447 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((~(((v256 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v256 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
    int v258 = v257[v447];
    int * v259 = v116->cache_age;
    int v260 = v259[v339];
    int * v261 = v116->cache_age;
    int v450 = v260 + ((int)((unsigned int)(v260 - v258) >> 31));
    v261[v339] = v450;
    int * v263 = v116->cache_age;
    int v264 = v263[v341];
    int * v265 = v116->cache_age;
    int v453 = v264 + ((int)((unsigned int)(v264 - v258) >> 31));
    v265[v341] = v453;
    int * v267 = v116->cache_age;
    v267[v447] = 0;
    v320 = v447;
  } else {
    int * v270 = v116->cache_age;
    int v457 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
    int v271 = v270[v457];
    int * v272 = v116->cache_tags;
    int v273 = v272[v457];
    int * v274 = v116->cache_age;
    int v275 = v274[v341];
    int * v276 = v116->cache_tags;
    int v277 = v276[v341];
    int * v278 = v116->cache_dirty;
    int v462 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v279 = v278[v462];
    bool v463 = !(v279 == 0);
    if (v463) {
      int * v280 = v116->cache_tags;
      int v281 = v280[v462];
      int * v282 = v116->cache_vals;
      int v466 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v283 = v282[v466];
      int * v284 = v116->cache_vals;
      int v468 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v285 = v284[v468];
      int * v286 = v116->mem;
      int v470 = v281 * 2;
      v286[v470] = v283;
      int * v288 = v116->mem;
      int v473 = (v281 * 2) + 1;
      v288[v473] = v285;
      ;
    } else {
      ;
    }
    int * v293 = v116->mem;
    int v478 = ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2;
    int v294 = v293[v478];
    int * v295 = v116->mem;
    int v480 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2) + 1;
    int v296 = v295[v480];
    int * v297 = v116->cache_vals;
    int v482 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v297[v482] = v294;
    int * v299 = v116->cache_vals;
    int v485 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v271 + ((~(((v273 ^ -1) | (-(v273 ^ -1))) >> 31)) & 2)) - (v275 + ((~(((v277 ^ -1) | (-(v277 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v299[v485] = v296;
    int * v301 = v116->cache_tags;
    int v488 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
    v301[v462] = v488;
    int * v303 = v116->cache_dirty;
    v303[v462] = 0;
    int * v305 = v116->cache_age;
    v305[v462] = 1;
    int * v307 = v116->cache_age;
    int v308 = v307[v462];
    int * v309 = v116->cache_age;
    int v310 = v309[v339];
    int * v311 = v116->cache_age;
    int v496 = v310 + ((int)((unsigned int)(v310 - v308) >> 31));
    v311[v339] = v496;
    int * v313 = v116->cache_age;
    int v314 = v313[v341];
    int * v315 = v116->cache_age;
    int v499 = v314 + ((int)((unsigned int)(v314 - v308) >> 31));
    v315[v341] = v499;
    int * v317 = v116->cache_age;
    v317[v462] = 0;
    v320 = v462;
  }
  int * v321 = v116->cache_vals;
  int v502 = (v320 * 2) + (((int)((unsigned int)v123 >> 2)) & 1);
  v321[v502] = v127;
  int * v323 = v116->cache_dirty;
  v323[v320] = 1;
  struct StateT * v325 = slot_6(v116);
  return v325;
}

struct StateT * slot_4(struct StateT * v98) {
  int v99 = v98->timer;
  int v100 = v98->timer;
  int v108 = v100 + 1;
  v98->timer = v108;
  int * v102 = v98->reg_ready;
  int v111 = v99 + 1;
  v102[7] = v111;
  int * v104 = v98->regs;
  v104[7] = 0;
  struct StateT * v106 = slot_5(v98);
  return v106;
}

struct StateT * slot_2(struct StateT * v45) {
  int v46 = v45->timer;
  int v47 = v45->timer;
  int v62 = v47 + 1;
  v45->timer = v62;
  int * v49 = v45->reg_ready;
  int v50 = v49[5];
  int * v51 = v45->regs;
  int v52 = v51[5];
  int * v53 = v45->reg_ready;
  int v54 = v53[9];
  int * v55 = v45->regs;
  int v56 = v55[9];
  bool v69 = v52 >= v56;
  struct StateT * v60;
  if (v69) {
    v60 = v45;
  } else {
    struct StateT * v58 = slot_3(v45);
    v60 = v58;
  }
  return v60;
}

struct StateT * slot_7(struct StateT * v763) {
  int v764 = v763->timer;
  int v765 = v763->timer;
  int v777 = v765 + 1;
  v763->timer = v777;
  int * v767 = v763->reg_ready;
  int v768 = v767[11];
  int * v769 = v763->regs;
  int v770 = v769[11];
  int * v771 = v763->reg_ready;
  int v782 = (v768 + ((v764 - v768) & (~((v764 - v768) >> 31)))) + 1;
  v771[11] = v782;
  int * v773 = v763->regs;
  int v784 = v770 << 2;
  v773[11] = v784;
  struct StateT * v775 = slot_8(v763);
  return v775;
}

struct StateT * slot_3(struct StateT * v73) {
  int v74 = v73->timer;
  int v75 = v73->timer;
  int v87 = v75 + 1;
  v73->timer = v87;
  int * v77 = v73->reg_ready;
  int v78 = v77[5];
  int * v79 = v73->regs;
  int v80 = v79[5];
  int * v81 = v73->reg_ready;
  int v93 = (v78 + ((v74 - v78) & (~((v74 - v78) >> 31)))) + 1;
  v81[6] = v93;
  int * v83 = v73->regs;
  int v95 = v80 + 80;
  v83[6] = v95;
  struct StateT * v85 = slot_4(v73);
  return v85;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v16 = v4 + 1;
  v2->timer = v16;
  int * v6 = v2->reg_ready;
  int v7 = v6[10];
  int * v8 = v2->regs;
  int v9 = v8[10];
  int * v10 = v2->reg_ready;
  int v22 = (v7 + ((v3 - v7) & (~((v3 - v7) >> 31)))) + 1;
  v10[5] = v22;
  int * v12 = v2->regs;
  int v24 = v9 & 28;
  v12[5] = v24;
  struct StateT * v14 = slot_1(v2);
  return v14;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}