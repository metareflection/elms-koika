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

struct StateT * slot_12(struct StateT * v750);
struct StateT * slot_14(struct StateT * v1112);
struct StateT * slot_6(struct StateT * v474);
struct StateT * slot_16(struct StateT * v797);
struct StateT * slot_5(struct StateT * v271);
struct StateT * slot_17(struct StateT * v240);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v487);
struct StateT * slot_3(struct StateT * v245);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v531);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v501);
struct StateT * slot_4(struct StateT * v258);
struct StateT * slot_13(struct StateT * v783);
struct StateT * slot_15(struct StateT * v770);
struct StateT * slot_9(struct StateT * v515);
struct StateT * slot_11(struct StateT * v734);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v750) {
  int v751 = v750->timer;
  int v761 = v751 + 1;
  v750->timer = v761;
  int * v753 = v750->regs;
  int v754 = v753[13];
  bool v764 = !(v754 == 0);
  struct StateT * v759;
  if (v764) {
    struct StateT * v755 = slot_15(v750);
    v759 = v755;
  } else {
    struct StateT * v757 = slot_13(v750);
    v759 = v757;
  }
  return v759;
}

struct StateT * slot_14(struct StateT * v1112) {
  int v1113 = v1112->timer;
  int v1124 = v1113 + 1;
  v1112->timer = v1124;
  int * v1115 = v1112->regs;
  int v1116 = v1115[10];
  int v1117 = v1115[11];
  bool v1128 = (v1116 ^ -2147483648) < (v1117 ^ -2147483648);
  struct StateT * v1122;
  if (v1128) {
    struct StateT * v1118 = slot_8(v1112);
    v1122 = v1118;
  } else {
    struct StateT * v1120 = slot_15(v1112);
    v1122 = v1120;
  }
  return v1122;
}

struct StateT * slot_6(struct StateT * v474) {
  int v475 = v474->timer;
  int v481 = v475 + 1;
  v474->timer = v481;
  int * v477 = v474->regs;
  v477[14] = 0;
  struct StateT * v479 = slot_7(v474);
  return v479;
}

