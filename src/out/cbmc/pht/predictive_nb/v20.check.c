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

struct StateT * slot_12(struct StateT * v755);
struct StateT * slot_14(struct StateT * v792);
struct StateT * slot_16(struct StateT * v834);
struct StateT * slot_5(struct StateT * v450);
struct StateT * slot_17(struct StateT * v858);
struct StateT * slot_20(struct StateT * v1297);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v471);
struct StateT * slot_21(struct StateT * v1616);
struct StateT * slot_3(struct StateT * v233);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v532);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v487);
struct StateT * slot_19(struct StateT * v1273);
struct StateT * slot_13(struct StateT * v776);
struct StateT * slot_15(struct StateT * v813);
struct StateT * slot_18(struct StateT * v1065);
struct StateT * slot_9(struct StateT * v508);
struct StateT * slot_11(struct StateT * v739);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v755) {
  int v756 = v755->timer;
  int v767 = v756 + 1;
  v755->timer = v767;
  int * v758 = v755->reg_ready;
  int v759 = v758[11];
  int * v760 = v755->regs;
  int v761 = v760[11];
  int v771 = (v759 + ((v756 - v759) & (~((v756 - v759) >> 31)))) + 1;
  v758[11] = v771;
  int * v763 = v755->regs;
  int v773 = v761 + 4;
  v763[11] = v773;
  struct StateT * v765 = slot_13(v755);
  return v765;
}

struct StateT * slot_14(struct StateT * v792) {
  int v793 = v792->timer;
  int v804 = v793 + 1;
  v792->timer = v804;
  int * v795 = v792->reg_ready;
  int v796 = v795[10];
  int * v797 = v792->regs;
  int v798 = v797[10];
  int v808 = (v796 + ((v793 - v796) & (~((v793 - v796) >> 31)))) + 1;
  v795[10] = v808;
  int * v800 = v792->regs;
  int v810 = v798 << 29;
  v800[10] = v810;
  struct StateT * v802 = slot_15(v792);
  return v802;
}

struct StateT * slot_16(struct StateT * v834) {
  int v835 = v834->timer;
  int v848 = v835 + 1;
  v834->timer = v848;
  int * v837 = v834->reg_ready;
  int v838 = v837[11];
  int * v839 = v834->regs;
  int v840 = v839[11];
  int v841 = v837[10];
  int v842 = v839[10];
  int v853 = (v841 + (((v838 + ((v835 - v838) & (~((v835 - v838) >> 31)))) - v841) & (~(((v838 + ((v835 - v838) & (~((v835 - v838) >> 31)))) - v841) >> 31)))) + 1;
  v837[10] = v853;
  int * v844 = v834->regs;
  int v855 = v840 + v842;
  v844[10] = v855;
  struct StateT * v846 = slot_17(v834);
  return v846;
}

struct StateT * slot_5(struct StateT * v450) {
  int v451 = v450->timer;
  int v462 = v451 + 1;
  v450->timer = v462;
  int * v453 = v450->reg_ready;
  int v454 = v453[10];
  int * v455 = v450->regs;
  int v456 = v455[10];
  int v466 = (v454 + ((v451 - v454) & (~((v451 - v454) >> 31)))) + 1;
  v453[10] = v466;
  int * v458 = v450->regs;
  int v468 = v456 << 2;
  v458[10] = v468;
  struct StateT * v460 = slot_7(v450);
  return v460;
}

