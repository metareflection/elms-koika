// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]

#define NUM_REGS 32
#define MEM_SIZE 30
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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
  int mem[30];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v410);
struct StateT * slot_6(struct StateT * v75);
struct StateT * slot_16(struct StateT * v518);
struct StateT * slot_23(struct StateT * v842);
struct StateT * slot_5(struct StateT * v67);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v103);
struct StateT * slot_21(struct StateT * v702);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_10(struct StateT * v355);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v562);
struct StateT * slot_13(struct StateT * v482);
struct StateT * slot_24(struct StateT * v869);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v502);
struct StateT * slot_17(struct StateT * v526);
struct StateT * slot_20(struct StateT * v674);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v215);
struct StateT * slot_4(struct StateT * v54);
struct StateT * slot_18(struct StateT * v534);
struct StateT * slot_9(struct StateT * v243);
struct StateT * slot_22(struct StateT * v814);
struct StateT * slot_11(struct StateT * v383);
struct StateT * slot_12(struct StateT * v410) {
  int * v411 = v410->regs;
  int v412 = v411[14];
  int * v413 = v410->regs;
  int v414 = v413[15];
  bool v451 = v412 >= v414;
  struct StateT * v445;
  if (v451) {
    int v415 = v410->timer;
    int v452 = v415 + 15;
    v410->timer = v452;
    int * v417 = v410->saved_regs;
    int v418 = v417[6];
    int * v419 = v410->regs;
    v419[6] = v418;
    int * v421 = v410->saved_regs;
    int v422 = v421[7];
    int * v423 = v410->regs;
    v423[7] = v422;
    int * v425 = v410->saved_regs;
    int v426 = v425[8];
    int * v427 = v410->regs;
    v427[8] = v426;
    int * v429 = v410->saved_regs;
    int v430 = v429[9];
    int * v431 = v410->regs;
    v431[9] = v430;
    int * v433 = v410->saved_regs;
    int v434 = v433[16];
    int * v435 = v410->regs;
    v435[16] = v434;
    int * v437 = v410->saved_regs;
    int v438 = v437[5];
    int * v439 = v410->regs;
    v439[5] = v438;
    struct StateT * v441 = slot_13(v410);
    v445 = v441;
  } else {
    struct StateT * v443 = slot_14(v410);
    v445 = v443;
  }
  return v445;
}

struct StateT * slot_6(struct StateT * v75) {
  int * v76 = v75->saved_regs;
  int * v77 = v75->regs;
  int v78 = v77[6];
  v76[6] = v78;
  int v80 = v75->timer;
  int v94 = v80 + 1;
  v75->timer = v94;
  int * v82 = v75->regs;
  int v83 = v82[12];
  int * v84 = v75->regs;
  int v85 = v84[14];
  int * v86 = v75->regs;
  int v100 = v83 + v85;
  v86[6] = v100;
  struct StateT * v88 = slot_7(v75);
  return v88;
}

struct StateT * slot_16(struct StateT * v518) {
  int v519 = v518->timer;
  int v523 = v519 + 1;
  v518->timer = v523;
  struct StateT * v521 = slot_17(v518);
  return v521;
}

struct StateT * slot_23(struct StateT * v842) {
  int * v843 = v842->saved_regs;
  int * v844 = v842->regs;
  int v845 = v844[5];
  v843[5] = v845;
  int v847 = v842->timer;
  int v861 = v847 + 1;
  v842->timer = v861;
  int * v849 = v842->regs;
  int v850 = v849[5];
  int * v851 = v842->regs;
  int v852 = v851[16];
  int * v853 = v842->regs;
  int v866 = v850 | v852;
  v853[5] = v866;
  struct StateT * v855 = slot_24(v842);
  return v855;
}

