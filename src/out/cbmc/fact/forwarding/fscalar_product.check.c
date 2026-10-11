// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT * slot_120(struct StateT * v8172);
struct StateT * slot_167(struct StateT * v10172);
struct StateT * slot_509(struct StateT * v30511);
struct StateT * slot_152(struct StateT * v8795);
struct StateT * slot_231(struct StateT * v15278);
struct StateT * slot_355(struct StateT * v23192);
struct StateT * slot_1032(struct StateT * v65660);
struct StateT * slot_1060(struct StateT * v72756);
struct StateT * slot_616(struct StateT * v32563);
struct StateT * slot_984(struct StateT * v61544);
struct StateT * slot_232(struct StateT * v15295);
struct StateT * slot_466(struct StateT * v29748);
struct StateT * slot_764(struct StateT * v35954);
struct StateT * slot_304(struct StateT * v16644);
struct StateT * slot_31(struct StateT * v3594);
struct StateT * slot_730(struct StateT * v34687);
struct StateT * slot_585(struct StateT * v31967);
struct StateT * slot_241(struct StateT * v15461);
struct StateT * slot_611(struct StateT * v32435);
struct StateT * slot_160(struct StateT * v9887);
struct StateT * slot_745(struct StateT * v34990);
struct StateT * slot_150(struct StateT * v8748);
struct StateT * slot_391(struct StateT * v26123);
struct StateT * slot_74(struct StateT * v5144);
struct StateT * slot_372(struct StateT * v22429);
struct StateT * slot_403(struct StateT * v26403);
struct StateT * slot_325(struct StateT * v18018);
struct StateT * slot_895(struct StateT * v55178);
struct StateT * slot_28(struct StateT * v3618);
struct StateT * slot_517(struct StateT * v30660);
struct StateT * slot_1080(struct StateT * v75434);
struct StateT * slot_1009(struct StateT * v63065);
struct StateT * slot_566(struct StateT * v31600);
struct StateT * slot_923(struct StateT * v56834);
struct StateT * slot_154(struct StateT * v8871);
struct StateT * slot_260(struct StateT * v15817);
struct StateT * slot_1090(struct StateT * v81192);
struct StateT * slot_305(struct StateT * v16665);
struct StateT * slot_662(struct StateT * v33465);
struct StateT * slot_34(struct StateT * v4084);
struct StateT * slot_971(struct StateT * v61150);
struct StateT * slot_1016(struct StateT * v63177);
struct StateT * slot_850(struct StateT * v47384);
struct StateT * slot_21(struct StateT * v2383);
struct StateT * slot_1116(struct StateT * v85945);
struct StateT * slot_118(struct StateT * v8131);
struct StateT * slot_833(struct StateT * v45937);
struct StateT * slot_376(struct StateT * v22529);
struct StateT * slot_373(struct StateT * v22445);
struct StateT * slot_146(struct StateT * v8663);
struct StateT * slot_383(struct StateT * v23583);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v30140);
struct StateT * slot_148(struct StateT * v8695);
struct StateT * slot_421(struct StateT * v27074);
struct StateT * slot_725(struct StateT * v34595);
struct StateT * slot_918(struct StateT * v56459);
struct StateT * slot_79(struct StateT * v7008);
struct StateT * slot_568(struct StateT * v31648);
struct StateT * slot_810(struct StateT * v40536);
struct StateT * slot_571(struct StateT * v31705);
struct StateT * slot_142(struct StateT * v8582);
struct StateT * slot_624(struct StateT * v32707);
struct StateT * slot_1038(struct StateT * v66854);
struct StateT * slot_738(struct StateT * v34812);
struct StateT * slot_214(struct StateT * v14787);
struct StateT * slot_29(struct StateT * v3847);
struct StateT * slot_151(struct StateT * v8779);
struct StateT * slot_7(struct StateT * v2182);
struct StateT * slot_124(struct StateT * v8255);
struct StateT * slot_128(struct StateT * v8328);
struct StateT * slot_365(struct StateT * v22499);
struct StateT * slot_1025(struct StateT * v66629);
struct StateT * slot_622(struct StateT * v32675);
struct StateT * slot_523(struct StateT * v30767);
struct StateT * slot_782(struct StateT * v37912);
struct StateT * slot_87(struct StateT * v7228);
struct StateT * slot_452(struct StateT * v29289);
struct StateT * slot_67(struct StateT * v4668);
struct StateT * slot_591(struct StateT * v32075);
struct StateT * slot_989(struct StateT * v61827);
struct StateT * slot_81(struct StateT * v5993);
struct StateT * slot_546(struct StateT * v31229);
struct StateT * slot_933(struct StateT * v57564);
struct StateT * slot_1033(struct StateT * v65975);
struct StateT * slot_32(struct StateT * v3822);
struct StateT * slot_861(struct StateT * v47993);
struct StateT * slot_394(struct StateT * v26170);
struct StateT * slot_33(struct StateT * v4051);
struct StateT * slot_743(struct StateT * v34895);
struct StateT * slot_935(struct StateT * v57893);
struct StateT * slot_709(struct StateT * v34322);
struct StateT * slot_35(struct StateT * v4099);
struct StateT * slot_258(struct StateT * v15785);
struct StateT * slot_744(struct StateT * v34911);
struct StateT * slot_615(struct StateT * v32531);
struct StateT * slot_51(struct StateT * v4366);
struct StateT * slot_25(struct StateT * v2455);
struct StateT * slot_991(struct StateT * v61860);
struct StateT * slot_490(struct StateT * v30157);
struct StateT * slot_123(struct StateT * v8230);
struct StateT * slot_982(struct StateT * v61512);
struct StateT * slot_958(struct StateT * v61573);
struct StateT * slot_799(struct StateT * v39271);
struct StateT * slot_299(struct StateT * v16563);
struct StateT * slot_539(struct StateT * v31089);
struct StateT * slot_671(struct StateT * v33626);
struct StateT * slot_929(struct StateT * v57515);
struct StateT * slot_240(struct StateT * v15436);
struct StateT * slot_548(struct StateT * v31261);
struct StateT * slot_70(struct StateT * v4744);
struct StateT * slot_348(struct StateT * v20157);
struct StateT * slot_920(struct StateT * v56487);
struct StateT * slot_749(struct StateT * v35067);
struct StateT * slot_293(struct StateT * v16456);
struct StateT * slot_288(struct StateT * v16368);
struct StateT * slot_89(struct StateT * v7511);
struct StateT * slot_347(struct StateT * v20140);
struct StateT * slot_140(struct StateT * v8558);
struct StateT * slot_473(struct StateT * v29864);
struct StateT * slot_40(struct StateT * v4179);
struct StateT * slot_586(struct StateT * v31992);
struct StateT * slot_75(struct StateT * v5760);
struct StateT * slot_175(struct StateT * v11535);
struct StateT * slot_565(struct StateT * v31584);
struct StateT * slot_188(struct StateT * v12823);
struct StateT * slot_758(struct StateT * v35552);
struct StateT * slot_972(struct StateT * v61166);
struct StateT * slot_110(struct StateT * v7981);
struct StateT * slot_301(struct StateT * v16603);
struct StateT * slot_502(struct StateT * v30387);
struct StateT * slot_203(struct StateT * v14757);
struct StateT * slot_157(struct StateT * v9223);
struct StateT * slot_26(struct StateT * v2770);
struct StateT * slot_370(struct StateT * v22339);
struct StateT * slot_14(struct StateT * v2260);
struct StateT * slot_602(struct StateT * v32282);
struct StateT * slot_639(struct StateT * v32977);
struct StateT * slot_954(struct StateT * v60550);
struct StateT * slot_36(struct StateT * v4113);
struct StateT * slot_57(struct StateT * v4482);
struct StateT * slot_62(struct StateT * v4580);
struct StateT * slot_323(struct StateT * v17955);
struct StateT * slot_628(struct StateT * v32779);
struct StateT * slot_23(struct StateT * v2425);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v7212);
struct StateT * slot_100(struct StateT * v7812);
struct StateT * slot_13(struct StateT * v2243);
struct StateT * slot_109(struct StateT * v7964);
struct StateT * slot_224(struct StateT * v15159);
struct StateT * slot_184(struct StateT * v12894);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_393(struct StateT * v26156);
struct StateT * slot_477(struct StateT * v29931);
struct StateT * slot_249(struct StateT * v15620);
struct StateT * slot_11(struct StateT * v2195);
struct StateT * slot_228(struct StateT * v15227);
struct StateT * slot_268(struct StateT * v15975);
struct StateT * slot_199(struct StateT * v14373);
struct StateT * slot_827(struct StateT * v43259);
struct StateT * slot_501(struct StateT * v30371);
struct StateT * slot_136(struct StateT * v8476);
struct StateT * slot_310(struct StateT * v16793);
struct StateT * slot_68(struct StateT * v4692);
struct StateT * slot_105(struct StateT * v7897);
struct StateT * slot_15(struct StateT * v2277);
struct StateT * slot_222(struct StateT * v15125);
struct StateT * slot_171(struct StateT * v10557);
struct StateT * slot_634(struct StateT * v32911);
struct StateT * slot_267(struct StateT * v15958);
struct StateT * slot_316(struct StateT * v16941);
struct StateT * slot_39(struct StateT * v4162);
struct StateT * slot_60(struct StateT * v4539);
struct StateT * slot_112(struct StateT * v8015);
struct StateT * slot_256(struct StateT * v15752);
struct StateT * slot_16(struct StateT * v2294);
struct StateT * slot_113(struct StateT * v8040);
struct StateT * slot_191(struct StateT * v12908);
struct StateT * slot_95(struct StateT * v7527);
struct StateT * slot_115(struct StateT * v8072);
struct StateT * slot_210(struct StateT * v14706);
struct StateT * slot_52(struct StateT * v4383);
struct StateT * slot_83(struct StateT * v6047);
struct StateT * slot_73(struct StateT * v5127);
struct StateT * slot_187(struct StateT * v12619);
struct StateT * slot_178(struct StateT * v12385);
struct StateT * slot_46(struct StateT * v4277);
struct StateT * slot_20(struct StateT * v2367);
struct StateT * slot_61(struct StateT * v4564);
struct StateT * slot_30(struct StateT * v4067);
struct StateT * slot_300(struct StateT * v16579);
struct StateT * slot_309(struct StateT * v16776);
struct StateT * slot_6(struct StateT * v1961);
struct StateT * slot_37(struct StateT * v4129);
struct StateT * slot_114(struct StateT * v8056);
struct StateT * slot_101(struct StateT * v7829);
struct StateT * slot_93(struct StateT * v7478);
struct StateT * slot_88(struct StateT * v7464);
struct StateT * slot_96(struct StateT * v7541);
struct StateT * slot_408(struct StateT * v28619);
struct StateT * slot_138(struct StateT * v8517);
struct StateT * slot_200(struct StateT * v14389);
struct StateT * slot_104(struct StateT * v7880);
struct StateT * slot_64(struct StateT * v4612);
struct StateT * slot_53(struct StateT * v4408);
struct StateT * slot_99(struct StateT * v7795);
struct StateT * slot_22(struct StateT * v2408);
struct StateT * slot_139(struct StateT * v8533);
struct StateT * slot_129(struct StateT * v8345);
struct StateT * slot_204(struct StateT * v14838);
struct StateT * slot_194(struct StateT * v13272);
struct StateT * slot_236(struct StateT * v15369);
struct StateT * slot_262(struct StateT * v15858);
struct StateT * slot_27(struct StateT * v3578);
struct StateT * slot_24(struct StateT * v2439);
struct StateT * slot_126(struct StateT * v8287);
struct StateT * slot_47(struct StateT * v4294);
struct StateT * slot_19(struct StateT * v2351);
struct StateT * slot_130(struct StateT * v8362);
struct StateT * slot_141(struct StateT * v8566);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_49(struct StateT * v4326);
struct StateT * slot_50(struct StateT * v4342);
struct StateT * slot_59(struct StateT * v4515);
struct StateT * slot_71(struct StateT * v4796);
struct StateT * slot_45(struct StateT * v4260);
struct StateT * slot_69(struct StateT * v4713);
struct StateT * slot_54(struct StateT * v4424);
struct StateT * slot_42(struct StateT * v4213);
struct StateT * slot_12(struct StateT * v2226);
struct StateT * slot_65(struct StateT * v4620);
struct StateT * slot_10(struct StateT * v2165);
struct StateT * slot_17(struct StateT * v2310);
struct StateT * slot_56(struct StateT * v4466);
struct StateT * slot_63(struct StateT * v4596);
struct StateT * slot_41(struct StateT * v4196);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_38(struct StateT * v4145);
struct StateT * slot_18(struct StateT * v2326);
struct StateT * slot_9(struct StateT * v1944);
struct StateT * slot_43(struct StateT * v4230);
struct StateT * slot_55(struct StateT * v4449);
struct StateT * slot_91(struct StateT * v7243);
struct StateT * slot_58(struct StateT * v4498);
struct StateT * slot_66(struct StateT * v4652);
struct StateT * slot_48(struct StateT * v4310);
struct StateT * slot_8(struct StateT * v2212);
struct StateT * slot_5(struct StateT * v1740);
struct StateT * slot_44(struct StateT * v4244);
struct StateT * slot_120(struct StateT * v8172) {
  int v8173 = v8172->timer;
  int v8185 = v8173 + 1;
  v8172->timer = v8185;
  int * v8175 = v8172->regs;
  int v8176 = v8175[29];
  int v8177 = v8175[31];
  bool v8189 = (v8176 ^ -2147483648) < (v8177 ^ -2147483648);
  int v8180;
  if (v8189) {
    v8180 = 1;
  } else {
    v8180 = 0;
  }
  int * v8181 = v8172->regs;
  v8181[6] = v8180;
  struct StateT * v8183 = slot_129(v8172);
  return v8183;
}

struct StateT * slot_167(struct StateT * v10172) {
  int v10173 = v10172->timer;
  int v10185 = v10173 + 1;
  v10172->timer = v10185;
  int * v10175 = v10172->regs;
  int v10176 = v10175[28];
  int v10177 = v10175[5];
  bool v10189 = (v10176 ^ -2147483648) < (v10177 ^ -2147483648);
  int v10180;
  if (v10189) {
    v10180 = 1;
  } else {
    v10180 = 0;
  }
  int * v10181 = v10172->regs;
  v10181[5] = v10180;
  struct StateT * v10183 = slot_171(v10172);
  return v10183;
}

struct StateT * slot_509(struct StateT * v30511) {
  int v30512 = v30511->timer;
  int v30520 = v30512 + 1;
  v30511->timer = v30520;
  int * v30514 = v30511->regs;
  int v30515 = v30514[28];
  int v30516 = v30514[5];
  int v30524 = v30515 + v30516;
  v30514[5] = v30524;
  struct StateT * v30518 = slot_517(v30511);
  return v30518;
}

struct StateT * slot_152(struct StateT * v8795) {
  int * v8796 = v8795->saved_regs;
  int v8797 = v8796[7];
  int v8798 = v8796[29];
  bool v8826 = v8797 == v8798;
  struct StateT * v8821;
  if (v8826) {
    int v8799 = v8795->timer;
    int v8827 = v8799 + 15;
    v8795->timer = v8827;
    int * v8801 = v8795->saved_regs;
    int v8802 = v8801[28];
    int * v8803 = v8795->regs;
    v8803[28] = v8802;
    int * v8805 = v8795->saved_regs;
    int v8806 = v8805[29];
    int * v8807 = v8795->regs;
    v8807[29] = v8806;
    int * v8809 = v8795->saved_regs;
    int v8810 = v8809[7];
    int * v8811 = v8795->regs;
    v8811[7] = v8810;
    int * v8813 = v8795->saved_regs;
    int v8814 = v8813[5];
    int * v8815 = v8795->regs;
    v8815[5] = v8814;
    struct StateT * v8817 = slot_154(v8795);
    v8821 = v8817;
  } else {
    struct StateT * v8819 = slot_171(v8795);
    v8821 = v8819;
  }
  return v8821;
}

struct StateT * slot_231(struct StateT * v15278) {
  int v15279 = v15278->timer;
  int v15287 = v15279 + 1;
  v15278->timer = v15287;
  int * v15281 = v15278->regs;
  int v15282 = v15281[29];
  int v15283 = v15281[13];
  int v15292 = (((((int)((unsigned int)v15282 >> 16)) * ((int)((unsigned int)v15283 >> 16))) + ((int)((unsigned int)((v15282 & 65535) * ((int)((unsigned int)v15283 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v15282 >> 16)) * (v15283 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v15282 & 65535) * (v15283 & 65535)) >> 16)) + (((v15282 & 65535) * ((int)((unsigned int)v15283 >> 16))) & 65535)) + ((((int)((unsigned int)v15282 >> 16)) * (v15283 & 65535)) & 65535)) >> 16));
  v15281[18] = v15292;
  struct StateT * v15285 = slot_249(v15278);
  return v15285;
}

struct StateT * slot_355(struct StateT * v23192) {
  int v23193 = v23192->timer;
  int v23201 = v23193 + 1;
  v23192->timer = v23201;
  int * v23195 = v23192->regs;
  int v23196 = v23195[6];
  int v23197 = v23195[5];
  int v23205 = v23196 + v23197;
  v23195[5] = v23205;
  struct StateT * v23199 = slot_408(v23192);
  return v23199;
}

struct StateT * slot_1032(struct StateT * v65660) {
  int v65661 = v65660->timer;
  int v65831 = v65661 + 1;
  v65660->timer = v65831;
  int * v65663 = v65660->regs;
  int v65664 = v65663[10];
  int v65665 = v65663[12];
  int * v65666 = v65660->cache_tags;
  int v65836 = (((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2;
  int v65667 = v65666[v65836];
  int v65837 = ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v65668 = v65666[v65837];
  int v65838 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2);
  int v65669 = v65666[v65838];
  int v65839 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v65670 = v65666[v65839];
  int v65671 = v65660->timer;
  int v65840 = v65671 + ((100 ^ (((~(((v65669 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65669 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v65667 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65667 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v65668 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65668 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v65669 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65669 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v65660->timer = v65840;
  bool v65841 = !(((~(((v65667 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65667 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v65668 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65668 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v65765;
  if (v65841) {
    int * v65673 = v65660->cache_age;
    int v65843 = ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v65668 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65668 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v65674 = v65673[v65843];
    int v65675 = v65673[v65836];
    int v65844 = v65675 + ((int)((unsigned int)(v65675 - v65674) >> 31));
    v65673[v65836] = v65844;
    int * v65677 = v65660->cache_age;
    int v65678 = v65677[v65837];
    int v65846 = v65678 + ((int)((unsigned int)(v65678 - v65674) >> 31));
    v65677[v65837] = v65846;
    int * v65680 = v65660->cache_age;
    v65680[v65843] = 0;
    v65765 = v65843;
  } else {
    int * v65683 = v65660->cache_age;
    int v65850 = (((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2;
    int v65684 = v65683[v65850];
    int * v65685 = v65660->cache_tags;
    int v65686 = v65685[v65850];
    int v65687 = v65683[v65837];
    int v65688 = v65685[v65837];
    bool v65852 = !(((~(((v65669 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65669 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v65742;
    if (v65852) {
      int * v65689 = v65660->cache_age;
      int v65854 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65670 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v65690 = v65689[v65854];
      int v65691 = v65689[v65838];
      int v65855 = v65691 + ((int)((unsigned int)(v65691 - v65690) >> 31));
      v65689[v65838] = v65855;
      int * v65693 = v65660->cache_age;
      int v65694 = v65693[v65839];
      int v65857 = v65694 + ((int)((unsigned int)(v65694 - v65690) >> 31));
      v65693[v65839] = v65857;
      int * v65696 = v65660->cache_age;
      v65696[v65854] = 0;
      v65742 = v65854;
    } else {
      int * v65699 = v65660->cache_age;
      int v65861 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2);
      int v65700 = v65699[v65861];
      int * v65701 = v65660->cache_tags;
      int v65702 = v65701[v65861];
      int v65703 = v65699[v65839];
      int v65704 = v65701[v65839];
      int * v65705 = v65660->cache_dirty;
      int v65864 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65700 + ((~(((v65702 ^ -1) | (-(v65702 ^ -1))) >> 31)) & 2)) - (v65703 + ((~(((v65704 ^ -1) | (-(v65704 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v65706 = v65705[v65864];
      bool v65865 = !(v65706 == 0);
      if (v65865) {
        int * v65707 = v65660->cache_tags;
        int v65708 = v65707[v65864];
        int * v65709 = v65660->cache_vals;
        int v65868 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65700 + ((~(((v65702 ^ -1) | (-(v65702 ^ -1))) >> 31)) & 2)) - (v65703 + ((~(((v65704 ^ -1) | (-(v65704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65710 = v65709[v65868];
        int v65869 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65700 + ((~(((v65702 ^ -1) | (-(v65702 ^ -1))) >> 31)) & 2)) - (v65703 + ((~(((v65704 ^ -1) | (-(v65704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v65711 = v65709[v65869];
        int * v65712 = v65660->mem;
        int v65871 = v65708 * 2;
        v65712[v65871] = v65710;
        int * v65714 = v65660->mem;
        int v65874 = (v65708 * 2) + 1;
        v65714[v65874] = v65711;
        ;
      } else {
        ;
      }
      int * v65719 = v65660->mem;
      int v65879 = ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) * 2;
      int v65720 = v65719[v65879];
      int v65880 = (((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) * 2) + 1;
      int v65721 = v65719[v65880];
      int * v65722 = v65660->cache_vals;
      int v65882 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65700 + ((~(((v65702 ^ -1) | (-(v65702 ^ -1))) >> 31)) & 2)) - (v65703 + ((~(((v65704 ^ -1) | (-(v65704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v65722[v65882] = v65720;
      int * v65724 = v65660->cache_vals;
      int v65885 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65700 + ((~(((v65702 ^ -1) | (-(v65702 ^ -1))) >> 31)) & 2)) - (v65703 + ((~(((v65704 ^ -1) | (-(v65704 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v65724[v65885] = v65721;
      int * v65726 = v65660->cache_tags;
      int v65888 = (int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1);
      v65726[v65864] = v65888;
      int * v65728 = v65660->cache_dirty;
      v65728[v65864] = 0;
      int * v65730 = v65660->cache_age;
      v65730[v65864] = 1;
      int * v65732 = v65660->cache_age;
      int v65733 = v65732[v65864];
      int v65734 = v65732[v65838];
      int v65894 = v65734 + ((int)((unsigned int)(v65734 - v65733) >> 31));
      v65732[v65838] = v65894;
      int * v65736 = v65660->cache_age;
      int v65737 = v65736[v65839];
      int v65896 = v65737 + ((int)((unsigned int)(v65737 - v65733) >> 31));
      v65736[v65839] = v65896;
      int * v65739 = v65660->cache_age;
      v65739[v65864] = 0;
      v65742 = v65864;
    }
    int * v65743 = v65660->cache_vals;
    int v65899 = v65742 * 2;
    int v65744 = v65743[v65899];
    int v65900 = (v65742 * 2) + 1;
    int v65745 = v65743[v65900];
    int v65901 = (((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v65684 + ((~(((v65686 ^ -1) | (-(v65686 ^ -1))) >> 31)) & 2)) - (v65687 + ((~(((v65688 ^ -1) | (-(v65688 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v65743[v65901] = v65744;
    int * v65747 = v65660->cache_vals;
    int v65904 = ((((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v65684 + ((~(((v65686 ^ -1) | (-(v65686 ^ -1))) >> 31)) & 2)) - (v65687 + ((~(((v65688 ^ -1) | (-(v65688 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v65747[v65904] = v65745;
    int * v65749 = v65660->cache_tags;
    int v65907 = ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v65684 + ((~(((v65686 ^ -1) | (-(v65686 ^ -1))) >> 31)) & 2)) - (v65687 + ((~(((v65688 ^ -1) | (-(v65688 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v65908 = (int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1);
    v65749[v65907] = v65908;
    int * v65751 = v65660->cache_dirty;
    v65751[v65907] = 0;
    int * v65753 = v65660->cache_age;
    v65753[v65907] = 1;
    int * v65755 = v65660->cache_age;
    int v65756 = v65755[v65907];
    int v65757 = v65755[v65836];
    int v65914 = v65757 + ((int)((unsigned int)(v65757 - v65756) >> 31));
    v65755[v65836] = v65914;
    int * v65759 = v65660->cache_age;
    int v65760 = v65759[v65837];
    int v65916 = v65760 + ((int)((unsigned int)(v65760 - v65756) >> 31));
    v65759[v65837] = v65916;
    int * v65762 = v65660->cache_age;
    v65762[v65907] = 0;
    v65765 = v65907;
  }
  int * v65766 = v65660->cache_vals;
  int v65919 = (v65765 * 2) + (((int)((unsigned int)(v65664 + 4) >> 2)) & 1);
  v65766[v65919] = v65665;
  int * v65768 = v65660->cache_tags;
  int v65769 = v65768[v65838];
  int v65770 = v65768[v65839];
  bool v65922 = !(((~(((v65769 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65769 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v65770 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65770 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v65824;
  if (v65922) {
    int * v65771 = v65660->cache_age;
    int v65924 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v65770 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))) | (-(v65770 ^ ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v65772 = v65771[v65924];
    int v65773 = v65771[v65838];
    int v65925 = v65773 + ((int)((unsigned int)(v65773 - v65772) >> 31));
    v65771[v65838] = v65925;
    int * v65775 = v65660->cache_age;
    int v65776 = v65775[v65839];
    int v65927 = v65776 + ((int)((unsigned int)(v65776 - v65772) >> 31));
    v65775[v65839] = v65927;
    int * v65778 = v65660->cache_age;
    v65778[v65924] = 0;
    v65824 = v65924;
  } else {
    int * v65781 = v65660->cache_age;
    int v65931 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2);
    int v65782 = v65781[v65931];
    int * v65783 = v65660->cache_tags;
    int v65784 = v65783[v65931];
    int v65785 = v65781[v65839];
    int v65786 = v65783[v65839];
    int * v65787 = v65660->cache_dirty;
    int v65934 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65782 + ((~(((v65784 ^ -1) | (-(v65784 ^ -1))) >> 31)) & 2)) - (v65785 + ((~(((v65786 ^ -1) | (-(v65786 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v65788 = v65787[v65934];
    bool v65935 = !(v65788 == 0);
    if (v65935) {
      int * v65789 = v65660->cache_tags;
      int v65790 = v65789[v65934];
      int * v65791 = v65660->cache_vals;
      int v65938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65782 + ((~(((v65784 ^ -1) | (-(v65784 ^ -1))) >> 31)) & 2)) - (v65785 + ((~(((v65786 ^ -1) | (-(v65786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v65792 = v65791[v65938];
      int v65939 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65782 + ((~(((v65784 ^ -1) | (-(v65784 ^ -1))) >> 31)) & 2)) - (v65785 + ((~(((v65786 ^ -1) | (-(v65786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v65793 = v65791[v65939];
      int * v65794 = v65660->mem;
      int v65941 = v65790 * 2;
      v65794[v65941] = v65792;
      int * v65796 = v65660->mem;
      int v65944 = (v65790 * 2) + 1;
      v65796[v65944] = v65793;
      ;
    } else {
      ;
    }
    int * v65801 = v65660->mem;
    int v65949 = ((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) * 2;
    int v65802 = v65801[v65949];
    int v65950 = (((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) * 2) + 1;
    int v65803 = v65801[v65950];
    int * v65804 = v65660->cache_vals;
    int v65952 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65782 + ((~(((v65784 ^ -1) | (-(v65784 ^ -1))) >> 31)) & 2)) - (v65785 + ((~(((v65786 ^ -1) | (-(v65786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v65804[v65952] = v65802;
    int * v65806 = v65660->cache_vals;
    int v65955 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v65782 + ((~(((v65784 ^ -1) | (-(v65784 ^ -1))) >> 31)) & 2)) - (v65785 + ((~(((v65786 ^ -1) | (-(v65786 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v65806[v65955] = v65803;
    int * v65808 = v65660->cache_tags;
    int v65958 = (int)((unsigned int)((int)((unsigned int)(v65664 + 4) >> 2)) >> 1);
    v65808[v65934] = v65958;
    int * v65810 = v65660->cache_dirty;
    v65810[v65934] = 0;
    int * v65812 = v65660->cache_age;
    v65812[v65934] = 1;
    int * v65814 = v65660->cache_age;
    int v65815 = v65814[v65934];
    int v65816 = v65814[v65838];
    int v65964 = v65816 + ((int)((unsigned int)(v65816 - v65815) >> 31));
    v65814[v65838] = v65964;
    int * v65818 = v65660->cache_age;
    int v65819 = v65818[v65839];
    int v65966 = v65819 + ((int)((unsigned int)(v65819 - v65815) >> 31));
    v65818[v65839] = v65966;
    int * v65821 = v65660->cache_age;
    v65821[v65934] = 0;
    v65824 = v65934;
  }
  int * v65825 = v65660->cache_vals;
  int v65969 = (v65824 * 2) + (((int)((unsigned int)(v65664 + 4) >> 2)) & 1);
  v65825[v65969] = v65665;
  int * v65827 = v65660->cache_dirty;
  v65827[v65824] = 1;
  struct StateT * v65829 = slot_1080(v65660);
  return v65829;
}

struct StateT * slot_1060(struct StateT * v72756) {
  int v72757 = v72756->timer;
  int v72927 = v72757 + 1;
  v72756->timer = v72927;
  int * v72759 = v72756->regs;
  int v72760 = v72759[10];
  int v72761 = v72759[13];
  int * v72762 = v72756->cache_tags;
  int v72932 = (((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2;
  int v72763 = v72762[v72932];
  int v72933 = ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2) + 1;
  int v72764 = v72762[v72933];
  int v72934 = 4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2);
  int v72765 = v72762[v72934];
  int v72935 = (4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v72766 = v72762[v72935];
  int v72767 = v72756->timer;
  int v72936 = v72767 + ((100 ^ (((~(((v72765 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72765 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) | (~(((v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v72763 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72763 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) | (~(((v72764 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72764 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v72765 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72765 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) | (~(((v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31))) & 104)))));
  v72756->timer = v72936;
  bool v72937 = !(((~(((v72763 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72763 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) | (~(((v72764 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72764 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31))) == 0);
  int v72861;
  if (v72937) {
    int * v72769 = v72756->cache_age;
    int v72939 = ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2) + ((~(((v72764 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72764 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) & 1);
    int v72770 = v72769[v72939];
    int v72771 = v72769[v72932];
    int v72940 = v72771 + ((int)((unsigned int)(v72771 - v72770) >> 31));
    v72769[v72932] = v72940;
    int * v72773 = v72756->cache_age;
    int v72774 = v72773[v72933];
    int v72942 = v72774 + ((int)((unsigned int)(v72774 - v72770) >> 31));
    v72773[v72933] = v72942;
    int * v72776 = v72756->cache_age;
    v72776[v72939] = 0;
    v72861 = v72939;
  } else {
    int * v72779 = v72756->cache_age;
    int v72946 = (((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2;
    int v72780 = v72779[v72946];
    int * v72781 = v72756->cache_tags;
    int v72782 = v72781[v72946];
    int v72783 = v72779[v72933];
    int v72784 = v72781[v72933];
    bool v72948 = !(((~(((v72765 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72765 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) | (~(((v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31))) == 0);
    int v72838;
    if (v72948) {
      int * v72785 = v72756->cache_age;
      int v72950 = (4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((~(((v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72766 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) & 1);
      int v72786 = v72785[v72950];
      int v72787 = v72785[v72934];
      int v72951 = v72787 + ((int)((unsigned int)(v72787 - v72786) >> 31));
      v72785[v72934] = v72951;
      int * v72789 = v72756->cache_age;
      int v72790 = v72789[v72935];
      int v72953 = v72790 + ((int)((unsigned int)(v72790 - v72786) >> 31));
      v72789[v72935] = v72953;
      int * v72792 = v72756->cache_age;
      v72792[v72950] = 0;
      v72838 = v72950;
    } else {
      int * v72795 = v72756->cache_age;
      int v72957 = 4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2);
      int v72796 = v72795[v72957];
      int * v72797 = v72756->cache_tags;
      int v72798 = v72797[v72957];
      int v72799 = v72795[v72935];
      int v72800 = v72797[v72935];
      int * v72801 = v72756->cache_dirty;
      int v72960 = (4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72796 + ((~(((v72798 ^ -1) | (-(v72798 ^ -1))) >> 31)) & 2)) - (v72799 + ((~(((v72800 ^ -1) | (-(v72800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v72802 = v72801[v72960];
      bool v72961 = !(v72802 == 0);
      if (v72961) {
        int * v72803 = v72756->cache_tags;
        int v72804 = v72803[v72960];
        int * v72805 = v72756->cache_vals;
        int v72964 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72796 + ((~(((v72798 ^ -1) | (-(v72798 ^ -1))) >> 31)) & 2)) - (v72799 + ((~(((v72800 ^ -1) | (-(v72800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v72806 = v72805[v72964];
        int v72965 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72796 + ((~(((v72798 ^ -1) | (-(v72798 ^ -1))) >> 31)) & 2)) - (v72799 + ((~(((v72800 ^ -1) | (-(v72800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v72807 = v72805[v72965];
        int * v72808 = v72756->mem;
        int v72967 = v72804 * 2;
        v72808[v72967] = v72806;
        int * v72810 = v72756->mem;
        int v72970 = (v72804 * 2) + 1;
        v72810[v72970] = v72807;
        ;
      } else {
        ;
      }
      int * v72815 = v72756->mem;
      int v72975 = ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) * 2;
      int v72816 = v72815[v72975];
      int v72976 = (((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) * 2) + 1;
      int v72817 = v72815[v72976];
      int * v72818 = v72756->cache_vals;
      int v72978 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72796 + ((~(((v72798 ^ -1) | (-(v72798 ^ -1))) >> 31)) & 2)) - (v72799 + ((~(((v72800 ^ -1) | (-(v72800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v72818[v72978] = v72816;
      int * v72820 = v72756->cache_vals;
      int v72981 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72796 + ((~(((v72798 ^ -1) | (-(v72798 ^ -1))) >> 31)) & 2)) - (v72799 + ((~(((v72800 ^ -1) | (-(v72800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v72820[v72981] = v72817;
      int * v72822 = v72756->cache_tags;
      int v72984 = (int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1);
      v72822[v72960] = v72984;
      int * v72824 = v72756->cache_dirty;
      v72824[v72960] = 0;
      int * v72826 = v72756->cache_age;
      v72826[v72960] = 1;
      int * v72828 = v72756->cache_age;
      int v72829 = v72828[v72960];
      int v72830 = v72828[v72934];
      int v72990 = v72830 + ((int)((unsigned int)(v72830 - v72829) >> 31));
      v72828[v72934] = v72990;
      int * v72832 = v72756->cache_age;
      int v72833 = v72832[v72935];
      int v72992 = v72833 + ((int)((unsigned int)(v72833 - v72829) >> 31));
      v72832[v72935] = v72992;
      int * v72835 = v72756->cache_age;
      v72835[v72960] = 0;
      v72838 = v72960;
    }
    int * v72839 = v72756->cache_vals;
    int v72995 = v72838 * 2;
    int v72840 = v72839[v72995];
    int v72996 = (v72838 * 2) + 1;
    int v72841 = v72839[v72996];
    int v72997 = (((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2) + ((((v72780 + ((~(((v72782 ^ -1) | (-(v72782 ^ -1))) >> 31)) & 2)) - (v72783 + ((~(((v72784 ^ -1) | (-(v72784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v72839[v72997] = v72840;
    int * v72843 = v72756->cache_vals;
    int v73000 = ((((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2) + ((((v72780 + ((~(((v72782 ^ -1) | (-(v72782 ^ -1))) >> 31)) & 2)) - (v72783 + ((~(((v72784 ^ -1) | (-(v72784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v72843[v73000] = v72841;
    int * v72845 = v72756->cache_tags;
    int v73003 = ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 1) * 2) + ((((v72780 + ((~(((v72782 ^ -1) | (-(v72782 ^ -1))) >> 31)) & 2)) - (v72783 + ((~(((v72784 ^ -1) | (-(v72784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v73004 = (int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1);
    v72845[v73003] = v73004;
    int * v72847 = v72756->cache_dirty;
    v72847[v73003] = 0;
    int * v72849 = v72756->cache_age;
    v72849[v73003] = 1;
    int * v72851 = v72756->cache_age;
    int v72852 = v72851[v73003];
    int v72853 = v72851[v72932];
    int v73010 = v72853 + ((int)((unsigned int)(v72853 - v72852) >> 31));
    v72851[v72932] = v73010;
    int * v72855 = v72756->cache_age;
    int v72856 = v72855[v72933];
    int v73012 = v72856 + ((int)((unsigned int)(v72856 - v72852) >> 31));
    v72855[v72933] = v73012;
    int * v72858 = v72756->cache_age;
    v72858[v73003] = 0;
    v72861 = v73003;
  }
  int * v72862 = v72756->cache_vals;
  int v73015 = (v72861 * 2) + (((int)((unsigned int)v72760 >> 2)) & 1);
  v72862[v73015] = v72761;
  int * v72864 = v72756->cache_tags;
  int v72865 = v72864[v72934];
  int v72866 = v72864[v72935];
  bool v73018 = !(((~(((v72865 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72865 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) | (~(((v72866 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72866 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31))) == 0);
  int v72920;
  if (v73018) {
    int * v72867 = v72756->cache_age;
    int v73020 = (4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((~(((v72866 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))) | (-(v72866 ^ ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1))))) >> 31)) & 1);
    int v72868 = v72867[v73020];
    int v72869 = v72867[v72934];
    int v73021 = v72869 + ((int)((unsigned int)(v72869 - v72868) >> 31));
    v72867[v72934] = v73021;
    int * v72871 = v72756->cache_age;
    int v72872 = v72871[v72935];
    int v73023 = v72872 + ((int)((unsigned int)(v72872 - v72868) >> 31));
    v72871[v72935] = v73023;
    int * v72874 = v72756->cache_age;
    v72874[v73020] = 0;
    v72920 = v73020;
  } else {
    int * v72877 = v72756->cache_age;
    int v73027 = 4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2);
    int v72878 = v72877[v73027];
    int * v72879 = v72756->cache_tags;
    int v72880 = v72879[v73027];
    int v72881 = v72877[v72935];
    int v72882 = v72879[v72935];
    int * v72883 = v72756->cache_dirty;
    int v73030 = (4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72878 + ((~(((v72880 ^ -1) | (-(v72880 ^ -1))) >> 31)) & 2)) - (v72881 + ((~(((v72882 ^ -1) | (-(v72882 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v72884 = v72883[v73030];
    bool v73031 = !(v72884 == 0);
    if (v73031) {
      int * v72885 = v72756->cache_tags;
      int v72886 = v72885[v73030];
      int * v72887 = v72756->cache_vals;
      int v73034 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72878 + ((~(((v72880 ^ -1) | (-(v72880 ^ -1))) >> 31)) & 2)) - (v72881 + ((~(((v72882 ^ -1) | (-(v72882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v72888 = v72887[v73034];
      int v73035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72878 + ((~(((v72880 ^ -1) | (-(v72880 ^ -1))) >> 31)) & 2)) - (v72881 + ((~(((v72882 ^ -1) | (-(v72882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v72889 = v72887[v73035];
      int * v72890 = v72756->mem;
      int v73037 = v72886 * 2;
      v72890[v73037] = v72888;
      int * v72892 = v72756->mem;
      int v73040 = (v72886 * 2) + 1;
      v72892[v73040] = v72889;
      ;
    } else {
      ;
    }
    int * v72897 = v72756->mem;
    int v73045 = ((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) * 2;
    int v72898 = v72897[v73045];
    int v73046 = (((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) * 2) + 1;
    int v72899 = v72897[v73046];
    int * v72900 = v72756->cache_vals;
    int v73048 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72878 + ((~(((v72880 ^ -1) | (-(v72880 ^ -1))) >> 31)) & 2)) - (v72881 + ((~(((v72882 ^ -1) | (-(v72882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v72900[v73048] = v72898;
    int * v72902 = v72756->cache_vals;
    int v73051 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1)) & 3) * 2)) + ((((v72878 + ((~(((v72880 ^ -1) | (-(v72880 ^ -1))) >> 31)) & 2)) - (v72881 + ((~(((v72882 ^ -1) | (-(v72882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v72902[v73051] = v72899;
    int * v72904 = v72756->cache_tags;
    int v73054 = (int)((unsigned int)((int)((unsigned int)v72760 >> 2)) >> 1);
    v72904[v73030] = v73054;
    int * v72906 = v72756->cache_dirty;
    v72906[v73030] = 0;
    int * v72908 = v72756->cache_age;
    v72908[v73030] = 1;
    int * v72910 = v72756->cache_age;
    int v72911 = v72910[v73030];
    int v72912 = v72910[v72934];
    int v73060 = v72912 + ((int)((unsigned int)(v72912 - v72911) >> 31));
    v72910[v72934] = v73060;
    int * v72914 = v72756->cache_age;
    int v72915 = v72914[v72935];
    int v73062 = v72915 + ((int)((unsigned int)(v72915 - v72911) >> 31));
    v72914[v72935] = v73062;
    int * v72917 = v72756->cache_age;
    v72917[v73030] = 0;
    v72920 = v73030;
  }
  int * v72921 = v72756->cache_vals;
  int v73065 = (v72920 * 2) + (((int)((unsigned int)v72760 >> 2)) & 1);
  v72921[v73065] = v72761;
  int * v72923 = v72756->cache_dirty;
  v72923[v72920] = 1;
  struct StateT * v72925 = slot_1032(v72756);
  return v72925;
}

struct StateT * slot_616(struct StateT * v32563) {
  int * v32564 = v32563->saved_regs;
  int * v32565 = v32563->regs;
  int v32566 = v32565[12];
  v32564[12] = v32566;
  int v32568 = v32563->timer;
  int v32584 = v32568 + 1;
  v32563->timer = v32584;
  int * v32570 = v32563->regs;
  int v32571 = v32570[5];
  int v32572 = v32570[12];
  bool v32587 = (v32571 ^ -2147483648) < (v32572 ^ -2147483648);
  int v32575;
  if (v32587) {
    v32575 = 1;
  } else {
    v32575 = 0;
  }
  int * v32576 = v32563->regs;
  v32576[12] = v32575;
  struct StateT * v32578 = slot_624(v32563);
  return v32578;
}

struct StateT * slot_984(struct StateT * v61544) {
  int v61545 = v61544->timer;
  int v61553 = v61545 + 1;
  v61544->timer = v61553;
  int * v61547 = v61544->regs;
  int v61548 = v61547[12];
  int v61549 = v61547[14];
  int v61557 = v61548 + v61549;
  v61547[12] = v61557;
  struct StateT * v61551 = slot_1060(v61544);
  return v61551;
}

struct StateT * slot_232(struct StateT * v15295) {
  int v15296 = v15295->timer;
  int v15308 = v15296 + 1;
  v15295->timer = v15308;
  int * v15298 = v15295->regs;
  int v15299 = v15298[29];
  int v15300 = v15298[28];
  bool v15312 = (v15299 ^ -2147483648) < (v15300 ^ -2147483648);
  int v15303;
  if (v15312) {
    v15303 = 1;
  } else {
    v15303 = 0;
  }
  int * v15304 = v15295->regs;
  v15304[7] = v15303;
  struct StateT * v15306 = slot_236(v15295);
  return v15306;
}

struct StateT * slot_466(struct StateT * v29748) {
  int v29749 = v29748->timer;
  int v29757 = v29749 + 1;
  v29748->timer = v29757;
  int * v29751 = v29748->regs;
  int v29752 = v29751[6];
  int v29753 = v29751[13];
  int v29762 = v29752 * v29753;
  v29751[30] = v29762;
  struct StateT * v29755 = slot_477(v29748);
  return v29755;
}

struct StateT * slot_764(struct StateT * v35954) {
  int v35955 = v35954->timer;
  int v35963 = v35955 + 1;
  v35954->timer = v35963;
  int * v35957 = v35954->regs;
  int v35958 = v35957[14];
  int v35959 = v35957[13];
  int v35967 = v35958 + v35959;
  v35957[13] = v35967;
  struct StateT * v35961 = slot_743(v35954);
  return v35961;
}

struct StateT * slot_304(struct StateT * v16644) {
  int * v16645 = v16644->saved_regs;
  int * v16646 = v16644->regs;
  int v16647 = v16646[7];
  v16645[7] = v16647;
  int v16649 = v16644->timer;
  int v16660 = v16649 + 1;
  v16644->timer = v16660;
  int * v16651 = v16644->regs;
  int v16652 = v16651[7];
  int v16662 = (int)((unsigned int)v16652 >> 19);
  v16651[7] = v16662;
  struct StateT * v16654 = slot_325(v16644);
  return v16654;
}

struct StateT * slot_31(struct StateT * v3594) {
  int v3595 = v3594->timer;
  int v3607 = v3595 + 1;
  v3594->timer = v3607;
  int * v3597 = v3594->regs;
  int v3598 = v3597[5];
  int v3599 = v3597[6];
  bool v3611 = (v3598 ^ -2147483648) < (v3599 ^ -2147483648);
  int v3602;
  if (v3611) {
    v3602 = 1;
  } else {
    v3602 = 0;
  }
  int * v3603 = v3594->regs;
  v3603[5] = v3602;
  struct StateT * v3605 = slot_32(v3594);
  return v3605;
}

struct StateT * slot_730(struct StateT * v34687) {
  int v34688 = v34687->timer;
  int v34696 = v34688 + 1;
  v34687->timer = v34696;
  int * v34690 = v34687->regs;
  int v34691 = v34690[12];
  int v34692 = v34690[5];
  int v34700 = v34691 | v34692;
  v34690[12] = v34700;
  struct StateT * v34694 = slot_738(v34687);
  return v34694;
}

struct StateT * slot_585(struct StateT * v31967) {
  int v31968 = v31967->timer;
  int v31980 = v31968 + 1;
  v31967->timer = v31980;
  int * v31970 = v31967->regs;
  int v31971 = v31970[6];
  int v31972 = v31970[30];
  bool v31984 = (v31971 ^ -2147483648) < (v31972 ^ -2147483648);
  int v31975;
  if (v31984) {
    v31975 = 1;
  } else {
    v31975 = 0;
  }
  int * v31976 = v31967->regs;
  v31976[12] = v31975;
  struct StateT * v31978 = slot_565(v31967);
  return v31978;
}

struct StateT * slot_241(struct StateT * v15461) {
  int v15462 = v15461->timer;
  int v15470 = v15462 + 1;
  v15461->timer = v15470;
  int * v15464 = v15461->regs;
  int v15465 = v15464[29];
  int v15466 = v15464[13];
  int v15475 = v15465 * v15466;
  v15464[9] = v15475;
  struct StateT * v15468 = slot_231(v15461);
  return v15468;
}

struct StateT * slot_611(struct StateT * v32435) {
  int v32436 = v32435->timer;
  int v32444 = v32436 + 1;
  v32435->timer = v32444;
  int * v32438 = v32435->regs;
  int v32439 = v32438[13];
  int v32440 = v32438[7];
  int v32448 = v32439 + v32440;
  v32438[13] = v32448;
  struct StateT * v32442 = slot_591(v32435);
  return v32442;
}

struct StateT * slot_160(struct StateT * v9887) {
  int v9888 = v9887->timer;
  int v9895 = v9888 + 1;
  v9887->timer = v9895;
  int * v9890 = v9887->regs;
  int v9891 = v9890[7];
  int v9898 = (int)((unsigned int)v9891 >> 19);
  v9890[7] = v9898;
  struct StateT * v9893 = slot_167(v9887);
  return v9893;
}

struct StateT * slot_745(struct StateT * v34990) {
  int v34991 = v34990->timer;
  int v34998 = v34991 + 1;
  v34990->timer = v34998;
  int * v34993 = v34990->regs;
  int v34994 = v34993[5];
  int v35001 = (int)((unsigned int)v34994 >> 19);
  v34993[5] = v35001;
  struct StateT * v34996 = slot_725(v34990);
  return v34996;
}

struct StateT * slot_150(struct StateT * v8748) {
  int * v8749 = v8748->saved_regs;
  int * v8750 = v8748->regs;
  int v8751 = v8750[5];
  v8749[5] = v8751;
  int v8753 = v8748->timer;
  int v8769 = v8753 + 1;
  v8748->timer = v8769;
  int * v8755 = v8748->regs;
  int v8756 = v8755[28];
  int v8757 = v8755[5];
  bool v8772 = (v8756 ^ -2147483648) < (v8757 ^ -2147483648);
  int v8760;
  if (v8772) {
    v8760 = 1;
  } else {
    v8760 = 0;
  }
  int * v8761 = v8748->regs;
  v8761[5] = v8760;
  struct StateT * v8763 = slot_152(v8748);
  return v8763;
}

struct StateT * slot_391(struct StateT * v26123) {
  int v26124 = v26123->timer;
  int v26132 = v26124 + 1;
  v26123->timer = v26132;
  int * v26126 = v26123->regs;
  int v26127 = v26126[5];
  int v26128 = v26126[17];
  int v26136 = v26127 | v26128;
  v26126[17] = v26136;
  struct StateT * v26130 = slot_473(v26123);
  return v26130;
}

struct StateT * slot_74(struct StateT * v5144) {
  int v5145 = v5144->timer;
  int v5481 = v5145 + 1;
  v5144->timer = v5481;
  int * v5147 = v5144->regs;
  int v5148 = v5147[10];
  int v5149 = v5147[29];
  int * v5150 = v5144->saved_regs;
  int v5151 = v5147[17];
  v5150[17] = v5151;
  int v5153 = v5144->timer;
  int v5488 = v5153 + 1;
  v5144->timer = v5488;
  int * v5155 = v5144->regs;
  int v5156 = v5155[28];
  int v5491 = (int)((unsigned int)v5156 >> 19);
  v5155[17] = v5491;
  int * v5158 = v5144->saved_regs;
  int * v5159 = v5144->regs;
  int v5160 = v5159[28];
  v5158[28] = v5160;
  int v5162 = v5144->timer;
  int v5495 = v5162 + 1;
  v5144->timer = v5495;
  int * v5164 = v5144->regs;
  int v5165 = v5164[28];
  int v5497 = v5165 << 13;
  v5164[28] = v5497;
  int * v5167 = v5144->saved_regs;
  int * v5168 = v5144->regs;
  int v5169 = v5168[5];
  v5167[5] = v5169;
  int v5171 = v5144->timer;
  int v5502 = v5171 + 1;
  v5144->timer = v5502;
  int * v5173 = v5144->regs;
  int v5174 = v5173[6];
  int v5175 = v5173[5];
  int v5505 = v5174 + v5175;
  v5173[5] = v5505;
  int * v5177 = v5144->saved_regs;
  int * v5178 = v5144->regs;
  int v5179 = v5178[6];
  v5177[6] = v5179;
  int v5181 = v5144->timer;
  int v5509 = v5181 + 1;
  v5144->timer = v5509;
  int * v5183 = v5144->regs;
  int v5184 = v5183[11];
  bool v5512 = (((int)((unsigned int)(v5148 + 12) >> 2)) & 3) == (((int)((unsigned int)(v5184 + 16) >> 2)) & 3);
  int v5291;
  if (v5512) {
    int v5185 = v5144->timer;
    int v5513 = v5185 + 1;
    v5144->timer = v5513;
    v5291 = v5149;
  } else {
    int * v5188 = v5144->cache_tags;
    int v5516 = (((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2;
    int v5189 = v5188[v5516];
    int v5517 = ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
    int v5190 = v5188[v5517];
    int v5518 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2);
    int v5191 = v5188[v5518];
    int v5519 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v5192 = v5188[v5519];
    int v5193 = v5144->timer;
    int v5520 = v5193 + ((100 ^ (((~(((v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
    v5144->timer = v5520;
    int * v5195 = v5144->cache_vals;
    bool v5521 = !(((~(((v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5189 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v5288;
    if (v5521) {
      int * v5196 = v5144->cache_age;
      int v5523 = ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5190 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v5197 = v5196[v5523];
      int v5198 = v5196[v5516];
      int v5524 = v5198 + ((int)((unsigned int)(v5198 - v5197) >> 31));
      v5196[v5516] = v5524;
      int * v5200 = v5144->cache_age;
      int v5201 = v5200[v5517];
      int v5526 = v5201 + ((int)((unsigned int)(v5201 - v5197) >> 31));
      v5200[v5517] = v5526;
      int * v5203 = v5144->cache_age;
      v5203[v5523] = 0;
      v5288 = v5523;
    } else {
      int * v5206 = v5144->cache_age;
      int v5530 = (((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2;
      int v5207 = v5206[v5530];
      int * v5208 = v5144->cache_tags;
      int v5209 = v5208[v5530];
      int v5210 = v5206[v5517];
      int v5211 = v5208[v5517];
      bool v5532 = !(((~(((v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5191 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31))) == 0);
      int v5265;
      if (v5532) {
        int * v5212 = v5144->cache_age;
        int v5534 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))) | (-(v5192 ^ ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1))))) >> 31)) & 1);
        int v5213 = v5212[v5534];
        int v5214 = v5212[v5518];
        int v5535 = v5214 + ((int)((unsigned int)(v5214 - v5213) >> 31));
        v5212[v5518] = v5535;
        int * v5216 = v5144->cache_age;
        int v5217 = v5216[v5519];
        int v5537 = v5217 + ((int)((unsigned int)(v5217 - v5213) >> 31));
        v5216[v5519] = v5537;
        int * v5219 = v5144->cache_age;
        v5219[v5534] = 0;
        v5265 = v5534;
      } else {
        int * v5222 = v5144->cache_age;
        int v5541 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2);
        int v5223 = v5222[v5541];
        int * v5224 = v5144->cache_tags;
        int v5225 = v5224[v5541];
        int v5226 = v5222[v5519];
        int v5227 = v5224[v5519];
        int * v5228 = v5144->cache_dirty;
        int v5544 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v5229 = v5228[v5544];
        bool v5545 = !(v5229 == 0);
        if (v5545) {
          int * v5230 = v5144->cache_tags;
          int v5231 = v5230[v5544];
          int * v5232 = v5144->cache_vals;
          int v5548 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v5233 = v5232[v5548];
          int v5549 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v5234 = v5232[v5549];
          int * v5235 = v5144->mem;
          int v5551 = v5231 * 2;
          v5235[v5551] = v5233;
          int * v5237 = v5144->mem;
          int v5554 = (v5231 * 2) + 1;
          v5237[v5554] = v5234;
          ;
        } else {
          ;
        }
        int * v5242 = v5144->mem;
        int v5559 = ((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) * 2;
        int v5243 = v5242[v5559];
        int v5560 = (((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) * 2) + 1;
        int v5244 = v5242[v5560];
        int * v5245 = v5144->cache_vals;
        int v5562 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v5245[v5562] = v5243;
        int * v5247 = v5144->cache_vals;
        int v5565 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v5223 + ((~(((v5225 ^ -1) | (-(v5225 ^ -1))) >> 31)) & 2)) - (v5226 + ((~(((v5227 ^ -1) | (-(v5227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v5247[v5565] = v5244;
        int * v5249 = v5144->cache_tags;
        int v5568 = (int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1);
        v5249[v5544] = v5568;
        int * v5251 = v5144->cache_dirty;
        v5251[v5544] = 0;
        int * v5253 = v5144->cache_age;
        v5253[v5544] = 1;
        int * v5255 = v5144->cache_age;
        int v5256 = v5255[v5544];
        int v5257 = v5255[v5518];
        int v5574 = v5257 + ((int)((unsigned int)(v5257 - v5256) >> 31));
        v5255[v5518] = v5574;
        int * v5259 = v5144->cache_age;
        int v5260 = v5259[v5519];
        int v5576 = v5260 + ((int)((unsigned int)(v5260 - v5256) >> 31));
        v5259[v5519] = v5576;
        int * v5262 = v5144->cache_age;
        v5262[v5544] = 0;
        v5265 = v5544;
      }
      int * v5266 = v5144->cache_vals;
      int v5579 = v5265 * 2;
      int v5267 = v5266[v5579];
      int v5580 = (v5265 * 2) + 1;
      int v5268 = v5266[v5580];
      int v5581 = (((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5207 + ((~(((v5209 ^ -1) | (-(v5209 ^ -1))) >> 31)) & 2)) - (v5210 + ((~(((v5211 ^ -1) | (-(v5211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5266[v5581] = v5267;
      int * v5270 = v5144->cache_vals;
      int v5584 = ((((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5207 + ((~(((v5209 ^ -1) | (-(v5209 ^ -1))) >> 31)) & 2)) - (v5210 + ((~(((v5211 ^ -1) | (-(v5211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5270[v5584] = v5268;
      int * v5272 = v5144->cache_tags;
      int v5587 = ((((int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v5207 + ((~(((v5209 ^ -1) | (-(v5209 ^ -1))) >> 31)) & 2)) - (v5210 + ((~(((v5211 ^ -1) | (-(v5211 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5588 = (int)((unsigned int)((int)((unsigned int)(v5184 + 16) >> 2)) >> 1);
      v5272[v5587] = v5588;
      int * v5274 = v5144->cache_dirty;
      v5274[v5587] = 0;
      int * v5276 = v5144->cache_age;
      v5276[v5587] = 1;
      int * v5278 = v5144->cache_age;
      int v5279 = v5278[v5587];
      int v5280 = v5278[v5516];
      int v5594 = v5280 + ((int)((unsigned int)(v5280 - v5279) >> 31));
      v5278[v5516] = v5594;
      int * v5282 = v5144->cache_age;
      int v5283 = v5282[v5517];
      int v5596 = v5283 + ((int)((unsigned int)(v5283 - v5279) >> 31));
      v5282[v5517] = v5596;
      int * v5285 = v5144->cache_age;
      v5285[v5587] = 0;
      v5288 = v5587;
    }
    int v5599 = (v5288 * 2) + (((int)((unsigned int)(v5184 + 16) >> 2)) & 1);
    int v5289 = v5195[v5599];
    v5291 = v5289;
  }
  int * v5292 = v5144->regs;
  v5292[6] = v5291;
  int * v5294 = v5144->cache_tags;
  int v5604 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2;
  int v5295 = v5294[v5604];
  int v5605 = ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5296 = v5294[v5605];
  int v5606 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2);
  int v5297 = v5294[v5606];
  int v5607 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5298 = v5294[v5607];
  int v5299 = v5144->timer;
  int v5608 = v5299 + ((100 ^ (((~(((v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5144->timer = v5608;
  bool v5609 = !(((~(((v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5295 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5393;
  if (v5609) {
    int * v5301 = v5144->cache_age;
    int v5611 = ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5296 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5302 = v5301[v5611];
    int v5303 = v5301[v5604];
    int v5612 = v5303 + ((int)((unsigned int)(v5303 - v5302) >> 31));
    v5301[v5604] = v5612;
    int * v5305 = v5144->cache_age;
    int v5306 = v5305[v5605];
    int v5614 = v5306 + ((int)((unsigned int)(v5306 - v5302) >> 31));
    v5305[v5605] = v5614;
    int * v5308 = v5144->cache_age;
    v5308[v5611] = 0;
    v5393 = v5611;
  } else {
    int * v5311 = v5144->cache_age;
    int v5618 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2;
    int v5312 = v5311[v5618];
    int * v5313 = v5144->cache_tags;
    int v5314 = v5313[v5618];
    int v5315 = v5311[v5605];
    int v5316 = v5313[v5605];
    bool v5620 = !(((~(((v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5297 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v5370;
    if (v5620) {
      int * v5317 = v5144->cache_age;
      int v5622 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5298 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v5318 = v5317[v5622];
      int v5319 = v5317[v5606];
      int v5623 = v5319 + ((int)((unsigned int)(v5319 - v5318) >> 31));
      v5317[v5606] = v5623;
      int * v5321 = v5144->cache_age;
      int v5322 = v5321[v5607];
      int v5625 = v5322 + ((int)((unsigned int)(v5322 - v5318) >> 31));
      v5321[v5607] = v5625;
      int * v5324 = v5144->cache_age;
      v5324[v5622] = 0;
      v5370 = v5622;
    } else {
      int * v5327 = v5144->cache_age;
      int v5629 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2);
      int v5328 = v5327[v5629];
      int * v5329 = v5144->cache_tags;
      int v5330 = v5329[v5629];
      int v5331 = v5327[v5607];
      int v5332 = v5329[v5607];
      int * v5333 = v5144->cache_dirty;
      int v5632 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5334 = v5333[v5632];
      bool v5633 = !(v5334 == 0);
      if (v5633) {
        int * v5335 = v5144->cache_tags;
        int v5336 = v5335[v5632];
        int * v5337 = v5144->cache_vals;
        int v5636 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5338 = v5337[v5636];
        int v5637 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5339 = v5337[v5637];
        int * v5340 = v5144->mem;
        int v5639 = v5336 * 2;
        v5340[v5639] = v5338;
        int * v5342 = v5144->mem;
        int v5642 = (v5336 * 2) + 1;
        v5342[v5642] = v5339;
        ;
      } else {
        ;
      }
      int * v5347 = v5144->mem;
      int v5647 = ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2;
      int v5348 = v5347[v5647];
      int v5648 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2) + 1;
      int v5349 = v5347[v5648];
      int * v5350 = v5144->cache_vals;
      int v5650 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5350[v5650] = v5348;
      int * v5352 = v5144->cache_vals;
      int v5653 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5328 + ((~(((v5330 ^ -1) | (-(v5330 ^ -1))) >> 31)) & 2)) - (v5331 + ((~(((v5332 ^ -1) | (-(v5332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5352[v5653] = v5349;
      int * v5354 = v5144->cache_tags;
      int v5656 = (int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1);
      v5354[v5632] = v5656;
      int * v5356 = v5144->cache_dirty;
      v5356[v5632] = 0;
      int * v5358 = v5144->cache_age;
      v5358[v5632] = 1;
      int * v5360 = v5144->cache_age;
      int v5361 = v5360[v5632];
      int v5362 = v5360[v5606];
      int v5662 = v5362 + ((int)((unsigned int)(v5362 - v5361) >> 31));
      v5360[v5606] = v5662;
      int * v5364 = v5144->cache_age;
      int v5365 = v5364[v5607];
      int v5664 = v5365 + ((int)((unsigned int)(v5365 - v5361) >> 31));
      v5364[v5607] = v5664;
      int * v5367 = v5144->cache_age;
      v5367[v5632] = 0;
      v5370 = v5632;
    }
    int * v5371 = v5144->cache_vals;
    int v5667 = v5370 * 2;
    int v5372 = v5371[v5667];
    int v5668 = (v5370 * 2) + 1;
    int v5373 = v5371[v5668];
    int v5669 = (((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5312 + ((~(((v5314 ^ -1) | (-(v5314 ^ -1))) >> 31)) & 2)) - (v5315 + ((~(((v5316 ^ -1) | (-(v5316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5371[v5669] = v5372;
    int * v5375 = v5144->cache_vals;
    int v5672 = ((((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5312 + ((~(((v5314 ^ -1) | (-(v5314 ^ -1))) >> 31)) & 2)) - (v5315 + ((~(((v5316 ^ -1) | (-(v5316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5375[v5672] = v5373;
    int * v5377 = v5144->cache_tags;
    int v5675 = ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5312 + ((~(((v5314 ^ -1) | (-(v5314 ^ -1))) >> 31)) & 2)) - (v5315 + ((~(((v5316 ^ -1) | (-(v5316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5676 = (int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1);
    v5377[v5675] = v5676;
    int * v5379 = v5144->cache_dirty;
    v5379[v5675] = 0;
    int * v5381 = v5144->cache_age;
    v5381[v5675] = 1;
    int * v5383 = v5144->cache_age;
    int v5384 = v5383[v5675];
    int v5385 = v5383[v5604];
    int v5682 = v5385 + ((int)((unsigned int)(v5385 - v5384) >> 31));
    v5383[v5604] = v5682;
    int * v5387 = v5144->cache_age;
    int v5388 = v5387[v5605];
    int v5684 = v5388 + ((int)((unsigned int)(v5388 - v5384) >> 31));
    v5387[v5605] = v5684;
    int * v5390 = v5144->cache_age;
    v5390[v5675] = 0;
    v5393 = v5675;
  }
  int * v5394 = v5144->cache_vals;
  int v5687 = (v5393 * 2) + (((int)((unsigned int)(v5148 + 12) >> 2)) & 1);
  v5394[v5687] = v5149;
  int * v5396 = v5144->cache_tags;
  int v5397 = v5396[v5606];
  int v5398 = v5396[v5607];
  bool v5690 = !(((~(((v5397 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5397 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5452;
  if (v5690) {
    int * v5399 = v5144->cache_age;
    int v5692 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))) | (-(v5398 ^ ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5400 = v5399[v5692];
    int v5401 = v5399[v5606];
    int v5693 = v5401 + ((int)((unsigned int)(v5401 - v5400) >> 31));
    v5399[v5606] = v5693;
    int * v5403 = v5144->cache_age;
    int v5404 = v5403[v5607];
    int v5695 = v5404 + ((int)((unsigned int)(v5404 - v5400) >> 31));
    v5403[v5607] = v5695;
    int * v5406 = v5144->cache_age;
    v5406[v5692] = 0;
    v5452 = v5692;
  } else {
    int * v5409 = v5144->cache_age;
    int v5699 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2);
    int v5410 = v5409[v5699];
    int * v5411 = v5144->cache_tags;
    int v5412 = v5411[v5699];
    int v5413 = v5409[v5607];
    int v5414 = v5411[v5607];
    int * v5415 = v5144->cache_dirty;
    int v5702 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5416 = v5415[v5702];
    bool v5703 = !(v5416 == 0);
    if (v5703) {
      int * v5417 = v5144->cache_tags;
      int v5418 = v5417[v5702];
      int * v5419 = v5144->cache_vals;
      int v5706 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5420 = v5419[v5706];
      int v5707 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5421 = v5419[v5707];
      int * v5422 = v5144->mem;
      int v5709 = v5418 * 2;
      v5422[v5709] = v5420;
      int * v5424 = v5144->mem;
      int v5712 = (v5418 * 2) + 1;
      v5424[v5712] = v5421;
      ;
    } else {
      ;
    }
    int * v5429 = v5144->mem;
    int v5717 = ((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2;
    int v5430 = v5429[v5717];
    int v5718 = (((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) * 2) + 1;
    int v5431 = v5429[v5718];
    int * v5432 = v5144->cache_vals;
    int v5720 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5432[v5720] = v5430;
    int * v5434 = v5144->cache_vals;
    int v5723 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5410 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2)) - (v5413 + ((~(((v5414 ^ -1) | (-(v5414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5434[v5723] = v5431;
    int * v5436 = v5144->cache_tags;
    int v5726 = (int)((unsigned int)((int)((unsigned int)(v5148 + 12) >> 2)) >> 1);
    v5436[v5702] = v5726;
    int * v5438 = v5144->cache_dirty;
    v5438[v5702] = 0;
    int * v5440 = v5144->cache_age;
    v5440[v5702] = 1;
    int * v5442 = v5144->cache_age;
    int v5443 = v5442[v5702];
    int v5444 = v5442[v5606];
    int v5732 = v5444 + ((int)((unsigned int)(v5444 - v5443) >> 31));
    v5442[v5606] = v5732;
    int * v5446 = v5144->cache_age;
    int v5447 = v5446[v5607];
    int v5734 = v5447 + ((int)((unsigned int)(v5447 - v5443) >> 31));
    v5446[v5607] = v5734;
    int * v5449 = v5144->cache_age;
    v5449[v5702] = 0;
    v5452 = v5702;
  }
  int * v5453 = v5144->cache_vals;
  int v5737 = (v5452 * 2) + (((int)((unsigned int)(v5148 + 12) >> 2)) & 1);
  v5453[v5737] = v5149;
  int * v5455 = v5144->cache_dirty;
  v5455[v5452] = 1;
  bool v5741 = ((((int)((unsigned int)(v5184 + 16) >> 2)) & 3) == (((int)((unsigned int)(v5148 + 12) >> 2)) & 3)) & (!(((int)((unsigned int)(v5184 + 16) >> 2)) == ((int)((unsigned int)(v5148 + 12) >> 2))));
  struct StateT * v5479;
  if (v5741) {
    int v5457 = v5144->timer;
    int v5742 = v5457 + 15;
    v5144->timer = v5742;
    int * v5459 = v5144->saved_regs;
    int v5460 = v5459[17];
    int * v5461 = v5144->regs;
    v5461[17] = v5460;
    int * v5463 = v5144->saved_regs;
    int v5464 = v5463[28];
    int * v5465 = v5144->regs;
    v5465[28] = v5464;
    int * v5467 = v5144->saved_regs;
    int v5468 = v5467[5];
    int * v5469 = v5144->regs;
    v5469[5] = v5468;
    int * v5471 = v5144->saved_regs;
    int v5472 = v5471[6];
    int * v5473 = v5144->regs;
    v5473[6] = v5472;
    struct StateT * v5475 = slot_87(v5144);
    v5479 = v5475;
  } else {
    struct StateT * v5477 = slot_91(v5144);
    v5479 = v5477;
  }
  return v5479;
}

struct StateT * slot_372(struct StateT * v22429) {
  int v22430 = v22429->timer;
  int v22438 = v22430 + 1;
  v22429->timer = v22438;
  int * v22432 = v22429->regs;
  int v22433 = v22432[7];
  int v22434 = v22432[28];
  int v22442 = v22433 | v22434;
  v22432[7] = v22442;
  struct StateT * v22436 = slot_383(v22429);
  return v22436;
}

struct StateT * slot_403(struct StateT * v26403) {
  int v26404 = v26403->timer;
  int v26514 = v26404 + 1;
  v26403->timer = v26514;
  int * v26406 = v26403->regs;
  int v26407 = v26406[11];
  int * v26408 = v26403->cache_tags;
  int v26518 = (((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2;
  int v26409 = v26408[v26518];
  int v26519 = ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v26410 = v26408[v26519];
  int v26520 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2);
  int v26411 = v26408[v26520];
  int v26521 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26412 = v26408[v26521];
  int v26413 = v26403->timer;
  int v26522 = v26413 + ((100 ^ (((~(((v26411 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26411 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26409 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26409 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v26410 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26410 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v26411 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26411 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v26403->timer = v26522;
  int * v26415 = v26403->cache_vals;
  bool v26523 = !(((~(((v26409 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26409 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v26410 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26410 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v26508;
  if (v26523) {
    int * v26416 = v26403->cache_age;
    int v26525 = ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v26410 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26410 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v26417 = v26416[v26525];
    int v26418 = v26416[v26518];
    int v26526 = v26418 + ((int)((unsigned int)(v26418 - v26417) >> 31));
    v26416[v26518] = v26526;
    int * v26420 = v26403->cache_age;
    int v26421 = v26420[v26519];
    int v26528 = v26421 + ((int)((unsigned int)(v26421 - v26417) >> 31));
    v26420[v26519] = v26528;
    int * v26423 = v26403->cache_age;
    v26423[v26525] = 0;
    v26508 = v26525;
  } else {
    int * v26426 = v26403->cache_age;
    int v26532 = (((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2;
    int v26427 = v26426[v26532];
    int * v26428 = v26403->cache_tags;
    int v26429 = v26428[v26532];
    int v26430 = v26426[v26519];
    int v26431 = v26428[v26519];
    bool v26534 = !(((~(((v26411 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26411 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v26485;
    if (v26534) {
      int * v26432 = v26403->cache_age;
      int v26536 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))) | (-(v26412 ^ ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v26433 = v26432[v26536];
      int v26434 = v26432[v26520];
      int v26537 = v26434 + ((int)((unsigned int)(v26434 - v26433) >> 31));
      v26432[v26520] = v26537;
      int * v26436 = v26403->cache_age;
      int v26437 = v26436[v26521];
      int v26539 = v26437 + ((int)((unsigned int)(v26437 - v26433) >> 31));
      v26436[v26521] = v26539;
      int * v26439 = v26403->cache_age;
      v26439[v26536] = 0;
      v26485 = v26536;
    } else {
      int * v26442 = v26403->cache_age;
      int v26543 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2);
      int v26443 = v26442[v26543];
      int * v26444 = v26403->cache_tags;
      int v26445 = v26444[v26543];
      int v26446 = v26442[v26521];
      int v26447 = v26444[v26521];
      int * v26448 = v26403->cache_dirty;
      int v26546 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v26443 + ((~(((v26445 ^ -1) | (-(v26445 ^ -1))) >> 31)) & 2)) - (v26446 + ((~(((v26447 ^ -1) | (-(v26447 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v26449 = v26448[v26546];
      bool v26547 = !(v26449 == 0);
      if (v26547) {
        int * v26450 = v26403->cache_tags;
        int v26451 = v26450[v26546];
        int * v26452 = v26403->cache_vals;
        int v26550 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v26443 + ((~(((v26445 ^ -1) | (-(v26445 ^ -1))) >> 31)) & 2)) - (v26446 + ((~(((v26447 ^ -1) | (-(v26447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v26453 = v26452[v26550];
        int v26551 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v26443 + ((~(((v26445 ^ -1) | (-(v26445 ^ -1))) >> 31)) & 2)) - (v26446 + ((~(((v26447 ^ -1) | (-(v26447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v26454 = v26452[v26551];
        int * v26455 = v26403->mem;
        int v26553 = v26451 * 2;
        v26455[v26553] = v26453;
        int * v26457 = v26403->mem;
        int v26556 = (v26451 * 2) + 1;
        v26457[v26556] = v26454;
        ;
      } else {
        ;
      }
      int * v26462 = v26403->mem;
      int v26561 = ((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) * 2;
      int v26463 = v26462[v26561];
      int v26562 = (((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) * 2) + 1;
      int v26464 = v26462[v26562];
      int * v26465 = v26403->cache_vals;
      int v26564 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v26443 + ((~(((v26445 ^ -1) | (-(v26445 ^ -1))) >> 31)) & 2)) - (v26446 + ((~(((v26447 ^ -1) | (-(v26447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v26465[v26564] = v26463;
      int * v26467 = v26403->cache_vals;
      int v26567 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v26443 + ((~(((v26445 ^ -1) | (-(v26445 ^ -1))) >> 31)) & 2)) - (v26446 + ((~(((v26447 ^ -1) | (-(v26447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v26467[v26567] = v26464;
      int * v26469 = v26403->cache_tags;
      int v26570 = (int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1);
      v26469[v26546] = v26570;
      int * v26471 = v26403->cache_dirty;
      v26471[v26546] = 0;
      int * v26473 = v26403->cache_age;
      v26473[v26546] = 1;
      int * v26475 = v26403->cache_age;
      int v26476 = v26475[v26546];
      int v26477 = v26475[v26520];
      int v26576 = v26477 + ((int)((unsigned int)(v26477 - v26476) >> 31));
      v26475[v26520] = v26576;
      int * v26479 = v26403->cache_age;
      int v26480 = v26479[v26521];
      int v26578 = v26480 + ((int)((unsigned int)(v26480 - v26476) >> 31));
      v26479[v26521] = v26578;
      int * v26482 = v26403->cache_age;
      v26482[v26546] = 0;
      v26485 = v26546;
    }
    int * v26486 = v26403->cache_vals;
    int v26581 = v26485 * 2;
    int v26487 = v26486[v26581];
    int v26582 = (v26485 * 2) + 1;
    int v26488 = v26486[v26582];
    int v26583 = (((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v26427 + ((~(((v26429 ^ -1) | (-(v26429 ^ -1))) >> 31)) & 2)) - (v26430 + ((~(((v26431 ^ -1) | (-(v26431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v26486[v26583] = v26487;
    int * v26490 = v26403->cache_vals;
    int v26586 = ((((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v26427 + ((~(((v26429 ^ -1) | (-(v26429 ^ -1))) >> 31)) & 2)) - (v26430 + ((~(((v26431 ^ -1) | (-(v26431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v26490[v26586] = v26488;
    int * v26492 = v26403->cache_tags;
    int v26589 = ((((int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v26427 + ((~(((v26429 ^ -1) | (-(v26429 ^ -1))) >> 31)) & 2)) - (v26430 + ((~(((v26431 ^ -1) | (-(v26431 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v26590 = (int)((unsigned int)((int)((unsigned int)(v26407 + 36) >> 2)) >> 1);
    v26492[v26589] = v26590;
    int * v26494 = v26403->cache_dirty;
    v26494[v26589] = 0;
    int * v26496 = v26403->cache_age;
    v26496[v26589] = 1;
    int * v26498 = v26403->cache_age;
    int v26499 = v26498[v26589];
    int v26500 = v26498[v26518];
    int v26596 = v26500 + ((int)((unsigned int)(v26500 - v26499) >> 31));
    v26498[v26518] = v26596;
    int * v26502 = v26403->cache_age;
    int v26503 = v26502[v26519];
    int v26598 = v26503 + ((int)((unsigned int)(v26503 - v26499) >> 31));
    v26502[v26519] = v26598;
    int * v26505 = v26403->cache_age;
    v26505[v26589] = 0;
    v26508 = v26589;
  }
  int v26601 = (v26508 * 2) + (((int)((unsigned int)(v26407 + 36) >> 2)) & 1);
  int v26509 = v26415[v26601];
  int * v26510 = v26403->regs;
  v26510[11] = v26509;
  struct StateT * v26512 = slot_372(v26403);
  return v26512;
}

struct StateT * slot_325(struct StateT * v18018) {
  int * v18019 = v18018->saved_regs;
  int * v18020 = v18018->regs;
  int v18021 = v18020[5];
  v18019[5] = v18021;
  int v18023 = v18018->timer;
  int v18039 = v18023 + 1;
  v18018->timer = v18039;
  int * v18025 = v18018->regs;
  int v18026 = v18025[28];
  int v18027 = v18025[5];
  bool v18042 = (v18026 ^ -2147483648) < (v18027 ^ -2147483648);
  int v18030;
  if (v18042) {
    v18030 = 1;
  } else {
    v18030 = 0;
  }
  int * v18031 = v18018->regs;
  v18031[5] = v18030;
  struct StateT * v18033 = slot_370(v18018);
  return v18033;
}

struct StateT * slot_895(struct StateT * v55178) {
  int v55179 = v55178->timer;
  int v55185 = v55179 + 1;
  v55178->timer = v55185;
  int * v55181 = v55178->regs;
  v55181[17] = 19;
  struct StateT * v55183 = slot_918(v55178);
  return v55183;
}

struct StateT * slot_28(struct StateT * v3618) {
  int v3619 = v3618->timer;
  int v3729 = v3619 + 1;
  v3618->timer = v3729;
  int * v3621 = v3618->regs;
  int v3622 = v3621[11];
  int * v3623 = v3618->cache_tags;
  int v3733 = (((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3624 = v3623[v3733];
  int v3734 = ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3625 = v3623[v3734];
  int v3735 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3626 = v3623[v3735];
  int v3736 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3627 = v3623[v3736];
  int v3628 = v3618->timer;
  int v3737 = v3628 + ((100 ^ (((~(((v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3618->timer = v3737;
  int * v3630 = v3618->cache_vals;
  bool v3738 = !(((~(((v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3624 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3723;
  if (v3738) {
    int * v3631 = v3618->cache_age;
    int v3740 = ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3625 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3632 = v3631[v3740];
    int v3633 = v3631[v3733];
    int v3741 = v3633 + ((int)((unsigned int)(v3633 - v3632) >> 31));
    v3631[v3733] = v3741;
    int * v3635 = v3618->cache_age;
    int v3636 = v3635[v3734];
    int v3743 = v3636 + ((int)((unsigned int)(v3636 - v3632) >> 31));
    v3635[v3734] = v3743;
    int * v3638 = v3618->cache_age;
    v3638[v3740] = 0;
    v3723 = v3740;
  } else {
    int * v3641 = v3618->cache_age;
    int v3747 = (((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3642 = v3641[v3747];
    int * v3643 = v3618->cache_tags;
    int v3644 = v3643[v3747];
    int v3645 = v3641[v3734];
    int v3646 = v3643[v3734];
    bool v3749 = !(((~(((v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3626 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3700;
    if (v3749) {
      int * v3647 = v3618->cache_age;
      int v3751 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))) | (-(v3627 ^ ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3648 = v3647[v3751];
      int v3649 = v3647[v3735];
      int v3752 = v3649 + ((int)((unsigned int)(v3649 - v3648) >> 31));
      v3647[v3735] = v3752;
      int * v3651 = v3618->cache_age;
      int v3652 = v3651[v3736];
      int v3754 = v3652 + ((int)((unsigned int)(v3652 - v3648) >> 31));
      v3651[v3736] = v3754;
      int * v3654 = v3618->cache_age;
      v3654[v3751] = 0;
      v3700 = v3751;
    } else {
      int * v3657 = v3618->cache_age;
      int v3758 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3658 = v3657[v3758];
      int * v3659 = v3618->cache_tags;
      int v3660 = v3659[v3758];
      int v3661 = v3657[v3736];
      int v3662 = v3659[v3736];
      int * v3663 = v3618->cache_dirty;
      int v3761 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3664 = v3663[v3761];
      bool v3762 = !(v3664 == 0);
      if (v3762) {
        int * v3665 = v3618->cache_tags;
        int v3666 = v3665[v3761];
        int * v3667 = v3618->cache_vals;
        int v3765 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3668 = v3667[v3765];
        int v3766 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3669 = v3667[v3766];
        int * v3670 = v3618->mem;
        int v3768 = v3666 * 2;
        v3670[v3768] = v3668;
        int * v3672 = v3618->mem;
        int v3771 = (v3666 * 2) + 1;
        v3672[v3771] = v3669;
        ;
      } else {
        ;
      }
      int * v3677 = v3618->mem;
      int v3776 = ((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) * 2;
      int v3678 = v3677[v3776];
      int v3777 = (((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3679 = v3677[v3777];
      int * v3680 = v3618->cache_vals;
      int v3779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3680[v3779] = v3678;
      int * v3682 = v3618->cache_vals;
      int v3782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3658 + ((~(((v3660 ^ -1) | (-(v3660 ^ -1))) >> 31)) & 2)) - (v3661 + ((~(((v3662 ^ -1) | (-(v3662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3682[v3782] = v3679;
      int * v3684 = v3618->cache_tags;
      int v3785 = (int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1);
      v3684[v3761] = v3785;
      int * v3686 = v3618->cache_dirty;
      v3686[v3761] = 0;
      int * v3688 = v3618->cache_age;
      v3688[v3761] = 1;
      int * v3690 = v3618->cache_age;
      int v3691 = v3690[v3761];
      int v3692 = v3690[v3735];
      int v3791 = v3692 + ((int)((unsigned int)(v3692 - v3691) >> 31));
      v3690[v3735] = v3791;
      int * v3694 = v3618->cache_age;
      int v3695 = v3694[v3736];
      int v3793 = v3695 + ((int)((unsigned int)(v3695 - v3691) >> 31));
      v3694[v3736] = v3793;
      int * v3697 = v3618->cache_age;
      v3697[v3761] = 0;
      v3700 = v3761;
    }
    int * v3701 = v3618->cache_vals;
    int v3796 = v3700 * 2;
    int v3702 = v3701[v3796];
    int v3797 = (v3700 * 2) + 1;
    int v3703 = v3701[v3797];
    int v3798 = (((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3642 + ((~(((v3644 ^ -1) | (-(v3644 ^ -1))) >> 31)) & 2)) - (v3645 + ((~(((v3646 ^ -1) | (-(v3646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3701[v3798] = v3702;
    int * v3705 = v3618->cache_vals;
    int v3801 = ((((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3642 + ((~(((v3644 ^ -1) | (-(v3644 ^ -1))) >> 31)) & 2)) - (v3645 + ((~(((v3646 ^ -1) | (-(v3646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3705[v3801] = v3703;
    int * v3707 = v3618->cache_tags;
    int v3804 = ((((int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3642 + ((~(((v3644 ^ -1) | (-(v3644 ^ -1))) >> 31)) & 2)) - (v3645 + ((~(((v3646 ^ -1) | (-(v3646 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3805 = (int)((unsigned int)((int)((unsigned int)(v3622 + 8) >> 2)) >> 1);
    v3707[v3804] = v3805;
    int * v3709 = v3618->cache_dirty;
    v3709[v3804] = 0;
    int * v3711 = v3618->cache_age;
    v3711[v3804] = 1;
    int * v3713 = v3618->cache_age;
    int v3714 = v3713[v3804];
    int v3715 = v3713[v3733];
    int v3811 = v3715 + ((int)((unsigned int)(v3715 - v3714) >> 31));
    v3713[v3733] = v3811;
    int * v3717 = v3618->cache_age;
    int v3718 = v3717[v3734];
    int v3813 = v3718 + ((int)((unsigned int)(v3718 - v3714) >> 31));
    v3717[v3734] = v3813;
    int * v3720 = v3618->cache_age;
    v3720[v3804] = 0;
    v3723 = v3804;
  }
  int v3816 = (v3723 * 2) + (((int)((unsigned int)(v3622 + 8) >> 2)) & 1);
  int v3724 = v3630[v3816];
  int * v3725 = v3618->regs;
  v3725[7] = v3724;
  struct StateT * v3727 = slot_29(v3618);
  return v3727;
}

struct StateT * slot_517(struct StateT * v30660) {
  int v30661 = v30660->timer;
  int v30669 = v30661 + 1;
  v30660->timer = v30669;
  int * v30663 = v30660->regs;
  int v30664 = v30663[12];
  int v30665 = v30663[7];
  int v30674 = v30664 + v30665;
  v30663[11] = v30674;
  struct StateT * v30667 = slot_523(v30660);
  return v30667;
}

struct StateT * slot_1080(struct StateT * v75434) {
  int v75435 = v75434->timer;
  int v75605 = v75435 + 1;
  v75434->timer = v75605;
  int * v75437 = v75434->regs;
  int v75438 = v75437[10];
  int v75439 = v75437[11];
  int * v75440 = v75434->cache_tags;
  int v75610 = (((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2;
  int v75441 = v75440[v75610];
  int v75611 = ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v75442 = v75440[v75611];
  int v75612 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2);
  int v75443 = v75440[v75612];
  int v75613 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v75444 = v75440[v75613];
  int v75445 = v75434->timer;
  int v75614 = v75445 + ((100 ^ (((~(((v75443 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75443 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v75441 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75441 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v75442 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75442 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v75443 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75443 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v75434->timer = v75614;
  bool v75615 = !(((~(((v75441 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75441 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v75442 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75442 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v75539;
  if (v75615) {
    int * v75447 = v75434->cache_age;
    int v75617 = ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v75442 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75442 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v75448 = v75447[v75617];
    int v75449 = v75447[v75610];
    int v75618 = v75449 + ((int)((unsigned int)(v75449 - v75448) >> 31));
    v75447[v75610] = v75618;
    int * v75451 = v75434->cache_age;
    int v75452 = v75451[v75611];
    int v75620 = v75452 + ((int)((unsigned int)(v75452 - v75448) >> 31));
    v75451[v75611] = v75620;
    int * v75454 = v75434->cache_age;
    v75454[v75617] = 0;
    v75539 = v75617;
  } else {
    int * v75457 = v75434->cache_age;
    int v75624 = (((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2;
    int v75458 = v75457[v75624];
    int * v75459 = v75434->cache_tags;
    int v75460 = v75459[v75624];
    int v75461 = v75457[v75611];
    int v75462 = v75459[v75611];
    bool v75626 = !(((~(((v75443 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75443 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v75516;
    if (v75626) {
      int * v75463 = v75434->cache_age;
      int v75628 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75444 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v75464 = v75463[v75628];
      int v75465 = v75463[v75612];
      int v75629 = v75465 + ((int)((unsigned int)(v75465 - v75464) >> 31));
      v75463[v75612] = v75629;
      int * v75467 = v75434->cache_age;
      int v75468 = v75467[v75613];
      int v75631 = v75468 + ((int)((unsigned int)(v75468 - v75464) >> 31));
      v75467[v75613] = v75631;
      int * v75470 = v75434->cache_age;
      v75470[v75628] = 0;
      v75516 = v75628;
    } else {
      int * v75473 = v75434->cache_age;
      int v75635 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2);
      int v75474 = v75473[v75635];
      int * v75475 = v75434->cache_tags;
      int v75476 = v75475[v75635];
      int v75477 = v75473[v75613];
      int v75478 = v75475[v75613];
      int * v75479 = v75434->cache_dirty;
      int v75638 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75474 + ((~(((v75476 ^ -1) | (-(v75476 ^ -1))) >> 31)) & 2)) - (v75477 + ((~(((v75478 ^ -1) | (-(v75478 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v75480 = v75479[v75638];
      bool v75639 = !(v75480 == 0);
      if (v75639) {
        int * v75481 = v75434->cache_tags;
        int v75482 = v75481[v75638];
        int * v75483 = v75434->cache_vals;
        int v75642 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75474 + ((~(((v75476 ^ -1) | (-(v75476 ^ -1))) >> 31)) & 2)) - (v75477 + ((~(((v75478 ^ -1) | (-(v75478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v75484 = v75483[v75642];
        int v75643 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75474 + ((~(((v75476 ^ -1) | (-(v75476 ^ -1))) >> 31)) & 2)) - (v75477 + ((~(((v75478 ^ -1) | (-(v75478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v75485 = v75483[v75643];
        int * v75486 = v75434->mem;
        int v75645 = v75482 * 2;
        v75486[v75645] = v75484;
        int * v75488 = v75434->mem;
        int v75648 = (v75482 * 2) + 1;
        v75488[v75648] = v75485;
        ;
      } else {
        ;
      }
      int * v75493 = v75434->mem;
      int v75653 = ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) * 2;
      int v75494 = v75493[v75653];
      int v75654 = (((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) * 2) + 1;
      int v75495 = v75493[v75654];
      int * v75496 = v75434->cache_vals;
      int v75656 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75474 + ((~(((v75476 ^ -1) | (-(v75476 ^ -1))) >> 31)) & 2)) - (v75477 + ((~(((v75478 ^ -1) | (-(v75478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v75496[v75656] = v75494;
      int * v75498 = v75434->cache_vals;
      int v75659 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75474 + ((~(((v75476 ^ -1) | (-(v75476 ^ -1))) >> 31)) & 2)) - (v75477 + ((~(((v75478 ^ -1) | (-(v75478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v75498[v75659] = v75495;
      int * v75500 = v75434->cache_tags;
      int v75662 = (int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1);
      v75500[v75638] = v75662;
      int * v75502 = v75434->cache_dirty;
      v75502[v75638] = 0;
      int * v75504 = v75434->cache_age;
      v75504[v75638] = 1;
      int * v75506 = v75434->cache_age;
      int v75507 = v75506[v75638];
      int v75508 = v75506[v75612];
      int v75668 = v75508 + ((int)((unsigned int)(v75508 - v75507) >> 31));
      v75506[v75612] = v75668;
      int * v75510 = v75434->cache_age;
      int v75511 = v75510[v75613];
      int v75670 = v75511 + ((int)((unsigned int)(v75511 - v75507) >> 31));
      v75510[v75613] = v75670;
      int * v75513 = v75434->cache_age;
      v75513[v75638] = 0;
      v75516 = v75638;
    }
    int * v75517 = v75434->cache_vals;
    int v75673 = v75516 * 2;
    int v75518 = v75517[v75673];
    int v75674 = (v75516 * 2) + 1;
    int v75519 = v75517[v75674];
    int v75675 = (((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v75458 + ((~(((v75460 ^ -1) | (-(v75460 ^ -1))) >> 31)) & 2)) - (v75461 + ((~(((v75462 ^ -1) | (-(v75462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v75517[v75675] = v75518;
    int * v75521 = v75434->cache_vals;
    int v75678 = ((((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v75458 + ((~(((v75460 ^ -1) | (-(v75460 ^ -1))) >> 31)) & 2)) - (v75461 + ((~(((v75462 ^ -1) | (-(v75462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v75521[v75678] = v75519;
    int * v75523 = v75434->cache_tags;
    int v75681 = ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v75458 + ((~(((v75460 ^ -1) | (-(v75460 ^ -1))) >> 31)) & 2)) - (v75461 + ((~(((v75462 ^ -1) | (-(v75462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v75682 = (int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1);
    v75523[v75681] = v75682;
    int * v75525 = v75434->cache_dirty;
    v75525[v75681] = 0;
    int * v75527 = v75434->cache_age;
    v75527[v75681] = 1;
    int * v75529 = v75434->cache_age;
    int v75530 = v75529[v75681];
    int v75531 = v75529[v75610];
    int v75688 = v75531 + ((int)((unsigned int)(v75531 - v75530) >> 31));
    v75529[v75610] = v75688;
    int * v75533 = v75434->cache_age;
    int v75534 = v75533[v75611];
    int v75690 = v75534 + ((int)((unsigned int)(v75534 - v75530) >> 31));
    v75533[v75611] = v75690;
    int * v75536 = v75434->cache_age;
    v75536[v75681] = 0;
    v75539 = v75681;
  }
  int * v75540 = v75434->cache_vals;
  int v75693 = (v75539 * 2) + (((int)((unsigned int)(v75438 + 32) >> 2)) & 1);
  v75540[v75693] = v75439;
  int * v75542 = v75434->cache_tags;
  int v75543 = v75542[v75612];
  int v75544 = v75542[v75613];
  bool v75696 = !(((~(((v75543 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75543 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v75544 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75544 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v75598;
  if (v75696) {
    int * v75545 = v75434->cache_age;
    int v75698 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v75544 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))) | (-(v75544 ^ ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v75546 = v75545[v75698];
    int v75547 = v75545[v75612];
    int v75699 = v75547 + ((int)((unsigned int)(v75547 - v75546) >> 31));
    v75545[v75612] = v75699;
    int * v75549 = v75434->cache_age;
    int v75550 = v75549[v75613];
    int v75701 = v75550 + ((int)((unsigned int)(v75550 - v75546) >> 31));
    v75549[v75613] = v75701;
    int * v75552 = v75434->cache_age;
    v75552[v75698] = 0;
    v75598 = v75698;
  } else {
    int * v75555 = v75434->cache_age;
    int v75705 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2);
    int v75556 = v75555[v75705];
    int * v75557 = v75434->cache_tags;
    int v75558 = v75557[v75705];
    int v75559 = v75555[v75613];
    int v75560 = v75557[v75613];
    int * v75561 = v75434->cache_dirty;
    int v75708 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75556 + ((~(((v75558 ^ -1) | (-(v75558 ^ -1))) >> 31)) & 2)) - (v75559 + ((~(((v75560 ^ -1) | (-(v75560 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v75562 = v75561[v75708];
    bool v75709 = !(v75562 == 0);
    if (v75709) {
      int * v75563 = v75434->cache_tags;
      int v75564 = v75563[v75708];
      int * v75565 = v75434->cache_vals;
      int v75712 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75556 + ((~(((v75558 ^ -1) | (-(v75558 ^ -1))) >> 31)) & 2)) - (v75559 + ((~(((v75560 ^ -1) | (-(v75560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v75566 = v75565[v75712];
      int v75713 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75556 + ((~(((v75558 ^ -1) | (-(v75558 ^ -1))) >> 31)) & 2)) - (v75559 + ((~(((v75560 ^ -1) | (-(v75560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v75567 = v75565[v75713];
      int * v75568 = v75434->mem;
      int v75715 = v75564 * 2;
      v75568[v75715] = v75566;
      int * v75570 = v75434->mem;
      int v75718 = (v75564 * 2) + 1;
      v75570[v75718] = v75567;
      ;
    } else {
      ;
    }
    int * v75575 = v75434->mem;
    int v75723 = ((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) * 2;
    int v75576 = v75575[v75723];
    int v75724 = (((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) * 2) + 1;
    int v75577 = v75575[v75724];
    int * v75578 = v75434->cache_vals;
    int v75726 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75556 + ((~(((v75558 ^ -1) | (-(v75558 ^ -1))) >> 31)) & 2)) - (v75559 + ((~(((v75560 ^ -1) | (-(v75560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v75578[v75726] = v75576;
    int * v75580 = v75434->cache_vals;
    int v75729 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v75556 + ((~(((v75558 ^ -1) | (-(v75558 ^ -1))) >> 31)) & 2)) - (v75559 + ((~(((v75560 ^ -1) | (-(v75560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v75580[v75729] = v75577;
    int * v75582 = v75434->cache_tags;
    int v75732 = (int)((unsigned int)((int)((unsigned int)(v75438 + 32) >> 2)) >> 1);
    v75582[v75708] = v75732;
    int * v75584 = v75434->cache_dirty;
    v75584[v75708] = 0;
    int * v75586 = v75434->cache_age;
    v75586[v75708] = 1;
    int * v75588 = v75434->cache_age;
    int v75589 = v75588[v75708];
    int v75590 = v75588[v75612];
    int v75738 = v75590 + ((int)((unsigned int)(v75590 - v75589) >> 31));
    v75588[v75612] = v75738;
    int * v75592 = v75434->cache_age;
    int v75593 = v75592[v75613];
    int v75740 = v75593 + ((int)((unsigned int)(v75593 - v75589) >> 31));
    v75592[v75613] = v75740;
    int * v75595 = v75434->cache_age;
    v75595[v75708] = 0;
    v75598 = v75708;
  }
  int * v75599 = v75434->cache_vals;
  int v75743 = (v75598 * 2) + (((int)((unsigned int)(v75438 + 32) >> 2)) & 1);
  v75599[v75743] = v75439;
  int * v75601 = v75434->cache_dirty;
  v75601[v75598] = 1;
  struct StateT * v75603 = slot_1016(v75434);
  return v75603;
}

struct StateT * slot_1009(struct StateT * v63065) {
  int v63066 = v63065->timer;
  int v63074 = v63066 + 1;
  v63065->timer = v63074;
  int * v63068 = v63065->regs;
  int v63069 = v63068[12];
  int v63070 = v63068[5];
  int v63078 = v63069 | v63070;
  v63068[12] = v63078;
  struct StateT * v63072 = slot_989(v63065);
  return v63072;
}

struct StateT * slot_566(struct StateT * v31600) {
  int v31601 = v31600->timer;
  int v31613 = v31601 + 1;
  v31600->timer = v31613;
  int * v31603 = v31600->regs;
  int v31604 = v31603[28];
  int v31605 = v31603[7];
  bool v31617 = (v31604 ^ -2147483648) < (v31605 ^ -2147483648);
  int v31608;
  if (v31617) {
    v31608 = 1;
  } else {
    v31608 = 0;
  }
  int * v31609 = v31600->regs;
  v31609[7] = v31608;
  struct StateT * v31611 = slot_602(v31600);
  return v31611;
}

struct StateT * slot_923(struct StateT * v56834) {
  int v56835 = v56834->timer;
  int v56842 = v56835 + 1;
  v56834->timer = v56842;
  int * v56837 = v56834->regs;
  int v56838 = v56837[5];
  int v56846 = v56838 << 13;
  v56837[13] = v56846;
  struct StateT * v56840 = slot_935(v56834);
  return v56840;
}

struct StateT * slot_154(struct StateT * v8871) {
  int v8872 = v8871->timer;
  int v8880 = v8872 + 1;
  v8871->timer = v8880;
  int * v8874 = v8871->regs;
  int v8875 = v8874[5];
  int v8876 = v8874[28];
  int v8884 = v8875 + v8876;
  v8874[28] = v8884;
  struct StateT * v8878 = slot_157(v8871);
  return v8878;
}

struct StateT * slot_260(struct StateT * v15817) {
  int v15818 = v15817->timer;
  int v15826 = v15818 + 1;
  v15817->timer = v15826;
  int * v15820 = v15817->regs;
  int v15821 = v15820[7];
  int v15822 = v15820[6];
  int v15830 = v15821 + v15822;
  v15820[6] = v15830;
  struct StateT * v15824 = slot_293(v15817);
  return v15824;
}

struct StateT * slot_1090(struct StateT * v81192) {
  int v81193 = v81192->timer;
  int v81303 = v81193 + 1;
  v81192->timer = v81303;
  int * v81195 = v81192->regs;
  int v81196 = v81195[2];
  int * v81197 = v81192->cache_tags;
  int v81307 = (((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2;
  int v81198 = v81197[v81307];
  int v81308 = ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v81199 = v81197[v81308];
  int v81309 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2);
  int v81200 = v81197[v81309];
  int v81310 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v81201 = v81197[v81310];
  int v81202 = v81192->timer;
  int v81311 = v81202 + ((100 ^ (((~(((v81200 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81200 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v81198 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81198 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v81199 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81199 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v81200 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81200 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v81192->timer = v81311;
  int * v81204 = v81192->cache_vals;
  bool v81312 = !(((~(((v81198 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81198 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v81199 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81199 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v81297;
  if (v81312) {
    int * v81205 = v81192->cache_age;
    int v81314 = ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v81199 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81199 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v81206 = v81205[v81314];
    int v81207 = v81205[v81307];
    int v81315 = v81207 + ((int)((unsigned int)(v81207 - v81206) >> 31));
    v81205[v81307] = v81315;
    int * v81209 = v81192->cache_age;
    int v81210 = v81209[v81308];
    int v81317 = v81210 + ((int)((unsigned int)(v81210 - v81206) >> 31));
    v81209[v81308] = v81317;
    int * v81212 = v81192->cache_age;
    v81212[v81314] = 0;
    v81297 = v81314;
  } else {
    int * v81215 = v81192->cache_age;
    int v81321 = (((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2;
    int v81216 = v81215[v81321];
    int * v81217 = v81192->cache_tags;
    int v81218 = v81217[v81321];
    int v81219 = v81215[v81308];
    int v81220 = v81217[v81308];
    bool v81323 = !(((~(((v81200 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81200 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v81274;
    if (v81323) {
      int * v81221 = v81192->cache_age;
      int v81325 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))) | (-(v81201 ^ ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v81222 = v81221[v81325];
      int v81223 = v81221[v81309];
      int v81326 = v81223 + ((int)((unsigned int)(v81223 - v81222) >> 31));
      v81221[v81309] = v81326;
      int * v81225 = v81192->cache_age;
      int v81226 = v81225[v81310];
      int v81328 = v81226 + ((int)((unsigned int)(v81226 - v81222) >> 31));
      v81225[v81310] = v81328;
      int * v81228 = v81192->cache_age;
      v81228[v81325] = 0;
      v81274 = v81325;
    } else {
      int * v81231 = v81192->cache_age;
      int v81332 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2);
      int v81232 = v81231[v81332];
      int * v81233 = v81192->cache_tags;
      int v81234 = v81233[v81332];
      int v81235 = v81231[v81310];
      int v81236 = v81233[v81310];
      int * v81237 = v81192->cache_dirty;
      int v81335 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v81232 + ((~(((v81234 ^ -1) | (-(v81234 ^ -1))) >> 31)) & 2)) - (v81235 + ((~(((v81236 ^ -1) | (-(v81236 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v81238 = v81237[v81335];
      bool v81336 = !(v81238 == 0);
      if (v81336) {
        int * v81239 = v81192->cache_tags;
        int v81240 = v81239[v81335];
        int * v81241 = v81192->cache_vals;
        int v81339 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v81232 + ((~(((v81234 ^ -1) | (-(v81234 ^ -1))) >> 31)) & 2)) - (v81235 + ((~(((v81236 ^ -1) | (-(v81236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v81242 = v81241[v81339];
        int v81340 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v81232 + ((~(((v81234 ^ -1) | (-(v81234 ^ -1))) >> 31)) & 2)) - (v81235 + ((~(((v81236 ^ -1) | (-(v81236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v81243 = v81241[v81340];
        int * v81244 = v81192->mem;
        int v81342 = v81240 * 2;
        v81244[v81342] = v81242;
        int * v81246 = v81192->mem;
        int v81345 = (v81240 * 2) + 1;
        v81246[v81345] = v81243;
        ;
      } else {
        ;
      }
      int * v81251 = v81192->mem;
      int v81350 = ((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) * 2;
      int v81252 = v81251[v81350];
      int v81351 = (((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) * 2) + 1;
      int v81253 = v81251[v81351];
      int * v81254 = v81192->cache_vals;
      int v81353 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v81232 + ((~(((v81234 ^ -1) | (-(v81234 ^ -1))) >> 31)) & 2)) - (v81235 + ((~(((v81236 ^ -1) | (-(v81236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v81254[v81353] = v81252;
      int * v81256 = v81192->cache_vals;
      int v81356 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v81232 + ((~(((v81234 ^ -1) | (-(v81234 ^ -1))) >> 31)) & 2)) - (v81235 + ((~(((v81236 ^ -1) | (-(v81236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v81256[v81356] = v81253;
      int * v81258 = v81192->cache_tags;
      int v81359 = (int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1);
      v81258[v81335] = v81359;
      int * v81260 = v81192->cache_dirty;
      v81260[v81335] = 0;
      int * v81262 = v81192->cache_age;
      v81262[v81335] = 1;
      int * v81264 = v81192->cache_age;
      int v81265 = v81264[v81335];
      int v81266 = v81264[v81309];
      int v81365 = v81266 + ((int)((unsigned int)(v81266 - v81265) >> 31));
      v81264[v81309] = v81365;
      int * v81268 = v81192->cache_age;
      int v81269 = v81268[v81310];
      int v81367 = v81269 + ((int)((unsigned int)(v81269 - v81265) >> 31));
      v81268[v81310] = v81367;
      int * v81271 = v81192->cache_age;
      v81271[v81335] = 0;
      v81274 = v81335;
    }
    int * v81275 = v81192->cache_vals;
    int v81370 = v81274 * 2;
    int v81276 = v81275[v81370];
    int v81371 = (v81274 * 2) + 1;
    int v81277 = v81275[v81371];
    int v81372 = (((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v81216 + ((~(((v81218 ^ -1) | (-(v81218 ^ -1))) >> 31)) & 2)) - (v81219 + ((~(((v81220 ^ -1) | (-(v81220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v81275[v81372] = v81276;
    int * v81279 = v81192->cache_vals;
    int v81375 = ((((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v81216 + ((~(((v81218 ^ -1) | (-(v81218 ^ -1))) >> 31)) & 2)) - (v81219 + ((~(((v81220 ^ -1) | (-(v81220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v81279[v81375] = v81277;
    int * v81281 = v81192->cache_tags;
    int v81378 = ((((int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v81216 + ((~(((v81218 ^ -1) | (-(v81218 ^ -1))) >> 31)) & 2)) - (v81219 + ((~(((v81220 ^ -1) | (-(v81220 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v81379 = (int)((unsigned int)((int)((unsigned int)(v81196 + 12) >> 2)) >> 1);
    v81281[v81378] = v81379;
    int * v81283 = v81192->cache_dirty;
    v81283[v81378] = 0;
    int * v81285 = v81192->cache_age;
    v81285[v81378] = 1;
    int * v81287 = v81192->cache_age;
    int v81288 = v81287[v81378];
    int v81289 = v81287[v81307];
    int v81385 = v81289 + ((int)((unsigned int)(v81289 - v81288) >> 31));
    v81287[v81307] = v81385;
    int * v81291 = v81192->cache_age;
    int v81292 = v81291[v81308];
    int v81387 = v81292 + ((int)((unsigned int)(v81292 - v81288) >> 31));
    v81291[v81308] = v81387;
    int * v81294 = v81192->cache_age;
    v81294[v81378] = 0;
    v81297 = v81378;
  }
  int v81390 = (v81297 * 2) + (((int)((unsigned int)(v81196 + 12) >> 2)) & 1);
  int v81298 = v81204[v81390];
  int * v81299 = v81192->regs;
  v81299[8] = v81298;
  struct StateT * v81301 = slot_1025(v81192);
  return v81301;
}

struct StateT * slot_305(struct StateT * v16665) {
  int v16666 = v16665->timer;
  int v16674 = v16666 + 1;
  v16665->timer = v16674;
  int * v16668 = v16665->regs;
  int v16669 = v16668[18];
  int v16670 = v16668[6];
  int v16678 = v16669 + v16670;
  v16668[6] = v16678;
  struct StateT * v16672 = slot_309(v16665);
  return v16672;
}

struct StateT * slot_662(struct StateT * v33465) {
  int * v33466 = v33465->saved_regs;
  int * v33467 = v33465->regs;
  int v33468 = v33467[13];
  v33466[13] = v33468;
  int v33470 = v33465->timer;
  int v33481 = v33470 + 1;
  v33465->timer = v33481;
  int * v33472 = v33465->regs;
  int v33473 = v33472[5];
  int v33484 = v33473 << 13;
  v33472[13] = v33484;
  struct StateT * v33475 = slot_671(v33465);
  return v33475;
}

struct StateT * slot_34(struct StateT * v4084) {
  int v4085 = v4084->timer;
  int v4092 = v4085 + 1;
  v4084->timer = v4092;
  int * v4087 = v4084->regs;
  int v4088 = v4087[31];
  int v4096 = (int)((unsigned int)v4088 >> 19);
  v4087[29] = v4096;
  struct StateT * v4090 = slot_35(v4084);
  return v4090;
}

struct StateT * slot_971(struct StateT * v61150) {
  int v61151 = v61150->timer;
  int v61159 = v61151 + 1;
  v61150->timer = v61159;
  int * v61153 = v61150->regs;
  int v61154 = v61153[15];
  int v61155 = v61153[5];
  int v61163 = v61154 + v61155;
  v61153[15] = v61163;
  struct StateT * v61157 = slot_982(v61150);
  return v61157;
}

struct StateT * slot_1016(struct StateT * v63177) {
  int v63178 = v63177->timer;
  int v63827 = v63178 + 1;
  v63177->timer = v63827;
  int * v63180 = v63177->regs;
  int v63181 = v63180[10];
  int v63182 = v63180[16];
  int * v63183 = v63177->saved_regs;
  int v63184 = v63180[8];
  v63183[8] = v63184;
  int v63186 = v63177->timer;
  int v63834 = v63186 + 1;
  v63177->timer = v63834;
  int * v63188 = v63177->regs;
  int v63189 = v63188[2];
  int * v63190 = v63177->cache_tags;
  int v63838 = (((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2;
  int v63191 = v63190[v63838];
  int v63839 = ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v63192 = v63190[v63839];
  int v63840 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2);
  int v63193 = v63190[v63840];
  int v63841 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v63194 = v63190[v63841];
  int v63195 = v63177->timer;
  int v63842 = v63195 + ((100 ^ (((~(((v63193 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63193 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63191 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63191 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v63192 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63192 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v63193 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63193 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v63177->timer = v63842;
  int * v63197 = v63177->cache_vals;
  bool v63843 = !(((~(((v63191 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63191 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v63192 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63192 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v63290;
  if (v63843) {
    int * v63198 = v63177->cache_age;
    int v63845 = ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v63192 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63192 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v63199 = v63198[v63845];
    int v63200 = v63198[v63838];
    int v63846 = v63200 + ((int)((unsigned int)(v63200 - v63199) >> 31));
    v63198[v63838] = v63846;
    int * v63202 = v63177->cache_age;
    int v63203 = v63202[v63839];
    int v63848 = v63203 + ((int)((unsigned int)(v63203 - v63199) >> 31));
    v63202[v63839] = v63848;
    int * v63205 = v63177->cache_age;
    v63205[v63845] = 0;
    v63290 = v63845;
  } else {
    int * v63208 = v63177->cache_age;
    int v63852 = (((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2;
    int v63209 = v63208[v63852];
    int * v63210 = v63177->cache_tags;
    int v63211 = v63210[v63852];
    int v63212 = v63208[v63839];
    int v63213 = v63210[v63839];
    bool v63854 = !(((~(((v63193 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63193 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v63267;
    if (v63854) {
      int * v63214 = v63177->cache_age;
      int v63856 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))) | (-(v63194 ^ ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v63215 = v63214[v63856];
      int v63216 = v63214[v63840];
      int v63857 = v63216 + ((int)((unsigned int)(v63216 - v63215) >> 31));
      v63214[v63840] = v63857;
      int * v63218 = v63177->cache_age;
      int v63219 = v63218[v63841];
      int v63859 = v63219 + ((int)((unsigned int)(v63219 - v63215) >> 31));
      v63218[v63841] = v63859;
      int * v63221 = v63177->cache_age;
      v63221[v63856] = 0;
      v63267 = v63856;
    } else {
      int * v63224 = v63177->cache_age;
      int v63863 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2);
      int v63225 = v63224[v63863];
      int * v63226 = v63177->cache_tags;
      int v63227 = v63226[v63863];
      int v63228 = v63224[v63841];
      int v63229 = v63226[v63841];
      int * v63230 = v63177->cache_dirty;
      int v63866 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v63225 + ((~(((v63227 ^ -1) | (-(v63227 ^ -1))) >> 31)) & 2)) - (v63228 + ((~(((v63229 ^ -1) | (-(v63229 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v63231 = v63230[v63866];
      bool v63867 = !(v63231 == 0);
      if (v63867) {
        int * v63232 = v63177->cache_tags;
        int v63233 = v63232[v63866];
        int * v63234 = v63177->cache_vals;
        int v63870 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v63225 + ((~(((v63227 ^ -1) | (-(v63227 ^ -1))) >> 31)) & 2)) - (v63228 + ((~(((v63229 ^ -1) | (-(v63229 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63235 = v63234[v63870];
        int v63871 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v63225 + ((~(((v63227 ^ -1) | (-(v63227 ^ -1))) >> 31)) & 2)) - (v63228 + ((~(((v63229 ^ -1) | (-(v63229 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v63236 = v63234[v63871];
        int * v63237 = v63177->mem;
        int v63873 = v63233 * 2;
        v63237[v63873] = v63235;
        int * v63239 = v63177->mem;
        int v63876 = (v63233 * 2) + 1;
        v63239[v63876] = v63236;
        ;
      } else {
        ;
      }
      int * v63244 = v63177->mem;
      int v63881 = ((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) * 2;
      int v63245 = v63244[v63881];
      int v63882 = (((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) * 2) + 1;
      int v63246 = v63244[v63882];
      int * v63247 = v63177->cache_vals;
      int v63884 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v63225 + ((~(((v63227 ^ -1) | (-(v63227 ^ -1))) >> 31)) & 2)) - (v63228 + ((~(((v63229 ^ -1) | (-(v63229 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v63247[v63884] = v63245;
      int * v63249 = v63177->cache_vals;
      int v63887 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v63225 + ((~(((v63227 ^ -1) | (-(v63227 ^ -1))) >> 31)) & 2)) - (v63228 + ((~(((v63229 ^ -1) | (-(v63229 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v63249[v63887] = v63246;
      int * v63251 = v63177->cache_tags;
      int v63890 = (int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1);
      v63251[v63866] = v63890;
      int * v63253 = v63177->cache_dirty;
      v63253[v63866] = 0;
      int * v63255 = v63177->cache_age;
      v63255[v63866] = 1;
      int * v63257 = v63177->cache_age;
      int v63258 = v63257[v63866];
      int v63259 = v63257[v63840];
      int v63896 = v63259 + ((int)((unsigned int)(v63259 - v63258) >> 31));
      v63257[v63840] = v63896;
      int * v63261 = v63177->cache_age;
      int v63262 = v63261[v63841];
      int v63898 = v63262 + ((int)((unsigned int)(v63262 - v63258) >> 31));
      v63261[v63841] = v63898;
      int * v63264 = v63177->cache_age;
      v63264[v63866] = 0;
      v63267 = v63866;
    }
    int * v63268 = v63177->cache_vals;
    int v63901 = v63267 * 2;
    int v63269 = v63268[v63901];
    int v63902 = (v63267 * 2) + 1;
    int v63270 = v63268[v63902];
    int v63903 = (((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v63209 + ((~(((v63211 ^ -1) | (-(v63211 ^ -1))) >> 31)) & 2)) - (v63212 + ((~(((v63213 ^ -1) | (-(v63213 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v63268[v63903] = v63269;
    int * v63272 = v63177->cache_vals;
    int v63906 = ((((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v63209 + ((~(((v63211 ^ -1) | (-(v63211 ^ -1))) >> 31)) & 2)) - (v63212 + ((~(((v63213 ^ -1) | (-(v63213 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v63272[v63906] = v63270;
    int * v63274 = v63177->cache_tags;
    int v63909 = ((((int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v63209 + ((~(((v63211 ^ -1) | (-(v63211 ^ -1))) >> 31)) & 2)) - (v63212 + ((~(((v63213 ^ -1) | (-(v63213 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v63910 = (int)((unsigned int)((int)((unsigned int)(v63189 + 12) >> 2)) >> 1);
    v63274[v63909] = v63910;
    int * v63276 = v63177->cache_dirty;
    v63276[v63909] = 0;
    int * v63278 = v63177->cache_age;
    v63278[v63909] = 1;
    int * v63280 = v63177->cache_age;
    int v63281 = v63280[v63909];
    int v63282 = v63280[v63838];
    int v63916 = v63282 + ((int)((unsigned int)(v63282 - v63281) >> 31));
    v63280[v63838] = v63916;
    int * v63284 = v63177->cache_age;
    int v63285 = v63284[v63839];
    int v63918 = v63285 + ((int)((unsigned int)(v63285 - v63281) >> 31));
    v63284[v63839] = v63918;
    int * v63287 = v63177->cache_age;
    v63287[v63909] = 0;
    v63290 = v63909;
  }
  int v63921 = (v63290 * 2) + (((int)((unsigned int)(v63189 + 12) >> 2)) & 1);
  int v63291 = v63197[v63921];
  int * v63292 = v63177->regs;
  v63292[8] = v63291;
  int * v63294 = v63177->saved_regs;
  int * v63295 = v63177->regs;
  int v63296 = v63295[9];
  v63294[9] = v63296;
  int v63298 = v63177->timer;
  int v63928 = v63298 + 1;
  v63177->timer = v63928;
  int * v63300 = v63177->regs;
  int v63301 = v63300[2];
  int * v63302 = v63177->cache_tags;
  int v63931 = (((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2;
  int v63303 = v63302[v63931];
  int v63932 = ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v63304 = v63302[v63932];
  int v63933 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2);
  int v63305 = v63302[v63933];
  int v63934 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v63306 = v63302[v63934];
  int v63307 = v63177->timer;
  int v63935 = v63307 + ((100 ^ (((~(((v63305 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63305 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63303 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63303 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v63304 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63304 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v63305 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63305 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v63177->timer = v63935;
  int * v63309 = v63177->cache_vals;
  bool v63936 = !(((~(((v63303 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63303 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v63304 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63304 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v63402;
  if (v63936) {
    int * v63310 = v63177->cache_age;
    int v63938 = ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v63304 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63304 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v63311 = v63310[v63938];
    int v63312 = v63310[v63931];
    int v63939 = v63312 + ((int)((unsigned int)(v63312 - v63311) >> 31));
    v63310[v63931] = v63939;
    int * v63314 = v63177->cache_age;
    int v63315 = v63314[v63932];
    int v63941 = v63315 + ((int)((unsigned int)(v63315 - v63311) >> 31));
    v63314[v63932] = v63941;
    int * v63317 = v63177->cache_age;
    v63317[v63938] = 0;
    v63402 = v63938;
  } else {
    int * v63320 = v63177->cache_age;
    int v63945 = (((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2;
    int v63321 = v63320[v63945];
    int * v63322 = v63177->cache_tags;
    int v63323 = v63322[v63945];
    int v63324 = v63320[v63932];
    int v63325 = v63322[v63932];
    bool v63947 = !(((~(((v63305 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63305 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v63379;
    if (v63947) {
      int * v63326 = v63177->cache_age;
      int v63949 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))) | (-(v63306 ^ ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v63327 = v63326[v63949];
      int v63328 = v63326[v63933];
      int v63950 = v63328 + ((int)((unsigned int)(v63328 - v63327) >> 31));
      v63326[v63933] = v63950;
      int * v63330 = v63177->cache_age;
      int v63331 = v63330[v63934];
      int v63952 = v63331 + ((int)((unsigned int)(v63331 - v63327) >> 31));
      v63330[v63934] = v63952;
      int * v63333 = v63177->cache_age;
      v63333[v63949] = 0;
      v63379 = v63949;
    } else {
      int * v63336 = v63177->cache_age;
      int v63956 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2);
      int v63337 = v63336[v63956];
      int * v63338 = v63177->cache_tags;
      int v63339 = v63338[v63956];
      int v63340 = v63336[v63934];
      int v63341 = v63338[v63934];
      int * v63342 = v63177->cache_dirty;
      int v63959 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v63337 + ((~(((v63339 ^ -1) | (-(v63339 ^ -1))) >> 31)) & 2)) - (v63340 + ((~(((v63341 ^ -1) | (-(v63341 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v63343 = v63342[v63959];
      bool v63960 = !(v63343 == 0);
      if (v63960) {
        int * v63344 = v63177->cache_tags;
        int v63345 = v63344[v63959];
        int * v63346 = v63177->cache_vals;
        int v63963 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v63337 + ((~(((v63339 ^ -1) | (-(v63339 ^ -1))) >> 31)) & 2)) - (v63340 + ((~(((v63341 ^ -1) | (-(v63341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63347 = v63346[v63963];
        int v63964 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v63337 + ((~(((v63339 ^ -1) | (-(v63339 ^ -1))) >> 31)) & 2)) - (v63340 + ((~(((v63341 ^ -1) | (-(v63341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v63348 = v63346[v63964];
        int * v63349 = v63177->mem;
        int v63966 = v63345 * 2;
        v63349[v63966] = v63347;
        int * v63351 = v63177->mem;
        int v63969 = (v63345 * 2) + 1;
        v63351[v63969] = v63348;
        ;
      } else {
        ;
      }
      int * v63356 = v63177->mem;
      int v63974 = ((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) * 2;
      int v63357 = v63356[v63974];
      int v63975 = (((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) * 2) + 1;
      int v63358 = v63356[v63975];
      int * v63359 = v63177->cache_vals;
      int v63977 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v63337 + ((~(((v63339 ^ -1) | (-(v63339 ^ -1))) >> 31)) & 2)) - (v63340 + ((~(((v63341 ^ -1) | (-(v63341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v63359[v63977] = v63357;
      int * v63361 = v63177->cache_vals;
      int v63980 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v63337 + ((~(((v63339 ^ -1) | (-(v63339 ^ -1))) >> 31)) & 2)) - (v63340 + ((~(((v63341 ^ -1) | (-(v63341 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v63361[v63980] = v63358;
      int * v63363 = v63177->cache_tags;
      int v63983 = (int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1);
      v63363[v63959] = v63983;
      int * v63365 = v63177->cache_dirty;
      v63365[v63959] = 0;
      int * v63367 = v63177->cache_age;
      v63367[v63959] = 1;
      int * v63369 = v63177->cache_age;
      int v63370 = v63369[v63959];
      int v63371 = v63369[v63933];
      int v63989 = v63371 + ((int)((unsigned int)(v63371 - v63370) >> 31));
      v63369[v63933] = v63989;
      int * v63373 = v63177->cache_age;
      int v63374 = v63373[v63934];
      int v63991 = v63374 + ((int)((unsigned int)(v63374 - v63370) >> 31));
      v63373[v63934] = v63991;
      int * v63376 = v63177->cache_age;
      v63376[v63959] = 0;
      v63379 = v63959;
    }
    int * v63380 = v63177->cache_vals;
    int v63994 = v63379 * 2;
    int v63381 = v63380[v63994];
    int v63995 = (v63379 * 2) + 1;
    int v63382 = v63380[v63995];
    int v63996 = (((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v63321 + ((~(((v63323 ^ -1) | (-(v63323 ^ -1))) >> 31)) & 2)) - (v63324 + ((~(((v63325 ^ -1) | (-(v63325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v63380[v63996] = v63381;
    int * v63384 = v63177->cache_vals;
    int v63999 = ((((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v63321 + ((~(((v63323 ^ -1) | (-(v63323 ^ -1))) >> 31)) & 2)) - (v63324 + ((~(((v63325 ^ -1) | (-(v63325 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v63384[v63999] = v63382;
    int * v63386 = v63177->cache_tags;
    int v64002 = ((((int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v63321 + ((~(((v63323 ^ -1) | (-(v63323 ^ -1))) >> 31)) & 2)) - (v63324 + ((~(((v63325 ^ -1) | (-(v63325 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v64003 = (int)((unsigned int)((int)((unsigned int)(v63301 + 8) >> 2)) >> 1);
    v63386[v64002] = v64003;
    int * v63388 = v63177->cache_dirty;
    v63388[v64002] = 0;
    int * v63390 = v63177->cache_age;
    v63390[v64002] = 1;
    int * v63392 = v63177->cache_age;
    int v63393 = v63392[v64002];
    int v63394 = v63392[v63931];
    int v64009 = v63394 + ((int)((unsigned int)(v63394 - v63393) >> 31));
    v63392[v63931] = v64009;
    int * v63396 = v63177->cache_age;
    int v63397 = v63396[v63932];
    int v64011 = v63397 + ((int)((unsigned int)(v63397 - v63393) >> 31));
    v63396[v63932] = v64011;
    int * v63399 = v63177->cache_age;
    v63399[v64002] = 0;
    v63402 = v64002;
  }
  int v64014 = (v63402 * 2) + (((int)((unsigned int)(v63301 + 8) >> 2)) & 1);
  int v63403 = v63309[v64014];
  int * v63404 = v63177->regs;
  v63404[9] = v63403;
  int * v63406 = v63177->saved_regs;
  int * v63407 = v63177->regs;
  int v63408 = v63407[18];
  v63406[18] = v63408;
  int v63410 = v63177->timer;
  int v64021 = v63410 + 1;
  v63177->timer = v64021;
  int * v63412 = v63177->regs;
  int v63413 = v63412[2];
  bool v64023 = (((int)((unsigned int)(v63181 + 36) >> 2)) & 3) == (((int)((unsigned int)(v63413 + 4) >> 2)) & 3);
  int v63520;
  if (v64023) {
    int v63414 = v63177->timer;
    int v64024 = v63414 + 1;
    v63177->timer = v64024;
    v63520 = v63182;
  } else {
    int * v63417 = v63177->cache_tags;
    int v64027 = (((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2;
    int v63418 = v63417[v64027];
    int v64028 = ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
    int v63419 = v63417[v64028];
    int v64029 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2);
    int v63420 = v63417[v64029];
    int v64030 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v63421 = v63417[v64030];
    int v63422 = v63177->timer;
    int v64031 = v63422 + ((100 ^ (((~(((v63420 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63420 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63418 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63418 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v63419 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63419 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v63420 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63420 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
    v63177->timer = v64031;
    int * v63424 = v63177->cache_vals;
    bool v64032 = !(((~(((v63418 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63418 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v63419 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63419 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v63517;
    if (v64032) {
      int * v63425 = v63177->cache_age;
      int v64034 = ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v63419 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63419 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v63426 = v63425[v64034];
      int v63427 = v63425[v64027];
      int v64035 = v63427 + ((int)((unsigned int)(v63427 - v63426) >> 31));
      v63425[v64027] = v64035;
      int * v63429 = v63177->cache_age;
      int v63430 = v63429[v64028];
      int v64037 = v63430 + ((int)((unsigned int)(v63430 - v63426) >> 31));
      v63429[v64028] = v64037;
      int * v63432 = v63177->cache_age;
      v63432[v64034] = 0;
      v63517 = v64034;
    } else {
      int * v63435 = v63177->cache_age;
      int v64041 = (((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2;
      int v63436 = v63435[v64041];
      int * v63437 = v63177->cache_tags;
      int v63438 = v63437[v64041];
      int v63439 = v63435[v64028];
      int v63440 = v63437[v64028];
      bool v64043 = !(((~(((v63420 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63420 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31))) == 0);
      int v63494;
      if (v64043) {
        int * v63441 = v63177->cache_age;
        int v64045 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))) | (-(v63421 ^ ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1))))) >> 31)) & 1);
        int v63442 = v63441[v64045];
        int v63443 = v63441[v64029];
        int v64046 = v63443 + ((int)((unsigned int)(v63443 - v63442) >> 31));
        v63441[v64029] = v64046;
        int * v63445 = v63177->cache_age;
        int v63446 = v63445[v64030];
        int v64048 = v63446 + ((int)((unsigned int)(v63446 - v63442) >> 31));
        v63445[v64030] = v64048;
        int * v63448 = v63177->cache_age;
        v63448[v64045] = 0;
        v63494 = v64045;
      } else {
        int * v63451 = v63177->cache_age;
        int v64052 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2);
        int v63452 = v63451[v64052];
        int * v63453 = v63177->cache_tags;
        int v63454 = v63453[v64052];
        int v63455 = v63451[v64030];
        int v63456 = v63453[v64030];
        int * v63457 = v63177->cache_dirty;
        int v64055 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v63452 + ((~(((v63454 ^ -1) | (-(v63454 ^ -1))) >> 31)) & 2)) - (v63455 + ((~(((v63456 ^ -1) | (-(v63456 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v63458 = v63457[v64055];
        bool v64056 = !(v63458 == 0);
        if (v64056) {
          int * v63459 = v63177->cache_tags;
          int v63460 = v63459[v64055];
          int * v63461 = v63177->cache_vals;
          int v64059 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v63452 + ((~(((v63454 ^ -1) | (-(v63454 ^ -1))) >> 31)) & 2)) - (v63455 + ((~(((v63456 ^ -1) | (-(v63456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v63462 = v63461[v64059];
          int v64060 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v63452 + ((~(((v63454 ^ -1) | (-(v63454 ^ -1))) >> 31)) & 2)) - (v63455 + ((~(((v63456 ^ -1) | (-(v63456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v63463 = v63461[v64060];
          int * v63464 = v63177->mem;
          int v64062 = v63460 * 2;
          v63464[v64062] = v63462;
          int * v63466 = v63177->mem;
          int v64065 = (v63460 * 2) + 1;
          v63466[v64065] = v63463;
          ;
        } else {
          ;
        }
        int * v63471 = v63177->mem;
        int v64070 = ((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) * 2;
        int v63472 = v63471[v64070];
        int v64071 = (((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) * 2) + 1;
        int v63473 = v63471[v64071];
        int * v63474 = v63177->cache_vals;
        int v64073 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v63452 + ((~(((v63454 ^ -1) | (-(v63454 ^ -1))) >> 31)) & 2)) - (v63455 + ((~(((v63456 ^ -1) | (-(v63456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v63474[v64073] = v63472;
        int * v63476 = v63177->cache_vals;
        int v64076 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v63452 + ((~(((v63454 ^ -1) | (-(v63454 ^ -1))) >> 31)) & 2)) - (v63455 + ((~(((v63456 ^ -1) | (-(v63456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v63476[v64076] = v63473;
        int * v63478 = v63177->cache_tags;
        int v64079 = (int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1);
        v63478[v64055] = v64079;
        int * v63480 = v63177->cache_dirty;
        v63480[v64055] = 0;
        int * v63482 = v63177->cache_age;
        v63482[v64055] = 1;
        int * v63484 = v63177->cache_age;
        int v63485 = v63484[v64055];
        int v63486 = v63484[v64029];
        int v64085 = v63486 + ((int)((unsigned int)(v63486 - v63485) >> 31));
        v63484[v64029] = v64085;
        int * v63488 = v63177->cache_age;
        int v63489 = v63488[v64030];
        int v64087 = v63489 + ((int)((unsigned int)(v63489 - v63485) >> 31));
        v63488[v64030] = v64087;
        int * v63491 = v63177->cache_age;
        v63491[v64055] = 0;
        v63494 = v64055;
      }
      int * v63495 = v63177->cache_vals;
      int v64090 = v63494 * 2;
      int v63496 = v63495[v64090];
      int v64091 = (v63494 * 2) + 1;
      int v63497 = v63495[v64091];
      int v64092 = (((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v63436 + ((~(((v63438 ^ -1) | (-(v63438 ^ -1))) >> 31)) & 2)) - (v63439 + ((~(((v63440 ^ -1) | (-(v63440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v63495[v64092] = v63496;
      int * v63499 = v63177->cache_vals;
      int v64095 = ((((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v63436 + ((~(((v63438 ^ -1) | (-(v63438 ^ -1))) >> 31)) & 2)) - (v63439 + ((~(((v63440 ^ -1) | (-(v63440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v63499[v64095] = v63497;
      int * v63501 = v63177->cache_tags;
      int v64098 = ((((int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v63436 + ((~(((v63438 ^ -1) | (-(v63438 ^ -1))) >> 31)) & 2)) - (v63439 + ((~(((v63440 ^ -1) | (-(v63440 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64099 = (int)((unsigned int)((int)((unsigned int)(v63413 + 4) >> 2)) >> 1);
      v63501[v64098] = v64099;
      int * v63503 = v63177->cache_dirty;
      v63503[v64098] = 0;
      int * v63505 = v63177->cache_age;
      v63505[v64098] = 1;
      int * v63507 = v63177->cache_age;
      int v63508 = v63507[v64098];
      int v63509 = v63507[v64027];
      int v64105 = v63509 + ((int)((unsigned int)(v63509 - v63508) >> 31));
      v63507[v64027] = v64105;
      int * v63511 = v63177->cache_age;
      int v63512 = v63511[v64028];
      int v64107 = v63512 + ((int)((unsigned int)(v63512 - v63508) >> 31));
      v63511[v64028] = v64107;
      int * v63514 = v63177->cache_age;
      v63514[v64098] = 0;
      v63517 = v64098;
    }
    int v64110 = (v63517 * 2) + (((int)((unsigned int)(v63413 + 4) >> 2)) & 1);
    int v63518 = v63424[v64110];
    v63520 = v63518;
  }
  int * v63521 = v63177->regs;
  v63521[18] = v63520;
  int * v63523 = v63177->saved_regs;
  int * v63524 = v63177->regs;
  int v63525 = v63524[19];
  v63523[19] = v63525;
  int v63527 = v63177->timer;
  int v64118 = v63527 + 1;
  v63177->timer = v64118;
  int * v63529 = v63177->regs;
  int v63530 = v63529[2];
  bool v64120 = (((int)((unsigned int)(v63181 + 36) >> 2)) & 3) == (((int)((unsigned int)v63530 >> 2)) & 3);
  int v63637;
  if (v64120) {
    int v63531 = v63177->timer;
    int v64121 = v63531 + 1;
    v63177->timer = v64121;
    v63637 = v63182;
  } else {
    int * v63534 = v63177->cache_tags;
    int v64124 = (((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2;
    int v63535 = v63534[v64124];
    int v64125 = ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2) + 1;
    int v63536 = v63534[v64125];
    int v64126 = 4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2);
    int v63537 = v63534[v64126];
    int v64127 = (4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v63538 = v63534[v64127];
    int v63539 = v63177->timer;
    int v64128 = v63539 + ((100 ^ (((~(((v63537 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63537 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) | (~(((v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63535 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63535 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) | (~(((v63536 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63536 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v63537 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63537 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) | (~(((v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31))) & 104)))));
    v63177->timer = v64128;
    int * v63541 = v63177->cache_vals;
    bool v64129 = !(((~(((v63535 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63535 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) | (~(((v63536 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63536 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31))) == 0);
    int v63634;
    if (v64129) {
      int * v63542 = v63177->cache_age;
      int v64131 = ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2) + ((~(((v63536 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63536 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) & 1);
      int v63543 = v63542[v64131];
      int v63544 = v63542[v64124];
      int v64132 = v63544 + ((int)((unsigned int)(v63544 - v63543) >> 31));
      v63542[v64124] = v64132;
      int * v63546 = v63177->cache_age;
      int v63547 = v63546[v64125];
      int v64134 = v63547 + ((int)((unsigned int)(v63547 - v63543) >> 31));
      v63546[v64125] = v64134;
      int * v63549 = v63177->cache_age;
      v63549[v64131] = 0;
      v63634 = v64131;
    } else {
      int * v63552 = v63177->cache_age;
      int v64138 = (((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2;
      int v63553 = v63552[v64138];
      int * v63554 = v63177->cache_tags;
      int v63555 = v63554[v64138];
      int v63556 = v63552[v64125];
      int v63557 = v63554[v64125];
      bool v64140 = !(((~(((v63537 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63537 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) | (~(((v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31))) == 0);
      int v63611;
      if (v64140) {
        int * v63558 = v63177->cache_age;
        int v64142 = (4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + ((~(((v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))) | (-(v63538 ^ ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1))))) >> 31)) & 1);
        int v63559 = v63558[v64142];
        int v63560 = v63558[v64126];
        int v64143 = v63560 + ((int)((unsigned int)(v63560 - v63559) >> 31));
        v63558[v64126] = v64143;
        int * v63562 = v63177->cache_age;
        int v63563 = v63562[v64127];
        int v64145 = v63563 + ((int)((unsigned int)(v63563 - v63559) >> 31));
        v63562[v64127] = v64145;
        int * v63565 = v63177->cache_age;
        v63565[v64142] = 0;
        v63611 = v64142;
      } else {
        int * v63568 = v63177->cache_age;
        int v64149 = 4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2);
        int v63569 = v63568[v64149];
        int * v63570 = v63177->cache_tags;
        int v63571 = v63570[v64149];
        int v63572 = v63568[v64127];
        int v63573 = v63570[v64127];
        int * v63574 = v63177->cache_dirty;
        int v64152 = (4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + ((((v63569 + ((~(((v63571 ^ -1) | (-(v63571 ^ -1))) >> 31)) & 2)) - (v63572 + ((~(((v63573 ^ -1) | (-(v63573 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v63575 = v63574[v64152];
        bool v64153 = !(v63575 == 0);
        if (v64153) {
          int * v63576 = v63177->cache_tags;
          int v63577 = v63576[v64152];
          int * v63578 = v63177->cache_vals;
          int v64156 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + ((((v63569 + ((~(((v63571 ^ -1) | (-(v63571 ^ -1))) >> 31)) & 2)) - (v63572 + ((~(((v63573 ^ -1) | (-(v63573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v63579 = v63578[v64156];
          int v64157 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + ((((v63569 + ((~(((v63571 ^ -1) | (-(v63571 ^ -1))) >> 31)) & 2)) - (v63572 + ((~(((v63573 ^ -1) | (-(v63573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v63580 = v63578[v64157];
          int * v63581 = v63177->mem;
          int v64159 = v63577 * 2;
          v63581[v64159] = v63579;
          int * v63583 = v63177->mem;
          int v64162 = (v63577 * 2) + 1;
          v63583[v64162] = v63580;
          ;
        } else {
          ;
        }
        int * v63588 = v63177->mem;
        int v64167 = ((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) * 2;
        int v63589 = v63588[v64167];
        int v64168 = (((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) * 2) + 1;
        int v63590 = v63588[v64168];
        int * v63591 = v63177->cache_vals;
        int v64170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + ((((v63569 + ((~(((v63571 ^ -1) | (-(v63571 ^ -1))) >> 31)) & 2)) - (v63572 + ((~(((v63573 ^ -1) | (-(v63573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v63591[v64170] = v63589;
        int * v63593 = v63177->cache_vals;
        int v64173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 3) * 2)) + ((((v63569 + ((~(((v63571 ^ -1) | (-(v63571 ^ -1))) >> 31)) & 2)) - (v63572 + ((~(((v63573 ^ -1) | (-(v63573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v63593[v64173] = v63590;
        int * v63595 = v63177->cache_tags;
        int v64176 = (int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1);
        v63595[v64152] = v64176;
        int * v63597 = v63177->cache_dirty;
        v63597[v64152] = 0;
        int * v63599 = v63177->cache_age;
        v63599[v64152] = 1;
        int * v63601 = v63177->cache_age;
        int v63602 = v63601[v64152];
        int v63603 = v63601[v64126];
        int v64182 = v63603 + ((int)((unsigned int)(v63603 - v63602) >> 31));
        v63601[v64126] = v64182;
        int * v63605 = v63177->cache_age;
        int v63606 = v63605[v64127];
        int v64184 = v63606 + ((int)((unsigned int)(v63606 - v63602) >> 31));
        v63605[v64127] = v64184;
        int * v63608 = v63177->cache_age;
        v63608[v64152] = 0;
        v63611 = v64152;
      }
      int * v63612 = v63177->cache_vals;
      int v64187 = v63611 * 2;
      int v63613 = v63612[v64187];
      int v64188 = (v63611 * 2) + 1;
      int v63614 = v63612[v64188];
      int v64189 = (((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2) + ((((v63553 + ((~(((v63555 ^ -1) | (-(v63555 ^ -1))) >> 31)) & 2)) - (v63556 + ((~(((v63557 ^ -1) | (-(v63557 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v63612[v64189] = v63613;
      int * v63616 = v63177->cache_vals;
      int v64192 = ((((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2) + ((((v63553 + ((~(((v63555 ^ -1) | (-(v63555 ^ -1))) >> 31)) & 2)) - (v63556 + ((~(((v63557 ^ -1) | (-(v63557 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v63616[v64192] = v63614;
      int * v63618 = v63177->cache_tags;
      int v64195 = ((((int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1)) & 1) * 2) + ((((v63553 + ((~(((v63555 ^ -1) | (-(v63555 ^ -1))) >> 31)) & 2)) - (v63556 + ((~(((v63557 ^ -1) | (-(v63557 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64196 = (int)((unsigned int)((int)((unsigned int)v63530 >> 2)) >> 1);
      v63618[v64195] = v64196;
      int * v63620 = v63177->cache_dirty;
      v63620[v64195] = 0;
      int * v63622 = v63177->cache_age;
      v63622[v64195] = 1;
      int * v63624 = v63177->cache_age;
      int v63625 = v63624[v64195];
      int v63626 = v63624[v64124];
      int v64202 = v63626 + ((int)((unsigned int)(v63626 - v63625) >> 31));
      v63624[v64124] = v64202;
      int * v63628 = v63177->cache_age;
      int v63629 = v63628[v64125];
      int v64204 = v63629 + ((int)((unsigned int)(v63629 - v63625) >> 31));
      v63628[v64125] = v64204;
      int * v63631 = v63177->cache_age;
      v63631[v64195] = 0;
      v63634 = v64195;
    }
    int v64207 = (v63634 * 2) + (((int)((unsigned int)v63530 >> 2)) & 1);
    int v63635 = v63541[v64207];
    v63637 = v63635;
  }
  int * v63638 = v63177->regs;
  v63638[19] = v63637;
  int * v63640 = v63177->cache_tags;
  int v64212 = (((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2;
  int v63641 = v63640[v64212];
  int v64213 = ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v63642 = v63640[v64213];
  int v64214 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2);
  int v63643 = v63640[v64214];
  int v64215 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v63644 = v63640[v64215];
  int v63645 = v63177->timer;
  int v64216 = v63645 + ((100 ^ (((~(((v63643 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63643 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63641 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63641 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v63642 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63642 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v63643 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63643 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v63177->timer = v64216;
  bool v64217 = !(((~(((v63641 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63641 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v63642 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63642 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v63739;
  if (v64217) {
    int * v63647 = v63177->cache_age;
    int v64219 = ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v63642 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63642 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v63648 = v63647[v64219];
    int v63649 = v63647[v64212];
    int v64220 = v63649 + ((int)((unsigned int)(v63649 - v63648) >> 31));
    v63647[v64212] = v64220;
    int * v63651 = v63177->cache_age;
    int v63652 = v63651[v64213];
    int v64222 = v63652 + ((int)((unsigned int)(v63652 - v63648) >> 31));
    v63651[v64213] = v64222;
    int * v63654 = v63177->cache_age;
    v63654[v64219] = 0;
    v63739 = v64219;
  } else {
    int * v63657 = v63177->cache_age;
    int v64226 = (((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2;
    int v63658 = v63657[v64226];
    int * v63659 = v63177->cache_tags;
    int v63660 = v63659[v64226];
    int v63661 = v63657[v64213];
    int v63662 = v63659[v64213];
    bool v64228 = !(((~(((v63643 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63643 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v63716;
    if (v64228) {
      int * v63663 = v63177->cache_age;
      int v64230 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63644 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v63664 = v63663[v64230];
      int v63665 = v63663[v64214];
      int v64231 = v63665 + ((int)((unsigned int)(v63665 - v63664) >> 31));
      v63663[v64214] = v64231;
      int * v63667 = v63177->cache_age;
      int v63668 = v63667[v64215];
      int v64233 = v63668 + ((int)((unsigned int)(v63668 - v63664) >> 31));
      v63667[v64215] = v64233;
      int * v63670 = v63177->cache_age;
      v63670[v64230] = 0;
      v63716 = v64230;
    } else {
      int * v63673 = v63177->cache_age;
      int v64237 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2);
      int v63674 = v63673[v64237];
      int * v63675 = v63177->cache_tags;
      int v63676 = v63675[v64237];
      int v63677 = v63673[v64215];
      int v63678 = v63675[v64215];
      int * v63679 = v63177->cache_dirty;
      int v64240 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63674 + ((~(((v63676 ^ -1) | (-(v63676 ^ -1))) >> 31)) & 2)) - (v63677 + ((~(((v63678 ^ -1) | (-(v63678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v63680 = v63679[v64240];
      bool v64241 = !(v63680 == 0);
      if (v64241) {
        int * v63681 = v63177->cache_tags;
        int v63682 = v63681[v64240];
        int * v63683 = v63177->cache_vals;
        int v64244 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63674 + ((~(((v63676 ^ -1) | (-(v63676 ^ -1))) >> 31)) & 2)) - (v63677 + ((~(((v63678 ^ -1) | (-(v63678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63684 = v63683[v64244];
        int v64245 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63674 + ((~(((v63676 ^ -1) | (-(v63676 ^ -1))) >> 31)) & 2)) - (v63677 + ((~(((v63678 ^ -1) | (-(v63678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v63685 = v63683[v64245];
        int * v63686 = v63177->mem;
        int v64247 = v63682 * 2;
        v63686[v64247] = v63684;
        int * v63688 = v63177->mem;
        int v64250 = (v63682 * 2) + 1;
        v63688[v64250] = v63685;
        ;
      } else {
        ;
      }
      int * v63693 = v63177->mem;
      int v64255 = ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) * 2;
      int v63694 = v63693[v64255];
      int v64256 = (((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) * 2) + 1;
      int v63695 = v63693[v64256];
      int * v63696 = v63177->cache_vals;
      int v64258 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63674 + ((~(((v63676 ^ -1) | (-(v63676 ^ -1))) >> 31)) & 2)) - (v63677 + ((~(((v63678 ^ -1) | (-(v63678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v63696[v64258] = v63694;
      int * v63698 = v63177->cache_vals;
      int v64261 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63674 + ((~(((v63676 ^ -1) | (-(v63676 ^ -1))) >> 31)) & 2)) - (v63677 + ((~(((v63678 ^ -1) | (-(v63678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v63698[v64261] = v63695;
      int * v63700 = v63177->cache_tags;
      int v64264 = (int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1);
      v63700[v64240] = v64264;
      int * v63702 = v63177->cache_dirty;
      v63702[v64240] = 0;
      int * v63704 = v63177->cache_age;
      v63704[v64240] = 1;
      int * v63706 = v63177->cache_age;
      int v63707 = v63706[v64240];
      int v63708 = v63706[v64214];
      int v64270 = v63708 + ((int)((unsigned int)(v63708 - v63707) >> 31));
      v63706[v64214] = v64270;
      int * v63710 = v63177->cache_age;
      int v63711 = v63710[v64215];
      int v64272 = v63711 + ((int)((unsigned int)(v63711 - v63707) >> 31));
      v63710[v64215] = v64272;
      int * v63713 = v63177->cache_age;
      v63713[v64240] = 0;
      v63716 = v64240;
    }
    int * v63717 = v63177->cache_vals;
    int v64275 = v63716 * 2;
    int v63718 = v63717[v64275];
    int v64276 = (v63716 * 2) + 1;
    int v63719 = v63717[v64276];
    int v64277 = (((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v63658 + ((~(((v63660 ^ -1) | (-(v63660 ^ -1))) >> 31)) & 2)) - (v63661 + ((~(((v63662 ^ -1) | (-(v63662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v63717[v64277] = v63718;
    int * v63721 = v63177->cache_vals;
    int v64280 = ((((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v63658 + ((~(((v63660 ^ -1) | (-(v63660 ^ -1))) >> 31)) & 2)) - (v63661 + ((~(((v63662 ^ -1) | (-(v63662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v63721[v64280] = v63719;
    int * v63723 = v63177->cache_tags;
    int v64283 = ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v63658 + ((~(((v63660 ^ -1) | (-(v63660 ^ -1))) >> 31)) & 2)) - (v63661 + ((~(((v63662 ^ -1) | (-(v63662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v64284 = (int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1);
    v63723[v64283] = v64284;
    int * v63725 = v63177->cache_dirty;
    v63725[v64283] = 0;
    int * v63727 = v63177->cache_age;
    v63727[v64283] = 1;
    int * v63729 = v63177->cache_age;
    int v63730 = v63729[v64283];
    int v63731 = v63729[v64212];
    int v64290 = v63731 + ((int)((unsigned int)(v63731 - v63730) >> 31));
    v63729[v64212] = v64290;
    int * v63733 = v63177->cache_age;
    int v63734 = v63733[v64213];
    int v64292 = v63734 + ((int)((unsigned int)(v63734 - v63730) >> 31));
    v63733[v64213] = v64292;
    int * v63736 = v63177->cache_age;
    v63736[v64283] = 0;
    v63739 = v64283;
  }
  int * v63740 = v63177->cache_vals;
  int v64295 = (v63739 * 2) + (((int)((unsigned int)(v63181 + 36) >> 2)) & 1);
  v63740[v64295] = v63182;
  int * v63742 = v63177->cache_tags;
  int v63743 = v63742[v64214];
  int v63744 = v63742[v64215];
  bool v64298 = !(((~(((v63743 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63743 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v63744 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63744 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v63798;
  if (v64298) {
    int * v63745 = v63177->cache_age;
    int v64300 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v63744 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))) | (-(v63744 ^ ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v63746 = v63745[v64300];
    int v63747 = v63745[v64214];
    int v64301 = v63747 + ((int)((unsigned int)(v63747 - v63746) >> 31));
    v63745[v64214] = v64301;
    int * v63749 = v63177->cache_age;
    int v63750 = v63749[v64215];
    int v64303 = v63750 + ((int)((unsigned int)(v63750 - v63746) >> 31));
    v63749[v64215] = v64303;
    int * v63752 = v63177->cache_age;
    v63752[v64300] = 0;
    v63798 = v64300;
  } else {
    int * v63755 = v63177->cache_age;
    int v64307 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2);
    int v63756 = v63755[v64307];
    int * v63757 = v63177->cache_tags;
    int v63758 = v63757[v64307];
    int v63759 = v63755[v64215];
    int v63760 = v63757[v64215];
    int * v63761 = v63177->cache_dirty;
    int v64310 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63756 + ((~(((v63758 ^ -1) | (-(v63758 ^ -1))) >> 31)) & 2)) - (v63759 + ((~(((v63760 ^ -1) | (-(v63760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v63762 = v63761[v64310];
    bool v64311 = !(v63762 == 0);
    if (v64311) {
      int * v63763 = v63177->cache_tags;
      int v63764 = v63763[v64310];
      int * v63765 = v63177->cache_vals;
      int v64314 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63756 + ((~(((v63758 ^ -1) | (-(v63758 ^ -1))) >> 31)) & 2)) - (v63759 + ((~(((v63760 ^ -1) | (-(v63760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v63766 = v63765[v64314];
      int v64315 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63756 + ((~(((v63758 ^ -1) | (-(v63758 ^ -1))) >> 31)) & 2)) - (v63759 + ((~(((v63760 ^ -1) | (-(v63760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v63767 = v63765[v64315];
      int * v63768 = v63177->mem;
      int v64317 = v63764 * 2;
      v63768[v64317] = v63766;
      int * v63770 = v63177->mem;
      int v64320 = (v63764 * 2) + 1;
      v63770[v64320] = v63767;
      ;
    } else {
      ;
    }
    int * v63775 = v63177->mem;
    int v64325 = ((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) * 2;
    int v63776 = v63775[v64325];
    int v64326 = (((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) * 2) + 1;
    int v63777 = v63775[v64326];
    int * v63778 = v63177->cache_vals;
    int v64328 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63756 + ((~(((v63758 ^ -1) | (-(v63758 ^ -1))) >> 31)) & 2)) - (v63759 + ((~(((v63760 ^ -1) | (-(v63760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v63778[v64328] = v63776;
    int * v63780 = v63177->cache_vals;
    int v64331 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v63756 + ((~(((v63758 ^ -1) | (-(v63758 ^ -1))) >> 31)) & 2)) - (v63759 + ((~(((v63760 ^ -1) | (-(v63760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v63780[v64331] = v63777;
    int * v63782 = v63177->cache_tags;
    int v64334 = (int)((unsigned int)((int)((unsigned int)(v63181 + 36) >> 2)) >> 1);
    v63782[v64310] = v64334;
    int * v63784 = v63177->cache_dirty;
    v63784[v64310] = 0;
    int * v63786 = v63177->cache_age;
    v63786[v64310] = 1;
    int * v63788 = v63177->cache_age;
    int v63789 = v63788[v64310];
    int v63790 = v63788[v64214];
    int v64340 = v63790 + ((int)((unsigned int)(v63790 - v63789) >> 31));
    v63788[v64214] = v64340;
    int * v63792 = v63177->cache_age;
    int v63793 = v63792[v64215];
    int v64342 = v63793 + ((int)((unsigned int)(v63793 - v63789) >> 31));
    v63792[v64215] = v64342;
    int * v63795 = v63177->cache_age;
    v63795[v64310] = 0;
    v63798 = v64310;
  }
  int * v63799 = v63177->cache_vals;
  int v64345 = (v63798 * 2) + (((int)((unsigned int)(v63181 + 36) >> 2)) & 1);
  v63799[v64345] = v63182;
  int * v63801 = v63177->cache_dirty;
  v63801[v63798] = 1;
  bool v64349 = (((((int)((unsigned int)(v63189 + 12) >> 2)) == ((int)((unsigned int)(v63181 + 36) >> 2))) | (((int)((unsigned int)(v63301 + 8) >> 2)) == ((int)((unsigned int)(v63181 + 36) >> 2)))) | (((((int)((unsigned int)(v63413 + 4) >> 2)) & 3) == (((int)((unsigned int)(v63181 + 36) >> 2)) & 3)) & (!(((int)((unsigned int)(v63413 + 4) >> 2)) == ((int)((unsigned int)(v63181 + 36) >> 2)))))) | (((((int)((unsigned int)v63530 >> 2)) & 3) == (((int)((unsigned int)(v63181 + 36) >> 2)) & 3)) & (!(((int)((unsigned int)v63530 >> 2)) == ((int)((unsigned int)(v63181 + 36) >> 2)))));
  struct StateT * v63825;
  if (v64349) {
    int v63803 = v63177->timer;
    int v64350 = v63803 + 15;
    v63177->timer = v64350;
    int * v63805 = v63177->saved_regs;
    int v63806 = v63805[8];
    int * v63807 = v63177->regs;
    v63807[8] = v63806;
    int * v63809 = v63177->saved_regs;
    int v63810 = v63809[9];
    int * v63811 = v63177->regs;
    v63811[9] = v63810;
    int * v63813 = v63177->saved_regs;
    int v63814 = v63813[18];
    int * v63815 = v63177->regs;
    v63815[18] = v63814;
    int * v63817 = v63177->saved_regs;
    int v63818 = v63817[19];
    int * v63819 = v63177->regs;
    v63819[19] = v63818;
    struct StateT * v63821 = slot_1090(v63177);
    v63825 = v63821;
  } else {
    struct StateT * v63823 = slot_850(v63177);
    v63825 = v63823;
  }
  return v63825;
}

struct StateT * slot_850(struct StateT * v47384) {
  int v47385 = v47384->timer;
  int v47392 = v47385 + 1;
  v47384->timer = v47392;
  int * v47387 = v47384->regs;
  int v47388 = v47387[2];
  int v47395 = v47388 + 16;
  v47387[2] = v47395;
  struct StateT * v47390 = slot_929(v47384);
  return v47390;
}

struct StateT * slot_21(struct StateT * v2383) {
  int v2384 = v2383->timer;
  int v2396 = v2384 + 1;
  v2383->timer = v2396;
  int * v2386 = v2383->regs;
  int v2387 = v2386[17];
  int v2388 = v2386[7];
  bool v2400 = (v2387 ^ -2147483648) < (v2388 ^ -2147483648);
  int v2391;
  if (v2400) {
    v2391 = 1;
  } else {
    v2391 = 0;
  }
  int * v2392 = v2383->regs;
  v2392[5] = v2391;
  struct StateT * v2394 = slot_22(v2383);
  return v2394;
}

struct StateT * slot_1116(struct StateT * v85945) {
  int v85946 = v85945->timer;
  int v86056 = v85946 + 1;
  v85945->timer = v86056;
  int * v85948 = v85945->regs;
  int v85949 = v85948[2];
  int * v85950 = v85945->cache_tags;
  int v86060 = (((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2;
  int v85951 = v85950[v86060];
  int v86061 = ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v85952 = v85950[v86061];
  int v86062 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2);
  int v85953 = v85950[v86062];
  int v86063 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v85954 = v85950[v86063];
  int v85955 = v85945->timer;
  int v86064 = v85955 + ((100 ^ (((~(((v85953 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85953 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v85951 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85951 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v85952 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85952 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v85953 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85953 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v85945->timer = v86064;
  int * v85957 = v85945->cache_vals;
  bool v86065 = !(((~(((v85951 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85951 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v85952 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85952 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v86050;
  if (v86065) {
    int * v85958 = v85945->cache_age;
    int v86067 = ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v85952 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85952 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v85959 = v85958[v86067];
    int v85960 = v85958[v86060];
    int v86068 = v85960 + ((int)((unsigned int)(v85960 - v85959) >> 31));
    v85958[v86060] = v86068;
    int * v85962 = v85945->cache_age;
    int v85963 = v85962[v86061];
    int v86070 = v85963 + ((int)((unsigned int)(v85963 - v85959) >> 31));
    v85962[v86061] = v86070;
    int * v85965 = v85945->cache_age;
    v85965[v86067] = 0;
    v86050 = v86067;
  } else {
    int * v85968 = v85945->cache_age;
    int v86074 = (((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2;
    int v85969 = v85968[v86074];
    int * v85970 = v85945->cache_tags;
    int v85971 = v85970[v86074];
    int v85972 = v85968[v86061];
    int v85973 = v85970[v86061];
    bool v86076 = !(((~(((v85953 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85953 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v86027;
    if (v86076) {
      int * v85974 = v85945->cache_age;
      int v86078 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))) | (-(v85954 ^ ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v85975 = v85974[v86078];
      int v85976 = v85974[v86062];
      int v86079 = v85976 + ((int)((unsigned int)(v85976 - v85975) >> 31));
      v85974[v86062] = v86079;
      int * v85978 = v85945->cache_age;
      int v85979 = v85978[v86063];
      int v86081 = v85979 + ((int)((unsigned int)(v85979 - v85975) >> 31));
      v85978[v86063] = v86081;
      int * v85981 = v85945->cache_age;
      v85981[v86078] = 0;
      v86027 = v86078;
    } else {
      int * v85984 = v85945->cache_age;
      int v86085 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2);
      int v85985 = v85984[v86085];
      int * v85986 = v85945->cache_tags;
      int v85987 = v85986[v86085];
      int v85988 = v85984[v86063];
      int v85989 = v85986[v86063];
      int * v85990 = v85945->cache_dirty;
      int v86088 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v85985 + ((~(((v85987 ^ -1) | (-(v85987 ^ -1))) >> 31)) & 2)) - (v85988 + ((~(((v85989 ^ -1) | (-(v85989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v85991 = v85990[v86088];
      bool v86089 = !(v85991 == 0);
      if (v86089) {
        int * v85992 = v85945->cache_tags;
        int v85993 = v85992[v86088];
        int * v85994 = v85945->cache_vals;
        int v86092 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v85985 + ((~(((v85987 ^ -1) | (-(v85987 ^ -1))) >> 31)) & 2)) - (v85988 + ((~(((v85989 ^ -1) | (-(v85989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v85995 = v85994[v86092];
        int v86093 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v85985 + ((~(((v85987 ^ -1) | (-(v85987 ^ -1))) >> 31)) & 2)) - (v85988 + ((~(((v85989 ^ -1) | (-(v85989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v85996 = v85994[v86093];
        int * v85997 = v85945->mem;
        int v86095 = v85993 * 2;
        v85997[v86095] = v85995;
        int * v85999 = v85945->mem;
        int v86098 = (v85993 * 2) + 1;
        v85999[v86098] = v85996;
        ;
      } else {
        ;
      }
      int * v86004 = v85945->mem;
      int v86103 = ((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) * 2;
      int v86005 = v86004[v86103];
      int v86104 = (((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) * 2) + 1;
      int v86006 = v86004[v86104];
      int * v86007 = v85945->cache_vals;
      int v86106 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v85985 + ((~(((v85987 ^ -1) | (-(v85987 ^ -1))) >> 31)) & 2)) - (v85988 + ((~(((v85989 ^ -1) | (-(v85989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v86007[v86106] = v86005;
      int * v86009 = v85945->cache_vals;
      int v86109 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v85985 + ((~(((v85987 ^ -1) | (-(v85987 ^ -1))) >> 31)) & 2)) - (v85988 + ((~(((v85989 ^ -1) | (-(v85989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v86009[v86109] = v86006;
      int * v86011 = v85945->cache_tags;
      int v86112 = (int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1);
      v86011[v86088] = v86112;
      int * v86013 = v85945->cache_dirty;
      v86013[v86088] = 0;
      int * v86015 = v85945->cache_age;
      v86015[v86088] = 1;
      int * v86017 = v85945->cache_age;
      int v86018 = v86017[v86088];
      int v86019 = v86017[v86062];
      int v86118 = v86019 + ((int)((unsigned int)(v86019 - v86018) >> 31));
      v86017[v86062] = v86118;
      int * v86021 = v85945->cache_age;
      int v86022 = v86021[v86063];
      int v86120 = v86022 + ((int)((unsigned int)(v86022 - v86018) >> 31));
      v86021[v86063] = v86120;
      int * v86024 = v85945->cache_age;
      v86024[v86088] = 0;
      v86027 = v86088;
    }
    int * v86028 = v85945->cache_vals;
    int v86123 = v86027 * 2;
    int v86029 = v86028[v86123];
    int v86124 = (v86027 * 2) + 1;
    int v86030 = v86028[v86124];
    int v86125 = (((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v85969 + ((~(((v85971 ^ -1) | (-(v85971 ^ -1))) >> 31)) & 2)) - (v85972 + ((~(((v85973 ^ -1) | (-(v85973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v86028[v86125] = v86029;
    int * v86032 = v85945->cache_vals;
    int v86128 = ((((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v85969 + ((~(((v85971 ^ -1) | (-(v85971 ^ -1))) >> 31)) & 2)) - (v85972 + ((~(((v85973 ^ -1) | (-(v85973 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v86032[v86128] = v86030;
    int * v86034 = v85945->cache_tags;
    int v86131 = ((((int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v85969 + ((~(((v85971 ^ -1) | (-(v85971 ^ -1))) >> 31)) & 2)) - (v85972 + ((~(((v85973 ^ -1) | (-(v85973 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v86132 = (int)((unsigned int)((int)((unsigned int)(v85949 + 4) >> 2)) >> 1);
    v86034[v86131] = v86132;
    int * v86036 = v85945->cache_dirty;
    v86036[v86131] = 0;
    int * v86038 = v85945->cache_age;
    v86038[v86131] = 1;
    int * v86040 = v85945->cache_age;
    int v86041 = v86040[v86131];
    int v86042 = v86040[v86060];
    int v86138 = v86042 + ((int)((unsigned int)(v86042 - v86041) >> 31));
    v86040[v86060] = v86138;
    int * v86044 = v85945->cache_age;
    int v86045 = v86044[v86061];
    int v86140 = v86045 + ((int)((unsigned int)(v86045 - v86041) >> 31));
    v86044[v86061] = v86140;
    int * v86047 = v85945->cache_age;
    v86047[v86131] = 0;
    v86050 = v86131;
  }
  int v86143 = (v86050 * 2) + (((int)((unsigned int)(v85949 + 4) >> 2)) & 1);
  int v86051 = v85957[v86143];
  int * v86052 = v85945->regs;
  v86052[18] = v86051;
  struct StateT * v86054 = slot_958(v85945);
  return v86054;
}

struct StateT * slot_118(struct StateT * v8131) {
  int v8132 = v8131->timer;
  int v8140 = v8132 + 1;
  v8131->timer = v8140;
  int * v8134 = v8131->regs;
  int v8135 = v8134[30];
  int v8136 = v8134[7];
  int v8144 = v8135 + v8136;
  v8134[7] = v8144;
  struct StateT * v8138 = slot_120(v8131);
  return v8138;
}

struct StateT * slot_833(struct StateT * v45937) {
  int v45938 = v45937->timer;
  int v45946 = v45938 + 1;
  v45937->timer = v45946;
  int * v45940 = v45937->regs;
  int v45941 = v45940[12];
  int v45942 = v45940[5];
  int v45950 = v45941 + v45942;
  v45940[5] = v45950;
  struct StateT * v45944 = slot_861(v45937);
  return v45944;
}

struct StateT * slot_376(struct StateT * v22529) {
  int v22530 = v22529->timer;
  int v22538 = v22530 + 1;
  v22529->timer = v22538;
  int * v22532 = v22529->regs;
  int v22533 = v22532[11];
  int v22534 = v22532[12];
  int v22543 = v22533 * v22534;
  v22532[28] = v22543;
  struct StateT * v22536 = slot_489(v22529);
  return v22536;
}

struct StateT * slot_373(struct StateT * v22445) {
  int v22446 = v22445->timer;
  int v22458 = v22446 + 1;
  v22445->timer = v22458;
  int * v22448 = v22445->regs;
  int v22449 = v22448[28];
  int v22450 = v22448[5];
  bool v22462 = (v22449 ^ -2147483648) < (v22450 ^ -2147483648);
  int v22453;
  if (v22462) {
    v22453 = 1;
  } else {
    v22453 = 0;
  }
  int * v22454 = v22445->regs;
  v22454[5] = v22453;
  struct StateT * v22456 = slot_421(v22445);
  return v22456;
}

struct StateT * slot_146(struct StateT * v8663) {
  int * v8664 = v8663->saved_regs;
  int * v8665 = v8663->regs;
  int v8666 = v8665[29];
  v8664[29] = v8666;
  int v8668 = v8663->timer;
  int v8680 = v8668 + 1;
  v8663->timer = v8680;
  int * v8670 = v8663->regs;
  int v8671 = v8670[7];
  int v8672 = v8670[16];
  int v8684 = v8671 & v8672;
  v8670[29] = v8684;
  struct StateT * v8674 = slot_148(v8663);
  return v8674;
}

struct StateT * slot_383(struct StateT * v23583) {
  int v23584 = v23583->timer;
  int v23591 = v23584 + 1;
  v23583->timer = v23591;
  int * v23586 = v23583->regs;
  int v23587 = v23586[5];
  int v23594 = v23587 << 13;
  v23586[5] = v23594;
  struct StateT * v23589 = slot_391(v23583);
  return v23589;
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

struct StateT * slot_489(struct StateT * v30140) {
  int v30141 = v30140->timer;
  int v30149 = v30141 + 1;
  v30140->timer = v30149;
  int * v30143 = v30140->regs;
  int v30144 = v30143[11];
  int v30145 = v30143[12];
  int v30154 = (((((int)((unsigned int)v30144 >> 16)) * ((int)((unsigned int)v30145 >> 16))) + ((int)((unsigned int)((v30144 & 65535) * ((int)((unsigned int)v30145 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v30144 >> 16)) * (v30145 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v30144 & 65535) * (v30145 & 65535)) >> 16)) + (((v30144 & 65535) * ((int)((unsigned int)v30145 >> 16))) & 65535)) + ((((int)((unsigned int)v30144 >> 16)) * (v30145 & 65535)) & 65535)) >> 16));
  v30143[29] = v30154;
  struct StateT * v30147 = slot_466(v30140);
  return v30147;
}

struct StateT * slot_148(struct StateT * v8695) {
  int * v8696 = v8695->saved_regs;
  int * v8697 = v8695->regs;
  int v8698 = v8697[7];
  v8696[7] = v8698;
  int v8700 = v8695->timer;
  int v8711 = v8700 + 1;
  v8695->timer = v8711;
  int * v8702 = v8695->regs;
  int v8703 = v8702[7];
  int v8713 = (int)((unsigned int)v8703 >> 19);
  v8702[7] = v8713;
  struct StateT * v8705 = slot_150(v8695);
  return v8705;
}

struct StateT * slot_421(struct StateT * v27074) {
  int v27075 = v27074->timer;
  int v27245 = v27075 + 1;
  v27074->timer = v27245;
  int * v27077 = v27074->regs;
  int v27078 = v27077[10];
  int v27079 = v27077[17];
  int * v27080 = v27074->cache_tags;
  int v27250 = (((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2;
  int v27081 = v27080[v27250];
  int v27251 = ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v27082 = v27080[v27251];
  int v27252 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2);
  int v27083 = v27080[v27252];
  int v27253 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v27084 = v27080[v27253];
  int v27085 = v27074->timer;
  int v27254 = v27085 + ((100 ^ (((~(((v27083 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27083 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v27081 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27081 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v27082 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27082 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v27083 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27083 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v27074->timer = v27254;
  bool v27255 = !(((~(((v27081 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27081 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v27082 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27082 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v27179;
  if (v27255) {
    int * v27087 = v27074->cache_age;
    int v27257 = ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v27082 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27082 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v27088 = v27087[v27257];
    int v27089 = v27087[v27250];
    int v27258 = v27089 + ((int)((unsigned int)(v27089 - v27088) >> 31));
    v27087[v27250] = v27258;
    int * v27091 = v27074->cache_age;
    int v27092 = v27091[v27251];
    int v27260 = v27092 + ((int)((unsigned int)(v27092 - v27088) >> 31));
    v27091[v27251] = v27260;
    int * v27094 = v27074->cache_age;
    v27094[v27257] = 0;
    v27179 = v27257;
  } else {
    int * v27097 = v27074->cache_age;
    int v27264 = (((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2;
    int v27098 = v27097[v27264];
    int * v27099 = v27074->cache_tags;
    int v27100 = v27099[v27264];
    int v27101 = v27097[v27251];
    int v27102 = v27099[v27251];
    bool v27266 = !(((~(((v27083 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27083 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v27156;
    if (v27266) {
      int * v27103 = v27074->cache_age;
      int v27268 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27084 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v27104 = v27103[v27268];
      int v27105 = v27103[v27252];
      int v27269 = v27105 + ((int)((unsigned int)(v27105 - v27104) >> 31));
      v27103[v27252] = v27269;
      int * v27107 = v27074->cache_age;
      int v27108 = v27107[v27253];
      int v27271 = v27108 + ((int)((unsigned int)(v27108 - v27104) >> 31));
      v27107[v27253] = v27271;
      int * v27110 = v27074->cache_age;
      v27110[v27268] = 0;
      v27156 = v27268;
    } else {
      int * v27113 = v27074->cache_age;
      int v27275 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2);
      int v27114 = v27113[v27275];
      int * v27115 = v27074->cache_tags;
      int v27116 = v27115[v27275];
      int v27117 = v27113[v27253];
      int v27118 = v27115[v27253];
      int * v27119 = v27074->cache_dirty;
      int v27278 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27114 + ((~(((v27116 ^ -1) | (-(v27116 ^ -1))) >> 31)) & 2)) - (v27117 + ((~(((v27118 ^ -1) | (-(v27118 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v27120 = v27119[v27278];
      bool v27279 = !(v27120 == 0);
      if (v27279) {
        int * v27121 = v27074->cache_tags;
        int v27122 = v27121[v27278];
        int * v27123 = v27074->cache_vals;
        int v27282 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27114 + ((~(((v27116 ^ -1) | (-(v27116 ^ -1))) >> 31)) & 2)) - (v27117 + ((~(((v27118 ^ -1) | (-(v27118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v27124 = v27123[v27282];
        int v27283 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27114 + ((~(((v27116 ^ -1) | (-(v27116 ^ -1))) >> 31)) & 2)) - (v27117 + ((~(((v27118 ^ -1) | (-(v27118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v27125 = v27123[v27283];
        int * v27126 = v27074->mem;
        int v27285 = v27122 * 2;
        v27126[v27285] = v27124;
        int * v27128 = v27074->mem;
        int v27288 = (v27122 * 2) + 1;
        v27128[v27288] = v27125;
        ;
      } else {
        ;
      }
      int * v27133 = v27074->mem;
      int v27293 = ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) * 2;
      int v27134 = v27133[v27293];
      int v27294 = (((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) * 2) + 1;
      int v27135 = v27133[v27294];
      int * v27136 = v27074->cache_vals;
      int v27296 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27114 + ((~(((v27116 ^ -1) | (-(v27116 ^ -1))) >> 31)) & 2)) - (v27117 + ((~(((v27118 ^ -1) | (-(v27118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v27136[v27296] = v27134;
      int * v27138 = v27074->cache_vals;
      int v27299 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27114 + ((~(((v27116 ^ -1) | (-(v27116 ^ -1))) >> 31)) & 2)) - (v27117 + ((~(((v27118 ^ -1) | (-(v27118 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v27138[v27299] = v27135;
      int * v27140 = v27074->cache_tags;
      int v27302 = (int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1);
      v27140[v27278] = v27302;
      int * v27142 = v27074->cache_dirty;
      v27142[v27278] = 0;
      int * v27144 = v27074->cache_age;
      v27144[v27278] = 1;
      int * v27146 = v27074->cache_age;
      int v27147 = v27146[v27278];
      int v27148 = v27146[v27252];
      int v27308 = v27148 + ((int)((unsigned int)(v27148 - v27147) >> 31));
      v27146[v27252] = v27308;
      int * v27150 = v27074->cache_age;
      int v27151 = v27150[v27253];
      int v27310 = v27151 + ((int)((unsigned int)(v27151 - v27147) >> 31));
      v27150[v27253] = v27310;
      int * v27153 = v27074->cache_age;
      v27153[v27278] = 0;
      v27156 = v27278;
    }
    int * v27157 = v27074->cache_vals;
    int v27313 = v27156 * 2;
    int v27158 = v27157[v27313];
    int v27314 = (v27156 * 2) + 1;
    int v27159 = v27157[v27314];
    int v27315 = (((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v27098 + ((~(((v27100 ^ -1) | (-(v27100 ^ -1))) >> 31)) & 2)) - (v27101 + ((~(((v27102 ^ -1) | (-(v27102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v27157[v27315] = v27158;
    int * v27161 = v27074->cache_vals;
    int v27318 = ((((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v27098 + ((~(((v27100 ^ -1) | (-(v27100 ^ -1))) >> 31)) & 2)) - (v27101 + ((~(((v27102 ^ -1) | (-(v27102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v27161[v27318] = v27159;
    int * v27163 = v27074->cache_tags;
    int v27321 = ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v27098 + ((~(((v27100 ^ -1) | (-(v27100 ^ -1))) >> 31)) & 2)) - (v27101 + ((~(((v27102 ^ -1) | (-(v27102 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v27322 = (int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1);
    v27163[v27321] = v27322;
    int * v27165 = v27074->cache_dirty;
    v27165[v27321] = 0;
    int * v27167 = v27074->cache_age;
    v27167[v27321] = 1;
    int * v27169 = v27074->cache_age;
    int v27170 = v27169[v27321];
    int v27171 = v27169[v27250];
    int v27328 = v27171 + ((int)((unsigned int)(v27171 - v27170) >> 31));
    v27169[v27250] = v27328;
    int * v27173 = v27074->cache_age;
    int v27174 = v27173[v27251];
    int v27330 = v27174 + ((int)((unsigned int)(v27174 - v27170) >> 31));
    v27173[v27251] = v27330;
    int * v27176 = v27074->cache_age;
    v27176[v27321] = 0;
    v27179 = v27321;
  }
  int * v27180 = v27074->cache_vals;
  int v27333 = (v27179 * 2) + (((int)((unsigned int)(v27078 + 24) >> 2)) & 1);
  v27180[v27333] = v27079;
  int * v27182 = v27074->cache_tags;
  int v27183 = v27182[v27252];
  int v27184 = v27182[v27253];
  bool v27336 = !(((~(((v27183 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27183 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v27184 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27184 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v27238;
  if (v27336) {
    int * v27185 = v27074->cache_age;
    int v27338 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v27184 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))) | (-(v27184 ^ ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v27186 = v27185[v27338];
    int v27187 = v27185[v27252];
    int v27339 = v27187 + ((int)((unsigned int)(v27187 - v27186) >> 31));
    v27185[v27252] = v27339;
    int * v27189 = v27074->cache_age;
    int v27190 = v27189[v27253];
    int v27341 = v27190 + ((int)((unsigned int)(v27190 - v27186) >> 31));
    v27189[v27253] = v27341;
    int * v27192 = v27074->cache_age;
    v27192[v27338] = 0;
    v27238 = v27338;
  } else {
    int * v27195 = v27074->cache_age;
    int v27345 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2);
    int v27196 = v27195[v27345];
    int * v27197 = v27074->cache_tags;
    int v27198 = v27197[v27345];
    int v27199 = v27195[v27253];
    int v27200 = v27197[v27253];
    int * v27201 = v27074->cache_dirty;
    int v27348 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27196 + ((~(((v27198 ^ -1) | (-(v27198 ^ -1))) >> 31)) & 2)) - (v27199 + ((~(((v27200 ^ -1) | (-(v27200 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v27202 = v27201[v27348];
    bool v27349 = !(v27202 == 0);
    if (v27349) {
      int * v27203 = v27074->cache_tags;
      int v27204 = v27203[v27348];
      int * v27205 = v27074->cache_vals;
      int v27352 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27196 + ((~(((v27198 ^ -1) | (-(v27198 ^ -1))) >> 31)) & 2)) - (v27199 + ((~(((v27200 ^ -1) | (-(v27200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v27206 = v27205[v27352];
      int v27353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27196 + ((~(((v27198 ^ -1) | (-(v27198 ^ -1))) >> 31)) & 2)) - (v27199 + ((~(((v27200 ^ -1) | (-(v27200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v27207 = v27205[v27353];
      int * v27208 = v27074->mem;
      int v27355 = v27204 * 2;
      v27208[v27355] = v27206;
      int * v27210 = v27074->mem;
      int v27358 = (v27204 * 2) + 1;
      v27210[v27358] = v27207;
      ;
    } else {
      ;
    }
    int * v27215 = v27074->mem;
    int v27363 = ((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) * 2;
    int v27216 = v27215[v27363];
    int v27364 = (((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) * 2) + 1;
    int v27217 = v27215[v27364];
    int * v27218 = v27074->cache_vals;
    int v27366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27196 + ((~(((v27198 ^ -1) | (-(v27198 ^ -1))) >> 31)) & 2)) - (v27199 + ((~(((v27200 ^ -1) | (-(v27200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v27218[v27366] = v27216;
    int * v27220 = v27074->cache_vals;
    int v27369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v27196 + ((~(((v27198 ^ -1) | (-(v27198 ^ -1))) >> 31)) & 2)) - (v27199 + ((~(((v27200 ^ -1) | (-(v27200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v27220[v27369] = v27217;
    int * v27222 = v27074->cache_tags;
    int v27372 = (int)((unsigned int)((int)((unsigned int)(v27078 + 24) >> 2)) >> 1);
    v27222[v27348] = v27372;
    int * v27224 = v27074->cache_dirty;
    v27224[v27348] = 0;
    int * v27226 = v27074->cache_age;
    v27226[v27348] = 1;
    int * v27228 = v27074->cache_age;
    int v27229 = v27228[v27348];
    int v27230 = v27228[v27252];
    int v27378 = v27230 + ((int)((unsigned int)(v27230 - v27229) >> 31));
    v27228[v27252] = v27378;
    int * v27232 = v27074->cache_age;
    int v27233 = v27232[v27253];
    int v27380 = v27233 + ((int)((unsigned int)(v27233 - v27229) >> 31));
    v27232[v27253] = v27380;
    int * v27235 = v27074->cache_age;
    v27235[v27348] = 0;
    v27238 = v27348;
  }
  int * v27239 = v27074->cache_vals;
  int v27383 = (v27238 * 2) + (((int)((unsigned int)(v27078 + 24) >> 2)) & 1);
  v27239[v27383] = v27079;
  int * v27241 = v27074->cache_dirty;
  v27241[v27238] = 1;
  struct StateT * v27243 = slot_348(v27074);
  return v27243;
}

struct StateT * slot_725(struct StateT * v34595) {
  int v34596 = v34595->timer;
  int v34603 = v34596 + 1;
  v34595->timer = v34603;
  int * v34598 = v34595->regs;
  int v34599 = v34598[12];
  int v34606 = v34599 << 13;
  v34598[12] = v34606;
  struct StateT * v34601 = slot_730(v34595);
  return v34601;
}

struct StateT * slot_918(struct StateT * v56459) {
  int v56460 = v56459->timer;
  int v56467 = v56460 + 1;
  v56459->timer = v56467;
  int * v56462 = v56459->regs;
  int v56463 = v56462[5];
  int v56470 = (int)((unsigned int)v56463 >> 19);
  v56462[5] = v56470;
  struct StateT * v56465 = slot_972(v56459);
  return v56465;
}

struct StateT * slot_79(struct StateT * v7008) {
  int v7009 = v7008->timer;
  int v7119 = v7009 + 1;
  v7008->timer = v7119;
  int * v7011 = v7008->regs;
  int v7012 = v7011[11];
  int * v7013 = v7008->cache_tags;
  int v7123 = (((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2;
  int v7014 = v7013[v7123];
  int v7124 = ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7015 = v7013[v7124];
  int v7125 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2);
  int v7016 = v7013[v7125];
  int v7126 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7017 = v7013[v7126];
  int v7018 = v7008->timer;
  int v7127 = v7018 + ((100 ^ (((~(((v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7008->timer = v7127;
  int * v7020 = v7008->cache_vals;
  bool v7128 = !(((~(((v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7014 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v7113;
  if (v7128) {
    int * v7021 = v7008->cache_age;
    int v7130 = ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7015 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v7022 = v7021[v7130];
    int v7023 = v7021[v7123];
    int v7131 = v7023 + ((int)((unsigned int)(v7023 - v7022) >> 31));
    v7021[v7123] = v7131;
    int * v7025 = v7008->cache_age;
    int v7026 = v7025[v7124];
    int v7133 = v7026 + ((int)((unsigned int)(v7026 - v7022) >> 31));
    v7025[v7124] = v7133;
    int * v7028 = v7008->cache_age;
    v7028[v7130] = 0;
    v7113 = v7130;
  } else {
    int * v7031 = v7008->cache_age;
    int v7137 = (((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2;
    int v7032 = v7031[v7137];
    int * v7033 = v7008->cache_tags;
    int v7034 = v7033[v7137];
    int v7035 = v7031[v7124];
    int v7036 = v7033[v7124];
    bool v7139 = !(((~(((v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7016 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v7090;
    if (v7139) {
      int * v7037 = v7008->cache_age;
      int v7141 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))) | (-(v7017 ^ ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v7038 = v7037[v7141];
      int v7039 = v7037[v7125];
      int v7142 = v7039 + ((int)((unsigned int)(v7039 - v7038) >> 31));
      v7037[v7125] = v7142;
      int * v7041 = v7008->cache_age;
      int v7042 = v7041[v7126];
      int v7144 = v7042 + ((int)((unsigned int)(v7042 - v7038) >> 31));
      v7041[v7126] = v7144;
      int * v7044 = v7008->cache_age;
      v7044[v7141] = 0;
      v7090 = v7141;
    } else {
      int * v7047 = v7008->cache_age;
      int v7148 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2);
      int v7048 = v7047[v7148];
      int * v7049 = v7008->cache_tags;
      int v7050 = v7049[v7148];
      int v7051 = v7047[v7126];
      int v7052 = v7049[v7126];
      int * v7053 = v7008->cache_dirty;
      int v7151 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7048 + ((~(((v7050 ^ -1) | (-(v7050 ^ -1))) >> 31)) & 2)) - (v7051 + ((~(((v7052 ^ -1) | (-(v7052 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7054 = v7053[v7151];
      bool v7152 = !(v7054 == 0);
      if (v7152) {
        int * v7055 = v7008->cache_tags;
        int v7056 = v7055[v7151];
        int * v7057 = v7008->cache_vals;
        int v7155 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7048 + ((~(((v7050 ^ -1) | (-(v7050 ^ -1))) >> 31)) & 2)) - (v7051 + ((~(((v7052 ^ -1) | (-(v7052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7058 = v7057[v7155];
        int v7156 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7048 + ((~(((v7050 ^ -1) | (-(v7050 ^ -1))) >> 31)) & 2)) - (v7051 + ((~(((v7052 ^ -1) | (-(v7052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7059 = v7057[v7156];
        int * v7060 = v7008->mem;
        int v7158 = v7056 * 2;
        v7060[v7158] = v7058;
        int * v7062 = v7008->mem;
        int v7161 = (v7056 * 2) + 1;
        v7062[v7161] = v7059;
        ;
      } else {
        ;
      }
      int * v7067 = v7008->mem;
      int v7166 = ((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) * 2;
      int v7068 = v7067[v7166];
      int v7167 = (((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) * 2) + 1;
      int v7069 = v7067[v7167];
      int * v7070 = v7008->cache_vals;
      int v7169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7048 + ((~(((v7050 ^ -1) | (-(v7050 ^ -1))) >> 31)) & 2)) - (v7051 + ((~(((v7052 ^ -1) | (-(v7052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7070[v7169] = v7068;
      int * v7072 = v7008->cache_vals;
      int v7172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v7048 + ((~(((v7050 ^ -1) | (-(v7050 ^ -1))) >> 31)) & 2)) - (v7051 + ((~(((v7052 ^ -1) | (-(v7052 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7072[v7172] = v7069;
      int * v7074 = v7008->cache_tags;
      int v7175 = (int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1);
      v7074[v7151] = v7175;
      int * v7076 = v7008->cache_dirty;
      v7076[v7151] = 0;
      int * v7078 = v7008->cache_age;
      v7078[v7151] = 1;
      int * v7080 = v7008->cache_age;
      int v7081 = v7080[v7151];
      int v7082 = v7080[v7125];
      int v7181 = v7082 + ((int)((unsigned int)(v7082 - v7081) >> 31));
      v7080[v7125] = v7181;
      int * v7084 = v7008->cache_age;
      int v7085 = v7084[v7126];
      int v7183 = v7085 + ((int)((unsigned int)(v7085 - v7081) >> 31));
      v7084[v7126] = v7183;
      int * v7087 = v7008->cache_age;
      v7087[v7151] = 0;
      v7090 = v7151;
    }
    int * v7091 = v7008->cache_vals;
    int v7186 = v7090 * 2;
    int v7092 = v7091[v7186];
    int v7187 = (v7090 * 2) + 1;
    int v7093 = v7091[v7187];
    int v7188 = (((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v7032 + ((~(((v7034 ^ -1) | (-(v7034 ^ -1))) >> 31)) & 2)) - (v7035 + ((~(((v7036 ^ -1) | (-(v7036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7091[v7188] = v7092;
    int * v7095 = v7008->cache_vals;
    int v7191 = ((((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v7032 + ((~(((v7034 ^ -1) | (-(v7034 ^ -1))) >> 31)) & 2)) - (v7035 + ((~(((v7036 ^ -1) | (-(v7036 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7095[v7191] = v7093;
    int * v7097 = v7008->cache_tags;
    int v7194 = ((((int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v7032 + ((~(((v7034 ^ -1) | (-(v7034 ^ -1))) >> 31)) & 2)) - (v7035 + ((~(((v7036 ^ -1) | (-(v7036 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7195 = (int)((unsigned int)((int)((unsigned int)(v7012 + 16) >> 2)) >> 1);
    v7097[v7194] = v7195;
    int * v7099 = v7008->cache_dirty;
    v7099[v7194] = 0;
    int * v7101 = v7008->cache_age;
    v7101[v7194] = 1;
    int * v7103 = v7008->cache_age;
    int v7104 = v7103[v7194];
    int v7105 = v7103[v7123];
    int v7201 = v7105 + ((int)((unsigned int)(v7105 - v7104) >> 31));
    v7103[v7123] = v7201;
    int * v7107 = v7008->cache_age;
    int v7108 = v7107[v7124];
    int v7203 = v7108 + ((int)((unsigned int)(v7108 - v7104) >> 31));
    v7107[v7124] = v7203;
    int * v7110 = v7008->cache_age;
    v7110[v7194] = 0;
    v7113 = v7194;
  }
  int v7206 = (v7113 * 2) + (((int)((unsigned int)(v7012 + 16) >> 2)) & 1);
  int v7114 = v7020[v7206];
  int * v7115 = v7008->regs;
  v7115[6] = v7114;
  struct StateT * v7117 = slot_91(v7008);
  return v7117;
}

struct StateT * slot_568(struct StateT * v31648) {
  int v31649 = v31648->timer;
  int v31657 = v31649 + 1;
  v31648->timer = v31657;
  int * v31651 = v31648->regs;
  int v31652 = v31651[13];
  int v31653 = v31651[28];
  int v31661 = v31652 + v31653;
  v31651[13] = v31661;
  struct StateT * v31655 = slot_634(v31648);
  return v31655;
}

struct StateT * slot_810(struct StateT * v40536) {
  int v40537 = v40536->timer;
  int v40545 = v40537 + 1;
  v40536->timer = v40545;
  int * v40539 = v40536->regs;
  int v40540 = v40539[12];
  int v40541 = v40539[14];
  int v40549 = v40540 + v40541;
  v40539[12] = v40549;
  struct StateT * v40543 = slot_744(v40536);
  return v40543;
}

struct StateT * slot_571(struct StateT * v31705) {
  int v31706 = v31705->timer;
  int v31714 = v31706 + 1;
  v31705->timer = v31714;
  int * v31708 = v31705->regs;
  int v31709 = v31708[31];
  int v31710 = v31708[12];
  int v31718 = v31709 + v31710;
  v31708[12] = v31718;
  struct StateT * v31712 = slot_548(v31705);
  return v31712;
}

struct StateT * slot_142(struct StateT * v8582) {
  int * v8583 = v8582->saved_regs;
  int * v8584 = v8582->regs;
  int v8585 = v8584[28];
  v8583[28] = v8585;
  int v8587 = v8582->timer;
  int v8603 = v8587 + 1;
  v8582->timer = v8603;
  int * v8589 = v8582->regs;
  int v8590 = v8589[7];
  int v8591 = v8589[29];
  bool v8607 = (v8590 ^ -2147483648) < (v8591 ^ -2147483648);
  int v8594;
  if (v8607) {
    v8594 = 1;
  } else {
    v8594 = 0;
  }
  int * v8595 = v8582->regs;
  v8595[28] = v8594;
  struct StateT * v8597 = slot_151(v8582);
  return v8597;
}

struct StateT * slot_624(struct StateT * v32707) {
  int v32708 = v32707->timer;
  int v32716 = v32708 + 1;
  v32707->timer = v32716;
  int * v32710 = v32707->regs;
  int v32711 = v32710[13];
  int v32712 = v32710[12];
  int v32720 = v32711 + v32712;
  v32710[12] = v32720;
  struct StateT * v32714 = slot_662(v32707);
  return v32714;
}

struct StateT * slot_1038(struct StateT * v66854) {
  int v66855 = v66854->timer;
  int v66863 = v66855 + 1;
  v66854->timer = v66863;
  int * v66857 = v66854->regs;
  int v66858 = v66857[15];
  int v66859 = v66857[12];
  int v66867 = v66858 + v66859;
  v66857[12] = v66867;
  struct StateT * v66861 = slot_984(v66854);
  return v66861;
}

struct StateT * slot_738(struct StateT * v34812) {
  int v34813 = v34812->timer;
  int v34821 = v34813 + 1;
  v34812->timer = v34821;
  int * v34815 = v34812->regs;
  int v34816 = v34815[13];
  int v34817 = v34815[17];
  int v34826 = (((((int)((unsigned int)v34816 >> 16)) * ((int)((unsigned int)v34817 >> 16))) + ((int)((unsigned int)((v34816 & 65535) * ((int)((unsigned int)v34817 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v34816 >> 16)) * (v34817 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v34816 & 65535) * (v34817 & 65535)) >> 16)) + (((v34816 & 65535) * ((int)((unsigned int)v34817 >> 16))) & 65535)) + ((((int)((unsigned int)v34816 >> 16)) * (v34817 & 65535)) & 65535)) >> 16));
  v34815[5] = v34826;
  struct StateT * v34819 = slot_749(v34812);
  return v34819;
}

struct StateT * slot_214(struct StateT * v14787) {
  int v14788 = v14787->timer;
  int v14796 = v14788 + 1;
  v14787->timer = v14796;
  int * v14790 = v14787->regs;
  int v14791 = v14790[29];
  int v14792 = v14790[12];
  int v14801 = (((((int)((unsigned int)v14791 >> 16)) * ((int)((unsigned int)v14792 >> 16))) + ((int)((unsigned int)((v14791 & 65535) * ((int)((unsigned int)v14792 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v14791 >> 16)) * (v14792 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v14791 & 65535) * (v14792 & 65535)) >> 16)) + (((v14791 & 65535) * ((int)((unsigned int)v14792 >> 16))) & 65535)) + ((((int)((unsigned int)v14791 >> 16)) * (v14792 & 65535)) & 65535)) >> 16));
  v14790[30] = v14801;
  struct StateT * v14794 = slot_200(v14787);
  return v14794;
}

struct StateT * slot_29(struct StateT * v3847) {
  int v3848 = v3847->timer;
  int v3958 = v3848 + 1;
  v3847->timer = v3958;
  int * v3850 = v3847->regs;
  int v3851 = v3850[11];
  int * v3852 = v3847->cache_tags;
  int v3962 = (((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2;
  int v3853 = v3852[v3962];
  int v3963 = ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3854 = v3852[v3963];
  int v3964 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2);
  int v3855 = v3852[v3964];
  int v3965 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3856 = v3852[v3965];
  int v3857 = v3847->timer;
  int v3966 = v3857 + ((100 ^ (((~(((v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3847->timer = v3966;
  int * v3859 = v3847->cache_vals;
  bool v3967 = !(((~(((v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3853 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3952;
  if (v3967) {
    int * v3860 = v3847->cache_age;
    int v3969 = ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3854 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3861 = v3860[v3969];
    int v3862 = v3860[v3962];
    int v3970 = v3862 + ((int)((unsigned int)(v3862 - v3861) >> 31));
    v3860[v3962] = v3970;
    int * v3864 = v3847->cache_age;
    int v3865 = v3864[v3963];
    int v3972 = v3865 + ((int)((unsigned int)(v3865 - v3861) >> 31));
    v3864[v3963] = v3972;
    int * v3867 = v3847->cache_age;
    v3867[v3969] = 0;
    v3952 = v3969;
  } else {
    int * v3870 = v3847->cache_age;
    int v3976 = (((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2;
    int v3871 = v3870[v3976];
    int * v3872 = v3847->cache_tags;
    int v3873 = v3872[v3976];
    int v3874 = v3870[v3963];
    int v3875 = v3872[v3963];
    bool v3978 = !(((~(((v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3855 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3929;
    if (v3978) {
      int * v3876 = v3847->cache_age;
      int v3980 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))) | (-(v3856 ^ ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v3877 = v3876[v3980];
      int v3878 = v3876[v3964];
      int v3981 = v3878 + ((int)((unsigned int)(v3878 - v3877) >> 31));
      v3876[v3964] = v3981;
      int * v3880 = v3847->cache_age;
      int v3881 = v3880[v3965];
      int v3983 = v3881 + ((int)((unsigned int)(v3881 - v3877) >> 31));
      v3880[v3965] = v3983;
      int * v3883 = v3847->cache_age;
      v3883[v3980] = 0;
      v3929 = v3980;
    } else {
      int * v3886 = v3847->cache_age;
      int v3987 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3887 = v3886[v3987];
      int * v3888 = v3847->cache_tags;
      int v3889 = v3888[v3987];
      int v3890 = v3886[v3965];
      int v3891 = v3888[v3965];
      int * v3892 = v3847->cache_dirty;
      int v3990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3893 = v3892[v3990];
      bool v3991 = !(v3893 == 0);
      if (v3991) {
        int * v3894 = v3847->cache_tags;
        int v3895 = v3894[v3990];
        int * v3896 = v3847->cache_vals;
        int v3994 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3897 = v3896[v3994];
        int v3995 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3898 = v3896[v3995];
        int * v3899 = v3847->mem;
        int v3997 = v3895 * 2;
        v3899[v3997] = v3897;
        int * v3901 = v3847->mem;
        int v4000 = (v3895 * 2) + 1;
        v3901[v4000] = v3898;
        ;
      } else {
        ;
      }
      int * v3906 = v3847->mem;
      int v4005 = ((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) * 2;
      int v3907 = v3906[v4005];
      int v4006 = (((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3908 = v3906[v4006];
      int * v3909 = v3847->cache_vals;
      int v4008 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3909[v4008] = v3907;
      int * v3911 = v3847->cache_vals;
      int v4011 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3887 + ((~(((v3889 ^ -1) | (-(v3889 ^ -1))) >> 31)) & 2)) - (v3890 + ((~(((v3891 ^ -1) | (-(v3891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3911[v4011] = v3908;
      int * v3913 = v3847->cache_tags;
      int v4014 = (int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1);
      v3913[v3990] = v4014;
      int * v3915 = v3847->cache_dirty;
      v3915[v3990] = 0;
      int * v3917 = v3847->cache_age;
      v3917[v3990] = 1;
      int * v3919 = v3847->cache_age;
      int v3920 = v3919[v3990];
      int v3921 = v3919[v3964];
      int v4020 = v3921 + ((int)((unsigned int)(v3921 - v3920) >> 31));
      v3919[v3964] = v4020;
      int * v3923 = v3847->cache_age;
      int v3924 = v3923[v3965];
      int v4022 = v3924 + ((int)((unsigned int)(v3924 - v3920) >> 31));
      v3923[v3965] = v4022;
      int * v3926 = v3847->cache_age;
      v3926[v3990] = 0;
      v3929 = v3990;
    }
    int * v3930 = v3847->cache_vals;
    int v4025 = v3929 * 2;
    int v3931 = v3930[v4025];
    int v4026 = (v3929 * 2) + 1;
    int v3932 = v3930[v4026];
    int v4027 = (((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3871 + ((~(((v3873 ^ -1) | (-(v3873 ^ -1))) >> 31)) & 2)) - (v3874 + ((~(((v3875 ^ -1) | (-(v3875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3930[v4027] = v3931;
    int * v3934 = v3847->cache_vals;
    int v4030 = ((((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3871 + ((~(((v3873 ^ -1) | (-(v3873 ^ -1))) >> 31)) & 2)) - (v3874 + ((~(((v3875 ^ -1) | (-(v3875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3934[v4030] = v3932;
    int * v3936 = v3847->cache_tags;
    int v4033 = ((((int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3871 + ((~(((v3873 ^ -1) | (-(v3873 ^ -1))) >> 31)) & 2)) - (v3874 + ((~(((v3875 ^ -1) | (-(v3875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4034 = (int)((unsigned int)((int)((unsigned int)(v3851 + 12) >> 2)) >> 1);
    v3936[v4033] = v4034;
    int * v3938 = v3847->cache_dirty;
    v3938[v4033] = 0;
    int * v3940 = v3847->cache_age;
    v3940[v4033] = 1;
    int * v3942 = v3847->cache_age;
    int v3943 = v3942[v4033];
    int v3944 = v3942[v3962];
    int v4040 = v3944 + ((int)((unsigned int)(v3944 - v3943) >> 31));
    v3942[v3962] = v4040;
    int * v3946 = v3847->cache_age;
    int v3947 = v3946[v3963];
    int v4042 = v3947 + ((int)((unsigned int)(v3947 - v3943) >> 31));
    v3946[v3963] = v4042;
    int * v3949 = v3847->cache_age;
    v3949[v4033] = 0;
    v3952 = v4033;
  }
  int v4045 = (v3952 * 2) + (((int)((unsigned int)(v3851 + 12) >> 2)) & 1);
  int v3953 = v3859[v4045];
  int * v3954 = v3847->regs;
  v3954[28] = v3953;
  struct StateT * v3956 = slot_30(v3847);
  return v3956;
}

struct StateT * slot_151(struct StateT * v8779) {
  int v8780 = v8779->timer;
  int v8788 = v8780 + 1;
  v8779->timer = v8788;
  int * v8782 = v8779->regs;
  int v8783 = v8782[5];
  int v8784 = v8782[28];
  int v8792 = v8783 + v8784;
  v8782[28] = v8792;
  struct StateT * v8786 = slot_146(v8779);
  return v8786;
}

struct StateT * slot_7(struct StateT * v2182) {
  int v2183 = v2182->timer;
  int v2189 = v2183 + 1;
  v2182->timer = v2189;
  int * v2185 = v2182->regs;
  v2185[16] = 524288;
  struct StateT * v2187 = slot_8(v2182);
  return v2187;
}

struct StateT * slot_124(struct StateT * v8255) {
  int v8256 = v8255->timer;
  int v8264 = v8256 + 1;
  v8255->timer = v8264;
  int * v8258 = v8255->regs;
  int v8259 = v8258[8];
  int v8260 = v8258[6];
  int v8268 = v8259 + v8260;
  v8258[6] = v8268;
  struct StateT * v8262 = slot_126(v8255);
  return v8262;
}

struct StateT * slot_128(struct StateT * v8328) {
  int v8329 = v8328->timer;
  int v8337 = v8329 + 1;
  v8328->timer = v8337;
  int * v8331 = v8328->regs;
  int v8332 = v8331[9];
  int v8333 = v8331[6];
  int v8342 = v8332 + v8333;
  v8331[5] = v8342;
  struct StateT * v8335 = slot_130(v8328);
  return v8335;
}

struct StateT * slot_365(struct StateT * v22499) {
  int v22500 = v22499->timer;
  int v22507 = v22500 + 1;
  v22499->timer = v22507;
  int * v22502 = v22499->regs;
  int v22503 = v22502[28];
  int v22510 = v22503 << 13;
  v22502[28] = v22510;
  struct StateT * v22505 = slot_355(v22499);
  return v22505;
}

struct StateT * slot_1025(struct StateT * v66629) {
  int v66630 = v66629->timer;
  int v66740 = v66630 + 1;
  v66629->timer = v66740;
  int * v66632 = v66629->regs;
  int v66633 = v66632[2];
  int * v66634 = v66629->cache_tags;
  int v66744 = (((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2;
  int v66635 = v66634[v66744];
  int v66745 = ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v66636 = v66634[v66745];
  int v66746 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2);
  int v66637 = v66634[v66746];
  int v66747 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v66638 = v66634[v66747];
  int v66639 = v66629->timer;
  int v66748 = v66639 + ((100 ^ (((~(((v66637 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66637 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v66635 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66635 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v66636 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66636 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v66637 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66637 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v66629->timer = v66748;
  int * v66641 = v66629->cache_vals;
  bool v66749 = !(((~(((v66635 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66635 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v66636 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66636 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v66734;
  if (v66749) {
    int * v66642 = v66629->cache_age;
    int v66751 = ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v66636 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66636 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v66643 = v66642[v66751];
    int v66644 = v66642[v66744];
    int v66752 = v66644 + ((int)((unsigned int)(v66644 - v66643) >> 31));
    v66642[v66744] = v66752;
    int * v66646 = v66629->cache_age;
    int v66647 = v66646[v66745];
    int v66754 = v66647 + ((int)((unsigned int)(v66647 - v66643) >> 31));
    v66646[v66745] = v66754;
    int * v66649 = v66629->cache_age;
    v66649[v66751] = 0;
    v66734 = v66751;
  } else {
    int * v66652 = v66629->cache_age;
    int v66758 = (((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2;
    int v66653 = v66652[v66758];
    int * v66654 = v66629->cache_tags;
    int v66655 = v66654[v66758];
    int v66656 = v66652[v66745];
    int v66657 = v66654[v66745];
    bool v66760 = !(((~(((v66637 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66637 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v66711;
    if (v66760) {
      int * v66658 = v66629->cache_age;
      int v66762 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))) | (-(v66638 ^ ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v66659 = v66658[v66762];
      int v66660 = v66658[v66746];
      int v66763 = v66660 + ((int)((unsigned int)(v66660 - v66659) >> 31));
      v66658[v66746] = v66763;
      int * v66662 = v66629->cache_age;
      int v66663 = v66662[v66747];
      int v66765 = v66663 + ((int)((unsigned int)(v66663 - v66659) >> 31));
      v66662[v66747] = v66765;
      int * v66665 = v66629->cache_age;
      v66665[v66762] = 0;
      v66711 = v66762;
    } else {
      int * v66668 = v66629->cache_age;
      int v66769 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2);
      int v66669 = v66668[v66769];
      int * v66670 = v66629->cache_tags;
      int v66671 = v66670[v66769];
      int v66672 = v66668[v66747];
      int v66673 = v66670[v66747];
      int * v66674 = v66629->cache_dirty;
      int v66772 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v66669 + ((~(((v66671 ^ -1) | (-(v66671 ^ -1))) >> 31)) & 2)) - (v66672 + ((~(((v66673 ^ -1) | (-(v66673 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v66675 = v66674[v66772];
      bool v66773 = !(v66675 == 0);
      if (v66773) {
        int * v66676 = v66629->cache_tags;
        int v66677 = v66676[v66772];
        int * v66678 = v66629->cache_vals;
        int v66776 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v66669 + ((~(((v66671 ^ -1) | (-(v66671 ^ -1))) >> 31)) & 2)) - (v66672 + ((~(((v66673 ^ -1) | (-(v66673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66679 = v66678[v66776];
        int v66777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v66669 + ((~(((v66671 ^ -1) | (-(v66671 ^ -1))) >> 31)) & 2)) - (v66672 + ((~(((v66673 ^ -1) | (-(v66673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66680 = v66678[v66777];
        int * v66681 = v66629->mem;
        int v66779 = v66677 * 2;
        v66681[v66779] = v66679;
        int * v66683 = v66629->mem;
        int v66782 = (v66677 * 2) + 1;
        v66683[v66782] = v66680;
        ;
      } else {
        ;
      }
      int * v66688 = v66629->mem;
      int v66787 = ((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) * 2;
      int v66689 = v66688[v66787];
      int v66788 = (((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) * 2) + 1;
      int v66690 = v66688[v66788];
      int * v66691 = v66629->cache_vals;
      int v66790 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v66669 + ((~(((v66671 ^ -1) | (-(v66671 ^ -1))) >> 31)) & 2)) - (v66672 + ((~(((v66673 ^ -1) | (-(v66673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v66691[v66790] = v66689;
      int * v66693 = v66629->cache_vals;
      int v66793 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v66669 + ((~(((v66671 ^ -1) | (-(v66671 ^ -1))) >> 31)) & 2)) - (v66672 + ((~(((v66673 ^ -1) | (-(v66673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v66693[v66793] = v66690;
      int * v66695 = v66629->cache_tags;
      int v66796 = (int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1);
      v66695[v66772] = v66796;
      int * v66697 = v66629->cache_dirty;
      v66697[v66772] = 0;
      int * v66699 = v66629->cache_age;
      v66699[v66772] = 1;
      int * v66701 = v66629->cache_age;
      int v66702 = v66701[v66772];
      int v66703 = v66701[v66746];
      int v66802 = v66703 + ((int)((unsigned int)(v66703 - v66702) >> 31));
      v66701[v66746] = v66802;
      int * v66705 = v66629->cache_age;
      int v66706 = v66705[v66747];
      int v66804 = v66706 + ((int)((unsigned int)(v66706 - v66702) >> 31));
      v66705[v66747] = v66804;
      int * v66708 = v66629->cache_age;
      v66708[v66772] = 0;
      v66711 = v66772;
    }
    int * v66712 = v66629->cache_vals;
    int v66807 = v66711 * 2;
    int v66713 = v66712[v66807];
    int v66808 = (v66711 * 2) + 1;
    int v66714 = v66712[v66808];
    int v66809 = (((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v66653 + ((~(((v66655 ^ -1) | (-(v66655 ^ -1))) >> 31)) & 2)) - (v66656 + ((~(((v66657 ^ -1) | (-(v66657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v66712[v66809] = v66713;
    int * v66716 = v66629->cache_vals;
    int v66812 = ((((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v66653 + ((~(((v66655 ^ -1) | (-(v66655 ^ -1))) >> 31)) & 2)) - (v66656 + ((~(((v66657 ^ -1) | (-(v66657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v66716[v66812] = v66714;
    int * v66718 = v66629->cache_tags;
    int v66815 = ((((int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v66653 + ((~(((v66655 ^ -1) | (-(v66655 ^ -1))) >> 31)) & 2)) - (v66656 + ((~(((v66657 ^ -1) | (-(v66657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v66816 = (int)((unsigned int)((int)((unsigned int)(v66633 + 8) >> 2)) >> 1);
    v66718[v66815] = v66816;
    int * v66720 = v66629->cache_dirty;
    v66720[v66815] = 0;
    int * v66722 = v66629->cache_age;
    v66722[v66815] = 1;
    int * v66724 = v66629->cache_age;
    int v66725 = v66724[v66815];
    int v66726 = v66724[v66744];
    int v66822 = v66726 + ((int)((unsigned int)(v66726 - v66725) >> 31));
    v66724[v66744] = v66822;
    int * v66728 = v66629->cache_age;
    int v66729 = v66728[v66745];
    int v66824 = v66729 + ((int)((unsigned int)(v66729 - v66725) >> 31));
    v66728[v66745] = v66824;
    int * v66731 = v66629->cache_age;
    v66731[v66815] = 0;
    v66734 = v66815;
  }
  int v66827 = (v66734 * 2) + (((int)((unsigned int)(v66633 + 8) >> 2)) & 1);
  int v66735 = v66641[v66827];
  int * v66736 = v66629->regs;
  v66736[9] = v66735;
  struct StateT * v66738 = slot_1116(v66629);
  return v66738;
}

struct StateT * slot_622(struct StateT * v32675) {
  int v32676 = v32675->timer;
  int v32684 = v32676 + 1;
  v32675->timer = v32684;
  int * v32678 = v32675->regs;
  int v32679 = v32678[12];
  int v32680 = v32678[5];
  int v32688 = v32679 + v32680;
  v32678[5] = v32688;
  struct StateT * v32682 = slot_628(v32675);
  return v32682;
}

struct StateT * slot_523(struct StateT * v30767) {
  int v30768 = v30767->timer;
  int v30780 = v30768 + 1;
  v30767->timer = v30780;
  int * v30770 = v30767->regs;
  int v30771 = v30770[5];
  int v30772 = v30770[28];
  bool v30784 = (v30771 ^ -2147483648) < (v30772 ^ -2147483648);
  int v30775;
  if (v30784) {
    v30775 = 1;
  } else {
    v30775 = 0;
  }
  int * v30776 = v30767->regs;
  v30776[7] = v30775;
  struct StateT * v30778 = slot_502(v30767);
  return v30778;
}

struct StateT * slot_782(struct StateT * v37912) {
  int * v37913 = v37912->saved_regs;
  int * v37914 = v37912->regs;
  int v37915 = v37914[14];
  v37913[14] = v37915;
  int v37917 = v37912->timer;
  int v37933 = v37917 + 1;
  v37912->timer = v37933;
  int * v37919 = v37912->regs;
  int v37920 = v37919[13];
  int v37921 = v37919[14];
  bool v37936 = (v37920 ^ -2147483648) < (v37921 ^ -2147483648);
  int v37924;
  if (v37936) {
    v37924 = 1;
  } else {
    v37924 = 0;
  }
  int * v37925 = v37912->regs;
  v37925[14] = v37924;
  struct StateT * v37927 = slot_799(v37912);
  return v37927;
}

struct StateT * slot_87(struct StateT * v7228) {
  int v7229 = v7228->timer;
  int v7236 = v7229 + 1;
  v7228->timer = v7236;
  int * v7231 = v7228->regs;
  int v7232 = v7231[28];
  int v7240 = (int)((unsigned int)v7232 >> 19);
  v7231[17] = v7240;
  struct StateT * v7234 = slot_88(v7228);
  return v7234;
}

struct StateT * slot_452(struct StateT * v29289) {
  int v29290 = v29289->timer;
  int v29298 = v29290 + 1;
  v29289->timer = v29298;
  int * v29292 = v29289->regs;
  int v29293 = v29292[11];
  int v29294 = v29292[13];
  int v29303 = v29293 * v29294;
  v29292[8] = v29303;
  struct StateT * v29296 = slot_490(v29289);
  return v29296;
}

struct StateT * slot_67(struct StateT * v4668) {
  int * v4669 = v4668->saved_regs;
  int * v4670 = v4668->regs;
  int v4671 = v4670[29];
  v4669[29] = v4671;
  int v4673 = v4668->timer;
  int v4685 = v4673 + 1;
  v4668->timer = v4685;
  int * v4675 = v4668->regs;
  int v4676 = v4675[7];
  int v4677 = v4675[16];
  int v4689 = v4676 & v4677;
  v4675[29] = v4689;
  struct StateT * v4679 = slot_68(v4668);
  return v4679;
}

struct StateT * slot_591(struct StateT * v32075) {
  int v32076 = v32075->timer;
  int v32084 = v32076 + 1;
  v32075->timer = v32084;
  int * v32078 = v32075->regs;
  int v32079 = v32078[17];
  int v32080 = v32078[5];
  int v32088 = v32079 + v32080;
  v32078[17] = v32088;
  struct StateT * v32082 = slot_568(v32075);
  return v32082;
}

struct StateT * slot_989(struct StateT * v61827) {
  int v61828 = v61827->timer;
  int v61836 = v61828 + 1;
  v61827->timer = v61836;
  int * v61830 = v61827->regs;
  int v61831 = v61830[13];
  int v61832 = v61830[17];
  int v61841 = (((((int)((unsigned int)v61831 >> 16)) * ((int)((unsigned int)v61832 >> 16))) + ((int)((unsigned int)((v61831 & 65535) * ((int)((unsigned int)v61832 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v61831 >> 16)) * (v61832 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v61831 & 65535) * (v61832 & 65535)) >> 16)) + (((v61831 & 65535) * ((int)((unsigned int)v61832 >> 16))) & 65535)) + ((((int)((unsigned int)v61831 >> 16)) * (v61832 & 65535)) & 65535)) >> 16));
  v61830[5] = v61841;
  struct StateT * v61834 = slot_920(v61827);
  return v61834;
}

struct StateT * slot_81(struct StateT * v5993) {
  int v5994 = v5993->timer;
  int v6006 = v5994 + 1;
  v5993->timer = v6006;
  int * v5996 = v5993->regs;
  int v5997 = v5996[28];
  int v5998 = v5996[5];
  bool v6010 = (v5997 ^ -2147483648) < (v5998 ^ -2147483648);
  int v6001;
  if (v6010) {
    v6001 = 1;
  } else {
    v6001 = 0;
  }
  int * v6002 = v5993->regs;
  v6002[5] = v6001;
  struct StateT * v6004 = slot_83(v5993);
  return v6004;
}

struct StateT * slot_546(struct StateT * v31229) {
  int v31230 = v31229->timer;
  int v31238 = v31230 + 1;
  v31229->timer = v31238;
  int * v31232 = v31229->regs;
  int v31233 = v31232[29];
  int v31234 = v31232[7];
  int v31242 = v31233 + v31234;
  v31232[7] = v31242;
  struct StateT * v31236 = slot_585(v31229);
  return v31236;
}

struct StateT * slot_933(struct StateT * v57564) {
  int v57565 = v57564->timer;
  int v57572 = v57565 + 1;
  v57564->timer = v57572;
  int * v57567 = v57564->regs;
  int v57568 = v57567[17];
  int v57575 = (int)((unsigned int)v57568 >> 19);
  v57567[17] = v57575;
  struct StateT * v57570 = slot_827(v57564);
  return v57570;
}

struct StateT * slot_1033(struct StateT * v65975) {
  int v65976 = v65975->timer;
  int v65988 = v65976 + 1;
  v65975->timer = v65988;
  int * v65978 = v65975->regs;
  int v65979 = v65978[13];
  int v65980 = v65978[14];
  bool v65992 = (v65979 ^ -2147483648) < (v65980 ^ -2147483648);
  int v65983;
  if (v65992) {
    v65983 = 1;
  } else {
    v65983 = 0;
  }
  int * v65984 = v65975->regs;
  v65984[14] = v65983;
  struct StateT * v65986 = slot_1038(v65975);
  return v65986;
}

struct StateT * slot_32(struct StateT * v3822) {
  int v3823 = v3822->timer;
  int v3835 = v3823 + 1;
  v3822->timer = v3835;
  int * v3825 = v3822->regs;
  int v3826 = v3825[31];
  int v3827 = v3825[29];
  bool v3839 = (v3826 ^ -2147483648) < (v3827 ^ -2147483648);
  int v3830;
  if (v3839) {
    v3830 = 1;
  } else {
    v3830 = 0;
  }
  int * v3831 = v3822->regs;
  v3831[6] = v3830;
  struct StateT * v3833 = slot_33(v3822);
  return v3833;
}

struct StateT * slot_861(struct StateT * v47993) {
  int v47994 = v47993->timer;
  int v48002 = v47994 + 1;
  v47993->timer = v48002;
  int * v47996 = v47993->regs;
  int v47997 = v47996[17];
  int v47998 = v47996[16];
  int v48006 = v47997 & v47998;
  v47996[16] = v48006;
  struct StateT * v48000 = slot_933(v47993);
  return v48000;
}

struct StateT * slot_394(struct StateT * v26170) {
  int v26171 = v26170->timer;
  int v26178 = v26171 + 1;
  v26170->timer = v26178;
  int * v26173 = v26170->regs;
  int v26174 = v26173[28];
  int v26182 = (int)((unsigned int)v26174 >> 19);
  v26173[17] = v26182;
  struct StateT * v26176 = slot_365(v26170);
  return v26176;
}

struct StateT * slot_33(struct StateT * v4051) {
  int v4052 = v4051->timer;
  int v4060 = v4052 + 1;
  v4051->timer = v4060;
  int * v4054 = v4051->regs;
  int v4055 = v4054[30];
  int v4056 = v4054[5];
  int v4064 = v4055 + v4056;
  v4054[5] = v4064;
  struct StateT * v4058 = slot_34(v4051);
  return v4058;
}

struct StateT * slot_743(struct StateT * v34895) {
  int v34896 = v34895->timer;
  int v34904 = v34896 + 1;
  v34895->timer = v34904;
  int * v34898 = v34895->regs;
  int v34899 = v34898[12];
  int v34900 = v34898[17];
  int v34908 = v34899 * v34900;
  v34898[12] = v34908;
  struct StateT * v34902 = slot_782(v34895);
  return v34902;
}

struct StateT * slot_935(struct StateT * v57893) {
  int v57894 = v57893->timer;
  int v57902 = v57894 + 1;
  v57893->timer = v57902;
  int * v57896 = v57893->regs;
  int v57897 = v57896[17];
  int v57898 = v57896[13];
  int v57906 = v57897 | v57898;
  v57896[13] = v57906;
  struct StateT * v57900 = slot_895(v57893);
  return v57900;
}

struct StateT * slot_709(struct StateT * v34322) {
  int v34323 = v34322->timer;
  int v34329 = v34323 + 1;
  v34322->timer = v34329;
  int * v34325 = v34322->regs;
  v34325[17] = 19;
  struct StateT * v34327 = slot_745(v34322);
  return v34327;
}

struct StateT * slot_35(struct StateT * v4099) {
  int v4100 = v4099->timer;
  int v4107 = v4100 + 1;
  v4099->timer = v4107;
  int * v4102 = v4099->regs;
  int v4103 = v4102[31];
  int v4110 = v4103 << 13;
  v4102[31] = v4110;
  struct StateT * v4105 = slot_36(v4099);
  return v4105;
}

struct StateT * slot_258(struct StateT * v15785) {
  int v15786 = v15785->timer;
  int v15794 = v15786 + 1;
  v15785->timer = v15794;
  int * v15788 = v15785->regs;
  int v15789 = v15788[30];
  int v15790 = v15788[7];
  int v15798 = v15789 + v15790;
  v15788[7] = v15798;
  struct StateT * v15792 = slot_262(v15785);
  return v15792;
}

struct StateT * slot_744(struct StateT * v34911) {
  int * v34912 = v34911->saved_regs;
  int v34913 = v34912[17];
  int * v34914 = v34911->regs;
  int v34915 = v34914[6];
  bool v34956 = v34913 == v34915;
  struct StateT * v34950;
  if (v34956) {
    int v34916 = v34911->timer;
    int v34957 = v34916 + 15;
    v34911->timer = v34957;
    int * v34918 = v34911->saved_regs;
    int v34919 = v34918[5];
    int * v34920 = v34911->regs;
    v34920[5] = v34919;
    int * v34922 = v34911->saved_regs;
    int v34923 = v34922[16];
    int * v34924 = v34911->regs;
    v34924[16] = v34923;
    int * v34926 = v34911->saved_regs;
    int v34927 = v34926[17];
    int * v34928 = v34911->regs;
    v34928[17] = v34927;
    int * v34930 = v34911->saved_regs;
    int v34931 = v34930[12];
    int * v34932 = v34911->regs;
    v34932[12] = v34931;
    int * v34934 = v34911->saved_regs;
    int v34935 = v34934[13];
    int * v34936 = v34911->regs;
    v34936[13] = v34935;
    int * v34938 = v34911->saved_regs;
    int v34939 = v34938[15];
    int * v34940 = v34911->regs;
    v34940[15] = v34939;
    int * v34942 = v34911->saved_regs;
    int v34943 = v34942[14];
    int * v34944 = v34911->regs;
    v34944[14] = v34943;
    struct StateT * v34946 = slot_833(v34911);
    v34950 = v34946;
  } else {
    struct StateT * v34948 = slot_1060(v34911);
    v34950 = v34948;
  }
  return v34950;
}

struct StateT * slot_615(struct StateT * v32531) {
  int * v32532 = v32531->saved_regs;
  int * v32533 = v32531->regs;
  int v32534 = v32533[5];
  v32532[5] = v32534;
  int v32536 = v32531->timer;
  int v32552 = v32536 + 1;
  v32531->timer = v32552;
  int * v32538 = v32531->regs;
  int v32539 = v32538[17];
  int v32540 = v32538[6];
  bool v32556 = (v32539 ^ -2147483648) < (v32540 ^ -2147483648);
  int v32543;
  if (v32556) {
    v32543 = 1;
  } else {
    v32543 = 0;
  }
  int * v32544 = v32531->regs;
  v32544[5] = v32543;
  struct StateT * v32546 = slot_622(v32531);
  return v32546;
}

struct StateT * slot_51(struct StateT * v4366) {
  int v4367 = v4366->timer;
  int v4375 = v4367 + 1;
  v4366->timer = v4375;
  int * v4369 = v4366->regs;
  int v4370 = v4369[8];
  int v4371 = v4369[6];
  int v4380 = v4370 + v4371;
  v4369[29] = v4380;
  struct StateT * v4373 = slot_52(v4366);
  return v4373;
}

struct StateT * slot_25(struct StateT * v2455) {
  int v2456 = v2455->timer;
  int v2626 = v2456 + 1;
  v2455->timer = v2626;
  int * v2458 = v2455->regs;
  int v2459 = v2458[10];
  int v2460 = v2458[14];
  int * v2461 = v2455->cache_tags;
  int v2631 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2;
  int v2462 = v2461[v2631];
  int v2632 = ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2463 = v2461[v2632];
  int v2633 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2);
  int v2464 = v2461[v2633];
  int v2634 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2465 = v2461[v2634];
  int v2466 = v2455->timer;
  int v2635 = v2466 + ((100 ^ (((~(((v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2455->timer = v2635;
  bool v2636 = !(((~(((v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2462 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) == 0);
  int v2560;
  if (v2636) {
    int * v2468 = v2455->cache_age;
    int v2638 = ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((~(((v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2463 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) & 1);
    int v2469 = v2468[v2638];
    int v2470 = v2468[v2631];
    int v2639 = v2470 + ((int)((unsigned int)(v2470 - v2469) >> 31));
    v2468[v2631] = v2639;
    int * v2472 = v2455->cache_age;
    int v2473 = v2472[v2632];
    int v2641 = v2473 + ((int)((unsigned int)(v2473 - v2469) >> 31));
    v2472[v2632] = v2641;
    int * v2475 = v2455->cache_age;
    v2475[v2638] = 0;
    v2560 = v2638;
  } else {
    int * v2478 = v2455->cache_age;
    int v2645 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2;
    int v2479 = v2478[v2645];
    int * v2480 = v2455->cache_tags;
    int v2481 = v2480[v2645];
    int v2482 = v2478[v2632];
    int v2483 = v2480[v2632];
    bool v2647 = !(((~(((v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2464 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) == 0);
    int v2537;
    if (v2647) {
      int * v2484 = v2455->cache_age;
      int v2649 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2465 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) & 1);
      int v2485 = v2484[v2649];
      int v2486 = v2484[v2633];
      int v2650 = v2486 + ((int)((unsigned int)(v2486 - v2485) >> 31));
      v2484[v2633] = v2650;
      int * v2488 = v2455->cache_age;
      int v2489 = v2488[v2634];
      int v2652 = v2489 + ((int)((unsigned int)(v2489 - v2485) >> 31));
      v2488[v2634] = v2652;
      int * v2491 = v2455->cache_age;
      v2491[v2649] = 0;
      v2537 = v2649;
    } else {
      int * v2494 = v2455->cache_age;
      int v2656 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2);
      int v2495 = v2494[v2656];
      int * v2496 = v2455->cache_tags;
      int v2497 = v2496[v2656];
      int v2498 = v2494[v2634];
      int v2499 = v2496[v2634];
      int * v2500 = v2455->cache_dirty;
      int v2659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2501 = v2500[v2659];
      bool v2660 = !(v2501 == 0);
      if (v2660) {
        int * v2502 = v2455->cache_tags;
        int v2503 = v2502[v2659];
        int * v2504 = v2455->cache_vals;
        int v2663 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2505 = v2504[v2663];
        int v2664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2506 = v2504[v2664];
        int * v2507 = v2455->mem;
        int v2666 = v2503 * 2;
        v2507[v2666] = v2505;
        int * v2509 = v2455->mem;
        int v2669 = (v2503 * 2) + 1;
        v2509[v2669] = v2506;
        ;
      } else {
        ;
      }
      int * v2514 = v2455->mem;
      int v2674 = ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2;
      int v2515 = v2514[v2674];
      int v2675 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2) + 1;
      int v2516 = v2514[v2675];
      int * v2517 = v2455->cache_vals;
      int v2677 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2517[v2677] = v2515;
      int * v2519 = v2455->cache_vals;
      int v2680 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2495 + ((~(((v2497 ^ -1) | (-(v2497 ^ -1))) >> 31)) & 2)) - (v2498 + ((~(((v2499 ^ -1) | (-(v2499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2519[v2680] = v2516;
      int * v2521 = v2455->cache_tags;
      int v2683 = (int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1);
      v2521[v2659] = v2683;
      int * v2523 = v2455->cache_dirty;
      v2523[v2659] = 0;
      int * v2525 = v2455->cache_age;
      v2525[v2659] = 1;
      int * v2527 = v2455->cache_age;
      int v2528 = v2527[v2659];
      int v2529 = v2527[v2633];
      int v2689 = v2529 + ((int)((unsigned int)(v2529 - v2528) >> 31));
      v2527[v2633] = v2689;
      int * v2531 = v2455->cache_age;
      int v2532 = v2531[v2634];
      int v2691 = v2532 + ((int)((unsigned int)(v2532 - v2528) >> 31));
      v2531[v2634] = v2691;
      int * v2534 = v2455->cache_age;
      v2534[v2659] = 0;
      v2537 = v2659;
    }
    int * v2538 = v2455->cache_vals;
    int v2694 = v2537 * 2;
    int v2539 = v2538[v2694];
    int v2695 = (v2537 * 2) + 1;
    int v2540 = v2538[v2695];
    int v2696 = (((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((((v2479 + ((~(((v2481 ^ -1) | (-(v2481 ^ -1))) >> 31)) & 2)) - (v2482 + ((~(((v2483 ^ -1) | (-(v2483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2538[v2696] = v2539;
    int * v2542 = v2455->cache_vals;
    int v2699 = ((((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((((v2479 + ((~(((v2481 ^ -1) | (-(v2481 ^ -1))) >> 31)) & 2)) - (v2482 + ((~(((v2483 ^ -1) | (-(v2483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2542[v2699] = v2540;
    int * v2544 = v2455->cache_tags;
    int v2702 = ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 1) * 2) + ((((v2479 + ((~(((v2481 ^ -1) | (-(v2481 ^ -1))) >> 31)) & 2)) - (v2482 + ((~(((v2483 ^ -1) | (-(v2483 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2703 = (int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1);
    v2544[v2702] = v2703;
    int * v2546 = v2455->cache_dirty;
    v2546[v2702] = 0;
    int * v2548 = v2455->cache_age;
    v2548[v2702] = 1;
    int * v2550 = v2455->cache_age;
    int v2551 = v2550[v2702];
    int v2552 = v2550[v2631];
    int v2709 = v2552 + ((int)((unsigned int)(v2552 - v2551) >> 31));
    v2550[v2631] = v2709;
    int * v2554 = v2455->cache_age;
    int v2555 = v2554[v2632];
    int v2711 = v2555 + ((int)((unsigned int)(v2555 - v2551) >> 31));
    v2554[v2632] = v2711;
    int * v2557 = v2455->cache_age;
    v2557[v2702] = 0;
    v2560 = v2702;
  }
  int * v2561 = v2455->cache_vals;
  int v2714 = (v2560 * 2) + (((int)((unsigned int)v2459 >> 2)) & 1);
  v2561[v2714] = v2460;
  int * v2563 = v2455->cache_tags;
  int v2564 = v2563[v2633];
  int v2565 = v2563[v2634];
  bool v2717 = !(((~(((v2564 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2564 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) | (~(((v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31))) == 0);
  int v2619;
  if (v2717) {
    int * v2566 = v2455->cache_age;
    int v2719 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))) | (-(v2565 ^ ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1))))) >> 31)) & 1);
    int v2567 = v2566[v2719];
    int v2568 = v2566[v2633];
    int v2720 = v2568 + ((int)((unsigned int)(v2568 - v2567) >> 31));
    v2566[v2633] = v2720;
    int * v2570 = v2455->cache_age;
    int v2571 = v2570[v2634];
    int v2722 = v2571 + ((int)((unsigned int)(v2571 - v2567) >> 31));
    v2570[v2634] = v2722;
    int * v2573 = v2455->cache_age;
    v2573[v2719] = 0;
    v2619 = v2719;
  } else {
    int * v2576 = v2455->cache_age;
    int v2726 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2);
    int v2577 = v2576[v2726];
    int * v2578 = v2455->cache_tags;
    int v2579 = v2578[v2726];
    int v2580 = v2576[v2634];
    int v2581 = v2578[v2634];
    int * v2582 = v2455->cache_dirty;
    int v2729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2583 = v2582[v2729];
    bool v2730 = !(v2583 == 0);
    if (v2730) {
      int * v2584 = v2455->cache_tags;
      int v2585 = v2584[v2729];
      int * v2586 = v2455->cache_vals;
      int v2733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2587 = v2586[v2733];
      int v2734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2588 = v2586[v2734];
      int * v2589 = v2455->mem;
      int v2736 = v2585 * 2;
      v2589[v2736] = v2587;
      int * v2591 = v2455->mem;
      int v2739 = (v2585 * 2) + 1;
      v2591[v2739] = v2588;
      ;
    } else {
      ;
    }
    int * v2596 = v2455->mem;
    int v2744 = ((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2;
    int v2597 = v2596[v2744];
    int v2745 = (((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) * 2) + 1;
    int v2598 = v2596[v2745];
    int * v2599 = v2455->cache_vals;
    int v2747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2599[v2747] = v2597;
    int * v2601 = v2455->cache_vals;
    int v2750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1)) & 3) * 2)) + ((((v2577 + ((~(((v2579 ^ -1) | (-(v2579 ^ -1))) >> 31)) & 2)) - (v2580 + ((~(((v2581 ^ -1) | (-(v2581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2601[v2750] = v2598;
    int * v2603 = v2455->cache_tags;
    int v2753 = (int)((unsigned int)((int)((unsigned int)v2459 >> 2)) >> 1);
    v2603[v2729] = v2753;
    int * v2605 = v2455->cache_dirty;
    v2605[v2729] = 0;
    int * v2607 = v2455->cache_age;
    v2607[v2729] = 1;
    int * v2609 = v2455->cache_age;
    int v2610 = v2609[v2729];
    int v2611 = v2609[v2633];
    int v2759 = v2611 + ((int)((unsigned int)(v2611 - v2610) >> 31));
    v2609[v2633] = v2759;
    int * v2613 = v2455->cache_age;
    int v2614 = v2613[v2634];
    int v2761 = v2614 + ((int)((unsigned int)(v2614 - v2610) >> 31));
    v2613[v2634] = v2761;
    int * v2616 = v2455->cache_age;
    v2616[v2729] = 0;
    v2619 = v2729;
  }
  int * v2620 = v2455->cache_vals;
  int v2764 = (v2619 * 2) + (((int)((unsigned int)v2459 >> 2)) & 1);
  v2620[v2764] = v2460;
  int * v2622 = v2455->cache_dirty;
  v2622[v2619] = 1;
  struct StateT * v2624 = slot_26(v2455);
  return v2624;
}

struct StateT * slot_991(struct StateT * v61860) {
  int v61861 = v61860->timer;
  int v61869 = v61861 + 1;
  v61860->timer = v61869;
  int * v61863 = v61860->regs;
  int v61864 = v61863[12];
  int v61865 = v61863[17];
  int v61873 = v61864 * v61865;
  v61863[12] = v61873;
  struct StateT * v61867 = slot_1033(v61860);
  return v61867;
}

struct StateT * slot_490(struct StateT * v30157) {
  int v30158 = v30157->timer;
  int v30166 = v30158 + 1;
  v30157->timer = v30166;
  int * v30160 = v30157->regs;
  int v30161 = v30160[11];
  int v30162 = v30160[13];
  int v30170 = (((((int)((unsigned int)v30161 >> 16)) * ((int)((unsigned int)v30162 >> 16))) + ((int)((unsigned int)((v30161 & 65535) * ((int)((unsigned int)v30162 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v30161 >> 16)) * (v30162 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v30161 & 65535) * (v30162 & 65535)) >> 16)) + (((v30161 & 65535) * ((int)((unsigned int)v30162 >> 16))) & 65535)) + ((((int)((unsigned int)v30161 >> 16)) * (v30162 & 65535)) & 65535)) >> 16));
  v30160[13] = v30170;
  struct StateT * v30164 = slot_501(v30157);
  return v30164;
}

struct StateT * slot_123(struct StateT * v8230) {
  int v8231 = v8230->timer;
  int v8243 = v8231 + 1;
  v8230->timer = v8243;
  int * v8233 = v8230->regs;
  int v8234 = v8233[17];
  int v8235 = v8233[6];
  bool v8247 = (v8234 ^ -2147483648) < (v8235 ^ -2147483648);
  int v8238;
  if (v8247) {
    v8238 = 1;
  } else {
    v8238 = 0;
  }
  int * v8239 = v8230->regs;
  v8239[28] = v8238;
  struct StateT * v8241 = slot_118(v8230);
  return v8241;
}

struct StateT * slot_982(struct StateT * v61512) {
  int v61513 = v61512->timer;
  int v61521 = v61513 + 1;
  v61512->timer = v61521;
  int * v61515 = v61512->regs;
  int v61516 = v61515[14];
  int v61517 = v61515[13];
  int v61525 = v61516 + v61517;
  v61515[13] = v61525;
  struct StateT * v61519 = slot_991(v61512);
  return v61519;
}

struct StateT * slot_958(struct StateT * v61573) {
  int v61574 = v61573->timer;
  int v61684 = v61574 + 1;
  v61573->timer = v61684;
  int * v61576 = v61573->regs;
  int v61577 = v61576[2];
  int * v61578 = v61573->cache_tags;
  int v61688 = (((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2;
  int v61579 = v61578[v61688];
  int v61689 = ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2) + 1;
  int v61580 = v61578[v61689];
  int v61690 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2);
  int v61581 = v61578[v61690];
  int v61691 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v61582 = v61578[v61691];
  int v61583 = v61573->timer;
  int v61692 = v61583 + ((100 ^ (((~(((v61581 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61581 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) | (~(((v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v61579 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61579 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) | (~(((v61580 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61580 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v61581 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61581 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) | (~(((v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31))) & 104)))));
  v61573->timer = v61692;
  int * v61585 = v61573->cache_vals;
  bool v61693 = !(((~(((v61579 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61579 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) | (~(((v61580 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61580 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31))) == 0);
  int v61678;
  if (v61693) {
    int * v61586 = v61573->cache_age;
    int v61695 = ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2) + ((~(((v61580 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61580 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) & 1);
    int v61587 = v61586[v61695];
    int v61588 = v61586[v61688];
    int v61696 = v61588 + ((int)((unsigned int)(v61588 - v61587) >> 31));
    v61586[v61688] = v61696;
    int * v61590 = v61573->cache_age;
    int v61591 = v61590[v61689];
    int v61698 = v61591 + ((int)((unsigned int)(v61591 - v61587) >> 31));
    v61590[v61689] = v61698;
    int * v61593 = v61573->cache_age;
    v61593[v61695] = 0;
    v61678 = v61695;
  } else {
    int * v61596 = v61573->cache_age;
    int v61702 = (((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2;
    int v61597 = v61596[v61702];
    int * v61598 = v61573->cache_tags;
    int v61599 = v61598[v61702];
    int v61600 = v61596[v61689];
    int v61601 = v61598[v61689];
    bool v61704 = !(((~(((v61581 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61581 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) | (~(((v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31))) == 0);
    int v61655;
    if (v61704) {
      int * v61602 = v61573->cache_age;
      int v61706 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + ((~(((v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))) | (-(v61582 ^ ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1))))) >> 31)) & 1);
      int v61603 = v61602[v61706];
      int v61604 = v61602[v61690];
      int v61707 = v61604 + ((int)((unsigned int)(v61604 - v61603) >> 31));
      v61602[v61690] = v61707;
      int * v61606 = v61573->cache_age;
      int v61607 = v61606[v61691];
      int v61709 = v61607 + ((int)((unsigned int)(v61607 - v61603) >> 31));
      v61606[v61691] = v61709;
      int * v61609 = v61573->cache_age;
      v61609[v61706] = 0;
      v61655 = v61706;
    } else {
      int * v61612 = v61573->cache_age;
      int v61713 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2);
      int v61613 = v61612[v61713];
      int * v61614 = v61573->cache_tags;
      int v61615 = v61614[v61713];
      int v61616 = v61612[v61691];
      int v61617 = v61614[v61691];
      int * v61618 = v61573->cache_dirty;
      int v61716 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + ((((v61613 + ((~(((v61615 ^ -1) | (-(v61615 ^ -1))) >> 31)) & 2)) - (v61616 + ((~(((v61617 ^ -1) | (-(v61617 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61619 = v61618[v61716];
      bool v61717 = !(v61619 == 0);
      if (v61717) {
        int * v61620 = v61573->cache_tags;
        int v61621 = v61620[v61716];
        int * v61622 = v61573->cache_vals;
        int v61720 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + ((((v61613 + ((~(((v61615 ^ -1) | (-(v61615 ^ -1))) >> 31)) & 2)) - (v61616 + ((~(((v61617 ^ -1) | (-(v61617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v61623 = v61622[v61720];
        int v61721 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + ((((v61613 + ((~(((v61615 ^ -1) | (-(v61615 ^ -1))) >> 31)) & 2)) - (v61616 + ((~(((v61617 ^ -1) | (-(v61617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v61624 = v61622[v61721];
        int * v61625 = v61573->mem;
        int v61723 = v61621 * 2;
        v61625[v61723] = v61623;
        int * v61627 = v61573->mem;
        int v61726 = (v61621 * 2) + 1;
        v61627[v61726] = v61624;
        ;
      } else {
        ;
      }
      int * v61632 = v61573->mem;
      int v61731 = ((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) * 2;
      int v61633 = v61632[v61731];
      int v61732 = (((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) * 2) + 1;
      int v61634 = v61632[v61732];
      int * v61635 = v61573->cache_vals;
      int v61734 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + ((((v61613 + ((~(((v61615 ^ -1) | (-(v61615 ^ -1))) >> 31)) & 2)) - (v61616 + ((~(((v61617 ^ -1) | (-(v61617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v61635[v61734] = v61633;
      int * v61637 = v61573->cache_vals;
      int v61737 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 3) * 2)) + ((((v61613 + ((~(((v61615 ^ -1) | (-(v61615 ^ -1))) >> 31)) & 2)) - (v61616 + ((~(((v61617 ^ -1) | (-(v61617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v61637[v61737] = v61634;
      int * v61639 = v61573->cache_tags;
      int v61740 = (int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1);
      v61639[v61716] = v61740;
      int * v61641 = v61573->cache_dirty;
      v61641[v61716] = 0;
      int * v61643 = v61573->cache_age;
      v61643[v61716] = 1;
      int * v61645 = v61573->cache_age;
      int v61646 = v61645[v61716];
      int v61647 = v61645[v61690];
      int v61746 = v61647 + ((int)((unsigned int)(v61647 - v61646) >> 31));
      v61645[v61690] = v61746;
      int * v61649 = v61573->cache_age;
      int v61650 = v61649[v61691];
      int v61748 = v61650 + ((int)((unsigned int)(v61650 - v61646) >> 31));
      v61649[v61691] = v61748;
      int * v61652 = v61573->cache_age;
      v61652[v61716] = 0;
      v61655 = v61716;
    }
    int * v61656 = v61573->cache_vals;
    int v61751 = v61655 * 2;
    int v61657 = v61656[v61751];
    int v61752 = (v61655 * 2) + 1;
    int v61658 = v61656[v61752];
    int v61753 = (((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2) + ((((v61597 + ((~(((v61599 ^ -1) | (-(v61599 ^ -1))) >> 31)) & 2)) - (v61600 + ((~(((v61601 ^ -1) | (-(v61601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v61656[v61753] = v61657;
    int * v61660 = v61573->cache_vals;
    int v61756 = ((((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2) + ((((v61597 + ((~(((v61599 ^ -1) | (-(v61599 ^ -1))) >> 31)) & 2)) - (v61600 + ((~(((v61601 ^ -1) | (-(v61601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v61660[v61756] = v61658;
    int * v61662 = v61573->cache_tags;
    int v61759 = ((((int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1)) & 1) * 2) + ((((v61597 + ((~(((v61599 ^ -1) | (-(v61599 ^ -1))) >> 31)) & 2)) - (v61600 + ((~(((v61601 ^ -1) | (-(v61601 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v61760 = (int)((unsigned int)((int)((unsigned int)v61577 >> 2)) >> 1);
    v61662[v61759] = v61760;
    int * v61664 = v61573->cache_dirty;
    v61664[v61759] = 0;
    int * v61666 = v61573->cache_age;
    v61666[v61759] = 1;
    int * v61668 = v61573->cache_age;
    int v61669 = v61668[v61759];
    int v61670 = v61668[v61688];
    int v61766 = v61670 + ((int)((unsigned int)(v61670 - v61669) >> 31));
    v61668[v61688] = v61766;
    int * v61672 = v61573->cache_age;
    int v61673 = v61672[v61689];
    int v61768 = v61673 + ((int)((unsigned int)(v61673 - v61669) >> 31));
    v61672[v61689] = v61768;
    int * v61675 = v61573->cache_age;
    v61675[v61759] = 0;
    v61678 = v61759;
  }
  int v61771 = (v61678 * 2) + (((int)((unsigned int)v61577 >> 2)) & 1);
  int v61679 = v61585[v61771];
  int * v61680 = v61573->regs;
  v61680[19] = v61679;
  struct StateT * v61682 = slot_850(v61573);
  return v61682;
}

struct StateT * slot_799(struct StateT * v39271) {
  int v39272 = v39271->timer;
  int v39280 = v39272 + 1;
  v39271->timer = v39280;
  int * v39274 = v39271->regs;
  int v39275 = v39274[15];
  int v39276 = v39274[12];
  int v39284 = v39275 + v39276;
  v39274[12] = v39284;
  struct StateT * v39278 = slot_810(v39271);
  return v39278;
}

struct StateT * slot_299(struct StateT * v16563) {
  int v16564 = v16563->timer;
  int v16572 = v16564 + 1;
  v16563->timer = v16572;
  int * v16566 = v16563->regs;
  int v16567 = v16566[6];
  int v16568 = v16566[31];
  int v16576 = v16567 + v16568;
  v16566[6] = v16576;
  struct StateT * v16570 = slot_288(v16563);
  return v16570;
}

struct StateT * slot_539(struct StateT * v31089) {
  int v31090 = v31089->timer;
  int v31102 = v31090 + 1;
  v31089->timer = v31102;
  int * v31092 = v31089->regs;
  int v31093 = v31092[11];
  int v31094 = v31092[12];
  bool v31106 = (v31093 ^ -2147483648) < (v31094 ^ -2147483648);
  int v31097;
  if (v31106) {
    v31097 = 1;
  } else {
    v31097 = 0;
  }
  int * v31098 = v31089->regs;
  v31098[5] = v31097;
  struct StateT * v31100 = slot_546(v31089);
  return v31100;
}

struct StateT * slot_671(struct StateT * v33626) {
  int v33627 = v33626->timer;
  int v33635 = v33627 + 1;
  v33626->timer = v33635;
  int * v33629 = v33626->regs;
  int v33630 = v33629[17];
  int v33631 = v33629[13];
  int v33639 = v33630 | v33631;
  v33629[13] = v33639;
  struct StateT * v33633 = slot_709(v33626);
  return v33633;
}

struct StateT * slot_929(struct StateT * v57515) {
  int v57516 = v57515->timer;
  int v57519 = v57516 + 1;
  v57515->timer = v57519;
  return v57515;
}

struct StateT * slot_240(struct StateT * v15436) {
  int v15437 = v15436->timer;
  int v15449 = v15437 + 1;
  v15436->timer = v15449;
  int * v15439 = v15436->regs;
  int v15440 = v15439[17];
  int v15441 = v15439[6];
  bool v15453 = (v15440 ^ -2147483648) < (v15441 ^ -2147483648);
  int v15444;
  if (v15453) {
    v15444 = 1;
  } else {
    v15444 = 0;
  }
  int * v15445 = v15436->regs;
  v15445[28] = v15444;
  struct StateT * v15447 = slot_258(v15436);
  return v15447;
}

struct StateT * slot_548(struct StateT * v31261) {
  int v31262 = v31261->timer;
  int v31270 = v31262 + 1;
  v31261->timer = v31270;
  int * v31264 = v31261->regs;
  int v31265 = v31264[7];
  int v31266 = v31264[12];
  int v31275 = v31265 + v31266;
  v31264[28] = v31275;
  struct StateT * v31268 = slot_586(v31261);
  return v31268;
}

struct StateT * slot_70(struct StateT * v4744) {
  int * v4745 = v4744->saved_regs;
  int v4746 = v4745[7];
  int v4747 = v4745[29];
  bool v4775 = v4746 == v4747;
  struct StateT * v4770;
  if (v4775) {
    int v4748 = v4744->timer;
    int v4776 = v4748 + 15;
    v4744->timer = v4776;
    int * v4750 = v4744->saved_regs;
    int v4751 = v4750[28];
    int * v4752 = v4744->regs;
    v4752[28] = v4751;
    int * v4754 = v4744->saved_regs;
    int v4755 = v4754[29];
    int * v4756 = v4744->regs;
    v4756[29] = v4755;
    int * v4758 = v4744->saved_regs;
    int v4759 = v4758[7];
    int * v4760 = v4744->regs;
    v4760[7] = v4759;
    int * v4762 = v4744->saved_regs;
    int v4763 = v4762[5];
    int * v4764 = v4744->regs;
    v4764[5] = v4763;
    struct StateT * v4766 = slot_71(v4744);
    v4770 = v4766;
  } else {
    struct StateT * v4768 = slot_83(v4744);
    v4770 = v4768;
  }
  return v4770;
}

struct StateT * slot_348(struct StateT * v20157) {
  int v20158 = v20157->timer;
  int v20494 = v20158 + 1;
  v20157->timer = v20494;
  int * v20160 = v20157->regs;
  int v20161 = v20160[10];
  int v20162 = v20160[29];
  int * v20163 = v20157->saved_regs;
  int v20164 = v20160[17];
  v20163[17] = v20164;
  int v20166 = v20157->timer;
  int v20501 = v20166 + 1;
  v20157->timer = v20501;
  int * v20168 = v20157->regs;
  int v20169 = v20168[28];
  int v20504 = (int)((unsigned int)v20169 >> 19);
  v20168[17] = v20504;
  int * v20171 = v20157->saved_regs;
  int * v20172 = v20157->regs;
  int v20173 = v20172[28];
  v20171[28] = v20173;
  int v20175 = v20157->timer;
  int v20508 = v20175 + 1;
  v20157->timer = v20508;
  int * v20177 = v20157->regs;
  int v20178 = v20177[28];
  int v20510 = v20178 << 13;
  v20177[28] = v20510;
  int * v20180 = v20157->saved_regs;
  int * v20181 = v20157->regs;
  int v20182 = v20181[5];
  v20180[5] = v20182;
  int v20184 = v20157->timer;
  int v20515 = v20184 + 1;
  v20157->timer = v20515;
  int * v20186 = v20157->regs;
  int v20187 = v20186[6];
  int v20188 = v20186[5];
  int v20518 = v20187 + v20188;
  v20186[5] = v20518;
  int * v20190 = v20157->saved_regs;
  int * v20191 = v20157->regs;
  int v20192 = v20191[6];
  v20190[6] = v20192;
  int v20194 = v20157->timer;
  int v20522 = v20194 + 1;
  v20157->timer = v20522;
  int * v20196 = v20157->regs;
  int v20197 = v20196[11];
  bool v20525 = (((int)((unsigned int)(v20161 + 28) >> 2)) & 3) == (((int)((unsigned int)(v20197 + 32) >> 2)) & 3);
  int v20304;
  if (v20525) {
    int v20198 = v20157->timer;
    int v20526 = v20198 + 1;
    v20157->timer = v20526;
    v20304 = v20162;
  } else {
    int * v20201 = v20157->cache_tags;
    int v20529 = (((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2;
    int v20202 = v20201[v20529];
    int v20530 = ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
    int v20203 = v20201[v20530];
    int v20531 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2);
    int v20204 = v20201[v20531];
    int v20532 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v20205 = v20201[v20532];
    int v20206 = v20157->timer;
    int v20533 = v20206 + ((100 ^ (((~(((v20204 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20204 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20202 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20202 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v20203 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20203 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v20204 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20204 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
    v20157->timer = v20533;
    int * v20208 = v20157->cache_vals;
    bool v20534 = !(((~(((v20202 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20202 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v20203 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20203 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v20301;
    if (v20534) {
      int * v20209 = v20157->cache_age;
      int v20536 = ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v20203 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20203 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v20210 = v20209[v20536];
      int v20211 = v20209[v20529];
      int v20537 = v20211 + ((int)((unsigned int)(v20211 - v20210) >> 31));
      v20209[v20529] = v20537;
      int * v20213 = v20157->cache_age;
      int v20214 = v20213[v20530];
      int v20539 = v20214 + ((int)((unsigned int)(v20214 - v20210) >> 31));
      v20213[v20530] = v20539;
      int * v20216 = v20157->cache_age;
      v20216[v20536] = 0;
      v20301 = v20536;
    } else {
      int * v20219 = v20157->cache_age;
      int v20543 = (((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2;
      int v20220 = v20219[v20543];
      int * v20221 = v20157->cache_tags;
      int v20222 = v20221[v20543];
      int v20223 = v20219[v20530];
      int v20224 = v20221[v20530];
      bool v20545 = !(((~(((v20204 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20204 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31))) == 0);
      int v20278;
      if (v20545) {
        int * v20225 = v20157->cache_age;
        int v20547 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))) | (-(v20205 ^ ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1))))) >> 31)) & 1);
        int v20226 = v20225[v20547];
        int v20227 = v20225[v20531];
        int v20548 = v20227 + ((int)((unsigned int)(v20227 - v20226) >> 31));
        v20225[v20531] = v20548;
        int * v20229 = v20157->cache_age;
        int v20230 = v20229[v20532];
        int v20550 = v20230 + ((int)((unsigned int)(v20230 - v20226) >> 31));
        v20229[v20532] = v20550;
        int * v20232 = v20157->cache_age;
        v20232[v20547] = 0;
        v20278 = v20547;
      } else {
        int * v20235 = v20157->cache_age;
        int v20554 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2);
        int v20236 = v20235[v20554];
        int * v20237 = v20157->cache_tags;
        int v20238 = v20237[v20554];
        int v20239 = v20235[v20532];
        int v20240 = v20237[v20532];
        int * v20241 = v20157->cache_dirty;
        int v20557 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v20236 + ((~(((v20238 ^ -1) | (-(v20238 ^ -1))) >> 31)) & 2)) - (v20239 + ((~(((v20240 ^ -1) | (-(v20240 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v20242 = v20241[v20557];
        bool v20558 = !(v20242 == 0);
        if (v20558) {
          int * v20243 = v20157->cache_tags;
          int v20244 = v20243[v20557];
          int * v20245 = v20157->cache_vals;
          int v20561 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v20236 + ((~(((v20238 ^ -1) | (-(v20238 ^ -1))) >> 31)) & 2)) - (v20239 + ((~(((v20240 ^ -1) | (-(v20240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v20246 = v20245[v20561];
          int v20562 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v20236 + ((~(((v20238 ^ -1) | (-(v20238 ^ -1))) >> 31)) & 2)) - (v20239 + ((~(((v20240 ^ -1) | (-(v20240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v20247 = v20245[v20562];
          int * v20248 = v20157->mem;
          int v20564 = v20244 * 2;
          v20248[v20564] = v20246;
          int * v20250 = v20157->mem;
          int v20567 = (v20244 * 2) + 1;
          v20250[v20567] = v20247;
          ;
        } else {
          ;
        }
        int * v20255 = v20157->mem;
        int v20572 = ((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) * 2;
        int v20256 = v20255[v20572];
        int v20573 = (((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) * 2) + 1;
        int v20257 = v20255[v20573];
        int * v20258 = v20157->cache_vals;
        int v20575 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v20236 + ((~(((v20238 ^ -1) | (-(v20238 ^ -1))) >> 31)) & 2)) - (v20239 + ((~(((v20240 ^ -1) | (-(v20240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v20258[v20575] = v20256;
        int * v20260 = v20157->cache_vals;
        int v20578 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v20236 + ((~(((v20238 ^ -1) | (-(v20238 ^ -1))) >> 31)) & 2)) - (v20239 + ((~(((v20240 ^ -1) | (-(v20240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v20260[v20578] = v20257;
        int * v20262 = v20157->cache_tags;
        int v20581 = (int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1);
        v20262[v20557] = v20581;
        int * v20264 = v20157->cache_dirty;
        v20264[v20557] = 0;
        int * v20266 = v20157->cache_age;
        v20266[v20557] = 1;
        int * v20268 = v20157->cache_age;
        int v20269 = v20268[v20557];
        int v20270 = v20268[v20531];
        int v20587 = v20270 + ((int)((unsigned int)(v20270 - v20269) >> 31));
        v20268[v20531] = v20587;
        int * v20272 = v20157->cache_age;
        int v20273 = v20272[v20532];
        int v20589 = v20273 + ((int)((unsigned int)(v20273 - v20269) >> 31));
        v20272[v20532] = v20589;
        int * v20275 = v20157->cache_age;
        v20275[v20557] = 0;
        v20278 = v20557;
      }
      int * v20279 = v20157->cache_vals;
      int v20592 = v20278 * 2;
      int v20280 = v20279[v20592];
      int v20593 = (v20278 * 2) + 1;
      int v20281 = v20279[v20593];
      int v20594 = (((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v20220 + ((~(((v20222 ^ -1) | (-(v20222 ^ -1))) >> 31)) & 2)) - (v20223 + ((~(((v20224 ^ -1) | (-(v20224 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v20279[v20594] = v20280;
      int * v20283 = v20157->cache_vals;
      int v20597 = ((((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v20220 + ((~(((v20222 ^ -1) | (-(v20222 ^ -1))) >> 31)) & 2)) - (v20223 + ((~(((v20224 ^ -1) | (-(v20224 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v20283[v20597] = v20281;
      int * v20285 = v20157->cache_tags;
      int v20600 = ((((int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v20220 + ((~(((v20222 ^ -1) | (-(v20222 ^ -1))) >> 31)) & 2)) - (v20223 + ((~(((v20224 ^ -1) | (-(v20224 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v20601 = (int)((unsigned int)((int)((unsigned int)(v20197 + 32) >> 2)) >> 1);
      v20285[v20600] = v20601;
      int * v20287 = v20157->cache_dirty;
      v20287[v20600] = 0;
      int * v20289 = v20157->cache_age;
      v20289[v20600] = 1;
      int * v20291 = v20157->cache_age;
      int v20292 = v20291[v20600];
      int v20293 = v20291[v20529];
      int v20607 = v20293 + ((int)((unsigned int)(v20293 - v20292) >> 31));
      v20291[v20529] = v20607;
      int * v20295 = v20157->cache_age;
      int v20296 = v20295[v20530];
      int v20609 = v20296 + ((int)((unsigned int)(v20296 - v20292) >> 31));
      v20295[v20530] = v20609;
      int * v20298 = v20157->cache_age;
      v20298[v20600] = 0;
      v20301 = v20600;
    }
    int v20612 = (v20301 * 2) + (((int)((unsigned int)(v20197 + 32) >> 2)) & 1);
    int v20302 = v20208[v20612];
    v20304 = v20302;
  }
  int * v20305 = v20157->regs;
  v20305[6] = v20304;
  int * v20307 = v20157->cache_tags;
  int v20617 = (((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2;
  int v20308 = v20307[v20617];
  int v20618 = ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v20309 = v20307[v20618];
  int v20619 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2);
  int v20310 = v20307[v20619];
  int v20620 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v20311 = v20307[v20620];
  int v20312 = v20157->timer;
  int v20621 = v20312 + ((100 ^ (((~(((v20310 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20310 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v20308 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20308 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v20309 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20309 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v20310 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20310 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v20157->timer = v20621;
  bool v20622 = !(((~(((v20308 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20308 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v20309 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20309 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v20406;
  if (v20622) {
    int * v20314 = v20157->cache_age;
    int v20624 = ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v20309 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20309 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v20315 = v20314[v20624];
    int v20316 = v20314[v20617];
    int v20625 = v20316 + ((int)((unsigned int)(v20316 - v20315) >> 31));
    v20314[v20617] = v20625;
    int * v20318 = v20157->cache_age;
    int v20319 = v20318[v20618];
    int v20627 = v20319 + ((int)((unsigned int)(v20319 - v20315) >> 31));
    v20318[v20618] = v20627;
    int * v20321 = v20157->cache_age;
    v20321[v20624] = 0;
    v20406 = v20624;
  } else {
    int * v20324 = v20157->cache_age;
    int v20631 = (((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2;
    int v20325 = v20324[v20631];
    int * v20326 = v20157->cache_tags;
    int v20327 = v20326[v20631];
    int v20328 = v20324[v20618];
    int v20329 = v20326[v20618];
    bool v20633 = !(((~(((v20310 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20310 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v20383;
    if (v20633) {
      int * v20330 = v20157->cache_age;
      int v20635 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20311 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v20331 = v20330[v20635];
      int v20332 = v20330[v20619];
      int v20636 = v20332 + ((int)((unsigned int)(v20332 - v20331) >> 31));
      v20330[v20619] = v20636;
      int * v20334 = v20157->cache_age;
      int v20335 = v20334[v20620];
      int v20638 = v20335 + ((int)((unsigned int)(v20335 - v20331) >> 31));
      v20334[v20620] = v20638;
      int * v20337 = v20157->cache_age;
      v20337[v20635] = 0;
      v20383 = v20635;
    } else {
      int * v20340 = v20157->cache_age;
      int v20642 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2);
      int v20341 = v20340[v20642];
      int * v20342 = v20157->cache_tags;
      int v20343 = v20342[v20642];
      int v20344 = v20340[v20620];
      int v20345 = v20342[v20620];
      int * v20346 = v20157->cache_dirty;
      int v20645 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20341 + ((~(((v20343 ^ -1) | (-(v20343 ^ -1))) >> 31)) & 2)) - (v20344 + ((~(((v20345 ^ -1) | (-(v20345 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v20347 = v20346[v20645];
      bool v20646 = !(v20347 == 0);
      if (v20646) {
        int * v20348 = v20157->cache_tags;
        int v20349 = v20348[v20645];
        int * v20350 = v20157->cache_vals;
        int v20649 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20341 + ((~(((v20343 ^ -1) | (-(v20343 ^ -1))) >> 31)) & 2)) - (v20344 + ((~(((v20345 ^ -1) | (-(v20345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v20351 = v20350[v20649];
        int v20650 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20341 + ((~(((v20343 ^ -1) | (-(v20343 ^ -1))) >> 31)) & 2)) - (v20344 + ((~(((v20345 ^ -1) | (-(v20345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v20352 = v20350[v20650];
        int * v20353 = v20157->mem;
        int v20652 = v20349 * 2;
        v20353[v20652] = v20351;
        int * v20355 = v20157->mem;
        int v20655 = (v20349 * 2) + 1;
        v20355[v20655] = v20352;
        ;
      } else {
        ;
      }
      int * v20360 = v20157->mem;
      int v20660 = ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) * 2;
      int v20361 = v20360[v20660];
      int v20661 = (((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) * 2) + 1;
      int v20362 = v20360[v20661];
      int * v20363 = v20157->cache_vals;
      int v20663 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20341 + ((~(((v20343 ^ -1) | (-(v20343 ^ -1))) >> 31)) & 2)) - (v20344 + ((~(((v20345 ^ -1) | (-(v20345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v20363[v20663] = v20361;
      int * v20365 = v20157->cache_vals;
      int v20666 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20341 + ((~(((v20343 ^ -1) | (-(v20343 ^ -1))) >> 31)) & 2)) - (v20344 + ((~(((v20345 ^ -1) | (-(v20345 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v20365[v20666] = v20362;
      int * v20367 = v20157->cache_tags;
      int v20669 = (int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1);
      v20367[v20645] = v20669;
      int * v20369 = v20157->cache_dirty;
      v20369[v20645] = 0;
      int * v20371 = v20157->cache_age;
      v20371[v20645] = 1;
      int * v20373 = v20157->cache_age;
      int v20374 = v20373[v20645];
      int v20375 = v20373[v20619];
      int v20675 = v20375 + ((int)((unsigned int)(v20375 - v20374) >> 31));
      v20373[v20619] = v20675;
      int * v20377 = v20157->cache_age;
      int v20378 = v20377[v20620];
      int v20677 = v20378 + ((int)((unsigned int)(v20378 - v20374) >> 31));
      v20377[v20620] = v20677;
      int * v20380 = v20157->cache_age;
      v20380[v20645] = 0;
      v20383 = v20645;
    }
    int * v20384 = v20157->cache_vals;
    int v20680 = v20383 * 2;
    int v20385 = v20384[v20680];
    int v20681 = (v20383 * 2) + 1;
    int v20386 = v20384[v20681];
    int v20682 = (((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v20325 + ((~(((v20327 ^ -1) | (-(v20327 ^ -1))) >> 31)) & 2)) - (v20328 + ((~(((v20329 ^ -1) | (-(v20329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v20384[v20682] = v20385;
    int * v20388 = v20157->cache_vals;
    int v20685 = ((((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v20325 + ((~(((v20327 ^ -1) | (-(v20327 ^ -1))) >> 31)) & 2)) - (v20328 + ((~(((v20329 ^ -1) | (-(v20329 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v20388[v20685] = v20386;
    int * v20390 = v20157->cache_tags;
    int v20688 = ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v20325 + ((~(((v20327 ^ -1) | (-(v20327 ^ -1))) >> 31)) & 2)) - (v20328 + ((~(((v20329 ^ -1) | (-(v20329 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v20689 = (int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1);
    v20390[v20688] = v20689;
    int * v20392 = v20157->cache_dirty;
    v20392[v20688] = 0;
    int * v20394 = v20157->cache_age;
    v20394[v20688] = 1;
    int * v20396 = v20157->cache_age;
    int v20397 = v20396[v20688];
    int v20398 = v20396[v20617];
    int v20695 = v20398 + ((int)((unsigned int)(v20398 - v20397) >> 31));
    v20396[v20617] = v20695;
    int * v20400 = v20157->cache_age;
    int v20401 = v20400[v20618];
    int v20697 = v20401 + ((int)((unsigned int)(v20401 - v20397) >> 31));
    v20400[v20618] = v20697;
    int * v20403 = v20157->cache_age;
    v20403[v20688] = 0;
    v20406 = v20688;
  }
  int * v20407 = v20157->cache_vals;
  int v20700 = (v20406 * 2) + (((int)((unsigned int)(v20161 + 28) >> 2)) & 1);
  v20407[v20700] = v20162;
  int * v20409 = v20157->cache_tags;
  int v20410 = v20409[v20619];
  int v20411 = v20409[v20620];
  bool v20703 = !(((~(((v20410 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20410 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v20411 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20411 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v20465;
  if (v20703) {
    int * v20412 = v20157->cache_age;
    int v20705 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v20411 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))) | (-(v20411 ^ ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v20413 = v20412[v20705];
    int v20414 = v20412[v20619];
    int v20706 = v20414 + ((int)((unsigned int)(v20414 - v20413) >> 31));
    v20412[v20619] = v20706;
    int * v20416 = v20157->cache_age;
    int v20417 = v20416[v20620];
    int v20708 = v20417 + ((int)((unsigned int)(v20417 - v20413) >> 31));
    v20416[v20620] = v20708;
    int * v20419 = v20157->cache_age;
    v20419[v20705] = 0;
    v20465 = v20705;
  } else {
    int * v20422 = v20157->cache_age;
    int v20712 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2);
    int v20423 = v20422[v20712];
    int * v20424 = v20157->cache_tags;
    int v20425 = v20424[v20712];
    int v20426 = v20422[v20620];
    int v20427 = v20424[v20620];
    int * v20428 = v20157->cache_dirty;
    int v20715 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20423 + ((~(((v20425 ^ -1) | (-(v20425 ^ -1))) >> 31)) & 2)) - (v20426 + ((~(((v20427 ^ -1) | (-(v20427 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v20429 = v20428[v20715];
    bool v20716 = !(v20429 == 0);
    if (v20716) {
      int * v20430 = v20157->cache_tags;
      int v20431 = v20430[v20715];
      int * v20432 = v20157->cache_vals;
      int v20719 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20423 + ((~(((v20425 ^ -1) | (-(v20425 ^ -1))) >> 31)) & 2)) - (v20426 + ((~(((v20427 ^ -1) | (-(v20427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v20433 = v20432[v20719];
      int v20720 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20423 + ((~(((v20425 ^ -1) | (-(v20425 ^ -1))) >> 31)) & 2)) - (v20426 + ((~(((v20427 ^ -1) | (-(v20427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v20434 = v20432[v20720];
      int * v20435 = v20157->mem;
      int v20722 = v20431 * 2;
      v20435[v20722] = v20433;
      int * v20437 = v20157->mem;
      int v20725 = (v20431 * 2) + 1;
      v20437[v20725] = v20434;
      ;
    } else {
      ;
    }
    int * v20442 = v20157->mem;
    int v20730 = ((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) * 2;
    int v20443 = v20442[v20730];
    int v20731 = (((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) * 2) + 1;
    int v20444 = v20442[v20731];
    int * v20445 = v20157->cache_vals;
    int v20733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20423 + ((~(((v20425 ^ -1) | (-(v20425 ^ -1))) >> 31)) & 2)) - (v20426 + ((~(((v20427 ^ -1) | (-(v20427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v20445[v20733] = v20443;
    int * v20447 = v20157->cache_vals;
    int v20736 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v20423 + ((~(((v20425 ^ -1) | (-(v20425 ^ -1))) >> 31)) & 2)) - (v20426 + ((~(((v20427 ^ -1) | (-(v20427 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v20447[v20736] = v20444;
    int * v20449 = v20157->cache_tags;
    int v20739 = (int)((unsigned int)((int)((unsigned int)(v20161 + 28) >> 2)) >> 1);
    v20449[v20715] = v20739;
    int * v20451 = v20157->cache_dirty;
    v20451[v20715] = 0;
    int * v20453 = v20157->cache_age;
    v20453[v20715] = 1;
    int * v20455 = v20157->cache_age;
    int v20456 = v20455[v20715];
    int v20457 = v20455[v20619];
    int v20745 = v20457 + ((int)((unsigned int)(v20457 - v20456) >> 31));
    v20455[v20619] = v20745;
    int * v20459 = v20157->cache_age;
    int v20460 = v20459[v20620];
    int v20747 = v20460 + ((int)((unsigned int)(v20460 - v20456) >> 31));
    v20459[v20620] = v20747;
    int * v20462 = v20157->cache_age;
    v20462[v20715] = 0;
    v20465 = v20715;
  }
  int * v20466 = v20157->cache_vals;
  int v20750 = (v20465 * 2) + (((int)((unsigned int)(v20161 + 28) >> 2)) & 1);
  v20466[v20750] = v20162;
  int * v20468 = v20157->cache_dirty;
  v20468[v20465] = 1;
  bool v20754 = ((((int)((unsigned int)(v20197 + 32) >> 2)) & 3) == (((int)((unsigned int)(v20161 + 28) >> 2)) & 3)) & (!(((int)((unsigned int)(v20197 + 32) >> 2)) == ((int)((unsigned int)(v20161 + 28) >> 2))));
  struct StateT * v20492;
  if (v20754) {
    int v20470 = v20157->timer;
    int v20755 = v20470 + 15;
    v20157->timer = v20755;
    int * v20472 = v20157->saved_regs;
    int v20473 = v20472[17];
    int * v20474 = v20157->regs;
    v20474[17] = v20473;
    int * v20476 = v20157->saved_regs;
    int v20477 = v20476[28];
    int * v20478 = v20157->regs;
    v20478[28] = v20477;
    int * v20480 = v20157->saved_regs;
    int v20481 = v20480[5];
    int * v20482 = v20157->regs;
    v20482[5] = v20481;
    int * v20484 = v20157->saved_regs;
    int v20485 = v20484[6];
    int * v20486 = v20157->regs;
    v20486[6] = v20485;
    struct StateT * v20488 = slot_394(v20157);
    v20492 = v20488;
  } else {
    struct StateT * v20490 = slot_403(v20157);
    v20492 = v20490;
  }
  return v20492;
}

struct StateT * slot_920(struct StateT * v56487) {
  int v56488 = v56487->timer;
  int v56496 = v56488 + 1;
  v56487->timer = v56496;
  int * v56490 = v56487->regs;
  int v56491 = v56490[13];
  int v56492 = v56490[17];
  int v56500 = v56491 * v56492;
  v56490[13] = v56500;
  struct StateT * v56494 = slot_971(v56487);
  return v56494;
}

struct StateT * slot_749(struct StateT * v35067) {
  int v35068 = v35067->timer;
  int v35076 = v35068 + 1;
  v35067->timer = v35076;
  int * v35070 = v35067->regs;
  int v35071 = v35070[13];
  int v35072 = v35070[17];
  int v35080 = v35071 * v35072;
  v35070[13] = v35080;
  struct StateT * v35074 = slot_758(v35067);
  return v35074;
}

struct StateT * slot_293(struct StateT * v16456) {
  int v16457 = v16456->timer;
  int v16465 = v16457 + 1;
  v16456->timer = v16465;
  int * v16459 = v16456->regs;
  int v16460 = v16459[9];
  int v16461 = v16459[6];
  int v16470 = v16460 + v16461;
  v16459[5] = v16470;
  struct StateT * v16463 = slot_268(v16456);
  return v16463;
}

struct StateT * slot_288(struct StateT * v16368) {
  int v16369 = v16368->timer;
  int v16373 = v16369 + 1;
  v16368->timer = v16373;
  struct StateT * v16371 = slot_323(v16368);
  return v16371;
}

struct StateT * slot_89(struct StateT * v7511) {
  int v7512 = v7511->timer;
  int v7520 = v7512 + 1;
  v7511->timer = v7520;
  int * v7514 = v7511->regs;
  int v7515 = v7514[6];
  int v7516 = v7514[5];
  int v7524 = v7515 + v7516;
  v7514[5] = v7524;
  struct StateT * v7518 = slot_79(v7511);
  return v7518;
}

struct StateT * slot_347(struct StateT * v20140) {
  int v20141 = v20140->timer;
  int v20149 = v20141 + 1;
  v20140->timer = v20149;
  int * v20143 = v20140->regs;
  int v20144 = v20143[7];
  int v20145 = v20143[16];
  int v20154 = v20144 & v20145;
  v20143[29] = v20154;
  struct StateT * v20147 = slot_393(v20140);
  return v20147;
}

struct StateT * slot_140(struct StateT * v8558) {
  int v8559 = v8558->timer;
  int v8563 = v8559 + 1;
  v8558->timer = v8563;
  struct StateT * v8561 = slot_142(v8558);
  return v8561;
}

struct StateT * slot_473(struct StateT * v29864) {
  int v29865 = v29864->timer;
  int v29873 = v29865 + 1;
  v29864->timer = v29873;
  int * v29867 = v29864->regs;
  int v29868 = v29867[6];
  int v29869 = v29867[12];
  int v29878 = (((((int)((unsigned int)v29868 >> 16)) * ((int)((unsigned int)v29869 >> 16))) + ((int)((unsigned int)((v29868 & 65535) * ((int)((unsigned int)v29869 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v29868 >> 16)) * (v29869 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v29868 & 65535) * (v29869 & 65535)) >> 16)) + (((v29868 & 65535) * ((int)((unsigned int)v29869 >> 16))) & 65535)) + ((((int)((unsigned int)v29868 >> 16)) * (v29869 & 65535)) & 65535)) >> 16));
  v29867[5] = v29878;
  struct StateT * v29871 = slot_376(v29864);
  return v29871;
}

struct StateT * slot_40(struct StateT * v4179) {
  int v4180 = v4179->timer;
  int v4188 = v4180 + 1;
  v4179->timer = v4188;
  int * v4182 = v4179->regs;
  int v4183 = v4182[28];
  int v4184 = v4182[12];
  int v4193 = (((((int)((unsigned int)v4183 >> 16)) * ((int)((unsigned int)v4184 >> 16))) + ((int)((unsigned int)((v4183 & 65535) * ((int)((unsigned int)v4184 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4183 >> 16)) * (v4184 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4183 & 65535) * (v4184 & 65535)) >> 16)) + (((v4183 & 65535) * ((int)((unsigned int)v4184 >> 16))) & 65535)) + ((((int)((unsigned int)v4183 >> 16)) * (v4184 & 65535)) & 65535)) >> 16));
  v4182[31] = v4193;
  struct StateT * v4186 = slot_41(v4179);
  return v4186;
}

struct StateT * slot_586(struct StateT * v31992) {
  int v31993 = v31992->timer;
  int v32001 = v31993 + 1;
  v31992->timer = v32001;
  int * v31995 = v31992->regs;
  int v31996 = v31995[8];
  int v31997 = v31995[28];
  int v32006 = v31996 + v31997;
  v31995[12] = v32006;
  struct StateT * v31999 = slot_566(v31992);
  return v31999;
}

struct StateT * slot_75(struct StateT * v5760) {
  int v5761 = v5760->timer;
  int v5768 = v5761 + 1;
  v5760->timer = v5768;
  int * v5763 = v5760->regs;
  int v5764 = v5763[7];
  int v5771 = (int)((unsigned int)v5764 >> 19);
  v5763[7] = v5771;
  struct StateT * v5766 = slot_81(v5760);
  return v5766;
}

struct StateT * slot_175(struct StateT * v11535) {
  int v11536 = v11535->timer;
  int v11872 = v11536 + 1;
  v11535->timer = v11872;
  int * v11538 = v11535->regs;
  int v11539 = v11538[10];
  int v11540 = v11538[29];
  int * v11541 = v11535->saved_regs;
  int v11542 = v11538[17];
  v11541[17] = v11542;
  int v11544 = v11535->timer;
  int v11879 = v11544 + 1;
  v11535->timer = v11879;
  int * v11546 = v11535->regs;
  int v11547 = v11546[28];
  int v11882 = (int)((unsigned int)v11547 >> 19);
  v11546[17] = v11882;
  int * v11549 = v11535->saved_regs;
  int * v11550 = v11535->regs;
  int v11551 = v11550[28];
  v11549[28] = v11551;
  int v11553 = v11535->timer;
  int v11886 = v11553 + 1;
  v11535->timer = v11886;
  int * v11555 = v11535->regs;
  int v11556 = v11555[28];
  int v11888 = v11556 << 13;
  v11555[28] = v11888;
  int * v11558 = v11535->saved_regs;
  int * v11559 = v11535->regs;
  int v11560 = v11559[5];
  v11558[5] = v11560;
  int v11562 = v11535->timer;
  int v11893 = v11562 + 1;
  v11535->timer = v11893;
  int * v11564 = v11535->regs;
  int v11565 = v11564[6];
  int v11566 = v11564[5];
  int v11896 = v11565 + v11566;
  v11564[5] = v11896;
  int * v11568 = v11535->saved_regs;
  int * v11569 = v11535->regs;
  int v11570 = v11569[6];
  v11568[6] = v11570;
  int v11572 = v11535->timer;
  int v11900 = v11572 + 1;
  v11535->timer = v11900;
  int * v11574 = v11535->regs;
  int v11575 = v11574[11];
  bool v11903 = (((int)((unsigned int)(v11539 + 20) >> 2)) & 3) == (((int)((unsigned int)(v11575 + 24) >> 2)) & 3);
  int v11682;
  if (v11903) {
    int v11576 = v11535->timer;
    int v11904 = v11576 + 1;
    v11535->timer = v11904;
    v11682 = v11540;
  } else {
    int * v11579 = v11535->cache_tags;
    int v11907 = (((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2;
    int v11580 = v11579[v11907];
    int v11908 = ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
    int v11581 = v11579[v11908];
    int v11909 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2);
    int v11582 = v11579[v11909];
    int v11910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v11583 = v11579[v11910];
    int v11584 = v11535->timer;
    int v11911 = v11584 + ((100 ^ (((~(((v11582 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11582 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11580 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11580 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11581 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11581 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11582 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11582 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
    v11535->timer = v11911;
    int * v11586 = v11535->cache_vals;
    bool v11912 = !(((~(((v11580 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11580 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11581 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11581 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v11679;
    if (v11912) {
      int * v11587 = v11535->cache_age;
      int v11914 = ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v11581 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11581 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v11588 = v11587[v11914];
      int v11589 = v11587[v11907];
      int v11915 = v11589 + ((int)((unsigned int)(v11589 - v11588) >> 31));
      v11587[v11907] = v11915;
      int * v11591 = v11535->cache_age;
      int v11592 = v11591[v11908];
      int v11917 = v11592 + ((int)((unsigned int)(v11592 - v11588) >> 31));
      v11591[v11908] = v11917;
      int * v11594 = v11535->cache_age;
      v11594[v11914] = 0;
      v11679 = v11914;
    } else {
      int * v11597 = v11535->cache_age;
      int v11921 = (((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2;
      int v11598 = v11597[v11921];
      int * v11599 = v11535->cache_tags;
      int v11600 = v11599[v11921];
      int v11601 = v11597[v11908];
      int v11602 = v11599[v11908];
      bool v11923 = !(((~(((v11582 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11582 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31))) == 0);
      int v11656;
      if (v11923) {
        int * v11603 = v11535->cache_age;
        int v11925 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))) | (-(v11583 ^ ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1))))) >> 31)) & 1);
        int v11604 = v11603[v11925];
        int v11605 = v11603[v11909];
        int v11926 = v11605 + ((int)((unsigned int)(v11605 - v11604) >> 31));
        v11603[v11909] = v11926;
        int * v11607 = v11535->cache_age;
        int v11608 = v11607[v11910];
        int v11928 = v11608 + ((int)((unsigned int)(v11608 - v11604) >> 31));
        v11607[v11910] = v11928;
        int * v11610 = v11535->cache_age;
        v11610[v11925] = 0;
        v11656 = v11925;
      } else {
        int * v11613 = v11535->cache_age;
        int v11932 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2);
        int v11614 = v11613[v11932];
        int * v11615 = v11535->cache_tags;
        int v11616 = v11615[v11932];
        int v11617 = v11613[v11910];
        int v11618 = v11615[v11910];
        int * v11619 = v11535->cache_dirty;
        int v11935 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11614 + ((~(((v11616 ^ -1) | (-(v11616 ^ -1))) >> 31)) & 2)) - (v11617 + ((~(((v11618 ^ -1) | (-(v11618 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v11620 = v11619[v11935];
        bool v11936 = !(v11620 == 0);
        if (v11936) {
          int * v11621 = v11535->cache_tags;
          int v11622 = v11621[v11935];
          int * v11623 = v11535->cache_vals;
          int v11939 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11614 + ((~(((v11616 ^ -1) | (-(v11616 ^ -1))) >> 31)) & 2)) - (v11617 + ((~(((v11618 ^ -1) | (-(v11618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v11624 = v11623[v11939];
          int v11940 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11614 + ((~(((v11616 ^ -1) | (-(v11616 ^ -1))) >> 31)) & 2)) - (v11617 + ((~(((v11618 ^ -1) | (-(v11618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v11625 = v11623[v11940];
          int * v11626 = v11535->mem;
          int v11942 = v11622 * 2;
          v11626[v11942] = v11624;
          int * v11628 = v11535->mem;
          int v11945 = (v11622 * 2) + 1;
          v11628[v11945] = v11625;
          ;
        } else {
          ;
        }
        int * v11633 = v11535->mem;
        int v11950 = ((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) * 2;
        int v11634 = v11633[v11950];
        int v11951 = (((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) * 2) + 1;
        int v11635 = v11633[v11951];
        int * v11636 = v11535->cache_vals;
        int v11953 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11614 + ((~(((v11616 ^ -1) | (-(v11616 ^ -1))) >> 31)) & 2)) - (v11617 + ((~(((v11618 ^ -1) | (-(v11618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v11636[v11953] = v11634;
        int * v11638 = v11535->cache_vals;
        int v11956 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11614 + ((~(((v11616 ^ -1) | (-(v11616 ^ -1))) >> 31)) & 2)) - (v11617 + ((~(((v11618 ^ -1) | (-(v11618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v11638[v11956] = v11635;
        int * v11640 = v11535->cache_tags;
        int v11959 = (int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1);
        v11640[v11935] = v11959;
        int * v11642 = v11535->cache_dirty;
        v11642[v11935] = 0;
        int * v11644 = v11535->cache_age;
        v11644[v11935] = 1;
        int * v11646 = v11535->cache_age;
        int v11647 = v11646[v11935];
        int v11648 = v11646[v11909];
        int v11965 = v11648 + ((int)((unsigned int)(v11648 - v11647) >> 31));
        v11646[v11909] = v11965;
        int * v11650 = v11535->cache_age;
        int v11651 = v11650[v11910];
        int v11967 = v11651 + ((int)((unsigned int)(v11651 - v11647) >> 31));
        v11650[v11910] = v11967;
        int * v11653 = v11535->cache_age;
        v11653[v11935] = 0;
        v11656 = v11935;
      }
      int * v11657 = v11535->cache_vals;
      int v11970 = v11656 * 2;
      int v11658 = v11657[v11970];
      int v11971 = (v11656 * 2) + 1;
      int v11659 = v11657[v11971];
      int v11972 = (((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v11598 + ((~(((v11600 ^ -1) | (-(v11600 ^ -1))) >> 31)) & 2)) - (v11601 + ((~(((v11602 ^ -1) | (-(v11602 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11657[v11972] = v11658;
      int * v11661 = v11535->cache_vals;
      int v11975 = ((((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v11598 + ((~(((v11600 ^ -1) | (-(v11600 ^ -1))) >> 31)) & 2)) - (v11601 + ((~(((v11602 ^ -1) | (-(v11602 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11661[v11975] = v11659;
      int * v11663 = v11535->cache_tags;
      int v11978 = ((((int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v11598 + ((~(((v11600 ^ -1) | (-(v11600 ^ -1))) >> 31)) & 2)) - (v11601 + ((~(((v11602 ^ -1) | (-(v11602 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11979 = (int)((unsigned int)((int)((unsigned int)(v11575 + 24) >> 2)) >> 1);
      v11663[v11978] = v11979;
      int * v11665 = v11535->cache_dirty;
      v11665[v11978] = 0;
      int * v11667 = v11535->cache_age;
      v11667[v11978] = 1;
      int * v11669 = v11535->cache_age;
      int v11670 = v11669[v11978];
      int v11671 = v11669[v11907];
      int v11985 = v11671 + ((int)((unsigned int)(v11671 - v11670) >> 31));
      v11669[v11907] = v11985;
      int * v11673 = v11535->cache_age;
      int v11674 = v11673[v11908];
      int v11987 = v11674 + ((int)((unsigned int)(v11674 - v11670) >> 31));
      v11673[v11908] = v11987;
      int * v11676 = v11535->cache_age;
      v11676[v11978] = 0;
      v11679 = v11978;
    }
    int v11990 = (v11679 * 2) + (((int)((unsigned int)(v11575 + 24) >> 2)) & 1);
    int v11680 = v11586[v11990];
    v11682 = v11680;
  }
  int * v11683 = v11535->regs;
  v11683[6] = v11682;
  int * v11685 = v11535->cache_tags;
  int v11995 = (((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2;
  int v11686 = v11685[v11995];
  int v11996 = ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11687 = v11685[v11996];
  int v11997 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2);
  int v11688 = v11685[v11997];
  int v11998 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11689 = v11685[v11998];
  int v11690 = v11535->timer;
  int v11999 = v11690 + ((100 ^ (((~(((v11688 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11688 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11686 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11686 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v11687 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11687 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11688 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11688 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11535->timer = v11999;
  bool v12000 = !(((~(((v11686 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11686 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v11687 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11687 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v11784;
  if (v12000) {
    int * v11692 = v11535->cache_age;
    int v12002 = ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v11687 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11687 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v11693 = v11692[v12002];
    int v11694 = v11692[v11995];
    int v12003 = v11694 + ((int)((unsigned int)(v11694 - v11693) >> 31));
    v11692[v11995] = v12003;
    int * v11696 = v11535->cache_age;
    int v11697 = v11696[v11996];
    int v12005 = v11697 + ((int)((unsigned int)(v11697 - v11693) >> 31));
    v11696[v11996] = v12005;
    int * v11699 = v11535->cache_age;
    v11699[v12002] = 0;
    v11784 = v12002;
  } else {
    int * v11702 = v11535->cache_age;
    int v12009 = (((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2;
    int v11703 = v11702[v12009];
    int * v11704 = v11535->cache_tags;
    int v11705 = v11704[v12009];
    int v11706 = v11702[v11996];
    int v11707 = v11704[v11996];
    bool v12011 = !(((~(((v11688 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11688 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v11761;
    if (v12011) {
      int * v11708 = v11535->cache_age;
      int v12013 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11689 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v11709 = v11708[v12013];
      int v11710 = v11708[v11997];
      int v12014 = v11710 + ((int)((unsigned int)(v11710 - v11709) >> 31));
      v11708[v11997] = v12014;
      int * v11712 = v11535->cache_age;
      int v11713 = v11712[v11998];
      int v12016 = v11713 + ((int)((unsigned int)(v11713 - v11709) >> 31));
      v11712[v11998] = v12016;
      int * v11715 = v11535->cache_age;
      v11715[v12013] = 0;
      v11761 = v12013;
    } else {
      int * v11718 = v11535->cache_age;
      int v12020 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2);
      int v11719 = v11718[v12020];
      int * v11720 = v11535->cache_tags;
      int v11721 = v11720[v12020];
      int v11722 = v11718[v11998];
      int v11723 = v11720[v11998];
      int * v11724 = v11535->cache_dirty;
      int v12023 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11719 + ((~(((v11721 ^ -1) | (-(v11721 ^ -1))) >> 31)) & 2)) - (v11722 + ((~(((v11723 ^ -1) | (-(v11723 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11725 = v11724[v12023];
      bool v12024 = !(v11725 == 0);
      if (v12024) {
        int * v11726 = v11535->cache_tags;
        int v11727 = v11726[v12023];
        int * v11728 = v11535->cache_vals;
        int v12027 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11719 + ((~(((v11721 ^ -1) | (-(v11721 ^ -1))) >> 31)) & 2)) - (v11722 + ((~(((v11723 ^ -1) | (-(v11723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11729 = v11728[v12027];
        int v12028 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11719 + ((~(((v11721 ^ -1) | (-(v11721 ^ -1))) >> 31)) & 2)) - (v11722 + ((~(((v11723 ^ -1) | (-(v11723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11730 = v11728[v12028];
        int * v11731 = v11535->mem;
        int v12030 = v11727 * 2;
        v11731[v12030] = v11729;
        int * v11733 = v11535->mem;
        int v12033 = (v11727 * 2) + 1;
        v11733[v12033] = v11730;
        ;
      } else {
        ;
      }
      int * v11738 = v11535->mem;
      int v12038 = ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) * 2;
      int v11739 = v11738[v12038];
      int v12039 = (((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) * 2) + 1;
      int v11740 = v11738[v12039];
      int * v11741 = v11535->cache_vals;
      int v12041 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11719 + ((~(((v11721 ^ -1) | (-(v11721 ^ -1))) >> 31)) & 2)) - (v11722 + ((~(((v11723 ^ -1) | (-(v11723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11741[v12041] = v11739;
      int * v11743 = v11535->cache_vals;
      int v12044 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11719 + ((~(((v11721 ^ -1) | (-(v11721 ^ -1))) >> 31)) & 2)) - (v11722 + ((~(((v11723 ^ -1) | (-(v11723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11743[v12044] = v11740;
      int * v11745 = v11535->cache_tags;
      int v12047 = (int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1);
      v11745[v12023] = v12047;
      int * v11747 = v11535->cache_dirty;
      v11747[v12023] = 0;
      int * v11749 = v11535->cache_age;
      v11749[v12023] = 1;
      int * v11751 = v11535->cache_age;
      int v11752 = v11751[v12023];
      int v11753 = v11751[v11997];
      int v12053 = v11753 + ((int)((unsigned int)(v11753 - v11752) >> 31));
      v11751[v11997] = v12053;
      int * v11755 = v11535->cache_age;
      int v11756 = v11755[v11998];
      int v12055 = v11756 + ((int)((unsigned int)(v11756 - v11752) >> 31));
      v11755[v11998] = v12055;
      int * v11758 = v11535->cache_age;
      v11758[v12023] = 0;
      v11761 = v12023;
    }
    int * v11762 = v11535->cache_vals;
    int v12058 = v11761 * 2;
    int v11763 = v11762[v12058];
    int v12059 = (v11761 * 2) + 1;
    int v11764 = v11762[v12059];
    int v12060 = (((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v11703 + ((~(((v11705 ^ -1) | (-(v11705 ^ -1))) >> 31)) & 2)) - (v11706 + ((~(((v11707 ^ -1) | (-(v11707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11762[v12060] = v11763;
    int * v11766 = v11535->cache_vals;
    int v12063 = ((((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v11703 + ((~(((v11705 ^ -1) | (-(v11705 ^ -1))) >> 31)) & 2)) - (v11706 + ((~(((v11707 ^ -1) | (-(v11707 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11766[v12063] = v11764;
    int * v11768 = v11535->cache_tags;
    int v12066 = ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v11703 + ((~(((v11705 ^ -1) | (-(v11705 ^ -1))) >> 31)) & 2)) - (v11706 + ((~(((v11707 ^ -1) | (-(v11707 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12067 = (int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1);
    v11768[v12066] = v12067;
    int * v11770 = v11535->cache_dirty;
    v11770[v12066] = 0;
    int * v11772 = v11535->cache_age;
    v11772[v12066] = 1;
    int * v11774 = v11535->cache_age;
    int v11775 = v11774[v12066];
    int v11776 = v11774[v11995];
    int v12073 = v11776 + ((int)((unsigned int)(v11776 - v11775) >> 31));
    v11774[v11995] = v12073;
    int * v11778 = v11535->cache_age;
    int v11779 = v11778[v11996];
    int v12075 = v11779 + ((int)((unsigned int)(v11779 - v11775) >> 31));
    v11778[v11996] = v12075;
    int * v11781 = v11535->cache_age;
    v11781[v12066] = 0;
    v11784 = v12066;
  }
  int * v11785 = v11535->cache_vals;
  int v12078 = (v11784 * 2) + (((int)((unsigned int)(v11539 + 20) >> 2)) & 1);
  v11785[v12078] = v11540;
  int * v11787 = v11535->cache_tags;
  int v11788 = v11787[v11997];
  int v11789 = v11787[v11998];
  bool v12081 = !(((~(((v11788 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11788 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v11789 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11789 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v11843;
  if (v12081) {
    int * v11790 = v11535->cache_age;
    int v12083 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11789 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))) | (-(v11789 ^ ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v11791 = v11790[v12083];
    int v11792 = v11790[v11997];
    int v12084 = v11792 + ((int)((unsigned int)(v11792 - v11791) >> 31));
    v11790[v11997] = v12084;
    int * v11794 = v11535->cache_age;
    int v11795 = v11794[v11998];
    int v12086 = v11795 + ((int)((unsigned int)(v11795 - v11791) >> 31));
    v11794[v11998] = v12086;
    int * v11797 = v11535->cache_age;
    v11797[v12083] = 0;
    v11843 = v12083;
  } else {
    int * v11800 = v11535->cache_age;
    int v12090 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2);
    int v11801 = v11800[v12090];
    int * v11802 = v11535->cache_tags;
    int v11803 = v11802[v12090];
    int v11804 = v11800[v11998];
    int v11805 = v11802[v11998];
    int * v11806 = v11535->cache_dirty;
    int v12093 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11801 + ((~(((v11803 ^ -1) | (-(v11803 ^ -1))) >> 31)) & 2)) - (v11804 + ((~(((v11805 ^ -1) | (-(v11805 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11807 = v11806[v12093];
    bool v12094 = !(v11807 == 0);
    if (v12094) {
      int * v11808 = v11535->cache_tags;
      int v11809 = v11808[v12093];
      int * v11810 = v11535->cache_vals;
      int v12097 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11801 + ((~(((v11803 ^ -1) | (-(v11803 ^ -1))) >> 31)) & 2)) - (v11804 + ((~(((v11805 ^ -1) | (-(v11805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11811 = v11810[v12097];
      int v12098 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11801 + ((~(((v11803 ^ -1) | (-(v11803 ^ -1))) >> 31)) & 2)) - (v11804 + ((~(((v11805 ^ -1) | (-(v11805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11812 = v11810[v12098];
      int * v11813 = v11535->mem;
      int v12100 = v11809 * 2;
      v11813[v12100] = v11811;
      int * v11815 = v11535->mem;
      int v12103 = (v11809 * 2) + 1;
      v11815[v12103] = v11812;
      ;
    } else {
      ;
    }
    int * v11820 = v11535->mem;
    int v12108 = ((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) * 2;
    int v11821 = v11820[v12108];
    int v12109 = (((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) * 2) + 1;
    int v11822 = v11820[v12109];
    int * v11823 = v11535->cache_vals;
    int v12111 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11801 + ((~(((v11803 ^ -1) | (-(v11803 ^ -1))) >> 31)) & 2)) - (v11804 + ((~(((v11805 ^ -1) | (-(v11805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11823[v12111] = v11821;
    int * v11825 = v11535->cache_vals;
    int v12114 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v11801 + ((~(((v11803 ^ -1) | (-(v11803 ^ -1))) >> 31)) & 2)) - (v11804 + ((~(((v11805 ^ -1) | (-(v11805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11825[v12114] = v11822;
    int * v11827 = v11535->cache_tags;
    int v12117 = (int)((unsigned int)((int)((unsigned int)(v11539 + 20) >> 2)) >> 1);
    v11827[v12093] = v12117;
    int * v11829 = v11535->cache_dirty;
    v11829[v12093] = 0;
    int * v11831 = v11535->cache_age;
    v11831[v12093] = 1;
    int * v11833 = v11535->cache_age;
    int v11834 = v11833[v12093];
    int v11835 = v11833[v11997];
    int v12123 = v11835 + ((int)((unsigned int)(v11835 - v11834) >> 31));
    v11833[v11997] = v12123;
    int * v11837 = v11535->cache_age;
    int v11838 = v11837[v11998];
    int v12125 = v11838 + ((int)((unsigned int)(v11838 - v11834) >> 31));
    v11837[v11998] = v12125;
    int * v11840 = v11535->cache_age;
    v11840[v12093] = 0;
    v11843 = v12093;
  }
  int * v11844 = v11535->cache_vals;
  int v12128 = (v11843 * 2) + (((int)((unsigned int)(v11539 + 20) >> 2)) & 1);
  v11844[v12128] = v11540;
  int * v11846 = v11535->cache_dirty;
  v11846[v11843] = 1;
  bool v12132 = ((((int)((unsigned int)(v11575 + 24) >> 2)) & 3) == (((int)((unsigned int)(v11539 + 20) >> 2)) & 3)) & (!(((int)((unsigned int)(v11575 + 24) >> 2)) == ((int)((unsigned int)(v11539 + 20) >> 2))));
  struct StateT * v11870;
  if (v12132) {
    int v11848 = v11535->timer;
    int v12133 = v11848 + 15;
    v11535->timer = v12133;
    int * v11850 = v11535->saved_regs;
    int v11851 = v11850[17];
    int * v11852 = v11535->regs;
    v11852[17] = v11851;
    int * v11854 = v11535->saved_regs;
    int v11855 = v11854[28];
    int * v11856 = v11535->regs;
    v11856[28] = v11855;
    int * v11858 = v11535->saved_regs;
    int v11859 = v11858[5];
    int * v11860 = v11535->regs;
    v11860[5] = v11859;
    int * v11862 = v11535->saved_regs;
    int v11863 = v11862[6];
    int * v11864 = v11535->regs;
    v11864[6] = v11863;
    struct StateT * v11866 = slot_178(v11535);
    v11870 = v11866;
  } else {
    struct StateT * v11868 = slot_187(v11535);
    v11870 = v11868;
  }
  return v11870;
}

struct StateT * slot_565(struct StateT * v31584) {
  int v31585 = v31584->timer;
  int v31593 = v31585 + 1;
  v31584->timer = v31593;
  int * v31587 = v31584->regs;
  int v31588 = v31587[6];
  int v31589 = v31587[17];
  int v31597 = v31588 + v31589;
  v31587[17] = v31597;
  struct StateT * v31591 = slot_571(v31584);
  return v31591;
}

struct StateT * slot_188(struct StateT * v12823) {
  int v12824 = v12823->timer;
  int v12832 = v12824 + 1;
  v12823->timer = v12832;
  int * v12826 = v12823->regs;
  int v12827 = v12826[6];
  int v12828 = v12826[12];
  int v12837 = (((((int)((unsigned int)v12827 >> 16)) * ((int)((unsigned int)v12828 >> 16))) + ((int)((unsigned int)((v12827 & 65535) * ((int)((unsigned int)v12828 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v12827 >> 16)) * (v12828 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v12827 & 65535) * (v12828 & 65535)) >> 16)) + (((v12827 & 65535) * ((int)((unsigned int)v12828 >> 16))) & 65535)) + ((((int)((unsigned int)v12827 >> 16)) * (v12828 & 65535)) & 65535)) >> 16));
  v12826[17] = v12837;
  struct StateT * v12830 = slot_210(v12823);
  return v12830;
}

struct StateT * slot_758(struct StateT * v35552) {
  int * v35553 = v35552->saved_regs;
  int * v35554 = v35552->regs;
  int v35555 = v35554[15];
  v35553[15] = v35555;
  int v35557 = v35552->timer;
  int v35569 = v35557 + 1;
  v35552->timer = v35569;
  int * v35559 = v35552->regs;
  int v35560 = v35559[15];
  int v35561 = v35559[5];
  int v35572 = v35560 + v35561;
  v35559[15] = v35572;
  struct StateT * v35563 = slot_764(v35552);
  return v35563;
}

struct StateT * slot_972(struct StateT * v61166) {
  int v61167 = v61166->timer;
  int v61174 = v61167 + 1;
  v61166->timer = v61174;
  int * v61169 = v61166->regs;
  int v61170 = v61169[12];
  int v61177 = v61170 << 13;
  v61169[12] = v61177;
  struct StateT * v61172 = slot_1009(v61166);
  return v61172;
}

struct StateT * slot_110(struct StateT * v7981) {
  int v7982 = v7981->timer;
  int v7990 = v7982 + 1;
  v7981->timer = v7990;
  int * v7984 = v7981->regs;
  int v7985 = v7984[6];
  int v7986 = v7984[7];
  int v7995 = v7985 + v7986;
  v7984[17] = v7995;
  struct StateT * v7988 = slot_112(v7981);
  return v7988;
}

struct StateT * slot_301(struct StateT * v16603) {
  int v16604 = v16603->timer;
  int v16616 = v16604 + 1;
  v16603->timer = v16616;
  int * v16606 = v16603->regs;
  int v16607 = v16606[5];
  int v16608 = v16606[9];
  bool v16620 = (v16607 ^ -2147483648) < (v16608 ^ -2147483648);
  int v16611;
  if (v16620) {
    v16611 = 1;
  } else {
    v16611 = 0;
  }
  int * v16612 = v16603->regs;
  v16612[31] = v16611;
  struct StateT * v16614 = slot_305(v16603);
  return v16614;
}

struct StateT * slot_502(struct StateT * v30387) {
  int v30388 = v30387->timer;
  int v30396 = v30388 + 1;
  v30387->timer = v30396;
  int * v30390 = v30387->regs;
  int v30391 = v30390[30];
  int v30392 = v30390[5];
  int v30401 = v30391 + v30392;
  v30390[6] = v30401;
  struct StateT * v30394 = slot_539(v30387);
  return v30394;
}

struct StateT * slot_203(struct StateT * v14757) {
  int v14758 = v14757->timer;
  int v14766 = v14758 + 1;
  v14757->timer = v14766;
  int * v14760 = v14757->regs;
  int v14761 = v14760[6];
  int v14762 = v14760[5];
  int v14770 = v14761 + v14762;
  v14760[5] = v14770;
  struct StateT * v14764 = slot_204(v14757);
  return v14764;
}

struct StateT * slot_157(struct StateT * v9223) {
  int v9224 = v9223->timer;
  int v9232 = v9224 + 1;
  v9223->timer = v9232;
  int * v9226 = v9223->regs;
  int v9227 = v9226[7];
  int v9228 = v9226[16];
  int v9237 = v9227 & v9228;
  v9226[29] = v9237;
  struct StateT * v9230 = slot_160(v9223);
  return v9230;
}

struct StateT * slot_26(struct StateT * v2770) {
  int v2771 = v2770->timer;
  int v3211 = v2771 + 1;
  v2770->timer = v3211;
  int * v2773 = v2770->regs;
  int v2774 = v2773[10];
  int v2775 = v2773[15];
  int * v2776 = v2770->saved_regs;
  int v2777 = v2773[5];
  v2776[5] = v2777;
  int v2779 = v2770->timer;
  int v3218 = v2779 + 1;
  v2770->timer = v3218;
  int * v2781 = v2770->regs;
  int v2782 = v2781[6];
  int v2783 = v2781[5];
  int v3221 = v2782 + v2783;
  v2781[5] = v3221;
  int * v2785 = v2770->saved_regs;
  int * v2786 = v2770->regs;
  int v2787 = v2786[7];
  v2785[7] = v2787;
  int v2789 = v2770->timer;
  int v3226 = v2789 + 1;
  v2770->timer = v3226;
  int * v2791 = v2770->regs;
  int v2792 = v2791[11];
  int * v2793 = v2770->cache_tags;
  int v3230 = (((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2794 = v2793[v3230];
  int v3231 = ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2795 = v2793[v3231];
  int v3232 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2796 = v2793[v3232];
  int v3233 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2797 = v2793[v3233];
  int v2798 = v2770->timer;
  int v3234 = v2798 + ((100 ^ (((~(((v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2770->timer = v3234;
  int * v2800 = v2770->cache_vals;
  bool v3235 = !(((~(((v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2794 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v2893;
  if (v3235) {
    int * v2801 = v2770->cache_age;
    int v3237 = ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2795 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2802 = v2801[v3237];
    int v2803 = v2801[v3230];
    int v3238 = v2803 + ((int)((unsigned int)(v2803 - v2802) >> 31));
    v2801[v3230] = v3238;
    int * v2805 = v2770->cache_age;
    int v2806 = v2805[v3231];
    int v3240 = v2806 + ((int)((unsigned int)(v2806 - v2802) >> 31));
    v2805[v3231] = v3240;
    int * v2808 = v2770->cache_age;
    v2808[v3237] = 0;
    v2893 = v3237;
  } else {
    int * v2811 = v2770->cache_age;
    int v3244 = (((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2812 = v2811[v3244];
    int * v2813 = v2770->cache_tags;
    int v2814 = v2813[v3244];
    int v2815 = v2811[v3231];
    int v2816 = v2813[v3231];
    bool v3246 = !(((~(((v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2796 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2870;
    if (v3246) {
      int * v2817 = v2770->cache_age;
      int v3248 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))) | (-(v2797 ^ ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2818 = v2817[v3248];
      int v2819 = v2817[v3232];
      int v3249 = v2819 + ((int)((unsigned int)(v2819 - v2818) >> 31));
      v2817[v3232] = v3249;
      int * v2821 = v2770->cache_age;
      int v2822 = v2821[v3233];
      int v3251 = v2822 + ((int)((unsigned int)(v2822 - v2818) >> 31));
      v2821[v3233] = v3251;
      int * v2824 = v2770->cache_age;
      v2824[v3248] = 0;
      v2870 = v3248;
    } else {
      int * v2827 = v2770->cache_age;
      int v3255 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2828 = v2827[v3255];
      int * v2829 = v2770->cache_tags;
      int v2830 = v2829[v3255];
      int v2831 = v2827[v3233];
      int v2832 = v2829[v3233];
      int * v2833 = v2770->cache_dirty;
      int v3258 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2834 = v2833[v3258];
      bool v3259 = !(v2834 == 0);
      if (v3259) {
        int * v2835 = v2770->cache_tags;
        int v2836 = v2835[v3258];
        int * v2837 = v2770->cache_vals;
        int v3262 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2838 = v2837[v3262];
        int v3263 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2839 = v2837[v3263];
        int * v2840 = v2770->mem;
        int v3265 = v2836 * 2;
        v2840[v3265] = v2838;
        int * v2842 = v2770->mem;
        int v3268 = (v2836 * 2) + 1;
        v2842[v3268] = v2839;
        ;
      } else {
        ;
      }
      int * v2847 = v2770->mem;
      int v3273 = ((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) * 2;
      int v2848 = v2847[v3273];
      int v3274 = (((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2849 = v2847[v3274];
      int * v2850 = v2770->cache_vals;
      int v3276 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2850[v3276] = v2848;
      int * v2852 = v2770->cache_vals;
      int v3279 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2828 + ((~(((v2830 ^ -1) | (-(v2830 ^ -1))) >> 31)) & 2)) - (v2831 + ((~(((v2832 ^ -1) | (-(v2832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2852[v3279] = v2849;
      int * v2854 = v2770->cache_tags;
      int v3282 = (int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1);
      v2854[v3258] = v3282;
      int * v2856 = v2770->cache_dirty;
      v2856[v3258] = 0;
      int * v2858 = v2770->cache_age;
      v2858[v3258] = 1;
      int * v2860 = v2770->cache_age;
      int v2861 = v2860[v3258];
      int v2862 = v2860[v3232];
      int v3288 = v2862 + ((int)((unsigned int)(v2862 - v2861) >> 31));
      v2860[v3232] = v3288;
      int * v2864 = v2770->cache_age;
      int v2865 = v2864[v3233];
      int v3290 = v2865 + ((int)((unsigned int)(v2865 - v2861) >> 31));
      v2864[v3233] = v3290;
      int * v2867 = v2770->cache_age;
      v2867[v3258] = 0;
      v2870 = v3258;
    }
    int * v2871 = v2770->cache_vals;
    int v3293 = v2870 * 2;
    int v2872 = v2871[v3293];
    int v3294 = (v2870 * 2) + 1;
    int v2873 = v2871[v3294];
    int v3295 = (((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2812 + ((~(((v2814 ^ -1) | (-(v2814 ^ -1))) >> 31)) & 2)) - (v2815 + ((~(((v2816 ^ -1) | (-(v2816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2871[v3295] = v2872;
    int * v2875 = v2770->cache_vals;
    int v3298 = ((((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2812 + ((~(((v2814 ^ -1) | (-(v2814 ^ -1))) >> 31)) & 2)) - (v2815 + ((~(((v2816 ^ -1) | (-(v2816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2875[v3298] = v2873;
    int * v2877 = v2770->cache_tags;
    int v3301 = ((((int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2812 + ((~(((v2814 ^ -1) | (-(v2814 ^ -1))) >> 31)) & 2)) - (v2815 + ((~(((v2816 ^ -1) | (-(v2816 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3302 = (int)((unsigned int)((int)((unsigned int)(v2792 + 8) >> 2)) >> 1);
    v2877[v3301] = v3302;
    int * v2879 = v2770->cache_dirty;
    v2879[v3301] = 0;
    int * v2881 = v2770->cache_age;
    v2881[v3301] = 1;
    int * v2883 = v2770->cache_age;
    int v2884 = v2883[v3301];
    int v2885 = v2883[v3230];
    int v3308 = v2885 + ((int)((unsigned int)(v2885 - v2884) >> 31));
    v2883[v3230] = v3308;
    int * v2887 = v2770->cache_age;
    int v2888 = v2887[v3231];
    int v3310 = v2888 + ((int)((unsigned int)(v2888 - v2884) >> 31));
    v2887[v3231] = v3310;
    int * v2890 = v2770->cache_age;
    v2890[v3301] = 0;
    v2893 = v3301;
  }
  int v3313 = (v2893 * 2) + (((int)((unsigned int)(v2792 + 8) >> 2)) & 1);
  int v2894 = v2800[v3313];
  int * v2895 = v2770->regs;
  v2895[7] = v2894;
  int * v2897 = v2770->saved_regs;
  int * v2898 = v2770->regs;
  int v2899 = v2898[28];
  v2897[28] = v2899;
  int v2901 = v2770->timer;
  int v3320 = v2901 + 1;
  v2770->timer = v3320;
  int * v2903 = v2770->regs;
  int v2904 = v2903[11];
  bool v3322 = (((int)((unsigned int)(v2774 + 4) >> 2)) & 3) == (((int)((unsigned int)(v2904 + 12) >> 2)) & 3);
  int v3011;
  if (v3322) {
    int v2905 = v2770->timer;
    int v3323 = v2905 + 1;
    v2770->timer = v3323;
    v3011 = v2775;
  } else {
    int * v2908 = v2770->cache_tags;
    int v3326 = (((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2909 = v2908[v3326];
    int v3327 = ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
    int v2910 = v2908[v3327];
    int v3328 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2);
    int v2911 = v2908[v3328];
    int v3329 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v2912 = v2908[v3329];
    int v2913 = v2770->timer;
    int v3330 = v2913 + ((100 ^ (((~(((v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
    v2770->timer = v3330;
    int * v2915 = v2770->cache_vals;
    bool v3331 = !(((~(((v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2909 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3008;
    if (v3331) {
      int * v2916 = v2770->cache_age;
      int v3333 = ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2910 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2917 = v2916[v3333];
      int v2918 = v2916[v3326];
      int v3334 = v2918 + ((int)((unsigned int)(v2918 - v2917) >> 31));
      v2916[v3326] = v3334;
      int * v2920 = v2770->cache_age;
      int v2921 = v2920[v3327];
      int v3336 = v2921 + ((int)((unsigned int)(v2921 - v2917) >> 31));
      v2920[v3327] = v3336;
      int * v2923 = v2770->cache_age;
      v2923[v3333] = 0;
      v3008 = v3333;
    } else {
      int * v2926 = v2770->cache_age;
      int v3340 = (((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2;
      int v2927 = v2926[v3340];
      int * v2928 = v2770->cache_tags;
      int v2929 = v2928[v3340];
      int v2930 = v2926[v3327];
      int v2931 = v2928[v3327];
      bool v3342 = !(((~(((v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2911 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31))) == 0);
      int v2985;
      if (v3342) {
        int * v2932 = v2770->cache_age;
        int v3344 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))) | (-(v2912 ^ ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1))))) >> 31)) & 1);
        int v2933 = v2932[v3344];
        int v2934 = v2932[v3328];
        int v3345 = v2934 + ((int)((unsigned int)(v2934 - v2933) >> 31));
        v2932[v3328] = v3345;
        int * v2936 = v2770->cache_age;
        int v2937 = v2936[v3329];
        int v3347 = v2937 + ((int)((unsigned int)(v2937 - v2933) >> 31));
        v2936[v3329] = v3347;
        int * v2939 = v2770->cache_age;
        v2939[v3344] = 0;
        v2985 = v3344;
      } else {
        int * v2942 = v2770->cache_age;
        int v3351 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2);
        int v2943 = v2942[v3351];
        int * v2944 = v2770->cache_tags;
        int v2945 = v2944[v3351];
        int v2946 = v2942[v3329];
        int v2947 = v2944[v3329];
        int * v2948 = v2770->cache_dirty;
        int v3354 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v2949 = v2948[v3354];
        bool v3355 = !(v2949 == 0);
        if (v3355) {
          int * v2950 = v2770->cache_tags;
          int v2951 = v2950[v3354];
          int * v2952 = v2770->cache_vals;
          int v3358 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v2953 = v2952[v3358];
          int v3359 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v2954 = v2952[v3359];
          int * v2955 = v2770->mem;
          int v3361 = v2951 * 2;
          v2955[v3361] = v2953;
          int * v2957 = v2770->mem;
          int v3364 = (v2951 * 2) + 1;
          v2957[v3364] = v2954;
          ;
        } else {
          ;
        }
        int * v2962 = v2770->mem;
        int v3369 = ((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) * 2;
        int v2963 = v2962[v3369];
        int v3370 = (((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) * 2) + 1;
        int v2964 = v2962[v3370];
        int * v2965 = v2770->cache_vals;
        int v3372 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v2965[v3372] = v2963;
        int * v2967 = v2770->cache_vals;
        int v3375 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2943 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2)) - (v2946 + ((~(((v2947 ^ -1) | (-(v2947 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v2967[v3375] = v2964;
        int * v2969 = v2770->cache_tags;
        int v3378 = (int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1);
        v2969[v3354] = v3378;
        int * v2971 = v2770->cache_dirty;
        v2971[v3354] = 0;
        int * v2973 = v2770->cache_age;
        v2973[v3354] = 1;
        int * v2975 = v2770->cache_age;
        int v2976 = v2975[v3354];
        int v2977 = v2975[v3328];
        int v3384 = v2977 + ((int)((unsigned int)(v2977 - v2976) >> 31));
        v2975[v3328] = v3384;
        int * v2979 = v2770->cache_age;
        int v2980 = v2979[v3329];
        int v3386 = v2980 + ((int)((unsigned int)(v2980 - v2976) >> 31));
        v2979[v3329] = v3386;
        int * v2982 = v2770->cache_age;
        v2982[v3354] = 0;
        v2985 = v3354;
      }
      int * v2986 = v2770->cache_vals;
      int v3389 = v2985 * 2;
      int v2987 = v2986[v3389];
      int v3390 = (v2985 * 2) + 1;
      int v2988 = v2986[v3390];
      int v3391 = (((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2927 + ((~(((v2929 ^ -1) | (-(v2929 ^ -1))) >> 31)) & 2)) - (v2930 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2986[v3391] = v2987;
      int * v2990 = v2770->cache_vals;
      int v3394 = ((((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2927 + ((~(((v2929 ^ -1) | (-(v2929 ^ -1))) >> 31)) & 2)) - (v2930 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2990[v3394] = v2988;
      int * v2992 = v2770->cache_tags;
      int v3397 = ((((int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2927 + ((~(((v2929 ^ -1) | (-(v2929 ^ -1))) >> 31)) & 2)) - (v2930 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3398 = (int)((unsigned int)((int)((unsigned int)(v2904 + 12) >> 2)) >> 1);
      v2992[v3397] = v3398;
      int * v2994 = v2770->cache_dirty;
      v2994[v3397] = 0;
      int * v2996 = v2770->cache_age;
      v2996[v3397] = 1;
      int * v2998 = v2770->cache_age;
      int v2999 = v2998[v3397];
      int v3000 = v2998[v3326];
      int v3404 = v3000 + ((int)((unsigned int)(v3000 - v2999) >> 31));
      v2998[v3326] = v3404;
      int * v3002 = v2770->cache_age;
      int v3003 = v3002[v3327];
      int v3406 = v3003 + ((int)((unsigned int)(v3003 - v2999) >> 31));
      v3002[v3327] = v3406;
      int * v3005 = v2770->cache_age;
      v3005[v3397] = 0;
      v3008 = v3397;
    }
    int v3409 = (v3008 * 2) + (((int)((unsigned int)(v2904 + 12) >> 2)) & 1);
    int v3009 = v2915[v3409];
    v3011 = v3009;
  }
  int * v3012 = v2770->regs;
  v3012[28] = v3011;
  int * v3014 = v2770->saved_regs;
  int * v3015 = v2770->regs;
  int v3016 = v3015[31];
  v3014[31] = v3016;
  int v3018 = v2770->timer;
  int v3417 = v3018 + 1;
  v2770->timer = v3417;
  int * v3020 = v2770->regs;
  int v3021 = v3020[29];
  int v3022 = v3020[5];
  int v3420 = v3021 + v3022;
  v3020[31] = v3420;
  int * v3024 = v2770->cache_tags;
  int v3422 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3025 = v3024[v3422];
  int v3423 = ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3026 = v3024[v3423];
  int v3424 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3027 = v3024[v3424];
  int v3425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3028 = v3024[v3425];
  int v3029 = v2770->timer;
  int v3426 = v3029 + ((100 ^ (((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2770->timer = v3426;
  bool v3427 = !(((~(((v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3025 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3123;
  if (v3427) {
    int * v3031 = v2770->cache_age;
    int v3429 = ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3032 = v3031[v3429];
    int v3033 = v3031[v3422];
    int v3430 = v3033 + ((int)((unsigned int)(v3033 - v3032) >> 31));
    v3031[v3422] = v3430;
    int * v3035 = v2770->cache_age;
    int v3036 = v3035[v3423];
    int v3432 = v3036 + ((int)((unsigned int)(v3036 - v3032) >> 31));
    v3035[v3423] = v3432;
    int * v3038 = v2770->cache_age;
    v3038[v3429] = 0;
    v3123 = v3429;
  } else {
    int * v3041 = v2770->cache_age;
    int v3436 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3042 = v3041[v3436];
    int * v3043 = v2770->cache_tags;
    int v3044 = v3043[v3436];
    int v3045 = v3041[v3423];
    int v3046 = v3043[v3423];
    bool v3438 = !(((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3100;
    if (v3438) {
      int * v3047 = v2770->cache_age;
      int v3440 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3028 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3048 = v3047[v3440];
      int v3049 = v3047[v3424];
      int v3441 = v3049 + ((int)((unsigned int)(v3049 - v3048) >> 31));
      v3047[v3424] = v3441;
      int * v3051 = v2770->cache_age;
      int v3052 = v3051[v3425];
      int v3443 = v3052 + ((int)((unsigned int)(v3052 - v3048) >> 31));
      v3051[v3425] = v3443;
      int * v3054 = v2770->cache_age;
      v3054[v3440] = 0;
      v3100 = v3440;
    } else {
      int * v3057 = v2770->cache_age;
      int v3447 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3058 = v3057[v3447];
      int * v3059 = v2770->cache_tags;
      int v3060 = v3059[v3447];
      int v3061 = v3057[v3425];
      int v3062 = v3059[v3425];
      int * v3063 = v2770->cache_dirty;
      int v3450 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3064 = v3063[v3450];
      bool v3451 = !(v3064 == 0);
      if (v3451) {
        int * v3065 = v2770->cache_tags;
        int v3066 = v3065[v3450];
        int * v3067 = v2770->cache_vals;
        int v3454 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3068 = v3067[v3454];
        int v3455 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3069 = v3067[v3455];
        int * v3070 = v2770->mem;
        int v3457 = v3066 * 2;
        v3070[v3457] = v3068;
        int * v3072 = v2770->mem;
        int v3460 = (v3066 * 2) + 1;
        v3072[v3460] = v3069;
        ;
      } else {
        ;
      }
      int * v3077 = v2770->mem;
      int v3465 = ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2;
      int v3078 = v3077[v3465];
      int v3466 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3079 = v3077[v3466];
      int * v3080 = v2770->cache_vals;
      int v3468 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3080[v3468] = v3078;
      int * v3082 = v2770->cache_vals;
      int v3471 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3058 + ((~(((v3060 ^ -1) | (-(v3060 ^ -1))) >> 31)) & 2)) - (v3061 + ((~(((v3062 ^ -1) | (-(v3062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3082[v3471] = v3079;
      int * v3084 = v2770->cache_tags;
      int v3474 = (int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1);
      v3084[v3450] = v3474;
      int * v3086 = v2770->cache_dirty;
      v3086[v3450] = 0;
      int * v3088 = v2770->cache_age;
      v3088[v3450] = 1;
      int * v3090 = v2770->cache_age;
      int v3091 = v3090[v3450];
      int v3092 = v3090[v3424];
      int v3480 = v3092 + ((int)((unsigned int)(v3092 - v3091) >> 31));
      v3090[v3424] = v3480;
      int * v3094 = v2770->cache_age;
      int v3095 = v3094[v3425];
      int v3482 = v3095 + ((int)((unsigned int)(v3095 - v3091) >> 31));
      v3094[v3425] = v3482;
      int * v3097 = v2770->cache_age;
      v3097[v3450] = 0;
      v3100 = v3450;
    }
    int * v3101 = v2770->cache_vals;
    int v3485 = v3100 * 2;
    int v3102 = v3101[v3485];
    int v3486 = (v3100 * 2) + 1;
    int v3103 = v3101[v3486];
    int v3487 = (((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3042 + ((~(((v3044 ^ -1) | (-(v3044 ^ -1))) >> 31)) & 2)) - (v3045 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3101[v3487] = v3102;
    int * v3105 = v2770->cache_vals;
    int v3490 = ((((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3042 + ((~(((v3044 ^ -1) | (-(v3044 ^ -1))) >> 31)) & 2)) - (v3045 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3105[v3490] = v3103;
    int * v3107 = v2770->cache_tags;
    int v3493 = ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3042 + ((~(((v3044 ^ -1) | (-(v3044 ^ -1))) >> 31)) & 2)) - (v3045 + ((~(((v3046 ^ -1) | (-(v3046 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3494 = (int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1);
    v3107[v3493] = v3494;
    int * v3109 = v2770->cache_dirty;
    v3109[v3493] = 0;
    int * v3111 = v2770->cache_age;
    v3111[v3493] = 1;
    int * v3113 = v2770->cache_age;
    int v3114 = v3113[v3493];
    int v3115 = v3113[v3422];
    int v3500 = v3115 + ((int)((unsigned int)(v3115 - v3114) >> 31));
    v3113[v3422] = v3500;
    int * v3117 = v2770->cache_age;
    int v3118 = v3117[v3423];
    int v3502 = v3118 + ((int)((unsigned int)(v3118 - v3114) >> 31));
    v3117[v3423] = v3502;
    int * v3120 = v2770->cache_age;
    v3120[v3493] = 0;
    v3123 = v3493;
  }
  int * v3124 = v2770->cache_vals;
  int v3505 = (v3123 * 2) + (((int)((unsigned int)(v2774 + 4) >> 2)) & 1);
  v3124[v3505] = v2775;
  int * v3126 = v2770->cache_tags;
  int v3127 = v3126[v3424];
  int v3128 = v3126[v3425];
  bool v3508 = !(((~(((v3127 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3127 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3182;
  if (v3508) {
    int * v3129 = v2770->cache_age;
    int v3510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))) | (-(v3128 ^ ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3130 = v3129[v3510];
    int v3131 = v3129[v3424];
    int v3511 = v3131 + ((int)((unsigned int)(v3131 - v3130) >> 31));
    v3129[v3424] = v3511;
    int * v3133 = v2770->cache_age;
    int v3134 = v3133[v3425];
    int v3513 = v3134 + ((int)((unsigned int)(v3134 - v3130) >> 31));
    v3133[v3425] = v3513;
    int * v3136 = v2770->cache_age;
    v3136[v3510] = 0;
    v3182 = v3510;
  } else {
    int * v3139 = v2770->cache_age;
    int v3517 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2);
    int v3140 = v3139[v3517];
    int * v3141 = v2770->cache_tags;
    int v3142 = v3141[v3517];
    int v3143 = v3139[v3425];
    int v3144 = v3141[v3425];
    int * v3145 = v2770->cache_dirty;
    int v3520 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3146 = v3145[v3520];
    bool v3521 = !(v3146 == 0);
    if (v3521) {
      int * v3147 = v2770->cache_tags;
      int v3148 = v3147[v3520];
      int * v3149 = v2770->cache_vals;
      int v3524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3150 = v3149[v3524];
      int v3525 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3151 = v3149[v3525];
      int * v3152 = v2770->mem;
      int v3527 = v3148 * 2;
      v3152[v3527] = v3150;
      int * v3154 = v2770->mem;
      int v3530 = (v3148 * 2) + 1;
      v3154[v3530] = v3151;
      ;
    } else {
      ;
    }
    int * v3159 = v2770->mem;
    int v3535 = ((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2;
    int v3160 = v3159[v3535];
    int v3536 = (((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) * 2) + 1;
    int v3161 = v3159[v3536];
    int * v3162 = v2770->cache_vals;
    int v3538 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3162[v3538] = v3160;
    int * v3164 = v2770->cache_vals;
    int v3541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3140 + ((~(((v3142 ^ -1) | (-(v3142 ^ -1))) >> 31)) & 2)) - (v3143 + ((~(((v3144 ^ -1) | (-(v3144 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3164[v3541] = v3161;
    int * v3166 = v2770->cache_tags;
    int v3544 = (int)((unsigned int)((int)((unsigned int)(v2774 + 4) >> 2)) >> 1);
    v3166[v3520] = v3544;
    int * v3168 = v2770->cache_dirty;
    v3168[v3520] = 0;
    int * v3170 = v2770->cache_age;
    v3170[v3520] = 1;
    int * v3172 = v2770->cache_age;
    int v3173 = v3172[v3520];
    int v3174 = v3172[v3424];
    int v3550 = v3174 + ((int)((unsigned int)(v3174 - v3173) >> 31));
    v3172[v3424] = v3550;
    int * v3176 = v2770->cache_age;
    int v3177 = v3176[v3425];
    int v3552 = v3177 + ((int)((unsigned int)(v3177 - v3173) >> 31));
    v3176[v3425] = v3552;
    int * v3179 = v2770->cache_age;
    v3179[v3520] = 0;
    v3182 = v3520;
  }
  int * v3183 = v2770->cache_vals;
  int v3555 = (v3182 * 2) + (((int)((unsigned int)(v2774 + 4) >> 2)) & 1);
  v3183[v3555] = v2775;
  int * v3185 = v2770->cache_dirty;
  v3185[v3182] = 1;
  bool v3559 = (((int)((unsigned int)(v2792 + 8) >> 2)) == ((int)((unsigned int)(v2774 + 4) >> 2))) | (((((int)((unsigned int)(v2904 + 12) >> 2)) & 3) == (((int)((unsigned int)(v2774 + 4) >> 2)) & 3)) & (!(((int)((unsigned int)(v2904 + 12) >> 2)) == ((int)((unsigned int)(v2774 + 4) >> 2)))));
  struct StateT * v3209;
  if (v3559) {
    int v3187 = v2770->timer;
    int v3560 = v3187 + 15;
    v2770->timer = v3560;
    int * v3189 = v2770->saved_regs;
    int v3190 = v3189[5];
    int * v3191 = v2770->regs;
    v3191[5] = v3190;
    int * v3193 = v2770->saved_regs;
    int v3194 = v3193[7];
    int * v3195 = v2770->regs;
    v3195[7] = v3194;
    int * v3197 = v2770->saved_regs;
    int v3198 = v3197[28];
    int * v3199 = v2770->regs;
    v3199[28] = v3198;
    int * v3201 = v2770->saved_regs;
    int v3202 = v3201[31];
    int * v3203 = v2770->regs;
    v3203[31] = v3202;
    struct StateT * v3205 = slot_27(v2770);
    v3209 = v3205;
  } else {
    struct StateT * v3207 = slot_31(v2770);
    v3209 = v3207;
  }
  return v3209;
}

struct StateT * slot_370(struct StateT * v22339) {
  int * v22340 = v22339->saved_regs;
  int v22341 = v22340[7];
  int v22342 = v22340[29];
  bool v22370 = v22341 == v22342;
  struct StateT * v22365;
  if (v22370) {
    int v22343 = v22339->timer;
    int v22371 = v22343 + 15;
    v22339->timer = v22371;
    int * v22345 = v22339->saved_regs;
    int v22346 = v22345[28];
    int * v22347 = v22339->regs;
    v22347[28] = v22346;
    int * v22349 = v22339->saved_regs;
    int v22350 = v22349[29];
    int * v22351 = v22339->regs;
    v22351[29] = v22350;
    int * v22353 = v22339->saved_regs;
    int v22354 = v22353[7];
    int * v22355 = v22339->regs;
    v22355[7] = v22354;
    int * v22357 = v22339->saved_regs;
    int v22358 = v22357[5];
    int * v22359 = v22339->regs;
    v22359[5] = v22358;
    struct StateT * v22361 = slot_316(v22339);
    v22365 = v22361;
  } else {
    struct StateT * v22363 = slot_421(v22339);
    v22365 = v22363;
  }
  return v22365;
}

struct StateT * slot_14(struct StateT * v2260) {
  int v2261 = v2260->timer;
  int v2269 = v2261 + 1;
  v2260->timer = v2269;
  int * v2263 = v2260->regs;
  int v2264 = v2263[15];
  int v2265 = v2263[13];
  int v2274 = v2264 * v2265;
  v2263[29] = v2274;
  struct StateT * v2267 = slot_15(v2260);
  return v2267;
}

struct StateT * slot_602(struct StateT * v32282) {
  int v32283 = v32282->timer;
  int v32295 = v32283 + 1;
  v32282->timer = v32295;
  int * v32285 = v32282->regs;
  int v32286 = v32285[12];
  int v32287 = v32285[8];
  bool v32299 = (v32286 ^ -2147483648) < (v32287 ^ -2147483648);
  int v32290;
  if (v32299) {
    v32290 = 1;
  } else {
    v32290 = 0;
  }
  int * v32291 = v32282->regs;
  v32291[28] = v32290;
  struct StateT * v32293 = slot_611(v32282);
  return v32293;
}

struct StateT * slot_639(struct StateT * v32977) {
  int * v32978 = v32977->saved_regs;
  int * v32979 = v32977->regs;
  int v32980 = v32979[17];
  v32978[17] = v32980;
  int v32982 = v32977->timer;
  int v32993 = v32982 + 1;
  v32977->timer = v32993;
  int * v32984 = v32977->regs;
  int v32985 = v32984[17];
  int v32995 = (int)((unsigned int)v32985 >> 19);
  v32984[17] = v32995;
  struct StateT * v32987 = slot_616(v32977);
  return v32987;
}

struct StateT * slot_954(struct StateT * v60550) {
  int v60551 = v60550->timer;
  int v60559 = v60551 + 1;
  v60550->timer = v60559;
  int * v60553 = v60550->regs;
  int v60554 = v60553[13];
  int v60555 = v60553[12];
  int v60563 = v60554 + v60555;
  v60553[12] = v60563;
  struct StateT * v60557 = slot_923(v60550);
  return v60557;
}

struct StateT * slot_36(struct StateT * v4113) {
  int v4114 = v4113->timer;
  int v4122 = v4114 + 1;
  v4113->timer = v4122;
  int * v4116 = v4113->regs;
  int v4117 = v4116[5];
  int v4118 = v4116[6];
  int v4126 = v4117 + v4118;
  v4116[5] = v4126;
  struct StateT * v4120 = slot_37(v4113);
  return v4120;
}

struct StateT * slot_57(struct StateT * v4482) {
  int v4483 = v4482->timer;
  int v4491 = v4483 + 1;
  v4482->timer = v4491;
  int * v4485 = v4482->regs;
  int v4486 = v4485[30];
  int v4487 = v4485[6];
  int v4495 = v4486 + v4487;
  v4485[6] = v4495;
  struct StateT * v4489 = slot_58(v4482);
  return v4489;
}

struct StateT * slot_62(struct StateT * v4580) {
  int v4581 = v4580->timer;
  int v4589 = v4581 + 1;
  v4580->timer = v4589;
  int * v4583 = v4580->regs;
  int v4584 = v4583[7];
  int v4585 = v4583[28];
  int v4593 = v4584 + v4585;
  v4583[7] = v4593;
  struct StateT * v4587 = slot_63(v4580);
  return v4587;
}

struct StateT * slot_323(struct StateT * v17955) {
  int * v17956 = v17955->saved_regs;
  int * v17957 = v17955->regs;
  int v17958 = v17957[28];
  v17956[28] = v17958;
  int v17960 = v17955->timer;
  int v17976 = v17960 + 1;
  v17955->timer = v17976;
  int * v17962 = v17955->regs;
  int v17963 = v17962[7];
  int v17964 = v17962[29];
  bool v17980 = (v17963 ^ -2147483648) < (v17964 ^ -2147483648);
  int v17967;
  if (v17980) {
    v17967 = 1;
  } else {
    v17967 = 0;
  }
  int * v17968 = v17955->regs;
  v17968[28] = v17967;
  struct StateT * v17970 = slot_310(v17955);
  return v17970;
}

struct StateT * slot_628(struct StateT * v32779) {
  int * v32780 = v32779->saved_regs;
  int * v32781 = v32779->regs;
  int v32782 = v32781[16];
  v32780[16] = v32782;
  int v32784 = v32779->timer;
  int v32796 = v32784 + 1;
  v32779->timer = v32796;
  int * v32786 = v32779->regs;
  int v32787 = v32786[17];
  int v32788 = v32786[16];
  int v32799 = v32787 & v32788;
  v32786[16] = v32799;
  struct StateT * v32790 = slot_639(v32779);
  return v32790;
}

struct StateT * slot_23(struct StateT * v2425) {
  int v2426 = v2425->timer;
  int v2433 = v2426 + 1;
  v2425->timer = v2433;
  int * v2428 = v2425->regs;
  int v2429 = v2428[17];
  int v2436 = (int)((unsigned int)v2429 >> 19);
  v2428[17] = v2436;
  struct StateT * v2431 = slot_24(v2425);
  return v2431;
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

struct StateT * slot_86(struct StateT * v7212) {
  int v7213 = v7212->timer;
  int v7221 = v7213 + 1;
  v7212->timer = v7221;
  int * v7215 = v7212->regs;
  int v7216 = v7215[5];
  int v7217 = v7215[17];
  int v7225 = v7216 | v7217;
  v7215[5] = v7225;
  struct StateT * v7219 = slot_99(v7212);
  return v7219;
}

struct StateT * slot_100(struct StateT * v7812) {
  int v7813 = v7812->timer;
  int v7821 = v7813 + 1;
  v7812->timer = v7821;
  int * v7815 = v7812->regs;
  int v7816 = v7815[6];
  int v7817 = v7815[13];
  int v7826 = (((((int)((unsigned int)v7816 >> 16)) * ((int)((unsigned int)v7817 >> 16))) + ((int)((unsigned int)((v7816 & 65535) * ((int)((unsigned int)v7817 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v7816 >> 16)) * (v7817 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v7816 & 65535) * (v7817 & 65535)) >> 16)) + (((v7816 & 65535) * ((int)((unsigned int)v7817 >> 16))) & 65535)) + ((((int)((unsigned int)v7816 >> 16)) * (v7817 & 65535)) & 65535)) >> 16));
  v7815[8] = v7826;
  struct StateT * v7819 = slot_109(v7812);
  return v7819;
}

struct StateT * slot_13(struct StateT * v2243) {
  int v2244 = v2243->timer;
  int v2252 = v2244 + 1;
  v2243->timer = v2252;
  int * v2246 = v2243->regs;
  int v2247 = v2246[14];
  int v2248 = v2246[13];
  int v2257 = (((((int)((unsigned int)v2247 >> 16)) * ((int)((unsigned int)v2248 >> 16))) + ((int)((unsigned int)((v2247 & 65535) * ((int)((unsigned int)v2248 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2247 >> 16)) * (v2248 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2247 & 65535) * (v2248 & 65535)) >> 16)) + (((v2247 & 65535) * ((int)((unsigned int)v2248 >> 16))) & 65535)) + ((((int)((unsigned int)v2247 >> 16)) * (v2248 & 65535)) & 65535)) >> 16));
  v2246[28] = v2257;
  struct StateT * v2250 = slot_14(v2243);
  return v2250;
}

struct StateT * slot_109(struct StateT * v7964) {
  int v7965 = v7964->timer;
  int v7973 = v7965 + 1;
  v7964->timer = v7973;
  int * v7967 = v7964->regs;
  int v7968 = v7967[29];
  int v7969 = v7967[13];
  int v7978 = v7968 * v7969;
  v7967[9] = v7978;
  struct StateT * v7971 = slot_104(v7964);
  return v7971;
}

struct StateT * slot_224(struct StateT * v15159) {
  int v15160 = v15159->timer;
  int v15168 = v15160 + 1;
  v15159->timer = v15168;
  int * v15162 = v15159->regs;
  int v15163 = v15162[28];
  int v15164 = v15162[17];
  int v15173 = v15163 + v15164;
  v15162[29] = v15173;
  struct StateT * v15166 = slot_228(v15159);
  return v15166;
}

struct StateT * slot_184(struct StateT * v12894) {
  int v12895 = v12894->timer;
  int v12902 = v12895 + 1;
  v12894->timer = v12902;
  int * v12897 = v12894->regs;
  int v12898 = v12897[28];
  int v12905 = v12898 << 13;
  v12897[28] = v12905;
  struct StateT * v12900 = slot_203(v12894);
  return v12900;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_393(struct StateT * v26156) {
  int v26157 = v26156->timer;
  int v26164 = v26157 + 1;
  v26156->timer = v26164;
  int * v26159 = v26156->regs;
  int v26160 = v26159[7];
  int v26167 = (int)((unsigned int)v26160 >> 19);
  v26159[7] = v26167;
  struct StateT * v26162 = slot_373(v26156);
  return v26162;
}

struct StateT * slot_477(struct StateT * v29931) {
  int v29932 = v29931->timer;
  int v29940 = v29932 + 1;
  v29931->timer = v29940;
  int * v29934 = v29931->regs;
  int v29935 = v29934[6];
  int v29936 = v29934[13];
  int v29945 = (((((int)((unsigned int)v29935 >> 16)) * ((int)((unsigned int)v29936 >> 16))) + ((int)((unsigned int)((v29935 & 65535) * ((int)((unsigned int)v29936 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v29935 >> 16)) * (v29936 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v29935 & 65535) * (v29936 & 65535)) >> 16)) + (((v29935 & 65535) * ((int)((unsigned int)v29936 >> 16))) & 65535)) + ((((int)((unsigned int)v29935 >> 16)) * (v29936 & 65535)) & 65535)) >> 16));
  v29934[31] = v29945;
  struct StateT * v29938 = slot_452(v29931);
  return v29938;
}

struct StateT * slot_249(struct StateT * v15620) {
  int v15621 = v15620->timer;
  int v15629 = v15621 + 1;
  v15620->timer = v15629;
  int * v15623 = v15620->regs;
  int v15624 = v15623[6];
  int v15625 = v15623[12];
  int v15633 = v15624 * v15625;
  v15623[6] = v15633;
  struct StateT * v15627 = slot_224(v15620);
  return v15627;
}

struct StateT * slot_11(struct StateT * v2195) {
  int v2196 = v2195->timer;
  int v2204 = v2196 + 1;
  v2195->timer = v2204;
  int * v2198 = v2195->regs;
  int v2199 = v2198[15];
  int v2200 = v2198[12];
  int v2209 = (((((int)((unsigned int)v2199 >> 16)) * ((int)((unsigned int)v2200 >> 16))) + ((int)((unsigned int)((v2199 & 65535) * ((int)((unsigned int)v2200 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2199 >> 16)) * (v2200 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2199 & 65535) * (v2200 & 65535)) >> 16)) + (((v2199 & 65535) * ((int)((unsigned int)v2200 >> 16))) & 65535)) + ((((int)((unsigned int)v2199 >> 16)) * (v2200 & 65535)) & 65535)) >> 16));
  v2198[6] = v2209;
  struct StateT * v2202 = slot_12(v2195);
  return v2202;
}

struct StateT * slot_228(struct StateT * v15227) {
  int v15228 = v15227->timer;
  int v15236 = v15228 + 1;
  v15227->timer = v15236;
  int * v15230 = v15227->regs;
  int v15231 = v15230[6];
  int v15232 = v15230[7];
  int v15241 = v15231 + v15232;
  v15230[17] = v15241;
  struct StateT * v15234 = slot_232(v15227);
  return v15234;
}

struct StateT * slot_268(struct StateT * v15975) {
  int v15976 = v15975->timer;
  int v15988 = v15976 + 1;
  v15975->timer = v15988;
  int * v15978 = v15975->regs;
  int v15979 = v15978[6];
  int v15980 = v15978[7];
  bool v15992 = (v15979 ^ -2147483648) < (v15980 ^ -2147483648);
  int v15983;
  if (v15992) {
    v15983 = 1;
  } else {
    v15983 = 0;
  }
  int * v15984 = v15975->regs;
  v15984[6] = v15983;
  struct StateT * v15986 = slot_301(v15975);
  return v15986;
}

struct StateT * slot_199(struct StateT * v14373) {
  int v14374 = v14373->timer;
  int v14382 = v14374 + 1;
  v14373->timer = v14382;
  int * v14376 = v14373->regs;
  int v14377 = v14376[5];
  int v14378 = v14376[17];
  int v14386 = v14377 | v14378;
  v14376[5] = v14386;
  struct StateT * v14380 = slot_188(v14373);
  return v14380;
}

struct StateT * slot_827(struct StateT * v43259) {
  int v43260 = v43259->timer;
  int v43272 = v43260 + 1;
  v43259->timer = v43272;
  int * v43262 = v43259->regs;
  int v43263 = v43262[5];
  int v43264 = v43262[12];
  bool v43276 = (v43263 ^ -2147483648) < (v43264 ^ -2147483648);
  int v43267;
  if (v43276) {
    v43267 = 1;
  } else {
    v43267 = 0;
  }
  int * v43268 = v43259->regs;
  v43268[12] = v43267;
  struct StateT * v43270 = slot_954(v43259);
  return v43270;
}

struct StateT * slot_501(struct StateT * v30371) {
  int v30372 = v30371->timer;
  int v30380 = v30372 + 1;
  v30371->timer = v30380;
  int * v30374 = v30371->regs;
  int v30375 = v30374[6];
  int v30376 = v30374[12];
  int v30384 = v30375 * v30376;
  v30374[12] = v30384;
  struct StateT * v30378 = slot_509(v30371);
  return v30378;
}

struct StateT * slot_136(struct StateT * v8476) {
  int v8477 = v8476->timer;
  int v8485 = v8477 + 1;
  v8476->timer = v8485;
  int * v8479 = v8476->regs;
  int v8480 = v8479[30];
  int v8481 = v8479[28];
  int v8490 = v8480 + v8481;
  v8479[7] = v8490;
  struct StateT * v8483 = slot_138(v8476);
  return v8483;
}

struct StateT * slot_310(struct StateT * v16793) {
  int v16794 = v16793->timer;
  int v16802 = v16794 + 1;
  v16793->timer = v16802;
  int * v16796 = v16793->regs;
  int v16797 = v16796[5];
  int v16798 = v16796[28];
  int v16806 = v16797 + v16798;
  v16796[28] = v16806;
  struct StateT * v16800 = slot_300(v16793);
  return v16800;
}

struct StateT * slot_68(struct StateT * v4692) {
  int * v4693 = v4692->saved_regs;
  int * v4694 = v4692->regs;
  int v4695 = v4694[7];
  v4693[7] = v4695;
  int v4697 = v4692->timer;
  int v4708 = v4697 + 1;
  v4692->timer = v4708;
  int * v4699 = v4692->regs;
  int v4700 = v4699[7];
  int v4710 = (int)((unsigned int)v4700 >> 19);
  v4699[7] = v4710;
  struct StateT * v4702 = slot_69(v4692);
  return v4702;
}

struct StateT * slot_105(struct StateT * v7897) {
  int v7898 = v7897->timer;
  int v7906 = v7898 + 1;
  v7897->timer = v7906;
  int * v7900 = v7897->regs;
  int v7901 = v7900[6];
  int v7902 = v7900[13];
  int v7911 = v7901 * v7902;
  v7900[31] = v7911;
  struct StateT * v7904 = slot_100(v7897);
  return v7904;
}

struct StateT * slot_15(struct StateT * v2277) {
  int v2278 = v2277->timer;
  int v2286 = v2278 + 1;
  v2277->timer = v2286;
  int * v2280 = v2277->regs;
  int v2281 = v2280[15];
  int v2282 = v2280[13];
  int v2291 = (((((int)((unsigned int)v2281 >> 16)) * ((int)((unsigned int)v2282 >> 16))) + ((int)((unsigned int)((v2281 & 65535) * ((int)((unsigned int)v2282 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v2281 >> 16)) * (v2282 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v2281 & 65535) * (v2282 & 65535)) >> 16)) + (((v2281 & 65535) * ((int)((unsigned int)v2282 >> 16))) & 65535)) + ((((int)((unsigned int)v2281 >> 16)) * (v2282 & 65535)) & 65535)) >> 16));
  v2280[30] = v2291;
  struct StateT * v2284 = slot_16(v2277);
  return v2284;
}

struct StateT * slot_222(struct StateT * v15125) {
  int v15126 = v15125->timer;
  int v15134 = v15126 + 1;
  v15125->timer = v15134;
  int * v15128 = v15125->regs;
  int v15129 = v15128[6];
  int v15130 = v15128[13];
  int v15139 = (((((int)((unsigned int)v15129 >> 16)) * ((int)((unsigned int)v15130 >> 16))) + ((int)((unsigned int)((v15129 & 65535) * ((int)((unsigned int)v15130 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v15129 >> 16)) * (v15130 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v15129 & 65535) * (v15130 & 65535)) >> 16)) + (((v15129 & 65535) * ((int)((unsigned int)v15130 >> 16))) & 65535)) + ((((int)((unsigned int)v15129 >> 16)) * (v15130 & 65535)) & 65535)) >> 16));
  v15128[8] = v15139;
  struct StateT * v15132 = slot_241(v15125);
  return v15132;
}

struct StateT * slot_171(struct StateT * v10557) {
  int v10558 = v10557->timer;
  int v10728 = v10558 + 1;
  v10557->timer = v10728;
  int * v10560 = v10557->regs;
  int v10561 = v10560[10];
  int v10562 = v10560[17];
  int * v10563 = v10557->cache_tags;
  int v10733 = (((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2;
  int v10564 = v10563[v10733];
  int v10734 = ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10565 = v10563[v10734];
  int v10735 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2);
  int v10566 = v10563[v10735];
  int v10736 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10567 = v10563[v10736];
  int v10568 = v10557->timer;
  int v10737 = v10568 + ((100 ^ (((~(((v10566 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10566 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10564 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10564 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10565 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10565 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10566 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10566 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10557->timer = v10737;
  bool v10738 = !(((~(((v10564 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10564 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10565 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10565 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v10662;
  if (v10738) {
    int * v10570 = v10557->cache_age;
    int v10740 = ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v10565 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10565 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v10571 = v10570[v10740];
    int v10572 = v10570[v10733];
    int v10741 = v10572 + ((int)((unsigned int)(v10572 - v10571) >> 31));
    v10570[v10733] = v10741;
    int * v10574 = v10557->cache_age;
    int v10575 = v10574[v10734];
    int v10743 = v10575 + ((int)((unsigned int)(v10575 - v10571) >> 31));
    v10574[v10734] = v10743;
    int * v10577 = v10557->cache_age;
    v10577[v10740] = 0;
    v10662 = v10740;
  } else {
    int * v10580 = v10557->cache_age;
    int v10747 = (((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2;
    int v10581 = v10580[v10747];
    int * v10582 = v10557->cache_tags;
    int v10583 = v10582[v10747];
    int v10584 = v10580[v10734];
    int v10585 = v10582[v10734];
    bool v10749 = !(((~(((v10566 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10566 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v10639;
    if (v10749) {
      int * v10586 = v10557->cache_age;
      int v10751 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10567 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v10587 = v10586[v10751];
      int v10588 = v10586[v10735];
      int v10752 = v10588 + ((int)((unsigned int)(v10588 - v10587) >> 31));
      v10586[v10735] = v10752;
      int * v10590 = v10557->cache_age;
      int v10591 = v10590[v10736];
      int v10754 = v10591 + ((int)((unsigned int)(v10591 - v10587) >> 31));
      v10590[v10736] = v10754;
      int * v10593 = v10557->cache_age;
      v10593[v10751] = 0;
      v10639 = v10751;
    } else {
      int * v10596 = v10557->cache_age;
      int v10758 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2);
      int v10597 = v10596[v10758];
      int * v10598 = v10557->cache_tags;
      int v10599 = v10598[v10758];
      int v10600 = v10596[v10736];
      int v10601 = v10598[v10736];
      int * v10602 = v10557->cache_dirty;
      int v10761 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10597 + ((~(((v10599 ^ -1) | (-(v10599 ^ -1))) >> 31)) & 2)) - (v10600 + ((~(((v10601 ^ -1) | (-(v10601 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10603 = v10602[v10761];
      bool v10762 = !(v10603 == 0);
      if (v10762) {
        int * v10604 = v10557->cache_tags;
        int v10605 = v10604[v10761];
        int * v10606 = v10557->cache_vals;
        int v10765 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10597 + ((~(((v10599 ^ -1) | (-(v10599 ^ -1))) >> 31)) & 2)) - (v10600 + ((~(((v10601 ^ -1) | (-(v10601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10607 = v10606[v10765];
        int v10766 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10597 + ((~(((v10599 ^ -1) | (-(v10599 ^ -1))) >> 31)) & 2)) - (v10600 + ((~(((v10601 ^ -1) | (-(v10601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10608 = v10606[v10766];
        int * v10609 = v10557->mem;
        int v10768 = v10605 * 2;
        v10609[v10768] = v10607;
        int * v10611 = v10557->mem;
        int v10771 = (v10605 * 2) + 1;
        v10611[v10771] = v10608;
        ;
      } else {
        ;
      }
      int * v10616 = v10557->mem;
      int v10776 = ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) * 2;
      int v10617 = v10616[v10776];
      int v10777 = (((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) * 2) + 1;
      int v10618 = v10616[v10777];
      int * v10619 = v10557->cache_vals;
      int v10779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10597 + ((~(((v10599 ^ -1) | (-(v10599 ^ -1))) >> 31)) & 2)) - (v10600 + ((~(((v10601 ^ -1) | (-(v10601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10619[v10779] = v10617;
      int * v10621 = v10557->cache_vals;
      int v10782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10597 + ((~(((v10599 ^ -1) | (-(v10599 ^ -1))) >> 31)) & 2)) - (v10600 + ((~(((v10601 ^ -1) | (-(v10601 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10621[v10782] = v10618;
      int * v10623 = v10557->cache_tags;
      int v10785 = (int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1);
      v10623[v10761] = v10785;
      int * v10625 = v10557->cache_dirty;
      v10625[v10761] = 0;
      int * v10627 = v10557->cache_age;
      v10627[v10761] = 1;
      int * v10629 = v10557->cache_age;
      int v10630 = v10629[v10761];
      int v10631 = v10629[v10735];
      int v10791 = v10631 + ((int)((unsigned int)(v10631 - v10630) >> 31));
      v10629[v10735] = v10791;
      int * v10633 = v10557->cache_age;
      int v10634 = v10633[v10736];
      int v10793 = v10634 + ((int)((unsigned int)(v10634 - v10630) >> 31));
      v10633[v10736] = v10793;
      int * v10636 = v10557->cache_age;
      v10636[v10761] = 0;
      v10639 = v10761;
    }
    int * v10640 = v10557->cache_vals;
    int v10796 = v10639 * 2;
    int v10641 = v10640[v10796];
    int v10797 = (v10639 * 2) + 1;
    int v10642 = v10640[v10797];
    int v10798 = (((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10581 + ((~(((v10583 ^ -1) | (-(v10583 ^ -1))) >> 31)) & 2)) - (v10584 + ((~(((v10585 ^ -1) | (-(v10585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10640[v10798] = v10641;
    int * v10644 = v10557->cache_vals;
    int v10801 = ((((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10581 + ((~(((v10583 ^ -1) | (-(v10583 ^ -1))) >> 31)) & 2)) - (v10584 + ((~(((v10585 ^ -1) | (-(v10585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10644[v10801] = v10642;
    int * v10646 = v10557->cache_tags;
    int v10804 = ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10581 + ((~(((v10583 ^ -1) | (-(v10583 ^ -1))) >> 31)) & 2)) - (v10584 + ((~(((v10585 ^ -1) | (-(v10585 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10805 = (int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1);
    v10646[v10804] = v10805;
    int * v10648 = v10557->cache_dirty;
    v10648[v10804] = 0;
    int * v10650 = v10557->cache_age;
    v10650[v10804] = 1;
    int * v10652 = v10557->cache_age;
    int v10653 = v10652[v10804];
    int v10654 = v10652[v10733];
    int v10811 = v10654 + ((int)((unsigned int)(v10654 - v10653) >> 31));
    v10652[v10733] = v10811;
    int * v10656 = v10557->cache_age;
    int v10657 = v10656[v10734];
    int v10813 = v10657 + ((int)((unsigned int)(v10657 - v10653) >> 31));
    v10656[v10734] = v10813;
    int * v10659 = v10557->cache_age;
    v10659[v10804] = 0;
    v10662 = v10804;
  }
  int * v10663 = v10557->cache_vals;
  int v10816 = (v10662 * 2) + (((int)((unsigned int)(v10561 + 16) >> 2)) & 1);
  v10663[v10816] = v10562;
  int * v10665 = v10557->cache_tags;
  int v10666 = v10665[v10735];
  int v10667 = v10665[v10736];
  bool v10819 = !(((~(((v10666 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10666 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10667 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10667 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v10721;
  if (v10819) {
    int * v10668 = v10557->cache_age;
    int v10821 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10667 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))) | (-(v10667 ^ ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v10669 = v10668[v10821];
    int v10670 = v10668[v10735];
    int v10822 = v10670 + ((int)((unsigned int)(v10670 - v10669) >> 31));
    v10668[v10735] = v10822;
    int * v10672 = v10557->cache_age;
    int v10673 = v10672[v10736];
    int v10824 = v10673 + ((int)((unsigned int)(v10673 - v10669) >> 31));
    v10672[v10736] = v10824;
    int * v10675 = v10557->cache_age;
    v10675[v10821] = 0;
    v10721 = v10821;
  } else {
    int * v10678 = v10557->cache_age;
    int v10828 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2);
    int v10679 = v10678[v10828];
    int * v10680 = v10557->cache_tags;
    int v10681 = v10680[v10828];
    int v10682 = v10678[v10736];
    int v10683 = v10680[v10736];
    int * v10684 = v10557->cache_dirty;
    int v10831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10679 + ((~(((v10681 ^ -1) | (-(v10681 ^ -1))) >> 31)) & 2)) - (v10682 + ((~(((v10683 ^ -1) | (-(v10683 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10685 = v10684[v10831];
    bool v10832 = !(v10685 == 0);
    if (v10832) {
      int * v10686 = v10557->cache_tags;
      int v10687 = v10686[v10831];
      int * v10688 = v10557->cache_vals;
      int v10835 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10679 + ((~(((v10681 ^ -1) | (-(v10681 ^ -1))) >> 31)) & 2)) - (v10682 + ((~(((v10683 ^ -1) | (-(v10683 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10689 = v10688[v10835];
      int v10836 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10679 + ((~(((v10681 ^ -1) | (-(v10681 ^ -1))) >> 31)) & 2)) - (v10682 + ((~(((v10683 ^ -1) | (-(v10683 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10690 = v10688[v10836];
      int * v10691 = v10557->mem;
      int v10838 = v10687 * 2;
      v10691[v10838] = v10689;
      int * v10693 = v10557->mem;
      int v10841 = (v10687 * 2) + 1;
      v10693[v10841] = v10690;
      ;
    } else {
      ;
    }
    int * v10698 = v10557->mem;
    int v10846 = ((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) * 2;
    int v10699 = v10698[v10846];
    int v10847 = (((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) * 2) + 1;
    int v10700 = v10698[v10847];
    int * v10701 = v10557->cache_vals;
    int v10849 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10679 + ((~(((v10681 ^ -1) | (-(v10681 ^ -1))) >> 31)) & 2)) - (v10682 + ((~(((v10683 ^ -1) | (-(v10683 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10701[v10849] = v10699;
    int * v10703 = v10557->cache_vals;
    int v10852 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10679 + ((~(((v10681 ^ -1) | (-(v10681 ^ -1))) >> 31)) & 2)) - (v10682 + ((~(((v10683 ^ -1) | (-(v10683 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10703[v10852] = v10700;
    int * v10705 = v10557->cache_tags;
    int v10855 = (int)((unsigned int)((int)((unsigned int)(v10561 + 16) >> 2)) >> 1);
    v10705[v10831] = v10855;
    int * v10707 = v10557->cache_dirty;
    v10707[v10831] = 0;
    int * v10709 = v10557->cache_age;
    v10709[v10831] = 1;
    int * v10711 = v10557->cache_age;
    int v10712 = v10711[v10831];
    int v10713 = v10711[v10735];
    int v10861 = v10713 + ((int)((unsigned int)(v10713 - v10712) >> 31));
    v10711[v10735] = v10861;
    int * v10715 = v10557->cache_age;
    int v10716 = v10715[v10736];
    int v10863 = v10716 + ((int)((unsigned int)(v10716 - v10712) >> 31));
    v10715[v10736] = v10863;
    int * v10718 = v10557->cache_age;
    v10718[v10831] = 0;
    v10721 = v10831;
  }
  int * v10722 = v10557->cache_vals;
  int v10866 = (v10721 * 2) + (((int)((unsigned int)(v10561 + 16) >> 2)) & 1);
  v10722[v10866] = v10562;
  int * v10724 = v10557->cache_dirty;
  v10724[v10721] = 1;
  struct StateT * v10726 = slot_175(v10557);
  return v10726;
}

struct StateT * slot_634(struct StateT * v32911) {
  int v32912 = v32911->timer;
  int v32916 = v32912 + 1;
  v32911->timer = v32916;
  struct StateT * v32914 = slot_615(v32911);
  return v32914;
}

struct StateT * slot_267(struct StateT * v15958) {
  int v15959 = v15958->timer;
  int v15967 = v15959 + 1;
  v15958->timer = v15967;
  int * v15961 = v15958->regs;
  int v15962 = v15961[29];
  int v15963 = v15961[5];
  int v15972 = v15962 + v15963;
  v15961[30] = v15972;
  struct StateT * v15965 = slot_256(v15958);
  return v15965;
}

struct StateT * slot_316(struct StateT * v16941) {
  int v16942 = v16941->timer;
  int v16950 = v16942 + 1;
  v16941->timer = v16950;
  int * v16944 = v16941->regs;
  int v16945 = v16944[5];
  int v16946 = v16944[28];
  int v16954 = v16945 + v16946;
  v16944[28] = v16954;
  struct StateT * v16948 = slot_347(v16941);
  return v16948;
}

struct StateT * slot_39(struct StateT * v4162) {
  int v4163 = v4162->timer;
  int v4171 = v4163 + 1;
  v4162->timer = v4171;
  int * v4165 = v4162->regs;
  int v4166 = v4165[28];
  int v4167 = v4165[12];
  int v4176 = v4166 * v4167;
  v4165[30] = v4176;
  struct StateT * v4169 = slot_40(v4162);
  return v4169;
}

struct StateT * slot_60(struct StateT * v4539) {
  int v4540 = v4539->timer;
  int v4552 = v4540 + 1;
  v4539->timer = v4552;
  int * v4542 = v4539->regs;
  int v4543 = v4542[5];
  int v4544 = v4542[18];
  bool v4556 = (v4543 ^ -2147483648) < (v4544 ^ -2147483648);
  int v4547;
  if (v4556) {
    v4547 = 1;
  } else {
    v4547 = 0;
  }
  int * v4548 = v4539->regs;
  v4548[30] = v4547;
  struct StateT * v4550 = slot_61(v4539);
  return v4550;
}

struct StateT * slot_112(struct StateT * v8015) {
  int v8016 = v8015->timer;
  int v8028 = v8016 + 1;
  v8015->timer = v8028;
  int * v8018 = v8015->regs;
  int v8019 = v8018[29];
  int v8020 = v8018[28];
  bool v8032 = (v8019 ^ -2147483648) < (v8020 ^ -2147483648);
  int v8023;
  if (v8032) {
    v8023 = 1;
  } else {
    v8023 = 0;
  }
  int * v8024 = v8015->regs;
  v8024[7] = v8023;
  struct StateT * v8026 = slot_114(v8015);
  return v8026;
}

struct StateT * slot_256(struct StateT * v15752) {
  int v15753 = v15752->timer;
  int v15761 = v15753 + 1;
  v15752->timer = v15761;
  int * v15755 = v15752->regs;
  int v15756 = v15755[8];
  int v15757 = v15755[6];
  int v15765 = v15756 + v15757;
  v15755[6] = v15765;
  struct StateT * v15759 = slot_260(v15752);
  return v15759;
}

struct StateT * slot_16(struct StateT * v2294) {
  int v2295 = v2294->timer;
  int v2303 = v2295 + 1;
  v2294->timer = v2303;
  int * v2297 = v2294->regs;
  int v2298 = v2297[14];
  int v2299 = v2297[12];
  int v2307 = v2298 * v2299;
  v2297[14] = v2307;
  struct StateT * v2301 = slot_17(v2294);
  return v2301;
}

struct StateT * slot_113(struct StateT * v8040) {
  int v8041 = v8040->timer;
  int v8049 = v8041 + 1;
  v8040->timer = v8049;
  int * v8043 = v8040->regs;
  int v8044 = v8043[6];
  int v8045 = v8043[12];
  int v8053 = v8044 * v8045;
  v8043[6] = v8053;
  struct StateT * v8047 = slot_115(v8040);
  return v8047;
}

struct StateT * slot_191(struct StateT * v12908) {
  int v12909 = v12908->timer;
  int v12917 = v12909 + 1;
  v12908->timer = v12917;
  int * v12911 = v12908->regs;
  int v12912 = v12911[7];
  int v12913 = v12911[28];
  int v12921 = v12912 | v12913;
  v12911[7] = v12921;
  struct StateT * v12915 = slot_194(v12908);
  return v12915;
}

struct StateT * slot_95(struct StateT * v7527) {
  int v7528 = v7527->timer;
  int v7535 = v7528 + 1;
  v7527->timer = v7535;
  int * v7530 = v7527->regs;
  int v7531 = v7530[5];
  int v7538 = v7531 << 13;
  v7530[5] = v7538;
  struct StateT * v7533 = slot_86(v7527);
  return v7533;
}

struct StateT * slot_115(struct StateT * v8072) {
  int v8073 = v8072->timer;
  int v8081 = v8073 + 1;
  v8072->timer = v8081;
  int * v8075 = v8072->regs;
  int v8076 = v8075[28];
  int v8077 = v8075[17];
  int v8086 = v8076 + v8077;
  v8075[29] = v8086;
  struct StateT * v8079 = slot_110(v8072);
  return v8079;
}

struct StateT * slot_210(struct StateT * v14706) {
  int v14707 = v14706->timer;
  int v14715 = v14707 + 1;
  v14706->timer = v14715;
  int * v14709 = v14706->regs;
  int v14710 = v14709[29];
  int v14711 = v14709[12];
  int v14720 = v14710 * v14711;
  v14709[28] = v14720;
  struct StateT * v14713 = slot_214(v14706);
  return v14713;
}

struct StateT * slot_52(struct StateT * v4383) {
  int v4384 = v4383->timer;
  int v4396 = v4384 + 1;
  v4383->timer = v4396;
  int * v4386 = v4383->regs;
  int v4387 = v4386[17];
  int v4388 = v4386[7];
  bool v4400 = (v4387 ^ -2147483648) < (v4388 ^ -2147483648);
  int v4391;
  if (v4400) {
    v4391 = 1;
  } else {
    v4391 = 0;
  }
  int * v4392 = v4383->regs;
  v4392[28] = v4391;
  struct StateT * v4394 = slot_53(v4383);
  return v4394;
}

struct StateT * slot_83(struct StateT * v6047) {
  int v6048 = v6047->timer;
  int v6218 = v6048 + 1;
  v6047->timer = v6218;
  int * v6050 = v6047->regs;
  int v6051 = v6050[10];
  int v6052 = v6050[17];
  int * v6053 = v6047->cache_tags;
  int v6223 = (((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2;
  int v6054 = v6053[v6223];
  int v6224 = ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6055 = v6053[v6224];
  int v6225 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2);
  int v6056 = v6053[v6225];
  int v6226 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6057 = v6053[v6226];
  int v6058 = v6047->timer;
  int v6227 = v6058 + ((100 ^ (((~(((v6056 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6056 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6054 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6054 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6055 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6055 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6056 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6056 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6047->timer = v6227;
  bool v6228 = !(((~(((v6054 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6054 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6055 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6055 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v6152;
  if (v6228) {
    int * v6060 = v6047->cache_age;
    int v6230 = ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v6055 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6055 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v6061 = v6060[v6230];
    int v6062 = v6060[v6223];
    int v6231 = v6062 + ((int)((unsigned int)(v6062 - v6061) >> 31));
    v6060[v6223] = v6231;
    int * v6064 = v6047->cache_age;
    int v6065 = v6064[v6224];
    int v6233 = v6065 + ((int)((unsigned int)(v6065 - v6061) >> 31));
    v6064[v6224] = v6233;
    int * v6067 = v6047->cache_age;
    v6067[v6230] = 0;
    v6152 = v6230;
  } else {
    int * v6070 = v6047->cache_age;
    int v6237 = (((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2;
    int v6071 = v6070[v6237];
    int * v6072 = v6047->cache_tags;
    int v6073 = v6072[v6237];
    int v6074 = v6070[v6224];
    int v6075 = v6072[v6224];
    bool v6239 = !(((~(((v6056 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6056 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v6129;
    if (v6239) {
      int * v6076 = v6047->cache_age;
      int v6241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6057 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v6077 = v6076[v6241];
      int v6078 = v6076[v6225];
      int v6242 = v6078 + ((int)((unsigned int)(v6078 - v6077) >> 31));
      v6076[v6225] = v6242;
      int * v6080 = v6047->cache_age;
      int v6081 = v6080[v6226];
      int v6244 = v6081 + ((int)((unsigned int)(v6081 - v6077) >> 31));
      v6080[v6226] = v6244;
      int * v6083 = v6047->cache_age;
      v6083[v6241] = 0;
      v6129 = v6241;
    } else {
      int * v6086 = v6047->cache_age;
      int v6248 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2);
      int v6087 = v6086[v6248];
      int * v6088 = v6047->cache_tags;
      int v6089 = v6088[v6248];
      int v6090 = v6086[v6226];
      int v6091 = v6088[v6226];
      int * v6092 = v6047->cache_dirty;
      int v6251 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6087 + ((~(((v6089 ^ -1) | (-(v6089 ^ -1))) >> 31)) & 2)) - (v6090 + ((~(((v6091 ^ -1) | (-(v6091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6093 = v6092[v6251];
      bool v6252 = !(v6093 == 0);
      if (v6252) {
        int * v6094 = v6047->cache_tags;
        int v6095 = v6094[v6251];
        int * v6096 = v6047->cache_vals;
        int v6255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6087 + ((~(((v6089 ^ -1) | (-(v6089 ^ -1))) >> 31)) & 2)) - (v6090 + ((~(((v6091 ^ -1) | (-(v6091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6097 = v6096[v6255];
        int v6256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6087 + ((~(((v6089 ^ -1) | (-(v6089 ^ -1))) >> 31)) & 2)) - (v6090 + ((~(((v6091 ^ -1) | (-(v6091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6098 = v6096[v6256];
        int * v6099 = v6047->mem;
        int v6258 = v6095 * 2;
        v6099[v6258] = v6097;
        int * v6101 = v6047->mem;
        int v6261 = (v6095 * 2) + 1;
        v6101[v6261] = v6098;
        ;
      } else {
        ;
      }
      int * v6106 = v6047->mem;
      int v6266 = ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) * 2;
      int v6107 = v6106[v6266];
      int v6267 = (((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) * 2) + 1;
      int v6108 = v6106[v6267];
      int * v6109 = v6047->cache_vals;
      int v6269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6087 + ((~(((v6089 ^ -1) | (-(v6089 ^ -1))) >> 31)) & 2)) - (v6090 + ((~(((v6091 ^ -1) | (-(v6091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6109[v6269] = v6107;
      int * v6111 = v6047->cache_vals;
      int v6272 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6087 + ((~(((v6089 ^ -1) | (-(v6089 ^ -1))) >> 31)) & 2)) - (v6090 + ((~(((v6091 ^ -1) | (-(v6091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6111[v6272] = v6108;
      int * v6113 = v6047->cache_tags;
      int v6275 = (int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1);
      v6113[v6251] = v6275;
      int * v6115 = v6047->cache_dirty;
      v6115[v6251] = 0;
      int * v6117 = v6047->cache_age;
      v6117[v6251] = 1;
      int * v6119 = v6047->cache_age;
      int v6120 = v6119[v6251];
      int v6121 = v6119[v6225];
      int v6281 = v6121 + ((int)((unsigned int)(v6121 - v6120) >> 31));
      v6119[v6225] = v6281;
      int * v6123 = v6047->cache_age;
      int v6124 = v6123[v6226];
      int v6283 = v6124 + ((int)((unsigned int)(v6124 - v6120) >> 31));
      v6123[v6226] = v6283;
      int * v6126 = v6047->cache_age;
      v6126[v6251] = 0;
      v6129 = v6251;
    }
    int * v6130 = v6047->cache_vals;
    int v6286 = v6129 * 2;
    int v6131 = v6130[v6286];
    int v6287 = (v6129 * 2) + 1;
    int v6132 = v6130[v6287];
    int v6288 = (((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6071 + ((~(((v6073 ^ -1) | (-(v6073 ^ -1))) >> 31)) & 2)) - (v6074 + ((~(((v6075 ^ -1) | (-(v6075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6130[v6288] = v6131;
    int * v6134 = v6047->cache_vals;
    int v6291 = ((((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6071 + ((~(((v6073 ^ -1) | (-(v6073 ^ -1))) >> 31)) & 2)) - (v6074 + ((~(((v6075 ^ -1) | (-(v6075 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6134[v6291] = v6132;
    int * v6136 = v6047->cache_tags;
    int v6294 = ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6071 + ((~(((v6073 ^ -1) | (-(v6073 ^ -1))) >> 31)) & 2)) - (v6074 + ((~(((v6075 ^ -1) | (-(v6075 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6295 = (int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1);
    v6136[v6294] = v6295;
    int * v6138 = v6047->cache_dirty;
    v6138[v6294] = 0;
    int * v6140 = v6047->cache_age;
    v6140[v6294] = 1;
    int * v6142 = v6047->cache_age;
    int v6143 = v6142[v6294];
    int v6144 = v6142[v6223];
    int v6301 = v6144 + ((int)((unsigned int)(v6144 - v6143) >> 31));
    v6142[v6223] = v6301;
    int * v6146 = v6047->cache_age;
    int v6147 = v6146[v6224];
    int v6303 = v6147 + ((int)((unsigned int)(v6147 - v6143) >> 31));
    v6146[v6224] = v6303;
    int * v6149 = v6047->cache_age;
    v6149[v6294] = 0;
    v6152 = v6294;
  }
  int * v6153 = v6047->cache_vals;
  int v6306 = (v6152 * 2) + (((int)((unsigned int)(v6051 + 8) >> 2)) & 1);
  v6153[v6306] = v6052;
  int * v6155 = v6047->cache_tags;
  int v6156 = v6155[v6225];
  int v6157 = v6155[v6226];
  bool v6309 = !(((~(((v6156 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6156 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6157 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6157 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v6211;
  if (v6309) {
    int * v6158 = v6047->cache_age;
    int v6311 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6157 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))) | (-(v6157 ^ ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v6159 = v6158[v6311];
    int v6160 = v6158[v6225];
    int v6312 = v6160 + ((int)((unsigned int)(v6160 - v6159) >> 31));
    v6158[v6225] = v6312;
    int * v6162 = v6047->cache_age;
    int v6163 = v6162[v6226];
    int v6314 = v6163 + ((int)((unsigned int)(v6163 - v6159) >> 31));
    v6162[v6226] = v6314;
    int * v6165 = v6047->cache_age;
    v6165[v6311] = 0;
    v6211 = v6311;
  } else {
    int * v6168 = v6047->cache_age;
    int v6318 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2);
    int v6169 = v6168[v6318];
    int * v6170 = v6047->cache_tags;
    int v6171 = v6170[v6318];
    int v6172 = v6168[v6226];
    int v6173 = v6170[v6226];
    int * v6174 = v6047->cache_dirty;
    int v6321 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6175 = v6174[v6321];
    bool v6322 = !(v6175 == 0);
    if (v6322) {
      int * v6176 = v6047->cache_tags;
      int v6177 = v6176[v6321];
      int * v6178 = v6047->cache_vals;
      int v6325 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6179 = v6178[v6325];
      int v6326 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6180 = v6178[v6326];
      int * v6181 = v6047->mem;
      int v6328 = v6177 * 2;
      v6181[v6328] = v6179;
      int * v6183 = v6047->mem;
      int v6331 = (v6177 * 2) + 1;
      v6183[v6331] = v6180;
      ;
    } else {
      ;
    }
    int * v6188 = v6047->mem;
    int v6336 = ((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) * 2;
    int v6189 = v6188[v6336];
    int v6337 = (((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) * 2) + 1;
    int v6190 = v6188[v6337];
    int * v6191 = v6047->cache_vals;
    int v6339 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6191[v6339] = v6189;
    int * v6193 = v6047->cache_vals;
    int v6342 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6169 + ((~(((v6171 ^ -1) | (-(v6171 ^ -1))) >> 31)) & 2)) - (v6172 + ((~(((v6173 ^ -1) | (-(v6173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6193[v6342] = v6190;
    int * v6195 = v6047->cache_tags;
    int v6345 = (int)((unsigned int)((int)((unsigned int)(v6051 + 8) >> 2)) >> 1);
    v6195[v6321] = v6345;
    int * v6197 = v6047->cache_dirty;
    v6197[v6321] = 0;
    int * v6199 = v6047->cache_age;
    v6199[v6321] = 1;
    int * v6201 = v6047->cache_age;
    int v6202 = v6201[v6321];
    int v6203 = v6201[v6225];
    int v6351 = v6203 + ((int)((unsigned int)(v6203 - v6202) >> 31));
    v6201[v6225] = v6351;
    int * v6205 = v6047->cache_age;
    int v6206 = v6205[v6226];
    int v6353 = v6206 + ((int)((unsigned int)(v6206 - v6202) >> 31));
    v6205[v6226] = v6353;
    int * v6208 = v6047->cache_age;
    v6208[v6321] = 0;
    v6211 = v6321;
  }
  int * v6212 = v6047->cache_vals;
  int v6356 = (v6211 * 2) + (((int)((unsigned int)(v6051 + 8) >> 2)) & 1);
  v6212[v6356] = v6052;
  int * v6214 = v6047->cache_dirty;
  v6214[v6211] = 1;
  struct StateT * v6216 = slot_74(v6047);
  return v6216;
}

struct StateT * slot_73(struct StateT * v5127) {
  int v5128 = v5127->timer;
  int v5136 = v5128 + 1;
  v5127->timer = v5136;
  int * v5130 = v5127->regs;
  int v5131 = v5130[7];
  int v5132 = v5130[16];
  int v5141 = v5131 & v5132;
  v5130[29] = v5141;
  struct StateT * v5134 = slot_75(v5127);
  return v5134;
}

struct StateT * slot_187(struct StateT * v12619) {
  int v12620 = v12619->timer;
  int v12730 = v12620 + 1;
  v12619->timer = v12730;
  int * v12622 = v12619->regs;
  int v12623 = v12622[11];
  int * v12624 = v12619->cache_tags;
  int v12734 = (((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2;
  int v12625 = v12624[v12734];
  int v12735 = ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12626 = v12624[v12735];
  int v12736 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2);
  int v12627 = v12624[v12736];
  int v12737 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12628 = v12624[v12737];
  int v12629 = v12619->timer;
  int v12738 = v12629 + ((100 ^ (((~(((v12627 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12627 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12625 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12625 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12626 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12626 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12627 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12627 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12619->timer = v12738;
  int * v12631 = v12619->cache_vals;
  bool v12739 = !(((~(((v12625 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12625 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12626 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12626 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v12724;
  if (v12739) {
    int * v12632 = v12619->cache_age;
    int v12741 = ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v12626 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12626 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v12633 = v12632[v12741];
    int v12634 = v12632[v12734];
    int v12742 = v12634 + ((int)((unsigned int)(v12634 - v12633) >> 31));
    v12632[v12734] = v12742;
    int * v12636 = v12619->cache_age;
    int v12637 = v12636[v12735];
    int v12744 = v12637 + ((int)((unsigned int)(v12637 - v12633) >> 31));
    v12636[v12735] = v12744;
    int * v12639 = v12619->cache_age;
    v12639[v12741] = 0;
    v12724 = v12741;
  } else {
    int * v12642 = v12619->cache_age;
    int v12748 = (((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2;
    int v12643 = v12642[v12748];
    int * v12644 = v12619->cache_tags;
    int v12645 = v12644[v12748];
    int v12646 = v12642[v12735];
    int v12647 = v12644[v12735];
    bool v12750 = !(((~(((v12627 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12627 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v12701;
    if (v12750) {
      int * v12648 = v12619->cache_age;
      int v12752 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))) | (-(v12628 ^ ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v12649 = v12648[v12752];
      int v12650 = v12648[v12736];
      int v12753 = v12650 + ((int)((unsigned int)(v12650 - v12649) >> 31));
      v12648[v12736] = v12753;
      int * v12652 = v12619->cache_age;
      int v12653 = v12652[v12737];
      int v12755 = v12653 + ((int)((unsigned int)(v12653 - v12649) >> 31));
      v12652[v12737] = v12755;
      int * v12655 = v12619->cache_age;
      v12655[v12752] = 0;
      v12701 = v12752;
    } else {
      int * v12658 = v12619->cache_age;
      int v12759 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2);
      int v12659 = v12658[v12759];
      int * v12660 = v12619->cache_tags;
      int v12661 = v12660[v12759];
      int v12662 = v12658[v12737];
      int v12663 = v12660[v12737];
      int * v12664 = v12619->cache_dirty;
      int v12762 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12659 + ((~(((v12661 ^ -1) | (-(v12661 ^ -1))) >> 31)) & 2)) - (v12662 + ((~(((v12663 ^ -1) | (-(v12663 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12665 = v12664[v12762];
      bool v12763 = !(v12665 == 0);
      if (v12763) {
        int * v12666 = v12619->cache_tags;
        int v12667 = v12666[v12762];
        int * v12668 = v12619->cache_vals;
        int v12766 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12659 + ((~(((v12661 ^ -1) | (-(v12661 ^ -1))) >> 31)) & 2)) - (v12662 + ((~(((v12663 ^ -1) | (-(v12663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12669 = v12668[v12766];
        int v12767 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12659 + ((~(((v12661 ^ -1) | (-(v12661 ^ -1))) >> 31)) & 2)) - (v12662 + ((~(((v12663 ^ -1) | (-(v12663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12670 = v12668[v12767];
        int * v12671 = v12619->mem;
        int v12769 = v12667 * 2;
        v12671[v12769] = v12669;
        int * v12673 = v12619->mem;
        int v12772 = (v12667 * 2) + 1;
        v12673[v12772] = v12670;
        ;
      } else {
        ;
      }
      int * v12678 = v12619->mem;
      int v12777 = ((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) * 2;
      int v12679 = v12678[v12777];
      int v12778 = (((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) * 2) + 1;
      int v12680 = v12678[v12778];
      int * v12681 = v12619->cache_vals;
      int v12780 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12659 + ((~(((v12661 ^ -1) | (-(v12661 ^ -1))) >> 31)) & 2)) - (v12662 + ((~(((v12663 ^ -1) | (-(v12663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12681[v12780] = v12679;
      int * v12683 = v12619->cache_vals;
      int v12783 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12659 + ((~(((v12661 ^ -1) | (-(v12661 ^ -1))) >> 31)) & 2)) - (v12662 + ((~(((v12663 ^ -1) | (-(v12663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12683[v12783] = v12680;
      int * v12685 = v12619->cache_tags;
      int v12786 = (int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1);
      v12685[v12762] = v12786;
      int * v12687 = v12619->cache_dirty;
      v12687[v12762] = 0;
      int * v12689 = v12619->cache_age;
      v12689[v12762] = 1;
      int * v12691 = v12619->cache_age;
      int v12692 = v12691[v12762];
      int v12693 = v12691[v12736];
      int v12792 = v12693 + ((int)((unsigned int)(v12693 - v12692) >> 31));
      v12691[v12736] = v12792;
      int * v12695 = v12619->cache_age;
      int v12696 = v12695[v12737];
      int v12794 = v12696 + ((int)((unsigned int)(v12696 - v12692) >> 31));
      v12695[v12737] = v12794;
      int * v12698 = v12619->cache_age;
      v12698[v12762] = 0;
      v12701 = v12762;
    }
    int * v12702 = v12619->cache_vals;
    int v12797 = v12701 * 2;
    int v12703 = v12702[v12797];
    int v12798 = (v12701 * 2) + 1;
    int v12704 = v12702[v12798];
    int v12799 = (((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12643 + ((~(((v12645 ^ -1) | (-(v12645 ^ -1))) >> 31)) & 2)) - (v12646 + ((~(((v12647 ^ -1) | (-(v12647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12702[v12799] = v12703;
    int * v12706 = v12619->cache_vals;
    int v12802 = ((((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12643 + ((~(((v12645 ^ -1) | (-(v12645 ^ -1))) >> 31)) & 2)) - (v12646 + ((~(((v12647 ^ -1) | (-(v12647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12706[v12802] = v12704;
    int * v12708 = v12619->cache_tags;
    int v12805 = ((((int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12643 + ((~(((v12645 ^ -1) | (-(v12645 ^ -1))) >> 31)) & 2)) - (v12646 + ((~(((v12647 ^ -1) | (-(v12647 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12806 = (int)((unsigned int)((int)((unsigned int)(v12623 + 28) >> 2)) >> 1);
    v12708[v12805] = v12806;
    int * v12710 = v12619->cache_dirty;
    v12710[v12805] = 0;
    int * v12712 = v12619->cache_age;
    v12712[v12805] = 1;
    int * v12714 = v12619->cache_age;
    int v12715 = v12714[v12805];
    int v12716 = v12714[v12734];
    int v12812 = v12716 + ((int)((unsigned int)(v12716 - v12715) >> 31));
    v12714[v12734] = v12812;
    int * v12718 = v12619->cache_age;
    int v12719 = v12718[v12735];
    int v12814 = v12719 + ((int)((unsigned int)(v12719 - v12715) >> 31));
    v12718[v12735] = v12814;
    int * v12721 = v12619->cache_age;
    v12721[v12805] = 0;
    v12724 = v12805;
  }
  int v12817 = (v12724 * 2) + (((int)((unsigned int)(v12623 + 28) >> 2)) & 1);
  int v12725 = v12631[v12817];
  int * v12726 = v12619->regs;
  v12726[29] = v12725;
  struct StateT * v12728 = slot_191(v12619);
  return v12728;
}

struct StateT * slot_178(struct StateT * v12385) {
  int v12386 = v12385->timer;
  int v12393 = v12386 + 1;
  v12385->timer = v12393;
  int * v12388 = v12385->regs;
  int v12389 = v12388[28];
  int v12397 = (int)((unsigned int)v12389 >> 19);
  v12388[17] = v12397;
  struct StateT * v12391 = slot_184(v12385);
  return v12391;
}

struct StateT * slot_46(struct StateT * v4277) {
  int v4278 = v4277->timer;
  int v4286 = v4278 + 1;
  v4277->timer = v4286;
  int * v4280 = v4277->regs;
  int v4281 = v4280[28];
  int v4282 = v4280[13];
  int v4291 = (((((int)((unsigned int)v4281 >> 16)) * ((int)((unsigned int)v4282 >> 16))) + ((int)((unsigned int)((v4281 & 65535) * ((int)((unsigned int)v4282 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4281 >> 16)) * (v4282 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4281 & 65535) * (v4282 & 65535)) >> 16)) + (((v4281 & 65535) * ((int)((unsigned int)v4282 >> 16))) & 65535)) + ((((int)((unsigned int)v4281 >> 16)) * (v4282 & 65535)) & 65535)) >> 16));
  v4280[19] = v4291;
  struct StateT * v4284 = slot_47(v4277);
  return v4284;
}

struct StateT * slot_20(struct StateT * v2367) {
  int v2368 = v2367->timer;
  int v2376 = v2368 + 1;
  v2367->timer = v2376;
  int * v2370 = v2367->regs;
  int v2371 = v2370[6];
  int v2372 = v2370[15];
  int v2380 = v2371 + v2372;
  v2370[6] = v2380;
  struct StateT * v2374 = slot_21(v2367);
  return v2374;
}

struct StateT * slot_61(struct StateT * v4564) {
  int v4565 = v4564->timer;
  int v4573 = v4565 + 1;
  v4564->timer = v4573;
  int * v4567 = v4564->regs;
  int v4568 = v4567[19];
  int v4569 = v4567[6];
  int v4577 = v4568 + v4569;
  v4567[6] = v4577;
  struct StateT * v4571 = slot_62(v4564);
  return v4571;
}

struct StateT * slot_30(struct StateT * v4067) {
  int v4068 = v4067->timer;
  int v4076 = v4068 + 1;
  v4067->timer = v4076;
  int * v4070 = v4067->regs;
  int v4071 = v4070[29];
  int v4072 = v4070[5];
  int v4081 = v4071 + v4072;
  v4070[31] = v4081;
  struct StateT * v4074 = slot_31(v4067);
  return v4074;
}

struct StateT * slot_300(struct StateT * v16579) {
  int * v16580 = v16579->saved_regs;
  int * v16581 = v16579->regs;
  int v16582 = v16581[29];
  v16580[29] = v16582;
  int v16584 = v16579->timer;
  int v16596 = v16584 + 1;
  v16579->timer = v16596;
  int * v16586 = v16579->regs;
  int v16587 = v16586[7];
  int v16588 = v16586[16];
  int v16600 = v16587 & v16588;
  v16586[29] = v16600;
  struct StateT * v16590 = slot_304(v16579);
  return v16590;
}

struct StateT * slot_309(struct StateT * v16776) {
  int v16777 = v16776->timer;
  int v16785 = v16777 + 1;
  v16776->timer = v16785;
  int * v16779 = v16776->regs;
  int v16780 = v16779[30];
  int v16781 = v16779[28];
  int v16790 = v16780 + v16781;
  v16779[7] = v16790;
  struct StateT * v16783 = slot_299(v16776);
  return v16783;
}

struct StateT * slot_6(struct StateT * v1961) {
  int v1962 = v1961->timer;
  int v2072 = v1962 + 1;
  v1961->timer = v2072;
  int * v1964 = v1961->regs;
  int v1965 = v1964[11];
  int * v1966 = v1961->cache_tags;
  int v2076 = (((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1967 = v1966[v2076];
  int v2077 = ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1968 = v1966[v2077];
  int v2078 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1969 = v1966[v2078];
  int v2079 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1970 = v1966[v2079];
  int v1971 = v1961->timer;
  int v2080 = v1971 + ((100 ^ (((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1961->timer = v2080;
  int * v1973 = v1961->cache_vals;
  bool v2081 = !(((~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2066;
  if (v2081) {
    int * v1974 = v1961->cache_age;
    int v2083 = ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1975 = v1974[v2083];
    int v1976 = v1974[v2076];
    int v2084 = v1976 + ((int)((unsigned int)(v1976 - v1975) >> 31));
    v1974[v2076] = v2084;
    int * v1978 = v1961->cache_age;
    int v1979 = v1978[v2077];
    int v2086 = v1979 + ((int)((unsigned int)(v1979 - v1975) >> 31));
    v1978[v2077] = v2086;
    int * v1981 = v1961->cache_age;
    v1981[v2083] = 0;
    v2066 = v2083;
  } else {
    int * v1984 = v1961->cache_age;
    int v2090 = (((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1985 = v1984[v2090];
    int * v1986 = v1961->cache_tags;
    int v1987 = v1986[v2090];
    int v1988 = v1984[v2077];
    int v1989 = v1986[v2077];
    bool v2092 = !(((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2043;
    if (v2092) {
      int * v1990 = v1961->cache_age;
      int v2094 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))) | (-(v1970 ^ ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1991 = v1990[v2094];
      int v1992 = v1990[v2078];
      int v2095 = v1992 + ((int)((unsigned int)(v1992 - v1991) >> 31));
      v1990[v2078] = v2095;
      int * v1994 = v1961->cache_age;
      int v1995 = v1994[v2079];
      int v2097 = v1995 + ((int)((unsigned int)(v1995 - v1991) >> 31));
      v1994[v2079] = v2097;
      int * v1997 = v1961->cache_age;
      v1997[v2094] = 0;
      v2043 = v2094;
    } else {
      int * v2000 = v1961->cache_age;
      int v2101 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2001 = v2000[v2101];
      int * v2002 = v1961->cache_tags;
      int v2003 = v2002[v2101];
      int v2004 = v2000[v2079];
      int v2005 = v2002[v2079];
      int * v2006 = v1961->cache_dirty;
      int v2104 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2007 = v2006[v2104];
      bool v2105 = !(v2007 == 0);
      if (v2105) {
        int * v2008 = v1961->cache_tags;
        int v2009 = v2008[v2104];
        int * v2010 = v1961->cache_vals;
        int v2108 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2011 = v2010[v2108];
        int v2109 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2012 = v2010[v2109];
        int * v2013 = v1961->mem;
        int v2111 = v2009 * 2;
        v2013[v2111] = v2011;
        int * v2015 = v1961->mem;
        int v2114 = (v2009 * 2) + 1;
        v2015[v2114] = v2012;
        ;
      } else {
        ;
      }
      int * v2020 = v1961->mem;
      int v2119 = ((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) * 2;
      int v2021 = v2020[v2119];
      int v2120 = (((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2022 = v2020[v2120];
      int * v2023 = v1961->cache_vals;
      int v2122 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2023[v2122] = v2021;
      int * v2025 = v1961->cache_vals;
      int v2125 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2001 + ((~(((v2003 ^ -1) | (-(v2003 ^ -1))) >> 31)) & 2)) - (v2004 + ((~(((v2005 ^ -1) | (-(v2005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2025[v2125] = v2022;
      int * v2027 = v1961->cache_tags;
      int v2128 = (int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1);
      v2027[v2104] = v2128;
      int * v2029 = v1961->cache_dirty;
      v2029[v2104] = 0;
      int * v2031 = v1961->cache_age;
      v2031[v2104] = 1;
      int * v2033 = v1961->cache_age;
      int v2034 = v2033[v2104];
      int v2035 = v2033[v2078];
      int v2134 = v2035 + ((int)((unsigned int)(v2035 - v2034) >> 31));
      v2033[v2078] = v2134;
      int * v2037 = v1961->cache_age;
      int v2038 = v2037[v2079];
      int v2136 = v2038 + ((int)((unsigned int)(v2038 - v2034) >> 31));
      v2037[v2079] = v2136;
      int * v2040 = v1961->cache_age;
      v2040[v2104] = 0;
      v2043 = v2104;
    }
    int * v2044 = v1961->cache_vals;
    int v2139 = v2043 * 2;
    int v2045 = v2044[v2139];
    int v2140 = (v2043 * 2) + 1;
    int v2046 = v2044[v2140];
    int v2141 = (((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1985 + ((~(((v1987 ^ -1) | (-(v1987 ^ -1))) >> 31)) & 2)) - (v1988 + ((~(((v1989 ^ -1) | (-(v1989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2044[v2141] = v2045;
    int * v2048 = v1961->cache_vals;
    int v2144 = ((((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1985 + ((~(((v1987 ^ -1) | (-(v1987 ^ -1))) >> 31)) & 2)) - (v1988 + ((~(((v1989 ^ -1) | (-(v1989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2048[v2144] = v2046;
    int * v2050 = v1961->cache_tags;
    int v2147 = ((((int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1985 + ((~(((v1987 ^ -1) | (-(v1987 ^ -1))) >> 31)) & 2)) - (v1988 + ((~(((v1989 ^ -1) | (-(v1989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2148 = (int)((unsigned int)((int)((unsigned int)(v1965 + 4) >> 2)) >> 1);
    v2050[v2147] = v2148;
    int * v2052 = v1961->cache_dirty;
    v2052[v2147] = 0;
    int * v2054 = v1961->cache_age;
    v2054[v2147] = 1;
    int * v2056 = v1961->cache_age;
    int v2057 = v2056[v2147];
    int v2058 = v2056[v2076];
    int v2154 = v2058 + ((int)((unsigned int)(v2058 - v2057) >> 31));
    v2056[v2076] = v2154;
    int * v2060 = v1961->cache_age;
    int v2061 = v2060[v2077];
    int v2156 = v2061 + ((int)((unsigned int)(v2061 - v2057) >> 31));
    v2060[v2077] = v2156;
    int * v2063 = v1961->cache_age;
    v2063[v2147] = 0;
    v2066 = v2147;
  }
  int v2159 = (v2066 * 2) + (((int)((unsigned int)(v1965 + 4) >> 2)) & 1);
  int v2067 = v1973[v2159];
  int * v2068 = v1961->regs;
  v2068[15] = v2067;
  struct StateT * v2070 = slot_7(v1961);
  return v2070;
}

struct StateT * slot_37(struct StateT * v4129) {
  int v4130 = v4129->timer;
  int v4138 = v4130 + 1;
  v4129->timer = v4138;
  int * v4132 = v4129->regs;
  int v4133 = v4132[17];
  int v4134 = v4132[31];
  int v4142 = v4133 | v4134;
  v4132[17] = v4142;
  struct StateT * v4136 = slot_38(v4129);
  return v4136;
}

struct StateT * slot_114(struct StateT * v8056) {
  int v8057 = v8056->timer;
  int v8065 = v8057 + 1;
  v8056->timer = v8065;
  int * v8059 = v8056->regs;
  int v8060 = v8059[31];
  int v8061 = v8059[29];
  int v8069 = v8060 + v8061;
  v8059[29] = v8069;
  struct StateT * v8063 = slot_123(v8056);
  return v8063;
}

struct StateT * slot_101(struct StateT * v7829) {
  int v7830 = v7829->timer;
  int v7838 = v7830 + 1;
  v7829->timer = v7838;
  int * v7832 = v7829->regs;
  int v7833 = v7832[29];
  int v7834 = v7832[12];
  int v7843 = v7833 * v7834;
  v7832[28] = v7843;
  struct StateT * v7836 = slot_96(v7829);
  return v7836;
}

struct StateT * slot_93(struct StateT * v7478) {
  int v7479 = v7478->timer;
  int v7487 = v7479 + 1;
  v7478->timer = v7487;
  int * v7481 = v7478->regs;
  int v7482 = v7481[7];
  int v7483 = v7481[28];
  int v7491 = v7482 | v7483;
  v7481[7] = v7491;
  struct StateT * v7485 = slot_95(v7478);
  return v7485;
}

struct StateT * slot_88(struct StateT * v7464) {
  int v7465 = v7464->timer;
  int v7472 = v7465 + 1;
  v7464->timer = v7472;
  int * v7467 = v7464->regs;
  int v7468 = v7467[28];
  int v7475 = v7468 << 13;
  v7467[28] = v7475;
  struct StateT * v7470 = slot_89(v7464);
  return v7470;
}

struct StateT * slot_96(struct StateT * v7541) {
  int v7542 = v7541->timer;
  int v7550 = v7542 + 1;
  v7541->timer = v7550;
  int * v7544 = v7541->regs;
  int v7545 = v7544[29];
  int v7546 = v7544[12];
  int v7555 = (((((int)((unsigned int)v7545 >> 16)) * ((int)((unsigned int)v7546 >> 16))) + ((int)((unsigned int)((v7545 & 65535) * ((int)((unsigned int)v7546 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v7545 >> 16)) * (v7546 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v7545 & 65535) * (v7546 & 65535)) >> 16)) + (((v7545 & 65535) * ((int)((unsigned int)v7546 >> 16))) & 65535)) + ((((int)((unsigned int)v7545 >> 16)) * (v7546 & 65535)) & 65535)) >> 16));
  v7544[30] = v7555;
  struct StateT * v7548 = slot_105(v7541);
  return v7548;
}

struct StateT * slot_408(struct StateT * v28619) {
  int v28620 = v28619->timer;
  int v28730 = v28620 + 1;
  v28619->timer = v28730;
  int * v28622 = v28619->regs;
  int v28623 = v28622[11];
  int * v28624 = v28619->cache_tags;
  int v28734 = (((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2;
  int v28625 = v28624[v28734];
  int v28735 = ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v28626 = v28624[v28735];
  int v28736 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2);
  int v28627 = v28624[v28736];
  int v28737 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v28628 = v28624[v28737];
  int v28629 = v28619->timer;
  int v28738 = v28629 + ((100 ^ (((~(((v28627 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28627 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v28625 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28625 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v28626 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28626 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28627 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28627 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v28619->timer = v28738;
  int * v28631 = v28619->cache_vals;
  bool v28739 = !(((~(((v28625 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28625 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v28626 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28626 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v28724;
  if (v28739) {
    int * v28632 = v28619->cache_age;
    int v28741 = ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v28626 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28626 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v28633 = v28632[v28741];
    int v28634 = v28632[v28734];
    int v28742 = v28634 + ((int)((unsigned int)(v28634 - v28633) >> 31));
    v28632[v28734] = v28742;
    int * v28636 = v28619->cache_age;
    int v28637 = v28636[v28735];
    int v28744 = v28637 + ((int)((unsigned int)(v28637 - v28633) >> 31));
    v28636[v28735] = v28744;
    int * v28639 = v28619->cache_age;
    v28639[v28741] = 0;
    v28724 = v28741;
  } else {
    int * v28642 = v28619->cache_age;
    int v28748 = (((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2;
    int v28643 = v28642[v28748];
    int * v28644 = v28619->cache_tags;
    int v28645 = v28644[v28748];
    int v28646 = v28642[v28735];
    int v28647 = v28644[v28735];
    bool v28750 = !(((~(((v28627 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28627 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v28701;
    if (v28750) {
      int * v28648 = v28619->cache_age;
      int v28752 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))) | (-(v28628 ^ ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v28649 = v28648[v28752];
      int v28650 = v28648[v28736];
      int v28753 = v28650 + ((int)((unsigned int)(v28650 - v28649) >> 31));
      v28648[v28736] = v28753;
      int * v28652 = v28619->cache_age;
      int v28653 = v28652[v28737];
      int v28755 = v28653 + ((int)((unsigned int)(v28653 - v28649) >> 31));
      v28652[v28737] = v28755;
      int * v28655 = v28619->cache_age;
      v28655[v28752] = 0;
      v28701 = v28752;
    } else {
      int * v28658 = v28619->cache_age;
      int v28759 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2);
      int v28659 = v28658[v28759];
      int * v28660 = v28619->cache_tags;
      int v28661 = v28660[v28759];
      int v28662 = v28658[v28737];
      int v28663 = v28660[v28737];
      int * v28664 = v28619->cache_dirty;
      int v28762 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v28659 + ((~(((v28661 ^ -1) | (-(v28661 ^ -1))) >> 31)) & 2)) - (v28662 + ((~(((v28663 ^ -1) | (-(v28663 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v28665 = v28664[v28762];
      bool v28763 = !(v28665 == 0);
      if (v28763) {
        int * v28666 = v28619->cache_tags;
        int v28667 = v28666[v28762];
        int * v28668 = v28619->cache_vals;
        int v28766 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v28659 + ((~(((v28661 ^ -1) | (-(v28661 ^ -1))) >> 31)) & 2)) - (v28662 + ((~(((v28663 ^ -1) | (-(v28663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v28669 = v28668[v28766];
        int v28767 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v28659 + ((~(((v28661 ^ -1) | (-(v28661 ^ -1))) >> 31)) & 2)) - (v28662 + ((~(((v28663 ^ -1) | (-(v28663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v28670 = v28668[v28767];
        int * v28671 = v28619->mem;
        int v28769 = v28667 * 2;
        v28671[v28769] = v28669;
        int * v28673 = v28619->mem;
        int v28772 = (v28667 * 2) + 1;
        v28673[v28772] = v28670;
        ;
      } else {
        ;
      }
      int * v28678 = v28619->mem;
      int v28777 = ((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) * 2;
      int v28679 = v28678[v28777];
      int v28778 = (((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) * 2) + 1;
      int v28680 = v28678[v28778];
      int * v28681 = v28619->cache_vals;
      int v28780 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v28659 + ((~(((v28661 ^ -1) | (-(v28661 ^ -1))) >> 31)) & 2)) - (v28662 + ((~(((v28663 ^ -1) | (-(v28663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v28681[v28780] = v28679;
      int * v28683 = v28619->cache_vals;
      int v28783 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v28659 + ((~(((v28661 ^ -1) | (-(v28661 ^ -1))) >> 31)) & 2)) - (v28662 + ((~(((v28663 ^ -1) | (-(v28663 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v28683[v28783] = v28680;
      int * v28685 = v28619->cache_tags;
      int v28786 = (int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1);
      v28685[v28762] = v28786;
      int * v28687 = v28619->cache_dirty;
      v28687[v28762] = 0;
      int * v28689 = v28619->cache_age;
      v28689[v28762] = 1;
      int * v28691 = v28619->cache_age;
      int v28692 = v28691[v28762];
      int v28693 = v28691[v28736];
      int v28792 = v28693 + ((int)((unsigned int)(v28693 - v28692) >> 31));
      v28691[v28736] = v28792;
      int * v28695 = v28619->cache_age;
      int v28696 = v28695[v28737];
      int v28794 = v28696 + ((int)((unsigned int)(v28696 - v28692) >> 31));
      v28695[v28737] = v28794;
      int * v28698 = v28619->cache_age;
      v28698[v28762] = 0;
      v28701 = v28762;
    }
    int * v28702 = v28619->cache_vals;
    int v28797 = v28701 * 2;
    int v28703 = v28702[v28797];
    int v28798 = (v28701 * 2) + 1;
    int v28704 = v28702[v28798];
    int v28799 = (((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v28643 + ((~(((v28645 ^ -1) | (-(v28645 ^ -1))) >> 31)) & 2)) - (v28646 + ((~(((v28647 ^ -1) | (-(v28647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v28702[v28799] = v28703;
    int * v28706 = v28619->cache_vals;
    int v28802 = ((((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v28643 + ((~(((v28645 ^ -1) | (-(v28645 ^ -1))) >> 31)) & 2)) - (v28646 + ((~(((v28647 ^ -1) | (-(v28647 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v28706[v28802] = v28704;
    int * v28708 = v28619->cache_tags;
    int v28805 = ((((int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v28643 + ((~(((v28645 ^ -1) | (-(v28645 ^ -1))) >> 31)) & 2)) - (v28646 + ((~(((v28647 ^ -1) | (-(v28647 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v28806 = (int)((unsigned int)((int)((unsigned int)(v28623 + 32) >> 2)) >> 1);
    v28708[v28805] = v28806;
    int * v28710 = v28619->cache_dirty;
    v28710[v28805] = 0;
    int * v28712 = v28619->cache_age;
    v28712[v28805] = 1;
    int * v28714 = v28619->cache_age;
    int v28715 = v28714[v28805];
    int v28716 = v28714[v28734];
    int v28812 = v28716 + ((int)((unsigned int)(v28716 - v28715) >> 31));
    v28714[v28734] = v28812;
    int * v28718 = v28619->cache_age;
    int v28719 = v28718[v28735];
    int v28814 = v28719 + ((int)((unsigned int)(v28719 - v28715) >> 31));
    v28718[v28735] = v28814;
    int * v28721 = v28619->cache_age;
    v28721[v28805] = 0;
    v28724 = v28805;
  }
  int v28817 = (v28724 * 2) + (((int)((unsigned int)(v28623 + 32) >> 2)) & 1);
  int v28725 = v28631[v28817];
  int * v28726 = v28619->regs;
  v28726[6] = v28725;
  struct StateT * v28728 = slot_403(v28619);
  return v28728;
}

struct StateT * slot_138(struct StateT * v8517) {
  int v8518 = v8517->timer;
  int v8526 = v8518 + 1;
  v8517->timer = v8526;
  int * v8520 = v8517->regs;
  int v8521 = v8520[6];
  int v8522 = v8520[31];
  int v8530 = v8521 + v8522;
  v8520[6] = v8530;
  struct StateT * v8524 = slot_140(v8517);
  return v8524;
}

struct StateT * slot_200(struct StateT * v14389) {
  int v14390 = v14389->timer;
  int v14398 = v14390 + 1;
  v14389->timer = v14398;
  int * v14392 = v14389->regs;
  int v14393 = v14392[6];
  int v14394 = v14392[13];
  int v14403 = v14393 * v14394;
  v14392[31] = v14403;
  struct StateT * v14396 = slot_222(v14389);
  return v14396;
}

struct StateT * slot_104(struct StateT * v7880) {
  int v7881 = v7880->timer;
  int v7889 = v7881 + 1;
  v7880->timer = v7889;
  int * v7883 = v7880->regs;
  int v7884 = v7883[29];
  int v7885 = v7883[13];
  int v7894 = (((((int)((unsigned int)v7884 >> 16)) * ((int)((unsigned int)v7885 >> 16))) + ((int)((unsigned int)((v7884 & 65535) * ((int)((unsigned int)v7885 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v7884 >> 16)) * (v7885 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v7884 & 65535) * (v7885 & 65535)) >> 16)) + (((v7884 & 65535) * ((int)((unsigned int)v7885 >> 16))) & 65535)) + ((((int)((unsigned int)v7884 >> 16)) * (v7885 & 65535)) & 65535)) >> 16));
  v7883[18] = v7894;
  struct StateT * v7887 = slot_113(v7880);
  return v7887;
}

struct StateT * slot_64(struct StateT * v4612) {
  int v4613 = v4612->timer;
  int v4617 = v4613 + 1;
  v4612->timer = v4617;
  struct StateT * v4615 = slot_65(v4612);
  return v4615;
}

struct StateT * slot_53(struct StateT * v4408) {
  int v4409 = v4408->timer;
  int v4417 = v4409 + 1;
  v4408->timer = v4417;
  int * v4411 = v4408->regs;
  int v4412 = v4411[31];
  int v4413 = v4411[30];
  int v4421 = v4412 + v4413;
  v4411[30] = v4421;
  struct StateT * v4415 = slot_54(v4408);
  return v4415;
}

struct StateT * slot_99(struct StateT * v7795) {
  int v7796 = v7795->timer;
  int v7804 = v7796 + 1;
  v7795->timer = v7804;
  int * v7798 = v7795->regs;
  int v7799 = v7798[6];
  int v7800 = v7798[12];
  int v7809 = (((((int)((unsigned int)v7799 >> 16)) * ((int)((unsigned int)v7800 >> 16))) + ((int)((unsigned int)((v7799 & 65535) * ((int)((unsigned int)v7800 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v7799 >> 16)) * (v7800 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v7799 & 65535) * (v7800 & 65535)) >> 16)) + (((v7799 & 65535) * ((int)((unsigned int)v7800 >> 16))) & 65535)) + ((((int)((unsigned int)v7799 >> 16)) * (v7800 & 65535)) & 65535)) >> 16));
  v7798[17] = v7809;
  struct StateT * v7802 = slot_101(v7795);
  return v7802;
}

struct StateT * slot_22(struct StateT * v2408) {
  int v2409 = v2408->timer;
  int v2417 = v2409 + 1;
  v2408->timer = v2417;
  int * v2411 = v2408->regs;
  int v2412 = v2411[17];
  int v2413 = v2411[16];
  int v2422 = v2412 & v2413;
  v2411[15] = v2422;
  struct StateT * v2415 = slot_23(v2408);
  return v2415;
}

struct StateT * slot_139(struct StateT * v8533) {
  int v8534 = v8533->timer;
  int v8546 = v8534 + 1;
  v8533->timer = v8546;
  int * v8536 = v8533->regs;
  int v8537 = v8536[5];
  int v8538 = v8536[9];
  bool v8550 = (v8537 ^ -2147483648) < (v8538 ^ -2147483648);
  int v8541;
  if (v8550) {
    v8541 = 1;
  } else {
    v8541 = 0;
  }
  int * v8542 = v8533->regs;
  v8542[31] = v8541;
  struct StateT * v8544 = slot_141(v8533);
  return v8544;
}

struct StateT * slot_129(struct StateT * v8345) {
  int v8346 = v8345->timer;
  int v8354 = v8346 + 1;
  v8345->timer = v8354;
  int * v8348 = v8345->regs;
  int v8349 = v8348[29];
  int v8350 = v8348[5];
  int v8359 = v8349 + v8350;
  v8348[30] = v8359;
  struct StateT * v8352 = slot_124(v8345);
  return v8352;
}

struct StateT * slot_204(struct StateT * v14838) {
  int v14839 = v14838->timer;
  int v14949 = v14839 + 1;
  v14838->timer = v14949;
  int * v14841 = v14838->regs;
  int v14842 = v14841[11];
  int * v14843 = v14838->cache_tags;
  int v14953 = (((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2;
  int v14844 = v14843[v14953];
  int v14954 = ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14845 = v14843[v14954];
  int v14955 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2);
  int v14846 = v14843[v14955];
  int v14956 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14847 = v14843[v14956];
  int v14848 = v14838->timer;
  int v14957 = v14848 + ((100 ^ (((~(((v14846 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14846 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14844 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14844 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14845 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14845 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14846 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14846 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14838->timer = v14957;
  int * v14850 = v14838->cache_vals;
  bool v14958 = !(((~(((v14844 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14844 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14845 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14845 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v14943;
  if (v14958) {
    int * v14851 = v14838->cache_age;
    int v14960 = ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v14845 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14845 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v14852 = v14851[v14960];
    int v14853 = v14851[v14953];
    int v14961 = v14853 + ((int)((unsigned int)(v14853 - v14852) >> 31));
    v14851[v14953] = v14961;
    int * v14855 = v14838->cache_age;
    int v14856 = v14855[v14954];
    int v14963 = v14856 + ((int)((unsigned int)(v14856 - v14852) >> 31));
    v14855[v14954] = v14963;
    int * v14858 = v14838->cache_age;
    v14858[v14960] = 0;
    v14943 = v14960;
  } else {
    int * v14861 = v14838->cache_age;
    int v14967 = (((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2;
    int v14862 = v14861[v14967];
    int * v14863 = v14838->cache_tags;
    int v14864 = v14863[v14967];
    int v14865 = v14861[v14954];
    int v14866 = v14863[v14954];
    bool v14969 = !(((~(((v14846 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14846 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v14920;
    if (v14969) {
      int * v14867 = v14838->cache_age;
      int v14971 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))) | (-(v14847 ^ ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v14868 = v14867[v14971];
      int v14869 = v14867[v14955];
      int v14972 = v14869 + ((int)((unsigned int)(v14869 - v14868) >> 31));
      v14867[v14955] = v14972;
      int * v14871 = v14838->cache_age;
      int v14872 = v14871[v14956];
      int v14974 = v14872 + ((int)((unsigned int)(v14872 - v14868) >> 31));
      v14871[v14956] = v14974;
      int * v14874 = v14838->cache_age;
      v14874[v14971] = 0;
      v14920 = v14971;
    } else {
      int * v14877 = v14838->cache_age;
      int v14978 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2);
      int v14878 = v14877[v14978];
      int * v14879 = v14838->cache_tags;
      int v14880 = v14879[v14978];
      int v14881 = v14877[v14956];
      int v14882 = v14879[v14956];
      int * v14883 = v14838->cache_dirty;
      int v14981 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14878 + ((~(((v14880 ^ -1) | (-(v14880 ^ -1))) >> 31)) & 2)) - (v14881 + ((~(((v14882 ^ -1) | (-(v14882 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14884 = v14883[v14981];
      bool v14982 = !(v14884 == 0);
      if (v14982) {
        int * v14885 = v14838->cache_tags;
        int v14886 = v14885[v14981];
        int * v14887 = v14838->cache_vals;
        int v14985 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14878 + ((~(((v14880 ^ -1) | (-(v14880 ^ -1))) >> 31)) & 2)) - (v14881 + ((~(((v14882 ^ -1) | (-(v14882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14888 = v14887[v14985];
        int v14986 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14878 + ((~(((v14880 ^ -1) | (-(v14880 ^ -1))) >> 31)) & 2)) - (v14881 + ((~(((v14882 ^ -1) | (-(v14882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14889 = v14887[v14986];
        int * v14890 = v14838->mem;
        int v14988 = v14886 * 2;
        v14890[v14988] = v14888;
        int * v14892 = v14838->mem;
        int v14991 = (v14886 * 2) + 1;
        v14892[v14991] = v14889;
        ;
      } else {
        ;
      }
      int * v14897 = v14838->mem;
      int v14996 = ((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) * 2;
      int v14898 = v14897[v14996];
      int v14997 = (((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) * 2) + 1;
      int v14899 = v14897[v14997];
      int * v14900 = v14838->cache_vals;
      int v14999 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14878 + ((~(((v14880 ^ -1) | (-(v14880 ^ -1))) >> 31)) & 2)) - (v14881 + ((~(((v14882 ^ -1) | (-(v14882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14900[v14999] = v14898;
      int * v14902 = v14838->cache_vals;
      int v15002 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v14878 + ((~(((v14880 ^ -1) | (-(v14880 ^ -1))) >> 31)) & 2)) - (v14881 + ((~(((v14882 ^ -1) | (-(v14882 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14902[v15002] = v14899;
      int * v14904 = v14838->cache_tags;
      int v15005 = (int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1);
      v14904[v14981] = v15005;
      int * v14906 = v14838->cache_dirty;
      v14906[v14981] = 0;
      int * v14908 = v14838->cache_age;
      v14908[v14981] = 1;
      int * v14910 = v14838->cache_age;
      int v14911 = v14910[v14981];
      int v14912 = v14910[v14955];
      int v15011 = v14912 + ((int)((unsigned int)(v14912 - v14911) >> 31));
      v14910[v14955] = v15011;
      int * v14914 = v14838->cache_age;
      int v14915 = v14914[v14956];
      int v15013 = v14915 + ((int)((unsigned int)(v14915 - v14911) >> 31));
      v14914[v14956] = v15013;
      int * v14917 = v14838->cache_age;
      v14917[v14981] = 0;
      v14920 = v14981;
    }
    int * v14921 = v14838->cache_vals;
    int v15016 = v14920 * 2;
    int v14922 = v14921[v15016];
    int v15017 = (v14920 * 2) + 1;
    int v14923 = v14921[v15017];
    int v15018 = (((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14862 + ((~(((v14864 ^ -1) | (-(v14864 ^ -1))) >> 31)) & 2)) - (v14865 + ((~(((v14866 ^ -1) | (-(v14866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14921[v15018] = v14922;
    int * v14925 = v14838->cache_vals;
    int v15021 = ((((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14862 + ((~(((v14864 ^ -1) | (-(v14864 ^ -1))) >> 31)) & 2)) - (v14865 + ((~(((v14866 ^ -1) | (-(v14866 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14925[v15021] = v14923;
    int * v14927 = v14838->cache_tags;
    int v15024 = ((((int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v14862 + ((~(((v14864 ^ -1) | (-(v14864 ^ -1))) >> 31)) & 2)) - (v14865 + ((~(((v14866 ^ -1) | (-(v14866 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15025 = (int)((unsigned int)((int)((unsigned int)(v14842 + 24) >> 2)) >> 1);
    v14927[v15024] = v15025;
    int * v14929 = v14838->cache_dirty;
    v14929[v15024] = 0;
    int * v14931 = v14838->cache_age;
    v14931[v15024] = 1;
    int * v14933 = v14838->cache_age;
    int v14934 = v14933[v15024];
    int v14935 = v14933[v14953];
    int v15031 = v14935 + ((int)((unsigned int)(v14935 - v14934) >> 31));
    v14933[v14953] = v15031;
    int * v14937 = v14838->cache_age;
    int v14938 = v14937[v14954];
    int v15033 = v14938 + ((int)((unsigned int)(v14938 - v14934) >> 31));
    v14937[v14954] = v15033;
    int * v14940 = v14838->cache_age;
    v14940[v15024] = 0;
    v14943 = v15024;
  }
  int v15036 = (v14943 * 2) + (((int)((unsigned int)(v14842 + 24) >> 2)) & 1);
  int v14944 = v14850[v15036];
  int * v14945 = v14838->regs;
  v14945[6] = v14944;
  struct StateT * v14947 = slot_187(v14838);
  return v14947;
}

struct StateT * slot_194(struct StateT * v13272) {
  int v13273 = v13272->timer;
  int v13280 = v13273 + 1;
  v13272->timer = v13280;
  int * v13275 = v13272->regs;
  int v13276 = v13275[5];
  int v13283 = v13276 << 13;
  v13275[5] = v13283;
  struct StateT * v13278 = slot_199(v13272);
  return v13278;
}

struct StateT * slot_236(struct StateT * v15369) {
  int v15370 = v15369->timer;
  int v15378 = v15370 + 1;
  v15369->timer = v15378;
  int * v15372 = v15369->regs;
  int v15373 = v15372[31];
  int v15374 = v15372[29];
  int v15382 = v15373 + v15374;
  v15372[29] = v15382;
  struct StateT * v15376 = slot_240(v15369);
  return v15376;
}

struct StateT * slot_262(struct StateT * v15858) {
  int v15859 = v15858->timer;
  int v15871 = v15859 + 1;
  v15858->timer = v15871;
  int * v15861 = v15858->regs;
  int v15862 = v15861[29];
  int v15863 = v15861[31];
  bool v15875 = (v15862 ^ -2147483648) < (v15863 ^ -2147483648);
  int v15866;
  if (v15875) {
    v15866 = 1;
  } else {
    v15866 = 0;
  }
  int * v15867 = v15858->regs;
  v15867[6] = v15866;
  struct StateT * v15869 = slot_267(v15858);
  return v15869;
}

struct StateT * slot_27(struct StateT * v3578) {
  int v3579 = v3578->timer;
  int v3587 = v3579 + 1;
  v3578->timer = v3587;
  int * v3581 = v3578->regs;
  int v3582 = v3581[6];
  int v3583 = v3581[5];
  int v3591 = v3582 + v3583;
  v3581[5] = v3591;
  struct StateT * v3585 = slot_28(v3578);
  return v3585;
}

struct StateT * slot_24(struct StateT * v2439) {
  int v2440 = v2439->timer;
  int v2448 = v2440 + 1;
  v2439->timer = v2448;
  int * v2442 = v2439->regs;
  int v2443 = v2442[28];
  int v2444 = v2442[5];
  int v2452 = v2443 + v2444;
  v2442[5] = v2452;
  struct StateT * v2446 = slot_25(v2439);
  return v2446;
}

struct StateT * slot_126(struct StateT * v8287) {
  int v8288 = v8287->timer;
  int v8296 = v8288 + 1;
  v8287->timer = v8296;
  int * v8290 = v8287->regs;
  int v8291 = v8290[7];
  int v8292 = v8290[6];
  int v8300 = v8291 + v8292;
  v8290[6] = v8300;
  struct StateT * v8294 = slot_128(v8287);
  return v8294;
}

struct StateT * slot_47(struct StateT * v4294) {
  int v4295 = v4294->timer;
  int v4303 = v4295 + 1;
  v4294->timer = v4303;
  int * v4297 = v4294->regs;
  int v4298 = v4297[7];
  int v4299 = v4297[12];
  int v4307 = v4298 * v4299;
  v4297[7] = v4307;
  struct StateT * v4301 = slot_48(v4294);
  return v4301;
}

struct StateT * slot_19(struct StateT * v2351) {
  int v2352 = v2351->timer;
  int v2360 = v2352 + 1;
  v2351->timer = v2360;
  int * v2354 = v2351->regs;
  int v2355 = v2354[7];
  int v2356 = v2354[17];
  int v2364 = v2355 + v2356;
  v2354[17] = v2364;
  struct StateT * v2358 = slot_20(v2351);
  return v2358;
}

struct StateT * slot_130(struct StateT * v8362) {
  int v8363 = v8362->timer;
  int v8375 = v8363 + 1;
  v8362->timer = v8375;
  int * v8365 = v8362->regs;
  int v8366 = v8365[6];
  int v8367 = v8365[7];
  bool v8379 = (v8366 ^ -2147483648) < (v8367 ^ -2147483648);
  int v8370;
  if (v8379) {
    v8370 = 1;
  } else {
    v8370 = 0;
  }
  int * v8371 = v8362->regs;
  v8371[6] = v8370;
  struct StateT * v8373 = slot_139(v8362);
  return v8373;
}

struct StateT * slot_141(struct StateT * v8566) {
  int v8567 = v8566->timer;
  int v8575 = v8567 + 1;
  v8566->timer = v8575;
  int * v8569 = v8566->regs;
  int v8570 = v8569[18];
  int v8571 = v8569[6];
  int v8579 = v8570 + v8571;
  v8569[6] = v8579;
  struct StateT * v8573 = slot_136(v8566);
  return v8573;
}

struct StateT * slot_4(struct StateT * v961) {
  int v962 = v961->timer;
  int v1386 = v962 + 1;
  v961->timer = v1386;
  int * v964 = v961->regs;
  int v965 = v964[2];
  int v966 = v964[19];
  int * v967 = v961->saved_regs;
  int v968 = v964[14];
  v967[14] = v968;
  int v970 = v961->timer;
  int v1393 = v970 + 1;
  v961->timer = v1393;
  int * v972 = v961->regs;
  int v973 = v972[11];
  int * v974 = v961->cache_tags;
  int v1397 = (((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2;
  int v975 = v974[v1397];
  int v1398 = ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + 1;
  int v976 = v974[v1398];
  int v1399 = 4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2);
  int v977 = v974[v1399];
  int v1400 = (4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v978 = v974[v1400];
  int v979 = v961->timer;
  int v1401 = v979 + ((100 ^ (((~(((v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1401;
  int * v981 = v961->cache_vals;
  bool v1402 = !(((~(((v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v975 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) == 0);
  int v1074;
  if (v1402) {
    int * v982 = v961->cache_age;
    int v1404 = ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((~(((v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v976 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) & 1);
    int v983 = v982[v1404];
    int v984 = v982[v1397];
    int v1405 = v984 + ((int)((unsigned int)(v984 - v983) >> 31));
    v982[v1397] = v1405;
    int * v986 = v961->cache_age;
    int v987 = v986[v1398];
    int v1407 = v987 + ((int)((unsigned int)(v987 - v983) >> 31));
    v986[v1398] = v1407;
    int * v989 = v961->cache_age;
    v989[v1404] = 0;
    v1074 = v1404;
  } else {
    int * v992 = v961->cache_age;
    int v1411 = (((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2;
    int v993 = v992[v1411];
    int * v994 = v961->cache_tags;
    int v995 = v994[v1411];
    int v996 = v992[v1398];
    int v997 = v994[v1398];
    bool v1413 = !(((~(((v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v977 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) | (~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31))) == 0);
    int v1051;
    if (v1413) {
      int * v998 = v961->cache_age;
      int v1415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((~(((v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))) | (-(v978 ^ ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1))))) >> 31)) & 1);
      int v999 = v998[v1415];
      int v1000 = v998[v1399];
      int v1416 = v1000 + ((int)((unsigned int)(v1000 - v999) >> 31));
      v998[v1399] = v1416;
      int * v1002 = v961->cache_age;
      int v1003 = v1002[v1400];
      int v1418 = v1003 + ((int)((unsigned int)(v1003 - v999) >> 31));
      v1002[v1400] = v1418;
      int * v1005 = v961->cache_age;
      v1005[v1415] = 0;
      v1051 = v1415;
    } else {
      int * v1008 = v961->cache_age;
      int v1422 = 4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2);
      int v1009 = v1008[v1422];
      int * v1010 = v961->cache_tags;
      int v1011 = v1010[v1422];
      int v1012 = v1008[v1400];
      int v1013 = v1010[v1400];
      int * v1014 = v961->cache_dirty;
      int v1425 = (4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1015 = v1014[v1425];
      bool v1426 = !(v1015 == 0);
      if (v1426) {
        int * v1016 = v961->cache_tags;
        int v1017 = v1016[v1425];
        int * v1018 = v961->cache_vals;
        int v1429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1019 = v1018[v1429];
        int v1430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1020 = v1018[v1430];
        int * v1021 = v961->mem;
        int v1432 = v1017 * 2;
        v1021[v1432] = v1019;
        int * v1023 = v961->mem;
        int v1435 = (v1017 * 2) + 1;
        v1023[v1435] = v1020;
        ;
      } else {
        ;
      }
      int * v1028 = v961->mem;
      int v1440 = ((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) * 2;
      int v1029 = v1028[v1440];
      int v1441 = (((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) * 2) + 1;
      int v1030 = v1028[v1441];
      int * v1031 = v961->cache_vals;
      int v1443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1031[v1443] = v1029;
      int * v1033 = v961->cache_vals;
      int v1446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 3) * 2)) + ((((v1009 + ((~(((v1011 ^ -1) | (-(v1011 ^ -1))) >> 31)) & 2)) - (v1012 + ((~(((v1013 ^ -1) | (-(v1013 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1033[v1446] = v1030;
      int * v1035 = v961->cache_tags;
      int v1449 = (int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1);
      v1035[v1425] = v1449;
      int * v1037 = v961->cache_dirty;
      v1037[v1425] = 0;
      int * v1039 = v961->cache_age;
      v1039[v1425] = 1;
      int * v1041 = v961->cache_age;
      int v1042 = v1041[v1425];
      int v1043 = v1041[v1399];
      int v1455 = v1043 + ((int)((unsigned int)(v1043 - v1042) >> 31));
      v1041[v1399] = v1455;
      int * v1045 = v961->cache_age;
      int v1046 = v1045[v1400];
      int v1457 = v1046 + ((int)((unsigned int)(v1046 - v1042) >> 31));
      v1045[v1400] = v1457;
      int * v1048 = v961->cache_age;
      v1048[v1425] = 0;
      v1051 = v1425;
    }
    int * v1052 = v961->cache_vals;
    int v1460 = v1051 * 2;
    int v1053 = v1052[v1460];
    int v1461 = (v1051 * 2) + 1;
    int v1054 = v1052[v1461];
    int v1462 = (((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1052[v1462] = v1053;
    int * v1056 = v961->cache_vals;
    int v1465 = ((((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1056[v1465] = v1054;
    int * v1058 = v961->cache_tags;
    int v1468 = ((((int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1)) & 1) * 2) + ((((v993 + ((~(((v995 ^ -1) | (-(v995 ^ -1))) >> 31)) & 2)) - (v996 + ((~(((v997 ^ -1) | (-(v997 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1469 = (int)((unsigned int)((int)((unsigned int)v973 >> 2)) >> 1);
    v1058[v1468] = v1469;
    int * v1060 = v961->cache_dirty;
    v1060[v1468] = 0;
    int * v1062 = v961->cache_age;
    v1062[v1468] = 1;
    int * v1064 = v961->cache_age;
    int v1065 = v1064[v1468];
    int v1066 = v1064[v1397];
    int v1475 = v1066 + ((int)((unsigned int)(v1066 - v1065) >> 31));
    v1064[v1397] = v1475;
    int * v1068 = v961->cache_age;
    int v1069 = v1068[v1398];
    int v1477 = v1069 + ((int)((unsigned int)(v1069 - v1065) >> 31));
    v1068[v1398] = v1477;
    int * v1071 = v961->cache_age;
    v1071[v1468] = 0;
    v1074 = v1468;
  }
  int v1480 = (v1074 * 2) + (((int)((unsigned int)v973 >> 2)) & 1);
  int v1075 = v981[v1480];
  int * v1076 = v961->regs;
  v1076[14] = v1075;
  int * v1078 = v961->saved_regs;
  int * v1079 = v961->regs;
  int v1080 = v1079[15];
  v1078[15] = v1080;
  int v1082 = v961->timer;
  int v1487 = v1082 + 1;
  v961->timer = v1487;
  int * v1084 = v961->regs;
  int v1085 = v1084[11];
  int * v1086 = v961->cache_tags;
  int v1490 = (((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1087 = v1086[v1490];
  int v1491 = ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1088 = v1086[v1491];
  int v1492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1089 = v1086[v1492];
  int v1493 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1090 = v1086[v1493];
  int v1091 = v961->timer;
  int v1494 = v1091 + ((100 ^ (((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1494;
  int * v1093 = v961->cache_vals;
  bool v1495 = !(((~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1186;
  if (v1495) {
    int * v1094 = v961->cache_age;
    int v1497 = ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1095 = v1094[v1497];
    int v1096 = v1094[v1490];
    int v1498 = v1096 + ((int)((unsigned int)(v1096 - v1095) >> 31));
    v1094[v1490] = v1498;
    int * v1098 = v961->cache_age;
    int v1099 = v1098[v1491];
    int v1500 = v1099 + ((int)((unsigned int)(v1099 - v1095) >> 31));
    v1098[v1491] = v1500;
    int * v1101 = v961->cache_age;
    v1101[v1497] = 0;
    v1186 = v1497;
  } else {
    int * v1104 = v961->cache_age;
    int v1504 = (((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1105 = v1104[v1504];
    int * v1106 = v961->cache_tags;
    int v1107 = v1106[v1504];
    int v1108 = v1104[v1491];
    int v1109 = v1106[v1491];
    bool v1506 = !(((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1163;
    if (v1506) {
      int * v1110 = v961->cache_age;
      int v1508 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))) | (-(v1090 ^ ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1111 = v1110[v1508];
      int v1112 = v1110[v1492];
      int v1509 = v1112 + ((int)((unsigned int)(v1112 - v1111) >> 31));
      v1110[v1492] = v1509;
      int * v1114 = v961->cache_age;
      int v1115 = v1114[v1493];
      int v1511 = v1115 + ((int)((unsigned int)(v1115 - v1111) >> 31));
      v1114[v1493] = v1511;
      int * v1117 = v961->cache_age;
      v1117[v1508] = 0;
      v1163 = v1508;
    } else {
      int * v1120 = v961->cache_age;
      int v1515 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1121 = v1120[v1515];
      int * v1122 = v961->cache_tags;
      int v1123 = v1122[v1515];
      int v1124 = v1120[v1493];
      int v1125 = v1122[v1493];
      int * v1126 = v961->cache_dirty;
      int v1518 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1127 = v1126[v1518];
      bool v1519 = !(v1127 == 0);
      if (v1519) {
        int * v1128 = v961->cache_tags;
        int v1129 = v1128[v1518];
        int * v1130 = v961->cache_vals;
        int v1522 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1131 = v1130[v1522];
        int v1523 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1132 = v1130[v1523];
        int * v1133 = v961->mem;
        int v1525 = v1129 * 2;
        v1133[v1525] = v1131;
        int * v1135 = v961->mem;
        int v1528 = (v1129 * 2) + 1;
        v1135[v1528] = v1132;
        ;
      } else {
        ;
      }
      int * v1140 = v961->mem;
      int v1533 = ((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) * 2;
      int v1141 = v1140[v1533];
      int v1534 = (((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1142 = v1140[v1534];
      int * v1143 = v961->cache_vals;
      int v1536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1143[v1536] = v1141;
      int * v1145 = v961->cache_vals;
      int v1539 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1121 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2)) - (v1124 + ((~(((v1125 ^ -1) | (-(v1125 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1145[v1539] = v1142;
      int * v1147 = v961->cache_tags;
      int v1542 = (int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1);
      v1147[v1518] = v1542;
      int * v1149 = v961->cache_dirty;
      v1149[v1518] = 0;
      int * v1151 = v961->cache_age;
      v1151[v1518] = 1;
      int * v1153 = v961->cache_age;
      int v1154 = v1153[v1518];
      int v1155 = v1153[v1492];
      int v1548 = v1155 + ((int)((unsigned int)(v1155 - v1154) >> 31));
      v1153[v1492] = v1548;
      int * v1157 = v961->cache_age;
      int v1158 = v1157[v1493];
      int v1550 = v1158 + ((int)((unsigned int)(v1158 - v1154) >> 31));
      v1157[v1493] = v1550;
      int * v1160 = v961->cache_age;
      v1160[v1518] = 0;
      v1163 = v1518;
    }
    int * v1164 = v961->cache_vals;
    int v1553 = v1163 * 2;
    int v1165 = v1164[v1553];
    int v1554 = (v1163 * 2) + 1;
    int v1166 = v1164[v1554];
    int v1555 = (((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1164[v1555] = v1165;
    int * v1168 = v961->cache_vals;
    int v1558 = ((((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1168[v1558] = v1166;
    int * v1170 = v961->cache_tags;
    int v1561 = ((((int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1105 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2)) - (v1108 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1562 = (int)((unsigned int)((int)((unsigned int)(v1085 + 4) >> 2)) >> 1);
    v1170[v1561] = v1562;
    int * v1172 = v961->cache_dirty;
    v1172[v1561] = 0;
    int * v1174 = v961->cache_age;
    v1174[v1561] = 1;
    int * v1176 = v961->cache_age;
    int v1177 = v1176[v1561];
    int v1178 = v1176[v1490];
    int v1568 = v1178 + ((int)((unsigned int)(v1178 - v1177) >> 31));
    v1176[v1490] = v1568;
    int * v1180 = v961->cache_age;
    int v1181 = v1180[v1491];
    int v1570 = v1181 + ((int)((unsigned int)(v1181 - v1177) >> 31));
    v1180[v1491] = v1570;
    int * v1183 = v961->cache_age;
    v1183[v1561] = 0;
    v1186 = v1561;
  }
  int v1573 = (v1186 * 2) + (((int)((unsigned int)(v1085 + 4) >> 2)) & 1);
  int v1187 = v1093[v1573];
  int * v1188 = v961->regs;
  v1188[15] = v1187;
  int * v1190 = v961->saved_regs;
  int * v1191 = v961->regs;
  int v1192 = v1191[16];
  v1190[16] = v1192;
  int v1194 = v961->timer;
  int v1580 = v1194 + 1;
  v961->timer = v1580;
  int * v1196 = v961->regs;
  v1196[16] = 524288;
  int v1198 = v961->timer;
  int v1583 = v1198 + 1;
  v961->timer = v1583;
  int * v1200 = v961->regs;
  int v1201 = v1200[16];
  int v1585 = v1201 + -1;
  v1200[16] = v1585;
  int * v1203 = v961->cache_tags;
  int v1587 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
  int v1204 = v1203[v1587];
  int v1588 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1205 = v1203[v1588];
  int v1589 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
  int v1206 = v1203[v1589];
  int v1590 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1207 = v1203[v1590];
  int v1208 = v961->timer;
  int v1591 = v1208 + ((100 ^ (((~(((v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1591;
  bool v1592 = !(((~(((v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1204 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1302;
  if (v1592) {
    int * v1210 = v961->cache_age;
    int v1594 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((~(((v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1205 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v1211 = v1210[v1594];
    int v1212 = v1210[v1587];
    int v1595 = v1212 + ((int)((unsigned int)(v1212 - v1211) >> 31));
    v1210[v1587] = v1595;
    int * v1214 = v961->cache_age;
    int v1215 = v1214[v1588];
    int v1597 = v1215 + ((int)((unsigned int)(v1215 - v1211) >> 31));
    v1214[v1588] = v1597;
    int * v1217 = v961->cache_age;
    v1217[v1594] = 0;
    v1302 = v1594;
  } else {
    int * v1220 = v961->cache_age;
    int v1601 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2;
    int v1221 = v1220[v1601];
    int * v1222 = v961->cache_tags;
    int v1223 = v1222[v1601];
    int v1224 = v1220[v1588];
    int v1225 = v1222[v1588];
    bool v1603 = !(((~(((v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1206 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
    int v1279;
    if (v1603) {
      int * v1226 = v961->cache_age;
      int v1605 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1207 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
      int v1227 = v1226[v1605];
      int v1228 = v1226[v1589];
      int v1606 = v1228 + ((int)((unsigned int)(v1228 - v1227) >> 31));
      v1226[v1589] = v1606;
      int * v1230 = v961->cache_age;
      int v1231 = v1230[v1590];
      int v1608 = v1231 + ((int)((unsigned int)(v1231 - v1227) >> 31));
      v1230[v1590] = v1608;
      int * v1233 = v961->cache_age;
      v1233[v1605] = 0;
      v1279 = v1605;
    } else {
      int * v1236 = v961->cache_age;
      int v1612 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
      int v1237 = v1236[v1612];
      int * v1238 = v961->cache_tags;
      int v1239 = v1238[v1612];
      int v1240 = v1236[v1590];
      int v1241 = v1238[v1590];
      int * v1242 = v961->cache_dirty;
      int v1615 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1243 = v1242[v1615];
      bool v1616 = !(v1243 == 0);
      if (v1616) {
        int * v1244 = v961->cache_tags;
        int v1245 = v1244[v1615];
        int * v1246 = v961->cache_vals;
        int v1619 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1247 = v1246[v1619];
        int v1620 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1248 = v1246[v1620];
        int * v1249 = v961->mem;
        int v1622 = v1245 * 2;
        v1249[v1622] = v1247;
        int * v1251 = v961->mem;
        int v1625 = (v1245 * 2) + 1;
        v1251[v1625] = v1248;
        ;
      } else {
        ;
      }
      int * v1256 = v961->mem;
      int v1630 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
      int v1257 = v1256[v1630];
      int v1631 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
      int v1258 = v1256[v1631];
      int * v1259 = v961->cache_vals;
      int v1633 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1259[v1633] = v1257;
      int * v1261 = v961->cache_vals;
      int v1636 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1237 + ((~(((v1239 ^ -1) | (-(v1239 ^ -1))) >> 31)) & 2)) - (v1240 + ((~(((v1241 ^ -1) | (-(v1241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1261[v1636] = v1258;
      int * v1263 = v961->cache_tags;
      int v1639 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
      v1263[v1615] = v1639;
      int * v1265 = v961->cache_dirty;
      v1265[v1615] = 0;
      int * v1267 = v961->cache_age;
      v1267[v1615] = 1;
      int * v1269 = v961->cache_age;
      int v1270 = v1269[v1615];
      int v1271 = v1269[v1589];
      int v1645 = v1271 + ((int)((unsigned int)(v1271 - v1270) >> 31));
      v1269[v1589] = v1645;
      int * v1273 = v961->cache_age;
      int v1274 = v1273[v1590];
      int v1647 = v1274 + ((int)((unsigned int)(v1274 - v1270) >> 31));
      v1273[v1590] = v1647;
      int * v1276 = v961->cache_age;
      v1276[v1615] = 0;
      v1279 = v1615;
    }
    int * v1280 = v961->cache_vals;
    int v1650 = v1279 * 2;
    int v1281 = v1280[v1650];
    int v1651 = (v1279 * 2) + 1;
    int v1282 = v1280[v1651];
    int v1652 = (((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v1221 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2)) - (v1224 + ((~(((v1225 ^ -1) | (-(v1225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1280[v1652] = v1281;
    int * v1284 = v961->cache_vals;
    int v1655 = ((((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v1221 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2)) - (v1224 + ((~(((v1225 ^ -1) | (-(v1225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1284[v1655] = v1282;
    int * v1286 = v961->cache_tags;
    int v1658 = ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 1) * 2) + ((((v1221 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2)) - (v1224 + ((~(((v1225 ^ -1) | (-(v1225 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1659 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1286[v1658] = v1659;
    int * v1288 = v961->cache_dirty;
    v1288[v1658] = 0;
    int * v1290 = v961->cache_age;
    v1290[v1658] = 1;
    int * v1292 = v961->cache_age;
    int v1293 = v1292[v1658];
    int v1294 = v1292[v1587];
    int v1665 = v1294 + ((int)((unsigned int)(v1294 - v1293) >> 31));
    v1292[v1587] = v1665;
    int * v1296 = v961->cache_age;
    int v1297 = v1296[v1588];
    int v1667 = v1297 + ((int)((unsigned int)(v1297 - v1293) >> 31));
    v1296[v1588] = v1667;
    int * v1299 = v961->cache_age;
    v1299[v1658] = 0;
    v1302 = v1658;
  }
  int * v1303 = v961->cache_vals;
  int v1670 = (v1302 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1303[v1670] = v966;
  int * v1305 = v961->cache_tags;
  int v1306 = v1305[v1589];
  int v1307 = v1305[v1590];
  bool v1673 = !(((~(((v1306 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1306 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) | (~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31))) == 0);
  int v1361;
  if (v1673) {
    int * v1308 = v961->cache_age;
    int v1675 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1))))) >> 31)) & 1);
    int v1309 = v1308[v1675];
    int v1310 = v1308[v1589];
    int v1676 = v1310 + ((int)((unsigned int)(v1310 - v1309) >> 31));
    v1308[v1589] = v1676;
    int * v1312 = v961->cache_age;
    int v1313 = v1312[v1590];
    int v1678 = v1313 + ((int)((unsigned int)(v1313 - v1309) >> 31));
    v1312[v1590] = v1678;
    int * v1315 = v961->cache_age;
    v1315[v1675] = 0;
    v1361 = v1675;
  } else {
    int * v1318 = v961->cache_age;
    int v1682 = 4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2);
    int v1319 = v1318[v1682];
    int * v1320 = v961->cache_tags;
    int v1321 = v1320[v1682];
    int v1322 = v1318[v1590];
    int v1323 = v1320[v1590];
    int * v1324 = v961->cache_dirty;
    int v1685 = (4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1325 = v1324[v1685];
    bool v1686 = !(v1325 == 0);
    if (v1686) {
      int * v1326 = v961->cache_tags;
      int v1327 = v1326[v1685];
      int * v1328 = v961->cache_vals;
      int v1689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1329 = v1328[v1689];
      int v1690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1330 = v1328[v1690];
      int * v1331 = v961->mem;
      int v1692 = v1327 * 2;
      v1331[v1692] = v1329;
      int * v1333 = v961->mem;
      int v1695 = (v1327 * 2) + 1;
      v1333[v1695] = v1330;
      ;
    } else {
      ;
    }
    int * v1338 = v961->mem;
    int v1700 = ((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2;
    int v1339 = v1338[v1700];
    int v1701 = (((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) * 2) + 1;
    int v1340 = v1338[v1701];
    int * v1341 = v961->cache_vals;
    int v1703 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1341[v1703] = v1339;
    int * v1343 = v961->cache_vals;
    int v1706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1)) & 3) * 2)) + ((((v1319 + ((~(((v1321 ^ -1) | (-(v1321 ^ -1))) >> 31)) & 2)) - (v1322 + ((~(((v1323 ^ -1) | (-(v1323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1343[v1706] = v1340;
    int * v1345 = v961->cache_tags;
    int v1709 = (int)((unsigned int)((int)((unsigned int)v965 >> 2)) >> 1);
    v1345[v1685] = v1709;
    int * v1347 = v961->cache_dirty;
    v1347[v1685] = 0;
    int * v1349 = v961->cache_age;
    v1349[v1685] = 1;
    int * v1351 = v961->cache_age;
    int v1352 = v1351[v1685];
    int v1353 = v1351[v1589];
    int v1715 = v1353 + ((int)((unsigned int)(v1353 - v1352) >> 31));
    v1351[v1589] = v1715;
    int * v1355 = v961->cache_age;
    int v1356 = v1355[v1590];
    int v1717 = v1356 + ((int)((unsigned int)(v1356 - v1352) >> 31));
    v1355[v1590] = v1717;
    int * v1358 = v961->cache_age;
    v1358[v1685] = 0;
    v1361 = v1685;
  }
  int * v1362 = v961->cache_vals;
  int v1720 = (v1361 * 2) + (((int)((unsigned int)v965 >> 2)) & 1);
  v1362[v1720] = v966;
  int * v1364 = v961->cache_dirty;
  v1364[v1361] = 1;
  bool v1724 = (((int)((unsigned int)v973 >> 2)) == ((int)((unsigned int)v965 >> 2))) | (((int)((unsigned int)(v1085 + 4) >> 2)) == ((int)((unsigned int)v965 >> 2)));
  struct StateT * v1384;
  if (v1724) {
    int v1366 = v961->timer;
    int v1725 = v1366 + 15;
    v961->timer = v1725;
    int * v1368 = v961->saved_regs;
    int v1369 = v1368[14];
    int * v1370 = v961->regs;
    v1370[14] = v1369;
    int * v1372 = v961->saved_regs;
    int v1373 = v1372[15];
    int * v1374 = v961->regs;
    v1374[15] = v1373;
    int * v1376 = v961->saved_regs;
    int v1377 = v1376[16];
    int * v1378 = v961->regs;
    v1378[16] = v1377;
    struct StateT * v1380 = slot_5(v961);
    v1384 = v1380;
  } else {
    struct StateT * v1382 = slot_9(v961);
    v1384 = v1382;
  }
  return v1384;
}

struct StateT * slot_49(struct StateT * v4326) {
  int v4327 = v4326->timer;
  int v4335 = v4327 + 1;
  v4326->timer = v4335;
  int * v4329 = v4326->regs;
  int v4330 = v4329[7];
  int v4331 = v4329[17];
  int v4339 = v4330 + v4331;
  v4329[17] = v4339;
  struct StateT * v4333 = slot_50(v4326);
  return v4333;
}

struct StateT * slot_50(struct StateT * v4342) {
  int v4343 = v4342->timer;
  int v4355 = v4343 + 1;
  v4342->timer = v4355;
  int * v4345 = v4342->regs;
  int v4346 = v4345[6];
  int v4347 = v4345[30];
  bool v4359 = (v4346 ^ -2147483648) < (v4347 ^ -2147483648);
  int v4350;
  if (v4359) {
    v4350 = 1;
  } else {
    v4350 = 0;
  }
  int * v4351 = v4342->regs;
  v4351[30] = v4350;
  struct StateT * v4353 = slot_51(v4342);
  return v4353;
}

struct StateT * slot_59(struct StateT * v4515) {
  int v4516 = v4515->timer;
  int v4528 = v4516 + 1;
  v4515->timer = v4528;
  int * v4518 = v4515->regs;
  int v4519 = v4518[6];
  int v4520 = v4518[30];
  bool v4532 = (v4519 ^ -2147483648) < (v4520 ^ -2147483648);
  int v4523;
  if (v4532) {
    v4523 = 1;
  } else {
    v4523 = 0;
  }
  int * v4524 = v4515->regs;
  v4524[6] = v4523;
  struct StateT * v4526 = slot_60(v4515);
  return v4526;
}

struct StateT * slot_71(struct StateT * v4796) {
  int v4797 = v4796->timer;
  int v4805 = v4797 + 1;
  v4796->timer = v4805;
  int * v4799 = v4796->regs;
  int v4800 = v4799[5];
  int v4801 = v4799[28];
  int v4809 = v4800 + v4801;
  v4799[28] = v4809;
  struct StateT * v4803 = slot_73(v4796);
  return v4803;
}

struct StateT * slot_45(struct StateT * v4260) {
  int v4261 = v4260->timer;
  int v4269 = v4261 + 1;
  v4260->timer = v4269;
  int * v4263 = v4260->regs;
  int v4264 = v4263[28];
  int v4265 = v4263[13];
  int v4274 = v4264 * v4265;
  v4263[18] = v4274;
  struct StateT * v4267 = slot_46(v4260);
  return v4267;
}

struct StateT * slot_69(struct StateT * v4713) {
  int * v4714 = v4713->saved_regs;
  int * v4715 = v4713->regs;
  int v4716 = v4715[5];
  v4714[5] = v4716;
  int v4718 = v4713->timer;
  int v4734 = v4718 + 1;
  v4713->timer = v4734;
  int * v4720 = v4713->regs;
  int v4721 = v4720[28];
  int v4722 = v4720[5];
  bool v4737 = (v4721 ^ -2147483648) < (v4722 ^ -2147483648);
  int v4725;
  if (v4737) {
    v4725 = 1;
  } else {
    v4725 = 0;
  }
  int * v4726 = v4713->regs;
  v4726[5] = v4725;
  struct StateT * v4728 = slot_70(v4713);
  return v4728;
}

struct StateT * slot_54(struct StateT * v4424) {
  int v4425 = v4424->timer;
  int v4437 = v4425 + 1;
  v4424->timer = v4437;
  int * v4427 = v4424->regs;
  int v4428 = v4427[29];
  int v4429 = v4427[8];
  bool v4441 = (v4428 ^ -2147483648) < (v4429 ^ -2147483648);
  int v4432;
  if (v4441) {
    v4432 = 1;
  } else {
    v4432 = 0;
  }
  int * v4433 = v4424->regs;
  v4433[6] = v4432;
  struct StateT * v4435 = slot_55(v4424);
  return v4435;
}

struct StateT * slot_42(struct StateT * v4213) {
  int v4214 = v4213->timer;
  int v4222 = v4214 + 1;
  v4213->timer = v4222;
  int * v4216 = v4213->regs;
  int v4217 = v4216[7];
  int v4218 = v4216[13];
  int v4227 = (((((int)((unsigned int)v4217 >> 16)) * ((int)((unsigned int)v4218 >> 16))) + ((int)((unsigned int)((v4217 & 65535) * ((int)((unsigned int)v4218 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4217 >> 16)) * (v4218 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4217 & 65535) * (v4218 & 65535)) >> 16)) + (((v4217 & 65535) * ((int)((unsigned int)v4218 >> 16))) & 65535)) + ((((int)((unsigned int)v4217 >> 16)) * (v4218 & 65535)) & 65535)) >> 16));
  v4216[9] = v4227;
  struct StateT * v4220 = slot_43(v4213);
  return v4220;
}

struct StateT * slot_12(struct StateT * v2226) {
  int v2227 = v2226->timer;
  int v2235 = v2227 + 1;
  v2226->timer = v2235;
  int * v2229 = v2226->regs;
  int v2230 = v2229[14];
  int v2231 = v2229[13];
  int v2240 = v2230 * v2231;
  v2229[7] = v2240;
  struct StateT * v2233 = slot_13(v2226);
  return v2233;
}

struct StateT * slot_65(struct StateT * v4620) {
  int * v4621 = v4620->saved_regs;
  int * v4622 = v4620->regs;
  int v4623 = v4622[28];
  v4621[28] = v4623;
  int v4625 = v4620->timer;
  int v4641 = v4625 + 1;
  v4620->timer = v4641;
  int * v4627 = v4620->regs;
  int v4628 = v4627[7];
  int v4629 = v4627[29];
  bool v4645 = (v4628 ^ -2147483648) < (v4629 ^ -2147483648);
  int v4632;
  if (v4645) {
    v4632 = 1;
  } else {
    v4632 = 0;
  }
  int * v4633 = v4620->regs;
  v4633[28] = v4632;
  struct StateT * v4635 = slot_66(v4620);
  return v4635;
}

struct StateT * slot_10(struct StateT * v2165) {
  int v2166 = v2165->timer;
  int v2174 = v2166 + 1;
  v2165->timer = v2174;
  int * v2168 = v2165->regs;
  int v2169 = v2168[15];
  int v2170 = v2168[12];
  int v2179 = v2169 * v2170;
  v2168[5] = v2179;
  struct StateT * v2172 = slot_11(v2165);
  return v2172;
}

struct StateT * slot_17(struct StateT * v2310) {
  int v2311 = v2310->timer;
  int v2319 = v2311 + 1;
  v2310->timer = v2319;
  int * v2313 = v2310->regs;
  int v2314 = v2313[5];
  int v2315 = v2313[17];
  int v2323 = v2314 + v2315;
  v2313[17] = v2323;
  struct StateT * v2317 = slot_18(v2310);
  return v2317;
}

struct StateT * slot_56(struct StateT * v4466) {
  int v4467 = v4466->timer;
  int v4475 = v4467 + 1;
  v4466->timer = v4475;
  int * v4469 = v4466->regs;
  int v4470 = v4469[9];
  int v4471 = v4469[6];
  int v4479 = v4470 + v4471;
  v4469[6] = v4479;
  struct StateT * v4473 = slot_57(v4466);
  return v4473;
}

struct StateT * slot_63(struct StateT * v4596) {
  int v4597 = v4596->timer;
  int v4605 = v4597 + 1;
  v4596->timer = v4605;
  int * v4599 = v4596->regs;
  int v4600 = v4599[6];
  int v4601 = v4599[30];
  int v4609 = v4600 + v4601;
  v4599[6] = v4609;
  struct StateT * v4603 = slot_64(v4596);
  return v4603;
}

struct StateT * slot_41(struct StateT * v4196) {
  int v4197 = v4196->timer;
  int v4205 = v4197 + 1;
  v4196->timer = v4205;
  int * v4199 = v4196->regs;
  int v4200 = v4199[7];
  int v4201 = v4199[13];
  int v4210 = v4200 * v4201;
  v4199[8] = v4210;
  struct StateT * v4203 = slot_42(v4196);
  return v4203;
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

struct StateT * slot_38(struct StateT * v4145) {
  int v4146 = v4145->timer;
  int v4154 = v4146 + 1;
  v4145->timer = v4154;
  int * v4148 = v4145->regs;
  int v4149 = v4148[7];
  int v4150 = v4148[12];
  int v4159 = (((((int)((unsigned int)v4149 >> 16)) * ((int)((unsigned int)v4150 >> 16))) + ((int)((unsigned int)((v4149 & 65535) * ((int)((unsigned int)v4150 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v4149 >> 16)) * (v4150 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v4149 & 65535) * (v4150 & 65535)) >> 16)) + (((v4149 & 65535) * ((int)((unsigned int)v4150 >> 16))) & 65535)) + ((((int)((unsigned int)v4149 >> 16)) * (v4150 & 65535)) & 65535)) >> 16));
  v4148[6] = v4159;
  struct StateT * v4152 = slot_39(v4145);
  return v4152;
}

struct StateT * slot_18(struct StateT * v2326) {
  int v2327 = v2326->timer;
  int v2339 = v2327 + 1;
  v2326->timer = v2339;
  int * v2329 = v2326->regs;
  int v2330 = v2329[17];
  int v2331 = v2329[5];
  bool v2343 = (v2330 ^ -2147483648) < (v2331 ^ -2147483648);
  int v2334;
  if (v2343) {
    v2334 = 1;
  } else {
    v2334 = 0;
  }
  int * v2335 = v2326->regs;
  v2335[15] = v2334;
  struct StateT * v2337 = slot_19(v2326);
  return v2337;
}

struct StateT * slot_9(struct StateT * v1944) {
  int v1945 = v1944->timer;
  int v1953 = v1945 + 1;
  v1944->timer = v1953;
  int * v1947 = v1944->regs;
  int v1948 = v1947[14];
  int v1949 = v1947[12];
  int v1958 = (((((int)((unsigned int)v1948 >> 16)) * ((int)((unsigned int)v1949 >> 16))) + ((int)((unsigned int)((v1948 & 65535) * ((int)((unsigned int)v1949 >> 16))) >> 16))) + ((int)((unsigned int)(((int)((unsigned int)v1948 >> 16)) * (v1949 & 65535)) >> 16))) + ((int)((unsigned int)((((int)((unsigned int)((v1948 & 65535) * (v1949 & 65535)) >> 16)) + (((v1948 & 65535) * ((int)((unsigned int)v1949 >> 16))) & 65535)) + ((((int)((unsigned int)v1948 >> 16)) * (v1949 & 65535)) & 65535)) >> 16));
  v1947[17] = v1958;
  struct StateT * v1951 = slot_10(v1944);
  return v1951;
}

struct StateT * slot_43(struct StateT * v4230) {
  int v4231 = v4230->timer;
  int v4238 = v4231 + 1;
  v4230->timer = v4238;
  int * v4233 = v4230->regs;
  int v4234 = v4233[5];
  int v4241 = v4234 << 13;
  v4233[5] = v4241;
  struct StateT * v4236 = slot_44(v4230);
  return v4236;
}

struct StateT * slot_55(struct StateT * v4449) {
  int v4450 = v4449->timer;
  int v4458 = v4450 + 1;
  v4449->timer = v4458;
  int * v4452 = v4449->regs;
  int v4453 = v4452[29];
  int v4454 = v4452[5];
  int v4463 = v4453 + v4454;
  v4452[7] = v4463;
  struct StateT * v4456 = slot_56(v4449);
  return v4456;
}

struct StateT * slot_91(struct StateT * v7243) {
  int v7244 = v7243->timer;
  int v7354 = v7244 + 1;
  v7243->timer = v7354;
  int * v7246 = v7243->regs;
  int v7247 = v7246[11];
  int * v7248 = v7243->cache_tags;
  int v7358 = (((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2;
  int v7249 = v7248[v7358];
  int v7359 = ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7250 = v7248[v7359];
  int v7360 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2);
  int v7251 = v7248[v7360];
  int v7361 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7252 = v7248[v7361];
  int v7253 = v7243->timer;
  int v7362 = v7253 + ((100 ^ (((~(((v7251 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7251 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7249 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7249 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7250 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7250 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7251 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7251 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7243->timer = v7362;
  int * v7255 = v7243->cache_vals;
  bool v7363 = !(((~(((v7249 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7249 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7250 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7250 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v7348;
  if (v7363) {
    int * v7256 = v7243->cache_age;
    int v7365 = ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v7250 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7250 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v7257 = v7256[v7365];
    int v7258 = v7256[v7358];
    int v7366 = v7258 + ((int)((unsigned int)(v7258 - v7257) >> 31));
    v7256[v7358] = v7366;
    int * v7260 = v7243->cache_age;
    int v7261 = v7260[v7359];
    int v7368 = v7261 + ((int)((unsigned int)(v7261 - v7257) >> 31));
    v7260[v7359] = v7368;
    int * v7263 = v7243->cache_age;
    v7263[v7365] = 0;
    v7348 = v7365;
  } else {
    int * v7266 = v7243->cache_age;
    int v7372 = (((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2;
    int v7267 = v7266[v7372];
    int * v7268 = v7243->cache_tags;
    int v7269 = v7268[v7372];
    int v7270 = v7266[v7359];
    int v7271 = v7268[v7359];
    bool v7374 = !(((~(((v7251 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7251 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v7325;
    if (v7374) {
      int * v7272 = v7243->cache_age;
      int v7376 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))) | (-(v7252 ^ ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v7273 = v7272[v7376];
      int v7274 = v7272[v7360];
      int v7377 = v7274 + ((int)((unsigned int)(v7274 - v7273) >> 31));
      v7272[v7360] = v7377;
      int * v7276 = v7243->cache_age;
      int v7277 = v7276[v7361];
      int v7379 = v7277 + ((int)((unsigned int)(v7277 - v7273) >> 31));
      v7276[v7361] = v7379;
      int * v7279 = v7243->cache_age;
      v7279[v7376] = 0;
      v7325 = v7376;
    } else {
      int * v7282 = v7243->cache_age;
      int v7383 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2);
      int v7283 = v7282[v7383];
      int * v7284 = v7243->cache_tags;
      int v7285 = v7284[v7383];
      int v7286 = v7282[v7361];
      int v7287 = v7284[v7361];
      int * v7288 = v7243->cache_dirty;
      int v7386 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7283 + ((~(((v7285 ^ -1) | (-(v7285 ^ -1))) >> 31)) & 2)) - (v7286 + ((~(((v7287 ^ -1) | (-(v7287 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7289 = v7288[v7386];
      bool v7387 = !(v7289 == 0);
      if (v7387) {
        int * v7290 = v7243->cache_tags;
        int v7291 = v7290[v7386];
        int * v7292 = v7243->cache_vals;
        int v7390 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7283 + ((~(((v7285 ^ -1) | (-(v7285 ^ -1))) >> 31)) & 2)) - (v7286 + ((~(((v7287 ^ -1) | (-(v7287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7293 = v7292[v7390];
        int v7391 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7283 + ((~(((v7285 ^ -1) | (-(v7285 ^ -1))) >> 31)) & 2)) - (v7286 + ((~(((v7287 ^ -1) | (-(v7287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7294 = v7292[v7391];
        int * v7295 = v7243->mem;
        int v7393 = v7291 * 2;
        v7295[v7393] = v7293;
        int * v7297 = v7243->mem;
        int v7396 = (v7291 * 2) + 1;
        v7297[v7396] = v7294;
        ;
      } else {
        ;
      }
      int * v7302 = v7243->mem;
      int v7401 = ((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) * 2;
      int v7303 = v7302[v7401];
      int v7402 = (((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) * 2) + 1;
      int v7304 = v7302[v7402];
      int * v7305 = v7243->cache_vals;
      int v7404 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7283 + ((~(((v7285 ^ -1) | (-(v7285 ^ -1))) >> 31)) & 2)) - (v7286 + ((~(((v7287 ^ -1) | (-(v7287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7305[v7404] = v7303;
      int * v7307 = v7243->cache_vals;
      int v7407 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7283 + ((~(((v7285 ^ -1) | (-(v7285 ^ -1))) >> 31)) & 2)) - (v7286 + ((~(((v7287 ^ -1) | (-(v7287 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7307[v7407] = v7304;
      int * v7309 = v7243->cache_tags;
      int v7410 = (int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1);
      v7309[v7386] = v7410;
      int * v7311 = v7243->cache_dirty;
      v7311[v7386] = 0;
      int * v7313 = v7243->cache_age;
      v7313[v7386] = 1;
      int * v7315 = v7243->cache_age;
      int v7316 = v7315[v7386];
      int v7317 = v7315[v7360];
      int v7416 = v7317 + ((int)((unsigned int)(v7317 - v7316) >> 31));
      v7315[v7360] = v7416;
      int * v7319 = v7243->cache_age;
      int v7320 = v7319[v7361];
      int v7418 = v7320 + ((int)((unsigned int)(v7320 - v7316) >> 31));
      v7319[v7361] = v7418;
      int * v7322 = v7243->cache_age;
      v7322[v7386] = 0;
      v7325 = v7386;
    }
    int * v7326 = v7243->cache_vals;
    int v7421 = v7325 * 2;
    int v7327 = v7326[v7421];
    int v7422 = (v7325 * 2) + 1;
    int v7328 = v7326[v7422];
    int v7423 = (((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7267 + ((~(((v7269 ^ -1) | (-(v7269 ^ -1))) >> 31)) & 2)) - (v7270 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7326[v7423] = v7327;
    int * v7330 = v7243->cache_vals;
    int v7426 = ((((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7267 + ((~(((v7269 ^ -1) | (-(v7269 ^ -1))) >> 31)) & 2)) - (v7270 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7330[v7426] = v7328;
    int * v7332 = v7243->cache_tags;
    int v7429 = ((((int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7267 + ((~(((v7269 ^ -1) | (-(v7269 ^ -1))) >> 31)) & 2)) - (v7270 + ((~(((v7271 ^ -1) | (-(v7271 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7430 = (int)((unsigned int)((int)((unsigned int)(v7247 + 20) >> 2)) >> 1);
    v7332[v7429] = v7430;
    int * v7334 = v7243->cache_dirty;
    v7334[v7429] = 0;
    int * v7336 = v7243->cache_age;
    v7336[v7429] = 1;
    int * v7338 = v7243->cache_age;
    int v7339 = v7338[v7429];
    int v7340 = v7338[v7358];
    int v7436 = v7340 + ((int)((unsigned int)(v7340 - v7339) >> 31));
    v7338[v7358] = v7436;
    int * v7342 = v7243->cache_age;
    int v7343 = v7342[v7359];
    int v7438 = v7343 + ((int)((unsigned int)(v7343 - v7339) >> 31));
    v7342[v7359] = v7438;
    int * v7345 = v7243->cache_age;
    v7345[v7429] = 0;
    v7348 = v7429;
  }
  int v7441 = (v7348 * 2) + (((int)((unsigned int)(v7247 + 20) >> 2)) & 1);
  int v7349 = v7255[v7441];
  int * v7350 = v7243->regs;
  v7350[29] = v7349;
  struct StateT * v7352 = slot_93(v7243);
  return v7352;
}

struct StateT * slot_58(struct StateT * v4498) {
  int v4499 = v4498->timer;
  int v4507 = v4499 + 1;
  v4498->timer = v4507;
  int * v4501 = v4498->regs;
  int v4502 = v4501[18];
  int v4503 = v4501[6];
  int v4512 = v4502 + v4503;
  v4501[5] = v4512;
  struct StateT * v4505 = slot_59(v4498);
  return v4505;
}

struct StateT * slot_66(struct StateT * v4652) {
  int v4653 = v4652->timer;
  int v4661 = v4653 + 1;
  v4652->timer = v4661;
  int * v4655 = v4652->regs;
  int v4656 = v4655[5];
  int v4657 = v4655[28];
  int v4665 = v4656 + v4657;
  v4655[28] = v4665;
  struct StateT * v4659 = slot_67(v4652);
  return v4659;
}

struct StateT * slot_48(struct StateT * v4310) {
  int v4311 = v4310->timer;
  int v4319 = v4311 + 1;
  v4310->timer = v4319;
  int * v4313 = v4310->regs;
  int v4314 = v4313[30];
  int v4315 = v4313[6];
  int v4323 = v4314 + v4315;
  v4313[6] = v4323;
  struct StateT * v4317 = slot_49(v4310);
  return v4317;
}

struct StateT * slot_8(struct StateT * v2212) {
  int v2213 = v2212->timer;
  int v2220 = v2213 + 1;
  v2212->timer = v2220;
  int * v2215 = v2212->regs;
  int v2216 = v2215[16];
  int v2223 = v2216 + -1;
  v2215[16] = v2223;
  struct StateT * v2218 = slot_9(v2212);
  return v2218;
}

struct StateT * slot_5(struct StateT * v1740) {
  int v1741 = v1740->timer;
  int v1851 = v1741 + 1;
  v1740->timer = v1851;
  int * v1743 = v1740->regs;
  int v1744 = v1743[11];
  int * v1745 = v1740->cache_tags;
  int v1855 = (((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2;
  int v1746 = v1745[v1855];
  int v1856 = ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1747 = v1745[v1856];
  int v1857 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2);
  int v1748 = v1745[v1857];
  int v1858 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1749 = v1745[v1858];
  int v1750 = v1740->timer;
  int v1859 = v1750 + ((100 ^ (((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1740->timer = v1859;
  int * v1752 = v1740->cache_vals;
  bool v1860 = !(((~(((v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1746 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) == 0);
  int v1845;
  if (v1860) {
    int * v1753 = v1740->cache_age;
    int v1862 = ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((~(((v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1747 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) & 1);
    int v1754 = v1753[v1862];
    int v1755 = v1753[v1855];
    int v1863 = v1755 + ((int)((unsigned int)(v1755 - v1754) >> 31));
    v1753[v1855] = v1863;
    int * v1757 = v1740->cache_age;
    int v1758 = v1757[v1856];
    int v1865 = v1758 + ((int)((unsigned int)(v1758 - v1754) >> 31));
    v1757[v1856] = v1865;
    int * v1760 = v1740->cache_age;
    v1760[v1862] = 0;
    v1845 = v1862;
  } else {
    int * v1763 = v1740->cache_age;
    int v1869 = (((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2;
    int v1764 = v1763[v1869];
    int * v1765 = v1740->cache_tags;
    int v1766 = v1765[v1869];
    int v1767 = v1763[v1856];
    int v1768 = v1765[v1856];
    bool v1871 = !(((~(((v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1748 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) | (~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31))) == 0);
    int v1822;
    if (v1871) {
      int * v1769 = v1740->cache_age;
      int v1873 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))) | (-(v1749 ^ ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1))))) >> 31)) & 1);
      int v1770 = v1769[v1873];
      int v1771 = v1769[v1857];
      int v1874 = v1771 + ((int)((unsigned int)(v1771 - v1770) >> 31));
      v1769[v1857] = v1874;
      int * v1773 = v1740->cache_age;
      int v1774 = v1773[v1858];
      int v1876 = v1774 + ((int)((unsigned int)(v1774 - v1770) >> 31));
      v1773[v1858] = v1876;
      int * v1776 = v1740->cache_age;
      v1776[v1873] = 0;
      v1822 = v1873;
    } else {
      int * v1779 = v1740->cache_age;
      int v1880 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2);
      int v1780 = v1779[v1880];
      int * v1781 = v1740->cache_tags;
      int v1782 = v1781[v1880];
      int v1783 = v1779[v1858];
      int v1784 = v1781[v1858];
      int * v1785 = v1740->cache_dirty;
      int v1883 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1786 = v1785[v1883];
      bool v1884 = !(v1786 == 0);
      if (v1884) {
        int * v1787 = v1740->cache_tags;
        int v1788 = v1787[v1883];
        int * v1789 = v1740->cache_vals;
        int v1887 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1790 = v1789[v1887];
        int v1888 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1791 = v1789[v1888];
        int * v1792 = v1740->mem;
        int v1890 = v1788 * 2;
        v1792[v1890] = v1790;
        int * v1794 = v1740->mem;
        int v1893 = (v1788 * 2) + 1;
        v1794[v1893] = v1791;
        ;
      } else {
        ;
      }
      int * v1799 = v1740->mem;
      int v1898 = ((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) * 2;
      int v1800 = v1799[v1898];
      int v1899 = (((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) * 2) + 1;
      int v1801 = v1799[v1899];
      int * v1802 = v1740->cache_vals;
      int v1901 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1802[v1901] = v1800;
      int * v1804 = v1740->cache_vals;
      int v1904 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 3) * 2)) + ((((v1780 + ((~(((v1782 ^ -1) | (-(v1782 ^ -1))) >> 31)) & 2)) - (v1783 + ((~(((v1784 ^ -1) | (-(v1784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1804[v1904] = v1801;
      int * v1806 = v1740->cache_tags;
      int v1907 = (int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1);
      v1806[v1883] = v1907;
      int * v1808 = v1740->cache_dirty;
      v1808[v1883] = 0;
      int * v1810 = v1740->cache_age;
      v1810[v1883] = 1;
      int * v1812 = v1740->cache_age;
      int v1813 = v1812[v1883];
      int v1814 = v1812[v1857];
      int v1913 = v1814 + ((int)((unsigned int)(v1814 - v1813) >> 31));
      v1812[v1857] = v1913;
      int * v1816 = v1740->cache_age;
      int v1817 = v1816[v1858];
      int v1915 = v1817 + ((int)((unsigned int)(v1817 - v1813) >> 31));
      v1816[v1858] = v1915;
      int * v1819 = v1740->cache_age;
      v1819[v1883] = 0;
      v1822 = v1883;
    }
    int * v1823 = v1740->cache_vals;
    int v1918 = v1822 * 2;
    int v1824 = v1823[v1918];
    int v1919 = (v1822 * 2) + 1;
    int v1825 = v1823[v1919];
    int v1920 = (((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((((v1764 + ((~(((v1766 ^ -1) | (-(v1766 ^ -1))) >> 31)) & 2)) - (v1767 + ((~(((v1768 ^ -1) | (-(v1768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1823[v1920] = v1824;
    int * v1827 = v1740->cache_vals;
    int v1923 = ((((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((((v1764 + ((~(((v1766 ^ -1) | (-(v1766 ^ -1))) >> 31)) & 2)) - (v1767 + ((~(((v1768 ^ -1) | (-(v1768 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1827[v1923] = v1825;
    int * v1829 = v1740->cache_tags;
    int v1926 = ((((int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1)) & 1) * 2) + ((((v1764 + ((~(((v1766 ^ -1) | (-(v1766 ^ -1))) >> 31)) & 2)) - (v1767 + ((~(((v1768 ^ -1) | (-(v1768 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1927 = (int)((unsigned int)((int)((unsigned int)v1744 >> 2)) >> 1);
    v1829[v1926] = v1927;
    int * v1831 = v1740->cache_dirty;
    v1831[v1926] = 0;
    int * v1833 = v1740->cache_age;
    v1833[v1926] = 1;
    int * v1835 = v1740->cache_age;
    int v1836 = v1835[v1926];
    int v1837 = v1835[v1855];
    int v1933 = v1837 + ((int)((unsigned int)(v1837 - v1836) >> 31));
    v1835[v1855] = v1933;
    int * v1839 = v1740->cache_age;
    int v1840 = v1839[v1856];
    int v1935 = v1840 + ((int)((unsigned int)(v1840 - v1836) >> 31));
    v1839[v1856] = v1935;
    int * v1842 = v1740->cache_age;
    v1842[v1926] = 0;
    v1845 = v1926;
  }
  int v1938 = (v1845 * 2) + (((int)((unsigned int)v1744 >> 2)) & 1);
  int v1846 = v1752[v1938];
  int * v1847 = v1740->regs;
  v1847[14] = v1846;
  struct StateT * v1849 = slot_6(v1740);
  return v1849;
}

struct StateT * slot_44(struct StateT * v4244) {
  int v4245 = v4244->timer;
  int v4253 = v4245 + 1;
  v4244->timer = v4253;
  int * v4247 = v4244->regs;
  int v4248 = v4247[5];
  int v4249 = v4247[29];
  int v4257 = v4248 | v4249;
  v4247[5] = v4257;
  struct StateT * v4251 = slot_45(v4244);
  return v4251;
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