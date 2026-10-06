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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_6(struct StateT * v306);
struct StateT * slot_5(struct StateT * v98);
struct StateT * slot_4(struct StateT * v73);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v327);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v532 = v1->timer;
  int * v533 = v1->reg_ready;
  int v534 = v533[0];
  int v665 = v534 + ((v532 - v534) & (~((v532 - v534) >> 31)));
  v1->timer = v665;
  int v536 = v1->timer;
  int * v537 = v1->reg_ready;
  int v538 = v537[1];
  int v668 = v538 + ((v536 - v538) & (~((v536 - v538) >> 31)));
  v1->timer = v668;
  int v540 = v1->timer;
  int * v541 = v1->reg_ready;
  int v542 = v541[2];
  int v671 = v542 + ((v540 - v542) & (~((v540 - v542) >> 31)));
  v1->timer = v671;
  int v544 = v1->timer;
  int * v545 = v1->reg_ready;
  int v546 = v545[3];
  int v674 = v546 + ((v544 - v546) & (~((v544 - v546) >> 31)));
  v1->timer = v674;
  int v548 = v1->timer;
  int * v549 = v1->reg_ready;
  int v550 = v549[4];
  int v677 = v550 + ((v548 - v550) & (~((v548 - v550) >> 31)));
  v1->timer = v677;
  int v552 = v1->timer;
  int * v553 = v1->reg_ready;
  int v554 = v553[5];
  int v680 = v554 + ((v552 - v554) & (~((v552 - v554) >> 31)));
  v1->timer = v680;
  int v556 = v1->timer;
  int * v557 = v1->reg_ready;
  int v558 = v557[6];
  int v683 = v558 + ((v556 - v558) & (~((v556 - v558) >> 31)));
  v1->timer = v683;
  int v560 = v1->timer;
  int * v561 = v1->reg_ready;
  int v562 = v561[7];
  int v686 = v562 + ((v560 - v562) & (~((v560 - v562) >> 31)));
  v1->timer = v686;
  int v564 = v1->timer;
  int * v565 = v1->reg_ready;
  int v566 = v565[8];
  int v689 = v566 + ((v564 - v566) & (~((v564 - v566) >> 31)));
  v1->timer = v689;
  int v568 = v1->timer;
  int * v569 = v1->reg_ready;
  int v570 = v569[9];
  int v692 = v570 + ((v568 - v570) & (~((v568 - v570) >> 31)));
  v1->timer = v692;
  int v572 = v1->timer;
  int * v573 = v1->reg_ready;
  int v574 = v573[10];
  int v695 = v574 + ((v572 - v574) & (~((v572 - v574) >> 31)));
  v1->timer = v695;
  int v576 = v1->timer;
  int * v577 = v1->reg_ready;
  int v578 = v577[11];
  int v698 = v578 + ((v576 - v578) & (~((v576 - v578) >> 31)));
  v1->timer = v698;
  int v580 = v1->timer;
  int * v581 = v1->reg_ready;
  int v582 = v581[12];
  int v701 = v582 + ((v580 - v582) & (~((v580 - v582) >> 31)));
  v1->timer = v701;
  int v584 = v1->timer;
  int * v585 = v1->reg_ready;
  int v586 = v585[13];
  int v704 = v586 + ((v584 - v586) & (~((v584 - v586) >> 31)));
  v1->timer = v704;
  int v588 = v1->timer;
  int * v589 = v1->reg_ready;
  int v590 = v589[14];
  int v707 = v590 + ((v588 - v590) & (~((v588 - v590) >> 31)));
  v1->timer = v707;
  int v592 = v1->timer;
  int * v593 = v1->reg_ready;
  int v594 = v593[15];
  int v710 = v594 + ((v592 - v594) & (~((v592 - v594) >> 31)));
  v1->timer = v710;
  int v596 = v1->timer;
  int * v597 = v1->reg_ready;
  int v598 = v597[16];
  int v713 = v598 + ((v596 - v598) & (~((v596 - v598) >> 31)));
  v1->timer = v713;
  int v600 = v1->timer;
  int * v601 = v1->reg_ready;
  int v602 = v601[17];
  int v716 = v602 + ((v600 - v602) & (~((v600 - v602) >> 31)));
  v1->timer = v716;
  int v604 = v1->timer;
  int * v605 = v1->reg_ready;
  int v606 = v605[18];
  int v719 = v606 + ((v604 - v606) & (~((v604 - v606) >> 31)));
  v1->timer = v719;
  int v608 = v1->timer;
  int * v609 = v1->reg_ready;
  int v610 = v609[19];
  int v722 = v610 + ((v608 - v610) & (~((v608 - v610) >> 31)));
  v1->timer = v722;
  int v612 = v1->timer;
  int * v613 = v1->reg_ready;
  int v614 = v613[20];
  int v725 = v614 + ((v612 - v614) & (~((v612 - v614) >> 31)));
  v1->timer = v725;
  int v616 = v1->timer;
  int * v617 = v1->reg_ready;
  int v618 = v617[21];
  int v728 = v618 + ((v616 - v618) & (~((v616 - v618) >> 31)));
  v1->timer = v728;
  int v620 = v1->timer;
  int * v621 = v1->reg_ready;
  int v622 = v621[22];
  int v731 = v622 + ((v620 - v622) & (~((v620 - v622) >> 31)));
  v1->timer = v731;
  int v624 = v1->timer;
  int * v625 = v1->reg_ready;
  int v626 = v625[23];
  int v734 = v626 + ((v624 - v626) & (~((v624 - v626) >> 31)));
  v1->timer = v734;
  int v628 = v1->timer;
  int * v629 = v1->reg_ready;
  int v630 = v629[24];
  int v737 = v630 + ((v628 - v630) & (~((v628 - v630) >> 31)));
  v1->timer = v737;
  int v632 = v1->timer;
  int * v633 = v1->reg_ready;
  int v634 = v633[25];
  int v740 = v634 + ((v632 - v634) & (~((v632 - v634) >> 31)));
  v1->timer = v740;
  int v636 = v1->timer;
  int * v637 = v1->reg_ready;
  int v638 = v637[26];
  int v743 = v638 + ((v636 - v638) & (~((v636 - v638) >> 31)));
  v1->timer = v743;
  int v640 = v1->timer;
  int * v641 = v1->reg_ready;
  int v642 = v641[27];
  int v746 = v642 + ((v640 - v642) & (~((v640 - v642) >> 31)));
  v1->timer = v746;
  int v644 = v1->timer;
  int * v645 = v1->reg_ready;
  int v646 = v645[28];
  int v749 = v646 + ((v644 - v646) & (~((v644 - v646) >> 31)));
  v1->timer = v749;
  int v648 = v1->timer;
  int * v649 = v1->reg_ready;
  int v650 = v649[29];
  int v752 = v650 + ((v648 - v650) & (~((v648 - v650) >> 31)));
  v1->timer = v752;
  int v652 = v1->timer;
  int * v653 = v1->reg_ready;
  int v654 = v653[30];
  int v755 = v654 + ((v652 - v654) & (~((v652 - v654) >> 31)));
  v1->timer = v755;
  int v656 = v1->timer;
  int * v657 = v1->reg_ready;
  int v658 = v657[31];
  int v758 = v658 + ((v656 - v658) & (~((v656 - v658) >> 31)));
  v1->timer = v758;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[10] = v27;
  int * v23 = v18->regs;
  v23[10] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_6(struct StateT * v306) {
  int v307 = v306->timer;
  int v318 = v307 + 1;
  v306->timer = v318;
  int * v309 = v306->reg_ready;
  int v310 = v309[11];
  int * v311 = v306->regs;
  int v312 = v311[11];
  int v322 = (v310 + ((v307 - v310) & (~((v307 - v310) >> 31)))) + 1;
  v309[11] = v322;
  int * v314 = v306->regs;
  int v324 = v312 << 2;
  v314[11] = v324;
  struct StateT * v316 = slot_7(v306);
  return v316;
}