struct StateT * slot_16(struct StateT * v797) {
  int v798 = v797->timer;
  int v968 = v798 + 1;
  v797->timer = v968;
  int * v800 = v797->regs;
  int v801 = v800[10];
  int v802 = v800[12];
  int * v803 = v797->cache_tags;
  int v973 = (((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2;
  int v804 = v803[v973];
  int v974 = ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v805 = v803[v974];
  int v975 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2);
  int v806 = v803[v975];
  int v976 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v807 = v803[v976];
  int v808 = v797->timer;
  int v977 = v808 + ((100 ^ (((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v797->timer = v977;
  bool v978 = !(((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v902;
  if (v978) {
    int * v810 = v797->cache_age;
    int v980 = ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v811 = v810[v980];
    int v812 = v810[v973];
    int v981 = v812 + ((int)((unsigned int)(v812 - v811) >> 31));
    v810[v973] = v981;
    int * v814 = v797->cache_age;
    int v815 = v814[v974];
    int v983 = v815 + ((int)((unsigned int)(v815 - v811) >> 31));
    v814[v974] = v983;
    int * v817 = v797->cache_age;
    v817[v980] = 0;
    v902 = v980;
  } else {
    int * v820 = v797->cache_age;
    int v987 = (((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2;
    int v821 = v820[v987];
    int * v822 = v797->cache_tags;
    int v823 = v822[v987];
    int v824 = v820[v974];
    int v825 = v822[v974];
    bool v989 = !(((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v879;
    if (v989) {
      int * v826 = v797->cache_age;
      int v991 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v827 = v826[v991];
      int v828 = v826[v975];
      int v992 = v828 + ((int)((unsigned int)(v828 - v827) >> 31));
      v826[v975] = v992;
      int * v830 = v797->cache_age;
      int v831 = v830[v976];
      int v994 = v831 + ((int)((unsigned int)(v831 - v827) >> 31));
      v830[v976] = v994;
      int * v833 = v797->cache_age;
      v833[v991] = 0;
      v879 = v991;
    } else {
      int * v836 = v797->cache_age;
      int v998 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2);
      int v837 = v836[v998];
      int * v838 = v797->cache_tags;
      int v839 = v838[v998];
      int v840 = v836[v976];
      int v841 = v838[v976];
      int * v842 = v797->cache_dirty;
      int v1001 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v843 = v842[v1001];
      bool v1002 = !(v843 == 0);
      if (v1002) {
        int * v844 = v797->cache_tags;
        int v845 = v844[v1001];
        int * v846 = v797->cache_vals;
        int v1005 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v847 = v846[v1005];
        int v1006 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v848 = v846[v1006];
        int * v849 = v797->mem;
        int v1008 = v845 * 2;
        v849[v1008] = v847;
        int * v851 = v797->mem;
        int v1011 = (v845 * 2) + 1;
        v851[v1011] = v848;
        ;
      } else {
        ;
      }
      int * v856 = v797->mem;
      int v1016 = ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) * 2;
      int v857 = v856[v1016];
      int v1017 = (((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) * 2) + 1;
      int v858 = v856[v1017];
      int * v859 = v797->cache_vals;
      int v1019 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v859[v1019] = v857;
      int * v861 = v797->cache_vals;
      int v1022 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v837 + ((~(((v839 ^ -1) | (-(v839 ^ -1))) >> 31)) & 2)) - (v840 + ((~(((v841 ^ -1) | (-(v841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v861[v1022] = v858;
      int * v863 = v797->cache_tags;
      int v1025 = (int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1);
      v863[v1001] = v1025;
      int * v865 = v797->cache_dirty;
      v865[v1001] = 0;
      int * v867 = v797->cache_age;
      v867[v1001] = 1;
      int * v869 = v797->cache_age;
      int v870 = v869[v1001];
      int v871 = v869[v975];
      int v1031 = v871 + ((int)((unsigned int)(v871 - v870) >> 31));
      v869[v975] = v1031;
      int * v873 = v797->cache_age;
      int v874 = v873[v976];
      int v1033 = v874 + ((int)((unsigned int)(v874 - v870) >> 31));
      v873[v976] = v1033;
      int * v876 = v797->cache_age;
      v876[v1001] = 0;
      v879 = v1001;
    }
    int * v880 = v797->cache_vals;
    int v1036 = v879 * 2;
    int v881 = v880[v1036];
    int v1037 = (v879 * 2) + 1;
    int v882 = v880[v1037];
    int v1038 = (((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v821 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2)) - (v824 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v880[v1038] = v881;
    int * v884 = v797->cache_vals;
    int v1041 = ((((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v821 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2)) - (v824 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v884[v1041] = v882;
    int * v886 = v797->cache_tags;
    int v1044 = ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v821 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2)) - (v824 + ((~(((v825 ^ -1) | (-(v825 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1045 = (int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1);
    v886[v1044] = v1045;
    int * v888 = v797->cache_dirty;
    v888[v1044] = 0;
    int * v890 = v797->cache_age;
    v890[v1044] = 1;
    int * v892 = v797->cache_age;
    int v893 = v892[v1044];
    int v894 = v892[v973];
    int v1051 = v894 + ((int)((unsigned int)(v894 - v893) >> 31));
    v892[v973] = v1051;
    int * v896 = v797->cache_age;
    int v897 = v896[v974];
    int v1053 = v897 + ((int)((unsigned int)(v897 - v893) >> 31));
    v896[v974] = v1053;
    int * v899 = v797->cache_age;
    v899[v1044] = 0;
    v902 = v1044;
  }
  int * v903 = v797->cache_vals;
  int v1056 = (v902 * 2) + (((int)((unsigned int)(v801 + 68) >> 2)) & 1);
  v903[v1056] = v802;
  int * v905 = v797->cache_tags;
  int v906 = v905[v975];
  int v907 = v905[v976];
  bool v1059 = !(((~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v961;
  if (v1059) {
    int * v908 = v797->cache_age;
    int v1061 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v907 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))) | (-(v907 ^ ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v909 = v908[v1061];
    int v910 = v908[v975];
    int v1062 = v910 + ((int)((unsigned int)(v910 - v909) >> 31));
    v908[v975] = v1062;
    int * v912 = v797->cache_age;
    int v913 = v912[v976];
    int v1064 = v913 + ((int)((unsigned int)(v913 - v909) >> 31));
    v912[v976] = v1064;
    int * v915 = v797->cache_age;
    v915[v1061] = 0;
    v961 = v1061;
  } else {
    int * v918 = v797->cache_age;
    int v1068 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2);
    int v919 = v918[v1068];
    int * v920 = v797->cache_tags;
    int v921 = v920[v1068];
    int v922 = v918[v976];
    int v923 = v920[v976];
    int * v924 = v797->cache_dirty;
    int v1071 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v919 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2)) - (v922 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v925 = v924[v1071];
    bool v1072 = !(v925 == 0);
    if (v1072) {
      int * v926 = v797->cache_tags;
      int v927 = v926[v1071];
      int * v928 = v797->cache_vals;
      int v1075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v919 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2)) - (v922 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v929 = v928[v1075];
      int v1076 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v919 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2)) - (v922 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v930 = v928[v1076];
      int * v931 = v797->mem;
      int v1078 = v927 * 2;
      v931[v1078] = v929;
      int * v933 = v797->mem;
      int v1081 = (v927 * 2) + 1;
      v933[v1081] = v930;
      ;
    } else {
      ;
    }
    int * v938 = v797->mem;
    int v1086 = ((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) * 2;
    int v939 = v938[v1086];
    int v1087 = (((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) * 2) + 1;
    int v940 = v938[v1087];
    int * v941 = v797->cache_vals;
    int v1089 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v919 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2)) - (v922 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v941[v1089] = v939;
    int * v943 = v797->cache_vals;
    int v1092 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v919 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2)) - (v922 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v943[v1092] = v940;
    int * v945 = v797->cache_tags;
    int v1095 = (int)((unsigned int)((int)((unsigned int)(v801 + 68) >> 2)) >> 1);
    v945[v1071] = v1095;
    int * v947 = v797->cache_dirty;
    v947[v1071] = 0;
    int * v949 = v797->cache_age;
    v949[v1071] = 1;
    int * v951 = v797->cache_age;
    int v952 = v951[v1071];
    int v953 = v951[v975];
    int v1101 = v953 + ((int)((unsigned int)(v953 - v952) >> 31));
    v951[v975] = v1101;
    int * v955 = v797->cache_age;
    int v956 = v955[v976];
    int v1103 = v956 + ((int)((unsigned int)(v956 - v952) >> 31));
    v955[v976] = v1103;
    int * v958 = v797->cache_age;
    v958[v1071] = 0;
    v961 = v1071;
  }
  int * v962 = v797->cache_vals;
  int v1106 = (v961 * 2) + (((int)((unsigned int)(v801 + 68) >> 2)) & 1);
  v962[v1106] = v802;
  int * v964 = v797->cache_dirty;
  v964[v961] = 1;
  struct StateT * v966 = slot_17(v797);
  return v966;
}

struct StateT * slot_5(struct StateT * v271) {
  int v272 = v271->timer;
  int v382 = v272 + 1;
  v271->timer = v382;
  int * v274 = v271->regs;
  int v275 = v274[12];
  int * v276 = v271->cache_tags;
  int v386 = (((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2;
  int v277 = v276[v386];
  int v387 = ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v278 = v276[v387];
  int v388 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2);
  int v279 = v276[v388];
  int v389 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v280 = v276[v389];
  int v281 = v271->timer;
  int v390 = v281 + ((100 ^ (((~(((v279 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v279 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v277 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v277 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v279 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v279 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v271->timer = v390;
  int * v283 = v271->cache_vals;
  bool v391 = !(((~(((v277 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v277 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v376;
  if (v391) {
    int * v284 = v271->cache_age;
    int v393 = ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v285 = v284[v393];
    int v286 = v284[v386];
    int v394 = v286 + ((int)((unsigned int)(v286 - v285) >> 31));
    v284[v386] = v394;
    int * v288 = v271->cache_age;
    int v289 = v288[v387];
    int v396 = v289 + ((int)((unsigned int)(v289 - v285) >> 31));
    v288[v387] = v396;
    int * v291 = v271->cache_age;
    v291[v393] = 0;
    v376 = v393;
  } else {
    int * v294 = v271->cache_age;
    int v400 = (((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2;
    int v295 = v294[v400];
    int * v296 = v271->cache_tags;
    int v297 = v296[v400];
    int v298 = v294[v387];
    int v299 = v296[v387];
    bool v402 = !(((~(((v279 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v279 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v353;
    if (v402) {
      int * v300 = v271->cache_age;
      int v404 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))) | (-(v280 ^ ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v301 = v300[v404];
      int v302 = v300[v388];
      int v405 = v302 + ((int)((unsigned int)(v302 - v301) >> 31));
      v300[v388] = v405;
      int * v304 = v271->cache_age;
      int v305 = v304[v389];
      int v407 = v305 + ((int)((unsigned int)(v305 - v301) >> 31));
      v304[v389] = v407;
      int * v307 = v271->cache_age;
      v307[v404] = 0;
      v353 = v404;
    } else {
      int * v310 = v271->cache_age;
      int v411 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2);
      int v311 = v310[v411];
      int * v312 = v271->cache_tags;
      int v313 = v312[v411];
      int v314 = v310[v389];
      int v315 = v312[v389];
      int * v316 = v271->cache_dirty;
      int v414 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v314 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v317 = v316[v414];
      bool v415 = !(v317 == 0);
      if (v415) {
        int * v318 = v271->cache_tags;
        int v319 = v318[v414];
        int * v320 = v271->cache_vals;
        int v418 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v314 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v321 = v320[v418];
        int v419 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v314 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v322 = v320[v419];
        int * v323 = v271->mem;
        int v421 = v319 * 2;
        v323[v421] = v321;
        int * v325 = v271->mem;
        int v424 = (v319 * 2) + 1;
        v325[v424] = v322;
        ;
      } else {
        ;
      }
      int * v330 = v271->mem;
      int v429 = ((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) * 2;
      int v331 = v330[v429];
      int v430 = (((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) * 2) + 1;
      int v332 = v330[v430];
      int * v333 = v271->cache_vals;
      int v432 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v314 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v333[v432] = v331;
      int * v335 = v271->cache_vals;
      int v435 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v311 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2)) - (v314 + ((~(((v315 ^ -1) | (-(v315 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v335[v435] = v332;
      int * v337 = v271->cache_tags;
      int v438 = (int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1);
      v337[v414] = v438;
      int * v339 = v271->cache_dirty;
      v339[v414] = 0;
      int * v341 = v271->cache_age;
      v341[v414] = 1;
      int * v343 = v271->cache_age;
      int v344 = v343[v414];
      int v345 = v343[v388];
      int v444 = v345 + ((int)((unsigned int)(v345 - v344) >> 31));
      v343[v388] = v444;
      int * v347 = v271->cache_age;
      int v348 = v347[v389];
      int v446 = v348 + ((int)((unsigned int)(v348 - v344) >> 31));
      v347[v389] = v446;
      int * v350 = v271->cache_age;
      v350[v414] = 0;
      v353 = v414;
    }
    int * v354 = v271->cache_vals;
    int v449 = v353 * 2;
    int v355 = v354[v449];
    int v450 = (v353 * 2) + 1;
    int v356 = v354[v450];
    int v451 = (((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v354[v451] = v355;
    int * v358 = v271->cache_vals;
    int v454 = ((((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v358[v454] = v356;
    int * v360 = v271->cache_tags;
    int v457 = ((((int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v295 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2)) - (v298 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v458 = (int)((unsigned int)((int)((unsigned int)(v275 + 68) >> 2)) >> 1);
    v360[v457] = v458;
    int * v362 = v271->cache_dirty;
    v362[v457] = 0;
    int * v364 = v271->cache_age;
    v364[v457] = 1;
    int * v366 = v271->cache_age;
    int v367 = v366[v457];
    int v368 = v366[v386];
    int v464 = v368 + ((int)((unsigned int)(v368 - v367) >> 31));
    v366[v386] = v464;
    int * v370 = v271->cache_age;
    int v371 = v370[v387];
    int v466 = v371 + ((int)((unsigned int)(v371 - v367) >> 31));
    v370[v387] = v466;
    int * v373 = v271->cache_age;
    v373[v457] = 0;
    v376 = v457;
  }
  int v469 = (v376 * 2) + (((int)((unsigned int)(v275 + 68) >> 2)) & 1);
  int v377 = v283[v469];
  int * v378 = v271->regs;
  v378[12] = v377;
  struct StateT * v380 = slot_6(v271);
  return v380;
}

struct StateT * slot_17(struct StateT * v240) {
  int v241 = v240->timer;
  int v244 = v241 + 1;
  v240->timer = v244;
  return v240;
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
    struct StateT * v224 = slot_17(v218);
    v228 = v224;
  } else {
    struct StateT * v226 = slot_3(v218);
    v228 = v226;
  }
  return v228;
}

struct StateT * slot_7(struct StateT * v487) {
  int v488 = v487->timer;
  int v495 = v488 + 1;
  v487->timer = v495;
  int * v490 = v487->regs;
  int v491 = v490[14];
  int v498 = v491 + 72;
  v490[14] = v498;
  struct StateT * v493 = slot_8(v487);
  return v493;
}

struct StateT * slot_3(struct StateT * v245) {
  int v246 = v245->timer;
  int v252 = v246 + 1;
  v245->timer = v252;
  int * v248 = v245->regs;
  v248[13] = 0;
  struct StateT * v250 = slot_4(v245);
  return v250;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v531) {
  int v532 = v531->timer;
  int v642 = v532 + 1;
  v531->timer = v642;
  int * v534 = v531->regs;
  int v535 = v534[10];
  int * v536 = v531->cache_tags;
  int v646 = (((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2;
  int v537 = v536[v646];
  int v647 = ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2) + 1;
  int v538 = v536[v647];
  int v648 = 4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2);
  int v539 = v536[v648];
  int v649 = (4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v540 = v536[v649];
  int v541 = v531->timer;
  int v650 = v541 + ((100 ^ (((~(((v539 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v539 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) | (~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) | (~(((v538 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v538 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v539 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v539 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) | (~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31))) & 104)))));
  v531->timer = v650;
  int * v543 = v531->cache_vals;
  bool v651 = !(((~(((v537 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v537 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) | (~(((v538 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v538 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31))) == 0);
  int v636;
  if (v651) {
    int * v544 = v531->cache_age;
    int v653 = ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2) + ((~(((v538 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v538 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) & 1);
    int v545 = v544[v653];
    int v546 = v544[v646];
    int v654 = v546 + ((int)((unsigned int)(v546 - v545) >> 31));
    v544[v646] = v654;
    int * v548 = v531->cache_age;
    int v549 = v548[v647];
    int v656 = v549 + ((int)((unsigned int)(v549 - v545) >> 31));
    v548[v647] = v656;
    int * v551 = v531->cache_age;
    v551[v653] = 0;
    v636 = v653;
  } else {
    int * v554 = v531->cache_age;
    int v660 = (((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2;
    int v555 = v554[v660];
    int * v556 = v531->cache_tags;
    int v557 = v556[v660];
    int v558 = v554[v647];
    int v559 = v556[v647];
    bool v662 = !(((~(((v539 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v539 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) | (~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31))) == 0);
    int v613;
    if (v662) {
      int * v560 = v531->cache_age;
      int v664 = (4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + ((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1))))) >> 31)) & 1);
      int v561 = v560[v664];
      int v562 = v560[v648];
      int v665 = v562 + ((int)((unsigned int)(v562 - v561) >> 31));
      v560[v648] = v665;
      int * v564 = v531->cache_age;
      int v565 = v564[v649];
      int v667 = v565 + ((int)((unsigned int)(v565 - v561) >> 31));
      v564[v649] = v667;
      int * v567 = v531->cache_age;
      v567[v664] = 0;
      v613 = v664;
    } else {
      int * v570 = v531->cache_age;
      int v671 = 4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2);
      int v571 = v570[v671];
      int * v572 = v531->cache_tags;
      int v573 = v572[v671];
      int v574 = v570[v649];
      int v575 = v572[v649];
      int * v576 = v531->cache_dirty;
      int v674 = (4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v577 = v576[v674];
      bool v675 = !(v577 == 0);
      if (v675) {
        int * v578 = v531->cache_tags;
        int v579 = v578[v674];
        int * v580 = v531->cache_vals;
        int v678 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v581 = v580[v678];
        int v679 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v582 = v580[v679];
        int * v583 = v531->mem;
        int v681 = v579 * 2;
        v583[v681] = v581;
        int * v585 = v531->mem;
        int v684 = (v579 * 2) + 1;
        v585[v684] = v582;
        ;
      } else {
        ;
      }
      int * v590 = v531->mem;
      int v689 = ((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) * 2;
      int v591 = v590[v689];
      int v690 = (((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) * 2) + 1;
      int v592 = v590[v690];
      int * v593 = v531->cache_vals;
      int v692 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v593[v692] = v591;
      int * v595 = v531->cache_vals;
      int v695 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v595[v695] = v592;
      int * v597 = v531->cache_tags;
      int v698 = (int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1);
      v597[v674] = v698;
      int * v599 = v531->cache_dirty;
      v599[v674] = 0;
      int * v601 = v531->cache_age;
      v601[v674] = 1;
      int * v603 = v531->cache_age;
      int v604 = v603[v674];
      int v605 = v603[v648];
      int v704 = v605 + ((int)((unsigned int)(v605 - v604) >> 31));
      v603[v648] = v704;
      int * v607 = v531->cache_age;
      int v608 = v607[v649];
      int v706 = v608 + ((int)((unsigned int)(v608 - v604) >> 31));
      v607[v649] = v706;
      int * v610 = v531->cache_age;
      v610[v674] = 0;
      v613 = v674;
    }
    int * v614 = v531->cache_vals;
    int v709 = v613 * 2;
    int v615 = v614[v709];
    int v710 = (v613 * 2) + 1;
    int v616 = v614[v710];
    int v711 = (((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v614[v711] = v615;
    int * v618 = v531->cache_vals;
    int v714 = ((((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v618[v714] = v616;
    int * v620 = v531->cache_tags;
    int v717 = ((((int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1)) & 1) * 2) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v718 = (int)((unsigned int)((int)((unsigned int)v535 >> 2)) >> 1);
    v620[v717] = v718;
    int * v622 = v531->cache_dirty;
    v622[v717] = 0;
    int * v624 = v531->cache_age;
    v624[v717] = 1;
    int * v626 = v531->cache_age;
    int v627 = v626[v717];
    int v628 = v626[v646];
    int v724 = v628 + ((int)((unsigned int)(v628 - v627) >> 31));
    v626[v646] = v724;
    int * v630 = v531->cache_age;
    int v631 = v630[v647];
    int v726 = v631 + ((int)((unsigned int)(v631 - v627) >> 31));
    v630[v647] = v726;
    int * v633 = v531->cache_age;
    v633[v717] = 0;
    v636 = v717;
  }
  int v729 = (v636 * 2) + (((int)((unsigned int)v535 >> 2)) & 1);
  int v637 = v543[v729];
  int * v638 = v531->regs;
  v638[10] = v637;
  struct StateT * v640 = slot_11(v531);
  return v640;
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

struct StateT * slot_8(struct StateT * v501) {
  int v502 = v501->timer;
  int v509 = v502 + 1;
  v501->timer = v509;
  int * v504 = v501->regs;
  int v505 = v504[10];
  int v512 = v505 << 2;
  v504[10] = v512;
  struct StateT * v507 = slot_9(v501);
  return v507;
}

struct StateT * slot_4(struct StateT * v258) {
  int v259 = v258->timer;
  int v265 = v259 + 1;
  v258->timer = v265;
  int * v261 = v258->regs;
  v261[12] = 0;
  struct StateT * v263 = slot_5(v258);
  return v263;
}

struct StateT * slot_13(struct StateT * v783) {
  int v784 = v783->timer;
  int v791 = v784 + 1;
  v783->timer = v791;
  int * v786 = v783->regs;
  int v787 = v786[13];
  int v794 = v787 + -1;
  v786[13] = v794;
  struct StateT * v789 = slot_14(v783);
  return v789;
}

struct StateT * slot_15(struct StateT * v770) {
  int v771 = v770->timer;
  int v777 = v771 + 1;
  v770->timer = v777;
  int * v773 = v770->regs;
  v773[10] = 0;
  struct StateT * v775 = slot_16(v770);
  return v775;
}

struct StateT * slot_9(struct StateT * v515) {
  int v516 = v515->timer;
  int v524 = v516 + 1;
  v515->timer = v524;
  int * v518 = v515->regs;
  int v519 = v518[14];
  int v520 = v518[10];
  int v528 = v519 + v520;
  v518[10] = v528;
  struct StateT * v522 = slot_10(v515);
  return v522;
}

struct StateT * slot_11(struct StateT * v734) {
  int v735 = v734->timer;
  int v743 = v735 + 1;
  v734->timer = v743;
  int * v737 = v734->regs;
  int v738 = v737[12];
  int v739 = v737[10];
  int v747 = v738 & v739;
  v737[12] = v747;
  struct StateT * v741 = slot_12(v734);
  return v741;
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