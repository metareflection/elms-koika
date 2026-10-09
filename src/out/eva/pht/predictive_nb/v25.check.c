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

struct StateT * slot_12(struct StateT * v613);
struct StateT * slot_6(struct StateT * v297);
struct StateT * slot_29(struct StateT * v1498);
struct StateT * slot_23(struct StateT * v1006);
struct StateT * slot_5(struct StateT * v289);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v318);
struct StateT * slot_21(struct StateT * v775);
struct StateT * slot_31(struct StateT * v1838);
struct StateT * slot_3(struct StateT * v240);
struct StateT * slot_26(struct StateT * v1250);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_13(struct StateT * v634);
struct StateT * slot_38(struct StateT * v2327);
struct StateT * slot_24(struct StateT * v1022);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v658);
struct StateT * slot_28(struct StateT * v1474);
struct StateT * slot_32(struct StateT * v1859);
struct StateT * slot_33(struct StateT * v1864);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v273);
struct StateT * slot_15(struct StateT * v674);
struct StateT * slot_18(struct StateT * v746);
struct StateT * slot_9(struct StateT * v553);
struct StateT * slot_11(struct StateT * v592);
struct StateT * slot_12(struct StateT * v613) {
  int v614 = v613->timer;
  int v625 = v614 + 1;
  v613->timer = v625;
  int * v616 = v613->reg_ready;
  int v617 = v616[11];
  int * v618 = v613->regs;
  int v619 = v618[11];
  int v629 = (v617 + ((v614 - v617) & (~((v614 - v617) >> 31)))) + 1;
  v616[11] = v629;
  int * v621 = v613->regs;
  int v631 = v619 + 4;
  v621[11] = v631;
  struct StateT * v623 = slot_14(v613);
  return v623;
}

struct StateT * slot_6(struct StateT * v297) {
  int v298 = v297->timer;
  int v309 = v298 + 1;
  v297->timer = v309;
  int * v300 = v297->reg_ready;
  int v301 = v300[10];
  int * v302 = v297->regs;
  int v303 = v302[10];
  int v313 = (v301 + ((v298 - v301) & (~((v298 - v301) >> 31)))) + 1;
  v300[10] = v313;
  int * v305 = v297->regs;
  int v315 = v303 + 72;
  v305[10] = v315;
  struct StateT * v307 = slot_21(v297);
  return v307;
}

struct StateT * slot_29(struct StateT * v1498) {
  int v1499 = v1498->timer;
  int v1510 = v1499 + 1;
  v1498->timer = v1510;
  int * v1501 = v1498->reg_ready;
  int v1502 = v1501[10];
  int * v1503 = v1498->regs;
  int v1504 = v1503[10];
  int v1514 = (v1502 + ((v1499 - v1502) & (~((v1499 - v1502) >> 31)))) + 1;
  v1501[10] = v1514;
  int * v1506 = v1498->regs;
  int v1516 = v1504 << 29;
  v1506[10] = v1516;
  struct StateT * v1508 = slot_31(v1498);
  return v1508;
}

struct StateT * slot_23(struct StateT * v1006) {
  int v1007 = v1006->timer;
  int v1015 = v1007 + 1;
  v1006->timer = v1015;
  int * v1009 = v1006->reg_ready;
  v1009[11] = v1015;
  int * v1011 = v1006->regs;
  v1011[11] = 0;
  struct StateT * v1013 = slot_12(v1006);
  return v1013;
}

struct StateT * slot_5(struct StateT * v289) {
  int v290 = v289->timer;
  int v294 = v290 + 1;
  v289->timer = v294;
  struct StateT * v292 = slot_7(v289);
  return v292;
}

