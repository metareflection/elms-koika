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

struct StateT * slot_12(struct StateT * v3477);
struct StateT * slot_228(struct StateT * v11024);
struct StateT * slot_143(struct StateT * v20965);
struct StateT * slot_120(struct StateT * v20607);
struct StateT * slot_226(struct StateT * v10775);
struct StateT * slot_167(struct StateT * v21342);
struct StateT * slot_268(struct StateT * v18934);
struct StateT * slot_152(struct StateT * v21111);
struct StateT * slot_231(struct StateT * v11305);
struct StateT * slot_199(struct StateT * v21846);
struct StateT * slot_252(struct StateT * v14316);
struct StateT * slot_92(struct StateT * v15294);
struct StateT * slot_232(struct StateT * v11525);
struct StateT * slot_269(struct StateT * v19155);
struct StateT * slot_31(struct StateT * v6622);
struct StateT * slot_236(struct StateT * v12032);
struct StateT * slot_241(struct StateT * v12180);
struct StateT * slot_160(struct StateT * v21236);
struct StateT * slot_251(struct StateT * v13985);
struct StateT * slot_65(struct StateT * v11010);
struct StateT * slot_10(struct StateT * v2847);
struct StateT * slot_150(struct StateT * v21077);
struct StateT * slot_74(struct StateT * v12048);
struct StateT * slot_262(struct StateT * v17620);
struct StateT * slot_107(struct StateT * v19359);
struct StateT * slot_136(struct StateT * v20861);
struct StateT * slot_84(struct StateT * v12648);
struct StateT * slot_28(struct StateT * v6581);
struct StateT * slot_155(struct StateT * v21162);
struct StateT * slot_177(struct StateT * v21503);
struct StateT * slot_229(struct StateT * v11053);
struct StateT * slot_17(struct StateT * v4528);
struct StateT * slot_181(struct StateT * v21564);
struct StateT * slot_197(struct StateT * v21815);
struct StateT * slot_207(struct StateT * v21966);
struct StateT * slot_156(struct StateT * v21177);
struct StateT * slot_154(struct StateT * v21145);
struct StateT * slot_68(struct StateT * v11289);
struct StateT * slot_260(struct StateT * v16965);
struct StateT * slot_105(struct StateT * v18920);
struct StateT * slot_27(struct StateT * v6568);
struct StateT * slot_164(struct StateT * v21297);
struct StateT * slot_15(struct StateT * v4120);
struct StateT * slot_133(struct StateT * v20812);
struct StateT * slot_56(struct StateT * v9982);
struct StateT * slot_244(struct StateT * v12271);
struct StateT * slot_222(struct StateT * v10274);
struct StateT * slot_34(struct StateT * v6665);
struct StateT * slot_171(struct StateT * v21406);
struct StateT * slot_162(struct StateT * v21267);
struct StateT * slot_21(struct StateT * v5344);
struct StateT * slot_239(struct StateT * v12121);
struct StateT * slot_118(struct StateT * v20578);
struct StateT * slot_121(struct StateT * v20623);
struct StateT * slot_144(struct StateT * v20981);
struct StateT * slot_267(struct StateT * v18716);
struct StateT * slot_201(struct StateT * v21876);
struct StateT * slot_94(struct StateT * v15958);
struct StateT * slot_63(struct StateT * v10759);
struct StateT * slot_146(struct StateT * v21010);
struct StateT * slot_24(struct StateT * v5956);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v21786);
struct StateT * slot_125(struct StateT * v20683);
struct StateT * slot_254(struct StateT * v14979);
struct StateT * slot_148(struct StateT * v21043);
struct StateT * slot_126(struct StateT * v20697);
struct StateT * slot_223(struct StateT * v10494);
struct StateT * slot_79(struct StateT * v12194);
struct StateT * slot_237(struct StateT * v12065);
struct StateT * slot_41(struct StateT * v8263);
struct StateT * slot_39(struct StateT * v7637);
struct StateT * slot_142(struct StateT * v20951);
struct StateT * slot_60(struct StateT * v10478);
struct StateT * slot_238(struct StateT * v12093);
struct StateT * slot_112(struct StateT * v20463);
struct StateT * slot_256(struct StateT * v15643);
struct StateT * slot_272(struct StateT * v19817);
struct StateT * slot_47(struct StateT * v9253);
struct StateT * slot_214(struct StateT * v9651);
struct StateT * slot_29(struct StateT * v6594);
struct StateT * slot_16(struct StateT * v4324);
struct StateT * slot_245(struct StateT * v12301);
struct StateT * slot_113(struct StateT * v20494);
struct StateT * slot_151(struct StateT * v21094);
struct StateT * slot_7(struct StateT * v1902);
struct StateT * slot_124(struct StateT * v20668);
struct StateT * slot_191(struct StateT * v21718);
struct StateT * slot_103(struct StateT * v18481);
struct StateT * slot_128(struct StateT * v20729);
struct StateT * slot_19(struct StateT * v4936);
struct StateT * slot_87(struct StateT * v13638);
struct StateT * slot_67(struct StateT * v11257);
struct StateT * slot_81(struct StateT * v12256);
struct StateT * slot_95(struct StateT * v16290);
struct StateT * slot_115(struct StateT * v20533);
struct StateT * slot_78(struct StateT * v12165);
struct StateT * slot_32(struct StateT * v6637);
struct StateT * slot_205(struct StateT * v21936);
struct StateT * slot_193(struct StateT * v21752);
struct StateT * slot_233(struct StateT * v11557);
struct StateT * slot_176(struct StateT * v21489);
struct StateT * slot_189(struct StateT * v21686);
struct StateT * slot_33(struct StateT * v6652);
struct StateT * slot_35(struct StateT * v6679);
struct StateT * slot_258(struct StateT * v16305);
struct StateT * slot_246(struct StateT * v12333);
struct StateT * slot_210(struct StateT * v22015);
struct StateT * slot_166(struct StateT * v21326);
struct StateT * slot_51(struct StateT * v9634);
struct StateT * slot_52(struct StateT * v9667);
struct StateT * slot_83(struct StateT * v12317);
struct StateT * slot_25(struct StateT * v6160);
struct StateT * slot_209(struct StateT * v21999);
struct StateT * slot_3(struct StateT * v642);
struct StateT * slot_264(struct StateT * v18059);
struct StateT * slot_123(struct StateT * v20652);
struct StateT * slot_73(struct StateT * v12015);
struct StateT * slot_270(struct StateT * v19376);
struct StateT * slot_198(struct StateT * v21831);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v21654);
struct StateT * slot_97(struct StateT * v16949);
struct StateT * slot_182(struct StateT * v21579);
struct StateT * slot_38(struct StateT * v7322);
struct StateT * slot_178(struct StateT * v21519);
struct StateT * slot_106(struct StateT * v19138);
struct StateT * slot_98(struct StateT * v17276);
struct StateT * slot_159(struct StateT * v21222);
struct StateT * slot_46(struct StateT * v9238);
struct StateT * slot_212(struct StateT * v22045);
struct StateT * slot_132(struct StateT * v20795);
struct StateT * slot_130(struct StateT * v20762);
struct StateT * slot_211(struct StateT * v22031);
struct StateT * slot_20(struct StateT * v5140);
struct StateT * slot_141(struct StateT * v20936);
struct StateT * slot_61(struct StateT * v10510);
struct StateT * slot_30(struct StateT * v6607);
struct StateT * slot_4(struct StateT * v957);
struct StateT * slot_18(struct StateT * v4732);
struct StateT * slot_9(struct StateT * v2532);
struct StateT * slot_183(struct StateT * v21593);
struct StateT * slot_240(struct StateT * v12151);
struct StateT * slot_247(struct StateT * v12663);
struct StateT * slot_43(struct StateT * v8893);
struct StateT * slot_70(struct StateT * v11541);
struct StateT * slot_168(struct StateT * v21358);
struct StateT * slot_76(struct StateT * v12107);
struct StateT * slot_6(struct StateT * v1587);
struct StateT * slot_225(struct StateT * v10743);
struct StateT * slot_55(struct StateT * v9951);
struct StateT * slot_213(struct StateT * v9618);
struct StateT * slot_82(struct StateT * v12287);
struct StateT * slot_274(struct StateT * v20259);
struct StateT * slot_263(struct StateT * v17840);
struct StateT * slot_161(struct StateT * v21252);
struct StateT * slot_185(struct StateT * v21624);
struct StateT * slot_91(struct StateT * v14962);
struct StateT * slot_58(struct StateT * v10229);
struct StateT * slot_89(struct StateT * v14300);
struct StateT * slot_255(struct StateT * v15311);
struct StateT * slot_66(struct StateT * v11037);
struct StateT * slot_140(struct StateT * v20920);
struct StateT * slot_265(struct StateT * v18277);
struct StateT * slot_49(struct StateT * v9583);
struct StateT * slot_216(struct StateT * v9714);
struct StateT * slot_50(struct StateT * v9598);
struct StateT * slot_37(struct StateT * v7007);
struct StateT * slot_114(struct StateT * v20516);
struct StateT * slot_135(struct StateT * v20846);
struct StateT * slot_248(struct StateT * v12992);
struct StateT * slot_257(struct StateT * v15975);
struct StateT * slot_59(struct StateT * v10260);
struct StateT * slot_192(struct StateT * v21735);
struct StateT * slot_40(struct StateT * v7948);
struct StateT * slot_48(struct StateT * v9268);
struct StateT * slot_77(struct StateT * v12135);
struct StateT * slot_85(struct StateT * v12978);
struct StateT * slot_75(struct StateT * v12078);
struct StateT * slot_72(struct StateT * v11794);
struct StateT * slot_119(struct StateT * v20593);
struct StateT * slot_71(struct StateT * v11761);
struct StateT * slot_101(struct StateT * v18044);
struct StateT * slot_276(struct StateT * v20511);
struct StateT * slot_108(struct StateT * v19580);
struct StateT * slot_116(struct StateT * v20548);
struct StateT * slot_93(struct StateT * v15626);
struct StateT * slot_266(struct StateT * v18497);
struct StateT * slot_88(struct StateT * v13969);
struct StateT * slot_96(struct StateT * v16620);
struct StateT * slot_215(struct StateT * v9684);
struct StateT * slot_234(struct StateT * v11778);
struct StateT * slot_45(struct StateT * v9223);
struct StateT * slot_218(struct StateT * v9966);
struct StateT * slot_220(struct StateT * v10025);
struct StateT * slot_134(struct StateT * v20829);
struct StateT * slot_175(struct StateT * v21474);
struct StateT * slot_273(struct StateT * v20038);
struct StateT * slot_69(struct StateT * v11509);
struct StateT * slot_202(struct StateT * v21891);
struct StateT * slot_230(struct StateT * v11273);
struct StateT * slot_188(struct StateT * v21670);
struct StateT * slot_138(struct StateT * v20891);
struct StateT * slot_186(struct StateT * v21638);
struct StateT * slot_102(struct StateT * v18263);
struct StateT * slot_145(struct StateT * v20996);
struct StateT * slot_110(struct StateT * v20021);
struct StateT * slot_196(struct StateT * v21801);
struct StateT * slot_208(struct StateT * v21982);
struct StateT * slot_172(struct StateT * v21423);
struct StateT * slot_131(struct StateT * v20778);
struct StateT * slot_8(struct StateT * v2217);
struct StateT * slot_180(struct StateT * v21548);
struct StateT * slot_203(struct StateT * v21905);
struct StateT * slot_190(struct StateT * v21702);
struct StateT * slot_157(struct StateT * v21191);
struct StateT * slot_242(struct StateT * v12208);
struct StateT * slot_200(struct StateT * v21860);
struct StateT * slot_243(struct StateT * v12240);
struct StateT * slot_173(struct StateT * v21440);
struct StateT * slot_149(struct StateT * v21060);
struct StateT * slot_5(struct StateT * v1272);
struct StateT * slot_104(struct StateT * v18701);
struct StateT * slot_235(struct StateT * v11811);
struct StateT * slot_275(struct StateT * v20480);
struct StateT * slot_54(struct StateT * v9730);
struct StateT * slot_26(struct StateT * v6364);
struct StateT * slot_206(struct StateT * v21950);
struct StateT * slot_227(struct StateT * v10994);
struct StateT * slot_169(struct StateT * v21374);
struct StateT * slot_253(struct StateT * v14647);
struct StateT * slot_64(struct StateT * v10979);
struct StateT * slot_170(struct StateT * v21390);
struct StateT * slot_14(struct StateT * v4107);
struct StateT * slot_53(struct StateT * v9697);
struct StateT * slot_80(struct StateT * v12224);
struct StateT * slot_44(struct StateT * v9208);
struct StateT * slot_261(struct StateT * v17291);
struct StateT * slot_137(struct StateT * v20875);
struct StateT * slot_122(struct StateT * v20638);
struct StateT * slot_99(struct StateT * v17606);
struct StateT * slot_179(struct StateT * v21534);
struct StateT * slot_219(struct StateT * v9996);
struct StateT * slot_36(struct StateT * v6692);
struct StateT * slot_57(struct StateT * v10009);
struct StateT * slot_62(struct StateT * v10729);
struct StateT * slot_22(struct StateT * v5548);
struct StateT * slot_139(struct StateT * v20906);
struct StateT * slot_221(struct StateT * v10244);
struct StateT * slot_23(struct StateT * v5752);
struct StateT * slot_153(struct StateT * v21128);
struct StateT * slot_2(struct StateT * v327);
struct StateT * slot_86(struct StateT * v13307);
struct StateT * slot_129(struct StateT * v20746);
struct StateT * slot_158(struct StateT * v21207);
struct StateT * slot_100(struct StateT * v17824);
struct StateT * slot_271(struct StateT * v19596);
struct StateT * slot_127(struct StateT * v20713);
struct StateT * slot_217(struct StateT * v9747);
struct StateT * slot_13(struct StateT * v3792);
struct StateT * slot_111(struct StateT * v20242);
struct StateT * slot_109(struct StateT * v19800);
struct StateT * slot_174(struct StateT * v21457);
struct StateT * slot_147(struct StateT * v21027);
struct StateT * slot_42(struct StateT * v8578);
struct StateT * slot_224(struct StateT * v10525);
struct StateT * slot_163(struct StateT * v21281);
struct StateT * slot_184(struct StateT * v21609);
struct StateT * slot_204(struct StateT * v21921);
struct StateT * slot_194(struct StateT * v21769);
struct StateT * slot_165(struct StateT * v21312);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v13654);
struct StateT * slot_259(struct StateT * v16634);
struct StateT * slot_117(struct StateT * v20562);
struct StateT * slot_249(struct StateT * v13323);
struct StateT * slot_90(struct StateT * v14631);
struct StateT * slot_11(struct StateT * v3162);
struct StateT * slot_12(struct StateT * v3477) {
  int v3478 = v3477->timer;
  int v3648 = v3478 + 1;
  v3477->timer = v3648;
  int * v3480 = v3477->regs;
  int v3481 = v3480[2];
  int v3482 = v3480[26];
  int * v3483 = v3477->cache_tags;
  int v3653 = (((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2;
  int v3484 = v3483[v3653];
  int v3654 = ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3485 = v3483[v3654];
  int v3655 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2);
  int v3486 = v3483[v3655];
  int v3656 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3487 = v3483[v3656];
  int v3488 = v3477->timer;
  int v3657 = v3488 + ((100 ^ (((~(((v3486 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3486 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3486 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3486 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3477->timer = v3657;
  bool v3658 = !(((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31))) == 0);
  int v3582;
  if (v3658) {
    int * v3490 = v3477->cache_age;
    int v3660 = ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2) + ((~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) & 1);
    int v3491 = v3490[v3660];
    int v3492 = v3490[v3653];
    int v3661 = v3492 + ((int)((unsigned int)(v3492 - v3491) >> 31));
    v3490[v3653] = v3661;
    int * v3494 = v3477->cache_age;
    int v3495 = v3494[v3654];
    int v3663 = v3495 + ((int)((unsigned int)(v3495 - v3491) >> 31));
    v3494[v3654] = v3663;
    int * v3497 = v3477->cache_age;
    v3497[v3660] = 0;
    v3582 = v3660;
  } else {
    int * v3500 = v3477->cache_age;
    int v3667 = (((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2;
    int v3501 = v3500[v3667];
    int * v3502 = v3477->cache_tags;
    int v3503 = v3502[v3667];
    int v3504 = v3500[v3654];
    int v3505 = v3502[v3654];
    bool v3669 = !(((~(((v3486 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3486 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31))) == 0);
    int v3559;
    if (v3669) {
      int * v3506 = v3477->cache_age;
      int v3671 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3487 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) & 1);
      int v3507 = v3506[v3671];
      int v3508 = v3506[v3655];
      int v3672 = v3508 + ((int)((unsigned int)(v3508 - v3507) >> 31));
      v3506[v3655] = v3672;
      int * v3510 = v3477->cache_age;
      int v3511 = v3510[v3656];
      int v3674 = v3511 + ((int)((unsigned int)(v3511 - v3507) >> 31));
      v3510[v3656] = v3674;
      int * v3513 = v3477->cache_age;
      v3513[v3671] = 0;
      v3559 = v3671;
    } else {
      int * v3516 = v3477->cache_age;
      int v3678 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2);
      int v3517 = v3516[v3678];
      int * v3518 = v3477->cache_tags;
      int v3519 = v3518[v3678];
      int v3520 = v3516[v3656];
      int v3521 = v3518[v3656];
      int * v3522 = v3477->cache_dirty;
      int v3681 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3523 = v3522[v3681];
      bool v3682 = !(v3523 == 0);
      if (v3682) {
        int * v3524 = v3477->cache_tags;
        int v3525 = v3524[v3681];
        int * v3526 = v3477->cache_vals;
        int v3685 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3527 = v3526[v3685];
        int v3686 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3528 = v3526[v3686];
        int * v3529 = v3477->mem;
        int v3688 = v3525 * 2;
        v3529[v3688] = v3527;
        int * v3531 = v3477->mem;
        int v3691 = (v3525 * 2) + 1;
        v3531[v3691] = v3528;
        ;
      } else {
        ;
      }
      int * v3536 = v3477->mem;
      int v3696 = ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) * 2;
      int v3537 = v3536[v3696];
      int v3697 = (((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) * 2) + 1;
      int v3538 = v3536[v3697];
      int * v3539 = v3477->cache_vals;
      int v3699 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3539[v3699] = v3537;
      int * v3541 = v3477->cache_vals;
      int v3702 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3541[v3702] = v3538;
      int * v3543 = v3477->cache_tags;
      int v3705 = (int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1);
      v3543[v3681] = v3705;
      int * v3545 = v3477->cache_dirty;
      v3545[v3681] = 0;
      int * v3547 = v3477->cache_age;
      v3547[v3681] = 1;
      int * v3549 = v3477->cache_age;
      int v3550 = v3549[v3681];
      int v3551 = v3549[v3655];
      int v3711 = v3551 + ((int)((unsigned int)(v3551 - v3550) >> 31));
      v3549[v3655] = v3711;
      int * v3553 = v3477->cache_age;
      int v3554 = v3553[v3656];
      int v3713 = v3554 + ((int)((unsigned int)(v3554 - v3550) >> 31));
      v3553[v3656] = v3713;
      int * v3556 = v3477->cache_age;
      v3556[v3681] = 0;
      v3559 = v3681;
    }
    int * v3560 = v3477->cache_vals;
    int v3716 = v3559 * 2;
    int v3561 = v3560[v3716];
    int v3717 = (v3559 * 2) + 1;
    int v3562 = v3560[v3717];
    int v3718 = (((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v3501 + ((~(((v3503 ^ -1) | (-(v3503 ^ -1))) >> 31)) & 2)) - (v3504 + ((~(((v3505 ^ -1) | (-(v3505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3560[v3718] = v3561;
    int * v3564 = v3477->cache_vals;
    int v3721 = ((((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v3501 + ((~(((v3503 ^ -1) | (-(v3503 ^ -1))) >> 31)) & 2)) - (v3504 + ((~(((v3505 ^ -1) | (-(v3505 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3564[v3721] = v3562;
    int * v3566 = v3477->cache_tags;
    int v3724 = ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v3501 + ((~(((v3503 ^ -1) | (-(v3503 ^ -1))) >> 31)) & 2)) - (v3504 + ((~(((v3505 ^ -1) | (-(v3505 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3725 = (int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1);
    v3566[v3724] = v3725;
    int * v3568 = v3477->cache_dirty;
    v3568[v3724] = 0;
    int * v3570 = v3477->cache_age;
    v3570[v3724] = 1;
    int * v3572 = v3477->cache_age;
    int v3573 = v3572[v3724];
    int v3574 = v3572[v3653];
    int v3731 = v3574 + ((int)((unsigned int)(v3574 - v3573) >> 31));
    v3572[v3653] = v3731;
    int * v3576 = v3477->cache_age;
    int v3577 = v3576[v3654];
    int v3733 = v3577 + ((int)((unsigned int)(v3577 - v3573) >> 31));
    v3576[v3654] = v3733;
    int * v3579 = v3477->cache_age;
    v3579[v3724] = 0;
    v3582 = v3724;
  }
  int * v3583 = v3477->cache_vals;
  int v3736 = (v3582 * 2) + (((int)((unsigned int)(v3481 + 48) >> 2)) & 1);
  v3583[v3736] = v3482;
  int * v3585 = v3477->cache_tags;
  int v3586 = v3585[v3655];
  int v3587 = v3585[v3656];
  bool v3739 = !(((~(((v3586 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3586 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v3587 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3587 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31))) == 0);
  int v3641;
  if (v3739) {
    int * v3588 = v3477->cache_age;
    int v3741 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3587 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))) | (-(v3587 ^ ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1))))) >> 31)) & 1);
    int v3589 = v3588[v3741];
    int v3590 = v3588[v3655];
    int v3742 = v3590 + ((int)((unsigned int)(v3590 - v3589) >> 31));
    v3588[v3655] = v3742;
    int * v3592 = v3477->cache_age;
    int v3593 = v3592[v3656];
    int v3744 = v3593 + ((int)((unsigned int)(v3593 - v3589) >> 31));
    v3592[v3656] = v3744;
    int * v3595 = v3477->cache_age;
    v3595[v3741] = 0;
    v3641 = v3741;
  } else {
    int * v3598 = v3477->cache_age;
    int v3748 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2);
    int v3599 = v3598[v3748];
    int * v3600 = v3477->cache_tags;
    int v3601 = v3600[v3748];
    int v3602 = v3598[v3656];
    int v3603 = v3600[v3656];
    int * v3604 = v3477->cache_dirty;
    int v3751 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3599 + ((~(((v3601 ^ -1) | (-(v3601 ^ -1))) >> 31)) & 2)) - (v3602 + ((~(((v3603 ^ -1) | (-(v3603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3605 = v3604[v3751];
    bool v3752 = !(v3605 == 0);
    if (v3752) {
      int * v3606 = v3477->cache_tags;
      int v3607 = v3606[v3751];
      int * v3608 = v3477->cache_vals;
      int v3755 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3599 + ((~(((v3601 ^ -1) | (-(v3601 ^ -1))) >> 31)) & 2)) - (v3602 + ((~(((v3603 ^ -1) | (-(v3603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3609 = v3608[v3755];
      int v3756 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3599 + ((~(((v3601 ^ -1) | (-(v3601 ^ -1))) >> 31)) & 2)) - (v3602 + ((~(((v3603 ^ -1) | (-(v3603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3610 = v3608[v3756];
      int * v3611 = v3477->mem;
      int v3758 = v3607 * 2;
      v3611[v3758] = v3609;
      int * v3613 = v3477->mem;
      int v3761 = (v3607 * 2) + 1;
      v3613[v3761] = v3610;
      ;
    } else {
      ;
    }
    int * v3618 = v3477->mem;
    int v3766 = ((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) * 2;
    int v3619 = v3618[v3766];
    int v3767 = (((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) * 2) + 1;
    int v3620 = v3618[v3767];
    int * v3621 = v3477->cache_vals;
    int v3769 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3599 + ((~(((v3601 ^ -1) | (-(v3601 ^ -1))) >> 31)) & 2)) - (v3602 + ((~(((v3603 ^ -1) | (-(v3603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3621[v3769] = v3619;
    int * v3623 = v3477->cache_vals;
    int v3772 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v3599 + ((~(((v3601 ^ -1) | (-(v3601 ^ -1))) >> 31)) & 2)) - (v3602 + ((~(((v3603 ^ -1) | (-(v3603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3623[v3772] = v3620;
    int * v3625 = v3477->cache_tags;
    int v3775 = (int)((unsigned int)((int)((unsigned int)(v3481 + 48) >> 2)) >> 1);
    v3625[v3751] = v3775;
    int * v3627 = v3477->cache_dirty;
    v3627[v3751] = 0;
    int * v3629 = v3477->cache_age;
    v3629[v3751] = 1;
    int * v3631 = v3477->cache_age;
    int v3632 = v3631[v3751];
    int v3633 = v3631[v3655];
    int v3781 = v3633 + ((int)((unsigned int)(v3633 - v3632) >> 31));
    v3631[v3655] = v3781;
    int * v3635 = v3477->cache_age;
    int v3636 = v3635[v3656];
    int v3783 = v3636 + ((int)((unsigned int)(v3636 - v3632) >> 31));
    v3635[v3656] = v3783;
    int * v3638 = v3477->cache_age;
    v3638[v3751] = 0;
    v3641 = v3751;
  }
  int * v3642 = v3477->cache_vals;
  int v3786 = (v3641 * 2) + (((int)((unsigned int)(v3481 + 48) >> 2)) & 1);
  v3642[v3786] = v3482;
  int * v3644 = v3477->cache_dirty;
  v3644[v3641] = 1;
  struct StateT * v3646 = slot_13(v3477);
  return v3646;
}

struct StateT * slot_228(struct StateT * v11024) {
  int v11025 = v11024->timer;
  int v11031 = v11025 + 1;
  v11024->timer = v11031;
  int * v11027 = v11024->regs;
  v11027[7] = 2036477952;
  struct StateT * v11029 = slot_229(v11024);
  return v11029;
}

struct StateT * slot_143(struct StateT * v20965) {
  int v20966 = v20965->timer;
  int v20974 = v20966 + 1;
  v20965->timer = v20974;
  int * v20968 = v20965->regs;
  int v20969 = v20968[16];
  int v20970 = v20968[5];
  int v20978 = v20969 | v20970;
  v20968[16] = v20978;
  struct StateT * v20972 = slot_144(v20965);
  return v20972;
}

struct StateT * slot_120(struct StateT * v20607) {
  int v20608 = v20607->timer;
  int v20616 = v20608 + 1;
  v20607->timer = v20616;
  int * v20610 = v20607->regs;
  int v20611 = v20610[16];
  int v20612 = v20610[6];
  int v20620 = v20611 | v20612;
  v20610[16] = v20620;
  struct StateT * v20614 = slot_121(v20607);
  return v20614;
}

struct StateT * slot_226(struct StateT * v10775) {
  int v10776 = v10775->timer;
  int v10886 = v10776 + 1;
  v10775->timer = v10886;
  int * v10778 = v10775->regs;
  int v10779 = v10778[2];
  int * v10780 = v10775->cache_tags;
  int v10890 = (((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2;
  int v10781 = v10780[v10890];
  int v10891 = ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10782 = v10780[v10891];
  int v10892 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2);
  int v10783 = v10780[v10892];
  int v10893 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10784 = v10780[v10893];
  int v10785 = v10775->timer;
  int v10894 = v10785 + ((100 ^ (((~(((v10783 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10783 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10781 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10781 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10782 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10782 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10783 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10783 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10775->timer = v10894;
  int * v10787 = v10775->cache_vals;
  bool v10895 = !(((~(((v10781 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10781 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10782 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10782 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v10880;
  if (v10895) {
    int * v10788 = v10775->cache_age;
    int v10897 = ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v10782 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10782 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v10789 = v10788[v10897];
    int v10790 = v10788[v10890];
    int v10898 = v10790 + ((int)((unsigned int)(v10790 - v10789) >> 31));
    v10788[v10890] = v10898;
    int * v10792 = v10775->cache_age;
    int v10793 = v10792[v10891];
    int v10900 = v10793 + ((int)((unsigned int)(v10793 - v10789) >> 31));
    v10792[v10891] = v10900;
    int * v10795 = v10775->cache_age;
    v10795[v10897] = 0;
    v10880 = v10897;
  } else {
    int * v10798 = v10775->cache_age;
    int v10904 = (((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2;
    int v10799 = v10798[v10904];
    int * v10800 = v10775->cache_tags;
    int v10801 = v10800[v10904];
    int v10802 = v10798[v10891];
    int v10803 = v10800[v10891];
    bool v10906 = !(((~(((v10783 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10783 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v10857;
    if (v10906) {
      int * v10804 = v10775->cache_age;
      int v10908 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))) | (-(v10784 ^ ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v10805 = v10804[v10908];
      int v10806 = v10804[v10892];
      int v10909 = v10806 + ((int)((unsigned int)(v10806 - v10805) >> 31));
      v10804[v10892] = v10909;
      int * v10808 = v10775->cache_age;
      int v10809 = v10808[v10893];
      int v10911 = v10809 + ((int)((unsigned int)(v10809 - v10805) >> 31));
      v10808[v10893] = v10911;
      int * v10811 = v10775->cache_age;
      v10811[v10908] = 0;
      v10857 = v10908;
    } else {
      int * v10814 = v10775->cache_age;
      int v10915 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2);
      int v10815 = v10814[v10915];
      int * v10816 = v10775->cache_tags;
      int v10817 = v10816[v10915];
      int v10818 = v10814[v10893];
      int v10819 = v10816[v10893];
      int * v10820 = v10775->cache_dirty;
      int v10918 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10815 + ((~(((v10817 ^ -1) | (-(v10817 ^ -1))) >> 31)) & 2)) - (v10818 + ((~(((v10819 ^ -1) | (-(v10819 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10821 = v10820[v10918];
      bool v10919 = !(v10821 == 0);
      if (v10919) {
        int * v10822 = v10775->cache_tags;
        int v10823 = v10822[v10918];
        int * v10824 = v10775->cache_vals;
        int v10922 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10815 + ((~(((v10817 ^ -1) | (-(v10817 ^ -1))) >> 31)) & 2)) - (v10818 + ((~(((v10819 ^ -1) | (-(v10819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10825 = v10824[v10922];
        int v10923 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10815 + ((~(((v10817 ^ -1) | (-(v10817 ^ -1))) >> 31)) & 2)) - (v10818 + ((~(((v10819 ^ -1) | (-(v10819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10826 = v10824[v10923];
        int * v10827 = v10775->mem;
        int v10925 = v10823 * 2;
        v10827[v10925] = v10825;
        int * v10829 = v10775->mem;
        int v10928 = (v10823 * 2) + 1;
        v10829[v10928] = v10826;
        ;
      } else {
        ;
      }
      int * v10834 = v10775->mem;
      int v10933 = ((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) * 2;
      int v10835 = v10834[v10933];
      int v10934 = (((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) * 2) + 1;
      int v10836 = v10834[v10934];
      int * v10837 = v10775->cache_vals;
      int v10936 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10815 + ((~(((v10817 ^ -1) | (-(v10817 ^ -1))) >> 31)) & 2)) - (v10818 + ((~(((v10819 ^ -1) | (-(v10819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10837[v10936] = v10835;
      int * v10839 = v10775->cache_vals;
      int v10939 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v10815 + ((~(((v10817 ^ -1) | (-(v10817 ^ -1))) >> 31)) & 2)) - (v10818 + ((~(((v10819 ^ -1) | (-(v10819 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10839[v10939] = v10836;
      int * v10841 = v10775->cache_tags;
      int v10942 = (int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1);
      v10841[v10918] = v10942;
      int * v10843 = v10775->cache_dirty;
      v10843[v10918] = 0;
      int * v10845 = v10775->cache_age;
      v10845[v10918] = 1;
      int * v10847 = v10775->cache_age;
      int v10848 = v10847[v10918];
      int v10849 = v10847[v10892];
      int v10948 = v10849 + ((int)((unsigned int)(v10849 - v10848) >> 31));
      v10847[v10892] = v10948;
      int * v10851 = v10775->cache_age;
      int v10852 = v10851[v10893];
      int v10950 = v10852 + ((int)((unsigned int)(v10852 - v10848) >> 31));
      v10851[v10893] = v10950;
      int * v10854 = v10775->cache_age;
      v10854[v10918] = 0;
      v10857 = v10918;
    }
    int * v10858 = v10775->cache_vals;
    int v10953 = v10857 * 2;
    int v10859 = v10858[v10953];
    int v10954 = (v10857 * 2) + 1;
    int v10860 = v10858[v10954];
    int v10955 = (((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10799 + ((~(((v10801 ^ -1) | (-(v10801 ^ -1))) >> 31)) & 2)) - (v10802 + ((~(((v10803 ^ -1) | (-(v10803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10858[v10955] = v10859;
    int * v10862 = v10775->cache_vals;
    int v10958 = ((((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10799 + ((~(((v10801 ^ -1) | (-(v10801 ^ -1))) >> 31)) & 2)) - (v10802 + ((~(((v10803 ^ -1) | (-(v10803 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10862[v10958] = v10860;
    int * v10864 = v10775->cache_tags;
    int v10961 = ((((int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10799 + ((~(((v10801 ^ -1) | (-(v10801 ^ -1))) >> 31)) & 2)) - (v10802 + ((~(((v10803 ^ -1) | (-(v10803 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10962 = (int)((unsigned int)((int)((unsigned int)(v10779 + 24) >> 2)) >> 1);
    v10864[v10961] = v10962;
    int * v10866 = v10775->cache_dirty;
    v10866[v10961] = 0;
    int * v10868 = v10775->cache_age;
    v10868[v10961] = 1;
    int * v10870 = v10775->cache_age;
    int v10871 = v10870[v10961];
    int v10872 = v10870[v10890];
    int v10968 = v10872 + ((int)((unsigned int)(v10872 - v10871) >> 31));
    v10870[v10890] = v10968;
    int * v10874 = v10775->cache_age;
    int v10875 = v10874[v10891];
    int v10970 = v10875 + ((int)((unsigned int)(v10875 - v10871) >> 31));
    v10874[v10891] = v10970;
    int * v10877 = v10775->cache_age;
    v10877[v10961] = 0;
    v10880 = v10961;
  }
  int v10973 = (v10880 * 2) + (((int)((unsigned int)(v10779 + 24) >> 2)) & 1);
  int v10881 = v10787[v10973];
  int * v10882 = v10775->regs;
  v10882[7] = v10881;
  struct StateT * v10884 = slot_227(v10775);
  return v10884;
}

struct StateT * slot_167(struct StateT * v21342) {
  int v21343 = v21342->timer;
  int v21351 = v21343 + 1;
  v21342->timer = v21351;
  int * v21345 = v21342->regs;
  int v21346 = v21345[27];
  int v21347 = v21345[11];
  int v21355 = v21346 ^ v21347;
  v21345[27] = v21355;
  struct StateT * v21349 = slot_168(v21342);
  return v21349;
}

struct StateT * slot_268(struct StateT * v18934) {
  int v18935 = v18934->timer;
  int v19045 = v18935 + 1;
  v18934->timer = v19045;
  int * v18937 = v18934->regs;
  int v18938 = v18937[2];
  int * v18939 = v18934->cache_tags;
  int v19049 = (((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2;
  int v18940 = v18939[v19049];
  int v19050 = ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18941 = v18939[v19050];
  int v19051 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2);
  int v18942 = v18939[v19051];
  int v19052 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18943 = v18939[v19052];
  int v18944 = v18934->timer;
  int v19053 = v18944 + ((100 ^ (((~(((v18942 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18942 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18940 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18940 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v18941 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18941 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18942 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18942 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18934->timer = v19053;
  int * v18946 = v18934->cache_vals;
  bool v19054 = !(((~(((v18940 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18940 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v18941 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18941 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v19039;
  if (v19054) {
    int * v18947 = v18934->cache_age;
    int v19056 = ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v18941 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18941 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v18948 = v18947[v19056];
    int v18949 = v18947[v19049];
    int v19057 = v18949 + ((int)((unsigned int)(v18949 - v18948) >> 31));
    v18947[v19049] = v19057;
    int * v18951 = v18934->cache_age;
    int v18952 = v18951[v19050];
    int v19059 = v18952 + ((int)((unsigned int)(v18952 - v18948) >> 31));
    v18951[v19050] = v19059;
    int * v18954 = v18934->cache_age;
    v18954[v19056] = 0;
    v19039 = v19056;
  } else {
    int * v18957 = v18934->cache_age;
    int v19063 = (((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2;
    int v18958 = v18957[v19063];
    int * v18959 = v18934->cache_tags;
    int v18960 = v18959[v19063];
    int v18961 = v18957[v19050];
    int v18962 = v18959[v19050];
    bool v19065 = !(((~(((v18942 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18942 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v19016;
    if (v19065) {
      int * v18963 = v18934->cache_age;
      int v19067 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))) | (-(v18943 ^ ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v18964 = v18963[v19067];
      int v18965 = v18963[v19051];
      int v19068 = v18965 + ((int)((unsigned int)(v18965 - v18964) >> 31));
      v18963[v19051] = v19068;
      int * v18967 = v18934->cache_age;
      int v18968 = v18967[v19052];
      int v19070 = v18968 + ((int)((unsigned int)(v18968 - v18964) >> 31));
      v18967[v19052] = v19070;
      int * v18970 = v18934->cache_age;
      v18970[v19067] = 0;
      v19016 = v19067;
    } else {
      int * v18973 = v18934->cache_age;
      int v19074 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2);
      int v18974 = v18973[v19074];
      int * v18975 = v18934->cache_tags;
      int v18976 = v18975[v19074];
      int v18977 = v18973[v19052];
      int v18978 = v18975[v19052];
      int * v18979 = v18934->cache_dirty;
      int v19077 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v18974 + ((~(((v18976 ^ -1) | (-(v18976 ^ -1))) >> 31)) & 2)) - (v18977 + ((~(((v18978 ^ -1) | (-(v18978 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18980 = v18979[v19077];
      bool v19078 = !(v18980 == 0);
      if (v19078) {
        int * v18981 = v18934->cache_tags;
        int v18982 = v18981[v19077];
        int * v18983 = v18934->cache_vals;
        int v19081 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v18974 + ((~(((v18976 ^ -1) | (-(v18976 ^ -1))) >> 31)) & 2)) - (v18977 + ((~(((v18978 ^ -1) | (-(v18978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18984 = v18983[v19081];
        int v19082 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v18974 + ((~(((v18976 ^ -1) | (-(v18976 ^ -1))) >> 31)) & 2)) - (v18977 + ((~(((v18978 ^ -1) | (-(v18978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18985 = v18983[v19082];
        int * v18986 = v18934->mem;
        int v19084 = v18982 * 2;
        v18986[v19084] = v18984;
        int * v18988 = v18934->mem;
        int v19087 = (v18982 * 2) + 1;
        v18988[v19087] = v18985;
        ;
      } else {
        ;
      }
      int * v18993 = v18934->mem;
      int v19092 = ((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) * 2;
      int v18994 = v18993[v19092];
      int v19093 = (((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) * 2) + 1;
      int v18995 = v18993[v19093];
      int * v18996 = v18934->cache_vals;
      int v19095 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v18974 + ((~(((v18976 ^ -1) | (-(v18976 ^ -1))) >> 31)) & 2)) - (v18977 + ((~(((v18978 ^ -1) | (-(v18978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18996[v19095] = v18994;
      int * v18998 = v18934->cache_vals;
      int v19098 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v18974 + ((~(((v18976 ^ -1) | (-(v18976 ^ -1))) >> 31)) & 2)) - (v18977 + ((~(((v18978 ^ -1) | (-(v18978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18998[v19098] = v18995;
      int * v19000 = v18934->cache_tags;
      int v19101 = (int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1);
      v19000[v19077] = v19101;
      int * v19002 = v18934->cache_dirty;
      v19002[v19077] = 0;
      int * v19004 = v18934->cache_age;
      v19004[v19077] = 1;
      int * v19006 = v18934->cache_age;
      int v19007 = v19006[v19077];
      int v19008 = v19006[v19051];
      int v19107 = v19008 + ((int)((unsigned int)(v19008 - v19007) >> 31));
      v19006[v19051] = v19107;
      int * v19010 = v18934->cache_age;
      int v19011 = v19010[v19052];
      int v19109 = v19011 + ((int)((unsigned int)(v19011 - v19007) >> 31));
      v19010[v19052] = v19109;
      int * v19013 = v18934->cache_age;
      v19013[v19077] = 0;
      v19016 = v19077;
    }
    int * v19017 = v18934->cache_vals;
    int v19112 = v19016 * 2;
    int v19018 = v19017[v19112];
    int v19113 = (v19016 * 2) + 1;
    int v19019 = v19017[v19113];
    int v19114 = (((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v18958 + ((~(((v18960 ^ -1) | (-(v18960 ^ -1))) >> 31)) & 2)) - (v18961 + ((~(((v18962 ^ -1) | (-(v18962 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19017[v19114] = v19018;
    int * v19021 = v18934->cache_vals;
    int v19117 = ((((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v18958 + ((~(((v18960 ^ -1) | (-(v18960 ^ -1))) >> 31)) & 2)) - (v18961 + ((~(((v18962 ^ -1) | (-(v18962 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19021[v19117] = v19019;
    int * v19023 = v18934->cache_tags;
    int v19120 = ((((int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v18958 + ((~(((v18960 ^ -1) | (-(v18960 ^ -1))) >> 31)) & 2)) - (v18961 + ((~(((v18962 ^ -1) | (-(v18962 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19121 = (int)((unsigned int)((int)((unsigned int)(v18938 + 68) >> 2)) >> 1);
    v19023[v19120] = v19121;
    int * v19025 = v18934->cache_dirty;
    v19025[v19120] = 0;
    int * v19027 = v18934->cache_age;
    v19027[v19120] = 1;
    int * v19029 = v18934->cache_age;
    int v19030 = v19029[v19120];
    int v19031 = v19029[v19049];
    int v19127 = v19031 + ((int)((unsigned int)(v19031 - v19030) >> 31));
    v19029[v19049] = v19127;
    int * v19033 = v18934->cache_age;
    int v19034 = v19033[v19050];
    int v19129 = v19034 + ((int)((unsigned int)(v19034 - v19030) >> 31));
    v19033[v19050] = v19129;
    int * v19036 = v18934->cache_age;
    v19036[v19120] = 0;
    v19039 = v19120;
  }
  int v19132 = (v19039 * 2) + (((int)((unsigned int)(v18938 + 68) >> 2)) & 1);
  int v19040 = v18946[v19132];
  int * v19041 = v18934->regs;
  v19041[21] = v19040;
  struct StateT * v19043 = slot_269(v18934);
  return v19043;
}

struct StateT * slot_152(struct StateT * v21111) {
  int v21112 = v21111->timer;
  int v21120 = v21112 + 1;
  v21111->timer = v21120;
  int * v21114 = v21111->regs;
  int v21115 = v21114[5];
  int v21116 = v21114[20];
  int v21125 = v21115 + v21116;
  v21114[15] = v21125;
  struct StateT * v21118 = slot_153(v21111);
  return v21118;
}

struct StateT * slot_231(struct StateT * v11305) {
  int v11306 = v11305->timer;
  int v11416 = v11306 + 1;
  v11305->timer = v11416;
  int * v11308 = v11305->regs;
  int v11309 = v11308[2];
  int * v11310 = v11305->cache_tags;
  int v11420 = (((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2;
  int v11311 = v11310[v11420];
  int v11421 = ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11312 = v11310[v11421];
  int v11422 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2);
  int v11313 = v11310[v11422];
  int v11423 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11314 = v11310[v11423];
  int v11315 = v11305->timer;
  int v11424 = v11315 + ((100 ^ (((~(((v11313 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11313 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11311 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11311 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11312 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11312 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11313 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11313 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11305->timer = v11424;
  int * v11317 = v11305->cache_vals;
  bool v11425 = !(((~(((v11311 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11311 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11312 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11312 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v11410;
  if (v11425) {
    int * v11318 = v11305->cache_age;
    int v11427 = ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v11312 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11312 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v11319 = v11318[v11427];
    int v11320 = v11318[v11420];
    int v11428 = v11320 + ((int)((unsigned int)(v11320 - v11319) >> 31));
    v11318[v11420] = v11428;
    int * v11322 = v11305->cache_age;
    int v11323 = v11322[v11421];
    int v11430 = v11323 + ((int)((unsigned int)(v11323 - v11319) >> 31));
    v11322[v11421] = v11430;
    int * v11325 = v11305->cache_age;
    v11325[v11427] = 0;
    v11410 = v11427;
  } else {
    int * v11328 = v11305->cache_age;
    int v11434 = (((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2;
    int v11329 = v11328[v11434];
    int * v11330 = v11305->cache_tags;
    int v11331 = v11330[v11434];
    int v11332 = v11328[v11421];
    int v11333 = v11330[v11421];
    bool v11436 = !(((~(((v11313 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11313 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v11387;
    if (v11436) {
      int * v11334 = v11305->cache_age;
      int v11438 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))) | (-(v11314 ^ ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v11335 = v11334[v11438];
      int v11336 = v11334[v11422];
      int v11439 = v11336 + ((int)((unsigned int)(v11336 - v11335) >> 31));
      v11334[v11422] = v11439;
      int * v11338 = v11305->cache_age;
      int v11339 = v11338[v11423];
      int v11441 = v11339 + ((int)((unsigned int)(v11339 - v11335) >> 31));
      v11338[v11423] = v11441;
      int * v11341 = v11305->cache_age;
      v11341[v11438] = 0;
      v11387 = v11438;
    } else {
      int * v11344 = v11305->cache_age;
      int v11445 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2);
      int v11345 = v11344[v11445];
      int * v11346 = v11305->cache_tags;
      int v11347 = v11346[v11445];
      int v11348 = v11344[v11423];
      int v11349 = v11346[v11423];
      int * v11350 = v11305->cache_dirty;
      int v11448 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11345 + ((~(((v11347 ^ -1) | (-(v11347 ^ -1))) >> 31)) & 2)) - (v11348 + ((~(((v11349 ^ -1) | (-(v11349 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11351 = v11350[v11448];
      bool v11449 = !(v11351 == 0);
      if (v11449) {
        int * v11352 = v11305->cache_tags;
        int v11353 = v11352[v11448];
        int * v11354 = v11305->cache_vals;
        int v11452 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11345 + ((~(((v11347 ^ -1) | (-(v11347 ^ -1))) >> 31)) & 2)) - (v11348 + ((~(((v11349 ^ -1) | (-(v11349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11355 = v11354[v11452];
        int v11453 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11345 + ((~(((v11347 ^ -1) | (-(v11347 ^ -1))) >> 31)) & 2)) - (v11348 + ((~(((v11349 ^ -1) | (-(v11349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11356 = v11354[v11453];
        int * v11357 = v11305->mem;
        int v11455 = v11353 * 2;
        v11357[v11455] = v11355;
        int * v11359 = v11305->mem;
        int v11458 = (v11353 * 2) + 1;
        v11359[v11458] = v11356;
        ;
      } else {
        ;
      }
      int * v11364 = v11305->mem;
      int v11463 = ((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) * 2;
      int v11365 = v11364[v11463];
      int v11464 = (((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) * 2) + 1;
      int v11366 = v11364[v11464];
      int * v11367 = v11305->cache_vals;
      int v11466 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11345 + ((~(((v11347 ^ -1) | (-(v11347 ^ -1))) >> 31)) & 2)) - (v11348 + ((~(((v11349 ^ -1) | (-(v11349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11367[v11466] = v11365;
      int * v11369 = v11305->cache_vals;
      int v11469 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11345 + ((~(((v11347 ^ -1) | (-(v11347 ^ -1))) >> 31)) & 2)) - (v11348 + ((~(((v11349 ^ -1) | (-(v11349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11369[v11469] = v11366;
      int * v11371 = v11305->cache_tags;
      int v11472 = (int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1);
      v11371[v11448] = v11472;
      int * v11373 = v11305->cache_dirty;
      v11373[v11448] = 0;
      int * v11375 = v11305->cache_age;
      v11375[v11448] = 1;
      int * v11377 = v11305->cache_age;
      int v11378 = v11377[v11448];
      int v11379 = v11377[v11422];
      int v11478 = v11379 + ((int)((unsigned int)(v11379 - v11378) >> 31));
      v11377[v11422] = v11478;
      int * v11381 = v11305->cache_age;
      int v11382 = v11381[v11423];
      int v11480 = v11382 + ((int)((unsigned int)(v11382 - v11378) >> 31));
      v11381[v11423] = v11480;
      int * v11384 = v11305->cache_age;
      v11384[v11448] = 0;
      v11387 = v11448;
    }
    int * v11388 = v11305->cache_vals;
    int v11483 = v11387 * 2;
    int v11389 = v11388[v11483];
    int v11484 = (v11387 * 2) + 1;
    int v11390 = v11388[v11484];
    int v11485 = (((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11329 + ((~(((v11331 ^ -1) | (-(v11331 ^ -1))) >> 31)) & 2)) - (v11332 + ((~(((v11333 ^ -1) | (-(v11333 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11388[v11485] = v11389;
    int * v11392 = v11305->cache_vals;
    int v11488 = ((((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11329 + ((~(((v11331 ^ -1) | (-(v11331 ^ -1))) >> 31)) & 2)) - (v11332 + ((~(((v11333 ^ -1) | (-(v11333 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11392[v11488] = v11390;
    int * v11394 = v11305->cache_tags;
    int v11491 = ((((int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11329 + ((~(((v11331 ^ -1) | (-(v11331 ^ -1))) >> 31)) & 2)) - (v11332 + ((~(((v11333 ^ -1) | (-(v11333 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11492 = (int)((unsigned int)((int)((unsigned int)(v11309 + 32) >> 2)) >> 1);
    v11394[v11491] = v11492;
    int * v11396 = v11305->cache_dirty;
    v11396[v11491] = 0;
    int * v11398 = v11305->cache_age;
    v11398[v11491] = 1;
    int * v11400 = v11305->cache_age;
    int v11401 = v11400[v11491];
    int v11402 = v11400[v11420];
    int v11498 = v11402 + ((int)((unsigned int)(v11402 - v11401) >> 31));
    v11400[v11420] = v11498;
    int * v11404 = v11305->cache_age;
    int v11405 = v11404[v11421];
    int v11500 = v11405 + ((int)((unsigned int)(v11405 - v11401) >> 31));
    v11404[v11421] = v11500;
    int * v11407 = v11305->cache_age;
    v11407[v11491] = 0;
    v11410 = v11491;
  }
  int v11503 = (v11410 * 2) + (((int)((unsigned int)(v11309 + 32) >> 2)) & 1);
  int v11411 = v11317[v11503];
  int * v11412 = v11305->regs;
  v11412[30] = v11411;
  struct StateT * v11414 = slot_232(v11305);
  return v11414;
}

struct StateT * slot_199(struct StateT * v21846) {
  int v21847 = v21846->timer;
  int v21854 = v21847 + 1;
  v21846->timer = v21854;
  int * v21849 = v21846->regs;
  int v21850 = v21849[15];
  int v21857 = v21850 << 18;
  v21849[15] = v21857;
  struct StateT * v21852 = slot_200(v21846);
  return v21852;
}

struct StateT * slot_252(struct StateT * v14316) {
  int v14317 = v14316->timer;
  int v14487 = v14317 + 1;
  v14316->timer = v14487;
  int * v14319 = v14316->regs;
  int v14320 = v14319[10];
  int v14321 = v14319[5];
  int * v14322 = v14316->cache_tags;
  int v14492 = (((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2;
  int v14323 = v14322[v14492];
  int v14493 = ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14324 = v14322[v14493];
  int v14494 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2);
  int v14325 = v14322[v14494];
  int v14495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14326 = v14322[v14495];
  int v14327 = v14316->timer;
  int v14496 = v14327 + ((100 ^ (((~(((v14325 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14325 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14323 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14323 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14324 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14324 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14325 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14325 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14316->timer = v14496;
  bool v14497 = !(((~(((v14323 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14323 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14324 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14324 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v14421;
  if (v14497) {
    int * v14329 = v14316->cache_age;
    int v14499 = ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v14324 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14324 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v14330 = v14329[v14499];
    int v14331 = v14329[v14492];
    int v14500 = v14331 + ((int)((unsigned int)(v14331 - v14330) >> 31));
    v14329[v14492] = v14500;
    int * v14333 = v14316->cache_age;
    int v14334 = v14333[v14493];
    int v14502 = v14334 + ((int)((unsigned int)(v14334 - v14330) >> 31));
    v14333[v14493] = v14502;
    int * v14336 = v14316->cache_age;
    v14336[v14499] = 0;
    v14421 = v14499;
  } else {
    int * v14339 = v14316->cache_age;
    int v14506 = (((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2;
    int v14340 = v14339[v14506];
    int * v14341 = v14316->cache_tags;
    int v14342 = v14341[v14506];
    int v14343 = v14339[v14493];
    int v14344 = v14341[v14493];
    bool v14508 = !(((~(((v14325 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14325 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v14398;
    if (v14508) {
      int * v14345 = v14316->cache_age;
      int v14510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14326 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v14346 = v14345[v14510];
      int v14347 = v14345[v14494];
      int v14511 = v14347 + ((int)((unsigned int)(v14347 - v14346) >> 31));
      v14345[v14494] = v14511;
      int * v14349 = v14316->cache_age;
      int v14350 = v14349[v14495];
      int v14513 = v14350 + ((int)((unsigned int)(v14350 - v14346) >> 31));
      v14349[v14495] = v14513;
      int * v14352 = v14316->cache_age;
      v14352[v14510] = 0;
      v14398 = v14510;
    } else {
      int * v14355 = v14316->cache_age;
      int v14517 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2);
      int v14356 = v14355[v14517];
      int * v14357 = v14316->cache_tags;
      int v14358 = v14357[v14517];
      int v14359 = v14355[v14495];
      int v14360 = v14357[v14495];
      int * v14361 = v14316->cache_dirty;
      int v14520 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14362 = v14361[v14520];
      bool v14521 = !(v14362 == 0);
      if (v14521) {
        int * v14363 = v14316->cache_tags;
        int v14364 = v14363[v14520];
        int * v14365 = v14316->cache_vals;
        int v14524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14366 = v14365[v14524];
        int v14525 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14367 = v14365[v14525];
        int * v14368 = v14316->mem;
        int v14527 = v14364 * 2;
        v14368[v14527] = v14366;
        int * v14370 = v14316->mem;
        int v14530 = (v14364 * 2) + 1;
        v14370[v14530] = v14367;
        ;
      } else {
        ;
      }
      int * v14375 = v14316->mem;
      int v14535 = ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) * 2;
      int v14376 = v14375[v14535];
      int v14536 = (((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) * 2) + 1;
      int v14377 = v14375[v14536];
      int * v14378 = v14316->cache_vals;
      int v14538 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14378[v14538] = v14376;
      int * v14380 = v14316->cache_vals;
      int v14541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14380[v14541] = v14377;
      int * v14382 = v14316->cache_tags;
      int v14544 = (int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1);
      v14382[v14520] = v14544;
      int * v14384 = v14316->cache_dirty;
      v14384[v14520] = 0;
      int * v14386 = v14316->cache_age;
      v14386[v14520] = 1;
      int * v14388 = v14316->cache_age;
      int v14389 = v14388[v14520];
      int v14390 = v14388[v14494];
      int v14550 = v14390 + ((int)((unsigned int)(v14390 - v14389) >> 31));
      v14388[v14494] = v14550;
      int * v14392 = v14316->cache_age;
      int v14393 = v14392[v14495];
      int v14552 = v14393 + ((int)((unsigned int)(v14393 - v14389) >> 31));
      v14392[v14495] = v14552;
      int * v14395 = v14316->cache_age;
      v14395[v14520] = 0;
      v14398 = v14520;
    }
    int * v14399 = v14316->cache_vals;
    int v14555 = v14398 * 2;
    int v14400 = v14399[v14555];
    int v14556 = (v14398 * 2) + 1;
    int v14401 = v14399[v14556];
    int v14557 = (((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14340 + ((~(((v14342 ^ -1) | (-(v14342 ^ -1))) >> 31)) & 2)) - (v14343 + ((~(((v14344 ^ -1) | (-(v14344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14399[v14557] = v14400;
    int * v14403 = v14316->cache_vals;
    int v14560 = ((((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14340 + ((~(((v14342 ^ -1) | (-(v14342 ^ -1))) >> 31)) & 2)) - (v14343 + ((~(((v14344 ^ -1) | (-(v14344 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14403[v14560] = v14401;
    int * v14405 = v14316->cache_tags;
    int v14563 = ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14340 + ((~(((v14342 ^ -1) | (-(v14342 ^ -1))) >> 31)) & 2)) - (v14343 + ((~(((v14344 ^ -1) | (-(v14344 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14564 = (int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1);
    v14405[v14563] = v14564;
    int * v14407 = v14316->cache_dirty;
    v14407[v14563] = 0;
    int * v14409 = v14316->cache_age;
    v14409[v14563] = 1;
    int * v14411 = v14316->cache_age;
    int v14412 = v14411[v14563];
    int v14413 = v14411[v14492];
    int v14570 = v14413 + ((int)((unsigned int)(v14413 - v14412) >> 31));
    v14411[v14492] = v14570;
    int * v14415 = v14316->cache_age;
    int v14416 = v14415[v14493];
    int v14572 = v14416 + ((int)((unsigned int)(v14416 - v14412) >> 31));
    v14415[v14493] = v14572;
    int * v14418 = v14316->cache_age;
    v14418[v14563] = 0;
    v14421 = v14563;
  }
  int * v14422 = v14316->cache_vals;
  int v14575 = (v14421 * 2) + (((int)((unsigned int)(v14320 + 24) >> 2)) & 1);
  v14422[v14575] = v14321;
  int * v14424 = v14316->cache_tags;
  int v14425 = v14424[v14494];
  int v14426 = v14424[v14495];
  bool v14578 = !(((~(((v14425 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14425 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14426 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14426 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v14480;
  if (v14578) {
    int * v14427 = v14316->cache_age;
    int v14580 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14426 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))) | (-(v14426 ^ ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v14428 = v14427[v14580];
    int v14429 = v14427[v14494];
    int v14581 = v14429 + ((int)((unsigned int)(v14429 - v14428) >> 31));
    v14427[v14494] = v14581;
    int * v14431 = v14316->cache_age;
    int v14432 = v14431[v14495];
    int v14583 = v14432 + ((int)((unsigned int)(v14432 - v14428) >> 31));
    v14431[v14495] = v14583;
    int * v14434 = v14316->cache_age;
    v14434[v14580] = 0;
    v14480 = v14580;
  } else {
    int * v14437 = v14316->cache_age;
    int v14587 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2);
    int v14438 = v14437[v14587];
    int * v14439 = v14316->cache_tags;
    int v14440 = v14439[v14587];
    int v14441 = v14437[v14495];
    int v14442 = v14439[v14495];
    int * v14443 = v14316->cache_dirty;
    int v14590 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14438 + ((~(((v14440 ^ -1) | (-(v14440 ^ -1))) >> 31)) & 2)) - (v14441 + ((~(((v14442 ^ -1) | (-(v14442 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14444 = v14443[v14590];
    bool v14591 = !(v14444 == 0);
    if (v14591) {
      int * v14445 = v14316->cache_tags;
      int v14446 = v14445[v14590];
      int * v14447 = v14316->cache_vals;
      int v14594 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14438 + ((~(((v14440 ^ -1) | (-(v14440 ^ -1))) >> 31)) & 2)) - (v14441 + ((~(((v14442 ^ -1) | (-(v14442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v14448 = v14447[v14594];
      int v14595 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14438 + ((~(((v14440 ^ -1) | (-(v14440 ^ -1))) >> 31)) & 2)) - (v14441 + ((~(((v14442 ^ -1) | (-(v14442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v14449 = v14447[v14595];
      int * v14450 = v14316->mem;
      int v14597 = v14446 * 2;
      v14450[v14597] = v14448;
      int * v14452 = v14316->mem;
      int v14600 = (v14446 * 2) + 1;
      v14452[v14600] = v14449;
      ;
    } else {
      ;
    }
    int * v14457 = v14316->mem;
    int v14605 = ((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) * 2;
    int v14458 = v14457[v14605];
    int v14606 = (((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) * 2) + 1;
    int v14459 = v14457[v14606];
    int * v14460 = v14316->cache_vals;
    int v14608 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14438 + ((~(((v14440 ^ -1) | (-(v14440 ^ -1))) >> 31)) & 2)) - (v14441 + ((~(((v14442 ^ -1) | (-(v14442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14460[v14608] = v14458;
    int * v14462 = v14316->cache_vals;
    int v14611 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14438 + ((~(((v14440 ^ -1) | (-(v14440 ^ -1))) >> 31)) & 2)) - (v14441 + ((~(((v14442 ^ -1) | (-(v14442 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14462[v14611] = v14459;
    int * v14464 = v14316->cache_tags;
    int v14614 = (int)((unsigned int)((int)((unsigned int)(v14320 + 24) >> 2)) >> 1);
    v14464[v14590] = v14614;
    int * v14466 = v14316->cache_dirty;
    v14466[v14590] = 0;
    int * v14468 = v14316->cache_age;
    v14468[v14590] = 1;
    int * v14470 = v14316->cache_age;
    int v14471 = v14470[v14590];
    int v14472 = v14470[v14494];
    int v14620 = v14472 + ((int)((unsigned int)(v14472 - v14471) >> 31));
    v14470[v14494] = v14620;
    int * v14474 = v14316->cache_age;
    int v14475 = v14474[v14495];
    int v14622 = v14475 + ((int)((unsigned int)(v14475 - v14471) >> 31));
    v14474[v14495] = v14622;
    int * v14477 = v14316->cache_age;
    v14477[v14590] = 0;
    v14480 = v14590;
  }
  int * v14481 = v14316->cache_vals;
  int v14625 = (v14480 * 2) + (((int)((unsigned int)(v14320 + 24) >> 2)) & 1);
  v14481[v14625] = v14321;
  int * v14483 = v14316->cache_dirty;
  v14483[v14480] = 1;
  struct StateT * v14485 = slot_253(v14316);
  return v14485;
}

struct StateT * slot_92(struct StateT * v15294) {
  int v15295 = v15294->timer;
  int v15303 = v15295 + 1;
  v15294->timer = v15303;
  int * v15297 = v15294->regs;
  int v15298 = v15297[24];
  int v15299 = v15297[13];
  int v15308 = v15298 + v15299;
  v15297[8] = v15308;
  struct StateT * v15301 = slot_93(v15294);
  return v15301;
}

struct StateT * slot_232(struct StateT * v11525) {
  int v11526 = v11525->timer;
  int v11534 = v11526 + 1;
  v11525->timer = v11534;
  int * v11528 = v11525->regs;
  int v11529 = v11528[16];
  int v11530 = v11528[30];
  int v11538 = v11529 + v11530;
  v11528[16] = v11538;
  struct StateT * v11532 = slot_233(v11525);
  return v11532;
}

struct StateT * slot_269(struct StateT * v19155) {
  int v19156 = v19155->timer;
  int v19266 = v19156 + 1;
  v19155->timer = v19266;
  int * v19158 = v19155->regs;
  int v19159 = v19158[2];
  int * v19160 = v19155->cache_tags;
  int v19270 = (((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2;
  int v19161 = v19160[v19270];
  int v19271 = ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19162 = v19160[v19271];
  int v19272 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2);
  int v19163 = v19160[v19272];
  int v19273 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19164 = v19160[v19273];
  int v19165 = v19155->timer;
  int v19274 = v19165 + ((100 ^ (((~(((v19163 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19163 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19161 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19161 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v19162 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19162 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19163 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19163 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19155->timer = v19274;
  int * v19167 = v19155->cache_vals;
  bool v19275 = !(((~(((v19161 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19161 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v19162 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19162 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31))) == 0);
  int v19260;
  if (v19275) {
    int * v19168 = v19155->cache_age;
    int v19277 = ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2) + ((~(((v19162 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19162 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) & 1);
    int v19169 = v19168[v19277];
    int v19170 = v19168[v19270];
    int v19278 = v19170 + ((int)((unsigned int)(v19170 - v19169) >> 31));
    v19168[v19270] = v19278;
    int * v19172 = v19155->cache_age;
    int v19173 = v19172[v19271];
    int v19280 = v19173 + ((int)((unsigned int)(v19173 - v19169) >> 31));
    v19172[v19271] = v19280;
    int * v19175 = v19155->cache_age;
    v19175[v19277] = 0;
    v19260 = v19277;
  } else {
    int * v19178 = v19155->cache_age;
    int v19284 = (((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2;
    int v19179 = v19178[v19284];
    int * v19180 = v19155->cache_tags;
    int v19181 = v19180[v19284];
    int v19182 = v19178[v19271];
    int v19183 = v19180[v19271];
    bool v19286 = !(((~(((v19163 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19163 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31))) == 0);
    int v19237;
    if (v19286) {
      int * v19184 = v19155->cache_age;
      int v19288 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))) | (-(v19164 ^ ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1))))) >> 31)) & 1);
      int v19185 = v19184[v19288];
      int v19186 = v19184[v19272];
      int v19289 = v19186 + ((int)((unsigned int)(v19186 - v19185) >> 31));
      v19184[v19272] = v19289;
      int * v19188 = v19155->cache_age;
      int v19189 = v19188[v19273];
      int v19291 = v19189 + ((int)((unsigned int)(v19189 - v19185) >> 31));
      v19188[v19273] = v19291;
      int * v19191 = v19155->cache_age;
      v19191[v19288] = 0;
      v19237 = v19288;
    } else {
      int * v19194 = v19155->cache_age;
      int v19295 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2);
      int v19195 = v19194[v19295];
      int * v19196 = v19155->cache_tags;
      int v19197 = v19196[v19295];
      int v19198 = v19194[v19273];
      int v19199 = v19196[v19273];
      int * v19200 = v19155->cache_dirty;
      int v19298 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v19195 + ((~(((v19197 ^ -1) | (-(v19197 ^ -1))) >> 31)) & 2)) - (v19198 + ((~(((v19199 ^ -1) | (-(v19199 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19201 = v19200[v19298];
      bool v19299 = !(v19201 == 0);
      if (v19299) {
        int * v19202 = v19155->cache_tags;
        int v19203 = v19202[v19298];
        int * v19204 = v19155->cache_vals;
        int v19302 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v19195 + ((~(((v19197 ^ -1) | (-(v19197 ^ -1))) >> 31)) & 2)) - (v19198 + ((~(((v19199 ^ -1) | (-(v19199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19205 = v19204[v19302];
        int v19303 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v19195 + ((~(((v19197 ^ -1) | (-(v19197 ^ -1))) >> 31)) & 2)) - (v19198 + ((~(((v19199 ^ -1) | (-(v19199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19206 = v19204[v19303];
        int * v19207 = v19155->mem;
        int v19305 = v19203 * 2;
        v19207[v19305] = v19205;
        int * v19209 = v19155->mem;
        int v19308 = (v19203 * 2) + 1;
        v19209[v19308] = v19206;
        ;
      } else {
        ;
      }
      int * v19214 = v19155->mem;
      int v19313 = ((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) * 2;
      int v19215 = v19214[v19313];
      int v19314 = (((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) * 2) + 1;
      int v19216 = v19214[v19314];
      int * v19217 = v19155->cache_vals;
      int v19316 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v19195 + ((~(((v19197 ^ -1) | (-(v19197 ^ -1))) >> 31)) & 2)) - (v19198 + ((~(((v19199 ^ -1) | (-(v19199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19217[v19316] = v19215;
      int * v19219 = v19155->cache_vals;
      int v19319 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v19195 + ((~(((v19197 ^ -1) | (-(v19197 ^ -1))) >> 31)) & 2)) - (v19198 + ((~(((v19199 ^ -1) | (-(v19199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19219[v19319] = v19216;
      int * v19221 = v19155->cache_tags;
      int v19322 = (int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1);
      v19221[v19298] = v19322;
      int * v19223 = v19155->cache_dirty;
      v19223[v19298] = 0;
      int * v19225 = v19155->cache_age;
      v19225[v19298] = 1;
      int * v19227 = v19155->cache_age;
      int v19228 = v19227[v19298];
      int v19229 = v19227[v19272];
      int v19328 = v19229 + ((int)((unsigned int)(v19229 - v19228) >> 31));
      v19227[v19272] = v19328;
      int * v19231 = v19155->cache_age;
      int v19232 = v19231[v19273];
      int v19330 = v19232 + ((int)((unsigned int)(v19232 - v19228) >> 31));
      v19231[v19273] = v19330;
      int * v19234 = v19155->cache_age;
      v19234[v19298] = 0;
      v19237 = v19298;
    }
    int * v19238 = v19155->cache_vals;
    int v19333 = v19237 * 2;
    int v19239 = v19238[v19333];
    int v19334 = (v19237 * 2) + 1;
    int v19240 = v19238[v19334];
    int v19335 = (((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2) + ((((v19179 + ((~(((v19181 ^ -1) | (-(v19181 ^ -1))) >> 31)) & 2)) - (v19182 + ((~(((v19183 ^ -1) | (-(v19183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19238[v19335] = v19239;
    int * v19242 = v19155->cache_vals;
    int v19338 = ((((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2) + ((((v19179 + ((~(((v19181 ^ -1) | (-(v19181 ^ -1))) >> 31)) & 2)) - (v19182 + ((~(((v19183 ^ -1) | (-(v19183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19242[v19338] = v19240;
    int * v19244 = v19155->cache_tags;
    int v19341 = ((((int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1)) & 1) * 2) + ((((v19179 + ((~(((v19181 ^ -1) | (-(v19181 ^ -1))) >> 31)) & 2)) - (v19182 + ((~(((v19183 ^ -1) | (-(v19183 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19342 = (int)((unsigned int)((int)((unsigned int)(v19159 + 64) >> 2)) >> 1);
    v19244[v19341] = v19342;
    int * v19246 = v19155->cache_dirty;
    v19246[v19341] = 0;
    int * v19248 = v19155->cache_age;
    v19248[v19341] = 1;
    int * v19250 = v19155->cache_age;
    int v19251 = v19250[v19341];
    int v19252 = v19250[v19270];
    int v19348 = v19252 + ((int)((unsigned int)(v19252 - v19251) >> 31));
    v19250[v19270] = v19348;
    int * v19254 = v19155->cache_age;
    int v19255 = v19254[v19271];
    int v19350 = v19255 + ((int)((unsigned int)(v19255 - v19251) >> 31));
    v19254[v19271] = v19350;
    int * v19257 = v19155->cache_age;
    v19257[v19341] = 0;
    v19260 = v19341;
  }
  int v19353 = (v19260 * 2) + (((int)((unsigned int)(v19159 + 64) >> 2)) & 1);
  int v19261 = v19167[v19353];
  int * v19262 = v19155->regs;
  v19262[22] = v19261;
  struct StateT * v19264 = slot_270(v19155);
  return v19264;
}

struct StateT * slot_31(struct StateT * v6622) {
  int v6623 = v6622->timer;
  int v6630 = v6623 + 1;
  v6622->timer = v6630;
  int * v6625 = v6622->regs;
  int v6626 = v6625[13];
  int v6634 = v6626 + 1134;
  v6625[11] = v6634;
  struct StateT * v6628 = slot_32(v6622);
  return v6628;
}

struct StateT * slot_236(struct StateT * v12032) {
  int v12033 = v12032->timer;
  int v12041 = v12033 + 1;
  v12032->timer = v12041;
  int * v12035 = v12032->regs;
  int v12036 = v12035[1];
  int v12037 = v12035[30];
  int v12045 = v12036 + v12037;
  v12035[1] = v12045;
  struct StateT * v12039 = slot_237(v12032);
  return v12039;
}

struct StateT * slot_241(struct StateT * v12180) {
  int v12181 = v12180->timer;
  int v12188 = v12181 + 1;
  v12180->timer = v12188;
  int * v12183 = v12180->regs;
  int v12184 = v12183[30];
  int v12191 = v12184 + 1396;
  v12183[30] = v12191;
  struct StateT * v12186 = slot_242(v12180);
  return v12186;
}

struct StateT * slot_160(struct StateT * v21236) {
  int v21237 = v21236->timer;
  int v21245 = v21237 + 1;
  v21236->timer = v21245;
  int * v21239 = v21236->regs;
  int v21240 = v21239[15];
  int v21241 = v21239[9];
  int v21249 = v21240 | v21241;
  v21239[15] = v21249;
  struct StateT * v21243 = slot_161(v21236);
  return v21243;
}

struct StateT * slot_251(struct StateT * v13985) {
  int v13986 = v13985->timer;
  int v14156 = v13986 + 1;
  v13985->timer = v14156;
  int * v13988 = v13985->regs;
  int v13989 = v13988[10];
  int v13990 = v13988[11];
  int * v13991 = v13985->cache_tags;
  int v14161 = (((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2;
  int v13992 = v13991[v14161];
  int v14162 = ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13993 = v13991[v14162];
  int v14163 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2);
  int v13994 = v13991[v14163];
  int v14164 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13995 = v13991[v14164];
  int v13996 = v13985->timer;
  int v14165 = v13996 + ((100 ^ (((~(((v13994 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13994 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13992 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13992 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13993 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13993 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13994 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13994 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13985->timer = v14165;
  bool v14166 = !(((~(((v13992 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13992 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13993 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13993 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v14090;
  if (v14166) {
    int * v13998 = v13985->cache_age;
    int v14168 = ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v13993 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13993 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v13999 = v13998[v14168];
    int v14000 = v13998[v14161];
    int v14169 = v14000 + ((int)((unsigned int)(v14000 - v13999) >> 31));
    v13998[v14161] = v14169;
    int * v14002 = v13985->cache_age;
    int v14003 = v14002[v14162];
    int v14171 = v14003 + ((int)((unsigned int)(v14003 - v13999) >> 31));
    v14002[v14162] = v14171;
    int * v14005 = v13985->cache_age;
    v14005[v14168] = 0;
    v14090 = v14168;
  } else {
    int * v14008 = v13985->cache_age;
    int v14175 = (((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2;
    int v14009 = v14008[v14175];
    int * v14010 = v13985->cache_tags;
    int v14011 = v14010[v14175];
    int v14012 = v14008[v14162];
    int v14013 = v14010[v14162];
    bool v14177 = !(((~(((v13994 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13994 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v14067;
    if (v14177) {
      int * v14014 = v13985->cache_age;
      int v14179 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v13995 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v14015 = v14014[v14179];
      int v14016 = v14014[v14163];
      int v14180 = v14016 + ((int)((unsigned int)(v14016 - v14015) >> 31));
      v14014[v14163] = v14180;
      int * v14018 = v13985->cache_age;
      int v14019 = v14018[v14164];
      int v14182 = v14019 + ((int)((unsigned int)(v14019 - v14015) >> 31));
      v14018[v14164] = v14182;
      int * v14021 = v13985->cache_age;
      v14021[v14179] = 0;
      v14067 = v14179;
    } else {
      int * v14024 = v13985->cache_age;
      int v14186 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2);
      int v14025 = v14024[v14186];
      int * v14026 = v13985->cache_tags;
      int v14027 = v14026[v14186];
      int v14028 = v14024[v14164];
      int v14029 = v14026[v14164];
      int * v14030 = v13985->cache_dirty;
      int v14189 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14025 + ((~(((v14027 ^ -1) | (-(v14027 ^ -1))) >> 31)) & 2)) - (v14028 + ((~(((v14029 ^ -1) | (-(v14029 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14031 = v14030[v14189];
      bool v14190 = !(v14031 == 0);
      if (v14190) {
        int * v14032 = v13985->cache_tags;
        int v14033 = v14032[v14189];
        int * v14034 = v13985->cache_vals;
        int v14193 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14025 + ((~(((v14027 ^ -1) | (-(v14027 ^ -1))) >> 31)) & 2)) - (v14028 + ((~(((v14029 ^ -1) | (-(v14029 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14035 = v14034[v14193];
        int v14194 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14025 + ((~(((v14027 ^ -1) | (-(v14027 ^ -1))) >> 31)) & 2)) - (v14028 + ((~(((v14029 ^ -1) | (-(v14029 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14036 = v14034[v14194];
        int * v14037 = v13985->mem;
        int v14196 = v14033 * 2;
        v14037[v14196] = v14035;
        int * v14039 = v13985->mem;
        int v14199 = (v14033 * 2) + 1;
        v14039[v14199] = v14036;
        ;
      } else {
        ;
      }
      int * v14044 = v13985->mem;
      int v14204 = ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) * 2;
      int v14045 = v14044[v14204];
      int v14205 = (((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) * 2) + 1;
      int v14046 = v14044[v14205];
      int * v14047 = v13985->cache_vals;
      int v14207 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14025 + ((~(((v14027 ^ -1) | (-(v14027 ^ -1))) >> 31)) & 2)) - (v14028 + ((~(((v14029 ^ -1) | (-(v14029 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14047[v14207] = v14045;
      int * v14049 = v13985->cache_vals;
      int v14210 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14025 + ((~(((v14027 ^ -1) | (-(v14027 ^ -1))) >> 31)) & 2)) - (v14028 + ((~(((v14029 ^ -1) | (-(v14029 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14049[v14210] = v14046;
      int * v14051 = v13985->cache_tags;
      int v14213 = (int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1);
      v14051[v14189] = v14213;
      int * v14053 = v13985->cache_dirty;
      v14053[v14189] = 0;
      int * v14055 = v13985->cache_age;
      v14055[v14189] = 1;
      int * v14057 = v13985->cache_age;
      int v14058 = v14057[v14189];
      int v14059 = v14057[v14163];
      int v14219 = v14059 + ((int)((unsigned int)(v14059 - v14058) >> 31));
      v14057[v14163] = v14219;
      int * v14061 = v13985->cache_age;
      int v14062 = v14061[v14164];
      int v14221 = v14062 + ((int)((unsigned int)(v14062 - v14058) >> 31));
      v14061[v14164] = v14221;
      int * v14064 = v13985->cache_age;
      v14064[v14189] = 0;
      v14067 = v14189;
    }
    int * v14068 = v13985->cache_vals;
    int v14224 = v14067 * 2;
    int v14069 = v14068[v14224];
    int v14225 = (v14067 * 2) + 1;
    int v14070 = v14068[v14225];
    int v14226 = (((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v14009 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2)) - (v14012 + ((~(((v14013 ^ -1) | (-(v14013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14068[v14226] = v14069;
    int * v14072 = v13985->cache_vals;
    int v14229 = ((((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v14009 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2)) - (v14012 + ((~(((v14013 ^ -1) | (-(v14013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14072[v14229] = v14070;
    int * v14074 = v13985->cache_tags;
    int v14232 = ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v14009 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2)) - (v14012 + ((~(((v14013 ^ -1) | (-(v14013 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14233 = (int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1);
    v14074[v14232] = v14233;
    int * v14076 = v13985->cache_dirty;
    v14076[v14232] = 0;
    int * v14078 = v13985->cache_age;
    v14078[v14232] = 1;
    int * v14080 = v13985->cache_age;
    int v14081 = v14080[v14232];
    int v14082 = v14080[v14161];
    int v14239 = v14082 + ((int)((unsigned int)(v14082 - v14081) >> 31));
    v14080[v14161] = v14239;
    int * v14084 = v13985->cache_age;
    int v14085 = v14084[v14162];
    int v14241 = v14085 + ((int)((unsigned int)(v14085 - v14081) >> 31));
    v14084[v14162] = v14241;
    int * v14087 = v13985->cache_age;
    v14087[v14232] = 0;
    v14090 = v14232;
  }
  int * v14091 = v13985->cache_vals;
  int v14244 = (v14090 * 2) + (((int)((unsigned int)(v13989 + 20) >> 2)) & 1);
  v14091[v14244] = v13990;
  int * v14093 = v13985->cache_tags;
  int v14094 = v14093[v14163];
  int v14095 = v14093[v14164];
  bool v14247 = !(((~(((v14094 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v14094 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v14095 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v14095 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v14149;
  if (v14247) {
    int * v14096 = v13985->cache_age;
    int v14249 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14095 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))) | (-(v14095 ^ ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v14097 = v14096[v14249];
    int v14098 = v14096[v14163];
    int v14250 = v14098 + ((int)((unsigned int)(v14098 - v14097) >> 31));
    v14096[v14163] = v14250;
    int * v14100 = v13985->cache_age;
    int v14101 = v14100[v14164];
    int v14252 = v14101 + ((int)((unsigned int)(v14101 - v14097) >> 31));
    v14100[v14164] = v14252;
    int * v14103 = v13985->cache_age;
    v14103[v14249] = 0;
    v14149 = v14249;
  } else {
    int * v14106 = v13985->cache_age;
    int v14256 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2);
    int v14107 = v14106[v14256];
    int * v14108 = v13985->cache_tags;
    int v14109 = v14108[v14256];
    int v14110 = v14106[v14164];
    int v14111 = v14108[v14164];
    int * v14112 = v13985->cache_dirty;
    int v14259 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14107 + ((~(((v14109 ^ -1) | (-(v14109 ^ -1))) >> 31)) & 2)) - (v14110 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14113 = v14112[v14259];
    bool v14260 = !(v14113 == 0);
    if (v14260) {
      int * v14114 = v13985->cache_tags;
      int v14115 = v14114[v14259];
      int * v14116 = v13985->cache_vals;
      int v14263 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14107 + ((~(((v14109 ^ -1) | (-(v14109 ^ -1))) >> 31)) & 2)) - (v14110 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v14117 = v14116[v14263];
      int v14264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14107 + ((~(((v14109 ^ -1) | (-(v14109 ^ -1))) >> 31)) & 2)) - (v14110 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v14118 = v14116[v14264];
      int * v14119 = v13985->mem;
      int v14266 = v14115 * 2;
      v14119[v14266] = v14117;
      int * v14121 = v13985->mem;
      int v14269 = (v14115 * 2) + 1;
      v14121[v14269] = v14118;
      ;
    } else {
      ;
    }
    int * v14126 = v13985->mem;
    int v14274 = ((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) * 2;
    int v14127 = v14126[v14274];
    int v14275 = (((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) * 2) + 1;
    int v14128 = v14126[v14275];
    int * v14129 = v13985->cache_vals;
    int v14277 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14107 + ((~(((v14109 ^ -1) | (-(v14109 ^ -1))) >> 31)) & 2)) - (v14110 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14129[v14277] = v14127;
    int * v14131 = v13985->cache_vals;
    int v14280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v14107 + ((~(((v14109 ^ -1) | (-(v14109 ^ -1))) >> 31)) & 2)) - (v14110 + ((~(((v14111 ^ -1) | (-(v14111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14131[v14280] = v14128;
    int * v14133 = v13985->cache_tags;
    int v14283 = (int)((unsigned int)((int)((unsigned int)(v13989 + 20) >> 2)) >> 1);
    v14133[v14259] = v14283;
    int * v14135 = v13985->cache_dirty;
    v14135[v14259] = 0;
    int * v14137 = v13985->cache_age;
    v14137[v14259] = 1;
    int * v14139 = v13985->cache_age;
    int v14140 = v14139[v14259];
    int v14141 = v14139[v14163];
    int v14289 = v14141 + ((int)((unsigned int)(v14141 - v14140) >> 31));
    v14139[v14163] = v14289;
    int * v14143 = v13985->cache_age;
    int v14144 = v14143[v14164];
    int v14291 = v14144 + ((int)((unsigned int)(v14144 - v14140) >> 31));
    v14143[v14164] = v14291;
    int * v14146 = v13985->cache_age;
    v14146[v14259] = 0;
    v14149 = v14259;
  }
  int * v14150 = v13985->cache_vals;
  int v14294 = (v14149 * 2) + (((int)((unsigned int)(v13989 + 20) >> 2)) & 1);
  v14150[v14294] = v13990;
  int * v14152 = v13985->cache_dirty;
  v14152[v14149] = 1;
  struct StateT * v14154 = slot_252(v13985);
  return v14154;
}

struct StateT * slot_65(struct StateT * v11010) {
  int v11011 = v11010->timer;
  int v11018 = v11011 + 1;
  v11010->timer = v11018;
  int * v11013 = v11010->regs;
  int v11014 = v11013[8];
  int v11021 = v11014 << 7;
  v11013[8] = v11021;
  struct StateT * v11016 = slot_66(v11010);
  return v11016;
}

struct StateT * slot_10(struct StateT * v2847) {
  int v2848 = v2847->timer;
  int v3018 = v2848 + 1;
  v2847->timer = v3018;
  int * v2850 = v2847->regs;
  int v2851 = v2850[2];
  int v2852 = v2850[24];
  int * v2853 = v2847->cache_tags;
  int v3023 = (((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2;
  int v2854 = v2853[v3023];
  int v3024 = ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2855 = v2853[v3024];
  int v3025 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2);
  int v2856 = v2853[v3025];
  int v3026 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2857 = v2853[v3026];
  int v2858 = v2847->timer;
  int v3027 = v2858 + ((100 ^ (((~(((v2856 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2856 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2856 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2856 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2847->timer = v3027;
  bool v3028 = !(((~(((v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2854 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31))) == 0);
  int v2952;
  if (v3028) {
    int * v2860 = v2847->cache_age;
    int v3030 = ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2) + ((~(((v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2855 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) & 1);
    int v2861 = v2860[v3030];
    int v2862 = v2860[v3023];
    int v3031 = v2862 + ((int)((unsigned int)(v2862 - v2861) >> 31));
    v2860[v3023] = v3031;
    int * v2864 = v2847->cache_age;
    int v2865 = v2864[v3024];
    int v3033 = v2865 + ((int)((unsigned int)(v2865 - v2861) >> 31));
    v2864[v3024] = v3033;
    int * v2867 = v2847->cache_age;
    v2867[v3030] = 0;
    v2952 = v3030;
  } else {
    int * v2870 = v2847->cache_age;
    int v3037 = (((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2;
    int v2871 = v2870[v3037];
    int * v2872 = v2847->cache_tags;
    int v2873 = v2872[v3037];
    int v2874 = v2870[v3024];
    int v2875 = v2872[v3024];
    bool v3039 = !(((~(((v2856 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2856 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31))) == 0);
    int v2929;
    if (v3039) {
      int * v2876 = v2847->cache_age;
      int v3041 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) & 1);
      int v2877 = v2876[v3041];
      int v2878 = v2876[v3025];
      int v3042 = v2878 + ((int)((unsigned int)(v2878 - v2877) >> 31));
      v2876[v3025] = v3042;
      int * v2880 = v2847->cache_age;
      int v2881 = v2880[v3026];
      int v3044 = v2881 + ((int)((unsigned int)(v2881 - v2877) >> 31));
      v2880[v3026] = v3044;
      int * v2883 = v2847->cache_age;
      v2883[v3041] = 0;
      v2929 = v3041;
    } else {
      int * v2886 = v2847->cache_age;
      int v3048 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2);
      int v2887 = v2886[v3048];
      int * v2888 = v2847->cache_tags;
      int v2889 = v2888[v3048];
      int v2890 = v2886[v3026];
      int v2891 = v2888[v3026];
      int * v2892 = v2847->cache_dirty;
      int v3051 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2887 + ((~(((v2889 ^ -1) | (-(v2889 ^ -1))) >> 31)) & 2)) - (v2890 + ((~(((v2891 ^ -1) | (-(v2891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2893 = v2892[v3051];
      bool v3052 = !(v2893 == 0);
      if (v3052) {
        int * v2894 = v2847->cache_tags;
        int v2895 = v2894[v3051];
        int * v2896 = v2847->cache_vals;
        int v3055 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2887 + ((~(((v2889 ^ -1) | (-(v2889 ^ -1))) >> 31)) & 2)) - (v2890 + ((~(((v2891 ^ -1) | (-(v2891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2897 = v2896[v3055];
        int v3056 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2887 + ((~(((v2889 ^ -1) | (-(v2889 ^ -1))) >> 31)) & 2)) - (v2890 + ((~(((v2891 ^ -1) | (-(v2891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2898 = v2896[v3056];
        int * v2899 = v2847->mem;
        int v3058 = v2895 * 2;
        v2899[v3058] = v2897;
        int * v2901 = v2847->mem;
        int v3061 = (v2895 * 2) + 1;
        v2901[v3061] = v2898;
        ;
      } else {
        ;
      }
      int * v2906 = v2847->mem;
      int v3066 = ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) * 2;
      int v2907 = v2906[v3066];
      int v3067 = (((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) * 2) + 1;
      int v2908 = v2906[v3067];
      int * v2909 = v2847->cache_vals;
      int v3069 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2887 + ((~(((v2889 ^ -1) | (-(v2889 ^ -1))) >> 31)) & 2)) - (v2890 + ((~(((v2891 ^ -1) | (-(v2891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2909[v3069] = v2907;
      int * v2911 = v2847->cache_vals;
      int v3072 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2887 + ((~(((v2889 ^ -1) | (-(v2889 ^ -1))) >> 31)) & 2)) - (v2890 + ((~(((v2891 ^ -1) | (-(v2891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2911[v3072] = v2908;
      int * v2913 = v2847->cache_tags;
      int v3075 = (int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1);
      v2913[v3051] = v3075;
      int * v2915 = v2847->cache_dirty;
      v2915[v3051] = 0;
      int * v2917 = v2847->cache_age;
      v2917[v3051] = 1;
      int * v2919 = v2847->cache_age;
      int v2920 = v2919[v3051];
      int v2921 = v2919[v3025];
      int v3081 = v2921 + ((int)((unsigned int)(v2921 - v2920) >> 31));
      v2919[v3025] = v3081;
      int * v2923 = v2847->cache_age;
      int v2924 = v2923[v3026];
      int v3083 = v2924 + ((int)((unsigned int)(v2924 - v2920) >> 31));
      v2923[v3026] = v3083;
      int * v2926 = v2847->cache_age;
      v2926[v3051] = 0;
      v2929 = v3051;
    }
    int * v2930 = v2847->cache_vals;
    int v3086 = v2929 * 2;
    int v2931 = v2930[v3086];
    int v3087 = (v2929 * 2) + 1;
    int v2932 = v2930[v3087];
    int v3088 = (((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v2871 + ((~(((v2873 ^ -1) | (-(v2873 ^ -1))) >> 31)) & 2)) - (v2874 + ((~(((v2875 ^ -1) | (-(v2875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2930[v3088] = v2931;
    int * v2934 = v2847->cache_vals;
    int v3091 = ((((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v2871 + ((~(((v2873 ^ -1) | (-(v2873 ^ -1))) >> 31)) & 2)) - (v2874 + ((~(((v2875 ^ -1) | (-(v2875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2934[v3091] = v2932;
    int * v2936 = v2847->cache_tags;
    int v3094 = ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v2871 + ((~(((v2873 ^ -1) | (-(v2873 ^ -1))) >> 31)) & 2)) - (v2874 + ((~(((v2875 ^ -1) | (-(v2875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3095 = (int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1);
    v2936[v3094] = v3095;
    int * v2938 = v2847->cache_dirty;
    v2938[v3094] = 0;
    int * v2940 = v2847->cache_age;
    v2940[v3094] = 1;
    int * v2942 = v2847->cache_age;
    int v2943 = v2942[v3094];
    int v2944 = v2942[v3023];
    int v3101 = v2944 + ((int)((unsigned int)(v2944 - v2943) >> 31));
    v2942[v3023] = v3101;
    int * v2946 = v2847->cache_age;
    int v2947 = v2946[v3024];
    int v3103 = v2947 + ((int)((unsigned int)(v2947 - v2943) >> 31));
    v2946[v3024] = v3103;
    int * v2949 = v2847->cache_age;
    v2949[v3094] = 0;
    v2952 = v3094;
  }
  int * v2953 = v2847->cache_vals;
  int v3106 = (v2952 * 2) + (((int)((unsigned int)(v2851 + 56) >> 2)) & 1);
  v2953[v3106] = v2852;
  int * v2955 = v2847->cache_tags;
  int v2956 = v2955[v3025];
  int v2957 = v2955[v3026];
  bool v3109 = !(((~(((v2956 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2956 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v2957 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2957 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31))) == 0);
  int v3011;
  if (v3109) {
    int * v2958 = v2847->cache_age;
    int v3111 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2957 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))) | (-(v2957 ^ ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1))))) >> 31)) & 1);
    int v2959 = v2958[v3111];
    int v2960 = v2958[v3025];
    int v3112 = v2960 + ((int)((unsigned int)(v2960 - v2959) >> 31));
    v2958[v3025] = v3112;
    int * v2962 = v2847->cache_age;
    int v2963 = v2962[v3026];
    int v3114 = v2963 + ((int)((unsigned int)(v2963 - v2959) >> 31));
    v2962[v3026] = v3114;
    int * v2965 = v2847->cache_age;
    v2965[v3111] = 0;
    v3011 = v3111;
  } else {
    int * v2968 = v2847->cache_age;
    int v3118 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2);
    int v2969 = v2968[v3118];
    int * v2970 = v2847->cache_tags;
    int v2971 = v2970[v3118];
    int v2972 = v2968[v3026];
    int v2973 = v2970[v3026];
    int * v2974 = v2847->cache_dirty;
    int v3121 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2969 + ((~(((v2971 ^ -1) | (-(v2971 ^ -1))) >> 31)) & 2)) - (v2972 + ((~(((v2973 ^ -1) | (-(v2973 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2975 = v2974[v3121];
    bool v3122 = !(v2975 == 0);
    if (v3122) {
      int * v2976 = v2847->cache_tags;
      int v2977 = v2976[v3121];
      int * v2978 = v2847->cache_vals;
      int v3125 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2969 + ((~(((v2971 ^ -1) | (-(v2971 ^ -1))) >> 31)) & 2)) - (v2972 + ((~(((v2973 ^ -1) | (-(v2973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2979 = v2978[v3125];
      int v3126 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2969 + ((~(((v2971 ^ -1) | (-(v2971 ^ -1))) >> 31)) & 2)) - (v2972 + ((~(((v2973 ^ -1) | (-(v2973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2980 = v2978[v3126];
      int * v2981 = v2847->mem;
      int v3128 = v2977 * 2;
      v2981[v3128] = v2979;
      int * v2983 = v2847->mem;
      int v3131 = (v2977 * 2) + 1;
      v2983[v3131] = v2980;
      ;
    } else {
      ;
    }
    int * v2988 = v2847->mem;
    int v3136 = ((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) * 2;
    int v2989 = v2988[v3136];
    int v3137 = (((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) * 2) + 1;
    int v2990 = v2988[v3137];
    int * v2991 = v2847->cache_vals;
    int v3139 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2969 + ((~(((v2971 ^ -1) | (-(v2971 ^ -1))) >> 31)) & 2)) - (v2972 + ((~(((v2973 ^ -1) | (-(v2973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2991[v3139] = v2989;
    int * v2993 = v2847->cache_vals;
    int v3142 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v2969 + ((~(((v2971 ^ -1) | (-(v2971 ^ -1))) >> 31)) & 2)) - (v2972 + ((~(((v2973 ^ -1) | (-(v2973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2993[v3142] = v2990;
    int * v2995 = v2847->cache_tags;
    int v3145 = (int)((unsigned int)((int)((unsigned int)(v2851 + 56) >> 2)) >> 1);
    v2995[v3121] = v3145;
    int * v2997 = v2847->cache_dirty;
    v2997[v3121] = 0;
    int * v2999 = v2847->cache_age;
    v2999[v3121] = 1;
    int * v3001 = v2847->cache_age;
    int v3002 = v3001[v3121];
    int v3003 = v3001[v3025];
    int v3151 = v3003 + ((int)((unsigned int)(v3003 - v3002) >> 31));
    v3001[v3025] = v3151;
    int * v3005 = v2847->cache_age;
    int v3006 = v3005[v3026];
    int v3153 = v3006 + ((int)((unsigned int)(v3006 - v3002) >> 31));
    v3005[v3026] = v3153;
    int * v3008 = v2847->cache_age;
    v3008[v3121] = 0;
    v3011 = v3121;
  }
  int * v3012 = v2847->cache_vals;
  int v3156 = (v3011 * 2) + (((int)((unsigned int)(v2851 + 56) >> 2)) & 1);
  v3012[v3156] = v2852;
  int * v3014 = v2847->cache_dirty;
  v3014[v3011] = 1;
  struct StateT * v3016 = slot_11(v2847);
  return v3016;
}

struct StateT * slot_150(struct StateT * v21077) {
  int v21078 = v21077->timer;
  int v21086 = v21078 + 1;
  v21077->timer = v21086;
  int * v21080 = v21077->regs;
  int v21081 = v21080[9];
  int v21082 = v21080[6];
  int v21091 = v21081 ^ v21082;
  v21080[16] = v21091;
  struct StateT * v21084 = slot_151(v21077);
  return v21084;
}

struct StateT * slot_74(struct StateT * v12048) {
  int v12049 = v12048->timer;
  int v12057 = v12049 + 1;
  v12048->timer = v12057;
  int * v12051 = v12048->regs;
  int v12052 = v12051[14];
  int v12053 = v12051[22];
  int v12062 = v12052 + v12053;
  v12051[18] = v12062;
  struct StateT * v12055 = slot_75(v12048);
  return v12055;
}

struct StateT * slot_262(struct StateT * v17620) {
  int v17621 = v17620->timer;
  int v17731 = v17621 + 1;
  v17620->timer = v17731;
  int * v17623 = v17620->regs;
  int v17624 = v17623[2];
  int * v17625 = v17620->cache_tags;
  int v17735 = (((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2;
  int v17626 = v17625[v17735];
  int v17736 = ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2) + 1;
  int v17627 = v17625[v17736];
  int v17737 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2);
  int v17628 = v17625[v17737];
  int v17738 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17629 = v17625[v17738];
  int v17630 = v17620->timer;
  int v17739 = v17630 + ((100 ^ (((~(((v17628 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17628 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v17626 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17626 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v17627 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17627 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v17628 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17628 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31))) & 104)))));
  v17620->timer = v17739;
  int * v17632 = v17620->cache_vals;
  bool v17740 = !(((~(((v17626 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17626 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v17627 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17627 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31))) == 0);
  int v17725;
  if (v17740) {
    int * v17633 = v17620->cache_age;
    int v17742 = ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2) + ((~(((v17627 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17627 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) & 1);
    int v17634 = v17633[v17742];
    int v17635 = v17633[v17735];
    int v17743 = v17635 + ((int)((unsigned int)(v17635 - v17634) >> 31));
    v17633[v17735] = v17743;
    int * v17637 = v17620->cache_age;
    int v17638 = v17637[v17736];
    int v17745 = v17638 + ((int)((unsigned int)(v17638 - v17634) >> 31));
    v17637[v17736] = v17745;
    int * v17640 = v17620->cache_age;
    v17640[v17742] = 0;
    v17725 = v17742;
  } else {
    int * v17643 = v17620->cache_age;
    int v17749 = (((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2;
    int v17644 = v17643[v17749];
    int * v17645 = v17620->cache_tags;
    int v17646 = v17645[v17749];
    int v17647 = v17643[v17736];
    int v17648 = v17645[v17736];
    bool v17751 = !(((~(((v17628 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17628 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31))) == 0);
    int v17702;
    if (v17751) {
      int * v17649 = v17620->cache_age;
      int v17753 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))) | (-(v17629 ^ ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1))))) >> 31)) & 1);
      int v17650 = v17649[v17753];
      int v17651 = v17649[v17737];
      int v17754 = v17651 + ((int)((unsigned int)(v17651 - v17650) >> 31));
      v17649[v17737] = v17754;
      int * v17653 = v17620->cache_age;
      int v17654 = v17653[v17738];
      int v17756 = v17654 + ((int)((unsigned int)(v17654 - v17650) >> 31));
      v17653[v17738] = v17756;
      int * v17656 = v17620->cache_age;
      v17656[v17753] = 0;
      v17702 = v17753;
    } else {
      int * v17659 = v17620->cache_age;
      int v17760 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2);
      int v17660 = v17659[v17760];
      int * v17661 = v17620->cache_tags;
      int v17662 = v17661[v17760];
      int v17663 = v17659[v17738];
      int v17664 = v17661[v17738];
      int * v17665 = v17620->cache_dirty;
      int v17763 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v17660 + ((~(((v17662 ^ -1) | (-(v17662 ^ -1))) >> 31)) & 2)) - (v17663 + ((~(((v17664 ^ -1) | (-(v17664 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17666 = v17665[v17763];
      bool v17764 = !(v17666 == 0);
      if (v17764) {
        int * v17667 = v17620->cache_tags;
        int v17668 = v17667[v17763];
        int * v17669 = v17620->cache_vals;
        int v17767 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v17660 + ((~(((v17662 ^ -1) | (-(v17662 ^ -1))) >> 31)) & 2)) - (v17663 + ((~(((v17664 ^ -1) | (-(v17664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17670 = v17669[v17767];
        int v17768 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v17660 + ((~(((v17662 ^ -1) | (-(v17662 ^ -1))) >> 31)) & 2)) - (v17663 + ((~(((v17664 ^ -1) | (-(v17664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17671 = v17669[v17768];
        int * v17672 = v17620->mem;
        int v17770 = v17668 * 2;
        v17672[v17770] = v17670;
        int * v17674 = v17620->mem;
        int v17773 = (v17668 * 2) + 1;
        v17674[v17773] = v17671;
        ;
      } else {
        ;
      }
      int * v17679 = v17620->mem;
      int v17778 = ((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) * 2;
      int v17680 = v17679[v17778];
      int v17779 = (((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) * 2) + 1;
      int v17681 = v17679[v17779];
      int * v17682 = v17620->cache_vals;
      int v17781 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v17660 + ((~(((v17662 ^ -1) | (-(v17662 ^ -1))) >> 31)) & 2)) - (v17663 + ((~(((v17664 ^ -1) | (-(v17664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17682[v17781] = v17680;
      int * v17684 = v17620->cache_vals;
      int v17784 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v17660 + ((~(((v17662 ^ -1) | (-(v17662 ^ -1))) >> 31)) & 2)) - (v17663 + ((~(((v17664 ^ -1) | (-(v17664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17684[v17784] = v17681;
      int * v17686 = v17620->cache_tags;
      int v17787 = (int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1);
      v17686[v17763] = v17787;
      int * v17688 = v17620->cache_dirty;
      v17688[v17763] = 0;
      int * v17690 = v17620->cache_age;
      v17690[v17763] = 1;
      int * v17692 = v17620->cache_age;
      int v17693 = v17692[v17763];
      int v17694 = v17692[v17737];
      int v17793 = v17694 + ((int)((unsigned int)(v17694 - v17693) >> 31));
      v17692[v17737] = v17793;
      int * v17696 = v17620->cache_age;
      int v17697 = v17696[v17738];
      int v17795 = v17697 + ((int)((unsigned int)(v17697 - v17693) >> 31));
      v17696[v17738] = v17795;
      int * v17699 = v17620->cache_age;
      v17699[v17763] = 0;
      v17702 = v17763;
    }
    int * v17703 = v17620->cache_vals;
    int v17798 = v17702 * 2;
    int v17704 = v17703[v17798];
    int v17799 = (v17702 * 2) + 1;
    int v17705 = v17703[v17799];
    int v17800 = (((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2) + ((((v17644 + ((~(((v17646 ^ -1) | (-(v17646 ^ -1))) >> 31)) & 2)) - (v17647 + ((~(((v17648 ^ -1) | (-(v17648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17703[v17800] = v17704;
    int * v17707 = v17620->cache_vals;
    int v17803 = ((((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2) + ((((v17644 + ((~(((v17646 ^ -1) | (-(v17646 ^ -1))) >> 31)) & 2)) - (v17647 + ((~(((v17648 ^ -1) | (-(v17648 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17707[v17803] = v17705;
    int * v17709 = v17620->cache_tags;
    int v17806 = ((((int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1)) & 1) * 2) + ((((v17644 + ((~(((v17646 ^ -1) | (-(v17646 ^ -1))) >> 31)) & 2)) - (v17647 + ((~(((v17648 ^ -1) | (-(v17648 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17807 = (int)((unsigned int)((int)((unsigned int)(v17624 + 92) >> 2)) >> 1);
    v17709[v17806] = v17807;
    int * v17711 = v17620->cache_dirty;
    v17711[v17806] = 0;
    int * v17713 = v17620->cache_age;
    v17713[v17806] = 1;
    int * v17715 = v17620->cache_age;
    int v17716 = v17715[v17806];
    int v17717 = v17715[v17735];
    int v17813 = v17717 + ((int)((unsigned int)(v17717 - v17716) >> 31));
    v17715[v17735] = v17813;
    int * v17719 = v17620->cache_age;
    int v17720 = v17719[v17736];
    int v17815 = v17720 + ((int)((unsigned int)(v17720 - v17716) >> 31));
    v17719[v17736] = v17815;
    int * v17722 = v17620->cache_age;
    v17722[v17806] = 0;
    v17725 = v17806;
  }
  int v17818 = (v17725 * 2) + (((int)((unsigned int)(v17624 + 92) >> 2)) & 1);
  int v17726 = v17632[v17818];
  int * v17727 = v17620->regs;
  v17727[1] = v17726;
  struct StateT * v17729 = slot_263(v17620);
  return v17729;
}

struct StateT * slot_107(struct StateT * v19359) {
  int v19360 = v19359->timer;
  int v19368 = v19360 + 1;
  v19359->timer = v19368;
  int * v19362 = v19359->regs;
  int v19363 = v19362[16];
  int v19364 = v19362[15];
  int v19373 = v19363 ^ v19364;
  v19362[9] = v19373;
  struct StateT * v19366 = slot_108(v19359);
  return v19366;
}

struct StateT * slot_136(struct StateT * v20861) {
  int v20862 = v20861->timer;
  int v20869 = v20862 + 1;
  v20861->timer = v20869;
  int * v20864 = v20861->regs;
  int v20865 = v20864[15];
  int v20872 = v20865 << 7;
  v20864[15] = v20872;
  struct StateT * v20867 = slot_137(v20861);
  return v20867;
}

struct StateT * slot_84(struct StateT * v12648) {
  int v12649 = v12648->timer;
  int v12656 = v12649 + 1;
  v12648->timer = v12656;
  int * v12651 = v12648->regs;
  int v12652 = v12651[18];
  int v12660 = (int)((unsigned int)v12652 >> 23);
  v12651[20] = v12660;
  struct StateT * v12654 = slot_85(v12648);
  return v12654;
}

struct StateT * slot_28(struct StateT * v6581) {
  int v6582 = v6581->timer;
  int v6588 = v6582 + 1;
  v6581->timer = v6588;
  int * v6584 = v6581->regs;
  v6584[13] = 857759744;
  struct StateT * v6586 = slot_29(v6581);
  return v6586;
}

struct StateT * slot_155(struct StateT * v21162) {
  int v21163 = v21162->timer;
  int v21170 = v21163 + 1;
  v21162->timer = v21170;
  int * v21165 = v21162->regs;
  int v21166 = v21165[11];
  int v21174 = (int)((unsigned int)v21166 >> 23);
  v21165[9] = v21174;
  struct StateT * v21168 = slot_156(v21162);
  return v21168;
}

struct StateT * slot_177(struct StateT * v21503) {
  int v21504 = v21503->timer;
  int v21512 = v21504 + 1;
  v21503->timer = v21512;
  int * v21506 = v21503->regs;
  int v21507 = v21506[11];
  int v21508 = v21506[9];
  int v21516 = v21507 | v21508;
  v21506[11] = v21516;
  struct StateT * v21510 = slot_178(v21503);
  return v21510;
}

struct StateT * slot_229(struct StateT * v11053) {
  int v11054 = v11053->timer;
  int v11164 = v11054 + 1;
  v11053->timer = v11164;
  int * v11056 = v11053->regs;
  int v11057 = v11056[2];
  int * v11058 = v11053->cache_tags;
  int v11168 = (((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2;
  int v11059 = v11058[v11168];
  int v11169 = ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11060 = v11058[v11169];
  int v11170 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2);
  int v11061 = v11058[v11170];
  int v11171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11062 = v11058[v11171];
  int v11063 = v11053->timer;
  int v11172 = v11063 + ((100 ^ (((~(((v11061 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11061 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11059 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11059 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11060 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11060 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11061 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11061 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11053->timer = v11172;
  int * v11065 = v11053->cache_vals;
  bool v11173 = !(((~(((v11059 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11059 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11060 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11060 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v11158;
  if (v11173) {
    int * v11066 = v11053->cache_age;
    int v11175 = ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v11060 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11060 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v11067 = v11066[v11175];
    int v11068 = v11066[v11168];
    int v11176 = v11068 + ((int)((unsigned int)(v11068 - v11067) >> 31));
    v11066[v11168] = v11176;
    int * v11070 = v11053->cache_age;
    int v11071 = v11070[v11169];
    int v11178 = v11071 + ((int)((unsigned int)(v11071 - v11067) >> 31));
    v11070[v11169] = v11178;
    int * v11073 = v11053->cache_age;
    v11073[v11175] = 0;
    v11158 = v11175;
  } else {
    int * v11076 = v11053->cache_age;
    int v11182 = (((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2;
    int v11077 = v11076[v11182];
    int * v11078 = v11053->cache_tags;
    int v11079 = v11078[v11182];
    int v11080 = v11076[v11169];
    int v11081 = v11078[v11169];
    bool v11184 = !(((~(((v11061 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11061 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v11135;
    if (v11184) {
      int * v11082 = v11053->cache_age;
      int v11186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))) | (-(v11062 ^ ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v11083 = v11082[v11186];
      int v11084 = v11082[v11170];
      int v11187 = v11084 + ((int)((unsigned int)(v11084 - v11083) >> 31));
      v11082[v11170] = v11187;
      int * v11086 = v11053->cache_age;
      int v11087 = v11086[v11171];
      int v11189 = v11087 + ((int)((unsigned int)(v11087 - v11083) >> 31));
      v11086[v11171] = v11189;
      int * v11089 = v11053->cache_age;
      v11089[v11186] = 0;
      v11135 = v11186;
    } else {
      int * v11092 = v11053->cache_age;
      int v11193 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2);
      int v11093 = v11092[v11193];
      int * v11094 = v11053->cache_tags;
      int v11095 = v11094[v11193];
      int v11096 = v11092[v11171];
      int v11097 = v11094[v11171];
      int * v11098 = v11053->cache_dirty;
      int v11196 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11093 + ((~(((v11095 ^ -1) | (-(v11095 ^ -1))) >> 31)) & 2)) - (v11096 + ((~(((v11097 ^ -1) | (-(v11097 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11099 = v11098[v11196];
      bool v11197 = !(v11099 == 0);
      if (v11197) {
        int * v11100 = v11053->cache_tags;
        int v11101 = v11100[v11196];
        int * v11102 = v11053->cache_vals;
        int v11200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11093 + ((~(((v11095 ^ -1) | (-(v11095 ^ -1))) >> 31)) & 2)) - (v11096 + ((~(((v11097 ^ -1) | (-(v11097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11103 = v11102[v11200];
        int v11201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11093 + ((~(((v11095 ^ -1) | (-(v11095 ^ -1))) >> 31)) & 2)) - (v11096 + ((~(((v11097 ^ -1) | (-(v11097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11104 = v11102[v11201];
        int * v11105 = v11053->mem;
        int v11203 = v11101 * 2;
        v11105[v11203] = v11103;
        int * v11107 = v11053->mem;
        int v11206 = (v11101 * 2) + 1;
        v11107[v11206] = v11104;
        ;
      } else {
        ;
      }
      int * v11112 = v11053->mem;
      int v11211 = ((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) * 2;
      int v11113 = v11112[v11211];
      int v11212 = (((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) * 2) + 1;
      int v11114 = v11112[v11212];
      int * v11115 = v11053->cache_vals;
      int v11214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11093 + ((~(((v11095 ^ -1) | (-(v11095 ^ -1))) >> 31)) & 2)) - (v11096 + ((~(((v11097 ^ -1) | (-(v11097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11115[v11214] = v11113;
      int * v11117 = v11053->cache_vals;
      int v11217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11093 + ((~(((v11095 ^ -1) | (-(v11095 ^ -1))) >> 31)) & 2)) - (v11096 + ((~(((v11097 ^ -1) | (-(v11097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11117[v11217] = v11114;
      int * v11119 = v11053->cache_tags;
      int v11220 = (int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1);
      v11119[v11196] = v11220;
      int * v11121 = v11053->cache_dirty;
      v11121[v11196] = 0;
      int * v11123 = v11053->cache_age;
      v11123[v11196] = 1;
      int * v11125 = v11053->cache_age;
      int v11126 = v11125[v11196];
      int v11127 = v11125[v11170];
      int v11226 = v11127 + ((int)((unsigned int)(v11127 - v11126) >> 31));
      v11125[v11170] = v11226;
      int * v11129 = v11053->cache_age;
      int v11130 = v11129[v11171];
      int v11228 = v11130 + ((int)((unsigned int)(v11130 - v11126) >> 31));
      v11129[v11171] = v11228;
      int * v11132 = v11053->cache_age;
      v11132[v11196] = 0;
      v11135 = v11196;
    }
    int * v11136 = v11053->cache_vals;
    int v11231 = v11135 * 2;
    int v11137 = v11136[v11231];
    int v11232 = (v11135 * 2) + 1;
    int v11138 = v11136[v11232];
    int v11233 = (((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11077 + ((~(((v11079 ^ -1) | (-(v11079 ^ -1))) >> 31)) & 2)) - (v11080 + ((~(((v11081 ^ -1) | (-(v11081 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11136[v11233] = v11137;
    int * v11140 = v11053->cache_vals;
    int v11236 = ((((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11077 + ((~(((v11079 ^ -1) | (-(v11079 ^ -1))) >> 31)) & 2)) - (v11080 + ((~(((v11081 ^ -1) | (-(v11081 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11140[v11236] = v11138;
    int * v11142 = v11053->cache_tags;
    int v11239 = ((((int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11077 + ((~(((v11079 ^ -1) | (-(v11079 ^ -1))) >> 31)) & 2)) - (v11080 + ((~(((v11081 ^ -1) | (-(v11081 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11240 = (int)((unsigned int)((int)((unsigned int)(v11057 + 28) >> 2)) >> 1);
    v11142[v11239] = v11240;
    int * v11144 = v11053->cache_dirty;
    v11144[v11239] = 0;
    int * v11146 = v11053->cache_age;
    v11146[v11239] = 1;
    int * v11148 = v11053->cache_age;
    int v11149 = v11148[v11239];
    int v11150 = v11148[v11168];
    int v11246 = v11150 + ((int)((unsigned int)(v11150 - v11149) >> 31));
    v11148[v11168] = v11246;
    int * v11152 = v11053->cache_age;
    int v11153 = v11152[v11169];
    int v11248 = v11153 + ((int)((unsigned int)(v11153 - v11149) >> 31));
    v11152[v11169] = v11248;
    int * v11155 = v11053->cache_age;
    v11155[v11239] = 0;
    v11158 = v11239;
  }
  int v11251 = (v11158 * 2) + (((int)((unsigned int)(v11057 + 28) >> 2)) & 1);
  int v11159 = v11065[v11251];
  int * v11160 = v11053->regs;
  v11160[30] = v11159;
  struct StateT * v11162 = slot_230(v11053);
  return v11162;
}

struct StateT * slot_17(struct StateT * v4528) {
  int v4529 = v4528->timer;
  int v4639 = v4529 + 1;
  v4528->timer = v4639;
  int * v4531 = v4528->regs;
  int v4532 = v4531[12];
  int * v4533 = v4528->cache_tags;
  int v4643 = (((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2;
  int v4534 = v4533[v4643];
  int v4644 = ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4535 = v4533[v4644];
  int v4645 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2);
  int v4536 = v4533[v4645];
  int v4646 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4537 = v4533[v4646];
  int v4538 = v4528->timer;
  int v4647 = v4538 + ((100 ^ (((~(((v4536 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4536 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4534 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4534 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4535 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4535 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4536 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4536 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4528->timer = v4647;
  int * v4540 = v4528->cache_vals;
  bool v4648 = !(((~(((v4534 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4534 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4535 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4535 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4633;
  if (v4648) {
    int * v4541 = v4528->cache_age;
    int v4650 = ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v4535 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4535 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4542 = v4541[v4650];
    int v4543 = v4541[v4643];
    int v4651 = v4543 + ((int)((unsigned int)(v4543 - v4542) >> 31));
    v4541[v4643] = v4651;
    int * v4545 = v4528->cache_age;
    int v4546 = v4545[v4644];
    int v4653 = v4546 + ((int)((unsigned int)(v4546 - v4542) >> 31));
    v4545[v4644] = v4653;
    int * v4548 = v4528->cache_age;
    v4548[v4650] = 0;
    v4633 = v4650;
  } else {
    int * v4551 = v4528->cache_age;
    int v4657 = (((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2;
    int v4552 = v4551[v4657];
    int * v4553 = v4528->cache_tags;
    int v4554 = v4553[v4657];
    int v4555 = v4551[v4644];
    int v4556 = v4553[v4644];
    bool v4659 = !(((~(((v4536 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4536 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v4610;
    if (v4659) {
      int * v4557 = v4528->cache_age;
      int v4661 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))) | (-(v4537 ^ ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v4558 = v4557[v4661];
      int v4559 = v4557[v4645];
      int v4662 = v4559 + ((int)((unsigned int)(v4559 - v4558) >> 31));
      v4557[v4645] = v4662;
      int * v4561 = v4528->cache_age;
      int v4562 = v4561[v4646];
      int v4664 = v4562 + ((int)((unsigned int)(v4562 - v4558) >> 31));
      v4561[v4646] = v4664;
      int * v4564 = v4528->cache_age;
      v4564[v4661] = 0;
      v4610 = v4661;
    } else {
      int * v4567 = v4528->cache_age;
      int v4668 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2);
      int v4568 = v4567[v4668];
      int * v4569 = v4528->cache_tags;
      int v4570 = v4569[v4668];
      int v4571 = v4567[v4646];
      int v4572 = v4569[v4646];
      int * v4573 = v4528->cache_dirty;
      int v4671 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4568 + ((~(((v4570 ^ -1) | (-(v4570 ^ -1))) >> 31)) & 2)) - (v4571 + ((~(((v4572 ^ -1) | (-(v4572 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4574 = v4573[v4671];
      bool v4672 = !(v4574 == 0);
      if (v4672) {
        int * v4575 = v4528->cache_tags;
        int v4576 = v4575[v4671];
        int * v4577 = v4528->cache_vals;
        int v4675 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4568 + ((~(((v4570 ^ -1) | (-(v4570 ^ -1))) >> 31)) & 2)) - (v4571 + ((~(((v4572 ^ -1) | (-(v4572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4578 = v4577[v4675];
        int v4676 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4568 + ((~(((v4570 ^ -1) | (-(v4570 ^ -1))) >> 31)) & 2)) - (v4571 + ((~(((v4572 ^ -1) | (-(v4572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4579 = v4577[v4676];
        int * v4580 = v4528->mem;
        int v4678 = v4576 * 2;
        v4580[v4678] = v4578;
        int * v4582 = v4528->mem;
        int v4681 = (v4576 * 2) + 1;
        v4582[v4681] = v4579;
        ;
      } else {
        ;
      }
      int * v4587 = v4528->mem;
      int v4686 = ((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) * 2;
      int v4588 = v4587[v4686];
      int v4687 = (((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) * 2) + 1;
      int v4589 = v4587[v4687];
      int * v4590 = v4528->cache_vals;
      int v4689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4568 + ((~(((v4570 ^ -1) | (-(v4570 ^ -1))) >> 31)) & 2)) - (v4571 + ((~(((v4572 ^ -1) | (-(v4572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4590[v4689] = v4588;
      int * v4592 = v4528->cache_vals;
      int v4692 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4568 + ((~(((v4570 ^ -1) | (-(v4570 ^ -1))) >> 31)) & 2)) - (v4571 + ((~(((v4572 ^ -1) | (-(v4572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4592[v4692] = v4589;
      int * v4594 = v4528->cache_tags;
      int v4695 = (int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1);
      v4594[v4671] = v4695;
      int * v4596 = v4528->cache_dirty;
      v4596[v4671] = 0;
      int * v4598 = v4528->cache_age;
      v4598[v4671] = 1;
      int * v4600 = v4528->cache_age;
      int v4601 = v4600[v4671];
      int v4602 = v4600[v4645];
      int v4701 = v4602 + ((int)((unsigned int)(v4602 - v4601) >> 31));
      v4600[v4645] = v4701;
      int * v4604 = v4528->cache_age;
      int v4605 = v4604[v4646];
      int v4703 = v4605 + ((int)((unsigned int)(v4605 - v4601) >> 31));
      v4604[v4646] = v4703;
      int * v4607 = v4528->cache_age;
      v4607[v4671] = 0;
      v4610 = v4671;
    }
    int * v4611 = v4528->cache_vals;
    int v4706 = v4610 * 2;
    int v4612 = v4611[v4706];
    int v4707 = (v4610 * 2) + 1;
    int v4613 = v4611[v4707];
    int v4708 = (((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4552 + ((~(((v4554 ^ -1) | (-(v4554 ^ -1))) >> 31)) & 2)) - (v4555 + ((~(((v4556 ^ -1) | (-(v4556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4611[v4708] = v4612;
    int * v4615 = v4528->cache_vals;
    int v4711 = ((((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4552 + ((~(((v4554 ^ -1) | (-(v4554 ^ -1))) >> 31)) & 2)) - (v4555 + ((~(((v4556 ^ -1) | (-(v4556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4615[v4711] = v4613;
    int * v4617 = v4528->cache_tags;
    int v4714 = ((((int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4552 + ((~(((v4554 ^ -1) | (-(v4554 ^ -1))) >> 31)) & 2)) - (v4555 + ((~(((v4556 ^ -1) | (-(v4556 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4715 = (int)((unsigned int)((int)((unsigned int)(v4532 + 8) >> 2)) >> 1);
    v4617[v4714] = v4715;
    int * v4619 = v4528->cache_dirty;
    v4619[v4714] = 0;
    int * v4621 = v4528->cache_age;
    v4621[v4714] = 1;
    int * v4623 = v4528->cache_age;
    int v4624 = v4623[v4714];
    int v4625 = v4623[v4643];
    int v4721 = v4625 + ((int)((unsigned int)(v4625 - v4624) >> 31));
    v4623[v4643] = v4721;
    int * v4627 = v4528->cache_age;
    int v4628 = v4627[v4644];
    int v4723 = v4628 + ((int)((unsigned int)(v4628 - v4624) >> 31));
    v4627[v4644] = v4723;
    int * v4630 = v4528->cache_age;
    v4630[v4714] = 0;
    v4633 = v4714;
  }
  int v4726 = (v4633 * 2) + (((int)((unsigned int)(v4532 + 8) >> 2)) & 1);
  int v4634 = v4540[v4726];
  int * v4635 = v4528->regs;
  v4635[7] = v4634;
  struct StateT * v4637 = slot_18(v4528);
  return v4637;
}

struct StateT * slot_181(struct StateT * v21564) {
  int v21565 = v21564->timer;
  int v21572 = v21565 + 1;
  v21564->timer = v21572;
  int * v21567 = v21564->regs;
  int v21568 = v21567[6];
  int v21576 = (int)((unsigned int)v21568 >> 19);
  v21567[9] = v21576;
  struct StateT * v21570 = slot_182(v21564);
  return v21570;
}

struct StateT * slot_197(struct StateT * v21815) {
  int v21816 = v21815->timer;
  int v21824 = v21816 + 1;
  v21815->timer = v21824;
  int * v21818 = v21815->regs;
  int v21819 = v21818[11];
  int v21820 = v21818[9];
  int v21828 = v21819 | v21820;
  v21818[11] = v21828;
  struct StateT * v21822 = slot_198(v21815);
  return v21822;
}

struct StateT * slot_207(struct StateT * v21966) {
  int v21967 = v21966->timer;
  int v21975 = v21967 + 1;
  v21966->timer = v21975;
  int * v21969 = v21966->regs;
  int v21970 = v21969[21];
  int v21971 = v21969[11];
  int v21979 = v21970 ^ v21971;
  v21969[21] = v21979;
  struct StateT * v21973 = slot_208(v21966);
  return v21973;
}

struct StateT * slot_156(struct StateT * v21177) {
  int v21178 = v21177->timer;
  int v21185 = v21178 + 1;
  v21177->timer = v21185;
  int * v21180 = v21177->regs;
  int v21181 = v21180[11];
  int v21188 = v21181 << 9;
  v21180[11] = v21188;
  struct StateT * v21183 = slot_157(v21177);
  return v21183;
}

struct StateT * slot_154(struct StateT * v21145) {
  int v21146 = v21145->timer;
  int v21154 = v21146 + 1;
  v21145->timer = v21154;
  int * v21148 = v21145->regs;
  int v21149 = v21148[16];
  int v21150 = v21148[22];
  int v21159 = v21149 + v21150;
  v21148[8] = v21159;
  struct StateT * v21152 = slot_155(v21145);
  return v21152;
}

struct StateT * slot_68(struct StateT * v11289) {
  int v11290 = v11289->timer;
  int v11298 = v11290 + 1;
  v11289->timer = v11298;
  int * v11292 = v11289->regs;
  int v11293 = v11292[13];
  int v11294 = v11292[9];
  int v11302 = v11293 ^ v11294;
  v11292[13] = v11302;
  struct StateT * v11296 = slot_69(v11289);
  return v11296;
}

struct StateT * slot_260(struct StateT * v16965) {
  int v16966 = v16965->timer;
  int v17136 = v16966 + 1;
  v16965->timer = v17136;
  int * v16968 = v16965->regs;
  int v16969 = v16968[10];
  int v16970 = v16968[1];
  int * v16971 = v16965->cache_tags;
  int v17141 = (((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2;
  int v16972 = v16971[v17141];
  int v17142 = ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16973 = v16971[v17142];
  int v17143 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2);
  int v16974 = v16971[v17143];
  int v17144 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16975 = v16971[v17144];
  int v16976 = v16965->timer;
  int v17145 = v16976 + ((100 ^ (((~(((v16974 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16974 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16972 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16972 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v16973 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16973 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16974 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16974 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16965->timer = v17145;
  bool v17146 = !(((~(((v16972 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16972 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v16973 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16973 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31))) == 0);
  int v17070;
  if (v17146) {
    int * v16978 = v16965->cache_age;
    int v17148 = ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2) + ((~(((v16973 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16973 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) & 1);
    int v16979 = v16978[v17148];
    int v16980 = v16978[v17141];
    int v17149 = v16980 + ((int)((unsigned int)(v16980 - v16979) >> 31));
    v16978[v17141] = v17149;
    int * v16982 = v16965->cache_age;
    int v16983 = v16982[v17142];
    int v17151 = v16983 + ((int)((unsigned int)(v16983 - v16979) >> 31));
    v16982[v17142] = v17151;
    int * v16985 = v16965->cache_age;
    v16985[v17148] = 0;
    v17070 = v17148;
  } else {
    int * v16988 = v16965->cache_age;
    int v17155 = (((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2;
    int v16989 = v16988[v17155];
    int * v16990 = v16965->cache_tags;
    int v16991 = v16990[v17155];
    int v16992 = v16988[v17142];
    int v16993 = v16990[v17142];
    bool v17157 = !(((~(((v16974 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16974 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31))) == 0);
    int v17047;
    if (v17157) {
      int * v16994 = v16965->cache_age;
      int v17159 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v16975 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) & 1);
      int v16995 = v16994[v17159];
      int v16996 = v16994[v17143];
      int v17160 = v16996 + ((int)((unsigned int)(v16996 - v16995) >> 31));
      v16994[v17143] = v17160;
      int * v16998 = v16965->cache_age;
      int v16999 = v16998[v17144];
      int v17162 = v16999 + ((int)((unsigned int)(v16999 - v16995) >> 31));
      v16998[v17144] = v17162;
      int * v17001 = v16965->cache_age;
      v17001[v17159] = 0;
      v17047 = v17159;
    } else {
      int * v17004 = v16965->cache_age;
      int v17166 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2);
      int v17005 = v17004[v17166];
      int * v17006 = v16965->cache_tags;
      int v17007 = v17006[v17166];
      int v17008 = v17004[v17144];
      int v17009 = v17006[v17144];
      int * v17010 = v16965->cache_dirty;
      int v17169 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17005 + ((~(((v17007 ^ -1) | (-(v17007 ^ -1))) >> 31)) & 2)) - (v17008 + ((~(((v17009 ^ -1) | (-(v17009 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17011 = v17010[v17169];
      bool v17170 = !(v17011 == 0);
      if (v17170) {
        int * v17012 = v16965->cache_tags;
        int v17013 = v17012[v17169];
        int * v17014 = v16965->cache_vals;
        int v17173 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17005 + ((~(((v17007 ^ -1) | (-(v17007 ^ -1))) >> 31)) & 2)) - (v17008 + ((~(((v17009 ^ -1) | (-(v17009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17015 = v17014[v17173];
        int v17174 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17005 + ((~(((v17007 ^ -1) | (-(v17007 ^ -1))) >> 31)) & 2)) - (v17008 + ((~(((v17009 ^ -1) | (-(v17009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17016 = v17014[v17174];
        int * v17017 = v16965->mem;
        int v17176 = v17013 * 2;
        v17017[v17176] = v17015;
        int * v17019 = v16965->mem;
        int v17179 = (v17013 * 2) + 1;
        v17019[v17179] = v17016;
        ;
      } else {
        ;
      }
      int * v17024 = v16965->mem;
      int v17184 = ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) * 2;
      int v17025 = v17024[v17184];
      int v17185 = (((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) * 2) + 1;
      int v17026 = v17024[v17185];
      int * v17027 = v16965->cache_vals;
      int v17187 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17005 + ((~(((v17007 ^ -1) | (-(v17007 ^ -1))) >> 31)) & 2)) - (v17008 + ((~(((v17009 ^ -1) | (-(v17009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17027[v17187] = v17025;
      int * v17029 = v16965->cache_vals;
      int v17190 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17005 + ((~(((v17007 ^ -1) | (-(v17007 ^ -1))) >> 31)) & 2)) - (v17008 + ((~(((v17009 ^ -1) | (-(v17009 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17029[v17190] = v17026;
      int * v17031 = v16965->cache_tags;
      int v17193 = (int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1);
      v17031[v17169] = v17193;
      int * v17033 = v16965->cache_dirty;
      v17033[v17169] = 0;
      int * v17035 = v16965->cache_age;
      v17035[v17169] = 1;
      int * v17037 = v16965->cache_age;
      int v17038 = v17037[v17169];
      int v17039 = v17037[v17143];
      int v17198 = v17039 + ((int)((unsigned int)(v17039 - v17038) >> 31));
      v17037[v17143] = v17198;
      int * v17041 = v16965->cache_age;
      int v17042 = v17041[v17144];
      int v17200 = v17042 + ((int)((unsigned int)(v17042 - v17038) >> 31));
      v17041[v17144] = v17200;
      int * v17044 = v16965->cache_age;
      v17044[v17169] = 0;
      v17047 = v17169;
    }
    int * v17048 = v16965->cache_vals;
    int v17203 = v17047 * 2;
    int v17049 = v17048[v17203];
    int v17204 = (v17047 * 2) + 1;
    int v17050 = v17048[v17204];
    int v17205 = (((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v16989 + ((~(((v16991 ^ -1) | (-(v16991 ^ -1))) >> 31)) & 2)) - (v16992 + ((~(((v16993 ^ -1) | (-(v16993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17048[v17205] = v17049;
    int * v17052 = v16965->cache_vals;
    int v17208 = ((((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v16989 + ((~(((v16991 ^ -1) | (-(v16991 ^ -1))) >> 31)) & 2)) - (v16992 + ((~(((v16993 ^ -1) | (-(v16993 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17052[v17208] = v17050;
    int * v17054 = v16965->cache_tags;
    int v17211 = ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v16989 + ((~(((v16991 ^ -1) | (-(v16991 ^ -1))) >> 31)) & 2)) - (v16992 + ((~(((v16993 ^ -1) | (-(v16993 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17212 = (int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1);
    v17054[v17211] = v17212;
    int * v17056 = v16965->cache_dirty;
    v17056[v17211] = 0;
    int * v17058 = v16965->cache_age;
    v17058[v17211] = 1;
    int * v17060 = v16965->cache_age;
    int v17061 = v17060[v17211];
    int v17062 = v17060[v17141];
    int v17217 = v17062 + ((int)((unsigned int)(v17062 - v17061) >> 31));
    v17060[v17141] = v17217;
    int * v17064 = v16965->cache_age;
    int v17065 = v17064[v17142];
    int v17219 = v17065 + ((int)((unsigned int)(v17065 - v17061) >> 31));
    v17064[v17142] = v17219;
    int * v17067 = v16965->cache_age;
    v17067[v17211] = 0;
    v17070 = v17211;
  }
  int * v17071 = v16965->cache_vals;
  int v17222 = (v17070 * 2) + (((int)((unsigned int)(v16969 + 56) >> 2)) & 1);
  v17071[v17222] = v16970;
  int * v17073 = v16965->cache_tags;
  int v17074 = v17073[v17143];
  int v17075 = v17073[v17144];
  bool v17225 = !(((~(((v17074 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v17074 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v17075 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v17075 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31))) == 0);
  int v17129;
  if (v17225) {
    int * v17076 = v16965->cache_age;
    int v17227 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17075 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))) | (-(v17075 ^ ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1))))) >> 31)) & 1);
    int v17077 = v17076[v17227];
    int v17078 = v17076[v17143];
    int v17228 = v17078 + ((int)((unsigned int)(v17078 - v17077) >> 31));
    v17076[v17143] = v17228;
    int * v17080 = v16965->cache_age;
    int v17081 = v17080[v17144];
    int v17230 = v17081 + ((int)((unsigned int)(v17081 - v17077) >> 31));
    v17080[v17144] = v17230;
    int * v17083 = v16965->cache_age;
    v17083[v17227] = 0;
    v17129 = v17227;
  } else {
    int * v17086 = v16965->cache_age;
    int v17234 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2);
    int v17087 = v17086[v17234];
    int * v17088 = v16965->cache_tags;
    int v17089 = v17088[v17234];
    int v17090 = v17086[v17144];
    int v17091 = v17088[v17144];
    int * v17092 = v16965->cache_dirty;
    int v17237 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17087 + ((~(((v17089 ^ -1) | (-(v17089 ^ -1))) >> 31)) & 2)) - (v17090 + ((~(((v17091 ^ -1) | (-(v17091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17093 = v17092[v17237];
    bool v17238 = !(v17093 == 0);
    if (v17238) {
      int * v17094 = v16965->cache_tags;
      int v17095 = v17094[v17237];
      int * v17096 = v16965->cache_vals;
      int v17241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17087 + ((~(((v17089 ^ -1) | (-(v17089 ^ -1))) >> 31)) & 2)) - (v17090 + ((~(((v17091 ^ -1) | (-(v17091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v17097 = v17096[v17241];
      int v17242 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17087 + ((~(((v17089 ^ -1) | (-(v17089 ^ -1))) >> 31)) & 2)) - (v17090 + ((~(((v17091 ^ -1) | (-(v17091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v17098 = v17096[v17242];
      int * v17099 = v16965->mem;
      int v17244 = v17095 * 2;
      v17099[v17244] = v17097;
      int * v17101 = v16965->mem;
      int v17247 = (v17095 * 2) + 1;
      v17101[v17247] = v17098;
      ;
    } else {
      ;
    }
    int * v17106 = v16965->mem;
    int v17252 = ((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) * 2;
    int v17107 = v17106[v17252];
    int v17253 = (((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) * 2) + 1;
    int v17108 = v17106[v17253];
    int * v17109 = v16965->cache_vals;
    int v17255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17087 + ((~(((v17089 ^ -1) | (-(v17089 ^ -1))) >> 31)) & 2)) - (v17090 + ((~(((v17091 ^ -1) | (-(v17091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17109[v17255] = v17107;
    int * v17111 = v16965->cache_vals;
    int v17258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v17087 + ((~(((v17089 ^ -1) | (-(v17089 ^ -1))) >> 31)) & 2)) - (v17090 + ((~(((v17091 ^ -1) | (-(v17091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17111[v17258] = v17108;
    int * v17113 = v16965->cache_tags;
    int v17261 = (int)((unsigned int)((int)((unsigned int)(v16969 + 56) >> 2)) >> 1);
    v17113[v17237] = v17261;
    int * v17115 = v16965->cache_dirty;
    v17115[v17237] = 0;
    int * v17117 = v16965->cache_age;
    v17117[v17237] = 1;
    int * v17119 = v16965->cache_age;
    int v17120 = v17119[v17237];
    int v17121 = v17119[v17143];
    int v17266 = v17121 + ((int)((unsigned int)(v17121 - v17120) >> 31));
    v17119[v17143] = v17266;
    int * v17123 = v16965->cache_age;
    int v17124 = v17123[v17144];
    int v17268 = v17124 + ((int)((unsigned int)(v17124 - v17120) >> 31));
    v17123[v17144] = v17268;
    int * v17126 = v16965->cache_age;
    v17126[v17237] = 0;
    v17129 = v17237;
  }
  int * v17130 = v16965->cache_vals;
  int v17271 = (v17129 * 2) + (((int)((unsigned int)(v16969 + 56) >> 2)) & 1);
  v17130[v17271] = v16970;
  int * v17132 = v16965->cache_dirty;
  v17132[v17129] = 1;
  struct StateT * v17134 = slot_261(v16965);
  return v17134;
}

struct StateT * slot_105(struct StateT * v18920) {
  int v18921 = v18920->timer;
  int v18928 = v18921 + 1;
  v18920->timer = v18928;
  int * v18923 = v18920->regs;
  int v18924 = v18923[18];
  int v18931 = v18924 << 13;
  v18923[18] = v18931;
  struct StateT * v18926 = slot_106(v18920);
  return v18926;
}

struct StateT * slot_27(struct StateT * v6568) {
  int v6569 = v6568->timer;
  int v6575 = v6569 + 1;
  v6568->timer = v6575;
  int * v6571 = v6568->regs;
  v6571[12] = 1634762752;
  struct StateT * v6573 = slot_28(v6568);
  return v6573;
}

struct StateT * slot_164(struct StateT * v21297) {
  int v21298 = v21297->timer;
  int v21305 = v21298 + 1;
  v21297->timer = v21305;
  int * v21300 = v21297->regs;
  int v21301 = v21300[8];
  int v21309 = (int)((unsigned int)v21301 >> 23);
  v21300[9] = v21309;
  struct StateT * v21303 = slot_165(v21297);
  return v21303;
}

struct StateT * slot_15(struct StateT * v4120) {
  int v4121 = v4120->timer;
  int v4231 = v4121 + 1;
  v4120->timer = v4231;
  int * v4123 = v4120->regs;
  int v4124 = v4123[12];
  int * v4125 = v4120->cache_tags;
  int v4235 = (((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2;
  int v4126 = v4125[v4235];
  int v4236 = ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4127 = v4125[v4236];
  int v4237 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2);
  int v4128 = v4125[v4237];
  int v4238 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4129 = v4125[v4238];
  int v4130 = v4120->timer;
  int v4239 = v4130 + ((100 ^ (((~(((v4128 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4128 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) | (~(((v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4126 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4126 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) | (~(((v4127 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4127 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4128 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4128 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) | (~(((v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4120->timer = v4239;
  int * v4132 = v4120->cache_vals;
  bool v4240 = !(((~(((v4126 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4126 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) | (~(((v4127 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4127 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31))) == 0);
  int v4225;
  if (v4240) {
    int * v4133 = v4120->cache_age;
    int v4242 = ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2) + ((~(((v4127 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4127 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) & 1);
    int v4134 = v4133[v4242];
    int v4135 = v4133[v4235];
    int v4243 = v4135 + ((int)((unsigned int)(v4135 - v4134) >> 31));
    v4133[v4235] = v4243;
    int * v4137 = v4120->cache_age;
    int v4138 = v4137[v4236];
    int v4245 = v4138 + ((int)((unsigned int)(v4138 - v4134) >> 31));
    v4137[v4236] = v4245;
    int * v4140 = v4120->cache_age;
    v4140[v4242] = 0;
    v4225 = v4242;
  } else {
    int * v4143 = v4120->cache_age;
    int v4249 = (((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2;
    int v4144 = v4143[v4249];
    int * v4145 = v4120->cache_tags;
    int v4146 = v4145[v4249];
    int v4147 = v4143[v4236];
    int v4148 = v4145[v4236];
    bool v4251 = !(((~(((v4128 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4128 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) | (~(((v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31))) == 0);
    int v4202;
    if (v4251) {
      int * v4149 = v4120->cache_age;
      int v4253 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))) | (-(v4129 ^ ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1))))) >> 31)) & 1);
      int v4150 = v4149[v4253];
      int v4151 = v4149[v4237];
      int v4254 = v4151 + ((int)((unsigned int)(v4151 - v4150) >> 31));
      v4149[v4237] = v4254;
      int * v4153 = v4120->cache_age;
      int v4154 = v4153[v4238];
      int v4256 = v4154 + ((int)((unsigned int)(v4154 - v4150) >> 31));
      v4153[v4238] = v4256;
      int * v4156 = v4120->cache_age;
      v4156[v4253] = 0;
      v4202 = v4253;
    } else {
      int * v4159 = v4120->cache_age;
      int v4260 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2);
      int v4160 = v4159[v4260];
      int * v4161 = v4120->cache_tags;
      int v4162 = v4161[v4260];
      int v4163 = v4159[v4238];
      int v4164 = v4161[v4238];
      int * v4165 = v4120->cache_dirty;
      int v4263 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4166 = v4165[v4263];
      bool v4264 = !(v4166 == 0);
      if (v4264) {
        int * v4167 = v4120->cache_tags;
        int v4168 = v4167[v4263];
        int * v4169 = v4120->cache_vals;
        int v4267 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4170 = v4169[v4267];
        int v4268 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4171 = v4169[v4268];
        int * v4172 = v4120->mem;
        int v4270 = v4168 * 2;
        v4172[v4270] = v4170;
        int * v4174 = v4120->mem;
        int v4273 = (v4168 * 2) + 1;
        v4174[v4273] = v4171;
        ;
      } else {
        ;
      }
      int * v4179 = v4120->mem;
      int v4278 = ((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) * 2;
      int v4180 = v4179[v4278];
      int v4279 = (((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) * 2) + 1;
      int v4181 = v4179[v4279];
      int * v4182 = v4120->cache_vals;
      int v4281 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4182[v4281] = v4180;
      int * v4184 = v4120->cache_vals;
      int v4284 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4184[v4284] = v4181;
      int * v4186 = v4120->cache_tags;
      int v4287 = (int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1);
      v4186[v4263] = v4287;
      int * v4188 = v4120->cache_dirty;
      v4188[v4263] = 0;
      int * v4190 = v4120->cache_age;
      v4190[v4263] = 1;
      int * v4192 = v4120->cache_age;
      int v4193 = v4192[v4263];
      int v4194 = v4192[v4237];
      int v4293 = v4194 + ((int)((unsigned int)(v4194 - v4193) >> 31));
      v4192[v4237] = v4293;
      int * v4196 = v4120->cache_age;
      int v4197 = v4196[v4238];
      int v4295 = v4197 + ((int)((unsigned int)(v4197 - v4193) >> 31));
      v4196[v4238] = v4295;
      int * v4199 = v4120->cache_age;
      v4199[v4263] = 0;
      v4202 = v4263;
    }
    int * v4203 = v4120->cache_vals;
    int v4298 = v4202 * 2;
    int v4204 = v4203[v4298];
    int v4299 = (v4202 * 2) + 1;
    int v4205 = v4203[v4299];
    int v4300 = (((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2) + ((((v4144 + ((~(((v4146 ^ -1) | (-(v4146 ^ -1))) >> 31)) & 2)) - (v4147 + ((~(((v4148 ^ -1) | (-(v4148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4203[v4300] = v4204;
    int * v4207 = v4120->cache_vals;
    int v4303 = ((((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2) + ((((v4144 + ((~(((v4146 ^ -1) | (-(v4146 ^ -1))) >> 31)) & 2)) - (v4147 + ((~(((v4148 ^ -1) | (-(v4148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4207[v4303] = v4205;
    int * v4209 = v4120->cache_tags;
    int v4306 = ((((int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1)) & 1) * 2) + ((((v4144 + ((~(((v4146 ^ -1) | (-(v4146 ^ -1))) >> 31)) & 2)) - (v4147 + ((~(((v4148 ^ -1) | (-(v4148 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4307 = (int)((unsigned int)((int)((unsigned int)v4124 >> 2)) >> 1);
    v4209[v4306] = v4307;
    int * v4211 = v4120->cache_dirty;
    v4211[v4306] = 0;
    int * v4213 = v4120->cache_age;
    v4213[v4306] = 1;
    int * v4215 = v4120->cache_age;
    int v4216 = v4215[v4306];
    int v4217 = v4215[v4235];
    int v4313 = v4217 + ((int)((unsigned int)(v4217 - v4216) >> 31));
    v4215[v4235] = v4313;
    int * v4219 = v4120->cache_age;
    int v4220 = v4219[v4236];
    int v4315 = v4220 + ((int)((unsigned int)(v4220 - v4216) >> 31));
    v4219[v4236] = v4315;
    int * v4222 = v4120->cache_age;
    v4222[v4306] = 0;
    v4225 = v4306;
  }
  int v4318 = (v4225 * 2) + (((int)((unsigned int)v4124 >> 2)) & 1);
  int v4226 = v4132[v4318];
  int * v4227 = v4120->regs;
  v4227[29] = v4226;
  struct StateT * v4229 = slot_16(v4120);
  return v4229;
}

struct StateT * slot_133(struct StateT * v20812) {
  int v20813 = v20812->timer;
  int v20821 = v20813 + 1;
  v20812->timer = v20821;
  int * v20815 = v20812->regs;
  int v20816 = v20815[19];
  int v20817 = v20815[13];
  int v20826 = v20816 + v20817;
  v20815[16] = v20826;
  struct StateT * v20819 = slot_134(v20812);
  return v20819;
}

struct StateT * slot_56(struct StateT * v9982) {
  int v9983 = v9982->timer;
  int v9990 = v9983 + 1;
  v9982->timer = v9990;
  int * v9985 = v9982->regs;
  int v9986 = v9985[15];
  int v9993 = v9986 << 7;
  v9985[15] = v9993;
  struct StateT * v9988 = slot_57(v9982);
  return v9988;
}

struct StateT * slot_244(struct StateT * v12271) {
  int v12272 = v12271->timer;
  int v12280 = v12272 + 1;
  v12271->timer = v12280;
  int * v12274 = v12271->regs;
  int v12275 = v12274[19];
  int v12276 = v12274[7];
  int v12284 = v12275 + v12276;
  v12274[7] = v12284;
  struct StateT * v12278 = slot_245(v12271);
  return v12278;
}

struct StateT * slot_222(struct StateT * v10274) {
  int v10275 = v10274->timer;
  int v10385 = v10275 + 1;
  v10274->timer = v10385;
  int * v10277 = v10274->regs;
  int v10278 = v10277[2];
  int * v10279 = v10274->cache_tags;
  int v10389 = (((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2;
  int v10280 = v10279[v10389];
  int v10390 = ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10281 = v10279[v10390];
  int v10391 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2);
  int v10282 = v10279[v10391];
  int v10392 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10283 = v10279[v10392];
  int v10284 = v10274->timer;
  int v10393 = v10284 + ((100 ^ (((~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10274->timer = v10393;
  int * v10286 = v10274->cache_vals;
  bool v10394 = !(((~(((v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10280 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v10379;
  if (v10394) {
    int * v10287 = v10274->cache_age;
    int v10396 = ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10281 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v10288 = v10287[v10396];
    int v10289 = v10287[v10389];
    int v10397 = v10289 + ((int)((unsigned int)(v10289 - v10288) >> 31));
    v10287[v10389] = v10397;
    int * v10291 = v10274->cache_age;
    int v10292 = v10291[v10390];
    int v10399 = v10292 + ((int)((unsigned int)(v10292 - v10288) >> 31));
    v10291[v10390] = v10399;
    int * v10294 = v10274->cache_age;
    v10294[v10396] = 0;
    v10379 = v10396;
  } else {
    int * v10297 = v10274->cache_age;
    int v10403 = (((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2;
    int v10298 = v10297[v10403];
    int * v10299 = v10274->cache_tags;
    int v10300 = v10299[v10403];
    int v10301 = v10297[v10390];
    int v10302 = v10299[v10390];
    bool v10405 = !(((~(((v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10282 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v10356;
    if (v10405) {
      int * v10303 = v10274->cache_age;
      int v10407 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))) | (-(v10283 ^ ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v10304 = v10303[v10407];
      int v10305 = v10303[v10391];
      int v10408 = v10305 + ((int)((unsigned int)(v10305 - v10304) >> 31));
      v10303[v10391] = v10408;
      int * v10307 = v10274->cache_age;
      int v10308 = v10307[v10392];
      int v10410 = v10308 + ((int)((unsigned int)(v10308 - v10304) >> 31));
      v10307[v10392] = v10410;
      int * v10310 = v10274->cache_age;
      v10310[v10407] = 0;
      v10356 = v10407;
    } else {
      int * v10313 = v10274->cache_age;
      int v10414 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2);
      int v10314 = v10313[v10414];
      int * v10315 = v10274->cache_tags;
      int v10316 = v10315[v10414];
      int v10317 = v10313[v10392];
      int v10318 = v10315[v10392];
      int * v10319 = v10274->cache_dirty;
      int v10417 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10314 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2)) - (v10317 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10320 = v10319[v10417];
      bool v10418 = !(v10320 == 0);
      if (v10418) {
        int * v10321 = v10274->cache_tags;
        int v10322 = v10321[v10417];
        int * v10323 = v10274->cache_vals;
        int v10421 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10314 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2)) - (v10317 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10324 = v10323[v10421];
        int v10422 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10314 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2)) - (v10317 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10325 = v10323[v10422];
        int * v10326 = v10274->mem;
        int v10424 = v10322 * 2;
        v10326[v10424] = v10324;
        int * v10328 = v10274->mem;
        int v10427 = (v10322 * 2) + 1;
        v10328[v10427] = v10325;
        ;
      } else {
        ;
      }
      int * v10333 = v10274->mem;
      int v10432 = ((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) * 2;
      int v10334 = v10333[v10432];
      int v10433 = (((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) * 2) + 1;
      int v10335 = v10333[v10433];
      int * v10336 = v10274->cache_vals;
      int v10435 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10314 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2)) - (v10317 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10336[v10435] = v10334;
      int * v10338 = v10274->cache_vals;
      int v10438 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10314 + ((~(((v10316 ^ -1) | (-(v10316 ^ -1))) >> 31)) & 2)) - (v10317 + ((~(((v10318 ^ -1) | (-(v10318 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10338[v10438] = v10335;
      int * v10340 = v10274->cache_tags;
      int v10441 = (int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1);
      v10340[v10417] = v10441;
      int * v10342 = v10274->cache_dirty;
      v10342[v10417] = 0;
      int * v10344 = v10274->cache_age;
      v10344[v10417] = 1;
      int * v10346 = v10274->cache_age;
      int v10347 = v10346[v10417];
      int v10348 = v10346[v10391];
      int v10447 = v10348 + ((int)((unsigned int)(v10348 - v10347) >> 31));
      v10346[v10391] = v10447;
      int * v10350 = v10274->cache_age;
      int v10351 = v10350[v10392];
      int v10449 = v10351 + ((int)((unsigned int)(v10351 - v10347) >> 31));
      v10350[v10392] = v10449;
      int * v10353 = v10274->cache_age;
      v10353[v10417] = 0;
      v10356 = v10417;
    }
    int * v10357 = v10274->cache_vals;
    int v10452 = v10356 * 2;
    int v10358 = v10357[v10452];
    int v10453 = (v10356 * 2) + 1;
    int v10359 = v10357[v10453];
    int v10454 = (((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10298 + ((~(((v10300 ^ -1) | (-(v10300 ^ -1))) >> 31)) & 2)) - (v10301 + ((~(((v10302 ^ -1) | (-(v10302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10357[v10454] = v10358;
    int * v10361 = v10274->cache_vals;
    int v10457 = ((((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10298 + ((~(((v10300 ^ -1) | (-(v10300 ^ -1))) >> 31)) & 2)) - (v10301 + ((~(((v10302 ^ -1) | (-(v10302 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10361[v10457] = v10359;
    int * v10363 = v10274->cache_tags;
    int v10460 = ((((int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10298 + ((~(((v10300 ^ -1) | (-(v10300 ^ -1))) >> 31)) & 2)) - (v10301 + ((~(((v10302 ^ -1) | (-(v10302 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10461 = (int)((unsigned int)((int)((unsigned int)(v10278 + 16) >> 2)) >> 1);
    v10363[v10460] = v10461;
    int * v10365 = v10274->cache_dirty;
    v10365[v10460] = 0;
    int * v10367 = v10274->cache_age;
    v10367[v10460] = 1;
    int * v10369 = v10274->cache_age;
    int v10370 = v10369[v10460];
    int v10371 = v10369[v10389];
    int v10467 = v10371 + ((int)((unsigned int)(v10371 - v10370) >> 31));
    v10369[v10389] = v10467;
    int * v10373 = v10274->cache_age;
    int v10374 = v10373[v10390];
    int v10469 = v10374 + ((int)((unsigned int)(v10374 - v10370) >> 31));
    v10373[v10390] = v10469;
    int * v10376 = v10274->cache_age;
    v10376[v10460] = 0;
    v10379 = v10460;
  }
  int v10472 = (v10379 * 2) + (((int)((unsigned int)(v10278 + 16) >> 2)) & 1);
  int v10380 = v10286[v10472];
  int * v10381 = v10274->regs;
  v10381[7] = v10380;
  struct StateT * v10383 = slot_223(v10274);
  return v10383;
}

struct StateT * slot_34(struct StateT * v6665) {
  int v6666 = v6665->timer;
  int v6673 = v6666 + 1;
  v6665->timer = v6673;
  int * v6668 = v6665->regs;
  int v6669 = v6668[22];
  int v6676 = v6669 + 1396;
  v6668[22] = v6676;
  struct StateT * v6671 = slot_35(v6665);
  return v6671;
}

struct StateT * slot_171(struct StateT * v21406) {
  int v21407 = v21406->timer;
  int v21415 = v21407 + 1;
  v21406->timer = v21415;
  int * v21409 = v21406->regs;
  int v21410 = v21409[27];
  int v21411 = v21409[23];
  int v21420 = v21410 + v21411;
  v21409[11] = v21420;
  struct StateT * v21413 = slot_172(v21406);
  return v21413;
}

struct StateT * slot_162(struct StateT * v21267) {
  int v21268 = v21267->timer;
  int v21275 = v21268 + 1;
  v21267->timer = v21275;
  int * v21270 = v21267->regs;
  int v21271 = v21270[6];
  int v21278 = v21271 << 9;
  v21270[6] = v21278;
  struct StateT * v21273 = slot_163(v21267);
  return v21273;
}

struct StateT * slot_21(struct StateT * v5344) {
  int v5345 = v5344->timer;
  int v5455 = v5345 + 1;
  v5344->timer = v5455;
  int * v5347 = v5344->regs;
  int v5348 = v5347[12];
  int * v5349 = v5344->cache_tags;
  int v5459 = (((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2;
  int v5350 = v5349[v5459];
  int v5460 = ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5351 = v5349[v5460];
  int v5461 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2);
  int v5352 = v5349[v5461];
  int v5462 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5353 = v5349[v5462];
  int v5354 = v5344->timer;
  int v5463 = v5354 + ((100 ^ (((~(((v5352 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5352 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5350 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5350 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5351 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5351 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5352 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5352 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5344->timer = v5463;
  int * v5356 = v5344->cache_vals;
  bool v5464 = !(((~(((v5350 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5350 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5351 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5351 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5449;
  if (v5464) {
    int * v5357 = v5344->cache_age;
    int v5466 = ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v5351 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5351 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5358 = v5357[v5466];
    int v5359 = v5357[v5459];
    int v5467 = v5359 + ((int)((unsigned int)(v5359 - v5358) >> 31));
    v5357[v5459] = v5467;
    int * v5361 = v5344->cache_age;
    int v5362 = v5361[v5460];
    int v5469 = v5362 + ((int)((unsigned int)(v5362 - v5358) >> 31));
    v5361[v5460] = v5469;
    int * v5364 = v5344->cache_age;
    v5364[v5466] = 0;
    v5449 = v5466;
  } else {
    int * v5367 = v5344->cache_age;
    int v5473 = (((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2;
    int v5368 = v5367[v5473];
    int * v5369 = v5344->cache_tags;
    int v5370 = v5369[v5473];
    int v5371 = v5367[v5460];
    int v5372 = v5369[v5460];
    bool v5475 = !(((~(((v5352 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5352 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v5426;
    if (v5475) {
      int * v5373 = v5344->cache_age;
      int v5477 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))) | (-(v5353 ^ ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v5374 = v5373[v5477];
      int v5375 = v5373[v5461];
      int v5478 = v5375 + ((int)((unsigned int)(v5375 - v5374) >> 31));
      v5373[v5461] = v5478;
      int * v5377 = v5344->cache_age;
      int v5378 = v5377[v5462];
      int v5480 = v5378 + ((int)((unsigned int)(v5378 - v5374) >> 31));
      v5377[v5462] = v5480;
      int * v5380 = v5344->cache_age;
      v5380[v5477] = 0;
      v5426 = v5477;
    } else {
      int * v5383 = v5344->cache_age;
      int v5484 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2);
      int v5384 = v5383[v5484];
      int * v5385 = v5344->cache_tags;
      int v5386 = v5385[v5484];
      int v5387 = v5383[v5462];
      int v5388 = v5385[v5462];
      int * v5389 = v5344->cache_dirty;
      int v5487 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5384 + ((~(((v5386 ^ -1) | (-(v5386 ^ -1))) >> 31)) & 2)) - (v5387 + ((~(((v5388 ^ -1) | (-(v5388 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5390 = v5389[v5487];
      bool v5488 = !(v5390 == 0);
      if (v5488) {
        int * v5391 = v5344->cache_tags;
        int v5392 = v5391[v5487];
        int * v5393 = v5344->cache_vals;
        int v5491 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5384 + ((~(((v5386 ^ -1) | (-(v5386 ^ -1))) >> 31)) & 2)) - (v5387 + ((~(((v5388 ^ -1) | (-(v5388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5394 = v5393[v5491];
        int v5492 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5384 + ((~(((v5386 ^ -1) | (-(v5386 ^ -1))) >> 31)) & 2)) - (v5387 + ((~(((v5388 ^ -1) | (-(v5388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5395 = v5393[v5492];
        int * v5396 = v5344->mem;
        int v5494 = v5392 * 2;
        v5396[v5494] = v5394;
        int * v5398 = v5344->mem;
        int v5497 = (v5392 * 2) + 1;
        v5398[v5497] = v5395;
        ;
      } else {
        ;
      }
      int * v5403 = v5344->mem;
      int v5502 = ((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) * 2;
      int v5404 = v5403[v5502];
      int v5503 = (((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) * 2) + 1;
      int v5405 = v5403[v5503];
      int * v5406 = v5344->cache_vals;
      int v5505 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5384 + ((~(((v5386 ^ -1) | (-(v5386 ^ -1))) >> 31)) & 2)) - (v5387 + ((~(((v5388 ^ -1) | (-(v5388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5406[v5505] = v5404;
      int * v5408 = v5344->cache_vals;
      int v5508 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5384 + ((~(((v5386 ^ -1) | (-(v5386 ^ -1))) >> 31)) & 2)) - (v5387 + ((~(((v5388 ^ -1) | (-(v5388 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5408[v5508] = v5405;
      int * v5410 = v5344->cache_tags;
      int v5511 = (int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1);
      v5410[v5487] = v5511;
      int * v5412 = v5344->cache_dirty;
      v5412[v5487] = 0;
      int * v5414 = v5344->cache_age;
      v5414[v5487] = 1;
      int * v5416 = v5344->cache_age;
      int v5417 = v5416[v5487];
      int v5418 = v5416[v5461];
      int v5517 = v5418 + ((int)((unsigned int)(v5418 - v5417) >> 31));
      v5416[v5461] = v5517;
      int * v5420 = v5344->cache_age;
      int v5421 = v5420[v5462];
      int v5519 = v5421 + ((int)((unsigned int)(v5421 - v5417) >> 31));
      v5420[v5462] = v5519;
      int * v5423 = v5344->cache_age;
      v5423[v5487] = 0;
      v5426 = v5487;
    }
    int * v5427 = v5344->cache_vals;
    int v5522 = v5426 * 2;
    int v5428 = v5427[v5522];
    int v5523 = (v5426 * 2) + 1;
    int v5429 = v5427[v5523];
    int v5524 = (((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5368 + ((~(((v5370 ^ -1) | (-(v5370 ^ -1))) >> 31)) & 2)) - (v5371 + ((~(((v5372 ^ -1) | (-(v5372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5427[v5524] = v5428;
    int * v5431 = v5344->cache_vals;
    int v5527 = ((((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5368 + ((~(((v5370 ^ -1) | (-(v5370 ^ -1))) >> 31)) & 2)) - (v5371 + ((~(((v5372 ^ -1) | (-(v5372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5431[v5527] = v5429;
    int * v5433 = v5344->cache_tags;
    int v5530 = ((((int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5368 + ((~(((v5370 ^ -1) | (-(v5370 ^ -1))) >> 31)) & 2)) - (v5371 + ((~(((v5372 ^ -1) | (-(v5372 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5531 = (int)((unsigned int)((int)((unsigned int)(v5348 + 24) >> 2)) >> 1);
    v5433[v5530] = v5531;
    int * v5435 = v5344->cache_dirty;
    v5435[v5530] = 0;
    int * v5437 = v5344->cache_age;
    v5437[v5530] = 1;
    int * v5439 = v5344->cache_age;
    int v5440 = v5439[v5530];
    int v5441 = v5439[v5459];
    int v5537 = v5441 + ((int)((unsigned int)(v5441 - v5440) >> 31));
    v5439[v5459] = v5537;
    int * v5443 = v5344->cache_age;
    int v5444 = v5443[v5460];
    int v5539 = v5444 + ((int)((unsigned int)(v5444 - v5440) >> 31));
    v5443[v5460] = v5539;
    int * v5446 = v5344->cache_age;
    v5446[v5530] = 0;
    v5449 = v5530;
  }
  int v5542 = (v5449 * 2) + (((int)((unsigned int)(v5348 + 24) >> 2)) & 1);
  int v5450 = v5356[v5542];
  int * v5451 = v5344->regs;
  v5451[24] = v5450;
  struct StateT * v5453 = slot_22(v5344);
  return v5453;
}

struct StateT * slot_239(struct StateT * v12121) {
  int v12122 = v12121->timer;
  int v12129 = v12122 + 1;
  v12121->timer = v12129;
  int * v12124 = v12121->regs;
  int v12125 = v12124[6];
  int v12132 = v12125 + 1134;
  v12124[6] = v12132;
  struct StateT * v12127 = slot_240(v12121);
  return v12127;
}

struct StateT * slot_118(struct StateT * v20578) {
  int v20579 = v20578->timer;
  int v20586 = v20579 + 1;
  v20578->timer = v20586;
  int * v20581 = v20578->regs;
  int v20582 = v20581[16];
  int v20590 = (int)((unsigned int)v20582 >> 14);
  v20581[6] = v20590;
  struct StateT * v20584 = slot_119(v20578);
  return v20584;
}

struct StateT * slot_121(struct StateT * v20623) {
  int v20624 = v20623->timer;
  int v20631 = v20624 + 1;
  v20623->timer = v20631;
  int * v20626 = v20623->regs;
  int v20627 = v20626[17];
  int v20635 = (int)((unsigned int)v20627 >> 14);
  v20626[6] = v20635;
  struct StateT * v20629 = slot_122(v20623);
  return v20629;
}

struct StateT * slot_144(struct StateT * v20981) {
  int v20982 = v20981->timer;
  int v20989 = v20982 + 1;
  v20981->timer = v20989;
  int * v20984 = v20981->regs;
  int v20985 = v20984[17];
  int v20993 = (int)((unsigned int)v20985 >> 25);
  v20984[5] = v20993;
  struct StateT * v20987 = slot_145(v20981);
  return v20987;
}

struct StateT * slot_267(struct StateT * v18716) {
  int v18717 = v18716->timer;
  int v18827 = v18717 + 1;
  v18716->timer = v18827;
  int * v18719 = v18716->regs;
  int v18720 = v18719[2];
  int * v18721 = v18716->cache_tags;
  int v18831 = (((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2;
  int v18722 = v18721[v18831];
  int v18832 = ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18723 = v18721[v18832];
  int v18833 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2);
  int v18724 = v18721[v18833];
  int v18834 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18725 = v18721[v18834];
  int v18726 = v18716->timer;
  int v18835 = v18726 + ((100 ^ (((~(((v18724 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18724 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18722 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18722 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v18723 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18723 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18724 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18724 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18716->timer = v18835;
  int * v18728 = v18716->cache_vals;
  bool v18836 = !(((~(((v18722 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18722 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v18723 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18723 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31))) == 0);
  int v18821;
  if (v18836) {
    int * v18729 = v18716->cache_age;
    int v18838 = ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2) + ((~(((v18723 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18723 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) & 1);
    int v18730 = v18729[v18838];
    int v18731 = v18729[v18831];
    int v18839 = v18731 + ((int)((unsigned int)(v18731 - v18730) >> 31));
    v18729[v18831] = v18839;
    int * v18733 = v18716->cache_age;
    int v18734 = v18733[v18832];
    int v18841 = v18734 + ((int)((unsigned int)(v18734 - v18730) >> 31));
    v18733[v18832] = v18841;
    int * v18736 = v18716->cache_age;
    v18736[v18838] = 0;
    v18821 = v18838;
  } else {
    int * v18739 = v18716->cache_age;
    int v18845 = (((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2;
    int v18740 = v18739[v18845];
    int * v18741 = v18716->cache_tags;
    int v18742 = v18741[v18845];
    int v18743 = v18739[v18832];
    int v18744 = v18741[v18832];
    bool v18847 = !(((~(((v18724 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18724 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31))) == 0);
    int v18798;
    if (v18847) {
      int * v18745 = v18716->cache_age;
      int v18849 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))) | (-(v18725 ^ ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1))))) >> 31)) & 1);
      int v18746 = v18745[v18849];
      int v18747 = v18745[v18833];
      int v18850 = v18747 + ((int)((unsigned int)(v18747 - v18746) >> 31));
      v18745[v18833] = v18850;
      int * v18749 = v18716->cache_age;
      int v18750 = v18749[v18834];
      int v18852 = v18750 + ((int)((unsigned int)(v18750 - v18746) >> 31));
      v18749[v18834] = v18852;
      int * v18752 = v18716->cache_age;
      v18752[v18849] = 0;
      v18798 = v18849;
    } else {
      int * v18755 = v18716->cache_age;
      int v18856 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2);
      int v18756 = v18755[v18856];
      int * v18757 = v18716->cache_tags;
      int v18758 = v18757[v18856];
      int v18759 = v18755[v18834];
      int v18760 = v18757[v18834];
      int * v18761 = v18716->cache_dirty;
      int v18859 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v18756 + ((~(((v18758 ^ -1) | (-(v18758 ^ -1))) >> 31)) & 2)) - (v18759 + ((~(((v18760 ^ -1) | (-(v18760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18762 = v18761[v18859];
      bool v18860 = !(v18762 == 0);
      if (v18860) {
        int * v18763 = v18716->cache_tags;
        int v18764 = v18763[v18859];
        int * v18765 = v18716->cache_vals;
        int v18863 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v18756 + ((~(((v18758 ^ -1) | (-(v18758 ^ -1))) >> 31)) & 2)) - (v18759 + ((~(((v18760 ^ -1) | (-(v18760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18766 = v18765[v18863];
        int v18864 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v18756 + ((~(((v18758 ^ -1) | (-(v18758 ^ -1))) >> 31)) & 2)) - (v18759 + ((~(((v18760 ^ -1) | (-(v18760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18767 = v18765[v18864];
        int * v18768 = v18716->mem;
        int v18866 = v18764 * 2;
        v18768[v18866] = v18766;
        int * v18770 = v18716->mem;
        int v18869 = (v18764 * 2) + 1;
        v18770[v18869] = v18767;
        ;
      } else {
        ;
      }
      int * v18775 = v18716->mem;
      int v18874 = ((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) * 2;
      int v18776 = v18775[v18874];
      int v18875 = (((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) * 2) + 1;
      int v18777 = v18775[v18875];
      int * v18778 = v18716->cache_vals;
      int v18877 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v18756 + ((~(((v18758 ^ -1) | (-(v18758 ^ -1))) >> 31)) & 2)) - (v18759 + ((~(((v18760 ^ -1) | (-(v18760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18778[v18877] = v18776;
      int * v18780 = v18716->cache_vals;
      int v18880 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v18756 + ((~(((v18758 ^ -1) | (-(v18758 ^ -1))) >> 31)) & 2)) - (v18759 + ((~(((v18760 ^ -1) | (-(v18760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18780[v18880] = v18777;
      int * v18782 = v18716->cache_tags;
      int v18883 = (int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1);
      v18782[v18859] = v18883;
      int * v18784 = v18716->cache_dirty;
      v18784[v18859] = 0;
      int * v18786 = v18716->cache_age;
      v18786[v18859] = 1;
      int * v18788 = v18716->cache_age;
      int v18789 = v18788[v18859];
      int v18790 = v18788[v18833];
      int v18889 = v18790 + ((int)((unsigned int)(v18790 - v18789) >> 31));
      v18788[v18833] = v18889;
      int * v18792 = v18716->cache_age;
      int v18793 = v18792[v18834];
      int v18891 = v18793 + ((int)((unsigned int)(v18793 - v18789) >> 31));
      v18792[v18834] = v18891;
      int * v18795 = v18716->cache_age;
      v18795[v18859] = 0;
      v18798 = v18859;
    }
    int * v18799 = v18716->cache_vals;
    int v18894 = v18798 * 2;
    int v18800 = v18799[v18894];
    int v18895 = (v18798 * 2) + 1;
    int v18801 = v18799[v18895];
    int v18896 = (((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2) + ((((v18740 + ((~(((v18742 ^ -1) | (-(v18742 ^ -1))) >> 31)) & 2)) - (v18743 + ((~(((v18744 ^ -1) | (-(v18744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18799[v18896] = v18800;
    int * v18803 = v18716->cache_vals;
    int v18899 = ((((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2) + ((((v18740 + ((~(((v18742 ^ -1) | (-(v18742 ^ -1))) >> 31)) & 2)) - (v18743 + ((~(((v18744 ^ -1) | (-(v18744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18803[v18899] = v18801;
    int * v18805 = v18716->cache_tags;
    int v18902 = ((((int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1)) & 1) * 2) + ((((v18740 + ((~(((v18742 ^ -1) | (-(v18742 ^ -1))) >> 31)) & 2)) - (v18743 + ((~(((v18744 ^ -1) | (-(v18744 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18903 = (int)((unsigned int)((int)((unsigned int)(v18720 + 72) >> 2)) >> 1);
    v18805[v18902] = v18903;
    int * v18807 = v18716->cache_dirty;
    v18807[v18902] = 0;
    int * v18809 = v18716->cache_age;
    v18809[v18902] = 1;
    int * v18811 = v18716->cache_age;
    int v18812 = v18811[v18902];
    int v18813 = v18811[v18831];
    int v18909 = v18813 + ((int)((unsigned int)(v18813 - v18812) >> 31));
    v18811[v18831] = v18909;
    int * v18815 = v18716->cache_age;
    int v18816 = v18815[v18832];
    int v18911 = v18816 + ((int)((unsigned int)(v18816 - v18812) >> 31));
    v18815[v18832] = v18911;
    int * v18818 = v18716->cache_age;
    v18818[v18902] = 0;
    v18821 = v18902;
  }
  int v18914 = (v18821 * 2) + (((int)((unsigned int)(v18720 + 72) >> 2)) & 1);
  int v18822 = v18728[v18914];
  int * v18823 = v18716->regs;
  v18823[20] = v18822;
  struct StateT * v18825 = slot_268(v18716);
  return v18825;
}

struct StateT * slot_201(struct StateT * v21876) {
  int v21877 = v21876->timer;
  int v21884 = v21877 + 1;
  v21876->timer = v21884;
  int * v21879 = v21876->regs;
  int v21880 = v21879[6];
  int v21888 = (int)((unsigned int)v21880 >> 14);
  v21879[9] = v21888;
  struct StateT * v21882 = slot_202(v21876);
  return v21882;
}

struct StateT * slot_94(struct StateT * v15958) {
  int v15959 = v15958->timer;
  int v15967 = v15959 + 1;
  v15958->timer = v15967;
  int * v15961 = v15958->regs;
  int v15962 = v15961[25];
  int v15963 = v15961[14];
  int v15972 = v15962 + v15963;
  v15961[18] = v15972;
  struct StateT * v15965 = slot_95(v15958);
  return v15965;
}

struct StateT * slot_63(struct StateT * v10759) {
  int v10760 = v10759->timer;
  int v10768 = v10760 + 1;
  v10759->timer = v10768;
  int * v10762 = v10759->regs;
  int v10763 = v10762[18];
  int v10764 = v10762[20];
  int v10772 = v10763 | v10764;
  v10762[18] = v10772;
  struct StateT * v10766 = slot_64(v10759);
  return v10766;
}

struct StateT * slot_146(struct StateT * v21010) {
  int v21011 = v21010->timer;
  int v21019 = v21011 + 1;
  v21010->timer = v21019;
  int * v21013 = v21010->regs;
  int v21014 = v21013[17];
  int v21015 = v21013[5];
  int v21024 = v21014 | v21015;
  v21013[6] = v21024;
  struct StateT * v21017 = slot_147(v21010);
  return v21017;
}

struct StateT * slot_24(struct StateT * v5956) {
  int v5957 = v5956->timer;
  int v6067 = v5957 + 1;
  v5956->timer = v6067;
  int * v5959 = v5956->regs;
  int v5960 = v5959[11];
  int * v5961 = v5956->cache_tags;
  int v6071 = (((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2;
  int v5962 = v5961[v6071];
  int v6072 = ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5963 = v5961[v6072];
  int v6073 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2);
  int v5964 = v5961[v6073];
  int v6074 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5965 = v5961[v6074];
  int v5966 = v5956->timer;
  int v6075 = v5966 + ((100 ^ (((~(((v5964 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5964 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5962 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5962 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5963 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5963 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5964 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5964 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5956->timer = v6075;
  int * v5968 = v5956->cache_vals;
  bool v6076 = !(((~(((v5962 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5962 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5963 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5963 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v6061;
  if (v6076) {
    int * v5969 = v5956->cache_age;
    int v6078 = ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v5963 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5963 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5970 = v5969[v6078];
    int v5971 = v5969[v6071];
    int v6079 = v5971 + ((int)((unsigned int)(v5971 - v5970) >> 31));
    v5969[v6071] = v6079;
    int * v5973 = v5956->cache_age;
    int v5974 = v5973[v6072];
    int v6081 = v5974 + ((int)((unsigned int)(v5974 - v5970) >> 31));
    v5973[v6072] = v6081;
    int * v5976 = v5956->cache_age;
    v5976[v6078] = 0;
    v6061 = v6078;
  } else {
    int * v5979 = v5956->cache_age;
    int v6085 = (((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2;
    int v5980 = v5979[v6085];
    int * v5981 = v5956->cache_tags;
    int v5982 = v5981[v6085];
    int v5983 = v5979[v6072];
    int v5984 = v5981[v6072];
    bool v6087 = !(((~(((v5964 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5964 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v6038;
    if (v6087) {
      int * v5985 = v5956->cache_age;
      int v6089 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))) | (-(v5965 ^ ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v5986 = v5985[v6089];
      int v5987 = v5985[v6073];
      int v6090 = v5987 + ((int)((unsigned int)(v5987 - v5986) >> 31));
      v5985[v6073] = v6090;
      int * v5989 = v5956->cache_age;
      int v5990 = v5989[v6074];
      int v6092 = v5990 + ((int)((unsigned int)(v5990 - v5986) >> 31));
      v5989[v6074] = v6092;
      int * v5992 = v5956->cache_age;
      v5992[v6089] = 0;
      v6038 = v6089;
    } else {
      int * v5995 = v5956->cache_age;
      int v6096 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2);
      int v5996 = v5995[v6096];
      int * v5997 = v5956->cache_tags;
      int v5998 = v5997[v6096];
      int v5999 = v5995[v6074];
      int v6000 = v5997[v6074];
      int * v6001 = v5956->cache_dirty;
      int v6099 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5996 + ((~(((v5998 ^ -1) | (-(v5998 ^ -1))) >> 31)) & 2)) - (v5999 + ((~(((v6000 ^ -1) | (-(v6000 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6002 = v6001[v6099];
      bool v6100 = !(v6002 == 0);
      if (v6100) {
        int * v6003 = v5956->cache_tags;
        int v6004 = v6003[v6099];
        int * v6005 = v5956->cache_vals;
        int v6103 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5996 + ((~(((v5998 ^ -1) | (-(v5998 ^ -1))) >> 31)) & 2)) - (v5999 + ((~(((v6000 ^ -1) | (-(v6000 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6006 = v6005[v6103];
        int v6104 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5996 + ((~(((v5998 ^ -1) | (-(v5998 ^ -1))) >> 31)) & 2)) - (v5999 + ((~(((v6000 ^ -1) | (-(v6000 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6007 = v6005[v6104];
        int * v6008 = v5956->mem;
        int v6106 = v6004 * 2;
        v6008[v6106] = v6006;
        int * v6010 = v5956->mem;
        int v6109 = (v6004 * 2) + 1;
        v6010[v6109] = v6007;
        ;
      } else {
        ;
      }
      int * v6015 = v5956->mem;
      int v6114 = ((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) * 2;
      int v6016 = v6015[v6114];
      int v6115 = (((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) * 2) + 1;
      int v6017 = v6015[v6115];
      int * v6018 = v5956->cache_vals;
      int v6117 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5996 + ((~(((v5998 ^ -1) | (-(v5998 ^ -1))) >> 31)) & 2)) - (v5999 + ((~(((v6000 ^ -1) | (-(v6000 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6018[v6117] = v6016;
      int * v6020 = v5956->cache_vals;
      int v6120 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5996 + ((~(((v5998 ^ -1) | (-(v5998 ^ -1))) >> 31)) & 2)) - (v5999 + ((~(((v6000 ^ -1) | (-(v6000 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6020[v6120] = v6017;
      int * v6022 = v5956->cache_tags;
      int v6123 = (int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1);
      v6022[v6099] = v6123;
      int * v6024 = v5956->cache_dirty;
      v6024[v6099] = 0;
      int * v6026 = v5956->cache_age;
      v6026[v6099] = 1;
      int * v6028 = v5956->cache_age;
      int v6029 = v6028[v6099];
      int v6030 = v6028[v6073];
      int v6129 = v6030 + ((int)((unsigned int)(v6030 - v6029) >> 31));
      v6028[v6073] = v6129;
      int * v6032 = v5956->cache_age;
      int v6033 = v6032[v6074];
      int v6131 = v6033 + ((int)((unsigned int)(v6033 - v6029) >> 31));
      v6032[v6074] = v6131;
      int * v6035 = v5956->cache_age;
      v6035[v6099] = 0;
      v6038 = v6099;
    }
    int * v6039 = v5956->cache_vals;
    int v6134 = v6038 * 2;
    int v6040 = v6039[v6134];
    int v6135 = (v6038 * 2) + 1;
    int v6041 = v6039[v6135];
    int v6136 = (((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5980 + ((~(((v5982 ^ -1) | (-(v5982 ^ -1))) >> 31)) & 2)) - (v5983 + ((~(((v5984 ^ -1) | (-(v5984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6039[v6136] = v6040;
    int * v6043 = v5956->cache_vals;
    int v6139 = ((((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5980 + ((~(((v5982 ^ -1) | (-(v5982 ^ -1))) >> 31)) & 2)) - (v5983 + ((~(((v5984 ^ -1) | (-(v5984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6043[v6139] = v6041;
    int * v6045 = v5956->cache_tags;
    int v6142 = ((((int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5980 + ((~(((v5982 ^ -1) | (-(v5982 ^ -1))) >> 31)) & 2)) - (v5983 + ((~(((v5984 ^ -1) | (-(v5984 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6143 = (int)((unsigned int)((int)((unsigned int)(v5960 + 4) >> 2)) >> 1);
    v6045[v6142] = v6143;
    int * v6047 = v5956->cache_dirty;
    v6047[v6142] = 0;
    int * v6049 = v5956->cache_age;
    v6049[v6142] = 1;
    int * v6051 = v5956->cache_age;
    int v6052 = v6051[v6142];
    int v6053 = v6051[v6071];
    int v6149 = v6053 + ((int)((unsigned int)(v6053 - v6052) >> 31));
    v6051[v6071] = v6149;
    int * v6055 = v5956->cache_age;
    int v6056 = v6055[v6072];
    int v6151 = v6056 + ((int)((unsigned int)(v6056 - v6052) >> 31));
    v6055[v6072] = v6151;
    int * v6058 = v5956->cache_age;
    v6058[v6142] = 0;
    v6061 = v6142;
  }
  int v6154 = (v6061 * 2) + (((int)((unsigned int)(v5960 + 4) >> 2)) & 1);
  int v6062 = v5968[v6154];
  int * v6063 = v5956->regs;
  v6063[25] = v6062;
  struct StateT * v6065 = slot_25(v5956);
  return v6065;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -96;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_195(struct StateT * v21786) {
  int v21787 = v21786->timer;
  int v21794 = v21787 + 1;
  v21786->timer = v21794;
  int * v21789 = v21786->regs;
  int v21790 = v21789[11];
  int v21798 = (int)((unsigned int)v21790 >> 14);
  v21789[9] = v21798;
  struct StateT * v21792 = slot_196(v21786);
  return v21792;
}

struct StateT * slot_125(struct StateT * v20683) {
  int v20684 = v20683->timer;
  int v20691 = v20684 + 1;
  v20683->timer = v20691;
  int * v20686 = v20683->regs;
  int v20687 = v20686[5];
  int v20694 = v20687 << 18;
  v20686[5] = v20694;
  struct StateT * v20689 = slot_126(v20683);
  return v20689;
}

struct StateT * slot_254(struct StateT * v14979) {
  int v14980 = v14979->timer;
  int v15150 = v14980 + 1;
  v14979->timer = v15150;
  int * v14982 = v14979->regs;
  int v14983 = v14982[10];
  int v14984 = v14982[26];
  int * v14985 = v14979->cache_tags;
  int v15155 = (((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2;
  int v14986 = v14985[v15155];
  int v15156 = ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14987 = v14985[v15156];
  int v15157 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2);
  int v14988 = v14985[v15157];
  int v15158 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14989 = v14985[v15158];
  int v14990 = v14979->timer;
  int v15159 = v14990 + ((100 ^ (((~(((v14988 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14988 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14986 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14986 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14987 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14987 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14988 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14988 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14979->timer = v15159;
  bool v15160 = !(((~(((v14986 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14986 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14987 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14987 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v15084;
  if (v15160) {
    int * v14992 = v14979->cache_age;
    int v15162 = ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v14987 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14987 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v14993 = v14992[v15162];
    int v14994 = v14992[v15155];
    int v15163 = v14994 + ((int)((unsigned int)(v14994 - v14993) >> 31));
    v14992[v15155] = v15163;
    int * v14996 = v14979->cache_age;
    int v14997 = v14996[v15156];
    int v15165 = v14997 + ((int)((unsigned int)(v14997 - v14993) >> 31));
    v14996[v15156] = v15165;
    int * v14999 = v14979->cache_age;
    v14999[v15162] = 0;
    v15084 = v15162;
  } else {
    int * v15002 = v14979->cache_age;
    int v15169 = (((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2;
    int v15003 = v15002[v15169];
    int * v15004 = v14979->cache_tags;
    int v15005 = v15004[v15169];
    int v15006 = v15002[v15156];
    int v15007 = v15004[v15156];
    bool v15171 = !(((~(((v14988 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14988 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v15061;
    if (v15171) {
      int * v15008 = v14979->cache_age;
      int v15173 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v14989 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v15009 = v15008[v15173];
      int v15010 = v15008[v15157];
      int v15174 = v15010 + ((int)((unsigned int)(v15010 - v15009) >> 31));
      v15008[v15157] = v15174;
      int * v15012 = v14979->cache_age;
      int v15013 = v15012[v15158];
      int v15176 = v15013 + ((int)((unsigned int)(v15013 - v15009) >> 31));
      v15012[v15158] = v15176;
      int * v15015 = v14979->cache_age;
      v15015[v15173] = 0;
      v15061 = v15173;
    } else {
      int * v15018 = v14979->cache_age;
      int v15180 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2);
      int v15019 = v15018[v15180];
      int * v15020 = v14979->cache_tags;
      int v15021 = v15020[v15180];
      int v15022 = v15018[v15158];
      int v15023 = v15020[v15158];
      int * v15024 = v14979->cache_dirty;
      int v15183 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15019 + ((~(((v15021 ^ -1) | (-(v15021 ^ -1))) >> 31)) & 2)) - (v15022 + ((~(((v15023 ^ -1) | (-(v15023 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15025 = v15024[v15183];
      bool v15184 = !(v15025 == 0);
      if (v15184) {
        int * v15026 = v14979->cache_tags;
        int v15027 = v15026[v15183];
        int * v15028 = v14979->cache_vals;
        int v15187 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15019 + ((~(((v15021 ^ -1) | (-(v15021 ^ -1))) >> 31)) & 2)) - (v15022 + ((~(((v15023 ^ -1) | (-(v15023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15029 = v15028[v15187];
        int v15188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15019 + ((~(((v15021 ^ -1) | (-(v15021 ^ -1))) >> 31)) & 2)) - (v15022 + ((~(((v15023 ^ -1) | (-(v15023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15030 = v15028[v15188];
        int * v15031 = v14979->mem;
        int v15190 = v15027 * 2;
        v15031[v15190] = v15029;
        int * v15033 = v14979->mem;
        int v15193 = (v15027 * 2) + 1;
        v15033[v15193] = v15030;
        ;
      } else {
        ;
      }
      int * v15038 = v14979->mem;
      int v15198 = ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) * 2;
      int v15039 = v15038[v15198];
      int v15199 = (((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) * 2) + 1;
      int v15040 = v15038[v15199];
      int * v15041 = v14979->cache_vals;
      int v15201 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15019 + ((~(((v15021 ^ -1) | (-(v15021 ^ -1))) >> 31)) & 2)) - (v15022 + ((~(((v15023 ^ -1) | (-(v15023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15041[v15201] = v15039;
      int * v15043 = v14979->cache_vals;
      int v15204 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15019 + ((~(((v15021 ^ -1) | (-(v15021 ^ -1))) >> 31)) & 2)) - (v15022 + ((~(((v15023 ^ -1) | (-(v15023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15043[v15204] = v15040;
      int * v15045 = v14979->cache_tags;
      int v15207 = (int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1);
      v15045[v15183] = v15207;
      int * v15047 = v14979->cache_dirty;
      v15047[v15183] = 0;
      int * v15049 = v14979->cache_age;
      v15049[v15183] = 1;
      int * v15051 = v14979->cache_age;
      int v15052 = v15051[v15183];
      int v15053 = v15051[v15157];
      int v15213 = v15053 + ((int)((unsigned int)(v15053 - v15052) >> 31));
      v15051[v15157] = v15213;
      int * v15055 = v14979->cache_age;
      int v15056 = v15055[v15158];
      int v15215 = v15056 + ((int)((unsigned int)(v15056 - v15052) >> 31));
      v15055[v15158] = v15215;
      int * v15058 = v14979->cache_age;
      v15058[v15183] = 0;
      v15061 = v15183;
    }
    int * v15062 = v14979->cache_vals;
    int v15218 = v15061 * 2;
    int v15063 = v15062[v15218];
    int v15219 = (v15061 * 2) + 1;
    int v15064 = v15062[v15219];
    int v15220 = (((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v15003 + ((~(((v15005 ^ -1) | (-(v15005 ^ -1))) >> 31)) & 2)) - (v15006 + ((~(((v15007 ^ -1) | (-(v15007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15062[v15220] = v15063;
    int * v15066 = v14979->cache_vals;
    int v15223 = ((((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v15003 + ((~(((v15005 ^ -1) | (-(v15005 ^ -1))) >> 31)) & 2)) - (v15006 + ((~(((v15007 ^ -1) | (-(v15007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15066[v15223] = v15064;
    int * v15068 = v14979->cache_tags;
    int v15226 = ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v15003 + ((~(((v15005 ^ -1) | (-(v15005 ^ -1))) >> 31)) & 2)) - (v15006 + ((~(((v15007 ^ -1) | (-(v15007 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15227 = (int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1);
    v15068[v15226] = v15227;
    int * v15070 = v14979->cache_dirty;
    v15070[v15226] = 0;
    int * v15072 = v14979->cache_age;
    v15072[v15226] = 1;
    int * v15074 = v14979->cache_age;
    int v15075 = v15074[v15226];
    int v15076 = v15074[v15155];
    int v15233 = v15076 + ((int)((unsigned int)(v15076 - v15075) >> 31));
    v15074[v15155] = v15233;
    int * v15078 = v14979->cache_age;
    int v15079 = v15078[v15156];
    int v15235 = v15079 + ((int)((unsigned int)(v15079 - v15075) >> 31));
    v15078[v15156] = v15235;
    int * v15081 = v14979->cache_age;
    v15081[v15226] = 0;
    v15084 = v15226;
  }
  int * v15085 = v14979->cache_vals;
  int v15238 = (v15084 * 2) + (((int)((unsigned int)(v14983 + 32) >> 2)) & 1);
  v15085[v15238] = v14984;
  int * v15087 = v14979->cache_tags;
  int v15088 = v15087[v15157];
  int v15089 = v15087[v15158];
  bool v15241 = !(((~(((v15088 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v15088 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v15089 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v15089 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v15143;
  if (v15241) {
    int * v15090 = v14979->cache_age;
    int v15243 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15089 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))) | (-(v15089 ^ ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v15091 = v15090[v15243];
    int v15092 = v15090[v15157];
    int v15244 = v15092 + ((int)((unsigned int)(v15092 - v15091) >> 31));
    v15090[v15157] = v15244;
    int * v15094 = v14979->cache_age;
    int v15095 = v15094[v15158];
    int v15246 = v15095 + ((int)((unsigned int)(v15095 - v15091) >> 31));
    v15094[v15158] = v15246;
    int * v15097 = v14979->cache_age;
    v15097[v15243] = 0;
    v15143 = v15243;
  } else {
    int * v15100 = v14979->cache_age;
    int v15250 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2);
    int v15101 = v15100[v15250];
    int * v15102 = v14979->cache_tags;
    int v15103 = v15102[v15250];
    int v15104 = v15100[v15158];
    int v15105 = v15102[v15158];
    int * v15106 = v14979->cache_dirty;
    int v15253 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15101 + ((~(((v15103 ^ -1) | (-(v15103 ^ -1))) >> 31)) & 2)) - (v15104 + ((~(((v15105 ^ -1) | (-(v15105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15107 = v15106[v15253];
    bool v15254 = !(v15107 == 0);
    if (v15254) {
      int * v15108 = v14979->cache_tags;
      int v15109 = v15108[v15253];
      int * v15110 = v14979->cache_vals;
      int v15257 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15101 + ((~(((v15103 ^ -1) | (-(v15103 ^ -1))) >> 31)) & 2)) - (v15104 + ((~(((v15105 ^ -1) | (-(v15105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v15111 = v15110[v15257];
      int v15258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15101 + ((~(((v15103 ^ -1) | (-(v15103 ^ -1))) >> 31)) & 2)) - (v15104 + ((~(((v15105 ^ -1) | (-(v15105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v15112 = v15110[v15258];
      int * v15113 = v14979->mem;
      int v15260 = v15109 * 2;
      v15113[v15260] = v15111;
      int * v15115 = v14979->mem;
      int v15263 = (v15109 * 2) + 1;
      v15115[v15263] = v15112;
      ;
    } else {
      ;
    }
    int * v15120 = v14979->mem;
    int v15268 = ((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) * 2;
    int v15121 = v15120[v15268];
    int v15269 = (((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) * 2) + 1;
    int v15122 = v15120[v15269];
    int * v15123 = v14979->cache_vals;
    int v15271 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15101 + ((~(((v15103 ^ -1) | (-(v15103 ^ -1))) >> 31)) & 2)) - (v15104 + ((~(((v15105 ^ -1) | (-(v15105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15123[v15271] = v15121;
    int * v15125 = v14979->cache_vals;
    int v15274 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v15101 + ((~(((v15103 ^ -1) | (-(v15103 ^ -1))) >> 31)) & 2)) - (v15104 + ((~(((v15105 ^ -1) | (-(v15105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15125[v15274] = v15122;
    int * v15127 = v14979->cache_tags;
    int v15277 = (int)((unsigned int)((int)((unsigned int)(v14983 + 32) >> 2)) >> 1);
    v15127[v15253] = v15277;
    int * v15129 = v14979->cache_dirty;
    v15129[v15253] = 0;
    int * v15131 = v14979->cache_age;
    v15131[v15253] = 1;
    int * v15133 = v14979->cache_age;
    int v15134 = v15133[v15253];
    int v15135 = v15133[v15157];
    int v15283 = v15135 + ((int)((unsigned int)(v15135 - v15134) >> 31));
    v15133[v15157] = v15283;
    int * v15137 = v14979->cache_age;
    int v15138 = v15137[v15158];
    int v15285 = v15138 + ((int)((unsigned int)(v15138 - v15134) >> 31));
    v15137[v15158] = v15285;
    int * v15140 = v14979->cache_age;
    v15140[v15253] = 0;
    v15143 = v15253;
  }
  int * v15144 = v14979->cache_vals;
  int v15288 = (v15143 * 2) + (((int)((unsigned int)(v14983 + 32) >> 2)) & 1);
  v15144[v15288] = v14984;
  int * v15146 = v14979->cache_dirty;
  v15146[v15143] = 1;
  struct StateT * v15148 = slot_255(v14979);
  return v15148;
}

struct StateT * slot_148(struct StateT * v21043) {
  int v21044 = v21043->timer;
  int v21052 = v21044 + 1;
  v21043->timer = v21052;
  int * v21046 = v21043->regs;
  int v21047 = v21046[18];
  int v21048 = v21046[11];
  int v21057 = v21047 ^ v21048;
  v21046[5] = v21057;
  struct StateT * v21050 = slot_149(v21043);
  return v21050;
}

struct StateT * slot_126(struct StateT * v20697) {
  int v20698 = v20697->timer;
  int v20706 = v20698 + 1;
  v20697->timer = v20706;
  int * v20700 = v20697->regs;
  int v20701 = v20700[5];
  int v20702 = v20700[6];
  int v20710 = v20701 | v20702;
  v20700[5] = v20710;
  struct StateT * v20704 = slot_127(v20697);
  return v20704;
}

struct StateT * slot_223(struct StateT * v10494) {
  int v10495 = v10494->timer;
  int v10503 = v10495 + 1;
  v10494->timer = v10503;
  int * v10497 = v10494->regs;
  int v10498 = v10497[25];
  int v10499 = v10497[7];
  int v10507 = v10498 + v10499;
  v10497[25] = v10507;
  struct StateT * v10501 = slot_224(v10494);
  return v10501;
}

struct StateT * slot_79(struct StateT * v12194) {
  int v12195 = v12194->timer;
  int v12202 = v12195 + 1;
  v12194->timer = v12202;
  int * v12197 = v12194->regs;
  int v12198 = v12197[8];
  int v12205 = v12198 << 9;
  v12197[8] = v12205;
  struct StateT * v12200 = slot_80(v12194);
  return v12200;
}

struct StateT * slot_237(struct StateT * v12065) {
  int v12066 = v12065->timer;
  int v12072 = v12066 + 1;
  v12065->timer = v12072;
  int * v12068 = v12065->regs;
  v12068[30] = 1797283840;
  struct StateT * v12070 = slot_238(v12065);
  return v12070;
}

struct StateT * slot_41(struct StateT * v8263) {
  int v8264 = v8263->timer;
  int v8434 = v8264 + 1;
  v8263->timer = v8434;
  int * v8266 = v8263->regs;
  int v8267 = v8266[2];
  int v8268 = v8266[16];
  int * v8269 = v8263->cache_tags;
  int v8439 = (((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2;
  int v8270 = v8269[v8439];
  int v8440 = ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8271 = v8269[v8440];
  int v8441 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2);
  int v8272 = v8269[v8441];
  int v8442 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8273 = v8269[v8442];
  int v8274 = v8263->timer;
  int v8443 = v8274 + ((100 ^ (((~(((v8272 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8272 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8270 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8270 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8271 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8271 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8272 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8272 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8263->timer = v8443;
  bool v8444 = !(((~(((v8270 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8270 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8271 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8271 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v8368;
  if (v8444) {
    int * v8276 = v8263->cache_age;
    int v8446 = ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v8271 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8271 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v8277 = v8276[v8446];
    int v8278 = v8276[v8439];
    int v8447 = v8278 + ((int)((unsigned int)(v8278 - v8277) >> 31));
    v8276[v8439] = v8447;
    int * v8280 = v8263->cache_age;
    int v8281 = v8280[v8440];
    int v8449 = v8281 + ((int)((unsigned int)(v8281 - v8277) >> 31));
    v8280[v8440] = v8449;
    int * v8283 = v8263->cache_age;
    v8283[v8446] = 0;
    v8368 = v8446;
  } else {
    int * v8286 = v8263->cache_age;
    int v8453 = (((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2;
    int v8287 = v8286[v8453];
    int * v8288 = v8263->cache_tags;
    int v8289 = v8288[v8453];
    int v8290 = v8286[v8440];
    int v8291 = v8288[v8440];
    bool v8455 = !(((~(((v8272 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8272 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v8345;
    if (v8455) {
      int * v8292 = v8263->cache_age;
      int v8457 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8273 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v8293 = v8292[v8457];
      int v8294 = v8292[v8441];
      int v8458 = v8294 + ((int)((unsigned int)(v8294 - v8293) >> 31));
      v8292[v8441] = v8458;
      int * v8296 = v8263->cache_age;
      int v8297 = v8296[v8442];
      int v8460 = v8297 + ((int)((unsigned int)(v8297 - v8293) >> 31));
      v8296[v8442] = v8460;
      int * v8299 = v8263->cache_age;
      v8299[v8457] = 0;
      v8345 = v8457;
    } else {
      int * v8302 = v8263->cache_age;
      int v8464 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2);
      int v8303 = v8302[v8464];
      int * v8304 = v8263->cache_tags;
      int v8305 = v8304[v8464];
      int v8306 = v8302[v8442];
      int v8307 = v8304[v8442];
      int * v8308 = v8263->cache_dirty;
      int v8467 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8303 + ((~(((v8305 ^ -1) | (-(v8305 ^ -1))) >> 31)) & 2)) - (v8306 + ((~(((v8307 ^ -1) | (-(v8307 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8309 = v8308[v8467];
      bool v8468 = !(v8309 == 0);
      if (v8468) {
        int * v8310 = v8263->cache_tags;
        int v8311 = v8310[v8467];
        int * v8312 = v8263->cache_vals;
        int v8471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8303 + ((~(((v8305 ^ -1) | (-(v8305 ^ -1))) >> 31)) & 2)) - (v8306 + ((~(((v8307 ^ -1) | (-(v8307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8313 = v8312[v8471];
        int v8472 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8303 + ((~(((v8305 ^ -1) | (-(v8305 ^ -1))) >> 31)) & 2)) - (v8306 + ((~(((v8307 ^ -1) | (-(v8307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8314 = v8312[v8472];
        int * v8315 = v8263->mem;
        int v8474 = v8311 * 2;
        v8315[v8474] = v8313;
        int * v8317 = v8263->mem;
        int v8477 = (v8311 * 2) + 1;
        v8317[v8477] = v8314;
        ;
      } else {
        ;
      }
      int * v8322 = v8263->mem;
      int v8482 = ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) * 2;
      int v8323 = v8322[v8482];
      int v8483 = (((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) * 2) + 1;
      int v8324 = v8322[v8483];
      int * v8325 = v8263->cache_vals;
      int v8485 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8303 + ((~(((v8305 ^ -1) | (-(v8305 ^ -1))) >> 31)) & 2)) - (v8306 + ((~(((v8307 ^ -1) | (-(v8307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8325[v8485] = v8323;
      int * v8327 = v8263->cache_vals;
      int v8488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8303 + ((~(((v8305 ^ -1) | (-(v8305 ^ -1))) >> 31)) & 2)) - (v8306 + ((~(((v8307 ^ -1) | (-(v8307 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8327[v8488] = v8324;
      int * v8329 = v8263->cache_tags;
      int v8491 = (int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1);
      v8329[v8467] = v8491;
      int * v8331 = v8263->cache_dirty;
      v8331[v8467] = 0;
      int * v8333 = v8263->cache_age;
      v8333[v8467] = 1;
      int * v8335 = v8263->cache_age;
      int v8336 = v8335[v8467];
      int v8337 = v8335[v8441];
      int v8497 = v8337 + ((int)((unsigned int)(v8337 - v8336) >> 31));
      v8335[v8441] = v8497;
      int * v8339 = v8263->cache_age;
      int v8340 = v8339[v8442];
      int v8499 = v8340 + ((int)((unsigned int)(v8340 - v8336) >> 31));
      v8339[v8442] = v8499;
      int * v8342 = v8263->cache_age;
      v8342[v8467] = 0;
      v8345 = v8467;
    }
    int * v8346 = v8263->cache_vals;
    int v8502 = v8345 * 2;
    int v8347 = v8346[v8502];
    int v8503 = (v8345 * 2) + 1;
    int v8348 = v8346[v8503];
    int v8504 = (((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8287 + ((~(((v8289 ^ -1) | (-(v8289 ^ -1))) >> 31)) & 2)) - (v8290 + ((~(((v8291 ^ -1) | (-(v8291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8346[v8504] = v8347;
    int * v8350 = v8263->cache_vals;
    int v8507 = ((((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8287 + ((~(((v8289 ^ -1) | (-(v8289 ^ -1))) >> 31)) & 2)) - (v8290 + ((~(((v8291 ^ -1) | (-(v8291 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8350[v8507] = v8348;
    int * v8352 = v8263->cache_tags;
    int v8510 = ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8287 + ((~(((v8289 ^ -1) | (-(v8289 ^ -1))) >> 31)) & 2)) - (v8290 + ((~(((v8291 ^ -1) | (-(v8291 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8511 = (int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1);
    v8352[v8510] = v8511;
    int * v8354 = v8263->cache_dirty;
    v8354[v8510] = 0;
    int * v8356 = v8263->cache_age;
    v8356[v8510] = 1;
    int * v8358 = v8263->cache_age;
    int v8359 = v8358[v8510];
    int v8360 = v8358[v8439];
    int v8517 = v8360 + ((int)((unsigned int)(v8360 - v8359) >> 31));
    v8358[v8439] = v8517;
    int * v8362 = v8263->cache_age;
    int v8363 = v8362[v8440];
    int v8519 = v8363 + ((int)((unsigned int)(v8363 - v8359) >> 31));
    v8362[v8440] = v8519;
    int * v8365 = v8263->cache_age;
    v8365[v8510] = 0;
    v8368 = v8510;
  }
  int * v8369 = v8263->cache_vals;
  int v8522 = (v8368 * 2) + (((int)((unsigned int)(v8267 + 32) >> 2)) & 1);
  v8369[v8522] = v8268;
  int * v8371 = v8263->cache_tags;
  int v8372 = v8371[v8441];
  int v8373 = v8371[v8442];
  bool v8525 = !(((~(((v8372 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8372 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8373 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8373 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v8427;
  if (v8525) {
    int * v8374 = v8263->cache_age;
    int v8527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8373 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))) | (-(v8373 ^ ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v8375 = v8374[v8527];
    int v8376 = v8374[v8441];
    int v8528 = v8376 + ((int)((unsigned int)(v8376 - v8375) >> 31));
    v8374[v8441] = v8528;
    int * v8378 = v8263->cache_age;
    int v8379 = v8378[v8442];
    int v8530 = v8379 + ((int)((unsigned int)(v8379 - v8375) >> 31));
    v8378[v8442] = v8530;
    int * v8381 = v8263->cache_age;
    v8381[v8527] = 0;
    v8427 = v8527;
  } else {
    int * v8384 = v8263->cache_age;
    int v8534 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2);
    int v8385 = v8384[v8534];
    int * v8386 = v8263->cache_tags;
    int v8387 = v8386[v8534];
    int v8388 = v8384[v8442];
    int v8389 = v8386[v8442];
    int * v8390 = v8263->cache_dirty;
    int v8537 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8385 + ((~(((v8387 ^ -1) | (-(v8387 ^ -1))) >> 31)) & 2)) - (v8388 + ((~(((v8389 ^ -1) | (-(v8389 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8391 = v8390[v8537];
    bool v8538 = !(v8391 == 0);
    if (v8538) {
      int * v8392 = v8263->cache_tags;
      int v8393 = v8392[v8537];
      int * v8394 = v8263->cache_vals;
      int v8541 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8385 + ((~(((v8387 ^ -1) | (-(v8387 ^ -1))) >> 31)) & 2)) - (v8388 + ((~(((v8389 ^ -1) | (-(v8389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v8395 = v8394[v8541];
      int v8542 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8385 + ((~(((v8387 ^ -1) | (-(v8387 ^ -1))) >> 31)) & 2)) - (v8388 + ((~(((v8389 ^ -1) | (-(v8389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v8396 = v8394[v8542];
      int * v8397 = v8263->mem;
      int v8544 = v8393 * 2;
      v8397[v8544] = v8395;
      int * v8399 = v8263->mem;
      int v8547 = (v8393 * 2) + 1;
      v8399[v8547] = v8396;
      ;
    } else {
      ;
    }
    int * v8404 = v8263->mem;
    int v8552 = ((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) * 2;
    int v8405 = v8404[v8552];
    int v8553 = (((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) * 2) + 1;
    int v8406 = v8404[v8553];
    int * v8407 = v8263->cache_vals;
    int v8555 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8385 + ((~(((v8387 ^ -1) | (-(v8387 ^ -1))) >> 31)) & 2)) - (v8388 + ((~(((v8389 ^ -1) | (-(v8389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8407[v8555] = v8405;
    int * v8409 = v8263->cache_vals;
    int v8558 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8385 + ((~(((v8387 ^ -1) | (-(v8387 ^ -1))) >> 31)) & 2)) - (v8388 + ((~(((v8389 ^ -1) | (-(v8389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8409[v8558] = v8406;
    int * v8411 = v8263->cache_tags;
    int v8561 = (int)((unsigned int)((int)((unsigned int)(v8267 + 32) >> 2)) >> 1);
    v8411[v8537] = v8561;
    int * v8413 = v8263->cache_dirty;
    v8413[v8537] = 0;
    int * v8415 = v8263->cache_age;
    v8415[v8537] = 1;
    int * v8417 = v8263->cache_age;
    int v8418 = v8417[v8537];
    int v8419 = v8417[v8441];
    int v8567 = v8419 + ((int)((unsigned int)(v8419 - v8418) >> 31));
    v8417[v8441] = v8567;
    int * v8421 = v8263->cache_age;
    int v8422 = v8421[v8442];
    int v8569 = v8422 + ((int)((unsigned int)(v8422 - v8418) >> 31));
    v8421[v8442] = v8569;
    int * v8424 = v8263->cache_age;
    v8424[v8537] = 0;
    v8427 = v8537;
  }
  int * v8428 = v8263->cache_vals;
  int v8572 = (v8427 * 2) + (((int)((unsigned int)(v8267 + 32) >> 2)) & 1);
  v8428[v8572] = v8268;
  int * v8430 = v8263->cache_dirty;
  v8430[v8427] = 1;
  struct StateT * v8432 = slot_42(v8263);
  return v8432;
}

struct StateT * slot_39(struct StateT * v7637) {
  int v7638 = v7637->timer;
  int v7808 = v7638 + 1;
  v7637->timer = v7808;
  int * v7640 = v7637->regs;
  int v7641 = v7640[2];
  int v7642 = v7640[1];
  int * v7643 = v7637->cache_tags;
  int v7813 = (((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2;
  int v7644 = v7643[v7813];
  int v7814 = ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7645 = v7643[v7814];
  int v7815 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2);
  int v7646 = v7643[v7815];
  int v7816 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7647 = v7643[v7816];
  int v7648 = v7637->timer;
  int v7817 = v7648 + ((100 ^ (((~(((v7646 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7646 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7644 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7644 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v7645 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7645 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7646 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7646 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7637->timer = v7817;
  bool v7818 = !(((~(((v7644 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7644 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v7645 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7645 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v7742;
  if (v7818) {
    int * v7650 = v7637->cache_age;
    int v7820 = ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v7645 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7645 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v7651 = v7650[v7820];
    int v7652 = v7650[v7813];
    int v7821 = v7652 + ((int)((unsigned int)(v7652 - v7651) >> 31));
    v7650[v7813] = v7821;
    int * v7654 = v7637->cache_age;
    int v7655 = v7654[v7814];
    int v7823 = v7655 + ((int)((unsigned int)(v7655 - v7651) >> 31));
    v7654[v7814] = v7823;
    int * v7657 = v7637->cache_age;
    v7657[v7820] = 0;
    v7742 = v7820;
  } else {
    int * v7660 = v7637->cache_age;
    int v7827 = (((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2;
    int v7661 = v7660[v7827];
    int * v7662 = v7637->cache_tags;
    int v7663 = v7662[v7827];
    int v7664 = v7660[v7814];
    int v7665 = v7662[v7814];
    bool v7829 = !(((~(((v7646 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7646 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v7719;
    if (v7829) {
      int * v7666 = v7637->cache_age;
      int v7831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7647 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v7667 = v7666[v7831];
      int v7668 = v7666[v7815];
      int v7832 = v7668 + ((int)((unsigned int)(v7668 - v7667) >> 31));
      v7666[v7815] = v7832;
      int * v7670 = v7637->cache_age;
      int v7671 = v7670[v7816];
      int v7834 = v7671 + ((int)((unsigned int)(v7671 - v7667) >> 31));
      v7670[v7816] = v7834;
      int * v7673 = v7637->cache_age;
      v7673[v7831] = 0;
      v7719 = v7831;
    } else {
      int * v7676 = v7637->cache_age;
      int v7838 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2);
      int v7677 = v7676[v7838];
      int * v7678 = v7637->cache_tags;
      int v7679 = v7678[v7838];
      int v7680 = v7676[v7816];
      int v7681 = v7678[v7816];
      int * v7682 = v7637->cache_dirty;
      int v7841 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7677 + ((~(((v7679 ^ -1) | (-(v7679 ^ -1))) >> 31)) & 2)) - (v7680 + ((~(((v7681 ^ -1) | (-(v7681 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7683 = v7682[v7841];
      bool v7842 = !(v7683 == 0);
      if (v7842) {
        int * v7684 = v7637->cache_tags;
        int v7685 = v7684[v7841];
        int * v7686 = v7637->cache_vals;
        int v7845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7677 + ((~(((v7679 ^ -1) | (-(v7679 ^ -1))) >> 31)) & 2)) - (v7680 + ((~(((v7681 ^ -1) | (-(v7681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7687 = v7686[v7845];
        int v7846 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7677 + ((~(((v7679 ^ -1) | (-(v7679 ^ -1))) >> 31)) & 2)) - (v7680 + ((~(((v7681 ^ -1) | (-(v7681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7688 = v7686[v7846];
        int * v7689 = v7637->mem;
        int v7848 = v7685 * 2;
        v7689[v7848] = v7687;
        int * v7691 = v7637->mem;
        int v7851 = (v7685 * 2) + 1;
        v7691[v7851] = v7688;
        ;
      } else {
        ;
      }
      int * v7696 = v7637->mem;
      int v7856 = ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) * 2;
      int v7697 = v7696[v7856];
      int v7857 = (((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) * 2) + 1;
      int v7698 = v7696[v7857];
      int * v7699 = v7637->cache_vals;
      int v7859 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7677 + ((~(((v7679 ^ -1) | (-(v7679 ^ -1))) >> 31)) & 2)) - (v7680 + ((~(((v7681 ^ -1) | (-(v7681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7699[v7859] = v7697;
      int * v7701 = v7637->cache_vals;
      int v7862 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7677 + ((~(((v7679 ^ -1) | (-(v7679 ^ -1))) >> 31)) & 2)) - (v7680 + ((~(((v7681 ^ -1) | (-(v7681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7701[v7862] = v7698;
      int * v7703 = v7637->cache_tags;
      int v7865 = (int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1);
      v7703[v7841] = v7865;
      int * v7705 = v7637->cache_dirty;
      v7705[v7841] = 0;
      int * v7707 = v7637->cache_age;
      v7707[v7841] = 1;
      int * v7709 = v7637->cache_age;
      int v7710 = v7709[v7841];
      int v7711 = v7709[v7815];
      int v7870 = v7711 + ((int)((unsigned int)(v7711 - v7710) >> 31));
      v7709[v7815] = v7870;
      int * v7713 = v7637->cache_age;
      int v7714 = v7713[v7816];
      int v7872 = v7714 + ((int)((unsigned int)(v7714 - v7710) >> 31));
      v7713[v7816] = v7872;
      int * v7716 = v7637->cache_age;
      v7716[v7841] = 0;
      v7719 = v7841;
    }
    int * v7720 = v7637->cache_vals;
    int v7875 = v7719 * 2;
    int v7721 = v7720[v7875];
    int v7876 = (v7719 * 2) + 1;
    int v7722 = v7720[v7876];
    int v7877 = (((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v7661 + ((~(((v7663 ^ -1) | (-(v7663 ^ -1))) >> 31)) & 2)) - (v7664 + ((~(((v7665 ^ -1) | (-(v7665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7720[v7877] = v7721;
    int * v7724 = v7637->cache_vals;
    int v7880 = ((((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v7661 + ((~(((v7663 ^ -1) | (-(v7663 ^ -1))) >> 31)) & 2)) - (v7664 + ((~(((v7665 ^ -1) | (-(v7665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7724[v7880] = v7722;
    int * v7726 = v7637->cache_tags;
    int v7883 = ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v7661 + ((~(((v7663 ^ -1) | (-(v7663 ^ -1))) >> 31)) & 2)) - (v7664 + ((~(((v7665 ^ -1) | (-(v7665 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7884 = (int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1);
    v7726[v7883] = v7884;
    int * v7728 = v7637->cache_dirty;
    v7728[v7883] = 0;
    int * v7730 = v7637->cache_age;
    v7730[v7883] = 1;
    int * v7732 = v7637->cache_age;
    int v7733 = v7732[v7883];
    int v7734 = v7732[v7813];
    int v7889 = v7734 + ((int)((unsigned int)(v7734 - v7733) >> 31));
    v7732[v7813] = v7889;
    int * v7736 = v7637->cache_age;
    int v7737 = v7736[v7814];
    int v7891 = v7737 + ((int)((unsigned int)(v7737 - v7733) >> 31));
    v7736[v7814] = v7891;
    int * v7739 = v7637->cache_age;
    v7739[v7883] = 0;
    v7742 = v7883;
  }
  int * v7743 = v7637->cache_vals;
  int v7894 = (v7742 * 2) + (((int)((unsigned int)(v7641 + 40) >> 2)) & 1);
  v7743[v7894] = v7642;
  int * v7745 = v7637->cache_tags;
  int v7746 = v7745[v7815];
  int v7747 = v7745[v7816];
  bool v7897 = !(((~(((v7746 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7746 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v7747 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7747 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v7801;
  if (v7897) {
    int * v7748 = v7637->cache_age;
    int v7899 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7747 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))) | (-(v7747 ^ ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v7749 = v7748[v7899];
    int v7750 = v7748[v7815];
    int v7900 = v7750 + ((int)((unsigned int)(v7750 - v7749) >> 31));
    v7748[v7815] = v7900;
    int * v7752 = v7637->cache_age;
    int v7753 = v7752[v7816];
    int v7902 = v7753 + ((int)((unsigned int)(v7753 - v7749) >> 31));
    v7752[v7816] = v7902;
    int * v7755 = v7637->cache_age;
    v7755[v7899] = 0;
    v7801 = v7899;
  } else {
    int * v7758 = v7637->cache_age;
    int v7906 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2);
    int v7759 = v7758[v7906];
    int * v7760 = v7637->cache_tags;
    int v7761 = v7760[v7906];
    int v7762 = v7758[v7816];
    int v7763 = v7760[v7816];
    int * v7764 = v7637->cache_dirty;
    int v7909 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7765 = v7764[v7909];
    bool v7910 = !(v7765 == 0);
    if (v7910) {
      int * v7766 = v7637->cache_tags;
      int v7767 = v7766[v7909];
      int * v7768 = v7637->cache_vals;
      int v7913 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7769 = v7768[v7913];
      int v7914 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7770 = v7768[v7914];
      int * v7771 = v7637->mem;
      int v7916 = v7767 * 2;
      v7771[v7916] = v7769;
      int * v7773 = v7637->mem;
      int v7919 = (v7767 * 2) + 1;
      v7773[v7919] = v7770;
      ;
    } else {
      ;
    }
    int * v7778 = v7637->mem;
    int v7924 = ((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) * 2;
    int v7779 = v7778[v7924];
    int v7925 = (((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) * 2) + 1;
    int v7780 = v7778[v7925];
    int * v7781 = v7637->cache_vals;
    int v7927 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7781[v7927] = v7779;
    int * v7783 = v7637->cache_vals;
    int v7930 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v7759 + ((~(((v7761 ^ -1) | (-(v7761 ^ -1))) >> 31)) & 2)) - (v7762 + ((~(((v7763 ^ -1) | (-(v7763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7783[v7930] = v7780;
    int * v7785 = v7637->cache_tags;
    int v7933 = (int)((unsigned int)((int)((unsigned int)(v7641 + 40) >> 2)) >> 1);
    v7785[v7909] = v7933;
    int * v7787 = v7637->cache_dirty;
    v7787[v7909] = 0;
    int * v7789 = v7637->cache_age;
    v7789[v7909] = 1;
    int * v7791 = v7637->cache_age;
    int v7792 = v7791[v7909];
    int v7793 = v7791[v7815];
    int v7938 = v7793 + ((int)((unsigned int)(v7793 - v7792) >> 31));
    v7791[v7815] = v7938;
    int * v7795 = v7637->cache_age;
    int v7796 = v7795[v7816];
    int v7940 = v7796 + ((int)((unsigned int)(v7796 - v7792) >> 31));
    v7795[v7816] = v7940;
    int * v7798 = v7637->cache_age;
    v7798[v7909] = 0;
    v7801 = v7909;
  }
  int * v7802 = v7637->cache_vals;
  int v7943 = (v7801 * 2) + (((int)((unsigned int)(v7641 + 40) >> 2)) & 1);
  v7802[v7943] = v7642;
  int * v7804 = v7637->cache_dirty;
  v7804[v7801] = 1;
  struct StateT * v7806 = slot_40(v7637);
  return v7806;
}

struct StateT * slot_142(struct StateT * v20951) {
  int v20952 = v20951->timer;
  int v20959 = v20952 + 1;
  v20951->timer = v20959;
  int * v20954 = v20951->regs;
  int v20955 = v20954[16];
  int v20962 = v20955 << 7;
  v20954[16] = v20962;
  struct StateT * v20957 = slot_143(v20951);
  return v20957;
}

struct StateT * slot_60(struct StateT * v10478) {
  int v10479 = v10478->timer;
  int v10487 = v10479 + 1;
  v10478->timer = v10487;
  int * v10481 = v10478->regs;
  int v10482 = v10481[20];
  int v10483 = v10481[9];
  int v10491 = v10482 | v10483;
  v10481[9] = v10491;
  struct StateT * v10485 = slot_61(v10478);
  return v10485;
}

struct StateT * slot_238(struct StateT * v12093) {
  int v12094 = v12093->timer;
  int v12101 = v12094 + 1;
  v12093->timer = v12101;
  int * v12096 = v12093->regs;
  int v12097 = v12096[15];
  int v12104 = v12097 + -1947;
  v12096[15] = v12104;
  struct StateT * v12099 = slot_239(v12093);
  return v12099;
}

struct StateT * slot_112(struct StateT * v20463) {
  int v20464 = v20463->timer;
  int v20472 = v20464 + 1;
  v20463->timer = v20472;
  int * v20466 = v20463->regs;
  int v20467 = v20466[23];
  int v20468 = v20466[24];
  int v20477 = v20467 + v20468;
  v20466[16] = v20477;
  struct StateT * v20470 = slot_113(v20463);
  return v20470;
}

struct StateT * slot_256(struct StateT * v15643) {
  int v15644 = v15643->timer;
  int v15814 = v15644 + 1;
  v15643->timer = v15814;
  int * v15646 = v15643->regs;
  int v15647 = v15646[10];
  int v15648 = v15646[7];
  int * v15649 = v15643->cache_tags;
  int v15819 = (((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2;
  int v15650 = v15649[v15819];
  int v15820 = ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15651 = v15649[v15820];
  int v15821 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2);
  int v15652 = v15649[v15821];
  int v15822 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15653 = v15649[v15822];
  int v15654 = v15643->timer;
  int v15823 = v15654 + ((100 ^ (((~(((v15652 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15652 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15650 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15650 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15651 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15651 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15652 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15652 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15643->timer = v15823;
  bool v15824 = !(((~(((v15650 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15650 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15651 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15651 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v15748;
  if (v15824) {
    int * v15656 = v15643->cache_age;
    int v15826 = ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v15651 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15651 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v15657 = v15656[v15826];
    int v15658 = v15656[v15819];
    int v15827 = v15658 + ((int)((unsigned int)(v15658 - v15657) >> 31));
    v15656[v15819] = v15827;
    int * v15660 = v15643->cache_age;
    int v15661 = v15660[v15820];
    int v15829 = v15661 + ((int)((unsigned int)(v15661 - v15657) >> 31));
    v15660[v15820] = v15829;
    int * v15663 = v15643->cache_age;
    v15663[v15826] = 0;
    v15748 = v15826;
  } else {
    int * v15666 = v15643->cache_age;
    int v15833 = (((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2;
    int v15667 = v15666[v15833];
    int * v15668 = v15643->cache_tags;
    int v15669 = v15668[v15833];
    int v15670 = v15666[v15820];
    int v15671 = v15668[v15820];
    bool v15835 = !(((~(((v15652 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15652 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v15725;
    if (v15835) {
      int * v15672 = v15643->cache_age;
      int v15837 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15653 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v15673 = v15672[v15837];
      int v15674 = v15672[v15821];
      int v15838 = v15674 + ((int)((unsigned int)(v15674 - v15673) >> 31));
      v15672[v15821] = v15838;
      int * v15676 = v15643->cache_age;
      int v15677 = v15676[v15822];
      int v15840 = v15677 + ((int)((unsigned int)(v15677 - v15673) >> 31));
      v15676[v15822] = v15840;
      int * v15679 = v15643->cache_age;
      v15679[v15837] = 0;
      v15725 = v15837;
    } else {
      int * v15682 = v15643->cache_age;
      int v15844 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2);
      int v15683 = v15682[v15844];
      int * v15684 = v15643->cache_tags;
      int v15685 = v15684[v15844];
      int v15686 = v15682[v15822];
      int v15687 = v15684[v15822];
      int * v15688 = v15643->cache_dirty;
      int v15847 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15683 + ((~(((v15685 ^ -1) | (-(v15685 ^ -1))) >> 31)) & 2)) - (v15686 + ((~(((v15687 ^ -1) | (-(v15687 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15689 = v15688[v15847];
      bool v15848 = !(v15689 == 0);
      if (v15848) {
        int * v15690 = v15643->cache_tags;
        int v15691 = v15690[v15847];
        int * v15692 = v15643->cache_vals;
        int v15851 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15683 + ((~(((v15685 ^ -1) | (-(v15685 ^ -1))) >> 31)) & 2)) - (v15686 + ((~(((v15687 ^ -1) | (-(v15687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15693 = v15692[v15851];
        int v15852 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15683 + ((~(((v15685 ^ -1) | (-(v15685 ^ -1))) >> 31)) & 2)) - (v15686 + ((~(((v15687 ^ -1) | (-(v15687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15694 = v15692[v15852];
        int * v15695 = v15643->mem;
        int v15854 = v15691 * 2;
        v15695[v15854] = v15693;
        int * v15697 = v15643->mem;
        int v15857 = (v15691 * 2) + 1;
        v15697[v15857] = v15694;
        ;
      } else {
        ;
      }
      int * v15702 = v15643->mem;
      int v15862 = ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) * 2;
      int v15703 = v15702[v15862];
      int v15863 = (((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) * 2) + 1;
      int v15704 = v15702[v15863];
      int * v15705 = v15643->cache_vals;
      int v15865 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15683 + ((~(((v15685 ^ -1) | (-(v15685 ^ -1))) >> 31)) & 2)) - (v15686 + ((~(((v15687 ^ -1) | (-(v15687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15705[v15865] = v15703;
      int * v15707 = v15643->cache_vals;
      int v15868 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15683 + ((~(((v15685 ^ -1) | (-(v15685 ^ -1))) >> 31)) & 2)) - (v15686 + ((~(((v15687 ^ -1) | (-(v15687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15707[v15868] = v15704;
      int * v15709 = v15643->cache_tags;
      int v15871 = (int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1);
      v15709[v15847] = v15871;
      int * v15711 = v15643->cache_dirty;
      v15711[v15847] = 0;
      int * v15713 = v15643->cache_age;
      v15713[v15847] = 1;
      int * v15715 = v15643->cache_age;
      int v15716 = v15715[v15847];
      int v15717 = v15715[v15821];
      int v15877 = v15717 + ((int)((unsigned int)(v15717 - v15716) >> 31));
      v15715[v15821] = v15877;
      int * v15719 = v15643->cache_age;
      int v15720 = v15719[v15822];
      int v15879 = v15720 + ((int)((unsigned int)(v15720 - v15716) >> 31));
      v15719[v15822] = v15879;
      int * v15722 = v15643->cache_age;
      v15722[v15847] = 0;
      v15725 = v15847;
    }
    int * v15726 = v15643->cache_vals;
    int v15882 = v15725 * 2;
    int v15727 = v15726[v15882];
    int v15883 = (v15725 * 2) + 1;
    int v15728 = v15726[v15883];
    int v15884 = (((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15667 + ((~(((v15669 ^ -1) | (-(v15669 ^ -1))) >> 31)) & 2)) - (v15670 + ((~(((v15671 ^ -1) | (-(v15671 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15726[v15884] = v15727;
    int * v15730 = v15643->cache_vals;
    int v15887 = ((((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15667 + ((~(((v15669 ^ -1) | (-(v15669 ^ -1))) >> 31)) & 2)) - (v15670 + ((~(((v15671 ^ -1) | (-(v15671 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15730[v15887] = v15728;
    int * v15732 = v15643->cache_tags;
    int v15890 = ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v15667 + ((~(((v15669 ^ -1) | (-(v15669 ^ -1))) >> 31)) & 2)) - (v15670 + ((~(((v15671 ^ -1) | (-(v15671 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15891 = (int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1);
    v15732[v15890] = v15891;
    int * v15734 = v15643->cache_dirty;
    v15734[v15890] = 0;
    int * v15736 = v15643->cache_age;
    v15736[v15890] = 1;
    int * v15738 = v15643->cache_age;
    int v15739 = v15738[v15890];
    int v15740 = v15738[v15819];
    int v15897 = v15740 + ((int)((unsigned int)(v15740 - v15739) >> 31));
    v15738[v15819] = v15897;
    int * v15742 = v15643->cache_age;
    int v15743 = v15742[v15820];
    int v15899 = v15743 + ((int)((unsigned int)(v15743 - v15739) >> 31));
    v15742[v15820] = v15899;
    int * v15745 = v15643->cache_age;
    v15745[v15890] = 0;
    v15748 = v15890;
  }
  int * v15749 = v15643->cache_vals;
  int v15902 = (v15748 * 2) + (((int)((unsigned int)(v15647 + 40) >> 2)) & 1);
  v15749[v15902] = v15648;
  int * v15751 = v15643->cache_tags;
  int v15752 = v15751[v15821];
  int v15753 = v15751[v15822];
  bool v15905 = !(((~(((v15752 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15752 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v15753 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15753 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v15807;
  if (v15905) {
    int * v15754 = v15643->cache_age;
    int v15907 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15753 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))) | (-(v15753 ^ ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v15755 = v15754[v15907];
    int v15756 = v15754[v15821];
    int v15908 = v15756 + ((int)((unsigned int)(v15756 - v15755) >> 31));
    v15754[v15821] = v15908;
    int * v15758 = v15643->cache_age;
    int v15759 = v15758[v15822];
    int v15910 = v15759 + ((int)((unsigned int)(v15759 - v15755) >> 31));
    v15758[v15822] = v15910;
    int * v15761 = v15643->cache_age;
    v15761[v15907] = 0;
    v15807 = v15907;
  } else {
    int * v15764 = v15643->cache_age;
    int v15914 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2);
    int v15765 = v15764[v15914];
    int * v15766 = v15643->cache_tags;
    int v15767 = v15766[v15914];
    int v15768 = v15764[v15822];
    int v15769 = v15766[v15822];
    int * v15770 = v15643->cache_dirty;
    int v15917 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15765 + ((~(((v15767 ^ -1) | (-(v15767 ^ -1))) >> 31)) & 2)) - (v15768 + ((~(((v15769 ^ -1) | (-(v15769 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15771 = v15770[v15917];
    bool v15918 = !(v15771 == 0);
    if (v15918) {
      int * v15772 = v15643->cache_tags;
      int v15773 = v15772[v15917];
      int * v15774 = v15643->cache_vals;
      int v15921 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15765 + ((~(((v15767 ^ -1) | (-(v15767 ^ -1))) >> 31)) & 2)) - (v15768 + ((~(((v15769 ^ -1) | (-(v15769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v15775 = v15774[v15921];
      int v15922 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15765 + ((~(((v15767 ^ -1) | (-(v15767 ^ -1))) >> 31)) & 2)) - (v15768 + ((~(((v15769 ^ -1) | (-(v15769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v15776 = v15774[v15922];
      int * v15777 = v15643->mem;
      int v15924 = v15773 * 2;
      v15777[v15924] = v15775;
      int * v15779 = v15643->mem;
      int v15927 = (v15773 * 2) + 1;
      v15779[v15927] = v15776;
      ;
    } else {
      ;
    }
    int * v15784 = v15643->mem;
    int v15932 = ((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) * 2;
    int v15785 = v15784[v15932];
    int v15933 = (((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) * 2) + 1;
    int v15786 = v15784[v15933];
    int * v15787 = v15643->cache_vals;
    int v15935 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15765 + ((~(((v15767 ^ -1) | (-(v15767 ^ -1))) >> 31)) & 2)) - (v15768 + ((~(((v15769 ^ -1) | (-(v15769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15787[v15935] = v15785;
    int * v15789 = v15643->cache_vals;
    int v15938 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v15765 + ((~(((v15767 ^ -1) | (-(v15767 ^ -1))) >> 31)) & 2)) - (v15768 + ((~(((v15769 ^ -1) | (-(v15769 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15789[v15938] = v15786;
    int * v15791 = v15643->cache_tags;
    int v15941 = (int)((unsigned int)((int)((unsigned int)(v15647 + 40) >> 2)) >> 1);
    v15791[v15917] = v15941;
    int * v15793 = v15643->cache_dirty;
    v15793[v15917] = 0;
    int * v15795 = v15643->cache_age;
    v15795[v15917] = 1;
    int * v15797 = v15643->cache_age;
    int v15798 = v15797[v15917];
    int v15799 = v15797[v15821];
    int v15947 = v15799 + ((int)((unsigned int)(v15799 - v15798) >> 31));
    v15797[v15821] = v15947;
    int * v15801 = v15643->cache_age;
    int v15802 = v15801[v15822];
    int v15949 = v15802 + ((int)((unsigned int)(v15802 - v15798) >> 31));
    v15801[v15822] = v15949;
    int * v15804 = v15643->cache_age;
    v15804[v15917] = 0;
    v15807 = v15917;
  }
  int * v15808 = v15643->cache_vals;
  int v15952 = (v15807 * 2) + (((int)((unsigned int)(v15647 + 40) >> 2)) & 1);
  v15808[v15952] = v15648;
  int * v15810 = v15643->cache_dirty;
  v15810[v15807] = 1;
  struct StateT * v15812 = slot_257(v15643);
  return v15812;
}

struct StateT * slot_272(struct StateT * v19817) {
  int v19818 = v19817->timer;
  int v19928 = v19818 + 1;
  v19817->timer = v19928;
  int * v19820 = v19817->regs;
  int v19821 = v19820[2];
  int * v19822 = v19817->cache_tags;
  int v19932 = (((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2;
  int v19823 = v19822[v19932];
  int v19933 = ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19824 = v19822[v19933];
  int v19934 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2);
  int v19825 = v19822[v19934];
  int v19935 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19826 = v19822[v19935];
  int v19827 = v19817->timer;
  int v19936 = v19827 + ((100 ^ (((~(((v19825 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19825 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19823 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19823 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v19824 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19824 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19825 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19825 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19817->timer = v19936;
  int * v19829 = v19817->cache_vals;
  bool v19937 = !(((~(((v19823 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19823 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v19824 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19824 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31))) == 0);
  int v19922;
  if (v19937) {
    int * v19830 = v19817->cache_age;
    int v19939 = ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2) + ((~(((v19824 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19824 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) & 1);
    int v19831 = v19830[v19939];
    int v19832 = v19830[v19932];
    int v19940 = v19832 + ((int)((unsigned int)(v19832 - v19831) >> 31));
    v19830[v19932] = v19940;
    int * v19834 = v19817->cache_age;
    int v19835 = v19834[v19933];
    int v19942 = v19835 + ((int)((unsigned int)(v19835 - v19831) >> 31));
    v19834[v19933] = v19942;
    int * v19837 = v19817->cache_age;
    v19837[v19939] = 0;
    v19922 = v19939;
  } else {
    int * v19840 = v19817->cache_age;
    int v19946 = (((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2;
    int v19841 = v19840[v19946];
    int * v19842 = v19817->cache_tags;
    int v19843 = v19842[v19946];
    int v19844 = v19840[v19933];
    int v19845 = v19842[v19933];
    bool v19948 = !(((~(((v19825 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19825 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31))) == 0);
    int v19899;
    if (v19948) {
      int * v19846 = v19817->cache_age;
      int v19950 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))) | (-(v19826 ^ ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1))))) >> 31)) & 1);
      int v19847 = v19846[v19950];
      int v19848 = v19846[v19934];
      int v19951 = v19848 + ((int)((unsigned int)(v19848 - v19847) >> 31));
      v19846[v19934] = v19951;
      int * v19850 = v19817->cache_age;
      int v19851 = v19850[v19935];
      int v19953 = v19851 + ((int)((unsigned int)(v19851 - v19847) >> 31));
      v19850[v19935] = v19953;
      int * v19853 = v19817->cache_age;
      v19853[v19950] = 0;
      v19899 = v19950;
    } else {
      int * v19856 = v19817->cache_age;
      int v19957 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2);
      int v19857 = v19856[v19957];
      int * v19858 = v19817->cache_tags;
      int v19859 = v19858[v19957];
      int v19860 = v19856[v19935];
      int v19861 = v19858[v19935];
      int * v19862 = v19817->cache_dirty;
      int v19960 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v19857 + ((~(((v19859 ^ -1) | (-(v19859 ^ -1))) >> 31)) & 2)) - (v19860 + ((~(((v19861 ^ -1) | (-(v19861 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19863 = v19862[v19960];
      bool v19961 = !(v19863 == 0);
      if (v19961) {
        int * v19864 = v19817->cache_tags;
        int v19865 = v19864[v19960];
        int * v19866 = v19817->cache_vals;
        int v19964 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v19857 + ((~(((v19859 ^ -1) | (-(v19859 ^ -1))) >> 31)) & 2)) - (v19860 + ((~(((v19861 ^ -1) | (-(v19861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19867 = v19866[v19964];
        int v19965 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v19857 + ((~(((v19859 ^ -1) | (-(v19859 ^ -1))) >> 31)) & 2)) - (v19860 + ((~(((v19861 ^ -1) | (-(v19861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19868 = v19866[v19965];
        int * v19869 = v19817->mem;
        int v19967 = v19865 * 2;
        v19869[v19967] = v19867;
        int * v19871 = v19817->mem;
        int v19970 = (v19865 * 2) + 1;
        v19871[v19970] = v19868;
        ;
      } else {
        ;
      }
      int * v19876 = v19817->mem;
      int v19975 = ((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) * 2;
      int v19877 = v19876[v19975];
      int v19976 = (((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) * 2) + 1;
      int v19878 = v19876[v19976];
      int * v19879 = v19817->cache_vals;
      int v19978 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v19857 + ((~(((v19859 ^ -1) | (-(v19859 ^ -1))) >> 31)) & 2)) - (v19860 + ((~(((v19861 ^ -1) | (-(v19861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19879[v19978] = v19877;
      int * v19881 = v19817->cache_vals;
      int v19981 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v19857 + ((~(((v19859 ^ -1) | (-(v19859 ^ -1))) >> 31)) & 2)) - (v19860 + ((~(((v19861 ^ -1) | (-(v19861 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19881[v19981] = v19878;
      int * v19883 = v19817->cache_tags;
      int v19984 = (int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1);
      v19883[v19960] = v19984;
      int * v19885 = v19817->cache_dirty;
      v19885[v19960] = 0;
      int * v19887 = v19817->cache_age;
      v19887[v19960] = 1;
      int * v19889 = v19817->cache_age;
      int v19890 = v19889[v19960];
      int v19891 = v19889[v19934];
      int v19990 = v19891 + ((int)((unsigned int)(v19891 - v19890) >> 31));
      v19889[v19934] = v19990;
      int * v19893 = v19817->cache_age;
      int v19894 = v19893[v19935];
      int v19992 = v19894 + ((int)((unsigned int)(v19894 - v19890) >> 31));
      v19893[v19935] = v19992;
      int * v19896 = v19817->cache_age;
      v19896[v19960] = 0;
      v19899 = v19960;
    }
    int * v19900 = v19817->cache_vals;
    int v19995 = v19899 * 2;
    int v19901 = v19900[v19995];
    int v19996 = (v19899 * 2) + 1;
    int v19902 = v19900[v19996];
    int v19997 = (((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v19841 + ((~(((v19843 ^ -1) | (-(v19843 ^ -1))) >> 31)) & 2)) - (v19844 + ((~(((v19845 ^ -1) | (-(v19845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19900[v19997] = v19901;
    int * v19904 = v19817->cache_vals;
    int v20000 = ((((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v19841 + ((~(((v19843 ^ -1) | (-(v19843 ^ -1))) >> 31)) & 2)) - (v19844 + ((~(((v19845 ^ -1) | (-(v19845 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19904[v20000] = v19902;
    int * v19906 = v19817->cache_tags;
    int v20003 = ((((int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v19841 + ((~(((v19843 ^ -1) | (-(v19843 ^ -1))) >> 31)) & 2)) - (v19844 + ((~(((v19845 ^ -1) | (-(v19845 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v20004 = (int)((unsigned int)((int)((unsigned int)(v19821 + 52) >> 2)) >> 1);
    v19906[v20003] = v20004;
    int * v19908 = v19817->cache_dirty;
    v19908[v20003] = 0;
    int * v19910 = v19817->cache_age;
    v19910[v20003] = 1;
    int * v19912 = v19817->cache_age;
    int v19913 = v19912[v20003];
    int v19914 = v19912[v19932];
    int v20010 = v19914 + ((int)((unsigned int)(v19914 - v19913) >> 31));
    v19912[v19932] = v20010;
    int * v19916 = v19817->cache_age;
    int v19917 = v19916[v19933];
    int v20012 = v19917 + ((int)((unsigned int)(v19917 - v19913) >> 31));
    v19916[v19933] = v20012;
    int * v19919 = v19817->cache_age;
    v19919[v20003] = 0;
    v19922 = v20003;
  }
  int v20015 = (v19922 * 2) + (((int)((unsigned int)(v19821 + 52) >> 2)) & 1);
  int v19923 = v19829[v20015];
  int * v19924 = v19817->regs;
  v19924[25] = v19923;
  struct StateT * v19926 = slot_273(v19817);
  return v19926;
}

struct StateT * slot_47(struct StateT * v9253) {
  int v9254 = v9253->timer;
  int v9261 = v9254 + 1;
  v9253->timer = v9261;
  int * v9256 = v9253->regs;
  int v9257 = v9256[29];
  v9256[23] = v9257;
  struct StateT * v9259 = slot_48(v9253);
  return v9259;
}

struct StateT * slot_214(struct StateT * v9651) {
  int v9652 = v9651->timer;
  int v9660 = v9652 + 1;
  v9651->timer = v9660;
  int * v9654 = v9651->regs;
  int v9655 = v9654[27];
  int v9656 = v9654[28];
  int v9664 = v9655 + v9656;
  v9654[28] = v9664;
  struct StateT * v9658 = slot_215(v9651);
  return v9658;
}

struct StateT * slot_29(struct StateT * v6594) {
  int v6595 = v6594->timer;
  int v6601 = v6595 + 1;
  v6594->timer = v6601;
  int * v6597 = v6594->regs;
  v6597[14] = 2036477952;
  struct StateT * v6599 = slot_30(v6594);
  return v6599;
}

struct StateT * slot_16(struct StateT * v4324) {
  int v4325 = v4324->timer;
  int v4435 = v4325 + 1;
  v4324->timer = v4435;
  int * v4327 = v4324->regs;
  int v4328 = v4327[12];
  int * v4329 = v4324->cache_tags;
  int v4439 = (((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4330 = v4329[v4439];
  int v4440 = ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4331 = v4329[v4440];
  int v4441 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4332 = v4329[v4441];
  int v4442 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4333 = v4329[v4442];
  int v4334 = v4324->timer;
  int v4443 = v4334 + ((100 ^ (((~(((v4332 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4332 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4330 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4330 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4331 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4331 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4332 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4332 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4324->timer = v4443;
  int * v4336 = v4324->cache_vals;
  bool v4444 = !(((~(((v4330 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4330 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4331 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4331 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4429;
  if (v4444) {
    int * v4337 = v4324->cache_age;
    int v4446 = ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4331 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4331 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4338 = v4337[v4446];
    int v4339 = v4337[v4439];
    int v4447 = v4339 + ((int)((unsigned int)(v4339 - v4338) >> 31));
    v4337[v4439] = v4447;
    int * v4341 = v4324->cache_age;
    int v4342 = v4341[v4440];
    int v4449 = v4342 + ((int)((unsigned int)(v4342 - v4338) >> 31));
    v4341[v4440] = v4449;
    int * v4344 = v4324->cache_age;
    v4344[v4446] = 0;
    v4429 = v4446;
  } else {
    int * v4347 = v4324->cache_age;
    int v4453 = (((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4348 = v4347[v4453];
    int * v4349 = v4324->cache_tags;
    int v4350 = v4349[v4453];
    int v4351 = v4347[v4440];
    int v4352 = v4349[v4440];
    bool v4455 = !(((~(((v4332 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4332 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4406;
    if (v4455) {
      int * v4353 = v4324->cache_age;
      int v4457 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))) | (-(v4333 ^ ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4354 = v4353[v4457];
      int v4355 = v4353[v4441];
      int v4458 = v4355 + ((int)((unsigned int)(v4355 - v4354) >> 31));
      v4353[v4441] = v4458;
      int * v4357 = v4324->cache_age;
      int v4358 = v4357[v4442];
      int v4460 = v4358 + ((int)((unsigned int)(v4358 - v4354) >> 31));
      v4357[v4442] = v4460;
      int * v4360 = v4324->cache_age;
      v4360[v4457] = 0;
      v4406 = v4457;
    } else {
      int * v4363 = v4324->cache_age;
      int v4464 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4364 = v4363[v4464];
      int * v4365 = v4324->cache_tags;
      int v4366 = v4365[v4464];
      int v4367 = v4363[v4442];
      int v4368 = v4365[v4442];
      int * v4369 = v4324->cache_dirty;
      int v4467 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4364 + ((~(((v4366 ^ -1) | (-(v4366 ^ -1))) >> 31)) & 2)) - (v4367 + ((~(((v4368 ^ -1) | (-(v4368 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4370 = v4369[v4467];
      bool v4468 = !(v4370 == 0);
      if (v4468) {
        int * v4371 = v4324->cache_tags;
        int v4372 = v4371[v4467];
        int * v4373 = v4324->cache_vals;
        int v4471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4364 + ((~(((v4366 ^ -1) | (-(v4366 ^ -1))) >> 31)) & 2)) - (v4367 + ((~(((v4368 ^ -1) | (-(v4368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4374 = v4373[v4471];
        int v4472 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4364 + ((~(((v4366 ^ -1) | (-(v4366 ^ -1))) >> 31)) & 2)) - (v4367 + ((~(((v4368 ^ -1) | (-(v4368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4375 = v4373[v4472];
        int * v4376 = v4324->mem;
        int v4474 = v4372 * 2;
        v4376[v4474] = v4374;
        int * v4378 = v4324->mem;
        int v4477 = (v4372 * 2) + 1;
        v4378[v4477] = v4375;
        ;
      } else {
        ;
      }
      int * v4383 = v4324->mem;
      int v4482 = ((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) * 2;
      int v4384 = v4383[v4482];
      int v4483 = (((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4385 = v4383[v4483];
      int * v4386 = v4324->cache_vals;
      int v4485 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4364 + ((~(((v4366 ^ -1) | (-(v4366 ^ -1))) >> 31)) & 2)) - (v4367 + ((~(((v4368 ^ -1) | (-(v4368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4386[v4485] = v4384;
      int * v4388 = v4324->cache_vals;
      int v4488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4364 + ((~(((v4366 ^ -1) | (-(v4366 ^ -1))) >> 31)) & 2)) - (v4367 + ((~(((v4368 ^ -1) | (-(v4368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4388[v4488] = v4385;
      int * v4390 = v4324->cache_tags;
      int v4491 = (int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1);
      v4390[v4467] = v4491;
      int * v4392 = v4324->cache_dirty;
      v4392[v4467] = 0;
      int * v4394 = v4324->cache_age;
      v4394[v4467] = 1;
      int * v4396 = v4324->cache_age;
      int v4397 = v4396[v4467];
      int v4398 = v4396[v4441];
      int v4497 = v4398 + ((int)((unsigned int)(v4398 - v4397) >> 31));
      v4396[v4441] = v4497;
      int * v4400 = v4324->cache_age;
      int v4401 = v4400[v4442];
      int v4499 = v4401 + ((int)((unsigned int)(v4401 - v4397) >> 31));
      v4400[v4442] = v4499;
      int * v4403 = v4324->cache_age;
      v4403[v4467] = 0;
      v4406 = v4467;
    }
    int * v4407 = v4324->cache_vals;
    int v4502 = v4406 * 2;
    int v4408 = v4407[v4502];
    int v4503 = (v4406 * 2) + 1;
    int v4409 = v4407[v4503];
    int v4504 = (((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4348 + ((~(((v4350 ^ -1) | (-(v4350 ^ -1))) >> 31)) & 2)) - (v4351 + ((~(((v4352 ^ -1) | (-(v4352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4407[v4504] = v4408;
    int * v4411 = v4324->cache_vals;
    int v4507 = ((((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4348 + ((~(((v4350 ^ -1) | (-(v4350 ^ -1))) >> 31)) & 2)) - (v4351 + ((~(((v4352 ^ -1) | (-(v4352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4411[v4507] = v4409;
    int * v4413 = v4324->cache_tags;
    int v4510 = ((((int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4348 + ((~(((v4350 ^ -1) | (-(v4350 ^ -1))) >> 31)) & 2)) - (v4351 + ((~(((v4352 ^ -1) | (-(v4352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4511 = (int)((unsigned int)((int)((unsigned int)(v4328 + 4) >> 2)) >> 1);
    v4413[v4510] = v4511;
    int * v4415 = v4324->cache_dirty;
    v4415[v4510] = 0;
    int * v4417 = v4324->cache_age;
    v4417[v4510] = 1;
    int * v4419 = v4324->cache_age;
    int v4420 = v4419[v4510];
    int v4421 = v4419[v4439];
    int v4517 = v4421 + ((int)((unsigned int)(v4421 - v4420) >> 31));
    v4419[v4439] = v4517;
    int * v4423 = v4324->cache_age;
    int v4424 = v4423[v4440];
    int v4519 = v4424 + ((int)((unsigned int)(v4424 - v4420) >> 31));
    v4423[v4440] = v4519;
    int * v4426 = v4324->cache_age;
    v4426[v4510] = 0;
    v4429 = v4510;
  }
  int v4522 = (v4429 * 2) + (((int)((unsigned int)(v4328 + 4) >> 2)) & 1);
  int v4430 = v4336[v4522];
  int * v4431 = v4324->regs;
  v4431[28] = v4430;
  struct StateT * v4433 = slot_17(v4324);
  return v4433;
}

struct StateT * slot_245(struct StateT * v12301) {
  int v12302 = v12301->timer;
  int v12310 = v12302 + 1;
  v12301->timer = v12310;
  int * v12304 = v12301->regs;
  int v12305 = v12304[22];
  int v12306 = v12304[30];
  int v12314 = v12305 + v12306;
  v12304[30] = v12314;
  struct StateT * v12308 = slot_246(v12301);
  return v12308;
}

struct StateT * slot_113(struct StateT * v20494) {
  int v20495 = v20494->timer;
  int v20503 = v20495 + 1;
  v20494->timer = v20503;
  int * v20497 = v20494->regs;
  int v20498 = v20497[18];
  int v20499 = v20497[27];
  int v20508 = v20498 + v20499;
  v20497[17] = v20508;
  struct StateT * v20501 = slot_114(v20494);
  return v20501;
}

struct StateT * slot_151(struct StateT * v21094) {
  int v21095 = v21094->timer;
  int v21103 = v21095 + 1;
  v21094->timer = v21103;
  int * v21097 = v21094->regs;
  int v21098 = v21097[23];
  int v21099 = v21097[21];
  int v21108 = v21098 + v21099;
  v21097[11] = v21108;
  struct StateT * v21101 = slot_152(v21094);
  return v21101;
}

struct StateT * slot_7(struct StateT * v1902) {
  int v1903 = v1902->timer;
  int v2073 = v1903 + 1;
  v1902->timer = v2073;
  int * v1905 = v1902->regs;
  int v1906 = v1905[2];
  int v1907 = v1905[21];
  int * v1908 = v1902->cache_tags;
  int v2078 = (((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1909 = v1908[v2078];
  int v2079 = ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1910 = v1908[v2079];
  int v2080 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1911 = v1908[v2080];
  int v2081 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1912 = v1908[v2081];
  int v1913 = v1902->timer;
  int v2082 = v1913 + ((100 ^ (((~(((v1911 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1911 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1909 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1909 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1910 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1910 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1911 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1911 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1902->timer = v2082;
  bool v2083 = !(((~(((v1909 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1909 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1910 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1910 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2007;
  if (v2083) {
    int * v1915 = v1902->cache_age;
    int v2085 = ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1910 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1910 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1916 = v1915[v2085];
    int v1917 = v1915[v2078];
    int v2086 = v1917 + ((int)((unsigned int)(v1917 - v1916) >> 31));
    v1915[v2078] = v2086;
    int * v1919 = v1902->cache_age;
    int v1920 = v1919[v2079];
    int v2088 = v1920 + ((int)((unsigned int)(v1920 - v1916) >> 31));
    v1919[v2079] = v2088;
    int * v1922 = v1902->cache_age;
    v1922[v2085] = 0;
    v2007 = v2085;
  } else {
    int * v1925 = v1902->cache_age;
    int v2092 = (((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1926 = v1925[v2092];
    int * v1927 = v1902->cache_tags;
    int v1928 = v1927[v2092];
    int v1929 = v1925[v2079];
    int v1930 = v1927[v2079];
    bool v2094 = !(((~(((v1911 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1911 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1984;
    if (v2094) {
      int * v1931 = v1902->cache_age;
      int v2096 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v1912 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1932 = v1931[v2096];
      int v1933 = v1931[v2080];
      int v2097 = v1933 + ((int)((unsigned int)(v1933 - v1932) >> 31));
      v1931[v2080] = v2097;
      int * v1935 = v1902->cache_age;
      int v1936 = v1935[v2081];
      int v2099 = v1936 + ((int)((unsigned int)(v1936 - v1932) >> 31));
      v1935[v2081] = v2099;
      int * v1938 = v1902->cache_age;
      v1938[v2096] = 0;
      v1984 = v2096;
    } else {
      int * v1941 = v1902->cache_age;
      int v2103 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1942 = v1941[v2103];
      int * v1943 = v1902->cache_tags;
      int v1944 = v1943[v2103];
      int v1945 = v1941[v2081];
      int v1946 = v1943[v2081];
      int * v1947 = v1902->cache_dirty;
      int v2106 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1942 + ((~(((v1944 ^ -1) | (-(v1944 ^ -1))) >> 31)) & 2)) - (v1945 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1948 = v1947[v2106];
      bool v2107 = !(v1948 == 0);
      if (v2107) {
        int * v1949 = v1902->cache_tags;
        int v1950 = v1949[v2106];
        int * v1951 = v1902->cache_vals;
        int v2110 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1942 + ((~(((v1944 ^ -1) | (-(v1944 ^ -1))) >> 31)) & 2)) - (v1945 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1952 = v1951[v2110];
        int v2111 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1942 + ((~(((v1944 ^ -1) | (-(v1944 ^ -1))) >> 31)) & 2)) - (v1945 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1953 = v1951[v2111];
        int * v1954 = v1902->mem;
        int v2113 = v1950 * 2;
        v1954[v2113] = v1952;
        int * v1956 = v1902->mem;
        int v2116 = (v1950 * 2) + 1;
        v1956[v2116] = v1953;
        ;
      } else {
        ;
      }
      int * v1961 = v1902->mem;
      int v2121 = ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) * 2;
      int v1962 = v1961[v2121];
      int v2122 = (((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1963 = v1961[v2122];
      int * v1964 = v1902->cache_vals;
      int v2124 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1942 + ((~(((v1944 ^ -1) | (-(v1944 ^ -1))) >> 31)) & 2)) - (v1945 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1964[v2124] = v1962;
      int * v1966 = v1902->cache_vals;
      int v2127 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1942 + ((~(((v1944 ^ -1) | (-(v1944 ^ -1))) >> 31)) & 2)) - (v1945 + ((~(((v1946 ^ -1) | (-(v1946 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1966[v2127] = v1963;
      int * v1968 = v1902->cache_tags;
      int v2130 = (int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1);
      v1968[v2106] = v2130;
      int * v1970 = v1902->cache_dirty;
      v1970[v2106] = 0;
      int * v1972 = v1902->cache_age;
      v1972[v2106] = 1;
      int * v1974 = v1902->cache_age;
      int v1975 = v1974[v2106];
      int v1976 = v1974[v2080];
      int v2136 = v1976 + ((int)((unsigned int)(v1976 - v1975) >> 31));
      v1974[v2080] = v2136;
      int * v1978 = v1902->cache_age;
      int v1979 = v1978[v2081];
      int v2138 = v1979 + ((int)((unsigned int)(v1979 - v1975) >> 31));
      v1978[v2081] = v2138;
      int * v1981 = v1902->cache_age;
      v1981[v2106] = 0;
      v1984 = v2106;
    }
    int * v1985 = v1902->cache_vals;
    int v2141 = v1984 * 2;
    int v1986 = v1985[v2141];
    int v2142 = (v1984 * 2) + 1;
    int v1987 = v1985[v2142];
    int v2143 = (((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1926 + ((~(((v1928 ^ -1) | (-(v1928 ^ -1))) >> 31)) & 2)) - (v1929 + ((~(((v1930 ^ -1) | (-(v1930 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1985[v2143] = v1986;
    int * v1989 = v1902->cache_vals;
    int v2146 = ((((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1926 + ((~(((v1928 ^ -1) | (-(v1928 ^ -1))) >> 31)) & 2)) - (v1929 + ((~(((v1930 ^ -1) | (-(v1930 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1989[v2146] = v1987;
    int * v1991 = v1902->cache_tags;
    int v2149 = ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1926 + ((~(((v1928 ^ -1) | (-(v1928 ^ -1))) >> 31)) & 2)) - (v1929 + ((~(((v1930 ^ -1) | (-(v1930 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2150 = (int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1);
    v1991[v2149] = v2150;
    int * v1993 = v1902->cache_dirty;
    v1993[v2149] = 0;
    int * v1995 = v1902->cache_age;
    v1995[v2149] = 1;
    int * v1997 = v1902->cache_age;
    int v1998 = v1997[v2149];
    int v1999 = v1997[v2078];
    int v2156 = v1999 + ((int)((unsigned int)(v1999 - v1998) >> 31));
    v1997[v2078] = v2156;
    int * v2001 = v1902->cache_age;
    int v2002 = v2001[v2079];
    int v2158 = v2002 + ((int)((unsigned int)(v2002 - v1998) >> 31));
    v2001[v2079] = v2158;
    int * v2004 = v1902->cache_age;
    v2004[v2149] = 0;
    v2007 = v2149;
  }
  int * v2008 = v1902->cache_vals;
  int v2161 = (v2007 * 2) + (((int)((unsigned int)(v1906 + 68) >> 2)) & 1);
  v2008[v2161] = v1907;
  int * v2010 = v1902->cache_tags;
  int v2011 = v2010[v2080];
  int v2012 = v2010[v2081];
  bool v2164 = !(((~(((v2011 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v2011 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2012 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v2012 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2066;
  if (v2164) {
    int * v2013 = v1902->cache_age;
    int v2166 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2012 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))) | (-(v2012 ^ ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2014 = v2013[v2166];
    int v2015 = v2013[v2080];
    int v2167 = v2015 + ((int)((unsigned int)(v2015 - v2014) >> 31));
    v2013[v2080] = v2167;
    int * v2017 = v1902->cache_age;
    int v2018 = v2017[v2081];
    int v2169 = v2018 + ((int)((unsigned int)(v2018 - v2014) >> 31));
    v2017[v2081] = v2169;
    int * v2020 = v1902->cache_age;
    v2020[v2166] = 0;
    v2066 = v2166;
  } else {
    int * v2023 = v1902->cache_age;
    int v2173 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2024 = v2023[v2173];
    int * v2025 = v1902->cache_tags;
    int v2026 = v2025[v2173];
    int v2027 = v2023[v2081];
    int v2028 = v2025[v2081];
    int * v2029 = v1902->cache_dirty;
    int v2176 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2024 + ((~(((v2026 ^ -1) | (-(v2026 ^ -1))) >> 31)) & 2)) - (v2027 + ((~(((v2028 ^ -1) | (-(v2028 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2030 = v2029[v2176];
    bool v2177 = !(v2030 == 0);
    if (v2177) {
      int * v2031 = v1902->cache_tags;
      int v2032 = v2031[v2176];
      int * v2033 = v1902->cache_vals;
      int v2180 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2024 + ((~(((v2026 ^ -1) | (-(v2026 ^ -1))) >> 31)) & 2)) - (v2027 + ((~(((v2028 ^ -1) | (-(v2028 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2034 = v2033[v2180];
      int v2181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2024 + ((~(((v2026 ^ -1) | (-(v2026 ^ -1))) >> 31)) & 2)) - (v2027 + ((~(((v2028 ^ -1) | (-(v2028 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2035 = v2033[v2181];
      int * v2036 = v1902->mem;
      int v2183 = v2032 * 2;
      v2036[v2183] = v2034;
      int * v2038 = v1902->mem;
      int v2186 = (v2032 * 2) + 1;
      v2038[v2186] = v2035;
      ;
    } else {
      ;
    }
    int * v2043 = v1902->mem;
    int v2191 = ((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) * 2;
    int v2044 = v2043[v2191];
    int v2192 = (((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2045 = v2043[v2192];
    int * v2046 = v1902->cache_vals;
    int v2194 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2024 + ((~(((v2026 ^ -1) | (-(v2026 ^ -1))) >> 31)) & 2)) - (v2027 + ((~(((v2028 ^ -1) | (-(v2028 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2046[v2194] = v2044;
    int * v2048 = v1902->cache_vals;
    int v2197 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2024 + ((~(((v2026 ^ -1) | (-(v2026 ^ -1))) >> 31)) & 2)) - (v2027 + ((~(((v2028 ^ -1) | (-(v2028 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2048[v2197] = v2045;
    int * v2050 = v1902->cache_tags;
    int v2200 = (int)((unsigned int)((int)((unsigned int)(v1906 + 68) >> 2)) >> 1);
    v2050[v2176] = v2200;
    int * v2052 = v1902->cache_dirty;
    v2052[v2176] = 0;
    int * v2054 = v1902->cache_age;
    v2054[v2176] = 1;
    int * v2056 = v1902->cache_age;
    int v2057 = v2056[v2176];
    int v2058 = v2056[v2080];
    int v2206 = v2058 + ((int)((unsigned int)(v2058 - v2057) >> 31));
    v2056[v2080] = v2206;
    int * v2060 = v1902->cache_age;
    int v2061 = v2060[v2081];
    int v2208 = v2061 + ((int)((unsigned int)(v2061 - v2057) >> 31));
    v2060[v2081] = v2208;
    int * v2063 = v1902->cache_age;
    v2063[v2176] = 0;
    v2066 = v2176;
  }
  int * v2067 = v1902->cache_vals;
  int v2211 = (v2066 * 2) + (((int)((unsigned int)(v1906 + 68) >> 2)) & 1);
  v2067[v2211] = v1907;
  int * v2069 = v1902->cache_dirty;
  v2069[v2066] = 1;
  struct StateT * v2071 = slot_8(v1902);
  return v2071;
}

struct StateT * slot_124(struct StateT * v20668) {
  int v20669 = v20668->timer;
  int v20676 = v20669 + 1;
  v20668->timer = v20676;
  int * v20671 = v20668->regs;
  int v20672 = v20671[5];
  int v20680 = (int)((unsigned int)v20672 >> 14);
  v20671[6] = v20680;
  struct StateT * v20674 = slot_125(v20668);
  return v20674;
}

struct StateT * slot_191(struct StateT * v21718) {
  int v21719 = v21718->timer;
  int v21727 = v21719 + 1;
  v21718->timer = v21727;
  int * v21721 = v21718->regs;
  int v21722 = v21721[14];
  int v21723 = v21721[27];
  int v21732 = v21722 + v21723;
  v21721[11] = v21732;
  struct StateT * v21725 = slot_192(v21718);
  return v21725;
}

struct StateT * slot_103(struct StateT * v18481) {
  int v18482 = v18481->timer;
  int v18490 = v18482 + 1;
  v18481->timer = v18490;
  int * v18484 = v18481->regs;
  int v18485 = v18484[9];
  int v18486 = v18484[20];
  int v18494 = v18485 | v18486;
  v18484[20] = v18494;
  struct StateT * v18488 = slot_104(v18481);
  return v18488;
}

struct StateT * slot_128(struct StateT * v20729) {
  int v20730 = v20729->timer;
  int v20738 = v20730 + 1;
  v20729->timer = v20738;
  int * v20732 = v20729->regs;
  int v20733 = v20732[11];
  int v20734 = v20732[16];
  int v20743 = v20733 ^ v20734;
  v20732[20] = v20743;
  struct StateT * v20736 = slot_129(v20729);
  return v20736;
}

struct StateT * slot_19(struct StateT * v4936) {
  int v4937 = v4936->timer;
  int v5047 = v4937 + 1;
  v4936->timer = v5047;
  int * v4939 = v4936->regs;
  int v4940 = v4939[12];
  int * v4941 = v4936->cache_tags;
  int v5051 = (((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2;
  int v4942 = v4941[v5051];
  int v5052 = ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4943 = v4941[v5052];
  int v5053 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2);
  int v4944 = v4941[v5053];
  int v5054 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4945 = v4941[v5054];
  int v4946 = v4936->timer;
  int v5055 = v4946 + ((100 ^ (((~(((v4944 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4944 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4942 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4942 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4943 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4943 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4944 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4944 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4936->timer = v5055;
  int * v4948 = v4936->cache_vals;
  bool v5056 = !(((~(((v4942 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4942 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4943 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4943 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v5041;
  if (v5056) {
    int * v4949 = v4936->cache_age;
    int v5058 = ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v4943 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4943 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4950 = v4949[v5058];
    int v4951 = v4949[v5051];
    int v5059 = v4951 + ((int)((unsigned int)(v4951 - v4950) >> 31));
    v4949[v5051] = v5059;
    int * v4953 = v4936->cache_age;
    int v4954 = v4953[v5052];
    int v5061 = v4954 + ((int)((unsigned int)(v4954 - v4950) >> 31));
    v4953[v5052] = v5061;
    int * v4956 = v4936->cache_age;
    v4956[v5058] = 0;
    v5041 = v5058;
  } else {
    int * v4959 = v4936->cache_age;
    int v5065 = (((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2;
    int v4960 = v4959[v5065];
    int * v4961 = v4936->cache_tags;
    int v4962 = v4961[v5065];
    int v4963 = v4959[v5052];
    int v4964 = v4961[v5052];
    bool v5067 = !(((~(((v4944 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4944 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v5018;
    if (v5067) {
      int * v4965 = v4936->cache_age;
      int v5069 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))) | (-(v4945 ^ ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v4966 = v4965[v5069];
      int v4967 = v4965[v5053];
      int v5070 = v4967 + ((int)((unsigned int)(v4967 - v4966) >> 31));
      v4965[v5053] = v5070;
      int * v4969 = v4936->cache_age;
      int v4970 = v4969[v5054];
      int v5072 = v4970 + ((int)((unsigned int)(v4970 - v4966) >> 31));
      v4969[v5054] = v5072;
      int * v4972 = v4936->cache_age;
      v4972[v5069] = 0;
      v5018 = v5069;
    } else {
      int * v4975 = v4936->cache_age;
      int v5076 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2);
      int v4976 = v4975[v5076];
      int * v4977 = v4936->cache_tags;
      int v4978 = v4977[v5076];
      int v4979 = v4975[v5054];
      int v4980 = v4977[v5054];
      int * v4981 = v4936->cache_dirty;
      int v5079 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4976 + ((~(((v4978 ^ -1) | (-(v4978 ^ -1))) >> 31)) & 2)) - (v4979 + ((~(((v4980 ^ -1) | (-(v4980 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4982 = v4981[v5079];
      bool v5080 = !(v4982 == 0);
      if (v5080) {
        int * v4983 = v4936->cache_tags;
        int v4984 = v4983[v5079];
        int * v4985 = v4936->cache_vals;
        int v5083 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4976 + ((~(((v4978 ^ -1) | (-(v4978 ^ -1))) >> 31)) & 2)) - (v4979 + ((~(((v4980 ^ -1) | (-(v4980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4986 = v4985[v5083];
        int v5084 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4976 + ((~(((v4978 ^ -1) | (-(v4978 ^ -1))) >> 31)) & 2)) - (v4979 + ((~(((v4980 ^ -1) | (-(v4980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4987 = v4985[v5084];
        int * v4988 = v4936->mem;
        int v5086 = v4984 * 2;
        v4988[v5086] = v4986;
        int * v4990 = v4936->mem;
        int v5089 = (v4984 * 2) + 1;
        v4990[v5089] = v4987;
        ;
      } else {
        ;
      }
      int * v4995 = v4936->mem;
      int v5094 = ((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) * 2;
      int v4996 = v4995[v5094];
      int v5095 = (((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4997 = v4995[v5095];
      int * v4998 = v4936->cache_vals;
      int v5097 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4976 + ((~(((v4978 ^ -1) | (-(v4978 ^ -1))) >> 31)) & 2)) - (v4979 + ((~(((v4980 ^ -1) | (-(v4980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4998[v5097] = v4996;
      int * v5000 = v4936->cache_vals;
      int v5100 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4976 + ((~(((v4978 ^ -1) | (-(v4978 ^ -1))) >> 31)) & 2)) - (v4979 + ((~(((v4980 ^ -1) | (-(v4980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5000[v5100] = v4997;
      int * v5002 = v4936->cache_tags;
      int v5103 = (int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1);
      v5002[v5079] = v5103;
      int * v5004 = v4936->cache_dirty;
      v5004[v5079] = 0;
      int * v5006 = v4936->cache_age;
      v5006[v5079] = 1;
      int * v5008 = v4936->cache_age;
      int v5009 = v5008[v5079];
      int v5010 = v5008[v5053];
      int v5109 = v5010 + ((int)((unsigned int)(v5010 - v5009) >> 31));
      v5008[v5053] = v5109;
      int * v5012 = v4936->cache_age;
      int v5013 = v5012[v5054];
      int v5111 = v5013 + ((int)((unsigned int)(v5013 - v5009) >> 31));
      v5012[v5054] = v5111;
      int * v5015 = v4936->cache_age;
      v5015[v5079] = 0;
      v5018 = v5079;
    }
    int * v5019 = v4936->cache_vals;
    int v5114 = v5018 * 2;
    int v5020 = v5019[v5114];
    int v5115 = (v5018 * 2) + 1;
    int v5021 = v5019[v5115];
    int v5116 = (((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4960 + ((~(((v4962 ^ -1) | (-(v4962 ^ -1))) >> 31)) & 2)) - (v4963 + ((~(((v4964 ^ -1) | (-(v4964 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5019[v5116] = v5020;
    int * v5023 = v4936->cache_vals;
    int v5119 = ((((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4960 + ((~(((v4962 ^ -1) | (-(v4962 ^ -1))) >> 31)) & 2)) - (v4963 + ((~(((v4964 ^ -1) | (-(v4964 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5023[v5119] = v5021;
    int * v5025 = v4936->cache_tags;
    int v5122 = ((((int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4960 + ((~(((v4962 ^ -1) | (-(v4962 ^ -1))) >> 31)) & 2)) - (v4963 + ((~(((v4964 ^ -1) | (-(v4964 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5123 = (int)((unsigned int)((int)((unsigned int)(v4940 + 16) >> 2)) >> 1);
    v5025[v5122] = v5123;
    int * v5027 = v4936->cache_dirty;
    v5027[v5122] = 0;
    int * v5029 = v4936->cache_age;
    v5029[v5122] = 1;
    int * v5031 = v4936->cache_age;
    int v5032 = v5031[v5122];
    int v5033 = v5031[v5051];
    int v5129 = v5033 + ((int)((unsigned int)(v5033 - v5032) >> 31));
    v5031[v5051] = v5129;
    int * v5035 = v4936->cache_age;
    int v5036 = v5035[v5052];
    int v5131 = v5036 + ((int)((unsigned int)(v5036 - v5032) >> 31));
    v5035[v5052] = v5131;
    int * v5038 = v4936->cache_age;
    v5038[v5122] = 0;
    v5041 = v5122;
  }
  int v5134 = (v5041 * 2) + (((int)((unsigned int)(v4940 + 16) >> 2)) & 1);
  int v5042 = v4948[v5134];
  int * v5043 = v4936->regs;
  v5043[17] = v5042;
  struct StateT * v5045 = slot_20(v4936);
  return v5045;
}

struct StateT * slot_87(struct StateT * v13638) {
  int v13639 = v13638->timer;
  int v13647 = v13639 + 1;
  v13638->timer = v13647;
  int * v13641 = v13638->regs;
  int v13642 = v13641[26];
  int v13643 = v13641[15];
  int v13651 = v13642 ^ v13643;
  v13641[26] = v13651;
  struct StateT * v13645 = slot_88(v13638);
  return v13645;
}

struct StateT * slot_67(struct StateT * v11257) {
  int v11258 = v11257->timer;
  int v11266 = v11258 + 1;
  v11257->timer = v11266;
  int * v11260 = v11257->regs;
  int v11261 = v11260[12];
  int v11262 = v11260[15];
  int v11270 = v11261 ^ v11262;
  v11260[12] = v11270;
  struct StateT * v11264 = slot_68(v11257);
  return v11264;
}

struct StateT * slot_81(struct StateT * v12256) {
  int v12257 = v12256->timer;
  int v12264 = v12257 + 1;
  v12256->timer = v12264;
  int * v12259 = v12256->regs;
  int v12260 = v12259[9];
  int v12268 = (int)((unsigned int)v12260 >> 23);
  v12259[20] = v12268;
  struct StateT * v12262 = slot_82(v12256);
  return v12262;
}

struct StateT * slot_95(struct StateT * v16290) {
  int v16291 = v16290->timer;
  int v16298 = v16291 + 1;
  v16290->timer = v16298;
  int * v16293 = v16290->regs;
  int v16294 = v16293[15];
  int v16302 = (int)((unsigned int)v16294 >> 19);
  v16293[20] = v16302;
  struct StateT * v16296 = slot_96(v16290);
  return v16296;
}

struct StateT * slot_115(struct StateT * v20533) {
  int v20534 = v20533->timer;
  int v20541 = v20534 + 1;
  v20533->timer = v20541;
  int * v20536 = v20533->regs;
  int v20537 = v20536[15];
  int v20545 = (int)((unsigned int)v20537 >> 14);
  v20536[6] = v20545;
  struct StateT * v20539 = slot_116(v20533);
  return v20539;
}

struct StateT * slot_78(struct StateT * v12165) {
  int v12166 = v12165->timer;
  int v12173 = v12166 + 1;
  v12165->timer = v12173;
  int * v12168 = v12165->regs;
  int v12169 = v12168[8];
  int v12177 = (int)((unsigned int)v12169 >> 23);
  v12168[20] = v12177;
  struct StateT * v12171 = slot_79(v12165);
  return v12171;
}

struct StateT * slot_32(struct StateT * v6637) {
  int v6638 = v6637->timer;
  int v6645 = v6638 + 1;
  v6637->timer = v6645;
  int * v6640 = v6637->regs;
  int v6641 = v6640[14];
  int v6649 = v6641 + -718;
  v6640[19] = v6649;
  struct StateT * v6643 = slot_33(v6637);
  return v6643;
}

struct StateT * slot_205(struct StateT * v21936) {
  int v21937 = v21936->timer;
  int v21944 = v21937 + 1;
  v21936->timer = v21944;
  int * v21939 = v21936->regs;
  int v21940 = v21939[8];
  int v21947 = v21940 << 18;
  v21939[8] = v21947;
  struct StateT * v21942 = slot_206(v21936);
  return v21942;
}

struct StateT * slot_193(struct StateT * v21752) {
  int v21753 = v21752->timer;
  int v21761 = v21753 + 1;
  v21752->timer = v21761;
  int * v21755 = v21752->regs;
  int v21756 = v21755[13];
  int v21757 = v21755[26];
  int v21766 = v21756 + v21757;
  v21755[6] = v21766;
  struct StateT * v21759 = slot_194(v21752);
  return v21759;
}

struct StateT * slot_233(struct StateT * v11557) {
  int v11558 = v11557->timer;
  int v11668 = v11558 + 1;
  v11557->timer = v11668;
  int * v11560 = v11557->regs;
  int v11561 = v11560[2];
  int * v11562 = v11557->cache_tags;
  int v11672 = (((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2;
  int v11563 = v11562[v11672];
  int v11673 = ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11564 = v11562[v11673];
  int v11674 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2);
  int v11565 = v11562[v11674];
  int v11675 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11566 = v11562[v11675];
  int v11567 = v11557->timer;
  int v11676 = v11567 + ((100 ^ (((~(((v11565 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11565 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11563 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11563 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11564 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11564 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11565 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11565 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11557->timer = v11676;
  int * v11569 = v11557->cache_vals;
  bool v11677 = !(((~(((v11563 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11563 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11564 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11564 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v11662;
  if (v11677) {
    int * v11570 = v11557->cache_age;
    int v11679 = ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v11564 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11564 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v11571 = v11570[v11679];
    int v11572 = v11570[v11672];
    int v11680 = v11572 + ((int)((unsigned int)(v11572 - v11571) >> 31));
    v11570[v11672] = v11680;
    int * v11574 = v11557->cache_age;
    int v11575 = v11574[v11673];
    int v11682 = v11575 + ((int)((unsigned int)(v11575 - v11571) >> 31));
    v11574[v11673] = v11682;
    int * v11577 = v11557->cache_age;
    v11577[v11679] = 0;
    v11662 = v11679;
  } else {
    int * v11580 = v11557->cache_age;
    int v11686 = (((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2;
    int v11581 = v11580[v11686];
    int * v11582 = v11557->cache_tags;
    int v11583 = v11582[v11686];
    int v11584 = v11580[v11673];
    int v11585 = v11582[v11673];
    bool v11688 = !(((~(((v11565 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11565 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v11639;
    if (v11688) {
      int * v11586 = v11557->cache_age;
      int v11690 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))) | (-(v11566 ^ ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v11587 = v11586[v11690];
      int v11588 = v11586[v11674];
      int v11691 = v11588 + ((int)((unsigned int)(v11588 - v11587) >> 31));
      v11586[v11674] = v11691;
      int * v11590 = v11557->cache_age;
      int v11591 = v11590[v11675];
      int v11693 = v11591 + ((int)((unsigned int)(v11591 - v11587) >> 31));
      v11590[v11675] = v11693;
      int * v11593 = v11557->cache_age;
      v11593[v11690] = 0;
      v11639 = v11690;
    } else {
      int * v11596 = v11557->cache_age;
      int v11697 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2);
      int v11597 = v11596[v11697];
      int * v11598 = v11557->cache_tags;
      int v11599 = v11598[v11697];
      int v11600 = v11596[v11675];
      int v11601 = v11598[v11675];
      int * v11602 = v11557->cache_dirty;
      int v11700 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11597 + ((~(((v11599 ^ -1) | (-(v11599 ^ -1))) >> 31)) & 2)) - (v11600 + ((~(((v11601 ^ -1) | (-(v11601 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11603 = v11602[v11700];
      bool v11701 = !(v11603 == 0);
      if (v11701) {
        int * v11604 = v11557->cache_tags;
        int v11605 = v11604[v11700];
        int * v11606 = v11557->cache_vals;
        int v11704 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11597 + ((~(((v11599 ^ -1) | (-(v11599 ^ -1))) >> 31)) & 2)) - (v11600 + ((~(((v11601 ^ -1) | (-(v11601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11607 = v11606[v11704];
        int v11705 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11597 + ((~(((v11599 ^ -1) | (-(v11599 ^ -1))) >> 31)) & 2)) - (v11600 + ((~(((v11601 ^ -1) | (-(v11601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11608 = v11606[v11705];
        int * v11609 = v11557->mem;
        int v11707 = v11605 * 2;
        v11609[v11707] = v11607;
        int * v11611 = v11557->mem;
        int v11710 = (v11605 * 2) + 1;
        v11611[v11710] = v11608;
        ;
      } else {
        ;
      }
      int * v11616 = v11557->mem;
      int v11715 = ((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) * 2;
      int v11617 = v11616[v11715];
      int v11716 = (((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) * 2) + 1;
      int v11618 = v11616[v11716];
      int * v11619 = v11557->cache_vals;
      int v11718 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11597 + ((~(((v11599 ^ -1) | (-(v11599 ^ -1))) >> 31)) & 2)) - (v11600 + ((~(((v11601 ^ -1) | (-(v11601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11619[v11718] = v11617;
      int * v11621 = v11557->cache_vals;
      int v11721 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11597 + ((~(((v11599 ^ -1) | (-(v11599 ^ -1))) >> 31)) & 2)) - (v11600 + ((~(((v11601 ^ -1) | (-(v11601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11621[v11721] = v11618;
      int * v11623 = v11557->cache_tags;
      int v11724 = (int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1);
      v11623[v11700] = v11724;
      int * v11625 = v11557->cache_dirty;
      v11625[v11700] = 0;
      int * v11627 = v11557->cache_age;
      v11627[v11700] = 1;
      int * v11629 = v11557->cache_age;
      int v11630 = v11629[v11700];
      int v11631 = v11629[v11674];
      int v11730 = v11631 + ((int)((unsigned int)(v11631 - v11630) >> 31));
      v11629[v11674] = v11730;
      int * v11633 = v11557->cache_age;
      int v11634 = v11633[v11675];
      int v11732 = v11634 + ((int)((unsigned int)(v11634 - v11630) >> 31));
      v11633[v11675] = v11732;
      int * v11636 = v11557->cache_age;
      v11636[v11700] = 0;
      v11639 = v11700;
    }
    int * v11640 = v11557->cache_vals;
    int v11735 = v11639 * 2;
    int v11641 = v11640[v11735];
    int v11736 = (v11639 * 2) + 1;
    int v11642 = v11640[v11736];
    int v11737 = (((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11581 + ((~(((v11583 ^ -1) | (-(v11583 ^ -1))) >> 31)) & 2)) - (v11584 + ((~(((v11585 ^ -1) | (-(v11585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11640[v11737] = v11641;
    int * v11644 = v11557->cache_vals;
    int v11740 = ((((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11581 + ((~(((v11583 ^ -1) | (-(v11583 ^ -1))) >> 31)) & 2)) - (v11584 + ((~(((v11585 ^ -1) | (-(v11585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11644[v11740] = v11642;
    int * v11646 = v11557->cache_tags;
    int v11743 = ((((int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11581 + ((~(((v11583 ^ -1) | (-(v11583 ^ -1))) >> 31)) & 2)) - (v11584 + ((~(((v11585 ^ -1) | (-(v11585 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11744 = (int)((unsigned int)((int)((unsigned int)(v11561 + 36) >> 2)) >> 1);
    v11646[v11743] = v11744;
    int * v11648 = v11557->cache_dirty;
    v11648[v11743] = 0;
    int * v11650 = v11557->cache_age;
    v11650[v11743] = 1;
    int * v11652 = v11557->cache_age;
    int v11653 = v11652[v11743];
    int v11654 = v11652[v11672];
    int v11750 = v11654 + ((int)((unsigned int)(v11654 - v11653) >> 31));
    v11652[v11672] = v11750;
    int * v11656 = v11557->cache_age;
    int v11657 = v11656[v11673];
    int v11752 = v11657 + ((int)((unsigned int)(v11657 - v11653) >> 31));
    v11656[v11673] = v11752;
    int * v11659 = v11557->cache_age;
    v11659[v11743] = 0;
    v11662 = v11743;
  }
  int v11755 = (v11662 * 2) + (((int)((unsigned int)(v11561 + 36) >> 2)) & 1);
  int v11663 = v11569[v11755];
  int * v11664 = v11557->regs;
  v11664[30] = v11663;
  struct StateT * v11666 = slot_234(v11557);
  return v11666;
}

struct StateT * slot_176(struct StateT * v21489) {
  int v21490 = v21489->timer;
  int v21497 = v21490 + 1;
  v21489->timer = v21497;
  int * v21492 = v21489->regs;
  int v21493 = v21492[11];
  int v21500 = v21493 << 13;
  v21492[11] = v21500;
  struct StateT * v21495 = slot_177(v21489);
  return v21495;
}

struct StateT * slot_189(struct StateT * v21686) {
  int v21687 = v21686->timer;
  int v21695 = v21687 + 1;
  v21686->timer = v21695;
  int * v21689 = v21686->regs;
  int v21690 = v21689[13];
  int v21691 = v21689[6];
  int v21699 = v21690 ^ v21691;
  v21689[13] = v21699;
  struct StateT * v21693 = slot_190(v21686);
  return v21693;
}

struct StateT * slot_33(struct StateT * v6652) {
  int v6653 = v6652->timer;
  int v6659 = v6653 + 1;
  v6652->timer = v6659;
  int * v6655 = v6652->regs;
  v6655[22] = 1797283840;
  struct StateT * v6657 = slot_34(v6652);
  return v6657;
}

struct StateT * slot_35(struct StateT * v6679) {
  int v6680 = v6679->timer;
  int v6686 = v6680 + 1;
  v6679->timer = v6686;
  int * v6682 = v6679->regs;
  v6682[31] = 9;
  struct StateT * v6684 = slot_36(v6679);
  return v6684;
}

struct StateT * slot_258(struct StateT * v16305) {
  int v16306 = v16305->timer;
  int v16476 = v16306 + 1;
  v16305->timer = v16476;
  int * v16308 = v16305->regs;
  int v16309 = v16308[10];
  int v16310 = v16308[16];
  int * v16311 = v16305->cache_tags;
  int v16481 = (((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2;
  int v16312 = v16311[v16481];
  int v16482 = ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16313 = v16311[v16482];
  int v16483 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2);
  int v16314 = v16311[v16483];
  int v16484 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16315 = v16311[v16484];
  int v16316 = v16305->timer;
  int v16485 = v16316 + ((100 ^ (((~(((v16314 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16314 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16312 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16312 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v16313 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16313 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16314 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16314 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16305->timer = v16485;
  bool v16486 = !(((~(((v16312 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16312 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v16313 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16313 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31))) == 0);
  int v16410;
  if (v16486) {
    int * v16318 = v16305->cache_age;
    int v16488 = ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2) + ((~(((v16313 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16313 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) & 1);
    int v16319 = v16318[v16488];
    int v16320 = v16318[v16481];
    int v16489 = v16320 + ((int)((unsigned int)(v16320 - v16319) >> 31));
    v16318[v16481] = v16489;
    int * v16322 = v16305->cache_age;
    int v16323 = v16322[v16482];
    int v16491 = v16323 + ((int)((unsigned int)(v16323 - v16319) >> 31));
    v16322[v16482] = v16491;
    int * v16325 = v16305->cache_age;
    v16325[v16488] = 0;
    v16410 = v16488;
  } else {
    int * v16328 = v16305->cache_age;
    int v16495 = (((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2;
    int v16329 = v16328[v16495];
    int * v16330 = v16305->cache_tags;
    int v16331 = v16330[v16495];
    int v16332 = v16328[v16482];
    int v16333 = v16330[v16482];
    bool v16497 = !(((~(((v16314 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16314 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31))) == 0);
    int v16387;
    if (v16497) {
      int * v16334 = v16305->cache_age;
      int v16499 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16315 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) & 1);
      int v16335 = v16334[v16499];
      int v16336 = v16334[v16483];
      int v16500 = v16336 + ((int)((unsigned int)(v16336 - v16335) >> 31));
      v16334[v16483] = v16500;
      int * v16338 = v16305->cache_age;
      int v16339 = v16338[v16484];
      int v16502 = v16339 + ((int)((unsigned int)(v16339 - v16335) >> 31));
      v16338[v16484] = v16502;
      int * v16341 = v16305->cache_age;
      v16341[v16499] = 0;
      v16387 = v16499;
    } else {
      int * v16344 = v16305->cache_age;
      int v16506 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2);
      int v16345 = v16344[v16506];
      int * v16346 = v16305->cache_tags;
      int v16347 = v16346[v16506];
      int v16348 = v16344[v16484];
      int v16349 = v16346[v16484];
      int * v16350 = v16305->cache_dirty;
      int v16509 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16345 + ((~(((v16347 ^ -1) | (-(v16347 ^ -1))) >> 31)) & 2)) - (v16348 + ((~(((v16349 ^ -1) | (-(v16349 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16351 = v16350[v16509];
      bool v16510 = !(v16351 == 0);
      if (v16510) {
        int * v16352 = v16305->cache_tags;
        int v16353 = v16352[v16509];
        int * v16354 = v16305->cache_vals;
        int v16513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16345 + ((~(((v16347 ^ -1) | (-(v16347 ^ -1))) >> 31)) & 2)) - (v16348 + ((~(((v16349 ^ -1) | (-(v16349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16355 = v16354[v16513];
        int v16514 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16345 + ((~(((v16347 ^ -1) | (-(v16347 ^ -1))) >> 31)) & 2)) - (v16348 + ((~(((v16349 ^ -1) | (-(v16349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16356 = v16354[v16514];
        int * v16357 = v16305->mem;
        int v16516 = v16353 * 2;
        v16357[v16516] = v16355;
        int * v16359 = v16305->mem;
        int v16519 = (v16353 * 2) + 1;
        v16359[v16519] = v16356;
        ;
      } else {
        ;
      }
      int * v16364 = v16305->mem;
      int v16524 = ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) * 2;
      int v16365 = v16364[v16524];
      int v16525 = (((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) * 2) + 1;
      int v16366 = v16364[v16525];
      int * v16367 = v16305->cache_vals;
      int v16527 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16345 + ((~(((v16347 ^ -1) | (-(v16347 ^ -1))) >> 31)) & 2)) - (v16348 + ((~(((v16349 ^ -1) | (-(v16349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16367[v16527] = v16365;
      int * v16369 = v16305->cache_vals;
      int v16530 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16345 + ((~(((v16347 ^ -1) | (-(v16347 ^ -1))) >> 31)) & 2)) - (v16348 + ((~(((v16349 ^ -1) | (-(v16349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16369[v16530] = v16366;
      int * v16371 = v16305->cache_tags;
      int v16533 = (int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1);
      v16371[v16509] = v16533;
      int * v16373 = v16305->cache_dirty;
      v16373[v16509] = 0;
      int * v16375 = v16305->cache_age;
      v16375[v16509] = 1;
      int * v16377 = v16305->cache_age;
      int v16378 = v16377[v16509];
      int v16379 = v16377[v16483];
      int v16539 = v16379 + ((int)((unsigned int)(v16379 - v16378) >> 31));
      v16377[v16483] = v16539;
      int * v16381 = v16305->cache_age;
      int v16382 = v16381[v16484];
      int v16541 = v16382 + ((int)((unsigned int)(v16382 - v16378) >> 31));
      v16381[v16484] = v16541;
      int * v16384 = v16305->cache_age;
      v16384[v16509] = 0;
      v16387 = v16509;
    }
    int * v16388 = v16305->cache_vals;
    int v16544 = v16387 * 2;
    int v16389 = v16388[v16544];
    int v16545 = (v16387 * 2) + 1;
    int v16390 = v16388[v16545];
    int v16546 = (((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v16329 + ((~(((v16331 ^ -1) | (-(v16331 ^ -1))) >> 31)) & 2)) - (v16332 + ((~(((v16333 ^ -1) | (-(v16333 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16388[v16546] = v16389;
    int * v16392 = v16305->cache_vals;
    int v16549 = ((((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v16329 + ((~(((v16331 ^ -1) | (-(v16331 ^ -1))) >> 31)) & 2)) - (v16332 + ((~(((v16333 ^ -1) | (-(v16333 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16392[v16549] = v16390;
    int * v16394 = v16305->cache_tags;
    int v16552 = ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v16329 + ((~(((v16331 ^ -1) | (-(v16331 ^ -1))) >> 31)) & 2)) - (v16332 + ((~(((v16333 ^ -1) | (-(v16333 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16553 = (int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1);
    v16394[v16552] = v16553;
    int * v16396 = v16305->cache_dirty;
    v16396[v16552] = 0;
    int * v16398 = v16305->cache_age;
    v16398[v16552] = 1;
    int * v16400 = v16305->cache_age;
    int v16401 = v16400[v16552];
    int v16402 = v16400[v16481];
    int v16559 = v16402 + ((int)((unsigned int)(v16402 - v16401) >> 31));
    v16400[v16481] = v16559;
    int * v16404 = v16305->cache_age;
    int v16405 = v16404[v16482];
    int v16561 = v16405 + ((int)((unsigned int)(v16405 - v16401) >> 31));
    v16404[v16482] = v16561;
    int * v16407 = v16305->cache_age;
    v16407[v16552] = 0;
    v16410 = v16552;
  }
  int * v16411 = v16305->cache_vals;
  int v16564 = (v16410 * 2) + (((int)((unsigned int)(v16309 + 48) >> 2)) & 1);
  v16411[v16564] = v16310;
  int * v16413 = v16305->cache_tags;
  int v16414 = v16413[v16483];
  int v16415 = v16413[v16484];
  bool v16567 = !(((~(((v16414 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16414 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v16415 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16415 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31))) == 0);
  int v16469;
  if (v16567) {
    int * v16416 = v16305->cache_age;
    int v16569 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16415 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))) | (-(v16415 ^ ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1))))) >> 31)) & 1);
    int v16417 = v16416[v16569];
    int v16418 = v16416[v16483];
    int v16570 = v16418 + ((int)((unsigned int)(v16418 - v16417) >> 31));
    v16416[v16483] = v16570;
    int * v16420 = v16305->cache_age;
    int v16421 = v16420[v16484];
    int v16572 = v16421 + ((int)((unsigned int)(v16421 - v16417) >> 31));
    v16420[v16484] = v16572;
    int * v16423 = v16305->cache_age;
    v16423[v16569] = 0;
    v16469 = v16569;
  } else {
    int * v16426 = v16305->cache_age;
    int v16576 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2);
    int v16427 = v16426[v16576];
    int * v16428 = v16305->cache_tags;
    int v16429 = v16428[v16576];
    int v16430 = v16426[v16484];
    int v16431 = v16428[v16484];
    int * v16432 = v16305->cache_dirty;
    int v16579 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16427 + ((~(((v16429 ^ -1) | (-(v16429 ^ -1))) >> 31)) & 2)) - (v16430 + ((~(((v16431 ^ -1) | (-(v16431 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16433 = v16432[v16579];
    bool v16580 = !(v16433 == 0);
    if (v16580) {
      int * v16434 = v16305->cache_tags;
      int v16435 = v16434[v16579];
      int * v16436 = v16305->cache_vals;
      int v16583 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16427 + ((~(((v16429 ^ -1) | (-(v16429 ^ -1))) >> 31)) & 2)) - (v16430 + ((~(((v16431 ^ -1) | (-(v16431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v16437 = v16436[v16583];
      int v16584 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16427 + ((~(((v16429 ^ -1) | (-(v16429 ^ -1))) >> 31)) & 2)) - (v16430 + ((~(((v16431 ^ -1) | (-(v16431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v16438 = v16436[v16584];
      int * v16439 = v16305->mem;
      int v16586 = v16435 * 2;
      v16439[v16586] = v16437;
      int * v16441 = v16305->mem;
      int v16589 = (v16435 * 2) + 1;
      v16441[v16589] = v16438;
      ;
    } else {
      ;
    }
    int * v16446 = v16305->mem;
    int v16594 = ((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) * 2;
    int v16447 = v16446[v16594];
    int v16595 = (((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) * 2) + 1;
    int v16448 = v16446[v16595];
    int * v16449 = v16305->cache_vals;
    int v16597 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16427 + ((~(((v16429 ^ -1) | (-(v16429 ^ -1))) >> 31)) & 2)) - (v16430 + ((~(((v16431 ^ -1) | (-(v16431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16449[v16597] = v16447;
    int * v16451 = v16305->cache_vals;
    int v16600 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v16427 + ((~(((v16429 ^ -1) | (-(v16429 ^ -1))) >> 31)) & 2)) - (v16430 + ((~(((v16431 ^ -1) | (-(v16431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16451[v16600] = v16448;
    int * v16453 = v16305->cache_tags;
    int v16603 = (int)((unsigned int)((int)((unsigned int)(v16309 + 48) >> 2)) >> 1);
    v16453[v16579] = v16603;
    int * v16455 = v16305->cache_dirty;
    v16455[v16579] = 0;
    int * v16457 = v16305->cache_age;
    v16457[v16579] = 1;
    int * v16459 = v16305->cache_age;
    int v16460 = v16459[v16579];
    int v16461 = v16459[v16483];
    int v16609 = v16461 + ((int)((unsigned int)(v16461 - v16460) >> 31));
    v16459[v16483] = v16609;
    int * v16463 = v16305->cache_age;
    int v16464 = v16463[v16484];
    int v16611 = v16464 + ((int)((unsigned int)(v16464 - v16460) >> 31));
    v16463[v16484] = v16611;
    int * v16466 = v16305->cache_age;
    v16466[v16579] = 0;
    v16469 = v16579;
  }
  int * v16470 = v16305->cache_vals;
  int v16614 = (v16469 * 2) + (((int)((unsigned int)(v16309 + 48) >> 2)) & 1);
  v16470[v16614] = v16310;
  int * v16472 = v16305->cache_dirty;
  v16472[v16469] = 1;
  struct StateT * v16474 = slot_259(v16305);
  return v16474;
}

struct StateT * slot_246(struct StateT * v12333) {
  int v12334 = v12333->timer;
  int v12504 = v12334 + 1;
  v12333->timer = v12504;
  int * v12336 = v12333->regs;
  int v12337 = v12336[10];
  int v12338 = v12336[15];
  int * v12339 = v12333->cache_tags;
  int v12509 = (((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2;
  int v12340 = v12339[v12509];
  int v12510 = ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2) + 1;
  int v12341 = v12339[v12510];
  int v12511 = 4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2);
  int v12342 = v12339[v12511];
  int v12512 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12343 = v12339[v12512];
  int v12344 = v12333->timer;
  int v12513 = v12344 + ((100 ^ (((~(((v12342 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12342 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) | (~(((v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12340 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12340 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) | (~(((v12341 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12341 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12342 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12342 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) | (~(((v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31))) & 104)))));
  v12333->timer = v12513;
  bool v12514 = !(((~(((v12340 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12340 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) | (~(((v12341 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12341 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31))) == 0);
  int v12438;
  if (v12514) {
    int * v12346 = v12333->cache_age;
    int v12516 = ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2) + ((~(((v12341 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12341 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) & 1);
    int v12347 = v12346[v12516];
    int v12348 = v12346[v12509];
    int v12517 = v12348 + ((int)((unsigned int)(v12348 - v12347) >> 31));
    v12346[v12509] = v12517;
    int * v12350 = v12333->cache_age;
    int v12351 = v12350[v12510];
    int v12519 = v12351 + ((int)((unsigned int)(v12351 - v12347) >> 31));
    v12350[v12510] = v12519;
    int * v12353 = v12333->cache_age;
    v12353[v12516] = 0;
    v12438 = v12516;
  } else {
    int * v12356 = v12333->cache_age;
    int v12523 = (((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2;
    int v12357 = v12356[v12523];
    int * v12358 = v12333->cache_tags;
    int v12359 = v12358[v12523];
    int v12360 = v12356[v12510];
    int v12361 = v12358[v12510];
    bool v12525 = !(((~(((v12342 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12342 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) | (~(((v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31))) == 0);
    int v12415;
    if (v12525) {
      int * v12362 = v12333->cache_age;
      int v12527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((~(((v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12343 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) & 1);
      int v12363 = v12362[v12527];
      int v12364 = v12362[v12511];
      int v12528 = v12364 + ((int)((unsigned int)(v12364 - v12363) >> 31));
      v12362[v12511] = v12528;
      int * v12366 = v12333->cache_age;
      int v12367 = v12366[v12512];
      int v12530 = v12367 + ((int)((unsigned int)(v12367 - v12363) >> 31));
      v12366[v12512] = v12530;
      int * v12369 = v12333->cache_age;
      v12369[v12527] = 0;
      v12415 = v12527;
    } else {
      int * v12372 = v12333->cache_age;
      int v12534 = 4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2);
      int v12373 = v12372[v12534];
      int * v12374 = v12333->cache_tags;
      int v12375 = v12374[v12534];
      int v12376 = v12372[v12512];
      int v12377 = v12374[v12512];
      int * v12378 = v12333->cache_dirty;
      int v12537 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12373 + ((~(((v12375 ^ -1) | (-(v12375 ^ -1))) >> 31)) & 2)) - (v12376 + ((~(((v12377 ^ -1) | (-(v12377 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12379 = v12378[v12537];
      bool v12538 = !(v12379 == 0);
      if (v12538) {
        int * v12380 = v12333->cache_tags;
        int v12381 = v12380[v12537];
        int * v12382 = v12333->cache_vals;
        int v12541 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12373 + ((~(((v12375 ^ -1) | (-(v12375 ^ -1))) >> 31)) & 2)) - (v12376 + ((~(((v12377 ^ -1) | (-(v12377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12383 = v12382[v12541];
        int v12542 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12373 + ((~(((v12375 ^ -1) | (-(v12375 ^ -1))) >> 31)) & 2)) - (v12376 + ((~(((v12377 ^ -1) | (-(v12377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12384 = v12382[v12542];
        int * v12385 = v12333->mem;
        int v12544 = v12381 * 2;
        v12385[v12544] = v12383;
        int * v12387 = v12333->mem;
        int v12547 = (v12381 * 2) + 1;
        v12387[v12547] = v12384;
        ;
      } else {
        ;
      }
      int * v12392 = v12333->mem;
      int v12552 = ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) * 2;
      int v12393 = v12392[v12552];
      int v12553 = (((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) * 2) + 1;
      int v12394 = v12392[v12553];
      int * v12395 = v12333->cache_vals;
      int v12555 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12373 + ((~(((v12375 ^ -1) | (-(v12375 ^ -1))) >> 31)) & 2)) - (v12376 + ((~(((v12377 ^ -1) | (-(v12377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12395[v12555] = v12393;
      int * v12397 = v12333->cache_vals;
      int v12558 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12373 + ((~(((v12375 ^ -1) | (-(v12375 ^ -1))) >> 31)) & 2)) - (v12376 + ((~(((v12377 ^ -1) | (-(v12377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12397[v12558] = v12394;
      int * v12399 = v12333->cache_tags;
      int v12561 = (int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1);
      v12399[v12537] = v12561;
      int * v12401 = v12333->cache_dirty;
      v12401[v12537] = 0;
      int * v12403 = v12333->cache_age;
      v12403[v12537] = 1;
      int * v12405 = v12333->cache_age;
      int v12406 = v12405[v12537];
      int v12407 = v12405[v12511];
      int v12567 = v12407 + ((int)((unsigned int)(v12407 - v12406) >> 31));
      v12405[v12511] = v12567;
      int * v12409 = v12333->cache_age;
      int v12410 = v12409[v12512];
      int v12569 = v12410 + ((int)((unsigned int)(v12410 - v12406) >> 31));
      v12409[v12512] = v12569;
      int * v12412 = v12333->cache_age;
      v12412[v12537] = 0;
      v12415 = v12537;
    }
    int * v12416 = v12333->cache_vals;
    int v12572 = v12415 * 2;
    int v12417 = v12416[v12572];
    int v12573 = (v12415 * 2) + 1;
    int v12418 = v12416[v12573];
    int v12574 = (((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2) + ((((v12357 + ((~(((v12359 ^ -1) | (-(v12359 ^ -1))) >> 31)) & 2)) - (v12360 + ((~(((v12361 ^ -1) | (-(v12361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12416[v12574] = v12417;
    int * v12420 = v12333->cache_vals;
    int v12577 = ((((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2) + ((((v12357 + ((~(((v12359 ^ -1) | (-(v12359 ^ -1))) >> 31)) & 2)) - (v12360 + ((~(((v12361 ^ -1) | (-(v12361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12420[v12577] = v12418;
    int * v12422 = v12333->cache_tags;
    int v12580 = ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 1) * 2) + ((((v12357 + ((~(((v12359 ^ -1) | (-(v12359 ^ -1))) >> 31)) & 2)) - (v12360 + ((~(((v12361 ^ -1) | (-(v12361 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12581 = (int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1);
    v12422[v12580] = v12581;
    int * v12424 = v12333->cache_dirty;
    v12424[v12580] = 0;
    int * v12426 = v12333->cache_age;
    v12426[v12580] = 1;
    int * v12428 = v12333->cache_age;
    int v12429 = v12428[v12580];
    int v12430 = v12428[v12509];
    int v12587 = v12430 + ((int)((unsigned int)(v12430 - v12429) >> 31));
    v12428[v12509] = v12587;
    int * v12432 = v12333->cache_age;
    int v12433 = v12432[v12510];
    int v12589 = v12433 + ((int)((unsigned int)(v12433 - v12429) >> 31));
    v12432[v12510] = v12589;
    int * v12435 = v12333->cache_age;
    v12435[v12580] = 0;
    v12438 = v12580;
  }
  int * v12439 = v12333->cache_vals;
  int v12592 = (v12438 * 2) + (((int)((unsigned int)v12337 >> 2)) & 1);
  v12439[v12592] = v12338;
  int * v12441 = v12333->cache_tags;
  int v12442 = v12441[v12511];
  int v12443 = v12441[v12512];
  bool v12595 = !(((~(((v12442 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12442 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) | (~(((v12443 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12443 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31))) == 0);
  int v12497;
  if (v12595) {
    int * v12444 = v12333->cache_age;
    int v12597 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((~(((v12443 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))) | (-(v12443 ^ ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1))))) >> 31)) & 1);
    int v12445 = v12444[v12597];
    int v12446 = v12444[v12511];
    int v12598 = v12446 + ((int)((unsigned int)(v12446 - v12445) >> 31));
    v12444[v12511] = v12598;
    int * v12448 = v12333->cache_age;
    int v12449 = v12448[v12512];
    int v12600 = v12449 + ((int)((unsigned int)(v12449 - v12445) >> 31));
    v12448[v12512] = v12600;
    int * v12451 = v12333->cache_age;
    v12451[v12597] = 0;
    v12497 = v12597;
  } else {
    int * v12454 = v12333->cache_age;
    int v12604 = 4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2);
    int v12455 = v12454[v12604];
    int * v12456 = v12333->cache_tags;
    int v12457 = v12456[v12604];
    int v12458 = v12454[v12512];
    int v12459 = v12456[v12512];
    int * v12460 = v12333->cache_dirty;
    int v12607 = (4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12455 + ((~(((v12457 ^ -1) | (-(v12457 ^ -1))) >> 31)) & 2)) - (v12458 + ((~(((v12459 ^ -1) | (-(v12459 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12461 = v12460[v12607];
    bool v12608 = !(v12461 == 0);
    if (v12608) {
      int * v12462 = v12333->cache_tags;
      int v12463 = v12462[v12607];
      int * v12464 = v12333->cache_vals;
      int v12611 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12455 + ((~(((v12457 ^ -1) | (-(v12457 ^ -1))) >> 31)) & 2)) - (v12458 + ((~(((v12459 ^ -1) | (-(v12459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12465 = v12464[v12611];
      int v12612 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12455 + ((~(((v12457 ^ -1) | (-(v12457 ^ -1))) >> 31)) & 2)) - (v12458 + ((~(((v12459 ^ -1) | (-(v12459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12466 = v12464[v12612];
      int * v12467 = v12333->mem;
      int v12614 = v12463 * 2;
      v12467[v12614] = v12465;
      int * v12469 = v12333->mem;
      int v12617 = (v12463 * 2) + 1;
      v12469[v12617] = v12466;
      ;
    } else {
      ;
    }
    int * v12474 = v12333->mem;
    int v12622 = ((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) * 2;
    int v12475 = v12474[v12622];
    int v12623 = (((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) * 2) + 1;
    int v12476 = v12474[v12623];
    int * v12477 = v12333->cache_vals;
    int v12625 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12455 + ((~(((v12457 ^ -1) | (-(v12457 ^ -1))) >> 31)) & 2)) - (v12458 + ((~(((v12459 ^ -1) | (-(v12459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12477[v12625] = v12475;
    int * v12479 = v12333->cache_vals;
    int v12628 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1)) & 3) * 2)) + ((((v12455 + ((~(((v12457 ^ -1) | (-(v12457 ^ -1))) >> 31)) & 2)) - (v12458 + ((~(((v12459 ^ -1) | (-(v12459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12479[v12628] = v12476;
    int * v12481 = v12333->cache_tags;
    int v12631 = (int)((unsigned int)((int)((unsigned int)v12337 >> 2)) >> 1);
    v12481[v12607] = v12631;
    int * v12483 = v12333->cache_dirty;
    v12483[v12607] = 0;
    int * v12485 = v12333->cache_age;
    v12485[v12607] = 1;
    int * v12487 = v12333->cache_age;
    int v12488 = v12487[v12607];
    int v12489 = v12487[v12511];
    int v12637 = v12489 + ((int)((unsigned int)(v12489 - v12488) >> 31));
    v12487[v12511] = v12637;
    int * v12491 = v12333->cache_age;
    int v12492 = v12491[v12512];
    int v12639 = v12492 + ((int)((unsigned int)(v12492 - v12488) >> 31));
    v12491[v12512] = v12639;
    int * v12494 = v12333->cache_age;
    v12494[v12607] = 0;
    v12497 = v12607;
  }
  int * v12498 = v12333->cache_vals;
  int v12642 = (v12497 * 2) + (((int)((unsigned int)v12337 >> 2)) & 1);
  v12498[v12642] = v12338;
  int * v12500 = v12333->cache_dirty;
  v12500[v12497] = 1;
  struct StateT * v12502 = slot_247(v12333);
  return v12502;
}

struct StateT * slot_210(struct StateT * v22015) {
  int v22016 = v22015->timer;
  int v22024 = v22016 + 1;
  v22015->timer = v22024;
  int * v22018 = v22015->regs;
  int v22019 = v22018[22];
  int v22020 = v22018[8];
  int v22028 = v22019 ^ v22020;
  v22018[22] = v22028;
  struct StateT * v22022 = slot_211(v22015);
  return v22022;
}

struct StateT * slot_166(struct StateT * v21326) {
  int v21327 = v21326->timer;
  int v21335 = v21327 + 1;
  v21326->timer = v21335;
  int * v21329 = v21326->regs;
  int v21330 = v21329[8];
  int v21331 = v21329[9];
  int v21339 = v21330 | v21331;
  v21329[8] = v21339;
  struct StateT * v21333 = slot_167(v21326);
  return v21333;
}

struct StateT * slot_51(struct StateT * v9634) {
  int v9635 = v9634->timer;
  int v9643 = v9635 + 1;
  v9634->timer = v9643;
  int * v9637 = v9634->regs;
  int v9638 = v9637[21];
  int v9639 = v9637[16];
  int v9648 = v9638 + v9639;
  v9637[15] = v9648;
  struct StateT * v9641 = slot_52(v9634);
  return v9641;
}

struct StateT * slot_52(struct StateT * v9667) {
  int v9668 = v9667->timer;
  int v9676 = v9668 + 1;
  v9667->timer = v9676;
  int * v9670 = v9667->regs;
  int v9671 = v9670[11];
  int v9672 = v9670[23];
  int v9681 = v9671 + v9672;
  v9670[20] = v9681;
  struct StateT * v9674 = slot_53(v9667);
  return v9674;
}

struct StateT * slot_83(struct StateT * v12317) {
  int v12318 = v12317->timer;
  int v12326 = v12318 + 1;
  v12317->timer = v12326;
  int * v12320 = v12317->regs;
  int v12321 = v12320[9];
  int v12322 = v12320[20];
  int v12330 = v12321 | v12322;
  v12320[9] = v12330;
  struct StateT * v12324 = slot_84(v12317);
  return v12324;
}

struct StateT * slot_25(struct StateT * v6160) {
  int v6161 = v6160->timer;
  int v6271 = v6161 + 1;
  v6160->timer = v6271;
  int * v6163 = v6160->regs;
  int v6164 = v6163[11];
  int * v6165 = v6160->cache_tags;
  int v6275 = (((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2;
  int v6166 = v6165[v6275];
  int v6276 = ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6167 = v6165[v6276];
  int v6277 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2);
  int v6168 = v6165[v6277];
  int v6278 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6169 = v6165[v6278];
  int v6170 = v6160->timer;
  int v6279 = v6170 + ((100 ^ (((~(((v6168 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6168 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6166 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6166 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6167 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6167 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6168 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6168 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6160->timer = v6279;
  int * v6172 = v6160->cache_vals;
  bool v6280 = !(((~(((v6166 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6166 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6167 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6167 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v6265;
  if (v6280) {
    int * v6173 = v6160->cache_age;
    int v6282 = ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v6167 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6167 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v6174 = v6173[v6282];
    int v6175 = v6173[v6275];
    int v6283 = v6175 + ((int)((unsigned int)(v6175 - v6174) >> 31));
    v6173[v6275] = v6283;
    int * v6177 = v6160->cache_age;
    int v6178 = v6177[v6276];
    int v6285 = v6178 + ((int)((unsigned int)(v6178 - v6174) >> 31));
    v6177[v6276] = v6285;
    int * v6180 = v6160->cache_age;
    v6180[v6282] = 0;
    v6265 = v6282;
  } else {
    int * v6183 = v6160->cache_age;
    int v6289 = (((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2;
    int v6184 = v6183[v6289];
    int * v6185 = v6160->cache_tags;
    int v6186 = v6185[v6289];
    int v6187 = v6183[v6276];
    int v6188 = v6185[v6276];
    bool v6291 = !(((~(((v6168 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6168 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v6242;
    if (v6291) {
      int * v6189 = v6160->cache_age;
      int v6293 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v6190 = v6189[v6293];
      int v6191 = v6189[v6277];
      int v6294 = v6191 + ((int)((unsigned int)(v6191 - v6190) >> 31));
      v6189[v6277] = v6294;
      int * v6193 = v6160->cache_age;
      int v6194 = v6193[v6278];
      int v6296 = v6194 + ((int)((unsigned int)(v6194 - v6190) >> 31));
      v6193[v6278] = v6296;
      int * v6196 = v6160->cache_age;
      v6196[v6293] = 0;
      v6242 = v6293;
    } else {
      int * v6199 = v6160->cache_age;
      int v6300 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2);
      int v6200 = v6199[v6300];
      int * v6201 = v6160->cache_tags;
      int v6202 = v6201[v6300];
      int v6203 = v6199[v6278];
      int v6204 = v6201[v6278];
      int * v6205 = v6160->cache_dirty;
      int v6303 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6200 + ((~(((v6202 ^ -1) | (-(v6202 ^ -1))) >> 31)) & 2)) - (v6203 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6206 = v6205[v6303];
      bool v6304 = !(v6206 == 0);
      if (v6304) {
        int * v6207 = v6160->cache_tags;
        int v6208 = v6207[v6303];
        int * v6209 = v6160->cache_vals;
        int v6307 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6200 + ((~(((v6202 ^ -1) | (-(v6202 ^ -1))) >> 31)) & 2)) - (v6203 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6210 = v6209[v6307];
        int v6308 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6200 + ((~(((v6202 ^ -1) | (-(v6202 ^ -1))) >> 31)) & 2)) - (v6203 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6211 = v6209[v6308];
        int * v6212 = v6160->mem;
        int v6310 = v6208 * 2;
        v6212[v6310] = v6210;
        int * v6214 = v6160->mem;
        int v6313 = (v6208 * 2) + 1;
        v6214[v6313] = v6211;
        ;
      } else {
        ;
      }
      int * v6219 = v6160->mem;
      int v6318 = ((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) * 2;
      int v6220 = v6219[v6318];
      int v6319 = (((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) * 2) + 1;
      int v6221 = v6219[v6319];
      int * v6222 = v6160->cache_vals;
      int v6321 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6200 + ((~(((v6202 ^ -1) | (-(v6202 ^ -1))) >> 31)) & 2)) - (v6203 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6222[v6321] = v6220;
      int * v6224 = v6160->cache_vals;
      int v6324 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6200 + ((~(((v6202 ^ -1) | (-(v6202 ^ -1))) >> 31)) & 2)) - (v6203 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6224[v6324] = v6221;
      int * v6226 = v6160->cache_tags;
      int v6327 = (int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1);
      v6226[v6303] = v6327;
      int * v6228 = v6160->cache_dirty;
      v6228[v6303] = 0;
      int * v6230 = v6160->cache_age;
      v6230[v6303] = 1;
      int * v6232 = v6160->cache_age;
      int v6233 = v6232[v6303];
      int v6234 = v6232[v6277];
      int v6333 = v6234 + ((int)((unsigned int)(v6234 - v6233) >> 31));
      v6232[v6277] = v6333;
      int * v6236 = v6160->cache_age;
      int v6237 = v6236[v6278];
      int v6335 = v6237 + ((int)((unsigned int)(v6237 - v6233) >> 31));
      v6236[v6278] = v6335;
      int * v6239 = v6160->cache_age;
      v6239[v6303] = 0;
      v6242 = v6303;
    }
    int * v6243 = v6160->cache_vals;
    int v6338 = v6242 * 2;
    int v6244 = v6243[v6338];
    int v6339 = (v6242 * 2) + 1;
    int v6245 = v6243[v6339];
    int v6340 = (((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6184 + ((~(((v6186 ^ -1) | (-(v6186 ^ -1))) >> 31)) & 2)) - (v6187 + ((~(((v6188 ^ -1) | (-(v6188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6243[v6340] = v6244;
    int * v6247 = v6160->cache_vals;
    int v6343 = ((((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6184 + ((~(((v6186 ^ -1) | (-(v6186 ^ -1))) >> 31)) & 2)) - (v6187 + ((~(((v6188 ^ -1) | (-(v6188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6247[v6343] = v6245;
    int * v6249 = v6160->cache_tags;
    int v6346 = ((((int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6184 + ((~(((v6186 ^ -1) | (-(v6186 ^ -1))) >> 31)) & 2)) - (v6187 + ((~(((v6188 ^ -1) | (-(v6188 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6347 = (int)((unsigned int)((int)((unsigned int)(v6164 + 8) >> 2)) >> 1);
    v6249[v6346] = v6347;
    int * v6251 = v6160->cache_dirty;
    v6251[v6346] = 0;
    int * v6253 = v6160->cache_age;
    v6253[v6346] = 1;
    int * v6255 = v6160->cache_age;
    int v6256 = v6255[v6346];
    int v6257 = v6255[v6275];
    int v6353 = v6257 + ((int)((unsigned int)(v6257 - v6256) >> 31));
    v6255[v6275] = v6353;
    int * v6259 = v6160->cache_age;
    int v6260 = v6259[v6276];
    int v6355 = v6260 + ((int)((unsigned int)(v6260 - v6256) >> 31));
    v6259[v6276] = v6355;
    int * v6262 = v6160->cache_age;
    v6262[v6346] = 0;
    v6265 = v6346;
  }
  int v6358 = (v6265 * 2) + (((int)((unsigned int)(v6164 + 8) >> 2)) & 1);
  int v6266 = v6172[v6358];
  int * v6267 = v6160->regs;
  v6267[26] = v6266;
  struct StateT * v6269 = slot_26(v6160);
  return v6269;
}

struct StateT * slot_209(struct StateT * v21999) {
  int v22000 = v21999->timer;
  int v22008 = v22000 + 1;
  v21999->timer = v22008;
  int * v22002 = v21999->regs;
  int v22003 = v22002[19];
  int v22004 = v22002[6];
  int v22012 = v22003 ^ v22004;
  v22002[19] = v22012;
  struct StateT * v22006 = slot_210(v21999);
  return v22006;
}

struct StateT * slot_3(struct StateT * v642) {
  int v643 = v642->timer;
  int v813 = v643 + 1;
  v642->timer = v813;
  int * v645 = v642->regs;
  int v646 = v645[2];
  int v647 = v645[9];
  int * v648 = v642->cache_tags;
  int v818 = (((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2;
  int v649 = v648[v818];
  int v819 = ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2) + 1;
  int v650 = v648[v819];
  int v820 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2);
  int v651 = v648[v820];
  int v821 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v652 = v648[v821];
  int v653 = v642->timer;
  int v822 = v653 + ((100 ^ (((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31))) & 104)))));
  v642->timer = v822;
  bool v823 = !(((~(((v649 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v649 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31))) == 0);
  int v747;
  if (v823) {
    int * v655 = v642->cache_age;
    int v825 = ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2) + ((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) & 1);
    int v656 = v655[v825];
    int v657 = v655[v818];
    int v826 = v657 + ((int)((unsigned int)(v657 - v656) >> 31));
    v655[v818] = v826;
    int * v659 = v642->cache_age;
    int v660 = v659[v819];
    int v828 = v660 + ((int)((unsigned int)(v660 - v656) >> 31));
    v659[v819] = v828;
    int * v662 = v642->cache_age;
    v662[v825] = 0;
    v747 = v825;
  } else {
    int * v665 = v642->cache_age;
    int v832 = (((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2;
    int v666 = v665[v832];
    int * v667 = v642->cache_tags;
    int v668 = v667[v832];
    int v669 = v665[v819];
    int v670 = v667[v819];
    bool v834 = !(((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31))) == 0);
    int v724;
    if (v834) {
      int * v671 = v642->cache_age;
      int v836 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) & 1);
      int v672 = v671[v836];
      int v673 = v671[v820];
      int v837 = v673 + ((int)((unsigned int)(v673 - v672) >> 31));
      v671[v820] = v837;
      int * v675 = v642->cache_age;
      int v676 = v675[v821];
      int v839 = v676 + ((int)((unsigned int)(v676 - v672) >> 31));
      v675[v821] = v839;
      int * v678 = v642->cache_age;
      v678[v836] = 0;
      v724 = v836;
    } else {
      int * v681 = v642->cache_age;
      int v843 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2);
      int v682 = v681[v843];
      int * v683 = v642->cache_tags;
      int v684 = v683[v843];
      int v685 = v681[v821];
      int v686 = v683[v821];
      int * v687 = v642->cache_dirty;
      int v846 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v688 = v687[v846];
      bool v847 = !(v688 == 0);
      if (v847) {
        int * v689 = v642->cache_tags;
        int v690 = v689[v846];
        int * v691 = v642->cache_vals;
        int v850 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v692 = v691[v850];
        int v851 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v693 = v691[v851];
        int * v694 = v642->mem;
        int v853 = v690 * 2;
        v694[v853] = v692;
        int * v696 = v642->mem;
        int v856 = (v690 * 2) + 1;
        v696[v856] = v693;
        ;
      } else {
        ;
      }
      int * v701 = v642->mem;
      int v861 = ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) * 2;
      int v702 = v701[v861];
      int v862 = (((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) * 2) + 1;
      int v703 = v701[v862];
      int * v704 = v642->cache_vals;
      int v864 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v704[v864] = v702;
      int * v706 = v642->cache_vals;
      int v867 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v682 + ((~(((v684 ^ -1) | (-(v684 ^ -1))) >> 31)) & 2)) - (v685 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v706[v867] = v703;
      int * v708 = v642->cache_tags;
      int v870 = (int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1);
      v708[v846] = v870;
      int * v710 = v642->cache_dirty;
      v710[v846] = 0;
      int * v712 = v642->cache_age;
      v712[v846] = 1;
      int * v714 = v642->cache_age;
      int v715 = v714[v846];
      int v716 = v714[v820];
      int v876 = v716 + ((int)((unsigned int)(v716 - v715) >> 31));
      v714[v820] = v876;
      int * v718 = v642->cache_age;
      int v719 = v718[v821];
      int v878 = v719 + ((int)((unsigned int)(v719 - v715) >> 31));
      v718[v821] = v878;
      int * v721 = v642->cache_age;
      v721[v846] = 0;
      v724 = v846;
    }
    int * v725 = v642->cache_vals;
    int v881 = v724 * 2;
    int v726 = v725[v881];
    int v882 = (v724 * 2) + 1;
    int v727 = v725[v882];
    int v883 = (((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v725[v883] = v726;
    int * v729 = v642->cache_vals;
    int v886 = ((((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v729[v886] = v727;
    int * v731 = v642->cache_tags;
    int v889 = ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 1) * 2) + ((((v666 + ((~(((v668 ^ -1) | (-(v668 ^ -1))) >> 31)) & 2)) - (v669 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v890 = (int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1);
    v731[v889] = v890;
    int * v733 = v642->cache_dirty;
    v733[v889] = 0;
    int * v735 = v642->cache_age;
    v735[v889] = 1;
    int * v737 = v642->cache_age;
    int v738 = v737[v889];
    int v739 = v737[v818];
    int v896 = v739 + ((int)((unsigned int)(v739 - v738) >> 31));
    v737[v818] = v896;
    int * v741 = v642->cache_age;
    int v742 = v741[v819];
    int v898 = v742 + ((int)((unsigned int)(v742 - v738) >> 31));
    v741[v819] = v898;
    int * v744 = v642->cache_age;
    v744[v889] = 0;
    v747 = v889;
  }
  int * v748 = v642->cache_vals;
  int v901 = (v747 * 2) + (((int)((unsigned int)(v646 + 84) >> 2)) & 1);
  v748[v901] = v647;
  int * v750 = v642->cache_tags;
  int v751 = v750[v820];
  int v752 = v750[v821];
  bool v904 = !(((~(((v751 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v751 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31))) == 0);
  int v806;
  if (v904) {
    int * v753 = v642->cache_age;
    int v906 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((~(((v752 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))) | (-(v752 ^ ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1))))) >> 31)) & 1);
    int v754 = v753[v906];
    int v755 = v753[v820];
    int v907 = v755 + ((int)((unsigned int)(v755 - v754) >> 31));
    v753[v820] = v907;
    int * v757 = v642->cache_age;
    int v758 = v757[v821];
    int v909 = v758 + ((int)((unsigned int)(v758 - v754) >> 31));
    v757[v821] = v909;
    int * v760 = v642->cache_age;
    v760[v906] = 0;
    v806 = v906;
  } else {
    int * v763 = v642->cache_age;
    int v913 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2);
    int v764 = v763[v913];
    int * v765 = v642->cache_tags;
    int v766 = v765[v913];
    int v767 = v763[v821];
    int v768 = v765[v821];
    int * v769 = v642->cache_dirty;
    int v916 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v770 = v769[v916];
    bool v917 = !(v770 == 0);
    if (v917) {
      int * v771 = v642->cache_tags;
      int v772 = v771[v916];
      int * v773 = v642->cache_vals;
      int v920 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v774 = v773[v920];
      int v921 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v775 = v773[v921];
      int * v776 = v642->mem;
      int v923 = v772 * 2;
      v776[v923] = v774;
      int * v778 = v642->mem;
      int v926 = (v772 * 2) + 1;
      v778[v926] = v775;
      ;
    } else {
      ;
    }
    int * v783 = v642->mem;
    int v931 = ((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) * 2;
    int v784 = v783[v931];
    int v932 = (((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) * 2) + 1;
    int v785 = v783[v932];
    int * v786 = v642->cache_vals;
    int v934 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v786[v934] = v784;
    int * v788 = v642->cache_vals;
    int v937 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v764 + ((~(((v766 ^ -1) | (-(v766 ^ -1))) >> 31)) & 2)) - (v767 + ((~(((v768 ^ -1) | (-(v768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v788[v937] = v785;
    int * v790 = v642->cache_tags;
    int v940 = (int)((unsigned int)((int)((unsigned int)(v646 + 84) >> 2)) >> 1);
    v790[v916] = v940;
    int * v792 = v642->cache_dirty;
    v792[v916] = 0;
    int * v794 = v642->cache_age;
    v794[v916] = 1;
    int * v796 = v642->cache_age;
    int v797 = v796[v916];
    int v798 = v796[v820];
    int v946 = v798 + ((int)((unsigned int)(v798 - v797) >> 31));
    v796[v820] = v946;
    int * v800 = v642->cache_age;
    int v801 = v800[v821];
    int v948 = v801 + ((int)((unsigned int)(v801 - v797) >> 31));
    v800[v821] = v948;
    int * v803 = v642->cache_age;
    v803[v916] = 0;
    v806 = v916;
  }
  int * v807 = v642->cache_vals;
  int v951 = (v806 * 2) + (((int)((unsigned int)(v646 + 84) >> 2)) & 1);
  v807[v951] = v647;
  int * v809 = v642->cache_dirty;
  v809[v806] = 1;
  struct StateT * v811 = slot_4(v642);
  return v811;
}

struct StateT * slot_264(struct StateT * v18059) {
  int v18060 = v18059->timer;
  int v18170 = v18060 + 1;
  v18059->timer = v18170;
  int * v18062 = v18059->regs;
  int v18063 = v18062[2];
  int * v18064 = v18059->cache_tags;
  int v18174 = (((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2;
  int v18065 = v18064[v18174];
  int v18175 = ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18066 = v18064[v18175];
  int v18176 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2);
  int v18067 = v18064[v18176];
  int v18177 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18068 = v18064[v18177];
  int v18069 = v18059->timer;
  int v18178 = v18069 + ((100 ^ (((~(((v18067 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18067 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18065 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18065 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v18066 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18066 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18067 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18067 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18059->timer = v18178;
  int * v18071 = v18059->cache_vals;
  bool v18179 = !(((~(((v18065 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18065 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v18066 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18066 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31))) == 0);
  int v18164;
  if (v18179) {
    int * v18072 = v18059->cache_age;
    int v18181 = ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2) + ((~(((v18066 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18066 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) & 1);
    int v18073 = v18072[v18181];
    int v18074 = v18072[v18174];
    int v18182 = v18074 + ((int)((unsigned int)(v18074 - v18073) >> 31));
    v18072[v18174] = v18182;
    int * v18076 = v18059->cache_age;
    int v18077 = v18076[v18175];
    int v18184 = v18077 + ((int)((unsigned int)(v18077 - v18073) >> 31));
    v18076[v18175] = v18184;
    int * v18079 = v18059->cache_age;
    v18079[v18181] = 0;
    v18164 = v18181;
  } else {
    int * v18082 = v18059->cache_age;
    int v18188 = (((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2;
    int v18083 = v18082[v18188];
    int * v18084 = v18059->cache_tags;
    int v18085 = v18084[v18188];
    int v18086 = v18082[v18175];
    int v18087 = v18084[v18175];
    bool v18190 = !(((~(((v18067 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18067 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) | (~(((v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31))) == 0);
    int v18141;
    if (v18190) {
      int * v18088 = v18059->cache_age;
      int v18192 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))) | (-(v18068 ^ ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1))))) >> 31)) & 1);
      int v18089 = v18088[v18192];
      int v18090 = v18088[v18176];
      int v18193 = v18090 + ((int)((unsigned int)(v18090 - v18089) >> 31));
      v18088[v18176] = v18193;
      int * v18092 = v18059->cache_age;
      int v18093 = v18092[v18177];
      int v18195 = v18093 + ((int)((unsigned int)(v18093 - v18089) >> 31));
      v18092[v18177] = v18195;
      int * v18095 = v18059->cache_age;
      v18095[v18192] = 0;
      v18141 = v18192;
    } else {
      int * v18098 = v18059->cache_age;
      int v18199 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2);
      int v18099 = v18098[v18199];
      int * v18100 = v18059->cache_tags;
      int v18101 = v18100[v18199];
      int v18102 = v18098[v18177];
      int v18103 = v18100[v18177];
      int * v18104 = v18059->cache_dirty;
      int v18202 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v18099 + ((~(((v18101 ^ -1) | (-(v18101 ^ -1))) >> 31)) & 2)) - (v18102 + ((~(((v18103 ^ -1) | (-(v18103 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18105 = v18104[v18202];
      bool v18203 = !(v18105 == 0);
      if (v18203) {
        int * v18106 = v18059->cache_tags;
        int v18107 = v18106[v18202];
        int * v18108 = v18059->cache_vals;
        int v18206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v18099 + ((~(((v18101 ^ -1) | (-(v18101 ^ -1))) >> 31)) & 2)) - (v18102 + ((~(((v18103 ^ -1) | (-(v18103 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18109 = v18108[v18206];
        int v18207 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v18099 + ((~(((v18101 ^ -1) | (-(v18101 ^ -1))) >> 31)) & 2)) - (v18102 + ((~(((v18103 ^ -1) | (-(v18103 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18110 = v18108[v18207];
        int * v18111 = v18059->mem;
        int v18209 = v18107 * 2;
        v18111[v18209] = v18109;
        int * v18113 = v18059->mem;
        int v18212 = (v18107 * 2) + 1;
        v18113[v18212] = v18110;
        ;
      } else {
        ;
      }
      int * v18118 = v18059->mem;
      int v18217 = ((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) * 2;
      int v18119 = v18118[v18217];
      int v18218 = (((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) * 2) + 1;
      int v18120 = v18118[v18218];
      int * v18121 = v18059->cache_vals;
      int v18220 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v18099 + ((~(((v18101 ^ -1) | (-(v18101 ^ -1))) >> 31)) & 2)) - (v18102 + ((~(((v18103 ^ -1) | (-(v18103 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18121[v18220] = v18119;
      int * v18123 = v18059->cache_vals;
      int v18223 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 3) * 2)) + ((((v18099 + ((~(((v18101 ^ -1) | (-(v18101 ^ -1))) >> 31)) & 2)) - (v18102 + ((~(((v18103 ^ -1) | (-(v18103 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18123[v18223] = v18120;
      int * v18125 = v18059->cache_tags;
      int v18226 = (int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1);
      v18125[v18202] = v18226;
      int * v18127 = v18059->cache_dirty;
      v18127[v18202] = 0;
      int * v18129 = v18059->cache_age;
      v18129[v18202] = 1;
      int * v18131 = v18059->cache_age;
      int v18132 = v18131[v18202];
      int v18133 = v18131[v18176];
      int v18232 = v18133 + ((int)((unsigned int)(v18133 - v18132) >> 31));
      v18131[v18176] = v18232;
      int * v18135 = v18059->cache_age;
      int v18136 = v18135[v18177];
      int v18234 = v18136 + ((int)((unsigned int)(v18136 - v18132) >> 31));
      v18135[v18177] = v18234;
      int * v18138 = v18059->cache_age;
      v18138[v18202] = 0;
      v18141 = v18202;
    }
    int * v18142 = v18059->cache_vals;
    int v18237 = v18141 * 2;
    int v18143 = v18142[v18237];
    int v18238 = (v18141 * 2) + 1;
    int v18144 = v18142[v18238];
    int v18239 = (((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2) + ((((v18083 + ((~(((v18085 ^ -1) | (-(v18085 ^ -1))) >> 31)) & 2)) - (v18086 + ((~(((v18087 ^ -1) | (-(v18087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18142[v18239] = v18143;
    int * v18146 = v18059->cache_vals;
    int v18242 = ((((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2) + ((((v18083 + ((~(((v18085 ^ -1) | (-(v18085 ^ -1))) >> 31)) & 2)) - (v18086 + ((~(((v18087 ^ -1) | (-(v18087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18146[v18242] = v18144;
    int * v18148 = v18059->cache_tags;
    int v18245 = ((((int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1)) & 1) * 2) + ((((v18083 + ((~(((v18085 ^ -1) | (-(v18085 ^ -1))) >> 31)) & 2)) - (v18086 + ((~(((v18087 ^ -1) | (-(v18087 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18246 = (int)((unsigned int)((int)((unsigned int)(v18063 + 84) >> 2)) >> 1);
    v18148[v18245] = v18246;
    int * v18150 = v18059->cache_dirty;
    v18150[v18245] = 0;
    int * v18152 = v18059->cache_age;
    v18152[v18245] = 1;
    int * v18154 = v18059->cache_age;
    int v18155 = v18154[v18245];
    int v18156 = v18154[v18174];
    int v18252 = v18156 + ((int)((unsigned int)(v18156 - v18155) >> 31));
    v18154[v18174] = v18252;
    int * v18158 = v18059->cache_age;
    int v18159 = v18158[v18175];
    int v18254 = v18159 + ((int)((unsigned int)(v18159 - v18155) >> 31));
    v18158[v18175] = v18254;
    int * v18161 = v18059->cache_age;
    v18161[v18245] = 0;
    v18164 = v18245;
  }
  int v18257 = (v18164 * 2) + (((int)((unsigned int)(v18063 + 84) >> 2)) & 1);
  int v18165 = v18071[v18257];
  int * v18166 = v18059->regs;
  v18166[9] = v18165;
  struct StateT * v18168 = slot_265(v18059);
  return v18168;
}

struct StateT * slot_123(struct StateT * v20652) {
  int v20653 = v20652->timer;
  int v20661 = v20653 + 1;
  v20652->timer = v20661;
  int * v20655 = v20652->regs;
  int v20656 = v20655[17];
  int v20657 = v20655[6];
  int v20665 = v20656 | v20657;
  v20655[17] = v20665;
  struct StateT * v20659 = slot_124(v20652);
  return v20659;
}

struct StateT * slot_73(struct StateT * v12015) {
  int v12016 = v12015->timer;
  int v12024 = v12016 + 1;
  v12015->timer = v12024;
  int * v12018 = v12015->regs;
  int v12019 = v12018[1];
  int v12020 = v12018[19];
  int v12029 = v12019 + v12020;
  v12018[9] = v12029;
  struct StateT * v12022 = slot_74(v12015);
  return v12022;
}

struct StateT * slot_270(struct StateT * v19376) {
  int v19377 = v19376->timer;
  int v19487 = v19377 + 1;
  v19376->timer = v19487;
  int * v19379 = v19376->regs;
  int v19380 = v19379[2];
  int * v19381 = v19376->cache_tags;
  int v19491 = (((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2;
  int v19382 = v19381[v19491];
  int v19492 = ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19383 = v19381[v19492];
  int v19493 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2);
  int v19384 = v19381[v19493];
  int v19494 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19385 = v19381[v19494];
  int v19386 = v19376->timer;
  int v19495 = v19386 + ((100 ^ (((~(((v19384 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19384 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19382 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19382 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v19383 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19383 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19384 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19384 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19376->timer = v19495;
  int * v19388 = v19376->cache_vals;
  bool v19496 = !(((~(((v19382 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19382 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v19383 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19383 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31))) == 0);
  int v19481;
  if (v19496) {
    int * v19389 = v19376->cache_age;
    int v19498 = ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2) + ((~(((v19383 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19383 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) & 1);
    int v19390 = v19389[v19498];
    int v19391 = v19389[v19491];
    int v19499 = v19391 + ((int)((unsigned int)(v19391 - v19390) >> 31));
    v19389[v19491] = v19499;
    int * v19393 = v19376->cache_age;
    int v19394 = v19393[v19492];
    int v19501 = v19394 + ((int)((unsigned int)(v19394 - v19390) >> 31));
    v19393[v19492] = v19501;
    int * v19396 = v19376->cache_age;
    v19396[v19498] = 0;
    v19481 = v19498;
  } else {
    int * v19399 = v19376->cache_age;
    int v19505 = (((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2;
    int v19400 = v19399[v19505];
    int * v19401 = v19376->cache_tags;
    int v19402 = v19401[v19505];
    int v19403 = v19399[v19492];
    int v19404 = v19401[v19492];
    bool v19507 = !(((~(((v19384 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19384 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31))) == 0);
    int v19458;
    if (v19507) {
      int * v19405 = v19376->cache_age;
      int v19509 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))) | (-(v19385 ^ ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1))))) >> 31)) & 1);
      int v19406 = v19405[v19509];
      int v19407 = v19405[v19493];
      int v19510 = v19407 + ((int)((unsigned int)(v19407 - v19406) >> 31));
      v19405[v19493] = v19510;
      int * v19409 = v19376->cache_age;
      int v19410 = v19409[v19494];
      int v19512 = v19410 + ((int)((unsigned int)(v19410 - v19406) >> 31));
      v19409[v19494] = v19512;
      int * v19412 = v19376->cache_age;
      v19412[v19509] = 0;
      v19458 = v19509;
    } else {
      int * v19415 = v19376->cache_age;
      int v19516 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2);
      int v19416 = v19415[v19516];
      int * v19417 = v19376->cache_tags;
      int v19418 = v19417[v19516];
      int v19419 = v19415[v19494];
      int v19420 = v19417[v19494];
      int * v19421 = v19376->cache_dirty;
      int v19519 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v19416 + ((~(((v19418 ^ -1) | (-(v19418 ^ -1))) >> 31)) & 2)) - (v19419 + ((~(((v19420 ^ -1) | (-(v19420 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19422 = v19421[v19519];
      bool v19520 = !(v19422 == 0);
      if (v19520) {
        int * v19423 = v19376->cache_tags;
        int v19424 = v19423[v19519];
        int * v19425 = v19376->cache_vals;
        int v19523 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v19416 + ((~(((v19418 ^ -1) | (-(v19418 ^ -1))) >> 31)) & 2)) - (v19419 + ((~(((v19420 ^ -1) | (-(v19420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19426 = v19425[v19523];
        int v19524 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v19416 + ((~(((v19418 ^ -1) | (-(v19418 ^ -1))) >> 31)) & 2)) - (v19419 + ((~(((v19420 ^ -1) | (-(v19420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19427 = v19425[v19524];
        int * v19428 = v19376->mem;
        int v19526 = v19424 * 2;
        v19428[v19526] = v19426;
        int * v19430 = v19376->mem;
        int v19529 = (v19424 * 2) + 1;
        v19430[v19529] = v19427;
        ;
      } else {
        ;
      }
      int * v19435 = v19376->mem;
      int v19534 = ((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) * 2;
      int v19436 = v19435[v19534];
      int v19535 = (((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) * 2) + 1;
      int v19437 = v19435[v19535];
      int * v19438 = v19376->cache_vals;
      int v19537 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v19416 + ((~(((v19418 ^ -1) | (-(v19418 ^ -1))) >> 31)) & 2)) - (v19419 + ((~(((v19420 ^ -1) | (-(v19420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19438[v19537] = v19436;
      int * v19440 = v19376->cache_vals;
      int v19540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v19416 + ((~(((v19418 ^ -1) | (-(v19418 ^ -1))) >> 31)) & 2)) - (v19419 + ((~(((v19420 ^ -1) | (-(v19420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19440[v19540] = v19437;
      int * v19442 = v19376->cache_tags;
      int v19543 = (int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1);
      v19442[v19519] = v19543;
      int * v19444 = v19376->cache_dirty;
      v19444[v19519] = 0;
      int * v19446 = v19376->cache_age;
      v19446[v19519] = 1;
      int * v19448 = v19376->cache_age;
      int v19449 = v19448[v19519];
      int v19450 = v19448[v19493];
      int v19549 = v19450 + ((int)((unsigned int)(v19450 - v19449) >> 31));
      v19448[v19493] = v19549;
      int * v19452 = v19376->cache_age;
      int v19453 = v19452[v19494];
      int v19551 = v19453 + ((int)((unsigned int)(v19453 - v19449) >> 31));
      v19452[v19494] = v19551;
      int * v19455 = v19376->cache_age;
      v19455[v19519] = 0;
      v19458 = v19519;
    }
    int * v19459 = v19376->cache_vals;
    int v19554 = v19458 * 2;
    int v19460 = v19459[v19554];
    int v19555 = (v19458 * 2) + 1;
    int v19461 = v19459[v19555];
    int v19556 = (((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v19400 + ((~(((v19402 ^ -1) | (-(v19402 ^ -1))) >> 31)) & 2)) - (v19403 + ((~(((v19404 ^ -1) | (-(v19404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19459[v19556] = v19460;
    int * v19463 = v19376->cache_vals;
    int v19559 = ((((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v19400 + ((~(((v19402 ^ -1) | (-(v19402 ^ -1))) >> 31)) & 2)) - (v19403 + ((~(((v19404 ^ -1) | (-(v19404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19463[v19559] = v19461;
    int * v19465 = v19376->cache_tags;
    int v19562 = ((((int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v19400 + ((~(((v19402 ^ -1) | (-(v19402 ^ -1))) >> 31)) & 2)) - (v19403 + ((~(((v19404 ^ -1) | (-(v19404 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19563 = (int)((unsigned int)((int)((unsigned int)(v19380 + 60) >> 2)) >> 1);
    v19465[v19562] = v19563;
    int * v19467 = v19376->cache_dirty;
    v19467[v19562] = 0;
    int * v19469 = v19376->cache_age;
    v19469[v19562] = 1;
    int * v19471 = v19376->cache_age;
    int v19472 = v19471[v19562];
    int v19473 = v19471[v19491];
    int v19569 = v19473 + ((int)((unsigned int)(v19473 - v19472) >> 31));
    v19471[v19491] = v19569;
    int * v19475 = v19376->cache_age;
    int v19476 = v19475[v19492];
    int v19571 = v19476 + ((int)((unsigned int)(v19476 - v19472) >> 31));
    v19475[v19492] = v19571;
    int * v19478 = v19376->cache_age;
    v19478[v19562] = 0;
    v19481 = v19562;
  }
  int v19574 = (v19481 * 2) + (((int)((unsigned int)(v19380 + 60) >> 2)) & 1);
  int v19482 = v19388[v19574];
  int * v19483 = v19376->regs;
  v19483[23] = v19482;
  struct StateT * v19485 = slot_271(v19376);
  return v19485;
}

struct StateT * slot_198(struct StateT * v21831) {
  int v21832 = v21831->timer;
  int v21839 = v21832 + 1;
  v21831->timer = v21839;
  int * v21834 = v21831->regs;
  int v21835 = v21834[15];
  int v21843 = (int)((unsigned int)v21835 >> 14);
  v21834[9] = v21843;
  struct StateT * v21837 = slot_199(v21831);
  return v21837;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v187 = v17 + 1;
  v16->timer = v187;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[1];
  int * v22 = v16->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2;
  int v23 = v22[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2) + 1;
  int v24 = v22[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2);
  int v25 = v22[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26 = v22[v195];
  int v27 = v16->timer;
  int v196 = v27 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16->timer = v196;
  bool v197 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31))) == 0);
  int v121;
  if (v197) {
    int * v29 = v16->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v206 = (((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2;
    int v40 = v39[v206];
    int * v41 = v16->cache_tags;
    int v42 = v41[v206];
    int v43 = v39[v193];
    int v44 = v41[v193];
    bool v208 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31))) == 0);
    int v98;
    if (v208) {
      int * v45 = v16->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) & 1);
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
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2);
      int v56 = v55[v217];
      int * v57 = v16->cache_tags;
      int v58 = v57[v217];
      int v59 = v55[v195];
      int v60 = v57[v195];
      int * v61 = v16->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v62 = v61[v220];
      bool v221 = !(v62 == 0);
      if (v221) {
        int * v63 = v16->cache_tags;
        int v64 = v63[v220];
        int * v65 = v16->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66 = v65[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v235 = ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) * 2;
      int v76 = v75[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) * 2) + 1;
      int v77 = v75[v236];
      int * v78 = v16->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v78[v238] = v76;
      int * v80 = v16->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v80[v241] = v77;
      int * v82 = v16->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1);
      v82[v220] = v244;
      int * v84 = v16->cache_dirty;
      v84[v220] = 0;
      int * v86 = v16->cache_age;
      v86[v220] = 1;
      int * v88 = v16->cache_age;
      int v89 = v88[v220];
      int v90 = v88[v194];
      int v249 = v90 + ((int)((unsigned int)(v90 - v89) >> 31));
      v88[v194] = v249;
      int * v92 = v16->cache_age;
      int v93 = v92[v195];
      int v251 = v93 + ((int)((unsigned int)(v93 - v89) >> 31));
      v92[v195] = v251;
      int * v95 = v16->cache_age;
      v95[v220] = 0;
      v98 = v220;
    }
    int * v99 = v16->cache_vals;
    int v254 = v98 * 2;
    int v100 = v99[v254];
    int v255 = (v98 * 2) + 1;
    int v101 = v99[v255];
    int v256 = (((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v99[v256] = v100;
    int * v103 = v16->cache_vals;
    int v259 = ((((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v103[v259] = v101;
    int * v105 = v16->cache_tags;
    int v262 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v263 = (int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1);
    v105[v262] = v263;
    int * v107 = v16->cache_dirty;
    v107[v262] = 0;
    int * v109 = v16->cache_age;
    v109[v262] = 1;
    int * v111 = v16->cache_age;
    int v112 = v111[v262];
    int v113 = v111[v192];
    int v268 = v113 + ((int)((unsigned int)(v113 - v112) >> 31));
    v111[v192] = v268;
    int * v115 = v16->cache_age;
    int v116 = v115[v193];
    int v270 = v116 + ((int)((unsigned int)(v116 - v112) >> 31));
    v115[v193] = v270;
    int * v118 = v16->cache_age;
    v118[v262] = 0;
    v121 = v262;
  }
  int * v122 = v16->cache_vals;
  int v273 = (v121 * 2) + (((int)((unsigned int)(v20 + 92) >> 2)) & 1);
  v122[v273] = v21;
  int * v124 = v16->cache_tags;
  int v125 = v124[v194];
  int v126 = v124[v195];
  bool v276 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) | (~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31))) == 0);
  int v180;
  if (v276) {
    int * v127 = v16->cache_age;
    int v278 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1))))) >> 31)) & 1);
    int v128 = v127[v278];
    int v129 = v127[v194];
    int v279 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
    v127[v194] = v279;
    int * v131 = v16->cache_age;
    int v132 = v131[v195];
    int v281 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
    v131[v195] = v281;
    int * v134 = v16->cache_age;
    v134[v278] = 0;
    v180 = v278;
  } else {
    int * v137 = v16->cache_age;
    int v285 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2);
    int v138 = v137[v285];
    int * v139 = v16->cache_tags;
    int v140 = v139[v285];
    int v141 = v137[v195];
    int v142 = v139[v195];
    int * v143 = v16->cache_dirty;
    int v288 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v144 = v143[v288];
    bool v289 = !(v144 == 0);
    if (v289) {
      int * v145 = v16->cache_tags;
      int v146 = v145[v288];
      int * v147 = v16->cache_vals;
      int v292 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v148 = v147[v292];
      int v293 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v149 = v147[v293];
      int * v150 = v16->mem;
      int v295 = v146 * 2;
      v150[v295] = v148;
      int * v152 = v16->mem;
      int v298 = (v146 * 2) + 1;
      v152[v298] = v149;
      ;
    } else {
      ;
    }
    int * v157 = v16->mem;
    int v303 = ((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) * 2;
    int v158 = v157[v303];
    int v304 = (((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) * 2) + 1;
    int v159 = v157[v304];
    int * v160 = v16->cache_vals;
    int v306 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v306] = v158;
    int * v162 = v16->cache_vals;
    int v309 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v162[v309] = v159;
    int * v164 = v16->cache_tags;
    int v312 = (int)((unsigned int)((int)((unsigned int)(v20 + 92) >> 2)) >> 1);
    v164[v288] = v312;
    int * v166 = v16->cache_dirty;
    v166[v288] = 0;
    int * v168 = v16->cache_age;
    v168[v288] = 1;
    int * v170 = v16->cache_age;
    int v171 = v170[v288];
    int v172 = v170[v194];
    int v317 = v172 + ((int)((unsigned int)(v172 - v171) >> 31));
    v170[v194] = v317;
    int * v174 = v16->cache_age;
    int v175 = v174[v195];
    int v319 = v175 + ((int)((unsigned int)(v175 - v171) >> 31));
    v174[v195] = v319;
    int * v177 = v16->cache_age;
    v177[v288] = 0;
    v180 = v288;
  }
  int * v181 = v16->cache_vals;
  int v322 = (v180 * 2) + (((int)((unsigned int)(v20 + 92) >> 2)) & 1);
  v181[v322] = v21;
  int * v183 = v16->cache_dirty;
  v183[v180] = 1;
  struct StateT * v185 = slot_2(v16);
  return v185;
}

struct StateT * slot_187(struct StateT * v21654) {
  int v21655 = v21654->timer;
  int v21663 = v21655 + 1;
  v21654->timer = v21663;
  int * v21657 = v21654->regs;
  int v21658 = v21657[14];
  int v21659 = v21657[11];
  int v21667 = v21658 ^ v21659;
  v21657[14] = v21667;
  struct StateT * v21661 = slot_188(v21654);
  return v21661;
}

struct StateT * slot_97(struct StateT * v16949) {
  int v16950 = v16949->timer;
  int v16958 = v16950 + 1;
  v16949->timer = v16958;
  int * v16952 = v16949->regs;
  int v16953 = v16952[15];
  int v16954 = v16952[20];
  int v16962 = v16953 | v16954;
  v16952[15] = v16962;
  struct StateT * v16956 = slot_98(v16949);
  return v16956;
}

struct StateT * slot_182(struct StateT * v21579) {
  int v21580 = v21579->timer;
  int v21587 = v21580 + 1;
  v21579->timer = v21587;
  int * v21582 = v21579->regs;
  int v21583 = v21582[6];
  int v21590 = v21583 << 13;
  v21582[6] = v21590;
  struct StateT * v21585 = slot_183(v21579);
  return v21585;
}

struct StateT * slot_38(struct StateT * v7322) {
  int v7323 = v7322->timer;
  int v7493 = v7323 + 1;
  v7322->timer = v7493;
  int * v7325 = v7322->regs;
  int v7326 = v7325[2];
  int v7327 = v7325[5];
  int * v7328 = v7322->cache_tags;
  int v7498 = (((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2;
  int v7329 = v7328[v7498];
  int v7499 = ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7330 = v7328[v7499];
  int v7500 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2);
  int v7331 = v7328[v7500];
  int v7501 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7332 = v7328[v7501];
  int v7333 = v7322->timer;
  int v7502 = v7333 + ((100 ^ (((~(((v7331 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7331 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7329 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7329 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v7330 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7330 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7331 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7331 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7322->timer = v7502;
  bool v7503 = !(((~(((v7329 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7329 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v7330 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7330 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v7427;
  if (v7503) {
    int * v7335 = v7322->cache_age;
    int v7505 = ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v7330 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7330 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v7336 = v7335[v7505];
    int v7337 = v7335[v7498];
    int v7506 = v7337 + ((int)((unsigned int)(v7337 - v7336) >> 31));
    v7335[v7498] = v7506;
    int * v7339 = v7322->cache_age;
    int v7340 = v7339[v7499];
    int v7508 = v7340 + ((int)((unsigned int)(v7340 - v7336) >> 31));
    v7339[v7499] = v7508;
    int * v7342 = v7322->cache_age;
    v7342[v7505] = 0;
    v7427 = v7505;
  } else {
    int * v7345 = v7322->cache_age;
    int v7512 = (((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2;
    int v7346 = v7345[v7512];
    int * v7347 = v7322->cache_tags;
    int v7348 = v7347[v7512];
    int v7349 = v7345[v7499];
    int v7350 = v7347[v7499];
    bool v7514 = !(((~(((v7331 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7331 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v7404;
    if (v7514) {
      int * v7351 = v7322->cache_age;
      int v7516 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7332 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v7352 = v7351[v7516];
      int v7353 = v7351[v7500];
      int v7517 = v7353 + ((int)((unsigned int)(v7353 - v7352) >> 31));
      v7351[v7500] = v7517;
      int * v7355 = v7322->cache_age;
      int v7356 = v7355[v7501];
      int v7519 = v7356 + ((int)((unsigned int)(v7356 - v7352) >> 31));
      v7355[v7501] = v7519;
      int * v7358 = v7322->cache_age;
      v7358[v7516] = 0;
      v7404 = v7516;
    } else {
      int * v7361 = v7322->cache_age;
      int v7523 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2);
      int v7362 = v7361[v7523];
      int * v7363 = v7322->cache_tags;
      int v7364 = v7363[v7523];
      int v7365 = v7361[v7501];
      int v7366 = v7363[v7501];
      int * v7367 = v7322->cache_dirty;
      int v7526 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7362 + ((~(((v7364 ^ -1) | (-(v7364 ^ -1))) >> 31)) & 2)) - (v7365 + ((~(((v7366 ^ -1) | (-(v7366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7368 = v7367[v7526];
      bool v7527 = !(v7368 == 0);
      if (v7527) {
        int * v7369 = v7322->cache_tags;
        int v7370 = v7369[v7526];
        int * v7371 = v7322->cache_vals;
        int v7530 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7362 + ((~(((v7364 ^ -1) | (-(v7364 ^ -1))) >> 31)) & 2)) - (v7365 + ((~(((v7366 ^ -1) | (-(v7366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7372 = v7371[v7530];
        int v7531 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7362 + ((~(((v7364 ^ -1) | (-(v7364 ^ -1))) >> 31)) & 2)) - (v7365 + ((~(((v7366 ^ -1) | (-(v7366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7373 = v7371[v7531];
        int * v7374 = v7322->mem;
        int v7533 = v7370 * 2;
        v7374[v7533] = v7372;
        int * v7376 = v7322->mem;
        int v7536 = (v7370 * 2) + 1;
        v7376[v7536] = v7373;
        ;
      } else {
        ;
      }
      int * v7381 = v7322->mem;
      int v7541 = ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) * 2;
      int v7382 = v7381[v7541];
      int v7542 = (((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) * 2) + 1;
      int v7383 = v7381[v7542];
      int * v7384 = v7322->cache_vals;
      int v7544 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7362 + ((~(((v7364 ^ -1) | (-(v7364 ^ -1))) >> 31)) & 2)) - (v7365 + ((~(((v7366 ^ -1) | (-(v7366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7384[v7544] = v7382;
      int * v7386 = v7322->cache_vals;
      int v7547 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7362 + ((~(((v7364 ^ -1) | (-(v7364 ^ -1))) >> 31)) & 2)) - (v7365 + ((~(((v7366 ^ -1) | (-(v7366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7386[v7547] = v7383;
      int * v7388 = v7322->cache_tags;
      int v7550 = (int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1);
      v7388[v7526] = v7550;
      int * v7390 = v7322->cache_dirty;
      v7390[v7526] = 0;
      int * v7392 = v7322->cache_age;
      v7392[v7526] = 1;
      int * v7394 = v7322->cache_age;
      int v7395 = v7394[v7526];
      int v7396 = v7394[v7500];
      int v7556 = v7396 + ((int)((unsigned int)(v7396 - v7395) >> 31));
      v7394[v7500] = v7556;
      int * v7398 = v7322->cache_age;
      int v7399 = v7398[v7501];
      int v7558 = v7399 + ((int)((unsigned int)(v7399 - v7395) >> 31));
      v7398[v7501] = v7558;
      int * v7401 = v7322->cache_age;
      v7401[v7526] = 0;
      v7404 = v7526;
    }
    int * v7405 = v7322->cache_vals;
    int v7561 = v7404 * 2;
    int v7406 = v7405[v7561];
    int v7562 = (v7404 * 2) + 1;
    int v7407 = v7405[v7562];
    int v7563 = (((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v7346 + ((~(((v7348 ^ -1) | (-(v7348 ^ -1))) >> 31)) & 2)) - (v7349 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7405[v7563] = v7406;
    int * v7409 = v7322->cache_vals;
    int v7566 = ((((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v7346 + ((~(((v7348 ^ -1) | (-(v7348 ^ -1))) >> 31)) & 2)) - (v7349 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7409[v7566] = v7407;
    int * v7411 = v7322->cache_tags;
    int v7569 = ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v7346 + ((~(((v7348 ^ -1) | (-(v7348 ^ -1))) >> 31)) & 2)) - (v7349 + ((~(((v7350 ^ -1) | (-(v7350 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7570 = (int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1);
    v7411[v7569] = v7570;
    int * v7413 = v7322->cache_dirty;
    v7413[v7569] = 0;
    int * v7415 = v7322->cache_age;
    v7415[v7569] = 1;
    int * v7417 = v7322->cache_age;
    int v7418 = v7417[v7569];
    int v7419 = v7417[v7498];
    int v7576 = v7419 + ((int)((unsigned int)(v7419 - v7418) >> 31));
    v7417[v7498] = v7576;
    int * v7421 = v7322->cache_age;
    int v7422 = v7421[v7499];
    int v7578 = v7422 + ((int)((unsigned int)(v7422 - v7418) >> 31));
    v7421[v7499] = v7578;
    int * v7424 = v7322->cache_age;
    v7424[v7569] = 0;
    v7427 = v7569;
  }
  int * v7428 = v7322->cache_vals;
  int v7581 = (v7427 * 2) + (((int)((unsigned int)(v7326 + 12) >> 2)) & 1);
  v7428[v7581] = v7327;
  int * v7430 = v7322->cache_tags;
  int v7431 = v7430[v7500];
  int v7432 = v7430[v7501];
  bool v7584 = !(((~(((v7431 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7431 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v7432 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7432 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v7486;
  if (v7584) {
    int * v7433 = v7322->cache_age;
    int v7586 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7432 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))) | (-(v7432 ^ ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v7434 = v7433[v7586];
    int v7435 = v7433[v7500];
    int v7587 = v7435 + ((int)((unsigned int)(v7435 - v7434) >> 31));
    v7433[v7500] = v7587;
    int * v7437 = v7322->cache_age;
    int v7438 = v7437[v7501];
    int v7589 = v7438 + ((int)((unsigned int)(v7438 - v7434) >> 31));
    v7437[v7501] = v7589;
    int * v7440 = v7322->cache_age;
    v7440[v7586] = 0;
    v7486 = v7586;
  } else {
    int * v7443 = v7322->cache_age;
    int v7593 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2);
    int v7444 = v7443[v7593];
    int * v7445 = v7322->cache_tags;
    int v7446 = v7445[v7593];
    int v7447 = v7443[v7501];
    int v7448 = v7445[v7501];
    int * v7449 = v7322->cache_dirty;
    int v7596 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7450 = v7449[v7596];
    bool v7597 = !(v7450 == 0);
    if (v7597) {
      int * v7451 = v7322->cache_tags;
      int v7452 = v7451[v7596];
      int * v7453 = v7322->cache_vals;
      int v7600 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7454 = v7453[v7600];
      int v7601 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7455 = v7453[v7601];
      int * v7456 = v7322->mem;
      int v7603 = v7452 * 2;
      v7456[v7603] = v7454;
      int * v7458 = v7322->mem;
      int v7606 = (v7452 * 2) + 1;
      v7458[v7606] = v7455;
      ;
    } else {
      ;
    }
    int * v7463 = v7322->mem;
    int v7611 = ((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) * 2;
    int v7464 = v7463[v7611];
    int v7612 = (((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) * 2) + 1;
    int v7465 = v7463[v7612];
    int * v7466 = v7322->cache_vals;
    int v7614 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7466[v7614] = v7464;
    int * v7468 = v7322->cache_vals;
    int v7617 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v7444 + ((~(((v7446 ^ -1) | (-(v7446 ^ -1))) >> 31)) & 2)) - (v7447 + ((~(((v7448 ^ -1) | (-(v7448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7468[v7617] = v7465;
    int * v7470 = v7322->cache_tags;
    int v7620 = (int)((unsigned int)((int)((unsigned int)(v7326 + 12) >> 2)) >> 1);
    v7470[v7596] = v7620;
    int * v7472 = v7322->cache_dirty;
    v7472[v7596] = 0;
    int * v7474 = v7322->cache_age;
    v7474[v7596] = 1;
    int * v7476 = v7322->cache_age;
    int v7477 = v7476[v7596];
    int v7478 = v7476[v7500];
    int v7626 = v7478 + ((int)((unsigned int)(v7478 - v7477) >> 31));
    v7476[v7500] = v7626;
    int * v7480 = v7322->cache_age;
    int v7481 = v7480[v7501];
    int v7628 = v7481 + ((int)((unsigned int)(v7481 - v7477) >> 31));
    v7480[v7501] = v7628;
    int * v7483 = v7322->cache_age;
    v7483[v7596] = 0;
    v7486 = v7596;
  }
  int * v7487 = v7322->cache_vals;
  int v7631 = (v7486 * 2) + (((int)((unsigned int)(v7326 + 12) >> 2)) & 1);
  v7487[v7631] = v7327;
  int * v7489 = v7322->cache_dirty;
  v7489[v7486] = 1;
  struct StateT * v7491 = slot_39(v7322);
  return v7491;
}

struct StateT * slot_178(struct StateT * v21519) {
  int v21520 = v21519->timer;
  int v21527 = v21520 + 1;
  v21519->timer = v21527;
  int * v21522 = v21519->regs;
  int v21523 = v21522[15];
  int v21531 = (int)((unsigned int)v21523 >> 19);
  v21522[9] = v21531;
  struct StateT * v21525 = slot_179(v21519);
  return v21525;
}

struct StateT * slot_106(struct StateT * v19138) {
  int v19139 = v19138->timer;
  int v19147 = v19139 + 1;
  v19138->timer = v19147;
  int * v19141 = v19138->regs;
  int v19142 = v19141[18];
  int v19143 = v19141[9];
  int v19152 = v19142 | v19143;
  v19141[6] = v19152;
  struct StateT * v19145 = slot_107(v19138);
  return v19145;
}

struct StateT * slot_98(struct StateT * v17276) {
  int v17277 = v17276->timer;
  int v17284 = v17277 + 1;
  v17276->timer = v17284;
  int * v17279 = v17276->regs;
  int v17280 = v17279[8];
  int v17288 = (int)((unsigned int)v17280 >> 19);
  v17279[20] = v17288;
  struct StateT * v17282 = slot_99(v17276);
  return v17282;
}

struct StateT * slot_159(struct StateT * v21222) {
  int v21223 = v21222->timer;
  int v21230 = v21223 + 1;
  v21222->timer = v21230;
  int * v21225 = v21222->regs;
  int v21226 = v21225[15];
  int v21233 = v21226 << 9;
  v21225[15] = v21233;
  struct StateT * v21228 = slot_160(v21222);
  return v21228;
}

struct StateT * slot_46(struct StateT * v9238) {
  int v9239 = v9238->timer;
  int v9246 = v9239 + 1;
  v9238->timer = v9246;
  int * v9241 = v9238->regs;
  int v9242 = v9241[28];
  v9241[27] = v9242;
  struct StateT * v9244 = slot_47(v9238);
  return v9244;
}

struct StateT * slot_212(struct StateT * v22045) {
  int v22046 = v22045->timer;
  int v22057 = v22046 + 1;
  v22045->timer = v22057;
  int * v22048 = v22045->regs;
  int v22049 = v22048[31];
  int v22050 = v22048[30];
  bool v22061 = (v22049 ^ -2147483648) >= (v22050 ^ -2147483648);
  struct StateT * v22055;
  if (v22061) {
    struct StateT * v22051 = slot_51(v22045);
    v22055 = v22051;
  } else {
    struct StateT * v22053 = slot_213(v22045);
    v22055 = v22053;
  }
  return v22055;
}

struct StateT * slot_132(struct StateT * v20795) {
  int v20796 = v20795->timer;
  int v20804 = v20796 + 1;
  v20795->timer = v20804;
  int * v20798 = v20795->regs;
  int v20799 = v20798[20];
  int v20800 = v20798[12];
  int v20809 = v20799 + v20800;
  v20798[11] = v20809;
  struct StateT * v20802 = slot_133(v20795);
  return v20802;
}

struct StateT * slot_130(struct StateT * v20762) {
  int v20763 = v20762->timer;
  int v20771 = v20763 + 1;
  v20762->timer = v20771;
  int * v20765 = v20762->regs;
  int v20766 = v20765[22];
  int v20767 = v20765[5];
  int v20775 = v20766 ^ v20767;
  v20765[22] = v20775;
  struct StateT * v20769 = slot_131(v20762);
  return v20769;
}

struct StateT * slot_211(struct StateT * v22031) {
  int v22032 = v22031->timer;
  int v22039 = v22032 + 1;
  v22031->timer = v22039;
  int * v22034 = v22031->regs;
  int v22035 = v22034[30];
  int v22042 = v22035 + 1;
  v22034[30] = v22042;
  struct StateT * v22037 = slot_212(v22031);
  return v22037;
}

struct StateT * slot_20(struct StateT * v5140) {
  int v5141 = v5140->timer;
  int v5251 = v5141 + 1;
  v5140->timer = v5251;
  int * v5143 = v5140->regs;
  int v5144 = v5143[12];
  int * v5145 = v5140->cache_tags;
  int v5255 = (((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2;
  int v5146 = v5145[v5255];
  int v5256 = ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5147 = v5145[v5256];
  int v5257 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2);
  int v5148 = v5145[v5257];
  int v5258 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5149 = v5145[v5258];
  int v5150 = v5140->timer;
  int v5259 = v5150 + ((100 ^ (((~(((v5148 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5148 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5146 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5146 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5147 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5147 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5148 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5148 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5140->timer = v5259;
  int * v5152 = v5140->cache_vals;
  bool v5260 = !(((~(((v5146 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5146 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5147 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5147 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5245;
  if (v5260) {
    int * v5153 = v5140->cache_age;
    int v5262 = ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v5147 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5147 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5154 = v5153[v5262];
    int v5155 = v5153[v5255];
    int v5263 = v5155 + ((int)((unsigned int)(v5155 - v5154) >> 31));
    v5153[v5255] = v5263;
    int * v5157 = v5140->cache_age;
    int v5158 = v5157[v5256];
    int v5265 = v5158 + ((int)((unsigned int)(v5158 - v5154) >> 31));
    v5157[v5256] = v5265;
    int * v5160 = v5140->cache_age;
    v5160[v5262] = 0;
    v5245 = v5262;
  } else {
    int * v5163 = v5140->cache_age;
    int v5269 = (((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2;
    int v5164 = v5163[v5269];
    int * v5165 = v5140->cache_tags;
    int v5166 = v5165[v5269];
    int v5167 = v5163[v5256];
    int v5168 = v5165[v5256];
    bool v5271 = !(((~(((v5148 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5148 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v5222;
    if (v5271) {
      int * v5169 = v5140->cache_age;
      int v5273 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))) | (-(v5149 ^ ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v5170 = v5169[v5273];
      int v5171 = v5169[v5257];
      int v5274 = v5171 + ((int)((unsigned int)(v5171 - v5170) >> 31));
      v5169[v5257] = v5274;
      int * v5173 = v5140->cache_age;
      int v5174 = v5173[v5258];
      int v5276 = v5174 + ((int)((unsigned int)(v5174 - v5170) >> 31));
      v5173[v5258] = v5276;
      int * v5176 = v5140->cache_age;
      v5176[v5273] = 0;
      v5222 = v5273;
    } else {
      int * v5179 = v5140->cache_age;
      int v5280 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2);
      int v5180 = v5179[v5280];
      int * v5181 = v5140->cache_tags;
      int v5182 = v5181[v5280];
      int v5183 = v5179[v5258];
      int v5184 = v5181[v5258];
      int * v5185 = v5140->cache_dirty;
      int v5283 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5180 + ((~(((v5182 ^ -1) | (-(v5182 ^ -1))) >> 31)) & 2)) - (v5183 + ((~(((v5184 ^ -1) | (-(v5184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5186 = v5185[v5283];
      bool v5284 = !(v5186 == 0);
      if (v5284) {
        int * v5187 = v5140->cache_tags;
        int v5188 = v5187[v5283];
        int * v5189 = v5140->cache_vals;
        int v5287 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5180 + ((~(((v5182 ^ -1) | (-(v5182 ^ -1))) >> 31)) & 2)) - (v5183 + ((~(((v5184 ^ -1) | (-(v5184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5190 = v5189[v5287];
        int v5288 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5180 + ((~(((v5182 ^ -1) | (-(v5182 ^ -1))) >> 31)) & 2)) - (v5183 + ((~(((v5184 ^ -1) | (-(v5184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5191 = v5189[v5288];
        int * v5192 = v5140->mem;
        int v5290 = v5188 * 2;
        v5192[v5290] = v5190;
        int * v5194 = v5140->mem;
        int v5293 = (v5188 * 2) + 1;
        v5194[v5293] = v5191;
        ;
      } else {
        ;
      }
      int * v5199 = v5140->mem;
      int v5298 = ((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) * 2;
      int v5200 = v5199[v5298];
      int v5299 = (((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) * 2) + 1;
      int v5201 = v5199[v5299];
      int * v5202 = v5140->cache_vals;
      int v5301 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5180 + ((~(((v5182 ^ -1) | (-(v5182 ^ -1))) >> 31)) & 2)) - (v5183 + ((~(((v5184 ^ -1) | (-(v5184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5202[v5301] = v5200;
      int * v5204 = v5140->cache_vals;
      int v5304 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5180 + ((~(((v5182 ^ -1) | (-(v5182 ^ -1))) >> 31)) & 2)) - (v5183 + ((~(((v5184 ^ -1) | (-(v5184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5204[v5304] = v5201;
      int * v5206 = v5140->cache_tags;
      int v5307 = (int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1);
      v5206[v5283] = v5307;
      int * v5208 = v5140->cache_dirty;
      v5208[v5283] = 0;
      int * v5210 = v5140->cache_age;
      v5210[v5283] = 1;
      int * v5212 = v5140->cache_age;
      int v5213 = v5212[v5283];
      int v5214 = v5212[v5257];
      int v5313 = v5214 + ((int)((unsigned int)(v5214 - v5213) >> 31));
      v5212[v5257] = v5313;
      int * v5216 = v5140->cache_age;
      int v5217 = v5216[v5258];
      int v5315 = v5217 + ((int)((unsigned int)(v5217 - v5213) >> 31));
      v5216[v5258] = v5315;
      int * v5219 = v5140->cache_age;
      v5219[v5283] = 0;
      v5222 = v5283;
    }
    int * v5223 = v5140->cache_vals;
    int v5318 = v5222 * 2;
    int v5224 = v5223[v5318];
    int v5319 = (v5222 * 2) + 1;
    int v5225 = v5223[v5319];
    int v5320 = (((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5164 + ((~(((v5166 ^ -1) | (-(v5166 ^ -1))) >> 31)) & 2)) - (v5167 + ((~(((v5168 ^ -1) | (-(v5168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5223[v5320] = v5224;
    int * v5227 = v5140->cache_vals;
    int v5323 = ((((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5164 + ((~(((v5166 ^ -1) | (-(v5166 ^ -1))) >> 31)) & 2)) - (v5167 + ((~(((v5168 ^ -1) | (-(v5168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5227[v5323] = v5225;
    int * v5229 = v5140->cache_tags;
    int v5326 = ((((int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5164 + ((~(((v5166 ^ -1) | (-(v5166 ^ -1))) >> 31)) & 2)) - (v5167 + ((~(((v5168 ^ -1) | (-(v5168 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5327 = (int)((unsigned int)((int)((unsigned int)(v5144 + 20) >> 2)) >> 1);
    v5229[v5326] = v5327;
    int * v5231 = v5140->cache_dirty;
    v5231[v5326] = 0;
    int * v5233 = v5140->cache_age;
    v5233[v5326] = 1;
    int * v5235 = v5140->cache_age;
    int v5236 = v5235[v5326];
    int v5237 = v5235[v5255];
    int v5333 = v5237 + ((int)((unsigned int)(v5237 - v5236) >> 31));
    v5235[v5255] = v5333;
    int * v5239 = v5140->cache_age;
    int v5240 = v5239[v5256];
    int v5335 = v5240 + ((int)((unsigned int)(v5240 - v5236) >> 31));
    v5239[v5256] = v5335;
    int * v5242 = v5140->cache_age;
    v5242[v5326] = 0;
    v5245 = v5326;
  }
  int v5338 = (v5245 * 2) + (((int)((unsigned int)(v5144 + 20) >> 2)) & 1);
  int v5246 = v5152[v5338];
  int * v5247 = v5140->regs;
  v5247[16] = v5246;
  struct StateT * v5249 = slot_21(v5140);
  return v5249;
}

struct StateT * slot_141(struct StateT * v20936) {
  int v20937 = v20936->timer;
  int v20944 = v20937 + 1;
  v20936->timer = v20944;
  int * v20939 = v20936->regs;
  int v20940 = v20939[16];
  int v20948 = (int)((unsigned int)v20940 >> 25);
  v20939[5] = v20948;
  struct StateT * v20942 = slot_142(v20936);
  return v20942;
}

struct StateT * slot_61(struct StateT * v10510) {
  int v10511 = v10510->timer;
  int v10518 = v10511 + 1;
  v10510->timer = v10518;
  int * v10513 = v10510->regs;
  int v10514 = v10513[18];
  int v10522 = (int)((unsigned int)v10514 >> 25);
  v10513[20] = v10522;
  struct StateT * v10516 = slot_62(v10510);
  return v10516;
}

struct StateT * slot_30(struct StateT * v6607) {
  int v6608 = v6607->timer;
  int v6615 = v6608 + 1;
  v6607->timer = v6615;
  int * v6610 = v6607->regs;
  int v6611 = v6610[12];
  int v6619 = v6611 + -1947;
  v6610[21] = v6619;
  struct StateT * v6613 = slot_31(v6607);
  return v6613;
}

struct StateT * slot_4(struct StateT * v957) {
  int v958 = v957->timer;
  int v1128 = v958 + 1;
  v957->timer = v1128;
  int * v960 = v957->regs;
  int v961 = v960[2];
  int v962 = v960[18];
  int * v963 = v957->cache_tags;
  int v1133 = (((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2;
  int v964 = v963[v1133];
  int v1134 = ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2) + 1;
  int v965 = v963[v1134];
  int v1135 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2);
  int v966 = v963[v1135];
  int v1136 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v967 = v963[v1136];
  int v968 = v957->timer;
  int v1137 = v968 + ((100 ^ (((~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v964 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v964 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31))) & 104)))));
  v957->timer = v1137;
  bool v1138 = !(((~(((v964 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v964 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31))) == 0);
  int v1062;
  if (v1138) {
    int * v970 = v957->cache_age;
    int v1140 = ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2) + ((~(((v965 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v965 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) & 1);
    int v971 = v970[v1140];
    int v972 = v970[v1133];
    int v1141 = v972 + ((int)((unsigned int)(v972 - v971) >> 31));
    v970[v1133] = v1141;
    int * v974 = v957->cache_age;
    int v975 = v974[v1134];
    int v1143 = v975 + ((int)((unsigned int)(v975 - v971) >> 31));
    v974[v1134] = v1143;
    int * v977 = v957->cache_age;
    v977[v1140] = 0;
    v1062 = v1140;
  } else {
    int * v980 = v957->cache_age;
    int v1147 = (((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2;
    int v981 = v980[v1147];
    int * v982 = v957->cache_tags;
    int v983 = v982[v1147];
    int v984 = v980[v1134];
    int v985 = v982[v1134];
    bool v1149 = !(((~(((v966 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v966 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31))) == 0);
    int v1039;
    if (v1149) {
      int * v986 = v957->cache_age;
      int v1151 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((~(((v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v967 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) & 1);
      int v987 = v986[v1151];
      int v988 = v986[v1135];
      int v1152 = v988 + ((int)((unsigned int)(v988 - v987) >> 31));
      v986[v1135] = v1152;
      int * v990 = v957->cache_age;
      int v991 = v990[v1136];
      int v1154 = v991 + ((int)((unsigned int)(v991 - v987) >> 31));
      v990[v1136] = v1154;
      int * v993 = v957->cache_age;
      v993[v1151] = 0;
      v1039 = v1151;
    } else {
      int * v996 = v957->cache_age;
      int v1158 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2);
      int v997 = v996[v1158];
      int * v998 = v957->cache_tags;
      int v999 = v998[v1158];
      int v1000 = v996[v1136];
      int v1001 = v998[v1136];
      int * v1002 = v957->cache_dirty;
      int v1161 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1003 = v1002[v1161];
      bool v1162 = !(v1003 == 0);
      if (v1162) {
        int * v1004 = v957->cache_tags;
        int v1005 = v1004[v1161];
        int * v1006 = v957->cache_vals;
        int v1165 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1007 = v1006[v1165];
        int v1166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1008 = v1006[v1166];
        int * v1009 = v957->mem;
        int v1168 = v1005 * 2;
        v1009[v1168] = v1007;
        int * v1011 = v957->mem;
        int v1171 = (v1005 * 2) + 1;
        v1011[v1171] = v1008;
        ;
      } else {
        ;
      }
      int * v1016 = v957->mem;
      int v1176 = ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) * 2;
      int v1017 = v1016[v1176];
      int v1177 = (((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) * 2) + 1;
      int v1018 = v1016[v1177];
      int * v1019 = v957->cache_vals;
      int v1179 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1019[v1179] = v1017;
      int * v1021 = v957->cache_vals;
      int v1182 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v997 + ((~(((v999 ^ -1) | (-(v999 ^ -1))) >> 31)) & 2)) - (v1000 + ((~(((v1001 ^ -1) | (-(v1001 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1021[v1182] = v1018;
      int * v1023 = v957->cache_tags;
      int v1185 = (int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1);
      v1023[v1161] = v1185;
      int * v1025 = v957->cache_dirty;
      v1025[v1161] = 0;
      int * v1027 = v957->cache_age;
      v1027[v1161] = 1;
      int * v1029 = v957->cache_age;
      int v1030 = v1029[v1161];
      int v1031 = v1029[v1135];
      int v1191 = v1031 + ((int)((unsigned int)(v1031 - v1030) >> 31));
      v1029[v1135] = v1191;
      int * v1033 = v957->cache_age;
      int v1034 = v1033[v1136];
      int v1193 = v1034 + ((int)((unsigned int)(v1034 - v1030) >> 31));
      v1033[v1136] = v1193;
      int * v1036 = v957->cache_age;
      v1036[v1161] = 0;
      v1039 = v1161;
    }
    int * v1040 = v957->cache_vals;
    int v1196 = v1039 * 2;
    int v1041 = v1040[v1196];
    int v1197 = (v1039 * 2) + 1;
    int v1042 = v1040[v1197];
    int v1198 = (((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2) + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1040[v1198] = v1041;
    int * v1044 = v957->cache_vals;
    int v1201 = ((((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2) + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1044[v1201] = v1042;
    int * v1046 = v957->cache_tags;
    int v1204 = ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 1) * 2) + ((((v981 + ((~(((v983 ^ -1) | (-(v983 ^ -1))) >> 31)) & 2)) - (v984 + ((~(((v985 ^ -1) | (-(v985 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1205 = (int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1);
    v1046[v1204] = v1205;
    int * v1048 = v957->cache_dirty;
    v1048[v1204] = 0;
    int * v1050 = v957->cache_age;
    v1050[v1204] = 1;
    int * v1052 = v957->cache_age;
    int v1053 = v1052[v1204];
    int v1054 = v1052[v1133];
    int v1211 = v1054 + ((int)((unsigned int)(v1054 - v1053) >> 31));
    v1052[v1133] = v1211;
    int * v1056 = v957->cache_age;
    int v1057 = v1056[v1134];
    int v1213 = v1057 + ((int)((unsigned int)(v1057 - v1053) >> 31));
    v1056[v1134] = v1213;
    int * v1059 = v957->cache_age;
    v1059[v1204] = 0;
    v1062 = v1204;
  }
  int * v1063 = v957->cache_vals;
  int v1216 = (v1062 * 2) + (((int)((unsigned int)(v961 + 80) >> 2)) & 1);
  v1063[v1216] = v962;
  int * v1065 = v957->cache_tags;
  int v1066 = v1065[v1135];
  int v1067 = v1065[v1136];
  bool v1219 = !(((~(((v1066 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v1066 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v1067 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v1067 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31))) == 0);
  int v1121;
  if (v1219) {
    int * v1068 = v957->cache_age;
    int v1221 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1067 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))) | (-(v1067 ^ ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1))))) >> 31)) & 1);
    int v1069 = v1068[v1221];
    int v1070 = v1068[v1135];
    int v1222 = v1070 + ((int)((unsigned int)(v1070 - v1069) >> 31));
    v1068[v1135] = v1222;
    int * v1072 = v957->cache_age;
    int v1073 = v1072[v1136];
    int v1224 = v1073 + ((int)((unsigned int)(v1073 - v1069) >> 31));
    v1072[v1136] = v1224;
    int * v1075 = v957->cache_age;
    v1075[v1221] = 0;
    v1121 = v1221;
  } else {
    int * v1078 = v957->cache_age;
    int v1228 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2);
    int v1079 = v1078[v1228];
    int * v1080 = v957->cache_tags;
    int v1081 = v1080[v1228];
    int v1082 = v1078[v1136];
    int v1083 = v1080[v1136];
    int * v1084 = v957->cache_dirty;
    int v1231 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1085 = v1084[v1231];
    bool v1232 = !(v1085 == 0);
    if (v1232) {
      int * v1086 = v957->cache_tags;
      int v1087 = v1086[v1231];
      int * v1088 = v957->cache_vals;
      int v1235 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1089 = v1088[v1235];
      int v1236 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1090 = v1088[v1236];
      int * v1091 = v957->mem;
      int v1238 = v1087 * 2;
      v1091[v1238] = v1089;
      int * v1093 = v957->mem;
      int v1241 = (v1087 * 2) + 1;
      v1093[v1241] = v1090;
      ;
    } else {
      ;
    }
    int * v1098 = v957->mem;
    int v1246 = ((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) * 2;
    int v1099 = v1098[v1246];
    int v1247 = (((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) * 2) + 1;
    int v1100 = v1098[v1247];
    int * v1101 = v957->cache_vals;
    int v1249 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1101[v1249] = v1099;
    int * v1103 = v957->cache_vals;
    int v1252 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1103[v1252] = v1100;
    int * v1105 = v957->cache_tags;
    int v1255 = (int)((unsigned int)((int)((unsigned int)(v961 + 80) >> 2)) >> 1);
    v1105[v1231] = v1255;
    int * v1107 = v957->cache_dirty;
    v1107[v1231] = 0;
    int * v1109 = v957->cache_age;
    v1109[v1231] = 1;
    int * v1111 = v957->cache_age;
    int v1112 = v1111[v1231];
    int v1113 = v1111[v1135];
    int v1261 = v1113 + ((int)((unsigned int)(v1113 - v1112) >> 31));
    v1111[v1135] = v1261;
    int * v1115 = v957->cache_age;
    int v1116 = v1115[v1136];
    int v1263 = v1116 + ((int)((unsigned int)(v1116 - v1112) >> 31));
    v1115[v1136] = v1263;
    int * v1118 = v957->cache_age;
    v1118[v1231] = 0;
    v1121 = v1231;
  }
  int * v1122 = v957->cache_vals;
  int v1266 = (v1121 * 2) + (((int)((unsigned int)(v961 + 80) >> 2)) & 1);
  v1122[v1266] = v962;
  int * v1124 = v957->cache_dirty;
  v1124[v1121] = 1;
  struct StateT * v1126 = slot_5(v957);
  return v1126;
}

struct StateT * slot_18(struct StateT * v4732) {
  int v4733 = v4732->timer;
  int v4843 = v4733 + 1;
  v4732->timer = v4843;
  int * v4735 = v4732->regs;
  int v4736 = v4735[12];
  int * v4737 = v4732->cache_tags;
  int v4847 = (((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2;
  int v4738 = v4737[v4847];
  int v4848 = ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4739 = v4737[v4848];
  int v4849 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2);
  int v4740 = v4737[v4849];
  int v4850 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4741 = v4737[v4850];
  int v4742 = v4732->timer;
  int v4851 = v4742 + ((100 ^ (((~(((v4740 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4740 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4738 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4738 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4739 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4739 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4740 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4740 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4732->timer = v4851;
  int * v4744 = v4732->cache_vals;
  bool v4852 = !(((~(((v4738 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4738 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4739 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4739 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4837;
  if (v4852) {
    int * v4745 = v4732->cache_age;
    int v4854 = ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v4739 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4739 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4746 = v4745[v4854];
    int v4747 = v4745[v4847];
    int v4855 = v4747 + ((int)((unsigned int)(v4747 - v4746) >> 31));
    v4745[v4847] = v4855;
    int * v4749 = v4732->cache_age;
    int v4750 = v4749[v4848];
    int v4857 = v4750 + ((int)((unsigned int)(v4750 - v4746) >> 31));
    v4749[v4848] = v4857;
    int * v4752 = v4732->cache_age;
    v4752[v4854] = 0;
    v4837 = v4854;
  } else {
    int * v4755 = v4732->cache_age;
    int v4861 = (((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2;
    int v4756 = v4755[v4861];
    int * v4757 = v4732->cache_tags;
    int v4758 = v4757[v4861];
    int v4759 = v4755[v4848];
    int v4760 = v4757[v4848];
    bool v4863 = !(((~(((v4740 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4740 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v4814;
    if (v4863) {
      int * v4761 = v4732->cache_age;
      int v4865 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))) | (-(v4741 ^ ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v4762 = v4761[v4865];
      int v4763 = v4761[v4849];
      int v4866 = v4763 + ((int)((unsigned int)(v4763 - v4762) >> 31));
      v4761[v4849] = v4866;
      int * v4765 = v4732->cache_age;
      int v4766 = v4765[v4850];
      int v4868 = v4766 + ((int)((unsigned int)(v4766 - v4762) >> 31));
      v4765[v4850] = v4868;
      int * v4768 = v4732->cache_age;
      v4768[v4865] = 0;
      v4814 = v4865;
    } else {
      int * v4771 = v4732->cache_age;
      int v4872 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2);
      int v4772 = v4771[v4872];
      int * v4773 = v4732->cache_tags;
      int v4774 = v4773[v4872];
      int v4775 = v4771[v4850];
      int v4776 = v4773[v4850];
      int * v4777 = v4732->cache_dirty;
      int v4875 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4772 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2)) - (v4775 + ((~(((v4776 ^ -1) | (-(v4776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4778 = v4777[v4875];
      bool v4876 = !(v4778 == 0);
      if (v4876) {
        int * v4779 = v4732->cache_tags;
        int v4780 = v4779[v4875];
        int * v4781 = v4732->cache_vals;
        int v4879 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4772 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2)) - (v4775 + ((~(((v4776 ^ -1) | (-(v4776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4782 = v4781[v4879];
        int v4880 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4772 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2)) - (v4775 + ((~(((v4776 ^ -1) | (-(v4776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4783 = v4781[v4880];
        int * v4784 = v4732->mem;
        int v4882 = v4780 * 2;
        v4784[v4882] = v4782;
        int * v4786 = v4732->mem;
        int v4885 = (v4780 * 2) + 1;
        v4786[v4885] = v4783;
        ;
      } else {
        ;
      }
      int * v4791 = v4732->mem;
      int v4890 = ((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) * 2;
      int v4792 = v4791[v4890];
      int v4891 = (((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) * 2) + 1;
      int v4793 = v4791[v4891];
      int * v4794 = v4732->cache_vals;
      int v4893 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4772 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2)) - (v4775 + ((~(((v4776 ^ -1) | (-(v4776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4794[v4893] = v4792;
      int * v4796 = v4732->cache_vals;
      int v4896 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4772 + ((~(((v4774 ^ -1) | (-(v4774 ^ -1))) >> 31)) & 2)) - (v4775 + ((~(((v4776 ^ -1) | (-(v4776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4796[v4896] = v4793;
      int * v4798 = v4732->cache_tags;
      int v4899 = (int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1);
      v4798[v4875] = v4899;
      int * v4800 = v4732->cache_dirty;
      v4800[v4875] = 0;
      int * v4802 = v4732->cache_age;
      v4802[v4875] = 1;
      int * v4804 = v4732->cache_age;
      int v4805 = v4804[v4875];
      int v4806 = v4804[v4849];
      int v4905 = v4806 + ((int)((unsigned int)(v4806 - v4805) >> 31));
      v4804[v4849] = v4905;
      int * v4808 = v4732->cache_age;
      int v4809 = v4808[v4850];
      int v4907 = v4809 + ((int)((unsigned int)(v4809 - v4805) >> 31));
      v4808[v4850] = v4907;
      int * v4811 = v4732->cache_age;
      v4811[v4875] = 0;
      v4814 = v4875;
    }
    int * v4815 = v4732->cache_vals;
    int v4910 = v4814 * 2;
    int v4816 = v4815[v4910];
    int v4911 = (v4814 * 2) + 1;
    int v4817 = v4815[v4911];
    int v4912 = (((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4756 + ((~(((v4758 ^ -1) | (-(v4758 ^ -1))) >> 31)) & 2)) - (v4759 + ((~(((v4760 ^ -1) | (-(v4760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4815[v4912] = v4816;
    int * v4819 = v4732->cache_vals;
    int v4915 = ((((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4756 + ((~(((v4758 ^ -1) | (-(v4758 ^ -1))) >> 31)) & 2)) - (v4759 + ((~(((v4760 ^ -1) | (-(v4760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4819[v4915] = v4817;
    int * v4821 = v4732->cache_tags;
    int v4918 = ((((int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4756 + ((~(((v4758 ^ -1) | (-(v4758 ^ -1))) >> 31)) & 2)) - (v4759 + ((~(((v4760 ^ -1) | (-(v4760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4919 = (int)((unsigned int)((int)((unsigned int)(v4736 + 12) >> 2)) >> 1);
    v4821[v4918] = v4919;
    int * v4823 = v4732->cache_dirty;
    v4823[v4918] = 0;
    int * v4825 = v4732->cache_age;
    v4825[v4918] = 1;
    int * v4827 = v4732->cache_age;
    int v4828 = v4827[v4918];
    int v4829 = v4827[v4847];
    int v4925 = v4829 + ((int)((unsigned int)(v4829 - v4828) >> 31));
    v4827[v4847] = v4925;
    int * v4831 = v4732->cache_age;
    int v4832 = v4831[v4848];
    int v4927 = v4832 + ((int)((unsigned int)(v4832 - v4828) >> 31));
    v4831[v4848] = v4927;
    int * v4834 = v4732->cache_age;
    v4834[v4918] = 0;
    v4837 = v4918;
  }
  int v4930 = (v4837 * 2) + (((int)((unsigned int)(v4736 + 12) >> 2)) & 1);
  int v4838 = v4744[v4930];
  int * v4839 = v4732->regs;
  v4839[6] = v4838;
  struct StateT * v4841 = slot_19(v4732);
  return v4841;
}

struct StateT * slot_9(struct StateT * v2532) {
  int v2533 = v2532->timer;
  int v2703 = v2533 + 1;
  v2532->timer = v2703;
  int * v2535 = v2532->regs;
  int v2536 = v2535[2];
  int v2537 = v2535[23];
  int * v2538 = v2532->cache_tags;
  int v2708 = (((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2;
  int v2539 = v2538[v2708];
  int v2709 = ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2540 = v2538[v2709];
  int v2710 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2);
  int v2541 = v2538[v2710];
  int v2711 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2542 = v2538[v2711];
  int v2543 = v2532->timer;
  int v2712 = v2543 + ((100 ^ (((~(((v2541 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2541 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2539 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2539 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v2540 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2540 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2541 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2541 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2532->timer = v2712;
  bool v2713 = !(((~(((v2539 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2539 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v2540 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2540 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31))) == 0);
  int v2637;
  if (v2713) {
    int * v2545 = v2532->cache_age;
    int v2715 = ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2) + ((~(((v2540 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2540 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) & 1);
    int v2546 = v2545[v2715];
    int v2547 = v2545[v2708];
    int v2716 = v2547 + ((int)((unsigned int)(v2547 - v2546) >> 31));
    v2545[v2708] = v2716;
    int * v2549 = v2532->cache_age;
    int v2550 = v2549[v2709];
    int v2718 = v2550 + ((int)((unsigned int)(v2550 - v2546) >> 31));
    v2549[v2709] = v2718;
    int * v2552 = v2532->cache_age;
    v2552[v2715] = 0;
    v2637 = v2715;
  } else {
    int * v2555 = v2532->cache_age;
    int v2722 = (((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2;
    int v2556 = v2555[v2722];
    int * v2557 = v2532->cache_tags;
    int v2558 = v2557[v2722];
    int v2559 = v2555[v2709];
    int v2560 = v2557[v2709];
    bool v2724 = !(((~(((v2541 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2541 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31))) == 0);
    int v2614;
    if (v2724) {
      int * v2561 = v2532->cache_age;
      int v2726 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2542 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) & 1);
      int v2562 = v2561[v2726];
      int v2563 = v2561[v2710];
      int v2727 = v2563 + ((int)((unsigned int)(v2563 - v2562) >> 31));
      v2561[v2710] = v2727;
      int * v2565 = v2532->cache_age;
      int v2566 = v2565[v2711];
      int v2729 = v2566 + ((int)((unsigned int)(v2566 - v2562) >> 31));
      v2565[v2711] = v2729;
      int * v2568 = v2532->cache_age;
      v2568[v2726] = 0;
      v2614 = v2726;
    } else {
      int * v2571 = v2532->cache_age;
      int v2733 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2);
      int v2572 = v2571[v2733];
      int * v2573 = v2532->cache_tags;
      int v2574 = v2573[v2733];
      int v2575 = v2571[v2711];
      int v2576 = v2573[v2711];
      int * v2577 = v2532->cache_dirty;
      int v2736 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2572 + ((~(((v2574 ^ -1) | (-(v2574 ^ -1))) >> 31)) & 2)) - (v2575 + ((~(((v2576 ^ -1) | (-(v2576 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2578 = v2577[v2736];
      bool v2737 = !(v2578 == 0);
      if (v2737) {
        int * v2579 = v2532->cache_tags;
        int v2580 = v2579[v2736];
        int * v2581 = v2532->cache_vals;
        int v2740 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2572 + ((~(((v2574 ^ -1) | (-(v2574 ^ -1))) >> 31)) & 2)) - (v2575 + ((~(((v2576 ^ -1) | (-(v2576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2582 = v2581[v2740];
        int v2741 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2572 + ((~(((v2574 ^ -1) | (-(v2574 ^ -1))) >> 31)) & 2)) - (v2575 + ((~(((v2576 ^ -1) | (-(v2576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2583 = v2581[v2741];
        int * v2584 = v2532->mem;
        int v2743 = v2580 * 2;
        v2584[v2743] = v2582;
        int * v2586 = v2532->mem;
        int v2746 = (v2580 * 2) + 1;
        v2586[v2746] = v2583;
        ;
      } else {
        ;
      }
      int * v2591 = v2532->mem;
      int v2751 = ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) * 2;
      int v2592 = v2591[v2751];
      int v2752 = (((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) * 2) + 1;
      int v2593 = v2591[v2752];
      int * v2594 = v2532->cache_vals;
      int v2754 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2572 + ((~(((v2574 ^ -1) | (-(v2574 ^ -1))) >> 31)) & 2)) - (v2575 + ((~(((v2576 ^ -1) | (-(v2576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2594[v2754] = v2592;
      int * v2596 = v2532->cache_vals;
      int v2757 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2572 + ((~(((v2574 ^ -1) | (-(v2574 ^ -1))) >> 31)) & 2)) - (v2575 + ((~(((v2576 ^ -1) | (-(v2576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2596[v2757] = v2593;
      int * v2598 = v2532->cache_tags;
      int v2760 = (int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1);
      v2598[v2736] = v2760;
      int * v2600 = v2532->cache_dirty;
      v2600[v2736] = 0;
      int * v2602 = v2532->cache_age;
      v2602[v2736] = 1;
      int * v2604 = v2532->cache_age;
      int v2605 = v2604[v2736];
      int v2606 = v2604[v2710];
      int v2766 = v2606 + ((int)((unsigned int)(v2606 - v2605) >> 31));
      v2604[v2710] = v2766;
      int * v2608 = v2532->cache_age;
      int v2609 = v2608[v2711];
      int v2768 = v2609 + ((int)((unsigned int)(v2609 - v2605) >> 31));
      v2608[v2711] = v2768;
      int * v2611 = v2532->cache_age;
      v2611[v2736] = 0;
      v2614 = v2736;
    }
    int * v2615 = v2532->cache_vals;
    int v2771 = v2614 * 2;
    int v2616 = v2615[v2771];
    int v2772 = (v2614 * 2) + 1;
    int v2617 = v2615[v2772];
    int v2773 = (((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v2556 + ((~(((v2558 ^ -1) | (-(v2558 ^ -1))) >> 31)) & 2)) - (v2559 + ((~(((v2560 ^ -1) | (-(v2560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2615[v2773] = v2616;
    int * v2619 = v2532->cache_vals;
    int v2776 = ((((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v2556 + ((~(((v2558 ^ -1) | (-(v2558 ^ -1))) >> 31)) & 2)) - (v2559 + ((~(((v2560 ^ -1) | (-(v2560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2619[v2776] = v2617;
    int * v2621 = v2532->cache_tags;
    int v2779 = ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v2556 + ((~(((v2558 ^ -1) | (-(v2558 ^ -1))) >> 31)) & 2)) - (v2559 + ((~(((v2560 ^ -1) | (-(v2560 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2780 = (int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1);
    v2621[v2779] = v2780;
    int * v2623 = v2532->cache_dirty;
    v2623[v2779] = 0;
    int * v2625 = v2532->cache_age;
    v2625[v2779] = 1;
    int * v2627 = v2532->cache_age;
    int v2628 = v2627[v2779];
    int v2629 = v2627[v2708];
    int v2786 = v2629 + ((int)((unsigned int)(v2629 - v2628) >> 31));
    v2627[v2708] = v2786;
    int * v2631 = v2532->cache_age;
    int v2632 = v2631[v2709];
    int v2788 = v2632 + ((int)((unsigned int)(v2632 - v2628) >> 31));
    v2631[v2709] = v2788;
    int * v2634 = v2532->cache_age;
    v2634[v2779] = 0;
    v2637 = v2779;
  }
  int * v2638 = v2532->cache_vals;
  int v2791 = (v2637 * 2) + (((int)((unsigned int)(v2536 + 60) >> 2)) & 1);
  v2638[v2791] = v2537;
  int * v2640 = v2532->cache_tags;
  int v2641 = v2640[v2710];
  int v2642 = v2640[v2711];
  bool v2794 = !(((~(((v2641 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2641 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v2642 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2642 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31))) == 0);
  int v2696;
  if (v2794) {
    int * v2643 = v2532->cache_age;
    int v2796 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2642 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))) | (-(v2642 ^ ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1))))) >> 31)) & 1);
    int v2644 = v2643[v2796];
    int v2645 = v2643[v2710];
    int v2797 = v2645 + ((int)((unsigned int)(v2645 - v2644) >> 31));
    v2643[v2710] = v2797;
    int * v2647 = v2532->cache_age;
    int v2648 = v2647[v2711];
    int v2799 = v2648 + ((int)((unsigned int)(v2648 - v2644) >> 31));
    v2647[v2711] = v2799;
    int * v2650 = v2532->cache_age;
    v2650[v2796] = 0;
    v2696 = v2796;
  } else {
    int * v2653 = v2532->cache_age;
    int v2803 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2);
    int v2654 = v2653[v2803];
    int * v2655 = v2532->cache_tags;
    int v2656 = v2655[v2803];
    int v2657 = v2653[v2711];
    int v2658 = v2655[v2711];
    int * v2659 = v2532->cache_dirty;
    int v2806 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2654 + ((~(((v2656 ^ -1) | (-(v2656 ^ -1))) >> 31)) & 2)) - (v2657 + ((~(((v2658 ^ -1) | (-(v2658 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2660 = v2659[v2806];
    bool v2807 = !(v2660 == 0);
    if (v2807) {
      int * v2661 = v2532->cache_tags;
      int v2662 = v2661[v2806];
      int * v2663 = v2532->cache_vals;
      int v2810 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2654 + ((~(((v2656 ^ -1) | (-(v2656 ^ -1))) >> 31)) & 2)) - (v2657 + ((~(((v2658 ^ -1) | (-(v2658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2664 = v2663[v2810];
      int v2811 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2654 + ((~(((v2656 ^ -1) | (-(v2656 ^ -1))) >> 31)) & 2)) - (v2657 + ((~(((v2658 ^ -1) | (-(v2658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2665 = v2663[v2811];
      int * v2666 = v2532->mem;
      int v2813 = v2662 * 2;
      v2666[v2813] = v2664;
      int * v2668 = v2532->mem;
      int v2816 = (v2662 * 2) + 1;
      v2668[v2816] = v2665;
      ;
    } else {
      ;
    }
    int * v2673 = v2532->mem;
    int v2821 = ((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) * 2;
    int v2674 = v2673[v2821];
    int v2822 = (((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) * 2) + 1;
    int v2675 = v2673[v2822];
    int * v2676 = v2532->cache_vals;
    int v2824 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2654 + ((~(((v2656 ^ -1) | (-(v2656 ^ -1))) >> 31)) & 2)) - (v2657 + ((~(((v2658 ^ -1) | (-(v2658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2676[v2824] = v2674;
    int * v2678 = v2532->cache_vals;
    int v2827 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v2654 + ((~(((v2656 ^ -1) | (-(v2656 ^ -1))) >> 31)) & 2)) - (v2657 + ((~(((v2658 ^ -1) | (-(v2658 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2678[v2827] = v2675;
    int * v2680 = v2532->cache_tags;
    int v2830 = (int)((unsigned int)((int)((unsigned int)(v2536 + 60) >> 2)) >> 1);
    v2680[v2806] = v2830;
    int * v2682 = v2532->cache_dirty;
    v2682[v2806] = 0;
    int * v2684 = v2532->cache_age;
    v2684[v2806] = 1;
    int * v2686 = v2532->cache_age;
    int v2687 = v2686[v2806];
    int v2688 = v2686[v2710];
    int v2836 = v2688 + ((int)((unsigned int)(v2688 - v2687) >> 31));
    v2686[v2710] = v2836;
    int * v2690 = v2532->cache_age;
    int v2691 = v2690[v2711];
    int v2838 = v2691 + ((int)((unsigned int)(v2691 - v2687) >> 31));
    v2690[v2711] = v2838;
    int * v2693 = v2532->cache_age;
    v2693[v2806] = 0;
    v2696 = v2806;
  }
  int * v2697 = v2532->cache_vals;
  int v2841 = (v2696 * 2) + (((int)((unsigned int)(v2536 + 60) >> 2)) & 1);
  v2697[v2841] = v2537;
  int * v2699 = v2532->cache_dirty;
  v2699[v2696] = 1;
  struct StateT * v2701 = slot_10(v2532);
  return v2701;
}

struct StateT * slot_183(struct StateT * v21593) {
  int v21594 = v21593->timer;
  int v21602 = v21594 + 1;
  v21593->timer = v21602;
  int * v21596 = v21593->regs;
  int v21597 = v21596[6];
  int v21598 = v21596[9];
  int v21606 = v21597 | v21598;
  v21596[6] = v21606;
  struct StateT * v21600 = slot_184(v21593);
  return v21600;
}

struct StateT * slot_240(struct StateT * v12151) {
  int v12152 = v12151->timer;
  int v12159 = v12152 + 1;
  v12151->timer = v12159;
  int * v12154 = v12151->regs;
  int v12155 = v12154[7];
  int v12162 = v12155 + -718;
  v12154[7] = v12162;
  struct StateT * v12157 = slot_241(v12151);
  return v12157;
}

struct StateT * slot_247(struct StateT * v12663) {
  int v12664 = v12663->timer;
  int v12834 = v12664 + 1;
  v12663->timer = v12834;
  int * v12666 = v12663->regs;
  int v12667 = v12666[10];
  int v12668 = v12666[29];
  int * v12669 = v12663->cache_tags;
  int v12839 = (((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2;
  int v12670 = v12669[v12839];
  int v12840 = ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12671 = v12669[v12840];
  int v12841 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2);
  int v12672 = v12669[v12841];
  int v12842 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12673 = v12669[v12842];
  int v12674 = v12663->timer;
  int v12843 = v12674 + ((100 ^ (((~(((v12672 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12672 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12670 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12670 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12671 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12671 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12672 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12672 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12663->timer = v12843;
  bool v12844 = !(((~(((v12670 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12670 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12671 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12671 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v12768;
  if (v12844) {
    int * v12676 = v12663->cache_age;
    int v12846 = ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v12671 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12671 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v12677 = v12676[v12846];
    int v12678 = v12676[v12839];
    int v12847 = v12678 + ((int)((unsigned int)(v12678 - v12677) >> 31));
    v12676[v12839] = v12847;
    int * v12680 = v12663->cache_age;
    int v12681 = v12680[v12840];
    int v12849 = v12681 + ((int)((unsigned int)(v12681 - v12677) >> 31));
    v12680[v12840] = v12849;
    int * v12683 = v12663->cache_age;
    v12683[v12846] = 0;
    v12768 = v12846;
  } else {
    int * v12686 = v12663->cache_age;
    int v12853 = (((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2;
    int v12687 = v12686[v12853];
    int * v12688 = v12663->cache_tags;
    int v12689 = v12688[v12853];
    int v12690 = v12686[v12840];
    int v12691 = v12688[v12840];
    bool v12855 = !(((~(((v12672 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12672 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v12745;
    if (v12855) {
      int * v12692 = v12663->cache_age;
      int v12857 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12673 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v12693 = v12692[v12857];
      int v12694 = v12692[v12841];
      int v12858 = v12694 + ((int)((unsigned int)(v12694 - v12693) >> 31));
      v12692[v12841] = v12858;
      int * v12696 = v12663->cache_age;
      int v12697 = v12696[v12842];
      int v12860 = v12697 + ((int)((unsigned int)(v12697 - v12693) >> 31));
      v12696[v12842] = v12860;
      int * v12699 = v12663->cache_age;
      v12699[v12857] = 0;
      v12745 = v12857;
    } else {
      int * v12702 = v12663->cache_age;
      int v12864 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2);
      int v12703 = v12702[v12864];
      int * v12704 = v12663->cache_tags;
      int v12705 = v12704[v12864];
      int v12706 = v12702[v12842];
      int v12707 = v12704[v12842];
      int * v12708 = v12663->cache_dirty;
      int v12867 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12703 + ((~(((v12705 ^ -1) | (-(v12705 ^ -1))) >> 31)) & 2)) - (v12706 + ((~(((v12707 ^ -1) | (-(v12707 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12709 = v12708[v12867];
      bool v12868 = !(v12709 == 0);
      if (v12868) {
        int * v12710 = v12663->cache_tags;
        int v12711 = v12710[v12867];
        int * v12712 = v12663->cache_vals;
        int v12871 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12703 + ((~(((v12705 ^ -1) | (-(v12705 ^ -1))) >> 31)) & 2)) - (v12706 + ((~(((v12707 ^ -1) | (-(v12707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12713 = v12712[v12871];
        int v12872 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12703 + ((~(((v12705 ^ -1) | (-(v12705 ^ -1))) >> 31)) & 2)) - (v12706 + ((~(((v12707 ^ -1) | (-(v12707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12714 = v12712[v12872];
        int * v12715 = v12663->mem;
        int v12874 = v12711 * 2;
        v12715[v12874] = v12713;
        int * v12717 = v12663->mem;
        int v12877 = (v12711 * 2) + 1;
        v12717[v12877] = v12714;
        ;
      } else {
        ;
      }
      int * v12722 = v12663->mem;
      int v12882 = ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) * 2;
      int v12723 = v12722[v12882];
      int v12883 = (((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) * 2) + 1;
      int v12724 = v12722[v12883];
      int * v12725 = v12663->cache_vals;
      int v12885 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12703 + ((~(((v12705 ^ -1) | (-(v12705 ^ -1))) >> 31)) & 2)) - (v12706 + ((~(((v12707 ^ -1) | (-(v12707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12725[v12885] = v12723;
      int * v12727 = v12663->cache_vals;
      int v12888 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12703 + ((~(((v12705 ^ -1) | (-(v12705 ^ -1))) >> 31)) & 2)) - (v12706 + ((~(((v12707 ^ -1) | (-(v12707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12727[v12888] = v12724;
      int * v12729 = v12663->cache_tags;
      int v12891 = (int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1);
      v12729[v12867] = v12891;
      int * v12731 = v12663->cache_dirty;
      v12731[v12867] = 0;
      int * v12733 = v12663->cache_age;
      v12733[v12867] = 1;
      int * v12735 = v12663->cache_age;
      int v12736 = v12735[v12867];
      int v12737 = v12735[v12841];
      int v12897 = v12737 + ((int)((unsigned int)(v12737 - v12736) >> 31));
      v12735[v12841] = v12897;
      int * v12739 = v12663->cache_age;
      int v12740 = v12739[v12842];
      int v12899 = v12740 + ((int)((unsigned int)(v12740 - v12736) >> 31));
      v12739[v12842] = v12899;
      int * v12742 = v12663->cache_age;
      v12742[v12867] = 0;
      v12745 = v12867;
    }
    int * v12746 = v12663->cache_vals;
    int v12902 = v12745 * 2;
    int v12747 = v12746[v12902];
    int v12903 = (v12745 * 2) + 1;
    int v12748 = v12746[v12903];
    int v12904 = (((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v12687 + ((~(((v12689 ^ -1) | (-(v12689 ^ -1))) >> 31)) & 2)) - (v12690 + ((~(((v12691 ^ -1) | (-(v12691 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12746[v12904] = v12747;
    int * v12750 = v12663->cache_vals;
    int v12907 = ((((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v12687 + ((~(((v12689 ^ -1) | (-(v12689 ^ -1))) >> 31)) & 2)) - (v12690 + ((~(((v12691 ^ -1) | (-(v12691 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12750[v12907] = v12748;
    int * v12752 = v12663->cache_tags;
    int v12910 = ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v12687 + ((~(((v12689 ^ -1) | (-(v12689 ^ -1))) >> 31)) & 2)) - (v12690 + ((~(((v12691 ^ -1) | (-(v12691 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12911 = (int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1);
    v12752[v12910] = v12911;
    int * v12754 = v12663->cache_dirty;
    v12754[v12910] = 0;
    int * v12756 = v12663->cache_age;
    v12756[v12910] = 1;
    int * v12758 = v12663->cache_age;
    int v12759 = v12758[v12910];
    int v12760 = v12758[v12839];
    int v12917 = v12760 + ((int)((unsigned int)(v12760 - v12759) >> 31));
    v12758[v12839] = v12917;
    int * v12762 = v12663->cache_age;
    int v12763 = v12762[v12840];
    int v12919 = v12763 + ((int)((unsigned int)(v12763 - v12759) >> 31));
    v12762[v12840] = v12919;
    int * v12765 = v12663->cache_age;
    v12765[v12910] = 0;
    v12768 = v12910;
  }
  int * v12769 = v12663->cache_vals;
  int v12922 = (v12768 * 2) + (((int)((unsigned int)(v12667 + 4) >> 2)) & 1);
  v12769[v12922] = v12668;
  int * v12771 = v12663->cache_tags;
  int v12772 = v12771[v12841];
  int v12773 = v12771[v12842];
  bool v12925 = !(((~(((v12772 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12772 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v12773 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12773 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v12827;
  if (v12925) {
    int * v12774 = v12663->cache_age;
    int v12927 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12773 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))) | (-(v12773 ^ ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v12775 = v12774[v12927];
    int v12776 = v12774[v12841];
    int v12928 = v12776 + ((int)((unsigned int)(v12776 - v12775) >> 31));
    v12774[v12841] = v12928;
    int * v12778 = v12663->cache_age;
    int v12779 = v12778[v12842];
    int v12930 = v12779 + ((int)((unsigned int)(v12779 - v12775) >> 31));
    v12778[v12842] = v12930;
    int * v12781 = v12663->cache_age;
    v12781[v12927] = 0;
    v12827 = v12927;
  } else {
    int * v12784 = v12663->cache_age;
    int v12934 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2);
    int v12785 = v12784[v12934];
    int * v12786 = v12663->cache_tags;
    int v12787 = v12786[v12934];
    int v12788 = v12784[v12842];
    int v12789 = v12786[v12842];
    int * v12790 = v12663->cache_dirty;
    int v12937 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12785 + ((~(((v12787 ^ -1) | (-(v12787 ^ -1))) >> 31)) & 2)) - (v12788 + ((~(((v12789 ^ -1) | (-(v12789 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12791 = v12790[v12937];
    bool v12938 = !(v12791 == 0);
    if (v12938) {
      int * v12792 = v12663->cache_tags;
      int v12793 = v12792[v12937];
      int * v12794 = v12663->cache_vals;
      int v12941 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12785 + ((~(((v12787 ^ -1) | (-(v12787 ^ -1))) >> 31)) & 2)) - (v12788 + ((~(((v12789 ^ -1) | (-(v12789 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12795 = v12794[v12941];
      int v12942 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12785 + ((~(((v12787 ^ -1) | (-(v12787 ^ -1))) >> 31)) & 2)) - (v12788 + ((~(((v12789 ^ -1) | (-(v12789 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12796 = v12794[v12942];
      int * v12797 = v12663->mem;
      int v12944 = v12793 * 2;
      v12797[v12944] = v12795;
      int * v12799 = v12663->mem;
      int v12947 = (v12793 * 2) + 1;
      v12799[v12947] = v12796;
      ;
    } else {
      ;
    }
    int * v12804 = v12663->mem;
    int v12952 = ((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) * 2;
    int v12805 = v12804[v12952];
    int v12953 = (((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) * 2) + 1;
    int v12806 = v12804[v12953];
    int * v12807 = v12663->cache_vals;
    int v12955 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12785 + ((~(((v12787 ^ -1) | (-(v12787 ^ -1))) >> 31)) & 2)) - (v12788 + ((~(((v12789 ^ -1) | (-(v12789 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12807[v12955] = v12805;
    int * v12809 = v12663->cache_vals;
    int v12958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v12785 + ((~(((v12787 ^ -1) | (-(v12787 ^ -1))) >> 31)) & 2)) - (v12788 + ((~(((v12789 ^ -1) | (-(v12789 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12809[v12958] = v12806;
    int * v12811 = v12663->cache_tags;
    int v12961 = (int)((unsigned int)((int)((unsigned int)(v12667 + 4) >> 2)) >> 1);
    v12811[v12937] = v12961;
    int * v12813 = v12663->cache_dirty;
    v12813[v12937] = 0;
    int * v12815 = v12663->cache_age;
    v12815[v12937] = 1;
    int * v12817 = v12663->cache_age;
    int v12818 = v12817[v12937];
    int v12819 = v12817[v12841];
    int v12967 = v12819 + ((int)((unsigned int)(v12819 - v12818) >> 31));
    v12817[v12841] = v12967;
    int * v12821 = v12663->cache_age;
    int v12822 = v12821[v12842];
    int v12969 = v12822 + ((int)((unsigned int)(v12822 - v12818) >> 31));
    v12821[v12842] = v12969;
    int * v12824 = v12663->cache_age;
    v12824[v12937] = 0;
    v12827 = v12937;
  }
  int * v12828 = v12663->cache_vals;
  int v12972 = (v12827 * 2) + (((int)((unsigned int)(v12667 + 4) >> 2)) & 1);
  v12828[v12972] = v12668;
  int * v12830 = v12663->cache_dirty;
  v12830[v12827] = 1;
  struct StateT * v12832 = slot_248(v12663);
  return v12832;
}

struct StateT * slot_43(struct StateT * v8893) {
  int v8894 = v8893->timer;
  int v9064 = v8894 + 1;
  v8893->timer = v9064;
  int * v8896 = v8893->regs;
  int v8897 = v8896[2];
  int v8898 = v8896[6];
  int * v8899 = v8893->cache_tags;
  int v9069 = (((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2;
  int v8900 = v8899[v9069];
  int v9070 = ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8901 = v8899[v9070];
  int v9071 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2);
  int v8902 = v8899[v9071];
  int v9072 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8903 = v8899[v9072];
  int v8904 = v8893->timer;
  int v9073 = v8904 + ((100 ^ (((~(((v8902 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8902 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8900 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8900 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8901 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8901 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8902 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8902 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8893->timer = v9073;
  bool v9074 = !(((~(((v8900 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8900 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8901 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8901 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v8998;
  if (v9074) {
    int * v8906 = v8893->cache_age;
    int v9076 = ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v8901 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8901 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v8907 = v8906[v9076];
    int v8908 = v8906[v9069];
    int v9077 = v8908 + ((int)((unsigned int)(v8908 - v8907) >> 31));
    v8906[v9069] = v9077;
    int * v8910 = v8893->cache_age;
    int v8911 = v8910[v9070];
    int v9079 = v8911 + ((int)((unsigned int)(v8911 - v8907) >> 31));
    v8910[v9070] = v9079;
    int * v8913 = v8893->cache_age;
    v8913[v9076] = 0;
    v8998 = v9076;
  } else {
    int * v8916 = v8893->cache_age;
    int v9083 = (((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2;
    int v8917 = v8916[v9083];
    int * v8918 = v8893->cache_tags;
    int v8919 = v8918[v9083];
    int v8920 = v8916[v9070];
    int v8921 = v8918[v9070];
    bool v9085 = !(((~(((v8902 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8902 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v8975;
    if (v9085) {
      int * v8922 = v8893->cache_age;
      int v9087 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v8903 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v8923 = v8922[v9087];
      int v8924 = v8922[v9071];
      int v9088 = v8924 + ((int)((unsigned int)(v8924 - v8923) >> 31));
      v8922[v9071] = v9088;
      int * v8926 = v8893->cache_age;
      int v8927 = v8926[v9072];
      int v9090 = v8927 + ((int)((unsigned int)(v8927 - v8923) >> 31));
      v8926[v9072] = v9090;
      int * v8929 = v8893->cache_age;
      v8929[v9087] = 0;
      v8975 = v9087;
    } else {
      int * v8932 = v8893->cache_age;
      int v9094 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2);
      int v8933 = v8932[v9094];
      int * v8934 = v8893->cache_tags;
      int v8935 = v8934[v9094];
      int v8936 = v8932[v9072];
      int v8937 = v8934[v9072];
      int * v8938 = v8893->cache_dirty;
      int v9097 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v8933 + ((~(((v8935 ^ -1) | (-(v8935 ^ -1))) >> 31)) & 2)) - (v8936 + ((~(((v8937 ^ -1) | (-(v8937 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8939 = v8938[v9097];
      bool v9098 = !(v8939 == 0);
      if (v9098) {
        int * v8940 = v8893->cache_tags;
        int v8941 = v8940[v9097];
        int * v8942 = v8893->cache_vals;
        int v9101 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v8933 + ((~(((v8935 ^ -1) | (-(v8935 ^ -1))) >> 31)) & 2)) - (v8936 + ((~(((v8937 ^ -1) | (-(v8937 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8943 = v8942[v9101];
        int v9102 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v8933 + ((~(((v8935 ^ -1) | (-(v8935 ^ -1))) >> 31)) & 2)) - (v8936 + ((~(((v8937 ^ -1) | (-(v8937 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8944 = v8942[v9102];
        int * v8945 = v8893->mem;
        int v9104 = v8941 * 2;
        v8945[v9104] = v8943;
        int * v8947 = v8893->mem;
        int v9107 = (v8941 * 2) + 1;
        v8947[v9107] = v8944;
        ;
      } else {
        ;
      }
      int * v8952 = v8893->mem;
      int v9112 = ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) * 2;
      int v8953 = v8952[v9112];
      int v9113 = (((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) * 2) + 1;
      int v8954 = v8952[v9113];
      int * v8955 = v8893->cache_vals;
      int v9115 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v8933 + ((~(((v8935 ^ -1) | (-(v8935 ^ -1))) >> 31)) & 2)) - (v8936 + ((~(((v8937 ^ -1) | (-(v8937 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8955[v9115] = v8953;
      int * v8957 = v8893->cache_vals;
      int v9118 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v8933 + ((~(((v8935 ^ -1) | (-(v8935 ^ -1))) >> 31)) & 2)) - (v8936 + ((~(((v8937 ^ -1) | (-(v8937 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8957[v9118] = v8954;
      int * v8959 = v8893->cache_tags;
      int v9121 = (int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1);
      v8959[v9097] = v9121;
      int * v8961 = v8893->cache_dirty;
      v8961[v9097] = 0;
      int * v8963 = v8893->cache_age;
      v8963[v9097] = 1;
      int * v8965 = v8893->cache_age;
      int v8966 = v8965[v9097];
      int v8967 = v8965[v9071];
      int v9127 = v8967 + ((int)((unsigned int)(v8967 - v8966) >> 31));
      v8965[v9071] = v9127;
      int * v8969 = v8893->cache_age;
      int v8970 = v8969[v9072];
      int v9129 = v8970 + ((int)((unsigned int)(v8970 - v8966) >> 31));
      v8969[v9072] = v9129;
      int * v8972 = v8893->cache_age;
      v8972[v9097] = 0;
      v8975 = v9097;
    }
    int * v8976 = v8893->cache_vals;
    int v9132 = v8975 * 2;
    int v8977 = v8976[v9132];
    int v9133 = (v8975 * 2) + 1;
    int v8978 = v8976[v9133];
    int v9134 = (((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v8917 + ((~(((v8919 ^ -1) | (-(v8919 ^ -1))) >> 31)) & 2)) - (v8920 + ((~(((v8921 ^ -1) | (-(v8921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8976[v9134] = v8977;
    int * v8980 = v8893->cache_vals;
    int v9137 = ((((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v8917 + ((~(((v8919 ^ -1) | (-(v8919 ^ -1))) >> 31)) & 2)) - (v8920 + ((~(((v8921 ^ -1) | (-(v8921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8980[v9137] = v8978;
    int * v8982 = v8893->cache_tags;
    int v9140 = ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v8917 + ((~(((v8919 ^ -1) | (-(v8919 ^ -1))) >> 31)) & 2)) - (v8920 + ((~(((v8921 ^ -1) | (-(v8921 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9141 = (int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1);
    v8982[v9140] = v9141;
    int * v8984 = v8893->cache_dirty;
    v8984[v9140] = 0;
    int * v8986 = v8893->cache_age;
    v8986[v9140] = 1;
    int * v8988 = v8893->cache_age;
    int v8989 = v8988[v9140];
    int v8990 = v8988[v9069];
    int v9147 = v8990 + ((int)((unsigned int)(v8990 - v8989) >> 31));
    v8988[v9069] = v9147;
    int * v8992 = v8893->cache_age;
    int v8993 = v8992[v9070];
    int v9149 = v8993 + ((int)((unsigned int)(v8993 - v8989) >> 31));
    v8992[v9070] = v9149;
    int * v8995 = v8893->cache_age;
    v8995[v9140] = 0;
    v8998 = v9140;
  }
  int * v8999 = v8893->cache_vals;
  int v9152 = (v8998 * 2) + (((int)((unsigned int)(v8897 + 8) >> 2)) & 1);
  v8999[v9152] = v8898;
  int * v9001 = v8893->cache_tags;
  int v9002 = v9001[v9071];
  int v9003 = v9001[v9072];
  bool v9155 = !(((~(((v9002 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v9002 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9003 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v9003 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v9057;
  if (v9155) {
    int * v9004 = v8893->cache_age;
    int v9157 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9003 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))) | (-(v9003 ^ ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v9005 = v9004[v9157];
    int v9006 = v9004[v9071];
    int v9158 = v9006 + ((int)((unsigned int)(v9006 - v9005) >> 31));
    v9004[v9071] = v9158;
    int * v9008 = v8893->cache_age;
    int v9009 = v9008[v9072];
    int v9160 = v9009 + ((int)((unsigned int)(v9009 - v9005) >> 31));
    v9008[v9072] = v9160;
    int * v9011 = v8893->cache_age;
    v9011[v9157] = 0;
    v9057 = v9157;
  } else {
    int * v9014 = v8893->cache_age;
    int v9164 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2);
    int v9015 = v9014[v9164];
    int * v9016 = v8893->cache_tags;
    int v9017 = v9016[v9164];
    int v9018 = v9014[v9072];
    int v9019 = v9016[v9072];
    int * v9020 = v8893->cache_dirty;
    int v9167 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9015 + ((~(((v9017 ^ -1) | (-(v9017 ^ -1))) >> 31)) & 2)) - (v9018 + ((~(((v9019 ^ -1) | (-(v9019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9021 = v9020[v9167];
    bool v9168 = !(v9021 == 0);
    if (v9168) {
      int * v9022 = v8893->cache_tags;
      int v9023 = v9022[v9167];
      int * v9024 = v8893->cache_vals;
      int v9171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9015 + ((~(((v9017 ^ -1) | (-(v9017 ^ -1))) >> 31)) & 2)) - (v9018 + ((~(((v9019 ^ -1) | (-(v9019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9025 = v9024[v9171];
      int v9172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9015 + ((~(((v9017 ^ -1) | (-(v9017 ^ -1))) >> 31)) & 2)) - (v9018 + ((~(((v9019 ^ -1) | (-(v9019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9026 = v9024[v9172];
      int * v9027 = v8893->mem;
      int v9174 = v9023 * 2;
      v9027[v9174] = v9025;
      int * v9029 = v8893->mem;
      int v9177 = (v9023 * 2) + 1;
      v9029[v9177] = v9026;
      ;
    } else {
      ;
    }
    int * v9034 = v8893->mem;
    int v9182 = ((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) * 2;
    int v9035 = v9034[v9182];
    int v9183 = (((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) * 2) + 1;
    int v9036 = v9034[v9183];
    int * v9037 = v8893->cache_vals;
    int v9185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9015 + ((~(((v9017 ^ -1) | (-(v9017 ^ -1))) >> 31)) & 2)) - (v9018 + ((~(((v9019 ^ -1) | (-(v9019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9037[v9185] = v9035;
    int * v9039 = v8893->cache_vals;
    int v9188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9015 + ((~(((v9017 ^ -1) | (-(v9017 ^ -1))) >> 31)) & 2)) - (v9018 + ((~(((v9019 ^ -1) | (-(v9019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9039[v9188] = v9036;
    int * v9041 = v8893->cache_tags;
    int v9191 = (int)((unsigned int)((int)((unsigned int)(v8897 + 8) >> 2)) >> 1);
    v9041[v9167] = v9191;
    int * v9043 = v8893->cache_dirty;
    v9043[v9167] = 0;
    int * v9045 = v8893->cache_age;
    v9045[v9167] = 1;
    int * v9047 = v8893->cache_age;
    int v9048 = v9047[v9167];
    int v9049 = v9047[v9071];
    int v9197 = v9049 + ((int)((unsigned int)(v9049 - v9048) >> 31));
    v9047[v9071] = v9197;
    int * v9051 = v8893->cache_age;
    int v9052 = v9051[v9072];
    int v9199 = v9052 + ((int)((unsigned int)(v9052 - v9048) >> 31));
    v9051[v9072] = v9199;
    int * v9054 = v8893->cache_age;
    v9054[v9167] = 0;
    v9057 = v9167;
  }
  int * v9058 = v8893->cache_vals;
  int v9202 = (v9057 * 2) + (((int)((unsigned int)(v8897 + 8) >> 2)) & 1);
  v9058[v9202] = v8898;
  int * v9060 = v8893->cache_dirty;
  v9060[v9057] = 1;
  struct StateT * v9062 = slot_44(v8893);
  return v9062;
}

struct StateT * slot_70(struct StateT * v11541) {
  int v11542 = v11541->timer;
  int v11550 = v11542 + 1;
  v11541->timer = v11550;
  int * v11544 = v11541->regs;
  int v11545 = v11544[14];
  int v11546 = v11544[8];
  int v11554 = v11545 ^ v11546;
  v11544[14] = v11554;
  struct StateT * v11548 = slot_71(v11541);
  return v11548;
}

struct StateT * slot_168(struct StateT * v21358) {
  int v21359 = v21358->timer;
  int v21367 = v21359 + 1;
  v21358->timer = v21367;
  int * v21361 = v21358->regs;
  int v21362 = v21361[25];
  int v21363 = v21361[15];
  int v21371 = v21362 ^ v21363;
  v21361[25] = v21371;
  struct StateT * v21365 = slot_169(v21358);
  return v21365;
}

struct StateT * slot_76(struct StateT * v12107) {
  int v12108 = v12107->timer;
  int v12115 = v12108 + 1;
  v12107->timer = v12115;
  int * v12110 = v12107->regs;
  int v12111 = v12110[15];
  int v12118 = v12111 << 9;
  v12110[15] = v12118;
  struct StateT * v12113 = slot_77(v12107);
  return v12113;
}

struct StateT * slot_6(struct StateT * v1587) {
  int v1588 = v1587->timer;
  int v1758 = v1588 + 1;
  v1587->timer = v1758;
  int * v1590 = v1587->regs;
  int v1591 = v1590[2];
  int v1592 = v1590[20];
  int * v1593 = v1587->cache_tags;
  int v1763 = (((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2;
  int v1594 = v1593[v1763];
  int v1764 = ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1595 = v1593[v1764];
  int v1765 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2);
  int v1596 = v1593[v1765];
  int v1766 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1597 = v1593[v1766];
  int v1598 = v1587->timer;
  int v1767 = v1598 + ((100 ^ (((~(((v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1594 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1594 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1587->timer = v1767;
  bool v1768 = !(((~(((v1594 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1594 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31))) == 0);
  int v1692;
  if (v1768) {
    int * v1600 = v1587->cache_age;
    int v1770 = ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2) + ((~(((v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1595 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) & 1);
    int v1601 = v1600[v1770];
    int v1602 = v1600[v1763];
    int v1771 = v1602 + ((int)((unsigned int)(v1602 - v1601) >> 31));
    v1600[v1763] = v1771;
    int * v1604 = v1587->cache_age;
    int v1605 = v1604[v1764];
    int v1773 = v1605 + ((int)((unsigned int)(v1605 - v1601) >> 31));
    v1604[v1764] = v1773;
    int * v1607 = v1587->cache_age;
    v1607[v1770] = 0;
    v1692 = v1770;
  } else {
    int * v1610 = v1587->cache_age;
    int v1777 = (((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2;
    int v1611 = v1610[v1777];
    int * v1612 = v1587->cache_tags;
    int v1613 = v1612[v1777];
    int v1614 = v1610[v1764];
    int v1615 = v1612[v1764];
    bool v1779 = !(((~(((v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1596 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31))) == 0);
    int v1669;
    if (v1779) {
      int * v1616 = v1587->cache_age;
      int v1781 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1597 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) & 1);
      int v1617 = v1616[v1781];
      int v1618 = v1616[v1765];
      int v1782 = v1618 + ((int)((unsigned int)(v1618 - v1617) >> 31));
      v1616[v1765] = v1782;
      int * v1620 = v1587->cache_age;
      int v1621 = v1620[v1766];
      int v1784 = v1621 + ((int)((unsigned int)(v1621 - v1617) >> 31));
      v1620[v1766] = v1784;
      int * v1623 = v1587->cache_age;
      v1623[v1781] = 0;
      v1669 = v1781;
    } else {
      int * v1626 = v1587->cache_age;
      int v1788 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2);
      int v1627 = v1626[v1788];
      int * v1628 = v1587->cache_tags;
      int v1629 = v1628[v1788];
      int v1630 = v1626[v1766];
      int v1631 = v1628[v1766];
      int * v1632 = v1587->cache_dirty;
      int v1791 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1633 = v1632[v1791];
      bool v1792 = !(v1633 == 0);
      if (v1792) {
        int * v1634 = v1587->cache_tags;
        int v1635 = v1634[v1791];
        int * v1636 = v1587->cache_vals;
        int v1795 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1637 = v1636[v1795];
        int v1796 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1638 = v1636[v1796];
        int * v1639 = v1587->mem;
        int v1798 = v1635 * 2;
        v1639[v1798] = v1637;
        int * v1641 = v1587->mem;
        int v1801 = (v1635 * 2) + 1;
        v1641[v1801] = v1638;
        ;
      } else {
        ;
      }
      int * v1646 = v1587->mem;
      int v1806 = ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) * 2;
      int v1647 = v1646[v1806];
      int v1807 = (((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) * 2) + 1;
      int v1648 = v1646[v1807];
      int * v1649 = v1587->cache_vals;
      int v1809 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1649[v1809] = v1647;
      int * v1651 = v1587->cache_vals;
      int v1812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1627 + ((~(((v1629 ^ -1) | (-(v1629 ^ -1))) >> 31)) & 2)) - (v1630 + ((~(((v1631 ^ -1) | (-(v1631 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1651[v1812] = v1648;
      int * v1653 = v1587->cache_tags;
      int v1815 = (int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1);
      v1653[v1791] = v1815;
      int * v1655 = v1587->cache_dirty;
      v1655[v1791] = 0;
      int * v1657 = v1587->cache_age;
      v1657[v1791] = 1;
      int * v1659 = v1587->cache_age;
      int v1660 = v1659[v1791];
      int v1661 = v1659[v1765];
      int v1821 = v1661 + ((int)((unsigned int)(v1661 - v1660) >> 31));
      v1659[v1765] = v1821;
      int * v1663 = v1587->cache_age;
      int v1664 = v1663[v1766];
      int v1823 = v1664 + ((int)((unsigned int)(v1664 - v1660) >> 31));
      v1663[v1766] = v1823;
      int * v1666 = v1587->cache_age;
      v1666[v1791] = 0;
      v1669 = v1791;
    }
    int * v1670 = v1587->cache_vals;
    int v1826 = v1669 * 2;
    int v1671 = v1670[v1826];
    int v1827 = (v1669 * 2) + 1;
    int v1672 = v1670[v1827];
    int v1828 = (((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2) + ((((v1611 + ((~(((v1613 ^ -1) | (-(v1613 ^ -1))) >> 31)) & 2)) - (v1614 + ((~(((v1615 ^ -1) | (-(v1615 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1670[v1828] = v1671;
    int * v1674 = v1587->cache_vals;
    int v1831 = ((((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2) + ((((v1611 + ((~(((v1613 ^ -1) | (-(v1613 ^ -1))) >> 31)) & 2)) - (v1614 + ((~(((v1615 ^ -1) | (-(v1615 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1674[v1831] = v1672;
    int * v1676 = v1587->cache_tags;
    int v1834 = ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 1) * 2) + ((((v1611 + ((~(((v1613 ^ -1) | (-(v1613 ^ -1))) >> 31)) & 2)) - (v1614 + ((~(((v1615 ^ -1) | (-(v1615 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1835 = (int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1);
    v1676[v1834] = v1835;
    int * v1678 = v1587->cache_dirty;
    v1678[v1834] = 0;
    int * v1680 = v1587->cache_age;
    v1680[v1834] = 1;
    int * v1682 = v1587->cache_age;
    int v1683 = v1682[v1834];
    int v1684 = v1682[v1763];
    int v1841 = v1684 + ((int)((unsigned int)(v1684 - v1683) >> 31));
    v1682[v1763] = v1841;
    int * v1686 = v1587->cache_age;
    int v1687 = v1686[v1764];
    int v1843 = v1687 + ((int)((unsigned int)(v1687 - v1683) >> 31));
    v1686[v1764] = v1843;
    int * v1689 = v1587->cache_age;
    v1689[v1834] = 0;
    v1692 = v1834;
  }
  int * v1693 = v1587->cache_vals;
  int v1846 = (v1692 * 2) + (((int)((unsigned int)(v1591 + 72) >> 2)) & 1);
  v1693[v1846] = v1592;
  int * v1695 = v1587->cache_tags;
  int v1696 = v1695[v1765];
  int v1697 = v1695[v1766];
  bool v1849 = !(((~(((v1696 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1696 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) | (~(((v1697 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1697 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31))) == 0);
  int v1751;
  if (v1849) {
    int * v1698 = v1587->cache_age;
    int v1851 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1697 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))) | (-(v1697 ^ ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1))))) >> 31)) & 1);
    int v1699 = v1698[v1851];
    int v1700 = v1698[v1765];
    int v1852 = v1700 + ((int)((unsigned int)(v1700 - v1699) >> 31));
    v1698[v1765] = v1852;
    int * v1702 = v1587->cache_age;
    int v1703 = v1702[v1766];
    int v1854 = v1703 + ((int)((unsigned int)(v1703 - v1699) >> 31));
    v1702[v1766] = v1854;
    int * v1705 = v1587->cache_age;
    v1705[v1851] = 0;
    v1751 = v1851;
  } else {
    int * v1708 = v1587->cache_age;
    int v1858 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2);
    int v1709 = v1708[v1858];
    int * v1710 = v1587->cache_tags;
    int v1711 = v1710[v1858];
    int v1712 = v1708[v1766];
    int v1713 = v1710[v1766];
    int * v1714 = v1587->cache_dirty;
    int v1861 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1709 + ((~(((v1711 ^ -1) | (-(v1711 ^ -1))) >> 31)) & 2)) - (v1712 + ((~(((v1713 ^ -1) | (-(v1713 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1715 = v1714[v1861];
    bool v1862 = !(v1715 == 0);
    if (v1862) {
      int * v1716 = v1587->cache_tags;
      int v1717 = v1716[v1861];
      int * v1718 = v1587->cache_vals;
      int v1865 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1709 + ((~(((v1711 ^ -1) | (-(v1711 ^ -1))) >> 31)) & 2)) - (v1712 + ((~(((v1713 ^ -1) | (-(v1713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1719 = v1718[v1865];
      int v1866 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1709 + ((~(((v1711 ^ -1) | (-(v1711 ^ -1))) >> 31)) & 2)) - (v1712 + ((~(((v1713 ^ -1) | (-(v1713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1720 = v1718[v1866];
      int * v1721 = v1587->mem;
      int v1868 = v1717 * 2;
      v1721[v1868] = v1719;
      int * v1723 = v1587->mem;
      int v1871 = (v1717 * 2) + 1;
      v1723[v1871] = v1720;
      ;
    } else {
      ;
    }
    int * v1728 = v1587->mem;
    int v1876 = ((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) * 2;
    int v1729 = v1728[v1876];
    int v1877 = (((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) * 2) + 1;
    int v1730 = v1728[v1877];
    int * v1731 = v1587->cache_vals;
    int v1879 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1709 + ((~(((v1711 ^ -1) | (-(v1711 ^ -1))) >> 31)) & 2)) - (v1712 + ((~(((v1713 ^ -1) | (-(v1713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1731[v1879] = v1729;
    int * v1733 = v1587->cache_vals;
    int v1882 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1)) & 3) * 2)) + ((((v1709 + ((~(((v1711 ^ -1) | (-(v1711 ^ -1))) >> 31)) & 2)) - (v1712 + ((~(((v1713 ^ -1) | (-(v1713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1733[v1882] = v1730;
    int * v1735 = v1587->cache_tags;
    int v1885 = (int)((unsigned int)((int)((unsigned int)(v1591 + 72) >> 2)) >> 1);
    v1735[v1861] = v1885;
    int * v1737 = v1587->cache_dirty;
    v1737[v1861] = 0;
    int * v1739 = v1587->cache_age;
    v1739[v1861] = 1;
    int * v1741 = v1587->cache_age;
    int v1742 = v1741[v1861];
    int v1743 = v1741[v1765];
    int v1891 = v1743 + ((int)((unsigned int)(v1743 - v1742) >> 31));
    v1741[v1765] = v1891;
    int * v1745 = v1587->cache_age;
    int v1746 = v1745[v1766];
    int v1893 = v1746 + ((int)((unsigned int)(v1746 - v1742) >> 31));
    v1745[v1766] = v1893;
    int * v1748 = v1587->cache_age;
    v1748[v1861] = 0;
    v1751 = v1861;
  }
  int * v1752 = v1587->cache_vals;
  int v1896 = (v1751 * 2) + (((int)((unsigned int)(v1591 + 72) >> 2)) & 1);
  v1752[v1896] = v1592;
  int * v1754 = v1587->cache_dirty;
  v1754[v1751] = 1;
  struct StateT * v1756 = slot_7(v1587);
  return v1756;
}

struct StateT * slot_225(struct StateT * v10743) {
  int v10744 = v10743->timer;
  int v10752 = v10744 + 1;
  v10743->timer = v10752;
  int * v10746 = v10743->regs;
  int v10747 = v10746[26];
  int v10748 = v10746[7];
  int v10756 = v10747 + v10748;
  v10746[26] = v10756;
  struct StateT * v10750 = slot_226(v10743);
  return v10750;
}

struct StateT * slot_55(struct StateT * v9951) {
  int v9952 = v9951->timer;
  int v9959 = v9952 + 1;
  v9951->timer = v9959;
  int * v9954 = v9951->regs;
  int v9955 = v9954[15];
  int v9963 = (int)((unsigned int)v9955 >> 25);
  v9954[9] = v9963;
  struct StateT * v9957 = slot_56(v9951);
  return v9957;
}

struct StateT * slot_213(struct StateT * v9618) {
  int v9619 = v9618->timer;
  int v9627 = v9619 + 1;
  v9618->timer = v9627;
  int * v9621 = v9618->regs;
  int v9622 = v9621[23];
  int v9623 = v9621[29];
  int v9631 = v9622 + v9623;
  v9621[29] = v9631;
  struct StateT * v9625 = slot_214(v9618);
  return v9625;
}

struct StateT * slot_82(struct StateT * v12287) {
  int v12288 = v12287->timer;
  int v12295 = v12288 + 1;
  v12287->timer = v12295;
  int * v12290 = v12287->regs;
  int v12291 = v12290[9];
  int v12298 = v12291 << 9;
  v12290[9] = v12298;
  struct StateT * v12293 = slot_83(v12287);
  return v12293;
}

struct StateT * slot_274(struct StateT * v20259) {
  int v20260 = v20259->timer;
  int v20370 = v20260 + 1;
  v20259->timer = v20370;
  int * v20262 = v20259->regs;
  int v20263 = v20262[2];
  int * v20264 = v20259->cache_tags;
  int v20374 = (((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2;
  int v20265 = v20264[v20374];
  int v20375 = ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v20266 = v20264[v20375];
  int v20376 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2);
  int v20267 = v20264[v20376];
  int v20377 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v20268 = v20264[v20377];
  int v20269 = v20259->timer;
  int v20378 = v20269 + ((100 ^ (((~(((v20267 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20267 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20265 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20265 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v20266 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20266 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v20267 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20267 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v20259->timer = v20378;
  int * v20271 = v20259->cache_vals;
  bool v20379 = !(((~(((v20265 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20265 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v20266 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20266 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v20364;
  if (v20379) {
    int * v20272 = v20259->cache_age;
    int v20381 = ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v20266 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20266 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v20273 = v20272[v20381];
    int v20274 = v20272[v20374];
    int v20382 = v20274 + ((int)((unsigned int)(v20274 - v20273) >> 31));
    v20272[v20374] = v20382;
    int * v20276 = v20259->cache_age;
    int v20277 = v20276[v20375];
    int v20384 = v20277 + ((int)((unsigned int)(v20277 - v20273) >> 31));
    v20276[v20375] = v20384;
    int * v20279 = v20259->cache_age;
    v20279[v20381] = 0;
    v20364 = v20381;
  } else {
    int * v20282 = v20259->cache_age;
    int v20388 = (((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2;
    int v20283 = v20282[v20388];
    int * v20284 = v20259->cache_tags;
    int v20285 = v20284[v20388];
    int v20286 = v20282[v20375];
    int v20287 = v20284[v20375];
    bool v20390 = !(((~(((v20267 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20267 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v20341;
    if (v20390) {
      int * v20288 = v20259->cache_age;
      int v20392 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))) | (-(v20268 ^ ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v20289 = v20288[v20392];
      int v20290 = v20288[v20376];
      int v20393 = v20290 + ((int)((unsigned int)(v20290 - v20289) >> 31));
      v20288[v20376] = v20393;
      int * v20292 = v20259->cache_age;
      int v20293 = v20292[v20377];
      int v20395 = v20293 + ((int)((unsigned int)(v20293 - v20289) >> 31));
      v20292[v20377] = v20395;
      int * v20295 = v20259->cache_age;
      v20295[v20392] = 0;
      v20341 = v20392;
    } else {
      int * v20298 = v20259->cache_age;
      int v20399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2);
      int v20299 = v20298[v20399];
      int * v20300 = v20259->cache_tags;
      int v20301 = v20300[v20399];
      int v20302 = v20298[v20377];
      int v20303 = v20300[v20377];
      int * v20304 = v20259->cache_dirty;
      int v20402 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v20299 + ((~(((v20301 ^ -1) | (-(v20301 ^ -1))) >> 31)) & 2)) - (v20302 + ((~(((v20303 ^ -1) | (-(v20303 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v20305 = v20304[v20402];
      bool v20403 = !(v20305 == 0);
      if (v20403) {
        int * v20306 = v20259->cache_tags;
        int v20307 = v20306[v20402];
        int * v20308 = v20259->cache_vals;
        int v20406 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v20299 + ((~(((v20301 ^ -1) | (-(v20301 ^ -1))) >> 31)) & 2)) - (v20302 + ((~(((v20303 ^ -1) | (-(v20303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v20309 = v20308[v20406];
        int v20407 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v20299 + ((~(((v20301 ^ -1) | (-(v20301 ^ -1))) >> 31)) & 2)) - (v20302 + ((~(((v20303 ^ -1) | (-(v20303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v20310 = v20308[v20407];
        int * v20311 = v20259->mem;
        int v20409 = v20307 * 2;
        v20311[v20409] = v20309;
        int * v20313 = v20259->mem;
        int v20412 = (v20307 * 2) + 1;
        v20313[v20412] = v20310;
        ;
      } else {
        ;
      }
      int * v20318 = v20259->mem;
      int v20417 = ((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) * 2;
      int v20319 = v20318[v20417];
      int v20418 = (((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) * 2) + 1;
      int v20320 = v20318[v20418];
      int * v20321 = v20259->cache_vals;
      int v20420 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v20299 + ((~(((v20301 ^ -1) | (-(v20301 ^ -1))) >> 31)) & 2)) - (v20302 + ((~(((v20303 ^ -1) | (-(v20303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v20321[v20420] = v20319;
      int * v20323 = v20259->cache_vals;
      int v20423 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v20299 + ((~(((v20301 ^ -1) | (-(v20301 ^ -1))) >> 31)) & 2)) - (v20302 + ((~(((v20303 ^ -1) | (-(v20303 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v20323[v20423] = v20320;
      int * v20325 = v20259->cache_tags;
      int v20426 = (int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1);
      v20325[v20402] = v20426;
      int * v20327 = v20259->cache_dirty;
      v20327[v20402] = 0;
      int * v20329 = v20259->cache_age;
      v20329[v20402] = 1;
      int * v20331 = v20259->cache_age;
      int v20332 = v20331[v20402];
      int v20333 = v20331[v20376];
      int v20432 = v20333 + ((int)((unsigned int)(v20333 - v20332) >> 31));
      v20331[v20376] = v20432;
      int * v20335 = v20259->cache_age;
      int v20336 = v20335[v20377];
      int v20434 = v20336 + ((int)((unsigned int)(v20336 - v20332) >> 31));
      v20335[v20377] = v20434;
      int * v20338 = v20259->cache_age;
      v20338[v20402] = 0;
      v20341 = v20402;
    }
    int * v20342 = v20259->cache_vals;
    int v20437 = v20341 * 2;
    int v20343 = v20342[v20437];
    int v20438 = (v20341 * 2) + 1;
    int v20344 = v20342[v20438];
    int v20439 = (((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v20283 + ((~(((v20285 ^ -1) | (-(v20285 ^ -1))) >> 31)) & 2)) - (v20286 + ((~(((v20287 ^ -1) | (-(v20287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v20342[v20439] = v20343;
    int * v20346 = v20259->cache_vals;
    int v20442 = ((((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v20283 + ((~(((v20285 ^ -1) | (-(v20285 ^ -1))) >> 31)) & 2)) - (v20286 + ((~(((v20287 ^ -1) | (-(v20287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v20346[v20442] = v20344;
    int * v20348 = v20259->cache_tags;
    int v20445 = ((((int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v20283 + ((~(((v20285 ^ -1) | (-(v20285 ^ -1))) >> 31)) & 2)) - (v20286 + ((~(((v20287 ^ -1) | (-(v20287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v20446 = (int)((unsigned int)((int)((unsigned int)(v20263 + 44) >> 2)) >> 1);
    v20348[v20445] = v20446;
    int * v20350 = v20259->cache_dirty;
    v20350[v20445] = 0;
    int * v20352 = v20259->cache_age;
    v20352[v20445] = 1;
    int * v20354 = v20259->cache_age;
    int v20355 = v20354[v20445];
    int v20356 = v20354[v20374];
    int v20452 = v20356 + ((int)((unsigned int)(v20356 - v20355) >> 31));
    v20354[v20374] = v20452;
    int * v20358 = v20259->cache_age;
    int v20359 = v20358[v20375];
    int v20454 = v20359 + ((int)((unsigned int)(v20359 - v20355) >> 31));
    v20358[v20375] = v20454;
    int * v20361 = v20259->cache_age;
    v20361[v20445] = 0;
    v20364 = v20445;
  }
  int v20457 = (v20364 * 2) + (((int)((unsigned int)(v20263 + 44) >> 2)) & 1);
  int v20365 = v20271[v20457];
  int * v20366 = v20259->regs;
  v20366[27] = v20365;
  struct StateT * v20368 = slot_275(v20259);
  return v20368;
}

struct StateT * slot_263(struct StateT * v17840) {
  int v17841 = v17840->timer;
  int v17951 = v17841 + 1;
  v17840->timer = v17951;
  int * v17843 = v17840->regs;
  int v17844 = v17843[2];
  int * v17845 = v17840->cache_tags;
  int v17955 = (((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2;
  int v17846 = v17845[v17955];
  int v17956 = ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2) + 1;
  int v17847 = v17845[v17956];
  int v17957 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2);
  int v17848 = v17845[v17957];
  int v17958 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17849 = v17845[v17958];
  int v17850 = v17840->timer;
  int v17959 = v17850 + ((100 ^ (((~(((v17848 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17848 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v17846 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17846 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v17847 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17847 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v17848 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17848 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31))) & 104)))));
  v17840->timer = v17959;
  int * v17852 = v17840->cache_vals;
  bool v17960 = !(((~(((v17846 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17846 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v17847 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17847 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31))) == 0);
  int v17945;
  if (v17960) {
    int * v17853 = v17840->cache_age;
    int v17962 = ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2) + ((~(((v17847 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17847 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) & 1);
    int v17854 = v17853[v17962];
    int v17855 = v17853[v17955];
    int v17963 = v17855 + ((int)((unsigned int)(v17855 - v17854) >> 31));
    v17853[v17955] = v17963;
    int * v17857 = v17840->cache_age;
    int v17858 = v17857[v17956];
    int v17965 = v17858 + ((int)((unsigned int)(v17858 - v17854) >> 31));
    v17857[v17956] = v17965;
    int * v17860 = v17840->cache_age;
    v17860[v17962] = 0;
    v17945 = v17962;
  } else {
    int * v17863 = v17840->cache_age;
    int v17969 = (((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2;
    int v17864 = v17863[v17969];
    int * v17865 = v17840->cache_tags;
    int v17866 = v17865[v17969];
    int v17867 = v17863[v17956];
    int v17868 = v17865[v17956];
    bool v17971 = !(((~(((v17848 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17848 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31))) == 0);
    int v17922;
    if (v17971) {
      int * v17869 = v17840->cache_age;
      int v17973 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))) | (-(v17849 ^ ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1))))) >> 31)) & 1);
      int v17870 = v17869[v17973];
      int v17871 = v17869[v17957];
      int v17974 = v17871 + ((int)((unsigned int)(v17871 - v17870) >> 31));
      v17869[v17957] = v17974;
      int * v17873 = v17840->cache_age;
      int v17874 = v17873[v17958];
      int v17976 = v17874 + ((int)((unsigned int)(v17874 - v17870) >> 31));
      v17873[v17958] = v17976;
      int * v17876 = v17840->cache_age;
      v17876[v17973] = 0;
      v17922 = v17973;
    } else {
      int * v17879 = v17840->cache_age;
      int v17980 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2);
      int v17880 = v17879[v17980];
      int * v17881 = v17840->cache_tags;
      int v17882 = v17881[v17980];
      int v17883 = v17879[v17958];
      int v17884 = v17881[v17958];
      int * v17885 = v17840->cache_dirty;
      int v17983 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v17880 + ((~(((v17882 ^ -1) | (-(v17882 ^ -1))) >> 31)) & 2)) - (v17883 + ((~(((v17884 ^ -1) | (-(v17884 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17886 = v17885[v17983];
      bool v17984 = !(v17886 == 0);
      if (v17984) {
        int * v17887 = v17840->cache_tags;
        int v17888 = v17887[v17983];
        int * v17889 = v17840->cache_vals;
        int v17987 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v17880 + ((~(((v17882 ^ -1) | (-(v17882 ^ -1))) >> 31)) & 2)) - (v17883 + ((~(((v17884 ^ -1) | (-(v17884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17890 = v17889[v17987];
        int v17988 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v17880 + ((~(((v17882 ^ -1) | (-(v17882 ^ -1))) >> 31)) & 2)) - (v17883 + ((~(((v17884 ^ -1) | (-(v17884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17891 = v17889[v17988];
        int * v17892 = v17840->mem;
        int v17990 = v17888 * 2;
        v17892[v17990] = v17890;
        int * v17894 = v17840->mem;
        int v17993 = (v17888 * 2) + 1;
        v17894[v17993] = v17891;
        ;
      } else {
        ;
      }
      int * v17899 = v17840->mem;
      int v17998 = ((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) * 2;
      int v17900 = v17899[v17998];
      int v17999 = (((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) * 2) + 1;
      int v17901 = v17899[v17999];
      int * v17902 = v17840->cache_vals;
      int v18001 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v17880 + ((~(((v17882 ^ -1) | (-(v17882 ^ -1))) >> 31)) & 2)) - (v17883 + ((~(((v17884 ^ -1) | (-(v17884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17902[v18001] = v17900;
      int * v17904 = v17840->cache_vals;
      int v18004 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v17880 + ((~(((v17882 ^ -1) | (-(v17882 ^ -1))) >> 31)) & 2)) - (v17883 + ((~(((v17884 ^ -1) | (-(v17884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17904[v18004] = v17901;
      int * v17906 = v17840->cache_tags;
      int v18007 = (int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1);
      v17906[v17983] = v18007;
      int * v17908 = v17840->cache_dirty;
      v17908[v17983] = 0;
      int * v17910 = v17840->cache_age;
      v17910[v17983] = 1;
      int * v17912 = v17840->cache_age;
      int v17913 = v17912[v17983];
      int v17914 = v17912[v17957];
      int v18013 = v17914 + ((int)((unsigned int)(v17914 - v17913) >> 31));
      v17912[v17957] = v18013;
      int * v17916 = v17840->cache_age;
      int v17917 = v17916[v17958];
      int v18015 = v17917 + ((int)((unsigned int)(v17917 - v17913) >> 31));
      v17916[v17958] = v18015;
      int * v17919 = v17840->cache_age;
      v17919[v17983] = 0;
      v17922 = v17983;
    }
    int * v17923 = v17840->cache_vals;
    int v18018 = v17922 * 2;
    int v17924 = v17923[v18018];
    int v18019 = (v17922 * 2) + 1;
    int v17925 = v17923[v18019];
    int v18020 = (((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2) + ((((v17864 + ((~(((v17866 ^ -1) | (-(v17866 ^ -1))) >> 31)) & 2)) - (v17867 + ((~(((v17868 ^ -1) | (-(v17868 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17923[v18020] = v17924;
    int * v17927 = v17840->cache_vals;
    int v18023 = ((((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2) + ((((v17864 + ((~(((v17866 ^ -1) | (-(v17866 ^ -1))) >> 31)) & 2)) - (v17867 + ((~(((v17868 ^ -1) | (-(v17868 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17927[v18023] = v17925;
    int * v17929 = v17840->cache_tags;
    int v18026 = ((((int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1)) & 1) * 2) + ((((v17864 + ((~(((v17866 ^ -1) | (-(v17866 ^ -1))) >> 31)) & 2)) - (v17867 + ((~(((v17868 ^ -1) | (-(v17868 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18027 = (int)((unsigned int)((int)((unsigned int)(v17844 + 88) >> 2)) >> 1);
    v17929[v18026] = v18027;
    int * v17931 = v17840->cache_dirty;
    v17931[v18026] = 0;
    int * v17933 = v17840->cache_age;
    v17933[v18026] = 1;
    int * v17935 = v17840->cache_age;
    int v17936 = v17935[v18026];
    int v17937 = v17935[v17955];
    int v18033 = v17937 + ((int)((unsigned int)(v17937 - v17936) >> 31));
    v17935[v17955] = v18033;
    int * v17939 = v17840->cache_age;
    int v17940 = v17939[v17956];
    int v18035 = v17940 + ((int)((unsigned int)(v17940 - v17936) >> 31));
    v17939[v17956] = v18035;
    int * v17942 = v17840->cache_age;
    v17942[v18026] = 0;
    v17945 = v18026;
  }
  int v18038 = (v17945 * 2) + (((int)((unsigned int)(v17844 + 88) >> 2)) & 1);
  int v17946 = v17852[v18038];
  int * v17947 = v17840->regs;
  v17947[8] = v17946;
  struct StateT * v17949 = slot_264(v17840);
  return v17949;
}

struct StateT * slot_161(struct StateT * v21252) {
  int v21253 = v21252->timer;
  int v21260 = v21253 + 1;
  v21252->timer = v21260;
  int * v21255 = v21252->regs;
  int v21256 = v21255[6];
  int v21264 = (int)((unsigned int)v21256 >> 23);
  v21255[9] = v21264;
  struct StateT * v21258 = slot_162(v21252);
  return v21258;
}

struct StateT * slot_185(struct StateT * v21624) {
  int v21625 = v21624->timer;
  int v21632 = v21625 + 1;
  v21624->timer = v21632;
  int * v21627 = v21624->regs;
  int v21628 = v21627[8];
  int v21635 = v21628 << 13;
  v21627[8] = v21635;
  struct StateT * v21630 = slot_186(v21624);
  return v21630;
}

struct StateT * slot_91(struct StateT * v14962) {
  int v14963 = v14962->timer;
  int v14971 = v14963 + 1;
  v14962->timer = v14971;
  int * v14965 = v14962->regs;
  int v14966 = v14965[26];
  int v14967 = v14965[12];
  int v14976 = v14966 + v14967;
  v14965[15] = v14976;
  struct StateT * v14969 = slot_92(v14962);
  return v14969;
}

struct StateT * slot_58(struct StateT * v10229) {
  int v10230 = v10229->timer;
  int v10237 = v10230 + 1;
  v10229->timer = v10237;
  int * v10232 = v10229->regs;
  int v10233 = v10232[20];
  int v10241 = (int)((unsigned int)v10233 >> 25);
  v10232[9] = v10241;
  struct StateT * v10235 = slot_59(v10229);
  return v10235;
}

struct StateT * slot_89(struct StateT * v14300) {
  int v14301 = v14300->timer;
  int v14309 = v14301 + 1;
  v14300->timer = v14309;
  int * v14303 = v14300->regs;
  int v14304 = v14303[27];
  int v14305 = v14303[9];
  int v14313 = v14304 ^ v14305;
  v14303[27] = v14313;
  struct StateT * v14307 = slot_90(v14300);
  return v14307;
}

struct StateT * slot_255(struct StateT * v15311) {
  int v15312 = v15311->timer;
  int v15482 = v15312 + 1;
  v15311->timer = v15482;
  int * v15314 = v15311->regs;
  int v15315 = v15314[10];
  int v15316 = v15314[13];
  int * v15317 = v15311->cache_tags;
  int v15487 = (((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2;
  int v15318 = v15317[v15487];
  int v15488 = ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15319 = v15317[v15488];
  int v15489 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2);
  int v15320 = v15317[v15489];
  int v15490 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15321 = v15317[v15490];
  int v15322 = v15311->timer;
  int v15491 = v15322 + ((100 ^ (((~(((v15320 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15320 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15318 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15318 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15319 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15319 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15320 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15320 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15311->timer = v15491;
  bool v15492 = !(((~(((v15318 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15318 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15319 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15319 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v15416;
  if (v15492) {
    int * v15324 = v15311->cache_age;
    int v15494 = ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v15319 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15319 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v15325 = v15324[v15494];
    int v15326 = v15324[v15487];
    int v15495 = v15326 + ((int)((unsigned int)(v15326 - v15325) >> 31));
    v15324[v15487] = v15495;
    int * v15328 = v15311->cache_age;
    int v15329 = v15328[v15488];
    int v15497 = v15329 + ((int)((unsigned int)(v15329 - v15325) >> 31));
    v15328[v15488] = v15497;
    int * v15331 = v15311->cache_age;
    v15331[v15494] = 0;
    v15416 = v15494;
  } else {
    int * v15334 = v15311->cache_age;
    int v15501 = (((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2;
    int v15335 = v15334[v15501];
    int * v15336 = v15311->cache_tags;
    int v15337 = v15336[v15501];
    int v15338 = v15334[v15488];
    int v15339 = v15336[v15488];
    bool v15503 = !(((~(((v15320 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15320 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v15393;
    if (v15503) {
      int * v15340 = v15311->cache_age;
      int v15505 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15321 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v15341 = v15340[v15505];
      int v15342 = v15340[v15489];
      int v15506 = v15342 + ((int)((unsigned int)(v15342 - v15341) >> 31));
      v15340[v15489] = v15506;
      int * v15344 = v15311->cache_age;
      int v15345 = v15344[v15490];
      int v15508 = v15345 + ((int)((unsigned int)(v15345 - v15341) >> 31));
      v15344[v15490] = v15508;
      int * v15347 = v15311->cache_age;
      v15347[v15505] = 0;
      v15393 = v15505;
    } else {
      int * v15350 = v15311->cache_age;
      int v15512 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2);
      int v15351 = v15350[v15512];
      int * v15352 = v15311->cache_tags;
      int v15353 = v15352[v15512];
      int v15354 = v15350[v15490];
      int v15355 = v15352[v15490];
      int * v15356 = v15311->cache_dirty;
      int v15515 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15351 + ((~(((v15353 ^ -1) | (-(v15353 ^ -1))) >> 31)) & 2)) - (v15354 + ((~(((v15355 ^ -1) | (-(v15355 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15357 = v15356[v15515];
      bool v15516 = !(v15357 == 0);
      if (v15516) {
        int * v15358 = v15311->cache_tags;
        int v15359 = v15358[v15515];
        int * v15360 = v15311->cache_vals;
        int v15519 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15351 + ((~(((v15353 ^ -1) | (-(v15353 ^ -1))) >> 31)) & 2)) - (v15354 + ((~(((v15355 ^ -1) | (-(v15355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15361 = v15360[v15519];
        int v15520 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15351 + ((~(((v15353 ^ -1) | (-(v15353 ^ -1))) >> 31)) & 2)) - (v15354 + ((~(((v15355 ^ -1) | (-(v15355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15362 = v15360[v15520];
        int * v15363 = v15311->mem;
        int v15522 = v15359 * 2;
        v15363[v15522] = v15361;
        int * v15365 = v15311->mem;
        int v15525 = (v15359 * 2) + 1;
        v15365[v15525] = v15362;
        ;
      } else {
        ;
      }
      int * v15370 = v15311->mem;
      int v15530 = ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) * 2;
      int v15371 = v15370[v15530];
      int v15531 = (((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) * 2) + 1;
      int v15372 = v15370[v15531];
      int * v15373 = v15311->cache_vals;
      int v15533 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15351 + ((~(((v15353 ^ -1) | (-(v15353 ^ -1))) >> 31)) & 2)) - (v15354 + ((~(((v15355 ^ -1) | (-(v15355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15373[v15533] = v15371;
      int * v15375 = v15311->cache_vals;
      int v15536 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15351 + ((~(((v15353 ^ -1) | (-(v15353 ^ -1))) >> 31)) & 2)) - (v15354 + ((~(((v15355 ^ -1) | (-(v15355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15375[v15536] = v15372;
      int * v15377 = v15311->cache_tags;
      int v15539 = (int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1);
      v15377[v15515] = v15539;
      int * v15379 = v15311->cache_dirty;
      v15379[v15515] = 0;
      int * v15381 = v15311->cache_age;
      v15381[v15515] = 1;
      int * v15383 = v15311->cache_age;
      int v15384 = v15383[v15515];
      int v15385 = v15383[v15489];
      int v15545 = v15385 + ((int)((unsigned int)(v15385 - v15384) >> 31));
      v15383[v15489] = v15545;
      int * v15387 = v15311->cache_age;
      int v15388 = v15387[v15490];
      int v15547 = v15388 + ((int)((unsigned int)(v15388 - v15384) >> 31));
      v15387[v15490] = v15547;
      int * v15390 = v15311->cache_age;
      v15390[v15515] = 0;
      v15393 = v15515;
    }
    int * v15394 = v15311->cache_vals;
    int v15550 = v15393 * 2;
    int v15395 = v15394[v15550];
    int v15551 = (v15393 * 2) + 1;
    int v15396 = v15394[v15551];
    int v15552 = (((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v15335 + ((~(((v15337 ^ -1) | (-(v15337 ^ -1))) >> 31)) & 2)) - (v15338 + ((~(((v15339 ^ -1) | (-(v15339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15394[v15552] = v15395;
    int * v15398 = v15311->cache_vals;
    int v15555 = ((((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v15335 + ((~(((v15337 ^ -1) | (-(v15337 ^ -1))) >> 31)) & 2)) - (v15338 + ((~(((v15339 ^ -1) | (-(v15339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15398[v15555] = v15396;
    int * v15400 = v15311->cache_tags;
    int v15558 = ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v15335 + ((~(((v15337 ^ -1) | (-(v15337 ^ -1))) >> 31)) & 2)) - (v15338 + ((~(((v15339 ^ -1) | (-(v15339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15559 = (int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1);
    v15400[v15558] = v15559;
    int * v15402 = v15311->cache_dirty;
    v15402[v15558] = 0;
    int * v15404 = v15311->cache_age;
    v15404[v15558] = 1;
    int * v15406 = v15311->cache_age;
    int v15407 = v15406[v15558];
    int v15408 = v15406[v15487];
    int v15565 = v15408 + ((int)((unsigned int)(v15408 - v15407) >> 31));
    v15406[v15487] = v15565;
    int * v15410 = v15311->cache_age;
    int v15411 = v15410[v15488];
    int v15567 = v15411 + ((int)((unsigned int)(v15411 - v15407) >> 31));
    v15410[v15488] = v15567;
    int * v15413 = v15311->cache_age;
    v15413[v15558] = 0;
    v15416 = v15558;
  }
  int * v15417 = v15311->cache_vals;
  int v15570 = (v15416 * 2) + (((int)((unsigned int)(v15315 + 36) >> 2)) & 1);
  v15417[v15570] = v15316;
  int * v15419 = v15311->cache_tags;
  int v15420 = v15419[v15489];
  int v15421 = v15419[v15490];
  bool v15573 = !(((~(((v15420 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15420 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v15421 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15421 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v15475;
  if (v15573) {
    int * v15422 = v15311->cache_age;
    int v15575 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15421 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))) | (-(v15421 ^ ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v15423 = v15422[v15575];
    int v15424 = v15422[v15489];
    int v15576 = v15424 + ((int)((unsigned int)(v15424 - v15423) >> 31));
    v15422[v15489] = v15576;
    int * v15426 = v15311->cache_age;
    int v15427 = v15426[v15490];
    int v15578 = v15427 + ((int)((unsigned int)(v15427 - v15423) >> 31));
    v15426[v15490] = v15578;
    int * v15429 = v15311->cache_age;
    v15429[v15575] = 0;
    v15475 = v15575;
  } else {
    int * v15432 = v15311->cache_age;
    int v15582 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2);
    int v15433 = v15432[v15582];
    int * v15434 = v15311->cache_tags;
    int v15435 = v15434[v15582];
    int v15436 = v15432[v15490];
    int v15437 = v15434[v15490];
    int * v15438 = v15311->cache_dirty;
    int v15585 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15433 + ((~(((v15435 ^ -1) | (-(v15435 ^ -1))) >> 31)) & 2)) - (v15436 + ((~(((v15437 ^ -1) | (-(v15437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15439 = v15438[v15585];
    bool v15586 = !(v15439 == 0);
    if (v15586) {
      int * v15440 = v15311->cache_tags;
      int v15441 = v15440[v15585];
      int * v15442 = v15311->cache_vals;
      int v15589 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15433 + ((~(((v15435 ^ -1) | (-(v15435 ^ -1))) >> 31)) & 2)) - (v15436 + ((~(((v15437 ^ -1) | (-(v15437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v15443 = v15442[v15589];
      int v15590 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15433 + ((~(((v15435 ^ -1) | (-(v15435 ^ -1))) >> 31)) & 2)) - (v15436 + ((~(((v15437 ^ -1) | (-(v15437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v15444 = v15442[v15590];
      int * v15445 = v15311->mem;
      int v15592 = v15441 * 2;
      v15445[v15592] = v15443;
      int * v15447 = v15311->mem;
      int v15595 = (v15441 * 2) + 1;
      v15447[v15595] = v15444;
      ;
    } else {
      ;
    }
    int * v15452 = v15311->mem;
    int v15600 = ((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) * 2;
    int v15453 = v15452[v15600];
    int v15601 = (((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) * 2) + 1;
    int v15454 = v15452[v15601];
    int * v15455 = v15311->cache_vals;
    int v15603 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15433 + ((~(((v15435 ^ -1) | (-(v15435 ^ -1))) >> 31)) & 2)) - (v15436 + ((~(((v15437 ^ -1) | (-(v15437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15455[v15603] = v15453;
    int * v15457 = v15311->cache_vals;
    int v15606 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15433 + ((~(((v15435 ^ -1) | (-(v15435 ^ -1))) >> 31)) & 2)) - (v15436 + ((~(((v15437 ^ -1) | (-(v15437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15457[v15606] = v15454;
    int * v15459 = v15311->cache_tags;
    int v15609 = (int)((unsigned int)((int)((unsigned int)(v15315 + 36) >> 2)) >> 1);
    v15459[v15585] = v15609;
    int * v15461 = v15311->cache_dirty;
    v15461[v15585] = 0;
    int * v15463 = v15311->cache_age;
    v15463[v15585] = 1;
    int * v15465 = v15311->cache_age;
    int v15466 = v15465[v15585];
    int v15467 = v15465[v15489];
    int v15615 = v15467 + ((int)((unsigned int)(v15467 - v15466) >> 31));
    v15465[v15489] = v15615;
    int * v15469 = v15311->cache_age;
    int v15470 = v15469[v15490];
    int v15617 = v15470 + ((int)((unsigned int)(v15470 - v15466) >> 31));
    v15469[v15490] = v15617;
    int * v15472 = v15311->cache_age;
    v15472[v15585] = 0;
    v15475 = v15585;
  }
  int * v15476 = v15311->cache_vals;
  int v15620 = (v15475 * 2) + (((int)((unsigned int)(v15315 + 36) >> 2)) & 1);
  v15476[v15620] = v15316;
  int * v15478 = v15311->cache_dirty;
  v15478[v15475] = 1;
  struct StateT * v15480 = slot_256(v15311);
  return v15480;
}

struct StateT * slot_66(struct StateT * v11037) {
  int v11038 = v11037->timer;
  int v11046 = v11038 + 1;
  v11037->timer = v11046;
  int * v11040 = v11037->regs;
  int v11041 = v11040[8];
  int v11042 = v11040[20];
  int v11050 = v11041 | v11042;
  v11040[8] = v11050;
  struct StateT * v11044 = slot_67(v11037);
  return v11044;
}

struct StateT * slot_140(struct StateT * v20920) {
  int v20921 = v20920->timer;
  int v20929 = v20921 + 1;
  v20920->timer = v20929;
  int * v20923 = v20920->regs;
  int v20924 = v20923[11];
  int v20925 = v20923[5];
  int v20933 = v20924 | v20925;
  v20923[11] = v20933;
  struct StateT * v20927 = slot_141(v20920);
  return v20927;
}

struct StateT * slot_265(struct StateT * v18277) {
  int v18278 = v18277->timer;
  int v18388 = v18278 + 1;
  v18277->timer = v18388;
  int * v18280 = v18277->regs;
  int v18281 = v18280[2];
  int * v18282 = v18277->cache_tags;
  int v18392 = (((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2;
  int v18283 = v18282[v18392];
  int v18393 = ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18284 = v18282[v18393];
  int v18394 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2);
  int v18285 = v18282[v18394];
  int v18395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18286 = v18282[v18395];
  int v18287 = v18277->timer;
  int v18396 = v18287 + ((100 ^ (((~(((v18285 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18285 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18283 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18283 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v18284 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18284 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18285 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18285 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18277->timer = v18396;
  int * v18289 = v18277->cache_vals;
  bool v18397 = !(((~(((v18283 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18283 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v18284 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18284 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31))) == 0);
  int v18382;
  if (v18397) {
    int * v18290 = v18277->cache_age;
    int v18399 = ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2) + ((~(((v18284 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18284 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) & 1);
    int v18291 = v18290[v18399];
    int v18292 = v18290[v18392];
    int v18400 = v18292 + ((int)((unsigned int)(v18292 - v18291) >> 31));
    v18290[v18392] = v18400;
    int * v18294 = v18277->cache_age;
    int v18295 = v18294[v18393];
    int v18402 = v18295 + ((int)((unsigned int)(v18295 - v18291) >> 31));
    v18294[v18393] = v18402;
    int * v18297 = v18277->cache_age;
    v18297[v18399] = 0;
    v18382 = v18399;
  } else {
    int * v18300 = v18277->cache_age;
    int v18406 = (((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2;
    int v18301 = v18300[v18406];
    int * v18302 = v18277->cache_tags;
    int v18303 = v18302[v18406];
    int v18304 = v18300[v18393];
    int v18305 = v18302[v18393];
    bool v18408 = !(((~(((v18285 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18285 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) | (~(((v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31))) == 0);
    int v18359;
    if (v18408) {
      int * v18306 = v18277->cache_age;
      int v18410 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))) | (-(v18286 ^ ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1))))) >> 31)) & 1);
      int v18307 = v18306[v18410];
      int v18308 = v18306[v18394];
      int v18411 = v18308 + ((int)((unsigned int)(v18308 - v18307) >> 31));
      v18306[v18394] = v18411;
      int * v18310 = v18277->cache_age;
      int v18311 = v18310[v18395];
      int v18413 = v18311 + ((int)((unsigned int)(v18311 - v18307) >> 31));
      v18310[v18395] = v18413;
      int * v18313 = v18277->cache_age;
      v18313[v18410] = 0;
      v18359 = v18410;
    } else {
      int * v18316 = v18277->cache_age;
      int v18417 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2);
      int v18317 = v18316[v18417];
      int * v18318 = v18277->cache_tags;
      int v18319 = v18318[v18417];
      int v18320 = v18316[v18395];
      int v18321 = v18318[v18395];
      int * v18322 = v18277->cache_dirty;
      int v18420 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v18317 + ((~(((v18319 ^ -1) | (-(v18319 ^ -1))) >> 31)) & 2)) - (v18320 + ((~(((v18321 ^ -1) | (-(v18321 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18323 = v18322[v18420];
      bool v18421 = !(v18323 == 0);
      if (v18421) {
        int * v18324 = v18277->cache_tags;
        int v18325 = v18324[v18420];
        int * v18326 = v18277->cache_vals;
        int v18424 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v18317 + ((~(((v18319 ^ -1) | (-(v18319 ^ -1))) >> 31)) & 2)) - (v18320 + ((~(((v18321 ^ -1) | (-(v18321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18327 = v18326[v18424];
        int v18425 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v18317 + ((~(((v18319 ^ -1) | (-(v18319 ^ -1))) >> 31)) & 2)) - (v18320 + ((~(((v18321 ^ -1) | (-(v18321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18328 = v18326[v18425];
        int * v18329 = v18277->mem;
        int v18427 = v18325 * 2;
        v18329[v18427] = v18327;
        int * v18331 = v18277->mem;
        int v18430 = (v18325 * 2) + 1;
        v18331[v18430] = v18328;
        ;
      } else {
        ;
      }
      int * v18336 = v18277->mem;
      int v18435 = ((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) * 2;
      int v18337 = v18336[v18435];
      int v18436 = (((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) * 2) + 1;
      int v18338 = v18336[v18436];
      int * v18339 = v18277->cache_vals;
      int v18438 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v18317 + ((~(((v18319 ^ -1) | (-(v18319 ^ -1))) >> 31)) & 2)) - (v18320 + ((~(((v18321 ^ -1) | (-(v18321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18339[v18438] = v18337;
      int * v18341 = v18277->cache_vals;
      int v18441 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 3) * 2)) + ((((v18317 + ((~(((v18319 ^ -1) | (-(v18319 ^ -1))) >> 31)) & 2)) - (v18320 + ((~(((v18321 ^ -1) | (-(v18321 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18341[v18441] = v18338;
      int * v18343 = v18277->cache_tags;
      int v18444 = (int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1);
      v18343[v18420] = v18444;
      int * v18345 = v18277->cache_dirty;
      v18345[v18420] = 0;
      int * v18347 = v18277->cache_age;
      v18347[v18420] = 1;
      int * v18349 = v18277->cache_age;
      int v18350 = v18349[v18420];
      int v18351 = v18349[v18394];
      int v18450 = v18351 + ((int)((unsigned int)(v18351 - v18350) >> 31));
      v18349[v18394] = v18450;
      int * v18353 = v18277->cache_age;
      int v18354 = v18353[v18395];
      int v18452 = v18354 + ((int)((unsigned int)(v18354 - v18350) >> 31));
      v18353[v18395] = v18452;
      int * v18356 = v18277->cache_age;
      v18356[v18420] = 0;
      v18359 = v18420;
    }
    int * v18360 = v18277->cache_vals;
    int v18455 = v18359 * 2;
    int v18361 = v18360[v18455];
    int v18456 = (v18359 * 2) + 1;
    int v18362 = v18360[v18456];
    int v18457 = (((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2) + ((((v18301 + ((~(((v18303 ^ -1) | (-(v18303 ^ -1))) >> 31)) & 2)) - (v18304 + ((~(((v18305 ^ -1) | (-(v18305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18360[v18457] = v18361;
    int * v18364 = v18277->cache_vals;
    int v18460 = ((((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2) + ((((v18301 + ((~(((v18303 ^ -1) | (-(v18303 ^ -1))) >> 31)) & 2)) - (v18304 + ((~(((v18305 ^ -1) | (-(v18305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18364[v18460] = v18362;
    int * v18366 = v18277->cache_tags;
    int v18463 = ((((int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1)) & 1) * 2) + ((((v18301 + ((~(((v18303 ^ -1) | (-(v18303 ^ -1))) >> 31)) & 2)) - (v18304 + ((~(((v18305 ^ -1) | (-(v18305 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18464 = (int)((unsigned int)((int)((unsigned int)(v18281 + 80) >> 2)) >> 1);
    v18366[v18463] = v18464;
    int * v18368 = v18277->cache_dirty;
    v18368[v18463] = 0;
    int * v18370 = v18277->cache_age;
    v18370[v18463] = 1;
    int * v18372 = v18277->cache_age;
    int v18373 = v18372[v18463];
    int v18374 = v18372[v18392];
    int v18470 = v18374 + ((int)((unsigned int)(v18374 - v18373) >> 31));
    v18372[v18392] = v18470;
    int * v18376 = v18277->cache_age;
    int v18377 = v18376[v18393];
    int v18472 = v18377 + ((int)((unsigned int)(v18377 - v18373) >> 31));
    v18376[v18393] = v18472;
    int * v18379 = v18277->cache_age;
    v18379[v18463] = 0;
    v18382 = v18463;
  }
  int v18475 = (v18382 * 2) + (((int)((unsigned int)(v18281 + 80) >> 2)) & 1);
  int v18383 = v18289[v18475];
  int * v18384 = v18277->regs;
  v18384[18] = v18383;
  struct StateT * v18386 = slot_266(v18277);
  return v18386;
}

struct StateT * slot_49(struct StateT * v9583) {
  int v9584 = v9583->timer;
  int v9591 = v9584 + 1;
  v9583->timer = v9591;
  int * v9586 = v9583->regs;
  int v9587 = v9586[15];
  v9586[13] = v9587;
  struct StateT * v9589 = slot_50(v9583);
  return v9589;
}

struct StateT * slot_216(struct StateT * v9714) {
  int v9715 = v9714->timer;
  int v9723 = v9715 + 1;
  v9714->timer = v9723;
  int * v9717 = v9714->regs;
  int v9718 = v9717[14];
  int v9719 = v9717[7];
  int v9727 = v9718 + v9719;
  v9717[14] = v9727;
  struct StateT * v9721 = slot_217(v9714);
  return v9721;
}

struct StateT * slot_50(struct StateT * v9598) {
  int v9599 = v9598->timer;
  int v9609 = v9599 + 1;
  v9598->timer = v9609;
  int * v9601 = v9598->regs;
  int v9602 = v9601[31];
  bool v9612 = (v9602 ^ -2147483648) < -2147483648;
  struct StateT * v9607;
  if (v9612) {
    struct StateT * v9603 = slot_213(v9598);
    v9607 = v9603;
  } else {
    struct StateT * v9605 = slot_51(v9598);
    v9607 = v9605;
  }
  return v9607;
}

struct StateT * slot_37(struct StateT * v7007) {
  int v7008 = v7007->timer;
  int v7178 = v7008 + 1;
  v7007->timer = v7178;
  int * v7010 = v7007->regs;
  int v7011 = v7010[2];
  int v7012 = v7010[25];
  int * v7013 = v7007->cache_tags;
  int v7183 = (((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2;
  int v7014 = v7013[v7183];
  int v7184 = ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7015 = v7013[v7184];
  int v7185 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2);
  int v7016 = v7013[v7185];
  int v7186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7017 = v7013[v7186];
  int v7018 = v7007->timer;
  int v7187 = v7018 + ((100 ^ (((~(((v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7007->timer = v7187;
  bool v7188 = !(((~(((v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v7112;
  if (v7188) {
    int * v7020 = v7007->cache_age;
    int v7190 = ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v7021 = v7020[v7190];
    int v7022 = v7020[v7183];
    int v7191 = v7022 + ((int)((unsigned int)(v7022 - v7021) >> 31));
    v7020[v7183] = v7191;
    int * v7024 = v7007->cache_age;
    int v7025 = v7024[v7184];
    int v7193 = v7025 + ((int)((unsigned int)(v7025 - v7021) >> 31));
    v7024[v7184] = v7193;
    int * v7027 = v7007->cache_age;
    v7027[v7190] = 0;
    v7112 = v7190;
  } else {
    int * v7030 = v7007->cache_age;
    int v7197 = (((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2;
    int v7031 = v7030[v7197];
    int * v7032 = v7007->cache_tags;
    int v7033 = v7032[v7197];
    int v7034 = v7030[v7184];
    int v7035 = v7032[v7184];
    bool v7199 = !(((~(((v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v7089;
    if (v7199) {
      int * v7036 = v7007->cache_age;
      int v7201 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v7037 = v7036[v7201];
      int v7038 = v7036[v7185];
      int v7202 = v7038 + ((int)((unsigned int)(v7038 - v7037) >> 31));
      v7036[v7185] = v7202;
      int * v7040 = v7007->cache_age;
      int v7041 = v7040[v7186];
      int v7204 = v7041 + ((int)((unsigned int)(v7041 - v7037) >> 31));
      v7040[v7186] = v7204;
      int * v7043 = v7007->cache_age;
      v7043[v7201] = 0;
      v7089 = v7201;
    } else {
      int * v7046 = v7007->cache_age;
      int v7208 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2);
      int v7047 = v7046[v7208];
      int * v7048 = v7007->cache_tags;
      int v7049 = v7048[v7208];
      int v7050 = v7046[v7186];
      int v7051 = v7048[v7186];
      int * v7052 = v7007->cache_dirty;
      int v7211 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7047 + ((~(((v7049 ^ -1) | (-(v7049 ^ -1))) >> 31)) & 2)) - (v7050 + ((~(((v7051 ^ -1) | (-(v7051 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7053 = v7052[v7211];
      bool v7212 = !(v7053 == 0);
      if (v7212) {
        int * v7054 = v7007->cache_tags;
        int v7055 = v7054[v7211];
        int * v7056 = v7007->cache_vals;
        int v7215 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7047 + ((~(((v7049 ^ -1) | (-(v7049 ^ -1))) >> 31)) & 2)) - (v7050 + ((~(((v7051 ^ -1) | (-(v7051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7057 = v7056[v7215];
        int v7216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7047 + ((~(((v7049 ^ -1) | (-(v7049 ^ -1))) >> 31)) & 2)) - (v7050 + ((~(((v7051 ^ -1) | (-(v7051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7058 = v7056[v7216];
        int * v7059 = v7007->mem;
        int v7218 = v7055 * 2;
        v7059[v7218] = v7057;
        int * v7061 = v7007->mem;
        int v7221 = (v7055 * 2) + 1;
        v7061[v7221] = v7058;
        ;
      } else {
        ;
      }
      int * v7066 = v7007->mem;
      int v7226 = ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) * 2;
      int v7067 = v7066[v7226];
      int v7227 = (((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) * 2) + 1;
      int v7068 = v7066[v7227];
      int * v7069 = v7007->cache_vals;
      int v7229 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7047 + ((~(((v7049 ^ -1) | (-(v7049 ^ -1))) >> 31)) & 2)) - (v7050 + ((~(((v7051 ^ -1) | (-(v7051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7069[v7229] = v7067;
      int * v7071 = v7007->cache_vals;
      int v7232 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7047 + ((~(((v7049 ^ -1) | (-(v7049 ^ -1))) >> 31)) & 2)) - (v7050 + ((~(((v7051 ^ -1) | (-(v7051 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7071[v7232] = v7068;
      int * v7073 = v7007->cache_tags;
      int v7235 = (int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1);
      v7073[v7211] = v7235;
      int * v7075 = v7007->cache_dirty;
      v7075[v7211] = 0;
      int * v7077 = v7007->cache_age;
      v7077[v7211] = 1;
      int * v7079 = v7007->cache_age;
      int v7080 = v7079[v7211];
      int v7081 = v7079[v7185];
      int v7241 = v7081 + ((int)((unsigned int)(v7081 - v7080) >> 31));
      v7079[v7185] = v7241;
      int * v7083 = v7007->cache_age;
      int v7084 = v7083[v7186];
      int v7243 = v7084 + ((int)((unsigned int)(v7084 - v7080) >> 31));
      v7083[v7186] = v7243;
      int * v7086 = v7007->cache_age;
      v7086[v7211] = 0;
      v7089 = v7211;
    }
    int * v7090 = v7007->cache_vals;
    int v7246 = v7089 * 2;
    int v7091 = v7090[v7246];
    int v7247 = (v7089 * 2) + 1;
    int v7092 = v7090[v7247];
    int v7248 = (((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v7031 + ((~(((v7033 ^ -1) | (-(v7033 ^ -1))) >> 31)) & 2)) - (v7034 + ((~(((v7035 ^ -1) | (-(v7035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7090[v7248] = v7091;
    int * v7094 = v7007->cache_vals;
    int v7251 = ((((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v7031 + ((~(((v7033 ^ -1) | (-(v7033 ^ -1))) >> 31)) & 2)) - (v7034 + ((~(((v7035 ^ -1) | (-(v7035 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7094[v7251] = v7092;
    int * v7096 = v7007->cache_tags;
    int v7254 = ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v7031 + ((~(((v7033 ^ -1) | (-(v7033 ^ -1))) >> 31)) & 2)) - (v7034 + ((~(((v7035 ^ -1) | (-(v7035 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7255 = (int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1);
    v7096[v7254] = v7255;
    int * v7098 = v7007->cache_dirty;
    v7098[v7254] = 0;
    int * v7100 = v7007->cache_age;
    v7100[v7254] = 1;
    int * v7102 = v7007->cache_age;
    int v7103 = v7102[v7254];
    int v7104 = v7102[v7183];
    int v7261 = v7104 + ((int)((unsigned int)(v7104 - v7103) >> 31));
    v7102[v7183] = v7261;
    int * v7106 = v7007->cache_age;
    int v7107 = v7106[v7184];
    int v7263 = v7107 + ((int)((unsigned int)(v7107 - v7103) >> 31));
    v7106[v7184] = v7263;
    int * v7109 = v7007->cache_age;
    v7109[v7254] = 0;
    v7112 = v7254;
  }
  int * v7113 = v7007->cache_vals;
  int v7266 = (v7112 * 2) + (((int)((unsigned int)(v7011 + 16) >> 2)) & 1);
  v7113[v7266] = v7012;
  int * v7115 = v7007->cache_tags;
  int v7116 = v7115[v7185];
  int v7117 = v7115[v7186];
  bool v7269 = !(((~(((v7116 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7116 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7117 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7117 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v7171;
  if (v7269) {
    int * v7118 = v7007->cache_age;
    int v7271 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7117 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))) | (-(v7117 ^ ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v7119 = v7118[v7271];
    int v7120 = v7118[v7185];
    int v7272 = v7120 + ((int)((unsigned int)(v7120 - v7119) >> 31));
    v7118[v7185] = v7272;
    int * v7122 = v7007->cache_age;
    int v7123 = v7122[v7186];
    int v7274 = v7123 + ((int)((unsigned int)(v7123 - v7119) >> 31));
    v7122[v7186] = v7274;
    int * v7125 = v7007->cache_age;
    v7125[v7271] = 0;
    v7171 = v7271;
  } else {
    int * v7128 = v7007->cache_age;
    int v7278 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2);
    int v7129 = v7128[v7278];
    int * v7130 = v7007->cache_tags;
    int v7131 = v7130[v7278];
    int v7132 = v7128[v7186];
    int v7133 = v7130[v7186];
    int * v7134 = v7007->cache_dirty;
    int v7281 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7129 + ((~(((v7131 ^ -1) | (-(v7131 ^ -1))) >> 31)) & 2)) - (v7132 + ((~(((v7133 ^ -1) | (-(v7133 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7135 = v7134[v7281];
    bool v7282 = !(v7135 == 0);
    if (v7282) {
      int * v7136 = v7007->cache_tags;
      int v7137 = v7136[v7281];
      int * v7138 = v7007->cache_vals;
      int v7285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7129 + ((~(((v7131 ^ -1) | (-(v7131 ^ -1))) >> 31)) & 2)) - (v7132 + ((~(((v7133 ^ -1) | (-(v7133 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7139 = v7138[v7285];
      int v7286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7129 + ((~(((v7131 ^ -1) | (-(v7131 ^ -1))) >> 31)) & 2)) - (v7132 + ((~(((v7133 ^ -1) | (-(v7133 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7140 = v7138[v7286];
      int * v7141 = v7007->mem;
      int v7288 = v7137 * 2;
      v7141[v7288] = v7139;
      int * v7143 = v7007->mem;
      int v7291 = (v7137 * 2) + 1;
      v7143[v7291] = v7140;
      ;
    } else {
      ;
    }
    int * v7148 = v7007->mem;
    int v7296 = ((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) * 2;
    int v7149 = v7148[v7296];
    int v7297 = (((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) * 2) + 1;
    int v7150 = v7148[v7297];
    int * v7151 = v7007->cache_vals;
    int v7299 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7129 + ((~(((v7131 ^ -1) | (-(v7131 ^ -1))) >> 31)) & 2)) - (v7132 + ((~(((v7133 ^ -1) | (-(v7133 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7151[v7299] = v7149;
    int * v7153 = v7007->cache_vals;
    int v7302 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7129 + ((~(((v7131 ^ -1) | (-(v7131 ^ -1))) >> 31)) & 2)) - (v7132 + ((~(((v7133 ^ -1) | (-(v7133 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7153[v7302] = v7150;
    int * v7155 = v7007->cache_tags;
    int v7305 = (int)((unsigned int)((int)((unsigned int)(v7011 + 16) >> 2)) >> 1);
    v7155[v7281] = v7305;
    int * v7157 = v7007->cache_dirty;
    v7157[v7281] = 0;
    int * v7159 = v7007->cache_age;
    v7159[v7281] = 1;
    int * v7161 = v7007->cache_age;
    int v7162 = v7161[v7281];
    int v7163 = v7161[v7185];
    int v7311 = v7163 + ((int)((unsigned int)(v7163 - v7162) >> 31));
    v7161[v7185] = v7311;
    int * v7165 = v7007->cache_age;
    int v7166 = v7165[v7186];
    int v7313 = v7166 + ((int)((unsigned int)(v7166 - v7162) >> 31));
    v7165[v7186] = v7313;
    int * v7168 = v7007->cache_age;
    v7168[v7281] = 0;
    v7171 = v7281;
  }
  int * v7172 = v7007->cache_vals;
  int v7316 = (v7171 * 2) + (((int)((unsigned int)(v7011 + 16) >> 2)) & 1);
  v7172[v7316] = v7012;
  int * v7174 = v7007->cache_dirty;
  v7174[v7171] = 1;
  struct StateT * v7176 = slot_38(v7007);
  return v7176;
}

struct StateT * slot_114(struct StateT * v20516) {
  int v20517 = v20516->timer;
  int v20525 = v20517 + 1;
  v20516->timer = v20525;
  int * v20519 = v20516->regs;
  int v20520 = v20519[8];
  int v20521 = v20519[25];
  int v20530 = v20520 + v20521;
  v20519[5] = v20530;
  struct StateT * v20523 = slot_115(v20516);
  return v20523;
}

struct StateT * slot_135(struct StateT * v20846) {
  int v20847 = v20846->timer;
  int v20854 = v20847 + 1;
  v20846->timer = v20854;
  int * v20849 = v20846->regs;
  int v20850 = v20849[15];
  int v20858 = (int)((unsigned int)v20850 >> 25);
  v20849[5] = v20858;
  struct StateT * v20852 = slot_136(v20846);
  return v20852;
}

struct StateT * slot_248(struct StateT * v12992) {
  int v12993 = v12992->timer;
  int v13163 = v12993 + 1;
  v12992->timer = v13163;
  int * v12995 = v12992->regs;
  int v12996 = v12995[10];
  int v12997 = v12995[28];
  int * v12998 = v12992->cache_tags;
  int v13168 = (((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2;
  int v12999 = v12998[v13168];
  int v13169 = ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13000 = v12998[v13169];
  int v13170 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2);
  int v13001 = v12998[v13170];
  int v13171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13002 = v12998[v13171];
  int v13003 = v12992->timer;
  int v13172 = v13003 + ((100 ^ (((~(((v13001 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13001 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12999 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v12999 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13000 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13000 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13001 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13001 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12992->timer = v13172;
  bool v13173 = !(((~(((v12999 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v12999 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13000 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13000 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v13097;
  if (v13173) {
    int * v13005 = v12992->cache_age;
    int v13175 = ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v13000 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13000 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v13006 = v13005[v13175];
    int v13007 = v13005[v13168];
    int v13176 = v13007 + ((int)((unsigned int)(v13007 - v13006) >> 31));
    v13005[v13168] = v13176;
    int * v13009 = v12992->cache_age;
    int v13010 = v13009[v13169];
    int v13178 = v13010 + ((int)((unsigned int)(v13010 - v13006) >> 31));
    v13009[v13169] = v13178;
    int * v13012 = v12992->cache_age;
    v13012[v13175] = 0;
    v13097 = v13175;
  } else {
    int * v13015 = v12992->cache_age;
    int v13182 = (((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2;
    int v13016 = v13015[v13182];
    int * v13017 = v12992->cache_tags;
    int v13018 = v13017[v13182];
    int v13019 = v13015[v13169];
    int v13020 = v13017[v13169];
    bool v13184 = !(((~(((v13001 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13001 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v13074;
    if (v13184) {
      int * v13021 = v12992->cache_age;
      int v13186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13002 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v13022 = v13021[v13186];
      int v13023 = v13021[v13170];
      int v13187 = v13023 + ((int)((unsigned int)(v13023 - v13022) >> 31));
      v13021[v13170] = v13187;
      int * v13025 = v12992->cache_age;
      int v13026 = v13025[v13171];
      int v13189 = v13026 + ((int)((unsigned int)(v13026 - v13022) >> 31));
      v13025[v13171] = v13189;
      int * v13028 = v12992->cache_age;
      v13028[v13186] = 0;
      v13074 = v13186;
    } else {
      int * v13031 = v12992->cache_age;
      int v13193 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2);
      int v13032 = v13031[v13193];
      int * v13033 = v12992->cache_tags;
      int v13034 = v13033[v13193];
      int v13035 = v13031[v13171];
      int v13036 = v13033[v13171];
      int * v13037 = v12992->cache_dirty;
      int v13196 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13032 + ((~(((v13034 ^ -1) | (-(v13034 ^ -1))) >> 31)) & 2)) - (v13035 + ((~(((v13036 ^ -1) | (-(v13036 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13038 = v13037[v13196];
      bool v13197 = !(v13038 == 0);
      if (v13197) {
        int * v13039 = v12992->cache_tags;
        int v13040 = v13039[v13196];
        int * v13041 = v12992->cache_vals;
        int v13200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13032 + ((~(((v13034 ^ -1) | (-(v13034 ^ -1))) >> 31)) & 2)) - (v13035 + ((~(((v13036 ^ -1) | (-(v13036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13042 = v13041[v13200];
        int v13201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13032 + ((~(((v13034 ^ -1) | (-(v13034 ^ -1))) >> 31)) & 2)) - (v13035 + ((~(((v13036 ^ -1) | (-(v13036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13043 = v13041[v13201];
        int * v13044 = v12992->mem;
        int v13203 = v13040 * 2;
        v13044[v13203] = v13042;
        int * v13046 = v12992->mem;
        int v13206 = (v13040 * 2) + 1;
        v13046[v13206] = v13043;
        ;
      } else {
        ;
      }
      int * v13051 = v12992->mem;
      int v13211 = ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) * 2;
      int v13052 = v13051[v13211];
      int v13212 = (((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) * 2) + 1;
      int v13053 = v13051[v13212];
      int * v13054 = v12992->cache_vals;
      int v13214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13032 + ((~(((v13034 ^ -1) | (-(v13034 ^ -1))) >> 31)) & 2)) - (v13035 + ((~(((v13036 ^ -1) | (-(v13036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13054[v13214] = v13052;
      int * v13056 = v12992->cache_vals;
      int v13217 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13032 + ((~(((v13034 ^ -1) | (-(v13034 ^ -1))) >> 31)) & 2)) - (v13035 + ((~(((v13036 ^ -1) | (-(v13036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13056[v13217] = v13053;
      int * v13058 = v12992->cache_tags;
      int v13220 = (int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1);
      v13058[v13196] = v13220;
      int * v13060 = v12992->cache_dirty;
      v13060[v13196] = 0;
      int * v13062 = v12992->cache_age;
      v13062[v13196] = 1;
      int * v13064 = v12992->cache_age;
      int v13065 = v13064[v13196];
      int v13066 = v13064[v13170];
      int v13226 = v13066 + ((int)((unsigned int)(v13066 - v13065) >> 31));
      v13064[v13170] = v13226;
      int * v13068 = v12992->cache_age;
      int v13069 = v13068[v13171];
      int v13228 = v13069 + ((int)((unsigned int)(v13069 - v13065) >> 31));
      v13068[v13171] = v13228;
      int * v13071 = v12992->cache_age;
      v13071[v13196] = 0;
      v13074 = v13196;
    }
    int * v13075 = v12992->cache_vals;
    int v13231 = v13074 * 2;
    int v13076 = v13075[v13231];
    int v13232 = (v13074 * 2) + 1;
    int v13077 = v13075[v13232];
    int v13233 = (((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v13016 + ((~(((v13018 ^ -1) | (-(v13018 ^ -1))) >> 31)) & 2)) - (v13019 + ((~(((v13020 ^ -1) | (-(v13020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13075[v13233] = v13076;
    int * v13079 = v12992->cache_vals;
    int v13236 = ((((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v13016 + ((~(((v13018 ^ -1) | (-(v13018 ^ -1))) >> 31)) & 2)) - (v13019 + ((~(((v13020 ^ -1) | (-(v13020 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13079[v13236] = v13077;
    int * v13081 = v12992->cache_tags;
    int v13239 = ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v13016 + ((~(((v13018 ^ -1) | (-(v13018 ^ -1))) >> 31)) & 2)) - (v13019 + ((~(((v13020 ^ -1) | (-(v13020 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13240 = (int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1);
    v13081[v13239] = v13240;
    int * v13083 = v12992->cache_dirty;
    v13083[v13239] = 0;
    int * v13085 = v12992->cache_age;
    v13085[v13239] = 1;
    int * v13087 = v12992->cache_age;
    int v13088 = v13087[v13239];
    int v13089 = v13087[v13168];
    int v13246 = v13089 + ((int)((unsigned int)(v13089 - v13088) >> 31));
    v13087[v13168] = v13246;
    int * v13091 = v12992->cache_age;
    int v13092 = v13091[v13169];
    int v13248 = v13092 + ((int)((unsigned int)(v13092 - v13088) >> 31));
    v13091[v13169] = v13248;
    int * v13094 = v12992->cache_age;
    v13094[v13239] = 0;
    v13097 = v13239;
  }
  int * v13098 = v12992->cache_vals;
  int v13251 = (v13097 * 2) + (((int)((unsigned int)(v12996 + 8) >> 2)) & 1);
  v13098[v13251] = v12997;
  int * v13100 = v12992->cache_tags;
  int v13101 = v13100[v13170];
  int v13102 = v13100[v13171];
  bool v13254 = !(((~(((v13101 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13101 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v13102 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13102 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v13156;
  if (v13254) {
    int * v13103 = v12992->cache_age;
    int v13256 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13102 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))) | (-(v13102 ^ ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v13104 = v13103[v13256];
    int v13105 = v13103[v13170];
    int v13257 = v13105 + ((int)((unsigned int)(v13105 - v13104) >> 31));
    v13103[v13170] = v13257;
    int * v13107 = v12992->cache_age;
    int v13108 = v13107[v13171];
    int v13259 = v13108 + ((int)((unsigned int)(v13108 - v13104) >> 31));
    v13107[v13171] = v13259;
    int * v13110 = v12992->cache_age;
    v13110[v13256] = 0;
    v13156 = v13256;
  } else {
    int * v13113 = v12992->cache_age;
    int v13263 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2);
    int v13114 = v13113[v13263];
    int * v13115 = v12992->cache_tags;
    int v13116 = v13115[v13263];
    int v13117 = v13113[v13171];
    int v13118 = v13115[v13171];
    int * v13119 = v12992->cache_dirty;
    int v13266 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13114 + ((~(((v13116 ^ -1) | (-(v13116 ^ -1))) >> 31)) & 2)) - (v13117 + ((~(((v13118 ^ -1) | (-(v13118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13120 = v13119[v13266];
    bool v13267 = !(v13120 == 0);
    if (v13267) {
      int * v13121 = v12992->cache_tags;
      int v13122 = v13121[v13266];
      int * v13123 = v12992->cache_vals;
      int v13270 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13114 + ((~(((v13116 ^ -1) | (-(v13116 ^ -1))) >> 31)) & 2)) - (v13117 + ((~(((v13118 ^ -1) | (-(v13118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v13124 = v13123[v13270];
      int v13271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13114 + ((~(((v13116 ^ -1) | (-(v13116 ^ -1))) >> 31)) & 2)) - (v13117 + ((~(((v13118 ^ -1) | (-(v13118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v13125 = v13123[v13271];
      int * v13126 = v12992->mem;
      int v13273 = v13122 * 2;
      v13126[v13273] = v13124;
      int * v13128 = v12992->mem;
      int v13276 = (v13122 * 2) + 1;
      v13128[v13276] = v13125;
      ;
    } else {
      ;
    }
    int * v13133 = v12992->mem;
    int v13281 = ((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) * 2;
    int v13134 = v13133[v13281];
    int v13282 = (((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) * 2) + 1;
    int v13135 = v13133[v13282];
    int * v13136 = v12992->cache_vals;
    int v13284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13114 + ((~(((v13116 ^ -1) | (-(v13116 ^ -1))) >> 31)) & 2)) - (v13117 + ((~(((v13118 ^ -1) | (-(v13118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13136[v13284] = v13134;
    int * v13138 = v12992->cache_vals;
    int v13287 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v13114 + ((~(((v13116 ^ -1) | (-(v13116 ^ -1))) >> 31)) & 2)) - (v13117 + ((~(((v13118 ^ -1) | (-(v13118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13138[v13287] = v13135;
    int * v13140 = v12992->cache_tags;
    int v13290 = (int)((unsigned int)((int)((unsigned int)(v12996 + 8) >> 2)) >> 1);
    v13140[v13266] = v13290;
    int * v13142 = v12992->cache_dirty;
    v13142[v13266] = 0;
    int * v13144 = v12992->cache_age;
    v13144[v13266] = 1;
    int * v13146 = v12992->cache_age;
    int v13147 = v13146[v13266];
    int v13148 = v13146[v13170];
    int v13296 = v13148 + ((int)((unsigned int)(v13148 - v13147) >> 31));
    v13146[v13170] = v13296;
    int * v13150 = v12992->cache_age;
    int v13151 = v13150[v13171];
    int v13298 = v13151 + ((int)((unsigned int)(v13151 - v13147) >> 31));
    v13150[v13171] = v13298;
    int * v13153 = v12992->cache_age;
    v13153[v13266] = 0;
    v13156 = v13266;
  }
  int * v13157 = v12992->cache_vals;
  int v13301 = (v13156 * 2) + (((int)((unsigned int)(v12996 + 8) >> 2)) & 1);
  v13157[v13301] = v12997;
  int * v13159 = v12992->cache_dirty;
  v13159[v13156] = 1;
  struct StateT * v13161 = slot_249(v12992);
  return v13161;
}

struct StateT * slot_257(struct StateT * v15975) {
  int v15976 = v15975->timer;
  int v16146 = v15976 + 1;
  v15975->timer = v16146;
  int * v15978 = v15975->regs;
  int v15979 = v15978[10];
  int v15980 = v15978[17];
  int * v15981 = v15975->cache_tags;
  int v16151 = (((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2;
  int v15982 = v15981[v16151];
  int v16152 = ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15983 = v15981[v16152];
  int v16153 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2);
  int v15984 = v15981[v16153];
  int v16154 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15985 = v15981[v16154];
  int v15986 = v15975->timer;
  int v16155 = v15986 + ((100 ^ (((~(((v15984 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15984 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15982 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15982 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15983 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15983 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15984 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15984 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15975->timer = v16155;
  bool v16156 = !(((~(((v15982 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15982 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15983 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15983 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v16080;
  if (v16156) {
    int * v15988 = v15975->cache_age;
    int v16158 = ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v15983 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15983 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v15989 = v15988[v16158];
    int v15990 = v15988[v16151];
    int v16159 = v15990 + ((int)((unsigned int)(v15990 - v15989) >> 31));
    v15988[v16151] = v16159;
    int * v15992 = v15975->cache_age;
    int v15993 = v15992[v16152];
    int v16161 = v15993 + ((int)((unsigned int)(v15993 - v15989) >> 31));
    v15992[v16152] = v16161;
    int * v15995 = v15975->cache_age;
    v15995[v16158] = 0;
    v16080 = v16158;
  } else {
    int * v15998 = v15975->cache_age;
    int v16165 = (((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2;
    int v15999 = v15998[v16165];
    int * v16000 = v15975->cache_tags;
    int v16001 = v16000[v16165];
    int v16002 = v15998[v16152];
    int v16003 = v16000[v16152];
    bool v16167 = !(((~(((v15984 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15984 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v16057;
    if (v16167) {
      int * v16004 = v15975->cache_age;
      int v16169 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v15985 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v16005 = v16004[v16169];
      int v16006 = v16004[v16153];
      int v16170 = v16006 + ((int)((unsigned int)(v16006 - v16005) >> 31));
      v16004[v16153] = v16170;
      int * v16008 = v15975->cache_age;
      int v16009 = v16008[v16154];
      int v16172 = v16009 + ((int)((unsigned int)(v16009 - v16005) >> 31));
      v16008[v16154] = v16172;
      int * v16011 = v15975->cache_age;
      v16011[v16169] = 0;
      v16057 = v16169;
    } else {
      int * v16014 = v15975->cache_age;
      int v16176 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2);
      int v16015 = v16014[v16176];
      int * v16016 = v15975->cache_tags;
      int v16017 = v16016[v16176];
      int v16018 = v16014[v16154];
      int v16019 = v16016[v16154];
      int * v16020 = v15975->cache_dirty;
      int v16179 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16015 + ((~(((v16017 ^ -1) | (-(v16017 ^ -1))) >> 31)) & 2)) - (v16018 + ((~(((v16019 ^ -1) | (-(v16019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16021 = v16020[v16179];
      bool v16180 = !(v16021 == 0);
      if (v16180) {
        int * v16022 = v15975->cache_tags;
        int v16023 = v16022[v16179];
        int * v16024 = v15975->cache_vals;
        int v16183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16015 + ((~(((v16017 ^ -1) | (-(v16017 ^ -1))) >> 31)) & 2)) - (v16018 + ((~(((v16019 ^ -1) | (-(v16019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16025 = v16024[v16183];
        int v16184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16015 + ((~(((v16017 ^ -1) | (-(v16017 ^ -1))) >> 31)) & 2)) - (v16018 + ((~(((v16019 ^ -1) | (-(v16019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16026 = v16024[v16184];
        int * v16027 = v15975->mem;
        int v16186 = v16023 * 2;
        v16027[v16186] = v16025;
        int * v16029 = v15975->mem;
        int v16189 = (v16023 * 2) + 1;
        v16029[v16189] = v16026;
        ;
      } else {
        ;
      }
      int * v16034 = v15975->mem;
      int v16194 = ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) * 2;
      int v16035 = v16034[v16194];
      int v16195 = (((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) * 2) + 1;
      int v16036 = v16034[v16195];
      int * v16037 = v15975->cache_vals;
      int v16197 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16015 + ((~(((v16017 ^ -1) | (-(v16017 ^ -1))) >> 31)) & 2)) - (v16018 + ((~(((v16019 ^ -1) | (-(v16019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16037[v16197] = v16035;
      int * v16039 = v15975->cache_vals;
      int v16200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16015 + ((~(((v16017 ^ -1) | (-(v16017 ^ -1))) >> 31)) & 2)) - (v16018 + ((~(((v16019 ^ -1) | (-(v16019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16039[v16200] = v16036;
      int * v16041 = v15975->cache_tags;
      int v16203 = (int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1);
      v16041[v16179] = v16203;
      int * v16043 = v15975->cache_dirty;
      v16043[v16179] = 0;
      int * v16045 = v15975->cache_age;
      v16045[v16179] = 1;
      int * v16047 = v15975->cache_age;
      int v16048 = v16047[v16179];
      int v16049 = v16047[v16153];
      int v16209 = v16049 + ((int)((unsigned int)(v16049 - v16048) >> 31));
      v16047[v16153] = v16209;
      int * v16051 = v15975->cache_age;
      int v16052 = v16051[v16154];
      int v16211 = v16052 + ((int)((unsigned int)(v16052 - v16048) >> 31));
      v16051[v16154] = v16211;
      int * v16054 = v15975->cache_age;
      v16054[v16179] = 0;
      v16057 = v16179;
    }
    int * v16058 = v15975->cache_vals;
    int v16214 = v16057 * 2;
    int v16059 = v16058[v16214];
    int v16215 = (v16057 * 2) + 1;
    int v16060 = v16058[v16215];
    int v16216 = (((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v15999 + ((~(((v16001 ^ -1) | (-(v16001 ^ -1))) >> 31)) & 2)) - (v16002 + ((~(((v16003 ^ -1) | (-(v16003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16058[v16216] = v16059;
    int * v16062 = v15975->cache_vals;
    int v16219 = ((((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v15999 + ((~(((v16001 ^ -1) | (-(v16001 ^ -1))) >> 31)) & 2)) - (v16002 + ((~(((v16003 ^ -1) | (-(v16003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16062[v16219] = v16060;
    int * v16064 = v15975->cache_tags;
    int v16222 = ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v15999 + ((~(((v16001 ^ -1) | (-(v16001 ^ -1))) >> 31)) & 2)) - (v16002 + ((~(((v16003 ^ -1) | (-(v16003 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16223 = (int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1);
    v16064[v16222] = v16223;
    int * v16066 = v15975->cache_dirty;
    v16066[v16222] = 0;
    int * v16068 = v15975->cache_age;
    v16068[v16222] = 1;
    int * v16070 = v15975->cache_age;
    int v16071 = v16070[v16222];
    int v16072 = v16070[v16151];
    int v16229 = v16072 + ((int)((unsigned int)(v16072 - v16071) >> 31));
    v16070[v16151] = v16229;
    int * v16074 = v15975->cache_age;
    int v16075 = v16074[v16152];
    int v16231 = v16075 + ((int)((unsigned int)(v16075 - v16071) >> 31));
    v16074[v16152] = v16231;
    int * v16077 = v15975->cache_age;
    v16077[v16222] = 0;
    v16080 = v16222;
  }
  int * v16081 = v15975->cache_vals;
  int v16234 = (v16080 * 2) + (((int)((unsigned int)(v15979 + 44) >> 2)) & 1);
  v16081[v16234] = v15980;
  int * v16083 = v15975->cache_tags;
  int v16084 = v16083[v16153];
  int v16085 = v16083[v16154];
  bool v16237 = !(((~(((v16084 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v16084 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v16085 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v16085 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v16139;
  if (v16237) {
    int * v16086 = v15975->cache_age;
    int v16239 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16085 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))) | (-(v16085 ^ ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v16087 = v16086[v16239];
    int v16088 = v16086[v16153];
    int v16240 = v16088 + ((int)((unsigned int)(v16088 - v16087) >> 31));
    v16086[v16153] = v16240;
    int * v16090 = v15975->cache_age;
    int v16091 = v16090[v16154];
    int v16242 = v16091 + ((int)((unsigned int)(v16091 - v16087) >> 31));
    v16090[v16154] = v16242;
    int * v16093 = v15975->cache_age;
    v16093[v16239] = 0;
    v16139 = v16239;
  } else {
    int * v16096 = v15975->cache_age;
    int v16246 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2);
    int v16097 = v16096[v16246];
    int * v16098 = v15975->cache_tags;
    int v16099 = v16098[v16246];
    int v16100 = v16096[v16154];
    int v16101 = v16098[v16154];
    int * v16102 = v15975->cache_dirty;
    int v16249 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16097 + ((~(((v16099 ^ -1) | (-(v16099 ^ -1))) >> 31)) & 2)) - (v16100 + ((~(((v16101 ^ -1) | (-(v16101 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16103 = v16102[v16249];
    bool v16250 = !(v16103 == 0);
    if (v16250) {
      int * v16104 = v15975->cache_tags;
      int v16105 = v16104[v16249];
      int * v16106 = v15975->cache_vals;
      int v16253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16097 + ((~(((v16099 ^ -1) | (-(v16099 ^ -1))) >> 31)) & 2)) - (v16100 + ((~(((v16101 ^ -1) | (-(v16101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v16107 = v16106[v16253];
      int v16254 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16097 + ((~(((v16099 ^ -1) | (-(v16099 ^ -1))) >> 31)) & 2)) - (v16100 + ((~(((v16101 ^ -1) | (-(v16101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v16108 = v16106[v16254];
      int * v16109 = v15975->mem;
      int v16256 = v16105 * 2;
      v16109[v16256] = v16107;
      int * v16111 = v15975->mem;
      int v16259 = (v16105 * 2) + 1;
      v16111[v16259] = v16108;
      ;
    } else {
      ;
    }
    int * v16116 = v15975->mem;
    int v16264 = ((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) * 2;
    int v16117 = v16116[v16264];
    int v16265 = (((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) * 2) + 1;
    int v16118 = v16116[v16265];
    int * v16119 = v15975->cache_vals;
    int v16267 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16097 + ((~(((v16099 ^ -1) | (-(v16099 ^ -1))) >> 31)) & 2)) - (v16100 + ((~(((v16101 ^ -1) | (-(v16101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16119[v16267] = v16117;
    int * v16121 = v15975->cache_vals;
    int v16270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v16097 + ((~(((v16099 ^ -1) | (-(v16099 ^ -1))) >> 31)) & 2)) - (v16100 + ((~(((v16101 ^ -1) | (-(v16101 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16121[v16270] = v16118;
    int * v16123 = v15975->cache_tags;
    int v16273 = (int)((unsigned int)((int)((unsigned int)(v15979 + 44) >> 2)) >> 1);
    v16123[v16249] = v16273;
    int * v16125 = v15975->cache_dirty;
    v16125[v16249] = 0;
    int * v16127 = v15975->cache_age;
    v16127[v16249] = 1;
    int * v16129 = v15975->cache_age;
    int v16130 = v16129[v16249];
    int v16131 = v16129[v16153];
    int v16279 = v16131 + ((int)((unsigned int)(v16131 - v16130) >> 31));
    v16129[v16153] = v16279;
    int * v16133 = v15975->cache_age;
    int v16134 = v16133[v16154];
    int v16281 = v16134 + ((int)((unsigned int)(v16134 - v16130) >> 31));
    v16133[v16154] = v16281;
    int * v16136 = v15975->cache_age;
    v16136[v16249] = 0;
    v16139 = v16249;
  }
  int * v16140 = v15975->cache_vals;
  int v16284 = (v16139 * 2) + (((int)((unsigned int)(v15979 + 44) >> 2)) & 1);
  v16140[v16284] = v15980;
  int * v16142 = v15975->cache_dirty;
  v16142[v16139] = 1;
  struct StateT * v16144 = slot_258(v15975);
  return v16144;
}

struct StateT * slot_59(struct StateT * v10260) {
  int v10261 = v10260->timer;
  int v10268 = v10261 + 1;
  v10260->timer = v10268;
  int * v10263 = v10260->regs;
  int v10264 = v10263[20];
  int v10271 = v10264 << 7;
  v10263[20] = v10271;
  struct StateT * v10266 = slot_60(v10260);
  return v10266;
}

struct StateT * slot_192(struct StateT * v21735) {
  int v21736 = v21735->timer;
  int v21744 = v21736 + 1;
  v21735->timer = v21744;
  int * v21738 = v21735->regs;
  int v21739 = v21738[12];
  int v21740 = v21738[25];
  int v21749 = v21739 + v21740;
  v21738[15] = v21749;
  struct StateT * v21742 = slot_193(v21735);
  return v21742;
}

struct StateT * slot_40(struct StateT * v7948) {
  int v7949 = v7948->timer;
  int v8119 = v7949 + 1;
  v7948->timer = v8119;
  int * v7951 = v7948->regs;
  int v7952 = v7951[2];
  int v7953 = v7951[24];
  int * v7954 = v7948->cache_tags;
  int v8124 = (((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2;
  int v7955 = v7954[v8124];
  int v8125 = ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7956 = v7954[v8125];
  int v8126 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2);
  int v7957 = v7954[v8126];
  int v8127 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7958 = v7954[v8127];
  int v7959 = v7948->timer;
  int v8128 = v7959 + ((100 ^ (((~(((v7957 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7957 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7955 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7955 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7956 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7956 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7957 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7957 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7948->timer = v8128;
  bool v8129 = !(((~(((v7955 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7955 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7956 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7956 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v8053;
  if (v8129) {
    int * v7961 = v7948->cache_age;
    int v8131 = ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v7956 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7956 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7962 = v7961[v8131];
    int v7963 = v7961[v8124];
    int v8132 = v7963 + ((int)((unsigned int)(v7963 - v7962) >> 31));
    v7961[v8124] = v8132;
    int * v7965 = v7948->cache_age;
    int v7966 = v7965[v8125];
    int v8134 = v7966 + ((int)((unsigned int)(v7966 - v7962) >> 31));
    v7965[v8125] = v8134;
    int * v7968 = v7948->cache_age;
    v7968[v8131] = 0;
    v8053 = v8131;
  } else {
    int * v7971 = v7948->cache_age;
    int v8138 = (((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2;
    int v7972 = v7971[v8138];
    int * v7973 = v7948->cache_tags;
    int v7974 = v7973[v8138];
    int v7975 = v7971[v8125];
    int v7976 = v7973[v8125];
    bool v8140 = !(((~(((v7957 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7957 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v8030;
    if (v8140) {
      int * v7977 = v7948->cache_age;
      int v8142 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v7958 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v7978 = v7977[v8142];
      int v7979 = v7977[v8126];
      int v8143 = v7979 + ((int)((unsigned int)(v7979 - v7978) >> 31));
      v7977[v8126] = v8143;
      int * v7981 = v7948->cache_age;
      int v7982 = v7981[v8127];
      int v8145 = v7982 + ((int)((unsigned int)(v7982 - v7978) >> 31));
      v7981[v8127] = v8145;
      int * v7984 = v7948->cache_age;
      v7984[v8142] = 0;
      v8030 = v8142;
    } else {
      int * v7987 = v7948->cache_age;
      int v8149 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2);
      int v7988 = v7987[v8149];
      int * v7989 = v7948->cache_tags;
      int v7990 = v7989[v8149];
      int v7991 = v7987[v8127];
      int v7992 = v7989[v8127];
      int * v7993 = v7948->cache_dirty;
      int v8152 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7988 + ((~(((v7990 ^ -1) | (-(v7990 ^ -1))) >> 31)) & 2)) - (v7991 + ((~(((v7992 ^ -1) | (-(v7992 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7994 = v7993[v8152];
      bool v8153 = !(v7994 == 0);
      if (v8153) {
        int * v7995 = v7948->cache_tags;
        int v7996 = v7995[v8152];
        int * v7997 = v7948->cache_vals;
        int v8156 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7988 + ((~(((v7990 ^ -1) | (-(v7990 ^ -1))) >> 31)) & 2)) - (v7991 + ((~(((v7992 ^ -1) | (-(v7992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7998 = v7997[v8156];
        int v8157 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7988 + ((~(((v7990 ^ -1) | (-(v7990 ^ -1))) >> 31)) & 2)) - (v7991 + ((~(((v7992 ^ -1) | (-(v7992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7999 = v7997[v8157];
        int * v8000 = v7948->mem;
        int v8159 = v7996 * 2;
        v8000[v8159] = v7998;
        int * v8002 = v7948->mem;
        int v8162 = (v7996 * 2) + 1;
        v8002[v8162] = v7999;
        ;
      } else {
        ;
      }
      int * v8007 = v7948->mem;
      int v8167 = ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) * 2;
      int v8008 = v8007[v8167];
      int v8168 = (((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) * 2) + 1;
      int v8009 = v8007[v8168];
      int * v8010 = v7948->cache_vals;
      int v8170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7988 + ((~(((v7990 ^ -1) | (-(v7990 ^ -1))) >> 31)) & 2)) - (v7991 + ((~(((v7992 ^ -1) | (-(v7992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8010[v8170] = v8008;
      int * v8012 = v7948->cache_vals;
      int v8173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7988 + ((~(((v7990 ^ -1) | (-(v7990 ^ -1))) >> 31)) & 2)) - (v7991 + ((~(((v7992 ^ -1) | (-(v7992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8012[v8173] = v8009;
      int * v8014 = v7948->cache_tags;
      int v8176 = (int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1);
      v8014[v8152] = v8176;
      int * v8016 = v7948->cache_dirty;
      v8016[v8152] = 0;
      int * v8018 = v7948->cache_age;
      v8018[v8152] = 1;
      int * v8020 = v7948->cache_age;
      int v8021 = v8020[v8152];
      int v8022 = v8020[v8126];
      int v8182 = v8022 + ((int)((unsigned int)(v8022 - v8021) >> 31));
      v8020[v8126] = v8182;
      int * v8024 = v7948->cache_age;
      int v8025 = v8024[v8127];
      int v8184 = v8025 + ((int)((unsigned int)(v8025 - v8021) >> 31));
      v8024[v8127] = v8184;
      int * v8027 = v7948->cache_age;
      v8027[v8152] = 0;
      v8030 = v8152;
    }
    int * v8031 = v7948->cache_vals;
    int v8187 = v8030 * 2;
    int v8032 = v8031[v8187];
    int v8188 = (v8030 * 2) + 1;
    int v8033 = v8031[v8188];
    int v8189 = (((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7972 + ((~(((v7974 ^ -1) | (-(v7974 ^ -1))) >> 31)) & 2)) - (v7975 + ((~(((v7976 ^ -1) | (-(v7976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8031[v8189] = v8032;
    int * v8035 = v7948->cache_vals;
    int v8192 = ((((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7972 + ((~(((v7974 ^ -1) | (-(v7974 ^ -1))) >> 31)) & 2)) - (v7975 + ((~(((v7976 ^ -1) | (-(v7976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8035[v8192] = v8033;
    int * v8037 = v7948->cache_tags;
    int v8195 = ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7972 + ((~(((v7974 ^ -1) | (-(v7974 ^ -1))) >> 31)) & 2)) - (v7975 + ((~(((v7976 ^ -1) | (-(v7976 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8196 = (int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1);
    v8037[v8195] = v8196;
    int * v8039 = v7948->cache_dirty;
    v8039[v8195] = 0;
    int * v8041 = v7948->cache_age;
    v8041[v8195] = 1;
    int * v8043 = v7948->cache_age;
    int v8044 = v8043[v8195];
    int v8045 = v8043[v8124];
    int v8202 = v8045 + ((int)((unsigned int)(v8045 - v8044) >> 31));
    v8043[v8124] = v8202;
    int * v8047 = v7948->cache_age;
    int v8048 = v8047[v8125];
    int v8204 = v8048 + ((int)((unsigned int)(v8048 - v8044) >> 31));
    v8047[v8125] = v8204;
    int * v8050 = v7948->cache_age;
    v8050[v8195] = 0;
    v8053 = v8195;
  }
  int * v8054 = v7948->cache_vals;
  int v8207 = (v8053 * 2) + (((int)((unsigned int)(v7952 + 36) >> 2)) & 1);
  v8054[v8207] = v7953;
  int * v8056 = v7948->cache_tags;
  int v8057 = v8056[v8126];
  int v8058 = v8056[v8127];
  bool v8210 = !(((~(((v8057 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v8057 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8058 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v8058 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v8112;
  if (v8210) {
    int * v8059 = v7948->cache_age;
    int v8212 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8058 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))) | (-(v8058 ^ ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v8060 = v8059[v8212];
    int v8061 = v8059[v8126];
    int v8213 = v8061 + ((int)((unsigned int)(v8061 - v8060) >> 31));
    v8059[v8126] = v8213;
    int * v8063 = v7948->cache_age;
    int v8064 = v8063[v8127];
    int v8215 = v8064 + ((int)((unsigned int)(v8064 - v8060) >> 31));
    v8063[v8127] = v8215;
    int * v8066 = v7948->cache_age;
    v8066[v8212] = 0;
    v8112 = v8212;
  } else {
    int * v8069 = v7948->cache_age;
    int v8219 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2);
    int v8070 = v8069[v8219];
    int * v8071 = v7948->cache_tags;
    int v8072 = v8071[v8219];
    int v8073 = v8069[v8127];
    int v8074 = v8071[v8127];
    int * v8075 = v7948->cache_dirty;
    int v8222 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8070 + ((~(((v8072 ^ -1) | (-(v8072 ^ -1))) >> 31)) & 2)) - (v8073 + ((~(((v8074 ^ -1) | (-(v8074 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8076 = v8075[v8222];
    bool v8223 = !(v8076 == 0);
    if (v8223) {
      int * v8077 = v7948->cache_tags;
      int v8078 = v8077[v8222];
      int * v8079 = v7948->cache_vals;
      int v8226 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8070 + ((~(((v8072 ^ -1) | (-(v8072 ^ -1))) >> 31)) & 2)) - (v8073 + ((~(((v8074 ^ -1) | (-(v8074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v8080 = v8079[v8226];
      int v8227 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8070 + ((~(((v8072 ^ -1) | (-(v8072 ^ -1))) >> 31)) & 2)) - (v8073 + ((~(((v8074 ^ -1) | (-(v8074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v8081 = v8079[v8227];
      int * v8082 = v7948->mem;
      int v8229 = v8078 * 2;
      v8082[v8229] = v8080;
      int * v8084 = v7948->mem;
      int v8232 = (v8078 * 2) + 1;
      v8084[v8232] = v8081;
      ;
    } else {
      ;
    }
    int * v8089 = v7948->mem;
    int v8237 = ((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) * 2;
    int v8090 = v8089[v8237];
    int v8238 = (((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) * 2) + 1;
    int v8091 = v8089[v8238];
    int * v8092 = v7948->cache_vals;
    int v8240 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8070 + ((~(((v8072 ^ -1) | (-(v8072 ^ -1))) >> 31)) & 2)) - (v8073 + ((~(((v8074 ^ -1) | (-(v8074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8092[v8240] = v8090;
    int * v8094 = v7948->cache_vals;
    int v8243 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8070 + ((~(((v8072 ^ -1) | (-(v8072 ^ -1))) >> 31)) & 2)) - (v8073 + ((~(((v8074 ^ -1) | (-(v8074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8094[v8243] = v8091;
    int * v8096 = v7948->cache_tags;
    int v8246 = (int)((unsigned int)((int)((unsigned int)(v7952 + 36) >> 2)) >> 1);
    v8096[v8222] = v8246;
    int * v8098 = v7948->cache_dirty;
    v8098[v8222] = 0;
    int * v8100 = v7948->cache_age;
    v8100[v8222] = 1;
    int * v8102 = v7948->cache_age;
    int v8103 = v8102[v8222];
    int v8104 = v8102[v8126];
    int v8252 = v8104 + ((int)((unsigned int)(v8104 - v8103) >> 31));
    v8102[v8126] = v8252;
    int * v8106 = v7948->cache_age;
    int v8107 = v8106[v8127];
    int v8254 = v8107 + ((int)((unsigned int)(v8107 - v8103) >> 31));
    v8106[v8127] = v8254;
    int * v8109 = v7948->cache_age;
    v8109[v8222] = 0;
    v8112 = v8222;
  }
  int * v8113 = v7948->cache_vals;
  int v8257 = (v8112 * 2) + (((int)((unsigned int)(v7952 + 36) >> 2)) & 1);
  v8113[v8257] = v7953;
  int * v8115 = v7948->cache_dirty;
  v8115[v8112] = 1;
  struct StateT * v8117 = slot_41(v7948);
  return v8117;
}

struct StateT * slot_48(struct StateT * v9268) {
  int v9269 = v9268->timer;
  int v9439 = v9269 + 1;
  v9268->timer = v9439;
  int * v9271 = v9268->regs;
  int v9272 = v9271[2];
  int v9273 = v9271[15];
  int * v9274 = v9268->cache_tags;
  int v9444 = (((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2;
  int v9275 = v9274[v9444];
  int v9445 = ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9276 = v9274[v9445];
  int v9446 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2);
  int v9277 = v9274[v9446];
  int v9447 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9278 = v9274[v9447];
  int v9279 = v9268->timer;
  int v9448 = v9279 + ((100 ^ (((~(((v9277 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9277 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9275 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9275 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9276 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9276 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9277 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9277 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9268->timer = v9448;
  bool v9449 = !(((~(((v9275 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9275 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9276 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9276 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v9373;
  if (v9449) {
    int * v9281 = v9268->cache_age;
    int v9451 = ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v9276 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9276 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v9282 = v9281[v9451];
    int v9283 = v9281[v9444];
    int v9452 = v9283 + ((int)((unsigned int)(v9283 - v9282) >> 31));
    v9281[v9444] = v9452;
    int * v9285 = v9268->cache_age;
    int v9286 = v9285[v9445];
    int v9454 = v9286 + ((int)((unsigned int)(v9286 - v9282) >> 31));
    v9285[v9445] = v9454;
    int * v9288 = v9268->cache_age;
    v9288[v9451] = 0;
    v9373 = v9451;
  } else {
    int * v9291 = v9268->cache_age;
    int v9458 = (((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2;
    int v9292 = v9291[v9458];
    int * v9293 = v9268->cache_tags;
    int v9294 = v9293[v9458];
    int v9295 = v9291[v9445];
    int v9296 = v9293[v9445];
    bool v9460 = !(((~(((v9277 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9277 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v9350;
    if (v9460) {
      int * v9297 = v9268->cache_age;
      int v9462 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9278 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v9298 = v9297[v9462];
      int v9299 = v9297[v9446];
      int v9463 = v9299 + ((int)((unsigned int)(v9299 - v9298) >> 31));
      v9297[v9446] = v9463;
      int * v9301 = v9268->cache_age;
      int v9302 = v9301[v9447];
      int v9465 = v9302 + ((int)((unsigned int)(v9302 - v9298) >> 31));
      v9301[v9447] = v9465;
      int * v9304 = v9268->cache_age;
      v9304[v9462] = 0;
      v9350 = v9462;
    } else {
      int * v9307 = v9268->cache_age;
      int v9469 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2);
      int v9308 = v9307[v9469];
      int * v9309 = v9268->cache_tags;
      int v9310 = v9309[v9469];
      int v9311 = v9307[v9447];
      int v9312 = v9309[v9447];
      int * v9313 = v9268->cache_dirty;
      int v9472 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9308 + ((~(((v9310 ^ -1) | (-(v9310 ^ -1))) >> 31)) & 2)) - (v9311 + ((~(((v9312 ^ -1) | (-(v9312 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9314 = v9313[v9472];
      bool v9473 = !(v9314 == 0);
      if (v9473) {
        int * v9315 = v9268->cache_tags;
        int v9316 = v9315[v9472];
        int * v9317 = v9268->cache_vals;
        int v9476 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9308 + ((~(((v9310 ^ -1) | (-(v9310 ^ -1))) >> 31)) & 2)) - (v9311 + ((~(((v9312 ^ -1) | (-(v9312 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9318 = v9317[v9476];
        int v9477 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9308 + ((~(((v9310 ^ -1) | (-(v9310 ^ -1))) >> 31)) & 2)) - (v9311 + ((~(((v9312 ^ -1) | (-(v9312 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9319 = v9317[v9477];
        int * v9320 = v9268->mem;
        int v9479 = v9316 * 2;
        v9320[v9479] = v9318;
        int * v9322 = v9268->mem;
        int v9482 = (v9316 * 2) + 1;
        v9322[v9482] = v9319;
        ;
      } else {
        ;
      }
      int * v9327 = v9268->mem;
      int v9487 = ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) * 2;
      int v9328 = v9327[v9487];
      int v9488 = (((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) * 2) + 1;
      int v9329 = v9327[v9488];
      int * v9330 = v9268->cache_vals;
      int v9490 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9308 + ((~(((v9310 ^ -1) | (-(v9310 ^ -1))) >> 31)) & 2)) - (v9311 + ((~(((v9312 ^ -1) | (-(v9312 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9330[v9490] = v9328;
      int * v9332 = v9268->cache_vals;
      int v9493 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9308 + ((~(((v9310 ^ -1) | (-(v9310 ^ -1))) >> 31)) & 2)) - (v9311 + ((~(((v9312 ^ -1) | (-(v9312 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9332[v9493] = v9329;
      int * v9334 = v9268->cache_tags;
      int v9496 = (int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1);
      v9334[v9472] = v9496;
      int * v9336 = v9268->cache_dirty;
      v9336[v9472] = 0;
      int * v9338 = v9268->cache_age;
      v9338[v9472] = 1;
      int * v9340 = v9268->cache_age;
      int v9341 = v9340[v9472];
      int v9342 = v9340[v9446];
      int v9502 = v9342 + ((int)((unsigned int)(v9342 - v9341) >> 31));
      v9340[v9446] = v9502;
      int * v9344 = v9268->cache_age;
      int v9345 = v9344[v9447];
      int v9504 = v9345 + ((int)((unsigned int)(v9345 - v9341) >> 31));
      v9344[v9447] = v9504;
      int * v9347 = v9268->cache_age;
      v9347[v9472] = 0;
      v9350 = v9472;
    }
    int * v9351 = v9268->cache_vals;
    int v9507 = v9350 * 2;
    int v9352 = v9351[v9507];
    int v9508 = (v9350 * 2) + 1;
    int v9353 = v9351[v9508];
    int v9509 = (((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9292 + ((~(((v9294 ^ -1) | (-(v9294 ^ -1))) >> 31)) & 2)) - (v9295 + ((~(((v9296 ^ -1) | (-(v9296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9351[v9509] = v9352;
    int * v9355 = v9268->cache_vals;
    int v9512 = ((((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9292 + ((~(((v9294 ^ -1) | (-(v9294 ^ -1))) >> 31)) & 2)) - (v9295 + ((~(((v9296 ^ -1) | (-(v9296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9355[v9512] = v9353;
    int * v9357 = v9268->cache_tags;
    int v9515 = ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9292 + ((~(((v9294 ^ -1) | (-(v9294 ^ -1))) >> 31)) & 2)) - (v9295 + ((~(((v9296 ^ -1) | (-(v9296 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9516 = (int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1);
    v9357[v9515] = v9516;
    int * v9359 = v9268->cache_dirty;
    v9359[v9515] = 0;
    int * v9361 = v9268->cache_age;
    v9361[v9515] = 1;
    int * v9363 = v9268->cache_age;
    int v9364 = v9363[v9515];
    int v9365 = v9363[v9444];
    int v9522 = v9365 + ((int)((unsigned int)(v9365 - v9364) >> 31));
    v9363[v9444] = v9522;
    int * v9367 = v9268->cache_age;
    int v9368 = v9367[v9445];
    int v9524 = v9368 + ((int)((unsigned int)(v9368 - v9364) >> 31));
    v9367[v9445] = v9524;
    int * v9370 = v9268->cache_age;
    v9370[v9515] = 0;
    v9373 = v9515;
  }
  int * v9374 = v9268->cache_vals;
  int v9527 = (v9373 * 2) + (((int)((unsigned int)(v9272 + 24) >> 2)) & 1);
  v9374[v9527] = v9273;
  int * v9376 = v9268->cache_tags;
  int v9377 = v9376[v9446];
  int v9378 = v9376[v9447];
  bool v9530 = !(((~(((v9377 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9377 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9378 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9378 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v9432;
  if (v9530) {
    int * v9379 = v9268->cache_age;
    int v9532 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9378 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))) | (-(v9378 ^ ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v9380 = v9379[v9532];
    int v9381 = v9379[v9446];
    int v9533 = v9381 + ((int)((unsigned int)(v9381 - v9380) >> 31));
    v9379[v9446] = v9533;
    int * v9383 = v9268->cache_age;
    int v9384 = v9383[v9447];
    int v9535 = v9384 + ((int)((unsigned int)(v9384 - v9380) >> 31));
    v9383[v9447] = v9535;
    int * v9386 = v9268->cache_age;
    v9386[v9532] = 0;
    v9432 = v9532;
  } else {
    int * v9389 = v9268->cache_age;
    int v9539 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2);
    int v9390 = v9389[v9539];
    int * v9391 = v9268->cache_tags;
    int v9392 = v9391[v9539];
    int v9393 = v9389[v9447];
    int v9394 = v9391[v9447];
    int * v9395 = v9268->cache_dirty;
    int v9542 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9390 + ((~(((v9392 ^ -1) | (-(v9392 ^ -1))) >> 31)) & 2)) - (v9393 + ((~(((v9394 ^ -1) | (-(v9394 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9396 = v9395[v9542];
    bool v9543 = !(v9396 == 0);
    if (v9543) {
      int * v9397 = v9268->cache_tags;
      int v9398 = v9397[v9542];
      int * v9399 = v9268->cache_vals;
      int v9546 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9390 + ((~(((v9392 ^ -1) | (-(v9392 ^ -1))) >> 31)) & 2)) - (v9393 + ((~(((v9394 ^ -1) | (-(v9394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9400 = v9399[v9546];
      int v9547 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9390 + ((~(((v9392 ^ -1) | (-(v9392 ^ -1))) >> 31)) & 2)) - (v9393 + ((~(((v9394 ^ -1) | (-(v9394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9401 = v9399[v9547];
      int * v9402 = v9268->mem;
      int v9549 = v9398 * 2;
      v9402[v9549] = v9400;
      int * v9404 = v9268->mem;
      int v9552 = (v9398 * 2) + 1;
      v9404[v9552] = v9401;
      ;
    } else {
      ;
    }
    int * v9409 = v9268->mem;
    int v9557 = ((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) * 2;
    int v9410 = v9409[v9557];
    int v9558 = (((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) * 2) + 1;
    int v9411 = v9409[v9558];
    int * v9412 = v9268->cache_vals;
    int v9560 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9390 + ((~(((v9392 ^ -1) | (-(v9392 ^ -1))) >> 31)) & 2)) - (v9393 + ((~(((v9394 ^ -1) | (-(v9394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9412[v9560] = v9410;
    int * v9414 = v9268->cache_vals;
    int v9563 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9390 + ((~(((v9392 ^ -1) | (-(v9392 ^ -1))) >> 31)) & 2)) - (v9393 + ((~(((v9394 ^ -1) | (-(v9394 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9414[v9563] = v9411;
    int * v9416 = v9268->cache_tags;
    int v9566 = (int)((unsigned int)((int)((unsigned int)(v9272 + 24) >> 2)) >> 1);
    v9416[v9542] = v9566;
    int * v9418 = v9268->cache_dirty;
    v9418[v9542] = 0;
    int * v9420 = v9268->cache_age;
    v9420[v9542] = 1;
    int * v9422 = v9268->cache_age;
    int v9423 = v9422[v9542];
    int v9424 = v9422[v9446];
    int v9572 = v9424 + ((int)((unsigned int)(v9424 - v9423) >> 31));
    v9422[v9446] = v9572;
    int * v9426 = v9268->cache_age;
    int v9427 = v9426[v9447];
    int v9574 = v9427 + ((int)((unsigned int)(v9427 - v9423) >> 31));
    v9426[v9447] = v9574;
    int * v9429 = v9268->cache_age;
    v9429[v9542] = 0;
    v9432 = v9542;
  }
  int * v9433 = v9268->cache_vals;
  int v9577 = (v9432 * 2) + (((int)((unsigned int)(v9272 + 24) >> 2)) & 1);
  v9433[v9577] = v9273;
  int * v9435 = v9268->cache_dirty;
  v9435[v9432] = 1;
  struct StateT * v9437 = slot_49(v9268);
  return v9437;
}

struct StateT * slot_77(struct StateT * v12135) {
  int v12136 = v12135->timer;
  int v12144 = v12136 + 1;
  v12135->timer = v12144;
  int * v12138 = v12135->regs;
  int v12139 = v12138[15];
  int v12140 = v12138[20];
  int v12148 = v12139 | v12140;
  v12138[15] = v12148;
  struct StateT * v12142 = slot_78(v12135);
  return v12142;
}

struct StateT * slot_85(struct StateT * v12978) {
  int v12979 = v12978->timer;
  int v12986 = v12979 + 1;
  v12978->timer = v12986;
  int * v12981 = v12978->regs;
  int v12982 = v12981[18];
  int v12989 = v12982 << 9;
  v12981[18] = v12989;
  struct StateT * v12984 = slot_86(v12978);
  return v12984;
}

struct StateT * slot_75(struct StateT * v12078) {
  int v12079 = v12078->timer;
  int v12086 = v12079 + 1;
  v12078->timer = v12086;
  int * v12081 = v12078->regs;
  int v12082 = v12081[15];
  int v12090 = (int)((unsigned int)v12082 >> 23);
  v12081[20] = v12090;
  struct StateT * v12084 = slot_76(v12078);
  return v12084;
}

struct StateT * slot_72(struct StateT * v11794) {
  int v11795 = v11794->timer;
  int v11803 = v11795 + 1;
  v11794->timer = v11803;
  int * v11797 = v11794->regs;
  int v11798 = v11797[13];
  int v11799 = v11797[11];
  int v11808 = v11798 + v11799;
  v11797[8] = v11808;
  struct StateT * v11801 = slot_73(v11794);
  return v11801;
}

struct StateT * slot_119(struct StateT * v20593) {
  int v20594 = v20593->timer;
  int v20601 = v20594 + 1;
  v20593->timer = v20601;
  int * v20596 = v20593->regs;
  int v20597 = v20596[16];
  int v20604 = v20597 << 18;
  v20596[16] = v20604;
  struct StateT * v20599 = slot_120(v20593);
  return v20599;
}

struct StateT * slot_71(struct StateT * v11761) {
  int v11762 = v11761->timer;
  int v11770 = v11762 + 1;
  v11761->timer = v11770;
  int * v11764 = v11761->regs;
  int v11765 = v11764[12];
  int v11766 = v11764[21];
  int v11775 = v11765 + v11766;
  v11764[15] = v11775;
  struct StateT * v11768 = slot_72(v11761);
  return v11768;
}

struct StateT * slot_101(struct StateT * v18044) {
  int v18045 = v18044->timer;
  int v18052 = v18045 + 1;
  v18044->timer = v18052;
  int * v18047 = v18044->regs;
  int v18048 = v18047[9];
  int v18056 = (int)((unsigned int)v18048 >> 19);
  v18047[20] = v18056;
  struct StateT * v18050 = slot_102(v18044);
  return v18050;
}

struct StateT * slot_276(struct StateT * v20511) {
  int v20512 = v20511->timer;
  int v20515 = v20512 + 1;
  v20511->timer = v20515;
  return v20511;
}

struct StateT * slot_108(struct StateT * v19580) {
  int v19581 = v19580->timer;
  int v19589 = v19581 + 1;
  v19580->timer = v19589;
  int * v19583 = v19580->regs;
  int v19584 = v19583[23];
  int v19585 = v19583[8];
  int v19593 = v19584 ^ v19585;
  v19583[23] = v19593;
  struct StateT * v19587 = slot_109(v19580);
  return v19587;
}

struct StateT * slot_116(struct StateT * v20548) {
  int v20549 = v20548->timer;
  int v20556 = v20549 + 1;
  v20548->timer = v20556;
  int * v20551 = v20548->regs;
  int v20552 = v20551[15];
  int v20559 = v20552 << 18;
  v20551[15] = v20559;
  struct StateT * v20554 = slot_117(v20548);
  return v20554;
}

struct StateT * slot_93(struct StateT * v15626) {
  int v15627 = v15626->timer;
  int v15635 = v15627 + 1;
  v15626->timer = v15635;
  int * v15629 = v15626->regs;
  int v15630 = v15629[27];
  int v15631 = v15629[1];
  int v15640 = v15630 + v15631;
  v15629[9] = v15640;
  struct StateT * v15633 = slot_94(v15626);
  return v15633;
}

struct StateT * slot_266(struct StateT * v18497) {
  int v18498 = v18497->timer;
  int v18608 = v18498 + 1;
  v18497->timer = v18608;
  int * v18500 = v18497->regs;
  int v18501 = v18500[2];
  int * v18502 = v18497->cache_tags;
  int v18612 = (((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2;
  int v18503 = v18502[v18612];
  int v18613 = ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2) + 1;
  int v18504 = v18502[v18613];
  int v18614 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2);
  int v18505 = v18502[v18614];
  int v18615 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v18506 = v18502[v18615];
  int v18507 = v18497->timer;
  int v18616 = v18507 + ((100 ^ (((~(((v18505 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18505 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v18503 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18503 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v18504 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18504 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v18505 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18505 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31))) & 104)))));
  v18497->timer = v18616;
  int * v18509 = v18497->cache_vals;
  bool v18617 = !(((~(((v18503 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18503 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v18504 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18504 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31))) == 0);
  int v18602;
  if (v18617) {
    int * v18510 = v18497->cache_age;
    int v18619 = ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2) + ((~(((v18504 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18504 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) & 1);
    int v18511 = v18510[v18619];
    int v18512 = v18510[v18612];
    int v18620 = v18512 + ((int)((unsigned int)(v18512 - v18511) >> 31));
    v18510[v18612] = v18620;
    int * v18514 = v18497->cache_age;
    int v18515 = v18514[v18613];
    int v18622 = v18515 + ((int)((unsigned int)(v18515 - v18511) >> 31));
    v18514[v18613] = v18622;
    int * v18517 = v18497->cache_age;
    v18517[v18619] = 0;
    v18602 = v18619;
  } else {
    int * v18520 = v18497->cache_age;
    int v18626 = (((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2;
    int v18521 = v18520[v18626];
    int * v18522 = v18497->cache_tags;
    int v18523 = v18522[v18626];
    int v18524 = v18520[v18613];
    int v18525 = v18522[v18613];
    bool v18628 = !(((~(((v18505 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18505 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31))) == 0);
    int v18579;
    if (v18628) {
      int * v18526 = v18497->cache_age;
      int v18630 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + ((~(((v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))) | (-(v18506 ^ ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1))))) >> 31)) & 1);
      int v18527 = v18526[v18630];
      int v18528 = v18526[v18614];
      int v18631 = v18528 + ((int)((unsigned int)(v18528 - v18527) >> 31));
      v18526[v18614] = v18631;
      int * v18530 = v18497->cache_age;
      int v18531 = v18530[v18615];
      int v18633 = v18531 + ((int)((unsigned int)(v18531 - v18527) >> 31));
      v18530[v18615] = v18633;
      int * v18533 = v18497->cache_age;
      v18533[v18630] = 0;
      v18579 = v18630;
    } else {
      int * v18536 = v18497->cache_age;
      int v18637 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2);
      int v18537 = v18536[v18637];
      int * v18538 = v18497->cache_tags;
      int v18539 = v18538[v18637];
      int v18540 = v18536[v18615];
      int v18541 = v18538[v18615];
      int * v18542 = v18497->cache_dirty;
      int v18640 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v18537 + ((~(((v18539 ^ -1) | (-(v18539 ^ -1))) >> 31)) & 2)) - (v18540 + ((~(((v18541 ^ -1) | (-(v18541 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v18543 = v18542[v18640];
      bool v18641 = !(v18543 == 0);
      if (v18641) {
        int * v18544 = v18497->cache_tags;
        int v18545 = v18544[v18640];
        int * v18546 = v18497->cache_vals;
        int v18644 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v18537 + ((~(((v18539 ^ -1) | (-(v18539 ^ -1))) >> 31)) & 2)) - (v18540 + ((~(((v18541 ^ -1) | (-(v18541 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v18547 = v18546[v18644];
        int v18645 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v18537 + ((~(((v18539 ^ -1) | (-(v18539 ^ -1))) >> 31)) & 2)) - (v18540 + ((~(((v18541 ^ -1) | (-(v18541 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v18548 = v18546[v18645];
        int * v18549 = v18497->mem;
        int v18647 = v18545 * 2;
        v18549[v18647] = v18547;
        int * v18551 = v18497->mem;
        int v18650 = (v18545 * 2) + 1;
        v18551[v18650] = v18548;
        ;
      } else {
        ;
      }
      int * v18556 = v18497->mem;
      int v18655 = ((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) * 2;
      int v18557 = v18556[v18655];
      int v18656 = (((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) * 2) + 1;
      int v18558 = v18556[v18656];
      int * v18559 = v18497->cache_vals;
      int v18658 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v18537 + ((~(((v18539 ^ -1) | (-(v18539 ^ -1))) >> 31)) & 2)) - (v18540 + ((~(((v18541 ^ -1) | (-(v18541 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v18559[v18658] = v18557;
      int * v18561 = v18497->cache_vals;
      int v18661 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v18537 + ((~(((v18539 ^ -1) | (-(v18539 ^ -1))) >> 31)) & 2)) - (v18540 + ((~(((v18541 ^ -1) | (-(v18541 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v18561[v18661] = v18558;
      int * v18563 = v18497->cache_tags;
      int v18664 = (int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1);
      v18563[v18640] = v18664;
      int * v18565 = v18497->cache_dirty;
      v18565[v18640] = 0;
      int * v18567 = v18497->cache_age;
      v18567[v18640] = 1;
      int * v18569 = v18497->cache_age;
      int v18570 = v18569[v18640];
      int v18571 = v18569[v18614];
      int v18670 = v18571 + ((int)((unsigned int)(v18571 - v18570) >> 31));
      v18569[v18614] = v18670;
      int * v18573 = v18497->cache_age;
      int v18574 = v18573[v18615];
      int v18672 = v18574 + ((int)((unsigned int)(v18574 - v18570) >> 31));
      v18573[v18615] = v18672;
      int * v18576 = v18497->cache_age;
      v18576[v18640] = 0;
      v18579 = v18640;
    }
    int * v18580 = v18497->cache_vals;
    int v18675 = v18579 * 2;
    int v18581 = v18580[v18675];
    int v18676 = (v18579 * 2) + 1;
    int v18582 = v18580[v18676];
    int v18677 = (((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2) + ((((v18521 + ((~(((v18523 ^ -1) | (-(v18523 ^ -1))) >> 31)) & 2)) - (v18524 + ((~(((v18525 ^ -1) | (-(v18525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v18580[v18677] = v18581;
    int * v18584 = v18497->cache_vals;
    int v18680 = ((((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2) + ((((v18521 + ((~(((v18523 ^ -1) | (-(v18523 ^ -1))) >> 31)) & 2)) - (v18524 + ((~(((v18525 ^ -1) | (-(v18525 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v18584[v18680] = v18582;
    int * v18586 = v18497->cache_tags;
    int v18683 = ((((int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1)) & 1) * 2) + ((((v18521 + ((~(((v18523 ^ -1) | (-(v18523 ^ -1))) >> 31)) & 2)) - (v18524 + ((~(((v18525 ^ -1) | (-(v18525 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v18684 = (int)((unsigned int)((int)((unsigned int)(v18501 + 76) >> 2)) >> 1);
    v18586[v18683] = v18684;
    int * v18588 = v18497->cache_dirty;
    v18588[v18683] = 0;
    int * v18590 = v18497->cache_age;
    v18590[v18683] = 1;
    int * v18592 = v18497->cache_age;
    int v18593 = v18592[v18683];
    int v18594 = v18592[v18612];
    int v18690 = v18594 + ((int)((unsigned int)(v18594 - v18593) >> 31));
    v18592[v18612] = v18690;
    int * v18596 = v18497->cache_age;
    int v18597 = v18596[v18613];
    int v18692 = v18597 + ((int)((unsigned int)(v18597 - v18593) >> 31));
    v18596[v18613] = v18692;
    int * v18599 = v18497->cache_age;
    v18599[v18683] = 0;
    v18602 = v18683;
  }
  int v18695 = (v18602 * 2) + (((int)((unsigned int)(v18501 + 76) >> 2)) & 1);
  int v18603 = v18509[v18695];
  int * v18604 = v18497->regs;
  v18604[19] = v18603;
  struct StateT * v18606 = slot_267(v18497);
  return v18606;
}

struct StateT * slot_88(struct StateT * v13969) {
  int v13970 = v13969->timer;
  int v13978 = v13970 + 1;
  v13969->timer = v13978;
  int * v13972 = v13969->regs;
  int v13973 = v13972[24];
  int v13974 = v13972[8];
  int v13982 = v13973 ^ v13974;
  v13972[24] = v13982;
  struct StateT * v13976 = slot_89(v13969);
  return v13976;
}

struct StateT * slot_96(struct StateT * v16620) {
  int v16621 = v16620->timer;
  int v16628 = v16621 + 1;
  v16620->timer = v16628;
  int * v16623 = v16620->regs;
  int v16624 = v16623[15];
  int v16631 = v16624 << 13;
  v16623[15] = v16631;
  struct StateT * v16626 = slot_97(v16620);
  return v16626;
}

struct StateT * slot_215(struct StateT * v9684) {
  int v9685 = v9684->timer;
  int v9691 = v9685 + 1;
  v9684->timer = v9691;
  int * v9687 = v9684->regs;
  v9687[15] = 1634762752;
  struct StateT * v9689 = slot_216(v9684);
  return v9689;
}

struct StateT * slot_234(struct StateT * v11778) {
  int v11779 = v11778->timer;
  int v11787 = v11779 + 1;
  v11778->timer = v11787;
  int * v11781 = v11778->regs;
  int v11782 = v11781[24];
  int v11783 = v11781[30];
  int v11791 = v11782 + v11783;
  v11781[24] = v11791;
  struct StateT * v11785 = slot_235(v11778);
  return v11785;
}

struct StateT * slot_45(struct StateT * v9223) {
  int v9224 = v9223->timer;
  int v9231 = v9224 + 1;
  v9223->timer = v9231;
  int * v9226 = v9223->regs;
  int v9227 = v9226[7];
  v9226[14] = v9227;
  struct StateT * v9229 = slot_46(v9223);
  return v9229;
}

struct StateT * slot_218(struct StateT * v9966) {
  int v9967 = v9966->timer;
  int v9975 = v9967 + 1;
  v9966->timer = v9975;
  int * v9969 = v9966->regs;
  int v9970 = v9969[12];
  int v9971 = v9969[6];
  int v9979 = v9970 + v9971;
  v9969[12] = v9979;
  struct StateT * v9973 = slot_219(v9966);
  return v9973;
}

struct StateT * slot_220(struct StateT * v10025) {
  int v10026 = v10025->timer;
  int v10136 = v10026 + 1;
  v10025->timer = v10136;
  int * v10028 = v10025->regs;
  int v10029 = v10028[2];
  int * v10030 = v10025->cache_tags;
  int v10140 = (((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2;
  int v10031 = v10030[v10140];
  int v10141 = ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10032 = v10030[v10141];
  int v10142 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2);
  int v10033 = v10030[v10142];
  int v10143 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10034 = v10030[v10143];
  int v10035 = v10025->timer;
  int v10144 = v10035 + ((100 ^ (((~(((v10033 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10033 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10031 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10031 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10032 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10032 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10033 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10033 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10025->timer = v10144;
  int * v10037 = v10025->cache_vals;
  bool v10145 = !(((~(((v10031 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10031 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10032 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10032 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v10130;
  if (v10145) {
    int * v10038 = v10025->cache_age;
    int v10147 = ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v10032 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10032 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v10039 = v10038[v10147];
    int v10040 = v10038[v10140];
    int v10148 = v10040 + ((int)((unsigned int)(v10040 - v10039) >> 31));
    v10038[v10140] = v10148;
    int * v10042 = v10025->cache_age;
    int v10043 = v10042[v10141];
    int v10150 = v10043 + ((int)((unsigned int)(v10043 - v10039) >> 31));
    v10042[v10141] = v10150;
    int * v10045 = v10025->cache_age;
    v10045[v10147] = 0;
    v10130 = v10147;
  } else {
    int * v10048 = v10025->cache_age;
    int v10154 = (((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2;
    int v10049 = v10048[v10154];
    int * v10050 = v10025->cache_tags;
    int v10051 = v10050[v10154];
    int v10052 = v10048[v10141];
    int v10053 = v10050[v10141];
    bool v10156 = !(((~(((v10033 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10033 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v10107;
    if (v10156) {
      int * v10054 = v10025->cache_age;
      int v10158 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))) | (-(v10034 ^ ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v10055 = v10054[v10158];
      int v10056 = v10054[v10142];
      int v10159 = v10056 + ((int)((unsigned int)(v10056 - v10055) >> 31));
      v10054[v10142] = v10159;
      int * v10058 = v10025->cache_age;
      int v10059 = v10058[v10143];
      int v10161 = v10059 + ((int)((unsigned int)(v10059 - v10055) >> 31));
      v10058[v10143] = v10161;
      int * v10061 = v10025->cache_age;
      v10061[v10158] = 0;
      v10107 = v10158;
    } else {
      int * v10064 = v10025->cache_age;
      int v10165 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2);
      int v10065 = v10064[v10165];
      int * v10066 = v10025->cache_tags;
      int v10067 = v10066[v10165];
      int v10068 = v10064[v10143];
      int v10069 = v10066[v10143];
      int * v10070 = v10025->cache_dirty;
      int v10168 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10071 = v10070[v10168];
      bool v10169 = !(v10071 == 0);
      if (v10169) {
        int * v10072 = v10025->cache_tags;
        int v10073 = v10072[v10168];
        int * v10074 = v10025->cache_vals;
        int v10172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10075 = v10074[v10172];
        int v10173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10076 = v10074[v10173];
        int * v10077 = v10025->mem;
        int v10175 = v10073 * 2;
        v10077[v10175] = v10075;
        int * v10079 = v10025->mem;
        int v10178 = (v10073 * 2) + 1;
        v10079[v10178] = v10076;
        ;
      } else {
        ;
      }
      int * v10084 = v10025->mem;
      int v10183 = ((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) * 2;
      int v10085 = v10084[v10183];
      int v10184 = (((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) * 2) + 1;
      int v10086 = v10084[v10184];
      int * v10087 = v10025->cache_vals;
      int v10186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10087[v10186] = v10085;
      int * v10089 = v10025->cache_vals;
      int v10189 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10065 + ((~(((v10067 ^ -1) | (-(v10067 ^ -1))) >> 31)) & 2)) - (v10068 + ((~(((v10069 ^ -1) | (-(v10069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10089[v10189] = v10086;
      int * v10091 = v10025->cache_tags;
      int v10192 = (int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1);
      v10091[v10168] = v10192;
      int * v10093 = v10025->cache_dirty;
      v10093[v10168] = 0;
      int * v10095 = v10025->cache_age;
      v10095[v10168] = 1;
      int * v10097 = v10025->cache_age;
      int v10098 = v10097[v10168];
      int v10099 = v10097[v10142];
      int v10198 = v10099 + ((int)((unsigned int)(v10099 - v10098) >> 31));
      v10097[v10142] = v10198;
      int * v10101 = v10025->cache_age;
      int v10102 = v10101[v10143];
      int v10200 = v10102 + ((int)((unsigned int)(v10102 - v10098) >> 31));
      v10101[v10143] = v10200;
      int * v10104 = v10025->cache_age;
      v10104[v10168] = 0;
      v10107 = v10168;
    }
    int * v10108 = v10025->cache_vals;
    int v10203 = v10107 * 2;
    int v10109 = v10108[v10203];
    int v10204 = (v10107 * 2) + 1;
    int v10110 = v10108[v10204];
    int v10205 = (((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10049 + ((~(((v10051 ^ -1) | (-(v10051 ^ -1))) >> 31)) & 2)) - (v10052 + ((~(((v10053 ^ -1) | (-(v10053 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10108[v10205] = v10109;
    int * v10112 = v10025->cache_vals;
    int v10208 = ((((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10049 + ((~(((v10051 ^ -1) | (-(v10051 ^ -1))) >> 31)) & 2)) - (v10052 + ((~(((v10053 ^ -1) | (-(v10053 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10112[v10208] = v10110;
    int * v10114 = v10025->cache_tags;
    int v10211 = ((((int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v10049 + ((~(((v10051 ^ -1) | (-(v10051 ^ -1))) >> 31)) & 2)) - (v10052 + ((~(((v10053 ^ -1) | (-(v10053 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10212 = (int)((unsigned int)((int)((unsigned int)(v10029 + 12) >> 2)) >> 1);
    v10114[v10211] = v10212;
    int * v10116 = v10025->cache_dirty;
    v10116[v10211] = 0;
    int * v10118 = v10025->cache_age;
    v10118[v10211] = 1;
    int * v10120 = v10025->cache_age;
    int v10121 = v10120[v10211];
    int v10122 = v10120[v10140];
    int v10218 = v10122 + ((int)((unsigned int)(v10122 - v10121) >> 31));
    v10120[v10140] = v10218;
    int * v10124 = v10025->cache_age;
    int v10125 = v10124[v10141];
    int v10220 = v10125 + ((int)((unsigned int)(v10125 - v10121) >> 31));
    v10124[v10141] = v10220;
    int * v10127 = v10025->cache_age;
    v10127[v10211] = 0;
    v10130 = v10211;
  }
  int v10223 = (v10130 * 2) + (((int)((unsigned int)(v10029 + 12) >> 2)) & 1);
  int v10131 = v10037[v10223];
  int * v10132 = v10025->regs;
  v10132[7] = v10131;
  struct StateT * v10134 = slot_221(v10025);
  return v10134;
}

struct StateT * slot_134(struct StateT * v20829) {
  int v20830 = v20829->timer;
  int v20838 = v20830 + 1;
  v20829->timer = v20838;
  int * v20832 = v20829->regs;
  int v20833 = v20832[22];
  int v20834 = v20832[1];
  int v20843 = v20833 + v20834;
  v20832[17] = v20843;
  struct StateT * v20836 = slot_135(v20829);
  return v20836;
}

struct StateT * slot_175(struct StateT * v21474) {
  int v21475 = v21474->timer;
  int v21482 = v21475 + 1;
  v21474->timer = v21482;
  int * v21477 = v21474->regs;
  int v21478 = v21477[11];
  int v21486 = (int)((unsigned int)v21478 >> 19);
  v21477[9] = v21486;
  struct StateT * v21480 = slot_176(v21474);
  return v21480;
}

struct StateT * slot_273(struct StateT * v20038) {
  int v20039 = v20038->timer;
  int v20149 = v20039 + 1;
  v20038->timer = v20149;
  int * v20041 = v20038->regs;
  int v20042 = v20041[2];
  int * v20043 = v20038->cache_tags;
  int v20153 = (((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2;
  int v20044 = v20043[v20153];
  int v20154 = ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2) + 1;
  int v20045 = v20043[v20154];
  int v20155 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2);
  int v20046 = v20043[v20155];
  int v20156 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v20047 = v20043[v20156];
  int v20048 = v20038->timer;
  int v20157 = v20048 + ((100 ^ (((~(((v20046 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20046 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20044 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20044 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v20045 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20045 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v20046 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20046 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31))) & 104)))));
  v20038->timer = v20157;
  int * v20050 = v20038->cache_vals;
  bool v20158 = !(((~(((v20044 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20044 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v20045 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20045 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31))) == 0);
  int v20143;
  if (v20158) {
    int * v20051 = v20038->cache_age;
    int v20160 = ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2) + ((~(((v20045 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20045 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) & 1);
    int v20052 = v20051[v20160];
    int v20053 = v20051[v20153];
    int v20161 = v20053 + ((int)((unsigned int)(v20053 - v20052) >> 31));
    v20051[v20153] = v20161;
    int * v20055 = v20038->cache_age;
    int v20056 = v20055[v20154];
    int v20163 = v20056 + ((int)((unsigned int)(v20056 - v20052) >> 31));
    v20055[v20154] = v20163;
    int * v20058 = v20038->cache_age;
    v20058[v20160] = 0;
    v20143 = v20160;
  } else {
    int * v20061 = v20038->cache_age;
    int v20167 = (((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2;
    int v20062 = v20061[v20167];
    int * v20063 = v20038->cache_tags;
    int v20064 = v20063[v20167];
    int v20065 = v20061[v20154];
    int v20066 = v20063[v20154];
    bool v20169 = !(((~(((v20046 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20046 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) | (~(((v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31))) == 0);
    int v20120;
    if (v20169) {
      int * v20067 = v20038->cache_age;
      int v20171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + ((~(((v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))) | (-(v20047 ^ ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1))))) >> 31)) & 1);
      int v20068 = v20067[v20171];
      int v20069 = v20067[v20155];
      int v20172 = v20069 + ((int)((unsigned int)(v20069 - v20068) >> 31));
      v20067[v20155] = v20172;
      int * v20071 = v20038->cache_age;
      int v20072 = v20071[v20156];
      int v20174 = v20072 + ((int)((unsigned int)(v20072 - v20068) >> 31));
      v20071[v20156] = v20174;
      int * v20074 = v20038->cache_age;
      v20074[v20171] = 0;
      v20120 = v20171;
    } else {
      int * v20077 = v20038->cache_age;
      int v20178 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2);
      int v20078 = v20077[v20178];
      int * v20079 = v20038->cache_tags;
      int v20080 = v20079[v20178];
      int v20081 = v20077[v20156];
      int v20082 = v20079[v20156];
      int * v20083 = v20038->cache_dirty;
      int v20181 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v20078 + ((~(((v20080 ^ -1) | (-(v20080 ^ -1))) >> 31)) & 2)) - (v20081 + ((~(((v20082 ^ -1) | (-(v20082 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v20084 = v20083[v20181];
      bool v20182 = !(v20084 == 0);
      if (v20182) {
        int * v20085 = v20038->cache_tags;
        int v20086 = v20085[v20181];
        int * v20087 = v20038->cache_vals;
        int v20185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v20078 + ((~(((v20080 ^ -1) | (-(v20080 ^ -1))) >> 31)) & 2)) - (v20081 + ((~(((v20082 ^ -1) | (-(v20082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v20088 = v20087[v20185];
        int v20186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v20078 + ((~(((v20080 ^ -1) | (-(v20080 ^ -1))) >> 31)) & 2)) - (v20081 + ((~(((v20082 ^ -1) | (-(v20082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v20089 = v20087[v20186];
        int * v20090 = v20038->mem;
        int v20188 = v20086 * 2;
        v20090[v20188] = v20088;
        int * v20092 = v20038->mem;
        int v20191 = (v20086 * 2) + 1;
        v20092[v20191] = v20089;
        ;
      } else {
        ;
      }
      int * v20097 = v20038->mem;
      int v20196 = ((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) * 2;
      int v20098 = v20097[v20196];
      int v20197 = (((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) * 2) + 1;
      int v20099 = v20097[v20197];
      int * v20100 = v20038->cache_vals;
      int v20199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v20078 + ((~(((v20080 ^ -1) | (-(v20080 ^ -1))) >> 31)) & 2)) - (v20081 + ((~(((v20082 ^ -1) | (-(v20082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v20100[v20199] = v20098;
      int * v20102 = v20038->cache_vals;
      int v20202 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 3) * 2)) + ((((v20078 + ((~(((v20080 ^ -1) | (-(v20080 ^ -1))) >> 31)) & 2)) - (v20081 + ((~(((v20082 ^ -1) | (-(v20082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v20102[v20202] = v20099;
      int * v20104 = v20038->cache_tags;
      int v20205 = (int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1);
      v20104[v20181] = v20205;
      int * v20106 = v20038->cache_dirty;
      v20106[v20181] = 0;
      int * v20108 = v20038->cache_age;
      v20108[v20181] = 1;
      int * v20110 = v20038->cache_age;
      int v20111 = v20110[v20181];
      int v20112 = v20110[v20155];
      int v20211 = v20112 + ((int)((unsigned int)(v20112 - v20111) >> 31));
      v20110[v20155] = v20211;
      int * v20114 = v20038->cache_age;
      int v20115 = v20114[v20156];
      int v20213 = v20115 + ((int)((unsigned int)(v20115 - v20111) >> 31));
      v20114[v20156] = v20213;
      int * v20117 = v20038->cache_age;
      v20117[v20181] = 0;
      v20120 = v20181;
    }
    int * v20121 = v20038->cache_vals;
    int v20216 = v20120 * 2;
    int v20122 = v20121[v20216];
    int v20217 = (v20120 * 2) + 1;
    int v20123 = v20121[v20217];
    int v20218 = (((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v20062 + ((~(((v20064 ^ -1) | (-(v20064 ^ -1))) >> 31)) & 2)) - (v20065 + ((~(((v20066 ^ -1) | (-(v20066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v20121[v20218] = v20122;
    int * v20125 = v20038->cache_vals;
    int v20221 = ((((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v20062 + ((~(((v20064 ^ -1) | (-(v20064 ^ -1))) >> 31)) & 2)) - (v20065 + ((~(((v20066 ^ -1) | (-(v20066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v20125[v20221] = v20123;
    int * v20127 = v20038->cache_tags;
    int v20224 = ((((int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1)) & 1) * 2) + ((((v20062 + ((~(((v20064 ^ -1) | (-(v20064 ^ -1))) >> 31)) & 2)) - (v20065 + ((~(((v20066 ^ -1) | (-(v20066 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v20225 = (int)((unsigned int)((int)((unsigned int)(v20042 + 48) >> 2)) >> 1);
    v20127[v20224] = v20225;
    int * v20129 = v20038->cache_dirty;
    v20129[v20224] = 0;
    int * v20131 = v20038->cache_age;
    v20131[v20224] = 1;
    int * v20133 = v20038->cache_age;
    int v20134 = v20133[v20224];
    int v20135 = v20133[v20153];
    int v20231 = v20135 + ((int)((unsigned int)(v20135 - v20134) >> 31));
    v20133[v20153] = v20231;
    int * v20137 = v20038->cache_age;
    int v20138 = v20137[v20154];
    int v20233 = v20138 + ((int)((unsigned int)(v20138 - v20134) >> 31));
    v20137[v20154] = v20233;
    int * v20140 = v20038->cache_age;
    v20140[v20224] = 0;
    v20143 = v20224;
  }
  int v20236 = (v20143 * 2) + (((int)((unsigned int)(v20042 + 48) >> 2)) & 1);
  int v20144 = v20050[v20236];
  int * v20145 = v20038->regs;
  v20145[26] = v20144;
  struct StateT * v20147 = slot_274(v20038);
  return v20147;
}

struct StateT * slot_69(struct StateT * v11509) {
  int v11510 = v11509->timer;
  int v11518 = v11510 + 1;
  v11509->timer = v11518;
  int * v11512 = v11509->regs;
  int v11513 = v11512[1];
  int v11514 = v11512[18];
  int v11522 = v11513 ^ v11514;
  v11512[1] = v11522;
  struct StateT * v11516 = slot_70(v11509);
  return v11516;
}

struct StateT * slot_202(struct StateT * v21891) {
  int v21892 = v21891->timer;
  int v21899 = v21892 + 1;
  v21891->timer = v21899;
  int * v21894 = v21891->regs;
  int v21895 = v21894[6];
  int v21902 = v21895 << 18;
  v21894[6] = v21902;
  struct StateT * v21897 = slot_203(v21891);
  return v21897;
}

struct StateT * slot_230(struct StateT * v11273) {
  int v11274 = v11273->timer;
  int v11282 = v11274 + 1;
  v11273->timer = v11282;
  int * v11276 = v11273->regs;
  int v11277 = v11276[17];
  int v11278 = v11276[30];
  int v11286 = v11277 + v11278;
  v11276[17] = v11286;
  struct StateT * v11280 = slot_231(v11273);
  return v11280;
}

struct StateT * slot_188(struct StateT * v21670) {
  int v21671 = v21670->timer;
  int v21679 = v21671 + 1;
  v21670->timer = v21679;
  int * v21673 = v21670->regs;
  int v21674 = v21673[12];
  int v21675 = v21673[15];
  int v21683 = v21674 ^ v21675;
  v21673[12] = v21683;
  struct StateT * v21677 = slot_189(v21670);
  return v21677;
}

struct StateT * slot_138(struct StateT * v20891) {
  int v20892 = v20891->timer;
  int v20899 = v20892 + 1;
  v20891->timer = v20899;
  int * v20894 = v20891->regs;
  int v20895 = v20894[11];
  int v20903 = (int)((unsigned int)v20895 >> 25);
  v20894[5] = v20903;
  struct StateT * v20897 = slot_139(v20891);
  return v20897;
}

struct StateT * slot_186(struct StateT * v21638) {
  int v21639 = v21638->timer;
  int v21647 = v21639 + 1;
  v21638->timer = v21647;
  int * v21641 = v21638->regs;
  int v21642 = v21641[8];
  int v21643 = v21641[9];
  int v21651 = v21642 | v21643;
  v21641[8] = v21651;
  struct StateT * v21645 = slot_187(v21638);
  return v21645;
}

struct StateT * slot_102(struct StateT * v18263) {
  int v18264 = v18263->timer;
  int v18271 = v18264 + 1;
  v18263->timer = v18271;
  int * v18266 = v18263->regs;
  int v18267 = v18266[9];
  int v18274 = v18267 << 13;
  v18266[9] = v18274;
  struct StateT * v18269 = slot_103(v18263);
  return v18269;
}

struct StateT * slot_145(struct StateT * v20996) {
  int v20997 = v20996->timer;
  int v21004 = v20997 + 1;
  v20996->timer = v21004;
  int * v20999 = v20996->regs;
  int v21000 = v20999[17];
  int v21007 = v21000 << 7;
  v20999[17] = v21007;
  struct StateT * v21002 = slot_146(v20996);
  return v21002;
}

struct StateT * slot_110(struct StateT * v20021) {
  int v20022 = v20021->timer;
  int v20030 = v20022 + 1;
  v20021->timer = v20030;
  int * v20024 = v20021->regs;
  int v20025 = v20024[17];
  int v20026 = v20024[6];
  int v20035 = v20025 ^ v20026;
  v20024[8] = v20035;
  struct StateT * v20028 = slot_111(v20021);
  return v20028;
}

struct StateT * slot_196(struct StateT * v21801) {
  int v21802 = v21801->timer;
  int v21809 = v21802 + 1;
  v21801->timer = v21809;
  int * v21804 = v21801->regs;
  int v21805 = v21804[11];
  int v21812 = v21805 << 18;
  v21804[11] = v21812;
  struct StateT * v21807 = slot_197(v21801);
  return v21807;
}

struct StateT * slot_208(struct StateT * v21982) {
  int v21983 = v21982->timer;
  int v21991 = v21983 + 1;
  v21982->timer = v21991;
  int * v21985 = v21982->regs;
  int v21986 = v21985[20];
  int v21987 = v21985[15];
  int v21996 = v21986 ^ v21987;
  v21985[11] = v21996;
  struct StateT * v21989 = slot_209(v21982);
  return v21989;
}

struct StateT * slot_172(struct StateT * v21423) {
  int v21424 = v21423->timer;
  int v21432 = v21424 + 1;
  v21423->timer = v21432;
  int * v21426 = v21423->regs;
  int v21427 = v21426[25];
  int v21428 = v21426[5];
  int v21437 = v21427 + v21428;
  v21426[15] = v21437;
  struct StateT * v21430 = slot_173(v21423);
  return v21430;
}

struct StateT * slot_131(struct StateT * v20778) {
  int v20779 = v20778->timer;
  int v20787 = v20779 + 1;
  v20778->timer = v20787;
  int * v20781 = v20778->regs;
  int v20782 = v20781[21];
  int v20783 = v20781[14];
  int v20792 = v20782 + v20783;
  v20781[15] = v20792;
  struct StateT * v20785 = slot_132(v20778);
  return v20785;
}

struct StateT * slot_8(struct StateT * v2217) {
  int v2218 = v2217->timer;
  int v2388 = v2218 + 1;
  v2217->timer = v2388;
  int * v2220 = v2217->regs;
  int v2221 = v2220[2];
  int v2222 = v2220[22];
  int * v2223 = v2217->cache_tags;
  int v2393 = (((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2;
  int v2224 = v2223[v2393];
  int v2394 = ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2225 = v2223[v2394];
  int v2395 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2);
  int v2226 = v2223[v2395];
  int v2396 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2227 = v2223[v2396];
  int v2228 = v2217->timer;
  int v2397 = v2228 + ((100 ^ (((~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2224 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2224 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v2225 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2225 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2217->timer = v2397;
  bool v2398 = !(((~(((v2224 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2224 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v2225 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2225 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31))) == 0);
  int v2322;
  if (v2398) {
    int * v2230 = v2217->cache_age;
    int v2400 = ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2) + ((~(((v2225 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2225 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) & 1);
    int v2231 = v2230[v2400];
    int v2232 = v2230[v2393];
    int v2401 = v2232 + ((int)((unsigned int)(v2232 - v2231) >> 31));
    v2230[v2393] = v2401;
    int * v2234 = v2217->cache_age;
    int v2235 = v2234[v2394];
    int v2403 = v2235 + ((int)((unsigned int)(v2235 - v2231) >> 31));
    v2234[v2394] = v2403;
    int * v2237 = v2217->cache_age;
    v2237[v2400] = 0;
    v2322 = v2400;
  } else {
    int * v2240 = v2217->cache_age;
    int v2407 = (((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2;
    int v2241 = v2240[v2407];
    int * v2242 = v2217->cache_tags;
    int v2243 = v2242[v2407];
    int v2244 = v2240[v2394];
    int v2245 = v2242[v2394];
    bool v2409 = !(((~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31))) == 0);
    int v2299;
    if (v2409) {
      int * v2246 = v2217->cache_age;
      int v2411 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2227 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) & 1);
      int v2247 = v2246[v2411];
      int v2248 = v2246[v2395];
      int v2412 = v2248 + ((int)((unsigned int)(v2248 - v2247) >> 31));
      v2246[v2395] = v2412;
      int * v2250 = v2217->cache_age;
      int v2251 = v2250[v2396];
      int v2414 = v2251 + ((int)((unsigned int)(v2251 - v2247) >> 31));
      v2250[v2396] = v2414;
      int * v2253 = v2217->cache_age;
      v2253[v2411] = 0;
      v2299 = v2411;
    } else {
      int * v2256 = v2217->cache_age;
      int v2418 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2);
      int v2257 = v2256[v2418];
      int * v2258 = v2217->cache_tags;
      int v2259 = v2258[v2418];
      int v2260 = v2256[v2396];
      int v2261 = v2258[v2396];
      int * v2262 = v2217->cache_dirty;
      int v2421 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2263 = v2262[v2421];
      bool v2422 = !(v2263 == 0);
      if (v2422) {
        int * v2264 = v2217->cache_tags;
        int v2265 = v2264[v2421];
        int * v2266 = v2217->cache_vals;
        int v2425 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2267 = v2266[v2425];
        int v2426 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2268 = v2266[v2426];
        int * v2269 = v2217->mem;
        int v2428 = v2265 * 2;
        v2269[v2428] = v2267;
        int * v2271 = v2217->mem;
        int v2431 = (v2265 * 2) + 1;
        v2271[v2431] = v2268;
        ;
      } else {
        ;
      }
      int * v2276 = v2217->mem;
      int v2436 = ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) * 2;
      int v2277 = v2276[v2436];
      int v2437 = (((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) * 2) + 1;
      int v2278 = v2276[v2437];
      int * v2279 = v2217->cache_vals;
      int v2439 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2279[v2439] = v2277;
      int * v2281 = v2217->cache_vals;
      int v2442 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2281[v2442] = v2278;
      int * v2283 = v2217->cache_tags;
      int v2445 = (int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1);
      v2283[v2421] = v2445;
      int * v2285 = v2217->cache_dirty;
      v2285[v2421] = 0;
      int * v2287 = v2217->cache_age;
      v2287[v2421] = 1;
      int * v2289 = v2217->cache_age;
      int v2290 = v2289[v2421];
      int v2291 = v2289[v2395];
      int v2451 = v2291 + ((int)((unsigned int)(v2291 - v2290) >> 31));
      v2289[v2395] = v2451;
      int * v2293 = v2217->cache_age;
      int v2294 = v2293[v2396];
      int v2453 = v2294 + ((int)((unsigned int)(v2294 - v2290) >> 31));
      v2293[v2396] = v2453;
      int * v2296 = v2217->cache_age;
      v2296[v2421] = 0;
      v2299 = v2421;
    }
    int * v2300 = v2217->cache_vals;
    int v2456 = v2299 * 2;
    int v2301 = v2300[v2456];
    int v2457 = (v2299 * 2) + 1;
    int v2302 = v2300[v2457];
    int v2458 = (((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2) + ((((v2241 + ((~(((v2243 ^ -1) | (-(v2243 ^ -1))) >> 31)) & 2)) - (v2244 + ((~(((v2245 ^ -1) | (-(v2245 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2300[v2458] = v2301;
    int * v2304 = v2217->cache_vals;
    int v2461 = ((((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2) + ((((v2241 + ((~(((v2243 ^ -1) | (-(v2243 ^ -1))) >> 31)) & 2)) - (v2244 + ((~(((v2245 ^ -1) | (-(v2245 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2304[v2461] = v2302;
    int * v2306 = v2217->cache_tags;
    int v2464 = ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 1) * 2) + ((((v2241 + ((~(((v2243 ^ -1) | (-(v2243 ^ -1))) >> 31)) & 2)) - (v2244 + ((~(((v2245 ^ -1) | (-(v2245 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2465 = (int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1);
    v2306[v2464] = v2465;
    int * v2308 = v2217->cache_dirty;
    v2308[v2464] = 0;
    int * v2310 = v2217->cache_age;
    v2310[v2464] = 1;
    int * v2312 = v2217->cache_age;
    int v2313 = v2312[v2464];
    int v2314 = v2312[v2393];
    int v2471 = v2314 + ((int)((unsigned int)(v2314 - v2313) >> 31));
    v2312[v2393] = v2471;
    int * v2316 = v2217->cache_age;
    int v2317 = v2316[v2394];
    int v2473 = v2317 + ((int)((unsigned int)(v2317 - v2313) >> 31));
    v2316[v2394] = v2473;
    int * v2319 = v2217->cache_age;
    v2319[v2464] = 0;
    v2322 = v2464;
  }
  int * v2323 = v2217->cache_vals;
  int v2476 = (v2322 * 2) + (((int)((unsigned int)(v2221 + 64) >> 2)) & 1);
  v2323[v2476] = v2222;
  int * v2325 = v2217->cache_tags;
  int v2326 = v2325[v2395];
  int v2327 = v2325[v2396];
  bool v2479 = !(((~(((v2326 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2326 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) | (~(((v2327 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2327 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31))) == 0);
  int v2381;
  if (v2479) {
    int * v2328 = v2217->cache_age;
    int v2481 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2327 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))) | (-(v2327 ^ ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1))))) >> 31)) & 1);
    int v2329 = v2328[v2481];
    int v2330 = v2328[v2395];
    int v2482 = v2330 + ((int)((unsigned int)(v2330 - v2329) >> 31));
    v2328[v2395] = v2482;
    int * v2332 = v2217->cache_age;
    int v2333 = v2332[v2396];
    int v2484 = v2333 + ((int)((unsigned int)(v2333 - v2329) >> 31));
    v2332[v2396] = v2484;
    int * v2335 = v2217->cache_age;
    v2335[v2481] = 0;
    v2381 = v2481;
  } else {
    int * v2338 = v2217->cache_age;
    int v2488 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2);
    int v2339 = v2338[v2488];
    int * v2340 = v2217->cache_tags;
    int v2341 = v2340[v2488];
    int v2342 = v2338[v2396];
    int v2343 = v2340[v2396];
    int * v2344 = v2217->cache_dirty;
    int v2491 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2339 + ((~(((v2341 ^ -1) | (-(v2341 ^ -1))) >> 31)) & 2)) - (v2342 + ((~(((v2343 ^ -1) | (-(v2343 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2345 = v2344[v2491];
    bool v2492 = !(v2345 == 0);
    if (v2492) {
      int * v2346 = v2217->cache_tags;
      int v2347 = v2346[v2491];
      int * v2348 = v2217->cache_vals;
      int v2495 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2339 + ((~(((v2341 ^ -1) | (-(v2341 ^ -1))) >> 31)) & 2)) - (v2342 + ((~(((v2343 ^ -1) | (-(v2343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2349 = v2348[v2495];
      int v2496 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2339 + ((~(((v2341 ^ -1) | (-(v2341 ^ -1))) >> 31)) & 2)) - (v2342 + ((~(((v2343 ^ -1) | (-(v2343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2350 = v2348[v2496];
      int * v2351 = v2217->mem;
      int v2498 = v2347 * 2;
      v2351[v2498] = v2349;
      int * v2353 = v2217->mem;
      int v2501 = (v2347 * 2) + 1;
      v2353[v2501] = v2350;
      ;
    } else {
      ;
    }
    int * v2358 = v2217->mem;
    int v2506 = ((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) * 2;
    int v2359 = v2358[v2506];
    int v2507 = (((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) * 2) + 1;
    int v2360 = v2358[v2507];
    int * v2361 = v2217->cache_vals;
    int v2509 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2339 + ((~(((v2341 ^ -1) | (-(v2341 ^ -1))) >> 31)) & 2)) - (v2342 + ((~(((v2343 ^ -1) | (-(v2343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2361[v2509] = v2359;
    int * v2363 = v2217->cache_vals;
    int v2512 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1)) & 3) * 2)) + ((((v2339 + ((~(((v2341 ^ -1) | (-(v2341 ^ -1))) >> 31)) & 2)) - (v2342 + ((~(((v2343 ^ -1) | (-(v2343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2363[v2512] = v2360;
    int * v2365 = v2217->cache_tags;
    int v2515 = (int)((unsigned int)((int)((unsigned int)(v2221 + 64) >> 2)) >> 1);
    v2365[v2491] = v2515;
    int * v2367 = v2217->cache_dirty;
    v2367[v2491] = 0;
    int * v2369 = v2217->cache_age;
    v2369[v2491] = 1;
    int * v2371 = v2217->cache_age;
    int v2372 = v2371[v2491];
    int v2373 = v2371[v2395];
    int v2521 = v2373 + ((int)((unsigned int)(v2373 - v2372) >> 31));
    v2371[v2395] = v2521;
    int * v2375 = v2217->cache_age;
    int v2376 = v2375[v2396];
    int v2523 = v2376 + ((int)((unsigned int)(v2376 - v2372) >> 31));
    v2375[v2396] = v2523;
    int * v2378 = v2217->cache_age;
    v2378[v2491] = 0;
    v2381 = v2491;
  }
  int * v2382 = v2217->cache_vals;
  int v2526 = (v2381 * 2) + (((int)((unsigned int)(v2221 + 64) >> 2)) & 1);
  v2382[v2526] = v2222;
  int * v2384 = v2217->cache_dirty;
  v2384[v2381] = 1;
  struct StateT * v2386 = slot_9(v2217);
  return v2386;
}

struct StateT * slot_180(struct StateT * v21548) {
  int v21549 = v21548->timer;
  int v21557 = v21549 + 1;
  v21548->timer = v21557;
  int * v21551 = v21548->regs;
  int v21552 = v21551[15];
  int v21553 = v21551[9];
  int v21561 = v21552 | v21553;
  v21551[15] = v21561;
  struct StateT * v21555 = slot_181(v21548);
  return v21555;
}

struct StateT * slot_203(struct StateT * v21905) {
  int v21906 = v21905->timer;
  int v21914 = v21906 + 1;
  v21905->timer = v21914;
  int * v21908 = v21905->regs;
  int v21909 = v21908[6];
  int v21910 = v21908[9];
  int v21918 = v21909 | v21910;
  v21908[6] = v21918;
  struct StateT * v21912 = slot_204(v21905);
  return v21912;
}

struct StateT * slot_190(struct StateT * v21702) {
  int v21703 = v21702->timer;
  int v21711 = v21703 + 1;
  v21702->timer = v21711;
  int * v21705 = v21702->regs;
  int v21706 = v21705[1];
  int v21707 = v21705[8];
  int v21715 = v21706 ^ v21707;
  v21705[1] = v21715;
  struct StateT * v21709 = slot_191(v21702);
  return v21709;
}

struct StateT * slot_157(struct StateT * v21191) {
  int v21192 = v21191->timer;
  int v21200 = v21192 + 1;
  v21191->timer = v21200;
  int * v21194 = v21191->regs;
  int v21195 = v21194[11];
  int v21196 = v21194[9];
  int v21204 = v21195 | v21196;
  v21194[11] = v21204;
  struct StateT * v21198 = slot_158(v21191);
  return v21198;
}

struct StateT * slot_242(struct StateT * v12208) {
  int v12209 = v12208->timer;
  int v12217 = v12209 + 1;
  v12208->timer = v12217;
  int * v12211 = v12208->regs;
  int v12212 = v12211[21];
  int v12213 = v12211[15];
  int v12221 = v12212 + v12213;
  v12211[15] = v12221;
  struct StateT * v12215 = slot_243(v12208);
  return v12215;
}

struct StateT * slot_200(struct StateT * v21860) {
  int v21861 = v21860->timer;
  int v21869 = v21861 + 1;
  v21860->timer = v21869;
  int * v21863 = v21860->regs;
  int v21864 = v21863[15];
  int v21865 = v21863[9];
  int v21873 = v21864 | v21865;
  v21863[15] = v21873;
  struct StateT * v21867 = slot_201(v21860);
  return v21867;
}

struct StateT * slot_243(struct StateT * v12240) {
  int v12241 = v12240->timer;
  int v12249 = v12241 + 1;
  v12240->timer = v12249;
  int * v12243 = v12240->regs;
  int v12244 = v12243[11];
  int v12245 = v12243[6];
  int v12253 = v12244 + v12245;
  v12243[11] = v12253;
  struct StateT * v12247 = slot_244(v12240);
  return v12247;
}

struct StateT * slot_173(struct StateT * v21440) {
  int v21441 = v21440->timer;
  int v21449 = v21441 + 1;
  v21440->timer = v21449;
  int * v21443 = v21440->regs;
  int v21444 = v21443[26];
  int v21445 = v21443[17];
  int v21454 = v21444 + v21445;
  v21443[6] = v21454;
  struct StateT * v21447 = slot_174(v21440);
  return v21447;
}

struct StateT * slot_149(struct StateT * v21060) {
  int v21061 = v21060->timer;
  int v21069 = v21061 + 1;
  v21060->timer = v21069;
  int * v21063 = v21060->regs;
  int v21064 = v21063[8];
  int v21065 = v21063[16];
  int v21074 = v21064 ^ v21065;
  v21063[17] = v21074;
  struct StateT * v21067 = slot_150(v21060);
  return v21067;
}

struct StateT * slot_5(struct StateT * v1272) {
  int v1273 = v1272->timer;
  int v1443 = v1273 + 1;
  v1272->timer = v1443;
  int * v1275 = v1272->regs;
  int v1276 = v1275[2];
  int v1277 = v1275[19];
  int * v1278 = v1272->cache_tags;
  int v1448 = (((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2;
  int v1279 = v1278[v1448];
  int v1449 = ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1280 = v1278[v1449];
  int v1450 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2);
  int v1281 = v1278[v1450];
  int v1451 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1282 = v1278[v1451];
  int v1283 = v1272->timer;
  int v1452 = v1283 + ((100 ^ (((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v1280 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1280 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1272->timer = v1452;
  bool v1453 = !(((~(((v1279 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1279 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v1280 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1280 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31))) == 0);
  int v1377;
  if (v1453) {
    int * v1285 = v1272->cache_age;
    int v1455 = ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2) + ((~(((v1280 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1280 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) & 1);
    int v1286 = v1285[v1455];
    int v1287 = v1285[v1448];
    int v1456 = v1287 + ((int)((unsigned int)(v1287 - v1286) >> 31));
    v1285[v1448] = v1456;
    int * v1289 = v1272->cache_age;
    int v1290 = v1289[v1449];
    int v1458 = v1290 + ((int)((unsigned int)(v1290 - v1286) >> 31));
    v1289[v1449] = v1458;
    int * v1292 = v1272->cache_age;
    v1292[v1455] = 0;
    v1377 = v1455;
  } else {
    int * v1295 = v1272->cache_age;
    int v1462 = (((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2;
    int v1296 = v1295[v1462];
    int * v1297 = v1272->cache_tags;
    int v1298 = v1297[v1462];
    int v1299 = v1295[v1449];
    int v1300 = v1297[v1449];
    bool v1464 = !(((~(((v1281 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1281 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31))) == 0);
    int v1354;
    if (v1464) {
      int * v1301 = v1272->cache_age;
      int v1466 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1282 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) & 1);
      int v1302 = v1301[v1466];
      int v1303 = v1301[v1450];
      int v1467 = v1303 + ((int)((unsigned int)(v1303 - v1302) >> 31));
      v1301[v1450] = v1467;
      int * v1305 = v1272->cache_age;
      int v1306 = v1305[v1451];
      int v1469 = v1306 + ((int)((unsigned int)(v1306 - v1302) >> 31));
      v1305[v1451] = v1469;
      int * v1308 = v1272->cache_age;
      v1308[v1466] = 0;
      v1354 = v1466;
    } else {
      int * v1311 = v1272->cache_age;
      int v1473 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2);
      int v1312 = v1311[v1473];
      int * v1313 = v1272->cache_tags;
      int v1314 = v1313[v1473];
      int v1315 = v1311[v1451];
      int v1316 = v1313[v1451];
      int * v1317 = v1272->cache_dirty;
      int v1476 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2)) - (v1315 + ((~(((v1316 ^ -1) | (-(v1316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1318 = v1317[v1476];
      bool v1477 = !(v1318 == 0);
      if (v1477) {
        int * v1319 = v1272->cache_tags;
        int v1320 = v1319[v1476];
        int * v1321 = v1272->cache_vals;
        int v1480 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2)) - (v1315 + ((~(((v1316 ^ -1) | (-(v1316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1322 = v1321[v1480];
        int v1481 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2)) - (v1315 + ((~(((v1316 ^ -1) | (-(v1316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1323 = v1321[v1481];
        int * v1324 = v1272->mem;
        int v1483 = v1320 * 2;
        v1324[v1483] = v1322;
        int * v1326 = v1272->mem;
        int v1486 = (v1320 * 2) + 1;
        v1326[v1486] = v1323;
        ;
      } else {
        ;
      }
      int * v1331 = v1272->mem;
      int v1491 = ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) * 2;
      int v1332 = v1331[v1491];
      int v1492 = (((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) * 2) + 1;
      int v1333 = v1331[v1492];
      int * v1334 = v1272->cache_vals;
      int v1494 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2)) - (v1315 + ((~(((v1316 ^ -1) | (-(v1316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1334[v1494] = v1332;
      int * v1336 = v1272->cache_vals;
      int v1497 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1312 + ((~(((v1314 ^ -1) | (-(v1314 ^ -1))) >> 31)) & 2)) - (v1315 + ((~(((v1316 ^ -1) | (-(v1316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1336[v1497] = v1333;
      int * v1338 = v1272->cache_tags;
      int v1500 = (int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1);
      v1338[v1476] = v1500;
      int * v1340 = v1272->cache_dirty;
      v1340[v1476] = 0;
      int * v1342 = v1272->cache_age;
      v1342[v1476] = 1;
      int * v1344 = v1272->cache_age;
      int v1345 = v1344[v1476];
      int v1346 = v1344[v1450];
      int v1506 = v1346 + ((int)((unsigned int)(v1346 - v1345) >> 31));
      v1344[v1450] = v1506;
      int * v1348 = v1272->cache_age;
      int v1349 = v1348[v1451];
      int v1508 = v1349 + ((int)((unsigned int)(v1349 - v1345) >> 31));
      v1348[v1451] = v1508;
      int * v1351 = v1272->cache_age;
      v1351[v1476] = 0;
      v1354 = v1476;
    }
    int * v1355 = v1272->cache_vals;
    int v1511 = v1354 * 2;
    int v1356 = v1355[v1511];
    int v1512 = (v1354 * 2) + 1;
    int v1357 = v1355[v1512];
    int v1513 = (((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1355[v1513] = v1356;
    int * v1359 = v1272->cache_vals;
    int v1516 = ((((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1359[v1516] = v1357;
    int * v1361 = v1272->cache_tags;
    int v1519 = ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 1) * 2) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1520 = (int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1);
    v1361[v1519] = v1520;
    int * v1363 = v1272->cache_dirty;
    v1363[v1519] = 0;
    int * v1365 = v1272->cache_age;
    v1365[v1519] = 1;
    int * v1367 = v1272->cache_age;
    int v1368 = v1367[v1519];
    int v1369 = v1367[v1448];
    int v1526 = v1369 + ((int)((unsigned int)(v1369 - v1368) >> 31));
    v1367[v1448] = v1526;
    int * v1371 = v1272->cache_age;
    int v1372 = v1371[v1449];
    int v1528 = v1372 + ((int)((unsigned int)(v1372 - v1368) >> 31));
    v1371[v1449] = v1528;
    int * v1374 = v1272->cache_age;
    v1374[v1519] = 0;
    v1377 = v1519;
  }
  int * v1378 = v1272->cache_vals;
  int v1531 = (v1377 * 2) + (((int)((unsigned int)(v1276 + 76) >> 2)) & 1);
  v1378[v1531] = v1277;
  int * v1380 = v1272->cache_tags;
  int v1381 = v1380[v1450];
  int v1382 = v1380[v1451];
  bool v1534 = !(((~(((v1381 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1381 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) | (~(((v1382 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1382 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31))) == 0);
  int v1436;
  if (v1534) {
    int * v1383 = v1272->cache_age;
    int v1536 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1382 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))) | (-(v1382 ^ ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1))))) >> 31)) & 1);
    int v1384 = v1383[v1536];
    int v1385 = v1383[v1450];
    int v1537 = v1385 + ((int)((unsigned int)(v1385 - v1384) >> 31));
    v1383[v1450] = v1537;
    int * v1387 = v1272->cache_age;
    int v1388 = v1387[v1451];
    int v1539 = v1388 + ((int)((unsigned int)(v1388 - v1384) >> 31));
    v1387[v1451] = v1539;
    int * v1390 = v1272->cache_age;
    v1390[v1536] = 0;
    v1436 = v1536;
  } else {
    int * v1393 = v1272->cache_age;
    int v1543 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2);
    int v1394 = v1393[v1543];
    int * v1395 = v1272->cache_tags;
    int v1396 = v1395[v1543];
    int v1397 = v1393[v1451];
    int v1398 = v1395[v1451];
    int * v1399 = v1272->cache_dirty;
    int v1546 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1400 = v1399[v1546];
    bool v1547 = !(v1400 == 0);
    if (v1547) {
      int * v1401 = v1272->cache_tags;
      int v1402 = v1401[v1546];
      int * v1403 = v1272->cache_vals;
      int v1550 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1404 = v1403[v1550];
      int v1551 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1405 = v1403[v1551];
      int * v1406 = v1272->mem;
      int v1553 = v1402 * 2;
      v1406[v1553] = v1404;
      int * v1408 = v1272->mem;
      int v1556 = (v1402 * 2) + 1;
      v1408[v1556] = v1405;
      ;
    } else {
      ;
    }
    int * v1413 = v1272->mem;
    int v1561 = ((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) * 2;
    int v1414 = v1413[v1561];
    int v1562 = (((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) * 2) + 1;
    int v1415 = v1413[v1562];
    int * v1416 = v1272->cache_vals;
    int v1564 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1416[v1564] = v1414;
    int * v1418 = v1272->cache_vals;
    int v1567 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1)) & 3) * 2)) + ((((v1394 + ((~(((v1396 ^ -1) | (-(v1396 ^ -1))) >> 31)) & 2)) - (v1397 + ((~(((v1398 ^ -1) | (-(v1398 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1418[v1567] = v1415;
    int * v1420 = v1272->cache_tags;
    int v1570 = (int)((unsigned int)((int)((unsigned int)(v1276 + 76) >> 2)) >> 1);
    v1420[v1546] = v1570;
    int * v1422 = v1272->cache_dirty;
    v1422[v1546] = 0;
    int * v1424 = v1272->cache_age;
    v1424[v1546] = 1;
    int * v1426 = v1272->cache_age;
    int v1427 = v1426[v1546];
    int v1428 = v1426[v1450];
    int v1576 = v1428 + ((int)((unsigned int)(v1428 - v1427) >> 31));
    v1426[v1450] = v1576;
    int * v1430 = v1272->cache_age;
    int v1431 = v1430[v1451];
    int v1578 = v1431 + ((int)((unsigned int)(v1431 - v1427) >> 31));
    v1430[v1451] = v1578;
    int * v1433 = v1272->cache_age;
    v1433[v1546] = 0;
    v1436 = v1546;
  }
  int * v1437 = v1272->cache_vals;
  int v1581 = (v1436 * 2) + (((int)((unsigned int)(v1276 + 76) >> 2)) & 1);
  v1437[v1581] = v1277;
  int * v1439 = v1272->cache_dirty;
  v1439[v1436] = 1;
  struct StateT * v1441 = slot_6(v1272);
  return v1441;
}

struct StateT * slot_104(struct StateT * v18701) {
  int v18702 = v18701->timer;
  int v18709 = v18702 + 1;
  v18701->timer = v18709;
  int * v18704 = v18701->regs;
  int v18705 = v18704[18];
  int v18713 = (int)((unsigned int)v18705 >> 19);
  v18704[9] = v18713;
  struct StateT * v18707 = slot_105(v18701);
  return v18707;
}

struct StateT * slot_235(struct StateT * v11811) {
  int v11812 = v11811->timer;
  int v11922 = v11812 + 1;
  v11811->timer = v11922;
  int * v11814 = v11811->regs;
  int v11815 = v11814[2];
  int * v11816 = v11811->cache_tags;
  int v11926 = (((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2;
  int v11817 = v11816[v11926];
  int v11927 = ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11818 = v11816[v11927];
  int v11928 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2);
  int v11819 = v11816[v11928];
  int v11929 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11820 = v11816[v11929];
  int v11821 = v11811->timer;
  int v11930 = v11821 + ((100 ^ (((~(((v11819 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11819 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11817 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11817 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11818 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11818 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11819 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11819 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11811->timer = v11930;
  int * v11823 = v11811->cache_vals;
  bool v11931 = !(((~(((v11817 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11817 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11818 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11818 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v11916;
  if (v11931) {
    int * v11824 = v11811->cache_age;
    int v11933 = ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v11818 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11818 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v11825 = v11824[v11933];
    int v11826 = v11824[v11926];
    int v11934 = v11826 + ((int)((unsigned int)(v11826 - v11825) >> 31));
    v11824[v11926] = v11934;
    int * v11828 = v11811->cache_age;
    int v11829 = v11828[v11927];
    int v11936 = v11829 + ((int)((unsigned int)(v11829 - v11825) >> 31));
    v11828[v11927] = v11936;
    int * v11831 = v11811->cache_age;
    v11831[v11933] = 0;
    v11916 = v11933;
  } else {
    int * v11834 = v11811->cache_age;
    int v11940 = (((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2;
    int v11835 = v11834[v11940];
    int * v11836 = v11811->cache_tags;
    int v11837 = v11836[v11940];
    int v11838 = v11834[v11927];
    int v11839 = v11836[v11927];
    bool v11942 = !(((~(((v11819 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11819 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v11893;
    if (v11942) {
      int * v11840 = v11811->cache_age;
      int v11944 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))) | (-(v11820 ^ ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v11841 = v11840[v11944];
      int v11842 = v11840[v11928];
      int v11945 = v11842 + ((int)((unsigned int)(v11842 - v11841) >> 31));
      v11840[v11928] = v11945;
      int * v11844 = v11811->cache_age;
      int v11845 = v11844[v11929];
      int v11947 = v11845 + ((int)((unsigned int)(v11845 - v11841) >> 31));
      v11844[v11929] = v11947;
      int * v11847 = v11811->cache_age;
      v11847[v11944] = 0;
      v11893 = v11944;
    } else {
      int * v11850 = v11811->cache_age;
      int v11951 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2);
      int v11851 = v11850[v11951];
      int * v11852 = v11811->cache_tags;
      int v11853 = v11852[v11951];
      int v11854 = v11850[v11929];
      int v11855 = v11852[v11929];
      int * v11856 = v11811->cache_dirty;
      int v11954 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11851 + ((~(((v11853 ^ -1) | (-(v11853 ^ -1))) >> 31)) & 2)) - (v11854 + ((~(((v11855 ^ -1) | (-(v11855 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11857 = v11856[v11954];
      bool v11955 = !(v11857 == 0);
      if (v11955) {
        int * v11858 = v11811->cache_tags;
        int v11859 = v11858[v11954];
        int * v11860 = v11811->cache_vals;
        int v11958 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11851 + ((~(((v11853 ^ -1) | (-(v11853 ^ -1))) >> 31)) & 2)) - (v11854 + ((~(((v11855 ^ -1) | (-(v11855 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11861 = v11860[v11958];
        int v11959 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11851 + ((~(((v11853 ^ -1) | (-(v11853 ^ -1))) >> 31)) & 2)) - (v11854 + ((~(((v11855 ^ -1) | (-(v11855 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11862 = v11860[v11959];
        int * v11863 = v11811->mem;
        int v11961 = v11859 * 2;
        v11863[v11961] = v11861;
        int * v11865 = v11811->mem;
        int v11964 = (v11859 * 2) + 1;
        v11865[v11964] = v11862;
        ;
      } else {
        ;
      }
      int * v11870 = v11811->mem;
      int v11969 = ((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) * 2;
      int v11871 = v11870[v11969];
      int v11970 = (((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) * 2) + 1;
      int v11872 = v11870[v11970];
      int * v11873 = v11811->cache_vals;
      int v11972 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11851 + ((~(((v11853 ^ -1) | (-(v11853 ^ -1))) >> 31)) & 2)) - (v11854 + ((~(((v11855 ^ -1) | (-(v11855 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11873[v11972] = v11871;
      int * v11875 = v11811->cache_vals;
      int v11975 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11851 + ((~(((v11853 ^ -1) | (-(v11853 ^ -1))) >> 31)) & 2)) - (v11854 + ((~(((v11855 ^ -1) | (-(v11855 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11875[v11975] = v11872;
      int * v11877 = v11811->cache_tags;
      int v11978 = (int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1);
      v11877[v11954] = v11978;
      int * v11879 = v11811->cache_dirty;
      v11879[v11954] = 0;
      int * v11881 = v11811->cache_age;
      v11881[v11954] = 1;
      int * v11883 = v11811->cache_age;
      int v11884 = v11883[v11954];
      int v11885 = v11883[v11928];
      int v11984 = v11885 + ((int)((unsigned int)(v11885 - v11884) >> 31));
      v11883[v11928] = v11984;
      int * v11887 = v11811->cache_age;
      int v11888 = v11887[v11929];
      int v11986 = v11888 + ((int)((unsigned int)(v11888 - v11884) >> 31));
      v11887[v11929] = v11986;
      int * v11890 = v11811->cache_age;
      v11890[v11954] = 0;
      v11893 = v11954;
    }
    int * v11894 = v11811->cache_vals;
    int v11989 = v11893 * 2;
    int v11895 = v11894[v11989];
    int v11990 = (v11893 * 2) + 1;
    int v11896 = v11894[v11990];
    int v11991 = (((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11835 + ((~(((v11837 ^ -1) | (-(v11837 ^ -1))) >> 31)) & 2)) - (v11838 + ((~(((v11839 ^ -1) | (-(v11839 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11894[v11991] = v11895;
    int * v11898 = v11811->cache_vals;
    int v11994 = ((((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11835 + ((~(((v11837 ^ -1) | (-(v11837 ^ -1))) >> 31)) & 2)) - (v11838 + ((~(((v11839 ^ -1) | (-(v11839 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11898[v11994] = v11896;
    int * v11900 = v11811->cache_tags;
    int v11997 = ((((int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11835 + ((~(((v11837 ^ -1) | (-(v11837 ^ -1))) >> 31)) & 2)) - (v11838 + ((~(((v11839 ^ -1) | (-(v11839 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11998 = (int)((unsigned int)((int)((unsigned int)(v11815 + 40) >> 2)) >> 1);
    v11900[v11997] = v11998;
    int * v11902 = v11811->cache_dirty;
    v11902[v11997] = 0;
    int * v11904 = v11811->cache_age;
    v11904[v11997] = 1;
    int * v11906 = v11811->cache_age;
    int v11907 = v11906[v11997];
    int v11908 = v11906[v11926];
    int v12004 = v11908 + ((int)((unsigned int)(v11908 - v11907) >> 31));
    v11906[v11926] = v12004;
    int * v11910 = v11811->cache_age;
    int v11911 = v11910[v11927];
    int v12006 = v11911 + ((int)((unsigned int)(v11911 - v11907) >> 31));
    v11910[v11927] = v12006;
    int * v11913 = v11811->cache_age;
    v11913[v11997] = 0;
    v11916 = v11997;
  }
  int v12009 = (v11916 * 2) + (((int)((unsigned int)(v11815 + 40) >> 2)) & 1);
  int v11917 = v11823[v12009];
  int * v11918 = v11811->regs;
  v11918[30] = v11917;
  struct StateT * v11920 = slot_236(v11811);
  return v11920;
}

struct StateT * slot_275(struct StateT * v20480) {
  int v20481 = v20480->timer;
  int v20488 = v20481 + 1;
  v20480->timer = v20488;
  int * v20483 = v20480->regs;
  int v20484 = v20483[2];
  int v20491 = v20484 + 96;
  v20483[2] = v20491;
  struct StateT * v20486 = slot_276(v20480);
  return v20486;
}

struct StateT * slot_54(struct StateT * v9730) {
  int v9731 = v9730->timer;
  int v9739 = v9731 + 1;
  v9730->timer = v9739;
  int * v9733 = v9730->regs;
  int v9734 = v9733[22];
  int v9735 = v9733[17];
  int v9744 = v9734 + v9735;
  v9733[8] = v9744;
  struct StateT * v9737 = slot_55(v9730);
  return v9737;
}

struct StateT * slot_26(struct StateT * v6364) {
  int v6365 = v6364->timer;
  int v6475 = v6365 + 1;
  v6364->timer = v6475;
  int * v6367 = v6364->regs;
  int v6368 = v6367[11];
  int * v6369 = v6364->cache_tags;
  int v6479 = (((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2;
  int v6370 = v6369[v6479];
  int v6480 = ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6371 = v6369[v6480];
  int v6481 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2);
  int v6372 = v6369[v6481];
  int v6482 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6373 = v6369[v6482];
  int v6374 = v6364->timer;
  int v6483 = v6374 + ((100 ^ (((~(((v6372 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6372 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6370 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6370 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6371 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6371 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6372 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6372 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6364->timer = v6483;
  int * v6376 = v6364->cache_vals;
  bool v6484 = !(((~(((v6370 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6370 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6371 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6371 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v6469;
  if (v6484) {
    int * v6377 = v6364->cache_age;
    int v6486 = ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v6371 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6371 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v6378 = v6377[v6486];
    int v6379 = v6377[v6479];
    int v6487 = v6379 + ((int)((unsigned int)(v6379 - v6378) >> 31));
    v6377[v6479] = v6487;
    int * v6381 = v6364->cache_age;
    int v6382 = v6381[v6480];
    int v6489 = v6382 + ((int)((unsigned int)(v6382 - v6378) >> 31));
    v6381[v6480] = v6489;
    int * v6384 = v6364->cache_age;
    v6384[v6486] = 0;
    v6469 = v6486;
  } else {
    int * v6387 = v6364->cache_age;
    int v6493 = (((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2;
    int v6388 = v6387[v6493];
    int * v6389 = v6364->cache_tags;
    int v6390 = v6389[v6493];
    int v6391 = v6387[v6480];
    int v6392 = v6389[v6480];
    bool v6495 = !(((~(((v6372 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6372 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v6446;
    if (v6495) {
      int * v6393 = v6364->cache_age;
      int v6497 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))) | (-(v6373 ^ ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v6394 = v6393[v6497];
      int v6395 = v6393[v6481];
      int v6498 = v6395 + ((int)((unsigned int)(v6395 - v6394) >> 31));
      v6393[v6481] = v6498;
      int * v6397 = v6364->cache_age;
      int v6398 = v6397[v6482];
      int v6500 = v6398 + ((int)((unsigned int)(v6398 - v6394) >> 31));
      v6397[v6482] = v6500;
      int * v6400 = v6364->cache_age;
      v6400[v6497] = 0;
      v6446 = v6497;
    } else {
      int * v6403 = v6364->cache_age;
      int v6504 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2);
      int v6404 = v6403[v6504];
      int * v6405 = v6364->cache_tags;
      int v6406 = v6405[v6504];
      int v6407 = v6403[v6482];
      int v6408 = v6405[v6482];
      int * v6409 = v6364->cache_dirty;
      int v6507 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6404 + ((~(((v6406 ^ -1) | (-(v6406 ^ -1))) >> 31)) & 2)) - (v6407 + ((~(((v6408 ^ -1) | (-(v6408 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6410 = v6409[v6507];
      bool v6508 = !(v6410 == 0);
      if (v6508) {
        int * v6411 = v6364->cache_tags;
        int v6412 = v6411[v6507];
        int * v6413 = v6364->cache_vals;
        int v6511 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6404 + ((~(((v6406 ^ -1) | (-(v6406 ^ -1))) >> 31)) & 2)) - (v6407 + ((~(((v6408 ^ -1) | (-(v6408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6414 = v6413[v6511];
        int v6512 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6404 + ((~(((v6406 ^ -1) | (-(v6406 ^ -1))) >> 31)) & 2)) - (v6407 + ((~(((v6408 ^ -1) | (-(v6408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6415 = v6413[v6512];
        int * v6416 = v6364->mem;
        int v6514 = v6412 * 2;
        v6416[v6514] = v6414;
        int * v6418 = v6364->mem;
        int v6517 = (v6412 * 2) + 1;
        v6418[v6517] = v6415;
        ;
      } else {
        ;
      }
      int * v6423 = v6364->mem;
      int v6522 = ((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) * 2;
      int v6424 = v6423[v6522];
      int v6523 = (((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) * 2) + 1;
      int v6425 = v6423[v6523];
      int * v6426 = v6364->cache_vals;
      int v6525 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6404 + ((~(((v6406 ^ -1) | (-(v6406 ^ -1))) >> 31)) & 2)) - (v6407 + ((~(((v6408 ^ -1) | (-(v6408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6426[v6525] = v6424;
      int * v6428 = v6364->cache_vals;
      int v6528 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6404 + ((~(((v6406 ^ -1) | (-(v6406 ^ -1))) >> 31)) & 2)) - (v6407 + ((~(((v6408 ^ -1) | (-(v6408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6428[v6528] = v6425;
      int * v6430 = v6364->cache_tags;
      int v6531 = (int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1);
      v6430[v6507] = v6531;
      int * v6432 = v6364->cache_dirty;
      v6432[v6507] = 0;
      int * v6434 = v6364->cache_age;
      v6434[v6507] = 1;
      int * v6436 = v6364->cache_age;
      int v6437 = v6436[v6507];
      int v6438 = v6436[v6481];
      int v6537 = v6438 + ((int)((unsigned int)(v6438 - v6437) >> 31));
      v6436[v6481] = v6537;
      int * v6440 = v6364->cache_age;
      int v6441 = v6440[v6482];
      int v6539 = v6441 + ((int)((unsigned int)(v6441 - v6437) >> 31));
      v6440[v6482] = v6539;
      int * v6443 = v6364->cache_age;
      v6443[v6507] = 0;
      v6446 = v6507;
    }
    int * v6447 = v6364->cache_vals;
    int v6542 = v6446 * 2;
    int v6448 = v6447[v6542];
    int v6543 = (v6446 * 2) + 1;
    int v6449 = v6447[v6543];
    int v6544 = (((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v6388 + ((~(((v6390 ^ -1) | (-(v6390 ^ -1))) >> 31)) & 2)) - (v6391 + ((~(((v6392 ^ -1) | (-(v6392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6447[v6544] = v6448;
    int * v6451 = v6364->cache_vals;
    int v6547 = ((((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v6388 + ((~(((v6390 ^ -1) | (-(v6390 ^ -1))) >> 31)) & 2)) - (v6391 + ((~(((v6392 ^ -1) | (-(v6392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6451[v6547] = v6449;
    int * v6453 = v6364->cache_tags;
    int v6550 = ((((int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v6388 + ((~(((v6390 ^ -1) | (-(v6390 ^ -1))) >> 31)) & 2)) - (v6391 + ((~(((v6392 ^ -1) | (-(v6392 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6551 = (int)((unsigned int)((int)((unsigned int)(v6368 + 12) >> 2)) >> 1);
    v6453[v6550] = v6551;
    int * v6455 = v6364->cache_dirty;
    v6455[v6550] = 0;
    int * v6457 = v6364->cache_age;
    v6457[v6550] = 1;
    int * v6459 = v6364->cache_age;
    int v6460 = v6459[v6550];
    int v6461 = v6459[v6479];
    int v6557 = v6461 + ((int)((unsigned int)(v6461 - v6460) >> 31));
    v6459[v6479] = v6557;
    int * v6463 = v6364->cache_age;
    int v6464 = v6463[v6480];
    int v6559 = v6464 + ((int)((unsigned int)(v6464 - v6460) >> 31));
    v6463[v6480] = v6559;
    int * v6466 = v6364->cache_age;
    v6466[v6550] = 0;
    v6469 = v6550;
  }
  int v6562 = (v6469 * 2) + (((int)((unsigned int)(v6368 + 12) >> 2)) & 1);
  int v6470 = v6376[v6562];
  int * v6471 = v6364->regs;
  v6471[15] = v6470;
  struct StateT * v6473 = slot_27(v6364);
  return v6473;
}

struct StateT * slot_206(struct StateT * v21950) {
  int v21951 = v21950->timer;
  int v21959 = v21951 + 1;
  v21950->timer = v21959;
  int * v21953 = v21950->regs;
  int v21954 = v21953[8];
  int v21955 = v21953[9];
  int v21963 = v21954 | v21955;
  v21953[8] = v21963;
  struct StateT * v21957 = slot_207(v21950);
  return v21957;
}

struct StateT * slot_227(struct StateT * v10994) {
  int v10995 = v10994->timer;
  int v11003 = v10995 + 1;
  v10994->timer = v11003;
  int * v10997 = v10994->regs;
  int v10998 = v10997[13];
  int v10999 = v10997[7];
  int v11007 = v10998 + v10999;
  v10997[13] = v11007;
  struct StateT * v11001 = slot_228(v10994);
  return v11001;
}

struct StateT * slot_169(struct StateT * v21374) {
  int v21375 = v21374->timer;
  int v21383 = v21375 + 1;
  v21374->timer = v21383;
  int * v21377 = v21374->regs;
  int v21378 = v21377[26];
  int v21379 = v21377[6];
  int v21387 = v21378 ^ v21379;
  v21377[26] = v21387;
  struct StateT * v21381 = slot_170(v21374);
  return v21381;
}

struct StateT * slot_253(struct StateT * v14647) {
  int v14648 = v14647->timer;
  int v14818 = v14648 + 1;
  v14647->timer = v14818;
  int * v14650 = v14647->regs;
  int v14651 = v14650[10];
  int v14652 = v14650[25];
  int * v14653 = v14647->cache_tags;
  int v14823 = (((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2;
  int v14654 = v14653[v14823];
  int v14824 = ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14655 = v14653[v14824];
  int v14825 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2);
  int v14656 = v14653[v14825];
  int v14826 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14657 = v14653[v14826];
  int v14658 = v14647->timer;
  int v14827 = v14658 + ((100 ^ (((~(((v14656 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14656 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14654 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14654 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14655 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14655 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14656 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14656 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14647->timer = v14827;
  bool v14828 = !(((~(((v14654 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14654 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14655 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14655 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v14752;
  if (v14828) {
    int * v14660 = v14647->cache_age;
    int v14830 = ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v14655 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14655 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v14661 = v14660[v14830];
    int v14662 = v14660[v14823];
    int v14831 = v14662 + ((int)((unsigned int)(v14662 - v14661) >> 31));
    v14660[v14823] = v14831;
    int * v14664 = v14647->cache_age;
    int v14665 = v14664[v14824];
    int v14833 = v14665 + ((int)((unsigned int)(v14665 - v14661) >> 31));
    v14664[v14824] = v14833;
    int * v14667 = v14647->cache_age;
    v14667[v14830] = 0;
    v14752 = v14830;
  } else {
    int * v14670 = v14647->cache_age;
    int v14837 = (((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2;
    int v14671 = v14670[v14837];
    int * v14672 = v14647->cache_tags;
    int v14673 = v14672[v14837];
    int v14674 = v14670[v14824];
    int v14675 = v14672[v14824];
    bool v14839 = !(((~(((v14656 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14656 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v14729;
    if (v14839) {
      int * v14676 = v14647->cache_age;
      int v14841 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14657 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v14677 = v14676[v14841];
      int v14678 = v14676[v14825];
      int v14842 = v14678 + ((int)((unsigned int)(v14678 - v14677) >> 31));
      v14676[v14825] = v14842;
      int * v14680 = v14647->cache_age;
      int v14681 = v14680[v14826];
      int v14844 = v14681 + ((int)((unsigned int)(v14681 - v14677) >> 31));
      v14680[v14826] = v14844;
      int * v14683 = v14647->cache_age;
      v14683[v14841] = 0;
      v14729 = v14841;
    } else {
      int * v14686 = v14647->cache_age;
      int v14848 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2);
      int v14687 = v14686[v14848];
      int * v14688 = v14647->cache_tags;
      int v14689 = v14688[v14848];
      int v14690 = v14686[v14826];
      int v14691 = v14688[v14826];
      int * v14692 = v14647->cache_dirty;
      int v14851 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14687 + ((~(((v14689 ^ -1) | (-(v14689 ^ -1))) >> 31)) & 2)) - (v14690 + ((~(((v14691 ^ -1) | (-(v14691 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14693 = v14692[v14851];
      bool v14852 = !(v14693 == 0);
      if (v14852) {
        int * v14694 = v14647->cache_tags;
        int v14695 = v14694[v14851];
        int * v14696 = v14647->cache_vals;
        int v14855 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14687 + ((~(((v14689 ^ -1) | (-(v14689 ^ -1))) >> 31)) & 2)) - (v14690 + ((~(((v14691 ^ -1) | (-(v14691 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14697 = v14696[v14855];
        int v14856 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14687 + ((~(((v14689 ^ -1) | (-(v14689 ^ -1))) >> 31)) & 2)) - (v14690 + ((~(((v14691 ^ -1) | (-(v14691 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14698 = v14696[v14856];
        int * v14699 = v14647->mem;
        int v14858 = v14695 * 2;
        v14699[v14858] = v14697;
        int * v14701 = v14647->mem;
        int v14861 = (v14695 * 2) + 1;
        v14701[v14861] = v14698;
        ;
      } else {
        ;
      }
      int * v14706 = v14647->mem;
      int v14866 = ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) * 2;
      int v14707 = v14706[v14866];
      int v14867 = (((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) * 2) + 1;
      int v14708 = v14706[v14867];
      int * v14709 = v14647->cache_vals;
      int v14869 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14687 + ((~(((v14689 ^ -1) | (-(v14689 ^ -1))) >> 31)) & 2)) - (v14690 + ((~(((v14691 ^ -1) | (-(v14691 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14709[v14869] = v14707;
      int * v14711 = v14647->cache_vals;
      int v14872 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14687 + ((~(((v14689 ^ -1) | (-(v14689 ^ -1))) >> 31)) & 2)) - (v14690 + ((~(((v14691 ^ -1) | (-(v14691 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14711[v14872] = v14708;
      int * v14713 = v14647->cache_tags;
      int v14875 = (int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1);
      v14713[v14851] = v14875;
      int * v14715 = v14647->cache_dirty;
      v14715[v14851] = 0;
      int * v14717 = v14647->cache_age;
      v14717[v14851] = 1;
      int * v14719 = v14647->cache_age;
      int v14720 = v14719[v14851];
      int v14721 = v14719[v14825];
      int v14881 = v14721 + ((int)((unsigned int)(v14721 - v14720) >> 31));
      v14719[v14825] = v14881;
      int * v14723 = v14647->cache_age;
      int v14724 = v14723[v14826];
      int v14883 = v14724 + ((int)((unsigned int)(v14724 - v14720) >> 31));
      v14723[v14826] = v14883;
      int * v14726 = v14647->cache_age;
      v14726[v14851] = 0;
      v14729 = v14851;
    }
    int * v14730 = v14647->cache_vals;
    int v14886 = v14729 * 2;
    int v14731 = v14730[v14886];
    int v14887 = (v14729 * 2) + 1;
    int v14732 = v14730[v14887];
    int v14888 = (((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v14671 + ((~(((v14673 ^ -1) | (-(v14673 ^ -1))) >> 31)) & 2)) - (v14674 + ((~(((v14675 ^ -1) | (-(v14675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14730[v14888] = v14731;
    int * v14734 = v14647->cache_vals;
    int v14891 = ((((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v14671 + ((~(((v14673 ^ -1) | (-(v14673 ^ -1))) >> 31)) & 2)) - (v14674 + ((~(((v14675 ^ -1) | (-(v14675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14734[v14891] = v14732;
    int * v14736 = v14647->cache_tags;
    int v14894 = ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v14671 + ((~(((v14673 ^ -1) | (-(v14673 ^ -1))) >> 31)) & 2)) - (v14674 + ((~(((v14675 ^ -1) | (-(v14675 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14895 = (int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1);
    v14736[v14894] = v14895;
    int * v14738 = v14647->cache_dirty;
    v14738[v14894] = 0;
    int * v14740 = v14647->cache_age;
    v14740[v14894] = 1;
    int * v14742 = v14647->cache_age;
    int v14743 = v14742[v14894];
    int v14744 = v14742[v14823];
    int v14901 = v14744 + ((int)((unsigned int)(v14744 - v14743) >> 31));
    v14742[v14823] = v14901;
    int * v14746 = v14647->cache_age;
    int v14747 = v14746[v14824];
    int v14903 = v14747 + ((int)((unsigned int)(v14747 - v14743) >> 31));
    v14746[v14824] = v14903;
    int * v14749 = v14647->cache_age;
    v14749[v14894] = 0;
    v14752 = v14894;
  }
  int * v14753 = v14647->cache_vals;
  int v14906 = (v14752 * 2) + (((int)((unsigned int)(v14651 + 28) >> 2)) & 1);
  v14753[v14906] = v14652;
  int * v14755 = v14647->cache_tags;
  int v14756 = v14755[v14825];
  int v14757 = v14755[v14826];
  bool v14909 = !(((~(((v14756 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14756 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14757 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14757 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v14811;
  if (v14909) {
    int * v14758 = v14647->cache_age;
    int v14911 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14757 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))) | (-(v14757 ^ ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v14759 = v14758[v14911];
    int v14760 = v14758[v14825];
    int v14912 = v14760 + ((int)((unsigned int)(v14760 - v14759) >> 31));
    v14758[v14825] = v14912;
    int * v14762 = v14647->cache_age;
    int v14763 = v14762[v14826];
    int v14914 = v14763 + ((int)((unsigned int)(v14763 - v14759) >> 31));
    v14762[v14826] = v14914;
    int * v14765 = v14647->cache_age;
    v14765[v14911] = 0;
    v14811 = v14911;
  } else {
    int * v14768 = v14647->cache_age;
    int v14918 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2);
    int v14769 = v14768[v14918];
    int * v14770 = v14647->cache_tags;
    int v14771 = v14770[v14918];
    int v14772 = v14768[v14826];
    int v14773 = v14770[v14826];
    int * v14774 = v14647->cache_dirty;
    int v14921 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14769 + ((~(((v14771 ^ -1) | (-(v14771 ^ -1))) >> 31)) & 2)) - (v14772 + ((~(((v14773 ^ -1) | (-(v14773 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14775 = v14774[v14921];
    bool v14922 = !(v14775 == 0);
    if (v14922) {
      int * v14776 = v14647->cache_tags;
      int v14777 = v14776[v14921];
      int * v14778 = v14647->cache_vals;
      int v14925 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14769 + ((~(((v14771 ^ -1) | (-(v14771 ^ -1))) >> 31)) & 2)) - (v14772 + ((~(((v14773 ^ -1) | (-(v14773 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v14779 = v14778[v14925];
      int v14926 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14769 + ((~(((v14771 ^ -1) | (-(v14771 ^ -1))) >> 31)) & 2)) - (v14772 + ((~(((v14773 ^ -1) | (-(v14773 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v14780 = v14778[v14926];
      int * v14781 = v14647->mem;
      int v14928 = v14777 * 2;
      v14781[v14928] = v14779;
      int * v14783 = v14647->mem;
      int v14931 = (v14777 * 2) + 1;
      v14783[v14931] = v14780;
      ;
    } else {
      ;
    }
    int * v14788 = v14647->mem;
    int v14936 = ((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) * 2;
    int v14789 = v14788[v14936];
    int v14937 = (((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) * 2) + 1;
    int v14790 = v14788[v14937];
    int * v14791 = v14647->cache_vals;
    int v14939 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14769 + ((~(((v14771 ^ -1) | (-(v14771 ^ -1))) >> 31)) & 2)) - (v14772 + ((~(((v14773 ^ -1) | (-(v14773 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14791[v14939] = v14789;
    int * v14793 = v14647->cache_vals;
    int v14942 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14769 + ((~(((v14771 ^ -1) | (-(v14771 ^ -1))) >> 31)) & 2)) - (v14772 + ((~(((v14773 ^ -1) | (-(v14773 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14793[v14942] = v14790;
    int * v14795 = v14647->cache_tags;
    int v14945 = (int)((unsigned int)((int)((unsigned int)(v14651 + 28) >> 2)) >> 1);
    v14795[v14921] = v14945;
    int * v14797 = v14647->cache_dirty;
    v14797[v14921] = 0;
    int * v14799 = v14647->cache_age;
    v14799[v14921] = 1;
    int * v14801 = v14647->cache_age;
    int v14802 = v14801[v14921];
    int v14803 = v14801[v14825];
    int v14951 = v14803 + ((int)((unsigned int)(v14803 - v14802) >> 31));
    v14801[v14825] = v14951;
    int * v14805 = v14647->cache_age;
    int v14806 = v14805[v14826];
    int v14953 = v14806 + ((int)((unsigned int)(v14806 - v14802) >> 31));
    v14805[v14826] = v14953;
    int * v14808 = v14647->cache_age;
    v14808[v14921] = 0;
    v14811 = v14921;
  }
  int * v14812 = v14647->cache_vals;
  int v14956 = (v14811 * 2) + (((int)((unsigned int)(v14651 + 28) >> 2)) & 1);
  v14812[v14956] = v14652;
  int * v14814 = v14647->cache_dirty;
  v14814[v14811] = 1;
  struct StateT * v14816 = slot_254(v14647);
  return v14816;
}

struct StateT * slot_64(struct StateT * v10979) {
  int v10980 = v10979->timer;
  int v10987 = v10980 + 1;
  v10979->timer = v10987;
  int * v10982 = v10979->regs;
  int v10983 = v10982[8];
  int v10991 = (int)((unsigned int)v10983 >> 25);
  v10982[20] = v10991;
  struct StateT * v10985 = slot_65(v10979);
  return v10985;
}

struct StateT * slot_170(struct StateT * v21390) {
  int v21391 = v21390->timer;
  int v21399 = v21391 + 1;
  v21390->timer = v21399;
  int * v21393 = v21390->regs;
  int v21394 = v21393[24];
  int v21395 = v21393[8];
  int v21403 = v21394 ^ v21395;
  v21393[24] = v21403;
  struct StateT * v21397 = slot_171(v21390);
  return v21397;
}

struct StateT * slot_14(struct StateT * v4107) {
  int v4108 = v4107->timer;
  int v4114 = v4108 + 1;
  v4107->timer = v4114;
  int * v4110 = v4107->regs;
  v4110[30] = 0;
  struct StateT * v4112 = slot_15(v4107);
  return v4112;
}

struct StateT * slot_53(struct StateT * v9697) {
  int v9698 = v9697->timer;
  int v9706 = v9698 + 1;
  v9697->timer = v9706;
  int * v9700 = v9697->regs;
  int v9701 = v9700[19];
  int v9702 = v9700[5];
  int v9711 = v9701 + v9702;
  v9700[18] = v9711;
  struct StateT * v9704 = slot_54(v9697);
  return v9704;
}

struct StateT * slot_80(struct StateT * v12224) {
  int v12225 = v12224->timer;
  int v12233 = v12225 + 1;
  v12224->timer = v12233;
  int * v12227 = v12224->regs;
  int v12228 = v12227[8];
  int v12229 = v12227[20];
  int v12237 = v12228 | v12229;
  v12227[8] = v12237;
  struct StateT * v12231 = slot_81(v12224);
  return v12231;
}

struct StateT * slot_44(struct StateT * v9208) {
  int v9209 = v9208->timer;
  int v9216 = v9209 + 1;
  v9208->timer = v9216;
  int * v9211 = v9208->regs;
  int v9212 = v9211[6];
  v9211[12] = v9212;
  struct StateT * v9214 = slot_45(v9208);
  return v9214;
}

struct StateT * slot_261(struct StateT * v17291) {
  int v17292 = v17291->timer;
  int v17462 = v17292 + 1;
  v17291->timer = v17462;
  int * v17294 = v17291->regs;
  int v17295 = v17294[10];
  int v17296 = v17294[30];
  int * v17297 = v17291->cache_tags;
  int v17467 = (((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2;
  int v17298 = v17297[v17467];
  int v17468 = ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2) + 1;
  int v17299 = v17297[v17468];
  int v17469 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2);
  int v17300 = v17297[v17469];
  int v17470 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v17301 = v17297[v17470];
  int v17302 = v17291->timer;
  int v17471 = v17302 + ((100 ^ (((~(((v17300 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17300 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v17298 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17298 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v17299 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17299 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v17300 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17300 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31))) & 104)))));
  v17291->timer = v17471;
  bool v17472 = !(((~(((v17298 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17298 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v17299 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17299 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31))) == 0);
  int v17396;
  if (v17472) {
    int * v17304 = v17291->cache_age;
    int v17474 = ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2) + ((~(((v17299 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17299 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) & 1);
    int v17305 = v17304[v17474];
    int v17306 = v17304[v17467];
    int v17475 = v17306 + ((int)((unsigned int)(v17306 - v17305) >> 31));
    v17304[v17467] = v17475;
    int * v17308 = v17291->cache_age;
    int v17309 = v17308[v17468];
    int v17477 = v17309 + ((int)((unsigned int)(v17309 - v17305) >> 31));
    v17308[v17468] = v17477;
    int * v17311 = v17291->cache_age;
    v17311[v17474] = 0;
    v17396 = v17474;
  } else {
    int * v17314 = v17291->cache_age;
    int v17481 = (((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2;
    int v17315 = v17314[v17481];
    int * v17316 = v17291->cache_tags;
    int v17317 = v17316[v17481];
    int v17318 = v17314[v17468];
    int v17319 = v17316[v17468];
    bool v17483 = !(((~(((v17300 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17300 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31))) == 0);
    int v17373;
    if (v17483) {
      int * v17320 = v17291->cache_age;
      int v17485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17301 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) & 1);
      int v17321 = v17320[v17485];
      int v17322 = v17320[v17469];
      int v17486 = v17322 + ((int)((unsigned int)(v17322 - v17321) >> 31));
      v17320[v17469] = v17486;
      int * v17324 = v17291->cache_age;
      int v17325 = v17324[v17470];
      int v17488 = v17325 + ((int)((unsigned int)(v17325 - v17321) >> 31));
      v17324[v17470] = v17488;
      int * v17327 = v17291->cache_age;
      v17327[v17485] = 0;
      v17373 = v17485;
    } else {
      int * v17330 = v17291->cache_age;
      int v17492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2);
      int v17331 = v17330[v17492];
      int * v17332 = v17291->cache_tags;
      int v17333 = v17332[v17492];
      int v17334 = v17330[v17470];
      int v17335 = v17332[v17470];
      int * v17336 = v17291->cache_dirty;
      int v17495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17331 + ((~(((v17333 ^ -1) | (-(v17333 ^ -1))) >> 31)) & 2)) - (v17334 + ((~(((v17335 ^ -1) | (-(v17335 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v17337 = v17336[v17495];
      bool v17496 = !(v17337 == 0);
      if (v17496) {
        int * v17338 = v17291->cache_tags;
        int v17339 = v17338[v17495];
        int * v17340 = v17291->cache_vals;
        int v17499 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17331 + ((~(((v17333 ^ -1) | (-(v17333 ^ -1))) >> 31)) & 2)) - (v17334 + ((~(((v17335 ^ -1) | (-(v17335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v17341 = v17340[v17499];
        int v17500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17331 + ((~(((v17333 ^ -1) | (-(v17333 ^ -1))) >> 31)) & 2)) - (v17334 + ((~(((v17335 ^ -1) | (-(v17335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v17342 = v17340[v17500];
        int * v17343 = v17291->mem;
        int v17502 = v17339 * 2;
        v17343[v17502] = v17341;
        int * v17345 = v17291->mem;
        int v17505 = (v17339 * 2) + 1;
        v17345[v17505] = v17342;
        ;
      } else {
        ;
      }
      int * v17350 = v17291->mem;
      int v17510 = ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) * 2;
      int v17351 = v17350[v17510];
      int v17511 = (((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) * 2) + 1;
      int v17352 = v17350[v17511];
      int * v17353 = v17291->cache_vals;
      int v17513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17331 + ((~(((v17333 ^ -1) | (-(v17333 ^ -1))) >> 31)) & 2)) - (v17334 + ((~(((v17335 ^ -1) | (-(v17335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v17353[v17513] = v17351;
      int * v17355 = v17291->cache_vals;
      int v17516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17331 + ((~(((v17333 ^ -1) | (-(v17333 ^ -1))) >> 31)) & 2)) - (v17334 + ((~(((v17335 ^ -1) | (-(v17335 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v17355[v17516] = v17352;
      int * v17357 = v17291->cache_tags;
      int v17519 = (int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1);
      v17357[v17495] = v17519;
      int * v17359 = v17291->cache_dirty;
      v17359[v17495] = 0;
      int * v17361 = v17291->cache_age;
      v17361[v17495] = 1;
      int * v17363 = v17291->cache_age;
      int v17364 = v17363[v17495];
      int v17365 = v17363[v17469];
      int v17525 = v17365 + ((int)((unsigned int)(v17365 - v17364) >> 31));
      v17363[v17469] = v17525;
      int * v17367 = v17291->cache_age;
      int v17368 = v17367[v17470];
      int v17527 = v17368 + ((int)((unsigned int)(v17368 - v17364) >> 31));
      v17367[v17470] = v17527;
      int * v17370 = v17291->cache_age;
      v17370[v17495] = 0;
      v17373 = v17495;
    }
    int * v17374 = v17291->cache_vals;
    int v17530 = v17373 * 2;
    int v17375 = v17374[v17530];
    int v17531 = (v17373 * 2) + 1;
    int v17376 = v17374[v17531];
    int v17532 = (((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v17315 + ((~(((v17317 ^ -1) | (-(v17317 ^ -1))) >> 31)) & 2)) - (v17318 + ((~(((v17319 ^ -1) | (-(v17319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17374[v17532] = v17375;
    int * v17378 = v17291->cache_vals;
    int v17535 = ((((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v17315 + ((~(((v17317 ^ -1) | (-(v17317 ^ -1))) >> 31)) & 2)) - (v17318 + ((~(((v17319 ^ -1) | (-(v17319 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17378[v17535] = v17376;
    int * v17380 = v17291->cache_tags;
    int v17538 = ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 1) * 2) + ((((v17315 + ((~(((v17317 ^ -1) | (-(v17317 ^ -1))) >> 31)) & 2)) - (v17318 + ((~(((v17319 ^ -1) | (-(v17319 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17539 = (int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1);
    v17380[v17538] = v17539;
    int * v17382 = v17291->cache_dirty;
    v17382[v17538] = 0;
    int * v17384 = v17291->cache_age;
    v17384[v17538] = 1;
    int * v17386 = v17291->cache_age;
    int v17387 = v17386[v17538];
    int v17388 = v17386[v17467];
    int v17545 = v17388 + ((int)((unsigned int)(v17388 - v17387) >> 31));
    v17386[v17467] = v17545;
    int * v17390 = v17291->cache_age;
    int v17391 = v17390[v17468];
    int v17547 = v17391 + ((int)((unsigned int)(v17391 - v17387) >> 31));
    v17390[v17468] = v17547;
    int * v17393 = v17291->cache_age;
    v17393[v17538] = 0;
    v17396 = v17538;
  }
  int * v17397 = v17291->cache_vals;
  int v17550 = (v17396 * 2) + (((int)((unsigned int)(v17295 + 60) >> 2)) & 1);
  v17397[v17550] = v17296;
  int * v17399 = v17291->cache_tags;
  int v17400 = v17399[v17469];
  int v17401 = v17399[v17470];
  bool v17553 = !(((~(((v17400 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17400 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) | (~(((v17401 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17401 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31))) == 0);
  int v17455;
  if (v17553) {
    int * v17402 = v17291->cache_age;
    int v17555 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((~(((v17401 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))) | (-(v17401 ^ ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1))))) >> 31)) & 1);
    int v17403 = v17402[v17555];
    int v17404 = v17402[v17469];
    int v17556 = v17404 + ((int)((unsigned int)(v17404 - v17403) >> 31));
    v17402[v17469] = v17556;
    int * v17406 = v17291->cache_age;
    int v17407 = v17406[v17470];
    int v17558 = v17407 + ((int)((unsigned int)(v17407 - v17403) >> 31));
    v17406[v17470] = v17558;
    int * v17409 = v17291->cache_age;
    v17409[v17555] = 0;
    v17455 = v17555;
  } else {
    int * v17412 = v17291->cache_age;
    int v17562 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2);
    int v17413 = v17412[v17562];
    int * v17414 = v17291->cache_tags;
    int v17415 = v17414[v17562];
    int v17416 = v17412[v17470];
    int v17417 = v17414[v17470];
    int * v17418 = v17291->cache_dirty;
    int v17565 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17413 + ((~(((v17415 ^ -1) | (-(v17415 ^ -1))) >> 31)) & 2)) - (v17416 + ((~(((v17417 ^ -1) | (-(v17417 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v17419 = v17418[v17565];
    bool v17566 = !(v17419 == 0);
    if (v17566) {
      int * v17420 = v17291->cache_tags;
      int v17421 = v17420[v17565];
      int * v17422 = v17291->cache_vals;
      int v17569 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17413 + ((~(((v17415 ^ -1) | (-(v17415 ^ -1))) >> 31)) & 2)) - (v17416 + ((~(((v17417 ^ -1) | (-(v17417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v17423 = v17422[v17569];
      int v17570 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17413 + ((~(((v17415 ^ -1) | (-(v17415 ^ -1))) >> 31)) & 2)) - (v17416 + ((~(((v17417 ^ -1) | (-(v17417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v17424 = v17422[v17570];
      int * v17425 = v17291->mem;
      int v17572 = v17421 * 2;
      v17425[v17572] = v17423;
      int * v17427 = v17291->mem;
      int v17575 = (v17421 * 2) + 1;
      v17427[v17575] = v17424;
      ;
    } else {
      ;
    }
    int * v17432 = v17291->mem;
    int v17580 = ((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) * 2;
    int v17433 = v17432[v17580];
    int v17581 = (((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) * 2) + 1;
    int v17434 = v17432[v17581];
    int * v17435 = v17291->cache_vals;
    int v17583 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17413 + ((~(((v17415 ^ -1) | (-(v17415 ^ -1))) >> 31)) & 2)) - (v17416 + ((~(((v17417 ^ -1) | (-(v17417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v17435[v17583] = v17433;
    int * v17437 = v17291->cache_vals;
    int v17586 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1)) & 3) * 2)) + ((((v17413 + ((~(((v17415 ^ -1) | (-(v17415 ^ -1))) >> 31)) & 2)) - (v17416 + ((~(((v17417 ^ -1) | (-(v17417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v17437[v17586] = v17434;
    int * v17439 = v17291->cache_tags;
    int v17589 = (int)((unsigned int)((int)((unsigned int)(v17295 + 60) >> 2)) >> 1);
    v17439[v17565] = v17589;
    int * v17441 = v17291->cache_dirty;
    v17441[v17565] = 0;
    int * v17443 = v17291->cache_age;
    v17443[v17565] = 1;
    int * v17445 = v17291->cache_age;
    int v17446 = v17445[v17565];
    int v17447 = v17445[v17469];
    int v17595 = v17447 + ((int)((unsigned int)(v17447 - v17446) >> 31));
    v17445[v17469] = v17595;
    int * v17449 = v17291->cache_age;
    int v17450 = v17449[v17470];
    int v17597 = v17450 + ((int)((unsigned int)(v17450 - v17446) >> 31));
    v17449[v17470] = v17597;
    int * v17452 = v17291->cache_age;
    v17452[v17565] = 0;
    v17455 = v17565;
  }
  int * v17456 = v17291->cache_vals;
  int v17600 = (v17455 * 2) + (((int)((unsigned int)(v17295 + 60) >> 2)) & 1);
  v17456[v17600] = v17296;
  int * v17458 = v17291->cache_dirty;
  v17458[v17455] = 1;
  struct StateT * v17460 = slot_262(v17291);
  return v17460;
}

struct StateT * slot_137(struct StateT * v20875) {
  int v20876 = v20875->timer;
  int v20884 = v20876 + 1;
  v20875->timer = v20884;
  int * v20878 = v20875->regs;
  int v20879 = v20878[15];
  int v20880 = v20878[5];
  int v20888 = v20879 | v20880;
  v20878[15] = v20888;
  struct StateT * v20882 = slot_138(v20875);
  return v20882;
}

struct StateT * slot_122(struct StateT * v20638) {
  int v20639 = v20638->timer;
  int v20646 = v20639 + 1;
  v20638->timer = v20646;
  int * v20641 = v20638->regs;
  int v20642 = v20641[17];
  int v20649 = v20642 << 18;
  v20641[17] = v20649;
  struct StateT * v20644 = slot_123(v20638);
  return v20644;
}

struct StateT * slot_99(struct StateT * v17606) {
  int v17607 = v17606->timer;
  int v17614 = v17607 + 1;
  v17606->timer = v17614;
  int * v17609 = v17606->regs;
  int v17610 = v17609[8];
  int v17617 = v17610 << 13;
  v17609[8] = v17617;
  struct StateT * v17612 = slot_100(v17606);
  return v17612;
}

struct StateT * slot_179(struct StateT * v21534) {
  int v21535 = v21534->timer;
  int v21542 = v21535 + 1;
  v21534->timer = v21542;
  int * v21537 = v21534->regs;
  int v21538 = v21537[15];
  int v21545 = v21538 << 13;
  v21537[15] = v21545;
  struct StateT * v21540 = slot_180(v21534);
  return v21540;
}

struct StateT * slot_219(struct StateT * v9996) {
  int v9997 = v9996->timer;
  int v10003 = v9997 + 1;
  v9996->timer = v10003;
  int * v9999 = v9996->regs;
  v9999[6] = 857759744;
  struct StateT * v10001 = slot_220(v9996);
  return v10001;
}

struct StateT * slot_36(struct StateT * v6692) {
  int v6693 = v6692->timer;
  int v6863 = v6693 + 1;
  v6692->timer = v6863;
  int * v6695 = v6692->regs;
  int v6696 = v6695[2];
  int v6697 = v6695[26];
  int * v6698 = v6692->cache_tags;
  int v6868 = (((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2;
  int v6699 = v6698[v6868];
  int v6869 = ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6700 = v6698[v6869];
  int v6870 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2);
  int v6701 = v6698[v6870];
  int v6871 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6702 = v6698[v6871];
  int v6703 = v6692->timer;
  int v6872 = v6703 + ((100 ^ (((~(((v6701 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6701 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6699 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6699 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6700 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6700 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6701 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6701 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6692->timer = v6872;
  bool v6873 = !(((~(((v6699 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6699 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6700 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6700 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v6797;
  if (v6873) {
    int * v6705 = v6692->cache_age;
    int v6875 = ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v6700 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6700 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v6706 = v6705[v6875];
    int v6707 = v6705[v6868];
    int v6876 = v6707 + ((int)((unsigned int)(v6707 - v6706) >> 31));
    v6705[v6868] = v6876;
    int * v6709 = v6692->cache_age;
    int v6710 = v6709[v6869];
    int v6878 = v6710 + ((int)((unsigned int)(v6710 - v6706) >> 31));
    v6709[v6869] = v6878;
    int * v6712 = v6692->cache_age;
    v6712[v6875] = 0;
    v6797 = v6875;
  } else {
    int * v6715 = v6692->cache_age;
    int v6882 = (((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2;
    int v6716 = v6715[v6882];
    int * v6717 = v6692->cache_tags;
    int v6718 = v6717[v6882];
    int v6719 = v6715[v6869];
    int v6720 = v6717[v6869];
    bool v6884 = !(((~(((v6701 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6701 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v6774;
    if (v6884) {
      int * v6721 = v6692->cache_age;
      int v6886 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6702 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v6722 = v6721[v6886];
      int v6723 = v6721[v6870];
      int v6887 = v6723 + ((int)((unsigned int)(v6723 - v6722) >> 31));
      v6721[v6870] = v6887;
      int * v6725 = v6692->cache_age;
      int v6726 = v6725[v6871];
      int v6889 = v6726 + ((int)((unsigned int)(v6726 - v6722) >> 31));
      v6725[v6871] = v6889;
      int * v6728 = v6692->cache_age;
      v6728[v6886] = 0;
      v6774 = v6886;
    } else {
      int * v6731 = v6692->cache_age;
      int v6893 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2);
      int v6732 = v6731[v6893];
      int * v6733 = v6692->cache_tags;
      int v6734 = v6733[v6893];
      int v6735 = v6731[v6871];
      int v6736 = v6733[v6871];
      int * v6737 = v6692->cache_dirty;
      int v6896 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6732 + ((~(((v6734 ^ -1) | (-(v6734 ^ -1))) >> 31)) & 2)) - (v6735 + ((~(((v6736 ^ -1) | (-(v6736 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6738 = v6737[v6896];
      bool v6897 = !(v6738 == 0);
      if (v6897) {
        int * v6739 = v6692->cache_tags;
        int v6740 = v6739[v6896];
        int * v6741 = v6692->cache_vals;
        int v6900 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6732 + ((~(((v6734 ^ -1) | (-(v6734 ^ -1))) >> 31)) & 2)) - (v6735 + ((~(((v6736 ^ -1) | (-(v6736 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6742 = v6741[v6900];
        int v6901 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6732 + ((~(((v6734 ^ -1) | (-(v6734 ^ -1))) >> 31)) & 2)) - (v6735 + ((~(((v6736 ^ -1) | (-(v6736 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6743 = v6741[v6901];
        int * v6744 = v6692->mem;
        int v6903 = v6740 * 2;
        v6744[v6903] = v6742;
        int * v6746 = v6692->mem;
        int v6906 = (v6740 * 2) + 1;
        v6746[v6906] = v6743;
        ;
      } else {
        ;
      }
      int * v6751 = v6692->mem;
      int v6911 = ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) * 2;
      int v6752 = v6751[v6911];
      int v6912 = (((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) * 2) + 1;
      int v6753 = v6751[v6912];
      int * v6754 = v6692->cache_vals;
      int v6914 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6732 + ((~(((v6734 ^ -1) | (-(v6734 ^ -1))) >> 31)) & 2)) - (v6735 + ((~(((v6736 ^ -1) | (-(v6736 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6754[v6914] = v6752;
      int * v6756 = v6692->cache_vals;
      int v6917 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6732 + ((~(((v6734 ^ -1) | (-(v6734 ^ -1))) >> 31)) & 2)) - (v6735 + ((~(((v6736 ^ -1) | (-(v6736 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6756[v6917] = v6753;
      int * v6758 = v6692->cache_tags;
      int v6920 = (int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1);
      v6758[v6896] = v6920;
      int * v6760 = v6692->cache_dirty;
      v6760[v6896] = 0;
      int * v6762 = v6692->cache_age;
      v6762[v6896] = 1;
      int * v6764 = v6692->cache_age;
      int v6765 = v6764[v6896];
      int v6766 = v6764[v6870];
      int v6926 = v6766 + ((int)((unsigned int)(v6766 - v6765) >> 31));
      v6764[v6870] = v6926;
      int * v6768 = v6692->cache_age;
      int v6769 = v6768[v6871];
      int v6928 = v6769 + ((int)((unsigned int)(v6769 - v6765) >> 31));
      v6768[v6871] = v6928;
      int * v6771 = v6692->cache_age;
      v6771[v6896] = 0;
      v6774 = v6896;
    }
    int * v6775 = v6692->cache_vals;
    int v6931 = v6774 * 2;
    int v6776 = v6775[v6931];
    int v6932 = (v6774 * 2) + 1;
    int v6777 = v6775[v6932];
    int v6933 = (((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v6716 + ((~(((v6718 ^ -1) | (-(v6718 ^ -1))) >> 31)) & 2)) - (v6719 + ((~(((v6720 ^ -1) | (-(v6720 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6775[v6933] = v6776;
    int * v6779 = v6692->cache_vals;
    int v6936 = ((((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v6716 + ((~(((v6718 ^ -1) | (-(v6718 ^ -1))) >> 31)) & 2)) - (v6719 + ((~(((v6720 ^ -1) | (-(v6720 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6779[v6936] = v6777;
    int * v6781 = v6692->cache_tags;
    int v6939 = ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v6716 + ((~(((v6718 ^ -1) | (-(v6718 ^ -1))) >> 31)) & 2)) - (v6719 + ((~(((v6720 ^ -1) | (-(v6720 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6940 = (int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1);
    v6781[v6939] = v6940;
    int * v6783 = v6692->cache_dirty;
    v6783[v6939] = 0;
    int * v6785 = v6692->cache_age;
    v6785[v6939] = 1;
    int * v6787 = v6692->cache_age;
    int v6788 = v6787[v6939];
    int v6789 = v6787[v6868];
    int v6946 = v6789 + ((int)((unsigned int)(v6789 - v6788) >> 31));
    v6787[v6868] = v6946;
    int * v6791 = v6692->cache_age;
    int v6792 = v6791[v6869];
    int v6948 = v6792 + ((int)((unsigned int)(v6792 - v6788) >> 31));
    v6791[v6869] = v6948;
    int * v6794 = v6692->cache_age;
    v6794[v6939] = 0;
    v6797 = v6939;
  }
  int * v6798 = v6692->cache_vals;
  int v6951 = (v6797 * 2) + (((int)((unsigned int)(v6696 + 20) >> 2)) & 1);
  v6798[v6951] = v6697;
  int * v6800 = v6692->cache_tags;
  int v6801 = v6800[v6870];
  int v6802 = v6800[v6871];
  bool v6954 = !(((~(((v6801 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6801 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v6802 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6802 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v6856;
  if (v6954) {
    int * v6803 = v6692->cache_age;
    int v6956 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6802 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))) | (-(v6802 ^ ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v6804 = v6803[v6956];
    int v6805 = v6803[v6870];
    int v6957 = v6805 + ((int)((unsigned int)(v6805 - v6804) >> 31));
    v6803[v6870] = v6957;
    int * v6807 = v6692->cache_age;
    int v6808 = v6807[v6871];
    int v6959 = v6808 + ((int)((unsigned int)(v6808 - v6804) >> 31));
    v6807[v6871] = v6959;
    int * v6810 = v6692->cache_age;
    v6810[v6956] = 0;
    v6856 = v6956;
  } else {
    int * v6813 = v6692->cache_age;
    int v6963 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2);
    int v6814 = v6813[v6963];
    int * v6815 = v6692->cache_tags;
    int v6816 = v6815[v6963];
    int v6817 = v6813[v6871];
    int v6818 = v6815[v6871];
    int * v6819 = v6692->cache_dirty;
    int v6966 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6814 + ((~(((v6816 ^ -1) | (-(v6816 ^ -1))) >> 31)) & 2)) - (v6817 + ((~(((v6818 ^ -1) | (-(v6818 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6820 = v6819[v6966];
    bool v6967 = !(v6820 == 0);
    if (v6967) {
      int * v6821 = v6692->cache_tags;
      int v6822 = v6821[v6966];
      int * v6823 = v6692->cache_vals;
      int v6970 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6814 + ((~(((v6816 ^ -1) | (-(v6816 ^ -1))) >> 31)) & 2)) - (v6817 + ((~(((v6818 ^ -1) | (-(v6818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6824 = v6823[v6970];
      int v6971 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6814 + ((~(((v6816 ^ -1) | (-(v6816 ^ -1))) >> 31)) & 2)) - (v6817 + ((~(((v6818 ^ -1) | (-(v6818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6825 = v6823[v6971];
      int * v6826 = v6692->mem;
      int v6973 = v6822 * 2;
      v6826[v6973] = v6824;
      int * v6828 = v6692->mem;
      int v6976 = (v6822 * 2) + 1;
      v6828[v6976] = v6825;
      ;
    } else {
      ;
    }
    int * v6833 = v6692->mem;
    int v6981 = ((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) * 2;
    int v6834 = v6833[v6981];
    int v6982 = (((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) * 2) + 1;
    int v6835 = v6833[v6982];
    int * v6836 = v6692->cache_vals;
    int v6984 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6814 + ((~(((v6816 ^ -1) | (-(v6816 ^ -1))) >> 31)) & 2)) - (v6817 + ((~(((v6818 ^ -1) | (-(v6818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6836[v6984] = v6834;
    int * v6838 = v6692->cache_vals;
    int v6987 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v6814 + ((~(((v6816 ^ -1) | (-(v6816 ^ -1))) >> 31)) & 2)) - (v6817 + ((~(((v6818 ^ -1) | (-(v6818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6838[v6987] = v6835;
    int * v6840 = v6692->cache_tags;
    int v6990 = (int)((unsigned int)((int)((unsigned int)(v6696 + 20) >> 2)) >> 1);
    v6840[v6966] = v6990;
    int * v6842 = v6692->cache_dirty;
    v6842[v6966] = 0;
    int * v6844 = v6692->cache_age;
    v6844[v6966] = 1;
    int * v6846 = v6692->cache_age;
    int v6847 = v6846[v6966];
    int v6848 = v6846[v6870];
    int v6996 = v6848 + ((int)((unsigned int)(v6848 - v6847) >> 31));
    v6846[v6870] = v6996;
    int * v6850 = v6692->cache_age;
    int v6851 = v6850[v6871];
    int v6998 = v6851 + ((int)((unsigned int)(v6851 - v6847) >> 31));
    v6850[v6871] = v6998;
    int * v6853 = v6692->cache_age;
    v6853[v6966] = 0;
    v6856 = v6966;
  }
  int * v6857 = v6692->cache_vals;
  int v7001 = (v6856 * 2) + (((int)((unsigned int)(v6696 + 20) >> 2)) & 1);
  v6857[v7001] = v6697;
  int * v6859 = v6692->cache_dirty;
  v6859[v6856] = 1;
  struct StateT * v6861 = slot_37(v6692);
  return v6861;
}

struct StateT * slot_57(struct StateT * v10009) {
  int v10010 = v10009->timer;
  int v10018 = v10010 + 1;
  v10009->timer = v10018;
  int * v10012 = v10009->regs;
  int v10013 = v10012[15];
  int v10014 = v10012[9];
  int v10022 = v10013 | v10014;
  v10012[15] = v10022;
  struct StateT * v10016 = slot_58(v10009);
  return v10016;
}

struct StateT * slot_62(struct StateT * v10729) {
  int v10730 = v10729->timer;
  int v10737 = v10730 + 1;
  v10729->timer = v10737;
  int * v10732 = v10729->regs;
  int v10733 = v10732[18];
  int v10740 = v10733 << 7;
  v10732[18] = v10740;
  struct StateT * v10735 = slot_63(v10729);
  return v10735;
}

struct StateT * slot_22(struct StateT * v5548) {
  int v5549 = v5548->timer;
  int v5659 = v5549 + 1;
  v5548->timer = v5659;
  int * v5551 = v5548->regs;
  int v5552 = v5551[12];
  int * v5553 = v5548->cache_tags;
  int v5663 = (((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2;
  int v5554 = v5553[v5663];
  int v5664 = ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5555 = v5553[v5664];
  int v5665 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2);
  int v5556 = v5553[v5665];
  int v5666 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5557 = v5553[v5666];
  int v5558 = v5548->timer;
  int v5667 = v5558 + ((100 ^ (((~(((v5556 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5556 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5554 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5554 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5555 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5555 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5556 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5556 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5548->timer = v5667;
  int * v5560 = v5548->cache_vals;
  bool v5668 = !(((~(((v5554 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5554 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5555 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5555 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v5653;
  if (v5668) {
    int * v5561 = v5548->cache_age;
    int v5670 = ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v5555 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5555 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v5562 = v5561[v5670];
    int v5563 = v5561[v5663];
    int v5671 = v5563 + ((int)((unsigned int)(v5563 - v5562) >> 31));
    v5561[v5663] = v5671;
    int * v5565 = v5548->cache_age;
    int v5566 = v5565[v5664];
    int v5673 = v5566 + ((int)((unsigned int)(v5566 - v5562) >> 31));
    v5565[v5664] = v5673;
    int * v5568 = v5548->cache_age;
    v5568[v5670] = 0;
    v5653 = v5670;
  } else {
    int * v5571 = v5548->cache_age;
    int v5677 = (((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2;
    int v5572 = v5571[v5677];
    int * v5573 = v5548->cache_tags;
    int v5574 = v5573[v5677];
    int v5575 = v5571[v5664];
    int v5576 = v5573[v5664];
    bool v5679 = !(((~(((v5556 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5556 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v5630;
    if (v5679) {
      int * v5577 = v5548->cache_age;
      int v5681 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))) | (-(v5557 ^ ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v5578 = v5577[v5681];
      int v5579 = v5577[v5665];
      int v5682 = v5579 + ((int)((unsigned int)(v5579 - v5578) >> 31));
      v5577[v5665] = v5682;
      int * v5581 = v5548->cache_age;
      int v5582 = v5581[v5666];
      int v5684 = v5582 + ((int)((unsigned int)(v5582 - v5578) >> 31));
      v5581[v5666] = v5684;
      int * v5584 = v5548->cache_age;
      v5584[v5681] = 0;
      v5630 = v5681;
    } else {
      int * v5587 = v5548->cache_age;
      int v5688 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2);
      int v5588 = v5587[v5688];
      int * v5589 = v5548->cache_tags;
      int v5590 = v5589[v5688];
      int v5591 = v5587[v5666];
      int v5592 = v5589[v5666];
      int * v5593 = v5548->cache_dirty;
      int v5691 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5588 + ((~(((v5590 ^ -1) | (-(v5590 ^ -1))) >> 31)) & 2)) - (v5591 + ((~(((v5592 ^ -1) | (-(v5592 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5594 = v5593[v5691];
      bool v5692 = !(v5594 == 0);
      if (v5692) {
        int * v5595 = v5548->cache_tags;
        int v5596 = v5595[v5691];
        int * v5597 = v5548->cache_vals;
        int v5695 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5588 + ((~(((v5590 ^ -1) | (-(v5590 ^ -1))) >> 31)) & 2)) - (v5591 + ((~(((v5592 ^ -1) | (-(v5592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5598 = v5597[v5695];
        int v5696 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5588 + ((~(((v5590 ^ -1) | (-(v5590 ^ -1))) >> 31)) & 2)) - (v5591 + ((~(((v5592 ^ -1) | (-(v5592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5599 = v5597[v5696];
        int * v5600 = v5548->mem;
        int v5698 = v5596 * 2;
        v5600[v5698] = v5598;
        int * v5602 = v5548->mem;
        int v5701 = (v5596 * 2) + 1;
        v5602[v5701] = v5599;
        ;
      } else {
        ;
      }
      int * v5607 = v5548->mem;
      int v5706 = ((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) * 2;
      int v5608 = v5607[v5706];
      int v5707 = (((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) * 2) + 1;
      int v5609 = v5607[v5707];
      int * v5610 = v5548->cache_vals;
      int v5709 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5588 + ((~(((v5590 ^ -1) | (-(v5590 ^ -1))) >> 31)) & 2)) - (v5591 + ((~(((v5592 ^ -1) | (-(v5592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5610[v5709] = v5608;
      int * v5612 = v5548->cache_vals;
      int v5712 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5588 + ((~(((v5590 ^ -1) | (-(v5590 ^ -1))) >> 31)) & 2)) - (v5591 + ((~(((v5592 ^ -1) | (-(v5592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5612[v5712] = v5609;
      int * v5614 = v5548->cache_tags;
      int v5715 = (int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1);
      v5614[v5691] = v5715;
      int * v5616 = v5548->cache_dirty;
      v5616[v5691] = 0;
      int * v5618 = v5548->cache_age;
      v5618[v5691] = 1;
      int * v5620 = v5548->cache_age;
      int v5621 = v5620[v5691];
      int v5622 = v5620[v5665];
      int v5721 = v5622 + ((int)((unsigned int)(v5622 - v5621) >> 31));
      v5620[v5665] = v5721;
      int * v5624 = v5548->cache_age;
      int v5625 = v5624[v5666];
      int v5723 = v5625 + ((int)((unsigned int)(v5625 - v5621) >> 31));
      v5624[v5666] = v5723;
      int * v5627 = v5548->cache_age;
      v5627[v5691] = 0;
      v5630 = v5691;
    }
    int * v5631 = v5548->cache_vals;
    int v5726 = v5630 * 2;
    int v5632 = v5631[v5726];
    int v5727 = (v5630 * 2) + 1;
    int v5633 = v5631[v5727];
    int v5728 = (((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5572 + ((~(((v5574 ^ -1) | (-(v5574 ^ -1))) >> 31)) & 2)) - (v5575 + ((~(((v5576 ^ -1) | (-(v5576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5631[v5728] = v5632;
    int * v5635 = v5548->cache_vals;
    int v5731 = ((((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5572 + ((~(((v5574 ^ -1) | (-(v5574 ^ -1))) >> 31)) & 2)) - (v5575 + ((~(((v5576 ^ -1) | (-(v5576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5635[v5731] = v5633;
    int * v5637 = v5548->cache_tags;
    int v5734 = ((((int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5572 + ((~(((v5574 ^ -1) | (-(v5574 ^ -1))) >> 31)) & 2)) - (v5575 + ((~(((v5576 ^ -1) | (-(v5576 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5735 = (int)((unsigned int)((int)((unsigned int)(v5552 + 28) >> 2)) >> 1);
    v5637[v5734] = v5735;
    int * v5639 = v5548->cache_dirty;
    v5639[v5734] = 0;
    int * v5641 = v5548->cache_age;
    v5641[v5734] = 1;
    int * v5643 = v5548->cache_age;
    int v5644 = v5643[v5734];
    int v5645 = v5643[v5663];
    int v5741 = v5645 + ((int)((unsigned int)(v5645 - v5644) >> 31));
    v5643[v5663] = v5741;
    int * v5647 = v5548->cache_age;
    int v5648 = v5647[v5664];
    int v5743 = v5648 + ((int)((unsigned int)(v5648 - v5644) >> 31));
    v5647[v5664] = v5743;
    int * v5650 = v5548->cache_age;
    v5650[v5734] = 0;
    v5653 = v5734;
  }
  int v5746 = (v5653 * 2) + (((int)((unsigned int)(v5552 + 28) >> 2)) & 1);
  int v5654 = v5560[v5746];
  int * v5655 = v5548->regs;
  v5655[1] = v5654;
  struct StateT * v5657 = slot_23(v5548);
  return v5657;
}

struct StateT * slot_139(struct StateT * v20906) {
  int v20907 = v20906->timer;
  int v20914 = v20907 + 1;
  v20906->timer = v20914;
  int * v20909 = v20906->regs;
  int v20910 = v20909[11];
  int v20917 = v20910 << 7;
  v20909[11] = v20917;
  struct StateT * v20912 = slot_140(v20906);
  return v20912;
}

struct StateT * slot_221(struct StateT * v10244) {
  int v10245 = v10244->timer;
  int v10253 = v10245 + 1;
  v10244->timer = v10253;
  int * v10247 = v10244->regs;
  int v10248 = v10247[5];
  int v10249 = v10247[7];
  int v10257 = v10248 + v10249;
  v10247[5] = v10257;
  struct StateT * v10251 = slot_222(v10244);
  return v10251;
}

struct StateT * slot_23(struct StateT * v5752) {
  int v5753 = v5752->timer;
  int v5863 = v5753 + 1;
  v5752->timer = v5863;
  int * v5755 = v5752->regs;
  int v5756 = v5755[11];
  int * v5757 = v5752->cache_tags;
  int v5867 = (((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2;
  int v5758 = v5757[v5867];
  int v5868 = ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5759 = v5757[v5868];
  int v5869 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2);
  int v5760 = v5757[v5869];
  int v5870 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5761 = v5757[v5870];
  int v5762 = v5752->timer;
  int v5871 = v5762 + ((100 ^ (((~(((v5760 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5760 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) | (~(((v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5758 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5758 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) | (~(((v5759 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5759 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5760 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5760 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) | (~(((v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5752->timer = v5871;
  int * v5764 = v5752->cache_vals;
  bool v5872 = !(((~(((v5758 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5758 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) | (~(((v5759 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5759 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31))) == 0);
  int v5857;
  if (v5872) {
    int * v5765 = v5752->cache_age;
    int v5874 = ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2) + ((~(((v5759 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5759 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) & 1);
    int v5766 = v5765[v5874];
    int v5767 = v5765[v5867];
    int v5875 = v5767 + ((int)((unsigned int)(v5767 - v5766) >> 31));
    v5765[v5867] = v5875;
    int * v5769 = v5752->cache_age;
    int v5770 = v5769[v5868];
    int v5877 = v5770 + ((int)((unsigned int)(v5770 - v5766) >> 31));
    v5769[v5868] = v5877;
    int * v5772 = v5752->cache_age;
    v5772[v5874] = 0;
    v5857 = v5874;
  } else {
    int * v5775 = v5752->cache_age;
    int v5881 = (((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2;
    int v5776 = v5775[v5881];
    int * v5777 = v5752->cache_tags;
    int v5778 = v5777[v5881];
    int v5779 = v5775[v5868];
    int v5780 = v5777[v5868];
    bool v5883 = !(((~(((v5760 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5760 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) | (~(((v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31))) == 0);
    int v5834;
    if (v5883) {
      int * v5781 = v5752->cache_age;
      int v5885 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))) | (-(v5761 ^ ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1))))) >> 31)) & 1);
      int v5782 = v5781[v5885];
      int v5783 = v5781[v5869];
      int v5886 = v5783 + ((int)((unsigned int)(v5783 - v5782) >> 31));
      v5781[v5869] = v5886;
      int * v5785 = v5752->cache_age;
      int v5786 = v5785[v5870];
      int v5888 = v5786 + ((int)((unsigned int)(v5786 - v5782) >> 31));
      v5785[v5870] = v5888;
      int * v5788 = v5752->cache_age;
      v5788[v5885] = 0;
      v5834 = v5885;
    } else {
      int * v5791 = v5752->cache_age;
      int v5892 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2);
      int v5792 = v5791[v5892];
      int * v5793 = v5752->cache_tags;
      int v5794 = v5793[v5892];
      int v5795 = v5791[v5870];
      int v5796 = v5793[v5870];
      int * v5797 = v5752->cache_dirty;
      int v5895 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + ((((v5792 + ((~(((v5794 ^ -1) | (-(v5794 ^ -1))) >> 31)) & 2)) - (v5795 + ((~(((v5796 ^ -1) | (-(v5796 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5798 = v5797[v5895];
      bool v5896 = !(v5798 == 0);
      if (v5896) {
        int * v5799 = v5752->cache_tags;
        int v5800 = v5799[v5895];
        int * v5801 = v5752->cache_vals;
        int v5899 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + ((((v5792 + ((~(((v5794 ^ -1) | (-(v5794 ^ -1))) >> 31)) & 2)) - (v5795 + ((~(((v5796 ^ -1) | (-(v5796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5802 = v5801[v5899];
        int v5900 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + ((((v5792 + ((~(((v5794 ^ -1) | (-(v5794 ^ -1))) >> 31)) & 2)) - (v5795 + ((~(((v5796 ^ -1) | (-(v5796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5803 = v5801[v5900];
        int * v5804 = v5752->mem;
        int v5902 = v5800 * 2;
        v5804[v5902] = v5802;
        int * v5806 = v5752->mem;
        int v5905 = (v5800 * 2) + 1;
        v5806[v5905] = v5803;
        ;
      } else {
        ;
      }
      int * v5811 = v5752->mem;
      int v5910 = ((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) * 2;
      int v5812 = v5811[v5910];
      int v5911 = (((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) * 2) + 1;
      int v5813 = v5811[v5911];
      int * v5814 = v5752->cache_vals;
      int v5913 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + ((((v5792 + ((~(((v5794 ^ -1) | (-(v5794 ^ -1))) >> 31)) & 2)) - (v5795 + ((~(((v5796 ^ -1) | (-(v5796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5814[v5913] = v5812;
      int * v5816 = v5752->cache_vals;
      int v5916 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 3) * 2)) + ((((v5792 + ((~(((v5794 ^ -1) | (-(v5794 ^ -1))) >> 31)) & 2)) - (v5795 + ((~(((v5796 ^ -1) | (-(v5796 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5816[v5916] = v5813;
      int * v5818 = v5752->cache_tags;
      int v5919 = (int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1);
      v5818[v5895] = v5919;
      int * v5820 = v5752->cache_dirty;
      v5820[v5895] = 0;
      int * v5822 = v5752->cache_age;
      v5822[v5895] = 1;
      int * v5824 = v5752->cache_age;
      int v5825 = v5824[v5895];
      int v5826 = v5824[v5869];
      int v5925 = v5826 + ((int)((unsigned int)(v5826 - v5825) >> 31));
      v5824[v5869] = v5925;
      int * v5828 = v5752->cache_age;
      int v5829 = v5828[v5870];
      int v5927 = v5829 + ((int)((unsigned int)(v5829 - v5825) >> 31));
      v5828[v5870] = v5927;
      int * v5831 = v5752->cache_age;
      v5831[v5895] = 0;
      v5834 = v5895;
    }
    int * v5835 = v5752->cache_vals;
    int v5930 = v5834 * 2;
    int v5836 = v5835[v5930];
    int v5931 = (v5834 * 2) + 1;
    int v5837 = v5835[v5931];
    int v5932 = (((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2) + ((((v5776 + ((~(((v5778 ^ -1) | (-(v5778 ^ -1))) >> 31)) & 2)) - (v5779 + ((~(((v5780 ^ -1) | (-(v5780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5835[v5932] = v5836;
    int * v5839 = v5752->cache_vals;
    int v5935 = ((((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2) + ((((v5776 + ((~(((v5778 ^ -1) | (-(v5778 ^ -1))) >> 31)) & 2)) - (v5779 + ((~(((v5780 ^ -1) | (-(v5780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5839[v5935] = v5837;
    int * v5841 = v5752->cache_tags;
    int v5938 = ((((int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1)) & 1) * 2) + ((((v5776 + ((~(((v5778 ^ -1) | (-(v5778 ^ -1))) >> 31)) & 2)) - (v5779 + ((~(((v5780 ^ -1) | (-(v5780 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5939 = (int)((unsigned int)((int)((unsigned int)v5756 >> 2)) >> 1);
    v5841[v5938] = v5939;
    int * v5843 = v5752->cache_dirty;
    v5843[v5938] = 0;
    int * v5845 = v5752->cache_age;
    v5845[v5938] = 1;
    int * v5847 = v5752->cache_age;
    int v5848 = v5847[v5938];
    int v5849 = v5847[v5867];
    int v5945 = v5849 + ((int)((unsigned int)(v5849 - v5848) >> 31));
    v5847[v5867] = v5945;
    int * v5851 = v5752->cache_age;
    int v5852 = v5851[v5868];
    int v5947 = v5852 + ((int)((unsigned int)(v5852 - v5848) >> 31));
    v5851[v5868] = v5947;
    int * v5854 = v5752->cache_age;
    v5854[v5938] = 0;
    v5857 = v5938;
  }
  int v5950 = (v5857 * 2) + (((int)((unsigned int)v5756 >> 2)) & 1);
  int v5858 = v5764[v5950];
  int * v5859 = v5752->regs;
  v5859[5] = v5858;
  struct StateT * v5861 = slot_24(v5752);
  return v5861;
}

struct StateT * slot_153(struct StateT * v21128) {
  int v21129 = v21128->timer;
  int v21137 = v21129 + 1;
  v21128->timer = v21137;
  int * v21131 = v21128->regs;
  int v21132 = v21131[17];
  int v21133 = v21131[19];
  int v21142 = v21132 + v21133;
  v21131[6] = v21142;
  struct StateT * v21135 = slot_154(v21128);
  return v21135;
}

struct StateT * slot_2(struct StateT * v327) {
  int v328 = v327->timer;
  int v498 = v328 + 1;
  v327->timer = v498;
  int * v330 = v327->regs;
  int v331 = v330[2];
  int v332 = v330[8];
  int * v333 = v327->cache_tags;
  int v503 = (((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2;
  int v334 = v333[v503];
  int v504 = ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2) + 1;
  int v335 = v333[v504];
  int v505 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2);
  int v336 = v333[v505];
  int v506 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v337 = v333[v506];
  int v338 = v327->timer;
  int v507 = v338 + ((100 ^ (((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31))) & 104)))));
  v327->timer = v507;
  bool v508 = !(((~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31))) == 0);
  int v432;
  if (v508) {
    int * v340 = v327->cache_age;
    int v510 = ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2) + ((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) & 1);
    int v341 = v340[v510];
    int v342 = v340[v503];
    int v511 = v342 + ((int)((unsigned int)(v342 - v341) >> 31));
    v340[v503] = v511;
    int * v344 = v327->cache_age;
    int v345 = v344[v504];
    int v513 = v345 + ((int)((unsigned int)(v345 - v341) >> 31));
    v344[v504] = v513;
    int * v347 = v327->cache_age;
    v347[v510] = 0;
    v432 = v510;
  } else {
    int * v350 = v327->cache_age;
    int v517 = (((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2;
    int v351 = v350[v517];
    int * v352 = v327->cache_tags;
    int v353 = v352[v517];
    int v354 = v350[v504];
    int v355 = v352[v504];
    bool v519 = !(((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31))) == 0);
    int v409;
    if (v519) {
      int * v356 = v327->cache_age;
      int v521 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) & 1);
      int v357 = v356[v521];
      int v358 = v356[v505];
      int v522 = v358 + ((int)((unsigned int)(v358 - v357) >> 31));
      v356[v505] = v522;
      int * v360 = v327->cache_age;
      int v361 = v360[v506];
      int v524 = v361 + ((int)((unsigned int)(v361 - v357) >> 31));
      v360[v506] = v524;
      int * v363 = v327->cache_age;
      v363[v521] = 0;
      v409 = v521;
    } else {
      int * v366 = v327->cache_age;
      int v528 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2);
      int v367 = v366[v528];
      int * v368 = v327->cache_tags;
      int v369 = v368[v528];
      int v370 = v366[v506];
      int v371 = v368[v506];
      int * v372 = v327->cache_dirty;
      int v531 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v373 = v372[v531];
      bool v532 = !(v373 == 0);
      if (v532) {
        int * v374 = v327->cache_tags;
        int v375 = v374[v531];
        int * v376 = v327->cache_vals;
        int v535 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v377 = v376[v535];
        int v536 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v378 = v376[v536];
        int * v379 = v327->mem;
        int v538 = v375 * 2;
        v379[v538] = v377;
        int * v381 = v327->mem;
        int v541 = (v375 * 2) + 1;
        v381[v541] = v378;
        ;
      } else {
        ;
      }
      int * v386 = v327->mem;
      int v546 = ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) * 2;
      int v387 = v386[v546];
      int v547 = (((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) * 2) + 1;
      int v388 = v386[v547];
      int * v389 = v327->cache_vals;
      int v549 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v389[v549] = v387;
      int * v391 = v327->cache_vals;
      int v552 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v391[v552] = v388;
      int * v393 = v327->cache_tags;
      int v555 = (int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1);
      v393[v531] = v555;
      int * v395 = v327->cache_dirty;
      v395[v531] = 0;
      int * v397 = v327->cache_age;
      v397[v531] = 1;
      int * v399 = v327->cache_age;
      int v400 = v399[v531];
      int v401 = v399[v505];
      int v561 = v401 + ((int)((unsigned int)(v401 - v400) >> 31));
      v399[v505] = v561;
      int * v403 = v327->cache_age;
      int v404 = v403[v506];
      int v563 = v404 + ((int)((unsigned int)(v404 - v400) >> 31));
      v403[v506] = v563;
      int * v406 = v327->cache_age;
      v406[v531] = 0;
      v409 = v531;
    }
    int * v410 = v327->cache_vals;
    int v566 = v409 * 2;
    int v411 = v410[v566];
    int v567 = (v409 * 2) + 1;
    int v412 = v410[v567];
    int v568 = (((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v410[v568] = v411;
    int * v414 = v327->cache_vals;
    int v571 = ((((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v414[v571] = v412;
    int * v416 = v327->cache_tags;
    int v574 = ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v575 = (int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1);
    v416[v574] = v575;
    int * v418 = v327->cache_dirty;
    v418[v574] = 0;
    int * v420 = v327->cache_age;
    v420[v574] = 1;
    int * v422 = v327->cache_age;
    int v423 = v422[v574];
    int v424 = v422[v503];
    int v581 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
    v422[v503] = v581;
    int * v426 = v327->cache_age;
    int v427 = v426[v504];
    int v583 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
    v426[v504] = v583;
    int * v429 = v327->cache_age;
    v429[v574] = 0;
    v432 = v574;
  }
  int * v433 = v327->cache_vals;
  int v586 = (v432 * 2) + (((int)((unsigned int)(v331 + 88) >> 2)) & 1);
  v433[v586] = v332;
  int * v435 = v327->cache_tags;
  int v436 = v435[v505];
  int v437 = v435[v506];
  bool v589 = !(((~(((v436 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v436 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) | (~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31))) == 0);
  int v491;
  if (v589) {
    int * v438 = v327->cache_age;
    int v591 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((~(((v437 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))) | (-(v437 ^ ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1))))) >> 31)) & 1);
    int v439 = v438[v591];
    int v440 = v438[v505];
    int v592 = v440 + ((int)((unsigned int)(v440 - v439) >> 31));
    v438[v505] = v592;
    int * v442 = v327->cache_age;
    int v443 = v442[v506];
    int v594 = v443 + ((int)((unsigned int)(v443 - v439) >> 31));
    v442[v506] = v594;
    int * v445 = v327->cache_age;
    v445[v591] = 0;
    v491 = v591;
  } else {
    int * v448 = v327->cache_age;
    int v598 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2);
    int v449 = v448[v598];
    int * v450 = v327->cache_tags;
    int v451 = v450[v598];
    int v452 = v448[v506];
    int v453 = v450[v506];
    int * v454 = v327->cache_dirty;
    int v601 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v455 = v454[v601];
    bool v602 = !(v455 == 0);
    if (v602) {
      int * v456 = v327->cache_tags;
      int v457 = v456[v601];
      int * v458 = v327->cache_vals;
      int v605 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v459 = v458[v605];
      int v606 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v460 = v458[v606];
      int * v461 = v327->mem;
      int v608 = v457 * 2;
      v461[v608] = v459;
      int * v463 = v327->mem;
      int v611 = (v457 * 2) + 1;
      v463[v611] = v460;
      ;
    } else {
      ;
    }
    int * v468 = v327->mem;
    int v616 = ((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) * 2;
    int v469 = v468[v616];
    int v617 = (((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) * 2) + 1;
    int v470 = v468[v617];
    int * v471 = v327->cache_vals;
    int v619 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v471[v619] = v469;
    int * v473 = v327->cache_vals;
    int v622 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v473[v622] = v470;
    int * v475 = v327->cache_tags;
    int v625 = (int)((unsigned int)((int)((unsigned int)(v331 + 88) >> 2)) >> 1);
    v475[v601] = v625;
    int * v477 = v327->cache_dirty;
    v477[v601] = 0;
    int * v479 = v327->cache_age;
    v479[v601] = 1;
    int * v481 = v327->cache_age;
    int v482 = v481[v601];
    int v483 = v481[v505];
    int v631 = v483 + ((int)((unsigned int)(v483 - v482) >> 31));
    v481[v505] = v631;
    int * v485 = v327->cache_age;
    int v486 = v485[v506];
    int v633 = v486 + ((int)((unsigned int)(v486 - v482) >> 31));
    v485[v506] = v633;
    int * v488 = v327->cache_age;
    v488[v601] = 0;
    v491 = v601;
  }
  int * v492 = v327->cache_vals;
  int v636 = (v491 * 2) + (((int)((unsigned int)(v331 + 88) >> 2)) & 1);
  v492[v636] = v332;
  int * v494 = v327->cache_dirty;
  v494[v491] = 1;
  struct StateT * v496 = slot_3(v327);
  return v496;
}

struct StateT * slot_86(struct StateT * v13307) {
  int v13308 = v13307->timer;
  int v13316 = v13308 + 1;
  v13307->timer = v13316;
  int * v13310 = v13307->regs;
  int v13311 = v13310[18];
  int v13312 = v13310[20];
  int v13320 = v13311 | v13312;
  v13310[18] = v13320;
  struct StateT * v13314 = slot_87(v13307);
  return v13314;
}

struct StateT * slot_129(struct StateT * v20746) {
  int v20747 = v20746->timer;
  int v20755 = v20747 + 1;
  v20746->timer = v20755;
  int * v20749 = v20746->regs;
  int v20750 = v20749[19];
  int v20751 = v20749[17];
  int v20759 = v20750 ^ v20751;
  v20749[19] = v20759;
  struct StateT * v20753 = slot_130(v20746);
  return v20753;
}

struct StateT * slot_158(struct StateT * v21207) {
  int v21208 = v21207->timer;
  int v21215 = v21208 + 1;
  v21207->timer = v21215;
  int * v21210 = v21207->regs;
  int v21211 = v21210[15];
  int v21219 = (int)((unsigned int)v21211 >> 23);
  v21210[9] = v21219;
  struct StateT * v21213 = slot_159(v21207);
  return v21213;
}

struct StateT * slot_100(struct StateT * v17824) {
  int v17825 = v17824->timer;
  int v17833 = v17825 + 1;
  v17824->timer = v17833;
  int * v17827 = v17824->regs;
  int v17828 = v17827[8];
  int v17829 = v17827[20];
  int v17837 = v17828 | v17829;
  v17827[8] = v17837;
  struct StateT * v17831 = slot_101(v17824);
  return v17831;
}

struct StateT * slot_271(struct StateT * v19596) {
  int v19597 = v19596->timer;
  int v19707 = v19597 + 1;
  v19596->timer = v19707;
  int * v19599 = v19596->regs;
  int v19600 = v19599[2];
  int * v19601 = v19596->cache_tags;
  int v19711 = (((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2;
  int v19602 = v19601[v19711];
  int v19712 = ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2) + 1;
  int v19603 = v19601[v19712];
  int v19713 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2);
  int v19604 = v19601[v19713];
  int v19714 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v19605 = v19601[v19714];
  int v19606 = v19596->timer;
  int v19715 = v19606 + ((100 ^ (((~(((v19604 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19604 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v19602 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19602 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v19603 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19603 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v19604 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19604 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31))) & 104)))));
  v19596->timer = v19715;
  int * v19608 = v19596->cache_vals;
  bool v19716 = !(((~(((v19602 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19602 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v19603 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19603 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31))) == 0);
  int v19701;
  if (v19716) {
    int * v19609 = v19596->cache_age;
    int v19718 = ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2) + ((~(((v19603 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19603 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) & 1);
    int v19610 = v19609[v19718];
    int v19611 = v19609[v19711];
    int v19719 = v19611 + ((int)((unsigned int)(v19611 - v19610) >> 31));
    v19609[v19711] = v19719;
    int * v19613 = v19596->cache_age;
    int v19614 = v19613[v19712];
    int v19721 = v19614 + ((int)((unsigned int)(v19614 - v19610) >> 31));
    v19613[v19712] = v19721;
    int * v19616 = v19596->cache_age;
    v19616[v19718] = 0;
    v19701 = v19718;
  } else {
    int * v19619 = v19596->cache_age;
    int v19725 = (((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2;
    int v19620 = v19619[v19725];
    int * v19621 = v19596->cache_tags;
    int v19622 = v19621[v19725];
    int v19623 = v19619[v19712];
    int v19624 = v19621[v19712];
    bool v19727 = !(((~(((v19604 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19604 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) | (~(((v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31))) == 0);
    int v19678;
    if (v19727) {
      int * v19625 = v19596->cache_age;
      int v19729 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + ((~(((v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))) | (-(v19605 ^ ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1))))) >> 31)) & 1);
      int v19626 = v19625[v19729];
      int v19627 = v19625[v19713];
      int v19730 = v19627 + ((int)((unsigned int)(v19627 - v19626) >> 31));
      v19625[v19713] = v19730;
      int * v19629 = v19596->cache_age;
      int v19630 = v19629[v19714];
      int v19732 = v19630 + ((int)((unsigned int)(v19630 - v19626) >> 31));
      v19629[v19714] = v19732;
      int * v19632 = v19596->cache_age;
      v19632[v19729] = 0;
      v19678 = v19729;
    } else {
      int * v19635 = v19596->cache_age;
      int v19736 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2);
      int v19636 = v19635[v19736];
      int * v19637 = v19596->cache_tags;
      int v19638 = v19637[v19736];
      int v19639 = v19635[v19714];
      int v19640 = v19637[v19714];
      int * v19641 = v19596->cache_dirty;
      int v19739 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v19636 + ((~(((v19638 ^ -1) | (-(v19638 ^ -1))) >> 31)) & 2)) - (v19639 + ((~(((v19640 ^ -1) | (-(v19640 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v19642 = v19641[v19739];
      bool v19740 = !(v19642 == 0);
      if (v19740) {
        int * v19643 = v19596->cache_tags;
        int v19644 = v19643[v19739];
        int * v19645 = v19596->cache_vals;
        int v19743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v19636 + ((~(((v19638 ^ -1) | (-(v19638 ^ -1))) >> 31)) & 2)) - (v19639 + ((~(((v19640 ^ -1) | (-(v19640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v19646 = v19645[v19743];
        int v19744 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v19636 + ((~(((v19638 ^ -1) | (-(v19638 ^ -1))) >> 31)) & 2)) - (v19639 + ((~(((v19640 ^ -1) | (-(v19640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v19647 = v19645[v19744];
        int * v19648 = v19596->mem;
        int v19746 = v19644 * 2;
        v19648[v19746] = v19646;
        int * v19650 = v19596->mem;
        int v19749 = (v19644 * 2) + 1;
        v19650[v19749] = v19647;
        ;
      } else {
        ;
      }
      int * v19655 = v19596->mem;
      int v19754 = ((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) * 2;
      int v19656 = v19655[v19754];
      int v19755 = (((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) * 2) + 1;
      int v19657 = v19655[v19755];
      int * v19658 = v19596->cache_vals;
      int v19757 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v19636 + ((~(((v19638 ^ -1) | (-(v19638 ^ -1))) >> 31)) & 2)) - (v19639 + ((~(((v19640 ^ -1) | (-(v19640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v19658[v19757] = v19656;
      int * v19660 = v19596->cache_vals;
      int v19760 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 3) * 2)) + ((((v19636 + ((~(((v19638 ^ -1) | (-(v19638 ^ -1))) >> 31)) & 2)) - (v19639 + ((~(((v19640 ^ -1) | (-(v19640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v19660[v19760] = v19657;
      int * v19662 = v19596->cache_tags;
      int v19763 = (int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1);
      v19662[v19739] = v19763;
      int * v19664 = v19596->cache_dirty;
      v19664[v19739] = 0;
      int * v19666 = v19596->cache_age;
      v19666[v19739] = 1;
      int * v19668 = v19596->cache_age;
      int v19669 = v19668[v19739];
      int v19670 = v19668[v19713];
      int v19769 = v19670 + ((int)((unsigned int)(v19670 - v19669) >> 31));
      v19668[v19713] = v19769;
      int * v19672 = v19596->cache_age;
      int v19673 = v19672[v19714];
      int v19771 = v19673 + ((int)((unsigned int)(v19673 - v19669) >> 31));
      v19672[v19714] = v19771;
      int * v19675 = v19596->cache_age;
      v19675[v19739] = 0;
      v19678 = v19739;
    }
    int * v19679 = v19596->cache_vals;
    int v19774 = v19678 * 2;
    int v19680 = v19679[v19774];
    int v19775 = (v19678 * 2) + 1;
    int v19681 = v19679[v19775];
    int v19776 = (((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v19620 + ((~(((v19622 ^ -1) | (-(v19622 ^ -1))) >> 31)) & 2)) - (v19623 + ((~(((v19624 ^ -1) | (-(v19624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v19679[v19776] = v19680;
    int * v19683 = v19596->cache_vals;
    int v19779 = ((((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v19620 + ((~(((v19622 ^ -1) | (-(v19622 ^ -1))) >> 31)) & 2)) - (v19623 + ((~(((v19624 ^ -1) | (-(v19624 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v19683[v19779] = v19681;
    int * v19685 = v19596->cache_tags;
    int v19782 = ((((int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1)) & 1) * 2) + ((((v19620 + ((~(((v19622 ^ -1) | (-(v19622 ^ -1))) >> 31)) & 2)) - (v19623 + ((~(((v19624 ^ -1) | (-(v19624 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v19783 = (int)((unsigned int)((int)((unsigned int)(v19600 + 56) >> 2)) >> 1);
    v19685[v19782] = v19783;
    int * v19687 = v19596->cache_dirty;
    v19687[v19782] = 0;
    int * v19689 = v19596->cache_age;
    v19689[v19782] = 1;
    int * v19691 = v19596->cache_age;
    int v19692 = v19691[v19782];
    int v19693 = v19691[v19711];
    int v19789 = v19693 + ((int)((unsigned int)(v19693 - v19692) >> 31));
    v19691[v19711] = v19789;
    int * v19695 = v19596->cache_age;
    int v19696 = v19695[v19712];
    int v19791 = v19696 + ((int)((unsigned int)(v19696 - v19692) >> 31));
    v19695[v19712] = v19791;
    int * v19698 = v19596->cache_age;
    v19698[v19782] = 0;
    v19701 = v19782;
  }
  int v19794 = (v19701 * 2) + (((int)((unsigned int)(v19600 + 56) >> 2)) & 1);
  int v19702 = v19608[v19794];
  int * v19703 = v19596->regs;
  v19703[24] = v19702;
  struct StateT * v19705 = slot_272(v19596);
  return v19705;
}

struct StateT * slot_127(struct StateT * v20713) {
  int v20714 = v20713->timer;
  int v20722 = v20714 + 1;
  v20713->timer = v20722;
  int * v20716 = v20713->regs;
  int v20717 = v20716[21];
  int v20718 = v20716[15];
  int v20726 = v20717 ^ v20718;
  v20716[21] = v20726;
  struct StateT * v20720 = slot_128(v20713);
  return v20720;
}

struct StateT * slot_217(struct StateT * v9747) {
  int v9748 = v9747->timer;
  int v9858 = v9748 + 1;
  v9747->timer = v9858;
  int * v9750 = v9747->regs;
  int v9751 = v9750[2];
  int * v9752 = v9747->cache_tags;
  int v9862 = (((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2;
  int v9753 = v9752[v9862];
  int v9863 = ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9754 = v9752[v9863];
  int v9864 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2);
  int v9755 = v9752[v9864];
  int v9865 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9756 = v9752[v9865];
  int v9757 = v9747->timer;
  int v9866 = v9757 + ((100 ^ (((~(((v9755 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9755 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9753 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9753 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9754 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9754 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9755 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9755 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9747->timer = v9866;
  int * v9759 = v9747->cache_vals;
  bool v9867 = !(((~(((v9753 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9753 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9754 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9754 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v9852;
  if (v9867) {
    int * v9760 = v9747->cache_age;
    int v9869 = ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v9754 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9754 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v9761 = v9760[v9869];
    int v9762 = v9760[v9862];
    int v9870 = v9762 + ((int)((unsigned int)(v9762 - v9761) >> 31));
    v9760[v9862] = v9870;
    int * v9764 = v9747->cache_age;
    int v9765 = v9764[v9863];
    int v9872 = v9765 + ((int)((unsigned int)(v9765 - v9761) >> 31));
    v9764[v9863] = v9872;
    int * v9767 = v9747->cache_age;
    v9767[v9869] = 0;
    v9852 = v9869;
  } else {
    int * v9770 = v9747->cache_age;
    int v9876 = (((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2;
    int v9771 = v9770[v9876];
    int * v9772 = v9747->cache_tags;
    int v9773 = v9772[v9876];
    int v9774 = v9770[v9863];
    int v9775 = v9772[v9863];
    bool v9878 = !(((~(((v9755 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9755 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v9829;
    if (v9878) {
      int * v9776 = v9747->cache_age;
      int v9880 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))) | (-(v9756 ^ ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v9777 = v9776[v9880];
      int v9778 = v9776[v9864];
      int v9881 = v9778 + ((int)((unsigned int)(v9778 - v9777) >> 31));
      v9776[v9864] = v9881;
      int * v9780 = v9747->cache_age;
      int v9781 = v9780[v9865];
      int v9883 = v9781 + ((int)((unsigned int)(v9781 - v9777) >> 31));
      v9780[v9865] = v9883;
      int * v9783 = v9747->cache_age;
      v9783[v9880] = 0;
      v9829 = v9880;
    } else {
      int * v9786 = v9747->cache_age;
      int v9887 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2);
      int v9787 = v9786[v9887];
      int * v9788 = v9747->cache_tags;
      int v9789 = v9788[v9887];
      int v9790 = v9786[v9865];
      int v9791 = v9788[v9865];
      int * v9792 = v9747->cache_dirty;
      int v9890 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9787 + ((~(((v9789 ^ -1) | (-(v9789 ^ -1))) >> 31)) & 2)) - (v9790 + ((~(((v9791 ^ -1) | (-(v9791 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9793 = v9792[v9890];
      bool v9891 = !(v9793 == 0);
      if (v9891) {
        int * v9794 = v9747->cache_tags;
        int v9795 = v9794[v9890];
        int * v9796 = v9747->cache_vals;
        int v9894 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9787 + ((~(((v9789 ^ -1) | (-(v9789 ^ -1))) >> 31)) & 2)) - (v9790 + ((~(((v9791 ^ -1) | (-(v9791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9797 = v9796[v9894];
        int v9895 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9787 + ((~(((v9789 ^ -1) | (-(v9789 ^ -1))) >> 31)) & 2)) - (v9790 + ((~(((v9791 ^ -1) | (-(v9791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9798 = v9796[v9895];
        int * v9799 = v9747->mem;
        int v9897 = v9795 * 2;
        v9799[v9897] = v9797;
        int * v9801 = v9747->mem;
        int v9900 = (v9795 * 2) + 1;
        v9801[v9900] = v9798;
        ;
      } else {
        ;
      }
      int * v9806 = v9747->mem;
      int v9905 = ((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) * 2;
      int v9807 = v9806[v9905];
      int v9906 = (((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) * 2) + 1;
      int v9808 = v9806[v9906];
      int * v9809 = v9747->cache_vals;
      int v9908 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9787 + ((~(((v9789 ^ -1) | (-(v9789 ^ -1))) >> 31)) & 2)) - (v9790 + ((~(((v9791 ^ -1) | (-(v9791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9809[v9908] = v9807;
      int * v9811 = v9747->cache_vals;
      int v9911 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9787 + ((~(((v9789 ^ -1) | (-(v9789 ^ -1))) >> 31)) & 2)) - (v9790 + ((~(((v9791 ^ -1) | (-(v9791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9811[v9911] = v9808;
      int * v9813 = v9747->cache_tags;
      int v9914 = (int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1);
      v9813[v9890] = v9914;
      int * v9815 = v9747->cache_dirty;
      v9815[v9890] = 0;
      int * v9817 = v9747->cache_age;
      v9817[v9890] = 1;
      int * v9819 = v9747->cache_age;
      int v9820 = v9819[v9890];
      int v9821 = v9819[v9864];
      int v9920 = v9821 + ((int)((unsigned int)(v9821 - v9820) >> 31));
      v9819[v9864] = v9920;
      int * v9823 = v9747->cache_age;
      int v9824 = v9823[v9865];
      int v9922 = v9824 + ((int)((unsigned int)(v9824 - v9820) >> 31));
      v9823[v9865] = v9922;
      int * v9826 = v9747->cache_age;
      v9826[v9890] = 0;
      v9829 = v9890;
    }
    int * v9830 = v9747->cache_vals;
    int v9925 = v9829 * 2;
    int v9831 = v9830[v9925];
    int v9926 = (v9829 * 2) + 1;
    int v9832 = v9830[v9926];
    int v9927 = (((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v9771 + ((~(((v9773 ^ -1) | (-(v9773 ^ -1))) >> 31)) & 2)) - (v9774 + ((~(((v9775 ^ -1) | (-(v9775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9830[v9927] = v9831;
    int * v9834 = v9747->cache_vals;
    int v9930 = ((((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v9771 + ((~(((v9773 ^ -1) | (-(v9773 ^ -1))) >> 31)) & 2)) - (v9774 + ((~(((v9775 ^ -1) | (-(v9775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9834[v9930] = v9832;
    int * v9836 = v9747->cache_tags;
    int v9933 = ((((int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v9771 + ((~(((v9773 ^ -1) | (-(v9773 ^ -1))) >> 31)) & 2)) - (v9774 + ((~(((v9775 ^ -1) | (-(v9775 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9934 = (int)((unsigned int)((int)((unsigned int)(v9751 + 8) >> 2)) >> 1);
    v9836[v9933] = v9934;
    int * v9838 = v9747->cache_dirty;
    v9838[v9933] = 0;
    int * v9840 = v9747->cache_age;
    v9840[v9933] = 1;
    int * v9842 = v9747->cache_age;
    int v9843 = v9842[v9933];
    int v9844 = v9842[v9862];
    int v9940 = v9844 + ((int)((unsigned int)(v9844 - v9843) >> 31));
    v9842[v9862] = v9940;
    int * v9846 = v9747->cache_age;
    int v9847 = v9846[v9863];
    int v9942 = v9847 + ((int)((unsigned int)(v9847 - v9843) >> 31));
    v9846[v9863] = v9942;
    int * v9849 = v9747->cache_age;
    v9849[v9933] = 0;
    v9852 = v9933;
  }
  int v9945 = (v9852 * 2) + (((int)((unsigned int)(v9751 + 8) >> 2)) & 1);
  int v9853 = v9759[v9945];
  int * v9854 = v9747->regs;
  v9854[6] = v9853;
  struct StateT * v9856 = slot_218(v9747);
  return v9856;
}

struct StateT * slot_13(struct StateT * v3792) {
  int v3793 = v3792->timer;
  int v3963 = v3793 + 1;
  v3792->timer = v3963;
  int * v3795 = v3792->regs;
  int v3796 = v3795[2];
  int v3797 = v3795[27];
  int * v3798 = v3792->cache_tags;
  int v3968 = (((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2;
  int v3799 = v3798[v3968];
  int v3969 = ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3800 = v3798[v3969];
  int v3970 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2);
  int v3801 = v3798[v3970];
  int v3971 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3802 = v3798[v3971];
  int v3803 = v3792->timer;
  int v3972 = v3803 + ((100 ^ (((~(((v3801 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3801 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3799 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3799 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v3800 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3800 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3801 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3801 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3792->timer = v3972;
  bool v3973 = !(((~(((v3799 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3799 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v3800 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3800 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v3897;
  if (v3973) {
    int * v3805 = v3792->cache_age;
    int v3975 = ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v3800 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3800 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v3806 = v3805[v3975];
    int v3807 = v3805[v3968];
    int v3976 = v3807 + ((int)((unsigned int)(v3807 - v3806) >> 31));
    v3805[v3968] = v3976;
    int * v3809 = v3792->cache_age;
    int v3810 = v3809[v3969];
    int v3978 = v3810 + ((int)((unsigned int)(v3810 - v3806) >> 31));
    v3809[v3969] = v3978;
    int * v3812 = v3792->cache_age;
    v3812[v3975] = 0;
    v3897 = v3975;
  } else {
    int * v3815 = v3792->cache_age;
    int v3982 = (((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2;
    int v3816 = v3815[v3982];
    int * v3817 = v3792->cache_tags;
    int v3818 = v3817[v3982];
    int v3819 = v3815[v3969];
    int v3820 = v3817[v3969];
    bool v3984 = !(((~(((v3801 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3801 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v3874;
    if (v3984) {
      int * v3821 = v3792->cache_age;
      int v3986 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3802 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v3822 = v3821[v3986];
      int v3823 = v3821[v3970];
      int v3987 = v3823 + ((int)((unsigned int)(v3823 - v3822) >> 31));
      v3821[v3970] = v3987;
      int * v3825 = v3792->cache_age;
      int v3826 = v3825[v3971];
      int v3989 = v3826 + ((int)((unsigned int)(v3826 - v3822) >> 31));
      v3825[v3971] = v3989;
      int * v3828 = v3792->cache_age;
      v3828[v3986] = 0;
      v3874 = v3986;
    } else {
      int * v3831 = v3792->cache_age;
      int v3993 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2);
      int v3832 = v3831[v3993];
      int * v3833 = v3792->cache_tags;
      int v3834 = v3833[v3993];
      int v3835 = v3831[v3971];
      int v3836 = v3833[v3971];
      int * v3837 = v3792->cache_dirty;
      int v3996 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3832 + ((~(((v3834 ^ -1) | (-(v3834 ^ -1))) >> 31)) & 2)) - (v3835 + ((~(((v3836 ^ -1) | (-(v3836 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3838 = v3837[v3996];
      bool v3997 = !(v3838 == 0);
      if (v3997) {
        int * v3839 = v3792->cache_tags;
        int v3840 = v3839[v3996];
        int * v3841 = v3792->cache_vals;
        int v4000 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3832 + ((~(((v3834 ^ -1) | (-(v3834 ^ -1))) >> 31)) & 2)) - (v3835 + ((~(((v3836 ^ -1) | (-(v3836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3842 = v3841[v4000];
        int v4001 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3832 + ((~(((v3834 ^ -1) | (-(v3834 ^ -1))) >> 31)) & 2)) - (v3835 + ((~(((v3836 ^ -1) | (-(v3836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3843 = v3841[v4001];
        int * v3844 = v3792->mem;
        int v4003 = v3840 * 2;
        v3844[v4003] = v3842;
        int * v3846 = v3792->mem;
        int v4006 = (v3840 * 2) + 1;
        v3846[v4006] = v3843;
        ;
      } else {
        ;
      }
      int * v3851 = v3792->mem;
      int v4011 = ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) * 2;
      int v3852 = v3851[v4011];
      int v4012 = (((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) * 2) + 1;
      int v3853 = v3851[v4012];
      int * v3854 = v3792->cache_vals;
      int v4014 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3832 + ((~(((v3834 ^ -1) | (-(v3834 ^ -1))) >> 31)) & 2)) - (v3835 + ((~(((v3836 ^ -1) | (-(v3836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3854[v4014] = v3852;
      int * v3856 = v3792->cache_vals;
      int v4017 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3832 + ((~(((v3834 ^ -1) | (-(v3834 ^ -1))) >> 31)) & 2)) - (v3835 + ((~(((v3836 ^ -1) | (-(v3836 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3856[v4017] = v3853;
      int * v3858 = v3792->cache_tags;
      int v4020 = (int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1);
      v3858[v3996] = v4020;
      int * v3860 = v3792->cache_dirty;
      v3860[v3996] = 0;
      int * v3862 = v3792->cache_age;
      v3862[v3996] = 1;
      int * v3864 = v3792->cache_age;
      int v3865 = v3864[v3996];
      int v3866 = v3864[v3970];
      int v4026 = v3866 + ((int)((unsigned int)(v3866 - v3865) >> 31));
      v3864[v3970] = v4026;
      int * v3868 = v3792->cache_age;
      int v3869 = v3868[v3971];
      int v4028 = v3869 + ((int)((unsigned int)(v3869 - v3865) >> 31));
      v3868[v3971] = v4028;
      int * v3871 = v3792->cache_age;
      v3871[v3996] = 0;
      v3874 = v3996;
    }
    int * v3875 = v3792->cache_vals;
    int v4031 = v3874 * 2;
    int v3876 = v3875[v4031];
    int v4032 = (v3874 * 2) + 1;
    int v3877 = v3875[v4032];
    int v4033 = (((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v3816 + ((~(((v3818 ^ -1) | (-(v3818 ^ -1))) >> 31)) & 2)) - (v3819 + ((~(((v3820 ^ -1) | (-(v3820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3875[v4033] = v3876;
    int * v3879 = v3792->cache_vals;
    int v4036 = ((((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v3816 + ((~(((v3818 ^ -1) | (-(v3818 ^ -1))) >> 31)) & 2)) - (v3819 + ((~(((v3820 ^ -1) | (-(v3820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3879[v4036] = v3877;
    int * v3881 = v3792->cache_tags;
    int v4039 = ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v3816 + ((~(((v3818 ^ -1) | (-(v3818 ^ -1))) >> 31)) & 2)) - (v3819 + ((~(((v3820 ^ -1) | (-(v3820 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4040 = (int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1);
    v3881[v4039] = v4040;
    int * v3883 = v3792->cache_dirty;
    v3883[v4039] = 0;
    int * v3885 = v3792->cache_age;
    v3885[v4039] = 1;
    int * v3887 = v3792->cache_age;
    int v3888 = v3887[v4039];
    int v3889 = v3887[v3968];
    int v4046 = v3889 + ((int)((unsigned int)(v3889 - v3888) >> 31));
    v3887[v3968] = v4046;
    int * v3891 = v3792->cache_age;
    int v3892 = v3891[v3969];
    int v4048 = v3892 + ((int)((unsigned int)(v3892 - v3888) >> 31));
    v3891[v3969] = v4048;
    int * v3894 = v3792->cache_age;
    v3894[v4039] = 0;
    v3897 = v4039;
  }
  int * v3898 = v3792->cache_vals;
  int v4051 = (v3897 * 2) + (((int)((unsigned int)(v3796 + 44) >> 2)) & 1);
  v3898[v4051] = v3797;
  int * v3900 = v3792->cache_tags;
  int v3901 = v3900[v3970];
  int v3902 = v3900[v3971];
  bool v4054 = !(((~(((v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3901 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v3902 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3902 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v3956;
  if (v4054) {
    int * v3903 = v3792->cache_age;
    int v4056 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3902 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))) | (-(v3902 ^ ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v3904 = v3903[v4056];
    int v3905 = v3903[v3970];
    int v4057 = v3905 + ((int)((unsigned int)(v3905 - v3904) >> 31));
    v3903[v3970] = v4057;
    int * v3907 = v3792->cache_age;
    int v3908 = v3907[v3971];
    int v4059 = v3908 + ((int)((unsigned int)(v3908 - v3904) >> 31));
    v3907[v3971] = v4059;
    int * v3910 = v3792->cache_age;
    v3910[v4056] = 0;
    v3956 = v4056;
  } else {
    int * v3913 = v3792->cache_age;
    int v4063 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2);
    int v3914 = v3913[v4063];
    int * v3915 = v3792->cache_tags;
    int v3916 = v3915[v4063];
    int v3917 = v3913[v3971];
    int v3918 = v3915[v3971];
    int * v3919 = v3792->cache_dirty;
    int v4066 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3914 + ((~(((v3916 ^ -1) | (-(v3916 ^ -1))) >> 31)) & 2)) - (v3917 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3920 = v3919[v4066];
    bool v4067 = !(v3920 == 0);
    if (v4067) {
      int * v3921 = v3792->cache_tags;
      int v3922 = v3921[v4066];
      int * v3923 = v3792->cache_vals;
      int v4070 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3914 + ((~(((v3916 ^ -1) | (-(v3916 ^ -1))) >> 31)) & 2)) - (v3917 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3924 = v3923[v4070];
      int v4071 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3914 + ((~(((v3916 ^ -1) | (-(v3916 ^ -1))) >> 31)) & 2)) - (v3917 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3925 = v3923[v4071];
      int * v3926 = v3792->mem;
      int v4073 = v3922 * 2;
      v3926[v4073] = v3924;
      int * v3928 = v3792->mem;
      int v4076 = (v3922 * 2) + 1;
      v3928[v4076] = v3925;
      ;
    } else {
      ;
    }
    int * v3933 = v3792->mem;
    int v4081 = ((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) * 2;
    int v3934 = v3933[v4081];
    int v4082 = (((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) * 2) + 1;
    int v3935 = v3933[v4082];
    int * v3936 = v3792->cache_vals;
    int v4084 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3914 + ((~(((v3916 ^ -1) | (-(v3916 ^ -1))) >> 31)) & 2)) - (v3917 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3936[v4084] = v3934;
    int * v3938 = v3792->cache_vals;
    int v4087 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v3914 + ((~(((v3916 ^ -1) | (-(v3916 ^ -1))) >> 31)) & 2)) - (v3917 + ((~(((v3918 ^ -1) | (-(v3918 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3938[v4087] = v3935;
    int * v3940 = v3792->cache_tags;
    int v4090 = (int)((unsigned int)((int)((unsigned int)(v3796 + 44) >> 2)) >> 1);
    v3940[v4066] = v4090;
    int * v3942 = v3792->cache_dirty;
    v3942[v4066] = 0;
    int * v3944 = v3792->cache_age;
    v3944[v4066] = 1;
    int * v3946 = v3792->cache_age;
    int v3947 = v3946[v4066];
    int v3948 = v3946[v3970];
    int v4096 = v3948 + ((int)((unsigned int)(v3948 - v3947) >> 31));
    v3946[v3970] = v4096;
    int * v3950 = v3792->cache_age;
    int v3951 = v3950[v3971];
    int v4098 = v3951 + ((int)((unsigned int)(v3951 - v3947) >> 31));
    v3950[v3971] = v4098;
    int * v3953 = v3792->cache_age;
    v3953[v4066] = 0;
    v3956 = v4066;
  }
  int * v3957 = v3792->cache_vals;
  int v4101 = (v3956 * 2) + (((int)((unsigned int)(v3796 + 44) >> 2)) & 1);
  v3957[v4101] = v3797;
  int * v3959 = v3792->cache_dirty;
  v3959[v3956] = 1;
  struct StateT * v3961 = slot_14(v3792);
  return v3961;
}

struct StateT * slot_111(struct StateT * v20242) {
  int v20243 = v20242->timer;
  int v20251 = v20243 + 1;
  v20242->timer = v20251;
  int * v20245 = v20242->regs;
  int v20246 = v20245[9];
  int v20247 = v20245[26];
  int v20256 = v20246 + v20247;
  v20245[15] = v20256;
  struct StateT * v20249 = slot_112(v20242);
  return v20249;
}

struct StateT * slot_109(struct StateT * v19800) {
  int v19801 = v19800->timer;
  int v19809 = v19801 + 1;
  v19800->timer = v19809;
  int * v19803 = v19800->regs;
  int v19804 = v19803[5];
  int v19805 = v19803[20];
  int v19814 = v19804 ^ v19805;
  v19803[18] = v19814;
  struct StateT * v19807 = slot_110(v19800);
  return v19807;
}

struct StateT * slot_174(struct StateT * v21457) {
  int v21458 = v21457->timer;
  int v21466 = v21458 + 1;
  v21457->timer = v21466;
  int * v21460 = v21457->regs;
  int v21461 = v21460[24];
  int v21462 = v21460[16];
  int v21471 = v21461 + v21462;
  v21460[8] = v21471;
  struct StateT * v21464 = slot_175(v21457);
  return v21464;
}

struct StateT * slot_147(struct StateT * v21027) {
  int v21028 = v21027->timer;
  int v21036 = v21028 + 1;
  v21027->timer = v21036;
  int * v21030 = v21027->regs;
  int v21031 = v21030[23];
  int v21032 = v21030[15];
  int v21040 = v21031 ^ v21032;
  v21030[23] = v21040;
  struct StateT * v21034 = slot_148(v21027);
  return v21034;
}

struct StateT * slot_42(struct StateT * v8578) {
  int v8579 = v8578->timer;
  int v8749 = v8579 + 1;
  v8578->timer = v8749;
  int * v8581 = v8578->regs;
  int v8582 = v8581[2];
  int v8583 = v8581[17];
  int * v8584 = v8578->cache_tags;
  int v8754 = (((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2;
  int v8585 = v8584[v8754];
  int v8755 = ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8586 = v8584[v8755];
  int v8756 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2);
  int v8587 = v8584[v8756];
  int v8757 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8588 = v8584[v8757];
  int v8589 = v8578->timer;
  int v8758 = v8589 + ((100 ^ (((~(((v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8585 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8585 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8578->timer = v8758;
  bool v8759 = !(((~(((v8585 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8585 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v8683;
  if (v8759) {
    int * v8591 = v8578->cache_age;
    int v8761 = ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8586 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v8592 = v8591[v8761];
    int v8593 = v8591[v8754];
    int v8762 = v8593 + ((int)((unsigned int)(v8593 - v8592) >> 31));
    v8591[v8754] = v8762;
    int * v8595 = v8578->cache_age;
    int v8596 = v8595[v8755];
    int v8764 = v8596 + ((int)((unsigned int)(v8596 - v8592) >> 31));
    v8595[v8755] = v8764;
    int * v8598 = v8578->cache_age;
    v8598[v8761] = 0;
    v8683 = v8761;
  } else {
    int * v8601 = v8578->cache_age;
    int v8768 = (((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2;
    int v8602 = v8601[v8768];
    int * v8603 = v8578->cache_tags;
    int v8604 = v8603[v8768];
    int v8605 = v8601[v8755];
    int v8606 = v8603[v8755];
    bool v8770 = !(((~(((v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8587 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v8660;
    if (v8770) {
      int * v8607 = v8578->cache_age;
      int v8772 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8588 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v8608 = v8607[v8772];
      int v8609 = v8607[v8756];
      int v8773 = v8609 + ((int)((unsigned int)(v8609 - v8608) >> 31));
      v8607[v8756] = v8773;
      int * v8611 = v8578->cache_age;
      int v8612 = v8611[v8757];
      int v8775 = v8612 + ((int)((unsigned int)(v8612 - v8608) >> 31));
      v8611[v8757] = v8775;
      int * v8614 = v8578->cache_age;
      v8614[v8772] = 0;
      v8660 = v8772;
    } else {
      int * v8617 = v8578->cache_age;
      int v8779 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2);
      int v8618 = v8617[v8779];
      int * v8619 = v8578->cache_tags;
      int v8620 = v8619[v8779];
      int v8621 = v8617[v8757];
      int v8622 = v8619[v8757];
      int * v8623 = v8578->cache_dirty;
      int v8782 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8618 + ((~(((v8620 ^ -1) | (-(v8620 ^ -1))) >> 31)) & 2)) - (v8621 + ((~(((v8622 ^ -1) | (-(v8622 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8624 = v8623[v8782];
      bool v8783 = !(v8624 == 0);
      if (v8783) {
        int * v8625 = v8578->cache_tags;
        int v8626 = v8625[v8782];
        int * v8627 = v8578->cache_vals;
        int v8786 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8618 + ((~(((v8620 ^ -1) | (-(v8620 ^ -1))) >> 31)) & 2)) - (v8621 + ((~(((v8622 ^ -1) | (-(v8622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8628 = v8627[v8786];
        int v8787 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8618 + ((~(((v8620 ^ -1) | (-(v8620 ^ -1))) >> 31)) & 2)) - (v8621 + ((~(((v8622 ^ -1) | (-(v8622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8629 = v8627[v8787];
        int * v8630 = v8578->mem;
        int v8789 = v8626 * 2;
        v8630[v8789] = v8628;
        int * v8632 = v8578->mem;
        int v8792 = (v8626 * 2) + 1;
        v8632[v8792] = v8629;
        ;
      } else {
        ;
      }
      int * v8637 = v8578->mem;
      int v8797 = ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) * 2;
      int v8638 = v8637[v8797];
      int v8798 = (((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) * 2) + 1;
      int v8639 = v8637[v8798];
      int * v8640 = v8578->cache_vals;
      int v8800 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8618 + ((~(((v8620 ^ -1) | (-(v8620 ^ -1))) >> 31)) & 2)) - (v8621 + ((~(((v8622 ^ -1) | (-(v8622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8640[v8800] = v8638;
      int * v8642 = v8578->cache_vals;
      int v8803 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8618 + ((~(((v8620 ^ -1) | (-(v8620 ^ -1))) >> 31)) & 2)) - (v8621 + ((~(((v8622 ^ -1) | (-(v8622 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8642[v8803] = v8639;
      int * v8644 = v8578->cache_tags;
      int v8806 = (int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1);
      v8644[v8782] = v8806;
      int * v8646 = v8578->cache_dirty;
      v8646[v8782] = 0;
      int * v8648 = v8578->cache_age;
      v8648[v8782] = 1;
      int * v8650 = v8578->cache_age;
      int v8651 = v8650[v8782];
      int v8652 = v8650[v8756];
      int v8812 = v8652 + ((int)((unsigned int)(v8652 - v8651) >> 31));
      v8650[v8756] = v8812;
      int * v8654 = v8578->cache_age;
      int v8655 = v8654[v8757];
      int v8814 = v8655 + ((int)((unsigned int)(v8655 - v8651) >> 31));
      v8654[v8757] = v8814;
      int * v8657 = v8578->cache_age;
      v8657[v8782] = 0;
      v8660 = v8782;
    }
    int * v8661 = v8578->cache_vals;
    int v8817 = v8660 * 2;
    int v8662 = v8661[v8817];
    int v8818 = (v8660 * 2) + 1;
    int v8663 = v8661[v8818];
    int v8819 = (((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v8602 + ((~(((v8604 ^ -1) | (-(v8604 ^ -1))) >> 31)) & 2)) - (v8605 + ((~(((v8606 ^ -1) | (-(v8606 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8661[v8819] = v8662;
    int * v8665 = v8578->cache_vals;
    int v8822 = ((((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v8602 + ((~(((v8604 ^ -1) | (-(v8604 ^ -1))) >> 31)) & 2)) - (v8605 + ((~(((v8606 ^ -1) | (-(v8606 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8665[v8822] = v8663;
    int * v8667 = v8578->cache_tags;
    int v8825 = ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v8602 + ((~(((v8604 ^ -1) | (-(v8604 ^ -1))) >> 31)) & 2)) - (v8605 + ((~(((v8606 ^ -1) | (-(v8606 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8826 = (int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1);
    v8667[v8825] = v8826;
    int * v8669 = v8578->cache_dirty;
    v8669[v8825] = 0;
    int * v8671 = v8578->cache_age;
    v8671[v8825] = 1;
    int * v8673 = v8578->cache_age;
    int v8674 = v8673[v8825];
    int v8675 = v8673[v8754];
    int v8832 = v8675 + ((int)((unsigned int)(v8675 - v8674) >> 31));
    v8673[v8754] = v8832;
    int * v8677 = v8578->cache_age;
    int v8678 = v8677[v8755];
    int v8834 = v8678 + ((int)((unsigned int)(v8678 - v8674) >> 31));
    v8677[v8755] = v8834;
    int * v8680 = v8578->cache_age;
    v8680[v8825] = 0;
    v8683 = v8825;
  }
  int * v8684 = v8578->cache_vals;
  int v8837 = (v8683 * 2) + (((int)((unsigned int)(v8582 + 28) >> 2)) & 1);
  v8684[v8837] = v8583;
  int * v8686 = v8578->cache_tags;
  int v8687 = v8686[v8756];
  int v8688 = v8686[v8757];
  bool v8840 = !(((~(((v8687 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8687 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8688 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8688 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v8742;
  if (v8840) {
    int * v8689 = v8578->cache_age;
    int v8842 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8688 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))) | (-(v8688 ^ ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v8690 = v8689[v8842];
    int v8691 = v8689[v8756];
    int v8843 = v8691 + ((int)((unsigned int)(v8691 - v8690) >> 31));
    v8689[v8756] = v8843;
    int * v8693 = v8578->cache_age;
    int v8694 = v8693[v8757];
    int v8845 = v8694 + ((int)((unsigned int)(v8694 - v8690) >> 31));
    v8693[v8757] = v8845;
    int * v8696 = v8578->cache_age;
    v8696[v8842] = 0;
    v8742 = v8842;
  } else {
    int * v8699 = v8578->cache_age;
    int v8849 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2);
    int v8700 = v8699[v8849];
    int * v8701 = v8578->cache_tags;
    int v8702 = v8701[v8849];
    int v8703 = v8699[v8757];
    int v8704 = v8701[v8757];
    int * v8705 = v8578->cache_dirty;
    int v8852 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8700 + ((~(((v8702 ^ -1) | (-(v8702 ^ -1))) >> 31)) & 2)) - (v8703 + ((~(((v8704 ^ -1) | (-(v8704 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8706 = v8705[v8852];
    bool v8853 = !(v8706 == 0);
    if (v8853) {
      int * v8707 = v8578->cache_tags;
      int v8708 = v8707[v8852];
      int * v8709 = v8578->cache_vals;
      int v8856 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8700 + ((~(((v8702 ^ -1) | (-(v8702 ^ -1))) >> 31)) & 2)) - (v8703 + ((~(((v8704 ^ -1) | (-(v8704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v8710 = v8709[v8856];
      int v8857 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8700 + ((~(((v8702 ^ -1) | (-(v8702 ^ -1))) >> 31)) & 2)) - (v8703 + ((~(((v8704 ^ -1) | (-(v8704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v8711 = v8709[v8857];
      int * v8712 = v8578->mem;
      int v8859 = v8708 * 2;
      v8712[v8859] = v8710;
      int * v8714 = v8578->mem;
      int v8862 = (v8708 * 2) + 1;
      v8714[v8862] = v8711;
      ;
    } else {
      ;
    }
    int * v8719 = v8578->mem;
    int v8867 = ((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) * 2;
    int v8720 = v8719[v8867];
    int v8868 = (((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) * 2) + 1;
    int v8721 = v8719[v8868];
    int * v8722 = v8578->cache_vals;
    int v8870 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8700 + ((~(((v8702 ^ -1) | (-(v8702 ^ -1))) >> 31)) & 2)) - (v8703 + ((~(((v8704 ^ -1) | (-(v8704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8722[v8870] = v8720;
    int * v8724 = v8578->cache_vals;
    int v8873 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v8700 + ((~(((v8702 ^ -1) | (-(v8702 ^ -1))) >> 31)) & 2)) - (v8703 + ((~(((v8704 ^ -1) | (-(v8704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8724[v8873] = v8721;
    int * v8726 = v8578->cache_tags;
    int v8876 = (int)((unsigned int)((int)((unsigned int)(v8582 + 28) >> 2)) >> 1);
    v8726[v8852] = v8876;
    int * v8728 = v8578->cache_dirty;
    v8728[v8852] = 0;
    int * v8730 = v8578->cache_age;
    v8730[v8852] = 1;
    int * v8732 = v8578->cache_age;
    int v8733 = v8732[v8852];
    int v8734 = v8732[v8756];
    int v8882 = v8734 + ((int)((unsigned int)(v8734 - v8733) >> 31));
    v8732[v8756] = v8882;
    int * v8736 = v8578->cache_age;
    int v8737 = v8736[v8757];
    int v8884 = v8737 + ((int)((unsigned int)(v8737 - v8733) >> 31));
    v8736[v8757] = v8884;
    int * v8739 = v8578->cache_age;
    v8739[v8852] = 0;
    v8742 = v8852;
  }
  int * v8743 = v8578->cache_vals;
  int v8887 = (v8742 * 2) + (((int)((unsigned int)(v8582 + 28) >> 2)) & 1);
  v8743[v8887] = v8583;
  int * v8745 = v8578->cache_dirty;
  v8745[v8742] = 1;
  struct StateT * v8747 = slot_43(v8578);
  return v8747;
}

struct StateT * slot_224(struct StateT * v10525) {
  int v10526 = v10525->timer;
  int v10636 = v10526 + 1;
  v10525->timer = v10636;
  int * v10528 = v10525->regs;
  int v10529 = v10528[2];
  int * v10530 = v10525->cache_tags;
  int v10640 = (((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2;
  int v10531 = v10530[v10640];
  int v10641 = ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10532 = v10530[v10641];
  int v10642 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2);
  int v10533 = v10530[v10642];
  int v10643 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10534 = v10530[v10643];
  int v10535 = v10525->timer;
  int v10644 = v10535 + ((100 ^ (((~(((v10533 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10533 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10531 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10531 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10532 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10532 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10533 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10533 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10525->timer = v10644;
  int * v10537 = v10525->cache_vals;
  bool v10645 = !(((~(((v10531 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10531 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10532 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10532 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v10630;
  if (v10645) {
    int * v10538 = v10525->cache_age;
    int v10647 = ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v10532 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10532 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v10539 = v10538[v10647];
    int v10540 = v10538[v10640];
    int v10648 = v10540 + ((int)((unsigned int)(v10540 - v10539) >> 31));
    v10538[v10640] = v10648;
    int * v10542 = v10525->cache_age;
    int v10543 = v10542[v10641];
    int v10650 = v10543 + ((int)((unsigned int)(v10543 - v10539) >> 31));
    v10542[v10641] = v10650;
    int * v10545 = v10525->cache_age;
    v10545[v10647] = 0;
    v10630 = v10647;
  } else {
    int * v10548 = v10525->cache_age;
    int v10654 = (((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2;
    int v10549 = v10548[v10654];
    int * v10550 = v10525->cache_tags;
    int v10551 = v10550[v10654];
    int v10552 = v10548[v10641];
    int v10553 = v10550[v10641];
    bool v10656 = !(((~(((v10533 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10533 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v10607;
    if (v10656) {
      int * v10554 = v10525->cache_age;
      int v10658 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))) | (-(v10534 ^ ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v10555 = v10554[v10658];
      int v10556 = v10554[v10642];
      int v10659 = v10556 + ((int)((unsigned int)(v10556 - v10555) >> 31));
      v10554[v10642] = v10659;
      int * v10558 = v10525->cache_age;
      int v10559 = v10558[v10643];
      int v10661 = v10559 + ((int)((unsigned int)(v10559 - v10555) >> 31));
      v10558[v10643] = v10661;
      int * v10561 = v10525->cache_age;
      v10561[v10658] = 0;
      v10607 = v10658;
    } else {
      int * v10564 = v10525->cache_age;
      int v10665 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2);
      int v10565 = v10564[v10665];
      int * v10566 = v10525->cache_tags;
      int v10567 = v10566[v10665];
      int v10568 = v10564[v10643];
      int v10569 = v10566[v10643];
      int * v10570 = v10525->cache_dirty;
      int v10668 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10565 + ((~(((v10567 ^ -1) | (-(v10567 ^ -1))) >> 31)) & 2)) - (v10568 + ((~(((v10569 ^ -1) | (-(v10569 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10571 = v10570[v10668];
      bool v10669 = !(v10571 == 0);
      if (v10669) {
        int * v10572 = v10525->cache_tags;
        int v10573 = v10572[v10668];
        int * v10574 = v10525->cache_vals;
        int v10672 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10565 + ((~(((v10567 ^ -1) | (-(v10567 ^ -1))) >> 31)) & 2)) - (v10568 + ((~(((v10569 ^ -1) | (-(v10569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10575 = v10574[v10672];
        int v10673 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10565 + ((~(((v10567 ^ -1) | (-(v10567 ^ -1))) >> 31)) & 2)) - (v10568 + ((~(((v10569 ^ -1) | (-(v10569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10576 = v10574[v10673];
        int * v10577 = v10525->mem;
        int v10675 = v10573 * 2;
        v10577[v10675] = v10575;
        int * v10579 = v10525->mem;
        int v10678 = (v10573 * 2) + 1;
        v10579[v10678] = v10576;
        ;
      } else {
        ;
      }
      int * v10584 = v10525->mem;
      int v10683 = ((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) * 2;
      int v10585 = v10584[v10683];
      int v10684 = (((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) * 2) + 1;
      int v10586 = v10584[v10684];
      int * v10587 = v10525->cache_vals;
      int v10686 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10565 + ((~(((v10567 ^ -1) | (-(v10567 ^ -1))) >> 31)) & 2)) - (v10568 + ((~(((v10569 ^ -1) | (-(v10569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10587[v10686] = v10585;
      int * v10589 = v10525->cache_vals;
      int v10689 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10565 + ((~(((v10567 ^ -1) | (-(v10567 ^ -1))) >> 31)) & 2)) - (v10568 + ((~(((v10569 ^ -1) | (-(v10569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10589[v10689] = v10586;
      int * v10591 = v10525->cache_tags;
      int v10692 = (int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1);
      v10591[v10668] = v10692;
      int * v10593 = v10525->cache_dirty;
      v10593[v10668] = 0;
      int * v10595 = v10525->cache_age;
      v10595[v10668] = 1;
      int * v10597 = v10525->cache_age;
      int v10598 = v10597[v10668];
      int v10599 = v10597[v10642];
      int v10698 = v10599 + ((int)((unsigned int)(v10599 - v10598) >> 31));
      v10597[v10642] = v10698;
      int * v10601 = v10525->cache_age;
      int v10602 = v10601[v10643];
      int v10700 = v10602 + ((int)((unsigned int)(v10602 - v10598) >> 31));
      v10601[v10643] = v10700;
      int * v10604 = v10525->cache_age;
      v10604[v10668] = 0;
      v10607 = v10668;
    }
    int * v10608 = v10525->cache_vals;
    int v10703 = v10607 * 2;
    int v10609 = v10608[v10703];
    int v10704 = (v10607 * 2) + 1;
    int v10610 = v10608[v10704];
    int v10705 = (((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v10549 + ((~(((v10551 ^ -1) | (-(v10551 ^ -1))) >> 31)) & 2)) - (v10552 + ((~(((v10553 ^ -1) | (-(v10553 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10608[v10705] = v10609;
    int * v10612 = v10525->cache_vals;
    int v10708 = ((((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v10549 + ((~(((v10551 ^ -1) | (-(v10551 ^ -1))) >> 31)) & 2)) - (v10552 + ((~(((v10553 ^ -1) | (-(v10553 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10612[v10708] = v10610;
    int * v10614 = v10525->cache_tags;
    int v10711 = ((((int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v10549 + ((~(((v10551 ^ -1) | (-(v10551 ^ -1))) >> 31)) & 2)) - (v10552 + ((~(((v10553 ^ -1) | (-(v10553 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10712 = (int)((unsigned int)((int)((unsigned int)(v10529 + 20) >> 2)) >> 1);
    v10614[v10711] = v10712;
    int * v10616 = v10525->cache_dirty;
    v10616[v10711] = 0;
    int * v10618 = v10525->cache_age;
    v10618[v10711] = 1;
    int * v10620 = v10525->cache_age;
    int v10621 = v10620[v10711];
    int v10622 = v10620[v10640];
    int v10718 = v10622 + ((int)((unsigned int)(v10622 - v10621) >> 31));
    v10620[v10640] = v10718;
    int * v10624 = v10525->cache_age;
    int v10625 = v10624[v10641];
    int v10720 = v10625 + ((int)((unsigned int)(v10625 - v10621) >> 31));
    v10624[v10641] = v10720;
    int * v10627 = v10525->cache_age;
    v10627[v10711] = 0;
    v10630 = v10711;
  }
  int v10723 = (v10630 * 2) + (((int)((unsigned int)(v10529 + 20) >> 2)) & 1);
  int v10631 = v10537[v10723];
  int * v10632 = v10525->regs;
  v10632[7] = v10631;
  struct StateT * v10634 = slot_225(v10525);
  return v10634;
}

struct StateT * slot_163(struct StateT * v21281) {
  int v21282 = v21281->timer;
  int v21290 = v21282 + 1;
  v21281->timer = v21290;
  int * v21284 = v21281->regs;
  int v21285 = v21284[6];
  int v21286 = v21284[9];
  int v21294 = v21285 | v21286;
  v21284[6] = v21294;
  struct StateT * v21288 = slot_164(v21281);
  return v21288;
}

struct StateT * slot_184(struct StateT * v21609) {
  int v21610 = v21609->timer;
  int v21617 = v21610 + 1;
  v21609->timer = v21617;
  int * v21612 = v21609->regs;
  int v21613 = v21612[8];
  int v21621 = (int)((unsigned int)v21613 >> 19);
  v21612[9] = v21621;
  struct StateT * v21615 = slot_185(v21609);
  return v21615;
}

struct StateT * slot_204(struct StateT * v21921) {
  int v21922 = v21921->timer;
  int v21929 = v21922 + 1;
  v21921->timer = v21929;
  int * v21924 = v21921->regs;
  int v21925 = v21924[8];
  int v21933 = (int)((unsigned int)v21925 >> 14);
  v21924[9] = v21933;
  struct StateT * v21927 = slot_205(v21921);
  return v21927;
}

struct StateT * slot_194(struct StateT * v21769) {
  int v21770 = v21769->timer;
  int v21778 = v21770 + 1;
  v21769->timer = v21778;
  int * v21772 = v21769->regs;
  int v21773 = v21772[1];
  int v21774 = v21772[24];
  int v21783 = v21773 + v21774;
  v21772[8] = v21783;
  struct StateT * v21776 = slot_195(v21769);
  return v21776;
}

struct StateT * slot_165(struct StateT * v21312) {
  int v21313 = v21312->timer;
  int v21320 = v21313 + 1;
  v21312->timer = v21320;
  int * v21315 = v21312->regs;
  int v21316 = v21315[8];
  int v21323 = v21316 << 9;
  v21315[8] = v21323;
  struct StateT * v21318 = slot_166(v21312);
  return v21318;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v13654) {
  int v13655 = v13654->timer;
  int v13825 = v13655 + 1;
  v13654->timer = v13825;
  int * v13657 = v13654->regs;
  int v13658 = v13657[10];
  int v13659 = v13657[12];
  int * v13660 = v13654->cache_tags;
  int v13830 = (((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2;
  int v13661 = v13660[v13830];
  int v13831 = ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13662 = v13660[v13831];
  int v13832 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2);
  int v13663 = v13660[v13832];
  int v13833 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13664 = v13660[v13833];
  int v13665 = v13654->timer;
  int v13834 = v13665 + ((100 ^ (((~(((v13663 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13663 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13661 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13661 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13662 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13662 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13663 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13663 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13654->timer = v13834;
  bool v13835 = !(((~(((v13661 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13661 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13662 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13662 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v13759;
  if (v13835) {
    int * v13667 = v13654->cache_age;
    int v13837 = ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v13662 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13662 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v13668 = v13667[v13837];
    int v13669 = v13667[v13830];
    int v13838 = v13669 + ((int)((unsigned int)(v13669 - v13668) >> 31));
    v13667[v13830] = v13838;
    int * v13671 = v13654->cache_age;
    int v13672 = v13671[v13831];
    int v13840 = v13672 + ((int)((unsigned int)(v13672 - v13668) >> 31));
    v13671[v13831] = v13840;
    int * v13674 = v13654->cache_age;
    v13674[v13837] = 0;
    v13759 = v13837;
  } else {
    int * v13677 = v13654->cache_age;
    int v13844 = (((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2;
    int v13678 = v13677[v13844];
    int * v13679 = v13654->cache_tags;
    int v13680 = v13679[v13844];
    int v13681 = v13677[v13831];
    int v13682 = v13679[v13831];
    bool v13846 = !(((~(((v13663 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13663 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v13736;
    if (v13846) {
      int * v13683 = v13654->cache_age;
      int v13848 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13664 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v13684 = v13683[v13848];
      int v13685 = v13683[v13832];
      int v13849 = v13685 + ((int)((unsigned int)(v13685 - v13684) >> 31));
      v13683[v13832] = v13849;
      int * v13687 = v13654->cache_age;
      int v13688 = v13687[v13833];
      int v13851 = v13688 + ((int)((unsigned int)(v13688 - v13684) >> 31));
      v13687[v13833] = v13851;
      int * v13690 = v13654->cache_age;
      v13690[v13848] = 0;
      v13736 = v13848;
    } else {
      int * v13693 = v13654->cache_age;
      int v13855 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2);
      int v13694 = v13693[v13855];
      int * v13695 = v13654->cache_tags;
      int v13696 = v13695[v13855];
      int v13697 = v13693[v13833];
      int v13698 = v13695[v13833];
      int * v13699 = v13654->cache_dirty;
      int v13858 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13694 + ((~(((v13696 ^ -1) | (-(v13696 ^ -1))) >> 31)) & 2)) - (v13697 + ((~(((v13698 ^ -1) | (-(v13698 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13700 = v13699[v13858];
      bool v13859 = !(v13700 == 0);
      if (v13859) {
        int * v13701 = v13654->cache_tags;
        int v13702 = v13701[v13858];
        int * v13703 = v13654->cache_vals;
        int v13862 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13694 + ((~(((v13696 ^ -1) | (-(v13696 ^ -1))) >> 31)) & 2)) - (v13697 + ((~(((v13698 ^ -1) | (-(v13698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13704 = v13703[v13862];
        int v13863 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13694 + ((~(((v13696 ^ -1) | (-(v13696 ^ -1))) >> 31)) & 2)) - (v13697 + ((~(((v13698 ^ -1) | (-(v13698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13705 = v13703[v13863];
        int * v13706 = v13654->mem;
        int v13865 = v13702 * 2;
        v13706[v13865] = v13704;
        int * v13708 = v13654->mem;
        int v13868 = (v13702 * 2) + 1;
        v13708[v13868] = v13705;
        ;
      } else {
        ;
      }
      int * v13713 = v13654->mem;
      int v13873 = ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) * 2;
      int v13714 = v13713[v13873];
      int v13874 = (((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) * 2) + 1;
      int v13715 = v13713[v13874];
      int * v13716 = v13654->cache_vals;
      int v13876 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13694 + ((~(((v13696 ^ -1) | (-(v13696 ^ -1))) >> 31)) & 2)) - (v13697 + ((~(((v13698 ^ -1) | (-(v13698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13716[v13876] = v13714;
      int * v13718 = v13654->cache_vals;
      int v13879 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13694 + ((~(((v13696 ^ -1) | (-(v13696 ^ -1))) >> 31)) & 2)) - (v13697 + ((~(((v13698 ^ -1) | (-(v13698 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13718[v13879] = v13715;
      int * v13720 = v13654->cache_tags;
      int v13882 = (int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1);
      v13720[v13858] = v13882;
      int * v13722 = v13654->cache_dirty;
      v13722[v13858] = 0;
      int * v13724 = v13654->cache_age;
      v13724[v13858] = 1;
      int * v13726 = v13654->cache_age;
      int v13727 = v13726[v13858];
      int v13728 = v13726[v13832];
      int v13888 = v13728 + ((int)((unsigned int)(v13728 - v13727) >> 31));
      v13726[v13832] = v13888;
      int * v13730 = v13654->cache_age;
      int v13731 = v13730[v13833];
      int v13890 = v13731 + ((int)((unsigned int)(v13731 - v13727) >> 31));
      v13730[v13833] = v13890;
      int * v13733 = v13654->cache_age;
      v13733[v13858] = 0;
      v13736 = v13858;
    }
    int * v13737 = v13654->cache_vals;
    int v13893 = v13736 * 2;
    int v13738 = v13737[v13893];
    int v13894 = (v13736 * 2) + 1;
    int v13739 = v13737[v13894];
    int v13895 = (((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v13678 + ((~(((v13680 ^ -1) | (-(v13680 ^ -1))) >> 31)) & 2)) - (v13681 + ((~(((v13682 ^ -1) | (-(v13682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13737[v13895] = v13738;
    int * v13741 = v13654->cache_vals;
    int v13898 = ((((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v13678 + ((~(((v13680 ^ -1) | (-(v13680 ^ -1))) >> 31)) & 2)) - (v13681 + ((~(((v13682 ^ -1) | (-(v13682 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13741[v13898] = v13739;
    int * v13743 = v13654->cache_tags;
    int v13901 = ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v13678 + ((~(((v13680 ^ -1) | (-(v13680 ^ -1))) >> 31)) & 2)) - (v13681 + ((~(((v13682 ^ -1) | (-(v13682 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13902 = (int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1);
    v13743[v13901] = v13902;
    int * v13745 = v13654->cache_dirty;
    v13745[v13901] = 0;
    int * v13747 = v13654->cache_age;
    v13747[v13901] = 1;
    int * v13749 = v13654->cache_age;
    int v13750 = v13749[v13901];
    int v13751 = v13749[v13830];
    int v13908 = v13751 + ((int)((unsigned int)(v13751 - v13750) >> 31));
    v13749[v13830] = v13908;
    int * v13753 = v13654->cache_age;
    int v13754 = v13753[v13831];
    int v13910 = v13754 + ((int)((unsigned int)(v13754 - v13750) >> 31));
    v13753[v13831] = v13910;
    int * v13756 = v13654->cache_age;
    v13756[v13901] = 0;
    v13759 = v13901;
  }
  int * v13760 = v13654->cache_vals;
  int v13913 = (v13759 * 2) + (((int)((unsigned int)(v13658 + 16) >> 2)) & 1);
  v13760[v13913] = v13659;
  int * v13762 = v13654->cache_tags;
  int v13763 = v13762[v13832];
  int v13764 = v13762[v13833];
  bool v13916 = !(((~(((v13763 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13763 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13764 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13764 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v13818;
  if (v13916) {
    int * v13765 = v13654->cache_age;
    int v13918 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13764 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))) | (-(v13764 ^ ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v13766 = v13765[v13918];
    int v13767 = v13765[v13832];
    int v13919 = v13767 + ((int)((unsigned int)(v13767 - v13766) >> 31));
    v13765[v13832] = v13919;
    int * v13769 = v13654->cache_age;
    int v13770 = v13769[v13833];
    int v13921 = v13770 + ((int)((unsigned int)(v13770 - v13766) >> 31));
    v13769[v13833] = v13921;
    int * v13772 = v13654->cache_age;
    v13772[v13918] = 0;
    v13818 = v13918;
  } else {
    int * v13775 = v13654->cache_age;
    int v13925 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2);
    int v13776 = v13775[v13925];
    int * v13777 = v13654->cache_tags;
    int v13778 = v13777[v13925];
    int v13779 = v13775[v13833];
    int v13780 = v13777[v13833];
    int * v13781 = v13654->cache_dirty;
    int v13928 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13776 + ((~(((v13778 ^ -1) | (-(v13778 ^ -1))) >> 31)) & 2)) - (v13779 + ((~(((v13780 ^ -1) | (-(v13780 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13782 = v13781[v13928];
    bool v13929 = !(v13782 == 0);
    if (v13929) {
      int * v13783 = v13654->cache_tags;
      int v13784 = v13783[v13928];
      int * v13785 = v13654->cache_vals;
      int v13932 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13776 + ((~(((v13778 ^ -1) | (-(v13778 ^ -1))) >> 31)) & 2)) - (v13779 + ((~(((v13780 ^ -1) | (-(v13780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v13786 = v13785[v13932];
      int v13933 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13776 + ((~(((v13778 ^ -1) | (-(v13778 ^ -1))) >> 31)) & 2)) - (v13779 + ((~(((v13780 ^ -1) | (-(v13780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v13787 = v13785[v13933];
      int * v13788 = v13654->mem;
      int v13935 = v13784 * 2;
      v13788[v13935] = v13786;
      int * v13790 = v13654->mem;
      int v13938 = (v13784 * 2) + 1;
      v13790[v13938] = v13787;
      ;
    } else {
      ;
    }
    int * v13795 = v13654->mem;
    int v13943 = ((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) * 2;
    int v13796 = v13795[v13943];
    int v13944 = (((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) * 2) + 1;
    int v13797 = v13795[v13944];
    int * v13798 = v13654->cache_vals;
    int v13946 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13776 + ((~(((v13778 ^ -1) | (-(v13778 ^ -1))) >> 31)) & 2)) - (v13779 + ((~(((v13780 ^ -1) | (-(v13780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13798[v13946] = v13796;
    int * v13800 = v13654->cache_vals;
    int v13949 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v13776 + ((~(((v13778 ^ -1) | (-(v13778 ^ -1))) >> 31)) & 2)) - (v13779 + ((~(((v13780 ^ -1) | (-(v13780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13800[v13949] = v13797;
    int * v13802 = v13654->cache_tags;
    int v13952 = (int)((unsigned int)((int)((unsigned int)(v13658 + 16) >> 2)) >> 1);
    v13802[v13928] = v13952;
    int * v13804 = v13654->cache_dirty;
    v13804[v13928] = 0;
    int * v13806 = v13654->cache_age;
    v13806[v13928] = 1;
    int * v13808 = v13654->cache_age;
    int v13809 = v13808[v13928];
    int v13810 = v13808[v13832];
    int v13958 = v13810 + ((int)((unsigned int)(v13810 - v13809) >> 31));
    v13808[v13832] = v13958;
    int * v13812 = v13654->cache_age;
    int v13813 = v13812[v13833];
    int v13960 = v13813 + ((int)((unsigned int)(v13813 - v13809) >> 31));
    v13812[v13833] = v13960;
    int * v13815 = v13654->cache_age;
    v13815[v13928] = 0;
    v13818 = v13928;
  }
  int * v13819 = v13654->cache_vals;
  int v13963 = (v13818 * 2) + (((int)((unsigned int)(v13658 + 16) >> 2)) & 1);
  v13819[v13963] = v13659;
  int * v13821 = v13654->cache_dirty;
  v13821[v13818] = 1;
  struct StateT * v13823 = slot_251(v13654);
  return v13823;
}

struct StateT * slot_259(struct StateT * v16634) {
  int v16635 = v16634->timer;
  int v16805 = v16635 + 1;
  v16634->timer = v16805;
  int * v16637 = v16634->regs;
  int v16638 = v16637[10];
  int v16639 = v16637[24];
  int * v16640 = v16634->cache_tags;
  int v16810 = (((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2;
  int v16641 = v16640[v16810];
  int v16811 = ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16642 = v16640[v16811];
  int v16812 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2);
  int v16643 = v16640[v16812];
  int v16813 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16644 = v16640[v16813];
  int v16645 = v16634->timer;
  int v16814 = v16645 + ((100 ^ (((~(((v16643 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16643 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16641 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16641 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v16642 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16642 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16643 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16643 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16634->timer = v16814;
  bool v16815 = !(((~(((v16641 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16641 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v16642 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16642 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31))) == 0);
  int v16739;
  if (v16815) {
    int * v16647 = v16634->cache_age;
    int v16817 = ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2) + ((~(((v16642 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16642 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) & 1);
    int v16648 = v16647[v16817];
    int v16649 = v16647[v16810];
    int v16818 = v16649 + ((int)((unsigned int)(v16649 - v16648) >> 31));
    v16647[v16810] = v16818;
    int * v16651 = v16634->cache_age;
    int v16652 = v16651[v16811];
    int v16820 = v16652 + ((int)((unsigned int)(v16652 - v16648) >> 31));
    v16651[v16811] = v16820;
    int * v16654 = v16634->cache_age;
    v16654[v16817] = 0;
    v16739 = v16817;
  } else {
    int * v16657 = v16634->cache_age;
    int v16824 = (((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2;
    int v16658 = v16657[v16824];
    int * v16659 = v16634->cache_tags;
    int v16660 = v16659[v16824];
    int v16661 = v16657[v16811];
    int v16662 = v16659[v16811];
    bool v16826 = !(((~(((v16643 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16643 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31))) == 0);
    int v16716;
    if (v16826) {
      int * v16663 = v16634->cache_age;
      int v16828 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16644 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) & 1);
      int v16664 = v16663[v16828];
      int v16665 = v16663[v16812];
      int v16829 = v16665 + ((int)((unsigned int)(v16665 - v16664) >> 31));
      v16663[v16812] = v16829;
      int * v16667 = v16634->cache_age;
      int v16668 = v16667[v16813];
      int v16831 = v16668 + ((int)((unsigned int)(v16668 - v16664) >> 31));
      v16667[v16813] = v16831;
      int * v16670 = v16634->cache_age;
      v16670[v16828] = 0;
      v16716 = v16828;
    } else {
      int * v16673 = v16634->cache_age;
      int v16835 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2);
      int v16674 = v16673[v16835];
      int * v16675 = v16634->cache_tags;
      int v16676 = v16675[v16835];
      int v16677 = v16673[v16813];
      int v16678 = v16675[v16813];
      int * v16679 = v16634->cache_dirty;
      int v16838 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16674 + ((~(((v16676 ^ -1) | (-(v16676 ^ -1))) >> 31)) & 2)) - (v16677 + ((~(((v16678 ^ -1) | (-(v16678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16680 = v16679[v16838];
      bool v16839 = !(v16680 == 0);
      if (v16839) {
        int * v16681 = v16634->cache_tags;
        int v16682 = v16681[v16838];
        int * v16683 = v16634->cache_vals;
        int v16842 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16674 + ((~(((v16676 ^ -1) | (-(v16676 ^ -1))) >> 31)) & 2)) - (v16677 + ((~(((v16678 ^ -1) | (-(v16678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16684 = v16683[v16842];
        int v16843 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16674 + ((~(((v16676 ^ -1) | (-(v16676 ^ -1))) >> 31)) & 2)) - (v16677 + ((~(((v16678 ^ -1) | (-(v16678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16685 = v16683[v16843];
        int * v16686 = v16634->mem;
        int v16845 = v16682 * 2;
        v16686[v16845] = v16684;
        int * v16688 = v16634->mem;
        int v16848 = (v16682 * 2) + 1;
        v16688[v16848] = v16685;
        ;
      } else {
        ;
      }
      int * v16693 = v16634->mem;
      int v16853 = ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) * 2;
      int v16694 = v16693[v16853];
      int v16854 = (((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) * 2) + 1;
      int v16695 = v16693[v16854];
      int * v16696 = v16634->cache_vals;
      int v16856 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16674 + ((~(((v16676 ^ -1) | (-(v16676 ^ -1))) >> 31)) & 2)) - (v16677 + ((~(((v16678 ^ -1) | (-(v16678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16696[v16856] = v16694;
      int * v16698 = v16634->cache_vals;
      int v16859 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16674 + ((~(((v16676 ^ -1) | (-(v16676 ^ -1))) >> 31)) & 2)) - (v16677 + ((~(((v16678 ^ -1) | (-(v16678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16698[v16859] = v16695;
      int * v16700 = v16634->cache_tags;
      int v16862 = (int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1);
      v16700[v16838] = v16862;
      int * v16702 = v16634->cache_dirty;
      v16702[v16838] = 0;
      int * v16704 = v16634->cache_age;
      v16704[v16838] = 1;
      int * v16706 = v16634->cache_age;
      int v16707 = v16706[v16838];
      int v16708 = v16706[v16812];
      int v16868 = v16708 + ((int)((unsigned int)(v16708 - v16707) >> 31));
      v16706[v16812] = v16868;
      int * v16710 = v16634->cache_age;
      int v16711 = v16710[v16813];
      int v16870 = v16711 + ((int)((unsigned int)(v16711 - v16707) >> 31));
      v16710[v16813] = v16870;
      int * v16713 = v16634->cache_age;
      v16713[v16838] = 0;
      v16716 = v16838;
    }
    int * v16717 = v16634->cache_vals;
    int v16873 = v16716 * 2;
    int v16718 = v16717[v16873];
    int v16874 = (v16716 * 2) + 1;
    int v16719 = v16717[v16874];
    int v16875 = (((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v16658 + ((~(((v16660 ^ -1) | (-(v16660 ^ -1))) >> 31)) & 2)) - (v16661 + ((~(((v16662 ^ -1) | (-(v16662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16717[v16875] = v16718;
    int * v16721 = v16634->cache_vals;
    int v16878 = ((((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v16658 + ((~(((v16660 ^ -1) | (-(v16660 ^ -1))) >> 31)) & 2)) - (v16661 + ((~(((v16662 ^ -1) | (-(v16662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16721[v16878] = v16719;
    int * v16723 = v16634->cache_tags;
    int v16881 = ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v16658 + ((~(((v16660 ^ -1) | (-(v16660 ^ -1))) >> 31)) & 2)) - (v16661 + ((~(((v16662 ^ -1) | (-(v16662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16882 = (int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1);
    v16723[v16881] = v16882;
    int * v16725 = v16634->cache_dirty;
    v16725[v16881] = 0;
    int * v16727 = v16634->cache_age;
    v16727[v16881] = 1;
    int * v16729 = v16634->cache_age;
    int v16730 = v16729[v16881];
    int v16731 = v16729[v16810];
    int v16888 = v16731 + ((int)((unsigned int)(v16731 - v16730) >> 31));
    v16729[v16810] = v16888;
    int * v16733 = v16634->cache_age;
    int v16734 = v16733[v16811];
    int v16890 = v16734 + ((int)((unsigned int)(v16734 - v16730) >> 31));
    v16733[v16811] = v16890;
    int * v16736 = v16634->cache_age;
    v16736[v16881] = 0;
    v16739 = v16881;
  }
  int * v16740 = v16634->cache_vals;
  int v16893 = (v16739 * 2) + (((int)((unsigned int)(v16638 + 52) >> 2)) & 1);
  v16740[v16893] = v16639;
  int * v16742 = v16634->cache_tags;
  int v16743 = v16742[v16812];
  int v16744 = v16742[v16813];
  bool v16896 = !(((~(((v16743 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16743 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v16744 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16744 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31))) == 0);
  int v16798;
  if (v16896) {
    int * v16745 = v16634->cache_age;
    int v16898 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16744 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))) | (-(v16744 ^ ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1))))) >> 31)) & 1);
    int v16746 = v16745[v16898];
    int v16747 = v16745[v16812];
    int v16899 = v16747 + ((int)((unsigned int)(v16747 - v16746) >> 31));
    v16745[v16812] = v16899;
    int * v16749 = v16634->cache_age;
    int v16750 = v16749[v16813];
    int v16901 = v16750 + ((int)((unsigned int)(v16750 - v16746) >> 31));
    v16749[v16813] = v16901;
    int * v16752 = v16634->cache_age;
    v16752[v16898] = 0;
    v16798 = v16898;
  } else {
    int * v16755 = v16634->cache_age;
    int v16905 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2);
    int v16756 = v16755[v16905];
    int * v16757 = v16634->cache_tags;
    int v16758 = v16757[v16905];
    int v16759 = v16755[v16813];
    int v16760 = v16757[v16813];
    int * v16761 = v16634->cache_dirty;
    int v16908 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16756 + ((~(((v16758 ^ -1) | (-(v16758 ^ -1))) >> 31)) & 2)) - (v16759 + ((~(((v16760 ^ -1) | (-(v16760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16762 = v16761[v16908];
    bool v16909 = !(v16762 == 0);
    if (v16909) {
      int * v16763 = v16634->cache_tags;
      int v16764 = v16763[v16908];
      int * v16765 = v16634->cache_vals;
      int v16912 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16756 + ((~(((v16758 ^ -1) | (-(v16758 ^ -1))) >> 31)) & 2)) - (v16759 + ((~(((v16760 ^ -1) | (-(v16760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v16766 = v16765[v16912];
      int v16913 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16756 + ((~(((v16758 ^ -1) | (-(v16758 ^ -1))) >> 31)) & 2)) - (v16759 + ((~(((v16760 ^ -1) | (-(v16760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v16767 = v16765[v16913];
      int * v16768 = v16634->mem;
      int v16915 = v16764 * 2;
      v16768[v16915] = v16766;
      int * v16770 = v16634->mem;
      int v16918 = (v16764 * 2) + 1;
      v16770[v16918] = v16767;
      ;
    } else {
      ;
    }
    int * v16775 = v16634->mem;
    int v16923 = ((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) * 2;
    int v16776 = v16775[v16923];
    int v16924 = (((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) * 2) + 1;
    int v16777 = v16775[v16924];
    int * v16778 = v16634->cache_vals;
    int v16926 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16756 + ((~(((v16758 ^ -1) | (-(v16758 ^ -1))) >> 31)) & 2)) - (v16759 + ((~(((v16760 ^ -1) | (-(v16760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16778[v16926] = v16776;
    int * v16780 = v16634->cache_vals;
    int v16929 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v16756 + ((~(((v16758 ^ -1) | (-(v16758 ^ -1))) >> 31)) & 2)) - (v16759 + ((~(((v16760 ^ -1) | (-(v16760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16780[v16929] = v16777;
    int * v16782 = v16634->cache_tags;
    int v16932 = (int)((unsigned int)((int)((unsigned int)(v16638 + 52) >> 2)) >> 1);
    v16782[v16908] = v16932;
    int * v16784 = v16634->cache_dirty;
    v16784[v16908] = 0;
    int * v16786 = v16634->cache_age;
    v16786[v16908] = 1;
    int * v16788 = v16634->cache_age;
    int v16789 = v16788[v16908];
    int v16790 = v16788[v16812];
    int v16938 = v16790 + ((int)((unsigned int)(v16790 - v16789) >> 31));
    v16788[v16812] = v16938;
    int * v16792 = v16634->cache_age;
    int v16793 = v16792[v16813];
    int v16940 = v16793 + ((int)((unsigned int)(v16793 - v16789) >> 31));
    v16792[v16813] = v16940;
    int * v16795 = v16634->cache_age;
    v16795[v16908] = 0;
    v16798 = v16908;
  }
  int * v16799 = v16634->cache_vals;
  int v16943 = (v16798 * 2) + (((int)((unsigned int)(v16638 + 52) >> 2)) & 1);
  v16799[v16943] = v16639;
  int * v16801 = v16634->cache_dirty;
  v16801[v16798] = 1;
  struct StateT * v16803 = slot_260(v16634);
  return v16803;
}

struct StateT * slot_117(struct StateT * v20562) {
  int v20563 = v20562->timer;
  int v20571 = v20563 + 1;
  v20562->timer = v20571;
  int * v20565 = v20562->regs;
  int v20566 = v20565[15];
  int v20567 = v20565[6];
  int v20575 = v20566 | v20567;
  v20565[15] = v20575;
  struct StateT * v20569 = slot_118(v20562);
  return v20569;
}

struct StateT * slot_249(struct StateT * v13323) {
  int v13324 = v13323->timer;
  int v13494 = v13324 + 1;
  v13323->timer = v13494;
  int * v13326 = v13323->regs;
  int v13327 = v13326[10];
  int v13328 = v13326[14];
  int * v13329 = v13323->cache_tags;
  int v13499 = (((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2;
  int v13330 = v13329[v13499];
  int v13500 = ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13331 = v13329[v13500];
  int v13501 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2);
  int v13332 = v13329[v13501];
  int v13502 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13333 = v13329[v13502];
  int v13334 = v13323->timer;
  int v13503 = v13334 + ((100 ^ (((~(((v13332 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13332 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13330 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13330 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13331 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13331 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13332 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13332 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13323->timer = v13503;
  bool v13504 = !(((~(((v13330 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13330 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13331 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13331 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v13428;
  if (v13504) {
    int * v13336 = v13323->cache_age;
    int v13506 = ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v13331 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13331 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v13337 = v13336[v13506];
    int v13338 = v13336[v13499];
    int v13507 = v13338 + ((int)((unsigned int)(v13338 - v13337) >> 31));
    v13336[v13499] = v13507;
    int * v13340 = v13323->cache_age;
    int v13341 = v13340[v13500];
    int v13509 = v13341 + ((int)((unsigned int)(v13341 - v13337) >> 31));
    v13340[v13500] = v13509;
    int * v13343 = v13323->cache_age;
    v13343[v13506] = 0;
    v13428 = v13506;
  } else {
    int * v13346 = v13323->cache_age;
    int v13513 = (((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2;
    int v13347 = v13346[v13513];
    int * v13348 = v13323->cache_tags;
    int v13349 = v13348[v13513];
    int v13350 = v13346[v13500];
    int v13351 = v13348[v13500];
    bool v13515 = !(((~(((v13332 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13332 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v13405;
    if (v13515) {
      int * v13352 = v13323->cache_age;
      int v13517 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13333 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v13353 = v13352[v13517];
      int v13354 = v13352[v13501];
      int v13518 = v13354 + ((int)((unsigned int)(v13354 - v13353) >> 31));
      v13352[v13501] = v13518;
      int * v13356 = v13323->cache_age;
      int v13357 = v13356[v13502];
      int v13520 = v13357 + ((int)((unsigned int)(v13357 - v13353) >> 31));
      v13356[v13502] = v13520;
      int * v13359 = v13323->cache_age;
      v13359[v13517] = 0;
      v13405 = v13517;
    } else {
      int * v13362 = v13323->cache_age;
      int v13524 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2);
      int v13363 = v13362[v13524];
      int * v13364 = v13323->cache_tags;
      int v13365 = v13364[v13524];
      int v13366 = v13362[v13502];
      int v13367 = v13364[v13502];
      int * v13368 = v13323->cache_dirty;
      int v13527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13363 + ((~(((v13365 ^ -1) | (-(v13365 ^ -1))) >> 31)) & 2)) - (v13366 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13369 = v13368[v13527];
      bool v13528 = !(v13369 == 0);
      if (v13528) {
        int * v13370 = v13323->cache_tags;
        int v13371 = v13370[v13527];
        int * v13372 = v13323->cache_vals;
        int v13531 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13363 + ((~(((v13365 ^ -1) | (-(v13365 ^ -1))) >> 31)) & 2)) - (v13366 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13373 = v13372[v13531];
        int v13532 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13363 + ((~(((v13365 ^ -1) | (-(v13365 ^ -1))) >> 31)) & 2)) - (v13366 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13374 = v13372[v13532];
        int * v13375 = v13323->mem;
        int v13534 = v13371 * 2;
        v13375[v13534] = v13373;
        int * v13377 = v13323->mem;
        int v13537 = (v13371 * 2) + 1;
        v13377[v13537] = v13374;
        ;
      } else {
        ;
      }
      int * v13382 = v13323->mem;
      int v13542 = ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) * 2;
      int v13383 = v13382[v13542];
      int v13543 = (((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) * 2) + 1;
      int v13384 = v13382[v13543];
      int * v13385 = v13323->cache_vals;
      int v13545 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13363 + ((~(((v13365 ^ -1) | (-(v13365 ^ -1))) >> 31)) & 2)) - (v13366 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13385[v13545] = v13383;
      int * v13387 = v13323->cache_vals;
      int v13548 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13363 + ((~(((v13365 ^ -1) | (-(v13365 ^ -1))) >> 31)) & 2)) - (v13366 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13387[v13548] = v13384;
      int * v13389 = v13323->cache_tags;
      int v13551 = (int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1);
      v13389[v13527] = v13551;
      int * v13391 = v13323->cache_dirty;
      v13391[v13527] = 0;
      int * v13393 = v13323->cache_age;
      v13393[v13527] = 1;
      int * v13395 = v13323->cache_age;
      int v13396 = v13395[v13527];
      int v13397 = v13395[v13501];
      int v13557 = v13397 + ((int)((unsigned int)(v13397 - v13396) >> 31));
      v13395[v13501] = v13557;
      int * v13399 = v13323->cache_age;
      int v13400 = v13399[v13502];
      int v13559 = v13400 + ((int)((unsigned int)(v13400 - v13396) >> 31));
      v13399[v13502] = v13559;
      int * v13402 = v13323->cache_age;
      v13402[v13527] = 0;
      v13405 = v13527;
    }
    int * v13406 = v13323->cache_vals;
    int v13562 = v13405 * 2;
    int v13407 = v13406[v13562];
    int v13563 = (v13405 * 2) + 1;
    int v13408 = v13406[v13563];
    int v13564 = (((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v13347 + ((~(((v13349 ^ -1) | (-(v13349 ^ -1))) >> 31)) & 2)) - (v13350 + ((~(((v13351 ^ -1) | (-(v13351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13406[v13564] = v13407;
    int * v13410 = v13323->cache_vals;
    int v13567 = ((((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v13347 + ((~(((v13349 ^ -1) | (-(v13349 ^ -1))) >> 31)) & 2)) - (v13350 + ((~(((v13351 ^ -1) | (-(v13351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13410[v13567] = v13408;
    int * v13412 = v13323->cache_tags;
    int v13570 = ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v13347 + ((~(((v13349 ^ -1) | (-(v13349 ^ -1))) >> 31)) & 2)) - (v13350 + ((~(((v13351 ^ -1) | (-(v13351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13571 = (int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1);
    v13412[v13570] = v13571;
    int * v13414 = v13323->cache_dirty;
    v13414[v13570] = 0;
    int * v13416 = v13323->cache_age;
    v13416[v13570] = 1;
    int * v13418 = v13323->cache_age;
    int v13419 = v13418[v13570];
    int v13420 = v13418[v13499];
    int v13577 = v13420 + ((int)((unsigned int)(v13420 - v13419) >> 31));
    v13418[v13499] = v13577;
    int * v13422 = v13323->cache_age;
    int v13423 = v13422[v13500];
    int v13579 = v13423 + ((int)((unsigned int)(v13423 - v13419) >> 31));
    v13422[v13500] = v13579;
    int * v13425 = v13323->cache_age;
    v13425[v13570] = 0;
    v13428 = v13570;
  }
  int * v13429 = v13323->cache_vals;
  int v13582 = (v13428 * 2) + (((int)((unsigned int)(v13327 + 12) >> 2)) & 1);
  v13429[v13582] = v13328;
  int * v13431 = v13323->cache_tags;
  int v13432 = v13431[v13501];
  int v13433 = v13431[v13502];
  bool v13585 = !(((~(((v13432 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13432 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v13433 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13433 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v13487;
  if (v13585) {
    int * v13434 = v13323->cache_age;
    int v13587 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13433 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))) | (-(v13433 ^ ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v13435 = v13434[v13587];
    int v13436 = v13434[v13501];
    int v13588 = v13436 + ((int)((unsigned int)(v13436 - v13435) >> 31));
    v13434[v13501] = v13588;
    int * v13438 = v13323->cache_age;
    int v13439 = v13438[v13502];
    int v13590 = v13439 + ((int)((unsigned int)(v13439 - v13435) >> 31));
    v13438[v13502] = v13590;
    int * v13441 = v13323->cache_age;
    v13441[v13587] = 0;
    v13487 = v13587;
  } else {
    int * v13444 = v13323->cache_age;
    int v13594 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2);
    int v13445 = v13444[v13594];
    int * v13446 = v13323->cache_tags;
    int v13447 = v13446[v13594];
    int v13448 = v13444[v13502];
    int v13449 = v13446[v13502];
    int * v13450 = v13323->cache_dirty;
    int v13597 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13445 + ((~(((v13447 ^ -1) | (-(v13447 ^ -1))) >> 31)) & 2)) - (v13448 + ((~(((v13449 ^ -1) | (-(v13449 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13451 = v13450[v13597];
    bool v13598 = !(v13451 == 0);
    if (v13598) {
      int * v13452 = v13323->cache_tags;
      int v13453 = v13452[v13597];
      int * v13454 = v13323->cache_vals;
      int v13601 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13445 + ((~(((v13447 ^ -1) | (-(v13447 ^ -1))) >> 31)) & 2)) - (v13448 + ((~(((v13449 ^ -1) | (-(v13449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v13455 = v13454[v13601];
      int v13602 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13445 + ((~(((v13447 ^ -1) | (-(v13447 ^ -1))) >> 31)) & 2)) - (v13448 + ((~(((v13449 ^ -1) | (-(v13449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v13456 = v13454[v13602];
      int * v13457 = v13323->mem;
      int v13604 = v13453 * 2;
      v13457[v13604] = v13455;
      int * v13459 = v13323->mem;
      int v13607 = (v13453 * 2) + 1;
      v13459[v13607] = v13456;
      ;
    } else {
      ;
    }
    int * v13464 = v13323->mem;
    int v13612 = ((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) * 2;
    int v13465 = v13464[v13612];
    int v13613 = (((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) * 2) + 1;
    int v13466 = v13464[v13613];
    int * v13467 = v13323->cache_vals;
    int v13615 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13445 + ((~(((v13447 ^ -1) | (-(v13447 ^ -1))) >> 31)) & 2)) - (v13448 + ((~(((v13449 ^ -1) | (-(v13449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13467[v13615] = v13465;
    int * v13469 = v13323->cache_vals;
    int v13618 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v13445 + ((~(((v13447 ^ -1) | (-(v13447 ^ -1))) >> 31)) & 2)) - (v13448 + ((~(((v13449 ^ -1) | (-(v13449 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13469[v13618] = v13466;
    int * v13471 = v13323->cache_tags;
    int v13621 = (int)((unsigned int)((int)((unsigned int)(v13327 + 12) >> 2)) >> 1);
    v13471[v13597] = v13621;
    int * v13473 = v13323->cache_dirty;
    v13473[v13597] = 0;
    int * v13475 = v13323->cache_age;
    v13475[v13597] = 1;
    int * v13477 = v13323->cache_age;
    int v13478 = v13477[v13597];
    int v13479 = v13477[v13501];
    int v13627 = v13479 + ((int)((unsigned int)(v13479 - v13478) >> 31));
    v13477[v13501] = v13627;
    int * v13481 = v13323->cache_age;
    int v13482 = v13481[v13502];
    int v13629 = v13482 + ((int)((unsigned int)(v13482 - v13478) >> 31));
    v13481[v13502] = v13629;
    int * v13484 = v13323->cache_age;
    v13484[v13597] = 0;
    v13487 = v13597;
  }
  int * v13488 = v13323->cache_vals;
  int v13632 = (v13487 * 2) + (((int)((unsigned int)(v13327 + 12) >> 2)) & 1);
  v13488[v13632] = v13328;
  int * v13490 = v13323->cache_dirty;
  v13490[v13487] = 1;
  struct StateT * v13492 = slot_250(v13323);
  return v13492;
}

struct StateT * slot_90(struct StateT * v14631) {
  int v14632 = v14631->timer;
  int v14640 = v14632 + 1;
  v14631->timer = v14640;
  int * v14634 = v14631->regs;
  int v14635 = v14634[25];
  int v14636 = v14634[18];
  int v14644 = v14635 ^ v14636;
  v14634[25] = v14644;
  struct StateT * v14638 = slot_91(v14631);
  return v14638;
}

struct StateT * slot_11(struct StateT * v3162) {
  int v3163 = v3162->timer;
  int v3333 = v3163 + 1;
  v3162->timer = v3333;
  int * v3165 = v3162->regs;
  int v3166 = v3165[2];
  int v3167 = v3165[25];
  int * v3168 = v3162->cache_tags;
  int v3338 = (((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2;
  int v3169 = v3168[v3338];
  int v3339 = ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3170 = v3168[v3339];
  int v3340 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2);
  int v3171 = v3168[v3340];
  int v3341 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3172 = v3168[v3341];
  int v3173 = v3162->timer;
  int v3342 = v3173 + ((100 ^ (((~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3169 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3169 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v3170 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3170 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3162->timer = v3342;
  bool v3343 = !(((~(((v3169 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3169 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v3170 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3170 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31))) == 0);
  int v3267;
  if (v3343) {
    int * v3175 = v3162->cache_age;
    int v3345 = ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2) + ((~(((v3170 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3170 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) & 1);
    int v3176 = v3175[v3345];
    int v3177 = v3175[v3338];
    int v3346 = v3177 + ((int)((unsigned int)(v3177 - v3176) >> 31));
    v3175[v3338] = v3346;
    int * v3179 = v3162->cache_age;
    int v3180 = v3179[v3339];
    int v3348 = v3180 + ((int)((unsigned int)(v3180 - v3176) >> 31));
    v3179[v3339] = v3348;
    int * v3182 = v3162->cache_age;
    v3182[v3345] = 0;
    v3267 = v3345;
  } else {
    int * v3185 = v3162->cache_age;
    int v3352 = (((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2;
    int v3186 = v3185[v3352];
    int * v3187 = v3162->cache_tags;
    int v3188 = v3187[v3352];
    int v3189 = v3185[v3339];
    int v3190 = v3187[v3339];
    bool v3354 = !(((~(((v3171 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3171 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31))) == 0);
    int v3244;
    if (v3354) {
      int * v3191 = v3162->cache_age;
      int v3356 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3172 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) & 1);
      int v3192 = v3191[v3356];
      int v3193 = v3191[v3340];
      int v3357 = v3193 + ((int)((unsigned int)(v3193 - v3192) >> 31));
      v3191[v3340] = v3357;
      int * v3195 = v3162->cache_age;
      int v3196 = v3195[v3341];
      int v3359 = v3196 + ((int)((unsigned int)(v3196 - v3192) >> 31));
      v3195[v3341] = v3359;
      int * v3198 = v3162->cache_age;
      v3198[v3356] = 0;
      v3244 = v3356;
    } else {
      int * v3201 = v3162->cache_age;
      int v3363 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2);
      int v3202 = v3201[v3363];
      int * v3203 = v3162->cache_tags;
      int v3204 = v3203[v3363];
      int v3205 = v3201[v3341];
      int v3206 = v3203[v3341];
      int * v3207 = v3162->cache_dirty;
      int v3366 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3202 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2)) - (v3205 + ((~(((v3206 ^ -1) | (-(v3206 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3208 = v3207[v3366];
      bool v3367 = !(v3208 == 0);
      if (v3367) {
        int * v3209 = v3162->cache_tags;
        int v3210 = v3209[v3366];
        int * v3211 = v3162->cache_vals;
        int v3370 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3202 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2)) - (v3205 + ((~(((v3206 ^ -1) | (-(v3206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3212 = v3211[v3370];
        int v3371 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3202 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2)) - (v3205 + ((~(((v3206 ^ -1) | (-(v3206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3213 = v3211[v3371];
        int * v3214 = v3162->mem;
        int v3373 = v3210 * 2;
        v3214[v3373] = v3212;
        int * v3216 = v3162->mem;
        int v3376 = (v3210 * 2) + 1;
        v3216[v3376] = v3213;
        ;
      } else {
        ;
      }
      int * v3221 = v3162->mem;
      int v3381 = ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) * 2;
      int v3222 = v3221[v3381];
      int v3382 = (((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) * 2) + 1;
      int v3223 = v3221[v3382];
      int * v3224 = v3162->cache_vals;
      int v3384 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3202 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2)) - (v3205 + ((~(((v3206 ^ -1) | (-(v3206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3224[v3384] = v3222;
      int * v3226 = v3162->cache_vals;
      int v3387 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3202 + ((~(((v3204 ^ -1) | (-(v3204 ^ -1))) >> 31)) & 2)) - (v3205 + ((~(((v3206 ^ -1) | (-(v3206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3226[v3387] = v3223;
      int * v3228 = v3162->cache_tags;
      int v3390 = (int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1);
      v3228[v3366] = v3390;
      int * v3230 = v3162->cache_dirty;
      v3230[v3366] = 0;
      int * v3232 = v3162->cache_age;
      v3232[v3366] = 1;
      int * v3234 = v3162->cache_age;
      int v3235 = v3234[v3366];
      int v3236 = v3234[v3340];
      int v3396 = v3236 + ((int)((unsigned int)(v3236 - v3235) >> 31));
      v3234[v3340] = v3396;
      int * v3238 = v3162->cache_age;
      int v3239 = v3238[v3341];
      int v3398 = v3239 + ((int)((unsigned int)(v3239 - v3235) >> 31));
      v3238[v3341] = v3398;
      int * v3241 = v3162->cache_age;
      v3241[v3366] = 0;
      v3244 = v3366;
    }
    int * v3245 = v3162->cache_vals;
    int v3401 = v3244 * 2;
    int v3246 = v3245[v3401];
    int v3402 = (v3244 * 2) + 1;
    int v3247 = v3245[v3402];
    int v3403 = (((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v3186 + ((~(((v3188 ^ -1) | (-(v3188 ^ -1))) >> 31)) & 2)) - (v3189 + ((~(((v3190 ^ -1) | (-(v3190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3245[v3403] = v3246;
    int * v3249 = v3162->cache_vals;
    int v3406 = ((((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v3186 + ((~(((v3188 ^ -1) | (-(v3188 ^ -1))) >> 31)) & 2)) - (v3189 + ((~(((v3190 ^ -1) | (-(v3190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3249[v3406] = v3247;
    int * v3251 = v3162->cache_tags;
    int v3409 = ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 1) * 2) + ((((v3186 + ((~(((v3188 ^ -1) | (-(v3188 ^ -1))) >> 31)) & 2)) - (v3189 + ((~(((v3190 ^ -1) | (-(v3190 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3410 = (int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1);
    v3251[v3409] = v3410;
    int * v3253 = v3162->cache_dirty;
    v3253[v3409] = 0;
    int * v3255 = v3162->cache_age;
    v3255[v3409] = 1;
    int * v3257 = v3162->cache_age;
    int v3258 = v3257[v3409];
    int v3259 = v3257[v3338];
    int v3416 = v3259 + ((int)((unsigned int)(v3259 - v3258) >> 31));
    v3257[v3338] = v3416;
    int * v3261 = v3162->cache_age;
    int v3262 = v3261[v3339];
    int v3418 = v3262 + ((int)((unsigned int)(v3262 - v3258) >> 31));
    v3261[v3339] = v3418;
    int * v3264 = v3162->cache_age;
    v3264[v3409] = 0;
    v3267 = v3409;
  }
  int * v3268 = v3162->cache_vals;
  int v3421 = (v3267 * 2) + (((int)((unsigned int)(v3166 + 52) >> 2)) & 1);
  v3268[v3421] = v3167;
  int * v3270 = v3162->cache_tags;
  int v3271 = v3270[v3340];
  int v3272 = v3270[v3341];
  bool v3424 = !(((~(((v3271 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3271 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) | (~(((v3272 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3272 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31))) == 0);
  int v3326;
  if (v3424) {
    int * v3273 = v3162->cache_age;
    int v3426 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3272 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))) | (-(v3272 ^ ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1))))) >> 31)) & 1);
    int v3274 = v3273[v3426];
    int v3275 = v3273[v3340];
    int v3427 = v3275 + ((int)((unsigned int)(v3275 - v3274) >> 31));
    v3273[v3340] = v3427;
    int * v3277 = v3162->cache_age;
    int v3278 = v3277[v3341];
    int v3429 = v3278 + ((int)((unsigned int)(v3278 - v3274) >> 31));
    v3277[v3341] = v3429;
    int * v3280 = v3162->cache_age;
    v3280[v3426] = 0;
    v3326 = v3426;
  } else {
    int * v3283 = v3162->cache_age;
    int v3433 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2);
    int v3284 = v3283[v3433];
    int * v3285 = v3162->cache_tags;
    int v3286 = v3285[v3433];
    int v3287 = v3283[v3341];
    int v3288 = v3285[v3341];
    int * v3289 = v3162->cache_dirty;
    int v3436 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3284 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2)) - (v3287 + ((~(((v3288 ^ -1) | (-(v3288 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3290 = v3289[v3436];
    bool v3437 = !(v3290 == 0);
    if (v3437) {
      int * v3291 = v3162->cache_tags;
      int v3292 = v3291[v3436];
      int * v3293 = v3162->cache_vals;
      int v3440 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3284 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2)) - (v3287 + ((~(((v3288 ^ -1) | (-(v3288 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3294 = v3293[v3440];
      int v3441 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3284 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2)) - (v3287 + ((~(((v3288 ^ -1) | (-(v3288 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3295 = v3293[v3441];
      int * v3296 = v3162->mem;
      int v3443 = v3292 * 2;
      v3296[v3443] = v3294;
      int * v3298 = v3162->mem;
      int v3446 = (v3292 * 2) + 1;
      v3298[v3446] = v3295;
      ;
    } else {
      ;
    }
    int * v3303 = v3162->mem;
    int v3451 = ((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) * 2;
    int v3304 = v3303[v3451];
    int v3452 = (((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) * 2) + 1;
    int v3305 = v3303[v3452];
    int * v3306 = v3162->cache_vals;
    int v3454 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3284 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2)) - (v3287 + ((~(((v3288 ^ -1) | (-(v3288 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3306[v3454] = v3304;
    int * v3308 = v3162->cache_vals;
    int v3457 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1)) & 3) * 2)) + ((((v3284 + ((~(((v3286 ^ -1) | (-(v3286 ^ -1))) >> 31)) & 2)) - (v3287 + ((~(((v3288 ^ -1) | (-(v3288 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3308[v3457] = v3305;
    int * v3310 = v3162->cache_tags;
    int v3460 = (int)((unsigned int)((int)((unsigned int)(v3166 + 52) >> 2)) >> 1);
    v3310[v3436] = v3460;
    int * v3312 = v3162->cache_dirty;
    v3312[v3436] = 0;
    int * v3314 = v3162->cache_age;
    v3314[v3436] = 1;
    int * v3316 = v3162->cache_age;
    int v3317 = v3316[v3436];
    int v3318 = v3316[v3340];
    int v3466 = v3318 + ((int)((unsigned int)(v3318 - v3317) >> 31));
    v3316[v3340] = v3466;
    int * v3320 = v3162->cache_age;
    int v3321 = v3320[v3341];
    int v3468 = v3321 + ((int)((unsigned int)(v3321 - v3317) >> 31));
    v3320[v3341] = v3468;
    int * v3323 = v3162->cache_age;
    v3323[v3436] = 0;
    v3326 = v3436;
  }
  int * v3327 = v3162->cache_vals;
  int v3471 = (v3326 * 2) + (((int)((unsigned int)(v3166 + 52) >> 2)) & 1);
  v3327[v3471] = v3167;
  int * v3329 = v3162->cache_dirty;
  v3329[v3326] = 1;
  struct StateT * v3331 = slot_12(v3162);
  return v3331;
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
  
  // a10, 16 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 64;
  s2.regs[11] = 64;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[16 + i] = secret(0, 20);
    s2.mem[16 + i] = secret(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = secret(0, 20);
    s2.mem[20 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}