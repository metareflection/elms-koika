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
struct StateT * slot_1(struct StateT * v27);
struct StateT * slot_6(struct StateT * v740);
struct StateT * slot_5(struct StateT * v716);
struct StateT * slot_4(struct StateT * v461);
struct StateT * slot_2(struct StateT * v51);
struct StateT * slot_3(struct StateT * v69);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v992 = v1->timer;
  int * v993 = v1->reg_ready;
  int v994 = v993[0];
  int v1125 = v994 + ((v992 - v994) & (~((v992 - v994) >> 31)));
  v1->timer = v1125;
  int v996 = v1->timer;
  int * v997 = v1->reg_ready;
  int v998 = v997[1];
  int v1128 = v998 + ((v996 - v998) & (~((v996 - v998) >> 31)));
  v1->timer = v1128;
  int v1000 = v1->timer;
  int * v1001 = v1->reg_ready;
  int v1002 = v1001[2];
  int v1131 = v1002 + ((v1000 - v1002) & (~((v1000 - v1002) >> 31)));
  v1->timer = v1131;
  int v1004 = v1->timer;
  int * v1005 = v1->reg_ready;
  int v1006 = v1005[3];
  int v1134 = v1006 + ((v1004 - v1006) & (~((v1004 - v1006) >> 31)));
  v1->timer = v1134;
  int v1008 = v1->timer;
  int * v1009 = v1->reg_ready;
  int v1010 = v1009[4];
  int v1137 = v1010 + ((v1008 - v1010) & (~((v1008 - v1010) >> 31)));
  v1->timer = v1137;
  int v1012 = v1->timer;
  int * v1013 = v1->reg_ready;
  int v1014 = v1013[5];
  int v1140 = v1014 + ((v1012 - v1014) & (~((v1012 - v1014) >> 31)));
  v1->timer = v1140;
  int v1016 = v1->timer;
  int * v1017 = v1->reg_ready;
  int v1018 = v1017[6];
  int v1143 = v1018 + ((v1016 - v1018) & (~((v1016 - v1018) >> 31)));
  v1->timer = v1143;
  int v1020 = v1->timer;
  int * v1021 = v1->reg_ready;
  int v1022 = v1021[7];
  int v1146 = v1022 + ((v1020 - v1022) & (~((v1020 - v1022) >> 31)));
  v1->timer = v1146;
  int v1024 = v1->timer;
  int * v1025 = v1->reg_ready;
  int v1026 = v1025[8];
  int v1149 = v1026 + ((v1024 - v1026) & (~((v1024 - v1026) >> 31)));
  v1->timer = v1149;
  int v1028 = v1->timer;
  int * v1029 = v1->reg_ready;
  int v1030 = v1029[9];
  int v1152 = v1030 + ((v1028 - v1030) & (~((v1028 - v1030) >> 31)));
  v1->timer = v1152;
  int v1032 = v1->timer;
  int * v1033 = v1->reg_ready;
  int v1034 = v1033[10];
  int v1155 = v1034 + ((v1032 - v1034) & (~((v1032 - v1034) >> 31)));
  v1->timer = v1155;
  int v1036 = v1->timer;
  int * v1037 = v1->reg_ready;
  int v1038 = v1037[11];
  int v1158 = v1038 + ((v1036 - v1038) & (~((v1036 - v1038) >> 31)));
  v1->timer = v1158;
  int v1040 = v1->timer;
  int * v1041 = v1->reg_ready;
  int v1042 = v1041[12];
  int v1161 = v1042 + ((v1040 - v1042) & (~((v1040 - v1042) >> 31)));
  v1->timer = v1161;
  int v1044 = v1->timer;
  int * v1045 = v1->reg_ready;
  int v1046 = v1045[13];
  int v1164 = v1046 + ((v1044 - v1046) & (~((v1044 - v1046) >> 31)));
  v1->timer = v1164;
  int v1048 = v1->timer;
  int * v1049 = v1->reg_ready;
  int v1050 = v1049[14];
  int v1167 = v1050 + ((v1048 - v1050) & (~((v1048 - v1050) >> 31)));
  v1->timer = v1167;
  int v1052 = v1->timer;
  int * v1053 = v1->reg_ready;
  int v1054 = v1053[15];
  int v1170 = v1054 + ((v1052 - v1054) & (~((v1052 - v1054) >> 31)));
  v1->timer = v1170;
  int v1056 = v1->timer;
  int * v1057 = v1->reg_ready;
  int v1058 = v1057[16];
  int v1173 = v1058 + ((v1056 - v1058) & (~((v1056 - v1058) >> 31)));
  v1->timer = v1173;
  int v1060 = v1->timer;
  int * v1061 = v1->reg_ready;
  int v1062 = v1061[17];
  int v1176 = v1062 + ((v1060 - v1062) & (~((v1060 - v1062) >> 31)));
  v1->timer = v1176;
  int v1064 = v1->timer;
  int * v1065 = v1->reg_ready;
  int v1066 = v1065[18];
  int v1179 = v1066 + ((v1064 - v1066) & (~((v1064 - v1066) >> 31)));
  v1->timer = v1179;
  int v1068 = v1->timer;
  int * v1069 = v1->reg_ready;
  int v1070 = v1069[19];
  int v1182 = v1070 + ((v1068 - v1070) & (~((v1068 - v1070) >> 31)));
  v1->timer = v1182;
  int v1072 = v1->timer;
  int * v1073 = v1->reg_ready;
  int v1074 = v1073[20];
  int v1185 = v1074 + ((v1072 - v1074) & (~((v1072 - v1074) >> 31)));
  v1->timer = v1185;
  int v1076 = v1->timer;
  int * v1077 = v1->reg_ready;
  int v1078 = v1077[21];
  int v1188 = v1078 + ((v1076 - v1078) & (~((v1076 - v1078) >> 31)));
  v1->timer = v1188;
  int v1080 = v1->timer;
  int * v1081 = v1->reg_ready;
  int v1082 = v1081[22];
  int v1191 = v1082 + ((v1080 - v1082) & (~((v1080 - v1082) >> 31)));
  v1->timer = v1191;
  int v1084 = v1->timer;
  int * v1085 = v1->reg_ready;
  int v1086 = v1085[23];
  int v1194 = v1086 + ((v1084 - v1086) & (~((v1084 - v1086) >> 31)));
  v1->timer = v1194;
  int v1088 = v1->timer;
  int * v1089 = v1->reg_ready;
  int v1090 = v1089[24];
  int v1197 = v1090 + ((v1088 - v1090) & (~((v1088 - v1090) >> 31)));
  v1->timer = v1197;
  int v1092 = v1->timer;
  int * v1093 = v1->reg_ready;
  int v1094 = v1093[25];
  int v1200 = v1094 + ((v1092 - v1094) & (~((v1092 - v1094) >> 31)));
  v1->timer = v1200;
  int v1096 = v1->timer;
  int * v1097 = v1->reg_ready;
  int v1098 = v1097[26];
  int v1203 = v1098 + ((v1096 - v1098) & (~((v1096 - v1098) >> 31)));
  v1->timer = v1203;
  int v1100 = v1->timer;
  int * v1101 = v1->reg_ready;
  int v1102 = v1101[27];
  int v1206 = v1102 + ((v1100 - v1102) & (~((v1100 - v1102) >> 31)));
  v1->timer = v1206;
  int v1104 = v1->timer;
  int * v1105 = v1->reg_ready;
  int v1106 = v1105[28];
  int v1209 = v1106 + ((v1104 - v1106) & (~((v1104 - v1106) >> 31)));
  v1->timer = v1209;
  int v1108 = v1->timer;
  int * v1109 = v1->reg_ready;
  int v1110 = v1109[29];
  int v1212 = v1110 + ((v1108 - v1110) & (~((v1108 - v1110) >> 31)));
  v1->timer = v1212;
  int v1112 = v1->timer;
  int * v1113 = v1->reg_ready;
  int v1114 = v1113[30];
  int v1215 = v1114 + ((v1112 - v1114) & (~((v1112 - v1114) >> 31)));
  v1->timer = v1215;
  int v1116 = v1->timer;
  int * v1117 = v1->reg_ready;
  int v1118 = v1117[31];
  int v1218 = v1118 + ((v1116 - v1118) & (~((v1116 - v1118) >> 31)));
  v1->timer = v1218;
  return v1;
}