struct StateT * slot_2(struct StateT * v33) {
  int v34 = v33->timer;
  int v146 = v34 + 1;
  v33->timer = v146;
  int * v36 = v33->reg_ready;
  int v37 = v36[11];
  int * v38 = v33->regs;
  int v39 = v38[11];
  int * v40 = v33->cache_tags;
  int v151 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2;
  int v41 = v40[v151];
  int v152 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + 1;
  int v42 = v40[v152];
  int v153 = 4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2);
  int v43 = v40[v153];
  int v154 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v44 = v40[v154];
  int * v45 = v33->cache_vals;
  bool v155 = !(((~(((v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) == 0);
  int v138;
  if (v155) {
    int * v46 = v33->cache_age;
    int v157 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) & 1);
    int v47 = v46[v157];
    int v48 = v46[v151];
    int v158 = v48 + ((int)((unsigned int)(v48 - v47) >> 31));
    v46[v151] = v158;
    int * v50 = v33->cache_age;
    int v51 = v50[v152];
    int v160 = v51 + ((int)((unsigned int)(v51 - v47) >> 31));
    v50[v152] = v160;
    int * v53 = v33->cache_age;
    v53[v157] = 0;
    v138 = v157;
  } else {
    int * v56 = v33->cache_age;
    int v164 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2;
    int v57 = v56[v164];
    int * v58 = v33->cache_tags;
    int v59 = v58[v164];
    int v60 = v56[v152];
    int v61 = v58[v152];
    bool v166 = !(((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) == 0);
    int v115;
    if (v166) {
      int * v62 = v33->cache_age;
      int v168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) & 1);
      int v63 = v62[v168];
      int v64 = v62[v153];
      int v169 = v64 + ((int)((unsigned int)(v64 - v63) >> 31));
      v62[v153] = v169;
      int * v66 = v33->cache_age;
      int v67 = v66[v154];
      int v171 = v67 + ((int)((unsigned int)(v67 - v63) >> 31));
      v66[v154] = v171;
      int * v69 = v33->cache_age;
      v69[v168] = 0;
      v115 = v168;
    } else {
      int * v72 = v33->cache_age;
      int v175 = 4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2);
      int v73 = v72[v175];
      int * v74 = v33->cache_tags;
      int v75 = v74[v175];
      int v76 = v72[v154];
      int v77 = v74[v154];
      int * v78 = v33->cache_dirty;
      int v178 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v79 = v78[v178];
      bool v179 = !(v79 == 0);
      if (v179) {
        int * v80 = v33->cache_tags;
        int v81 = v80[v178];
        int * v82 = v33->cache_vals;
        int v182 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v83 = v82[v182];
        int v183 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v84 = v82[v183];
        int * v85 = v33->mem;
        int v185 = v81 * 2;
        v85[v185] = v83;
        int * v87 = v33->mem;
        int v188 = (v81 * 2) + 1;
        v87[v188] = v84;
        ;
      } else {
        ;
      }
      int * v92 = v33->mem;
      int v193 = ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) * 2;
      int v93 = v92[v193];
      int v194 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) * 2) + 1;
      int v94 = v92[v194];
      int * v95 = v33->cache_vals;
      int v196 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v95[v196] = v93;
      int * v97 = v33->cache_vals;
      int v199 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v97[v199] = v94;
      int * v99 = v33->cache_tags;
      int v202 = (int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1);
      v99[v178] = v202;
      int * v101 = v33->cache_dirty;
      v101[v178] = 0;
      int * v103 = v33->cache_age;
      v103[v178] = 1;
      int * v105 = v33->cache_age;
      int v106 = v105[v178];
      int v107 = v105[v153];
      int v208 = v107 + ((int)((unsigned int)(v107 - v106) >> 31));
      v105[v153] = v208;
      int * v109 = v33->cache_age;
      int v110 = v109[v154];
      int v210 = v110 + ((int)((unsigned int)(v110 - v106) >> 31));
      v109[v154] = v210;
      int * v112 = v33->cache_age;
      v112[v178] = 0;
      v115 = v178;
    }
    int * v116 = v33->cache_vals;
    int v213 = v115 * 2;
    int v117 = v116[v213];
    int v214 = (v115 * 2) + 1;
    int v118 = v116[v214];
    int v215 = (((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v116[v215] = v117;
    int * v120 = v33->cache_vals;
    int v218 = ((((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v120[v218] = v118;
    int * v122 = v33->cache_tags;
    int v221 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v222 = (int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1);
    v122[v221] = v222;
    int * v124 = v33->cache_dirty;
    v124[v221] = 0;
    int * v126 = v33->cache_age;
    v126[v221] = 1;
    int * v128 = v33->cache_age;
    int v129 = v128[v221];
    int v130 = v128[v151];
    int v228 = v130 + ((int)((unsigned int)(v130 - v129) >> 31));
    v128[v151] = v228;
    int * v132 = v33->cache_age;
    int v133 = v132[v152];
    int v230 = v133 + ((int)((unsigned int)(v133 - v129) >> 31));
    v132[v152] = v230;
    int * v135 = v33->cache_age;
    v135[v221] = 0;
    v138 = v221;
  }
  int v233 = (v138 * 2) + (((int)((unsigned int)v39 >> 2)) & 1);
  int v139 = v45[v233];
  int * v140 = v33->reg_ready;
  int v235 = ((v37 + ((v34 - v37) & (~((v34 - v37) >> 31)))) + 1) + ((100 ^ (((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & 104)))));
  v140[11] = v235;
  int * v142 = v33->regs;
  v142[11] = v139;
  struct StateT * v144 = slot_3(v33);
  return v144;
}

struct StateT * slot_7(struct StateT * v318) {
  int * v319 = v318->saved_regs;
  int * v320 = v318->regs;
  int v321 = v320[10];
  v319[10] = v321;
  int v323 = v318->timer;
  int v338 = v323 + 1;
  v318->timer = v338;
  int * v325 = v318->reg_ready;
  int v326 = v325[10];
  int * v327 = v318->regs;
  int v328 = v327[10];
  int v341 = (v326 + ((v323 - v326) & (~((v323 - v326) >> 31)))) + 1;
  v325[10] = v341;
  int * v330 = v318->regs;
  int v343 = v328 << 2;
  v330[10] = v343;
  struct StateT * v332 = slot_9(v318);
  return v332;
}

struct StateT * slot_21(struct StateT * v775) {
  int v776 = v775->timer;
  int v888 = v776 + 1;
  v775->timer = v888;
  int * v778 = v775->reg_ready;
  int v779 = v778[10];
  int * v780 = v775->regs;
  int v781 = v780[10];
  int * v782 = v775->cache_tags;
  int v893 = (((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2;
  int v783 = v782[v893];
  int v894 = ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2) + 1;
  int v784 = v782[v894];
  int v895 = 4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2);
  int v785 = v782[v895];
  int v896 = (4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v786 = v782[v896];
  int * v787 = v775->cache_vals;
  bool v897 = !(((~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31))) == 0);
  int v880;
  if (v897) {
    int * v788 = v775->cache_age;
    int v899 = ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2) + ((~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) & 1);
    int v789 = v788[v899];
    int v790 = v788[v893];
    int v900 = v790 + ((int)((unsigned int)(v790 - v789) >> 31));
    v788[v893] = v900;
    int * v792 = v775->cache_age;
    int v793 = v792[v894];
    int v902 = v793 + ((int)((unsigned int)(v793 - v789) >> 31));
    v792[v894] = v902;
    int * v795 = v775->cache_age;
    v795[v899] = 0;
    v880 = v899;
  } else {
    int * v798 = v775->cache_age;
    int v906 = (((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2;
    int v799 = v798[v906];
    int * v800 = v775->cache_tags;
    int v801 = v800[v906];
    int v802 = v798[v894];
    int v803 = v800[v894];
    bool v908 = !(((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31))) == 0);
    int v857;
    if (v908) {
      int * v804 = v775->cache_age;
      int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + ((~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) & 1);
      int v805 = v804[v910];
      int v806 = v804[v895];
      int v911 = v806 + ((int)((unsigned int)(v806 - v805) >> 31));
      v804[v895] = v911;
      int * v808 = v775->cache_age;
      int v809 = v808[v896];
      int v913 = v809 + ((int)((unsigned int)(v809 - v805) >> 31));
      v808[v896] = v913;
      int * v811 = v775->cache_age;
      v811[v910] = 0;
      v857 = v910;
    } else {
      int * v814 = v775->cache_age;
      int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2);
      int v815 = v814[v917];
      int * v816 = v775->cache_tags;
      int v817 = v816[v917];
      int v818 = v814[v896];
      int v819 = v816[v896];
      int * v820 = v775->cache_dirty;
      int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v821 = v820[v920];
      bool v921 = !(v821 == 0);
      if (v921) {
        int * v822 = v775->cache_tags;
        int v823 = v822[v920];
        int * v824 = v775->cache_vals;
        int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v825 = v824[v924];
        int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v826 = v824[v925];
        int * v827 = v775->mem;
        int v927 = v823 * 2;
        v827[v927] = v825;
        int * v829 = v775->mem;
        int v930 = (v823 * 2) + 1;
        v829[v930] = v826;
        ;
      } else {
        ;
      }
      int * v834 = v775->mem;
      int v935 = ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) * 2;
      int v835 = v834[v935];
      int v936 = (((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) * 2) + 1;
      int v836 = v834[v936];
      int * v837 = v775->cache_vals;
      int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v837[v938] = v835;
      int * v839 = v775->cache_vals;
      int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v818 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v839[v941] = v836;
      int * v841 = v775->cache_tags;
      int v944 = (int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1);
      v841[v920] = v944;
      int * v843 = v775->cache_dirty;
      v843[v920] = 0;
      int * v845 = v775->cache_age;
      v845[v920] = 1;
      int * v847 = v775->cache_age;
      int v848 = v847[v920];
      int v849 = v847[v895];
      int v950 = v849 + ((int)((unsigned int)(v849 - v848) >> 31));
      v847[v895] = v950;
      int * v851 = v775->cache_age;
      int v852 = v851[v896];
      int v952 = v852 + ((int)((unsigned int)(v852 - v848) >> 31));
      v851[v896] = v952;
      int * v854 = v775->cache_age;
      v854[v920] = 0;
      v857 = v920;
    }
    int * v858 = v775->cache_vals;
    int v955 = v857 * 2;
    int v859 = v858[v955];
    int v956 = (v857 * 2) + 1;
    int v860 = v858[v956];
    int v957 = (((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v802 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v858[v957] = v859;
    int * v862 = v775->cache_vals;
    int v960 = ((((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v802 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v862[v960] = v860;
    int * v864 = v775->cache_tags;
    int v963 = ((((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1)) & 1) * 2) + ((((v799 + ((~(((v801 ^ -1) | (-(v801 ^ -1))) >> 31)) & 2)) - (v802 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v964 = (int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1);
    v864[v963] = v964;
    int * v866 = v775->cache_dirty;
    v866[v963] = 0;
    int * v868 = v775->cache_age;
    v868[v963] = 1;
    int * v870 = v775->cache_age;
    int v871 = v870[v963];
    int v872 = v870[v893];
    int v970 = v872 + ((int)((unsigned int)(v872 - v871) >> 31));
    v870[v893] = v970;
    int * v874 = v775->cache_age;
    int v875 = v874[v894];
    int v972 = v875 + ((int)((unsigned int)(v875 - v871) >> 31));
    v874[v894] = v972;
    int * v877 = v775->cache_age;
    v877[v963] = 0;
    v880 = v963;
  }
  int v975 = (v880 * 2) + (((int)((unsigned int)v781 >> 2)) & 1);
  int v881 = v787[v975];
  int * v882 = v775->reg_ready;
  int v977 = ((v779 + ((v776 - v779) & (~((v776 - v779) >> 31)))) + 1) + ((100 ^ (((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v781 >> 2)) >> 1))))) >> 31))) & 104)))));
  v882[10] = v977;
  int * v884 = v775->regs;
  v884[10] = v881;
  struct StateT * v886 = slot_23(v775);
  return v886;
}

struct StateT * slot_31(struct StateT * v1838) {
  int v1839 = v1838->timer;
  int v1850 = v1839 + 1;
  v1838->timer = v1850;
  int * v1841 = v1838->reg_ready;
  int v1842 = v1841[10];
  int * v1843 = v1838->regs;
  int v1844 = v1843[10];
  int v1854 = (v1842 + ((v1839 - v1842) & (~((v1839 - v1842) >> 31)))) + 1;
  v1841[10] = v1854;
  int * v1846 = v1838->regs;
  int v1856 = (int)((unsigned int)v1844 >> 26);
  v1846[10] = v1856;
  struct StateT * v1848 = slot_33(v1838);
  return v1848;
}

struct StateT * slot_3(struct StateT * v240) {
  int * v241 = v240->regs;
  int v242 = v241[10];
  bool v260 = v242 == 0;
  struct StateT * v256;
  if (v260) {
    int v243 = v240->timer;
    int v261 = v243 + 15;
    v240->timer = v261;
    int * v245 = v240->saved_regs;
    int v246 = v245[11];
    int * v247 = v240->regs;
    v247[11] = v246;
    int * v249 = v240->reg_ready;
    int v250 = v240->timer;
    v249[11] = v250;
    struct StateT * v252 = slot_4(v240);
    v256 = v252;
  } else {
    struct StateT * v254 = slot_5(v240);
    v256 = v254;
  }
  return v256;
}

struct StateT * slot_26(struct StateT * v1250) {
  int v1251 = v1250->timer;
  int v1363 = v1251 + 1;
  v1250->timer = v1363;
  int * v1253 = v1250->reg_ready;
  int v1254 = v1253[12];
  int * v1255 = v1250->regs;
  int v1256 = v1255[12];
  int * v1257 = v1250->cache_tags;
  int v1368 = (((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1258 = v1257[v1368];
  int v1369 = ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1259 = v1257[v1369];
  int v1370 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1260 = v1257[v1370];
  int v1371 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1261 = v1257[v1371];
  int * v1262 = v1250->cache_vals;
  bool v1372 = !(((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1355;
  if (v1372) {
    int * v1263 = v1250->cache_age;
    int v1374 = ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1264 = v1263[v1374];
    int v1265 = v1263[v1368];
    int v1375 = v1265 + ((int)((unsigned int)(v1265 - v1264) >> 31));
    v1263[v1368] = v1375;
    int * v1267 = v1250->cache_age;
    int v1268 = v1267[v1369];
    int v1377 = v1268 + ((int)((unsigned int)(v1268 - v1264) >> 31));
    v1267[v1369] = v1377;
    int * v1270 = v1250->cache_age;
    v1270[v1374] = 0;
    v1355 = v1374;
  } else {
    int * v1273 = v1250->cache_age;
    int v1381 = (((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1274 = v1273[v1381];
    int * v1275 = v1250->cache_tags;
    int v1276 = v1275[v1381];
    int v1277 = v1273[v1369];
    int v1278 = v1275[v1369];
    bool v1383 = !(((~(((v1260 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1260 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1332;
    if (v1383) {
      int * v1279 = v1250->cache_age;
      int v1385 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1280 = v1279[v1385];
      int v1281 = v1279[v1370];
      int v1386 = v1281 + ((int)((unsigned int)(v1281 - v1280) >> 31));
      v1279[v1370] = v1386;
      int * v1283 = v1250->cache_age;
      int v1284 = v1283[v1371];
      int v1388 = v1284 + ((int)((unsigned int)(v1284 - v1280) >> 31));
      v1283[v1371] = v1388;
      int * v1286 = v1250->cache_age;
      v1286[v1385] = 0;
      v1332 = v1385;
    } else {
      int * v1289 = v1250->cache_age;
      int v1392 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1290 = v1289[v1392];
      int * v1291 = v1250->cache_tags;
      int v1292 = v1291[v1392];
      int v1293 = v1289[v1371];
      int v1294 = v1291[v1371];
      int * v1295 = v1250->cache_dirty;
      int v1395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1296 = v1295[v1395];
      bool v1396 = !(v1296 == 0);
      if (v1396) {
        int * v1297 = v1250->cache_tags;
        int v1298 = v1297[v1395];
        int * v1299 = v1250->cache_vals;
        int v1399 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1300 = v1299[v1399];
        int v1400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1301 = v1299[v1400];
        int * v1302 = v1250->mem;
        int v1402 = v1298 * 2;
        v1302[v1402] = v1300;
        int * v1304 = v1250->mem;
        int v1405 = (v1298 * 2) + 1;
        v1304[v1405] = v1301;
        ;
      } else {
        ;
      }
      int * v1309 = v1250->mem;
      int v1410 = ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) * 2;
      int v1310 = v1309[v1410];
      int v1411 = (((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1311 = v1309[v1411];
      int * v1312 = v1250->cache_vals;
      int v1413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1312[v1413] = v1310;
      int * v1314 = v1250->cache_vals;
      int v1416 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1290 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2)) - (v1293 + ((~(((v1294 ^ -1) | (-(v1294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1314[v1416] = v1311;
      int * v1316 = v1250->cache_tags;
      int v1419 = (int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1);
      v1316[v1395] = v1419;
      int * v1318 = v1250->cache_dirty;
      v1318[v1395] = 0;
      int * v1320 = v1250->cache_age;
      v1320[v1395] = 1;
      int * v1322 = v1250->cache_age;
      int v1323 = v1322[v1395];
      int v1324 = v1322[v1370];
      int v1425 = v1324 + ((int)((unsigned int)(v1324 - v1323) >> 31));
      v1322[v1370] = v1425;
      int * v1326 = v1250->cache_age;
      int v1327 = v1326[v1371];
      int v1427 = v1327 + ((int)((unsigned int)(v1327 - v1323) >> 31));
      v1326[v1371] = v1427;
      int * v1329 = v1250->cache_age;
      v1329[v1395] = 0;
      v1332 = v1395;
    }
    int * v1333 = v1250->cache_vals;
    int v1430 = v1332 * 2;
    int v1334 = v1333[v1430];
    int v1431 = (v1332 * 2) + 1;
    int v1335 = v1333[v1431];
    int v1432 = (((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1274 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2)) - (v1277 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1333[v1432] = v1334;
    int * v1337 = v1250->cache_vals;
    int v1435 = ((((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1274 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2)) - (v1277 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1337[v1435] = v1335;
    int * v1339 = v1250->cache_tags;
    int v1438 = ((((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1274 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2)) - (v1277 + ((~(((v1278 ^ -1) | (-(v1278 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1439 = (int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1);
    v1339[v1438] = v1439;
    int * v1341 = v1250->cache_dirty;
    v1341[v1438] = 0;
    int * v1343 = v1250->cache_age;
    v1343[v1438] = 1;
    int * v1345 = v1250->cache_age;
    int v1346 = v1345[v1438];
    int v1347 = v1345[v1368];
    int v1445 = v1347 + ((int)((unsigned int)(v1347 - v1346) >> 31));
    v1345[v1368] = v1445;
    int * v1349 = v1250->cache_age;
    int v1350 = v1349[v1369];
    int v1447 = v1350 + ((int)((unsigned int)(v1350 - v1346) >> 31));
    v1349[v1369] = v1447;
    int * v1352 = v1250->cache_age;
    v1352[v1438] = 0;
    v1355 = v1438;
  }
  int v1450 = (v1355 * 2) + (((int)((unsigned int)(v1256 + 68) >> 2)) & 1);
  int v1356 = v1262[v1450];
  int * v1357 = v1250->reg_ready;
  int v1453 = ((v1254 + ((v1251 - v1254) & (~((v1251 - v1254) >> 31)))) + 1) + ((100 ^ (((~(((v1260 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1260 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1260 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1260 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))) | (-(v1261 ^ ((int)((unsigned int)((int)((unsigned int)(v1256 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1357[11] = v1453;
  int * v1359 = v1250->regs;
  v1359[11] = v1356;
  struct StateT * v1361 = slot_28(v1250);
  return v1361;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v27 = v15 + 1;
  v10->timer = v27;
  int * v17 = v10->reg_ready;
  v17[11] = v27;
  int * v19 = v10->regs;
  v19[11] = 0;
  struct StateT * v21 = slot_2(v10);
  return v21;
}

struct StateT * slot_13(struct StateT * v634) {
  int v635 = v634->timer;
  int v648 = v635 + 1;
  v634->timer = v648;
  int * v637 = v634->reg_ready;
  int v638 = v637[11];
  int * v639 = v634->regs;
  int v640 = v639[11];
  int v641 = v637[10];
  int v642 = v639[10];
  int v653 = (v641 + (((v638 + ((v635 - v638) & (~((v635 - v638) >> 31)))) - v641) & (~(((v638 + ((v635 - v638) & (~((v635 - v638) >> 31)))) - v641) >> 31)))) + 1;
  v637[10] = v653;
  int * v644 = v634->regs;
  int v655 = v640 + v642;
  v644[10] = v655;
  struct StateT * v646 = slot_15(v634);
  return v646;
}

struct StateT * slot_38(struct StateT * v2327) {
  int v2328 = v2327->timer;
  int v2501 = v2328 + 1;
  v2327->timer = v2501;
  int * v2330 = v2327->reg_ready;
  int * v2332 = v2327->regs;
  int v2333 = v2332[12];
  int v2335 = v2332[10];
  int * v2336 = v2327->cache_tags;
  int v2507 = (((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2337 = v2336[v2507];
  int v2508 = ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2338 = v2336[v2508];
  int v2509 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2339 = v2336[v2509];
  int v2510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2340 = v2336[v2510];
  int v2341 = v2327->timer;
  int v2511 = v2341 + ((100 ^ (((~(((v2339 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2339 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2337 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2337 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2338 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2338 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2339 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2339 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2327->timer = v2511;
  bool v2512 = !(((~(((v2337 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2337 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2338 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2338 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2435;
  if (v2512) {
    int * v2343 = v2327->cache_age;
    int v2514 = ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2338 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2338 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2344 = v2343[v2514];
    int v2345 = v2343[v2507];
    int v2515 = v2345 + ((int)((unsigned int)(v2345 - v2344) >> 31));
    v2343[v2507] = v2515;
    int * v2347 = v2327->cache_age;
    int v2348 = v2347[v2508];
    int v2517 = v2348 + ((int)((unsigned int)(v2348 - v2344) >> 31));
    v2347[v2508] = v2517;
    int * v2350 = v2327->cache_age;
    v2350[v2514] = 0;
    v2435 = v2514;
  } else {
    int * v2353 = v2327->cache_age;
    int v2521 = (((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2354 = v2353[v2521];
    int * v2355 = v2327->cache_tags;
    int v2356 = v2355[v2521];
    int v2357 = v2353[v2508];
    int v2358 = v2355[v2508];
    bool v2523 = !(((~(((v2339 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2339 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2412;
    if (v2523) {
      int * v2359 = v2327->cache_age;
      int v2525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2360 = v2359[v2525];
      int v2361 = v2359[v2509];
      int v2526 = v2361 + ((int)((unsigned int)(v2361 - v2360) >> 31));
      v2359[v2509] = v2526;
      int * v2363 = v2327->cache_age;
      int v2364 = v2363[v2510];
      int v2528 = v2364 + ((int)((unsigned int)(v2364 - v2360) >> 31));
      v2363[v2510] = v2528;
      int * v2366 = v2327->cache_age;
      v2366[v2525] = 0;
      v2412 = v2525;
    } else {
      int * v2369 = v2327->cache_age;
      int v2532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2370 = v2369[v2532];
      int * v2371 = v2327->cache_tags;
      int v2372 = v2371[v2532];
      int v2373 = v2369[v2510];
      int v2374 = v2371[v2510];
      int * v2375 = v2327->cache_dirty;
      int v2535 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2370 + ((~(((v2372 ^ -1) | (-(v2372 ^ -1))) >> 31)) & 2)) - (v2373 + ((~(((v2374 ^ -1) | (-(v2374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2376 = v2375[v2535];
      bool v2536 = !(v2376 == 0);
      if (v2536) {
        int * v2377 = v2327->cache_tags;
        int v2378 = v2377[v2535];
        int * v2379 = v2327->cache_vals;
        int v2539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2370 + ((~(((v2372 ^ -1) | (-(v2372 ^ -1))) >> 31)) & 2)) - (v2373 + ((~(((v2374 ^ -1) | (-(v2374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2380 = v2379[v2539];
        int v2540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2370 + ((~(((v2372 ^ -1) | (-(v2372 ^ -1))) >> 31)) & 2)) - (v2373 + ((~(((v2374 ^ -1) | (-(v2374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2381 = v2379[v2540];
        int * v2382 = v2327->mem;
        int v2542 = v2378 * 2;
        v2382[v2542] = v2380;
        int * v2384 = v2327->mem;
        int v2545 = (v2378 * 2) + 1;
        v2384[v2545] = v2381;
        ;
      } else {
        ;
      }
      int * v2389 = v2327->mem;
      int v2550 = ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) * 2;
      int v2390 = v2389[v2550];
      int v2551 = (((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2391 = v2389[v2551];
      int * v2392 = v2327->cache_vals;
      int v2553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2370 + ((~(((v2372 ^ -1) | (-(v2372 ^ -1))) >> 31)) & 2)) - (v2373 + ((~(((v2374 ^ -1) | (-(v2374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2392[v2553] = v2390;
      int * v2394 = v2327->cache_vals;
      int v2556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2370 + ((~(((v2372 ^ -1) | (-(v2372 ^ -1))) >> 31)) & 2)) - (v2373 + ((~(((v2374 ^ -1) | (-(v2374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2394[v2556] = v2391;
      int * v2396 = v2327->cache_tags;
      int v2559 = (int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1);
      v2396[v2535] = v2559;
      int * v2398 = v2327->cache_dirty;
      v2398[v2535] = 0;
      int * v2400 = v2327->cache_age;
      v2400[v2535] = 1;
      int * v2402 = v2327->cache_age;
      int v2403 = v2402[v2535];
      int v2404 = v2402[v2509];
      int v2565 = v2404 + ((int)((unsigned int)(v2404 - v2403) >> 31));
      v2402[v2509] = v2565;
      int * v2406 = v2327->cache_age;
      int v2407 = v2406[v2510];
      int v2567 = v2407 + ((int)((unsigned int)(v2407 - v2403) >> 31));
      v2406[v2510] = v2567;
      int * v2409 = v2327->cache_age;
      v2409[v2535] = 0;
      v2412 = v2535;
    }
    int * v2413 = v2327->cache_vals;
    int v2570 = v2412 * 2;
    int v2414 = v2413[v2570];
    int v2571 = (v2412 * 2) + 1;
    int v2415 = v2413[v2571];
    int v2572 = (((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2354 + ((~(((v2356 ^ -1) | (-(v2356 ^ -1))) >> 31)) & 2)) - (v2357 + ((~(((v2358 ^ -1) | (-(v2358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2413[v2572] = v2414;
    int * v2417 = v2327->cache_vals;
    int v2575 = ((((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2354 + ((~(((v2356 ^ -1) | (-(v2356 ^ -1))) >> 31)) & 2)) - (v2357 + ((~(((v2358 ^ -1) | (-(v2358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2417[v2575] = v2415;
    int * v2419 = v2327->cache_tags;
    int v2578 = ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2354 + ((~(((v2356 ^ -1) | (-(v2356 ^ -1))) >> 31)) & 2)) - (v2357 + ((~(((v2358 ^ -1) | (-(v2358 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2579 = (int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1);
    v2419[v2578] = v2579;
    int * v2421 = v2327->cache_dirty;
    v2421[v2578] = 0;
    int * v2423 = v2327->cache_age;
    v2423[v2578] = 1;
    int * v2425 = v2327->cache_age;
    int v2426 = v2425[v2578];
    int v2427 = v2425[v2507];
    int v2585 = v2427 + ((int)((unsigned int)(v2427 - v2426) >> 31));
    v2425[v2507] = v2585;
    int * v2429 = v2327->cache_age;
    int v2430 = v2429[v2508];
    int v2587 = v2430 + ((int)((unsigned int)(v2430 - v2426) >> 31));
    v2429[v2508] = v2587;
    int * v2432 = v2327->cache_age;
    v2432[v2578] = 0;
    v2435 = v2578;
  }
  int * v2436 = v2327->cache_vals;
  int v2590 = (v2435 * 2) + (((int)((unsigned int)(v2333 + 68) >> 2)) & 1);
  v2436[v2590] = v2335;
  int * v2438 = v2327->cache_tags;
  int v2439 = v2438[v2509];
  int v2440 = v2438[v2510];
  bool v2593 = !(((~(((v2439 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2439 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2440 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2440 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2494;
  if (v2593) {
    int * v2441 = v2327->cache_age;
    int v2595 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2440 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))) | (-(v2440 ^ ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2442 = v2441[v2595];
    int v2443 = v2441[v2509];
    int v2596 = v2443 + ((int)((unsigned int)(v2443 - v2442) >> 31));
    v2441[v2509] = v2596;
    int * v2445 = v2327->cache_age;
    int v2446 = v2445[v2510];
    int v2598 = v2446 + ((int)((unsigned int)(v2446 - v2442) >> 31));
    v2445[v2510] = v2598;
    int * v2448 = v2327->cache_age;
    v2448[v2595] = 0;
    v2494 = v2595;
  } else {
    int * v2451 = v2327->cache_age;
    int v2602 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2452 = v2451[v2602];
    int * v2453 = v2327->cache_tags;
    int v2454 = v2453[v2602];
    int v2455 = v2451[v2510];
    int v2456 = v2453[v2510];
    int * v2457 = v2327->cache_dirty;
    int v2605 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2452 + ((~(((v2454 ^ -1) | (-(v2454 ^ -1))) >> 31)) & 2)) - (v2455 + ((~(((v2456 ^ -1) | (-(v2456 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2458 = v2457[v2605];
    bool v2606 = !(v2458 == 0);
    if (v2606) {
      int * v2459 = v2327->cache_tags;
      int v2460 = v2459[v2605];
      int * v2461 = v2327->cache_vals;
      int v2609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2452 + ((~(((v2454 ^ -1) | (-(v2454 ^ -1))) >> 31)) & 2)) - (v2455 + ((~(((v2456 ^ -1) | (-(v2456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2462 = v2461[v2609];
      int v2610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2452 + ((~(((v2454 ^ -1) | (-(v2454 ^ -1))) >> 31)) & 2)) - (v2455 + ((~(((v2456 ^ -1) | (-(v2456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2463 = v2461[v2610];
      int * v2464 = v2327->mem;
      int v2612 = v2460 * 2;
      v2464[v2612] = v2462;
      int * v2466 = v2327->mem;
      int v2615 = (v2460 * 2) + 1;
      v2466[v2615] = v2463;
      ;
    } else {
      ;
    }
    int * v2471 = v2327->mem;
    int v2620 = ((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) * 2;
    int v2472 = v2471[v2620];
    int v2621 = (((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2473 = v2471[v2621];
    int * v2474 = v2327->cache_vals;
    int v2623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2452 + ((~(((v2454 ^ -1) | (-(v2454 ^ -1))) >> 31)) & 2)) - (v2455 + ((~(((v2456 ^ -1) | (-(v2456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2474[v2623] = v2472;
    int * v2476 = v2327->cache_vals;
    int v2626 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2452 + ((~(((v2454 ^ -1) | (-(v2454 ^ -1))) >> 31)) & 2)) - (v2455 + ((~(((v2456 ^ -1) | (-(v2456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2476[v2626] = v2473;
    int * v2478 = v2327->cache_tags;
    int v2629 = (int)((unsigned int)((int)((unsigned int)(v2333 + 68) >> 2)) >> 1);
    v2478[v2605] = v2629;
    int * v2480 = v2327->cache_dirty;
    v2480[v2605] = 0;
    int * v2482 = v2327->cache_age;
    v2482[v2605] = 1;
    int * v2484 = v2327->cache_age;
    int v2485 = v2484[v2605];
    int v2486 = v2484[v2509];
    int v2635 = v2486 + ((int)((unsigned int)(v2486 - v2485) >> 31));
    v2484[v2509] = v2635;
    int * v2488 = v2327->cache_age;
    int v2489 = v2488[v2510];
    int v2637 = v2489 + ((int)((unsigned int)(v2489 - v2485) >> 31));
    v2488[v2510] = v2637;
    int * v2491 = v2327->cache_age;
    v2491[v2605] = 0;
    v2494 = v2605;
  }
  int * v2495 = v2327->cache_vals;
  int v2640 = (v2494 * 2) + (((int)((unsigned int)(v2333 + 68) >> 2)) & 1);
  v2495[v2640] = v2335;
  int * v2497 = v2327->cache_dirty;
  v2497[v2494] = 1;
  struct StateT * v2499 = slot_32(v2327);
  return v2499;
}

struct StateT * slot_24(struct StateT * v1022) {
  int v1023 = v1022->timer;
  int v1135 = v1023 + 1;
  v1022->timer = v1135;
  int * v1025 = v1022->reg_ready;
  int v1026 = v1025[10];
  int * v1027 = v1022->regs;
  int v1028 = v1027[10];
  int * v1029 = v1022->cache_tags;
  int v1140 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2;
  int v1030 = v1029[v1140];
  int v1141 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1031 = v1029[v1141];
  int v1142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
  int v1032 = v1029[v1142];
  int v1143 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1033 = v1029[v1143];
  int * v1034 = v1022->cache_vals;
  bool v1144 = !(((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
  int v1127;
  if (v1144) {
    int * v1035 = v1022->cache_age;
    int v1146 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
    int v1036 = v1035[v1146];
    int v1037 = v1035[v1140];
    int v1147 = v1037 + ((int)((unsigned int)(v1037 - v1036) >> 31));
    v1035[v1140] = v1147;
    int * v1039 = v1022->cache_age;
    int v1040 = v1039[v1141];
    int v1149 = v1040 + ((int)((unsigned int)(v1040 - v1036) >> 31));
    v1039[v1141] = v1149;
    int * v1042 = v1022->cache_age;
    v1042[v1146] = 0;
    v1127 = v1146;
  } else {
    int * v1045 = v1022->cache_age;
    int v1153 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2;
    int v1046 = v1045[v1153];
    int * v1047 = v1022->cache_tags;
    int v1048 = v1047[v1153];
    int v1049 = v1045[v1141];
    int v1050 = v1047[v1141];
    bool v1155 = !(((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) == 0);
    int v1104;
    if (v1155) {
      int * v1051 = v1022->cache_age;
      int v1157 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) & 1);
      int v1052 = v1051[v1157];
      int v1053 = v1051[v1142];
      int v1158 = v1053 + ((int)((unsigned int)(v1053 - v1052) >> 31));
      v1051[v1142] = v1158;
      int * v1055 = v1022->cache_age;
      int v1056 = v1055[v1143];
      int v1160 = v1056 + ((int)((unsigned int)(v1056 - v1052) >> 31));
      v1055[v1143] = v1160;
      int * v1058 = v1022->cache_age;
      v1058[v1157] = 0;
      v1104 = v1157;
    } else {
      int * v1061 = v1022->cache_age;
      int v1164 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2);
      int v1062 = v1061[v1164];
      int * v1063 = v1022->cache_tags;
      int v1064 = v1063[v1164];
      int v1065 = v1061[v1143];
      int v1066 = v1063[v1143];
      int * v1067 = v1022->cache_dirty;
      int v1167 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1068 = v1067[v1167];
      bool v1168 = !(v1068 == 0);
      if (v1168) {
        int * v1069 = v1022->cache_tags;
        int v1070 = v1069[v1167];
        int * v1071 = v1022->cache_vals;
        int v1171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1072 = v1071[v1171];
        int v1172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1073 = v1071[v1172];
        int * v1074 = v1022->mem;
        int v1174 = v1070 * 2;
        v1074[v1174] = v1072;
        int * v1076 = v1022->mem;
        int v1177 = (v1070 * 2) + 1;
        v1076[v1177] = v1073;
        ;
      } else {
        ;
      }
      int * v1081 = v1022->mem;
      int v1182 = ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2;
      int v1082 = v1081[v1182];
      int v1183 = (((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) * 2) + 1;
      int v1083 = v1081[v1183];
      int * v1084 = v1022->cache_vals;
      int v1185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1084[v1185] = v1082;
      int * v1086 = v1022->cache_vals;
      int v1188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 3) * 2)) + ((((v1062 + ((~(((v1064 ^ -1) | (-(v1064 ^ -1))) >> 31)) & 2)) - (v1065 + ((~(((v1066 ^ -1) | (-(v1066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1086[v1188] = v1083;
      int * v1088 = v1022->cache_tags;
      int v1191 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
      v1088[v1167] = v1191;
      int * v1090 = v1022->cache_dirty;
      v1090[v1167] = 0;
      int * v1092 = v1022->cache_age;
      v1092[v1167] = 1;
      int * v1094 = v1022->cache_age;
      int v1095 = v1094[v1167];
      int v1096 = v1094[v1142];
      int v1197 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
      v1094[v1142] = v1197;
      int * v1098 = v1022->cache_age;
      int v1099 = v1098[v1143];
      int v1199 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
      v1098[v1143] = v1199;
      int * v1101 = v1022->cache_age;
      v1101[v1167] = 0;
      v1104 = v1167;
    }
    int * v1105 = v1022->cache_vals;
    int v1202 = v1104 * 2;
    int v1106 = v1105[v1202];
    int v1203 = (v1104 * 2) + 1;
    int v1107 = v1105[v1203];
    int v1204 = (((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1105[v1204] = v1106;
    int * v1109 = v1022->cache_vals;
    int v1207 = ((((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1109[v1207] = v1107;
    int * v1111 = v1022->cache_tags;
    int v1210 = ((((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1)) & 1) * 2) + ((((v1046 + ((~(((v1048 ^ -1) | (-(v1048 ^ -1))) >> 31)) & 2)) - (v1049 + ((~(((v1050 ^ -1) | (-(v1050 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1211 = (int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1);
    v1111[v1210] = v1211;
    int * v1113 = v1022->cache_dirty;
    v1113[v1210] = 0;
    int * v1115 = v1022->cache_age;
    v1115[v1210] = 1;
    int * v1117 = v1022->cache_age;
    int v1118 = v1117[v1210];
    int v1119 = v1117[v1140];
    int v1217 = v1119 + ((int)((unsigned int)(v1119 - v1118) >> 31));
    v1117[v1140] = v1217;
    int * v1121 = v1022->cache_age;
    int v1122 = v1121[v1141];
    int v1219 = v1122 + ((int)((unsigned int)(v1122 - v1118) >> 31));
    v1121[v1141] = v1219;
    int * v1124 = v1022->cache_age;
    v1124[v1210] = 0;
    v1127 = v1210;
  }
  int v1222 = (v1127 * 2) + (((int)((unsigned int)v1028 >> 2)) & 1);
  int v1128 = v1034[v1222];
  int * v1129 = v1022->reg_ready;
  int v1224 = ((v1026 + ((v1023 - v1026) & (~((v1023 - v1026) >> 31)))) + 1) + ((100 ^ (((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1030 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1031 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1032 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31)) | (~(((v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))) | (-(v1033 ^ ((int)((unsigned int)((int)((unsigned int)v1028 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1129[10] = v1224;
  int * v1131 = v1022->regs;
  v1131[10] = v1128;
  struct StateT * v1133 = slot_26(v1022);
  return v1133;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_14(struct StateT * v658) {
  int v659 = v658->timer;
  int v667 = v659 + 1;
  v658->timer = v667;
  int * v661 = v658->reg_ready;
  v661[12] = v667;
  int * v663 = v658->regs;
  v663[12] = 0;
  struct StateT * v665 = slot_29(v658);
  return v665;
}

struct StateT * slot_28(struct StateT * v1474) {
  int v1475 = v1474->timer;
  int v1488 = v1475 + 1;
  v1474->timer = v1488;
  int * v1477 = v1474->reg_ready;
  int v1478 = v1477[11];
  int * v1479 = v1474->regs;
  int v1480 = v1479[11];
  int v1481 = v1477[10];
  int v1482 = v1479[10];
  int v1493 = (v1481 + (((v1478 + ((v1475 - v1478) & (~((v1475 - v1478) >> 31)))) - v1481) & (~(((v1478 + ((v1475 - v1478) & (~((v1475 - v1478) >> 31)))) - v1481) >> 31)))) + 1;
  v1477[10] = v1493;
  int * v1484 = v1474->regs;
  int v1495 = v1480 & v1482;
  v1484[10] = v1495;
  struct StateT * v1486 = slot_38(v1474);
  return v1486;
}

struct StateT * slot_32(struct StateT * v1859) {
  int v1860 = v1859->timer;
  int v1863 = v1860 + 1;
  v1859->timer = v1863;
  return v1859;
}

struct StateT * slot_33(struct StateT * v1864) {
  int v1865 = v1864->timer;
  int v1878 = v1865 + 1;
  v1864->timer = v1878;
  int * v1867 = v1864->reg_ready;
  int v1868 = v1867[11];
  int * v1869 = v1864->regs;
  int v1870 = v1869[11];
  int v1871 = v1867[10];
  int v1872 = v1869[10];
  int v1883 = (v1871 + (((v1868 + ((v1865 - v1868) & (~((v1865 - v1868) >> 31)))) - v1871) & (~(((v1868 + ((v1865 - v1868) & (~((v1865 - v1868) >> 31)))) - v1871) >> 31)))) + 1;
  v1867[10] = v1883;
  int * v1874 = v1864->regs;
  int v1885 = v1870 + v1872;
  v1874[10] = v1885;
  struct StateT * v1876 = slot_24(v1864);
  return v1876;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2651 = v1->timer;
  int * v2652 = v1->reg_ready;
  int v2653 = v2652[0];
  int v2784 = v2653 + ((v2651 - v2653) & (~((v2651 - v2653) >> 31)));
  v1->timer = v2784;
  int v2655 = v1->timer;
  int * v2656 = v1->reg_ready;
  int v2657 = v2656[1];
  int v2787 = v2657 + ((v2655 - v2657) & (~((v2655 - v2657) >> 31)));
  v1->timer = v2787;
  int v2659 = v1->timer;
  int * v2660 = v1->reg_ready;
  int v2661 = v2660[2];
  int v2790 = v2661 + ((v2659 - v2661) & (~((v2659 - v2661) >> 31)));
  v1->timer = v2790;
  int v2663 = v1->timer;
  int * v2664 = v1->reg_ready;
  int v2665 = v2664[3];
  int v2793 = v2665 + ((v2663 - v2665) & (~((v2663 - v2665) >> 31)));
  v1->timer = v2793;
  int v2667 = v1->timer;
  int * v2668 = v1->reg_ready;
  int v2669 = v2668[4];
  int v2796 = v2669 + ((v2667 - v2669) & (~((v2667 - v2669) >> 31)));
  v1->timer = v2796;
  int v2671 = v1->timer;
  int * v2672 = v1->reg_ready;
  int v2673 = v2672[5];
  int v2799 = v2673 + ((v2671 - v2673) & (~((v2671 - v2673) >> 31)));
  v1->timer = v2799;
  int v2675 = v1->timer;
  int * v2676 = v1->reg_ready;
  int v2677 = v2676[6];
  int v2802 = v2677 + ((v2675 - v2677) & (~((v2675 - v2677) >> 31)));
  v1->timer = v2802;
  int v2679 = v1->timer;
  int * v2680 = v1->reg_ready;
  int v2681 = v2680[7];
  int v2805 = v2681 + ((v2679 - v2681) & (~((v2679 - v2681) >> 31)));
  v1->timer = v2805;
  int v2683 = v1->timer;
  int * v2684 = v1->reg_ready;
  int v2685 = v2684[8];
  int v2808 = v2685 + ((v2683 - v2685) & (~((v2683 - v2685) >> 31)));
  v1->timer = v2808;
  int v2687 = v1->timer;
  int * v2688 = v1->reg_ready;
  int v2689 = v2688[9];
  int v2811 = v2689 + ((v2687 - v2689) & (~((v2687 - v2689) >> 31)));
  v1->timer = v2811;
  int v2691 = v1->timer;
  int * v2692 = v1->reg_ready;
  int v2693 = v2692[10];
  int v2814 = v2693 + ((v2691 - v2693) & (~((v2691 - v2693) >> 31)));
  v1->timer = v2814;
  int v2695 = v1->timer;
  int * v2696 = v1->reg_ready;
  int v2697 = v2696[11];
  int v2817 = v2697 + ((v2695 - v2697) & (~((v2695 - v2697) >> 31)));
  v1->timer = v2817;
  int v2699 = v1->timer;
  int * v2700 = v1->reg_ready;
  int v2701 = v2700[12];
  int v2820 = v2701 + ((v2699 - v2701) & (~((v2699 - v2701) >> 31)));
  v1->timer = v2820;
  int v2703 = v1->timer;
  int * v2704 = v1->reg_ready;
  int v2705 = v2704[13];
  int v2823 = v2705 + ((v2703 - v2705) & (~((v2703 - v2705) >> 31)));
  v1->timer = v2823;
  int v2707 = v1->timer;
  int * v2708 = v1->reg_ready;
  int v2709 = v2708[14];
  int v2826 = v2709 + ((v2707 - v2709) & (~((v2707 - v2709) >> 31)));
  v1->timer = v2826;
  int v2711 = v1->timer;
  int * v2712 = v1->reg_ready;
  int v2713 = v2712[15];
  int v2829 = v2713 + ((v2711 - v2713) & (~((v2711 - v2713) >> 31)));
  v1->timer = v2829;
  int v2715 = v1->timer;
  int * v2716 = v1->reg_ready;
  int v2717 = v2716[16];
  int v2832 = v2717 + ((v2715 - v2717) & (~((v2715 - v2717) >> 31)));
  v1->timer = v2832;
  int v2719 = v1->timer;
  int * v2720 = v1->reg_ready;
  int v2721 = v2720[17];
  int v2835 = v2721 + ((v2719 - v2721) & (~((v2719 - v2721) >> 31)));
  v1->timer = v2835;
  int v2723 = v1->timer;
  int * v2724 = v1->reg_ready;
  int v2725 = v2724[18];
  int v2838 = v2725 + ((v2723 - v2725) & (~((v2723 - v2725) >> 31)));
  v1->timer = v2838;
  int v2727 = v1->timer;
  int * v2728 = v1->reg_ready;
  int v2729 = v2728[19];
  int v2841 = v2729 + ((v2727 - v2729) & (~((v2727 - v2729) >> 31)));
  v1->timer = v2841;
  int v2731 = v1->timer;
  int * v2732 = v1->reg_ready;
  int v2733 = v2732[20];
  int v2844 = v2733 + ((v2731 - v2733) & (~((v2731 - v2733) >> 31)));
  v1->timer = v2844;
  int v2735 = v1->timer;
  int * v2736 = v1->reg_ready;
  int v2737 = v2736[21];
  int v2847 = v2737 + ((v2735 - v2737) & (~((v2735 - v2737) >> 31)));
  v1->timer = v2847;
  int v2739 = v1->timer;
  int * v2740 = v1->reg_ready;
  int v2741 = v2740[22];
  int v2850 = v2741 + ((v2739 - v2741) & (~((v2739 - v2741) >> 31)));
  v1->timer = v2850;
  int v2743 = v1->timer;
  int * v2744 = v1->reg_ready;
  int v2745 = v2744[23];
  int v2853 = v2745 + ((v2743 - v2745) & (~((v2743 - v2745) >> 31)));
  v1->timer = v2853;
  int v2747 = v1->timer;
  int * v2748 = v1->reg_ready;
  int v2749 = v2748[24];
  int v2856 = v2749 + ((v2747 - v2749) & (~((v2747 - v2749) >> 31)));
  v1->timer = v2856;
  int v2751 = v1->timer;
  int * v2752 = v1->reg_ready;
  int v2753 = v2752[25];
  int v2859 = v2753 + ((v2751 - v2753) & (~((v2751 - v2753) >> 31)));
  v1->timer = v2859;
  int v2755 = v1->timer;
  int * v2756 = v1->reg_ready;
  int v2757 = v2756[26];
  int v2862 = v2757 + ((v2755 - v2757) & (~((v2755 - v2757) >> 31)));
  v1->timer = v2862;
  int v2759 = v1->timer;
  int * v2760 = v1->reg_ready;
  int v2761 = v2760[27];
  int v2865 = v2761 + ((v2759 - v2761) & (~((v2759 - v2761) >> 31)));
  v1->timer = v2865;
  int v2763 = v1->timer;
  int * v2764 = v1->reg_ready;
  int v2765 = v2764[28];
  int v2868 = v2765 + ((v2763 - v2765) & (~((v2763 - v2765) >> 31)));
  v1->timer = v2868;
  int v2767 = v1->timer;
  int * v2768 = v1->reg_ready;
  int v2769 = v2768[29];
  int v2871 = v2769 + ((v2767 - v2769) & (~((v2767 - v2769) >> 31)));
  v1->timer = v2871;
  int v2771 = v1->timer;
  int * v2772 = v1->reg_ready;
  int v2773 = v2772[30];
  int v2874 = v2773 + ((v2771 - v2773) & (~((v2771 - v2773) >> 31)));
  v1->timer = v2874;
  int v2775 = v1->timer;
  int * v2776 = v1->reg_ready;
  int v2777 = v2776[31];
  int v2877 = v2777 + ((v2775 - v2777) & (~((v2775 - v2777) >> 31)));
  v1->timer = v2877;
  return v1;
}

struct StateT * slot_4(struct StateT * v273) {
  int v274 = v273->timer;
  int v282 = v274 + 1;
  v273->timer = v282;
  int * v276 = v273->reg_ready;
  v276[10] = v282;
  int * v278 = v273->regs;
  v278[10] = 0;
  struct StateT * v280 = slot_6(v273);
  return v280;
}

struct StateT * slot_15(struct StateT * v674) {
  int * v675 = v674->saved_regs;
  int v676 = v675[10];
  int v677 = v675[11];
  bool v703 = (v676 ^ -2147483648) >= (v677 ^ -2147483648);
  struct StateT * v698;
  if (v703) {
    int v678 = v674->timer;
    int v704 = v678 + 15;
    v674->timer = v704;
    int * v680 = v674->saved_regs;
    int v681 = v680[10];
    int * v682 = v674->regs;
    v682[10] = v681;
    int * v684 = v674->saved_regs;
    int v685 = v684[11];
    int * v686 = v674->regs;
    v686[11] = v685;
    int * v688 = v674->reg_ready;
    int v689 = v674->timer;
    v688[10] = v689;
    int * v691 = v674->reg_ready;
    int v692 = v674->timer;
    v691[11] = v692;
    struct StateT * v694 = slot_32(v674);
    v698 = v694;
  } else {
    struct StateT * v696 = slot_18(v674);
    v698 = v696;
  }
  return v698;
}

struct StateT * slot_18(struct StateT * v746) {
  int v747 = v746->timer;
  int v751 = v747 + 1;
  v746->timer = v751;
  struct StateT * v749 = slot_21(v746);
  return v749;
}

struct StateT * slot_9(struct StateT * v553) {
  int * v554 = v553->saved_regs;
  int * v555 = v553->regs;
  int v556 = v555[11];
  v554[11] = v556;
  int v558 = v553->timer;
  int v570 = v558 + 1;
  v553->timer = v570;
  int * v560 = v553->reg_ready;
  v560[11] = v570;
  int * v562 = v553->regs;
  v562[11] = 0;
  struct StateT * v564 = slot_11(v553);
  return v564;
}

struct StateT * slot_11(struct StateT * v592) {
  int v593 = v592->timer;
  int v604 = v593 + 1;
  v592->timer = v604;
  int * v595 = v592->reg_ready;
  int v596 = v595[11];
  int * v597 = v592->regs;
  int v598 = v597[11];
  int v608 = (v596 + ((v593 - v596) & (~((v593 - v596) >> 31)))) + 1;
  v595[11] = v608;
  int * v600 = v592->regs;
  int v610 = v598 + 72;
  v600[11] = v610;
  struct StateT * v602 = slot_13(v592);
  return v602;
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