// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v44);
struct StateT2 * slot_6(struct StateT2 * v569);
struct StateT2 * slot_5(struct StateT2 * v676);
struct StateT2 * slot_4(struct StateT2 * v611);
struct StateT2 * slot_2(struct StateT2 * v470);
struct StateT2 * slot_3(struct StateT2 * v512);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v699 = v1->a;
  int v700 = v699->timer;
  int * v701 = v699->reg_ready;
  int v702 = v701[0];
  int v963 = v702 + ((v700 - v702) & (~((v700 - v702) >> 31)));
  v699->timer = v963;
  int v704 = v699->timer;
  int * v705 = v699->reg_ready;
  int v706 = v705[1];
  int v966 = v706 + ((v704 - v706) & (~((v704 - v706) >> 31)));
  v699->timer = v966;
  int v708 = v699->timer;
  int * v709 = v699->reg_ready;
  int v710 = v709[2];
  int v969 = v710 + ((v708 - v710) & (~((v708 - v710) >> 31)));
  v699->timer = v969;
  int v712 = v699->timer;
  int * v713 = v699->reg_ready;
  int v714 = v713[3];
  int v972 = v714 + ((v712 - v714) & (~((v712 - v714) >> 31)));
  v699->timer = v972;
  int v716 = v699->timer;
  int * v717 = v699->reg_ready;
  int v718 = v717[4];
  int v975 = v718 + ((v716 - v718) & (~((v716 - v718) >> 31)));
  v699->timer = v975;
  int v720 = v699->timer;
  int * v721 = v699->reg_ready;
  int v722 = v721[5];
  int v978 = v722 + ((v720 - v722) & (~((v720 - v722) >> 31)));
  v699->timer = v978;
  int v724 = v699->timer;
  int * v725 = v699->reg_ready;
  int v726 = v725[6];
  int v981 = v726 + ((v724 - v726) & (~((v724 - v726) >> 31)));
  v699->timer = v981;
  int v728 = v699->timer;
  int * v729 = v699->reg_ready;
  int v730 = v729[7];
  int v984 = v730 + ((v728 - v730) & (~((v728 - v730) >> 31)));
  v699->timer = v984;
  int v732 = v699->timer;
  int * v733 = v699->reg_ready;
  int v734 = v733[8];
  int v987 = v734 + ((v732 - v734) & (~((v732 - v734) >> 31)));
  v699->timer = v987;
  int v736 = v699->timer;
  int * v737 = v699->reg_ready;
  int v738 = v737[9];
  int v990 = v738 + ((v736 - v738) & (~((v736 - v738) >> 31)));
  v699->timer = v990;
  int v740 = v699->timer;
  int * v741 = v699->reg_ready;
  int v742 = v741[10];
  int v993 = v742 + ((v740 - v742) & (~((v740 - v742) >> 31)));
  v699->timer = v993;
  int v744 = v699->timer;
  int * v745 = v699->reg_ready;
  int v746 = v745[11];
  int v996 = v746 + ((v744 - v746) & (~((v744 - v746) >> 31)));
  v699->timer = v996;
  int v748 = v699->timer;
  int * v749 = v699->reg_ready;
  int v750 = v749[12];
  int v999 = v750 + ((v748 - v750) & (~((v748 - v750) >> 31)));
  v699->timer = v999;
  int v752 = v699->timer;
  int * v753 = v699->reg_ready;
  int v754 = v753[13];
  int v1002 = v754 + ((v752 - v754) & (~((v752 - v754) >> 31)));
  v699->timer = v1002;
  int v756 = v699->timer;
  int * v757 = v699->reg_ready;
  int v758 = v757[14];
  int v1005 = v758 + ((v756 - v758) & (~((v756 - v758) >> 31)));
  v699->timer = v1005;
  int v760 = v699->timer;
  int * v761 = v699->reg_ready;
  int v762 = v761[15];
  int v1008 = v762 + ((v760 - v762) & (~((v760 - v762) >> 31)));
  v699->timer = v1008;
  int v764 = v699->timer;
  int * v765 = v699->reg_ready;
  int v766 = v765[16];
  int v1011 = v766 + ((v764 - v766) & (~((v764 - v766) >> 31)));
  v699->timer = v1011;
  int v768 = v699->timer;
  int * v769 = v699->reg_ready;
  int v770 = v769[17];
  int v1014 = v770 + ((v768 - v770) & (~((v768 - v770) >> 31)));
  v699->timer = v1014;
  int v772 = v699->timer;
  int * v773 = v699->reg_ready;
  int v774 = v773[18];
  int v1017 = v774 + ((v772 - v774) & (~((v772 - v774) >> 31)));
  v699->timer = v1017;
  int v776 = v699->timer;
  int * v777 = v699->reg_ready;
  int v778 = v777[19];
  int v1020 = v778 + ((v776 - v778) & (~((v776 - v778) >> 31)));
  v699->timer = v1020;
  int v780 = v699->timer;
  int * v781 = v699->reg_ready;
  int v782 = v781[20];
  int v1023 = v782 + ((v780 - v782) & (~((v780 - v782) >> 31)));
  v699->timer = v1023;
  int v784 = v699->timer;
  int * v785 = v699->reg_ready;
  int v786 = v785[21];
  int v1026 = v786 + ((v784 - v786) & (~((v784 - v786) >> 31)));
  v699->timer = v1026;
  int v788 = v699->timer;
  int * v789 = v699->reg_ready;
  int v790 = v789[22];
  int v1029 = v790 + ((v788 - v790) & (~((v788 - v790) >> 31)));
  v699->timer = v1029;
  int v792 = v699->timer;
  int * v793 = v699->reg_ready;
  int v794 = v793[23];
  int v1032 = v794 + ((v792 - v794) & (~((v792 - v794) >> 31)));
  v699->timer = v1032;
  int v796 = v699->timer;
  int * v797 = v699->reg_ready;
  int v798 = v797[24];
  int v1035 = v798 + ((v796 - v798) & (~((v796 - v798) >> 31)));
  v699->timer = v1035;
  int v800 = v699->timer;
  int * v801 = v699->reg_ready;
  int v802 = v801[25];
  int v1038 = v802 + ((v800 - v802) & (~((v800 - v802) >> 31)));
  v699->timer = v1038;
  int v804 = v699->timer;
  int * v805 = v699->reg_ready;
  int v806 = v805[26];
  int v1041 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v699->timer = v1041;
  int v808 = v699->timer;
  int * v809 = v699->reg_ready;
  int v810 = v809[27];
  int v1044 = v810 + ((v808 - v810) & (~((v808 - v810) >> 31)));
  v699->timer = v1044;
  int v812 = v699->timer;
  int * v813 = v699->reg_ready;
  int v814 = v813[28];
  int v1047 = v814 + ((v812 - v814) & (~((v812 - v814) >> 31)));
  v699->timer = v1047;
  int v816 = v699->timer;
  int * v817 = v699->reg_ready;
  int v818 = v817[29];
  int v1050 = v818 + ((v816 - v818) & (~((v816 - v818) >> 31)));
  v699->timer = v1050;
  int v820 = v699->timer;
  int * v821 = v699->reg_ready;
  int v822 = v821[30];
  int v1053 = v822 + ((v820 - v822) & (~((v820 - v822) >> 31)));
  v699->timer = v1053;
  int v824 = v699->timer;
  int * v825 = v699->reg_ready;
  int v826 = v825[31];
  int v1056 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v699->timer = v1056;
  struct StateT * v828 = v1->b;
  int v829 = v828->timer;
  int * v830 = v828->reg_ready;
  int v831 = v830[0];
  int v1059 = v831 + ((v829 - v831) & (~((v829 - v831) >> 31)));
  v828->timer = v1059;
  int v833 = v828->timer;
  int * v834 = v828->reg_ready;
  int v835 = v834[1];
  int v1061 = v835 + ((v833 - v835) & (~((v833 - v835) >> 31)));
  v828->timer = v1061;
  int v837 = v828->timer;
  int * v838 = v828->reg_ready;
  int v839 = v838[2];
  int v1063 = v839 + ((v837 - v839) & (~((v837 - v839) >> 31)));
  v828->timer = v1063;
  int v841 = v828->timer;
  int * v842 = v828->reg_ready;
  int v843 = v842[3];
  int v1065 = v843 + ((v841 - v843) & (~((v841 - v843) >> 31)));
  v828->timer = v1065;
  int v845 = v828->timer;
  int * v846 = v828->reg_ready;
  int v847 = v846[4];
  int v1067 = v847 + ((v845 - v847) & (~((v845 - v847) >> 31)));
  v828->timer = v1067;
  int v849 = v828->timer;
  int * v850 = v828->reg_ready;
  int v851 = v850[5];
  int v1069 = v851 + ((v849 - v851) & (~((v849 - v851) >> 31)));
  v828->timer = v1069;
  int v853 = v828->timer;
  int * v854 = v828->reg_ready;
  int v855 = v854[6];
  int v1071 = v855 + ((v853 - v855) & (~((v853 - v855) >> 31)));
  v828->timer = v1071;
  int v857 = v828->timer;
  int * v858 = v828->reg_ready;
  int v859 = v858[7];
  int v1073 = v859 + ((v857 - v859) & (~((v857 - v859) >> 31)));
  v828->timer = v1073;
  int v861 = v828->timer;
  int * v862 = v828->reg_ready;
  int v863 = v862[8];
  int v1075 = v863 + ((v861 - v863) & (~((v861 - v863) >> 31)));
  v828->timer = v1075;
  int v865 = v828->timer;
  int * v866 = v828->reg_ready;
  int v867 = v866[9];
  int v1077 = v867 + ((v865 - v867) & (~((v865 - v867) >> 31)));
  v828->timer = v1077;
  int v869 = v828->timer;
  int * v870 = v828->reg_ready;
  int v871 = v870[10];
  int v1079 = v871 + ((v869 - v871) & (~((v869 - v871) >> 31)));
  v828->timer = v1079;
  int v873 = v828->timer;
  int * v874 = v828->reg_ready;
  int v875 = v874[11];
  int v1081 = v875 + ((v873 - v875) & (~((v873 - v875) >> 31)));
  v828->timer = v1081;
  int v877 = v828->timer;
  int * v878 = v828->reg_ready;
  int v879 = v878[12];
  int v1083 = v879 + ((v877 - v879) & (~((v877 - v879) >> 31)));
  v828->timer = v1083;
  int v881 = v828->timer;
  int * v882 = v828->reg_ready;
  int v883 = v882[13];
  int v1085 = v883 + ((v881 - v883) & (~((v881 - v883) >> 31)));
  v828->timer = v1085;
  int v885 = v828->timer;
  int * v886 = v828->reg_ready;
  int v887 = v886[14];
  int v1087 = v887 + ((v885 - v887) & (~((v885 - v887) >> 31)));
  v828->timer = v1087;
  int v889 = v828->timer;
  int * v890 = v828->reg_ready;
  int v891 = v890[15];
  int v1089 = v891 + ((v889 - v891) & (~((v889 - v891) >> 31)));
  v828->timer = v1089;
  int v893 = v828->timer;
  int * v894 = v828->reg_ready;
  int v895 = v894[16];
  int v1091 = v895 + ((v893 - v895) & (~((v893 - v895) >> 31)));
  v828->timer = v1091;
  int v897 = v828->timer;
  int * v898 = v828->reg_ready;
  int v899 = v898[17];
  int v1093 = v899 + ((v897 - v899) & (~((v897 - v899) >> 31)));
  v828->timer = v1093;
  int v901 = v828->timer;
  int * v902 = v828->reg_ready;
  int v903 = v902[18];
  int v1095 = v903 + ((v901 - v903) & (~((v901 - v903) >> 31)));
  v828->timer = v1095;
  int v905 = v828->timer;
  int * v906 = v828->reg_ready;
  int v907 = v906[19];
  int v1097 = v907 + ((v905 - v907) & (~((v905 - v907) >> 31)));
  v828->timer = v1097;
  int v909 = v828->timer;
  int * v910 = v828->reg_ready;
  int v911 = v910[20];
  int v1099 = v911 + ((v909 - v911) & (~((v909 - v911) >> 31)));
  v828->timer = v1099;
  int v913 = v828->timer;
  int * v914 = v828->reg_ready;
  int v915 = v914[21];
  int v1101 = v915 + ((v913 - v915) & (~((v913 - v915) >> 31)));
  v828->timer = v1101;
  int v917 = v828->timer;
  int * v918 = v828->reg_ready;
  int v919 = v918[22];
  int v1103 = v919 + ((v917 - v919) & (~((v917 - v919) >> 31)));
  v828->timer = v1103;
  int v921 = v828->timer;
  int * v922 = v828->reg_ready;
  int v923 = v922[23];
  int v1105 = v923 + ((v921 - v923) & (~((v921 - v923) >> 31)));
  v828->timer = v1105;
  int v925 = v828->timer;
  int * v926 = v828->reg_ready;
  int v927 = v926[24];
  int v1107 = v927 + ((v925 - v927) & (~((v925 - v927) >> 31)));
  v828->timer = v1107;
  int v929 = v828->timer;
  int * v930 = v828->reg_ready;
  int v931 = v930[25];
  int v1109 = v931 + ((v929 - v931) & (~((v929 - v931) >> 31)));
  v828->timer = v1109;
  int v933 = v828->timer;
  int * v934 = v828->reg_ready;
  int v935 = v934[26];
  int v1111 = v935 + ((v933 - v935) & (~((v933 - v935) >> 31)));
  v828->timer = v1111;
  int v937 = v828->timer;
  int * v938 = v828->reg_ready;
  int v939 = v938[27];
  int v1113 = v939 + ((v937 - v939) & (~((v937 - v939) >> 31)));
  v828->timer = v1113;
  int v941 = v828->timer;
  int * v942 = v828->reg_ready;
  int v943 = v942[28];
  int v1115 = v943 + ((v941 - v943) & (~((v941 - v943) >> 31)));
  v828->timer = v1115;
  int v945 = v828->timer;
  int * v946 = v828->reg_ready;
  int v947 = v946[29];
  int v1117 = v947 + ((v945 - v947) & (~((v945 - v947) >> 31)));
  v828->timer = v1117;
  int v949 = v828->timer;
  int * v950 = v828->reg_ready;
  int v951 = v950[30];
  int v1119 = v951 + ((v949 - v951) & (~((v949 - v951) >> 31)));
  v828->timer = v1119;
  int v953 = v828->timer;
  int * v954 = v828->reg_ready;
  int v955 = v954[31];
  int v1121 = v955 + ((v953 - v955) & (~((v953 - v955) >> 31)));
  v828->timer = v1121;
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v44) {
  struct StateT * v45 = v44->a;
  int v46 = v45->timer;
  struct StateT * v47 = v44->b;
  int v48 = v47->timer;
  bool v279 = v46 == v48;
  squared_assert(v279);
  squared_assume(v279);
  struct StateT * v51 = v44->a;
  int v52 = v51->timer;
  int v281 = v52 + 1;
  v51->timer = v281;
  struct StateT * v54 = v44->b;
  int v55 = v54->timer;
  int v283 = v55 + 1;
  v54->timer = v283;
  struct StateT * v57 = v44->a;
  int * v58 = v57->reg_ready;
  int v59 = v58[12];
  int * v60 = v57->regs;
  int v61 = v60[12];
  int * v62 = v57->cache_tags;
  int v289 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
  int v63 = v62[v289];
  int v290 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + 1;
  int v64 = v62[v290];
  int v291 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
  int v65 = v62[v291];
  int v292 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v66 = v62[v292];
  int * v67 = v57->cache_vals;
  bool v293 = !(((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
  int v160;
  if (v293) {
    int * v68 = v57->cache_age;
    int v295 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
    int v69 = v68[v295];
    int v70 = v68[v289];
    int v296 = v70 + ((int)((unsigned int)(v70 - v69) >> 31));
    v68[v289] = v296;
    int * v72 = v57->cache_age;
    int v73 = v72[v290];
    int v298 = v73 + ((int)((unsigned int)(v73 - v69) >> 31));
    v72[v290] = v298;
    int * v75 = v57->cache_age;
    v75[v295] = 0;
    v160 = v295;
  } else {
    int * v78 = v57->cache_age;
    int v302 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
    int v79 = v78[v302];
    int * v80 = v57->cache_tags;
    int v81 = v80[v302];
    int v82 = v78[v290];
    int v83 = v80[v290];
    bool v304 = !(((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
    int v137;
    if (v304) {
      int * v84 = v57->cache_age;
      int v306 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
      int v85 = v84[v306];
      int v86 = v84[v291];
      int v307 = v86 + ((int)((unsigned int)(v86 - v85) >> 31));
      v84[v291] = v307;
      int * v88 = v57->cache_age;
      int v89 = v88[v292];
      int v309 = v89 + ((int)((unsigned int)(v89 - v85) >> 31));
      v88[v292] = v309;
      int * v91 = v57->cache_age;
      v91[v306] = 0;
      v137 = v306;
    } else {
      int * v94 = v57->cache_age;
      int v313 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
      int v95 = v94[v313];
      int * v96 = v57->cache_tags;
      int v97 = v96[v313];
      int v98 = v94[v292];
      int v99 = v96[v292];
      int * v100 = v57->cache_dirty;
      int v316 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v99 ^ -1) | (-(v99 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v101 = v100[v316];
      bool v317 = !(v101 == 0);
      if (v317) {
        int * v102 = v57->cache_tags;
        int v103 = v102[v316];
        int * v104 = v57->cache_vals;
        int v320 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v99 ^ -1) | (-(v99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v105 = v104[v320];
        int v321 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v99 ^ -1) | (-(v99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v106 = v104[v321];
        int * v107 = v57->mem;
        int v323 = v103 * 2;
        v107[v323] = v105;
        int * v109 = v57->mem;
        int v326 = (v103 * 2) + 1;
        v109[v326] = v106;
        ;
      } else {
        ;
      }
      int * v114 = v57->mem;
      int v331 = ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2;
      int v115 = v114[v331];
      int v332 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2) + 1;
      int v116 = v114[v332];
      int * v117 = v57->cache_vals;
      int v334 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v99 ^ -1) | (-(v99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v117[v334] = v115;
      int * v119 = v57->cache_vals;
      int v337 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2)) - (v98 + ((~(((v99 ^ -1) | (-(v99 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v119[v337] = v116;
      int * v121 = v57->cache_tags;
      int v340 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
      v121[v316] = v340;
      int * v123 = v57->cache_dirty;
      v123[v316] = 0;
      int * v125 = v57->cache_age;
      v125[v316] = 1;
      int * v127 = v57->cache_age;
      int v128 = v127[v316];
      int v129 = v127[v291];
      int v346 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
      v127[v291] = v346;
      int * v131 = v57->cache_age;
      int v132 = v131[v292];
      int v348 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
      v131[v292] = v348;
      int * v134 = v57->cache_age;
      v134[v316] = 0;
      v137 = v316;
    }
    int * v138 = v57->cache_vals;
    int v351 = v137 * 2;
    int v139 = v138[v351];
    int v352 = (v137 * 2) + 1;
    int v140 = v138[v352];
    int v353 = (((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v82 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v138[v353] = v139;
    int * v142 = v57->cache_vals;
    int v356 = ((((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v82 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v142[v356] = v140;
    int * v144 = v57->cache_tags;
    int v359 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v79 + ((~(((v81 ^ -1) | (-(v81 ^ -1))) >> 31)) & 2)) - (v82 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v360 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
    v144[v359] = v360;
    int * v146 = v57->cache_dirty;
    v146[v359] = 0;
    int * v148 = v57->cache_age;
    v148[v359] = 1;
    int * v150 = v57->cache_age;
    int v151 = v150[v359];
    int v152 = v150[v289];
    int v366 = v152 + ((int)((unsigned int)(v152 - v151) >> 31));
    v150[v289] = v366;
    int * v154 = v57->cache_age;
    int v155 = v154[v290];
    int v368 = v155 + ((int)((unsigned int)(v155 - v151) >> 31));
    v154[v290] = v368;
    int * v157 = v57->cache_age;
    v157[v359] = 0;
    v160 = v359;
  }
  int v371 = (v160 * 2) + (((int)((unsigned int)v61 >> 2)) & 1);
  int v161 = v67[v371];
  int * v162 = v57->reg_ready;
  int v374 = ((v59 + ((v52 - v59) & (~((v52 - v59) >> 31)))) + 1) + ((100 ^ (((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v66 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)))));
  v162[16] = v374;
  int * v164 = v57->regs;
  v164[16] = v161;
  struct StateT * v166 = v44->b;
  int * v167 = v166->reg_ready;
  int v168 = v167[12];
  int * v169 = v166->regs;
  int v170 = v169[12];
  int * v171 = v166->cache_tags;
  int v381 = (((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2;
  int v172 = v171[v381];
  int v382 = ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2) + 1;
  int v173 = v171[v382];
  int v383 = 4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2);
  int v174 = v171[v383];
  int v384 = (4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v175 = v171[v384];
  int * v176 = v166->cache_vals;
  bool v385 = !(((~(((v172 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v172 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) | (~(((v173 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v173 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31))) == 0);
  int v269;
  if (v385) {
    int * v177 = v166->cache_age;
    int v387 = ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2) + ((~(((v173 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v173 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) & 1);
    int v178 = v177[v387];
    int v179 = v177[v381];
    int v388 = v179 + ((int)((unsigned int)(v179 - v178) >> 31));
    v177[v381] = v388;
    int * v181 = v166->cache_age;
    int v182 = v181[v382];
    int v390 = v182 + ((int)((unsigned int)(v182 - v178) >> 31));
    v181[v382] = v390;
    int * v184 = v166->cache_age;
    v184[v387] = 0;
    v269 = v387;
  } else {
    int * v187 = v166->cache_age;
    int v394 = (((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2;
    int v188 = v187[v394];
    int * v189 = v166->cache_tags;
    int v190 = v189[v394];
    int v191 = v187[v382];
    int v192 = v189[v382];
    bool v396 = !(((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) | (~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31))) == 0);
    int v246;
    if (v396) {
      int * v193 = v166->cache_age;
      int v398 = (4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + ((~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) & 1);
      int v194 = v193[v398];
      int v195 = v193[v383];
      int v399 = v195 + ((int)((unsigned int)(v195 - v194) >> 31));
      v193[v383] = v399;
      int * v197 = v166->cache_age;
      int v198 = v197[v384];
      int v401 = v198 + ((int)((unsigned int)(v198 - v194) >> 31));
      v197[v384] = v401;
      int * v200 = v166->cache_age;
      v200[v398] = 0;
      v246 = v398;
    } else {
      int * v203 = v166->cache_age;
      int v405 = 4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2);
      int v204 = v203[v405];
      int * v205 = v166->cache_tags;
      int v206 = v205[v405];
      int v207 = v203[v384];
      int v208 = v205[v384];
      int * v209 = v166->cache_dirty;
      int v408 = (4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v207 + ((~(((v208 ^ -1) | (-(v208 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v210 = v209[v408];
      bool v409 = !(v210 == 0);
      if (v409) {
        int * v211 = v166->cache_tags;
        int v212 = v211[v408];
        int * v213 = v166->cache_vals;
        int v412 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v207 + ((~(((v208 ^ -1) | (-(v208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v214 = v213[v412];
        int v413 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v207 + ((~(((v208 ^ -1) | (-(v208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v215 = v213[v413];
        int * v216 = v166->mem;
        int v415 = v212 * 2;
        v216[v415] = v214;
        int * v218 = v166->mem;
        int v418 = (v212 * 2) + 1;
        v218[v418] = v215;
        ;
      } else {
        ;
      }
      int * v223 = v166->mem;
      int v423 = ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) * 2;
      int v224 = v223[v423];
      int v424 = (((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) * 2) + 1;
      int v225 = v223[v424];
      int * v226 = v166->cache_vals;
      int v426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v207 + ((~(((v208 ^ -1) | (-(v208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v226[v426] = v224;
      int * v228 = v166->cache_vals;
      int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v207 + ((~(((v208 ^ -1) | (-(v208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v228[v429] = v225;
      int * v230 = v166->cache_tags;
      int v432 = (int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1);
      v230[v408] = v432;
      int * v232 = v166->cache_dirty;
      v232[v408] = 0;
      int * v234 = v166->cache_age;
      v234[v408] = 1;
      int * v236 = v166->cache_age;
      int v237 = v236[v408];
      int v238 = v236[v383];
      int v438 = v238 + ((int)((unsigned int)(v238 - v237) >> 31));
      v236[v383] = v438;
      int * v240 = v166->cache_age;
      int v241 = v240[v384];
      int v440 = v241 + ((int)((unsigned int)(v241 - v237) >> 31));
      v240[v384] = v440;
      int * v243 = v166->cache_age;
      v243[v408] = 0;
      v246 = v408;
    }
    int * v247 = v166->cache_vals;
    int v443 = v246 * 2;
    int v248 = v247[v443];
    int v444 = (v246 * 2) + 1;
    int v249 = v247[v444];
    int v445 = (((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v247[v445] = v248;
    int * v251 = v166->cache_vals;
    int v448 = ((((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v251[v448] = v249;
    int * v253 = v166->cache_tags;
    int v451 = ((((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1)) & 1) * 2) + ((((v188 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2)) - (v191 + ((~(((v192 ^ -1) | (-(v192 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v452 = (int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1);
    v253[v451] = v452;
    int * v255 = v166->cache_dirty;
    v255[v451] = 0;
    int * v257 = v166->cache_age;
    v257[v451] = 1;
    int * v259 = v166->cache_age;
    int v260 = v259[v451];
    int v261 = v259[v381];
    int v458 = v261 + ((int)((unsigned int)(v261 - v260) >> 31));
    v259[v381] = v458;
    int * v263 = v166->cache_age;
    int v264 = v263[v382];
    int v460 = v264 + ((int)((unsigned int)(v264 - v260) >> 31));
    v263[v382] = v460;
    int * v266 = v166->cache_age;
    v266[v451] = 0;
    v269 = v451;
  }
  int v463 = (v269 * 2) + (((int)((unsigned int)v170 >> 2)) & 1);
  int v270 = v176[v463];
  int * v271 = v166->reg_ready;
  int v465 = ((v168 + ((v55 - v168) & (~((v55 - v168) >> 31)))) + 1) + ((100 ^ (((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) | (~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v172 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v172 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) | (~(((v173 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v173 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31)) | (~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v170 >> 2)) >> 1))))) >> 31))) & 104)))));
  v271[16] = v465;
  int * v273 = v166->regs;
  v273[16] = v270;
  struct StateT2 * v275 = slot_2(v44);
  return v275;
}

struct StateT2 * slot_6(struct StateT2 * v569) {
  struct StateT * v570 = v569->a;
  int v571 = v570->timer;
  struct StateT * v572 = v569->b;
  int v573 = v572->timer;
  bool v596 = v571 == v573;
  squared_assert(v596);
  squared_assume(v596);
  struct StateT * v576 = v569->a;
  int v577 = v576->timer;
  int v598 = v577 + 1;
  v576->timer = v598;
  struct StateT * v579 = v569->b;
  int v580 = v579->timer;
  int v600 = v580 + 1;
  v579->timer = v600;
  struct StateT * v582 = v569->a;
  int * v583 = v582->reg_ready;
  v583[18] = v598;
  int * v585 = v582->regs;
  v585[18] = 2;
  struct StateT * v587 = v569->b;
  int * v588 = v587->reg_ready;
  v588[18] = v600;
  int * v590 = v587->regs;
  v590[18] = 2;
  struct StateT2 * v592 = slot_5(v569);
  return v592;
}

struct StateT2 * slot_5(struct StateT2 * v676) {
  struct StateT * v677 = v676->a;
  int v678 = v677->timer;
  struct StateT * v679 = v676->b;
  int v680 = v679->timer;
  bool v694 = v678 == v680;
  squared_assert(v694);
  squared_assume(v694);
  struct StateT * v683 = v676->a;
  int v684 = v683->timer;
  int v696 = v684 + 1;
  v683->timer = v696;
  struct StateT * v686 = v676->b;
  int v687 = v686->timer;
  int v698 = v687 + 1;
  v686->timer = v698;
  return v676;
}

struct StateT2 * slot_4(struct StateT2 * v611) {
  struct StateT * v612 = v611->a;
  int v613 = v612->timer;
  struct StateT * v614 = v611->b;
  int v615 = v614->timer;
  bool v638 = v613 == v615;
  squared_assert(v638);
  squared_assume(v638);
  struct StateT * v618 = v611->a;
  int v619 = v618->timer;
  int v640 = v619 + 1;
  v618->timer = v640;
  struct StateT * v621 = v611->b;
  int v622 = v621->timer;
  int v642 = v622 + 1;
  v621->timer = v642;
  struct StateT * v624 = v611->a;
  int * v625 = v624->reg_ready;
  v625[18] = v640;
  int * v627 = v624->regs;
  v627[18] = 1;
  struct StateT * v629 = v611->b;
  int * v630 = v629->reg_ready;
  v630[18] = v642;
  int * v632 = v629->regs;
  v632[18] = 1;
  struct StateT2 * v634 = slot_5(v611);
  return v634;
}

struct StateT2 * slot_2(struct StateT2 * v470) {
  struct StateT * v471 = v470->a;
  int v472 = v471->timer;
  struct StateT * v473 = v470->b;
  int v474 = v473->timer;
  bool v497 = v472 == v474;
  squared_assert(v497);
  squared_assume(v497);
  struct StateT * v477 = v470->a;
  int v478 = v477->timer;
  int v499 = v478 + 1;
  v477->timer = v499;
  struct StateT * v480 = v470->b;
  int v481 = v480->timer;
  int v501 = v481 + 1;
  v480->timer = v501;
  struct StateT * v483 = v470->a;
  int * v484 = v483->reg_ready;
  v484[17] = v499;
  int * v486 = v483->regs;
  v486[17] = 10;
  struct StateT * v488 = v470->b;
  int * v489 = v488->reg_ready;
  v489[17] = v501;
  int * v491 = v488->regs;
  v491[17] = 10;
  struct StateT2 * v493 = slot_3(v470);
  return v493;
}

struct StateT2 * slot_3(struct StateT2 * v512) {
  struct StateT * v513 = v512->a;
  int v514 = v513->timer;
  struct StateT * v515 = v512->b;
  int v516 = v515->timer;
  bool v549 = v514 == v516;
  squared_assert(v549);
  squared_assume(v549);
  struct StateT * v519 = v512->a;
  int v520 = v519->timer;
  int v551 = v520 + 1;
  v519->timer = v551;
  struct StateT * v522 = v512->b;
  int v523 = v522->timer;
  int v553 = v523 + 1;
  v522->timer = v553;
  struct StateT * v525 = v512->a;
  int * v526 = v525->reg_ready;
  int * v528 = v525->regs;
  int v529 = v528[16];
  int v531 = v528[17];
  struct StateT * v532 = v512->b;
  int * v533 = v532->reg_ready;
  int * v535 = v532->regs;
  int v536 = v535[16];
  int v538 = v535[17];
  bool v562 = (v529 < v531) == (v536 < v538);
  squared_diverged(v562);
  squared_assume(v562);
  bool v563 = v529 < v531;
  struct StateT2 * v545;
  if (v563) {
    struct StateT2 * v541 = slot_6(v512);
    v545 = v541;
  } else {
    struct StateT2 * v543 = slot_4(v512);
    v545 = v543;
  }
  return v545;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v29 = v4 == v6;
  squared_assert(v29);
  squared_assume(v29);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v31 = v10 + 1;
  v9->timer = v31;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v33 = v13 + 1;
  v12->timer = v33;
  struct StateT * v15 = v2->a;
  int * v16 = v15->reg_ready;
  v16[12] = v31;
  int * v18 = v15->regs;
  v18[12] = 80;
  struct StateT * v20 = v2->b;
  int * v21 = v20->reg_ready;
  v21[12] = v33;
  int * v23 = v20->regs;
  v23[12] = 80;
  struct StateT2 * v25 = slot_1(v2);
  return v25;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}