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
struct StateT2 * slot_1(struct StateT2 * v48);
struct StateT2 * slot_6(struct StateT2 * v681);
struct StateT2 * slot_5(struct StateT2 * v798);
struct StateT2 * slot_4(struct StateT2 * v727);
struct StateT2 * slot_2(struct StateT2 * v568);
struct StateT2 * slot_7(struct StateT2 * v773);
struct StateT2 * slot_3(struct StateT2 * v614);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v823 = v1->a;
  int v824 = v823->timer;
  int * v825 = v823->reg_ready;
  int v826 = v825[0];
  int v1087 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v823->timer = v1087;
  int v828 = v823->timer;
  int * v829 = v823->reg_ready;
  int v830 = v829[1];
  int v1090 = v830 + ((v828 - v830) & (~((v828 - v830) >> 31)));
  v823->timer = v1090;
  int v832 = v823->timer;
  int * v833 = v823->reg_ready;
  int v834 = v833[2];
  int v1093 = v834 + ((v832 - v834) & (~((v832 - v834) >> 31)));
  v823->timer = v1093;
  int v836 = v823->timer;
  int * v837 = v823->reg_ready;
  int v838 = v837[3];
  int v1096 = v838 + ((v836 - v838) & (~((v836 - v838) >> 31)));
  v823->timer = v1096;
  int v840 = v823->timer;
  int * v841 = v823->reg_ready;
  int v842 = v841[4];
  int v1099 = v842 + ((v840 - v842) & (~((v840 - v842) >> 31)));
  v823->timer = v1099;
  int v844 = v823->timer;
  int * v845 = v823->reg_ready;
  int v846 = v845[5];
  int v1102 = v846 + ((v844 - v846) & (~((v844 - v846) >> 31)));
  v823->timer = v1102;
  int v848 = v823->timer;
  int * v849 = v823->reg_ready;
  int v850 = v849[6];
  int v1105 = v850 + ((v848 - v850) & (~((v848 - v850) >> 31)));
  v823->timer = v1105;
  int v852 = v823->timer;
  int * v853 = v823->reg_ready;
  int v854 = v853[7];
  int v1108 = v854 + ((v852 - v854) & (~((v852 - v854) >> 31)));
  v823->timer = v1108;
  int v856 = v823->timer;
  int * v857 = v823->reg_ready;
  int v858 = v857[8];
  int v1111 = v858 + ((v856 - v858) & (~((v856 - v858) >> 31)));
  v823->timer = v1111;
  int v860 = v823->timer;
  int * v861 = v823->reg_ready;
  int v862 = v861[9];
  int v1114 = v862 + ((v860 - v862) & (~((v860 - v862) >> 31)));
  v823->timer = v1114;
  int v864 = v823->timer;
  int * v865 = v823->reg_ready;
  int v866 = v865[10];
  int v1117 = v866 + ((v864 - v866) & (~((v864 - v866) >> 31)));
  v823->timer = v1117;
  int v868 = v823->timer;
  int * v869 = v823->reg_ready;
  int v870 = v869[11];
  int v1120 = v870 + ((v868 - v870) & (~((v868 - v870) >> 31)));
  v823->timer = v1120;
  int v872 = v823->timer;
  int * v873 = v823->reg_ready;
  int v874 = v873[12];
  int v1123 = v874 + ((v872 - v874) & (~((v872 - v874) >> 31)));
  v823->timer = v1123;
  int v876 = v823->timer;
  int * v877 = v823->reg_ready;
  int v878 = v877[13];
  int v1126 = v878 + ((v876 - v878) & (~((v876 - v878) >> 31)));
  v823->timer = v1126;
  int v880 = v823->timer;
  int * v881 = v823->reg_ready;
  int v882 = v881[14];
  int v1129 = v882 + ((v880 - v882) & (~((v880 - v882) >> 31)));
  v823->timer = v1129;
  int v884 = v823->timer;
  int * v885 = v823->reg_ready;
  int v886 = v885[15];
  int v1132 = v886 + ((v884 - v886) & (~((v884 - v886) >> 31)));
  v823->timer = v1132;
  int v888 = v823->timer;
  int * v889 = v823->reg_ready;
  int v890 = v889[16];
  int v1135 = v890 + ((v888 - v890) & (~((v888 - v890) >> 31)));
  v823->timer = v1135;
  int v892 = v823->timer;
  int * v893 = v823->reg_ready;
  int v894 = v893[17];
  int v1138 = v894 + ((v892 - v894) & (~((v892 - v894) >> 31)));
  v823->timer = v1138;
  int v896 = v823->timer;
  int * v897 = v823->reg_ready;
  int v898 = v897[18];
  int v1141 = v898 + ((v896 - v898) & (~((v896 - v898) >> 31)));
  v823->timer = v1141;
  int v900 = v823->timer;
  int * v901 = v823->reg_ready;
  int v902 = v901[19];
  int v1144 = v902 + ((v900 - v902) & (~((v900 - v902) >> 31)));
  v823->timer = v1144;
  int v904 = v823->timer;
  int * v905 = v823->reg_ready;
  int v906 = v905[20];
  int v1147 = v906 + ((v904 - v906) & (~((v904 - v906) >> 31)));
  v823->timer = v1147;
  int v908 = v823->timer;
  int * v909 = v823->reg_ready;
  int v910 = v909[21];
  int v1150 = v910 + ((v908 - v910) & (~((v908 - v910) >> 31)));
  v823->timer = v1150;
  int v912 = v823->timer;
  int * v913 = v823->reg_ready;
  int v914 = v913[22];
  int v1153 = v914 + ((v912 - v914) & (~((v912 - v914) >> 31)));
  v823->timer = v1153;
  int v916 = v823->timer;
  int * v917 = v823->reg_ready;
  int v918 = v917[23];
  int v1156 = v918 + ((v916 - v918) & (~((v916 - v918) >> 31)));
  v823->timer = v1156;
  int v920 = v823->timer;
  int * v921 = v823->reg_ready;
  int v922 = v921[24];
  int v1159 = v922 + ((v920 - v922) & (~((v920 - v922) >> 31)));
  v823->timer = v1159;
  int v924 = v823->timer;
  int * v925 = v823->reg_ready;
  int v926 = v925[25];
  int v1162 = v926 + ((v924 - v926) & (~((v924 - v926) >> 31)));
  v823->timer = v1162;
  int v928 = v823->timer;
  int * v929 = v823->reg_ready;
  int v930 = v929[26];
  int v1165 = v930 + ((v928 - v930) & (~((v928 - v930) >> 31)));
  v823->timer = v1165;
  int v932 = v823->timer;
  int * v933 = v823->reg_ready;
  int v934 = v933[27];
  int v1168 = v934 + ((v932 - v934) & (~((v932 - v934) >> 31)));
  v823->timer = v1168;
  int v936 = v823->timer;
  int * v937 = v823->reg_ready;
  int v938 = v937[28];
  int v1171 = v938 + ((v936 - v938) & (~((v936 - v938) >> 31)));
  v823->timer = v1171;
  int v940 = v823->timer;
  int * v941 = v823->reg_ready;
  int v942 = v941[29];
  int v1174 = v942 + ((v940 - v942) & (~((v940 - v942) >> 31)));
  v823->timer = v1174;
  int v944 = v823->timer;
  int * v945 = v823->reg_ready;
  int v946 = v945[30];
  int v1177 = v946 + ((v944 - v946) & (~((v944 - v946) >> 31)));
  v823->timer = v1177;
  int v948 = v823->timer;
  int * v949 = v823->reg_ready;
  int v950 = v949[31];
  int v1180 = v950 + ((v948 - v950) & (~((v948 - v950) >> 31)));
  v823->timer = v1180;
  struct StateT * v952 = v1->b;
  int v953 = v952->timer;
  int * v954 = v952->reg_ready;
  int v955 = v954[0];
  int v1183 = v955 + ((v953 - v955) & (~((v953 - v955) >> 31)));
  v952->timer = v1183;
  int v957 = v952->timer;
  int * v958 = v952->reg_ready;
  int v959 = v958[1];
  int v1185 = v959 + ((v957 - v959) & (~((v957 - v959) >> 31)));
  v952->timer = v1185;
  int v961 = v952->timer;
  int * v962 = v952->reg_ready;
  int v963 = v962[2];
  int v1187 = v963 + ((v961 - v963) & (~((v961 - v963) >> 31)));
  v952->timer = v1187;
  int v965 = v952->timer;
  int * v966 = v952->reg_ready;
  int v967 = v966[3];
  int v1189 = v967 + ((v965 - v967) & (~((v965 - v967) >> 31)));
  v952->timer = v1189;
  int v969 = v952->timer;
  int * v970 = v952->reg_ready;
  int v971 = v970[4];
  int v1191 = v971 + ((v969 - v971) & (~((v969 - v971) >> 31)));
  v952->timer = v1191;
  int v973 = v952->timer;
  int * v974 = v952->reg_ready;
  int v975 = v974[5];
  int v1193 = v975 + ((v973 - v975) & (~((v973 - v975) >> 31)));
  v952->timer = v1193;
  int v977 = v952->timer;
  int * v978 = v952->reg_ready;
  int v979 = v978[6];
  int v1195 = v979 + ((v977 - v979) & (~((v977 - v979) >> 31)));
  v952->timer = v1195;
  int v981 = v952->timer;
  int * v982 = v952->reg_ready;
  int v983 = v982[7];
  int v1197 = v983 + ((v981 - v983) & (~((v981 - v983) >> 31)));
  v952->timer = v1197;
  int v985 = v952->timer;
  int * v986 = v952->reg_ready;
  int v987 = v986[8];
  int v1199 = v987 + ((v985 - v987) & (~((v985 - v987) >> 31)));
  v952->timer = v1199;
  int v989 = v952->timer;
  int * v990 = v952->reg_ready;
  int v991 = v990[9];
  int v1201 = v991 + ((v989 - v991) & (~((v989 - v991) >> 31)));
  v952->timer = v1201;
  int v993 = v952->timer;
  int * v994 = v952->reg_ready;
  int v995 = v994[10];
  int v1203 = v995 + ((v993 - v995) & (~((v993 - v995) >> 31)));
  v952->timer = v1203;
  int v997 = v952->timer;
  int * v998 = v952->reg_ready;
  int v999 = v998[11];
  int v1205 = v999 + ((v997 - v999) & (~((v997 - v999) >> 31)));
  v952->timer = v1205;
  int v1001 = v952->timer;
  int * v1002 = v952->reg_ready;
  int v1003 = v1002[12];
  int v1207 = v1003 + ((v1001 - v1003) & (~((v1001 - v1003) >> 31)));
  v952->timer = v1207;
  int v1005 = v952->timer;
  int * v1006 = v952->reg_ready;
  int v1007 = v1006[13];
  int v1209 = v1007 + ((v1005 - v1007) & (~((v1005 - v1007) >> 31)));
  v952->timer = v1209;
  int v1009 = v952->timer;
  int * v1010 = v952->reg_ready;
  int v1011 = v1010[14];
  int v1211 = v1011 + ((v1009 - v1011) & (~((v1009 - v1011) >> 31)));
  v952->timer = v1211;
  int v1013 = v952->timer;
  int * v1014 = v952->reg_ready;
  int v1015 = v1014[15];
  int v1213 = v1015 + ((v1013 - v1015) & (~((v1013 - v1015) >> 31)));
  v952->timer = v1213;
  int v1017 = v952->timer;
  int * v1018 = v952->reg_ready;
  int v1019 = v1018[16];
  int v1215 = v1019 + ((v1017 - v1019) & (~((v1017 - v1019) >> 31)));
  v952->timer = v1215;
  int v1021 = v952->timer;
  int * v1022 = v952->reg_ready;
  int v1023 = v1022[17];
  int v1217 = v1023 + ((v1021 - v1023) & (~((v1021 - v1023) >> 31)));
  v952->timer = v1217;
  int v1025 = v952->timer;
  int * v1026 = v952->reg_ready;
  int v1027 = v1026[18];
  int v1219 = v1027 + ((v1025 - v1027) & (~((v1025 - v1027) >> 31)));
  v952->timer = v1219;
  int v1029 = v952->timer;
  int * v1030 = v952->reg_ready;
  int v1031 = v1030[19];
  int v1221 = v1031 + ((v1029 - v1031) & (~((v1029 - v1031) >> 31)));
  v952->timer = v1221;
  int v1033 = v952->timer;
  int * v1034 = v952->reg_ready;
  int v1035 = v1034[20];
  int v1223 = v1035 + ((v1033 - v1035) & (~((v1033 - v1035) >> 31)));
  v952->timer = v1223;
  int v1037 = v952->timer;
  int * v1038 = v952->reg_ready;
  int v1039 = v1038[21];
  int v1225 = v1039 + ((v1037 - v1039) & (~((v1037 - v1039) >> 31)));
  v952->timer = v1225;
  int v1041 = v952->timer;
  int * v1042 = v952->reg_ready;
  int v1043 = v1042[22];
  int v1227 = v1043 + ((v1041 - v1043) & (~((v1041 - v1043) >> 31)));
  v952->timer = v1227;
  int v1045 = v952->timer;
  int * v1046 = v952->reg_ready;
  int v1047 = v1046[23];
  int v1229 = v1047 + ((v1045 - v1047) & (~((v1045 - v1047) >> 31)));
  v952->timer = v1229;
  int v1049 = v952->timer;
  int * v1050 = v952->reg_ready;
  int v1051 = v1050[24];
  int v1231 = v1051 + ((v1049 - v1051) & (~((v1049 - v1051) >> 31)));
  v952->timer = v1231;
  int v1053 = v952->timer;
  int * v1054 = v952->reg_ready;
  int v1055 = v1054[25];
  int v1233 = v1055 + ((v1053 - v1055) & (~((v1053 - v1055) >> 31)));
  v952->timer = v1233;
  int v1057 = v952->timer;
  int * v1058 = v952->reg_ready;
  int v1059 = v1058[26];
  int v1235 = v1059 + ((v1057 - v1059) & (~((v1057 - v1059) >> 31)));
  v952->timer = v1235;
  int v1061 = v952->timer;
  int * v1062 = v952->reg_ready;
  int v1063 = v1062[27];
  int v1237 = v1063 + ((v1061 - v1063) & (~((v1061 - v1063) >> 31)));
  v952->timer = v1237;
  int v1065 = v952->timer;
  int * v1066 = v952->reg_ready;
  int v1067 = v1066[28];
  int v1239 = v1067 + ((v1065 - v1067) & (~((v1065 - v1067) >> 31)));
  v952->timer = v1239;
  int v1069 = v952->timer;
  int * v1070 = v952->reg_ready;
  int v1071 = v1070[29];
  int v1241 = v1071 + ((v1069 - v1071) & (~((v1069 - v1071) >> 31)));
  v952->timer = v1241;
  int v1073 = v952->timer;
  int * v1074 = v952->reg_ready;
  int v1075 = v1074[30];
  int v1243 = v1075 + ((v1073 - v1075) & (~((v1073 - v1075) >> 31)));
  v952->timer = v1243;
  int v1077 = v952->timer;
  int * v1078 = v952->reg_ready;
  int v1079 = v1078[31];
  int v1245 = v1079 + ((v1077 - v1079) & (~((v1077 - v1079) >> 31)));
  v952->timer = v1245;
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v48) {
  struct StateT * v49 = v48->a;
  int v50 = v49->timer;
  struct StateT * v51 = v48->b;
  int v52 = v51->timer;
  bool v331 = v50 == v52;
  squared_assert(v331);
  squared_assume(v331);
  struct StateT * v55 = v48->a;
  int v56 = v55->timer;
  int v57 = v55->timer;
  int v333 = v57 + 1;
  v55->timer = v333;
  struct StateT * v59 = v48->b;
  int v60 = v59->timer;
  int v61 = v59->timer;
  int v335 = v61 + 1;
  v59->timer = v335;
  struct StateT * v63 = v48->a;
  int * v64 = v63->reg_ready;
  int v65 = v64[12];
  int * v66 = v63->regs;
  int v67 = v66[12];
  int * v68 = v63->cache_tags;
  int v341 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2;
  int v69 = v68[v341];
  int * v70 = v63->cache_tags;
  int v343 = ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + 1;
  int v71 = v70[v343];
  int * v72 = v63->cache_tags;
  int v345 = 4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2);
  int v73 = v72[v345];
  int * v74 = v63->cache_tags;
  int v347 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v75 = v74[v347];
  int * v76 = v63->cache_vals;
  bool v348 = !(((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) == 0);
  int v189;
  if (v348) {
    int * v77 = v63->cache_age;
    int v350 = ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) & 1);
    int v78 = v77[v350];
    int * v79 = v63->cache_age;
    int v80 = v79[v341];
    int * v81 = v63->cache_age;
    int v353 = v80 + ((int)((unsigned int)(v80 - v78) >> 31));
    v81[v341] = v353;
    int * v83 = v63->cache_age;
    int v84 = v83[v343];
    int * v85 = v63->cache_age;
    int v356 = v84 + ((int)((unsigned int)(v84 - v78) >> 31));
    v85[v343] = v356;
    int * v87 = v63->cache_age;
    v87[v350] = 0;
    v189 = v350;
  } else {
    int * v90 = v63->cache_age;
    int v360 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2;
    int v91 = v90[v360];
    int * v92 = v63->cache_tags;
    int v93 = v92[v360];
    int * v94 = v63->cache_age;
    int v95 = v94[v343];
    int * v96 = v63->cache_tags;
    int v97 = v96[v343];
    bool v364 = !(((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) == 0);
    int v161;
    if (v364) {
      int * v98 = v63->cache_age;
      int v366 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) & 1);
      int v99 = v98[v366];
      int * v100 = v63->cache_age;
      int v101 = v100[v345];
      int * v102 = v63->cache_age;
      int v369 = v101 + ((int)((unsigned int)(v101 - v99) >> 31));
      v102[v345] = v369;
      int * v104 = v63->cache_age;
      int v105 = v104[v347];
      int * v106 = v63->cache_age;
      int v372 = v105 + ((int)((unsigned int)(v105 - v99) >> 31));
      v106[v347] = v372;
      int * v108 = v63->cache_age;
      v108[v366] = 0;
      v161 = v366;
    } else {
      int * v111 = v63->cache_age;
      int v376 = 4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2);
      int v112 = v111[v376];
      int * v113 = v63->cache_tags;
      int v114 = v113[v376];
      int * v115 = v63->cache_age;
      int v116 = v115[v347];
      int * v117 = v63->cache_tags;
      int v118 = v117[v347];
      int * v119 = v63->cache_dirty;
      int v381 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v120 = v119[v381];
      bool v382 = !(v120 == 0);
      if (v382) {
        int * v121 = v63->cache_tags;
        int v122 = v121[v381];
        int * v123 = v63->cache_vals;
        int v385 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v124 = v123[v385];
        int * v125 = v63->cache_vals;
        int v387 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v126 = v125[v387];
        int * v127 = v63->mem;
        int v389 = v122 * 2;
        v127[v389] = v124;
        int * v129 = v63->mem;
        int v392 = (v122 * 2) + 1;
        v129[v392] = v126;
        ;
      } else {
        ;
      }
      int * v134 = v63->mem;
      int v397 = ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) * 2;
      int v135 = v134[v397];
      int * v136 = v63->mem;
      int v399 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) * 2) + 1;
      int v137 = v136[v399];
      int * v138 = v63->cache_vals;
      int v401 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v138[v401] = v135;
      int * v140 = v63->cache_vals;
      int v404 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2)) - (v116 + ((~(((v118 ^ -1) | (-(v118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v140[v404] = v137;
      int * v142 = v63->cache_tags;
      int v407 = (int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1);
      v142[v381] = v407;
      int * v144 = v63->cache_dirty;
      v144[v381] = 0;
      int * v146 = v63->cache_age;
      v146[v381] = 1;
      int * v148 = v63->cache_age;
      int v149 = v148[v381];
      int * v150 = v63->cache_age;
      int v151 = v150[v345];
      int * v152 = v63->cache_age;
      int v415 = v151 + ((int)((unsigned int)(v151 - v149) >> 31));
      v152[v345] = v415;
      int * v154 = v63->cache_age;
      int v155 = v154[v347];
      int * v156 = v63->cache_age;
      int v418 = v155 + ((int)((unsigned int)(v155 - v149) >> 31));
      v156[v347] = v418;
      int * v158 = v63->cache_age;
      v158[v381] = 0;
      v161 = v381;
    }
    int * v162 = v63->cache_vals;
    int v421 = v161 * 2;
    int v163 = v162[v421];
    int * v164 = v63->cache_vals;
    int v423 = (v161 * 2) + 1;
    int v165 = v164[v423];
    int * v166 = v63->cache_vals;
    int v425 = (((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((((v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v166[v425] = v163;
    int * v168 = v63->cache_vals;
    int v428 = ((((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((((v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v168[v428] = v165;
    int * v170 = v63->cache_tags;
    int v431 = ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((((v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2)) - (v95 + ((~(((v97 ^ -1) | (-(v97 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v432 = (int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1);
    v170[v431] = v432;
    int * v172 = v63->cache_dirty;
    v172[v431] = 0;
    int * v174 = v63->cache_age;
    v174[v431] = 1;
    int * v176 = v63->cache_age;
    int v177 = v176[v431];
    int * v178 = v63->cache_age;
    int v179 = v178[v341];
    int * v180 = v63->cache_age;
    int v440 = v179 + ((int)((unsigned int)(v179 - v177) >> 31));
    v180[v341] = v440;
    int * v182 = v63->cache_age;
    int v183 = v182[v343];
    int * v184 = v63->cache_age;
    int v443 = v183 + ((int)((unsigned int)(v183 - v177) >> 31));
    v184[v343] = v443;
    int * v186 = v63->cache_age;
    v186[v431] = 0;
    v189 = v431;
  }
  int v446 = (v189 * 2) + (((int)((unsigned int)v67 >> 2)) & 1);
  int v190 = v76[v446];
  int * v191 = v63->reg_ready;
  int v449 = ((v65 + ((v56 - v65) & (~((v56 - v65) >> 31)))) + 1) + ((100 ^ (((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) & 104)))));
  v191[16] = v449;
  int * v193 = v63->regs;
  v193[16] = v190;
  struct StateT * v195 = v48->b;
  int * v196 = v195->reg_ready;
  int v197 = v196[12];
  int * v198 = v195->regs;
  int v199 = v198[12];
  int * v200 = v195->cache_tags;
  int v456 = (((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2;
  int v201 = v200[v456];
  int * v202 = v195->cache_tags;
  int v458 = ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2) + 1;
  int v203 = v202[v458];
  int * v204 = v195->cache_tags;
  int v460 = 4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2);
  int v205 = v204[v460];
  int * v206 = v195->cache_tags;
  int v462 = (4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v207 = v206[v462];
  int * v208 = v195->cache_vals;
  bool v463 = !(((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) | (~(((v203 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v203 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31))) == 0);
  int v321;
  if (v463) {
    int * v209 = v195->cache_age;
    int v465 = ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2) + ((~(((v203 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v203 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) & 1);
    int v210 = v209[v465];
    int * v211 = v195->cache_age;
    int v212 = v211[v456];
    int * v213 = v195->cache_age;
    int v468 = v212 + ((int)((unsigned int)(v212 - v210) >> 31));
    v213[v456] = v468;
    int * v215 = v195->cache_age;
    int v216 = v215[v458];
    int * v217 = v195->cache_age;
    int v471 = v216 + ((int)((unsigned int)(v216 - v210) >> 31));
    v217[v458] = v471;
    int * v219 = v195->cache_age;
    v219[v465] = 0;
    v321 = v465;
  } else {
    int * v222 = v195->cache_age;
    int v475 = (((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2;
    int v223 = v222[v475];
    int * v224 = v195->cache_tags;
    int v225 = v224[v475];
    int * v226 = v195->cache_age;
    int v227 = v226[v458];
    int * v228 = v195->cache_tags;
    int v229 = v228[v458];
    bool v479 = !(((~(((v205 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v205 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) | (~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31))) == 0);
    int v293;
    if (v479) {
      int * v230 = v195->cache_age;
      int v481 = (4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + ((~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) & 1);
      int v231 = v230[v481];
      int * v232 = v195->cache_age;
      int v233 = v232[v460];
      int * v234 = v195->cache_age;
      int v484 = v233 + ((int)((unsigned int)(v233 - v231) >> 31));
      v234[v460] = v484;
      int * v236 = v195->cache_age;
      int v237 = v236[v462];
      int * v238 = v195->cache_age;
      int v487 = v237 + ((int)((unsigned int)(v237 - v231) >> 31));
      v238[v462] = v487;
      int * v240 = v195->cache_age;
      v240[v481] = 0;
      v293 = v481;
    } else {
      int * v243 = v195->cache_age;
      int v491 = 4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2);
      int v244 = v243[v491];
      int * v245 = v195->cache_tags;
      int v246 = v245[v491];
      int * v247 = v195->cache_age;
      int v248 = v247[v462];
      int * v249 = v195->cache_tags;
      int v250 = v249[v462];
      int * v251 = v195->cache_dirty;
      int v496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v252 = v251[v496];
      bool v497 = !(v252 == 0);
      if (v497) {
        int * v253 = v195->cache_tags;
        int v254 = v253[v496];
        int * v255 = v195->cache_vals;
        int v500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v256 = v255[v500];
        int * v257 = v195->cache_vals;
        int v502 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v258 = v257[v502];
        int * v259 = v195->mem;
        int v504 = v254 * 2;
        v259[v504] = v256;
        int * v261 = v195->mem;
        int v507 = (v254 * 2) + 1;
        v261[v507] = v258;
        ;
      } else {
        ;
      }
      int * v266 = v195->mem;
      int v512 = ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) * 2;
      int v267 = v266[v512];
      int * v268 = v195->mem;
      int v514 = (((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) * 2) + 1;
      int v269 = v268[v514];
      int * v270 = v195->cache_vals;
      int v516 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v270[v516] = v267;
      int * v272 = v195->cache_vals;
      int v519 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 3) * 2)) + ((((v244 + ((~(((v246 ^ -1) | (-(v246 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v250 ^ -1) | (-(v250 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v272[v519] = v269;
      int * v274 = v195->cache_tags;
      int v522 = (int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1);
      v274[v496] = v522;
      int * v276 = v195->cache_dirty;
      v276[v496] = 0;
      int * v278 = v195->cache_age;
      v278[v496] = 1;
      int * v280 = v195->cache_age;
      int v281 = v280[v496];
      int * v282 = v195->cache_age;
      int v283 = v282[v460];
      int * v284 = v195->cache_age;
      int v530 = v283 + ((int)((unsigned int)(v283 - v281) >> 31));
      v284[v460] = v530;
      int * v286 = v195->cache_age;
      int v287 = v286[v462];
      int * v288 = v195->cache_age;
      int v533 = v287 + ((int)((unsigned int)(v287 - v281) >> 31));
      v288[v462] = v533;
      int * v290 = v195->cache_age;
      v290[v496] = 0;
      v293 = v496;
    }
    int * v294 = v195->cache_vals;
    int v536 = v293 * 2;
    int v295 = v294[v536];
    int * v296 = v195->cache_vals;
    int v538 = (v293 * 2) + 1;
    int v297 = v296[v538];
    int * v298 = v195->cache_vals;
    int v540 = (((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2) + ((((v223 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2)) - (v227 + ((~(((v229 ^ -1) | (-(v229 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v298[v540] = v295;
    int * v300 = v195->cache_vals;
    int v543 = ((((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2) + ((((v223 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2)) - (v227 + ((~(((v229 ^ -1) | (-(v229 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v300[v543] = v297;
    int * v302 = v195->cache_tags;
    int v546 = ((((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1)) & 1) * 2) + ((((v223 + ((~(((v225 ^ -1) | (-(v225 ^ -1))) >> 31)) & 2)) - (v227 + ((~(((v229 ^ -1) | (-(v229 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v547 = (int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1);
    v302[v546] = v547;
    int * v304 = v195->cache_dirty;
    v304[v546] = 0;
    int * v306 = v195->cache_age;
    v306[v546] = 1;
    int * v308 = v195->cache_age;
    int v309 = v308[v546];
    int * v310 = v195->cache_age;
    int v311 = v310[v456];
    int * v312 = v195->cache_age;
    int v555 = v311 + ((int)((unsigned int)(v311 - v309) >> 31));
    v312[v456] = v555;
    int * v314 = v195->cache_age;
    int v315 = v314[v458];
    int * v316 = v195->cache_age;
    int v558 = v315 + ((int)((unsigned int)(v315 - v309) >> 31));
    v316[v458] = v558;
    int * v318 = v195->cache_age;
    v318[v546] = 0;
    v321 = v546;
  }
  int v561 = (v321 * 2) + (((int)((unsigned int)v199 >> 2)) & 1);
  int v322 = v208[v561];
  int * v323 = v195->reg_ready;
  int v563 = ((v197 + ((v60 - v197) & (~((v60 - v197) >> 31)))) + 1) + ((100 ^ (((~(((v205 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v205 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) | (~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) | (~(((v203 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v203 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v205 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v205 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31)) | (~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v199 >> 2)) >> 1))))) >> 31))) & 104)))));
  v323[16] = v563;
  int * v325 = v195->regs;
  v325[16] = v322;
  struct StateT2 * v327 = slot_2(v48);
  return v327;
}

struct StateT2 * slot_6(struct StateT2 * v681) {
  struct StateT * v682 = v681->a;
  int v683 = v682->timer;
  struct StateT * v684 = v681->b;
  int v685 = v684->timer;
  bool v710 = v683 == v685;
  squared_assert(v710);
  squared_assume(v710);
  struct StateT * v688 = v681->a;
  int v689 = v688->timer;
  int v690 = v688->timer;
  int v712 = v690 + 1;
  v688->timer = v712;
  struct StateT * v692 = v681->b;
  int v693 = v692->timer;
  int v694 = v692->timer;
  int v714 = v694 + 1;
  v692->timer = v714;
  struct StateT * v696 = v681->a;
  int * v697 = v696->reg_ready;
  int v718 = v689 + 1;
  v697[18] = v718;
  int * v699 = v696->regs;
  v699[18] = 2;
  struct StateT * v701 = v681->b;
  int * v702 = v701->reg_ready;
  int v723 = v693 + 1;
  v702[18] = v723;
  int * v704 = v701->regs;
  v704[18] = 2;
  struct StateT2 * v706 = slot_7(v681);
  return v706;
}

struct StateT2 * slot_5(struct StateT2 * v798) {
  struct StateT * v799 = v798->a;
  int v800 = v799->timer;
  struct StateT * v801 = v798->b;
  int v802 = v801->timer;
  bool v818 = v800 == v802;
  squared_assert(v818);
  squared_assume(v818);
  struct StateT * v805 = v798->a;
  int v806 = v805->timer;
  int v807 = v805->timer;
  int v820 = v807 + 1;
  v805->timer = v820;
  struct StateT * v809 = v798->b;
  int v810 = v809->timer;
  int v811 = v809->timer;
  int v822 = v811 + 1;
  v809->timer = v822;
  struct StateT * v813 = v798->a;
  struct StateT * v814 = v798->b;
  return v798;
}

struct StateT2 * slot_4(struct StateT2 * v727) {
  struct StateT * v728 = v727->a;
  int v729 = v728->timer;
  struct StateT * v730 = v727->b;
  int v731 = v730->timer;
  bool v756 = v729 == v731;
  squared_assert(v756);
  squared_assume(v756);
  struct StateT * v734 = v727->a;
  int v735 = v734->timer;
  int v736 = v734->timer;
  int v758 = v736 + 1;
  v734->timer = v758;
  struct StateT * v738 = v727->b;
  int v739 = v738->timer;
  int v740 = v738->timer;
  int v760 = v740 + 1;
  v738->timer = v760;
  struct StateT * v742 = v727->a;
  int * v743 = v742->reg_ready;
  int v764 = v735 + 1;
  v743[18] = v764;
  int * v745 = v742->regs;
  v745[18] = 1;
  struct StateT * v747 = v727->b;
  int * v748 = v747->reg_ready;
  int v769 = v739 + 1;
  v748[18] = v769;
  int * v750 = v747->regs;
  v750[18] = 1;
  struct StateT2 * v752 = slot_5(v727);
  return v752;
}

struct StateT2 * slot_2(struct StateT2 * v568) {
  struct StateT * v569 = v568->a;
  int v570 = v569->timer;
  struct StateT * v571 = v568->b;
  int v572 = v571->timer;
  bool v597 = v570 == v572;
  squared_assert(v597);
  squared_assume(v597);
  struct StateT * v575 = v568->a;
  int v576 = v575->timer;
  int v577 = v575->timer;
  int v599 = v577 + 1;
  v575->timer = v599;
  struct StateT * v579 = v568->b;
  int v580 = v579->timer;
  int v581 = v579->timer;
  int v601 = v581 + 1;
  v579->timer = v601;
  struct StateT * v583 = v568->a;
  int * v584 = v583->reg_ready;
  int v605 = v576 + 1;
  v584[17] = v605;
  int * v586 = v583->regs;
  v586[17] = 10;
  struct StateT * v588 = v568->b;
  int * v589 = v588->reg_ready;
  int v610 = v580 + 1;
  v589[17] = v610;
  int * v591 = v588->regs;
  v591[17] = 10;
  struct StateT2 * v593 = slot_3(v568);
  return v593;
}

struct StateT2 * slot_7(struct StateT2 * v773) {
  struct StateT * v774 = v773->a;
  int v775 = v774->timer;
  struct StateT * v776 = v773->b;
  int v777 = v776->timer;
  bool v793 = v775 == v777;
  squared_assert(v793);
  squared_assume(v793);
  struct StateT * v780 = v773->a;
  int v781 = v780->timer;
  int v782 = v780->timer;
  int v795 = v782 + 1;
  v780->timer = v795;
  struct StateT * v784 = v773->b;
  int v785 = v784->timer;
  int v786 = v784->timer;
  int v797 = v786 + 1;
  v784->timer = v797;
  struct StateT * v788 = v773->a;
  struct StateT * v789 = v773->b;
  return v773;
}

struct StateT2 * slot_3(struct StateT2 * v614) {
  struct StateT * v615 = v614->a;
  int v616 = v615->timer;
  struct StateT * v617 = v614->b;
  int v618 = v617->timer;
  bool v657 = v616 == v618;
  squared_assert(v657);
  squared_assume(v657);
  struct StateT * v621 = v614->a;
  int v622 = v621->timer;
  int v623 = v621->timer;
  int v659 = v623 + 1;
  v621->timer = v659;
  struct StateT * v625 = v614->b;
  int v626 = v625->timer;
  int v627 = v625->timer;
  int v661 = v627 + 1;
  v625->timer = v661;
  struct StateT * v629 = v614->a;
  int * v630 = v629->reg_ready;
  int v631 = v630[16];
  int * v632 = v629->regs;
  int v633 = v632[16];
  int * v634 = v629->reg_ready;
  int v635 = v634[17];
  int * v636 = v629->regs;
  int v637 = v636[17];
  struct StateT * v638 = v614->b;
  int * v639 = v638->reg_ready;
  int v640 = v639[16];
  int * v641 = v638->regs;
  int v642 = v641[16];
  int * v643 = v638->reg_ready;
  int v644 = v643[17];
  int * v645 = v638->regs;
  int v646 = v645[17];
  bool v674 = (v633 < v637) == (v642 < v646);
  squared_diverged(v674);
  squared_assume(v674);
  bool v675 = v633 < v637;
  struct StateT2 * v653;
  if (v675) {
    struct StateT2 * v649 = slot_6(v614);
    v653 = v649;
  } else {
    struct StateT2 * v651 = slot_4(v614);
    v653 = v651;
  }
  return v653;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v31 = v4 == v6;
  squared_assert(v31);
  squared_assume(v31);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v11 = v9->timer;
  int v33 = v11 + 1;
  v9->timer = v33;
  struct StateT * v13 = v2->b;
  int v14 = v13->timer;
  int v15 = v13->timer;
  int v35 = v15 + 1;
  v13->timer = v35;
  struct StateT * v17 = v2->a;
  int * v18 = v17->reg_ready;
  int v39 = v10 + 1;
  v18[12] = v39;
  int * v20 = v17->regs;
  v20[12] = 80;
  struct StateT * v22 = v2->b;
  int * v23 = v22->reg_ready;
  int v44 = v14 + 1;
  v23[12] = v44;
  int * v25 = v22->regs;
  v25[12] = 80;
  struct StateT2 * v27 = slot_1(v2);
  return v27;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}