struct StateT * slot_5(struct StateT * v67) {
  int v68 = v67->timer;
  int v72 = v68 + 1;
  v67->timer = v72;
  struct StateT * v70 = slot_6(v67);
  return v70;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 0;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v103) {
  int * v104 = v103->saved_regs;
  int * v105 = v103->regs;
  int v106 = v105[7];
  v104[7] = v106;
  int v108 = v103->timer;
  int v170 = v108 + 1;
  v103->timer = v170;
  int * v110 = v103->regs;
  int v111 = v110[6];
  int * v112 = v103->cache_keys;
  int v113 = v112[0];
  bool v175 = v113 == ((int)((unsigned int)v111 >> 2));
  int v161;
  if (v175) {
    int * v114 = v103->cache_vals;
    int v115 = v114[0];
    v161 = v115;
  } else {
    int * v117 = v103->cache_keys;
    int v118 = v117[1];
    bool v180 = v118 == ((int)((unsigned int)v111 >> 2));
    int v159;
    if (v180) {
      int * v119 = v103->cache_vals;
      int v120 = v119[1];
      int * v121 = v103->cache_keys;
      int * v122 = v103->cache_keys;
      int v123 = v122[0];
      v121[1] = v123;
      int * v125 = v103->cache_vals;
      int * v126 = v103->cache_vals;
      int v127 = v126[0];
      v125[1] = v127;
      int * v129 = v103->cache_keys;
      int v189 = (int)((unsigned int)v111 >> 2);
      v129[0] = v189;
      int * v131 = v103->cache_vals;
      v131[0] = v120;
      int v133 = v103->timer;
      int v192 = v133 + 1;
      v103->timer = v192;
      v159 = v120;
    } else {
      int * v136 = v103->mem;
      int v194 = (int)((unsigned int)v111 >> 2);
      int v137 = v136[v194];
      int * v138 = v103->mem;
      int * v139 = v103->cache_keys;
      int v140 = v139[1];
      int * v141 = v103->cache_vals;
      int v142 = v141[1];
      v138[v140] = v142;
      int * v144 = v103->cache_keys;
      int * v145 = v103->cache_keys;
      int v146 = v145[0];
      v144[1] = v146;
      int * v148 = v103->cache_vals;
      int * v149 = v103->cache_vals;
      int v150 = v149[0];
      v148[1] = v150;
      int * v152 = v103->cache_keys;
      v152[0] = v194;
      int * v154 = v103->cache_vals;
      v154[0] = v137;
      int v156 = v103->timer;
      int v209 = v156 + 100;
      v103->timer = v209;
      v159 = v137;
    }
    v161 = v159;
  }
  int * v162 = v103->regs;
  v162[7] = v161;
  struct StateT * v164 = slot_8(v103);
  return v164;
}