struct StateT * slot_17(struct StateT * v858) {
  int v859 = v858->timer;
  int v971 = v859 + 1;
  v858->timer = v971;
  int * v861 = v858->reg_ready;
  int v862 = v861[10];
  int * v863 = v858->regs;
  int v864 = v863[10];
  int * v865 = v858->cache_tags;
  int v976 = (((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2;
  int v866 = v865[v976];
  int v977 = ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + 1;
  int v867 = v865[v977];
  int v978 = 4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2);
  int v868 = v865[v978];
  int v979 = (4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v869 = v865[v979];
  int * v870 = v858->cache_vals;
  bool v980 = !(((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) == 0);
  int v963;
  if (v980) {
    int * v871 = v858->cache_age;
    int v982 = ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) & 1);
    int v872 = v871[v982];
    int v873 = v871[v976];
    int v983 = v873 + ((int)((unsigned int)(v873 - v872) >> 31));
    v871[v976] = v983;
    int * v875 = v858->cache_age;
    int v876 = v875[v977];
    int v985 = v876 + ((int)((unsigned int)(v876 - v872) >> 31));
    v875[v977] = v985;
    int * v878 = v858->cache_age;
    v878[v982] = 0;
    v963 = v982;
  } else {
    int * v881 = v858->cache_age;
    int v989 = (((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2;
    int v882 = v881[v989];
    int * v883 = v858->cache_tags;
    int v884 = v883[v989];
    int v885 = v881[v977];
    int v886 = v883[v977];
    bool v991 = !(((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) == 0);
    int v940;
    if (v991) {
      int * v887 = v858->cache_age;
      int v993 = (4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) & 1);
      int v888 = v887[v993];
      int v889 = v887[v978];
      int v994 = v889 + ((int)((unsigned int)(v889 - v888) >> 31));
      v887[v978] = v994;
      int * v891 = v858->cache_age;
      int v892 = v891[v979];
      int v996 = v892 + ((int)((unsigned int)(v892 - v888) >> 31));
      v891[v979] = v996;
      int * v894 = v858->cache_age;
      v894[v993] = 0;
      v940 = v993;
    } else {
      int * v897 = v858->cache_age;
      int v1000 = 4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2);
      int v898 = v897[v1000];
      int * v899 = v858->cache_tags;
      int v900 = v899[v1000];
      int v901 = v897[v979];
      int v902 = v899[v979];
      int * v903 = v858->cache_dirty;
      int v1003 = (4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v904 = v903[v1003];
      bool v1004 = !(v904 == 0);
      if (v1004) {
        int * v905 = v858->cache_tags;
        int v906 = v905[v1003];
        int * v907 = v858->cache_vals;
        int v1007 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v908 = v907[v1007];
        int v1008 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v909 = v907[v1008];
        int * v910 = v858->mem;
        int v1010 = v906 * 2;
        v910[v1010] = v908;
        int * v912 = v858->mem;
        int v1013 = (v906 * 2) + 1;
        v912[v1013] = v909;
        ;
      } else {
        ;
      }
      int * v917 = v858->mem;
      int v1018 = ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) * 2;
      int v918 = v917[v1018];
      int v1019 = (((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) * 2) + 1;
      int v919 = v917[v1019];
      int * v920 = v858->cache_vals;
      int v1021 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v920[v1021] = v918;
      int * v922 = v858->cache_vals;
      int v1024 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 3) * 2)) + ((((v898 + ((~(((v900 ^ -1) | (-(v900 ^ -1))) >> 31)) & 2)) - (v901 + ((~(((v902 ^ -1) | (-(v902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v922[v1024] = v919;
      int * v924 = v858->cache_tags;
      int v1027 = (int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1);
      v924[v1003] = v1027;
      int * v926 = v858->cache_dirty;
      v926[v1003] = 0;
      int * v928 = v858->cache_age;
      v928[v1003] = 1;
      int * v930 = v858->cache_age;
      int v931 = v930[v1003];
      int v932 = v930[v978];
      int v1033 = v932 + ((int)((unsigned int)(v932 - v931) >> 31));
      v930[v978] = v1033;
      int * v934 = v858->cache_age;
      int v935 = v934[v979];
      int v1035 = v935 + ((int)((unsigned int)(v935 - v931) >> 31));
      v934[v979] = v1035;
      int * v937 = v858->cache_age;
      v937[v1003] = 0;
      v940 = v1003;
    }
    int * v941 = v858->cache_vals;
    int v1038 = v940 * 2;
    int v942 = v941[v1038];
    int v1039 = (v940 * 2) + 1;
    int v943 = v941[v1039];
    int v1040 = (((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v941[v1040] = v942;
    int * v945 = v858->cache_vals;
    int v1043 = ((((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v945[v1043] = v943;
    int * v947 = v858->cache_tags;
    int v1046 = ((((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1)) & 1) * 2) + ((((v882 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2)) - (v885 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1047 = (int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1);
    v947[v1046] = v1047;
    int * v949 = v858->cache_dirty;
    v949[v1046] = 0;
    int * v951 = v858->cache_age;
    v951[v1046] = 1;
    int * v953 = v858->cache_age;
    int v954 = v953[v1046];
    int v955 = v953[v976];
    int v1053 = v955 + ((int)((unsigned int)(v955 - v954) >> 31));
    v953[v976] = v1053;
    int * v957 = v858->cache_age;
    int v958 = v957[v977];
    int v1055 = v958 + ((int)((unsigned int)(v958 - v954) >> 31));
    v957[v977] = v1055;
    int * v960 = v858->cache_age;
    v960[v1046] = 0;
    v963 = v1046;
  }
  int v1058 = (v963 * 2) + (((int)((unsigned int)v864 >> 2)) & 1);
  int v964 = v870[v1058];
  int * v965 = v858->reg_ready;
  int v1060 = ((v862 + ((v859 - v862) & (~((v859 - v862) >> 31)))) + 1) + ((100 ^ (((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31)) | (~(((v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))) | (-(v869 ^ ((int)((unsigned int)((int)((unsigned int)v864 >> 2)) >> 1))))) >> 31))) & 104)))));
  v965[10] = v1060;
  int * v967 = v858->regs;
  v967[10] = v964;
  struct StateT * v969 = slot_18(v858);
  return v969;
}

struct StateT * slot_20(struct StateT * v1297) {
  int v1298 = v1297->timer;
  int v1471 = v1298 + 1;
  v1297->timer = v1471;
  int * v1300 = v1297->reg_ready;
  int * v1302 = v1297->regs;
  int v1303 = v1302[12];
  int v1305 = v1302[10];
  int * v1306 = v1297->cache_tags;
  int v1477 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1307 = v1306[v1477];
  int v1478 = ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1308 = v1306[v1478];
  int v1479 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1309 = v1306[v1479];
  int v1480 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1310 = v1306[v1480];
  int v1311 = v1297->timer;
  int v1481 = v1311 + ((100 ^ (((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1297->timer = v1481;
  bool v1482 = !(((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1405;
  if (v1482) {
    int * v1313 = v1297->cache_age;
    int v1484 = ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1314 = v1313[v1484];
    int v1315 = v1313[v1477];
    int v1485 = v1315 + ((int)((unsigned int)(v1315 - v1314) >> 31));
    v1313[v1477] = v1485;
    int * v1317 = v1297->cache_age;
    int v1318 = v1317[v1478];
    int v1487 = v1318 + ((int)((unsigned int)(v1318 - v1314) >> 31));
    v1317[v1478] = v1487;
    int * v1320 = v1297->cache_age;
    v1320[v1484] = 0;
    v1405 = v1484;
  } else {
    int * v1323 = v1297->cache_age;
    int v1491 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1324 = v1323[v1491];
    int * v1325 = v1297->cache_tags;
    int v1326 = v1325[v1491];
    int v1327 = v1323[v1478];
    int v1328 = v1325[v1478];
    bool v1493 = !(((~(((v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1309 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1382;
    if (v1493) {
      int * v1329 = v1297->cache_age;
      int v1495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1310 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1330 = v1329[v1495];
      int v1331 = v1329[v1479];
      int v1496 = v1331 + ((int)((unsigned int)(v1331 - v1330) >> 31));
      v1329[v1479] = v1496;
      int * v1333 = v1297->cache_age;
      int v1334 = v1333[v1480];
      int v1498 = v1334 + ((int)((unsigned int)(v1334 - v1330) >> 31));
      v1333[v1480] = v1498;
      int * v1336 = v1297->cache_age;
      v1336[v1495] = 0;
      v1382 = v1495;
    } else {
      int * v1339 = v1297->cache_age;
      int v1502 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1340 = v1339[v1502];
      int * v1341 = v1297->cache_tags;
      int v1342 = v1341[v1502];
      int v1343 = v1339[v1480];
      int v1344 = v1341[v1480];
      int * v1345 = v1297->cache_dirty;
      int v1505 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1346 = v1345[v1505];
      bool v1506 = !(v1346 == 0);
      if (v1506) {
        int * v1347 = v1297->cache_tags;
        int v1348 = v1347[v1505];
        int * v1349 = v1297->cache_vals;
        int v1509 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1350 = v1349[v1509];
        int v1510 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1351 = v1349[v1510];
        int * v1352 = v1297->mem;
        int v1512 = v1348 * 2;
        v1352[v1512] = v1350;
        int * v1354 = v1297->mem;
        int v1515 = (v1348 * 2) + 1;
        v1354[v1515] = v1351;
        ;
      } else {
        ;
      }
      int * v1359 = v1297->mem;
      int v1520 = ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2;
      int v1360 = v1359[v1520];
      int v1521 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1361 = v1359[v1521];
      int * v1362 = v1297->cache_vals;
      int v1523 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1362[v1523] = v1360;
      int * v1364 = v1297->cache_vals;
      int v1526 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1340 + ((~(((v1342 ^ -1) | (-(v1342 ^ -1))) >> 31)) & 2)) - (v1343 + ((~(((v1344 ^ -1) | (-(v1344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1364[v1526] = v1361;
      int * v1366 = v1297->cache_tags;
      int v1529 = (int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1);
      v1366[v1505] = v1529;
      int * v1368 = v1297->cache_dirty;
      v1368[v1505] = 0;
      int * v1370 = v1297->cache_age;
      v1370[v1505] = 1;
      int * v1372 = v1297->cache_age;
      int v1373 = v1372[v1505];
      int v1374 = v1372[v1479];
      int v1535 = v1374 + ((int)((unsigned int)(v1374 - v1373) >> 31));
      v1372[v1479] = v1535;
      int * v1376 = v1297->cache_age;
      int v1377 = v1376[v1480];
      int v1537 = v1377 + ((int)((unsigned int)(v1377 - v1373) >> 31));
      v1376[v1480] = v1537;
      int * v1379 = v1297->cache_age;
      v1379[v1505] = 0;
      v1382 = v1505;
    }
    int * v1383 = v1297->cache_vals;
    int v1540 = v1382 * 2;
    int v1384 = v1383[v1540];
    int v1541 = (v1382 * 2) + 1;
    int v1385 = v1383[v1541];
    int v1542 = (((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1383[v1542] = v1384;
    int * v1387 = v1297->cache_vals;
    int v1545 = ((((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1387[v1545] = v1385;
    int * v1389 = v1297->cache_tags;
    int v1548 = ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1549 = (int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1);
    v1389[v1548] = v1549;
    int * v1391 = v1297->cache_dirty;
    v1391[v1548] = 0;
    int * v1393 = v1297->cache_age;
    v1393[v1548] = 1;
    int * v1395 = v1297->cache_age;
    int v1396 = v1395[v1548];
    int v1397 = v1395[v1477];
    int v1555 = v1397 + ((int)((unsigned int)(v1397 - v1396) >> 31));
    v1395[v1477] = v1555;
    int * v1399 = v1297->cache_age;
    int v1400 = v1399[v1478];
    int v1557 = v1400 + ((int)((unsigned int)(v1400 - v1396) >> 31));
    v1399[v1478] = v1557;
    int * v1402 = v1297->cache_age;
    v1402[v1548] = 0;
    v1405 = v1548;
  }
  int * v1406 = v1297->cache_vals;
  int v1560 = (v1405 * 2) + (((int)((unsigned int)(v1303 + 68) >> 2)) & 1);
  v1406[v1560] = v1305;
  int * v1408 = v1297->cache_tags;
  int v1409 = v1408[v1479];
  int v1410 = v1408[v1480];
  bool v1563 = !(((~(((v1409 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1409 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1464;
  if (v1563) {
    int * v1411 = v1297->cache_age;
    int v1565 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))) | (-(v1410 ^ ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1412 = v1411[v1565];
    int v1413 = v1411[v1479];
    int v1566 = v1413 + ((int)((unsigned int)(v1413 - v1412) >> 31));
    v1411[v1479] = v1566;
    int * v1415 = v1297->cache_age;
    int v1416 = v1415[v1480];
    int v1568 = v1416 + ((int)((unsigned int)(v1416 - v1412) >> 31));
    v1415[v1480] = v1568;
    int * v1418 = v1297->cache_age;
    v1418[v1565] = 0;
    v1464 = v1565;
  } else {
    int * v1421 = v1297->cache_age;
    int v1572 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1422 = v1421[v1572];
    int * v1423 = v1297->cache_tags;
    int v1424 = v1423[v1572];
    int v1425 = v1421[v1480];
    int v1426 = v1423[v1480];
    int * v1427 = v1297->cache_dirty;
    int v1575 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1428 = v1427[v1575];
    bool v1576 = !(v1428 == 0);
    if (v1576) {
      int * v1429 = v1297->cache_tags;
      int v1430 = v1429[v1575];
      int * v1431 = v1297->cache_vals;
      int v1579 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1432 = v1431[v1579];
      int v1580 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1433 = v1431[v1580];
      int * v1434 = v1297->mem;
      int v1582 = v1430 * 2;
      v1434[v1582] = v1432;
      int * v1436 = v1297->mem;
      int v1585 = (v1430 * 2) + 1;
      v1436[v1585] = v1433;
      ;
    } else {
      ;
    }
    int * v1441 = v1297->mem;
    int v1590 = ((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2;
    int v1442 = v1441[v1590];
    int v1591 = (((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1443 = v1441[v1591];
    int * v1444 = v1297->cache_vals;
    int v1593 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1444[v1593] = v1442;
    int * v1446 = v1297->cache_vals;
    int v1596 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1422 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2)) - (v1425 + ((~(((v1426 ^ -1) | (-(v1426 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1446[v1596] = v1443;
    int * v1448 = v1297->cache_tags;
    int v1599 = (int)((unsigned int)((int)((unsigned int)(v1303 + 68) >> 2)) >> 1);
    v1448[v1575] = v1599;
    int * v1450 = v1297->cache_dirty;
    v1450[v1575] = 0;
    int * v1452 = v1297->cache_age;
    v1452[v1575] = 1;
    int * v1454 = v1297->cache_age;
    int v1455 = v1454[v1575];
    int v1456 = v1454[v1479];
    int v1605 = v1456 + ((int)((unsigned int)(v1456 - v1455) >> 31));
    v1454[v1479] = v1605;
    int * v1458 = v1297->cache_age;
    int v1459 = v1458[v1480];
    int v1607 = v1459 + ((int)((unsigned int)(v1459 - v1455) >> 31));
    v1458[v1480] = v1607;
    int * v1461 = v1297->cache_age;
    v1461[v1575] = 0;
    v1464 = v1575;
  }
  int * v1465 = v1297->cache_vals;
  int v1610 = (v1464 * 2) + (((int)((unsigned int)(v1303 + 68) >> 2)) & 1);
  v1465[v1610] = v1305;
  int * v1467 = v1297->cache_dirty;
  v1467[v1464] = 1;
  struct StateT * v1469 = slot_21(v1297);
  return v1469;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v471) {
  int v472 = v471->timer;
  int v480 = v472 + 1;
  v471->timer = v480;
  int * v474 = v471->reg_ready;
  v474[11] = v480;
  int * v476 = v471->regs;
  v476[11] = 0;
  struct StateT * v478 = slot_8(v471);
  return v478;
}

struct StateT * slot_21(struct StateT * v1616) {
  int v1617 = v1616->timer;
  int v1620 = v1617 + 1;
  v1616->timer = v1620;
  return v1616;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->regs;
  int v235 = v234[10];
  int v236 = v234[11];
  bool v344 = (v235 ^ -2147483648) >= (v236 ^ -2147483648);
  struct StateT * v339;
  if (v344) {
    int v237 = v233->timer;
    int v345 = v237 + 15;
    v233->timer = v345;
    int * v239 = v233->reg_ready;
    int v240 = v233->timer;
    v239[0] = v240;
    int * v242 = v233->reg_ready;
    int v243 = v233->timer;
    v242[1] = v243;
    int * v245 = v233->reg_ready;
    int v246 = v233->timer;
    v245[2] = v246;
    int * v248 = v233->reg_ready;
    int v249 = v233->timer;
    v248[3] = v249;
    int * v251 = v233->reg_ready;
    int v252 = v233->timer;
    v251[4] = v252;
    int * v254 = v233->reg_ready;
    int v255 = v233->timer;
    v254[5] = v255;
    int * v257 = v233->reg_ready;
    int v258 = v233->timer;
    v257[6] = v258;
    int * v260 = v233->reg_ready;
    int v261 = v233->timer;
    v260[7] = v261;
    int * v263 = v233->reg_ready;
    int v264 = v233->timer;
    v263[8] = v264;
    int * v266 = v233->reg_ready;
    int v267 = v233->timer;
    v266[9] = v267;
    int * v269 = v233->reg_ready;
    int v270 = v233->timer;
    v269[10] = v270;
    int * v272 = v233->reg_ready;
    int v273 = v233->timer;
    v272[11] = v273;
    int * v275 = v233->reg_ready;
    int v276 = v233->timer;
    v275[12] = v276;
    int * v278 = v233->reg_ready;
    int v279 = v233->timer;
    v278[13] = v279;
    int * v281 = v233->reg_ready;
    int v282 = v233->timer;
    v281[14] = v282;
    int * v284 = v233->reg_ready;
    int v285 = v233->timer;
    v284[15] = v285;
    int * v287 = v233->reg_ready;
    int v288 = v233->timer;
    v287[16] = v288;
    int * v290 = v233->reg_ready;
    int v291 = v233->timer;
    v290[17] = v291;
    int * v293 = v233->reg_ready;
    int v294 = v233->timer;
    v293[18] = v294;
    int * v296 = v233->reg_ready;
    int v297 = v233->timer;
    v296[19] = v297;
    int * v299 = v233->reg_ready;
    int v300 = v233->timer;
    v299[20] = v300;
    int * v302 = v233->reg_ready;
    int v303 = v233->timer;
    v302[21] = v303;
    int * v305 = v233->reg_ready;
    int v306 = v233->timer;
    v305[22] = v306;
    int * v308 = v233->reg_ready;
    int v309 = v233->timer;
    v308[23] = v309;
    int * v311 = v233->reg_ready;
    int v312 = v233->timer;
    v311[24] = v312;
    int * v314 = v233->reg_ready;
    int v315 = v233->timer;
    v314[25] = v315;
    int * v317 = v233->reg_ready;
    int v318 = v233->timer;
    v317[26] = v318;
    int * v320 = v233->reg_ready;
    int v321 = v233->timer;
    v320[27] = v321;
    int * v323 = v233->reg_ready;
    int v324 = v233->timer;
    v323[28] = v324;
    int * v326 = v233->reg_ready;
    int v327 = v233->timer;
    v326[29] = v327;
    int * v329 = v233->reg_ready;
    int v330 = v233->timer;
    v329[30] = v330;
    int * v332 = v233->reg_ready;
    int v333 = v233->timer;
    v332[31] = v333;
    struct StateT * v335 = slot_21(v233);
    v339 = v335;
  } else {
    struct StateT * v337 = slot_5(v233);
    v339 = v337;
  }
  return v339;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1621 = v1->timer;
  int * v1622 = v1->reg_ready;
  int v1623 = v1622[0];
  int v1754 = v1623 + ((v1621 - v1623) & (~((v1621 - v1623) >> 31)));
  v1->timer = v1754;
  int v1625 = v1->timer;
  int * v1626 = v1->reg_ready;
  int v1627 = v1626[1];
  int v1757 = v1627 + ((v1625 - v1627) & (~((v1625 - v1627) >> 31)));
  v1->timer = v1757;
  int v1629 = v1->timer;
  int * v1630 = v1->reg_ready;
  int v1631 = v1630[2];
  int v1760 = v1631 + ((v1629 - v1631) & (~((v1629 - v1631) >> 31)));
  v1->timer = v1760;
  int v1633 = v1->timer;
  int * v1634 = v1->reg_ready;
  int v1635 = v1634[3];
  int v1763 = v1635 + ((v1633 - v1635) & (~((v1633 - v1635) >> 31)));
  v1->timer = v1763;
  int v1637 = v1->timer;
  int * v1638 = v1->reg_ready;
  int v1639 = v1638[4];
  int v1766 = v1639 + ((v1637 - v1639) & (~((v1637 - v1639) >> 31)));
  v1->timer = v1766;
  int v1641 = v1->timer;
  int * v1642 = v1->reg_ready;
  int v1643 = v1642[5];
  int v1769 = v1643 + ((v1641 - v1643) & (~((v1641 - v1643) >> 31)));
  v1->timer = v1769;
  int v1645 = v1->timer;
  int * v1646 = v1->reg_ready;
  int v1647 = v1646[6];
  int v1772 = v1647 + ((v1645 - v1647) & (~((v1645 - v1647) >> 31)));
  v1->timer = v1772;
  int v1649 = v1->timer;
  int * v1650 = v1->reg_ready;
  int v1651 = v1650[7];
  int v1775 = v1651 + ((v1649 - v1651) & (~((v1649 - v1651) >> 31)));
  v1->timer = v1775;
  int v1653 = v1->timer;
  int * v1654 = v1->reg_ready;
  int v1655 = v1654[8];
  int v1778 = v1655 + ((v1653 - v1655) & (~((v1653 - v1655) >> 31)));
  v1->timer = v1778;
  int v1657 = v1->timer;
  int * v1658 = v1->reg_ready;
  int v1659 = v1658[9];
  int v1781 = v1659 + ((v1657 - v1659) & (~((v1657 - v1659) >> 31)));
  v1->timer = v1781;
  int v1661 = v1->timer;
  int * v1662 = v1->reg_ready;
  int v1663 = v1662[10];
  int v1784 = v1663 + ((v1661 - v1663) & (~((v1661 - v1663) >> 31)));
  v1->timer = v1784;
  int v1665 = v1->timer;
  int * v1666 = v1->reg_ready;
  int v1667 = v1666[11];
  int v1787 = v1667 + ((v1665 - v1667) & (~((v1665 - v1667) >> 31)));
  v1->timer = v1787;
  int v1669 = v1->timer;
  int * v1670 = v1->reg_ready;
  int v1671 = v1670[12];
  int v1790 = v1671 + ((v1669 - v1671) & (~((v1669 - v1671) >> 31)));
  v1->timer = v1790;
  int v1673 = v1->timer;
  int * v1674 = v1->reg_ready;
  int v1675 = v1674[13];
  int v1793 = v1675 + ((v1673 - v1675) & (~((v1673 - v1675) >> 31)));
  v1->timer = v1793;
  int v1677 = v1->timer;
  int * v1678 = v1->reg_ready;
  int v1679 = v1678[14];
  int v1796 = v1679 + ((v1677 - v1679) & (~((v1677 - v1679) >> 31)));
  v1->timer = v1796;
  int v1681 = v1->timer;
  int * v1682 = v1->reg_ready;
  int v1683 = v1682[15];
  int v1799 = v1683 + ((v1681 - v1683) & (~((v1681 - v1683) >> 31)));
  v1->timer = v1799;
  int v1685 = v1->timer;
  int * v1686 = v1->reg_ready;
  int v1687 = v1686[16];
  int v1802 = v1687 + ((v1685 - v1687) & (~((v1685 - v1687) >> 31)));
  v1->timer = v1802;
  int v1689 = v1->timer;
  int * v1690 = v1->reg_ready;
  int v1691 = v1690[17];
  int v1805 = v1691 + ((v1689 - v1691) & (~((v1689 - v1691) >> 31)));
  v1->timer = v1805;
  int v1693 = v1->timer;
  int * v1694 = v1->reg_ready;
  int v1695 = v1694[18];
  int v1808 = v1695 + ((v1693 - v1695) & (~((v1693 - v1695) >> 31)));
  v1->timer = v1808;
  int v1697 = v1->timer;
  int * v1698 = v1->reg_ready;
  int v1699 = v1698[19];
  int v1811 = v1699 + ((v1697 - v1699) & (~((v1697 - v1699) >> 31)));
  v1->timer = v1811;
  int v1701 = v1->timer;
  int * v1702 = v1->reg_ready;
  int v1703 = v1702[20];
  int v1814 = v1703 + ((v1701 - v1703) & (~((v1701 - v1703) >> 31)));
  v1->timer = v1814;
  int v1705 = v1->timer;
  int * v1706 = v1->reg_ready;
  int v1707 = v1706[21];
  int v1817 = v1707 + ((v1705 - v1707) & (~((v1705 - v1707) >> 31)));
  v1->timer = v1817;
  int v1709 = v1->timer;
  int * v1710 = v1->reg_ready;
  int v1711 = v1710[22];
  int v1820 = v1711 + ((v1709 - v1711) & (~((v1709 - v1711) >> 31)));
  v1->timer = v1820;
  int v1713 = v1->timer;
  int * v1714 = v1->reg_ready;
  int v1715 = v1714[23];
  int v1823 = v1715 + ((v1713 - v1715) & (~((v1713 - v1715) >> 31)));
  v1->timer = v1823;
  int v1717 = v1->timer;
  int * v1718 = v1->reg_ready;
  int v1719 = v1718[24];
  int v1826 = v1719 + ((v1717 - v1719) & (~((v1717 - v1719) >> 31)));
  v1->timer = v1826;
  int v1721 = v1->timer;
  int * v1722 = v1->reg_ready;
  int v1723 = v1722[25];
  int v1829 = v1723 + ((v1721 - v1723) & (~((v1721 - v1723) >> 31)));
  v1->timer = v1829;
  int v1725 = v1->timer;
  int * v1726 = v1->reg_ready;
  int v1727 = v1726[26];
  int v1832 = v1727 + ((v1725 - v1727) & (~((v1725 - v1727) >> 31)));
  v1->timer = v1832;
  int v1729 = v1->timer;
  int * v1730 = v1->reg_ready;
  int v1731 = v1730[27];
  int v1835 = v1731 + ((v1729 - v1731) & (~((v1729 - v1731) >> 31)));
  v1->timer = v1835;
  int v1733 = v1->timer;
  int * v1734 = v1->reg_ready;
  int v1735 = v1734[28];
  int v1838 = v1735 + ((v1733 - v1735) & (~((v1733 - v1735) >> 31)));
  v1->timer = v1838;
  int v1737 = v1->timer;
  int * v1738 = v1->reg_ready;
  int v1739 = v1738[29];
  int v1841 = v1739 + ((v1737 - v1739) & (~((v1737 - v1739) >> 31)));
  v1->timer = v1841;
  int v1741 = v1->timer;
  int * v1742 = v1->reg_ready;
  int v1743 = v1742[30];
  int v1844 = v1743 + ((v1741 - v1743) & (~((v1741 - v1743) >> 31)));
  v1->timer = v1844;
  int v1745 = v1->timer;
  int * v1746 = v1->reg_ready;
  int v1747 = v1746[31];
  int v1847 = v1747 + ((v1745 - v1747) & (~((v1745 - v1747) >> 31)));
  v1->timer = v1847;
  return v1;
}

struct StateT * slot_10(struct StateT * v532) {
  int v533 = v532->timer;
  int v645 = v533 + 1;
  v532->timer = v645;
  int * v535 = v532->reg_ready;
  int v536 = v535[10];
  int * v537 = v532->regs;
  int v538 = v537[10];
  int * v539 = v532->cache_tags;
  int v650 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2;
  int v540 = v539[v650];
  int v651 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + 1;
  int v541 = v539[v651];
  int v652 = 4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2);
  int v542 = v539[v652];
  int v653 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v543 = v539[v653];
  int * v544 = v532->cache_vals;
  bool v654 = !(((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) == 0);
  int v637;
  if (v654) {
    int * v545 = v532->cache_age;
    int v656 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) & 1);
    int v546 = v545[v656];
    int v547 = v545[v650];
    int v657 = v547 + ((int)((unsigned int)(v547 - v546) >> 31));
    v545[v650] = v657;
    int * v549 = v532->cache_age;
    int v550 = v549[v651];
    int v659 = v550 + ((int)((unsigned int)(v550 - v546) >> 31));
    v549[v651] = v659;
    int * v552 = v532->cache_age;
    v552[v656] = 0;
    v637 = v656;
  } else {
    int * v555 = v532->cache_age;
    int v663 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2;
    int v556 = v555[v663];
    int * v557 = v532->cache_tags;
    int v558 = v557[v663];
    int v559 = v555[v651];
    int v560 = v557[v651];
    bool v665 = !(((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) == 0);
    int v614;
    if (v665) {
      int * v561 = v532->cache_age;
      int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) & 1);
      int v562 = v561[v667];
      int v563 = v561[v652];
      int v668 = v563 + ((int)((unsigned int)(v563 - v562) >> 31));
      v561[v652] = v668;
      int * v565 = v532->cache_age;
      int v566 = v565[v653];
      int v670 = v566 + ((int)((unsigned int)(v566 - v562) >> 31));
      v565[v653] = v670;
      int * v568 = v532->cache_age;
      v568[v667] = 0;
      v614 = v667;
    } else {
      int * v571 = v532->cache_age;
      int v674 = 4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2);
      int v572 = v571[v674];
      int * v573 = v532->cache_tags;
      int v574 = v573[v674];
      int v575 = v571[v653];
      int v576 = v573[v653];
      int * v577 = v532->cache_dirty;
      int v677 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v578 = v577[v677];
      bool v678 = !(v578 == 0);
      if (v678) {
        int * v579 = v532->cache_tags;
        int v580 = v579[v677];
        int * v581 = v532->cache_vals;
        int v681 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v582 = v581[v681];
        int v682 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v583 = v581[v682];
        int * v584 = v532->mem;
        int v684 = v580 * 2;
        v584[v684] = v582;
        int * v586 = v532->mem;
        int v687 = (v580 * 2) + 1;
        v586[v687] = v583;
        ;
      } else {
        ;
      }
      int * v591 = v532->mem;
      int v692 = ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) * 2;
      int v592 = v591[v692];
      int v693 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) * 2) + 1;
      int v593 = v591[v693];
      int * v594 = v532->cache_vals;
      int v695 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v594[v695] = v592;
      int * v596 = v532->cache_vals;
      int v698 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v572 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2)) - (v575 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v596[v698] = v593;
      int * v598 = v532->cache_tags;
      int v701 = (int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1);
      v598[v677] = v701;
      int * v600 = v532->cache_dirty;
      v600[v677] = 0;
      int * v602 = v532->cache_age;
      v602[v677] = 1;
      int * v604 = v532->cache_age;
      int v605 = v604[v677];
      int v606 = v604[v652];
      int v707 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
      v604[v652] = v707;
      int * v608 = v532->cache_age;
      int v609 = v608[v653];
      int v709 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
      v608[v653] = v709;
      int * v611 = v532->cache_age;
      v611[v677] = 0;
      v614 = v677;
    }
    int * v615 = v532->cache_vals;
    int v712 = v614 * 2;
    int v616 = v615[v712];
    int v713 = (v614 * 2) + 1;
    int v617 = v615[v713];
    int v714 = (((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2)) - (v559 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v615[v714] = v616;
    int * v619 = v532->cache_vals;
    int v717 = ((((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2)) - (v559 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v619[v717] = v617;
    int * v621 = v532->cache_tags;
    int v720 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v556 + ((~(((v558 ^ -1) | (-(v558 ^ -1))) >> 31)) & 2)) - (v559 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v721 = (int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1);
    v621[v720] = v721;
    int * v623 = v532->cache_dirty;
    v623[v720] = 0;
    int * v625 = v532->cache_age;
    v625[v720] = 1;
    int * v627 = v532->cache_age;
    int v628 = v627[v720];
    int v629 = v627[v650];
    int v727 = v629 + ((int)((unsigned int)(v629 - v628) >> 31));
    v627[v650] = v727;
    int * v631 = v532->cache_age;
    int v632 = v631[v651];
    int v729 = v632 + ((int)((unsigned int)(v632 - v628) >> 31));
    v631[v651] = v729;
    int * v634 = v532->cache_age;
    v634[v720] = 0;
    v637 = v720;
  }
  int v732 = (v637 * 2) + (((int)((unsigned int)v538 >> 2)) & 1);
  int v638 = v544[v732];
  int * v639 = v532->reg_ready;
  int v734 = ((v536 + ((v533 - v536) & (~((v533 - v536) >> 31)))) + 1) + ((100 ^ (((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & 104)))));
  v639[10] = v734;
  int * v641 = v532->regs;
  v641[10] = v638;
  struct StateT * v643 = slot_11(v532);
  return v643;
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

struct StateT * slot_8(struct StateT * v487) {
  int v488 = v487->timer;
  int v499 = v488 + 1;
  v487->timer = v499;
  int * v490 = v487->reg_ready;
  int v491 = v490[11];
  int * v492 = v487->regs;
  int v493 = v492[11];
  int v503 = (v491 + ((v488 - v491) & (~((v488 - v491) >> 31)))) + 1;
  v490[11] = v503;
  int * v495 = v487->regs;
  int v505 = v493 + 72;
  v495[11] = v505;
  struct StateT * v497 = slot_9(v487);
  return v497;
}

struct StateT * slot_19(struct StateT * v1273) {
  int v1274 = v1273->timer;
  int v1287 = v1274 + 1;
  v1273->timer = v1287;
  int * v1276 = v1273->reg_ready;
  int v1277 = v1276[11];
  int * v1278 = v1273->regs;
  int v1279 = v1278[11];
  int v1280 = v1276[10];
  int v1281 = v1278[10];
  int v1292 = (v1280 + (((v1277 + ((v1274 - v1277) & (~((v1274 - v1277) >> 31)))) - v1280) & (~(((v1277 + ((v1274 - v1277) & (~((v1274 - v1277) >> 31)))) - v1280) >> 31)))) + 1;
  v1276[10] = v1292;
  int * v1283 = v1273->regs;
  int v1294 = v1279 & v1281;
  v1283[10] = v1294;
  struct StateT * v1285 = slot_20(v1273);
  return v1285;
}

struct StateT * slot_13(struct StateT * v776) {
  int v777 = v776->timer;
  int v785 = v777 + 1;
  v776->timer = v785;
  int * v779 = v776->reg_ready;
  v779[12] = v785;
  int * v781 = v776->regs;
  v781[12] = 0;
  struct StateT * v783 = slot_14(v776);
  return v783;
}

struct StateT * slot_15(struct StateT * v813) {
  int v814 = v813->timer;
  int v825 = v814 + 1;
  v813->timer = v825;
  int * v816 = v813->reg_ready;
  int v817 = v816[10];
  int * v818 = v813->regs;
  int v819 = v818[10];
  int v829 = (v817 + ((v814 - v817) & (~((v814 - v817) >> 31)))) + 1;
  v816[10] = v829;
  int * v821 = v813->regs;
  int v831 = (int)((unsigned int)v819 >> 26);
  v821[10] = v831;
  struct StateT * v823 = slot_16(v813);
  return v823;
}

struct StateT * slot_18(struct StateT * v1065) {
  int v1066 = v1065->timer;
  int v1178 = v1066 + 1;
  v1065->timer = v1178;
  int * v1068 = v1065->reg_ready;
  int v1069 = v1068[12];
  int * v1070 = v1065->regs;
  int v1071 = v1070[12];
  int * v1072 = v1065->cache_tags;
  int v1183 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1073 = v1072[v1183];
  int v1184 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1074 = v1072[v1184];
  int v1185 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1075 = v1072[v1185];
  int v1186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1076 = v1072[v1186];
  int * v1077 = v1065->cache_vals;
  bool v1187 = !(((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1170;
  if (v1187) {
    int * v1078 = v1065->cache_age;
    int v1189 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1079 = v1078[v1189];
    int v1080 = v1078[v1183];
    int v1190 = v1080 + ((int)((unsigned int)(v1080 - v1079) >> 31));
    v1078[v1183] = v1190;
    int * v1082 = v1065->cache_age;
    int v1083 = v1082[v1184];
    int v1192 = v1083 + ((int)((unsigned int)(v1083 - v1079) >> 31));
    v1082[v1184] = v1192;
    int * v1085 = v1065->cache_age;
    v1085[v1189] = 0;
    v1170 = v1189;
  } else {
    int * v1088 = v1065->cache_age;
    int v1196 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1089 = v1088[v1196];
    int * v1090 = v1065->cache_tags;
    int v1091 = v1090[v1196];
    int v1092 = v1088[v1184];
    int v1093 = v1090[v1184];
    bool v1198 = !(((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1147;
    if (v1198) {
      int * v1094 = v1065->cache_age;
      int v1200 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1095 = v1094[v1200];
      int v1096 = v1094[v1185];
      int v1201 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
      v1094[v1185] = v1201;
      int * v1098 = v1065->cache_age;
      int v1099 = v1098[v1186];
      int v1203 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
      v1098[v1186] = v1203;
      int * v1101 = v1065->cache_age;
      v1101[v1200] = 0;
      v1147 = v1200;
    } else {
      int * v1104 = v1065->cache_age;
      int v1207 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1105 = v1104[v1207];
      int * v1106 = v1065->cache_tags;
      int v1107 = v1106[v1207];
      int v1108 = v1104[v1186];
      int v1109 = v1106[v1186];
      int * v1110 = v1065->cache_dirty;
      int v1210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1111 = v1110[v1210];
      bool v1211 = !(v1111 == 0);
      if (v1211) {
        int * v1112 = v1065->cache_tags;
        int v1113 = v1112[v1210];
        int * v1114 = v1065->cache_vals;
        int v1214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1115 = v1114[v1214];
        int v1215 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1116 = v1114[v1215];
        int * v1117 = v1065->mem;
        int v1217 = v1113 * 2;
        v1117[v1217] = v1115;
        int * v1119 = v1065->mem;
        int v1220 = (v1113 * 2) + 1;
        v1119[v1220] = v1116;
        ;
      } else {
        ;
      }
      int * v1124 = v1065->mem;
      int v1225 = ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2;
      int v1125 = v1124[v1225];
      int v1226 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1126 = v1124[v1226];
      int * v1127 = v1065->cache_vals;
      int v1228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1127[v1228] = v1125;
      int * v1129 = v1065->cache_vals;
      int v1231 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1129[v1231] = v1126;
      int * v1131 = v1065->cache_tags;
      int v1234 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
      v1131[v1210] = v1234;
      int * v1133 = v1065->cache_dirty;
      v1133[v1210] = 0;
      int * v1135 = v1065->cache_age;
      v1135[v1210] = 1;
      int * v1137 = v1065->cache_age;
      int v1138 = v1137[v1210];
      int v1139 = v1137[v1185];
      int v1240 = v1139 + ((int)((unsigned int)(v1139 - v1138) >> 31));
      v1137[v1185] = v1240;
      int * v1141 = v1065->cache_age;
      int v1142 = v1141[v1186];
      int v1242 = v1142 + ((int)((unsigned int)(v1142 - v1138) >> 31));
      v1141[v1186] = v1242;
      int * v1144 = v1065->cache_age;
      v1144[v1210] = 0;
      v1147 = v1210;
    }
    int * v1148 = v1065->cache_vals;
    int v1245 = v1147 * 2;
    int v1149 = v1148[v1245];
    int v1246 = (v1147 * 2) + 1;
    int v1150 = v1148[v1246];
    int v1247 = (((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1148[v1247] = v1149;
    int * v1152 = v1065->cache_vals;
    int v1250 = ((((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1152[v1250] = v1150;
    int * v1154 = v1065->cache_tags;
    int v1253 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1089 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2)) - (v1092 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1254 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
    v1154[v1253] = v1254;
    int * v1156 = v1065->cache_dirty;
    v1156[v1253] = 0;
    int * v1158 = v1065->cache_age;
    v1158[v1253] = 1;
    int * v1160 = v1065->cache_age;
    int v1161 = v1160[v1253];
    int v1162 = v1160[v1183];
    int v1260 = v1162 + ((int)((unsigned int)(v1162 - v1161) >> 31));
    v1160[v1183] = v1260;
    int * v1164 = v1065->cache_age;
    int v1165 = v1164[v1184];
    int v1262 = v1165 + ((int)((unsigned int)(v1165 - v1161) >> 31));
    v1164[v1184] = v1262;
    int * v1167 = v1065->cache_age;
    v1167[v1253] = 0;
    v1170 = v1253;
  }
  int v1265 = (v1170 * 2) + (((int)((unsigned int)(v1071 + 68) >> 2)) & 1);
  int v1171 = v1077[v1265];
  int * v1172 = v1065->reg_ready;
  int v1268 = ((v1069 + ((v1066 - v1069) & (~((v1066 - v1069) >> 31)))) + 1) + ((100 ^ (((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1073 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1172[11] = v1268;
  int * v1174 = v1065->regs;
  v1174[11] = v1171;
  struct StateT * v1176 = slot_19(v1065);
  return v1176;
}

struct StateT * slot_9(struct StateT * v508) {
  int v509 = v508->timer;
  int v522 = v509 + 1;
  v508->timer = v522;
  int * v511 = v508->reg_ready;
  int v512 = v511[11];
  int * v513 = v508->regs;
  int v514 = v513[11];
  int v515 = v511[10];
  int v516 = v513[10];
  int v527 = (v515 + (((v512 + ((v509 - v512) & (~((v509 - v512) >> 31)))) - v515) & (~(((v512 + ((v509 - v512) & (~((v509 - v512) >> 31)))) - v515) >> 31)))) + 1;
  v511[10] = v527;
  int * v518 = v508->regs;
  int v529 = v514 + v516;
  v518[10] = v529;
  struct StateT * v520 = slot_10(v508);
  return v520;
}

struct StateT * slot_11(struct StateT * v739) {
  int v740 = v739->timer;
  int v748 = v740 + 1;
  v739->timer = v748;
  int * v742 = v739->reg_ready;
  v742[11] = v748;
  int * v744 = v739->regs;
  v744[11] = 0;
  struct StateT * v746 = slot_12(v739);
  return v746;
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