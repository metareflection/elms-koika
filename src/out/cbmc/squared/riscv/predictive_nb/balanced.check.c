// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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
struct StateT2 * slot_8(struct StateT2 * v739);
struct StateT2 * slot_6(struct StateT2 * v674);
struct StateT2 * slot_5(struct StateT2 * v596);
struct StateT2 * slot_4(struct StateT2 * v536);
struct StateT2 * slot_2(struct StateT2 * v470);
struct StateT2 * slot_3(struct StateT2 * v512);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v762 = v1->a;
  int v763 = v762->timer;
  int * v764 = v762->reg_ready;
  int v765 = v764[0];
  int v1026 = v765 + ((v763 - v765) & (~((v763 - v765) >> 31)));
  v762->timer = v1026;
  int v767 = v762->timer;
  int * v768 = v762->reg_ready;
  int v769 = v768[1];
  int v1029 = v769 + ((v767 - v769) & (~((v767 - v769) >> 31)));
  v762->timer = v1029;
  int v771 = v762->timer;
  int * v772 = v762->reg_ready;
  int v773 = v772[2];
  int v1032 = v773 + ((v771 - v773) & (~((v771 - v773) >> 31)));
  v762->timer = v1032;
  int v775 = v762->timer;
  int * v776 = v762->reg_ready;
  int v777 = v776[3];
  int v1035 = v777 + ((v775 - v777) & (~((v775 - v777) >> 31)));
  v762->timer = v1035;
  int v779 = v762->timer;
  int * v780 = v762->reg_ready;
  int v781 = v780[4];
  int v1038 = v781 + ((v779 - v781) & (~((v779 - v781) >> 31)));
  v762->timer = v1038;
  int v783 = v762->timer;
  int * v784 = v762->reg_ready;
  int v785 = v784[5];
  int v1041 = v785 + ((v783 - v785) & (~((v783 - v785) >> 31)));
  v762->timer = v1041;
  int v787 = v762->timer;
  int * v788 = v762->reg_ready;
  int v789 = v788[6];
  int v1044 = v789 + ((v787 - v789) & (~((v787 - v789) >> 31)));
  v762->timer = v1044;
  int v791 = v762->timer;
  int * v792 = v762->reg_ready;
  int v793 = v792[7];
  int v1047 = v793 + ((v791 - v793) & (~((v791 - v793) >> 31)));
  v762->timer = v1047;
  int v795 = v762->timer;
  int * v796 = v762->reg_ready;
  int v797 = v796[8];
  int v1050 = v797 + ((v795 - v797) & (~((v795 - v797) >> 31)));
  v762->timer = v1050;
  int v799 = v762->timer;
  int * v800 = v762->reg_ready;
  int v801 = v800[9];
  int v1053 = v801 + ((v799 - v801) & (~((v799 - v801) >> 31)));
  v762->timer = v1053;
  int v803 = v762->timer;
  int * v804 = v762->reg_ready;
  int v805 = v804[10];
  int v1056 = v805 + ((v803 - v805) & (~((v803 - v805) >> 31)));
  v762->timer = v1056;
  int v807 = v762->timer;
  int * v808 = v762->reg_ready;
  int v809 = v808[11];
  int v1059 = v809 + ((v807 - v809) & (~((v807 - v809) >> 31)));
  v762->timer = v1059;
  int v811 = v762->timer;
  int * v812 = v762->reg_ready;
  int v813 = v812[12];
  int v1062 = v813 + ((v811 - v813) & (~((v811 - v813) >> 31)));
  v762->timer = v1062;
  int v815 = v762->timer;
  int * v816 = v762->reg_ready;
  int v817 = v816[13];
  int v1065 = v817 + ((v815 - v817) & (~((v815 - v817) >> 31)));
  v762->timer = v1065;
  int v819 = v762->timer;
  int * v820 = v762->reg_ready;
  int v821 = v820[14];
  int v1068 = v821 + ((v819 - v821) & (~((v819 - v821) >> 31)));
  v762->timer = v1068;
  int v823 = v762->timer;
  int * v824 = v762->reg_ready;
  int v825 = v824[15];
  int v1071 = v825 + ((v823 - v825) & (~((v823 - v825) >> 31)));
  v762->timer = v1071;
  int v827 = v762->timer;
  int * v828 = v762->reg_ready;
  int v829 = v828[16];
  int v1074 = v829 + ((v827 - v829) & (~((v827 - v829) >> 31)));
  v762->timer = v1074;
  int v831 = v762->timer;
  int * v832 = v762->reg_ready;
  int v833 = v832[17];
  int v1077 = v833 + ((v831 - v833) & (~((v831 - v833) >> 31)));
  v762->timer = v1077;
  int v835 = v762->timer;
  int * v836 = v762->reg_ready;
  int v837 = v836[18];
  int v1080 = v837 + ((v835 - v837) & (~((v835 - v837) >> 31)));
  v762->timer = v1080;
  int v839 = v762->timer;
  int * v840 = v762->reg_ready;
  int v841 = v840[19];
  int v1083 = v841 + ((v839 - v841) & (~((v839 - v841) >> 31)));
  v762->timer = v1083;
  int v843 = v762->timer;
  int * v844 = v762->reg_ready;
  int v845 = v844[20];
  int v1086 = v845 + ((v843 - v845) & (~((v843 - v845) >> 31)));
  v762->timer = v1086;
  int v847 = v762->timer;
  int * v848 = v762->reg_ready;
  int v849 = v848[21];
  int v1089 = v849 + ((v847 - v849) & (~((v847 - v849) >> 31)));
  v762->timer = v1089;
  int v851 = v762->timer;
  int * v852 = v762->reg_ready;
  int v853 = v852[22];
  int v1092 = v853 + ((v851 - v853) & (~((v851 - v853) >> 31)));
  v762->timer = v1092;
  int v855 = v762->timer;
  int * v856 = v762->reg_ready;
  int v857 = v856[23];
  int v1095 = v857 + ((v855 - v857) & (~((v855 - v857) >> 31)));
  v762->timer = v1095;
  int v859 = v762->timer;
  int * v860 = v762->reg_ready;
  int v861 = v860[24];
  int v1098 = v861 + ((v859 - v861) & (~((v859 - v861) >> 31)));
  v762->timer = v1098;
  int v863 = v762->timer;
  int * v864 = v762->reg_ready;
  int v865 = v864[25];
  int v1101 = v865 + ((v863 - v865) & (~((v863 - v865) >> 31)));
  v762->timer = v1101;
  int v867 = v762->timer;
  int * v868 = v762->reg_ready;
  int v869 = v868[26];
  int v1104 = v869 + ((v867 - v869) & (~((v867 - v869) >> 31)));
  v762->timer = v1104;
  int v871 = v762->timer;
  int * v872 = v762->reg_ready;
  int v873 = v872[27];
  int v1107 = v873 + ((v871 - v873) & (~((v871 - v873) >> 31)));
  v762->timer = v1107;
  int v875 = v762->timer;
  int * v876 = v762->reg_ready;
  int v877 = v876[28];
  int v1110 = v877 + ((v875 - v877) & (~((v875 - v877) >> 31)));
  v762->timer = v1110;
  int v879 = v762->timer;
  int * v880 = v762->reg_ready;
  int v881 = v880[29];
  int v1113 = v881 + ((v879 - v881) & (~((v879 - v881) >> 31)));
  v762->timer = v1113;
  int v883 = v762->timer;
  int * v884 = v762->reg_ready;
  int v885 = v884[30];
  int v1116 = v885 + ((v883 - v885) & (~((v883 - v885) >> 31)));
  v762->timer = v1116;
  int v887 = v762->timer;
  int * v888 = v762->reg_ready;
  int v889 = v888[31];
  int v1119 = v889 + ((v887 - v889) & (~((v887 - v889) >> 31)));
  v762->timer = v1119;
  struct StateT * v891 = v1->b;
  int v892 = v891->timer;
  int * v893 = v891->reg_ready;
  int v894 = v893[0];
  int v1122 = v894 + ((v892 - v894) & (~((v892 - v894) >> 31)));
  v891->timer = v1122;
  int v896 = v891->timer;
  int * v897 = v891->reg_ready;
  int v898 = v897[1];
  int v1124 = v898 + ((v896 - v898) & (~((v896 - v898) >> 31)));
  v891->timer = v1124;
  int v900 = v891->timer;
  int * v901 = v891->reg_ready;
  int v902 = v901[2];
  int v1126 = v902 + ((v900 - v902) & (~((v900 - v902) >> 31)));
  v891->timer = v1126;
  int v904 = v891->timer;
  int * v905 = v891->reg_ready;
  int v906 = v905[3];
  int v1128 = v906 + ((v904 - v906) & (~((v904 - v906) >> 31)));
  v891->timer = v1128;
  int v908 = v891->timer;
  int * v909 = v891->reg_ready;
  int v910 = v909[4];
  int v1130 = v910 + ((v908 - v910) & (~((v908 - v910) >> 31)));
  v891->timer = v1130;
  int v912 = v891->timer;
  int * v913 = v891->reg_ready;
  int v914 = v913[5];
  int v1132 = v914 + ((v912 - v914) & (~((v912 - v914) >> 31)));
  v891->timer = v1132;
  int v916 = v891->timer;
  int * v917 = v891->reg_ready;
  int v918 = v917[6];
  int v1134 = v918 + ((v916 - v918) & (~((v916 - v918) >> 31)));
  v891->timer = v1134;
  int v920 = v891->timer;
  int * v921 = v891->reg_ready;
  int v922 = v921[7];
  int v1136 = v922 + ((v920 - v922) & (~((v920 - v922) >> 31)));
  v891->timer = v1136;
  int v924 = v891->timer;
  int * v925 = v891->reg_ready;
  int v926 = v925[8];
  int v1138 = v926 + ((v924 - v926) & (~((v924 - v926) >> 31)));
  v891->timer = v1138;
  int v928 = v891->timer;
  int * v929 = v891->reg_ready;
  int v930 = v929[9];
  int v1140 = v930 + ((v928 - v930) & (~((v928 - v930) >> 31)));
  v891->timer = v1140;
  int v932 = v891->timer;
  int * v933 = v891->reg_ready;
  int v934 = v933[10];
  int v1142 = v934 + ((v932 - v934) & (~((v932 - v934) >> 31)));
  v891->timer = v1142;
  int v936 = v891->timer;
  int * v937 = v891->reg_ready;
  int v938 = v937[11];
  int v1144 = v938 + ((v936 - v938) & (~((v936 - v938) >> 31)));
  v891->timer = v1144;
  int v940 = v891->timer;
  int * v941 = v891->reg_ready;
  int v942 = v941[12];
  int v1146 = v942 + ((v940 - v942) & (~((v940 - v942) >> 31)));
  v891->timer = v1146;
  int v944 = v891->timer;
  int * v945 = v891->reg_ready;
  int v946 = v945[13];
  int v1148 = v946 + ((v944 - v946) & (~((v944 - v946) >> 31)));
  v891->timer = v1148;
  int v948 = v891->timer;
  int * v949 = v891->reg_ready;
  int v950 = v949[14];
  int v1150 = v950 + ((v948 - v950) & (~((v948 - v950) >> 31)));
  v891->timer = v1150;
  int v952 = v891->timer;
  int * v953 = v891->reg_ready;
  int v954 = v953[15];
  int v1152 = v954 + ((v952 - v954) & (~((v952 - v954) >> 31)));
  v891->timer = v1152;
  int v956 = v891->timer;
  int * v957 = v891->reg_ready;
  int v958 = v957[16];
  int v1154 = v958 + ((v956 - v958) & (~((v956 - v958) >> 31)));
  v891->timer = v1154;
  int v960 = v891->timer;
  int * v961 = v891->reg_ready;
  int v962 = v961[17];
  int v1156 = v962 + ((v960 - v962) & (~((v960 - v962) >> 31)));
  v891->timer = v1156;
  int v964 = v891->timer;
  int * v965 = v891->reg_ready;
  int v966 = v965[18];
  int v1158 = v966 + ((v964 - v966) & (~((v964 - v966) >> 31)));
  v891->timer = v1158;
  int v968 = v891->timer;
  int * v969 = v891->reg_ready;
  int v970 = v969[19];
  int v1160 = v970 + ((v968 - v970) & (~((v968 - v970) >> 31)));
  v891->timer = v1160;
  int v972 = v891->timer;
  int * v973 = v891->reg_ready;
  int v974 = v973[20];
  int v1162 = v974 + ((v972 - v974) & (~((v972 - v974) >> 31)));
  v891->timer = v1162;
  int v976 = v891->timer;
  int * v977 = v891->reg_ready;
  int v978 = v977[21];
  int v1164 = v978 + ((v976 - v978) & (~((v976 - v978) >> 31)));
  v891->timer = v1164;
  int v980 = v891->timer;
  int * v981 = v891->reg_ready;
  int v982 = v981[22];
  int v1166 = v982 + ((v980 - v982) & (~((v980 - v982) >> 31)));
  v891->timer = v1166;
  int v984 = v891->timer;
  int * v985 = v891->reg_ready;
  int v986 = v985[23];
  int v1168 = v986 + ((v984 - v986) & (~((v984 - v986) >> 31)));
  v891->timer = v1168;
  int v988 = v891->timer;
  int * v989 = v891->reg_ready;
  int v990 = v989[24];
  int v1170 = v990 + ((v988 - v990) & (~((v988 - v990) >> 31)));
  v891->timer = v1170;
  int v992 = v891->timer;
  int * v993 = v891->reg_ready;
  int v994 = v993[25];
  int v1172 = v994 + ((v992 - v994) & (~((v992 - v994) >> 31)));
  v891->timer = v1172;
  int v996 = v891->timer;
  int * v997 = v891->reg_ready;
  int v998 = v997[26];
  int v1174 = v998 + ((v996 - v998) & (~((v996 - v998) >> 31)));
  v891->timer = v1174;
  int v1000 = v891->timer;
  int * v1001 = v891->reg_ready;
  int v1002 = v1001[27];
  int v1176 = v1002 + ((v1000 - v1002) & (~((v1000 - v1002) >> 31)));
  v891->timer = v1176;
  int v1004 = v891->timer;
  int * v1005 = v891->reg_ready;
  int v1006 = v1005[28];
  int v1178 = v1006 + ((v1004 - v1006) & (~((v1004 - v1006) >> 31)));
  v891->timer = v1178;
  int v1008 = v891->timer;
  int * v1009 = v891->reg_ready;
  int v1010 = v1009[29];
  int v1180 = v1010 + ((v1008 - v1010) & (~((v1008 - v1010) >> 31)));
  v891->timer = v1180;
  int v1012 = v891->timer;
  int * v1013 = v891->reg_ready;
  int v1014 = v1013[30];
  int v1182 = v1014 + ((v1012 - v1014) & (~((v1012 - v1014) >> 31)));
  v891->timer = v1182;
  int v1016 = v891->timer;
  int * v1017 = v891->reg_ready;
  int v1018 = v1017[31];
  int v1184 = v1018 + ((v1016 - v1018) & (~((v1016 - v1018) >> 31)));
  v891->timer = v1184;
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

