// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT * slot_12(struct StateT * v756);
struct StateT * slot_14(struct StateT * v976);
struct StateT * slot_6(struct StateT * v286);
struct StateT * slot_5(struct StateT * v272);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v302);
struct StateT * slot_3(struct StateT * v245);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v540);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v505);
struct StateT * slot_4(struct StateT * v259);
struct StateT * slot_13(struct StateT * v960);
struct StateT * slot_15(struct StateT * v240);
struct StateT * slot_9(struct StateT * v527);
struct StateT * slot_11(struct StateT * v553);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v756) {
  int v757 = v756->timer;
  int v867 = v757 + 1;
  v756->timer = v867;
  int * v759 = v756->regs;
  int v760 = v759[11];
  int * v761 = v756->cache_tags;
  int v871 = (((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2;
  int v762 = v761[v871];
  int v872 = ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v763 = v761[v872];
  int v873 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2);
  int v764 = v761[v873];
  int v874 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v765 = v761[v874];
  int v766 = v756->timer;
  int v875 = v766 + ((100 ^ (((~(((v764 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v764 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v762 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v762 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v763 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v763 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v764 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v764 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v756->timer = v875;
  int * v768 = v756->cache_vals;
  bool v876 = !(((~(((v762 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v762 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v763 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v763 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v861;
  if (v876) {
    int * v769 = v756->cache_age;
    int v878 = ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v763 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v763 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v770 = v769[v878];
    int v771 = v769[v871];
    int v879 = v771 + ((int)((unsigned int)(v771 - v770) >> 31));
    v769[v871] = v879;
    int * v773 = v756->cache_age;
    int v774 = v773[v872];
    int v881 = v774 + ((int)((unsigned int)(v774 - v770) >> 31));
    v773[v872] = v881;
    int * v776 = v756->cache_age;
    v776[v878] = 0;
    v861 = v878;
  } else {
    int * v779 = v756->cache_age;
    int v885 = (((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2;
    int v780 = v779[v885];
    int * v781 = v756->cache_tags;
    int v782 = v781[v885];
    int v783 = v779[v872];
    int v784 = v781[v872];
    bool v887 = !(((~(((v764 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v764 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v838;
    if (v887) {
      int * v785 = v756->cache_age;
      int v889 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))) | (-(v765 ^ ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v786 = v785[v889];
      int v787 = v785[v873];
      int v890 = v787 + ((int)((unsigned int)(v787 - v786) >> 31));
      v785[v873] = v890;
      int * v789 = v756->cache_age;
      int v790 = v789[v874];
      int v892 = v790 + ((int)((unsigned int)(v790 - v786) >> 31));
      v789[v874] = v892;
      int * v792 = v756->cache_age;
      v792[v889] = 0;
      v838 = v889;
    } else {
      int * v795 = v756->cache_age;
      int v896 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2);
      int v796 = v795[v896];
      int * v797 = v756->cache_tags;
      int v798 = v797[v896];
      int v799 = v795[v874];
      int v800 = v797[v874];
      int * v801 = v756->cache_dirty;
      int v899 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v802 = v801[v899];
      bool v900 = !(v802 == 0);
      if (v900) {
        int * v803 = v756->cache_tags;
        int v804 = v803[v899];
        int * v805 = v756->cache_vals;
        int v903 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v806 = v805[v903];
        int v904 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v807 = v805[v904];
        int * v808 = v756->mem;
        int v906 = v804 * 2;
        v808[v906] = v806;
        int * v810 = v756->mem;
        int v909 = (v804 * 2) + 1;
        v810[v909] = v807;
        ;
      } else {
        ;
      }
      int * v815 = v756->mem;
      int v914 = ((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) * 2;
      int v816 = v815[v914];
      int v915 = (((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) * 2) + 1;
      int v817 = v815[v915];
      int * v818 = v756->cache_vals;
      int v917 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v818[v917] = v816;
      int * v820 = v756->cache_vals;
      int v920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2)) - (v799 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v820[v920] = v817;
      int * v822 = v756->cache_tags;
      int v923 = (int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1);
      v822[v899] = v923;
      int * v824 = v756->cache_dirty;
      v824[v899] = 0;
      int * v826 = v756->cache_age;
      v826[v899] = 1;
      int * v828 = v756->cache_age;
      int v829 = v828[v899];
      int v830 = v828[v873];
      int v929 = v830 + ((int)((unsigned int)(v830 - v829) >> 31));
      v828[v873] = v929;
      int * v832 = v756->cache_age;
      int v833 = v832[v874];
      int v931 = v833 + ((int)((unsigned int)(v833 - v829) >> 31));
      v832[v874] = v931;
      int * v835 = v756->cache_age;
      v835[v899] = 0;
      v838 = v899;
    }
    int * v839 = v756->cache_vals;
    int v934 = v838 * 2;
    int v840 = v839[v934];
    int v935 = (v838 * 2) + 1;
    int v841 = v839[v935];
    int v936 = (((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v839[v936] = v840;
    int * v843 = v756->cache_vals;
    int v939 = ((((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v843[v939] = v841;
    int * v845 = v756->cache_tags;
    int v942 = ((((int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v780 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2)) - (v783 + ((~(((v784 ^ -1) | (-(v784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v943 = (int)((unsigned int)((int)((unsigned int)(v760 + 68) >> 2)) >> 1);
    v845[v942] = v943;
    int * v847 = v756->cache_dirty;
    v847[v942] = 0;
    int * v849 = v756->cache_age;
    v849[v942] = 1;
    int * v851 = v756->cache_age;
    int v852 = v851[v942];
    int v853 = v851[v871];
    int v949 = v853 + ((int)((unsigned int)(v853 - v852) >> 31));
    v851[v871] = v949;
    int * v855 = v756->cache_age;
    int v856 = v855[v872];
    int v951 = v856 + ((int)((unsigned int)(v856 - v852) >> 31));
    v855[v872] = v951;
    int * v858 = v756->cache_age;
    v858[v942] = 0;
    v861 = v942;
  }
  int v954 = (v861 * 2) + (((int)((unsigned int)(v760 + 68) >> 2)) & 1);
  int v862 = v768[v954];
  int * v863 = v756->regs;
  v863[12] = v862;
  struct StateT * v865 = slot_13(v756);
  return v865;
}

struct StateT * slot_14(struct StateT * v976) {
  int v977 = v976->timer;
  int v1147 = v977 + 1;
  v976->timer = v1147;
  int * v979 = v976->regs;
  int v980 = v979[11];
  int v981 = v979[10];
  int * v982 = v976->cache_tags;
  int v1152 = (((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2;
  int v983 = v982[v1152];
  int v1153 = ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v984 = v982[v1153];
  int v1154 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2);
  int v985 = v982[v1154];
  int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v986 = v982[v1155];
  int v987 = v976->timer;
  int v1156 = v987 + ((100 ^ (((~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v976->timer = v1156;
  bool v1157 = !(((~(((v983 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v983 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1081;
  if (v1157) {
    int * v989 = v976->cache_age;
    int v1159 = ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v984 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v984 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v990 = v989[v1159];
    int v991 = v989[v1152];
    int v1160 = v991 + ((int)((unsigned int)(v991 - v990) >> 31));
    v989[v1152] = v1160;
    int * v993 = v976->cache_age;
    int v994 = v993[v1153];
    int v1162 = v994 + ((int)((unsigned int)(v994 - v990) >> 31));
    v993[v1153] = v1162;
    int * v996 = v976->cache_age;
    v996[v1159] = 0;
    v1081 = v1159;
  } else {
    int * v999 = v976->cache_age;
    int v1166 = (((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1000 = v999[v1166];
    int * v1001 = v976->cache_tags;
    int v1002 = v1001[v1166];
    int v1003 = v999[v1153];
    int v1004 = v1001[v1153];
    bool v1168 = !(((~(((v985 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v985 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1058;
    if (v1168) {
      int * v1005 = v976->cache_age;
      int v1170 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v986 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1006 = v1005[v1170];
      int v1007 = v1005[v1154];
      int v1171 = v1007 + ((int)((unsigned int)(v1007 - v1006) >> 31));
      v1005[v1154] = v1171;
      int * v1009 = v976->cache_age;
      int v1010 = v1009[v1155];
      int v1173 = v1010 + ((int)((unsigned int)(v1010 - v1006) >> 31));
      v1009[v1155] = v1173;
      int * v1012 = v976->cache_age;
      v1012[v1170] = 0;
      v1058 = v1170;
    } else {
      int * v1015 = v976->cache_age;
      int v1177 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1016 = v1015[v1177];
      int * v1017 = v976->cache_tags;
      int v1018 = v1017[v1177];
      int v1019 = v1015[v1155];
      int v1020 = v1017[v1155];
      int * v1021 = v976->cache_dirty;
      int v1180 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1022 = v1021[v1180];
      bool v1181 = !(v1022 == 0);
      if (v1181) {
        int * v1023 = v976->cache_tags;
        int v1024 = v1023[v1180];
        int * v1025 = v976->cache_vals;
        int v1184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1026 = v1025[v1184];
        int v1185 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1027 = v1025[v1185];
        int * v1028 = v976->mem;
        int v1187 = v1024 * 2;
        v1028[v1187] = v1026;
        int * v1030 = v976->mem;
        int v1190 = (v1024 * 2) + 1;
        v1030[v1190] = v1027;
        ;
      } else {
        ;
      }
      int * v1035 = v976->mem;
      int v1195 = ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) * 2;
      int v1036 = v1035[v1195];
      int v1196 = (((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1037 = v1035[v1196];
      int * v1038 = v976->cache_vals;
      int v1198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1038[v1198] = v1036;
      int * v1040 = v976->cache_vals;
      int v1201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1016 + ((~(((v1018 ^ -1) | (-(v1018 ^ -1))) >> 31)) & 2)) - (v1019 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1040[v1201] = v1037;
      int * v1042 = v976->cache_tags;
      int v1204 = (int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1);
      v1042[v1180] = v1204;
      int * v1044 = v976->cache_dirty;
      v1044[v1180] = 0;
      int * v1046 = v976->cache_age;
      v1046[v1180] = 1;
      int * v1048 = v976->cache_age;
      int v1049 = v1048[v1180];
      int v1050 = v1048[v1154];
      int v1210 = v1050 + ((int)((unsigned int)(v1050 - v1049) >> 31));
      v1048[v1154] = v1210;
      int * v1052 = v976->cache_age;
      int v1053 = v1052[v1155];
      int v1212 = v1053 + ((int)((unsigned int)(v1053 - v1049) >> 31));
      v1052[v1155] = v1212;
      int * v1055 = v976->cache_age;
      v1055[v1180] = 0;
      v1058 = v1180;
    }
    int * v1059 = v976->cache_vals;
    int v1215 = v1058 * 2;
    int v1060 = v1059[v1215];
    int v1216 = (v1058 * 2) + 1;
    int v1061 = v1059[v1216];
    int v1217 = (((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1000 + ((~(((v1002 ^ -1) | (-(v1002 ^ -1))) >> 31)) & 2)) - (v1003 + ((~(((v1004 ^ -1) | (-(v1004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1059[v1217] = v1060;
    int * v1063 = v976->cache_vals;
    int v1220 = ((((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1000 + ((~(((v1002 ^ -1) | (-(v1002 ^ -1))) >> 31)) & 2)) - (v1003 + ((~(((v1004 ^ -1) | (-(v1004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1063[v1220] = v1061;
    int * v1065 = v976->cache_tags;
    int v1223 = ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1000 + ((~(((v1002 ^ -1) | (-(v1002 ^ -1))) >> 31)) & 2)) - (v1003 + ((~(((v1004 ^ -1) | (-(v1004 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1224 = (int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1);
    v1065[v1223] = v1224;
    int * v1067 = v976->cache_dirty;
    v1067[v1223] = 0;
    int * v1069 = v976->cache_age;
    v1069[v1223] = 1;
    int * v1071 = v976->cache_age;
    int v1072 = v1071[v1223];
    int v1073 = v1071[v1152];
    int v1230 = v1073 + ((int)((unsigned int)(v1073 - v1072) >> 31));
    v1071[v1152] = v1230;
    int * v1075 = v976->cache_age;
    int v1076 = v1075[v1153];
    int v1232 = v1076 + ((int)((unsigned int)(v1076 - v1072) >> 31));
    v1075[v1153] = v1232;
    int * v1078 = v976->cache_age;
    v1078[v1223] = 0;
    v1081 = v1223;
  }
  int * v1082 = v976->cache_vals;
  int v1235 = (v1081 * 2) + (((int)((unsigned int)(v980 + 68) >> 2)) & 1);
  v1082[v1235] = v981;
  int * v1084 = v976->cache_tags;
  int v1085 = v1084[v1154];
  int v1086 = v1084[v1155];
  bool v1238 = !(((~(((v1085 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v1085 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1086 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v1086 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1140;
  if (v1238) {
    int * v1087 = v976->cache_age;
    int v1240 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1086 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))) | (-(v1086 ^ ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1088 = v1087[v1240];
    int v1089 = v1087[v1154];
    int v1241 = v1089 + ((int)((unsigned int)(v1089 - v1088) >> 31));
    v1087[v1154] = v1241;
    int * v1091 = v976->cache_age;
    int v1092 = v1091[v1155];
    int v1243 = v1092 + ((int)((unsigned int)(v1092 - v1088) >> 31));
    v1091[v1155] = v1243;
    int * v1094 = v976->cache_age;
    v1094[v1240] = 0;
    v1140 = v1240;
  } else {
    int * v1097 = v976->cache_age;
    int v1247 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1098 = v1097[v1247];
    int * v1099 = v976->cache_tags;
    int v1100 = v1099[v1247];
    int v1101 = v1097[v1155];
    int v1102 = v1099[v1155];
    int * v1103 = v976->cache_dirty;
    int v1250 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1098 + ((~(((v1100 ^ -1) | (-(v1100 ^ -1))) >> 31)) & 2)) - (v1101 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1104 = v1103[v1250];
    bool v1251 = !(v1104 == 0);
    if (v1251) {
      int * v1105 = v976->cache_tags;
      int v1106 = v1105[v1250];
      int * v1107 = v976->cache_vals;
      int v1254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1098 + ((~(((v1100 ^ -1) | (-(v1100 ^ -1))) >> 31)) & 2)) - (v1101 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1108 = v1107[v1254];
      int v1255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1098 + ((~(((v1100 ^ -1) | (-(v1100 ^ -1))) >> 31)) & 2)) - (v1101 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1109 = v1107[v1255];
      int * v1110 = v976->mem;
      int v1257 = v1106 * 2;
      v1110[v1257] = v1108;
      int * v1112 = v976->mem;
      int v1260 = (v1106 * 2) + 1;
      v1112[v1260] = v1109;
      ;
    } else {
      ;
    }
    int * v1117 = v976->mem;
    int v1265 = ((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) * 2;
    int v1118 = v1117[v1265];
    int v1266 = (((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1119 = v1117[v1266];
    int * v1120 = v976->cache_vals;
    int v1268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1098 + ((~(((v1100 ^ -1) | (-(v1100 ^ -1))) >> 31)) & 2)) - (v1101 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1120[v1268] = v1118;
    int * v1122 = v976->cache_vals;
    int v1271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1098 + ((~(((v1100 ^ -1) | (-(v1100 ^ -1))) >> 31)) & 2)) - (v1101 + ((~(((v1102 ^ -1) | (-(v1102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1122[v1271] = v1119;
    int * v1124 = v976->cache_tags;
    int v1274 = (int)((unsigned int)((int)((unsigned int)(v980 + 68) >> 2)) >> 1);
    v1124[v1250] = v1274;
    int * v1126 = v976->cache_dirty;
    v1126[v1250] = 0;
    int * v1128 = v976->cache_age;
    v1128[v1250] = 1;
    int * v1130 = v976->cache_age;
    int v1131 = v1130[v1250];
    int v1132 = v1130[v1154];
    int v1280 = v1132 + ((int)((unsigned int)(v1132 - v1131) >> 31));
    v1130[v1154] = v1280;
    int * v1134 = v976->cache_age;
    int v1135 = v1134[v1155];
    int v1282 = v1135 + ((int)((unsigned int)(v1135 - v1131) >> 31));
    v1134[v1155] = v1282;
    int * v1137 = v976->cache_age;
    v1137[v1250] = 0;
    v1140 = v1250;
  }
  int * v1141 = v976->cache_vals;
  int v1285 = (v1140 * 2) + (((int)((unsigned int)(v980 + 68) >> 2)) & 1);
  v1141[v1285] = v981;
  int * v1143 = v976->cache_dirty;
  v1143[v1140] = 1;
  struct StateT * v1145 = slot_15(v976);
  return v1145;
}

struct StateT * slot_6(struct StateT * v286) {
  int v287 = v286->timer;
  int v295 = v287 + 1;
  v286->timer = v295;
  int * v289 = v286->regs;
  int v290 = v289[12];
  int v291 = v289[10];
  int v299 = v290 + v291;
  v289[10] = v299;
  struct StateT * v293 = slot_7(v286);
  return v293;
}

struct StateT * slot_5(struct StateT * v272) {
  int v273 = v272->timer;
  int v280 = v273 + 1;
  v272->timer = v280;
  int * v275 = v272->regs;
  int v276 = v275[12];
  int v283 = v276 + 72;
  v275[12] = v283;
  struct StateT * v278 = slot_6(v272);
  return v278;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v230 = v219 + 1;
  v218->timer = v230;
  int * v221 = v218->regs;
  int v222 = v221[10];
  int v223 = v221[12];
  bool v234 = (v222 ^ -2147483648) >= (v223 ^ -2147483648);
  struct StateT * v228;
  if (v234) {
    struct StateT * v224 = slot_15(v218);
    v228 = v224;
  } else {
    struct StateT * v226 = slot_3(v218);
    v228 = v226;
  }
  return v228;
}

struct StateT * slot_7(struct StateT * v302) {
  int v303 = v302->timer;
  int v413 = v303 + 1;
  v302->timer = v413;
  int * v305 = v302->regs;
  int v306 = v305[10];
  int * v307 = v302->cache_tags;
  int v417 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2;
  int v308 = v307[v417];
  int v418 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + 1;
  int v309 = v307[v418];
  int v419 = 4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2);
  int v310 = v307[v419];
  int v420 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v311 = v307[v420];
  int v312 = v302->timer;
  int v421 = v312 + ((100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & 104)))));
  v302->timer = v421;
  int * v314 = v302->cache_vals;
  bool v422 = !(((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) == 0);
  int v407;
  if (v422) {
    int * v315 = v302->cache_age;
    int v424 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) & 1);
    int v316 = v315[v424];
    int v317 = v315[v417];
    int v425 = v317 + ((int)((unsigned int)(v317 - v316) >> 31));
    v315[v417] = v425;
    int * v319 = v302->cache_age;
    int v320 = v319[v418];
    int v427 = v320 + ((int)((unsigned int)(v320 - v316) >> 31));
    v319[v418] = v427;
    int * v322 = v302->cache_age;
    v322[v424] = 0;
    v407 = v424;
  } else {
    int * v325 = v302->cache_age;
    int v431 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2;
    int v326 = v325[v431];
    int * v327 = v302->cache_tags;
    int v328 = v327[v431];
    int v329 = v325[v418];
    int v330 = v327[v418];
    bool v433 = !(((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) == 0);
    int v384;
    if (v433) {
      int * v331 = v302->cache_age;
      int v435 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) & 1);
      int v332 = v331[v435];
      int v333 = v331[v419];
      int v436 = v333 + ((int)((unsigned int)(v333 - v332) >> 31));
      v331[v419] = v436;
      int * v335 = v302->cache_age;
      int v336 = v335[v420];
      int v438 = v336 + ((int)((unsigned int)(v336 - v332) >> 31));
      v335[v420] = v438;
      int * v338 = v302->cache_age;
      v338[v435] = 0;
      v384 = v435;
    } else {
      int * v341 = v302->cache_age;
      int v442 = 4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2);
      int v342 = v341[v442];
      int * v343 = v302->cache_tags;
      int v344 = v343[v442];
      int v345 = v341[v420];
      int v346 = v343[v420];
      int * v347 = v302->cache_dirty;
      int v445 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v348 = v347[v445];
      bool v446 = !(v348 == 0);
      if (v446) {
        int * v349 = v302->cache_tags;
        int v350 = v349[v445];
        int * v351 = v302->cache_vals;
        int v449 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v352 = v351[v449];
        int v450 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v353 = v351[v450];
        int * v354 = v302->mem;
        int v452 = v350 * 2;
        v354[v452] = v352;
        int * v356 = v302->mem;
        int v455 = (v350 * 2) + 1;
        v356[v455] = v353;
        ;
      } else {
        ;
      }
      int * v361 = v302->mem;
      int v460 = ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) * 2;
      int v362 = v361[v460];
      int v461 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) * 2) + 1;
      int v363 = v361[v461];
      int * v364 = v302->cache_vals;
      int v463 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v364[v463] = v362;
      int * v366 = v302->cache_vals;
      int v466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v366[v466] = v363;
      int * v368 = v302->cache_tags;
      int v469 = (int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1);
      v368[v445] = v469;
      int * v370 = v302->cache_dirty;
      v370[v445] = 0;
      int * v372 = v302->cache_age;
      v372[v445] = 1;
      int * v374 = v302->cache_age;
      int v375 = v374[v445];
      int v376 = v374[v419];
      int v475 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
      v374[v419] = v475;
      int * v378 = v302->cache_age;
      int v379 = v378[v420];
      int v477 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
      v378[v420] = v477;
      int * v381 = v302->cache_age;
      v381[v445] = 0;
      v384 = v445;
    }
    int * v385 = v302->cache_vals;
    int v480 = v384 * 2;
    int v386 = v385[v480];
    int v481 = (v384 * 2) + 1;
    int v387 = v385[v481];
    int v482 = (((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v385[v482] = v386;
    int * v389 = v302->cache_vals;
    int v485 = ((((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v389[v485] = v387;
    int * v391 = v302->cache_tags;
    int v488 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v489 = (int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1);
    v391[v488] = v489;
    int * v393 = v302->cache_dirty;
    v393[v488] = 0;
    int * v395 = v302->cache_age;
    v395[v488] = 1;
    int * v397 = v302->cache_age;
    int v398 = v397[v488];
    int v399 = v397[v417];
    int v495 = v399 + ((int)((unsigned int)(v399 - v398) >> 31));
    v397[v417] = v495;
    int * v401 = v302->cache_age;
    int v402 = v401[v418];
    int v497 = v402 + ((int)((unsigned int)(v402 - v398) >> 31));
    v401[v418] = v497;
    int * v404 = v302->cache_age;
    v404[v488] = 0;
    v407 = v488;
  }
  int v500 = (v407 * 2) + (((int)((unsigned int)v306 >> 2)) & 1);
  int v408 = v314[v500];
  int * v409 = v302->regs;
  v409[10] = v408;
  struct StateT * v411 = slot_8(v302);
  return v411;
}

struct StateT * slot_3(struct StateT * v245) {
  int v246 = v245->timer;
  int v253 = v246 + 1;
  v245->timer = v253;
  int * v248 = v245->regs;
  int v249 = v248[10];
  int v256 = v249 << 2;
  v248[10] = v256;
  struct StateT * v251 = slot_4(v245);
  return v251;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v540) {
  int v541 = v540->timer;
  int v547 = v541 + 1;
  v540->timer = v547;
  int * v543 = v540->regs;
  v543[11] = 0;
  struct StateT * v545 = slot_11(v540);
  return v545;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
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
  v122[12] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_8(struct StateT * v505) {
  int v506 = v505->timer;
  int v517 = v506 + 1;
  v505->timer = v517;
  int * v508 = v505->regs;
  int v509 = v508[10];
  int v510 = v508[11];
  bool v521 = !(v509 == v510);
  struct StateT * v515;
  if (v521) {
    struct StateT * v511 = slot_15(v505);
    v515 = v511;
  } else {
    struct StateT * v513 = slot_9(v505);
    v515 = v513;
  }
  return v515;
}

struct StateT * slot_4(struct StateT * v259) {
  int v260 = v259->timer;
  int v266 = v260 + 1;
  v259->timer = v266;
  int * v262 = v259->regs;
  v262[12] = 0;
  struct StateT * v264 = slot_5(v259);
  return v264;
}

struct StateT * slot_13(struct StateT * v960) {
  int v961 = v960->timer;
  int v969 = v961 + 1;
  v960->timer = v969;
  int * v963 = v960->regs;
  int v964 = v963[12];
  int v965 = v963[10];
  int v973 = v964 & v965;
  v963[10] = v973;
  struct StateT * v967 = slot_14(v960);
  return v967;
}

struct StateT * slot_15(struct StateT * v240) {
  int v241 = v240->timer;
  int v244 = v241 + 1;
  v240->timer = v244;
  return v240;
}

struct StateT * slot_9(struct StateT * v527) {
  int v528 = v527->timer;
  int v534 = v528 + 1;
  v527->timer = v534;
  int * v530 = v527->regs;
  v530[10] = 0;
  struct StateT * v532 = slot_10(v527);
  return v532;
}

struct StateT * slot_11(struct StateT * v553) {
  int v554 = v553->timer;
  int v664 = v554 + 1;
  v553->timer = v664;
  int * v556 = v553->regs;
  int v557 = v556[10];
  int * v558 = v553->cache_tags;
  int v668 = (((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2;
  int v559 = v558[v668];
  int v669 = ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v560 = v558[v669];
  int v670 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2);
  int v561 = v558[v670];
  int v671 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v562 = v558[v671];
  int v563 = v553->timer;
  int v672 = v563 + ((100 ^ (((~(((v561 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v561 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v561 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v561 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v553->timer = v672;
  int * v565 = v553->cache_vals;
  bool v673 = !(((~(((v559 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v559 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v658;
  if (v673) {
    int * v566 = v553->cache_age;
    int v675 = ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v560 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v560 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v567 = v566[v675];
    int v568 = v566[v668];
    int v676 = v568 + ((int)((unsigned int)(v568 - v567) >> 31));
    v566[v668] = v676;
    int * v570 = v553->cache_age;
    int v571 = v570[v669];
    int v678 = v571 + ((int)((unsigned int)(v571 - v567) >> 31));
    v570[v669] = v678;
    int * v573 = v553->cache_age;
    v573[v675] = 0;
    v658 = v675;
  } else {
    int * v576 = v553->cache_age;
    int v682 = (((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2;
    int v577 = v576[v682];
    int * v578 = v553->cache_tags;
    int v579 = v578[v682];
    int v580 = v576[v669];
    int v581 = v578[v669];
    bool v684 = !(((~(((v561 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v561 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v635;
    if (v684) {
      int * v582 = v553->cache_age;
      int v686 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))) | (-(v562 ^ ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v583 = v582[v686];
      int v584 = v582[v670];
      int v687 = v584 + ((int)((unsigned int)(v584 - v583) >> 31));
      v582[v670] = v687;
      int * v586 = v553->cache_age;
      int v587 = v586[v671];
      int v689 = v587 + ((int)((unsigned int)(v587 - v583) >> 31));
      v586[v671] = v689;
      int * v589 = v553->cache_age;
      v589[v686] = 0;
      v635 = v686;
    } else {
      int * v592 = v553->cache_age;
      int v693 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2);
      int v593 = v592[v693];
      int * v594 = v553->cache_tags;
      int v595 = v594[v693];
      int v596 = v592[v671];
      int v597 = v594[v671];
      int * v598 = v553->cache_dirty;
      int v696 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v599 = v598[v696];
      bool v697 = !(v599 == 0);
      if (v697) {
        int * v600 = v553->cache_tags;
        int v601 = v600[v696];
        int * v602 = v553->cache_vals;
        int v700 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v603 = v602[v700];
        int v701 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v604 = v602[v701];
        int * v605 = v553->mem;
        int v703 = v601 * 2;
        v605[v703] = v603;
        int * v607 = v553->mem;
        int v706 = (v601 * 2) + 1;
        v607[v706] = v604;
        ;
      } else {
        ;
      }
      int * v612 = v553->mem;
      int v711 = ((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) * 2;
      int v613 = v612[v711];
      int v712 = (((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) * 2) + 1;
      int v614 = v612[v712];
      int * v615 = v553->cache_vals;
      int v714 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v615[v714] = v613;
      int * v617 = v553->cache_vals;
      int v717 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v593 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2)) - (v596 + ((~(((v597 ^ -1) | (-(v597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v617[v717] = v614;
      int * v619 = v553->cache_tags;
      int v720 = (int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1);
      v619[v696] = v720;
      int * v621 = v553->cache_dirty;
      v621[v696] = 0;
      int * v623 = v553->cache_age;
      v623[v696] = 1;
      int * v625 = v553->cache_age;
      int v626 = v625[v696];
      int v627 = v625[v670];
      int v726 = v627 + ((int)((unsigned int)(v627 - v626) >> 31));
      v625[v670] = v726;
      int * v629 = v553->cache_age;
      int v630 = v629[v671];
      int v728 = v630 + ((int)((unsigned int)(v630 - v626) >> 31));
      v629[v671] = v728;
      int * v632 = v553->cache_age;
      v632[v696] = 0;
      v635 = v696;
    }
    int * v636 = v553->cache_vals;
    int v731 = v635 * 2;
    int v637 = v636[v731];
    int v732 = (v635 * 2) + 1;
    int v638 = v636[v732];
    int v733 = (((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v636[v733] = v637;
    int * v640 = v553->cache_vals;
    int v736 = ((((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v640[v736] = v638;
    int * v642 = v553->cache_tags;
    int v739 = ((((int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v577 + ((~(((v579 ^ -1) | (-(v579 ^ -1))) >> 31)) & 2)) - (v580 + ((~(((v581 ^ -1) | (-(v581 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v740 = (int)((unsigned int)((int)((unsigned int)(v557 + 4) >> 2)) >> 1);
    v642[v739] = v740;
    int * v644 = v553->cache_dirty;
    v644[v739] = 0;
    int * v646 = v553->cache_age;
    v646[v739] = 1;
    int * v648 = v553->cache_age;
    int v649 = v648[v739];
    int v650 = v648[v668];
    int v746 = v650 + ((int)((unsigned int)(v650 - v649) >> 31));
    v648[v668] = v746;
    int * v652 = v553->cache_age;
    int v653 = v652[v669];
    int v748 = v653 + ((int)((unsigned int)(v653 - v649) >> 31));
    v652[v669] = v748;
    int * v655 = v553->cache_age;
    v655[v739] = 0;
    v658 = v739;
  }
  int v751 = (v658 * 2) + (((int)((unsigned int)(v557 + 4) >> 2)) & 1);
  int v659 = v565[v751];
  int * v660 = v553->regs;
  v660[10] = v659;
  struct StateT * v662 = slot_12(v553);
  return v662;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
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