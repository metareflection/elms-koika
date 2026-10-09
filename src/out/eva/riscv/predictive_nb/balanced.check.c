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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v329);
struct StateT * slot_6(struct StateT * v308);
struct StateT * slot_5(struct StateT * v273);
struct StateT * slot_4(struct StateT * v250);
struct StateT * slot_2(struct StateT * v226);
struct StateT * slot_3(struct StateT * v242);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v334 = v1->timer;
  int * v335 = v1->reg_ready;
  int v336 = v335[0];
  int v467 = v336 + ((v334 - v336) & (~((v334 - v336) >> 31)));
  v1->timer = v467;
  int v338 = v1->timer;
  int * v339 = v1->reg_ready;
  int v340 = v339[1];
  int v470 = v340 + ((v338 - v340) & (~((v338 - v340) >> 31)));
  v1->timer = v470;
  int v342 = v1->timer;
  int * v343 = v1->reg_ready;
  int v344 = v343[2];
  int v473 = v344 + ((v342 - v344) & (~((v342 - v344) >> 31)));
  v1->timer = v473;
  int v346 = v1->timer;
  int * v347 = v1->reg_ready;
  int v348 = v347[3];
  int v476 = v348 + ((v346 - v348) & (~((v346 - v348) >> 31)));
  v1->timer = v476;
  int v350 = v1->timer;
  int * v351 = v1->reg_ready;
  int v352 = v351[4];
  int v479 = v352 + ((v350 - v352) & (~((v350 - v352) >> 31)));
  v1->timer = v479;
  int v354 = v1->timer;
  int * v355 = v1->reg_ready;
  int v356 = v355[5];
  int v482 = v356 + ((v354 - v356) & (~((v354 - v356) >> 31)));
  v1->timer = v482;
  int v358 = v1->timer;
  int * v359 = v1->reg_ready;
  int v360 = v359[6];
  int v485 = v360 + ((v358 - v360) & (~((v358 - v360) >> 31)));
  v1->timer = v485;
  int v362 = v1->timer;
  int * v363 = v1->reg_ready;
  int v364 = v363[7];
  int v488 = v364 + ((v362 - v364) & (~((v362 - v364) >> 31)));
  v1->timer = v488;
  int v366 = v1->timer;
  int * v367 = v1->reg_ready;
  int v368 = v367[8];
  int v491 = v368 + ((v366 - v368) & (~((v366 - v368) >> 31)));
  v1->timer = v491;
  int v370 = v1->timer;
  int * v371 = v1->reg_ready;
  int v372 = v371[9];
  int v494 = v372 + ((v370 - v372) & (~((v370 - v372) >> 31)));
  v1->timer = v494;
  int v374 = v1->timer;
  int * v375 = v1->reg_ready;
  int v376 = v375[10];
  int v497 = v376 + ((v374 - v376) & (~((v374 - v376) >> 31)));
  v1->timer = v497;
  int v378 = v1->timer;
  int * v379 = v1->reg_ready;
  int v380 = v379[11];
  int v500 = v380 + ((v378 - v380) & (~((v378 - v380) >> 31)));
  v1->timer = v500;
  int v382 = v1->timer;
  int * v383 = v1->reg_ready;
  int v384 = v383[12];
  int v503 = v384 + ((v382 - v384) & (~((v382 - v384) >> 31)));
  v1->timer = v503;
  int v386 = v1->timer;
  int * v387 = v1->reg_ready;
  int v388 = v387[13];
  int v506 = v388 + ((v386 - v388) & (~((v386 - v388) >> 31)));
  v1->timer = v506;
  int v390 = v1->timer;
  int * v391 = v1->reg_ready;
  int v392 = v391[14];
  int v509 = v392 + ((v390 - v392) & (~((v390 - v392) >> 31)));
  v1->timer = v509;
  int v394 = v1->timer;
  int * v395 = v1->reg_ready;
  int v396 = v395[15];
  int v512 = v396 + ((v394 - v396) & (~((v394 - v396) >> 31)));
  v1->timer = v512;
  int v398 = v1->timer;
  int * v399 = v1->reg_ready;
  int v400 = v399[16];
  int v515 = v400 + ((v398 - v400) & (~((v398 - v400) >> 31)));
  v1->timer = v515;
  int v402 = v1->timer;
  int * v403 = v1->reg_ready;
  int v404 = v403[17];
  int v518 = v404 + ((v402 - v404) & (~((v402 - v404) >> 31)));
  v1->timer = v518;
  int v406 = v1->timer;
  int * v407 = v1->reg_ready;
  int v408 = v407[18];
  int v521 = v408 + ((v406 - v408) & (~((v406 - v408) >> 31)));
  v1->timer = v521;
  int v410 = v1->timer;
  int * v411 = v1->reg_ready;
  int v412 = v411[19];
  int v524 = v412 + ((v410 - v412) & (~((v410 - v412) >> 31)));
  v1->timer = v524;
  int v414 = v1->timer;
  int * v415 = v1->reg_ready;
  int v416 = v415[20];
  int v527 = v416 + ((v414 - v416) & (~((v414 - v416) >> 31)));
  v1->timer = v527;
  int v418 = v1->timer;
  int * v419 = v1->reg_ready;
  int v420 = v419[21];
  int v530 = v420 + ((v418 - v420) & (~((v418 - v420) >> 31)));
  v1->timer = v530;
  int v422 = v1->timer;
  int * v423 = v1->reg_ready;
  int v424 = v423[22];
  int v533 = v424 + ((v422 - v424) & (~((v422 - v424) >> 31)));
  v1->timer = v533;
  int v426 = v1->timer;
  int * v427 = v1->reg_ready;
  int v428 = v427[23];
  int v536 = v428 + ((v426 - v428) & (~((v426 - v428) >> 31)));
  v1->timer = v536;
  int v430 = v1->timer;
  int * v431 = v1->reg_ready;
  int v432 = v431[24];
  int v539 = v432 + ((v430 - v432) & (~((v430 - v432) >> 31)));
  v1->timer = v539;
  int v434 = v1->timer;
  int * v435 = v1->reg_ready;
  int v436 = v435[25];
  int v542 = v436 + ((v434 - v436) & (~((v434 - v436) >> 31)));
  v1->timer = v542;
  int v438 = v1->timer;
  int * v439 = v1->reg_ready;
  int v440 = v439[26];
  int v545 = v440 + ((v438 - v440) & (~((v438 - v440) >> 31)));
  v1->timer = v545;
  int v442 = v1->timer;
  int * v443 = v1->reg_ready;
  int v444 = v443[27];
  int v548 = v444 + ((v442 - v444) & (~((v442 - v444) >> 31)));
  v1->timer = v548;
  int v446 = v1->timer;
  int * v447 = v1->reg_ready;
  int v448 = v447[28];
  int v551 = v448 + ((v446 - v448) & (~((v446 - v448) >> 31)));
  v1->timer = v551;
  int v450 = v1->timer;
  int * v451 = v1->reg_ready;
  int v452 = v451[29];
  int v554 = v452 + ((v450 - v452) & (~((v450 - v452) >> 31)));
  v1->timer = v554;
  int v454 = v1->timer;
  int * v455 = v1->reg_ready;
  int v456 = v455[30];
  int v557 = v456 + ((v454 - v456) & (~((v454 - v456) >> 31)));
  v1->timer = v557;
  int v458 = v1->timer;
  int * v459 = v1->reg_ready;
  int v460 = v459[31];
  int v560 = v460 + ((v458 - v460) & (~((v458 - v460) >> 31)));
  v1->timer = v560;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[12];
  int * v23 = v18->regs;
  int v24 = v23[12];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v221 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[16] = v221;
  int * v127 = v18->regs;
  v127[16] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v329) {
  int v330 = v329->timer;
  int v333 = v330 + 1;
  v329->timer = v333;
  return v329;
}

