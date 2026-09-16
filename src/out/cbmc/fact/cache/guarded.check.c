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

struct StateT * slot_12(struct StateT * v1586);
struct StateT * slot_14(struct StateT * v590);
struct StateT * slot_6(struct StateT * v606);
struct StateT * slot_16(struct StateT * v895);
struct StateT * slot_5(struct StateT * v573);
struct StateT * slot_17(struct StateT * v1296);
struct StateT * slot_2(struct StateT * v501);
struct StateT * slot_7(struct StateT * v646);
struct StateT * slot_3(struct StateT * v513);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1317);
struct StateT * slot_1(struct StateT * v251);
struct StateT * slot_8(struct StateT * v1280);
struct StateT * slot_4(struct StateT * v533);
struct StateT * slot_13(struct StateT * v557);
struct StateT * slot_15(struct StateT * v626);
struct StateT * slot_9(struct StateT * v1301);
struct StateT * slot_11(struct StateT * v1337);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1586) {
  int v1587 = v1586->timer;
  int v1597 = v1587 + 1;
  v1586->timer = v1597;
  int * v1589 = v1586->regs;
  int v1590 = v1589[12];
  int * v1591 = v1586->regs;
  int v1592 = v1591[11];
  int * v1593 = v1586->regs;
  int v1603 = v1590 + v1592;
  v1593[12] = v1603;
  struct StateT * v1595 = slot_13(v1586);
  return v1595;
}

struct StateT * slot_14(struct StateT * v590) {
  int v591 = v590->timer;
  int v599 = v591 + 1;
  v590->timer = v599;
  int * v593 = v590->regs;
  int v594 = v593[10];
  int * v595 = v590->regs;
  int v603 = v594 << 2;
  v595[10] = v603;
  struct StateT * v597 = slot_15(v590);
  return v597;
}

struct StateT * slot_6(struct StateT * v606) {
  int v607 = v606->timer;
  int v617 = v607 + 1;
  v606->timer = v617;
  int * v609 = v606->regs;
  int v610 = v609[11];
  int * v611 = v606->regs;
  int v612 = v611[14];
  int * v613 = v606->regs;
  int v623 = v610 + v612;
  v613[14] = v623;
  struct StateT * v615 = slot_7(v606);
  return v615;
}

