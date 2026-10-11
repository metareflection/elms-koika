// verify: leak likely-timeout (KLEE probably does not finish this path space) [budget 1200s]
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

struct StateT * slot_120(struct StateT * v6613);
struct StateT * slot_167(struct StateT * v8477);
struct StateT * slot_509(struct StateT * v25340);
struct StateT * slot_152(struct StateT * v7236);
struct StateT * slot_231(struct StateT * v12515);
struct StateT * slot_355(struct StateT * v17752);
struct StateT * slot_1032(struct StateT * v53560);
struct StateT * slot_616(struct StateT * v27392);
struct StateT * slot_984(struct StateT * v49596);
struct StateT * slot_232(struct StateT * v12532);
struct StateT * slot_466(struct StateT * v24577);
struct StateT * slot_764(struct StateT * v30783);
struct StateT * slot_304(struct StateT * v13881);
struct StateT * slot_31(struct StateT * v3062);
struct StateT * slot_730(struct StateT * v29516);
struct StateT * slot_585(struct StateT * v26796);
struct StateT * slot_241(struct StateT * v12698);
struct StateT * slot_611(struct StateT * v27264);
struct StateT * slot_160(struct StateT * v8027);
struct StateT * slot_745(struct StateT * v29819);
struct StateT * slot_150(struct StateT * v7189);
struct StateT * slot_391(struct StateT * v21254);
struct StateT * slot_74(struct StateT * v4187);
struct StateT * slot_372(struct StateT * v19528);
struct StateT * slot_325(struct StateT * v14954);
struct StateT * slot_895(struct StateT * v44837);
struct StateT * slot_28(struct StateT * v2637);
struct StateT * slot_517(struct StateT * v25489);
struct StateT * slot_1022(struct StateT * v51693);
struct StateT * slot_566(struct StateT * v26429);
struct StateT * slot_923(struct StateT * v46769);
struct StateT * slot_154(struct StateT * v7312);
struct StateT * slot_260(struct StateT * v13054);
struct StateT * slot_1090(struct StateT * v64201);
struct StateT * slot_305(struct StateT * v13902);
struct StateT * slot_662(struct StateT * v28294);
struct StateT * slot_34(struct StateT * v3127);
struct StateT * slot_971(struct StateT * v49250);
struct StateT * slot_1016(struct StateT * v50998);
struct StateT * slot_21(struct StateT * v1919);
struct StateT * slot_118(struct StateT * v6572);
struct StateT * slot_376(struct StateT * v20455);
struct StateT * slot_373(struct StateT * v19732);
struct StateT * slot_146(struct StateT * v7104);
struct StateT * slot_383(struct StateT * v20936);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v24969);
struct StateT * slot_148(struct StateT * v7136);
struct StateT * slot_725(struct StateT * v29424);
struct StateT * slot_918(struct StateT * v46204);
struct StateT * slot_79(struct StateT * v4569);
struct StateT * slot_568(struct StateT * v26477);
struct StateT * slot_810(struct StateT * v34831);
struct StateT * slot_571(struct StateT * v26534);
struct StateT * slot_142(struct StateT * v7023);
struct StateT * slot_416(struct StateT * v23376);
struct StateT * slot_624(struct StateT * v27536);
struct StateT * slot_1038(struct StateT * v54143);
struct StateT * slot_738(struct StateT * v29641);
struct StateT * slot_214(struct StateT * v12228);
struct StateT * slot_29(struct StateT * v2841);
struct StateT * slot_151(struct StateT * v7220);
struct StateT * slot_7(struct StateT * v1684);
struct StateT * slot_124(struct StateT * v6696);
struct StateT * slot_128(struct StateT * v6769);
struct StateT * slot_365(struct StateT * v18520);
struct StateT * slot_1025(struct StateT * v52527);
struct StateT * slot_622(struct StateT * v27504);
struct StateT * slot_523(struct StateT * v25596);
struct StateT * slot_782(struct StateT * v31865);
struct StateT * slot_87(struct StateT * v5668);
struct StateT * slot_452(struct StateT * v24338);
struct StateT * slot_67(struct StateT * v3711);
struct StateT * slot_591(struct StateT * v26904);
struct StateT * slot_546(struct StateT * v26058);
struct StateT * slot_933(struct StateT * v47257);
struct StateT * slot_1033(struct StateT * v53764);
struct StateT * slot_32(struct StateT * v3086);
struct StateT * slot_189(struct StateT * v11075);
struct StateT * slot_394(struct StateT * v21602);
struct StateT * slot_33(struct StateT * v3111);
struct StateT * slot_743(struct StateT * v29724);
struct StateT * slot_935(struct StateT * v47596);
struct StateT * slot_709(struct StateT * v29151);
struct StateT * slot_35(struct StateT * v3142);
struct StateT * slot_258(struct StateT * v13022);
struct StateT * slot_744(struct StateT * v29740);
struct StateT * slot_615(struct StateT * v27360);
struct StateT * slot_51(struct StateT * v3409);
struct StateT * slot_25(struct StateT * v1991);
struct StateT * slot_490(struct StateT * v24986);
struct StateT * slot_123(struct StateT * v6671);
struct StateT * slot_982(struct StateT * v49375);
struct StateT * slot_799(struct StateT * v33573);
struct StateT * slot_299(struct StateT * v13800);
struct StateT * slot_539(struct StateT * v25918);
struct StateT * slot_671(struct StateT * v28455);
struct StateT * slot_794(struct StateT * v33194);
struct StateT * slot_900(struct StateT * v45099);
struct StateT * slot_240(struct StateT * v12673);
struct StateT * slot_1055(struct StateT * v57559);
struct StateT * slot_548(struct StateT * v26090);
struct StateT * slot_70(struct StateT * v3787);
struct StateT * slot_348(struct StateT * v17424);
struct StateT * slot_920(struct StateT * v46533);
struct StateT * slot_749(struct StateT * v29896);
struct StateT * slot_988(struct StateT * v49662);
struct StateT * slot_1057(struct StateT * v57777);
struct StateT * slot_293(struct StateT * v13693);
struct StateT * slot_288(struct StateT * v13605);
struct StateT * slot_89(struct StateT * v5698);
struct StateT * slot_1065(struct StateT * v59363);
struct StateT * slot_140(struct StateT * v6999);
struct StateT * slot_473(struct StateT * v24693);
struct StateT * slot_913(struct StateT * v46150);
struct StateT * slot_40(struct StateT * v3222);
struct StateT * slot_586(struct StateT * v26821);
struct StateT * slot_784(struct StateT * v31927);
struct StateT * slot_85(struct StateT * v5638);
struct StateT * slot_75(struct StateT * v4502);
struct StateT * slot_387(struct StateT * v21194);
struct StateT * slot_565(struct StateT * v26413);
struct StateT * slot_188(struct StateT * v11059);
struct StateT * slot_758(struct StateT * v30381);
struct StateT * slot_110(struct StateT * v6422);
struct StateT * slot_301(struct StateT * v13840);
struct StateT * slot_502(struct StateT * v25216);
struct StateT * slot_157(struct StateT * v7664);
struct StateT * slot_1030(struct StateT * v52930);
struct StateT * slot_453(struct StateT * v24355);
struct StateT * slot_26(struct StateT * v2306);
struct StateT * slot_206(struct StateT * v12096);
struct StateT * slot_14(struct StateT * v1796);
struct StateT * slot_602(struct StateT * v27111);
struct StateT * slot_838(struct StateT * v38456);
struct StateT * slot_639(struct StateT * v27806);
struct StateT * slot_36(struct StateT * v3156);
struct StateT * slot_57(struct StateT * v3525);
struct StateT * slot_426(struct StateT * v23539);
struct StateT * slot_62(struct StateT * v3623);
struct StateT * slot_323(struct StateT * v14891);
struct StateT * slot_628(struct StateT * v27608);
struct StateT * slot_23(struct StateT * v1961);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v5652);
struct StateT * slot_100(struct StateT * v6253);
struct StateT * slot_13(struct StateT * v1779);
struct StateT * slot_109(struct StateT * v6405);
struct StateT * slot_224(struct StateT * v12396);
struct StateT * slot_184(struct StateT * v10322);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_352(struct StateT * v17482);
struct StateT * slot_249(struct StateT * v12857);
struct StateT * slot_11(struct StateT * v1745);
struct StateT * slot_228(struct StateT * v12464);
struct StateT * slot_268(struct StateT * v13212);
struct StateT * slot_501(struct StateT * v25200);
struct StateT * slot_979(struct StateT * v49330);
struct StateT * slot_136(struct StateT * v6917);
struct StateT * slot_310(struct StateT * v14030);
struct StateT * slot_197(struct StateT * v11578);
struct StateT * slot_68(struct StateT * v3735);
struct StateT * slot_105(struct StateT * v6338);
struct StateT * slot_15(struct StateT * v1813);
struct StateT * slot_222(struct StateT * v12362);
struct StateT * slot_171(struct StateT * v9140);
struct StateT * slot_634(struct StateT * v27740);
struct StateT * slot_267(struct StateT * v13195);
struct StateT * slot_316(struct StateT * v14178);
struct StateT * slot_39(struct StateT * v3205);
struct StateT * slot_60(struct StateT * v3582);
struct StateT * slot_112(struct StateT * v6456);
struct StateT * slot_256(struct StateT * v12989);
struct StateT * slot_1042(struct StateT * v54993);
struct StateT * slot_16(struct StateT * v1830);
struct StateT * slot_113(struct StateT * v6481);
struct StateT * slot_191(struct StateT * v11294);
struct StateT * slot_95(struct StateT * v6172);
struct StateT * slot_905(struct StateT * v45474);
struct StateT * slot_354(struct StateT * v17700);
struct StateT * slot_115(struct StateT * v6513);
struct StateT * slot_210(struct StateT * v12163);
struct StateT * slot_52(struct StateT * v3426);
struct StateT * slot_83(struct StateT * v5419);
struct StateT * slot_209(struct StateT * v12147);
struct StateT * slot_73(struct StateT * v4170);
struct StateT * slot_187(struct StateT * v10855);
struct StateT * slot_178(struct StateT * v9931);
struct StateT * slot_46(struct StateT * v3320);
struct StateT * slot_20(struct StateT * v1903);
struct StateT * slot_61(struct StateT * v3607);
struct StateT * slot_30(struct StateT * v3045);
struct StateT * slot_300(struct StateT * v13816);
struct StateT * slot_309(struct StateT * v14013);
struct StateT * slot_6(struct StateT * v1480);
struct StateT * slot_37(struct StateT * v3172);
struct StateT * slot_114(struct StateT * v6497);
struct StateT * slot_101(struct StateT * v6270);
struct StateT * slot_96(struct StateT * v6186);
struct StateT * slot_138(struct StateT * v6958);
struct StateT * slot_104(struct StateT * v6321);
struct StateT * slot_64(struct StateT * v3655);
struct StateT * slot_53(struct StateT * v3451);
struct StateT * slot_99(struct StateT * v6236);
struct StateT * slot_219(struct StateT * v12312);
struct StateT * slot_22(struct StateT * v1944);
struct StateT * slot_139(struct StateT * v6974);
struct StateT * slot_129(struct StateT * v6786);
struct StateT * slot_90(struct StateT * v5902);
struct StateT * slot_236(struct StateT * v12606);
struct StateT * slot_262(struct StateT * v13095);
struct StateT * slot_84(struct StateT * v5434);
struct StateT * slot_177(struct StateT * v9907);
struct StateT * slot_27(struct StateT * v2621);
struct StateT * slot_24(struct StateT * v1975);
struct StateT * slot_126(struct StateT * v6728);
struct StateT * slot_341(struct StateT * v16210);
struct StateT * slot_47(struct StateT * v3337);
struct StateT * slot_19(struct StateT * v1887);
struct StateT * slot_130(struct StateT * v6803);
struct StateT * slot_141(struct StateT * v7007);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_49(struct StateT * v3369);
struct StateT * slot_50(struct StateT * v3385);
struct StateT * slot_59(struct StateT * v3558);
struct StateT * slot_77(struct StateT * v4531);
struct StateT * slot_71(struct StateT * v3839);
struct StateT * slot_45(struct StateT * v3303);
struct StateT * slot_69(struct StateT * v3756);
struct StateT * slot_54(struct StateT * v3467);
struct StateT * slot_42(struct StateT * v3256);
struct StateT * slot_12(struct StateT * v1762);
struct StateT * slot_65(struct StateT * v3663);
struct StateT * slot_10(struct StateT * v1728);
struct StateT * slot_17(struct StateT * v1846);
struct StateT * slot_56(struct StateT * v3509);
struct StateT * slot_63(struct StateT * v3639);
struct StateT * slot_41(struct StateT * v3239);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_38(struct StateT * v3188);
struct StateT * slot_18(struct StateT * v1862);
struct StateT * slot_9(struct StateT * v1711);
struct StateT * slot_43(struct StateT * v3273);
struct StateT * slot_55(struct StateT * v3492);
struct StateT * slot_58(struct StateT * v3541);
struct StateT * slot_66(struct StateT * v3695);
struct StateT * slot_48(struct StateT * v3353);
struct StateT * slot_8(struct StateT * v1697);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_44(struct StateT * v3287);
struct StateT * slot_120(struct StateT * v6613) {
  int v6614 = v6613->timer;
  int v6626 = v6614 + 1;
  v6613->timer = v6626;
  int * v6616 = v6613->regs;
  int v6617 = v6616[29];
  int v6618 = v6616[31];
  bool v6630 = (v6617 ^ -2147483648) < (v6618 ^ -2147483648);
  int v6621;
  if (v6630) {
    v6621 = 1;
  } else {
    v6621 = 0;
  }
  int * v6622 = v6613->regs;
  v6622[6] = v6621;
  struct StateT * v6624 = slot_129(v6613);
  return v6624;
}

struct StateT * slot_167(struct StateT * v8477) {
  int v8478 = v8477->timer;
  int v8648 = v8478 + 1;
  v8477->timer = v8648;
  int * v8480 = v8477->regs;
  int v8481 = v8480[10];
  int v8482 = v8480[17];
  int * v8483 = v8477->cache_tags;
  int v8653 = (((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2;
  int v8484 = v8483[v8653];
  int v8654 = ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8485 = v8483[v8654];
  int v8655 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2);
  int v8486 = v8483[v8655];
  int v8656 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8487 = v8483[v8656];
  int v8488 = v8477->timer;
  int v8657 = v8488 + ((100 ^ (((~(((v8486 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8486 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8484 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8484 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v8485 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8485 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8486 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8486 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8477->timer = v8657;
  bool v8658 = !(((~(((v8484 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8484 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v8485 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8485 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v8582;
  if (v8658) {
    int * v8490 = v8477->cache_age;
    int v8660 = ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v8485 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8485 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v8491 = v8490[v8660];
    int v8492 = v8490[v8653];
    int v8661 = v8492 + ((int)((unsigned int)(v8492 - v8491) >> 31));
    v8490[v8653] = v8661;
    int * v8494 = v8477->cache_age;
    int v8495 = v8494[v8654];
    int v8663 = v8495 + ((int)((unsigned int)(v8495 - v8491) >> 31));
    v8494[v8654] = v8663;
    int * v8497 = v8477->cache_age;
    v8497[v8660] = 0;
    v8582 = v8660;
  } else {
    int * v8500 = v8477->cache_age;
    int v8667 = (((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2;
    int v8501 = v8500[v8667];
    int * v8502 = v8477->cache_tags;
    int v8503 = v8502[v8667];
    int v8504 = v8500[v8654];
    int v8505 = v8502[v8654];
    bool v8669 = !(((~(((v8486 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8486 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v8559;
    if (v8669) {
      int * v8506 = v8477->cache_age;
      int v8671 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8487 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v8507 = v8506[v8671];
      int v8508 = v8506[v8655];
      int v8672 = v8508 + ((int)((unsigned int)(v8508 - v8507) >> 31));
      v8506[v8655] = v8672;
      int * v8510 = v8477->cache_age;
      int v8511 = v8510[v8656];
      int v8674 = v8511 + ((int)((unsigned int)(v8511 - v8507) >> 31));
      v8510[v8656] = v8674;
      int * v8513 = v8477->cache_age;
      v8513[v8671] = 0;
      v8559 = v8671;
    } else {
      int * v8516 = v8477->cache_age;
      int v8678 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2);
      int v8517 = v8516[v8678];
      int * v8518 = v8477->cache_tags;
      int v8519 = v8518[v8678];
      int v8520 = v8516[v8656];
      int v8521 = v8518[v8656];
      int * v8522 = v8477->cache_dirty;
      int v8681 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8517 + ((~(((v8519 ^ -1) | (-(v8519 ^ -1))) >> 31)) & 2)) - (v8520 + ((~(((v8521 ^ -1) | (-(v8521 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8523 = v8522[v8681];
      bool v8682 = !(v8523 == 0);
      if (v8682) {
        int * v8524 = v8477->cache_tags;
        int v8525 = v8524[v8681];
        int * v8526 = v8477->cache_vals;
        int v8685 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8517 + ((~(((v8519 ^ -1) | (-(v8519 ^ -1))) >> 31)) & 2)) - (v8520 + ((~(((v8521 ^ -1) | (-(v8521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8527 = v8526[v8685];
        int v8686 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8517 + ((~(((v8519 ^ -1) | (-(v8519 ^ -1))) >> 31)) & 2)) - (v8520 + ((~(((v8521 ^ -1) | (-(v8521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8528 = v8526[v8686];
        int * v8529 = v8477->mem;
        int v8688 = v8525 * 2;
        v8529[v8688] = v8527;
        int * v8531 = v8477->mem;
        int v8691 = (v8525 * 2) + 1;
        v8531[v8691] = v8528;
        ;
      } else {
        ;
      }
      int * v8536 = v8477->mem;
      int v8696 = ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) * 2;
      int v8537 = v8536[v8696];
      int v8697 = (((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) * 2) + 1;
      int v8538 = v8536[v8697];
      int * v8539 = v8477->cache_vals;
      int v8699 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8517 + ((~(((v8519 ^ -1) | (-(v8519 ^ -1))) >> 31)) & 2)) - (v8520 + ((~(((v8521 ^ -1) | (-(v8521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8539[v8699] = v8537;
      int * v8541 = v8477->cache_vals;
      int v8702 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8517 + ((~(((v8519 ^ -1) | (-(v8519 ^ -1))) >> 31)) & 2)) - (v8520 + ((~(((v8521 ^ -1) | (-(v8521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8541[v8702] = v8538;
      int * v8543 = v8477->cache_tags;
      int v8705 = (int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1);
      v8543[v8681] = v8705;
      int * v8545 = v8477->cache_dirty;
      v8545[v8681] = 0;
      int * v8547 = v8477->cache_age;
      v8547[v8681] = 1;
      int * v8549 = v8477->cache_age;
      int v8550 = v8549[v8681];
      int v8551 = v8549[v8655];
      int v8711 = v8551 + ((int)((unsigned int)(v8551 - v8550) >> 31));
      v8549[v8655] = v8711;
      int * v8553 = v8477->cache_age;
      int v8554 = v8553[v8656];
      int v8713 = v8554 + ((int)((unsigned int)(v8554 - v8550) >> 31));
      v8553[v8656] = v8713;
      int * v8556 = v8477->cache_age;
      v8556[v8681] = 0;
      v8559 = v8681;
    }
    int * v8560 = v8477->cache_vals;
    int v8716 = v8559 * 2;
    int v8561 = v8560[v8716];
    int v8717 = (v8559 * 2) + 1;
    int v8562 = v8560[v8717];
    int v8718 = (((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v8501 + ((~(((v8503 ^ -1) | (-(v8503 ^ -1))) >> 31)) & 2)) - (v8504 + ((~(((v8505 ^ -1) | (-(v8505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8560[v8718] = v8561;
    int * v8564 = v8477->cache_vals;
    int v8721 = ((((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v8501 + ((~(((v8503 ^ -1) | (-(v8503 ^ -1))) >> 31)) & 2)) - (v8504 + ((~(((v8505 ^ -1) | (-(v8505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8564[v8721] = v8562;
    int * v8566 = v8477->cache_tags;
    int v8724 = ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v8501 + ((~(((v8503 ^ -1) | (-(v8503 ^ -1))) >> 31)) & 2)) - (v8504 + ((~(((v8505 ^ -1) | (-(v8505 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8725 = (int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1);
    v8566[v8724] = v8725;
    int * v8568 = v8477->cache_dirty;
    v8568[v8724] = 0;
    int * v8570 = v8477->cache_age;
    v8570[v8724] = 1;
    int * v8572 = v8477->cache_age;
    int v8573 = v8572[v8724];
    int v8574 = v8572[v8653];
    int v8731 = v8574 + ((int)((unsigned int)(v8574 - v8573) >> 31));
    v8572[v8653] = v8731;
    int * v8576 = v8477->cache_age;
    int v8577 = v8576[v8654];
    int v8733 = v8577 + ((int)((unsigned int)(v8577 - v8573) >> 31));
    v8576[v8654] = v8733;
    int * v8579 = v8477->cache_age;
    v8579[v8724] = 0;
    v8582 = v8724;
  }
  int * v8583 = v8477->cache_vals;
  int v8736 = (v8582 * 2) + (((int)((unsigned int)(v8481 + 16) >> 2)) & 1);
  v8583[v8736] = v8482;
  int * v8585 = v8477->cache_tags;
  int v8586 = v8585[v8655];
  int v8587 = v8585[v8656];
  bool v8739 = !(((~(((v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v8641;
  if (v8739) {
    int * v8588 = v8477->cache_age;
    int v8741 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))) | (-(v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v8589 = v8588[v8741];
    int v8590 = v8588[v8655];
    int v8742 = v8590 + ((int)((unsigned int)(v8590 - v8589) >> 31));
    v8588[v8655] = v8742;
    int * v8592 = v8477->cache_age;
    int v8593 = v8592[v8656];
    int v8744 = v8593 + ((int)((unsigned int)(v8593 - v8589) >> 31));
    v8592[v8656] = v8744;
    int * v8595 = v8477->cache_age;
    v8595[v8741] = 0;
    v8641 = v8741;
  } else {
    int * v8598 = v8477->cache_age;
    int v8748 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2);
    int v8599 = v8598[v8748];
    int * v8600 = v8477->cache_tags;
    int v8601 = v8600[v8748];
    int v8602 = v8598[v8656];
    int v8603 = v8600[v8656];
    int * v8604 = v8477->cache_dirty;
    int v8751 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8599 + ((~(((v8601 ^ -1) | (-(v8601 ^ -1))) >> 31)) & 2)) - (v8602 + ((~(((v8603 ^ -1) | (-(v8603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8605 = v8604[v8751];
    bool v8752 = !(v8605 == 0);
    if (v8752) {
      int * v8606 = v8477->cache_tags;
      int v8607 = v8606[v8751];
      int * v8608 = v8477->cache_vals;
      int v8755 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8599 + ((~(((v8601 ^ -1) | (-(v8601 ^ -1))) >> 31)) & 2)) - (v8602 + ((~(((v8603 ^ -1) | (-(v8603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v8609 = v8608[v8755];
      int v8756 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8599 + ((~(((v8601 ^ -1) | (-(v8601 ^ -1))) >> 31)) & 2)) - (v8602 + ((~(((v8603 ^ -1) | (-(v8603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v8610 = v8608[v8756];
      int * v8611 = v8477->mem;
      int v8758 = v8607 * 2;
      v8611[v8758] = v8609;
      int * v8613 = v8477->mem;
      int v8761 = (v8607 * 2) + 1;
      v8613[v8761] = v8610;
      ;
    } else {
      ;
    }
    int * v8618 = v8477->mem;
    int v8766 = ((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) * 2;
    int v8619 = v8618[v8766];
    int v8767 = (((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) * 2) + 1;
    int v8620 = v8618[v8767];
    int * v8621 = v8477->cache_vals;
    int v8769 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8599 + ((~(((v8601 ^ -1) | (-(v8601 ^ -1))) >> 31)) & 2)) - (v8602 + ((~(((v8603 ^ -1) | (-(v8603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8621[v8769] = v8619;
    int * v8623 = v8477->cache_vals;
    int v8772 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v8599 + ((~(((v8601 ^ -1) | (-(v8601 ^ -1))) >> 31)) & 2)) - (v8602 + ((~(((v8603 ^ -1) | (-(v8603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8623[v8772] = v8620;
    int * v8625 = v8477->cache_tags;
    int v8775 = (int)((unsigned int)((int)((unsigned int)(v8481 + 16) >> 2)) >> 1);
    v8625[v8751] = v8775;
    int * v8627 = v8477->cache_dirty;
    v8627[v8751] = 0;
    int * v8629 = v8477->cache_age;
    v8629[v8751] = 1;
    int * v8631 = v8477->cache_age;
    int v8632 = v8631[v8751];
    int v8633 = v8631[v8655];
    int v8781 = v8633 + ((int)((unsigned int)(v8633 - v8632) >> 31));
    v8631[v8655] = v8781;
    int * v8635 = v8477->cache_age;
    int v8636 = v8635[v8656];
    int v8783 = v8636 + ((int)((unsigned int)(v8636 - v8632) >> 31));
    v8635[v8656] = v8783;
    int * v8638 = v8477->cache_age;
    v8638[v8751] = 0;
    v8641 = v8751;
  }
  int * v8642 = v8477->cache_vals;
  int v8786 = (v8641 * 2) + (((int)((unsigned int)(v8481 + 16) >> 2)) & 1);
  v8642[v8786] = v8482;
  int * v8644 = v8477->cache_dirty;
  v8644[v8641] = 1;
  struct StateT * v8646 = slot_171(v8477);
  return v8646;
}

struct StateT * slot_509(struct StateT * v25340) {
  int v25341 = v25340->timer;
  int v25349 = v25341 + 1;
  v25340->timer = v25349;
  int * v25343 = v25340->regs;
  int v25344 = v25343[28];
  int v25345 = v25343[5];
  int v25353 = v25344 + v25345;
  v25343[5] = v25353;
  struct StateT * v25347 = slot_517(v25340);
  return v25347;
}

struct StateT * slot_152(struct StateT * v7236) {
  int * v7237 = v7236->saved_regs;
  int v7238 = v7237[7];
  int v7239 = v7237[29];
  bool v7267 = v7238 == v7239;
  struct StateT * v7262;
  if (v7267) {
    int v7240 = v7236->timer;
    int v7268 = v7240 + 15;
    v7236->timer = v7268;
    int * v7242 = v7236->saved_regs;
    int v7243 = v7242[28];
    int * v7244 = v7236->regs;
    v7244[28] = v7243;
    int * v7246 = v7236->saved_regs;
    int v7247 = v7246[29];
    int * v7248 = v7236->regs;
    v7248[29] = v7247;
    int * v7250 = v7236->saved_regs;
    int v7251 = v7250[7];
    int * v7252 = v7236->regs;
    v7252[7] = v7251;
    int * v7254 = v7236->saved_regs;
    int v7255 = v7254[5];
    int * v7256 = v7236->regs;
    v7256[5] = v7255;
    struct StateT * v7258 = slot_154(v7236);
    v7262 = v7258;
  } else {
    struct StateT * v7260 = slot_167(v7236);
    v7262 = v7260;
  }
  return v7262;
}

struct StateT * slot_231(struct StateT * v12515) {
  int v12516 = v12515->timer;
  int v12524 = v12516 + 1;
  v12515->timer = v12524;
  int * v12518 = v12515->regs;
  int v12519 = v12518[29];
  int v12520 = v12518[13];
  int v12529 = (((((int)((unsigned int)v12519 >> 16)) * ((int)((unsigned int)v12520 >> 16))) + ((int)((unsigned int)((v12519 & 65535) * ((int)((unsigned int)v12520 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v12519 >> 16)) * (v12520 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v12519 & 65535) * (v12520 & 65535)) >> 16)) + (((v12519 & 65535) * ((int)((unsigned int)v12520 >> 16))) & 65535)) + ((((int)((unsigned int)v12519 >> 16)) * (v12520 & 65535)) & 65535)) >> 16));
  v12518[18] = v12529;
  struct StateT * v12522 = slot_249(v12515);
  return v12522;
}

struct StateT * slot_355(struct StateT * v17752) {
  int v17753 = v17752->timer;
  int v17765 = v17753 + 1;
  v17752->timer = v17765;
  int * v17755 = v17752->regs;
  int v17756 = v17755[28];
  int v17757 = v17755[5];
  bool v17769 = (v17756 ^ -2147483648) < (v17757 ^ -2147483648);
  int v17760;
  if (v17769) {
    v17760 = 1;
  } else {
    v17760 = 0;
  }
  int * v17761 = v17752->regs;
  v17761[5] = v17760;
  struct StateT * v17763 = slot_365(v17752);
  return v17763;
}

struct StateT * slot_1032(struct StateT * v53560) {
  int v53561 = v53560->timer;
  int v53671 = v53561 + 1;
  v53560->timer = v53671;
  int * v53563 = v53560->regs;
  int v53564 = v53563[2];
  int * v53565 = v53560->cache_tags;
  int v53675 = (((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2;
  int v53566 = v53565[v53675];
  int v53676 = ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v53567 = v53565[v53676];
  int v53677 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2);
  int v53568 = v53565[v53677];
  int v53678 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v53569 = v53565[v53678];
  int v53570 = v53560->timer;
  int v53679 = v53570 + ((100 ^ (((~(((v53568 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53568 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v53566 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53566 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v53567 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53567 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v53568 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53568 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v53560->timer = v53679;
  int * v53572 = v53560->cache_vals;
  bool v53680 = !(((~(((v53566 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53566 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v53567 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53567 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v53665;
  if (v53680) {
    int * v53573 = v53560->cache_age;
    int v53682 = ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v53567 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53567 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v53574 = v53573[v53682];
    int v53575 = v53573[v53675];
    int v53683 = v53575 + ((int)((unsigned int)(v53575 - v53574) >> 31));
    v53573[v53675] = v53683;
    int * v53577 = v53560->cache_age;
    int v53578 = v53577[v53676];
    int v53685 = v53578 + ((int)((unsigned int)(v53578 - v53574) >> 31));
    v53577[v53676] = v53685;
    int * v53580 = v53560->cache_age;
    v53580[v53682] = 0;
    v53665 = v53682;
  } else {
    int * v53583 = v53560->cache_age;
    int v53689 = (((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2;
    int v53584 = v53583[v53689];
    int * v53585 = v53560->cache_tags;
    int v53586 = v53585[v53689];
    int v53587 = v53583[v53676];
    int v53588 = v53585[v53676];
    bool v53691 = !(((~(((v53568 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53568 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v53642;
    if (v53691) {
      int * v53589 = v53560->cache_age;
      int v53693 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))) | (-(v53569 ^ ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v53590 = v53589[v53693];
      int v53591 = v53589[v53677];
      int v53694 = v53591 + ((int)((unsigned int)(v53591 - v53590) >> 31));
      v53589[v53677] = v53694;
      int * v53593 = v53560->cache_age;
      int v53594 = v53593[v53678];
      int v53696 = v53594 + ((int)((unsigned int)(v53594 - v53590) >> 31));
      v53593[v53678] = v53696;
      int * v53596 = v53560->cache_age;
      v53596[v53693] = 0;
      v53642 = v53693;
    } else {
      int * v53599 = v53560->cache_age;
      int v53700 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2);
      int v53600 = v53599[v53700];
      int * v53601 = v53560->cache_tags;
      int v53602 = v53601[v53700];
      int v53603 = v53599[v53678];
      int v53604 = v53601[v53678];
      int * v53605 = v53560->cache_dirty;
      int v53703 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v53600 + ((~(((v53602 ^ -1) | (-(v53602 ^ -1))) >> 31)) & 2)) - (v53603 + ((~(((v53604 ^ -1) | (-(v53604 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v53606 = v53605[v53703];
      bool v53704 = !(v53606 == 0);
      if (v53704) {
        int * v53607 = v53560->cache_tags;
        int v53608 = v53607[v53703];
        int * v53609 = v53560->cache_vals;
        int v53707 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v53600 + ((~(((v53602 ^ -1) | (-(v53602 ^ -1))) >> 31)) & 2)) - (v53603 + ((~(((v53604 ^ -1) | (-(v53604 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v53610 = v53609[v53707];
        int v53708 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v53600 + ((~(((v53602 ^ -1) | (-(v53602 ^ -1))) >> 31)) & 2)) - (v53603 + ((~(((v53604 ^ -1) | (-(v53604 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v53611 = v53609[v53708];
        int * v53612 = v53560->mem;
        int v53710 = v53608 * 2;
        v53612[v53710] = v53610;
        int * v53614 = v53560->mem;
        int v53713 = (v53608 * 2) + 1;
        v53614[v53713] = v53611;
        ;
      } else {
        ;
      }
      int * v53619 = v53560->mem;
      int v53718 = ((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) * 2;
      int v53620 = v53619[v53718];
      int v53719 = (((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) * 2) + 1;
      int v53621 = v53619[v53719];
      int * v53622 = v53560->cache_vals;
      int v53721 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v53600 + ((~(((v53602 ^ -1) | (-(v53602 ^ -1))) >> 31)) & 2)) - (v53603 + ((~(((v53604 ^ -1) | (-(v53604 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v53622[v53721] = v53620;
      int * v53624 = v53560->cache_vals;
      int v53724 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v53600 + ((~(((v53602 ^ -1) | (-(v53602 ^ -1))) >> 31)) & 2)) - (v53603 + ((~(((v53604 ^ -1) | (-(v53604 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v53624[v53724] = v53621;
      int * v53626 = v53560->cache_tags;
      int v53727 = (int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1);
      v53626[v53703] = v53727;
      int * v53628 = v53560->cache_dirty;
      v53628[v53703] = 0;
      int * v53630 = v53560->cache_age;
      v53630[v53703] = 1;
      int * v53632 = v53560->cache_age;
      int v53633 = v53632[v53703];
      int v53634 = v53632[v53677];
      int v53733 = v53634 + ((int)((unsigned int)(v53634 - v53633) >> 31));
      v53632[v53677] = v53733;
      int * v53636 = v53560->cache_age;
      int v53637 = v53636[v53678];
      int v53735 = v53637 + ((int)((unsigned int)(v53637 - v53633) >> 31));
      v53636[v53678] = v53735;
      int * v53639 = v53560->cache_age;
      v53639[v53703] = 0;
      v53642 = v53703;
    }
    int * v53643 = v53560->cache_vals;
    int v53738 = v53642 * 2;
    int v53644 = v53643[v53738];
    int v53739 = (v53642 * 2) + 1;
    int v53645 = v53643[v53739];
    int v53740 = (((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v53584 + ((~(((v53586 ^ -1) | (-(v53586 ^ -1))) >> 31)) & 2)) - (v53587 + ((~(((v53588 ^ -1) | (-(v53588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v53643[v53740] = v53644;
    int * v53647 = v53560->cache_vals;
    int v53743 = ((((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v53584 + ((~(((v53586 ^ -1) | (-(v53586 ^ -1))) >> 31)) & 2)) - (v53587 + ((~(((v53588 ^ -1) | (-(v53588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v53647[v53743] = v53645;
    int * v53649 = v53560->cache_tags;
    int v53746 = ((((int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v53584 + ((~(((v53586 ^ -1) | (-(v53586 ^ -1))) >> 31)) & 2)) - (v53587 + ((~(((v53588 ^ -1) | (-(v53588 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v53747 = (int)((unsigned int)((int)((unsigned int)(v53564 + 8) >> 2)) >> 1);
    v53649[v53746] = v53747;
    int * v53651 = v53560->cache_dirty;
    v53651[v53746] = 0;
    int * v53653 = v53560->cache_age;
    v53653[v53746] = 1;
    int * v53655 = v53560->cache_age;
    int v53656 = v53655[v53746];
    int v53657 = v53655[v53675];
    int v53753 = v53657 + ((int)((unsigned int)(v53657 - v53656) >> 31));
    v53655[v53675] = v53753;
    int * v53659 = v53560->cache_age;
    int v53660 = v53659[v53676];
    int v53755 = v53660 + ((int)((unsigned int)(v53660 - v53656) >> 31));
    v53659[v53676] = v53755;
    int * v53662 = v53560->cache_age;
    v53662[v53746] = 0;
    v53665 = v53746;
  }
  int v53758 = (v53665 * 2) + (((int)((unsigned int)(v53564 + 8) >> 2)) & 1);
  int v53666 = v53572[v53758];
  int * v53667 = v53560->regs;
  v53667[9] = v53666;
  struct StateT * v53669 = slot_923(v53560);
  return v53669;
}

struct StateT * slot_616(struct StateT * v27392) {
  int * v27393 = v27392->saved_regs;
  int * v27394 = v27392->regs;
  int v27395 = v27394[12];
  v27393[12] = v27395;
  int v27397 = v27392->timer;
  int v27413 = v27397 + 1;
  v27392->timer = v27413;
  int * v27399 = v27392->regs;
  int v27400 = v27399[5];
  int v27401 = v27399[12];
  bool v27416 = (v27400 ^ -2147483648) < (v27401 ^ -2147483648);
  int v27404;
  if (v27416) {
    v27404 = 1;
  } else {
    v27404 = 0;
  }
  int * v27405 = v27392->regs;
  v27405[12] = v27404;
  struct StateT * v27407 = slot_624(v27392);
  return v27407;
}

struct StateT * slot_984(struct StateT * v49596) {
  int v49597 = v49596->timer;
  int v49605 = v49597 + 1;
  v49596->timer = v49605;
  int * v49599 = v49596->regs;
  int v49600 = v49599[13];
  int v49601 = v49599[17];
  int v49610 = (((((int)((unsigned int)v49600 >> 16)) * ((int)((unsigned int)v49601 >> 16))) + ((int)((unsigned int)((v49600 & 65535) * ((int)((unsigned int)v49601 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v49600 >> 16)) * (v49601 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v49600 & 65535) * (v49601 & 65535)) >> 16)) + (((v49600 & 65535) * ((int)((unsigned int)v49601 >> 16))) & 65535)) + ((((int)((unsigned int)v49600 >> 16)) * (v49601 & 65535)) & 65535)) >> 16));
  v49599[5] = v49610;
  struct StateT * v49603 = slot_1025(v49596);
  return v49603;
}

struct StateT * slot_232(struct StateT * v12532) {
  int v12533 = v12532->timer;
  int v12545 = v12533 + 1;
  v12532->timer = v12545;
  int * v12535 = v12532->regs;
  int v12536 = v12535[29];
  int v12537 = v12535[28];
  bool v12549 = (v12536 ^ -2147483648) < (v12537 ^ -2147483648);
  int v12540;
  if (v12549) {
    v12540 = 1;
  } else {
    v12540 = 0;
  }
  int * v12541 = v12532->regs;
  v12541[7] = v12540;
  struct StateT * v12543 = slot_236(v12532);
  return v12543;
}

struct StateT * slot_466(struct StateT * v24577) {
  int v24578 = v24577->timer;
  int v24586 = v24578 + 1;
  v24577->timer = v24586;
  int * v24580 = v24577->regs;
  int v24581 = v24580[6];
  int v24582 = v24580[13];
  int v24591 = v24581 * v24582;
  v24580[30] = v24591;
  struct StateT * v24584 = slot_416(v24577);
  return v24584;
}

struct StateT * slot_764(struct StateT * v30783) {
  int v30784 = v30783->timer;
  int v30792 = v30784 + 1;
  v30783->timer = v30792;
  int * v30786 = v30783->regs;
  int v30787 = v30786[14];
  int v30788 = v30786[13];
  int v30796 = v30787 + v30788;
  v30786[13] = v30796;
  struct StateT * v30790 = slot_743(v30783);
  return v30790;
}

struct StateT * slot_304(struct StateT * v13881) {
  int * v13882 = v13881->saved_regs;
  int * v13883 = v13881->regs;
  int v13884 = v13883[7];
  v13882[7] = v13884;
  int v13886 = v13881->timer;
  int v13897 = v13886 + 1;
  v13881->timer = v13897;
  int * v13888 = v13881->regs;
  int v13889 = v13888[7];
  int v13899 = (int)((unsigned int)v13889 >> 19);
  v13888[7] = v13899;
  struct StateT * v13891 = slot_325(v13881);
  return v13891;
}

struct StateT * slot_31(struct StateT * v3062) {
  int v3063 = v3062->timer;
  int v3075 = v3063 + 1;
  v3062->timer = v3075;
  int * v3065 = v3062->regs;
  int v3066 = v3065[5];
  int v3067 = v3065[6];
  bool v3079 = (v3066 ^ -2147483648) < (v3067 ^ -2147483648);
  int v3070;
  if (v3079) {
    v3070 = 1;
  } else {
    v3070 = 0;
  }
  int * v3071 = v3062->regs;
  v3071[5] = v3070;
  struct StateT * v3073 = slot_32(v3062);
  return v3073;
}

struct StateT * slot_730(struct StateT * v29516) {
  int v29517 = v29516->timer;
  int v29525 = v29517 + 1;
  v29516->timer = v29525;
  int * v29519 = v29516->regs;
  int v29520 = v29519[12];
  int v29521 = v29519[5];
  int v29529 = v29520 | v29521;
  v29519[12] = v29529;
  struct StateT * v29523 = slot_738(v29516);
  return v29523;
}

struct StateT * slot_585(struct StateT * v26796) {
  int v26797 = v26796->timer;
  int v26809 = v26797 + 1;
  v26796->timer = v26809;
  int * v26799 = v26796->regs;
  int v26800 = v26799[6];
  int v26801 = v26799[30];
  bool v26813 = (v26800 ^ -2147483648) < (v26801 ^ -2147483648);
  int v26804;
  if (v26813) {
    v26804 = 1;
  } else {
    v26804 = 0;
  }
  int * v26805 = v26796->regs;
  v26805[12] = v26804;
  struct StateT * v26807 = slot_565(v26796);
  return v26807;
}

struct StateT * slot_241(struct StateT * v12698) {
  int v12699 = v12698->timer;
  int v12707 = v12699 + 1;
  v12698->timer = v12707;
  int * v12701 = v12698->regs;
  int v12702 = v12701[29];
  int v12703 = v12701[13];
  int v12712 = v12702 * v12703;
  v12701[9] = v12712;
  struct StateT * v12705 = slot_231(v12698);
  return v12705;
}

struct StateT * slot_611(struct StateT * v27264) {
  int v27265 = v27264->timer;
  int v27273 = v27265 + 1;
  v27264->timer = v27273;
  int * v27267 = v27264->regs;
  int v27268 = v27267[13];
  int v27269 = v27267[7];
  int v27277 = v27268 + v27269;
  v27267[13] = v27277;
  struct StateT * v27271 = slot_591(v27264);
  return v27271;
}

struct StateT * slot_160(struct StateT * v8027) {
  int v8028 = v8027->timer;
  int v8035 = v8028 + 1;
  v8027->timer = v8035;
  int * v8030 = v8027->regs;
  int v8031 = v8030[7];
  int v8038 = (int)((unsigned int)v8031 >> 19);
  v8030[7] = v8038;
  struct StateT * v8033 = slot_177(v8027);
  return v8033;
}

struct StateT * slot_745(struct StateT * v29819) {
  int v29820 = v29819->timer;
  int v29827 = v29820 + 1;
  v29819->timer = v29827;
  int * v29822 = v29819->regs;
  int v29823 = v29822[5];
  int v29830 = (int)((unsigned int)v29823 >> 19);
  v29822[5] = v29830;
  struct StateT * v29825 = slot_725(v29819);
  return v29825;
}

struct StateT * slot_150(struct StateT * v7189) {
  int * v7190 = v7189->saved_regs;
  int * v7191 = v7189->regs;
  int v7192 = v7191[5];
  v7190[5] = v7192;
  int v7194 = v7189->timer;
  int v7210 = v7194 + 1;
  v7189->timer = v7210;
  int * v7196 = v7189->regs;
  int v7197 = v7196[28];
  int v7198 = v7196[5];
  bool v7213 = (v7197 ^ -2147483648) < (v7198 ^ -2147483648);
  int v7201;
  if (v7213) {
    v7201 = 1;
  } else {
    v7201 = 0;
  }
  int * v7202 = v7189->regs;
  v7202[5] = v7201;
  struct StateT * v7204 = slot_152(v7189);
  return v7204;
}

struct StateT * slot_391(struct StateT * v21254) {
  int v21255 = v21254->timer;
  int v21263 = v21255 + 1;
  v21254->timer = v21263;
  int * v21257 = v21254->regs;
  int v21258 = v21257[7];
  int v21259 = v21257[28];
  int v21267 = v21258 | v21259;
  v21257[7] = v21267;
  struct StateT * v21261 = slot_426(v21254);
  return v21261;
}

struct StateT * slot_74(struct StateT * v4187) {
  int v4188 = v4187->timer;
  int v4358 = v4188 + 1;
  v4187->timer = v4358;
  int * v4190 = v4187->regs;
  int v4191 = v4190[10];
  int v4192 = v4190[29];
  int * v4193 = v4187->cache_tags;
  int v4363 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2;
  int v4194 = v4193[v4363];
  int v4364 = ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4195 = v4193[v4364];
  int v4365 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2);
  int v4196 = v4193[v4365];
  int v4366 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4197 = v4193[v4366];
  int v4198 = v4187->timer;
  int v4367 = v4198 + ((100 ^ (((~(((v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4187->timer = v4367;
  bool v4368 = !(((~(((v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4194 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4292;
  if (v4368) {
    int * v4200 = v4187->cache_age;
    int v4370 = ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4195 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4201 = v4200[v4370];
    int v4202 = v4200[v4363];
    int v4371 = v4202 + ((int)((unsigned int)(v4202 - v4201) >> 31));
    v4200[v4363] = v4371;
    int * v4204 = v4187->cache_age;
    int v4205 = v4204[v4364];
    int v4373 = v4205 + ((int)((unsigned int)(v4205 - v4201) >> 31));
    v4204[v4364] = v4373;
    int * v4207 = v4187->cache_age;
    v4207[v4370] = 0;
    v4292 = v4370;
  } else {
    int * v4210 = v4187->cache_age;
    int v4377 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2;
    int v4211 = v4210[v4377];
    int * v4212 = v4187->cache_tags;
    int v4213 = v4212[v4377];
    int v4214 = v4210[v4364];
    int v4215 = v4212[v4364];
    bool v4379 = !(((~(((v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4196 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v4269;
    if (v4379) {
      int * v4216 = v4187->cache_age;
      int v4381 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4197 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v4217 = v4216[v4381];
      int v4218 = v4216[v4365];
      int v4382 = v4218 + ((int)((unsigned int)(v4218 - v4217) >> 31));
      v4216[v4365] = v4382;
      int * v4220 = v4187->cache_age;
      int v4221 = v4220[v4366];
      int v4384 = v4221 + ((int)((unsigned int)(v4221 - v4217) >> 31));
      v4220[v4366] = v4384;
      int * v4223 = v4187->cache_age;
      v4223[v4381] = 0;
      v4269 = v4381;
    } else {
      int * v4226 = v4187->cache_age;
      int v4388 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2);
      int v4227 = v4226[v4388];
      int * v4228 = v4187->cache_tags;
      int v4229 = v4228[v4388];
      int v4230 = v4226[v4366];
      int v4231 = v4228[v4366];
      int * v4232 = v4187->cache_dirty;
      int v4391 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4233 = v4232[v4391];
      bool v4392 = !(v4233 == 0);
      if (v4392) {
        int * v4234 = v4187->cache_tags;
        int v4235 = v4234[v4391];
        int * v4236 = v4187->cache_vals;
        int v4395 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4237 = v4236[v4395];
        int v4396 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4238 = v4236[v4396];
        int * v4239 = v4187->mem;
        int v4398 = v4235 * 2;
        v4239[v4398] = v4237;
        int * v4241 = v4187->mem;
        int v4401 = (v4235 * 2) + 1;
        v4241[v4401] = v4238;
        ;
      } else {
        ;
      }
      int * v4246 = v4187->mem;
      int v4406 = ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2;
      int v4247 = v4246[v4406];
      int v4407 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2) + 1;
      int v4248 = v4246[v4407];
      int * v4249 = v4187->cache_vals;
      int v4409 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4249[v4409] = v4247;
      int * v4251 = v4187->cache_vals;
      int v4412 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4227 + ((~(((v4229 ^ -1) | (-(v4229 ^ -1))) >> 31)) & 2)) - (v4230 + ((~(((v4231 ^ -1) | (-(v4231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4251[v4412] = v4248;
      int * v4253 = v4187->cache_tags;
      int v4415 = (int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1);
      v4253[v4391] = v4415;
      int * v4255 = v4187->cache_dirty;
      v4255[v4391] = 0;
      int * v4257 = v4187->cache_age;
      v4257[v4391] = 1;
      int * v4259 = v4187->cache_age;
      int v4260 = v4259[v4391];
      int v4261 = v4259[v4365];
      int v4421 = v4261 + ((int)((unsigned int)(v4261 - v4260) >> 31));
      v4259[v4365] = v4421;
      int * v4263 = v4187->cache_age;
      int v4264 = v4263[v4366];
      int v4423 = v4264 + ((int)((unsigned int)(v4264 - v4260) >> 31));
      v4263[v4366] = v4423;
      int * v4266 = v4187->cache_age;
      v4266[v4391] = 0;
      v4269 = v4391;
    }
    int * v4270 = v4187->cache_vals;
    int v4426 = v4269 * 2;
    int v4271 = v4270[v4426];
    int v4427 = (v4269 * 2) + 1;
    int v4272 = v4270[v4427];
    int v4428 = (((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4211 + ((~(((v4213 ^ -1) | (-(v4213 ^ -1))) >> 31)) & 2)) - (v4214 + ((~(((v4215 ^ -1) | (-(v4215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4270[v4428] = v4271;
    int * v4274 = v4187->cache_vals;
    int v4431 = ((((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4211 + ((~(((v4213 ^ -1) | (-(v4213 ^ -1))) >> 31)) & 2)) - (v4214 + ((~(((v4215 ^ -1) | (-(v4215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4274[v4431] = v4272;
    int * v4276 = v4187->cache_tags;
    int v4434 = ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4211 + ((~(((v4213 ^ -1) | (-(v4213 ^ -1))) >> 31)) & 2)) - (v4214 + ((~(((v4215 ^ -1) | (-(v4215 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4435 = (int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1);
    v4276[v4434] = v4435;
    int * v4278 = v4187->cache_dirty;
    v4278[v4434] = 0;
    int * v4280 = v4187->cache_age;
    v4280[v4434] = 1;
    int * v4282 = v4187->cache_age;
    int v4283 = v4282[v4434];
    int v4284 = v4282[v4363];
    int v4441 = v4284 + ((int)((unsigned int)(v4284 - v4283) >> 31));
    v4282[v4363] = v4441;
    int * v4286 = v4187->cache_age;
    int v4287 = v4286[v4364];
    int v4443 = v4287 + ((int)((unsigned int)(v4287 - v4283) >> 31));
    v4286[v4364] = v4443;
    int * v4289 = v4187->cache_age;
    v4289[v4434] = 0;
    v4292 = v4434;
  }
  int * v4293 = v4187->cache_vals;
  int v4446 = (v4292 * 2) + (((int)((unsigned int)(v4191 + 12) >> 2)) & 1);
  v4293[v4446] = v4192;
  int * v4295 = v4187->cache_tags;
  int v4296 = v4295[v4365];
  int v4297 = v4295[v4366];
  bool v4449 = !(((~(((v4296 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4296 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4351;
  if (v4449) {
    int * v4298 = v4187->cache_age;
    int v4451 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))) | (-(v4297 ^ ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4299 = v4298[v4451];
    int v4300 = v4298[v4365];
    int v4452 = v4300 + ((int)((unsigned int)(v4300 - v4299) >> 31));
    v4298[v4365] = v4452;
    int * v4302 = v4187->cache_age;
    int v4303 = v4302[v4366];
    int v4454 = v4303 + ((int)((unsigned int)(v4303 - v4299) >> 31));
    v4302[v4366] = v4454;
    int * v4305 = v4187->cache_age;
    v4305[v4451] = 0;
    v4351 = v4451;
  } else {
    int * v4308 = v4187->cache_age;
    int v4458 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2);
    int v4309 = v4308[v4458];
    int * v4310 = v4187->cache_tags;
    int v4311 = v4310[v4458];
    int v4312 = v4308[v4366];
    int v4313 = v4310[v4366];
    int * v4314 = v4187->cache_dirty;
    int v4461 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4315 = v4314[v4461];
    bool v4462 = !(v4315 == 0);
    if (v4462) {
      int * v4316 = v4187->cache_tags;
      int v4317 = v4316[v4461];
      int * v4318 = v4187->cache_vals;
      int v4465 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4319 = v4318[v4465];
      int v4466 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4320 = v4318[v4466];
      int * v4321 = v4187->mem;
      int v4468 = v4317 * 2;
      v4321[v4468] = v4319;
      int * v4323 = v4187->mem;
      int v4471 = (v4317 * 2) + 1;
      v4323[v4471] = v4320;
      ;
    } else {
      ;
    }
    int * v4328 = v4187->mem;
    int v4476 = ((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2;
    int v4329 = v4328[v4476];
    int v4477 = (((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) * 2) + 1;
    int v4330 = v4328[v4477];
    int * v4331 = v4187->cache_vals;
    int v4479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4331[v4479] = v4329;
    int * v4333 = v4187->cache_vals;
    int v4482 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4309 + ((~(((v4311 ^ -1) | (-(v4311 ^ -1))) >> 31)) & 2)) - (v4312 + ((~(((v4313 ^ -1) | (-(v4313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4333[v4482] = v4330;
    int * v4335 = v4187->cache_tags;
    int v4485 = (int)((unsigned int)((int)((unsigned int)(v4191 + 12) >> 2)) >> 1);
    v4335[v4461] = v4485;
    int * v4337 = v4187->cache_dirty;
    v4337[v4461] = 0;
    int * v4339 = v4187->cache_age;
    v4339[v4461] = 1;
    int * v4341 = v4187->cache_age;
    int v4342 = v4341[v4461];
    int v4343 = v4341[v4365];
    int v4491 = v4343 + ((int)((unsigned int)(v4343 - v4342) >> 31));
    v4341[v4365] = v4491;
    int * v4345 = v4187->cache_age;
    int v4346 = v4345[v4366];
    int v4493 = v4346 + ((int)((unsigned int)(v4346 - v4342) >> 31));
    v4345[v4366] = v4493;
    int * v4348 = v4187->cache_age;
    v4348[v4461] = 0;
    v4351 = v4461;
  }
  int * v4352 = v4187->cache_vals;
  int v4496 = (v4351 * 2) + (((int)((unsigned int)(v4191 + 12) >> 2)) & 1);
  v4352[v4496] = v4192;
  int * v4354 = v4187->cache_dirty;
  v4354[v4351] = 1;
  struct StateT * v4356 = slot_83(v4187);
  return v4356;
}

struct StateT * slot_372(struct StateT * v19528) {
  int v19529 = v19528->timer;
  int v19639 = v19529 + 1;
  v19528->timer = v19639;
  int * v19531 = v19528->regs;
  int v19532 = v19531[11];
  int * v19533 = v19528->cache_tags;
  int v19643 = (((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2;
  int v19534 = v19533[v19643];
  int v19644 = ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19535 = v19533[v19644];
  int v19645 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2);
  int v19536 = v19533[v19645];
  int v19646 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19537 = v19533[v19646];
  int v19538 = v19528->timer;
  int v19647 = v19538 + ((100 ^ (((~(((v19536 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19536 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19534 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19534 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19535 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19535 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19536 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19536 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19528->timer = v19647;
  int * v19540 = v19528->cache_vals;
  bool v19648 = !(((~(((v19534 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19534 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19535 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19535 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v19633;
  if (v19648) {
    int * v19541 = v19528->cache_age;
    int v19650 = ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v19535 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19535 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v19542 = v19541[v19650];
    int v19543 = v19541[v19643];
    int v19651 = v19543 + ((int)((unsigned int)(v19543 - v19542) >> 31));
    v19541[v19643] = v19651;
    int * v19545 = v19528->cache_age;
    int v19546 = v19545[v19644];
    int v19653 = v19546 + ((int)((unsigned int)(v19546 - v19542) >> 31));
    v19545[v19644] = v19653;
    int * v19548 = v19528->cache_age;
    v19548[v19650] = 0;
    v19633 = v19650;
  } else {
    int * v19551 = v19528->cache_age;
    int v19657 = (((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2;
    int v19552 = v19551[v19657];
    int * v19553 = v19528->cache_tags;
    int v19554 = v19553[v19657];
    int v19555 = v19551[v19644];
    int v19556 = v19553[v19644];
    bool v19659 = !(((~(((v19536 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19536 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v19610;
    if (v19659) {
      int * v19557 = v19528->cache_age;
      int v19661 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))) | (-(v19537 ^ ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v19558 = v19557[v19661];
      int v19559 = v19557[v19645];
      int v19662 = v19559 + ((int)((unsigned int)(v19559 - v19558) >> 31));
      v19557[v19645] = v19662;
      int * v19561 = v19528->cache_age;
      int v19562 = v19561[v19646];
      int v19664 = v19562 + ((int)((unsigned int)(v19562 - v19558) >> 31));
      v19561[v19646] = v19664;
      int * v19564 = v19528->cache_age;
      v19564[v19661] = 0;
      v19610 = v19661;
    } else {
      int * v19567 = v19528->cache_age;
      int v19668 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2);
      int v19568 = v19567[v19668];
      int * v19569 = v19528->cache_tags;
      int v19570 = v19569[v19668];
      int v19571 = v19567[v19646];
      int v19572 = v19569[v19646];
      int * v19573 = v19528->cache_dirty;
      int v19671 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19568 + ((~(((v19570 ^ -1) | (-(v19570 ^ -1))) >> 31)) & 2)) - (v19571 + ((~(((v19572 ^ -1) | (-(v19572 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19574 = v19573[v19671];
      bool v19672 = !(v19574 == 0);
      if (v19672) {
        int * v19575 = v19528->cache_tags;
        int v19576 = v19575[v19671];
        int * v19577 = v19528->cache_vals;
        int v19675 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19568 + ((~(((v19570 ^ -1) | (-(v19570 ^ -1))) >> 31)) & 2)) - (v19571 + ((~(((v19572 ^ -1) | (-(v19572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19578 = v19577[v19675];
        int v19676 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19568 + ((~(((v19570 ^ -1) | (-(v19570 ^ -1))) >> 31)) & 2)) - (v19571 + ((~(((v19572 ^ -1) | (-(v19572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19579 = v19577[v19676];
        int * v19580 = v19528->mem;
        int v19678 = v19576 * 2;
        v19580[v19678] = v19578;
        int * v19582 = v19528->mem;
        int v19681 = (v19576 * 2) + 1;
        v19582[v19681] = v19579;
        ;
      } else {
        ;
      }
      int * v19587 = v19528->mem;
      int v19686 = ((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) * 2;
      int v19588 = v19587[v19686];
      int v19687 = (((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) * 2) + 1;
      int v19589 = v19587[v19687];
      int * v19590 = v19528->cache_vals;
      int v19689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19568 + ((~(((v19570 ^ -1) | (-(v19570 ^ -1))) >> 31)) & 2)) - (v19571 + ((~(((v19572 ^ -1) | (-(v19572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19590[v19689] = v19588;
      int * v19592 = v19528->cache_vals;
      int v19692 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v19568 + ((~(((v19570 ^ -1) | (-(v19570 ^ -1))) >> 31)) & 2)) - (v19571 + ((~(((v19572 ^ -1) | (-(v19572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19592[v19692] = v19589;
      int * v19594 = v19528->cache_tags;
      int v19695 = (int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1);
      v19594[v19671] = v19695;
      int * v19596 = v19528->cache_dirty;
      v19596[v19671] = 0;
      int * v19598 = v19528->cache_age;
      v19598[v19671] = 1;
      int * v19600 = v19528->cache_age;
      int v19601 = v19600[v19671];
      int v19602 = v19600[v19645];
      int v19701 = v19602 + ((int)((unsigned int)(v19602 - v19601) >> 31));
      v19600[v19645] = v19701;
      int * v19604 = v19528->cache_age;
      int v19605 = v19604[v19646];
      int v19703 = v19605 + ((int)((unsigned int)(v19605 - v19601) >> 31));
      v19604[v19646] = v19703;
      int * v19607 = v19528->cache_age;
      v19607[v19671] = 0;
      v19610 = v19671;
    }
    int * v19611 = v19528->cache_vals;
    int v19706 = v19610 * 2;
    int v19612 = v19611[v19706];
    int v19707 = (v19610 * 2) + 1;
    int v19613 = v19611[v19707];
    int v19708 = (((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v19552 + ((~(((v19554 ^ -1) | (-(v19554 ^ -1))) >> 31)) & 2)) - (v19555 + ((~(((v19556 ^ -1) | (-(v19556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19611[v19708] = v19612;
    int * v19615 = v19528->cache_vals;
    int v19711 = ((((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v19552 + ((~(((v19554 ^ -1) | (-(v19554 ^ -1))) >> 31)) & 2)) - (v19555 + ((~(((v19556 ^ -1) | (-(v19556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19615[v19711] = v19613;
    int * v19617 = v19528->cache_tags;
    int v19714 = ((((int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v19552 + ((~(((v19554 ^ -1) | (-(v19554 ^ -1))) >> 31)) & 2)) - (v19555 + ((~(((v19556 ^ -1) | (-(v19556 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19715 = (int)((unsigned int)((int)((unsigned int)(v19532 + 32) >> 2)) >> 1);
    v19617[v19714] = v19715;
    int * v19619 = v19528->cache_dirty;
    v19619[v19714] = 0;
    int * v19621 = v19528->cache_age;
    v19621[v19714] = 1;
    int * v19623 = v19528->cache_age;
    int v19624 = v19623[v19714];
    int v19625 = v19623[v19643];
    int v19721 = v19625 + ((int)((unsigned int)(v19625 - v19624) >> 31));
    v19623[v19643] = v19721;
    int * v19627 = v19528->cache_age;
    int v19628 = v19627[v19644];
    int v19723 = v19628 + ((int)((unsigned int)(v19628 - v19624) >> 31));
    v19627[v19644] = v19723;
    int * v19630 = v19528->cache_age;
    v19630[v19714] = 0;
    v19633 = v19714;
  }
  int v19726 = (v19633 * 2) + (((int)((unsigned int)(v19532 + 32) >> 2)) & 1);
  int v19634 = v19540[v19726];
  int * v19635 = v19528->regs;
  v19635[6] = v19634;
  struct StateT * v19637 = slot_383(v19528);
  return v19637;
}

struct StateT * slot_325(struct StateT * v14954) {
  int * v14955 = v14954->saved_regs;
  int * v14956 = v14954->regs;
  int v14957 = v14956[5];
  v14955[5] = v14957;
  int v14959 = v14954->timer;
  int v14975 = v14959 + 1;
  v14954->timer = v14975;
  int * v14961 = v14954->regs;
  int v14962 = v14961[28];
  int v14963 = v14961[5];
  bool v14978 = (v14962 ^ -2147483648) < (v14963 ^ -2147483648);
  int v14966;
  if (v14978) {
    v14966 = 1;
  } else {
    v14966 = 0;
  }
  int * v14967 = v14954->regs;
  v14967[5] = v14966;
  struct StateT * v14969 = slot_354(v14954);
  return v14969;
}

struct StateT * slot_895(struct StateT * v44837) {
  int v44838 = v44837->timer;
  int v44845 = v44838 + 1;
  v44837->timer = v44845;
  int * v44840 = v44837->regs;
  int v44841 = v44840[2];
  int v44848 = v44841 + 16;
  v44840[2] = v44848;
  struct StateT * v44843 = slot_1090(v44837);
  return v44843;
}

struct StateT * slot_28(struct StateT * v2637) {
  int v2638 = v2637->timer;
  int v2748 = v2638 + 1;
  v2637->timer = v2748;
  int * v2640 = v2637->regs;
  int v2641 = v2640[11];
  int * v2642 = v2637->cache_tags;
  int v2752 = (((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2643 = v2642[v2752];
  int v2753 = ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2644 = v2642[v2753];
  int v2754 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2645 = v2642[v2754];
  int v2755 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2646 = v2642[v2755];
  int v2647 = v2637->timer;
  int v2756 = v2647 + ((100 ^ (((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2637->timer = v2756;
  int * v2649 = v2637->cache_vals;
  bool v2757 = !(((~(((v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2643 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2742;
  if (v2757) {
    int * v2650 = v2637->cache_age;
    int v2759 = ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2644 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2651 = v2650[v2759];
    int v2652 = v2650[v2752];
    int v2760 = v2652 + ((int)((unsigned int)(v2652 - v2651) >> 31));
    v2650[v2752] = v2760;
    int * v2654 = v2637->cache_age;
    int v2655 = v2654[v2753];
    int v2762 = v2655 + ((int)((unsigned int)(v2655 - v2651) >> 31));
    v2654[v2753] = v2762;
    int * v2657 = v2637->cache_age;
    v2657[v2759] = 0;
    v2742 = v2759;
  } else {
    int * v2660 = v2637->cache_age;
    int v2766 = (((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2661 = v2660[v2766];
    int * v2662 = v2637->cache_tags;
    int v2663 = v2662[v2766];
    int v2664 = v2660[v2753];
    int v2665 = v2662[v2753];
    bool v2768 = !(((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2719;
    if (v2768) {
      int * v2666 = v2637->cache_age;
      int v2770 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2667 = v2666[v2770];
      int v2668 = v2666[v2754];
      int v2771 = v2668 + ((int)((unsigned int)(v2668 - v2667) >> 31));
      v2666[v2754] = v2771;
      int * v2670 = v2637->cache_age;
      int v2671 = v2670[v2755];
      int v2773 = v2671 + ((int)((unsigned int)(v2671 - v2667) >> 31));
      v2670[v2755] = v2773;
      int * v2673 = v2637->cache_age;
      v2673[v2770] = 0;
      v2719 = v2770;
    } else {
      int * v2676 = v2637->cache_age;
      int v2777 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2677 = v2676[v2777];
      int * v2678 = v2637->cache_tags;
      int v2679 = v2678[v2777];
      int v2680 = v2676[v2755];
      int v2681 = v2678[v2755];
      int * v2682 = v2637->cache_dirty;
      int v2780 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2683 = v2682[v2780];
      bool v2781 = !(v2683 == 0);
      if (v2781) {
        int * v2684 = v2637->cache_tags;
        int v2685 = v2684[v2780];
        int * v2686 = v2637->cache_vals;
        int v2784 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2687 = v2686[v2784];
        int v2785 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2688 = v2686[v2785];
        int * v2689 = v2637->mem;
        int v2787 = v2685 * 2;
        v2689[v2787] = v2687;
        int * v2691 = v2637->mem;
        int v2790 = (v2685 * 2) + 1;
        v2691[v2790] = v2688;
        ;
      } else {
        ;
      }
      int * v2696 = v2637->mem;
      int v2795 = ((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) * 2;
      int v2697 = v2696[v2795];
      int v2796 = (((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2698 = v2696[v2796];
      int * v2699 = v2637->cache_vals;
      int v2798 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2699[v2798] = v2697;
      int * v2701 = v2637->cache_vals;
      int v2801 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2677 + ((~(((v2679 ^ -1) | (-(v2679 ^ -1))) >> 31)) & 2)) - (v2680 + ((~(((v2681 ^ -1) | (-(v2681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2701[v2801] = v2698;
      int * v2703 = v2637->cache_tags;
      int v2804 = (int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1);
      v2703[v2780] = v2804;
      int * v2705 = v2637->cache_dirty;
      v2705[v2780] = 0;
      int * v2707 = v2637->cache_age;
      v2707[v2780] = 1;
      int * v2709 = v2637->cache_age;
      int v2710 = v2709[v2780];
      int v2711 = v2709[v2754];
      int v2810 = v2711 + ((int)((unsigned int)(v2711 - v2710) >> 31));
      v2709[v2754] = v2810;
      int * v2713 = v2637->cache_age;
      int v2714 = v2713[v2755];
      int v2812 = v2714 + ((int)((unsigned int)(v2714 - v2710) >> 31));
      v2713[v2755] = v2812;
      int * v2716 = v2637->cache_age;
      v2716[v2780] = 0;
      v2719 = v2780;
    }
    int * v2720 = v2637->cache_vals;
    int v2815 = v2719 * 2;
    int v2721 = v2720[v2815];
    int v2816 = (v2719 * 2) + 1;
    int v2722 = v2720[v2816];
    int v2817 = (((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2661 + ((~(((v2663 ^ -1) | (-(v2663 ^ -1))) >> 31)) & 2)) - (v2664 + ((~(((v2665 ^ -1) | (-(v2665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2720[v2817] = v2721;
    int * v2724 = v2637->cache_vals;
    int v2820 = ((((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2661 + ((~(((v2663 ^ -1) | (-(v2663 ^ -1))) >> 31)) & 2)) - (v2664 + ((~(((v2665 ^ -1) | (-(v2665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2724[v2820] = v2722;
    int * v2726 = v2637->cache_tags;
    int v2823 = ((((int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2661 + ((~(((v2663 ^ -1) | (-(v2663 ^ -1))) >> 31)) & 2)) - (v2664 + ((~(((v2665 ^ -1) | (-(v2665 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2824 = (int)((unsigned int)((int)((unsigned int)(v2641 + 8) >> 2)) >> 1);
    v2726[v2823] = v2824;
    int * v2728 = v2637->cache_dirty;
    v2728[v2823] = 0;
    int * v2730 = v2637->cache_age;
    v2730[v2823] = 1;
    int * v2732 = v2637->cache_age;
    int v2733 = v2732[v2823];
    int v2734 = v2732[v2752];
    int v2830 = v2734 + ((int)((unsigned int)(v2734 - v2733) >> 31));
    v2732[v2752] = v2830;
    int * v2736 = v2637->cache_age;
    int v2737 = v2736[v2753];
    int v2832 = v2737 + ((int)((unsigned int)(v2737 - v2733) >> 31));
    v2736[v2753] = v2832;
    int * v2739 = v2637->cache_age;
    v2739[v2823] = 0;
    v2742 = v2823;
  }
  int v2835 = (v2742 * 2) + (((int)((unsigned int)(v2641 + 8) >> 2)) & 1);
  int v2743 = v2649[v2835];
  int * v2744 = v2637->regs;
  v2744[7] = v2743;
  struct StateT * v2746 = slot_29(v2637);
  return v2746;
}

struct StateT * slot_517(struct StateT * v25489) {
  int v25490 = v25489->timer;
  int v25498 = v25490 + 1;
  v25489->timer = v25498;
  int * v25492 = v25489->regs;
  int v25493 = v25492[12];
  int v25494 = v25492[7];
  int v25503 = v25493 + v25494;
  v25492[11] = v25503;
  struct StateT * v25496 = slot_523(v25489);
  return v25496;
}

struct StateT * slot_1022(struct StateT * v51693) {
  int v51694 = v51693->timer;
  int v51864 = v51694 + 1;
  v51693->timer = v51864;
  int * v51696 = v51693->regs;
  int v51697 = v51696[10];
  int v51698 = v51696[13];
  int * v51699 = v51693->cache_tags;
  int v51869 = (((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2;
  int v51700 = v51699[v51869];
  int v51870 = ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2) + 1;
  int v51701 = v51699[v51870];
  int v51871 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2);
  int v51702 = v51699[v51871];
  int v51872 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v51703 = v51699[v51872];
  int v51704 = v51693->timer;
  int v51873 = v51704 + ((100 ^ (((~(((v51702 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51702 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) | (~(((v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v51700 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51700 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) | (~(((v51701 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51701 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v51702 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51702 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) | (~(((v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31))) & 104)))));
  v51693->timer = v51873;
  bool v51874 = !(((~(((v51700 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51700 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) | (~(((v51701 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51701 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31))) == 0);
  int v51798;
  if (v51874) {
    int * v51706 = v51693->cache_age;
    int v51876 = ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2) + ((~(((v51701 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51701 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) & 1);
    int v51707 = v51706[v51876];
    int v51708 = v51706[v51869];
    int v51877 = v51708 + ((int)((unsigned int)(v51708 - v51707) >> 31));
    v51706[v51869] = v51877;
    int * v51710 = v51693->cache_age;
    int v51711 = v51710[v51870];
    int v51879 = v51711 + ((int)((unsigned int)(v51711 - v51707) >> 31));
    v51710[v51870] = v51879;
    int * v51713 = v51693->cache_age;
    v51713[v51876] = 0;
    v51798 = v51876;
  } else {
    int * v51716 = v51693->cache_age;
    int v51883 = (((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2;
    int v51717 = v51716[v51883];
    int * v51718 = v51693->cache_tags;
    int v51719 = v51718[v51883];
    int v51720 = v51716[v51870];
    int v51721 = v51718[v51870];
    bool v51885 = !(((~(((v51702 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51702 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) | (~(((v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31))) == 0);
    int v51775;
    if (v51885) {
      int * v51722 = v51693->cache_age;
      int v51887 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((~(((v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51703 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) & 1);
      int v51723 = v51722[v51887];
      int v51724 = v51722[v51871];
      int v51888 = v51724 + ((int)((unsigned int)(v51724 - v51723) >> 31));
      v51722[v51871] = v51888;
      int * v51726 = v51693->cache_age;
      int v51727 = v51726[v51872];
      int v51890 = v51727 + ((int)((unsigned int)(v51727 - v51723) >> 31));
      v51726[v51872] = v51890;
      int * v51729 = v51693->cache_age;
      v51729[v51887] = 0;
      v51775 = v51887;
    } else {
      int * v51732 = v51693->cache_age;
      int v51894 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2);
      int v51733 = v51732[v51894];
      int * v51734 = v51693->cache_tags;
      int v51735 = v51734[v51894];
      int v51736 = v51732[v51872];
      int v51737 = v51734[v51872];
      int * v51738 = v51693->cache_dirty;
      int v51897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51733 + ((~(((v51735 ^ -1) | (-(v51735 ^ -1))) >> 31)) & 2)) - (v51736 + ((~(((v51737 ^ -1) | (-(v51737 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v51739 = v51738[v51897];
      bool v51898 = !(v51739 == 0);
      if (v51898) {
        int * v51740 = v51693->cache_tags;
        int v51741 = v51740[v51897];
        int * v51742 = v51693->cache_vals;
        int v51901 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51733 + ((~(((v51735 ^ -1) | (-(v51735 ^ -1))) >> 31)) & 2)) - (v51736 + ((~(((v51737 ^ -1) | (-(v51737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v51743 = v51742[v51901];
        int v51902 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51733 + ((~(((v51735 ^ -1) | (-(v51735 ^ -1))) >> 31)) & 2)) - (v51736 + ((~(((v51737 ^ -1) | (-(v51737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v51744 = v51742[v51902];
        int * v51745 = v51693->mem;
        int v51904 = v51741 * 2;
        v51745[v51904] = v51743;
        int * v51747 = v51693->mem;
        int v51907 = (v51741 * 2) + 1;
        v51747[v51907] = v51744;
        ;
      } else {
        ;
      }
      int * v51752 = v51693->mem;
      int v51912 = ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) * 2;
      int v51753 = v51752[v51912];
      int v51913 = (((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) * 2) + 1;
      int v51754 = v51752[v51913];
      int * v51755 = v51693->cache_vals;
      int v51915 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51733 + ((~(((v51735 ^ -1) | (-(v51735 ^ -1))) >> 31)) & 2)) - (v51736 + ((~(((v51737 ^ -1) | (-(v51737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v51755[v51915] = v51753;
      int * v51757 = v51693->cache_vals;
      int v51918 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51733 + ((~(((v51735 ^ -1) | (-(v51735 ^ -1))) >> 31)) & 2)) - (v51736 + ((~(((v51737 ^ -1) | (-(v51737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v51757[v51918] = v51754;
      int * v51759 = v51693->cache_tags;
      int v51921 = (int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1);
      v51759[v51897] = v51921;
      int * v51761 = v51693->cache_dirty;
      v51761[v51897] = 0;
      int * v51763 = v51693->cache_age;
      v51763[v51897] = 1;
      int * v51765 = v51693->cache_age;
      int v51766 = v51765[v51897];
      int v51767 = v51765[v51871];
      int v51927 = v51767 + ((int)((unsigned int)(v51767 - v51766) >> 31));
      v51765[v51871] = v51927;
      int * v51769 = v51693->cache_age;
      int v51770 = v51769[v51872];
      int v51929 = v51770 + ((int)((unsigned int)(v51770 - v51766) >> 31));
      v51769[v51872] = v51929;
      int * v51772 = v51693->cache_age;
      v51772[v51897] = 0;
      v51775 = v51897;
    }
    int * v51776 = v51693->cache_vals;
    int v51932 = v51775 * 2;
    int v51777 = v51776[v51932];
    int v51933 = (v51775 * 2) + 1;
    int v51778 = v51776[v51933];
    int v51934 = (((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2) + ((((v51717 + ((~(((v51719 ^ -1) | (-(v51719 ^ -1))) >> 31)) & 2)) - (v51720 + ((~(((v51721 ^ -1) | (-(v51721 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v51776[v51934] = v51777;
    int * v51780 = v51693->cache_vals;
    int v51937 = ((((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2) + ((((v51717 + ((~(((v51719 ^ -1) | (-(v51719 ^ -1))) >> 31)) & 2)) - (v51720 + ((~(((v51721 ^ -1) | (-(v51721 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v51780[v51937] = v51778;
    int * v51782 = v51693->cache_tags;
    int v51940 = ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 1) * 2) + ((((v51717 + ((~(((v51719 ^ -1) | (-(v51719 ^ -1))) >> 31)) & 2)) - (v51720 + ((~(((v51721 ^ -1) | (-(v51721 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v51941 = (int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1);
    v51782[v51940] = v51941;
    int * v51784 = v51693->cache_dirty;
    v51784[v51940] = 0;
    int * v51786 = v51693->cache_age;
    v51786[v51940] = 1;
    int * v51788 = v51693->cache_age;
    int v51789 = v51788[v51940];
    int v51790 = v51788[v51869];
    int v51947 = v51790 + ((int)((unsigned int)(v51790 - v51789) >> 31));
    v51788[v51869] = v51947;
    int * v51792 = v51693->cache_age;
    int v51793 = v51792[v51870];
    int v51949 = v51793 + ((int)((unsigned int)(v51793 - v51789) >> 31));
    v51792[v51870] = v51949;
    int * v51795 = v51693->cache_age;
    v51795[v51940] = 0;
    v51798 = v51940;
  }
  int * v51799 = v51693->cache_vals;
  int v51952 = (v51798 * 2) + (((int)((unsigned int)v51697 >> 2)) & 1);
  v51799[v51952] = v51698;
  int * v51801 = v51693->cache_tags;
  int v51802 = v51801[v51871];
  int v51803 = v51801[v51872];
  bool v51955 = !(((~(((v51802 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51802 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) | (~(((v51803 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51803 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31))) == 0);
  int v51857;
  if (v51955) {
    int * v51804 = v51693->cache_age;
    int v51957 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((~(((v51803 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))) | (-(v51803 ^ ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1))))) >> 31)) & 1);
    int v51805 = v51804[v51957];
    int v51806 = v51804[v51871];
    int v51958 = v51806 + ((int)((unsigned int)(v51806 - v51805) >> 31));
    v51804[v51871] = v51958;
    int * v51808 = v51693->cache_age;
    int v51809 = v51808[v51872];
    int v51960 = v51809 + ((int)((unsigned int)(v51809 - v51805) >> 31));
    v51808[v51872] = v51960;
    int * v51811 = v51693->cache_age;
    v51811[v51957] = 0;
    v51857 = v51957;
  } else {
    int * v51814 = v51693->cache_age;
    int v51964 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2);
    int v51815 = v51814[v51964];
    int * v51816 = v51693->cache_tags;
    int v51817 = v51816[v51964];
    int v51818 = v51814[v51872];
    int v51819 = v51816[v51872];
    int * v51820 = v51693->cache_dirty;
    int v51967 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51815 + ((~(((v51817 ^ -1) | (-(v51817 ^ -1))) >> 31)) & 2)) - (v51818 + ((~(((v51819 ^ -1) | (-(v51819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v51821 = v51820[v51967];
    bool v51968 = !(v51821 == 0);
    if (v51968) {
      int * v51822 = v51693->cache_tags;
      int v51823 = v51822[v51967];
      int * v51824 = v51693->cache_vals;
      int v51971 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51815 + ((~(((v51817 ^ -1) | (-(v51817 ^ -1))) >> 31)) & 2)) - (v51818 + ((~(((v51819 ^ -1) | (-(v51819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v51825 = v51824[v51971];
      int v51972 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51815 + ((~(((v51817 ^ -1) | (-(v51817 ^ -1))) >> 31)) & 2)) - (v51818 + ((~(((v51819 ^ -1) | (-(v51819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v51826 = v51824[v51972];
      int * v51827 = v51693->mem;
      int v51974 = v51823 * 2;
      v51827[v51974] = v51825;
      int * v51829 = v51693->mem;
      int v51977 = (v51823 * 2) + 1;
      v51829[v51977] = v51826;
      ;
    } else {
      ;
    }
    int * v51834 = v51693->mem;
    int v51982 = ((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) * 2;
    int v51835 = v51834[v51982];
    int v51983 = (((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) * 2) + 1;
    int v51836 = v51834[v51983];
    int * v51837 = v51693->cache_vals;
    int v51985 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51815 + ((~(((v51817 ^ -1) | (-(v51817 ^ -1))) >> 31)) & 2)) - (v51818 + ((~(((v51819 ^ -1) | (-(v51819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v51837[v51985] = v51835;
    int * v51839 = v51693->cache_vals;
    int v51988 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1)) & 3) * 2)) + ((((v51815 + ((~(((v51817 ^ -1) | (-(v51817 ^ -1))) >> 31)) & 2)) - (v51818 + ((~(((v51819 ^ -1) | (-(v51819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v51839[v51988] = v51836;
    int * v51841 = v51693->cache_tags;
    int v51991 = (int)((unsigned int)((int)((unsigned int)v51697 >> 2)) >> 1);
    v51841[v51967] = v51991;
    int * v51843 = v51693->cache_dirty;
    v51843[v51967] = 0;
    int * v51845 = v51693->cache_age;
    v51845[v51967] = 1;
    int * v51847 = v51693->cache_age;
    int v51848 = v51847[v51967];
    int v51849 = v51847[v51871];
    int v51997 = v51849 + ((int)((unsigned int)(v51849 - v51848) >> 31));
    v51847[v51871] = v51997;
    int * v51851 = v51693->cache_age;
    int v51852 = v51851[v51872];
    int v51999 = v51852 + ((int)((unsigned int)(v51852 - v51848) >> 31));
    v51851[v51872] = v51999;
    int * v51854 = v51693->cache_age;
    v51854[v51967] = 0;
    v51857 = v51967;
  }
  int * v51858 = v51693->cache_vals;
  int v52002 = (v51857 * 2) + (((int)((unsigned int)v51697 >> 2)) & 1);
  v51858[v52002] = v51698;
  int * v51860 = v51693->cache_dirty;
  v51860[v51857] = 1;
  struct StateT * v51862 = slot_1030(v51693);
  return v51862;
}

struct StateT * slot_566(struct StateT * v26429) {
  int v26430 = v26429->timer;
  int v26442 = v26430 + 1;
  v26429->timer = v26442;
  int * v26432 = v26429->regs;
  int v26433 = v26432[28];
  int v26434 = v26432[7];
  bool v26446 = (v26433 ^ -2147483648) < (v26434 ^ -2147483648);
  int v26437;
  if (v26446) {
    v26437 = 1;
  } else {
    v26437 = 0;
  }
  int * v26438 = v26429->regs;
  v26438[7] = v26437;
  struct StateT * v26440 = slot_602(v26429);
  return v26440;
}

struct StateT * slot_923(struct StateT * v46769) {
  int v46770 = v46769->timer;
  int v46880 = v46770 + 1;
  v46769->timer = v46880;
  int * v46772 = v46769->regs;
  int v46773 = v46772[2];
  int * v46774 = v46769->cache_tags;
  int v46884 = (((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2;
  int v46775 = v46774[v46884];
  int v46885 = ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v46776 = v46774[v46885];
  int v46886 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2);
  int v46777 = v46774[v46886];
  int v46887 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v46778 = v46774[v46887];
  int v46779 = v46769->timer;
  int v46888 = v46779 + ((100 ^ (((~(((v46777 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46777 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v46775 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46775 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v46776 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46776 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v46777 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46777 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v46769->timer = v46888;
  int * v46781 = v46769->cache_vals;
  bool v46889 = !(((~(((v46775 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46775 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v46776 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46776 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v46874;
  if (v46889) {
    int * v46782 = v46769->cache_age;
    int v46891 = ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v46776 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46776 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v46783 = v46782[v46891];
    int v46784 = v46782[v46884];
    int v46892 = v46784 + ((int)((unsigned int)(v46784 - v46783) >> 31));
    v46782[v46884] = v46892;
    int * v46786 = v46769->cache_age;
    int v46787 = v46786[v46885];
    int v46894 = v46787 + ((int)((unsigned int)(v46787 - v46783) >> 31));
    v46786[v46885] = v46894;
    int * v46789 = v46769->cache_age;
    v46789[v46891] = 0;
    v46874 = v46891;
  } else {
    int * v46792 = v46769->cache_age;
    int v46898 = (((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2;
    int v46793 = v46792[v46898];
    int * v46794 = v46769->cache_tags;
    int v46795 = v46794[v46898];
    int v46796 = v46792[v46885];
    int v46797 = v46794[v46885];
    bool v46900 = !(((~(((v46777 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46777 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v46851;
    if (v46900) {
      int * v46798 = v46769->cache_age;
      int v46902 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))) | (-(v46778 ^ ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v46799 = v46798[v46902];
      int v46800 = v46798[v46886];
      int v46903 = v46800 + ((int)((unsigned int)(v46800 - v46799) >> 31));
      v46798[v46886] = v46903;
      int * v46802 = v46769->cache_age;
      int v46803 = v46802[v46887];
      int v46905 = v46803 + ((int)((unsigned int)(v46803 - v46799) >> 31));
      v46802[v46887] = v46905;
      int * v46805 = v46769->cache_age;
      v46805[v46902] = 0;
      v46851 = v46902;
    } else {
      int * v46808 = v46769->cache_age;
      int v46909 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2);
      int v46809 = v46808[v46909];
      int * v46810 = v46769->cache_tags;
      int v46811 = v46810[v46909];
      int v46812 = v46808[v46887];
      int v46813 = v46810[v46887];
      int * v46814 = v46769->cache_dirty;
      int v46912 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v46809 + ((~(((v46811 ^ -1) | (-(v46811 ^ -1))) >> 31)) & 2)) - (v46812 + ((~(((v46813 ^ -1) | (-(v46813 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v46815 = v46814[v46912];
      bool v46913 = !(v46815 == 0);
      if (v46913) {
        int * v46816 = v46769->cache_tags;
        int v46817 = v46816[v46912];
        int * v46818 = v46769->cache_vals;
        int v46916 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v46809 + ((~(((v46811 ^ -1) | (-(v46811 ^ -1))) >> 31)) & 2)) - (v46812 + ((~(((v46813 ^ -1) | (-(v46813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v46819 = v46818[v46916];
        int v46917 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v46809 + ((~(((v46811 ^ -1) | (-(v46811 ^ -1))) >> 31)) & 2)) - (v46812 + ((~(((v46813 ^ -1) | (-(v46813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v46820 = v46818[v46917];
        int * v46821 = v46769->mem;
        int v46919 = v46817 * 2;
        v46821[v46919] = v46819;
        int * v46823 = v46769->mem;
        int v46922 = (v46817 * 2) + 1;
        v46823[v46922] = v46820;
        ;
      } else {
        ;
      }
      int * v46828 = v46769->mem;
      int v46927 = ((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) * 2;
      int v46829 = v46828[v46927];
      int v46928 = (((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) * 2) + 1;
      int v46830 = v46828[v46928];
      int * v46831 = v46769->cache_vals;
      int v46930 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v46809 + ((~(((v46811 ^ -1) | (-(v46811 ^ -1))) >> 31)) & 2)) - (v46812 + ((~(((v46813 ^ -1) | (-(v46813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v46831[v46930] = v46829;
      int * v46833 = v46769->cache_vals;
      int v46933 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v46809 + ((~(((v46811 ^ -1) | (-(v46811 ^ -1))) >> 31)) & 2)) - (v46812 + ((~(((v46813 ^ -1) | (-(v46813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v46833[v46933] = v46830;
      int * v46835 = v46769->cache_tags;
      int v46936 = (int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1);
      v46835[v46912] = v46936;
      int * v46837 = v46769->cache_dirty;
      v46837[v46912] = 0;
      int * v46839 = v46769->cache_age;
      v46839[v46912] = 1;
      int * v46841 = v46769->cache_age;
      int v46842 = v46841[v46912];
      int v46843 = v46841[v46886];
      int v46942 = v46843 + ((int)((unsigned int)(v46843 - v46842) >> 31));
      v46841[v46886] = v46942;
      int * v46845 = v46769->cache_age;
      int v46846 = v46845[v46887];
      int v46944 = v46846 + ((int)((unsigned int)(v46846 - v46842) >> 31));
      v46845[v46887] = v46944;
      int * v46848 = v46769->cache_age;
      v46848[v46912] = 0;
      v46851 = v46912;
    }
    int * v46852 = v46769->cache_vals;
    int v46947 = v46851 * 2;
    int v46853 = v46852[v46947];
    int v46948 = (v46851 * 2) + 1;
    int v46854 = v46852[v46948];
    int v46949 = (((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v46793 + ((~(((v46795 ^ -1) | (-(v46795 ^ -1))) >> 31)) & 2)) - (v46796 + ((~(((v46797 ^ -1) | (-(v46797 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v46852[v46949] = v46853;
    int * v46856 = v46769->cache_vals;
    int v46952 = ((((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v46793 + ((~(((v46795 ^ -1) | (-(v46795 ^ -1))) >> 31)) & 2)) - (v46796 + ((~(((v46797 ^ -1) | (-(v46797 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v46856[v46952] = v46854;
    int * v46858 = v46769->cache_tags;
    int v46955 = ((((int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v46793 + ((~(((v46795 ^ -1) | (-(v46795 ^ -1))) >> 31)) & 2)) - (v46796 + ((~(((v46797 ^ -1) | (-(v46797 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v46956 = (int)((unsigned int)((int)((unsigned int)(v46773 + 4) >> 2)) >> 1);
    v46858[v46955] = v46956;
    int * v46860 = v46769->cache_dirty;
    v46860[v46955] = 0;
    int * v46862 = v46769->cache_age;
    v46862[v46955] = 1;
    int * v46864 = v46769->cache_age;
    int v46865 = v46864[v46955];
    int v46866 = v46864[v46884];
    int v46962 = v46866 + ((int)((unsigned int)(v46866 - v46865) >> 31));
    v46864[v46884] = v46962;
    int * v46868 = v46769->cache_age;
    int v46869 = v46868[v46885];
    int v46964 = v46869 + ((int)((unsigned int)(v46869 - v46865) >> 31));
    v46868[v46885] = v46964;
    int * v46871 = v46769->cache_age;
    v46871[v46955] = 0;
    v46874 = v46955;
  }
  int v46967 = (v46874 * 2) + (((int)((unsigned int)(v46773 + 4) >> 2)) & 1);
  int v46875 = v46781[v46967];
  int * v46876 = v46769->regs;
  v46876[18] = v46875;
  struct StateT * v46878 = slot_982(v46769);
  return v46878;
}

struct StateT * slot_154(struct StateT * v7312) {
  int v7313 = v7312->timer;
  int v7321 = v7313 + 1;
  v7312->timer = v7321;
  int * v7315 = v7312->regs;
  int v7316 = v7315[5];
  int v7317 = v7315[28];
  int v7325 = v7316 + v7317;
  v7315[28] = v7325;
  struct StateT * v7319 = slot_157(v7312);
  return v7319;
}

struct StateT * slot_260(struct StateT * v13054) {
  int v13055 = v13054->timer;
  int v13063 = v13055 + 1;
  v13054->timer = v13063;
  int * v13057 = v13054->regs;
  int v13058 = v13057[7];
  int v13059 = v13057[6];
  int v13067 = v13058 + v13059;
  v13057[6] = v13067;
  struct StateT * v13061 = slot_293(v13054);
  return v13061;
}

struct StateT * slot_1090(struct StateT * v64201) {
  int v64202 = v64201->timer;
  int v64205 = v64202 + 1;
  v64201->timer = v64205;
  return v64201;
}

struct StateT * slot_305(struct StateT * v13902) {
  int v13903 = v13902->timer;
  int v13911 = v13903 + 1;
  v13902->timer = v13911;
  int * v13905 = v13902->regs;
  int v13906 = v13905[18];
  int v13907 = v13905[6];
  int v13915 = v13906 + v13907;
  v13905[6] = v13915;
  struct StateT * v13909 = slot_309(v13902);
  return v13909;
}

struct StateT * slot_662(struct StateT * v28294) {
  int * v28295 = v28294->saved_regs;
  int * v28296 = v28294->regs;
  int v28297 = v28296[13];
  v28295[13] = v28297;
  int v28299 = v28294->timer;
  int v28310 = v28299 + 1;
  v28294->timer = v28310;
  int * v28301 = v28294->regs;
  int v28302 = v28301[5];
  int v28313 = v28302 << 13;
  v28301[13] = v28313;
  struct StateT * v28304 = slot_671(v28294);
  return v28304;
}

struct StateT * slot_34(struct StateT * v3127) {
  int v3128 = v3127->timer;
  int v3135 = v3128 + 1;
  v3127->timer = v3135;
  int * v3130 = v3127->regs;
  int v3131 = v3130[31];
  int v3139 = (int)((unsigned int)v3131 >> 19);
  v3130[29] = v3139;
  struct StateT * v3133 = slot_35(v3127);
  return v3133;
}

struct StateT * slot_971(struct StateT * v49250) {
  int v49251 = v49250->timer;
  int v49259 = v49251 + 1;
  v49250->timer = v49259;
  int * v49253 = v49250->regs;
  int v49254 = v49253[12];
  int v49255 = v49253[5];
  int v49263 = v49254 | v49255;
  v49253[12] = v49263;
  struct StateT * v49257 = slot_984(v49250);
  return v49257;
}

struct StateT * slot_1016(struct StateT * v50998) {
  int v50999 = v50998->timer;
  int v51169 = v50999 + 1;
  v50998->timer = v51169;
  int * v51001 = v50998->regs;
  int v51002 = v51001[10];
  int v51003 = v51001[16];
  int * v51004 = v50998->cache_tags;
  int v51174 = (((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2;
  int v51005 = v51004[v51174];
  int v51175 = ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v51006 = v51004[v51175];
  int v51176 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2);
  int v51007 = v51004[v51176];
  int v51177 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v51008 = v51004[v51177];
  int v51009 = v50998->timer;
  int v51178 = v51009 + ((100 ^ (((~(((v51007 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51007 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v51005 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51005 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v51006 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51006 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v51007 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51007 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v50998->timer = v51178;
  bool v51179 = !(((~(((v51005 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51005 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v51006 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51006 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v51103;
  if (v51179) {
    int * v51011 = v50998->cache_age;
    int v51181 = ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v51006 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51006 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v51012 = v51011[v51181];
    int v51013 = v51011[v51174];
    int v51182 = v51013 + ((int)((unsigned int)(v51013 - v51012) >> 31));
    v51011[v51174] = v51182;
    int * v51015 = v50998->cache_age;
    int v51016 = v51015[v51175];
    int v51184 = v51016 + ((int)((unsigned int)(v51016 - v51012) >> 31));
    v51015[v51175] = v51184;
    int * v51018 = v50998->cache_age;
    v51018[v51181] = 0;
    v51103 = v51181;
  } else {
    int * v51021 = v50998->cache_age;
    int v51188 = (((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2;
    int v51022 = v51021[v51188];
    int * v51023 = v50998->cache_tags;
    int v51024 = v51023[v51188];
    int v51025 = v51021[v51175];
    int v51026 = v51023[v51175];
    bool v51190 = !(((~(((v51007 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51007 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v51080;
    if (v51190) {
      int * v51027 = v50998->cache_age;
      int v51192 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51008 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v51028 = v51027[v51192];
      int v51029 = v51027[v51176];
      int v51193 = v51029 + ((int)((unsigned int)(v51029 - v51028) >> 31));
      v51027[v51176] = v51193;
      int * v51031 = v50998->cache_age;
      int v51032 = v51031[v51177];
      int v51195 = v51032 + ((int)((unsigned int)(v51032 - v51028) >> 31));
      v51031[v51177] = v51195;
      int * v51034 = v50998->cache_age;
      v51034[v51192] = 0;
      v51080 = v51192;
    } else {
      int * v51037 = v50998->cache_age;
      int v51199 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2);
      int v51038 = v51037[v51199];
      int * v51039 = v50998->cache_tags;
      int v51040 = v51039[v51199];
      int v51041 = v51037[v51177];
      int v51042 = v51039[v51177];
      int * v51043 = v50998->cache_dirty;
      int v51202 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51038 + ((~(((v51040 ^ -1) | (-(v51040 ^ -1))) >> 31)) & 2)) - (v51041 + ((~(((v51042 ^ -1) | (-(v51042 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v51044 = v51043[v51202];
      bool v51203 = !(v51044 == 0);
      if (v51203) {
        int * v51045 = v50998->cache_tags;
        int v51046 = v51045[v51202];
        int * v51047 = v50998->cache_vals;
        int v51206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51038 + ((~(((v51040 ^ -1) | (-(v51040 ^ -1))) >> 31)) & 2)) - (v51041 + ((~(((v51042 ^ -1) | (-(v51042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v51048 = v51047[v51206];
        int v51207 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51038 + ((~(((v51040 ^ -1) | (-(v51040 ^ -1))) >> 31)) & 2)) - (v51041 + ((~(((v51042 ^ -1) | (-(v51042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v51049 = v51047[v51207];
        int * v51050 = v50998->mem;
        int v51209 = v51046 * 2;
        v51050[v51209] = v51048;
        int * v51052 = v50998->mem;
        int v51212 = (v51046 * 2) + 1;
        v51052[v51212] = v51049;
        ;
      } else {
        ;
      }
      int * v51057 = v50998->mem;
      int v51217 = ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) * 2;
      int v51058 = v51057[v51217];
      int v51218 = (((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) * 2) + 1;
      int v51059 = v51057[v51218];
      int * v51060 = v50998->cache_vals;
      int v51220 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51038 + ((~(((v51040 ^ -1) | (-(v51040 ^ -1))) >> 31)) & 2)) - (v51041 + ((~(((v51042 ^ -1) | (-(v51042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v51060[v51220] = v51058;
      int * v51062 = v50998->cache_vals;
      int v51223 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51038 + ((~(((v51040 ^ -1) | (-(v51040 ^ -1))) >> 31)) & 2)) - (v51041 + ((~(((v51042 ^ -1) | (-(v51042 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v51062[v51223] = v51059;
      int * v51064 = v50998->cache_tags;
      int v51226 = (int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1);
      v51064[v51202] = v51226;
      int * v51066 = v50998->cache_dirty;
      v51066[v51202] = 0;
      int * v51068 = v50998->cache_age;
      v51068[v51202] = 1;
      int * v51070 = v50998->cache_age;
      int v51071 = v51070[v51202];
      int v51072 = v51070[v51176];
      int v51232 = v51072 + ((int)((unsigned int)(v51072 - v51071) >> 31));
      v51070[v51176] = v51232;
      int * v51074 = v50998->cache_age;
      int v51075 = v51074[v51177];
      int v51234 = v51075 + ((int)((unsigned int)(v51075 - v51071) >> 31));
      v51074[v51177] = v51234;
      int * v51077 = v50998->cache_age;
      v51077[v51202] = 0;
      v51080 = v51202;
    }
    int * v51081 = v50998->cache_vals;
    int v51237 = v51080 * 2;
    int v51082 = v51081[v51237];
    int v51238 = (v51080 * 2) + 1;
    int v51083 = v51081[v51238];
    int v51239 = (((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v51022 + ((~(((v51024 ^ -1) | (-(v51024 ^ -1))) >> 31)) & 2)) - (v51025 + ((~(((v51026 ^ -1) | (-(v51026 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v51081[v51239] = v51082;
    int * v51085 = v50998->cache_vals;
    int v51242 = ((((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v51022 + ((~(((v51024 ^ -1) | (-(v51024 ^ -1))) >> 31)) & 2)) - (v51025 + ((~(((v51026 ^ -1) | (-(v51026 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v51085[v51242] = v51083;
    int * v51087 = v50998->cache_tags;
    int v51245 = ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v51022 + ((~(((v51024 ^ -1) | (-(v51024 ^ -1))) >> 31)) & 2)) - (v51025 + ((~(((v51026 ^ -1) | (-(v51026 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v51246 = (int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1);
    v51087[v51245] = v51246;
    int * v51089 = v50998->cache_dirty;
    v51089[v51245] = 0;
    int * v51091 = v50998->cache_age;
    v51091[v51245] = 1;
    int * v51093 = v50998->cache_age;
    int v51094 = v51093[v51245];
    int v51095 = v51093[v51174];
    int v51252 = v51095 + ((int)((unsigned int)(v51095 - v51094) >> 31));
    v51093[v51174] = v51252;
    int * v51097 = v50998->cache_age;
    int v51098 = v51097[v51175];
    int v51254 = v51098 + ((int)((unsigned int)(v51098 - v51094) >> 31));
    v51097[v51175] = v51254;
    int * v51100 = v50998->cache_age;
    v51100[v51245] = 0;
    v51103 = v51245;
  }
  int * v51104 = v50998->cache_vals;
  int v51257 = (v51103 * 2) + (((int)((unsigned int)(v51002 + 36) >> 2)) & 1);
  v51104[v51257] = v51003;
  int * v51106 = v50998->cache_tags;
  int v51107 = v51106[v51176];
  int v51108 = v51106[v51177];
  bool v51260 = !(((~(((v51107 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51107 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v51108 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51108 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v51162;
  if (v51260) {
    int * v51109 = v50998->cache_age;
    int v51262 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v51108 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))) | (-(v51108 ^ ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v51110 = v51109[v51262];
    int v51111 = v51109[v51176];
    int v51263 = v51111 + ((int)((unsigned int)(v51111 - v51110) >> 31));
    v51109[v51176] = v51263;
    int * v51113 = v50998->cache_age;
    int v51114 = v51113[v51177];
    int v51265 = v51114 + ((int)((unsigned int)(v51114 - v51110) >> 31));
    v51113[v51177] = v51265;
    int * v51116 = v50998->cache_age;
    v51116[v51262] = 0;
    v51162 = v51262;
  } else {
    int * v51119 = v50998->cache_age;
    int v51269 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2);
    int v51120 = v51119[v51269];
    int * v51121 = v50998->cache_tags;
    int v51122 = v51121[v51269];
    int v51123 = v51119[v51177];
    int v51124 = v51121[v51177];
    int * v51125 = v50998->cache_dirty;
    int v51272 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51120 + ((~(((v51122 ^ -1) | (-(v51122 ^ -1))) >> 31)) & 2)) - (v51123 + ((~(((v51124 ^ -1) | (-(v51124 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v51126 = v51125[v51272];
    bool v51273 = !(v51126 == 0);
    if (v51273) {
      int * v51127 = v50998->cache_tags;
      int v51128 = v51127[v51272];
      int * v51129 = v50998->cache_vals;
      int v51276 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51120 + ((~(((v51122 ^ -1) | (-(v51122 ^ -1))) >> 31)) & 2)) - (v51123 + ((~(((v51124 ^ -1) | (-(v51124 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v51130 = v51129[v51276];
      int v51277 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51120 + ((~(((v51122 ^ -1) | (-(v51122 ^ -1))) >> 31)) & 2)) - (v51123 + ((~(((v51124 ^ -1) | (-(v51124 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v51131 = v51129[v51277];
      int * v51132 = v50998->mem;
      int v51279 = v51128 * 2;
      v51132[v51279] = v51130;
      int * v51134 = v50998->mem;
      int v51282 = (v51128 * 2) + 1;
      v51134[v51282] = v51131;
      ;
    } else {
      ;
    }
    int * v51139 = v50998->mem;
    int v51287 = ((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) * 2;
    int v51140 = v51139[v51287];
    int v51288 = (((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) * 2) + 1;
    int v51141 = v51139[v51288];
    int * v51142 = v50998->cache_vals;
    int v51290 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51120 + ((~(((v51122 ^ -1) | (-(v51122 ^ -1))) >> 31)) & 2)) - (v51123 + ((~(((v51124 ^ -1) | (-(v51124 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v51142[v51290] = v51140;
    int * v51144 = v50998->cache_vals;
    int v51293 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v51120 + ((~(((v51122 ^ -1) | (-(v51122 ^ -1))) >> 31)) & 2)) - (v51123 + ((~(((v51124 ^ -1) | (-(v51124 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v51144[v51293] = v51141;
    int * v51146 = v50998->cache_tags;
    int v51296 = (int)((unsigned int)((int)((unsigned int)(v51002 + 36) >> 2)) >> 1);
    v51146[v51272] = v51296;
    int * v51148 = v50998->cache_dirty;
    v51148[v51272] = 0;
    int * v51150 = v50998->cache_age;
    v51150[v51272] = 1;
    int * v51152 = v50998->cache_age;
    int v51153 = v51152[v51272];
    int v51154 = v51152[v51176];
    int v51302 = v51154 + ((int)((unsigned int)(v51154 - v51153) >> 31));
    v51152[v51176] = v51302;
    int * v51156 = v50998->cache_age;
    int v51157 = v51156[v51177];
    int v51304 = v51157 + ((int)((unsigned int)(v51157 - v51153) >> 31));
    v51156[v51177] = v51304;
    int * v51159 = v50998->cache_age;
    v51159[v51272] = 0;
    v51162 = v51272;
  }
  int * v51163 = v50998->cache_vals;
  int v51307 = (v51162 * 2) + (((int)((unsigned int)(v51002 + 36) >> 2)) & 1);
  v51163[v51307] = v51003;
  int * v51165 = v50998->cache_dirty;
  v51165[v51162] = 1;
  struct StateT * v51167 = slot_1055(v50998);
  return v51167;
}

struct StateT * slot_21(struct StateT * v1919) {
  int v1920 = v1919->timer;
  int v1932 = v1920 + 1;
  v1919->timer = v1932;
  int * v1922 = v1919->regs;
  int v1923 = v1922[17];
  int v1924 = v1922[7];
  bool v1936 = (v1923 ^ -2147483648) < (v1924 ^ -2147483648);
  int v1927;
  if (v1936) {
    v1927 = 1;
  } else {
    v1927 = 0;
  }
  int * v1928 = v1919->regs;
  v1928[5] = v1927;
  struct StateT * v1930 = slot_22(v1919);
  return v1930;
}

struct StateT * slot_118(struct StateT * v6572) {
  int v6573 = v6572->timer;
  int v6581 = v6573 + 1;
  v6572->timer = v6581;
  int * v6575 = v6572->regs;
  int v6576 = v6575[30];
  int v6577 = v6575[7];
  int v6585 = v6576 + v6577;
  v6575[7] = v6585;
  struct StateT * v6579 = slot_120(v6572);
  return v6579;
}

struct StateT * slot_376(struct StateT * v20455) {
  int v20456 = v20455->timer;
  int v20464 = v20456 + 1;
  v20455->timer = v20464;
  int * v20458 = v20455->regs;
  int v20459 = v20458[5];
  int v20460 = v20458[17];
  int v20468 = v20459 | v20460;
  v20458[17] = v20468;
  struct StateT * v20462 = slot_473(v20455);
  return v20462;
}

struct StateT * slot_373(struct StateT * v19732) {
  int v19733 = v19732->timer;
  int v19903 = v19733 + 1;
  v19732->timer = v19903;
  int * v19735 = v19732->regs;
  int v19736 = v19735[10];
  int v19737 = v19735[29];
  int * v19738 = v19732->cache_tags;
  int v19908 = (((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2;
  int v19739 = v19738[v19908];
  int v19909 = ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19740 = v19738[v19909];
  int v19910 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2);
  int v19741 = v19738[v19910];
  int v19911 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19742 = v19738[v19911];
  int v19743 = v19732->timer;
  int v19912 = v19743 + ((100 ^ (((~(((v19741 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19741 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19739 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19739 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v19740 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19740 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19741 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19741 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19732->timer = v19912;
  bool v19913 = !(((~(((v19739 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19739 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v19740 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19740 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v19837;
  if (v19913) {
    int * v19745 = v19732->cache_age;
    int v19915 = ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v19740 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19740 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v19746 = v19745[v19915];
    int v19747 = v19745[v19908];
    int v19916 = v19747 + ((int)((unsigned int)(v19747 - v19746) >> 31));
    v19745[v19908] = v19916;
    int * v19749 = v19732->cache_age;
    int v19750 = v19749[v19909];
    int v19918 = v19750 + ((int)((unsigned int)(v19750 - v19746) >> 31));
    v19749[v19909] = v19918;
    int * v19752 = v19732->cache_age;
    v19752[v19915] = 0;
    v19837 = v19915;
  } else {
    int * v19755 = v19732->cache_age;
    int v19922 = (((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2;
    int v19756 = v19755[v19922];
    int * v19757 = v19732->cache_tags;
    int v19758 = v19757[v19922];
    int v19759 = v19755[v19909];
    int v19760 = v19757[v19909];
    bool v19924 = !(((~(((v19741 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19741 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v19814;
    if (v19924) {
      int * v19761 = v19732->cache_age;
      int v19926 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19742 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v19762 = v19761[v19926];
      int v19763 = v19761[v19910];
      int v19927 = v19763 + ((int)((unsigned int)(v19763 - v19762) >> 31));
      v19761[v19910] = v19927;
      int * v19765 = v19732->cache_age;
      int v19766 = v19765[v19911];
      int v19929 = v19766 + ((int)((unsigned int)(v19766 - v19762) >> 31));
      v19765[v19911] = v19929;
      int * v19768 = v19732->cache_age;
      v19768[v19926] = 0;
      v19814 = v19926;
    } else {
      int * v19771 = v19732->cache_age;
      int v19933 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2);
      int v19772 = v19771[v19933];
      int * v19773 = v19732->cache_tags;
      int v19774 = v19773[v19933];
      int v19775 = v19771[v19911];
      int v19776 = v19773[v19911];
      int * v19777 = v19732->cache_dirty;
      int v19936 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19772 + ((~(((v19774 ^ -1) | (-(v19774 ^ -1))) >> 31)) & 2)) - (v19775 + ((~(((v19776 ^ -1) | (-(v19776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19778 = v19777[v19936];
      bool v19937 = !(v19778 == 0);
      if (v19937) {
        int * v19779 = v19732->cache_tags;
        int v19780 = v19779[v19936];
        int * v19781 = v19732->cache_vals;
        int v19940 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19772 + ((~(((v19774 ^ -1) | (-(v19774 ^ -1))) >> 31)) & 2)) - (v19775 + ((~(((v19776 ^ -1) | (-(v19776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19782 = v19781[v19940];
        int v19941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19772 + ((~(((v19774 ^ -1) | (-(v19774 ^ -1))) >> 31)) & 2)) - (v19775 + ((~(((v19776 ^ -1) | (-(v19776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19783 = v19781[v19941];
        int * v19784 = v19732->mem;
        int v19943 = v19780 * 2;
        v19784[v19943] = v19782;
        int * v19786 = v19732->mem;
        int v19946 = (v19780 * 2) + 1;
        v19786[v19946] = v19783;
        ;
      } else {
        ;
      }
      int * v19791 = v19732->mem;
      int v19951 = ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) * 2;
      int v19792 = v19791[v19951];
      int v19952 = (((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) * 2) + 1;
      int v19793 = v19791[v19952];
      int * v19794 = v19732->cache_vals;
      int v19954 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19772 + ((~(((v19774 ^ -1) | (-(v19774 ^ -1))) >> 31)) & 2)) - (v19775 + ((~(((v19776 ^ -1) | (-(v19776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19794[v19954] = v19792;
      int * v19796 = v19732->cache_vals;
      int v19957 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19772 + ((~(((v19774 ^ -1) | (-(v19774 ^ -1))) >> 31)) & 2)) - (v19775 + ((~(((v19776 ^ -1) | (-(v19776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19796[v19957] = v19793;
      int * v19798 = v19732->cache_tags;
      int v19960 = (int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1);
      v19798[v19936] = v19960;
      int * v19800 = v19732->cache_dirty;
      v19800[v19936] = 0;
      int * v19802 = v19732->cache_age;
      v19802[v19936] = 1;
      int * v19804 = v19732->cache_age;
      int v19805 = v19804[v19936];
      int v19806 = v19804[v19910];
      int v19966 = v19806 + ((int)((unsigned int)(v19806 - v19805) >> 31));
      v19804[v19910] = v19966;
      int * v19808 = v19732->cache_age;
      int v19809 = v19808[v19911];
      int v19968 = v19809 + ((int)((unsigned int)(v19809 - v19805) >> 31));
      v19808[v19911] = v19968;
      int * v19811 = v19732->cache_age;
      v19811[v19936] = 0;
      v19814 = v19936;
    }
    int * v19815 = v19732->cache_vals;
    int v19971 = v19814 * 2;
    int v19816 = v19815[v19971];
    int v19972 = (v19814 * 2) + 1;
    int v19817 = v19815[v19972];
    int v19973 = (((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v19756 + ((~(((v19758 ^ -1) | (-(v19758 ^ -1))) >> 31)) & 2)) - (v19759 + ((~(((v19760 ^ -1) | (-(v19760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19815[v19973] = v19816;
    int * v19819 = v19732->cache_vals;
    int v19976 = ((((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v19756 + ((~(((v19758 ^ -1) | (-(v19758 ^ -1))) >> 31)) & 2)) - (v19759 + ((~(((v19760 ^ -1) | (-(v19760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19819[v19976] = v19817;
    int * v19821 = v19732->cache_tags;
    int v19979 = ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v19756 + ((~(((v19758 ^ -1) | (-(v19758 ^ -1))) >> 31)) & 2)) - (v19759 + ((~(((v19760 ^ -1) | (-(v19760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19980 = (int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1);
    v19821[v19979] = v19980;
    int * v19823 = v19732->cache_dirty;
    v19823[v19979] = 0;
    int * v19825 = v19732->cache_age;
    v19825[v19979] = 1;
    int * v19827 = v19732->cache_age;
    int v19828 = v19827[v19979];
    int v19829 = v19827[v19908];
    int v19986 = v19829 + ((int)((unsigned int)(v19829 - v19828) >> 31));
    v19827[v19908] = v19986;
    int * v19831 = v19732->cache_age;
    int v19832 = v19831[v19909];
    int v19988 = v19832 + ((int)((unsigned int)(v19832 - v19828) >> 31));
    v19831[v19909] = v19988;
    int * v19834 = v19732->cache_age;
    v19834[v19979] = 0;
    v19837 = v19979;
  }
  int * v19838 = v19732->cache_vals;
  int v19991 = (v19837 * 2) + (((int)((unsigned int)(v19736 + 28) >> 2)) & 1);
  v19838[v19991] = v19737;
  int * v19840 = v19732->cache_tags;
  int v19841 = v19840[v19910];
  int v19842 = v19840[v19911];
  bool v19994 = !(((~(((v19841 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19841 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v19842 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19842 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v19896;
  if (v19994) {
    int * v19843 = v19732->cache_age;
    int v19996 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19842 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))) | (-(v19842 ^ ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v19844 = v19843[v19996];
    int v19845 = v19843[v19910];
    int v19997 = v19845 + ((int)((unsigned int)(v19845 - v19844) >> 31));
    v19843[v19910] = v19997;
    int * v19847 = v19732->cache_age;
    int v19848 = v19847[v19911];
    int v19999 = v19848 + ((int)((unsigned int)(v19848 - v19844) >> 31));
    v19847[v19911] = v19999;
    int * v19850 = v19732->cache_age;
    v19850[v19996] = 0;
    v19896 = v19996;
  } else {
    int * v19853 = v19732->cache_age;
    int v20003 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2);
    int v19854 = v19853[v20003];
    int * v19855 = v19732->cache_tags;
    int v19856 = v19855[v20003];
    int v19857 = v19853[v19911];
    int v19858 = v19855[v19911];
    int * v19859 = v19732->cache_dirty;
    int v20006 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19854 + ((~(((v19856 ^ -1) | (-(v19856 ^ -1))) >> 31)) & 2)) - (v19857 + ((~(((v19858 ^ -1) | (-(v19858 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19860 = v19859[v20006];
    bool v20007 = !(v19860 == 0);
    if (v20007) {
      int * v19861 = v19732->cache_tags;
      int v19862 = v19861[v20006];
      int * v19863 = v19732->cache_vals;
      int v20010 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19854 + ((~(((v19856 ^ -1) | (-(v19856 ^ -1))) >> 31)) & 2)) - (v19857 + ((~(((v19858 ^ -1) | (-(v19858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v19864 = v19863[v20010];
      int v20011 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19854 + ((~(((v19856 ^ -1) | (-(v19856 ^ -1))) >> 31)) & 2)) - (v19857 + ((~(((v19858 ^ -1) | (-(v19858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v19865 = v19863[v20011];
      int * v19866 = v19732->mem;
      int v20013 = v19862 * 2;
      v19866[v20013] = v19864;
      int * v19868 = v19732->mem;
      int v20016 = (v19862 * 2) + 1;
      v19868[v20016] = v19865;
      ;
    } else {
      ;
    }
    int * v19873 = v19732->mem;
    int v20021 = ((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) * 2;
    int v19874 = v19873[v20021];
    int v20022 = (((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) * 2) + 1;
    int v19875 = v19873[v20022];
    int * v19876 = v19732->cache_vals;
    int v20024 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19854 + ((~(((v19856 ^ -1) | (-(v19856 ^ -1))) >> 31)) & 2)) - (v19857 + ((~(((v19858 ^ -1) | (-(v19858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19876[v20024] = v19874;
    int * v19878 = v19732->cache_vals;
    int v20027 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v19854 + ((~(((v19856 ^ -1) | (-(v19856 ^ -1))) >> 31)) & 2)) - (v19857 + ((~(((v19858 ^ -1) | (-(v19858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19878[v20027] = v19875;
    int * v19880 = v19732->cache_tags;
    int v20030 = (int)((unsigned int)((int)((unsigned int)(v19736 + 28) >> 2)) >> 1);
    v19880[v20006] = v20030;
    int * v19882 = v19732->cache_dirty;
    v19882[v20006] = 0;
    int * v19884 = v19732->cache_age;
    v19884[v20006] = 1;
    int * v19886 = v19732->cache_age;
    int v19887 = v19886[v20006];
    int v19888 = v19886[v19910];
    int v20036 = v19888 + ((int)((unsigned int)(v19888 - v19887) >> 31));
    v19886[v19910] = v20036;
    int * v19890 = v19732->cache_age;
    int v19891 = v19890[v19911];
    int v20038 = v19891 + ((int)((unsigned int)(v19891 - v19887) >> 31));
    v19890[v19911] = v20038;
    int * v19893 = v19732->cache_age;
    v19893[v20006] = 0;
    v19896 = v20006;
  }
  int * v19897 = v19732->cache_vals;
  int v20041 = (v19896 * 2) + (((int)((unsigned int)(v19736 + 28) >> 2)) & 1);
  v19897[v20041] = v19737;
  int * v19899 = v19732->cache_dirty;
  v19899[v19896] = 1;
  struct StateT * v19901 = slot_352(v19732);
  return v19901;
}

struct StateT * slot_146(struct StateT * v7104) {
  int * v7105 = v7104->saved_regs;
  int * v7106 = v7104->regs;
  int v7107 = v7106[29];
  v7105[29] = v7107;
  int v7109 = v7104->timer;
  int v7121 = v7109 + 1;
  v7104->timer = v7121;
  int * v7111 = v7104->regs;
  int v7112 = v7111[7];
  int v7113 = v7111[16];
  int v7125 = v7112 & v7113;
  v7111[29] = v7125;
  struct StateT * v7115 = slot_148(v7104);
  return v7115;
}

struct StateT * slot_383(struct StateT * v20936) {
  int v20937 = v20936->timer;
  int v21047 = v20937 + 1;
  v20936->timer = v21047;
  int * v20939 = v20936->regs;
  int v20940 = v20939[11];
  int * v20941 = v20936->cache_tags;
  int v21051 = (((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2;
  int v20942 = v20941[v21051];
  int v21052 = ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v20943 = v20941[v21052];
  int v21053 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2);
  int v20944 = v20941[v21053];
  int v21054 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v20945 = v20941[v21054];
  int v20946 = v20936->timer;
  int v21055 = v20946 + ((100 ^ (((~(((v20944 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20944 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20942 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20942 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v20943 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20943 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v20944 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20944 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v20936->timer = v21055;
  int * v20948 = v20936->cache_vals;
  bool v21056 = !(((~(((v20942 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20942 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v20943 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20943 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v21041;
  if (v21056) {
    int * v20949 = v20936->cache_age;
    int v21058 = ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v20943 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20943 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v20950 = v20949[v21058];
    int v20951 = v20949[v21051];
    int v21059 = v20951 + ((int)((unsigned int)(v20951 - v20950) >> 31));
    v20949[v21051] = v21059;
    int * v20953 = v20936->cache_age;
    int v20954 = v20953[v21052];
    int v21061 = v20954 + ((int)((unsigned int)(v20954 - v20950) >> 31));
    v20953[v21052] = v21061;
    int * v20956 = v20936->cache_age;
    v20956[v21058] = 0;
    v21041 = v21058;
  } else {
    int * v20959 = v20936->cache_age;
    int v21065 = (((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2;
    int v20960 = v20959[v21065];
    int * v20961 = v20936->cache_tags;
    int v20962 = v20961[v21065];
    int v20963 = v20959[v21052];
    int v20964 = v20961[v21052];
    bool v21067 = !(((~(((v20944 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20944 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v21018;
    if (v21067) {
      int * v20965 = v20936->cache_age;
      int v21069 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))) | (-(v20945 ^ ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v20966 = v20965[v21069];
      int v20967 = v20965[v21053];
      int v21070 = v20967 + ((int)((unsigned int)(v20967 - v20966) >> 31));
      v20965[v21053] = v21070;
      int * v20969 = v20936->cache_age;
      int v20970 = v20969[v21054];
      int v21072 = v20970 + ((int)((unsigned int)(v20970 - v20966) >> 31));
      v20969[v21054] = v21072;
      int * v20972 = v20936->cache_age;
      v20972[v21069] = 0;
      v21018 = v21069;
    } else {
      int * v20975 = v20936->cache_age;
      int v21076 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2);
      int v20976 = v20975[v21076];
      int * v20977 = v20936->cache_tags;
      int v20978 = v20977[v21076];
      int v20979 = v20975[v21054];
      int v20980 = v20977[v21054];
      int * v20981 = v20936->cache_dirty;
      int v21079 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v20976 + ((~(((v20978 ^ -1) | (-(v20978 ^ -1))) >> 31)) & 2)) - (v20979 + ((~(((v20980 ^ -1) | (-(v20980 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v20982 = v20981[v21079];
      bool v21080 = !(v20982 == 0);
      if (v21080) {
        int * v20983 = v20936->cache_tags;
        int v20984 = v20983[v21079];
        int * v20985 = v20936->cache_vals;
        int v21083 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v20976 + ((~(((v20978 ^ -1) | (-(v20978 ^ -1))) >> 31)) & 2)) - (v20979 + ((~(((v20980 ^ -1) | (-(v20980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v20986 = v20985[v21083];
        int v21084 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v20976 + ((~(((v20978 ^ -1) | (-(v20978 ^ -1))) >> 31)) & 2)) - (v20979 + ((~(((v20980 ^ -1) | (-(v20980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v20987 = v20985[v21084];
        int * v20988 = v20936->mem;
        int v21086 = v20984 * 2;
        v20988[v21086] = v20986;
        int * v20990 = v20936->mem;
        int v21089 = (v20984 * 2) + 1;
        v20990[v21089] = v20987;
        ;
      } else {
        ;
      }
      int * v20995 = v20936->mem;
      int v21094 = ((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) * 2;
      int v20996 = v20995[v21094];
      int v21095 = (((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) * 2) + 1;
      int v20997 = v20995[v21095];
      int * v20998 = v20936->cache_vals;
      int v21097 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v20976 + ((~(((v20978 ^ -1) | (-(v20978 ^ -1))) >> 31)) & 2)) - (v20979 + ((~(((v20980 ^ -1) | (-(v20980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v20998[v21097] = v20996;
      int * v21000 = v20936->cache_vals;
      int v21100 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v20976 + ((~(((v20978 ^ -1) | (-(v20978 ^ -1))) >> 31)) & 2)) - (v20979 + ((~(((v20980 ^ -1) | (-(v20980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v21000[v21100] = v20997;
      int * v21002 = v20936->cache_tags;
      int v21103 = (int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1);
      v21002[v21079] = v21103;
      int * v21004 = v20936->cache_dirty;
      v21004[v21079] = 0;
      int * v21006 = v20936->cache_age;
      v21006[v21079] = 1;
      int * v21008 = v20936->cache_age;
      int v21009 = v21008[v21079];
      int v21010 = v21008[v21053];
      int v21109 = v21010 + ((int)((unsigned int)(v21010 - v21009) >> 31));
      v21008[v21053] = v21109;
      int * v21012 = v20936->cache_age;
      int v21013 = v21012[v21054];
      int v21111 = v21013 + ((int)((unsigned int)(v21013 - v21009) >> 31));
      v21012[v21054] = v21111;
      int * v21015 = v20936->cache_age;
      v21015[v21079] = 0;
      v21018 = v21079;
    }
    int * v21019 = v20936->cache_vals;
    int v21114 = v21018 * 2;
    int v21020 = v21019[v21114];
    int v21115 = (v21018 * 2) + 1;
    int v21021 = v21019[v21115];
    int v21116 = (((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v20960 + ((~(((v20962 ^ -1) | (-(v20962 ^ -1))) >> 31)) & 2)) - (v20963 + ((~(((v20964 ^ -1) | (-(v20964 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v21019[v21116] = v21020;
    int * v21023 = v20936->cache_vals;
    int v21119 = ((((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v20960 + ((~(((v20962 ^ -1) | (-(v20962 ^ -1))) >> 31)) & 2)) - (v20963 + ((~(((v20964 ^ -1) | (-(v20964 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v21023[v21119] = v21021;
    int * v21025 = v20936->cache_tags;
    int v21122 = ((((int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v20960 + ((~(((v20962 ^ -1) | (-(v20962 ^ -1))) >> 31)) & 2)) - (v20963 + ((~(((v20964 ^ -1) | (-(v20964 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v21123 = (int)((unsigned int)((int)((unsigned int)(v20940 + 36) >> 2)) >> 1);
    v21025[v21122] = v21123;
    int * v21027 = v20936->cache_dirty;
    v21027[v21122] = 0;
    int * v21029 = v20936->cache_age;
    v21029[v21122] = 1;
    int * v21031 = v20936->cache_age;
    int v21032 = v21031[v21122];
    int v21033 = v21031[v21051];
    int v21129 = v21033 + ((int)((unsigned int)(v21033 - v21032) >> 31));
    v21031[v21051] = v21129;
    int * v21035 = v20936->cache_age;
    int v21036 = v21035[v21052];
    int v21131 = v21036 + ((int)((unsigned int)(v21036 - v21032) >> 31));
    v21035[v21052] = v21131;
    int * v21038 = v20936->cache_age;
    v21038[v21122] = 0;
    v21041 = v21122;
  }
  int v21134 = (v21041 * 2) + (((int)((unsigned int)(v20940 + 36) >> 2)) & 1);
  int v21042 = v20948[v21134];
  int * v21043 = v20936->regs;
  v21043[11] = v21042;
  struct StateT * v21045 = slot_391(v20936);
  return v21045;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -16;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_489(struct StateT * v24969) {
  int v24970 = v24969->timer;
  int v24978 = v24970 + 1;
  v24969->timer = v24978;
  int * v24972 = v24969->regs;
  int v24973 = v24972[11];
  int v24974 = v24972[12];
  int v24983 = (((((int)((unsigned int)v24973 >> 16)) * ((int)((unsigned int)v24974 >> 16))) + ((int)((unsigned int)((v24973 & 65535) * ((int)((unsigned int)v24974 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v24973 >> 16)) * (v24974 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v24973 & 65535) * (v24974 & 65535)) >> 16)) + (((v24973 & 65535) * ((int)((unsigned int)v24974 >> 16))) & 65535)) + ((((int)((unsigned int)v24973 >> 16)) * (v24974 & 65535)) & 65535)) >> 16));
  v24972[29] = v24983;
  struct StateT * v24976 = slot_466(v24969);
  return v24976;
}

struct StateT * slot_148(struct StateT * v7136) {
  int * v7137 = v7136->saved_regs;
  int * v7138 = v7136->regs;
  int v7139 = v7138[7];
  v7137[7] = v7139;
  int v7141 = v7136->timer;
  int v7152 = v7141 + 1;
  v7136->timer = v7152;
  int * v7143 = v7136->regs;
  int v7144 = v7143[7];
  int v7154 = (int)((unsigned int)v7144 >> 19);
  v7143[7] = v7154;
  struct StateT * v7146 = slot_150(v7136);
  return v7146;
}

struct StateT * slot_725(struct StateT * v29424) {
  int v29425 = v29424->timer;
  int v29432 = v29425 + 1;
  v29424->timer = v29432;
  int * v29427 = v29424->regs;
  int v29428 = v29427[12];
  int v29435 = v29428 << 13;
  v29427[12] = v29435;
  struct StateT * v29430 = slot_730(v29424);
  return v29430;
}

struct StateT * slot_918(struct StateT * v46204) {
  int v46205 = v46204->timer;
  int v46212 = v46205 + 1;
  v46204->timer = v46212;
  int * v46207 = v46204->regs;
  int v46208 = v46207[17];
  int v46215 = (int)((unsigned int)v46208 >> 19);
  v46207[17] = v46215;
  struct StateT * v46210 = slot_933(v46204);
  return v46210;
}

struct StateT * slot_79(struct StateT * v4569) {
  int v4570 = v4569->timer;
  int v4740 = v4570 + 1;
  v4569->timer = v4740;
  int * v4572 = v4569->regs;
  int v4573 = v4572[10];
  int v4574 = v4572[17];
  int * v4575 = v4569->cache_tags;
  int v4745 = (((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2;
  int v4576 = v4575[v4745];
  int v4746 = ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4577 = v4575[v4746];
  int v4747 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2);
  int v4578 = v4575[v4747];
  int v4748 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4579 = v4575[v4748];
  int v4580 = v4569->timer;
  int v4749 = v4580 + ((100 ^ (((~(((v4578 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4578 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4576 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4576 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4577 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4577 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4578 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4578 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4569->timer = v4749;
  bool v4750 = !(((~(((v4576 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4576 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4577 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4577 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4674;
  if (v4750) {
    int * v4582 = v4569->cache_age;
    int v4752 = ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v4577 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4577 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4583 = v4582[v4752];
    int v4584 = v4582[v4745];
    int v4753 = v4584 + ((int)((unsigned int)(v4584 - v4583) >> 31));
    v4582[v4745] = v4753;
    int * v4586 = v4569->cache_age;
    int v4587 = v4586[v4746];
    int v4755 = v4587 + ((int)((unsigned int)(v4587 - v4583) >> 31));
    v4586[v4746] = v4755;
    int * v4589 = v4569->cache_age;
    v4589[v4752] = 0;
    v4674 = v4752;
  } else {
    int * v4592 = v4569->cache_age;
    int v4759 = (((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2;
    int v4593 = v4592[v4759];
    int * v4594 = v4569->cache_tags;
    int v4595 = v4594[v4759];
    int v4596 = v4592[v4746];
    int v4597 = v4594[v4746];
    bool v4761 = !(((~(((v4578 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4578 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v4651;
    if (v4761) {
      int * v4598 = v4569->cache_age;
      int v4763 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4579 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v4599 = v4598[v4763];
      int v4600 = v4598[v4747];
      int v4764 = v4600 + ((int)((unsigned int)(v4600 - v4599) >> 31));
      v4598[v4747] = v4764;
      int * v4602 = v4569->cache_age;
      int v4603 = v4602[v4748];
      int v4766 = v4603 + ((int)((unsigned int)(v4603 - v4599) >> 31));
      v4602[v4748] = v4766;
      int * v4605 = v4569->cache_age;
      v4605[v4763] = 0;
      v4651 = v4763;
    } else {
      int * v4608 = v4569->cache_age;
      int v4770 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2);
      int v4609 = v4608[v4770];
      int * v4610 = v4569->cache_tags;
      int v4611 = v4610[v4770];
      int v4612 = v4608[v4748];
      int v4613 = v4610[v4748];
      int * v4614 = v4569->cache_dirty;
      int v4773 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4615 = v4614[v4773];
      bool v4774 = !(v4615 == 0);
      if (v4774) {
        int * v4616 = v4569->cache_tags;
        int v4617 = v4616[v4773];
        int * v4618 = v4569->cache_vals;
        int v4777 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4619 = v4618[v4777];
        int v4778 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4620 = v4618[v4778];
        int * v4621 = v4569->mem;
        int v4780 = v4617 * 2;
        v4621[v4780] = v4619;
        int * v4623 = v4569->mem;
        int v4783 = (v4617 * 2) + 1;
        v4623[v4783] = v4620;
        ;
      } else {
        ;
      }
      int * v4628 = v4569->mem;
      int v4788 = ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) * 2;
      int v4629 = v4628[v4788];
      int v4789 = (((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) * 2) + 1;
      int v4630 = v4628[v4789];
      int * v4631 = v4569->cache_vals;
      int v4791 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4631[v4791] = v4629;
      int * v4633 = v4569->cache_vals;
      int v4794 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4609 + ((~(((v4611 ^ -1) | (-(v4611 ^ -1))) >> 31)) & 2)) - (v4612 + ((~(((v4613 ^ -1) | (-(v4613 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4633[v4794] = v4630;
      int * v4635 = v4569->cache_tags;
      int v4797 = (int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1);
      v4635[v4773] = v4797;
      int * v4637 = v4569->cache_dirty;
      v4637[v4773] = 0;
      int * v4639 = v4569->cache_age;
      v4639[v4773] = 1;
      int * v4641 = v4569->cache_age;
      int v4642 = v4641[v4773];
      int v4643 = v4641[v4747];
      int v4803 = v4643 + ((int)((unsigned int)(v4643 - v4642) >> 31));
      v4641[v4747] = v4803;
      int * v4645 = v4569->cache_age;
      int v4646 = v4645[v4748];
      int v4805 = v4646 + ((int)((unsigned int)(v4646 - v4642) >> 31));
      v4645[v4748] = v4805;
      int * v4648 = v4569->cache_age;
      v4648[v4773] = 0;
      v4651 = v4773;
    }
    int * v4652 = v4569->cache_vals;
    int v4808 = v4651 * 2;
    int v4653 = v4652[v4808];
    int v4809 = (v4651 * 2) + 1;
    int v4654 = v4652[v4809];
    int v4810 = (((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4593 + ((~(((v4595 ^ -1) | (-(v4595 ^ -1))) >> 31)) & 2)) - (v4596 + ((~(((v4597 ^ -1) | (-(v4597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4652[v4810] = v4653;
    int * v4656 = v4569->cache_vals;
    int v4813 = ((((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4593 + ((~(((v4595 ^ -1) | (-(v4595 ^ -1))) >> 31)) & 2)) - (v4596 + ((~(((v4597 ^ -1) | (-(v4597 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4656[v4813] = v4654;
    int * v4658 = v4569->cache_tags;
    int v4816 = ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4593 + ((~(((v4595 ^ -1) | (-(v4595 ^ -1))) >> 31)) & 2)) - (v4596 + ((~(((v4597 ^ -1) | (-(v4597 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4817 = (int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1);
    v4658[v4816] = v4817;
    int * v4660 = v4569->cache_dirty;
    v4660[v4816] = 0;
    int * v4662 = v4569->cache_age;
    v4662[v4816] = 1;
    int * v4664 = v4569->cache_age;
    int v4665 = v4664[v4816];
    int v4666 = v4664[v4745];
    int v4823 = v4666 + ((int)((unsigned int)(v4666 - v4665) >> 31));
    v4664[v4745] = v4823;
    int * v4668 = v4569->cache_age;
    int v4669 = v4668[v4746];
    int v4825 = v4669 + ((int)((unsigned int)(v4669 - v4665) >> 31));
    v4668[v4746] = v4825;
    int * v4671 = v4569->cache_age;
    v4671[v4816] = 0;
    v4674 = v4816;
  }
  int * v4675 = v4569->cache_vals;
  int v4828 = (v4674 * 2) + (((int)((unsigned int)(v4573 + 8) >> 2)) & 1);
  v4675[v4828] = v4574;
  int * v4677 = v4569->cache_tags;
  int v4678 = v4677[v4747];
  int v4679 = v4677[v4748];
  bool v4831 = !(((~(((v4678 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4678 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4679 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4679 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4733;
  if (v4831) {
    int * v4680 = v4569->cache_age;
    int v4833 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4679 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))) | (-(v4679 ^ ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4681 = v4680[v4833];
    int v4682 = v4680[v4747];
    int v4834 = v4682 + ((int)((unsigned int)(v4682 - v4681) >> 31));
    v4680[v4747] = v4834;
    int * v4684 = v4569->cache_age;
    int v4685 = v4684[v4748];
    int v4836 = v4685 + ((int)((unsigned int)(v4685 - v4681) >> 31));
    v4684[v4748] = v4836;
    int * v4687 = v4569->cache_age;
    v4687[v4833] = 0;
    v4733 = v4833;
  } else {
    int * v4690 = v4569->cache_age;
    int v4840 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2);
    int v4691 = v4690[v4840];
    int * v4692 = v4569->cache_tags;
    int v4693 = v4692[v4840];
    int v4694 = v4690[v4748];
    int v4695 = v4692[v4748];
    int * v4696 = v4569->cache_dirty;
    int v4843 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4691 + ((~(((v4693 ^ -1) | (-(v4693 ^ -1))) >> 31)) & 2)) - (v4694 + ((~(((v4695 ^ -1) | (-(v4695 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4697 = v4696[v4843];
    bool v4844 = !(v4697 == 0);
    if (v4844) {
      int * v4698 = v4569->cache_tags;
      int v4699 = v4698[v4843];
      int * v4700 = v4569->cache_vals;
      int v4847 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4691 + ((~(((v4693 ^ -1) | (-(v4693 ^ -1))) >> 31)) & 2)) - (v4694 + ((~(((v4695 ^ -1) | (-(v4695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4701 = v4700[v4847];
      int v4848 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4691 + ((~(((v4693 ^ -1) | (-(v4693 ^ -1))) >> 31)) & 2)) - (v4694 + ((~(((v4695 ^ -1) | (-(v4695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4702 = v4700[v4848];
      int * v4703 = v4569->mem;
      int v4850 = v4699 * 2;
      v4703[v4850] = v4701;
      int * v4705 = v4569->mem;
      int v4853 = (v4699 * 2) + 1;
      v4705[v4853] = v4702;
      ;
    } else {
      ;
    }
    int * v4710 = v4569->mem;
    int v4858 = ((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) * 2;
    int v4711 = v4710[v4858];
    int v4859 = (((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) * 2) + 1;
    int v4712 = v4710[v4859];
    int * v4713 = v4569->cache_vals;
    int v4861 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4691 + ((~(((v4693 ^ -1) | (-(v4693 ^ -1))) >> 31)) & 2)) - (v4694 + ((~(((v4695 ^ -1) | (-(v4695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4713[v4861] = v4711;
    int * v4715 = v4569->cache_vals;
    int v4864 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4691 + ((~(((v4693 ^ -1) | (-(v4693 ^ -1))) >> 31)) & 2)) - (v4694 + ((~(((v4695 ^ -1) | (-(v4695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4715[v4864] = v4712;
    int * v4717 = v4569->cache_tags;
    int v4867 = (int)((unsigned int)((int)((unsigned int)(v4573 + 8) >> 2)) >> 1);
    v4717[v4843] = v4867;
    int * v4719 = v4569->cache_dirty;
    v4719[v4843] = 0;
    int * v4721 = v4569->cache_age;
    v4721[v4843] = 1;
    int * v4723 = v4569->cache_age;
    int v4724 = v4723[v4843];
    int v4725 = v4723[v4747];
    int v4873 = v4725 + ((int)((unsigned int)(v4725 - v4724) >> 31));
    v4723[v4747] = v4873;
    int * v4727 = v4569->cache_age;
    int v4728 = v4727[v4748];
    int v4875 = v4728 + ((int)((unsigned int)(v4728 - v4724) >> 31));
    v4727[v4748] = v4875;
    int * v4730 = v4569->cache_age;
    v4730[v4843] = 0;
    v4733 = v4843;
  }
  int * v4734 = v4569->cache_vals;
  int v4878 = (v4733 * 2) + (((int)((unsigned int)(v4573 + 8) >> 2)) & 1);
  v4734[v4878] = v4574;
  int * v4736 = v4569->cache_dirty;
  v4736[v4733] = 1;
  struct StateT * v4738 = slot_74(v4569);
  return v4738;
}

struct StateT * slot_568(struct StateT * v26477) {
  int v26478 = v26477->timer;
  int v26486 = v26478 + 1;
  v26477->timer = v26486;
  int * v26480 = v26477->regs;
  int v26481 = v26480[13];
  int v26482 = v26480[28];
  int v26490 = v26481 + v26482;
  v26480[13] = v26490;
  struct StateT * v26484 = slot_634(v26477);
  return v26484;
}

struct StateT * slot_810(struct StateT * v34831) {
  int v34832 = v34831->timer;
  int v34840 = v34832 + 1;
  v34831->timer = v34840;
  int * v34834 = v34831->regs;
  int v34835 = v34834[12];
  int v34836 = v34834[14];
  int v34844 = v34835 + v34836;
  v34834[12] = v34844;
  struct StateT * v34838 = slot_744(v34831);
  return v34838;
}

struct StateT * slot_571(struct StateT * v26534) {
  int v26535 = v26534->timer;
  int v26543 = v26535 + 1;
  v26534->timer = v26543;
  int * v26537 = v26534->regs;
  int v26538 = v26537[31];
  int v26539 = v26537[12];
  int v26547 = v26538 + v26539;
  v26537[12] = v26547;
  struct StateT * v26541 = slot_548(v26534);
  return v26541;
}

struct StateT * slot_142(struct StateT * v7023) {
  int * v7024 = v7023->saved_regs;
  int * v7025 = v7023->regs;
  int v7026 = v7025[28];
  v7024[28] = v7026;
  int v7028 = v7023->timer;
  int v7044 = v7028 + 1;
  v7023->timer = v7044;
  int * v7030 = v7023->regs;
  int v7031 = v7030[7];
  int v7032 = v7030[29];
  bool v7048 = (v7031 ^ -2147483648) < (v7032 ^ -2147483648);
  int v7035;
  if (v7048) {
    v7035 = 1;
  } else {
    v7035 = 0;
  }
  int * v7036 = v7023->regs;
  v7036[28] = v7035;
  struct StateT * v7038 = slot_151(v7023);
  return v7038;
}

struct StateT * slot_416(struct StateT * v23376) {
  int v23377 = v23376->timer;
  int v23385 = v23377 + 1;
  v23376->timer = v23385;
  int * v23379 = v23376->regs;
  int v23380 = v23379[6];
  int v23381 = v23379[13];
  int v23390 = (((((int)((unsigned int)v23380 >> 16)) * ((int)((unsigned int)v23381 >> 16))) + ((int)((unsigned int)((v23380 & 65535) * ((int)((unsigned int)v23381 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v23380 >> 16)) * (v23381 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v23380 & 65535) * (v23381 & 65535)) >> 16)) + (((v23380 & 65535) * ((int)((unsigned int)v23381 >> 16))) & 65535)) + ((((int)((unsigned int)v23380 >> 16)) * (v23381 & 65535)) & 65535)) >> 16));
  v23379[31] = v23390;
  struct StateT * v23383 = slot_452(v23376);
  return v23383;
}

struct StateT * slot_624(struct StateT * v27536) {
  int v27537 = v27536->timer;
  int v27545 = v27537 + 1;
  v27536->timer = v27545;
  int * v27539 = v27536->regs;
  int v27540 = v27539[13];
  int v27541 = v27539[12];
  int v27549 = v27540 + v27541;
  v27539[12] = v27549;
  struct StateT * v27543 = slot_662(v27536);
  return v27543;
}

struct StateT * slot_1038(struct StateT * v54143) {
  int v54144 = v54143->timer;
  int v54314 = v54144 + 1;
  v54143->timer = v54314;
  int * v54146 = v54143->regs;
  int v54147 = v54146[10];
  int v54148 = v54146[11];
  int * v54149 = v54143->cache_tags;
  int v54319 = (((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2;
  int v54150 = v54149[v54319];
  int v54320 = ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v54151 = v54149[v54320];
  int v54321 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2);
  int v54152 = v54149[v54321];
  int v54322 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v54153 = v54149[v54322];
  int v54154 = v54143->timer;
  int v54323 = v54154 + ((100 ^ (((~(((v54152 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54152 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v54150 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54150 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v54151 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54151 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v54152 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54152 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v54143->timer = v54323;
  bool v54324 = !(((~(((v54150 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54150 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v54151 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54151 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v54248;
  if (v54324) {
    int * v54156 = v54143->cache_age;
    int v54326 = ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v54151 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54151 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v54157 = v54156[v54326];
    int v54158 = v54156[v54319];
    int v54327 = v54158 + ((int)((unsigned int)(v54158 - v54157) >> 31));
    v54156[v54319] = v54327;
    int * v54160 = v54143->cache_age;
    int v54161 = v54160[v54320];
    int v54329 = v54161 + ((int)((unsigned int)(v54161 - v54157) >> 31));
    v54160[v54320] = v54329;
    int * v54163 = v54143->cache_age;
    v54163[v54326] = 0;
    v54248 = v54326;
  } else {
    int * v54166 = v54143->cache_age;
    int v54333 = (((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2;
    int v54167 = v54166[v54333];
    int * v54168 = v54143->cache_tags;
    int v54169 = v54168[v54333];
    int v54170 = v54166[v54320];
    int v54171 = v54168[v54320];
    bool v54335 = !(((~(((v54152 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54152 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v54225;
    if (v54335) {
      int * v54172 = v54143->cache_age;
      int v54337 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54153 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v54173 = v54172[v54337];
      int v54174 = v54172[v54321];
      int v54338 = v54174 + ((int)((unsigned int)(v54174 - v54173) >> 31));
      v54172[v54321] = v54338;
      int * v54176 = v54143->cache_age;
      int v54177 = v54176[v54322];
      int v54340 = v54177 + ((int)((unsigned int)(v54177 - v54173) >> 31));
      v54176[v54322] = v54340;
      int * v54179 = v54143->cache_age;
      v54179[v54337] = 0;
      v54225 = v54337;
    } else {
      int * v54182 = v54143->cache_age;
      int v54344 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2);
      int v54183 = v54182[v54344];
      int * v54184 = v54143->cache_tags;
      int v54185 = v54184[v54344];
      int v54186 = v54182[v54322];
      int v54187 = v54184[v54322];
      int * v54188 = v54143->cache_dirty;
      int v54347 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54183 + ((~(((v54185 ^ -1) | (-(v54185 ^ -1))) >> 31)) & 2)) - (v54186 + ((~(((v54187 ^ -1) | (-(v54187 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v54189 = v54188[v54347];
      bool v54348 = !(v54189 == 0);
      if (v54348) {
        int * v54190 = v54143->cache_tags;
        int v54191 = v54190[v54347];
        int * v54192 = v54143->cache_vals;
        int v54351 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54183 + ((~(((v54185 ^ -1) | (-(v54185 ^ -1))) >> 31)) & 2)) - (v54186 + ((~(((v54187 ^ -1) | (-(v54187 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v54193 = v54192[v54351];
        int v54352 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54183 + ((~(((v54185 ^ -1) | (-(v54185 ^ -1))) >> 31)) & 2)) - (v54186 + ((~(((v54187 ^ -1) | (-(v54187 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v54194 = v54192[v54352];
        int * v54195 = v54143->mem;
        int v54354 = v54191 * 2;
        v54195[v54354] = v54193;
        int * v54197 = v54143->mem;
        int v54357 = (v54191 * 2) + 1;
        v54197[v54357] = v54194;
        ;
      } else {
        ;
      }
      int * v54202 = v54143->mem;
      int v54362 = ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) * 2;
      int v54203 = v54202[v54362];
      int v54363 = (((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) * 2) + 1;
      int v54204 = v54202[v54363];
      int * v54205 = v54143->cache_vals;
      int v54365 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54183 + ((~(((v54185 ^ -1) | (-(v54185 ^ -1))) >> 31)) & 2)) - (v54186 + ((~(((v54187 ^ -1) | (-(v54187 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v54205[v54365] = v54203;
      int * v54207 = v54143->cache_vals;
      int v54368 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54183 + ((~(((v54185 ^ -1) | (-(v54185 ^ -1))) >> 31)) & 2)) - (v54186 + ((~(((v54187 ^ -1) | (-(v54187 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v54207[v54368] = v54204;
      int * v54209 = v54143->cache_tags;
      int v54371 = (int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1);
      v54209[v54347] = v54371;
      int * v54211 = v54143->cache_dirty;
      v54211[v54347] = 0;
      int * v54213 = v54143->cache_age;
      v54213[v54347] = 1;
      int * v54215 = v54143->cache_age;
      int v54216 = v54215[v54347];
      int v54217 = v54215[v54321];
      int v54377 = v54217 + ((int)((unsigned int)(v54217 - v54216) >> 31));
      v54215[v54321] = v54377;
      int * v54219 = v54143->cache_age;
      int v54220 = v54219[v54322];
      int v54379 = v54220 + ((int)((unsigned int)(v54220 - v54216) >> 31));
      v54219[v54322] = v54379;
      int * v54222 = v54143->cache_age;
      v54222[v54347] = 0;
      v54225 = v54347;
    }
    int * v54226 = v54143->cache_vals;
    int v54382 = v54225 * 2;
    int v54227 = v54226[v54382];
    int v54383 = (v54225 * 2) + 1;
    int v54228 = v54226[v54383];
    int v54384 = (((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v54167 + ((~(((v54169 ^ -1) | (-(v54169 ^ -1))) >> 31)) & 2)) - (v54170 + ((~(((v54171 ^ -1) | (-(v54171 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v54226[v54384] = v54227;
    int * v54230 = v54143->cache_vals;
    int v54387 = ((((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v54167 + ((~(((v54169 ^ -1) | (-(v54169 ^ -1))) >> 31)) & 2)) - (v54170 + ((~(((v54171 ^ -1) | (-(v54171 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v54230[v54387] = v54228;
    int * v54232 = v54143->cache_tags;
    int v54390 = ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v54167 + ((~(((v54169 ^ -1) | (-(v54169 ^ -1))) >> 31)) & 2)) - (v54170 + ((~(((v54171 ^ -1) | (-(v54171 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v54391 = (int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1);
    v54232[v54390] = v54391;
    int * v54234 = v54143->cache_dirty;
    v54234[v54390] = 0;
    int * v54236 = v54143->cache_age;
    v54236[v54390] = 1;
    int * v54238 = v54143->cache_age;
    int v54239 = v54238[v54390];
    int v54240 = v54238[v54319];
    int v54397 = v54240 + ((int)((unsigned int)(v54240 - v54239) >> 31));
    v54238[v54319] = v54397;
    int * v54242 = v54143->cache_age;
    int v54243 = v54242[v54320];
    int v54399 = v54243 + ((int)((unsigned int)(v54243 - v54239) >> 31));
    v54242[v54320] = v54399;
    int * v54245 = v54143->cache_age;
    v54245[v54390] = 0;
    v54248 = v54390;
  }
  int * v54249 = v54143->cache_vals;
  int v54402 = (v54248 * 2) + (((int)((unsigned int)(v54147 + 32) >> 2)) & 1);
  v54249[v54402] = v54148;
  int * v54251 = v54143->cache_tags;
  int v54252 = v54251[v54321];
  int v54253 = v54251[v54322];
  bool v54405 = !(((~(((v54252 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54252 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v54253 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54253 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v54307;
  if (v54405) {
    int * v54254 = v54143->cache_age;
    int v54407 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v54253 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))) | (-(v54253 ^ ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v54255 = v54254[v54407];
    int v54256 = v54254[v54321];
    int v54408 = v54256 + ((int)((unsigned int)(v54256 - v54255) >> 31));
    v54254[v54321] = v54408;
    int * v54258 = v54143->cache_age;
    int v54259 = v54258[v54322];
    int v54410 = v54259 + ((int)((unsigned int)(v54259 - v54255) >> 31));
    v54258[v54322] = v54410;
    int * v54261 = v54143->cache_age;
    v54261[v54407] = 0;
    v54307 = v54407;
  } else {
    int * v54264 = v54143->cache_age;
    int v54414 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2);
    int v54265 = v54264[v54414];
    int * v54266 = v54143->cache_tags;
    int v54267 = v54266[v54414];
    int v54268 = v54264[v54322];
    int v54269 = v54266[v54322];
    int * v54270 = v54143->cache_dirty;
    int v54417 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54265 + ((~(((v54267 ^ -1) | (-(v54267 ^ -1))) >> 31)) & 2)) - (v54268 + ((~(((v54269 ^ -1) | (-(v54269 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v54271 = v54270[v54417];
    bool v54418 = !(v54271 == 0);
    if (v54418) {
      int * v54272 = v54143->cache_tags;
      int v54273 = v54272[v54417];
      int * v54274 = v54143->cache_vals;
      int v54421 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54265 + ((~(((v54267 ^ -1) | (-(v54267 ^ -1))) >> 31)) & 2)) - (v54268 + ((~(((v54269 ^ -1) | (-(v54269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v54275 = v54274[v54421];
      int v54422 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54265 + ((~(((v54267 ^ -1) | (-(v54267 ^ -1))) >> 31)) & 2)) - (v54268 + ((~(((v54269 ^ -1) | (-(v54269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v54276 = v54274[v54422];
      int * v54277 = v54143->mem;
      int v54424 = v54273 * 2;
      v54277[v54424] = v54275;
      int * v54279 = v54143->mem;
      int v54427 = (v54273 * 2) + 1;
      v54279[v54427] = v54276;
      ;
    } else {
      ;
    }
    int * v54284 = v54143->mem;
    int v54432 = ((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) * 2;
    int v54285 = v54284[v54432];
    int v54433 = (((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) * 2) + 1;
    int v54286 = v54284[v54433];
    int * v54287 = v54143->cache_vals;
    int v54435 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54265 + ((~(((v54267 ^ -1) | (-(v54267 ^ -1))) >> 31)) & 2)) - (v54268 + ((~(((v54269 ^ -1) | (-(v54269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v54287[v54435] = v54285;
    int * v54289 = v54143->cache_vals;
    int v54438 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v54265 + ((~(((v54267 ^ -1) | (-(v54267 ^ -1))) >> 31)) & 2)) - (v54268 + ((~(((v54269 ^ -1) | (-(v54269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v54289[v54438] = v54286;
    int * v54291 = v54143->cache_tags;
    int v54441 = (int)((unsigned int)((int)((unsigned int)(v54147 + 32) >> 2)) >> 1);
    v54291[v54417] = v54441;
    int * v54293 = v54143->cache_dirty;
    v54293[v54417] = 0;
    int * v54295 = v54143->cache_age;
    v54295[v54417] = 1;
    int * v54297 = v54143->cache_age;
    int v54298 = v54297[v54417];
    int v54299 = v54297[v54321];
    int v54447 = v54299 + ((int)((unsigned int)(v54299 - v54298) >> 31));
    v54297[v54321] = v54447;
    int * v54301 = v54143->cache_age;
    int v54302 = v54301[v54322];
    int v54449 = v54302 + ((int)((unsigned int)(v54302 - v54298) >> 31));
    v54301[v54322] = v54449;
    int * v54304 = v54143->cache_age;
    v54304[v54417] = 0;
    v54307 = v54417;
  }
  int * v54308 = v54143->cache_vals;
  int v54452 = (v54307 * 2) + (((int)((unsigned int)(v54147 + 32) >> 2)) & 1);
  v54308[v54452] = v54148;
  int * v54310 = v54143->cache_dirty;
  v54310[v54307] = 1;
  struct StateT * v54312 = slot_1016(v54143);
  return v54312;
}

struct StateT * slot_738(struct StateT * v29641) {
  int v29642 = v29641->timer;
  int v29650 = v29642 + 1;
  v29641->timer = v29650;
  int * v29644 = v29641->regs;
  int v29645 = v29644[13];
  int v29646 = v29644[17];
  int v29655 = (((((int)((unsigned int)v29645 >> 16)) * ((int)((unsigned int)v29646 >> 16))) + ((int)((unsigned int)((v29645 & 65535) * ((int)((unsigned int)v29646 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v29645 >> 16)) * (v29646 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v29645 & 65535) * (v29646 & 65535)) >> 16)) + (((v29645 & 65535) * ((int)((unsigned int)v29646 >> 16))) & 65535)) + ((((int)((unsigned int)v29645 >> 16)) * (v29646 & 65535)) & 65535)) >> 16));
  v29644[5] = v29655;
  struct StateT * v29648 = slot_749(v29641);
  return v29648;
}

struct StateT * slot_214(struct StateT * v12228) {
  int v12229 = v12228->timer;
  int v12237 = v12229 + 1;
  v12228->timer = v12237;
  int * v12231 = v12228->regs;
  int v12232 = v12231[29];
  int v12233 = v12231[12];
  int v12242 = (((((int)((unsigned int)v12232 >> 16)) * ((int)((unsigned int)v12233 >> 16))) + ((int)((unsigned int)((v12232 & 65535) * ((int)((unsigned int)v12233 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v12232 >> 16)) * (v12233 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v12232 & 65535) * (v12233 & 65535)) >> 16)) + (((v12232 & 65535) * ((int)((unsigned int)v12233 >> 16))) & 65535)) + ((((int)((unsigned int)v12232 >> 16)) * (v12233 & 65535)) & 65535)) >> 16));
  v12231[30] = v12242;
  struct StateT * v12235 = slot_219(v12228);
  return v12235;
}

struct StateT * slot_29(struct StateT * v2841) {
  int v2842 = v2841->timer;
  int v2952 = v2842 + 1;
  v2841->timer = v2952;
  int * v2844 = v2841->regs;
  int v2845 = v2844[11];
  int * v2846 = v2841->cache_tags;
  int v2956 = (((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2847 = v2846[v2956];
  int v2957 = ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2848 = v2846[v2957];
  int v2958 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2849 = v2846[v2958];
  int v2959 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2850 = v2846[v2959];
  int v2851 = v2841->timer;
  int v2960 = v2851 + ((100 ^ (((~(((v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2841->timer = v2960;
  int * v2853 = v2841->cache_vals;
  bool v2961 = !(((~(((v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2847 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2946;
  if (v2961) {
    int * v2854 = v2841->cache_age;
    int v2963 = ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2848 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2855 = v2854[v2963];
    int v2856 = v2854[v2956];
    int v2964 = v2856 + ((int)((unsigned int)(v2856 - v2855) >> 31));
    v2854[v2956] = v2964;
    int * v2858 = v2841->cache_age;
    int v2859 = v2858[v2957];
    int v2966 = v2859 + ((int)((unsigned int)(v2859 - v2855) >> 31));
    v2858[v2957] = v2966;
    int * v2861 = v2841->cache_age;
    v2861[v2963] = 0;
    v2946 = v2963;
  } else {
    int * v2864 = v2841->cache_age;
    int v2970 = (((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2865 = v2864[v2970];
    int * v2866 = v2841->cache_tags;
    int v2867 = v2866[v2970];
    int v2868 = v2864[v2957];
    int v2869 = v2866[v2957];
    bool v2972 = !(((~(((v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2849 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v2923;
    if (v2972) {
      int * v2870 = v2841->cache_age;
      int v2974 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))) | (-(v2850 ^ ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2871 = v2870[v2974];
      int v2872 = v2870[v2958];
      int v2975 = v2872 + ((int)((unsigned int)(v2872 - v2871) >> 31));
      v2870[v2958] = v2975;
      int * v2874 = v2841->cache_age;
      int v2875 = v2874[v2959];
      int v2977 = v2875 + ((int)((unsigned int)(v2875 - v2871) >> 31));
      v2874[v2959] = v2977;
      int * v2877 = v2841->cache_age;
      v2877[v2974] = 0;
      v2923 = v2974;
    } else {
      int * v2880 = v2841->cache_age;
      int v2981 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2);
      int v2881 = v2880[v2981];
      int * v2882 = v2841->cache_tags;
      int v2883 = v2882[v2981];
      int v2884 = v2880[v2959];
      int v2885 = v2882[v2959];
      int * v2886 = v2841->cache_dirty;
      int v2984 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2887 = v2886[v2984];
      bool v2985 = !(v2887 == 0);
      if (v2985) {
        int * v2888 = v2841->cache_tags;
        int v2889 = v2888[v2984];
        int * v2890 = v2841->cache_vals;
        int v2988 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2891 = v2890[v2988];
        int v2989 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2892 = v2890[v2989];
        int * v2893 = v2841->mem;
        int v2991 = v2889 * 2;
        v2893[v2991] = v2891;
        int * v2895 = v2841->mem;
        int v2994 = (v2889 * 2) + 1;
        v2895[v2994] = v2892;
        ;
      } else {
        ;
      }
      int * v2900 = v2841->mem;
      int v2999 = ((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) * 2;
      int v2901 = v2900[v2999];
      int v3000 = (((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) * 2) + 1;
      int v2902 = v2900[v3000];
      int * v2903 = v2841->cache_vals;
      int v3002 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2903[v3002] = v2901;
      int * v2905 = v2841->cache_vals;
      int v3005 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2881 + ((~(((v2883 ^ -1) | (-(v2883 ^ -1))) >> 31)) & 2)) - (v2884 + ((~(((v2885 ^ -1) | (-(v2885 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2905[v3005] = v2902;
      int * v2907 = v2841->cache_tags;
      int v3008 = (int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1);
      v2907[v2984] = v3008;
      int * v2909 = v2841->cache_dirty;
      v2909[v2984] = 0;
      int * v2911 = v2841->cache_age;
      v2911[v2984] = 1;
      int * v2913 = v2841->cache_age;
      int v2914 = v2913[v2984];
      int v2915 = v2913[v2958];
      int v3014 = v2915 + ((int)((unsigned int)(v2915 - v2914) >> 31));
      v2913[v2958] = v3014;
      int * v2917 = v2841->cache_age;
      int v2918 = v2917[v2959];
      int v3016 = v2918 + ((int)((unsigned int)(v2918 - v2914) >> 31));
      v2917[v2959] = v3016;
      int * v2920 = v2841->cache_age;
      v2920[v2984] = 0;
      v2923 = v2984;
    }
    int * v2924 = v2841->cache_vals;
    int v3019 = v2923 * 2;
    int v2925 = v2924[v3019];
    int v3020 = (v2923 * 2) + 1;
    int v2926 = v2924[v3020];
    int v3021 = (((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2865 + ((~(((v2867 ^ -1) | (-(v2867 ^ -1))) >> 31)) & 2)) - (v2868 + ((~(((v2869 ^ -1) | (-(v2869 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2924[v3021] = v2925;
    int * v2928 = v2841->cache_vals;
    int v3024 = ((((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2865 + ((~(((v2867 ^ -1) | (-(v2867 ^ -1))) >> 31)) & 2)) - (v2868 + ((~(((v2869 ^ -1) | (-(v2869 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2928[v3024] = v2926;
    int * v2930 = v2841->cache_tags;
    int v3027 = ((((int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2865 + ((~(((v2867 ^ -1) | (-(v2867 ^ -1))) >> 31)) & 2)) - (v2868 + ((~(((v2869 ^ -1) | (-(v2869 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3028 = (int)((unsigned int)((int)((unsigned int)(v2845 + 12) >> 2)) >> 1);
    v2930[v3027] = v3028;
    int * v2932 = v2841->cache_dirty;
    v2932[v3027] = 0;
    int * v2934 = v2841->cache_age;
    v2934[v3027] = 1;
    int * v2936 = v2841->cache_age;
    int v2937 = v2936[v3027];
    int v2938 = v2936[v2956];
    int v3034 = v2938 + ((int)((unsigned int)(v2938 - v2937) >> 31));
    v2936[v2956] = v3034;
    int * v2940 = v2841->cache_age;
    int v2941 = v2940[v2957];
    int v3036 = v2941 + ((int)((unsigned int)(v2941 - v2937) >> 31));
    v2940[v2957] = v3036;
    int * v2943 = v2841->cache_age;
    v2943[v3027] = 0;
    v2946 = v3027;
  }
  int v3039 = (v2946 * 2) + (((int)((unsigned int)(v2845 + 12) >> 2)) & 1);
  int v2947 = v2853[v3039];
  int * v2948 = v2841->regs;
  v2948[28] = v2947;
  struct StateT * v2950 = slot_30(v2841);
  return v2950;
}

struct StateT * slot_151(struct StateT * v7220) {
  int v7221 = v7220->timer;
  int v7229 = v7221 + 1;
  v7220->timer = v7229;
  int * v7223 = v7220->regs;
  int v7224 = v7223[5];
  int v7225 = v7223[28];
  int v7233 = v7224 + v7225;
  v7223[28] = v7233;
  struct StateT * v7227 = slot_146(v7220);
  return v7227;
}

struct StateT * slot_7(struct StateT * v1684) {
  int v1685 = v1684->timer;
  int v1691 = v1685 + 1;
  v1684->timer = v1691;
  int * v1687 = v1684->regs;
  v1687[16] = 524288;
  struct StateT * v1689 = slot_8(v1684);
  return v1689;
}

struct StateT * slot_124(struct StateT * v6696) {
  int v6697 = v6696->timer;
  int v6705 = v6697 + 1;
  v6696->timer = v6705;
  int * v6699 = v6696->regs;
  int v6700 = v6699[8];
  int v6701 = v6699[6];
  int v6709 = v6700 + v6701;
  v6699[6] = v6709;
  struct StateT * v6703 = slot_126(v6696);
  return v6703;
}

struct StateT * slot_128(struct StateT * v6769) {
  int v6770 = v6769->timer;
  int v6778 = v6770 + 1;
  v6769->timer = v6778;
  int * v6772 = v6769->regs;
  int v6773 = v6772[9];
  int v6774 = v6772[6];
  int v6783 = v6773 + v6774;
  v6772[5] = v6783;
  struct StateT * v6776 = slot_130(v6769);
  return v6776;
}

struct StateT * slot_365(struct StateT * v18520) {
  int v18521 = v18520->timer;
  int v18691 = v18521 + 1;
  v18520->timer = v18691;
  int * v18523 = v18520->regs;
  int v18524 = v18523[10];
  int v18525 = v18523[17];
  int * v18526 = v18520->cache_tags;
  int v18696 = (((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2;
  int v18527 = v18526[v18696];
  int v18697 = ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18528 = v18526[v18697];
  int v18698 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2);
  int v18529 = v18526[v18698];
  int v18699 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18530 = v18526[v18699];
  int v18531 = v18520->timer;
  int v18700 = v18531 + ((100 ^ (((~(((v18529 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18529 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18527 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18527 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18528 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18528 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18529 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18529 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18520->timer = v18700;
  bool v18701 = !(((~(((v18527 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18527 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18528 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18528 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v18625;
  if (v18701) {
    int * v18533 = v18520->cache_age;
    int v18703 = ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v18528 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18528 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v18534 = v18533[v18703];
    int v18535 = v18533[v18696];
    int v18704 = v18535 + ((int)((unsigned int)(v18535 - v18534) >> 31));
    v18533[v18696] = v18704;
    int * v18537 = v18520->cache_age;
    int v18538 = v18537[v18697];
    int v18706 = v18538 + ((int)((unsigned int)(v18538 - v18534) >> 31));
    v18537[v18697] = v18706;
    int * v18540 = v18520->cache_age;
    v18540[v18703] = 0;
    v18625 = v18703;
  } else {
    int * v18543 = v18520->cache_age;
    int v18710 = (((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2;
    int v18544 = v18543[v18710];
    int * v18545 = v18520->cache_tags;
    int v18546 = v18545[v18710];
    int v18547 = v18543[v18697];
    int v18548 = v18545[v18697];
    bool v18712 = !(((~(((v18529 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18529 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v18602;
    if (v18712) {
      int * v18549 = v18520->cache_age;
      int v18714 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18530 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v18550 = v18549[v18714];
      int v18551 = v18549[v18698];
      int v18715 = v18551 + ((int)((unsigned int)(v18551 - v18550) >> 31));
      v18549[v18698] = v18715;
      int * v18553 = v18520->cache_age;
      int v18554 = v18553[v18699];
      int v18717 = v18554 + ((int)((unsigned int)(v18554 - v18550) >> 31));
      v18553[v18699] = v18717;
      int * v18556 = v18520->cache_age;
      v18556[v18714] = 0;
      v18602 = v18714;
    } else {
      int * v18559 = v18520->cache_age;
      int v18721 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2);
      int v18560 = v18559[v18721];
      int * v18561 = v18520->cache_tags;
      int v18562 = v18561[v18721];
      int v18563 = v18559[v18699];
      int v18564 = v18561[v18699];
      int * v18565 = v18520->cache_dirty;
      int v18724 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18560 + ((~(((v18562 ^ -1) | (-(v18562 ^ -1))) >> 31)) & 2)) - (v18563 + ((~(((v18564 ^ -1) | (-(v18564 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18566 = v18565[v18724];
      bool v18725 = !(v18566 == 0);
      if (v18725) {
        int * v18567 = v18520->cache_tags;
        int v18568 = v18567[v18724];
        int * v18569 = v18520->cache_vals;
        int v18728 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18560 + ((~(((v18562 ^ -1) | (-(v18562 ^ -1))) >> 31)) & 2)) - (v18563 + ((~(((v18564 ^ -1) | (-(v18564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18570 = v18569[v18728];
        int v18729 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18560 + ((~(((v18562 ^ -1) | (-(v18562 ^ -1))) >> 31)) & 2)) - (v18563 + ((~(((v18564 ^ -1) | (-(v18564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18571 = v18569[v18729];
        int * v18572 = v18520->mem;
        int v18731 = v18568 * 2;
        v18572[v18731] = v18570;
        int * v18574 = v18520->mem;
        int v18734 = (v18568 * 2) + 1;
        v18574[v18734] = v18571;
        ;
      } else {
        ;
      }
      int * v18579 = v18520->mem;
      int v18739 = ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) * 2;
      int v18580 = v18579[v18739];
      int v18740 = (((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) * 2) + 1;
      int v18581 = v18579[v18740];
      int * v18582 = v18520->cache_vals;
      int v18742 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18560 + ((~(((v18562 ^ -1) | (-(v18562 ^ -1))) >> 31)) & 2)) - (v18563 + ((~(((v18564 ^ -1) | (-(v18564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18582[v18742] = v18580;
      int * v18584 = v18520->cache_vals;
      int v18745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18560 + ((~(((v18562 ^ -1) | (-(v18562 ^ -1))) >> 31)) & 2)) - (v18563 + ((~(((v18564 ^ -1) | (-(v18564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18584[v18745] = v18581;
      int * v18586 = v18520->cache_tags;
      int v18748 = (int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1);
      v18586[v18724] = v18748;
      int * v18588 = v18520->cache_dirty;
      v18588[v18724] = 0;
      int * v18590 = v18520->cache_age;
      v18590[v18724] = 1;
      int * v18592 = v18520->cache_age;
      int v18593 = v18592[v18724];
      int v18594 = v18592[v18698];
      int v18754 = v18594 + ((int)((unsigned int)(v18594 - v18593) >> 31));
      v18592[v18698] = v18754;
      int * v18596 = v18520->cache_age;
      int v18597 = v18596[v18699];
      int v18756 = v18597 + ((int)((unsigned int)(v18597 - v18593) >> 31));
      v18596[v18699] = v18756;
      int * v18599 = v18520->cache_age;
      v18599[v18724] = 0;
      v18602 = v18724;
    }
    int * v18603 = v18520->cache_vals;
    int v18759 = v18602 * 2;
    int v18604 = v18603[v18759];
    int v18760 = (v18602 * 2) + 1;
    int v18605 = v18603[v18760];
    int v18761 = (((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v18544 + ((~(((v18546 ^ -1) | (-(v18546 ^ -1))) >> 31)) & 2)) - (v18547 + ((~(((v18548 ^ -1) | (-(v18548 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18603[v18761] = v18604;
    int * v18607 = v18520->cache_vals;
    int v18764 = ((((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v18544 + ((~(((v18546 ^ -1) | (-(v18546 ^ -1))) >> 31)) & 2)) - (v18547 + ((~(((v18548 ^ -1) | (-(v18548 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18607[v18764] = v18605;
    int * v18609 = v18520->cache_tags;
    int v18767 = ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v18544 + ((~(((v18546 ^ -1) | (-(v18546 ^ -1))) >> 31)) & 2)) - (v18547 + ((~(((v18548 ^ -1) | (-(v18548 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18768 = (int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1);
    v18609[v18767] = v18768;
    int * v18611 = v18520->cache_dirty;
    v18611[v18767] = 0;
    int * v18613 = v18520->cache_age;
    v18613[v18767] = 1;
    int * v18615 = v18520->cache_age;
    int v18616 = v18615[v18767];
    int v18617 = v18615[v18696];
    int v18774 = v18617 + ((int)((unsigned int)(v18617 - v18616) >> 31));
    v18615[v18696] = v18774;
    int * v18619 = v18520->cache_age;
    int v18620 = v18619[v18697];
    int v18776 = v18620 + ((int)((unsigned int)(v18620 - v18616) >> 31));
    v18619[v18697] = v18776;
    int * v18622 = v18520->cache_age;
    v18622[v18767] = 0;
    v18625 = v18767;
  }
  int * v18626 = v18520->cache_vals;
  int v18779 = (v18625 * 2) + (((int)((unsigned int)(v18524 + 24) >> 2)) & 1);
  v18626[v18779] = v18525;
  int * v18628 = v18520->cache_tags;
  int v18629 = v18628[v18698];
  int v18630 = v18628[v18699];
  bool v18782 = !(((~(((v18629 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18629 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v18630 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18630 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v18684;
  if (v18782) {
    int * v18631 = v18520->cache_age;
    int v18784 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18630 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))) | (-(v18630 ^ ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v18632 = v18631[v18784];
    int v18633 = v18631[v18698];
    int v18785 = v18633 + ((int)((unsigned int)(v18633 - v18632) >> 31));
    v18631[v18698] = v18785;
    int * v18635 = v18520->cache_age;
    int v18636 = v18635[v18699];
    int v18787 = v18636 + ((int)((unsigned int)(v18636 - v18632) >> 31));
    v18635[v18699] = v18787;
    int * v18638 = v18520->cache_age;
    v18638[v18784] = 0;
    v18684 = v18784;
  } else {
    int * v18641 = v18520->cache_age;
    int v18791 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2);
    int v18642 = v18641[v18791];
    int * v18643 = v18520->cache_tags;
    int v18644 = v18643[v18791];
    int v18645 = v18641[v18699];
    int v18646 = v18643[v18699];
    int * v18647 = v18520->cache_dirty;
    int v18794 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18642 + ((~(((v18644 ^ -1) | (-(v18644 ^ -1))) >> 31)) & 2)) - (v18645 + ((~(((v18646 ^ -1) | (-(v18646 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18648 = v18647[v18794];
    bool v18795 = !(v18648 == 0);
    if (v18795) {
      int * v18649 = v18520->cache_tags;
      int v18650 = v18649[v18794];
      int * v18651 = v18520->cache_vals;
      int v18798 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18642 + ((~(((v18644 ^ -1) | (-(v18644 ^ -1))) >> 31)) & 2)) - (v18645 + ((~(((v18646 ^ -1) | (-(v18646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v18652 = v18651[v18798];
      int v18799 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18642 + ((~(((v18644 ^ -1) | (-(v18644 ^ -1))) >> 31)) & 2)) - (v18645 + ((~(((v18646 ^ -1) | (-(v18646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v18653 = v18651[v18799];
      int * v18654 = v18520->mem;
      int v18801 = v18650 * 2;
      v18654[v18801] = v18652;
      int * v18656 = v18520->mem;
      int v18804 = (v18650 * 2) + 1;
      v18656[v18804] = v18653;
      ;
    } else {
      ;
    }
    int * v18661 = v18520->mem;
    int v18809 = ((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) * 2;
    int v18662 = v18661[v18809];
    int v18810 = (((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) * 2) + 1;
    int v18663 = v18661[v18810];
    int * v18664 = v18520->cache_vals;
    int v18812 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18642 + ((~(((v18644 ^ -1) | (-(v18644 ^ -1))) >> 31)) & 2)) - (v18645 + ((~(((v18646 ^ -1) | (-(v18646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18664[v18812] = v18662;
    int * v18666 = v18520->cache_vals;
    int v18815 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v18642 + ((~(((v18644 ^ -1) | (-(v18644 ^ -1))) >> 31)) & 2)) - (v18645 + ((~(((v18646 ^ -1) | (-(v18646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18666[v18815] = v18663;
    int * v18668 = v18520->cache_tags;
    int v18818 = (int)((unsigned int)((int)((unsigned int)(v18524 + 24) >> 2)) >> 1);
    v18668[v18794] = v18818;
    int * v18670 = v18520->cache_dirty;
    v18670[v18794] = 0;
    int * v18672 = v18520->cache_age;
    v18672[v18794] = 1;
    int * v18674 = v18520->cache_age;
    int v18675 = v18674[v18794];
    int v18676 = v18674[v18698];
    int v18824 = v18676 + ((int)((unsigned int)(v18676 - v18675) >> 31));
    v18674[v18698] = v18824;
    int * v18678 = v18520->cache_age;
    int v18679 = v18678[v18699];
    int v18826 = v18679 + ((int)((unsigned int)(v18679 - v18675) >> 31));
    v18678[v18699] = v18826;
    int * v18681 = v18520->cache_age;
    v18681[v18794] = 0;
    v18684 = v18794;
  }
  int * v18685 = v18520->cache_vals;
  int v18829 = (v18684 * 2) + (((int)((unsigned int)(v18524 + 24) >> 2)) & 1);
  v18685[v18829] = v18525;
  int * v18687 = v18520->cache_dirty;
  v18687[v18684] = 1;
  struct StateT * v18689 = slot_373(v18520);
  return v18689;
}

struct StateT * slot_1025(struct StateT * v52527) {
  int v52528 = v52527->timer;
  int v52536 = v52528 + 1;
  v52527->timer = v52536;
  int * v52530 = v52527->regs;
  int v52531 = v52530[13];
  int v52532 = v52530[17];
  int v52540 = v52531 * v52532;
  v52530[13] = v52540;
  struct StateT * v52534 = slot_1033(v52527);
  return v52534;
}

struct StateT * slot_622(struct StateT * v27504) {
  int v27505 = v27504->timer;
  int v27513 = v27505 + 1;
  v27504->timer = v27513;
  int * v27507 = v27504->regs;
  int v27508 = v27507[12];
  int v27509 = v27507[5];
  int v27517 = v27508 + v27509;
  v27507[5] = v27517;
  struct StateT * v27511 = slot_628(v27504);
  return v27511;
}

struct StateT * slot_523(struct StateT * v25596) {
  int v25597 = v25596->timer;
  int v25609 = v25597 + 1;
  v25596->timer = v25609;
  int * v25599 = v25596->regs;
  int v25600 = v25599[5];
  int v25601 = v25599[28];
  bool v25613 = (v25600 ^ -2147483648) < (v25601 ^ -2147483648);
  int v25604;
  if (v25613) {
    v25604 = 1;
  } else {
    v25604 = 0;
  }
  int * v25605 = v25596->regs;
  v25605[7] = v25604;
  struct StateT * v25607 = slot_502(v25596);
  return v25607;
}

struct StateT * slot_782(struct StateT * v31865) {
  int * v31866 = v31865->saved_regs;
  int * v31867 = v31865->regs;
  int v31868 = v31867[14];
  v31866[14] = v31868;
  int v31870 = v31865->timer;
  int v31886 = v31870 + 1;
  v31865->timer = v31886;
  int * v31872 = v31865->regs;
  int v31873 = v31872[13];
  int v31874 = v31872[14];
  bool v31889 = (v31873 ^ -2147483648) < (v31874 ^ -2147483648);
  int v31877;
  if (v31889) {
    v31877 = 1;
  } else {
    v31877 = 0;
  }
  int * v31878 = v31865->regs;
  v31878[14] = v31877;
  struct StateT * v31880 = slot_794(v31865);
  return v31880;
}

struct StateT * slot_87(struct StateT * v5668) {
  int v5669 = v5668->timer;
  int v5677 = v5669 + 1;
  v5668->timer = v5677;
  int * v5671 = v5668->regs;
  int v5672 = v5671[6];
  int v5673 = v5671[5];
  int v5681 = v5672 + v5673;
  v5671[5] = v5681;
  struct StateT * v5675 = slot_89(v5668);
  return v5675;
}

struct StateT * slot_452(struct StateT * v24338) {
  int v24339 = v24338->timer;
  int v24347 = v24339 + 1;
  v24338->timer = v24347;
  int * v24341 = v24338->regs;
  int v24342 = v24341[11];
  int v24343 = v24341[13];
  int v24352 = v24342 * v24343;
  v24341[8] = v24352;
  struct StateT * v24345 = slot_490(v24338);
  return v24345;
}

struct StateT * slot_67(struct StateT * v3711) {
  int * v3712 = v3711->saved_regs;
  int * v3713 = v3711->regs;
  int v3714 = v3713[29];
  v3712[29] = v3714;
  int v3716 = v3711->timer;
  int v3728 = v3716 + 1;
  v3711->timer = v3728;
  int * v3718 = v3711->regs;
  int v3719 = v3718[7];
  int v3720 = v3718[16];
  int v3732 = v3719 & v3720;
  v3718[29] = v3732;
  struct StateT * v3722 = slot_68(v3711);
  return v3722;
}

struct StateT * slot_591(struct StateT * v26904) {
  int v26905 = v26904->timer;
  int v26913 = v26905 + 1;
  v26904->timer = v26913;
  int * v26907 = v26904->regs;
  int v26908 = v26907[17];
  int v26909 = v26907[5];
  int v26917 = v26908 + v26909;
  v26907[17] = v26917;
  struct StateT * v26911 = slot_568(v26904);
  return v26911;
}

struct StateT * slot_546(struct StateT * v26058) {
  int v26059 = v26058->timer;
  int v26067 = v26059 + 1;
  v26058->timer = v26067;
  int * v26061 = v26058->regs;
  int v26062 = v26061[29];
  int v26063 = v26061[7];
  int v26071 = v26062 + v26063;
  v26061[7] = v26071;
  struct StateT * v26065 = slot_585(v26058);
  return v26065;
}

struct StateT * slot_933(struct StateT * v47257) {
  int v47258 = v47257->timer;
  int v47270 = v47258 + 1;
  v47257->timer = v47270;
  int * v47260 = v47257->regs;
  int v47261 = v47260[5];
  int v47262 = v47260[12];
  bool v47274 = (v47261 ^ -2147483648) < (v47262 ^ -2147483648);
  int v47265;
  if (v47274) {
    v47265 = 1;
  } else {
    v47265 = 0;
  }
  int * v47266 = v47257->regs;
  v47266[12] = v47265;
  struct StateT * v47268 = slot_838(v47257);
  return v47268;
}

struct StateT * slot_1033(struct StateT * v53764) {
  int v53765 = v53764->timer;
  int v53773 = v53765 + 1;
  v53764->timer = v53773;
  int * v53767 = v53764->regs;
  int v53768 = v53767[15];
  int v53769 = v53767[5];
  int v53777 = v53768 + v53769;
  v53767[15] = v53777;
  struct StateT * v53771 = slot_979(v53764);
  return v53771;
}

struct StateT * slot_32(struct StateT * v3086) {
  int v3087 = v3086->timer;
  int v3099 = v3087 + 1;
  v3086->timer = v3099;
  int * v3089 = v3086->regs;
  int v3090 = v3089[31];
  int v3091 = v3089[29];
  bool v3103 = (v3090 ^ -2147483648) < (v3091 ^ -2147483648);
  int v3094;
  if (v3103) {
    v3094 = 1;
  } else {
    v3094 = 0;
  }
  int * v3095 = v3086->regs;
  v3095[6] = v3094;
  struct StateT * v3097 = slot_33(v3086);
  return v3097;
}

struct StateT * slot_189(struct StateT * v11075) {
  int v11076 = v11075->timer;
  int v11083 = v11076 + 1;
  v11075->timer = v11083;
  int * v11078 = v11075->regs;
  int v11079 = v11078[28];
  int v11087 = (int)((unsigned int)v11079 >> 19);
  v11078[17] = v11087;
  struct StateT * v11081 = slot_178(v11075);
  return v11081;
}

struct StateT * slot_394(struct StateT * v21602) {
  int v21603 = v21602->timer;
  int v21611 = v21603 + 1;
  v21602->timer = v21611;
  int * v21605 = v21602->regs;
  int v21606 = v21605[6];
  int v21607 = v21605[5];
  int v21615 = v21606 + v21607;
  v21605[5] = v21615;
  struct StateT * v21609 = slot_372(v21602);
  return v21609;
}

struct StateT * slot_33(struct StateT * v3111) {
  int v3112 = v3111->timer;
  int v3120 = v3112 + 1;
  v3111->timer = v3120;
  int * v3114 = v3111->regs;
  int v3115 = v3114[30];
  int v3116 = v3114[5];
  int v3124 = v3115 + v3116;
  v3114[5] = v3124;
  struct StateT * v3118 = slot_34(v3111);
  return v3118;
}

struct StateT * slot_743(struct StateT * v29724) {
  int v29725 = v29724->timer;
  int v29733 = v29725 + 1;
  v29724->timer = v29733;
  int * v29727 = v29724->regs;
  int v29728 = v29727[12];
  int v29729 = v29727[17];
  int v29737 = v29728 * v29729;
  v29727[12] = v29737;
  struct StateT * v29731 = slot_782(v29724);
  return v29731;
}

struct StateT * slot_935(struct StateT * v47596) {
  int v47597 = v47596->timer;
  int v47603 = v47597 + 1;
  v47596->timer = v47603;
  int * v47599 = v47596->regs;
  v47599[17] = 19;
  struct StateT * v47601 = slot_900(v47596);
  return v47601;
}

struct StateT * slot_709(struct StateT * v29151) {
  int v29152 = v29151->timer;
  int v29158 = v29152 + 1;
  v29151->timer = v29158;
  int * v29154 = v29151->regs;
  v29154[17] = 19;
  struct StateT * v29156 = slot_745(v29151);
  return v29156;
}

struct StateT * slot_35(struct StateT * v3142) {
  int v3143 = v3142->timer;
  int v3150 = v3143 + 1;
  v3142->timer = v3150;
  int * v3145 = v3142->regs;
  int v3146 = v3145[31];
  int v3153 = v3146 << 13;
  v3145[31] = v3153;
  struct StateT * v3148 = slot_36(v3142);
  return v3148;
}

struct StateT * slot_258(struct StateT * v13022) {
  int v13023 = v13022->timer;
  int v13031 = v13023 + 1;
  v13022->timer = v13031;
  int * v13025 = v13022->regs;
  int v13026 = v13025[30];
  int v13027 = v13025[7];
  int v13035 = v13026 + v13027;
  v13025[7] = v13035;
  struct StateT * v13029 = slot_262(v13022);
  return v13029;
}

struct StateT * slot_744(struct StateT * v29740) {
  int * v29741 = v29740->saved_regs;
  int v29742 = v29741[17];
  int * v29743 = v29740->regs;
  int v29744 = v29743[6];
  bool v29785 = v29742 == v29744;
  struct StateT * v29779;
  if (v29785) {
    int v29745 = v29740->timer;
    int v29786 = v29745 + 15;
    v29740->timer = v29786;
    int * v29747 = v29740->saved_regs;
    int v29748 = v29747[5];
    int * v29749 = v29740->regs;
    v29749[5] = v29748;
    int * v29751 = v29740->saved_regs;
    int v29752 = v29751[16];
    int * v29753 = v29740->regs;
    v29753[16] = v29752;
    int * v29755 = v29740->saved_regs;
    int v29756 = v29755[17];
    int * v29757 = v29740->regs;
    v29757[17] = v29756;
    int * v29759 = v29740->saved_regs;
    int v29760 = v29759[12];
    int * v29761 = v29740->regs;
    v29761[12] = v29760;
    int * v29763 = v29740->saved_regs;
    int v29764 = v29763[13];
    int * v29765 = v29740->regs;
    v29765[13] = v29764;
    int * v29767 = v29740->saved_regs;
    int v29768 = v29767[15];
    int * v29769 = v29740->regs;
    v29769[15] = v29768;
    int * v29771 = v29740->saved_regs;
    int v29772 = v29771[14];
    int * v29773 = v29740->regs;
    v29773[14] = v29772;
    struct StateT * v29775 = slot_784(v29740);
    v29779 = v29775;
  } else {
    struct StateT * v29777 = slot_1022(v29740);
    v29779 = v29777;
  }
  return v29779;
}

struct StateT * slot_615(struct StateT * v27360) {
  int * v27361 = v27360->saved_regs;
  int * v27362 = v27360->regs;
  int v27363 = v27362[5];
  v27361[5] = v27363;
  int v27365 = v27360->timer;
  int v27381 = v27365 + 1;
  v27360->timer = v27381;
  int * v27367 = v27360->regs;
  int v27368 = v27367[17];
  int v27369 = v27367[6];
  bool v27385 = (v27368 ^ -2147483648) < (v27369 ^ -2147483648);
  int v27372;
  if (v27385) {
    v27372 = 1;
  } else {
    v27372 = 0;
  }
  int * v27373 = v27360->regs;
  v27373[5] = v27372;
  struct StateT * v27375 = slot_622(v27360);
  return v27375;
}

struct StateT * slot_51(struct StateT * v3409) {
  int v3410 = v3409->timer;
  int v3418 = v3410 + 1;
  v3409->timer = v3418;
  int * v3412 = v3409->regs;
  int v3413 = v3412[8];
  int v3414 = v3412[6];
  int v3423 = v3413 + v3414;
  v3412[29] = v3423;
  struct StateT * v3416 = slot_52(v3409);
  return v3416;
}

struct StateT * slot_25(struct StateT * v1991) {
  int v1992 = v1991->timer;
  int v2162 = v1992 + 1;
  v1991->timer = v2162;
  int * v1994 = v1991->regs;
  int v1995 = v1994[10];
  int v1996 = v1994[14];
  int * v1997 = v1991->cache_tags;
  int v2167 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2;
  int v1998 = v1997[v2167];
  int v2168 = ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1999 = v1997[v2168];
  int v2169 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2);
  int v2000 = v1997[v2169];
  int v2170 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2001 = v1997[v2170];
  int v2002 = v1991->timer;
  int v2171 = v2002 + ((100 ^ (((~(((v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1991->timer = v2171;
  bool v2172 = !(((~(((v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1998 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) == 0);
  int v2096;
  if (v2172) {
    int * v2004 = v1991->cache_age;
    int v2174 = ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((~(((v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v1999 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) & 1);
    int v2005 = v2004[v2174];
    int v2006 = v2004[v2167];
    int v2175 = v2006 + ((int)((unsigned int)(v2006 - v2005) >> 31));
    v2004[v2167] = v2175;
    int * v2008 = v1991->cache_age;
    int v2009 = v2008[v2168];
    int v2177 = v2009 + ((int)((unsigned int)(v2009 - v2005) >> 31));
    v2008[v2168] = v2177;
    int * v2011 = v1991->cache_age;
    v2011[v2174] = 0;
    v2096 = v2174;
  } else {
    int * v2014 = v1991->cache_age;
    int v2181 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2;
    int v2015 = v2014[v2181];
    int * v2016 = v1991->cache_tags;
    int v2017 = v2016[v2181];
    int v2018 = v2014[v2168];
    int v2019 = v2016[v2168];
    bool v2183 = !(((~(((v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2000 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) == 0);
    int v2073;
    if (v2183) {
      int * v2020 = v1991->cache_age;
      int v2185 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2001 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) & 1);
      int v2021 = v2020[v2185];
      int v2022 = v2020[v2169];
      int v2186 = v2022 + ((int)((unsigned int)(v2022 - v2021) >> 31));
      v2020[v2169] = v2186;
      int * v2024 = v1991->cache_age;
      int v2025 = v2024[v2170];
      int v2188 = v2025 + ((int)((unsigned int)(v2025 - v2021) >> 31));
      v2024[v2170] = v2188;
      int * v2027 = v1991->cache_age;
      v2027[v2185] = 0;
      v2073 = v2185;
    } else {
      int * v2030 = v1991->cache_age;
      int v2192 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2);
      int v2031 = v2030[v2192];
      int * v2032 = v1991->cache_tags;
      int v2033 = v2032[v2192];
      int v2034 = v2030[v2170];
      int v2035 = v2032[v2170];
      int * v2036 = v1991->cache_dirty;
      int v2195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2037 = v2036[v2195];
      bool v2196 = !(v2037 == 0);
      if (v2196) {
        int * v2038 = v1991->cache_tags;
        int v2039 = v2038[v2195];
        int * v2040 = v1991->cache_vals;
        int v2199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2041 = v2040[v2199];
        int v2200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2042 = v2040[v2200];
        int * v2043 = v1991->mem;
        int v2202 = v2039 * 2;
        v2043[v2202] = v2041;
        int * v2045 = v1991->mem;
        int v2205 = (v2039 * 2) + 1;
        v2045[v2205] = v2042;
        ;
      } else {
        ;
      }
      int * v2050 = v1991->mem;
      int v2210 = ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2;
      int v2051 = v2050[v2210];
      int v2211 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2) + 1;
      int v2052 = v2050[v2211];
      int * v2053 = v1991->cache_vals;
      int v2213 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2053[v2213] = v2051;
      int * v2055 = v1991->cache_vals;
      int v2216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2031 + ((~(((v2033 ^ -1) | (-(v2033 ^ -1))) >> 31)) & 2)) - (v2034 + ((~(((v2035 ^ -1) | (-(v2035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2055[v2216] = v2052;
      int * v2057 = v1991->cache_tags;
      int v2219 = (int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1);
      v2057[v2195] = v2219;
      int * v2059 = v1991->cache_dirty;
      v2059[v2195] = 0;
      int * v2061 = v1991->cache_age;
      v2061[v2195] = 1;
      int * v2063 = v1991->cache_age;
      int v2064 = v2063[v2195];
      int v2065 = v2063[v2169];
      int v2225 = v2065 + ((int)((unsigned int)(v2065 - v2064) >> 31));
      v2063[v2169] = v2225;
      int * v2067 = v1991->cache_age;
      int v2068 = v2067[v2170];
      int v2227 = v2068 + ((int)((unsigned int)(v2068 - v2064) >> 31));
      v2067[v2170] = v2227;
      int * v2070 = v1991->cache_age;
      v2070[v2195] = 0;
      v2073 = v2195;
    }
    int * v2074 = v1991->cache_vals;
    int v2230 = v2073 * 2;
    int v2075 = v2074[v2230];
    int v2231 = (v2073 * 2) + 1;
    int v2076 = v2074[v2231];
    int v2232 = (((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((((v2015 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2)) - (v2018 + ((~(((v2019 ^ -1) | (-(v2019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2074[v2232] = v2075;
    int * v2078 = v1991->cache_vals;
    int v2235 = ((((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((((v2015 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2)) - (v2018 + ((~(((v2019 ^ -1) | (-(v2019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2078[v2235] = v2076;
    int * v2080 = v1991->cache_tags;
    int v2238 = ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 1) * 2) + ((((v2015 + ((~(((v2017 ^ -1) | (-(v2017 ^ -1))) >> 31)) & 2)) - (v2018 + ((~(((v2019 ^ -1) | (-(v2019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2239 = (int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1);
    v2080[v2238] = v2239;
    int * v2082 = v1991->cache_dirty;
    v2082[v2238] = 0;
    int * v2084 = v1991->cache_age;
    v2084[v2238] = 1;
    int * v2086 = v1991->cache_age;
    int v2087 = v2086[v2238];
    int v2088 = v2086[v2167];
    int v2245 = v2088 + ((int)((unsigned int)(v2088 - v2087) >> 31));
    v2086[v2167] = v2245;
    int * v2090 = v1991->cache_age;
    int v2091 = v2090[v2168];
    int v2247 = v2091 + ((int)((unsigned int)(v2091 - v2087) >> 31));
    v2090[v2168] = v2247;
    int * v2093 = v1991->cache_age;
    v2093[v2238] = 0;
    v2096 = v2238;
  }
  int * v2097 = v1991->cache_vals;
  int v2250 = (v2096 * 2) + (((int)((unsigned int)v1995 >> 2)) & 1);
  v2097[v2250] = v1996;
  int * v2099 = v1991->cache_tags;
  int v2100 = v2099[v2169];
  int v2101 = v2099[v2170];
  bool v2253 = !(((~(((v2100 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2100 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) | (~(((v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31))) == 0);
  int v2155;
  if (v2253) {
    int * v2102 = v1991->cache_age;
    int v2255 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))) | (-(v2101 ^ ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1))))) >> 31)) & 1);
    int v2103 = v2102[v2255];
    int v2104 = v2102[v2169];
    int v2256 = v2104 + ((int)((unsigned int)(v2104 - v2103) >> 31));
    v2102[v2169] = v2256;
    int * v2106 = v1991->cache_age;
    int v2107 = v2106[v2170];
    int v2258 = v2107 + ((int)((unsigned int)(v2107 - v2103) >> 31));
    v2106[v2170] = v2258;
    int * v2109 = v1991->cache_age;
    v2109[v2255] = 0;
    v2155 = v2255;
  } else {
    int * v2112 = v1991->cache_age;
    int v2262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2);
    int v2113 = v2112[v2262];
    int * v2114 = v1991->cache_tags;
    int v2115 = v2114[v2262];
    int v2116 = v2112[v2170];
    int v2117 = v2114[v2170];
    int * v2118 = v1991->cache_dirty;
    int v2265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2119 = v2118[v2265];
    bool v2266 = !(v2119 == 0);
    if (v2266) {
      int * v2120 = v1991->cache_tags;
      int v2121 = v2120[v2265];
      int * v2122 = v1991->cache_vals;
      int v2269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2123 = v2122[v2269];
      int v2270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2124 = v2122[v2270];
      int * v2125 = v1991->mem;
      int v2272 = v2121 * 2;
      v2125[v2272] = v2123;
      int * v2127 = v1991->mem;
      int v2275 = (v2121 * 2) + 1;
      v2127[v2275] = v2124;
      ;
    } else {
      ;
    }
    int * v2132 = v1991->mem;
    int v2280 = ((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2;
    int v2133 = v2132[v2280];
    int v2281 = (((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) * 2) + 1;
    int v2134 = v2132[v2281];
    int * v2135 = v1991->cache_vals;
    int v2283 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2135[v2283] = v2133;
    int * v2137 = v1991->cache_vals;
    int v2286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1)) & 3) * 2)) + ((((v2113 + ((~(((v2115 ^ -1) | (-(v2115 ^ -1))) >> 31)) & 2)) - (v2116 + ((~(((v2117 ^ -1) | (-(v2117 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2137[v2286] = v2134;
    int * v2139 = v1991->cache_tags;
    int v2289 = (int)((unsigned int)((int)((unsigned int)v1995 >> 2)) >> 1);
    v2139[v2265] = v2289;
    int * v2141 = v1991->cache_dirty;
    v2141[v2265] = 0;
    int * v2143 = v1991->cache_age;
    v2143[v2265] = 1;
    int * v2145 = v1991->cache_age;
    int v2146 = v2145[v2265];
    int v2147 = v2145[v2169];
    int v2295 = v2147 + ((int)((unsigned int)(v2147 - v2146) >> 31));
    v2145[v2169] = v2295;
    int * v2149 = v1991->cache_age;
    int v2150 = v2149[v2170];
    int v2297 = v2150 + ((int)((unsigned int)(v2150 - v2146) >> 31));
    v2149[v2170] = v2297;
    int * v2152 = v1991->cache_age;
    v2152[v2265] = 0;
    v2155 = v2265;
  }
  int * v2156 = v1991->cache_vals;
  int v2300 = (v2155 * 2) + (((int)((unsigned int)v1995 >> 2)) & 1);
  v2156[v2300] = v1996;
  int * v2158 = v1991->cache_dirty;
  v2158[v2155] = 1;
  struct StateT * v2160 = slot_26(v1991);
  return v2160;
}

struct StateT * slot_490(struct StateT * v24986) {
  int v24987 = v24986->timer;
  int v24995 = v24987 + 1;
  v24986->timer = v24995;
  int * v24989 = v24986->regs;
  int v24990 = v24989[11];
  int v24991 = v24989[13];
  int v24999 = (((((int)((unsigned int)v24990 >> 16)) * ((int)((unsigned int)v24991 >> 16))) + ((int)((unsigned int)((v24990 & 65535) * ((int)((unsigned int)v24991 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v24990 >> 16)) * (v24991 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v24990 & 65535) * (v24991 & 65535)) >> 16)) + (((v24990 & 65535) * ((int)((unsigned int)v24991 >> 16))) & 65535)) + ((((int)((unsigned int)v24990 >> 16)) * (v24991 & 65535)) & 65535)) >> 16));
  v24989[13] = v24999;
  struct StateT * v24993 = slot_501(v24986);
  return v24993;
}

struct StateT * slot_123(struct StateT * v6671) {
  int v6672 = v6671->timer;
  int v6684 = v6672 + 1;
  v6671->timer = v6684;
  int * v6674 = v6671->regs;
  int v6675 = v6674[17];
  int v6676 = v6674[6];
  bool v6688 = (v6675 ^ -2147483648) < (v6676 ^ -2147483648);
  int v6679;
  if (v6688) {
    v6679 = 1;
  } else {
    v6679 = 0;
  }
  int * v6680 = v6671->regs;
  v6680[28] = v6679;
  struct StateT * v6682 = slot_118(v6671);
  return v6682;
}

struct StateT * slot_982(struct StateT * v49375) {
  int v49376 = v49375->timer;
  int v49486 = v49376 + 1;
  v49375->timer = v49486;
  int * v49378 = v49375->regs;
  int v49379 = v49378[2];
  int * v49380 = v49375->cache_tags;
  int v49490 = (((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2;
  int v49381 = v49380[v49490];
  int v49491 = ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2) + 1;
  int v49382 = v49380[v49491];
  int v49492 = 4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2);
  int v49383 = v49380[v49492];
  int v49493 = (4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v49384 = v49380[v49493];
  int v49385 = v49375->timer;
  int v49494 = v49385 + ((100 ^ (((~(((v49383 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49383 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) | (~(((v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v49381 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49381 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) | (~(((v49382 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49382 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v49383 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49383 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) | (~(((v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31))) & 104)))));
  v49375->timer = v49494;
  int * v49387 = v49375->cache_vals;
  bool v49495 = !(((~(((v49381 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49381 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) | (~(((v49382 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49382 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31))) == 0);
  int v49480;
  if (v49495) {
    int * v49388 = v49375->cache_age;
    int v49497 = ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2) + ((~(((v49382 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49382 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) & 1);
    int v49389 = v49388[v49497];
    int v49390 = v49388[v49490];
    int v49498 = v49390 + ((int)((unsigned int)(v49390 - v49389) >> 31));
    v49388[v49490] = v49498;
    int * v49392 = v49375->cache_age;
    int v49393 = v49392[v49491];
    int v49500 = v49393 + ((int)((unsigned int)(v49393 - v49389) >> 31));
    v49392[v49491] = v49500;
    int * v49395 = v49375->cache_age;
    v49395[v49497] = 0;
    v49480 = v49497;
  } else {
    int * v49398 = v49375->cache_age;
    int v49504 = (((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2;
    int v49399 = v49398[v49504];
    int * v49400 = v49375->cache_tags;
    int v49401 = v49400[v49504];
    int v49402 = v49398[v49491];
    int v49403 = v49400[v49491];
    bool v49506 = !(((~(((v49383 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49383 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) | (~(((v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31))) == 0);
    int v49457;
    if (v49506) {
      int * v49404 = v49375->cache_age;
      int v49508 = (4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + ((~(((v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))) | (-(v49384 ^ ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1))))) >> 31)) & 1);
      int v49405 = v49404[v49508];
      int v49406 = v49404[v49492];
      int v49509 = v49406 + ((int)((unsigned int)(v49406 - v49405) >> 31));
      v49404[v49492] = v49509;
      int * v49408 = v49375->cache_age;
      int v49409 = v49408[v49493];
      int v49511 = v49409 + ((int)((unsigned int)(v49409 - v49405) >> 31));
      v49408[v49493] = v49511;
      int * v49411 = v49375->cache_age;
      v49411[v49508] = 0;
      v49457 = v49508;
    } else {
      int * v49414 = v49375->cache_age;
      int v49515 = 4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2);
      int v49415 = v49414[v49515];
      int * v49416 = v49375->cache_tags;
      int v49417 = v49416[v49515];
      int v49418 = v49414[v49493];
      int v49419 = v49416[v49493];
      int * v49420 = v49375->cache_dirty;
      int v49518 = (4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + ((((v49415 + ((~(((v49417 ^ -1) | (-(v49417 ^ -1))) >> 31)) & 2)) - (v49418 + ((~(((v49419 ^ -1) | (-(v49419 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v49421 = v49420[v49518];
      bool v49519 = !(v49421 == 0);
      if (v49519) {
        int * v49422 = v49375->cache_tags;
        int v49423 = v49422[v49518];
        int * v49424 = v49375->cache_vals;
        int v49522 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + ((((v49415 + ((~(((v49417 ^ -1) | (-(v49417 ^ -1))) >> 31)) & 2)) - (v49418 + ((~(((v49419 ^ -1) | (-(v49419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v49425 = v49424[v49522];
        int v49523 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + ((((v49415 + ((~(((v49417 ^ -1) | (-(v49417 ^ -1))) >> 31)) & 2)) - (v49418 + ((~(((v49419 ^ -1) | (-(v49419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v49426 = v49424[v49523];
        int * v49427 = v49375->mem;
        int v49525 = v49423 * 2;
        v49427[v49525] = v49425;
        int * v49429 = v49375->mem;
        int v49528 = (v49423 * 2) + 1;
        v49429[v49528] = v49426;
        ;
      } else {
        ;
      }
      int * v49434 = v49375->mem;
      int v49533 = ((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) * 2;
      int v49435 = v49434[v49533];
      int v49534 = (((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) * 2) + 1;
      int v49436 = v49434[v49534];
      int * v49437 = v49375->cache_vals;
      int v49536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + ((((v49415 + ((~(((v49417 ^ -1) | (-(v49417 ^ -1))) >> 31)) & 2)) - (v49418 + ((~(((v49419 ^ -1) | (-(v49419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v49437[v49536] = v49435;
      int * v49439 = v49375->cache_vals;
      int v49539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 3) * 2)) + ((((v49415 + ((~(((v49417 ^ -1) | (-(v49417 ^ -1))) >> 31)) & 2)) - (v49418 + ((~(((v49419 ^ -1) | (-(v49419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v49439[v49539] = v49436;
      int * v49441 = v49375->cache_tags;
      int v49542 = (int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1);
      v49441[v49518] = v49542;
      int * v49443 = v49375->cache_dirty;
      v49443[v49518] = 0;
      int * v49445 = v49375->cache_age;
      v49445[v49518] = 1;
      int * v49447 = v49375->cache_age;
      int v49448 = v49447[v49518];
      int v49449 = v49447[v49492];
      int v49548 = v49449 + ((int)((unsigned int)(v49449 - v49448) >> 31));
      v49447[v49492] = v49548;
      int * v49451 = v49375->cache_age;
      int v49452 = v49451[v49493];
      int v49550 = v49452 + ((int)((unsigned int)(v49452 - v49448) >> 31));
      v49451[v49493] = v49550;
      int * v49454 = v49375->cache_age;
      v49454[v49518] = 0;
      v49457 = v49518;
    }
    int * v49458 = v49375->cache_vals;
    int v49553 = v49457 * 2;
    int v49459 = v49458[v49553];
    int v49554 = (v49457 * 2) + 1;
    int v49460 = v49458[v49554];
    int v49555 = (((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2) + ((((v49399 + ((~(((v49401 ^ -1) | (-(v49401 ^ -1))) >> 31)) & 2)) - (v49402 + ((~(((v49403 ^ -1) | (-(v49403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v49458[v49555] = v49459;
    int * v49462 = v49375->cache_vals;
    int v49558 = ((((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2) + ((((v49399 + ((~(((v49401 ^ -1) | (-(v49401 ^ -1))) >> 31)) & 2)) - (v49402 + ((~(((v49403 ^ -1) | (-(v49403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v49462[v49558] = v49460;
    int * v49464 = v49375->cache_tags;
    int v49561 = ((((int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1)) & 1) * 2) + ((((v49399 + ((~(((v49401 ^ -1) | (-(v49401 ^ -1))) >> 31)) & 2)) - (v49402 + ((~(((v49403 ^ -1) | (-(v49403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v49562 = (int)((unsigned int)((int)((unsigned int)v49379 >> 2)) >> 1);
    v49464[v49561] = v49562;
    int * v49466 = v49375->cache_dirty;
    v49466[v49561] = 0;
    int * v49468 = v49375->cache_age;
    v49468[v49561] = 1;
    int * v49470 = v49375->cache_age;
    int v49471 = v49470[v49561];
    int v49472 = v49470[v49490];
    int v49568 = v49472 + ((int)((unsigned int)(v49472 - v49471) >> 31));
    v49470[v49490] = v49568;
    int * v49474 = v49375->cache_age;
    int v49475 = v49474[v49491];
    int v49570 = v49475 + ((int)((unsigned int)(v49475 - v49471) >> 31));
    v49474[v49491] = v49570;
    int * v49477 = v49375->cache_age;
    v49477[v49561] = 0;
    v49480 = v49561;
  }
  int v49573 = (v49480 * 2) + (((int)((unsigned int)v49379 >> 2)) & 1);
  int v49481 = v49387[v49573];
  int * v49482 = v49375->regs;
  v49482[19] = v49481;
  struct StateT * v49484 = slot_895(v49375);
  return v49484;
}

struct StateT * slot_799(struct StateT * v33573) {
  int v33574 = v33573->timer;
  int v33582 = v33574 + 1;
  v33573->timer = v33582;
  int * v33576 = v33573->regs;
  int v33577 = v33576[17];
  int v33578 = v33576[16];
  int v33586 = v33577 & v33578;
  v33576[16] = v33586;
  struct StateT * v33580 = slot_918(v33573);
  return v33580;
}

struct StateT * slot_299(struct StateT * v13800) {
  int v13801 = v13800->timer;
  int v13809 = v13801 + 1;
  v13800->timer = v13809;
  int * v13803 = v13800->regs;
  int v13804 = v13803[6];
  int v13805 = v13803[31];
  int v13813 = v13804 + v13805;
  v13803[6] = v13813;
  struct StateT * v13807 = slot_288(v13800);
  return v13807;
}

struct StateT * slot_539(struct StateT * v25918) {
  int v25919 = v25918->timer;
  int v25931 = v25919 + 1;
  v25918->timer = v25931;
  int * v25921 = v25918->regs;
  int v25922 = v25921[11];
  int v25923 = v25921[12];
  bool v25935 = (v25922 ^ -2147483648) < (v25923 ^ -2147483648);
  int v25926;
  if (v25935) {
    v25926 = 1;
  } else {
    v25926 = 0;
  }
  int * v25927 = v25918->regs;
  v25927[5] = v25926;
  struct StateT * v25929 = slot_546(v25918);
  return v25929;
}

struct StateT * slot_671(struct StateT * v28455) {
  int v28456 = v28455->timer;
  int v28464 = v28456 + 1;
  v28455->timer = v28464;
  int * v28458 = v28455->regs;
  int v28459 = v28458[17];
  int v28460 = v28458[13];
  int v28468 = v28459 | v28460;
  v28458[13] = v28468;
  struct StateT * v28462 = slot_709(v28455);
  return v28462;
}

struct StateT * slot_794(struct StateT * v33194) {
  int v33195 = v33194->timer;
  int v33203 = v33195 + 1;
  v33194->timer = v33203;
  int * v33197 = v33194->regs;
  int v33198 = v33197[15];
  int v33199 = v33197[12];
  int v33207 = v33198 + v33199;
  v33197[12] = v33207;
  struct StateT * v33201 = slot_810(v33194);
  return v33201;
}

struct StateT * slot_900(struct StateT * v45099) {
  int v45100 = v45099->timer;
  int v45107 = v45100 + 1;
  v45099->timer = v45107;
  int * v45102 = v45099->regs;
  int v45103 = v45102[5];
  int v45110 = (int)((unsigned int)v45103 >> 19);
  v45102[5] = v45110;
  struct StateT * v45105 = slot_913(v45099);
  return v45105;
}

struct StateT * slot_240(struct StateT * v12673) {
  int v12674 = v12673->timer;
  int v12686 = v12674 + 1;
  v12673->timer = v12686;
  int * v12676 = v12673->regs;
  int v12677 = v12676[17];
  int v12678 = v12676[6];
  bool v12690 = (v12677 ^ -2147483648) < (v12678 ^ -2147483648);
  int v12681;
  if (v12690) {
    v12681 = 1;
  } else {
    v12681 = 0;
  }
  int * v12682 = v12673->regs;
  v12682[28] = v12681;
  struct StateT * v12684 = slot_258(v12673);
  return v12684;
}

struct StateT * slot_1055(struct StateT * v57559) {
  int v57560 = v57559->timer;
  int v57670 = v57560 + 1;
  v57559->timer = v57670;
  int * v57562 = v57559->regs;
  int v57563 = v57562[2];
  int * v57564 = v57559->cache_tags;
  int v57674 = (((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2;
  int v57565 = v57564[v57674];
  int v57675 = ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v57566 = v57564[v57675];
  int v57676 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2);
  int v57567 = v57564[v57676];
  int v57677 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v57568 = v57564[v57677];
  int v57569 = v57559->timer;
  int v57678 = v57569 + ((100 ^ (((~(((v57567 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57567 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v57565 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57565 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v57566 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57566 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v57567 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57567 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v57559->timer = v57678;
  int * v57571 = v57559->cache_vals;
  bool v57679 = !(((~(((v57565 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57565 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v57566 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57566 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v57664;
  if (v57679) {
    int * v57572 = v57559->cache_age;
    int v57681 = ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v57566 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57566 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v57573 = v57572[v57681];
    int v57574 = v57572[v57674];
    int v57682 = v57574 + ((int)((unsigned int)(v57574 - v57573) >> 31));
    v57572[v57674] = v57682;
    int * v57576 = v57559->cache_age;
    int v57577 = v57576[v57675];
    int v57684 = v57577 + ((int)((unsigned int)(v57577 - v57573) >> 31));
    v57576[v57675] = v57684;
    int * v57579 = v57559->cache_age;
    v57579[v57681] = 0;
    v57664 = v57681;
  } else {
    int * v57582 = v57559->cache_age;
    int v57688 = (((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2;
    int v57583 = v57582[v57688];
    int * v57584 = v57559->cache_tags;
    int v57585 = v57584[v57688];
    int v57586 = v57582[v57675];
    int v57587 = v57584[v57675];
    bool v57690 = !(((~(((v57567 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57567 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v57641;
    if (v57690) {
      int * v57588 = v57559->cache_age;
      int v57692 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))) | (-(v57568 ^ ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v57589 = v57588[v57692];
      int v57590 = v57588[v57676];
      int v57693 = v57590 + ((int)((unsigned int)(v57590 - v57589) >> 31));
      v57588[v57676] = v57693;
      int * v57592 = v57559->cache_age;
      int v57593 = v57592[v57677];
      int v57695 = v57593 + ((int)((unsigned int)(v57593 - v57589) >> 31));
      v57592[v57677] = v57695;
      int * v57595 = v57559->cache_age;
      v57595[v57692] = 0;
      v57641 = v57692;
    } else {
      int * v57598 = v57559->cache_age;
      int v57699 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2);
      int v57599 = v57598[v57699];
      int * v57600 = v57559->cache_tags;
      int v57601 = v57600[v57699];
      int v57602 = v57598[v57677];
      int v57603 = v57600[v57677];
      int * v57604 = v57559->cache_dirty;
      int v57702 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v57599 + ((~(((v57601 ^ -1) | (-(v57601 ^ -1))) >> 31)) & 2)) - (v57602 + ((~(((v57603 ^ -1) | (-(v57603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v57605 = v57604[v57702];
      bool v57703 = !(v57605 == 0);
      if (v57703) {
        int * v57606 = v57559->cache_tags;
        int v57607 = v57606[v57702];
        int * v57608 = v57559->cache_vals;
        int v57706 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v57599 + ((~(((v57601 ^ -1) | (-(v57601 ^ -1))) >> 31)) & 2)) - (v57602 + ((~(((v57603 ^ -1) | (-(v57603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v57609 = v57608[v57706];
        int v57707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v57599 + ((~(((v57601 ^ -1) | (-(v57601 ^ -1))) >> 31)) & 2)) - (v57602 + ((~(((v57603 ^ -1) | (-(v57603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v57610 = v57608[v57707];
        int * v57611 = v57559->mem;
        int v57709 = v57607 * 2;
        v57611[v57709] = v57609;
        int * v57613 = v57559->mem;
        int v57712 = (v57607 * 2) + 1;
        v57613[v57712] = v57610;
        ;
      } else {
        ;
      }
      int * v57618 = v57559->mem;
      int v57717 = ((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) * 2;
      int v57619 = v57618[v57717];
      int v57718 = (((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) * 2) + 1;
      int v57620 = v57618[v57718];
      int * v57621 = v57559->cache_vals;
      int v57720 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v57599 + ((~(((v57601 ^ -1) | (-(v57601 ^ -1))) >> 31)) & 2)) - (v57602 + ((~(((v57603 ^ -1) | (-(v57603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v57621[v57720] = v57619;
      int * v57623 = v57559->cache_vals;
      int v57723 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v57599 + ((~(((v57601 ^ -1) | (-(v57601 ^ -1))) >> 31)) & 2)) - (v57602 + ((~(((v57603 ^ -1) | (-(v57603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v57623[v57723] = v57620;
      int * v57625 = v57559->cache_tags;
      int v57726 = (int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1);
      v57625[v57702] = v57726;
      int * v57627 = v57559->cache_dirty;
      v57627[v57702] = 0;
      int * v57629 = v57559->cache_age;
      v57629[v57702] = 1;
      int * v57631 = v57559->cache_age;
      int v57632 = v57631[v57702];
      int v57633 = v57631[v57676];
      int v57732 = v57633 + ((int)((unsigned int)(v57633 - v57632) >> 31));
      v57631[v57676] = v57732;
      int * v57635 = v57559->cache_age;
      int v57636 = v57635[v57677];
      int v57734 = v57636 + ((int)((unsigned int)(v57636 - v57632) >> 31));
      v57635[v57677] = v57734;
      int * v57638 = v57559->cache_age;
      v57638[v57702] = 0;
      v57641 = v57702;
    }
    int * v57642 = v57559->cache_vals;
    int v57737 = v57641 * 2;
    int v57643 = v57642[v57737];
    int v57738 = (v57641 * 2) + 1;
    int v57644 = v57642[v57738];
    int v57739 = (((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v57583 + ((~(((v57585 ^ -1) | (-(v57585 ^ -1))) >> 31)) & 2)) - (v57586 + ((~(((v57587 ^ -1) | (-(v57587 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v57642[v57739] = v57643;
    int * v57646 = v57559->cache_vals;
    int v57742 = ((((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v57583 + ((~(((v57585 ^ -1) | (-(v57585 ^ -1))) >> 31)) & 2)) - (v57586 + ((~(((v57587 ^ -1) | (-(v57587 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v57646[v57742] = v57644;
    int * v57648 = v57559->cache_tags;
    int v57745 = ((((int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v57583 + ((~(((v57585 ^ -1) | (-(v57585 ^ -1))) >> 31)) & 2)) - (v57586 + ((~(((v57587 ^ -1) | (-(v57587 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v57746 = (int)((unsigned int)((int)((unsigned int)(v57563 + 12) >> 2)) >> 1);
    v57648[v57745] = v57746;
    int * v57650 = v57559->cache_dirty;
    v57650[v57745] = 0;
    int * v57652 = v57559->cache_age;
    v57652[v57745] = 1;
    int * v57654 = v57559->cache_age;
    int v57655 = v57654[v57745];
    int v57656 = v57654[v57674];
    int v57752 = v57656 + ((int)((unsigned int)(v57656 - v57655) >> 31));
    v57654[v57674] = v57752;
    int * v57658 = v57559->cache_age;
    int v57659 = v57658[v57675];
    int v57754 = v57659 + ((int)((unsigned int)(v57659 - v57655) >> 31));
    v57658[v57675] = v57754;
    int * v57661 = v57559->cache_age;
    v57661[v57745] = 0;
    v57664 = v57745;
  }
  int v57757 = (v57664 * 2) + (((int)((unsigned int)(v57563 + 12) >> 2)) & 1);
  int v57665 = v57571[v57757];
  int * v57666 = v57559->regs;
  v57666[8] = v57665;
  struct StateT * v57668 = slot_1032(v57559);
  return v57668;
}

struct StateT * slot_548(struct StateT * v26090) {
  int v26091 = v26090->timer;
  int v26099 = v26091 + 1;
  v26090->timer = v26099;
  int * v26093 = v26090->regs;
  int v26094 = v26093[7];
  int v26095 = v26093[12];
  int v26104 = v26094 + v26095;
  v26093[28] = v26104;
  struct StateT * v26097 = slot_586(v26090);
  return v26097;
}

struct StateT * slot_70(struct StateT * v3787) {
  int * v3788 = v3787->saved_regs;
  int v3789 = v3788[7];
  int v3790 = v3788[29];
  bool v3818 = v3789 == v3790;
  struct StateT * v3813;
  if (v3818) {
    int v3791 = v3787->timer;
    int v3819 = v3791 + 15;
    v3787->timer = v3819;
    int * v3793 = v3787->saved_regs;
    int v3794 = v3793[28];
    int * v3795 = v3787->regs;
    v3795[28] = v3794;
    int * v3797 = v3787->saved_regs;
    int v3798 = v3797[29];
    int * v3799 = v3787->regs;
    v3799[29] = v3798;
    int * v3801 = v3787->saved_regs;
    int v3802 = v3801[7];
    int * v3803 = v3787->regs;
    v3803[7] = v3802;
    int * v3805 = v3787->saved_regs;
    int v3806 = v3805[5];
    int * v3807 = v3787->regs;
    v3807[5] = v3806;
    struct StateT * v3809 = slot_71(v3787);
    v3813 = v3809;
  } else {
    struct StateT * v3811 = slot_79(v3787);
    v3813 = v3811;
  }
  return v3813;
}

struct StateT * slot_348(struct StateT * v17424) {
  int v17425 = v17424->timer;
  int v17432 = v17425 + 1;
  v17424->timer = v17432;
  int * v17427 = v17424->regs;
  int v17428 = v17427[7];
  int v17435 = (int)((unsigned int)v17428 >> 19);
  v17427[7] = v17435;
  struct StateT * v17430 = slot_355(v17424);
  return v17430;
}

struct StateT * slot_920(struct StateT * v46533) {
  int v46534 = v46533->timer;
  int v46542 = v46534 + 1;
  v46533->timer = v46542;
  int * v46536 = v46533->regs;
  int v46537 = v46536[17];
  int v46538 = v46536[13];
  int v46546 = v46537 | v46538;
  v46536[13] = v46546;
  struct StateT * v46540 = slot_935(v46533);
  return v46540;
}

struct StateT * slot_749(struct StateT * v29896) {
  int v29897 = v29896->timer;
  int v29905 = v29897 + 1;
  v29896->timer = v29905;
  int * v29899 = v29896->regs;
  int v29900 = v29899[13];
  int v29901 = v29899[17];
  int v29909 = v29900 * v29901;
  v29899[13] = v29909;
  struct StateT * v29903 = slot_758(v29896);
  return v29903;
}

struct StateT * slot_988(struct StateT * v49662) {
  int v49663 = v49662->timer;
  int v49671 = v49663 + 1;
  v49662->timer = v49671;
  int * v49665 = v49662->regs;
  int v49666 = v49665[12];
  int v49667 = v49665[17];
  int v49675 = v49666 * v49667;
  v49665[12] = v49675;
  struct StateT * v49669 = slot_1057(v49662);
  return v49669;
}

struct StateT * slot_1057(struct StateT * v57777) {
  int v57778 = v57777->timer;
  int v57790 = v57778 + 1;
  v57777->timer = v57790;
  int * v57780 = v57777->regs;
  int v57781 = v57780[13];
  int v57782 = v57780[14];
  bool v57794 = (v57781 ^ -2147483648) < (v57782 ^ -2147483648);
  int v57785;
  if (v57794) {
    v57785 = 1;
  } else {
    v57785 = 0;
  }
  int * v57786 = v57777->regs;
  v57786[14] = v57785;
  struct StateT * v57788 = slot_1065(v57777);
  return v57788;
}

struct StateT * slot_293(struct StateT * v13693) {
  int v13694 = v13693->timer;
  int v13702 = v13694 + 1;
  v13693->timer = v13702;
  int * v13696 = v13693->regs;
  int v13697 = v13696[9];
  int v13698 = v13696[6];
  int v13707 = v13697 + v13698;
  v13696[5] = v13707;
  struct StateT * v13700 = slot_268(v13693);
  return v13700;
}

struct StateT * slot_288(struct StateT * v13605) {
  int v13606 = v13605->timer;
  int v13610 = v13606 + 1;
  v13605->timer = v13610;
  struct StateT * v13608 = slot_323(v13605);
  return v13608;
}

struct StateT * slot_89(struct StateT * v5698) {
  int v5699 = v5698->timer;
  int v5809 = v5699 + 1;
  v5698->timer = v5809;
  int * v5701 = v5698->regs;
  int v5702 = v5701[11];
  int * v5703 = v5698->cache_tags;
  int v5813 = (((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2;
  int v5704 = v5703[v5813];
  int v5814 = ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5705 = v5703[v5814];
  int v5815 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2);
  int v5706 = v5703[v5815];
  int v5816 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5707 = v5703[v5816];
  int v5708 = v5698->timer;
  int v5817 = v5708 + ((100 ^ (((~(((v5706 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5706 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5704 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5704 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5705 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5705 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5706 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5706 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5698->timer = v5817;
  int * v5710 = v5698->cache_vals;
  bool v5818 = !(((~(((v5704 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5704 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5705 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5705 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v5803;
  if (v5818) {
    int * v5711 = v5698->cache_age;
    int v5820 = ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v5705 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5705 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v5712 = v5711[v5820];
    int v5713 = v5711[v5813];
    int v5821 = v5713 + ((int)((unsigned int)(v5713 - v5712) >> 31));
    v5711[v5813] = v5821;
    int * v5715 = v5698->cache_age;
    int v5716 = v5715[v5814];
    int v5823 = v5716 + ((int)((unsigned int)(v5716 - v5712) >> 31));
    v5715[v5814] = v5823;
    int * v5718 = v5698->cache_age;
    v5718[v5820] = 0;
    v5803 = v5820;
  } else {
    int * v5721 = v5698->cache_age;
    int v5827 = (((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2;
    int v5722 = v5721[v5827];
    int * v5723 = v5698->cache_tags;
    int v5724 = v5723[v5827];
    int v5725 = v5721[v5814];
    int v5726 = v5723[v5814];
    bool v5829 = !(((~(((v5706 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5706 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v5780;
    if (v5829) {
      int * v5727 = v5698->cache_age;
      int v5831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))) | (-(v5707 ^ ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v5728 = v5727[v5831];
      int v5729 = v5727[v5815];
      int v5832 = v5729 + ((int)((unsigned int)(v5729 - v5728) >> 31));
      v5727[v5815] = v5832;
      int * v5731 = v5698->cache_age;
      int v5732 = v5731[v5816];
      int v5834 = v5732 + ((int)((unsigned int)(v5732 - v5728) >> 31));
      v5731[v5816] = v5834;
      int * v5734 = v5698->cache_age;
      v5734[v5831] = 0;
      v5780 = v5831;
    } else {
      int * v5737 = v5698->cache_age;
      int v5838 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2);
      int v5738 = v5737[v5838];
      int * v5739 = v5698->cache_tags;
      int v5740 = v5739[v5838];
      int v5741 = v5737[v5816];
      int v5742 = v5739[v5816];
      int * v5743 = v5698->cache_dirty;
      int v5841 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5738 + ((~(((v5740 ^ -1) | (-(v5740 ^ -1))) >> 31)) & 2)) - (v5741 + ((~(((v5742 ^ -1) | (-(v5742 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5744 = v5743[v5841];
      bool v5842 = !(v5744 == 0);
      if (v5842) {
        int * v5745 = v5698->cache_tags;
        int v5746 = v5745[v5841];
        int * v5747 = v5698->cache_vals;
        int v5845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5738 + ((~(((v5740 ^ -1) | (-(v5740 ^ -1))) >> 31)) & 2)) - (v5741 + ((~(((v5742 ^ -1) | (-(v5742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5748 = v5747[v5845];
        int v5846 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5738 + ((~(((v5740 ^ -1) | (-(v5740 ^ -1))) >> 31)) & 2)) - (v5741 + ((~(((v5742 ^ -1) | (-(v5742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5749 = v5747[v5846];
        int * v5750 = v5698->mem;
        int v5848 = v5746 * 2;
        v5750[v5848] = v5748;
        int * v5752 = v5698->mem;
        int v5851 = (v5746 * 2) + 1;
        v5752[v5851] = v5749;
        ;
      } else {
        ;
      }
      int * v5757 = v5698->mem;
      int v5856 = ((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) * 2;
      int v5758 = v5757[v5856];
      int v5857 = (((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) * 2) + 1;
      int v5759 = v5757[v5857];
      int * v5760 = v5698->cache_vals;
      int v5859 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5738 + ((~(((v5740 ^ -1) | (-(v5740 ^ -1))) >> 31)) & 2)) - (v5741 + ((~(((v5742 ^ -1) | (-(v5742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5760[v5859] = v5758;
      int * v5762 = v5698->cache_vals;
      int v5862 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5738 + ((~(((v5740 ^ -1) | (-(v5740 ^ -1))) >> 31)) & 2)) - (v5741 + ((~(((v5742 ^ -1) | (-(v5742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5762[v5862] = v5759;
      int * v5764 = v5698->cache_tags;
      int v5865 = (int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1);
      v5764[v5841] = v5865;
      int * v5766 = v5698->cache_dirty;
      v5766[v5841] = 0;
      int * v5768 = v5698->cache_age;
      v5768[v5841] = 1;
      int * v5770 = v5698->cache_age;
      int v5771 = v5770[v5841];
      int v5772 = v5770[v5815];
      int v5871 = v5772 + ((int)((unsigned int)(v5772 - v5771) >> 31));
      v5770[v5815] = v5871;
      int * v5774 = v5698->cache_age;
      int v5775 = v5774[v5816];
      int v5873 = v5775 + ((int)((unsigned int)(v5775 - v5771) >> 31));
      v5774[v5816] = v5873;
      int * v5777 = v5698->cache_age;
      v5777[v5841] = 0;
      v5780 = v5841;
    }
    int * v5781 = v5698->cache_vals;
    int v5876 = v5780 * 2;
    int v5782 = v5781[v5876];
    int v5877 = (v5780 * 2) + 1;
    int v5783 = v5781[v5877];
    int v5878 = (((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5722 + ((~(((v5724 ^ -1) | (-(v5724 ^ -1))) >> 31)) & 2)) - (v5725 + ((~(((v5726 ^ -1) | (-(v5726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5781[v5878] = v5782;
    int * v5785 = v5698->cache_vals;
    int v5881 = ((((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5722 + ((~(((v5724 ^ -1) | (-(v5724 ^ -1))) >> 31)) & 2)) - (v5725 + ((~(((v5726 ^ -1) | (-(v5726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5785[v5881] = v5783;
    int * v5787 = v5698->cache_tags;
    int v5884 = ((((int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5722 + ((~(((v5724 ^ -1) | (-(v5724 ^ -1))) >> 31)) & 2)) - (v5725 + ((~(((v5726 ^ -1) | (-(v5726 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5885 = (int)((unsigned int)((int)((unsigned int)(v5702 + 16) >> 2)) >> 1);
    v5787[v5884] = v5885;
    int * v5789 = v5698->cache_dirty;
    v5789[v5884] = 0;
    int * v5791 = v5698->cache_age;
    v5791[v5884] = 1;
    int * v5793 = v5698->cache_age;
    int v5794 = v5793[v5884];
    int v5795 = v5793[v5813];
    int v5891 = v5795 + ((int)((unsigned int)(v5795 - v5794) >> 31));
    v5793[v5813] = v5891;
    int * v5797 = v5698->cache_age;
    int v5798 = v5797[v5814];
    int v5893 = v5798 + ((int)((unsigned int)(v5798 - v5794) >> 31));
    v5797[v5814] = v5893;
    int * v5800 = v5698->cache_age;
    v5800[v5884] = 0;
    v5803 = v5884;
  }
  int v5896 = (v5803 * 2) + (((int)((unsigned int)(v5702 + 16) >> 2)) & 1);
  int v5804 = v5710[v5896];
  int * v5805 = v5698->regs;
  v5805[6] = v5804;
  struct StateT * v5807 = slot_84(v5698);
  return v5807;
}

struct StateT * slot_1065(struct StateT * v59363) {
  int v59364 = v59363->timer;
  int v59372 = v59364 + 1;
  v59363->timer = v59372;
  int * v59366 = v59363->regs;
  int v59367 = v59366[15];
  int v59368 = v59366[12];
  int v59376 = v59367 + v59368;
  v59366[12] = v59376;
  struct StateT * v59370 = slot_1042(v59363);
  return v59370;
}

struct StateT * slot_140(struct StateT * v6999) {
  int v7000 = v6999->timer;
  int v7004 = v7000 + 1;
  v6999->timer = v7004;
  struct StateT * v7002 = slot_142(v6999);
  return v7002;
}

struct StateT * slot_473(struct StateT * v24693) {
  int v24694 = v24693->timer;
  int v24702 = v24694 + 1;
  v24693->timer = v24702;
  int * v24696 = v24693->regs;
  int v24697 = v24696[6];
  int v24698 = v24696[12];
  int v24707 = (((((int)((unsigned int)v24697 >> 16)) * ((int)((unsigned int)v24698 >> 16))) + ((int)((unsigned int)((v24697 & 65535) * ((int)((unsigned int)v24698 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v24697 >> 16)) * (v24698 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v24697 & 65535) * (v24698 & 65535)) >> 16)) + (((v24697 & 65535) * ((int)((unsigned int)v24698 >> 16))) & 65535)) + ((((int)((unsigned int)v24697 >> 16)) * (v24698 & 65535)) & 65535)) >> 16));
  v24696[5] = v24707;
  struct StateT * v24700 = slot_453(v24693);
  return v24700;
}

struct StateT * slot_913(struct StateT * v46150) {
  int v46151 = v46150->timer;
  int v46158 = v46151 + 1;
  v46150->timer = v46158;
  int * v46153 = v46150->regs;
  int v46154 = v46153[12];
  int v46161 = v46154 << 13;
  v46153[12] = v46161;
  struct StateT * v46156 = slot_971(v46150);
  return v46156;
}

struct StateT * slot_40(struct StateT * v3222) {
  int v3223 = v3222->timer;
  int v3231 = v3223 + 1;
  v3222->timer = v3231;
  int * v3225 = v3222->regs;
  int v3226 = v3225[28];
  int v3227 = v3225[12];
  int v3236 = (((((int)((unsigned int)v3226 >> 16)) * ((int)((unsigned int)v3227 >> 16))) + ((int)((unsigned int)((v3226 & 65535) * ((int)((unsigned int)v3227 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3226 >> 16)) * (v3227 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3226 & 65535) * (v3227 & 65535)) >> 16)) + (((v3226 & 65535) * ((int)((unsigned int)v3227 >> 16))) & 65535)) + ((((int)((unsigned int)v3226 >> 16)) * (v3227 & 65535)) & 65535)) >> 16));
  v3225[31] = v3236;
  struct StateT * v3229 = slot_41(v3222);
  return v3229;
}

struct StateT * slot_586(struct StateT * v26821) {
  int v26822 = v26821->timer;
  int v26830 = v26822 + 1;
  v26821->timer = v26830;
  int * v26824 = v26821->regs;
  int v26825 = v26824[8];
  int v26826 = v26824[28];
  int v26835 = v26825 + v26826;
  v26824[12] = v26835;
  struct StateT * v26828 = slot_566(v26821);
  return v26828;
}

struct StateT * slot_784(struct StateT * v31927) {
  int v31928 = v31927->timer;
  int v31936 = v31928 + 1;
  v31927->timer = v31936;
  int * v31930 = v31927->regs;
  int v31931 = v31930[12];
  int v31932 = v31930[5];
  int v31940 = v31931 + v31932;
  v31930[5] = v31940;
  struct StateT * v31934 = slot_799(v31927);
  return v31934;
}

struct StateT * slot_85(struct StateT * v5638) {
  int v5639 = v5638->timer;
  int v5646 = v5639 + 1;
  v5638->timer = v5646;
  int * v5641 = v5638->regs;
  int v5642 = v5641[28];
  int v5649 = v5642 << 13;
  v5641[28] = v5649;
  struct StateT * v5644 = slot_87(v5638);
  return v5644;
}

struct StateT * slot_75(struct StateT * v4502) {
  int v4503 = v4502->timer;
  int v4510 = v4503 + 1;
  v4502->timer = v4510;
  int * v4505 = v4502->regs;
  int v4506 = v4505[7];
  int v4513 = (int)((unsigned int)v4506 >> 19);
  v4505[7] = v4513;
  struct StateT * v4508 = slot_77(v4502);
  return v4508;
}

struct StateT * slot_387(struct StateT * v21194) {
  int v21195 = v21194->timer;
  int v21202 = v21195 + 1;
  v21194->timer = v21202;
  int * v21197 = v21194->regs;
  int v21198 = v21197[28];
  int v21205 = v21198 << 13;
  v21197[28] = v21205;
  struct StateT * v21200 = slot_394(v21194);
  return v21200;
}

struct StateT * slot_565(struct StateT * v26413) {
  int v26414 = v26413->timer;
  int v26422 = v26414 + 1;
  v26413->timer = v26422;
  int * v26416 = v26413->regs;
  int v26417 = v26416[6];
  int v26418 = v26416[17];
  int v26426 = v26417 + v26418;
  v26416[17] = v26426;
  struct StateT * v26420 = slot_571(v26413);
  return v26420;
}

struct StateT * slot_188(struct StateT * v11059) {
  int v11060 = v11059->timer;
  int v11068 = v11060 + 1;
  v11059->timer = v11068;
  int * v11062 = v11059->regs;
  int v11063 = v11062[5];
  int v11064 = v11062[17];
  int v11072 = v11063 | v11064;
  v11062[5] = v11072;
  struct StateT * v11066 = slot_206(v11059);
  return v11066;
}

struct StateT * slot_758(struct StateT * v30381) {
  int * v30382 = v30381->saved_regs;
  int * v30383 = v30381->regs;
  int v30384 = v30383[15];
  v30382[15] = v30384;
  int v30386 = v30381->timer;
  int v30398 = v30386 + 1;
  v30381->timer = v30398;
  int * v30388 = v30381->regs;
  int v30389 = v30388[15];
  int v30390 = v30388[5];
  int v30401 = v30389 + v30390;
  v30388[15] = v30401;
  struct StateT * v30392 = slot_764(v30381);
  return v30392;
}

struct StateT * slot_110(struct StateT * v6422) {
  int v6423 = v6422->timer;
  int v6431 = v6423 + 1;
  v6422->timer = v6431;
  int * v6425 = v6422->regs;
  int v6426 = v6425[6];
  int v6427 = v6425[7];
  int v6436 = v6426 + v6427;
  v6425[17] = v6436;
  struct StateT * v6429 = slot_112(v6422);
  return v6429;
}

struct StateT * slot_301(struct StateT * v13840) {
  int v13841 = v13840->timer;
  int v13853 = v13841 + 1;
  v13840->timer = v13853;
  int * v13843 = v13840->regs;
  int v13844 = v13843[5];
  int v13845 = v13843[9];
  bool v13857 = (v13844 ^ -2147483648) < (v13845 ^ -2147483648);
  int v13848;
  if (v13857) {
    v13848 = 1;
  } else {
    v13848 = 0;
  }
  int * v13849 = v13840->regs;
  v13849[31] = v13848;
  struct StateT * v13851 = slot_305(v13840);
  return v13851;
}

struct StateT * slot_502(struct StateT * v25216) {
  int v25217 = v25216->timer;
  int v25225 = v25217 + 1;
  v25216->timer = v25225;
  int * v25219 = v25216->regs;
  int v25220 = v25219[30];
  int v25221 = v25219[5];
  int v25230 = v25220 + v25221;
  v25219[6] = v25230;
  struct StateT * v25223 = slot_539(v25216);
  return v25223;
}

struct StateT * slot_157(struct StateT * v7664) {
  int v7665 = v7664->timer;
  int v7673 = v7665 + 1;
  v7664->timer = v7673;
  int * v7667 = v7664->regs;
  int v7668 = v7667[7];
  int v7669 = v7667[16];
  int v7678 = v7668 & v7669;
  v7667[29] = v7678;
  struct StateT * v7671 = slot_160(v7664);
  return v7671;
}

struct StateT * slot_1030(struct StateT * v52930) {
  int v52931 = v52930->timer;
  int v53101 = v52931 + 1;
  v52930->timer = v53101;
  int * v52933 = v52930->regs;
  int v52934 = v52933[10];
  int v52935 = v52933[12];
  int * v52936 = v52930->cache_tags;
  int v53106 = (((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2;
  int v52937 = v52936[v53106];
  int v53107 = ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v52938 = v52936[v53107];
  int v53108 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2);
  int v52939 = v52936[v53108];
  int v53109 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v52940 = v52936[v53109];
  int v52941 = v52930->timer;
  int v53110 = v52941 + ((100 ^ (((~(((v52939 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52939 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v52937 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52937 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v52938 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52938 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v52939 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52939 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v52930->timer = v53110;
  bool v53111 = !(((~(((v52937 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52937 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v52938 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52938 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v53035;
  if (v53111) {
    int * v52943 = v52930->cache_age;
    int v53113 = ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v52938 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52938 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v52944 = v52943[v53113];
    int v52945 = v52943[v53106];
    int v53114 = v52945 + ((int)((unsigned int)(v52945 - v52944) >> 31));
    v52943[v53106] = v53114;
    int * v52947 = v52930->cache_age;
    int v52948 = v52947[v53107];
    int v53116 = v52948 + ((int)((unsigned int)(v52948 - v52944) >> 31));
    v52947[v53107] = v53116;
    int * v52950 = v52930->cache_age;
    v52950[v53113] = 0;
    v53035 = v53113;
  } else {
    int * v52953 = v52930->cache_age;
    int v53120 = (((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2;
    int v52954 = v52953[v53120];
    int * v52955 = v52930->cache_tags;
    int v52956 = v52955[v53120];
    int v52957 = v52953[v53107];
    int v52958 = v52955[v53107];
    bool v53122 = !(((~(((v52939 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52939 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v53012;
    if (v53122) {
      int * v52959 = v52930->cache_age;
      int v53124 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v52940 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v52960 = v52959[v53124];
      int v52961 = v52959[v53108];
      int v53125 = v52961 + ((int)((unsigned int)(v52961 - v52960) >> 31));
      v52959[v53108] = v53125;
      int * v52963 = v52930->cache_age;
      int v52964 = v52963[v53109];
      int v53127 = v52964 + ((int)((unsigned int)(v52964 - v52960) >> 31));
      v52963[v53109] = v53127;
      int * v52966 = v52930->cache_age;
      v52966[v53124] = 0;
      v53012 = v53124;
    } else {
      int * v52969 = v52930->cache_age;
      int v53131 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2);
      int v52970 = v52969[v53131];
      int * v52971 = v52930->cache_tags;
      int v52972 = v52971[v53131];
      int v52973 = v52969[v53109];
      int v52974 = v52971[v53109];
      int * v52975 = v52930->cache_dirty;
      int v53134 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v52970 + ((~(((v52972 ^ -1) | (-(v52972 ^ -1))) >> 31)) & 2)) - (v52973 + ((~(((v52974 ^ -1) | (-(v52974 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v52976 = v52975[v53134];
      bool v53135 = !(v52976 == 0);
      if (v53135) {
        int * v52977 = v52930->cache_tags;
        int v52978 = v52977[v53134];
        int * v52979 = v52930->cache_vals;
        int v53138 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v52970 + ((~(((v52972 ^ -1) | (-(v52972 ^ -1))) >> 31)) & 2)) - (v52973 + ((~(((v52974 ^ -1) | (-(v52974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v52980 = v52979[v53138];
        int v53139 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v52970 + ((~(((v52972 ^ -1) | (-(v52972 ^ -1))) >> 31)) & 2)) - (v52973 + ((~(((v52974 ^ -1) | (-(v52974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v52981 = v52979[v53139];
        int * v52982 = v52930->mem;
        int v53141 = v52978 * 2;
        v52982[v53141] = v52980;
        int * v52984 = v52930->mem;
        int v53144 = (v52978 * 2) + 1;
        v52984[v53144] = v52981;
        ;
      } else {
        ;
      }
      int * v52989 = v52930->mem;
      int v53149 = ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) * 2;
      int v52990 = v52989[v53149];
      int v53150 = (((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) * 2) + 1;
      int v52991 = v52989[v53150];
      int * v52992 = v52930->cache_vals;
      int v53152 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v52970 + ((~(((v52972 ^ -1) | (-(v52972 ^ -1))) >> 31)) & 2)) - (v52973 + ((~(((v52974 ^ -1) | (-(v52974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v52992[v53152] = v52990;
      int * v52994 = v52930->cache_vals;
      int v53155 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v52970 + ((~(((v52972 ^ -1) | (-(v52972 ^ -1))) >> 31)) & 2)) - (v52973 + ((~(((v52974 ^ -1) | (-(v52974 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v52994[v53155] = v52991;
      int * v52996 = v52930->cache_tags;
      int v53158 = (int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1);
      v52996[v53134] = v53158;
      int * v52998 = v52930->cache_dirty;
      v52998[v53134] = 0;
      int * v53000 = v52930->cache_age;
      v53000[v53134] = 1;
      int * v53002 = v52930->cache_age;
      int v53003 = v53002[v53134];
      int v53004 = v53002[v53108];
      int v53164 = v53004 + ((int)((unsigned int)(v53004 - v53003) >> 31));
      v53002[v53108] = v53164;
      int * v53006 = v52930->cache_age;
      int v53007 = v53006[v53109];
      int v53166 = v53007 + ((int)((unsigned int)(v53007 - v53003) >> 31));
      v53006[v53109] = v53166;
      int * v53009 = v52930->cache_age;
      v53009[v53134] = 0;
      v53012 = v53134;
    }
    int * v53013 = v52930->cache_vals;
    int v53169 = v53012 * 2;
    int v53014 = v53013[v53169];
    int v53170 = (v53012 * 2) + 1;
    int v53015 = v53013[v53170];
    int v53171 = (((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v52954 + ((~(((v52956 ^ -1) | (-(v52956 ^ -1))) >> 31)) & 2)) - (v52957 + ((~(((v52958 ^ -1) | (-(v52958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v53013[v53171] = v53014;
    int * v53017 = v52930->cache_vals;
    int v53174 = ((((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v52954 + ((~(((v52956 ^ -1) | (-(v52956 ^ -1))) >> 31)) & 2)) - (v52957 + ((~(((v52958 ^ -1) | (-(v52958 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v53017[v53174] = v53015;
    int * v53019 = v52930->cache_tags;
    int v53177 = ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v52954 + ((~(((v52956 ^ -1) | (-(v52956 ^ -1))) >> 31)) & 2)) - (v52957 + ((~(((v52958 ^ -1) | (-(v52958 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v53178 = (int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1);
    v53019[v53177] = v53178;
    int * v53021 = v52930->cache_dirty;
    v53021[v53177] = 0;
    int * v53023 = v52930->cache_age;
    v53023[v53177] = 1;
    int * v53025 = v52930->cache_age;
    int v53026 = v53025[v53177];
    int v53027 = v53025[v53106];
    int v53184 = v53027 + ((int)((unsigned int)(v53027 - v53026) >> 31));
    v53025[v53106] = v53184;
    int * v53029 = v52930->cache_age;
    int v53030 = v53029[v53107];
    int v53186 = v53030 + ((int)((unsigned int)(v53030 - v53026) >> 31));
    v53029[v53107] = v53186;
    int * v53032 = v52930->cache_age;
    v53032[v53177] = 0;
    v53035 = v53177;
  }
  int * v53036 = v52930->cache_vals;
  int v53189 = (v53035 * 2) + (((int)((unsigned int)(v52934 + 4) >> 2)) & 1);
  v53036[v53189] = v52935;
  int * v53038 = v52930->cache_tags;
  int v53039 = v53038[v53108];
  int v53040 = v53038[v53109];
  bool v53192 = !(((~(((v53039 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v53039 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v53040 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v53040 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v53094;
  if (v53192) {
    int * v53041 = v52930->cache_age;
    int v53194 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v53040 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))) | (-(v53040 ^ ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v53042 = v53041[v53194];
    int v53043 = v53041[v53108];
    int v53195 = v53043 + ((int)((unsigned int)(v53043 - v53042) >> 31));
    v53041[v53108] = v53195;
    int * v53045 = v52930->cache_age;
    int v53046 = v53045[v53109];
    int v53197 = v53046 + ((int)((unsigned int)(v53046 - v53042) >> 31));
    v53045[v53109] = v53197;
    int * v53048 = v52930->cache_age;
    v53048[v53194] = 0;
    v53094 = v53194;
  } else {
    int * v53051 = v52930->cache_age;
    int v53201 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2);
    int v53052 = v53051[v53201];
    int * v53053 = v52930->cache_tags;
    int v53054 = v53053[v53201];
    int v53055 = v53051[v53109];
    int v53056 = v53053[v53109];
    int * v53057 = v52930->cache_dirty;
    int v53204 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v53052 + ((~(((v53054 ^ -1) | (-(v53054 ^ -1))) >> 31)) & 2)) - (v53055 + ((~(((v53056 ^ -1) | (-(v53056 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v53058 = v53057[v53204];
    bool v53205 = !(v53058 == 0);
    if (v53205) {
      int * v53059 = v52930->cache_tags;
      int v53060 = v53059[v53204];
      int * v53061 = v52930->cache_vals;
      int v53208 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v53052 + ((~(((v53054 ^ -1) | (-(v53054 ^ -1))) >> 31)) & 2)) - (v53055 + ((~(((v53056 ^ -1) | (-(v53056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v53062 = v53061[v53208];
      int v53209 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v53052 + ((~(((v53054 ^ -1) | (-(v53054 ^ -1))) >> 31)) & 2)) - (v53055 + ((~(((v53056 ^ -1) | (-(v53056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v53063 = v53061[v53209];
      int * v53064 = v52930->mem;
      int v53211 = v53060 * 2;
      v53064[v53211] = v53062;
      int * v53066 = v52930->mem;
      int v53214 = (v53060 * 2) + 1;
      v53066[v53214] = v53063;
      ;
    } else {
      ;
    }
    int * v53071 = v52930->mem;
    int v53219 = ((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) * 2;
    int v53072 = v53071[v53219];
    int v53220 = (((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) * 2) + 1;
    int v53073 = v53071[v53220];
    int * v53074 = v52930->cache_vals;
    int v53222 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v53052 + ((~(((v53054 ^ -1) | (-(v53054 ^ -1))) >> 31)) & 2)) - (v53055 + ((~(((v53056 ^ -1) | (-(v53056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v53074[v53222] = v53072;
    int * v53076 = v52930->cache_vals;
    int v53225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v53052 + ((~(((v53054 ^ -1) | (-(v53054 ^ -1))) >> 31)) & 2)) - (v53055 + ((~(((v53056 ^ -1) | (-(v53056 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v53076[v53225] = v53073;
    int * v53078 = v52930->cache_tags;
    int v53228 = (int)((unsigned int)((int)((unsigned int)(v52934 + 4) >> 2)) >> 1);
    v53078[v53204] = v53228;
    int * v53080 = v52930->cache_dirty;
    v53080[v53204] = 0;
    int * v53082 = v52930->cache_age;
    v53082[v53204] = 1;
    int * v53084 = v52930->cache_age;
    int v53085 = v53084[v53204];
    int v53086 = v53084[v53108];
    int v53234 = v53086 + ((int)((unsigned int)(v53086 - v53085) >> 31));
    v53084[v53108] = v53234;
    int * v53088 = v52930->cache_age;
    int v53089 = v53088[v53109];
    int v53236 = v53089 + ((int)((unsigned int)(v53089 - v53085) >> 31));
    v53088[v53109] = v53236;
    int * v53091 = v52930->cache_age;
    v53091[v53204] = 0;
    v53094 = v53204;
  }
  int * v53095 = v52930->cache_vals;
  int v53239 = (v53094 * 2) + (((int)((unsigned int)(v52934 + 4) >> 2)) & 1);
  v53095[v53239] = v52935;
  int * v53097 = v52930->cache_dirty;
  v53097[v53094] = 1;
  struct StateT * v53099 = slot_1038(v52930);
  return v53099;
}

struct StateT * slot_453(struct StateT * v24355) {
  int v24356 = v24355->timer;
  int v24364 = v24356 + 1;
  v24355->timer = v24364;
  int * v24358 = v24355->regs;
  int v24359 = v24358[11];
  int v24360 = v24358[12];
  int v24369 = v24359 * v24360;
  v24358[28] = v24369;
  struct StateT * v24362 = slot_489(v24355);
  return v24362;
}

struct StateT * slot_26(struct StateT * v2306) {
  int v2307 = v2306->timer;
  int v2477 = v2307 + 1;
  v2306->timer = v2477;
  int * v2309 = v2306->regs;
  int v2310 = v2309[10];
  int v2311 = v2309[15];
  int * v2312 = v2306->cache_tags;
  int v2482 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2313 = v2312[v2482];
  int v2483 = ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2314 = v2312[v2483];
  int v2484 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2315 = v2312[v2484];
  int v2485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2316 = v2312[v2485];
  int v2317 = v2306->timer;
  int v2486 = v2317 + ((100 ^ (((~(((v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2306->timer = v2486;
  bool v2487 = !(((~(((v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2313 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2411;
  if (v2487) {
    int * v2319 = v2306->cache_age;
    int v2489 = ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2314 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2320 = v2319[v2489];
    int v2321 = v2319[v2482];
    int v2490 = v2321 + ((int)((unsigned int)(v2321 - v2320) >> 31));
    v2319[v2482] = v2490;
    int * v2323 = v2306->cache_age;
    int v2324 = v2323[v2483];
    int v2492 = v2324 + ((int)((unsigned int)(v2324 - v2320) >> 31));
    v2323[v2483] = v2492;
    int * v2326 = v2306->cache_age;
    v2326[v2489] = 0;
    v2411 = v2489;
  } else {
    int * v2329 = v2306->cache_age;
    int v2496 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2330 = v2329[v2496];
    int * v2331 = v2306->cache_tags;
    int v2332 = v2331[v2496];
    int v2333 = v2329[v2483];
    int v2334 = v2331[v2483];
    bool v2498 = !(((~(((v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2315 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2388;
    if (v2498) {
      int * v2335 = v2306->cache_age;
      int v2500 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2316 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2336 = v2335[v2500];
      int v2337 = v2335[v2484];
      int v2501 = v2337 + ((int)((unsigned int)(v2337 - v2336) >> 31));
      v2335[v2484] = v2501;
      int * v2339 = v2306->cache_age;
      int v2340 = v2339[v2485];
      int v2503 = v2340 + ((int)((unsigned int)(v2340 - v2336) >> 31));
      v2339[v2485] = v2503;
      int * v2342 = v2306->cache_age;
      v2342[v2500] = 0;
      v2388 = v2500;
    } else {
      int * v2345 = v2306->cache_age;
      int v2507 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2346 = v2345[v2507];
      int * v2347 = v2306->cache_tags;
      int v2348 = v2347[v2507];
      int v2349 = v2345[v2485];
      int v2350 = v2347[v2485];
      int * v2351 = v2306->cache_dirty;
      int v2510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2352 = v2351[v2510];
      bool v2511 = !(v2352 == 0);
      if (v2511) {
        int * v2353 = v2306->cache_tags;
        int v2354 = v2353[v2510];
        int * v2355 = v2306->cache_vals;
        int v2514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2356 = v2355[v2514];
        int v2515 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2357 = v2355[v2515];
        int * v2358 = v2306->mem;
        int v2517 = v2354 * 2;
        v2358[v2517] = v2356;
        int * v2360 = v2306->mem;
        int v2520 = (v2354 * 2) + 1;
        v2360[v2520] = v2357;
        ;
      } else {
        ;
      }
      int * v2365 = v2306->mem;
      int v2525 = ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2;
      int v2366 = v2365[v2525];
      int v2526 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2367 = v2365[v2526];
      int * v2368 = v2306->cache_vals;
      int v2528 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2368[v2528] = v2366;
      int * v2370 = v2306->cache_vals;
      int v2531 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2346 + ((~(((v2348 ^ -1) | (-(v2348 ^ -1))) >> 31)) & 2)) - (v2349 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2370[v2531] = v2367;
      int * v2372 = v2306->cache_tags;
      int v2534 = (int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1);
      v2372[v2510] = v2534;
      int * v2374 = v2306->cache_dirty;
      v2374[v2510] = 0;
      int * v2376 = v2306->cache_age;
      v2376[v2510] = 1;
      int * v2378 = v2306->cache_age;
      int v2379 = v2378[v2510];
      int v2380 = v2378[v2484];
      int v2540 = v2380 + ((int)((unsigned int)(v2380 - v2379) >> 31));
      v2378[v2484] = v2540;
      int * v2382 = v2306->cache_age;
      int v2383 = v2382[v2485];
      int v2542 = v2383 + ((int)((unsigned int)(v2383 - v2379) >> 31));
      v2382[v2485] = v2542;
      int * v2385 = v2306->cache_age;
      v2385[v2510] = 0;
      v2388 = v2510;
    }
    int * v2389 = v2306->cache_vals;
    int v2545 = v2388 * 2;
    int v2390 = v2389[v2545];
    int v2546 = (v2388 * 2) + 1;
    int v2391 = v2389[v2546];
    int v2547 = (((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2330 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2)) - (v2333 + ((~(((v2334 ^ -1) | (-(v2334 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2389[v2547] = v2390;
    int * v2393 = v2306->cache_vals;
    int v2550 = ((((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2330 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2)) - (v2333 + ((~(((v2334 ^ -1) | (-(v2334 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2393[v2550] = v2391;
    int * v2395 = v2306->cache_tags;
    int v2553 = ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2330 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2)) - (v2333 + ((~(((v2334 ^ -1) | (-(v2334 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2554 = (int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1);
    v2395[v2553] = v2554;
    int * v2397 = v2306->cache_dirty;
    v2397[v2553] = 0;
    int * v2399 = v2306->cache_age;
    v2399[v2553] = 1;
    int * v2401 = v2306->cache_age;
    int v2402 = v2401[v2553];
    int v2403 = v2401[v2482];
    int v2560 = v2403 + ((int)((unsigned int)(v2403 - v2402) >> 31));
    v2401[v2482] = v2560;
    int * v2405 = v2306->cache_age;
    int v2406 = v2405[v2483];
    int v2562 = v2406 + ((int)((unsigned int)(v2406 - v2402) >> 31));
    v2405[v2483] = v2562;
    int * v2408 = v2306->cache_age;
    v2408[v2553] = 0;
    v2411 = v2553;
  }
  int * v2412 = v2306->cache_vals;
  int v2565 = (v2411 * 2) + (((int)((unsigned int)(v2310 + 4) >> 2)) & 1);
  v2412[v2565] = v2311;
  int * v2414 = v2306->cache_tags;
  int v2415 = v2414[v2484];
  int v2416 = v2414[v2485];
  bool v2568 = !(((~(((v2415 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2415 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2470;
  if (v2568) {
    int * v2417 = v2306->cache_age;
    int v2570 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))) | (-(v2416 ^ ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2418 = v2417[v2570];
    int v2419 = v2417[v2484];
    int v2571 = v2419 + ((int)((unsigned int)(v2419 - v2418) >> 31));
    v2417[v2484] = v2571;
    int * v2421 = v2306->cache_age;
    int v2422 = v2421[v2485];
    int v2573 = v2422 + ((int)((unsigned int)(v2422 - v2418) >> 31));
    v2421[v2485] = v2573;
    int * v2424 = v2306->cache_age;
    v2424[v2570] = 0;
    v2470 = v2570;
  } else {
    int * v2427 = v2306->cache_age;
    int v2577 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2428 = v2427[v2577];
    int * v2429 = v2306->cache_tags;
    int v2430 = v2429[v2577];
    int v2431 = v2427[v2485];
    int v2432 = v2429[v2485];
    int * v2433 = v2306->cache_dirty;
    int v2580 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2434 = v2433[v2580];
    bool v2581 = !(v2434 == 0);
    if (v2581) {
      int * v2435 = v2306->cache_tags;
      int v2436 = v2435[v2580];
      int * v2437 = v2306->cache_vals;
      int v2584 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2438 = v2437[v2584];
      int v2585 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2439 = v2437[v2585];
      int * v2440 = v2306->mem;
      int v2587 = v2436 * 2;
      v2440[v2587] = v2438;
      int * v2442 = v2306->mem;
      int v2590 = (v2436 * 2) + 1;
      v2442[v2590] = v2439;
      ;
    } else {
      ;
    }
    int * v2447 = v2306->mem;
    int v2595 = ((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2;
    int v2448 = v2447[v2595];
    int v2596 = (((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2449 = v2447[v2596];
    int * v2450 = v2306->cache_vals;
    int v2598 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2450[v2598] = v2448;
    int * v2452 = v2306->cache_vals;
    int v2601 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2428 + ((~(((v2430 ^ -1) | (-(v2430 ^ -1))) >> 31)) & 2)) - (v2431 + ((~(((v2432 ^ -1) | (-(v2432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2452[v2601] = v2449;
    int * v2454 = v2306->cache_tags;
    int v2604 = (int)((unsigned int)((int)((unsigned int)(v2310 + 4) >> 2)) >> 1);
    v2454[v2580] = v2604;
    int * v2456 = v2306->cache_dirty;
    v2456[v2580] = 0;
    int * v2458 = v2306->cache_age;
    v2458[v2580] = 1;
    int * v2460 = v2306->cache_age;
    int v2461 = v2460[v2580];
    int v2462 = v2460[v2484];
    int v2610 = v2462 + ((int)((unsigned int)(v2462 - v2461) >> 31));
    v2460[v2484] = v2610;
    int * v2464 = v2306->cache_age;
    int v2465 = v2464[v2485];
    int v2612 = v2465 + ((int)((unsigned int)(v2465 - v2461) >> 31));
    v2464[v2485] = v2612;
    int * v2467 = v2306->cache_age;
    v2467[v2580] = 0;
    v2470 = v2580;
  }
  int * v2471 = v2306->cache_vals;
  int v2615 = (v2470 * 2) + (((int)((unsigned int)(v2310 + 4) >> 2)) & 1);
  v2471[v2615] = v2311;
  int * v2473 = v2306->cache_dirty;
  v2473[v2470] = 1;
  struct StateT * v2475 = slot_27(v2306);
  return v2475;
}

struct StateT * slot_206(struct StateT * v12096) {
  int v12097 = v12096->timer;
  int v12105 = v12097 + 1;
  v12096->timer = v12105;
  int * v12099 = v12096->regs;
  int v12100 = v12099[6];
  int v12101 = v12099[12];
  int v12110 = (((((int)((unsigned int)v12100 >> 16)) * ((int)((unsigned int)v12101 >> 16))) + ((int)((unsigned int)((v12100 & 65535) * ((int)((unsigned int)v12101 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v12100 >> 16)) * (v12101 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v12100 & 65535) * (v12101 & 65535)) >> 16)) + (((v12100 & 65535) * ((int)((unsigned int)v12101 >> 16))) & 65535)) + ((((int)((unsigned int)v12100 >> 16)) * (v12101 & 65535)) & 65535)) >> 16));
  v12099[17] = v12110;
  struct StateT * v12103 = slot_210(v12096);
  return v12103;
}

struct StateT * slot_14(struct StateT * v1796) {
  int v1797 = v1796->timer;
  int v1805 = v1797 + 1;
  v1796->timer = v1805;
  int * v1799 = v1796->regs;
  int v1800 = v1799[15];
  int v1801 = v1799[13];
  int v1810 = v1800 * v1801;
  v1799[29] = v1810;
  struct StateT * v1803 = slot_15(v1796);
  return v1803;
}

struct StateT * slot_602(struct StateT * v27111) {
  int v27112 = v27111->timer;
  int v27124 = v27112 + 1;
  v27111->timer = v27124;
  int * v27114 = v27111->regs;
  int v27115 = v27114[12];
  int v27116 = v27114[8];
  bool v27128 = (v27115 ^ -2147483648) < (v27116 ^ -2147483648);
  int v27119;
  if (v27128) {
    v27119 = 1;
  } else {
    v27119 = 0;
  }
  int * v27120 = v27111->regs;
  v27120[28] = v27119;
  struct StateT * v27122 = slot_611(v27111);
  return v27122;
}

struct StateT * slot_838(struct StateT * v38456) {
  int v38457 = v38456->timer;
  int v38465 = v38457 + 1;
  v38456->timer = v38465;
  int * v38459 = v38456->regs;
  int v38460 = v38459[13];
  int v38461 = v38459[12];
  int v38469 = v38460 + v38461;
  v38459[12] = v38469;
  struct StateT * v38463 = slot_905(v38456);
  return v38463;
}

struct StateT * slot_639(struct StateT * v27806) {
  int * v27807 = v27806->saved_regs;
  int * v27808 = v27806->regs;
  int v27809 = v27808[17];
  v27807[17] = v27809;
  int v27811 = v27806->timer;
  int v27822 = v27811 + 1;
  v27806->timer = v27822;
  int * v27813 = v27806->regs;
  int v27814 = v27813[17];
  int v27824 = (int)((unsigned int)v27814 >> 19);
  v27813[17] = v27824;
  struct StateT * v27816 = slot_616(v27806);
  return v27816;
}

struct StateT * slot_36(struct StateT * v3156) {
  int v3157 = v3156->timer;
  int v3165 = v3157 + 1;
  v3156->timer = v3165;
  int * v3159 = v3156->regs;
  int v3160 = v3159[5];
  int v3161 = v3159[6];
  int v3169 = v3160 + v3161;
  v3159[5] = v3169;
  struct StateT * v3163 = slot_37(v3156);
  return v3163;
}

struct StateT * slot_57(struct StateT * v3525) {
  int v3526 = v3525->timer;
  int v3534 = v3526 + 1;
  v3525->timer = v3534;
  int * v3528 = v3525->regs;
  int v3529 = v3528[30];
  int v3530 = v3528[6];
  int v3538 = v3529 + v3530;
  v3528[6] = v3538;
  struct StateT * v3532 = slot_58(v3525);
  return v3532;
}

struct StateT * slot_426(struct StateT * v23539) {
  int v23540 = v23539->timer;
  int v23547 = v23540 + 1;
  v23539->timer = v23547;
  int * v23542 = v23539->regs;
  int v23543 = v23542[5];
  int v23550 = v23543 << 13;
  v23542[5] = v23550;
  struct StateT * v23545 = slot_376(v23539);
  return v23545;
}

struct StateT * slot_62(struct StateT * v3623) {
  int v3624 = v3623->timer;
  int v3632 = v3624 + 1;
  v3623->timer = v3632;
  int * v3626 = v3623->regs;
  int v3627 = v3626[7];
  int v3628 = v3626[28];
  int v3636 = v3627 + v3628;
  v3626[7] = v3636;
  struct StateT * v3630 = slot_63(v3623);
  return v3630;
}

struct StateT * slot_323(struct StateT * v14891) {
  int * v14892 = v14891->saved_regs;
  int * v14893 = v14891->regs;
  int v14894 = v14893[28];
  v14892[28] = v14894;
  int v14896 = v14891->timer;
  int v14912 = v14896 + 1;
  v14891->timer = v14912;
  int * v14898 = v14891->regs;
  int v14899 = v14898[7];
  int v14900 = v14898[29];
  bool v14916 = (v14899 ^ -2147483648) < (v14900 ^ -2147483648);
  int v14903;
  if (v14916) {
    v14903 = 1;
  } else {
    v14903 = 0;
  }
  int * v14904 = v14891->regs;
  v14904[28] = v14903;
  struct StateT * v14906 = slot_310(v14891);
  return v14906;
}

struct StateT * slot_628(struct StateT * v27608) {
  int * v27609 = v27608->saved_regs;
  int * v27610 = v27608->regs;
  int v27611 = v27610[16];
  v27609[16] = v27611;
  int v27613 = v27608->timer;
  int v27625 = v27613 + 1;
  v27608->timer = v27625;
  int * v27615 = v27608->regs;
  int v27616 = v27615[17];
  int v27617 = v27615[16];
  int v27628 = v27616 & v27617;
  v27615[16] = v27628;
  struct StateT * v27619 = slot_639(v27608);
  return v27619;
}

struct StateT * slot_23(struct StateT * v1961) {
  int v1962 = v1961->timer;
  int v1969 = v1962 + 1;
  v1961->timer = v1969;
  int * v1964 = v1961->regs;
  int v1965 = v1964[17];
  int v1972 = (int)((unsigned int)v1965 >> 19);
  v1964[17] = v1972;
  struct StateT * v1967 = slot_24(v1961);
  return v1967;
}

struct StateT * slot_2(struct StateT * v331) {
  int v332 = v331->timer;
  int v502 = v332 + 1;
  v331->timer = v502;
  int * v334 = v331->regs;
  int v335 = v334[2];
  int v336 = v334[9];
  int * v337 = v331->cache_tags;
  int v507 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v507];
  int v508 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v508];
  int v509 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v509];
  int v510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v510];
  int v342 = v331->timer;
  int v511 = v342 + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v331->timer = v511;
  bool v512 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v436;
  if (v512) {
    int * v344 = v331->cache_age;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v345 = v344[v514];
    int v346 = v344[v507];
    int v515 = v346 + ((int)((unsigned int)(v346 - v345) >> 31));
    v344[v507] = v515;
    int * v348 = v331->cache_age;
    int v349 = v348[v508];
    int v517 = v349 + ((int)((unsigned int)(v349 - v345) >> 31));
    v348[v508] = v517;
    int * v351 = v331->cache_age;
    v351[v514] = 0;
    v436 = v514;
  } else {
    int * v354 = v331->cache_age;
    int v521 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2;
    int v355 = v354[v521];
    int * v356 = v331->cache_tags;
    int v357 = v356[v521];
    int v358 = v354[v508];
    int v359 = v356[v508];
    bool v523 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v413;
    if (v523) {
      int * v360 = v331->cache_age;
      int v525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v361 = v360[v525];
      int v362 = v360[v509];
      int v526 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
      v360[v509] = v526;
      int * v364 = v331->cache_age;
      int v365 = v364[v510];
      int v528 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
      v364[v510] = v528;
      int * v367 = v331->cache_age;
      v367[v525] = 0;
      v413 = v525;
    } else {
      int * v370 = v331->cache_age;
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2);
      int v371 = v370[v532];
      int * v372 = v331->cache_tags;
      int v373 = v372[v532];
      int v374 = v370[v510];
      int v375 = v372[v510];
      int * v376 = v331->cache_dirty;
      int v535 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v377 = v376[v535];
      bool v536 = !(v377 == 0);
      if (v536) {
        int * v378 = v331->cache_tags;
        int v379 = v378[v535];
        int * v380 = v331->cache_vals;
        int v539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v381 = v380[v539];
        int v540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v382 = v380[v540];
        int * v383 = v331->mem;
        int v542 = v379 * 2;
        v383[v542] = v381;
        int * v385 = v331->mem;
        int v545 = (v379 * 2) + 1;
        v385[v545] = v382;
        ;
      } else {
        ;
      }
      int * v390 = v331->mem;
      int v550 = ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2;
      int v391 = v390[v550];
      int v551 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2) + 1;
      int v392 = v390[v551];
      int * v393 = v331->cache_vals;
      int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v393[v553] = v391;
      int * v395 = v331->cache_vals;
      int v556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v395[v556] = v392;
      int * v397 = v331->cache_tags;
      int v559 = (int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1);
      v397[v535] = v559;
      int * v399 = v331->cache_dirty;
      v399[v535] = 0;
      int * v401 = v331->cache_age;
      v401[v535] = 1;
      int * v403 = v331->cache_age;
      int v404 = v403[v535];
      int v405 = v403[v509];
      int v565 = v405 + ((int)((unsigned int)(v405 - v404) >> 31));
      v403[v509] = v565;
      int * v407 = v331->cache_age;
      int v408 = v407[v510];
      int v567 = v408 + ((int)((unsigned int)(v408 - v404) >> 31));
      v407[v510] = v567;
      int * v410 = v331->cache_age;
      v410[v535] = 0;
      v413 = v535;
    }
    int * v414 = v331->cache_vals;
    int v570 = v413 * 2;
    int v415 = v414[v570];
    int v571 = (v413 * 2) + 1;
    int v416 = v414[v571];
    int v572 = (((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v414[v572] = v415;
    int * v418 = v331->cache_vals;
    int v575 = ((((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v418[v575] = v416;
    int * v420 = v331->cache_tags;
    int v578 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v579 = (int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1);
    v420[v578] = v579;
    int * v422 = v331->cache_dirty;
    v422[v578] = 0;
    int * v424 = v331->cache_age;
    v424[v578] = 1;
    int * v426 = v331->cache_age;
    int v427 = v426[v578];
    int v428 = v426[v507];
    int v585 = v428 + ((int)((unsigned int)(v428 - v427) >> 31));
    v426[v507] = v585;
    int * v430 = v331->cache_age;
    int v431 = v430[v508];
    int v587 = v431 + ((int)((unsigned int)(v431 - v427) >> 31));
    v430[v508] = v587;
    int * v433 = v331->cache_age;
    v433[v578] = 0;
    v436 = v578;
  }
  int * v437 = v331->cache_vals;
  int v590 = (v436 * 2) + (((int)((unsigned int)(v335 + 8) >> 2)) & 1);
  v437[v590] = v336;
  int * v439 = v331->cache_tags;
  int v440 = v439[v509];
  int v441 = v439[v510];
  bool v593 = !(((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v495;
  if (v593) {
    int * v442 = v331->cache_age;
    int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v443 = v442[v595];
    int v444 = v442[v509];
    int v596 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[v509] = v596;
    int * v446 = v331->cache_age;
    int v447 = v446[v510];
    int v598 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[v510] = v598;
    int * v449 = v331->cache_age;
    v449[v595] = 0;
    v495 = v595;
  } else {
    int * v452 = v331->cache_age;
    int v602 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2);
    int v453 = v452[v602];
    int * v454 = v331->cache_tags;
    int v455 = v454[v602];
    int v456 = v452[v510];
    int v457 = v454[v510];
    int * v458 = v331->cache_dirty;
    int v605 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v459 = v458[v605];
    bool v606 = !(v459 == 0);
    if (v606) {
      int * v460 = v331->cache_tags;
      int v461 = v460[v605];
      int * v462 = v331->cache_vals;
      int v609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v463 = v462[v609];
      int v610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v464 = v462[v610];
      int * v465 = v331->mem;
      int v612 = v461 * 2;
      v465[v612] = v463;
      int * v467 = v331->mem;
      int v615 = (v461 * 2) + 1;
      v467[v615] = v464;
      ;
    } else {
      ;
    }
    int * v472 = v331->mem;
    int v620 = ((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2;
    int v473 = v472[v620];
    int v621 = (((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) * 2) + 1;
    int v474 = v472[v621];
    int * v475 = v331->cache_vals;
    int v623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v475[v623] = v473;
    int * v477 = v331->cache_vals;
    int v626 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v477[v626] = v474;
    int * v479 = v331->cache_tags;
    int v629 = (int)((unsigned int)((int)((unsigned int)(v335 + 8) >> 2)) >> 1);
    v479[v605] = v629;
    int * v481 = v331->cache_dirty;
    v481[v605] = 0;
    int * v483 = v331->cache_age;
    v483[v605] = 1;
    int * v485 = v331->cache_age;
    int v486 = v485[v605];
    int v487 = v485[v509];
    int v635 = v487 + ((int)((unsigned int)(v487 - v486) >> 31));
    v485[v509] = v635;
    int * v489 = v331->cache_age;
    int v490 = v489[v510];
    int v637 = v490 + ((int)((unsigned int)(v490 - v486) >> 31));
    v489[v510] = v637;
    int * v492 = v331->cache_age;
    v492[v605] = 0;
    v495 = v605;
  }
  int * v496 = v331->cache_vals;
  int v640 = (v495 * 2) + (((int)((unsigned int)(v335 + 8) >> 2)) & 1);
  v496[v640] = v336;
  int * v498 = v331->cache_dirty;
  v498[v495] = 1;
  struct StateT * v500 = slot_3(v331);
  return v500;
}

struct StateT * slot_86(struct StateT * v5652) {
  int v5653 = v5652->timer;
  int v5661 = v5653 + 1;
  v5652->timer = v5661;
  int * v5655 = v5652->regs;
  int v5656 = v5655[7];
  int v5657 = v5655[28];
  int v5665 = v5656 | v5657;
  v5655[7] = v5665;
  struct StateT * v5659 = slot_95(v5652);
  return v5659;
}

struct StateT * slot_100(struct StateT * v6253) {
  int v6254 = v6253->timer;
  int v6262 = v6254 + 1;
  v6253->timer = v6262;
  int * v6256 = v6253->regs;
  int v6257 = v6256[6];
  int v6258 = v6256[13];
  int v6267 = (((((int)((unsigned int)v6257 >> 16)) * ((int)((unsigned int)v6258 >> 16))) + ((int)((unsigned int)((v6257 & 65535) * ((int)((unsigned int)v6258 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6257 >> 16)) * (v6258 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6257 & 65535) * (v6258 & 65535)) >> 16)) + (((v6257 & 65535) * ((int)((unsigned int)v6258 >> 16))) & 65535)) + ((((int)((unsigned int)v6257 >> 16)) * (v6258 & 65535)) & 65535)) >> 16));
  v6256[8] = v6267;
  struct StateT * v6260 = slot_109(v6253);
  return v6260;
}

struct StateT * slot_13(struct StateT * v1779) {
  int v1780 = v1779->timer;
  int v1788 = v1780 + 1;
  v1779->timer = v1788;
  int * v1782 = v1779->regs;
  int v1783 = v1782[14];
  int v1784 = v1782[13];
  int v1793 = (((((int)((unsigned int)v1783 >> 16)) * ((int)((unsigned int)v1784 >> 16))) + ((int)((unsigned int)((v1783 & 65535) * ((int)((unsigned int)v1784 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1783 >> 16)) * (v1784 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1783 & 65535) * (v1784 & 65535)) >> 16)) + (((v1783 & 65535) * ((int)((unsigned int)v1784 >> 16))) & 65535)) + ((((int)((unsigned int)v1783 >> 16)) * (v1784 & 65535)) & 65535)) >> 16));
  v1782[28] = v1793;
  struct StateT * v1786 = slot_14(v1779);
  return v1786;
}

struct StateT * slot_109(struct StateT * v6405) {
  int v6406 = v6405->timer;
  int v6414 = v6406 + 1;
  v6405->timer = v6414;
  int * v6408 = v6405->regs;
  int v6409 = v6408[29];
  int v6410 = v6408[13];
  int v6419 = v6409 * v6410;
  v6408[9] = v6419;
  struct StateT * v6412 = slot_104(v6405);
  return v6412;
}

struct StateT * slot_224(struct StateT * v12396) {
  int v12397 = v12396->timer;
  int v12405 = v12397 + 1;
  v12396->timer = v12405;
  int * v12399 = v12396->regs;
  int v12400 = v12399[28];
  int v12401 = v12399[17];
  int v12410 = v12400 + v12401;
  v12399[29] = v12410;
  struct StateT * v12403 = slot_228(v12396);
  return v12403;
}

struct StateT * slot_184(struct StateT * v10322) {
  int v10323 = v10322->timer;
  int v10330 = v10323 + 1;
  v10322->timer = v10330;
  int * v10325 = v10322->regs;
  int v10326 = v10325[5];
  int v10333 = v10326 << 13;
  v10325[5] = v10333;
  struct StateT * v10328 = slot_188(v10322);
  return v10328;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_352(struct StateT * v17482) {
  int v17483 = v17482->timer;
  int v17490 = v17483 + 1;
  v17482->timer = v17490;
  int * v17485 = v17482->regs;
  int v17486 = v17485[28];
  int v17494 = (int)((unsigned int)v17486 >> 19);
  v17485[17] = v17494;
  struct StateT * v17488 = slot_387(v17482);
  return v17488;
}

struct StateT * slot_249(struct StateT * v12857) {
  int v12858 = v12857->timer;
  int v12866 = v12858 + 1;
  v12857->timer = v12866;
  int * v12860 = v12857->regs;
  int v12861 = v12860[6];
  int v12862 = v12860[12];
  int v12870 = v12861 * v12862;
  v12860[6] = v12870;
  struct StateT * v12864 = slot_224(v12857);
  return v12864;
}

struct StateT * slot_11(struct StateT * v1745) {
  int v1746 = v1745->timer;
  int v1754 = v1746 + 1;
  v1745->timer = v1754;
  int * v1748 = v1745->regs;
  int v1749 = v1748[15];
  int v1750 = v1748[12];
  int v1759 = (((((int)((unsigned int)v1749 >> 16)) * ((int)((unsigned int)v1750 >> 16))) + ((int)((unsigned int)((v1749 & 65535) * ((int)((unsigned int)v1750 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1749 >> 16)) * (v1750 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1749 & 65535) * (v1750 & 65535)) >> 16)) + (((v1749 & 65535) * ((int)((unsigned int)v1750 >> 16))) & 65535)) + ((((int)((unsigned int)v1749 >> 16)) * (v1750 & 65535)) & 65535)) >> 16));
  v1748[6] = v1759;
  struct StateT * v1752 = slot_12(v1745);
  return v1752;
}

struct StateT * slot_228(struct StateT * v12464) {
  int v12465 = v12464->timer;
  int v12473 = v12465 + 1;
  v12464->timer = v12473;
  int * v12467 = v12464->regs;
  int v12468 = v12467[6];
  int v12469 = v12467[7];
  int v12478 = v12468 + v12469;
  v12467[17] = v12478;
  struct StateT * v12471 = slot_232(v12464);
  return v12471;
}

struct StateT * slot_268(struct StateT * v13212) {
  int v13213 = v13212->timer;
  int v13225 = v13213 + 1;
  v13212->timer = v13225;
  int * v13215 = v13212->regs;
  int v13216 = v13215[6];
  int v13217 = v13215[7];
  bool v13229 = (v13216 ^ -2147483648) < (v13217 ^ -2147483648);
  int v13220;
  if (v13229) {
    v13220 = 1;
  } else {
    v13220 = 0;
  }
  int * v13221 = v13212->regs;
  v13221[6] = v13220;
  struct StateT * v13223 = slot_301(v13212);
  return v13223;
}

struct StateT * slot_501(struct StateT * v25200) {
  int v25201 = v25200->timer;
  int v25209 = v25201 + 1;
  v25200->timer = v25209;
  int * v25203 = v25200->regs;
  int v25204 = v25203[6];
  int v25205 = v25203[12];
  int v25213 = v25204 * v25205;
  v25203[12] = v25213;
  struct StateT * v25207 = slot_509(v25200);
  return v25207;
}

struct StateT * slot_979(struct StateT * v49330) {
  int v49331 = v49330->timer;
  int v49339 = v49331 + 1;
  v49330->timer = v49339;
  int * v49333 = v49330->regs;
  int v49334 = v49333[14];
  int v49335 = v49333[13];
  int v49343 = v49334 + v49335;
  v49333[13] = v49343;
  struct StateT * v49337 = slot_988(v49330);
  return v49337;
}

struct StateT * slot_136(struct StateT * v6917) {
  int v6918 = v6917->timer;
  int v6926 = v6918 + 1;
  v6917->timer = v6926;
  int * v6920 = v6917->regs;
  int v6921 = v6920[30];
  int v6922 = v6920[28];
  int v6931 = v6921 + v6922;
  v6920[7] = v6931;
  struct StateT * v6924 = slot_138(v6917);
  return v6924;
}

struct StateT * slot_310(struct StateT * v14030) {
  int v14031 = v14030->timer;
  int v14039 = v14031 + 1;
  v14030->timer = v14039;
  int * v14033 = v14030->regs;
  int v14034 = v14033[5];
  int v14035 = v14033[28];
  int v14043 = v14034 + v14035;
  v14033[28] = v14043;
  struct StateT * v14037 = slot_300(v14030);
  return v14037;
}

struct StateT * slot_197(struct StateT * v11578) {
  int v11579 = v11578->timer;
  int v11587 = v11579 + 1;
  v11578->timer = v11587;
  int * v11581 = v11578->regs;
  int v11582 = v11581[6];
  int v11583 = v11581[5];
  int v11591 = v11582 + v11583;
  v11581[5] = v11591;
  struct StateT * v11585 = slot_187(v11578);
  return v11585;
}

struct StateT * slot_68(struct StateT * v3735) {
  int * v3736 = v3735->saved_regs;
  int * v3737 = v3735->regs;
  int v3738 = v3737[7];
  v3736[7] = v3738;
  int v3740 = v3735->timer;
  int v3751 = v3740 + 1;
  v3735->timer = v3751;
  int * v3742 = v3735->regs;
  int v3743 = v3742[7];
  int v3753 = (int)((unsigned int)v3743 >> 19);
  v3742[7] = v3753;
  struct StateT * v3745 = slot_69(v3735);
  return v3745;
}

struct StateT * slot_105(struct StateT * v6338) {
  int v6339 = v6338->timer;
  int v6347 = v6339 + 1;
  v6338->timer = v6347;
  int * v6341 = v6338->regs;
  int v6342 = v6341[6];
  int v6343 = v6341[13];
  int v6352 = v6342 * v6343;
  v6341[31] = v6352;
  struct StateT * v6345 = slot_100(v6338);
  return v6345;
}

struct StateT * slot_15(struct StateT * v1813) {
  int v1814 = v1813->timer;
  int v1822 = v1814 + 1;
  v1813->timer = v1822;
  int * v1816 = v1813->regs;
  int v1817 = v1816[15];
  int v1818 = v1816[13];
  int v1827 = (((((int)((unsigned int)v1817 >> 16)) * ((int)((unsigned int)v1818 >> 16))) + ((int)((unsigned int)((v1817 & 65535) * ((int)((unsigned int)v1818 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1817 >> 16)) * (v1818 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1817 & 65535) * (v1818 & 65535)) >> 16)) + (((v1817 & 65535) * ((int)((unsigned int)v1818 >> 16))) & 65535)) + ((((int)((unsigned int)v1817 >> 16)) * (v1818 & 65535)) & 65535)) >> 16));
  v1816[30] = v1827;
  struct StateT * v1820 = slot_16(v1813);
  return v1820;
}

struct StateT * slot_222(struct StateT * v12362) {
  int v12363 = v12362->timer;
  int v12371 = v12363 + 1;
  v12362->timer = v12371;
  int * v12365 = v12362->regs;
  int v12366 = v12365[6];
  int v12367 = v12365[13];
  int v12376 = (((((int)((unsigned int)v12366 >> 16)) * ((int)((unsigned int)v12367 >> 16))) + ((int)((unsigned int)((v12366 & 65535) * ((int)((unsigned int)v12367 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v12366 >> 16)) * (v12367 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v12366 & 65535) * (v12367 & 65535)) >> 16)) + (((v12366 & 65535) * ((int)((unsigned int)v12367 >> 16))) & 65535)) + ((((int)((unsigned int)v12366 >> 16)) * (v12367 & 65535)) & 65535)) >> 16));
  v12365[8] = v12376;
  struct StateT * v12369 = slot_241(v12362);
  return v12369;
}

struct StateT * slot_171(struct StateT * v9140) {
  int v9141 = v9140->timer;
  int v9311 = v9141 + 1;
  v9140->timer = v9311;
  int * v9143 = v9140->regs;
  int v9144 = v9143[10];
  int v9145 = v9143[29];
  int * v9146 = v9140->cache_tags;
  int v9316 = (((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2;
  int v9147 = v9146[v9316];
  int v9317 = ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9148 = v9146[v9317];
  int v9318 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2);
  int v9149 = v9146[v9318];
  int v9319 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9150 = v9146[v9319];
  int v9151 = v9140->timer;
  int v9320 = v9151 + ((100 ^ (((~(((v9149 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9149 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9147 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9147 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9148 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9148 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9149 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9149 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9140->timer = v9320;
  bool v9321 = !(((~(((v9147 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9147 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9148 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9148 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v9245;
  if (v9321) {
    int * v9153 = v9140->cache_age;
    int v9323 = ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v9148 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9148 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v9154 = v9153[v9323];
    int v9155 = v9153[v9316];
    int v9324 = v9155 + ((int)((unsigned int)(v9155 - v9154) >> 31));
    v9153[v9316] = v9324;
    int * v9157 = v9140->cache_age;
    int v9158 = v9157[v9317];
    int v9326 = v9158 + ((int)((unsigned int)(v9158 - v9154) >> 31));
    v9157[v9317] = v9326;
    int * v9160 = v9140->cache_age;
    v9160[v9323] = 0;
    v9245 = v9323;
  } else {
    int * v9163 = v9140->cache_age;
    int v9330 = (((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2;
    int v9164 = v9163[v9330];
    int * v9165 = v9140->cache_tags;
    int v9166 = v9165[v9330];
    int v9167 = v9163[v9317];
    int v9168 = v9165[v9317];
    bool v9332 = !(((~(((v9149 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9149 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v9222;
    if (v9332) {
      int * v9169 = v9140->cache_age;
      int v9334 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9150 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v9170 = v9169[v9334];
      int v9171 = v9169[v9318];
      int v9335 = v9171 + ((int)((unsigned int)(v9171 - v9170) >> 31));
      v9169[v9318] = v9335;
      int * v9173 = v9140->cache_age;
      int v9174 = v9173[v9319];
      int v9337 = v9174 + ((int)((unsigned int)(v9174 - v9170) >> 31));
      v9173[v9319] = v9337;
      int * v9176 = v9140->cache_age;
      v9176[v9334] = 0;
      v9222 = v9334;
    } else {
      int * v9179 = v9140->cache_age;
      int v9341 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2);
      int v9180 = v9179[v9341];
      int * v9181 = v9140->cache_tags;
      int v9182 = v9181[v9341];
      int v9183 = v9179[v9319];
      int v9184 = v9181[v9319];
      int * v9185 = v9140->cache_dirty;
      int v9344 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9180 + ((~(((v9182 ^ -1) | (-(v9182 ^ -1))) >> 31)) & 2)) - (v9183 + ((~(((v9184 ^ -1) | (-(v9184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9186 = v9185[v9344];
      bool v9345 = !(v9186 == 0);
      if (v9345) {
        int * v9187 = v9140->cache_tags;
        int v9188 = v9187[v9344];
        int * v9189 = v9140->cache_vals;
        int v9348 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9180 + ((~(((v9182 ^ -1) | (-(v9182 ^ -1))) >> 31)) & 2)) - (v9183 + ((~(((v9184 ^ -1) | (-(v9184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9190 = v9189[v9348];
        int v9349 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9180 + ((~(((v9182 ^ -1) | (-(v9182 ^ -1))) >> 31)) & 2)) - (v9183 + ((~(((v9184 ^ -1) | (-(v9184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9191 = v9189[v9349];
        int * v9192 = v9140->mem;
        int v9351 = v9188 * 2;
        v9192[v9351] = v9190;
        int * v9194 = v9140->mem;
        int v9354 = (v9188 * 2) + 1;
        v9194[v9354] = v9191;
        ;
      } else {
        ;
      }
      int * v9199 = v9140->mem;
      int v9359 = ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) * 2;
      int v9200 = v9199[v9359];
      int v9360 = (((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) * 2) + 1;
      int v9201 = v9199[v9360];
      int * v9202 = v9140->cache_vals;
      int v9362 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9180 + ((~(((v9182 ^ -1) | (-(v9182 ^ -1))) >> 31)) & 2)) - (v9183 + ((~(((v9184 ^ -1) | (-(v9184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9202[v9362] = v9200;
      int * v9204 = v9140->cache_vals;
      int v9365 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9180 + ((~(((v9182 ^ -1) | (-(v9182 ^ -1))) >> 31)) & 2)) - (v9183 + ((~(((v9184 ^ -1) | (-(v9184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9204[v9365] = v9201;
      int * v9206 = v9140->cache_tags;
      int v9368 = (int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1);
      v9206[v9344] = v9368;
      int * v9208 = v9140->cache_dirty;
      v9208[v9344] = 0;
      int * v9210 = v9140->cache_age;
      v9210[v9344] = 1;
      int * v9212 = v9140->cache_age;
      int v9213 = v9212[v9344];
      int v9214 = v9212[v9318];
      int v9374 = v9214 + ((int)((unsigned int)(v9214 - v9213) >> 31));
      v9212[v9318] = v9374;
      int * v9216 = v9140->cache_age;
      int v9217 = v9216[v9319];
      int v9376 = v9217 + ((int)((unsigned int)(v9217 - v9213) >> 31));
      v9216[v9319] = v9376;
      int * v9219 = v9140->cache_age;
      v9219[v9344] = 0;
      v9222 = v9344;
    }
    int * v9223 = v9140->cache_vals;
    int v9379 = v9222 * 2;
    int v9224 = v9223[v9379];
    int v9380 = (v9222 * 2) + 1;
    int v9225 = v9223[v9380];
    int v9381 = (((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9164 + ((~(((v9166 ^ -1) | (-(v9166 ^ -1))) >> 31)) & 2)) - (v9167 + ((~(((v9168 ^ -1) | (-(v9168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9223[v9381] = v9224;
    int * v9227 = v9140->cache_vals;
    int v9384 = ((((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9164 + ((~(((v9166 ^ -1) | (-(v9166 ^ -1))) >> 31)) & 2)) - (v9167 + ((~(((v9168 ^ -1) | (-(v9168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9227[v9384] = v9225;
    int * v9229 = v9140->cache_tags;
    int v9387 = ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9164 + ((~(((v9166 ^ -1) | (-(v9166 ^ -1))) >> 31)) & 2)) - (v9167 + ((~(((v9168 ^ -1) | (-(v9168 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9388 = (int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1);
    v9229[v9387] = v9388;
    int * v9231 = v9140->cache_dirty;
    v9231[v9387] = 0;
    int * v9233 = v9140->cache_age;
    v9233[v9387] = 1;
    int * v9235 = v9140->cache_age;
    int v9236 = v9235[v9387];
    int v9237 = v9235[v9316];
    int v9394 = v9237 + ((int)((unsigned int)(v9237 - v9236) >> 31));
    v9235[v9316] = v9394;
    int * v9239 = v9140->cache_age;
    int v9240 = v9239[v9317];
    int v9396 = v9240 + ((int)((unsigned int)(v9240 - v9236) >> 31));
    v9239[v9317] = v9396;
    int * v9242 = v9140->cache_age;
    v9242[v9387] = 0;
    v9245 = v9387;
  }
  int * v9246 = v9140->cache_vals;
  int v9399 = (v9245 * 2) + (((int)((unsigned int)(v9144 + 20) >> 2)) & 1);
  v9246[v9399] = v9145;
  int * v9248 = v9140->cache_tags;
  int v9249 = v9248[v9318];
  int v9250 = v9248[v9319];
  bool v9402 = !(((~(((v9249 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9249 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9250 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9250 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v9304;
  if (v9402) {
    int * v9251 = v9140->cache_age;
    int v9404 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9250 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))) | (-(v9250 ^ ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v9252 = v9251[v9404];
    int v9253 = v9251[v9318];
    int v9405 = v9253 + ((int)((unsigned int)(v9253 - v9252) >> 31));
    v9251[v9318] = v9405;
    int * v9255 = v9140->cache_age;
    int v9256 = v9255[v9319];
    int v9407 = v9256 + ((int)((unsigned int)(v9256 - v9252) >> 31));
    v9255[v9319] = v9407;
    int * v9258 = v9140->cache_age;
    v9258[v9404] = 0;
    v9304 = v9404;
  } else {
    int * v9261 = v9140->cache_age;
    int v9411 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2);
    int v9262 = v9261[v9411];
    int * v9263 = v9140->cache_tags;
    int v9264 = v9263[v9411];
    int v9265 = v9261[v9319];
    int v9266 = v9263[v9319];
    int * v9267 = v9140->cache_dirty;
    int v9414 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9262 + ((~(((v9264 ^ -1) | (-(v9264 ^ -1))) >> 31)) & 2)) - (v9265 + ((~(((v9266 ^ -1) | (-(v9266 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9268 = v9267[v9414];
    bool v9415 = !(v9268 == 0);
    if (v9415) {
      int * v9269 = v9140->cache_tags;
      int v9270 = v9269[v9414];
      int * v9271 = v9140->cache_vals;
      int v9418 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9262 + ((~(((v9264 ^ -1) | (-(v9264 ^ -1))) >> 31)) & 2)) - (v9265 + ((~(((v9266 ^ -1) | (-(v9266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9272 = v9271[v9418];
      int v9419 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9262 + ((~(((v9264 ^ -1) | (-(v9264 ^ -1))) >> 31)) & 2)) - (v9265 + ((~(((v9266 ^ -1) | (-(v9266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9273 = v9271[v9419];
      int * v9274 = v9140->mem;
      int v9421 = v9270 * 2;
      v9274[v9421] = v9272;
      int * v9276 = v9140->mem;
      int v9424 = (v9270 * 2) + 1;
      v9276[v9424] = v9273;
      ;
    } else {
      ;
    }
    int * v9281 = v9140->mem;
    int v9429 = ((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) * 2;
    int v9282 = v9281[v9429];
    int v9430 = (((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) * 2) + 1;
    int v9283 = v9281[v9430];
    int * v9284 = v9140->cache_vals;
    int v9432 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9262 + ((~(((v9264 ^ -1) | (-(v9264 ^ -1))) >> 31)) & 2)) - (v9265 + ((~(((v9266 ^ -1) | (-(v9266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9284[v9432] = v9282;
    int * v9286 = v9140->cache_vals;
    int v9435 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9262 + ((~(((v9264 ^ -1) | (-(v9264 ^ -1))) >> 31)) & 2)) - (v9265 + ((~(((v9266 ^ -1) | (-(v9266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9286[v9435] = v9283;
    int * v9288 = v9140->cache_tags;
    int v9438 = (int)((unsigned int)((int)((unsigned int)(v9144 + 20) >> 2)) >> 1);
    v9288[v9414] = v9438;
    int * v9290 = v9140->cache_dirty;
    v9290[v9414] = 0;
    int * v9292 = v9140->cache_age;
    v9292[v9414] = 1;
    int * v9294 = v9140->cache_age;
    int v9295 = v9294[v9414];
    int v9296 = v9294[v9318];
    int v9444 = v9296 + ((int)((unsigned int)(v9296 - v9295) >> 31));
    v9294[v9318] = v9444;
    int * v9298 = v9140->cache_age;
    int v9299 = v9298[v9319];
    int v9446 = v9299 + ((int)((unsigned int)(v9299 - v9295) >> 31));
    v9298[v9319] = v9446;
    int * v9301 = v9140->cache_age;
    v9301[v9414] = 0;
    v9304 = v9414;
  }
  int * v9305 = v9140->cache_vals;
  int v9449 = (v9304 * 2) + (((int)((unsigned int)(v9144 + 20) >> 2)) & 1);
  v9305[v9449] = v9145;
  int * v9307 = v9140->cache_dirty;
  v9307[v9304] = 1;
  struct StateT * v9309 = slot_189(v9140);
  return v9309;
}

struct StateT * slot_634(struct StateT * v27740) {
  int v27741 = v27740->timer;
  int v27745 = v27741 + 1;
  v27740->timer = v27745;
  struct StateT * v27743 = slot_615(v27740);
  return v27743;
}

struct StateT * slot_267(struct StateT * v13195) {
  int v13196 = v13195->timer;
  int v13204 = v13196 + 1;
  v13195->timer = v13204;
  int * v13198 = v13195->regs;
  int v13199 = v13198[29];
  int v13200 = v13198[5];
  int v13209 = v13199 + v13200;
  v13198[30] = v13209;
  struct StateT * v13202 = slot_256(v13195);
  return v13202;
}

struct StateT * slot_316(struct StateT * v14178) {
  int v14179 = v14178->timer;
  int v14187 = v14179 + 1;
  v14178->timer = v14187;
  int * v14181 = v14178->regs;
  int v14182 = v14181[5];
  int v14183 = v14181[28];
  int v14191 = v14182 + v14183;
  v14181[28] = v14191;
  struct StateT * v14185 = slot_341(v14178);
  return v14185;
}

struct StateT * slot_39(struct StateT * v3205) {
  int v3206 = v3205->timer;
  int v3214 = v3206 + 1;
  v3205->timer = v3214;
  int * v3208 = v3205->regs;
  int v3209 = v3208[28];
  int v3210 = v3208[12];
  int v3219 = v3209 * v3210;
  v3208[30] = v3219;
  struct StateT * v3212 = slot_40(v3205);
  return v3212;
}

struct StateT * slot_60(struct StateT * v3582) {
  int v3583 = v3582->timer;
  int v3595 = v3583 + 1;
  v3582->timer = v3595;
  int * v3585 = v3582->regs;
  int v3586 = v3585[5];
  int v3587 = v3585[18];
  bool v3599 = (v3586 ^ -2147483648) < (v3587 ^ -2147483648);
  int v3590;
  if (v3599) {
    v3590 = 1;
  } else {
    v3590 = 0;
  }
  int * v3591 = v3582->regs;
  v3591[30] = v3590;
  struct StateT * v3593 = slot_61(v3582);
  return v3593;
}

struct StateT * slot_112(struct StateT * v6456) {
  int v6457 = v6456->timer;
  int v6469 = v6457 + 1;
  v6456->timer = v6469;
  int * v6459 = v6456->regs;
  int v6460 = v6459[29];
  int v6461 = v6459[28];
  bool v6473 = (v6460 ^ -2147483648) < (v6461 ^ -2147483648);
  int v6464;
  if (v6473) {
    v6464 = 1;
  } else {
    v6464 = 0;
  }
  int * v6465 = v6456->regs;
  v6465[7] = v6464;
  struct StateT * v6467 = slot_114(v6456);
  return v6467;
}

struct StateT * slot_256(struct StateT * v12989) {
  int v12990 = v12989->timer;
  int v12998 = v12990 + 1;
  v12989->timer = v12998;
  int * v12992 = v12989->regs;
  int v12993 = v12992[8];
  int v12994 = v12992[6];
  int v13002 = v12993 + v12994;
  v12992[6] = v13002;
  struct StateT * v12996 = slot_260(v12989);
  return v12996;
}

struct StateT * slot_1042(struct StateT * v54993) {
  int v54994 = v54993->timer;
  int v55002 = v54994 + 1;
  v54993->timer = v55002;
  int * v54996 = v54993->regs;
  int v54997 = v54996[12];
  int v54998 = v54996[14];
  int v55006 = v54997 + v54998;
  v54996[12] = v55006;
  struct StateT * v55000 = slot_1022(v54993);
  return v55000;
}

struct StateT * slot_16(struct StateT * v1830) {
  int v1831 = v1830->timer;
  int v1839 = v1831 + 1;
  v1830->timer = v1839;
  int * v1833 = v1830->regs;
  int v1834 = v1833[14];
  int v1835 = v1833[12];
  int v1843 = v1834 * v1835;
  v1833[14] = v1843;
  struct StateT * v1837 = slot_17(v1830);
  return v1837;
}

struct StateT * slot_113(struct StateT * v6481) {
  int v6482 = v6481->timer;
  int v6490 = v6482 + 1;
  v6481->timer = v6490;
  int * v6484 = v6481->regs;
  int v6485 = v6484[6];
  int v6486 = v6484[12];
  int v6494 = v6485 * v6486;
  v6484[6] = v6494;
  struct StateT * v6488 = slot_115(v6481);
  return v6488;
}

struct StateT * slot_191(struct StateT * v11294) {
  int v11295 = v11294->timer;
  int v11405 = v11295 + 1;
  v11294->timer = v11405;
  int * v11297 = v11294->regs;
  int v11298 = v11297[11];
  int * v11299 = v11294->cache_tags;
  int v11409 = (((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2;
  int v11300 = v11299[v11409];
  int v11410 = ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11301 = v11299[v11410];
  int v11411 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2);
  int v11302 = v11299[v11411];
  int v11412 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11303 = v11299[v11412];
  int v11304 = v11294->timer;
  int v11413 = v11304 + ((100 ^ (((~(((v11302 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11302 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11300 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11300 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11301 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11301 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11302 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11302 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11294->timer = v11413;
  int * v11306 = v11294->cache_vals;
  bool v11414 = !(((~(((v11300 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11300 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11301 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11301 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v11399;
  if (v11414) {
    int * v11307 = v11294->cache_age;
    int v11416 = ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v11301 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11301 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v11308 = v11307[v11416];
    int v11309 = v11307[v11409];
    int v11417 = v11309 + ((int)((unsigned int)(v11309 - v11308) >> 31));
    v11307[v11409] = v11417;
    int * v11311 = v11294->cache_age;
    int v11312 = v11311[v11410];
    int v11419 = v11312 + ((int)((unsigned int)(v11312 - v11308) >> 31));
    v11311[v11410] = v11419;
    int * v11314 = v11294->cache_age;
    v11314[v11416] = 0;
    v11399 = v11416;
  } else {
    int * v11317 = v11294->cache_age;
    int v11423 = (((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2;
    int v11318 = v11317[v11423];
    int * v11319 = v11294->cache_tags;
    int v11320 = v11319[v11423];
    int v11321 = v11317[v11410];
    int v11322 = v11319[v11410];
    bool v11425 = !(((~(((v11302 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11302 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v11376;
    if (v11425) {
      int * v11323 = v11294->cache_age;
      int v11427 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))) | (-(v11303 ^ ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v11324 = v11323[v11427];
      int v11325 = v11323[v11411];
      int v11428 = v11325 + ((int)((unsigned int)(v11325 - v11324) >> 31));
      v11323[v11411] = v11428;
      int * v11327 = v11294->cache_age;
      int v11328 = v11327[v11412];
      int v11430 = v11328 + ((int)((unsigned int)(v11328 - v11324) >> 31));
      v11327[v11412] = v11430;
      int * v11330 = v11294->cache_age;
      v11330[v11427] = 0;
      v11376 = v11427;
    } else {
      int * v11333 = v11294->cache_age;
      int v11434 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2);
      int v11334 = v11333[v11434];
      int * v11335 = v11294->cache_tags;
      int v11336 = v11335[v11434];
      int v11337 = v11333[v11412];
      int v11338 = v11335[v11412];
      int * v11339 = v11294->cache_dirty;
      int v11437 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11334 + ((~(((v11336 ^ -1) | (-(v11336 ^ -1))) >> 31)) & 2)) - (v11337 + ((~(((v11338 ^ -1) | (-(v11338 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11340 = v11339[v11437];
      bool v11438 = !(v11340 == 0);
      if (v11438) {
        int * v11341 = v11294->cache_tags;
        int v11342 = v11341[v11437];
        int * v11343 = v11294->cache_vals;
        int v11441 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11334 + ((~(((v11336 ^ -1) | (-(v11336 ^ -1))) >> 31)) & 2)) - (v11337 + ((~(((v11338 ^ -1) | (-(v11338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11344 = v11343[v11441];
        int v11442 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11334 + ((~(((v11336 ^ -1) | (-(v11336 ^ -1))) >> 31)) & 2)) - (v11337 + ((~(((v11338 ^ -1) | (-(v11338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11345 = v11343[v11442];
        int * v11346 = v11294->mem;
        int v11444 = v11342 * 2;
        v11346[v11444] = v11344;
        int * v11348 = v11294->mem;
        int v11447 = (v11342 * 2) + 1;
        v11348[v11447] = v11345;
        ;
      } else {
        ;
      }
      int * v11353 = v11294->mem;
      int v11452 = ((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) * 2;
      int v11354 = v11353[v11452];
      int v11453 = (((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) * 2) + 1;
      int v11355 = v11353[v11453];
      int * v11356 = v11294->cache_vals;
      int v11455 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11334 + ((~(((v11336 ^ -1) | (-(v11336 ^ -1))) >> 31)) & 2)) - (v11337 + ((~(((v11338 ^ -1) | (-(v11338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11356[v11455] = v11354;
      int * v11358 = v11294->cache_vals;
      int v11458 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11334 + ((~(((v11336 ^ -1) | (-(v11336 ^ -1))) >> 31)) & 2)) - (v11337 + ((~(((v11338 ^ -1) | (-(v11338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11358[v11458] = v11355;
      int * v11360 = v11294->cache_tags;
      int v11461 = (int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1);
      v11360[v11437] = v11461;
      int * v11362 = v11294->cache_dirty;
      v11362[v11437] = 0;
      int * v11364 = v11294->cache_age;
      v11364[v11437] = 1;
      int * v11366 = v11294->cache_age;
      int v11367 = v11366[v11437];
      int v11368 = v11366[v11411];
      int v11467 = v11368 + ((int)((unsigned int)(v11368 - v11367) >> 31));
      v11366[v11411] = v11467;
      int * v11370 = v11294->cache_age;
      int v11371 = v11370[v11412];
      int v11469 = v11371 + ((int)((unsigned int)(v11371 - v11367) >> 31));
      v11370[v11412] = v11469;
      int * v11373 = v11294->cache_age;
      v11373[v11437] = 0;
      v11376 = v11437;
    }
    int * v11377 = v11294->cache_vals;
    int v11472 = v11376 * 2;
    int v11378 = v11377[v11472];
    int v11473 = (v11376 * 2) + 1;
    int v11379 = v11377[v11473];
    int v11474 = (((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11318 + ((~(((v11320 ^ -1) | (-(v11320 ^ -1))) >> 31)) & 2)) - (v11321 + ((~(((v11322 ^ -1) | (-(v11322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11377[v11474] = v11378;
    int * v11381 = v11294->cache_vals;
    int v11477 = ((((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11318 + ((~(((v11320 ^ -1) | (-(v11320 ^ -1))) >> 31)) & 2)) - (v11321 + ((~(((v11322 ^ -1) | (-(v11322 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11381[v11477] = v11379;
    int * v11383 = v11294->cache_tags;
    int v11480 = ((((int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11318 + ((~(((v11320 ^ -1) | (-(v11320 ^ -1))) >> 31)) & 2)) - (v11321 + ((~(((v11322 ^ -1) | (-(v11322 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11481 = (int)((unsigned int)((int)((unsigned int)(v11298 + 28) >> 2)) >> 1);
    v11383[v11480] = v11481;
    int * v11385 = v11294->cache_dirty;
    v11385[v11480] = 0;
    int * v11387 = v11294->cache_age;
    v11387[v11480] = 1;
    int * v11389 = v11294->cache_age;
    int v11390 = v11389[v11480];
    int v11391 = v11389[v11409];
    int v11487 = v11391 + ((int)((unsigned int)(v11391 - v11390) >> 31));
    v11389[v11409] = v11487;
    int * v11393 = v11294->cache_age;
    int v11394 = v11393[v11410];
    int v11489 = v11394 + ((int)((unsigned int)(v11394 - v11390) >> 31));
    v11393[v11410] = v11489;
    int * v11396 = v11294->cache_age;
    v11396[v11480] = 0;
    v11399 = v11480;
  }
  int v11492 = (v11399 * 2) + (((int)((unsigned int)(v11298 + 28) >> 2)) & 1);
  int v11400 = v11306[v11492];
  int * v11401 = v11294->regs;
  v11401[29] = v11400;
  struct StateT * v11403 = slot_209(v11294);
  return v11403;
}

struct StateT * slot_95(struct StateT * v6172) {
  int v6173 = v6172->timer;
  int v6180 = v6173 + 1;
  v6172->timer = v6180;
  int * v6175 = v6172->regs;
  int v6176 = v6175[5];
  int v6183 = v6176 << 13;
  v6175[5] = v6183;
  struct StateT * v6178 = slot_90(v6172);
  return v6178;
}

struct StateT * slot_905(struct StateT * v45474) {
  int v45475 = v45474->timer;
  int v45482 = v45475 + 1;
  v45474->timer = v45482;
  int * v45477 = v45474->regs;
  int v45478 = v45477[5];
  int v45486 = v45478 << 13;
  v45477[13] = v45486;
  struct StateT * v45480 = slot_920(v45474);
  return v45480;
}

struct StateT * slot_354(struct StateT * v17700) {
  int * v17701 = v17700->saved_regs;
  int v17702 = v17701[7];
  int v17703 = v17701[29];
  bool v17731 = v17702 == v17703;
  struct StateT * v17726;
  if (v17731) {
    int v17704 = v17700->timer;
    int v17732 = v17704 + 15;
    v17700->timer = v17732;
    int * v17706 = v17700->saved_regs;
    int v17707 = v17706[28];
    int * v17708 = v17700->regs;
    v17708[28] = v17707;
    int * v17710 = v17700->saved_regs;
    int v17711 = v17710[29];
    int * v17712 = v17700->regs;
    v17712[29] = v17711;
    int * v17714 = v17700->saved_regs;
    int v17715 = v17714[7];
    int * v17716 = v17700->regs;
    v17716[7] = v17715;
    int * v17718 = v17700->saved_regs;
    int v17719 = v17718[5];
    int * v17720 = v17700->regs;
    v17720[5] = v17719;
    struct StateT * v17722 = slot_316(v17700);
    v17726 = v17722;
  } else {
    struct StateT * v17724 = slot_365(v17700);
    v17726 = v17724;
  }
  return v17726;
}

struct StateT * slot_115(struct StateT * v6513) {
  int v6514 = v6513->timer;
  int v6522 = v6514 + 1;
  v6513->timer = v6522;
  int * v6516 = v6513->regs;
  int v6517 = v6516[28];
  int v6518 = v6516[17];
  int v6527 = v6517 + v6518;
  v6516[29] = v6527;
  struct StateT * v6520 = slot_110(v6513);
  return v6520;
}

struct StateT * slot_210(struct StateT * v12163) {
  int v12164 = v12163->timer;
  int v12172 = v12164 + 1;
  v12163->timer = v12172;
  int * v12166 = v12163->regs;
  int v12167 = v12166[29];
  int v12168 = v12166[12];
  int v12177 = v12167 * v12168;
  v12166[28] = v12177;
  struct StateT * v12170 = slot_214(v12163);
  return v12170;
}

struct StateT * slot_52(struct StateT * v3426) {
  int v3427 = v3426->timer;
  int v3439 = v3427 + 1;
  v3426->timer = v3439;
  int * v3429 = v3426->regs;
  int v3430 = v3429[17];
  int v3431 = v3429[7];
  bool v3443 = (v3430 ^ -2147483648) < (v3431 ^ -2147483648);
  int v3434;
  if (v3443) {
    v3434 = 1;
  } else {
    v3434 = 0;
  }
  int * v3435 = v3426->regs;
  v3435[28] = v3434;
  struct StateT * v3437 = slot_53(v3426);
  return v3437;
}

struct StateT * slot_83(struct StateT * v5419) {
  int v5420 = v5419->timer;
  int v5427 = v5420 + 1;
  v5419->timer = v5427;
  int * v5422 = v5419->regs;
  int v5423 = v5422[28];
  int v5431 = (int)((unsigned int)v5423 >> 19);
  v5422[17] = v5431;
  struct StateT * v5425 = slot_85(v5419);
  return v5425;
}

struct StateT * slot_209(struct StateT * v12147) {
  int v12148 = v12147->timer;
  int v12156 = v12148 + 1;
  v12147->timer = v12156;
  int * v12150 = v12147->regs;
  int v12151 = v12150[7];
  int v12152 = v12150[28];
  int v12160 = v12151 | v12152;
  v12150[7] = v12160;
  struct StateT * v12154 = slot_184(v12147);
  return v12154;
}

struct StateT * slot_73(struct StateT * v4170) {
  int v4171 = v4170->timer;
  int v4179 = v4171 + 1;
  v4170->timer = v4179;
  int * v4173 = v4170->regs;
  int v4174 = v4173[7];
  int v4175 = v4173[16];
  int v4184 = v4174 & v4175;
  v4173[29] = v4184;
  struct StateT * v4177 = slot_75(v4170);
  return v4177;
}

struct StateT * slot_187(struct StateT * v10855) {
  int v10856 = v10855->timer;
  int v10966 = v10856 + 1;
  v10855->timer = v10966;
  int * v10858 = v10855->regs;
  int v10859 = v10858[11];
  int * v10860 = v10855->cache_tags;
  int v10970 = (((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2;
  int v10861 = v10860[v10970];
  int v10971 = ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10862 = v10860[v10971];
  int v10972 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2);
  int v10863 = v10860[v10972];
  int v10973 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10864 = v10860[v10973];
  int v10865 = v10855->timer;
  int v10974 = v10865 + ((100 ^ (((~(((v10863 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10863 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10861 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10861 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10862 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10862 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10863 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10863 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10855->timer = v10974;
  int * v10867 = v10855->cache_vals;
  bool v10975 = !(((~(((v10861 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10861 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10862 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10862 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v10960;
  if (v10975) {
    int * v10868 = v10855->cache_age;
    int v10977 = ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v10862 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10862 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v10869 = v10868[v10977];
    int v10870 = v10868[v10970];
    int v10978 = v10870 + ((int)((unsigned int)(v10870 - v10869) >> 31));
    v10868[v10970] = v10978;
    int * v10872 = v10855->cache_age;
    int v10873 = v10872[v10971];
    int v10980 = v10873 + ((int)((unsigned int)(v10873 - v10869) >> 31));
    v10872[v10971] = v10980;
    int * v10875 = v10855->cache_age;
    v10875[v10977] = 0;
    v10960 = v10977;
  } else {
    int * v10878 = v10855->cache_age;
    int v10984 = (((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2;
    int v10879 = v10878[v10984];
    int * v10880 = v10855->cache_tags;
    int v10881 = v10880[v10984];
    int v10882 = v10878[v10971];
    int v10883 = v10880[v10971];
    bool v10986 = !(((~(((v10863 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10863 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v10937;
    if (v10986) {
      int * v10884 = v10855->cache_age;
      int v10988 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))) | (-(v10864 ^ ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v10885 = v10884[v10988];
      int v10886 = v10884[v10972];
      int v10989 = v10886 + ((int)((unsigned int)(v10886 - v10885) >> 31));
      v10884[v10972] = v10989;
      int * v10888 = v10855->cache_age;
      int v10889 = v10888[v10973];
      int v10991 = v10889 + ((int)((unsigned int)(v10889 - v10885) >> 31));
      v10888[v10973] = v10991;
      int * v10891 = v10855->cache_age;
      v10891[v10988] = 0;
      v10937 = v10988;
    } else {
      int * v10894 = v10855->cache_age;
      int v10995 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2);
      int v10895 = v10894[v10995];
      int * v10896 = v10855->cache_tags;
      int v10897 = v10896[v10995];
      int v10898 = v10894[v10973];
      int v10899 = v10896[v10973];
      int * v10900 = v10855->cache_dirty;
      int v10998 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10895 + ((~(((v10897 ^ -1) | (-(v10897 ^ -1))) >> 31)) & 2)) - (v10898 + ((~(((v10899 ^ -1) | (-(v10899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10901 = v10900[v10998];
      bool v10999 = !(v10901 == 0);
      if (v10999) {
        int * v10902 = v10855->cache_tags;
        int v10903 = v10902[v10998];
        int * v10904 = v10855->cache_vals;
        int v11002 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10895 + ((~(((v10897 ^ -1) | (-(v10897 ^ -1))) >> 31)) & 2)) - (v10898 + ((~(((v10899 ^ -1) | (-(v10899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10905 = v10904[v11002];
        int v11003 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10895 + ((~(((v10897 ^ -1) | (-(v10897 ^ -1))) >> 31)) & 2)) - (v10898 + ((~(((v10899 ^ -1) | (-(v10899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10906 = v10904[v11003];
        int * v10907 = v10855->mem;
        int v11005 = v10903 * 2;
        v10907[v11005] = v10905;
        int * v10909 = v10855->mem;
        int v11008 = (v10903 * 2) + 1;
        v10909[v11008] = v10906;
        ;
      } else {
        ;
      }
      int * v10914 = v10855->mem;
      int v11013 = ((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) * 2;
      int v10915 = v10914[v11013];
      int v11014 = (((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) * 2) + 1;
      int v10916 = v10914[v11014];
      int * v10917 = v10855->cache_vals;
      int v11016 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10895 + ((~(((v10897 ^ -1) | (-(v10897 ^ -1))) >> 31)) & 2)) - (v10898 + ((~(((v10899 ^ -1) | (-(v10899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10917[v11016] = v10915;
      int * v10919 = v10855->cache_vals;
      int v11019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10895 + ((~(((v10897 ^ -1) | (-(v10897 ^ -1))) >> 31)) & 2)) - (v10898 + ((~(((v10899 ^ -1) | (-(v10899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10919[v11019] = v10916;
      int * v10921 = v10855->cache_tags;
      int v11022 = (int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1);
      v10921[v10998] = v11022;
      int * v10923 = v10855->cache_dirty;
      v10923[v10998] = 0;
      int * v10925 = v10855->cache_age;
      v10925[v10998] = 1;
      int * v10927 = v10855->cache_age;
      int v10928 = v10927[v10998];
      int v10929 = v10927[v10972];
      int v11028 = v10929 + ((int)((unsigned int)(v10929 - v10928) >> 31));
      v10927[v10972] = v11028;
      int * v10931 = v10855->cache_age;
      int v10932 = v10931[v10973];
      int v11030 = v10932 + ((int)((unsigned int)(v10932 - v10928) >> 31));
      v10931[v10973] = v11030;
      int * v10934 = v10855->cache_age;
      v10934[v10998] = 0;
      v10937 = v10998;
    }
    int * v10938 = v10855->cache_vals;
    int v11033 = v10937 * 2;
    int v10939 = v10938[v11033];
    int v11034 = (v10937 * 2) + 1;
    int v10940 = v10938[v11034];
    int v11035 = (((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10879 + ((~(((v10881 ^ -1) | (-(v10881 ^ -1))) >> 31)) & 2)) - (v10882 + ((~(((v10883 ^ -1) | (-(v10883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10938[v11035] = v10939;
    int * v10942 = v10855->cache_vals;
    int v11038 = ((((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10879 + ((~(((v10881 ^ -1) | (-(v10881 ^ -1))) >> 31)) & 2)) - (v10882 + ((~(((v10883 ^ -1) | (-(v10883 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10942[v11038] = v10940;
    int * v10944 = v10855->cache_tags;
    int v11041 = ((((int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10879 + ((~(((v10881 ^ -1) | (-(v10881 ^ -1))) >> 31)) & 2)) - (v10882 + ((~(((v10883 ^ -1) | (-(v10883 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11042 = (int)((unsigned int)((int)((unsigned int)(v10859 + 24) >> 2)) >> 1);
    v10944[v11041] = v11042;
    int * v10946 = v10855->cache_dirty;
    v10946[v11041] = 0;
    int * v10948 = v10855->cache_age;
    v10948[v11041] = 1;
    int * v10950 = v10855->cache_age;
    int v10951 = v10950[v11041];
    int v10952 = v10950[v10970];
    int v11048 = v10952 + ((int)((unsigned int)(v10952 - v10951) >> 31));
    v10950[v10970] = v11048;
    int * v10954 = v10855->cache_age;
    int v10955 = v10954[v10971];
    int v11050 = v10955 + ((int)((unsigned int)(v10955 - v10951) >> 31));
    v10954[v10971] = v11050;
    int * v10957 = v10855->cache_age;
    v10957[v11041] = 0;
    v10960 = v11041;
  }
  int v11053 = (v10960 * 2) + (((int)((unsigned int)(v10859 + 24) >> 2)) & 1);
  int v10961 = v10867[v11053];
  int * v10962 = v10855->regs;
  v10962[6] = v10961;
  struct StateT * v10964 = slot_191(v10855);
  return v10964;
}

struct StateT * slot_178(struct StateT * v9931) {
  int v9932 = v9931->timer;
  int v9939 = v9932 + 1;
  v9931->timer = v9939;
  int * v9934 = v9931->regs;
  int v9935 = v9934[28];
  int v9942 = v9935 << 13;
  v9934[28] = v9942;
  struct StateT * v9937 = slot_197(v9931);
  return v9937;
}

struct StateT * slot_46(struct StateT * v3320) {
  int v3321 = v3320->timer;
  int v3329 = v3321 + 1;
  v3320->timer = v3329;
  int * v3323 = v3320->regs;
  int v3324 = v3323[28];
  int v3325 = v3323[13];
  int v3334 = (((((int)((unsigned int)v3324 >> 16)) * ((int)((unsigned int)v3325 >> 16))) + ((int)((unsigned int)((v3324 & 65535) * ((int)((unsigned int)v3325 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3324 >> 16)) * (v3325 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3324 & 65535) * (v3325 & 65535)) >> 16)) + (((v3324 & 65535) * ((int)((unsigned int)v3325 >> 16))) & 65535)) + ((((int)((unsigned int)v3324 >> 16)) * (v3325 & 65535)) & 65535)) >> 16));
  v3323[19] = v3334;
  struct StateT * v3327 = slot_47(v3320);
  return v3327;
}

struct StateT * slot_20(struct StateT * v1903) {
  int v1904 = v1903->timer;
  int v1912 = v1904 + 1;
  v1903->timer = v1912;
  int * v1906 = v1903->regs;
  int v1907 = v1906[6];
  int v1908 = v1906[15];
  int v1916 = v1907 + v1908;
  v1906[6] = v1916;
  struct StateT * v1910 = slot_21(v1903);
  return v1910;
}

struct StateT * slot_61(struct StateT * v3607) {
  int v3608 = v3607->timer;
  int v3616 = v3608 + 1;
  v3607->timer = v3616;
  int * v3610 = v3607->regs;
  int v3611 = v3610[19];
  int v3612 = v3610[6];
  int v3620 = v3611 + v3612;
  v3610[6] = v3620;
  struct StateT * v3614 = slot_62(v3607);
  return v3614;
}

struct StateT * slot_30(struct StateT * v3045) {
  int v3046 = v3045->timer;
  int v3054 = v3046 + 1;
  v3045->timer = v3054;
  int * v3048 = v3045->regs;
  int v3049 = v3048[29];
  int v3050 = v3048[5];
  int v3059 = v3049 + v3050;
  v3048[31] = v3059;
  struct StateT * v3052 = slot_31(v3045);
  return v3052;
}

struct StateT * slot_300(struct StateT * v13816) {
  int * v13817 = v13816->saved_regs;
  int * v13818 = v13816->regs;
  int v13819 = v13818[29];
  v13817[29] = v13819;
  int v13821 = v13816->timer;
  int v13833 = v13821 + 1;
  v13816->timer = v13833;
  int * v13823 = v13816->regs;
  int v13824 = v13823[7];
  int v13825 = v13823[16];
  int v13837 = v13824 & v13825;
  v13823[29] = v13837;
  struct StateT * v13827 = slot_304(v13816);
  return v13827;
}

struct StateT * slot_309(struct StateT * v14013) {
  int v14014 = v14013->timer;
  int v14022 = v14014 + 1;
  v14013->timer = v14022;
  int * v14016 = v14013->regs;
  int v14017 = v14016[30];
  int v14018 = v14016[28];
  int v14027 = v14017 + v14018;
  v14016[7] = v14027;
  struct StateT * v14020 = slot_299(v14013);
  return v14020;
}

struct StateT * slot_6(struct StateT * v1480) {
  int v1481 = v1480->timer;
  int v1591 = v1481 + 1;
  v1480->timer = v1591;
  int * v1483 = v1480->regs;
  int v1484 = v1483[11];
  int * v1485 = v1480->cache_tags;
  int v1595 = (((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1486 = v1485[v1595];
  int v1596 = ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1487 = v1485[v1596];
  int v1597 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1488 = v1485[v1597];
  int v1598 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1489 = v1485[v1598];
  int v1490 = v1480->timer;
  int v1599 = v1490 + ((100 ^ (((~(((v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1480->timer = v1599;
  int * v1492 = v1480->cache_vals;
  bool v1600 = !(((~(((v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1486 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1585;
  if (v1600) {
    int * v1493 = v1480->cache_age;
    int v1602 = ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1487 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1494 = v1493[v1602];
    int v1495 = v1493[v1595];
    int v1603 = v1495 + ((int)((unsigned int)(v1495 - v1494) >> 31));
    v1493[v1595] = v1603;
    int * v1497 = v1480->cache_age;
    int v1498 = v1497[v1596];
    int v1605 = v1498 + ((int)((unsigned int)(v1498 - v1494) >> 31));
    v1497[v1596] = v1605;
    int * v1500 = v1480->cache_age;
    v1500[v1602] = 0;
    v1585 = v1602;
  } else {
    int * v1503 = v1480->cache_age;
    int v1609 = (((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1504 = v1503[v1609];
    int * v1505 = v1480->cache_tags;
    int v1506 = v1505[v1609];
    int v1507 = v1503[v1596];
    int v1508 = v1505[v1596];
    bool v1611 = !(((~(((v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1488 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1562;
    if (v1611) {
      int * v1509 = v1480->cache_age;
      int v1613 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))) | (-(v1489 ^ ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1510 = v1509[v1613];
      int v1511 = v1509[v1597];
      int v1614 = v1511 + ((int)((unsigned int)(v1511 - v1510) >> 31));
      v1509[v1597] = v1614;
      int * v1513 = v1480->cache_age;
      int v1514 = v1513[v1598];
      int v1616 = v1514 + ((int)((unsigned int)(v1514 - v1510) >> 31));
      v1513[v1598] = v1616;
      int * v1516 = v1480->cache_age;
      v1516[v1613] = 0;
      v1562 = v1613;
    } else {
      int * v1519 = v1480->cache_age;
      int v1620 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1520 = v1519[v1620];
      int * v1521 = v1480->cache_tags;
      int v1522 = v1521[v1620];
      int v1523 = v1519[v1598];
      int v1524 = v1521[v1598];
      int * v1525 = v1480->cache_dirty;
      int v1623 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1526 = v1525[v1623];
      bool v1624 = !(v1526 == 0);
      if (v1624) {
        int * v1527 = v1480->cache_tags;
        int v1528 = v1527[v1623];
        int * v1529 = v1480->cache_vals;
        int v1627 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1530 = v1529[v1627];
        int v1628 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1531 = v1529[v1628];
        int * v1532 = v1480->mem;
        int v1630 = v1528 * 2;
        v1532[v1630] = v1530;
        int * v1534 = v1480->mem;
        int v1633 = (v1528 * 2) + 1;
        v1534[v1633] = v1531;
        ;
      } else {
        ;
      }
      int * v1539 = v1480->mem;
      int v1638 = ((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) * 2;
      int v1540 = v1539[v1638];
      int v1639 = (((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1541 = v1539[v1639];
      int * v1542 = v1480->cache_vals;
      int v1641 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1542[v1641] = v1540;
      int * v1544 = v1480->cache_vals;
      int v1644 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1520 + ((~(((v1522 ^ -1) | (-(v1522 ^ -1))) >> 31)) & 2)) - (v1523 + ((~(((v1524 ^ -1) | (-(v1524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1544[v1644] = v1541;
      int * v1546 = v1480->cache_tags;
      int v1647 = (int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1);
      v1546[v1623] = v1647;
      int * v1548 = v1480->cache_dirty;
      v1548[v1623] = 0;
      int * v1550 = v1480->cache_age;
      v1550[v1623] = 1;
      int * v1552 = v1480->cache_age;
      int v1553 = v1552[v1623];
      int v1554 = v1552[v1597];
      int v1653 = v1554 + ((int)((unsigned int)(v1554 - v1553) >> 31));
      v1552[v1597] = v1653;
      int * v1556 = v1480->cache_age;
      int v1557 = v1556[v1598];
      int v1655 = v1557 + ((int)((unsigned int)(v1557 - v1553) >> 31));
      v1556[v1598] = v1655;
      int * v1559 = v1480->cache_age;
      v1559[v1623] = 0;
      v1562 = v1623;
    }
    int * v1563 = v1480->cache_vals;
    int v1658 = v1562 * 2;
    int v1564 = v1563[v1658];
    int v1659 = (v1562 * 2) + 1;
    int v1565 = v1563[v1659];
    int v1660 = (((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1504 + ((~(((v1506 ^ -1) | (-(v1506 ^ -1))) >> 31)) & 2)) - (v1507 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1563[v1660] = v1564;
    int * v1567 = v1480->cache_vals;
    int v1663 = ((((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1504 + ((~(((v1506 ^ -1) | (-(v1506 ^ -1))) >> 31)) & 2)) - (v1507 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1567[v1663] = v1565;
    int * v1569 = v1480->cache_tags;
    int v1666 = ((((int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1504 + ((~(((v1506 ^ -1) | (-(v1506 ^ -1))) >> 31)) & 2)) - (v1507 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1667 = (int)((unsigned int)((int)((unsigned int)(v1484 + 4) >> 2)) >> 1);
    v1569[v1666] = v1667;
    int * v1571 = v1480->cache_dirty;
    v1571[v1666] = 0;
    int * v1573 = v1480->cache_age;
    v1573[v1666] = 1;
    int * v1575 = v1480->cache_age;
    int v1576 = v1575[v1666];
    int v1577 = v1575[v1595];
    int v1673 = v1577 + ((int)((unsigned int)(v1577 - v1576) >> 31));
    v1575[v1595] = v1673;
    int * v1579 = v1480->cache_age;
    int v1580 = v1579[v1596];
    int v1675 = v1580 + ((int)((unsigned int)(v1580 - v1576) >> 31));
    v1579[v1596] = v1675;
    int * v1582 = v1480->cache_age;
    v1582[v1666] = 0;
    v1585 = v1666;
  }
  int v1678 = (v1585 * 2) + (((int)((unsigned int)(v1484 + 4) >> 2)) & 1);
  int v1586 = v1492[v1678];
  int * v1587 = v1480->regs;
  v1587[15] = v1586;
  struct StateT * v1589 = slot_7(v1480);
  return v1589;
}

struct StateT * slot_37(struct StateT * v3172) {
  int v3173 = v3172->timer;
  int v3181 = v3173 + 1;
  v3172->timer = v3181;
  int * v3175 = v3172->regs;
  int v3176 = v3175[17];
  int v3177 = v3175[31];
  int v3185 = v3176 | v3177;
  v3175[17] = v3185;
  struct StateT * v3179 = slot_38(v3172);
  return v3179;
}

struct StateT * slot_114(struct StateT * v6497) {
  int v6498 = v6497->timer;
  int v6506 = v6498 + 1;
  v6497->timer = v6506;
  int * v6500 = v6497->regs;
  int v6501 = v6500[31];
  int v6502 = v6500[29];
  int v6510 = v6501 + v6502;
  v6500[29] = v6510;
  struct StateT * v6504 = slot_123(v6497);
  return v6504;
}

struct StateT * slot_101(struct StateT * v6270) {
  int v6271 = v6270->timer;
  int v6279 = v6271 + 1;
  v6270->timer = v6279;
  int * v6273 = v6270->regs;
  int v6274 = v6273[29];
  int v6275 = v6273[12];
  int v6284 = v6274 * v6275;
  v6273[28] = v6284;
  struct StateT * v6277 = slot_96(v6270);
  return v6277;
}

struct StateT * slot_96(struct StateT * v6186) {
  int v6187 = v6186->timer;
  int v6195 = v6187 + 1;
  v6186->timer = v6195;
  int * v6189 = v6186->regs;
  int v6190 = v6189[29];
  int v6191 = v6189[12];
  int v6200 = (((((int)((unsigned int)v6190 >> 16)) * ((int)((unsigned int)v6191 >> 16))) + ((int)((unsigned int)((v6190 & 65535) * ((int)((unsigned int)v6191 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6190 >> 16)) * (v6191 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6190 & 65535) * (v6191 & 65535)) >> 16)) + (((v6190 & 65535) * ((int)((unsigned int)v6191 >> 16))) & 65535)) + ((((int)((unsigned int)v6190 >> 16)) * (v6191 & 65535)) & 65535)) >> 16));
  v6189[30] = v6200;
  struct StateT * v6193 = slot_105(v6186);
  return v6193;
}

struct StateT * slot_138(struct StateT * v6958) {
  int v6959 = v6958->timer;
  int v6967 = v6959 + 1;
  v6958->timer = v6967;
  int * v6961 = v6958->regs;
  int v6962 = v6961[6];
  int v6963 = v6961[31];
  int v6971 = v6962 + v6963;
  v6961[6] = v6971;
  struct StateT * v6965 = slot_140(v6958);
  return v6965;
}

struct StateT * slot_104(struct StateT * v6321) {
  int v6322 = v6321->timer;
  int v6330 = v6322 + 1;
  v6321->timer = v6330;
  int * v6324 = v6321->regs;
  int v6325 = v6324[29];
  int v6326 = v6324[13];
  int v6335 = (((((int)((unsigned int)v6325 >> 16)) * ((int)((unsigned int)v6326 >> 16))) + ((int)((unsigned int)((v6325 & 65535) * ((int)((unsigned int)v6326 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6325 >> 16)) * (v6326 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6325 & 65535) * (v6326 & 65535)) >> 16)) + (((v6325 & 65535) * ((int)((unsigned int)v6326 >> 16))) & 65535)) + ((((int)((unsigned int)v6325 >> 16)) * (v6326 & 65535)) & 65535)) >> 16));
  v6324[18] = v6335;
  struct StateT * v6328 = slot_113(v6321);
  return v6328;
}

struct StateT * slot_64(struct StateT * v3655) {
  int v3656 = v3655->timer;
  int v3660 = v3656 + 1;
  v3655->timer = v3660;
  struct StateT * v3658 = slot_65(v3655);
  return v3658;
}

struct StateT * slot_53(struct StateT * v3451) {
  int v3452 = v3451->timer;
  int v3460 = v3452 + 1;
  v3451->timer = v3460;
  int * v3454 = v3451->regs;
  int v3455 = v3454[31];
  int v3456 = v3454[30];
  int v3464 = v3455 + v3456;
  v3454[30] = v3464;
  struct StateT * v3458 = slot_54(v3451);
  return v3458;
}

struct StateT * slot_99(struct StateT * v6236) {
  int v6237 = v6236->timer;
  int v6245 = v6237 + 1;
  v6236->timer = v6245;
  int * v6239 = v6236->regs;
  int v6240 = v6239[6];
  int v6241 = v6239[12];
  int v6250 = (((((int)((unsigned int)v6240 >> 16)) * ((int)((unsigned int)v6241 >> 16))) + ((int)((unsigned int)((v6240 & 65535) * ((int)((unsigned int)v6241 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v6240 >> 16)) * (v6241 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v6240 & 65535) * (v6241 & 65535)) >> 16)) + (((v6240 & 65535) * ((int)((unsigned int)v6241 >> 16))) & 65535)) + ((((int)((unsigned int)v6240 >> 16)) * (v6241 & 65535)) & 65535)) >> 16));
  v6239[17] = v6250;
  struct StateT * v6243 = slot_101(v6236);
  return v6243;
}

struct StateT * slot_219(struct StateT * v12312) {
  int v12313 = v12312->timer;
  int v12321 = v12313 + 1;
  v12312->timer = v12321;
  int * v12315 = v12312->regs;
  int v12316 = v12315[6];
  int v12317 = v12315[13];
  int v12326 = v12316 * v12317;
  v12315[31] = v12326;
  struct StateT * v12319 = slot_222(v12312);
  return v12319;
}

struct StateT * slot_22(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1953 = v1945 + 1;
  v1944->timer = v1953;
  int * v1947 = v1944->regs;
  int v1948 = v1947[17];
  int v1949 = v1947[16];
  int v1958 = v1948 & v1949;
  v1947[15] = v1958;
  struct StateT * v1951 = slot_23(v1944);
  return v1951;
}

struct StateT * slot_139(struct StateT * v6974) {
  int v6975 = v6974->timer;
  int v6987 = v6975 + 1;
  v6974->timer = v6987;
  int * v6977 = v6974->regs;
  int v6978 = v6977[5];
  int v6979 = v6977[9];
  bool v6991 = (v6978 ^ -2147483648) < (v6979 ^ -2147483648);
  int v6982;
  if (v6991) {
    v6982 = 1;
  } else {
    v6982 = 0;
  }
  int * v6983 = v6974->regs;
  v6983[31] = v6982;
  struct StateT * v6985 = slot_141(v6974);
  return v6985;
}

struct StateT * slot_129(struct StateT * v6786) {
  int v6787 = v6786->timer;
  int v6795 = v6787 + 1;
  v6786->timer = v6795;
  int * v6789 = v6786->regs;
  int v6790 = v6789[29];
  int v6791 = v6789[5];
  int v6800 = v6790 + v6791;
  v6789[30] = v6800;
  struct StateT * v6793 = slot_124(v6786);
  return v6793;
}

struct StateT * slot_90(struct StateT * v5902) {
  int v5903 = v5902->timer;
  int v5911 = v5903 + 1;
  v5902->timer = v5911;
  int * v5905 = v5902->regs;
  int v5906 = v5905[5];
  int v5907 = v5905[17];
  int v5915 = v5906 | v5907;
  v5905[5] = v5915;
  struct StateT * v5909 = slot_99(v5902);
  return v5909;
}

struct StateT * slot_236(struct StateT * v12606) {
  int v12607 = v12606->timer;
  int v12615 = v12607 + 1;
  v12606->timer = v12615;
  int * v12609 = v12606->regs;
  int v12610 = v12609[31];
  int v12611 = v12609[29];
  int v12619 = v12610 + v12611;
  v12609[29] = v12619;
  struct StateT * v12613 = slot_240(v12606);
  return v12613;
}

struct StateT * slot_262(struct StateT * v13095) {
  int v13096 = v13095->timer;
  int v13108 = v13096 + 1;
  v13095->timer = v13108;
  int * v13098 = v13095->regs;
  int v13099 = v13098[29];
  int v13100 = v13098[31];
  bool v13112 = (v13099 ^ -2147483648) < (v13100 ^ -2147483648);
  int v13103;
  if (v13112) {
    v13103 = 1;
  } else {
    v13103 = 0;
  }
  int * v13104 = v13095->regs;
  v13104[6] = v13103;
  struct StateT * v13106 = slot_267(v13095);
  return v13106;
}

struct StateT * slot_84(struct StateT * v5434) {
  int v5435 = v5434->timer;
  int v5545 = v5435 + 1;
  v5434->timer = v5545;
  int * v5437 = v5434->regs;
  int v5438 = v5437[11];
  int * v5439 = v5434->cache_tags;
  int v5549 = (((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2;
  int v5440 = v5439[v5549];
  int v5550 = ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5441 = v5439[v5550];
  int v5551 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2);
  int v5442 = v5439[v5551];
  int v5552 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5443 = v5439[v5552];
  int v5444 = v5434->timer;
  int v5553 = v5444 + ((100 ^ (((~(((v5442 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5442 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5440 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5440 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5441 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5441 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5442 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5442 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5434->timer = v5553;
  int * v5446 = v5434->cache_vals;
  bool v5554 = !(((~(((v5440 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5440 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5441 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5441 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5539;
  if (v5554) {
    int * v5447 = v5434->cache_age;
    int v5556 = ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v5441 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5441 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5448 = v5447[v5556];
    int v5449 = v5447[v5549];
    int v5557 = v5449 + ((int)((unsigned int)(v5449 - v5448) >> 31));
    v5447[v5549] = v5557;
    int * v5451 = v5434->cache_age;
    int v5452 = v5451[v5550];
    int v5559 = v5452 + ((int)((unsigned int)(v5452 - v5448) >> 31));
    v5451[v5550] = v5559;
    int * v5454 = v5434->cache_age;
    v5454[v5556] = 0;
    v5539 = v5556;
  } else {
    int * v5457 = v5434->cache_age;
    int v5563 = (((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2;
    int v5458 = v5457[v5563];
    int * v5459 = v5434->cache_tags;
    int v5460 = v5459[v5563];
    int v5461 = v5457[v5550];
    int v5462 = v5459[v5550];
    bool v5565 = !(((~(((v5442 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5442 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v5516;
    if (v5565) {
      int * v5463 = v5434->cache_age;
      int v5567 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))) | (-(v5443 ^ ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v5464 = v5463[v5567];
      int v5465 = v5463[v5551];
      int v5568 = v5465 + ((int)((unsigned int)(v5465 - v5464) >> 31));
      v5463[v5551] = v5568;
      int * v5467 = v5434->cache_age;
      int v5468 = v5467[v5552];
      int v5570 = v5468 + ((int)((unsigned int)(v5468 - v5464) >> 31));
      v5467[v5552] = v5570;
      int * v5470 = v5434->cache_age;
      v5470[v5567] = 0;
      v5516 = v5567;
    } else {
      int * v5473 = v5434->cache_age;
      int v5574 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2);
      int v5474 = v5473[v5574];
      int * v5475 = v5434->cache_tags;
      int v5476 = v5475[v5574];
      int v5477 = v5473[v5552];
      int v5478 = v5475[v5552];
      int * v5479 = v5434->cache_dirty;
      int v5577 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5474 + ((~(((v5476 ^ -1) | (-(v5476 ^ -1))) >> 31)) & 2)) - (v5477 + ((~(((v5478 ^ -1) | (-(v5478 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5480 = v5479[v5577];
      bool v5578 = !(v5480 == 0);
      if (v5578) {
        int * v5481 = v5434->cache_tags;
        int v5482 = v5481[v5577];
        int * v5483 = v5434->cache_vals;
        int v5581 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5474 + ((~(((v5476 ^ -1) | (-(v5476 ^ -1))) >> 31)) & 2)) - (v5477 + ((~(((v5478 ^ -1) | (-(v5478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5484 = v5483[v5581];
        int v5582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5474 + ((~(((v5476 ^ -1) | (-(v5476 ^ -1))) >> 31)) & 2)) - (v5477 + ((~(((v5478 ^ -1) | (-(v5478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5485 = v5483[v5582];
        int * v5486 = v5434->mem;
        int v5584 = v5482 * 2;
        v5486[v5584] = v5484;
        int * v5488 = v5434->mem;
        int v5587 = (v5482 * 2) + 1;
        v5488[v5587] = v5485;
        ;
      } else {
        ;
      }
      int * v5493 = v5434->mem;
      int v5592 = ((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) * 2;
      int v5494 = v5493[v5592];
      int v5593 = (((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) * 2) + 1;
      int v5495 = v5493[v5593];
      int * v5496 = v5434->cache_vals;
      int v5595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5474 + ((~(((v5476 ^ -1) | (-(v5476 ^ -1))) >> 31)) & 2)) - (v5477 + ((~(((v5478 ^ -1) | (-(v5478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5496[v5595] = v5494;
      int * v5498 = v5434->cache_vals;
      int v5598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5474 + ((~(((v5476 ^ -1) | (-(v5476 ^ -1))) >> 31)) & 2)) - (v5477 + ((~(((v5478 ^ -1) | (-(v5478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5498[v5598] = v5495;
      int * v5500 = v5434->cache_tags;
      int v5601 = (int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1);
      v5500[v5577] = v5601;
      int * v5502 = v5434->cache_dirty;
      v5502[v5577] = 0;
      int * v5504 = v5434->cache_age;
      v5504[v5577] = 1;
      int * v5506 = v5434->cache_age;
      int v5507 = v5506[v5577];
      int v5508 = v5506[v5551];
      int v5607 = v5508 + ((int)((unsigned int)(v5508 - v5507) >> 31));
      v5506[v5551] = v5607;
      int * v5510 = v5434->cache_age;
      int v5511 = v5510[v5552];
      int v5609 = v5511 + ((int)((unsigned int)(v5511 - v5507) >> 31));
      v5510[v5552] = v5609;
      int * v5513 = v5434->cache_age;
      v5513[v5577] = 0;
      v5516 = v5577;
    }
    int * v5517 = v5434->cache_vals;
    int v5612 = v5516 * 2;
    int v5518 = v5517[v5612];
    int v5613 = (v5516 * 2) + 1;
    int v5519 = v5517[v5613];
    int v5614 = (((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5458 + ((~(((v5460 ^ -1) | (-(v5460 ^ -1))) >> 31)) & 2)) - (v5461 + ((~(((v5462 ^ -1) | (-(v5462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5517[v5614] = v5518;
    int * v5521 = v5434->cache_vals;
    int v5617 = ((((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5458 + ((~(((v5460 ^ -1) | (-(v5460 ^ -1))) >> 31)) & 2)) - (v5461 + ((~(((v5462 ^ -1) | (-(v5462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5521[v5617] = v5519;
    int * v5523 = v5434->cache_tags;
    int v5620 = ((((int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5458 + ((~(((v5460 ^ -1) | (-(v5460 ^ -1))) >> 31)) & 2)) - (v5461 + ((~(((v5462 ^ -1) | (-(v5462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5621 = (int)((unsigned int)((int)((unsigned int)(v5438 + 20) >> 2)) >> 1);
    v5523[v5620] = v5621;
    int * v5525 = v5434->cache_dirty;
    v5525[v5620] = 0;
    int * v5527 = v5434->cache_age;
    v5527[v5620] = 1;
    int * v5529 = v5434->cache_age;
    int v5530 = v5529[v5620];
    int v5531 = v5529[v5549];
    int v5627 = v5531 + ((int)((unsigned int)(v5531 - v5530) >> 31));
    v5529[v5549] = v5627;
    int * v5533 = v5434->cache_age;
    int v5534 = v5533[v5550];
    int v5629 = v5534 + ((int)((unsigned int)(v5534 - v5530) >> 31));
    v5533[v5550] = v5629;
    int * v5536 = v5434->cache_age;
    v5536[v5620] = 0;
    v5539 = v5620;
  }
  int v5632 = (v5539 * 2) + (((int)((unsigned int)(v5438 + 20) >> 2)) & 1);
  int v5540 = v5446[v5632];
  int * v5541 = v5434->regs;
  v5541[29] = v5540;
  struct StateT * v5543 = slot_86(v5434);
  return v5543;
}

struct StateT * slot_177(struct StateT * v9907) {
  int v9908 = v9907->timer;
  int v9920 = v9908 + 1;
  v9907->timer = v9920;
  int * v9910 = v9907->regs;
  int v9911 = v9910[28];
  int v9912 = v9910[5];
  bool v9924 = (v9911 ^ -2147483648) < (v9912 ^ -2147483648);
  int v9915;
  if (v9924) {
    v9915 = 1;
  } else {
    v9915 = 0;
  }
  int * v9916 = v9907->regs;
  v9916[5] = v9915;
  struct StateT * v9918 = slot_167(v9907);
  return v9918;
}

struct StateT * slot_27(struct StateT * v2621) {
  int v2622 = v2621->timer;
  int v2630 = v2622 + 1;
  v2621->timer = v2630;
  int * v2624 = v2621->regs;
  int v2625 = v2624[6];
  int v2626 = v2624[5];
  int v2634 = v2625 + v2626;
  v2624[5] = v2634;
  struct StateT * v2628 = slot_28(v2621);
  return v2628;
}

struct StateT * slot_24(struct StateT * v1975) {
  int v1976 = v1975->timer;
  int v1984 = v1976 + 1;
  v1975->timer = v1984;
  int * v1978 = v1975->regs;
  int v1979 = v1978[28];
  int v1980 = v1978[5];
  int v1988 = v1979 + v1980;
  v1978[5] = v1988;
  struct StateT * v1982 = slot_25(v1975);
  return v1982;
}

struct StateT * slot_126(struct StateT * v6728) {
  int v6729 = v6728->timer;
  int v6737 = v6729 + 1;
  v6728->timer = v6737;
  int * v6731 = v6728->regs;
  int v6732 = v6731[7];
  int v6733 = v6731[6];
  int v6741 = v6732 + v6733;
  v6731[6] = v6741;
  struct StateT * v6735 = slot_128(v6728);
  return v6735;
}

struct StateT * slot_341(struct StateT * v16210) {
  int v16211 = v16210->timer;
  int v16219 = v16211 + 1;
  v16210->timer = v16219;
  int * v16213 = v16210->regs;
  int v16214 = v16213[7];
  int v16215 = v16213[16];
  int v16224 = v16214 & v16215;
  v16213[29] = v16224;
  struct StateT * v16217 = slot_348(v16210);
  return v16217;
}

struct StateT * slot_47(struct StateT * v3337) {
  int v3338 = v3337->timer;
  int v3346 = v3338 + 1;
  v3337->timer = v3346;
  int * v3340 = v3337->regs;
  int v3341 = v3340[7];
  int v3342 = v3340[12];
  int v3350 = v3341 * v3342;
  v3340[7] = v3350;
  struct StateT * v3344 = slot_48(v3337);
  return v3344;
}

struct StateT * slot_19(struct StateT * v1887) {
  int v1888 = v1887->timer;
  int v1896 = v1888 + 1;
  v1887->timer = v1896;
  int * v1890 = v1887->regs;
  int v1891 = v1890[7];
  int v1892 = v1890[17];
  int v1900 = v1891 + v1892;
  v1890[17] = v1900;
  struct StateT * v1894 = slot_20(v1887);
  return v1894;
}

struct StateT * slot_130(struct StateT * v6803) {
  int v6804 = v6803->timer;
  int v6816 = v6804 + 1;
  v6803->timer = v6816;
  int * v6806 = v6803->regs;
  int v6807 = v6806[6];
  int v6808 = v6806[7];
  bool v6820 = (v6807 ^ -2147483648) < (v6808 ^ -2147483648);
  int v6811;
  if (v6820) {
    v6811 = 1;
  } else {
    v6811 = 0;
  }
  int * v6812 = v6803->regs;
  v6812[6] = v6811;
  struct StateT * v6814 = slot_139(v6803);
  return v6814;
}

struct StateT * slot_141(struct StateT * v7007) {
  int v7008 = v7007->timer;
  int v7016 = v7008 + 1;
  v7007->timer = v7016;
  int * v7010 = v7007->regs;
  int v7011 = v7010[18];
  int v7012 = v7010[6];
  int v7020 = v7011 + v7012;
  v7010[6] = v7020;
  struct StateT * v7014 = slot_136(v7007);
  return v7014;
}

struct StateT * slot_4(struct StateT * v961) {
  int v962 = v961->timer;
  int v1132 = v962 + 1;
  v961->timer = v1132;
  int * v964 = v961->regs;
  int v965 = v964[2];
  int v966 = v964[19];
  int * v967 = v961->cache_tags;
  int v1137 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
  int v968 = v967[v1137];
  int v1138 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + 1;
  int v969 = v967[v1138];
  int v1139 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
  int v970 = v967[v1139];
  int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v971 = v967[v1140];
  int v972 = v961->timer;
  int v1141 = v972 + ((100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1141;
  bool v1142 = !(((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1066;
  if (v1142) {
    int * v974 = v961->cache_age;
    int v1144 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v975 = v974[v1144];
    int v976 = v974[v1137];
    int v1145 = v976 + ((int)((unsigned int)(v976 - v975) >> 31));
    v974[v1137] = v1145;
    int * v978 = v961->cache_age;
    int v979 = v978[v1138];
    int v1147 = v979 + ((int)((unsigned int)(v979 - v975) >> 31));
    v978[v1138] = v1147;
    int * v981 = v961->cache_age;
    v981[v1144] = 0;
    v1066 = v1144;
  } else {
    int * v984 = v961->cache_age;
    int v1151 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
    int v985 = v984[v1151];
    int * v986 = v961->cache_tags;
    int v987 = v986[v1151];
    int v988 = v984[v1138];
    int v989 = v986[v1138];
    bool v1153 = !(((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
    int v1043;
    if (v1153) {
      int * v990 = v961->cache_age;
      int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
      int v991 = v990[v1155];
      int v992 = v990[v1139];
      int v1156 = v992 + ((int)((unsigned int)(v992 - v991) >> 31));
      v990[v1139] = v1156;
      int * v994 = v961->cache_age;
      int v995 = v994[v1140];
      int v1158 = v995 + ((int)((unsigned int)(v995 - v991) >> 31));
      v994[v1140] = v1158;
      int * v997 = v961->cache_age;
      v997[v1155] = 0;
      v1043 = v1155;
    } else {
      int * v1000 = v961->cache_age;
      int v1162 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
      int v1001 = v1000[v1162];
      int * v1002 = v961->cache_tags;
      int v1003 = v1002[v1162];
      int v1004 = v1000[v1140];
      int v1005 = v1002[v1140];
      int * v1006 = v961->cache_dirty;
      int v1165 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1007 = v1006[v1165];
      bool v1166 = !(v1007 == 0);
      if (v1166) {
        int * v1008 = v961->cache_tags;
        int v1009 = v1008[v1165];
        int * v1010 = v961->cache_vals;
        int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1011 = v1010[v1169];
        int v1170 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1012 = v1010[v1170];
        int * v1013 = v961->mem;
        int v1172 = v1009 * 2;
        v1013[v1172] = v1011;
        int * v1015 = v961->mem;
        int v1175 = (v1009 * 2) + 1;
        v1015[v1175] = v1012;
        ;
      } else {
        ;
      }
      int * v1020 = v961->mem;
      int v1180 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
      int v1021 = v1020[v1180];
      int v1181 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
      int v1022 = v1020[v1181];
      int * v1023 = v961->cache_vals;
      int v1183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1023[v1183] = v1021;
      int * v1025 = v961->cache_vals;
      int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1025[v1186] = v1022;
      int * v1027 = v961->cache_tags;
      int v1189 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
      v1027[v1165] = v1189;
      int * v1029 = v961->cache_dirty;
      v1029[v1165] = 0;
      int * v1031 = v961->cache_age;
      v1031[v1165] = 1;
      int * v1033 = v961->cache_age;
      int v1034 = v1033[v1165];
      int v1035 = v1033[v1139];
      int v1195 = v1035 + ((int)((unsigned int)(v1035 - v1034) >> 31));
      v1033[v1139] = v1195;
      int * v1037 = v961->cache_age;
      int v1038 = v1037[v1140];
      int v1197 = v1038 + ((int)((unsigned int)(v1038 - v1034) >> 31));
      v1037[v1140] = v1197;
      int * v1040 = v961->cache_age;
      v1040[v1165] = 0;
      v1043 = v1165;
    }
    int * v1044 = v961->cache_vals;
    int v1200 = v1043 * 2;
    int v1045 = v1044[v1200];
    int v1201 = (v1043 * 2) + 1;
    int v1046 = v1044[v1201];
    int v1202 = (((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1044[v1202] = v1045;
    int * v1048 = v961->cache_vals;
    int v1205 = ((((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1048[v1205] = v1046;
    int * v1050 = v961->cache_tags;
    int v1208 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1209 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1050[v1208] = v1209;
    int * v1052 = v961->cache_dirty;
    v1052[v1208] = 0;
    int * v1054 = v961->cache_age;
    v1054[v1208] = 1;
    int * v1056 = v961->cache_age;
    int v1057 = v1056[v1208];
    int v1058 = v1056[v1137];
    int v1215 = v1058 + ((int)((unsigned int)(v1058 - v1057) >> 31));
    v1056[v1137] = v1215;
    int * v1060 = v961->cache_age;
    int v1061 = v1060[v1138];
    int v1217 = v1061 + ((int)((unsigned int)(v1061 - v1057) >> 31));
    v1060[v1138] = v1217;
    int * v1063 = v961->cache_age;
    v1063[v1208] = 0;
    v1066 = v1208;
  }
  int * v1067 = v961->cache_vals;
  int v1220 = (v1066 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1067[v1220] = v966;
  int * v1069 = v961->cache_tags;
  int v1070 = v1069[v1139];
  int v1071 = v1069[v1140];
  bool v1223 = !(((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1125;
  if (v1223) {
    int * v1072 = v961->cache_age;
    int v1225 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v1073 = v1072[v1225];
    int v1074 = v1072[v1139];
    int v1226 = v1074 + ((int)((unsigned int)(v1074 - v1073) >> 31));
    v1072[v1139] = v1226;
    int * v1076 = v961->cache_age;
    int v1077 = v1076[v1140];
    int v1228 = v1077 + ((int)((unsigned int)(v1077 - v1073) >> 31));
    v1076[v1140] = v1228;
    int * v1079 = v961->cache_age;
    v1079[v1225] = 0;
    v1125 = v1225;
  } else {
    int * v1082 = v961->cache_age;
    int v1232 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
    int v1083 = v1082[v1232];
    int * v1084 = v961->cache_tags;
    int v1085 = v1084[v1232];
    int v1086 = v1082[v1140];
    int v1087 = v1084[v1140];
    int * v1088 = v961->cache_dirty;
    int v1235 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1089 = v1088[v1235];
    bool v1236 = !(v1089 == 0);
    if (v1236) {
      int * v1090 = v961->cache_tags;
      int v1091 = v1090[v1235];
      int * v1092 = v961->cache_vals;
      int v1239 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1093 = v1092[v1239];
      int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1094 = v1092[v1240];
      int * v1095 = v961->mem;
      int v1242 = v1091 * 2;
      v1095[v1242] = v1093;
      int * v1097 = v961->mem;
      int v1245 = (v1091 * 2) + 1;
      v1097[v1245] = v1094;
      ;
    } else {
      ;
    }
    int * v1102 = v961->mem;
    int v1250 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
    int v1103 = v1102[v1250];
    int v1251 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
    int v1104 = v1102[v1251];
    int * v1105 = v961->cache_vals;
    int v1253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1105[v1253] = v1103;
    int * v1107 = v961->cache_vals;
    int v1256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1107[v1256] = v1104;
    int * v1109 = v961->cache_tags;
    int v1259 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1109[v1235] = v1259;
    int * v1111 = v961->cache_dirty;
    v1111[v1235] = 0;
    int * v1113 = v961->cache_age;
    v1113[v1235] = 1;
    int * v1115 = v961->cache_age;
    int v1116 = v1115[v1235];
    int v1117 = v1115[v1139];
    int v1265 = v1117 + ((int)((unsigned int)(v1117 - v1116) >> 31));
    v1115[v1139] = v1265;
    int * v1119 = v961->cache_age;
    int v1120 = v1119[v1140];
    int v1267 = v1120 + ((int)((unsigned int)(v1120 - v1116) >> 31));
    v1119[v1140] = v1267;
    int * v1122 = v961->cache_age;
    v1122[v1235] = 0;
    v1125 = v1235;
  }
  int * v1126 = v961->cache_vals;
  int v1270 = (v1125 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1126[v1270] = v966;
  int * v1128 = v961->cache_dirty;
  v1128[v1125] = 1;
  struct StateT * v1130 = slot_5(v961);
  return v1130;
}

struct StateT * slot_49(struct StateT * v3369) {
  int v3370 = v3369->timer;
  int v3378 = v3370 + 1;
  v3369->timer = v3378;
  int * v3372 = v3369->regs;
  int v3373 = v3372[7];
  int v3374 = v3372[17];
  int v3382 = v3373 + v3374;
  v3372[17] = v3382;
  struct StateT * v3376 = slot_50(v3369);
  return v3376;
}

struct StateT * slot_50(struct StateT * v3385) {
  int v3386 = v3385->timer;
  int v3398 = v3386 + 1;
  v3385->timer = v3398;
  int * v3388 = v3385->regs;
  int v3389 = v3388[6];
  int v3390 = v3388[30];
  bool v3402 = (v3389 ^ -2147483648) < (v3390 ^ -2147483648);
  int v3393;
  if (v3402) {
    v3393 = 1;
  } else {
    v3393 = 0;
  }
  int * v3394 = v3385->regs;
  v3394[30] = v3393;
  struct StateT * v3396 = slot_51(v3385);
  return v3396;
}

struct StateT * slot_59(struct StateT * v3558) {
  int v3559 = v3558->timer;
  int v3571 = v3559 + 1;
  v3558->timer = v3571;
  int * v3561 = v3558->regs;
  int v3562 = v3561[6];
  int v3563 = v3561[30];
  bool v3575 = (v3562 ^ -2147483648) < (v3563 ^ -2147483648);
  int v3566;
  if (v3575) {
    v3566 = 1;
  } else {
    v3566 = 0;
  }
  int * v3567 = v3558->regs;
  v3567[6] = v3566;
  struct StateT * v3569 = slot_60(v3558);
  return v3569;
}

struct StateT * slot_77(struct StateT * v4531) {
  int v4532 = v4531->timer;
  int v4544 = v4532 + 1;
  v4531->timer = v4544;
  int * v4534 = v4531->regs;
  int v4535 = v4534[28];
  int v4536 = v4534[5];
  bool v4548 = (v4535 ^ -2147483648) < (v4536 ^ -2147483648);
  int v4539;
  if (v4548) {
    v4539 = 1;
  } else {
    v4539 = 0;
  }
  int * v4540 = v4531->regs;
  v4540[5] = v4539;
  struct StateT * v4542 = slot_79(v4531);
  return v4542;
}

struct StateT * slot_71(struct StateT * v3839) {
  int v3840 = v3839->timer;
  int v3848 = v3840 + 1;
  v3839->timer = v3848;
  int * v3842 = v3839->regs;
  int v3843 = v3842[5];
  int v3844 = v3842[28];
  int v3852 = v3843 + v3844;
  v3842[28] = v3852;
  struct StateT * v3846 = slot_73(v3839);
  return v3846;
}

struct StateT * slot_45(struct StateT * v3303) {
  int v3304 = v3303->timer;
  int v3312 = v3304 + 1;
  v3303->timer = v3312;
  int * v3306 = v3303->regs;
  int v3307 = v3306[28];
  int v3308 = v3306[13];
  int v3317 = v3307 * v3308;
  v3306[18] = v3317;
  struct StateT * v3310 = slot_46(v3303);
  return v3310;
}

struct StateT * slot_69(struct StateT * v3756) {
  int * v3757 = v3756->saved_regs;
  int * v3758 = v3756->regs;
  int v3759 = v3758[5];
  v3757[5] = v3759;
  int v3761 = v3756->timer;
  int v3777 = v3761 + 1;
  v3756->timer = v3777;
  int * v3763 = v3756->regs;
  int v3764 = v3763[28];
  int v3765 = v3763[5];
  bool v3780 = (v3764 ^ -2147483648) < (v3765 ^ -2147483648);
  int v3768;
  if (v3780) {
    v3768 = 1;
  } else {
    v3768 = 0;
  }
  int * v3769 = v3756->regs;
  v3769[5] = v3768;
  struct StateT * v3771 = slot_70(v3756);
  return v3771;
}

struct StateT * slot_54(struct StateT * v3467) {
  int v3468 = v3467->timer;
  int v3480 = v3468 + 1;
  v3467->timer = v3480;
  int * v3470 = v3467->regs;
  int v3471 = v3470[29];
  int v3472 = v3470[8];
  bool v3484 = (v3471 ^ -2147483648) < (v3472 ^ -2147483648);
  int v3475;
  if (v3484) {
    v3475 = 1;
  } else {
    v3475 = 0;
  }
  int * v3476 = v3467->regs;
  v3476[6] = v3475;
  struct StateT * v3478 = slot_55(v3467);
  return v3478;
}

struct StateT * slot_42(struct StateT * v3256) {
  int v3257 = v3256->timer;
  int v3265 = v3257 + 1;
  v3256->timer = v3265;
  int * v3259 = v3256->regs;
  int v3260 = v3259[7];
  int v3261 = v3259[13];
  int v3270 = (((((int)((unsigned int)v3260 >> 16)) * ((int)((unsigned int)v3261 >> 16))) + ((int)((unsigned int)((v3260 & 65535) * ((int)((unsigned int)v3261 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3260 >> 16)) * (v3261 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3260 & 65535) * (v3261 & 65535)) >> 16)) + (((v3260 & 65535) * ((int)((unsigned int)v3261 >> 16))) & 65535)) + ((((int)((unsigned int)v3260 >> 16)) * (v3261 & 65535)) & 65535)) >> 16));
  v3259[9] = v3270;
  struct StateT * v3263 = slot_43(v3256);
  return v3263;
}

struct StateT * slot_12(struct StateT * v1762) {
  int v1763 = v1762->timer;
  int v1771 = v1763 + 1;
  v1762->timer = v1771;
  int * v1765 = v1762->regs;
  int v1766 = v1765[14];
  int v1767 = v1765[13];
  int v1776 = v1766 * v1767;
  v1765[7] = v1776;
  struct StateT * v1769 = slot_13(v1762);
  return v1769;
}

struct StateT * slot_65(struct StateT * v3663) {
  int * v3664 = v3663->saved_regs;
  int * v3665 = v3663->regs;
  int v3666 = v3665[28];
  v3664[28] = v3666;
  int v3668 = v3663->timer;
  int v3684 = v3668 + 1;
  v3663->timer = v3684;
  int * v3670 = v3663->regs;
  int v3671 = v3670[7];
  int v3672 = v3670[29];
  bool v3688 = (v3671 ^ -2147483648) < (v3672 ^ -2147483648);
  int v3675;
  if (v3688) {
    v3675 = 1;
  } else {
    v3675 = 0;
  }
  int * v3676 = v3663->regs;
  v3676[28] = v3675;
  struct StateT * v3678 = slot_66(v3663);
  return v3678;
}

struct StateT * slot_10(struct StateT * v1728) {
  int v1729 = v1728->timer;
  int v1737 = v1729 + 1;
  v1728->timer = v1737;
  int * v1731 = v1728->regs;
  int v1732 = v1731[15];
  int v1733 = v1731[12];
  int v1742 = v1732 * v1733;
  v1731[5] = v1742;
  struct StateT * v1735 = slot_11(v1728);
  return v1735;
}

struct StateT * slot_17(struct StateT * v1846) {
  int v1847 = v1846->timer;
  int v1855 = v1847 + 1;
  v1846->timer = v1855;
  int * v1849 = v1846->regs;
  int v1850 = v1849[5];
  int v1851 = v1849[17];
  int v1859 = v1850 + v1851;
  v1849[17] = v1859;
  struct StateT * v1853 = slot_18(v1846);
  return v1853;
}

struct StateT * slot_56(struct StateT * v3509) {
  int v3510 = v3509->timer;
  int v3518 = v3510 + 1;
  v3509->timer = v3518;
  int * v3512 = v3509->regs;
  int v3513 = v3512[9];
  int v3514 = v3512[6];
  int v3522 = v3513 + v3514;
  v3512[6] = v3522;
  struct StateT * v3516 = slot_57(v3509);
  return v3516;
}

struct StateT * slot_63(struct StateT * v3639) {
  int v3640 = v3639->timer;
  int v3648 = v3640 + 1;
  v3639->timer = v3648;
  int * v3642 = v3639->regs;
  int v3643 = v3642[6];
  int v3644 = v3642[30];
  int v3652 = v3643 + v3644;
  v3642[6] = v3652;
  struct StateT * v3646 = slot_64(v3639);
  return v3646;
}

struct StateT * slot_41(struct StateT * v3239) {
  int v3240 = v3239->timer;
  int v3248 = v3240 + 1;
  v3239->timer = v3248;
  int * v3242 = v3239->regs;
  int v3243 = v3242[7];
  int v3244 = v3242[13];
  int v3253 = v3243 * v3244;
  v3242[8] = v3253;
  struct StateT * v3246 = slot_42(v3239);
  return v3246;
}

struct StateT * slot_3(struct StateT * v646) {
  int v647 = v646->timer;
  int v817 = v647 + 1;
  v646->timer = v817;
  int * v649 = v646->regs;
  int v650 = v649[2];
  int v651 = v649[18];
  int * v652 = v646->cache_tags;
  int v822 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2;
  int v653 = v652[v822];
  int v823 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v654 = v652[v823];
  int v824 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2);
  int v655 = v652[v824];
  int v825 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v656 = v652[v825];
  int v657 = v646->timer;
  int v826 = v657 + ((100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v646->timer = v826;
  bool v827 = !(((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v751;
  if (v827) {
    int * v659 = v646->cache_age;
    int v829 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v660 = v659[v829];
    int v661 = v659[v822];
    int v830 = v661 + ((int)((unsigned int)(v661 - v660) >> 31));
    v659[v822] = v830;
    int * v663 = v646->cache_age;
    int v664 = v663[v823];
    int v832 = v664 + ((int)((unsigned int)(v664 - v660) >> 31));
    v663[v823] = v832;
    int * v666 = v646->cache_age;
    v666[v829] = 0;
    v751 = v829;
  } else {
    int * v669 = v646->cache_age;
    int v836 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2;
    int v670 = v669[v836];
    int * v671 = v646->cache_tags;
    int v672 = v671[v836];
    int v673 = v669[v823];
    int v674 = v671[v823];
    bool v838 = !(((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v728;
    if (v838) {
      int * v675 = v646->cache_age;
      int v840 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v676 = v675[v840];
      int v677 = v675[v824];
      int v841 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
      v675[v824] = v841;
      int * v679 = v646->cache_age;
      int v680 = v679[v825];
      int v843 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
      v679[v825] = v843;
      int * v682 = v646->cache_age;
      v682[v840] = 0;
      v728 = v840;
    } else {
      int * v685 = v646->cache_age;
      int v847 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2);
      int v686 = v685[v847];
      int * v687 = v646->cache_tags;
      int v688 = v687[v847];
      int v689 = v685[v825];
      int v690 = v687[v825];
      int * v691 = v646->cache_dirty;
      int v850 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v692 = v691[v850];
      bool v851 = !(v692 == 0);
      if (v851) {
        int * v693 = v646->cache_tags;
        int v694 = v693[v850];
        int * v695 = v646->cache_vals;
        int v854 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v696 = v695[v854];
        int v855 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v697 = v695[v855];
        int * v698 = v646->mem;
        int v857 = v694 * 2;
        v698[v857] = v696;
        int * v700 = v646->mem;
        int v860 = (v694 * 2) + 1;
        v700[v860] = v697;
        ;
      } else {
        ;
      }
      int * v705 = v646->mem;
      int v865 = ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2;
      int v706 = v705[v865];
      int v866 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2) + 1;
      int v707 = v705[v866];
      int * v708 = v646->cache_vals;
      int v868 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v708[v868] = v706;
      int * v710 = v646->cache_vals;
      int v871 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v710[v871] = v707;
      int * v712 = v646->cache_tags;
      int v874 = (int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1);
      v712[v850] = v874;
      int * v714 = v646->cache_dirty;
      v714[v850] = 0;
      int * v716 = v646->cache_age;
      v716[v850] = 1;
      int * v718 = v646->cache_age;
      int v719 = v718[v850];
      int v720 = v718[v824];
      int v880 = v720 + ((int)((unsigned int)(v720 - v719) >> 31));
      v718[v824] = v880;
      int * v722 = v646->cache_age;
      int v723 = v722[v825];
      int v882 = v723 + ((int)((unsigned int)(v723 - v719) >> 31));
      v722[v825] = v882;
      int * v725 = v646->cache_age;
      v725[v850] = 0;
      v728 = v850;
    }
    int * v729 = v646->cache_vals;
    int v885 = v728 * 2;
    int v730 = v729[v885];
    int v886 = (v728 * 2) + 1;
    int v731 = v729[v886];
    int v887 = (((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v729[v887] = v730;
    int * v733 = v646->cache_vals;
    int v890 = ((((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v733[v890] = v731;
    int * v735 = v646->cache_tags;
    int v893 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v894 = (int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1);
    v735[v893] = v894;
    int * v737 = v646->cache_dirty;
    v737[v893] = 0;
    int * v739 = v646->cache_age;
    v739[v893] = 1;
    int * v741 = v646->cache_age;
    int v742 = v741[v893];
    int v743 = v741[v822];
    int v900 = v743 + ((int)((unsigned int)(v743 - v742) >> 31));
    v741[v822] = v900;
    int * v745 = v646->cache_age;
    int v746 = v745[v823];
    int v902 = v746 + ((int)((unsigned int)(v746 - v742) >> 31));
    v745[v823] = v902;
    int * v748 = v646->cache_age;
    v748[v893] = 0;
    v751 = v893;
  }
  int * v752 = v646->cache_vals;
  int v905 = (v751 * 2) + (((int)((unsigned int)(v650 + 4) >> 2)) & 1);
  v752[v905] = v651;
  int * v754 = v646->cache_tags;
  int v755 = v754[v824];
  int v756 = v754[v825];
  bool v908 = !(((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v810;
  if (v908) {
    int * v757 = v646->cache_age;
    int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v758 = v757[v910];
    int v759 = v757[v824];
    int v911 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v824] = v911;
    int * v761 = v646->cache_age;
    int v762 = v761[v825];
    int v913 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v825] = v913;
    int * v764 = v646->cache_age;
    v764[v910] = 0;
    v810 = v910;
  } else {
    int * v767 = v646->cache_age;
    int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2);
    int v768 = v767[v917];
    int * v769 = v646->cache_tags;
    int v770 = v769[v917];
    int v771 = v767[v825];
    int v772 = v769[v825];
    int * v773 = v646->cache_dirty;
    int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v774 = v773[v920];
    bool v921 = !(v774 == 0);
    if (v921) {
      int * v775 = v646->cache_tags;
      int v776 = v775[v920];
      int * v777 = v646->cache_vals;
      int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v778 = v777[v924];
      int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v779 = v777[v925];
      int * v780 = v646->mem;
      int v927 = v776 * 2;
      v780[v927] = v778;
      int * v782 = v646->mem;
      int v930 = (v776 * 2) + 1;
      v782[v930] = v779;
      ;
    } else {
      ;
    }
    int * v787 = v646->mem;
    int v935 = ((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2;
    int v788 = v787[v935];
    int v936 = (((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) * 2) + 1;
    int v789 = v787[v936];
    int * v790 = v646->cache_vals;
    int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v790[v938] = v788;
    int * v792 = v646->cache_vals;
    int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v792[v941] = v789;
    int * v794 = v646->cache_tags;
    int v944 = (int)((unsigned int)((int)((unsigned int)(v650 + 4) >> 2)) >> 1);
    v794[v920] = v944;
    int * v796 = v646->cache_dirty;
    v796[v920] = 0;
    int * v798 = v646->cache_age;
    v798[v920] = 1;
    int * v800 = v646->cache_age;
    int v801 = v800[v920];
    int v802 = v800[v824];
    int v950 = v802 + ((int)((unsigned int)(v802 - v801) >> 31));
    v800[v824] = v950;
    int * v804 = v646->cache_age;
    int v805 = v804[v825];
    int v952 = v805 + ((int)((unsigned int)(v805 - v801) >> 31));
    v804[v825] = v952;
    int * v807 = v646->cache_age;
    v807[v920] = 0;
    v810 = v920;
  }
  int * v811 = v646->cache_vals;
  int v955 = (v810 * 2) + (((int)((unsigned int)(v650 + 4) >> 2)) & 1);
  v811[v955] = v651;
  int * v813 = v646->cache_dirty;
  v813[v810] = 1;
  struct StateT * v815 = slot_4(v646);
  return v815;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v187 = v17 + 1;
  v16->timer = v187;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2;
  int v23 = v22[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v24 = v22[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2);
  int v25 = v22[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26 = v22[v195];
  int v27 = v16->timer;
  int v196 = v27 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16->timer = v196;
  bool v197 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v121;
  if (v197) {
    int * v29 = v16->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v30 = v29[v199];
    int v31 = v29[v192];
    int v200 = v31 + ((int)((unsigned int)(v31 - v30) >> 31));
    v29[v192] = v200;
    int * v33 = v16->cache_age;
    int v34 = v33[v193];
    int v202 = v34 + ((int)((unsigned int)(v34 - v30) >> 31));
    v33[v193] = v202;
    int * v36 = v16->cache_age;
    v36[v199] = 0;
    v121 = v199;
  } else {
    int * v39 = v16->cache_age;
    int v206 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2;
    int v40 = v39[v206];
    int * v41 = v16->cache_tags;
    int v42 = v41[v206];
    int v43 = v39[v193];
    int v44 = v41[v193];
    bool v208 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v98;
    if (v208) {
      int * v45 = v16->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v46 = v45[v210];
      int v47 = v45[v194];
      int v211 = v47 + ((int)((unsigned int)(v47 - v46) >> 31));
      v45[v194] = v211;
      int * v49 = v16->cache_age;
      int v50 = v49[v195];
      int v213 = v50 + ((int)((unsigned int)(v50 - v46) >> 31));
      v49[v195] = v213;
      int * v52 = v16->cache_age;
      v52[v210] = 0;
      v98 = v210;
    } else {
      int * v55 = v16->cache_age;
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2);
      int v56 = v55[v217];
      int * v57 = v16->cache_tags;
      int v58 = v57[v217];
      int v59 = v55[v195];
      int v60 = v57[v195];
      int * v61 = v16->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v62 = v61[v220];
      bool v221 = !(v62 == 0);
      if (v221) {
        int * v63 = v16->cache_tags;
        int v64 = v63[v220];
        int * v65 = v16->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66 = v65[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v65[v225];
        int * v68 = v16->mem;
        int v227 = v64 * 2;
        v68[v227] = v66;
        int * v70 = v16->mem;
        int v230 = (v64 * 2) + 1;
        v70[v230] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v16->mem;
      int v235 = ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2;
      int v76 = v75[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2) + 1;
      int v77 = v75[v236];
      int * v78 = v16->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v78[v238] = v76;
      int * v80 = v16->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v80[v241] = v77;
      int * v82 = v16->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1);
      v82[v220] = v244;
      int * v84 = v16->cache_dirty;
      v84[v220] = 0;
      int * v86 = v16->cache_age;
      v86[v220] = 1;
      int * v88 = v16->cache_age;
      int v89 = v88[v220];
      int v90 = v88[v194];
      int v250 = v90 + ((int)((unsigned int)(v90 - v89) >> 31));
      v88[v194] = v250;
      int * v92 = v16->cache_age;
      int v93 = v92[v195];
      int v252 = v93 + ((int)((unsigned int)(v93 - v89) >> 31));
      v92[v195] = v252;
      int * v95 = v16->cache_age;
      v95[v220] = 0;
      v98 = v220;
    }
    int * v99 = v16->cache_vals;
    int v255 = v98 * 2;
    int v100 = v99[v255];
    int v256 = (v98 * 2) + 1;
    int v101 = v99[v256];
    int v257 = (((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v99[v257] = v100;
    int * v103 = v16->cache_vals;
    int v260 = ((((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v103[v260] = v101;
    int * v105 = v16->cache_tags;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v264 = (int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1);
    v105[v263] = v264;
    int * v107 = v16->cache_dirty;
    v107[v263] = 0;
    int * v109 = v16->cache_age;
    v109[v263] = 1;
    int * v111 = v16->cache_age;
    int v112 = v111[v263];
    int v113 = v111[v192];
    int v270 = v113 + ((int)((unsigned int)(v113 - v112) >> 31));
    v111[v192] = v270;
    int * v115 = v16->cache_age;
    int v116 = v115[v193];
    int v272 = v116 + ((int)((unsigned int)(v116 - v112) >> 31));
    v115[v193] = v272;
    int * v118 = v16->cache_age;
    v118[v263] = 0;
    v121 = v263;
  }
  int * v122 = v16->cache_vals;
  int v275 = (v121 * 2) + (((int)((unsigned int)(v20 + 12) >> 2)) & 1);
  v122[v275] = v21;
  int * v124 = v16->cache_tags;
  int v125 = v124[v194];
  int v126 = v124[v195];
  bool v278 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v180;
  if (v278) {
    int * v127 = v16->cache_age;
    int v280 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v128 = v127[v280];
    int v129 = v127[v194];
    int v281 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
    v127[v194] = v281;
    int * v131 = v16->cache_age;
    int v132 = v131[v195];
    int v283 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
    v131[v195] = v283;
    int * v134 = v16->cache_age;
    v134[v280] = 0;
    v180 = v280;
  } else {
    int * v137 = v16->cache_age;
    int v287 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2);
    int v138 = v137[v287];
    int * v139 = v16->cache_tags;
    int v140 = v139[v287];
    int v141 = v137[v195];
    int v142 = v139[v195];
    int * v143 = v16->cache_dirty;
    int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v144 = v143[v290];
    bool v291 = !(v144 == 0);
    if (v291) {
      int * v145 = v16->cache_tags;
      int v146 = v145[v290];
      int * v147 = v16->cache_vals;
      int v294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v148 = v147[v294];
      int v295 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v149 = v147[v295];
      int * v150 = v16->mem;
      int v297 = v146 * 2;
      v150[v297] = v148;
      int * v152 = v16->mem;
      int v300 = (v146 * 2) + 1;
      v152[v300] = v149;
      ;
    } else {
      ;
    }
    int * v157 = v16->mem;
    int v305 = ((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2;
    int v158 = v157[v305];
    int v306 = (((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) * 2) + 1;
    int v159 = v157[v306];
    int * v160 = v16->cache_vals;
    int v308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v308] = v158;
    int * v162 = v16->cache_vals;
    int v311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v162[v311] = v159;
    int * v164 = v16->cache_tags;
    int v314 = (int)((unsigned int)((int)((unsigned int)(v20 + 12) >> 2)) >> 1);
    v164[v290] = v314;
    int * v166 = v16->cache_dirty;
    v166[v290] = 0;
    int * v168 = v16->cache_age;
    v168[v290] = 1;
    int * v170 = v16->cache_age;
    int v171 = v170[v290];
    int v172 = v170[v194];
    int v320 = v172 + ((int)((unsigned int)(v172 - v171) >> 31));
    v170[v194] = v320;
    int * v174 = v16->cache_age;
    int v175 = v174[v195];
    int v322 = v175 + ((int)((unsigned int)(v175 - v171) >> 31));
    v174[v195] = v322;
    int * v177 = v16->cache_age;
    v177[v290] = 0;
    v180 = v290;
  }
  int * v181 = v16->cache_vals;
  int v325 = (v180 * 2) + (((int)((unsigned int)(v20 + 12) >> 2)) & 1);
  v181[v325] = v21;
  int * v183 = v16->cache_dirty;
  v183[v180] = 1;
  struct StateT * v185 = slot_2(v16);
  return v185;
}

struct StateT * slot_38(struct StateT * v3188) {
  int v3189 = v3188->timer;
  int v3197 = v3189 + 1;
  v3188->timer = v3197;
  int * v3191 = v3188->regs;
  int v3192 = v3191[7];
  int v3193 = v3191[12];
  int v3202 = (((((int)((unsigned int)v3192 >> 16)) * ((int)((unsigned int)v3193 >> 16))) + ((int)((unsigned int)((v3192 & 65535) * ((int)((unsigned int)v3193 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v3192 >> 16)) * (v3193 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v3192 & 65535) * (v3193 & 65535)) >> 16)) + (((v3192 & 65535) * ((int)((unsigned int)v3193 >> 16))) & 65535)) + ((((int)((unsigned int)v3192 >> 16)) * (v3193 & 65535)) & 65535)) >> 16));
  v3191[6] = v3202;
  struct StateT * v3195 = slot_39(v3188);
  return v3195;
}

struct StateT * slot_18(struct StateT * v1862) {
  int v1863 = v1862->timer;
  int v1875 = v1863 + 1;
  v1862->timer = v1875;
  int * v1865 = v1862->regs;
  int v1866 = v1865[17];
  int v1867 = v1865[5];
  bool v1879 = (v1866 ^ -2147483648) < (v1867 ^ -2147483648);
  int v1870;
  if (v1879) {
    v1870 = 1;
  } else {
    v1870 = 0;
  }
  int * v1871 = v1862->regs;
  v1871[15] = v1870;
  struct StateT * v1873 = slot_19(v1862);
  return v1873;
}

struct StateT * slot_9(struct StateT * v1711) {
  int v1712 = v1711->timer;
  int v1720 = v1712 + 1;
  v1711->timer = v1720;
  int * v1714 = v1711->regs;
  int v1715 = v1714[14];
  int v1716 = v1714[12];
  int v1725 = (((((int)((unsigned int)v1715 >> 16)) * ((int)((unsigned int)v1716 >> 16))) + ((int)((unsigned int)((v1715 & 65535) * ((int)((unsigned int)v1716 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1715 >> 16)) * (v1716 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1715 & 65535) * (v1716 & 65535)) >> 16)) + (((v1715 & 65535) * ((int)((unsigned int)v1716 >> 16))) & 65535)) + ((((int)((unsigned int)v1715 >> 16)) * (v1716 & 65535)) & 65535)) >> 16));
  v1714[17] = v1725;
  struct StateT * v1718 = slot_10(v1711);
  return v1718;
}

struct StateT * slot_43(struct StateT * v3273) {
  int v3274 = v3273->timer;
  int v3281 = v3274 + 1;
  v3273->timer = v3281;
  int * v3276 = v3273->regs;
  int v3277 = v3276[5];
  int v3284 = v3277 << 13;
  v3276[5] = v3284;
  struct StateT * v3279 = slot_44(v3273);
  return v3279;
}

struct StateT * slot_55(struct StateT * v3492) {
  int v3493 = v3492->timer;
  int v3501 = v3493 + 1;
  v3492->timer = v3501;
  int * v3495 = v3492->regs;
  int v3496 = v3495[29];
  int v3497 = v3495[5];
  int v3506 = v3496 + v3497;
  v3495[7] = v3506;
  struct StateT * v3499 = slot_56(v3492);
  return v3499;
}

struct StateT * slot_58(struct StateT * v3541) {
  int v3542 = v3541->timer;
  int v3550 = v3542 + 1;
  v3541->timer = v3550;
  int * v3544 = v3541->regs;
  int v3545 = v3544[18];
  int v3546 = v3544[6];
  int v3555 = v3545 + v3546;
  v3544[5] = v3555;
  struct StateT * v3548 = slot_59(v3541);
  return v3548;
}

struct StateT * slot_66(struct StateT * v3695) {
  int v3696 = v3695->timer;
  int v3704 = v3696 + 1;
  v3695->timer = v3704;
  int * v3698 = v3695->regs;
  int v3699 = v3698[5];
  int v3700 = v3698[28];
  int v3708 = v3699 + v3700;
  v3698[28] = v3708;
  struct StateT * v3702 = slot_67(v3695);
  return v3702;
}

struct StateT * slot_48(struct StateT * v3353) {
  int v3354 = v3353->timer;
  int v3362 = v3354 + 1;
  v3353->timer = v3362;
  int * v3356 = v3353->regs;
  int v3357 = v3356[30];
  int v3358 = v3356[6];
  int v3366 = v3357 + v3358;
  v3356[6] = v3366;
  struct StateT * v3360 = slot_49(v3353);
  return v3360;
}

struct StateT * slot_8(struct StateT * v1697) {
  int v1698 = v1697->timer;
  int v1705 = v1698 + 1;
  v1697->timer = v1705;
  int * v1700 = v1697->regs;
  int v1701 = v1700[16];
  int v1708 = v1701 + -1;
  v1700[16] = v1708;
  struct StateT * v1703 = slot_9(v1697);
  return v1703;
}

struct StateT * slot_5(struct StateT * v1276) {
  int v1277 = v1276->timer;
  int v1387 = v1277 + 1;
  v1276->timer = v1387;
  int * v1279 = v1276->regs;
  int v1280 = v1279[11];
  int * v1281 = v1276->cache_tags;
  int v1391 = (((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2;
  int v1282 = v1281[v1391];
  int v1392 = ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1283 = v1281[v1392];
  int v1393 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2);
  int v1284 = v1281[v1393];
  int v1394 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1285 = v1281[v1394];
  int v1286 = v1276->timer;
  int v1395 = v1286 + ((100 ^ (((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1276->timer = v1395;
  int * v1288 = v1276->cache_vals;
  bool v1396 = !(((~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) == 0);
  int v1381;
  if (v1396) {
    int * v1289 = v1276->cache_age;
    int v1398 = ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) & 1);
    int v1290 = v1289[v1398];
    int v1291 = v1289[v1391];
    int v1399 = v1291 + ((int)((unsigned int)(v1291 - v1290) >> 31));
    v1289[v1391] = v1399;
    int * v1293 = v1276->cache_age;
    int v1294 = v1293[v1392];
    int v1401 = v1294 + ((int)((unsigned int)(v1294 - v1290) >> 31));
    v1293[v1392] = v1401;
    int * v1296 = v1276->cache_age;
    v1296[v1398] = 0;
    v1381 = v1398;
  } else {
    int * v1299 = v1276->cache_age;
    int v1405 = (((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2;
    int v1300 = v1299[v1405];
    int * v1301 = v1276->cache_tags;
    int v1302 = v1301[v1405];
    int v1303 = v1299[v1392];
    int v1304 = v1301[v1392];
    bool v1407 = !(((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) | (~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31))) == 0);
    int v1358;
    if (v1407) {
      int * v1305 = v1276->cache_age;
      int v1409 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1))))) >> 31)) & 1);
      int v1306 = v1305[v1409];
      int v1307 = v1305[v1393];
      int v1410 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
      v1305[v1393] = v1410;
      int * v1309 = v1276->cache_age;
      int v1310 = v1309[v1394];
      int v1412 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
      v1309[v1394] = v1412;
      int * v1312 = v1276->cache_age;
      v1312[v1409] = 0;
      v1358 = v1409;
    } else {
      int * v1315 = v1276->cache_age;
      int v1416 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2);
      int v1316 = v1315[v1416];
      int * v1317 = v1276->cache_tags;
      int v1318 = v1317[v1416];
      int v1319 = v1315[v1394];
      int v1320 = v1317[v1394];
      int * v1321 = v1276->cache_dirty;
      int v1419 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1322 = v1321[v1419];
      bool v1420 = !(v1322 == 0);
      if (v1420) {
        int * v1323 = v1276->cache_tags;
        int v1324 = v1323[v1419];
        int * v1325 = v1276->cache_vals;
        int v1423 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1326 = v1325[v1423];
        int v1424 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1327 = v1325[v1424];
        int * v1328 = v1276->mem;
        int v1426 = v1324 * 2;
        v1328[v1426] = v1326;
        int * v1330 = v1276->mem;
        int v1429 = (v1324 * 2) + 1;
        v1330[v1429] = v1327;
        ;
      } else {
        ;
      }
      int * v1335 = v1276->mem;
      int v1434 = ((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) * 2;
      int v1336 = v1335[v1434];
      int v1435 = (((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) * 2) + 1;
      int v1337 = v1335[v1435];
      int * v1338 = v1276->cache_vals;
      int v1437 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1338[v1437] = v1336;
      int * v1340 = v1276->cache_vals;
      int v1440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1340[v1440] = v1337;
      int * v1342 = v1276->cache_tags;
      int v1443 = (int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1);
      v1342[v1419] = v1443;
      int * v1344 = v1276->cache_dirty;
      v1344[v1419] = 0;
      int * v1346 = v1276->cache_age;
      v1346[v1419] = 1;
      int * v1348 = v1276->cache_age;
      int v1349 = v1348[v1419];
      int v1350 = v1348[v1393];
      int v1449 = v1350 + ((int)((unsigned int)(v1350 - v1349) >> 31));
      v1348[v1393] = v1449;
      int * v1352 = v1276->cache_age;
      int v1353 = v1352[v1394];
      int v1451 = v1353 + ((int)((unsigned int)(v1353 - v1349) >> 31));
      v1352[v1394] = v1451;
      int * v1355 = v1276->cache_age;
      v1355[v1419] = 0;
      v1358 = v1419;
    }
    int * v1359 = v1276->cache_vals;
    int v1454 = v1358 * 2;
    int v1360 = v1359[v1454];
    int v1455 = (v1358 * 2) + 1;
    int v1361 = v1359[v1455];
    int v1456 = (((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1359[v1456] = v1360;
    int * v1363 = v1276->cache_vals;
    int v1459 = ((((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1363[v1459] = v1361;
    int * v1365 = v1276->cache_tags;
    int v1462 = ((((int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1463 = (int)((unsigned int)((int)((unsigned int)v1280 >> 2)) >> 1);
    v1365[v1462] = v1463;
    int * v1367 = v1276->cache_dirty;
    v1367[v1462] = 0;
    int * v1369 = v1276->cache_age;
    v1369[v1462] = 1;
    int * v1371 = v1276->cache_age;
    int v1372 = v1371[v1462];
    int v1373 = v1371[v1391];
    int v1469 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
    v1371[v1391] = v1469;
    int * v1375 = v1276->cache_age;
    int v1376 = v1375[v1392];
    int v1471 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
    v1375[v1392] = v1471;
    int * v1378 = v1276->cache_age;
    v1378[v1462] = 0;
    v1381 = v1462;
  }
  int v1474 = (v1381 * 2) + (((int)((unsigned int)v1280 >> 2)) & 1);
  int v1382 = v1288[v1474];
  int * v1383 = v1276->regs;
  v1383[14] = v1382;
  struct StateT * v1385 = slot_6(v1276);
  return v1385;
}

struct StateT * slot_44(struct StateT * v3287) {
  int v3288 = v3287->timer;
  int v3296 = v3288 + 1;
  v3287->timer = v3296;
  int * v3290 = v3287->regs;
  int v3291 = v3290[5];
  int v3292 = v3290[29];
  int v3300 = v3291 | v3292;
  v3290[5] = v3300;
  struct StateT * v3294 = slot_45(v3287);
  return v3294;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, 10 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 2147483647);
    s2.mem[10 + i] = secret(0, 2147483647);
  }
  // a12 and a13, secret: a uint64's halves, drawn separately
  // in each state
  s1.regs[12] = secret(0, 2147483647);
  s2.regs[12] = secret(0, 2147483647);
  s1.regs[13] = secret(0, 2147483647);
  s2.regs[13] = secret(0, 2147483647);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}