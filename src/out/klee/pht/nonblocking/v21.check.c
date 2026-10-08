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

struct StateT * slot_12(struct StateT * v808);
struct StateT * slot_14(struct StateT * v1187);
struct StateT * slot_6(struct StateT * v495);
struct StateT * slot_16(struct StateT * v868);
struct StateT * slot_5(struct StateT * v288);
struct StateT * slot_17(struct StateT * v251);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v511);
struct StateT * slot_3(struct StateT * v256);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v577);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v532);
struct StateT * slot_4(struct StateT * v272);
struct StateT * slot_13(struct StateT * v847);
struct StateT * slot_15(struct StateT * v831);
struct StateT * slot_9(struct StateT * v553);
struct StateT * slot_11(struct StateT * v784);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v808) {
  int v809 = v808->timer;
  int v821 = v809 + 1;
  v808->timer = v821;
  int * v811 = v808->reg_ready;
  int * v813 = v808->regs;
  int v814 = v813[13];
  bool v825 = !(v814 == 0);
  struct StateT * v819;
  if (v825) {
    struct StateT * v815 = slot_15(v808);
    v819 = v815;
  } else {
    struct StateT * v817 = slot_13(v808);
    v819 = v817;
  }
  return v819;
}

struct StateT * slot_14(struct StateT * v1187) {
  int v1188 = v1187->timer;
  int v1202 = v1188 + 1;
  v1187->timer = v1202;
  int * v1190 = v1187->reg_ready;
  int * v1192 = v1187->regs;
  int v1193 = v1192[10];
  int v1195 = v1192[11];
  bool v1207 = (v1193 ^ -2147483648) < (v1195 ^ -2147483648);
  struct StateT * v1200;
  if (v1207) {
    struct StateT * v1196 = slot_8(v1187);
    v1200 = v1196;
  } else {
    struct StateT * v1198 = slot_15(v1187);
    v1200 = v1198;
  }
  return v1200;
}

struct StateT * slot_6(struct StateT * v495) {
  int v496 = v495->timer;
  int v504 = v496 + 1;
  v495->timer = v504;
  int * v498 = v495->reg_ready;
  v498[14] = v504;
  int * v500 = v495->regs;
  v500[14] = 0;
  struct StateT * v502 = slot_7(v495);
  return v502;
}

