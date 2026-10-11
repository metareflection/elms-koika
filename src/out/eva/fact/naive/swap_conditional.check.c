// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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

struct StateT * slot_12(struct StateT * v205);
struct StateT * slot_34(struct StateT * v114);
struct StateT * slot_6(struct StateT * v94);
struct StateT * slot_29(struct StateT * v495);
struct StateT * slot_25(struct StateT * v431);
struct StateT * slot_16(struct StateT * v275);
struct StateT * slot_23(struct StateT * v396);
struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_7(struct StateT * v119);
struct StateT * slot_21(struct StateT * v358);
struct StateT * slot_31(struct StateT * v530);
struct StateT * slot_3(struct StateT * v45);
struct StateT * slot_26(struct StateT * v447);
struct StateT * slot_10(struct StateT * v167);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v323);
struct StateT * slot_13(struct StateT * v224);
struct StateT * slot_24(struct StateT * v415);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v243);
struct StateT * slot_28(struct StateT * v479);
struct StateT * slot_32(struct StateT * v549);
struct StateT * slot_17(struct StateT * v291);
struct StateT * slot_20(struct StateT * v339);
struct StateT * slot_33(struct StateT * v563);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v134);
struct StateT * slot_27(struct StateT * v463);
struct StateT * slot_30(struct StateT * v511);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_15(struct StateT * v259);
struct StateT * slot_18(struct StateT * v307);
struct StateT * slot_9(struct StateT * v151);
struct StateT * slot_22(struct StateT * v377);
struct StateT * slot_11(struct StateT * v186);
struct StateT * slot_12(struct StateT * v205) {
  int v206 = v205->timer;
  int v215 = v206 + 1;
  v205->timer = v215;
  int * v208 = v205->regs;
  int v209 = v208[15];
  int * v210 = v205->mem;
  int v219 = (int)((unsigned int)(v209 + 4) >> 2);
  int v211 = v210[v219];
  v208[6] = v211;
  struct StateT * v213 = slot_13(v205);
  return v213;
}

struct StateT * slot_34(struct StateT * v114) {
  int v115 = v114->timer;
  int v118 = v115 + 1;
  v114->timer = v118;
  return v114;
}

struct StateT * slot_6(struct StateT * v94) {
  int v95 = v94->timer;
  int v105 = v95 + 1;
  v94->timer = v105;
  int * v97 = v94->regs;
  int v98 = v97[12];
  bool v108 = (v98 ^ -2147483648) < -2147483648;
  struct StateT * v103;
  if (v108) {
    struct StateT * v99 = slot_34(v94);
    v103 = v99;
  } else {
    struct StateT * v101 = slot_7(v94);
    v103 = v101;
  }
  return v103;
}

struct StateT * slot_29(struct StateT * v495) {
  int v496 = v495->timer;
  int v504 = v496 + 1;
  v495->timer = v504;
  int * v498 = v495->regs;
  int v499 = v498[6];
  int v500 = v498[17];
  int v508 = v499 ^ v500;
  v498[17] = v508;
  struct StateT * v502 = slot_30(v495);
  return v502;
}

struct StateT * slot_25(struct StateT * v431) {
  int v432 = v431->timer;
  int v440 = v432 + 1;
  v431->timer = v440;
  int * v434 = v431->regs;
  int v435 = v434[17];
  int v436 = v434[6];
  int v444 = v435 ^ v436;
  v434[17] = v444;
  struct StateT * v438 = slot_26(v431);
  return v438;
}

struct StateT * slot_16(struct StateT * v275) {
  int v276 = v275->timer;
  int v284 = v276 + 1;
  v275->timer = v284;
  int * v278 = v275->regs;
  int v279 = v278[13];
  int v280 = v278[7];
  int v288 = v279 & v280;
  v278[7] = v288;
  struct StateT * v282 = slot_17(v275);
  return v282;
}

struct StateT * slot_23(struct StateT * v396) {
  int v397 = v396->timer;
  int v406 = v397 + 1;
  v396->timer = v406;
  int * v399 = v396->regs;
  int v400 = v399[15];
  int * v401 = v396->mem;
  int v410 = (int)((unsigned int)v400 >> 2);
  int v402 = v401[v410];
  v399[6] = v402;
  struct StateT * v404 = slot_24(v396);
  return v404;
}

struct StateT * slot_5(struct StateT * v80) {
  int v81 = v80->timer;
  int v88 = v81 + 1;
  v80->timer = v88;
  int * v83 = v80->regs;
  int v84 = v83[13];
  int v91 = v84 + -1;
  v83[13] = v91;
  struct StateT * v86 = slot_6(v80);
  return v86;
}

struct StateT * slot_2(struct StateT * v29) {
  int v30 = v29->timer;
  int v38 = v30 + 1;
  v29->timer = v38;
  int * v32 = v29->regs;
  int v33 = v32[12];
  int v34 = v32[13];
  int v42 = v33 | v34;
  v32[13] = v42;
  struct StateT * v36 = slot_3(v29);
  return v36;
}