struct StateT * slot_16(struct StateT * v895) {
  int v896 = v895->timer;
  int v1101 = v896 + 1;
  v895->timer = v1101;
  int * v898 = v895->regs;
  int v899 = v898[10];
  int * v900 = v895->regs;
  int v901 = v900[12];
  int * v902 = v895->cache_tags;
  int v1107 = (((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2;
  int v903 = v902[v1107];
  int * v904 = v895->cache_tags;
  int v1109 = ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2) + 1;
  int v905 = v904[v1109];
  int * v906 = v895->cache_tags;
  int v1111 = 4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2);
  int v907 = v906[v1111];
  int * v908 = v895->cache_tags;
  int v1113 = (4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v909 = v908[v1113];
  int v910 = v895->timer;
  int v1114 = v910 + ((100 ^ (((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) | (~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) | (~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31))) & 104)))));
  v895->timer = v1114;
  bool v1115 = !(((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) | (~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31))) == 0);
  int v1024;
  if (v1115) {
    int * v912 = v895->cache_age;
    int v1117 = ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2) + ((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) & 1);
    int v913 = v912[v1117];
    int * v914 = v895->cache_age;
    int v915 = v914[v1107];
    int * v916 = v895->cache_age;
    int v1120 = v915 + ((int)((unsigned int)(v915 - v913) >> 31));
    v916[v1107] = v1120;
    int * v918 = v895->cache_age;
    int v919 = v918[v1109];
    int * v920 = v895->cache_age;
    int v1123 = v919 + ((int)((unsigned int)(v919 - v913) >> 31));
    v920[v1109] = v1123;
    int * v922 = v895->cache_age;
    v922[v1117] = 0;
    v1024 = v1117;
  } else {
    int * v925 = v895->cache_age;
    int v1127 = (((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2;
    int v926 = v925[v1127];
    int * v927 = v895->cache_tags;
    int v928 = v927[v1127];
    int * v929 = v895->cache_age;
    int v930 = v929[v1109];
    int * v931 = v895->cache_tags;
    int v932 = v931[v1109];
    bool v1131 = !(((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) | (~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31))) == 0);
    int v996;
    if (v1131) {
      int * v933 = v895->cache_age;
      int v1133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((~(((v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v909 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) & 1);
      int v934 = v933[v1133];
      int * v935 = v895->cache_age;
      int v936 = v935[v1111];
      int * v937 = v895->cache_age;
      int v1136 = v936 + ((int)((unsigned int)(v936 - v934) >> 31));
      v937[v1111] = v1136;
      int * v939 = v895->cache_age;
      int v940 = v939[v1113];
      int * v941 = v895->cache_age;
      int v1139 = v940 + ((int)((unsigned int)(v940 - v934) >> 31));
      v941[v1113] = v1139;
      int * v943 = v895->cache_age;
      v943[v1133] = 0;
      v996 = v1133;
    } else {
      int * v946 = v895->cache_age;
      int v1143 = 4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2);
      int v947 = v946[v1143];
      int * v948 = v895->cache_tags;
      int v949 = v948[v1143];
      int * v950 = v895->cache_age;
      int v951 = v950[v1113];
      int * v952 = v895->cache_tags;
      int v953 = v952[v1113];
      int * v954 = v895->cache_dirty;
      int v1148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v947 + ((~(((v949 ^ -1) | (-(v949 ^ -1))) >> 31)) & 2)) - (v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v955 = v954[v1148];
      bool v1149 = !(v955 == 0);
      if (v1149) {
        int * v956 = v895->cache_tags;
        int v957 = v956[v1148];
        int * v958 = v895->cache_vals;
        int v1152 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v947 + ((~(((v949 ^ -1) | (-(v949 ^ -1))) >> 31)) & 2)) - (v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v959 = v958[v1152];
        int * v960 = v895->cache_vals;
        int v1154 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v947 + ((~(((v949 ^ -1) | (-(v949 ^ -1))) >> 31)) & 2)) - (v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v961 = v960[v1154];
        int * v962 = v895->mem;
        int v1156 = v957 * 2;
        v962[v1156] = v959;
        int * v964 = v895->mem;
        int v1159 = (v957 * 2) + 1;
        v964[v1159] = v961;
        ;
      } else {
        ;
      }
      int * v969 = v895->mem;
      int v1164 = ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) * 2;
      int v970 = v969[v1164];
      int * v971 = v895->mem;
      int v1166 = (((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) * 2) + 1;
      int v972 = v971[v1166];
      int * v973 = v895->cache_vals;
      int v1168 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v947 + ((~(((v949 ^ -1) | (-(v949 ^ -1))) >> 31)) & 2)) - (v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v973[v1168] = v970;
      int * v975 = v895->cache_vals;
      int v1171 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v947 + ((~(((v949 ^ -1) | (-(v949 ^ -1))) >> 31)) & 2)) - (v951 + ((~(((v953 ^ -1) | (-(v953 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v975[v1171] = v972;
      int * v977 = v895->cache_tags;
      int v1174 = (int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1);
      v977[v1148] = v1174;
      int * v979 = v895->cache_dirty;
      v979[v1148] = 0;
      int * v981 = v895->cache_age;
      v981[v1148] = 1;
      int * v983 = v895->cache_age;
      int v984 = v983[v1148];
      int * v985 = v895->cache_age;
      int v986 = v985[v1111];
      int * v987 = v895->cache_age;
      int v1182 = v986 + ((int)((unsigned int)(v986 - v984) >> 31));
      v987[v1111] = v1182;
      int * v989 = v895->cache_age;
      int v990 = v989[v1113];
      int * v991 = v895->cache_age;
      int v1185 = v990 + ((int)((unsigned int)(v990 - v984) >> 31));
      v991[v1113] = v1185;
      int * v993 = v895->cache_age;
      v993[v1148] = 0;
      v996 = v1148;
    }
    int * v997 = v895->cache_vals;
    int v1188 = v996 * 2;
    int v998 = v997[v1188];
    int * v999 = v895->cache_vals;
    int v1190 = (v996 * 2) + 1;
    int v1000 = v999[v1190];
    int * v1001 = v895->cache_vals;
    int v1192 = (((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2) + ((((v926 + ((~(((v928 ^ -1) | (-(v928 ^ -1))) >> 31)) & 2)) - (v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1001[v1192] = v998;
    int * v1003 = v895->cache_vals;
    int v1195 = ((((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2) + ((((v926 + ((~(((v928 ^ -1) | (-(v928 ^ -1))) >> 31)) & 2)) - (v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1003[v1195] = v1000;
    int * v1005 = v895->cache_tags;
    int v1198 = ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 1) * 2) + ((((v926 + ((~(((v928 ^ -1) | (-(v928 ^ -1))) >> 31)) & 2)) - (v930 + ((~(((v932 ^ -1) | (-(v932 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1199 = (int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1);
    v1005[v1198] = v1199;
    int * v1007 = v895->cache_dirty;
    v1007[v1198] = 0;
    int * v1009 = v895->cache_age;
    v1009[v1198] = 1;
    int * v1011 = v895->cache_age;
    int v1012 = v1011[v1198];
    int * v1013 = v895->cache_age;
    int v1014 = v1013[v1107];
    int * v1015 = v895->cache_age;
    int v1207 = v1014 + ((int)((unsigned int)(v1014 - v1012) >> 31));
    v1015[v1107] = v1207;
    int * v1017 = v895->cache_age;
    int v1018 = v1017[v1109];
    int * v1019 = v895->cache_age;
    int v1210 = v1018 + ((int)((unsigned int)(v1018 - v1012) >> 31));
    v1019[v1109] = v1210;
    int * v1021 = v895->cache_age;
    v1021[v1198] = 0;
    v1024 = v1198;
  }
  int * v1025 = v895->cache_vals;
  int v1213 = (v1024 * 2) + (((int)((unsigned int)v899 >> 2)) & 1);
  v1025[v1213] = v901;
  int * v1027 = v895->cache_tags;
  int v1028 = v1027[v1111];
  int * v1029 = v895->cache_tags;
  int v1030 = v1029[v1113];
  bool v1217 = !(((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) | (~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31))) == 0);
  int v1094;
  if (v1217) {
    int * v1031 = v895->cache_age;
    int v1219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1))))) >> 31)) & 1);
    int v1032 = v1031[v1219];
    int * v1033 = v895->cache_age;
    int v1034 = v1033[v1111];
    int * v1035 = v895->cache_age;
    int v1222 = v1034 + ((int)((unsigned int)(v1034 - v1032) >> 31));
    v1035[v1111] = v1222;
    int * v1037 = v895->cache_age;
    int v1038 = v1037[v1113];
    int * v1039 = v895->cache_age;
    int v1225 = v1038 + ((int)((unsigned int)(v1038 - v1032) >> 31));
    v1039[v1113] = v1225;
    int * v1041 = v895->cache_age;
    v1041[v1219] = 0;
    v1094 = v1219;
  } else {
    int * v1044 = v895->cache_age;
    int v1229 = 4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2);
    int v1045 = v1044[v1229];
    int * v1046 = v895->cache_tags;
    int v1047 = v1046[v1229];
    int * v1048 = v895->cache_age;
    int v1049 = v1048[v1113];
    int * v1050 = v895->cache_tags;
    int v1051 = v1050[v1113];
    int * v1052 = v895->cache_dirty;
    int v1234 = (4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v1045 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1053 = v1052[v1234];
    bool v1235 = !(v1053 == 0);
    if (v1235) {
      int * v1054 = v895->cache_tags;
      int v1055 = v1054[v1234];
      int * v1056 = v895->cache_vals;
      int v1238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v1045 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1057 = v1056[v1238];
      int * v1058 = v895->cache_vals;
      int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v1045 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1059 = v1058[v1240];
      int * v1060 = v895->mem;
      int v1242 = v1055 * 2;
      v1060[v1242] = v1057;
      int * v1062 = v895->mem;
      int v1245 = (v1055 * 2) + 1;
      v1062[v1245] = v1059;
      ;
    } else {
      ;
    }
    int * v1067 = v895->mem;
    int v1250 = ((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) * 2;
    int v1068 = v1067[v1250];
    int * v1069 = v895->mem;
    int v1252 = (((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) * 2) + 1;
    int v1070 = v1069[v1252];
    int * v1071 = v895->cache_vals;
    int v1254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v1045 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1071[v1254] = v1068;
    int * v1073 = v895->cache_vals;
    int v1257 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1)) & 3) * 2)) + ((((v1045 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1051 ^ -1) | (-(v1051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1073[v1257] = v1070;
    int * v1075 = v895->cache_tags;
    int v1260 = (int)((unsigned int)((int)((unsigned int)v899 >> 2)) >> 1);
    v1075[v1234] = v1260;
    int * v1077 = v895->cache_dirty;
    v1077[v1234] = 0;
    int * v1079 = v895->cache_age;
    v1079[v1234] = 1;
    int * v1081 = v895->cache_age;
    int v1082 = v1081[v1234];
    int * v1083 = v895->cache_age;
    int v1084 = v1083[v1111];
    int * v1085 = v895->cache_age;
    int v1268 = v1084 + ((int)((unsigned int)(v1084 - v1082) >> 31));
    v1085[v1111] = v1268;
    int * v1087 = v895->cache_age;
    int v1088 = v1087[v1113];
    int * v1089 = v895->cache_age;
    int v1271 = v1088 + ((int)((unsigned int)(v1088 - v1082) >> 31));
    v1089[v1113] = v1271;
    int * v1091 = v895->cache_age;
    v1091[v1234] = 0;
    v1094 = v1234;
  }
  int * v1095 = v895->cache_vals;
  int v1274 = (v1094 * 2) + (((int)((unsigned int)v899 >> 2)) & 1);
  v1095[v1274] = v901;
  int * v1097 = v895->cache_dirty;
  v1097[v1094] = 1;
  struct StateT * v1099 = slot_17(v895);
  return v1099;
}

struct StateT * slot_5(struct StateT * v573) {
  int v574 = v573->timer;
  int v582 = v574 + 1;
  v573->timer = v582;
  int * v576 = v573->regs;
  int v577 = v576[10];
  int * v578 = v573->regs;
  int v587 = v577 << 2;
  v578[14] = v587;
  struct StateT * v580 = slot_6(v573);
  return v580;
}

struct StateT * slot_17(struct StateT * v1296) {
  int v1297 = v1296->timer;
  int v1300 = v1297 + 1;
  v1296->timer = v1300;
  return v1296;
}

struct StateT * slot_2(struct StateT * v501) {
  int v502 = v501->timer;
  int v508 = v502 + 1;
  v501->timer = v508;
  int * v504 = v501->regs;
  v504[15] = 15;
  struct StateT * v506 = slot_3(v501);
  return v506;
}

struct StateT * slot_7(struct StateT * v646) {
  int v647 = v646->timer;
  int v780 = v647 + 1;
  v646->timer = v780;
  int * v649 = v646->regs;
  int v650 = v649[14];
  int * v651 = v646->cache_tags;
  int v784 = (((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2;
  int v652 = v651[v784];
  int * v653 = v646->cache_tags;
  int v786 = ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2) + 1;
  int v654 = v653[v786];
  int * v655 = v646->cache_tags;
  int v788 = 4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2);
  int v656 = v655[v788];
  int * v657 = v646->cache_tags;
  int v790 = (4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v658 = v657[v790];
  int v659 = v646->timer;
  int v791 = v659 + ((100 ^ (((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) | (~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) | (~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31))) & 104)))));
  v646->timer = v791;
  int * v661 = v646->cache_vals;
  bool v792 = !(((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31))) == 0);
  int v774;
  if (v792) {
    int * v662 = v646->cache_age;
    int v794 = ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2) + ((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) & 1);
    int v663 = v662[v794];
    int * v664 = v646->cache_age;
    int v665 = v664[v784];
    int * v666 = v646->cache_age;
    int v797 = v665 + ((int)((unsigned int)(v665 - v663) >> 31));
    v666[v784] = v797;
    int * v668 = v646->cache_age;
    int v669 = v668[v786];
    int * v670 = v646->cache_age;
    int v800 = v669 + ((int)((unsigned int)(v669 - v663) >> 31));
    v670[v786] = v800;
    int * v672 = v646->cache_age;
    v672[v794] = 0;
    v774 = v794;
  } else {
    int * v675 = v646->cache_age;
    int v804 = (((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2;
    int v676 = v675[v804];
    int * v677 = v646->cache_tags;
    int v678 = v677[v804];
    int * v679 = v646->cache_age;
    int v680 = v679[v786];
    int * v681 = v646->cache_tags;
    int v682 = v681[v786];
    bool v808 = !(((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) | (~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31))) == 0);
    int v746;
    if (v808) {
      int * v683 = v646->cache_age;
      int v810 = (4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + ((~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1))))) >> 31)) & 1);
      int v684 = v683[v810];
      int * v685 = v646->cache_age;
      int v686 = v685[v788];
      int * v687 = v646->cache_age;
      int v813 = v686 + ((int)((unsigned int)(v686 - v684) >> 31));
      v687[v788] = v813;
      int * v689 = v646->cache_age;
      int v690 = v689[v790];
      int * v691 = v646->cache_age;
      int v816 = v690 + ((int)((unsigned int)(v690 - v684) >> 31));
      v691[v790] = v816;
      int * v693 = v646->cache_age;
      v693[v810] = 0;
      v746 = v810;
    } else {
      int * v696 = v646->cache_age;
      int v820 = 4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2);
      int v697 = v696[v820];
      int * v698 = v646->cache_tags;
      int v699 = v698[v820];
      int * v700 = v646->cache_age;
      int v701 = v700[v790];
      int * v702 = v646->cache_tags;
      int v703 = v702[v790];
      int * v704 = v646->cache_dirty;
      int v825 = (4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + ((((v697 + ((~(((v699 ^ -1) | (-(v699 ^ -1))) >> 31)) & 2)) - (v701 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v705 = v704[v825];
      bool v826 = !(v705 == 0);
      if (v826) {
        int * v706 = v646->cache_tags;
        int v707 = v706[v825];
        int * v708 = v646->cache_vals;
        int v829 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + ((((v697 + ((~(((v699 ^ -1) | (-(v699 ^ -1))) >> 31)) & 2)) - (v701 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v709 = v708[v829];
        int * v710 = v646->cache_vals;
        int v831 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + ((((v697 + ((~(((v699 ^ -1) | (-(v699 ^ -1))) >> 31)) & 2)) - (v701 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v711 = v710[v831];
        int * v712 = v646->mem;
        int v833 = v707 * 2;
        v712[v833] = v709;
        int * v714 = v646->mem;
        int v836 = (v707 * 2) + 1;
        v714[v836] = v711;
        ;
      } else {
        ;
      }
      int * v719 = v646->mem;
      int v841 = ((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) * 2;
      int v720 = v719[v841];
      int * v721 = v646->mem;
      int v843 = (((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) * 2) + 1;
      int v722 = v721[v843];
      int * v723 = v646->cache_vals;
      int v845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + ((((v697 + ((~(((v699 ^ -1) | (-(v699 ^ -1))) >> 31)) & 2)) - (v701 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v723[v845] = v720;
      int * v725 = v646->cache_vals;
      int v848 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 3) * 2)) + ((((v697 + ((~(((v699 ^ -1) | (-(v699 ^ -1))) >> 31)) & 2)) - (v701 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v725[v848] = v722;
      int * v727 = v646->cache_tags;
      int v851 = (int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1);
      v727[v825] = v851;
      int * v729 = v646->cache_dirty;
      v729[v825] = 0;
      int * v731 = v646->cache_age;
      v731[v825] = 1;
      int * v733 = v646->cache_age;
      int v734 = v733[v825];
      int * v735 = v646->cache_age;
      int v736 = v735[v788];
      int * v737 = v646->cache_age;
      int v859 = v736 + ((int)((unsigned int)(v736 - v734) >> 31));
      v737[v788] = v859;
      int * v739 = v646->cache_age;
      int v740 = v739[v790];
      int * v741 = v646->cache_age;
      int v862 = v740 + ((int)((unsigned int)(v740 - v734) >> 31));
      v741[v790] = v862;
      int * v743 = v646->cache_age;
      v743[v825] = 0;
      v746 = v825;
    }
    int * v747 = v646->cache_vals;
    int v865 = v746 * 2;
    int v748 = v747[v865];
    int * v749 = v646->cache_vals;
    int v867 = (v746 * 2) + 1;
    int v750 = v749[v867];
    int * v751 = v646->cache_vals;
    int v869 = (((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2) + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v751[v869] = v748;
    int * v753 = v646->cache_vals;
    int v872 = ((((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2) + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v753[v872] = v750;
    int * v755 = v646->cache_tags;
    int v875 = ((((int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1)) & 1) * 2) + ((((v676 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v682 ^ -1) | (-(v682 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v876 = (int)((unsigned int)((int)((unsigned int)v650 >> 2)) >> 1);
    v755[v875] = v876;
    int * v757 = v646->cache_dirty;
    v757[v875] = 0;
    int * v759 = v646->cache_age;
    v759[v875] = 1;
    int * v761 = v646->cache_age;
    int v762 = v761[v875];
    int * v763 = v646->cache_age;
    int v764 = v763[v784];
    int * v765 = v646->cache_age;
    int v884 = v764 + ((int)((unsigned int)(v764 - v762) >> 31));
    v765[v784] = v884;
    int * v767 = v646->cache_age;
    int v768 = v767[v786];
    int * v769 = v646->cache_age;
    int v887 = v768 + ((int)((unsigned int)(v768 - v762) >> 31));
    v769[v786] = v887;
    int * v771 = v646->cache_age;
    v771[v875] = 0;
    v774 = v875;
  }
  int v890 = (v774 * 2) + (((int)((unsigned int)v650 >> 2)) & 1);
  int v775 = v661[v890];
  int * v776 = v646->regs;
  v776[14] = v775;
  struct StateT * v778 = slot_8(v646);
  return v778;
}

struct StateT * slot_3(struct StateT * v513) {
  int v514 = v513->timer;
  int v524 = v514 + 1;
  v513->timer = v524;
  int * v516 = v513->regs;
  int v517 = v516[12];
  int * v518 = v513->regs;
  int v519 = v518[14];
  int * v520 = v513->regs;
  int v530 = v517 ^ v519;
  v520[12] = v530;
  struct StateT * v522 = slot_4(v513);
  return v522;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v1317) {
  int v1318 = v1317->timer;
  int v1328 = v1318 + 1;
  v1317->timer = v1328;
  int * v1320 = v1317->regs;
  int v1321 = v1320[11];
  int * v1322 = v1317->regs;
  int v1323 = v1322[14];
  int * v1324 = v1317->regs;
  int v1334 = v1321 + v1323;
  v1324[11] = v1334;
  struct StateT * v1326 = slot_11(v1317);
  return v1326;
}

struct StateT * slot_1(struct StateT * v251) {
  int v252 = v251->timer;
  int v385 = v252 + 1;
  v251->timer = v385;
  int * v254 = v251->regs;
  int v255 = v254[11];
  int * v256 = v251->cache_tags;
  int v389 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2;
  int v257 = v256[v389];
  int * v258 = v251->cache_tags;
  int v391 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v259 = v258[v391];
  int * v260 = v251->cache_tags;
  int v393 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2);
  int v261 = v260[v393];
  int * v262 = v251->cache_tags;
  int v395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v263 = v262[v395];
  int v264 = v251->timer;
  int v396 = v264 + ((100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v251->timer = v396;
  int * v266 = v251->cache_vals;
  bool v397 = !(((~(((v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v257 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v379;
  if (v397) {
    int * v267 = v251->cache_age;
    int v399 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v268 = v267[v399];
    int * v269 = v251->cache_age;
    int v270 = v269[v389];
    int * v271 = v251->cache_age;
    int v402 = v270 + ((int)((unsigned int)(v270 - v268) >> 31));
    v271[v389] = v402;
    int * v273 = v251->cache_age;
    int v274 = v273[v391];
    int * v275 = v251->cache_age;
    int v405 = v274 + ((int)((unsigned int)(v274 - v268) >> 31));
    v275[v391] = v405;
    int * v277 = v251->cache_age;
    v277[v399] = 0;
    v379 = v399;
  } else {
    int * v280 = v251->cache_age;
    int v409 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2;
    int v281 = v280[v409];
    int * v282 = v251->cache_tags;
    int v283 = v282[v409];
    int * v284 = v251->cache_age;
    int v285 = v284[v391];
    int * v286 = v251->cache_tags;
    int v287 = v286[v391];
    bool v413 = !(((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v351;
    if (v413) {
      int * v288 = v251->cache_age;
      int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v289 = v288[v415];
      int * v290 = v251->cache_age;
      int v291 = v290[v393];
      int * v292 = v251->cache_age;
      int v418 = v291 + ((int)((unsigned int)(v291 - v289) >> 31));
      v292[v393] = v418;
      int * v294 = v251->cache_age;
      int v295 = v294[v395];
      int * v296 = v251->cache_age;
      int v421 = v295 + ((int)((unsigned int)(v295 - v289) >> 31));
      v296[v395] = v421;
      int * v298 = v251->cache_age;
      v298[v415] = 0;
      v351 = v415;
    } else {
      int * v301 = v251->cache_age;
      int v425 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2);
      int v302 = v301[v425];
      int * v303 = v251->cache_tags;
      int v304 = v303[v425];
      int * v305 = v251->cache_age;
      int v306 = v305[v395];
      int * v307 = v251->cache_tags;
      int v308 = v307[v395];
      int * v309 = v251->cache_dirty;
      int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v310 = v309[v430];
      bool v431 = !(v310 == 0);
      if (v431) {
        int * v311 = v251->cache_tags;
        int v312 = v311[v430];
        int * v313 = v251->cache_vals;
        int v434 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v314 = v313[v434];
        int * v315 = v251->cache_vals;
        int v436 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316 = v315[v436];
        int * v317 = v251->mem;
        int v438 = v312 * 2;
        v317[v438] = v314;
        int * v319 = v251->mem;
        int v441 = (v312 * 2) + 1;
        v319[v441] = v316;
        ;
      } else {
        ;
      }
      int * v324 = v251->mem;
      int v446 = ((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) * 2;
      int v325 = v324[v446];
      int * v326 = v251->mem;
      int v448 = (((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) * 2) + 1;
      int v327 = v326[v448];
      int * v328 = v251->cache_vals;
      int v450 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v328[v450] = v325;
      int * v330 = v251->cache_vals;
      int v453 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v302 + ((~(((v304 ^ -1) | (-(v304 ^ -1))) >> 31)) & 2)) - (v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v453] = v327;
      int * v332 = v251->cache_tags;
      int v456 = (int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1);
      v332[v430] = v456;
      int * v334 = v251->cache_dirty;
      v334[v430] = 0;
      int * v336 = v251->cache_age;
      v336[v430] = 1;
      int * v338 = v251->cache_age;
      int v339 = v338[v430];
      int * v340 = v251->cache_age;
      int v341 = v340[v393];
      int * v342 = v251->cache_age;
      int v464 = v341 + ((int)((unsigned int)(v341 - v339) >> 31));
      v342[v393] = v464;
      int * v344 = v251->cache_age;
      int v345 = v344[v395];
      int * v346 = v251->cache_age;
      int v467 = v345 + ((int)((unsigned int)(v345 - v339) >> 31));
      v346[v395] = v467;
      int * v348 = v251->cache_age;
      v348[v430] = 0;
      v351 = v430;
    }
    int * v352 = v251->cache_vals;
    int v470 = v351 * 2;
    int v353 = v352[v470];
    int * v354 = v251->cache_vals;
    int v472 = (v351 * 2) + 1;
    int v355 = v354[v472];
    int * v356 = v251->cache_vals;
    int v474 = (((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v356[v474] = v353;
    int * v358 = v251->cache_vals;
    int v477 = ((((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v358[v477] = v355;
    int * v360 = v251->cache_tags;
    int v480 = ((((int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v285 + ((~(((v287 ^ -1) | (-(v287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v481 = (int)((unsigned int)((int)((unsigned int)(v255 + 12) >> 2)) >> 1);
    v360[v480] = v481;
    int * v362 = v251->cache_dirty;
    v362[v480] = 0;
    int * v364 = v251->cache_age;
    v364[v480] = 1;
    int * v366 = v251->cache_age;
    int v367 = v366[v480];
    int * v368 = v251->cache_age;
    int v369 = v368[v389];
    int * v370 = v251->cache_age;
    int v489 = v369 + ((int)((unsigned int)(v369 - v367) >> 31));
    v370[v389] = v489;
    int * v372 = v251->cache_age;
    int v373 = v372[v391];
    int * v374 = v251->cache_age;
    int v492 = v373 + ((int)((unsigned int)(v373 - v367) >> 31));
    v374[v391] = v492;
    int * v376 = v251->cache_age;
    v376[v480] = 0;
    v379 = v480;
  }
  int v495 = (v379 * 2) + (((int)((unsigned int)(v255 + 12) >> 2)) & 1);
  int v380 = v266[v495];
  int * v381 = v251->regs;
  v381[14] = v380;
  struct StateT * v383 = slot_2(v251);
  return v383;
}

struct StateT * slot_8(struct StateT * v1280) {
  int v1281 = v1280->timer;
  int v1289 = v1281 + 1;
  v1280->timer = v1289;
  int * v1283 = v1280->regs;
  int v1284 = v1283[14];
  int * v1285 = v1280->regs;
  int v1293 = v1284 & 15;
  v1285[14] = v1293;
  struct StateT * v1287 = slot_9(v1280);
  return v1287;
}

struct StateT * slot_4(struct StateT * v533) {
  int v534 = v533->timer;
  int v546 = v534 + 1;
  v533->timer = v546;
  int * v536 = v533->regs;
  int v537 = v536[15];
  int * v538 = v533->regs;
  int v539 = v538[10];
  bool v551 = (v537 ^ -2147483648) < (v539 ^ -2147483648);
  struct StateT * v544;
  if (v551) {
    struct StateT * v540 = slot_13(v533);
    v544 = v540;
  } else {
    struct StateT * v542 = slot_5(v533);
    v544 = v542;
  }
  return v544;
}

struct StateT * slot_13(struct StateT * v557) {
  int v558 = v557->timer;
  int v566 = v558 + 1;
  v557->timer = v566;
  int * v560 = v557->regs;
  int v561 = v560[10];
  int * v562 = v557->regs;
  int v570 = v561 & 7;
  v562[10] = v570;
  struct StateT * v564 = slot_14(v557);
  return v564;
}

struct StateT * slot_15(struct StateT * v626) {
  int v627 = v626->timer;
  int v637 = v627 + 1;
  v626->timer = v637;
  int * v629 = v626->regs;
  int v630 = v629[13];
  int * v631 = v626->regs;
  int v632 = v631[10];
  int * v633 = v626->regs;
  int v643 = v630 + v632;
  v633[10] = v643;
  struct StateT * v635 = slot_16(v626);
  return v635;
}

struct StateT * slot_9(struct StateT * v1301) {
  int v1302 = v1301->timer;
  int v1310 = v1302 + 1;
  v1301->timer = v1310;
  int * v1304 = v1301->regs;
  int v1305 = v1304[14];
  int * v1306 = v1301->regs;
  int v1314 = v1305 << 2;
  v1306[14] = v1314;
  struct StateT * v1308 = slot_10(v1301);
  return v1308;
}

struct StateT * slot_11(struct StateT * v1337) {
  int v1338 = v1337->timer;
  int v1471 = v1338 + 1;
  v1337->timer = v1471;
  int * v1340 = v1337->regs;
  int v1341 = v1340[11];
  int * v1342 = v1337->cache_tags;
  int v1475 = (((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2;
  int v1343 = v1342[v1475];
  int * v1344 = v1337->cache_tags;
  int v1477 = ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1345 = v1344[v1477];
  int * v1346 = v1337->cache_tags;
  int v1479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2);
  int v1347 = v1346[v1479];
  int * v1348 = v1337->cache_tags;
  int v1481 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1349 = v1348[v1481];
  int v1350 = v1337->timer;
  int v1482 = v1350 + ((100 ^ (((~(((v1347 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1347 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) | (~(((v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1343 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1343 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) | (~(((v1345 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1345 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1347 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1347 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) | (~(((v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1337->timer = v1482;
  int * v1352 = v1337->cache_vals;
  bool v1483 = !(((~(((v1343 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1343 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) | (~(((v1345 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1345 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31))) == 0);
  int v1465;
  if (v1483) {
    int * v1353 = v1337->cache_age;
    int v1485 = ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2) + ((~(((v1345 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1345 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) & 1);
    int v1354 = v1353[v1485];
    int * v1355 = v1337->cache_age;
    int v1356 = v1355[v1475];
    int * v1357 = v1337->cache_age;
    int v1488 = v1356 + ((int)((unsigned int)(v1356 - v1354) >> 31));
    v1357[v1475] = v1488;
    int * v1359 = v1337->cache_age;
    int v1360 = v1359[v1477];
    int * v1361 = v1337->cache_age;
    int v1491 = v1360 + ((int)((unsigned int)(v1360 - v1354) >> 31));
    v1361[v1477] = v1491;
    int * v1363 = v1337->cache_age;
    v1363[v1485] = 0;
    v1465 = v1485;
  } else {
    int * v1366 = v1337->cache_age;
    int v1495 = (((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2;
    int v1367 = v1366[v1495];
    int * v1368 = v1337->cache_tags;
    int v1369 = v1368[v1495];
    int * v1370 = v1337->cache_age;
    int v1371 = v1370[v1477];
    int * v1372 = v1337->cache_tags;
    int v1373 = v1372[v1477];
    bool v1499 = !(((~(((v1347 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1347 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) | (~(((v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31))) == 0);
    int v1437;
    if (v1499) {
      int * v1374 = v1337->cache_age;
      int v1501 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))) | (-(v1349 ^ ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1))))) >> 31)) & 1);
      int v1375 = v1374[v1501];
      int * v1376 = v1337->cache_age;
      int v1377 = v1376[v1479];
      int * v1378 = v1337->cache_age;
      int v1504 = v1377 + ((int)((unsigned int)(v1377 - v1375) >> 31));
      v1378[v1479] = v1504;
      int * v1380 = v1337->cache_age;
      int v1381 = v1380[v1481];
      int * v1382 = v1337->cache_age;
      int v1507 = v1381 + ((int)((unsigned int)(v1381 - v1375) >> 31));
      v1382[v1481] = v1507;
      int * v1384 = v1337->cache_age;
      v1384[v1501] = 0;
      v1437 = v1501;
    } else {
      int * v1387 = v1337->cache_age;
      int v1511 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2);
      int v1388 = v1387[v1511];
      int * v1389 = v1337->cache_tags;
      int v1390 = v1389[v1511];
      int * v1391 = v1337->cache_age;
      int v1392 = v1391[v1481];
      int * v1393 = v1337->cache_tags;
      int v1394 = v1393[v1481];
      int * v1395 = v1337->cache_dirty;
      int v1516 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + ((((v1388 + ((~(((v1390 ^ -1) | (-(v1390 ^ -1))) >> 31)) & 2)) - (v1392 + ((~(((v1394 ^ -1) | (-(v1394 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1396 = v1395[v1516];
      bool v1517 = !(v1396 == 0);
      if (v1517) {
        int * v1397 = v1337->cache_tags;
        int v1398 = v1397[v1516];
        int * v1399 = v1337->cache_vals;
        int v1520 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + ((((v1388 + ((~(((v1390 ^ -1) | (-(v1390 ^ -1))) >> 31)) & 2)) - (v1392 + ((~(((v1394 ^ -1) | (-(v1394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1400 = v1399[v1520];
        int * v1401 = v1337->cache_vals;
        int v1522 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + ((((v1388 + ((~(((v1390 ^ -1) | (-(v1390 ^ -1))) >> 31)) & 2)) - (v1392 + ((~(((v1394 ^ -1) | (-(v1394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1402 = v1401[v1522];
        int * v1403 = v1337->mem;
        int v1524 = v1398 * 2;
        v1403[v1524] = v1400;
        int * v1405 = v1337->mem;
        int v1527 = (v1398 * 2) + 1;
        v1405[v1527] = v1402;
        ;
      } else {
        ;
      }
      int * v1410 = v1337->mem;
      int v1532 = ((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) * 2;
      int v1411 = v1410[v1532];
      int * v1412 = v1337->mem;
      int v1534 = (((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) * 2) + 1;
      int v1413 = v1412[v1534];
      int * v1414 = v1337->cache_vals;
      int v1536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + ((((v1388 + ((~(((v1390 ^ -1) | (-(v1390 ^ -1))) >> 31)) & 2)) - (v1392 + ((~(((v1394 ^ -1) | (-(v1394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1414[v1536] = v1411;
      int * v1416 = v1337->cache_vals;
      int v1539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 3) * 2)) + ((((v1388 + ((~(((v1390 ^ -1) | (-(v1390 ^ -1))) >> 31)) & 2)) - (v1392 + ((~(((v1394 ^ -1) | (-(v1394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1416[v1539] = v1413;
      int * v1418 = v1337->cache_tags;
      int v1542 = (int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1);
      v1418[v1516] = v1542;
      int * v1420 = v1337->cache_dirty;
      v1420[v1516] = 0;
      int * v1422 = v1337->cache_age;
      v1422[v1516] = 1;
      int * v1424 = v1337->cache_age;
      int v1425 = v1424[v1516];
      int * v1426 = v1337->cache_age;
      int v1427 = v1426[v1479];
      int * v1428 = v1337->cache_age;
      int v1550 = v1427 + ((int)((unsigned int)(v1427 - v1425) >> 31));
      v1428[v1479] = v1550;
      int * v1430 = v1337->cache_age;
      int v1431 = v1430[v1481];
      int * v1432 = v1337->cache_age;
      int v1553 = v1431 + ((int)((unsigned int)(v1431 - v1425) >> 31));
      v1432[v1481] = v1553;
      int * v1434 = v1337->cache_age;
      v1434[v1516] = 0;
      v1437 = v1516;
    }
    int * v1438 = v1337->cache_vals;
    int v1556 = v1437 * 2;
    int v1439 = v1438[v1556];
    int * v1440 = v1337->cache_vals;
    int v1558 = (v1437 * 2) + 1;
    int v1441 = v1440[v1558];
    int * v1442 = v1337->cache_vals;
    int v1560 = (((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2) + ((((v1367 + ((~(((v1369 ^ -1) | (-(v1369 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1373 ^ -1) | (-(v1373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1442[v1560] = v1439;
    int * v1444 = v1337->cache_vals;
    int v1563 = ((((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2) + ((((v1367 + ((~(((v1369 ^ -1) | (-(v1369 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1373 ^ -1) | (-(v1373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1444[v1563] = v1441;
    int * v1446 = v1337->cache_tags;
    int v1566 = ((((int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1)) & 1) * 2) + ((((v1367 + ((~(((v1369 ^ -1) | (-(v1369 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1373 ^ -1) | (-(v1373 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1567 = (int)((unsigned int)((int)((unsigned int)v1341 >> 2)) >> 1);
    v1446[v1566] = v1567;
    int * v1448 = v1337->cache_dirty;
    v1448[v1566] = 0;
    int * v1450 = v1337->cache_age;
    v1450[v1566] = 1;
    int * v1452 = v1337->cache_age;
    int v1453 = v1452[v1566];
    int * v1454 = v1337->cache_age;
    int v1455 = v1454[v1475];
    int * v1456 = v1337->cache_age;
    int v1575 = v1455 + ((int)((unsigned int)(v1455 - v1453) >> 31));
    v1456[v1475] = v1575;
    int * v1458 = v1337->cache_age;
    int v1459 = v1458[v1477];
    int * v1460 = v1337->cache_age;
    int v1578 = v1459 + ((int)((unsigned int)(v1459 - v1453) >> 31));
    v1460[v1477] = v1578;
    int * v1462 = v1337->cache_age;
    v1462[v1566] = 0;
    v1465 = v1566;
  }
  int v1581 = (v1465 * 2) + (((int)((unsigned int)v1341 >> 2)) & 1);
  int v1466 = v1352[v1581];
  int * v1467 = v1337->regs;
  v1467[11] = v1466;
  struct StateT * v1469 = slot_12(v1337);
  return v1469;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v136 = v3 + 1;
  v2->timer = v136;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_tags;
  int v140 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v140];
  int * v9 = v2->cache_tags;
  int v142 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v10 = v9[v142];
  int * v11 = v2->cache_tags;
  int v144 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v12 = v11[v144];
  int * v13 = v2->cache_tags;
  int v146 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14 = v13[v146];
  int v15 = v2->timer;
  int v147 = v15 + ((100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v147;
  int * v17 = v2->cache_vals;
  bool v148 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v130;
  if (v148) {
    int * v18 = v2->cache_age;
    int v150 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v19 = v18[v150];
    int * v20 = v2->cache_age;
    int v21 = v20[v140];
    int * v22 = v2->cache_age;
    int v153 = v21 + ((int)((unsigned int)(v21 - v19) >> 31));
    v22[v140] = v153;
    int * v24 = v2->cache_age;
    int v25 = v24[v142];
    int * v26 = v2->cache_age;
    int v156 = v25 + ((int)((unsigned int)(v25 - v19) >> 31));
    v26[v142] = v156;
    int * v28 = v2->cache_age;
    v28[v150] = 0;
    v130 = v150;
  } else {
    int * v31 = v2->cache_age;
    int v160 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v32 = v31[v160];
    int * v33 = v2->cache_tags;
    int v34 = v33[v160];
    int * v35 = v2->cache_age;
    int v36 = v35[v142];
    int * v37 = v2->cache_tags;
    int v38 = v37[v142];
    bool v164 = !(((~(((v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v12 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v102;
    if (v164) {
      int * v39 = v2->cache_age;
      int v166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v14 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v40 = v39[v166];
      int * v41 = v2->cache_age;
      int v42 = v41[v144];
      int * v43 = v2->cache_age;
      int v169 = v42 + ((int)((unsigned int)(v42 - v40) >> 31));
      v43[v144] = v169;
      int * v45 = v2->cache_age;
      int v46 = v45[v146];
      int * v47 = v2->cache_age;
      int v172 = v46 + ((int)((unsigned int)(v46 - v40) >> 31));
      v47[v146] = v172;
      int * v49 = v2->cache_age;
      v49[v166] = 0;
      v102 = v166;
    } else {
      int * v52 = v2->cache_age;
      int v176 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v53 = v52[v176];
      int * v54 = v2->cache_tags;
      int v55 = v54[v176];
      int * v56 = v2->cache_age;
      int v57 = v56[v146];
      int * v58 = v2->cache_tags;
      int v59 = v58[v146];
      int * v60 = v2->cache_dirty;
      int v181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v181];
      bool v182 = !(v61 == 0);
      if (v182) {
        int * v62 = v2->cache_tags;
        int v63 = v62[v181];
        int * v64 = v2->cache_vals;
        int v185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v185];
        int * v66 = v2->cache_vals;
        int v187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v66[v187];
        int * v68 = v2->mem;
        int v189 = v63 * 2;
        v68[v189] = v65;
        int * v70 = v2->mem;
        int v192 = (v63 * 2) + 1;
        v70[v192] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v2->mem;
      int v197 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v76 = v75[v197];
      int * v77 = v2->mem;
      int v199 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v78 = v77[v199];
      int * v79 = v2->cache_vals;
      int v201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v79[v201] = v76;
      int * v81 = v2->cache_vals;
      int v204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v53 + ((~(((v55 ^ -1) | (-(v55 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v81[v204] = v78;
      int * v83 = v2->cache_tags;
      int v207 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v83[v181] = v207;
      int * v85 = v2->cache_dirty;
      v85[v181] = 0;
      int * v87 = v2->cache_age;
      v87[v181] = 1;
      int * v89 = v2->cache_age;
      int v90 = v89[v181];
      int * v91 = v2->cache_age;
      int v92 = v91[v144];
      int * v93 = v2->cache_age;
      int v215 = v92 + ((int)((unsigned int)(v92 - v90) >> 31));
      v93[v144] = v215;
      int * v95 = v2->cache_age;
      int v96 = v95[v146];
      int * v97 = v2->cache_age;
      int v218 = v96 + ((int)((unsigned int)(v96 - v90) >> 31));
      v97[v146] = v218;
      int * v99 = v2->cache_age;
      v99[v181] = 0;
      v102 = v181;
    }
    int * v103 = v2->cache_vals;
    int v221 = v102 * 2;
    int v104 = v103[v221];
    int * v105 = v2->cache_vals;
    int v223 = (v102 * 2) + 1;
    int v106 = v105[v223];
    int * v107 = v2->cache_vals;
    int v225 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v107[v225] = v104;
    int * v109 = v2->cache_vals;
    int v228 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v109[v228] = v106;
    int * v111 = v2->cache_tags;
    int v231 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v32 + ((~(((v34 ^ -1) | (-(v34 ^ -1))) >> 31)) & 2)) - (v36 + ((~(((v38 ^ -1) | (-(v38 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v232 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v111[v231] = v232;
    int * v113 = v2->cache_dirty;
    v113[v231] = 0;
    int * v115 = v2->cache_age;
    v115[v231] = 1;
    int * v117 = v2->cache_age;
    int v118 = v117[v231];
    int * v119 = v2->cache_age;
    int v120 = v119[v140];
    int * v121 = v2->cache_age;
    int v240 = v120 + ((int)((unsigned int)(v120 - v118) >> 31));
    v121[v140] = v240;
    int * v123 = v2->cache_age;
    int v124 = v123[v142];
    int * v125 = v2->cache_age;
    int v243 = v124 + ((int)((unsigned int)(v124 - v118) >> 31));
    v125[v142] = v243;
    int * v127 = v2->cache_age;
    v127[v231] = 0;
    v130 = v231;
  }
  int v246 = (v130 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v131 = v17[v246];
  int * v132 = v2->regs;
  v132[12] = v131;
  struct StateT * v134 = slot_1(v2);
  return v134;
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
  
  // a10, public: one draw, written into both states
  int a10 = bounded(0, 23);
  s1.regs[10] = a10;
  s2.regs[10] = a10;
  // a11, 16 words read by the callee: the address is public
  s1.regs[11] = 0;
  s2.regs[11] = 0;
  // its contents, public: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[0 + i] = v;
    s2.mem[0 + i] = v;
  }
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 64;
  s2.regs[12] = 64;
  // a13, 8 words written by the callee: the address is public
  s1.regs[13] = 96;
  s2.regs[13] = 96;
  
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}