struct StateT * slot_6(struct StateT * v308) {
  int v309 = v308->timer;
  int v317 = v309 + 1;
  v308->timer = v317;
  int * v311 = v308->reg_ready;
  v311[18] = v317;
  int * v313 = v308->regs;
  v313[18] = 2;
  struct StateT * v315 = slot_8(v308);
  return v315;
}

struct StateT * slot_5(struct StateT * v273) {
  int * v274 = v273->regs;
  int v275 = v274[16];
  int v276 = v274[17];
  bool v295 = v275 < v276;
  struct StateT * v290;
  if (v295) {
    int v277 = v273->timer;
    int v296 = v277 + 15;
    v273->timer = v296;
    int * v279 = v273->saved_regs;
    int v280 = v279[18];
    int * v281 = v273->regs;
    v281[18] = v280;
    int * v283 = v273->reg_ready;
    int v284 = v273->timer;
    v283[18] = v284;
    struct StateT * v286 = slot_6(v273);
    v290 = v286;
  } else {
    struct StateT * v288 = slot_8(v273);
    v290 = v288;
  }
  return v290;
}

struct StateT * slot_4(struct StateT * v250) {
  int * v251 = v250->saved_regs;
  int * v252 = v250->regs;
  int v253 = v252[18];
  v251[18] = v253;
  int v255 = v250->timer;
  int v267 = v255 + 1;
  v250->timer = v267;
  int * v257 = v250->reg_ready;
  v257[18] = v267;
  int * v259 = v250->regs;
  v259[18] = 1;
  struct StateT * v261 = slot_5(v250);
  return v261;
}

struct StateT * slot_2(struct StateT * v226) {
  int v227 = v226->timer;
  int v235 = v227 + 1;
  v226->timer = v235;
  int * v229 = v226->reg_ready;
  v229[17] = v235;
  int * v231 = v226->regs;
  v231[17] = 10;
  struct StateT * v233 = slot_3(v226);
  return v233;
}

struct StateT * slot_3(struct StateT * v242) {
  int v243 = v242->timer;
  int v247 = v243 + 1;
  v242->timer = v247;
  struct StateT * v245 = slot_4(v242);
  return v245;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 80;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}