struct StateT * slot_7(struct StateT * v119) {
  int v120 = v119->timer;
  int v127 = v120 + 1;
  v119->timer = v127;
  int * v122 = v119->regs;
  int v123 = v122[14];
  int v131 = v123 << 3;
  v122[15] = v131;
  struct StateT * v125 = slot_8(v119);
  return v125;
}

struct StateT * slot_21(struct StateT * v358) {
  int v359 = v358->timer;
  int v368 = v359 + 1;
  v358->timer = v368;
  int * v361 = v358->regs;
  int v362 = v361[16];
  int v363 = v361[6];
  int * v364 = v358->mem;
  int v373 = (int)((unsigned int)(v362 + 4) >> 2);
  v364[v373] = v363;
  struct StateT * v366 = slot_22(v358);
  return v366;
}

struct StateT * slot_31(struct StateT * v530) {
  int v531 = v530->timer;
  int v540 = v531 + 1;
  v530->timer = v540;
  int * v533 = v530->regs;
  int v534 = v533[15];
  int v535 = v533[16];
  int * v536 = v530->mem;
  int v545 = (int)((unsigned int)(v534 + 4) >> 2);
  v536[v545] = v535;
  struct StateT * v538 = slot_32(v530);
  return v538;
}

struct StateT * slot_3(struct StateT * v45) {
  int v46 = v45->timer;
  int v52 = v46 + 1;
  v45->timer = v52;
  int * v48 = v45->regs;
  v48[12] = 4;
  struct StateT * v50 = slot_4(v45);
  return v50;
}

struct StateT * slot_26(struct StateT * v447) {
  int v448 = v447->timer;
  int v456 = v448 + 1;
  v447->timer = v456;
  int * v450 = v447->regs;
  int v451 = v450[13];
  int v452 = v450[17];
  int v460 = v451 & v452;
  v450[17] = v460;
  struct StateT * v454 = slot_27(v447);
  return v454;
}

struct StateT * slot_10(struct StateT * v167) {
  int v168 = v167->timer;
  int v177 = v168 + 1;
  v167->timer = v177;
  int * v170 = v167->regs;
  int v171 = v170[16];
  int * v172 = v167->mem;
  int v181 = (int)((unsigned int)v171 >> 2);
  int v173 = v172[v181];
  v170[17] = v173;
  struct StateT * v175 = slot_11(v167);
  return v175;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v23 = v16 + 1;
  v15->timer = v23;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int v26 = v19 ^ 1;
  v18[12] = v26;
  struct StateT * v21 = slot_2(v15);
  return v21;
}

struct StateT * slot_19(struct StateT * v323) {
  int v324 = v323->timer;
  int v332 = v324 + 1;
  v323->timer = v332;
  int * v326 = v323->regs;
  int v327 = v326[17];
  int v328 = v326[7];
  int v336 = v327 ^ v328;
  v326[7] = v336;
  struct StateT * v330 = slot_20(v323);
  return v330;
}

struct StateT * slot_13(struct StateT * v224) {
  int v225 = v224->timer;
  int v234 = v225 + 1;
  v224->timer = v234;
  int * v227 = v224->regs;
  int v228 = v227[15];
  int * v229 = v224->mem;
  int v238 = (int)((unsigned int)v228 >> 2);
  int v230 = v229[v238];
  v227[7] = v230;
  struct StateT * v232 = slot_14(v224);
  return v232;
}

struct StateT * slot_24(struct StateT * v415) {
  int v416 = v415->timer;
  int v424 = v416 + 1;
  v415->timer = v424;
  int * v418 = v415->regs;
  int v419 = v418[5];
  int v420 = v418[16];
  int v428 = v419 ^ v420;
  v418[5] = v428;
  struct StateT * v422 = slot_25(v415);
  return v422;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[14] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v243) {
  int v244 = v243->timer;
  int v252 = v244 + 1;
  v243->timer = v252;
  int * v246 = v243->regs;
  int v247 = v246[6];
  int v248 = v246[5];
  int v256 = v247 ^ v248;
  v246[6] = v256;
  struct StateT * v250 = slot_15(v243);
  return v250;
}

struct StateT * slot_28(struct StateT * v479) {
  int v480 = v479->timer;
  int v488 = v480 + 1;
  v479->timer = v488;
  int * v482 = v479->regs;
  int v483 = v482[16];
  int v484 = v482[5];
  int v492 = v483 ^ v484;
  v482[16] = v492;
  struct StateT * v486 = slot_29(v479);
  return v486;
}

struct StateT * slot_32(struct StateT * v549) {
  int v550 = v549->timer;
  int v557 = v550 + 1;
  v549->timer = v557;
  int * v552 = v549->regs;
  int v553 = v552[14];
  int v560 = v553 + 1;
  v552[14] = v560;
  struct StateT * v555 = slot_33(v549);
  return v555;
}

struct StateT * slot_17(struct StateT * v291) {
  int v292 = v291->timer;
  int v300 = v292 + 1;
  v291->timer = v300;
  int * v294 = v291->regs;
  int v295 = v294[13];
  int v296 = v294[6];
  int v304 = v295 & v296;
  v294[6] = v304;
  struct StateT * v298 = slot_18(v291);
  return v298;
}

