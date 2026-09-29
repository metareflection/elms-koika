// verify: leak (Eva should report untainted: unknown) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
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
struct StateT2 * slot_1(struct StateT2 * v45);
struct StateT2 * slot_2(struct StateT2 * v463);
struct StateT2 * slot_3(struct StateT2 * v502);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v45) {
  struct StateT * v46 = v45->a;
  int v47 = v46->timer;
  struct StateT * v48 = v45->b;
  int v49 = v48->timer;
  bool v276 = v47 == v49;
  squared_assert(v276);
  squared_assume(v276);
  struct StateT * v52 = v45->a;
  int v53 = v52->timer;
  int v278 = v53 + 1;
  v52->timer = v278;
  struct StateT * v55 = v45->b;
  int v56 = v55->timer;
  int v280 = v56 + 1;
  v55->timer = v280;
  struct StateT * v58 = v45->a;
  int * v59 = v58->regs;
  int v60 = v59[10];
  int * v61 = v58->cache_tags;
  int v285 = (((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2;
  int v62 = v61[v285];
  int v286 = ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + 1;
  int v63 = v61[v286];
  int v287 = 4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2);
  int v64 = v61[v287];
  int v288 = (4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v65 = v61[v288];
  int v66 = v58->timer;
  int v289 = v66 + ((100 ^ (((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) & 104)))));
  v58->timer = v289;
  int * v68 = v58->cache_vals;
  bool v290 = !(((~(((v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v62 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) == 0);
  int v161;
  if (v290) {
    int * v69 = v58->cache_age;
    int v292 = ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) & 1);
    int v70 = v69[v292];
    int v71 = v69[v285];
    int v293 = v71 + ((int)((unsigned int)(v71 - v70) >> 31));
    v69[v285] = v293;
    int * v73 = v58->cache_age;
    int v74 = v73[v286];
    int v295 = v74 + ((int)((unsigned int)(v74 - v70) >> 31));
    v73[v286] = v295;
    int * v76 = v58->cache_age;
    v76[v292] = 0;
    v161 = v292;
  } else {
    int * v79 = v58->cache_age;
    int v299 = (((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2;
    int v80 = v79[v299];
    int * v81 = v58->cache_tags;
    int v82 = v81[v299];
    int v83 = v79[v286];
    int v84 = v81[v286];
    bool v301 = !(((~(((v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v64 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31))) == 0);
    int v138;
    if (v301) {
      int * v85 = v58->cache_age;
      int v303 = (4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1))))) >> 31)) & 1);
      int v86 = v85[v303];
      int v87 = v85[v287];
      int v304 = v87 + ((int)((unsigned int)(v87 - v86) >> 31));
      v85[v287] = v304;
      int * v89 = v58->cache_age;
      int v90 = v89[v288];
      int v306 = v90 + ((int)((unsigned int)(v90 - v86) >> 31));
      v89[v288] = v306;
      int * v92 = v58->cache_age;
      v92[v303] = 0;
      v138 = v303;
    } else {
      int * v95 = v58->cache_age;
      int v310 = 4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2);
      int v96 = v95[v310];
      int * v97 = v58->cache_tags;
      int v98 = v97[v310];
      int v99 = v95[v288];
      int v100 = v97[v288];
      int * v101 = v58->cache_dirty;
      int v313 = (4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v102 = v101[v313];
      bool v314 = !(v102 == 0);
      if (v314) {
        int * v103 = v58->cache_tags;
        int v104 = v103[v313];
        int * v105 = v58->cache_vals;
        int v317 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v106 = v105[v317];
        int v318 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v107 = v105[v318];
        int * v108 = v58->mem;
        int v320 = v104 * 2;
        v108[v320] = v106;
        int * v110 = v58->mem;
        int v323 = (v104 * 2) + 1;
        v110[v323] = v107;
        ;
      } else {
        ;
      }
      int * v115 = v58->mem;
      int v328 = ((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) * 2;
      int v116 = v115[v328];
      int v329 = (((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) * 2) + 1;
      int v117 = v115[v329];
      int * v118 = v58->cache_vals;
      int v331 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v118[v331] = v116;
      int * v120 = v58->cache_vals;
      int v334 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 3) * 2)) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v99 + ((~(((v100 ^ -1) | (-(v100 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v120[v334] = v117;
      int * v122 = v58->cache_tags;
      int v337 = (int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1);
      v122[v313] = v337;
      int * v124 = v58->cache_dirty;
      v124[v313] = 0;
      int * v126 = v58->cache_age;
      v126[v313] = 1;
      int * v128 = v58->cache_age;
      int v129 = v128[v313];
      int v130 = v128[v287];
      int v343 = v130 + ((int)((unsigned int)(v130 - v129) >> 31));
      v128[v287] = v343;
      int * v132 = v58->cache_age;
      int v133 = v132[v288];
      int v345 = v133 + ((int)((unsigned int)(v133 - v129) >> 31));
      v132[v288] = v345;
      int * v135 = v58->cache_age;
      v135[v313] = 0;
      v138 = v313;
    }
    int * v139 = v58->cache_vals;
    int v348 = v138 * 2;
    int v140 = v139[v348];
    int v349 = (v138 * 2) + 1;
    int v141 = v139[v349];
    int v350 = (((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((((v80 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v84 ^ -1) | (-(v84 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v139[v350] = v140;
    int * v143 = v58->cache_vals;
    int v353 = ((((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((((v80 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v84 ^ -1) | (-(v84 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v143[v353] = v141;
    int * v145 = v58->cache_tags;
    int v356 = ((((int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1)) & 1) * 2) + ((((v80 + ((~(((v82 ^ -1) | (-(v82 ^ -1))) >> 31)) & 2)) - (v83 + ((~(((v84 ^ -1) | (-(v84 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v357 = (int)((unsigned int)((int)((unsigned int)v60 >> 2)) >> 1);
    v145[v356] = v357;
    int * v147 = v58->cache_dirty;
    v147[v356] = 0;
    int * v149 = v58->cache_age;
    v149[v356] = 1;
    int * v151 = v58->cache_age;
    int v152 = v151[v356];
    int v153 = v151[v285];
    int v363 = v153 + ((int)((unsigned int)(v153 - v152) >> 31));
    v151[v285] = v363;
    int * v155 = v58->cache_age;
    int v156 = v155[v286];
    int v365 = v156 + ((int)((unsigned int)(v156 - v152) >> 31));
    v155[v286] = v365;
    int * v158 = v58->cache_age;
    v158[v356] = 0;
    v161 = v356;
  }
  int v368 = (v161 * 2) + (((int)((unsigned int)v60 >> 2)) & 1);
  int v162 = v68[v368];
  int * v163 = v58->regs;
  v163[11] = v162;
  struct StateT * v165 = v45->b;
  int * v166 = v165->regs;
  int v167 = v166[10];
  int * v168 = v165->cache_tags;
  int v375 = (((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2;
  int v169 = v168[v375];
  int v376 = ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2) + 1;
  int v170 = v168[v376];
  int v377 = 4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2);
  int v171 = v168[v377];
  int v378 = (4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v172 = v168[v378];
  int v173 = v165->timer;
  int v379 = v173 + ((100 ^ (((~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) | (~(((v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v169 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v169 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) | (~(((v170 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v170 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) | (~(((v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31))) & 104)))));
  v165->timer = v379;
  int * v175 = v165->cache_vals;
  bool v380 = !(((~(((v169 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v169 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) | (~(((v170 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v170 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31))) == 0);
  int v268;
  if (v380) {
    int * v176 = v165->cache_age;
    int v382 = ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2) + ((~(((v170 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v170 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) & 1);
    int v177 = v176[v382];
    int v178 = v176[v375];
    int v383 = v178 + ((int)((unsigned int)(v178 - v177) >> 31));
    v176[v375] = v383;
    int * v180 = v165->cache_age;
    int v181 = v180[v376];
    int v385 = v181 + ((int)((unsigned int)(v181 - v177) >> 31));
    v180[v376] = v385;
    int * v183 = v165->cache_age;
    v183[v382] = 0;
    v268 = v382;
  } else {
    int * v186 = v165->cache_age;
    int v389 = (((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2;
    int v187 = v186[v389];
    int * v188 = v165->cache_tags;
    int v189 = v188[v389];
    int v190 = v186[v376];
    int v191 = v188[v376];
    bool v391 = !(((~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) | (~(((v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31))) == 0);
    int v245;
    if (v391) {
      int * v192 = v165->cache_age;
      int v393 = (4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + ((~(((v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))) | (-(v172 ^ ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1))))) >> 31)) & 1);
      int v193 = v192[v393];
      int v194 = v192[v377];
      int v394 = v194 + ((int)((unsigned int)(v194 - v193) >> 31));
      v192[v377] = v394;
      int * v196 = v165->cache_age;
      int v197 = v196[v378];
      int v396 = v197 + ((int)((unsigned int)(v197 - v193) >> 31));
      v196[v378] = v396;
      int * v199 = v165->cache_age;
      v199[v393] = 0;
      v245 = v393;
    } else {
      int * v202 = v165->cache_age;
      int v400 = 4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2);
      int v203 = v202[v400];
      int * v204 = v165->cache_tags;
      int v205 = v204[v400];
      int v206 = v202[v378];
      int v207 = v204[v378];
      int * v208 = v165->cache_dirty;
      int v403 = (4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + ((((v203 + ((~(((v205 ^ -1) | (-(v205 ^ -1))) >> 31)) & 2)) - (v206 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v209 = v208[v403];
      bool v404 = !(v209 == 0);
      if (v404) {
        int * v210 = v165->cache_tags;
        int v211 = v210[v403];
        int * v212 = v165->cache_vals;
        int v407 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + ((((v203 + ((~(((v205 ^ -1) | (-(v205 ^ -1))) >> 31)) & 2)) - (v206 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v213 = v212[v407];
        int v408 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + ((((v203 + ((~(((v205 ^ -1) | (-(v205 ^ -1))) >> 31)) & 2)) - (v206 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v214 = v212[v408];
        int * v215 = v165->mem;
        int v410 = v211 * 2;
        v215[v410] = v213;
        int * v217 = v165->mem;
        int v413 = (v211 * 2) + 1;
        v217[v413] = v214;
        ;
      } else {
        ;
      }
      int * v222 = v165->mem;
      int v418 = ((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) * 2;
      int v223 = v222[v418];
      int v419 = (((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) * 2) + 1;
      int v224 = v222[v419];
      int * v225 = v165->cache_vals;
      int v421 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + ((((v203 + ((~(((v205 ^ -1) | (-(v205 ^ -1))) >> 31)) & 2)) - (v206 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v225[v421] = v223;
      int * v227 = v165->cache_vals;
      int v424 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 3) * 2)) + ((((v203 + ((~(((v205 ^ -1) | (-(v205 ^ -1))) >> 31)) & 2)) - (v206 + ((~(((v207 ^ -1) | (-(v207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v227[v424] = v224;
      int * v229 = v165->cache_tags;
      int v427 = (int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1);
      v229[v403] = v427;
      int * v231 = v165->cache_dirty;
      v231[v403] = 0;
      int * v233 = v165->cache_age;
      v233[v403] = 1;
      int * v235 = v165->cache_age;
      int v236 = v235[v403];
      int v237 = v235[v377];
      int v433 = v237 + ((int)((unsigned int)(v237 - v236) >> 31));
      v235[v377] = v433;
      int * v239 = v165->cache_age;
      int v240 = v239[v378];
      int v435 = v240 + ((int)((unsigned int)(v240 - v236) >> 31));
      v239[v378] = v435;
      int * v242 = v165->cache_age;
      v242[v403] = 0;
      v245 = v403;
    }
    int * v246 = v165->cache_vals;
    int v438 = v245 * 2;
    int v247 = v246[v438];
    int v439 = (v245 * 2) + 1;
    int v248 = v246[v439];
    int v440 = (((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2) + ((((v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2)) - (v190 + ((~(((v191 ^ -1) | (-(v191 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v246[v440] = v247;
    int * v250 = v165->cache_vals;
    int v443 = ((((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2) + ((((v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2)) - (v190 + ((~(((v191 ^ -1) | (-(v191 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v250[v443] = v248;
    int * v252 = v165->cache_tags;
    int v446 = ((((int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1)) & 1) * 2) + ((((v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2)) - (v190 + ((~(((v191 ^ -1) | (-(v191 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v447 = (int)((unsigned int)((int)((unsigned int)v167 >> 2)) >> 1);
    v252[v446] = v447;
    int * v254 = v165->cache_dirty;
    v254[v446] = 0;
    int * v256 = v165->cache_age;
    v256[v446] = 1;
    int * v258 = v165->cache_age;
    int v259 = v258[v446];
    int v260 = v258[v375];
    int v453 = v260 + ((int)((unsigned int)(v260 - v259) >> 31));
    v258[v375] = v453;
    int * v262 = v165->cache_age;
    int v263 = v262[v376];
    int v455 = v263 + ((int)((unsigned int)(v263 - v259) >> 31));
    v262[v376] = v455;
    int * v265 = v165->cache_age;
    v265[v446] = 0;
    v268 = v446;
  }
  int v458 = (v268 * 2) + (((int)((unsigned int)v167 >> 2)) & 1);
  int v269 = v175[v458];
  int * v270 = v165->regs;
  v270[11] = v269;
  struct StateT2 * v272 = slot_2(v45);
  return v272;
}

struct StateT2 * slot_2(struct StateT2 * v463) {
  struct StateT * v464 = v463->a;
  int v465 = v464->timer;
  struct StateT * v466 = v463->b;
  int v467 = v466->timer;
  bool v488 = v465 == v467;
  squared_assert(v488);
  squared_assume(v488);
  struct StateT * v470 = v463->a;
  int v471 = v470->timer;
  int v490 = v471 + 1;
  v470->timer = v490;
  struct StateT * v473 = v463->b;
  int v474 = v473->timer;
  int v492 = v474 + 1;
  v473->timer = v492;
  struct StateT * v476 = v463->a;
  int * v477 = v476->regs;
  int v478 = v477[11];
  int v496 = v478 << 2;
  v477[11] = v496;
  struct StateT * v480 = v463->b;
  int * v481 = v480->regs;
  int v482 = v481[11];
  int v499 = v482 << 2;
  v481[11] = v499;
  struct StateT2 * v484 = slot_3(v463);
  return v484;
}

struct StateT2 * slot_3(struct StateT2 * v502) {
  struct StateT * v503 = v502->a;
  int v504 = v503->timer;
  struct StateT * v505 = v502->b;
  int v506 = v505->timer;
  bool v732 = v504 == v506;
  squared_assert(v732);
  squared_assume(v732);
  struct StateT * v509 = v502->a;
  int v510 = v509->timer;
  int v734 = v510 + 1;
  v509->timer = v734;
  struct StateT * v512 = v502->b;
  int v513 = v512->timer;
  int v736 = v513 + 1;
  v512->timer = v736;
  struct StateT * v515 = v502->a;
  int * v516 = v515->regs;
  int v517 = v516[11];
  int * v518 = v515->cache_tags;
  int v741 = (((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2;
  int v519 = v518[v741];
  int v742 = ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v520 = v518[v742];
  int v743 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2);
  int v521 = v518[v743];
  int v744 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v522 = v518[v744];
  int v523 = v515->timer;
  int v745 = v523 + ((100 ^ (((~(((v521 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v521 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v520 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v520 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v521 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v521 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v515->timer = v745;
  int * v525 = v515->cache_vals;
  bool v746 = !(((~(((v519 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v519 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v520 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v520 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v618;
  if (v746) {
    int * v526 = v515->cache_age;
    int v748 = ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v520 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v520 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v527 = v526[v748];
    int v528 = v526[v741];
    int v749 = v528 + ((int)((unsigned int)(v528 - v527) >> 31));
    v526[v741] = v749;
    int * v530 = v515->cache_age;
    int v531 = v530[v742];
    int v751 = v531 + ((int)((unsigned int)(v531 - v527) >> 31));
    v530[v742] = v751;
    int * v533 = v515->cache_age;
    v533[v748] = 0;
    v618 = v748;
  } else {
    int * v536 = v515->cache_age;
    int v755 = (((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2;
    int v537 = v536[v755];
    int * v538 = v515->cache_tags;
    int v539 = v538[v755];
    int v540 = v536[v742];
    int v541 = v538[v742];
    bool v757 = !(((~(((v521 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v521 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v595;
    if (v757) {
      int * v542 = v515->cache_age;
      int v759 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))) | (-(v522 ^ ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v543 = v542[v759];
      int v544 = v542[v743];
      int v760 = v544 + ((int)((unsigned int)(v544 - v543) >> 31));
      v542[v743] = v760;
      int * v546 = v515->cache_age;
      int v547 = v546[v744];
      int v762 = v547 + ((int)((unsigned int)(v547 - v543) >> 31));
      v546[v744] = v762;
      int * v549 = v515->cache_age;
      v549[v759] = 0;
      v595 = v759;
    } else {
      int * v552 = v515->cache_age;
      int v766 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2);
      int v553 = v552[v766];
      int * v554 = v515->cache_tags;
      int v555 = v554[v766];
      int v556 = v552[v744];
      int v557 = v554[v744];
      int * v558 = v515->cache_dirty;
      int v769 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v553 + ((~(((v555 ^ -1) | (-(v555 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v559 = v558[v769];
      bool v770 = !(v559 == 0);
      if (v770) {
        int * v560 = v515->cache_tags;
        int v561 = v560[v769];
        int * v562 = v515->cache_vals;
        int v773 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v553 + ((~(((v555 ^ -1) | (-(v555 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v563 = v562[v773];
        int v774 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v553 + ((~(((v555 ^ -1) | (-(v555 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v564 = v562[v774];
        int * v565 = v515->mem;
        int v776 = v561 * 2;
        v565[v776] = v563;
        int * v567 = v515->mem;
        int v779 = (v561 * 2) + 1;
        v567[v779] = v564;
        ;
      } else {
        ;
      }
      int * v572 = v515->mem;
      int v784 = ((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) * 2;
      int v573 = v572[v784];
      int v785 = (((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) * 2) + 1;
      int v574 = v572[v785];
      int * v575 = v515->cache_vals;
      int v787 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v553 + ((~(((v555 ^ -1) | (-(v555 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v575[v787] = v573;
      int * v577 = v515->cache_vals;
      int v790 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v553 + ((~(((v555 ^ -1) | (-(v555 ^ -1))) >> 31)) & 2)) - (v556 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v577[v790] = v574;
      int * v579 = v515->cache_tags;
      int v793 = (int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1);
      v579[v769] = v793;
      int * v581 = v515->cache_dirty;
      v581[v769] = 0;
      int * v583 = v515->cache_age;
      v583[v769] = 1;
      int * v585 = v515->cache_age;
      int v586 = v585[v769];
      int v587 = v585[v743];
      int v799 = v587 + ((int)((unsigned int)(v587 - v586) >> 31));
      v585[v743] = v799;
      int * v589 = v515->cache_age;
      int v590 = v589[v744];
      int v801 = v590 + ((int)((unsigned int)(v590 - v586) >> 31));
      v589[v744] = v801;
      int * v592 = v515->cache_age;
      v592[v769] = 0;
      v595 = v769;
    }
    int * v596 = v515->cache_vals;
    int v804 = v595 * 2;
    int v597 = v596[v804];
    int v805 = (v595 * 2) + 1;
    int v598 = v596[v805];
    int v806 = (((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v537 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2)) - (v540 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v596[v806] = v597;
    int * v600 = v515->cache_vals;
    int v809 = ((((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v537 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2)) - (v540 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v600[v809] = v598;
    int * v602 = v515->cache_tags;
    int v812 = ((((int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v537 + ((~(((v539 ^ -1) | (-(v539 ^ -1))) >> 31)) & 2)) - (v540 + ((~(((v541 ^ -1) | (-(v541 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v813 = (int)((unsigned int)((int)((unsigned int)(v517 + 16) >> 2)) >> 1);
    v602[v812] = v813;
    int * v604 = v515->cache_dirty;
    v604[v812] = 0;
    int * v606 = v515->cache_age;
    v606[v812] = 1;
    int * v608 = v515->cache_age;
    int v609 = v608[v812];
    int v610 = v608[v741];
    int v819 = v610 + ((int)((unsigned int)(v610 - v609) >> 31));
    v608[v741] = v819;
    int * v612 = v515->cache_age;
    int v613 = v612[v742];
    int v821 = v613 + ((int)((unsigned int)(v613 - v609) >> 31));
    v612[v742] = v821;
    int * v615 = v515->cache_age;
    v615[v812] = 0;
    v618 = v812;
  }
  int v824 = (v618 * 2) + (((int)((unsigned int)(v517 + 16) >> 2)) & 1);
  int v619 = v525[v824];
  int * v620 = v515->regs;
  v620[12] = v619;
  struct StateT * v622 = v502->b;
  int * v623 = v622->regs;
  int v624 = v623[11];
  int * v625 = v622->cache_tags;
  int v831 = (((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2;
  int v626 = v625[v831];
  int v832 = ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v627 = v625[v832];
  int v833 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2);
  int v628 = v625[v833];
  int v834 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v629 = v625[v834];
  int v630 = v622->timer;
  int v835 = v630 + ((100 ^ (((~(((v628 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v628 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v626 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v626 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v627 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v627 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v628 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v628 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v622->timer = v835;
  int * v632 = v622->cache_vals;
  bool v836 = !(((~(((v626 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v626 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v627 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v627 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v725;
  if (v836) {
    int * v633 = v622->cache_age;
    int v838 = ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v627 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v627 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v634 = v633[v838];
    int v635 = v633[v831];
    int v839 = v635 + ((int)((unsigned int)(v635 - v634) >> 31));
    v633[v831] = v839;
    int * v637 = v622->cache_age;
    int v638 = v637[v832];
    int v841 = v638 + ((int)((unsigned int)(v638 - v634) >> 31));
    v637[v832] = v841;
    int * v640 = v622->cache_age;
    v640[v838] = 0;
    v725 = v838;
  } else {
    int * v643 = v622->cache_age;
    int v845 = (((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2;
    int v644 = v643[v845];
    int * v645 = v622->cache_tags;
    int v646 = v645[v845];
    int v647 = v643[v832];
    int v648 = v645[v832];
    bool v847 = !(((~(((v628 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v628 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v702;
    if (v847) {
      int * v649 = v622->cache_age;
      int v849 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))) | (-(v629 ^ ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v650 = v649[v849];
      int v651 = v649[v833];
      int v850 = v651 + ((int)((unsigned int)(v651 - v650) >> 31));
      v649[v833] = v850;
      int * v653 = v622->cache_age;
      int v654 = v653[v834];
      int v852 = v654 + ((int)((unsigned int)(v654 - v650) >> 31));
      v653[v834] = v852;
      int * v656 = v622->cache_age;
      v656[v849] = 0;
      v702 = v849;
    } else {
      int * v659 = v622->cache_age;
      int v856 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2);
      int v660 = v659[v856];
      int * v661 = v622->cache_tags;
      int v662 = v661[v856];
      int v663 = v659[v834];
      int v664 = v661[v834];
      int * v665 = v622->cache_dirty;
      int v859 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v666 = v665[v859];
      bool v860 = !(v666 == 0);
      if (v860) {
        int * v667 = v622->cache_tags;
        int v668 = v667[v859];
        int * v669 = v622->cache_vals;
        int v863 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v670 = v669[v863];
        int v864 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v671 = v669[v864];
        int * v672 = v622->mem;
        int v866 = v668 * 2;
        v672[v866] = v670;
        int * v674 = v622->mem;
        int v869 = (v668 * 2) + 1;
        v674[v869] = v671;
        ;
      } else {
        ;
      }
      int * v679 = v622->mem;
      int v874 = ((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) * 2;
      int v680 = v679[v874];
      int v875 = (((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) * 2) + 1;
      int v681 = v679[v875];
      int * v682 = v622->cache_vals;
      int v877 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v682[v877] = v680;
      int * v684 = v622->cache_vals;
      int v880 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v660 + ((~(((v662 ^ -1) | (-(v662 ^ -1))) >> 31)) & 2)) - (v663 + ((~(((v664 ^ -1) | (-(v664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v684[v880] = v681;
      int * v686 = v622->cache_tags;
      int v883 = (int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1);
      v686[v859] = v883;
      int * v688 = v622->cache_dirty;
      v688[v859] = 0;
      int * v690 = v622->cache_age;
      v690[v859] = 1;
      int * v692 = v622->cache_age;
      int v693 = v692[v859];
      int v694 = v692[v833];
      int v889 = v694 + ((int)((unsigned int)(v694 - v693) >> 31));
      v692[v833] = v889;
      int * v696 = v622->cache_age;
      int v697 = v696[v834];
      int v891 = v697 + ((int)((unsigned int)(v697 - v693) >> 31));
      v696[v834] = v891;
      int * v699 = v622->cache_age;
      v699[v859] = 0;
      v702 = v859;
    }
    int * v703 = v622->cache_vals;
    int v894 = v702 * 2;
    int v704 = v703[v894];
    int v895 = (v702 * 2) + 1;
    int v705 = v703[v895];
    int v896 = (((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v644 + ((~(((v646 ^ -1) | (-(v646 ^ -1))) >> 31)) & 2)) - (v647 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v703[v896] = v704;
    int * v707 = v622->cache_vals;
    int v899 = ((((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v644 + ((~(((v646 ^ -1) | (-(v646 ^ -1))) >> 31)) & 2)) - (v647 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v707[v899] = v705;
    int * v709 = v622->cache_tags;
    int v902 = ((((int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v644 + ((~(((v646 ^ -1) | (-(v646 ^ -1))) >> 31)) & 2)) - (v647 + ((~(((v648 ^ -1) | (-(v648 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v903 = (int)((unsigned int)((int)((unsigned int)(v624 + 16) >> 2)) >> 1);
    v709[v902] = v903;
    int * v711 = v622->cache_dirty;
    v711[v902] = 0;
    int * v713 = v622->cache_age;
    v713[v902] = 1;
    int * v715 = v622->cache_age;
    int v716 = v715[v902];
    int v717 = v715[v831];
    int v909 = v717 + ((int)((unsigned int)(v717 - v716) >> 31));
    v715[v831] = v909;
    int * v719 = v622->cache_age;
    int v720 = v719[v832];
    int v911 = v720 + ((int)((unsigned int)(v720 - v716) >> 31));
    v719[v832] = v911;
    int * v722 = v622->cache_age;
    v722[v902] = 0;
    v725 = v902;
  }
  int v914 = (v725 * 2) + (((int)((unsigned int)(v624 + 16) >> 2)) & 1);
  int v726 = v632[v914];
  int * v727 = v622->regs;
  v727[12] = v726;
  return v502;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v30 = v4 == v6;
  squared_assert(v30);
  squared_assume(v30);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v32 = v10 + 1;
  v9->timer = v32;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v34 = v13 + 1;
  v12->timer = v34;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  int v20 = v19[10];
  bool v40 = (v17 == 0) == (v20 == 0);
  squared_diverged(v40);
  squared_assume(v40);
  bool v41 = v17 == 0;
  struct StateT2 * v26;
  if (v41) {
    v26 = v2;
  } else {
    struct StateT2 * v24 = slot_1(v2);
    v26 = v24;
  }
  return v26;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}