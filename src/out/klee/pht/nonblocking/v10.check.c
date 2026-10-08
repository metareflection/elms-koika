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

struct StateT * slot_12(struct StateT * v810);
struct StateT * slot_14(struct StateT * v1042);
struct StateT * slot_6(struct StateT * v314);
struct StateT * slot_5(struct StateT * v293);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v338);
struct StateT * slot_3(struct StateT * v256);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v587);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v545);
struct StateT * slot_4(struct StateT * v277);
struct StateT * slot_13(struct StateT * v1018);
struct StateT * slot_15(struct StateT * v251);
struct StateT * slot_9(struct StateT * v571);
struct StateT * slot_11(struct StateT * v603);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v810) {
  int v811 = v810->timer;
  int v923 = v811 + 1;
  v810->timer = v923;
  int * v813 = v810->reg_ready;
  int v814 = v813[11];
  int * v815 = v810->regs;
  int v816 = v815[11];
  int * v817 = v810->cache_tags;
  int v928 = (((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2;
  int v818 = v817[v928];
  int v929 = ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v819 = v817[v929];
  int v930 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2);
  int v820 = v817[v930];
  int v931 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v821 = v817[v931];
  int * v822 = v810->cache_vals;
  bool v932 = !(((~(((v818 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v818 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v819 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v819 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v915;
  if (v932) {
    int * v823 = v810->cache_age;
    int v934 = ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v819 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v819 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v824 = v823[v934];
    int v825 = v823[v928];
    int v935 = v825 + ((int)((unsigned int)(v825 - v824) >> 31));
    v823[v928] = v935;
    int * v827 = v810->cache_age;
    int v828 = v827[v929];
    int v937 = v828 + ((int)((unsigned int)(v828 - v824) >> 31));
    v827[v929] = v937;
    int * v830 = v810->cache_age;
    v830[v934] = 0;
    v915 = v934;
  } else {
    int * v833 = v810->cache_age;
    int v941 = (((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2;
    int v834 = v833[v941];
    int * v835 = v810->cache_tags;
    int v836 = v835[v941];
    int v837 = v833[v929];
    int v838 = v835[v929];
    bool v943 = !(((~(((v820 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v820 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v892;
    if (v943) {
      int * v839 = v810->cache_age;
      int v945 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v840 = v839[v945];
      int v841 = v839[v930];
      int v946 = v841 + ((int)((unsigned int)(v841 - v840) >> 31));
      v839[v930] = v946;
      int * v843 = v810->cache_age;
      int v844 = v843[v931];
      int v948 = v844 + ((int)((unsigned int)(v844 - v840) >> 31));
      v843[v931] = v948;
      int * v846 = v810->cache_age;
      v846[v945] = 0;
      v892 = v945;
    } else {
      int * v849 = v810->cache_age;
      int v952 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2);
      int v850 = v849[v952];
      int * v851 = v810->cache_tags;
      int v852 = v851[v952];
      int v853 = v849[v931];
      int v854 = v851[v931];
      int * v855 = v810->cache_dirty;
      int v955 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2)) - (v853 + ((~(((v854 ^ -1) | (-(v854 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v856 = v855[v955];
      bool v956 = !(v856 == 0);
      if (v956) {
        int * v857 = v810->cache_tags;
        int v858 = v857[v955];
        int * v859 = v810->cache_vals;
        int v959 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2)) - (v853 + ((~(((v854 ^ -1) | (-(v854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v860 = v859[v959];
        int v960 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2)) - (v853 + ((~(((v854 ^ -1) | (-(v854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v861 = v859[v960];
        int * v862 = v810->mem;
        int v962 = v858 * 2;
        v862[v962] = v860;
        int * v864 = v810->mem;
        int v965 = (v858 * 2) + 1;
        v864[v965] = v861;
        ;
      } else {
        ;
      }
      int * v869 = v810->mem;
      int v970 = ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) * 2;
      int v870 = v869[v970];
      int v971 = (((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) * 2) + 1;
      int v871 = v869[v971];
      int * v872 = v810->cache_vals;
      int v973 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2)) - (v853 + ((~(((v854 ^ -1) | (-(v854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v872[v973] = v870;
      int * v874 = v810->cache_vals;
      int v976 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v850 + ((~(((v852 ^ -1) | (-(v852 ^ -1))) >> 31)) & 2)) - (v853 + ((~(((v854 ^ -1) | (-(v854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v874[v976] = v871;
      int * v876 = v810->cache_tags;
      int v979 = (int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1);
      v876[v955] = v979;
      int * v878 = v810->cache_dirty;
      v878[v955] = 0;
      int * v880 = v810->cache_age;
      v880[v955] = 1;
      int * v882 = v810->cache_age;
      int v883 = v882[v955];
      int v884 = v882[v930];
      int v985 = v884 + ((int)((unsigned int)(v884 - v883) >> 31));
      v882[v930] = v985;
      int * v886 = v810->cache_age;
      int v887 = v886[v931];
      int v987 = v887 + ((int)((unsigned int)(v887 - v883) >> 31));
      v886[v931] = v987;
      int * v889 = v810->cache_age;
      v889[v955] = 0;
      v892 = v955;
    }
    int * v893 = v810->cache_vals;
    int v990 = v892 * 2;
    int v894 = v893[v990];
    int v991 = (v892 * 2) + 1;
    int v895 = v893[v991];
    int v992 = (((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v893[v992] = v894;
    int * v897 = v810->cache_vals;
    int v995 = ((((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v897[v995] = v895;
    int * v899 = v810->cache_tags;
    int v998 = ((((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v834 + ((~(((v836 ^ -1) | (-(v836 ^ -1))) >> 31)) & 2)) - (v837 + ((~(((v838 ^ -1) | (-(v838 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v999 = (int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1);
    v899[v998] = v999;
    int * v901 = v810->cache_dirty;
    v901[v998] = 0;
    int * v903 = v810->cache_age;
    v903[v998] = 1;
    int * v905 = v810->cache_age;
    int v906 = v905[v998];
    int v907 = v905[v928];
    int v1005 = v907 + ((int)((unsigned int)(v907 - v906) >> 31));
    v905[v928] = v1005;
    int * v909 = v810->cache_age;
    int v910 = v909[v929];
    int v1007 = v910 + ((int)((unsigned int)(v910 - v906) >> 31));
    v909[v929] = v1007;
    int * v912 = v810->cache_age;
    v912[v998] = 0;
    v915 = v998;
  }
  int v1010 = (v915 * 2) + (((int)((unsigned int)(v816 + 68) >> 2)) & 1);
  int v916 = v822[v1010];
  int * v917 = v810->reg_ready;
  int v1013 = ((v814 + ((v811 - v814) & (~((v811 - v814) >> 31)))) + 1) + ((100 ^ (((~(((v820 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v820 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v818 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v818 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v819 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v819 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v820 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v820 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))) | (-(v821 ^ ((int)((unsigned int)((int)((unsigned int)(v816 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v917[12] = v1013;
  int * v919 = v810->regs;
  v919[12] = v916;
  struct StateT * v921 = slot_13(v810);
  return v921;
}

struct StateT * slot_14(struct StateT * v1042) {
  int v1043 = v1042->timer;
  int v1216 = v1043 + 1;
  v1042->timer = v1216;
  int * v1045 = v1042->reg_ready;
  int * v1047 = v1042->regs;
  int v1048 = v1047[11];
  int v1050 = v1047[10];
  int * v1051 = v1042->cache_tags;
  int v1222 = (((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1052 = v1051[v1222];
  int v1223 = ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1053 = v1051[v1223];
  int v1224 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1054 = v1051[v1224];
  int v1225 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1055 = v1051[v1225];
  int v1056 = v1042->timer;
  int v1226 = v1056 + ((100 ^ (((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1042->timer = v1226;
  bool v1227 = !(((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1150;
  if (v1227) {
    int * v1058 = v1042->cache_age;
    int v1229 = ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1059 = v1058[v1229];
    int v1060 = v1058[v1222];
    int v1230 = v1060 + ((int)((unsigned int)(v1060 - v1059) >> 31));
    v1058[v1222] = v1230;
    int * v1062 = v1042->cache_age;
    int v1063 = v1062[v1223];
    int v1232 = v1063 + ((int)((unsigned int)(v1063 - v1059) >> 31));
    v1062[v1223] = v1232;
    int * v1065 = v1042->cache_age;
    v1065[v1229] = 0;
    v1150 = v1229;
  } else {
    int * v1068 = v1042->cache_age;
    int v1236 = (((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1069 = v1068[v1236];
    int * v1070 = v1042->cache_tags;
    int v1071 = v1070[v1236];
    int v1072 = v1068[v1223];
    int v1073 = v1070[v1223];
    bool v1238 = !(((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1127;
    if (v1238) {
      int * v1074 = v1042->cache_age;
      int v1240 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1075 = v1074[v1240];
      int v1076 = v1074[v1224];
      int v1241 = v1076 + ((int)((unsigned int)(v1076 - v1075) >> 31));
      v1074[v1224] = v1241;
      int * v1078 = v1042->cache_age;
      int v1079 = v1078[v1225];
      int v1243 = v1079 + ((int)((unsigned int)(v1079 - v1075) >> 31));
      v1078[v1225] = v1243;
      int * v1081 = v1042->cache_age;
      v1081[v1240] = 0;
      v1127 = v1240;
    } else {
      int * v1084 = v1042->cache_age;
      int v1247 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1085 = v1084[v1247];
      int * v1086 = v1042->cache_tags;
      int v1087 = v1086[v1247];
      int v1088 = v1084[v1225];
      int v1089 = v1086[v1225];
      int * v1090 = v1042->cache_dirty;
      int v1250 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1085 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2)) - (v1088 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1091 = v1090[v1250];
      bool v1251 = !(v1091 == 0);
      if (v1251) {
        int * v1092 = v1042->cache_tags;
        int v1093 = v1092[v1250];
        int * v1094 = v1042->cache_vals;
        int v1254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1085 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2)) - (v1088 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1095 = v1094[v1254];
        int v1255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1085 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2)) - (v1088 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1096 = v1094[v1255];
        int * v1097 = v1042->mem;
        int v1257 = v1093 * 2;
        v1097[v1257] = v1095;
        int * v1099 = v1042->mem;
        int v1260 = (v1093 * 2) + 1;
        v1099[v1260] = v1096;
        ;
      } else {
        ;
      }
      int * v1104 = v1042->mem;
      int v1265 = ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) * 2;
      int v1105 = v1104[v1265];
      int v1266 = (((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1106 = v1104[v1266];
      int * v1107 = v1042->cache_vals;
      int v1268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1085 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2)) - (v1088 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1107[v1268] = v1105;
      int * v1109 = v1042->cache_vals;
      int v1271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1085 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2)) - (v1088 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1109[v1271] = v1106;
      int * v1111 = v1042->cache_tags;
      int v1274 = (int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1);
      v1111[v1250] = v1274;
      int * v1113 = v1042->cache_dirty;
      v1113[v1250] = 0;
      int * v1115 = v1042->cache_age;
      v1115[v1250] = 1;
      int * v1117 = v1042->cache_age;
      int v1118 = v1117[v1250];
      int v1119 = v1117[v1224];
      int v1280 = v1119 + ((int)((unsigned int)(v1119 - v1118) >> 31));
      v1117[v1224] = v1280;
      int * v1121 = v1042->cache_age;
      int v1122 = v1121[v1225];
      int v1282 = v1122 + ((int)((unsigned int)(v1122 - v1118) >> 31));
      v1121[v1225] = v1282;
      int * v1124 = v1042->cache_age;
      v1124[v1250] = 0;
      v1127 = v1250;
    }
    int * v1128 = v1042->cache_vals;
    int v1285 = v1127 * 2;
    int v1129 = v1128[v1285];
    int v1286 = (v1127 * 2) + 1;
    int v1130 = v1128[v1286];
    int v1287 = (((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1069 + ((~(((v1071 ^ -1) | (-(v1071 ^ -1))) >> 31)) & 2)) - (v1072 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1128[v1287] = v1129;
    int * v1132 = v1042->cache_vals;
    int v1290 = ((((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1069 + ((~(((v1071 ^ -1) | (-(v1071 ^ -1))) >> 31)) & 2)) - (v1072 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1132[v1290] = v1130;
    int * v1134 = v1042->cache_tags;
    int v1293 = ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1069 + ((~(((v1071 ^ -1) | (-(v1071 ^ -1))) >> 31)) & 2)) - (v1072 + ((~(((v1073 ^ -1) | (-(v1073 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1294 = (int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1);
    v1134[v1293] = v1294;
    int * v1136 = v1042->cache_dirty;
    v1136[v1293] = 0;
    int * v1138 = v1042->cache_age;
    v1138[v1293] = 1;
    int * v1140 = v1042->cache_age;
    int v1141 = v1140[v1293];
    int v1142 = v1140[v1222];
    int v1300 = v1142 + ((int)((unsigned int)(v1142 - v1141) >> 31));
    v1140[v1222] = v1300;
    int * v1144 = v1042->cache_age;
    int v1145 = v1144[v1223];
    int v1302 = v1145 + ((int)((unsigned int)(v1145 - v1141) >> 31));
    v1144[v1223] = v1302;
    int * v1147 = v1042->cache_age;
    v1147[v1293] = 0;
    v1150 = v1293;
  }
  int * v1151 = v1042->cache_vals;
  int v1305 = (v1150 * 2) + (((int)((unsigned int)(v1048 + 68) >> 2)) & 1);
  v1151[v1305] = v1050;
  int * v1153 = v1042->cache_tags;
  int v1154 = v1153[v1224];
  int v1155 = v1153[v1225];
  bool v1308 = !(((~(((v1154 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1154 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1155 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1155 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1209;
  if (v1308) {
    int * v1156 = v1042->cache_age;
    int v1310 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1155 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))) | (-(v1155 ^ ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1157 = v1156[v1310];
    int v1158 = v1156[v1224];
    int v1311 = v1158 + ((int)((unsigned int)(v1158 - v1157) >> 31));
    v1156[v1224] = v1311;
    int * v1160 = v1042->cache_age;
    int v1161 = v1160[v1225];
    int v1313 = v1161 + ((int)((unsigned int)(v1161 - v1157) >> 31));
    v1160[v1225] = v1313;
    int * v1163 = v1042->cache_age;
    v1163[v1310] = 0;
    v1209 = v1310;
  } else {
    int * v1166 = v1042->cache_age;
    int v1317 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1167 = v1166[v1317];
    int * v1168 = v1042->cache_tags;
    int v1169 = v1168[v1317];
    int v1170 = v1166[v1225];
    int v1171 = v1168[v1225];
    int * v1172 = v1042->cache_dirty;
    int v1320 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1167 + ((~(((v1169 ^ -1) | (-(v1169 ^ -1))) >> 31)) & 2)) - (v1170 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1173 = v1172[v1320];
    bool v1321 = !(v1173 == 0);
    if (v1321) {
      int * v1174 = v1042->cache_tags;
      int v1175 = v1174[v1320];
      int * v1176 = v1042->cache_vals;
      int v1324 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1167 + ((~(((v1169 ^ -1) | (-(v1169 ^ -1))) >> 31)) & 2)) - (v1170 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1177 = v1176[v1324];
      int v1325 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1167 + ((~(((v1169 ^ -1) | (-(v1169 ^ -1))) >> 31)) & 2)) - (v1170 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1178 = v1176[v1325];
      int * v1179 = v1042->mem;
      int v1327 = v1175 * 2;
      v1179[v1327] = v1177;
      int * v1181 = v1042->mem;
      int v1330 = (v1175 * 2) + 1;
      v1181[v1330] = v1178;
      ;
    } else {
      ;
    }
    int * v1186 = v1042->mem;
    int v1335 = ((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) * 2;
    int v1187 = v1186[v1335];
    int v1336 = (((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1188 = v1186[v1336];
    int * v1189 = v1042->cache_vals;
    int v1338 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1167 + ((~(((v1169 ^ -1) | (-(v1169 ^ -1))) >> 31)) & 2)) - (v1170 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1189[v1338] = v1187;
    int * v1191 = v1042->cache_vals;
    int v1341 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1167 + ((~(((v1169 ^ -1) | (-(v1169 ^ -1))) >> 31)) & 2)) - (v1170 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1191[v1341] = v1188;
    int * v1193 = v1042->cache_tags;
    int v1344 = (int)((unsigned int)((int)((unsigned int)(v1048 + 68) >> 2)) >> 1);
    v1193[v1320] = v1344;
    int * v1195 = v1042->cache_dirty;
    v1195[v1320] = 0;
    int * v1197 = v1042->cache_age;
    v1197[v1320] = 1;
    int * v1199 = v1042->cache_age;
    int v1200 = v1199[v1320];
    int v1201 = v1199[v1224];
    int v1350 = v1201 + ((int)((unsigned int)(v1201 - v1200) >> 31));
    v1199[v1224] = v1350;
    int * v1203 = v1042->cache_age;
    int v1204 = v1203[v1225];
    int v1352 = v1204 + ((int)((unsigned int)(v1204 - v1200) >> 31));
    v1203[v1225] = v1352;
    int * v1206 = v1042->cache_age;
    v1206[v1320] = 0;
    v1209 = v1320;
  }
  int * v1210 = v1042->cache_vals;
  int v1355 = (v1209 * 2) + (((int)((unsigned int)(v1048 + 68) >> 2)) & 1);
  v1210[v1355] = v1050;
  int * v1212 = v1042->cache_dirty;
  v1212[v1209] = 1;
  struct StateT * v1214 = slot_15(v1042);
  return v1214;
}

struct StateT * slot_6(struct StateT * v314) {
  int v315 = v314->timer;
  int v328 = v315 + 1;
  v314->timer = v328;
  int * v317 = v314->reg_ready;
  int v318 = v317[12];
  int * v319 = v314->regs;
  int v320 = v319[12];
  int v321 = v317[10];
  int v322 = v319[10];
  int v333 = (v321 + (((v318 + ((v315 - v318) & (~((v315 - v318) >> 31)))) - v321) & (~(((v318 + ((v315 - v318) & (~((v315 - v318) >> 31)))) - v321) >> 31)))) + 1;
  v317[10] = v333;
  int * v324 = v314->regs;
  int v335 = v320 + v322;
  v324[10] = v335;
  struct StateT * v326 = slot_7(v314);
  return v326;
}

struct StateT * slot_5(struct StateT * v293) {
  int v294 = v293->timer;
  int v305 = v294 + 1;
  v293->timer = v305;
  int * v296 = v293->reg_ready;
  int v297 = v296[12];
  int * v298 = v293->regs;
  int v299 = v298[12];
  int v309 = (v297 + ((v294 - v297) & (~((v294 - v297) >> 31)))) + 1;
  v296[12] = v309;
  int * v301 = v293->regs;
  int v311 = v299 + 72;
  v301[12] = v311;
  struct StateT * v303 = slot_6(v293);
  return v303;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v240 = v226 + 1;
  v225->timer = v240;
  int * v228 = v225->reg_ready;
  int * v230 = v225->regs;
  int v231 = v230[10];
  int v233 = v230[12];
  bool v245 = (v231 ^ -2147483648) >= (v233 ^ -2147483648);
  struct StateT * v238;
  if (v245) {
    struct StateT * v234 = slot_15(v225);
    v238 = v234;
  } else {
    struct StateT * v236 = slot_3(v225);
    v238 = v236;
  }
  return v238;
}

struct StateT * slot_7(struct StateT * v338) {
  int v339 = v338->timer;
  int v451 = v339 + 1;
  v338->timer = v451;
  int * v341 = v338->reg_ready;
  int v342 = v341[10];
  int * v343 = v338->regs;
  int v344 = v343[10];
  int * v345 = v338->cache_tags;
  int v456 = (((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2;
  int v346 = v345[v456];
  int v457 = ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + 1;
  int v347 = v345[v457];
  int v458 = 4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2);
  int v348 = v345[v458];
  int v459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v349 = v345[v459];
  int * v350 = v338->cache_vals;
  bool v460 = !(((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) == 0);
  int v443;
  if (v460) {
    int * v351 = v338->cache_age;
    int v462 = ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) & 1);
    int v352 = v351[v462];
    int v353 = v351[v456];
    int v463 = v353 + ((int)((unsigned int)(v353 - v352) >> 31));
    v351[v456] = v463;
    int * v355 = v338->cache_age;
    int v356 = v355[v457];
    int v465 = v356 + ((int)((unsigned int)(v356 - v352) >> 31));
    v355[v457] = v465;
    int * v358 = v338->cache_age;
    v358[v462] = 0;
    v443 = v462;
  } else {
    int * v361 = v338->cache_age;
    int v469 = (((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2;
    int v362 = v361[v469];
    int * v363 = v338->cache_tags;
    int v364 = v363[v469];
    int v365 = v361[v457];
    int v366 = v363[v457];
    bool v471 = !(((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) == 0);
    int v420;
    if (v471) {
      int * v367 = v338->cache_age;
      int v473 = (4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) & 1);
      int v368 = v367[v473];
      int v369 = v367[v458];
      int v474 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v458] = v474;
      int * v371 = v338->cache_age;
      int v372 = v371[v459];
      int v476 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v459] = v476;
      int * v374 = v338->cache_age;
      v374[v473] = 0;
      v420 = v473;
    } else {
      int * v377 = v338->cache_age;
      int v480 = 4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2);
      int v378 = v377[v480];
      int * v379 = v338->cache_tags;
      int v380 = v379[v480];
      int v381 = v377[v459];
      int v382 = v379[v459];
      int * v383 = v338->cache_dirty;
      int v483 = (4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v384 = v383[v483];
      bool v484 = !(v384 == 0);
      if (v484) {
        int * v385 = v338->cache_tags;
        int v386 = v385[v483];
        int * v387 = v338->cache_vals;
        int v487 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v388 = v387[v487];
        int v488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v389 = v387[v488];
        int * v390 = v338->mem;
        int v490 = v386 * 2;
        v390[v490] = v388;
        int * v392 = v338->mem;
        int v493 = (v386 * 2) + 1;
        v392[v493] = v389;
        ;
      } else {
        ;
      }
      int * v397 = v338->mem;
      int v498 = ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) * 2;
      int v398 = v397[v498];
      int v499 = (((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) * 2) + 1;
      int v399 = v397[v499];
      int * v400 = v338->cache_vals;
      int v501 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v400[v501] = v398;
      int * v402 = v338->cache_vals;
      int v504 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 3) * 2)) + ((((v378 + ((~(((v380 ^ -1) | (-(v380 ^ -1))) >> 31)) & 2)) - (v381 + ((~(((v382 ^ -1) | (-(v382 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v402[v504] = v399;
      int * v404 = v338->cache_tags;
      int v507 = (int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1);
      v404[v483] = v507;
      int * v406 = v338->cache_dirty;
      v406[v483] = 0;
      int * v408 = v338->cache_age;
      v408[v483] = 1;
      int * v410 = v338->cache_age;
      int v411 = v410[v483];
      int v412 = v410[v458];
      int v513 = v412 + ((int)((unsigned int)(v412 - v411) >> 31));
      v410[v458] = v513;
      int * v414 = v338->cache_age;
      int v415 = v414[v459];
      int v515 = v415 + ((int)((unsigned int)(v415 - v411) >> 31));
      v414[v459] = v515;
      int * v417 = v338->cache_age;
      v417[v483] = 0;
      v420 = v483;
    }
    int * v421 = v338->cache_vals;
    int v518 = v420 * 2;
    int v422 = v421[v518];
    int v519 = (v420 * 2) + 1;
    int v423 = v421[v519];
    int v520 = (((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v421[v520] = v422;
    int * v425 = v338->cache_vals;
    int v523 = ((((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v425[v523] = v423;
    int * v427 = v338->cache_tags;
    int v526 = ((((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1)) & 1) * 2) + ((((v362 + ((~(((v364 ^ -1) | (-(v364 ^ -1))) >> 31)) & 2)) - (v365 + ((~(((v366 ^ -1) | (-(v366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v527 = (int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1);
    v427[v526] = v527;
    int * v429 = v338->cache_dirty;
    v429[v526] = 0;
    int * v431 = v338->cache_age;
    v431[v526] = 1;
    int * v433 = v338->cache_age;
    int v434 = v433[v526];
    int v435 = v433[v456];
    int v533 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
    v433[v456] = v533;
    int * v437 = v338->cache_age;
    int v438 = v437[v457];
    int v535 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
    v437[v457] = v535;
    int * v440 = v338->cache_age;
    v440[v526] = 0;
    v443 = v526;
  }
  int v538 = (v443 * 2) + (((int)((unsigned int)v344 >> 2)) & 1);
  int v444 = v350[v538];
  int * v445 = v338->reg_ready;
  int v540 = ((v342 + ((v339 - v342) & (~((v339 - v342) >> 31)))) + 1) + ((100 ^ (((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v346 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v344 >> 2)) >> 1))))) >> 31))) & 104)))));
  v445[10] = v540;
  int * v447 = v338->regs;
  v447[10] = v444;
  struct StateT * v449 = slot_8(v338);
  return v449;
}

struct StateT * slot_3(struct StateT * v256) {
  int v257 = v256->timer;
  int v268 = v257 + 1;
  v256->timer = v268;
  int * v259 = v256->reg_ready;
  int v260 = v259[10];
  int * v261 = v256->regs;
  int v262 = v261[10];
  int v272 = (v260 + ((v257 - v260) & (~((v257 - v260) >> 31)))) + 1;
  v259[10] = v272;
  int * v264 = v256->regs;
  int v274 = v262 << 2;
  v264[10] = v274;
  struct StateT * v266 = slot_4(v256);
  return v266;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1361 = v1->timer;
  int * v1362 = v1->reg_ready;
  int v1363 = v1362[0];
  int v1494 = v1363 + ((v1361 - v1363) & (~((v1361 - v1363) >> 31)));
  v1->timer = v1494;
  int v1365 = v1->timer;
  int * v1366 = v1->reg_ready;
  int v1367 = v1366[1];
  int v1497 = v1367 + ((v1365 - v1367) & (~((v1365 - v1367) >> 31)));
  v1->timer = v1497;
  int v1369 = v1->timer;
  int * v1370 = v1->reg_ready;
  int v1371 = v1370[2];
  int v1500 = v1371 + ((v1369 - v1371) & (~((v1369 - v1371) >> 31)));
  v1->timer = v1500;
  int v1373 = v1->timer;
  int * v1374 = v1->reg_ready;
  int v1375 = v1374[3];
  int v1503 = v1375 + ((v1373 - v1375) & (~((v1373 - v1375) >> 31)));
  v1->timer = v1503;
  int v1377 = v1->timer;
  int * v1378 = v1->reg_ready;
  int v1379 = v1378[4];
  int v1506 = v1379 + ((v1377 - v1379) & (~((v1377 - v1379) >> 31)));
  v1->timer = v1506;
  int v1381 = v1->timer;
  int * v1382 = v1->reg_ready;
  int v1383 = v1382[5];
  int v1509 = v1383 + ((v1381 - v1383) & (~((v1381 - v1383) >> 31)));
  v1->timer = v1509;
  int v1385 = v1->timer;
  int * v1386 = v1->reg_ready;
  int v1387 = v1386[6];
  int v1512 = v1387 + ((v1385 - v1387) & (~((v1385 - v1387) >> 31)));
  v1->timer = v1512;
  int v1389 = v1->timer;
  int * v1390 = v1->reg_ready;
  int v1391 = v1390[7];
  int v1515 = v1391 + ((v1389 - v1391) & (~((v1389 - v1391) >> 31)));
  v1->timer = v1515;
  int v1393 = v1->timer;
  int * v1394 = v1->reg_ready;
  int v1395 = v1394[8];
  int v1518 = v1395 + ((v1393 - v1395) & (~((v1393 - v1395) >> 31)));
  v1->timer = v1518;
  int v1397 = v1->timer;
  int * v1398 = v1->reg_ready;
  int v1399 = v1398[9];
  int v1521 = v1399 + ((v1397 - v1399) & (~((v1397 - v1399) >> 31)));
  v1->timer = v1521;
  int v1401 = v1->timer;
  int * v1402 = v1->reg_ready;
  int v1403 = v1402[10];
  int v1524 = v1403 + ((v1401 - v1403) & (~((v1401 - v1403) >> 31)));
  v1->timer = v1524;
  int v1405 = v1->timer;
  int * v1406 = v1->reg_ready;
  int v1407 = v1406[11];
  int v1527 = v1407 + ((v1405 - v1407) & (~((v1405 - v1407) >> 31)));
  v1->timer = v1527;
  int v1409 = v1->timer;
  int * v1410 = v1->reg_ready;
  int v1411 = v1410[12];
  int v1530 = v1411 + ((v1409 - v1411) & (~((v1409 - v1411) >> 31)));
  v1->timer = v1530;
  int v1413 = v1->timer;
  int * v1414 = v1->reg_ready;
  int v1415 = v1414[13];
  int v1533 = v1415 + ((v1413 - v1415) & (~((v1413 - v1415) >> 31)));
  v1->timer = v1533;
  int v1417 = v1->timer;
  int * v1418 = v1->reg_ready;
  int v1419 = v1418[14];
  int v1536 = v1419 + ((v1417 - v1419) & (~((v1417 - v1419) >> 31)));
  v1->timer = v1536;
  int v1421 = v1->timer;
  int * v1422 = v1->reg_ready;
  int v1423 = v1422[15];
  int v1539 = v1423 + ((v1421 - v1423) & (~((v1421 - v1423) >> 31)));
  v1->timer = v1539;
  int v1425 = v1->timer;
  int * v1426 = v1->reg_ready;
  int v1427 = v1426[16];
  int v1542 = v1427 + ((v1425 - v1427) & (~((v1425 - v1427) >> 31)));
  v1->timer = v1542;
  int v1429 = v1->timer;
  int * v1430 = v1->reg_ready;
  int v1431 = v1430[17];
  int v1545 = v1431 + ((v1429 - v1431) & (~((v1429 - v1431) >> 31)));
  v1->timer = v1545;
  int v1433 = v1->timer;
  int * v1434 = v1->reg_ready;
  int v1435 = v1434[18];
  int v1548 = v1435 + ((v1433 - v1435) & (~((v1433 - v1435) >> 31)));
  v1->timer = v1548;
  int v1437 = v1->timer;
  int * v1438 = v1->reg_ready;
  int v1439 = v1438[19];
  int v1551 = v1439 + ((v1437 - v1439) & (~((v1437 - v1439) >> 31)));
  v1->timer = v1551;
  int v1441 = v1->timer;
  int * v1442 = v1->reg_ready;
  int v1443 = v1442[20];
  int v1554 = v1443 + ((v1441 - v1443) & (~((v1441 - v1443) >> 31)));
  v1->timer = v1554;
  int v1445 = v1->timer;
  int * v1446 = v1->reg_ready;
  int v1447 = v1446[21];
  int v1557 = v1447 + ((v1445 - v1447) & (~((v1445 - v1447) >> 31)));
  v1->timer = v1557;
  int v1449 = v1->timer;
  int * v1450 = v1->reg_ready;
  int v1451 = v1450[22];
  int v1560 = v1451 + ((v1449 - v1451) & (~((v1449 - v1451) >> 31)));
  v1->timer = v1560;
  int v1453 = v1->timer;
  int * v1454 = v1->reg_ready;
  int v1455 = v1454[23];
  int v1563 = v1455 + ((v1453 - v1455) & (~((v1453 - v1455) >> 31)));
  v1->timer = v1563;
  int v1457 = v1->timer;
  int * v1458 = v1->reg_ready;
  int v1459 = v1458[24];
  int v1566 = v1459 + ((v1457 - v1459) & (~((v1457 - v1459) >> 31)));
  v1->timer = v1566;
  int v1461 = v1->timer;
  int * v1462 = v1->reg_ready;
  int v1463 = v1462[25];
  int v1569 = v1463 + ((v1461 - v1463) & (~((v1461 - v1463) >> 31)));
  v1->timer = v1569;
  int v1465 = v1->timer;
  int * v1466 = v1->reg_ready;
  int v1467 = v1466[26];
  int v1572 = v1467 + ((v1465 - v1467) & (~((v1465 - v1467) >> 31)));
  v1->timer = v1572;
  int v1469 = v1->timer;
  int * v1470 = v1->reg_ready;
  int v1471 = v1470[27];
  int v1575 = v1471 + ((v1469 - v1471) & (~((v1469 - v1471) >> 31)));
  v1->timer = v1575;
  int v1473 = v1->timer;
  int * v1474 = v1->reg_ready;
  int v1475 = v1474[28];
  int v1578 = v1475 + ((v1473 - v1475) & (~((v1473 - v1475) >> 31)));
  v1->timer = v1578;
  int v1477 = v1->timer;
  int * v1478 = v1->reg_ready;
  int v1479 = v1478[29];
  int v1581 = v1479 + ((v1477 - v1479) & (~((v1477 - v1479) >> 31)));
  v1->timer = v1581;
  int v1481 = v1->timer;
  int * v1482 = v1->reg_ready;
  int v1483 = v1482[30];
  int v1584 = v1483 + ((v1481 - v1483) & (~((v1481 - v1483) >> 31)));
  v1->timer = v1584;
  int v1485 = v1->timer;
  int * v1486 = v1->reg_ready;
  int v1487 = v1486[31];
  int v1587 = v1487 + ((v1485 - v1487) & (~((v1485 - v1487) >> 31)));
  v1->timer = v1587;
  return v1;
}

struct StateT * slot_10(struct StateT * v587) {
  int v588 = v587->timer;
  int v596 = v588 + 1;
  v587->timer = v596;
  int * v590 = v587->reg_ready;
  v590[11] = v596;
  int * v592 = v587->regs;
  v592[11] = 0;
  struct StateT * v594 = slot_11(v587);
  return v594;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[12];
  int * v23 = v18->regs;
  int v24 = v23[12];
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
  v125[12] = v220;
  int * v127 = v18->regs;
  v127[12] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v545) {
  int v546 = v545->timer;
  int v560 = v546 + 1;
  v545->timer = v560;
  int * v548 = v545->reg_ready;
  int * v550 = v545->regs;
  int v551 = v550[10];
  int v553 = v550[11];
  bool v565 = !(v551 == v553);
  struct StateT * v558;
  if (v565) {
    struct StateT * v554 = slot_15(v545);
    v558 = v554;
  } else {
    struct StateT * v556 = slot_9(v545);
    v558 = v556;
  }
  return v558;
}

struct StateT * slot_4(struct StateT * v277) {
  int v278 = v277->timer;
  int v286 = v278 + 1;
  v277->timer = v286;
  int * v280 = v277->reg_ready;
  v280[12] = v286;
  int * v282 = v277->regs;
  v282[12] = 0;
  struct StateT * v284 = slot_5(v277);
  return v284;
}

struct StateT * slot_13(struct StateT * v1018) {
  int v1019 = v1018->timer;
  int v1032 = v1019 + 1;
  v1018->timer = v1032;
  int * v1021 = v1018->reg_ready;
  int v1022 = v1021[12];
  int * v1023 = v1018->regs;
  int v1024 = v1023[12];
  int v1025 = v1021[10];
  int v1026 = v1023[10];
  int v1037 = (v1025 + (((v1022 + ((v1019 - v1022) & (~((v1019 - v1022) >> 31)))) - v1025) & (~(((v1022 + ((v1019 - v1022) & (~((v1019 - v1022) >> 31)))) - v1025) >> 31)))) + 1;
  v1021[10] = v1037;
  int * v1028 = v1018->regs;
  int v1039 = v1024 & v1026;
  v1028[10] = v1039;
  struct StateT * v1030 = slot_14(v1018);
  return v1030;
}

struct StateT * slot_15(struct StateT * v251) {
  int v252 = v251->timer;
  int v255 = v252 + 1;
  v251->timer = v255;
  return v251;
}

struct StateT * slot_9(struct StateT * v571) {
  int v572 = v571->timer;
  int v580 = v572 + 1;
  v571->timer = v580;
  int * v574 = v571->reg_ready;
  v574[10] = v580;
  int * v576 = v571->regs;
  v576[10] = 0;
  struct StateT * v578 = slot_10(v571);
  return v578;
}

struct StateT * slot_11(struct StateT * v603) {
  int v604 = v603->timer;
  int v716 = v604 + 1;
  v603->timer = v716;
  int * v606 = v603->reg_ready;
  int v607 = v606[10];
  int * v608 = v603->regs;
  int v609 = v608[10];
  int * v610 = v603->cache_tags;
  int v721 = (((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2;
  int v611 = v610[v721];
  int v722 = ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v612 = v610[v722];
  int v723 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2);
  int v613 = v610[v723];
  int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v614 = v610[v724];
  int * v615 = v603->cache_vals;
  bool v725 = !(((~(((v611 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v611 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v612 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v612 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v708;
  if (v725) {
    int * v616 = v603->cache_age;
    int v727 = ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v612 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v612 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v617 = v616[v727];
    int v618 = v616[v721];
    int v728 = v618 + ((int)((unsigned int)(v618 - v617) >> 31));
    v616[v721] = v728;
    int * v620 = v603->cache_age;
    int v621 = v620[v722];
    int v730 = v621 + ((int)((unsigned int)(v621 - v617) >> 31));
    v620[v722] = v730;
    int * v623 = v603->cache_age;
    v623[v727] = 0;
    v708 = v727;
  } else {
    int * v626 = v603->cache_age;
    int v734 = (((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2;
    int v627 = v626[v734];
    int * v628 = v603->cache_tags;
    int v629 = v628[v734];
    int v630 = v626[v722];
    int v631 = v628[v722];
    bool v736 = !(((~(((v613 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v613 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v685;
    if (v736) {
      int * v632 = v603->cache_age;
      int v738 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v633 = v632[v738];
      int v634 = v632[v723];
      int v739 = v634 + ((int)((unsigned int)(v634 - v633) >> 31));
      v632[v723] = v739;
      int * v636 = v603->cache_age;
      int v637 = v636[v724];
      int v741 = v637 + ((int)((unsigned int)(v637 - v633) >> 31));
      v636[v724] = v741;
      int * v639 = v603->cache_age;
      v639[v738] = 0;
      v685 = v738;
    } else {
      int * v642 = v603->cache_age;
      int v745 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2);
      int v643 = v642[v745];
      int * v644 = v603->cache_tags;
      int v645 = v644[v745];
      int v646 = v642[v724];
      int v647 = v644[v724];
      int * v648 = v603->cache_dirty;
      int v748 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v647 ^ -1) | (-(v647 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v649 = v648[v748];
      bool v749 = !(v649 == 0);
      if (v749) {
        int * v650 = v603->cache_tags;
        int v651 = v650[v748];
        int * v652 = v603->cache_vals;
        int v752 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v647 ^ -1) | (-(v647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v653 = v652[v752];
        int v753 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v647 ^ -1) | (-(v647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v654 = v652[v753];
        int * v655 = v603->mem;
        int v755 = v651 * 2;
        v655[v755] = v653;
        int * v657 = v603->mem;
        int v758 = (v651 * 2) + 1;
        v657[v758] = v654;
        ;
      } else {
        ;
      }
      int * v662 = v603->mem;
      int v763 = ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) * 2;
      int v663 = v662[v763];
      int v764 = (((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) * 2) + 1;
      int v664 = v662[v764];
      int * v665 = v603->cache_vals;
      int v766 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v647 ^ -1) | (-(v647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v665[v766] = v663;
      int * v667 = v603->cache_vals;
      int v769 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v643 + ((~(((v645 ^ -1) | (-(v645 ^ -1))) >> 31)) & 2)) - (v646 + ((~(((v647 ^ -1) | (-(v647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v667[v769] = v664;
      int * v669 = v603->cache_tags;
      int v772 = (int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1);
      v669[v748] = v772;
      int * v671 = v603->cache_dirty;
      v671[v748] = 0;
      int * v673 = v603->cache_age;
      v673[v748] = 1;
      int * v675 = v603->cache_age;
      int v676 = v675[v748];
      int v677 = v675[v723];
      int v778 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
      v675[v723] = v778;
      int * v679 = v603->cache_age;
      int v680 = v679[v724];
      int v780 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
      v679[v724] = v780;
      int * v682 = v603->cache_age;
      v682[v748] = 0;
      v685 = v748;
    }
    int * v686 = v603->cache_vals;
    int v783 = v685 * 2;
    int v687 = v686[v783];
    int v784 = (v685 * 2) + 1;
    int v688 = v686[v784];
    int v785 = (((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v686[v785] = v687;
    int * v690 = v603->cache_vals;
    int v788 = ((((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v690[v788] = v688;
    int * v692 = v603->cache_tags;
    int v791 = ((((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v627 + ((~(((v629 ^ -1) | (-(v629 ^ -1))) >> 31)) & 2)) - (v630 + ((~(((v631 ^ -1) | (-(v631 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v792 = (int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1);
    v692[v791] = v792;
    int * v694 = v603->cache_dirty;
    v694[v791] = 0;
    int * v696 = v603->cache_age;
    v696[v791] = 1;
    int * v698 = v603->cache_age;
    int v699 = v698[v791];
    int v700 = v698[v721];
    int v798 = v700 + ((int)((unsigned int)(v700 - v699) >> 31));
    v698[v721] = v798;
    int * v702 = v603->cache_age;
    int v703 = v702[v722];
    int v800 = v703 + ((int)((unsigned int)(v703 - v699) >> 31));
    v702[v722] = v800;
    int * v705 = v603->cache_age;
    v705[v791] = 0;
    v708 = v791;
  }
  int v803 = (v708 * 2) + (((int)((unsigned int)(v609 + 4) >> 2)) & 1);
  int v709 = v615[v803];
  int * v710 = v603->reg_ready;
  int v805 = ((v607 + ((v604 - v607) & (~((v604 - v607) >> 31)))) + 1) + ((100 ^ (((~(((v613 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v613 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v611 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v611 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v612 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v612 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v613 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v613 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))) | (-(v614 ^ ((int)((unsigned int)((int)((unsigned int)(v609 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v710[10] = v805;
  int * v712 = v603->regs;
  v712[10] = v709;
  struct StateT * v714 = slot_12(v603);
  return v714;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 0;
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
  int k = bounded(0, 20);
  s1.regs[11] = k;
  s2.regs[11] = k;
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