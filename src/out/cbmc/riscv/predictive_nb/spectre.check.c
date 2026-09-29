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
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v652);
struct StateT * slot_6(struct StateT * v366);
struct StateT * slot_5(struct StateT * v104);
struct StateT * slot_4(struct StateT * v65);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v390);
struct StateT * slot_3(struct StateT * v56);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v881 = v1->timer;
  int * v882 = v1->reg_ready;
  int v883 = v882[0];
  int v1014 = v883 + ((v881 - v883) & (~((v881 - v883) >> 31)));
  v1->timer = v1014;
  int v885 = v1->timer;
  int * v886 = v1->reg_ready;
  int v887 = v886[1];
  int v1017 = v887 + ((v885 - v887) & (~((v885 - v887) >> 31)));
  v1->timer = v1017;
  int v889 = v1->timer;
  int * v890 = v1->reg_ready;
  int v891 = v890[2];
  int v1020 = v891 + ((v889 - v891) & (~((v889 - v891) >> 31)));
  v1->timer = v1020;
  int v893 = v1->timer;
  int * v894 = v1->reg_ready;
  int v895 = v894[3];
  int v1023 = v895 + ((v893 - v895) & (~((v893 - v895) >> 31)));
  v1->timer = v1023;
  int v897 = v1->timer;
  int * v898 = v1->reg_ready;
  int v899 = v898[4];
  int v1026 = v899 + ((v897 - v899) & (~((v897 - v899) >> 31)));
  v1->timer = v1026;
  int v901 = v1->timer;
  int * v902 = v1->reg_ready;
  int v903 = v902[5];
  int v1029 = v903 + ((v901 - v903) & (~((v901 - v903) >> 31)));
  v1->timer = v1029;
  int v905 = v1->timer;
  int * v906 = v1->reg_ready;
  int v907 = v906[6];
  int v1032 = v907 + ((v905 - v907) & (~((v905 - v907) >> 31)));
  v1->timer = v1032;
  int v909 = v1->timer;
  int * v910 = v1->reg_ready;
  int v911 = v910[7];
  int v1035 = v911 + ((v909 - v911) & (~((v909 - v911) >> 31)));
  v1->timer = v1035;
  int v913 = v1->timer;
  int * v914 = v1->reg_ready;
  int v915 = v914[8];
  int v1038 = v915 + ((v913 - v915) & (~((v913 - v915) >> 31)));
  v1->timer = v1038;
  int v917 = v1->timer;
  int * v918 = v1->reg_ready;
  int v919 = v918[9];
  int v1041 = v919 + ((v917 - v919) & (~((v917 - v919) >> 31)));
  v1->timer = v1041;
  int v921 = v1->timer;
  int * v922 = v1->reg_ready;
  int v923 = v922[10];
  int v1044 = v923 + ((v921 - v923) & (~((v921 - v923) >> 31)));
  v1->timer = v1044;
  int v925 = v1->timer;
  int * v926 = v1->reg_ready;
  int v927 = v926[11];
  int v1047 = v927 + ((v925 - v927) & (~((v925 - v927) >> 31)));
  v1->timer = v1047;
  int v929 = v1->timer;
  int * v930 = v1->reg_ready;
  int v931 = v930[12];
  int v1050 = v931 + ((v929 - v931) & (~((v929 - v931) >> 31)));
  v1->timer = v1050;
  int v933 = v1->timer;
  int * v934 = v1->reg_ready;
  int v935 = v934[13];
  int v1053 = v935 + ((v933 - v935) & (~((v933 - v935) >> 31)));
  v1->timer = v1053;
  int v937 = v1->timer;
  int * v938 = v1->reg_ready;
  int v939 = v938[14];
  int v1056 = v939 + ((v937 - v939) & (~((v937 - v939) >> 31)));
  v1->timer = v1056;
  int v941 = v1->timer;
  int * v942 = v1->reg_ready;
  int v943 = v942[15];
  int v1059 = v943 + ((v941 - v943) & (~((v941 - v943) >> 31)));
  v1->timer = v1059;
  int v945 = v1->timer;
  int * v946 = v1->reg_ready;
  int v947 = v946[16];
  int v1062 = v947 + ((v945 - v947) & (~((v945 - v947) >> 31)));
  v1->timer = v1062;
  int v949 = v1->timer;
  int * v950 = v1->reg_ready;
  int v951 = v950[17];
  int v1065 = v951 + ((v949 - v951) & (~((v949 - v951) >> 31)));
  v1->timer = v1065;
  int v953 = v1->timer;
  int * v954 = v1->reg_ready;
  int v955 = v954[18];
  int v1068 = v955 + ((v953 - v955) & (~((v953 - v955) >> 31)));
  v1->timer = v1068;
  int v957 = v1->timer;
  int * v958 = v1->reg_ready;
  int v959 = v958[19];
  int v1071 = v959 + ((v957 - v959) & (~((v957 - v959) >> 31)));
  v1->timer = v1071;
  int v961 = v1->timer;
  int * v962 = v1->reg_ready;
  int v963 = v962[20];
  int v1074 = v963 + ((v961 - v963) & (~((v961 - v963) >> 31)));
  v1->timer = v1074;
  int v965 = v1->timer;
  int * v966 = v1->reg_ready;
  int v967 = v966[21];
  int v1077 = v967 + ((v965 - v967) & (~((v965 - v967) >> 31)));
  v1->timer = v1077;
  int v969 = v1->timer;
  int * v970 = v1->reg_ready;
  int v971 = v970[22];
  int v1080 = v971 + ((v969 - v971) & (~((v969 - v971) >> 31)));
  v1->timer = v1080;
  int v973 = v1->timer;
  int * v974 = v1->reg_ready;
  int v975 = v974[23];
  int v1083 = v975 + ((v973 - v975) & (~((v973 - v975) >> 31)));
  v1->timer = v1083;
  int v977 = v1->timer;
  int * v978 = v1->reg_ready;
  int v979 = v978[24];
  int v1086 = v979 + ((v977 - v979) & (~((v977 - v979) >> 31)));
  v1->timer = v1086;
  int v981 = v1->timer;
  int * v982 = v1->reg_ready;
  int v983 = v982[25];
  int v1089 = v983 + ((v981 - v983) & (~((v981 - v983) >> 31)));
  v1->timer = v1089;
  int v985 = v1->timer;
  int * v986 = v1->reg_ready;
  int v987 = v986[26];
  int v1092 = v987 + ((v985 - v987) & (~((v985 - v987) >> 31)));
  v1->timer = v1092;
  int v989 = v1->timer;
  int * v990 = v1->reg_ready;
  int v991 = v990[27];
  int v1095 = v991 + ((v989 - v991) & (~((v989 - v991) >> 31)));
  v1->timer = v1095;
  int v993 = v1->timer;
  int * v994 = v1->reg_ready;
  int v995 = v994[28];
  int v1098 = v995 + ((v993 - v995) & (~((v993 - v995) >> 31)));
  v1->timer = v1098;
  int v997 = v1->timer;
  int * v998 = v1->reg_ready;
  int v999 = v998[29];
  int v1101 = v999 + ((v997 - v999) & (~((v997 - v999) >> 31)));
  v1->timer = v1101;
  int v1001 = v1->timer;
  int * v1002 = v1->reg_ready;
  int v1003 = v1002[30];
  int v1104 = v1003 + ((v1001 - v1003) & (~((v1001 - v1003) >> 31)));
  v1->timer = v1104;
  int v1005 = v1->timer;
  int * v1006 = v1->reg_ready;
  int v1007 = v1006[31];
  int v1107 = v1007 + ((v1005 - v1007) & (~((v1005 - v1007) >> 31)));
  v1->timer = v1107;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[10] = v33;
  int * v26 = v20->regs;
  v26[10] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v652) {
  int * v653 = v652->regs;
  int v654 = v653[10];
  int * v655 = v652->regs;
  int v656 = v655[15];
  bool v775 = v654 >= v656;
  struct StateT * v769;
  if (v775) {
    int v657 = v652->timer;
    int v776 = v657 + 15;
    v652->timer = v776;
    int * v659 = v652->saved_regs;
    int v660 = v659[5];
    int * v661 = v652->regs;
    v661[5] = v660;
    int * v663 = v652->saved_regs;
    int v664 = v663[11];
    int * v665 = v652->regs;
    v665[11] = v664;
    int * v667 = v652->saved_regs;
    int v668 = v667[12];
    int * v669 = v652->regs;
    v669[12] = v668;
    int * v671 = v652->reg_ready;
    int v672 = v652->timer;
    v671[0] = v672;
    int * v674 = v652->reg_ready;
    int v675 = v652->timer;
    v674[1] = v675;
    int * v677 = v652->reg_ready;
    int v678 = v652->timer;
    v677[2] = v678;
    int * v680 = v652->reg_ready;
    int v681 = v652->timer;
    v680[3] = v681;
    int * v683 = v652->reg_ready;
    int v684 = v652->timer;
    v683[4] = v684;
    int * v686 = v652->reg_ready;
    int v687 = v652->timer;
    v686[5] = v687;
    int * v689 = v652->reg_ready;
    int v690 = v652->timer;
    v689[6] = v690;
    int * v692 = v652->reg_ready;
    int v693 = v652->timer;
    v692[7] = v693;
    int * v695 = v652->reg_ready;
    int v696 = v652->timer;
    v695[8] = v696;
    int * v698 = v652->reg_ready;
    int v699 = v652->timer;
    v698[9] = v699;
    int * v701 = v652->reg_ready;
    int v702 = v652->timer;
    v701[10] = v702;
    int * v704 = v652->reg_ready;
    int v705 = v652->timer;
    v704[11] = v705;
    int * v707 = v652->reg_ready;
    int v708 = v652->timer;
    v707[12] = v708;
    int * v710 = v652->reg_ready;
    int v711 = v652->timer;
    v710[13] = v711;
    int * v713 = v652->reg_ready;
    int v714 = v652->timer;
    v713[14] = v714;
    int * v716 = v652->reg_ready;
    int v717 = v652->timer;
    v716[15] = v717;
    int * v719 = v652->reg_ready;
    int v720 = v652->timer;
    v719[16] = v720;
    int * v722 = v652->reg_ready;
    int v723 = v652->timer;
    v722[17] = v723;
    int * v725 = v652->reg_ready;
    int v726 = v652->timer;
    v725[18] = v726;
    int * v728 = v652->reg_ready;
    int v729 = v652->timer;
    v728[19] = v729;
    int * v731 = v652->reg_ready;
    int v732 = v652->timer;
    v731[20] = v732;
    int * v734 = v652->reg_ready;
    int v735 = v652->timer;
    v734[21] = v735;
    int * v737 = v652->reg_ready;
    int v738 = v652->timer;
    v737[22] = v738;
    int * v740 = v652->reg_ready;
    int v741 = v652->timer;
    v740[23] = v741;
    int * v743 = v652->reg_ready;
    int v744 = v652->timer;
    v743[24] = v744;
    int * v746 = v652->reg_ready;
    int v747 = v652->timer;
    v746[25] = v747;
    int * v749 = v652->reg_ready;
    int v750 = v652->timer;
    v749[26] = v750;
    int * v752 = v652->reg_ready;
    int v753 = v652->timer;
    v752[27] = v753;
    int * v755 = v652->reg_ready;
    int v756 = v652->timer;
    v755[28] = v756;
    int * v758 = v652->reg_ready;
    int v759 = v652->timer;
    v758[29] = v759;
    int * v761 = v652->reg_ready;
    int v762 = v652->timer;
    v761[30] = v762;
    int * v764 = v652->reg_ready;
    int v765 = v652->timer;
    v764[31] = v765;
    v769 = v652;
  } else {
    v769 = v652;
  }
  return v769;
}