struct StateT2 * slot_8(struct StateT2 * v739) {
  struct StateT * v740 = v739->a;
  int v741 = v740->timer;
  struct StateT * v742 = v739->b;
  int v743 = v742->timer;
  bool v757 = v741 == v743;
  squared_assert(v757);
  squared_assume(v757);
  struct StateT * v746 = v739->a;
  int v747 = v746->timer;
  int v759 = v747 + 1;
  v746->timer = v759;
  struct StateT * v749 = v739->b;
  int v750 = v749->timer;
  int v761 = v750 + 1;
  v749->timer = v761;
  return v739;
}

struct StateT2 * slot_6(struct StateT2 * v674) {
  struct StateT * v675 = v674->a;
  int v676 = v675->timer;
  struct StateT * v677 = v674->b;
  int v678 = v677->timer;
  bool v701 = v676 == v678;
  squared_assert(v701);
  squared_assume(v701);
  struct StateT * v681 = v674->a;
  int v682 = v681->timer;
  int v703 = v682 + 1;
  v681->timer = v703;
  struct StateT * v684 = v674->b;
  int v685 = v684->timer;
  int v705 = v685 + 1;
  v684->timer = v705;
  struct StateT * v687 = v674->a;
  int * v688 = v687->reg_ready;
  v688[18] = v703;
  int * v690 = v687->regs;
  v690[18] = 2;
  struct StateT * v692 = v674->b;
  int * v693 = v692->reg_ready;
  v693[18] = v705;
  int * v695 = v692->regs;
  v695[18] = 2;
  struct StateT2 * v697 = slot_8(v674);
  return v697;
}