struct StateT * slot_20(struct StateT * v339) {
  int v340 = v339->timer;
  int v349 = v340 + 1;
  v339->timer = v349;
  int * v342 = v339->regs;
  int v343 = v342[16];
  int v344 = v342[7];
  int * v345 = v339->mem;
  int v354 = (int)((unsigned int)v343 >> 2);
  v345[v354] = v344;
  struct StateT * v347 = slot_21(v339);
  return v347;
}

struct StateT * slot_33(struct StateT * v563) {
  int v564 = v563->timer;
  int v575 = v564 + 1;
  v563->timer = v575;
  int * v566 = v563->regs;
  int v567 = v566[12];
  int v568 = v566[14];
  bool v579 = (v567 ^ -2147483648) >= (v568 ^ -2147483648);
  struct StateT * v573;
  if (v579) {
    struct StateT * v569 = slot_7(v563);
    v573 = v569;
  } else {
    struct StateT * v571 = slot_34(v563);
    v573 = v571;
  }
  return v573;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v134) {
  int v135 = v134->timer;
  int v143 = v135 + 1;
  v134->timer = v143;
  int * v137 = v134->regs;
  int v138 = v137[10];
  int v139 = v137[15];
  int v148 = v138 + v139;
  v137[16] = v148;
  struct StateT * v141 = slot_9(v134);
  return v141;
}

struct StateT * slot_27(struct StateT * v463) {
  int v464 = v463->timer;
  int v472 = v464 + 1;
  v463->timer = v472;
  int * v466 = v463->regs;
  int v467 = v466[13];
  int v468 = v466[5];
  int v476 = v467 & v468;
  v466[5] = v476;
  struct StateT * v470 = slot_28(v463);
  return v470;
}

struct StateT * slot_30(struct StateT * v511) {
  int v512 = v511->timer;
  int v521 = v512 + 1;
  v511->timer = v521;
  int * v514 = v511->regs;
  int v515 = v514[15];
  int v516 = v514[17];
  int * v517 = v511->mem;
  int v526 = (int)((unsigned int)v515 >> 2);
  v517[v526] = v516;
  struct StateT * v519 = slot_31(v511);
  return v519;
}

struct StateT * slot_4(struct StateT * v58) {
  int v59 = v58->timer;
  int v70 = v59 + 1;
  v58->timer = v70;
  int * v61 = v58->regs;
  int v62 = v61[13];
  bool v73 = -2147483648 < (v62 ^ -2147483648);
  int v65;
  if (v73) {
    v65 = 1;
  } else {
    v65 = 0;
  }
  int * v66 = v58->regs;
  v66[13] = v65;
  struct StateT * v68 = slot_5(v58);
  return v68;
}

struct StateT * slot_15(struct StateT * v259) {
  int v260 = v259->timer;
  int v268 = v260 + 1;
  v259->timer = v268;
  int * v262 = v259->regs;
  int v263 = v262[7];
  int v264 = v262[17];
  int v272 = v263 ^ v264;
  v262[7] = v272;
  struct StateT * v266 = slot_16(v259);
  return v266;
}

struct StateT * slot_18(struct StateT * v307) {
  int v308 = v307->timer;
  int v316 = v308 + 1;
  v307->timer = v316;
  int * v310 = v307->regs;
  int v311 = v310[5];
  int v312 = v310[6];
  int v320 = v311 ^ v312;
  v310[6] = v320;
  struct StateT * v314 = slot_19(v307);
  return v314;
}

struct StateT * slot_9(struct StateT * v151) {
  int v152 = v151->timer;
  int v160 = v152 + 1;
  v151->timer = v160;
  int * v154 = v151->regs;
  int v155 = v154[11];
  int v156 = v154[15];
  int v164 = v155 + v156;
  v154[15] = v164;
  struct StateT * v158 = slot_10(v151);
  return v158;
}

struct StateT * slot_22(struct StateT * v377) {
  int v378 = v377->timer;
  int v387 = v378 + 1;
  v377->timer = v387;
  int * v380 = v377->regs;
  int v381 = v380[15];
  int * v382 = v377->mem;
  int v391 = (int)((unsigned int)(v381 + 4) >> 2);
  int v383 = v382[v391];
  v380[16] = v383;
  struct StateT * v385 = slot_23(v377);
  return v385;
}

struct StateT * slot_11(struct StateT * v186) {
  int v187 = v186->timer;
  int v196 = v187 + 1;
  v186->timer = v196;
  int * v189 = v186->regs;
  int v190 = v189[16];
  int * v191 = v186->mem;
  int v200 = (int)((unsigned int)(v190 + 4) >> 2);
  int v192 = v191[v200];
  v189[5] = v192;
  struct StateT * v194 = slot_12(v186);
  return v194;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, 10 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  // a12 and a13, secret: a uint64's halves, drawn separately
  // in each state
  s1.regs[12] = secret(0, 1);
  s2.regs[12] = secret(0, 1);
  s1.regs[13] = secret(0, 1);
  s2.regs[13] = secret(0, 1);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}