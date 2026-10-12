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

struct StateT * slot_143(struct StateT * v7977);
struct StateT * slot_120(struct StateT * v7620);
struct StateT * slot_226(struct StateT * v14420);
struct StateT * slot_167(struct StateT * v8349);
struct StateT * slot_509(struct StateT * v18947);
struct StateT * slot_152(struct StateT * v8115);
struct StateT * slot_429(struct StateT * v17643);
struct StateT * slot_231(struct StateT * v14470);
struct StateT * slot_355(struct StateT * v16404);
struct StateT * slot_92(struct StateT * v7144);
struct StateT * slot_232(struct StateT * v14484);
struct StateT * slot_466(struct StateT * v18278);
struct StateT * slot_304(struct StateT * v15613);
struct StateT * slot_31(struct StateT * v6091);
struct StateT * slot_236(struct StateT * v14548);
struct StateT * slot_241(struct StateT * v14632);
struct StateT * slot_160(struct StateT * v8244);
struct StateT * slot_519(struct StateT * v19101);
struct StateT * slot_150(struct StateT * v8083);
struct StateT * slot_391(struct StateT * v16992);
struct StateT * slot_74(struct StateT * v6844);
struct StateT * slot_262(struct StateT * v14959);
struct StateT * slot_351(struct StateT * v16342);
struct StateT * slot_372(struct StateT * v16668);
struct StateT * slot_403(struct StateT * v17213);
struct StateT * slot_107(struct StateT * v7385);
struct StateT * slot_325(struct StateT * v15940);
struct StateT * slot_84(struct StateT * v7000);
struct StateT * slot_28(struct StateT * v6049);
struct StateT * slot_155(struct StateT * v8165);
struct StateT * slot_177(struct StateT * v8511);
struct StateT * slot_517(struct StateT * v19069);
struct StateT * slot_358(struct StateT * v16453);
struct StateT * slot_465(struct StateT * v18262);
struct StateT * slot_181(struct StateT * v8571);
struct StateT * slot_154(struct StateT * v8148);
struct StateT * slot_260(struct StateT * v14927);
struct StateT * slot_481(struct StateT * v18511);
struct StateT * slot_305(struct StateT * v15628);
struct StateT * slot_27(struct StateT * v6034);
struct StateT * slot_454(struct StateT * v18057);
struct StateT * slot_34(struct StateT * v6136);
struct StateT * slot_482(struct StateT * v18528);
struct StateT * slot_21(struct StateT * v5572);
struct StateT * slot_406(struct StateT * v17258);
struct StateT * slot_292(struct StateT * v15420);
struct StateT * slot_118(struct StateT * v7590);
struct StateT * slot_525(struct StateT * v19198);
struct StateT * slot_515(struct StateT * v19037);
struct StateT * slot_376(struct StateT * v16732);
struct StateT * slot_373(struct StateT * v16684);
struct StateT * slot_94(struct StateT * v7184);
struct StateT * slot_340(struct StateT * v16175);
struct StateT * slot_146(struct StateT * v8022);
struct StateT * slot_383(struct StateT * v16866);
struct StateT * slot_24(struct StateT * v5993);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v18635);
struct StateT * slot_286(struct StateT * v15330);
struct StateT * slot_520(struct StateT * v19118);
struct StateT * slot_125(struct StateT * v7694);
struct StateT * slot_254(struct StateT * v14828);
struct StateT * slot_148(struct StateT * v8051);
struct StateT * slot_421(struct StateT * v17519);
struct StateT * slot_126(struct StateT * v7710);
struct StateT * slot_363(struct StateT * v16533);
struct StateT * slot_79(struct StateT * v6924);
struct StateT * slot_367(struct StateT * v16594);
struct StateT * slot_437(struct StateT * v17779);
struct StateT * slot_341(struct StateT * v16192);
struct StateT * slot_142(struct StateT * v7961);
struct StateT * slot_416(struct StateT * v17416);
struct StateT * slot_280(struct StateT * v15239);
struct StateT * slot_272(struct StateT * v15108);
struct StateT * slot_47(struct StateT * v6365);
struct StateT * slot_214(struct StateT * v13763);
struct StateT * slot_297(struct StateT * v15500);
struct StateT * slot_29(struct StateT * v6064);
struct StateT * slot_314(struct StateT * v15764);
struct StateT * slot_151(struct StateT * v8099);
struct StateT * slot_7(struct StateT * v1906);
struct StateT * slot_124(struct StateT * v7680);
struct StateT * slot_128(struct StateT * v7739);
struct StateT * slot_365(struct StateT * v16564);
struct StateT * slot_441(struct StateT * v17859);
struct StateT * slot_19(struct StateT * v5164);
struct StateT * slot_382(struct StateT * v16842);
struct StateT * slot_523(struct StateT * v19169);
struct StateT * slot_87(struct StateT * v7045);
struct StateT * slot_452(struct StateT * v18028);
struct StateT * slot_67(struct StateT * v6705);
struct StateT * slot_81(struct StateT * v6955);
struct StateT * slot_337(struct StateT * v16124);
struct StateT * slot_32(struct StateT * v6104);
struct StateT * slot_233(struct StateT * v14500);
struct StateT * slot_176(struct StateT * v8494);
struct StateT * slot_189(struct StateT * v8691);
struct StateT * slot_394(struct StateT * v17037);
struct StateT * slot_398(struct StateT * v17122);
struct StateT * slot_33(struct StateT * v6112);
struct StateT * slot_371(struct StateT * v16654);
struct StateT * slot_330(struct StateT * v16015);
struct StateT * slot_450(struct StateT * v17998);
struct StateT * slot_35(struct StateT * v6160);
struct StateT * slot_484(struct StateT * v18560);
struct StateT * slot_258(struct StateT * v14893);
struct StateT * slot_166(struct StateT * v8334);
struct StateT * slot_418(struct StateT * v17462);
struct StateT * slot_51(struct StateT * v6441);
struct StateT * slot_25(struct StateT * v6006);
struct StateT * slot_490(struct StateT * v18650);
struct StateT * slot_264(struct StateT * v14989);
struct StateT * slot_339(struct StateT * v16158);
struct StateT * slot_123(struct StateT * v7665);
struct StateT * slot_97(struct StateT * v7235);
struct StateT * slot_106(struct StateT * v7370);
struct StateT * slot_299(struct StateT * v15534);
struct StateT * slot_539(struct StateT * v19413);
struct StateT * slot_319(struct StateT * v15846);
struct StateT * slot_344(struct StateT * v16237);
struct StateT * slot_513(struct StateT * v19007);
struct StateT * slot_130(struct StateT * v7771);
struct StateT * slot_497(struct StateT * v18757);
struct StateT * slot_455(struct StateT * v18073);
struct StateT * slot_141(struct StateT * v7947);
struct StateT * slot_432(struct StateT * v17688);
struct StateT * slot_306(struct StateT * v15642);
struct StateT * slot_312(struct StateT * v15732);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_240(struct StateT * v14615);
struct StateT * slot_247(struct StateT * v14722);
struct StateT * slot_70(struct StateT * v6758);
struct StateT * slot_168(struct StateT * v8363);
struct StateT * slot_348(struct StateT * v16297);
struct StateT * slot_456(struct StateT * v18096);
struct StateT * slot_225(struct StateT * v14406);
struct StateT * slot_467(struct StateT * v18293);
struct StateT * slot_285(struct StateT * v15316);
struct StateT * slot_213(struct StateT * v13341);
struct StateT * slot_82(struct StateT * v6969);
struct StateT * slot_263(struct StateT * v14973);
struct StateT * slot_161(struct StateT * v8259);
struct StateT * slot_293(struct StateT * v15436);
struct StateT * slot_185(struct StateT * v8630);
struct StateT * slot_288(struct StateT * v15361);
struct StateT * slot_89(struct StateT * v7075);
struct StateT * slot_384(struct StateT * v16888);
struct StateT * slot_486(struct StateT * v18590);
struct StateT * slot_347(struct StateT * v16282);
struct StateT * slot_140(struct StateT * v7932);
struct StateT * slot_473(struct StateT * v18383);
struct StateT * slot_49(struct StateT * v6395);
struct StateT * slot_216(struct StateT * v12902);
struct StateT * slot_468(struct StateT * v18307);
struct StateT * slot_50(struct StateT * v6418);
struct StateT * slot_135(struct StateT * v7853);
struct StateT * slot_248(struct StateT * v14737);
struct StateT * slot_59(struct StateT * v6584);
struct StateT * slot_485(struct StateT * v18574);
struct StateT * slot_40(struct StateT * v6260);
struct StateT * slot_77(struct StateT * v6895);
struct StateT * slot_85(struct StateT * v7014);
struct StateT * slot_350(struct StateT * v16327);
struct StateT * slot_392(struct StateT * v17008);
struct StateT * slot_75(struct StateT * v6861);
struct StateT * slot_71(struct StateT * v6781);
struct StateT * slot_378(struct StateT * v16762);
struct StateT * slot_108(struct StateT * v7399);
struct StateT * slot_116(struct StateT * v7558);
struct StateT * slot_417(struct StateT * v17439);
struct StateT * slot_405(struct StateT * v17242);
struct StateT * slot_215(struct StateT * v12698);
struct StateT * slot_45(struct StateT * v6334);
struct StateT * slot_220(struct StateT * v13749);
struct StateT * slot_134(struct StateT * v7836);
struct StateT * slot_463(struct StateT * v18233);
struct StateT * slot_175(struct StateT * v8477);
struct StateT * slot_387(struct StateT * v16933);
struct StateT * slot_273(struct StateT * v15124);
struct StateT * slot_69(struct StateT * v6735);
struct StateT * slot_188(struct StateT * v8675);
struct StateT * slot_495(struct StateT * v18725);
struct StateT * slot_186(struct StateT * v8646);
struct StateT * slot_102(struct StateT * v7309);
struct StateT * slot_145(struct StateT * v8006);
struct StateT * slot_110(struct StateT * v7438);
struct StateT * slot_208(struct StateT * v11275);
struct StateT * slot_301(struct StateT * v15568);
struct StateT * slot_502(struct StateT * v18840);
struct StateT * slot_506(struct StateT * v18902);
struct StateT * slot_413(struct StateT * v17363);
struct StateT * slot_320(struct StateT * v15863);
struct StateT * slot_281(struct StateT * v15256);
struct StateT * slot_533(struct StateT * v19319);
struct StateT * slot_203(struct StateT * v10296);
struct StateT * slot_190(struct StateT * v8707);
struct StateT * slot_157(struct StateT * v8199);
struct StateT * slot_447(struct StateT * v17953);
struct StateT * slot_243(struct StateT * v14661);
struct StateT * slot_173(struct StateT * v8443);
struct StateT * slot_307(struct StateT * v15658);
struct StateT * slot_453(struct StateT * v18043);
struct StateT * slot_54(struct StateT * v6504);
struct StateT * slot_26(struct StateT * v6019);
struct StateT * slot_370(struct StateT * v16639);
struct StateT * slot_206(struct StateT * v10943);
struct StateT * slot_227(struct StateT * v14434);
struct StateT * slot_169(struct StateT * v8379);
struct StateT * slot_442(struct StateT * v17876);
struct StateT * slot_529(struct StateT * v19259);
struct StateT * slot_14(struct StateT * v3532);
struct StateT * slot_357(struct StateT * v16436);
struct StateT * slot_385(struct StateT * v16902);
struct StateT * slot_444(struct StateT * v17908);
struct StateT * slot_261(struct StateT * v14944);
struct StateT * slot_287(struct StateT * v15346);
struct StateT * slot_343(struct StateT * v16221);
struct StateT * slot_36(struct StateT * v6184);
struct StateT * slot_57(struct StateT * v6555);
struct StateT * slot_426(struct StateT * v17598);
struct StateT * slot_536(struct StateT * v19365);
struct StateT * slot_470(struct StateT * v18338);
struct StateT * slot_431(struct StateT * v17672);
struct StateT * slot_62(struct StateT * v6629);
struct StateT * slot_308(struct StateT * v15673);
struct StateT * slot_400(struct StateT * v17162);
struct StateT * slot_323(struct StateT * v15909);
struct StateT * slot_521(struct StateT * v19135);
struct StateT * slot_530(struct StateT * v19274);
struct StateT * slot_23(struct StateT * v5980);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v7030);
struct StateT * slot_538(struct StateT * v19397);
struct StateT * slot_100(struct StateT * v7280);
struct StateT * slot_127(struct StateT * v7725);
struct StateT * slot_411(struct StateT * v17332);
struct StateT * slot_13(struct StateT * v4552);
struct StateT * slot_449(struct StateT * v17983);
struct StateT * slot_460(struct StateT * v18182);
struct StateT * slot_109(struct StateT * v7415);
struct StateT * slot_474(struct StateT * v18397);
struct StateT * slot_174(struct StateT * v8460);
struct StateT * slot_42(struct StateT * v6289);
struct StateT * slot_224(struct StateT * v14391);
struct StateT * slot_184(struct StateT * v8616);
struct StateT * slot_462(struct StateT * v18216);
struct StateT * slot_165(struct StateT * v8318);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_393(struct StateT * v17023);
struct StateT * slot_507(struct StateT * v18917);
struct StateT * slot_477(struct StateT * v18445);
struct StateT * slot_278(struct StateT * v15205);
struct StateT * slot_352(struct StateT * v16356);
struct StateT * slot_249(struct StateT * v14751);
struct StateT * slot_11(struct StateT * v3736);
struct StateT * slot_12(struct StateT * v4144);
struct StateT * slot_228(struct StateT * v14439);
struct StateT * slot_268(struct StateT * v15049);
struct StateT * slot_199(struct StateT * v9632);
struct StateT * slot_252(struct StateT * v14796);
struct StateT * slot_409(struct StateT * v17303);
struct StateT * slot_374(struct StateT * v16700);
struct StateT * slot_269(struct StateT * v15063);
struct StateT * slot_501(struct StateT * v18823);
struct StateT * slot_251(struct StateT * v14782);
struct StateT * slot_65(struct StateT * v6674);
struct StateT * slot_10(struct StateT * v3519);
struct StateT * slot_322(struct StateT * v15895);
struct StateT * slot_277(struct StateT * v15188);
struct StateT * slot_353(struct StateT * v16372);
struct StateT * slot_397(struct StateT * v17099);
struct StateT * slot_435(struct StateT * v17733);
struct StateT * slot_476(struct StateT * v18429);
struct StateT * slot_136(struct StateT * v7870);
struct StateT * slot_379(struct StateT * v16770);
struct StateT * slot_475(struct StateT * v18413);
struct StateT * slot_310(struct StateT * v15703);
struct StateT * slot_445(struct StateT * v17922);
struct StateT * slot_295(struct StateT * v15468);
struct StateT * slot_315(struct StateT * v15780);
struct StateT * slot_17(struct StateT * v4756);
struct StateT * slot_197(struct StateT * v9295);
struct StateT * slot_457(struct StateT * v18119);
struct StateT * slot_207(struct StateT * v10960);
struct StateT * slot_156(struct StateT * v8182);
struct StateT * slot_68(struct StateT * v6719);
struct StateT * slot_493(struct StateT * v18695);
struct StateT * slot_105(struct StateT * v7354);
struct StateT * slot_430(struct StateT * v17658);
struct StateT * slot_369(struct StateT * v16623);
struct StateT * slot_461(struct StateT * v18199);
struct StateT * slot_164(struct StateT * v8304);
struct StateT * slot_15(struct StateT * v3940);
struct StateT * slot_480(struct StateT * v18494);
struct StateT * slot_133(struct StateT * v7819);
struct StateT * slot_56(struct StateT * v6538);
struct StateT * slot_244(struct StateT * v14677);
struct StateT * slot_222(struct StateT * v14171);
struct StateT * slot_171(struct StateT * v8411);
struct StateT * slot_162(struct StateT * v8273);
struct StateT * slot_377(struct StateT * v16748);
struct StateT * slot_427(struct StateT * v17613);
struct StateT * slot_399(struct StateT * v17145);
struct StateT * slot_239(struct StateT * v14598);
struct StateT * slot_464(struct StateT * v18248);
struct StateT * slot_500(struct StateT * v18806);
struct StateT * slot_433(struct StateT * v17703);
struct StateT * slot_121(struct StateT * v7635);
struct StateT * slot_144(struct StateT * v7992);
struct StateT * slot_267(struct StateT * v15034);
struct StateT * slot_492(struct StateT * v18680);
struct StateT * slot_201(struct StateT * v9964);
struct StateT * slot_63(struct StateT * v6645);
struct StateT * slot_195(struct StateT * v8972);
struct StateT * slot_326(struct StateT * v15954);
struct StateT * slot_303(struct StateT * v15597);
struct StateT * slot_511(struct StateT * v18976);
struct StateT * slot_335(struct StateT * v16092);
struct StateT * slot_223(struct StateT * v14187);
struct StateT * slot_316(struct StateT * v15796);
struct StateT * slot_424(struct StateT * v17568);
struct StateT * slot_332(struct StateT * v16044);
struct StateT * slot_237(struct StateT * v14564);
struct StateT * slot_41(struct StateT * v6275);
struct StateT * slot_39(struct StateT * v6244);
struct StateT * slot_508(struct StateT * v18931);
struct StateT * slot_537(struct StateT * v19381);
struct StateT * slot_60(struct StateT * v6600);
struct StateT * slot_289(struct StateT * v15375);
struct StateT * slot_238(struct StateT * v14581);
struct StateT * slot_112(struct StateT * v7484);
struct StateT * slot_256(struct StateT * v14860);
struct StateT * slot_16(struct StateT * v4348);
struct StateT * slot_245(struct StateT * v14692);
struct StateT * slot_113(struct StateT * v7507);
struct StateT * slot_302(struct StateT * v15583);
struct StateT * slot_388(struct StateT * v16947);
struct StateT * slot_191(struct StateT * v8723);
struct StateT * slot_103(struct StateT * v7325);
struct StateT * slot_487(struct StateT * v18605);
struct StateT * slot_324(struct StateT * v15925);
struct StateT * slot_440(struct StateT * v17842);
struct StateT * slot_518(struct StateT * v19085);
struct StateT * slot_95(struct StateT * v7201);
struct StateT * slot_451(struct StateT * v18012);
struct StateT * slot_458(struct StateT * v18142);
struct StateT * slot_415(struct StateT * v17393);
struct StateT * slot_354(struct StateT * v16388);
struct StateT * slot_531(struct StateT * v19288);
struct StateT * slot_115(struct StateT * v7541);
struct StateT * slot_78(struct StateT * v6910);
struct StateT * slot_321(struct StateT * v15880);
struct StateT * slot_317(struct StateT * v15812);
struct StateT * slot_205(struct StateT * v10628);
struct StateT * slot_193(struct StateT * v8755);
struct StateT * slot_375(struct StateT * v16716);
struct StateT * slot_331(struct StateT * v16030);
struct StateT * slot_380(struct StateT * v16794);
struct StateT * slot_412(struct StateT * v17348);
struct StateT * slot_381(struct StateT * v16818);
struct StateT * slot_478(struct StateT * v18461);
struct StateT * slot_246(struct StateT * v14706);
struct StateT * slot_210(struct StateT * v12480);
struct StateT * slot_472(struct StateT * v18368);
struct StateT * slot_284(struct StateT * v15301);
struct StateT * slot_52(struct StateT * v6464);
struct StateT * slot_83(struct StateT * v6985);
struct StateT * slot_209(struct StateT * v11290);
struct StateT * slot_420(struct StateT * v17502);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_73(struct StateT * v6827);
struct StateT * slot_270(struct StateT * v15079);
struct StateT * slot_198(struct StateT * v9610);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v8661);
struct StateT * slot_446(struct StateT * v17938);
struct StateT * slot_182(struct StateT * v8585);
struct StateT * slot_361(struct StateT * v16504);
struct StateT * slot_38(struct StateT * v6230);
struct StateT * slot_178(struct StateT * v8526);
struct StateT * slot_98(struct StateT * v7250);
struct StateT * slot_159(struct StateT * v8228);
struct StateT * slot_510(struct StateT * v18962);
struct StateT * slot_459(struct StateT * v18165);
struct StateT * slot_404(struct StateT * v17228);
struct StateT * slot_46(struct StateT * v6350);
struct StateT * slot_212(struct StateT * v12918);
struct StateT * slot_132(struct StateT * v7803);
struct StateT * slot_313(struct StateT * v15748);
struct StateT * slot_211(struct StateT * v12494);
struct StateT * slot_20(struct StateT * v5368);
struct StateT * slot_436(struct StateT * v17756);
struct StateT * slot_61(struct StateT * v6615);
struct StateT * slot_499(struct StateT * v18789);
struct StateT * slot_359(struct StateT * v16470);
struct StateT * slot_514(struct StateT * v19021);
struct StateT * slot_296(struct StateT * v15484);
struct StateT * slot_30(struct StateT * v6077);
struct StateT * slot_18(struct StateT * v4960);
struct StateT * slot_9(struct StateT * v2536);
struct StateT * slot_300(struct StateT * v15551);
struct StateT * slot_183(struct StateT * v8601);
struct StateT * slot_282(struct StateT * v15271);
struct StateT * slot_309(struct StateT * v15687);
struct StateT * slot_362(struct StateT * v16519);
struct StateT * slot_43(struct StateT * v6305);
struct StateT * slot_76(struct StateT * v6878);
struct StateT * slot_6(struct StateT * v1591);
struct StateT * slot_55(struct StateT * v6521);
struct StateT * slot_283(struct StateT * v15285);
struct StateT * slot_346(struct StateT * v16266);
struct StateT * slot_516(struct StateT * v19053);
struct StateT * slot_274(struct StateT * v15140);
struct StateT * slot_535(struct StateT * v19349);
struct StateT * slot_318(struct StateT * v15829);
struct StateT * slot_91(struct StateT * v7121);
struct StateT * slot_58(struct StateT * v6570);
struct StateT * slot_255(struct StateT * v14844);
struct StateT * slot_540(struct StateT * v19434);
struct StateT * slot_66(struct StateT * v6690);
struct StateT * slot_368(struct StateT * v16609);
struct StateT * slot_265(struct StateT * v15004);
struct StateT * slot_37(struct StateT * v6208);
struct StateT * slot_114(struct StateT * v7524);
struct StateT * slot_257(struct StateT * v14876);
struct StateT * slot_192(struct StateT * v8739);
struct StateT * slot_327(struct StateT * v15970);
struct StateT * slot_48(struct StateT * v6379);
struct StateT * slot_396(struct StateT * v17076);
struct StateT * slot_528(struct StateT * v19243);
struct StateT * slot_72(struct StateT * v6804);
struct StateT * slot_526(struct StateT * v19214);
struct StateT * slot_119(struct StateT * v7604);
struct StateT * slot_101(struct StateT * v7295);
struct StateT * slot_276(struct StateT * v15172);
struct StateT * slot_290(struct StateT * v15391);
struct StateT * slot_93(struct StateT * v7167);
struct StateT * slot_266(struct StateT * v15018);
struct StateT * slot_88(struct StateT * v7059);
struct StateT * slot_96(struct StateT * v7218);
struct StateT * slot_234(struct StateT * v14516);
struct StateT * slot_471(struct StateT * v18352);
struct StateT * slot_419(struct StateT * v17485);
struct StateT * slot_218(struct StateT * v13326);
struct StateT * slot_202(struct StateT * v10279);
struct StateT * slot_336(struct StateT * v16108);
struct StateT * slot_230(struct StateT * v14455);
struct StateT * slot_294(struct StateT * v15452);
struct StateT * slot_408(struct StateT * v17287);
struct StateT * slot_342(struct StateT * v16207);
struct StateT * slot_488(struct StateT * v18619);
struct StateT * slot_439(struct StateT * v17825);
struct StateT * slot_389(struct StateT * v16963);
struct StateT * slot_479(struct StateT * v18477);
struct StateT * slot_138(struct StateT * v7902);
struct StateT * slot_483(struct StateT * v18545);
struct StateT * slot_196(struct StateT * v9287);
struct StateT * slot_172(struct StateT * v8427);
struct StateT * slot_425(struct StateT * v17582);
struct StateT * slot_443(struct StateT * v17893);
struct StateT * slot_131(struct StateT * v7787);
struct StateT * slot_8(struct StateT * v2221);
struct StateT * slot_534(struct StateT * v19333);
struct StateT * slot_180(struct StateT * v8556);
struct StateT * slot_504(struct StateT * v18872);
struct StateT * slot_512(struct StateT * v18992);
struct StateT * slot_496(struct StateT * v18741);
struct StateT * slot_494(struct StateT * v18709);
struct StateT * slot_242(struct StateT * v14647);
struct StateT * slot_328(struct StateT * v15985);
struct StateT * slot_402(struct StateT * v17196);
struct StateT * slot_200(struct StateT * v9947);
struct StateT * slot_149(struct StateT * v8067);
struct StateT * slot_527(struct StateT * v19229);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_334(struct StateT * v16076);
struct StateT * slot_104(struct StateT * v7340);
struct StateT * slot_235(struct StateT * v14532);
struct StateT * slot_275(struct StateT * v15156);
struct StateT * slot_329(struct StateT * v15999);
struct StateT * slot_428(struct StateT * v17627);
struct StateT * slot_395(struct StateT * v17053);
struct StateT * slot_345(struct StateT * v16252);
struct StateT * slot_298(struct StateT * v15517);
struct StateT * slot_414(struct StateT * v17377);
struct StateT * slot_364(struct StateT * v16549);
struct StateT * slot_356(struct StateT * v16420);
struct StateT * slot_253(struct StateT * v14812);
struct StateT * slot_434(struct StateT * v17717);
struct StateT * slot_64(struct StateT * v6660);
struct StateT * slot_170(struct StateT * v8395);
struct StateT * slot_53(struct StateT * v6487);
struct StateT * slot_522(struct StateT * v19152);
struct StateT * slot_80(struct StateT * v6940);
struct StateT * slot_503(struct StateT * v18857);
struct StateT * slot_390(struct StateT * v16978);
struct StateT * slot_44(struct StateT * v6320);
struct StateT * slot_137(struct StateT * v7887);
struct StateT * slot_386(struct StateT * v16918);
struct StateT * slot_122(struct StateT * v7649);
struct StateT * slot_99(struct StateT * v7264);
struct StateT * slot_179(struct StateT * v8540);
struct StateT * slot_219(struct StateT * v13545);
struct StateT * slot_338(struct StateT * v16141);
struct StateT * slot_22(struct StateT * v5776);
struct StateT * slot_366(struct StateT * v16578);
struct StateT * slot_139(struct StateT * v7916);
struct StateT * slot_438(struct StateT * v17802);
struct StateT * slot_333(struct StateT * v16060);
struct StateT * slot_221(struct StateT * v13967);
struct StateT * slot_153(struct StateT * v8131);
struct StateT * slot_129(struct StateT * v7755);
struct StateT * slot_158(struct StateT * v8214);
struct StateT * slot_311(struct StateT * v15718);
struct StateT * slot_498(struct StateT * v18773);
struct StateT * slot_279(struct StateT * v15222);
struct StateT * slot_271(struct StateT * v15094);
struct StateT * slot_524(struct StateT * v19184);
struct StateT * slot_505(struct StateT * v18886);
struct StateT * slot_401(struct StateT * v17179);
struct StateT * slot_423(struct StateT * v17553);
struct StateT * slot_532(struct StateT * v19304);
struct StateT * slot_217(struct StateT * v13122);
struct StateT * slot_111(struct StateT * v7461);
struct StateT * slot_349(struct StateT * v16311);
struct StateT * slot_291(struct StateT * v15406);
struct StateT * slot_147(struct StateT * v8037);
struct StateT * slot_410(struct StateT * v17318);
struct StateT * slot_491(struct StateT * v18664);
struct StateT * slot_163(struct StateT * v8289);
struct StateT * slot_422(struct StateT * v17536);
struct StateT * slot_448(struct StateT * v17967);
struct StateT * slot_204(struct StateT * v10611);
struct StateT * slot_194(struct StateT * v8776);
struct StateT * slot_407(struct StateT * v17273);
struct StateT * slot_250(struct StateT * v14767);
struct StateT * slot_360(struct StateT * v16487);
struct StateT * slot_259(struct StateT * v14910);
struct StateT * slot_469(struct StateT * v18323);
struct StateT * slot_117(struct StateT * v7575);
struct StateT * slot_90(struct StateT * v7098);
struct StateT * slot_143(struct StateT * v7977) {
  int v7978 = v7977->timer;
  int v7985 = v7978 + 1;
  v7977->timer = v7985;
  int * v7980 = v7977->regs;
  int v7981 = v7980[22];
  int v7989 = (int)((unsigned int)v7981 >> 23);
  v7980[24] = v7989;
  struct StateT * v7983 = slot_144(v7977);
  return v7983;
}

struct StateT * slot_120(struct StateT * v7620) {
  int v7621 = v7620->timer;
  int v7628 = v7621 + 1;
  v7620->timer = v7628;
  int * v7623 = v7620->regs;
  int v7624 = v7623[21];
  int v7632 = (int)((unsigned int)v7624 >> 25);
  v7623[24] = v7632;
  struct StateT * v7626 = slot_121(v7620);
  return v7626;
}

struct StateT * slot_226(struct StateT * v14420) {
  int v14421 = v14420->timer;
  int v14428 = v14421 + 1;
  v14420->timer = v14428;
  int * v14423 = v14420->regs;
  int v14424 = v14423[22];
  int v14431 = v14424 << 7;
  v14423[22] = v14431;
  struct StateT * v14426 = slot_228(v14420);
  return v14426;
}

struct StateT * slot_167(struct StateT * v8349) {
  int v8350 = v8349->timer;
  int v8357 = v8350 + 1;
  v8349->timer = v8357;
  int * v8352 = v8349->regs;
  int v8353 = v8352[23];
  int v8360 = v8353 << 13;
  v8352[23] = v8360;
  struct StateT * v8355 = slot_168(v8349);
  return v8355;
}

struct StateT * slot_509(struct StateT * v18947) {
  int v18948 = v18947->timer;
  int v18955 = v18948 + 1;
  v18947->timer = v18955;
  int * v18950 = v18947->regs;
  int v18951 = v18950[22];
  int v18959 = (int)((unsigned int)v18951 >> 19);
  v18950[24] = v18959;
  struct StateT * v18953 = slot_510(v18947);
  return v18953;
}

struct StateT * slot_152(struct StateT * v8115) {
  int v8116 = v8115->timer;
  int v8124 = v8116 + 1;
  v8115->timer = v8124;
  int * v8118 = v8115->regs;
  int v8119 = v8118[7];
  int v8120 = v8118[23];
  int v8128 = v8119 ^ v8120;
  v8118[7] = v8128;
  struct StateT * v8122 = slot_153(v8115);
  return v8122;
}

struct StateT * slot_429(struct StateT * v17643) {
  int v17644 = v17643->timer;
  int v17651 = v17644 + 1;
  v17643->timer = v17651;
  int * v17646 = v17643->regs;
  int v17647 = v17646[22];
  int v17655 = (int)((unsigned int)v17647 >> 19);
  v17646[24] = v17655;
  struct StateT * v17649 = slot_430(v17643);
  return v17649;
}

struct StateT * slot_231(struct StateT * v14470) {
  int v14471 = v14470->timer;
  int v14478 = v14471 + 1;
  v14470->timer = v14478;
  int * v14473 = v14470->regs;
  int v14474 = v14473[23];
  int v14481 = v14474 << 7;
  v14473[23] = v14481;
  struct StateT * v14476 = slot_232(v14470);
  return v14476;
}

struct StateT * slot_355(struct StateT * v16404) {
  int v16405 = v16404->timer;
  int v16413 = v16405 + 1;
  v16404->timer = v16413;
  int * v16407 = v16404->regs;
  int v16408 = v16407[18];
  int v16409 = v16407[22];
  int v16417 = v16408 ^ v16409;
  v16407[18] = v16417;
  struct StateT * v16411 = slot_356(v16404);
  return v16411;
}

struct StateT * slot_92(struct StateT * v7144) {
  int * v7145 = v7144->saved_regs;
  int * v7146 = v7144->regs;
  int v7147 = v7146[15];
  v7145[15] = v7147;
  int v7149 = v7144->timer;
  int v7161 = v7149 + 1;
  v7144->timer = v7161;
  int * v7151 = v7144->regs;
  int v7152 = v7151[15];
  int v7153 = v7151[23];
  int v7164 = v7152 ^ v7153;
  v7151[15] = v7164;
  struct StateT * v7155 = slot_93(v7144);
  return v7155;
}

struct StateT * slot_232(struct StateT * v14484) {
  int v14485 = v14484->timer;
  int v14493 = v14485 + 1;
  v14484->timer = v14493;
  int * v14487 = v14484->regs;
  int v14488 = v14487[23];
  int v14489 = v14487[24];
  int v14497 = v14488 | v14489;
  v14487[23] = v14497;
  struct StateT * v14491 = slot_233(v14484);
  return v14491;
}

struct StateT * slot_466(struct StateT * v18278) {
  int v18279 = v18278->timer;
  int v18286 = v18279 + 1;
  v18278->timer = v18286;
  int * v18281 = v18278->regs;
  int v18282 = v18281[21];
  int v18290 = (int)((unsigned int)v18282 >> 25);
  v18281[24] = v18290;
  struct StateT * v18284 = slot_467(v18278);
  return v18284;
}

struct StateT * slot_304(struct StateT * v15613) {
  int v15614 = v15613->timer;
  int v15621 = v15614 + 1;
  v15613->timer = v15621;
  int * v15616 = v15613->regs;
  int v15617 = v15616[21];
  int v15625 = (int)((unsigned int)v15617 >> 25);
  v15616[24] = v15625;
  struct StateT * v15619 = slot_305(v15613);
  return v15619;
}

struct StateT * slot_31(struct StateT * v6091) {
  int v6092 = v6091->timer;
  int v6098 = v6092 + 1;
  v6091->timer = v6098;
  int * v6094 = v6091->regs;
  v6094[11] = 9;
  struct StateT * v6096 = slot_32(v6091);
  return v6096;
}

struct StateT * slot_236(struct StateT * v14548) {
  int v14549 = v14548->timer;
  int v14557 = v14549 + 1;
  v14548->timer = v14557;
  int * v14551 = v14548->regs;
  int v14552 = v14551[8];
  int v14553 = v14551[23];
  int v14561 = v14552 ^ v14553;
  v14551[8] = v14561;
  struct StateT * v14555 = slot_237(v14548);
  return v14555;
}

struct StateT * slot_241(struct StateT * v14632) {
  int v14633 = v14632->timer;
  int v14640 = v14633 + 1;
  v14632->timer = v14640;
  int * v14635 = v14632->regs;
  int v14636 = v14635[20];
  int v14644 = (int)((unsigned int)v14636 >> 23);
  v14635[24] = v14644;
  struct StateT * v14638 = slot_242(v14632);
  return v14638;
}

struct StateT * slot_160(struct StateT * v8244) {
  int v8245 = v8244->timer;
  int v8252 = v8245 + 1;
  v8244->timer = v8252;
  int * v8247 = v8244->regs;
  int v8248 = v8247[21];
  int v8256 = (int)((unsigned int)v8248 >> 19);
  v8247[24] = v8256;
  struct StateT * v8250 = slot_161(v8244);
  return v8250;
}

struct StateT * slot_519(struct StateT * v19101) {
  int v19102 = v19101->timer;
  int v19110 = v19102 + 1;
  v19101->timer = v19110;
  int * v19104 = v19101->regs;
  int v19105 = v19104[8];
  int v19106 = v19104[17];
  int v19115 = v19105 + v19106;
  v19104[20] = v19115;
  struct StateT * v19108 = slot_520(v19101);
  return v19108;
}

struct StateT * slot_150(struct StateT * v8083) {
  int v8084 = v8083->timer;
  int v8092 = v8084 + 1;
  v8083->timer = v8092;
  int * v8086 = v8083->regs;
  int v8087 = v8086[5];
  int v8088 = v8086[21];
  int v8096 = v8087 ^ v8088;
  v8086[5] = v8096;
  struct StateT * v8090 = slot_151(v8083);
  return v8090;
}

struct StateT * slot_391(struct StateT * v16992) {
  int v16993 = v16992->timer;
  int v17001 = v16993 + 1;
  v16992->timer = v17001;
  int * v16995 = v16992->regs;
  int v16996 = v16995[22];
  int v16997 = v16995[24];
  int v17005 = v16996 | v16997;
  v16995[22] = v17005;
  struct StateT * v16999 = slot_392(v16992);
  return v16999;
}

struct StateT * slot_74(struct StateT * v6844) {
  int v6845 = v6844->timer;
  int v6853 = v6845 + 1;
  v6844->timer = v6853;
  int * v6847 = v6844->regs;
  int v6848 = v6847[7];
  int v6849 = v6847[18];
  int v6858 = v6848 + v6849;
  v6847[21] = v6858;
  struct StateT * v6851 = slot_75(v6844);
  return v6851;
}

struct StateT * slot_262(struct StateT * v14959) {
  int v14960 = v14959->timer;
  int v14967 = v14960 + 1;
  v14959->timer = v14967;
  int * v14962 = v14959->regs;
  int v14963 = v14962[20];
  int v14970 = v14963 << 13;
  v14962[20] = v14970;
  struct StateT * v14965 = slot_263(v14959);
  return v14965;
}

struct StateT * slot_351(struct StateT * v16342) {
  int v16343 = v16342->timer;
  int v16350 = v16343 + 1;
  v16342->timer = v16350;
  int * v16345 = v16342->regs;
  int v16346 = v16345[23];
  int v16353 = v16346 << 13;
  v16345[23] = v16353;
  struct StateT * v16348 = slot_352(v16342);
  return v16348;
}

struct StateT * slot_372(struct StateT * v16668) {
  int v16669 = v16668->timer;
  int v16677 = v16669 + 1;
  v16668->timer = v16677;
  int * v16671 = v16668->regs;
  int v16672 = v16671[23];
  int v16673 = v16671[24];
  int v16681 = v16672 | v16673;
  v16671[23] = v16681;
  struct StateT * v16675 = slot_373(v16668);
  return v16675;
}

struct StateT * slot_403(struct StateT * v17213) {
  int v17214 = v17213->timer;
  int v17221 = v17214 + 1;
  v17213->timer = v17221;
  int * v17216 = v17213->regs;
  int v17217 = v17216[20];
  int v17225 = (int)((unsigned int)v17217 >> 23);
  v17216[24] = v17225;
  struct StateT * v17219 = slot_404(v17213);
  return v17219;
}

struct StateT * slot_107(struct StateT * v7385) {
  int v7386 = v7385->timer;
  int v7393 = v7386 + 1;
  v7385->timer = v7393;
  int * v7388 = v7385->regs;
  int v7389 = v7388[23];
  int v7396 = v7389 << 18;
  v7388[23] = v7396;
  struct StateT * v7391 = slot_108(v7385);
  return v7391;
}

struct StateT * slot_325(struct StateT * v15940) {
  int v15941 = v15940->timer;
  int v15948 = v15941 + 1;
  v15940->timer = v15948;
  int * v15943 = v15940->regs;
  int v15944 = v15943[21];
  int v15951 = v15944 << 9;
  v15943[21] = v15951;
  struct StateT * v15946 = slot_326(v15940);
  return v15946;
}

struct StateT * slot_84(struct StateT * v7000) {
  int v7001 = v7000->timer;
  int v7008 = v7001 + 1;
  v7000->timer = v7008;
  int * v7003 = v7000->regs;
  int v7004 = v7003[22];
  int v7011 = v7004 << 13;
  v7003[22] = v7011;
  struct StateT * v7006 = slot_85(v7000);
  return v7006;
}

struct StateT * slot_28(struct StateT * v6049) {
  int v6050 = v6049->timer;
  int v6057 = v6050 + 1;
  v6049->timer = v6057;
  int * v6052 = v6049->regs;
  int v6053 = v6052[31];
  int v6061 = v6053 + -718;
  v6052[28] = v6061;
  struct StateT * v6055 = slot_29(v6049);
  return v6055;
}

struct StateT * slot_155(struct StateT * v8165) {
  int v8166 = v8165->timer;
  int v8174 = v8166 + 1;
  v8165->timer = v8174;
  int * v8168 = v8165->regs;
  int v8169 = v8168[6];
  int v8170 = v8168[15];
  int v8179 = v8169 + v8170;
  v8168[22] = v8179;
  struct StateT * v8172 = slot_156(v8165);
  return v8172;
}

struct StateT * slot_177(struct StateT * v8511) {
  int v8512 = v8511->timer;
  int v8519 = v8512 + 1;
  v8511->timer = v8519;
  int * v8514 = v8511->regs;
  int v8515 = v8514[20];
  int v8523 = (int)((unsigned int)v8515 >> 14);
  v8514[24] = v8523;
  struct StateT * v8517 = slot_178(v8511);
  return v8517;
}

struct StateT * slot_517(struct StateT * v19069) {
  int v19070 = v19069->timer;
  int v19078 = v19070 + 1;
  v19069->timer = v19078;
  int * v19072 = v19069->regs;
  int v19073 = v19072[18];
  int v19074 = v19072[22];
  int v19082 = v19073 ^ v19074;
  v19072[18] = v19082;
  struct StateT * v19076 = slot_518(v19069);
  return v19076;
}

struct StateT * slot_358(struct StateT * v16453) {
  int v16454 = v16453->timer;
  int v16462 = v16454 + 1;
  v16453->timer = v16462;
  int * v16456 = v16453->regs;
  int v16457 = v16456[9];
  int v16458 = v16456[5];
  int v16467 = v16457 + v16458;
  v16456[21] = v16467;
  struct StateT * v16460 = slot_359(v16453);
  return v16460;
}

struct StateT * slot_465(struct StateT * v18262) {
  int v18263 = v18262->timer;
  int v18271 = v18263 + 1;
  v18262->timer = v18271;
  int * v18265 = v18262->regs;
  int v18266 = v18265[20];
  int v18267 = v18265[24];
  int v18275 = v18266 | v18267;
  v18265[20] = v18275;
  struct StateT * v18269 = slot_466(v18262);
  return v18269;
}

struct StateT * slot_181(struct StateT * v8571) {
  int v8572 = v8571->timer;
  int v8579 = v8572 + 1;
  v8571->timer = v8579;
  int * v8574 = v8571->regs;
  int v8575 = v8574[21];
  int v8582 = v8575 << 18;
  v8574[21] = v8582;
  struct StateT * v8577 = slot_182(v8571);
  return v8577;
}

struct StateT * slot_154(struct StateT * v8148) {
  int v8149 = v8148->timer;
  int v8157 = v8149 + 1;
  v8148->timer = v8157;
  int * v8151 = v8148->regs;
  int v8152 = v8151[5];
  int v8153 = v8151[12];
  int v8162 = v8152 + v8153;
  v8151[21] = v8162;
  struct StateT * v8155 = slot_155(v8148);
  return v8155;
}

struct StateT * slot_260(struct StateT * v14927) {
  int v14928 = v14927->timer;
  int v14936 = v14928 + 1;
  v14927->timer = v14936;
  int * v14930 = v14927->regs;
  int v14931 = v14930[5];
  int v14932 = v14930[8];
  int v14941 = v14931 + v14932;
  v14930[23] = v14941;
  struct StateT * v14934 = slot_261(v14927);
  return v14934;
}

struct StateT * slot_481(struct StateT * v18511) {
  int v18512 = v18511->timer;
  int v18520 = v18512 + 1;
  v18511->timer = v18520;
  int * v18514 = v18511->regs;
  int v18515 = v18514[15];
  int v18516 = v18514[28];
  int v18525 = v18515 + v18516;
  v18514[22] = v18525;
  struct StateT * v18518 = slot_482(v18511);
  return v18518;
}

struct StateT * slot_305(struct StateT * v15628) {
  int v15629 = v15628->timer;
  int v15636 = v15629 + 1;
  v15628->timer = v15636;
  int * v15631 = v15628->regs;
  int v15632 = v15631[21];
  int v15639 = v15632 << 7;
  v15631[21] = v15639;
  struct StateT * v15634 = slot_306(v15628);
  return v15634;
}

struct StateT * slot_27(struct StateT * v6034) {
  int v6035 = v6034->timer;
  int v6042 = v6035 + 1;
  v6034->timer = v6042;
  int * v6037 = v6034->regs;
  int v6038 = v6037[28];
  int v6046 = v6038 + 1134;
  v6037[29] = v6046;
  struct StateT * v6040 = slot_28(v6034);
  return v6040;
}

struct StateT * slot_454(struct StateT * v18057) {
  int v18058 = v18057->timer;
  int v18066 = v18058 + 1;
  v18057->timer = v18066;
  int * v18060 = v18057->regs;
  int v18061 = v18060[23];
  int v18062 = v18060[24];
  int v18070 = v18061 | v18062;
  v18060[23] = v18070;
  struct StateT * v18064 = slot_455(v18057);
  return v18064;
}

struct StateT * slot_34(struct StateT * v6136) {
  int * v6137 = v6136->saved_regs;
  int * v6138 = v6136->regs;
  int v6139 = v6138[21];
  v6137[21] = v6139;
  int v6141 = v6136->timer;
  int v6153 = v6141 + 1;
  v6136->timer = v6153;
  int * v6143 = v6136->regs;
  int v6144 = v6143[29];
  int v6145 = v6143[14];
  int v6157 = v6144 + v6145;
  v6143[21] = v6157;
  struct StateT * v6147 = slot_35(v6136);
  return v6147;
}

struct StateT * slot_482(struct StateT * v18528) {
  int v18529 = v18528->timer;
  int v18537 = v18529 + 1;
  v18528->timer = v18537;
  int * v18531 = v18528->regs;
  int v18532 = v18531[16];
  int v18533 = v18531[31];
  int v18542 = v18532 + v18533;
  v18531[23] = v18542;
  struct StateT * v18535 = slot_483(v18528);
  return v18535;
}

struct StateT * slot_21(struct StateT * v5572) {
  int v5573 = v5572->timer;
  int v5683 = v5573 + 1;
  v5572->timer = v5683;
  int * v5575 = v5572->regs;
  int v5576 = v5575[11];
  int * v5577 = v5572->cache_tags;
  int v5687 = (((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2;
  int v5578 = v5577[v5687];
  int v5688 = ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5579 = v5577[v5688];
  int v5689 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2);
  int v5580 = v5577[v5689];
  int v5690 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5581 = v5577[v5690];
  int v5582 = v5572->timer;
  int v5691 = v5582 + ((100 ^ (((~(((v5580 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5580 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5578 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5578 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v5579 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5579 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5580 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5580 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5572->timer = v5691;
  int * v5584 = v5572->cache_vals;
  bool v5692 = !(((~(((v5578 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5578 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v5579 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5579 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v5677;
  if (v5692) {
    int * v5585 = v5572->cache_age;
    int v5694 = ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v5579 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5579 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v5586 = v5585[v5694];
    int v5587 = v5585[v5687];
    int v5695 = v5587 + ((int)((unsigned int)(v5587 - v5586) >> 31));
    v5585[v5687] = v5695;
    int * v5589 = v5572->cache_age;
    int v5590 = v5589[v5688];
    int v5697 = v5590 + ((int)((unsigned int)(v5590 - v5586) >> 31));
    v5589[v5688] = v5697;
    int * v5592 = v5572->cache_age;
    v5592[v5694] = 0;
    v5677 = v5694;
  } else {
    int * v5595 = v5572->cache_age;
    int v5701 = (((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2;
    int v5596 = v5595[v5701];
    int * v5597 = v5572->cache_tags;
    int v5598 = v5597[v5701];
    int v5599 = v5595[v5688];
    int v5600 = v5597[v5688];
    bool v5703 = !(((~(((v5580 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5580 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v5654;
    if (v5703) {
      int * v5601 = v5572->cache_age;
      int v5705 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))) | (-(v5581 ^ ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v5602 = v5601[v5705];
      int v5603 = v5601[v5689];
      int v5706 = v5603 + ((int)((unsigned int)(v5603 - v5602) >> 31));
      v5601[v5689] = v5706;
      int * v5605 = v5572->cache_age;
      int v5606 = v5605[v5690];
      int v5708 = v5606 + ((int)((unsigned int)(v5606 - v5602) >> 31));
      v5605[v5690] = v5708;
      int * v5608 = v5572->cache_age;
      v5608[v5705] = 0;
      v5654 = v5705;
    } else {
      int * v5611 = v5572->cache_age;
      int v5712 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2);
      int v5612 = v5611[v5712];
      int * v5613 = v5572->cache_tags;
      int v5614 = v5613[v5712];
      int v5615 = v5611[v5690];
      int v5616 = v5613[v5690];
      int * v5617 = v5572->cache_dirty;
      int v5715 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v5612 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2)) - (v5615 + ((~(((v5616 ^ -1) | (-(v5616 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5618 = v5617[v5715];
      bool v5716 = !(v5618 == 0);
      if (v5716) {
        int * v5619 = v5572->cache_tags;
        int v5620 = v5619[v5715];
        int * v5621 = v5572->cache_vals;
        int v5719 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v5612 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2)) - (v5615 + ((~(((v5616 ^ -1) | (-(v5616 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5622 = v5621[v5719];
        int v5720 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v5612 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2)) - (v5615 + ((~(((v5616 ^ -1) | (-(v5616 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5623 = v5621[v5720];
        int * v5624 = v5572->mem;
        int v5722 = v5620 * 2;
        v5624[v5722] = v5622;
        int * v5626 = v5572->mem;
        int v5725 = (v5620 * 2) + 1;
        v5626[v5725] = v5623;
        ;
      } else {
        ;
      }
      int * v5631 = v5572->mem;
      int v5730 = ((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) * 2;
      int v5632 = v5631[v5730];
      int v5731 = (((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) * 2) + 1;
      int v5633 = v5631[v5731];
      int * v5634 = v5572->cache_vals;
      int v5733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v5612 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2)) - (v5615 + ((~(((v5616 ^ -1) | (-(v5616 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5634[v5733] = v5632;
      int * v5636 = v5572->cache_vals;
      int v5736 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v5612 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2)) - (v5615 + ((~(((v5616 ^ -1) | (-(v5616 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5636[v5736] = v5633;
      int * v5638 = v5572->cache_tags;
      int v5739 = (int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1);
      v5638[v5715] = v5739;
      int * v5640 = v5572->cache_dirty;
      v5640[v5715] = 0;
      int * v5642 = v5572->cache_age;
      v5642[v5715] = 1;
      int * v5644 = v5572->cache_age;
      int v5645 = v5644[v5715];
      int v5646 = v5644[v5689];
      int v5745 = v5646 + ((int)((unsigned int)(v5646 - v5645) >> 31));
      v5644[v5689] = v5745;
      int * v5648 = v5572->cache_age;
      int v5649 = v5648[v5690];
      int v5747 = v5649 + ((int)((unsigned int)(v5649 - v5645) >> 31));
      v5648[v5690] = v5747;
      int * v5651 = v5572->cache_age;
      v5651[v5715] = 0;
      v5654 = v5715;
    }
    int * v5655 = v5572->cache_vals;
    int v5750 = v5654 * 2;
    int v5656 = v5655[v5750];
    int v5751 = (v5654 * 2) + 1;
    int v5657 = v5655[v5751];
    int v5752 = (((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v5596 + ((~(((v5598 ^ -1) | (-(v5598 ^ -1))) >> 31)) & 2)) - (v5599 + ((~(((v5600 ^ -1) | (-(v5600 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5655[v5752] = v5656;
    int * v5659 = v5572->cache_vals;
    int v5755 = ((((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v5596 + ((~(((v5598 ^ -1) | (-(v5598 ^ -1))) >> 31)) & 2)) - (v5599 + ((~(((v5600 ^ -1) | (-(v5600 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5659[v5755] = v5657;
    int * v5661 = v5572->cache_tags;
    int v5758 = ((((int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v5596 + ((~(((v5598 ^ -1) | (-(v5598 ^ -1))) >> 31)) & 2)) - (v5599 + ((~(((v5600 ^ -1) | (-(v5600 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5759 = (int)((unsigned int)((int)((unsigned int)(v5576 + 8) >> 2)) >> 1);
    v5661[v5758] = v5759;
    int * v5663 = v5572->cache_dirty;
    v5663[v5758] = 0;
    int * v5665 = v5572->cache_age;
    v5665[v5758] = 1;
    int * v5667 = v5572->cache_age;
    int v5668 = v5667[v5758];
    int v5669 = v5667[v5687];
    int v5765 = v5669 + ((int)((unsigned int)(v5669 - v5668) >> 31));
    v5667[v5687] = v5765;
    int * v5671 = v5572->cache_age;
    int v5672 = v5671[v5688];
    int v5767 = v5672 + ((int)((unsigned int)(v5672 - v5668) >> 31));
    v5671[v5688] = v5767;
    int * v5674 = v5572->cache_age;
    v5674[v5758] = 0;
    v5677 = v5758;
  }
  int v5770 = (v5677 * 2) + (((int)((unsigned int)(v5576 + 8) >> 2)) & 1);
  int v5678 = v5584[v5770];
  int * v5679 = v5572->regs;
  v5679[6] = v5678;
  struct StateT * v5681 = slot_22(v5572);
  return v5681;
}

struct StateT * slot_406(struct StateT * v17258) {
  int v17259 = v17258->timer;
  int v17266 = v17259 + 1;
  v17258->timer = v17266;
  int * v17261 = v17258->regs;
  int v17262 = v17261[21];
  int v17270 = (int)((unsigned int)v17262 >> 23);
  v17261[24] = v17270;
  struct StateT * v17264 = slot_407(v17258);
  return v17264;
}

struct StateT * slot_292(struct StateT * v15420) {
  int v15421 = v15420->timer;
  int v15429 = v15421 + 1;
  v15420->timer = v15429;
  int * v15423 = v15420->regs;
  int v15424 = v15423[23];
  int v15425 = v15423[24];
  int v15433 = v15424 | v15425;
  v15423[23] = v15433;
  struct StateT * v15427 = slot_293(v15420);
  return v15427;
}

struct StateT * slot_118(struct StateT * v7590) {
  int v7591 = v7590->timer;
  int v7598 = v7591 + 1;
  v7590->timer = v7598;
  int * v7593 = v7590->regs;
  int v7594 = v7593[20];
  int v7601 = v7594 << 7;
  v7593[20] = v7601;
  struct StateT * v7596 = slot_119(v7590);
  return v7596;
}

struct StateT * slot_525(struct StateT * v19198) {
  int v19199 = v19198->timer;
  int v19207 = v19199 + 1;
  v19198->timer = v19207;
  int * v19201 = v19198->regs;
  int v19202 = v19201[20];
  int v19203 = v19201[24];
  int v19211 = v19202 | v19203;
  v19201[20] = v19211;
  struct StateT * v19205 = slot_526(v19198);
  return v19205;
}

struct StateT * slot_515(struct StateT * v19037) {
  int v19038 = v19037->timer;
  int v19046 = v19038 + 1;
  v19037->timer = v19046;
  int * v19040 = v19037->regs;
  int v19041 = v19040[8];
  int v19042 = v19040[20];
  int v19050 = v19041 ^ v19042;
  v19040[8] = v19050;
  struct StateT * v19044 = slot_516(v19037);
  return v19044;
}

struct StateT * slot_376(struct StateT * v16732) {
  int v16733 = v16732->timer;
  int v16741 = v16733 + 1;
  v16732->timer = v16741;
  int * v16735 = v16732->regs;
  int v16736 = v16735[31];
  int v16737 = v16735[23];
  int v16745 = v16736 ^ v16737;
  v16735[31] = v16745;
  struct StateT * v16739 = slot_377(v16732);
  return v16739;
}

struct StateT * slot_373(struct StateT * v16684) {
  int v16685 = v16684->timer;
  int v16693 = v16685 + 1;
  v16684->timer = v16693;
  int * v16687 = v16684->regs;
  int v16688 = v16687[30];
  int v16689 = v16687[20];
  int v16697 = v16688 ^ v16689;
  v16687[30] = v16697;
  struct StateT * v16691 = slot_374(v16684);
  return v16691;
}

struct StateT * slot_94(struct StateT * v7184) {
  int v7185 = v7184->timer;
  int v7193 = v7185 + 1;
  v7184->timer = v7193;
  int * v7187 = v7184->regs;
  int v7188 = v7187[14];
  int v7189 = v7187[7];
  int v7198 = v7188 + v7189;
  v7187[21] = v7198;
  struct StateT * v7191 = slot_95(v7184);
  return v7191;
}

struct StateT * slot_340(struct StateT * v16175) {
  int v16176 = v16175->timer;
  int v16184 = v16176 + 1;
  v16175->timer = v16184;
  int * v16178 = v16175->regs;
  int v16179 = v16178[7];
  int v16180 = v16178[16];
  int v16189 = v16179 + v16180;
  v16178[23] = v16189;
  struct StateT * v16182 = slot_341(v16175);
  return v16182;
}

struct StateT * slot_146(struct StateT * v8022) {
  int v8023 = v8022->timer;
  int v8030 = v8023 + 1;
  v8022->timer = v8030;
  int * v8025 = v8022->regs;
  int v8026 = v8025[23];
  int v8034 = (int)((unsigned int)v8026 >> 23);
  v8025[24] = v8034;
  struct StateT * v8028 = slot_147(v8022);
  return v8028;
}

struct StateT * slot_383(struct StateT * v16866) {
  int * v16867 = v16866->saved_regs;
  int * v16868 = v16866->regs;
  int v16869 = v16868[24];
  v16867[24] = v16869;
  int v16871 = v16866->timer;
  int v16882 = v16871 + 1;
  v16866->timer = v16882;
  int * v16873 = v16866->regs;
  int v16874 = v16873[20];
  int v16885 = (int)((unsigned int)v16874 >> 25);
  v16873[24] = v16885;
  struct StateT * v16876 = slot_384(v16866);
  return v16876;
}

struct StateT * slot_24(struct StateT * v5993) {
  int v5994 = v5993->timer;
  int v6000 = v5994 + 1;
  v5993->timer = v6000;
  int * v5996 = v5993->regs;
  v5996[28] = 857759744;
  struct StateT * v5998 = slot_25(v5993);
  return v5998;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -48;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_489(struct StateT * v18635) {
  int v18636 = v18635->timer;
  int v18643 = v18636 + 1;
  v18635->timer = v18643;
  int * v18638 = v18635->regs;
  int v18639 = v18638[22];
  int v18647 = (int)((unsigned int)v18639 >> 23);
  v18638[24] = v18647;
  struct StateT * v18641 = slot_490(v18635);
  return v18641;
}

struct StateT * slot_286(struct StateT * v15330) {
  int v15331 = v15330->timer;
  int v15339 = v15331 + 1;
  v15330->timer = v15339;
  int * v15333 = v15330->regs;
  int v15334 = v15333[21];
  int v15335 = v15333[24];
  int v15343 = v15334 | v15335;
  v15333[21] = v15343;
  struct StateT * v15337 = slot_287(v15330);
  return v15337;
}

struct StateT * slot_520(struct StateT * v19118) {
  int v19119 = v19118->timer;
  int v19127 = v19119 + 1;
  v19118->timer = v19127;
  int * v19121 = v19118->regs;
  int v19122 = v19121[9];
  int v19123 = v19121[5];
  int v19132 = v19122 + v19123;
  v19121[21] = v19132;
  struct StateT * v19125 = slot_521(v19118);
  return v19125;
}

struct StateT * slot_125(struct StateT * v7694) {
  int v7695 = v7694->timer;
  int v7703 = v7695 + 1;
  v7694->timer = v7703;
  int * v7697 = v7694->regs;
  int v7698 = v7697[22];
  int v7699 = v7697[24];
  int v7707 = v7698 | v7699;
  v7697[22] = v7707;
  struct StateT * v7701 = slot_126(v7694);
  return v7701;
}

struct StateT * slot_254(struct StateT * v14828) {
  int v14829 = v14828->timer;
  int v14837 = v14829 + 1;
  v14828->timer = v14837;
  int * v14831 = v14828->regs;
  int v14832 = v14831[7];
  int v14833 = v14831[21];
  int v14841 = v14832 ^ v14833;
  v14831[7] = v14841;
  struct StateT * v14835 = slot_255(v14828);
  return v14835;
}

struct StateT * slot_148(struct StateT * v8051) {
  int v8052 = v8051->timer;
  int v8060 = v8052 + 1;
  v8051->timer = v8060;
  int * v8054 = v8051->regs;
  int v8055 = v8054[23];
  int v8056 = v8054[24];
  int v8064 = v8055 | v8056;
  v8054[23] = v8064;
  struct StateT * v8058 = slot_149(v8051);
  return v8058;
}

struct StateT * slot_421(struct StateT * v17519) {
  int v17520 = v17519->timer;
  int v17528 = v17520 + 1;
  v17519->timer = v17528;
  int * v17522 = v17519->regs;
  int v17523 = v17522[17];
  int v17524 = v17522[19];
  int v17533 = v17523 + v17524;
  v17522[22] = v17533;
  struct StateT * v17526 = slot_422(v17519);
  return v17526;
}

struct StateT * slot_126(struct StateT * v7710) {
  int v7711 = v7710->timer;
  int v7718 = v7711 + 1;
  v7710->timer = v7718;
  int * v7713 = v7710->regs;
  int v7714 = v7713[23];
  int v7722 = (int)((unsigned int)v7714 >> 25);
  v7713[24] = v7722;
  struct StateT * v7716 = slot_127(v7710);
  return v7716;
}

struct StateT * slot_363(struct StateT * v16533) {
  int v16534 = v16533->timer;
  int v16542 = v16534 + 1;
  v16533->timer = v16542;
  int * v16536 = v16533->regs;
  int v16537 = v16536[20];
  int v16538 = v16536[24];
  int v16546 = v16537 | v16538;
  v16536[20] = v16546;
  struct StateT * v16540 = slot_364(v16533);
  return v16540;
}

struct StateT * slot_79(struct StateT * v6924) {
  int v6925 = v6924->timer;
  int v6933 = v6925 + 1;
  v6924->timer = v6933;
  int * v6927 = v6924->regs;
  int v6928 = v6927[20];
  int v6929 = v6927[24];
  int v6937 = v6928 | v6929;
  v6927[20] = v6937;
  struct StateT * v6931 = slot_80(v6924);
  return v6931;
}

struct StateT * slot_367(struct StateT * v16594) {
  int v16595 = v16594->timer;
  int v16602 = v16595 + 1;
  v16594->timer = v16602;
  int * v16597 = v16594->regs;
  int v16598 = v16597[22];
  int v16606 = (int)((unsigned int)v16598 >> 14);
  v16597[24] = v16606;
  struct StateT * v16600 = slot_368(v16594);
  return v16600;
}

struct StateT * slot_437(struct StateT * v17779) {
  int * v17780 = v17779->saved_regs;
  int * v17781 = v17779->regs;
  int v17782 = v17781[12];
  v17780[12] = v17782;
  int v17784 = v17779->timer;
  int v17796 = v17784 + 1;
  v17779->timer = v17796;
  int * v17786 = v17779->regs;
  int v17787 = v17786[12];
  int v17788 = v17786[22];
  int v17799 = v17787 ^ v17788;
  v17786[12] = v17799;
  struct StateT * v17790 = slot_438(v17779);
  return v17790;
}

struct StateT * slot_341(struct StateT * v16192) {
  int v16193 = v16192->timer;
  int v16200 = v16193 + 1;
  v16192->timer = v16200;
  int * v16195 = v16192->regs;
  int v16196 = v16195[20];
  int v16204 = (int)((unsigned int)v16196 >> 19);
  v16195[24] = v16204;
  struct StateT * v16198 = slot_342(v16192);
  return v16198;
}

struct StateT * slot_142(struct StateT * v7961) {
  int v7962 = v7961->timer;
  int v7970 = v7962 + 1;
  v7961->timer = v7970;
  int * v7964 = v7961->regs;
  int v7965 = v7964[21];
  int v7966 = v7964[24];
  int v7974 = v7965 | v7966;
  v7964[21] = v7974;
  struct StateT * v7968 = slot_143(v7961);
  return v7968;
}

struct StateT * slot_416(struct StateT * v17416) {
  int * v17417 = v17416->saved_regs;
  int * v17418 = v17416->regs;
  int v17419 = v17418[7];
  v17417[7] = v17419;
  int v17421 = v17416->timer;
  int v17433 = v17421 + 1;
  v17416->timer = v17433;
  int * v17423 = v17416->regs;
  int v17424 = v17423[7];
  int v17425 = v17423[21];
  int v17436 = v17424 ^ v17425;
  v17423[7] = v17436;
  struct StateT * v17427 = slot_417(v17416);
  return v17427;
}

struct StateT * slot_280(struct StateT * v15239) {
  int v15240 = v15239->timer;
  int v15248 = v15240 + 1;
  v15239->timer = v15248;
  int * v15242 = v15239->regs;
  int v15243 = v15242[15];
  int v15244 = v15242[5];
  int v15253 = v15243 + v15244;
  v15242[23] = v15253;
  struct StateT * v15246 = slot_281(v15239);
  return v15246;
}

struct StateT * slot_272(struct StateT * v15108) {
  int v15109 = v15108->timer;
  int v15117 = v15109 + 1;
  v15108->timer = v15117;
  int * v15111 = v15108->regs;
  int v15112 = v15111[23];
  int v15113 = v15111[24];
  int v15121 = v15112 | v15113;
  v15111[23] = v15121;
  struct StateT * v15115 = slot_273(v15108);
  return v15115;
}

struct StateT * slot_47(struct StateT * v6365) {
  int v6366 = v6365->timer;
  int v6373 = v6366 + 1;
  v6365->timer = v6373;
  int * v6368 = v6365->regs;
  int v6369 = v6368[23];
  int v6376 = v6369 << 7;
  v6368[23] = v6376;
  struct StateT * v6371 = slot_48(v6365);
  return v6371;
}

struct StateT * slot_214(struct StateT * v13763) {
  int v13764 = v13763->timer;
  int v13874 = v13764 + 1;
  v13763->timer = v13874;
  int * v13766 = v13763->regs;
  int v13767 = v13766[2];
  int * v13768 = v13763->cache_tags;
  int v13878 = (((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2;
  int v13769 = v13768[v13878];
  int v13879 = ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13770 = v13768[v13879];
  int v13880 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2);
  int v13771 = v13768[v13880];
  int v13881 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13772 = v13768[v13881];
  int v13773 = v13763->timer;
  int v13882 = v13773 + ((100 ^ (((~(((v13771 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13771 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13769 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13769 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v13770 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13770 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13771 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13771 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13763->timer = v13882;
  int * v13775 = v13763->cache_vals;
  bool v13883 = !(((~(((v13769 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13769 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v13770 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13770 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v13868;
  if (v13883) {
    int * v13776 = v13763->cache_age;
    int v13885 = ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v13770 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13770 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v13777 = v13776[v13885];
    int v13778 = v13776[v13878];
    int v13886 = v13778 + ((int)((unsigned int)(v13778 - v13777) >> 31));
    v13776[v13878] = v13886;
    int * v13780 = v13763->cache_age;
    int v13781 = v13780[v13879];
    int v13888 = v13781 + ((int)((unsigned int)(v13781 - v13777) >> 31));
    v13780[v13879] = v13888;
    int * v13783 = v13763->cache_age;
    v13783[v13885] = 0;
    v13868 = v13885;
  } else {
    int * v13786 = v13763->cache_age;
    int v13892 = (((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2;
    int v13787 = v13786[v13892];
    int * v13788 = v13763->cache_tags;
    int v13789 = v13788[v13892];
    int v13790 = v13786[v13879];
    int v13791 = v13788[v13879];
    bool v13894 = !(((~(((v13771 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13771 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v13845;
    if (v13894) {
      int * v13792 = v13763->cache_age;
      int v13896 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))) | (-(v13772 ^ ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v13793 = v13792[v13896];
      int v13794 = v13792[v13880];
      int v13897 = v13794 + ((int)((unsigned int)(v13794 - v13793) >> 31));
      v13792[v13880] = v13897;
      int * v13796 = v13763->cache_age;
      int v13797 = v13796[v13881];
      int v13899 = v13797 + ((int)((unsigned int)(v13797 - v13793) >> 31));
      v13796[v13881] = v13899;
      int * v13799 = v13763->cache_age;
      v13799[v13896] = 0;
      v13845 = v13896;
    } else {
      int * v13802 = v13763->cache_age;
      int v13903 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2);
      int v13803 = v13802[v13903];
      int * v13804 = v13763->cache_tags;
      int v13805 = v13804[v13903];
      int v13806 = v13802[v13881];
      int v13807 = v13804[v13881];
      int * v13808 = v13763->cache_dirty;
      int v13906 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v13803 + ((~(((v13805 ^ -1) | (-(v13805 ^ -1))) >> 31)) & 2)) - (v13806 + ((~(((v13807 ^ -1) | (-(v13807 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13809 = v13808[v13906];
      bool v13907 = !(v13809 == 0);
      if (v13907) {
        int * v13810 = v13763->cache_tags;
        int v13811 = v13810[v13906];
        int * v13812 = v13763->cache_vals;
        int v13910 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v13803 + ((~(((v13805 ^ -1) | (-(v13805 ^ -1))) >> 31)) & 2)) - (v13806 + ((~(((v13807 ^ -1) | (-(v13807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13813 = v13812[v13910];
        int v13911 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v13803 + ((~(((v13805 ^ -1) | (-(v13805 ^ -1))) >> 31)) & 2)) - (v13806 + ((~(((v13807 ^ -1) | (-(v13807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13814 = v13812[v13911];
        int * v13815 = v13763->mem;
        int v13913 = v13811 * 2;
        v13815[v13913] = v13813;
        int * v13817 = v13763->mem;
        int v13916 = (v13811 * 2) + 1;
        v13817[v13916] = v13814;
        ;
      } else {
        ;
      }
      int * v13822 = v13763->mem;
      int v13921 = ((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) * 2;
      int v13823 = v13822[v13921];
      int v13922 = (((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) * 2) + 1;
      int v13824 = v13822[v13922];
      int * v13825 = v13763->cache_vals;
      int v13924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v13803 + ((~(((v13805 ^ -1) | (-(v13805 ^ -1))) >> 31)) & 2)) - (v13806 + ((~(((v13807 ^ -1) | (-(v13807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13825[v13924] = v13823;
      int * v13827 = v13763->cache_vals;
      int v13927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v13803 + ((~(((v13805 ^ -1) | (-(v13805 ^ -1))) >> 31)) & 2)) - (v13806 + ((~(((v13807 ^ -1) | (-(v13807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13827[v13927] = v13824;
      int * v13829 = v13763->cache_tags;
      int v13930 = (int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1);
      v13829[v13906] = v13930;
      int * v13831 = v13763->cache_dirty;
      v13831[v13906] = 0;
      int * v13833 = v13763->cache_age;
      v13833[v13906] = 1;
      int * v13835 = v13763->cache_age;
      int v13836 = v13835[v13906];
      int v13837 = v13835[v13880];
      int v13936 = v13837 + ((int)((unsigned int)(v13837 - v13836) >> 31));
      v13835[v13880] = v13936;
      int * v13839 = v13763->cache_age;
      int v13840 = v13839[v13881];
      int v13938 = v13840 + ((int)((unsigned int)(v13840 - v13836) >> 31));
      v13839[v13881] = v13938;
      int * v13842 = v13763->cache_age;
      v13842[v13906] = 0;
      v13845 = v13906;
    }
    int * v13846 = v13763->cache_vals;
    int v13941 = v13845 * 2;
    int v13847 = v13846[v13941];
    int v13942 = (v13845 * 2) + 1;
    int v13848 = v13846[v13942];
    int v13943 = (((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v13787 + ((~(((v13789 ^ -1) | (-(v13789 ^ -1))) >> 31)) & 2)) - (v13790 + ((~(((v13791 ^ -1) | (-(v13791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13846[v13943] = v13847;
    int * v13850 = v13763->cache_vals;
    int v13946 = ((((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v13787 + ((~(((v13789 ^ -1) | (-(v13789 ^ -1))) >> 31)) & 2)) - (v13790 + ((~(((v13791 ^ -1) | (-(v13791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13850[v13946] = v13848;
    int * v13852 = v13763->cache_tags;
    int v13949 = ((((int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v13787 + ((~(((v13789 ^ -1) | (-(v13789 ^ -1))) >> 31)) & 2)) - (v13790 + ((~(((v13791 ^ -1) | (-(v13791 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13950 = (int)((unsigned int)((int)((unsigned int)(v13767 + 32) >> 2)) >> 1);
    v13852[v13949] = v13950;
    int * v13854 = v13763->cache_dirty;
    v13854[v13949] = 0;
    int * v13856 = v13763->cache_age;
    v13856[v13949] = 1;
    int * v13858 = v13763->cache_age;
    int v13859 = v13858[v13949];
    int v13860 = v13858[v13878];
    int v13956 = v13860 + ((int)((unsigned int)(v13860 - v13859) >> 31));
    v13858[v13878] = v13956;
    int * v13862 = v13763->cache_age;
    int v13863 = v13862[v13879];
    int v13958 = v13863 + ((int)((unsigned int)(v13863 - v13859) >> 31));
    v13862[v13879] = v13958;
    int * v13865 = v13763->cache_age;
    v13865[v13949] = 0;
    v13868 = v13949;
  }
  int v13961 = (v13868 * 2) + (((int)((unsigned int)(v13767 + 32) >> 2)) & 1);
  int v13869 = v13775[v13961];
  int * v13870 = v13763->regs;
  v13870[19] = v13869;
  struct StateT * v13872 = slot_215(v13763);
  return v13872;
}

struct StateT * slot_297(struct StateT * v15500) {
  int v15501 = v15500->timer;
  int v15509 = v15501 + 1;
  v15500->timer = v15509;
  int * v15503 = v15500->regs;
  int v15504 = v15503[30];
  int v15505 = v15503[8];
  int v15514 = v15504 + v15505;
  v15503[20] = v15514;
  struct StateT * v15507 = slot_298(v15500);
  return v15507;
}

struct StateT * slot_29(struct StateT * v6064) {
  int v6065 = v6064->timer;
  int v6071 = v6065 + 1;
  v6064->timer = v6071;
  int * v6067 = v6064->regs;
  v6067[31] = 1797283840;
  struct StateT * v6069 = slot_30(v6064);
  return v6069;
}

struct StateT * slot_314(struct StateT * v15764) {
  int v15765 = v15764->timer;
  int v15773 = v15765 + 1;
  v15764->timer = v15773;
  int * v15767 = v15764->regs;
  int v15768 = v15767[12];
  int v15769 = v15767[21];
  int v15777 = v15768 ^ v15769;
  v15767[12] = v15777;
  struct StateT * v15771 = slot_315(v15764);
  return v15771;
}

struct StateT * slot_151(struct StateT * v8099) {
  int v8100 = v8099->timer;
  int v8108 = v8100 + 1;
  v8099->timer = v8108;
  int * v8102 = v8099->regs;
  int v8103 = v8102[6];
  int v8104 = v8102[22];
  int v8112 = v8103 ^ v8104;
  v8102[6] = v8112;
  struct StateT * v8106 = slot_152(v8099);
  return v8106;
}

struct StateT * slot_7(struct StateT * v1906) {
  int v1907 = v1906->timer;
  int v2077 = v1907 + 1;
  v1906->timer = v2077;
  int * v1909 = v1906->regs;
  int v1910 = v1909[2];
  int v1911 = v1909[22];
  int * v1912 = v1906->cache_tags;
  int v2082 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2;
  int v1913 = v1912[v2082];
  int v2083 = ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1914 = v1912[v2083];
  int v2084 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2);
  int v1915 = v1912[v2084];
  int v2085 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1916 = v1912[v2085];
  int v1917 = v1906->timer;
  int v2086 = v1917 + ((100 ^ (((~(((v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1906->timer = v2086;
  bool v2087 = !(((~(((v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v2011;
  if (v2087) {
    int * v1919 = v1906->cache_age;
    int v2089 = ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v1920 = v1919[v2089];
    int v1921 = v1919[v2082];
    int v2090 = v1921 + ((int)((unsigned int)(v1921 - v1920) >> 31));
    v1919[v2082] = v2090;
    int * v1923 = v1906->cache_age;
    int v1924 = v1923[v2083];
    int v2092 = v1924 + ((int)((unsigned int)(v1924 - v1920) >> 31));
    v1923[v2083] = v2092;
    int * v1926 = v1906->cache_age;
    v1926[v2089] = 0;
    v2011 = v2089;
  } else {
    int * v1929 = v1906->cache_age;
    int v2096 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2;
    int v1930 = v1929[v2096];
    int * v1931 = v1906->cache_tags;
    int v1932 = v1931[v2096];
    int v1933 = v1929[v2083];
    int v1934 = v1931[v2083];
    bool v2098 = !(((~(((v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v1988;
    if (v2098) {
      int * v1935 = v1906->cache_age;
      int v2100 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v1936 = v1935[v2100];
      int v1937 = v1935[v2084];
      int v2101 = v1937 + ((int)((unsigned int)(v1937 - v1936) >> 31));
      v1935[v2084] = v2101;
      int * v1939 = v1906->cache_age;
      int v1940 = v1939[v2085];
      int v2103 = v1940 + ((int)((unsigned int)(v1940 - v1936) >> 31));
      v1939[v2085] = v2103;
      int * v1942 = v1906->cache_age;
      v1942[v2100] = 0;
      v1988 = v2100;
    } else {
      int * v1945 = v1906->cache_age;
      int v2107 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2);
      int v1946 = v1945[v2107];
      int * v1947 = v1906->cache_tags;
      int v1948 = v1947[v2107];
      int v1949 = v1945[v2085];
      int v1950 = v1947[v2085];
      int * v1951 = v1906->cache_dirty;
      int v2110 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1952 = v1951[v2110];
      bool v2111 = !(v1952 == 0);
      if (v2111) {
        int * v1953 = v1906->cache_tags;
        int v1954 = v1953[v2110];
        int * v1955 = v1906->cache_vals;
        int v2114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1956 = v1955[v2114];
        int v2115 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1957 = v1955[v2115];
        int * v1958 = v1906->mem;
        int v2117 = v1954 * 2;
        v1958[v2117] = v1956;
        int * v1960 = v1906->mem;
        int v2120 = (v1954 * 2) + 1;
        v1960[v2120] = v1957;
        ;
      } else {
        ;
      }
      int * v1965 = v1906->mem;
      int v2125 = ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2;
      int v1966 = v1965[v2125];
      int v2126 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2) + 1;
      int v1967 = v1965[v2126];
      int * v1968 = v1906->cache_vals;
      int v2128 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1968[v2128] = v1966;
      int * v1970 = v1906->cache_vals;
      int v2131 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1970[v2131] = v1967;
      int * v1972 = v1906->cache_tags;
      int v2134 = (int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1);
      v1972[v2110] = v2134;
      int * v1974 = v1906->cache_dirty;
      v1974[v2110] = 0;
      int * v1976 = v1906->cache_age;
      v1976[v2110] = 1;
      int * v1978 = v1906->cache_age;
      int v1979 = v1978[v2110];
      int v1980 = v1978[v2084];
      int v2140 = v1980 + ((int)((unsigned int)(v1980 - v1979) >> 31));
      v1978[v2084] = v2140;
      int * v1982 = v1906->cache_age;
      int v1983 = v1982[v2085];
      int v2142 = v1983 + ((int)((unsigned int)(v1983 - v1979) >> 31));
      v1982[v2085] = v2142;
      int * v1985 = v1906->cache_age;
      v1985[v2110] = 0;
      v1988 = v2110;
    }
    int * v1989 = v1906->cache_vals;
    int v2145 = v1988 * 2;
    int v1990 = v1989[v2145];
    int v2146 = (v1988 * 2) + 1;
    int v1991 = v1989[v2146];
    int v2147 = (((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v1930 + ((~(((v1932 ^ -1) | (-(v1932 ^ -1))) >> 31)) & 2)) - (v1933 + ((~(((v1934 ^ -1) | (-(v1934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1989[v2147] = v1990;
    int * v1993 = v1906->cache_vals;
    int v2150 = ((((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v1930 + ((~(((v1932 ^ -1) | (-(v1932 ^ -1))) >> 31)) & 2)) - (v1933 + ((~(((v1934 ^ -1) | (-(v1934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1993[v2150] = v1991;
    int * v1995 = v1906->cache_tags;
    int v2153 = ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v1930 + ((~(((v1932 ^ -1) | (-(v1932 ^ -1))) >> 31)) & 2)) - (v1933 + ((~(((v1934 ^ -1) | (-(v1934 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2154 = (int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1);
    v1995[v2153] = v2154;
    int * v1997 = v1906->cache_dirty;
    v1997[v2153] = 0;
    int * v1999 = v1906->cache_age;
    v1999[v2153] = 1;
    int * v2001 = v1906->cache_age;
    int v2002 = v2001[v2153];
    int v2003 = v2001[v2082];
    int v2160 = v2003 + ((int)((unsigned int)(v2003 - v2002) >> 31));
    v2001[v2082] = v2160;
    int * v2005 = v1906->cache_age;
    int v2006 = v2005[v2083];
    int v2162 = v2006 + ((int)((unsigned int)(v2006 - v2002) >> 31));
    v2005[v2083] = v2162;
    int * v2008 = v1906->cache_age;
    v2008[v2153] = 0;
    v2011 = v2153;
  }
  int * v2012 = v1906->cache_vals;
  int v2165 = (v2011 * 2) + (((int)((unsigned int)(v1910 + 20) >> 2)) & 1);
  v2012[v2165] = v1911;
  int * v2014 = v1906->cache_tags;
  int v2015 = v2014[v2084];
  int v2016 = v2014[v2085];
  bool v2168 = !(((~(((v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v2070;
  if (v2168) {
    int * v2017 = v1906->cache_age;
    int v2170 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v2018 = v2017[v2170];
    int v2019 = v2017[v2084];
    int v2171 = v2019 + ((int)((unsigned int)(v2019 - v2018) >> 31));
    v2017[v2084] = v2171;
    int * v2021 = v1906->cache_age;
    int v2022 = v2021[v2085];
    int v2173 = v2022 + ((int)((unsigned int)(v2022 - v2018) >> 31));
    v2021[v2085] = v2173;
    int * v2024 = v1906->cache_age;
    v2024[v2170] = 0;
    v2070 = v2170;
  } else {
    int * v2027 = v1906->cache_age;
    int v2177 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2);
    int v2028 = v2027[v2177];
    int * v2029 = v1906->cache_tags;
    int v2030 = v2029[v2177];
    int v2031 = v2027[v2085];
    int v2032 = v2029[v2085];
    int * v2033 = v1906->cache_dirty;
    int v2180 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2034 = v2033[v2180];
    bool v2181 = !(v2034 == 0);
    if (v2181) {
      int * v2035 = v1906->cache_tags;
      int v2036 = v2035[v2180];
      int * v2037 = v1906->cache_vals;
      int v2184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2038 = v2037[v2184];
      int v2185 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2039 = v2037[v2185];
      int * v2040 = v1906->mem;
      int v2187 = v2036 * 2;
      v2040[v2187] = v2038;
      int * v2042 = v1906->mem;
      int v2190 = (v2036 * 2) + 1;
      v2042[v2190] = v2039;
      ;
    } else {
      ;
    }
    int * v2047 = v1906->mem;
    int v2195 = ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2;
    int v2048 = v2047[v2195];
    int v2196 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2) + 1;
    int v2049 = v2047[v2196];
    int * v2050 = v1906->cache_vals;
    int v2198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2050[v2198] = v2048;
    int * v2052 = v1906->cache_vals;
    int v2201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2052[v2201] = v2049;
    int * v2054 = v1906->cache_tags;
    int v2204 = (int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1);
    v2054[v2180] = v2204;
    int * v2056 = v1906->cache_dirty;
    v2056[v2180] = 0;
    int * v2058 = v1906->cache_age;
    v2058[v2180] = 1;
    int * v2060 = v1906->cache_age;
    int v2061 = v2060[v2180];
    int v2062 = v2060[v2084];
    int v2210 = v2062 + ((int)((unsigned int)(v2062 - v2061) >> 31));
    v2060[v2084] = v2210;
    int * v2064 = v1906->cache_age;
    int v2065 = v2064[v2085];
    int v2212 = v2065 + ((int)((unsigned int)(v2065 - v2061) >> 31));
    v2064[v2085] = v2212;
    int * v2067 = v1906->cache_age;
    v2067[v2180] = 0;
    v2070 = v2180;
  }
  int * v2071 = v1906->cache_vals;
  int v2215 = (v2070 * 2) + (((int)((unsigned int)(v1910 + 20) >> 2)) & 1);
  v2071[v2215] = v1911;
  int * v2073 = v1906->cache_dirty;
  v2073[v2070] = 1;
  struct StateT * v2075 = slot_8(v1906);
  return v2075;
}

struct StateT * slot_124(struct StateT * v7680) {
  int v7681 = v7680->timer;
  int v7688 = v7681 + 1;
  v7680->timer = v7688;
  int * v7683 = v7680->regs;
  int v7684 = v7683[22];
  int v7691 = v7684 << 7;
  v7683[22] = v7691;
  struct StateT * v7686 = slot_125(v7680);
  return v7686;
}

struct StateT * slot_128(struct StateT * v7739) {
  int v7740 = v7739->timer;
  int v7748 = v7740 + 1;
  v7739->timer = v7748;
  int * v7742 = v7739->regs;
  int v7743 = v7742[23];
  int v7744 = v7742[24];
  int v7752 = v7743 | v7744;
  v7742[23] = v7752;
  struct StateT * v7746 = slot_129(v7739);
  return v7746;
}

struct StateT * slot_365(struct StateT * v16564) {
  int v16565 = v16564->timer;
  int v16572 = v16565 + 1;
  v16564->timer = v16572;
  int * v16567 = v16564->regs;
  int v16568 = v16567[21];
  int v16575 = v16568 << 18;
  v16567[21] = v16575;
  struct StateT * v16570 = slot_366(v16564);
  return v16570;
}

struct StateT * slot_441(struct StateT * v17859) {
  int v17860 = v17859->timer;
  int v17868 = v17860 + 1;
  v17859->timer = v17868;
  int * v17862 = v17859->regs;
  int v17863 = v17862[12];
  int v17864 = v17862[17];
  int v17873 = v17863 + v17864;
  v17862[22] = v17873;
  struct StateT * v17866 = slot_442(v17859);
  return v17866;
}

struct StateT * slot_19(struct StateT * v5164) {
  int v5165 = v5164->timer;
  int v5275 = v5165 + 1;
  v5164->timer = v5275;
  int * v5167 = v5164->regs;
  int v5168 = v5167[11];
  int * v5169 = v5164->cache_tags;
  int v5279 = (((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2;
  int v5170 = v5169[v5279];
  int v5280 = ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5171 = v5169[v5280];
  int v5281 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2);
  int v5172 = v5169[v5281];
  int v5282 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5173 = v5169[v5282];
  int v5174 = v5164->timer;
  int v5283 = v5174 + ((100 ^ (((~(((v5172 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5172 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) | (~(((v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5170 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5170 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) | (~(((v5171 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5171 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5172 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5172 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) | (~(((v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5164->timer = v5283;
  int * v5176 = v5164->cache_vals;
  bool v5284 = !(((~(((v5170 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5170 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) | (~(((v5171 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5171 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31))) == 0);
  int v5269;
  if (v5284) {
    int * v5177 = v5164->cache_age;
    int v5286 = ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2) + ((~(((v5171 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5171 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) & 1);
    int v5178 = v5177[v5286];
    int v5179 = v5177[v5279];
    int v5287 = v5179 + ((int)((unsigned int)(v5179 - v5178) >> 31));
    v5177[v5279] = v5287;
    int * v5181 = v5164->cache_age;
    int v5182 = v5181[v5280];
    int v5289 = v5182 + ((int)((unsigned int)(v5182 - v5178) >> 31));
    v5181[v5280] = v5289;
    int * v5184 = v5164->cache_age;
    v5184[v5286] = 0;
    v5269 = v5286;
  } else {
    int * v5187 = v5164->cache_age;
    int v5293 = (((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2;
    int v5188 = v5187[v5293];
    int * v5189 = v5164->cache_tags;
    int v5190 = v5189[v5293];
    int v5191 = v5187[v5280];
    int v5192 = v5189[v5280];
    bool v5295 = !(((~(((v5172 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5172 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) | (~(((v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31))) == 0);
    int v5246;
    if (v5295) {
      int * v5193 = v5164->cache_age;
      int v5297 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))) | (-(v5173 ^ ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1))))) >> 31)) & 1);
      int v5194 = v5193[v5297];
      int v5195 = v5193[v5281];
      int v5298 = v5195 + ((int)((unsigned int)(v5195 - v5194) >> 31));
      v5193[v5281] = v5298;
      int * v5197 = v5164->cache_age;
      int v5198 = v5197[v5282];
      int v5300 = v5198 + ((int)((unsigned int)(v5198 - v5194) >> 31));
      v5197[v5282] = v5300;
      int * v5200 = v5164->cache_age;
      v5200[v5297] = 0;
      v5246 = v5297;
    } else {
      int * v5203 = v5164->cache_age;
      int v5304 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2);
      int v5204 = v5203[v5304];
      int * v5205 = v5164->cache_tags;
      int v5206 = v5205[v5304];
      int v5207 = v5203[v5282];
      int v5208 = v5205[v5282];
      int * v5209 = v5164->cache_dirty;
      int v5307 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + ((((v5204 + ((~(((v5206 ^ -1) | (-(v5206 ^ -1))) >> 31)) & 2)) - (v5207 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5210 = v5209[v5307];
      bool v5308 = !(v5210 == 0);
      if (v5308) {
        int * v5211 = v5164->cache_tags;
        int v5212 = v5211[v5307];
        int * v5213 = v5164->cache_vals;
        int v5311 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + ((((v5204 + ((~(((v5206 ^ -1) | (-(v5206 ^ -1))) >> 31)) & 2)) - (v5207 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5214 = v5213[v5311];
        int v5312 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + ((((v5204 + ((~(((v5206 ^ -1) | (-(v5206 ^ -1))) >> 31)) & 2)) - (v5207 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5215 = v5213[v5312];
        int * v5216 = v5164->mem;
        int v5314 = v5212 * 2;
        v5216[v5314] = v5214;
        int * v5218 = v5164->mem;
        int v5317 = (v5212 * 2) + 1;
        v5218[v5317] = v5215;
        ;
      } else {
        ;
      }
      int * v5223 = v5164->mem;
      int v5322 = ((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) * 2;
      int v5224 = v5223[v5322];
      int v5323 = (((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) * 2) + 1;
      int v5225 = v5223[v5323];
      int * v5226 = v5164->cache_vals;
      int v5325 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + ((((v5204 + ((~(((v5206 ^ -1) | (-(v5206 ^ -1))) >> 31)) & 2)) - (v5207 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5226[v5325] = v5224;
      int * v5228 = v5164->cache_vals;
      int v5328 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 3) * 2)) + ((((v5204 + ((~(((v5206 ^ -1) | (-(v5206 ^ -1))) >> 31)) & 2)) - (v5207 + ((~(((v5208 ^ -1) | (-(v5208 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5228[v5328] = v5225;
      int * v5230 = v5164->cache_tags;
      int v5331 = (int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1);
      v5230[v5307] = v5331;
      int * v5232 = v5164->cache_dirty;
      v5232[v5307] = 0;
      int * v5234 = v5164->cache_age;
      v5234[v5307] = 1;
      int * v5236 = v5164->cache_age;
      int v5237 = v5236[v5307];
      int v5238 = v5236[v5281];
      int v5337 = v5238 + ((int)((unsigned int)(v5238 - v5237) >> 31));
      v5236[v5281] = v5337;
      int * v5240 = v5164->cache_age;
      int v5241 = v5240[v5282];
      int v5339 = v5241 + ((int)((unsigned int)(v5241 - v5237) >> 31));
      v5240[v5282] = v5339;
      int * v5243 = v5164->cache_age;
      v5243[v5307] = 0;
      v5246 = v5307;
    }
    int * v5247 = v5164->cache_vals;
    int v5342 = v5246 * 2;
    int v5248 = v5247[v5342];
    int v5343 = (v5246 * 2) + 1;
    int v5249 = v5247[v5343];
    int v5344 = (((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2) + ((((v5188 + ((~(((v5190 ^ -1) | (-(v5190 ^ -1))) >> 31)) & 2)) - (v5191 + ((~(((v5192 ^ -1) | (-(v5192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5247[v5344] = v5248;
    int * v5251 = v5164->cache_vals;
    int v5347 = ((((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2) + ((((v5188 + ((~(((v5190 ^ -1) | (-(v5190 ^ -1))) >> 31)) & 2)) - (v5191 + ((~(((v5192 ^ -1) | (-(v5192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5251[v5347] = v5249;
    int * v5253 = v5164->cache_tags;
    int v5350 = ((((int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1)) & 1) * 2) + ((((v5188 + ((~(((v5190 ^ -1) | (-(v5190 ^ -1))) >> 31)) & 2)) - (v5191 + ((~(((v5192 ^ -1) | (-(v5192 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5351 = (int)((unsigned int)((int)((unsigned int)v5168 >> 2)) >> 1);
    v5253[v5350] = v5351;
    int * v5255 = v5164->cache_dirty;
    v5255[v5350] = 0;
    int * v5257 = v5164->cache_age;
    v5257[v5350] = 1;
    int * v5259 = v5164->cache_age;
    int v5260 = v5259[v5350];
    int v5261 = v5259[v5279];
    int v5357 = v5261 + ((int)((unsigned int)(v5261 - v5260) >> 31));
    v5259[v5279] = v5357;
    int * v5263 = v5164->cache_age;
    int v5264 = v5263[v5280];
    int v5359 = v5264 + ((int)((unsigned int)(v5264 - v5260) >> 31));
    v5263[v5280] = v5359;
    int * v5266 = v5164->cache_age;
    v5266[v5350] = 0;
    v5269 = v5350;
  }
  int v5362 = (v5269 * 2) + (((int)((unsigned int)v5168 >> 2)) & 1);
  int v5270 = v5176[v5362];
  int * v5271 = v5164->regs;
  v5271[12] = v5270;
  struct StateT * v5273 = slot_20(v5164);
  return v5273;
}

struct StateT * slot_382(struct StateT * v16842) {
  int * v16843 = v16842->saved_regs;
  int * v16844 = v16842->regs;
  int v16845 = v16844[23];
  v16843[23] = v16845;
  int v16847 = v16842->timer;
  int v16859 = v16847 + 1;
  v16842->timer = v16859;
  int * v16849 = v16842->regs;
  int v16850 = v16849[31];
  int v16851 = v16849[15];
  int v16863 = v16850 + v16851;
  v16849[23] = v16863;
  struct StateT * v16853 = slot_383(v16842);
  return v16853;
}

struct StateT * slot_523(struct StateT * v19169) {
  int v19170 = v19169->timer;
  int v19177 = v19170 + 1;
  v19169->timer = v19177;
  int * v19172 = v19169->regs;
  int v19173 = v19172[20];
  int v19181 = (int)((unsigned int)v19173 >> 14);
  v19172[24] = v19181;
  struct StateT * v19175 = slot_524(v19169);
  return v19175;
}

struct StateT * slot_87(struct StateT * v7045) {
  int v7046 = v7045->timer;
  int v7053 = v7046 + 1;
  v7045->timer = v7053;
  int * v7048 = v7045->regs;
  int v7049 = v7048[23];
  int v7056 = v7049 << 13;
  v7048[23] = v7056;
  struct StateT * v7051 = slot_88(v7045);
  return v7051;
}

struct StateT * slot_452(struct StateT * v18028) {
  int v18029 = v18028->timer;
  int v18036 = v18029 + 1;
  v18028->timer = v18036;
  int * v18031 = v18028->regs;
  int v18032 = v18031[23];
  int v18040 = (int)((unsigned int)v18032 >> 14);
  v18031[24] = v18040;
  struct StateT * v18034 = slot_453(v18028);
  return v18034;
}

struct StateT * slot_67(struct StateT * v6705) {
  int v6706 = v6705->timer;
  int v6713 = v6706 + 1;
  v6705->timer = v6713;
  int * v6708 = v6705->regs;
  int v6709 = v6708[23];
  int v6716 = v6709 << 9;
  v6708[23] = v6716;
  struct StateT * v6711 = slot_68(v6705);
  return v6711;
}

struct StateT * slot_81(struct StateT * v6955) {
  int v6956 = v6955->timer;
  int v6963 = v6956 + 1;
  v6955->timer = v6963;
  int * v6958 = v6955->regs;
  int v6959 = v6958[21];
  int v6966 = v6959 << 13;
  v6958[21] = v6966;
  struct StateT * v6961 = slot_82(v6955);
  return v6961;
}

struct StateT * slot_337(struct StateT * v16124) {
  int v16125 = v16124->timer;
  int v16133 = v16125 + 1;
  v16124->timer = v16133;
  int * v16127 = v16124->regs;
  int v16128 = v16127[17];
  int v16129 = v16127[14];
  int v16138 = v16128 + v16129;
  v16127[20] = v16138;
  struct StateT * v16131 = slot_338(v16124);
  return v16131;
}

struct StateT * slot_32(struct StateT * v6104) {
  int v6105 = v6104->timer;
  int v6109 = v6105 + 1;
  v6104->timer = v6109;
  struct StateT * v6107 = slot_33(v6104);
  return v6107;
}

struct StateT * slot_233(struct StateT * v14500) {
  int v14501 = v14500->timer;
  int v14509 = v14501 + 1;
  v14500->timer = v14509;
  int * v14503 = v14500->regs;
  int v14504 = v14503[9];
  int v14505 = v14503[20];
  int v14513 = v14504 ^ v14505;
  v14503[9] = v14513;
  struct StateT * v14507 = slot_234(v14500);
  return v14507;
}

struct StateT * slot_176(struct StateT * v8494) {
  int v8495 = v8494->timer;
  int v8503 = v8495 + 1;
  v8494->timer = v8503;
  int * v8497 = v8494->regs;
  int v8498 = v8497[19];
  int v8499 = v8497[7];
  int v8508 = v8498 + v8499;
  v8497[23] = v8508;
  struct StateT * v8501 = slot_177(v8494);
  return v8501;
}

struct StateT * slot_189(struct StateT * v8691) {
  int v8692 = v8691->timer;
  int v8700 = v8692 + 1;
  v8691->timer = v8700;
  int * v8694 = v8691->regs;
  int v8695 = v8694[30];
  int v8696 = v8694[20];
  int v8704 = v8695 ^ v8696;
  v8694[30] = v8704;
  struct StateT * v8698 = slot_190(v8691);
  return v8698;
}

struct StateT * slot_394(struct StateT * v17037) {
  int v17038 = v17037->timer;
  int v17046 = v17038 + 1;
  v17037->timer = v17046;
  int * v17040 = v17037->regs;
  int v17041 = v17040[23];
  int v17042 = v17040[24];
  int v17050 = v17041 | v17042;
  v17040[23] = v17050;
  struct StateT * v17044 = slot_395(v17037);
  return v17044;
}

struct StateT * slot_398(struct StateT * v17122) {
  int * v17123 = v17122->saved_regs;
  int * v17124 = v17122->regs;
  int v17125 = v17124[8];
  v17123[8] = v17125;
  int v17127 = v17122->timer;
  int v17139 = v17127 + 1;
  v17122->timer = v17139;
  int * v17129 = v17122->regs;
  int v17130 = v17129[8];
  int v17131 = v17129[23];
  int v17142 = v17130 ^ v17131;
  v17129[8] = v17142;
  struct StateT * v17133 = slot_399(v17122);
  return v17133;
}

struct StateT * slot_33(struct StateT * v6112) {
  int * v6113 = v6112->saved_regs;
  int * v6114 = v6112->regs;
  int v6115 = v6114[20];
  v6113[20] = v6115;
  int v6117 = v6112->timer;
  int v6129 = v6117 + 1;
  v6112->timer = v6129;
  int * v6119 = v6112->regs;
  int v6120 = v6119[30];
  int v6121 = v6119[16];
  int v6133 = v6120 + v6121;
  v6119[20] = v6133;
  struct StateT * v6123 = slot_34(v6112);
  return v6123;
}

struct StateT * slot_371(struct StateT * v16654) {
  int v16655 = v16654->timer;
  int v16662 = v16655 + 1;
  v16654->timer = v16662;
  int * v16657 = v16654->regs;
  int v16658 = v16657[23];
  int v16665 = v16658 << 18;
  v16657[23] = v16665;
  struct StateT * v16660 = slot_372(v16654);
  return v16660;
}

struct StateT * slot_330(struct StateT * v16015) {
  int v16016 = v16015->timer;
  int v16023 = v16016 + 1;
  v16015->timer = v16023;
  int * v16018 = v16015->regs;
  int v16019 = v16018[23];
  int v16027 = (int)((unsigned int)v16019 >> 23);
  v16018[24] = v16027;
  struct StateT * v16021 = slot_331(v16015);
  return v16021;
}

struct StateT * slot_450(struct StateT * v17998) {
  int v17999 = v17998->timer;
  int v18006 = v17999 + 1;
  v17998->timer = v18006;
  int * v18001 = v17998->regs;
  int v18002 = v18001[22];
  int v18009 = v18002 << 18;
  v18001[22] = v18009;
  struct StateT * v18004 = slot_451(v17998);
  return v18004;
}

struct StateT * slot_35(struct StateT * v6160) {
  int * v6161 = v6160->saved_regs;
  int * v6162 = v6160->regs;
  int v6163 = v6162[22];
  v6161[22] = v6163;
  int v6165 = v6160->timer;
  int v6177 = v6165 + 1;
  v6160->timer = v6177;
  int * v6167 = v6160->regs;
  int v6168 = v6167[28];
  int v6169 = v6167[12];
  int v6181 = v6168 + v6169;
  v6167[22] = v6181;
  struct StateT * v6171 = slot_36(v6160);
  return v6171;
}

struct StateT * slot_484(struct StateT * v18560) {
  int v18561 = v18560->timer;
  int v18568 = v18561 + 1;
  v18560->timer = v18568;
  int * v18563 = v18560->regs;
  int v18564 = v18563[20];
  int v18571 = v18564 << 9;
  v18563[20] = v18571;
  struct StateT * v18566 = slot_485(v18560);
  return v18566;
}

struct StateT * slot_258(struct StateT * v14893) {
  int v14894 = v14893->timer;
  int v14902 = v14894 + 1;
  v14893->timer = v14902;
  int * v14896 = v14893->regs;
  int v14897 = v14896[7];
  int v14898 = v14896[18];
  int v14907 = v14897 + v14898;
  v14896[21] = v14907;
  struct StateT * v14900 = slot_259(v14893);
  return v14900;
}

struct StateT * slot_166(struct StateT * v8334) {
  int v8335 = v8334->timer;
  int v8342 = v8335 + 1;
  v8334->timer = v8342;
  int * v8337 = v8334->regs;
  int v8338 = v8337[23];
  int v8346 = (int)((unsigned int)v8338 >> 19);
  v8337[24] = v8346;
  struct StateT * v8340 = slot_167(v8334);
  return v8340;
}

struct StateT * slot_418(struct StateT * v17462) {
  int * v17463 = v17462->saved_regs;
  int * v17464 = v17462->regs;
  int v17465 = v17464[5];
  v17463[5] = v17465;
  int v17467 = v17462->timer;
  int v17479 = v17467 + 1;
  v17462->timer = v17479;
  int * v17469 = v17462->regs;
  int v17470 = v17469[5];
  int v17471 = v17469[23];
  int v17482 = v17470 ^ v17471;
  v17469[5] = v17482;
  struct StateT * v17473 = slot_419(v17462);
  return v17473;
}

struct StateT * slot_51(struct StateT * v6441) {
  int * v6442 = v6441->saved_regs;
  int * v6443 = v6441->regs;
  int v6444 = v6443[19];
  v6442[19] = v6444;
  int v6446 = v6441->timer;
  int v6458 = v6446 + 1;
  v6441->timer = v6458;
  int * v6448 = v6441->regs;
  int v6449 = v6448[19];
  int v6450 = v6448[22];
  int v6461 = v6449 ^ v6450;
  v6448[19] = v6461;
  struct StateT * v6452 = slot_52(v6441);
  return v6452;
}

struct StateT * slot_25(struct StateT * v6006) {
  int v6007 = v6006->timer;
  int v6013 = v6007 + 1;
  v6006->timer = v6013;
  int * v6009 = v6006->regs;
  v6009[31] = 2036477952;
  struct StateT * v6011 = slot_26(v6006);
  return v6011;
}

struct StateT * slot_490(struct StateT * v18650) {
  int v18651 = v18650->timer;
  int v18658 = v18651 + 1;
  v18650->timer = v18658;
  int * v18653 = v18650->regs;
  int v18654 = v18653[22];
  int v18661 = v18654 << 9;
  v18653[22] = v18661;
  struct StateT * v18656 = slot_491(v18650);
  return v18656;
}

struct StateT * slot_264(struct StateT * v14989) {
  int v14990 = v14989->timer;
  int v14997 = v14990 + 1;
  v14989->timer = v14997;
  int * v14992 = v14989->regs;
  int v14993 = v14992[21];
  int v15001 = (int)((unsigned int)v14993 >> 19);
  v14992[24] = v15001;
  struct StateT * v14995 = slot_265(v14989);
  return v14995;
}

struct StateT * slot_339(struct StateT * v16158) {
  int v16159 = v16158->timer;
  int v16167 = v16159 + 1;
  v16158->timer = v16167;
  int * v16161 = v16158->regs;
  int v16162 = v16161[6];
  int v16163 = v16161[15];
  int v16172 = v16162 + v16163;
  v16161[22] = v16172;
  struct StateT * v16165 = slot_340(v16158);
  return v16165;
}

struct StateT * slot_123(struct StateT * v7665) {
  int v7666 = v7665->timer;
  int v7673 = v7666 + 1;
  v7665->timer = v7673;
  int * v7668 = v7665->regs;
  int v7669 = v7668[22];
  int v7677 = (int)((unsigned int)v7669 >> 25);
  v7668[24] = v7677;
  struct StateT * v7671 = slot_124(v7665);
  return v7671;
}

struct StateT * slot_97(struct StateT * v7235) {
  int v7236 = v7235->timer;
  int v7243 = v7236 + 1;
  v7235->timer = v7243;
  int * v7238 = v7235->regs;
  int v7239 = v7238[20];
  int v7247 = (int)((unsigned int)v7239 >> 14);
  v7238[24] = v7247;
  struct StateT * v7241 = slot_98(v7235);
  return v7241;
}

struct StateT * slot_106(struct StateT * v7370) {
  int v7371 = v7370->timer;
  int v7378 = v7371 + 1;
  v7370->timer = v7378;
  int * v7373 = v7370->regs;
  int v7374 = v7373[23];
  int v7382 = (int)((unsigned int)v7374 >> 14);
  v7373[24] = v7382;
  struct StateT * v7376 = slot_107(v7370);
  return v7376;
}

struct StateT * slot_299(struct StateT * v15534) {
  int v15535 = v15534->timer;
  int v15543 = v15535 + 1;
  v15534->timer = v15543;
  int * v15537 = v15534->regs;
  int v15538 = v15537[28];
  int v15539 = v15537[18];
  int v15548 = v15538 + v15539;
  v15537[22] = v15548;
  struct StateT * v15541 = slot_300(v15534);
  return v15541;
}

struct StateT * slot_539(struct StateT * v19413) {
  int * v19414 = v19413->saved_regs;
  int * v19415 = v19413->regs;
  int v19416 = v19415[13];
  v19414[13] = v19416;
  int v19418 = v19413->timer;
  int v19429 = v19418 + 1;
  v19413->timer = v19429;
  int * v19420 = v19413->regs;
  int v19421 = v19420[13];
  int v19431 = v19421 + 1;
  v19420[13] = v19431;
  struct StateT * v19423 = slot_540(v19413);
  return v19423;
}

struct StateT * slot_319(struct StateT * v15846) {
  int v15847 = v15846->timer;
  int v15855 = v15847 + 1;
  v15846->timer = v15855;
  int * v15849 = v15846->regs;
  int v15850 = v15849[15];
  int v15851 = v15849[28];
  int v15860 = v15850 + v15851;
  v15849[22] = v15860;
  struct StateT * v15853 = slot_320(v15846);
  return v15853;
}

struct StateT * slot_344(struct StateT * v16237) {
  int v16238 = v16237->timer;
  int v16245 = v16238 + 1;
  v16237->timer = v16245;
  int * v16240 = v16237->regs;
  int v16241 = v16240[21];
  int v16249 = (int)((unsigned int)v16241 >> 19);
  v16240[24] = v16249;
  struct StateT * v16243 = slot_345(v16237);
  return v16243;
}

struct StateT * slot_513(struct StateT * v19007) {
  int v19008 = v19007->timer;
  int v19015 = v19008 + 1;
  v19007->timer = v19015;
  int * v19010 = v19007->regs;
  int v19011 = v19010[23];
  int v19018 = v19011 << 13;
  v19010[23] = v19018;
  struct StateT * v19013 = slot_514(v19007);
  return v19013;
}

struct StateT * slot_130(struct StateT * v7771) {
  int v7772 = v7771->timer;
  int v7780 = v7772 + 1;
  v7771->timer = v7780;
  int * v7774 = v7771->regs;
  int v7775 = v7774[12];
  int v7776 = v7774[21];
  int v7784 = v7775 ^ v7776;
  v7774[12] = v7784;
  struct StateT * v7778 = slot_131(v7771);
  return v7778;
}

struct StateT * slot_497(struct StateT * v18757) {
  int v18758 = v18757->timer;
  int v18766 = v18758 + 1;
  v18757->timer = v18766;
  int * v18760 = v18757->regs;
  int v18761 = v18760[6];
  int v18762 = v18760[22];
  int v18770 = v18761 ^ v18762;
  v18760[6] = v18770;
  struct StateT * v18764 = slot_498(v18757);
  return v18764;
}

struct StateT * slot_455(struct StateT * v18073) {
  int * v18074 = v18073->saved_regs;
  int * v18075 = v18073->regs;
  int v18076 = v18075[30];
  v18074[30] = v18076;
  int v18078 = v18073->timer;
  int v18090 = v18078 + 1;
  v18073->timer = v18090;
  int * v18080 = v18073->regs;
  int v18081 = v18080[30];
  int v18082 = v18080[20];
  int v18093 = v18081 ^ v18082;
  v18080[30] = v18093;
  struct StateT * v18084 = slot_456(v18073);
  return v18084;
}

struct StateT * slot_141(struct StateT * v7947) {
  int v7948 = v7947->timer;
  int v7955 = v7948 + 1;
  v7947->timer = v7955;
  int * v7950 = v7947->regs;
  int v7951 = v7950[21];
  int v7958 = v7951 << 9;
  v7950[21] = v7958;
  struct StateT * v7953 = slot_142(v7947);
  return v7953;
}

struct StateT * slot_432(struct StateT * v17688) {
  int v17689 = v17688->timer;
  int v17696 = v17689 + 1;
  v17688->timer = v17696;
  int * v17691 = v17688->regs;
  int v17692 = v17691[23];
  int v17700 = (int)((unsigned int)v17692 >> 19);
  v17691[24] = v17700;
  struct StateT * v17694 = slot_433(v17688);
  return v17694;
}

struct StateT * slot_306(struct StateT * v15642) {
  int v15643 = v15642->timer;
  int v15651 = v15643 + 1;
  v15642->timer = v15651;
  int * v15645 = v15642->regs;
  int v15646 = v15645[21];
  int v15647 = v15645[24];
  int v15655 = v15646 | v15647;
  v15645[21] = v15655;
  struct StateT * v15649 = slot_307(v15642);
  return v15649;
}

struct StateT * slot_312(struct StateT * v15732) {
  int v15733 = v15732->timer;
  int v15741 = v15733 + 1;
  v15732->timer = v15741;
  int * v15735 = v15732->regs;
  int v15736 = v15735[23];
  int v15737 = v15735[24];
  int v15745 = v15736 | v15737;
  v15735[23] = v15745;
  struct StateT * v15739 = slot_313(v15732);
  return v15739;
}

struct StateT * slot_4(struct StateT * v961) {
  int v962 = v961->timer;
  int v1132 = v962 + 1;
  v961->timer = v1132;
  int * v964 = v961->regs;
  int v965 = v964[2];
  int v966 = v964[19];
  int * v967 = v961->cache_tags;
  int v1137 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2;
  int v968 = v967[v1137];
  int v1138 = ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v969 = v967[v1138];
  int v1139 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2);
  int v970 = v967[v1139];
  int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v971 = v967[v1140];
  int v972 = v961->timer;
  int v1141 = v972 + ((100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1141;
  bool v1142 = !(((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v1066;
  if (v1142) {
    int * v974 = v961->cache_age;
    int v1144 = ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v1151 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2;
    int v985 = v984[v1151];
    int * v986 = v961->cache_tags;
    int v987 = v986[v1151];
    int v988 = v984[v1138];
    int v989 = v986[v1138];
    bool v1153 = !(((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v1043;
    if (v1153) {
      int * v990 = v961->cache_age;
      int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) & 1);
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
      int v1162 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2);
      int v1001 = v1000[v1162];
      int * v1002 = v961->cache_tags;
      int v1003 = v1002[v1162];
      int v1004 = v1000[v1140];
      int v1005 = v1002[v1140];
      int * v1006 = v961->cache_dirty;
      int v1165 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1007 = v1006[v1165];
      bool v1166 = !(v1007 == 0);
      if (v1166) {
        int * v1008 = v961->cache_tags;
        int v1009 = v1008[v1165];
        int * v1010 = v961->cache_vals;
        int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1011 = v1010[v1169];
        int v1170 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v1180 = ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2;
      int v1021 = v1020[v1180];
      int v1181 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2) + 1;
      int v1022 = v1020[v1181];
      int * v1023 = v961->cache_vals;
      int v1183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1023[v1183] = v1021;
      int * v1025 = v961->cache_vals;
      int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1025[v1186] = v1022;
      int * v1027 = v961->cache_tags;
      int v1189 = (int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1);
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
    int v1202 = (((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1044[v1202] = v1045;
    int * v1048 = v961->cache_vals;
    int v1205 = ((((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1048[v1205] = v1046;
    int * v1050 = v961->cache_tags;
    int v1208 = ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1209 = (int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1);
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
  int v1220 = (v1066 * 2) + (((int)((unsigned int)(v965 + 32) >> 2)) & 1);
  v1067[v1220] = v966;
  int * v1069 = v961->cache_tags;
  int v1070 = v1069[v1139];
  int v1071 = v1069[v1140];
  bool v1223 = !(((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v1125;
  if (v1223) {
    int * v1072 = v961->cache_age;
    int v1225 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v1232 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2);
    int v1083 = v1082[v1232];
    int * v1084 = v961->cache_tags;
    int v1085 = v1084[v1232];
    int v1086 = v1082[v1140];
    int v1087 = v1084[v1140];
    int * v1088 = v961->cache_dirty;
    int v1235 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1089 = v1088[v1235];
    bool v1236 = !(v1089 == 0);
    if (v1236) {
      int * v1090 = v961->cache_tags;
      int v1091 = v1090[v1235];
      int * v1092 = v961->cache_vals;
      int v1239 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1093 = v1092[v1239];
      int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
    int v1250 = ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2;
    int v1103 = v1102[v1250];
    int v1251 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2) + 1;
    int v1104 = v1102[v1251];
    int * v1105 = v961->cache_vals;
    int v1253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1105[v1253] = v1103;
    int * v1107 = v961->cache_vals;
    int v1256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1107[v1256] = v1104;
    int * v1109 = v961->cache_tags;
    int v1259 = (int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1);
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
  int v1270 = (v1125 * 2) + (((int)((unsigned int)(v965 + 32) >> 2)) & 1);
  v1126[v1270] = v966;
  int * v1128 = v961->cache_dirty;
  v1128[v1125] = 1;
  struct StateT * v1130 = slot_5(v961);
  return v1130;
}

struct StateT * slot_240(struct StateT * v14615) {
  int v14616 = v14615->timer;
  int v14624 = v14616 + 1;
  v14615->timer = v14624;
  int * v14618 = v14615->regs;
  int v14619 = v14618[8];
  int v14620 = v14618[31];
  int v14629 = v14619 + v14620;
  v14618[23] = v14629;
  struct StateT * v14622 = slot_241(v14615);
  return v14622;
}

struct StateT * slot_247(struct StateT * v14722) {
  int v14723 = v14722->timer;
  int v14730 = v14723 + 1;
  v14722->timer = v14730;
  int * v14725 = v14722->regs;
  int v14726 = v14725[22];
  int v14734 = (int)((unsigned int)v14726 >> 23);
  v14725[24] = v14734;
  struct StateT * v14728 = slot_248(v14722);
  return v14728;
}

struct StateT * slot_70(struct StateT * v6758) {
  int * v6759 = v6758->saved_regs;
  int * v6760 = v6758->regs;
  int v6761 = v6760[7];
  v6759[7] = v6761;
  int v6763 = v6758->timer;
  int v6775 = v6763 + 1;
  v6758->timer = v6775;
  int * v6765 = v6758->regs;
  int v6766 = v6765[7];
  int v6767 = v6765[21];
  int v6778 = v6766 ^ v6767;
  v6765[7] = v6778;
  struct StateT * v6769 = slot_71(v6758);
  return v6769;
}

struct StateT * slot_168(struct StateT * v8363) {
  int v8364 = v8363->timer;
  int v8372 = v8364 + 1;
  v8363->timer = v8372;
  int * v8366 = v8363->regs;
  int v8367 = v8366[23];
  int v8368 = v8366[24];
  int v8376 = v8367 | v8368;
  v8366[23] = v8376;
  struct StateT * v8370 = slot_169(v8363);
  return v8370;
}

struct StateT * slot_348(struct StateT * v16297) {
  int v16298 = v16297->timer;
  int v16305 = v16298 + 1;
  v16297->timer = v16305;
  int * v16300 = v16297->regs;
  int v16301 = v16300[22];
  int v16308 = v16301 << 13;
  v16300[22] = v16308;
  struct StateT * v16303 = slot_349(v16297);
  return v16303;
}

struct StateT * slot_456(struct StateT * v18096) {
  int * v18097 = v18096->saved_regs;
  int * v18098 = v18096->regs;
  int v18099 = v18098[29];
  v18097[29] = v18099;
  int v18101 = v18096->timer;
  int v18113 = v18101 + 1;
  v18096->timer = v18113;
  int * v18103 = v18096->regs;
  int v18104 = v18103[29];
  int v18105 = v18103[21];
  int v18116 = v18104 ^ v18105;
  v18103[29] = v18116;
  struct StateT * v18107 = slot_457(v18096);
  return v18107;
}

struct StateT * slot_225(struct StateT * v14406) {
  int v14407 = v14406->timer;
  int v14414 = v14407 + 1;
  v14406->timer = v14414;
  int * v14409 = v14406->regs;
  int v14410 = v14409[2];
  int v14417 = v14410 + 48;
  v14409[2] = v14417;
  struct StateT * v14412 = slot_227(v14406);
  return v14412;
}

struct StateT * slot_467(struct StateT * v18293) {
  int v18294 = v18293->timer;
  int v18301 = v18294 + 1;
  v18293->timer = v18301;
  int * v18296 = v18293->regs;
  int v18297 = v18296[21];
  int v18304 = v18297 << 7;
  v18296[21] = v18304;
  struct StateT * v18299 = slot_468(v18293);
  return v18299;
}

struct StateT * slot_285(struct StateT * v15316) {
  int v15317 = v15316->timer;
  int v15324 = v15317 + 1;
  v15316->timer = v15324;
  int * v15319 = v15316->regs;
  int v15320 = v15319[21];
  int v15327 = v15320 << 18;
  v15319[21] = v15327;
  struct StateT * v15322 = slot_286(v15316);
  return v15322;
}

struct StateT * slot_213(struct StateT * v13341) {
  int v13342 = v13341->timer;
  int v13452 = v13342 + 1;
  v13341->timer = v13452;
  int * v13344 = v13341->regs;
  int v13345 = v13344[2];
  int * v13346 = v13341->cache_tags;
  int v13456 = (((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2;
  int v13347 = v13346[v13456];
  int v13457 = ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13348 = v13346[v13457];
  int v13458 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2);
  int v13349 = v13346[v13458];
  int v13459 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13350 = v13346[v13459];
  int v13351 = v13341->timer;
  int v13460 = v13351 + ((100 ^ (((~(((v13349 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13349 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13347 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13347 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v13348 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13348 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13349 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13349 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13341->timer = v13460;
  int * v13353 = v13341->cache_vals;
  bool v13461 = !(((~(((v13347 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13347 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v13348 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13348 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v13446;
  if (v13461) {
    int * v13354 = v13341->cache_age;
    int v13463 = ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v13348 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13348 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v13355 = v13354[v13463];
    int v13356 = v13354[v13456];
    int v13464 = v13356 + ((int)((unsigned int)(v13356 - v13355) >> 31));
    v13354[v13456] = v13464;
    int * v13358 = v13341->cache_age;
    int v13359 = v13358[v13457];
    int v13466 = v13359 + ((int)((unsigned int)(v13359 - v13355) >> 31));
    v13358[v13457] = v13466;
    int * v13361 = v13341->cache_age;
    v13361[v13463] = 0;
    v13446 = v13463;
  } else {
    int * v13364 = v13341->cache_age;
    int v13470 = (((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2;
    int v13365 = v13364[v13470];
    int * v13366 = v13341->cache_tags;
    int v13367 = v13366[v13470];
    int v13368 = v13364[v13457];
    int v13369 = v13366[v13457];
    bool v13472 = !(((~(((v13349 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13349 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v13423;
    if (v13472) {
      int * v13370 = v13341->cache_age;
      int v13474 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))) | (-(v13350 ^ ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v13371 = v13370[v13474];
      int v13372 = v13370[v13458];
      int v13475 = v13372 + ((int)((unsigned int)(v13372 - v13371) >> 31));
      v13370[v13458] = v13475;
      int * v13374 = v13341->cache_age;
      int v13375 = v13374[v13459];
      int v13477 = v13375 + ((int)((unsigned int)(v13375 - v13371) >> 31));
      v13374[v13459] = v13477;
      int * v13377 = v13341->cache_age;
      v13377[v13474] = 0;
      v13423 = v13474;
    } else {
      int * v13380 = v13341->cache_age;
      int v13481 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2);
      int v13381 = v13380[v13481];
      int * v13382 = v13341->cache_tags;
      int v13383 = v13382[v13481];
      int v13384 = v13380[v13459];
      int v13385 = v13382[v13459];
      int * v13386 = v13341->cache_dirty;
      int v13484 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13381 + ((~(((v13383 ^ -1) | (-(v13383 ^ -1))) >> 31)) & 2)) - (v13384 + ((~(((v13385 ^ -1) | (-(v13385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13387 = v13386[v13484];
      bool v13485 = !(v13387 == 0);
      if (v13485) {
        int * v13388 = v13341->cache_tags;
        int v13389 = v13388[v13484];
        int * v13390 = v13341->cache_vals;
        int v13488 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13381 + ((~(((v13383 ^ -1) | (-(v13383 ^ -1))) >> 31)) & 2)) - (v13384 + ((~(((v13385 ^ -1) | (-(v13385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13391 = v13390[v13488];
        int v13489 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13381 + ((~(((v13383 ^ -1) | (-(v13383 ^ -1))) >> 31)) & 2)) - (v13384 + ((~(((v13385 ^ -1) | (-(v13385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13392 = v13390[v13489];
        int * v13393 = v13341->mem;
        int v13491 = v13389 * 2;
        v13393[v13491] = v13391;
        int * v13395 = v13341->mem;
        int v13494 = (v13389 * 2) + 1;
        v13395[v13494] = v13392;
        ;
      } else {
        ;
      }
      int * v13400 = v13341->mem;
      int v13499 = ((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) * 2;
      int v13401 = v13400[v13499];
      int v13500 = (((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) * 2) + 1;
      int v13402 = v13400[v13500];
      int * v13403 = v13341->cache_vals;
      int v13502 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13381 + ((~(((v13383 ^ -1) | (-(v13383 ^ -1))) >> 31)) & 2)) - (v13384 + ((~(((v13385 ^ -1) | (-(v13385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13403[v13502] = v13401;
      int * v13405 = v13341->cache_vals;
      int v13505 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v13381 + ((~(((v13383 ^ -1) | (-(v13383 ^ -1))) >> 31)) & 2)) - (v13384 + ((~(((v13385 ^ -1) | (-(v13385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13405[v13505] = v13402;
      int * v13407 = v13341->cache_tags;
      int v13508 = (int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1);
      v13407[v13484] = v13508;
      int * v13409 = v13341->cache_dirty;
      v13409[v13484] = 0;
      int * v13411 = v13341->cache_age;
      v13411[v13484] = 1;
      int * v13413 = v13341->cache_age;
      int v13414 = v13413[v13484];
      int v13415 = v13413[v13458];
      int v13514 = v13415 + ((int)((unsigned int)(v13415 - v13414) >> 31));
      v13413[v13458] = v13514;
      int * v13417 = v13341->cache_age;
      int v13418 = v13417[v13459];
      int v13516 = v13418 + ((int)((unsigned int)(v13418 - v13414) >> 31));
      v13417[v13459] = v13516;
      int * v13420 = v13341->cache_age;
      v13420[v13484] = 0;
      v13423 = v13484;
    }
    int * v13424 = v13341->cache_vals;
    int v13519 = v13423 * 2;
    int v13425 = v13424[v13519];
    int v13520 = (v13423 * 2) + 1;
    int v13426 = v13424[v13520];
    int v13521 = (((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v13365 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2)) - (v13368 + ((~(((v13369 ^ -1) | (-(v13369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13424[v13521] = v13425;
    int * v13428 = v13341->cache_vals;
    int v13524 = ((((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v13365 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2)) - (v13368 + ((~(((v13369 ^ -1) | (-(v13369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13428[v13524] = v13426;
    int * v13430 = v13341->cache_tags;
    int v13527 = ((((int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v13365 + ((~(((v13367 ^ -1) | (-(v13367 ^ -1))) >> 31)) & 2)) - (v13368 + ((~(((v13369 ^ -1) | (-(v13369 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13528 = (int)((unsigned int)((int)((unsigned int)(v13345 + 36) >> 2)) >> 1);
    v13430[v13527] = v13528;
    int * v13432 = v13341->cache_dirty;
    v13432[v13527] = 0;
    int * v13434 = v13341->cache_age;
    v13434[v13527] = 1;
    int * v13436 = v13341->cache_age;
    int v13437 = v13436[v13527];
    int v13438 = v13436[v13456];
    int v13534 = v13438 + ((int)((unsigned int)(v13438 - v13437) >> 31));
    v13436[v13456] = v13534;
    int * v13440 = v13341->cache_age;
    int v13441 = v13440[v13457];
    int v13536 = v13441 + ((int)((unsigned int)(v13441 - v13437) >> 31));
    v13440[v13457] = v13536;
    int * v13443 = v13341->cache_age;
    v13443[v13527] = 0;
    v13446 = v13527;
  }
  int v13539 = (v13446 * 2) + (((int)((unsigned int)(v13345 + 36) >> 2)) & 1);
  int v13447 = v13353[v13539];
  int * v13448 = v13341->regs;
  v13448[18] = v13447;
  struct StateT * v13450 = slot_214(v13341);
  return v13450;
}

struct StateT * slot_82(struct StateT * v6969) {
  int v6970 = v6969->timer;
  int v6978 = v6970 + 1;
  v6969->timer = v6978;
  int * v6972 = v6969->regs;
  int v6973 = v6972[21];
  int v6974 = v6972[24];
  int v6982 = v6973 | v6974;
  v6972[21] = v6982;
  struct StateT * v6976 = slot_83(v6969);
  return v6976;
}

struct StateT * slot_263(struct StateT * v14973) {
  int v14974 = v14973->timer;
  int v14982 = v14974 + 1;
  v14973->timer = v14982;
  int * v14976 = v14973->regs;
  int v14977 = v14976[20];
  int v14978 = v14976[24];
  int v14986 = v14977 | v14978;
  v14976[20] = v14986;
  struct StateT * v14980 = slot_264(v14973);
  return v14980;
}

struct StateT * slot_161(struct StateT * v8259) {
  int v8260 = v8259->timer;
  int v8267 = v8260 + 1;
  v8259->timer = v8267;
  int * v8262 = v8259->regs;
  int v8263 = v8262[21];
  int v8270 = v8263 << 13;
  v8262[21] = v8270;
  struct StateT * v8265 = slot_162(v8259);
  return v8265;
}

struct StateT * slot_293(struct StateT * v15436) {
  int v15437 = v15436->timer;
  int v15445 = v15437 + 1;
  v15436->timer = v15445;
  int * v15439 = v15436->regs;
  int v15440 = v15439[30];
  int v15441 = v15439[20];
  int v15449 = v15440 ^ v15441;
  v15439[30] = v15449;
  struct StateT * v15443 = slot_294(v15436);
  return v15443;
}

struct StateT * slot_185(struct StateT * v8630) {
  int v8631 = v8630->timer;
  int v8639 = v8631 + 1;
  v8630->timer = v8639;
  int * v8633 = v8630->regs;
  int v8634 = v8633[22];
  int v8635 = v8633[24];
  int v8643 = v8634 | v8635;
  v8633[22] = v8643;
  struct StateT * v8637 = slot_186(v8630);
  return v8637;
}

struct StateT * slot_288(struct StateT * v15361) {
  int v15362 = v15361->timer;
  int v15369 = v15362 + 1;
  v15361->timer = v15369;
  int * v15364 = v15361->regs;
  int v15365 = v15364[22];
  int v15372 = v15365 << 18;
  v15364[22] = v15372;
  struct StateT * v15367 = slot_289(v15361);
  return v15367;
}

struct StateT * slot_89(struct StateT * v7075) {
  int * v7076 = v7075->saved_regs;
  int * v7077 = v7075->regs;
  int v7078 = v7077[16];
  v7076[16] = v7078;
  int v7080 = v7075->timer;
  int v7092 = v7080 + 1;
  v7075->timer = v7092;
  int * v7082 = v7075->regs;
  int v7083 = v7082[16];
  int v7084 = v7082[20];
  int v7095 = v7083 ^ v7084;
  v7082[16] = v7095;
  struct StateT * v7086 = slot_90(v7075);
  return v7086;
}

struct StateT * slot_384(struct StateT * v16888) {
  int v16889 = v16888->timer;
  int v16896 = v16889 + 1;
  v16888->timer = v16896;
  int * v16891 = v16888->regs;
  int v16892 = v16891[20];
  int v16899 = v16892 << 7;
  v16891[20] = v16899;
  struct StateT * v16894 = slot_385(v16888);
  return v16894;
}

struct StateT * slot_486(struct StateT * v18590) {
  int v18591 = v18590->timer;
  int v18598 = v18591 + 1;
  v18590->timer = v18598;
  int * v18593 = v18590->regs;
  int v18594 = v18593[21];
  int v18602 = (int)((unsigned int)v18594 >> 23);
  v18593[24] = v18602;
  struct StateT * v18596 = slot_487(v18590);
  return v18596;
}

struct StateT * slot_347(struct StateT * v16282) {
  int v16283 = v16282->timer;
  int v16290 = v16283 + 1;
  v16282->timer = v16290;
  int * v16285 = v16282->regs;
  int v16286 = v16285[22];
  int v16294 = (int)((unsigned int)v16286 >> 19);
  v16285[24] = v16294;
  struct StateT * v16288 = slot_348(v16282);
  return v16288;
}

struct StateT * slot_140(struct StateT * v7932) {
  int v7933 = v7932->timer;
  int v7940 = v7933 + 1;
  v7932->timer = v7940;
  int * v7935 = v7932->regs;
  int v7936 = v7935[21];
  int v7944 = (int)((unsigned int)v7936 >> 23);
  v7935[24] = v7944;
  struct StateT * v7938 = slot_141(v7932);
  return v7938;
}

struct StateT * slot_473(struct StateT * v18383) {
  int v18384 = v18383->timer;
  int v18391 = v18384 + 1;
  v18383->timer = v18391;
  int * v18386 = v18383->regs;
  int v18387 = v18386[23];
  int v18394 = v18387 << 7;
  v18386[23] = v18394;
  struct StateT * v18389 = slot_474(v18383);
  return v18389;
}

struct StateT * slot_49(struct StateT * v6395) {
  int * v6396 = v6395->saved_regs;
  int * v6397 = v6395->regs;
  int v6398 = v6397[9];
  v6396[9] = v6398;
  int v6400 = v6395->timer;
  int v6412 = v6400 + 1;
  v6395->timer = v6412;
  int * v6402 = v6395->regs;
  int v6403 = v6402[9];
  int v6404 = v6402[20];
  int v6415 = v6403 ^ v6404;
  v6402[9] = v6415;
  struct StateT * v6406 = slot_50(v6395);
  return v6406;
}

struct StateT * slot_216(struct StateT * v12902) {
  int v12903 = v12902->timer;
  int v12911 = v12903 + 1;
  v12902->timer = v12911;
  int * v12905 = v12902->regs;
  int v12906 = v12905[20];
  int v12907 = v12905[24];
  int v12915 = v12906 | v12907;
  v12905[20] = v12915;
  struct StateT * v12909 = slot_218(v12902);
  return v12909;
}

struct StateT * slot_468(struct StateT * v18307) {
  int v18308 = v18307->timer;
  int v18316 = v18308 + 1;
  v18307->timer = v18316;
  int * v18310 = v18307->regs;
  int v18311 = v18310[21];
  int v18312 = v18310[24];
  int v18320 = v18311 | v18312;
  v18310[21] = v18320;
  struct StateT * v18314 = slot_469(v18307);
  return v18314;
}

struct StateT * slot_50(struct StateT * v6418) {
  int * v6419 = v6418->saved_regs;
  int * v6420 = v6418->regs;
  int v6421 = v6420[18];
  v6419[18] = v6421;
  int v6423 = v6418->timer;
  int v6435 = v6423 + 1;
  v6418->timer = v6435;
  int * v6425 = v6418->regs;
  int v6426 = v6425[18];
  int v6427 = v6425[21];
  int v6438 = v6426 ^ v6427;
  v6425[18] = v6438;
  struct StateT * v6429 = slot_51(v6418);
  return v6429;
}

struct StateT * slot_135(struct StateT * v7853) {
  int v7854 = v7853->timer;
  int v7862 = v7854 + 1;
  v7853->timer = v7862;
  int * v7856 = v7853->regs;
  int v7857 = v7856[15];
  int v7858 = v7856[28];
  int v7867 = v7857 + v7858;
  v7856[22] = v7867;
  struct StateT * v7860 = slot_136(v7853);
  return v7860;
}

struct StateT * slot_248(struct StateT * v14737) {
  int v14738 = v14737->timer;
  int v14745 = v14738 + 1;
  v14737->timer = v14745;
  int * v14740 = v14737->regs;
  int v14741 = v14740[22];
  int v14748 = v14741 << 9;
  v14740[22] = v14748;
  struct StateT * v14743 = slot_249(v14737);
  return v14743;
}

struct StateT * slot_59(struct StateT * v6584) {
  int v6585 = v6584->timer;
  int v6593 = v6585 + 1;
  v6584->timer = v6593;
  int * v6587 = v6584->regs;
  int v6588 = v6587[20];
  int v6589 = v6587[24];
  int v6597 = v6588 | v6589;
  v6587[20] = v6597;
  struct StateT * v6591 = slot_60(v6584);
  return v6591;
}

struct StateT * slot_485(struct StateT * v18574) {
  int v18575 = v18574->timer;
  int v18583 = v18575 + 1;
  v18574->timer = v18583;
  int * v18577 = v18574->regs;
  int v18578 = v18577[20];
  int v18579 = v18577[24];
  int v18587 = v18578 | v18579;
  v18577[20] = v18587;
  struct StateT * v18581 = slot_486(v18574);
  return v18581;
}

struct StateT * slot_40(struct StateT * v6260) {
  int v6261 = v6260->timer;
  int v6268 = v6261 + 1;
  v6260->timer = v6268;
  int * v6263 = v6260->regs;
  int v6264 = v6263[21];
  int v6272 = (int)((unsigned int)v6264 >> 25);
  v6263[24] = v6272;
  struct StateT * v6266 = slot_41(v6260);
  return v6266;
}

struct StateT * slot_77(struct StateT * v6895) {
  int v6896 = v6895->timer;
  int v6903 = v6896 + 1;
  v6895->timer = v6903;
  int * v6898 = v6895->regs;
  int v6899 = v6898[20];
  int v6907 = (int)((unsigned int)v6899 >> 19);
  v6898[24] = v6907;
  struct StateT * v6901 = slot_78(v6895);
  return v6901;
}

struct StateT * slot_85(struct StateT * v7014) {
  int v7015 = v7014->timer;
  int v7023 = v7015 + 1;
  v7014->timer = v7023;
  int * v7017 = v7014->regs;
  int v7018 = v7017[22];
  int v7019 = v7017[24];
  int v7027 = v7018 | v7019;
  v7017[22] = v7027;
  struct StateT * v7021 = slot_86(v7014);
  return v7021;
}

struct StateT * slot_350(struct StateT * v16327) {
  int v16328 = v16327->timer;
  int v16335 = v16328 + 1;
  v16327->timer = v16335;
  int * v16330 = v16327->regs;
  int v16331 = v16330[23];
  int v16339 = (int)((unsigned int)v16331 >> 19);
  v16330[24] = v16339;
  struct StateT * v16333 = slot_351(v16327);
  return v16333;
}

struct StateT * slot_392(struct StateT * v17008) {
  int v17009 = v17008->timer;
  int v17016 = v17009 + 1;
  v17008->timer = v17016;
  int * v17011 = v17008->regs;
  int v17012 = v17011[23];
  int v17020 = (int)((unsigned int)v17012 >> 25);
  v17011[24] = v17020;
  struct StateT * v17014 = slot_393(v17008);
  return v17014;
}

struct StateT * slot_75(struct StateT * v6861) {
  int v6862 = v6861->timer;
  int v6870 = v6862 + 1;
  v6861->timer = v6870;
  int * v6864 = v6861->regs;
  int v6865 = v6864[17];
  int v6866 = v6864[19];
  int v6875 = v6865 + v6866;
  v6864[22] = v6875;
  struct StateT * v6868 = slot_76(v6861);
  return v6868;
}

struct StateT * slot_71(struct StateT * v6781) {
  int * v6782 = v6781->saved_regs;
  int * v6783 = v6781->regs;
  int v6784 = v6783[17];
  v6782[17] = v6784;
  int v6786 = v6781->timer;
  int v6798 = v6786 + 1;
  v6781->timer = v6798;
  int * v6788 = v6781->regs;
  int v6789 = v6788[17];
  int v6790 = v6788[22];
  int v6801 = v6789 ^ v6790;
  v6788[17] = v6801;
  struct StateT * v6792 = slot_72(v6781);
  return v6792;
}

struct StateT * slot_378(struct StateT * v16762) {
  int v16763 = v16762->timer;
  int v16767 = v16763 + 1;
  v16762->timer = v16767;
  struct StateT * v16765 = slot_379(v16762);
  return v16765;
}

struct StateT * slot_108(struct StateT * v7399) {
  int v7400 = v7399->timer;
  int v7408 = v7400 + 1;
  v7399->timer = v7408;
  int * v7402 = v7399->regs;
  int v7403 = v7402[23];
  int v7404 = v7402[24];
  int v7412 = v7403 | v7404;
  v7402[23] = v7412;
  struct StateT * v7406 = slot_109(v7399);
  return v7406;
}

struct StateT * slot_116(struct StateT * v7558) {
  int v7559 = v7558->timer;
  int v7567 = v7559 + 1;
  v7558->timer = v7567;
  int * v7561 = v7558->regs;
  int v7562 = v7561[31];
  int v7563 = v7561[19];
  int v7572 = v7562 + v7563;
  v7561[23] = v7572;
  struct StateT * v7565 = slot_117(v7558);
  return v7565;
}

struct StateT * slot_417(struct StateT * v17439) {
  int * v17440 = v17439->saved_regs;
  int * v17441 = v17439->regs;
  int v17442 = v17441[17];
  v17440[17] = v17442;
  int v17444 = v17439->timer;
  int v17456 = v17444 + 1;
  v17439->timer = v17456;
  int * v17446 = v17439->regs;
  int v17447 = v17446[17];
  int v17448 = v17446[22];
  int v17459 = v17447 ^ v17448;
  v17446[17] = v17459;
  struct StateT * v17450 = slot_418(v17439);
  return v17450;
}

struct StateT * slot_405(struct StateT * v17242) {
  int v17243 = v17242->timer;
  int v17251 = v17243 + 1;
  v17242->timer = v17251;
  int * v17245 = v17242->regs;
  int v17246 = v17245[20];
  int v17247 = v17245[24];
  int v17255 = v17246 | v17247;
  v17245[20] = v17255;
  struct StateT * v17249 = slot_406(v17242);
  return v17249;
}

struct StateT * slot_215(struct StateT * v12698) {
  int v12699 = v12698->timer;
  int v12809 = v12699 + 1;
  v12698->timer = v12809;
  int * v12701 = v12698->regs;
  int v12702 = v12701[2];
  int * v12703 = v12698->cache_tags;
  int v12813 = (((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2;
  int v12704 = v12703[v12813];
  int v12814 = ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12705 = v12703[v12814];
  int v12815 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2);
  int v12706 = v12703[v12815];
  int v12816 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12707 = v12703[v12816];
  int v12708 = v12698->timer;
  int v12817 = v12708 + ((100 ^ (((~(((v12706 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12706 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12704 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12704 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12705 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12705 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12706 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12706 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12698->timer = v12817;
  int * v12710 = v12698->cache_vals;
  bool v12818 = !(((~(((v12704 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12704 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12705 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12705 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v12803;
  if (v12818) {
    int * v12711 = v12698->cache_age;
    int v12820 = ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v12705 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12705 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v12712 = v12711[v12820];
    int v12713 = v12711[v12813];
    int v12821 = v12713 + ((int)((unsigned int)(v12713 - v12712) >> 31));
    v12711[v12813] = v12821;
    int * v12715 = v12698->cache_age;
    int v12716 = v12715[v12814];
    int v12823 = v12716 + ((int)((unsigned int)(v12716 - v12712) >> 31));
    v12715[v12814] = v12823;
    int * v12718 = v12698->cache_age;
    v12718[v12820] = 0;
    v12803 = v12820;
  } else {
    int * v12721 = v12698->cache_age;
    int v12827 = (((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2;
    int v12722 = v12721[v12827];
    int * v12723 = v12698->cache_tags;
    int v12724 = v12723[v12827];
    int v12725 = v12721[v12814];
    int v12726 = v12723[v12814];
    bool v12829 = !(((~(((v12706 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12706 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v12780;
    if (v12829) {
      int * v12727 = v12698->cache_age;
      int v12831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))) | (-(v12707 ^ ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v12728 = v12727[v12831];
      int v12729 = v12727[v12815];
      int v12832 = v12729 + ((int)((unsigned int)(v12729 - v12728) >> 31));
      v12727[v12815] = v12832;
      int * v12731 = v12698->cache_age;
      int v12732 = v12731[v12816];
      int v12834 = v12732 + ((int)((unsigned int)(v12732 - v12728) >> 31));
      v12731[v12816] = v12834;
      int * v12734 = v12698->cache_age;
      v12734[v12831] = 0;
      v12780 = v12831;
    } else {
      int * v12737 = v12698->cache_age;
      int v12838 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2);
      int v12738 = v12737[v12838];
      int * v12739 = v12698->cache_tags;
      int v12740 = v12739[v12838];
      int v12741 = v12737[v12816];
      int v12742 = v12739[v12816];
      int * v12743 = v12698->cache_dirty;
      int v12841 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12738 + ((~(((v12740 ^ -1) | (-(v12740 ^ -1))) >> 31)) & 2)) - (v12741 + ((~(((v12742 ^ -1) | (-(v12742 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12744 = v12743[v12841];
      bool v12842 = !(v12744 == 0);
      if (v12842) {
        int * v12745 = v12698->cache_tags;
        int v12746 = v12745[v12841];
        int * v12747 = v12698->cache_vals;
        int v12845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12738 + ((~(((v12740 ^ -1) | (-(v12740 ^ -1))) >> 31)) & 2)) - (v12741 + ((~(((v12742 ^ -1) | (-(v12742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12748 = v12747[v12845];
        int v12846 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12738 + ((~(((v12740 ^ -1) | (-(v12740 ^ -1))) >> 31)) & 2)) - (v12741 + ((~(((v12742 ^ -1) | (-(v12742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12749 = v12747[v12846];
        int * v12750 = v12698->mem;
        int v12848 = v12746 * 2;
        v12750[v12848] = v12748;
        int * v12752 = v12698->mem;
        int v12851 = (v12746 * 2) + 1;
        v12752[v12851] = v12749;
        ;
      } else {
        ;
      }
      int * v12757 = v12698->mem;
      int v12856 = ((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) * 2;
      int v12758 = v12757[v12856];
      int v12857 = (((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) * 2) + 1;
      int v12759 = v12757[v12857];
      int * v12760 = v12698->cache_vals;
      int v12859 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12738 + ((~(((v12740 ^ -1) | (-(v12740 ^ -1))) >> 31)) & 2)) - (v12741 + ((~(((v12742 ^ -1) | (-(v12742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12760[v12859] = v12758;
      int * v12762 = v12698->cache_vals;
      int v12862 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12738 + ((~(((v12740 ^ -1) | (-(v12740 ^ -1))) >> 31)) & 2)) - (v12741 + ((~(((v12742 ^ -1) | (-(v12742 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12762[v12862] = v12759;
      int * v12764 = v12698->cache_tags;
      int v12865 = (int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1);
      v12764[v12841] = v12865;
      int * v12766 = v12698->cache_dirty;
      v12766[v12841] = 0;
      int * v12768 = v12698->cache_age;
      v12768[v12841] = 1;
      int * v12770 = v12698->cache_age;
      int v12771 = v12770[v12841];
      int v12772 = v12770[v12815];
      int v12871 = v12772 + ((int)((unsigned int)(v12772 - v12771) >> 31));
      v12770[v12815] = v12871;
      int * v12774 = v12698->cache_age;
      int v12775 = v12774[v12816];
      int v12873 = v12775 + ((int)((unsigned int)(v12775 - v12771) >> 31));
      v12774[v12816] = v12873;
      int * v12777 = v12698->cache_age;
      v12777[v12841] = 0;
      v12780 = v12841;
    }
    int * v12781 = v12698->cache_vals;
    int v12876 = v12780 * 2;
    int v12782 = v12781[v12876];
    int v12877 = (v12780 * 2) + 1;
    int v12783 = v12781[v12877];
    int v12878 = (((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12722 + ((~(((v12724 ^ -1) | (-(v12724 ^ -1))) >> 31)) & 2)) - (v12725 + ((~(((v12726 ^ -1) | (-(v12726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12781[v12878] = v12782;
    int * v12785 = v12698->cache_vals;
    int v12881 = ((((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12722 + ((~(((v12724 ^ -1) | (-(v12724 ^ -1))) >> 31)) & 2)) - (v12725 + ((~(((v12726 ^ -1) | (-(v12726 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12785[v12881] = v12783;
    int * v12787 = v12698->cache_tags;
    int v12884 = ((((int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12722 + ((~(((v12724 ^ -1) | (-(v12724 ^ -1))) >> 31)) & 2)) - (v12725 + ((~(((v12726 ^ -1) | (-(v12726 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12885 = (int)((unsigned int)((int)((unsigned int)(v12702 + 28) >> 2)) >> 1);
    v12787[v12884] = v12885;
    int * v12789 = v12698->cache_dirty;
    v12789[v12884] = 0;
    int * v12791 = v12698->cache_age;
    v12791[v12884] = 1;
    int * v12793 = v12698->cache_age;
    int v12794 = v12793[v12884];
    int v12795 = v12793[v12813];
    int v12891 = v12795 + ((int)((unsigned int)(v12795 - v12794) >> 31));
    v12793[v12813] = v12891;
    int * v12797 = v12698->cache_age;
    int v12798 = v12797[v12814];
    int v12893 = v12798 + ((int)((unsigned int)(v12798 - v12794) >> 31));
    v12797[v12814] = v12893;
    int * v12800 = v12698->cache_age;
    v12800[v12884] = 0;
    v12803 = v12884;
  }
  int v12896 = (v12803 * 2) + (((int)((unsigned int)(v12702 + 28) >> 2)) & 1);
  int v12804 = v12710[v12896];
  int * v12805 = v12698->regs;
  v12805[20] = v12804;
  struct StateT * v12807 = slot_217(v12698);
  return v12807;
}

struct StateT * slot_45(struct StateT * v6334) {
  int v6335 = v6334->timer;
  int v6343 = v6335 + 1;
  v6334->timer = v6343;
  int * v6337 = v6334->regs;
  int v6338 = v6337[22];
  int v6339 = v6337[24];
  int v6347 = v6338 | v6339;
  v6337[22] = v6347;
  struct StateT * v6341 = slot_46(v6334);
  return v6341;
}

struct StateT * slot_220(struct StateT * v13749) {
  int v13750 = v13749->timer;
  int v13757 = v13750 + 1;
  v13749->timer = v13757;
  int * v13752 = v13749->regs;
  int v13753 = v13752[21];
  int v13760 = v13753 << 7;
  v13752[21] = v13760;
  struct StateT * v13755 = slot_222(v13749);
  return v13755;
}

struct StateT * slot_134(struct StateT * v7836) {
  int v7837 = v7836->timer;
  int v7845 = v7837 + 1;
  v7836->timer = v7845;
  int * v7839 = v7836->regs;
  int v7840 = v7839[12];
  int v7841 = v7839[29];
  int v7850 = v7840 + v7841;
  v7839[21] = v7850;
  struct StateT * v7843 = slot_135(v7836);
  return v7843;
}

struct StateT * slot_463(struct StateT * v18233) {
  int v18234 = v18233->timer;
  int v18241 = v18234 + 1;
  v18233->timer = v18241;
  int * v18236 = v18233->regs;
  int v18237 = v18236[20];
  int v18245 = (int)((unsigned int)v18237 >> 25);
  v18236[24] = v18245;
  struct StateT * v18239 = slot_464(v18233);
  return v18239;
}

struct StateT * slot_175(struct StateT * v8477) {
  int v8478 = v8477->timer;
  int v8486 = v8478 + 1;
  v8477->timer = v8486;
  int * v8480 = v8477->regs;
  int v8481 = v8480[18];
  int v8482 = v8480[6];
  int v8491 = v8481 + v8482;
  v8480[22] = v8491;
  struct StateT * v8484 = slot_176(v8477);
  return v8484;
}

struct StateT * slot_387(struct StateT * v16933) {
  int v16934 = v16933->timer;
  int v16941 = v16934 + 1;
  v16933->timer = v16941;
  int * v16936 = v16933->regs;
  int v16937 = v16936[21];
  int v16944 = v16937 << 7;
  v16936[21] = v16944;
  struct StateT * v16939 = slot_388(v16933);
  return v16939;
}

struct StateT * slot_273(struct StateT * v15124) {
  int v15125 = v15124->timer;
  int v15133 = v15125 + 1;
  v15124->timer = v15133;
  int * v15127 = v15124->regs;
  int v15128 = v15127[16];
  int v15129 = v15127[20];
  int v15137 = v15128 ^ v15129;
  v15127[16] = v15137;
  struct StateT * v15131 = slot_274(v15124);
  return v15131;
}

struct StateT * slot_69(struct StateT * v6735) {
  int * v6736 = v6735->saved_regs;
  int * v6737 = v6735->regs;
  int v6738 = v6737[6];
  v6736[6] = v6738;
  int v6740 = v6735->timer;
  int v6752 = v6740 + 1;
  v6735->timer = v6752;
  int * v6742 = v6735->regs;
  int v6743 = v6742[6];
  int v6744 = v6742[20];
  int v6755 = v6743 ^ v6744;
  v6742[6] = v6755;
  struct StateT * v6746 = slot_70(v6735);
  return v6746;
}

struct StateT * slot_188(struct StateT * v8675) {
  int v8676 = v8675->timer;
  int v8684 = v8676 + 1;
  v8675->timer = v8684;
  int * v8678 = v8675->regs;
  int v8679 = v8678[23];
  int v8680 = v8678[24];
  int v8688 = v8679 | v8680;
  v8678[23] = v8688;
  struct StateT * v8682 = slot_189(v8675);
  return v8682;
}

struct StateT * slot_495(struct StateT * v18725) {
  int v18726 = v18725->timer;
  int v18734 = v18726 + 1;
  v18725->timer = v18734;
  int * v18728 = v18725->regs;
  int v18729 = v18728[17];
  int v18730 = v18728[20];
  int v18738 = v18729 ^ v18730;
  v18728[17] = v18738;
  struct StateT * v18732 = slot_496(v18725);
  return v18732;
}

struct StateT * slot_186(struct StateT * v8646) {
  int v8647 = v8646->timer;
  int v8654 = v8647 + 1;
  v8646->timer = v8654;
  int * v8649 = v8646->regs;
  int v8650 = v8649[23];
  int v8658 = (int)((unsigned int)v8650 >> 14);
  v8649[24] = v8658;
  struct StateT * v8652 = slot_187(v8646);
  return v8652;
}

struct StateT * slot_102(struct StateT * v7309) {
  int v7310 = v7309->timer;
  int v7318 = v7310 + 1;
  v7309->timer = v7318;
  int * v7312 = v7309->regs;
  int v7313 = v7312[21];
  int v7314 = v7312[24];
  int v7322 = v7313 | v7314;
  v7312[21] = v7322;
  struct StateT * v7316 = slot_103(v7309);
  return v7316;
}

struct StateT * slot_145(struct StateT * v8006) {
  int v8007 = v8006->timer;
  int v8015 = v8007 + 1;
  v8006->timer = v8015;
  int * v8009 = v8006->regs;
  int v8010 = v8009[22];
  int v8011 = v8009[24];
  int v8019 = v8010 | v8011;
  v8009[22] = v8019;
  struct StateT * v8013 = slot_146(v8006);
  return v8013;
}

struct StateT * slot_110(struct StateT * v7438) {
  int * v7439 = v7438->saved_regs;
  int * v7440 = v7438->regs;
  int v7441 = v7440[29];
  v7439[29] = v7441;
  int v7443 = v7438->timer;
  int v7455 = v7443 + 1;
  v7438->timer = v7455;
  int * v7445 = v7438->regs;
  int v7446 = v7445[29];
  int v7447 = v7445[21];
  int v7458 = v7446 ^ v7447;
  v7445[29] = v7458;
  struct StateT * v7449 = slot_111(v7438);
  return v7449;
}

struct StateT * slot_208(struct StateT * v11275) {
  int v11276 = v11275->timer;
  int v11283 = v11276 + 1;
  v11275->timer = v11283;
  int * v11278 = v11275->regs;
  int v11279 = v11278[20];
  int v11287 = (int)((unsigned int)v11279 >> 25);
  v11278[24] = v11287;
  struct StateT * v11281 = slot_210(v11275);
  return v11281;
}

struct StateT * slot_301(struct StateT * v15568) {
  int v15569 = v15568->timer;
  int v15576 = v15569 + 1;
  v15568->timer = v15576;
  int * v15571 = v15568->regs;
  int v15572 = v15571[20];
  int v15580 = (int)((unsigned int)v15572 >> 25);
  v15571[24] = v15580;
  struct StateT * v15574 = slot_302(v15568);
  return v15574;
}

struct StateT * slot_502(struct StateT * v18840) {
  int v18841 = v18840->timer;
  int v18849 = v18841 + 1;
  v18840->timer = v18849;
  int * v18843 = v18840->regs;
  int v18844 = v18843[7];
  int v18845 = v18843[16];
  int v18854 = v18844 + v18845;
  v18843[23] = v18854;
  struct StateT * v18847 = slot_503(v18840);
  return v18847;
}

struct StateT * slot_506(struct StateT * v18902) {
  int v18903 = v18902->timer;
  int v18910 = v18903 + 1;
  v18902->timer = v18910;
  int * v18905 = v18902->regs;
  int v18906 = v18905[21];
  int v18914 = (int)((unsigned int)v18906 >> 19);
  v18905[24] = v18914;
  struct StateT * v18908 = slot_507(v18902);
  return v18908;
}

struct StateT * slot_413(struct StateT * v17363) {
  int v17364 = v17363->timer;
  int v17371 = v17364 + 1;
  v17363->timer = v17371;
  int * v17366 = v17363->regs;
  int v17367 = v17366[23];
  int v17374 = v17367 << 9;
  v17366[23] = v17374;
  struct StateT * v17369 = slot_414(v17363);
  return v17369;
}

struct StateT * slot_320(struct StateT * v15863) {
  int v15864 = v15863->timer;
  int v15872 = v15864 + 1;
  v15863->timer = v15872;
  int * v15866 = v15863->regs;
  int v15867 = v15866[16];
  int v15868 = v15866[31];
  int v15877 = v15867 + v15868;
  v15866[23] = v15877;
  struct StateT * v15870 = slot_321(v15863);
  return v15870;
}

struct StateT * slot_281(struct StateT * v15256) {
  int v15257 = v15256->timer;
  int v15264 = v15257 + 1;
  v15256->timer = v15264;
  int * v15259 = v15256->regs;
  int v15260 = v15259[20];
  int v15268 = (int)((unsigned int)v15260 >> 14);
  v15259[24] = v15268;
  struct StateT * v15262 = slot_282(v15256);
  return v15262;
}

struct StateT * slot_533(struct StateT * v19319) {
  int v19320 = v19319->timer;
  int v19327 = v19320 + 1;
  v19319->timer = v19327;
  int * v19322 = v19319->regs;
  int v19323 = v19322[23];
  int v19330 = v19323 << 18;
  v19322[23] = v19330;
  struct StateT * v19325 = slot_534(v19319);
  return v19325;
}

struct StateT * slot_203(struct StateT * v10296) {
  int v10297 = v10296->timer;
  int v10467 = v10297 + 1;
  v10296->timer = v10467;
  int * v10299 = v10296->regs;
  int v10300 = v10299[10];
  int v10301 = v10299[12];
  int * v10302 = v10296->cache_tags;
  int v10472 = (((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2;
  int v10303 = v10302[v10472];
  int v10473 = ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10304 = v10302[v10473];
  int v10474 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2);
  int v10305 = v10302[v10474];
  int v10475 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10306 = v10302[v10475];
  int v10307 = v10296->timer;
  int v10476 = v10307 + ((100 ^ (((~(((v10305 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10305 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10303 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10303 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10304 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10304 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10305 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10305 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10296->timer = v10476;
  bool v10477 = !(((~(((v10303 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10303 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10304 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10304 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v10401;
  if (v10477) {
    int * v10309 = v10296->cache_age;
    int v10479 = ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v10304 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10304 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v10310 = v10309[v10479];
    int v10311 = v10309[v10472];
    int v10480 = v10311 + ((int)((unsigned int)(v10311 - v10310) >> 31));
    v10309[v10472] = v10480;
    int * v10313 = v10296->cache_age;
    int v10314 = v10313[v10473];
    int v10482 = v10314 + ((int)((unsigned int)(v10314 - v10310) >> 31));
    v10313[v10473] = v10482;
    int * v10316 = v10296->cache_age;
    v10316[v10479] = 0;
    v10401 = v10479;
  } else {
    int * v10319 = v10296->cache_age;
    int v10486 = (((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2;
    int v10320 = v10319[v10486];
    int * v10321 = v10296->cache_tags;
    int v10322 = v10321[v10486];
    int v10323 = v10319[v10473];
    int v10324 = v10321[v10473];
    bool v10488 = !(((~(((v10305 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10305 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v10378;
    if (v10488) {
      int * v10325 = v10296->cache_age;
      int v10490 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10306 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v10326 = v10325[v10490];
      int v10327 = v10325[v10474];
      int v10491 = v10327 + ((int)((unsigned int)(v10327 - v10326) >> 31));
      v10325[v10474] = v10491;
      int * v10329 = v10296->cache_age;
      int v10330 = v10329[v10475];
      int v10493 = v10330 + ((int)((unsigned int)(v10330 - v10326) >> 31));
      v10329[v10475] = v10493;
      int * v10332 = v10296->cache_age;
      v10332[v10490] = 0;
      v10378 = v10490;
    } else {
      int * v10335 = v10296->cache_age;
      int v10497 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2);
      int v10336 = v10335[v10497];
      int * v10337 = v10296->cache_tags;
      int v10338 = v10337[v10497];
      int v10339 = v10335[v10475];
      int v10340 = v10337[v10475];
      int * v10341 = v10296->cache_dirty;
      int v10500 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10336 + ((~(((v10338 ^ -1) | (-(v10338 ^ -1))) >> 31)) & 2)) - (v10339 + ((~(((v10340 ^ -1) | (-(v10340 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10342 = v10341[v10500];
      bool v10501 = !(v10342 == 0);
      if (v10501) {
        int * v10343 = v10296->cache_tags;
        int v10344 = v10343[v10500];
        int * v10345 = v10296->cache_vals;
        int v10504 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10336 + ((~(((v10338 ^ -1) | (-(v10338 ^ -1))) >> 31)) & 2)) - (v10339 + ((~(((v10340 ^ -1) | (-(v10340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10346 = v10345[v10504];
        int v10505 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10336 + ((~(((v10338 ^ -1) | (-(v10338 ^ -1))) >> 31)) & 2)) - (v10339 + ((~(((v10340 ^ -1) | (-(v10340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10347 = v10345[v10505];
        int * v10348 = v10296->mem;
        int v10507 = v10344 * 2;
        v10348[v10507] = v10346;
        int * v10350 = v10296->mem;
        int v10510 = (v10344 * 2) + 1;
        v10350[v10510] = v10347;
        ;
      } else {
        ;
      }
      int * v10355 = v10296->mem;
      int v10515 = ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) * 2;
      int v10356 = v10355[v10515];
      int v10516 = (((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) * 2) + 1;
      int v10357 = v10355[v10516];
      int * v10358 = v10296->cache_vals;
      int v10518 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10336 + ((~(((v10338 ^ -1) | (-(v10338 ^ -1))) >> 31)) & 2)) - (v10339 + ((~(((v10340 ^ -1) | (-(v10340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10358[v10518] = v10356;
      int * v10360 = v10296->cache_vals;
      int v10521 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10336 + ((~(((v10338 ^ -1) | (-(v10338 ^ -1))) >> 31)) & 2)) - (v10339 + ((~(((v10340 ^ -1) | (-(v10340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10360[v10521] = v10357;
      int * v10362 = v10296->cache_tags;
      int v10524 = (int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1);
      v10362[v10500] = v10524;
      int * v10364 = v10296->cache_dirty;
      v10364[v10500] = 0;
      int * v10366 = v10296->cache_age;
      v10366[v10500] = 1;
      int * v10368 = v10296->cache_age;
      int v10369 = v10368[v10500];
      int v10370 = v10368[v10474];
      int v10530 = v10370 + ((int)((unsigned int)(v10370 - v10369) >> 31));
      v10368[v10474] = v10530;
      int * v10372 = v10296->cache_age;
      int v10373 = v10372[v10475];
      int v10532 = v10373 + ((int)((unsigned int)(v10373 - v10369) >> 31));
      v10372[v10475] = v10532;
      int * v10375 = v10296->cache_age;
      v10375[v10500] = 0;
      v10378 = v10500;
    }
    int * v10379 = v10296->cache_vals;
    int v10535 = v10378 * 2;
    int v10380 = v10379[v10535];
    int v10536 = (v10378 * 2) + 1;
    int v10381 = v10379[v10536];
    int v10537 = (((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10320 + ((~(((v10322 ^ -1) | (-(v10322 ^ -1))) >> 31)) & 2)) - (v10323 + ((~(((v10324 ^ -1) | (-(v10324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10379[v10537] = v10380;
    int * v10383 = v10296->cache_vals;
    int v10540 = ((((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10320 + ((~(((v10322 ^ -1) | (-(v10322 ^ -1))) >> 31)) & 2)) - (v10323 + ((~(((v10324 ^ -1) | (-(v10324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10383[v10540] = v10381;
    int * v10385 = v10296->cache_tags;
    int v10543 = ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v10320 + ((~(((v10322 ^ -1) | (-(v10322 ^ -1))) >> 31)) & 2)) - (v10323 + ((~(((v10324 ^ -1) | (-(v10324 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10544 = (int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1);
    v10385[v10543] = v10544;
    int * v10387 = v10296->cache_dirty;
    v10387[v10543] = 0;
    int * v10389 = v10296->cache_age;
    v10389[v10543] = 1;
    int * v10391 = v10296->cache_age;
    int v10392 = v10391[v10543];
    int v10393 = v10391[v10472];
    int v10550 = v10393 + ((int)((unsigned int)(v10393 - v10392) >> 31));
    v10391[v10472] = v10550;
    int * v10395 = v10296->cache_age;
    int v10396 = v10395[v10473];
    int v10552 = v10396 + ((int)((unsigned int)(v10396 - v10392) >> 31));
    v10395[v10473] = v10552;
    int * v10398 = v10296->cache_age;
    v10398[v10543] = 0;
    v10401 = v10543;
  }
  int * v10402 = v10296->cache_vals;
  int v10555 = (v10401 * 2) + (((int)((unsigned int)(v10300 + 16) >> 2)) & 1);
  v10402[v10555] = v10301;
  int * v10404 = v10296->cache_tags;
  int v10405 = v10404[v10474];
  int v10406 = v10404[v10475];
  bool v10558 = !(((~(((v10405 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10405 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v10406 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10406 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v10460;
  if (v10558) {
    int * v10407 = v10296->cache_age;
    int v10560 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10406 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))) | (-(v10406 ^ ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v10408 = v10407[v10560];
    int v10409 = v10407[v10474];
    int v10561 = v10409 + ((int)((unsigned int)(v10409 - v10408) >> 31));
    v10407[v10474] = v10561;
    int * v10411 = v10296->cache_age;
    int v10412 = v10411[v10475];
    int v10563 = v10412 + ((int)((unsigned int)(v10412 - v10408) >> 31));
    v10411[v10475] = v10563;
    int * v10414 = v10296->cache_age;
    v10414[v10560] = 0;
    v10460 = v10560;
  } else {
    int * v10417 = v10296->cache_age;
    int v10567 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2);
    int v10418 = v10417[v10567];
    int * v10419 = v10296->cache_tags;
    int v10420 = v10419[v10567];
    int v10421 = v10417[v10475];
    int v10422 = v10419[v10475];
    int * v10423 = v10296->cache_dirty;
    int v10570 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10418 + ((~(((v10420 ^ -1) | (-(v10420 ^ -1))) >> 31)) & 2)) - (v10421 + ((~(((v10422 ^ -1) | (-(v10422 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10424 = v10423[v10570];
    bool v10571 = !(v10424 == 0);
    if (v10571) {
      int * v10425 = v10296->cache_tags;
      int v10426 = v10425[v10570];
      int * v10427 = v10296->cache_vals;
      int v10574 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10418 + ((~(((v10420 ^ -1) | (-(v10420 ^ -1))) >> 31)) & 2)) - (v10421 + ((~(((v10422 ^ -1) | (-(v10422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10428 = v10427[v10574];
      int v10575 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10418 + ((~(((v10420 ^ -1) | (-(v10420 ^ -1))) >> 31)) & 2)) - (v10421 + ((~(((v10422 ^ -1) | (-(v10422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10429 = v10427[v10575];
      int * v10430 = v10296->mem;
      int v10577 = v10426 * 2;
      v10430[v10577] = v10428;
      int * v10432 = v10296->mem;
      int v10580 = (v10426 * 2) + 1;
      v10432[v10580] = v10429;
      ;
    } else {
      ;
    }
    int * v10437 = v10296->mem;
    int v10585 = ((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) * 2;
    int v10438 = v10437[v10585];
    int v10586 = (((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) * 2) + 1;
    int v10439 = v10437[v10586];
    int * v10440 = v10296->cache_vals;
    int v10588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10418 + ((~(((v10420 ^ -1) | (-(v10420 ^ -1))) >> 31)) & 2)) - (v10421 + ((~(((v10422 ^ -1) | (-(v10422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10440[v10588] = v10438;
    int * v10442 = v10296->cache_vals;
    int v10591 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v10418 + ((~(((v10420 ^ -1) | (-(v10420 ^ -1))) >> 31)) & 2)) - (v10421 + ((~(((v10422 ^ -1) | (-(v10422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10442[v10591] = v10439;
    int * v10444 = v10296->cache_tags;
    int v10594 = (int)((unsigned int)((int)((unsigned int)(v10300 + 16) >> 2)) >> 1);
    v10444[v10570] = v10594;
    int * v10446 = v10296->cache_dirty;
    v10446[v10570] = 0;
    int * v10448 = v10296->cache_age;
    v10448[v10570] = 1;
    int * v10450 = v10296->cache_age;
    int v10451 = v10450[v10570];
    int v10452 = v10450[v10474];
    int v10600 = v10452 + ((int)((unsigned int)(v10452 - v10451) >> 31));
    v10450[v10474] = v10600;
    int * v10454 = v10296->cache_age;
    int v10455 = v10454[v10475];
    int v10602 = v10455 + ((int)((unsigned int)(v10455 - v10451) >> 31));
    v10454[v10475] = v10602;
    int * v10457 = v10296->cache_age;
    v10457[v10570] = 0;
    v10460 = v10570;
  }
  int * v10461 = v10296->cache_vals;
  int v10605 = (v10460 * 2) + (((int)((unsigned int)(v10300 + 16) >> 2)) & 1);
  v10461[v10605] = v10301;
  int * v10463 = v10296->cache_dirty;
  v10463[v10460] = 1;
  struct StateT * v10465 = slot_205(v10296);
  return v10465;
}

struct StateT * slot_190(struct StateT * v8707) {
  int v8708 = v8707->timer;
  int v8716 = v8708 + 1;
  v8707->timer = v8716;
  int * v8710 = v8707->regs;
  int v8711 = v8710[29];
  int v8712 = v8710[21];
  int v8720 = v8711 ^ v8712;
  v8710[29] = v8720;
  struct StateT * v8714 = slot_191(v8707);
  return v8714;
}

struct StateT * slot_157(struct StateT * v8199) {
  int v8200 = v8199->timer;
  int v8207 = v8200 + 1;
  v8199->timer = v8207;
  int * v8202 = v8199->regs;
  int v8203 = v8202[20];
  int v8211 = (int)((unsigned int)v8203 >> 19);
  v8202[24] = v8211;
  struct StateT * v8205 = slot_158(v8199);
  return v8205;
}

struct StateT * slot_447(struct StateT * v17953) {
  int v17954 = v17953->timer;
  int v17961 = v17954 + 1;
  v17953->timer = v17961;
  int * v17956 = v17953->regs;
  int v17957 = v17956[21];
  int v17964 = v17957 << 18;
  v17956[21] = v17964;
  struct StateT * v17959 = slot_448(v17953);
  return v17959;
}

struct StateT * slot_243(struct StateT * v14661) {
  int v14662 = v14661->timer;
  int v14670 = v14662 + 1;
  v14661->timer = v14670;
  int * v14664 = v14661->regs;
  int v14665 = v14664[20];
  int v14666 = v14664[24];
  int v14674 = v14665 | v14666;
  v14664[20] = v14674;
  struct StateT * v14668 = slot_244(v14661);
  return v14668;
}

struct StateT * slot_173(struct StateT * v8443) {
  int v8444 = v8443->timer;
  int v8452 = v8444 + 1;
  v8443->timer = v8452;
  int * v8446 = v8443->regs;
  int v8447 = v8446[8];
  int v8448 = v8446[17];
  int v8457 = v8447 + v8448;
  v8446[20] = v8457;
  struct StateT * v8450 = slot_174(v8443);
  return v8450;
}

struct StateT * slot_307(struct StateT * v15658) {
  int v15659 = v15658->timer;
  int v15666 = v15659 + 1;
  v15658->timer = v15666;
  int * v15661 = v15658->regs;
  int v15662 = v15661[22];
  int v15670 = (int)((unsigned int)v15662 >> 25);
  v15661[24] = v15670;
  struct StateT * v15664 = slot_308(v15658);
  return v15664;
}

struct StateT * slot_453(struct StateT * v18043) {
  int v18044 = v18043->timer;
  int v18051 = v18044 + 1;
  v18043->timer = v18051;
  int * v18046 = v18043->regs;
  int v18047 = v18046[23];
  int v18054 = v18047 << 18;
  v18046[23] = v18054;
  struct StateT * v18049 = slot_454(v18043);
  return v18049;
}

struct StateT * slot_54(struct StateT * v6504) {
  int v6505 = v6504->timer;
  int v6513 = v6505 + 1;
  v6504->timer = v6513;
  int * v6507 = v6504->regs;
  int v6508 = v6507[18];
  int v6509 = v6507[29];
  int v6518 = v6508 + v6509;
  v6507[21] = v6518;
  struct StateT * v6511 = slot_55(v6504);
  return v6511;
}

struct StateT * slot_26(struct StateT * v6019) {
  int v6020 = v6019->timer;
  int v6027 = v6020 + 1;
  v6019->timer = v6027;
  int * v6022 = v6019->regs;
  int v6023 = v6022[11];
  int v6031 = v6023 + -1947;
  v6022[30] = v6031;
  struct StateT * v6025 = slot_27(v6019);
  return v6025;
}

struct StateT * slot_370(struct StateT * v16639) {
  int v16640 = v16639->timer;
  int v16647 = v16640 + 1;
  v16639->timer = v16647;
  int * v16642 = v16639->regs;
  int v16643 = v16642[23];
  int v16651 = (int)((unsigned int)v16643 >> 14);
  v16642[24] = v16651;
  struct StateT * v16645 = slot_371(v16639);
  return v16645;
}

struct StateT * slot_206(struct StateT * v10943) {
  int v10944 = v10943->timer;
  int v10952 = v10944 + 1;
  v10943->timer = v10952;
  int * v10946 = v10943->regs;
  int v10947 = v10946[31];
  int v10948 = v10946[15];
  int v10957 = v10947 + v10948;
  v10946[23] = v10957;
  struct StateT * v10950 = slot_208(v10943);
  return v10950;
}

struct StateT * slot_227(struct StateT * v14434) {
  int v14435 = v14434->timer;
  int v14438 = v14435 + 1;
  v14434->timer = v14438;
  return v14434;
}

struct StateT * slot_169(struct StateT * v8379) {
  int v8380 = v8379->timer;
  int v8388 = v8380 + 1;
  v8379->timer = v8388;
  int * v8382 = v8379->regs;
  int v8383 = v8382[8];
  int v8384 = v8382[20];
  int v8392 = v8383 ^ v8384;
  v8382[8] = v8392;
  struct StateT * v8386 = slot_170(v8379);
  return v8386;
}

struct StateT * slot_442(struct StateT * v17876) {
  int v17877 = v17876->timer;
  int v17885 = v17877 + 1;
  v17876->timer = v17885;
  int * v17879 = v17876->regs;
  int v17880 = v17879[15];
  int v17881 = v17879[5];
  int v17890 = v17880 + v17881;
  v17879[23] = v17890;
  struct StateT * v17883 = slot_443(v17876);
  return v17883;
}

struct StateT * slot_529(struct StateT * v19259) {
  int v19260 = v19259->timer;
  int v19267 = v19260 + 1;
  v19259->timer = v19267;
  int * v19262 = v19259->regs;
  int v19263 = v19262[22];
  int v19271 = (int)((unsigned int)v19263 >> 14);
  v19262[24] = v19271;
  struct StateT * v19265 = slot_530(v19259);
  return v19265;
}

struct StateT * slot_14(struct StateT * v3532) {
  int v3533 = v3532->timer;
  int v3643 = v3533 + 1;
  v3532->timer = v3643;
  int * v3535 = v3532->regs;
  int v3536 = v3535[12];
  int * v3537 = v3532->cache_tags;
  int v3647 = (((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2;
  int v3538 = v3537[v3647];
  int v3648 = ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3539 = v3537[v3648];
  int v3649 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2);
  int v3540 = v3537[v3649];
  int v3650 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3541 = v3537[v3650];
  int v3542 = v3532->timer;
  int v3651 = v3542 + ((100 ^ (((~(((v3540 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3540 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3538 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3538 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3539 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3539 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3540 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3540 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3532->timer = v3651;
  int * v3544 = v3532->cache_vals;
  bool v3652 = !(((~(((v3538 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3538 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3539 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3539 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3637;
  if (v3652) {
    int * v3545 = v3532->cache_age;
    int v3654 = ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v3539 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3539 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3546 = v3545[v3654];
    int v3547 = v3545[v3647];
    int v3655 = v3547 + ((int)((unsigned int)(v3547 - v3546) >> 31));
    v3545[v3647] = v3655;
    int * v3549 = v3532->cache_age;
    int v3550 = v3549[v3648];
    int v3657 = v3550 + ((int)((unsigned int)(v3550 - v3546) >> 31));
    v3549[v3648] = v3657;
    int * v3552 = v3532->cache_age;
    v3552[v3654] = 0;
    v3637 = v3654;
  } else {
    int * v3555 = v3532->cache_age;
    int v3661 = (((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2;
    int v3556 = v3555[v3661];
    int * v3557 = v3532->cache_tags;
    int v3558 = v3557[v3661];
    int v3559 = v3555[v3648];
    int v3560 = v3557[v3648];
    bool v3663 = !(((~(((v3540 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3540 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3614;
    if (v3663) {
      int * v3561 = v3532->cache_age;
      int v3665 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))) | (-(v3541 ^ ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v3562 = v3561[v3665];
      int v3563 = v3561[v3649];
      int v3666 = v3563 + ((int)((unsigned int)(v3563 - v3562) >> 31));
      v3561[v3649] = v3666;
      int * v3565 = v3532->cache_age;
      int v3566 = v3565[v3650];
      int v3668 = v3566 + ((int)((unsigned int)(v3566 - v3562) >> 31));
      v3565[v3650] = v3668;
      int * v3568 = v3532->cache_age;
      v3568[v3665] = 0;
      v3614 = v3665;
    } else {
      int * v3571 = v3532->cache_age;
      int v3672 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3572 = v3571[v3672];
      int * v3573 = v3532->cache_tags;
      int v3574 = v3573[v3672];
      int v3575 = v3571[v3650];
      int v3576 = v3573[v3650];
      int * v3577 = v3532->cache_dirty;
      int v3675 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3572 + ((~(((v3574 ^ -1) | (-(v3574 ^ -1))) >> 31)) & 2)) - (v3575 + ((~(((v3576 ^ -1) | (-(v3576 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3578 = v3577[v3675];
      bool v3676 = !(v3578 == 0);
      if (v3676) {
        int * v3579 = v3532->cache_tags;
        int v3580 = v3579[v3675];
        int * v3581 = v3532->cache_vals;
        int v3679 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3572 + ((~(((v3574 ^ -1) | (-(v3574 ^ -1))) >> 31)) & 2)) - (v3575 + ((~(((v3576 ^ -1) | (-(v3576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3582 = v3581[v3679];
        int v3680 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3572 + ((~(((v3574 ^ -1) | (-(v3574 ^ -1))) >> 31)) & 2)) - (v3575 + ((~(((v3576 ^ -1) | (-(v3576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3583 = v3581[v3680];
        int * v3584 = v3532->mem;
        int v3682 = v3580 * 2;
        v3584[v3682] = v3582;
        int * v3586 = v3532->mem;
        int v3685 = (v3580 * 2) + 1;
        v3586[v3685] = v3583;
        ;
      } else {
        ;
      }
      int * v3591 = v3532->mem;
      int v3690 = ((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) * 2;
      int v3592 = v3591[v3690];
      int v3691 = (((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3593 = v3591[v3691];
      int * v3594 = v3532->cache_vals;
      int v3693 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3572 + ((~(((v3574 ^ -1) | (-(v3574 ^ -1))) >> 31)) & 2)) - (v3575 + ((~(((v3576 ^ -1) | (-(v3576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3594[v3693] = v3592;
      int * v3596 = v3532->cache_vals;
      int v3696 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3572 + ((~(((v3574 ^ -1) | (-(v3574 ^ -1))) >> 31)) & 2)) - (v3575 + ((~(((v3576 ^ -1) | (-(v3576 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3596[v3696] = v3593;
      int * v3598 = v3532->cache_tags;
      int v3699 = (int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1);
      v3598[v3675] = v3699;
      int * v3600 = v3532->cache_dirty;
      v3600[v3675] = 0;
      int * v3602 = v3532->cache_age;
      v3602[v3675] = 1;
      int * v3604 = v3532->cache_age;
      int v3605 = v3604[v3675];
      int v3606 = v3604[v3649];
      int v3705 = v3606 + ((int)((unsigned int)(v3606 - v3605) >> 31));
      v3604[v3649] = v3705;
      int * v3608 = v3532->cache_age;
      int v3609 = v3608[v3650];
      int v3707 = v3609 + ((int)((unsigned int)(v3609 - v3605) >> 31));
      v3608[v3650] = v3707;
      int * v3611 = v3532->cache_age;
      v3611[v3675] = 0;
      v3614 = v3675;
    }
    int * v3615 = v3532->cache_vals;
    int v3710 = v3614 * 2;
    int v3616 = v3615[v3710];
    int v3711 = (v3614 * 2) + 1;
    int v3617 = v3615[v3711];
    int v3712 = (((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3556 + ((~(((v3558 ^ -1) | (-(v3558 ^ -1))) >> 31)) & 2)) - (v3559 + ((~(((v3560 ^ -1) | (-(v3560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3615[v3712] = v3616;
    int * v3619 = v3532->cache_vals;
    int v3715 = ((((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3556 + ((~(((v3558 ^ -1) | (-(v3558 ^ -1))) >> 31)) & 2)) - (v3559 + ((~(((v3560 ^ -1) | (-(v3560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3619[v3715] = v3617;
    int * v3621 = v3532->cache_tags;
    int v3718 = ((((int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3556 + ((~(((v3558 ^ -1) | (-(v3558 ^ -1))) >> 31)) & 2)) - (v3559 + ((~(((v3560 ^ -1) | (-(v3560 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3719 = (int)((unsigned int)((int)((unsigned int)(v3536 + 12) >> 2)) >> 1);
    v3621[v3718] = v3719;
    int * v3623 = v3532->cache_dirty;
    v3623[v3718] = 0;
    int * v3625 = v3532->cache_age;
    v3625[v3718] = 1;
    int * v3627 = v3532->cache_age;
    int v3628 = v3627[v3718];
    int v3629 = v3627[v3647];
    int v3725 = v3629 + ((int)((unsigned int)(v3629 - v3628) >> 31));
    v3627[v3647] = v3725;
    int * v3631 = v3532->cache_age;
    int v3632 = v3631[v3648];
    int v3727 = v3632 + ((int)((unsigned int)(v3632 - v3628) >> 31));
    v3631[v3648] = v3727;
    int * v3634 = v3532->cache_age;
    v3634[v3718] = 0;
    v3637 = v3718;
  }
  int v3730 = (v3637 * 2) + (((int)((unsigned int)(v3536 + 12) >> 2)) & 1);
  int v3638 = v3544[v3730];
  int * v3639 = v3532->regs;
  v3639[9] = v3638;
  struct StateT * v3641 = slot_15(v3532);
  return v3641;
}

struct StateT * slot_357(struct StateT * v16436) {
  int v16437 = v16436->timer;
  int v16445 = v16437 + 1;
  v16436->timer = v16445;
  int * v16439 = v16436->regs;
  int v16440 = v16439[8];
  int v16441 = v16439[17];
  int v16450 = v16440 + v16441;
  v16439[20] = v16450;
  struct StateT * v16443 = slot_358(v16436);
  return v16443;
}

struct StateT * slot_385(struct StateT * v16902) {
  int v16903 = v16902->timer;
  int v16911 = v16903 + 1;
  v16902->timer = v16911;
  int * v16905 = v16902->regs;
  int v16906 = v16905[20];
  int v16907 = v16905[24];
  int v16915 = v16906 | v16907;
  v16905[20] = v16915;
  struct StateT * v16909 = slot_386(v16902);
  return v16909;
}

struct StateT * slot_444(struct StateT * v17908) {
  int v17909 = v17908->timer;
  int v17916 = v17909 + 1;
  v17908->timer = v17916;
  int * v17911 = v17908->regs;
  int v17912 = v17911[20];
  int v17919 = v17912 << 18;
  v17911[20] = v17919;
  struct StateT * v17914 = slot_445(v17908);
  return v17914;
}

struct StateT * slot_261(struct StateT * v14944) {
  int v14945 = v14944->timer;
  int v14952 = v14945 + 1;
  v14944->timer = v14952;
  int * v14947 = v14944->regs;
  int v14948 = v14947[20];
  int v14956 = (int)((unsigned int)v14948 >> 19);
  v14947[24] = v14956;
  struct StateT * v14950 = slot_262(v14944);
  return v14950;
}

struct StateT * slot_287(struct StateT * v15346) {
  int v15347 = v15346->timer;
  int v15354 = v15347 + 1;
  v15346->timer = v15354;
  int * v15349 = v15346->regs;
  int v15350 = v15349[22];
  int v15358 = (int)((unsigned int)v15350 >> 14);
  v15349[24] = v15358;
  struct StateT * v15352 = slot_288(v15346);
  return v15352;
}

struct StateT * slot_343(struct StateT * v16221) {
  int v16222 = v16221->timer;
  int v16230 = v16222 + 1;
  v16221->timer = v16230;
  int * v16224 = v16221->regs;
  int v16225 = v16224[20];
  int v16226 = v16224[24];
  int v16234 = v16225 | v16226;
  v16224[20] = v16234;
  struct StateT * v16228 = slot_344(v16221);
  return v16228;
}

struct StateT * slot_36(struct StateT * v6184) {
  int * v6185 = v6184->saved_regs;
  int * v6186 = v6184->regs;
  int v6187 = v6186[23];
  v6185[23] = v6187;
  int v6189 = v6184->timer;
  int v6201 = v6189 + 1;
  v6184->timer = v6201;
  int * v6191 = v6184->regs;
  int v6192 = v6191[31];
  int v6193 = v6191[15];
  int v6205 = v6192 + v6193;
  v6191[23] = v6205;
  struct StateT * v6195 = slot_37(v6184);
  return v6195;
}

struct StateT * slot_57(struct StateT * v6555) {
  int v6556 = v6555->timer;
  int v6563 = v6556 + 1;
  v6555->timer = v6563;
  int * v6558 = v6555->regs;
  int v6559 = v6558[20];
  int v6567 = (int)((unsigned int)v6559 >> 23);
  v6558[24] = v6567;
  struct StateT * v6561 = slot_58(v6555);
  return v6561;
}

struct StateT * slot_426(struct StateT * v17598) {
  int v17599 = v17598->timer;
  int v17606 = v17599 + 1;
  v17598->timer = v17606;
  int * v17601 = v17598->regs;
  int v17602 = v17601[21];
  int v17610 = (int)((unsigned int)v17602 >> 19);
  v17601[24] = v17610;
  struct StateT * v17604 = slot_427(v17598);
  return v17604;
}

struct StateT * slot_536(struct StateT * v19365) {
  int v19366 = v19365->timer;
  int v19374 = v19366 + 1;
  v19365->timer = v19374;
  int * v19368 = v19365->regs;
  int v19369 = v19368[29];
  int v19370 = v19368[21];
  int v19378 = v19369 ^ v19370;
  v19368[29] = v19378;
  struct StateT * v19372 = slot_537(v19365);
  return v19372;
}

struct StateT * slot_470(struct StateT * v18338) {
  int v18339 = v18338->timer;
  int v18346 = v18339 + 1;
  v18338->timer = v18346;
  int * v18341 = v18338->regs;
  int v18342 = v18341[22];
  int v18349 = v18342 << 7;
  v18341[22] = v18349;
  struct StateT * v18344 = slot_471(v18338);
  return v18344;
}

struct StateT * slot_431(struct StateT * v17672) {
  int v17673 = v17672->timer;
  int v17681 = v17673 + 1;
  v17672->timer = v17681;
  int * v17675 = v17672->regs;
  int v17676 = v17675[22];
  int v17677 = v17675[24];
  int v17685 = v17676 | v17677;
  v17675[22] = v17685;
  struct StateT * v17679 = slot_432(v17672);
  return v17679;
}

struct StateT * slot_62(struct StateT * v6629) {
  int v6630 = v6629->timer;
  int v6638 = v6630 + 1;
  v6629->timer = v6638;
  int * v6632 = v6629->regs;
  int v6633 = v6632[21];
  int v6634 = v6632[24];
  int v6642 = v6633 | v6634;
  v6632[21] = v6642;
  struct StateT * v6636 = slot_63(v6629);
  return v6636;
}

struct StateT * slot_308(struct StateT * v15673) {
  int v15674 = v15673->timer;
  int v15681 = v15674 + 1;
  v15673->timer = v15681;
  int * v15676 = v15673->regs;
  int v15677 = v15676[22];
  int v15684 = v15677 << 7;
  v15676[22] = v15684;
  struct StateT * v15679 = slot_309(v15673);
  return v15679;
}

struct StateT * slot_400(struct StateT * v17162) {
  int v17163 = v17162->timer;
  int v17171 = v17163 + 1;
  v17162->timer = v17171;
  int * v17165 = v17162->regs;
  int v17166 = v17165[18];
  int v17167 = v17165[29];
  int v17176 = v17166 + v17167;
  v17165[21] = v17176;
  struct StateT * v17169 = slot_401(v17162);
  return v17169;
}

struct StateT * slot_323(struct StateT * v15909) {
  int v15910 = v15909->timer;
  int v15918 = v15910 + 1;
  v15909->timer = v15918;
  int * v15912 = v15909->regs;
  int v15913 = v15912[20];
  int v15914 = v15912[24];
  int v15922 = v15913 | v15914;
  v15912[20] = v15922;
  struct StateT * v15916 = slot_324(v15909);
  return v15916;
}

struct StateT * slot_521(struct StateT * v19135) {
  int v19136 = v19135->timer;
  int v19144 = v19136 + 1;
  v19135->timer = v19144;
  int * v19138 = v19135->regs;
  int v19139 = v19138[18];
  int v19140 = v19138[6];
  int v19149 = v19139 + v19140;
  v19138[22] = v19149;
  struct StateT * v19142 = slot_522(v19135);
  return v19142;
}

struct StateT * slot_530(struct StateT * v19274) {
  int v19275 = v19274->timer;
  int v19282 = v19275 + 1;
  v19274->timer = v19282;
  int * v19277 = v19274->regs;
  int v19278 = v19277[22];
  int v19285 = v19278 << 18;
  v19277[22] = v19285;
  struct StateT * v19280 = slot_531(v19274);
  return v19280;
}

struct StateT * slot_23(struct StateT * v5980) {
  int v5981 = v5980->timer;
  int v5987 = v5981 + 1;
  v5980->timer = v5987;
  int * v5983 = v5980->regs;
  v5983[11] = 1634762752;
  struct StateT * v5985 = slot_24(v5980);
  return v5985;
}

struct StateT * slot_2(struct StateT * v331) {
  int v332 = v331->timer;
  int v502 = v332 + 1;
  v331->timer = v502;
  int * v334 = v331->regs;
  int v335 = v334[2];
  int v336 = v334[9];
  int * v337 = v331->cache_tags;
  int v507 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v507];
  int v508 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v508];
  int v509 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v509];
  int v510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v510];
  int v342 = v331->timer;
  int v511 = v342 + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v331->timer = v511;
  bool v512 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v436;
  if (v512) {
    int * v344 = v331->cache_age;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v521 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2;
    int v355 = v354[v521];
    int * v356 = v331->cache_tags;
    int v357 = v356[v521];
    int v358 = v354[v508];
    int v359 = v356[v508];
    bool v523 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v413;
    if (v523) {
      int * v360 = v331->cache_age;
      int v525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) & 1);
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
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2);
      int v371 = v370[v532];
      int * v372 = v331->cache_tags;
      int v373 = v372[v532];
      int v374 = v370[v510];
      int v375 = v372[v510];
      int * v376 = v331->cache_dirty;
      int v535 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v377 = v376[v535];
      bool v536 = !(v377 == 0);
      if (v536) {
        int * v378 = v331->cache_tags;
        int v379 = v378[v535];
        int * v380 = v331->cache_vals;
        int v539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v381 = v380[v539];
        int v540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v550 = ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2;
      int v391 = v390[v550];
      int v551 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2) + 1;
      int v392 = v390[v551];
      int * v393 = v331->cache_vals;
      int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v393[v553] = v391;
      int * v395 = v331->cache_vals;
      int v556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v395[v556] = v392;
      int * v397 = v331->cache_tags;
      int v559 = (int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1);
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
    int v572 = (((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v414[v572] = v415;
    int * v418 = v331->cache_vals;
    int v575 = ((((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v418[v575] = v416;
    int * v420 = v331->cache_tags;
    int v578 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v579 = (int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1);
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
  int v590 = (v436 * 2) + (((int)((unsigned int)(v335 + 40) >> 2)) & 1);
  v437[v590] = v336;
  int * v439 = v331->cache_tags;
  int v440 = v439[v509];
  int v441 = v439[v510];
  bool v593 = !(((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v495;
  if (v593) {
    int * v442 = v331->cache_age;
    int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v602 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2);
    int v453 = v452[v602];
    int * v454 = v331->cache_tags;
    int v455 = v454[v602];
    int v456 = v452[v510];
    int v457 = v454[v510];
    int * v458 = v331->cache_dirty;
    int v605 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v459 = v458[v605];
    bool v606 = !(v459 == 0);
    if (v606) {
      int * v460 = v331->cache_tags;
      int v461 = v460[v605];
      int * v462 = v331->cache_vals;
      int v609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v463 = v462[v609];
      int v610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
    int v620 = ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2;
    int v473 = v472[v620];
    int v621 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2) + 1;
    int v474 = v472[v621];
    int * v475 = v331->cache_vals;
    int v623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v475[v623] = v473;
    int * v477 = v331->cache_vals;
    int v626 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v477[v626] = v474;
    int * v479 = v331->cache_tags;
    int v629 = (int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1);
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
  int v640 = (v495 * 2) + (((int)((unsigned int)(v335 + 40) >> 2)) & 1);
  v496[v640] = v336;
  int * v498 = v331->cache_dirty;
  v498[v495] = 1;
  struct StateT * v500 = slot_3(v331);
  return v500;
}

struct StateT * slot_86(struct StateT * v7030) {
  int v7031 = v7030->timer;
  int v7038 = v7031 + 1;
  v7030->timer = v7038;
  int * v7033 = v7030->regs;
  int v7034 = v7033[23];
  int v7042 = (int)((unsigned int)v7034 >> 19);
  v7033[24] = v7042;
  struct StateT * v7036 = slot_87(v7030);
  return v7036;
}

struct StateT * slot_538(struct StateT * v19397) {
  int v19398 = v19397->timer;
  int v19406 = v19398 + 1;
  v19397->timer = v19406;
  int * v19400 = v19397->regs;
  int v19401 = v19400[31];
  int v19402 = v19400[23];
  int v19410 = v19401 ^ v19402;
  v19400[31] = v19410;
  struct StateT * v19404 = slot_539(v19397);
  return v19404;
}

struct StateT * slot_100(struct StateT * v7280) {
  int v7281 = v7280->timer;
  int v7288 = v7281 + 1;
  v7280->timer = v7288;
  int * v7283 = v7280->regs;
  int v7284 = v7283[21];
  int v7292 = (int)((unsigned int)v7284 >> 14);
  v7283[24] = v7292;
  struct StateT * v7286 = slot_101(v7280);
  return v7286;
}

struct StateT * slot_127(struct StateT * v7725) {
  int v7726 = v7725->timer;
  int v7733 = v7726 + 1;
  v7725->timer = v7733;
  int * v7728 = v7725->regs;
  int v7729 = v7728[23];
  int v7736 = v7729 << 7;
  v7728[23] = v7736;
  struct StateT * v7731 = slot_128(v7725);
  return v7731;
}

struct StateT * slot_411(struct StateT * v17332) {
  int v17333 = v17332->timer;
  int v17341 = v17333 + 1;
  v17332->timer = v17341;
  int * v17335 = v17332->regs;
  int v17336 = v17335[22];
  int v17337 = v17335[24];
  int v17345 = v17336 | v17337;
  v17335[22] = v17345;
  struct StateT * v17339 = slot_412(v17332);
  return v17339;
}

struct StateT * slot_13(struct StateT * v4552) {
  int v4553 = v4552->timer;
  int v4663 = v4553 + 1;
  v4552->timer = v4663;
  int * v4555 = v4552->regs;
  int v4556 = v4555[12];
  int * v4557 = v4552->cache_tags;
  int v4667 = (((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2;
  int v4558 = v4557[v4667];
  int v4668 = ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4559 = v4557[v4668];
  int v4669 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2);
  int v4560 = v4557[v4669];
  int v4670 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4561 = v4557[v4670];
  int v4562 = v4552->timer;
  int v4671 = v4562 + ((100 ^ (((~(((v4560 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4560 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4558 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4558 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4559 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4559 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4560 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4560 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4552->timer = v4671;
  int * v4564 = v4552->cache_vals;
  bool v4672 = !(((~(((v4558 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4558 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4559 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4559 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v4657;
  if (v4672) {
    int * v4565 = v4552->cache_age;
    int v4674 = ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v4559 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4559 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4566 = v4565[v4674];
    int v4567 = v4565[v4667];
    int v4675 = v4567 + ((int)((unsigned int)(v4567 - v4566) >> 31));
    v4565[v4667] = v4675;
    int * v4569 = v4552->cache_age;
    int v4570 = v4569[v4668];
    int v4677 = v4570 + ((int)((unsigned int)(v4570 - v4566) >> 31));
    v4569[v4668] = v4677;
    int * v4572 = v4552->cache_age;
    v4572[v4674] = 0;
    v4657 = v4674;
  } else {
    int * v4575 = v4552->cache_age;
    int v4681 = (((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2;
    int v4576 = v4575[v4681];
    int * v4577 = v4552->cache_tags;
    int v4578 = v4577[v4681];
    int v4579 = v4575[v4668];
    int v4580 = v4577[v4668];
    bool v4683 = !(((~(((v4560 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4560 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v4634;
    if (v4683) {
      int * v4581 = v4552->cache_age;
      int v4685 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))) | (-(v4561 ^ ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v4582 = v4581[v4685];
      int v4583 = v4581[v4669];
      int v4686 = v4583 + ((int)((unsigned int)(v4583 - v4582) >> 31));
      v4581[v4669] = v4686;
      int * v4585 = v4552->cache_age;
      int v4586 = v4585[v4670];
      int v4688 = v4586 + ((int)((unsigned int)(v4586 - v4582) >> 31));
      v4585[v4670] = v4688;
      int * v4588 = v4552->cache_age;
      v4588[v4685] = 0;
      v4634 = v4685;
    } else {
      int * v4591 = v4552->cache_age;
      int v4692 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2);
      int v4592 = v4591[v4692];
      int * v4593 = v4552->cache_tags;
      int v4594 = v4593[v4692];
      int v4595 = v4591[v4670];
      int v4596 = v4593[v4670];
      int * v4597 = v4552->cache_dirty;
      int v4695 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4592 + ((~(((v4594 ^ -1) | (-(v4594 ^ -1))) >> 31)) & 2)) - (v4595 + ((~(((v4596 ^ -1) | (-(v4596 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4598 = v4597[v4695];
      bool v4696 = !(v4598 == 0);
      if (v4696) {
        int * v4599 = v4552->cache_tags;
        int v4600 = v4599[v4695];
        int * v4601 = v4552->cache_vals;
        int v4699 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4592 + ((~(((v4594 ^ -1) | (-(v4594 ^ -1))) >> 31)) & 2)) - (v4595 + ((~(((v4596 ^ -1) | (-(v4596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4602 = v4601[v4699];
        int v4700 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4592 + ((~(((v4594 ^ -1) | (-(v4594 ^ -1))) >> 31)) & 2)) - (v4595 + ((~(((v4596 ^ -1) | (-(v4596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4603 = v4601[v4700];
        int * v4604 = v4552->mem;
        int v4702 = v4600 * 2;
        v4604[v4702] = v4602;
        int * v4606 = v4552->mem;
        int v4705 = (v4600 * 2) + 1;
        v4606[v4705] = v4603;
        ;
      } else {
        ;
      }
      int * v4611 = v4552->mem;
      int v4710 = ((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) * 2;
      int v4612 = v4611[v4710];
      int v4711 = (((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) * 2) + 1;
      int v4613 = v4611[v4711];
      int * v4614 = v4552->cache_vals;
      int v4713 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4592 + ((~(((v4594 ^ -1) | (-(v4594 ^ -1))) >> 31)) & 2)) - (v4595 + ((~(((v4596 ^ -1) | (-(v4596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4614[v4713] = v4612;
      int * v4616 = v4552->cache_vals;
      int v4716 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4592 + ((~(((v4594 ^ -1) | (-(v4594 ^ -1))) >> 31)) & 2)) - (v4595 + ((~(((v4596 ^ -1) | (-(v4596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4616[v4716] = v4613;
      int * v4618 = v4552->cache_tags;
      int v4719 = (int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1);
      v4618[v4695] = v4719;
      int * v4620 = v4552->cache_dirty;
      v4620[v4695] = 0;
      int * v4622 = v4552->cache_age;
      v4622[v4695] = 1;
      int * v4624 = v4552->cache_age;
      int v4625 = v4624[v4695];
      int v4626 = v4624[v4669];
      int v4725 = v4626 + ((int)((unsigned int)(v4626 - v4625) >> 31));
      v4624[v4669] = v4725;
      int * v4628 = v4552->cache_age;
      int v4629 = v4628[v4670];
      int v4727 = v4629 + ((int)((unsigned int)(v4629 - v4625) >> 31));
      v4628[v4670] = v4727;
      int * v4631 = v4552->cache_age;
      v4631[v4695] = 0;
      v4634 = v4695;
    }
    int * v4635 = v4552->cache_vals;
    int v4730 = v4634 * 2;
    int v4636 = v4635[v4730];
    int v4731 = (v4634 * 2) + 1;
    int v4637 = v4635[v4731];
    int v4732 = (((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4576 + ((~(((v4578 ^ -1) | (-(v4578 ^ -1))) >> 31)) & 2)) - (v4579 + ((~(((v4580 ^ -1) | (-(v4580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4635[v4732] = v4636;
    int * v4639 = v4552->cache_vals;
    int v4735 = ((((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4576 + ((~(((v4578 ^ -1) | (-(v4578 ^ -1))) >> 31)) & 2)) - (v4579 + ((~(((v4580 ^ -1) | (-(v4580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4639[v4735] = v4637;
    int * v4641 = v4552->cache_tags;
    int v4738 = ((((int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4576 + ((~(((v4578 ^ -1) | (-(v4578 ^ -1))) >> 31)) & 2)) - (v4579 + ((~(((v4580 ^ -1) | (-(v4580 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4739 = (int)((unsigned int)((int)((unsigned int)(v4556 + 8) >> 2)) >> 1);
    v4641[v4738] = v4739;
    int * v4643 = v4552->cache_dirty;
    v4643[v4738] = 0;
    int * v4645 = v4552->cache_age;
    v4645[v4738] = 1;
    int * v4647 = v4552->cache_age;
    int v4648 = v4647[v4738];
    int v4649 = v4647[v4667];
    int v4745 = v4649 + ((int)((unsigned int)(v4649 - v4648) >> 31));
    v4647[v4667] = v4745;
    int * v4651 = v4552->cache_age;
    int v4652 = v4651[v4668];
    int v4747 = v4652 + ((int)((unsigned int)(v4652 - v4648) >> 31));
    v4651[v4668] = v4747;
    int * v4654 = v4552->cache_age;
    v4654[v4738] = 0;
    v4657 = v4738;
  }
  int v4750 = (v4657 * 2) + (((int)((unsigned int)(v4556 + 8) >> 2)) & 1);
  int v4658 = v4564[v4750];
  int * v4659 = v4552->regs;
  v4659[8] = v4658;
  struct StateT * v4661 = slot_14(v4552);
  return v4661;
}

struct StateT * slot_449(struct StateT * v17983) {
  int v17984 = v17983->timer;
  int v17991 = v17984 + 1;
  v17983->timer = v17991;
  int * v17986 = v17983->regs;
  int v17987 = v17986[22];
  int v17995 = (int)((unsigned int)v17987 >> 14);
  v17986[24] = v17995;
  struct StateT * v17989 = slot_450(v17983);
  return v17989;
}

struct StateT * slot_460(struct StateT * v18182) {
  int v18183 = v18182->timer;
  int v18191 = v18183 + 1;
  v18182->timer = v18191;
  int * v18185 = v18182->regs;
  int v18186 = v18185[29];
  int v18187 = v18185[9];
  int v18196 = v18186 + v18187;
  v18185[21] = v18196;
  struct StateT * v18189 = slot_461(v18182);
  return v18189;
}

struct StateT * slot_109(struct StateT * v7415) {
  int * v7416 = v7415->saved_regs;
  int * v7417 = v7415->regs;
  int v7418 = v7417[30];
  v7416[30] = v7418;
  int v7420 = v7415->timer;
  int v7432 = v7420 + 1;
  v7415->timer = v7432;
  int * v7422 = v7415->regs;
  int v7423 = v7422[30];
  int v7424 = v7422[20];
  int v7435 = v7423 ^ v7424;
  v7422[30] = v7435;
  struct StateT * v7426 = slot_110(v7415);
  return v7426;
}

struct StateT * slot_474(struct StateT * v18397) {
  int v18398 = v18397->timer;
  int v18406 = v18398 + 1;
  v18397->timer = v18406;
  int * v18400 = v18397->regs;
  int v18401 = v18400[23];
  int v18402 = v18400[24];
  int v18410 = v18401 | v18402;
  v18400[23] = v18410;
  struct StateT * v18404 = slot_475(v18397);
  return v18404;
}

struct StateT * slot_174(struct StateT * v8460) {
  int v8461 = v8460->timer;
  int v8469 = v8461 + 1;
  v8460->timer = v8469;
  int * v8463 = v8460->regs;
  int v8464 = v8463[9];
  int v8465 = v8463[5];
  int v8474 = v8464 + v8465;
  v8463[21] = v8474;
  struct StateT * v8467 = slot_175(v8460);
  return v8467;
}

struct StateT * slot_42(struct StateT * v6289) {
  int v6290 = v6289->timer;
  int v6298 = v6290 + 1;
  v6289->timer = v6298;
  int * v6292 = v6289->regs;
  int v6293 = v6292[21];
  int v6294 = v6292[24];
  int v6302 = v6293 | v6294;
  v6292[21] = v6302;
  struct StateT * v6296 = slot_43(v6289);
  return v6296;
}

struct StateT * slot_224(struct StateT * v14391) {
  int v14392 = v14391->timer;
  int v14399 = v14392 + 1;
  v14391->timer = v14399;
  int * v14394 = v14391->regs;
  int v14395 = v14394[22];
  int v14403 = (int)((unsigned int)v14395 >> 25);
  v14394[24] = v14403;
  struct StateT * v14397 = slot_226(v14391);
  return v14397;
}

struct StateT * slot_184(struct StateT * v8616) {
  int v8617 = v8616->timer;
  int v8624 = v8617 + 1;
  v8616->timer = v8624;
  int * v8619 = v8616->regs;
  int v8620 = v8619[22];
  int v8627 = v8620 << 18;
  v8619[22] = v8627;
  struct StateT * v8622 = slot_185(v8616);
  return v8622;
}

struct StateT * slot_462(struct StateT * v18216) {
  int v18217 = v18216->timer;
  int v18225 = v18217 + 1;
  v18216->timer = v18225;
  int * v18219 = v18216->regs;
  int v18220 = v18219[31];
  int v18221 = v18219[19];
  int v18230 = v18220 + v18221;
  v18219[23] = v18230;
  struct StateT * v18223 = slot_463(v18216);
  return v18223;
}

struct StateT * slot_165(struct StateT * v8318) {
  int v8319 = v8318->timer;
  int v8327 = v8319 + 1;
  v8318->timer = v8327;
  int * v8321 = v8318->regs;
  int v8322 = v8321[22];
  int v8323 = v8321[24];
  int v8331 = v8322 | v8323;
  v8321[22] = v8331;
  struct StateT * v8325 = slot_166(v8318);
  return v8325;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_393(struct StateT * v17023) {
  int v17024 = v17023->timer;
  int v17031 = v17024 + 1;
  v17023->timer = v17031;
  int * v17026 = v17023->regs;
  int v17027 = v17026[23];
  int v17034 = v17027 << 7;
  v17026[23] = v17034;
  struct StateT * v17029 = slot_394(v17023);
  return v17029;
}

struct StateT * slot_507(struct StateT * v18917) {
  int v18918 = v18917->timer;
  int v18925 = v18918 + 1;
  v18917->timer = v18925;
  int * v18920 = v18917->regs;
  int v18921 = v18920[21];
  int v18928 = v18921 << 13;
  v18920[21] = v18928;
  struct StateT * v18923 = slot_508(v18917);
  return v18923;
}

struct StateT * slot_477(struct StateT * v18445) {
  int v18446 = v18445->timer;
  int v18454 = v18446 + 1;
  v18445->timer = v18454;
  int * v18448 = v18445->regs;
  int v18449 = v18448[15];
  int v18450 = v18448[22];
  int v18458 = v18449 ^ v18450;
  v18448[15] = v18458;
  struct StateT * v18452 = slot_478(v18445);
  return v18452;
}

struct StateT * slot_278(struct StateT * v15205) {
  int v15206 = v15205->timer;
  int v15214 = v15206 + 1;
  v15205->timer = v15214;
  int * v15208 = v15205->regs;
  int v15209 = v15208[14];
  int v15210 = v15208[7];
  int v15219 = v15209 + v15210;
  v15208[21] = v15219;
  struct StateT * v15212 = slot_279(v15205);
  return v15212;
}

struct StateT * slot_352(struct StateT * v16356) {
  int v16357 = v16356->timer;
  int v16365 = v16357 + 1;
  v16356->timer = v16365;
  int * v16359 = v16356->regs;
  int v16360 = v16359[23];
  int v16361 = v16359[24];
  int v16369 = v16360 | v16361;
  v16359[23] = v16369;
  struct StateT * v16363 = slot_353(v16356);
  return v16363;
}

struct StateT * slot_249(struct StateT * v14751) {
  int v14752 = v14751->timer;
  int v14760 = v14752 + 1;
  v14751->timer = v14760;
  int * v14754 = v14751->regs;
  int v14755 = v14754[22];
  int v14756 = v14754[24];
  int v14764 = v14755 | v14756;
  v14754[22] = v14764;
  struct StateT * v14758 = slot_250(v14751);
  return v14758;
}

struct StateT * slot_11(struct StateT * v3736) {
  int v3737 = v3736->timer;
  int v3847 = v3737 + 1;
  v3736->timer = v3847;
  int * v3739 = v3736->regs;
  int v3740 = v3739[12];
  int * v3741 = v3736->cache_tags;
  int v3851 = (((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2;
  int v3742 = v3741[v3851];
  int v3852 = ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3743 = v3741[v3852];
  int v3853 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2);
  int v3744 = v3741[v3853];
  int v3854 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3745 = v3741[v3854];
  int v3746 = v3736->timer;
  int v3855 = v3746 + ((100 ^ (((~(((v3744 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3744 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) | (~(((v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3742 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3742 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) | (~(((v3743 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3743 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3744 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3744 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) | (~(((v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3736->timer = v3855;
  int * v3748 = v3736->cache_vals;
  bool v3856 = !(((~(((v3742 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3742 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) | (~(((v3743 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3743 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31))) == 0);
  int v3841;
  if (v3856) {
    int * v3749 = v3736->cache_age;
    int v3858 = ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2) + ((~(((v3743 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3743 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) & 1);
    int v3750 = v3749[v3858];
    int v3751 = v3749[v3851];
    int v3859 = v3751 + ((int)((unsigned int)(v3751 - v3750) >> 31));
    v3749[v3851] = v3859;
    int * v3753 = v3736->cache_age;
    int v3754 = v3753[v3852];
    int v3861 = v3754 + ((int)((unsigned int)(v3754 - v3750) >> 31));
    v3753[v3852] = v3861;
    int * v3756 = v3736->cache_age;
    v3756[v3858] = 0;
    v3841 = v3858;
  } else {
    int * v3759 = v3736->cache_age;
    int v3865 = (((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2;
    int v3760 = v3759[v3865];
    int * v3761 = v3736->cache_tags;
    int v3762 = v3761[v3865];
    int v3763 = v3759[v3852];
    int v3764 = v3761[v3852];
    bool v3867 = !(((~(((v3744 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3744 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) | (~(((v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31))) == 0);
    int v3818;
    if (v3867) {
      int * v3765 = v3736->cache_age;
      int v3869 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))) | (-(v3745 ^ ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1))))) >> 31)) & 1);
      int v3766 = v3765[v3869];
      int v3767 = v3765[v3853];
      int v3870 = v3767 + ((int)((unsigned int)(v3767 - v3766) >> 31));
      v3765[v3853] = v3870;
      int * v3769 = v3736->cache_age;
      int v3770 = v3769[v3854];
      int v3872 = v3770 + ((int)((unsigned int)(v3770 - v3766) >> 31));
      v3769[v3854] = v3872;
      int * v3772 = v3736->cache_age;
      v3772[v3869] = 0;
      v3818 = v3869;
    } else {
      int * v3775 = v3736->cache_age;
      int v3876 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2);
      int v3776 = v3775[v3876];
      int * v3777 = v3736->cache_tags;
      int v3778 = v3777[v3876];
      int v3779 = v3775[v3854];
      int v3780 = v3777[v3854];
      int * v3781 = v3736->cache_dirty;
      int v3879 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + ((((v3776 + ((~(((v3778 ^ -1) | (-(v3778 ^ -1))) >> 31)) & 2)) - (v3779 + ((~(((v3780 ^ -1) | (-(v3780 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3782 = v3781[v3879];
      bool v3880 = !(v3782 == 0);
      if (v3880) {
        int * v3783 = v3736->cache_tags;
        int v3784 = v3783[v3879];
        int * v3785 = v3736->cache_vals;
        int v3883 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + ((((v3776 + ((~(((v3778 ^ -1) | (-(v3778 ^ -1))) >> 31)) & 2)) - (v3779 + ((~(((v3780 ^ -1) | (-(v3780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3786 = v3785[v3883];
        int v3884 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + ((((v3776 + ((~(((v3778 ^ -1) | (-(v3778 ^ -1))) >> 31)) & 2)) - (v3779 + ((~(((v3780 ^ -1) | (-(v3780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3787 = v3785[v3884];
        int * v3788 = v3736->mem;
        int v3886 = v3784 * 2;
        v3788[v3886] = v3786;
        int * v3790 = v3736->mem;
        int v3889 = (v3784 * 2) + 1;
        v3790[v3889] = v3787;
        ;
      } else {
        ;
      }
      int * v3795 = v3736->mem;
      int v3894 = ((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) * 2;
      int v3796 = v3795[v3894];
      int v3895 = (((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) * 2) + 1;
      int v3797 = v3795[v3895];
      int * v3798 = v3736->cache_vals;
      int v3897 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + ((((v3776 + ((~(((v3778 ^ -1) | (-(v3778 ^ -1))) >> 31)) & 2)) - (v3779 + ((~(((v3780 ^ -1) | (-(v3780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3798[v3897] = v3796;
      int * v3800 = v3736->cache_vals;
      int v3900 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 3) * 2)) + ((((v3776 + ((~(((v3778 ^ -1) | (-(v3778 ^ -1))) >> 31)) & 2)) - (v3779 + ((~(((v3780 ^ -1) | (-(v3780 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3800[v3900] = v3797;
      int * v3802 = v3736->cache_tags;
      int v3903 = (int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1);
      v3802[v3879] = v3903;
      int * v3804 = v3736->cache_dirty;
      v3804[v3879] = 0;
      int * v3806 = v3736->cache_age;
      v3806[v3879] = 1;
      int * v3808 = v3736->cache_age;
      int v3809 = v3808[v3879];
      int v3810 = v3808[v3853];
      int v3909 = v3810 + ((int)((unsigned int)(v3810 - v3809) >> 31));
      v3808[v3853] = v3909;
      int * v3812 = v3736->cache_age;
      int v3813 = v3812[v3854];
      int v3911 = v3813 + ((int)((unsigned int)(v3813 - v3809) >> 31));
      v3812[v3854] = v3911;
      int * v3815 = v3736->cache_age;
      v3815[v3879] = 0;
      v3818 = v3879;
    }
    int * v3819 = v3736->cache_vals;
    int v3914 = v3818 * 2;
    int v3820 = v3819[v3914];
    int v3915 = (v3818 * 2) + 1;
    int v3821 = v3819[v3915];
    int v3916 = (((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2) + ((((v3760 + ((~(((v3762 ^ -1) | (-(v3762 ^ -1))) >> 31)) & 2)) - (v3763 + ((~(((v3764 ^ -1) | (-(v3764 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3819[v3916] = v3820;
    int * v3823 = v3736->cache_vals;
    int v3919 = ((((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2) + ((((v3760 + ((~(((v3762 ^ -1) | (-(v3762 ^ -1))) >> 31)) & 2)) - (v3763 + ((~(((v3764 ^ -1) | (-(v3764 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3823[v3919] = v3821;
    int * v3825 = v3736->cache_tags;
    int v3922 = ((((int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1)) & 1) * 2) + ((((v3760 + ((~(((v3762 ^ -1) | (-(v3762 ^ -1))) >> 31)) & 2)) - (v3763 + ((~(((v3764 ^ -1) | (-(v3764 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3923 = (int)((unsigned int)((int)((unsigned int)v3740 >> 2)) >> 1);
    v3825[v3922] = v3923;
    int * v3827 = v3736->cache_dirty;
    v3827[v3922] = 0;
    int * v3829 = v3736->cache_age;
    v3829[v3922] = 1;
    int * v3831 = v3736->cache_age;
    int v3832 = v3831[v3922];
    int v3833 = v3831[v3851];
    int v3929 = v3833 + ((int)((unsigned int)(v3833 - v3832) >> 31));
    v3831[v3851] = v3929;
    int * v3835 = v3736->cache_age;
    int v3836 = v3835[v3852];
    int v3931 = v3836 + ((int)((unsigned int)(v3836 - v3832) >> 31));
    v3835[v3852] = v3931;
    int * v3838 = v3736->cache_age;
    v3838[v3922] = 0;
    v3841 = v3922;
  }
  int v3934 = (v3841 * 2) + (((int)((unsigned int)v3740 >> 2)) & 1);
  int v3842 = v3748[v3934];
  int * v3843 = v3736->regs;
  v3843[14] = v3842;
  struct StateT * v3845 = slot_12(v3736);
  return v3845;
}

struct StateT * slot_12(struct StateT * v4144) {
  int v4145 = v4144->timer;
  int v4255 = v4145 + 1;
  v4144->timer = v4255;
  int * v4147 = v4144->regs;
  int v4148 = v4147[12];
  int * v4149 = v4144->cache_tags;
  int v4259 = (((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4150 = v4149[v4259];
  int v4260 = ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4151 = v4149[v4260];
  int v4261 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4152 = v4149[v4261];
  int v4262 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4153 = v4149[v4262];
  int v4154 = v4144->timer;
  int v4263 = v4154 + ((100 ^ (((~(((v4152 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4152 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4150 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4150 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4151 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4151 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4152 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4152 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4144->timer = v4263;
  int * v4156 = v4144->cache_vals;
  bool v4264 = !(((~(((v4150 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4150 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4151 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4151 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4249;
  if (v4264) {
    int * v4157 = v4144->cache_age;
    int v4266 = ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4151 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4151 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4158 = v4157[v4266];
    int v4159 = v4157[v4259];
    int v4267 = v4159 + ((int)((unsigned int)(v4159 - v4158) >> 31));
    v4157[v4259] = v4267;
    int * v4161 = v4144->cache_age;
    int v4162 = v4161[v4260];
    int v4269 = v4162 + ((int)((unsigned int)(v4162 - v4158) >> 31));
    v4161[v4260] = v4269;
    int * v4164 = v4144->cache_age;
    v4164[v4266] = 0;
    v4249 = v4266;
  } else {
    int * v4167 = v4144->cache_age;
    int v4273 = (((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4168 = v4167[v4273];
    int * v4169 = v4144->cache_tags;
    int v4170 = v4169[v4273];
    int v4171 = v4167[v4260];
    int v4172 = v4169[v4260];
    bool v4275 = !(((~(((v4152 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4152 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4226;
    if (v4275) {
      int * v4173 = v4144->cache_age;
      int v4277 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))) | (-(v4153 ^ ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4174 = v4173[v4277];
      int v4175 = v4173[v4261];
      int v4278 = v4175 + ((int)((unsigned int)(v4175 - v4174) >> 31));
      v4173[v4261] = v4278;
      int * v4177 = v4144->cache_age;
      int v4178 = v4177[v4262];
      int v4280 = v4178 + ((int)((unsigned int)(v4178 - v4174) >> 31));
      v4177[v4262] = v4280;
      int * v4180 = v4144->cache_age;
      v4180[v4277] = 0;
      v4226 = v4277;
    } else {
      int * v4183 = v4144->cache_age;
      int v4284 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4184 = v4183[v4284];
      int * v4185 = v4144->cache_tags;
      int v4186 = v4185[v4284];
      int v4187 = v4183[v4262];
      int v4188 = v4185[v4262];
      int * v4189 = v4144->cache_dirty;
      int v4287 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4184 + ((~(((v4186 ^ -1) | (-(v4186 ^ -1))) >> 31)) & 2)) - (v4187 + ((~(((v4188 ^ -1) | (-(v4188 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4190 = v4189[v4287];
      bool v4288 = !(v4190 == 0);
      if (v4288) {
        int * v4191 = v4144->cache_tags;
        int v4192 = v4191[v4287];
        int * v4193 = v4144->cache_vals;
        int v4291 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4184 + ((~(((v4186 ^ -1) | (-(v4186 ^ -1))) >> 31)) & 2)) - (v4187 + ((~(((v4188 ^ -1) | (-(v4188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4194 = v4193[v4291];
        int v4292 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4184 + ((~(((v4186 ^ -1) | (-(v4186 ^ -1))) >> 31)) & 2)) - (v4187 + ((~(((v4188 ^ -1) | (-(v4188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4195 = v4193[v4292];
        int * v4196 = v4144->mem;
        int v4294 = v4192 * 2;
        v4196[v4294] = v4194;
        int * v4198 = v4144->mem;
        int v4297 = (v4192 * 2) + 1;
        v4198[v4297] = v4195;
        ;
      } else {
        ;
      }
      int * v4203 = v4144->mem;
      int v4302 = ((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) * 2;
      int v4204 = v4203[v4302];
      int v4303 = (((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4205 = v4203[v4303];
      int * v4206 = v4144->cache_vals;
      int v4305 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4184 + ((~(((v4186 ^ -1) | (-(v4186 ^ -1))) >> 31)) & 2)) - (v4187 + ((~(((v4188 ^ -1) | (-(v4188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4206[v4305] = v4204;
      int * v4208 = v4144->cache_vals;
      int v4308 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4184 + ((~(((v4186 ^ -1) | (-(v4186 ^ -1))) >> 31)) & 2)) - (v4187 + ((~(((v4188 ^ -1) | (-(v4188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4208[v4308] = v4205;
      int * v4210 = v4144->cache_tags;
      int v4311 = (int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1);
      v4210[v4287] = v4311;
      int * v4212 = v4144->cache_dirty;
      v4212[v4287] = 0;
      int * v4214 = v4144->cache_age;
      v4214[v4287] = 1;
      int * v4216 = v4144->cache_age;
      int v4217 = v4216[v4287];
      int v4218 = v4216[v4261];
      int v4317 = v4218 + ((int)((unsigned int)(v4218 - v4217) >> 31));
      v4216[v4261] = v4317;
      int * v4220 = v4144->cache_age;
      int v4221 = v4220[v4262];
      int v4319 = v4221 + ((int)((unsigned int)(v4221 - v4217) >> 31));
      v4220[v4262] = v4319;
      int * v4223 = v4144->cache_age;
      v4223[v4287] = 0;
      v4226 = v4287;
    }
    int * v4227 = v4144->cache_vals;
    int v4322 = v4226 * 2;
    int v4228 = v4227[v4322];
    int v4323 = (v4226 * 2) + 1;
    int v4229 = v4227[v4323];
    int v4324 = (((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4168 + ((~(((v4170 ^ -1) | (-(v4170 ^ -1))) >> 31)) & 2)) - (v4171 + ((~(((v4172 ^ -1) | (-(v4172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4227[v4324] = v4228;
    int * v4231 = v4144->cache_vals;
    int v4327 = ((((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4168 + ((~(((v4170 ^ -1) | (-(v4170 ^ -1))) >> 31)) & 2)) - (v4171 + ((~(((v4172 ^ -1) | (-(v4172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4231[v4327] = v4229;
    int * v4233 = v4144->cache_tags;
    int v4330 = ((((int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4168 + ((~(((v4170 ^ -1) | (-(v4170 ^ -1))) >> 31)) & 2)) - (v4171 + ((~(((v4172 ^ -1) | (-(v4172 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4331 = (int)((unsigned int)((int)((unsigned int)(v4148 + 4) >> 2)) >> 1);
    v4233[v4330] = v4331;
    int * v4235 = v4144->cache_dirty;
    v4235[v4330] = 0;
    int * v4237 = v4144->cache_age;
    v4237[v4330] = 1;
    int * v4239 = v4144->cache_age;
    int v4240 = v4239[v4330];
    int v4241 = v4239[v4259];
    int v4337 = v4241 + ((int)((unsigned int)(v4241 - v4240) >> 31));
    v4239[v4259] = v4337;
    int * v4243 = v4144->cache_age;
    int v4244 = v4243[v4260];
    int v4339 = v4244 + ((int)((unsigned int)(v4244 - v4240) >> 31));
    v4243[v4260] = v4339;
    int * v4246 = v4144->cache_age;
    v4246[v4330] = 0;
    v4249 = v4330;
  }
  int v4342 = (v4249 * 2) + (((int)((unsigned int)(v4148 + 4) >> 2)) & 1);
  int v4250 = v4156[v4342];
  int * v4251 = v4144->regs;
  v4251[17] = v4250;
  struct StateT * v4253 = slot_13(v4144);
  return v4253;
}

struct StateT * slot_228(struct StateT * v14439) {
  int v14440 = v14439->timer;
  int v14448 = v14440 + 1;
  v14439->timer = v14448;
  int * v14442 = v14439->regs;
  int v14443 = v14442[22];
  int v14444 = v14442[24];
  int v14452 = v14443 | v14444;
  v14442[22] = v14452;
  struct StateT * v14446 = slot_230(v14439);
  return v14446;
}

struct StateT * slot_268(struct StateT * v15049) {
  int v15050 = v15049->timer;
  int v15057 = v15050 + 1;
  v15049->timer = v15057;
  int * v15052 = v15049->regs;
  int v15053 = v15052[22];
  int v15060 = v15053 << 13;
  v15052[22] = v15060;
  struct StateT * v15055 = slot_269(v15049);
  return v15055;
}

struct StateT * slot_199(struct StateT * v9632) {
  int v9633 = v9632->timer;
  int v9803 = v9633 + 1;
  v9632->timer = v9803;
  int * v9635 = v9632->regs;
  int v9636 = v9635[10];
  int v9637 = v9635[28];
  int * v9638 = v9632->cache_tags;
  int v9808 = (((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2;
  int v9639 = v9638[v9808];
  int v9809 = ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9640 = v9638[v9809];
  int v9810 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2);
  int v9641 = v9638[v9810];
  int v9811 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9642 = v9638[v9811];
  int v9643 = v9632->timer;
  int v9812 = v9643 + ((100 ^ (((~(((v9641 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9641 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9639 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9639 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9640 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9640 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9641 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9641 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9632->timer = v9812;
  bool v9813 = !(((~(((v9639 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9639 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9640 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9640 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v9737;
  if (v9813) {
    int * v9645 = v9632->cache_age;
    int v9815 = ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v9640 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9640 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v9646 = v9645[v9815];
    int v9647 = v9645[v9808];
    int v9816 = v9647 + ((int)((unsigned int)(v9647 - v9646) >> 31));
    v9645[v9808] = v9816;
    int * v9649 = v9632->cache_age;
    int v9650 = v9649[v9809];
    int v9818 = v9650 + ((int)((unsigned int)(v9650 - v9646) >> 31));
    v9649[v9809] = v9818;
    int * v9652 = v9632->cache_age;
    v9652[v9815] = 0;
    v9737 = v9815;
  } else {
    int * v9655 = v9632->cache_age;
    int v9822 = (((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2;
    int v9656 = v9655[v9822];
    int * v9657 = v9632->cache_tags;
    int v9658 = v9657[v9822];
    int v9659 = v9655[v9809];
    int v9660 = v9657[v9809];
    bool v9824 = !(((~(((v9641 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9641 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v9714;
    if (v9824) {
      int * v9661 = v9632->cache_age;
      int v9826 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v9662 = v9661[v9826];
      int v9663 = v9661[v9810];
      int v9827 = v9663 + ((int)((unsigned int)(v9663 - v9662) >> 31));
      v9661[v9810] = v9827;
      int * v9665 = v9632->cache_age;
      int v9666 = v9665[v9811];
      int v9829 = v9666 + ((int)((unsigned int)(v9666 - v9662) >> 31));
      v9665[v9811] = v9829;
      int * v9668 = v9632->cache_age;
      v9668[v9826] = 0;
      v9714 = v9826;
    } else {
      int * v9671 = v9632->cache_age;
      int v9833 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2);
      int v9672 = v9671[v9833];
      int * v9673 = v9632->cache_tags;
      int v9674 = v9673[v9833];
      int v9675 = v9671[v9811];
      int v9676 = v9673[v9811];
      int * v9677 = v9632->cache_dirty;
      int v9836 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9672 + ((~(((v9674 ^ -1) | (-(v9674 ^ -1))) >> 31)) & 2)) - (v9675 + ((~(((v9676 ^ -1) | (-(v9676 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9678 = v9677[v9836];
      bool v9837 = !(v9678 == 0);
      if (v9837) {
        int * v9679 = v9632->cache_tags;
        int v9680 = v9679[v9836];
        int * v9681 = v9632->cache_vals;
        int v9840 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9672 + ((~(((v9674 ^ -1) | (-(v9674 ^ -1))) >> 31)) & 2)) - (v9675 + ((~(((v9676 ^ -1) | (-(v9676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9682 = v9681[v9840];
        int v9841 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9672 + ((~(((v9674 ^ -1) | (-(v9674 ^ -1))) >> 31)) & 2)) - (v9675 + ((~(((v9676 ^ -1) | (-(v9676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9683 = v9681[v9841];
        int * v9684 = v9632->mem;
        int v9843 = v9680 * 2;
        v9684[v9843] = v9682;
        int * v9686 = v9632->mem;
        int v9846 = (v9680 * 2) + 1;
        v9686[v9846] = v9683;
        ;
      } else {
        ;
      }
      int * v9691 = v9632->mem;
      int v9851 = ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) * 2;
      int v9692 = v9691[v9851];
      int v9852 = (((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) * 2) + 1;
      int v9693 = v9691[v9852];
      int * v9694 = v9632->cache_vals;
      int v9854 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9672 + ((~(((v9674 ^ -1) | (-(v9674 ^ -1))) >> 31)) & 2)) - (v9675 + ((~(((v9676 ^ -1) | (-(v9676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9694[v9854] = v9692;
      int * v9696 = v9632->cache_vals;
      int v9857 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9672 + ((~(((v9674 ^ -1) | (-(v9674 ^ -1))) >> 31)) & 2)) - (v9675 + ((~(((v9676 ^ -1) | (-(v9676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9696[v9857] = v9693;
      int * v9698 = v9632->cache_tags;
      int v9860 = (int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1);
      v9698[v9836] = v9860;
      int * v9700 = v9632->cache_dirty;
      v9700[v9836] = 0;
      int * v9702 = v9632->cache_age;
      v9702[v9836] = 1;
      int * v9704 = v9632->cache_age;
      int v9705 = v9704[v9836];
      int v9706 = v9704[v9810];
      int v9866 = v9706 + ((int)((unsigned int)(v9706 - v9705) >> 31));
      v9704[v9810] = v9866;
      int * v9708 = v9632->cache_age;
      int v9709 = v9708[v9811];
      int v9868 = v9709 + ((int)((unsigned int)(v9709 - v9705) >> 31));
      v9708[v9811] = v9868;
      int * v9711 = v9632->cache_age;
      v9711[v9836] = 0;
      v9714 = v9836;
    }
    int * v9715 = v9632->cache_vals;
    int v9871 = v9714 * 2;
    int v9716 = v9715[v9871];
    int v9872 = (v9714 * 2) + 1;
    int v9717 = v9715[v9872];
    int v9873 = (((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v9656 + ((~(((v9658 ^ -1) | (-(v9658 ^ -1))) >> 31)) & 2)) - (v9659 + ((~(((v9660 ^ -1) | (-(v9660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9715[v9873] = v9716;
    int * v9719 = v9632->cache_vals;
    int v9876 = ((((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v9656 + ((~(((v9658 ^ -1) | (-(v9658 ^ -1))) >> 31)) & 2)) - (v9659 + ((~(((v9660 ^ -1) | (-(v9660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9719[v9876] = v9717;
    int * v9721 = v9632->cache_tags;
    int v9879 = ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v9656 + ((~(((v9658 ^ -1) | (-(v9658 ^ -1))) >> 31)) & 2)) - (v9659 + ((~(((v9660 ^ -1) | (-(v9660 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9880 = (int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1);
    v9721[v9879] = v9880;
    int * v9723 = v9632->cache_dirty;
    v9723[v9879] = 0;
    int * v9725 = v9632->cache_age;
    v9725[v9879] = 1;
    int * v9727 = v9632->cache_age;
    int v9728 = v9727[v9879];
    int v9729 = v9727[v9808];
    int v9886 = v9729 + ((int)((unsigned int)(v9729 - v9728) >> 31));
    v9727[v9808] = v9886;
    int * v9731 = v9632->cache_age;
    int v9732 = v9731[v9809];
    int v9888 = v9732 + ((int)((unsigned int)(v9732 - v9728) >> 31));
    v9731[v9809] = v9888;
    int * v9734 = v9632->cache_age;
    v9734[v9879] = 0;
    v9737 = v9879;
  }
  int * v9738 = v9632->cache_vals;
  int v9891 = (v9737 * 2) + (((int)((unsigned int)(v9636 + 8) >> 2)) & 1);
  v9738[v9891] = v9637;
  int * v9740 = v9632->cache_tags;
  int v9741 = v9740[v9810];
  int v9742 = v9740[v9811];
  bool v9894 = !(((~(((v9741 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9741 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9742 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9742 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v9796;
  if (v9894) {
    int * v9743 = v9632->cache_age;
    int v9896 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9742 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))) | (-(v9742 ^ ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v9744 = v9743[v9896];
    int v9745 = v9743[v9810];
    int v9897 = v9745 + ((int)((unsigned int)(v9745 - v9744) >> 31));
    v9743[v9810] = v9897;
    int * v9747 = v9632->cache_age;
    int v9748 = v9747[v9811];
    int v9899 = v9748 + ((int)((unsigned int)(v9748 - v9744) >> 31));
    v9747[v9811] = v9899;
    int * v9750 = v9632->cache_age;
    v9750[v9896] = 0;
    v9796 = v9896;
  } else {
    int * v9753 = v9632->cache_age;
    int v9903 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2);
    int v9754 = v9753[v9903];
    int * v9755 = v9632->cache_tags;
    int v9756 = v9755[v9903];
    int v9757 = v9753[v9811];
    int v9758 = v9755[v9811];
    int * v9759 = v9632->cache_dirty;
    int v9906 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9754 + ((~(((v9756 ^ -1) | (-(v9756 ^ -1))) >> 31)) & 2)) - (v9757 + ((~(((v9758 ^ -1) | (-(v9758 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9760 = v9759[v9906];
    bool v9907 = !(v9760 == 0);
    if (v9907) {
      int * v9761 = v9632->cache_tags;
      int v9762 = v9761[v9906];
      int * v9763 = v9632->cache_vals;
      int v9910 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9754 + ((~(((v9756 ^ -1) | (-(v9756 ^ -1))) >> 31)) & 2)) - (v9757 + ((~(((v9758 ^ -1) | (-(v9758 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9764 = v9763[v9910];
      int v9911 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9754 + ((~(((v9756 ^ -1) | (-(v9756 ^ -1))) >> 31)) & 2)) - (v9757 + ((~(((v9758 ^ -1) | (-(v9758 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9765 = v9763[v9911];
      int * v9766 = v9632->mem;
      int v9913 = v9762 * 2;
      v9766[v9913] = v9764;
      int * v9768 = v9632->mem;
      int v9916 = (v9762 * 2) + 1;
      v9768[v9916] = v9765;
      ;
    } else {
      ;
    }
    int * v9773 = v9632->mem;
    int v9921 = ((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) * 2;
    int v9774 = v9773[v9921];
    int v9922 = (((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) * 2) + 1;
    int v9775 = v9773[v9922];
    int * v9776 = v9632->cache_vals;
    int v9924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9754 + ((~(((v9756 ^ -1) | (-(v9756 ^ -1))) >> 31)) & 2)) - (v9757 + ((~(((v9758 ^ -1) | (-(v9758 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9776[v9924] = v9774;
    int * v9778 = v9632->cache_vals;
    int v9927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9754 + ((~(((v9756 ^ -1) | (-(v9756 ^ -1))) >> 31)) & 2)) - (v9757 + ((~(((v9758 ^ -1) | (-(v9758 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9778[v9927] = v9775;
    int * v9780 = v9632->cache_tags;
    int v9930 = (int)((unsigned int)((int)((unsigned int)(v9636 + 8) >> 2)) >> 1);
    v9780[v9906] = v9930;
    int * v9782 = v9632->cache_dirty;
    v9782[v9906] = 0;
    int * v9784 = v9632->cache_age;
    v9784[v9906] = 1;
    int * v9786 = v9632->cache_age;
    int v9787 = v9786[v9906];
    int v9788 = v9786[v9810];
    int v9936 = v9788 + ((int)((unsigned int)(v9788 - v9787) >> 31));
    v9786[v9810] = v9936;
    int * v9790 = v9632->cache_age;
    int v9791 = v9790[v9811];
    int v9938 = v9791 + ((int)((unsigned int)(v9791 - v9787) >> 31));
    v9790[v9811] = v9938;
    int * v9793 = v9632->cache_age;
    v9793[v9906] = 0;
    v9796 = v9906;
  }
  int * v9797 = v9632->cache_vals;
  int v9941 = (v9796 * 2) + (((int)((unsigned int)(v9636 + 8) >> 2)) & 1);
  v9797[v9941] = v9637;
  int * v9799 = v9632->cache_dirty;
  v9799[v9796] = 1;
  struct StateT * v9801 = slot_201(v9632);
  return v9801;
}

struct StateT * slot_252(struct StateT * v14796) {
  int v14797 = v14796->timer;
  int v14805 = v14797 + 1;
  v14796->timer = v14805;
  int * v14799 = v14796->regs;
  int v14800 = v14799[23];
  int v14801 = v14799[24];
  int v14809 = v14800 | v14801;
  v14799[23] = v14809;
  struct StateT * v14803 = slot_253(v14796);
  return v14803;
}

struct StateT * slot_409(struct StateT * v17303) {
  int v17304 = v17303->timer;
  int v17311 = v17304 + 1;
  v17303->timer = v17311;
  int * v17306 = v17303->regs;
  int v17307 = v17306[22];
  int v17315 = (int)((unsigned int)v17307 >> 23);
  v17306[24] = v17315;
  struct StateT * v17309 = slot_410(v17303);
  return v17309;
}

struct StateT * slot_374(struct StateT * v16700) {
  int v16701 = v16700->timer;
  int v16709 = v16701 + 1;
  v16700->timer = v16709;
  int * v16703 = v16700->regs;
  int v16704 = v16703[29];
  int v16705 = v16703[21];
  int v16713 = v16704 ^ v16705;
  v16703[29] = v16713;
  struct StateT * v16707 = slot_375(v16700);
  return v16707;
}

struct StateT * slot_269(struct StateT * v15063) {
  int v15064 = v15063->timer;
  int v15072 = v15064 + 1;
  v15063->timer = v15072;
  int * v15066 = v15063->regs;
  int v15067 = v15066[22];
  int v15068 = v15066[24];
  int v15076 = v15067 | v15068;
  v15066[22] = v15076;
  struct StateT * v15070 = slot_270(v15063);
  return v15070;
}

struct StateT * slot_501(struct StateT * v18823) {
  int v18824 = v18823->timer;
  int v18832 = v18824 + 1;
  v18823->timer = v18832;
  int * v18826 = v18823->regs;
  int v18827 = v18826[6];
  int v18828 = v18826[15];
  int v18837 = v18827 + v18828;
  v18826[22] = v18837;
  struct StateT * v18830 = slot_502(v18823);
  return v18830;
}

struct StateT * slot_251(struct StateT * v14782) {
  int v14783 = v14782->timer;
  int v14790 = v14783 + 1;
  v14782->timer = v14790;
  int * v14785 = v14782->regs;
  int v14786 = v14785[23];
  int v14793 = v14786 << 9;
  v14785[23] = v14793;
  struct StateT * v14788 = slot_252(v14782);
  return v14788;
}

struct StateT * slot_65(struct StateT * v6674) {
  int v6675 = v6674->timer;
  int v6683 = v6675 + 1;
  v6674->timer = v6683;
  int * v6677 = v6674->regs;
  int v6678 = v6677[22];
  int v6679 = v6677[24];
  int v6687 = v6678 | v6679;
  v6677[22] = v6687;
  struct StateT * v6681 = slot_66(v6674);
  return v6681;
}

struct StateT * slot_10(struct StateT * v3519) {
  int v3520 = v3519->timer;
  int v3526 = v3520 + 1;
  v3519->timer = v3526;
  int * v3522 = v3519->regs;
  v3522[13] = 0;
  struct StateT * v3524 = slot_11(v3519);
  return v3524;
}

struct StateT * slot_322(struct StateT * v15895) {
  int v15896 = v15895->timer;
  int v15903 = v15896 + 1;
  v15895->timer = v15903;
  int * v15898 = v15895->regs;
  int v15899 = v15898[20];
  int v15906 = v15899 << 9;
  v15898[20] = v15906;
  struct StateT * v15901 = slot_323(v15895);
  return v15901;
}

struct StateT * slot_277(struct StateT * v15188) {
  int v15189 = v15188->timer;
  int v15197 = v15189 + 1;
  v15188->timer = v15197;
  int * v15191 = v15188->regs;
  int v15192 = v15191[16];
  int v15193 = v15191[6];
  int v15202 = v15192 + v15193;
  v15191[20] = v15202;
  struct StateT * v15195 = slot_278(v15188);
  return v15195;
}

struct StateT * slot_353(struct StateT * v16372) {
  int v16373 = v16372->timer;
  int v16381 = v16373 + 1;
  v16372->timer = v16381;
  int * v16375 = v16372->regs;
  int v16376 = v16375[8];
  int v16377 = v16375[20];
  int v16385 = v16376 ^ v16377;
  v16375[8] = v16385;
  struct StateT * v16379 = slot_354(v16372);
  return v16379;
}

struct StateT * slot_397(struct StateT * v17099) {
  int * v17100 = v17099->saved_regs;
  int * v17101 = v17099->regs;
  int v17102 = v17101[19];
  v17100[19] = v17102;
  int v17104 = v17099->timer;
  int v17116 = v17104 + 1;
  v17099->timer = v17116;
  int * v17106 = v17099->regs;
  int v17107 = v17106[19];
  int v17108 = v17106[22];
  int v17119 = v17107 ^ v17108;
  v17106[19] = v17119;
  struct StateT * v17110 = slot_398(v17099);
  return v17110;
}

struct StateT * slot_435(struct StateT * v17733) {
  int * v17734 = v17733->saved_regs;
  int * v17735 = v17733->regs;
  int v17736 = v17735[16];
  v17734[16] = v17736;
  int v17738 = v17733->timer;
  int v17750 = v17738 + 1;
  v17733->timer = v17750;
  int * v17740 = v17733->regs;
  int v17741 = v17740[16];
  int v17742 = v17740[20];
  int v17753 = v17741 ^ v17742;
  v17740[16] = v17753;
  struct StateT * v17744 = slot_436(v17733);
  return v17744;
}

struct StateT * slot_476(struct StateT * v18429) {
  int v18430 = v18429->timer;
  int v18438 = v18430 + 1;
  v18429->timer = v18438;
  int * v18432 = v18429->regs;
  int v18433 = v18432[12];
  int v18434 = v18432[21];
  int v18442 = v18433 ^ v18434;
  v18432[12] = v18442;
  struct StateT * v18436 = slot_477(v18429);
  return v18436;
}

struct StateT * slot_136(struct StateT * v7870) {
  int v7871 = v7870->timer;
  int v7879 = v7871 + 1;
  v7870->timer = v7879;
  int * v7873 = v7870->regs;
  int v7874 = v7873[16];
  int v7875 = v7873[31];
  int v7884 = v7874 + v7875;
  v7873[23] = v7884;
  struct StateT * v7877 = slot_137(v7870);
  return v7877;
}

struct StateT * slot_379(struct StateT * v16770) {
  int * v16771 = v16770->saved_regs;
  int * v16772 = v16770->regs;
  int v16773 = v16772[20];
  v16771[20] = v16773;
  int v16775 = v16770->timer;
  int v16787 = v16775 + 1;
  v16770->timer = v16787;
  int * v16777 = v16770->regs;
  int v16778 = v16777[30];
  int v16779 = v16777[16];
  int v16791 = v16778 + v16779;
  v16777[20] = v16791;
  struct StateT * v16781 = slot_380(v16770);
  return v16781;
}

struct StateT * slot_475(struct StateT * v18413) {
  int v18414 = v18413->timer;
  int v18422 = v18414 + 1;
  v18413->timer = v18422;
  int * v18416 = v18413->regs;
  int v18417 = v18416[14];
  int v18418 = v18416[20];
  int v18426 = v18417 ^ v18418;
  v18416[14] = v18426;
  struct StateT * v18420 = slot_476(v18413);
  return v18420;
}

struct StateT * slot_310(struct StateT * v15703) {
  int v15704 = v15703->timer;
  int v15711 = v15704 + 1;
  v15703->timer = v15711;
  int * v15706 = v15703->regs;
  int v15707 = v15706[23];
  int v15715 = (int)((unsigned int)v15707 >> 25);
  v15706[24] = v15715;
  struct StateT * v15709 = slot_311(v15703);
  return v15709;
}

struct StateT * slot_445(struct StateT * v17922) {
  int v17923 = v17922->timer;
  int v17931 = v17923 + 1;
  v17922->timer = v17931;
  int * v17925 = v17922->regs;
  int v17926 = v17925[20];
  int v17927 = v17925[24];
  int v17935 = v17926 | v17927;
  v17925[20] = v17935;
  struct StateT * v17929 = slot_446(v17922);
  return v17929;
}

struct StateT * slot_295(struct StateT * v15468) {
  int v15469 = v15468->timer;
  int v15477 = v15469 + 1;
  v15468->timer = v15477;
  int * v15471 = v15468->regs;
  int v15472 = v15471[28];
  int v15473 = v15471[22];
  int v15481 = v15472 ^ v15473;
  v15471[28] = v15481;
  struct StateT * v15475 = slot_296(v15468);
  return v15475;
}

struct StateT * slot_315(struct StateT * v15780) {
  int v15781 = v15780->timer;
  int v15789 = v15781 + 1;
  v15780->timer = v15789;
  int * v15783 = v15780->regs;
  int v15784 = v15783[15];
  int v15785 = v15783[22];
  int v15793 = v15784 ^ v15785;
  v15783[15] = v15793;
  struct StateT * v15787 = slot_316(v15780);
  return v15787;
}

struct StateT * slot_17(struct StateT * v4756) {
  int v4757 = v4756->timer;
  int v4867 = v4757 + 1;
  v4756->timer = v4867;
  int * v4759 = v4756->regs;
  int v4760 = v4759[12];
  int * v4761 = v4756->cache_tags;
  int v4871 = (((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2;
  int v4762 = v4761[v4871];
  int v4872 = ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4763 = v4761[v4872];
  int v4873 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2);
  int v4764 = v4761[v4873];
  int v4874 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4765 = v4761[v4874];
  int v4766 = v4756->timer;
  int v4875 = v4766 + ((100 ^ (((~(((v4764 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4764 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4762 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4762 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4763 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4763 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4764 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4764 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4756->timer = v4875;
  int * v4768 = v4756->cache_vals;
  bool v4876 = !(((~(((v4762 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4762 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4763 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4763 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v4861;
  if (v4876) {
    int * v4769 = v4756->cache_age;
    int v4878 = ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v4763 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4763 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v4770 = v4769[v4878];
    int v4771 = v4769[v4871];
    int v4879 = v4771 + ((int)((unsigned int)(v4771 - v4770) >> 31));
    v4769[v4871] = v4879;
    int * v4773 = v4756->cache_age;
    int v4774 = v4773[v4872];
    int v4881 = v4774 + ((int)((unsigned int)(v4774 - v4770) >> 31));
    v4773[v4872] = v4881;
    int * v4776 = v4756->cache_age;
    v4776[v4878] = 0;
    v4861 = v4878;
  } else {
    int * v4779 = v4756->cache_age;
    int v4885 = (((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2;
    int v4780 = v4779[v4885];
    int * v4781 = v4756->cache_tags;
    int v4782 = v4781[v4885];
    int v4783 = v4779[v4872];
    int v4784 = v4781[v4872];
    bool v4887 = !(((~(((v4764 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4764 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v4838;
    if (v4887) {
      int * v4785 = v4756->cache_age;
      int v4889 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))) | (-(v4765 ^ ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v4786 = v4785[v4889];
      int v4787 = v4785[v4873];
      int v4890 = v4787 + ((int)((unsigned int)(v4787 - v4786) >> 31));
      v4785[v4873] = v4890;
      int * v4789 = v4756->cache_age;
      int v4790 = v4789[v4874];
      int v4892 = v4790 + ((int)((unsigned int)(v4790 - v4786) >> 31));
      v4789[v4874] = v4892;
      int * v4792 = v4756->cache_age;
      v4792[v4889] = 0;
      v4838 = v4889;
    } else {
      int * v4795 = v4756->cache_age;
      int v4896 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2);
      int v4796 = v4795[v4896];
      int * v4797 = v4756->cache_tags;
      int v4798 = v4797[v4896];
      int v4799 = v4795[v4874];
      int v4800 = v4797[v4874];
      int * v4801 = v4756->cache_dirty;
      int v4899 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4796 + ((~(((v4798 ^ -1) | (-(v4798 ^ -1))) >> 31)) & 2)) - (v4799 + ((~(((v4800 ^ -1) | (-(v4800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4802 = v4801[v4899];
      bool v4900 = !(v4802 == 0);
      if (v4900) {
        int * v4803 = v4756->cache_tags;
        int v4804 = v4803[v4899];
        int * v4805 = v4756->cache_vals;
        int v4903 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4796 + ((~(((v4798 ^ -1) | (-(v4798 ^ -1))) >> 31)) & 2)) - (v4799 + ((~(((v4800 ^ -1) | (-(v4800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4806 = v4805[v4903];
        int v4904 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4796 + ((~(((v4798 ^ -1) | (-(v4798 ^ -1))) >> 31)) & 2)) - (v4799 + ((~(((v4800 ^ -1) | (-(v4800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4807 = v4805[v4904];
        int * v4808 = v4756->mem;
        int v4906 = v4804 * 2;
        v4808[v4906] = v4806;
        int * v4810 = v4756->mem;
        int v4909 = (v4804 * 2) + 1;
        v4810[v4909] = v4807;
        ;
      } else {
        ;
      }
      int * v4815 = v4756->mem;
      int v4914 = ((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) * 2;
      int v4816 = v4815[v4914];
      int v4915 = (((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) * 2) + 1;
      int v4817 = v4815[v4915];
      int * v4818 = v4756->cache_vals;
      int v4917 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4796 + ((~(((v4798 ^ -1) | (-(v4798 ^ -1))) >> 31)) & 2)) - (v4799 + ((~(((v4800 ^ -1) | (-(v4800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4818[v4917] = v4816;
      int * v4820 = v4756->cache_vals;
      int v4920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4796 + ((~(((v4798 ^ -1) | (-(v4798 ^ -1))) >> 31)) & 2)) - (v4799 + ((~(((v4800 ^ -1) | (-(v4800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4820[v4920] = v4817;
      int * v4822 = v4756->cache_tags;
      int v4923 = (int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1);
      v4822[v4899] = v4923;
      int * v4824 = v4756->cache_dirty;
      v4824[v4899] = 0;
      int * v4826 = v4756->cache_age;
      v4826[v4899] = 1;
      int * v4828 = v4756->cache_age;
      int v4829 = v4828[v4899];
      int v4830 = v4828[v4873];
      int v4929 = v4830 + ((int)((unsigned int)(v4830 - v4829) >> 31));
      v4828[v4873] = v4929;
      int * v4832 = v4756->cache_age;
      int v4833 = v4832[v4874];
      int v4931 = v4833 + ((int)((unsigned int)(v4833 - v4829) >> 31));
      v4832[v4874] = v4931;
      int * v4835 = v4756->cache_age;
      v4835[v4899] = 0;
      v4838 = v4899;
    }
    int * v4839 = v4756->cache_vals;
    int v4934 = v4838 * 2;
    int v4840 = v4839[v4934];
    int v4935 = (v4838 * 2) + 1;
    int v4841 = v4839[v4935];
    int v4936 = (((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4780 + ((~(((v4782 ^ -1) | (-(v4782 ^ -1))) >> 31)) & 2)) - (v4783 + ((~(((v4784 ^ -1) | (-(v4784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4839[v4936] = v4840;
    int * v4843 = v4756->cache_vals;
    int v4939 = ((((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4780 + ((~(((v4782 ^ -1) | (-(v4782 ^ -1))) >> 31)) & 2)) - (v4783 + ((~(((v4784 ^ -1) | (-(v4784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4843[v4939] = v4841;
    int * v4845 = v4756->cache_tags;
    int v4942 = ((((int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4780 + ((~(((v4782 ^ -1) | (-(v4782 ^ -1))) >> 31)) & 2)) - (v4783 + ((~(((v4784 ^ -1) | (-(v4784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4943 = (int)((unsigned int)((int)((unsigned int)(v4760 + 24) >> 2)) >> 1);
    v4845[v4942] = v4943;
    int * v4847 = v4756->cache_dirty;
    v4847[v4942] = 0;
    int * v4849 = v4756->cache_age;
    v4849[v4942] = 1;
    int * v4851 = v4756->cache_age;
    int v4852 = v4851[v4942];
    int v4853 = v4851[v4871];
    int v4949 = v4853 + ((int)((unsigned int)(v4853 - v4852) >> 31));
    v4851[v4871] = v4949;
    int * v4855 = v4756->cache_age;
    int v4856 = v4855[v4872];
    int v4951 = v4856 + ((int)((unsigned int)(v4856 - v4852) >> 31));
    v4855[v4872] = v4951;
    int * v4858 = v4756->cache_age;
    v4858[v4942] = 0;
    v4861 = v4942;
  }
  int v4954 = (v4861 * 2) + (((int)((unsigned int)(v4760 + 24) >> 2)) & 1);
  int v4862 = v4768[v4954];
  int * v4863 = v4756->regs;
  v4863[7] = v4862;
  struct StateT * v4865 = slot_18(v4756);
  return v4865;
}

struct StateT * slot_197(struct StateT * v9295) {
  int v9296 = v9295->timer;
  int v9466 = v9296 + 1;
  v9295->timer = v9466;
  int * v9298 = v9295->regs;
  int v9299 = v9298[10];
  int v9300 = v9298[29];
  int * v9301 = v9295->cache_tags;
  int v9471 = (((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2;
  int v9302 = v9301[v9471];
  int v9472 = ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9303 = v9301[v9472];
  int v9473 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2);
  int v9304 = v9301[v9473];
  int v9474 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9305 = v9301[v9474];
  int v9306 = v9295->timer;
  int v9475 = v9306 + ((100 ^ (((~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9302 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9302 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9295->timer = v9475;
  bool v9476 = !(((~(((v9302 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9302 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v9400;
  if (v9476) {
    int * v9308 = v9295->cache_age;
    int v9478 = ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v9309 = v9308[v9478];
    int v9310 = v9308[v9471];
    int v9479 = v9310 + ((int)((unsigned int)(v9310 - v9309) >> 31));
    v9308[v9471] = v9479;
    int * v9312 = v9295->cache_age;
    int v9313 = v9312[v9472];
    int v9481 = v9313 + ((int)((unsigned int)(v9313 - v9309) >> 31));
    v9312[v9472] = v9481;
    int * v9315 = v9295->cache_age;
    v9315[v9478] = 0;
    v9400 = v9478;
  } else {
    int * v9318 = v9295->cache_age;
    int v9485 = (((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2;
    int v9319 = v9318[v9485];
    int * v9320 = v9295->cache_tags;
    int v9321 = v9320[v9485];
    int v9322 = v9318[v9472];
    int v9323 = v9320[v9472];
    bool v9487 = !(((~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v9377;
    if (v9487) {
      int * v9324 = v9295->cache_age;
      int v9489 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v9325 = v9324[v9489];
      int v9326 = v9324[v9473];
      int v9490 = v9326 + ((int)((unsigned int)(v9326 - v9325) >> 31));
      v9324[v9473] = v9490;
      int * v9328 = v9295->cache_age;
      int v9329 = v9328[v9474];
      int v9492 = v9329 + ((int)((unsigned int)(v9329 - v9325) >> 31));
      v9328[v9474] = v9492;
      int * v9331 = v9295->cache_age;
      v9331[v9489] = 0;
      v9377 = v9489;
    } else {
      int * v9334 = v9295->cache_age;
      int v9496 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2);
      int v9335 = v9334[v9496];
      int * v9336 = v9295->cache_tags;
      int v9337 = v9336[v9496];
      int v9338 = v9334[v9474];
      int v9339 = v9336[v9474];
      int * v9340 = v9295->cache_dirty;
      int v9499 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9335 + ((~(((v9337 ^ -1) | (-(v9337 ^ -1))) >> 31)) & 2)) - (v9338 + ((~(((v9339 ^ -1) | (-(v9339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9341 = v9340[v9499];
      bool v9500 = !(v9341 == 0);
      if (v9500) {
        int * v9342 = v9295->cache_tags;
        int v9343 = v9342[v9499];
        int * v9344 = v9295->cache_vals;
        int v9503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9335 + ((~(((v9337 ^ -1) | (-(v9337 ^ -1))) >> 31)) & 2)) - (v9338 + ((~(((v9339 ^ -1) | (-(v9339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9345 = v9344[v9503];
        int v9504 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9335 + ((~(((v9337 ^ -1) | (-(v9337 ^ -1))) >> 31)) & 2)) - (v9338 + ((~(((v9339 ^ -1) | (-(v9339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9346 = v9344[v9504];
        int * v9347 = v9295->mem;
        int v9506 = v9343 * 2;
        v9347[v9506] = v9345;
        int * v9349 = v9295->mem;
        int v9509 = (v9343 * 2) + 1;
        v9349[v9509] = v9346;
        ;
      } else {
        ;
      }
      int * v9354 = v9295->mem;
      int v9514 = ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) * 2;
      int v9355 = v9354[v9514];
      int v9515 = (((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) * 2) + 1;
      int v9356 = v9354[v9515];
      int * v9357 = v9295->cache_vals;
      int v9517 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9335 + ((~(((v9337 ^ -1) | (-(v9337 ^ -1))) >> 31)) & 2)) - (v9338 + ((~(((v9339 ^ -1) | (-(v9339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9357[v9517] = v9355;
      int * v9359 = v9295->cache_vals;
      int v9520 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9335 + ((~(((v9337 ^ -1) | (-(v9337 ^ -1))) >> 31)) & 2)) - (v9338 + ((~(((v9339 ^ -1) | (-(v9339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9359[v9520] = v9356;
      int * v9361 = v9295->cache_tags;
      int v9523 = (int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1);
      v9361[v9499] = v9523;
      int * v9363 = v9295->cache_dirty;
      v9363[v9499] = 0;
      int * v9365 = v9295->cache_age;
      v9365[v9499] = 1;
      int * v9367 = v9295->cache_age;
      int v9368 = v9367[v9499];
      int v9369 = v9367[v9473];
      int v9529 = v9369 + ((int)((unsigned int)(v9369 - v9368) >> 31));
      v9367[v9473] = v9529;
      int * v9371 = v9295->cache_age;
      int v9372 = v9371[v9474];
      int v9531 = v9372 + ((int)((unsigned int)(v9372 - v9368) >> 31));
      v9371[v9474] = v9531;
      int * v9374 = v9295->cache_age;
      v9374[v9499] = 0;
      v9377 = v9499;
    }
    int * v9378 = v9295->cache_vals;
    int v9534 = v9377 * 2;
    int v9379 = v9378[v9534];
    int v9535 = (v9377 * 2) + 1;
    int v9380 = v9378[v9535];
    int v9536 = (((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9319 + ((~(((v9321 ^ -1) | (-(v9321 ^ -1))) >> 31)) & 2)) - (v9322 + ((~(((v9323 ^ -1) | (-(v9323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9378[v9536] = v9379;
    int * v9382 = v9295->cache_vals;
    int v9539 = ((((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9319 + ((~(((v9321 ^ -1) | (-(v9321 ^ -1))) >> 31)) & 2)) - (v9322 + ((~(((v9323 ^ -1) | (-(v9323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9382[v9539] = v9380;
    int * v9384 = v9295->cache_tags;
    int v9542 = ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v9319 + ((~(((v9321 ^ -1) | (-(v9321 ^ -1))) >> 31)) & 2)) - (v9322 + ((~(((v9323 ^ -1) | (-(v9323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9543 = (int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1);
    v9384[v9542] = v9543;
    int * v9386 = v9295->cache_dirty;
    v9386[v9542] = 0;
    int * v9388 = v9295->cache_age;
    v9388[v9542] = 1;
    int * v9390 = v9295->cache_age;
    int v9391 = v9390[v9542];
    int v9392 = v9390[v9471];
    int v9549 = v9392 + ((int)((unsigned int)(v9392 - v9391) >> 31));
    v9390[v9471] = v9549;
    int * v9394 = v9295->cache_age;
    int v9395 = v9394[v9472];
    int v9551 = v9395 + ((int)((unsigned int)(v9395 - v9391) >> 31));
    v9394[v9472] = v9551;
    int * v9397 = v9295->cache_age;
    v9397[v9542] = 0;
    v9400 = v9542;
  }
  int * v9401 = v9295->cache_vals;
  int v9554 = (v9400 * 2) + (((int)((unsigned int)(v9299 + 4) >> 2)) & 1);
  v9401[v9554] = v9300;
  int * v9403 = v9295->cache_tags;
  int v9404 = v9403[v9473];
  int v9405 = v9403[v9474];
  bool v9557 = !(((~(((v9404 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9404 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v9405 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9405 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v9459;
  if (v9557) {
    int * v9406 = v9295->cache_age;
    int v9559 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9405 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))) | (-(v9405 ^ ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v9407 = v9406[v9559];
    int v9408 = v9406[v9473];
    int v9560 = v9408 + ((int)((unsigned int)(v9408 - v9407) >> 31));
    v9406[v9473] = v9560;
    int * v9410 = v9295->cache_age;
    int v9411 = v9410[v9474];
    int v9562 = v9411 + ((int)((unsigned int)(v9411 - v9407) >> 31));
    v9410[v9474] = v9562;
    int * v9413 = v9295->cache_age;
    v9413[v9559] = 0;
    v9459 = v9559;
  } else {
    int * v9416 = v9295->cache_age;
    int v9566 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2);
    int v9417 = v9416[v9566];
    int * v9418 = v9295->cache_tags;
    int v9419 = v9418[v9566];
    int v9420 = v9416[v9474];
    int v9421 = v9418[v9474];
    int * v9422 = v9295->cache_dirty;
    int v9569 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9417 + ((~(((v9419 ^ -1) | (-(v9419 ^ -1))) >> 31)) & 2)) - (v9420 + ((~(((v9421 ^ -1) | (-(v9421 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9423 = v9422[v9569];
    bool v9570 = !(v9423 == 0);
    if (v9570) {
      int * v9424 = v9295->cache_tags;
      int v9425 = v9424[v9569];
      int * v9426 = v9295->cache_vals;
      int v9573 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9417 + ((~(((v9419 ^ -1) | (-(v9419 ^ -1))) >> 31)) & 2)) - (v9420 + ((~(((v9421 ^ -1) | (-(v9421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9427 = v9426[v9573];
      int v9574 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9417 + ((~(((v9419 ^ -1) | (-(v9419 ^ -1))) >> 31)) & 2)) - (v9420 + ((~(((v9421 ^ -1) | (-(v9421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9428 = v9426[v9574];
      int * v9429 = v9295->mem;
      int v9576 = v9425 * 2;
      v9429[v9576] = v9427;
      int * v9431 = v9295->mem;
      int v9579 = (v9425 * 2) + 1;
      v9431[v9579] = v9428;
      ;
    } else {
      ;
    }
    int * v9436 = v9295->mem;
    int v9584 = ((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) * 2;
    int v9437 = v9436[v9584];
    int v9585 = (((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) * 2) + 1;
    int v9438 = v9436[v9585];
    int * v9439 = v9295->cache_vals;
    int v9587 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9417 + ((~(((v9419 ^ -1) | (-(v9419 ^ -1))) >> 31)) & 2)) - (v9420 + ((~(((v9421 ^ -1) | (-(v9421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9439[v9587] = v9437;
    int * v9441 = v9295->cache_vals;
    int v9590 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v9417 + ((~(((v9419 ^ -1) | (-(v9419 ^ -1))) >> 31)) & 2)) - (v9420 + ((~(((v9421 ^ -1) | (-(v9421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9441[v9590] = v9438;
    int * v9443 = v9295->cache_tags;
    int v9593 = (int)((unsigned int)((int)((unsigned int)(v9299 + 4) >> 2)) >> 1);
    v9443[v9569] = v9593;
    int * v9445 = v9295->cache_dirty;
    v9445[v9569] = 0;
    int * v9447 = v9295->cache_age;
    v9447[v9569] = 1;
    int * v9449 = v9295->cache_age;
    int v9450 = v9449[v9569];
    int v9451 = v9449[v9473];
    int v9599 = v9451 + ((int)((unsigned int)(v9451 - v9450) >> 31));
    v9449[v9473] = v9599;
    int * v9453 = v9295->cache_age;
    int v9454 = v9453[v9474];
    int v9601 = v9454 + ((int)((unsigned int)(v9454 - v9450) >> 31));
    v9453[v9474] = v9601;
    int * v9456 = v9295->cache_age;
    v9456[v9569] = 0;
    v9459 = v9569;
  }
  int * v9460 = v9295->cache_vals;
  int v9604 = (v9459 * 2) + (((int)((unsigned int)(v9299 + 4) >> 2)) & 1);
  v9460[v9604] = v9300;
  int * v9462 = v9295->cache_dirty;
  v9462[v9459] = 1;
  struct StateT * v9464 = slot_199(v9295);
  return v9464;
}

struct StateT * slot_457(struct StateT * v18119) {
  int * v18120 = v18119->saved_regs;
  int * v18121 = v18119->regs;
  int v18122 = v18121[28];
  v18120[28] = v18122;
  int v18124 = v18119->timer;
  int v18136 = v18124 + 1;
  v18119->timer = v18136;
  int * v18126 = v18119->regs;
  int v18127 = v18126[28];
  int v18128 = v18126[22];
  int v18139 = v18127 ^ v18128;
  v18126[28] = v18139;
  struct StateT * v18130 = slot_458(v18119);
  return v18130;
}

struct StateT * slot_207(struct StateT * v10960) {
  int v10961 = v10960->timer;
  int v11131 = v10961 + 1;
  v10960->timer = v11131;
  int * v10963 = v10960->regs;
  int v10964 = v10963[10];
  int v10965 = v10963[6];
  int * v10966 = v10960->cache_tags;
  int v11136 = (((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2;
  int v10967 = v10966[v11136];
  int v11137 = ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10968 = v10966[v11137];
  int v11138 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2);
  int v10969 = v10966[v11138];
  int v11139 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10970 = v10966[v11139];
  int v10971 = v10960->timer;
  int v11140 = v10971 + ((100 ^ (((~(((v10969 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10969 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10967 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10967 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10968 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10968 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10969 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10969 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10960->timer = v11140;
  bool v11141 = !(((~(((v10967 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10967 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10968 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10968 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v11065;
  if (v11141) {
    int * v10973 = v10960->cache_age;
    int v11143 = ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v10968 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10968 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v10974 = v10973[v11143];
    int v10975 = v10973[v11136];
    int v11144 = v10975 + ((int)((unsigned int)(v10975 - v10974) >> 31));
    v10973[v11136] = v11144;
    int * v10977 = v10960->cache_age;
    int v10978 = v10977[v11137];
    int v11146 = v10978 + ((int)((unsigned int)(v10978 - v10974) >> 31));
    v10977[v11137] = v11146;
    int * v10980 = v10960->cache_age;
    v10980[v11143] = 0;
    v11065 = v11143;
  } else {
    int * v10983 = v10960->cache_age;
    int v11150 = (((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2;
    int v10984 = v10983[v11150];
    int * v10985 = v10960->cache_tags;
    int v10986 = v10985[v11150];
    int v10987 = v10983[v11137];
    int v10988 = v10985[v11137];
    bool v11152 = !(((~(((v10969 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10969 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v11042;
    if (v11152) {
      int * v10989 = v10960->cache_age;
      int v11154 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v10970 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v10990 = v10989[v11154];
      int v10991 = v10989[v11138];
      int v11155 = v10991 + ((int)((unsigned int)(v10991 - v10990) >> 31));
      v10989[v11138] = v11155;
      int * v10993 = v10960->cache_age;
      int v10994 = v10993[v11139];
      int v11157 = v10994 + ((int)((unsigned int)(v10994 - v10990) >> 31));
      v10993[v11139] = v11157;
      int * v10996 = v10960->cache_age;
      v10996[v11154] = 0;
      v11042 = v11154;
    } else {
      int * v10999 = v10960->cache_age;
      int v11161 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2);
      int v11000 = v10999[v11161];
      int * v11001 = v10960->cache_tags;
      int v11002 = v11001[v11161];
      int v11003 = v10999[v11139];
      int v11004 = v11001[v11139];
      int * v11005 = v10960->cache_dirty;
      int v11164 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11000 + ((~(((v11002 ^ -1) | (-(v11002 ^ -1))) >> 31)) & 2)) - (v11003 + ((~(((v11004 ^ -1) | (-(v11004 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11006 = v11005[v11164];
      bool v11165 = !(v11006 == 0);
      if (v11165) {
        int * v11007 = v10960->cache_tags;
        int v11008 = v11007[v11164];
        int * v11009 = v10960->cache_vals;
        int v11168 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11000 + ((~(((v11002 ^ -1) | (-(v11002 ^ -1))) >> 31)) & 2)) - (v11003 + ((~(((v11004 ^ -1) | (-(v11004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11010 = v11009[v11168];
        int v11169 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11000 + ((~(((v11002 ^ -1) | (-(v11002 ^ -1))) >> 31)) & 2)) - (v11003 + ((~(((v11004 ^ -1) | (-(v11004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11011 = v11009[v11169];
        int * v11012 = v10960->mem;
        int v11171 = v11008 * 2;
        v11012[v11171] = v11010;
        int * v11014 = v10960->mem;
        int v11174 = (v11008 * 2) + 1;
        v11014[v11174] = v11011;
        ;
      } else {
        ;
      }
      int * v11019 = v10960->mem;
      int v11179 = ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) * 2;
      int v11020 = v11019[v11179];
      int v11180 = (((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) * 2) + 1;
      int v11021 = v11019[v11180];
      int * v11022 = v10960->cache_vals;
      int v11182 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11000 + ((~(((v11002 ^ -1) | (-(v11002 ^ -1))) >> 31)) & 2)) - (v11003 + ((~(((v11004 ^ -1) | (-(v11004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11022[v11182] = v11020;
      int * v11024 = v10960->cache_vals;
      int v11185 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11000 + ((~(((v11002 ^ -1) | (-(v11002 ^ -1))) >> 31)) & 2)) - (v11003 + ((~(((v11004 ^ -1) | (-(v11004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11024[v11185] = v11021;
      int * v11026 = v10960->cache_tags;
      int v11188 = (int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1);
      v11026[v11164] = v11188;
      int * v11028 = v10960->cache_dirty;
      v11028[v11164] = 0;
      int * v11030 = v10960->cache_age;
      v11030[v11164] = 1;
      int * v11032 = v10960->cache_age;
      int v11033 = v11032[v11164];
      int v11034 = v11032[v11138];
      int v11194 = v11034 + ((int)((unsigned int)(v11034 - v11033) >> 31));
      v11032[v11138] = v11194;
      int * v11036 = v10960->cache_age;
      int v11037 = v11036[v11139];
      int v11196 = v11037 + ((int)((unsigned int)(v11037 - v11033) >> 31));
      v11036[v11139] = v11196;
      int * v11039 = v10960->cache_age;
      v11039[v11164] = 0;
      v11042 = v11164;
    }
    int * v11043 = v10960->cache_vals;
    int v11199 = v11042 * 2;
    int v11044 = v11043[v11199];
    int v11200 = (v11042 * 2) + 1;
    int v11045 = v11043[v11200];
    int v11201 = (((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10984 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2)) - (v10987 + ((~(((v10988 ^ -1) | (-(v10988 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11043[v11201] = v11044;
    int * v11047 = v10960->cache_vals;
    int v11204 = ((((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10984 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2)) - (v10987 + ((~(((v10988 ^ -1) | (-(v10988 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11047[v11204] = v11045;
    int * v11049 = v10960->cache_tags;
    int v11207 = ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v10984 + ((~(((v10986 ^ -1) | (-(v10986 ^ -1))) >> 31)) & 2)) - (v10987 + ((~(((v10988 ^ -1) | (-(v10988 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11208 = (int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1);
    v11049[v11207] = v11208;
    int * v11051 = v10960->cache_dirty;
    v11051[v11207] = 0;
    int * v11053 = v10960->cache_age;
    v11053[v11207] = 1;
    int * v11055 = v10960->cache_age;
    int v11056 = v11055[v11207];
    int v11057 = v11055[v11136];
    int v11214 = v11057 + ((int)((unsigned int)(v11057 - v11056) >> 31));
    v11055[v11136] = v11214;
    int * v11059 = v10960->cache_age;
    int v11060 = v11059[v11137];
    int v11216 = v11060 + ((int)((unsigned int)(v11060 - v11056) >> 31));
    v11059[v11137] = v11216;
    int * v11062 = v10960->cache_age;
    v11062[v11207] = 0;
    v11065 = v11207;
  }
  int * v11066 = v10960->cache_vals;
  int v11219 = (v11065 * 2) + (((int)((unsigned int)(v10964 + 24) >> 2)) & 1);
  v11066[v11219] = v10965;
  int * v11068 = v10960->cache_tags;
  int v11069 = v11068[v11138];
  int v11070 = v11068[v11139];
  bool v11222 = !(((~(((v11069 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v11069 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11070 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v11070 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v11124;
  if (v11222) {
    int * v11071 = v10960->cache_age;
    int v11224 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11070 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))) | (-(v11070 ^ ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v11072 = v11071[v11224];
    int v11073 = v11071[v11138];
    int v11225 = v11073 + ((int)((unsigned int)(v11073 - v11072) >> 31));
    v11071[v11138] = v11225;
    int * v11075 = v10960->cache_age;
    int v11076 = v11075[v11139];
    int v11227 = v11076 + ((int)((unsigned int)(v11076 - v11072) >> 31));
    v11075[v11139] = v11227;
    int * v11078 = v10960->cache_age;
    v11078[v11224] = 0;
    v11124 = v11224;
  } else {
    int * v11081 = v10960->cache_age;
    int v11231 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2);
    int v11082 = v11081[v11231];
    int * v11083 = v10960->cache_tags;
    int v11084 = v11083[v11231];
    int v11085 = v11081[v11139];
    int v11086 = v11083[v11139];
    int * v11087 = v10960->cache_dirty;
    int v11234 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11082 + ((~(((v11084 ^ -1) | (-(v11084 ^ -1))) >> 31)) & 2)) - (v11085 + ((~(((v11086 ^ -1) | (-(v11086 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11088 = v11087[v11234];
    bool v11235 = !(v11088 == 0);
    if (v11235) {
      int * v11089 = v10960->cache_tags;
      int v11090 = v11089[v11234];
      int * v11091 = v10960->cache_vals;
      int v11238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11082 + ((~(((v11084 ^ -1) | (-(v11084 ^ -1))) >> 31)) & 2)) - (v11085 + ((~(((v11086 ^ -1) | (-(v11086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11092 = v11091[v11238];
      int v11239 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11082 + ((~(((v11084 ^ -1) | (-(v11084 ^ -1))) >> 31)) & 2)) - (v11085 + ((~(((v11086 ^ -1) | (-(v11086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11093 = v11091[v11239];
      int * v11094 = v10960->mem;
      int v11241 = v11090 * 2;
      v11094[v11241] = v11092;
      int * v11096 = v10960->mem;
      int v11244 = (v11090 * 2) + 1;
      v11096[v11244] = v11093;
      ;
    } else {
      ;
    }
    int * v11101 = v10960->mem;
    int v11249 = ((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) * 2;
    int v11102 = v11101[v11249];
    int v11250 = (((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) * 2) + 1;
    int v11103 = v11101[v11250];
    int * v11104 = v10960->cache_vals;
    int v11252 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11082 + ((~(((v11084 ^ -1) | (-(v11084 ^ -1))) >> 31)) & 2)) - (v11085 + ((~(((v11086 ^ -1) | (-(v11086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11104[v11252] = v11102;
    int * v11106 = v10960->cache_vals;
    int v11255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11082 + ((~(((v11084 ^ -1) | (-(v11084 ^ -1))) >> 31)) & 2)) - (v11085 + ((~(((v11086 ^ -1) | (-(v11086 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11106[v11255] = v11103;
    int * v11108 = v10960->cache_tags;
    int v11258 = (int)((unsigned int)((int)((unsigned int)(v10964 + 24) >> 2)) >> 1);
    v11108[v11234] = v11258;
    int * v11110 = v10960->cache_dirty;
    v11110[v11234] = 0;
    int * v11112 = v10960->cache_age;
    v11112[v11234] = 1;
    int * v11114 = v10960->cache_age;
    int v11115 = v11114[v11234];
    int v11116 = v11114[v11138];
    int v11264 = v11116 + ((int)((unsigned int)(v11116 - v11115) >> 31));
    v11114[v11138] = v11264;
    int * v11118 = v10960->cache_age;
    int v11119 = v11118[v11139];
    int v11266 = v11119 + ((int)((unsigned int)(v11119 - v11115) >> 31));
    v11118[v11139] = v11266;
    int * v11121 = v10960->cache_age;
    v11121[v11234] = 0;
    v11124 = v11234;
  }
  int * v11125 = v10960->cache_vals;
  int v11269 = (v11124 * 2) + (((int)((unsigned int)(v10964 + 24) >> 2)) & 1);
  v11125[v11269] = v10965;
  int * v11127 = v10960->cache_dirty;
  v11127[v11124] = 1;
  struct StateT * v11129 = slot_209(v10960);
  return v11129;
}

struct StateT * slot_156(struct StateT * v8182) {
  int v8183 = v8182->timer;
  int v8191 = v8183 + 1;
  v8182->timer = v8191;
  int * v8185 = v8182->regs;
  int v8186 = v8185[7];
  int v8187 = v8185[16];
  int v8196 = v8186 + v8187;
  v8185[23] = v8196;
  struct StateT * v8189 = slot_157(v8182);
  return v8189;
}

struct StateT * slot_68(struct StateT * v6719) {
  int v6720 = v6719->timer;
  int v6728 = v6720 + 1;
  v6719->timer = v6728;
  int * v6722 = v6719->regs;
  int v6723 = v6722[23];
  int v6724 = v6722[24];
  int v6732 = v6723 | v6724;
  v6722[23] = v6732;
  struct StateT * v6726 = slot_69(v6719);
  return v6726;
}

struct StateT * slot_493(struct StateT * v18695) {
  int v18696 = v18695->timer;
  int v18703 = v18696 + 1;
  v18695->timer = v18703;
  int * v18698 = v18695->regs;
  int v18699 = v18698[23];
  int v18706 = v18699 << 9;
  v18698[23] = v18706;
  struct StateT * v18701 = slot_494(v18695);
  return v18701;
}

struct StateT * slot_105(struct StateT * v7354) {
  int v7355 = v7354->timer;
  int v7363 = v7355 + 1;
  v7354->timer = v7363;
  int * v7357 = v7354->regs;
  int v7358 = v7357[22];
  int v7359 = v7357[24];
  int v7367 = v7358 | v7359;
  v7357[22] = v7367;
  struct StateT * v7361 = slot_106(v7354);
  return v7361;
}

struct StateT * slot_430(struct StateT * v17658) {
  int v17659 = v17658->timer;
  int v17666 = v17659 + 1;
  v17658->timer = v17666;
  int * v17661 = v17658->regs;
  int v17662 = v17661[22];
  int v17669 = v17662 << 13;
  v17661[22] = v17669;
  struct StateT * v17664 = slot_431(v17658);
  return v17664;
}

struct StateT * slot_369(struct StateT * v16623) {
  int v16624 = v16623->timer;
  int v16632 = v16624 + 1;
  v16623->timer = v16632;
  int * v16626 = v16623->regs;
  int v16627 = v16626[22];
  int v16628 = v16626[24];
  int v16636 = v16627 | v16628;
  v16626[22] = v16636;
  struct StateT * v16630 = slot_370(v16623);
  return v16630;
}

struct StateT * slot_461(struct StateT * v18199) {
  int v18200 = v18199->timer;
  int v18208 = v18200 + 1;
  v18199->timer = v18208;
  int * v18202 = v18199->regs;
  int v18203 = v18202[28];
  int v18204 = v18202[18];
  int v18213 = v18203 + v18204;
  v18202[22] = v18213;
  struct StateT * v18206 = slot_462(v18199);
  return v18206;
}

struct StateT * slot_164(struct StateT * v8304) {
  int v8305 = v8304->timer;
  int v8312 = v8305 + 1;
  v8304->timer = v8312;
  int * v8307 = v8304->regs;
  int v8308 = v8307[22];
  int v8315 = v8308 << 13;
  v8307[22] = v8315;
  struct StateT * v8310 = slot_165(v8304);
  return v8310;
}

struct StateT * slot_15(struct StateT * v3940) {
  int v3941 = v3940->timer;
  int v4051 = v3941 + 1;
  v3940->timer = v4051;
  int * v3943 = v3940->regs;
  int v3944 = v3943[12];
  int * v3945 = v3940->cache_tags;
  int v4055 = (((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2;
  int v3946 = v3945[v4055];
  int v4056 = ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3947 = v3945[v4056];
  int v4057 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2);
  int v3948 = v3945[v4057];
  int v4058 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3949 = v3945[v4058];
  int v3950 = v3940->timer;
  int v4059 = v3950 + ((100 ^ (((~(((v3948 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3948 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3946 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3946 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3947 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3947 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3948 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3948 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3940->timer = v4059;
  int * v3952 = v3940->cache_vals;
  bool v4060 = !(((~(((v3946 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3946 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3947 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3947 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4045;
  if (v4060) {
    int * v3953 = v3940->cache_age;
    int v4062 = ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v3947 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3947 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v3954 = v3953[v4062];
    int v3955 = v3953[v4055];
    int v4063 = v3955 + ((int)((unsigned int)(v3955 - v3954) >> 31));
    v3953[v4055] = v4063;
    int * v3957 = v3940->cache_age;
    int v3958 = v3957[v4056];
    int v4065 = v3958 + ((int)((unsigned int)(v3958 - v3954) >> 31));
    v3957[v4056] = v4065;
    int * v3960 = v3940->cache_age;
    v3960[v4062] = 0;
    v4045 = v4062;
  } else {
    int * v3963 = v3940->cache_age;
    int v4069 = (((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2;
    int v3964 = v3963[v4069];
    int * v3965 = v3940->cache_tags;
    int v3966 = v3965[v4069];
    int v3967 = v3963[v4056];
    int v3968 = v3965[v4056];
    bool v4071 = !(((~(((v3948 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3948 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v4022;
    if (v4071) {
      int * v3969 = v3940->cache_age;
      int v4073 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))) | (-(v3949 ^ ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v3970 = v3969[v4073];
      int v3971 = v3969[v4057];
      int v4074 = v3971 + ((int)((unsigned int)(v3971 - v3970) >> 31));
      v3969[v4057] = v4074;
      int * v3973 = v3940->cache_age;
      int v3974 = v3973[v4058];
      int v4076 = v3974 + ((int)((unsigned int)(v3974 - v3970) >> 31));
      v3973[v4058] = v4076;
      int * v3976 = v3940->cache_age;
      v3976[v4073] = 0;
      v4022 = v4073;
    } else {
      int * v3979 = v3940->cache_age;
      int v4080 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2);
      int v3980 = v3979[v4080];
      int * v3981 = v3940->cache_tags;
      int v3982 = v3981[v4080];
      int v3983 = v3979[v4058];
      int v3984 = v3981[v4058];
      int * v3985 = v3940->cache_dirty;
      int v4083 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3980 + ((~(((v3982 ^ -1) | (-(v3982 ^ -1))) >> 31)) & 2)) - (v3983 + ((~(((v3984 ^ -1) | (-(v3984 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3986 = v3985[v4083];
      bool v4084 = !(v3986 == 0);
      if (v4084) {
        int * v3987 = v3940->cache_tags;
        int v3988 = v3987[v4083];
        int * v3989 = v3940->cache_vals;
        int v4087 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3980 + ((~(((v3982 ^ -1) | (-(v3982 ^ -1))) >> 31)) & 2)) - (v3983 + ((~(((v3984 ^ -1) | (-(v3984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3990 = v3989[v4087];
        int v4088 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3980 + ((~(((v3982 ^ -1) | (-(v3982 ^ -1))) >> 31)) & 2)) - (v3983 + ((~(((v3984 ^ -1) | (-(v3984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3991 = v3989[v4088];
        int * v3992 = v3940->mem;
        int v4090 = v3988 * 2;
        v3992[v4090] = v3990;
        int * v3994 = v3940->mem;
        int v4093 = (v3988 * 2) + 1;
        v3994[v4093] = v3991;
        ;
      } else {
        ;
      }
      int * v3999 = v3940->mem;
      int v4098 = ((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) * 2;
      int v4000 = v3999[v4098];
      int v4099 = (((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4001 = v3999[v4099];
      int * v4002 = v3940->cache_vals;
      int v4101 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3980 + ((~(((v3982 ^ -1) | (-(v3982 ^ -1))) >> 31)) & 2)) - (v3983 + ((~(((v3984 ^ -1) | (-(v3984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4002[v4101] = v4000;
      int * v4004 = v3940->cache_vals;
      int v4104 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3980 + ((~(((v3982 ^ -1) | (-(v3982 ^ -1))) >> 31)) & 2)) - (v3983 + ((~(((v3984 ^ -1) | (-(v3984 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4004[v4104] = v4001;
      int * v4006 = v3940->cache_tags;
      int v4107 = (int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1);
      v4006[v4083] = v4107;
      int * v4008 = v3940->cache_dirty;
      v4008[v4083] = 0;
      int * v4010 = v3940->cache_age;
      v4010[v4083] = 1;
      int * v4012 = v3940->cache_age;
      int v4013 = v4012[v4083];
      int v4014 = v4012[v4057];
      int v4113 = v4014 + ((int)((unsigned int)(v4014 - v4013) >> 31));
      v4012[v4057] = v4113;
      int * v4016 = v3940->cache_age;
      int v4017 = v4016[v4058];
      int v4115 = v4017 + ((int)((unsigned int)(v4017 - v4013) >> 31));
      v4016[v4058] = v4115;
      int * v4019 = v3940->cache_age;
      v4019[v4083] = 0;
      v4022 = v4083;
    }
    int * v4023 = v3940->cache_vals;
    int v4118 = v4022 * 2;
    int v4024 = v4023[v4118];
    int v4119 = (v4022 * 2) + 1;
    int v4025 = v4023[v4119];
    int v4120 = (((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3964 + ((~(((v3966 ^ -1) | (-(v3966 ^ -1))) >> 31)) & 2)) - (v3967 + ((~(((v3968 ^ -1) | (-(v3968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4023[v4120] = v4024;
    int * v4027 = v3940->cache_vals;
    int v4123 = ((((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3964 + ((~(((v3966 ^ -1) | (-(v3966 ^ -1))) >> 31)) & 2)) - (v3967 + ((~(((v3968 ^ -1) | (-(v3968 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4027[v4123] = v4025;
    int * v4029 = v3940->cache_tags;
    int v4126 = ((((int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3964 + ((~(((v3966 ^ -1) | (-(v3966 ^ -1))) >> 31)) & 2)) - (v3967 + ((~(((v3968 ^ -1) | (-(v3968 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4127 = (int)((unsigned int)((int)((unsigned int)(v3944 + 16) >> 2)) >> 1);
    v4029[v4126] = v4127;
    int * v4031 = v3940->cache_dirty;
    v4031[v4126] = 0;
    int * v4033 = v3940->cache_age;
    v4033[v4126] = 1;
    int * v4035 = v3940->cache_age;
    int v4036 = v4035[v4126];
    int v4037 = v4035[v4055];
    int v4133 = v4037 + ((int)((unsigned int)(v4037 - v4036) >> 31));
    v4035[v4055] = v4133;
    int * v4039 = v3940->cache_age;
    int v4040 = v4039[v4056];
    int v4135 = v4040 + ((int)((unsigned int)(v4040 - v4036) >> 31));
    v4039[v4056] = v4135;
    int * v4042 = v3940->cache_age;
    v4042[v4126] = 0;
    v4045 = v4126;
  }
  int v4138 = (v4045 * 2) + (((int)((unsigned int)(v3944 + 16) >> 2)) & 1);
  int v4046 = v3952[v4138];
  int * v4047 = v3940->regs;
  v4047[15] = v4046;
  struct StateT * v4049 = slot_16(v3940);
  return v4049;
}

struct StateT * slot_480(struct StateT * v18494) {
  int v18495 = v18494->timer;
  int v18503 = v18495 + 1;
  v18494->timer = v18503;
  int * v18497 = v18494->regs;
  int v18498 = v18497[12];
  int v18499 = v18497[29];
  int v18508 = v18498 + v18499;
  v18497[21] = v18508;
  struct StateT * v18501 = slot_481(v18494);
  return v18501;
}

struct StateT * slot_133(struct StateT * v7819) {
  int v7820 = v7819->timer;
  int v7828 = v7820 + 1;
  v7819->timer = v7828;
  int * v7822 = v7819->regs;
  int v7823 = v7822[14];
  int v7824 = v7822[30];
  int v7833 = v7823 + v7824;
  v7822[20] = v7833;
  struct StateT * v7826 = slot_134(v7819);
  return v7826;
}

struct StateT * slot_56(struct StateT * v6538) {
  int v6539 = v6538->timer;
  int v6547 = v6539 + 1;
  v6538->timer = v6547;
  int * v6541 = v6538->regs;
  int v6542 = v6541[8];
  int v6543 = v6541[31];
  int v6552 = v6542 + v6543;
  v6541[23] = v6552;
  struct StateT * v6545 = slot_57(v6538);
  return v6545;
}

struct StateT * slot_244(struct StateT * v14677) {
  int v14678 = v14677->timer;
  int v14685 = v14678 + 1;
  v14677->timer = v14685;
  int * v14680 = v14677->regs;
  int v14681 = v14680[21];
  int v14689 = (int)((unsigned int)v14681 >> 23);
  v14680[24] = v14689;
  struct StateT * v14683 = slot_245(v14677);
  return v14683;
}

struct StateT * slot_222(struct StateT * v14171) {
  int v14172 = v14171->timer;
  int v14180 = v14172 + 1;
  v14171->timer = v14180;
  int * v14174 = v14171->regs;
  int v14175 = v14174[21];
  int v14176 = v14174[24];
  int v14184 = v14175 | v14176;
  v14174[21] = v14184;
  struct StateT * v14178 = slot_224(v14171);
  return v14178;
}

struct StateT * slot_171(struct StateT * v8411) {
  int v8412 = v8411->timer;
  int v8420 = v8412 + 1;
  v8411->timer = v8420;
  int * v8414 = v8411->regs;
  int v8415 = v8414[18];
  int v8416 = v8414[22];
  int v8424 = v8415 ^ v8416;
  v8414[18] = v8424;
  struct StateT * v8418 = slot_172(v8411);
  return v8418;
}

struct StateT * slot_162(struct StateT * v8273) {
  int v8274 = v8273->timer;
  int v8282 = v8274 + 1;
  v8273->timer = v8282;
  int * v8276 = v8273->regs;
  int v8277 = v8276[21];
  int v8278 = v8276[24];
  int v8286 = v8277 | v8278;
  v8276[21] = v8286;
  struct StateT * v8280 = slot_163(v8273);
  return v8280;
}

struct StateT * slot_377(struct StateT * v16748) {
  int v16749 = v16748->timer;
  int v16756 = v16749 + 1;
  v16748->timer = v16756;
  int * v16751 = v16748->regs;
  int v16752 = v16751[13];
  int v16759 = v16752 + 1;
  v16751[13] = v16759;
  struct StateT * v16754 = slot_378(v16748);
  return v16754;
}

struct StateT * slot_427(struct StateT * v17613) {
  int v17614 = v17613->timer;
  int v17621 = v17614 + 1;
  v17613->timer = v17621;
  int * v17616 = v17613->regs;
  int v17617 = v17616[21];
  int v17624 = v17617 << 13;
  v17616[21] = v17624;
  struct StateT * v17619 = slot_428(v17613);
  return v17619;
}

struct StateT * slot_399(struct StateT * v17145) {
  int v17146 = v17145->timer;
  int v17154 = v17146 + 1;
  v17145->timer = v17154;
  int * v17148 = v17145->regs;
  int v17149 = v17148[9];
  int v17150 = v17148[30];
  int v17159 = v17149 + v17150;
  v17148[20] = v17159;
  struct StateT * v17152 = slot_400(v17145);
  return v17152;
}

struct StateT * slot_239(struct StateT * v14598) {
  int v14599 = v14598->timer;
  int v14607 = v14599 + 1;
  v14598->timer = v14607;
  int * v14601 = v14598->regs;
  int v14602 = v14601[19];
  int v14603 = v14601[28];
  int v14612 = v14602 + v14603;
  v14601[22] = v14612;
  struct StateT * v14605 = slot_240(v14598);
  return v14605;
}

struct StateT * slot_464(struct StateT * v18248) {
  int v18249 = v18248->timer;
  int v18256 = v18249 + 1;
  v18248->timer = v18256;
  int * v18251 = v18248->regs;
  int v18252 = v18251[20];
  int v18259 = v18252 << 7;
  v18251[20] = v18259;
  struct StateT * v18254 = slot_465(v18248);
  return v18254;
}

struct StateT * slot_500(struct StateT * v18806) {
  int v18807 = v18806->timer;
  int v18815 = v18807 + 1;
  v18806->timer = v18815;
  int * v18809 = v18806->regs;
  int v18810 = v18809[5];
  int v18811 = v18809[12];
  int v18820 = v18810 + v18811;
  v18809[21] = v18820;
  struct StateT * v18813 = slot_501(v18806);
  return v18813;
}

struct StateT * slot_433(struct StateT * v17703) {
  int v17704 = v17703->timer;
  int v17711 = v17704 + 1;
  v17703->timer = v17711;
  int * v17706 = v17703->regs;
  int v17707 = v17706[23];
  int v17714 = v17707 << 13;
  v17706[23] = v17714;
  struct StateT * v17709 = slot_434(v17703);
  return v17709;
}

struct StateT * slot_121(struct StateT * v7635) {
  int v7636 = v7635->timer;
  int v7643 = v7636 + 1;
  v7635->timer = v7643;
  int * v7638 = v7635->regs;
  int v7639 = v7638[21];
  int v7646 = v7639 << 7;
  v7638[21] = v7646;
  struct StateT * v7641 = slot_122(v7635);
  return v7641;
}

struct StateT * slot_144(struct StateT * v7992) {
  int v7993 = v7992->timer;
  int v8000 = v7993 + 1;
  v7992->timer = v8000;
  int * v7995 = v7992->regs;
  int v7996 = v7995[22];
  int v8003 = v7996 << 9;
  v7995[22] = v8003;
  struct StateT * v7998 = slot_145(v7992);
  return v7998;
}

struct StateT * slot_267(struct StateT * v15034) {
  int v15035 = v15034->timer;
  int v15042 = v15035 + 1;
  v15034->timer = v15042;
  int * v15037 = v15034->regs;
  int v15038 = v15037[22];
  int v15046 = (int)((unsigned int)v15038 >> 19);
  v15037[24] = v15046;
  struct StateT * v15040 = slot_268(v15034);
  return v15040;
}

struct StateT * slot_492(struct StateT * v18680) {
  int v18681 = v18680->timer;
  int v18688 = v18681 + 1;
  v18680->timer = v18688;
  int * v18683 = v18680->regs;
  int v18684 = v18683[23];
  int v18692 = (int)((unsigned int)v18684 >> 23);
  v18683[24] = v18692;
  struct StateT * v18686 = slot_493(v18680);
  return v18686;
}

struct StateT * slot_201(struct StateT * v9964) {
  int v9965 = v9964->timer;
  int v10135 = v9965 + 1;
  v9964->timer = v10135;
  int * v9967 = v9964->regs;
  int v9968 = v9967[10];
  int v9969 = v9967[31];
  int * v9970 = v9964->cache_tags;
  int v10140 = (((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2;
  int v9971 = v9970[v10140];
  int v10141 = ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9972 = v9970[v10141];
  int v10142 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2);
  int v9973 = v9970[v10142];
  int v10143 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9974 = v9970[v10143];
  int v9975 = v9964->timer;
  int v10144 = v9975 + ((100 ^ (((~(((v9973 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9973 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9971 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9971 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9972 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9972 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9973 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9973 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9964->timer = v10144;
  bool v10145 = !(((~(((v9971 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9971 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9972 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9972 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v10069;
  if (v10145) {
    int * v9977 = v9964->cache_age;
    int v10147 = ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v9972 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9972 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v9978 = v9977[v10147];
    int v9979 = v9977[v10140];
    int v10148 = v9979 + ((int)((unsigned int)(v9979 - v9978) >> 31));
    v9977[v10140] = v10148;
    int * v9981 = v9964->cache_age;
    int v9982 = v9981[v10141];
    int v10150 = v9982 + ((int)((unsigned int)(v9982 - v9978) >> 31));
    v9981[v10141] = v10150;
    int * v9984 = v9964->cache_age;
    v9984[v10147] = 0;
    v10069 = v10147;
  } else {
    int * v9987 = v9964->cache_age;
    int v10154 = (((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2;
    int v9988 = v9987[v10154];
    int * v9989 = v9964->cache_tags;
    int v9990 = v9989[v10154];
    int v9991 = v9987[v10141];
    int v9992 = v9989[v10141];
    bool v10156 = !(((~(((v9973 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9973 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v10046;
    if (v10156) {
      int * v9993 = v9964->cache_age;
      int v10158 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v9974 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v9994 = v9993[v10158];
      int v9995 = v9993[v10142];
      int v10159 = v9995 + ((int)((unsigned int)(v9995 - v9994) >> 31));
      v9993[v10142] = v10159;
      int * v9997 = v9964->cache_age;
      int v9998 = v9997[v10143];
      int v10161 = v9998 + ((int)((unsigned int)(v9998 - v9994) >> 31));
      v9997[v10143] = v10161;
      int * v10000 = v9964->cache_age;
      v10000[v10158] = 0;
      v10046 = v10158;
    } else {
      int * v10003 = v9964->cache_age;
      int v10165 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2);
      int v10004 = v10003[v10165];
      int * v10005 = v9964->cache_tags;
      int v10006 = v10005[v10165];
      int v10007 = v10003[v10143];
      int v10008 = v10005[v10143];
      int * v10009 = v9964->cache_dirty;
      int v10168 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10010 = v10009[v10168];
      bool v10169 = !(v10010 == 0);
      if (v10169) {
        int * v10011 = v9964->cache_tags;
        int v10012 = v10011[v10168];
        int * v10013 = v9964->cache_vals;
        int v10172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10014 = v10013[v10172];
        int v10173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10015 = v10013[v10173];
        int * v10016 = v9964->mem;
        int v10175 = v10012 * 2;
        v10016[v10175] = v10014;
        int * v10018 = v9964->mem;
        int v10178 = (v10012 * 2) + 1;
        v10018[v10178] = v10015;
        ;
      } else {
        ;
      }
      int * v10023 = v9964->mem;
      int v10183 = ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) * 2;
      int v10024 = v10023[v10183];
      int v10184 = (((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) * 2) + 1;
      int v10025 = v10023[v10184];
      int * v10026 = v9964->cache_vals;
      int v10186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10026[v10186] = v10024;
      int * v10028 = v9964->cache_vals;
      int v10189 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10004 + ((~(((v10006 ^ -1) | (-(v10006 ^ -1))) >> 31)) & 2)) - (v10007 + ((~(((v10008 ^ -1) | (-(v10008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10028[v10189] = v10025;
      int * v10030 = v9964->cache_tags;
      int v10192 = (int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1);
      v10030[v10168] = v10192;
      int * v10032 = v9964->cache_dirty;
      v10032[v10168] = 0;
      int * v10034 = v9964->cache_age;
      v10034[v10168] = 1;
      int * v10036 = v9964->cache_age;
      int v10037 = v10036[v10168];
      int v10038 = v10036[v10142];
      int v10198 = v10038 + ((int)((unsigned int)(v10038 - v10037) >> 31));
      v10036[v10142] = v10198;
      int * v10040 = v9964->cache_age;
      int v10041 = v10040[v10143];
      int v10200 = v10041 + ((int)((unsigned int)(v10041 - v10037) >> 31));
      v10040[v10143] = v10200;
      int * v10043 = v9964->cache_age;
      v10043[v10168] = 0;
      v10046 = v10168;
    }
    int * v10047 = v9964->cache_vals;
    int v10203 = v10046 * 2;
    int v10048 = v10047[v10203];
    int v10204 = (v10046 * 2) + 1;
    int v10049 = v10047[v10204];
    int v10205 = (((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9988 + ((~(((v9990 ^ -1) | (-(v9990 ^ -1))) >> 31)) & 2)) - (v9991 + ((~(((v9992 ^ -1) | (-(v9992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10047[v10205] = v10048;
    int * v10051 = v9964->cache_vals;
    int v10208 = ((((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9988 + ((~(((v9990 ^ -1) | (-(v9990 ^ -1))) >> 31)) & 2)) - (v9991 + ((~(((v9992 ^ -1) | (-(v9992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10051[v10208] = v10049;
    int * v10053 = v9964->cache_tags;
    int v10211 = ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9988 + ((~(((v9990 ^ -1) | (-(v9990 ^ -1))) >> 31)) & 2)) - (v9991 + ((~(((v9992 ^ -1) | (-(v9992 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10212 = (int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1);
    v10053[v10211] = v10212;
    int * v10055 = v9964->cache_dirty;
    v10055[v10211] = 0;
    int * v10057 = v9964->cache_age;
    v10057[v10211] = 1;
    int * v10059 = v9964->cache_age;
    int v10060 = v10059[v10211];
    int v10061 = v10059[v10140];
    int v10218 = v10061 + ((int)((unsigned int)(v10061 - v10060) >> 31));
    v10059[v10140] = v10218;
    int * v10063 = v9964->cache_age;
    int v10064 = v10063[v10141];
    int v10220 = v10064 + ((int)((unsigned int)(v10064 - v10060) >> 31));
    v10063[v10141] = v10220;
    int * v10066 = v9964->cache_age;
    v10066[v10211] = 0;
    v10069 = v10211;
  }
  int * v10070 = v9964->cache_vals;
  int v10223 = (v10069 * 2) + (((int)((unsigned int)(v9968 + 12) >> 2)) & 1);
  v10070[v10223] = v9969;
  int * v10072 = v9964->cache_tags;
  int v10073 = v10072[v10142];
  int v10074 = v10072[v10143];
  bool v10226 = !(((~(((v10073 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v10073 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v10074 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v10074 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v10128;
  if (v10226) {
    int * v10075 = v9964->cache_age;
    int v10228 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10074 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))) | (-(v10074 ^ ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v10076 = v10075[v10228];
    int v10077 = v10075[v10142];
    int v10229 = v10077 + ((int)((unsigned int)(v10077 - v10076) >> 31));
    v10075[v10142] = v10229;
    int * v10079 = v9964->cache_age;
    int v10080 = v10079[v10143];
    int v10231 = v10080 + ((int)((unsigned int)(v10080 - v10076) >> 31));
    v10079[v10143] = v10231;
    int * v10082 = v9964->cache_age;
    v10082[v10228] = 0;
    v10128 = v10228;
  } else {
    int * v10085 = v9964->cache_age;
    int v10235 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2);
    int v10086 = v10085[v10235];
    int * v10087 = v9964->cache_tags;
    int v10088 = v10087[v10235];
    int v10089 = v10085[v10143];
    int v10090 = v10087[v10143];
    int * v10091 = v9964->cache_dirty;
    int v10238 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10092 = v10091[v10238];
    bool v10239 = !(v10092 == 0);
    if (v10239) {
      int * v10093 = v9964->cache_tags;
      int v10094 = v10093[v10238];
      int * v10095 = v9964->cache_vals;
      int v10242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10096 = v10095[v10242];
      int v10243 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10097 = v10095[v10243];
      int * v10098 = v9964->mem;
      int v10245 = v10094 * 2;
      v10098[v10245] = v10096;
      int * v10100 = v9964->mem;
      int v10248 = (v10094 * 2) + 1;
      v10100[v10248] = v10097;
      ;
    } else {
      ;
    }
    int * v10105 = v9964->mem;
    int v10253 = ((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) * 2;
    int v10106 = v10105[v10253];
    int v10254 = (((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) * 2) + 1;
    int v10107 = v10105[v10254];
    int * v10108 = v9964->cache_vals;
    int v10256 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10108[v10256] = v10106;
    int * v10110 = v9964->cache_vals;
    int v10259 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v10086 + ((~(((v10088 ^ -1) | (-(v10088 ^ -1))) >> 31)) & 2)) - (v10089 + ((~(((v10090 ^ -1) | (-(v10090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10110[v10259] = v10107;
    int * v10112 = v9964->cache_tags;
    int v10262 = (int)((unsigned int)((int)((unsigned int)(v9968 + 12) >> 2)) >> 1);
    v10112[v10238] = v10262;
    int * v10114 = v9964->cache_dirty;
    v10114[v10238] = 0;
    int * v10116 = v9964->cache_age;
    v10116[v10238] = 1;
    int * v10118 = v9964->cache_age;
    int v10119 = v10118[v10238];
    int v10120 = v10118[v10142];
    int v10268 = v10120 + ((int)((unsigned int)(v10120 - v10119) >> 31));
    v10118[v10142] = v10268;
    int * v10122 = v9964->cache_age;
    int v10123 = v10122[v10143];
    int v10270 = v10123 + ((int)((unsigned int)(v10123 - v10119) >> 31));
    v10122[v10143] = v10270;
    int * v10125 = v9964->cache_age;
    v10125[v10238] = 0;
    v10128 = v10238;
  }
  int * v10129 = v9964->cache_vals;
  int v10273 = (v10128 * 2) + (((int)((unsigned int)(v9968 + 12) >> 2)) & 1);
  v10129[v10273] = v9969;
  int * v10131 = v9964->cache_dirty;
  v10131[v10128] = 1;
  struct StateT * v10133 = slot_203(v9964);
  return v10133;
}

struct StateT * slot_63(struct StateT * v6645) {
  int v6646 = v6645->timer;
  int v6653 = v6646 + 1;
  v6645->timer = v6653;
  int * v6648 = v6645->regs;
  int v6649 = v6648[22];
  int v6657 = (int)((unsigned int)v6649 >> 23);
  v6648[24] = v6657;
  struct StateT * v6651 = slot_64(v6645);
  return v6651;
}

struct StateT * slot_195(struct StateT * v8972) {
  int v8973 = v8972->timer;
  int v9143 = v8973 + 1;
  v8972->timer = v9143;
  int * v8975 = v8972->regs;
  int v8976 = v8975[10];
  int v8977 = v8975[30];
  int * v8978 = v8972->cache_tags;
  int v9148 = (((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2;
  int v8979 = v8978[v9148];
  int v9149 = ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2) + 1;
  int v8980 = v8978[v9149];
  int v9150 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2);
  int v8981 = v8978[v9150];
  int v9151 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8982 = v8978[v9151];
  int v8983 = v8972->timer;
  int v9152 = v8983 + ((100 ^ (((~(((v8981 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8981 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) | (~(((v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8979 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8979 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) | (~(((v8980 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8980 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8981 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8981 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) | (~(((v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31))) & 104)))));
  v8972->timer = v9152;
  bool v9153 = !(((~(((v8979 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8979 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) | (~(((v8980 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8980 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31))) == 0);
  int v9077;
  if (v9153) {
    int * v8985 = v8972->cache_age;
    int v9155 = ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2) + ((~(((v8980 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8980 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) & 1);
    int v8986 = v8985[v9155];
    int v8987 = v8985[v9148];
    int v9156 = v8987 + ((int)((unsigned int)(v8987 - v8986) >> 31));
    v8985[v9148] = v9156;
    int * v8989 = v8972->cache_age;
    int v8990 = v8989[v9149];
    int v9158 = v8990 + ((int)((unsigned int)(v8990 - v8986) >> 31));
    v8989[v9149] = v9158;
    int * v8992 = v8972->cache_age;
    v8992[v9155] = 0;
    v9077 = v9155;
  } else {
    int * v8995 = v8972->cache_age;
    int v9162 = (((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2;
    int v8996 = v8995[v9162];
    int * v8997 = v8972->cache_tags;
    int v8998 = v8997[v9162];
    int v8999 = v8995[v9149];
    int v9000 = v8997[v9149];
    bool v9164 = !(((~(((v8981 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8981 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) | (~(((v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31))) == 0);
    int v9054;
    if (v9164) {
      int * v9001 = v8972->cache_age;
      int v9166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((~(((v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v8982 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) & 1);
      int v9002 = v9001[v9166];
      int v9003 = v9001[v9150];
      int v9167 = v9003 + ((int)((unsigned int)(v9003 - v9002) >> 31));
      v9001[v9150] = v9167;
      int * v9005 = v8972->cache_age;
      int v9006 = v9005[v9151];
      int v9169 = v9006 + ((int)((unsigned int)(v9006 - v9002) >> 31));
      v9005[v9151] = v9169;
      int * v9008 = v8972->cache_age;
      v9008[v9166] = 0;
      v9054 = v9166;
    } else {
      int * v9011 = v8972->cache_age;
      int v9173 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2);
      int v9012 = v9011[v9173];
      int * v9013 = v8972->cache_tags;
      int v9014 = v9013[v9173];
      int v9015 = v9011[v9151];
      int v9016 = v9013[v9151];
      int * v9017 = v8972->cache_dirty;
      int v9176 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9012 + ((~(((v9014 ^ -1) | (-(v9014 ^ -1))) >> 31)) & 2)) - (v9015 + ((~(((v9016 ^ -1) | (-(v9016 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9018 = v9017[v9176];
      bool v9177 = !(v9018 == 0);
      if (v9177) {
        int * v9019 = v8972->cache_tags;
        int v9020 = v9019[v9176];
        int * v9021 = v8972->cache_vals;
        int v9180 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9012 + ((~(((v9014 ^ -1) | (-(v9014 ^ -1))) >> 31)) & 2)) - (v9015 + ((~(((v9016 ^ -1) | (-(v9016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9022 = v9021[v9180];
        int v9181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9012 + ((~(((v9014 ^ -1) | (-(v9014 ^ -1))) >> 31)) & 2)) - (v9015 + ((~(((v9016 ^ -1) | (-(v9016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9023 = v9021[v9181];
        int * v9024 = v8972->mem;
        int v9183 = v9020 * 2;
        v9024[v9183] = v9022;
        int * v9026 = v8972->mem;
        int v9186 = (v9020 * 2) + 1;
        v9026[v9186] = v9023;
        ;
      } else {
        ;
      }
      int * v9031 = v8972->mem;
      int v9191 = ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) * 2;
      int v9032 = v9031[v9191];
      int v9192 = (((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) * 2) + 1;
      int v9033 = v9031[v9192];
      int * v9034 = v8972->cache_vals;
      int v9194 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9012 + ((~(((v9014 ^ -1) | (-(v9014 ^ -1))) >> 31)) & 2)) - (v9015 + ((~(((v9016 ^ -1) | (-(v9016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9034[v9194] = v9032;
      int * v9036 = v8972->cache_vals;
      int v9197 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9012 + ((~(((v9014 ^ -1) | (-(v9014 ^ -1))) >> 31)) & 2)) - (v9015 + ((~(((v9016 ^ -1) | (-(v9016 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9036[v9197] = v9033;
      int * v9038 = v8972->cache_tags;
      int v9200 = (int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1);
      v9038[v9176] = v9200;
      int * v9040 = v8972->cache_dirty;
      v9040[v9176] = 0;
      int * v9042 = v8972->cache_age;
      v9042[v9176] = 1;
      int * v9044 = v8972->cache_age;
      int v9045 = v9044[v9176];
      int v9046 = v9044[v9150];
      int v9206 = v9046 + ((int)((unsigned int)(v9046 - v9045) >> 31));
      v9044[v9150] = v9206;
      int * v9048 = v8972->cache_age;
      int v9049 = v9048[v9151];
      int v9208 = v9049 + ((int)((unsigned int)(v9049 - v9045) >> 31));
      v9048[v9151] = v9208;
      int * v9051 = v8972->cache_age;
      v9051[v9176] = 0;
      v9054 = v9176;
    }
    int * v9055 = v8972->cache_vals;
    int v9211 = v9054 * 2;
    int v9056 = v9055[v9211];
    int v9212 = (v9054 * 2) + 1;
    int v9057 = v9055[v9212];
    int v9213 = (((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2) + ((((v8996 + ((~(((v8998 ^ -1) | (-(v8998 ^ -1))) >> 31)) & 2)) - (v8999 + ((~(((v9000 ^ -1) | (-(v9000 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9055[v9213] = v9056;
    int * v9059 = v8972->cache_vals;
    int v9216 = ((((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2) + ((((v8996 + ((~(((v8998 ^ -1) | (-(v8998 ^ -1))) >> 31)) & 2)) - (v8999 + ((~(((v9000 ^ -1) | (-(v9000 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9059[v9216] = v9057;
    int * v9061 = v8972->cache_tags;
    int v9219 = ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 1) * 2) + ((((v8996 + ((~(((v8998 ^ -1) | (-(v8998 ^ -1))) >> 31)) & 2)) - (v8999 + ((~(((v9000 ^ -1) | (-(v9000 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9220 = (int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1);
    v9061[v9219] = v9220;
    int * v9063 = v8972->cache_dirty;
    v9063[v9219] = 0;
    int * v9065 = v8972->cache_age;
    v9065[v9219] = 1;
    int * v9067 = v8972->cache_age;
    int v9068 = v9067[v9219];
    int v9069 = v9067[v9148];
    int v9226 = v9069 + ((int)((unsigned int)(v9069 - v9068) >> 31));
    v9067[v9148] = v9226;
    int * v9071 = v8972->cache_age;
    int v9072 = v9071[v9149];
    int v9228 = v9072 + ((int)((unsigned int)(v9072 - v9068) >> 31));
    v9071[v9149] = v9228;
    int * v9074 = v8972->cache_age;
    v9074[v9219] = 0;
    v9077 = v9219;
  }
  int * v9078 = v8972->cache_vals;
  int v9231 = (v9077 * 2) + (((int)((unsigned int)v8976 >> 2)) & 1);
  v9078[v9231] = v8977;
  int * v9080 = v8972->cache_tags;
  int v9081 = v9080[v9150];
  int v9082 = v9080[v9151];
  bool v9234 = !(((~(((v9081 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v9081 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) | (~(((v9082 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v9082 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31))) == 0);
  int v9136;
  if (v9234) {
    int * v9083 = v8972->cache_age;
    int v9236 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9082 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))) | (-(v9082 ^ ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1))))) >> 31)) & 1);
    int v9084 = v9083[v9236];
    int v9085 = v9083[v9150];
    int v9237 = v9085 + ((int)((unsigned int)(v9085 - v9084) >> 31));
    v9083[v9150] = v9237;
    int * v9087 = v8972->cache_age;
    int v9088 = v9087[v9151];
    int v9239 = v9088 + ((int)((unsigned int)(v9088 - v9084) >> 31));
    v9087[v9151] = v9239;
    int * v9090 = v8972->cache_age;
    v9090[v9236] = 0;
    v9136 = v9236;
  } else {
    int * v9093 = v8972->cache_age;
    int v9243 = 4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2);
    int v9094 = v9093[v9243];
    int * v9095 = v8972->cache_tags;
    int v9096 = v9095[v9243];
    int v9097 = v9093[v9151];
    int v9098 = v9095[v9151];
    int * v9099 = v8972->cache_dirty;
    int v9246 = (4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9094 + ((~(((v9096 ^ -1) | (-(v9096 ^ -1))) >> 31)) & 2)) - (v9097 + ((~(((v9098 ^ -1) | (-(v9098 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9100 = v9099[v9246];
    bool v9247 = !(v9100 == 0);
    if (v9247) {
      int * v9101 = v8972->cache_tags;
      int v9102 = v9101[v9246];
      int * v9103 = v8972->cache_vals;
      int v9250 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9094 + ((~(((v9096 ^ -1) | (-(v9096 ^ -1))) >> 31)) & 2)) - (v9097 + ((~(((v9098 ^ -1) | (-(v9098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9104 = v9103[v9250];
      int v9251 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9094 + ((~(((v9096 ^ -1) | (-(v9096 ^ -1))) >> 31)) & 2)) - (v9097 + ((~(((v9098 ^ -1) | (-(v9098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9105 = v9103[v9251];
      int * v9106 = v8972->mem;
      int v9253 = v9102 * 2;
      v9106[v9253] = v9104;
      int * v9108 = v8972->mem;
      int v9256 = (v9102 * 2) + 1;
      v9108[v9256] = v9105;
      ;
    } else {
      ;
    }
    int * v9113 = v8972->mem;
    int v9261 = ((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) * 2;
    int v9114 = v9113[v9261];
    int v9262 = (((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) * 2) + 1;
    int v9115 = v9113[v9262];
    int * v9116 = v8972->cache_vals;
    int v9264 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9094 + ((~(((v9096 ^ -1) | (-(v9096 ^ -1))) >> 31)) & 2)) - (v9097 + ((~(((v9098 ^ -1) | (-(v9098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9116[v9264] = v9114;
    int * v9118 = v8972->cache_vals;
    int v9267 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1)) & 3) * 2)) + ((((v9094 + ((~(((v9096 ^ -1) | (-(v9096 ^ -1))) >> 31)) & 2)) - (v9097 + ((~(((v9098 ^ -1) | (-(v9098 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9118[v9267] = v9115;
    int * v9120 = v8972->cache_tags;
    int v9270 = (int)((unsigned int)((int)((unsigned int)v8976 >> 2)) >> 1);
    v9120[v9246] = v9270;
    int * v9122 = v8972->cache_dirty;
    v9122[v9246] = 0;
    int * v9124 = v8972->cache_age;
    v9124[v9246] = 1;
    int * v9126 = v8972->cache_age;
    int v9127 = v9126[v9246];
    int v9128 = v9126[v9150];
    int v9276 = v9128 + ((int)((unsigned int)(v9128 - v9127) >> 31));
    v9126[v9150] = v9276;
    int * v9130 = v8972->cache_age;
    int v9131 = v9130[v9151];
    int v9278 = v9131 + ((int)((unsigned int)(v9131 - v9127) >> 31));
    v9130[v9151] = v9278;
    int * v9133 = v8972->cache_age;
    v9133[v9246] = 0;
    v9136 = v9246;
  }
  int * v9137 = v8972->cache_vals;
  int v9281 = (v9136 * 2) + (((int)((unsigned int)v8976 >> 2)) & 1);
  v9137[v9281] = v8977;
  int * v9139 = v8972->cache_dirty;
  v9139[v9136] = 1;
  struct StateT * v9141 = slot_197(v8972);
  return v9141;
}

struct StateT * slot_326(struct StateT * v15954) {
  int v15955 = v15954->timer;
  int v15963 = v15955 + 1;
  v15954->timer = v15963;
  int * v15957 = v15954->regs;
  int v15958 = v15957[21];
  int v15959 = v15957[24];
  int v15967 = v15958 | v15959;
  v15957[21] = v15967;
  struct StateT * v15961 = slot_327(v15954);
  return v15961;
}

struct StateT * slot_303(struct StateT * v15597) {
  int v15598 = v15597->timer;
  int v15606 = v15598 + 1;
  v15597->timer = v15606;
  int * v15600 = v15597->regs;
  int v15601 = v15600[20];
  int v15602 = v15600[24];
  int v15610 = v15601 | v15602;
  v15600[20] = v15610;
  struct StateT * v15604 = slot_304(v15597);
  return v15604;
}

struct StateT * slot_511(struct StateT * v18976) {
  int v18977 = v18976->timer;
  int v18985 = v18977 + 1;
  v18976->timer = v18985;
  int * v18979 = v18976->regs;
  int v18980 = v18979[22];
  int v18981 = v18979[24];
  int v18989 = v18980 | v18981;
  v18979[22] = v18989;
  struct StateT * v18983 = slot_512(v18976);
  return v18983;
}

struct StateT * slot_335(struct StateT * v16092) {
  int v16093 = v16092->timer;
  int v16101 = v16093 + 1;
  v16092->timer = v16101;
  int * v16095 = v16092->regs;
  int v16096 = v16095[6];
  int v16097 = v16095[22];
  int v16105 = v16096 ^ v16097;
  v16095[6] = v16105;
  struct StateT * v16099 = slot_336(v16092);
  return v16099;
}

struct StateT * slot_223(struct StateT * v14187) {
  int v14188 = v14187->timer;
  int v14298 = v14188 + 1;
  v14187->timer = v14298;
  int * v14190 = v14187->regs;
  int v14191 = v14190[2];
  int * v14192 = v14187->cache_tags;
  int v14302 = (((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2;
  int v14193 = v14192[v14302];
  int v14303 = ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14194 = v14192[v14303];
  int v14304 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2);
  int v14195 = v14192[v14304];
  int v14305 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14196 = v14192[v14305];
  int v14197 = v14187->timer;
  int v14306 = v14197 + ((100 ^ (((~(((v14195 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14195 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14193 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14193 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v14194 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14194 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14195 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14195 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14187->timer = v14306;
  int * v14199 = v14187->cache_vals;
  bool v14307 = !(((~(((v14193 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14193 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v14194 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14194 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v14292;
  if (v14307) {
    int * v14200 = v14187->cache_age;
    int v14309 = ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v14194 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14194 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v14201 = v14200[v14309];
    int v14202 = v14200[v14302];
    int v14310 = v14202 + ((int)((unsigned int)(v14202 - v14201) >> 31));
    v14200[v14302] = v14310;
    int * v14204 = v14187->cache_age;
    int v14205 = v14204[v14303];
    int v14312 = v14205 + ((int)((unsigned int)(v14205 - v14201) >> 31));
    v14204[v14303] = v14312;
    int * v14207 = v14187->cache_age;
    v14207[v14309] = 0;
    v14292 = v14309;
  } else {
    int * v14210 = v14187->cache_age;
    int v14316 = (((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2;
    int v14211 = v14210[v14316];
    int * v14212 = v14187->cache_tags;
    int v14213 = v14212[v14316];
    int v14214 = v14210[v14303];
    int v14215 = v14212[v14303];
    bool v14318 = !(((~(((v14195 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14195 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v14269;
    if (v14318) {
      int * v14216 = v14187->cache_age;
      int v14320 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))) | (-(v14196 ^ ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v14217 = v14216[v14320];
      int v14218 = v14216[v14304];
      int v14321 = v14218 + ((int)((unsigned int)(v14218 - v14217) >> 31));
      v14216[v14304] = v14321;
      int * v14220 = v14187->cache_age;
      int v14221 = v14220[v14305];
      int v14323 = v14221 + ((int)((unsigned int)(v14221 - v14217) >> 31));
      v14220[v14305] = v14323;
      int * v14223 = v14187->cache_age;
      v14223[v14320] = 0;
      v14269 = v14320;
    } else {
      int * v14226 = v14187->cache_age;
      int v14327 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2);
      int v14227 = v14226[v14327];
      int * v14228 = v14187->cache_tags;
      int v14229 = v14228[v14327];
      int v14230 = v14226[v14305];
      int v14231 = v14228[v14305];
      int * v14232 = v14187->cache_dirty;
      int v14330 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v14227 + ((~(((v14229 ^ -1) | (-(v14229 ^ -1))) >> 31)) & 2)) - (v14230 + ((~(((v14231 ^ -1) | (-(v14231 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14233 = v14232[v14330];
      bool v14331 = !(v14233 == 0);
      if (v14331) {
        int * v14234 = v14187->cache_tags;
        int v14235 = v14234[v14330];
        int * v14236 = v14187->cache_vals;
        int v14334 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v14227 + ((~(((v14229 ^ -1) | (-(v14229 ^ -1))) >> 31)) & 2)) - (v14230 + ((~(((v14231 ^ -1) | (-(v14231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14237 = v14236[v14334];
        int v14335 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v14227 + ((~(((v14229 ^ -1) | (-(v14229 ^ -1))) >> 31)) & 2)) - (v14230 + ((~(((v14231 ^ -1) | (-(v14231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14238 = v14236[v14335];
        int * v14239 = v14187->mem;
        int v14337 = v14235 * 2;
        v14239[v14337] = v14237;
        int * v14241 = v14187->mem;
        int v14340 = (v14235 * 2) + 1;
        v14241[v14340] = v14238;
        ;
      } else {
        ;
      }
      int * v14246 = v14187->mem;
      int v14345 = ((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) * 2;
      int v14247 = v14246[v14345];
      int v14346 = (((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) * 2) + 1;
      int v14248 = v14246[v14346];
      int * v14249 = v14187->cache_vals;
      int v14348 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v14227 + ((~(((v14229 ^ -1) | (-(v14229 ^ -1))) >> 31)) & 2)) - (v14230 + ((~(((v14231 ^ -1) | (-(v14231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14249[v14348] = v14247;
      int * v14251 = v14187->cache_vals;
      int v14351 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v14227 + ((~(((v14229 ^ -1) | (-(v14229 ^ -1))) >> 31)) & 2)) - (v14230 + ((~(((v14231 ^ -1) | (-(v14231 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14251[v14351] = v14248;
      int * v14253 = v14187->cache_tags;
      int v14354 = (int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1);
      v14253[v14330] = v14354;
      int * v14255 = v14187->cache_dirty;
      v14255[v14330] = 0;
      int * v14257 = v14187->cache_age;
      v14257[v14330] = 1;
      int * v14259 = v14187->cache_age;
      int v14260 = v14259[v14330];
      int v14261 = v14259[v14304];
      int v14360 = v14261 + ((int)((unsigned int)(v14261 - v14260) >> 31));
      v14259[v14304] = v14360;
      int * v14263 = v14187->cache_age;
      int v14264 = v14263[v14305];
      int v14362 = v14264 + ((int)((unsigned int)(v14264 - v14260) >> 31));
      v14263[v14305] = v14362;
      int * v14266 = v14187->cache_age;
      v14266[v14330] = 0;
      v14269 = v14330;
    }
    int * v14270 = v14187->cache_vals;
    int v14365 = v14269 * 2;
    int v14271 = v14270[v14365];
    int v14366 = (v14269 * 2) + 1;
    int v14272 = v14270[v14366];
    int v14367 = (((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v14211 + ((~(((v14213 ^ -1) | (-(v14213 ^ -1))) >> 31)) & 2)) - (v14214 + ((~(((v14215 ^ -1) | (-(v14215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14270[v14367] = v14271;
    int * v14274 = v14187->cache_vals;
    int v14370 = ((((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v14211 + ((~(((v14213 ^ -1) | (-(v14213 ^ -1))) >> 31)) & 2)) - (v14214 + ((~(((v14215 ^ -1) | (-(v14215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14274[v14370] = v14272;
    int * v14276 = v14187->cache_tags;
    int v14373 = ((((int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v14211 + ((~(((v14213 ^ -1) | (-(v14213 ^ -1))) >> 31)) & 2)) - (v14214 + ((~(((v14215 ^ -1) | (-(v14215 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14374 = (int)((unsigned int)((int)((unsigned int)(v14191 + 12) >> 2)) >> 1);
    v14276[v14373] = v14374;
    int * v14278 = v14187->cache_dirty;
    v14278[v14373] = 0;
    int * v14280 = v14187->cache_age;
    v14280[v14373] = 1;
    int * v14282 = v14187->cache_age;
    int v14283 = v14282[v14373];
    int v14284 = v14282[v14302];
    int v14380 = v14284 + ((int)((unsigned int)(v14284 - v14283) >> 31));
    v14282[v14302] = v14380;
    int * v14286 = v14187->cache_age;
    int v14287 = v14286[v14303];
    int v14382 = v14287 + ((int)((unsigned int)(v14287 - v14283) >> 31));
    v14286[v14303] = v14382;
    int * v14289 = v14187->cache_age;
    v14289[v14373] = 0;
    v14292 = v14373;
  }
  int v14385 = (v14292 * 2) + (((int)((unsigned int)(v14191 + 12) >> 2)) & 1);
  int v14293 = v14199[v14385];
  int * v14294 = v14187->regs;
  v14294[24] = v14293;
  struct StateT * v14296 = slot_225(v14187);
  return v14296;
}

struct StateT * slot_316(struct StateT * v15796) {
  int v15797 = v15796->timer;
  int v15805 = v15797 + 1;
  v15796->timer = v15805;
  int * v15799 = v15796->regs;
  int v15800 = v15799[16];
  int v15801 = v15799[23];
  int v15809 = v15800 ^ v15801;
  v15799[16] = v15809;
  struct StateT * v15803 = slot_317(v15796);
  return v15803;
}

struct StateT * slot_424(struct StateT * v17568) {
  int v17569 = v17568->timer;
  int v17576 = v17569 + 1;
  v17568->timer = v17576;
  int * v17571 = v17568->regs;
  int v17572 = v17571[20];
  int v17579 = v17572 << 13;
  v17571[20] = v17579;
  struct StateT * v17574 = slot_425(v17568);
  return v17574;
}

struct StateT * slot_332(struct StateT * v16044) {
  int v16045 = v16044->timer;
  int v16053 = v16045 + 1;
  v16044->timer = v16053;
  int * v16047 = v16044->regs;
  int v16048 = v16047[23];
  int v16049 = v16047[24];
  int v16057 = v16048 | v16049;
  v16047[23] = v16057;
  struct StateT * v16051 = slot_333(v16044);
  return v16051;
}

struct StateT * slot_237(struct StateT * v14564) {
  int v14565 = v14564->timer;
  int v14573 = v14565 + 1;
  v14564->timer = v14573;
  int * v14567 = v14564->regs;
  int v14568 = v14567[9];
  int v14569 = v14567[30];
  int v14578 = v14568 + v14569;
  v14567[20] = v14578;
  struct StateT * v14571 = slot_238(v14564);
  return v14571;
}

struct StateT * slot_41(struct StateT * v6275) {
  int v6276 = v6275->timer;
  int v6283 = v6276 + 1;
  v6275->timer = v6283;
  int * v6278 = v6275->regs;
  int v6279 = v6278[21];
  int v6286 = v6279 << 7;
  v6278[21] = v6286;
  struct StateT * v6281 = slot_42(v6275);
  return v6281;
}

struct StateT * slot_39(struct StateT * v6244) {
  int v6245 = v6244->timer;
  int v6253 = v6245 + 1;
  v6244->timer = v6253;
  int * v6247 = v6244->regs;
  int v6248 = v6247[20];
  int v6249 = v6247[24];
  int v6257 = v6248 | v6249;
  v6247[20] = v6257;
  struct StateT * v6251 = slot_40(v6244);
  return v6251;
}

struct StateT * slot_508(struct StateT * v18931) {
  int v18932 = v18931->timer;
  int v18940 = v18932 + 1;
  v18931->timer = v18940;
  int * v18934 = v18931->regs;
  int v18935 = v18934[21];
  int v18936 = v18934[24];
  int v18944 = v18935 | v18936;
  v18934[21] = v18944;
  struct StateT * v18938 = slot_509(v18931);
  return v18938;
}

struct StateT * slot_537(struct StateT * v19381) {
  int v19382 = v19381->timer;
  int v19390 = v19382 + 1;
  v19381->timer = v19390;
  int * v19384 = v19381->regs;
  int v19385 = v19384[28];
  int v19386 = v19384[22];
  int v19394 = v19385 ^ v19386;
  v19384[28] = v19394;
  struct StateT * v19388 = slot_538(v19381);
  return v19388;
}

struct StateT * slot_60(struct StateT * v6600) {
  int v6601 = v6600->timer;
  int v6608 = v6601 + 1;
  v6600->timer = v6608;
  int * v6603 = v6600->regs;
  int v6604 = v6603[21];
  int v6612 = (int)((unsigned int)v6604 >> 23);
  v6603[24] = v6612;
  struct StateT * v6606 = slot_61(v6600);
  return v6606;
}

struct StateT * slot_289(struct StateT * v15375) {
  int v15376 = v15375->timer;
  int v15384 = v15376 + 1;
  v15375->timer = v15384;
  int * v15378 = v15375->regs;
  int v15379 = v15378[22];
  int v15380 = v15378[24];
  int v15388 = v15379 | v15380;
  v15378[22] = v15388;
  struct StateT * v15382 = slot_290(v15375);
  return v15382;
}

struct StateT * slot_238(struct StateT * v14581) {
  int v14582 = v14581->timer;
  int v14590 = v14582 + 1;
  v14581->timer = v14590;
  int * v14584 = v14581->regs;
  int v14585 = v14584[18];
  int v14586 = v14584[29];
  int v14595 = v14585 + v14586;
  v14584[21] = v14595;
  struct StateT * v14588 = slot_239(v14581);
  return v14588;
}

struct StateT * slot_112(struct StateT * v7484) {
  int * v7485 = v7484->saved_regs;
  int * v7486 = v7484->regs;
  int v7487 = v7486[31];
  v7485[31] = v7487;
  int v7489 = v7484->timer;
  int v7501 = v7489 + 1;
  v7484->timer = v7501;
  int * v7491 = v7484->regs;
  int v7492 = v7491[31];
  int v7493 = v7491[23];
  int v7504 = v7492 ^ v7493;
  v7491[31] = v7504;
  struct StateT * v7495 = slot_113(v7484);
  return v7495;
}

struct StateT * slot_256(struct StateT * v14860) {
  int v14861 = v14860->timer;
  int v14869 = v14861 + 1;
  v14860->timer = v14869;
  int * v14863 = v14860->regs;
  int v14864 = v14863[5];
  int v14865 = v14863[23];
  int v14873 = v14864 ^ v14865;
  v14863[5] = v14873;
  struct StateT * v14867 = slot_257(v14860);
  return v14867;
}

struct StateT * slot_16(struct StateT * v4348) {
  int v4349 = v4348->timer;
  int v4459 = v4349 + 1;
  v4348->timer = v4459;
  int * v4351 = v4348->regs;
  int v4352 = v4351[12];
  int * v4353 = v4348->cache_tags;
  int v4463 = (((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2;
  int v4354 = v4353[v4463];
  int v4464 = ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4355 = v4353[v4464];
  int v4465 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2);
  int v4356 = v4353[v4465];
  int v4466 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4357 = v4353[v4466];
  int v4358 = v4348->timer;
  int v4467 = v4358 + ((100 ^ (((~(((v4356 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4356 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4354 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4354 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4355 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4355 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4356 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4356 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4348->timer = v4467;
  int * v4360 = v4348->cache_vals;
  bool v4468 = !(((~(((v4354 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4354 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4355 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4355 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v4453;
  if (v4468) {
    int * v4361 = v4348->cache_age;
    int v4470 = ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v4355 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4355 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v4362 = v4361[v4470];
    int v4363 = v4361[v4463];
    int v4471 = v4363 + ((int)((unsigned int)(v4363 - v4362) >> 31));
    v4361[v4463] = v4471;
    int * v4365 = v4348->cache_age;
    int v4366 = v4365[v4464];
    int v4473 = v4366 + ((int)((unsigned int)(v4366 - v4362) >> 31));
    v4365[v4464] = v4473;
    int * v4368 = v4348->cache_age;
    v4368[v4470] = 0;
    v4453 = v4470;
  } else {
    int * v4371 = v4348->cache_age;
    int v4477 = (((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2;
    int v4372 = v4371[v4477];
    int * v4373 = v4348->cache_tags;
    int v4374 = v4373[v4477];
    int v4375 = v4371[v4464];
    int v4376 = v4373[v4464];
    bool v4479 = !(((~(((v4356 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4356 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v4430;
    if (v4479) {
      int * v4377 = v4348->cache_age;
      int v4481 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))) | (-(v4357 ^ ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v4378 = v4377[v4481];
      int v4379 = v4377[v4465];
      int v4482 = v4379 + ((int)((unsigned int)(v4379 - v4378) >> 31));
      v4377[v4465] = v4482;
      int * v4381 = v4348->cache_age;
      int v4382 = v4381[v4466];
      int v4484 = v4382 + ((int)((unsigned int)(v4382 - v4378) >> 31));
      v4381[v4466] = v4484;
      int * v4384 = v4348->cache_age;
      v4384[v4481] = 0;
      v4430 = v4481;
    } else {
      int * v4387 = v4348->cache_age;
      int v4488 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2);
      int v4388 = v4387[v4488];
      int * v4389 = v4348->cache_tags;
      int v4390 = v4389[v4488];
      int v4391 = v4387[v4466];
      int v4392 = v4389[v4466];
      int * v4393 = v4348->cache_dirty;
      int v4491 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4388 + ((~(((v4390 ^ -1) | (-(v4390 ^ -1))) >> 31)) & 2)) - (v4391 + ((~(((v4392 ^ -1) | (-(v4392 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4394 = v4393[v4491];
      bool v4492 = !(v4394 == 0);
      if (v4492) {
        int * v4395 = v4348->cache_tags;
        int v4396 = v4395[v4491];
        int * v4397 = v4348->cache_vals;
        int v4495 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4388 + ((~(((v4390 ^ -1) | (-(v4390 ^ -1))) >> 31)) & 2)) - (v4391 + ((~(((v4392 ^ -1) | (-(v4392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4398 = v4397[v4495];
        int v4496 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4388 + ((~(((v4390 ^ -1) | (-(v4390 ^ -1))) >> 31)) & 2)) - (v4391 + ((~(((v4392 ^ -1) | (-(v4392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4399 = v4397[v4496];
        int * v4400 = v4348->mem;
        int v4498 = v4396 * 2;
        v4400[v4498] = v4398;
        int * v4402 = v4348->mem;
        int v4501 = (v4396 * 2) + 1;
        v4402[v4501] = v4399;
        ;
      } else {
        ;
      }
      int * v4407 = v4348->mem;
      int v4506 = ((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) * 2;
      int v4408 = v4407[v4506];
      int v4507 = (((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) * 2) + 1;
      int v4409 = v4407[v4507];
      int * v4410 = v4348->cache_vals;
      int v4509 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4388 + ((~(((v4390 ^ -1) | (-(v4390 ^ -1))) >> 31)) & 2)) - (v4391 + ((~(((v4392 ^ -1) | (-(v4392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4410[v4509] = v4408;
      int * v4412 = v4348->cache_vals;
      int v4512 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4388 + ((~(((v4390 ^ -1) | (-(v4390 ^ -1))) >> 31)) & 2)) - (v4391 + ((~(((v4392 ^ -1) | (-(v4392 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4412[v4512] = v4409;
      int * v4414 = v4348->cache_tags;
      int v4515 = (int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1);
      v4414[v4491] = v4515;
      int * v4416 = v4348->cache_dirty;
      v4416[v4491] = 0;
      int * v4418 = v4348->cache_age;
      v4418[v4491] = 1;
      int * v4420 = v4348->cache_age;
      int v4421 = v4420[v4491];
      int v4422 = v4420[v4465];
      int v4521 = v4422 + ((int)((unsigned int)(v4422 - v4421) >> 31));
      v4420[v4465] = v4521;
      int * v4424 = v4348->cache_age;
      int v4425 = v4424[v4466];
      int v4523 = v4425 + ((int)((unsigned int)(v4425 - v4421) >> 31));
      v4424[v4466] = v4523;
      int * v4427 = v4348->cache_age;
      v4427[v4491] = 0;
      v4430 = v4491;
    }
    int * v4431 = v4348->cache_vals;
    int v4526 = v4430 * 2;
    int v4432 = v4431[v4526];
    int v4527 = (v4430 * 2) + 1;
    int v4433 = v4431[v4527];
    int v4528 = (((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4372 + ((~(((v4374 ^ -1) | (-(v4374 ^ -1))) >> 31)) & 2)) - (v4375 + ((~(((v4376 ^ -1) | (-(v4376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4431[v4528] = v4432;
    int * v4435 = v4348->cache_vals;
    int v4531 = ((((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4372 + ((~(((v4374 ^ -1) | (-(v4374 ^ -1))) >> 31)) & 2)) - (v4375 + ((~(((v4376 ^ -1) | (-(v4376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4435[v4531] = v4433;
    int * v4437 = v4348->cache_tags;
    int v4534 = ((((int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4372 + ((~(((v4374 ^ -1) | (-(v4374 ^ -1))) >> 31)) & 2)) - (v4375 + ((~(((v4376 ^ -1) | (-(v4376 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4535 = (int)((unsigned int)((int)((unsigned int)(v4352 + 20) >> 2)) >> 1);
    v4437[v4534] = v4535;
    int * v4439 = v4348->cache_dirty;
    v4439[v4534] = 0;
    int * v4441 = v4348->cache_age;
    v4441[v4534] = 1;
    int * v4443 = v4348->cache_age;
    int v4444 = v4443[v4534];
    int v4445 = v4443[v4463];
    int v4541 = v4445 + ((int)((unsigned int)(v4445 - v4444) >> 31));
    v4443[v4463] = v4541;
    int * v4447 = v4348->cache_age;
    int v4448 = v4447[v4464];
    int v4543 = v4448 + ((int)((unsigned int)(v4448 - v4444) >> 31));
    v4447[v4464] = v4543;
    int * v4450 = v4348->cache_age;
    v4450[v4534] = 0;
    v4453 = v4534;
  }
  int v4546 = (v4453 * 2) + (((int)((unsigned int)(v4352 + 20) >> 2)) & 1);
  int v4454 = v4360[v4546];
  int * v4455 = v4348->regs;
  v4455[16] = v4454;
  struct StateT * v4457 = slot_17(v4348);
  return v4457;
}

struct StateT * slot_245(struct StateT * v14692) {
  int v14693 = v14692->timer;
  int v14700 = v14693 + 1;
  v14692->timer = v14700;
  int * v14695 = v14692->regs;
  int v14696 = v14695[21];
  int v14703 = v14696 << 9;
  v14695[21] = v14703;
  struct StateT * v14698 = slot_246(v14692);
  return v14698;
}

struct StateT * slot_113(struct StateT * v7507) {
  int v7508 = v7507->timer;
  int v7516 = v7508 + 1;
  v7507->timer = v7516;
  int * v7510 = v7507->regs;
  int v7511 = v7510[30];
  int v7512 = v7510[8];
  int v7521 = v7511 + v7512;
  v7510[20] = v7521;
  struct StateT * v7514 = slot_114(v7507);
  return v7514;
}

struct StateT * slot_302(struct StateT * v15583) {
  int v15584 = v15583->timer;
  int v15591 = v15584 + 1;
  v15583->timer = v15591;
  int * v15586 = v15583->regs;
  int v15587 = v15586[20];
  int v15594 = v15587 << 7;
  v15586[20] = v15594;
  struct StateT * v15589 = slot_303(v15583);
  return v15589;
}

struct StateT * slot_388(struct StateT * v16947) {
  int v16948 = v16947->timer;
  int v16956 = v16948 + 1;
  v16947->timer = v16956;
  int * v16950 = v16947->regs;
  int v16951 = v16950[21];
  int v16952 = v16950[24];
  int v16960 = v16951 | v16952;
  v16950[21] = v16960;
  struct StateT * v16954 = slot_389(v16947);
  return v16954;
}

struct StateT * slot_191(struct StateT * v8723) {
  int v8724 = v8723->timer;
  int v8732 = v8724 + 1;
  v8723->timer = v8732;
  int * v8726 = v8723->regs;
  int v8727 = v8726[28];
  int v8728 = v8726[22];
  int v8736 = v8727 ^ v8728;
  v8726[28] = v8736;
  struct StateT * v8730 = slot_192(v8723);
  return v8730;
}

struct StateT * slot_103(struct StateT * v7325) {
  int v7326 = v7325->timer;
  int v7333 = v7326 + 1;
  v7325->timer = v7333;
  int * v7328 = v7325->regs;
  int v7329 = v7328[22];
  int v7337 = (int)((unsigned int)v7329 >> 14);
  v7328[24] = v7337;
  struct StateT * v7331 = slot_104(v7325);
  return v7331;
}

struct StateT * slot_487(struct StateT * v18605) {
  int v18606 = v18605->timer;
  int v18613 = v18606 + 1;
  v18605->timer = v18613;
  int * v18608 = v18605->regs;
  int v18609 = v18608[21];
  int v18616 = v18609 << 9;
  v18608[21] = v18616;
  struct StateT * v18611 = slot_488(v18605);
  return v18611;
}

struct StateT * slot_324(struct StateT * v15925) {
  int v15926 = v15925->timer;
  int v15933 = v15926 + 1;
  v15925->timer = v15933;
  int * v15928 = v15925->regs;
  int v15929 = v15928[21];
  int v15937 = (int)((unsigned int)v15929 >> 23);
  v15928[24] = v15937;
  struct StateT * v15931 = slot_325(v15925);
  return v15931;
}

struct StateT * slot_440(struct StateT * v17842) {
  int v17843 = v17842->timer;
  int v17851 = v17843 + 1;
  v17842->timer = v17851;
  int * v17845 = v17842->regs;
  int v17846 = v17845[14];
  int v17847 = v17845[7];
  int v17856 = v17846 + v17847;
  v17845[21] = v17856;
  struct StateT * v17849 = slot_441(v17842);
  return v17849;
}

struct StateT * slot_518(struct StateT * v19085) {
  int v19086 = v19085->timer;
  int v19094 = v19086 + 1;
  v19085->timer = v19094;
  int * v19088 = v19085->regs;
  int v19089 = v19088[19];
  int v19090 = v19088[23];
  int v19098 = v19089 ^ v19090;
  v19088[19] = v19098;
  struct StateT * v19092 = slot_519(v19085);
  return v19092;
}

struct StateT * slot_95(struct StateT * v7201) {
  int v7202 = v7201->timer;
  int v7210 = v7202 + 1;
  v7201->timer = v7210;
  int * v7204 = v7201->regs;
  int v7205 = v7204[12];
  int v7206 = v7204[17];
  int v7215 = v7205 + v7206;
  v7204[22] = v7215;
  struct StateT * v7208 = slot_96(v7201);
  return v7208;
}

struct StateT * slot_451(struct StateT * v18012) {
  int v18013 = v18012->timer;
  int v18021 = v18013 + 1;
  v18012->timer = v18021;
  int * v18015 = v18012->regs;
  int v18016 = v18015[22];
  int v18017 = v18015[24];
  int v18025 = v18016 | v18017;
  v18015[22] = v18025;
  struct StateT * v18019 = slot_452(v18012);
  return v18019;
}

struct StateT * slot_458(struct StateT * v18142) {
  int * v18143 = v18142->saved_regs;
  int * v18144 = v18142->regs;
  int v18145 = v18144[31];
  v18143[31] = v18145;
  int v18147 = v18142->timer;
  int v18159 = v18147 + 1;
  v18142->timer = v18159;
  int * v18149 = v18142->regs;
  int v18150 = v18149[31];
  int v18151 = v18149[23];
  int v18162 = v18150 ^ v18151;
  v18149[31] = v18162;
  struct StateT * v18153 = slot_459(v18142);
  return v18153;
}

struct StateT * slot_415(struct StateT * v17393) {
  int * v17394 = v17393->saved_regs;
  int * v17395 = v17393->regs;
  int v17396 = v17395[6];
  v17394[6] = v17396;
  int v17398 = v17393->timer;
  int v17410 = v17398 + 1;
  v17393->timer = v17410;
  int * v17400 = v17393->regs;
  int v17401 = v17400[6];
  int v17402 = v17400[20];
  int v17413 = v17401 ^ v17402;
  v17400[6] = v17413;
  struct StateT * v17404 = slot_416(v17393);
  return v17404;
}

struct StateT * slot_354(struct StateT * v16388) {
  int v16389 = v16388->timer;
  int v16397 = v16389 + 1;
  v16388->timer = v16397;
  int * v16391 = v16388->regs;
  int v16392 = v16391[9];
  int v16393 = v16391[21];
  int v16401 = v16392 ^ v16393;
  v16391[9] = v16401;
  struct StateT * v16395 = slot_355(v16388);
  return v16395;
}

struct StateT * slot_531(struct StateT * v19288) {
  int v19289 = v19288->timer;
  int v19297 = v19289 + 1;
  v19288->timer = v19297;
  int * v19291 = v19288->regs;
  int v19292 = v19291[22];
  int v19293 = v19291[24];
  int v19301 = v19292 | v19293;
  v19291[22] = v19301;
  struct StateT * v19295 = slot_532(v19288);
  return v19295;
}

struct StateT * slot_115(struct StateT * v7541) {
  int v7542 = v7541->timer;
  int v7550 = v7542 + 1;
  v7541->timer = v7550;
  int * v7544 = v7541->regs;
  int v7545 = v7544[28];
  int v7546 = v7544[18];
  int v7555 = v7545 + v7546;
  v7544[22] = v7555;
  struct StateT * v7548 = slot_116(v7541);
  return v7548;
}

struct StateT * slot_78(struct StateT * v6910) {
  int v6911 = v6910->timer;
  int v6918 = v6911 + 1;
  v6910->timer = v6918;
  int * v6913 = v6910->regs;
  int v6914 = v6913[20];
  int v6921 = v6914 << 13;
  v6913[20] = v6921;
  struct StateT * v6916 = slot_79(v6910);
  return v6916;
}

struct StateT * slot_321(struct StateT * v15880) {
  int v15881 = v15880->timer;
  int v15888 = v15881 + 1;
  v15880->timer = v15888;
  int * v15883 = v15880->regs;
  int v15884 = v15883[20];
  int v15892 = (int)((unsigned int)v15884 >> 23);
  v15883[24] = v15892;
  struct StateT * v15886 = slot_322(v15880);
  return v15886;
}

struct StateT * slot_317(struct StateT * v15812) {
  int v15813 = v15812->timer;
  int v15821 = v15813 + 1;
  v15812->timer = v15821;
  int * v15815 = v15812->regs;
  int v15816 = v15815[14];
  int v15817 = v15815[30];
  int v15826 = v15816 + v15817;
  v15815[20] = v15826;
  struct StateT * v15819 = slot_318(v15812);
  return v15819;
}

struct StateT * slot_205(struct StateT * v10628) {
  int v10629 = v10628->timer;
  int v10799 = v10629 + 1;
  v10628->timer = v10799;
  int * v10631 = v10628->regs;
  int v10632 = v10631[10];
  int v10633 = v10631[5];
  int * v10634 = v10628->cache_tags;
  int v10804 = (((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2;
  int v10635 = v10634[v10804];
  int v10805 = ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v10636 = v10634[v10805];
  int v10806 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2);
  int v10637 = v10634[v10806];
  int v10807 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v10638 = v10634[v10807];
  int v10639 = v10628->timer;
  int v10808 = v10639 + ((100 ^ (((~(((v10637 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10637 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v10635 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10635 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10636 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10636 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10637 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10637 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v10628->timer = v10808;
  bool v10809 = !(((~(((v10635 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10635 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10636 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10636 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v10733;
  if (v10809) {
    int * v10641 = v10628->cache_age;
    int v10811 = ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v10636 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10636 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v10642 = v10641[v10811];
    int v10643 = v10641[v10804];
    int v10812 = v10643 + ((int)((unsigned int)(v10643 - v10642) >> 31));
    v10641[v10804] = v10812;
    int * v10645 = v10628->cache_age;
    int v10646 = v10645[v10805];
    int v10814 = v10646 + ((int)((unsigned int)(v10646 - v10642) >> 31));
    v10645[v10805] = v10814;
    int * v10648 = v10628->cache_age;
    v10648[v10811] = 0;
    v10733 = v10811;
  } else {
    int * v10651 = v10628->cache_age;
    int v10818 = (((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2;
    int v10652 = v10651[v10818];
    int * v10653 = v10628->cache_tags;
    int v10654 = v10653[v10818];
    int v10655 = v10651[v10805];
    int v10656 = v10653[v10805];
    bool v10820 = !(((~(((v10637 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10637 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v10710;
    if (v10820) {
      int * v10657 = v10628->cache_age;
      int v10822 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10638 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v10658 = v10657[v10822];
      int v10659 = v10657[v10806];
      int v10823 = v10659 + ((int)((unsigned int)(v10659 - v10658) >> 31));
      v10657[v10806] = v10823;
      int * v10661 = v10628->cache_age;
      int v10662 = v10661[v10807];
      int v10825 = v10662 + ((int)((unsigned int)(v10662 - v10658) >> 31));
      v10661[v10807] = v10825;
      int * v10664 = v10628->cache_age;
      v10664[v10822] = 0;
      v10710 = v10822;
    } else {
      int * v10667 = v10628->cache_age;
      int v10829 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2);
      int v10668 = v10667[v10829];
      int * v10669 = v10628->cache_tags;
      int v10670 = v10669[v10829];
      int v10671 = v10667[v10807];
      int v10672 = v10669[v10807];
      int * v10673 = v10628->cache_dirty;
      int v10832 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10668 + ((~(((v10670 ^ -1) | (-(v10670 ^ -1))) >> 31)) & 2)) - (v10671 + ((~(((v10672 ^ -1) | (-(v10672 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v10674 = v10673[v10832];
      bool v10833 = !(v10674 == 0);
      if (v10833) {
        int * v10675 = v10628->cache_tags;
        int v10676 = v10675[v10832];
        int * v10677 = v10628->cache_vals;
        int v10836 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10668 + ((~(((v10670 ^ -1) | (-(v10670 ^ -1))) >> 31)) & 2)) - (v10671 + ((~(((v10672 ^ -1) | (-(v10672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v10678 = v10677[v10836];
        int v10837 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10668 + ((~(((v10670 ^ -1) | (-(v10670 ^ -1))) >> 31)) & 2)) - (v10671 + ((~(((v10672 ^ -1) | (-(v10672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v10679 = v10677[v10837];
        int * v10680 = v10628->mem;
        int v10839 = v10676 * 2;
        v10680[v10839] = v10678;
        int * v10682 = v10628->mem;
        int v10842 = (v10676 * 2) + 1;
        v10682[v10842] = v10679;
        ;
      } else {
        ;
      }
      int * v10687 = v10628->mem;
      int v10847 = ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) * 2;
      int v10688 = v10687[v10847];
      int v10848 = (((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) * 2) + 1;
      int v10689 = v10687[v10848];
      int * v10690 = v10628->cache_vals;
      int v10850 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10668 + ((~(((v10670 ^ -1) | (-(v10670 ^ -1))) >> 31)) & 2)) - (v10671 + ((~(((v10672 ^ -1) | (-(v10672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v10690[v10850] = v10688;
      int * v10692 = v10628->cache_vals;
      int v10853 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10668 + ((~(((v10670 ^ -1) | (-(v10670 ^ -1))) >> 31)) & 2)) - (v10671 + ((~(((v10672 ^ -1) | (-(v10672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v10692[v10853] = v10689;
      int * v10694 = v10628->cache_tags;
      int v10856 = (int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1);
      v10694[v10832] = v10856;
      int * v10696 = v10628->cache_dirty;
      v10696[v10832] = 0;
      int * v10698 = v10628->cache_age;
      v10698[v10832] = 1;
      int * v10700 = v10628->cache_age;
      int v10701 = v10700[v10832];
      int v10702 = v10700[v10806];
      int v10862 = v10702 + ((int)((unsigned int)(v10702 - v10701) >> 31));
      v10700[v10806] = v10862;
      int * v10704 = v10628->cache_age;
      int v10705 = v10704[v10807];
      int v10864 = v10705 + ((int)((unsigned int)(v10705 - v10701) >> 31));
      v10704[v10807] = v10864;
      int * v10707 = v10628->cache_age;
      v10707[v10832] = 0;
      v10710 = v10832;
    }
    int * v10711 = v10628->cache_vals;
    int v10867 = v10710 * 2;
    int v10712 = v10711[v10867];
    int v10868 = (v10710 * 2) + 1;
    int v10713 = v10711[v10868];
    int v10869 = (((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v10652 + ((~(((v10654 ^ -1) | (-(v10654 ^ -1))) >> 31)) & 2)) - (v10655 + ((~(((v10656 ^ -1) | (-(v10656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10711[v10869] = v10712;
    int * v10715 = v10628->cache_vals;
    int v10872 = ((((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v10652 + ((~(((v10654 ^ -1) | (-(v10654 ^ -1))) >> 31)) & 2)) - (v10655 + ((~(((v10656 ^ -1) | (-(v10656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10715[v10872] = v10713;
    int * v10717 = v10628->cache_tags;
    int v10875 = ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v10652 + ((~(((v10654 ^ -1) | (-(v10654 ^ -1))) >> 31)) & 2)) - (v10655 + ((~(((v10656 ^ -1) | (-(v10656 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10876 = (int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1);
    v10717[v10875] = v10876;
    int * v10719 = v10628->cache_dirty;
    v10719[v10875] = 0;
    int * v10721 = v10628->cache_age;
    v10721[v10875] = 1;
    int * v10723 = v10628->cache_age;
    int v10724 = v10723[v10875];
    int v10725 = v10723[v10804];
    int v10882 = v10725 + ((int)((unsigned int)(v10725 - v10724) >> 31));
    v10723[v10804] = v10882;
    int * v10727 = v10628->cache_age;
    int v10728 = v10727[v10805];
    int v10884 = v10728 + ((int)((unsigned int)(v10728 - v10724) >> 31));
    v10727[v10805] = v10884;
    int * v10730 = v10628->cache_age;
    v10730[v10875] = 0;
    v10733 = v10875;
  }
  int * v10734 = v10628->cache_vals;
  int v10887 = (v10733 * 2) + (((int)((unsigned int)(v10632 + 20) >> 2)) & 1);
  v10734[v10887] = v10633;
  int * v10736 = v10628->cache_tags;
  int v10737 = v10736[v10806];
  int v10738 = v10736[v10807];
  bool v10890 = !(((~(((v10737 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10737 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v10738 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10738 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v10792;
  if (v10890) {
    int * v10739 = v10628->cache_age;
    int v10892 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v10738 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))) | (-(v10738 ^ ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v10740 = v10739[v10892];
    int v10741 = v10739[v10806];
    int v10893 = v10741 + ((int)((unsigned int)(v10741 - v10740) >> 31));
    v10739[v10806] = v10893;
    int * v10743 = v10628->cache_age;
    int v10744 = v10743[v10807];
    int v10895 = v10744 + ((int)((unsigned int)(v10744 - v10740) >> 31));
    v10743[v10807] = v10895;
    int * v10746 = v10628->cache_age;
    v10746[v10892] = 0;
    v10792 = v10892;
  } else {
    int * v10749 = v10628->cache_age;
    int v10899 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2);
    int v10750 = v10749[v10899];
    int * v10751 = v10628->cache_tags;
    int v10752 = v10751[v10899];
    int v10753 = v10749[v10807];
    int v10754 = v10751[v10807];
    int * v10755 = v10628->cache_dirty;
    int v10902 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10750 + ((~(((v10752 ^ -1) | (-(v10752 ^ -1))) >> 31)) & 2)) - (v10753 + ((~(((v10754 ^ -1) | (-(v10754 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10756 = v10755[v10902];
    bool v10903 = !(v10756 == 0);
    if (v10903) {
      int * v10757 = v10628->cache_tags;
      int v10758 = v10757[v10902];
      int * v10759 = v10628->cache_vals;
      int v10906 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10750 + ((~(((v10752 ^ -1) | (-(v10752 ^ -1))) >> 31)) & 2)) - (v10753 + ((~(((v10754 ^ -1) | (-(v10754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v10760 = v10759[v10906];
      int v10907 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10750 + ((~(((v10752 ^ -1) | (-(v10752 ^ -1))) >> 31)) & 2)) - (v10753 + ((~(((v10754 ^ -1) | (-(v10754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v10761 = v10759[v10907];
      int * v10762 = v10628->mem;
      int v10909 = v10758 * 2;
      v10762[v10909] = v10760;
      int * v10764 = v10628->mem;
      int v10912 = (v10758 * 2) + 1;
      v10764[v10912] = v10761;
      ;
    } else {
      ;
    }
    int * v10769 = v10628->mem;
    int v10917 = ((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) * 2;
    int v10770 = v10769[v10917];
    int v10918 = (((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) * 2) + 1;
    int v10771 = v10769[v10918];
    int * v10772 = v10628->cache_vals;
    int v10920 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10750 + ((~(((v10752 ^ -1) | (-(v10752 ^ -1))) >> 31)) & 2)) - (v10753 + ((~(((v10754 ^ -1) | (-(v10754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v10772[v10920] = v10770;
    int * v10774 = v10628->cache_vals;
    int v10923 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v10750 + ((~(((v10752 ^ -1) | (-(v10752 ^ -1))) >> 31)) & 2)) - (v10753 + ((~(((v10754 ^ -1) | (-(v10754 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v10774[v10923] = v10771;
    int * v10776 = v10628->cache_tags;
    int v10926 = (int)((unsigned int)((int)((unsigned int)(v10632 + 20) >> 2)) >> 1);
    v10776[v10902] = v10926;
    int * v10778 = v10628->cache_dirty;
    v10778[v10902] = 0;
    int * v10780 = v10628->cache_age;
    v10780[v10902] = 1;
    int * v10782 = v10628->cache_age;
    int v10783 = v10782[v10902];
    int v10784 = v10782[v10806];
    int v10932 = v10784 + ((int)((unsigned int)(v10784 - v10783) >> 31));
    v10782[v10806] = v10932;
    int * v10786 = v10628->cache_age;
    int v10787 = v10786[v10807];
    int v10934 = v10787 + ((int)((unsigned int)(v10787 - v10783) >> 31));
    v10786[v10807] = v10934;
    int * v10789 = v10628->cache_age;
    v10789[v10902] = 0;
    v10792 = v10902;
  }
  int * v10793 = v10628->cache_vals;
  int v10937 = (v10792 * 2) + (((int)((unsigned int)(v10632 + 20) >> 2)) & 1);
  v10793[v10937] = v10633;
  int * v10795 = v10628->cache_dirty;
  v10795[v10792] = 1;
  struct StateT * v10797 = slot_207(v10628);
  return v10797;
}

struct StateT * slot_193(struct StateT * v8755) {
  int * v8756 = v8755->saved_regs;
  int * v8757 = v8755->regs;
  int v8758 = v8757[13];
  v8756[13] = v8758;
  int v8760 = v8755->timer;
  int v8771 = v8760 + 1;
  v8755->timer = v8771;
  int * v8762 = v8755->regs;
  int v8763 = v8762[13];
  int v8773 = v8763 + 1;
  v8762[13] = v8773;
  struct StateT * v8765 = slot_194(v8755);
  return v8765;
}

struct StateT * slot_375(struct StateT * v16716) {
  int v16717 = v16716->timer;
  int v16725 = v16717 + 1;
  v16716->timer = v16725;
  int * v16719 = v16716->regs;
  int v16720 = v16719[28];
  int v16721 = v16719[22];
  int v16729 = v16720 ^ v16721;
  v16719[28] = v16729;
  struct StateT * v16723 = slot_376(v16716);
  return v16723;
}

struct StateT * slot_331(struct StateT * v16030) {
  int v16031 = v16030->timer;
  int v16038 = v16031 + 1;
  v16030->timer = v16038;
  int * v16033 = v16030->regs;
  int v16034 = v16033[23];
  int v16041 = v16034 << 9;
  v16033[23] = v16041;
  struct StateT * v16036 = slot_332(v16030);
  return v16036;
}

struct StateT * slot_380(struct StateT * v16794) {
  int * v16795 = v16794->saved_regs;
  int * v16796 = v16794->regs;
  int v16797 = v16796[21];
  v16795[21] = v16797;
  int v16799 = v16794->timer;
  int v16811 = v16799 + 1;
  v16794->timer = v16811;
  int * v16801 = v16794->regs;
  int v16802 = v16801[29];
  int v16803 = v16801[14];
  int v16815 = v16802 + v16803;
  v16801[21] = v16815;
  struct StateT * v16805 = slot_381(v16794);
  return v16805;
}

struct StateT * slot_412(struct StateT * v17348) {
  int v17349 = v17348->timer;
  int v17356 = v17349 + 1;
  v17348->timer = v17356;
  int * v17351 = v17348->regs;
  int v17352 = v17351[23];
  int v17360 = (int)((unsigned int)v17352 >> 23);
  v17351[24] = v17360;
  struct StateT * v17354 = slot_413(v17348);
  return v17354;
}

struct StateT * slot_381(struct StateT * v16818) {
  int * v16819 = v16818->saved_regs;
  int * v16820 = v16818->regs;
  int v16821 = v16820[22];
  v16819[22] = v16821;
  int v16823 = v16818->timer;
  int v16835 = v16823 + 1;
  v16818->timer = v16835;
  int * v16825 = v16818->regs;
  int v16826 = v16825[28];
  int v16827 = v16825[12];
  int v16839 = v16826 + v16827;
  v16825[22] = v16839;
  struct StateT * v16829 = slot_382(v16818);
  return v16829;
}

struct StateT * slot_478(struct StateT * v18461) {
  int v18462 = v18461->timer;
  int v18470 = v18462 + 1;
  v18461->timer = v18470;
  int * v18464 = v18461->regs;
  int v18465 = v18464[16];
  int v18466 = v18464[23];
  int v18474 = v18465 ^ v18466;
  v18464[16] = v18474;
  struct StateT * v18468 = slot_479(v18461);
  return v18468;
}

struct StateT * slot_246(struct StateT * v14706) {
  int v14707 = v14706->timer;
  int v14715 = v14707 + 1;
  v14706->timer = v14715;
  int * v14709 = v14706->regs;
  int v14710 = v14709[21];
  int v14711 = v14709[24];
  int v14719 = v14710 | v14711;
  v14709[21] = v14719;
  struct StateT * v14713 = slot_247(v14706);
  return v14713;
}

struct StateT * slot_210(struct StateT * v12480) {
  int v12481 = v12480->timer;
  int v12488 = v12481 + 1;
  v12480->timer = v12488;
  int * v12483 = v12480->regs;
  int v12484 = v12483[20];
  int v12491 = v12484 << 7;
  v12483[20] = v12491;
  struct StateT * v12486 = slot_216(v12480);
  return v12486;
}

struct StateT * slot_472(struct StateT * v18368) {
  int v18369 = v18368->timer;
  int v18376 = v18369 + 1;
  v18368->timer = v18376;
  int * v18371 = v18368->regs;
  int v18372 = v18371[23];
  int v18380 = (int)((unsigned int)v18372 >> 25);
  v18371[24] = v18380;
  struct StateT * v18374 = slot_473(v18368);
  return v18374;
}

struct StateT * slot_284(struct StateT * v15301) {
  int v15302 = v15301->timer;
  int v15309 = v15302 + 1;
  v15301->timer = v15309;
  int * v15304 = v15301->regs;
  int v15305 = v15304[21];
  int v15313 = (int)((unsigned int)v15305 >> 14);
  v15304[24] = v15313;
  struct StateT * v15307 = slot_285(v15301);
  return v15307;
}

struct StateT * slot_52(struct StateT * v6464) {
  int * v6465 = v6464->saved_regs;
  int * v6466 = v6464->regs;
  int v6467 = v6466[8];
  v6465[8] = v6467;
  int v6469 = v6464->timer;
  int v6481 = v6469 + 1;
  v6464->timer = v6481;
  int * v6471 = v6464->regs;
  int v6472 = v6471[8];
  int v6473 = v6471[23];
  int v6484 = v6472 ^ v6473;
  v6471[8] = v6484;
  struct StateT * v6475 = slot_53(v6464);
  return v6475;
}

struct StateT * slot_83(struct StateT * v6985) {
  int v6986 = v6985->timer;
  int v6993 = v6986 + 1;
  v6985->timer = v6993;
  int * v6988 = v6985->regs;
  int v6989 = v6988[22];
  int v6997 = (int)((unsigned int)v6989 >> 19);
  v6988[24] = v6997;
  struct StateT * v6991 = slot_84(v6985);
  return v6991;
}

struct StateT * slot_209(struct StateT * v11290) {
  int v11291 = v11290->timer;
  int v11940 = v11291 + 1;
  v11290->timer = v11940;
  int * v11293 = v11290->regs;
  int v11294 = v11293[10];
  int v11295 = v11293[18];
  int * v11296 = v11290->saved_regs;
  int v11297 = v11293[8];
  v11296[8] = v11297;
  int v11299 = v11290->timer;
  int v11947 = v11299 + 1;
  v11290->timer = v11947;
  int * v11301 = v11290->regs;
  int v11302 = v11301[2];
  int * v11303 = v11290->cache_tags;
  int v11951 = (((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2;
  int v11304 = v11303[v11951];
  int v11952 = ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11305 = v11303[v11952];
  int v11953 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2);
  int v11306 = v11303[v11953];
  int v11954 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11307 = v11303[v11954];
  int v11308 = v11290->timer;
  int v11955 = v11308 + ((100 ^ (((~(((v11306 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11306 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11304 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11304 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v11305 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11305 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11306 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11306 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11290->timer = v11955;
  int * v11310 = v11290->cache_vals;
  bool v11956 = !(((~(((v11304 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11304 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v11305 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11305 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v11403;
  if (v11956) {
    int * v11311 = v11290->cache_age;
    int v11958 = ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v11305 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11305 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v11312 = v11311[v11958];
    int v11313 = v11311[v11951];
    int v11959 = v11313 + ((int)((unsigned int)(v11313 - v11312) >> 31));
    v11311[v11951] = v11959;
    int * v11315 = v11290->cache_age;
    int v11316 = v11315[v11952];
    int v11961 = v11316 + ((int)((unsigned int)(v11316 - v11312) >> 31));
    v11315[v11952] = v11961;
    int * v11318 = v11290->cache_age;
    v11318[v11958] = 0;
    v11403 = v11958;
  } else {
    int * v11321 = v11290->cache_age;
    int v11965 = (((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2;
    int v11322 = v11321[v11965];
    int * v11323 = v11290->cache_tags;
    int v11324 = v11323[v11965];
    int v11325 = v11321[v11952];
    int v11326 = v11323[v11952];
    bool v11967 = !(((~(((v11306 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11306 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v11380;
    if (v11967) {
      int * v11327 = v11290->cache_age;
      int v11969 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))) | (-(v11307 ^ ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v11328 = v11327[v11969];
      int v11329 = v11327[v11953];
      int v11970 = v11329 + ((int)((unsigned int)(v11329 - v11328) >> 31));
      v11327[v11953] = v11970;
      int * v11331 = v11290->cache_age;
      int v11332 = v11331[v11954];
      int v11972 = v11332 + ((int)((unsigned int)(v11332 - v11328) >> 31));
      v11331[v11954] = v11972;
      int * v11334 = v11290->cache_age;
      v11334[v11969] = 0;
      v11380 = v11969;
    } else {
      int * v11337 = v11290->cache_age;
      int v11976 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2);
      int v11338 = v11337[v11976];
      int * v11339 = v11290->cache_tags;
      int v11340 = v11339[v11976];
      int v11341 = v11337[v11954];
      int v11342 = v11339[v11954];
      int * v11343 = v11290->cache_dirty;
      int v11979 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v11338 + ((~(((v11340 ^ -1) | (-(v11340 ^ -1))) >> 31)) & 2)) - (v11341 + ((~(((v11342 ^ -1) | (-(v11342 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11344 = v11343[v11979];
      bool v11980 = !(v11344 == 0);
      if (v11980) {
        int * v11345 = v11290->cache_tags;
        int v11346 = v11345[v11979];
        int * v11347 = v11290->cache_vals;
        int v11983 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v11338 + ((~(((v11340 ^ -1) | (-(v11340 ^ -1))) >> 31)) & 2)) - (v11341 + ((~(((v11342 ^ -1) | (-(v11342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11348 = v11347[v11983];
        int v11984 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v11338 + ((~(((v11340 ^ -1) | (-(v11340 ^ -1))) >> 31)) & 2)) - (v11341 + ((~(((v11342 ^ -1) | (-(v11342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11349 = v11347[v11984];
        int * v11350 = v11290->mem;
        int v11986 = v11346 * 2;
        v11350[v11986] = v11348;
        int * v11352 = v11290->mem;
        int v11989 = (v11346 * 2) + 1;
        v11352[v11989] = v11349;
        ;
      } else {
        ;
      }
      int * v11357 = v11290->mem;
      int v11994 = ((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) * 2;
      int v11358 = v11357[v11994];
      int v11995 = (((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) * 2) + 1;
      int v11359 = v11357[v11995];
      int * v11360 = v11290->cache_vals;
      int v11997 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v11338 + ((~(((v11340 ^ -1) | (-(v11340 ^ -1))) >> 31)) & 2)) - (v11341 + ((~(((v11342 ^ -1) | (-(v11342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11360[v11997] = v11358;
      int * v11362 = v11290->cache_vals;
      int v12000 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v11338 + ((~(((v11340 ^ -1) | (-(v11340 ^ -1))) >> 31)) & 2)) - (v11341 + ((~(((v11342 ^ -1) | (-(v11342 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11362[v12000] = v11359;
      int * v11364 = v11290->cache_tags;
      int v12003 = (int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1);
      v11364[v11979] = v12003;
      int * v11366 = v11290->cache_dirty;
      v11366[v11979] = 0;
      int * v11368 = v11290->cache_age;
      v11368[v11979] = 1;
      int * v11370 = v11290->cache_age;
      int v11371 = v11370[v11979];
      int v11372 = v11370[v11953];
      int v12009 = v11372 + ((int)((unsigned int)(v11372 - v11371) >> 31));
      v11370[v11953] = v12009;
      int * v11374 = v11290->cache_age;
      int v11375 = v11374[v11954];
      int v12011 = v11375 + ((int)((unsigned int)(v11375 - v11371) >> 31));
      v11374[v11954] = v12011;
      int * v11377 = v11290->cache_age;
      v11377[v11979] = 0;
      v11380 = v11979;
    }
    int * v11381 = v11290->cache_vals;
    int v12014 = v11380 * 2;
    int v11382 = v11381[v12014];
    int v12015 = (v11380 * 2) + 1;
    int v11383 = v11381[v12015];
    int v12016 = (((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v11322 + ((~(((v11324 ^ -1) | (-(v11324 ^ -1))) >> 31)) & 2)) - (v11325 + ((~(((v11326 ^ -1) | (-(v11326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11381[v12016] = v11382;
    int * v11385 = v11290->cache_vals;
    int v12019 = ((((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v11322 + ((~(((v11324 ^ -1) | (-(v11324 ^ -1))) >> 31)) & 2)) - (v11325 + ((~(((v11326 ^ -1) | (-(v11326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11385[v12019] = v11383;
    int * v11387 = v11290->cache_tags;
    int v12022 = ((((int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v11322 + ((~(((v11324 ^ -1) | (-(v11324 ^ -1))) >> 31)) & 2)) - (v11325 + ((~(((v11326 ^ -1) | (-(v11326 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12023 = (int)((unsigned int)((int)((unsigned int)(v11302 + 44) >> 2)) >> 1);
    v11387[v12022] = v12023;
    int * v11389 = v11290->cache_dirty;
    v11389[v12022] = 0;
    int * v11391 = v11290->cache_age;
    v11391[v12022] = 1;
    int * v11393 = v11290->cache_age;
    int v11394 = v11393[v12022];
    int v11395 = v11393[v11951];
    int v12029 = v11395 + ((int)((unsigned int)(v11395 - v11394) >> 31));
    v11393[v11951] = v12029;
    int * v11397 = v11290->cache_age;
    int v11398 = v11397[v11952];
    int v12031 = v11398 + ((int)((unsigned int)(v11398 - v11394) >> 31));
    v11397[v11952] = v12031;
    int * v11400 = v11290->cache_age;
    v11400[v12022] = 0;
    v11403 = v12022;
  }
  int v12034 = (v11403 * 2) + (((int)((unsigned int)(v11302 + 44) >> 2)) & 1);
  int v11404 = v11310[v12034];
  int * v11405 = v11290->regs;
  v11405[8] = v11404;
  int * v11407 = v11290->saved_regs;
  int * v11408 = v11290->regs;
  int v11409 = v11408[9];
  v11407[9] = v11409;
  int v11411 = v11290->timer;
  int v12041 = v11411 + 1;
  v11290->timer = v12041;
  int * v11413 = v11290->regs;
  int v11414 = v11413[2];
  int * v11415 = v11290->cache_tags;
  int v12044 = (((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2;
  int v11416 = v11415[v12044];
  int v12045 = ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11417 = v11415[v12045];
  int v12046 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2);
  int v11418 = v11415[v12046];
  int v12047 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11419 = v11415[v12047];
  int v11420 = v11290->timer;
  int v12048 = v11420 + ((100 ^ (((~(((v11418 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11418 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11416 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11416 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11417 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11417 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11418 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11418 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11290->timer = v12048;
  int * v11422 = v11290->cache_vals;
  bool v12049 = !(((~(((v11416 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11416 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11417 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11417 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v11515;
  if (v12049) {
    int * v11423 = v11290->cache_age;
    int v12051 = ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v11417 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11417 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v11424 = v11423[v12051];
    int v11425 = v11423[v12044];
    int v12052 = v11425 + ((int)((unsigned int)(v11425 - v11424) >> 31));
    v11423[v12044] = v12052;
    int * v11427 = v11290->cache_age;
    int v11428 = v11427[v12045];
    int v12054 = v11428 + ((int)((unsigned int)(v11428 - v11424) >> 31));
    v11427[v12045] = v12054;
    int * v11430 = v11290->cache_age;
    v11430[v12051] = 0;
    v11515 = v12051;
  } else {
    int * v11433 = v11290->cache_age;
    int v12058 = (((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2;
    int v11434 = v11433[v12058];
    int * v11435 = v11290->cache_tags;
    int v11436 = v11435[v12058];
    int v11437 = v11433[v12045];
    int v11438 = v11435[v12045];
    bool v12060 = !(((~(((v11418 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11418 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v11492;
    if (v12060) {
      int * v11439 = v11290->cache_age;
      int v12062 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))) | (-(v11419 ^ ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v11440 = v11439[v12062];
      int v11441 = v11439[v12046];
      int v12063 = v11441 + ((int)((unsigned int)(v11441 - v11440) >> 31));
      v11439[v12046] = v12063;
      int * v11443 = v11290->cache_age;
      int v11444 = v11443[v12047];
      int v12065 = v11444 + ((int)((unsigned int)(v11444 - v11440) >> 31));
      v11443[v12047] = v12065;
      int * v11446 = v11290->cache_age;
      v11446[v12062] = 0;
      v11492 = v12062;
    } else {
      int * v11449 = v11290->cache_age;
      int v12069 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2);
      int v11450 = v11449[v12069];
      int * v11451 = v11290->cache_tags;
      int v11452 = v11451[v12069];
      int v11453 = v11449[v12047];
      int v11454 = v11451[v12047];
      int * v11455 = v11290->cache_dirty;
      int v12072 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11450 + ((~(((v11452 ^ -1) | (-(v11452 ^ -1))) >> 31)) & 2)) - (v11453 + ((~(((v11454 ^ -1) | (-(v11454 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11456 = v11455[v12072];
      bool v12073 = !(v11456 == 0);
      if (v12073) {
        int * v11457 = v11290->cache_tags;
        int v11458 = v11457[v12072];
        int * v11459 = v11290->cache_vals;
        int v12076 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11450 + ((~(((v11452 ^ -1) | (-(v11452 ^ -1))) >> 31)) & 2)) - (v11453 + ((~(((v11454 ^ -1) | (-(v11454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11460 = v11459[v12076];
        int v12077 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11450 + ((~(((v11452 ^ -1) | (-(v11452 ^ -1))) >> 31)) & 2)) - (v11453 + ((~(((v11454 ^ -1) | (-(v11454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11461 = v11459[v12077];
        int * v11462 = v11290->mem;
        int v12079 = v11458 * 2;
        v11462[v12079] = v11460;
        int * v11464 = v11290->mem;
        int v12082 = (v11458 * 2) + 1;
        v11464[v12082] = v11461;
        ;
      } else {
        ;
      }
      int * v11469 = v11290->mem;
      int v12087 = ((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) * 2;
      int v11470 = v11469[v12087];
      int v12088 = (((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) * 2) + 1;
      int v11471 = v11469[v12088];
      int * v11472 = v11290->cache_vals;
      int v12090 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11450 + ((~(((v11452 ^ -1) | (-(v11452 ^ -1))) >> 31)) & 2)) - (v11453 + ((~(((v11454 ^ -1) | (-(v11454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11472[v12090] = v11470;
      int * v11474 = v11290->cache_vals;
      int v12093 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v11450 + ((~(((v11452 ^ -1) | (-(v11452 ^ -1))) >> 31)) & 2)) - (v11453 + ((~(((v11454 ^ -1) | (-(v11454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11474[v12093] = v11471;
      int * v11476 = v11290->cache_tags;
      int v12096 = (int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1);
      v11476[v12072] = v12096;
      int * v11478 = v11290->cache_dirty;
      v11478[v12072] = 0;
      int * v11480 = v11290->cache_age;
      v11480[v12072] = 1;
      int * v11482 = v11290->cache_age;
      int v11483 = v11482[v12072];
      int v11484 = v11482[v12046];
      int v12102 = v11484 + ((int)((unsigned int)(v11484 - v11483) >> 31));
      v11482[v12046] = v12102;
      int * v11486 = v11290->cache_age;
      int v11487 = v11486[v12047];
      int v12104 = v11487 + ((int)((unsigned int)(v11487 - v11483) >> 31));
      v11486[v12047] = v12104;
      int * v11489 = v11290->cache_age;
      v11489[v12072] = 0;
      v11492 = v12072;
    }
    int * v11493 = v11290->cache_vals;
    int v12107 = v11492 * 2;
    int v11494 = v11493[v12107];
    int v12108 = (v11492 * 2) + 1;
    int v11495 = v11493[v12108];
    int v12109 = (((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11434 + ((~(((v11436 ^ -1) | (-(v11436 ^ -1))) >> 31)) & 2)) - (v11437 + ((~(((v11438 ^ -1) | (-(v11438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11493[v12109] = v11494;
    int * v11497 = v11290->cache_vals;
    int v12112 = ((((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11434 + ((~(((v11436 ^ -1) | (-(v11436 ^ -1))) >> 31)) & 2)) - (v11437 + ((~(((v11438 ^ -1) | (-(v11438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11497[v12112] = v11495;
    int * v11499 = v11290->cache_tags;
    int v12115 = ((((int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v11434 + ((~(((v11436 ^ -1) | (-(v11436 ^ -1))) >> 31)) & 2)) - (v11437 + ((~(((v11438 ^ -1) | (-(v11438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12116 = (int)((unsigned int)((int)((unsigned int)(v11414 + 40) >> 2)) >> 1);
    v11499[v12115] = v12116;
    int * v11501 = v11290->cache_dirty;
    v11501[v12115] = 0;
    int * v11503 = v11290->cache_age;
    v11503[v12115] = 1;
    int * v11505 = v11290->cache_age;
    int v11506 = v11505[v12115];
    int v11507 = v11505[v12044];
    int v12122 = v11507 + ((int)((unsigned int)(v11507 - v11506) >> 31));
    v11505[v12044] = v12122;
    int * v11509 = v11290->cache_age;
    int v11510 = v11509[v12045];
    int v12124 = v11510 + ((int)((unsigned int)(v11510 - v11506) >> 31));
    v11509[v12045] = v12124;
    int * v11512 = v11290->cache_age;
    v11512[v12115] = 0;
    v11515 = v12115;
  }
  int v12127 = (v11515 * 2) + (((int)((unsigned int)(v11414 + 40) >> 2)) & 1);
  int v11516 = v11422[v12127];
  int * v11517 = v11290->regs;
  v11517[9] = v11516;
  int * v11519 = v11290->saved_regs;
  int * v11520 = v11290->regs;
  int v11521 = v11520[18];
  v11519[18] = v11521;
  int v11523 = v11290->timer;
  int v12133 = v11523 + 1;
  v11290->timer = v12133;
  int * v11525 = v11290->regs;
  int v11526 = v11525[2];
  bool v12135 = (((int)((unsigned int)(v11294 + 28) >> 2)) & 3) == (((int)((unsigned int)(v11526 + 36) >> 2)) & 3);
  int v11633;
  if (v12135) {
    int v11527 = v11290->timer;
    int v12136 = v11527 + 1;
    v11290->timer = v12136;
    v11633 = v11295;
  } else {
    int * v11530 = v11290->cache_tags;
    int v12139 = (((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2;
    int v11531 = v11530[v12139];
    int v12140 = ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
    int v11532 = v11530[v12140];
    int v12141 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2);
    int v11533 = v11530[v12141];
    int v12142 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v11534 = v11530[v12142];
    int v11535 = v11290->timer;
    int v12143 = v11535 + ((100 ^ (((~(((v11533 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11533 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11531 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11531 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11532 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11532 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11533 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11533 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
    v11290->timer = v12143;
    int * v11537 = v11290->cache_vals;
    bool v12144 = !(((~(((v11531 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11531 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11532 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11532 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v11630;
    if (v12144) {
      int * v11538 = v11290->cache_age;
      int v12146 = ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v11532 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11532 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v11539 = v11538[v12146];
      int v11540 = v11538[v12139];
      int v12147 = v11540 + ((int)((unsigned int)(v11540 - v11539) >> 31));
      v11538[v12139] = v12147;
      int * v11542 = v11290->cache_age;
      int v11543 = v11542[v12140];
      int v12149 = v11543 + ((int)((unsigned int)(v11543 - v11539) >> 31));
      v11542[v12140] = v12149;
      int * v11545 = v11290->cache_age;
      v11545[v12146] = 0;
      v11630 = v12146;
    } else {
      int * v11548 = v11290->cache_age;
      int v12153 = (((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2;
      int v11549 = v11548[v12153];
      int * v11550 = v11290->cache_tags;
      int v11551 = v11550[v12153];
      int v11552 = v11548[v12140];
      int v11553 = v11550[v12140];
      bool v12155 = !(((~(((v11533 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11533 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31))) == 0);
      int v11607;
      if (v12155) {
        int * v11554 = v11290->cache_age;
        int v12157 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))) | (-(v11534 ^ ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1))))) >> 31)) & 1);
        int v11555 = v11554[v12157];
        int v11556 = v11554[v12141];
        int v12158 = v11556 + ((int)((unsigned int)(v11556 - v11555) >> 31));
        v11554[v12141] = v12158;
        int * v11558 = v11290->cache_age;
        int v11559 = v11558[v12142];
        int v12160 = v11559 + ((int)((unsigned int)(v11559 - v11555) >> 31));
        v11558[v12142] = v12160;
        int * v11561 = v11290->cache_age;
        v11561[v12157] = 0;
        v11607 = v12157;
      } else {
        int * v11564 = v11290->cache_age;
        int v12164 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2);
        int v11565 = v11564[v12164];
        int * v11566 = v11290->cache_tags;
        int v11567 = v11566[v12164];
        int v11568 = v11564[v12142];
        int v11569 = v11566[v12142];
        int * v11570 = v11290->cache_dirty;
        int v12167 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11565 + ((~(((v11567 ^ -1) | (-(v11567 ^ -1))) >> 31)) & 2)) - (v11568 + ((~(((v11569 ^ -1) | (-(v11569 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v11571 = v11570[v12167];
        bool v12168 = !(v11571 == 0);
        if (v12168) {
          int * v11572 = v11290->cache_tags;
          int v11573 = v11572[v12167];
          int * v11574 = v11290->cache_vals;
          int v12171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11565 + ((~(((v11567 ^ -1) | (-(v11567 ^ -1))) >> 31)) & 2)) - (v11568 + ((~(((v11569 ^ -1) | (-(v11569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v11575 = v11574[v12171];
          int v12172 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11565 + ((~(((v11567 ^ -1) | (-(v11567 ^ -1))) >> 31)) & 2)) - (v11568 + ((~(((v11569 ^ -1) | (-(v11569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v11576 = v11574[v12172];
          int * v11577 = v11290->mem;
          int v12174 = v11573 * 2;
          v11577[v12174] = v11575;
          int * v11579 = v11290->mem;
          int v12177 = (v11573 * 2) + 1;
          v11579[v12177] = v11576;
          ;
        } else {
          ;
        }
        int * v11584 = v11290->mem;
        int v12182 = ((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) * 2;
        int v11585 = v11584[v12182];
        int v12183 = (((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) * 2) + 1;
        int v11586 = v11584[v12183];
        int * v11587 = v11290->cache_vals;
        int v12185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11565 + ((~(((v11567 ^ -1) | (-(v11567 ^ -1))) >> 31)) & 2)) - (v11568 + ((~(((v11569 ^ -1) | (-(v11569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v11587[v12185] = v11585;
        int * v11589 = v11290->cache_vals;
        int v12188 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v11565 + ((~(((v11567 ^ -1) | (-(v11567 ^ -1))) >> 31)) & 2)) - (v11568 + ((~(((v11569 ^ -1) | (-(v11569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v11589[v12188] = v11586;
        int * v11591 = v11290->cache_tags;
        int v12191 = (int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1);
        v11591[v12167] = v12191;
        int * v11593 = v11290->cache_dirty;
        v11593[v12167] = 0;
        int * v11595 = v11290->cache_age;
        v11595[v12167] = 1;
        int * v11597 = v11290->cache_age;
        int v11598 = v11597[v12167];
        int v11599 = v11597[v12141];
        int v12197 = v11599 + ((int)((unsigned int)(v11599 - v11598) >> 31));
        v11597[v12141] = v12197;
        int * v11601 = v11290->cache_age;
        int v11602 = v11601[v12142];
        int v12199 = v11602 + ((int)((unsigned int)(v11602 - v11598) >> 31));
        v11601[v12142] = v12199;
        int * v11604 = v11290->cache_age;
        v11604[v12167] = 0;
        v11607 = v12167;
      }
      int * v11608 = v11290->cache_vals;
      int v12202 = v11607 * 2;
      int v11609 = v11608[v12202];
      int v12203 = (v11607 * 2) + 1;
      int v11610 = v11608[v12203];
      int v12204 = (((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11549 + ((~(((v11551 ^ -1) | (-(v11551 ^ -1))) >> 31)) & 2)) - (v11552 + ((~(((v11553 ^ -1) | (-(v11553 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11608[v12204] = v11609;
      int * v11612 = v11290->cache_vals;
      int v12207 = ((((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11549 + ((~(((v11551 ^ -1) | (-(v11551 ^ -1))) >> 31)) & 2)) - (v11552 + ((~(((v11553 ^ -1) | (-(v11553 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11612[v12207] = v11610;
      int * v11614 = v11290->cache_tags;
      int v12210 = ((((int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v11549 + ((~(((v11551 ^ -1) | (-(v11551 ^ -1))) >> 31)) & 2)) - (v11552 + ((~(((v11553 ^ -1) | (-(v11553 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12211 = (int)((unsigned int)((int)((unsigned int)(v11526 + 36) >> 2)) >> 1);
      v11614[v12210] = v12211;
      int * v11616 = v11290->cache_dirty;
      v11616[v12210] = 0;
      int * v11618 = v11290->cache_age;
      v11618[v12210] = 1;
      int * v11620 = v11290->cache_age;
      int v11621 = v11620[v12210];
      int v11622 = v11620[v12139];
      int v12217 = v11622 + ((int)((unsigned int)(v11622 - v11621) >> 31));
      v11620[v12139] = v12217;
      int * v11624 = v11290->cache_age;
      int v11625 = v11624[v12140];
      int v12219 = v11625 + ((int)((unsigned int)(v11625 - v11621) >> 31));
      v11624[v12140] = v12219;
      int * v11627 = v11290->cache_age;
      v11627[v12210] = 0;
      v11630 = v12210;
    }
    int v12222 = (v11630 * 2) + (((int)((unsigned int)(v11526 + 36) >> 2)) & 1);
    int v11631 = v11537[v12222];
    v11633 = v11631;
  }
  int * v11634 = v11290->regs;
  v11634[18] = v11633;
  int * v11636 = v11290->saved_regs;
  int * v11637 = v11290->regs;
  int v11638 = v11637[19];
  v11636[19] = v11638;
  int v11640 = v11290->timer;
  int v12230 = v11640 + 1;
  v11290->timer = v12230;
  int * v11642 = v11290->regs;
  int v11643 = v11642[2];
  bool v12232 = (((int)((unsigned int)(v11294 + 28) >> 2)) & 3) == (((int)((unsigned int)(v11643 + 32) >> 2)) & 3);
  int v11750;
  if (v12232) {
    int v11644 = v11290->timer;
    int v12233 = v11644 + 1;
    v11290->timer = v12233;
    v11750 = v11295;
  } else {
    int * v11647 = v11290->cache_tags;
    int v12236 = (((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2;
    int v11648 = v11647[v12236];
    int v12237 = ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
    int v11649 = v11647[v12237];
    int v12238 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2);
    int v11650 = v11647[v12238];
    int v12239 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v11651 = v11647[v12239];
    int v11652 = v11290->timer;
    int v12240 = v11652 + ((100 ^ (((~(((v11650 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11650 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11648 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11648 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11649 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11649 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11650 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11650 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
    v11290->timer = v12240;
    int * v11654 = v11290->cache_vals;
    bool v12241 = !(((~(((v11648 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11648 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11649 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11649 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v11747;
    if (v12241) {
      int * v11655 = v11290->cache_age;
      int v12243 = ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v11649 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11649 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v11656 = v11655[v12243];
      int v11657 = v11655[v12236];
      int v12244 = v11657 + ((int)((unsigned int)(v11657 - v11656) >> 31));
      v11655[v12236] = v12244;
      int * v11659 = v11290->cache_age;
      int v11660 = v11659[v12237];
      int v12246 = v11660 + ((int)((unsigned int)(v11660 - v11656) >> 31));
      v11659[v12237] = v12246;
      int * v11662 = v11290->cache_age;
      v11662[v12243] = 0;
      v11747 = v12243;
    } else {
      int * v11665 = v11290->cache_age;
      int v12250 = (((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2;
      int v11666 = v11665[v12250];
      int * v11667 = v11290->cache_tags;
      int v11668 = v11667[v12250];
      int v11669 = v11665[v12237];
      int v11670 = v11667[v12237];
      bool v12252 = !(((~(((v11650 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11650 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31))) == 0);
      int v11724;
      if (v12252) {
        int * v11671 = v11290->cache_age;
        int v12254 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))) | (-(v11651 ^ ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1))))) >> 31)) & 1);
        int v11672 = v11671[v12254];
        int v11673 = v11671[v12238];
        int v12255 = v11673 + ((int)((unsigned int)(v11673 - v11672) >> 31));
        v11671[v12238] = v12255;
        int * v11675 = v11290->cache_age;
        int v11676 = v11675[v12239];
        int v12257 = v11676 + ((int)((unsigned int)(v11676 - v11672) >> 31));
        v11675[v12239] = v12257;
        int * v11678 = v11290->cache_age;
        v11678[v12254] = 0;
        v11724 = v12254;
      } else {
        int * v11681 = v11290->cache_age;
        int v12261 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2);
        int v11682 = v11681[v12261];
        int * v11683 = v11290->cache_tags;
        int v11684 = v11683[v12261];
        int v11685 = v11681[v12239];
        int v11686 = v11683[v12239];
        int * v11687 = v11290->cache_dirty;
        int v12264 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11682 + ((~(((v11684 ^ -1) | (-(v11684 ^ -1))) >> 31)) & 2)) - (v11685 + ((~(((v11686 ^ -1) | (-(v11686 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v11688 = v11687[v12264];
        bool v12265 = !(v11688 == 0);
        if (v12265) {
          int * v11689 = v11290->cache_tags;
          int v11690 = v11689[v12264];
          int * v11691 = v11290->cache_vals;
          int v12268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11682 + ((~(((v11684 ^ -1) | (-(v11684 ^ -1))) >> 31)) & 2)) - (v11685 + ((~(((v11686 ^ -1) | (-(v11686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v11692 = v11691[v12268];
          int v12269 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11682 + ((~(((v11684 ^ -1) | (-(v11684 ^ -1))) >> 31)) & 2)) - (v11685 + ((~(((v11686 ^ -1) | (-(v11686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v11693 = v11691[v12269];
          int * v11694 = v11290->mem;
          int v12271 = v11690 * 2;
          v11694[v12271] = v11692;
          int * v11696 = v11290->mem;
          int v12274 = (v11690 * 2) + 1;
          v11696[v12274] = v11693;
          ;
        } else {
          ;
        }
        int * v11701 = v11290->mem;
        int v12279 = ((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) * 2;
        int v11702 = v11701[v12279];
        int v12280 = (((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) * 2) + 1;
        int v11703 = v11701[v12280];
        int * v11704 = v11290->cache_vals;
        int v12282 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11682 + ((~(((v11684 ^ -1) | (-(v11684 ^ -1))) >> 31)) & 2)) - (v11685 + ((~(((v11686 ^ -1) | (-(v11686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v11704[v12282] = v11702;
        int * v11706 = v11290->cache_vals;
        int v12285 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v11682 + ((~(((v11684 ^ -1) | (-(v11684 ^ -1))) >> 31)) & 2)) - (v11685 + ((~(((v11686 ^ -1) | (-(v11686 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v11706[v12285] = v11703;
        int * v11708 = v11290->cache_tags;
        int v12288 = (int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1);
        v11708[v12264] = v12288;
        int * v11710 = v11290->cache_dirty;
        v11710[v12264] = 0;
        int * v11712 = v11290->cache_age;
        v11712[v12264] = 1;
        int * v11714 = v11290->cache_age;
        int v11715 = v11714[v12264];
        int v11716 = v11714[v12238];
        int v12294 = v11716 + ((int)((unsigned int)(v11716 - v11715) >> 31));
        v11714[v12238] = v12294;
        int * v11718 = v11290->cache_age;
        int v11719 = v11718[v12239];
        int v12296 = v11719 + ((int)((unsigned int)(v11719 - v11715) >> 31));
        v11718[v12239] = v12296;
        int * v11721 = v11290->cache_age;
        v11721[v12264] = 0;
        v11724 = v12264;
      }
      int * v11725 = v11290->cache_vals;
      int v12299 = v11724 * 2;
      int v11726 = v11725[v12299];
      int v12300 = (v11724 * 2) + 1;
      int v11727 = v11725[v12300];
      int v12301 = (((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11666 + ((~(((v11668 ^ -1) | (-(v11668 ^ -1))) >> 31)) & 2)) - (v11669 + ((~(((v11670 ^ -1) | (-(v11670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11725[v12301] = v11726;
      int * v11729 = v11290->cache_vals;
      int v12304 = ((((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11666 + ((~(((v11668 ^ -1) | (-(v11668 ^ -1))) >> 31)) & 2)) - (v11669 + ((~(((v11670 ^ -1) | (-(v11670 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11729[v12304] = v11727;
      int * v11731 = v11290->cache_tags;
      int v12307 = ((((int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v11666 + ((~(((v11668 ^ -1) | (-(v11668 ^ -1))) >> 31)) & 2)) - (v11669 + ((~(((v11670 ^ -1) | (-(v11670 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12308 = (int)((unsigned int)((int)((unsigned int)(v11643 + 32) >> 2)) >> 1);
      v11731[v12307] = v12308;
      int * v11733 = v11290->cache_dirty;
      v11733[v12307] = 0;
      int * v11735 = v11290->cache_age;
      v11735[v12307] = 1;
      int * v11737 = v11290->cache_age;
      int v11738 = v11737[v12307];
      int v11739 = v11737[v12236];
      int v12314 = v11739 + ((int)((unsigned int)(v11739 - v11738) >> 31));
      v11737[v12236] = v12314;
      int * v11741 = v11290->cache_age;
      int v11742 = v11741[v12237];
      int v12316 = v11742 + ((int)((unsigned int)(v11742 - v11738) >> 31));
      v11741[v12237] = v12316;
      int * v11744 = v11290->cache_age;
      v11744[v12307] = 0;
      v11747 = v12307;
    }
    int v12319 = (v11747 * 2) + (((int)((unsigned int)(v11643 + 32) >> 2)) & 1);
    int v11748 = v11654[v12319];
    v11750 = v11748;
  }
  int * v11751 = v11290->regs;
  v11751[19] = v11750;
  int * v11753 = v11290->cache_tags;
  int v12324 = (((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2;
  int v11754 = v11753[v12324];
  int v12325 = ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11755 = v11753[v12325];
  int v12326 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2);
  int v11756 = v11753[v12326];
  int v12327 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11757 = v11753[v12327];
  int v11758 = v11290->timer;
  int v12328 = v11758 + ((100 ^ (((~(((v11756 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11756 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11754 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11754 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11755 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11755 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11756 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11756 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11290->timer = v12328;
  bool v12329 = !(((~(((v11754 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11754 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11755 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11755 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v11852;
  if (v12329) {
    int * v11760 = v11290->cache_age;
    int v12331 = ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v11755 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11755 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v11761 = v11760[v12331];
    int v11762 = v11760[v12324];
    int v12332 = v11762 + ((int)((unsigned int)(v11762 - v11761) >> 31));
    v11760[v12324] = v12332;
    int * v11764 = v11290->cache_age;
    int v11765 = v11764[v12325];
    int v12334 = v11765 + ((int)((unsigned int)(v11765 - v11761) >> 31));
    v11764[v12325] = v12334;
    int * v11767 = v11290->cache_age;
    v11767[v12331] = 0;
    v11852 = v12331;
  } else {
    int * v11770 = v11290->cache_age;
    int v12338 = (((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2;
    int v11771 = v11770[v12338];
    int * v11772 = v11290->cache_tags;
    int v11773 = v11772[v12338];
    int v11774 = v11770[v12325];
    int v11775 = v11772[v12325];
    bool v12340 = !(((~(((v11756 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11756 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v11829;
    if (v12340) {
      int * v11776 = v11290->cache_age;
      int v12342 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11757 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v11777 = v11776[v12342];
      int v11778 = v11776[v12326];
      int v12343 = v11778 + ((int)((unsigned int)(v11778 - v11777) >> 31));
      v11776[v12326] = v12343;
      int * v11780 = v11290->cache_age;
      int v11781 = v11780[v12327];
      int v12345 = v11781 + ((int)((unsigned int)(v11781 - v11777) >> 31));
      v11780[v12327] = v12345;
      int * v11783 = v11290->cache_age;
      v11783[v12342] = 0;
      v11829 = v12342;
    } else {
      int * v11786 = v11290->cache_age;
      int v12349 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2);
      int v11787 = v11786[v12349];
      int * v11788 = v11290->cache_tags;
      int v11789 = v11788[v12349];
      int v11790 = v11786[v12327];
      int v11791 = v11788[v12327];
      int * v11792 = v11290->cache_dirty;
      int v12352 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11787 + ((~(((v11789 ^ -1) | (-(v11789 ^ -1))) >> 31)) & 2)) - (v11790 + ((~(((v11791 ^ -1) | (-(v11791 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11793 = v11792[v12352];
      bool v12353 = !(v11793 == 0);
      if (v12353) {
        int * v11794 = v11290->cache_tags;
        int v11795 = v11794[v12352];
        int * v11796 = v11290->cache_vals;
        int v12356 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11787 + ((~(((v11789 ^ -1) | (-(v11789 ^ -1))) >> 31)) & 2)) - (v11790 + ((~(((v11791 ^ -1) | (-(v11791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11797 = v11796[v12356];
        int v12357 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11787 + ((~(((v11789 ^ -1) | (-(v11789 ^ -1))) >> 31)) & 2)) - (v11790 + ((~(((v11791 ^ -1) | (-(v11791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11798 = v11796[v12357];
        int * v11799 = v11290->mem;
        int v12359 = v11795 * 2;
        v11799[v12359] = v11797;
        int * v11801 = v11290->mem;
        int v12362 = (v11795 * 2) + 1;
        v11801[v12362] = v11798;
        ;
      } else {
        ;
      }
      int * v11806 = v11290->mem;
      int v12367 = ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) * 2;
      int v11807 = v11806[v12367];
      int v12368 = (((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) * 2) + 1;
      int v11808 = v11806[v12368];
      int * v11809 = v11290->cache_vals;
      int v12370 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11787 + ((~(((v11789 ^ -1) | (-(v11789 ^ -1))) >> 31)) & 2)) - (v11790 + ((~(((v11791 ^ -1) | (-(v11791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11809[v12370] = v11807;
      int * v11811 = v11290->cache_vals;
      int v12373 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11787 + ((~(((v11789 ^ -1) | (-(v11789 ^ -1))) >> 31)) & 2)) - (v11790 + ((~(((v11791 ^ -1) | (-(v11791 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11811[v12373] = v11808;
      int * v11813 = v11290->cache_tags;
      int v12376 = (int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1);
      v11813[v12352] = v12376;
      int * v11815 = v11290->cache_dirty;
      v11815[v12352] = 0;
      int * v11817 = v11290->cache_age;
      v11817[v12352] = 1;
      int * v11819 = v11290->cache_age;
      int v11820 = v11819[v12352];
      int v11821 = v11819[v12326];
      int v12382 = v11821 + ((int)((unsigned int)(v11821 - v11820) >> 31));
      v11819[v12326] = v12382;
      int * v11823 = v11290->cache_age;
      int v11824 = v11823[v12327];
      int v12384 = v11824 + ((int)((unsigned int)(v11824 - v11820) >> 31));
      v11823[v12327] = v12384;
      int * v11826 = v11290->cache_age;
      v11826[v12352] = 0;
      v11829 = v12352;
    }
    int * v11830 = v11290->cache_vals;
    int v12387 = v11829 * 2;
    int v11831 = v11830[v12387];
    int v12388 = (v11829 * 2) + 1;
    int v11832 = v11830[v12388];
    int v12389 = (((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11771 + ((~(((v11773 ^ -1) | (-(v11773 ^ -1))) >> 31)) & 2)) - (v11774 + ((~(((v11775 ^ -1) | (-(v11775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11830[v12389] = v11831;
    int * v11834 = v11290->cache_vals;
    int v12392 = ((((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11771 + ((~(((v11773 ^ -1) | (-(v11773 ^ -1))) >> 31)) & 2)) - (v11774 + ((~(((v11775 ^ -1) | (-(v11775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11834[v12392] = v11832;
    int * v11836 = v11290->cache_tags;
    int v12395 = ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v11771 + ((~(((v11773 ^ -1) | (-(v11773 ^ -1))) >> 31)) & 2)) - (v11774 + ((~(((v11775 ^ -1) | (-(v11775 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12396 = (int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1);
    v11836[v12395] = v12396;
    int * v11838 = v11290->cache_dirty;
    v11838[v12395] = 0;
    int * v11840 = v11290->cache_age;
    v11840[v12395] = 1;
    int * v11842 = v11290->cache_age;
    int v11843 = v11842[v12395];
    int v11844 = v11842[v12324];
    int v12402 = v11844 + ((int)((unsigned int)(v11844 - v11843) >> 31));
    v11842[v12324] = v12402;
    int * v11846 = v11290->cache_age;
    int v11847 = v11846[v12325];
    int v12404 = v11847 + ((int)((unsigned int)(v11847 - v11843) >> 31));
    v11846[v12325] = v12404;
    int * v11849 = v11290->cache_age;
    v11849[v12395] = 0;
    v11852 = v12395;
  }
  int * v11853 = v11290->cache_vals;
  int v12407 = (v11852 * 2) + (((int)((unsigned int)(v11294 + 28) >> 2)) & 1);
  v11853[v12407] = v11295;
  int * v11855 = v11290->cache_tags;
  int v11856 = v11855[v12326];
  int v11857 = v11855[v12327];
  bool v12410 = !(((~(((v11856 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11856 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v11857 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11857 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v11911;
  if (v12410) {
    int * v11858 = v11290->cache_age;
    int v12412 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11857 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))) | (-(v11857 ^ ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v11859 = v11858[v12412];
    int v11860 = v11858[v12326];
    int v12413 = v11860 + ((int)((unsigned int)(v11860 - v11859) >> 31));
    v11858[v12326] = v12413;
    int * v11862 = v11290->cache_age;
    int v11863 = v11862[v12327];
    int v12415 = v11863 + ((int)((unsigned int)(v11863 - v11859) >> 31));
    v11862[v12327] = v12415;
    int * v11865 = v11290->cache_age;
    v11865[v12412] = 0;
    v11911 = v12412;
  } else {
    int * v11868 = v11290->cache_age;
    int v12419 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2);
    int v11869 = v11868[v12419];
    int * v11870 = v11290->cache_tags;
    int v11871 = v11870[v12419];
    int v11872 = v11868[v12327];
    int v11873 = v11870[v12327];
    int * v11874 = v11290->cache_dirty;
    int v12422 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11869 + ((~(((v11871 ^ -1) | (-(v11871 ^ -1))) >> 31)) & 2)) - (v11872 + ((~(((v11873 ^ -1) | (-(v11873 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11875 = v11874[v12422];
    bool v12423 = !(v11875 == 0);
    if (v12423) {
      int * v11876 = v11290->cache_tags;
      int v11877 = v11876[v12422];
      int * v11878 = v11290->cache_vals;
      int v12426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11869 + ((~(((v11871 ^ -1) | (-(v11871 ^ -1))) >> 31)) & 2)) - (v11872 + ((~(((v11873 ^ -1) | (-(v11873 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11879 = v11878[v12426];
      int v12427 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11869 + ((~(((v11871 ^ -1) | (-(v11871 ^ -1))) >> 31)) & 2)) - (v11872 + ((~(((v11873 ^ -1) | (-(v11873 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11880 = v11878[v12427];
      int * v11881 = v11290->mem;
      int v12429 = v11877 * 2;
      v11881[v12429] = v11879;
      int * v11883 = v11290->mem;
      int v12432 = (v11877 * 2) + 1;
      v11883[v12432] = v11880;
      ;
    } else {
      ;
    }
    int * v11888 = v11290->mem;
    int v12437 = ((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) * 2;
    int v11889 = v11888[v12437];
    int v12438 = (((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) * 2) + 1;
    int v11890 = v11888[v12438];
    int * v11891 = v11290->cache_vals;
    int v12440 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11869 + ((~(((v11871 ^ -1) | (-(v11871 ^ -1))) >> 31)) & 2)) - (v11872 + ((~(((v11873 ^ -1) | (-(v11873 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11891[v12440] = v11889;
    int * v11893 = v11290->cache_vals;
    int v12443 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v11869 + ((~(((v11871 ^ -1) | (-(v11871 ^ -1))) >> 31)) & 2)) - (v11872 + ((~(((v11873 ^ -1) | (-(v11873 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11893[v12443] = v11890;
    int * v11895 = v11290->cache_tags;
    int v12446 = (int)((unsigned int)((int)((unsigned int)(v11294 + 28) >> 2)) >> 1);
    v11895[v12422] = v12446;
    int * v11897 = v11290->cache_dirty;
    v11897[v12422] = 0;
    int * v11899 = v11290->cache_age;
    v11899[v12422] = 1;
    int * v11901 = v11290->cache_age;
    int v11902 = v11901[v12422];
    int v11903 = v11901[v12326];
    int v12452 = v11903 + ((int)((unsigned int)(v11903 - v11902) >> 31));
    v11901[v12326] = v12452;
    int * v11905 = v11290->cache_age;
    int v11906 = v11905[v12327];
    int v12454 = v11906 + ((int)((unsigned int)(v11906 - v11902) >> 31));
    v11905[v12327] = v12454;
    int * v11908 = v11290->cache_age;
    v11908[v12422] = 0;
    v11911 = v12422;
  }
  int * v11912 = v11290->cache_vals;
  int v12457 = (v11911 * 2) + (((int)((unsigned int)(v11294 + 28) >> 2)) & 1);
  v11912[v12457] = v11295;
  int * v11914 = v11290->cache_dirty;
  v11914[v11911] = 1;
  bool v12461 = (((((int)((unsigned int)(v11302 + 44) >> 2)) == ((int)((unsigned int)(v11294 + 28) >> 2))) | (((int)((unsigned int)(v11414 + 40) >> 2)) == ((int)((unsigned int)(v11294 + 28) >> 2)))) | (((((int)((unsigned int)(v11526 + 36) >> 2)) & 3) == (((int)((unsigned int)(v11294 + 28) >> 2)) & 3)) & (!(((int)((unsigned int)(v11526 + 36) >> 2)) == ((int)((unsigned int)(v11294 + 28) >> 2)))))) | (((((int)((unsigned int)(v11643 + 32) >> 2)) & 3) == (((int)((unsigned int)(v11294 + 28) >> 2)) & 3)) & (!(((int)((unsigned int)(v11643 + 32) >> 2)) == ((int)((unsigned int)(v11294 + 28) >> 2)))));
  struct StateT * v11938;
  if (v12461) {
    int v11916 = v11290->timer;
    int v12462 = v11916 + 15;
    v11290->timer = v12462;
    int * v11918 = v11290->saved_regs;
    int v11919 = v11918[8];
    int * v11920 = v11290->regs;
    v11920[8] = v11919;
    int * v11922 = v11290->saved_regs;
    int v11923 = v11922[9];
    int * v11924 = v11290->regs;
    v11924[9] = v11923;
    int * v11926 = v11290->saved_regs;
    int v11927 = v11926[18];
    int * v11928 = v11290->regs;
    v11928[18] = v11927;
    int * v11930 = v11290->saved_regs;
    int v11931 = v11930[19];
    int * v11932 = v11290->regs;
    v11932[19] = v11931;
    struct StateT * v11934 = slot_211(v11290);
    v11938 = v11934;
  } else {
    struct StateT * v11936 = slot_215(v11290);
    v11938 = v11936;
  }
  return v11938;
}

struct StateT * slot_420(struct StateT * v17502) {
  int v17503 = v17502->timer;
  int v17511 = v17503 + 1;
  v17502->timer = v17511;
  int * v17505 = v17502->regs;
  int v17506 = v17505[7];
  int v17507 = v17505[18];
  int v17516 = v17506 + v17507;
  v17505[21] = v17516;
  struct StateT * v17509 = slot_421(v17502);
  return v17509;
}

struct StateT * slot_3(struct StateT * v646) {
  int v647 = v646->timer;
  int v817 = v647 + 1;
  v646->timer = v817;
  int * v649 = v646->regs;
  int v650 = v649[2];
  int v651 = v649[18];
  int * v652 = v646->cache_tags;
  int v822 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2;
  int v653 = v652[v822];
  int v823 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v654 = v652[v823];
  int v824 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2);
  int v655 = v652[v824];
  int v825 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v656 = v652[v825];
  int v657 = v646->timer;
  int v826 = v657 + ((100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v646->timer = v826;
  bool v827 = !(((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v751;
  if (v827) {
    int * v659 = v646->cache_age;
    int v829 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v836 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2;
    int v670 = v669[v836];
    int * v671 = v646->cache_tags;
    int v672 = v671[v836];
    int v673 = v669[v823];
    int v674 = v671[v823];
    bool v838 = !(((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v728;
    if (v838) {
      int * v675 = v646->cache_age;
      int v840 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) & 1);
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
      int v847 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2);
      int v686 = v685[v847];
      int * v687 = v646->cache_tags;
      int v688 = v687[v847];
      int v689 = v685[v825];
      int v690 = v687[v825];
      int * v691 = v646->cache_dirty;
      int v850 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v692 = v691[v850];
      bool v851 = !(v692 == 0);
      if (v851) {
        int * v693 = v646->cache_tags;
        int v694 = v693[v850];
        int * v695 = v646->cache_vals;
        int v854 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v696 = v695[v854];
        int v855 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v865 = ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2;
      int v706 = v705[v865];
      int v866 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2) + 1;
      int v707 = v705[v866];
      int * v708 = v646->cache_vals;
      int v868 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v708[v868] = v706;
      int * v710 = v646->cache_vals;
      int v871 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v710[v871] = v707;
      int * v712 = v646->cache_tags;
      int v874 = (int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1);
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
    int v887 = (((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v729[v887] = v730;
    int * v733 = v646->cache_vals;
    int v890 = ((((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v733[v890] = v731;
    int * v735 = v646->cache_tags;
    int v893 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v894 = (int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1);
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
  int v905 = (v751 * 2) + (((int)((unsigned int)(v650 + 36) >> 2)) & 1);
  v752[v905] = v651;
  int * v754 = v646->cache_tags;
  int v755 = v754[v824];
  int v756 = v754[v825];
  bool v908 = !(((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v810;
  if (v908) {
    int * v757 = v646->cache_age;
    int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2);
    int v768 = v767[v917];
    int * v769 = v646->cache_tags;
    int v770 = v769[v917];
    int v771 = v767[v825];
    int v772 = v769[v825];
    int * v773 = v646->cache_dirty;
    int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v774 = v773[v920];
    bool v921 = !(v774 == 0);
    if (v921) {
      int * v775 = v646->cache_tags;
      int v776 = v775[v920];
      int * v777 = v646->cache_vals;
      int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v778 = v777[v924];
      int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
    int v935 = ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2;
    int v788 = v787[v935];
    int v936 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2) + 1;
    int v789 = v787[v936];
    int * v790 = v646->cache_vals;
    int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v790[v938] = v788;
    int * v792 = v646->cache_vals;
    int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v792[v941] = v789;
    int * v794 = v646->cache_tags;
    int v944 = (int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1);
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
  int v955 = (v810 * 2) + (((int)((unsigned int)(v650 + 36) >> 2)) & 1);
  v811[v955] = v651;
  int * v813 = v646->cache_dirty;
  v813[v810] = 1;
  struct StateT * v815 = slot_4(v646);
  return v815;
}

struct StateT * slot_73(struct StateT * v6827) {
  int v6828 = v6827->timer;
  int v6836 = v6828 + 1;
  v6827->timer = v6836;
  int * v6830 = v6827->regs;
  int v6831 = v6830[6];
  int v6832 = v6830[9];
  int v6841 = v6831 + v6832;
  v6830[20] = v6841;
  struct StateT * v6834 = slot_74(v6827);
  return v6834;
}

struct StateT * slot_270(struct StateT * v15079) {
  int v15080 = v15079->timer;
  int v15087 = v15080 + 1;
  v15079->timer = v15087;
  int * v15082 = v15079->regs;
  int v15083 = v15082[23];
  int v15091 = (int)((unsigned int)v15083 >> 19);
  v15082[24] = v15091;
  struct StateT * v15085 = slot_271(v15079);
  return v15085;
}

struct StateT * slot_198(struct StateT * v9610) {
  int * v9611 = v9610->regs;
  int v9612 = v9611[11];
  int v9613 = v9611[13];
  bool v9625 = (v9612 ^ -2147483648) >= (v9613 ^ -2147483648);
  struct StateT * v9620;
  if (v9625) {
    int v9614 = v9610->timer;
    int v9626 = v9614 + 15;
    v9610->timer = v9626;
    struct StateT * v9616 = slot_200(v9610);
    v9620 = v9616;
  } else {
    struct StateT * v9618 = slot_195(v9610);
    v9620 = v9618;
  }
  return v9620;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v187 = v17 + 1;
  v16->timer = v187;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2;
  int v23 = v22[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v24 = v22[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2);
  int v25 = v22[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26 = v22[v195];
  int v27 = v16->timer;
  int v196 = v27 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16->timer = v196;
  bool v197 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v121;
  if (v197) {
    int * v29 = v16->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v206 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2;
    int v40 = v39[v206];
    int * v41 = v16->cache_tags;
    int v42 = v41[v206];
    int v43 = v39[v193];
    int v44 = v41[v193];
    bool v208 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v98;
    if (v208) {
      int * v45 = v16->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) & 1);
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
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2);
      int v56 = v55[v217];
      int * v57 = v16->cache_tags;
      int v58 = v57[v217];
      int v59 = v55[v195];
      int v60 = v57[v195];
      int * v61 = v16->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v62 = v61[v220];
      bool v221 = !(v62 == 0);
      if (v221) {
        int * v63 = v16->cache_tags;
        int v64 = v63[v220];
        int * v65 = v16->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66 = v65[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
      int v235 = ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2;
      int v76 = v75[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2) + 1;
      int v77 = v75[v236];
      int * v78 = v16->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v78[v238] = v76;
      int * v80 = v16->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v80[v241] = v77;
      int * v82 = v16->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1);
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
    int v257 = (((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v99[v257] = v100;
    int * v103 = v16->cache_vals;
    int v260 = ((((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v103[v260] = v101;
    int * v105 = v16->cache_tags;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v264 = (int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1);
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
  int v275 = (v121 * 2) + (((int)((unsigned int)(v20 + 44) >> 2)) & 1);
  v122[v275] = v21;
  int * v124 = v16->cache_tags;
  int v125 = v124[v194];
  int v126 = v124[v195];
  bool v278 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v180;
  if (v278) {
    int * v127 = v16->cache_age;
    int v280 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) & 1);
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
    int v287 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2);
    int v138 = v137[v287];
    int * v139 = v16->cache_tags;
    int v140 = v139[v287];
    int v141 = v137[v195];
    int v142 = v139[v195];
    int * v143 = v16->cache_dirty;
    int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v144 = v143[v290];
    bool v291 = !(v144 == 0);
    if (v291) {
      int * v145 = v16->cache_tags;
      int v146 = v145[v290];
      int * v147 = v16->cache_vals;
      int v294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v148 = v147[v294];
      int v295 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
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
    int v305 = ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2;
    int v158 = v157[v305];
    int v306 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2) + 1;
    int v159 = v157[v306];
    int * v160 = v16->cache_vals;
    int v308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v308] = v158;
    int * v162 = v16->cache_vals;
    int v311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v162[v311] = v159;
    int * v164 = v16->cache_tags;
    int v314 = (int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1);
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
  int v325 = (v180 * 2) + (((int)((unsigned int)(v20 + 44) >> 2)) & 1);
  v181[v325] = v21;
  int * v183 = v16->cache_dirty;
  v183[v180] = 1;
  struct StateT * v185 = slot_2(v16);
  return v185;
}

struct StateT * slot_187(struct StateT * v8661) {
  int v8662 = v8661->timer;
  int v8669 = v8662 + 1;
  v8661->timer = v8669;
  int * v8664 = v8661->regs;
  int v8665 = v8664[23];
  int v8672 = v8665 << 18;
  v8664[23] = v8672;
  struct StateT * v8667 = slot_188(v8661);
  return v8667;
}

struct StateT * slot_446(struct StateT * v17938) {
  int v17939 = v17938->timer;
  int v17946 = v17939 + 1;
  v17938->timer = v17946;
  int * v17941 = v17938->regs;
  int v17942 = v17941[21];
  int v17950 = (int)((unsigned int)v17942 >> 14);
  v17941[24] = v17950;
  struct StateT * v17944 = slot_447(v17938);
  return v17944;
}

struct StateT * slot_182(struct StateT * v8585) {
  int v8586 = v8585->timer;
  int v8594 = v8586 + 1;
  v8585->timer = v8594;
  int * v8588 = v8585->regs;
  int v8589 = v8588[21];
  int v8590 = v8588[24];
  int v8598 = v8589 | v8590;
  v8588[21] = v8598;
  struct StateT * v8592 = slot_183(v8585);
  return v8592;
}

struct StateT * slot_361(struct StateT * v16504) {
  int v16505 = v16504->timer;
  int v16512 = v16505 + 1;
  v16504->timer = v16512;
  int * v16507 = v16504->regs;
  int v16508 = v16507[20];
  int v16516 = (int)((unsigned int)v16508 >> 14);
  v16507[24] = v16516;
  struct StateT * v16510 = slot_362(v16504);
  return v16510;
}

struct StateT * slot_38(struct StateT * v6230) {
  int v6231 = v6230->timer;
  int v6238 = v6231 + 1;
  v6230->timer = v6238;
  int * v6233 = v6230->regs;
  int v6234 = v6233[20];
  int v6241 = v6234 << 7;
  v6233[20] = v6241;
  struct StateT * v6236 = slot_39(v6230);
  return v6236;
}

struct StateT * slot_178(struct StateT * v8526) {
  int v8527 = v8526->timer;
  int v8534 = v8527 + 1;
  v8526->timer = v8534;
  int * v8529 = v8526->regs;
  int v8530 = v8529[20];
  int v8537 = v8530 << 18;
  v8529[20] = v8537;
  struct StateT * v8532 = slot_179(v8526);
  return v8532;
}

struct StateT * slot_98(struct StateT * v7250) {
  int v7251 = v7250->timer;
  int v7258 = v7251 + 1;
  v7250->timer = v7258;
  int * v7253 = v7250->regs;
  int v7254 = v7253[20];
  int v7261 = v7254 << 18;
  v7253[20] = v7261;
  struct StateT * v7256 = slot_99(v7250);
  return v7256;
}

struct StateT * slot_159(struct StateT * v8228) {
  int v8229 = v8228->timer;
  int v8237 = v8229 + 1;
  v8228->timer = v8237;
  int * v8231 = v8228->regs;
  int v8232 = v8231[20];
  int v8233 = v8231[24];
  int v8241 = v8232 | v8233;
  v8231[20] = v8241;
  struct StateT * v8235 = slot_160(v8228);
  return v8235;
}

struct StateT * slot_510(struct StateT * v18962) {
  int v18963 = v18962->timer;
  int v18970 = v18963 + 1;
  v18962->timer = v18970;
  int * v18965 = v18962->regs;
  int v18966 = v18965[22];
  int v18973 = v18966 << 13;
  v18965[22] = v18973;
  struct StateT * v18968 = slot_511(v18962);
  return v18968;
}

struct StateT * slot_459(struct StateT * v18165) {
  int v18166 = v18165->timer;
  int v18174 = v18166 + 1;
  v18165->timer = v18174;
  int * v18168 = v18165->regs;
  int v18169 = v18168[30];
  int v18170 = v18168[8];
  int v18179 = v18169 + v18170;
  v18168[20] = v18179;
  struct StateT * v18172 = slot_460(v18165);
  return v18172;
}

struct StateT * slot_404(struct StateT * v17228) {
  int v17229 = v17228->timer;
  int v17236 = v17229 + 1;
  v17228->timer = v17236;
  int * v17231 = v17228->regs;
  int v17232 = v17231[20];
  int v17239 = v17232 << 9;
  v17231[20] = v17239;
  struct StateT * v17234 = slot_405(v17228);
  return v17234;
}

struct StateT * slot_46(struct StateT * v6350) {
  int v6351 = v6350->timer;
  int v6358 = v6351 + 1;
  v6350->timer = v6358;
  int * v6353 = v6350->regs;
  int v6354 = v6353[23];
  int v6362 = (int)((unsigned int)v6354 >> 25);
  v6353[24] = v6362;
  struct StateT * v6356 = slot_47(v6350);
  return v6356;
}

struct StateT * slot_212(struct StateT * v12918) {
  int v12919 = v12918->timer;
  int v13029 = v12919 + 1;
  v12918->timer = v13029;
  int * v12921 = v12918->regs;
  int v12922 = v12921[2];
  int * v12923 = v12918->cache_tags;
  int v13033 = (((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2;
  int v12924 = v12923[v13033];
  int v13034 = ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12925 = v12923[v13034];
  int v13035 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2);
  int v12926 = v12923[v13035];
  int v13036 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12927 = v12923[v13036];
  int v12928 = v12918->timer;
  int v13037 = v12928 + ((100 ^ (((~(((v12926 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12926 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12924 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12924 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v12925 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12925 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12926 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12926 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12918->timer = v13037;
  int * v12930 = v12918->cache_vals;
  bool v13038 = !(((~(((v12924 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12924 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v12925 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12925 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v13023;
  if (v13038) {
    int * v12931 = v12918->cache_age;
    int v13040 = ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v12925 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12925 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v12932 = v12931[v13040];
    int v12933 = v12931[v13033];
    int v13041 = v12933 + ((int)((unsigned int)(v12933 - v12932) >> 31));
    v12931[v13033] = v13041;
    int * v12935 = v12918->cache_age;
    int v12936 = v12935[v13034];
    int v13043 = v12936 + ((int)((unsigned int)(v12936 - v12932) >> 31));
    v12935[v13034] = v13043;
    int * v12938 = v12918->cache_age;
    v12938[v13040] = 0;
    v13023 = v13040;
  } else {
    int * v12941 = v12918->cache_age;
    int v13047 = (((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2;
    int v12942 = v12941[v13047];
    int * v12943 = v12918->cache_tags;
    int v12944 = v12943[v13047];
    int v12945 = v12941[v13034];
    int v12946 = v12943[v13034];
    bool v13049 = !(((~(((v12926 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12926 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v13000;
    if (v13049) {
      int * v12947 = v12918->cache_age;
      int v13051 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))) | (-(v12927 ^ ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v12948 = v12947[v13051];
      int v12949 = v12947[v13035];
      int v13052 = v12949 + ((int)((unsigned int)(v12949 - v12948) >> 31));
      v12947[v13035] = v13052;
      int * v12951 = v12918->cache_age;
      int v12952 = v12951[v13036];
      int v13054 = v12952 + ((int)((unsigned int)(v12952 - v12948) >> 31));
      v12951[v13036] = v13054;
      int * v12954 = v12918->cache_age;
      v12954[v13051] = 0;
      v13000 = v13051;
    } else {
      int * v12957 = v12918->cache_age;
      int v13058 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2);
      int v12958 = v12957[v13058];
      int * v12959 = v12918->cache_tags;
      int v12960 = v12959[v13058];
      int v12961 = v12957[v13036];
      int v12962 = v12959[v13036];
      int * v12963 = v12918->cache_dirty;
      int v13061 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v12958 + ((~(((v12960 ^ -1) | (-(v12960 ^ -1))) >> 31)) & 2)) - (v12961 + ((~(((v12962 ^ -1) | (-(v12962 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12964 = v12963[v13061];
      bool v13062 = !(v12964 == 0);
      if (v13062) {
        int * v12965 = v12918->cache_tags;
        int v12966 = v12965[v13061];
        int * v12967 = v12918->cache_vals;
        int v13065 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v12958 + ((~(((v12960 ^ -1) | (-(v12960 ^ -1))) >> 31)) & 2)) - (v12961 + ((~(((v12962 ^ -1) | (-(v12962 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12968 = v12967[v13065];
        int v13066 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v12958 + ((~(((v12960 ^ -1) | (-(v12960 ^ -1))) >> 31)) & 2)) - (v12961 + ((~(((v12962 ^ -1) | (-(v12962 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12969 = v12967[v13066];
        int * v12970 = v12918->mem;
        int v13068 = v12966 * 2;
        v12970[v13068] = v12968;
        int * v12972 = v12918->mem;
        int v13071 = (v12966 * 2) + 1;
        v12972[v13071] = v12969;
        ;
      } else {
        ;
      }
      int * v12977 = v12918->mem;
      int v13076 = ((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) * 2;
      int v12978 = v12977[v13076];
      int v13077 = (((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) * 2) + 1;
      int v12979 = v12977[v13077];
      int * v12980 = v12918->cache_vals;
      int v13079 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v12958 + ((~(((v12960 ^ -1) | (-(v12960 ^ -1))) >> 31)) & 2)) - (v12961 + ((~(((v12962 ^ -1) | (-(v12962 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12980[v13079] = v12978;
      int * v12982 = v12918->cache_vals;
      int v13082 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v12958 + ((~(((v12960 ^ -1) | (-(v12960 ^ -1))) >> 31)) & 2)) - (v12961 + ((~(((v12962 ^ -1) | (-(v12962 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12982[v13082] = v12979;
      int * v12984 = v12918->cache_tags;
      int v13085 = (int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1);
      v12984[v13061] = v13085;
      int * v12986 = v12918->cache_dirty;
      v12986[v13061] = 0;
      int * v12988 = v12918->cache_age;
      v12988[v13061] = 1;
      int * v12990 = v12918->cache_age;
      int v12991 = v12990[v13061];
      int v12992 = v12990[v13035];
      int v13091 = v12992 + ((int)((unsigned int)(v12992 - v12991) >> 31));
      v12990[v13035] = v13091;
      int * v12994 = v12918->cache_age;
      int v12995 = v12994[v13036];
      int v13093 = v12995 + ((int)((unsigned int)(v12995 - v12991) >> 31));
      v12994[v13036] = v13093;
      int * v12997 = v12918->cache_age;
      v12997[v13061] = 0;
      v13000 = v13061;
    }
    int * v13001 = v12918->cache_vals;
    int v13096 = v13000 * 2;
    int v13002 = v13001[v13096];
    int v13097 = (v13000 * 2) + 1;
    int v13003 = v13001[v13097];
    int v13098 = (((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v12942 + ((~(((v12944 ^ -1) | (-(v12944 ^ -1))) >> 31)) & 2)) - (v12945 + ((~(((v12946 ^ -1) | (-(v12946 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13001[v13098] = v13002;
    int * v13005 = v12918->cache_vals;
    int v13101 = ((((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v12942 + ((~(((v12944 ^ -1) | (-(v12944 ^ -1))) >> 31)) & 2)) - (v12945 + ((~(((v12946 ^ -1) | (-(v12946 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13005[v13101] = v13003;
    int * v13007 = v12918->cache_tags;
    int v13104 = ((((int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v12942 + ((~(((v12944 ^ -1) | (-(v12944 ^ -1))) >> 31)) & 2)) - (v12945 + ((~(((v12946 ^ -1) | (-(v12946 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13105 = (int)((unsigned int)((int)((unsigned int)(v12922 + 40) >> 2)) >> 1);
    v13007[v13104] = v13105;
    int * v13009 = v12918->cache_dirty;
    v13009[v13104] = 0;
    int * v13011 = v12918->cache_age;
    v13011[v13104] = 1;
    int * v13013 = v12918->cache_age;
    int v13014 = v13013[v13104];
    int v13015 = v13013[v13033];
    int v13111 = v13015 + ((int)((unsigned int)(v13015 - v13014) >> 31));
    v13013[v13033] = v13111;
    int * v13017 = v12918->cache_age;
    int v13018 = v13017[v13034];
    int v13113 = v13018 + ((int)((unsigned int)(v13018 - v13014) >> 31));
    v13017[v13034] = v13113;
    int * v13020 = v12918->cache_age;
    v13020[v13104] = 0;
    v13023 = v13104;
  }
  int v13116 = (v13023 * 2) + (((int)((unsigned int)(v12922 + 40) >> 2)) & 1);
  int v13024 = v12930[v13116];
  int * v13025 = v12918->regs;
  v13025[9] = v13024;
  struct StateT * v13027 = slot_213(v12918);
  return v13027;
}

struct StateT * slot_132(struct StateT * v7803) {
  int v7804 = v7803->timer;
  int v7812 = v7804 + 1;
  v7803->timer = v7812;
  int * v7806 = v7803->regs;
  int v7807 = v7806[16];
  int v7808 = v7806[23];
  int v7816 = v7807 ^ v7808;
  v7806[16] = v7816;
  struct StateT * v7810 = slot_133(v7803);
  return v7810;
}

struct StateT * slot_313(struct StateT * v15748) {
  int v15749 = v15748->timer;
  int v15757 = v15749 + 1;
  v15748->timer = v15757;
  int * v15751 = v15748->regs;
  int v15752 = v15751[14];
  int v15753 = v15751[20];
  int v15761 = v15752 ^ v15753;
  v15751[14] = v15761;
  struct StateT * v15755 = slot_314(v15748);
  return v15755;
}

struct StateT * slot_211(struct StateT * v12494) {
  int v12495 = v12494->timer;
  int v12605 = v12495 + 1;
  v12494->timer = v12605;
  int * v12497 = v12494->regs;
  int v12498 = v12497[2];
  int * v12499 = v12494->cache_tags;
  int v12609 = (((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2;
  int v12500 = v12499[v12609];
  int v12610 = ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12501 = v12499[v12610];
  int v12611 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2);
  int v12502 = v12499[v12611];
  int v12612 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12503 = v12499[v12612];
  int v12504 = v12494->timer;
  int v12613 = v12504 + ((100 ^ (((~(((v12502 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12502 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12500 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12500 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v12501 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12501 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12502 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12502 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12494->timer = v12613;
  int * v12506 = v12494->cache_vals;
  bool v12614 = !(((~(((v12500 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12500 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v12501 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12501 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v12599;
  if (v12614) {
    int * v12507 = v12494->cache_age;
    int v12616 = ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v12501 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12501 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v12508 = v12507[v12616];
    int v12509 = v12507[v12609];
    int v12617 = v12509 + ((int)((unsigned int)(v12509 - v12508) >> 31));
    v12507[v12609] = v12617;
    int * v12511 = v12494->cache_age;
    int v12512 = v12511[v12610];
    int v12619 = v12512 + ((int)((unsigned int)(v12512 - v12508) >> 31));
    v12511[v12610] = v12619;
    int * v12514 = v12494->cache_age;
    v12514[v12616] = 0;
    v12599 = v12616;
  } else {
    int * v12517 = v12494->cache_age;
    int v12623 = (((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2;
    int v12518 = v12517[v12623];
    int * v12519 = v12494->cache_tags;
    int v12520 = v12519[v12623];
    int v12521 = v12517[v12610];
    int v12522 = v12519[v12610];
    bool v12625 = !(((~(((v12502 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12502 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v12576;
    if (v12625) {
      int * v12523 = v12494->cache_age;
      int v12627 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))) | (-(v12503 ^ ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v12524 = v12523[v12627];
      int v12525 = v12523[v12611];
      int v12628 = v12525 + ((int)((unsigned int)(v12525 - v12524) >> 31));
      v12523[v12611] = v12628;
      int * v12527 = v12494->cache_age;
      int v12528 = v12527[v12612];
      int v12630 = v12528 + ((int)((unsigned int)(v12528 - v12524) >> 31));
      v12527[v12612] = v12630;
      int * v12530 = v12494->cache_age;
      v12530[v12627] = 0;
      v12576 = v12627;
    } else {
      int * v12533 = v12494->cache_age;
      int v12634 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2);
      int v12534 = v12533[v12634];
      int * v12535 = v12494->cache_tags;
      int v12536 = v12535[v12634];
      int v12537 = v12533[v12612];
      int v12538 = v12535[v12612];
      int * v12539 = v12494->cache_dirty;
      int v12637 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v12534 + ((~(((v12536 ^ -1) | (-(v12536 ^ -1))) >> 31)) & 2)) - (v12537 + ((~(((v12538 ^ -1) | (-(v12538 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12540 = v12539[v12637];
      bool v12638 = !(v12540 == 0);
      if (v12638) {
        int * v12541 = v12494->cache_tags;
        int v12542 = v12541[v12637];
        int * v12543 = v12494->cache_vals;
        int v12641 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v12534 + ((~(((v12536 ^ -1) | (-(v12536 ^ -1))) >> 31)) & 2)) - (v12537 + ((~(((v12538 ^ -1) | (-(v12538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12544 = v12543[v12641];
        int v12642 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v12534 + ((~(((v12536 ^ -1) | (-(v12536 ^ -1))) >> 31)) & 2)) - (v12537 + ((~(((v12538 ^ -1) | (-(v12538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12545 = v12543[v12642];
        int * v12546 = v12494->mem;
        int v12644 = v12542 * 2;
        v12546[v12644] = v12544;
        int * v12548 = v12494->mem;
        int v12647 = (v12542 * 2) + 1;
        v12548[v12647] = v12545;
        ;
      } else {
        ;
      }
      int * v12553 = v12494->mem;
      int v12652 = ((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) * 2;
      int v12554 = v12553[v12652];
      int v12653 = (((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) * 2) + 1;
      int v12555 = v12553[v12653];
      int * v12556 = v12494->cache_vals;
      int v12655 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v12534 + ((~(((v12536 ^ -1) | (-(v12536 ^ -1))) >> 31)) & 2)) - (v12537 + ((~(((v12538 ^ -1) | (-(v12538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12556[v12655] = v12554;
      int * v12558 = v12494->cache_vals;
      int v12658 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v12534 + ((~(((v12536 ^ -1) | (-(v12536 ^ -1))) >> 31)) & 2)) - (v12537 + ((~(((v12538 ^ -1) | (-(v12538 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12558[v12658] = v12555;
      int * v12560 = v12494->cache_tags;
      int v12661 = (int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1);
      v12560[v12637] = v12661;
      int * v12562 = v12494->cache_dirty;
      v12562[v12637] = 0;
      int * v12564 = v12494->cache_age;
      v12564[v12637] = 1;
      int * v12566 = v12494->cache_age;
      int v12567 = v12566[v12637];
      int v12568 = v12566[v12611];
      int v12667 = v12568 + ((int)((unsigned int)(v12568 - v12567) >> 31));
      v12566[v12611] = v12667;
      int * v12570 = v12494->cache_age;
      int v12571 = v12570[v12612];
      int v12669 = v12571 + ((int)((unsigned int)(v12571 - v12567) >> 31));
      v12570[v12612] = v12669;
      int * v12573 = v12494->cache_age;
      v12573[v12637] = 0;
      v12576 = v12637;
    }
    int * v12577 = v12494->cache_vals;
    int v12672 = v12576 * 2;
    int v12578 = v12577[v12672];
    int v12673 = (v12576 * 2) + 1;
    int v12579 = v12577[v12673];
    int v12674 = (((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v12518 + ((~(((v12520 ^ -1) | (-(v12520 ^ -1))) >> 31)) & 2)) - (v12521 + ((~(((v12522 ^ -1) | (-(v12522 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12577[v12674] = v12578;
    int * v12581 = v12494->cache_vals;
    int v12677 = ((((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v12518 + ((~(((v12520 ^ -1) | (-(v12520 ^ -1))) >> 31)) & 2)) - (v12521 + ((~(((v12522 ^ -1) | (-(v12522 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12581[v12677] = v12579;
    int * v12583 = v12494->cache_tags;
    int v12680 = ((((int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v12518 + ((~(((v12520 ^ -1) | (-(v12520 ^ -1))) >> 31)) & 2)) - (v12521 + ((~(((v12522 ^ -1) | (-(v12522 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12681 = (int)((unsigned int)((int)((unsigned int)(v12498 + 44) >> 2)) >> 1);
    v12583[v12680] = v12681;
    int * v12585 = v12494->cache_dirty;
    v12585[v12680] = 0;
    int * v12587 = v12494->cache_age;
    v12587[v12680] = 1;
    int * v12589 = v12494->cache_age;
    int v12590 = v12589[v12680];
    int v12591 = v12589[v12609];
    int v12687 = v12591 + ((int)((unsigned int)(v12591 - v12590) >> 31));
    v12589[v12609] = v12687;
    int * v12593 = v12494->cache_age;
    int v12594 = v12593[v12610];
    int v12689 = v12594 + ((int)((unsigned int)(v12594 - v12590) >> 31));
    v12593[v12610] = v12689;
    int * v12596 = v12494->cache_age;
    v12596[v12680] = 0;
    v12599 = v12680;
  }
  int v12692 = (v12599 * 2) + (((int)((unsigned int)(v12498 + 44) >> 2)) & 1);
  int v12600 = v12506[v12692];
  int * v12601 = v12494->regs;
  v12601[8] = v12600;
  struct StateT * v12603 = slot_212(v12494);
  return v12603;
}

struct StateT * slot_20(struct StateT * v5368) {
  int v5369 = v5368->timer;
  int v5479 = v5369 + 1;
  v5368->timer = v5479;
  int * v5371 = v5368->regs;
  int v5372 = v5371[11];
  int * v5373 = v5368->cache_tags;
  int v5483 = (((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2;
  int v5374 = v5373[v5483];
  int v5484 = ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5375 = v5373[v5484];
  int v5485 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2);
  int v5376 = v5373[v5485];
  int v5486 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5377 = v5373[v5486];
  int v5378 = v5368->timer;
  int v5487 = v5378 + ((100 ^ (((~(((v5376 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5376 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5374 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5374 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5375 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5375 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5376 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5376 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5368->timer = v5487;
  int * v5380 = v5368->cache_vals;
  bool v5488 = !(((~(((v5374 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5374 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5375 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5375 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5473;
  if (v5488) {
    int * v5381 = v5368->cache_age;
    int v5490 = ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v5375 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5375 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5382 = v5381[v5490];
    int v5383 = v5381[v5483];
    int v5491 = v5383 + ((int)((unsigned int)(v5383 - v5382) >> 31));
    v5381[v5483] = v5491;
    int * v5385 = v5368->cache_age;
    int v5386 = v5385[v5484];
    int v5493 = v5386 + ((int)((unsigned int)(v5386 - v5382) >> 31));
    v5385[v5484] = v5493;
    int * v5388 = v5368->cache_age;
    v5388[v5490] = 0;
    v5473 = v5490;
  } else {
    int * v5391 = v5368->cache_age;
    int v5497 = (((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2;
    int v5392 = v5391[v5497];
    int * v5393 = v5368->cache_tags;
    int v5394 = v5393[v5497];
    int v5395 = v5391[v5484];
    int v5396 = v5393[v5484];
    bool v5499 = !(((~(((v5376 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5376 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v5450;
    if (v5499) {
      int * v5397 = v5368->cache_age;
      int v5501 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))) | (-(v5377 ^ ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v5398 = v5397[v5501];
      int v5399 = v5397[v5485];
      int v5502 = v5399 + ((int)((unsigned int)(v5399 - v5398) >> 31));
      v5397[v5485] = v5502;
      int * v5401 = v5368->cache_age;
      int v5402 = v5401[v5486];
      int v5504 = v5402 + ((int)((unsigned int)(v5402 - v5398) >> 31));
      v5401[v5486] = v5504;
      int * v5404 = v5368->cache_age;
      v5404[v5501] = 0;
      v5450 = v5501;
    } else {
      int * v5407 = v5368->cache_age;
      int v5508 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2);
      int v5408 = v5407[v5508];
      int * v5409 = v5368->cache_tags;
      int v5410 = v5409[v5508];
      int v5411 = v5407[v5486];
      int v5412 = v5409[v5486];
      int * v5413 = v5368->cache_dirty;
      int v5511 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5408 + ((~(((v5410 ^ -1) | (-(v5410 ^ -1))) >> 31)) & 2)) - (v5411 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5414 = v5413[v5511];
      bool v5512 = !(v5414 == 0);
      if (v5512) {
        int * v5415 = v5368->cache_tags;
        int v5416 = v5415[v5511];
        int * v5417 = v5368->cache_vals;
        int v5515 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5408 + ((~(((v5410 ^ -1) | (-(v5410 ^ -1))) >> 31)) & 2)) - (v5411 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5418 = v5417[v5515];
        int v5516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5408 + ((~(((v5410 ^ -1) | (-(v5410 ^ -1))) >> 31)) & 2)) - (v5411 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5419 = v5417[v5516];
        int * v5420 = v5368->mem;
        int v5518 = v5416 * 2;
        v5420[v5518] = v5418;
        int * v5422 = v5368->mem;
        int v5521 = (v5416 * 2) + 1;
        v5422[v5521] = v5419;
        ;
      } else {
        ;
      }
      int * v5427 = v5368->mem;
      int v5526 = ((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) * 2;
      int v5428 = v5427[v5526];
      int v5527 = (((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) * 2) + 1;
      int v5429 = v5427[v5527];
      int * v5430 = v5368->cache_vals;
      int v5529 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5408 + ((~(((v5410 ^ -1) | (-(v5410 ^ -1))) >> 31)) & 2)) - (v5411 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5430[v5529] = v5428;
      int * v5432 = v5368->cache_vals;
      int v5532 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5408 + ((~(((v5410 ^ -1) | (-(v5410 ^ -1))) >> 31)) & 2)) - (v5411 + ((~(((v5412 ^ -1) | (-(v5412 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5432[v5532] = v5429;
      int * v5434 = v5368->cache_tags;
      int v5535 = (int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1);
      v5434[v5511] = v5535;
      int * v5436 = v5368->cache_dirty;
      v5436[v5511] = 0;
      int * v5438 = v5368->cache_age;
      v5438[v5511] = 1;
      int * v5440 = v5368->cache_age;
      int v5441 = v5440[v5511];
      int v5442 = v5440[v5485];
      int v5541 = v5442 + ((int)((unsigned int)(v5442 - v5441) >> 31));
      v5440[v5485] = v5541;
      int * v5444 = v5368->cache_age;
      int v5445 = v5444[v5486];
      int v5543 = v5445 + ((int)((unsigned int)(v5445 - v5441) >> 31));
      v5444[v5486] = v5543;
      int * v5447 = v5368->cache_age;
      v5447[v5511] = 0;
      v5450 = v5511;
    }
    int * v5451 = v5368->cache_vals;
    int v5546 = v5450 * 2;
    int v5452 = v5451[v5546];
    int v5547 = (v5450 * 2) + 1;
    int v5453 = v5451[v5547];
    int v5548 = (((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5392 + ((~(((v5394 ^ -1) | (-(v5394 ^ -1))) >> 31)) & 2)) - (v5395 + ((~(((v5396 ^ -1) | (-(v5396 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5451[v5548] = v5452;
    int * v5455 = v5368->cache_vals;
    int v5551 = ((((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5392 + ((~(((v5394 ^ -1) | (-(v5394 ^ -1))) >> 31)) & 2)) - (v5395 + ((~(((v5396 ^ -1) | (-(v5396 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5455[v5551] = v5453;
    int * v5457 = v5368->cache_tags;
    int v5554 = ((((int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5392 + ((~(((v5394 ^ -1) | (-(v5394 ^ -1))) >> 31)) & 2)) - (v5395 + ((~(((v5396 ^ -1) | (-(v5396 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5555 = (int)((unsigned int)((int)((unsigned int)(v5372 + 4) >> 2)) >> 1);
    v5457[v5554] = v5555;
    int * v5459 = v5368->cache_dirty;
    v5459[v5554] = 0;
    int * v5461 = v5368->cache_age;
    v5461[v5554] = 1;
    int * v5463 = v5368->cache_age;
    int v5464 = v5463[v5554];
    int v5465 = v5463[v5483];
    int v5561 = v5465 + ((int)((unsigned int)(v5465 - v5464) >> 31));
    v5463[v5483] = v5561;
    int * v5467 = v5368->cache_age;
    int v5468 = v5467[v5484];
    int v5563 = v5468 + ((int)((unsigned int)(v5468 - v5464) >> 31));
    v5467[v5484] = v5563;
    int * v5470 = v5368->cache_age;
    v5470[v5554] = 0;
    v5473 = v5554;
  }
  int v5566 = (v5473 * 2) + (((int)((unsigned int)(v5372 + 4) >> 2)) & 1);
  int v5474 = v5380[v5566];
  int * v5475 = v5368->regs;
  v5475[5] = v5474;
  struct StateT * v5477 = slot_21(v5368);
  return v5477;
}

struct StateT * slot_436(struct StateT * v17756) {
  int * v17757 = v17756->saved_regs;
  int * v17758 = v17756->regs;
  int v17759 = v17758[14];
  v17757[14] = v17759;
  int v17761 = v17756->timer;
  int v17773 = v17761 + 1;
  v17756->timer = v17773;
  int * v17763 = v17756->regs;
  int v17764 = v17763[14];
  int v17765 = v17763[21];
  int v17776 = v17764 ^ v17765;
  v17763[14] = v17776;
  struct StateT * v17767 = slot_437(v17756);
  return v17767;
}

struct StateT * slot_61(struct StateT * v6615) {
  int v6616 = v6615->timer;
  int v6623 = v6616 + 1;
  v6615->timer = v6623;
  int * v6618 = v6615->regs;
  int v6619 = v6618[21];
  int v6626 = v6619 << 9;
  v6618[21] = v6626;
  struct StateT * v6621 = slot_62(v6615);
  return v6621;
}

struct StateT * slot_499(struct StateT * v18789) {
  int v18790 = v18789->timer;
  int v18798 = v18790 + 1;
  v18789->timer = v18798;
  int * v18792 = v18789->regs;
  int v18793 = v18792[17];
  int v18794 = v18792[14];
  int v18803 = v18793 + v18794;
  v18792[20] = v18803;
  struct StateT * v18796 = slot_500(v18789);
  return v18796;
}

struct StateT * slot_359(struct StateT * v16470) {
  int v16471 = v16470->timer;
  int v16479 = v16471 + 1;
  v16470->timer = v16479;
  int * v16473 = v16470->regs;
  int v16474 = v16473[18];
  int v16475 = v16473[6];
  int v16484 = v16474 + v16475;
  v16473[22] = v16484;
  struct StateT * v16477 = slot_360(v16470);
  return v16477;
}

struct StateT * slot_514(struct StateT * v19021) {
  int v19022 = v19021->timer;
  int v19030 = v19022 + 1;
  v19021->timer = v19030;
  int * v19024 = v19021->regs;
  int v19025 = v19024[23];
  int v19026 = v19024[24];
  int v19034 = v19025 | v19026;
  v19024[23] = v19034;
  struct StateT * v19028 = slot_515(v19021);
  return v19028;
}

struct StateT * slot_296(struct StateT * v15484) {
  int v15485 = v15484->timer;
  int v15493 = v15485 + 1;
  v15484->timer = v15493;
  int * v15487 = v15484->regs;
  int v15488 = v15487[31];
  int v15489 = v15487[23];
  int v15497 = v15488 ^ v15489;
  v15487[31] = v15497;
  struct StateT * v15491 = slot_297(v15484);
  return v15491;
}

struct StateT * slot_30(struct StateT * v6077) {
  int v6078 = v6077->timer;
  int v6085 = v6078 + 1;
  v6077->timer = v6085;
  int * v6080 = v6077->regs;
  int v6081 = v6080[31];
  int v6088 = v6081 + 1396;
  v6080[31] = v6088;
  struct StateT * v6083 = slot_31(v6077);
  return v6083;
}

struct StateT * slot_18(struct StateT * v4960) {
  int v4961 = v4960->timer;
  int v5071 = v4961 + 1;
  v4960->timer = v5071;
  int * v4963 = v4960->regs;
  int v4964 = v4963[12];
  int * v4965 = v4960->cache_tags;
  int v5075 = (((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2;
  int v4966 = v4965[v5075];
  int v5076 = ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4967 = v4965[v5076];
  int v5077 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2);
  int v4968 = v4965[v5077];
  int v5078 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4969 = v4965[v5078];
  int v4970 = v4960->timer;
  int v5079 = v4970 + ((100 ^ (((~(((v4968 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4968 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4966 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4966 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4967 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4967 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4968 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4968 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4960->timer = v5079;
  int * v4972 = v4960->cache_vals;
  bool v5080 = !(((~(((v4966 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4966 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4967 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4967 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v5065;
  if (v5080) {
    int * v4973 = v4960->cache_age;
    int v5082 = ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v4967 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4967 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v4974 = v4973[v5082];
    int v4975 = v4973[v5075];
    int v5083 = v4975 + ((int)((unsigned int)(v4975 - v4974) >> 31));
    v4973[v5075] = v5083;
    int * v4977 = v4960->cache_age;
    int v4978 = v4977[v5076];
    int v5085 = v4978 + ((int)((unsigned int)(v4978 - v4974) >> 31));
    v4977[v5076] = v5085;
    int * v4980 = v4960->cache_age;
    v4980[v5082] = 0;
    v5065 = v5082;
  } else {
    int * v4983 = v4960->cache_age;
    int v5089 = (((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2;
    int v4984 = v4983[v5089];
    int * v4985 = v4960->cache_tags;
    int v4986 = v4985[v5089];
    int v4987 = v4983[v5076];
    int v4988 = v4985[v5076];
    bool v5091 = !(((~(((v4968 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4968 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v5042;
    if (v5091) {
      int * v4989 = v4960->cache_age;
      int v5093 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))) | (-(v4969 ^ ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v4990 = v4989[v5093];
      int v4991 = v4989[v5077];
      int v5094 = v4991 + ((int)((unsigned int)(v4991 - v4990) >> 31));
      v4989[v5077] = v5094;
      int * v4993 = v4960->cache_age;
      int v4994 = v4993[v5078];
      int v5096 = v4994 + ((int)((unsigned int)(v4994 - v4990) >> 31));
      v4993[v5078] = v5096;
      int * v4996 = v4960->cache_age;
      v4996[v5093] = 0;
      v5042 = v5093;
    } else {
      int * v4999 = v4960->cache_age;
      int v5100 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2);
      int v5000 = v4999[v5100];
      int * v5001 = v4960->cache_tags;
      int v5002 = v5001[v5100];
      int v5003 = v4999[v5078];
      int v5004 = v5001[v5078];
      int * v5005 = v4960->cache_dirty;
      int v5103 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5000 + ((~(((v5002 ^ -1) | (-(v5002 ^ -1))) >> 31)) & 2)) - (v5003 + ((~(((v5004 ^ -1) | (-(v5004 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5006 = v5005[v5103];
      bool v5104 = !(v5006 == 0);
      if (v5104) {
        int * v5007 = v4960->cache_tags;
        int v5008 = v5007[v5103];
        int * v5009 = v4960->cache_vals;
        int v5107 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5000 + ((~(((v5002 ^ -1) | (-(v5002 ^ -1))) >> 31)) & 2)) - (v5003 + ((~(((v5004 ^ -1) | (-(v5004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5010 = v5009[v5107];
        int v5108 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5000 + ((~(((v5002 ^ -1) | (-(v5002 ^ -1))) >> 31)) & 2)) - (v5003 + ((~(((v5004 ^ -1) | (-(v5004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5011 = v5009[v5108];
        int * v5012 = v4960->mem;
        int v5110 = v5008 * 2;
        v5012[v5110] = v5010;
        int * v5014 = v4960->mem;
        int v5113 = (v5008 * 2) + 1;
        v5014[v5113] = v5011;
        ;
      } else {
        ;
      }
      int * v5019 = v4960->mem;
      int v5118 = ((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) * 2;
      int v5020 = v5019[v5118];
      int v5119 = (((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) * 2) + 1;
      int v5021 = v5019[v5119];
      int * v5022 = v4960->cache_vals;
      int v5121 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5000 + ((~(((v5002 ^ -1) | (-(v5002 ^ -1))) >> 31)) & 2)) - (v5003 + ((~(((v5004 ^ -1) | (-(v5004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5022[v5121] = v5020;
      int * v5024 = v4960->cache_vals;
      int v5124 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5000 + ((~(((v5002 ^ -1) | (-(v5002 ^ -1))) >> 31)) & 2)) - (v5003 + ((~(((v5004 ^ -1) | (-(v5004 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5024[v5124] = v5021;
      int * v5026 = v4960->cache_tags;
      int v5127 = (int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1);
      v5026[v5103] = v5127;
      int * v5028 = v4960->cache_dirty;
      v5028[v5103] = 0;
      int * v5030 = v4960->cache_age;
      v5030[v5103] = 1;
      int * v5032 = v4960->cache_age;
      int v5033 = v5032[v5103];
      int v5034 = v5032[v5077];
      int v5133 = v5034 + ((int)((unsigned int)(v5034 - v5033) >> 31));
      v5032[v5077] = v5133;
      int * v5036 = v4960->cache_age;
      int v5037 = v5036[v5078];
      int v5135 = v5037 + ((int)((unsigned int)(v5037 - v5033) >> 31));
      v5036[v5078] = v5135;
      int * v5039 = v4960->cache_age;
      v5039[v5103] = 0;
      v5042 = v5103;
    }
    int * v5043 = v4960->cache_vals;
    int v5138 = v5042 * 2;
    int v5044 = v5043[v5138];
    int v5139 = (v5042 * 2) + 1;
    int v5045 = v5043[v5139];
    int v5140 = (((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4984 + ((~(((v4986 ^ -1) | (-(v4986 ^ -1))) >> 31)) & 2)) - (v4987 + ((~(((v4988 ^ -1) | (-(v4988 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5043[v5140] = v5044;
    int * v5047 = v4960->cache_vals;
    int v5143 = ((((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4984 + ((~(((v4986 ^ -1) | (-(v4986 ^ -1))) >> 31)) & 2)) - (v4987 + ((~(((v4988 ^ -1) | (-(v4988 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5047[v5143] = v5045;
    int * v5049 = v4960->cache_tags;
    int v5146 = ((((int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4984 + ((~(((v4986 ^ -1) | (-(v4986 ^ -1))) >> 31)) & 2)) - (v4987 + ((~(((v4988 ^ -1) | (-(v4988 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5147 = (int)((unsigned int)((int)((unsigned int)(v4964 + 28) >> 2)) >> 1);
    v5049[v5146] = v5147;
    int * v5051 = v4960->cache_dirty;
    v5051[v5146] = 0;
    int * v5053 = v4960->cache_age;
    v5053[v5146] = 1;
    int * v5055 = v4960->cache_age;
    int v5056 = v5055[v5146];
    int v5057 = v5055[v5075];
    int v5153 = v5057 + ((int)((unsigned int)(v5057 - v5056) >> 31));
    v5055[v5075] = v5153;
    int * v5059 = v4960->cache_age;
    int v5060 = v5059[v5076];
    int v5155 = v5060 + ((int)((unsigned int)(v5060 - v5056) >> 31));
    v5059[v5076] = v5155;
    int * v5062 = v4960->cache_age;
    v5062[v5146] = 0;
    v5065 = v5146;
  }
  int v5158 = (v5065 * 2) + (((int)((unsigned int)(v4964 + 28) >> 2)) & 1);
  int v5066 = v4972[v5158];
  int * v5067 = v4960->regs;
  v5067[19] = v5066;
  struct StateT * v5069 = slot_19(v4960);
  return v5069;
}

struct StateT * slot_9(struct StateT * v2536) {
  int v2537 = v2536->timer;
  int v3082 = v2537 + 1;
  v2536->timer = v3082;
  int * v2539 = v2536->regs;
  int v2540 = v2539[2];
  int v2541 = v2539[24];
  int * v2542 = v2536->saved_regs;
  int v2543 = v2539[13];
  v2542[13] = v2543;
  int v2545 = v2536->timer;
  int v3089 = v2545 + 1;
  v2536->timer = v3089;
  int * v2547 = v2536->regs;
  v2547[13] = 0;
  int * v2549 = v2536->saved_regs;
  int * v2550 = v2536->regs;
  int v2551 = v2550[14];
  v2549[14] = v2551;
  int v2553 = v2536->timer;
  int v3096 = v2553 + 1;
  v2536->timer = v3096;
  int * v2555 = v2536->regs;
  int v2556 = v2555[12];
  int * v2557 = v2536->cache_tags;
  int v3100 = (((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2;
  int v2558 = v2557[v3100];
  int v3101 = ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2559 = v2557[v3101];
  int v3102 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2);
  int v2560 = v2557[v3102];
  int v3103 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2561 = v2557[v3103];
  int v2562 = v2536->timer;
  int v3104 = v2562 + ((100 ^ (((~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) | (~(((v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) | (~(((v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) | (~(((v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2536->timer = v3104;
  int * v2564 = v2536->cache_vals;
  bool v3105 = !(((~(((v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2558 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) | (~(((v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31))) == 0);
  int v2657;
  if (v3105) {
    int * v2565 = v2536->cache_age;
    int v3107 = ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2) + ((~(((v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2559 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) & 1);
    int v2566 = v2565[v3107];
    int v2567 = v2565[v3100];
    int v3108 = v2567 + ((int)((unsigned int)(v2567 - v2566) >> 31));
    v2565[v3100] = v3108;
    int * v2569 = v2536->cache_age;
    int v2570 = v2569[v3101];
    int v3110 = v2570 + ((int)((unsigned int)(v2570 - v2566) >> 31));
    v2569[v3101] = v3110;
    int * v2572 = v2536->cache_age;
    v2572[v3107] = 0;
    v2657 = v3107;
  } else {
    int * v2575 = v2536->cache_age;
    int v3113 = (((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2;
    int v2576 = v2575[v3113];
    int * v2577 = v2536->cache_tags;
    int v2578 = v2577[v3113];
    int v2579 = v2575[v3101];
    int v2580 = v2577[v3101];
    bool v3115 = !(((~(((v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2560 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) | (~(((v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31))) == 0);
    int v2634;
    if (v3115) {
      int * v2581 = v2536->cache_age;
      int v3117 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))) | (-(v2561 ^ ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1))))) >> 31)) & 1);
      int v2582 = v2581[v3117];
      int v2583 = v2581[v3102];
      int v3118 = v2583 + ((int)((unsigned int)(v2583 - v2582) >> 31));
      v2581[v3102] = v3118;
      int * v2585 = v2536->cache_age;
      int v2586 = v2585[v3103];
      int v3120 = v2586 + ((int)((unsigned int)(v2586 - v2582) >> 31));
      v2585[v3103] = v3120;
      int * v2588 = v2536->cache_age;
      v2588[v3117] = 0;
      v2634 = v3117;
    } else {
      int * v2591 = v2536->cache_age;
      int v3123 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2);
      int v2592 = v2591[v3123];
      int * v2593 = v2536->cache_tags;
      int v2594 = v2593[v3123];
      int v2595 = v2591[v3103];
      int v2596 = v2593[v3103];
      int * v2597 = v2536->cache_dirty;
      int v3126 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + ((((v2592 + ((~(((v2594 ^ -1) | (-(v2594 ^ -1))) >> 31)) & 2)) - (v2595 + ((~(((v2596 ^ -1) | (-(v2596 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2598 = v2597[v3126];
      bool v3127 = !(v2598 == 0);
      if (v3127) {
        int * v2599 = v2536->cache_tags;
        int v2600 = v2599[v3126];
        int * v2601 = v2536->cache_vals;
        int v3130 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + ((((v2592 + ((~(((v2594 ^ -1) | (-(v2594 ^ -1))) >> 31)) & 2)) - (v2595 + ((~(((v2596 ^ -1) | (-(v2596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2602 = v2601[v3130];
        int v3131 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + ((((v2592 + ((~(((v2594 ^ -1) | (-(v2594 ^ -1))) >> 31)) & 2)) - (v2595 + ((~(((v2596 ^ -1) | (-(v2596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2603 = v2601[v3131];
        int * v2604 = v2536->mem;
        int v3133 = v2600 * 2;
        v2604[v3133] = v2602;
        int * v2606 = v2536->mem;
        int v3136 = (v2600 * 2) + 1;
        v2606[v3136] = v2603;
        ;
      } else {
        ;
      }
      int * v2611 = v2536->mem;
      int v3141 = ((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) * 2;
      int v2612 = v2611[v3141];
      int v3142 = (((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) * 2) + 1;
      int v2613 = v2611[v3142];
      int * v2614 = v2536->cache_vals;
      int v3144 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + ((((v2592 + ((~(((v2594 ^ -1) | (-(v2594 ^ -1))) >> 31)) & 2)) - (v2595 + ((~(((v2596 ^ -1) | (-(v2596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2614[v3144] = v2612;
      int * v2616 = v2536->cache_vals;
      int v3147 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 3) * 2)) + ((((v2592 + ((~(((v2594 ^ -1) | (-(v2594 ^ -1))) >> 31)) & 2)) - (v2595 + ((~(((v2596 ^ -1) | (-(v2596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2616[v3147] = v2613;
      int * v2618 = v2536->cache_tags;
      int v3150 = (int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1);
      v2618[v3126] = v3150;
      int * v2620 = v2536->cache_dirty;
      v2620[v3126] = 0;
      int * v2622 = v2536->cache_age;
      v2622[v3126] = 1;
      int * v2624 = v2536->cache_age;
      int v2625 = v2624[v3126];
      int v2626 = v2624[v3102];
      int v3155 = v2626 + ((int)((unsigned int)(v2626 - v2625) >> 31));
      v2624[v3102] = v3155;
      int * v2628 = v2536->cache_age;
      int v2629 = v2628[v3103];
      int v3157 = v2629 + ((int)((unsigned int)(v2629 - v2625) >> 31));
      v2628[v3103] = v3157;
      int * v2631 = v2536->cache_age;
      v2631[v3126] = 0;
      v2634 = v3126;
    }
    int * v2635 = v2536->cache_vals;
    int v3160 = v2634 * 2;
    int v2636 = v2635[v3160];
    int v3161 = (v2634 * 2) + 1;
    int v2637 = v2635[v3161];
    int v3162 = (((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2635[v3162] = v2636;
    int * v2639 = v2536->cache_vals;
    int v3165 = ((((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2639[v3165] = v2637;
    int * v2641 = v2536->cache_tags;
    int v3168 = ((((int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1)) & 1) * 2) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3169 = (int)((unsigned int)((int)((unsigned int)v2556 >> 2)) >> 1);
    v2641[v3168] = v3169;
    int * v2643 = v2536->cache_dirty;
    v2643[v3168] = 0;
    int * v2645 = v2536->cache_age;
    v2645[v3168] = 1;
    int * v2647 = v2536->cache_age;
    int v2648 = v2647[v3168];
    int v2649 = v2647[v3100];
    int v3174 = v2649 + ((int)((unsigned int)(v2649 - v2648) >> 31));
    v2647[v3100] = v3174;
    int * v2651 = v2536->cache_age;
    int v2652 = v2651[v3101];
    int v3176 = v2652 + ((int)((unsigned int)(v2652 - v2648) >> 31));
    v2651[v3101] = v3176;
    int * v2654 = v2536->cache_age;
    v2654[v3168] = 0;
    v2657 = v3168;
  }
  int v3179 = (v2657 * 2) + (((int)((unsigned int)v2556 >> 2)) & 1);
  int v2658 = v2564[v3179];
  int * v2659 = v2536->regs;
  v2659[14] = v2658;
  int * v2661 = v2536->saved_regs;
  int * v2662 = v2536->regs;
  int v2663 = v2662[17];
  v2661[17] = v2663;
  int v2665 = v2536->timer;
  int v3186 = v2665 + 1;
  v2536->timer = v3186;
  int * v2667 = v2536->regs;
  int v2668 = v2667[12];
  bool v3188 = (((int)((unsigned int)(v2540 + 12) >> 2)) & 3) == (((int)((unsigned int)(v2668 + 4) >> 2)) & 3);
  int v2775;
  if (v3188) {
    int v2669 = v2536->timer;
    int v3189 = v2669 + 1;
    v2536->timer = v3189;
    v2775 = v2541;
  } else {
    int * v2672 = v2536->cache_tags;
    int v3192 = (((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2673 = v2672[v3192];
    int v3193 = ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
    int v2674 = v2672[v3193];
    int v3194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2675 = v2672[v3194];
    int v3195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v2676 = v2672[v3195];
    int v2677 = v2536->timer;
    int v3196 = v2677 + ((100 ^ (((~(((v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2673 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2673 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
    v2536->timer = v3196;
    int * v2679 = v2536->cache_vals;
    bool v3197 = !(((~(((v2673 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2673 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2772;
    if (v3197) {
      int * v2680 = v2536->cache_age;
      int v3199 = ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2681 = v2680[v3199];
      int v2682 = v2680[v3192];
      int v3200 = v2682 + ((int)((unsigned int)(v2682 - v2681) >> 31));
      v2680[v3192] = v3200;
      int * v2684 = v2536->cache_age;
      int v2685 = v2684[v3193];
      int v3202 = v2685 + ((int)((unsigned int)(v2685 - v2681) >> 31));
      v2684[v3193] = v3202;
      int * v2687 = v2536->cache_age;
      v2687[v3199] = 0;
      v2772 = v3199;
    } else {
      int * v2690 = v2536->cache_age;
      int v3205 = (((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2;
      int v2691 = v2690[v3205];
      int * v2692 = v2536->cache_tags;
      int v2693 = v2692[v3205];
      int v2694 = v2690[v3193];
      int v2695 = v2692[v3193];
      bool v3207 = !(((~(((v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2675 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31))) == 0);
      int v2749;
      if (v3207) {
        int * v2696 = v2536->cache_age;
        int v3209 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))) | (-(v2676 ^ ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1))))) >> 31)) & 1);
        int v2697 = v2696[v3209];
        int v2698 = v2696[v3194];
        int v3210 = v2698 + ((int)((unsigned int)(v2698 - v2697) >> 31));
        v2696[v3194] = v3210;
        int * v2700 = v2536->cache_age;
        int v2701 = v2700[v3195];
        int v3212 = v2701 + ((int)((unsigned int)(v2701 - v2697) >> 31));
        v2700[v3195] = v3212;
        int * v2703 = v2536->cache_age;
        v2703[v3209] = 0;
        v2749 = v3209;
      } else {
        int * v2706 = v2536->cache_age;
        int v3215 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2);
        int v2707 = v2706[v3215];
        int * v2708 = v2536->cache_tags;
        int v2709 = v2708[v3215];
        int v2710 = v2706[v3195];
        int v2711 = v2708[v3195];
        int * v2712 = v2536->cache_dirty;
        int v3218 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v2713 = v2712[v3218];
        bool v3219 = !(v2713 == 0);
        if (v3219) {
          int * v2714 = v2536->cache_tags;
          int v2715 = v2714[v3218];
          int * v2716 = v2536->cache_vals;
          int v3222 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v2717 = v2716[v3222];
          int v3223 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v2718 = v2716[v3223];
          int * v2719 = v2536->mem;
          int v3225 = v2715 * 2;
          v2719[v3225] = v2717;
          int * v2721 = v2536->mem;
          int v3228 = (v2715 * 2) + 1;
          v2721[v3228] = v2718;
          ;
        } else {
          ;
        }
        int * v2726 = v2536->mem;
        int v3233 = ((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) * 2;
        int v2727 = v2726[v3233];
        int v3234 = (((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) * 2) + 1;
        int v2728 = v2726[v3234];
        int * v2729 = v2536->cache_vals;
        int v3236 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v2729[v3236] = v2727;
        int * v2731 = v2536->cache_vals;
        int v3239 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2707 + ((~(((v2709 ^ -1) | (-(v2709 ^ -1))) >> 31)) & 2)) - (v2710 + ((~(((v2711 ^ -1) | (-(v2711 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v2731[v3239] = v2728;
        int * v2733 = v2536->cache_tags;
        int v3242 = (int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1);
        v2733[v3218] = v3242;
        int * v2735 = v2536->cache_dirty;
        v2735[v3218] = 0;
        int * v2737 = v2536->cache_age;
        v2737[v3218] = 1;
        int * v2739 = v2536->cache_age;
        int v2740 = v2739[v3218];
        int v2741 = v2739[v3194];
        int v3247 = v2741 + ((int)((unsigned int)(v2741 - v2740) >> 31));
        v2739[v3194] = v3247;
        int * v2743 = v2536->cache_age;
        int v2744 = v2743[v3195];
        int v3249 = v2744 + ((int)((unsigned int)(v2744 - v2740) >> 31));
        v2743[v3195] = v3249;
        int * v2746 = v2536->cache_age;
        v2746[v3218] = 0;
        v2749 = v3218;
      }
      int * v2750 = v2536->cache_vals;
      int v3252 = v2749 * 2;
      int v2751 = v2750[v3252];
      int v3253 = (v2749 * 2) + 1;
      int v2752 = v2750[v3253];
      int v3254 = (((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2691 + ((~(((v2693 ^ -1) | (-(v2693 ^ -1))) >> 31)) & 2)) - (v2694 + ((~(((v2695 ^ -1) | (-(v2695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2750[v3254] = v2751;
      int * v2754 = v2536->cache_vals;
      int v3257 = ((((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2691 + ((~(((v2693 ^ -1) | (-(v2693 ^ -1))) >> 31)) & 2)) - (v2694 + ((~(((v2695 ^ -1) | (-(v2695 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2754[v3257] = v2752;
      int * v2756 = v2536->cache_tags;
      int v3260 = ((((int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2691 + ((~(((v2693 ^ -1) | (-(v2693 ^ -1))) >> 31)) & 2)) - (v2694 + ((~(((v2695 ^ -1) | (-(v2695 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3261 = (int)((unsigned int)((int)((unsigned int)(v2668 + 4) >> 2)) >> 1);
      v2756[v3260] = v3261;
      int * v2758 = v2536->cache_dirty;
      v2758[v3260] = 0;
      int * v2760 = v2536->cache_age;
      v2760[v3260] = 1;
      int * v2762 = v2536->cache_age;
      int v2763 = v2762[v3260];
      int v2764 = v2762[v3192];
      int v3266 = v2764 + ((int)((unsigned int)(v2764 - v2763) >> 31));
      v2762[v3192] = v3266;
      int * v2766 = v2536->cache_age;
      int v2767 = v2766[v3193];
      int v3268 = v2767 + ((int)((unsigned int)(v2767 - v2763) >> 31));
      v2766[v3193] = v3268;
      int * v2769 = v2536->cache_age;
      v2769[v3260] = 0;
      v2772 = v3260;
    }
    int v3271 = (v2772 * 2) + (((int)((unsigned int)(v2668 + 4) >> 2)) & 1);
    int v2773 = v2679[v3271];
    v2775 = v2773;
  }
  int * v2776 = v2536->regs;
  v2776[17] = v2775;
  int * v2778 = v2536->saved_regs;
  int * v2779 = v2536->regs;
  int v2780 = v2779[8];
  v2778[8] = v2780;
  int v2782 = v2536->timer;
  int v3279 = v2782 + 1;
  v2536->timer = v3279;
  int * v2784 = v2536->regs;
  int v2785 = v2784[12];
  bool v3281 = (((int)((unsigned int)(v2540 + 12) >> 2)) & 3) == (((int)((unsigned int)(v2785 + 8) >> 2)) & 3);
  int v2892;
  if (v3281) {
    int v2786 = v2536->timer;
    int v3282 = v2786 + 1;
    v2536->timer = v3282;
    v2892 = v2541;
  } else {
    int * v2789 = v2536->cache_tags;
    int v3285 = (((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2790 = v2789[v3285];
    int v3286 = ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
    int v2791 = v2789[v3286];
    int v3287 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2);
    int v2792 = v2789[v3287];
    int v3288 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
    int v2793 = v2789[v3288];
    int v2794 = v2536->timer;
    int v3289 = v2794 + ((100 ^ (((~(((v2792 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2792 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2790 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2790 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2791 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2791 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2792 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2792 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
    v2536->timer = v3289;
    int * v2796 = v2536->cache_vals;
    bool v3290 = !(((~(((v2790 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2790 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2791 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2791 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2889;
    if (v3290) {
      int * v2797 = v2536->cache_age;
      int v3292 = ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2791 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2791 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2798 = v2797[v3292];
      int v2799 = v2797[v3285];
      int v3293 = v2799 + ((int)((unsigned int)(v2799 - v2798) >> 31));
      v2797[v3285] = v3293;
      int * v2801 = v2536->cache_age;
      int v2802 = v2801[v3286];
      int v3295 = v2802 + ((int)((unsigned int)(v2802 - v2798) >> 31));
      v2801[v3286] = v3295;
      int * v2804 = v2536->cache_age;
      v2804[v3292] = 0;
      v2889 = v3292;
    } else {
      int * v2807 = v2536->cache_age;
      int v3298 = (((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2;
      int v2808 = v2807[v3298];
      int * v2809 = v2536->cache_tags;
      int v2810 = v2809[v3298];
      int v2811 = v2807[v3286];
      int v2812 = v2809[v3286];
      bool v3300 = !(((~(((v2792 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2792 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31))) == 0);
      int v2866;
      if (v3300) {
        int * v2813 = v2536->cache_age;
        int v3302 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))) | (-(v2793 ^ ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1))))) >> 31)) & 1);
        int v2814 = v2813[v3302];
        int v2815 = v2813[v3287];
        int v3303 = v2815 + ((int)((unsigned int)(v2815 - v2814) >> 31));
        v2813[v3287] = v3303;
        int * v2817 = v2536->cache_age;
        int v2818 = v2817[v3288];
        int v3305 = v2818 + ((int)((unsigned int)(v2818 - v2814) >> 31));
        v2817[v3288] = v3305;
        int * v2820 = v2536->cache_age;
        v2820[v3302] = 0;
        v2866 = v3302;
      } else {
        int * v2823 = v2536->cache_age;
        int v3308 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2);
        int v2824 = v2823[v3308];
        int * v2825 = v2536->cache_tags;
        int v2826 = v2825[v3308];
        int v2827 = v2823[v3288];
        int v2828 = v2825[v3288];
        int * v2829 = v2536->cache_dirty;
        int v3311 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2824 + ((~(((v2826 ^ -1) | (-(v2826 ^ -1))) >> 31)) & 2)) - (v2827 + ((~(((v2828 ^ -1) | (-(v2828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v2830 = v2829[v3311];
        bool v3312 = !(v2830 == 0);
        if (v3312) {
          int * v2831 = v2536->cache_tags;
          int v2832 = v2831[v3311];
          int * v2833 = v2536->cache_vals;
          int v3315 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2824 + ((~(((v2826 ^ -1) | (-(v2826 ^ -1))) >> 31)) & 2)) - (v2827 + ((~(((v2828 ^ -1) | (-(v2828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v2834 = v2833[v3315];
          int v3316 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2824 + ((~(((v2826 ^ -1) | (-(v2826 ^ -1))) >> 31)) & 2)) - (v2827 + ((~(((v2828 ^ -1) | (-(v2828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v2835 = v2833[v3316];
          int * v2836 = v2536->mem;
          int v3318 = v2832 * 2;
          v2836[v3318] = v2834;
          int * v2838 = v2536->mem;
          int v3321 = (v2832 * 2) + 1;
          v2838[v3321] = v2835;
          ;
        } else {
          ;
        }
        int * v2843 = v2536->mem;
        int v3326 = ((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) * 2;
        int v2844 = v2843[v3326];
        int v3327 = (((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) * 2) + 1;
        int v2845 = v2843[v3327];
        int * v2846 = v2536->cache_vals;
        int v3329 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2824 + ((~(((v2826 ^ -1) | (-(v2826 ^ -1))) >> 31)) & 2)) - (v2827 + ((~(((v2828 ^ -1) | (-(v2828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v2846[v3329] = v2844;
        int * v2848 = v2536->cache_vals;
        int v3332 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2824 + ((~(((v2826 ^ -1) | (-(v2826 ^ -1))) >> 31)) & 2)) - (v2827 + ((~(((v2828 ^ -1) | (-(v2828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v2848[v3332] = v2845;
        int * v2850 = v2536->cache_tags;
        int v3335 = (int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1);
        v2850[v3311] = v3335;
        int * v2852 = v2536->cache_dirty;
        v2852[v3311] = 0;
        int * v2854 = v2536->cache_age;
        v2854[v3311] = 1;
        int * v2856 = v2536->cache_age;
        int v2857 = v2856[v3311];
        int v2858 = v2856[v3287];
        int v3340 = v2858 + ((int)((unsigned int)(v2858 - v2857) >> 31));
        v2856[v3287] = v3340;
        int * v2860 = v2536->cache_age;
        int v2861 = v2860[v3288];
        int v3342 = v2861 + ((int)((unsigned int)(v2861 - v2857) >> 31));
        v2860[v3288] = v3342;
        int * v2863 = v2536->cache_age;
        v2863[v3311] = 0;
        v2866 = v3311;
      }
      int * v2867 = v2536->cache_vals;
      int v3345 = v2866 * 2;
      int v2868 = v2867[v3345];
      int v3346 = (v2866 * 2) + 1;
      int v2869 = v2867[v3346];
      int v3347 = (((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2808 + ((~(((v2810 ^ -1) | (-(v2810 ^ -1))) >> 31)) & 2)) - (v2811 + ((~(((v2812 ^ -1) | (-(v2812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2867[v3347] = v2868;
      int * v2871 = v2536->cache_vals;
      int v3350 = ((((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2808 + ((~(((v2810 ^ -1) | (-(v2810 ^ -1))) >> 31)) & 2)) - (v2811 + ((~(((v2812 ^ -1) | (-(v2812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2871[v3350] = v2869;
      int * v2873 = v2536->cache_tags;
      int v3353 = ((((int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2808 + ((~(((v2810 ^ -1) | (-(v2810 ^ -1))) >> 31)) & 2)) - (v2811 + ((~(((v2812 ^ -1) | (-(v2812 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3354 = (int)((unsigned int)((int)((unsigned int)(v2785 + 8) >> 2)) >> 1);
      v2873[v3353] = v3354;
      int * v2875 = v2536->cache_dirty;
      v2875[v3353] = 0;
      int * v2877 = v2536->cache_age;
      v2877[v3353] = 1;
      int * v2879 = v2536->cache_age;
      int v2880 = v2879[v3353];
      int v2881 = v2879[v3285];
      int v3359 = v2881 + ((int)((unsigned int)(v2881 - v2880) >> 31));
      v2879[v3285] = v3359;
      int * v2883 = v2536->cache_age;
      int v2884 = v2883[v3286];
      int v3361 = v2884 + ((int)((unsigned int)(v2884 - v2880) >> 31));
      v2883[v3286] = v3361;
      int * v2886 = v2536->cache_age;
      v2886[v3353] = 0;
      v2889 = v3353;
    }
    int v3364 = (v2889 * 2) + (((int)((unsigned int)(v2785 + 8) >> 2)) & 1);
    int v2890 = v2796[v3364];
    v2892 = v2890;
  }
  int * v2893 = v2536->regs;
  v2893[8] = v2892;
  int * v2895 = v2536->cache_tags;
  int v3369 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2896 = v2895[v3369];
  int v3370 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2897 = v2895[v3370];
  int v3371 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2898 = v2895[v3371];
  int v3372 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2899 = v2895[v3372];
  int v2900 = v2536->timer;
  int v3373 = v2900 + ((100 ^ (((~(((v2898 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2898 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2896 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2896 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2897 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2897 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2898 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2898 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2536->timer = v3373;
  bool v3374 = !(((~(((v2896 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2896 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2897 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2897 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2994;
  if (v3374) {
    int * v2902 = v2536->cache_age;
    int v3376 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2897 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2897 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2903 = v2902[v3376];
    int v2904 = v2902[v3369];
    int v3377 = v2904 + ((int)((unsigned int)(v2904 - v2903) >> 31));
    v2902[v3369] = v3377;
    int * v2906 = v2536->cache_age;
    int v2907 = v2906[v3370];
    int v3379 = v2907 + ((int)((unsigned int)(v2907 - v2903) >> 31));
    v2906[v3370] = v3379;
    int * v2909 = v2536->cache_age;
    v2909[v3376] = 0;
    v2994 = v3376;
  } else {
    int * v2912 = v2536->cache_age;
    int v3382 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2913 = v2912[v3382];
    int * v2914 = v2536->cache_tags;
    int v2915 = v2914[v3382];
    int v2916 = v2912[v3370];
    int v2917 = v2914[v3370];
    bool v3384 = !(((~(((v2898 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2898 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v2971;
    if (v3384) {
      int * v2918 = v2536->cache_age;
      int v3386 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2899 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2919 = v2918[v3386];
      int v2920 = v2918[v3371];
      int v3387 = v2920 + ((int)((unsigned int)(v2920 - v2919) >> 31));
      v2918[v3371] = v3387;
      int * v2922 = v2536->cache_age;
      int v2923 = v2922[v3372];
      int v3389 = v2923 + ((int)((unsigned int)(v2923 - v2919) >> 31));
      v2922[v3372] = v3389;
      int * v2925 = v2536->cache_age;
      v2925[v3386] = 0;
      v2971 = v3386;
    } else {
      int * v2928 = v2536->cache_age;
      int v3392 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
      int v2929 = v2928[v3392];
      int * v2930 = v2536->cache_tags;
      int v2931 = v2930[v3392];
      int v2932 = v2928[v3372];
      int v2933 = v2930[v3372];
      int * v2934 = v2536->cache_dirty;
      int v3395 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2929 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2)) - (v2932 + ((~(((v2933 ^ -1) | (-(v2933 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2935 = v2934[v3395];
      bool v3396 = !(v2935 == 0);
      if (v3396) {
        int * v2936 = v2536->cache_tags;
        int v2937 = v2936[v3395];
        int * v2938 = v2536->cache_vals;
        int v3399 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2929 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2)) - (v2932 + ((~(((v2933 ^ -1) | (-(v2933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2939 = v2938[v3399];
        int v3400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2929 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2)) - (v2932 + ((~(((v2933 ^ -1) | (-(v2933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2940 = v2938[v3400];
        int * v2941 = v2536->mem;
        int v3402 = v2937 * 2;
        v2941[v3402] = v2939;
        int * v2943 = v2536->mem;
        int v3405 = (v2937 * 2) + 1;
        v2943[v3405] = v2940;
        ;
      } else {
        ;
      }
      int * v2948 = v2536->mem;
      int v3410 = ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2;
      int v2949 = v2948[v3410];
      int v3411 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2) + 1;
      int v2950 = v2948[v3411];
      int * v2951 = v2536->cache_vals;
      int v3413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2929 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2)) - (v2932 + ((~(((v2933 ^ -1) | (-(v2933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2951[v3413] = v2949;
      int * v2953 = v2536->cache_vals;
      int v3416 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2929 + ((~(((v2931 ^ -1) | (-(v2931 ^ -1))) >> 31)) & 2)) - (v2932 + ((~(((v2933 ^ -1) | (-(v2933 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2953[v3416] = v2950;
      int * v2955 = v2536->cache_tags;
      int v3419 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
      v2955[v3395] = v3419;
      int * v2957 = v2536->cache_dirty;
      v2957[v3395] = 0;
      int * v2959 = v2536->cache_age;
      v2959[v3395] = 1;
      int * v2961 = v2536->cache_age;
      int v2962 = v2961[v3395];
      int v2963 = v2961[v3371];
      int v3424 = v2963 + ((int)((unsigned int)(v2963 - v2962) >> 31));
      v2961[v3371] = v3424;
      int * v2965 = v2536->cache_age;
      int v2966 = v2965[v3372];
      int v3426 = v2966 + ((int)((unsigned int)(v2966 - v2962) >> 31));
      v2965[v3372] = v3426;
      int * v2968 = v2536->cache_age;
      v2968[v3395] = 0;
      v2971 = v3395;
    }
    int * v2972 = v2536->cache_vals;
    int v3429 = v2971 * 2;
    int v2973 = v2972[v3429];
    int v3430 = (v2971 * 2) + 1;
    int v2974 = v2972[v3430];
    int v3431 = (((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2913 + ((~(((v2915 ^ -1) | (-(v2915 ^ -1))) >> 31)) & 2)) - (v2916 + ((~(((v2917 ^ -1) | (-(v2917 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2972[v3431] = v2973;
    int * v2976 = v2536->cache_vals;
    int v3434 = ((((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2913 + ((~(((v2915 ^ -1) | (-(v2915 ^ -1))) >> 31)) & 2)) - (v2916 + ((~(((v2917 ^ -1) | (-(v2917 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2976[v3434] = v2974;
    int * v2978 = v2536->cache_tags;
    int v3437 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2913 + ((~(((v2915 ^ -1) | (-(v2915 ^ -1))) >> 31)) & 2)) - (v2916 + ((~(((v2917 ^ -1) | (-(v2917 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3438 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
    v2978[v3437] = v3438;
    int * v2980 = v2536->cache_dirty;
    v2980[v3437] = 0;
    int * v2982 = v2536->cache_age;
    v2982[v3437] = 1;
    int * v2984 = v2536->cache_age;
    int v2985 = v2984[v3437];
    int v2986 = v2984[v3369];
    int v3443 = v2986 + ((int)((unsigned int)(v2986 - v2985) >> 31));
    v2984[v3369] = v3443;
    int * v2988 = v2536->cache_age;
    int v2989 = v2988[v3370];
    int v3445 = v2989 + ((int)((unsigned int)(v2989 - v2985) >> 31));
    v2988[v3370] = v3445;
    int * v2991 = v2536->cache_age;
    v2991[v3437] = 0;
    v2994 = v3437;
  }
  int * v2995 = v2536->cache_vals;
  int v3448 = (v2994 * 2) + (((int)((unsigned int)(v2540 + 12) >> 2)) & 1);
  v2995[v3448] = v2541;
  int * v2997 = v2536->cache_tags;
  int v2998 = v2997[v3371];
  int v2999 = v2997[v3372];
  bool v3451 = !(((~(((v2998 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2998 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2999 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2999 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3053;
  if (v3451) {
    int * v3000 = v2536->cache_age;
    int v3453 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2999 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2999 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3001 = v3000[v3453];
    int v3002 = v3000[v3371];
    int v3454 = v3002 + ((int)((unsigned int)(v3002 - v3001) >> 31));
    v3000[v3371] = v3454;
    int * v3004 = v2536->cache_age;
    int v3005 = v3004[v3372];
    int v3456 = v3005 + ((int)((unsigned int)(v3005 - v3001) >> 31));
    v3004[v3372] = v3456;
    int * v3007 = v2536->cache_age;
    v3007[v3453] = 0;
    v3053 = v3453;
  } else {
    int * v3010 = v2536->cache_age;
    int v3459 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
    int v3011 = v3010[v3459];
    int * v3012 = v2536->cache_tags;
    int v3013 = v3012[v3459];
    int v3014 = v3010[v3372];
    int v3015 = v3012[v3372];
    int * v3016 = v2536->cache_dirty;
    int v3462 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3011 + ((~(((v3013 ^ -1) | (-(v3013 ^ -1))) >> 31)) & 2)) - (v3014 + ((~(((v3015 ^ -1) | (-(v3015 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3017 = v3016[v3462];
    bool v3463 = !(v3017 == 0);
    if (v3463) {
      int * v3018 = v2536->cache_tags;
      int v3019 = v3018[v3462];
      int * v3020 = v2536->cache_vals;
      int v3466 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3011 + ((~(((v3013 ^ -1) | (-(v3013 ^ -1))) >> 31)) & 2)) - (v3014 + ((~(((v3015 ^ -1) | (-(v3015 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3021 = v3020[v3466];
      int v3467 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3011 + ((~(((v3013 ^ -1) | (-(v3013 ^ -1))) >> 31)) & 2)) - (v3014 + ((~(((v3015 ^ -1) | (-(v3015 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3022 = v3020[v3467];
      int * v3023 = v2536->mem;
      int v3469 = v3019 * 2;
      v3023[v3469] = v3021;
      int * v3025 = v2536->mem;
      int v3472 = (v3019 * 2) + 1;
      v3025[v3472] = v3022;
      ;
    } else {
      ;
    }
    int * v3030 = v2536->mem;
    int v3477 = ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2;
    int v3031 = v3030[v3477];
    int v3478 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2) + 1;
    int v3032 = v3030[v3478];
    int * v3033 = v2536->cache_vals;
    int v3480 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3011 + ((~(((v3013 ^ -1) | (-(v3013 ^ -1))) >> 31)) & 2)) - (v3014 + ((~(((v3015 ^ -1) | (-(v3015 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3033[v3480] = v3031;
    int * v3035 = v2536->cache_vals;
    int v3483 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3011 + ((~(((v3013 ^ -1) | (-(v3013 ^ -1))) >> 31)) & 2)) - (v3014 + ((~(((v3015 ^ -1) | (-(v3015 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3035[v3483] = v3032;
    int * v3037 = v2536->cache_tags;
    int v3486 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
    v3037[v3462] = v3486;
    int * v3039 = v2536->cache_dirty;
    v3039[v3462] = 0;
    int * v3041 = v2536->cache_age;
    v3041[v3462] = 1;
    int * v3043 = v2536->cache_age;
    int v3044 = v3043[v3462];
    int v3045 = v3043[v3371];
    int v3491 = v3045 + ((int)((unsigned int)(v3045 - v3044) >> 31));
    v3043[v3371] = v3491;
    int * v3047 = v2536->cache_age;
    int v3048 = v3047[v3372];
    int v3493 = v3048 + ((int)((unsigned int)(v3048 - v3044) >> 31));
    v3047[v3372] = v3493;
    int * v3050 = v2536->cache_age;
    v3050[v3462] = 0;
    v3053 = v3462;
  }
  int * v3054 = v2536->cache_vals;
  int v3496 = (v3053 * 2) + (((int)((unsigned int)(v2540 + 12) >> 2)) & 1);
  v3054[v3496] = v2541;
  int * v3056 = v2536->cache_dirty;
  v3056[v3053] = 1;
  bool v3500 = ((((int)((unsigned int)v2556 >> 2)) == ((int)((unsigned int)(v2540 + 12) >> 2))) | (((((int)((unsigned int)(v2668 + 4) >> 2)) & 3) == (((int)((unsigned int)(v2540 + 12) >> 2)) & 3)) & (!(((int)((unsigned int)(v2668 + 4) >> 2)) == ((int)((unsigned int)(v2540 + 12) >> 2)))))) | (((((int)((unsigned int)(v2785 + 8) >> 2)) & 3) == (((int)((unsigned int)(v2540 + 12) >> 2)) & 3)) & (!(((int)((unsigned int)(v2785 + 8) >> 2)) == ((int)((unsigned int)(v2540 + 12) >> 2)))));
  struct StateT * v3080;
  if (v3500) {
    int v3058 = v2536->timer;
    int v3501 = v3058 + 15;
    v2536->timer = v3501;
    int * v3060 = v2536->saved_regs;
    int v3061 = v3060[13];
    int * v3062 = v2536->regs;
    v3062[13] = v3061;
    int * v3064 = v2536->saved_regs;
    int v3065 = v3064[14];
    int * v3066 = v2536->regs;
    v3066[14] = v3065;
    int * v3068 = v2536->saved_regs;
    int v3069 = v3068[17];
    int * v3070 = v2536->regs;
    v3070[17] = v3069;
    int * v3072 = v2536->saved_regs;
    int v3073 = v3072[8];
    int * v3074 = v2536->regs;
    v3074[8] = v3073;
    struct StateT * v3076 = slot_10(v2536);
    v3080 = v3076;
  } else {
    struct StateT * v3078 = slot_14(v2536);
    v3080 = v3078;
  }
  return v3080;
}

struct StateT * slot_300(struct StateT * v15551) {
  int v15552 = v15551->timer;
  int v15560 = v15552 + 1;
  v15551->timer = v15560;
  int * v15554 = v15551->regs;
  int v15555 = v15554[31];
  int v15556 = v15554[19];
  int v15565 = v15555 + v15556;
  v15554[23] = v15565;
  struct StateT * v15558 = slot_301(v15551);
  return v15558;
}

struct StateT * slot_183(struct StateT * v8601) {
  int v8602 = v8601->timer;
  int v8609 = v8602 + 1;
  v8601->timer = v8609;
  int * v8604 = v8601->regs;
  int v8605 = v8604[22];
  int v8613 = (int)((unsigned int)v8605 >> 14);
  v8604[24] = v8613;
  struct StateT * v8607 = slot_184(v8601);
  return v8607;
}

struct StateT * slot_282(struct StateT * v15271) {
  int v15272 = v15271->timer;
  int v15279 = v15272 + 1;
  v15271->timer = v15279;
  int * v15274 = v15271->regs;
  int v15275 = v15274[20];
  int v15282 = v15275 << 18;
  v15274[20] = v15282;
  struct StateT * v15277 = slot_283(v15271);
  return v15277;
}

struct StateT * slot_309(struct StateT * v15687) {
  int v15688 = v15687->timer;
  int v15696 = v15688 + 1;
  v15687->timer = v15696;
  int * v15690 = v15687->regs;
  int v15691 = v15690[22];
  int v15692 = v15690[24];
  int v15700 = v15691 | v15692;
  v15690[22] = v15700;
  struct StateT * v15694 = slot_310(v15687);
  return v15694;
}

struct StateT * slot_362(struct StateT * v16519) {
  int v16520 = v16519->timer;
  int v16527 = v16520 + 1;
  v16519->timer = v16527;
  int * v16522 = v16519->regs;
  int v16523 = v16522[20];
  int v16530 = v16523 << 18;
  v16522[20] = v16530;
  struct StateT * v16525 = slot_363(v16519);
  return v16525;
}

struct StateT * slot_43(struct StateT * v6305) {
  int v6306 = v6305->timer;
  int v6313 = v6306 + 1;
  v6305->timer = v6313;
  int * v6308 = v6305->regs;
  int v6309 = v6308[22];
  int v6317 = (int)((unsigned int)v6309 >> 25);
  v6308[24] = v6317;
  struct StateT * v6311 = slot_44(v6305);
  return v6311;
}

struct StateT * slot_76(struct StateT * v6878) {
  int v6879 = v6878->timer;
  int v6887 = v6879 + 1;
  v6878->timer = v6887;
  int * v6881 = v6878->regs;
  int v6882 = v6881[5];
  int v6883 = v6881[8];
  int v6892 = v6882 + v6883;
  v6881[23] = v6892;
  struct StateT * v6885 = slot_77(v6878);
  return v6885;
}

struct StateT * slot_6(struct StateT * v1591) {
  int v1592 = v1591->timer;
  int v1762 = v1592 + 1;
  v1591->timer = v1762;
  int * v1594 = v1591->regs;
  int v1595 = v1594[2];
  int v1596 = v1594[21];
  int * v1597 = v1591->cache_tags;
  int v1767 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2;
  int v1598 = v1597[v1767];
  int v1768 = ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1599 = v1597[v1768];
  int v1769 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2);
  int v1600 = v1597[v1769];
  int v1770 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1601 = v1597[v1770];
  int v1602 = v1591->timer;
  int v1771 = v1602 + ((100 ^ (((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1591->timer = v1771;
  bool v1772 = !(((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v1696;
  if (v1772) {
    int * v1604 = v1591->cache_age;
    int v1774 = ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v1605 = v1604[v1774];
    int v1606 = v1604[v1767];
    int v1775 = v1606 + ((int)((unsigned int)(v1606 - v1605) >> 31));
    v1604[v1767] = v1775;
    int * v1608 = v1591->cache_age;
    int v1609 = v1608[v1768];
    int v1777 = v1609 + ((int)((unsigned int)(v1609 - v1605) >> 31));
    v1608[v1768] = v1777;
    int * v1611 = v1591->cache_age;
    v1611[v1774] = 0;
    v1696 = v1774;
  } else {
    int * v1614 = v1591->cache_age;
    int v1781 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2;
    int v1615 = v1614[v1781];
    int * v1616 = v1591->cache_tags;
    int v1617 = v1616[v1781];
    int v1618 = v1614[v1768];
    int v1619 = v1616[v1768];
    bool v1783 = !(((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v1673;
    if (v1783) {
      int * v1620 = v1591->cache_age;
      int v1785 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v1621 = v1620[v1785];
      int v1622 = v1620[v1769];
      int v1786 = v1622 + ((int)((unsigned int)(v1622 - v1621) >> 31));
      v1620[v1769] = v1786;
      int * v1624 = v1591->cache_age;
      int v1625 = v1624[v1770];
      int v1788 = v1625 + ((int)((unsigned int)(v1625 - v1621) >> 31));
      v1624[v1770] = v1788;
      int * v1627 = v1591->cache_age;
      v1627[v1785] = 0;
      v1673 = v1785;
    } else {
      int * v1630 = v1591->cache_age;
      int v1792 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2);
      int v1631 = v1630[v1792];
      int * v1632 = v1591->cache_tags;
      int v1633 = v1632[v1792];
      int v1634 = v1630[v1770];
      int v1635 = v1632[v1770];
      int * v1636 = v1591->cache_dirty;
      int v1795 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1637 = v1636[v1795];
      bool v1796 = !(v1637 == 0);
      if (v1796) {
        int * v1638 = v1591->cache_tags;
        int v1639 = v1638[v1795];
        int * v1640 = v1591->cache_vals;
        int v1799 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1641 = v1640[v1799];
        int v1800 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1642 = v1640[v1800];
        int * v1643 = v1591->mem;
        int v1802 = v1639 * 2;
        v1643[v1802] = v1641;
        int * v1645 = v1591->mem;
        int v1805 = (v1639 * 2) + 1;
        v1645[v1805] = v1642;
        ;
      } else {
        ;
      }
      int * v1650 = v1591->mem;
      int v1810 = ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2;
      int v1651 = v1650[v1810];
      int v1811 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2) + 1;
      int v1652 = v1650[v1811];
      int * v1653 = v1591->cache_vals;
      int v1813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1653[v1813] = v1651;
      int * v1655 = v1591->cache_vals;
      int v1816 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1655[v1816] = v1652;
      int * v1657 = v1591->cache_tags;
      int v1819 = (int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1);
      v1657[v1795] = v1819;
      int * v1659 = v1591->cache_dirty;
      v1659[v1795] = 0;
      int * v1661 = v1591->cache_age;
      v1661[v1795] = 1;
      int * v1663 = v1591->cache_age;
      int v1664 = v1663[v1795];
      int v1665 = v1663[v1769];
      int v1825 = v1665 + ((int)((unsigned int)(v1665 - v1664) >> 31));
      v1663[v1769] = v1825;
      int * v1667 = v1591->cache_age;
      int v1668 = v1667[v1770];
      int v1827 = v1668 + ((int)((unsigned int)(v1668 - v1664) >> 31));
      v1667[v1770] = v1827;
      int * v1670 = v1591->cache_age;
      v1670[v1795] = 0;
      v1673 = v1795;
    }
    int * v1674 = v1591->cache_vals;
    int v1830 = v1673 * 2;
    int v1675 = v1674[v1830];
    int v1831 = (v1673 * 2) + 1;
    int v1676 = v1674[v1831];
    int v1832 = (((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v1615 + ((~(((v1617 ^ -1) | (-(v1617 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1619 ^ -1) | (-(v1619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1674[v1832] = v1675;
    int * v1678 = v1591->cache_vals;
    int v1835 = ((((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v1615 + ((~(((v1617 ^ -1) | (-(v1617 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1619 ^ -1) | (-(v1619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1678[v1835] = v1676;
    int * v1680 = v1591->cache_tags;
    int v1838 = ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v1615 + ((~(((v1617 ^ -1) | (-(v1617 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1619 ^ -1) | (-(v1619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1839 = (int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1);
    v1680[v1838] = v1839;
    int * v1682 = v1591->cache_dirty;
    v1682[v1838] = 0;
    int * v1684 = v1591->cache_age;
    v1684[v1838] = 1;
    int * v1686 = v1591->cache_age;
    int v1687 = v1686[v1838];
    int v1688 = v1686[v1767];
    int v1845 = v1688 + ((int)((unsigned int)(v1688 - v1687) >> 31));
    v1686[v1767] = v1845;
    int * v1690 = v1591->cache_age;
    int v1691 = v1690[v1768];
    int v1847 = v1691 + ((int)((unsigned int)(v1691 - v1687) >> 31));
    v1690[v1768] = v1847;
    int * v1693 = v1591->cache_age;
    v1693[v1838] = 0;
    v1696 = v1838;
  }
  int * v1697 = v1591->cache_vals;
  int v1850 = (v1696 * 2) + (((int)((unsigned int)(v1595 + 24) >> 2)) & 1);
  v1697[v1850] = v1596;
  int * v1699 = v1591->cache_tags;
  int v1700 = v1699[v1769];
  int v1701 = v1699[v1770];
  bool v1853 = !(((~(((v1700 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1700 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v1755;
  if (v1853) {
    int * v1702 = v1591->cache_age;
    int v1855 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v1703 = v1702[v1855];
    int v1704 = v1702[v1769];
    int v1856 = v1704 + ((int)((unsigned int)(v1704 - v1703) >> 31));
    v1702[v1769] = v1856;
    int * v1706 = v1591->cache_age;
    int v1707 = v1706[v1770];
    int v1858 = v1707 + ((int)((unsigned int)(v1707 - v1703) >> 31));
    v1706[v1770] = v1858;
    int * v1709 = v1591->cache_age;
    v1709[v1855] = 0;
    v1755 = v1855;
  } else {
    int * v1712 = v1591->cache_age;
    int v1862 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2);
    int v1713 = v1712[v1862];
    int * v1714 = v1591->cache_tags;
    int v1715 = v1714[v1862];
    int v1716 = v1712[v1770];
    int v1717 = v1714[v1770];
    int * v1718 = v1591->cache_dirty;
    int v1865 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1719 = v1718[v1865];
    bool v1866 = !(v1719 == 0);
    if (v1866) {
      int * v1720 = v1591->cache_tags;
      int v1721 = v1720[v1865];
      int * v1722 = v1591->cache_vals;
      int v1869 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1723 = v1722[v1869];
      int v1870 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1724 = v1722[v1870];
      int * v1725 = v1591->mem;
      int v1872 = v1721 * 2;
      v1725[v1872] = v1723;
      int * v1727 = v1591->mem;
      int v1875 = (v1721 * 2) + 1;
      v1727[v1875] = v1724;
      ;
    } else {
      ;
    }
    int * v1732 = v1591->mem;
    int v1880 = ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2;
    int v1733 = v1732[v1880];
    int v1881 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2) + 1;
    int v1734 = v1732[v1881];
    int * v1735 = v1591->cache_vals;
    int v1883 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1735[v1883] = v1733;
    int * v1737 = v1591->cache_vals;
    int v1886 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1737[v1886] = v1734;
    int * v1739 = v1591->cache_tags;
    int v1889 = (int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1);
    v1739[v1865] = v1889;
    int * v1741 = v1591->cache_dirty;
    v1741[v1865] = 0;
    int * v1743 = v1591->cache_age;
    v1743[v1865] = 1;
    int * v1745 = v1591->cache_age;
    int v1746 = v1745[v1865];
    int v1747 = v1745[v1769];
    int v1895 = v1747 + ((int)((unsigned int)(v1747 - v1746) >> 31));
    v1745[v1769] = v1895;
    int * v1749 = v1591->cache_age;
    int v1750 = v1749[v1770];
    int v1897 = v1750 + ((int)((unsigned int)(v1750 - v1746) >> 31));
    v1749[v1770] = v1897;
    int * v1752 = v1591->cache_age;
    v1752[v1865] = 0;
    v1755 = v1865;
  }
  int * v1756 = v1591->cache_vals;
  int v1900 = (v1755 * 2) + (((int)((unsigned int)(v1595 + 24) >> 2)) & 1);
  v1756[v1900] = v1596;
  int * v1758 = v1591->cache_dirty;
  v1758[v1755] = 1;
  struct StateT * v1760 = slot_7(v1591);
  return v1760;
}

struct StateT * slot_55(struct StateT * v6521) {
  int v6522 = v6521->timer;
  int v6530 = v6522 + 1;
  v6521->timer = v6530;
  int * v6524 = v6521->regs;
  int v6525 = v6524[19];
  int v6526 = v6524[28];
  int v6535 = v6525 + v6526;
  v6524[22] = v6535;
  struct StateT * v6528 = slot_56(v6521);
  return v6528;
}

struct StateT * slot_283(struct StateT * v15285) {
  int v15286 = v15285->timer;
  int v15294 = v15286 + 1;
  v15285->timer = v15294;
  int * v15288 = v15285->regs;
  int v15289 = v15288[20];
  int v15290 = v15288[24];
  int v15298 = v15289 | v15290;
  v15288[20] = v15298;
  struct StateT * v15292 = slot_284(v15285);
  return v15292;
}

struct StateT * slot_346(struct StateT * v16266) {
  int v16267 = v16266->timer;
  int v16275 = v16267 + 1;
  v16266->timer = v16275;
  int * v16269 = v16266->regs;
  int v16270 = v16269[21];
  int v16271 = v16269[24];
  int v16279 = v16270 | v16271;
  v16269[21] = v16279;
  struct StateT * v16273 = slot_347(v16266);
  return v16273;
}

struct StateT * slot_516(struct StateT * v19053) {
  int v19054 = v19053->timer;
  int v19062 = v19054 + 1;
  v19053->timer = v19062;
  int * v19056 = v19053->regs;
  int v19057 = v19056[9];
  int v19058 = v19056[21];
  int v19066 = v19057 ^ v19058;
  v19056[9] = v19066;
  struct StateT * v19060 = slot_517(v19053);
  return v19060;
}

struct StateT * slot_274(struct StateT * v15140) {
  int v15141 = v15140->timer;
  int v15149 = v15141 + 1;
  v15140->timer = v15149;
  int * v15143 = v15140->regs;
  int v15144 = v15143[14];
  int v15145 = v15143[21];
  int v15153 = v15144 ^ v15145;
  v15143[14] = v15153;
  struct StateT * v15147 = slot_275(v15140);
  return v15147;
}

struct StateT * slot_535(struct StateT * v19349) {
  int v19350 = v19349->timer;
  int v19358 = v19350 + 1;
  v19349->timer = v19358;
  int * v19352 = v19349->regs;
  int v19353 = v19352[30];
  int v19354 = v19352[20];
  int v19362 = v19353 ^ v19354;
  v19352[30] = v19362;
  struct StateT * v19356 = slot_536(v19349);
  return v19356;
}

struct StateT * slot_318(struct StateT * v15829) {
  int v15830 = v15829->timer;
  int v15838 = v15830 + 1;
  v15829->timer = v15838;
  int * v15832 = v15829->regs;
  int v15833 = v15832[12];
  int v15834 = v15832[29];
  int v15843 = v15833 + v15834;
  v15832[21] = v15843;
  struct StateT * v15836 = slot_319(v15829);
  return v15836;
}

struct StateT * slot_91(struct StateT * v7121) {
  int * v7122 = v7121->saved_regs;
  int * v7123 = v7121->regs;
  int v7124 = v7123[12];
  v7122[12] = v7124;
  int v7126 = v7121->timer;
  int v7138 = v7126 + 1;
  v7121->timer = v7138;
  int * v7128 = v7121->regs;
  int v7129 = v7128[12];
  int v7130 = v7128[22];
  int v7141 = v7129 ^ v7130;
  v7128[12] = v7141;
  struct StateT * v7132 = slot_92(v7121);
  return v7132;
}

struct StateT * slot_58(struct StateT * v6570) {
  int v6571 = v6570->timer;
  int v6578 = v6571 + 1;
  v6570->timer = v6578;
  int * v6573 = v6570->regs;
  int v6574 = v6573[20];
  int v6581 = v6574 << 9;
  v6573[20] = v6581;
  struct StateT * v6576 = slot_59(v6570);
  return v6576;
}

struct StateT * slot_255(struct StateT * v14844) {
  int v14845 = v14844->timer;
  int v14853 = v14845 + 1;
  v14844->timer = v14853;
  int * v14847 = v14844->regs;
  int v14848 = v14847[17];
  int v14849 = v14847[22];
  int v14857 = v14848 ^ v14849;
  v14847[17] = v14857;
  struct StateT * v14851 = slot_256(v14844);
  return v14851;
}

struct StateT * slot_540(struct StateT * v19434) {
  int * v19435 = v19434->regs;
  int v19436 = v19435[11];
  int * v19437 = v19434->saved_regs;
  int v19438 = v19437[13];
  bool v19539 = (v19436 ^ -2147483648) >= (v19438 ^ -2147483648);
  struct StateT * v19533;
  if (v19539) {
    struct StateT * v19439 = slot_378(v19434);
    v19533 = v19439;
  } else {
    int v19441 = v19434->timer;
    int v19542 = v19441 + 15;
    v19434->timer = v19542;
    int * v19443 = v19434->saved_regs;
    int v19444 = v19443[20];
    int * v19445 = v19434->regs;
    v19445[20] = v19444;
    int * v19447 = v19434->saved_regs;
    int v19448 = v19447[21];
    int * v19449 = v19434->regs;
    v19449[21] = v19448;
    int * v19451 = v19434->saved_regs;
    int v19452 = v19451[22];
    int * v19453 = v19434->regs;
    v19453[22] = v19452;
    int * v19455 = v19434->saved_regs;
    int v19456 = v19455[23];
    int * v19457 = v19434->regs;
    v19457[23] = v19456;
    int * v19459 = v19434->saved_regs;
    int v19460 = v19459[24];
    int * v19461 = v19434->regs;
    v19461[24] = v19460;
    int * v19463 = v19434->saved_regs;
    int v19464 = v19463[9];
    int * v19465 = v19434->regs;
    v19465[9] = v19464;
    int * v19467 = v19434->saved_regs;
    int v19468 = v19467[18];
    int * v19469 = v19434->regs;
    v19469[18] = v19468;
    int * v19471 = v19434->saved_regs;
    int v19472 = v19471[19];
    int * v19473 = v19434->regs;
    v19473[19] = v19472;
    int * v19475 = v19434->saved_regs;
    int v19476 = v19475[8];
    int * v19477 = v19434->regs;
    v19477[8] = v19476;
    int * v19479 = v19434->saved_regs;
    int v19480 = v19479[6];
    int * v19481 = v19434->regs;
    v19481[6] = v19480;
    int * v19483 = v19434->saved_regs;
    int v19484 = v19483[7];
    int * v19485 = v19434->regs;
    v19485[7] = v19484;
    int * v19487 = v19434->saved_regs;
    int v19488 = v19487[17];
    int * v19489 = v19434->regs;
    v19489[17] = v19488;
    int * v19491 = v19434->saved_regs;
    int v19492 = v19491[5];
    int * v19493 = v19434->regs;
    v19493[5] = v19492;
    int * v19495 = v19434->saved_regs;
    int v19496 = v19495[16];
    int * v19497 = v19434->regs;
    v19497[16] = v19496;
    int * v19499 = v19434->saved_regs;
    int v19500 = v19499[14];
    int * v19501 = v19434->regs;
    v19501[14] = v19500;
    int * v19503 = v19434->saved_regs;
    int v19504 = v19503[12];
    int * v19505 = v19434->regs;
    v19505[12] = v19504;
    int * v19507 = v19434->saved_regs;
    int v19508 = v19507[15];
    int * v19509 = v19434->regs;
    v19509[15] = v19508;
    int * v19511 = v19434->saved_regs;
    int v19512 = v19511[30];
    int * v19513 = v19434->regs;
    v19513[30] = v19512;
    int * v19515 = v19434->saved_regs;
    int v19516 = v19515[29];
    int * v19517 = v19434->regs;
    v19517[29] = v19516;
    int * v19519 = v19434->saved_regs;
    int v19520 = v19519[28];
    int * v19521 = v19434->regs;
    v19521[28] = v19520;
    int * v19523 = v19434->saved_regs;
    int v19524 = v19523[31];
    int * v19525 = v19434->regs;
    v19525[31] = v19524;
    int * v19527 = v19434->saved_regs;
    int v19528 = v19527[13];
    int * v19529 = v19434->regs;
    v19529[13] = v19528;
    struct StateT * v19531 = slot_195(v19434);
    v19533 = v19531;
  }
  return v19533;
}

struct StateT * slot_66(struct StateT * v6690) {
  int v6691 = v6690->timer;
  int v6698 = v6691 + 1;
  v6690->timer = v6698;
  int * v6693 = v6690->regs;
  int v6694 = v6693[23];
  int v6702 = (int)((unsigned int)v6694 >> 23);
  v6693[24] = v6702;
  struct StateT * v6696 = slot_67(v6690);
  return v6696;
}

struct StateT * slot_368(struct StateT * v16609) {
  int v16610 = v16609->timer;
  int v16617 = v16610 + 1;
  v16609->timer = v16617;
  int * v16612 = v16609->regs;
  int v16613 = v16612[22];
  int v16620 = v16613 << 18;
  v16612[22] = v16620;
  struct StateT * v16615 = slot_369(v16609);
  return v16615;
}

struct StateT * slot_265(struct StateT * v15004) {
  int v15005 = v15004->timer;
  int v15012 = v15005 + 1;
  v15004->timer = v15012;
  int * v15007 = v15004->regs;
  int v15008 = v15007[21];
  int v15015 = v15008 << 13;
  v15007[21] = v15015;
  struct StateT * v15010 = slot_266(v15004);
  return v15010;
}

struct StateT * slot_37(struct StateT * v6208) {
  int * v6209 = v6208->saved_regs;
  int * v6210 = v6208->regs;
  int v6211 = v6210[24];
  v6209[24] = v6211;
  int v6213 = v6208->timer;
  int v6224 = v6213 + 1;
  v6208->timer = v6224;
  int * v6215 = v6208->regs;
  int v6216 = v6215[20];
  int v6227 = (int)((unsigned int)v6216 >> 25);
  v6215[24] = v6227;
  struct StateT * v6218 = slot_38(v6208);
  return v6218;
}

struct StateT * slot_114(struct StateT * v7524) {
  int v7525 = v7524->timer;
  int v7533 = v7525 + 1;
  v7524->timer = v7533;
  int * v7527 = v7524->regs;
  int v7528 = v7527[29];
  int v7529 = v7527[9];
  int v7538 = v7528 + v7529;
  v7527[21] = v7538;
  struct StateT * v7531 = slot_115(v7524);
  return v7531;
}

struct StateT * slot_257(struct StateT * v14876) {
  int v14877 = v14876->timer;
  int v14885 = v14877 + 1;
  v14876->timer = v14885;
  int * v14879 = v14876->regs;
  int v14880 = v14879[6];
  int v14881 = v14879[9];
  int v14890 = v14880 + v14881;
  v14879[20] = v14890;
  struct StateT * v14883 = slot_258(v14876);
  return v14883;
}

struct StateT * slot_192(struct StateT * v8739) {
  int v8740 = v8739->timer;
  int v8748 = v8740 + 1;
  v8739->timer = v8748;
  int * v8742 = v8739->regs;
  int v8743 = v8742[31];
  int v8744 = v8742[23];
  int v8752 = v8743 ^ v8744;
  v8742[31] = v8752;
  struct StateT * v8746 = slot_193(v8739);
  return v8746;
}

struct StateT * slot_327(struct StateT * v15970) {
  int v15971 = v15970->timer;
  int v15978 = v15971 + 1;
  v15970->timer = v15978;
  int * v15973 = v15970->regs;
  int v15974 = v15973[22];
  int v15982 = (int)((unsigned int)v15974 >> 23);
  v15973[24] = v15982;
  struct StateT * v15976 = slot_328(v15970);
  return v15976;
}

struct StateT * slot_48(struct StateT * v6379) {
  int v6380 = v6379->timer;
  int v6388 = v6380 + 1;
  v6379->timer = v6388;
  int * v6382 = v6379->regs;
  int v6383 = v6382[23];
  int v6384 = v6382[24];
  int v6392 = v6383 | v6384;
  v6382[23] = v6392;
  struct StateT * v6386 = slot_49(v6379);
  return v6386;
}

struct StateT * slot_396(struct StateT * v17076) {
  int * v17077 = v17076->saved_regs;
  int * v17078 = v17076->regs;
  int v17079 = v17078[18];
  v17077[18] = v17079;
  int v17081 = v17076->timer;
  int v17093 = v17081 + 1;
  v17076->timer = v17093;
  int * v17083 = v17076->regs;
  int v17084 = v17083[18];
  int v17085 = v17083[21];
  int v17096 = v17084 ^ v17085;
  v17083[18] = v17096;
  struct StateT * v17087 = slot_397(v17076);
  return v17087;
}

struct StateT * slot_528(struct StateT * v19243) {
  int v19244 = v19243->timer;
  int v19252 = v19244 + 1;
  v19243->timer = v19252;
  int * v19246 = v19243->regs;
  int v19247 = v19246[21];
  int v19248 = v19246[24];
  int v19256 = v19247 | v19248;
  v19246[21] = v19256;
  struct StateT * v19250 = slot_529(v19243);
  return v19250;
}

struct StateT * slot_72(struct StateT * v6804) {
  int * v6805 = v6804->saved_regs;
  int * v6806 = v6804->regs;
  int v6807 = v6806[5];
  v6805[5] = v6807;
  int v6809 = v6804->timer;
  int v6821 = v6809 + 1;
  v6804->timer = v6821;
  int * v6811 = v6804->regs;
  int v6812 = v6811[5];
  int v6813 = v6811[23];
  int v6824 = v6812 ^ v6813;
  v6811[5] = v6824;
  struct StateT * v6815 = slot_73(v6804);
  return v6815;
}

struct StateT * slot_526(struct StateT * v19214) {
  int v19215 = v19214->timer;
  int v19222 = v19215 + 1;
  v19214->timer = v19222;
  int * v19217 = v19214->regs;
  int v19218 = v19217[21];
  int v19226 = (int)((unsigned int)v19218 >> 14);
  v19217[24] = v19226;
  struct StateT * v19220 = slot_527(v19214);
  return v19220;
}

struct StateT * slot_119(struct StateT * v7604) {
  int v7605 = v7604->timer;
  int v7613 = v7605 + 1;
  v7604->timer = v7613;
  int * v7607 = v7604->regs;
  int v7608 = v7607[20];
  int v7609 = v7607[24];
  int v7617 = v7608 | v7609;
  v7607[20] = v7617;
  struct StateT * v7611 = slot_120(v7604);
  return v7611;
}

struct StateT * slot_101(struct StateT * v7295) {
  int v7296 = v7295->timer;
  int v7303 = v7296 + 1;
  v7295->timer = v7303;
  int * v7298 = v7295->regs;
  int v7299 = v7298[21];
  int v7306 = v7299 << 18;
  v7298[21] = v7306;
  struct StateT * v7301 = slot_102(v7295);
  return v7301;
}

struct StateT * slot_276(struct StateT * v15172) {
  int v15173 = v15172->timer;
  int v15181 = v15173 + 1;
  v15172->timer = v15181;
  int * v15175 = v15172->regs;
  int v15176 = v15175[15];
  int v15177 = v15175[23];
  int v15185 = v15176 ^ v15177;
  v15175[15] = v15185;
  struct StateT * v15179 = slot_277(v15172);
  return v15179;
}

struct StateT * slot_290(struct StateT * v15391) {
  int v15392 = v15391->timer;
  int v15399 = v15392 + 1;
  v15391->timer = v15399;
  int * v15394 = v15391->regs;
  int v15395 = v15394[23];
  int v15403 = (int)((unsigned int)v15395 >> 14);
  v15394[24] = v15403;
  struct StateT * v15397 = slot_291(v15391);
  return v15397;
}

struct StateT * slot_93(struct StateT * v7167) {
  int v7168 = v7167->timer;
  int v7176 = v7168 + 1;
  v7167->timer = v7176;
  int * v7170 = v7167->regs;
  int v7171 = v7170[16];
  int v7172 = v7170[6];
  int v7181 = v7171 + v7172;
  v7170[20] = v7181;
  struct StateT * v7174 = slot_94(v7167);
  return v7174;
}

struct StateT * slot_266(struct StateT * v15018) {
  int v15019 = v15018->timer;
  int v15027 = v15019 + 1;
  v15018->timer = v15027;
  int * v15021 = v15018->regs;
  int v15022 = v15021[21];
  int v15023 = v15021[24];
  int v15031 = v15022 | v15023;
  v15021[21] = v15031;
  struct StateT * v15025 = slot_267(v15018);
  return v15025;
}

struct StateT * slot_88(struct StateT * v7059) {
  int v7060 = v7059->timer;
  int v7068 = v7060 + 1;
  v7059->timer = v7068;
  int * v7062 = v7059->regs;
  int v7063 = v7062[23];
  int v7064 = v7062[24];
  int v7072 = v7063 | v7064;
  v7062[23] = v7072;
  struct StateT * v7066 = slot_89(v7059);
  return v7066;
}

struct StateT * slot_96(struct StateT * v7218) {
  int v7219 = v7218->timer;
  int v7227 = v7219 + 1;
  v7218->timer = v7227;
  int * v7221 = v7218->regs;
  int v7222 = v7221[15];
  int v7223 = v7221[5];
  int v7232 = v7222 + v7223;
  v7221[23] = v7232;
  struct StateT * v7225 = slot_97(v7218);
  return v7225;
}

struct StateT * slot_234(struct StateT * v14516) {
  int v14517 = v14516->timer;
  int v14525 = v14517 + 1;
  v14516->timer = v14525;
  int * v14519 = v14516->regs;
  int v14520 = v14519[18];
  int v14521 = v14519[21];
  int v14529 = v14520 ^ v14521;
  v14519[18] = v14529;
  struct StateT * v14523 = slot_235(v14516);
  return v14523;
}

struct StateT * slot_471(struct StateT * v18352) {
  int v18353 = v18352->timer;
  int v18361 = v18353 + 1;
  v18352->timer = v18361;
  int * v18355 = v18352->regs;
  int v18356 = v18355[22];
  int v18357 = v18355[24];
  int v18365 = v18356 | v18357;
  v18355[22] = v18365;
  struct StateT * v18359 = slot_472(v18352);
  return v18359;
}

struct StateT * slot_419(struct StateT * v17485) {
  int v17486 = v17485->timer;
  int v17494 = v17486 + 1;
  v17485->timer = v17494;
  int * v17488 = v17485->regs;
  int v17489 = v17488[6];
  int v17490 = v17488[9];
  int v17499 = v17489 + v17490;
  v17488[20] = v17499;
  struct StateT * v17492 = slot_420(v17485);
  return v17492;
}

struct StateT * slot_218(struct StateT * v13326) {
  int v13327 = v13326->timer;
  int v13334 = v13327 + 1;
  v13326->timer = v13334;
  int * v13329 = v13326->regs;
  int v13330 = v13329[21];
  int v13338 = (int)((unsigned int)v13330 >> 25);
  v13329[24] = v13338;
  struct StateT * v13332 = slot_220(v13326);
  return v13332;
}

struct StateT * slot_202(struct StateT * v10279) {
  int v10280 = v10279->timer;
  int v10288 = v10280 + 1;
  v10279->timer = v10288;
  int * v10282 = v10279->regs;
  int v10283 = v10282[29];
  int v10284 = v10282[14];
  int v10293 = v10283 + v10284;
  v10282[21] = v10293;
  struct StateT * v10286 = slot_204(v10279);
  return v10286;
}

struct StateT * slot_336(struct StateT * v16108) {
  int v16109 = v16108->timer;
  int v16117 = v16109 + 1;
  v16108->timer = v16117;
  int * v16111 = v16108->regs;
  int v16112 = v16111[7];
  int v16113 = v16111[23];
  int v16121 = v16112 ^ v16113;
  v16111[7] = v16121;
  struct StateT * v16115 = slot_337(v16108);
  return v16115;
}

struct StateT * slot_230(struct StateT * v14455) {
  int v14456 = v14455->timer;
  int v14463 = v14456 + 1;
  v14455->timer = v14463;
  int * v14458 = v14455->regs;
  int v14459 = v14458[23];
  int v14467 = (int)((unsigned int)v14459 >> 25);
  v14458[24] = v14467;
  struct StateT * v14461 = slot_231(v14455);
  return v14461;
}

struct StateT * slot_294(struct StateT * v15452) {
  int v15453 = v15452->timer;
  int v15461 = v15453 + 1;
  v15452->timer = v15461;
  int * v15455 = v15452->regs;
  int v15456 = v15455[29];
  int v15457 = v15455[21];
  int v15465 = v15456 ^ v15457;
  v15455[29] = v15465;
  struct StateT * v15459 = slot_295(v15452);
  return v15459;
}

struct StateT * slot_408(struct StateT * v17287) {
  int v17288 = v17287->timer;
  int v17296 = v17288 + 1;
  v17287->timer = v17296;
  int * v17290 = v17287->regs;
  int v17291 = v17290[21];
  int v17292 = v17290[24];
  int v17300 = v17291 | v17292;
  v17290[21] = v17300;
  struct StateT * v17294 = slot_409(v17287);
  return v17294;
}

struct StateT * slot_342(struct StateT * v16207) {
  int v16208 = v16207->timer;
  int v16215 = v16208 + 1;
  v16207->timer = v16215;
  int * v16210 = v16207->regs;
  int v16211 = v16210[20];
  int v16218 = v16211 << 13;
  v16210[20] = v16218;
  struct StateT * v16213 = slot_343(v16207);
  return v16213;
}

struct StateT * slot_488(struct StateT * v18619) {
  int v18620 = v18619->timer;
  int v18628 = v18620 + 1;
  v18619->timer = v18628;
  int * v18622 = v18619->regs;
  int v18623 = v18622[21];
  int v18624 = v18622[24];
  int v18632 = v18623 | v18624;
  v18622[21] = v18632;
  struct StateT * v18626 = slot_489(v18619);
  return v18626;
}

struct StateT * slot_439(struct StateT * v17825) {
  int v17826 = v17825->timer;
  int v17834 = v17826 + 1;
  v17825->timer = v17834;
  int * v17828 = v17825->regs;
  int v17829 = v17828[16];
  int v17830 = v17828[6];
  int v17839 = v17829 + v17830;
  v17828[20] = v17839;
  struct StateT * v17832 = slot_440(v17825);
  return v17832;
}

struct StateT * slot_389(struct StateT * v16963) {
  int v16964 = v16963->timer;
  int v16971 = v16964 + 1;
  v16963->timer = v16971;
  int * v16966 = v16963->regs;
  int v16967 = v16966[22];
  int v16975 = (int)((unsigned int)v16967 >> 25);
  v16966[24] = v16975;
  struct StateT * v16969 = slot_390(v16963);
  return v16969;
}

struct StateT * slot_479(struct StateT * v18477) {
  int v18478 = v18477->timer;
  int v18486 = v18478 + 1;
  v18477->timer = v18486;
  int * v18480 = v18477->regs;
  int v18481 = v18480[14];
  int v18482 = v18480[30];
  int v18491 = v18481 + v18482;
  v18480[20] = v18491;
  struct StateT * v18484 = slot_480(v18477);
  return v18484;
}

struct StateT * slot_138(struct StateT * v7902) {
  int v7903 = v7902->timer;
  int v7910 = v7903 + 1;
  v7902->timer = v7910;
  int * v7905 = v7902->regs;
  int v7906 = v7905[20];
  int v7913 = v7906 << 9;
  v7905[20] = v7913;
  struct StateT * v7908 = slot_139(v7902);
  return v7908;
}

struct StateT * slot_483(struct StateT * v18545) {
  int v18546 = v18545->timer;
  int v18553 = v18546 + 1;
  v18545->timer = v18553;
  int * v18548 = v18545->regs;
  int v18549 = v18548[20];
  int v18557 = (int)((unsigned int)v18549 >> 23);
  v18548[24] = v18557;
  struct StateT * v18551 = slot_484(v18545);
  return v18551;
}

struct StateT * slot_196(struct StateT * v9287) {
  int v9288 = v9287->timer;
  int v9292 = v9288 + 1;
  v9287->timer = v9292;
  struct StateT * v9290 = slot_198(v9287);
  return v9290;
}

struct StateT * slot_172(struct StateT * v8427) {
  int v8428 = v8427->timer;
  int v8436 = v8428 + 1;
  v8427->timer = v8436;
  int * v8430 = v8427->regs;
  int v8431 = v8430[19];
  int v8432 = v8430[23];
  int v8440 = v8431 ^ v8432;
  v8430[19] = v8440;
  struct StateT * v8434 = slot_173(v8427);
  return v8434;
}

struct StateT * slot_425(struct StateT * v17582) {
  int v17583 = v17582->timer;
  int v17591 = v17583 + 1;
  v17582->timer = v17591;
  int * v17585 = v17582->regs;
  int v17586 = v17585[20];
  int v17587 = v17585[24];
  int v17595 = v17586 | v17587;
  v17585[20] = v17595;
  struct StateT * v17589 = slot_426(v17582);
  return v17589;
}

struct StateT * slot_443(struct StateT * v17893) {
  int v17894 = v17893->timer;
  int v17901 = v17894 + 1;
  v17893->timer = v17901;
  int * v17896 = v17893->regs;
  int v17897 = v17896[20];
  int v17905 = (int)((unsigned int)v17897 >> 14);
  v17896[24] = v17905;
  struct StateT * v17899 = slot_444(v17893);
  return v17899;
}

struct StateT * slot_131(struct StateT * v7787) {
  int v7788 = v7787->timer;
  int v7796 = v7788 + 1;
  v7787->timer = v7796;
  int * v7790 = v7787->regs;
  int v7791 = v7790[15];
  int v7792 = v7790[22];
  int v7800 = v7791 ^ v7792;
  v7790[15] = v7800;
  struct StateT * v7794 = slot_132(v7787);
  return v7794;
}

struct StateT * slot_8(struct StateT * v2221) {
  int v2222 = v2221->timer;
  int v2392 = v2222 + 1;
  v2221->timer = v2392;
  int * v2224 = v2221->regs;
  int v2225 = v2224[2];
  int v2226 = v2224[23];
  int * v2227 = v2221->cache_tags;
  int v2397 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2;
  int v2228 = v2227[v2397];
  int v2398 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2229 = v2227[v2398];
  int v2399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2);
  int v2230 = v2227[v2399];
  int v2400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2231 = v2227[v2400];
  int v2232 = v2221->timer;
  int v2401 = v2232 + ((100 ^ (((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2221->timer = v2401;
  bool v2402 = !(((~(((v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v2326;
  if (v2402) {
    int * v2234 = v2221->cache_age;
    int v2404 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v2235 = v2234[v2404];
    int v2236 = v2234[v2397];
    int v2405 = v2236 + ((int)((unsigned int)(v2236 - v2235) >> 31));
    v2234[v2397] = v2405;
    int * v2238 = v2221->cache_age;
    int v2239 = v2238[v2398];
    int v2407 = v2239 + ((int)((unsigned int)(v2239 - v2235) >> 31));
    v2238[v2398] = v2407;
    int * v2241 = v2221->cache_age;
    v2241[v2404] = 0;
    v2326 = v2404;
  } else {
    int * v2244 = v2221->cache_age;
    int v2411 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2;
    int v2245 = v2244[v2411];
    int * v2246 = v2221->cache_tags;
    int v2247 = v2246[v2411];
    int v2248 = v2244[v2398];
    int v2249 = v2246[v2398];
    bool v2413 = !(((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v2303;
    if (v2413) {
      int * v2250 = v2221->cache_age;
      int v2415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v2251 = v2250[v2415];
      int v2252 = v2250[v2399];
      int v2416 = v2252 + ((int)((unsigned int)(v2252 - v2251) >> 31));
      v2250[v2399] = v2416;
      int * v2254 = v2221->cache_age;
      int v2255 = v2254[v2400];
      int v2418 = v2255 + ((int)((unsigned int)(v2255 - v2251) >> 31));
      v2254[v2400] = v2418;
      int * v2257 = v2221->cache_age;
      v2257[v2415] = 0;
      v2303 = v2415;
    } else {
      int * v2260 = v2221->cache_age;
      int v2422 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2);
      int v2261 = v2260[v2422];
      int * v2262 = v2221->cache_tags;
      int v2263 = v2262[v2422];
      int v2264 = v2260[v2400];
      int v2265 = v2262[v2400];
      int * v2266 = v2221->cache_dirty;
      int v2425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2267 = v2266[v2425];
      bool v2426 = !(v2267 == 0);
      if (v2426) {
        int * v2268 = v2221->cache_tags;
        int v2269 = v2268[v2425];
        int * v2270 = v2221->cache_vals;
        int v2429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2271 = v2270[v2429];
        int v2430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2272 = v2270[v2430];
        int * v2273 = v2221->mem;
        int v2432 = v2269 * 2;
        v2273[v2432] = v2271;
        int * v2275 = v2221->mem;
        int v2435 = (v2269 * 2) + 1;
        v2275[v2435] = v2272;
        ;
      } else {
        ;
      }
      int * v2280 = v2221->mem;
      int v2440 = ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2;
      int v2281 = v2280[v2440];
      int v2441 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2) + 1;
      int v2282 = v2280[v2441];
      int * v2283 = v2221->cache_vals;
      int v2443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2283[v2443] = v2281;
      int * v2285 = v2221->cache_vals;
      int v2446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2285[v2446] = v2282;
      int * v2287 = v2221->cache_tags;
      int v2449 = (int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1);
      v2287[v2425] = v2449;
      int * v2289 = v2221->cache_dirty;
      v2289[v2425] = 0;
      int * v2291 = v2221->cache_age;
      v2291[v2425] = 1;
      int * v2293 = v2221->cache_age;
      int v2294 = v2293[v2425];
      int v2295 = v2293[v2399];
      int v2455 = v2295 + ((int)((unsigned int)(v2295 - v2294) >> 31));
      v2293[v2399] = v2455;
      int * v2297 = v2221->cache_age;
      int v2298 = v2297[v2400];
      int v2457 = v2298 + ((int)((unsigned int)(v2298 - v2294) >> 31));
      v2297[v2400] = v2457;
      int * v2300 = v2221->cache_age;
      v2300[v2425] = 0;
      v2303 = v2425;
    }
    int * v2304 = v2221->cache_vals;
    int v2460 = v2303 * 2;
    int v2305 = v2304[v2460];
    int v2461 = (v2303 * 2) + 1;
    int v2306 = v2304[v2461];
    int v2462 = (((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2304[v2462] = v2305;
    int * v2308 = v2221->cache_vals;
    int v2465 = ((((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2308[v2465] = v2306;
    int * v2310 = v2221->cache_tags;
    int v2468 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2469 = (int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1);
    v2310[v2468] = v2469;
    int * v2312 = v2221->cache_dirty;
    v2312[v2468] = 0;
    int * v2314 = v2221->cache_age;
    v2314[v2468] = 1;
    int * v2316 = v2221->cache_age;
    int v2317 = v2316[v2468];
    int v2318 = v2316[v2397];
    int v2475 = v2318 + ((int)((unsigned int)(v2318 - v2317) >> 31));
    v2316[v2397] = v2475;
    int * v2320 = v2221->cache_age;
    int v2321 = v2320[v2398];
    int v2477 = v2321 + ((int)((unsigned int)(v2321 - v2317) >> 31));
    v2320[v2398] = v2477;
    int * v2323 = v2221->cache_age;
    v2323[v2468] = 0;
    v2326 = v2468;
  }
  int * v2327 = v2221->cache_vals;
  int v2480 = (v2326 * 2) + (((int)((unsigned int)(v2225 + 16) >> 2)) & 1);
  v2327[v2480] = v2226;
  int * v2329 = v2221->cache_tags;
  int v2330 = v2329[v2399];
  int v2331 = v2329[v2400];
  bool v2483 = !(((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v2385;
  if (v2483) {
    int * v2332 = v2221->cache_age;
    int v2485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v2333 = v2332[v2485];
    int v2334 = v2332[v2399];
    int v2486 = v2334 + ((int)((unsigned int)(v2334 - v2333) >> 31));
    v2332[v2399] = v2486;
    int * v2336 = v2221->cache_age;
    int v2337 = v2336[v2400];
    int v2488 = v2337 + ((int)((unsigned int)(v2337 - v2333) >> 31));
    v2336[v2400] = v2488;
    int * v2339 = v2221->cache_age;
    v2339[v2485] = 0;
    v2385 = v2485;
  } else {
    int * v2342 = v2221->cache_age;
    int v2492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2);
    int v2343 = v2342[v2492];
    int * v2344 = v2221->cache_tags;
    int v2345 = v2344[v2492];
    int v2346 = v2342[v2400];
    int v2347 = v2344[v2400];
    int * v2348 = v2221->cache_dirty;
    int v2495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2349 = v2348[v2495];
    bool v2496 = !(v2349 == 0);
    if (v2496) {
      int * v2350 = v2221->cache_tags;
      int v2351 = v2350[v2495];
      int * v2352 = v2221->cache_vals;
      int v2499 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2353 = v2352[v2499];
      int v2500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2354 = v2352[v2500];
      int * v2355 = v2221->mem;
      int v2502 = v2351 * 2;
      v2355[v2502] = v2353;
      int * v2357 = v2221->mem;
      int v2505 = (v2351 * 2) + 1;
      v2357[v2505] = v2354;
      ;
    } else {
      ;
    }
    int * v2362 = v2221->mem;
    int v2510 = ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2;
    int v2363 = v2362[v2510];
    int v2511 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2) + 1;
    int v2364 = v2362[v2511];
    int * v2365 = v2221->cache_vals;
    int v2513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2365[v2513] = v2363;
    int * v2367 = v2221->cache_vals;
    int v2516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2367[v2516] = v2364;
    int * v2369 = v2221->cache_tags;
    int v2519 = (int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1);
    v2369[v2495] = v2519;
    int * v2371 = v2221->cache_dirty;
    v2371[v2495] = 0;
    int * v2373 = v2221->cache_age;
    v2373[v2495] = 1;
    int * v2375 = v2221->cache_age;
    int v2376 = v2375[v2495];
    int v2377 = v2375[v2399];
    int v2525 = v2377 + ((int)((unsigned int)(v2377 - v2376) >> 31));
    v2375[v2399] = v2525;
    int * v2379 = v2221->cache_age;
    int v2380 = v2379[v2400];
    int v2527 = v2380 + ((int)((unsigned int)(v2380 - v2376) >> 31));
    v2379[v2400] = v2527;
    int * v2382 = v2221->cache_age;
    v2382[v2495] = 0;
    v2385 = v2495;
  }
  int * v2386 = v2221->cache_vals;
  int v2530 = (v2385 * 2) + (((int)((unsigned int)(v2225 + 16) >> 2)) & 1);
  v2386[v2530] = v2226;
  int * v2388 = v2221->cache_dirty;
  v2388[v2385] = 1;
  struct StateT * v2390 = slot_9(v2221);
  return v2390;
}

struct StateT * slot_534(struct StateT * v19333) {
  int v19334 = v19333->timer;
  int v19342 = v19334 + 1;
  v19333->timer = v19342;
  int * v19336 = v19333->regs;
  int v19337 = v19336[23];
  int v19338 = v19336[24];
  int v19346 = v19337 | v19338;
  v19336[23] = v19346;
  struct StateT * v19340 = slot_535(v19333);
  return v19340;
}

struct StateT * slot_180(struct StateT * v8556) {
  int v8557 = v8556->timer;
  int v8564 = v8557 + 1;
  v8556->timer = v8564;
  int * v8559 = v8556->regs;
  int v8560 = v8559[21];
  int v8568 = (int)((unsigned int)v8560 >> 14);
  v8559[24] = v8568;
  struct StateT * v8562 = slot_181(v8556);
  return v8562;
}

struct StateT * slot_504(struct StateT * v18872) {
  int v18873 = v18872->timer;
  int v18880 = v18873 + 1;
  v18872->timer = v18880;
  int * v18875 = v18872->regs;
  int v18876 = v18875[20];
  int v18883 = v18876 << 13;
  v18875[20] = v18883;
  struct StateT * v18878 = slot_505(v18872);
  return v18878;
}

struct StateT * slot_512(struct StateT * v18992) {
  int v18993 = v18992->timer;
  int v19000 = v18993 + 1;
  v18992->timer = v19000;
  int * v18995 = v18992->regs;
  int v18996 = v18995[23];
  int v19004 = (int)((unsigned int)v18996 >> 19);
  v18995[24] = v19004;
  struct StateT * v18998 = slot_513(v18992);
  return v18998;
}

struct StateT * slot_496(struct StateT * v18741) {
  int v18742 = v18741->timer;
  int v18750 = v18742 + 1;
  v18741->timer = v18750;
  int * v18744 = v18741->regs;
  int v18745 = v18744[5];
  int v18746 = v18744[21];
  int v18754 = v18745 ^ v18746;
  v18744[5] = v18754;
  struct StateT * v18748 = slot_497(v18741);
  return v18748;
}

struct StateT * slot_494(struct StateT * v18709) {
  int v18710 = v18709->timer;
  int v18718 = v18710 + 1;
  v18709->timer = v18718;
  int * v18712 = v18709->regs;
  int v18713 = v18712[23];
  int v18714 = v18712[24];
  int v18722 = v18713 | v18714;
  v18712[23] = v18722;
  struct StateT * v18716 = slot_495(v18709);
  return v18716;
}

struct StateT * slot_242(struct StateT * v14647) {
  int v14648 = v14647->timer;
  int v14655 = v14648 + 1;
  v14647->timer = v14655;
  int * v14650 = v14647->regs;
  int v14651 = v14650[20];
  int v14658 = v14651 << 9;
  v14650[20] = v14658;
  struct StateT * v14653 = slot_243(v14647);
  return v14653;
}

struct StateT * slot_328(struct StateT * v15985) {
  int v15986 = v15985->timer;
  int v15993 = v15986 + 1;
  v15985->timer = v15993;
  int * v15988 = v15985->regs;
  int v15989 = v15988[22];
  int v15996 = v15989 << 9;
  v15988[22] = v15996;
  struct StateT * v15991 = slot_329(v15985);
  return v15991;
}

struct StateT * slot_402(struct StateT * v17196) {
  int v17197 = v17196->timer;
  int v17205 = v17197 + 1;
  v17196->timer = v17205;
  int * v17199 = v17196->regs;
  int v17200 = v17199[8];
  int v17201 = v17199[31];
  int v17210 = v17200 + v17201;
  v17199[23] = v17210;
  struct StateT * v17203 = slot_403(v17196);
  return v17203;
}

struct StateT * slot_200(struct StateT * v9947) {
  int v9948 = v9947->timer;
  int v9956 = v9948 + 1;
  v9947->timer = v9956;
  int * v9950 = v9947->regs;
  int v9951 = v9950[30];
  int v9952 = v9950[16];
  int v9961 = v9951 + v9952;
  v9950[20] = v9961;
  struct StateT * v9954 = slot_202(v9947);
  return v9954;
}

struct StateT * slot_149(struct StateT * v8067) {
  int v8068 = v8067->timer;
  int v8076 = v8068 + 1;
  v8067->timer = v8076;
  int * v8070 = v8067->regs;
  int v8071 = v8070[17];
  int v8072 = v8070[20];
  int v8080 = v8071 ^ v8072;
  v8070[17] = v8080;
  struct StateT * v8074 = slot_150(v8067);
  return v8074;
}

struct StateT * slot_527(struct StateT * v19229) {
  int v19230 = v19229->timer;
  int v19237 = v19230 + 1;
  v19229->timer = v19237;
  int * v19232 = v19229->regs;
  int v19233 = v19232[21];
  int v19240 = v19233 << 18;
  v19232[21] = v19240;
  struct StateT * v19235 = slot_528(v19229);
  return v19235;
}

struct StateT * slot_5(struct StateT * v1276) {
  int v1277 = v1276->timer;
  int v1447 = v1277 + 1;
  v1276->timer = v1447;
  int * v1279 = v1276->regs;
  int v1280 = v1279[2];
  int v1281 = v1279[20];
  int * v1282 = v1276->cache_tags;
  int v1452 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2;
  int v1283 = v1282[v1452];
  int v1453 = ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1284 = v1282[v1453];
  int v1454 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2);
  int v1285 = v1282[v1454];
  int v1455 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1286 = v1282[v1455];
  int v1287 = v1276->timer;
  int v1456 = v1287 + ((100 ^ (((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1276->timer = v1456;
  bool v1457 = !(((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v1381;
  if (v1457) {
    int * v1289 = v1276->cache_age;
    int v1459 = ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v1290 = v1289[v1459];
    int v1291 = v1289[v1452];
    int v1460 = v1291 + ((int)((unsigned int)(v1291 - v1290) >> 31));
    v1289[v1452] = v1460;
    int * v1293 = v1276->cache_age;
    int v1294 = v1293[v1453];
    int v1462 = v1294 + ((int)((unsigned int)(v1294 - v1290) >> 31));
    v1293[v1453] = v1462;
    int * v1296 = v1276->cache_age;
    v1296[v1459] = 0;
    v1381 = v1459;
  } else {
    int * v1299 = v1276->cache_age;
    int v1466 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2;
    int v1300 = v1299[v1466];
    int * v1301 = v1276->cache_tags;
    int v1302 = v1301[v1466];
    int v1303 = v1299[v1453];
    int v1304 = v1301[v1453];
    bool v1468 = !(((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v1358;
    if (v1468) {
      int * v1305 = v1276->cache_age;
      int v1470 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v1306 = v1305[v1470];
      int v1307 = v1305[v1454];
      int v1471 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
      v1305[v1454] = v1471;
      int * v1309 = v1276->cache_age;
      int v1310 = v1309[v1455];
      int v1473 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
      v1309[v1455] = v1473;
      int * v1312 = v1276->cache_age;
      v1312[v1470] = 0;
      v1358 = v1470;
    } else {
      int * v1315 = v1276->cache_age;
      int v1477 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2);
      int v1316 = v1315[v1477];
      int * v1317 = v1276->cache_tags;
      int v1318 = v1317[v1477];
      int v1319 = v1315[v1455];
      int v1320 = v1317[v1455];
      int * v1321 = v1276->cache_dirty;
      int v1480 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1322 = v1321[v1480];
      bool v1481 = !(v1322 == 0);
      if (v1481) {
        int * v1323 = v1276->cache_tags;
        int v1324 = v1323[v1480];
        int * v1325 = v1276->cache_vals;
        int v1484 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1326 = v1325[v1484];
        int v1485 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1327 = v1325[v1485];
        int * v1328 = v1276->mem;
        int v1487 = v1324 * 2;
        v1328[v1487] = v1326;
        int * v1330 = v1276->mem;
        int v1490 = (v1324 * 2) + 1;
        v1330[v1490] = v1327;
        ;
      } else {
        ;
      }
      int * v1335 = v1276->mem;
      int v1495 = ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2;
      int v1336 = v1335[v1495];
      int v1496 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2) + 1;
      int v1337 = v1335[v1496];
      int * v1338 = v1276->cache_vals;
      int v1498 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1338[v1498] = v1336;
      int * v1340 = v1276->cache_vals;
      int v1501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1340[v1501] = v1337;
      int * v1342 = v1276->cache_tags;
      int v1504 = (int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1);
      v1342[v1480] = v1504;
      int * v1344 = v1276->cache_dirty;
      v1344[v1480] = 0;
      int * v1346 = v1276->cache_age;
      v1346[v1480] = 1;
      int * v1348 = v1276->cache_age;
      int v1349 = v1348[v1480];
      int v1350 = v1348[v1454];
      int v1510 = v1350 + ((int)((unsigned int)(v1350 - v1349) >> 31));
      v1348[v1454] = v1510;
      int * v1352 = v1276->cache_age;
      int v1353 = v1352[v1455];
      int v1512 = v1353 + ((int)((unsigned int)(v1353 - v1349) >> 31));
      v1352[v1455] = v1512;
      int * v1355 = v1276->cache_age;
      v1355[v1480] = 0;
      v1358 = v1480;
    }
    int * v1359 = v1276->cache_vals;
    int v1515 = v1358 * 2;
    int v1360 = v1359[v1515];
    int v1516 = (v1358 * 2) + 1;
    int v1361 = v1359[v1516];
    int v1517 = (((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1359[v1517] = v1360;
    int * v1363 = v1276->cache_vals;
    int v1520 = ((((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1363[v1520] = v1361;
    int * v1365 = v1276->cache_tags;
    int v1523 = ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1524 = (int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1);
    v1365[v1523] = v1524;
    int * v1367 = v1276->cache_dirty;
    v1367[v1523] = 0;
    int * v1369 = v1276->cache_age;
    v1369[v1523] = 1;
    int * v1371 = v1276->cache_age;
    int v1372 = v1371[v1523];
    int v1373 = v1371[v1452];
    int v1530 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
    v1371[v1452] = v1530;
    int * v1375 = v1276->cache_age;
    int v1376 = v1375[v1453];
    int v1532 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
    v1375[v1453] = v1532;
    int * v1378 = v1276->cache_age;
    v1378[v1523] = 0;
    v1381 = v1523;
  }
  int * v1382 = v1276->cache_vals;
  int v1535 = (v1381 * 2) + (((int)((unsigned int)(v1280 + 28) >> 2)) & 1);
  v1382[v1535] = v1281;
  int * v1384 = v1276->cache_tags;
  int v1385 = v1384[v1454];
  int v1386 = v1384[v1455];
  bool v1538 = !(((~(((v1385 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1385 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v1440;
  if (v1538) {
    int * v1387 = v1276->cache_age;
    int v1540 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v1388 = v1387[v1540];
    int v1389 = v1387[v1454];
    int v1541 = v1389 + ((int)((unsigned int)(v1389 - v1388) >> 31));
    v1387[v1454] = v1541;
    int * v1391 = v1276->cache_age;
    int v1392 = v1391[v1455];
    int v1543 = v1392 + ((int)((unsigned int)(v1392 - v1388) >> 31));
    v1391[v1455] = v1543;
    int * v1394 = v1276->cache_age;
    v1394[v1540] = 0;
    v1440 = v1540;
  } else {
    int * v1397 = v1276->cache_age;
    int v1547 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2);
    int v1398 = v1397[v1547];
    int * v1399 = v1276->cache_tags;
    int v1400 = v1399[v1547];
    int v1401 = v1397[v1455];
    int v1402 = v1399[v1455];
    int * v1403 = v1276->cache_dirty;
    int v1550 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1404 = v1403[v1550];
    bool v1551 = !(v1404 == 0);
    if (v1551) {
      int * v1405 = v1276->cache_tags;
      int v1406 = v1405[v1550];
      int * v1407 = v1276->cache_vals;
      int v1554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1408 = v1407[v1554];
      int v1555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1409 = v1407[v1555];
      int * v1410 = v1276->mem;
      int v1557 = v1406 * 2;
      v1410[v1557] = v1408;
      int * v1412 = v1276->mem;
      int v1560 = (v1406 * 2) + 1;
      v1412[v1560] = v1409;
      ;
    } else {
      ;
    }
    int * v1417 = v1276->mem;
    int v1565 = ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2;
    int v1418 = v1417[v1565];
    int v1566 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2) + 1;
    int v1419 = v1417[v1566];
    int * v1420 = v1276->cache_vals;
    int v1568 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1420[v1568] = v1418;
    int * v1422 = v1276->cache_vals;
    int v1571 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1422[v1571] = v1419;
    int * v1424 = v1276->cache_tags;
    int v1574 = (int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1);
    v1424[v1550] = v1574;
    int * v1426 = v1276->cache_dirty;
    v1426[v1550] = 0;
    int * v1428 = v1276->cache_age;
    v1428[v1550] = 1;
    int * v1430 = v1276->cache_age;
    int v1431 = v1430[v1550];
    int v1432 = v1430[v1454];
    int v1580 = v1432 + ((int)((unsigned int)(v1432 - v1431) >> 31));
    v1430[v1454] = v1580;
    int * v1434 = v1276->cache_age;
    int v1435 = v1434[v1455];
    int v1582 = v1435 + ((int)((unsigned int)(v1435 - v1431) >> 31));
    v1434[v1455] = v1582;
    int * v1437 = v1276->cache_age;
    v1437[v1550] = 0;
    v1440 = v1550;
  }
  int * v1441 = v1276->cache_vals;
  int v1585 = (v1440 * 2) + (((int)((unsigned int)(v1280 + 28) >> 2)) & 1);
  v1441[v1585] = v1281;
  int * v1443 = v1276->cache_dirty;
  v1443[v1440] = 1;
  struct StateT * v1445 = slot_6(v1276);
  return v1445;
}

struct StateT * slot_334(struct StateT * v16076) {
  int v16077 = v16076->timer;
  int v16085 = v16077 + 1;
  v16076->timer = v16085;
  int * v16079 = v16076->regs;
  int v16080 = v16079[5];
  int v16081 = v16079[21];
  int v16089 = v16080 ^ v16081;
  v16079[5] = v16089;
  struct StateT * v16083 = slot_335(v16076);
  return v16083;
}

struct StateT * slot_104(struct StateT * v7340) {
  int v7341 = v7340->timer;
  int v7348 = v7341 + 1;
  v7340->timer = v7348;
  int * v7343 = v7340->regs;
  int v7344 = v7343[22];
  int v7351 = v7344 << 18;
  v7343[22] = v7351;
  struct StateT * v7346 = slot_105(v7340);
  return v7346;
}

struct StateT * slot_235(struct StateT * v14532) {
  int v14533 = v14532->timer;
  int v14541 = v14533 + 1;
  v14532->timer = v14541;
  int * v14535 = v14532->regs;
  int v14536 = v14535[19];
  int v14537 = v14535[22];
  int v14545 = v14536 ^ v14537;
  v14535[19] = v14545;
  struct StateT * v14539 = slot_236(v14532);
  return v14539;
}

struct StateT * slot_275(struct StateT * v15156) {
  int v15157 = v15156->timer;
  int v15165 = v15157 + 1;
  v15156->timer = v15165;
  int * v15159 = v15156->regs;
  int v15160 = v15159[12];
  int v15161 = v15159[22];
  int v15169 = v15160 ^ v15161;
  v15159[12] = v15169;
  struct StateT * v15163 = slot_276(v15156);
  return v15163;
}

struct StateT * slot_329(struct StateT * v15999) {
  int v16000 = v15999->timer;
  int v16008 = v16000 + 1;
  v15999->timer = v16008;
  int * v16002 = v15999->regs;
  int v16003 = v16002[22];
  int v16004 = v16002[24];
  int v16012 = v16003 | v16004;
  v16002[22] = v16012;
  struct StateT * v16006 = slot_330(v15999);
  return v16006;
}

struct StateT * slot_428(struct StateT * v17627) {
  int v17628 = v17627->timer;
  int v17636 = v17628 + 1;
  v17627->timer = v17636;
  int * v17630 = v17627->regs;
  int v17631 = v17630[21];
  int v17632 = v17630[24];
  int v17640 = v17631 | v17632;
  v17630[21] = v17640;
  struct StateT * v17634 = slot_429(v17627);
  return v17634;
}

struct StateT * slot_395(struct StateT * v17053) {
  int * v17054 = v17053->saved_regs;
  int * v17055 = v17053->regs;
  int v17056 = v17055[9];
  v17054[9] = v17056;
  int v17058 = v17053->timer;
  int v17070 = v17058 + 1;
  v17053->timer = v17070;
  int * v17060 = v17053->regs;
  int v17061 = v17060[9];
  int v17062 = v17060[20];
  int v17073 = v17061 ^ v17062;
  v17060[9] = v17073;
  struct StateT * v17064 = slot_396(v17053);
  return v17064;
}

struct StateT * slot_345(struct StateT * v16252) {
  int v16253 = v16252->timer;
  int v16260 = v16253 + 1;
  v16252->timer = v16260;
  int * v16255 = v16252->regs;
  int v16256 = v16255[21];
  int v16263 = v16256 << 13;
  v16255[21] = v16263;
  struct StateT * v16258 = slot_346(v16252);
  return v16258;
}

struct StateT * slot_298(struct StateT * v15517) {
  int v15518 = v15517->timer;
  int v15526 = v15518 + 1;
  v15517->timer = v15526;
  int * v15520 = v15517->regs;
  int v15521 = v15520[29];
  int v15522 = v15520[9];
  int v15531 = v15521 + v15522;
  v15520[21] = v15531;
  struct StateT * v15524 = slot_299(v15517);
  return v15524;
}

struct StateT * slot_414(struct StateT * v17377) {
  int v17378 = v17377->timer;
  int v17386 = v17378 + 1;
  v17377->timer = v17386;
  int * v17380 = v17377->regs;
  int v17381 = v17380[23];
  int v17382 = v17380[24];
  int v17390 = v17381 | v17382;
  v17380[23] = v17390;
  struct StateT * v17384 = slot_415(v17377);
  return v17384;
}

struct StateT * slot_364(struct StateT * v16549) {
  int v16550 = v16549->timer;
  int v16557 = v16550 + 1;
  v16549->timer = v16557;
  int * v16552 = v16549->regs;
  int v16553 = v16552[21];
  int v16561 = (int)((unsigned int)v16553 >> 14);
  v16552[24] = v16561;
  struct StateT * v16555 = slot_365(v16549);
  return v16555;
}

struct StateT * slot_356(struct StateT * v16420) {
  int v16421 = v16420->timer;
  int v16429 = v16421 + 1;
  v16420->timer = v16429;
  int * v16423 = v16420->regs;
  int v16424 = v16423[19];
  int v16425 = v16423[23];
  int v16433 = v16424 ^ v16425;
  v16423[19] = v16433;
  struct StateT * v16427 = slot_357(v16420);
  return v16427;
}

struct StateT * slot_253(struct StateT * v14812) {
  int v14813 = v14812->timer;
  int v14821 = v14813 + 1;
  v14812->timer = v14821;
  int * v14815 = v14812->regs;
  int v14816 = v14815[6];
  int v14817 = v14815[20];
  int v14825 = v14816 ^ v14817;
  v14815[6] = v14825;
  struct StateT * v14819 = slot_254(v14812);
  return v14819;
}

struct StateT * slot_434(struct StateT * v17717) {
  int v17718 = v17717->timer;
  int v17726 = v17718 + 1;
  v17717->timer = v17726;
  int * v17720 = v17717->regs;
  int v17721 = v17720[23];
  int v17722 = v17720[24];
  int v17730 = v17721 | v17722;
  v17720[23] = v17730;
  struct StateT * v17724 = slot_435(v17717);
  return v17724;
}

struct StateT * slot_64(struct StateT * v6660) {
  int v6661 = v6660->timer;
  int v6668 = v6661 + 1;
  v6660->timer = v6668;
  int * v6663 = v6660->regs;
  int v6664 = v6663[22];
  int v6671 = v6664 << 9;
  v6663[22] = v6671;
  struct StateT * v6666 = slot_65(v6660);
  return v6666;
}

struct StateT * slot_170(struct StateT * v8395) {
  int v8396 = v8395->timer;
  int v8404 = v8396 + 1;
  v8395->timer = v8404;
  int * v8398 = v8395->regs;
  int v8399 = v8398[9];
  int v8400 = v8398[21];
  int v8408 = v8399 ^ v8400;
  v8398[9] = v8408;
  struct StateT * v8402 = slot_171(v8395);
  return v8402;
}

struct StateT * slot_53(struct StateT * v6487) {
  int v6488 = v6487->timer;
  int v6496 = v6488 + 1;
  v6487->timer = v6496;
  int * v6490 = v6487->regs;
  int v6491 = v6490[9];
  int v6492 = v6490[30];
  int v6501 = v6491 + v6492;
  v6490[20] = v6501;
  struct StateT * v6494 = slot_54(v6487);
  return v6494;
}

struct StateT * slot_522(struct StateT * v19152) {
  int v19153 = v19152->timer;
  int v19161 = v19153 + 1;
  v19152->timer = v19161;
  int * v19155 = v19152->regs;
  int v19156 = v19155[19];
  int v19157 = v19155[7];
  int v19166 = v19156 + v19157;
  v19155[23] = v19166;
  struct StateT * v19159 = slot_523(v19152);
  return v19159;
}

struct StateT * slot_80(struct StateT * v6940) {
  int v6941 = v6940->timer;
  int v6948 = v6941 + 1;
  v6940->timer = v6948;
  int * v6943 = v6940->regs;
  int v6944 = v6943[21];
  int v6952 = (int)((unsigned int)v6944 >> 19);
  v6943[24] = v6952;
  struct StateT * v6946 = slot_81(v6940);
  return v6946;
}

struct StateT * slot_503(struct StateT * v18857) {
  int v18858 = v18857->timer;
  int v18865 = v18858 + 1;
  v18857->timer = v18865;
  int * v18860 = v18857->regs;
  int v18861 = v18860[20];
  int v18869 = (int)((unsigned int)v18861 >> 19);
  v18860[24] = v18869;
  struct StateT * v18863 = slot_504(v18857);
  return v18863;
}

struct StateT * slot_390(struct StateT * v16978) {
  int v16979 = v16978->timer;
  int v16986 = v16979 + 1;
  v16978->timer = v16986;
  int * v16981 = v16978->regs;
  int v16982 = v16981[22];
  int v16989 = v16982 << 7;
  v16981[22] = v16989;
  struct StateT * v16984 = slot_391(v16978);
  return v16984;
}

struct StateT * slot_44(struct StateT * v6320) {
  int v6321 = v6320->timer;
  int v6328 = v6321 + 1;
  v6320->timer = v6328;
  int * v6323 = v6320->regs;
  int v6324 = v6323[22];
  int v6331 = v6324 << 7;
  v6323[22] = v6331;
  struct StateT * v6326 = slot_45(v6320);
  return v6326;
}

struct StateT * slot_137(struct StateT * v7887) {
  int v7888 = v7887->timer;
  int v7895 = v7888 + 1;
  v7887->timer = v7895;
  int * v7890 = v7887->regs;
  int v7891 = v7890[20];
  int v7899 = (int)((unsigned int)v7891 >> 23);
  v7890[24] = v7899;
  struct StateT * v7893 = slot_138(v7887);
  return v7893;
}

struct StateT * slot_386(struct StateT * v16918) {
  int v16919 = v16918->timer;
  int v16926 = v16919 + 1;
  v16918->timer = v16926;
  int * v16921 = v16918->regs;
  int v16922 = v16921[21];
  int v16930 = (int)((unsigned int)v16922 >> 25);
  v16921[24] = v16930;
  struct StateT * v16924 = slot_387(v16918);
  return v16924;
}

struct StateT * slot_122(struct StateT * v7649) {
  int v7650 = v7649->timer;
  int v7658 = v7650 + 1;
  v7649->timer = v7658;
  int * v7652 = v7649->regs;
  int v7653 = v7652[21];
  int v7654 = v7652[24];
  int v7662 = v7653 | v7654;
  v7652[21] = v7662;
  struct StateT * v7656 = slot_123(v7649);
  return v7656;
}

struct StateT * slot_99(struct StateT * v7264) {
  int v7265 = v7264->timer;
  int v7273 = v7265 + 1;
  v7264->timer = v7273;
  int * v7267 = v7264->regs;
  int v7268 = v7267[20];
  int v7269 = v7267[24];
  int v7277 = v7268 | v7269;
  v7267[20] = v7277;
  struct StateT * v7271 = slot_100(v7264);
  return v7271;
}

struct StateT * slot_179(struct StateT * v8540) {
  int v8541 = v8540->timer;
  int v8549 = v8541 + 1;
  v8540->timer = v8549;
  int * v8543 = v8540->regs;
  int v8544 = v8543[20];
  int v8545 = v8543[24];
  int v8553 = v8544 | v8545;
  v8543[20] = v8553;
  struct StateT * v8547 = slot_180(v8540);
  return v8547;
}

struct StateT * slot_219(struct StateT * v13545) {
  int v13546 = v13545->timer;
  int v13656 = v13546 + 1;
  v13545->timer = v13656;
  int * v13548 = v13545->regs;
  int v13549 = v13548[2];
  int * v13550 = v13545->cache_tags;
  int v13660 = (((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2;
  int v13551 = v13550[v13660];
  int v13661 = ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13552 = v13550[v13661];
  int v13662 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2);
  int v13553 = v13550[v13662];
  int v13663 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13554 = v13550[v13663];
  int v13555 = v13545->timer;
  int v13664 = v13555 + ((100 ^ (((~(((v13553 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13553 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13551 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13551 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13552 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13552 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13553 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13553 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13545->timer = v13664;
  int * v13557 = v13545->cache_vals;
  bool v13665 = !(((~(((v13551 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13551 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13552 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13552 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v13650;
  if (v13665) {
    int * v13558 = v13545->cache_age;
    int v13667 = ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v13552 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13552 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v13559 = v13558[v13667];
    int v13560 = v13558[v13660];
    int v13668 = v13560 + ((int)((unsigned int)(v13560 - v13559) >> 31));
    v13558[v13660] = v13668;
    int * v13562 = v13545->cache_age;
    int v13563 = v13562[v13661];
    int v13670 = v13563 + ((int)((unsigned int)(v13563 - v13559) >> 31));
    v13562[v13661] = v13670;
    int * v13565 = v13545->cache_age;
    v13565[v13667] = 0;
    v13650 = v13667;
  } else {
    int * v13568 = v13545->cache_age;
    int v13674 = (((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2;
    int v13569 = v13568[v13674];
    int * v13570 = v13545->cache_tags;
    int v13571 = v13570[v13674];
    int v13572 = v13568[v13661];
    int v13573 = v13570[v13661];
    bool v13676 = !(((~(((v13553 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13553 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v13627;
    if (v13676) {
      int * v13574 = v13545->cache_age;
      int v13678 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))) | (-(v13554 ^ ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v13575 = v13574[v13678];
      int v13576 = v13574[v13662];
      int v13679 = v13576 + ((int)((unsigned int)(v13576 - v13575) >> 31));
      v13574[v13662] = v13679;
      int * v13578 = v13545->cache_age;
      int v13579 = v13578[v13663];
      int v13681 = v13579 + ((int)((unsigned int)(v13579 - v13575) >> 31));
      v13578[v13663] = v13681;
      int * v13581 = v13545->cache_age;
      v13581[v13678] = 0;
      v13627 = v13678;
    } else {
      int * v13584 = v13545->cache_age;
      int v13685 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2);
      int v13585 = v13584[v13685];
      int * v13586 = v13545->cache_tags;
      int v13587 = v13586[v13685];
      int v13588 = v13584[v13663];
      int v13589 = v13586[v13663];
      int * v13590 = v13545->cache_dirty;
      int v13688 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v13585 + ((~(((v13587 ^ -1) | (-(v13587 ^ -1))) >> 31)) & 2)) - (v13588 + ((~(((v13589 ^ -1) | (-(v13589 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13591 = v13590[v13688];
      bool v13689 = !(v13591 == 0);
      if (v13689) {
        int * v13592 = v13545->cache_tags;
        int v13593 = v13592[v13688];
        int * v13594 = v13545->cache_vals;
        int v13692 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v13585 + ((~(((v13587 ^ -1) | (-(v13587 ^ -1))) >> 31)) & 2)) - (v13588 + ((~(((v13589 ^ -1) | (-(v13589 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13595 = v13594[v13692];
        int v13693 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v13585 + ((~(((v13587 ^ -1) | (-(v13587 ^ -1))) >> 31)) & 2)) - (v13588 + ((~(((v13589 ^ -1) | (-(v13589 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13596 = v13594[v13693];
        int * v13597 = v13545->mem;
        int v13695 = v13593 * 2;
        v13597[v13695] = v13595;
        int * v13599 = v13545->mem;
        int v13698 = (v13593 * 2) + 1;
        v13599[v13698] = v13596;
        ;
      } else {
        ;
      }
      int * v13604 = v13545->mem;
      int v13703 = ((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) * 2;
      int v13605 = v13604[v13703];
      int v13704 = (((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) * 2) + 1;
      int v13606 = v13604[v13704];
      int * v13607 = v13545->cache_vals;
      int v13706 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v13585 + ((~(((v13587 ^ -1) | (-(v13587 ^ -1))) >> 31)) & 2)) - (v13588 + ((~(((v13589 ^ -1) | (-(v13589 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13607[v13706] = v13605;
      int * v13609 = v13545->cache_vals;
      int v13709 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v13585 + ((~(((v13587 ^ -1) | (-(v13587 ^ -1))) >> 31)) & 2)) - (v13588 + ((~(((v13589 ^ -1) | (-(v13589 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13609[v13709] = v13606;
      int * v13611 = v13545->cache_tags;
      int v13712 = (int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1);
      v13611[v13688] = v13712;
      int * v13613 = v13545->cache_dirty;
      v13613[v13688] = 0;
      int * v13615 = v13545->cache_age;
      v13615[v13688] = 1;
      int * v13617 = v13545->cache_age;
      int v13618 = v13617[v13688];
      int v13619 = v13617[v13662];
      int v13718 = v13619 + ((int)((unsigned int)(v13619 - v13618) >> 31));
      v13617[v13662] = v13718;
      int * v13621 = v13545->cache_age;
      int v13622 = v13621[v13663];
      int v13720 = v13622 + ((int)((unsigned int)(v13622 - v13618) >> 31));
      v13621[v13663] = v13720;
      int * v13624 = v13545->cache_age;
      v13624[v13688] = 0;
      v13627 = v13688;
    }
    int * v13628 = v13545->cache_vals;
    int v13723 = v13627 * 2;
    int v13629 = v13628[v13723];
    int v13724 = (v13627 * 2) + 1;
    int v13630 = v13628[v13724];
    int v13725 = (((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v13569 + ((~(((v13571 ^ -1) | (-(v13571 ^ -1))) >> 31)) & 2)) - (v13572 + ((~(((v13573 ^ -1) | (-(v13573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13628[v13725] = v13629;
    int * v13632 = v13545->cache_vals;
    int v13728 = ((((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v13569 + ((~(((v13571 ^ -1) | (-(v13571 ^ -1))) >> 31)) & 2)) - (v13572 + ((~(((v13573 ^ -1) | (-(v13573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13632[v13728] = v13630;
    int * v13634 = v13545->cache_tags;
    int v13731 = ((((int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v13569 + ((~(((v13571 ^ -1) | (-(v13571 ^ -1))) >> 31)) & 2)) - (v13572 + ((~(((v13573 ^ -1) | (-(v13573 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13732 = (int)((unsigned int)((int)((unsigned int)(v13549 + 20) >> 2)) >> 1);
    v13634[v13731] = v13732;
    int * v13636 = v13545->cache_dirty;
    v13636[v13731] = 0;
    int * v13638 = v13545->cache_age;
    v13638[v13731] = 1;
    int * v13640 = v13545->cache_age;
    int v13641 = v13640[v13731];
    int v13642 = v13640[v13660];
    int v13738 = v13642 + ((int)((unsigned int)(v13642 - v13641) >> 31));
    v13640[v13660] = v13738;
    int * v13644 = v13545->cache_age;
    int v13645 = v13644[v13661];
    int v13740 = v13645 + ((int)((unsigned int)(v13645 - v13641) >> 31));
    v13644[v13661] = v13740;
    int * v13647 = v13545->cache_age;
    v13647[v13731] = 0;
    v13650 = v13731;
  }
  int v13743 = (v13650 * 2) + (((int)((unsigned int)(v13549 + 20) >> 2)) & 1);
  int v13651 = v13557[v13743];
  int * v13652 = v13545->regs;
  v13652[22] = v13651;
  struct StateT * v13654 = slot_221(v13545);
  return v13654;
}

struct StateT * slot_338(struct StateT * v16141) {
  int v16142 = v16141->timer;
  int v16150 = v16142 + 1;
  v16141->timer = v16150;
  int * v16144 = v16141->regs;
  int v16145 = v16144[5];
  int v16146 = v16144[12];
  int v16155 = v16145 + v16146;
  v16144[21] = v16155;
  struct StateT * v16148 = slot_339(v16141);
  return v16148;
}

struct StateT * slot_22(struct StateT * v5776) {
  int v5777 = v5776->timer;
  int v5887 = v5777 + 1;
  v5776->timer = v5887;
  int * v5779 = v5776->regs;
  int v5780 = v5779[11];
  int * v5781 = v5776->cache_tags;
  int v5891 = (((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2;
  int v5782 = v5781[v5891];
  int v5892 = ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5783 = v5781[v5892];
  int v5893 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2);
  int v5784 = v5781[v5893];
  int v5894 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5785 = v5781[v5894];
  int v5786 = v5776->timer;
  int v5895 = v5786 + ((100 ^ (((~(((v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5776->timer = v5895;
  int * v5788 = v5776->cache_vals;
  bool v5896 = !(((~(((v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5782 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5881;
  if (v5896) {
    int * v5789 = v5776->cache_age;
    int v5898 = ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5783 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5790 = v5789[v5898];
    int v5791 = v5789[v5891];
    int v5899 = v5791 + ((int)((unsigned int)(v5791 - v5790) >> 31));
    v5789[v5891] = v5899;
    int * v5793 = v5776->cache_age;
    int v5794 = v5793[v5892];
    int v5901 = v5794 + ((int)((unsigned int)(v5794 - v5790) >> 31));
    v5793[v5892] = v5901;
    int * v5796 = v5776->cache_age;
    v5796[v5898] = 0;
    v5881 = v5898;
  } else {
    int * v5799 = v5776->cache_age;
    int v5905 = (((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2;
    int v5800 = v5799[v5905];
    int * v5801 = v5776->cache_tags;
    int v5802 = v5801[v5905];
    int v5803 = v5799[v5892];
    int v5804 = v5801[v5892];
    bool v5907 = !(((~(((v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5784 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v5858;
    if (v5907) {
      int * v5805 = v5776->cache_age;
      int v5909 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))) | (-(v5785 ^ ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v5806 = v5805[v5909];
      int v5807 = v5805[v5893];
      int v5910 = v5807 + ((int)((unsigned int)(v5807 - v5806) >> 31));
      v5805[v5893] = v5910;
      int * v5809 = v5776->cache_age;
      int v5810 = v5809[v5894];
      int v5912 = v5810 + ((int)((unsigned int)(v5810 - v5806) >> 31));
      v5809[v5894] = v5912;
      int * v5812 = v5776->cache_age;
      v5812[v5909] = 0;
      v5858 = v5909;
    } else {
      int * v5815 = v5776->cache_age;
      int v5916 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2);
      int v5816 = v5815[v5916];
      int * v5817 = v5776->cache_tags;
      int v5818 = v5817[v5916];
      int v5819 = v5815[v5894];
      int v5820 = v5817[v5894];
      int * v5821 = v5776->cache_dirty;
      int v5919 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5816 + ((~(((v5818 ^ -1) | (-(v5818 ^ -1))) >> 31)) & 2)) - (v5819 + ((~(((v5820 ^ -1) | (-(v5820 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5822 = v5821[v5919];
      bool v5920 = !(v5822 == 0);
      if (v5920) {
        int * v5823 = v5776->cache_tags;
        int v5824 = v5823[v5919];
        int * v5825 = v5776->cache_vals;
        int v5923 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5816 + ((~(((v5818 ^ -1) | (-(v5818 ^ -1))) >> 31)) & 2)) - (v5819 + ((~(((v5820 ^ -1) | (-(v5820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5826 = v5825[v5923];
        int v5924 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5816 + ((~(((v5818 ^ -1) | (-(v5818 ^ -1))) >> 31)) & 2)) - (v5819 + ((~(((v5820 ^ -1) | (-(v5820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5827 = v5825[v5924];
        int * v5828 = v5776->mem;
        int v5926 = v5824 * 2;
        v5828[v5926] = v5826;
        int * v5830 = v5776->mem;
        int v5929 = (v5824 * 2) + 1;
        v5830[v5929] = v5827;
        ;
      } else {
        ;
      }
      int * v5835 = v5776->mem;
      int v5934 = ((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) * 2;
      int v5836 = v5835[v5934];
      int v5935 = (((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) * 2) + 1;
      int v5837 = v5835[v5935];
      int * v5838 = v5776->cache_vals;
      int v5937 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5816 + ((~(((v5818 ^ -1) | (-(v5818 ^ -1))) >> 31)) & 2)) - (v5819 + ((~(((v5820 ^ -1) | (-(v5820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5838[v5937] = v5836;
      int * v5840 = v5776->cache_vals;
      int v5940 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5816 + ((~(((v5818 ^ -1) | (-(v5818 ^ -1))) >> 31)) & 2)) - (v5819 + ((~(((v5820 ^ -1) | (-(v5820 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5840[v5940] = v5837;
      int * v5842 = v5776->cache_tags;
      int v5943 = (int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1);
      v5842[v5919] = v5943;
      int * v5844 = v5776->cache_dirty;
      v5844[v5919] = 0;
      int * v5846 = v5776->cache_age;
      v5846[v5919] = 1;
      int * v5848 = v5776->cache_age;
      int v5849 = v5848[v5919];
      int v5850 = v5848[v5893];
      int v5949 = v5850 + ((int)((unsigned int)(v5850 - v5849) >> 31));
      v5848[v5893] = v5949;
      int * v5852 = v5776->cache_age;
      int v5853 = v5852[v5894];
      int v5951 = v5853 + ((int)((unsigned int)(v5853 - v5849) >> 31));
      v5852[v5894] = v5951;
      int * v5855 = v5776->cache_age;
      v5855[v5919] = 0;
      v5858 = v5919;
    }
    int * v5859 = v5776->cache_vals;
    int v5954 = v5858 * 2;
    int v5860 = v5859[v5954];
    int v5955 = (v5858 * 2) + 1;
    int v5861 = v5859[v5955];
    int v5956 = (((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5800 + ((~(((v5802 ^ -1) | (-(v5802 ^ -1))) >> 31)) & 2)) - (v5803 + ((~(((v5804 ^ -1) | (-(v5804 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5859[v5956] = v5860;
    int * v5863 = v5776->cache_vals;
    int v5959 = ((((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5800 + ((~(((v5802 ^ -1) | (-(v5802 ^ -1))) >> 31)) & 2)) - (v5803 + ((~(((v5804 ^ -1) | (-(v5804 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5863[v5959] = v5861;
    int * v5865 = v5776->cache_tags;
    int v5962 = ((((int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5800 + ((~(((v5802 ^ -1) | (-(v5802 ^ -1))) >> 31)) & 2)) - (v5803 + ((~(((v5804 ^ -1) | (-(v5804 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5963 = (int)((unsigned int)((int)((unsigned int)(v5780 + 12) >> 2)) >> 1);
    v5865[v5962] = v5963;
    int * v5867 = v5776->cache_dirty;
    v5867[v5962] = 0;
    int * v5869 = v5776->cache_age;
    v5869[v5962] = 1;
    int * v5871 = v5776->cache_age;
    int v5872 = v5871[v5962];
    int v5873 = v5871[v5891];
    int v5969 = v5873 + ((int)((unsigned int)(v5873 - v5872) >> 31));
    v5871[v5891] = v5969;
    int * v5875 = v5776->cache_age;
    int v5876 = v5875[v5892];
    int v5971 = v5876 + ((int)((unsigned int)(v5876 - v5872) >> 31));
    v5875[v5892] = v5971;
    int * v5878 = v5776->cache_age;
    v5878[v5962] = 0;
    v5881 = v5962;
  }
  int v5974 = (v5881 * 2) + (((int)((unsigned int)(v5780 + 12) >> 2)) & 1);
  int v5882 = v5788[v5974];
  int * v5883 = v5776->regs;
  v5883[18] = v5882;
  struct StateT * v5885 = slot_23(v5776);
  return v5885;
}

struct StateT * slot_366(struct StateT * v16578) {
  int v16579 = v16578->timer;
  int v16587 = v16579 + 1;
  v16578->timer = v16587;
  int * v16581 = v16578->regs;
  int v16582 = v16581[21];
  int v16583 = v16581[24];
  int v16591 = v16582 | v16583;
  v16581[21] = v16591;
  struct StateT * v16585 = slot_367(v16578);
  return v16585;
}

struct StateT * slot_139(struct StateT * v7916) {
  int v7917 = v7916->timer;
  int v7925 = v7917 + 1;
  v7916->timer = v7925;
  int * v7919 = v7916->regs;
  int v7920 = v7919[20];
  int v7921 = v7919[24];
  int v7929 = v7920 | v7921;
  v7919[20] = v7929;
  struct StateT * v7923 = slot_140(v7916);
  return v7923;
}

struct StateT * slot_438(struct StateT * v17802) {
  int * v17803 = v17802->saved_regs;
  int * v17804 = v17802->regs;
  int v17805 = v17804[15];
  v17803[15] = v17805;
  int v17807 = v17802->timer;
  int v17819 = v17807 + 1;
  v17802->timer = v17819;
  int * v17809 = v17802->regs;
  int v17810 = v17809[15];
  int v17811 = v17809[23];
  int v17822 = v17810 ^ v17811;
  v17809[15] = v17822;
  struct StateT * v17813 = slot_439(v17802);
  return v17813;
}

struct StateT * slot_333(struct StateT * v16060) {
  int v16061 = v16060->timer;
  int v16069 = v16061 + 1;
  v16060->timer = v16069;
  int * v16063 = v16060->regs;
  int v16064 = v16063[17];
  int v16065 = v16063[20];
  int v16073 = v16064 ^ v16065;
  v16063[17] = v16073;
  struct StateT * v16067 = slot_334(v16060);
  return v16067;
}

struct StateT * slot_221(struct StateT * v13967) {
  int v13968 = v13967->timer;
  int v14078 = v13968 + 1;
  v13967->timer = v14078;
  int * v13970 = v13967->regs;
  int v13971 = v13970[2];
  int * v13972 = v13967->cache_tags;
  int v14082 = (((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2;
  int v13973 = v13972[v14082];
  int v14083 = ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13974 = v13972[v14083];
  int v14084 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2);
  int v13975 = v13972[v14084];
  int v14085 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13976 = v13972[v14085];
  int v13977 = v13967->timer;
  int v14086 = v13977 + ((100 ^ (((~(((v13975 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13975 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13973 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13973 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13974 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13974 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13975 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13975 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13967->timer = v14086;
  int * v13979 = v13967->cache_vals;
  bool v14087 = !(((~(((v13973 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13973 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13974 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13974 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v14072;
  if (v14087) {
    int * v13980 = v13967->cache_age;
    int v14089 = ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v13974 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13974 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v13981 = v13980[v14089];
    int v13982 = v13980[v14082];
    int v14090 = v13982 + ((int)((unsigned int)(v13982 - v13981) >> 31));
    v13980[v14082] = v14090;
    int * v13984 = v13967->cache_age;
    int v13985 = v13984[v14083];
    int v14092 = v13985 + ((int)((unsigned int)(v13985 - v13981) >> 31));
    v13984[v14083] = v14092;
    int * v13987 = v13967->cache_age;
    v13987[v14089] = 0;
    v14072 = v14089;
  } else {
    int * v13990 = v13967->cache_age;
    int v14096 = (((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2;
    int v13991 = v13990[v14096];
    int * v13992 = v13967->cache_tags;
    int v13993 = v13992[v14096];
    int v13994 = v13990[v14083];
    int v13995 = v13992[v14083];
    bool v14098 = !(((~(((v13975 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13975 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v14049;
    if (v14098) {
      int * v13996 = v13967->cache_age;
      int v14100 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))) | (-(v13976 ^ ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v13997 = v13996[v14100];
      int v13998 = v13996[v14084];
      int v14101 = v13998 + ((int)((unsigned int)(v13998 - v13997) >> 31));
      v13996[v14084] = v14101;
      int * v14000 = v13967->cache_age;
      int v14001 = v14000[v14085];
      int v14103 = v14001 + ((int)((unsigned int)(v14001 - v13997) >> 31));
      v14000[v14085] = v14103;
      int * v14003 = v13967->cache_age;
      v14003[v14100] = 0;
      v14049 = v14100;
    } else {
      int * v14006 = v13967->cache_age;
      int v14107 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2);
      int v14007 = v14006[v14107];
      int * v14008 = v13967->cache_tags;
      int v14009 = v14008[v14107];
      int v14010 = v14006[v14085];
      int v14011 = v14008[v14085];
      int * v14012 = v13967->cache_dirty;
      int v14110 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v14007 + ((~(((v14009 ^ -1) | (-(v14009 ^ -1))) >> 31)) & 2)) - (v14010 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14013 = v14012[v14110];
      bool v14111 = !(v14013 == 0);
      if (v14111) {
        int * v14014 = v13967->cache_tags;
        int v14015 = v14014[v14110];
        int * v14016 = v13967->cache_vals;
        int v14114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v14007 + ((~(((v14009 ^ -1) | (-(v14009 ^ -1))) >> 31)) & 2)) - (v14010 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14017 = v14016[v14114];
        int v14115 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v14007 + ((~(((v14009 ^ -1) | (-(v14009 ^ -1))) >> 31)) & 2)) - (v14010 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14018 = v14016[v14115];
        int * v14019 = v13967->mem;
        int v14117 = v14015 * 2;
        v14019[v14117] = v14017;
        int * v14021 = v13967->mem;
        int v14120 = (v14015 * 2) + 1;
        v14021[v14120] = v14018;
        ;
      } else {
        ;
      }
      int * v14026 = v13967->mem;
      int v14125 = ((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) * 2;
      int v14027 = v14026[v14125];
      int v14126 = (((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) * 2) + 1;
      int v14028 = v14026[v14126];
      int * v14029 = v13967->cache_vals;
      int v14128 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v14007 + ((~(((v14009 ^ -1) | (-(v14009 ^ -1))) >> 31)) & 2)) - (v14010 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14029[v14128] = v14027;
      int * v14031 = v13967->cache_vals;
      int v14131 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v14007 + ((~(((v14009 ^ -1) | (-(v14009 ^ -1))) >> 31)) & 2)) - (v14010 + ((~(((v14011 ^ -1) | (-(v14011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14031[v14131] = v14028;
      int * v14033 = v13967->cache_tags;
      int v14134 = (int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1);
      v14033[v14110] = v14134;
      int * v14035 = v13967->cache_dirty;
      v14035[v14110] = 0;
      int * v14037 = v13967->cache_age;
      v14037[v14110] = 1;
      int * v14039 = v13967->cache_age;
      int v14040 = v14039[v14110];
      int v14041 = v14039[v14084];
      int v14140 = v14041 + ((int)((unsigned int)(v14041 - v14040) >> 31));
      v14039[v14084] = v14140;
      int * v14043 = v13967->cache_age;
      int v14044 = v14043[v14085];
      int v14142 = v14044 + ((int)((unsigned int)(v14044 - v14040) >> 31));
      v14043[v14085] = v14142;
      int * v14046 = v13967->cache_age;
      v14046[v14110] = 0;
      v14049 = v14110;
    }
    int * v14050 = v13967->cache_vals;
    int v14145 = v14049 * 2;
    int v14051 = v14050[v14145];
    int v14146 = (v14049 * 2) + 1;
    int v14052 = v14050[v14146];
    int v14147 = (((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v13991 + ((~(((v13993 ^ -1) | (-(v13993 ^ -1))) >> 31)) & 2)) - (v13994 + ((~(((v13995 ^ -1) | (-(v13995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14050[v14147] = v14051;
    int * v14054 = v13967->cache_vals;
    int v14150 = ((((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v13991 + ((~(((v13993 ^ -1) | (-(v13993 ^ -1))) >> 31)) & 2)) - (v13994 + ((~(((v13995 ^ -1) | (-(v13995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14054[v14150] = v14052;
    int * v14056 = v13967->cache_tags;
    int v14153 = ((((int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v13991 + ((~(((v13993 ^ -1) | (-(v13993 ^ -1))) >> 31)) & 2)) - (v13994 + ((~(((v13995 ^ -1) | (-(v13995 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14154 = (int)((unsigned int)((int)((unsigned int)(v13971 + 16) >> 2)) >> 1);
    v14056[v14153] = v14154;
    int * v14058 = v13967->cache_dirty;
    v14058[v14153] = 0;
    int * v14060 = v13967->cache_age;
    v14060[v14153] = 1;
    int * v14062 = v13967->cache_age;
    int v14063 = v14062[v14153];
    int v14064 = v14062[v14082];
    int v14160 = v14064 + ((int)((unsigned int)(v14064 - v14063) >> 31));
    v14062[v14082] = v14160;
    int * v14066 = v13967->cache_age;
    int v14067 = v14066[v14083];
    int v14162 = v14067 + ((int)((unsigned int)(v14067 - v14063) >> 31));
    v14066[v14083] = v14162;
    int * v14069 = v13967->cache_age;
    v14069[v14153] = 0;
    v14072 = v14153;
  }
  int v14165 = (v14072 * 2) + (((int)((unsigned int)(v13971 + 16) >> 2)) & 1);
  int v14073 = v13979[v14165];
  int * v14074 = v13967->regs;
  v14074[23] = v14073;
  struct StateT * v14076 = slot_223(v13967);
  return v14076;
}

struct StateT * slot_153(struct StateT * v8131) {
  int v8132 = v8131->timer;
  int v8140 = v8132 + 1;
  v8131->timer = v8140;
  int * v8134 = v8131->regs;
  int v8135 = v8134[17];
  int v8136 = v8134[14];
  int v8145 = v8135 + v8136;
  v8134[20] = v8145;
  struct StateT * v8138 = slot_154(v8131);
  return v8138;
}

struct StateT * slot_129(struct StateT * v7755) {
  int v7756 = v7755->timer;
  int v7764 = v7756 + 1;
  v7755->timer = v7764;
  int * v7758 = v7755->regs;
  int v7759 = v7758[14];
  int v7760 = v7758[20];
  int v7768 = v7759 ^ v7760;
  v7758[14] = v7768;
  struct StateT * v7762 = slot_130(v7755);
  return v7762;
}

struct StateT * slot_158(struct StateT * v8214) {
  int v8215 = v8214->timer;
  int v8222 = v8215 + 1;
  v8214->timer = v8222;
  int * v8217 = v8214->regs;
  int v8218 = v8217[20];
  int v8225 = v8218 << 13;
  v8217[20] = v8225;
  struct StateT * v8220 = slot_159(v8214);
  return v8220;
}

struct StateT * slot_311(struct StateT * v15718) {
  int v15719 = v15718->timer;
  int v15726 = v15719 + 1;
  v15718->timer = v15726;
  int * v15721 = v15718->regs;
  int v15722 = v15721[23];
  int v15729 = v15722 << 7;
  v15721[23] = v15729;
  struct StateT * v15724 = slot_312(v15718);
  return v15724;
}

struct StateT * slot_498(struct StateT * v18773) {
  int v18774 = v18773->timer;
  int v18782 = v18774 + 1;
  v18773->timer = v18782;
  int * v18776 = v18773->regs;
  int v18777 = v18776[7];
  int v18778 = v18776[23];
  int v18786 = v18777 ^ v18778;
  v18776[7] = v18786;
  struct StateT * v18780 = slot_499(v18773);
  return v18780;
}

struct StateT * slot_279(struct StateT * v15222) {
  int v15223 = v15222->timer;
  int v15231 = v15223 + 1;
  v15222->timer = v15231;
  int * v15225 = v15222->regs;
  int v15226 = v15225[12];
  int v15227 = v15225[17];
  int v15236 = v15226 + v15227;
  v15225[22] = v15236;
  struct StateT * v15229 = slot_280(v15222);
  return v15229;
}

struct StateT * slot_271(struct StateT * v15094) {
  int v15095 = v15094->timer;
  int v15102 = v15095 + 1;
  v15094->timer = v15102;
  int * v15097 = v15094->regs;
  int v15098 = v15097[23];
  int v15105 = v15098 << 13;
  v15097[23] = v15105;
  struct StateT * v15100 = slot_272(v15094);
  return v15100;
}

struct StateT * slot_524(struct StateT * v19184) {
  int v19185 = v19184->timer;
  int v19192 = v19185 + 1;
  v19184->timer = v19192;
  int * v19187 = v19184->regs;
  int v19188 = v19187[20];
  int v19195 = v19188 << 18;
  v19187[20] = v19195;
  struct StateT * v19190 = slot_525(v19184);
  return v19190;
}

struct StateT * slot_505(struct StateT * v18886) {
  int v18887 = v18886->timer;
  int v18895 = v18887 + 1;
  v18886->timer = v18895;
  int * v18889 = v18886->regs;
  int v18890 = v18889[20];
  int v18891 = v18889[24];
  int v18899 = v18890 | v18891;
  v18889[20] = v18899;
  struct StateT * v18893 = slot_506(v18886);
  return v18893;
}

struct StateT * slot_401(struct StateT * v17179) {
  int v17180 = v17179->timer;
  int v17188 = v17180 + 1;
  v17179->timer = v17188;
  int * v17182 = v17179->regs;
  int v17183 = v17182[19];
  int v17184 = v17182[28];
  int v17193 = v17183 + v17184;
  v17182[22] = v17193;
  struct StateT * v17186 = slot_402(v17179);
  return v17186;
}

struct StateT * slot_423(struct StateT * v17553) {
  int v17554 = v17553->timer;
  int v17561 = v17554 + 1;
  v17553->timer = v17561;
  int * v17556 = v17553->regs;
  int v17557 = v17556[20];
  int v17565 = (int)((unsigned int)v17557 >> 19);
  v17556[24] = v17565;
  struct StateT * v17559 = slot_424(v17553);
  return v17559;
}

struct StateT * slot_532(struct StateT * v19304) {
  int v19305 = v19304->timer;
  int v19312 = v19305 + 1;
  v19304->timer = v19312;
  int * v19307 = v19304->regs;
  int v19308 = v19307[23];
  int v19316 = (int)((unsigned int)v19308 >> 14);
  v19307[24] = v19316;
  struct StateT * v19310 = slot_533(v19304);
  return v19310;
}

struct StateT * slot_217(struct StateT * v13122) {
  int v13123 = v13122->timer;
  int v13233 = v13123 + 1;
  v13122->timer = v13233;
  int * v13125 = v13122->regs;
  int v13126 = v13125[2];
  int * v13127 = v13122->cache_tags;
  int v13237 = (((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2;
  int v13128 = v13127[v13237];
  int v13238 = ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13129 = v13127[v13238];
  int v13239 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2);
  int v13130 = v13127[v13239];
  int v13240 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13131 = v13127[v13240];
  int v13132 = v13122->timer;
  int v13241 = v13132 + ((100 ^ (((~(((v13130 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13130 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13128 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13128 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v13129 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13129 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13130 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13130 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13122->timer = v13241;
  int * v13134 = v13122->cache_vals;
  bool v13242 = !(((~(((v13128 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13128 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v13129 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13129 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v13227;
  if (v13242) {
    int * v13135 = v13122->cache_age;
    int v13244 = ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v13129 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13129 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v13136 = v13135[v13244];
    int v13137 = v13135[v13237];
    int v13245 = v13137 + ((int)((unsigned int)(v13137 - v13136) >> 31));
    v13135[v13237] = v13245;
    int * v13139 = v13122->cache_age;
    int v13140 = v13139[v13238];
    int v13247 = v13140 + ((int)((unsigned int)(v13140 - v13136) >> 31));
    v13139[v13238] = v13247;
    int * v13142 = v13122->cache_age;
    v13142[v13244] = 0;
    v13227 = v13244;
  } else {
    int * v13145 = v13122->cache_age;
    int v13251 = (((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2;
    int v13146 = v13145[v13251];
    int * v13147 = v13122->cache_tags;
    int v13148 = v13147[v13251];
    int v13149 = v13145[v13238];
    int v13150 = v13147[v13238];
    bool v13253 = !(((~(((v13130 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13130 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v13204;
    if (v13253) {
      int * v13151 = v13122->cache_age;
      int v13255 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))) | (-(v13131 ^ ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v13152 = v13151[v13255];
      int v13153 = v13151[v13239];
      int v13256 = v13153 + ((int)((unsigned int)(v13153 - v13152) >> 31));
      v13151[v13239] = v13256;
      int * v13155 = v13122->cache_age;
      int v13156 = v13155[v13240];
      int v13258 = v13156 + ((int)((unsigned int)(v13156 - v13152) >> 31));
      v13155[v13240] = v13258;
      int * v13158 = v13122->cache_age;
      v13158[v13255] = 0;
      v13204 = v13255;
    } else {
      int * v13161 = v13122->cache_age;
      int v13262 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2);
      int v13162 = v13161[v13262];
      int * v13163 = v13122->cache_tags;
      int v13164 = v13163[v13262];
      int v13165 = v13161[v13240];
      int v13166 = v13163[v13240];
      int * v13167 = v13122->cache_dirty;
      int v13265 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v13162 + ((~(((v13164 ^ -1) | (-(v13164 ^ -1))) >> 31)) & 2)) - (v13165 + ((~(((v13166 ^ -1) | (-(v13166 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13168 = v13167[v13265];
      bool v13266 = !(v13168 == 0);
      if (v13266) {
        int * v13169 = v13122->cache_tags;
        int v13170 = v13169[v13265];
        int * v13171 = v13122->cache_vals;
        int v13269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v13162 + ((~(((v13164 ^ -1) | (-(v13164 ^ -1))) >> 31)) & 2)) - (v13165 + ((~(((v13166 ^ -1) | (-(v13166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13172 = v13171[v13269];
        int v13270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v13162 + ((~(((v13164 ^ -1) | (-(v13164 ^ -1))) >> 31)) & 2)) - (v13165 + ((~(((v13166 ^ -1) | (-(v13166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13173 = v13171[v13270];
        int * v13174 = v13122->mem;
        int v13272 = v13170 * 2;
        v13174[v13272] = v13172;
        int * v13176 = v13122->mem;
        int v13275 = (v13170 * 2) + 1;
        v13176[v13275] = v13173;
        ;
      } else {
        ;
      }
      int * v13181 = v13122->mem;
      int v13280 = ((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) * 2;
      int v13182 = v13181[v13280];
      int v13281 = (((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) * 2) + 1;
      int v13183 = v13181[v13281];
      int * v13184 = v13122->cache_vals;
      int v13283 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v13162 + ((~(((v13164 ^ -1) | (-(v13164 ^ -1))) >> 31)) & 2)) - (v13165 + ((~(((v13166 ^ -1) | (-(v13166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13184[v13283] = v13182;
      int * v13186 = v13122->cache_vals;
      int v13286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v13162 + ((~(((v13164 ^ -1) | (-(v13164 ^ -1))) >> 31)) & 2)) - (v13165 + ((~(((v13166 ^ -1) | (-(v13166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13186[v13286] = v13183;
      int * v13188 = v13122->cache_tags;
      int v13289 = (int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1);
      v13188[v13265] = v13289;
      int * v13190 = v13122->cache_dirty;
      v13190[v13265] = 0;
      int * v13192 = v13122->cache_age;
      v13192[v13265] = 1;
      int * v13194 = v13122->cache_age;
      int v13195 = v13194[v13265];
      int v13196 = v13194[v13239];
      int v13295 = v13196 + ((int)((unsigned int)(v13196 - v13195) >> 31));
      v13194[v13239] = v13295;
      int * v13198 = v13122->cache_age;
      int v13199 = v13198[v13240];
      int v13297 = v13199 + ((int)((unsigned int)(v13199 - v13195) >> 31));
      v13198[v13240] = v13297;
      int * v13201 = v13122->cache_age;
      v13201[v13265] = 0;
      v13204 = v13265;
    }
    int * v13205 = v13122->cache_vals;
    int v13300 = v13204 * 2;
    int v13206 = v13205[v13300];
    int v13301 = (v13204 * 2) + 1;
    int v13207 = v13205[v13301];
    int v13302 = (((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v13146 + ((~(((v13148 ^ -1) | (-(v13148 ^ -1))) >> 31)) & 2)) - (v13149 + ((~(((v13150 ^ -1) | (-(v13150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13205[v13302] = v13206;
    int * v13209 = v13122->cache_vals;
    int v13305 = ((((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v13146 + ((~(((v13148 ^ -1) | (-(v13148 ^ -1))) >> 31)) & 2)) - (v13149 + ((~(((v13150 ^ -1) | (-(v13150 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13209[v13305] = v13207;
    int * v13211 = v13122->cache_tags;
    int v13308 = ((((int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v13146 + ((~(((v13148 ^ -1) | (-(v13148 ^ -1))) >> 31)) & 2)) - (v13149 + ((~(((v13150 ^ -1) | (-(v13150 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13309 = (int)((unsigned int)((int)((unsigned int)(v13126 + 24) >> 2)) >> 1);
    v13211[v13308] = v13309;
    int * v13213 = v13122->cache_dirty;
    v13213[v13308] = 0;
    int * v13215 = v13122->cache_age;
    v13215[v13308] = 1;
    int * v13217 = v13122->cache_age;
    int v13218 = v13217[v13308];
    int v13219 = v13217[v13237];
    int v13315 = v13219 + ((int)((unsigned int)(v13219 - v13218) >> 31));
    v13217[v13237] = v13315;
    int * v13221 = v13122->cache_age;
    int v13222 = v13221[v13238];
    int v13317 = v13222 + ((int)((unsigned int)(v13222 - v13218) >> 31));
    v13221[v13238] = v13317;
    int * v13224 = v13122->cache_age;
    v13224[v13308] = 0;
    v13227 = v13308;
  }
  int v13320 = (v13227 * 2) + (((int)((unsigned int)(v13126 + 24) >> 2)) & 1);
  int v13228 = v13134[v13320];
  int * v13229 = v13122->regs;
  v13229[21] = v13228;
  struct StateT * v13231 = slot_219(v13122);
  return v13231;
}

struct StateT * slot_111(struct StateT * v7461) {
  int * v7462 = v7461->saved_regs;
  int * v7463 = v7461->regs;
  int v7464 = v7463[28];
  v7462[28] = v7464;
  int v7466 = v7461->timer;
  int v7478 = v7466 + 1;
  v7461->timer = v7478;
  int * v7468 = v7461->regs;
  int v7469 = v7468[28];
  int v7470 = v7468[22];
  int v7481 = v7469 ^ v7470;
  v7468[28] = v7481;
  struct StateT * v7472 = slot_112(v7461);
  return v7472;
}

struct StateT * slot_349(struct StateT * v16311) {
  int v16312 = v16311->timer;
  int v16320 = v16312 + 1;
  v16311->timer = v16320;
  int * v16314 = v16311->regs;
  int v16315 = v16314[22];
  int v16316 = v16314[24];
  int v16324 = v16315 | v16316;
  v16314[22] = v16324;
  struct StateT * v16318 = slot_350(v16311);
  return v16318;
}

struct StateT * slot_291(struct StateT * v15406) {
  int v15407 = v15406->timer;
  int v15414 = v15407 + 1;
  v15406->timer = v15414;
  int * v15409 = v15406->regs;
  int v15410 = v15409[23];
  int v15417 = v15410 << 18;
  v15409[23] = v15417;
  struct StateT * v15412 = slot_292(v15406);
  return v15412;
}

struct StateT * slot_147(struct StateT * v8037) {
  int v8038 = v8037->timer;
  int v8045 = v8038 + 1;
  v8037->timer = v8045;
  int * v8040 = v8037->regs;
  int v8041 = v8040[23];
  int v8048 = v8041 << 9;
  v8040[23] = v8048;
  struct StateT * v8043 = slot_148(v8037);
  return v8043;
}

struct StateT * slot_410(struct StateT * v17318) {
  int v17319 = v17318->timer;
  int v17326 = v17319 + 1;
  v17318->timer = v17326;
  int * v17321 = v17318->regs;
  int v17322 = v17321[22];
  int v17329 = v17322 << 9;
  v17321[22] = v17329;
  struct StateT * v17324 = slot_411(v17318);
  return v17324;
}

struct StateT * slot_491(struct StateT * v18664) {
  int v18665 = v18664->timer;
  int v18673 = v18665 + 1;
  v18664->timer = v18673;
  int * v18667 = v18664->regs;
  int v18668 = v18667[22];
  int v18669 = v18667[24];
  int v18677 = v18668 | v18669;
  v18667[22] = v18677;
  struct StateT * v18671 = slot_492(v18664);
  return v18671;
}

struct StateT * slot_163(struct StateT * v8289) {
  int v8290 = v8289->timer;
  int v8297 = v8290 + 1;
  v8289->timer = v8297;
  int * v8292 = v8289->regs;
  int v8293 = v8292[22];
  int v8301 = (int)((unsigned int)v8293 >> 19);
  v8292[24] = v8301;
  struct StateT * v8295 = slot_164(v8289);
  return v8295;
}

struct StateT * slot_422(struct StateT * v17536) {
  int v17537 = v17536->timer;
  int v17545 = v17537 + 1;
  v17536->timer = v17545;
  int * v17539 = v17536->regs;
  int v17540 = v17539[5];
  int v17541 = v17539[8];
  int v17550 = v17540 + v17541;
  v17539[23] = v17550;
  struct StateT * v17543 = slot_423(v17536);
  return v17543;
}

struct StateT * slot_448(struct StateT * v17967) {
  int v17968 = v17967->timer;
  int v17976 = v17968 + 1;
  v17967->timer = v17976;
  int * v17970 = v17967->regs;
  int v17971 = v17970[21];
  int v17972 = v17970[24];
  int v17980 = v17971 | v17972;
  v17970[21] = v17980;
  struct StateT * v17974 = slot_449(v17967);
  return v17974;
}

struct StateT * slot_204(struct StateT * v10611) {
  int v10612 = v10611->timer;
  int v10620 = v10612 + 1;
  v10611->timer = v10620;
  int * v10614 = v10611->regs;
  int v10615 = v10614[28];
  int v10616 = v10614[12];
  int v10625 = v10615 + v10616;
  v10614[22] = v10625;
  struct StateT * v10618 = slot_206(v10611);
  return v10618;
}

struct StateT * slot_194(struct StateT * v8776) {
  int * v8777 = v8776->regs;
  int v8778 = v8777[11];
  bool v8877 = (v8778 ^ -2147483648) < -2147483648;
  struct StateT * v8873;
  if (v8877) {
    int v8779 = v8776->timer;
    int v8878 = v8779 + 15;
    v8776->timer = v8878;
    int * v8781 = v8776->saved_regs;
    int v8782 = v8781[20];
    int * v8783 = v8776->regs;
    v8783[20] = v8782;
    int * v8785 = v8776->saved_regs;
    int v8786 = v8785[21];
    int * v8787 = v8776->regs;
    v8787[21] = v8786;
    int * v8789 = v8776->saved_regs;
    int v8790 = v8789[22];
    int * v8791 = v8776->regs;
    v8791[22] = v8790;
    int * v8793 = v8776->saved_regs;
    int v8794 = v8793[23];
    int * v8795 = v8776->regs;
    v8795[23] = v8794;
    int * v8797 = v8776->saved_regs;
    int v8798 = v8797[24];
    int * v8799 = v8776->regs;
    v8799[24] = v8798;
    int * v8801 = v8776->saved_regs;
    int v8802 = v8801[9];
    int * v8803 = v8776->regs;
    v8803[9] = v8802;
    int * v8805 = v8776->saved_regs;
    int v8806 = v8805[18];
    int * v8807 = v8776->regs;
    v8807[18] = v8806;
    int * v8809 = v8776->saved_regs;
    int v8810 = v8809[19];
    int * v8811 = v8776->regs;
    v8811[19] = v8810;
    int * v8813 = v8776->saved_regs;
    int v8814 = v8813[8];
    int * v8815 = v8776->regs;
    v8815[8] = v8814;
    int * v8817 = v8776->saved_regs;
    int v8818 = v8817[6];
    int * v8819 = v8776->regs;
    v8819[6] = v8818;
    int * v8821 = v8776->saved_regs;
    int v8822 = v8821[7];
    int * v8823 = v8776->regs;
    v8823[7] = v8822;
    int * v8825 = v8776->saved_regs;
    int v8826 = v8825[17];
    int * v8827 = v8776->regs;
    v8827[17] = v8826;
    int * v8829 = v8776->saved_regs;
    int v8830 = v8829[5];
    int * v8831 = v8776->regs;
    v8831[5] = v8830;
    int * v8833 = v8776->saved_regs;
    int v8834 = v8833[16];
    int * v8835 = v8776->regs;
    v8835[16] = v8834;
    int * v8837 = v8776->saved_regs;
    int v8838 = v8837[14];
    int * v8839 = v8776->regs;
    v8839[14] = v8838;
    int * v8841 = v8776->saved_regs;
    int v8842 = v8841[12];
    int * v8843 = v8776->regs;
    v8843[12] = v8842;
    int * v8845 = v8776->saved_regs;
    int v8846 = v8845[15];
    int * v8847 = v8776->regs;
    v8847[15] = v8846;
    int * v8849 = v8776->saved_regs;
    int v8850 = v8849[30];
    int * v8851 = v8776->regs;
    v8851[30] = v8850;
    int * v8853 = v8776->saved_regs;
    int v8854 = v8853[29];
    int * v8855 = v8776->regs;
    v8855[29] = v8854;
    int * v8857 = v8776->saved_regs;
    int v8858 = v8857[28];
    int * v8859 = v8776->regs;
    v8859[28] = v8858;
    int * v8861 = v8776->saved_regs;
    int v8862 = v8861[31];
    int * v8863 = v8776->regs;
    v8863[31] = v8862;
    int * v8865 = v8776->saved_regs;
    int v8866 = v8865[13];
    int * v8867 = v8776->regs;
    v8867[13] = v8866;
    struct StateT * v8869 = slot_195(v8776);
    v8873 = v8869;
  } else {
    struct StateT * v8871 = slot_196(v8776);
    v8873 = v8871;
  }
  return v8873;
}

struct StateT * slot_407(struct StateT * v17273) {
  int v17274 = v17273->timer;
  int v17281 = v17274 + 1;
  v17273->timer = v17281;
  int * v17276 = v17273->regs;
  int v17277 = v17276[21];
  int v17284 = v17277 << 9;
  v17276[21] = v17284;
  struct StateT * v17279 = slot_408(v17273);
  return v17279;
}

struct StateT * slot_250(struct StateT * v14767) {
  int v14768 = v14767->timer;
  int v14775 = v14768 + 1;
  v14767->timer = v14775;
  int * v14770 = v14767->regs;
  int v14771 = v14770[23];
  int v14779 = (int)((unsigned int)v14771 >> 23);
  v14770[24] = v14779;
  struct StateT * v14773 = slot_251(v14767);
  return v14773;
}

struct StateT * slot_360(struct StateT * v16487) {
  int v16488 = v16487->timer;
  int v16496 = v16488 + 1;
  v16487->timer = v16496;
  int * v16490 = v16487->regs;
  int v16491 = v16490[19];
  int v16492 = v16490[7];
  int v16501 = v16491 + v16492;
  v16490[23] = v16501;
  struct StateT * v16494 = slot_361(v16487);
  return v16494;
}

struct StateT * slot_259(struct StateT * v14910) {
  int v14911 = v14910->timer;
  int v14919 = v14911 + 1;
  v14910->timer = v14919;
  int * v14913 = v14910->regs;
  int v14914 = v14913[17];
  int v14915 = v14913[19];
  int v14924 = v14914 + v14915;
  v14913[22] = v14924;
  struct StateT * v14917 = slot_260(v14910);
  return v14917;
}

struct StateT * slot_469(struct StateT * v18323) {
  int v18324 = v18323->timer;
  int v18331 = v18324 + 1;
  v18323->timer = v18331;
  int * v18326 = v18323->regs;
  int v18327 = v18326[22];
  int v18335 = (int)((unsigned int)v18327 >> 25);
  v18326[24] = v18335;
  struct StateT * v18329 = slot_470(v18323);
  return v18329;
}

struct StateT * slot_117(struct StateT * v7575) {
  int v7576 = v7575->timer;
  int v7583 = v7576 + 1;
  v7575->timer = v7583;
  int * v7578 = v7575->regs;
  int v7579 = v7578[20];
  int v7587 = (int)((unsigned int)v7579 >> 25);
  v7578[24] = v7587;
  struct StateT * v7581 = slot_118(v7575);
  return v7581;
}

struct StateT * slot_90(struct StateT * v7098) {
  int * v7099 = v7098->saved_regs;
  int * v7100 = v7098->regs;
  int v7101 = v7100[14];
  v7099[14] = v7101;
  int v7103 = v7098->timer;
  int v7115 = v7103 + 1;
  v7098->timer = v7115;
  int * v7105 = v7098->regs;
  int v7106 = v7105[14];
  int v7107 = v7105[21];
  int v7118 = v7106 ^ v7107;
  v7105[14] = v7118;
  struct StateT * v7109 = slot_91(v7098);
  return v7109;
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
  
  // a10, 8 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 32;
  s2.regs[11] = 32;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 48;
  s2.regs[12] = 48;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[8 + i] = secret(0, 20);
    s2.mem[8 + i] = secret(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[12 + i] = secret(0, 20);
    s2.mem[12 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}