struct StateT2 * slot_5(struct StateT2 * v596) {
  struct StateT * v597 = v596->a;
  int v598 = v597->timer;
  struct StateT * v599 = v596->b;
  int v600 = v599->timer;
  bool v643 = v598 == v600;
  squared_assert(v643);
  squared_assume(v643);
  struct StateT * v603 = v596->a;
  int * v604 = v603->regs;
  int v605 = v604[16];
  int v606 = v604[17];
  struct StateT * v607 = v596->b;
  int * v608 = v607->regs;
  int v609 = v608[16];
  int v610 = v608[17];
  bool v650 = (v605 < v606) == (v609 < v610);
  squared_diverged(v650);
  squared_assume(v650);
  bool v651 = v605 < v606;
  struct StateT2 * v639;
  if (v651) {
    struct StateT * v613 = v596->a;
    int v614 = v613->timer;
    int v653 = v614 + 15;
    v613->timer = v653;
    int * v616 = v613->saved_regs;
    int v617 = v616[18];
    int * v618 = v613->regs;
    v618[18] = v617;
    struct StateT * v620 = v596->b;
    int v621 = v620->timer;
    int v659 = v621 + 15;
    v620->timer = v659;
    int * v623 = v620->saved_regs;
    int v624 = v623[18];
    int * v625 = v620->regs;
    v625[18] = v624;
    struct StateT * v627 = v596->a;
    int * v628 = v627->reg_ready;
    int v629 = v627->timer;
    v628[18] = v629;
    struct StateT * v631 = v596->b;
    int * v632 = v631->reg_ready;
    int v633 = v631->timer;
    v632[18] = v633;
    struct StateT2 * v635 = slot_6(v596);
    v639 = v635;
  } else {
    struct StateT2 * v637 = slot_8(v596);
    v639 = v637;
  }
  return v639;
}

