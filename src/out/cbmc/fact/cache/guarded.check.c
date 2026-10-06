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

struct StateT * slot_12(struct StateT * v1304);
struct StateT * slot_14(struct StateT * v488);
struct StateT * slot_6(struct StateT * v502);
struct StateT * slot_16(struct StateT * v737);
struct StateT * slot_5(struct StateT * v473);
struct StateT * slot_17(struct StateT * v1066);
struct StateT * slot_2(struct StateT * v409);
struct StateT * slot_7(struct StateT * v534);
struct StateT * slot_3(struct StateT * v421);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1085);
struct StateT * slot_1(struct StateT * v205);
struct StateT * slot_8(struct StateT * v1052);
struct StateT * slot_4(struct StateT * v437);
struct StateT * slot_13(struct StateT * v459);
struct StateT * slot_15(struct StateT * v518);
struct StateT * slot_9(struct StateT * v1071);
struct StateT * slot_11(struct StateT * v1101);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1304) {
  int v1305 = v1304->timer;
  int v1313 = v1305 + 1;
  v1304->timer = v1313;
  int * v1307 = v1304->regs;
  int v1308 = v1307[12];
  int v1309 = v1307[11];
  int v1317 = v1308 + v1309;
  v1307[12] = v1317;
  struct StateT * v1311 = slot_13(v1304);
  return v1311;
}

struct StateT * slot_14(struct StateT * v488) {
  int v489 = v488->timer;
  int v496 = v489 + 1;
  v488->timer = v496;
  int * v491 = v488->regs;
  int v492 = v491[10];
  int v499 = v492 << 2;
  v491[10] = v499;
  struct StateT * v494 = slot_15(v488);
  return v494;
}

struct StateT * slot_6(struct StateT * v502) {
  int v503 = v502->timer;
  int v511 = v503 + 1;
  v502->timer = v511;
  int * v505 = v502->regs;
  int v506 = v505[11];
  int v507 = v505[14];
  int v515 = v506 + v507;
  v505[14] = v515;
  struct StateT * v509 = slot_7(v502);
  return v509;
}