struct StateT * slot_16(struct StateT * v868) {
  int v869 = v868->timer;
  int v1042 = v869 + 1;
  v868->timer = v1042;
  int * v871 = v868->reg_ready;
  int * v873 = v868->regs;
  int v874 = v873[10];
  int v876 = v873[12];
  int * v877 = v868->cache_tags;
  int v1048 = (((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2;
  int v878 = v877[v1048];
  int v1049 = ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v879 = v877[v1049];
  int v1050 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2);
  int v880 = v877[v1050];
  int v1051 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v881 = v877[v1051];
  int v882 = v868->timer;
  int v1052 = v882 + ((100 ^ (((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v868->timer = v1052;
  bool v1053 = !(((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v976;
  if (v1053) {
    int * v884 = v868->cache_age;
    int v1055 = ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v885 = v884[v1055];
    int v886 = v884[v1048];
    int v1056 = v886 + ((int)((unsigned int)(v886 - v885) >> 31));
    v884[v1048] = v1056;
    int * v888 = v868->cache_age;
    int v889 = v888[v1049];
    int v1058 = v889 + ((int)((unsigned int)(v889 - v885) >> 31));
    v888[v1049] = v1058;
    int * v891 = v868->cache_age;
    v891[v1055] = 0;
    v976 = v1055;
  } else {
    int * v894 = v868->cache_age;
    int v1062 = (((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2;
    int v895 = v894[v1062];
    int * v896 = v868->cache_tags;
    int v897 = v896[v1062];
    int v898 = v894[v1049];
    int v899 = v896[v1049];
    bool v1064 = !(((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v953;
    if (v1064) {
      int * v900 = v868->cache_age;
      int v1066 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v881 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v901 = v900[v1066];
      int v902 = v900[v1050];
      int v1067 = v902 + ((int)((unsigned int)(v902 - v901) >> 31));
      v900[v1050] = v1067;
      int * v904 = v868->cache_age;
      int v905 = v904[v1051];
      int v1069 = v905 + ((int)((unsigned int)(v905 - v901) >> 31));
      v904[v1051] = v1069;
      int * v907 = v868->cache_age;
      v907[v1066] = 0;
      v953 = v1066;
    } else {
      int * v910 = v868->cache_age;
      int v1073 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2);
      int v911 = v910[v1073];
      int * v912 = v868->cache_tags;
      int v913 = v912[v1073];
      int v914 = v910[v1051];
      int v915 = v912[v1051];
      int * v916 = v868->cache_dirty;
      int v1076 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v917 = v916[v1076];
      bool v1077 = !(v917 == 0);
      if (v1077) {
        int * v918 = v868->cache_tags;
        int v919 = v918[v1076];
        int * v920 = v868->cache_vals;
        int v1080 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v921 = v920[v1080];
        int v1081 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v922 = v920[v1081];
        int * v923 = v868->mem;
        int v1083 = v919 * 2;
        v923[v1083] = v921;
        int * v925 = v868->mem;
        int v1086 = (v919 * 2) + 1;
        v925[v1086] = v922;
        ;
      } else {
        ;
      }
      int * v930 = v868->mem;
      int v1091 = ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) * 2;
      int v931 = v930[v1091];
      int v1092 = (((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) * 2) + 1;
      int v932 = v930[v1092];
      int * v933 = v868->cache_vals;
      int v1094 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v933[v1094] = v931;
      int * v935 = v868->cache_vals;
      int v1097 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v935[v1097] = v932;
      int * v937 = v868->cache_tags;
      int v1100 = (int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1);
      v937[v1076] = v1100;
      int * v939 = v868->cache_dirty;
      v939[v1076] = 0;
      int * v941 = v868->cache_age;
      v941[v1076] = 1;
      int * v943 = v868->cache_age;
      int v944 = v943[v1076];
      int v945 = v943[v1050];
      int v1106 = v945 + ((int)((unsigned int)(v945 - v944) >> 31));
      v943[v1050] = v1106;
      int * v947 = v868->cache_age;
      int v948 = v947[v1051];
      int v1108 = v948 + ((int)((unsigned int)(v948 - v944) >> 31));
      v947[v1051] = v1108;
      int * v950 = v868->cache_age;
      v950[v1076] = 0;
      v953 = v1076;
    }
    int * v954 = v868->cache_vals;
    int v1111 = v953 * 2;
    int v955 = v954[v1111];
    int v1112 = (v953 * 2) + 1;
    int v956 = v954[v1112];
    int v1113 = (((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v954[v1113] = v955;
    int * v958 = v868->cache_vals;
    int v1116 = ((((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v958[v1116] = v956;
    int * v960 = v868->cache_tags;
    int v1119 = ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1120 = (int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1);
    v960[v1119] = v1120;
    int * v962 = v868->cache_dirty;
    v962[v1119] = 0;
    int * v964 = v868->cache_age;
    v964[v1119] = 1;
    int * v966 = v868->cache_age;
    int v967 = v966[v1119];
    int v968 = v966[v1048];
    int v1126 = v968 + ((int)((unsigned int)(v968 - v967) >> 31));
    v966[v1048] = v1126;
    int * v970 = v868->cache_age;
    int v971 = v970[v1049];
    int v1128 = v971 + ((int)((unsigned int)(v971 - v967) >> 31));
    v970[v1049] = v1128;
    int * v973 = v868->cache_age;
    v973[v1119] = 0;
    v976 = v1119;
  }
  int * v977 = v868->cache_vals;
  int v1131 = (v976 * 2) + (((int)((unsigned int)(v874 + 68) >> 2)) & 1);
  v977[v1131] = v876;
  int * v979 = v868->cache_tags;
  int v980 = v979[v1050];
  int v981 = v979[v1051];
  bool v1134 = !(((~(((v980 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v980 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v981 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v981 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1035;
  if (v1134) {
    int * v982 = v868->cache_age;
    int v1136 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v981 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))) | (-(v981 ^ ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v983 = v982[v1136];
    int v984 = v982[v1050];
    int v1137 = v984 + ((int)((unsigned int)(v984 - v983) >> 31));
    v982[v1050] = v1137;
    int * v986 = v868->cache_age;
    int v987 = v986[v1051];
    int v1139 = v987 + ((int)((unsigned int)(v987 - v983) >> 31));
    v986[v1051] = v1139;
    int * v989 = v868->cache_age;
    v989[v1136] = 0;
    v1035 = v1136;
  } else {
    int * v992 = v868->cache_age;
    int v1143 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2);
    int v993 = v992[v1143];
    int * v994 = v868->cache_tags;
    int v995 = v994[v1143];
    int v996 = v992[v1051];
    int v997 = v994[v1051];
    int * v998 = v868->cache_dirty;
    int v1146 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v999 = v998[v1146];
    bool v1147 = !(v999 == 0);
    if (v1147) {
      int * v1000 = v868->cache_tags;
      int v1001 = v1000[v1146];
      int * v1002 = v868->cache_vals;
      int v1150 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1003 = v1002[v1150];
      int v1151 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1004 = v1002[v1151];
      int * v1005 = v868->mem;
      int v1153 = v1001 * 2;
      v1005[v1153] = v1003;
      int * v1007 = v868->mem;
      int v1156 = (v1001 * 2) + 1;
      v1007[v1156] = v1004;
      ;
    } else {
      ;
    }
    int * v1012 = v868->mem;
    int v1161 = ((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) * 2;
    int v1013 = v1012[v1161];
    int v1162 = (((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1014 = v1012[v1162];
    int * v1015 = v868->cache_vals;
    int v1164 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1015[v1164] = v1013;
    int * v1017 = v868->cache_vals;
    int v1167 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1017[v1167] = v1014;
    int * v1019 = v868->cache_tags;
    int v1170 = (int)((unsigned int)((int)((unsigned int)(v874 + 68) >> 2)) >> 1);
    v1019[v1146] = v1170;
    int * v1021 = v868->cache_dirty;
    v1021[v1146] = 0;
    int * v1023 = v868->cache_age;
    v1023[v1146] = 1;
    int * v1025 = v868->cache_age;
    int v1026 = v1025[v1146];
    int v1027 = v1025[v1050];
    int v1176 = v1027 + ((int)((unsigned int)(v1027 - v1026) >> 31));
    v1025[v1050] = v1176;
    int * v1029 = v868->cache_age;
    int v1030 = v1029[v1051];
    int v1178 = v1030 + ((int)((unsigned int)(v1030 - v1026) >> 31));
    v1029[v1051] = v1178;
    int * v1032 = v868->cache_age;
    v1032[v1146] = 0;
    v1035 = v1146;
  }
  int * v1036 = v868->cache_vals;
  int v1181 = (v1035 * 2) + (((int)((unsigned int)(v874 + 68) >> 2)) & 1);
  v1036[v1181] = v876;
  int * v1038 = v868->cache_dirty;
  v1038[v1035] = 1;
  struct StateT * v1040 = slot_17(v868);
  return v1040;
}

struct StateT * slot_5(struct StateT * v288) {
  int v289 = v288->timer;
  int v401 = v289 + 1;
  v288->timer = v401;
  int * v291 = v288->reg_ready;
  int v292 = v291[12];
  int * v293 = v288->regs;
  int v294 = v293[12];
  int * v295 = v288->cache_tags;
  int v406 = (((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2;
  int v296 = v295[v406];
  int v407 = ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v297 = v295[v407];
  int v408 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2);
  int v298 = v295[v408];
  int v409 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v299 = v295[v409];
  int * v300 = v288->cache_vals;
  bool v410 = !(((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v393;
  if (v410) {
    int * v301 = v288->cache_age;
    int v412 = ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v302 = v301[v412];
    int v303 = v301[v406];
    int v413 = v303 + ((int)((unsigned int)(v303 - v302) >> 31));
    v301[v406] = v413;
    int * v305 = v288->cache_age;
    int v306 = v305[v407];
    int v415 = v306 + ((int)((unsigned int)(v306 - v302) >> 31));
    v305[v407] = v415;
    int * v308 = v288->cache_age;
    v308[v412] = 0;
    v393 = v412;
  } else {
    int * v311 = v288->cache_age;
    int v419 = (((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2;
    int v312 = v311[v419];
    int * v313 = v288->cache_tags;
    int v314 = v313[v419];
    int v315 = v311[v407];
    int v316 = v313[v407];
    bool v421 = !(((~(((v298 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v298 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v370;
    if (v421) {
      int * v317 = v288->cache_age;
      int v423 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v318 = v317[v423];
      int v319 = v317[v408];
      int v424 = v319 + ((int)((unsigned int)(v319 - v318) >> 31));
      v317[v408] = v424;
      int * v321 = v288->cache_age;
      int v322 = v321[v409];
      int v426 = v322 + ((int)((unsigned int)(v322 - v318) >> 31));
      v321[v409] = v426;
      int * v324 = v288->cache_age;
      v324[v423] = 0;
      v370 = v423;
    } else {
      int * v327 = v288->cache_age;
      int v430 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2);
      int v328 = v327[v430];
      int * v329 = v288->cache_tags;
      int v330 = v329[v430];
      int v331 = v327[v409];
      int v332 = v329[v409];
      int * v333 = v288->cache_dirty;
      int v433 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v334 = v333[v433];
      bool v434 = !(v334 == 0);
      if (v434) {
        int * v335 = v288->cache_tags;
        int v336 = v335[v433];
        int * v337 = v288->cache_vals;
        int v437 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v338 = v337[v437];
        int v438 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v339 = v337[v438];
        int * v340 = v288->mem;
        int v440 = v336 * 2;
        v340[v440] = v338;
        int * v342 = v288->mem;
        int v443 = (v336 * 2) + 1;
        v342[v443] = v339;
        ;
      } else {
        ;
      }
      int * v347 = v288->mem;
      int v448 = ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) * 2;
      int v348 = v347[v448];
      int v449 = (((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) * 2) + 1;
      int v349 = v347[v449];
      int * v350 = v288->cache_vals;
      int v451 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v350[v451] = v348;
      int * v352 = v288->cache_vals;
      int v454 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v352[v454] = v349;
      int * v354 = v288->cache_tags;
      int v457 = (int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1);
      v354[v433] = v457;
      int * v356 = v288->cache_dirty;
      v356[v433] = 0;
      int * v358 = v288->cache_age;
      v358[v433] = 1;
      int * v360 = v288->cache_age;
      int v361 = v360[v433];
      int v362 = v360[v408];
      int v463 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
      v360[v408] = v463;
      int * v364 = v288->cache_age;
      int v365 = v364[v409];
      int v465 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
      v364[v409] = v465;
      int * v367 = v288->cache_age;
      v367[v433] = 0;
      v370 = v433;
    }
    int * v371 = v288->cache_vals;
    int v468 = v370 * 2;
    int v372 = v371[v468];
    int v469 = (v370 * 2) + 1;
    int v373 = v371[v469];
    int v470 = (((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v371[v470] = v372;
    int * v375 = v288->cache_vals;
    int v473 = ((((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v375[v473] = v373;
    int * v377 = v288->cache_tags;
    int v476 = ((((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v477 = (int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1);
    v377[v476] = v477;
    int * v379 = v288->cache_dirty;
    v379[v476] = 0;
    int * v381 = v288->cache_age;
    v381[v476] = 1;
    int * v383 = v288->cache_age;
    int v384 = v383[v476];
    int v385 = v383[v406];
    int v483 = v385 + ((int)((unsigned int)(v385 - v384) >> 31));
    v383[v406] = v483;
    int * v387 = v288->cache_age;
    int v388 = v387[v407];
    int v485 = v388 + ((int)((unsigned int)(v388 - v384) >> 31));
    v387[v407] = v485;
    int * v390 = v288->cache_age;
    v390[v476] = 0;
    v393 = v476;
  }
  int v488 = (v393 * 2) + (((int)((unsigned int)(v294 + 68) >> 2)) & 1);
  int v394 = v300[v488];
  int * v395 = v288->reg_ready;
  int v490 = ((v292 + ((v289 - v292) & (~((v289 - v292) >> 31)))) + 1) + ((100 ^ (((~(((v298 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v298 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v298 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v298 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))) | (-(v299 ^ ((int)((unsigned int)((int)((unsigned int)(v294 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v395[12] = v490;
  int * v397 = v288->regs;
  v397[12] = v394;
  struct StateT * v399 = slot_6(v288);
  return v399;
}

struct StateT * slot_17(struct StateT * v251) {
  int v252 = v251->timer;
  int v255 = v252 + 1;
  v251->timer = v255;
  return v251;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v240 = v226 + 1;
  v225->timer = v240;
  int * v228 = v225->reg_ready;
  int * v230 = v225->regs;
  int v231 = v230[10];
  int v233 = v230[11];
  bool v245 = (v231 ^ -2147483648) >= (v233 ^ -2147483648);
  struct StateT * v238;
  if (v245) {
    struct StateT * v234 = slot_17(v225);
    v238 = v234;
  } else {
    struct StateT * v236 = slot_3(v225);
    v238 = v236;
  }
  return v238;
}

struct StateT * slot_7(struct StateT * v511) {
  int v512 = v511->timer;
  int v523 = v512 + 1;
  v511->timer = v523;
  int * v514 = v511->reg_ready;
  int v515 = v514[14];
  int * v516 = v511->regs;
  int v517 = v516[14];
  int v527 = (v515 + ((v512 - v515) & (~((v512 - v515) >> 31)))) + 1;
  v514[14] = v527;
  int * v519 = v511->regs;
  int v529 = v517 + 72;
  v519[14] = v529;
  struct StateT * v521 = slot_8(v511);
  return v521;
}

struct StateT * slot_3(struct StateT * v256) {
  int v257 = v256->timer;
  int v265 = v257 + 1;
  v256->timer = v265;
  int * v259 = v256->reg_ready;
  v259[13] = v265;
  int * v261 = v256->regs;
  v261[13] = 0;
  struct StateT * v263 = slot_4(v256);
  return v263;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1213 = v1->timer;
  int * v1214 = v1->reg_ready;
  int v1215 = v1214[0];
  int v1346 = v1215 + ((v1213 - v1215) & (~((v1213 - v1215) >> 31)));
  v1->timer = v1346;
  int v1217 = v1->timer;
  int * v1218 = v1->reg_ready;
  int v1219 = v1218[1];
  int v1349 = v1219 + ((v1217 - v1219) & (~((v1217 - v1219) >> 31)));
  v1->timer = v1349;
  int v1221 = v1->timer;
  int * v1222 = v1->reg_ready;
  int v1223 = v1222[2];
  int v1352 = v1223 + ((v1221 - v1223) & (~((v1221 - v1223) >> 31)));
  v1->timer = v1352;
  int v1225 = v1->timer;
  int * v1226 = v1->reg_ready;
  int v1227 = v1226[3];
  int v1355 = v1227 + ((v1225 - v1227) & (~((v1225 - v1227) >> 31)));
  v1->timer = v1355;
  int v1229 = v1->timer;
  int * v1230 = v1->reg_ready;
  int v1231 = v1230[4];
  int v1358 = v1231 + ((v1229 - v1231) & (~((v1229 - v1231) >> 31)));
  v1->timer = v1358;
  int v1233 = v1->timer;
  int * v1234 = v1->reg_ready;
  int v1235 = v1234[5];
  int v1361 = v1235 + ((v1233 - v1235) & (~((v1233 - v1235) >> 31)));
  v1->timer = v1361;
  int v1237 = v1->timer;
  int * v1238 = v1->reg_ready;
  int v1239 = v1238[6];
  int v1364 = v1239 + ((v1237 - v1239) & (~((v1237 - v1239) >> 31)));
  v1->timer = v1364;
  int v1241 = v1->timer;
  int * v1242 = v1->reg_ready;
  int v1243 = v1242[7];
  int v1367 = v1243 + ((v1241 - v1243) & (~((v1241 - v1243) >> 31)));
  v1->timer = v1367;
  int v1245 = v1->timer;
  int * v1246 = v1->reg_ready;
  int v1247 = v1246[8];
  int v1370 = v1247 + ((v1245 - v1247) & (~((v1245 - v1247) >> 31)));
  v1->timer = v1370;
  int v1249 = v1->timer;
  int * v1250 = v1->reg_ready;
  int v1251 = v1250[9];
  int v1373 = v1251 + ((v1249 - v1251) & (~((v1249 - v1251) >> 31)));
  v1->timer = v1373;
  int v1253 = v1->timer;
  int * v1254 = v1->reg_ready;
  int v1255 = v1254[10];
  int v1376 = v1255 + ((v1253 - v1255) & (~((v1253 - v1255) >> 31)));
  v1->timer = v1376;
  int v1257 = v1->timer;
  int * v1258 = v1->reg_ready;
  int v1259 = v1258[11];
  int v1379 = v1259 + ((v1257 - v1259) & (~((v1257 - v1259) >> 31)));
  v1->timer = v1379;
  int v1261 = v1->timer;
  int * v1262 = v1->reg_ready;
  int v1263 = v1262[12];
  int v1382 = v1263 + ((v1261 - v1263) & (~((v1261 - v1263) >> 31)));
  v1->timer = v1382;
  int v1265 = v1->timer;
  int * v1266 = v1->reg_ready;
  int v1267 = v1266[13];
  int v1385 = v1267 + ((v1265 - v1267) & (~((v1265 - v1267) >> 31)));
  v1->timer = v1385;
  int v1269 = v1->timer;
  int * v1270 = v1->reg_ready;
  int v1271 = v1270[14];
  int v1388 = v1271 + ((v1269 - v1271) & (~((v1269 - v1271) >> 31)));
  v1->timer = v1388;
  int v1273 = v1->timer;
  int * v1274 = v1->reg_ready;
  int v1275 = v1274[15];
  int v1391 = v1275 + ((v1273 - v1275) & (~((v1273 - v1275) >> 31)));
  v1->timer = v1391;
  int v1277 = v1->timer;
  int * v1278 = v1->reg_ready;
  int v1279 = v1278[16];
  int v1394 = v1279 + ((v1277 - v1279) & (~((v1277 - v1279) >> 31)));
  v1->timer = v1394;
  int v1281 = v1->timer;
  int * v1282 = v1->reg_ready;
  int v1283 = v1282[17];
  int v1397 = v1283 + ((v1281 - v1283) & (~((v1281 - v1283) >> 31)));
  v1->timer = v1397;
  int v1285 = v1->timer;
  int * v1286 = v1->reg_ready;
  int v1287 = v1286[18];
  int v1400 = v1287 + ((v1285 - v1287) & (~((v1285 - v1287) >> 31)));
  v1->timer = v1400;
  int v1289 = v1->timer;
  int * v1290 = v1->reg_ready;
  int v1291 = v1290[19];
  int v1403 = v1291 + ((v1289 - v1291) & (~((v1289 - v1291) >> 31)));
  v1->timer = v1403;
  int v1293 = v1->timer;
  int * v1294 = v1->reg_ready;
  int v1295 = v1294[20];
  int v1406 = v1295 + ((v1293 - v1295) & (~((v1293 - v1295) >> 31)));
  v1->timer = v1406;
  int v1297 = v1->timer;
  int * v1298 = v1->reg_ready;
  int v1299 = v1298[21];
  int v1409 = v1299 + ((v1297 - v1299) & (~((v1297 - v1299) >> 31)));
  v1->timer = v1409;
  int v1301 = v1->timer;
  int * v1302 = v1->reg_ready;
  int v1303 = v1302[22];
  int v1412 = v1303 + ((v1301 - v1303) & (~((v1301 - v1303) >> 31)));
  v1->timer = v1412;
  int v1305 = v1->timer;
  int * v1306 = v1->reg_ready;
  int v1307 = v1306[23];
  int v1415 = v1307 + ((v1305 - v1307) & (~((v1305 - v1307) >> 31)));
  v1->timer = v1415;
  int v1309 = v1->timer;
  int * v1310 = v1->reg_ready;
  int v1311 = v1310[24];
  int v1418 = v1311 + ((v1309 - v1311) & (~((v1309 - v1311) >> 31)));
  v1->timer = v1418;
  int v1313 = v1->timer;
  int * v1314 = v1->reg_ready;
  int v1315 = v1314[25];
  int v1421 = v1315 + ((v1313 - v1315) & (~((v1313 - v1315) >> 31)));
  v1->timer = v1421;
  int v1317 = v1->timer;
  int * v1318 = v1->reg_ready;
  int v1319 = v1318[26];
  int v1424 = v1319 + ((v1317 - v1319) & (~((v1317 - v1319) >> 31)));
  v1->timer = v1424;
  int v1321 = v1->timer;
  int * v1322 = v1->reg_ready;
  int v1323 = v1322[27];
  int v1427 = v1323 + ((v1321 - v1323) & (~((v1321 - v1323) >> 31)));
  v1->timer = v1427;
  int v1325 = v1->timer;
  int * v1326 = v1->reg_ready;
  int v1327 = v1326[28];
  int v1430 = v1327 + ((v1325 - v1327) & (~((v1325 - v1327) >> 31)));
  v1->timer = v1430;
  int v1329 = v1->timer;
  int * v1330 = v1->reg_ready;
  int v1331 = v1330[29];
  int v1433 = v1331 + ((v1329 - v1331) & (~((v1329 - v1331) >> 31)));
  v1->timer = v1433;
  int v1333 = v1->timer;
  int * v1334 = v1->reg_ready;
  int v1335 = v1334[30];
  int v1436 = v1335 + ((v1333 - v1335) & (~((v1333 - v1335) >> 31)));
  v1->timer = v1436;
  int v1337 = v1->timer;
  int * v1338 = v1->reg_ready;
  int v1339 = v1338[31];
  int v1439 = v1339 + ((v1337 - v1339) & (~((v1337 - v1339) >> 31)));
  v1->timer = v1439;
  return v1;
}

struct StateT * slot_10(struct StateT * v577) {
  int v578 = v577->timer;
  int v690 = v578 + 1;
  v577->timer = v690;
  int * v580 = v577->reg_ready;
  int v581 = v580[10];
  int * v582 = v577->regs;
  int v583 = v582[10];
  int * v584 = v577->cache_tags;
  int v695 = (((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2;
  int v585 = v584[v695];
  int v696 = ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2) + 1;
  int v586 = v584[v696];
  int v697 = 4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2);
  int v587 = v584[v697];
  int v698 = (4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v588 = v584[v698];
  int * v589 = v577->cache_vals;
  bool v699 = !(((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31))) == 0);
  int v682;
  if (v699) {
    int * v590 = v577->cache_age;
    int v701 = ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2) + ((~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) & 1);
    int v591 = v590[v701];
    int v592 = v590[v695];
    int v702 = v592 + ((int)((unsigned int)(v592 - v591) >> 31));
    v590[v695] = v702;
    int * v594 = v577->cache_age;
    int v595 = v594[v696];
    int v704 = v595 + ((int)((unsigned int)(v595 - v591) >> 31));
    v594[v696] = v704;
    int * v597 = v577->cache_age;
    v597[v701] = 0;
    v682 = v701;
  } else {
    int * v600 = v577->cache_age;
    int v708 = (((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2;
    int v601 = v600[v708];
    int * v602 = v577->cache_tags;
    int v603 = v602[v708];
    int v604 = v600[v696];
    int v605 = v602[v696];
    bool v710 = !(((~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) | (~(((v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31))) == 0);
    int v659;
    if (v710) {
      int * v606 = v577->cache_age;
      int v712 = (4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + ((~(((v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) & 1);
      int v607 = v606[v712];
      int v608 = v606[v697];
      int v713 = v608 + ((int)((unsigned int)(v608 - v607) >> 31));
      v606[v697] = v713;
      int * v610 = v577->cache_age;
      int v611 = v610[v698];
      int v715 = v611 + ((int)((unsigned int)(v611 - v607) >> 31));
      v610[v698] = v715;
      int * v613 = v577->cache_age;
      v613[v712] = 0;
      v659 = v712;
    } else {
      int * v616 = v577->cache_age;
      int v719 = 4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2);
      int v617 = v616[v719];
      int * v618 = v577->cache_tags;
      int v619 = v618[v719];
      int v620 = v616[v698];
      int v621 = v618[v698];
      int * v622 = v577->cache_dirty;
      int v722 = (4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v623 = v622[v722];
      bool v723 = !(v623 == 0);
      if (v723) {
        int * v624 = v577->cache_tags;
        int v625 = v624[v722];
        int * v626 = v577->cache_vals;
        int v726 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v627 = v626[v726];
        int v727 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v628 = v626[v727];
        int * v629 = v577->mem;
        int v729 = v625 * 2;
        v629[v729] = v627;
        int * v631 = v577->mem;
        int v732 = (v625 * 2) + 1;
        v631[v732] = v628;
        ;
      } else {
        ;
      }
      int * v636 = v577->mem;
      int v737 = ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) * 2;
      int v637 = v636[v737];
      int v738 = (((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) * 2) + 1;
      int v638 = v636[v738];
      int * v639 = v577->cache_vals;
      int v740 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v639[v740] = v637;
      int * v641 = v577->cache_vals;
      int v743 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v641[v743] = v638;
      int * v643 = v577->cache_tags;
      int v746 = (int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1);
      v643[v722] = v746;
      int * v645 = v577->cache_dirty;
      v645[v722] = 0;
      int * v647 = v577->cache_age;
      v647[v722] = 1;
      int * v649 = v577->cache_age;
      int v650 = v649[v722];
      int v651 = v649[v697];
      int v752 = v651 + ((int)((unsigned int)(v651 - v650) >> 31));
      v649[v697] = v752;
      int * v653 = v577->cache_age;
      int v654 = v653[v698];
      int v754 = v654 + ((int)((unsigned int)(v654 - v650) >> 31));
      v653[v698] = v754;
      int * v656 = v577->cache_age;
      v656[v722] = 0;
      v659 = v722;
    }
    int * v660 = v577->cache_vals;
    int v757 = v659 * 2;
    int v661 = v660[v757];
    int v758 = (v659 * 2) + 1;
    int v662 = v660[v758];
    int v759 = (((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v660[v759] = v661;
    int * v664 = v577->cache_vals;
    int v762 = ((((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v664[v762] = v662;
    int * v666 = v577->cache_tags;
    int v765 = ((((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v766 = (int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1);
    v666[v765] = v766;
    int * v668 = v577->cache_dirty;
    v668[v765] = 0;
    int * v670 = v577->cache_age;
    v670[v765] = 1;
    int * v672 = v577->cache_age;
    int v673 = v672[v765];
    int v674 = v672[v695];
    int v772 = v674 + ((int)((unsigned int)(v674 - v673) >> 31));
    v672[v695] = v772;
    int * v676 = v577->cache_age;
    int v677 = v676[v696];
    int v774 = v677 + ((int)((unsigned int)(v677 - v673) >> 31));
    v676[v696] = v774;
    int * v679 = v577->cache_age;
    v679[v765] = 0;
    v682 = v765;
  }
  int v777 = (v682 * 2) + (((int)((unsigned int)v583 >> 2)) & 1);
  int v683 = v589[v777];
  int * v684 = v577->reg_ready;
  int v779 = ((v581 + ((v578 - v581) & (~((v578 - v581) >> 31)))) + 1) + ((100 ^ (((~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) | (~(((v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v587 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v587 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31)) | (~(((v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))) | (-(v588 ^ ((int)((unsigned int)((int)((unsigned int)v583 >> 2)) >> 1))))) >> 31))) & 104)))));
  v684[10] = v779;
  int * v686 = v577->regs;
  v686[10] = v683;
  struct StateT * v688 = slot_11(v577);
  return v688;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[11];
  int * v23 = v18->regs;
  int v24 = v23[11];
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
  int v220 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[11] = v220;
  int * v127 = v18->regs;
  v127[11] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v532) {
  int v533 = v532->timer;
  int v544 = v533 + 1;
  v532->timer = v544;
  int * v535 = v532->reg_ready;
  int v536 = v535[10];
  int * v537 = v532->regs;
  int v538 = v537[10];
  int v548 = (v536 + ((v533 - v536) & (~((v533 - v536) >> 31)))) + 1;
  v535[10] = v548;
  int * v540 = v532->regs;
  int v550 = v538 << 2;
  v540[10] = v550;
  struct StateT * v542 = slot_9(v532);
  return v542;
}

struct StateT * slot_4(struct StateT * v272) {
  int v273 = v272->timer;
  int v281 = v273 + 1;
  v272->timer = v281;
  int * v275 = v272->reg_ready;
  v275[12] = v281;
  int * v277 = v272->regs;
  v277[12] = 0;
  struct StateT * v279 = slot_5(v272);
  return v279;
}

struct StateT * slot_13(struct StateT * v847) {
  int v848 = v847->timer;
  int v859 = v848 + 1;
  v847->timer = v859;
  int * v850 = v847->reg_ready;
  int v851 = v850[13];
  int * v852 = v847->regs;
  int v853 = v852[13];
  int v863 = (v851 + ((v848 - v851) & (~((v848 - v851) >> 31)))) + 1;
  v850[13] = v863;
  int * v855 = v847->regs;
  int v865 = v853 + -1;
  v855[13] = v865;
  struct StateT * v857 = slot_14(v847);
  return v857;
}

struct StateT * slot_15(struct StateT * v831) {
  int v832 = v831->timer;
  int v840 = v832 + 1;
  v831->timer = v840;
  int * v834 = v831->reg_ready;
  v834[10] = v840;
  int * v836 = v831->regs;
  v836[10] = 0;
  struct StateT * v838 = slot_16(v831);
  return v838;
}

struct StateT * slot_9(struct StateT * v553) {
  int v554 = v553->timer;
  int v567 = v554 + 1;
  v553->timer = v567;
  int * v556 = v553->reg_ready;
  int v557 = v556[14];
  int * v558 = v553->regs;
  int v559 = v558[14];
  int v560 = v556[10];
  int v561 = v558[10];
  int v572 = (v560 + (((v557 + ((v554 - v557) & (~((v554 - v557) >> 31)))) - v560) & (~(((v557 + ((v554 - v557) & (~((v554 - v557) >> 31)))) - v560) >> 31)))) + 1;
  v556[10] = v572;
  int * v563 = v553->regs;
  int v574 = v559 + v561;
  v563[10] = v574;
  struct StateT * v565 = slot_10(v553);
  return v565;
}

struct StateT * slot_11(struct StateT * v784) {
  int v785 = v784->timer;
  int v798 = v785 + 1;
  v784->timer = v798;
  int * v787 = v784->reg_ready;
  int v788 = v787[12];
  int * v789 = v784->regs;
  int v790 = v789[12];
  int v791 = v787[10];
  int v792 = v789[10];
  int v803 = (v791 + (((v788 + ((v785 - v788) & (~((v785 - v788) >> 31)))) - v791) & (~(((v788 + ((v785 - v788) & (~((v785 - v788) >> 31)))) - v791) >> 31)))) + 1;
  v787[12] = v803;
  int * v794 = v784->regs;
  int v805 = v790 & v792;
  v794[12] = v805;
  struct StateT * v796 = slot_12(v784);
  return v796;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[11] = v11;
  int * v7 = v2->regs;
  v7[11] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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