struct StateT2 * slot_4(struct StateT2 * v536) {
  struct StateT * v537 = v536->a;
  int v538 = v537->timer;
  struct StateT * v539 = v536->b;
  int v540 = v539->timer;
  bool v573 = v538 == v540;
  squared_assert(v573);
  squared_assume(v573);
  struct StateT * v543 = v536->a;
  int * v544 = v543->saved_regs;
  int * v545 = v543->regs;
  int v546 = v545[18];
  v544[18] = v546;
  struct StateT * v548 = v536->b;
  int * v549 = v548->saved_regs;
  int * v550 = v548->regs;
  int v551 = v550[18];
  v549[18] = v551;
  struct StateT * v553 = v536->a;
  int v554 = v553->timer;
  int v584 = v554 + 1;
  v553->timer = v584;
  struct StateT * v556 = v536->b;
  int v557 = v556->timer;
  int v586 = v557 + 1;
  v556->timer = v586;
  struct StateT * v559 = v536->a;
  int * v560 = v559->reg_ready;
  v560[18] = v584;
  int * v562 = v559->regs;
  v562[18] = 1;
  struct StateT * v564 = v536->b;
  int * v565 = v564->reg_ready;
  v565[18] = v586;
  int * v567 = v564->regs;
  v567[18] = 1;
  struct StateT2 * v569 = slot_5(v536);
  return v569;
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
  bool v529 = v514 == v516;
  squared_assert(v529);
  squared_assume(v529);
  struct StateT * v519 = v512->a;
  int v520 = v519->timer;
  int v531 = v520 + 1;
  v519->timer = v531;
  struct StateT * v522 = v512->b;
  int v523 = v522->timer;
  int v533 = v523 + 1;
  v522->timer = v533;
  struct StateT2 * v525 = slot_4(v512);
  return v525;
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