struct StateT * slot_21(struct StateT * v702) {
  int * v703 = v702->saved_regs;
  int * v704 = v702->regs;
  int v705 = v704[9];
  v703[9] = v705;
  int v707 = v702->timer;
  int v769 = v707 + 1;
  v702->timer = v769;
  int * v709 = v702->regs;
  int v710 = v709[8];
  int * v711 = v702->cache_keys;
  int v712 = v711[0];
  bool v774 = v712 == ((int)((unsigned int)v710 >> 2));
  int v760;
  if (v774) {
    int * v713 = v702->cache_vals;
    int v714 = v713[0];
    v760 = v714;
  } else {
    int * v716 = v702->cache_keys;
    int v717 = v716[1];
    bool v779 = v717 == ((int)((unsigned int)v710 >> 2));
    int v758;
    if (v779) {
      int * v718 = v702->cache_vals;
      int v719 = v718[1];
      int * v720 = v702->cache_keys;
      int * v721 = v702->cache_keys;
      int v722 = v721[0];
      v720[1] = v722;
      int * v724 = v702->cache_vals;
      int * v725 = v702->cache_vals;
      int v726 = v725[0];
      v724[1] = v726;
      int * v728 = v702->cache_keys;
      int v788 = (int)((unsigned int)v710 >> 2);
      v728[0] = v788;
      int * v730 = v702->cache_vals;
      v730[0] = v719;
      int v732 = v702->timer;
      int v791 = v732 + 1;
      v702->timer = v791;
      v758 = v719;
    } else {
      int * v735 = v702->mem;
      int v793 = (int)((unsigned int)v710 >> 2);
      int v736 = v735[v793];
      int * v737 = v702->mem;
      int * v738 = v702->cache_keys;
      int v739 = v738[1];
      int * v740 = v702->cache_vals;
      int v741 = v740[1];
      v737[v739] = v741;
      int * v743 = v702->cache_keys;
      int * v744 = v702->cache_keys;
      int v745 = v744[0];
      v743[1] = v745;
      int * v747 = v702->cache_vals;
      int * v748 = v702->cache_vals;
      int v749 = v748[0];
      v747[1] = v749;
      int * v751 = v702->cache_keys;
      v751[0] = v793;
      int * v753 = v702->cache_vals;
      v753[0] = v736;
      int v755 = v702->timer;
      int v808 = v755 + 100;
      v702->timer = v808;
      v758 = v736;
    }
    v760 = v758;
  }
  int * v761 = v702->regs;
  v761[9] = v760;
  struct StateT * v763 = slot_22(v702);
  return v763;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 16;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * slot_10(struct StateT * v355) {
  int * v356 = v355->saved_regs;
  int * v357 = v355->regs;
  int v358 = v357[16];
  v356[16] = v358;
  int v360 = v355->timer;
  int v374 = v360 + 1;
  v355->timer = v374;
  int * v362 = v355->regs;
  int v363 = v362[7];
  int * v364 = v355->regs;
  int v365 = v364[9];
  int * v366 = v355->regs;
  int v380 = v363 ^ v365;
  v366[16] = v380;
  struct StateT * v368 = slot_11(v355);
  return v368;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_19(struct StateT * v562) {
  int * v563 = v562->saved_regs;
  int * v564 = v562->regs;
  int v565 = v564[7];
  v563[7] = v565;
  int v567 = v562->timer;
  int v629 = v567 + 1;
  v562->timer = v629;
  int * v569 = v562->regs;
  int v570 = v569[6];
  int * v571 = v562->cache_keys;
  int v572 = v571[0];
  bool v634 = v572 == ((int)((unsigned int)v570 >> 2));
  int v620;
  if (v634) {
    int * v573 = v562->cache_vals;
    int v574 = v573[0];
    v620 = v574;
  } else {
    int * v576 = v562->cache_keys;
    int v577 = v576[1];
    bool v639 = v577 == ((int)((unsigned int)v570 >> 2));
    int v618;
    if (v639) {
      int * v578 = v562->cache_vals;
      int v579 = v578[1];
      int * v580 = v562->cache_keys;
      int * v581 = v562->cache_keys;
      int v582 = v581[0];
      v580[1] = v582;
      int * v584 = v562->cache_vals;
      int * v585 = v562->cache_vals;
      int v586 = v585[0];
      v584[1] = v586;
      int * v588 = v562->cache_keys;
      int v648 = (int)((unsigned int)v570 >> 2);
      v588[0] = v648;
      int * v590 = v562->cache_vals;
      v590[0] = v579;
      int v592 = v562->timer;
      int v651 = v592 + 1;
      v562->timer = v651;
      v618 = v579;
    } else {
      int * v595 = v562->mem;
      int v653 = (int)((unsigned int)v570 >> 2);
      int v596 = v595[v653];
      int * v597 = v562->mem;
      int * v598 = v562->cache_keys;
      int v599 = v598[1];
      int * v600 = v562->cache_vals;
      int v601 = v600[1];
      v597[v599] = v601;
      int * v603 = v562->cache_keys;
      int * v604 = v562->cache_keys;
      int v605 = v604[0];
      v603[1] = v605;
      int * v607 = v562->cache_vals;
      int * v608 = v562->cache_vals;
      int v609 = v608[0];
      v607[1] = v609;
      int * v611 = v562->cache_keys;
      v611[0] = v653;
      int * v613 = v562->cache_vals;
      v613[0] = v596;
      int v615 = v562->timer;
      int v668 = v615 + 100;
      v562->timer = v668;
      v618 = v596;
    }
    v620 = v618;
  }
  int * v621 = v562->regs;
  v621[7] = v620;
  struct StateT * v623 = slot_20(v562);
  return v623;
}

struct StateT * slot_13(struct StateT * v482) {
  int v483 = v482->timer;
  int v493 = v483 + 1;
  v482->timer = v493;
  int * v485 = v482->regs;
  int v486 = v485[5];
  bool v496 = (v486 ^ -2147483648) < -2147483647;
  int v489;
  if (v496) {
    v489 = 1;
  } else {
    v489 = 0;
  }
  int * v490 = v482->regs;
  v490[11] = v489;
  return v482;
}

struct StateT * slot_24(struct StateT * v869) {
  int * v870 = v869->regs;
  int v871 = v870[14];
  int * v872 = v869->regs;
  int v873 = v872[15];
  bool v910 = v871 >= v873;
  struct StateT * v904;
  if (v910) {
    int v874 = v869->timer;
    int v911 = v874 + 15;
    v869->timer = v911;
    int * v876 = v869->saved_regs;
    int v877 = v876[6];
    int * v878 = v869->regs;
    v878[6] = v877;
    int * v880 = v869->saved_regs;
    int v881 = v880[7];
    int * v882 = v869->regs;
    v882[7] = v881;
    int * v884 = v869->saved_regs;
    int v885 = v884[8];
    int * v886 = v869->regs;
    v886[8] = v885;
    int * v888 = v869->saved_regs;
    int v889 = v888[9];
    int * v890 = v869->regs;
    v890[9] = v889;
    int * v892 = v869->saved_regs;
    int v893 = v892[16];
    int * v894 = v869->regs;
    v894[16] = v893;
    int * v896 = v869->saved_regs;
    int v897 = v896[5];
    int * v898 = v869->regs;
    v898[5] = v897;
    struct StateT * v900 = slot_13(v869);
    v904 = v900;
  } else {
    struct StateT * v902 = slot_14(v869);
    v904 = v902;
  }
  return v904;
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

struct StateT * slot_14(struct StateT * v502) {
  int v503 = v502->timer;
  int v511 = v503 + 1;
  v502->timer = v511;
  int * v505 = v502->regs;
  int v506 = v505[14];
  int * v507 = v502->regs;
  int v515 = v506 + 4;
  v507[14] = v515;
  struct StateT * v509 = slot_16(v502);
  return v509;
}

struct StateT * slot_17(struct StateT * v526) {
  int v527 = v526->timer;
  int v531 = v527 + 1;
  v526->timer = v531;
  struct StateT * v529 = slot_18(v526);
  return v529;
}

struct StateT * slot_20(struct StateT * v674) {
  int * v675 = v674->saved_regs;
  int * v676 = v674->regs;
  int v677 = v676[8];
  v675[8] = v677;
  int v679 = v674->timer;
  int v693 = v679 + 1;
  v674->timer = v693;
  int * v681 = v674->regs;
  int v682 = v681[13];
  int * v683 = v674->regs;
  int v684 = v683[14];
  int * v685 = v674->regs;
  int v699 = v682 + v684;
  v685[8] = v699;
  struct StateT * v687 = slot_21(v674);
  return v687;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v215) {
  int * v216 = v215->saved_regs;
  int * v217 = v215->regs;
  int v218 = v217[8];
  v216[8] = v218;
  int v220 = v215->timer;
  int v234 = v220 + 1;
  v215->timer = v234;
  int * v222 = v215->regs;
  int v223 = v222[13];
  int * v224 = v215->regs;
  int v225 = v224[14];
  int * v226 = v215->regs;
  int v240 = v223 + v225;
  v226[8] = v240;
  struct StateT * v228 = slot_9(v215);
  return v228;
}

struct StateT * slot_4(struct StateT * v54) {
  int v55 = v54->timer;
  int v61 = v55 + 1;
  v54->timer = v61;
  int * v57 = v54->regs;
  v57[5] = 0;
  struct StateT * v59 = slot_5(v54);
  return v59;
}

struct StateT * slot_18(struct StateT * v534) {
  int * v535 = v534->saved_regs;
  int * v536 = v534->regs;
  int v537 = v536[6];
  v535[6] = v537;
  int v539 = v534->timer;
  int v553 = v539 + 1;
  v534->timer = v553;
  int * v541 = v534->regs;
  int v542 = v541[12];
  int * v543 = v534->regs;
  int v544 = v543[14];
  int * v545 = v534->regs;
  int v559 = v542 + v544;
  v545[6] = v559;
  struct StateT * v547 = slot_19(v534);
  return v547;
}

struct StateT * slot_9(struct StateT * v243) {
  int * v244 = v243->saved_regs;
  int * v245 = v243->regs;
  int v246 = v245[9];
  v244[9] = v246;
  int v248 = v243->timer;
  int v310 = v248 + 1;
  v243->timer = v310;
  int * v250 = v243->regs;
  int v251 = v250[8];
  int * v252 = v243->cache_keys;
  int v253 = v252[0];
  bool v315 = v253 == ((int)((unsigned int)v251 >> 2));
  int v301;
  if (v315) {
    int * v254 = v243->cache_vals;
    int v255 = v254[0];
    v301 = v255;
  } else {
    int * v257 = v243->cache_keys;
    int v258 = v257[1];
    bool v320 = v258 == ((int)((unsigned int)v251 >> 2));
    int v299;
    if (v320) {
      int * v259 = v243->cache_vals;
      int v260 = v259[1];
      int * v261 = v243->cache_keys;
      int * v262 = v243->cache_keys;
      int v263 = v262[0];
      v261[1] = v263;
      int * v265 = v243->cache_vals;
      int * v266 = v243->cache_vals;
      int v267 = v266[0];
      v265[1] = v267;
      int * v269 = v243->cache_keys;
      int v329 = (int)((unsigned int)v251 >> 2);
      v269[0] = v329;
      int * v271 = v243->cache_vals;
      v271[0] = v260;
      int v273 = v243->timer;
      int v332 = v273 + 1;
      v243->timer = v332;
      v299 = v260;
    } else {
      int * v276 = v243->mem;
      int v334 = (int)((unsigned int)v251 >> 2);
      int v277 = v276[v334];
      int * v278 = v243->mem;
      int * v279 = v243->cache_keys;
      int v280 = v279[1];
      int * v281 = v243->cache_vals;
      int v282 = v281[1];
      v278[v280] = v282;
      int * v284 = v243->cache_keys;
      int * v285 = v243->cache_keys;
      int v286 = v285[0];
      v284[1] = v286;
      int * v288 = v243->cache_vals;
      int * v289 = v243->cache_vals;
      int v290 = v289[0];
      v288[1] = v290;
      int * v292 = v243->cache_keys;
      v292[0] = v334;
      int * v294 = v243->cache_vals;
      v294[0] = v277;
      int v296 = v243->timer;
      int v349 = v296 + 100;
      v243->timer = v349;
      v299 = v277;
    }
    v301 = v299;
  }
  int * v302 = v243->regs;
  v302[9] = v301;
  struct StateT * v304 = slot_10(v243);
  return v304;
}

struct StateT * slot_22(struct StateT * v814) {
  int * v815 = v814->saved_regs;
  int * v816 = v814->regs;
  int v817 = v816[16];
  v815[16] = v817;
  int v819 = v814->timer;
  int v833 = v819 + 1;
  v814->timer = v833;
  int * v821 = v814->regs;
  int v822 = v821[7];
  int * v823 = v814->regs;
  int v824 = v823[9];
  int * v825 = v814->regs;
  int v839 = v822 ^ v824;
  v825[16] = v839;
  struct StateT * v827 = slot_23(v814);
  return v827;
}

struct StateT * slot_11(struct StateT * v383) {
  int * v384 = v383->saved_regs;
  int * v385 = v383->regs;
  int v386 = v385[5];
  v384[5] = v386;
  int v388 = v383->timer;
  int v402 = v388 + 1;
  v383->timer = v402;
  int * v390 = v383->regs;
  int v391 = v390[5];
  int * v392 = v383->regs;
  int v393 = v392[16];
  int * v394 = v383->regs;
  int v407 = v391 | v393;
  v394[5] = v407;
  struct StateT * v396 = slot_12(v383);
  return v396;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
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
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}