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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_6(struct StateT * v1019);
struct StateT * slot_5(struct StateT * v815);
struct StateT * slot_4(struct StateT * v625);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_3(struct StateT * v329);
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
  int v21 = v20[5];
  int v29 = v21 + 80;
  v20[6] = v29;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_6(struct StateT * v1019) {
  int v1020 = v1019->timer;
  int v1129 = v1020 + 1;
  v1019->timer = v1129;
  int * v1022 = v1019->regs;
  int v1023 = v1022[11];
  int * v1024 = v1019->cache_tags;
  int v1133 = (((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2;
  int v1025 = v1024[v1133];
  int v1134 = ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1026 = v1024[v1134];
  int v1135 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2);
  int v1027 = v1024[v1135];
  int v1136 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1028 = v1024[v1136];
  int v1029 = v1019->timer;
  int v1137 = v1029 + ((100 ^ (((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1025 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1025 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) | (~(((v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1019->timer = v1137;
  int * v1031 = v1019->cache_vals;
  bool v1138 = !(((~(((v1025 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1025 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) | (~(((v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31))) == 0);
  int v1124;
  if (v1138) {
    int * v1032 = v1019->cache_age;
    int v1140 = ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2) + ((~(((v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1026 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) & 1);
    int v1033 = v1032[v1140];
    int v1034 = v1032[v1133];
    int v1141 = v1034 + ((int)((unsigned int)(v1034 - v1033) >> 31));
    v1032[v1133] = v1141;
    int * v1036 = v1019->cache_age;
    int v1037 = v1036[v1134];
    int v1143 = v1037 + ((int)((unsigned int)(v1037 - v1033) >> 31));
    v1036[v1134] = v1143;
    int * v1039 = v1019->cache_age;
    v1039[v1140] = 0;
    v1124 = v1140;
  } else {
    int * v1042 = v1019->cache_age;
    int v1147 = (((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2;
    int v1043 = v1042[v1147];
    int * v1044 = v1019->cache_tags;
    int v1045 = v1044[v1147];
    int v1046 = v1042[v1134];
    int v1047 = v1044[v1134];
    bool v1149 = !(((~(((v1027 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1027 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) | (~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31))) == 0);
    int v1101;
    if (v1149) {
      int * v1048 = v1019->cache_age;
      int v1151 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))) | (-(v1028 ^ ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1))))) >> 31)) & 1);
      int v1049 = v1048[v1151];
      int v1050 = v1048[v1135];
      int v1152 = v1050 + ((int)((unsigned int)(v1050 - v1049) >> 31));
      v1048[v1135] = v1152;
      int * v1052 = v1019->cache_age;
      int v1053 = v1052[v1136];
      int v1154 = v1053 + ((int)((unsigned int)(v1053 - v1049) >> 31));
      v1052[v1136] = v1154;
      int * v1055 = v1019->cache_age;
      v1055[v1151] = 0;
      v1101 = v1151;
    } else {
      int * v1058 = v1019->cache_age;
      int v1158 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2);
      int v1059 = v1058[v1158];
      int * v1060 = v1019->cache_tags;
      int v1061 = v1060[v1158];
      int v1062 = v1058[v1136];
      int v1063 = v1060[v1136];
      int * v1064 = v1019->cache_dirty;
      int v1161 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1063 ^ -1) | (-(v1063 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1065 = v1064[v1161];
      bool v1162 = !(v1065 == 0);
      if (v1162) {
        int * v1066 = v1019->cache_tags;
        int v1067 = v1066[v1161];
        int * v1068 = v1019->cache_vals;
        int v1165 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1063 ^ -1) | (-(v1063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1069 = v1068[v1165];
        int v1166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1063 ^ -1) | (-(v1063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1070 = v1068[v1166];
        int * v1071 = v1019->mem;
        int v1168 = v1067 * 2;
        v1071[v1168] = v1069;
        int * v1073 = v1019->mem;
        int v1171 = (v1067 * 2) + 1;
        v1073[v1171] = v1070;
        ;
      } else {
        ;
      }
      int * v1078 = v1019->mem;
      int v1176 = ((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) * 2;
      int v1079 = v1078[v1176];
      int v1177 = (((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) * 2) + 1;
      int v1080 = v1078[v1177];
      int * v1081 = v1019->cache_vals;
      int v1179 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1063 ^ -1) | (-(v1063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1081[v1179] = v1079;
      int * v1083 = v1019->cache_vals;
      int v1182 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 3) * 2)) + ((((v1059 + ((~(((v1061 ^ -1) | (-(v1061 ^ -1))) >> 31)) & 2)) - (v1062 + ((~(((v1063 ^ -1) | (-(v1063 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1083[v1182] = v1080;
      int * v1085 = v1019->cache_tags;
      int v1185 = (int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1);
      v1085[v1161] = v1185;
      int * v1087 = v1019->cache_dirty;
      v1087[v1161] = 0;
      int * v1089 = v1019->cache_age;
      v1089[v1161] = 1;
      int * v1091 = v1019->cache_age;
      int v1092 = v1091[v1161];
      int v1093 = v1091[v1135];
      int v1191 = v1093 + ((int)((unsigned int)(v1093 - v1092) >> 31));
      v1091[v1135] = v1191;
      int * v1095 = v1019->cache_age;
      int v1096 = v1095[v1136];
      int v1193 = v1096 + ((int)((unsigned int)(v1096 - v1092) >> 31));
      v1095[v1136] = v1193;
      int * v1098 = v1019->cache_age;
      v1098[v1161] = 0;
      v1101 = v1161;
    }
    int * v1102 = v1019->cache_vals;
    int v1196 = v1101 * 2;
    int v1103 = v1102[v1196];
    int v1197 = (v1101 * 2) + 1;
    int v1104 = v1102[v1197];
    int v1198 = (((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2) + ((((v1043 + ((~(((v1045 ^ -1) | (-(v1045 ^ -1))) >> 31)) & 2)) - (v1046 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1102[v1198] = v1103;
    int * v1106 = v1019->cache_vals;
    int v1201 = ((((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2) + ((((v1043 + ((~(((v1045 ^ -1) | (-(v1045 ^ -1))) >> 31)) & 2)) - (v1046 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1106[v1201] = v1104;
    int * v1108 = v1019->cache_tags;
    int v1204 = ((((int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1)) & 1) * 2) + ((((v1043 + ((~(((v1045 ^ -1) | (-(v1045 ^ -1))) >> 31)) & 2)) - (v1046 + ((~(((v1047 ^ -1) | (-(v1047 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1205 = (int)((unsigned int)((int)((unsigned int)v1023 >> 2)) >> 1);
    v1108[v1204] = v1205;
    int * v1110 = v1019->cache_dirty;
    v1110[v1204] = 0;
    int * v1112 = v1019->cache_age;
    v1112[v1204] = 1;
    int * v1114 = v1019->cache_age;
    int v1115 = v1114[v1204];
    int v1116 = v1114[v1133];
    int v1211 = v1116 + ((int)((unsigned int)(v1116 - v1115) >> 31));
    v1114[v1133] = v1211;
    int * v1118 = v1019->cache_age;
    int v1119 = v1118[v1134];
    int v1213 = v1119 + ((int)((unsigned int)(v1119 - v1115) >> 31));
    v1118[v1134] = v1213;
    int * v1121 = v1019->cache_age;
    v1121[v1204] = 0;
    v1124 = v1204;
  }
  int v1216 = (v1124 * 2) + (((int)((unsigned int)v1023 >> 2)) & 1);
  int v1125 = v1031[v1216];
  int * v1126 = v1019->regs;
  v1126[12] = v1125;
  return v1019;
}

struct StateT * slot_5(struct StateT * v815) {
  int v816 = v815->timer;
  int v926 = v816 + 1;
  v815->timer = v926;
  int * v818 = v815->regs;
  int v819 = v818[8];
  int * v820 = v815->cache_tags;
  int v930 = (((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2;
  int v821 = v820[v930];
  int v931 = ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + 1;
  int v822 = v820[v931];
  int v932 = 4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2);
  int v823 = v820[v932];
  int v933 = (4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v824 = v820[v933];
  int v825 = v815->timer;
  int v934 = v825 + ((100 ^ (((~(((v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) & 104)))));
  v815->timer = v934;
  int * v827 = v815->cache_vals;
  bool v935 = !(((~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) == 0);
  int v920;
  if (v935) {
    int * v828 = v815->cache_age;
    int v937 = ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((~(((v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v822 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) & 1);
    int v829 = v828[v937];
    int v830 = v828[v930];
    int v938 = v830 + ((int)((unsigned int)(v830 - v829) >> 31));
    v828[v930] = v938;
    int * v832 = v815->cache_age;
    int v833 = v832[v931];
    int v940 = v833 + ((int)((unsigned int)(v833 - v829) >> 31));
    v832[v931] = v940;
    int * v835 = v815->cache_age;
    v835[v937] = 0;
    v920 = v937;
  } else {
    int * v838 = v815->cache_age;
    int v944 = (((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2;
    int v839 = v838[v944];
    int * v840 = v815->cache_tags;
    int v841 = v840[v944];
    int v842 = v838[v931];
    int v843 = v840[v931];
    bool v946 = !(((~(((v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v823 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) | (~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31))) == 0);
    int v897;
    if (v946) {
      int * v844 = v815->cache_age;
      int v948 = (4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((~(((v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))) | (-(v824 ^ ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1))))) >> 31)) & 1);
      int v845 = v844[v948];
      int v846 = v844[v932];
      int v949 = v846 + ((int)((unsigned int)(v846 - v845) >> 31));
      v844[v932] = v949;
      int * v848 = v815->cache_age;
      int v849 = v848[v933];
      int v951 = v849 + ((int)((unsigned int)(v849 - v845) >> 31));
      v848[v933] = v951;
      int * v851 = v815->cache_age;
      v851[v948] = 0;
      v897 = v948;
    } else {
      int * v854 = v815->cache_age;
      int v955 = 4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2);
      int v855 = v854[v955];
      int * v856 = v815->cache_tags;
      int v857 = v856[v955];
      int v858 = v854[v933];
      int v859 = v856[v933];
      int * v860 = v815->cache_dirty;
      int v958 = (4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v861 = v860[v958];
      bool v959 = !(v861 == 0);
      if (v959) {
        int * v862 = v815->cache_tags;
        int v863 = v862[v958];
        int * v864 = v815->cache_vals;
        int v962 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v865 = v864[v962];
        int v963 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v866 = v864[v963];
        int * v867 = v815->mem;
        int v965 = v863 * 2;
        v867[v965] = v865;
        int * v869 = v815->mem;
        int v968 = (v863 * 2) + 1;
        v869[v968] = v866;
        ;
      } else {
        ;
      }
      int * v874 = v815->mem;
      int v973 = ((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) * 2;
      int v875 = v874[v973];
      int v974 = (((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) * 2) + 1;
      int v876 = v874[v974];
      int * v877 = v815->cache_vals;
      int v976 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v877[v976] = v875;
      int * v879 = v815->cache_vals;
      int v979 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 3) * 2)) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v879[v979] = v876;
      int * v881 = v815->cache_tags;
      int v982 = (int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1);
      v881[v958] = v982;
      int * v883 = v815->cache_dirty;
      v883[v958] = 0;
      int * v885 = v815->cache_age;
      v885[v958] = 1;
      int * v887 = v815->cache_age;
      int v888 = v887[v958];
      int v889 = v887[v932];
      int v988 = v889 + ((int)((unsigned int)(v889 - v888) >> 31));
      v887[v932] = v988;
      int * v891 = v815->cache_age;
      int v892 = v891[v933];
      int v990 = v892 + ((int)((unsigned int)(v892 - v888) >> 31));
      v891[v933] = v990;
      int * v894 = v815->cache_age;
      v894[v958] = 0;
      v897 = v958;
    }
    int * v898 = v815->cache_vals;
    int v993 = v897 * 2;
    int v899 = v898[v993];
    int v994 = (v897 * 2) + 1;
    int v900 = v898[v994];
    int v995 = (((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v898[v995] = v899;
    int * v902 = v815->cache_vals;
    int v998 = ((((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v902[v998] = v900;
    int * v904 = v815->cache_tags;
    int v1001 = ((((int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1)) & 1) * 2) + ((((v839 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2)) - (v842 + ((~(((v843 ^ -1) | (-(v843 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1002 = (int)((unsigned int)((int)((unsigned int)v819 >> 2)) >> 1);
    v904[v1001] = v1002;
    int * v906 = v815->cache_dirty;
    v906[v1001] = 0;
    int * v908 = v815->cache_age;
    v908[v1001] = 1;
    int * v910 = v815->cache_age;
    int v911 = v910[v1001];
    int v912 = v910[v930];
    int v1008 = v912 + ((int)((unsigned int)(v912 - v911) >> 31));
    v910[v930] = v1008;
    int * v914 = v815->cache_age;
    int v915 = v914[v931];
    int v1010 = v915 + ((int)((unsigned int)(v915 - v911) >> 31));
    v914[v931] = v1010;
    int * v917 = v815->cache_age;
    v917[v1001] = 0;
    v920 = v1001;
  }
  int v1013 = (v920 * 2) + (((int)((unsigned int)v819 >> 2)) & 1);
  int v921 = v827[v1013];
  int * v922 = v815->regs;
  v922[11] = v921;
  struct StateT * v924 = slot_6(v815);
  return v924;
}

struct StateT * slot_4(struct StateT * v625) {
  int v626 = v625->timer;
  int v734 = v626 + 1;
  v625->timer = v734;
  int * v628 = v625->cache_tags;
  int v629 = v628[0];
  int v630 = v628[1];
  int v631 = v628[4];
  int v632 = v628[5];
  int v633 = v625->timer;
  int v740 = v633 + ((100 ^ (((~(((v631 ^ 4) | (-(v631 ^ 4))) >> 31)) | (~(((v632 ^ 4) | (-(v632 ^ 4))) >> 31))) & 104)) ^ (((~(((v629 ^ 4) | (-(v629 ^ 4))) >> 31)) | (~(((v630 ^ 4) | (-(v630 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v631 ^ 4) | (-(v631 ^ 4))) >> 31)) | (~(((v632 ^ 4) | (-(v632 ^ 4))) >> 31))) & 104)))));
  v625->timer = v740;
  int * v635 = v625->cache_vals;
  bool v741 = !(((~(((v629 ^ 4) | (-(v629 ^ 4))) >> 31)) | (~(((v630 ^ 4) | (-(v630 ^ 4))) >> 31))) == 0);
  int v728;
  if (v741) {
    int * v636 = v625->cache_age;
    int v743 = (~(((v630 ^ 4) | (-(v630 ^ 4))) >> 31)) & 1;
    int v637 = v636[v743];
    int v638 = v636[0];
    int v744 = v638 + ((int)((unsigned int)(v638 - v637) >> 31));
    v636[0] = v744;
    int * v640 = v625->cache_age;
    int v641 = v640[1];
    int v746 = v641 + ((int)((unsigned int)(v641 - v637) >> 31));
    v640[1] = v746;
    int * v643 = v625->cache_age;
    v643[v743] = 0;
    v728 = v743;
  } else {
    int * v646 = v625->cache_age;
    int v647 = v646[0];
    int * v648 = v625->cache_tags;
    int v649 = v648[0];
    int v650 = v646[1];
    int v651 = v648[1];
    bool v750 = !(((~(((v631 ^ 4) | (-(v631 ^ 4))) >> 31)) | (~(((v632 ^ 4) | (-(v632 ^ 4))) >> 31))) == 0);
    int v705;
    if (v750) {
      int * v652 = v625->cache_age;
      int v752 = 4 + ((~(((v632 ^ 4) | (-(v632 ^ 4))) >> 31)) & 1);
      int v653 = v652[v752];
      int v654 = v652[4];
      int v753 = v654 + ((int)((unsigned int)(v654 - v653) >> 31));
      v652[4] = v753;
      int * v656 = v625->cache_age;
      int v657 = v656[5];
      int v755 = v657 + ((int)((unsigned int)(v657 - v653) >> 31));
      v656[5] = v755;
      int * v659 = v625->cache_age;
      v659[v752] = 0;
      v705 = v752;
    } else {
      int * v662 = v625->cache_age;
      int v663 = v662[4];
      int * v664 = v625->cache_tags;
      int v665 = v664[4];
      int v666 = v662[5];
      int v667 = v664[5];
      int * v668 = v625->cache_dirty;
      int v760 = 4 + ((((v663 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2)) - (v666 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v669 = v668[v760];
      bool v761 = !(v669 == 0);
      if (v761) {
        int * v670 = v625->cache_tags;
        int v671 = v670[v760];
        int * v672 = v625->cache_vals;
        int v764 = (4 + ((((v663 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2)) - (v666 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v673 = v672[v764];
        int v765 = ((4 + ((((v663 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2)) - (v666 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v674 = v672[v765];
        int * v675 = v625->mem;
        int v767 = v671 * 2;
        v675[v767] = v673;
        int * v677 = v625->mem;
        int v770 = (v671 * 2) + 1;
        v677[v770] = v674;
        ;
      } else {
        ;
      }
      int * v682 = v625->mem;
      int v683 = v682[8];
      int v684 = v682[9];
      int * v685 = v625->cache_vals;
      int v778 = (4 + ((((v663 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2)) - (v666 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v685[v778] = v683;
      int * v687 = v625->cache_vals;
      int v781 = ((4 + ((((v663 + ((~(((v665 ^ -1) | (-(v665 ^ -1))) >> 31)) & 2)) - (v666 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v687[v781] = v684;
      int * v689 = v625->cache_tags;
      v689[v760] = 4;
      int * v691 = v625->cache_dirty;
      v691[v760] = 0;
      int * v693 = v625->cache_age;
      v693[v760] = 1;
      int * v695 = v625->cache_age;
      int v696 = v695[v760];
      int v697 = v695[4];
      int v787 = v697 + ((int)((unsigned int)(v697 - v696) >> 31));
      v695[4] = v787;
      int * v699 = v625->cache_age;
      int v700 = v699[5];
      int v789 = v700 + ((int)((unsigned int)(v700 - v696) >> 31));
      v699[5] = v789;
      int * v702 = v625->cache_age;
      v702[v760] = 0;
      v705 = v760;
    }
    int * v706 = v625->cache_vals;
    int v792 = v705 * 2;
    int v707 = v706[v792];
    int v793 = (v705 * 2) + 1;
    int v708 = v706[v793];
    int v794 = ((((v647 + ((~(((v649 ^ -1) | (-(v649 ^ -1))) >> 31)) & 2)) - (v650 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v706[v794] = v707;
    int * v710 = v625->cache_vals;
    int v797 = (((((v647 + ((~(((v649 ^ -1) | (-(v649 ^ -1))) >> 31)) & 2)) - (v650 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v710[v797] = v708;
    int * v712 = v625->cache_tags;
    int v800 = (((v647 + ((~(((v649 ^ -1) | (-(v649 ^ -1))) >> 31)) & 2)) - (v650 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v712[v800] = 4;
    int * v714 = v625->cache_dirty;
    v714[v800] = 0;
    int * v716 = v625->cache_age;
    v716[v800] = 1;
    int * v718 = v625->cache_age;
    int v719 = v718[v800];
    int v720 = v718[0];
    int v804 = v720 + ((int)((unsigned int)(v720 - v719) >> 31));
    v718[0] = v804;
    int * v722 = v625->cache_age;
    int v723 = v722[1];
    int v806 = v723 + ((int)((unsigned int)(v723 - v719) >> 31));
    v722[1] = v806;
    int * v725 = v625->cache_age;
    v725[v800] = 0;
    v728 = v800;
  }
  int v809 = (v728 * 2) + 1;
  int v729 = v635[v809];
  int * v730 = v625->regs;
  v730[8] = v729;
  struct StateT * v732 = slot_5(v625);
  return v732;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v202 = v33 + 1;
  v32->timer = v202;
  int * v35 = v32->regs;
  int v36 = v35[6];
  int * v37 = v32->cache_tags;
  int v38 = v37[0];
  int v39 = v37[1];
  int v40 = v37[4];
  int v41 = v37[5];
  int v42 = v32->timer;
  int v210 = v42 + ((100 ^ (((~(((v40 ^ 4) | (-(v40 ^ 4))) >> 31)) | (~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31))) & 104)) ^ (((~(((v38 ^ 4) | (-(v38 ^ 4))) >> 31)) | (~(((v39 ^ 4) | (-(v39 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v40 ^ 4) | (-(v40 ^ 4))) >> 31)) | (~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31))) & 104)))));
  v32->timer = v210;
  bool v211 = !(((~(((v38 ^ 4) | (-(v38 ^ 4))) >> 31)) | (~(((v39 ^ 4) | (-(v39 ^ 4))) >> 31))) == 0);
  int v136;
  if (v211) {
    int * v44 = v32->cache_age;
    int v213 = (~(((v39 ^ 4) | (-(v39 ^ 4))) >> 31)) & 1;
    int v45 = v44[v213];
    int v46 = v44[0];
    int v214 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
    v44[0] = v214;
    int * v48 = v32->cache_age;
    int v49 = v48[1];
    int v216 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
    v48[1] = v216;
    int * v51 = v32->cache_age;
    v51[v213] = 0;
    v136 = v213;
  } else {
    int * v54 = v32->cache_age;
    int v55 = v54[0];
    int * v56 = v32->cache_tags;
    int v57 = v56[0];
    int v58 = v54[1];
    int v59 = v56[1];
    bool v220 = !(((~(((v40 ^ 4) | (-(v40 ^ 4))) >> 31)) | (~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31))) == 0);
    int v113;
    if (v220) {
      int * v60 = v32->cache_age;
      int v222 = 4 + ((~(((v41 ^ 4) | (-(v41 ^ 4))) >> 31)) & 1);
      int v61 = v60[v222];
      int v62 = v60[4];
      int v223 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
      v60[4] = v223;
      int * v64 = v32->cache_age;
      int v65 = v64[5];
      int v225 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
      v64[5] = v225;
      int * v67 = v32->cache_age;
      v67[v222] = 0;
      v113 = v222;
    } else {
      int * v70 = v32->cache_age;
      int v71 = v70[4];
      int * v72 = v32->cache_tags;
      int v73 = v72[4];
      int v74 = v70[5];
      int v75 = v72[5];
      int * v76 = v32->cache_dirty;
      int v230 = 4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v77 = v76[v230];
      bool v231 = !(v77 == 0);
      if (v231) {
        int * v78 = v32->cache_tags;
        int v79 = v78[v230];
        int * v80 = v32->cache_vals;
        int v234 = (4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v81 = v80[v234];
        int v235 = ((4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v82 = v80[v235];
        int * v83 = v32->mem;
        int v237 = v79 * 2;
        v83[v237] = v81;
        int * v85 = v32->mem;
        int v240 = (v79 * 2) + 1;
        v85[v240] = v82;
        ;
      } else {
        ;
      }
      int * v90 = v32->mem;
      int v91 = v90[8];
      int v92 = v90[9];
      int * v93 = v32->cache_vals;
      int v248 = (4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v93[v248] = v91;
      int * v95 = v32->cache_vals;
      int v251 = ((4 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v95[v251] = v92;
      int * v97 = v32->cache_tags;
      v97[v230] = 4;
      int * v99 = v32->cache_dirty;
      v99[v230] = 0;
      int * v101 = v32->cache_age;
      v101[v230] = 1;
      int * v103 = v32->cache_age;
      int v104 = v103[v230];
      int v105 = v103[4];
      int v257 = v105 + ((int)((unsigned int)(v105 - v104) >> 31));
      v103[4] = v257;
      int * v107 = v32->cache_age;
      int v108 = v107[5];
      int v259 = v108 + ((int)((unsigned int)(v108 - v104) >> 31));
      v107[5] = v259;
      int * v110 = v32->cache_age;
      v110[v230] = 0;
      v113 = v230;
    }
    int * v114 = v32->cache_vals;
    int v262 = v113 * 2;
    int v115 = v114[v262];
    int v263 = (v113 * 2) + 1;
    int v116 = v114[v263];
    int v264 = ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v114[v264] = v115;
    int * v118 = v32->cache_vals;
    int v267 = (((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v118[v267] = v116;
    int * v120 = v32->cache_tags;
    int v270 = (((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v120[v270] = 4;
    int * v122 = v32->cache_dirty;
    v122[v270] = 0;
    int * v124 = v32->cache_age;
    v124[v270] = 1;
    int * v126 = v32->cache_age;
    int v127 = v126[v270];
    int v128 = v126[0];
    int v274 = v128 + ((int)((unsigned int)(v128 - v127) >> 31));
    v126[0] = v274;
    int * v130 = v32->cache_age;
    int v131 = v130[1];
    int v276 = v131 + ((int)((unsigned int)(v131 - v127) >> 31));
    v130[1] = v276;
    int * v133 = v32->cache_age;
    v133[v270] = 0;
    v136 = v270;
  }
  int * v137 = v32->cache_vals;
  int v279 = (v136 * 2) + 1;
  v137[v279] = v36;
  int * v139 = v32->cache_tags;
  int v140 = v139[4];
  int v141 = v139[5];
  bool v282 = !(((~(((v140 ^ 4) | (-(v140 ^ 4))) >> 31)) | (~(((v141 ^ 4) | (-(v141 ^ 4))) >> 31))) == 0);
  int v195;
  if (v282) {
    int * v142 = v32->cache_age;
    int v284 = 4 + ((~(((v141 ^ 4) | (-(v141 ^ 4))) >> 31)) & 1);
    int v143 = v142[v284];
    int v144 = v142[4];
    int v285 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[4] = v285;
    int * v146 = v32->cache_age;
    int v147 = v146[5];
    int v287 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[5] = v287;
    int * v149 = v32->cache_age;
    v149[v284] = 0;
    v195 = v284;
  } else {
    int * v152 = v32->cache_age;
    int v153 = v152[4];
    int * v154 = v32->cache_tags;
    int v155 = v154[4];
    int v156 = v152[5];
    int v157 = v154[5];
    int * v158 = v32->cache_dirty;
    int v292 = 4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v159 = v158[v292];
    bool v293 = !(v159 == 0);
    if (v293) {
      int * v160 = v32->cache_tags;
      int v161 = v160[v292];
      int * v162 = v32->cache_vals;
      int v296 = (4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v163 = v162[v296];
      int v297 = ((4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v164 = v162[v297];
      int * v165 = v32->mem;
      int v299 = v161 * 2;
      v165[v299] = v163;
      int * v167 = v32->mem;
      int v302 = (v161 * 2) + 1;
      v167[v302] = v164;
      ;
    } else {
      ;
    }
    int * v172 = v32->mem;
    int v173 = v172[8];
    int v174 = v172[9];
    int * v175 = v32->cache_vals;
    int v310 = (4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v175[v310] = v173;
    int * v177 = v32->cache_vals;
    int v313 = ((4 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v177[v313] = v174;
    int * v179 = v32->cache_tags;
    v179[v292] = 4;
    int * v181 = v32->cache_dirty;
    v181[v292] = 0;
    int * v183 = v32->cache_age;
    v183[v292] = 1;
    int * v185 = v32->cache_age;
    int v186 = v185[v292];
    int v187 = v185[4];
    int v319 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
    v185[4] = v319;
    int * v189 = v32->cache_age;
    int v190 = v189[5];
    int v321 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
    v189[5] = v321;
    int * v192 = v32->cache_age;
    v192[v292] = 0;
    v195 = v292;
  }
  int * v196 = v32->cache_vals;
  int v324 = (v195 * 2) + 1;
  v196[v324] = v36;
  int * v198 = v32->cache_dirty;
  v198[v195] = 1;
  struct StateT * v200 = slot_3(v32);
  return v200;
}

struct StateT * slot_3(struct StateT * v329) {
  int v330 = v329->timer;
  int v499 = v330 + 1;
  v329->timer = v499;
  int * v332 = v329->regs;
  int v333 = v332[5];
  int * v334 = v329->cache_tags;
  int v335 = v334[0];
  int v336 = v334[1];
  int v337 = v334[4];
  int v338 = v334[5];
  int v339 = v329->timer;
  int v506 = v339 + ((100 ^ (((~(((v337 ^ 4) | (-(v337 ^ 4))) >> 31)) | (~(((v338 ^ 4) | (-(v338 ^ 4))) >> 31))) & 104)) ^ (((~(((v335 ^ 4) | (-(v335 ^ 4))) >> 31)) | (~(((v336 ^ 4) | (-(v336 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v337 ^ 4) | (-(v337 ^ 4))) >> 31)) | (~(((v338 ^ 4) | (-(v338 ^ 4))) >> 31))) & 104)))));
  v329->timer = v506;
  bool v507 = !(((~(((v335 ^ 4) | (-(v335 ^ 4))) >> 31)) | (~(((v336 ^ 4) | (-(v336 ^ 4))) >> 31))) == 0);
  int v433;
  if (v507) {
    int * v341 = v329->cache_age;
    int v509 = (~(((v336 ^ 4) | (-(v336 ^ 4))) >> 31)) & 1;
    int v342 = v341[v509];
    int v343 = v341[0];
    int v510 = v343 + ((int)((unsigned int)(v343 - v342) >> 31));
    v341[0] = v510;
    int * v345 = v329->cache_age;
    int v346 = v345[1];
    int v512 = v346 + ((int)((unsigned int)(v346 - v342) >> 31));
    v345[1] = v512;
    int * v348 = v329->cache_age;
    v348[v509] = 0;
    v433 = v509;
  } else {
    int * v351 = v329->cache_age;
    int v352 = v351[0];
    int * v353 = v329->cache_tags;
    int v354 = v353[0];
    int v355 = v351[1];
    int v356 = v353[1];
    bool v516 = !(((~(((v337 ^ 4) | (-(v337 ^ 4))) >> 31)) | (~(((v338 ^ 4) | (-(v338 ^ 4))) >> 31))) == 0);
    int v410;
    if (v516) {
      int * v357 = v329->cache_age;
      int v518 = 4 + ((~(((v338 ^ 4) | (-(v338 ^ 4))) >> 31)) & 1);
      int v358 = v357[v518];
      int v359 = v357[4];
      int v519 = v359 + ((int)((unsigned int)(v359 - v358) >> 31));
      v357[4] = v519;
      int * v361 = v329->cache_age;
      int v362 = v361[5];
      int v521 = v362 + ((int)((unsigned int)(v362 - v358) >> 31));
      v361[5] = v521;
      int * v364 = v329->cache_age;
      v364[v518] = 0;
      v410 = v518;
    } else {
      int * v367 = v329->cache_age;
      int v368 = v367[4];
      int * v369 = v329->cache_tags;
      int v370 = v369[4];
      int v371 = v367[5];
      int v372 = v369[5];
      int * v373 = v329->cache_dirty;
      int v526 = 4 + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v374 = v373[v526];
      bool v527 = !(v374 == 0);
      if (v527) {
        int * v375 = v329->cache_tags;
        int v376 = v375[v526];
        int * v377 = v329->cache_vals;
        int v530 = (4 + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v378 = v377[v530];
        int v531 = ((4 + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v379 = v377[v531];
        int * v380 = v329->mem;
        int v533 = v376 * 2;
        v380[v533] = v378;
        int * v382 = v329->mem;
        int v536 = (v376 * 2) + 1;
        v382[v536] = v379;
        ;
      } else {
        ;
      }
      int * v387 = v329->mem;
      int v388 = v387[8];
      int v389 = v387[9];
      int * v390 = v329->cache_vals;
      int v544 = (4 + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v390[v544] = v388;
      int * v392 = v329->cache_vals;
      int v547 = ((4 + ((((v368 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2)) - (v371 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v392[v547] = v389;
      int * v394 = v329->cache_tags;
      v394[v526] = 4;
      int * v396 = v329->cache_dirty;
      v396[v526] = 0;
      int * v398 = v329->cache_age;
      v398[v526] = 1;
      int * v400 = v329->cache_age;
      int v401 = v400[v526];
      int v402 = v400[4];
      int v553 = v402 + ((int)((unsigned int)(v402 - v401) >> 31));
      v400[4] = v553;
      int * v404 = v329->cache_age;
      int v405 = v404[5];
      int v555 = v405 + ((int)((unsigned int)(v405 - v401) >> 31));
      v404[5] = v555;
      int * v407 = v329->cache_age;
      v407[v526] = 0;
      v410 = v526;
    }
    int * v411 = v329->cache_vals;
    int v558 = v410 * 2;
    int v412 = v411[v558];
    int v559 = (v410 * 2) + 1;
    int v413 = v411[v559];
    int v560 = ((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v411[v560] = v412;
    int * v415 = v329->cache_vals;
    int v563 = (((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v415[v563] = v413;
    int * v417 = v329->cache_tags;
    int v566 = (((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v417[v566] = 4;
    int * v419 = v329->cache_dirty;
    v419[v566] = 0;
    int * v421 = v329->cache_age;
    v421[v566] = 1;
    int * v423 = v329->cache_age;
    int v424 = v423[v566];
    int v425 = v423[0];
    int v570 = v425 + ((int)((unsigned int)(v425 - v424) >> 31));
    v423[0] = v570;
    int * v427 = v329->cache_age;
    int v428 = v427[1];
    int v572 = v428 + ((int)((unsigned int)(v428 - v424) >> 31));
    v427[1] = v572;
    int * v430 = v329->cache_age;
    v430[v566] = 0;
    v433 = v566;
  }
  int * v434 = v329->cache_vals;
  int v575 = (v433 * 2) + 1;
  v434[v575] = v333;
  int * v436 = v329->cache_tags;
  int v437 = v436[4];
  int v438 = v436[5];
  bool v578 = !(((~(((v437 ^ 4) | (-(v437 ^ 4))) >> 31)) | (~(((v438 ^ 4) | (-(v438 ^ 4))) >> 31))) == 0);
  int v492;
  if (v578) {
    int * v439 = v329->cache_age;
    int v580 = 4 + ((~(((v438 ^ 4) | (-(v438 ^ 4))) >> 31)) & 1);
    int v440 = v439[v580];
    int v441 = v439[4];
    int v581 = v441 + ((int)((unsigned int)(v441 - v440) >> 31));
    v439[4] = v581;
    int * v443 = v329->cache_age;
    int v444 = v443[5];
    int v583 = v444 + ((int)((unsigned int)(v444 - v440) >> 31));
    v443[5] = v583;
    int * v446 = v329->cache_age;
    v446[v580] = 0;
    v492 = v580;
  } else {
    int * v449 = v329->cache_age;
    int v450 = v449[4];
    int * v451 = v329->cache_tags;
    int v452 = v451[4];
    int v453 = v449[5];
    int v454 = v451[5];
    int * v455 = v329->cache_dirty;
    int v588 = 4 + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v456 = v455[v588];
    bool v589 = !(v456 == 0);
    if (v589) {
      int * v457 = v329->cache_tags;
      int v458 = v457[v588];
      int * v459 = v329->cache_vals;
      int v592 = (4 + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v460 = v459[v592];
      int v593 = ((4 + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v461 = v459[v593];
      int * v462 = v329->mem;
      int v595 = v458 * 2;
      v462[v595] = v460;
      int * v464 = v329->mem;
      int v598 = (v458 * 2) + 1;
      v464[v598] = v461;
      ;
    } else {
      ;
    }
    int * v469 = v329->mem;
    int v470 = v469[8];
    int v471 = v469[9];
    int * v472 = v329->cache_vals;
    int v606 = (4 + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v472[v606] = v470;
    int * v474 = v329->cache_vals;
    int v609 = ((4 + ((((v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2)) - (v453 + ((~(((v454 ^ -1) | (-(v454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v474[v609] = v471;
    int * v476 = v329->cache_tags;
    v476[v588] = 4;
    int * v478 = v329->cache_dirty;
    v478[v588] = 0;
    int * v480 = v329->cache_age;
    v480[v588] = 1;
    int * v482 = v329->cache_age;
    int v483 = v482[v588];
    int v484 = v482[4];
    int v615 = v484 + ((int)((unsigned int)(v484 - v483) >> 31));
    v482[4] = v615;
    int * v486 = v329->cache_age;
    int v487 = v486[5];
    int v617 = v487 + ((int)((unsigned int)(v487 - v483) >> 31));
    v486[5] = v617;
    int * v489 = v329->cache_age;
    v489[v588] = 0;
    v492 = v588;
  }
  int * v493 = v329->cache_vals;
  int v620 = (v492 * 2) + 1;
  v493[v620] = v333;
  int * v495 = v329->cache_dirty;
  v495[v492] = 1;
  struct StateT * v497 = slot_4(v329);
  return v497;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
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