struct StateT * slot_5(struct StateT * v98) {
  int v99 = v98->timer;
  int v211 = v99 + 1;
  v98->timer = v211;
  int * v101 = v98->reg_ready;
  int v102 = v101[5];
  int * v103 = v98->regs;
  int v104 = v103[5];
  int * v105 = v98->cache_tags;
  int v216 = (((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2;
  int v106 = v105[v216];
  int v217 = ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + 1;
  int v107 = v105[v217];
  int v218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2);
  int v108 = v105[v218];
  int v219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v109 = v105[v219];
  int * v110 = v98->cache_vals;
  bool v220 = !(((~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) == 0);
  int v203;
  if (v220) {
    int * v111 = v98->cache_age;
    int v222 = ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((~(((v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) & 1);
    int v112 = v111[v222];
    int v113 = v111[v216];
    int v223 = v113 + ((int)((unsigned int)(v113 - v112) >> 31));
    v111[v216] = v223;
    int * v115 = v98->cache_age;
    int v116 = v115[v217];
    int v225 = v116 + ((int)((unsigned int)(v116 - v112) >> 31));
    v115[v217] = v225;
    int * v118 = v98->cache_age;
    v118[v222] = 0;
    v203 = v222;
  } else {
    int * v121 = v98->cache_age;
    int v229 = (((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2;
    int v122 = v121[v229];
    int * v123 = v98->cache_tags;
    int v124 = v123[v229];
    int v125 = v121[v217];
    int v126 = v123[v217];
    bool v231 = !(((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) == 0);
    int v180;
    if (v231) {
      int * v127 = v98->cache_age;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) & 1);
      int v128 = v127[v233];
      int v129 = v127[v218];
      int v234 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
      v127[v218] = v234;
      int * v131 = v98->cache_age;
      int v132 = v131[v219];
      int v236 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
      v131[v219] = v236;
      int * v134 = v98->cache_age;
      v134[v233] = 0;
      v180 = v233;
    } else {
      int * v137 = v98->cache_age;
      int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2);
      int v138 = v137[v240];
      int * v139 = v98->cache_tags;
      int v140 = v139[v240];
      int v141 = v137[v219];
      int v142 = v139[v219];
      int * v143 = v98->cache_dirty;
      int v243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v144 = v143[v243];
      bool v244 = !(v144 == 0);
      if (v244) {
        int * v145 = v98->cache_tags;
        int v146 = v145[v243];
        int * v147 = v98->cache_vals;
        int v247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v148 = v147[v247];
        int v248 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v149 = v147[v248];
        int * v150 = v98->mem;
        int v250 = v146 * 2;
        v150[v250] = v148;
        int * v152 = v98->mem;
        int v253 = (v146 * 2) + 1;
        v152[v253] = v149;
        ;
      } else {
        ;
      }
      int * v157 = v98->mem;
      int v258 = ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) * 2;
      int v158 = v157[v258];
      int v259 = (((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) * 2) + 1;
      int v159 = v157[v259];
      int * v160 = v98->cache_vals;
      int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v160[v261] = v158;
      int * v162 = v98->cache_vals;
      int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v162[v264] = v159;
      int * v164 = v98->cache_tags;
      int v267 = (int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1);
      v164[v243] = v267;
      int * v166 = v98->cache_dirty;
      v166[v243] = 0;
      int * v168 = v98->cache_age;
      v168[v243] = 1;
      int * v170 = v98->cache_age;
      int v171 = v170[v243];
      int v172 = v170[v218];
      int v273 = v172 + ((int)((unsigned int)(v172 - v171) >> 31));
      v170[v218] = v273;
      int * v174 = v98->cache_age;
      int v175 = v174[v219];
      int v275 = v175 + ((int)((unsigned int)(v175 - v171) >> 31));
      v174[v219] = v275;
      int * v177 = v98->cache_age;
      v177[v243] = 0;
      v180 = v243;
    }
    int * v181 = v98->cache_vals;
    int v278 = v180 * 2;
    int v182 = v181[v278];
    int v279 = (v180 * 2) + 1;
    int v183 = v181[v279];
    int v280 = (((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v181[v280] = v182;
    int * v185 = v98->cache_vals;
    int v283 = ((((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v185[v283] = v183;
    int * v187 = v98->cache_tags;
    int v286 = ((((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1)) & 1) * 2) + ((((v122 + ((~(((v124 ^ -1) | (-(v124 ^ -1))) >> 31)) & 2)) - (v125 + ((~(((v126 ^ -1) | (-(v126 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v287 = (int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1);
    v187[v286] = v287;
    int * v189 = v98->cache_dirty;
    v189[v286] = 0;
    int * v191 = v98->cache_age;
    v191[v286] = 1;
    int * v193 = v98->cache_age;
    int v194 = v193[v286];
    int v195 = v193[v216];
    int v293 = v195 + ((int)((unsigned int)(v195 - v194) >> 31));
    v193[v216] = v293;
    int * v197 = v98->cache_age;
    int v198 = v197[v217];
    int v295 = v198 + ((int)((unsigned int)(v198 - v194) >> 31));
    v197[v217] = v295;
    int * v200 = v98->cache_age;
    v200[v286] = 0;
    v203 = v286;
  }
  int v298 = (v203 * 2) + (((int)((unsigned int)v104 >> 2)) & 1);
  int v204 = v110[v298];
  int * v205 = v98->reg_ready;
  int v301 = ((v102 + ((v99 - v102) & (~((v99 - v102) >> 31)))) + 1) + ((100 ^ (((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v106 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v107 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v108 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31)) | (~(((v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))) | (-(v109 ^ ((int)((unsigned int)((int)((unsigned int)v104 >> 2)) >> 1))))) >> 31))) & 104)))));
  v205[11] = v301;
  int * v207 = v98->regs;
  v207[11] = v204;
  struct StateT * v209 = slot_6(v98);
  return v209;
}

struct StateT * slot_4(struct StateT * v73) {
  int v74 = v73->timer;
  int v87 = v74 + 1;
  v73->timer = v87;
  int * v76 = v73->reg_ready;
  int v77 = v76[13];
  int * v78 = v73->regs;
  int v79 = v78[13];
  int v80 = v76[10];
  int v81 = v78[10];
  int v93 = (v80 + (((v77 + ((v74 - v77) & (~((v74 - v77) >> 31)))) - v80) & (~(((v77 + ((v74 - v77) & (~((v74 - v77) >> 31)))) - v80) >> 31)))) + 1;
  v76[5] = v93;
  int * v83 = v73->regs;
  int v95 = v79 + v81;
  v83[5] = v95;
  struct StateT * v85 = slot_5(v73);
  return v85;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[15] = v43;
  int * v39 = v34->regs;
  v39[15] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v327) {
  int v328 = v327->timer;
  int v439 = v328 + 1;
  v327->timer = v439;
  int * v330 = v327->reg_ready;
  int v331 = v330[11];
  int * v332 = v327->regs;
  int v333 = v332[11];
  int * v334 = v327->cache_tags;
  int v444 = (((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2;
  int v335 = v334[v444];
  int v445 = ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2) + 1;
  int v336 = v334[v445];
  int v446 = 4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2);
  int v337 = v334[v446];
  int v447 = (4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v338 = v334[v447];
  int * v339 = v327->cache_vals;
  bool v448 = !(((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31))) == 0);
  int v432;
  if (v448) {
    int * v340 = v327->cache_age;
    int v450 = ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2) + ((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) & 1);
    int v341 = v340[v450];
    int v342 = v340[v444];
    int v451 = v342 + ((int)((unsigned int)(v342 - v341) >> 31));
    v340[v444] = v451;
    int * v344 = v327->cache_age;
    int v345 = v344[v445];
    int v453 = v345 + ((int)((unsigned int)(v345 - v341) >> 31));
    v344[v445] = v453;
    int * v347 = v327->cache_age;
    v347[v450] = 0;
    v432 = v450;
  } else {
    int * v350 = v327->cache_age;
    int v457 = (((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2;
    int v351 = v350[v457];
    int * v352 = v327->cache_tags;
    int v353 = v352[v457];
    int v354 = v350[v445];
    int v355 = v352[v445];
    bool v459 = !(((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31))) == 0);
    int v409;
    if (v459) {
      int * v356 = v327->cache_age;
      int v461 = (4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + ((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) & 1);
      int v357 = v356[v461];
      int v358 = v356[v446];
      int v462 = v358 + ((int)((unsigned int)(v358 - v357) >> 31));
      v356[v446] = v462;
      int * v360 = v327->cache_age;
      int v361 = v360[v447];
      int v464 = v361 + ((int)((unsigned int)(v361 - v357) >> 31));
      v360[v447] = v464;
      int * v363 = v327->cache_age;
      v363[v461] = 0;
      v409 = v461;
    } else {
      int * v366 = v327->cache_age;
      int v468 = 4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2);
      int v367 = v366[v468];
      int * v368 = v327->cache_tags;
      int v369 = v368[v468];
      int v370 = v366[v447];
      int v371 = v368[v447];
      int * v372 = v327->cache_dirty;
      int v471 = (4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v373 = v372[v471];
      bool v472 = !(v373 == 0);
      if (v472) {
        int * v374 = v327->cache_tags;
        int v375 = v374[v471];
        int * v376 = v327->cache_vals;
        int v475 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v377 = v376[v475];
        int v476 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v378 = v376[v476];
        int * v379 = v327->mem;
        int v478 = v375 * 2;
        v379[v478] = v377;
        int * v381 = v327->mem;
        int v481 = (v375 * 2) + 1;
        v381[v481] = v378;
        ;
      } else {
        ;
      }
      int * v386 = v327->mem;
      int v486 = ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) * 2;
      int v387 = v386[v486];
      int v487 = (((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) * 2) + 1;
      int v388 = v386[v487];
      int * v389 = v327->cache_vals;
      int v489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v389[v489] = v387;
      int * v391 = v327->cache_vals;
      int v492 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v391[v492] = v388;
      int * v393 = v327->cache_tags;
      int v495 = (int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1);
      v393[v471] = v495;
      int * v395 = v327->cache_dirty;
      v395[v471] = 0;
      int * v397 = v327->cache_age;
      v397[v471] = 1;
      int * v399 = v327->cache_age;
      int v400 = v399[v471];
      int v401 = v399[v446];
      int v501 = v401 + ((int)((unsigned int)(v401 - v400) >> 31));
      v399[v446] = v501;
      int * v403 = v327->cache_age;
      int v404 = v403[v447];
      int v503 = v404 + ((int)((unsigned int)(v404 - v400) >> 31));
      v403[v447] = v503;
      int * v406 = v327->cache_age;
      v406[v471] = 0;
      v409 = v471;
    }
    int * v410 = v327->cache_vals;
    int v506 = v409 * 2;
    int v411 = v410[v506];
    int v507 = (v409 * 2) + 1;
    int v412 = v410[v507];
    int v508 = (((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v410[v508] = v411;
    int * v414 = v327->cache_vals;
    int v511 = ((((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v414[v511] = v412;
    int * v416 = v327->cache_tags;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v515 = (int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1);
    v416[v514] = v515;
    int * v418 = v327->cache_dirty;
    v418[v514] = 0;
    int * v420 = v327->cache_age;
    v420[v514] = 1;
    int * v422 = v327->cache_age;
    int v423 = v422[v514];
    int v424 = v422[v444];
    int v521 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
    v422[v444] = v521;
    int * v426 = v327->cache_age;
    int v427 = v426[v445];
    int v523 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
    v426[v445] = v523;
    int * v429 = v327->cache_age;
    v429[v514] = 0;
    v432 = v514;
  }
  int v526 = (v432 * 2) + (((int)((unsigned int)v333 >> 2)) & 1);
  int v433 = v339[v526];
  int * v434 = v327->reg_ready;
  int v529 = ((v331 + ((v328 - v331) & (~((v328 - v331) >> 31)))) + 1) + ((100 ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v333 >> 2)) >> 1))))) >> 31))) & 104)))));
  v434[12] = v529;
  int * v436 = v327->regs;
  v436[12] = v433;
  return v327;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v64 = v51 + 1;
  v50->timer = v64;
  int * v53 = v50->reg_ready;
  int * v55 = v50->regs;
  int v56 = v55[10];
  int v58 = v55[15];
  bool v69 = v56 >= v58;
  struct StateT * v62;
  if (v69) {
    v62 = v50;
  } else {
    struct StateT * v60 = slot_4(v50);
    v62 = v60;
  }
  return v62;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[13] = v11;
  int * v7 = v2->regs;
  v7[13] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}