struct StateT * slot_6(struct StateT * v366) {
  int v367 = v366->timer;
  int v368 = v366->timer;
  int v380 = v368 + 1;
  v366->timer = v380;
  int * v370 = v366->reg_ready;
  int v371 = v370[11];
  int * v372 = v366->regs;
  int v373 = v372[11];
  int * v374 = v366->reg_ready;
  int v385 = (v371 + ((v367 - v371) & (~((v367 - v371) >> 31)))) + 1;
  v374[11] = v385;
  int * v376 = v366->regs;
  int v387 = v373 << 2;
  v376[11] = v387;
  struct StateT * v378 = slot_7(v366);
  return v378;
}

struct StateT * slot_5(struct StateT * v104) {
  int * v105 = v104->saved_regs;
  int * v106 = v104->regs;
  int v107 = v106[11];
  v105[11] = v107;
  int v109 = v104->timer;
  int v110 = v104->timer;
  int v249 = v110 + 1;
  v104->timer = v249;
  int * v112 = v104->reg_ready;
  int v113 = v112[5];
  int * v114 = v104->regs;
  int v115 = v114[5];
  int * v116 = v104->cache_tags;
  int v254 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2;
  int v117 = v116[v254];
  int * v118 = v104->cache_tags;
  int v256 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + 1;
  int v119 = v118[v256];
  int * v120 = v104->cache_tags;
  int v258 = 4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2);
  int v121 = v120[v258];
  int * v122 = v104->cache_tags;
  int v260 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v123 = v122[v260];
  int * v124 = v104->cache_vals;
  bool v261 = !(((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) == 0);
  int v237;
  if (v261) {
    int * v125 = v104->cache_age;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) & 1);
    int v126 = v125[v263];
    int * v127 = v104->cache_age;
    int v128 = v127[v254];
    int * v129 = v104->cache_age;
    int v266 = v128 + ((int)((unsigned int)(v128 - v126) >> 31));
    v129[v254] = v266;
    int * v131 = v104->cache_age;
    int v132 = v131[v256];
    int * v133 = v104->cache_age;
    int v269 = v132 + ((int)((unsigned int)(v132 - v126) >> 31));
    v133[v256] = v269;
    int * v135 = v104->cache_age;
    v135[v263] = 0;
    v237 = v263;
  } else {
    int * v138 = v104->cache_age;
    int v273 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2;
    int v139 = v138[v273];
    int * v140 = v104->cache_tags;
    int v141 = v140[v273];
    int * v142 = v104->cache_age;
    int v143 = v142[v256];
    int * v144 = v104->cache_tags;
    int v145 = v144[v256];
    bool v277 = !(((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) == 0);
    int v209;
    if (v277) {
      int * v146 = v104->cache_age;
      int v279 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) & 1);
      int v147 = v146[v279];
      int * v148 = v104->cache_age;
      int v149 = v148[v258];
      int * v150 = v104->cache_age;
      int v282 = v149 + ((int)((unsigned int)(v149 - v147) >> 31));
      v150[v258] = v282;
      int * v152 = v104->cache_age;
      int v153 = v152[v260];
      int * v154 = v104->cache_age;
      int v285 = v153 + ((int)((unsigned int)(v153 - v147) >> 31));
      v154[v260] = v285;
      int * v156 = v104->cache_age;
      v156[v279] = 0;
      v209 = v279;
    } else {
      int * v159 = v104->cache_age;
      int v289 = 4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2);
      int v160 = v159[v289];
      int * v161 = v104->cache_tags;
      int v162 = v161[v289];
      int * v163 = v104->cache_age;
      int v164 = v163[v260];
      int * v165 = v104->cache_tags;
      int v166 = v165[v260];
      int * v167 = v104->cache_dirty;
      int v294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v168 = v167[v294];
      bool v295 = !(v168 == 0);
      if (v295) {
        int * v169 = v104->cache_tags;
        int v170 = v169[v294];
        int * v171 = v104->cache_vals;
        int v298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v172 = v171[v298];
        int * v173 = v104->cache_vals;
        int v300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174 = v173[v300];
        int * v175 = v104->mem;
        int v302 = v170 * 2;
        v175[v302] = v172;
        int * v177 = v104->mem;
        int v305 = (v170 * 2) + 1;
        v177[v305] = v174;
        ;
      } else {
        ;
      }
      int * v182 = v104->mem;
      int v310 = ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) * 2;
      int v183 = v182[v310];
      int * v184 = v104->mem;
      int v312 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) * 2) + 1;
      int v185 = v184[v312];
      int * v186 = v104->cache_vals;
      int v314 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v186[v314] = v183;
      int * v188 = v104->cache_vals;
      int v317 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v188[v317] = v185;
      int * v190 = v104->cache_tags;
      int v320 = (int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1);
      v190[v294] = v320;
      int * v192 = v104->cache_dirty;
      v192[v294] = 0;
      int * v194 = v104->cache_age;
      v194[v294] = 1;
      int * v196 = v104->cache_age;
      int v197 = v196[v294];
      int * v198 = v104->cache_age;
      int v199 = v198[v258];
      int * v200 = v104->cache_age;
      int v328 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
      v200[v258] = v328;
      int * v202 = v104->cache_age;
      int v203 = v202[v260];
      int * v204 = v104->cache_age;
      int v331 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
      v204[v260] = v331;
      int * v206 = v104->cache_age;
      v206[v294] = 0;
      v209 = v294;
    }
    int * v210 = v104->cache_vals;
    int v334 = v209 * 2;
    int v211 = v210[v334];
    int * v212 = v104->cache_vals;
    int v336 = (v209 * 2) + 1;
    int v213 = v212[v336];
    int * v214 = v104->cache_vals;
    int v338 = (((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214[v338] = v211;
    int * v216 = v104->cache_vals;
    int v341 = ((((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216[v341] = v213;
    int * v218 = v104->cache_tags;
    int v344 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v345 = (int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1);
    v218[v344] = v345;
    int * v220 = v104->cache_dirty;
    v220[v344] = 0;
    int * v222 = v104->cache_age;
    v222[v344] = 1;
    int * v224 = v104->cache_age;
    int v225 = v224[v344];
    int * v226 = v104->cache_age;
    int v227 = v226[v254];
    int * v228 = v104->cache_age;
    int v353 = v227 + ((int)((unsigned int)(v227 - v225) >> 31));
    v228[v254] = v353;
    int * v230 = v104->cache_age;
    int v231 = v230[v256];
    int * v232 = v104->cache_age;
    int v356 = v231 + ((int)((unsigned int)(v231 - v225) >> 31));
    v232[v256] = v356;
    int * v234 = v104->cache_age;
    v234[v344] = 0;
    v237 = v344;
  }
  int v359 = (v237 * 2) + (((int)((unsigned int)v115 >> 2)) & 1);
  int v238 = v124[v359];
  int * v239 = v104->reg_ready;
  int v361 = ((v113 + ((v109 - v113) & (~((v109 - v113) >> 31)))) + 1) + ((100 ^ (((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & 104)))));
  v239[11] = v361;
  int * v241 = v104->regs;
  v241[11] = v238;
  struct StateT * v243 = slot_6(v104);
  return v243;
}

struct StateT * slot_4(struct StateT * v65) {
  int * v66 = v65->saved_regs;
  int * v67 = v65->regs;
  int v68 = v67[5];
  v66[5] = v68;
  int v70 = v65->timer;
  int v71 = v65->timer;
  int v91 = v71 + 1;
  v65->timer = v91;
  int * v73 = v65->reg_ready;
  int v74 = v73[13];
  int * v75 = v65->regs;
  int v76 = v75[13];
  int * v77 = v65->reg_ready;
  int v78 = v77[10];
  int * v79 = v65->regs;
  int v80 = v79[10];
  int * v81 = v65->reg_ready;
  int v99 = (v78 + (((v74 + ((v70 - v74) & (~((v70 - v74) >> 31)))) - v78) & (~(((v74 + ((v70 - v74) & (~((v70 - v74) >> 31)))) - v78) >> 31)))) + 1;
  v81[5] = v99;
  int * v83 = v65->regs;
  int v101 = v76 + v80;
  v83[5] = v101;
  struct StateT * v85 = slot_5(v65);
  return v85;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[15] = v51;
  int * v44 = v38->regs;
  v44[15] = 80;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v390) {
  int * v391 = v390->saved_regs;
  int * v392 = v390->regs;
  int v393 = v392[12];
  v391[12] = v393;
  int v395 = v390->timer;
  int v396 = v390->timer;
  int v535 = v396 + 1;
  v390->timer = v535;
  int * v398 = v390->reg_ready;
  int v399 = v398[11];
  int * v400 = v390->regs;
  int v401 = v400[11];
  int * v402 = v390->cache_tags;
  int v540 = (((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2;
  int v403 = v402[v540];
  int * v404 = v390->cache_tags;
  int v542 = ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + 1;
  int v405 = v404[v542];
  int * v406 = v390->cache_tags;
  int v544 = 4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2);
  int v407 = v406[v544];
  int * v408 = v390->cache_tags;
  int v546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v409 = v408[v546];
  int * v410 = v390->cache_vals;
  bool v547 = !(((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) == 0);
  int v523;
  if (v547) {
    int * v411 = v390->cache_age;
    int v549 = ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) & 1);
    int v412 = v411[v549];
    int * v413 = v390->cache_age;
    int v414 = v413[v540];
    int * v415 = v390->cache_age;
    int v552 = v414 + ((int)((unsigned int)(v414 - v412) >> 31));
    v415[v540] = v552;
    int * v417 = v390->cache_age;
    int v418 = v417[v542];
    int * v419 = v390->cache_age;
    int v555 = v418 + ((int)((unsigned int)(v418 - v412) >> 31));
    v419[v542] = v555;
    int * v421 = v390->cache_age;
    v421[v549] = 0;
    v523 = v549;
  } else {
    int * v424 = v390->cache_age;
    int v559 = (((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2;
    int v425 = v424[v559];
    int * v426 = v390->cache_tags;
    int v427 = v426[v559];
    int * v428 = v390->cache_age;
    int v429 = v428[v542];
    int * v430 = v390->cache_tags;
    int v431 = v430[v542];
    bool v563 = !(((~(((v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) == 0);
    int v495;
    if (v563) {
      int * v432 = v390->cache_age;
      int v565 = (4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) & 1);
      int v433 = v432[v565];
      int * v434 = v390->cache_age;
      int v435 = v434[v544];
      int * v436 = v390->cache_age;
      int v568 = v435 + ((int)((unsigned int)(v435 - v433) >> 31));
      v436[v544] = v568;
      int * v438 = v390->cache_age;
      int v439 = v438[v546];
      int * v440 = v390->cache_age;
      int v571 = v439 + ((int)((unsigned int)(v439 - v433) >> 31));
      v440[v546] = v571;
      int * v442 = v390->cache_age;
      v442[v565] = 0;
      v495 = v565;
    } else {
      int * v445 = v390->cache_age;
      int v575 = 4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2);
      int v446 = v445[v575];
      int * v447 = v390->cache_tags;
      int v448 = v447[v575];
      int * v449 = v390->cache_age;
      int v450 = v449[v546];
      int * v451 = v390->cache_tags;
      int v452 = v451[v546];
      int * v453 = v390->cache_dirty;
      int v580 = (4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v454 = v453[v580];
      bool v581 = !(v454 == 0);
      if (v581) {
        int * v455 = v390->cache_tags;
        int v456 = v455[v580];
        int * v457 = v390->cache_vals;
        int v584 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v458 = v457[v584];
        int * v459 = v390->cache_vals;
        int v586 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v460 = v459[v586];
        int * v461 = v390->mem;
        int v588 = v456 * 2;
        v461[v588] = v458;
        int * v463 = v390->mem;
        int v591 = (v456 * 2) + 1;
        v463[v591] = v460;
        ;
      } else {
        ;
      }
      int * v468 = v390->mem;
      int v596 = ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) * 2;
      int v469 = v468[v596];
      int * v470 = v390->mem;
      int v598 = (((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) * 2) + 1;
      int v471 = v470[v598];
      int * v472 = v390->cache_vals;
      int v600 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v472[v600] = v469;
      int * v474 = v390->cache_vals;
      int v603 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v474[v603] = v471;
      int * v476 = v390->cache_tags;
      int v606 = (int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1);
      v476[v580] = v606;
      int * v478 = v390->cache_dirty;
      v478[v580] = 0;
      int * v480 = v390->cache_age;
      v480[v580] = 1;
      int * v482 = v390->cache_age;
      int v483 = v482[v580];
      int * v484 = v390->cache_age;
      int v485 = v484[v544];
      int * v486 = v390->cache_age;
      int v614 = v485 + ((int)((unsigned int)(v485 - v483) >> 31));
      v486[v544] = v614;
      int * v488 = v390->cache_age;
      int v489 = v488[v546];
      int * v490 = v390->cache_age;
      int v617 = v489 + ((int)((unsigned int)(v489 - v483) >> 31));
      v490[v546] = v617;
      int * v492 = v390->cache_age;
      v492[v580] = 0;
      v495 = v580;
    }
    int * v496 = v390->cache_vals;
    int v620 = v495 * 2;
    int v497 = v496[v620];
    int * v498 = v390->cache_vals;
    int v622 = (v495 * 2) + 1;
    int v499 = v498[v622];
    int * v500 = v390->cache_vals;
    int v624 = (((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((((v425 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v500[v624] = v497;
    int * v502 = v390->cache_vals;
    int v627 = ((((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((((v425 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v502[v627] = v499;
    int * v504 = v390->cache_tags;
    int v630 = ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((((v425 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v631 = (int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1);
    v504[v630] = v631;
    int * v506 = v390->cache_dirty;
    v506[v630] = 0;
    int * v508 = v390->cache_age;
    v508[v630] = 1;
    int * v510 = v390->cache_age;
    int v511 = v510[v630];
    int * v512 = v390->cache_age;
    int v513 = v512[v540];
    int * v514 = v390->cache_age;
    int v639 = v513 + ((int)((unsigned int)(v513 - v511) >> 31));
    v514[v540] = v639;
    int * v516 = v390->cache_age;
    int v517 = v516[v542];
    int * v518 = v390->cache_age;
    int v642 = v517 + ((int)((unsigned int)(v517 - v511) >> 31));
    v518[v542] = v642;
    int * v520 = v390->cache_age;
    v520[v630] = 0;
    v523 = v630;
  }
  int v645 = (v523 * 2) + (((int)((unsigned int)v401 >> 2)) & 1);
  int v524 = v410[v645];
  int * v525 = v390->reg_ready;
  int v647 = ((v399 + ((v395 - v399) & (~((v395 - v399) >> 31)))) + 1) + ((100 ^ (((~(((v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) & 104)))));
  v525[12] = v647;
  int * v527 = v390->regs;
  v527[12] = v524;
  struct StateT * v529 = slot_8(v390);
  return v529;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v62 = v58 + 1;
  v56->timer = v62;
  struct StateT * v60 = slot_4(v56);
  return v60;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[13] = v15;
  int * v8 = v2->regs;
  v8[13] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}