struct StateT * slot_1(struct StateT * v27) {
  int v28 = v27->timer;
  int v29 = v27->timer;
  int v41 = v29 + 1;
  v27->timer = v41;
  int * v31 = v27->reg_ready;
  int v32 = v31[6];
  int * v33 = v27->regs;
  int v34 = v33[6];
  int * v35 = v27->reg_ready;
  int v46 = (v32 + ((v28 - v32) & (~((v28 - v32) >> 31)))) + 1;
  v35[6] = v46;
  int * v37 = v27->regs;
  int v48 = v34 + 80;
  v37[6] = v48;
  struct StateT * v39 = slot_2(v27);
  return v39;
}

struct StateT * slot_6(struct StateT * v740) {
  int v741 = v740->timer;
  int v742 = v740->timer;
  int v876 = v742 + 1;
  v740->timer = v876;
  int * v744 = v740->reg_ready;
  int v745 = v744[6];
  int * v746 = v740->regs;
  int v747 = v746[6];
  int * v748 = v740->cache_tags;
  int v881 = (((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2;
  int v749 = v748[v881];
  int * v750 = v740->cache_tags;
  int v883 = ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + 1;
  int v751 = v750[v883];
  int * v752 = v740->cache_tags;
  int v885 = 4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2);
  int v753 = v752[v885];
  int * v754 = v740->cache_tags;
  int v887 = (4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v755 = v754[v887];
  int * v756 = v740->cache_vals;
  bool v888 = !(((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) == 0);
  int v869;
  if (v888) {
    int * v757 = v740->cache_age;
    int v890 = ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) & 1);
    int v758 = v757[v890];
    int * v759 = v740->cache_age;
    int v760 = v759[v881];
    int * v761 = v740->cache_age;
    int v893 = v760 + ((int)((unsigned int)(v760 - v758) >> 31));
    v761[v881] = v893;
    int * v763 = v740->cache_age;
    int v764 = v763[v883];
    int * v765 = v740->cache_age;
    int v896 = v764 + ((int)((unsigned int)(v764 - v758) >> 31));
    v765[v883] = v896;
    int * v767 = v740->cache_age;
    v767[v890] = 0;
    v869 = v890;
  } else {
    int * v770 = v740->cache_age;
    int v900 = (((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2;
    int v771 = v770[v900];
    int * v772 = v740->cache_tags;
    int v773 = v772[v900];
    int * v774 = v740->cache_age;
    int v775 = v774[v883];
    int * v776 = v740->cache_tags;
    int v777 = v776[v883];
    bool v904 = !(((~(((v753 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v753 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) == 0);
    int v841;
    if (v904) {
      int * v778 = v740->cache_age;
      int v906 = (4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) & 1);
      int v779 = v778[v906];
      int * v780 = v740->cache_age;
      int v781 = v780[v885];
      int * v782 = v740->cache_age;
      int v909 = v781 + ((int)((unsigned int)(v781 - v779) >> 31));
      v782[v885] = v909;
      int * v784 = v740->cache_age;
      int v785 = v784[v887];
      int * v786 = v740->cache_age;
      int v912 = v785 + ((int)((unsigned int)(v785 - v779) >> 31));
      v786[v887] = v912;
      int * v788 = v740->cache_age;
      v788[v906] = 0;
      v841 = v906;
    } else {
      int * v791 = v740->cache_age;
      int v916 = 4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2);
      int v792 = v791[v916];
      int * v793 = v740->cache_tags;
      int v794 = v793[v916];
      int * v795 = v740->cache_age;
      int v796 = v795[v887];
      int * v797 = v740->cache_tags;
      int v798 = v797[v887];
      int * v799 = v740->cache_dirty;
      int v921 = (4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v792 + ((~(((v794 ^ -1) | (-(v794 ^ -1))) >> 31)) & 2)) - (v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v800 = v799[v921];
      bool v922 = !(v800 == 0);
      if (v922) {
        int * v801 = v740->cache_tags;
        int v802 = v801[v921];
        int * v803 = v740->cache_vals;
        int v925 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v792 + ((~(((v794 ^ -1) | (-(v794 ^ -1))) >> 31)) & 2)) - (v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v804 = v803[v925];
        int * v805 = v740->cache_vals;
        int v927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v792 + ((~(((v794 ^ -1) | (-(v794 ^ -1))) >> 31)) & 2)) - (v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v806 = v805[v927];
        int * v807 = v740->mem;
        int v929 = v802 * 2;
        v807[v929] = v804;
        int * v809 = v740->mem;
        int v932 = (v802 * 2) + 1;
        v809[v932] = v806;
        ;
      } else {
        ;
      }
      int * v814 = v740->mem;
      int v937 = ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) * 2;
      int v815 = v814[v937];
      int * v816 = v740->mem;
      int v939 = (((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) * 2) + 1;
      int v817 = v816[v939];
      int * v818 = v740->cache_vals;
      int v941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v792 + ((~(((v794 ^ -1) | (-(v794 ^ -1))) >> 31)) & 2)) - (v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v818[v941] = v815;
      int * v820 = v740->cache_vals;
      int v944 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 3) * 2)) + ((((v792 + ((~(((v794 ^ -1) | (-(v794 ^ -1))) >> 31)) & 2)) - (v796 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v820[v944] = v817;
      int * v822 = v740->cache_tags;
      int v947 = (int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1);
      v822[v921] = v947;
      int * v824 = v740->cache_dirty;
      v824[v921] = 0;
      int * v826 = v740->cache_age;
      v826[v921] = 1;
      int * v828 = v740->cache_age;
      int v829 = v828[v921];
      int * v830 = v740->cache_age;
      int v831 = v830[v885];
      int * v832 = v740->cache_age;
      int v955 = v831 + ((int)((unsigned int)(v831 - v829) >> 31));
      v832[v885] = v955;
      int * v834 = v740->cache_age;
      int v835 = v834[v887];
      int * v836 = v740->cache_age;
      int v958 = v835 + ((int)((unsigned int)(v835 - v829) >> 31));
      v836[v887] = v958;
      int * v838 = v740->cache_age;
      v838[v921] = 0;
      v841 = v921;
    }
    int * v842 = v740->cache_vals;
    int v961 = v841 * 2;
    int v843 = v842[v961];
    int * v844 = v740->cache_vals;
    int v963 = (v841 * 2) + 1;
    int v845 = v844[v963];
    int * v846 = v740->cache_vals;
    int v965 = (((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v777 ^ -1) | (-(v777 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v846[v965] = v843;
    int * v848 = v740->cache_vals;
    int v968 = ((((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v777 ^ -1) | (-(v777 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v848[v968] = v845;
    int * v850 = v740->cache_tags;
    int v971 = ((((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1)) & 1) * 2) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v777 ^ -1) | (-(v777 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v972 = (int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1);
    v850[v971] = v972;
    int * v852 = v740->cache_dirty;
    v852[v971] = 0;
    int * v854 = v740->cache_age;
    v854[v971] = 1;
    int * v856 = v740->cache_age;
    int v857 = v856[v971];
    int * v858 = v740->cache_age;
    int v859 = v858[v881];
    int * v860 = v740->cache_age;
    int v980 = v859 + ((int)((unsigned int)(v859 - v857) >> 31));
    v860[v881] = v980;
    int * v862 = v740->cache_age;
    int v863 = v862[v883];
    int * v864 = v740->cache_age;
    int v983 = v863 + ((int)((unsigned int)(v863 - v857) >> 31));
    v864[v883] = v983;
    int * v866 = v740->cache_age;
    v866[v971] = 0;
    v869 = v971;
  }
  int v986 = (v869 * 2) + (((int)((unsigned int)v747 >> 2)) & 1);
  int v870 = v756[v986];
  int * v871 = v740->reg_ready;
  int v989 = ((v745 + ((v741 - v745) & (~((v741 - v745) >> 31)))) + 1) + ((100 ^ (((~(((v753 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v753 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v749 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v753 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v753 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v747 >> 2)) >> 1))))) >> 31))) & 104)))));
  v871[12] = v989;
  int * v873 = v740->regs;
  v873[12] = v870;
  return v740;
}

struct StateT * slot_5(struct StateT * v716) {
  int v717 = v716->timer;
  int v718 = v716->timer;
  int v730 = v718 + 1;
  v716->timer = v730;
  int * v720 = v716->reg_ready;
  int v721 = v720[11];
  int * v722 = v716->regs;
  int v723 = v722[11];
  int * v724 = v716->reg_ready;
  int v735 = (v721 + ((v717 - v721) & (~((v717 - v721) >> 31)))) + 1;
  v724[11] = v735;
  int * v726 = v716->regs;
  int v737 = v723 << 2;
  v726[11] = v737;
  struct StateT * v728 = slot_6(v716);
  return v728;
}

struct StateT * slot_4(struct StateT * v461) {
  int v462 = v461->timer;
  int v463 = v461->timer;
  int v598 = v463 + 1;
  v461->timer = v598;
  int * v465 = v461->reg_ready;
  int v466 = v465[6];
  int * v467 = v461->regs;
  int v468 = v467[6];
  int * v469 = v461->cache_tags;
  int v603 = (((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2;
  int v470 = v469[v603];
  int * v471 = v461->cache_tags;
  int v605 = ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2) + 1;
  int v472 = v471[v605];
  int * v473 = v461->cache_tags;
  int v607 = 4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2);
  int v474 = v473[v607];
  int * v475 = v461->cache_tags;
  int v609 = (4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v476 = v475[v609];
  int * v477 = v461->cache_vals;
  bool v610 = !(((~(((v470 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v470 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) | (~(((v472 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v472 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31))) == 0);
  int v590;
  if (v610) {
    int * v478 = v461->cache_age;
    int v612 = ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2) + ((~(((v472 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v472 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) & 1);
    int v479 = v478[v612];
    int * v480 = v461->cache_age;
    int v481 = v480[v603];
    int * v482 = v461->cache_age;
    int v615 = v481 + ((int)((unsigned int)(v481 - v479) >> 31));
    v482[v603] = v615;
    int * v484 = v461->cache_age;
    int v485 = v484[v605];
    int * v486 = v461->cache_age;
    int v618 = v485 + ((int)((unsigned int)(v485 - v479) >> 31));
    v486[v605] = v618;
    int * v488 = v461->cache_age;
    v488[v612] = 0;
    v590 = v612;
  } else {
    int * v491 = v461->cache_age;
    int v622 = (((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2;
    int v492 = v491[v622];
    int * v493 = v461->cache_tags;
    int v494 = v493[v622];
    int * v495 = v461->cache_age;
    int v496 = v495[v605];
    int * v497 = v461->cache_tags;
    int v498 = v497[v605];
    bool v626 = !(((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31))) == 0);
    int v562;
    if (v626) {
      int * v499 = v461->cache_age;
      int v628 = (4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + ((~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) & 1);
      int v500 = v499[v628];
      int * v501 = v461->cache_age;
      int v502 = v501[v607];
      int * v503 = v461->cache_age;
      int v631 = v502 + ((int)((unsigned int)(v502 - v500) >> 31));
      v503[v607] = v631;
      int * v505 = v461->cache_age;
      int v506 = v505[v609];
      int * v507 = v461->cache_age;
      int v634 = v506 + ((int)((unsigned int)(v506 - v500) >> 31));
      v507[v609] = v634;
      int * v509 = v461->cache_age;
      v509[v628] = 0;
      v562 = v628;
    } else {
      int * v512 = v461->cache_age;
      int v638 = 4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2);
      int v513 = v512[v638];
      int * v514 = v461->cache_tags;
      int v515 = v514[v638];
      int * v516 = v461->cache_age;
      int v517 = v516[v609];
      int * v518 = v461->cache_tags;
      int v519 = v518[v609];
      int * v520 = v461->cache_dirty;
      int v643 = (4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + ((((v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2)) - (v517 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v521 = v520[v643];
      bool v644 = !(v521 == 0);
      if (v644) {
        int * v522 = v461->cache_tags;
        int v523 = v522[v643];
        int * v524 = v461->cache_vals;
        int v647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + ((((v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2)) - (v517 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v525 = v524[v647];
        int * v526 = v461->cache_vals;
        int v649 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + ((((v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2)) - (v517 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v527 = v526[v649];
        int * v528 = v461->mem;
        int v651 = v523 * 2;
        v528[v651] = v525;
        int * v530 = v461->mem;
        int v654 = (v523 * 2) + 1;
        v530[v654] = v527;
        ;
      } else {
        ;
      }
      int * v535 = v461->mem;
      int v659 = ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) * 2;
      int v536 = v535[v659];
      int * v537 = v461->mem;
      int v661 = (((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) * 2) + 1;
      int v538 = v537[v661];
      int * v539 = v461->cache_vals;
      int v663 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + ((((v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2)) - (v517 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v539[v663] = v536;
      int * v541 = v461->cache_vals;
      int v666 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 3) * 2)) + ((((v513 + ((~(((v515 ^ -1) | (-(v515 ^ -1))) >> 31)) & 2)) - (v517 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v541[v666] = v538;
      int * v543 = v461->cache_tags;
      int v669 = (int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1);
      v543[v643] = v669;
      int * v545 = v461->cache_dirty;
      v545[v643] = 0;
      int * v547 = v461->cache_age;
      v547[v643] = 1;
      int * v549 = v461->cache_age;
      int v550 = v549[v643];
      int * v551 = v461->cache_age;
      int v552 = v551[v607];
      int * v553 = v461->cache_age;
      int v677 = v552 + ((int)((unsigned int)(v552 - v550) >> 31));
      v553[v607] = v677;
      int * v555 = v461->cache_age;
      int v556 = v555[v609];
      int * v557 = v461->cache_age;
      int v680 = v556 + ((int)((unsigned int)(v556 - v550) >> 31));
      v557[v609] = v680;
      int * v559 = v461->cache_age;
      v559[v643] = 0;
      v562 = v643;
    }
    int * v563 = v461->cache_vals;
    int v683 = v562 * 2;
    int v564 = v563[v683];
    int * v565 = v461->cache_vals;
    int v685 = (v562 * 2) + 1;
    int v566 = v565[v685];
    int * v567 = v461->cache_vals;
    int v687 = (((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2) + ((((v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2)) - (v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v567[v687] = v564;
    int * v569 = v461->cache_vals;
    int v690 = ((((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2) + ((((v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2)) - (v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v569[v690] = v566;
    int * v571 = v461->cache_tags;
    int v693 = ((((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1)) & 1) * 2) + ((((v492 + ((~(((v494 ^ -1) | (-(v494 ^ -1))) >> 31)) & 2)) - (v496 + ((~(((v498 ^ -1) | (-(v498 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v694 = (int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1);
    v571[v693] = v694;
    int * v573 = v461->cache_dirty;
    v573[v693] = 0;
    int * v575 = v461->cache_age;
    v575[v693] = 1;
    int * v577 = v461->cache_age;
    int v578 = v577[v693];
    int * v579 = v461->cache_age;
    int v580 = v579[v603];
    int * v581 = v461->cache_age;
    int v702 = v580 + ((int)((unsigned int)(v580 - v578) >> 31));
    v581[v603] = v702;
    int * v583 = v461->cache_age;
    int v584 = v583[v605];
    int * v585 = v461->cache_age;
    int v705 = v584 + ((int)((unsigned int)(v584 - v578) >> 31));
    v585[v605] = v705;
    int * v587 = v461->cache_age;
    v587[v693] = 0;
    v590 = v693;
  }
  int v708 = (v590 * 2) + (((int)((unsigned int)v468 >> 2)) & 1);
  int v591 = v477[v708];
  int * v592 = v461->reg_ready;
  int v711 = ((v466 + ((v462 - v466) & (~((v462 - v466) >> 31)))) + 1) + ((100 ^ (((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v470 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v470 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) | (~(((v472 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v472 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v474 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v474 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31)) | (~(((v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))) | (-(v476 ^ ((int)((unsigned int)((int)((unsigned int)v468 >> 2)) >> 1))))) >> 31))) & 104)))));
  v592[11] = v711;
  int * v594 = v461->regs;
  v594[11] = v591;
  struct StateT * v596 = slot_5(v461);
  return v596;
}

struct StateT * slot_2(struct StateT * v51) {
  int v52 = v51->timer;
  int v53 = v51->timer;
  int v61 = v53 + 1;
  v51->timer = v61;
  int * v55 = v51->reg_ready;
  int v64 = v52 + 1;
  v55[7] = v64;
  int * v57 = v51->regs;
  v57[7] = 0;
  struct StateT * v59 = slot_3(v51);
  return v59;
}

struct StateT * slot_3(struct StateT * v69) {
  int v70 = v69->timer;
  int v71 = v69->timer;
  int v280 = v71 + 1;
  v69->timer = v280;
  int * v73 = v69->reg_ready;
  int v74 = v73[6];
  int * v75 = v69->regs;
  int v76 = v75[6];
  int * v77 = v69->reg_ready;
  int v78 = v77[7];
  int * v79 = v69->regs;
  int v80 = v79[7];
  int * v81 = v69->cache_tags;
  int v288 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2;
  int v82 = v81[v288];
  int * v83 = v69->cache_tags;
  int v290 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + 1;
  int v84 = v83[v290];
  int * v85 = v69->cache_tags;
  int v292 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
  int v86 = v85[v292];
  int * v87 = v69->cache_tags;
  int v294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v88 = v87[v294];
  int v89 = v69->timer;
  int v295 = v89 + ((100 ^ (((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v82 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v82 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) & 104)))));
  v69->timer = v295;
  bool v296 = !(((~(((v82 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v82 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
  int v203;
  if (v296) {
    int * v91 = v69->cache_age;
    int v298 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
    int v92 = v91[v298];
    int * v93 = v69->cache_age;
    int v94 = v93[v288];
    int * v95 = v69->cache_age;
    int v301 = v94 + ((int)((unsigned int)(v94 - v92) >> 31));
    v95[v288] = v301;
    int * v97 = v69->cache_age;
    int v98 = v97[v290];
    int * v99 = v69->cache_age;
    int v304 = v98 + ((int)((unsigned int)(v98 - v92) >> 31));
    v99[v290] = v304;
    int * v101 = v69->cache_age;
    v101[v298] = 0;
    v203 = v298;
  } else {
    int * v104 = v69->cache_age;
    int v308 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2;
    int v105 = v104[v308];
    int * v106 = v69->cache_tags;
    int v107 = v106[v308];
    int * v108 = v69->cache_age;
    int v109 = v108[v290];
    int * v110 = v69->cache_tags;
    int v111 = v110[v290];
    bool v312 = !(((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
    int v175;
    if (v312) {
      int * v112 = v69->cache_age;
      int v314 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((~(((v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v88 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
      int v113 = v112[v314];
      int * v114 = v69->cache_age;
      int v115 = v114[v292];
      int * v116 = v69->cache_age;
      int v317 = v115 + ((int)((unsigned int)(v115 - v113) >> 31));
      v116[v292] = v317;
      int * v118 = v69->cache_age;
      int v119 = v118[v294];
      int * v120 = v69->cache_age;
      int v320 = v119 + ((int)((unsigned int)(v119 - v113) >> 31));
      v120[v294] = v320;
      int * v122 = v69->cache_age;
      v122[v314] = 0;
      v175 = v314;
    } else {
      int * v125 = v69->cache_age;
      int v324 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
      int v126 = v125[v324];
      int * v127 = v69->cache_tags;
      int v128 = v127[v324];
      int * v129 = v69->cache_age;
      int v130 = v129[v294];
      int * v131 = v69->cache_tags;
      int v132 = v131[v294];
      int * v133 = v69->cache_dirty;
      int v329 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v134 = v133[v329];
      bool v330 = !(v134 == 0);
      if (v330) {
        int * v135 = v69->cache_tags;
        int v136 = v135[v329];
        int * v137 = v69->cache_vals;
        int v333 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v138 = v137[v333];
        int * v139 = v69->cache_vals;
        int v335 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v140 = v139[v335];
        int * v141 = v69->mem;
        int v337 = v136 * 2;
        v141[v337] = v138;
        int * v143 = v69->mem;
        int v340 = (v136 * 2) + 1;
        v143[v340] = v140;
        ;
      } else {
        ;
      }
      int * v148 = v69->mem;
      int v345 = ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2;
      int v149 = v148[v345];
      int * v150 = v69->mem;
      int v347 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2) + 1;
      int v151 = v150[v347];
      int * v152 = v69->cache_vals;
      int v349 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v152[v349] = v149;
      int * v154 = v69->cache_vals;
      int v352 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v126 + ((~(((v128 ^ -1) | (-(v128 ^ -1))) >> 31)) & 2)) - (v130 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v154[v352] = v151;
      int * v156 = v69->cache_tags;
      int v355 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
      v156[v329] = v355;
      int * v158 = v69->cache_dirty;
      v158[v329] = 0;
      int * v160 = v69->cache_age;
      v160[v329] = 1;
      int * v162 = v69->cache_age;
      int v163 = v162[v329];
      int * v164 = v69->cache_age;
      int v165 = v164[v292];
      int * v166 = v69->cache_age;
      int v363 = v165 + ((int)((unsigned int)(v165 - v163) >> 31));
      v166[v292] = v363;
      int * v168 = v69->cache_age;
      int v169 = v168[v294];
      int * v170 = v69->cache_age;
      int v366 = v169 + ((int)((unsigned int)(v169 - v163) >> 31));
      v170[v294] = v366;
      int * v172 = v69->cache_age;
      v172[v329] = 0;
      v175 = v329;
    }
    int * v176 = v69->cache_vals;
    int v369 = v175 * 2;
    int v177 = v176[v369];
    int * v178 = v69->cache_vals;
    int v371 = (v175 * 2) + 1;
    int v179 = v178[v371];
    int * v180 = v69->cache_vals;
    int v373 = (((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v105 + ((~(((v107 ^ -1) | (-(v107 ^ -1))) >> 31)) & 2)) - (v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v180[v373] = v177;
    int * v182 = v69->cache_vals;
    int v376 = ((((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v105 + ((~(((v107 ^ -1) | (-(v107 ^ -1))) >> 31)) & 2)) - (v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v182[v376] = v179;
    int * v184 = v69->cache_tags;
    int v379 = ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 1) * 2) + ((((v105 + ((~(((v107 ^ -1) | (-(v107 ^ -1))) >> 31)) & 2)) - (v109 + ((~(((v111 ^ -1) | (-(v111 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v380 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
    v184[v379] = v380;
    int * v186 = v69->cache_dirty;
    v186[v379] = 0;
    int * v188 = v69->cache_age;
    v188[v379] = 1;
    int * v190 = v69->cache_age;
    int v191 = v190[v379];
    int * v192 = v69->cache_age;
    int v193 = v192[v288];
    int * v194 = v69->cache_age;
    int v388 = v193 + ((int)((unsigned int)(v193 - v191) >> 31));
    v194[v288] = v388;
    int * v196 = v69->cache_age;
    int v197 = v196[v290];
    int * v198 = v69->cache_age;
    int v391 = v197 + ((int)((unsigned int)(v197 - v191) >> 31));
    v198[v290] = v391;
    int * v200 = v69->cache_age;
    v200[v379] = 0;
    v203 = v379;
  }
  int * v204 = v69->cache_vals;
  int v394 = (v203 * 2) + (((int)((unsigned int)v76 >> 2)) & 1);
  v204[v394] = v80;
  int * v206 = v69->cache_tags;
  int v207 = v206[v292];
  int * v208 = v69->cache_tags;
  int v209 = v208[v294];
  bool v398 = !(((~(((v207 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v207 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) | (~(((v209 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v209 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31))) == 0);
  int v273;
  if (v398) {
    int * v210 = v69->cache_age;
    int v400 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((~(((v209 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))) | (-(v209 ^ ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1))))) >> 31)) & 1);
    int v211 = v210[v400];
    int * v212 = v69->cache_age;
    int v213 = v212[v292];
    int * v214 = v69->cache_age;
    int v403 = v213 + ((int)((unsigned int)(v213 - v211) >> 31));
    v214[v292] = v403;
    int * v216 = v69->cache_age;
    int v217 = v216[v294];
    int * v218 = v69->cache_age;
    int v406 = v217 + ((int)((unsigned int)(v217 - v211) >> 31));
    v218[v294] = v406;
    int * v220 = v69->cache_age;
    v220[v400] = 0;
    v273 = v400;
  } else {
    int * v223 = v69->cache_age;
    int v410 = 4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2);
    int v224 = v223[v410];
    int * v225 = v69->cache_tags;
    int v226 = v225[v410];
    int * v227 = v69->cache_age;
    int v228 = v227[v294];
    int * v229 = v69->cache_tags;
    int v230 = v229[v294];
    int * v231 = v69->cache_dirty;
    int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v224 + ((~(((v226 ^ -1) | (-(v226 ^ -1))) >> 31)) & 2)) - (v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v232 = v231[v415];
    bool v416 = !(v232 == 0);
    if (v416) {
      int * v233 = v69->cache_tags;
      int v234 = v233[v415];
      int * v235 = v69->cache_vals;
      int v419 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v224 + ((~(((v226 ^ -1) | (-(v226 ^ -1))) >> 31)) & 2)) - (v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v236 = v235[v419];
      int * v237 = v69->cache_vals;
      int v421 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v224 + ((~(((v226 ^ -1) | (-(v226 ^ -1))) >> 31)) & 2)) - (v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v238 = v237[v421];
      int * v239 = v69->mem;
      int v423 = v234 * 2;
      v239[v423] = v236;
      int * v241 = v69->mem;
      int v426 = (v234 * 2) + 1;
      v241[v426] = v238;
      ;
    } else {
      ;
    }
    int * v246 = v69->mem;
    int v431 = ((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2;
    int v247 = v246[v431];
    int * v248 = v69->mem;
    int v433 = (((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) * 2) + 1;
    int v249 = v248[v433];
    int * v250 = v69->cache_vals;
    int v435 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v224 + ((~(((v226 ^ -1) | (-(v226 ^ -1))) >> 31)) & 2)) - (v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v250[v435] = v247;
    int * v252 = v69->cache_vals;
    int v438 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1)) & 3) * 2)) + ((((v224 + ((~(((v226 ^ -1) | (-(v226 ^ -1))) >> 31)) & 2)) - (v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v252[v438] = v249;
    int * v254 = v69->cache_tags;
    int v441 = (int)((unsigned int)((int)((unsigned int)v76 >> 2)) >> 1);
    v254[v415] = v441;
    int * v256 = v69->cache_dirty;
    v256[v415] = 0;
    int * v258 = v69->cache_age;
    v258[v415] = 1;
    int * v260 = v69->cache_age;
    int v261 = v260[v415];
    int * v262 = v69->cache_age;
    int v263 = v262[v292];
    int * v264 = v69->cache_age;
    int v449 = v263 + ((int)((unsigned int)(v263 - v261) >> 31));
    v264[v292] = v449;
    int * v266 = v69->cache_age;
    int v267 = v266[v294];
    int * v268 = v69->cache_age;
    int v452 = v267 + ((int)((unsigned int)(v267 - v261) >> 31));
    v268[v294] = v452;
    int * v270 = v69->cache_age;
    v270[v415] = 0;
    v273 = v415;
  }
  int * v274 = v69->cache_vals;
  int v455 = (v273 * 2) + (((int)((unsigned int)v76 >> 2)) & 1);
  v274[v455] = v80;
  int * v276 = v69->cache_dirty;
  v276[v273] = 1;
  struct StateT * v278 = slot_4(v69);
  return v278;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v16 = v4 + 1;
  v2->timer = v16;
  int * v6 = v2->reg_ready;
  int v7 = v6[10];
  int * v8 = v2->regs;
  int v9 = v8[10];
  int * v10 = v2->reg_ready;
  int v22 = (v7 + ((v3 - v7) & (~((v3 - v7) >> 31)))) + 1;
  v10[6] = v22;
  int * v12 = v2->regs;
  int v24 = v9 & 28;
  v12[6] = v24;
  struct StateT * v14 = slot_1(v2);
  return v14;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}