struct StateT * slot_16(struct StateT * v737) {
  int v738 = v737->timer;
  int v908 = v738 + 1;
  v737->timer = v908;
  int * v740 = v737->regs;
  int v741 = v740[10];
  int v742 = v740[12];
  int * v743 = v737->cache_tags;
  int v913 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2;
  int v744 = v743[v913];
  int v914 = ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + 1;
  int v745 = v743[v914];
  int v915 = 4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2);
  int v746 = v743[v915];
  int v916 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v747 = v743[v916];
  int v748 = v737->timer;
  int v917 = v748 + ((100 ^ (((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) & 104)))));
  v737->timer = v917;
  bool v918 = !(((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) == 0);
  int v842;
  if (v918) {
    int * v750 = v737->cache_age;
    int v920 = ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((~(((v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v745 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) & 1);
    int v751 = v750[v920];
    int v752 = v750[v913];
    int v921 = v752 + ((int)((unsigned int)(v752 - v751) >> 31));
    v750[v913] = v921;
    int * v754 = v737->cache_age;
    int v755 = v754[v914];
    int v923 = v755 + ((int)((unsigned int)(v755 - v751) >> 31));
    v754[v914] = v923;
    int * v757 = v737->cache_age;
    v757[v920] = 0;
    v842 = v920;
  } else {
    int * v760 = v737->cache_age;
    int v927 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2;
    int v761 = v760[v927];
    int * v762 = v737->cache_tags;
    int v763 = v762[v927];
    int v764 = v760[v914];
    int v765 = v762[v914];
    bool v929 = !(((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) == 0);
    int v819;
    if (v929) {
      int * v766 = v737->cache_age;
      int v931 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((~(((v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v747 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) & 1);
      int v767 = v766[v931];
      int v768 = v766[v915];
      int v932 = v768 + ((int)((unsigned int)(v768 - v767) >> 31));
      v766[v915] = v932;
      int * v770 = v737->cache_age;
      int v771 = v770[v916];
      int v934 = v771 + ((int)((unsigned int)(v771 - v767) >> 31));
      v770[v916] = v934;
      int * v773 = v737->cache_age;
      v773[v931] = 0;
      v819 = v931;
    } else {
      int * v776 = v737->cache_age;
      int v938 = 4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2);
      int v777 = v776[v938];
      int * v778 = v737->cache_tags;
      int v779 = v778[v938];
      int v780 = v776[v916];
      int v781 = v778[v916];
      int * v782 = v737->cache_dirty;
      int v941 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v783 = v782[v941];
      bool v942 = !(v783 == 0);
      if (v942) {
        int * v784 = v737->cache_tags;
        int v785 = v784[v941];
        int * v786 = v737->cache_vals;
        int v945 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v787 = v786[v945];
        int v946 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v788 = v786[v946];
        int * v789 = v737->mem;
        int v948 = v785 * 2;
        v789[v948] = v787;
        int * v791 = v737->mem;
        int v951 = (v785 * 2) + 1;
        v791[v951] = v788;
        ;
      } else {
        ;
      }
      int * v796 = v737->mem;
      int v956 = ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) * 2;
      int v797 = v796[v956];
      int v957 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) * 2) + 1;
      int v798 = v796[v957];
      int * v799 = v737->cache_vals;
      int v959 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v799[v959] = v797;
      int * v801 = v737->cache_vals;
      int v962 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v777 + ((~(((v779 ^ -1) | (-(v779 ^ -1))) >> 31)) & 2)) - (v780 + ((~(((v781 ^ -1) | (-(v781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v801[v962] = v798;
      int * v803 = v737->cache_tags;
      int v965 = (int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1);
      v803[v941] = v965;
      int * v805 = v737->cache_dirty;
      v805[v941] = 0;
      int * v807 = v737->cache_age;
      v807[v941] = 1;
      int * v809 = v737->cache_age;
      int v810 = v809[v941];
      int v811 = v809[v915];
      int v971 = v811 + ((int)((unsigned int)(v811 - v810) >> 31));
      v809[v915] = v971;
      int * v813 = v737->cache_age;
      int v814 = v813[v916];
      int v973 = v814 + ((int)((unsigned int)(v814 - v810) >> 31));
      v813[v916] = v973;
      int * v816 = v737->cache_age;
      v816[v941] = 0;
      v819 = v941;
    }
    int * v820 = v737->cache_vals;
    int v976 = v819 * 2;
    int v821 = v820[v976];
    int v977 = (v819 * 2) + 1;
    int v822 = v820[v977];
    int v978 = (((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v764 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v820[v978] = v821;
    int * v824 = v737->cache_vals;
    int v981 = ((((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v764 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v824[v981] = v822;
    int * v826 = v737->cache_tags;
    int v984 = ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 1) * 2) + ((((v761 + ((~(((v763 ^ -1) | (-(v763 ^ -1))) >> 31)) & 2)) - (v764 + ((~(((v765 ^ -1) | (-(v765 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v985 = (int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1);
    v826[v984] = v985;
    int * v828 = v737->cache_dirty;
    v828[v984] = 0;
    int * v830 = v737->cache_age;
    v830[v984] = 1;
    int * v832 = v737->cache_age;
    int v833 = v832[v984];
    int v834 = v832[v913];
    int v991 = v834 + ((int)((unsigned int)(v834 - v833) >> 31));
    v832[v913] = v991;
    int * v836 = v737->cache_age;
    int v837 = v836[v914];
    int v993 = v837 + ((int)((unsigned int)(v837 - v833) >> 31));
    v836[v914] = v993;
    int * v839 = v737->cache_age;
    v839[v984] = 0;
    v842 = v984;
  }
  int * v843 = v737->cache_vals;
  int v996 = (v842 * 2) + (((int)((unsigned int)v741 >> 2)) & 1);
  v843[v996] = v742;
  int * v845 = v737->cache_tags;
  int v846 = v845[v915];
  int v847 = v845[v916];
  bool v999 = !(((~(((v846 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v846 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) | (~(((v847 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v847 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31))) == 0);
  int v901;
  if (v999) {
    int * v848 = v737->cache_age;
    int v1001 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((~(((v847 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))) | (-(v847 ^ ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1))))) >> 31)) & 1);
    int v849 = v848[v1001];
    int v850 = v848[v915];
    int v1002 = v850 + ((int)((unsigned int)(v850 - v849) >> 31));
    v848[v915] = v1002;
    int * v852 = v737->cache_age;
    int v853 = v852[v916];
    int v1004 = v853 + ((int)((unsigned int)(v853 - v849) >> 31));
    v852[v916] = v1004;
    int * v855 = v737->cache_age;
    v855[v1001] = 0;
    v901 = v1001;
  } else {
    int * v858 = v737->cache_age;
    int v1008 = 4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2);
    int v859 = v858[v1008];
    int * v860 = v737->cache_tags;
    int v861 = v860[v1008];
    int v862 = v858[v916];
    int v863 = v860[v916];
    int * v864 = v737->cache_dirty;
    int v1011 = (4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v859 + ((~(((v861 ^ -1) | (-(v861 ^ -1))) >> 31)) & 2)) - (v862 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v865 = v864[v1011];
    bool v1012 = !(v865 == 0);
    if (v1012) {
      int * v866 = v737->cache_tags;
      int v867 = v866[v1011];
      int * v868 = v737->cache_vals;
      int v1015 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v859 + ((~(((v861 ^ -1) | (-(v861 ^ -1))) >> 31)) & 2)) - (v862 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v869 = v868[v1015];
      int v1016 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v859 + ((~(((v861 ^ -1) | (-(v861 ^ -1))) >> 31)) & 2)) - (v862 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v870 = v868[v1016];
      int * v871 = v737->mem;
      int v1018 = v867 * 2;
      v871[v1018] = v869;
      int * v873 = v737->mem;
      int v1021 = (v867 * 2) + 1;
      v873[v1021] = v870;
      ;
    } else {
      ;
    }
    int * v878 = v737->mem;
    int v1026 = ((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) * 2;
    int v879 = v878[v1026];
    int v1027 = (((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) * 2) + 1;
    int v880 = v878[v1027];
    int * v881 = v737->cache_vals;
    int v1029 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v859 + ((~(((v861 ^ -1) | (-(v861 ^ -1))) >> 31)) & 2)) - (v862 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v881[v1029] = v879;
    int * v883 = v737->cache_vals;
    int v1032 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1)) & 3) * 2)) + ((((v859 + ((~(((v861 ^ -1) | (-(v861 ^ -1))) >> 31)) & 2)) - (v862 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v883[v1032] = v880;
    int * v885 = v737->cache_tags;
    int v1035 = (int)((unsigned int)((int)((unsigned int)v741 >> 2)) >> 1);
    v885[v1011] = v1035;
    int * v887 = v737->cache_dirty;
    v887[v1011] = 0;
    int * v889 = v737->cache_age;
    v889[v1011] = 1;
    int * v891 = v737->cache_age;
    int v892 = v891[v1011];
    int v893 = v891[v915];
    int v1041 = v893 + ((int)((unsigned int)(v893 - v892) >> 31));
    v891[v915] = v1041;
    int * v895 = v737->cache_age;
    int v896 = v895[v916];
    int v1043 = v896 + ((int)((unsigned int)(v896 - v892) >> 31));
    v895[v916] = v1043;
    int * v898 = v737->cache_age;
    v898[v1011] = 0;
    v901 = v1011;
  }
  int * v902 = v737->cache_vals;
  int v1046 = (v901 * 2) + (((int)((unsigned int)v741 >> 2)) & 1);
  v902[v1046] = v742;
  int * v904 = v737->cache_dirty;
  v904[v901] = 1;
  struct StateT * v906 = slot_17(v737);
  return v906;
}

struct StateT * slot_5(struct StateT * v473) {
  int v474 = v473->timer;
  int v481 = v474 + 1;
  v473->timer = v481;
  int * v476 = v473->regs;
  int v477 = v476[10];
  int v485 = v477 << 2;
  v476[14] = v485;
  struct StateT * v479 = slot_6(v473);
  return v479;
}

struct StateT * slot_17(struct StateT * v1066) {
  int v1067 = v1066->timer;
  int v1070 = v1067 + 1;
  v1066->timer = v1070;
  return v1066;
}

struct StateT * slot_2(struct StateT * v409) {
  int v410 = v409->timer;
  int v416 = v410 + 1;
  v409->timer = v416;
  int * v412 = v409->regs;
  v412[15] = 15;
  struct StateT * v414 = slot_3(v409);
  return v414;
}

struct StateT * slot_7(struct StateT * v534) {
  int v535 = v534->timer;
  int v645 = v535 + 1;
  v534->timer = v645;
  int * v537 = v534->regs;
  int v538 = v537[14];
  int * v539 = v534->cache_tags;
  int v649 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2;
  int v540 = v539[v649];
  int v650 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + 1;
  int v541 = v539[v650];
  int v651 = 4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2);
  int v542 = v539[v651];
  int v652 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v543 = v539[v652];
  int v544 = v534->timer;
  int v653 = v544 + ((100 ^ (((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) & 104)))));
  v534->timer = v653;
  int * v546 = v534->cache_vals;
  bool v654 = !(((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) == 0);
  int v639;
  if (v654) {
    int * v547 = v534->cache_age;
    int v656 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) & 1);
    int v548 = v547[v656];
    int v549 = v547[v649];
    int v657 = v549 + ((int)((unsigned int)(v549 - v548) >> 31));
    v547[v649] = v657;
    int * v551 = v534->cache_age;
    int v552 = v551[v650];
    int v659 = v552 + ((int)((unsigned int)(v552 - v548) >> 31));
    v551[v650] = v659;
    int * v554 = v534->cache_age;
    v554[v656] = 0;
    v639 = v656;
  } else {
    int * v557 = v534->cache_age;
    int v663 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2;
    int v558 = v557[v663];
    int * v559 = v534->cache_tags;
    int v560 = v559[v663];
    int v561 = v557[v650];
    int v562 = v559[v650];
    bool v665 = !(((~(((v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v542 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) | (~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31))) == 0);
    int v616;
    if (v665) {
      int * v563 = v534->cache_age;
      int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((~(((v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))) | (-(v543 ^ ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1))))) >> 31)) & 1);
      int v564 = v563[v667];
      int v565 = v563[v651];
      int v668 = v565 + ((int)((unsigned int)(v565 - v564) >> 31));
      v563[v651] = v668;
      int * v567 = v534->cache_age;
      int v568 = v567[v652];
      int v670 = v568 + ((int)((unsigned int)(v568 - v564) >> 31));
      v567[v652] = v670;
      int * v570 = v534->cache_age;
      v570[v667] = 0;
      v616 = v667;
    } else {
      int * v573 = v534->cache_age;
      int v674 = 4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2);
      int v574 = v573[v674];
      int * v575 = v534->cache_tags;
      int v576 = v575[v674];
      int v577 = v573[v652];
      int v578 = v575[v652];
      int * v579 = v534->cache_dirty;
      int v677 = (4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v580 = v579[v677];
      bool v678 = !(v580 == 0);
      if (v678) {
        int * v581 = v534->cache_tags;
        int v582 = v581[v677];
        int * v583 = v534->cache_vals;
        int v681 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v584 = v583[v681];
        int v682 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v585 = v583[v682];
        int * v586 = v534->mem;
        int v684 = v582 * 2;
        v586[v684] = v584;
        int * v588 = v534->mem;
        int v687 = (v582 * 2) + 1;
        v588[v687] = v585;
        ;
      } else {
        ;
      }
      int * v593 = v534->mem;
      int v692 = ((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) * 2;
      int v594 = v593[v692];
      int v693 = (((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) * 2) + 1;
      int v595 = v593[v693];
      int * v596 = v534->cache_vals;
      int v695 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v596[v695] = v594;
      int * v598 = v534->cache_vals;
      int v698 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 3) * 2)) + ((((v574 + ((~(((v576 ^ -1) | (-(v576 ^ -1))) >> 31)) & 2)) - (v577 + ((~(((v578 ^ -1) | (-(v578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v598[v698] = v595;
      int * v600 = v534->cache_tags;
      int v701 = (int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1);
      v600[v677] = v701;
      int * v602 = v534->cache_dirty;
      v602[v677] = 0;
      int * v604 = v534->cache_age;
      v604[v677] = 1;
      int * v606 = v534->cache_age;
      int v607 = v606[v677];
      int v608 = v606[v651];
      int v707 = v608 + ((int)((unsigned int)(v608 - v607) >> 31));
      v606[v651] = v707;
      int * v610 = v534->cache_age;
      int v611 = v610[v652];
      int v709 = v611 + ((int)((unsigned int)(v611 - v607) >> 31));
      v610[v652] = v709;
      int * v613 = v534->cache_age;
      v613[v677] = 0;
      v616 = v677;
    }
    int * v617 = v534->cache_vals;
    int v712 = v616 * 2;
    int v618 = v617[v712];
    int v713 = (v616 * 2) + 1;
    int v619 = v617[v713];
    int v714 = (((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v558 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v617[v714] = v618;
    int * v621 = v534->cache_vals;
    int v717 = ((((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v558 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v621[v717] = v619;
    int * v623 = v534->cache_tags;
    int v720 = ((((int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1)) & 1) * 2) + ((((v558 + ((~(((v560 ^ -1) | (-(v560 ^ -1))) >> 31)) & 2)) - (v561 + ((~(((v562 ^ -1) | (-(v562 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v721 = (int)((unsigned int)((int)((unsigned int)v538 >> 2)) >> 1);
    v623[v720] = v721;
    int * v625 = v534->cache_dirty;
    v625[v720] = 0;
    int * v627 = v534->cache_age;
    v627[v720] = 1;
    int * v629 = v534->cache_age;
    int v630 = v629[v720];
    int v631 = v629[v649];
    int v727 = v631 + ((int)((unsigned int)(v631 - v630) >> 31));
    v629[v649] = v727;
    int * v633 = v534->cache_age;
    int v634 = v633[v650];
    int v729 = v634 + ((int)((unsigned int)(v634 - v630) >> 31));
    v633[v650] = v729;
    int * v636 = v534->cache_age;
    v636[v720] = 0;
    v639 = v720;
  }
  int v732 = (v639 * 2) + (((int)((unsigned int)v538 >> 2)) & 1);
  int v640 = v546[v732];
  int * v641 = v534->regs;
  v641[14] = v640;
  struct StateT * v643 = slot_8(v534);
  return v643;
}

struct StateT * slot_3(struct StateT * v421) {
  int v422 = v421->timer;
  int v430 = v422 + 1;
  v421->timer = v430;
  int * v424 = v421->regs;
  int v425 = v424[12];
  int v426 = v424[14];
  int v434 = v425 ^ v426;
  v424[12] = v434;
  struct StateT * v428 = slot_4(v421);
  return v428;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v1085) {
  int v1086 = v1085->timer;
  int v1094 = v1086 + 1;
  v1085->timer = v1094;
  int * v1088 = v1085->regs;
  int v1089 = v1088[11];
  int v1090 = v1088[14];
  int v1098 = v1089 + v1090;
  v1088[11] = v1098;
  struct StateT * v1092 = slot_11(v1085);
  return v1092;
}

struct StateT * slot_1(struct StateT * v205) {
  int v206 = v205->timer;
  int v316 = v206 + 1;
  v205->timer = v316;
  int * v208 = v205->regs;
  int v209 = v208[11];
  int * v210 = v205->cache_tags;
  int v320 = (((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2;
  int v211 = v210[v320];
  int v321 = ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v212 = v210[v321];
  int v322 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2);
  int v213 = v210[v322];
  int v323 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v214 = v210[v323];
  int v215 = v205->timer;
  int v324 = v215 + ((100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v205->timer = v324;
  int * v217 = v205->cache_vals;
  bool v325 = !(((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v310;
  if (v325) {
    int * v218 = v205->cache_age;
    int v327 = ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v219 = v218[v327];
    int v220 = v218[v320];
    int v328 = v220 + ((int)((unsigned int)(v220 - v219) >> 31));
    v218[v320] = v328;
    int * v222 = v205->cache_age;
    int v223 = v222[v321];
    int v330 = v223 + ((int)((unsigned int)(v223 - v219) >> 31));
    v222[v321] = v330;
    int * v225 = v205->cache_age;
    v225[v327] = 0;
    v310 = v327;
  } else {
    int * v228 = v205->cache_age;
    int v334 = (((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2;
    int v229 = v228[v334];
    int * v230 = v205->cache_tags;
    int v231 = v230[v334];
    int v232 = v228[v321];
    int v233 = v230[v321];
    bool v336 = !(((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v287;
    if (v336) {
      int * v234 = v205->cache_age;
      int v338 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v235 = v234[v338];
      int v236 = v234[v322];
      int v339 = v236 + ((int)((unsigned int)(v236 - v235) >> 31));
      v234[v322] = v339;
      int * v238 = v205->cache_age;
      int v239 = v238[v323];
      int v341 = v239 + ((int)((unsigned int)(v239 - v235) >> 31));
      v238[v323] = v341;
      int * v241 = v205->cache_age;
      v241[v338] = 0;
      v287 = v338;
    } else {
      int * v244 = v205->cache_age;
      int v345 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2);
      int v245 = v244[v345];
      int * v246 = v205->cache_tags;
      int v247 = v246[v345];
      int v248 = v244[v323];
      int v249 = v246[v323];
      int * v250 = v205->cache_dirty;
      int v348 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v251 = v250[v348];
      bool v349 = !(v251 == 0);
      if (v349) {
        int * v252 = v205->cache_tags;
        int v253 = v252[v348];
        int * v254 = v205->cache_vals;
        int v352 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v255 = v254[v352];
        int v353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v256 = v254[v353];
        int * v257 = v205->mem;
        int v355 = v253 * 2;
        v257[v355] = v255;
        int * v259 = v205->mem;
        int v358 = (v253 * 2) + 1;
        v259[v358] = v256;
        ;
      } else {
        ;
      }
      int * v264 = v205->mem;
      int v363 = ((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) * 2;
      int v265 = v264[v363];
      int v364 = (((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) * 2) + 1;
      int v266 = v264[v364];
      int * v267 = v205->cache_vals;
      int v366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v267[v366] = v265;
      int * v269 = v205->cache_vals;
      int v369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v269[v369] = v266;
      int * v271 = v205->cache_tags;
      int v372 = (int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1);
      v271[v348] = v372;
      int * v273 = v205->cache_dirty;
      v273[v348] = 0;
      int * v275 = v205->cache_age;
      v275[v348] = 1;
      int * v277 = v205->cache_age;
      int v278 = v277[v348];
      int v279 = v277[v322];
      int v378 = v279 + ((int)((unsigned int)(v279 - v278) >> 31));
      v277[v322] = v378;
      int * v281 = v205->cache_age;
      int v282 = v281[v323];
      int v380 = v282 + ((int)((unsigned int)(v282 - v278) >> 31));
      v281[v323] = v380;
      int * v284 = v205->cache_age;
      v284[v348] = 0;
      v287 = v348;
    }
    int * v288 = v205->cache_vals;
    int v383 = v287 * 2;
    int v289 = v288[v383];
    int v384 = (v287 * 2) + 1;
    int v290 = v288[v384];
    int v385 = (((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v288[v385] = v289;
    int * v292 = v205->cache_vals;
    int v388 = ((((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v292[v388] = v290;
    int * v294 = v205->cache_tags;
    int v391 = ((((int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v392 = (int)((unsigned int)((int)((unsigned int)(v209 + 12) >> 2)) >> 1);
    v294[v391] = v392;
    int * v296 = v205->cache_dirty;
    v296[v391] = 0;
    int * v298 = v205->cache_age;
    v298[v391] = 1;
    int * v300 = v205->cache_age;
    int v301 = v300[v391];
    int v302 = v300[v320];
    int v398 = v302 + ((int)((unsigned int)(v302 - v301) >> 31));
    v300[v320] = v398;
    int * v304 = v205->cache_age;
    int v305 = v304[v321];
    int v400 = v305 + ((int)((unsigned int)(v305 - v301) >> 31));
    v304[v321] = v400;
    int * v307 = v205->cache_age;
    v307[v391] = 0;
    v310 = v391;
  }
  int v403 = (v310 * 2) + (((int)((unsigned int)(v209 + 12) >> 2)) & 1);
  int v311 = v217[v403];
  int * v312 = v205->regs;
  v312[14] = v311;
  struct StateT * v314 = slot_2(v205);
  return v314;
}

struct StateT * slot_8(struct StateT * v1052) {
  int v1053 = v1052->timer;
  int v1060 = v1053 + 1;
  v1052->timer = v1060;
  int * v1055 = v1052->regs;
  int v1056 = v1055[14];
  int v1063 = v1056 & 15;
  v1055[14] = v1063;
  struct StateT * v1058 = slot_9(v1052);
  return v1058;
}

struct StateT * slot_4(struct StateT * v437) {
  int v438 = v437->timer;
  int v449 = v438 + 1;
  v437->timer = v449;
  int * v440 = v437->regs;
  int v441 = v440[15];
  int v442 = v440[10];
  bool v453 = (v441 ^ -2147483648) < (v442 ^ -2147483648);
  struct StateT * v447;
  if (v453) {
    struct StateT * v443 = slot_13(v437);
    v447 = v443;
  } else {
    struct StateT * v445 = slot_5(v437);
    v447 = v445;
  }
  return v447;
}

struct StateT * slot_13(struct StateT * v459) {
  int v460 = v459->timer;
  int v467 = v460 + 1;
  v459->timer = v467;
  int * v462 = v459->regs;
  int v463 = v462[10];
  int v470 = v463 & 7;
  v462[10] = v470;
  struct StateT * v465 = slot_14(v459);
  return v465;
}

struct StateT * slot_15(struct StateT * v518) {
  int v519 = v518->timer;
  int v527 = v519 + 1;
  v518->timer = v527;
  int * v521 = v518->regs;
  int v522 = v521[13];
  int v523 = v521[10];
  int v531 = v522 + v523;
  v521[10] = v531;
  struct StateT * v525 = slot_16(v518);
  return v525;
}

struct StateT * slot_9(struct StateT * v1071) {
  int v1072 = v1071->timer;
  int v1079 = v1072 + 1;
  v1071->timer = v1079;
  int * v1074 = v1071->regs;
  int v1075 = v1074[14];
  int v1082 = v1075 << 2;
  v1074[14] = v1082;
  struct StateT * v1077 = slot_10(v1071);
  return v1077;
}

struct StateT * slot_11(struct StateT * v1101) {
  int v1102 = v1101->timer;
  int v1212 = v1102 + 1;
  v1101->timer = v1212;
  int * v1104 = v1101->regs;
  int v1105 = v1104[11];
  int * v1106 = v1101->cache_tags;
  int v1216 = (((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2;
  int v1107 = v1106[v1216];
  int v1217 = ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1108 = v1106[v1217];
  int v1218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2);
  int v1109 = v1106[v1218];
  int v1219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1110 = v1106[v1219];
  int v1111 = v1101->timer;
  int v1220 = v1111 + ((100 ^ (((~(((v1109 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1109 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) | (~(((v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) | (~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1109 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1109 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) | (~(((v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1101->timer = v1220;
  int * v1113 = v1101->cache_vals;
  bool v1221 = !(((~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) | (~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31))) == 0);
  int v1206;
  if (v1221) {
    int * v1114 = v1101->cache_age;
    int v1223 = ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2) + ((~(((v1108 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1108 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) & 1);
    int v1115 = v1114[v1223];
    int v1116 = v1114[v1216];
    int v1224 = v1116 + ((int)((unsigned int)(v1116 - v1115) >> 31));
    v1114[v1216] = v1224;
    int * v1118 = v1101->cache_age;
    int v1119 = v1118[v1217];
    int v1226 = v1119 + ((int)((unsigned int)(v1119 - v1115) >> 31));
    v1118[v1217] = v1226;
    int * v1121 = v1101->cache_age;
    v1121[v1223] = 0;
    v1206 = v1223;
  } else {
    int * v1124 = v1101->cache_age;
    int v1230 = (((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2;
    int v1125 = v1124[v1230];
    int * v1126 = v1101->cache_tags;
    int v1127 = v1126[v1230];
    int v1128 = v1124[v1217];
    int v1129 = v1126[v1217];
    bool v1232 = !(((~(((v1109 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1109 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) | (~(((v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31))) == 0);
    int v1183;
    if (v1232) {
      int * v1130 = v1101->cache_age;
      int v1234 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))) | (-(v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1))))) >> 31)) & 1);
      int v1131 = v1130[v1234];
      int v1132 = v1130[v1218];
      int v1235 = v1132 + ((int)((unsigned int)(v1132 - v1131) >> 31));
      v1130[v1218] = v1235;
      int * v1134 = v1101->cache_age;
      int v1135 = v1134[v1219];
      int v1237 = v1135 + ((int)((unsigned int)(v1135 - v1131) >> 31));
      v1134[v1219] = v1237;
      int * v1137 = v1101->cache_age;
      v1137[v1234] = 0;
      v1183 = v1234;
    } else {
      int * v1140 = v1101->cache_age;
      int v1241 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2);
      int v1141 = v1140[v1241];
      int * v1142 = v1101->cache_tags;
      int v1143 = v1142[v1241];
      int v1144 = v1140[v1219];
      int v1145 = v1142[v1219];
      int * v1146 = v1101->cache_dirty;
      int v1244 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + ((((v1141 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2)) - (v1144 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1147 = v1146[v1244];
      bool v1245 = !(v1147 == 0);
      if (v1245) {
        int * v1148 = v1101->cache_tags;
        int v1149 = v1148[v1244];
        int * v1150 = v1101->cache_vals;
        int v1248 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + ((((v1141 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2)) - (v1144 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1151 = v1150[v1248];
        int v1249 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + ((((v1141 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2)) - (v1144 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1152 = v1150[v1249];
        int * v1153 = v1101->mem;
        int v1251 = v1149 * 2;
        v1153[v1251] = v1151;
        int * v1155 = v1101->mem;
        int v1254 = (v1149 * 2) + 1;
        v1155[v1254] = v1152;
        ;
      } else {
        ;
      }
      int * v1160 = v1101->mem;
      int v1259 = ((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) * 2;
      int v1161 = v1160[v1259];
      int v1260 = (((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) * 2) + 1;
      int v1162 = v1160[v1260];
      int * v1163 = v1101->cache_vals;
      int v1262 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + ((((v1141 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2)) - (v1144 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1163[v1262] = v1161;
      int * v1165 = v1101->cache_vals;
      int v1265 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 3) * 2)) + ((((v1141 + ((~(((v1143 ^ -1) | (-(v1143 ^ -1))) >> 31)) & 2)) - (v1144 + ((~(((v1145 ^ -1) | (-(v1145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1165[v1265] = v1162;
      int * v1167 = v1101->cache_tags;
      int v1268 = (int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1);
      v1167[v1244] = v1268;
      int * v1169 = v1101->cache_dirty;
      v1169[v1244] = 0;
      int * v1171 = v1101->cache_age;
      v1171[v1244] = 1;
      int * v1173 = v1101->cache_age;
      int v1174 = v1173[v1244];
      int v1175 = v1173[v1218];
      int v1274 = v1175 + ((int)((unsigned int)(v1175 - v1174) >> 31));
      v1173[v1218] = v1274;
      int * v1177 = v1101->cache_age;
      int v1178 = v1177[v1219];
      int v1276 = v1178 + ((int)((unsigned int)(v1178 - v1174) >> 31));
      v1177[v1219] = v1276;
      int * v1180 = v1101->cache_age;
      v1180[v1244] = 0;
      v1183 = v1244;
    }
    int * v1184 = v1101->cache_vals;
    int v1279 = v1183 * 2;
    int v1185 = v1184[v1279];
    int v1280 = (v1183 * 2) + 1;
    int v1186 = v1184[v1280];
    int v1281 = (((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2) + ((((v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2)) - (v1128 + ((~(((v1129 ^ -1) | (-(v1129 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1184[v1281] = v1185;
    int * v1188 = v1101->cache_vals;
    int v1284 = ((((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2) + ((((v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2)) - (v1128 + ((~(((v1129 ^ -1) | (-(v1129 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1188[v1284] = v1186;
    int * v1190 = v1101->cache_tags;
    int v1287 = ((((int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1)) & 1) * 2) + ((((v1125 + ((~(((v1127 ^ -1) | (-(v1127 ^ -1))) >> 31)) & 2)) - (v1128 + ((~(((v1129 ^ -1) | (-(v1129 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1288 = (int)((unsigned int)((int)((unsigned int)v1105 >> 2)) >> 1);
    v1190[v1287] = v1288;
    int * v1192 = v1101->cache_dirty;
    v1192[v1287] = 0;
    int * v1194 = v1101->cache_age;
    v1194[v1287] = 1;
    int * v1196 = v1101->cache_age;
    int v1197 = v1196[v1287];
    int v1198 = v1196[v1216];
    int v1294 = v1198 + ((int)((unsigned int)(v1198 - v1197) >> 31));
    v1196[v1216] = v1294;
    int * v1200 = v1101->cache_age;
    int v1201 = v1200[v1217];
    int v1296 = v1201 + ((int)((unsigned int)(v1201 - v1197) >> 31));
    v1200[v1217] = v1296;
    int * v1203 = v1101->cache_age;
    v1203[v1287] = 0;
    v1206 = v1287;
  }
  int v1299 = (v1206 * 2) + (((int)((unsigned int)v1105 >> 2)) & 1);
  int v1207 = v1113[v1299];
  int * v1208 = v1101->regs;
  v1208[11] = v1207;
  struct StateT * v1210 = slot_12(v1101);
  return v1210;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v113 = v3 + 1;
  v2->timer = v113;
  int * v5 = v2->regs;
  int v6 = v5[12];
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
    s1.mem[16 + i] = secret(0, 20);
    s2.mem[16 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}