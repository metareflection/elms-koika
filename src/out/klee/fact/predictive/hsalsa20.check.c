// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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

struct StateT * slot_143(struct StateT * v7309);
struct StateT * slot_120(struct StateT * v6952);
struct StateT * slot_226(struct StateT * v14332);
struct StateT * slot_167(struct StateT * v7681);
struct StateT * slot_509(struct StateT * v21467);
struct StateT * slot_152(struct StateT * v7447);
struct StateT * slot_429(struct StateT * v20135);
struct StateT * slot_231(struct StateT * v14975);
struct StateT * slot_355(struct StateT * v18924);
struct StateT * slot_92(struct StateT * v6476);
struct StateT * slot_232(struct StateT * v15179);
struct StateT * slot_466(struct StateT * v20770);
struct StateT * slot_304(struct StateT * v18133);
struct StateT * slot_31(struct StateT * v5423);
struct StateT * slot_236(struct StateT * v15805);
struct StateT * slot_241(struct StateT * v16448);
struct StateT * slot_160(struct StateT * v7576);
struct StateT * slot_519(struct StateT * v21621);
struct StateT * slot_150(struct StateT * v7415);
struct StateT * slot_391(struct StateT * v19486);
struct StateT * slot_74(struct StateT * v6176);
struct StateT * slot_262(struct StateT * v17479);
struct StateT * slot_351(struct StateT * v18862);
struct StateT * slot_372(struct StateT * v19188);
struct StateT * slot_403(struct StateT * v19698);
struct StateT * slot_107(struct StateT * v6717);
struct StateT * slot_555(struct StateT * v22181);
struct StateT * slot_541(struct StateT * v21967);
struct StateT * slot_325(struct StateT * v18460);
struct StateT * slot_84(struct StateT * v6332);
struct StateT * slot_28(struct StateT * v5381);
struct StateT * slot_155(struct StateT * v7497);
struct StateT * slot_177(struct StateT * v7843);
struct StateT * slot_517(struct StateT * v21589);
struct StateT * slot_229(struct StateT * v14756);
struct StateT * slot_358(struct StateT * v18973);
struct StateT * slot_465(struct StateT * v20754);
struct StateT * slot_181(struct StateT * v7903);
struct StateT * slot_542(struct StateT * v21984);
struct StateT * slot_154(struct StateT * v7480);
struct StateT * slot_260(struct StateT * v17447);
struct StateT * slot_481(struct StateT * v21031);
struct StateT * slot_305(struct StateT * v18148);
struct StateT * slot_27(struct StateT * v5366);
struct StateT * slot_454(struct StateT * v20549);
struct StateT * slot_34(struct StateT * v5468);
struct StateT * slot_482(struct StateT * v21048);
struct StateT * slot_21(struct StateT * v4904);
struct StateT * slot_406(struct StateT * v19750);
struct StateT * slot_292(struct StateT * v17940);
struct StateT * slot_118(struct StateT * v6922);
struct StateT * slot_525(struct StateT * v21718);
struct StateT * slot_515(struct StateT * v21557);
struct StateT * slot_376(struct StateT * v19252);
struct StateT * slot_373(struct StateT * v19204);
struct StateT * slot_94(struct StateT * v6516);
struct StateT * slot_340(struct StateT * v18695);
struct StateT * slot_146(struct StateT * v7354);
struct StateT * slot_383(struct StateT * v19365);
struct StateT * slot_24(struct StateT * v5325);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_489(struct StateT * v21155);
struct StateT * slot_286(struct StateT * v17850);
struct StateT * slot_520(struct StateT * v21638);
struct StateT * slot_125(struct StateT * v7026);
struct StateT * slot_254(struct StateT * v17375);
struct StateT * slot_148(struct StateT * v7383);
struct StateT * slot_421(struct StateT * v20011);
struct StateT * slot_126(struct StateT * v7042);
struct StateT * slot_363(struct StateT * v19053);
struct StateT * slot_79(struct StateT * v6256);
struct StateT * slot_367(struct StateT * v19114);
struct StateT * slot_437(struct StateT * v20271);
struct StateT * slot_341(struct StateT * v18712);
struct StateT * slot_142(struct StateT * v7293);
struct StateT * slot_416(struct StateT * v19908);
struct StateT * slot_280(struct StateT * v17759);
struct StateT * slot_272(struct StateT * v17628);
struct StateT * slot_47(struct StateT * v5697);
struct StateT * slot_214(struct StateT * v12197);
struct StateT * slot_297(struct StateT * v18020);
struct StateT * slot_29(struct StateT * v5396);
struct StateT * slot_314(struct StateT * v18284);
struct StateT * slot_151(struct StateT * v7431);
struct StateT * slot_7(struct StateT * v1906);
struct StateT * slot_124(struct StateT * v7012);
struct StateT * slot_128(struct StateT * v7071);
struct StateT * slot_365(struct StateT * v19084);
struct StateT * slot_441(struct StateT * v20351);
struct StateT * slot_19(struct StateT * v4496);
struct StateT * slot_382(struct StateT * v19351);
struct StateT * slot_523(struct StateT * v21689);
struct StateT * slot_87(struct StateT * v6377);
struct StateT * slot_452(struct StateT * v20520);
struct StateT * slot_67(struct StateT * v6037);
struct StateT * slot_81(struct StateT * v6287);
struct StateT * slot_546(struct StateT * v22046);
struct StateT * slot_556(struct StateT * v22197);
struct StateT * slot_337(struct StateT * v18644);
struct StateT * slot_32(struct StateT * v5436);
struct StateT * slot_233(struct StateT * v15383);
struct StateT * slot_176(struct StateT * v7826);
struct StateT * slot_189(struct StateT * v8023);
struct StateT * slot_394(struct StateT * v19532);
struct StateT * slot_398(struct StateT * v19594);
struct StateT * slot_33(struct StateT * v5444);
struct StateT * slot_371(struct StateT * v19174);
struct StateT * slot_330(struct StateT * v18535);
struct StateT * slot_450(struct StateT * v20490);
struct StateT * slot_35(struct StateT * v5492);
struct StateT * slot_484(struct StateT * v21080);
struct StateT * slot_258(struct StateT * v17413);
struct StateT * slot_166(struct StateT * v7666);
struct StateT * slot_418(struct StateT * v19954);
struct StateT * slot_51(struct StateT * v5773);
struct StateT * slot_25(struct StateT * v5338);
struct StateT * slot_490(struct StateT * v21170);
struct StateT * slot_264(struct StateT * v17509);
struct StateT * slot_339(struct StateT * v18678);
struct StateT * slot_123(struct StateT * v6997);
struct StateT * slot_97(struct StateT * v6567);
struct StateT * slot_106(struct StateT * v6702);
struct StateT * slot_299(struct StateT * v18054);
struct StateT * slot_539(struct StateT * v21933);
struct StateT * slot_319(struct StateT * v18366);
struct StateT * slot_344(struct StateT * v18757);
struct StateT * slot_513(struct StateT * v21527);
struct StateT * slot_130(struct StateT * v7103);
struct StateT * slot_497(struct StateT * v21277);
struct StateT * slot_455(struct StateT * v20565);
struct StateT * slot_141(struct StateT * v7279);
struct StateT * slot_432(struct StateT * v20180);
struct StateT * slot_306(struct StateT * v18162);
struct StateT * slot_312(struct StateT * v18252);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_560(struct StateT * v22266);
struct StateT * slot_548(struct StateT * v22075);
struct StateT * slot_70(struct StateT * v6090);
struct StateT * slot_168(struct StateT * v7695);
struct StateT * slot_348(struct StateT * v18817);
struct StateT * slot_456(struct StateT * v20588);
struct StateT * slot_225(struct StateT * v14128);
struct StateT * slot_467(struct StateT * v20785);
struct StateT * slot_285(struct StateT * v17836);
struct StateT * slot_213(struct StateT * v11882);
struct StateT * slot_82(struct StateT * v6301);
struct StateT * slot_263(struct StateT * v17493);
struct StateT * slot_161(struct StateT * v7591);
struct StateT * slot_293(struct StateT * v17956);
struct StateT * slot_185(struct StateT * v7962);
struct StateT * slot_288(struct StateT * v17881);
struct StateT * slot_89(struct StateT * v6407);
struct StateT * slot_384(struct StateT * v19381);
struct StateT * slot_486(struct StateT * v21110);
struct StateT * slot_347(struct StateT * v18802);
struct StateT * slot_140(struct StateT * v7264);
struct StateT * slot_473(struct StateT * v20875);
struct StateT * slot_49(struct StateT * v5727);
struct StateT * slot_216(struct StateT * v12526);
struct StateT * slot_468(struct StateT * v20799);
struct StateT * slot_50(struct StateT * v5750);
struct StateT * slot_135(struct StateT * v7185);
struct StateT * slot_248(struct StateT * v17109);
struct StateT * slot_59(struct StateT * v5916);
struct StateT * slot_485(struct StateT * v21094);
struct StateT * slot_40(struct StateT * v5592);
struct StateT * slot_77(struct StateT * v6227);
struct StateT * slot_85(struct StateT * v6346);
struct StateT * slot_350(struct StateT * v18847);
struct StateT * slot_392(struct StateT * v19500);
struct StateT * slot_75(struct StateT * v6193);
struct StateT * slot_71(struct StateT * v6113);
struct StateT * slot_378(struct StateT * v19285);
struct StateT * slot_108(struct StateT * v6731);
struct StateT * slot_116(struct StateT * v6890);
struct StateT * slot_417(struct StateT * v19931);
struct StateT * slot_405(struct StateT * v19734);
struct StateT * slot_215(struct StateT * v12512);
struct StateT * slot_45(struct StateT * v5666);
struct StateT * slot_220(struct StateT * v13376);
struct StateT * slot_134(struct StateT * v7168);
struct StateT * slot_463(struct StateT * v20725);
struct StateT * slot_175(struct StateT * v7809);
struct StateT * slot_387(struct StateT * v19426);
struct StateT * slot_273(struct StateT * v17644);
struct StateT * slot_69(struct StateT * v6067);
struct StateT * slot_188(struct StateT * v8007);
struct StateT * slot_495(struct StateT * v21245);
struct StateT * slot_186(struct StateT * v7978);
struct StateT * slot_102(struct StateT * v6641);
struct StateT * slot_145(struct StateT * v7338);
struct StateT * slot_110(struct StateT * v6770);
struct StateT * slot_301(struct StateT * v18088);
struct StateT * slot_502(struct StateT * v21360);
struct StateT * slot_506(struct StateT * v21422);
struct StateT * slot_413(struct StateT * v19855);
struct StateT * slot_320(struct StateT * v18383);
struct StateT * slot_281(struct StateT * v17776);
struct StateT * slot_533(struct StateT * v21839);
struct StateT * slot_203(struct StateT * v9926);
struct StateT * slot_190(struct StateT * v8039);
struct StateT * slot_157(struct StateT * v7531);
struct StateT * slot_447(struct StateT * v20445);
struct StateT * slot_559(struct StateT * v22245);
struct StateT * slot_243(struct StateT * v16666);
struct StateT * slot_173(struct StateT * v7775);
struct StateT * slot_307(struct StateT * v18178);
struct StateT * slot_453(struct StateT * v20535);
struct StateT * slot_54(struct StateT * v5836);
struct StateT * slot_26(struct StateT * v5351);
struct StateT * slot_370(struct StateT * v19159);
struct StateT * slot_206(struct StateT * v10573);
struct StateT * slot_227(struct StateT * v14536);
struct StateT * slot_169(struct StateT * v7711);
struct StateT * slot_442(struct StateT * v20368);
struct StateT * slot_529(struct StateT * v21779);
struct StateT * slot_14(struct StateT * v3476);
struct StateT * slot_357(struct StateT * v18956);
struct StateT * slot_385(struct StateT * v19396);
struct StateT * slot_444(struct StateT * v20400);
struct StateT * slot_261(struct StateT * v17464);
struct StateT * slot_287(struct StateT * v17866);
struct StateT * slot_343(struct StateT * v18741);
struct StateT * slot_36(struct StateT * v5516);
struct StateT * slot_57(struct StateT * v5887);
struct StateT * slot_426(struct StateT * v20090);
struct StateT * slot_536(struct StateT * v21885);
struct StateT * slot_470(struct StateT * v20830);
struct StateT * slot_431(struct StateT * v20164);
struct StateT * slot_62(struct StateT * v5961);
struct StateT * slot_308(struct StateT * v18193);
struct StateT * slot_400(struct StateT * v19626);
struct StateT * slot_323(struct StateT * v18429);
struct StateT * slot_521(struct StateT * v21655);
struct StateT * slot_530(struct StateT * v21794);
struct StateT * slot_23(struct StateT * v5312);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v6362);
struct StateT * slot_538(struct StateT * v21917);
struct StateT * slot_100(struct StateT * v6612);
struct StateT * slot_127(struct StateT * v7057);
struct StateT * slot_411(struct StateT * v19824);
struct StateT * slot_13(struct StateT * v3272);
struct StateT * slot_449(struct StateT * v20475);
struct StateT * slot_460(struct StateT * v20674);
struct StateT * slot_109(struct StateT * v6747);
struct StateT * slot_474(struct StateT * v20889);
struct StateT * slot_174(struct StateT * v7792);
struct StateT * slot_42(struct StateT * v5621);
struct StateT * slot_224(struct StateT * v14114);
struct StateT * slot_184(struct StateT * v7948);
struct StateT * slot_462(struct StateT * v20708);
struct StateT * slot_165(struct StateT * v7650);
struct StateT * slot_557(struct StateT * v22213);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_393(struct StateT * v19516);
struct StateT * slot_507(struct StateT * v21437);
struct StateT * slot_477(struct StateT * v20951);
struct StateT * slot_278(struct StateT * v17725);
struct StateT * slot_352(struct StateT * v18876);
struct StateT * slot_11(struct StateT * v2864);
struct StateT * slot_12(struct StateT * v3068);
struct StateT * slot_268(struct StateT * v17569);
struct StateT * slot_199(struct StateT * v8964);
struct StateT * slot_252(struct StateT * v17345);
struct StateT * slot_409(struct StateT * v19795);
struct StateT * slot_374(struct StateT * v19220);
struct StateT * slot_269(struct StateT * v17583);
struct StateT * slot_501(struct StateT * v21343);
struct StateT * slot_251(struct StateT * v17329);
struct StateT * slot_65(struct StateT * v6006);
struct StateT * slot_10(struct StateT * v2851);
struct StateT * slot_322(struct StateT * v18415);
struct StateT * slot_277(struct StateT * v17708);
struct StateT * slot_353(struct StateT * v18892);
struct StateT * slot_397(struct StateT * v19580);
struct StateT * slot_435(struct StateT * v20225);
struct StateT * slot_476(struct StateT * v20928);
struct StateT * slot_136(struct StateT * v7202);
struct StateT * slot_379(struct StateT * v19302);
struct StateT * slot_475(struct StateT * v20905);
struct StateT * slot_310(struct StateT * v18223);
struct StateT * slot_445(struct StateT * v20414);
struct StateT * slot_295(struct StateT * v17988);
struct StateT * slot_315(struct StateT * v18300);
struct StateT * slot_545(struct StateT * v22030);
struct StateT * slot_17(struct StateT * v4088);
struct StateT * slot_197(struct StateT * v8627);
struct StateT * slot_457(struct StateT * v20611);
struct StateT * slot_156(struct StateT * v7514);
struct StateT * slot_68(struct StateT * v6051);
struct StateT * slot_493(struct StateT * v21215);
struct StateT * slot_105(struct StateT * v6686);
struct StateT * slot_430(struct StateT * v20150);
struct StateT * slot_369(struct StateT * v19143);
struct StateT * slot_461(struct StateT * v20691);
struct StateT * slot_164(struct StateT * v7636);
struct StateT * slot_15(struct StateT * v3680);
struct StateT * slot_480(struct StateT * v21014);
struct StateT * slot_133(struct StateT * v7151);
struct StateT * slot_56(struct StateT * v5870);
struct StateT * slot_171(struct StateT * v7743);
struct StateT * slot_162(struct StateT * v7605);
struct StateT * slot_377(struct StateT * v19268);
struct StateT * slot_552(struct StateT * v22136);
struct StateT * slot_427(struct StateT * v20105);
struct StateT * slot_399(struct StateT * v19602);
struct StateT * slot_239(struct StateT * v16229);
struct StateT * slot_464(struct StateT * v20740);
struct StateT * slot_500(struct StateT * v21326);
struct StateT * slot_433(struct StateT * v20195);
struct StateT * slot_121(struct StateT * v6967);
struct StateT * slot_144(struct StateT * v7324);
struct StateT * slot_267(struct StateT * v17554);
struct StateT * slot_492(struct StateT * v21200);
struct StateT * slot_201(struct StateT * v9296);
struct StateT * slot_63(struct StateT * v5977);
struct StateT * slot_326(struct StateT * v18474);
struct StateT * slot_303(struct StateT * v18117);
struct StateT * slot_511(struct StateT * v21496);
struct StateT * slot_335(struct StateT * v18612);
struct StateT * slot_316(struct StateT * v18316);
struct StateT * slot_424(struct StateT * v20060);
struct StateT * slot_332(struct StateT * v18564);
struct StateT * slot_41(struct StateT * v5607);
struct StateT * slot_39(struct StateT * v5576);
struct StateT * slot_508(struct StateT * v21451);
struct StateT * slot_537(struct StateT * v21901);
struct StateT * slot_60(struct StateT * v5932);
struct StateT * slot_289(struct StateT * v17895);
struct StateT * slot_238(struct StateT * v16025);
struct StateT * slot_112(struct StateT * v6816);
struct StateT * slot_544(struct StateT * v22016);
struct StateT * slot_16(struct StateT * v3884);
struct StateT * slot_245(struct StateT * v16884);
struct StateT * slot_113(struct StateT * v6839);
struct StateT * slot_302(struct StateT * v18103);
struct StateT * slot_388(struct StateT * v19441);
struct StateT * slot_191(struct StateT * v8055);
struct StateT * slot_103(struct StateT * v6657);
struct StateT * slot_487(struct StateT * v21125);
struct StateT * slot_324(struct StateT * v18445);
struct StateT * slot_440(struct StateT * v20334);
struct StateT * slot_547(struct StateT * v22061);
struct StateT * slot_518(struct StateT * v21605);
struct StateT * slot_95(struct StateT * v6533);
struct StateT * slot_451(struct StateT * v20504);
struct StateT * slot_458(struct StateT * v20634);
struct StateT * slot_415(struct StateT * v19885);
struct StateT * slot_354(struct StateT * v18908);
struct StateT * slot_531(struct StateT * v21808);
struct StateT * slot_115(struct StateT * v6873);
struct StateT * slot_78(struct StateT * v6242);
struct StateT * slot_321(struct StateT * v18400);
struct StateT * slot_317(struct StateT * v18332);
struct StateT * slot_558(struct StateT * v22229);
struct StateT * slot_193(struct StateT * v8087);
struct StateT * slot_554(struct StateT * v22165);
struct StateT * slot_375(struct StateT * v19236);
struct StateT * slot_331(struct StateT * v18550);
struct StateT * slot_380(struct StateT * v19319);
struct StateT * slot_412(struct StateT * v19840);
struct StateT * slot_381(struct StateT * v19336);
struct StateT * slot_478(struct StateT * v20974);
struct StateT * slot_210(struct StateT * v11237);
struct StateT * slot_472(struct StateT * v20860);
struct StateT * slot_284(struct StateT * v17821);
struct StateT * slot_52(struct StateT * v5796);
struct StateT * slot_83(struct StateT * v6317);
struct StateT * slot_209(struct StateT * v11220);
struct StateT * slot_420(struct StateT * v19994);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_73(struct StateT * v6159);
struct StateT * slot_270(struct StateT * v17599);
struct StateT * slot_198(struct StateT * v8942);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v7993);
struct StateT * slot_446(struct StateT * v20430);
struct StateT * slot_182(struct StateT * v7917);
struct StateT * slot_361(struct StateT * v19024);
struct StateT * slot_38(struct StateT * v5562);
struct StateT * slot_178(struct StateT * v7858);
struct StateT * slot_98(struct StateT * v6582);
struct StateT * slot_159(struct StateT * v7560);
struct StateT * slot_510(struct StateT * v21482);
struct StateT * slot_459(struct StateT * v20657);
struct StateT * slot_404(struct StateT * v19720);
struct StateT * slot_46(struct StateT * v5682);
struct StateT * slot_212(struct StateT * v11867);
struct StateT * slot_132(struct StateT * v7135);
struct StateT * slot_313(struct StateT * v18268);
struct StateT * slot_553(struct StateT * v22151);
struct StateT * slot_211(struct StateT * v11552);
struct StateT * slot_20(struct StateT * v4700);
struct StateT * slot_436(struct StateT * v20248);
struct StateT * slot_61(struct StateT * v5947);
struct StateT * slot_499(struct StateT * v21309);
struct StateT * slot_359(struct StateT * v18990);
struct StateT * slot_514(struct StateT * v21541);
struct StateT * slot_296(struct StateT * v18004);
struct StateT * slot_30(struct StateT * v5409);
struct StateT * slot_18(struct StateT * v4292);
struct StateT * slot_9(struct StateT * v2536);
struct StateT * slot_300(struct StateT * v18071);
struct StateT * slot_183(struct StateT * v7933);
struct StateT * slot_282(struct StateT * v17791);
struct StateT * slot_309(struct StateT * v18207);
struct StateT * slot_362(struct StateT * v19039);
struct StateT * slot_43(struct StateT * v5637);
struct StateT * slot_76(struct StateT * v6210);
struct StateT * slot_6(struct StateT * v1591);
struct StateT * slot_55(struct StateT * v5853);
struct StateT * slot_283(struct StateT * v17805);
struct StateT * slot_346(struct StateT * v18786);
struct StateT * slot_516(struct StateT * v21573);
struct StateT * slot_274(struct StateT * v17660);
struct StateT * slot_535(struct StateT * v21869);
struct StateT * slot_318(struct StateT * v18349);
struct StateT * slot_91(struct StateT * v6453);
struct StateT * slot_58(struct StateT * v5902);
struct StateT * slot_255(struct StateT * v17380);
struct StateT * slot_540(struct StateT * v21950);
struct StateT * slot_66(struct StateT * v6022);
struct StateT * slot_550(struct StateT * v22106);
struct StateT * slot_368(struct StateT * v19129);
struct StateT * slot_265(struct StateT * v17524);
struct StateT * slot_37(struct StateT * v5540);
struct StateT * slot_114(struct StateT * v6856);
struct StateT * slot_257(struct StateT * v17396);
struct StateT * slot_192(struct StateT * v8071);
struct StateT * slot_327(struct StateT * v18490);
struct StateT * slot_48(struct StateT * v5711);
struct StateT * slot_396(struct StateT * v19564);
struct StateT * slot_528(struct StateT * v21763);
struct StateT * slot_72(struct StateT * v6136);
struct StateT * slot_526(struct StateT * v21734);
struct StateT * slot_119(struct StateT * v6936);
struct StateT * slot_101(struct StateT * v6627);
struct StateT * slot_276(struct StateT * v17692);
struct StateT * slot_290(struct StateT * v17911);
struct StateT * slot_93(struct StateT * v6499);
struct StateT * slot_266(struct StateT * v17538);
struct StateT * slot_88(struct StateT * v6391);
struct StateT * slot_96(struct StateT * v6550);
struct StateT * slot_471(struct StateT * v20844);
struct StateT * slot_419(struct StateT * v19977);
struct StateT * slot_218(struct StateT * v13045);
struct StateT * slot_336(struct StateT * v18628);
struct StateT * slot_230(struct StateT * v14960);
struct StateT * slot_294(struct StateT * v17972);
struct StateT * slot_408(struct StateT * v19779);
struct StateT * slot_342(struct StateT * v18727);
struct StateT * slot_488(struct StateT * v21139);
struct StateT * slot_439(struct StateT * v20317);
struct StateT * slot_389(struct StateT * v19455);
struct StateT * slot_479(struct StateT * v20997);
struct StateT * slot_138(struct StateT * v7234);
struct StateT * slot_483(struct StateT * v21065);
struct StateT * slot_196(struct StateT * v8619);
struct StateT * slot_172(struct StateT * v7759);
struct StateT * slot_425(struct StateT * v20074);
struct StateT * slot_443(struct StateT * v20385);
struct StateT * slot_131(struct StateT * v7119);
struct StateT * slot_8(struct StateT * v2221);
struct StateT * slot_534(struct StateT * v21853);
struct StateT * slot_180(struct StateT * v7888);
struct StateT * slot_504(struct StateT * v21392);
struct StateT * slot_512(struct StateT * v21512);
struct StateT * slot_496(struct StateT * v21261);
struct StateT * slot_494(struct StateT * v21229);
struct StateT * slot_242(struct StateT * v16652);
struct StateT * slot_328(struct StateT * v18505);
struct StateT * slot_402(struct StateT * v19674);
struct StateT * slot_200(struct StateT * v9279);
struct StateT * slot_149(struct StateT * v7399);
struct StateT * slot_527(struct StateT * v21749);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_334(struct StateT * v18596);
struct StateT * slot_104(struct StateT * v6672);
struct StateT * slot_275(struct StateT * v17676);
struct StateT * slot_329(struct StateT * v18519);
struct StateT * slot_428(struct StateT * v20119);
struct StateT * slot_395(struct StateT * v19548);
struct StateT * slot_345(struct StateT * v18772);
struct StateT * slot_298(struct StateT * v18037);
struct StateT * slot_414(struct StateT * v19869);
struct StateT * slot_364(struct StateT * v19069);
struct StateT * slot_356(struct StateT * v18940);
struct StateT * slot_253(struct StateT * v17359);
struct StateT * slot_434(struct StateT * v20209);
struct StateT * slot_64(struct StateT * v5992);
struct StateT * slot_170(struct StateT * v7727);
struct StateT * slot_53(struct StateT * v5819);
struct StateT * slot_522(struct StateT * v21672);
struct StateT * slot_80(struct StateT * v6272);
struct StateT * slot_503(struct StateT * v21377);
struct StateT * slot_390(struct StateT * v19471);
struct StateT * slot_44(struct StateT * v5652);
struct StateT * slot_137(struct StateT * v7219);
struct StateT * slot_386(struct StateT * v19410);
struct StateT * slot_122(struct StateT * v6981);
struct StateT * slot_99(struct StateT * v6596);
struct StateT * slot_179(struct StateT * v7872);
struct StateT * slot_338(struct StateT * v18661);
struct StateT * slot_22(struct StateT * v5108);
struct StateT * slot_366(struct StateT * v19098);
struct StateT * slot_139(struct StateT * v7248);
struct StateT * slot_438(struct StateT * v20294);
struct StateT * slot_333(struct StateT * v18580);
struct StateT * slot_221(struct StateT * v13580);
struct StateT * slot_153(struct StateT * v7463);
struct StateT * slot_129(struct StateT * v7087);
struct StateT * slot_158(struct StateT * v7546);
struct StateT * slot_311(struct StateT * v18238);
struct StateT * slot_498(struct StateT * v21293);
struct StateT * slot_279(struct StateT * v17742);
struct StateT * slot_271(struct StateT * v17614);
struct StateT * slot_524(struct StateT * v21704);
struct StateT * slot_505(struct StateT * v21406);
struct StateT * slot_401(struct StateT * v19650);
struct StateT * slot_423(struct StateT * v20045);
struct StateT * slot_532(struct StateT * v21824);
struct StateT * slot_111(struct StateT * v6793);
struct StateT * slot_549(struct StateT * v22091);
struct StateT * slot_349(struct StateT * v18831);
struct StateT * slot_291(struct StateT * v17926);
struct StateT * slot_147(struct StateT * v7369);
struct StateT * slot_410(struct StateT * v19810);
struct StateT * slot_491(struct StateT * v21184);
struct StateT * slot_163(struct StateT * v7621);
struct StateT * slot_422(struct StateT * v20028);
struct StateT * slot_448(struct StateT * v20459);
struct StateT * slot_194(struct StateT * v8108);
struct StateT * slot_551(struct StateT * v22120);
struct StateT * slot_407(struct StateT * v19765);
struct StateT * slot_543(struct StateT * v22001);
struct StateT * slot_360(struct StateT * v19007);
struct StateT * slot_259(struct StateT * v17430);
struct StateT * slot_469(struct StateT * v20815);
struct StateT * slot_117(struct StateT * v6907);
struct StateT * slot_90(struct StateT * v6430);
struct StateT * slot_143(struct StateT * v7309) {
  int v7310 = v7309->timer;
  int v7317 = v7310 + 1;
  v7309->timer = v7317;
  int * v7312 = v7309->regs;
  int v7313 = v7312[22];
  int v7321 = (int)((unsigned int)v7313 >> 23);
  v7312[24] = v7321;
  struct StateT * v7315 = slot_144(v7309);
  return v7315;
}

struct StateT * slot_120(struct StateT * v6952) {
  int v6953 = v6952->timer;
  int v6960 = v6953 + 1;
  v6952->timer = v6960;
  int * v6955 = v6952->regs;
  int v6956 = v6955[21];
  int v6964 = (int)((unsigned int)v6956 >> 25);
  v6955[24] = v6964;
  struct StateT * v6958 = slot_121(v6952);
  return v6958;
}

struct StateT * slot_226(struct StateT * v14332) {
  int v14333 = v14332->timer;
  int v14443 = v14333 + 1;
  v14332->timer = v14443;
  int * v14335 = v14332->regs;
  int v14336 = v14335[2];
  int * v14337 = v14332->cache_tags;
  int v14447 = (((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2;
  int v14338 = v14337[v14447];
  int v14448 = ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14339 = v14337[v14448];
  int v14449 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2);
  int v14340 = v14337[v14449];
  int v14450 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14341 = v14337[v14450];
  int v14342 = v14332->timer;
  int v14451 = v14342 + ((100 ^ (((~(((v14340 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14340 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14338 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14338 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14339 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14339 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14340 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14340 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14332->timer = v14451;
  int * v14344 = v14332->cache_vals;
  bool v14452 = !(((~(((v14338 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14338 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14339 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14339 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v14437;
  if (v14452) {
    int * v14345 = v14332->cache_age;
    int v14454 = ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v14339 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14339 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v14346 = v14345[v14454];
    int v14347 = v14345[v14447];
    int v14455 = v14347 + ((int)((unsigned int)(v14347 - v14346) >> 31));
    v14345[v14447] = v14455;
    int * v14349 = v14332->cache_age;
    int v14350 = v14349[v14448];
    int v14457 = v14350 + ((int)((unsigned int)(v14350 - v14346) >> 31));
    v14349[v14448] = v14457;
    int * v14352 = v14332->cache_age;
    v14352[v14454] = 0;
    v14437 = v14454;
  } else {
    int * v14355 = v14332->cache_age;
    int v14461 = (((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2;
    int v14356 = v14355[v14461];
    int * v14357 = v14332->cache_tags;
    int v14358 = v14357[v14461];
    int v14359 = v14355[v14448];
    int v14360 = v14357[v14448];
    bool v14463 = !(((~(((v14340 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14340 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v14414;
    if (v14463) {
      int * v14361 = v14332->cache_age;
      int v14465 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))) | (-(v14341 ^ ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v14362 = v14361[v14465];
      int v14363 = v14361[v14449];
      int v14466 = v14363 + ((int)((unsigned int)(v14363 - v14362) >> 31));
      v14361[v14449] = v14466;
      int * v14365 = v14332->cache_age;
      int v14366 = v14365[v14450];
      int v14468 = v14366 + ((int)((unsigned int)(v14366 - v14362) >> 31));
      v14365[v14450] = v14468;
      int * v14368 = v14332->cache_age;
      v14368[v14465] = 0;
      v14414 = v14465;
    } else {
      int * v14371 = v14332->cache_age;
      int v14472 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2);
      int v14372 = v14371[v14472];
      int * v14373 = v14332->cache_tags;
      int v14374 = v14373[v14472];
      int v14375 = v14371[v14450];
      int v14376 = v14373[v14450];
      int * v14377 = v14332->cache_dirty;
      int v14475 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v14372 + ((~(((v14374 ^ -1) | (-(v14374 ^ -1))) >> 31)) & 2)) - (v14375 + ((~(((v14376 ^ -1) | (-(v14376 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14378 = v14377[v14475];
      bool v14476 = !(v14378 == 0);
      if (v14476) {
        int * v14379 = v14332->cache_tags;
        int v14380 = v14379[v14475];
        int * v14381 = v14332->cache_vals;
        int v14479 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v14372 + ((~(((v14374 ^ -1) | (-(v14374 ^ -1))) >> 31)) & 2)) - (v14375 + ((~(((v14376 ^ -1) | (-(v14376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14382 = v14381[v14479];
        int v14480 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v14372 + ((~(((v14374 ^ -1) | (-(v14374 ^ -1))) >> 31)) & 2)) - (v14375 + ((~(((v14376 ^ -1) | (-(v14376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14383 = v14381[v14480];
        int * v14384 = v14332->mem;
        int v14482 = v14380 * 2;
        v14384[v14482] = v14382;
        int * v14386 = v14332->mem;
        int v14485 = (v14380 * 2) + 1;
        v14386[v14485] = v14383;
        ;
      } else {
        ;
      }
      int * v14391 = v14332->mem;
      int v14490 = ((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) * 2;
      int v14392 = v14391[v14490];
      int v14491 = (((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) * 2) + 1;
      int v14393 = v14391[v14491];
      int * v14394 = v14332->cache_vals;
      int v14493 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v14372 + ((~(((v14374 ^ -1) | (-(v14374 ^ -1))) >> 31)) & 2)) - (v14375 + ((~(((v14376 ^ -1) | (-(v14376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14394[v14493] = v14392;
      int * v14396 = v14332->cache_vals;
      int v14496 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v14372 + ((~(((v14374 ^ -1) | (-(v14374 ^ -1))) >> 31)) & 2)) - (v14375 + ((~(((v14376 ^ -1) | (-(v14376 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14396[v14496] = v14393;
      int * v14398 = v14332->cache_tags;
      int v14499 = (int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1);
      v14398[v14475] = v14499;
      int * v14400 = v14332->cache_dirty;
      v14400[v14475] = 0;
      int * v14402 = v14332->cache_age;
      v14402[v14475] = 1;
      int * v14404 = v14332->cache_age;
      int v14405 = v14404[v14475];
      int v14406 = v14404[v14449];
      int v14505 = v14406 + ((int)((unsigned int)(v14406 - v14405) >> 31));
      v14404[v14449] = v14505;
      int * v14408 = v14332->cache_age;
      int v14409 = v14408[v14450];
      int v14507 = v14409 + ((int)((unsigned int)(v14409 - v14405) >> 31));
      v14408[v14450] = v14507;
      int * v14411 = v14332->cache_age;
      v14411[v14475] = 0;
      v14414 = v14475;
    }
    int * v14415 = v14332->cache_vals;
    int v14510 = v14414 * 2;
    int v14416 = v14415[v14510];
    int v14511 = (v14414 * 2) + 1;
    int v14417 = v14415[v14511];
    int v14512 = (((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14415[v14512] = v14416;
    int * v14419 = v14332->cache_vals;
    int v14515 = ((((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14419[v14515] = v14417;
    int * v14421 = v14332->cache_tags;
    int v14518 = ((((int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v14356 + ((~(((v14358 ^ -1) | (-(v14358 ^ -1))) >> 31)) & 2)) - (v14359 + ((~(((v14360 ^ -1) | (-(v14360 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14519 = (int)((unsigned int)((int)((unsigned int)(v14336 + 32) >> 2)) >> 1);
    v14421[v14518] = v14519;
    int * v14423 = v14332->cache_dirty;
    v14423[v14518] = 0;
    int * v14425 = v14332->cache_age;
    v14425[v14518] = 1;
    int * v14427 = v14332->cache_age;
    int v14428 = v14427[v14518];
    int v14429 = v14427[v14447];
    int v14525 = v14429 + ((int)((unsigned int)(v14429 - v14428) >> 31));
    v14427[v14447] = v14525;
    int * v14431 = v14332->cache_age;
    int v14432 = v14431[v14448];
    int v14527 = v14432 + ((int)((unsigned int)(v14432 - v14428) >> 31));
    v14431[v14448] = v14527;
    int * v14434 = v14332->cache_age;
    v14434[v14518] = 0;
    v14437 = v14518;
  }
  int v14530 = (v14437 * 2) + (((int)((unsigned int)(v14336 + 32) >> 2)) & 1);
  int v14438 = v14344[v14530];
  int * v14439 = v14332->regs;
  v14439[19] = v14438;
  struct StateT * v14441 = slot_229(v14332);
  return v14441;
}

struct StateT * slot_167(struct StateT * v7681) {
  int v7682 = v7681->timer;
  int v7689 = v7682 + 1;
  v7681->timer = v7689;
  int * v7684 = v7681->regs;
  int v7685 = v7684[23];
  int v7692 = v7685 << 13;
  v7684[23] = v7692;
  struct StateT * v7687 = slot_168(v7681);
  return v7687;
}

struct StateT * slot_509(struct StateT * v21467) {
  int v21468 = v21467->timer;
  int v21475 = v21468 + 1;
  v21467->timer = v21475;
  int * v21470 = v21467->regs;
  int v21471 = v21470[22];
  int v21479 = (int)((unsigned int)v21471 >> 23);
  v21470[24] = v21479;
  struct StateT * v21473 = slot_510(v21467);
  return v21473;
}

struct StateT * slot_152(struct StateT * v7447) {
  int v7448 = v7447->timer;
  int v7456 = v7448 + 1;
  v7447->timer = v7456;
  int * v7450 = v7447->regs;
  int v7451 = v7450[7];
  int v7452 = v7450[23];
  int v7460 = v7451 ^ v7452;
  v7450[7] = v7460;
  struct StateT * v7454 = slot_153(v7447);
  return v7454;
}

struct StateT * slot_429(struct StateT * v20135) {
  int v20136 = v20135->timer;
  int v20143 = v20136 + 1;
  v20135->timer = v20143;
  int * v20138 = v20135->regs;
  int v20139 = v20138[22];
  int v20147 = (int)((unsigned int)v20139 >> 23);
  v20138[24] = v20147;
  struct StateT * v20141 = slot_430(v20135);
  return v20141;
}

struct StateT * slot_231(struct StateT * v14975) {
  int v14976 = v14975->timer;
  int v15086 = v14976 + 1;
  v14975->timer = v15086;
  int * v14978 = v14975->regs;
  int v14979 = v14978[2];
  int * v14980 = v14975->cache_tags;
  int v15090 = (((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2;
  int v14981 = v14980[v15090];
  int v15091 = ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14982 = v14980[v15091];
  int v15092 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2);
  int v14983 = v14980[v15092];
  int v15093 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14984 = v14980[v15093];
  int v14985 = v14975->timer;
  int v15094 = v14985 + ((100 ^ (((~(((v14983 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14983 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14981 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14981 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v14982 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14982 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14983 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14983 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14975->timer = v15094;
  int * v14987 = v14975->cache_vals;
  bool v15095 = !(((~(((v14981 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14981 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v14982 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14982 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v15080;
  if (v15095) {
    int * v14988 = v14975->cache_age;
    int v15097 = ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v14982 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14982 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v14989 = v14988[v15097];
    int v14990 = v14988[v15090];
    int v15098 = v14990 + ((int)((unsigned int)(v14990 - v14989) >> 31));
    v14988[v15090] = v15098;
    int * v14992 = v14975->cache_age;
    int v14993 = v14992[v15091];
    int v15100 = v14993 + ((int)((unsigned int)(v14993 - v14989) >> 31));
    v14992[v15091] = v15100;
    int * v14995 = v14975->cache_age;
    v14995[v15097] = 0;
    v15080 = v15097;
  } else {
    int * v14998 = v14975->cache_age;
    int v15104 = (((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2;
    int v14999 = v14998[v15104];
    int * v15000 = v14975->cache_tags;
    int v15001 = v15000[v15104];
    int v15002 = v14998[v15091];
    int v15003 = v15000[v15091];
    bool v15106 = !(((~(((v14983 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14983 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v15057;
    if (v15106) {
      int * v15004 = v14975->cache_age;
      int v15108 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))) | (-(v14984 ^ ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v15005 = v15004[v15108];
      int v15006 = v15004[v15092];
      int v15109 = v15006 + ((int)((unsigned int)(v15006 - v15005) >> 31));
      v15004[v15092] = v15109;
      int * v15008 = v14975->cache_age;
      int v15009 = v15008[v15093];
      int v15111 = v15009 + ((int)((unsigned int)(v15009 - v15005) >> 31));
      v15008[v15093] = v15111;
      int * v15011 = v14975->cache_age;
      v15011[v15108] = 0;
      v15057 = v15108;
    } else {
      int * v15014 = v14975->cache_age;
      int v15115 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2);
      int v15015 = v15014[v15115];
      int * v15016 = v14975->cache_tags;
      int v15017 = v15016[v15115];
      int v15018 = v15014[v15093];
      int v15019 = v15016[v15093];
      int * v15020 = v14975->cache_dirty;
      int v15118 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15015 + ((~(((v15017 ^ -1) | (-(v15017 ^ -1))) >> 31)) & 2)) - (v15018 + ((~(((v15019 ^ -1) | (-(v15019 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15021 = v15020[v15118];
      bool v15119 = !(v15021 == 0);
      if (v15119) {
        int * v15022 = v14975->cache_tags;
        int v15023 = v15022[v15118];
        int * v15024 = v14975->cache_vals;
        int v15122 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15015 + ((~(((v15017 ^ -1) | (-(v15017 ^ -1))) >> 31)) & 2)) - (v15018 + ((~(((v15019 ^ -1) | (-(v15019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15025 = v15024[v15122];
        int v15123 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15015 + ((~(((v15017 ^ -1) | (-(v15017 ^ -1))) >> 31)) & 2)) - (v15018 + ((~(((v15019 ^ -1) | (-(v15019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15026 = v15024[v15123];
        int * v15027 = v14975->mem;
        int v15125 = v15023 * 2;
        v15027[v15125] = v15025;
        int * v15029 = v14975->mem;
        int v15128 = (v15023 * 2) + 1;
        v15029[v15128] = v15026;
        ;
      } else {
        ;
      }
      int * v15034 = v14975->mem;
      int v15133 = ((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) * 2;
      int v15035 = v15034[v15133];
      int v15134 = (((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) * 2) + 1;
      int v15036 = v15034[v15134];
      int * v15037 = v14975->cache_vals;
      int v15136 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15015 + ((~(((v15017 ^ -1) | (-(v15017 ^ -1))) >> 31)) & 2)) - (v15018 + ((~(((v15019 ^ -1) | (-(v15019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15037[v15136] = v15035;
      int * v15039 = v14975->cache_vals;
      int v15139 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v15015 + ((~(((v15017 ^ -1) | (-(v15017 ^ -1))) >> 31)) & 2)) - (v15018 + ((~(((v15019 ^ -1) | (-(v15019 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15039[v15139] = v15036;
      int * v15041 = v14975->cache_tags;
      int v15142 = (int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1);
      v15041[v15118] = v15142;
      int * v15043 = v14975->cache_dirty;
      v15043[v15118] = 0;
      int * v15045 = v14975->cache_age;
      v15045[v15118] = 1;
      int * v15047 = v14975->cache_age;
      int v15048 = v15047[v15118];
      int v15049 = v15047[v15092];
      int v15148 = v15049 + ((int)((unsigned int)(v15049 - v15048) >> 31));
      v15047[v15092] = v15148;
      int * v15051 = v14975->cache_age;
      int v15052 = v15051[v15093];
      int v15150 = v15052 + ((int)((unsigned int)(v15052 - v15048) >> 31));
      v15051[v15093] = v15150;
      int * v15054 = v14975->cache_age;
      v15054[v15118] = 0;
      v15057 = v15118;
    }
    int * v15058 = v14975->cache_vals;
    int v15153 = v15057 * 2;
    int v15059 = v15058[v15153];
    int v15154 = (v15057 * 2) + 1;
    int v15060 = v15058[v15154];
    int v15155 = (((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v14999 + ((~(((v15001 ^ -1) | (-(v15001 ^ -1))) >> 31)) & 2)) - (v15002 + ((~(((v15003 ^ -1) | (-(v15003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15058[v15155] = v15059;
    int * v15062 = v14975->cache_vals;
    int v15158 = ((((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v14999 + ((~(((v15001 ^ -1) | (-(v15001 ^ -1))) >> 31)) & 2)) - (v15002 + ((~(((v15003 ^ -1) | (-(v15003 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15062[v15158] = v15060;
    int * v15064 = v14975->cache_tags;
    int v15161 = ((((int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v14999 + ((~(((v15001 ^ -1) | (-(v15001 ^ -1))) >> 31)) & 2)) - (v15002 + ((~(((v15003 ^ -1) | (-(v15003 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15162 = (int)((unsigned int)((int)((unsigned int)(v14979 + 36) >> 2)) >> 1);
    v15064[v15161] = v15162;
    int * v15066 = v14975->cache_dirty;
    v15066[v15161] = 0;
    int * v15068 = v14975->cache_age;
    v15068[v15161] = 1;
    int * v15070 = v14975->cache_age;
    int v15071 = v15070[v15161];
    int v15072 = v15070[v15090];
    int v15168 = v15072 + ((int)((unsigned int)(v15072 - v15071) >> 31));
    v15070[v15090] = v15168;
    int * v15074 = v14975->cache_age;
    int v15075 = v15074[v15091];
    int v15170 = v15075 + ((int)((unsigned int)(v15075 - v15071) >> 31));
    v15074[v15091] = v15170;
    int * v15077 = v14975->cache_age;
    v15077[v15161] = 0;
    v15080 = v15161;
  }
  int v15173 = (v15080 * 2) + (((int)((unsigned int)(v14979 + 36) >> 2)) & 1);
  int v15081 = v14987[v15173];
  int * v15082 = v14975->regs;
  v15082[18] = v15081;
  struct StateT * v15084 = slot_226(v14975);
  return v15084;
}

struct StateT * slot_355(struct StateT * v18924) {
  int v18925 = v18924->timer;
  int v18933 = v18925 + 1;
  v18924->timer = v18933;
  int * v18927 = v18924->regs;
  int v18928 = v18927[6];
  int v18929 = v18927[22];
  int v18937 = v18928 ^ v18929;
  v18927[6] = v18937;
  struct StateT * v18931 = slot_356(v18924);
  return v18931;
}

struct StateT * slot_92(struct StateT * v6476) {
  int * v6477 = v6476->saved_regs;
  int * v6478 = v6476->regs;
  int v6479 = v6478[15];
  v6477[15] = v6479;
  int v6481 = v6476->timer;
  int v6493 = v6481 + 1;
  v6476->timer = v6493;
  int * v6483 = v6476->regs;
  int v6484 = v6483[15];
  int v6485 = v6483[23];
  int v6496 = v6484 ^ v6485;
  v6483[15] = v6496;
  struct StateT * v6487 = slot_93(v6476);
  return v6487;
}

struct StateT * slot_232(struct StateT * v15179) {
  int v15180 = v15179->timer;
  int v15290 = v15180 + 1;
  v15179->timer = v15290;
  int * v15182 = v15179->regs;
  int v15183 = v15182[2];
  int * v15184 = v15179->cache_tags;
  int v15294 = (((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2;
  int v15185 = v15184[v15294];
  int v15295 = ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v15186 = v15184[v15295];
  int v15296 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2);
  int v15187 = v15184[v15296];
  int v15297 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v15188 = v15184[v15297];
  int v15189 = v15179->timer;
  int v15298 = v15189 + ((100 ^ (((~(((v15187 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15187 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v15185 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15185 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v15186 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15186 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v15187 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15187 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v15179->timer = v15298;
  int * v15191 = v15179->cache_vals;
  bool v15299 = !(((~(((v15185 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15185 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v15186 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15186 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v15284;
  if (v15299) {
    int * v15192 = v15179->cache_age;
    int v15301 = ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v15186 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15186 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v15193 = v15192[v15301];
    int v15194 = v15192[v15294];
    int v15302 = v15194 + ((int)((unsigned int)(v15194 - v15193) >> 31));
    v15192[v15294] = v15302;
    int * v15196 = v15179->cache_age;
    int v15197 = v15196[v15295];
    int v15304 = v15197 + ((int)((unsigned int)(v15197 - v15193) >> 31));
    v15196[v15295] = v15304;
    int * v15199 = v15179->cache_age;
    v15199[v15301] = 0;
    v15284 = v15301;
  } else {
    int * v15202 = v15179->cache_age;
    int v15308 = (((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2;
    int v15203 = v15202[v15308];
    int * v15204 = v15179->cache_tags;
    int v15205 = v15204[v15308];
    int v15206 = v15202[v15295];
    int v15207 = v15204[v15295];
    bool v15310 = !(((~(((v15187 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15187 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v15261;
    if (v15310) {
      int * v15208 = v15179->cache_age;
      int v15312 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))) | (-(v15188 ^ ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v15209 = v15208[v15312];
      int v15210 = v15208[v15296];
      int v15313 = v15210 + ((int)((unsigned int)(v15210 - v15209) >> 31));
      v15208[v15296] = v15313;
      int * v15212 = v15179->cache_age;
      int v15213 = v15212[v15297];
      int v15315 = v15213 + ((int)((unsigned int)(v15213 - v15209) >> 31));
      v15212[v15297] = v15315;
      int * v15215 = v15179->cache_age;
      v15215[v15312] = 0;
      v15261 = v15312;
    } else {
      int * v15218 = v15179->cache_age;
      int v15319 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2);
      int v15219 = v15218[v15319];
      int * v15220 = v15179->cache_tags;
      int v15221 = v15220[v15319];
      int v15222 = v15218[v15297];
      int v15223 = v15220[v15297];
      int * v15224 = v15179->cache_dirty;
      int v15322 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v15219 + ((~(((v15221 ^ -1) | (-(v15221 ^ -1))) >> 31)) & 2)) - (v15222 + ((~(((v15223 ^ -1) | (-(v15223 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v15225 = v15224[v15322];
      bool v15323 = !(v15225 == 0);
      if (v15323) {
        int * v15226 = v15179->cache_tags;
        int v15227 = v15226[v15322];
        int * v15228 = v15179->cache_vals;
        int v15326 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v15219 + ((~(((v15221 ^ -1) | (-(v15221 ^ -1))) >> 31)) & 2)) - (v15222 + ((~(((v15223 ^ -1) | (-(v15223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v15229 = v15228[v15326];
        int v15327 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v15219 + ((~(((v15221 ^ -1) | (-(v15221 ^ -1))) >> 31)) & 2)) - (v15222 + ((~(((v15223 ^ -1) | (-(v15223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v15230 = v15228[v15327];
        int * v15231 = v15179->mem;
        int v15329 = v15227 * 2;
        v15231[v15329] = v15229;
        int * v15233 = v15179->mem;
        int v15332 = (v15227 * 2) + 1;
        v15233[v15332] = v15230;
        ;
      } else {
        ;
      }
      int * v15238 = v15179->mem;
      int v15337 = ((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) * 2;
      int v15239 = v15238[v15337];
      int v15338 = (((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) * 2) + 1;
      int v15240 = v15238[v15338];
      int * v15241 = v15179->cache_vals;
      int v15340 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v15219 + ((~(((v15221 ^ -1) | (-(v15221 ^ -1))) >> 31)) & 2)) - (v15222 + ((~(((v15223 ^ -1) | (-(v15223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v15241[v15340] = v15239;
      int * v15243 = v15179->cache_vals;
      int v15343 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v15219 + ((~(((v15221 ^ -1) | (-(v15221 ^ -1))) >> 31)) & 2)) - (v15222 + ((~(((v15223 ^ -1) | (-(v15223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v15243[v15343] = v15240;
      int * v15245 = v15179->cache_tags;
      int v15346 = (int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1);
      v15245[v15322] = v15346;
      int * v15247 = v15179->cache_dirty;
      v15247[v15322] = 0;
      int * v15249 = v15179->cache_age;
      v15249[v15322] = 1;
      int * v15251 = v15179->cache_age;
      int v15252 = v15251[v15322];
      int v15253 = v15251[v15296];
      int v15352 = v15253 + ((int)((unsigned int)(v15253 - v15252) >> 31));
      v15251[v15296] = v15352;
      int * v15255 = v15179->cache_age;
      int v15256 = v15255[v15297];
      int v15354 = v15256 + ((int)((unsigned int)(v15256 - v15252) >> 31));
      v15255[v15297] = v15354;
      int * v15258 = v15179->cache_age;
      v15258[v15322] = 0;
      v15261 = v15322;
    }
    int * v15262 = v15179->cache_vals;
    int v15357 = v15261 * 2;
    int v15263 = v15262[v15357];
    int v15358 = (v15261 * 2) + 1;
    int v15264 = v15262[v15358];
    int v15359 = (((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v15203 + ((~(((v15205 ^ -1) | (-(v15205 ^ -1))) >> 31)) & 2)) - (v15206 + ((~(((v15207 ^ -1) | (-(v15207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v15262[v15359] = v15263;
    int * v15266 = v15179->cache_vals;
    int v15362 = ((((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v15203 + ((~(((v15205 ^ -1) | (-(v15205 ^ -1))) >> 31)) & 2)) - (v15206 + ((~(((v15207 ^ -1) | (-(v15207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v15266[v15362] = v15264;
    int * v15268 = v15179->cache_tags;
    int v15365 = ((((int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v15203 + ((~(((v15205 ^ -1) | (-(v15205 ^ -1))) >> 31)) & 2)) - (v15206 + ((~(((v15207 ^ -1) | (-(v15207 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v15366 = (int)((unsigned int)((int)((unsigned int)(v15183 + 24) >> 2)) >> 1);
    v15268[v15365] = v15366;
    int * v15270 = v15179->cache_dirty;
    v15270[v15365] = 0;
    int * v15272 = v15179->cache_age;
    v15272[v15365] = 1;
    int * v15274 = v15179->cache_age;
    int v15275 = v15274[v15365];
    int v15276 = v15274[v15294];
    int v15372 = v15276 + ((int)((unsigned int)(v15276 - v15275) >> 31));
    v15274[v15294] = v15372;
    int * v15278 = v15179->cache_age;
    int v15279 = v15278[v15295];
    int v15374 = v15279 + ((int)((unsigned int)(v15279 - v15275) >> 31));
    v15278[v15295] = v15374;
    int * v15281 = v15179->cache_age;
    v15281[v15365] = 0;
    v15284 = v15365;
  }
  int v15377 = (v15284 * 2) + (((int)((unsigned int)(v15183 + 24) >> 2)) & 1);
  int v15285 = v15191[v15377];
  int * v15286 = v15179->regs;
  v15286[21] = v15285;
  struct StateT * v15288 = slot_243(v15179);
  return v15288;
}

struct StateT * slot_466(struct StateT * v20770) {
  int v20771 = v20770->timer;
  int v20778 = v20771 + 1;
  v20770->timer = v20778;
  int * v20773 = v20770->regs;
  int v20774 = v20773[21];
  int v20782 = (int)((unsigned int)v20774 >> 14);
  v20773[24] = v20782;
  struct StateT * v20776 = slot_467(v20770);
  return v20776;
}

struct StateT * slot_304(struct StateT * v18133) {
  int v18134 = v18133->timer;
  int v18141 = v18134 + 1;
  v18133->timer = v18141;
  int * v18136 = v18133->regs;
  int v18137 = v18136[21];
  int v18145 = (int)((unsigned int)v18137 >> 14);
  v18136[24] = v18145;
  struct StateT * v18139 = slot_305(v18133);
  return v18139;
}

struct StateT * slot_31(struct StateT * v5423) {
  int v5424 = v5423->timer;
  int v5430 = v5424 + 1;
  v5423->timer = v5430;
  int * v5426 = v5423->regs;
  v5426[11] = 9;
  struct StateT * v5428 = slot_32(v5423);
  return v5428;
}

struct StateT * slot_236(struct StateT * v15805) {
  int v15806 = v15805->timer;
  int v15814 = v15806 + 1;
  v15805->timer = v15814;
  int * v15808 = v15805->regs;
  int v15809 = v15808[22];
  int v15810 = v15808[24];
  int v15818 = v15809 | v15810;
  v15808[22] = v15818;
  struct StateT * v15812 = slot_239(v15805);
  return v15812;
}

struct StateT * slot_241(struct StateT * v16448) {
  int v16449 = v16448->timer;
  int v16559 = v16449 + 1;
  v16448->timer = v16559;
  int * v16451 = v16448->regs;
  int v16452 = v16451[2];
  int * v16453 = v16448->cache_tags;
  int v16563 = (((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2;
  int v16454 = v16453[v16563];
  int v16564 = ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16455 = v16453[v16564];
  int v16565 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2);
  int v16456 = v16453[v16565];
  int v16566 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16457 = v16453[v16566];
  int v16458 = v16448->timer;
  int v16567 = v16458 + ((100 ^ (((~(((v16456 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16456 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16454 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16454 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v16455 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16455 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16456 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16456 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16448->timer = v16567;
  int * v16460 = v16448->cache_vals;
  bool v16568 = !(((~(((v16454 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16454 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v16455 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16455 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v16553;
  if (v16568) {
    int * v16461 = v16448->cache_age;
    int v16570 = ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v16455 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16455 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v16462 = v16461[v16570];
    int v16463 = v16461[v16563];
    int v16571 = v16463 + ((int)((unsigned int)(v16463 - v16462) >> 31));
    v16461[v16563] = v16571;
    int * v16465 = v16448->cache_age;
    int v16466 = v16465[v16564];
    int v16573 = v16466 + ((int)((unsigned int)(v16466 - v16462) >> 31));
    v16465[v16564] = v16573;
    int * v16468 = v16448->cache_age;
    v16468[v16570] = 0;
    v16553 = v16570;
  } else {
    int * v16471 = v16448->cache_age;
    int v16577 = (((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2;
    int v16472 = v16471[v16577];
    int * v16473 = v16448->cache_tags;
    int v16474 = v16473[v16577];
    int v16475 = v16471[v16564];
    int v16476 = v16473[v16564];
    bool v16579 = !(((~(((v16456 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16456 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v16530;
    if (v16579) {
      int * v16477 = v16448->cache_age;
      int v16581 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))) | (-(v16457 ^ ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v16478 = v16477[v16581];
      int v16479 = v16477[v16565];
      int v16582 = v16479 + ((int)((unsigned int)(v16479 - v16478) >> 31));
      v16477[v16565] = v16582;
      int * v16481 = v16448->cache_age;
      int v16482 = v16481[v16566];
      int v16584 = v16482 + ((int)((unsigned int)(v16482 - v16478) >> 31));
      v16481[v16566] = v16584;
      int * v16484 = v16448->cache_age;
      v16484[v16581] = 0;
      v16530 = v16581;
    } else {
      int * v16487 = v16448->cache_age;
      int v16588 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2);
      int v16488 = v16487[v16588];
      int * v16489 = v16448->cache_tags;
      int v16490 = v16489[v16588];
      int v16491 = v16487[v16566];
      int v16492 = v16489[v16566];
      int * v16493 = v16448->cache_dirty;
      int v16591 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v16488 + ((~(((v16490 ^ -1) | (-(v16490 ^ -1))) >> 31)) & 2)) - (v16491 + ((~(((v16492 ^ -1) | (-(v16492 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16494 = v16493[v16591];
      bool v16592 = !(v16494 == 0);
      if (v16592) {
        int * v16495 = v16448->cache_tags;
        int v16496 = v16495[v16591];
        int * v16497 = v16448->cache_vals;
        int v16595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v16488 + ((~(((v16490 ^ -1) | (-(v16490 ^ -1))) >> 31)) & 2)) - (v16491 + ((~(((v16492 ^ -1) | (-(v16492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16498 = v16497[v16595];
        int v16596 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v16488 + ((~(((v16490 ^ -1) | (-(v16490 ^ -1))) >> 31)) & 2)) - (v16491 + ((~(((v16492 ^ -1) | (-(v16492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16499 = v16497[v16596];
        int * v16500 = v16448->mem;
        int v16598 = v16496 * 2;
        v16500[v16598] = v16498;
        int * v16502 = v16448->mem;
        int v16601 = (v16496 * 2) + 1;
        v16502[v16601] = v16499;
        ;
      } else {
        ;
      }
      int * v16507 = v16448->mem;
      int v16606 = ((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) * 2;
      int v16508 = v16507[v16606];
      int v16607 = (((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) * 2) + 1;
      int v16509 = v16507[v16607];
      int * v16510 = v16448->cache_vals;
      int v16609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v16488 + ((~(((v16490 ^ -1) | (-(v16490 ^ -1))) >> 31)) & 2)) - (v16491 + ((~(((v16492 ^ -1) | (-(v16492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16510[v16609] = v16508;
      int * v16512 = v16448->cache_vals;
      int v16612 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v16488 + ((~(((v16490 ^ -1) | (-(v16490 ^ -1))) >> 31)) & 2)) - (v16491 + ((~(((v16492 ^ -1) | (-(v16492 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16512[v16612] = v16509;
      int * v16514 = v16448->cache_tags;
      int v16615 = (int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1);
      v16514[v16591] = v16615;
      int * v16516 = v16448->cache_dirty;
      v16516[v16591] = 0;
      int * v16518 = v16448->cache_age;
      v16518[v16591] = 1;
      int * v16520 = v16448->cache_age;
      int v16521 = v16520[v16591];
      int v16522 = v16520[v16565];
      int v16621 = v16522 + ((int)((unsigned int)(v16522 - v16521) >> 31));
      v16520[v16565] = v16621;
      int * v16524 = v16448->cache_age;
      int v16525 = v16524[v16566];
      int v16623 = v16525 + ((int)((unsigned int)(v16525 - v16521) >> 31));
      v16524[v16566] = v16623;
      int * v16527 = v16448->cache_age;
      v16527[v16591] = 0;
      v16530 = v16591;
    }
    int * v16531 = v16448->cache_vals;
    int v16626 = v16530 * 2;
    int v16532 = v16531[v16626];
    int v16627 = (v16530 * 2) + 1;
    int v16533 = v16531[v16627];
    int v16628 = (((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v16472 + ((~(((v16474 ^ -1) | (-(v16474 ^ -1))) >> 31)) & 2)) - (v16475 + ((~(((v16476 ^ -1) | (-(v16476 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16531[v16628] = v16532;
    int * v16535 = v16448->cache_vals;
    int v16631 = ((((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v16472 + ((~(((v16474 ^ -1) | (-(v16474 ^ -1))) >> 31)) & 2)) - (v16475 + ((~(((v16476 ^ -1) | (-(v16476 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16535[v16631] = v16533;
    int * v16537 = v16448->cache_tags;
    int v16634 = ((((int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v16472 + ((~(((v16474 ^ -1) | (-(v16474 ^ -1))) >> 31)) & 2)) - (v16475 + ((~(((v16476 ^ -1) | (-(v16476 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16635 = (int)((unsigned int)((int)((unsigned int)(v16452 + 12) >> 2)) >> 1);
    v16537[v16634] = v16635;
    int * v16539 = v16448->cache_dirty;
    v16539[v16634] = 0;
    int * v16541 = v16448->cache_age;
    v16541[v16634] = 1;
    int * v16543 = v16448->cache_age;
    int v16544 = v16543[v16634];
    int v16545 = v16543[v16563];
    int v16641 = v16545 + ((int)((unsigned int)(v16545 - v16544) >> 31));
    v16543[v16563] = v16641;
    int * v16547 = v16448->cache_age;
    int v16548 = v16547[v16564];
    int v16643 = v16548 + ((int)((unsigned int)(v16548 - v16544) >> 31));
    v16547[v16564] = v16643;
    int * v16550 = v16448->cache_age;
    v16550[v16634] = 0;
    v16553 = v16634;
  }
  int v16646 = (v16553 * 2) + (((int)((unsigned int)(v16452 + 12) >> 2)) & 1);
  int v16554 = v16460[v16646];
  int * v16555 = v16448->regs;
  v16555[24] = v16554;
  struct StateT * v16557 = slot_252(v16448);
  return v16557;
}

struct StateT * slot_160(struct StateT * v7576) {
  int v7577 = v7576->timer;
  int v7584 = v7577 + 1;
  v7576->timer = v7584;
  int * v7579 = v7576->regs;
  int v7580 = v7579[21];
  int v7588 = (int)((unsigned int)v7580 >> 19);
  v7579[24] = v7588;
  struct StateT * v7582 = slot_161(v7576);
  return v7582;
}

struct StateT * slot_519(struct StateT * v21621) {
  int v21622 = v21621->timer;
  int v21630 = v21622 + 1;
  v21621->timer = v21630;
  int * v21624 = v21621->regs;
  int v21625 = v21624[17];
  int v21626 = v21624[14];
  int v21635 = v21625 + v21626;
  v21624[20] = v21635;
  struct StateT * v21628 = slot_520(v21621);
  return v21628;
}

struct StateT * slot_150(struct StateT * v7415) {
  int v7416 = v7415->timer;
  int v7424 = v7416 + 1;
  v7415->timer = v7424;
  int * v7418 = v7415->regs;
  int v7419 = v7418[5];
  int v7420 = v7418[21];
  int v7428 = v7419 ^ v7420;
  v7418[5] = v7428;
  struct StateT * v7422 = slot_151(v7415);
  return v7422;
}

struct StateT * slot_391(struct StateT * v19486) {
  int v19487 = v19486->timer;
  int v19494 = v19487 + 1;
  v19486->timer = v19494;
  int * v19489 = v19486->regs;
  int v19490 = v19489[23];
  int v19497 = v19490 << 18;
  v19489[23] = v19497;
  struct StateT * v19492 = slot_392(v19486);
  return v19492;
}

struct StateT * slot_74(struct StateT * v6176) {
  int v6177 = v6176->timer;
  int v6185 = v6177 + 1;
  v6176->timer = v6185;
  int * v6179 = v6176->regs;
  int v6180 = v6179[7];
  int v6181 = v6179[18];
  int v6190 = v6180 + v6181;
  v6179[21] = v6190;
  struct StateT * v6183 = slot_75(v6176);
  return v6183;
}

struct StateT * slot_262(struct StateT * v17479) {
  int v17480 = v17479->timer;
  int v17487 = v17480 + 1;
  v17479->timer = v17487;
  int * v17482 = v17479->regs;
  int v17483 = v17482[20];
  int v17490 = v17483 << 9;
  v17482[20] = v17490;
  struct StateT * v17485 = slot_263(v17479);
  return v17485;
}

struct StateT * slot_351(struct StateT * v18862) {
  int v18863 = v18862->timer;
  int v18870 = v18863 + 1;
  v18862->timer = v18870;
  int * v18865 = v18862->regs;
  int v18866 = v18865[23];
  int v18873 = v18866 << 9;
  v18865[23] = v18873;
  struct StateT * v18868 = slot_352(v18862);
  return v18868;
}

struct StateT * slot_372(struct StateT * v19188) {
  int v19189 = v19188->timer;
  int v19197 = v19189 + 1;
  v19188->timer = v19197;
  int * v19191 = v19188->regs;
  int v19192 = v19191[23];
  int v19193 = v19191[24];
  int v19201 = v19192 | v19193;
  v19191[23] = v19201;
  struct StateT * v19195 = slot_373(v19188);
  return v19195;
}

struct StateT * slot_403(struct StateT * v19698) {
  int * v19699 = v19698->saved_regs;
  int * v19700 = v19698->regs;
  int v19701 = v19700[24];
  v19699[24] = v19701;
  int v19703 = v19698->timer;
  int v19714 = v19703 + 1;
  v19698->timer = v19714;
  int * v19705 = v19698->regs;
  int v19706 = v19705[20];
  int v19717 = (int)((unsigned int)v19706 >> 25);
  v19705[24] = v19717;
  struct StateT * v19708 = slot_404(v19698);
  return v19708;
}

struct StateT * slot_107(struct StateT * v6717) {
  int v6718 = v6717->timer;
  int v6725 = v6718 + 1;
  v6717->timer = v6725;
  int * v6720 = v6717->regs;
  int v6721 = v6720[23];
  int v6728 = v6721 << 18;
  v6720[23] = v6728;
  struct StateT * v6723 = slot_108(v6717);
  return v6723;
}

struct StateT * slot_555(struct StateT * v22181) {
  int v22182 = v22181->timer;
  int v22190 = v22182 + 1;
  v22181->timer = v22190;
  int * v22184 = v22181->regs;
  int v22185 = v22184[30];
  int v22186 = v22184[20];
  int v22194 = v22185 ^ v22186;
  v22184[30] = v22194;
  struct StateT * v22188 = slot_556(v22181);
  return v22188;
}

struct StateT * slot_541(struct StateT * v21967) {
  int v21968 = v21967->timer;
  int v21976 = v21968 + 1;
  v21967->timer = v21976;
  int * v21970 = v21967->regs;
  int v21971 = v21970[18];
  int v21972 = v21970[6];
  int v21981 = v21971 + v21972;
  v21970[22] = v21981;
  struct StateT * v21974 = slot_542(v21967);
  return v21974;
}

struct StateT * slot_325(struct StateT * v18460) {
  int v18461 = v18460->timer;
  int v18468 = v18461 + 1;
  v18460->timer = v18468;
  int * v18463 = v18460->regs;
  int v18464 = v18463[21];
  int v18471 = v18464 << 7;
  v18463[21] = v18471;
  struct StateT * v18466 = slot_326(v18460);
  return v18466;
}

struct StateT * slot_84(struct StateT * v6332) {
  int v6333 = v6332->timer;
  int v6340 = v6333 + 1;
  v6332->timer = v6340;
  int * v6335 = v6332->regs;
  int v6336 = v6335[22];
  int v6343 = v6336 << 13;
  v6335[22] = v6343;
  struct StateT * v6338 = slot_85(v6332);
  return v6338;
}

struct StateT * slot_28(struct StateT * v5381) {
  int v5382 = v5381->timer;
  int v5389 = v5382 + 1;
  v5381->timer = v5389;
  int * v5384 = v5381->regs;
  int v5385 = v5384[31];
  int v5393 = v5385 + -718;
  v5384[28] = v5393;
  struct StateT * v5387 = slot_29(v5381);
  return v5387;
}

struct StateT * slot_155(struct StateT * v7497) {
  int v7498 = v7497->timer;
  int v7506 = v7498 + 1;
  v7497->timer = v7506;
  int * v7500 = v7497->regs;
  int v7501 = v7500[6];
  int v7502 = v7500[15];
  int v7511 = v7501 + v7502;
  v7500[22] = v7511;
  struct StateT * v7504 = slot_156(v7497);
  return v7504;
}

struct StateT * slot_177(struct StateT * v7843) {
  int v7844 = v7843->timer;
  int v7851 = v7844 + 1;
  v7843->timer = v7851;
  int * v7846 = v7843->regs;
  int v7847 = v7846[20];
  int v7855 = (int)((unsigned int)v7847 >> 14);
  v7846[24] = v7855;
  struct StateT * v7849 = slot_178(v7843);
  return v7849;
}

struct StateT * slot_517(struct StateT * v21589) {
  int v21590 = v21589->timer;
  int v21598 = v21590 + 1;
  v21589->timer = v21598;
  int * v21592 = v21589->regs;
  int v21593 = v21592[6];
  int v21594 = v21592[22];
  int v21602 = v21593 ^ v21594;
  v21592[6] = v21602;
  struct StateT * v21596 = slot_518(v21589);
  return v21596;
}

struct StateT * slot_229(struct StateT * v14756) {
  int v14757 = v14756->timer;
  int v14867 = v14757 + 1;
  v14756->timer = v14867;
  int * v14759 = v14756->regs;
  int v14760 = v14759[2];
  int * v14761 = v14756->cache_tags;
  int v14871 = (((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2;
  int v14762 = v14761[v14871];
  int v14872 = ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14763 = v14761[v14872];
  int v14873 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2);
  int v14764 = v14761[v14873];
  int v14874 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14765 = v14761[v14874];
  int v14766 = v14756->timer;
  int v14875 = v14766 + ((100 ^ (((~(((v14764 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14764 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14762 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14762 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14763 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14763 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14764 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14764 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14756->timer = v14875;
  int * v14768 = v14756->cache_vals;
  bool v14876 = !(((~(((v14762 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14762 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14763 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14763 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v14861;
  if (v14876) {
    int * v14769 = v14756->cache_age;
    int v14878 = ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v14763 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14763 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v14770 = v14769[v14878];
    int v14771 = v14769[v14871];
    int v14879 = v14771 + ((int)((unsigned int)(v14771 - v14770) >> 31));
    v14769[v14871] = v14879;
    int * v14773 = v14756->cache_age;
    int v14774 = v14773[v14872];
    int v14881 = v14774 + ((int)((unsigned int)(v14774 - v14770) >> 31));
    v14773[v14872] = v14881;
    int * v14776 = v14756->cache_age;
    v14776[v14878] = 0;
    v14861 = v14878;
  } else {
    int * v14779 = v14756->cache_age;
    int v14885 = (((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2;
    int v14780 = v14779[v14885];
    int * v14781 = v14756->cache_tags;
    int v14782 = v14781[v14885];
    int v14783 = v14779[v14872];
    int v14784 = v14781[v14872];
    bool v14887 = !(((~(((v14764 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14764 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v14838;
    if (v14887) {
      int * v14785 = v14756->cache_age;
      int v14889 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))) | (-(v14765 ^ ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v14786 = v14785[v14889];
      int v14787 = v14785[v14873];
      int v14890 = v14787 + ((int)((unsigned int)(v14787 - v14786) >> 31));
      v14785[v14873] = v14890;
      int * v14789 = v14756->cache_age;
      int v14790 = v14789[v14874];
      int v14892 = v14790 + ((int)((unsigned int)(v14790 - v14786) >> 31));
      v14789[v14874] = v14892;
      int * v14792 = v14756->cache_age;
      v14792[v14889] = 0;
      v14838 = v14889;
    } else {
      int * v14795 = v14756->cache_age;
      int v14896 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2);
      int v14796 = v14795[v14896];
      int * v14797 = v14756->cache_tags;
      int v14798 = v14797[v14896];
      int v14799 = v14795[v14874];
      int v14800 = v14797[v14874];
      int * v14801 = v14756->cache_dirty;
      int v14899 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14796 + ((~(((v14798 ^ -1) | (-(v14798 ^ -1))) >> 31)) & 2)) - (v14799 + ((~(((v14800 ^ -1) | (-(v14800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14802 = v14801[v14899];
      bool v14900 = !(v14802 == 0);
      if (v14900) {
        int * v14803 = v14756->cache_tags;
        int v14804 = v14803[v14899];
        int * v14805 = v14756->cache_vals;
        int v14903 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14796 + ((~(((v14798 ^ -1) | (-(v14798 ^ -1))) >> 31)) & 2)) - (v14799 + ((~(((v14800 ^ -1) | (-(v14800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14806 = v14805[v14903];
        int v14904 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14796 + ((~(((v14798 ^ -1) | (-(v14798 ^ -1))) >> 31)) & 2)) - (v14799 + ((~(((v14800 ^ -1) | (-(v14800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14807 = v14805[v14904];
        int * v14808 = v14756->mem;
        int v14906 = v14804 * 2;
        v14808[v14906] = v14806;
        int * v14810 = v14756->mem;
        int v14909 = (v14804 * 2) + 1;
        v14810[v14909] = v14807;
        ;
      } else {
        ;
      }
      int * v14815 = v14756->mem;
      int v14914 = ((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) * 2;
      int v14816 = v14815[v14914];
      int v14915 = (((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) * 2) + 1;
      int v14817 = v14815[v14915];
      int * v14818 = v14756->cache_vals;
      int v14917 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14796 + ((~(((v14798 ^ -1) | (-(v14798 ^ -1))) >> 31)) & 2)) - (v14799 + ((~(((v14800 ^ -1) | (-(v14800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14818[v14917] = v14816;
      int * v14820 = v14756->cache_vals;
      int v14920 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v14796 + ((~(((v14798 ^ -1) | (-(v14798 ^ -1))) >> 31)) & 2)) - (v14799 + ((~(((v14800 ^ -1) | (-(v14800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14820[v14920] = v14817;
      int * v14822 = v14756->cache_tags;
      int v14923 = (int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1);
      v14822[v14899] = v14923;
      int * v14824 = v14756->cache_dirty;
      v14824[v14899] = 0;
      int * v14826 = v14756->cache_age;
      v14826[v14899] = 1;
      int * v14828 = v14756->cache_age;
      int v14829 = v14828[v14899];
      int v14830 = v14828[v14873];
      int v14929 = v14830 + ((int)((unsigned int)(v14830 - v14829) >> 31));
      v14828[v14873] = v14929;
      int * v14832 = v14756->cache_age;
      int v14833 = v14832[v14874];
      int v14931 = v14833 + ((int)((unsigned int)(v14833 - v14829) >> 31));
      v14832[v14874] = v14931;
      int * v14835 = v14756->cache_age;
      v14835[v14899] = 0;
      v14838 = v14899;
    }
    int * v14839 = v14756->cache_vals;
    int v14934 = v14838 * 2;
    int v14840 = v14839[v14934];
    int v14935 = (v14838 * 2) + 1;
    int v14841 = v14839[v14935];
    int v14936 = (((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v14780 + ((~(((v14782 ^ -1) | (-(v14782 ^ -1))) >> 31)) & 2)) - (v14783 + ((~(((v14784 ^ -1) | (-(v14784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14839[v14936] = v14840;
    int * v14843 = v14756->cache_vals;
    int v14939 = ((((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v14780 + ((~(((v14782 ^ -1) | (-(v14782 ^ -1))) >> 31)) & 2)) - (v14783 + ((~(((v14784 ^ -1) | (-(v14784 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14843[v14939] = v14841;
    int * v14845 = v14756->cache_tags;
    int v14942 = ((((int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v14780 + ((~(((v14782 ^ -1) | (-(v14782 ^ -1))) >> 31)) & 2)) - (v14783 + ((~(((v14784 ^ -1) | (-(v14784 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14943 = (int)((unsigned int)((int)((unsigned int)(v14760 + 28) >> 2)) >> 1);
    v14845[v14942] = v14943;
    int * v14847 = v14756->cache_dirty;
    v14847[v14942] = 0;
    int * v14849 = v14756->cache_age;
    v14849[v14942] = 1;
    int * v14851 = v14756->cache_age;
    int v14852 = v14851[v14942];
    int v14853 = v14851[v14871];
    int v14949 = v14853 + ((int)((unsigned int)(v14853 - v14852) >> 31));
    v14851[v14871] = v14949;
    int * v14855 = v14756->cache_age;
    int v14856 = v14855[v14872];
    int v14951 = v14856 + ((int)((unsigned int)(v14856 - v14852) >> 31));
    v14855[v14872] = v14951;
    int * v14858 = v14756->cache_age;
    v14858[v14942] = 0;
    v14861 = v14942;
  }
  int v14954 = (v14861 * 2) + (((int)((unsigned int)(v14760 + 28) >> 2)) & 1);
  int v14862 = v14768[v14954];
  int * v14863 = v14756->regs;
  v14863[20] = v14862;
  struct StateT * v14865 = slot_232(v14756);
  return v14865;
}

struct StateT * slot_358(struct StateT * v18973) {
  int v18974 = v18973->timer;
  int v18982 = v18974 + 1;
  v18973->timer = v18982;
  int * v18976 = v18973->regs;
  int v18977 = v18976[5];
  int v18978 = v18976[12];
  int v18987 = v18977 + v18978;
  v18976[21] = v18987;
  struct StateT * v18980 = slot_359(v18973);
  return v18980;
}

struct StateT * slot_465(struct StateT * v20754) {
  int v20755 = v20754->timer;
  int v20763 = v20755 + 1;
  v20754->timer = v20763;
  int * v20757 = v20754->regs;
  int v20758 = v20757[20];
  int v20759 = v20757[24];
  int v20767 = v20758 | v20759;
  v20757[20] = v20767;
  struct StateT * v20761 = slot_466(v20754);
  return v20761;
}

struct StateT * slot_181(struct StateT * v7903) {
  int v7904 = v7903->timer;
  int v7911 = v7904 + 1;
  v7903->timer = v7911;
  int * v7906 = v7903->regs;
  int v7907 = v7906[21];
  int v7914 = v7907 << 18;
  v7906[21] = v7914;
  struct StateT * v7909 = slot_182(v7903);
  return v7909;
}

struct StateT * slot_542(struct StateT * v21984) {
  int v21985 = v21984->timer;
  int v21993 = v21985 + 1;
  v21984->timer = v21993;
  int * v21987 = v21984->regs;
  int v21988 = v21987[19];
  int v21989 = v21987[7];
  int v21998 = v21988 + v21989;
  v21987[23] = v21998;
  struct StateT * v21991 = slot_543(v21984);
  return v21991;
}

struct StateT * slot_154(struct StateT * v7480) {
  int v7481 = v7480->timer;
  int v7489 = v7481 + 1;
  v7480->timer = v7489;
  int * v7483 = v7480->regs;
  int v7484 = v7483[5];
  int v7485 = v7483[12];
  int v7494 = v7484 + v7485;
  v7483[21] = v7494;
  struct StateT * v7487 = slot_155(v7480);
  return v7487;
}

struct StateT * slot_260(struct StateT * v17447) {
  int v17448 = v17447->timer;
  int v17456 = v17448 + 1;
  v17447->timer = v17456;
  int * v17450 = v17447->regs;
  int v17451 = v17450[8];
  int v17452 = v17450[31];
  int v17461 = v17451 + v17452;
  v17450[23] = v17461;
  struct StateT * v17454 = slot_261(v17447);
  return v17454;
}

struct StateT * slot_481(struct StateT * v21031) {
  int v21032 = v21031->timer;
  int v21040 = v21032 + 1;
  v21031->timer = v21040;
  int * v21034 = v21031->regs;
  int v21035 = v21034[28];
  int v21036 = v21034[18];
  int v21045 = v21035 + v21036;
  v21034[22] = v21045;
  struct StateT * v21038 = slot_482(v21031);
  return v21038;
}

struct StateT * slot_305(struct StateT * v18148) {
  int v18149 = v18148->timer;
  int v18156 = v18149 + 1;
  v18148->timer = v18156;
  int * v18151 = v18148->regs;
  int v18152 = v18151[21];
  int v18159 = v18152 << 18;
  v18151[21] = v18159;
  struct StateT * v18154 = slot_306(v18148);
  return v18154;
}

struct StateT * slot_27(struct StateT * v5366) {
  int v5367 = v5366->timer;
  int v5374 = v5367 + 1;
  v5366->timer = v5374;
  int * v5369 = v5366->regs;
  int v5370 = v5369[28];
  int v5378 = v5370 + 1134;
  v5369[29] = v5378;
  struct StateT * v5372 = slot_28(v5366);
  return v5372;
}

struct StateT * slot_454(struct StateT * v20549) {
  int v20550 = v20549->timer;
  int v20558 = v20550 + 1;
  v20549->timer = v20558;
  int * v20552 = v20549->regs;
  int v20553 = v20552[23];
  int v20554 = v20552[24];
  int v20562 = v20553 | v20554;
  v20552[23] = v20562;
  struct StateT * v20556 = slot_455(v20549);
  return v20556;
}

struct StateT * slot_34(struct StateT * v5468) {
  int * v5469 = v5468->saved_regs;
  int * v5470 = v5468->regs;
  int v5471 = v5470[21];
  v5469[21] = v5471;
  int v5473 = v5468->timer;
  int v5485 = v5473 + 1;
  v5468->timer = v5485;
  int * v5475 = v5468->regs;
  int v5476 = v5475[29];
  int v5477 = v5475[14];
  int v5489 = v5476 + v5477;
  v5475[21] = v5489;
  struct StateT * v5479 = slot_35(v5468);
  return v5479;
}

struct StateT * slot_482(struct StateT * v21048) {
  int v21049 = v21048->timer;
  int v21057 = v21049 + 1;
  v21048->timer = v21057;
  int * v21051 = v21048->regs;
  int v21052 = v21051[31];
  int v21053 = v21051[19];
  int v21062 = v21052 + v21053;
  v21051[23] = v21062;
  struct StateT * v21055 = slot_483(v21048);
  return v21055;
}

struct StateT * slot_21(struct StateT * v4904) {
  int v4905 = v4904->timer;
  int v5015 = v4905 + 1;
  v4904->timer = v5015;
  int * v4907 = v4904->regs;
  int v4908 = v4907[11];
  int * v4909 = v4904->cache_tags;
  int v5019 = (((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2;
  int v4910 = v4909[v5019];
  int v5020 = ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4911 = v4909[v5020];
  int v5021 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2);
  int v4912 = v4909[v5021];
  int v5022 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4913 = v4909[v5022];
  int v4914 = v4904->timer;
  int v5023 = v4914 + ((100 ^ (((~(((v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4904->timer = v5023;
  int * v4916 = v4904->cache_vals;
  bool v5024 = !(((~(((v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v5009;
  if (v5024) {
    int * v4917 = v4904->cache_age;
    int v5026 = ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4918 = v4917[v5026];
    int v4919 = v4917[v5019];
    int v5027 = v4919 + ((int)((unsigned int)(v4919 - v4918) >> 31));
    v4917[v5019] = v5027;
    int * v4921 = v4904->cache_age;
    int v4922 = v4921[v5020];
    int v5029 = v4922 + ((int)((unsigned int)(v4922 - v4918) >> 31));
    v4921[v5020] = v5029;
    int * v4924 = v4904->cache_age;
    v4924[v5026] = 0;
    v5009 = v5026;
  } else {
    int * v4927 = v4904->cache_age;
    int v5033 = (((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2;
    int v4928 = v4927[v5033];
    int * v4929 = v4904->cache_tags;
    int v4930 = v4929[v5033];
    int v4931 = v4927[v5020];
    int v4932 = v4929[v5020];
    bool v5035 = !(((~(((v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v4986;
    if (v5035) {
      int * v4933 = v4904->cache_age;
      int v5037 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v4934 = v4933[v5037];
      int v4935 = v4933[v5021];
      int v5038 = v4935 + ((int)((unsigned int)(v4935 - v4934) >> 31));
      v4933[v5021] = v5038;
      int * v4937 = v4904->cache_age;
      int v4938 = v4937[v5022];
      int v5040 = v4938 + ((int)((unsigned int)(v4938 - v4934) >> 31));
      v4937[v5022] = v5040;
      int * v4940 = v4904->cache_age;
      v4940[v5037] = 0;
      v4986 = v5037;
    } else {
      int * v4943 = v4904->cache_age;
      int v5044 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2);
      int v4944 = v4943[v5044];
      int * v4945 = v4904->cache_tags;
      int v4946 = v4945[v5044];
      int v4947 = v4943[v5022];
      int v4948 = v4945[v5022];
      int * v4949 = v4904->cache_dirty;
      int v5047 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4950 = v4949[v5047];
      bool v5048 = !(v4950 == 0);
      if (v5048) {
        int * v4951 = v4904->cache_tags;
        int v4952 = v4951[v5047];
        int * v4953 = v4904->cache_vals;
        int v5051 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4954 = v4953[v5051];
        int v5052 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4955 = v4953[v5052];
        int * v4956 = v4904->mem;
        int v5054 = v4952 * 2;
        v4956[v5054] = v4954;
        int * v4958 = v4904->mem;
        int v5057 = (v4952 * 2) + 1;
        v4958[v5057] = v4955;
        ;
      } else {
        ;
      }
      int * v4963 = v4904->mem;
      int v5062 = ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) * 2;
      int v4964 = v4963[v5062];
      int v5063 = (((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) * 2) + 1;
      int v4965 = v4963[v5063];
      int * v4966 = v4904->cache_vals;
      int v5065 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4966[v5065] = v4964;
      int * v4968 = v4904->cache_vals;
      int v5068 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4968[v5068] = v4965;
      int * v4970 = v4904->cache_tags;
      int v5071 = (int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1);
      v4970[v5047] = v5071;
      int * v4972 = v4904->cache_dirty;
      v4972[v5047] = 0;
      int * v4974 = v4904->cache_age;
      v4974[v5047] = 1;
      int * v4976 = v4904->cache_age;
      int v4977 = v4976[v5047];
      int v4978 = v4976[v5021];
      int v5077 = v4978 + ((int)((unsigned int)(v4978 - v4977) >> 31));
      v4976[v5021] = v5077;
      int * v4980 = v4904->cache_age;
      int v4981 = v4980[v5022];
      int v5079 = v4981 + ((int)((unsigned int)(v4981 - v4977) >> 31));
      v4980[v5022] = v5079;
      int * v4983 = v4904->cache_age;
      v4983[v5047] = 0;
      v4986 = v5047;
    }
    int * v4987 = v4904->cache_vals;
    int v5082 = v4986 * 2;
    int v4988 = v4987[v5082];
    int v5083 = (v4986 * 2) + 1;
    int v4989 = v4987[v5083];
    int v5084 = (((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4928 + ((~(((v4930 ^ -1) | (-(v4930 ^ -1))) >> 31)) & 2)) - (v4931 + ((~(((v4932 ^ -1) | (-(v4932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4987[v5084] = v4988;
    int * v4991 = v4904->cache_vals;
    int v5087 = ((((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4928 + ((~(((v4930 ^ -1) | (-(v4930 ^ -1))) >> 31)) & 2)) - (v4931 + ((~(((v4932 ^ -1) | (-(v4932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4991[v5087] = v4989;
    int * v4993 = v4904->cache_tags;
    int v5090 = ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4928 + ((~(((v4930 ^ -1) | (-(v4930 ^ -1))) >> 31)) & 2)) - (v4931 + ((~(((v4932 ^ -1) | (-(v4932 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5091 = (int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1);
    v4993[v5090] = v5091;
    int * v4995 = v4904->cache_dirty;
    v4995[v5090] = 0;
    int * v4997 = v4904->cache_age;
    v4997[v5090] = 1;
    int * v4999 = v4904->cache_age;
    int v5000 = v4999[v5090];
    int v5001 = v4999[v5019];
    int v5097 = v5001 + ((int)((unsigned int)(v5001 - v5000) >> 31));
    v4999[v5019] = v5097;
    int * v5003 = v4904->cache_age;
    int v5004 = v5003[v5020];
    int v5099 = v5004 + ((int)((unsigned int)(v5004 - v5000) >> 31));
    v5003[v5020] = v5099;
    int * v5006 = v4904->cache_age;
    v5006[v5090] = 0;
    v5009 = v5090;
  }
  int v5102 = (v5009 * 2) + (((int)((unsigned int)(v4908 + 8) >> 2)) & 1);
  int v5010 = v4916[v5102];
  int * v5011 = v4904->regs;
  v5011[6] = v5010;
  struct StateT * v5013 = slot_22(v4904);
  return v5013;
}

struct StateT * slot_406(struct StateT * v19750) {
  int v19751 = v19750->timer;
  int v19758 = v19751 + 1;
  v19750->timer = v19758;
  int * v19753 = v19750->regs;
  int v19754 = v19753[21];
  int v19762 = (int)((unsigned int)v19754 >> 25);
  v19753[24] = v19762;
  struct StateT * v19756 = slot_407(v19750);
  return v19756;
}

struct StateT * slot_292(struct StateT * v17940) {
  int v17941 = v17940->timer;
  int v17949 = v17941 + 1;
  v17940->timer = v17949;
  int * v17943 = v17940->regs;
  int v17944 = v17943[23];
  int v17945 = v17943[24];
  int v17953 = v17944 | v17945;
  v17943[23] = v17953;
  struct StateT * v17947 = slot_293(v17940);
  return v17947;
}

struct StateT * slot_118(struct StateT * v6922) {
  int v6923 = v6922->timer;
  int v6930 = v6923 + 1;
  v6922->timer = v6930;
  int * v6925 = v6922->regs;
  int v6926 = v6925[20];
  int v6933 = v6926 << 7;
  v6925[20] = v6933;
  struct StateT * v6928 = slot_119(v6922);
  return v6928;
}

struct StateT * slot_525(struct StateT * v21718) {
  int v21719 = v21718->timer;
  int v21727 = v21719 + 1;
  v21718->timer = v21727;
  int * v21721 = v21718->regs;
  int v21722 = v21721[20];
  int v21723 = v21721[24];
  int v21731 = v21722 | v21723;
  v21721[20] = v21731;
  struct StateT * v21725 = slot_526(v21718);
  return v21725;
}

struct StateT * slot_515(struct StateT * v21557) {
  int v21558 = v21557->timer;
  int v21566 = v21558 + 1;
  v21557->timer = v21566;
  int * v21560 = v21557->regs;
  int v21561 = v21560[17];
  int v21562 = v21560[20];
  int v21570 = v21561 ^ v21562;
  v21560[17] = v21570;
  struct StateT * v21564 = slot_516(v21557);
  return v21564;
}

struct StateT * slot_376(struct StateT * v19252) {
  int v19253 = v19252->timer;
  int v19261 = v19253 + 1;
  v19252->timer = v19261;
  int * v19255 = v19252->regs;
  int v19256 = v19255[19];
  int v19257 = v19255[23];
  int v19265 = v19256 ^ v19257;
  v19255[19] = v19265;
  struct StateT * v19259 = slot_377(v19252);
  return v19259;
}

struct StateT * slot_373(struct StateT * v19204) {
  int v19205 = v19204->timer;
  int v19213 = v19205 + 1;
  v19204->timer = v19213;
  int * v19207 = v19204->regs;
  int v19208 = v19207[8];
  int v19209 = v19207[20];
  int v19217 = v19208 ^ v19209;
  v19207[8] = v19217;
  struct StateT * v19211 = slot_374(v19204);
  return v19211;
}

struct StateT * slot_94(struct StateT * v6516) {
  int v6517 = v6516->timer;
  int v6525 = v6517 + 1;
  v6516->timer = v6525;
  int * v6519 = v6516->regs;
  int v6520 = v6519[14];
  int v6521 = v6519[7];
  int v6530 = v6520 + v6521;
  v6519[21] = v6530;
  struct StateT * v6523 = slot_95(v6516);
  return v6523;
}

struct StateT * slot_340(struct StateT * v18695) {
  int v18696 = v18695->timer;
  int v18704 = v18696 + 1;
  v18695->timer = v18704;
  int * v18698 = v18695->regs;
  int v18699 = v18698[16];
  int v18700 = v18698[31];
  int v18709 = v18699 + v18700;
  v18698[23] = v18709;
  struct StateT * v18702 = slot_341(v18695);
  return v18702;
}

struct StateT * slot_146(struct StateT * v7354) {
  int v7355 = v7354->timer;
  int v7362 = v7355 + 1;
  v7354->timer = v7362;
  int * v7357 = v7354->regs;
  int v7358 = v7357[23];
  int v7366 = (int)((unsigned int)v7358 >> 23);
  v7357[24] = v7366;
  struct StateT * v7360 = slot_147(v7354);
  return v7360;
}

struct StateT * slot_383(struct StateT * v19365) {
  int v19366 = v19365->timer;
  int v19374 = v19366 + 1;
  v19365->timer = v19374;
  int * v19368 = v19365->regs;
  int v19369 = v19368[20];
  int v19370 = v19368[24];
  int v19378 = v19369 | v19370;
  v19368[20] = v19378;
  struct StateT * v19372 = slot_384(v19365);
  return v19372;
}

struct StateT * slot_24(struct StateT * v5325) {
  int v5326 = v5325->timer;
  int v5332 = v5326 + 1;
  v5325->timer = v5332;
  int * v5328 = v5325->regs;
  v5328[28] = 857759744;
  struct StateT * v5330 = slot_25(v5325);
  return v5330;
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

struct StateT * slot_489(struct StateT * v21155) {
  int v21156 = v21155->timer;
  int v21163 = v21156 + 1;
  v21155->timer = v21163;
  int * v21158 = v21155->regs;
  int v21159 = v21158[22];
  int v21167 = (int)((unsigned int)v21159 >> 25);
  v21158[24] = v21167;
  struct StateT * v21161 = slot_490(v21155);
  return v21161;
}

struct StateT * slot_286(struct StateT * v17850) {
  int v17851 = v17850->timer;
  int v17859 = v17851 + 1;
  v17850->timer = v17859;
  int * v17853 = v17850->regs;
  int v17854 = v17853[21];
  int v17855 = v17853[24];
  int v17863 = v17854 | v17855;
  v17853[21] = v17863;
  struct StateT * v17857 = slot_287(v17850);
  return v17857;
}

struct StateT * slot_520(struct StateT * v21638) {
  int v21639 = v21638->timer;
  int v21647 = v21639 + 1;
  v21638->timer = v21647;
  int * v21641 = v21638->regs;
  int v21642 = v21641[5];
  int v21643 = v21641[12];
  int v21652 = v21642 + v21643;
  v21641[21] = v21652;
  struct StateT * v21645 = slot_521(v21638);
  return v21645;
}

struct StateT * slot_125(struct StateT * v7026) {
  int v7027 = v7026->timer;
  int v7035 = v7027 + 1;
  v7026->timer = v7035;
  int * v7029 = v7026->regs;
  int v7030 = v7029[22];
  int v7031 = v7029[24];
  int v7039 = v7030 | v7031;
  v7029[22] = v7039;
  struct StateT * v7033 = slot_126(v7026);
  return v7033;
}

struct StateT * slot_254(struct StateT * v17375) {
  int v17376 = v17375->timer;
  int v17379 = v17376 + 1;
  v17375->timer = v17379;
  return v17375;
}

struct StateT * slot_148(struct StateT * v7383) {
  int v7384 = v7383->timer;
  int v7392 = v7384 + 1;
  v7383->timer = v7392;
  int * v7386 = v7383->regs;
  int v7387 = v7386[23];
  int v7388 = v7386[24];
  int v7396 = v7387 | v7388;
  v7386[23] = v7396;
  struct StateT * v7390 = slot_149(v7383);
  return v7390;
}

struct StateT * slot_421(struct StateT * v20011) {
  int v20012 = v20011->timer;
  int v20020 = v20012 + 1;
  v20011->timer = v20020;
  int * v20014 = v20011->regs;
  int v20015 = v20014[19];
  int v20016 = v20014[28];
  int v20025 = v20015 + v20016;
  v20014[22] = v20025;
  struct StateT * v20018 = slot_422(v20011);
  return v20018;
}

struct StateT * slot_126(struct StateT * v7042) {
  int v7043 = v7042->timer;
  int v7050 = v7043 + 1;
  v7042->timer = v7050;
  int * v7045 = v7042->regs;
  int v7046 = v7045[23];
  int v7054 = (int)((unsigned int)v7046 >> 25);
  v7045[24] = v7054;
  struct StateT * v7048 = slot_127(v7042);
  return v7048;
}

struct StateT * slot_363(struct StateT * v19053) {
  int v19054 = v19053->timer;
  int v19062 = v19054 + 1;
  v19053->timer = v19062;
  int * v19056 = v19053->regs;
  int v19057 = v19056[20];
  int v19058 = v19056[24];
  int v19066 = v19057 | v19058;
  v19056[20] = v19066;
  struct StateT * v19060 = slot_364(v19053);
  return v19060;
}

struct StateT * slot_79(struct StateT * v6256) {
  int v6257 = v6256->timer;
  int v6265 = v6257 + 1;
  v6256->timer = v6265;
  int * v6259 = v6256->regs;
  int v6260 = v6259[20];
  int v6261 = v6259[24];
  int v6269 = v6260 | v6261;
  v6259[20] = v6269;
  struct StateT * v6263 = slot_80(v6256);
  return v6263;
}

struct StateT * slot_367(struct StateT * v19114) {
  int v19115 = v19114->timer;
  int v19122 = v19115 + 1;
  v19114->timer = v19122;
  int * v19117 = v19114->regs;
  int v19118 = v19117[22];
  int v19126 = (int)((unsigned int)v19118 >> 19);
  v19117[24] = v19126;
  struct StateT * v19120 = slot_368(v19114);
  return v19120;
}

struct StateT * slot_437(struct StateT * v20271) {
  int * v20272 = v20271->saved_regs;
  int * v20273 = v20271->regs;
  int v20274 = v20273[17];
  v20272[17] = v20274;
  int v20276 = v20271->timer;
  int v20288 = v20276 + 1;
  v20271->timer = v20288;
  int * v20278 = v20271->regs;
  int v20279 = v20278[17];
  int v20280 = v20278[22];
  int v20291 = v20279 ^ v20280;
  v20278[17] = v20291;
  struct StateT * v20282 = slot_438(v20271);
  return v20282;
}

struct StateT * slot_341(struct StateT * v18712) {
  int v18713 = v18712->timer;
  int v18720 = v18713 + 1;
  v18712->timer = v18720;
  int * v18715 = v18712->regs;
  int v18716 = v18715[20];
  int v18724 = (int)((unsigned int)v18716 >> 23);
  v18715[24] = v18724;
  struct StateT * v18718 = slot_342(v18712);
  return v18718;
}

struct StateT * slot_142(struct StateT * v7293) {
  int v7294 = v7293->timer;
  int v7302 = v7294 + 1;
  v7293->timer = v7302;
  int * v7296 = v7293->regs;
  int v7297 = v7296[21];
  int v7298 = v7296[24];
  int v7306 = v7297 | v7298;
  v7296[21] = v7306;
  struct StateT * v7300 = slot_143(v7293);
  return v7300;
}

struct StateT * slot_416(struct StateT * v19908) {
  int * v19909 = v19908->saved_regs;
  int * v19910 = v19908->regs;
  int v19911 = v19910[18];
  v19909[18] = v19911;
  int v19913 = v19908->timer;
  int v19925 = v19913 + 1;
  v19908->timer = v19925;
  int * v19915 = v19908->regs;
  int v19916 = v19915[18];
  int v19917 = v19915[21];
  int v19928 = v19916 ^ v19917;
  v19915[18] = v19928;
  struct StateT * v19919 = slot_417(v19908);
  return v19919;
}

struct StateT * slot_280(struct StateT * v17759) {
  int v17760 = v17759->timer;
  int v17768 = v17760 + 1;
  v17759->timer = v17768;
  int * v17762 = v17759->regs;
  int v17763 = v17762[5];
  int v17764 = v17762[8];
  int v17773 = v17763 + v17764;
  v17762[23] = v17773;
  struct StateT * v17766 = slot_281(v17759);
  return v17766;
}

struct StateT * slot_272(struct StateT * v17628) {
  int v17629 = v17628->timer;
  int v17637 = v17629 + 1;
  v17628->timer = v17637;
  int * v17631 = v17628->regs;
  int v17632 = v17631[23];
  int v17633 = v17631[24];
  int v17641 = v17632 | v17633;
  v17631[23] = v17641;
  struct StateT * v17635 = slot_273(v17628);
  return v17635;
}

struct StateT * slot_47(struct StateT * v5697) {
  int v5698 = v5697->timer;
  int v5705 = v5698 + 1;
  v5697->timer = v5705;
  int * v5700 = v5697->regs;
  int v5701 = v5700[23];
  int v5708 = v5701 << 7;
  v5700[23] = v5708;
  struct StateT * v5703 = slot_48(v5697);
  return v5703;
}

struct StateT * slot_214(struct StateT * v12197) {
  int v12198 = v12197->timer;
  int v12368 = v12198 + 1;
  v12197->timer = v12368;
  int * v12200 = v12197->regs;
  int v12201 = v12200[10];
  int v12202 = v12200[18];
  int * v12203 = v12197->cache_tags;
  int v12373 = (((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2;
  int v12204 = v12203[v12373];
  int v12374 = ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12205 = v12203[v12374];
  int v12375 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2);
  int v12206 = v12203[v12375];
  int v12376 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12207 = v12203[v12376];
  int v12208 = v12197->timer;
  int v12377 = v12208 + ((100 ^ (((~(((v12206 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12206 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12204 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12204 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12205 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12205 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12206 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12206 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12197->timer = v12377;
  bool v12378 = !(((~(((v12204 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12204 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12205 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12205 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v12302;
  if (v12378) {
    int * v12210 = v12197->cache_age;
    int v12380 = ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v12205 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12205 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v12211 = v12210[v12380];
    int v12212 = v12210[v12373];
    int v12381 = v12212 + ((int)((unsigned int)(v12212 - v12211) >> 31));
    v12210[v12373] = v12381;
    int * v12214 = v12197->cache_age;
    int v12215 = v12214[v12374];
    int v12383 = v12215 + ((int)((unsigned int)(v12215 - v12211) >> 31));
    v12214[v12374] = v12383;
    int * v12217 = v12197->cache_age;
    v12217[v12380] = 0;
    v12302 = v12380;
  } else {
    int * v12220 = v12197->cache_age;
    int v12387 = (((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2;
    int v12221 = v12220[v12387];
    int * v12222 = v12197->cache_tags;
    int v12223 = v12222[v12387];
    int v12224 = v12220[v12374];
    int v12225 = v12222[v12374];
    bool v12389 = !(((~(((v12206 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12206 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v12279;
    if (v12389) {
      int * v12226 = v12197->cache_age;
      int v12391 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12207 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v12227 = v12226[v12391];
      int v12228 = v12226[v12375];
      int v12392 = v12228 + ((int)((unsigned int)(v12228 - v12227) >> 31));
      v12226[v12375] = v12392;
      int * v12230 = v12197->cache_age;
      int v12231 = v12230[v12376];
      int v12394 = v12231 + ((int)((unsigned int)(v12231 - v12227) >> 31));
      v12230[v12376] = v12394;
      int * v12233 = v12197->cache_age;
      v12233[v12391] = 0;
      v12279 = v12391;
    } else {
      int * v12236 = v12197->cache_age;
      int v12398 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2);
      int v12237 = v12236[v12398];
      int * v12238 = v12197->cache_tags;
      int v12239 = v12238[v12398];
      int v12240 = v12236[v12376];
      int v12241 = v12238[v12376];
      int * v12242 = v12197->cache_dirty;
      int v12401 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12237 + ((~(((v12239 ^ -1) | (-(v12239 ^ -1))) >> 31)) & 2)) - (v12240 + ((~(((v12241 ^ -1) | (-(v12241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12243 = v12242[v12401];
      bool v12402 = !(v12243 == 0);
      if (v12402) {
        int * v12244 = v12197->cache_tags;
        int v12245 = v12244[v12401];
        int * v12246 = v12197->cache_vals;
        int v12405 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12237 + ((~(((v12239 ^ -1) | (-(v12239 ^ -1))) >> 31)) & 2)) - (v12240 + ((~(((v12241 ^ -1) | (-(v12241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12247 = v12246[v12405];
        int v12406 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12237 + ((~(((v12239 ^ -1) | (-(v12239 ^ -1))) >> 31)) & 2)) - (v12240 + ((~(((v12241 ^ -1) | (-(v12241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12248 = v12246[v12406];
        int * v12249 = v12197->mem;
        int v12408 = v12245 * 2;
        v12249[v12408] = v12247;
        int * v12251 = v12197->mem;
        int v12411 = (v12245 * 2) + 1;
        v12251[v12411] = v12248;
        ;
      } else {
        ;
      }
      int * v12256 = v12197->mem;
      int v12416 = ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) * 2;
      int v12257 = v12256[v12416];
      int v12417 = (((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) * 2) + 1;
      int v12258 = v12256[v12417];
      int * v12259 = v12197->cache_vals;
      int v12419 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12237 + ((~(((v12239 ^ -1) | (-(v12239 ^ -1))) >> 31)) & 2)) - (v12240 + ((~(((v12241 ^ -1) | (-(v12241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12259[v12419] = v12257;
      int * v12261 = v12197->cache_vals;
      int v12422 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12237 + ((~(((v12239 ^ -1) | (-(v12239 ^ -1))) >> 31)) & 2)) - (v12240 + ((~(((v12241 ^ -1) | (-(v12241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12261[v12422] = v12258;
      int * v12263 = v12197->cache_tags;
      int v12425 = (int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1);
      v12263[v12401] = v12425;
      int * v12265 = v12197->cache_dirty;
      v12265[v12401] = 0;
      int * v12267 = v12197->cache_age;
      v12267[v12401] = 1;
      int * v12269 = v12197->cache_age;
      int v12270 = v12269[v12401];
      int v12271 = v12269[v12375];
      int v12431 = v12271 + ((int)((unsigned int)(v12271 - v12270) >> 31));
      v12269[v12375] = v12431;
      int * v12273 = v12197->cache_age;
      int v12274 = v12273[v12376];
      int v12433 = v12274 + ((int)((unsigned int)(v12274 - v12270) >> 31));
      v12273[v12376] = v12433;
      int * v12276 = v12197->cache_age;
      v12276[v12401] = 0;
      v12279 = v12401;
    }
    int * v12280 = v12197->cache_vals;
    int v12436 = v12279 * 2;
    int v12281 = v12280[v12436];
    int v12437 = (v12279 * 2) + 1;
    int v12282 = v12280[v12437];
    int v12438 = (((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12221 + ((~(((v12223 ^ -1) | (-(v12223 ^ -1))) >> 31)) & 2)) - (v12224 + ((~(((v12225 ^ -1) | (-(v12225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12280[v12438] = v12281;
    int * v12284 = v12197->cache_vals;
    int v12441 = ((((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12221 + ((~(((v12223 ^ -1) | (-(v12223 ^ -1))) >> 31)) & 2)) - (v12224 + ((~(((v12225 ^ -1) | (-(v12225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12284[v12441] = v12282;
    int * v12286 = v12197->cache_tags;
    int v12444 = ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v12221 + ((~(((v12223 ^ -1) | (-(v12223 ^ -1))) >> 31)) & 2)) - (v12224 + ((~(((v12225 ^ -1) | (-(v12225 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12445 = (int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1);
    v12286[v12444] = v12445;
    int * v12288 = v12197->cache_dirty;
    v12288[v12444] = 0;
    int * v12290 = v12197->cache_age;
    v12290[v12444] = 1;
    int * v12292 = v12197->cache_age;
    int v12293 = v12292[v12444];
    int v12294 = v12292[v12373];
    int v12451 = v12294 + ((int)((unsigned int)(v12294 - v12293) >> 31));
    v12292[v12373] = v12451;
    int * v12296 = v12197->cache_age;
    int v12297 = v12296[v12374];
    int v12453 = v12297 + ((int)((unsigned int)(v12297 - v12293) >> 31));
    v12296[v12374] = v12453;
    int * v12299 = v12197->cache_age;
    v12299[v12444] = 0;
    v12302 = v12444;
  }
  int * v12303 = v12197->cache_vals;
  int v12456 = (v12302 * 2) + (((int)((unsigned int)(v12201 + 28) >> 2)) & 1);
  v12303[v12456] = v12202;
  int * v12305 = v12197->cache_tags;
  int v12306 = v12305[v12375];
  int v12307 = v12305[v12376];
  bool v12459 = !(((~(((v12306 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12306 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v12307 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12307 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v12361;
  if (v12459) {
    int * v12308 = v12197->cache_age;
    int v12461 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12307 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))) | (-(v12307 ^ ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v12309 = v12308[v12461];
    int v12310 = v12308[v12375];
    int v12462 = v12310 + ((int)((unsigned int)(v12310 - v12309) >> 31));
    v12308[v12375] = v12462;
    int * v12312 = v12197->cache_age;
    int v12313 = v12312[v12376];
    int v12464 = v12313 + ((int)((unsigned int)(v12313 - v12309) >> 31));
    v12312[v12376] = v12464;
    int * v12315 = v12197->cache_age;
    v12315[v12461] = 0;
    v12361 = v12461;
  } else {
    int * v12318 = v12197->cache_age;
    int v12468 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2);
    int v12319 = v12318[v12468];
    int * v12320 = v12197->cache_tags;
    int v12321 = v12320[v12468];
    int v12322 = v12318[v12376];
    int v12323 = v12320[v12376];
    int * v12324 = v12197->cache_dirty;
    int v12471 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12319 + ((~(((v12321 ^ -1) | (-(v12321 ^ -1))) >> 31)) & 2)) - (v12322 + ((~(((v12323 ^ -1) | (-(v12323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12325 = v12324[v12471];
    bool v12472 = !(v12325 == 0);
    if (v12472) {
      int * v12326 = v12197->cache_tags;
      int v12327 = v12326[v12471];
      int * v12328 = v12197->cache_vals;
      int v12475 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12319 + ((~(((v12321 ^ -1) | (-(v12321 ^ -1))) >> 31)) & 2)) - (v12322 + ((~(((v12323 ^ -1) | (-(v12323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12329 = v12328[v12475];
      int v12476 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12319 + ((~(((v12321 ^ -1) | (-(v12321 ^ -1))) >> 31)) & 2)) - (v12322 + ((~(((v12323 ^ -1) | (-(v12323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12330 = v12328[v12476];
      int * v12331 = v12197->mem;
      int v12478 = v12327 * 2;
      v12331[v12478] = v12329;
      int * v12333 = v12197->mem;
      int v12481 = (v12327 * 2) + 1;
      v12333[v12481] = v12330;
      ;
    } else {
      ;
    }
    int * v12338 = v12197->mem;
    int v12486 = ((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) * 2;
    int v12339 = v12338[v12486];
    int v12487 = (((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) * 2) + 1;
    int v12340 = v12338[v12487];
    int * v12341 = v12197->cache_vals;
    int v12489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12319 + ((~(((v12321 ^ -1) | (-(v12321 ^ -1))) >> 31)) & 2)) - (v12322 + ((~(((v12323 ^ -1) | (-(v12323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12341[v12489] = v12339;
    int * v12343 = v12197->cache_vals;
    int v12492 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v12319 + ((~(((v12321 ^ -1) | (-(v12321 ^ -1))) >> 31)) & 2)) - (v12322 + ((~(((v12323 ^ -1) | (-(v12323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12343[v12492] = v12340;
    int * v12345 = v12197->cache_tags;
    int v12495 = (int)((unsigned int)((int)((unsigned int)(v12201 + 28) >> 2)) >> 1);
    v12345[v12471] = v12495;
    int * v12347 = v12197->cache_dirty;
    v12347[v12471] = 0;
    int * v12349 = v12197->cache_age;
    v12349[v12471] = 1;
    int * v12351 = v12197->cache_age;
    int v12352 = v12351[v12471];
    int v12353 = v12351[v12375];
    int v12501 = v12353 + ((int)((unsigned int)(v12353 - v12352) >> 31));
    v12351[v12375] = v12501;
    int * v12355 = v12197->cache_age;
    int v12356 = v12355[v12376];
    int v12503 = v12356 + ((int)((unsigned int)(v12356 - v12352) >> 31));
    v12355[v12376] = v12503;
    int * v12358 = v12197->cache_age;
    v12358[v12471] = 0;
    v12361 = v12471;
  }
  int * v12362 = v12197->cache_vals;
  int v12506 = (v12361 * 2) + (((int)((unsigned int)(v12201 + 28) >> 2)) & 1);
  v12362[v12506] = v12202;
  int * v12364 = v12197->cache_dirty;
  v12364[v12361] = 1;
  struct StateT * v12366 = slot_225(v12197);
  return v12366;
}

struct StateT * slot_297(struct StateT * v18020) {
  int v18021 = v18020->timer;
  int v18029 = v18021 + 1;
  v18020->timer = v18029;
  int * v18023 = v18020->regs;
  int v18024 = v18023[16];
  int v18025 = v18023[6];
  int v18034 = v18024 + v18025;
  v18023[20] = v18034;
  struct StateT * v18027 = slot_298(v18020);
  return v18027;
}

struct StateT * slot_29(struct StateT * v5396) {
  int v5397 = v5396->timer;
  int v5403 = v5397 + 1;
  v5396->timer = v5403;
  int * v5399 = v5396->regs;
  v5399[31] = 1797283840;
  struct StateT * v5401 = slot_30(v5396);
  return v5401;
}

struct StateT * slot_314(struct StateT * v18284) {
  int v18285 = v18284->timer;
  int v18293 = v18285 + 1;
  v18284->timer = v18293;
  int * v18287 = v18284->regs;
  int v18288 = v18287[29];
  int v18289 = v18287[21];
  int v18297 = v18288 ^ v18289;
  v18287[29] = v18297;
  struct StateT * v18291 = slot_315(v18284);
  return v18291;
}

struct StateT * slot_151(struct StateT * v7431) {
  int v7432 = v7431->timer;
  int v7440 = v7432 + 1;
  v7431->timer = v7440;
  int * v7434 = v7431->regs;
  int v7435 = v7434[6];
  int v7436 = v7434[22];
  int v7444 = v7435 ^ v7436;
  v7434[6] = v7444;
  struct StateT * v7438 = slot_152(v7431);
  return v7438;
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

struct StateT * slot_124(struct StateT * v7012) {
  int v7013 = v7012->timer;
  int v7020 = v7013 + 1;
  v7012->timer = v7020;
  int * v7015 = v7012->regs;
  int v7016 = v7015[22];
  int v7023 = v7016 << 7;
  v7015[22] = v7023;
  struct StateT * v7018 = slot_125(v7012);
  return v7018;
}

struct StateT * slot_128(struct StateT * v7071) {
  int v7072 = v7071->timer;
  int v7080 = v7072 + 1;
  v7071->timer = v7080;
  int * v7074 = v7071->regs;
  int v7075 = v7074[23];
  int v7076 = v7074[24];
  int v7084 = v7075 | v7076;
  v7074[23] = v7084;
  struct StateT * v7078 = slot_129(v7071);
  return v7078;
}

struct StateT * slot_365(struct StateT * v19084) {
  int v19085 = v19084->timer;
  int v19092 = v19085 + 1;
  v19084->timer = v19092;
  int * v19087 = v19084->regs;
  int v19088 = v19087[21];
  int v19095 = v19088 << 13;
  v19087[21] = v19095;
  struct StateT * v19090 = slot_366(v19084);
  return v19090;
}

struct StateT * slot_441(struct StateT * v20351) {
  int v20352 = v20351->timer;
  int v20360 = v20352 + 1;
  v20351->timer = v20360;
  int * v20354 = v20351->regs;
  int v20355 = v20354[17];
  int v20356 = v20354[19];
  int v20365 = v20355 + v20356;
  v20354[22] = v20365;
  struct StateT * v20358 = slot_442(v20351);
  return v20358;
}

struct StateT * slot_19(struct StateT * v4496) {
  int v4497 = v4496->timer;
  int v4607 = v4497 + 1;
  v4496->timer = v4607;
  int * v4499 = v4496->regs;
  int v4500 = v4499[11];
  int * v4501 = v4496->cache_tags;
  int v4611 = (((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2;
  int v4502 = v4501[v4611];
  int v4612 = ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4503 = v4501[v4612];
  int v4613 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2);
  int v4504 = v4501[v4613];
  int v4614 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4505 = v4501[v4614];
  int v4506 = v4496->timer;
  int v4615 = v4506 + ((100 ^ (((~(((v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4496->timer = v4615;
  int * v4508 = v4496->cache_vals;
  bool v4616 = !(((~(((v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) == 0);
  int v4601;
  if (v4616) {
    int * v4509 = v4496->cache_age;
    int v4618 = ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((~(((v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) & 1);
    int v4510 = v4509[v4618];
    int v4511 = v4509[v4611];
    int v4619 = v4511 + ((int)((unsigned int)(v4511 - v4510) >> 31));
    v4509[v4611] = v4619;
    int * v4513 = v4496->cache_age;
    int v4514 = v4513[v4612];
    int v4621 = v4514 + ((int)((unsigned int)(v4514 - v4510) >> 31));
    v4513[v4612] = v4621;
    int * v4516 = v4496->cache_age;
    v4516[v4618] = 0;
    v4601 = v4618;
  } else {
    int * v4519 = v4496->cache_age;
    int v4625 = (((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2;
    int v4520 = v4519[v4625];
    int * v4521 = v4496->cache_tags;
    int v4522 = v4521[v4625];
    int v4523 = v4519[v4612];
    int v4524 = v4521[v4612];
    bool v4627 = !(((~(((v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) == 0);
    int v4578;
    if (v4627) {
      int * v4525 = v4496->cache_age;
      int v4629 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) & 1);
      int v4526 = v4525[v4629];
      int v4527 = v4525[v4613];
      int v4630 = v4527 + ((int)((unsigned int)(v4527 - v4526) >> 31));
      v4525[v4613] = v4630;
      int * v4529 = v4496->cache_age;
      int v4530 = v4529[v4614];
      int v4632 = v4530 + ((int)((unsigned int)(v4530 - v4526) >> 31));
      v4529[v4614] = v4632;
      int * v4532 = v4496->cache_age;
      v4532[v4629] = 0;
      v4578 = v4629;
    } else {
      int * v4535 = v4496->cache_age;
      int v4636 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2);
      int v4536 = v4535[v4636];
      int * v4537 = v4496->cache_tags;
      int v4538 = v4537[v4636];
      int v4539 = v4535[v4614];
      int v4540 = v4537[v4614];
      int * v4541 = v4496->cache_dirty;
      int v4639 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4542 = v4541[v4639];
      bool v4640 = !(v4542 == 0);
      if (v4640) {
        int * v4543 = v4496->cache_tags;
        int v4544 = v4543[v4639];
        int * v4545 = v4496->cache_vals;
        int v4643 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4546 = v4545[v4643];
        int v4644 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4547 = v4545[v4644];
        int * v4548 = v4496->mem;
        int v4646 = v4544 * 2;
        v4548[v4646] = v4546;
        int * v4550 = v4496->mem;
        int v4649 = (v4544 * 2) + 1;
        v4550[v4649] = v4547;
        ;
      } else {
        ;
      }
      int * v4555 = v4496->mem;
      int v4654 = ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) * 2;
      int v4556 = v4555[v4654];
      int v4655 = (((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) * 2) + 1;
      int v4557 = v4555[v4655];
      int * v4558 = v4496->cache_vals;
      int v4657 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4558[v4657] = v4556;
      int * v4560 = v4496->cache_vals;
      int v4660 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4560[v4660] = v4557;
      int * v4562 = v4496->cache_tags;
      int v4663 = (int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1);
      v4562[v4639] = v4663;
      int * v4564 = v4496->cache_dirty;
      v4564[v4639] = 0;
      int * v4566 = v4496->cache_age;
      v4566[v4639] = 1;
      int * v4568 = v4496->cache_age;
      int v4569 = v4568[v4639];
      int v4570 = v4568[v4613];
      int v4669 = v4570 + ((int)((unsigned int)(v4570 - v4569) >> 31));
      v4568[v4613] = v4669;
      int * v4572 = v4496->cache_age;
      int v4573 = v4572[v4614];
      int v4671 = v4573 + ((int)((unsigned int)(v4573 - v4569) >> 31));
      v4572[v4614] = v4671;
      int * v4575 = v4496->cache_age;
      v4575[v4639] = 0;
      v4578 = v4639;
    }
    int * v4579 = v4496->cache_vals;
    int v4674 = v4578 * 2;
    int v4580 = v4579[v4674];
    int v4675 = (v4578 * 2) + 1;
    int v4581 = v4579[v4675];
    int v4676 = (((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((((v4520 + ((~(((v4522 ^ -1) | (-(v4522 ^ -1))) >> 31)) & 2)) - (v4523 + ((~(((v4524 ^ -1) | (-(v4524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4579[v4676] = v4580;
    int * v4583 = v4496->cache_vals;
    int v4679 = ((((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((((v4520 + ((~(((v4522 ^ -1) | (-(v4522 ^ -1))) >> 31)) & 2)) - (v4523 + ((~(((v4524 ^ -1) | (-(v4524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4583[v4679] = v4581;
    int * v4585 = v4496->cache_tags;
    int v4682 = ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((((v4520 + ((~(((v4522 ^ -1) | (-(v4522 ^ -1))) >> 31)) & 2)) - (v4523 + ((~(((v4524 ^ -1) | (-(v4524 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4683 = (int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1);
    v4585[v4682] = v4683;
    int * v4587 = v4496->cache_dirty;
    v4587[v4682] = 0;
    int * v4589 = v4496->cache_age;
    v4589[v4682] = 1;
    int * v4591 = v4496->cache_age;
    int v4592 = v4591[v4682];
    int v4593 = v4591[v4611];
    int v4689 = v4593 + ((int)((unsigned int)(v4593 - v4592) >> 31));
    v4591[v4611] = v4689;
    int * v4595 = v4496->cache_age;
    int v4596 = v4595[v4612];
    int v4691 = v4596 + ((int)((unsigned int)(v4596 - v4592) >> 31));
    v4595[v4612] = v4691;
    int * v4598 = v4496->cache_age;
    v4598[v4682] = 0;
    v4601 = v4682;
  }
  int v4694 = (v4601 * 2) + (((int)((unsigned int)v4500 >> 2)) & 1);
  int v4602 = v4508[v4694];
  int * v4603 = v4496->regs;
  v4603[12] = v4602;
  struct StateT * v4605 = slot_20(v4496);
  return v4605;
}

struct StateT * slot_382(struct StateT * v19351) {
  int v19352 = v19351->timer;
  int v19359 = v19352 + 1;
  v19351->timer = v19359;
  int * v19354 = v19351->regs;
  int v19355 = v19354[20];
  int v19362 = v19355 << 18;
  v19354[20] = v19362;
  struct StateT * v19357 = slot_383(v19351);
  return v19357;
}

struct StateT * slot_523(struct StateT * v21689) {
  int v21690 = v21689->timer;
  int v21697 = v21690 + 1;
  v21689->timer = v21697;
  int * v21692 = v21689->regs;
  int v21693 = v21692[20];
  int v21701 = (int)((unsigned int)v21693 >> 19);
  v21692[24] = v21701;
  struct StateT * v21695 = slot_524(v21689);
  return v21695;
}

struct StateT * slot_87(struct StateT * v6377) {
  int v6378 = v6377->timer;
  int v6385 = v6378 + 1;
  v6377->timer = v6385;
  int * v6380 = v6377->regs;
  int v6381 = v6380[23];
  int v6388 = v6381 << 13;
  v6380[23] = v6388;
  struct StateT * v6383 = slot_88(v6377);
  return v6383;
}

struct StateT * slot_452(struct StateT * v20520) {
  int v20521 = v20520->timer;
  int v20528 = v20521 + 1;
  v20520->timer = v20528;
  int * v20523 = v20520->regs;
  int v20524 = v20523[23];
  int v20532 = (int)((unsigned int)v20524 >> 19);
  v20523[24] = v20532;
  struct StateT * v20526 = slot_453(v20520);
  return v20526;
}

struct StateT * slot_67(struct StateT * v6037) {
  int v6038 = v6037->timer;
  int v6045 = v6038 + 1;
  v6037->timer = v6045;
  int * v6040 = v6037->regs;
  int v6041 = v6040[23];
  int v6048 = v6041 << 9;
  v6040[23] = v6048;
  struct StateT * v6043 = slot_68(v6037);
  return v6043;
}

struct StateT * slot_81(struct StateT * v6287) {
  int v6288 = v6287->timer;
  int v6295 = v6288 + 1;
  v6287->timer = v6295;
  int * v6290 = v6287->regs;
  int v6291 = v6290[21];
  int v6298 = v6291 << 13;
  v6290[21] = v6298;
  struct StateT * v6293 = slot_82(v6287);
  return v6293;
}

struct StateT * slot_546(struct StateT * v22046) {
  int v22047 = v22046->timer;
  int v22054 = v22047 + 1;
  v22046->timer = v22054;
  int * v22049 = v22046->regs;
  int v22050 = v22049[21];
  int v22058 = (int)((unsigned int)v22050 >> 14);
  v22049[24] = v22058;
  struct StateT * v22052 = slot_547(v22046);
  return v22052;
}

struct StateT * slot_556(struct StateT * v22197) {
  int v22198 = v22197->timer;
  int v22206 = v22198 + 1;
  v22197->timer = v22206;
  int * v22200 = v22197->regs;
  int v22201 = v22200[29];
  int v22202 = v22200[21];
  int v22210 = v22201 ^ v22202;
  v22200[29] = v22210;
  struct StateT * v22204 = slot_557(v22197);
  return v22204;
}

struct StateT * slot_337(struct StateT * v18644) {
  int v18645 = v18644->timer;
  int v18653 = v18645 + 1;
  v18644->timer = v18653;
  int * v18647 = v18644->regs;
  int v18648 = v18647[14];
  int v18649 = v18647[30];
  int v18658 = v18648 + v18649;
  v18647[20] = v18658;
  struct StateT * v18651 = slot_338(v18644);
  return v18651;
}

struct StateT * slot_32(struct StateT * v5436) {
  int v5437 = v5436->timer;
  int v5441 = v5437 + 1;
  v5436->timer = v5441;
  struct StateT * v5439 = slot_33(v5436);
  return v5439;
}

struct StateT * slot_233(struct StateT * v15383) {
  int v15384 = v15383->timer;
  int v15391 = v15384 + 1;
  v15383->timer = v15391;
  int * v15386 = v15383->regs;
  int v15387 = v15386[22];
  int v15394 = v15387 << 7;
  v15386[22] = v15394;
  struct StateT * v15389 = slot_236(v15383);
  return v15389;
}

struct StateT * slot_176(struct StateT * v7826) {
  int v7827 = v7826->timer;
  int v7835 = v7827 + 1;
  v7826->timer = v7835;
  int * v7829 = v7826->regs;
  int v7830 = v7829[19];
  int v7831 = v7829[7];
  int v7840 = v7830 + v7831;
  v7829[23] = v7840;
  struct StateT * v7833 = slot_177(v7826);
  return v7833;
}

struct StateT * slot_189(struct StateT * v8023) {
  int v8024 = v8023->timer;
  int v8032 = v8024 + 1;
  v8023->timer = v8032;
  int * v8026 = v8023->regs;
  int v8027 = v8026[30];
  int v8028 = v8026[20];
  int v8036 = v8027 ^ v8028;
  v8026[30] = v8036;
  struct StateT * v8030 = slot_190(v8023);
  return v8030;
}

struct StateT * slot_394(struct StateT * v19532) {
  int v19533 = v19532->timer;
  int v19541 = v19533 + 1;
  v19532->timer = v19541;
  int * v19535 = v19532->regs;
  int v19536 = v19535[29];
  int v19537 = v19535[21];
  int v19545 = v19536 ^ v19537;
  v19535[29] = v19545;
  struct StateT * v19539 = slot_395(v19532);
  return v19539;
}

struct StateT * slot_398(struct StateT * v19594) {
  int v19595 = v19594->timer;
  int v19599 = v19595 + 1;
  v19594->timer = v19599;
  struct StateT * v19597 = slot_399(v19594);
  return v19597;
}

struct StateT * slot_33(struct StateT * v5444) {
  int * v5445 = v5444->saved_regs;
  int * v5446 = v5444->regs;
  int v5447 = v5446[20];
  v5445[20] = v5447;
  int v5449 = v5444->timer;
  int v5461 = v5449 + 1;
  v5444->timer = v5461;
  int * v5451 = v5444->regs;
  int v5452 = v5451[30];
  int v5453 = v5451[16];
  int v5465 = v5452 + v5453;
  v5451[20] = v5465;
  struct StateT * v5455 = slot_34(v5444);
  return v5455;
}

struct StateT * slot_371(struct StateT * v19174) {
  int v19175 = v19174->timer;
  int v19182 = v19175 + 1;
  v19174->timer = v19182;
  int * v19177 = v19174->regs;
  int v19178 = v19177[23];
  int v19185 = v19178 << 13;
  v19177[23] = v19185;
  struct StateT * v19180 = slot_372(v19174);
  return v19180;
}

struct StateT * slot_330(struct StateT * v18535) {
  int v18536 = v18535->timer;
  int v18543 = v18536 + 1;
  v18535->timer = v18543;
  int * v18538 = v18535->regs;
  int v18539 = v18538[23];
  int v18547 = (int)((unsigned int)v18539 >> 25);
  v18538[24] = v18547;
  struct StateT * v18541 = slot_331(v18535);
  return v18541;
}

struct StateT * slot_450(struct StateT * v20490) {
  int v20491 = v20490->timer;
  int v20498 = v20491 + 1;
  v20490->timer = v20498;
  int * v20493 = v20490->regs;
  int v20494 = v20493[22];
  int v20501 = v20494 << 13;
  v20493[22] = v20501;
  struct StateT * v20496 = slot_451(v20490);
  return v20496;
}

struct StateT * slot_35(struct StateT * v5492) {
  int * v5493 = v5492->saved_regs;
  int * v5494 = v5492->regs;
  int v5495 = v5494[22];
  v5493[22] = v5495;
  int v5497 = v5492->timer;
  int v5509 = v5497 + 1;
  v5492->timer = v5509;
  int * v5499 = v5492->regs;
  int v5500 = v5499[28];
  int v5501 = v5499[12];
  int v5513 = v5500 + v5501;
  v5499[22] = v5513;
  struct StateT * v5503 = slot_36(v5492);
  return v5503;
}

struct StateT * slot_484(struct StateT * v21080) {
  int v21081 = v21080->timer;
  int v21088 = v21081 + 1;
  v21080->timer = v21088;
  int * v21083 = v21080->regs;
  int v21084 = v21083[20];
  int v21091 = v21084 << 7;
  v21083[20] = v21091;
  struct StateT * v21086 = slot_485(v21080);
  return v21086;
}

struct StateT * slot_258(struct StateT * v17413) {
  int v17414 = v17413->timer;
  int v17422 = v17414 + 1;
  v17413->timer = v17422;
  int * v17416 = v17413->regs;
  int v17417 = v17416[18];
  int v17418 = v17416[29];
  int v17427 = v17417 + v17418;
  v17416[21] = v17427;
  struct StateT * v17420 = slot_259(v17413);
  return v17420;
}

struct StateT * slot_166(struct StateT * v7666) {
  int v7667 = v7666->timer;
  int v7674 = v7667 + 1;
  v7666->timer = v7674;
  int * v7669 = v7666->regs;
  int v7670 = v7669[23];
  int v7678 = (int)((unsigned int)v7670 >> 19);
  v7669[24] = v7678;
  struct StateT * v7672 = slot_167(v7666);
  return v7672;
}

struct StateT * slot_418(struct StateT * v19954) {
  int * v19955 = v19954->saved_regs;
  int * v19956 = v19954->regs;
  int v19957 = v19956[8];
  v19955[8] = v19957;
  int v19959 = v19954->timer;
  int v19971 = v19959 + 1;
  v19954->timer = v19971;
  int * v19961 = v19954->regs;
  int v19962 = v19961[8];
  int v19963 = v19961[23];
  int v19974 = v19962 ^ v19963;
  v19961[8] = v19974;
  struct StateT * v19965 = slot_419(v19954);
  return v19965;
}

struct StateT * slot_51(struct StateT * v5773) {
  int * v5774 = v5773->saved_regs;
  int * v5775 = v5773->regs;
  int v5776 = v5775[19];
  v5774[19] = v5776;
  int v5778 = v5773->timer;
  int v5790 = v5778 + 1;
  v5773->timer = v5790;
  int * v5780 = v5773->regs;
  int v5781 = v5780[19];
  int v5782 = v5780[22];
  int v5793 = v5781 ^ v5782;
  v5780[19] = v5793;
  struct StateT * v5784 = slot_52(v5773);
  return v5784;
}

struct StateT * slot_25(struct StateT * v5338) {
  int v5339 = v5338->timer;
  int v5345 = v5339 + 1;
  v5338->timer = v5345;
  int * v5341 = v5338->regs;
  v5341[31] = 2036477952;
  struct StateT * v5343 = slot_26(v5338);
  return v5343;
}

struct StateT * slot_490(struct StateT * v21170) {
  int v21171 = v21170->timer;
  int v21178 = v21171 + 1;
  v21170->timer = v21178;
  int * v21173 = v21170->regs;
  int v21174 = v21173[22];
  int v21181 = v21174 << 7;
  v21173[22] = v21181;
  struct StateT * v21176 = slot_491(v21170);
  return v21176;
}

struct StateT * slot_264(struct StateT * v17509) {
  int v17510 = v17509->timer;
  int v17517 = v17510 + 1;
  v17509->timer = v17517;
  int * v17512 = v17509->regs;
  int v17513 = v17512[21];
  int v17521 = (int)((unsigned int)v17513 >> 23);
  v17512[24] = v17521;
  struct StateT * v17515 = slot_265(v17509);
  return v17515;
}

struct StateT * slot_339(struct StateT * v18678) {
  int v18679 = v18678->timer;
  int v18687 = v18679 + 1;
  v18678->timer = v18687;
  int * v18681 = v18678->regs;
  int v18682 = v18681[15];
  int v18683 = v18681[28];
  int v18692 = v18682 + v18683;
  v18681[22] = v18692;
  struct StateT * v18685 = slot_340(v18678);
  return v18685;
}

struct StateT * slot_123(struct StateT * v6997) {
  int v6998 = v6997->timer;
  int v7005 = v6998 + 1;
  v6997->timer = v7005;
  int * v7000 = v6997->regs;
  int v7001 = v7000[22];
  int v7009 = (int)((unsigned int)v7001 >> 25);
  v7000[24] = v7009;
  struct StateT * v7003 = slot_124(v6997);
  return v7003;
}

struct StateT * slot_97(struct StateT * v6567) {
  int v6568 = v6567->timer;
  int v6575 = v6568 + 1;
  v6567->timer = v6575;
  int * v6570 = v6567->regs;
  int v6571 = v6570[20];
  int v6579 = (int)((unsigned int)v6571 >> 14);
  v6570[24] = v6579;
  struct StateT * v6573 = slot_98(v6567);
  return v6573;
}

struct StateT * slot_106(struct StateT * v6702) {
  int v6703 = v6702->timer;
  int v6710 = v6703 + 1;
  v6702->timer = v6710;
  int * v6705 = v6702->regs;
  int v6706 = v6705[23];
  int v6714 = (int)((unsigned int)v6706 >> 14);
  v6705[24] = v6714;
  struct StateT * v6708 = slot_107(v6702);
  return v6708;
}

struct StateT * slot_299(struct StateT * v18054) {
  int v18055 = v18054->timer;
  int v18063 = v18055 + 1;
  v18054->timer = v18063;
  int * v18057 = v18054->regs;
  int v18058 = v18057[12];
  int v18059 = v18057[17];
  int v18068 = v18058 + v18059;
  v18057[22] = v18068;
  struct StateT * v18061 = slot_300(v18054);
  return v18061;
}

struct StateT * slot_539(struct StateT * v21933) {
  int v21934 = v21933->timer;
  int v21942 = v21934 + 1;
  v21933->timer = v21942;
  int * v21936 = v21933->regs;
  int v21937 = v21936[8];
  int v21938 = v21936[17];
  int v21947 = v21937 + v21938;
  v21936[20] = v21947;
  struct StateT * v21940 = slot_540(v21933);
  return v21940;
}

struct StateT * slot_319(struct StateT * v18366) {
  int v18367 = v18366->timer;
  int v18375 = v18367 + 1;
  v18366->timer = v18375;
  int * v18369 = v18366->regs;
  int v18370 = v18369[28];
  int v18371 = v18369[18];
  int v18380 = v18370 + v18371;
  v18369[22] = v18380;
  struct StateT * v18373 = slot_320(v18366);
  return v18373;
}

struct StateT * slot_344(struct StateT * v18757) {
  int v18758 = v18757->timer;
  int v18765 = v18758 + 1;
  v18757->timer = v18765;
  int * v18760 = v18757->regs;
  int v18761 = v18760[21];
  int v18769 = (int)((unsigned int)v18761 >> 23);
  v18760[24] = v18769;
  struct StateT * v18763 = slot_345(v18757);
  return v18763;
}

struct StateT * slot_513(struct StateT * v21527) {
  int v21528 = v21527->timer;
  int v21535 = v21528 + 1;
  v21527->timer = v21535;
  int * v21530 = v21527->regs;
  int v21531 = v21530[23];
  int v21538 = v21531 << 9;
  v21530[23] = v21538;
  struct StateT * v21533 = slot_514(v21527);
  return v21533;
}

struct StateT * slot_130(struct StateT * v7103) {
  int v7104 = v7103->timer;
  int v7112 = v7104 + 1;
  v7103->timer = v7112;
  int * v7106 = v7103->regs;
  int v7107 = v7106[12];
  int v7108 = v7106[21];
  int v7116 = v7107 ^ v7108;
  v7106[12] = v7116;
  struct StateT * v7110 = slot_131(v7103);
  return v7110;
}

struct StateT * slot_497(struct StateT * v21277) {
  int v21278 = v21277->timer;
  int v21286 = v21278 + 1;
  v21277->timer = v21286;
  int * v21280 = v21277->regs;
  int v21281 = v21280[15];
  int v21282 = v21280[22];
  int v21290 = v21281 ^ v21282;
  v21280[15] = v21290;
  struct StateT * v21284 = slot_498(v21277);
  return v21284;
}

struct StateT * slot_455(struct StateT * v20565) {
  int * v20566 = v20565->saved_regs;
  int * v20567 = v20565->regs;
  int v20568 = v20567[16];
  v20566[16] = v20568;
  int v20570 = v20565->timer;
  int v20582 = v20570 + 1;
  v20565->timer = v20582;
  int * v20572 = v20565->regs;
  int v20573 = v20572[16];
  int v20574 = v20572[20];
  int v20585 = v20573 ^ v20574;
  v20572[16] = v20585;
  struct StateT * v20576 = slot_456(v20565);
  return v20576;
}

struct StateT * slot_141(struct StateT * v7279) {
  int v7280 = v7279->timer;
  int v7287 = v7280 + 1;
  v7279->timer = v7287;
  int * v7282 = v7279->regs;
  int v7283 = v7282[21];
  int v7290 = v7283 << 9;
  v7282[21] = v7290;
  struct StateT * v7285 = slot_142(v7279);
  return v7285;
}

struct StateT * slot_432(struct StateT * v20180) {
  int v20181 = v20180->timer;
  int v20188 = v20181 + 1;
  v20180->timer = v20188;
  int * v20183 = v20180->regs;
  int v20184 = v20183[23];
  int v20192 = (int)((unsigned int)v20184 >> 23);
  v20183[24] = v20192;
  struct StateT * v20186 = slot_433(v20180);
  return v20186;
}

struct StateT * slot_306(struct StateT * v18162) {
  int v18163 = v18162->timer;
  int v18171 = v18163 + 1;
  v18162->timer = v18171;
  int * v18165 = v18162->regs;
  int v18166 = v18165[21];
  int v18167 = v18165[24];
  int v18175 = v18166 | v18167;
  v18165[21] = v18175;
  struct StateT * v18169 = slot_307(v18162);
  return v18169;
}

struct StateT * slot_312(struct StateT * v18252) {
  int v18253 = v18252->timer;
  int v18261 = v18253 + 1;
  v18252->timer = v18261;
  int * v18255 = v18252->regs;
  int v18256 = v18255[23];
  int v18257 = v18255[24];
  int v18265 = v18256 | v18257;
  v18255[23] = v18265;
  struct StateT * v18259 = slot_313(v18252);
  return v18259;
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

struct StateT * slot_560(struct StateT * v22266) {
  int * v22267 = v22266->regs;
  int v22268 = v22267[11];
  int * v22269 = v22266->saved_regs;
  int v22270 = v22269[13];
  bool v22371 = (v22268 ^ -2147483648) >= (v22270 ^ -2147483648);
  struct StateT * v22365;
  if (v22371) {
    struct StateT * v22271 = slot_398(v22266);
    v22365 = v22271;
  } else {
    int v22273 = v22266->timer;
    int v22374 = v22273 + 15;
    v22266->timer = v22374;
    int * v22275 = v22266->saved_regs;
    int v22276 = v22275[20];
    int * v22277 = v22266->regs;
    v22277[20] = v22276;
    int * v22279 = v22266->saved_regs;
    int v22280 = v22279[21];
    int * v22281 = v22266->regs;
    v22281[21] = v22280;
    int * v22283 = v22266->saved_regs;
    int v22284 = v22283[22];
    int * v22285 = v22266->regs;
    v22285[22] = v22284;
    int * v22287 = v22266->saved_regs;
    int v22288 = v22287[23];
    int * v22289 = v22266->regs;
    v22289[23] = v22288;
    int * v22291 = v22266->saved_regs;
    int v22292 = v22291[24];
    int * v22293 = v22266->regs;
    v22293[24] = v22292;
    int * v22295 = v22266->saved_regs;
    int v22296 = v22295[9];
    int * v22297 = v22266->regs;
    v22297[9] = v22296;
    int * v22299 = v22266->saved_regs;
    int v22300 = v22299[18];
    int * v22301 = v22266->regs;
    v22301[18] = v22300;
    int * v22303 = v22266->saved_regs;
    int v22304 = v22303[19];
    int * v22305 = v22266->regs;
    v22305[19] = v22304;
    int * v22307 = v22266->saved_regs;
    int v22308 = v22307[8];
    int * v22309 = v22266->regs;
    v22309[8] = v22308;
    int * v22311 = v22266->saved_regs;
    int v22312 = v22311[6];
    int * v22313 = v22266->regs;
    v22313[6] = v22312;
    int * v22315 = v22266->saved_regs;
    int v22316 = v22315[7];
    int * v22317 = v22266->regs;
    v22317[7] = v22316;
    int * v22319 = v22266->saved_regs;
    int v22320 = v22319[17];
    int * v22321 = v22266->regs;
    v22321[17] = v22320;
    int * v22323 = v22266->saved_regs;
    int v22324 = v22323[5];
    int * v22325 = v22266->regs;
    v22325[5] = v22324;
    int * v22327 = v22266->saved_regs;
    int v22328 = v22327[16];
    int * v22329 = v22266->regs;
    v22329[16] = v22328;
    int * v22331 = v22266->saved_regs;
    int v22332 = v22331[14];
    int * v22333 = v22266->regs;
    v22333[14] = v22332;
    int * v22335 = v22266->saved_regs;
    int v22336 = v22335[12];
    int * v22337 = v22266->regs;
    v22337[12] = v22336;
    int * v22339 = v22266->saved_regs;
    int v22340 = v22339[15];
    int * v22341 = v22266->regs;
    v22341[15] = v22340;
    int * v22343 = v22266->saved_regs;
    int v22344 = v22343[30];
    int * v22345 = v22266->regs;
    v22345[30] = v22344;
    int * v22347 = v22266->saved_regs;
    int v22348 = v22347[29];
    int * v22349 = v22266->regs;
    v22349[29] = v22348;
    int * v22351 = v22266->saved_regs;
    int v22352 = v22351[28];
    int * v22353 = v22266->regs;
    v22353[28] = v22352;
    int * v22355 = v22266->saved_regs;
    int v22356 = v22355[31];
    int * v22357 = v22266->regs;
    v22357[31] = v22356;
    int * v22359 = v22266->saved_regs;
    int v22360 = v22359[13];
    int * v22361 = v22266->regs;
    v22361[13] = v22360;
    struct StateT * v22363 = slot_201(v22266);
    v22365 = v22363;
  }
  return v22365;
}

struct StateT * slot_548(struct StateT * v22075) {
  int v22076 = v22075->timer;
  int v22084 = v22076 + 1;
  v22075->timer = v22084;
  int * v22078 = v22075->regs;
  int v22079 = v22078[21];
  int v22080 = v22078[24];
  int v22088 = v22079 | v22080;
  v22078[21] = v22088;
  struct StateT * v22082 = slot_549(v22075);
  return v22082;
}

struct StateT * slot_70(struct StateT * v6090) {
  int * v6091 = v6090->saved_regs;
  int * v6092 = v6090->regs;
  int v6093 = v6092[7];
  v6091[7] = v6093;
  int v6095 = v6090->timer;
  int v6107 = v6095 + 1;
  v6090->timer = v6107;
  int * v6097 = v6090->regs;
  int v6098 = v6097[7];
  int v6099 = v6097[21];
  int v6110 = v6098 ^ v6099;
  v6097[7] = v6110;
  struct StateT * v6101 = slot_71(v6090);
  return v6101;
}

struct StateT * slot_168(struct StateT * v7695) {
  int v7696 = v7695->timer;
  int v7704 = v7696 + 1;
  v7695->timer = v7704;
  int * v7698 = v7695->regs;
  int v7699 = v7698[23];
  int v7700 = v7698[24];
  int v7708 = v7699 | v7700;
  v7698[23] = v7708;
  struct StateT * v7702 = slot_169(v7695);
  return v7702;
}

struct StateT * slot_348(struct StateT * v18817) {
  int v18818 = v18817->timer;
  int v18825 = v18818 + 1;
  v18817->timer = v18825;
  int * v18820 = v18817->regs;
  int v18821 = v18820[22];
  int v18828 = v18821 << 9;
  v18820[22] = v18828;
  struct StateT * v18823 = slot_349(v18817);
  return v18823;
}

struct StateT * slot_456(struct StateT * v20588) {
  int * v20589 = v20588->saved_regs;
  int * v20590 = v20588->regs;
  int v20591 = v20590[14];
  v20589[14] = v20591;
  int v20593 = v20588->timer;
  int v20605 = v20593 + 1;
  v20588->timer = v20605;
  int * v20595 = v20588->regs;
  int v20596 = v20595[14];
  int v20597 = v20595[21];
  int v20608 = v20596 ^ v20597;
  v20595[14] = v20608;
  struct StateT * v20599 = slot_457(v20588);
  return v20599;
}

struct StateT * slot_225(struct StateT * v14128) {
  int v14129 = v14128->timer;
  int v14239 = v14129 + 1;
  v14128->timer = v14239;
  int * v14131 = v14128->regs;
  int v14132 = v14131[2];
  int * v14133 = v14128->cache_tags;
  int v14243 = (((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2;
  int v14134 = v14133[v14243];
  int v14244 = ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v14135 = v14133[v14244];
  int v14245 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2);
  int v14136 = v14133[v14245];
  int v14246 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v14137 = v14133[v14246];
  int v14138 = v14128->timer;
  int v14247 = v14138 + ((100 ^ (((~(((v14136 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14136 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v14134 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14134 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v14135 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14135 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v14136 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14136 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v14128->timer = v14247;
  int * v14140 = v14128->cache_vals;
  bool v14248 = !(((~(((v14134 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14134 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v14135 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14135 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v14233;
  if (v14248) {
    int * v14141 = v14128->cache_age;
    int v14250 = ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v14135 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14135 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v14142 = v14141[v14250];
    int v14143 = v14141[v14243];
    int v14251 = v14143 + ((int)((unsigned int)(v14143 - v14142) >> 31));
    v14141[v14243] = v14251;
    int * v14145 = v14128->cache_age;
    int v14146 = v14145[v14244];
    int v14253 = v14146 + ((int)((unsigned int)(v14146 - v14142) >> 31));
    v14145[v14244] = v14253;
    int * v14148 = v14128->cache_age;
    v14148[v14250] = 0;
    v14233 = v14250;
  } else {
    int * v14151 = v14128->cache_age;
    int v14257 = (((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2;
    int v14152 = v14151[v14257];
    int * v14153 = v14128->cache_tags;
    int v14154 = v14153[v14257];
    int v14155 = v14151[v14244];
    int v14156 = v14153[v14244];
    bool v14259 = !(((~(((v14136 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14136 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v14210;
    if (v14259) {
      int * v14157 = v14128->cache_age;
      int v14261 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))) | (-(v14137 ^ ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v14158 = v14157[v14261];
      int v14159 = v14157[v14245];
      int v14262 = v14159 + ((int)((unsigned int)(v14159 - v14158) >> 31));
      v14157[v14245] = v14262;
      int * v14161 = v14128->cache_age;
      int v14162 = v14161[v14246];
      int v14264 = v14162 + ((int)((unsigned int)(v14162 - v14158) >> 31));
      v14161[v14246] = v14264;
      int * v14164 = v14128->cache_age;
      v14164[v14261] = 0;
      v14210 = v14261;
    } else {
      int * v14167 = v14128->cache_age;
      int v14268 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2);
      int v14168 = v14167[v14268];
      int * v14169 = v14128->cache_tags;
      int v14170 = v14169[v14268];
      int v14171 = v14167[v14246];
      int v14172 = v14169[v14246];
      int * v14173 = v14128->cache_dirty;
      int v14271 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v14168 + ((~(((v14170 ^ -1) | (-(v14170 ^ -1))) >> 31)) & 2)) - (v14171 + ((~(((v14172 ^ -1) | (-(v14172 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v14174 = v14173[v14271];
      bool v14272 = !(v14174 == 0);
      if (v14272) {
        int * v14175 = v14128->cache_tags;
        int v14176 = v14175[v14271];
        int * v14177 = v14128->cache_vals;
        int v14275 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v14168 + ((~(((v14170 ^ -1) | (-(v14170 ^ -1))) >> 31)) & 2)) - (v14171 + ((~(((v14172 ^ -1) | (-(v14172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v14178 = v14177[v14275];
        int v14276 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v14168 + ((~(((v14170 ^ -1) | (-(v14170 ^ -1))) >> 31)) & 2)) - (v14171 + ((~(((v14172 ^ -1) | (-(v14172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v14179 = v14177[v14276];
        int * v14180 = v14128->mem;
        int v14278 = v14176 * 2;
        v14180[v14278] = v14178;
        int * v14182 = v14128->mem;
        int v14281 = (v14176 * 2) + 1;
        v14182[v14281] = v14179;
        ;
      } else {
        ;
      }
      int * v14187 = v14128->mem;
      int v14286 = ((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) * 2;
      int v14188 = v14187[v14286];
      int v14287 = (((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) * 2) + 1;
      int v14189 = v14187[v14287];
      int * v14190 = v14128->cache_vals;
      int v14289 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v14168 + ((~(((v14170 ^ -1) | (-(v14170 ^ -1))) >> 31)) & 2)) - (v14171 + ((~(((v14172 ^ -1) | (-(v14172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v14190[v14289] = v14188;
      int * v14192 = v14128->cache_vals;
      int v14292 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v14168 + ((~(((v14170 ^ -1) | (-(v14170 ^ -1))) >> 31)) & 2)) - (v14171 + ((~(((v14172 ^ -1) | (-(v14172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v14192[v14292] = v14189;
      int * v14194 = v14128->cache_tags;
      int v14295 = (int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1);
      v14194[v14271] = v14295;
      int * v14196 = v14128->cache_dirty;
      v14196[v14271] = 0;
      int * v14198 = v14128->cache_age;
      v14198[v14271] = 1;
      int * v14200 = v14128->cache_age;
      int v14201 = v14200[v14271];
      int v14202 = v14200[v14245];
      int v14301 = v14202 + ((int)((unsigned int)(v14202 - v14201) >> 31));
      v14200[v14245] = v14301;
      int * v14204 = v14128->cache_age;
      int v14205 = v14204[v14246];
      int v14303 = v14205 + ((int)((unsigned int)(v14205 - v14201) >> 31));
      v14204[v14246] = v14303;
      int * v14207 = v14128->cache_age;
      v14207[v14271] = 0;
      v14210 = v14271;
    }
    int * v14211 = v14128->cache_vals;
    int v14306 = v14210 * 2;
    int v14212 = v14211[v14306];
    int v14307 = (v14210 * 2) + 1;
    int v14213 = v14211[v14307];
    int v14308 = (((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v14152 + ((~(((v14154 ^ -1) | (-(v14154 ^ -1))) >> 31)) & 2)) - (v14155 + ((~(((v14156 ^ -1) | (-(v14156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v14211[v14308] = v14212;
    int * v14215 = v14128->cache_vals;
    int v14311 = ((((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v14152 + ((~(((v14154 ^ -1) | (-(v14154 ^ -1))) >> 31)) & 2)) - (v14155 + ((~(((v14156 ^ -1) | (-(v14156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v14215[v14311] = v14213;
    int * v14217 = v14128->cache_tags;
    int v14314 = ((((int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v14152 + ((~(((v14154 ^ -1) | (-(v14154 ^ -1))) >> 31)) & 2)) - (v14155 + ((~(((v14156 ^ -1) | (-(v14156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v14315 = (int)((unsigned int)((int)((unsigned int)(v14132 + 44) >> 2)) >> 1);
    v14217[v14314] = v14315;
    int * v14219 = v14128->cache_dirty;
    v14219[v14314] = 0;
    int * v14221 = v14128->cache_age;
    v14221[v14314] = 1;
    int * v14223 = v14128->cache_age;
    int v14224 = v14223[v14314];
    int v14225 = v14223[v14243];
    int v14321 = v14225 + ((int)((unsigned int)(v14225 - v14224) >> 31));
    v14223[v14243] = v14321;
    int * v14227 = v14128->cache_age;
    int v14228 = v14227[v14244];
    int v14323 = v14228 + ((int)((unsigned int)(v14228 - v14224) >> 31));
    v14227[v14244] = v14323;
    int * v14230 = v14128->cache_age;
    v14230[v14314] = 0;
    v14233 = v14314;
  }
  int v14326 = (v14233 * 2) + (((int)((unsigned int)(v14132 + 44) >> 2)) & 1);
  int v14234 = v14140[v14326];
  int * v14235 = v14128->regs;
  v14235[8] = v14234;
  struct StateT * v14237 = slot_220(v14128);
  return v14237;
}

struct StateT * slot_467(struct StateT * v20785) {
  int v20786 = v20785->timer;
  int v20793 = v20786 + 1;
  v20785->timer = v20793;
  int * v20788 = v20785->regs;
  int v20789 = v20788[21];
  int v20796 = v20789 << 18;
  v20788[21] = v20796;
  struct StateT * v20791 = slot_468(v20785);
  return v20791;
}

struct StateT * slot_285(struct StateT * v17836) {
  int v17837 = v17836->timer;
  int v17844 = v17837 + 1;
  v17836->timer = v17844;
  int * v17839 = v17836->regs;
  int v17840 = v17839[21];
  int v17847 = v17840 << 13;
  v17839[21] = v17847;
  struct StateT * v17842 = slot_286(v17836);
  return v17842;
}

struct StateT * slot_213(struct StateT * v11882) {
  int v11883 = v11882->timer;
  int v12053 = v11883 + 1;
  v11882->timer = v12053;
  int * v11885 = v11882->regs;
  int v11886 = v11885[10];
  int v11887 = v11885[12];
  int * v11888 = v11882->cache_tags;
  int v12058 = (((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2;
  int v11889 = v11888[v12058];
  int v12059 = ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11890 = v11888[v12059];
  int v12060 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2);
  int v11891 = v11888[v12060];
  int v12061 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11892 = v11888[v12061];
  int v11893 = v11882->timer;
  int v12062 = v11893 + ((100 ^ (((~(((v11891 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11891 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11889 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11889 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v11890 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11890 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11891 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11891 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11882->timer = v12062;
  bool v12063 = !(((~(((v11889 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11889 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v11890 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11890 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v11987;
  if (v12063) {
    int * v11895 = v11882->cache_age;
    int v12065 = ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v11890 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11890 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v11896 = v11895[v12065];
    int v11897 = v11895[v12058];
    int v12066 = v11897 + ((int)((unsigned int)(v11897 - v11896) >> 31));
    v11895[v12058] = v12066;
    int * v11899 = v11882->cache_age;
    int v11900 = v11899[v12059];
    int v12068 = v11900 + ((int)((unsigned int)(v11900 - v11896) >> 31));
    v11899[v12059] = v12068;
    int * v11902 = v11882->cache_age;
    v11902[v12065] = 0;
    v11987 = v12065;
  } else {
    int * v11905 = v11882->cache_age;
    int v12072 = (((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2;
    int v11906 = v11905[v12072];
    int * v11907 = v11882->cache_tags;
    int v11908 = v11907[v12072];
    int v11909 = v11905[v12059];
    int v11910 = v11907[v12059];
    bool v12074 = !(((~(((v11891 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11891 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v11964;
    if (v12074) {
      int * v11911 = v11882->cache_age;
      int v12076 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11892 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v11912 = v11911[v12076];
      int v11913 = v11911[v12060];
      int v12077 = v11913 + ((int)((unsigned int)(v11913 - v11912) >> 31));
      v11911[v12060] = v12077;
      int * v11915 = v11882->cache_age;
      int v11916 = v11915[v12061];
      int v12079 = v11916 + ((int)((unsigned int)(v11916 - v11912) >> 31));
      v11915[v12061] = v12079;
      int * v11918 = v11882->cache_age;
      v11918[v12076] = 0;
      v11964 = v12076;
    } else {
      int * v11921 = v11882->cache_age;
      int v12083 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2);
      int v11922 = v11921[v12083];
      int * v11923 = v11882->cache_tags;
      int v11924 = v11923[v12083];
      int v11925 = v11921[v12061];
      int v11926 = v11923[v12061];
      int * v11927 = v11882->cache_dirty;
      int v12086 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v11922 + ((~(((v11924 ^ -1) | (-(v11924 ^ -1))) >> 31)) & 2)) - (v11925 + ((~(((v11926 ^ -1) | (-(v11926 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11928 = v11927[v12086];
      bool v12087 = !(v11928 == 0);
      if (v12087) {
        int * v11929 = v11882->cache_tags;
        int v11930 = v11929[v12086];
        int * v11931 = v11882->cache_vals;
        int v12090 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v11922 + ((~(((v11924 ^ -1) | (-(v11924 ^ -1))) >> 31)) & 2)) - (v11925 + ((~(((v11926 ^ -1) | (-(v11926 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11932 = v11931[v12090];
        int v12091 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v11922 + ((~(((v11924 ^ -1) | (-(v11924 ^ -1))) >> 31)) & 2)) - (v11925 + ((~(((v11926 ^ -1) | (-(v11926 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11933 = v11931[v12091];
        int * v11934 = v11882->mem;
        int v12093 = v11930 * 2;
        v11934[v12093] = v11932;
        int * v11936 = v11882->mem;
        int v12096 = (v11930 * 2) + 1;
        v11936[v12096] = v11933;
        ;
      } else {
        ;
      }
      int * v11941 = v11882->mem;
      int v12101 = ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) * 2;
      int v11942 = v11941[v12101];
      int v12102 = (((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) * 2) + 1;
      int v11943 = v11941[v12102];
      int * v11944 = v11882->cache_vals;
      int v12104 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v11922 + ((~(((v11924 ^ -1) | (-(v11924 ^ -1))) >> 31)) & 2)) - (v11925 + ((~(((v11926 ^ -1) | (-(v11926 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11944[v12104] = v11942;
      int * v11946 = v11882->cache_vals;
      int v12107 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v11922 + ((~(((v11924 ^ -1) | (-(v11924 ^ -1))) >> 31)) & 2)) - (v11925 + ((~(((v11926 ^ -1) | (-(v11926 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11946[v12107] = v11943;
      int * v11948 = v11882->cache_tags;
      int v12110 = (int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1);
      v11948[v12086] = v12110;
      int * v11950 = v11882->cache_dirty;
      v11950[v12086] = 0;
      int * v11952 = v11882->cache_age;
      v11952[v12086] = 1;
      int * v11954 = v11882->cache_age;
      int v11955 = v11954[v12086];
      int v11956 = v11954[v12060];
      int v12116 = v11956 + ((int)((unsigned int)(v11956 - v11955) >> 31));
      v11954[v12060] = v12116;
      int * v11958 = v11882->cache_age;
      int v11959 = v11958[v12061];
      int v12118 = v11959 + ((int)((unsigned int)(v11959 - v11955) >> 31));
      v11958[v12061] = v12118;
      int * v11961 = v11882->cache_age;
      v11961[v12086] = 0;
      v11964 = v12086;
    }
    int * v11965 = v11882->cache_vals;
    int v12121 = v11964 * 2;
    int v11966 = v11965[v12121];
    int v12122 = (v11964 * 2) + 1;
    int v11967 = v11965[v12122];
    int v12123 = (((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v11906 + ((~(((v11908 ^ -1) | (-(v11908 ^ -1))) >> 31)) & 2)) - (v11909 + ((~(((v11910 ^ -1) | (-(v11910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11965[v12123] = v11966;
    int * v11969 = v11882->cache_vals;
    int v12126 = ((((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v11906 + ((~(((v11908 ^ -1) | (-(v11908 ^ -1))) >> 31)) & 2)) - (v11909 + ((~(((v11910 ^ -1) | (-(v11910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11969[v12126] = v11967;
    int * v11971 = v11882->cache_tags;
    int v12129 = ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v11906 + ((~(((v11908 ^ -1) | (-(v11908 ^ -1))) >> 31)) & 2)) - (v11909 + ((~(((v11910 ^ -1) | (-(v11910 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12130 = (int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1);
    v11971[v12129] = v12130;
    int * v11973 = v11882->cache_dirty;
    v11973[v12129] = 0;
    int * v11975 = v11882->cache_age;
    v11975[v12129] = 1;
    int * v11977 = v11882->cache_age;
    int v11978 = v11977[v12129];
    int v11979 = v11977[v12058];
    int v12136 = v11979 + ((int)((unsigned int)(v11979 - v11978) >> 31));
    v11977[v12058] = v12136;
    int * v11981 = v11882->cache_age;
    int v11982 = v11981[v12059];
    int v12138 = v11982 + ((int)((unsigned int)(v11982 - v11978) >> 31));
    v11981[v12059] = v12138;
    int * v11984 = v11882->cache_age;
    v11984[v12129] = 0;
    v11987 = v12129;
  }
  int * v11988 = v11882->cache_vals;
  int v12141 = (v11987 * 2) + (((int)((unsigned int)(v11886 + 16) >> 2)) & 1);
  v11988[v12141] = v11887;
  int * v11990 = v11882->cache_tags;
  int v11991 = v11990[v12060];
  int v11992 = v11990[v12061];
  bool v12144 = !(((~(((v11991 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11991 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v11992 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11992 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v12046;
  if (v12144) {
    int * v11993 = v11882->cache_age;
    int v12146 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11992 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))) | (-(v11992 ^ ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v11994 = v11993[v12146];
    int v11995 = v11993[v12060];
    int v12147 = v11995 + ((int)((unsigned int)(v11995 - v11994) >> 31));
    v11993[v12060] = v12147;
    int * v11997 = v11882->cache_age;
    int v11998 = v11997[v12061];
    int v12149 = v11998 + ((int)((unsigned int)(v11998 - v11994) >> 31));
    v11997[v12061] = v12149;
    int * v12000 = v11882->cache_age;
    v12000[v12146] = 0;
    v12046 = v12146;
  } else {
    int * v12003 = v11882->cache_age;
    int v12153 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2);
    int v12004 = v12003[v12153];
    int * v12005 = v11882->cache_tags;
    int v12006 = v12005[v12153];
    int v12007 = v12003[v12061];
    int v12008 = v12005[v12061];
    int * v12009 = v11882->cache_dirty;
    int v12156 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12004 + ((~(((v12006 ^ -1) | (-(v12006 ^ -1))) >> 31)) & 2)) - (v12007 + ((~(((v12008 ^ -1) | (-(v12008 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12010 = v12009[v12156];
    bool v12157 = !(v12010 == 0);
    if (v12157) {
      int * v12011 = v11882->cache_tags;
      int v12012 = v12011[v12156];
      int * v12013 = v11882->cache_vals;
      int v12160 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12004 + ((~(((v12006 ^ -1) | (-(v12006 ^ -1))) >> 31)) & 2)) - (v12007 + ((~(((v12008 ^ -1) | (-(v12008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12014 = v12013[v12160];
      int v12161 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12004 + ((~(((v12006 ^ -1) | (-(v12006 ^ -1))) >> 31)) & 2)) - (v12007 + ((~(((v12008 ^ -1) | (-(v12008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12015 = v12013[v12161];
      int * v12016 = v11882->mem;
      int v12163 = v12012 * 2;
      v12016[v12163] = v12014;
      int * v12018 = v11882->mem;
      int v12166 = (v12012 * 2) + 1;
      v12018[v12166] = v12015;
      ;
    } else {
      ;
    }
    int * v12023 = v11882->mem;
    int v12171 = ((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) * 2;
    int v12024 = v12023[v12171];
    int v12172 = (((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) * 2) + 1;
    int v12025 = v12023[v12172];
    int * v12026 = v11882->cache_vals;
    int v12174 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12004 + ((~(((v12006 ^ -1) | (-(v12006 ^ -1))) >> 31)) & 2)) - (v12007 + ((~(((v12008 ^ -1) | (-(v12008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12026[v12174] = v12024;
    int * v12028 = v11882->cache_vals;
    int v12177 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v12004 + ((~(((v12006 ^ -1) | (-(v12006 ^ -1))) >> 31)) & 2)) - (v12007 + ((~(((v12008 ^ -1) | (-(v12008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12028[v12177] = v12025;
    int * v12030 = v11882->cache_tags;
    int v12180 = (int)((unsigned int)((int)((unsigned int)(v11886 + 16) >> 2)) >> 1);
    v12030[v12156] = v12180;
    int * v12032 = v11882->cache_dirty;
    v12032[v12156] = 0;
    int * v12034 = v11882->cache_age;
    v12034[v12156] = 1;
    int * v12036 = v11882->cache_age;
    int v12037 = v12036[v12156];
    int v12038 = v12036[v12060];
    int v12186 = v12038 + ((int)((unsigned int)(v12038 - v12037) >> 31));
    v12036[v12060] = v12186;
    int * v12040 = v11882->cache_age;
    int v12041 = v12040[v12061];
    int v12188 = v12041 + ((int)((unsigned int)(v12041 - v12037) >> 31));
    v12040[v12061] = v12188;
    int * v12043 = v11882->cache_age;
    v12043[v12156] = 0;
    v12046 = v12156;
  }
  int * v12047 = v11882->cache_vals;
  int v12191 = (v12046 * 2) + (((int)((unsigned int)(v11886 + 16) >> 2)) & 1);
  v12047[v12191] = v11887;
  int * v12049 = v11882->cache_dirty;
  v12049[v12046] = 1;
  struct StateT * v12051 = slot_216(v11882);
  return v12051;
}

struct StateT * slot_82(struct StateT * v6301) {
  int v6302 = v6301->timer;
  int v6310 = v6302 + 1;
  v6301->timer = v6310;
  int * v6304 = v6301->regs;
  int v6305 = v6304[21];
  int v6306 = v6304[24];
  int v6314 = v6305 | v6306;
  v6304[21] = v6314;
  struct StateT * v6308 = slot_83(v6301);
  return v6308;
}

struct StateT * slot_263(struct StateT * v17493) {
  int v17494 = v17493->timer;
  int v17502 = v17494 + 1;
  v17493->timer = v17502;
  int * v17496 = v17493->regs;
  int v17497 = v17496[20];
  int v17498 = v17496[24];
  int v17506 = v17497 | v17498;
  v17496[20] = v17506;
  struct StateT * v17500 = slot_264(v17493);
  return v17500;
}

struct StateT * slot_161(struct StateT * v7591) {
  int v7592 = v7591->timer;
  int v7599 = v7592 + 1;
  v7591->timer = v7599;
  int * v7594 = v7591->regs;
  int v7595 = v7594[21];
  int v7602 = v7595 << 13;
  v7594[21] = v7602;
  struct StateT * v7597 = slot_162(v7591);
  return v7597;
}

struct StateT * slot_293(struct StateT * v17956) {
  int v17957 = v17956->timer;
  int v17965 = v17957 + 1;
  v17956->timer = v17965;
  int * v17959 = v17956->regs;
  int v17960 = v17959[16];
  int v17961 = v17959[20];
  int v17969 = v17960 ^ v17961;
  v17959[16] = v17969;
  struct StateT * v17963 = slot_294(v17956);
  return v17963;
}

struct StateT * slot_185(struct StateT * v7962) {
  int v7963 = v7962->timer;
  int v7971 = v7963 + 1;
  v7962->timer = v7971;
  int * v7965 = v7962->regs;
  int v7966 = v7965[22];
  int v7967 = v7965[24];
  int v7975 = v7966 | v7967;
  v7965[22] = v7975;
  struct StateT * v7969 = slot_186(v7962);
  return v7969;
}

struct StateT * slot_288(struct StateT * v17881) {
  int v17882 = v17881->timer;
  int v17889 = v17882 + 1;
  v17881->timer = v17889;
  int * v17884 = v17881->regs;
  int v17885 = v17884[22];
  int v17892 = v17885 << 13;
  v17884[22] = v17892;
  struct StateT * v17887 = slot_289(v17881);
  return v17887;
}

struct StateT * slot_89(struct StateT * v6407) {
  int * v6408 = v6407->saved_regs;
  int * v6409 = v6407->regs;
  int v6410 = v6409[16];
  v6408[16] = v6410;
  int v6412 = v6407->timer;
  int v6424 = v6412 + 1;
  v6407->timer = v6424;
  int * v6414 = v6407->regs;
  int v6415 = v6414[16];
  int v6416 = v6414[20];
  int v6427 = v6415 ^ v6416;
  v6414[16] = v6427;
  struct StateT * v6418 = slot_90(v6407);
  return v6418;
}

struct StateT * slot_384(struct StateT * v19381) {
  int v19382 = v19381->timer;
  int v19389 = v19382 + 1;
  v19381->timer = v19389;
  int * v19384 = v19381->regs;
  int v19385 = v19384[21];
  int v19393 = (int)((unsigned int)v19385 >> 14);
  v19384[24] = v19393;
  struct StateT * v19387 = slot_385(v19381);
  return v19387;
}

struct StateT * slot_486(struct StateT * v21110) {
  int v21111 = v21110->timer;
  int v21118 = v21111 + 1;
  v21110->timer = v21118;
  int * v21113 = v21110->regs;
  int v21114 = v21113[21];
  int v21122 = (int)((unsigned int)v21114 >> 25);
  v21113[24] = v21122;
  struct StateT * v21116 = slot_487(v21110);
  return v21116;
}

struct StateT * slot_347(struct StateT * v18802) {
  int v18803 = v18802->timer;
  int v18810 = v18803 + 1;
  v18802->timer = v18810;
  int * v18805 = v18802->regs;
  int v18806 = v18805[22];
  int v18814 = (int)((unsigned int)v18806 >> 23);
  v18805[24] = v18814;
  struct StateT * v18808 = slot_348(v18802);
  return v18808;
}

struct StateT * slot_140(struct StateT * v7264) {
  int v7265 = v7264->timer;
  int v7272 = v7265 + 1;
  v7264->timer = v7272;
  int * v7267 = v7264->regs;
  int v7268 = v7267[21];
  int v7276 = (int)((unsigned int)v7268 >> 23);
  v7267[24] = v7276;
  struct StateT * v7270 = slot_141(v7264);
  return v7270;
}

struct StateT * slot_473(struct StateT * v20875) {
  int v20876 = v20875->timer;
  int v20883 = v20876 + 1;
  v20875->timer = v20883;
  int * v20878 = v20875->regs;
  int v20879 = v20878[23];
  int v20886 = v20879 << 18;
  v20878[23] = v20886;
  struct StateT * v20881 = slot_474(v20875);
  return v20881;
}

struct StateT * slot_49(struct StateT * v5727) {
  int * v5728 = v5727->saved_regs;
  int * v5729 = v5727->regs;
  int v5730 = v5729[9];
  v5728[9] = v5730;
  int v5732 = v5727->timer;
  int v5744 = v5732 + 1;
  v5727->timer = v5744;
  int * v5734 = v5727->regs;
  int v5735 = v5734[9];
  int v5736 = v5734[20];
  int v5747 = v5735 ^ v5736;
  v5734[9] = v5747;
  struct StateT * v5738 = slot_50(v5727);
  return v5738;
}

struct StateT * slot_216(struct StateT * v12526) {
  int v12527 = v12526->timer;
  int v12697 = v12527 + 1;
  v12526->timer = v12697;
  int * v12529 = v12526->regs;
  int v12530 = v12529[10];
  int v12531 = v12529[5];
  int * v12532 = v12526->cache_tags;
  int v12702 = (((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2;
  int v12533 = v12532[v12702];
  int v12703 = ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v12534 = v12532[v12703];
  int v12704 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2);
  int v12535 = v12532[v12704];
  int v12705 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v12536 = v12532[v12705];
  int v12537 = v12526->timer;
  int v12706 = v12537 + ((100 ^ (((~(((v12535 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12535 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v12533 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12533 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12534 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12534 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v12535 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12535 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v12526->timer = v12706;
  bool v12707 = !(((~(((v12533 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12533 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12534 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12534 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v12631;
  if (v12707) {
    int * v12539 = v12526->cache_age;
    int v12709 = ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v12534 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12534 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v12540 = v12539[v12709];
    int v12541 = v12539[v12702];
    int v12710 = v12541 + ((int)((unsigned int)(v12541 - v12540) >> 31));
    v12539[v12702] = v12710;
    int * v12543 = v12526->cache_age;
    int v12544 = v12543[v12703];
    int v12712 = v12544 + ((int)((unsigned int)(v12544 - v12540) >> 31));
    v12543[v12703] = v12712;
    int * v12546 = v12526->cache_age;
    v12546[v12709] = 0;
    v12631 = v12709;
  } else {
    int * v12549 = v12526->cache_age;
    int v12716 = (((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2;
    int v12550 = v12549[v12716];
    int * v12551 = v12526->cache_tags;
    int v12552 = v12551[v12716];
    int v12553 = v12549[v12703];
    int v12554 = v12551[v12703];
    bool v12718 = !(((~(((v12535 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12535 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v12608;
    if (v12718) {
      int * v12555 = v12526->cache_age;
      int v12720 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12536 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v12556 = v12555[v12720];
      int v12557 = v12555[v12704];
      int v12721 = v12557 + ((int)((unsigned int)(v12557 - v12556) >> 31));
      v12555[v12704] = v12721;
      int * v12559 = v12526->cache_age;
      int v12560 = v12559[v12705];
      int v12723 = v12560 + ((int)((unsigned int)(v12560 - v12556) >> 31));
      v12559[v12705] = v12723;
      int * v12562 = v12526->cache_age;
      v12562[v12720] = 0;
      v12608 = v12720;
    } else {
      int * v12565 = v12526->cache_age;
      int v12727 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2);
      int v12566 = v12565[v12727];
      int * v12567 = v12526->cache_tags;
      int v12568 = v12567[v12727];
      int v12569 = v12565[v12705];
      int v12570 = v12567[v12705];
      int * v12571 = v12526->cache_dirty;
      int v12730 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12566 + ((~(((v12568 ^ -1) | (-(v12568 ^ -1))) >> 31)) & 2)) - (v12569 + ((~(((v12570 ^ -1) | (-(v12570 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v12572 = v12571[v12730];
      bool v12731 = !(v12572 == 0);
      if (v12731) {
        int * v12573 = v12526->cache_tags;
        int v12574 = v12573[v12730];
        int * v12575 = v12526->cache_vals;
        int v12734 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12566 + ((~(((v12568 ^ -1) | (-(v12568 ^ -1))) >> 31)) & 2)) - (v12569 + ((~(((v12570 ^ -1) | (-(v12570 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v12576 = v12575[v12734];
        int v12735 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12566 + ((~(((v12568 ^ -1) | (-(v12568 ^ -1))) >> 31)) & 2)) - (v12569 + ((~(((v12570 ^ -1) | (-(v12570 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v12577 = v12575[v12735];
        int * v12578 = v12526->mem;
        int v12737 = v12574 * 2;
        v12578[v12737] = v12576;
        int * v12580 = v12526->mem;
        int v12740 = (v12574 * 2) + 1;
        v12580[v12740] = v12577;
        ;
      } else {
        ;
      }
      int * v12585 = v12526->mem;
      int v12745 = ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) * 2;
      int v12586 = v12585[v12745];
      int v12746 = (((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) * 2) + 1;
      int v12587 = v12585[v12746];
      int * v12588 = v12526->cache_vals;
      int v12748 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12566 + ((~(((v12568 ^ -1) | (-(v12568 ^ -1))) >> 31)) & 2)) - (v12569 + ((~(((v12570 ^ -1) | (-(v12570 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v12588[v12748] = v12586;
      int * v12590 = v12526->cache_vals;
      int v12751 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12566 + ((~(((v12568 ^ -1) | (-(v12568 ^ -1))) >> 31)) & 2)) - (v12569 + ((~(((v12570 ^ -1) | (-(v12570 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v12590[v12751] = v12587;
      int * v12592 = v12526->cache_tags;
      int v12754 = (int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1);
      v12592[v12730] = v12754;
      int * v12594 = v12526->cache_dirty;
      v12594[v12730] = 0;
      int * v12596 = v12526->cache_age;
      v12596[v12730] = 1;
      int * v12598 = v12526->cache_age;
      int v12599 = v12598[v12730];
      int v12600 = v12598[v12704];
      int v12760 = v12600 + ((int)((unsigned int)(v12600 - v12599) >> 31));
      v12598[v12704] = v12760;
      int * v12602 = v12526->cache_age;
      int v12603 = v12602[v12705];
      int v12762 = v12603 + ((int)((unsigned int)(v12603 - v12599) >> 31));
      v12602[v12705] = v12762;
      int * v12605 = v12526->cache_age;
      v12605[v12730] = 0;
      v12608 = v12730;
    }
    int * v12609 = v12526->cache_vals;
    int v12765 = v12608 * 2;
    int v12610 = v12609[v12765];
    int v12766 = (v12608 * 2) + 1;
    int v12611 = v12609[v12766];
    int v12767 = (((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v12550 + ((~(((v12552 ^ -1) | (-(v12552 ^ -1))) >> 31)) & 2)) - (v12553 + ((~(((v12554 ^ -1) | (-(v12554 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12609[v12767] = v12610;
    int * v12613 = v12526->cache_vals;
    int v12770 = ((((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v12550 + ((~(((v12552 ^ -1) | (-(v12552 ^ -1))) >> 31)) & 2)) - (v12553 + ((~(((v12554 ^ -1) | (-(v12554 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12613[v12770] = v12611;
    int * v12615 = v12526->cache_tags;
    int v12773 = ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v12550 + ((~(((v12552 ^ -1) | (-(v12552 ^ -1))) >> 31)) & 2)) - (v12553 + ((~(((v12554 ^ -1) | (-(v12554 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12774 = (int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1);
    v12615[v12773] = v12774;
    int * v12617 = v12526->cache_dirty;
    v12617[v12773] = 0;
    int * v12619 = v12526->cache_age;
    v12619[v12773] = 1;
    int * v12621 = v12526->cache_age;
    int v12622 = v12621[v12773];
    int v12623 = v12621[v12702];
    int v12780 = v12623 + ((int)((unsigned int)(v12623 - v12622) >> 31));
    v12621[v12702] = v12780;
    int * v12625 = v12526->cache_age;
    int v12626 = v12625[v12703];
    int v12782 = v12626 + ((int)((unsigned int)(v12626 - v12622) >> 31));
    v12625[v12703] = v12782;
    int * v12628 = v12526->cache_age;
    v12628[v12773] = 0;
    v12631 = v12773;
  }
  int * v12632 = v12526->cache_vals;
  int v12785 = (v12631 * 2) + (((int)((unsigned int)(v12530 + 20) >> 2)) & 1);
  v12632[v12785] = v12531;
  int * v12634 = v12526->cache_tags;
  int v12635 = v12634[v12704];
  int v12636 = v12634[v12705];
  bool v12788 = !(((~(((v12635 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12635 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v12636 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12636 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v12690;
  if (v12788) {
    int * v12637 = v12526->cache_age;
    int v12790 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v12636 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))) | (-(v12636 ^ ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v12638 = v12637[v12790];
    int v12639 = v12637[v12704];
    int v12791 = v12639 + ((int)((unsigned int)(v12639 - v12638) >> 31));
    v12637[v12704] = v12791;
    int * v12641 = v12526->cache_age;
    int v12642 = v12641[v12705];
    int v12793 = v12642 + ((int)((unsigned int)(v12642 - v12638) >> 31));
    v12641[v12705] = v12793;
    int * v12644 = v12526->cache_age;
    v12644[v12790] = 0;
    v12690 = v12790;
  } else {
    int * v12647 = v12526->cache_age;
    int v12797 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2);
    int v12648 = v12647[v12797];
    int * v12649 = v12526->cache_tags;
    int v12650 = v12649[v12797];
    int v12651 = v12647[v12705];
    int v12652 = v12649[v12705];
    int * v12653 = v12526->cache_dirty;
    int v12800 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12648 + ((~(((v12650 ^ -1) | (-(v12650 ^ -1))) >> 31)) & 2)) - (v12651 + ((~(((v12652 ^ -1) | (-(v12652 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v12654 = v12653[v12800];
    bool v12801 = !(v12654 == 0);
    if (v12801) {
      int * v12655 = v12526->cache_tags;
      int v12656 = v12655[v12800];
      int * v12657 = v12526->cache_vals;
      int v12804 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12648 + ((~(((v12650 ^ -1) | (-(v12650 ^ -1))) >> 31)) & 2)) - (v12651 + ((~(((v12652 ^ -1) | (-(v12652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v12658 = v12657[v12804];
      int v12805 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12648 + ((~(((v12650 ^ -1) | (-(v12650 ^ -1))) >> 31)) & 2)) - (v12651 + ((~(((v12652 ^ -1) | (-(v12652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v12659 = v12657[v12805];
      int * v12660 = v12526->mem;
      int v12807 = v12656 * 2;
      v12660[v12807] = v12658;
      int * v12662 = v12526->mem;
      int v12810 = (v12656 * 2) + 1;
      v12662[v12810] = v12659;
      ;
    } else {
      ;
    }
    int * v12667 = v12526->mem;
    int v12815 = ((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) * 2;
    int v12668 = v12667[v12815];
    int v12816 = (((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) * 2) + 1;
    int v12669 = v12667[v12816];
    int * v12670 = v12526->cache_vals;
    int v12818 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12648 + ((~(((v12650 ^ -1) | (-(v12650 ^ -1))) >> 31)) & 2)) - (v12651 + ((~(((v12652 ^ -1) | (-(v12652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v12670[v12818] = v12668;
    int * v12672 = v12526->cache_vals;
    int v12821 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v12648 + ((~(((v12650 ^ -1) | (-(v12650 ^ -1))) >> 31)) & 2)) - (v12651 + ((~(((v12652 ^ -1) | (-(v12652 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v12672[v12821] = v12669;
    int * v12674 = v12526->cache_tags;
    int v12824 = (int)((unsigned int)((int)((unsigned int)(v12530 + 20) >> 2)) >> 1);
    v12674[v12800] = v12824;
    int * v12676 = v12526->cache_dirty;
    v12676[v12800] = 0;
    int * v12678 = v12526->cache_age;
    v12678[v12800] = 1;
    int * v12680 = v12526->cache_age;
    int v12681 = v12680[v12800];
    int v12682 = v12680[v12704];
    int v12830 = v12682 + ((int)((unsigned int)(v12682 - v12681) >> 31));
    v12680[v12704] = v12830;
    int * v12684 = v12526->cache_age;
    int v12685 = v12684[v12705];
    int v12832 = v12685 + ((int)((unsigned int)(v12685 - v12681) >> 31));
    v12684[v12705] = v12832;
    int * v12687 = v12526->cache_age;
    v12687[v12800] = 0;
    v12690 = v12800;
  }
  int * v12691 = v12526->cache_vals;
  int v12835 = (v12690 * 2) + (((int)((unsigned int)(v12530 + 20) >> 2)) & 1);
  v12691[v12835] = v12531;
  int * v12693 = v12526->cache_dirty;
  v12693[v12690] = 1;
  struct StateT * v12695 = slot_211(v12526);
  return v12695;
}

struct StateT * slot_468(struct StateT * v20799) {
  int v20800 = v20799->timer;
  int v20808 = v20800 + 1;
  v20799->timer = v20808;
  int * v20802 = v20799->regs;
  int v20803 = v20802[21];
  int v20804 = v20802[24];
  int v20812 = v20803 | v20804;
  v20802[21] = v20812;
  struct StateT * v20806 = slot_469(v20799);
  return v20806;
}

struct StateT * slot_50(struct StateT * v5750) {
  int * v5751 = v5750->saved_regs;
  int * v5752 = v5750->regs;
  int v5753 = v5752[18];
  v5751[18] = v5753;
  int v5755 = v5750->timer;
  int v5767 = v5755 + 1;
  v5750->timer = v5767;
  int * v5757 = v5750->regs;
  int v5758 = v5757[18];
  int v5759 = v5757[21];
  int v5770 = v5758 ^ v5759;
  v5757[18] = v5770;
  struct StateT * v5761 = slot_51(v5750);
  return v5761;
}

struct StateT * slot_135(struct StateT * v7185) {
  int v7186 = v7185->timer;
  int v7194 = v7186 + 1;
  v7185->timer = v7194;
  int * v7188 = v7185->regs;
  int v7189 = v7188[15];
  int v7190 = v7188[28];
  int v7199 = v7189 + v7190;
  v7188[22] = v7199;
  struct StateT * v7192 = slot_136(v7185);
  return v7192;
}

struct StateT * slot_248(struct StateT * v17109) {
  int v17110 = v17109->timer;
  int v17118 = v17110 + 1;
  v17109->timer = v17118;
  int * v17112 = v17109->regs;
  int v17113 = v17112[9];
  int v17114 = v17112[20];
  int v17122 = v17113 ^ v17114;
  v17112[9] = v17122;
  struct StateT * v17116 = slot_251(v17109);
  return v17116;
}

struct StateT * slot_59(struct StateT * v5916) {
  int v5917 = v5916->timer;
  int v5925 = v5917 + 1;
  v5916->timer = v5925;
  int * v5919 = v5916->regs;
  int v5920 = v5919[20];
  int v5921 = v5919[24];
  int v5929 = v5920 | v5921;
  v5919[20] = v5929;
  struct StateT * v5923 = slot_60(v5916);
  return v5923;
}

struct StateT * slot_485(struct StateT * v21094) {
  int v21095 = v21094->timer;
  int v21103 = v21095 + 1;
  v21094->timer = v21103;
  int * v21097 = v21094->regs;
  int v21098 = v21097[20];
  int v21099 = v21097[24];
  int v21107 = v21098 | v21099;
  v21097[20] = v21107;
  struct StateT * v21101 = slot_486(v21094);
  return v21101;
}

struct StateT * slot_40(struct StateT * v5592) {
  int v5593 = v5592->timer;
  int v5600 = v5593 + 1;
  v5592->timer = v5600;
  int * v5595 = v5592->regs;
  int v5596 = v5595[21];
  int v5604 = (int)((unsigned int)v5596 >> 25);
  v5595[24] = v5604;
  struct StateT * v5598 = slot_41(v5592);
  return v5598;
}

struct StateT * slot_77(struct StateT * v6227) {
  int v6228 = v6227->timer;
  int v6235 = v6228 + 1;
  v6227->timer = v6235;
  int * v6230 = v6227->regs;
  int v6231 = v6230[20];
  int v6239 = (int)((unsigned int)v6231 >> 19);
  v6230[24] = v6239;
  struct StateT * v6233 = slot_78(v6227);
  return v6233;
}

struct StateT * slot_85(struct StateT * v6346) {
  int v6347 = v6346->timer;
  int v6355 = v6347 + 1;
  v6346->timer = v6355;
  int * v6349 = v6346->regs;
  int v6350 = v6349[22];
  int v6351 = v6349[24];
  int v6359 = v6350 | v6351;
  v6349[22] = v6359;
  struct StateT * v6353 = slot_86(v6346);
  return v6353;
}

struct StateT * slot_350(struct StateT * v18847) {
  int v18848 = v18847->timer;
  int v18855 = v18848 + 1;
  v18847->timer = v18855;
  int * v18850 = v18847->regs;
  int v18851 = v18850[23];
  int v18859 = (int)((unsigned int)v18851 >> 23);
  v18850[24] = v18859;
  struct StateT * v18853 = slot_351(v18847);
  return v18853;
}

struct StateT * slot_392(struct StateT * v19500) {
  int v19501 = v19500->timer;
  int v19509 = v19501 + 1;
  v19500->timer = v19509;
  int * v19503 = v19500->regs;
  int v19504 = v19503[23];
  int v19505 = v19503[24];
  int v19513 = v19504 | v19505;
  v19503[23] = v19513;
  struct StateT * v19507 = slot_393(v19500);
  return v19507;
}

struct StateT * slot_75(struct StateT * v6193) {
  int v6194 = v6193->timer;
  int v6202 = v6194 + 1;
  v6193->timer = v6202;
  int * v6196 = v6193->regs;
  int v6197 = v6196[17];
  int v6198 = v6196[19];
  int v6207 = v6197 + v6198;
  v6196[22] = v6207;
  struct StateT * v6200 = slot_76(v6193);
  return v6200;
}

struct StateT * slot_71(struct StateT * v6113) {
  int * v6114 = v6113->saved_regs;
  int * v6115 = v6113->regs;
  int v6116 = v6115[17];
  v6114[17] = v6116;
  int v6118 = v6113->timer;
  int v6130 = v6118 + 1;
  v6113->timer = v6130;
  int * v6120 = v6113->regs;
  int v6121 = v6120[17];
  int v6122 = v6120[22];
  int v6133 = v6121 ^ v6122;
  v6120[17] = v6133;
  struct StateT * v6124 = slot_72(v6113);
  return v6124;
}

struct StateT * slot_378(struct StateT * v19285) {
  int v19286 = v19285->timer;
  int v19294 = v19286 + 1;
  v19285->timer = v19294;
  int * v19288 = v19285->regs;
  int v19289 = v19288[9];
  int v19290 = v19288[5];
  int v19299 = v19289 + v19290;
  v19288[21] = v19299;
  struct StateT * v19292 = slot_379(v19285);
  return v19292;
}

struct StateT * slot_108(struct StateT * v6731) {
  int v6732 = v6731->timer;
  int v6740 = v6732 + 1;
  v6731->timer = v6740;
  int * v6734 = v6731->regs;
  int v6735 = v6734[23];
  int v6736 = v6734[24];
  int v6744 = v6735 | v6736;
  v6734[23] = v6744;
  struct StateT * v6738 = slot_109(v6731);
  return v6738;
}

struct StateT * slot_116(struct StateT * v6890) {
  int v6891 = v6890->timer;
  int v6899 = v6891 + 1;
  v6890->timer = v6899;
  int * v6893 = v6890->regs;
  int v6894 = v6893[31];
  int v6895 = v6893[19];
  int v6904 = v6894 + v6895;
  v6893[23] = v6904;
  struct StateT * v6897 = slot_117(v6890);
  return v6897;
}

struct StateT * slot_417(struct StateT * v19931) {
  int * v19932 = v19931->saved_regs;
  int * v19933 = v19931->regs;
  int v19934 = v19933[19];
  v19932[19] = v19934;
  int v19936 = v19931->timer;
  int v19948 = v19936 + 1;
  v19931->timer = v19948;
  int * v19938 = v19931->regs;
  int v19939 = v19938[19];
  int v19940 = v19938[22];
  int v19951 = v19939 ^ v19940;
  v19938[19] = v19951;
  struct StateT * v19942 = slot_418(v19931);
  return v19942;
}

struct StateT * slot_405(struct StateT * v19734) {
  int v19735 = v19734->timer;
  int v19743 = v19735 + 1;
  v19734->timer = v19743;
  int * v19737 = v19734->regs;
  int v19738 = v19737[20];
  int v19739 = v19737[24];
  int v19747 = v19738 | v19739;
  v19737[20] = v19747;
  struct StateT * v19741 = slot_406(v19734);
  return v19741;
}

struct StateT * slot_215(struct StateT * v12512) {
  int v12513 = v12512->timer;
  int v12520 = v12513 + 1;
  v12512->timer = v12520;
  int * v12515 = v12512->regs;
  int v12516 = v12515[20];
  int v12523 = v12516 << 7;
  v12515[20] = v12523;
  struct StateT * v12518 = slot_218(v12512);
  return v12518;
}

struct StateT * slot_45(struct StateT * v5666) {
  int v5667 = v5666->timer;
  int v5675 = v5667 + 1;
  v5666->timer = v5675;
  int * v5669 = v5666->regs;
  int v5670 = v5669[22];
  int v5671 = v5669[24];
  int v5679 = v5670 | v5671;
  v5669[22] = v5679;
  struct StateT * v5673 = slot_46(v5666);
  return v5673;
}

struct StateT * slot_220(struct StateT * v13376) {
  int v13377 = v13376->timer;
  int v13487 = v13377 + 1;
  v13376->timer = v13487;
  int * v13379 = v13376->regs;
  int v13380 = v13379[2];
  int * v13381 = v13376->cache_tags;
  int v13491 = (((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2;
  int v13382 = v13381[v13491];
  int v13492 = ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v13383 = v13381[v13492];
  int v13493 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2);
  int v13384 = v13381[v13493];
  int v13494 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v13385 = v13381[v13494];
  int v13386 = v13376->timer;
  int v13495 = v13386 + ((100 ^ (((~(((v13384 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13384 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v13382 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13382 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v13383 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13383 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v13384 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13384 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v13376->timer = v13495;
  int * v13388 = v13376->cache_vals;
  bool v13496 = !(((~(((v13382 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13382 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v13383 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13383 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v13481;
  if (v13496) {
    int * v13389 = v13376->cache_age;
    int v13498 = ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v13383 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13383 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v13390 = v13389[v13498];
    int v13391 = v13389[v13491];
    int v13499 = v13391 + ((int)((unsigned int)(v13391 - v13390) >> 31));
    v13389[v13491] = v13499;
    int * v13393 = v13376->cache_age;
    int v13394 = v13393[v13492];
    int v13501 = v13394 + ((int)((unsigned int)(v13394 - v13390) >> 31));
    v13393[v13492] = v13501;
    int * v13396 = v13376->cache_age;
    v13396[v13498] = 0;
    v13481 = v13498;
  } else {
    int * v13399 = v13376->cache_age;
    int v13505 = (((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2;
    int v13400 = v13399[v13505];
    int * v13401 = v13376->cache_tags;
    int v13402 = v13401[v13505];
    int v13403 = v13399[v13492];
    int v13404 = v13401[v13492];
    bool v13507 = !(((~(((v13384 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13384 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v13458;
    if (v13507) {
      int * v13405 = v13376->cache_age;
      int v13509 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))) | (-(v13385 ^ ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v13406 = v13405[v13509];
      int v13407 = v13405[v13493];
      int v13510 = v13407 + ((int)((unsigned int)(v13407 - v13406) >> 31));
      v13405[v13493] = v13510;
      int * v13409 = v13376->cache_age;
      int v13410 = v13409[v13494];
      int v13512 = v13410 + ((int)((unsigned int)(v13410 - v13406) >> 31));
      v13409[v13494] = v13512;
      int * v13412 = v13376->cache_age;
      v13412[v13509] = 0;
      v13458 = v13509;
    } else {
      int * v13415 = v13376->cache_age;
      int v13516 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2);
      int v13416 = v13415[v13516];
      int * v13417 = v13376->cache_tags;
      int v13418 = v13417[v13516];
      int v13419 = v13415[v13494];
      int v13420 = v13417[v13494];
      int * v13421 = v13376->cache_dirty;
      int v13519 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v13416 + ((~(((v13418 ^ -1) | (-(v13418 ^ -1))) >> 31)) & 2)) - (v13419 + ((~(((v13420 ^ -1) | (-(v13420 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v13422 = v13421[v13519];
      bool v13520 = !(v13422 == 0);
      if (v13520) {
        int * v13423 = v13376->cache_tags;
        int v13424 = v13423[v13519];
        int * v13425 = v13376->cache_vals;
        int v13523 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v13416 + ((~(((v13418 ^ -1) | (-(v13418 ^ -1))) >> 31)) & 2)) - (v13419 + ((~(((v13420 ^ -1) | (-(v13420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v13426 = v13425[v13523];
        int v13524 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v13416 + ((~(((v13418 ^ -1) | (-(v13418 ^ -1))) >> 31)) & 2)) - (v13419 + ((~(((v13420 ^ -1) | (-(v13420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v13427 = v13425[v13524];
        int * v13428 = v13376->mem;
        int v13526 = v13424 * 2;
        v13428[v13526] = v13426;
        int * v13430 = v13376->mem;
        int v13529 = (v13424 * 2) + 1;
        v13430[v13529] = v13427;
        ;
      } else {
        ;
      }
      int * v13435 = v13376->mem;
      int v13534 = ((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) * 2;
      int v13436 = v13435[v13534];
      int v13535 = (((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) * 2) + 1;
      int v13437 = v13435[v13535];
      int * v13438 = v13376->cache_vals;
      int v13537 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v13416 + ((~(((v13418 ^ -1) | (-(v13418 ^ -1))) >> 31)) & 2)) - (v13419 + ((~(((v13420 ^ -1) | (-(v13420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v13438[v13537] = v13436;
      int * v13440 = v13376->cache_vals;
      int v13540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v13416 + ((~(((v13418 ^ -1) | (-(v13418 ^ -1))) >> 31)) & 2)) - (v13419 + ((~(((v13420 ^ -1) | (-(v13420 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v13440[v13540] = v13437;
      int * v13442 = v13376->cache_tags;
      int v13543 = (int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1);
      v13442[v13519] = v13543;
      int * v13444 = v13376->cache_dirty;
      v13444[v13519] = 0;
      int * v13446 = v13376->cache_age;
      v13446[v13519] = 1;
      int * v13448 = v13376->cache_age;
      int v13449 = v13448[v13519];
      int v13450 = v13448[v13493];
      int v13549 = v13450 + ((int)((unsigned int)(v13450 - v13449) >> 31));
      v13448[v13493] = v13549;
      int * v13452 = v13376->cache_age;
      int v13453 = v13452[v13494];
      int v13551 = v13453 + ((int)((unsigned int)(v13453 - v13449) >> 31));
      v13452[v13494] = v13551;
      int * v13455 = v13376->cache_age;
      v13455[v13519] = 0;
      v13458 = v13519;
    }
    int * v13459 = v13376->cache_vals;
    int v13554 = v13458 * 2;
    int v13460 = v13459[v13554];
    int v13555 = (v13458 * 2) + 1;
    int v13461 = v13459[v13555];
    int v13556 = (((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v13400 + ((~(((v13402 ^ -1) | (-(v13402 ^ -1))) >> 31)) & 2)) - (v13403 + ((~(((v13404 ^ -1) | (-(v13404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v13459[v13556] = v13460;
    int * v13463 = v13376->cache_vals;
    int v13559 = ((((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v13400 + ((~(((v13402 ^ -1) | (-(v13402 ^ -1))) >> 31)) & 2)) - (v13403 + ((~(((v13404 ^ -1) | (-(v13404 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v13463[v13559] = v13461;
    int * v13465 = v13376->cache_tags;
    int v13562 = ((((int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v13400 + ((~(((v13402 ^ -1) | (-(v13402 ^ -1))) >> 31)) & 2)) - (v13403 + ((~(((v13404 ^ -1) | (-(v13404 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v13563 = (int)((unsigned int)((int)((unsigned int)(v13380 + 40) >> 2)) >> 1);
    v13465[v13562] = v13563;
    int * v13467 = v13376->cache_dirty;
    v13467[v13562] = 0;
    int * v13469 = v13376->cache_age;
    v13469[v13562] = 1;
    int * v13471 = v13376->cache_age;
    int v13472 = v13471[v13562];
    int v13473 = v13471[v13491];
    int v13569 = v13473 + ((int)((unsigned int)(v13473 - v13472) >> 31));
    v13471[v13491] = v13569;
    int * v13475 = v13376->cache_age;
    int v13476 = v13475[v13492];
    int v13571 = v13476 + ((int)((unsigned int)(v13476 - v13472) >> 31));
    v13475[v13492] = v13571;
    int * v13478 = v13376->cache_age;
    v13478[v13562] = 0;
    v13481 = v13562;
  }
  int v13574 = (v13481 * 2) + (((int)((unsigned int)(v13380 + 40) >> 2)) & 1);
  int v13482 = v13388[v13574];
  int * v13483 = v13376->regs;
  v13483[9] = v13482;
  struct StateT * v13485 = slot_231(v13376);
  return v13485;
}

struct StateT * slot_134(struct StateT * v7168) {
  int v7169 = v7168->timer;
  int v7177 = v7169 + 1;
  v7168->timer = v7177;
  int * v7171 = v7168->regs;
  int v7172 = v7171[12];
  int v7173 = v7171[29];
  int v7182 = v7172 + v7173;
  v7171[21] = v7182;
  struct StateT * v7175 = slot_135(v7168);
  return v7175;
}

struct StateT * slot_463(struct StateT * v20725) {
  int v20726 = v20725->timer;
  int v20733 = v20726 + 1;
  v20725->timer = v20733;
  int * v20728 = v20725->regs;
  int v20729 = v20728[20];
  int v20737 = (int)((unsigned int)v20729 >> 14);
  v20728[24] = v20737;
  struct StateT * v20731 = slot_464(v20725);
  return v20731;
}

struct StateT * slot_175(struct StateT * v7809) {
  int v7810 = v7809->timer;
  int v7818 = v7810 + 1;
  v7809->timer = v7818;
  int * v7812 = v7809->regs;
  int v7813 = v7812[18];
  int v7814 = v7812[6];
  int v7823 = v7813 + v7814;
  v7812[22] = v7823;
  struct StateT * v7816 = slot_176(v7809);
  return v7816;
}

struct StateT * slot_387(struct StateT * v19426) {
  int v19427 = v19426->timer;
  int v19434 = v19427 + 1;
  v19426->timer = v19434;
  int * v19429 = v19426->regs;
  int v19430 = v19429[22];
  int v19438 = (int)((unsigned int)v19430 >> 14);
  v19429[24] = v19438;
  struct StateT * v19432 = slot_388(v19426);
  return v19432;
}

struct StateT * slot_273(struct StateT * v17644) {
  int v17645 = v17644->timer;
  int v17653 = v17645 + 1;
  v17644->timer = v17653;
  int * v17647 = v17644->regs;
  int v17648 = v17647[6];
  int v17649 = v17647[20];
  int v17657 = v17648 ^ v17649;
  v17647[6] = v17657;
  struct StateT * v17651 = slot_274(v17644);
  return v17651;
}

struct StateT * slot_69(struct StateT * v6067) {
  int * v6068 = v6067->saved_regs;
  int * v6069 = v6067->regs;
  int v6070 = v6069[6];
  v6068[6] = v6070;
  int v6072 = v6067->timer;
  int v6084 = v6072 + 1;
  v6067->timer = v6084;
  int * v6074 = v6067->regs;
  int v6075 = v6074[6];
  int v6076 = v6074[20];
  int v6087 = v6075 ^ v6076;
  v6074[6] = v6087;
  struct StateT * v6078 = slot_70(v6067);
  return v6078;
}

struct StateT * slot_188(struct StateT * v8007) {
  int v8008 = v8007->timer;
  int v8016 = v8008 + 1;
  v8007->timer = v8016;
  int * v8010 = v8007->regs;
  int v8011 = v8010[23];
  int v8012 = v8010[24];
  int v8020 = v8011 | v8012;
  v8010[23] = v8020;
  struct StateT * v8014 = slot_189(v8007);
  return v8014;
}

struct StateT * slot_495(struct StateT * v21245) {
  int v21246 = v21245->timer;
  int v21254 = v21246 + 1;
  v21245->timer = v21254;
  int * v21248 = v21245->regs;
  int v21249 = v21248[14];
  int v21250 = v21248[20];
  int v21258 = v21249 ^ v21250;
  v21248[14] = v21258;
  struct StateT * v21252 = slot_496(v21245);
  return v21252;
}

struct StateT * slot_186(struct StateT * v7978) {
  int v7979 = v7978->timer;
  int v7986 = v7979 + 1;
  v7978->timer = v7986;
  int * v7981 = v7978->regs;
  int v7982 = v7981[23];
  int v7990 = (int)((unsigned int)v7982 >> 14);
  v7981[24] = v7990;
  struct StateT * v7984 = slot_187(v7978);
  return v7984;
}

struct StateT * slot_102(struct StateT * v6641) {
  int v6642 = v6641->timer;
  int v6650 = v6642 + 1;
  v6641->timer = v6650;
  int * v6644 = v6641->regs;
  int v6645 = v6644[21];
  int v6646 = v6644[24];
  int v6654 = v6645 | v6646;
  v6644[21] = v6654;
  struct StateT * v6648 = slot_103(v6641);
  return v6648;
}

struct StateT * slot_145(struct StateT * v7338) {
  int v7339 = v7338->timer;
  int v7347 = v7339 + 1;
  v7338->timer = v7347;
  int * v7341 = v7338->regs;
  int v7342 = v7341[22];
  int v7343 = v7341[24];
  int v7351 = v7342 | v7343;
  v7341[22] = v7351;
  struct StateT * v7345 = slot_146(v7338);
  return v7345;
}

struct StateT * slot_110(struct StateT * v6770) {
  int * v6771 = v6770->saved_regs;
  int * v6772 = v6770->regs;
  int v6773 = v6772[29];
  v6771[29] = v6773;
  int v6775 = v6770->timer;
  int v6787 = v6775 + 1;
  v6770->timer = v6787;
  int * v6777 = v6770->regs;
  int v6778 = v6777[29];
  int v6779 = v6777[21];
  int v6790 = v6778 ^ v6779;
  v6777[29] = v6790;
  struct StateT * v6781 = slot_111(v6770);
  return v6781;
}

struct StateT * slot_301(struct StateT * v18088) {
  int v18089 = v18088->timer;
  int v18096 = v18089 + 1;
  v18088->timer = v18096;
  int * v18091 = v18088->regs;
  int v18092 = v18091[20];
  int v18100 = (int)((unsigned int)v18092 >> 14);
  v18091[24] = v18100;
  struct StateT * v18094 = slot_302(v18088);
  return v18094;
}

struct StateT * slot_502(struct StateT * v21360) {
  int v21361 = v21360->timer;
  int v21369 = v21361 + 1;
  v21360->timer = v21369;
  int * v21363 = v21360->regs;
  int v21364 = v21363[16];
  int v21365 = v21363[31];
  int v21374 = v21364 + v21365;
  v21363[23] = v21374;
  struct StateT * v21367 = slot_503(v21360);
  return v21367;
}

struct StateT * slot_506(struct StateT * v21422) {
  int v21423 = v21422->timer;
  int v21430 = v21423 + 1;
  v21422->timer = v21430;
  int * v21425 = v21422->regs;
  int v21426 = v21425[21];
  int v21434 = (int)((unsigned int)v21426 >> 23);
  v21425[24] = v21434;
  struct StateT * v21428 = slot_507(v21422);
  return v21428;
}

struct StateT * slot_413(struct StateT * v19855) {
  int v19856 = v19855->timer;
  int v19863 = v19856 + 1;
  v19855->timer = v19863;
  int * v19858 = v19855->regs;
  int v19859 = v19858[23];
  int v19866 = v19859 << 7;
  v19858[23] = v19866;
  struct StateT * v19861 = slot_414(v19855);
  return v19861;
}

struct StateT * slot_320(struct StateT * v18383) {
  int v18384 = v18383->timer;
  int v18392 = v18384 + 1;
  v18383->timer = v18392;
  int * v18386 = v18383->regs;
  int v18387 = v18386[31];
  int v18388 = v18386[19];
  int v18397 = v18387 + v18388;
  v18386[23] = v18397;
  struct StateT * v18390 = slot_321(v18383);
  return v18390;
}

struct StateT * slot_281(struct StateT * v17776) {
  int v17777 = v17776->timer;
  int v17784 = v17777 + 1;
  v17776->timer = v17784;
  int * v17779 = v17776->regs;
  int v17780 = v17779[20];
  int v17788 = (int)((unsigned int)v17780 >> 19);
  v17779[24] = v17788;
  struct StateT * v17782 = slot_282(v17776);
  return v17782;
}

struct StateT * slot_533(struct StateT * v21839) {
  int v21840 = v21839->timer;
  int v21847 = v21840 + 1;
  v21839->timer = v21847;
  int * v21842 = v21839->regs;
  int v21843 = v21842[23];
  int v21850 = v21843 << 13;
  v21842[23] = v21850;
  struct StateT * v21845 = slot_534(v21839);
  return v21845;
}

struct StateT * slot_203(struct StateT * v9926) {
  int v9927 = v9926->timer;
  int v9935 = v9927 + 1;
  v9926->timer = v9935;
  int * v9929 = v9926->regs;
  int v9930 = v9929[29];
  int v9931 = v9929[14];
  int v9940 = v9930 + v9931;
  v9929[21] = v9940;
  struct StateT * v9933 = slot_206(v9926);
  return v9933;
}

struct StateT * slot_190(struct StateT * v8039) {
  int v8040 = v8039->timer;
  int v8048 = v8040 + 1;
  v8039->timer = v8048;
  int * v8042 = v8039->regs;
  int v8043 = v8042[29];
  int v8044 = v8042[21];
  int v8052 = v8043 ^ v8044;
  v8042[29] = v8052;
  struct StateT * v8046 = slot_191(v8039);
  return v8046;
}

struct StateT * slot_157(struct StateT * v7531) {
  int v7532 = v7531->timer;
  int v7539 = v7532 + 1;
  v7531->timer = v7539;
  int * v7534 = v7531->regs;
  int v7535 = v7534[20];
  int v7543 = (int)((unsigned int)v7535 >> 19);
  v7534[24] = v7543;
  struct StateT * v7537 = slot_158(v7531);
  return v7537;
}

struct StateT * slot_447(struct StateT * v20445) {
  int v20446 = v20445->timer;
  int v20453 = v20446 + 1;
  v20445->timer = v20453;
  int * v20448 = v20445->regs;
  int v20449 = v20448[21];
  int v20456 = v20449 << 13;
  v20448[21] = v20456;
  struct StateT * v20451 = slot_448(v20445);
  return v20451;
}

struct StateT * slot_559(struct StateT * v22245) {
  int * v22246 = v22245->saved_regs;
  int * v22247 = v22245->regs;
  int v22248 = v22247[13];
  v22246[13] = v22248;
  int v22250 = v22245->timer;
  int v22261 = v22250 + 1;
  v22245->timer = v22261;
  int * v22252 = v22245->regs;
  int v22253 = v22252[13];
  int v22263 = v22253 + 1;
  v22252[13] = v22263;
  struct StateT * v22255 = slot_560(v22245);
  return v22255;
}

struct StateT * slot_243(struct StateT * v16666) {
  int v16667 = v16666->timer;
  int v16777 = v16667 + 1;
  v16666->timer = v16777;
  int * v16669 = v16666->regs;
  int v16670 = v16669[2];
  int * v16671 = v16666->cache_tags;
  int v16781 = (((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2;
  int v16672 = v16671[v16781];
  int v16782 = ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16673 = v16671[v16782];
  int v16783 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2);
  int v16674 = v16671[v16783];
  int v16784 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16675 = v16671[v16784];
  int v16676 = v16666->timer;
  int v16785 = v16676 + ((100 ^ (((~(((v16674 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16674 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16672 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16672 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16673 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16673 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16674 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16674 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16666->timer = v16785;
  int * v16678 = v16666->cache_vals;
  bool v16786 = !(((~(((v16672 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16672 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16673 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16673 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v16771;
  if (v16786) {
    int * v16679 = v16666->cache_age;
    int v16788 = ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v16673 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16673 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v16680 = v16679[v16788];
    int v16681 = v16679[v16781];
    int v16789 = v16681 + ((int)((unsigned int)(v16681 - v16680) >> 31));
    v16679[v16781] = v16789;
    int * v16683 = v16666->cache_age;
    int v16684 = v16683[v16782];
    int v16791 = v16684 + ((int)((unsigned int)(v16684 - v16680) >> 31));
    v16683[v16782] = v16791;
    int * v16686 = v16666->cache_age;
    v16686[v16788] = 0;
    v16771 = v16788;
  } else {
    int * v16689 = v16666->cache_age;
    int v16795 = (((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2;
    int v16690 = v16689[v16795];
    int * v16691 = v16666->cache_tags;
    int v16692 = v16691[v16795];
    int v16693 = v16689[v16782];
    int v16694 = v16691[v16782];
    bool v16797 = !(((~(((v16674 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16674 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v16748;
    if (v16797) {
      int * v16695 = v16666->cache_age;
      int v16799 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))) | (-(v16675 ^ ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v16696 = v16695[v16799];
      int v16697 = v16695[v16783];
      int v16800 = v16697 + ((int)((unsigned int)(v16697 - v16696) >> 31));
      v16695[v16783] = v16800;
      int * v16699 = v16666->cache_age;
      int v16700 = v16699[v16784];
      int v16802 = v16700 + ((int)((unsigned int)(v16700 - v16696) >> 31));
      v16699[v16784] = v16802;
      int * v16702 = v16666->cache_age;
      v16702[v16799] = 0;
      v16748 = v16799;
    } else {
      int * v16705 = v16666->cache_age;
      int v16806 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2);
      int v16706 = v16705[v16806];
      int * v16707 = v16666->cache_tags;
      int v16708 = v16707[v16806];
      int v16709 = v16705[v16784];
      int v16710 = v16707[v16784];
      int * v16711 = v16666->cache_dirty;
      int v16809 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16706 + ((~(((v16708 ^ -1) | (-(v16708 ^ -1))) >> 31)) & 2)) - (v16709 + ((~(((v16710 ^ -1) | (-(v16710 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16712 = v16711[v16809];
      bool v16810 = !(v16712 == 0);
      if (v16810) {
        int * v16713 = v16666->cache_tags;
        int v16714 = v16713[v16809];
        int * v16715 = v16666->cache_vals;
        int v16813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16706 + ((~(((v16708 ^ -1) | (-(v16708 ^ -1))) >> 31)) & 2)) - (v16709 + ((~(((v16710 ^ -1) | (-(v16710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16716 = v16715[v16813];
        int v16814 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16706 + ((~(((v16708 ^ -1) | (-(v16708 ^ -1))) >> 31)) & 2)) - (v16709 + ((~(((v16710 ^ -1) | (-(v16710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16717 = v16715[v16814];
        int * v16718 = v16666->mem;
        int v16816 = v16714 * 2;
        v16718[v16816] = v16716;
        int * v16720 = v16666->mem;
        int v16819 = (v16714 * 2) + 1;
        v16720[v16819] = v16717;
        ;
      } else {
        ;
      }
      int * v16725 = v16666->mem;
      int v16824 = ((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) * 2;
      int v16726 = v16725[v16824];
      int v16825 = (((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) * 2) + 1;
      int v16727 = v16725[v16825];
      int * v16728 = v16666->cache_vals;
      int v16827 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16706 + ((~(((v16708 ^ -1) | (-(v16708 ^ -1))) >> 31)) & 2)) - (v16709 + ((~(((v16710 ^ -1) | (-(v16710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16728[v16827] = v16726;
      int * v16730 = v16666->cache_vals;
      int v16830 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v16706 + ((~(((v16708 ^ -1) | (-(v16708 ^ -1))) >> 31)) & 2)) - (v16709 + ((~(((v16710 ^ -1) | (-(v16710 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16730[v16830] = v16727;
      int * v16732 = v16666->cache_tags;
      int v16833 = (int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1);
      v16732[v16809] = v16833;
      int * v16734 = v16666->cache_dirty;
      v16734[v16809] = 0;
      int * v16736 = v16666->cache_age;
      v16736[v16809] = 1;
      int * v16738 = v16666->cache_age;
      int v16739 = v16738[v16809];
      int v16740 = v16738[v16783];
      int v16839 = v16740 + ((int)((unsigned int)(v16740 - v16739) >> 31));
      v16738[v16783] = v16839;
      int * v16742 = v16666->cache_age;
      int v16743 = v16742[v16784];
      int v16841 = v16743 + ((int)((unsigned int)(v16743 - v16739) >> 31));
      v16742[v16784] = v16841;
      int * v16745 = v16666->cache_age;
      v16745[v16809] = 0;
      v16748 = v16809;
    }
    int * v16749 = v16666->cache_vals;
    int v16844 = v16748 * 2;
    int v16750 = v16749[v16844];
    int v16845 = (v16748 * 2) + 1;
    int v16751 = v16749[v16845];
    int v16846 = (((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v16690 + ((~(((v16692 ^ -1) | (-(v16692 ^ -1))) >> 31)) & 2)) - (v16693 + ((~(((v16694 ^ -1) | (-(v16694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16749[v16846] = v16750;
    int * v16753 = v16666->cache_vals;
    int v16849 = ((((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v16690 + ((~(((v16692 ^ -1) | (-(v16692 ^ -1))) >> 31)) & 2)) - (v16693 + ((~(((v16694 ^ -1) | (-(v16694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16753[v16849] = v16751;
    int * v16755 = v16666->cache_tags;
    int v16852 = ((((int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v16690 + ((~(((v16692 ^ -1) | (-(v16692 ^ -1))) >> 31)) & 2)) - (v16693 + ((~(((v16694 ^ -1) | (-(v16694 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16853 = (int)((unsigned int)((int)((unsigned int)(v16670 + 20) >> 2)) >> 1);
    v16755[v16852] = v16853;
    int * v16757 = v16666->cache_dirty;
    v16757[v16852] = 0;
    int * v16759 = v16666->cache_age;
    v16759[v16852] = 1;
    int * v16761 = v16666->cache_age;
    int v16762 = v16761[v16852];
    int v16763 = v16761[v16781];
    int v16859 = v16763 + ((int)((unsigned int)(v16763 - v16762) >> 31));
    v16761[v16781] = v16859;
    int * v16765 = v16666->cache_age;
    int v16766 = v16765[v16782];
    int v16861 = v16766 + ((int)((unsigned int)(v16766 - v16762) >> 31));
    v16765[v16782] = v16861;
    int * v16768 = v16666->cache_age;
    v16768[v16852] = 0;
    v16771 = v16852;
  }
  int v16864 = (v16771 * 2) + (((int)((unsigned int)(v16670 + 20) >> 2)) & 1);
  int v16772 = v16678[v16864];
  int * v16773 = v16666->regs;
  v16773[22] = v16772;
  struct StateT * v16775 = slot_238(v16666);
  return v16775;
}

struct StateT * slot_173(struct StateT * v7775) {
  int v7776 = v7775->timer;
  int v7784 = v7776 + 1;
  v7775->timer = v7784;
  int * v7778 = v7775->regs;
  int v7779 = v7778[8];
  int v7780 = v7778[17];
  int v7789 = v7779 + v7780;
  v7778[20] = v7789;
  struct StateT * v7782 = slot_174(v7775);
  return v7782;
}

struct StateT * slot_307(struct StateT * v18178) {
  int v18179 = v18178->timer;
  int v18186 = v18179 + 1;
  v18178->timer = v18186;
  int * v18181 = v18178->regs;
  int v18182 = v18181[22];
  int v18190 = (int)((unsigned int)v18182 >> 14);
  v18181[24] = v18190;
  struct StateT * v18184 = slot_308(v18178);
  return v18184;
}

struct StateT * slot_453(struct StateT * v20535) {
  int v20536 = v20535->timer;
  int v20543 = v20536 + 1;
  v20535->timer = v20543;
  int * v20538 = v20535->regs;
  int v20539 = v20538[23];
  int v20546 = v20539 << 13;
  v20538[23] = v20546;
  struct StateT * v20541 = slot_454(v20535);
  return v20541;
}

struct StateT * slot_54(struct StateT * v5836) {
  int v5837 = v5836->timer;
  int v5845 = v5837 + 1;
  v5836->timer = v5845;
  int * v5839 = v5836->regs;
  int v5840 = v5839[18];
  int v5841 = v5839[29];
  int v5850 = v5840 + v5841;
  v5839[21] = v5850;
  struct StateT * v5843 = slot_55(v5836);
  return v5843;
}

struct StateT * slot_26(struct StateT * v5351) {
  int v5352 = v5351->timer;
  int v5359 = v5352 + 1;
  v5351->timer = v5359;
  int * v5354 = v5351->regs;
  int v5355 = v5354[11];
  int v5363 = v5355 + -1947;
  v5354[30] = v5363;
  struct StateT * v5357 = slot_27(v5351);
  return v5357;
}

struct StateT * slot_370(struct StateT * v19159) {
  int v19160 = v19159->timer;
  int v19167 = v19160 + 1;
  v19159->timer = v19167;
  int * v19162 = v19159->regs;
  int v19163 = v19162[23];
  int v19171 = (int)((unsigned int)v19163 >> 19);
  v19162[24] = v19171;
  struct StateT * v19165 = slot_371(v19159);
  return v19165;
}

struct StateT * slot_206(struct StateT * v10573) {
  int v10574 = v10573->timer;
  int v10582 = v10574 + 1;
  v10573->timer = v10582;
  int * v10576 = v10573->regs;
  int v10577 = v10576[28];
  int v10578 = v10576[12];
  int v10587 = v10577 + v10578;
  v10576[22] = v10587;
  struct StateT * v10580 = slot_209(v10573);
  return v10580;
}

struct StateT * slot_227(struct StateT * v14536) {
  int v14537 = v14536->timer;
  int v14545 = v14537 + 1;
  v14536->timer = v14545;
  int * v14539 = v14536->regs;
  int v14540 = v14539[21];
  int v14541 = v14539[24];
  int v14549 = v14540 | v14541;
  v14539[21] = v14549;
  struct StateT * v14543 = slot_230(v14536);
  return v14543;
}

struct StateT * slot_169(struct StateT * v7711) {
  int v7712 = v7711->timer;
  int v7720 = v7712 + 1;
  v7711->timer = v7720;
  int * v7714 = v7711->regs;
  int v7715 = v7714[8];
  int v7716 = v7714[20];
  int v7724 = v7715 ^ v7716;
  v7714[8] = v7724;
  struct StateT * v7718 = slot_170(v7711);
  return v7718;
}

struct StateT * slot_442(struct StateT * v20368) {
  int v20369 = v20368->timer;
  int v20377 = v20369 + 1;
  v20368->timer = v20377;
  int * v20371 = v20368->regs;
  int v20372 = v20371[5];
  int v20373 = v20371[8];
  int v20382 = v20372 + v20373;
  v20371[23] = v20382;
  struct StateT * v20375 = slot_443(v20368);
  return v20375;
}

struct StateT * slot_529(struct StateT * v21779) {
  int v21780 = v21779->timer;
  int v21787 = v21780 + 1;
  v21779->timer = v21787;
  int * v21782 = v21779->regs;
  int v21783 = v21782[22];
  int v21791 = (int)((unsigned int)v21783 >> 19);
  v21782[24] = v21791;
  struct StateT * v21785 = slot_530(v21779);
  return v21785;
}

struct StateT * slot_14(struct StateT * v3476) {
  int v3477 = v3476->timer;
  int v3587 = v3477 + 1;
  v3476->timer = v3587;
  int * v3479 = v3476->regs;
  int v3480 = v3479[12];
  int * v3481 = v3476->cache_tags;
  int v3591 = (((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2;
  int v3482 = v3481[v3591];
  int v3592 = ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3483 = v3481[v3592];
  int v3593 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2);
  int v3484 = v3481[v3593];
  int v3594 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3485 = v3481[v3594];
  int v3486 = v3476->timer;
  int v3595 = v3486 + ((100 ^ (((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3476->timer = v3595;
  int * v3488 = v3476->cache_vals;
  bool v3596 = !(((~(((v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3581;
  if (v3596) {
    int * v3489 = v3476->cache_age;
    int v3598 = ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3490 = v3489[v3598];
    int v3491 = v3489[v3591];
    int v3599 = v3491 + ((int)((unsigned int)(v3491 - v3490) >> 31));
    v3489[v3591] = v3599;
    int * v3493 = v3476->cache_age;
    int v3494 = v3493[v3592];
    int v3601 = v3494 + ((int)((unsigned int)(v3494 - v3490) >> 31));
    v3493[v3592] = v3601;
    int * v3496 = v3476->cache_age;
    v3496[v3598] = 0;
    v3581 = v3598;
  } else {
    int * v3499 = v3476->cache_age;
    int v3605 = (((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2;
    int v3500 = v3499[v3605];
    int * v3501 = v3476->cache_tags;
    int v3502 = v3501[v3605];
    int v3503 = v3499[v3592];
    int v3504 = v3501[v3592];
    bool v3607 = !(((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3558;
    if (v3607) {
      int * v3505 = v3476->cache_age;
      int v3609 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v3506 = v3505[v3609];
      int v3507 = v3505[v3593];
      int v3610 = v3507 + ((int)((unsigned int)(v3507 - v3506) >> 31));
      v3505[v3593] = v3610;
      int * v3509 = v3476->cache_age;
      int v3510 = v3509[v3594];
      int v3612 = v3510 + ((int)((unsigned int)(v3510 - v3506) >> 31));
      v3509[v3594] = v3612;
      int * v3512 = v3476->cache_age;
      v3512[v3609] = 0;
      v3558 = v3609;
    } else {
      int * v3515 = v3476->cache_age;
      int v3616 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3516 = v3515[v3616];
      int * v3517 = v3476->cache_tags;
      int v3518 = v3517[v3616];
      int v3519 = v3515[v3594];
      int v3520 = v3517[v3594];
      int * v3521 = v3476->cache_dirty;
      int v3619 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3522 = v3521[v3619];
      bool v3620 = !(v3522 == 0);
      if (v3620) {
        int * v3523 = v3476->cache_tags;
        int v3524 = v3523[v3619];
        int * v3525 = v3476->cache_vals;
        int v3623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3526 = v3525[v3623];
        int v3624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3527 = v3525[v3624];
        int * v3528 = v3476->mem;
        int v3626 = v3524 * 2;
        v3528[v3626] = v3526;
        int * v3530 = v3476->mem;
        int v3629 = (v3524 * 2) + 1;
        v3530[v3629] = v3527;
        ;
      } else {
        ;
      }
      int * v3535 = v3476->mem;
      int v3634 = ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) * 2;
      int v3536 = v3535[v3634];
      int v3635 = (((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3537 = v3535[v3635];
      int * v3538 = v3476->cache_vals;
      int v3637 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3538[v3637] = v3536;
      int * v3540 = v3476->cache_vals;
      int v3640 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3540[v3640] = v3537;
      int * v3542 = v3476->cache_tags;
      int v3643 = (int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1);
      v3542[v3619] = v3643;
      int * v3544 = v3476->cache_dirty;
      v3544[v3619] = 0;
      int * v3546 = v3476->cache_age;
      v3546[v3619] = 1;
      int * v3548 = v3476->cache_age;
      int v3549 = v3548[v3619];
      int v3550 = v3548[v3593];
      int v3649 = v3550 + ((int)((unsigned int)(v3550 - v3549) >> 31));
      v3548[v3593] = v3649;
      int * v3552 = v3476->cache_age;
      int v3553 = v3552[v3594];
      int v3651 = v3553 + ((int)((unsigned int)(v3553 - v3549) >> 31));
      v3552[v3594] = v3651;
      int * v3555 = v3476->cache_age;
      v3555[v3619] = 0;
      v3558 = v3619;
    }
    int * v3559 = v3476->cache_vals;
    int v3654 = v3558 * 2;
    int v3560 = v3559[v3654];
    int v3655 = (v3558 * 2) + 1;
    int v3561 = v3559[v3655];
    int v3656 = (((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3500 + ((~(((v3502 ^ -1) | (-(v3502 ^ -1))) >> 31)) & 2)) - (v3503 + ((~(((v3504 ^ -1) | (-(v3504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3559[v3656] = v3560;
    int * v3563 = v3476->cache_vals;
    int v3659 = ((((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3500 + ((~(((v3502 ^ -1) | (-(v3502 ^ -1))) >> 31)) & 2)) - (v3503 + ((~(((v3504 ^ -1) | (-(v3504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3563[v3659] = v3561;
    int * v3565 = v3476->cache_tags;
    int v3662 = ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3500 + ((~(((v3502 ^ -1) | (-(v3502 ^ -1))) >> 31)) & 2)) - (v3503 + ((~(((v3504 ^ -1) | (-(v3504 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3663 = (int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1);
    v3565[v3662] = v3663;
    int * v3567 = v3476->cache_dirty;
    v3567[v3662] = 0;
    int * v3569 = v3476->cache_age;
    v3569[v3662] = 1;
    int * v3571 = v3476->cache_age;
    int v3572 = v3571[v3662];
    int v3573 = v3571[v3591];
    int v3669 = v3573 + ((int)((unsigned int)(v3573 - v3572) >> 31));
    v3571[v3591] = v3669;
    int * v3575 = v3476->cache_age;
    int v3576 = v3575[v3592];
    int v3671 = v3576 + ((int)((unsigned int)(v3576 - v3572) >> 31));
    v3575[v3592] = v3671;
    int * v3578 = v3476->cache_age;
    v3578[v3662] = 0;
    v3581 = v3662;
  }
  int v3674 = (v3581 * 2) + (((int)((unsigned int)(v3480 + 12) >> 2)) & 1);
  int v3582 = v3488[v3674];
  int * v3583 = v3476->regs;
  v3583[9] = v3582;
  struct StateT * v3585 = slot_15(v3476);
  return v3585;
}

struct StateT * slot_357(struct StateT * v18956) {
  int v18957 = v18956->timer;
  int v18965 = v18957 + 1;
  v18956->timer = v18965;
  int * v18959 = v18956->regs;
  int v18960 = v18959[17];
  int v18961 = v18959[14];
  int v18970 = v18960 + v18961;
  v18959[20] = v18970;
  struct StateT * v18963 = slot_358(v18956);
  return v18963;
}

struct StateT * slot_385(struct StateT * v19396) {
  int v19397 = v19396->timer;
  int v19404 = v19397 + 1;
  v19396->timer = v19404;
  int * v19399 = v19396->regs;
  int v19400 = v19399[21];
  int v19407 = v19400 << 18;
  v19399[21] = v19407;
  struct StateT * v19402 = slot_386(v19396);
  return v19402;
}

struct StateT * slot_444(struct StateT * v20400) {
  int v20401 = v20400->timer;
  int v20408 = v20401 + 1;
  v20400->timer = v20408;
  int * v20403 = v20400->regs;
  int v20404 = v20403[20];
  int v20411 = v20404 << 13;
  v20403[20] = v20411;
  struct StateT * v20406 = slot_445(v20400);
  return v20406;
}

struct StateT * slot_261(struct StateT * v17464) {
  int v17465 = v17464->timer;
  int v17472 = v17465 + 1;
  v17464->timer = v17472;
  int * v17467 = v17464->regs;
  int v17468 = v17467[20];
  int v17476 = (int)((unsigned int)v17468 >> 23);
  v17467[24] = v17476;
  struct StateT * v17470 = slot_262(v17464);
  return v17470;
}

struct StateT * slot_287(struct StateT * v17866) {
  int v17867 = v17866->timer;
  int v17874 = v17867 + 1;
  v17866->timer = v17874;
  int * v17869 = v17866->regs;
  int v17870 = v17869[22];
  int v17878 = (int)((unsigned int)v17870 >> 19);
  v17869[24] = v17878;
  struct StateT * v17872 = slot_288(v17866);
  return v17872;
}

struct StateT * slot_343(struct StateT * v18741) {
  int v18742 = v18741->timer;
  int v18750 = v18742 + 1;
  v18741->timer = v18750;
  int * v18744 = v18741->regs;
  int v18745 = v18744[20];
  int v18746 = v18744[24];
  int v18754 = v18745 | v18746;
  v18744[20] = v18754;
  struct StateT * v18748 = slot_344(v18741);
  return v18748;
}

struct StateT * slot_36(struct StateT * v5516) {
  int * v5517 = v5516->saved_regs;
  int * v5518 = v5516->regs;
  int v5519 = v5518[23];
  v5517[23] = v5519;
  int v5521 = v5516->timer;
  int v5533 = v5521 + 1;
  v5516->timer = v5533;
  int * v5523 = v5516->regs;
  int v5524 = v5523[31];
  int v5525 = v5523[15];
  int v5537 = v5524 + v5525;
  v5523[23] = v5537;
  struct StateT * v5527 = slot_37(v5516);
  return v5527;
}

struct StateT * slot_57(struct StateT * v5887) {
  int v5888 = v5887->timer;
  int v5895 = v5888 + 1;
  v5887->timer = v5895;
  int * v5890 = v5887->regs;
  int v5891 = v5890[20];
  int v5899 = (int)((unsigned int)v5891 >> 23);
  v5890[24] = v5899;
  struct StateT * v5893 = slot_58(v5887);
  return v5893;
}

struct StateT * slot_426(struct StateT * v20090) {
  int v20091 = v20090->timer;
  int v20098 = v20091 + 1;
  v20090->timer = v20098;
  int * v20093 = v20090->regs;
  int v20094 = v20093[21];
  int v20102 = (int)((unsigned int)v20094 >> 23);
  v20093[24] = v20102;
  struct StateT * v20096 = slot_427(v20090);
  return v20096;
}

struct StateT * slot_536(struct StateT * v21885) {
  int v21886 = v21885->timer;
  int v21894 = v21886 + 1;
  v21885->timer = v21894;
  int * v21888 = v21885->regs;
  int v21889 = v21888[9];
  int v21890 = v21888[21];
  int v21898 = v21889 ^ v21890;
  v21888[9] = v21898;
  struct StateT * v21892 = slot_537(v21885);
  return v21892;
}

struct StateT * slot_470(struct StateT * v20830) {
  int v20831 = v20830->timer;
  int v20838 = v20831 + 1;
  v20830->timer = v20838;
  int * v20833 = v20830->regs;
  int v20834 = v20833[22];
  int v20841 = v20834 << 18;
  v20833[22] = v20841;
  struct StateT * v20836 = slot_471(v20830);
  return v20836;
}

struct StateT * slot_431(struct StateT * v20164) {
  int v20165 = v20164->timer;
  int v20173 = v20165 + 1;
  v20164->timer = v20173;
  int * v20167 = v20164->regs;
  int v20168 = v20167[22];
  int v20169 = v20167[24];
  int v20177 = v20168 | v20169;
  v20167[22] = v20177;
  struct StateT * v20171 = slot_432(v20164);
  return v20171;
}

struct StateT * slot_62(struct StateT * v5961) {
  int v5962 = v5961->timer;
  int v5970 = v5962 + 1;
  v5961->timer = v5970;
  int * v5964 = v5961->regs;
  int v5965 = v5964[21];
  int v5966 = v5964[24];
  int v5974 = v5965 | v5966;
  v5964[21] = v5974;
  struct StateT * v5968 = slot_63(v5961);
  return v5968;
}

struct StateT * slot_308(struct StateT * v18193) {
  int v18194 = v18193->timer;
  int v18201 = v18194 + 1;
  v18193->timer = v18201;
  int * v18196 = v18193->regs;
  int v18197 = v18196[22];
  int v18204 = v18197 << 18;
  v18196[22] = v18204;
  struct StateT * v18199 = slot_309(v18193);
  return v18199;
}

struct StateT * slot_400(struct StateT * v19626) {
  int * v19627 = v19626->saved_regs;
  int * v19628 = v19626->regs;
  int v19629 = v19628[21];
  v19627[21] = v19629;
  int v19631 = v19626->timer;
  int v19643 = v19631 + 1;
  v19626->timer = v19643;
  int * v19633 = v19626->regs;
  int v19634 = v19633[29];
  int v19635 = v19633[14];
  int v19647 = v19634 + v19635;
  v19633[21] = v19647;
  struct StateT * v19637 = slot_401(v19626);
  return v19637;
}

struct StateT * slot_323(struct StateT * v18429) {
  int v18430 = v18429->timer;
  int v18438 = v18430 + 1;
  v18429->timer = v18438;
  int * v18432 = v18429->regs;
  int v18433 = v18432[20];
  int v18434 = v18432[24];
  int v18442 = v18433 | v18434;
  v18432[20] = v18442;
  struct StateT * v18436 = slot_324(v18429);
  return v18436;
}

struct StateT * slot_521(struct StateT * v21655) {
  int v21656 = v21655->timer;
  int v21664 = v21656 + 1;
  v21655->timer = v21664;
  int * v21658 = v21655->regs;
  int v21659 = v21658[6];
  int v21660 = v21658[15];
  int v21669 = v21659 + v21660;
  v21658[22] = v21669;
  struct StateT * v21662 = slot_522(v21655);
  return v21662;
}

struct StateT * slot_530(struct StateT * v21794) {
  int v21795 = v21794->timer;
  int v21802 = v21795 + 1;
  v21794->timer = v21802;
  int * v21797 = v21794->regs;
  int v21798 = v21797[22];
  int v21805 = v21798 << 13;
  v21797[22] = v21805;
  struct StateT * v21800 = slot_531(v21794);
  return v21800;
}

struct StateT * slot_23(struct StateT * v5312) {
  int v5313 = v5312->timer;
  int v5319 = v5313 + 1;
  v5312->timer = v5319;
  int * v5315 = v5312->regs;
  v5315[11] = 1634762752;
  struct StateT * v5317 = slot_24(v5312);
  return v5317;
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

struct StateT * slot_86(struct StateT * v6362) {
  int v6363 = v6362->timer;
  int v6370 = v6363 + 1;
  v6362->timer = v6370;
  int * v6365 = v6362->regs;
  int v6366 = v6365[23];
  int v6374 = (int)((unsigned int)v6366 >> 19);
  v6365[24] = v6374;
  struct StateT * v6368 = slot_87(v6362);
  return v6368;
}

struct StateT * slot_538(struct StateT * v21917) {
  int v21918 = v21917->timer;
  int v21926 = v21918 + 1;
  v21917->timer = v21926;
  int * v21920 = v21917->regs;
  int v21921 = v21920[19];
  int v21922 = v21920[23];
  int v21930 = v21921 ^ v21922;
  v21920[19] = v21930;
  struct StateT * v21924 = slot_539(v21917);
  return v21924;
}

struct StateT * slot_100(struct StateT * v6612) {
  int v6613 = v6612->timer;
  int v6620 = v6613 + 1;
  v6612->timer = v6620;
  int * v6615 = v6612->regs;
  int v6616 = v6615[21];
  int v6624 = (int)((unsigned int)v6616 >> 14);
  v6615[24] = v6624;
  struct StateT * v6618 = slot_101(v6612);
  return v6618;
}

struct StateT * slot_127(struct StateT * v7057) {
  int v7058 = v7057->timer;
  int v7065 = v7058 + 1;
  v7057->timer = v7065;
  int * v7060 = v7057->regs;
  int v7061 = v7060[23];
  int v7068 = v7061 << 7;
  v7060[23] = v7068;
  struct StateT * v7063 = slot_128(v7057);
  return v7063;
}

struct StateT * slot_411(struct StateT * v19824) {
  int v19825 = v19824->timer;
  int v19833 = v19825 + 1;
  v19824->timer = v19833;
  int * v19827 = v19824->regs;
  int v19828 = v19827[22];
  int v19829 = v19827[24];
  int v19837 = v19828 | v19829;
  v19827[22] = v19837;
  struct StateT * v19831 = slot_412(v19824);
  return v19831;
}

struct StateT * slot_13(struct StateT * v3272) {
  int v3273 = v3272->timer;
  int v3383 = v3273 + 1;
  v3272->timer = v3383;
  int * v3275 = v3272->regs;
  int v3276 = v3275[12];
  int * v3277 = v3272->cache_tags;
  int v3387 = (((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3278 = v3277[v3387];
  int v3388 = ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3279 = v3277[v3388];
  int v3389 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3280 = v3277[v3389];
  int v3390 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3281 = v3277[v3390];
  int v3282 = v3272->timer;
  int v3391 = v3282 + ((100 ^ (((~(((v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3272->timer = v3391;
  int * v3284 = v3272->cache_vals;
  bool v3392 = !(((~(((v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3377;
  if (v3392) {
    int * v3285 = v3272->cache_age;
    int v3394 = ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3286 = v3285[v3394];
    int v3287 = v3285[v3387];
    int v3395 = v3287 + ((int)((unsigned int)(v3287 - v3286) >> 31));
    v3285[v3387] = v3395;
    int * v3289 = v3272->cache_age;
    int v3290 = v3289[v3388];
    int v3397 = v3290 + ((int)((unsigned int)(v3290 - v3286) >> 31));
    v3289[v3388] = v3397;
    int * v3292 = v3272->cache_age;
    v3292[v3394] = 0;
    v3377 = v3394;
  } else {
    int * v3295 = v3272->cache_age;
    int v3401 = (((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3296 = v3295[v3401];
    int * v3297 = v3272->cache_tags;
    int v3298 = v3297[v3401];
    int v3299 = v3295[v3388];
    int v3300 = v3297[v3388];
    bool v3403 = !(((~(((v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3354;
    if (v3403) {
      int * v3301 = v3272->cache_age;
      int v3405 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3302 = v3301[v3405];
      int v3303 = v3301[v3389];
      int v3406 = v3303 + ((int)((unsigned int)(v3303 - v3302) >> 31));
      v3301[v3389] = v3406;
      int * v3305 = v3272->cache_age;
      int v3306 = v3305[v3390];
      int v3408 = v3306 + ((int)((unsigned int)(v3306 - v3302) >> 31));
      v3305[v3390] = v3408;
      int * v3308 = v3272->cache_age;
      v3308[v3405] = 0;
      v3354 = v3405;
    } else {
      int * v3311 = v3272->cache_age;
      int v3412 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3312 = v3311[v3412];
      int * v3313 = v3272->cache_tags;
      int v3314 = v3313[v3412];
      int v3315 = v3311[v3390];
      int v3316 = v3313[v3390];
      int * v3317 = v3272->cache_dirty;
      int v3415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3318 = v3317[v3415];
      bool v3416 = !(v3318 == 0);
      if (v3416) {
        int * v3319 = v3272->cache_tags;
        int v3320 = v3319[v3415];
        int * v3321 = v3272->cache_vals;
        int v3419 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3322 = v3321[v3419];
        int v3420 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3323 = v3321[v3420];
        int * v3324 = v3272->mem;
        int v3422 = v3320 * 2;
        v3324[v3422] = v3322;
        int * v3326 = v3272->mem;
        int v3425 = (v3320 * 2) + 1;
        v3326[v3425] = v3323;
        ;
      } else {
        ;
      }
      int * v3331 = v3272->mem;
      int v3430 = ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) * 2;
      int v3332 = v3331[v3430];
      int v3431 = (((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3333 = v3331[v3431];
      int * v3334 = v3272->cache_vals;
      int v3433 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3334[v3433] = v3332;
      int * v3336 = v3272->cache_vals;
      int v3436 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3336[v3436] = v3333;
      int * v3338 = v3272->cache_tags;
      int v3439 = (int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1);
      v3338[v3415] = v3439;
      int * v3340 = v3272->cache_dirty;
      v3340[v3415] = 0;
      int * v3342 = v3272->cache_age;
      v3342[v3415] = 1;
      int * v3344 = v3272->cache_age;
      int v3345 = v3344[v3415];
      int v3346 = v3344[v3389];
      int v3445 = v3346 + ((int)((unsigned int)(v3346 - v3345) >> 31));
      v3344[v3389] = v3445;
      int * v3348 = v3272->cache_age;
      int v3349 = v3348[v3390];
      int v3447 = v3349 + ((int)((unsigned int)(v3349 - v3345) >> 31));
      v3348[v3390] = v3447;
      int * v3351 = v3272->cache_age;
      v3351[v3415] = 0;
      v3354 = v3415;
    }
    int * v3355 = v3272->cache_vals;
    int v3450 = v3354 * 2;
    int v3356 = v3355[v3450];
    int v3451 = (v3354 * 2) + 1;
    int v3357 = v3355[v3451];
    int v3452 = (((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3296 + ((~(((v3298 ^ -1) | (-(v3298 ^ -1))) >> 31)) & 2)) - (v3299 + ((~(((v3300 ^ -1) | (-(v3300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3355[v3452] = v3356;
    int * v3359 = v3272->cache_vals;
    int v3455 = ((((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3296 + ((~(((v3298 ^ -1) | (-(v3298 ^ -1))) >> 31)) & 2)) - (v3299 + ((~(((v3300 ^ -1) | (-(v3300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3359[v3455] = v3357;
    int * v3361 = v3272->cache_tags;
    int v3458 = ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3296 + ((~(((v3298 ^ -1) | (-(v3298 ^ -1))) >> 31)) & 2)) - (v3299 + ((~(((v3300 ^ -1) | (-(v3300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3459 = (int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1);
    v3361[v3458] = v3459;
    int * v3363 = v3272->cache_dirty;
    v3363[v3458] = 0;
    int * v3365 = v3272->cache_age;
    v3365[v3458] = 1;
    int * v3367 = v3272->cache_age;
    int v3368 = v3367[v3458];
    int v3369 = v3367[v3387];
    int v3465 = v3369 + ((int)((unsigned int)(v3369 - v3368) >> 31));
    v3367[v3387] = v3465;
    int * v3371 = v3272->cache_age;
    int v3372 = v3371[v3388];
    int v3467 = v3372 + ((int)((unsigned int)(v3372 - v3368) >> 31));
    v3371[v3388] = v3467;
    int * v3374 = v3272->cache_age;
    v3374[v3458] = 0;
    v3377 = v3458;
  }
  int v3470 = (v3377 * 2) + (((int)((unsigned int)(v3276 + 8) >> 2)) & 1);
  int v3378 = v3284[v3470];
  int * v3379 = v3272->regs;
  v3379[8] = v3378;
  struct StateT * v3381 = slot_14(v3272);
  return v3381;
}

struct StateT * slot_449(struct StateT * v20475) {
  int v20476 = v20475->timer;
  int v20483 = v20476 + 1;
  v20475->timer = v20483;
  int * v20478 = v20475->regs;
  int v20479 = v20478[22];
  int v20487 = (int)((unsigned int)v20479 >> 19);
  v20478[24] = v20487;
  struct StateT * v20481 = slot_450(v20475);
  return v20481;
}

struct StateT * slot_460(struct StateT * v20674) {
  int v20675 = v20674->timer;
  int v20683 = v20675 + 1;
  v20674->timer = v20683;
  int * v20677 = v20674->regs;
  int v20678 = v20677[14];
  int v20679 = v20677[7];
  int v20688 = v20678 + v20679;
  v20677[21] = v20688;
  struct StateT * v20681 = slot_461(v20674);
  return v20681;
}

struct StateT * slot_109(struct StateT * v6747) {
  int * v6748 = v6747->saved_regs;
  int * v6749 = v6747->regs;
  int v6750 = v6749[30];
  v6748[30] = v6750;
  int v6752 = v6747->timer;
  int v6764 = v6752 + 1;
  v6747->timer = v6764;
  int * v6754 = v6747->regs;
  int v6755 = v6754[30];
  int v6756 = v6754[20];
  int v6767 = v6755 ^ v6756;
  v6754[30] = v6767;
  struct StateT * v6758 = slot_110(v6747);
  return v6758;
}

struct StateT * slot_474(struct StateT * v20889) {
  int v20890 = v20889->timer;
  int v20898 = v20890 + 1;
  v20889->timer = v20898;
  int * v20892 = v20889->regs;
  int v20893 = v20892[23];
  int v20894 = v20892[24];
  int v20902 = v20893 | v20894;
  v20892[23] = v20902;
  struct StateT * v20896 = slot_475(v20889);
  return v20896;
}

struct StateT * slot_174(struct StateT * v7792) {
  int v7793 = v7792->timer;
  int v7801 = v7793 + 1;
  v7792->timer = v7801;
  int * v7795 = v7792->regs;
  int v7796 = v7795[9];
  int v7797 = v7795[5];
  int v7806 = v7796 + v7797;
  v7795[21] = v7806;
  struct StateT * v7799 = slot_175(v7792);
  return v7799;
}

struct StateT * slot_42(struct StateT * v5621) {
  int v5622 = v5621->timer;
  int v5630 = v5622 + 1;
  v5621->timer = v5630;
  int * v5624 = v5621->regs;
  int v5625 = v5624[21];
  int v5626 = v5624[24];
  int v5634 = v5625 | v5626;
  v5624[21] = v5634;
  struct StateT * v5628 = slot_43(v5621);
  return v5628;
}

struct StateT * slot_224(struct StateT * v14114) {
  int v14115 = v14114->timer;
  int v14122 = v14115 + 1;
  v14114->timer = v14122;
  int * v14117 = v14114->regs;
  int v14118 = v14117[21];
  int v14125 = v14118 << 7;
  v14117[21] = v14125;
  struct StateT * v14120 = slot_227(v14114);
  return v14120;
}

struct StateT * slot_184(struct StateT * v7948) {
  int v7949 = v7948->timer;
  int v7956 = v7949 + 1;
  v7948->timer = v7956;
  int * v7951 = v7948->regs;
  int v7952 = v7951[22];
  int v7959 = v7952 << 18;
  v7951[22] = v7959;
  struct StateT * v7954 = slot_185(v7948);
  return v7954;
}

struct StateT * slot_462(struct StateT * v20708) {
  int v20709 = v20708->timer;
  int v20717 = v20709 + 1;
  v20708->timer = v20717;
  int * v20711 = v20708->regs;
  int v20712 = v20711[15];
  int v20713 = v20711[5];
  int v20722 = v20712 + v20713;
  v20711[23] = v20722;
  struct StateT * v20715 = slot_463(v20708);
  return v20715;
}

struct StateT * slot_165(struct StateT * v7650) {
  int v7651 = v7650->timer;
  int v7659 = v7651 + 1;
  v7650->timer = v7659;
  int * v7653 = v7650->regs;
  int v7654 = v7653[22];
  int v7655 = v7653[24];
  int v7663 = v7654 | v7655;
  v7653[22] = v7663;
  struct StateT * v7657 = slot_166(v7650);
  return v7657;
}

struct StateT * slot_557(struct StateT * v22213) {
  int v22214 = v22213->timer;
  int v22222 = v22214 + 1;
  v22213->timer = v22222;
  int * v22216 = v22213->regs;
  int v22217 = v22216[28];
  int v22218 = v22216[22];
  int v22226 = v22217 ^ v22218;
  v22216[28] = v22226;
  struct StateT * v22220 = slot_558(v22213);
  return v22220;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_393(struct StateT * v19516) {
  int v19517 = v19516->timer;
  int v19525 = v19517 + 1;
  v19516->timer = v19525;
  int * v19519 = v19516->regs;
  int v19520 = v19519[30];
  int v19521 = v19519[20];
  int v19529 = v19520 ^ v19521;
  v19519[30] = v19529;
  struct StateT * v19523 = slot_394(v19516);
  return v19523;
}

struct StateT * slot_507(struct StateT * v21437) {
  int v21438 = v21437->timer;
  int v21445 = v21438 + 1;
  v21437->timer = v21445;
  int * v21440 = v21437->regs;
  int v21441 = v21440[21];
  int v21448 = v21441 << 9;
  v21440[21] = v21448;
  struct StateT * v21443 = slot_508(v21437);
  return v21443;
}

struct StateT * slot_477(struct StateT * v20951) {
  int * v20952 = v20951->saved_regs;
  int * v20953 = v20951->regs;
  int v20954 = v20953[28];
  v20952[28] = v20954;
  int v20956 = v20951->timer;
  int v20968 = v20956 + 1;
  v20951->timer = v20968;
  int * v20958 = v20951->regs;
  int v20959 = v20958[28];
  int v20960 = v20958[22];
  int v20971 = v20959 ^ v20960;
  v20958[28] = v20971;
  struct StateT * v20962 = slot_478(v20951);
  return v20962;
}

struct StateT * slot_278(struct StateT * v17725) {
  int v17726 = v17725->timer;
  int v17734 = v17726 + 1;
  v17725->timer = v17734;
  int * v17728 = v17725->regs;
  int v17729 = v17728[7];
  int v17730 = v17728[18];
  int v17739 = v17729 + v17730;
  v17728[21] = v17739;
  struct StateT * v17732 = slot_279(v17725);
  return v17732;
}

struct StateT * slot_352(struct StateT * v18876) {
  int v18877 = v18876->timer;
  int v18885 = v18877 + 1;
  v18876->timer = v18885;
  int * v18879 = v18876->regs;
  int v18880 = v18879[23];
  int v18881 = v18879[24];
  int v18889 = v18880 | v18881;
  v18879[23] = v18889;
  struct StateT * v18883 = slot_353(v18876);
  return v18883;
}

struct StateT * slot_11(struct StateT * v2864) {
  int v2865 = v2864->timer;
  int v2975 = v2865 + 1;
  v2864->timer = v2975;
  int * v2867 = v2864->regs;
  int v2868 = v2867[12];
  int * v2869 = v2864->cache_tags;
  int v2979 = (((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2;
  int v2870 = v2869[v2979];
  int v2980 = ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2871 = v2869[v2980];
  int v2981 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2);
  int v2872 = v2869[v2981];
  int v2982 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2873 = v2869[v2982];
  int v2874 = v2864->timer;
  int v2983 = v2874 + ((100 ^ (((~(((v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2864->timer = v2983;
  int * v2876 = v2864->cache_vals;
  bool v2984 = !(((~(((v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) == 0);
  int v2969;
  if (v2984) {
    int * v2877 = v2864->cache_age;
    int v2986 = ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((~(((v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) & 1);
    int v2878 = v2877[v2986];
    int v2879 = v2877[v2979];
    int v2987 = v2879 + ((int)((unsigned int)(v2879 - v2878) >> 31));
    v2877[v2979] = v2987;
    int * v2881 = v2864->cache_age;
    int v2882 = v2881[v2980];
    int v2989 = v2882 + ((int)((unsigned int)(v2882 - v2878) >> 31));
    v2881[v2980] = v2989;
    int * v2884 = v2864->cache_age;
    v2884[v2986] = 0;
    v2969 = v2986;
  } else {
    int * v2887 = v2864->cache_age;
    int v2993 = (((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2;
    int v2888 = v2887[v2993];
    int * v2889 = v2864->cache_tags;
    int v2890 = v2889[v2993];
    int v2891 = v2887[v2980];
    int v2892 = v2889[v2980];
    bool v2995 = !(((~(((v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) == 0);
    int v2946;
    if (v2995) {
      int * v2893 = v2864->cache_age;
      int v2997 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) & 1);
      int v2894 = v2893[v2997];
      int v2895 = v2893[v2981];
      int v2998 = v2895 + ((int)((unsigned int)(v2895 - v2894) >> 31));
      v2893[v2981] = v2998;
      int * v2897 = v2864->cache_age;
      int v2898 = v2897[v2982];
      int v3000 = v2898 + ((int)((unsigned int)(v2898 - v2894) >> 31));
      v2897[v2982] = v3000;
      int * v2900 = v2864->cache_age;
      v2900[v2997] = 0;
      v2946 = v2997;
    } else {
      int * v2903 = v2864->cache_age;
      int v3004 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2);
      int v2904 = v2903[v3004];
      int * v2905 = v2864->cache_tags;
      int v2906 = v2905[v3004];
      int v2907 = v2903[v2982];
      int v2908 = v2905[v2982];
      int * v2909 = v2864->cache_dirty;
      int v3007 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2910 = v2909[v3007];
      bool v3008 = !(v2910 == 0);
      if (v3008) {
        int * v2911 = v2864->cache_tags;
        int v2912 = v2911[v3007];
        int * v2913 = v2864->cache_vals;
        int v3011 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2914 = v2913[v3011];
        int v3012 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2915 = v2913[v3012];
        int * v2916 = v2864->mem;
        int v3014 = v2912 * 2;
        v2916[v3014] = v2914;
        int * v2918 = v2864->mem;
        int v3017 = (v2912 * 2) + 1;
        v2918[v3017] = v2915;
        ;
      } else {
        ;
      }
      int * v2923 = v2864->mem;
      int v3022 = ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) * 2;
      int v2924 = v2923[v3022];
      int v3023 = (((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) * 2) + 1;
      int v2925 = v2923[v3023];
      int * v2926 = v2864->cache_vals;
      int v3025 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2926[v3025] = v2924;
      int * v2928 = v2864->cache_vals;
      int v3028 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2928[v3028] = v2925;
      int * v2930 = v2864->cache_tags;
      int v3031 = (int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1);
      v2930[v3007] = v3031;
      int * v2932 = v2864->cache_dirty;
      v2932[v3007] = 0;
      int * v2934 = v2864->cache_age;
      v2934[v3007] = 1;
      int * v2936 = v2864->cache_age;
      int v2937 = v2936[v3007];
      int v2938 = v2936[v2981];
      int v3037 = v2938 + ((int)((unsigned int)(v2938 - v2937) >> 31));
      v2936[v2981] = v3037;
      int * v2940 = v2864->cache_age;
      int v2941 = v2940[v2982];
      int v3039 = v2941 + ((int)((unsigned int)(v2941 - v2937) >> 31));
      v2940[v2982] = v3039;
      int * v2943 = v2864->cache_age;
      v2943[v3007] = 0;
      v2946 = v3007;
    }
    int * v2947 = v2864->cache_vals;
    int v3042 = v2946 * 2;
    int v2948 = v2947[v3042];
    int v3043 = (v2946 * 2) + 1;
    int v2949 = v2947[v3043];
    int v3044 = (((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((((v2888 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2)) - (v2891 + ((~(((v2892 ^ -1) | (-(v2892 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2947[v3044] = v2948;
    int * v2951 = v2864->cache_vals;
    int v3047 = ((((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((((v2888 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2)) - (v2891 + ((~(((v2892 ^ -1) | (-(v2892 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2951[v3047] = v2949;
    int * v2953 = v2864->cache_tags;
    int v3050 = ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((((v2888 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2)) - (v2891 + ((~(((v2892 ^ -1) | (-(v2892 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3051 = (int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1);
    v2953[v3050] = v3051;
    int * v2955 = v2864->cache_dirty;
    v2955[v3050] = 0;
    int * v2957 = v2864->cache_age;
    v2957[v3050] = 1;
    int * v2959 = v2864->cache_age;
    int v2960 = v2959[v3050];
    int v2961 = v2959[v2979];
    int v3057 = v2961 + ((int)((unsigned int)(v2961 - v2960) >> 31));
    v2959[v2979] = v3057;
    int * v2963 = v2864->cache_age;
    int v2964 = v2963[v2980];
    int v3059 = v2964 + ((int)((unsigned int)(v2964 - v2960) >> 31));
    v2963[v2980] = v3059;
    int * v2966 = v2864->cache_age;
    v2966[v3050] = 0;
    v2969 = v3050;
  }
  int v3062 = (v2969 * 2) + (((int)((unsigned int)v2868 >> 2)) & 1);
  int v2970 = v2876[v3062];
  int * v2971 = v2864->regs;
  v2971[14] = v2970;
  struct StateT * v2973 = slot_12(v2864);
  return v2973;
}

struct StateT * slot_12(struct StateT * v3068) {
  int v3069 = v3068->timer;
  int v3179 = v3069 + 1;
  v3068->timer = v3179;
  int * v3071 = v3068->regs;
  int v3072 = v3071[12];
  int * v3073 = v3068->cache_tags;
  int v3183 = (((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3074 = v3073[v3183];
  int v3184 = ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3075 = v3073[v3184];
  int v3185 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3076 = v3073[v3185];
  int v3186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3077 = v3073[v3186];
  int v3078 = v3068->timer;
  int v3187 = v3078 + ((100 ^ (((~(((v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3068->timer = v3187;
  int * v3080 = v3068->cache_vals;
  bool v3188 = !(((~(((v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3173;
  if (v3188) {
    int * v3081 = v3068->cache_age;
    int v3190 = ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3082 = v3081[v3190];
    int v3083 = v3081[v3183];
    int v3191 = v3083 + ((int)((unsigned int)(v3083 - v3082) >> 31));
    v3081[v3183] = v3191;
    int * v3085 = v3068->cache_age;
    int v3086 = v3085[v3184];
    int v3193 = v3086 + ((int)((unsigned int)(v3086 - v3082) >> 31));
    v3085[v3184] = v3193;
    int * v3088 = v3068->cache_age;
    v3088[v3190] = 0;
    v3173 = v3190;
  } else {
    int * v3091 = v3068->cache_age;
    int v3197 = (((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3092 = v3091[v3197];
    int * v3093 = v3068->cache_tags;
    int v3094 = v3093[v3197];
    int v3095 = v3091[v3184];
    int v3096 = v3093[v3184];
    bool v3199 = !(((~(((v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3150;
    if (v3199) {
      int * v3097 = v3068->cache_age;
      int v3201 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3098 = v3097[v3201];
      int v3099 = v3097[v3185];
      int v3202 = v3099 + ((int)((unsigned int)(v3099 - v3098) >> 31));
      v3097[v3185] = v3202;
      int * v3101 = v3068->cache_age;
      int v3102 = v3101[v3186];
      int v3204 = v3102 + ((int)((unsigned int)(v3102 - v3098) >> 31));
      v3101[v3186] = v3204;
      int * v3104 = v3068->cache_age;
      v3104[v3201] = 0;
      v3150 = v3201;
    } else {
      int * v3107 = v3068->cache_age;
      int v3208 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3108 = v3107[v3208];
      int * v3109 = v3068->cache_tags;
      int v3110 = v3109[v3208];
      int v3111 = v3107[v3186];
      int v3112 = v3109[v3186];
      int * v3113 = v3068->cache_dirty;
      int v3211 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3114 = v3113[v3211];
      bool v3212 = !(v3114 == 0);
      if (v3212) {
        int * v3115 = v3068->cache_tags;
        int v3116 = v3115[v3211];
        int * v3117 = v3068->cache_vals;
        int v3215 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3118 = v3117[v3215];
        int v3216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3119 = v3117[v3216];
        int * v3120 = v3068->mem;
        int v3218 = v3116 * 2;
        v3120[v3218] = v3118;
        int * v3122 = v3068->mem;
        int v3221 = (v3116 * 2) + 1;
        v3122[v3221] = v3119;
        ;
      } else {
        ;
      }
      int * v3127 = v3068->mem;
      int v3226 = ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) * 2;
      int v3128 = v3127[v3226];
      int v3227 = (((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3129 = v3127[v3227];
      int * v3130 = v3068->cache_vals;
      int v3229 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3130[v3229] = v3128;
      int * v3132 = v3068->cache_vals;
      int v3232 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3132[v3232] = v3129;
      int * v3134 = v3068->cache_tags;
      int v3235 = (int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1);
      v3134[v3211] = v3235;
      int * v3136 = v3068->cache_dirty;
      v3136[v3211] = 0;
      int * v3138 = v3068->cache_age;
      v3138[v3211] = 1;
      int * v3140 = v3068->cache_age;
      int v3141 = v3140[v3211];
      int v3142 = v3140[v3185];
      int v3241 = v3142 + ((int)((unsigned int)(v3142 - v3141) >> 31));
      v3140[v3185] = v3241;
      int * v3144 = v3068->cache_age;
      int v3145 = v3144[v3186];
      int v3243 = v3145 + ((int)((unsigned int)(v3145 - v3141) >> 31));
      v3144[v3186] = v3243;
      int * v3147 = v3068->cache_age;
      v3147[v3211] = 0;
      v3150 = v3211;
    }
    int * v3151 = v3068->cache_vals;
    int v3246 = v3150 * 2;
    int v3152 = v3151[v3246];
    int v3247 = (v3150 * 2) + 1;
    int v3153 = v3151[v3247];
    int v3248 = (((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3092 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2)) - (v3095 + ((~(((v3096 ^ -1) | (-(v3096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3151[v3248] = v3152;
    int * v3155 = v3068->cache_vals;
    int v3251 = ((((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3092 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2)) - (v3095 + ((~(((v3096 ^ -1) | (-(v3096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3155[v3251] = v3153;
    int * v3157 = v3068->cache_tags;
    int v3254 = ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3092 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2)) - (v3095 + ((~(((v3096 ^ -1) | (-(v3096 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3255 = (int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1);
    v3157[v3254] = v3255;
    int * v3159 = v3068->cache_dirty;
    v3159[v3254] = 0;
    int * v3161 = v3068->cache_age;
    v3161[v3254] = 1;
    int * v3163 = v3068->cache_age;
    int v3164 = v3163[v3254];
    int v3165 = v3163[v3183];
    int v3261 = v3165 + ((int)((unsigned int)(v3165 - v3164) >> 31));
    v3163[v3183] = v3261;
    int * v3167 = v3068->cache_age;
    int v3168 = v3167[v3184];
    int v3263 = v3168 + ((int)((unsigned int)(v3168 - v3164) >> 31));
    v3167[v3184] = v3263;
    int * v3170 = v3068->cache_age;
    v3170[v3254] = 0;
    v3173 = v3254;
  }
  int v3266 = (v3173 * 2) + (((int)((unsigned int)(v3072 + 4) >> 2)) & 1);
  int v3174 = v3080[v3266];
  int * v3175 = v3068->regs;
  v3175[17] = v3174;
  struct StateT * v3177 = slot_13(v3068);
  return v3177;
}

struct StateT * slot_268(struct StateT * v17569) {
  int v17570 = v17569->timer;
  int v17577 = v17570 + 1;
  v17569->timer = v17577;
  int * v17572 = v17569->regs;
  int v17573 = v17572[22];
  int v17580 = v17573 << 9;
  v17572[22] = v17580;
  struct StateT * v17575 = slot_269(v17569);
  return v17575;
}

struct StateT * slot_199(struct StateT * v8964) {
  int v8965 = v8964->timer;
  int v9135 = v8965 + 1;
  v8964->timer = v9135;
  int * v8967 = v8964->regs;
  int v8968 = v8967[10];
  int v8969 = v8967[28];
  int * v8970 = v8964->cache_tags;
  int v9140 = (((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2;
  int v8971 = v8970[v9140];
  int v9141 = ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8972 = v8970[v9141];
  int v9142 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2);
  int v8973 = v8970[v9142];
  int v9143 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8974 = v8970[v9143];
  int v8975 = v8964->timer;
  int v9144 = v8975 + ((100 ^ (((~(((v8973 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8973 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8971 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8971 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8972 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8972 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8973 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8973 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8964->timer = v9144;
  bool v9145 = !(((~(((v8971 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8971 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8972 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8972 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v9069;
  if (v9145) {
    int * v8977 = v8964->cache_age;
    int v9147 = ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v8972 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8972 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v8978 = v8977[v9147];
    int v8979 = v8977[v9140];
    int v9148 = v8979 + ((int)((unsigned int)(v8979 - v8978) >> 31));
    v8977[v9140] = v9148;
    int * v8981 = v8964->cache_age;
    int v8982 = v8981[v9141];
    int v9150 = v8982 + ((int)((unsigned int)(v8982 - v8978) >> 31));
    v8981[v9141] = v9150;
    int * v8984 = v8964->cache_age;
    v8984[v9147] = 0;
    v9069 = v9147;
  } else {
    int * v8987 = v8964->cache_age;
    int v9154 = (((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2;
    int v8988 = v8987[v9154];
    int * v8989 = v8964->cache_tags;
    int v8990 = v8989[v9154];
    int v8991 = v8987[v9141];
    int v8992 = v8989[v9141];
    bool v9156 = !(((~(((v8973 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8973 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v9046;
    if (v9156) {
      int * v8993 = v8964->cache_age;
      int v9158 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v8974 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v8994 = v8993[v9158];
      int v8995 = v8993[v9142];
      int v9159 = v8995 + ((int)((unsigned int)(v8995 - v8994) >> 31));
      v8993[v9142] = v9159;
      int * v8997 = v8964->cache_age;
      int v8998 = v8997[v9143];
      int v9161 = v8998 + ((int)((unsigned int)(v8998 - v8994) >> 31));
      v8997[v9143] = v9161;
      int * v9000 = v8964->cache_age;
      v9000[v9158] = 0;
      v9046 = v9158;
    } else {
      int * v9003 = v8964->cache_age;
      int v9165 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2);
      int v9004 = v9003[v9165];
      int * v9005 = v8964->cache_tags;
      int v9006 = v9005[v9165];
      int v9007 = v9003[v9143];
      int v9008 = v9005[v9143];
      int * v9009 = v8964->cache_dirty;
      int v9168 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9004 + ((~(((v9006 ^ -1) | (-(v9006 ^ -1))) >> 31)) & 2)) - (v9007 + ((~(((v9008 ^ -1) | (-(v9008 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9010 = v9009[v9168];
      bool v9169 = !(v9010 == 0);
      if (v9169) {
        int * v9011 = v8964->cache_tags;
        int v9012 = v9011[v9168];
        int * v9013 = v8964->cache_vals;
        int v9172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9004 + ((~(((v9006 ^ -1) | (-(v9006 ^ -1))) >> 31)) & 2)) - (v9007 + ((~(((v9008 ^ -1) | (-(v9008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9014 = v9013[v9172];
        int v9173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9004 + ((~(((v9006 ^ -1) | (-(v9006 ^ -1))) >> 31)) & 2)) - (v9007 + ((~(((v9008 ^ -1) | (-(v9008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9015 = v9013[v9173];
        int * v9016 = v8964->mem;
        int v9175 = v9012 * 2;
        v9016[v9175] = v9014;
        int * v9018 = v8964->mem;
        int v9178 = (v9012 * 2) + 1;
        v9018[v9178] = v9015;
        ;
      } else {
        ;
      }
      int * v9023 = v8964->mem;
      int v9183 = ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) * 2;
      int v9024 = v9023[v9183];
      int v9184 = (((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) * 2) + 1;
      int v9025 = v9023[v9184];
      int * v9026 = v8964->cache_vals;
      int v9186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9004 + ((~(((v9006 ^ -1) | (-(v9006 ^ -1))) >> 31)) & 2)) - (v9007 + ((~(((v9008 ^ -1) | (-(v9008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9026[v9186] = v9024;
      int * v9028 = v8964->cache_vals;
      int v9189 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9004 + ((~(((v9006 ^ -1) | (-(v9006 ^ -1))) >> 31)) & 2)) - (v9007 + ((~(((v9008 ^ -1) | (-(v9008 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9028[v9189] = v9025;
      int * v9030 = v8964->cache_tags;
      int v9192 = (int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1);
      v9030[v9168] = v9192;
      int * v9032 = v8964->cache_dirty;
      v9032[v9168] = 0;
      int * v9034 = v8964->cache_age;
      v9034[v9168] = 1;
      int * v9036 = v8964->cache_age;
      int v9037 = v9036[v9168];
      int v9038 = v9036[v9142];
      int v9198 = v9038 + ((int)((unsigned int)(v9038 - v9037) >> 31));
      v9036[v9142] = v9198;
      int * v9040 = v8964->cache_age;
      int v9041 = v9040[v9143];
      int v9200 = v9041 + ((int)((unsigned int)(v9041 - v9037) >> 31));
      v9040[v9143] = v9200;
      int * v9043 = v8964->cache_age;
      v9043[v9168] = 0;
      v9046 = v9168;
    }
    int * v9047 = v8964->cache_vals;
    int v9203 = v9046 * 2;
    int v9048 = v9047[v9203];
    int v9204 = (v9046 * 2) + 1;
    int v9049 = v9047[v9204];
    int v9205 = (((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v8988 + ((~(((v8990 ^ -1) | (-(v8990 ^ -1))) >> 31)) & 2)) - (v8991 + ((~(((v8992 ^ -1) | (-(v8992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9047[v9205] = v9048;
    int * v9051 = v8964->cache_vals;
    int v9208 = ((((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v8988 + ((~(((v8990 ^ -1) | (-(v8990 ^ -1))) >> 31)) & 2)) - (v8991 + ((~(((v8992 ^ -1) | (-(v8992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9051[v9208] = v9049;
    int * v9053 = v8964->cache_tags;
    int v9211 = ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v8988 + ((~(((v8990 ^ -1) | (-(v8990 ^ -1))) >> 31)) & 2)) - (v8991 + ((~(((v8992 ^ -1) | (-(v8992 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9212 = (int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1);
    v9053[v9211] = v9212;
    int * v9055 = v8964->cache_dirty;
    v9055[v9211] = 0;
    int * v9057 = v8964->cache_age;
    v9057[v9211] = 1;
    int * v9059 = v8964->cache_age;
    int v9060 = v9059[v9211];
    int v9061 = v9059[v9140];
    int v9218 = v9061 + ((int)((unsigned int)(v9061 - v9060) >> 31));
    v9059[v9140] = v9218;
    int * v9063 = v8964->cache_age;
    int v9064 = v9063[v9141];
    int v9220 = v9064 + ((int)((unsigned int)(v9064 - v9060) >> 31));
    v9063[v9141] = v9220;
    int * v9066 = v8964->cache_age;
    v9066[v9211] = 0;
    v9069 = v9211;
  }
  int * v9070 = v8964->cache_vals;
  int v9223 = (v9069 * 2) + (((int)((unsigned int)(v8968 + 8) >> 2)) & 1);
  v9070[v9223] = v8969;
  int * v9072 = v8964->cache_tags;
  int v9073 = v9072[v9142];
  int v9074 = v9072[v9143];
  bool v9226 = !(((~(((v9073 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v9073 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v9074 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v9074 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v9128;
  if (v9226) {
    int * v9075 = v8964->cache_age;
    int v9228 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9074 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))) | (-(v9074 ^ ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v9076 = v9075[v9228];
    int v9077 = v9075[v9142];
    int v9229 = v9077 + ((int)((unsigned int)(v9077 - v9076) >> 31));
    v9075[v9142] = v9229;
    int * v9079 = v8964->cache_age;
    int v9080 = v9079[v9143];
    int v9231 = v9080 + ((int)((unsigned int)(v9080 - v9076) >> 31));
    v9079[v9143] = v9231;
    int * v9082 = v8964->cache_age;
    v9082[v9228] = 0;
    v9128 = v9228;
  } else {
    int * v9085 = v8964->cache_age;
    int v9235 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2);
    int v9086 = v9085[v9235];
    int * v9087 = v8964->cache_tags;
    int v9088 = v9087[v9235];
    int v9089 = v9085[v9143];
    int v9090 = v9087[v9143];
    int * v9091 = v8964->cache_dirty;
    int v9238 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9092 = v9091[v9238];
    bool v9239 = !(v9092 == 0);
    if (v9239) {
      int * v9093 = v8964->cache_tags;
      int v9094 = v9093[v9238];
      int * v9095 = v8964->cache_vals;
      int v9242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9096 = v9095[v9242];
      int v9243 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9097 = v9095[v9243];
      int * v9098 = v8964->mem;
      int v9245 = v9094 * 2;
      v9098[v9245] = v9096;
      int * v9100 = v8964->mem;
      int v9248 = (v9094 * 2) + 1;
      v9100[v9248] = v9097;
      ;
    } else {
      ;
    }
    int * v9105 = v8964->mem;
    int v9253 = ((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) * 2;
    int v9106 = v9105[v9253];
    int v9254 = (((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) * 2) + 1;
    int v9107 = v9105[v9254];
    int * v9108 = v8964->cache_vals;
    int v9256 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9108[v9256] = v9106;
    int * v9110 = v8964->cache_vals;
    int v9259 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v9086 + ((~(((v9088 ^ -1) | (-(v9088 ^ -1))) >> 31)) & 2)) - (v9089 + ((~(((v9090 ^ -1) | (-(v9090 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9110[v9259] = v9107;
    int * v9112 = v8964->cache_tags;
    int v9262 = (int)((unsigned int)((int)((unsigned int)(v8968 + 8) >> 2)) >> 1);
    v9112[v9238] = v9262;
    int * v9114 = v8964->cache_dirty;
    v9114[v9238] = 0;
    int * v9116 = v8964->cache_age;
    v9116[v9238] = 1;
    int * v9118 = v8964->cache_age;
    int v9119 = v9118[v9238];
    int v9120 = v9118[v9142];
    int v9268 = v9120 + ((int)((unsigned int)(v9120 - v9119) >> 31));
    v9118[v9142] = v9268;
    int * v9122 = v8964->cache_age;
    int v9123 = v9122[v9143];
    int v9270 = v9123 + ((int)((unsigned int)(v9123 - v9119) >> 31));
    v9122[v9143] = v9270;
    int * v9125 = v8964->cache_age;
    v9125[v9238] = 0;
    v9128 = v9238;
  }
  int * v9129 = v8964->cache_vals;
  int v9273 = (v9128 * 2) + (((int)((unsigned int)(v8968 + 8) >> 2)) & 1);
  v9129[v9273] = v8969;
  int * v9131 = v8964->cache_dirty;
  v9131[v9128] = 1;
  struct StateT * v9133 = slot_210(v8964);
  return v9133;
}

struct StateT * slot_252(struct StateT * v17345) {
  int v17346 = v17345->timer;
  int v17353 = v17346 + 1;
  v17345->timer = v17353;
  int * v17348 = v17345->regs;
  int v17349 = v17348[2];
  int v17356 = v17349 + 48;
  v17348[2] = v17356;
  struct StateT * v17351 = slot_254(v17345);
  return v17351;
}

struct StateT * slot_409(struct StateT * v19795) {
  int v19796 = v19795->timer;
  int v19803 = v19796 + 1;
  v19795->timer = v19803;
  int * v19798 = v19795->regs;
  int v19799 = v19798[22];
  int v19807 = (int)((unsigned int)v19799 >> 25);
  v19798[24] = v19807;
  struct StateT * v19801 = slot_410(v19795);
  return v19801;
}

struct StateT * slot_374(struct StateT * v19220) {
  int v19221 = v19220->timer;
  int v19229 = v19221 + 1;
  v19220->timer = v19229;
  int * v19223 = v19220->regs;
  int v19224 = v19223[9];
  int v19225 = v19223[21];
  int v19233 = v19224 ^ v19225;
  v19223[9] = v19233;
  struct StateT * v19227 = slot_375(v19220);
  return v19227;
}

struct StateT * slot_269(struct StateT * v17583) {
  int v17584 = v17583->timer;
  int v17592 = v17584 + 1;
  v17583->timer = v17592;
  int * v17586 = v17583->regs;
  int v17587 = v17586[22];
  int v17588 = v17586[24];
  int v17596 = v17587 | v17588;
  v17586[22] = v17596;
  struct StateT * v17590 = slot_270(v17583);
  return v17590;
}

struct StateT * slot_501(struct StateT * v21343) {
  int v21344 = v21343->timer;
  int v21352 = v21344 + 1;
  v21343->timer = v21352;
  int * v21346 = v21343->regs;
  int v21347 = v21346[15];
  int v21348 = v21346[28];
  int v21357 = v21347 + v21348;
  v21346[22] = v21357;
  struct StateT * v21350 = slot_502(v21343);
  return v21350;
}

struct StateT * slot_251(struct StateT * v17329) {
  int v17330 = v17329->timer;
  int v17338 = v17330 + 1;
  v17329->timer = v17338;
  int * v17332 = v17329->regs;
  int v17333 = v17332[18];
  int v17334 = v17332[21];
  int v17342 = v17333 ^ v17334;
  v17332[18] = v17342;
  struct StateT * v17336 = slot_253(v17329);
  return v17336;
}

struct StateT * slot_65(struct StateT * v6006) {
  int v6007 = v6006->timer;
  int v6015 = v6007 + 1;
  v6006->timer = v6015;
  int * v6009 = v6006->regs;
  int v6010 = v6009[22];
  int v6011 = v6009[24];
  int v6019 = v6010 | v6011;
  v6009[22] = v6019;
  struct StateT * v6013 = slot_66(v6006);
  return v6013;
}

struct StateT * slot_10(struct StateT * v2851) {
  int v2852 = v2851->timer;
  int v2858 = v2852 + 1;
  v2851->timer = v2858;
  int * v2854 = v2851->regs;
  v2854[13] = 0;
  struct StateT * v2856 = slot_11(v2851);
  return v2856;
}

struct StateT * slot_322(struct StateT * v18415) {
  int v18416 = v18415->timer;
  int v18423 = v18416 + 1;
  v18415->timer = v18423;
  int * v18418 = v18415->regs;
  int v18419 = v18418[20];
  int v18426 = v18419 << 7;
  v18418[20] = v18426;
  struct StateT * v18421 = slot_323(v18415);
  return v18421;
}

struct StateT * slot_277(struct StateT * v17708) {
  int v17709 = v17708->timer;
  int v17717 = v17709 + 1;
  v17708->timer = v17717;
  int * v17711 = v17708->regs;
  int v17712 = v17711[6];
  int v17713 = v17711[9];
  int v17722 = v17712 + v17713;
  v17711[20] = v17722;
  struct StateT * v17715 = slot_278(v17708);
  return v17715;
}

struct StateT * slot_353(struct StateT * v18892) {
  int v18893 = v18892->timer;
  int v18901 = v18893 + 1;
  v18892->timer = v18901;
  int * v18895 = v18892->regs;
  int v18896 = v18895[17];
  int v18897 = v18895[20];
  int v18905 = v18896 ^ v18897;
  v18895[17] = v18905;
  struct StateT * v18899 = slot_354(v18892);
  return v18899;
}

struct StateT * slot_397(struct StateT * v19580) {
  int v19581 = v19580->timer;
  int v19588 = v19581 + 1;
  v19580->timer = v19588;
  int * v19583 = v19580->regs;
  int v19584 = v19583[13];
  int v19591 = v19584 + 1;
  v19583[13] = v19591;
  struct StateT * v19586 = slot_398(v19580);
  return v19586;
}

struct StateT * slot_435(struct StateT * v20225) {
  int * v20226 = v20225->saved_regs;
  int * v20227 = v20225->regs;
  int v20228 = v20227[6];
  v20226[6] = v20228;
  int v20230 = v20225->timer;
  int v20242 = v20230 + 1;
  v20225->timer = v20242;
  int * v20232 = v20225->regs;
  int v20233 = v20232[6];
  int v20234 = v20232[20];
  int v20245 = v20233 ^ v20234;
  v20232[6] = v20245;
  struct StateT * v20236 = slot_436(v20225);
  return v20236;
}

struct StateT * slot_476(struct StateT * v20928) {
  int * v20929 = v20928->saved_regs;
  int * v20930 = v20928->regs;
  int v20931 = v20930[29];
  v20929[29] = v20931;
  int v20933 = v20928->timer;
  int v20945 = v20933 + 1;
  v20928->timer = v20945;
  int * v20935 = v20928->regs;
  int v20936 = v20935[29];
  int v20937 = v20935[21];
  int v20948 = v20936 ^ v20937;
  v20935[29] = v20948;
  struct StateT * v20939 = slot_477(v20928);
  return v20939;
}

struct StateT * slot_136(struct StateT * v7202) {
  int v7203 = v7202->timer;
  int v7211 = v7203 + 1;
  v7202->timer = v7211;
  int * v7205 = v7202->regs;
  int v7206 = v7205[16];
  int v7207 = v7205[31];
  int v7216 = v7206 + v7207;
  v7205[23] = v7216;
  struct StateT * v7209 = slot_137(v7202);
  return v7209;
}

struct StateT * slot_379(struct StateT * v19302) {
  int v19303 = v19302->timer;
  int v19311 = v19303 + 1;
  v19302->timer = v19311;
  int * v19305 = v19302->regs;
  int v19306 = v19305[18];
  int v19307 = v19305[6];
  int v19316 = v19306 + v19307;
  v19305[22] = v19316;
  struct StateT * v19309 = slot_380(v19302);
  return v19309;
}

struct StateT * slot_475(struct StateT * v20905) {
  int * v20906 = v20905->saved_regs;
  int * v20907 = v20905->regs;
  int v20908 = v20907[30];
  v20906[30] = v20908;
  int v20910 = v20905->timer;
  int v20922 = v20910 + 1;
  v20905->timer = v20922;
  int * v20912 = v20905->regs;
  int v20913 = v20912[30];
  int v20914 = v20912[20];
  int v20925 = v20913 ^ v20914;
  v20912[30] = v20925;
  struct StateT * v20916 = slot_476(v20905);
  return v20916;
}

struct StateT * slot_310(struct StateT * v18223) {
  int v18224 = v18223->timer;
  int v18231 = v18224 + 1;
  v18223->timer = v18231;
  int * v18226 = v18223->regs;
  int v18227 = v18226[23];
  int v18235 = (int)((unsigned int)v18227 >> 14);
  v18226[24] = v18235;
  struct StateT * v18229 = slot_311(v18223);
  return v18229;
}

struct StateT * slot_445(struct StateT * v20414) {
  int v20415 = v20414->timer;
  int v20423 = v20415 + 1;
  v20414->timer = v20423;
  int * v20417 = v20414->regs;
  int v20418 = v20417[20];
  int v20419 = v20417[24];
  int v20427 = v20418 | v20419;
  v20417[20] = v20427;
  struct StateT * v20421 = slot_446(v20414);
  return v20421;
}

struct StateT * slot_295(struct StateT * v17988) {
  int v17989 = v17988->timer;
  int v17997 = v17989 + 1;
  v17988->timer = v17997;
  int * v17991 = v17988->regs;
  int v17992 = v17991[12];
  int v17993 = v17991[22];
  int v18001 = v17992 ^ v17993;
  v17991[12] = v18001;
  struct StateT * v17995 = slot_296(v17988);
  return v17995;
}

struct StateT * slot_315(struct StateT * v18300) {
  int v18301 = v18300->timer;
  int v18309 = v18301 + 1;
  v18300->timer = v18309;
  int * v18303 = v18300->regs;
  int v18304 = v18303[28];
  int v18305 = v18303[22];
  int v18313 = v18304 ^ v18305;
  v18303[28] = v18313;
  struct StateT * v18307 = slot_316(v18300);
  return v18307;
}

struct StateT * slot_545(struct StateT * v22030) {
  int v22031 = v22030->timer;
  int v22039 = v22031 + 1;
  v22030->timer = v22039;
  int * v22033 = v22030->regs;
  int v22034 = v22033[20];
  int v22035 = v22033[24];
  int v22043 = v22034 | v22035;
  v22033[20] = v22043;
  struct StateT * v22037 = slot_546(v22030);
  return v22037;
}

struct StateT * slot_17(struct StateT * v4088) {
  int v4089 = v4088->timer;
  int v4199 = v4089 + 1;
  v4088->timer = v4199;
  int * v4091 = v4088->regs;
  int v4092 = v4091[12];
  int * v4093 = v4088->cache_tags;
  int v4203 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2;
  int v4094 = v4093[v4203];
  int v4204 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4095 = v4093[v4204];
  int v4205 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2);
  int v4096 = v4093[v4205];
  int v4206 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4097 = v4093[v4206];
  int v4098 = v4088->timer;
  int v4207 = v4098 + ((100 ^ (((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4088->timer = v4207;
  int * v4100 = v4088->cache_vals;
  bool v4208 = !(((~(((v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v4193;
  if (v4208) {
    int * v4101 = v4088->cache_age;
    int v4210 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v4102 = v4101[v4210];
    int v4103 = v4101[v4203];
    int v4211 = v4103 + ((int)((unsigned int)(v4103 - v4102) >> 31));
    v4101[v4203] = v4211;
    int * v4105 = v4088->cache_age;
    int v4106 = v4105[v4204];
    int v4213 = v4106 + ((int)((unsigned int)(v4106 - v4102) >> 31));
    v4105[v4204] = v4213;
    int * v4108 = v4088->cache_age;
    v4108[v4210] = 0;
    v4193 = v4210;
  } else {
    int * v4111 = v4088->cache_age;
    int v4217 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2;
    int v4112 = v4111[v4217];
    int * v4113 = v4088->cache_tags;
    int v4114 = v4113[v4217];
    int v4115 = v4111[v4204];
    int v4116 = v4113[v4204];
    bool v4219 = !(((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v4170;
    if (v4219) {
      int * v4117 = v4088->cache_age;
      int v4221 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v4118 = v4117[v4221];
      int v4119 = v4117[v4205];
      int v4222 = v4119 + ((int)((unsigned int)(v4119 - v4118) >> 31));
      v4117[v4205] = v4222;
      int * v4121 = v4088->cache_age;
      int v4122 = v4121[v4206];
      int v4224 = v4122 + ((int)((unsigned int)(v4122 - v4118) >> 31));
      v4121[v4206] = v4224;
      int * v4124 = v4088->cache_age;
      v4124[v4221] = 0;
      v4170 = v4221;
    } else {
      int * v4127 = v4088->cache_age;
      int v4228 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2);
      int v4128 = v4127[v4228];
      int * v4129 = v4088->cache_tags;
      int v4130 = v4129[v4228];
      int v4131 = v4127[v4206];
      int v4132 = v4129[v4206];
      int * v4133 = v4088->cache_dirty;
      int v4231 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4134 = v4133[v4231];
      bool v4232 = !(v4134 == 0);
      if (v4232) {
        int * v4135 = v4088->cache_tags;
        int v4136 = v4135[v4231];
        int * v4137 = v4088->cache_vals;
        int v4235 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4138 = v4137[v4235];
        int v4236 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4139 = v4137[v4236];
        int * v4140 = v4088->mem;
        int v4238 = v4136 * 2;
        v4140[v4238] = v4138;
        int * v4142 = v4088->mem;
        int v4241 = (v4136 * 2) + 1;
        v4142[v4241] = v4139;
        ;
      } else {
        ;
      }
      int * v4147 = v4088->mem;
      int v4246 = ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) * 2;
      int v4148 = v4147[v4246];
      int v4247 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) * 2) + 1;
      int v4149 = v4147[v4247];
      int * v4150 = v4088->cache_vals;
      int v4249 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4150[v4249] = v4148;
      int * v4152 = v4088->cache_vals;
      int v4252 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4152[v4252] = v4149;
      int * v4154 = v4088->cache_tags;
      int v4255 = (int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1);
      v4154[v4231] = v4255;
      int * v4156 = v4088->cache_dirty;
      v4156[v4231] = 0;
      int * v4158 = v4088->cache_age;
      v4158[v4231] = 1;
      int * v4160 = v4088->cache_age;
      int v4161 = v4160[v4231];
      int v4162 = v4160[v4205];
      int v4261 = v4162 + ((int)((unsigned int)(v4162 - v4161) >> 31));
      v4160[v4205] = v4261;
      int * v4164 = v4088->cache_age;
      int v4165 = v4164[v4206];
      int v4263 = v4165 + ((int)((unsigned int)(v4165 - v4161) >> 31));
      v4164[v4206] = v4263;
      int * v4167 = v4088->cache_age;
      v4167[v4231] = 0;
      v4170 = v4231;
    }
    int * v4171 = v4088->cache_vals;
    int v4266 = v4170 * 2;
    int v4172 = v4171[v4266];
    int v4267 = (v4170 * 2) + 1;
    int v4173 = v4171[v4267];
    int v4268 = (((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4171[v4268] = v4172;
    int * v4175 = v4088->cache_vals;
    int v4271 = ((((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4175[v4271] = v4173;
    int * v4177 = v4088->cache_tags;
    int v4274 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4275 = (int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1);
    v4177[v4274] = v4275;
    int * v4179 = v4088->cache_dirty;
    v4179[v4274] = 0;
    int * v4181 = v4088->cache_age;
    v4181[v4274] = 1;
    int * v4183 = v4088->cache_age;
    int v4184 = v4183[v4274];
    int v4185 = v4183[v4203];
    int v4281 = v4185 + ((int)((unsigned int)(v4185 - v4184) >> 31));
    v4183[v4203] = v4281;
    int * v4187 = v4088->cache_age;
    int v4188 = v4187[v4204];
    int v4283 = v4188 + ((int)((unsigned int)(v4188 - v4184) >> 31));
    v4187[v4204] = v4283;
    int * v4190 = v4088->cache_age;
    v4190[v4274] = 0;
    v4193 = v4274;
  }
  int v4286 = (v4193 * 2) + (((int)((unsigned int)(v4092 + 24) >> 2)) & 1);
  int v4194 = v4100[v4286];
  int * v4195 = v4088->regs;
  v4195[7] = v4194;
  struct StateT * v4197 = slot_18(v4088);
  return v4197;
}

struct StateT * slot_197(struct StateT * v8627) {
  int v8628 = v8627->timer;
  int v8798 = v8628 + 1;
  v8627->timer = v8798;
  int * v8630 = v8627->regs;
  int v8631 = v8630[10];
  int v8632 = v8630[29];
  int * v8633 = v8627->cache_tags;
  int v8803 = (((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2;
  int v8634 = v8633[v8803];
  int v8804 = ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8635 = v8633[v8804];
  int v8805 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2);
  int v8636 = v8633[v8805];
  int v8806 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8637 = v8633[v8806];
  int v8638 = v8627->timer;
  int v8807 = v8638 + ((100 ^ (((~(((v8636 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8636 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8634 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8634 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v8635 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8635 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8636 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8636 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8627->timer = v8807;
  bool v8808 = !(((~(((v8634 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8634 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v8635 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8635 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v8732;
  if (v8808) {
    int * v8640 = v8627->cache_age;
    int v8810 = ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v8635 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8635 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v8641 = v8640[v8810];
    int v8642 = v8640[v8803];
    int v8811 = v8642 + ((int)((unsigned int)(v8642 - v8641) >> 31));
    v8640[v8803] = v8811;
    int * v8644 = v8627->cache_age;
    int v8645 = v8644[v8804];
    int v8813 = v8645 + ((int)((unsigned int)(v8645 - v8641) >> 31));
    v8644[v8804] = v8813;
    int * v8647 = v8627->cache_age;
    v8647[v8810] = 0;
    v8732 = v8810;
  } else {
    int * v8650 = v8627->cache_age;
    int v8817 = (((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2;
    int v8651 = v8650[v8817];
    int * v8652 = v8627->cache_tags;
    int v8653 = v8652[v8817];
    int v8654 = v8650[v8804];
    int v8655 = v8652[v8804];
    bool v8819 = !(((~(((v8636 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8636 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v8709;
    if (v8819) {
      int * v8656 = v8627->cache_age;
      int v8821 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8637 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v8657 = v8656[v8821];
      int v8658 = v8656[v8805];
      int v8822 = v8658 + ((int)((unsigned int)(v8658 - v8657) >> 31));
      v8656[v8805] = v8822;
      int * v8660 = v8627->cache_age;
      int v8661 = v8660[v8806];
      int v8824 = v8661 + ((int)((unsigned int)(v8661 - v8657) >> 31));
      v8660[v8806] = v8824;
      int * v8663 = v8627->cache_age;
      v8663[v8821] = 0;
      v8709 = v8821;
    } else {
      int * v8666 = v8627->cache_age;
      int v8828 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2);
      int v8667 = v8666[v8828];
      int * v8668 = v8627->cache_tags;
      int v8669 = v8668[v8828];
      int v8670 = v8666[v8806];
      int v8671 = v8668[v8806];
      int * v8672 = v8627->cache_dirty;
      int v8831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8667 + ((~(((v8669 ^ -1) | (-(v8669 ^ -1))) >> 31)) & 2)) - (v8670 + ((~(((v8671 ^ -1) | (-(v8671 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8673 = v8672[v8831];
      bool v8832 = !(v8673 == 0);
      if (v8832) {
        int * v8674 = v8627->cache_tags;
        int v8675 = v8674[v8831];
        int * v8676 = v8627->cache_vals;
        int v8835 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8667 + ((~(((v8669 ^ -1) | (-(v8669 ^ -1))) >> 31)) & 2)) - (v8670 + ((~(((v8671 ^ -1) | (-(v8671 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8677 = v8676[v8835];
        int v8836 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8667 + ((~(((v8669 ^ -1) | (-(v8669 ^ -1))) >> 31)) & 2)) - (v8670 + ((~(((v8671 ^ -1) | (-(v8671 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8678 = v8676[v8836];
        int * v8679 = v8627->mem;
        int v8838 = v8675 * 2;
        v8679[v8838] = v8677;
        int * v8681 = v8627->mem;
        int v8841 = (v8675 * 2) + 1;
        v8681[v8841] = v8678;
        ;
      } else {
        ;
      }
      int * v8686 = v8627->mem;
      int v8846 = ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) * 2;
      int v8687 = v8686[v8846];
      int v8847 = (((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) * 2) + 1;
      int v8688 = v8686[v8847];
      int * v8689 = v8627->cache_vals;
      int v8849 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8667 + ((~(((v8669 ^ -1) | (-(v8669 ^ -1))) >> 31)) & 2)) - (v8670 + ((~(((v8671 ^ -1) | (-(v8671 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8689[v8849] = v8687;
      int * v8691 = v8627->cache_vals;
      int v8852 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8667 + ((~(((v8669 ^ -1) | (-(v8669 ^ -1))) >> 31)) & 2)) - (v8670 + ((~(((v8671 ^ -1) | (-(v8671 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8691[v8852] = v8688;
      int * v8693 = v8627->cache_tags;
      int v8855 = (int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1);
      v8693[v8831] = v8855;
      int * v8695 = v8627->cache_dirty;
      v8695[v8831] = 0;
      int * v8697 = v8627->cache_age;
      v8697[v8831] = 1;
      int * v8699 = v8627->cache_age;
      int v8700 = v8699[v8831];
      int v8701 = v8699[v8805];
      int v8861 = v8701 + ((int)((unsigned int)(v8701 - v8700) >> 31));
      v8699[v8805] = v8861;
      int * v8703 = v8627->cache_age;
      int v8704 = v8703[v8806];
      int v8863 = v8704 + ((int)((unsigned int)(v8704 - v8700) >> 31));
      v8703[v8806] = v8863;
      int * v8706 = v8627->cache_age;
      v8706[v8831] = 0;
      v8709 = v8831;
    }
    int * v8710 = v8627->cache_vals;
    int v8866 = v8709 * 2;
    int v8711 = v8710[v8866];
    int v8867 = (v8709 * 2) + 1;
    int v8712 = v8710[v8867];
    int v8868 = (((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v8651 + ((~(((v8653 ^ -1) | (-(v8653 ^ -1))) >> 31)) & 2)) - (v8654 + ((~(((v8655 ^ -1) | (-(v8655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8710[v8868] = v8711;
    int * v8714 = v8627->cache_vals;
    int v8871 = ((((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v8651 + ((~(((v8653 ^ -1) | (-(v8653 ^ -1))) >> 31)) & 2)) - (v8654 + ((~(((v8655 ^ -1) | (-(v8655 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8714[v8871] = v8712;
    int * v8716 = v8627->cache_tags;
    int v8874 = ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v8651 + ((~(((v8653 ^ -1) | (-(v8653 ^ -1))) >> 31)) & 2)) - (v8654 + ((~(((v8655 ^ -1) | (-(v8655 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8875 = (int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1);
    v8716[v8874] = v8875;
    int * v8718 = v8627->cache_dirty;
    v8718[v8874] = 0;
    int * v8720 = v8627->cache_age;
    v8720[v8874] = 1;
    int * v8722 = v8627->cache_age;
    int v8723 = v8722[v8874];
    int v8724 = v8722[v8803];
    int v8881 = v8724 + ((int)((unsigned int)(v8724 - v8723) >> 31));
    v8722[v8803] = v8881;
    int * v8726 = v8627->cache_age;
    int v8727 = v8726[v8804];
    int v8883 = v8727 + ((int)((unsigned int)(v8727 - v8723) >> 31));
    v8726[v8804] = v8883;
    int * v8729 = v8627->cache_age;
    v8729[v8874] = 0;
    v8732 = v8874;
  }
  int * v8733 = v8627->cache_vals;
  int v8886 = (v8732 * 2) + (((int)((unsigned int)(v8631 + 4) >> 2)) & 1);
  v8733[v8886] = v8632;
  int * v8735 = v8627->cache_tags;
  int v8736 = v8735[v8805];
  int v8737 = v8735[v8806];
  bool v8889 = !(((~(((v8736 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8736 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v8737 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8737 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v8791;
  if (v8889) {
    int * v8738 = v8627->cache_age;
    int v8891 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8737 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))) | (-(v8737 ^ ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v8739 = v8738[v8891];
    int v8740 = v8738[v8805];
    int v8892 = v8740 + ((int)((unsigned int)(v8740 - v8739) >> 31));
    v8738[v8805] = v8892;
    int * v8742 = v8627->cache_age;
    int v8743 = v8742[v8806];
    int v8894 = v8743 + ((int)((unsigned int)(v8743 - v8739) >> 31));
    v8742[v8806] = v8894;
    int * v8745 = v8627->cache_age;
    v8745[v8891] = 0;
    v8791 = v8891;
  } else {
    int * v8748 = v8627->cache_age;
    int v8898 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2);
    int v8749 = v8748[v8898];
    int * v8750 = v8627->cache_tags;
    int v8751 = v8750[v8898];
    int v8752 = v8748[v8806];
    int v8753 = v8750[v8806];
    int * v8754 = v8627->cache_dirty;
    int v8901 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8749 + ((~(((v8751 ^ -1) | (-(v8751 ^ -1))) >> 31)) & 2)) - (v8752 + ((~(((v8753 ^ -1) | (-(v8753 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8755 = v8754[v8901];
    bool v8902 = !(v8755 == 0);
    if (v8902) {
      int * v8756 = v8627->cache_tags;
      int v8757 = v8756[v8901];
      int * v8758 = v8627->cache_vals;
      int v8905 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8749 + ((~(((v8751 ^ -1) | (-(v8751 ^ -1))) >> 31)) & 2)) - (v8752 + ((~(((v8753 ^ -1) | (-(v8753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v8759 = v8758[v8905];
      int v8906 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8749 + ((~(((v8751 ^ -1) | (-(v8751 ^ -1))) >> 31)) & 2)) - (v8752 + ((~(((v8753 ^ -1) | (-(v8753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v8760 = v8758[v8906];
      int * v8761 = v8627->mem;
      int v8908 = v8757 * 2;
      v8761[v8908] = v8759;
      int * v8763 = v8627->mem;
      int v8911 = (v8757 * 2) + 1;
      v8763[v8911] = v8760;
      ;
    } else {
      ;
    }
    int * v8768 = v8627->mem;
    int v8916 = ((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) * 2;
    int v8769 = v8768[v8916];
    int v8917 = (((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) * 2) + 1;
    int v8770 = v8768[v8917];
    int * v8771 = v8627->cache_vals;
    int v8919 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8749 + ((~(((v8751 ^ -1) | (-(v8751 ^ -1))) >> 31)) & 2)) - (v8752 + ((~(((v8753 ^ -1) | (-(v8753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8771[v8919] = v8769;
    int * v8773 = v8627->cache_vals;
    int v8922 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v8749 + ((~(((v8751 ^ -1) | (-(v8751 ^ -1))) >> 31)) & 2)) - (v8752 + ((~(((v8753 ^ -1) | (-(v8753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8773[v8922] = v8770;
    int * v8775 = v8627->cache_tags;
    int v8925 = (int)((unsigned int)((int)((unsigned int)(v8631 + 4) >> 2)) >> 1);
    v8775[v8901] = v8925;
    int * v8777 = v8627->cache_dirty;
    v8777[v8901] = 0;
    int * v8779 = v8627->cache_age;
    v8779[v8901] = 1;
    int * v8781 = v8627->cache_age;
    int v8782 = v8781[v8901];
    int v8783 = v8781[v8805];
    int v8931 = v8783 + ((int)((unsigned int)(v8783 - v8782) >> 31));
    v8781[v8805] = v8931;
    int * v8785 = v8627->cache_age;
    int v8786 = v8785[v8806];
    int v8933 = v8786 + ((int)((unsigned int)(v8786 - v8782) >> 31));
    v8785[v8806] = v8933;
    int * v8788 = v8627->cache_age;
    v8788[v8901] = 0;
    v8791 = v8901;
  }
  int * v8792 = v8627->cache_vals;
  int v8936 = (v8791 * 2) + (((int)((unsigned int)(v8631 + 4) >> 2)) & 1);
  v8792[v8936] = v8632;
  int * v8794 = v8627->cache_dirty;
  v8794[v8791] = 1;
  struct StateT * v8796 = slot_199(v8627);
  return v8796;
}

struct StateT * slot_457(struct StateT * v20611) {
  int * v20612 = v20611->saved_regs;
  int * v20613 = v20611->regs;
  int v20614 = v20613[12];
  v20612[12] = v20614;
  int v20616 = v20611->timer;
  int v20628 = v20616 + 1;
  v20611->timer = v20628;
  int * v20618 = v20611->regs;
  int v20619 = v20618[12];
  int v20620 = v20618[22];
  int v20631 = v20619 ^ v20620;
  v20618[12] = v20631;
  struct StateT * v20622 = slot_458(v20611);
  return v20622;
}

struct StateT * slot_156(struct StateT * v7514) {
  int v7515 = v7514->timer;
  int v7523 = v7515 + 1;
  v7514->timer = v7523;
  int * v7517 = v7514->regs;
  int v7518 = v7517[7];
  int v7519 = v7517[16];
  int v7528 = v7518 + v7519;
  v7517[23] = v7528;
  struct StateT * v7521 = slot_157(v7514);
  return v7521;
}

struct StateT * slot_68(struct StateT * v6051) {
  int v6052 = v6051->timer;
  int v6060 = v6052 + 1;
  v6051->timer = v6060;
  int * v6054 = v6051->regs;
  int v6055 = v6054[23];
  int v6056 = v6054[24];
  int v6064 = v6055 | v6056;
  v6054[23] = v6064;
  struct StateT * v6058 = slot_69(v6051);
  return v6058;
}

struct StateT * slot_493(struct StateT * v21215) {
  int v21216 = v21215->timer;
  int v21223 = v21216 + 1;
  v21215->timer = v21223;
  int * v21218 = v21215->regs;
  int v21219 = v21218[23];
  int v21226 = v21219 << 7;
  v21218[23] = v21226;
  struct StateT * v21221 = slot_494(v21215);
  return v21221;
}

struct StateT * slot_105(struct StateT * v6686) {
  int v6687 = v6686->timer;
  int v6695 = v6687 + 1;
  v6686->timer = v6695;
  int * v6689 = v6686->regs;
  int v6690 = v6689[22];
  int v6691 = v6689[24];
  int v6699 = v6690 | v6691;
  v6689[22] = v6699;
  struct StateT * v6693 = slot_106(v6686);
  return v6693;
}

struct StateT * slot_430(struct StateT * v20150) {
  int v20151 = v20150->timer;
  int v20158 = v20151 + 1;
  v20150->timer = v20158;
  int * v20153 = v20150->regs;
  int v20154 = v20153[22];
  int v20161 = v20154 << 9;
  v20153[22] = v20161;
  struct StateT * v20156 = slot_431(v20150);
  return v20156;
}

struct StateT * slot_369(struct StateT * v19143) {
  int v19144 = v19143->timer;
  int v19152 = v19144 + 1;
  v19143->timer = v19152;
  int * v19146 = v19143->regs;
  int v19147 = v19146[22];
  int v19148 = v19146[24];
  int v19156 = v19147 | v19148;
  v19146[22] = v19156;
  struct StateT * v19150 = slot_370(v19143);
  return v19150;
}

struct StateT * slot_461(struct StateT * v20691) {
  int v20692 = v20691->timer;
  int v20700 = v20692 + 1;
  v20691->timer = v20700;
  int * v20694 = v20691->regs;
  int v20695 = v20694[12];
  int v20696 = v20694[17];
  int v20705 = v20695 + v20696;
  v20694[22] = v20705;
  struct StateT * v20698 = slot_462(v20691);
  return v20698;
}

struct StateT * slot_164(struct StateT * v7636) {
  int v7637 = v7636->timer;
  int v7644 = v7637 + 1;
  v7636->timer = v7644;
  int * v7639 = v7636->regs;
  int v7640 = v7639[22];
  int v7647 = v7640 << 13;
  v7639[22] = v7647;
  struct StateT * v7642 = slot_165(v7636);
  return v7642;
}

struct StateT * slot_15(struct StateT * v3680) {
  int v3681 = v3680->timer;
  int v3791 = v3681 + 1;
  v3680->timer = v3791;
  int * v3683 = v3680->regs;
  int v3684 = v3683[12];
  int * v3685 = v3680->cache_tags;
  int v3795 = (((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2;
  int v3686 = v3685[v3795];
  int v3796 = ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3687 = v3685[v3796];
  int v3797 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2);
  int v3688 = v3685[v3797];
  int v3798 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3689 = v3685[v3798];
  int v3690 = v3680->timer;
  int v3799 = v3690 + ((100 ^ (((~(((v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3680->timer = v3799;
  int * v3692 = v3680->cache_vals;
  bool v3800 = !(((~(((v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v3785;
  if (v3800) {
    int * v3693 = v3680->cache_age;
    int v3802 = ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v3694 = v3693[v3802];
    int v3695 = v3693[v3795];
    int v3803 = v3695 + ((int)((unsigned int)(v3695 - v3694) >> 31));
    v3693[v3795] = v3803;
    int * v3697 = v3680->cache_age;
    int v3698 = v3697[v3796];
    int v3805 = v3698 + ((int)((unsigned int)(v3698 - v3694) >> 31));
    v3697[v3796] = v3805;
    int * v3700 = v3680->cache_age;
    v3700[v3802] = 0;
    v3785 = v3802;
  } else {
    int * v3703 = v3680->cache_age;
    int v3809 = (((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2;
    int v3704 = v3703[v3809];
    int * v3705 = v3680->cache_tags;
    int v3706 = v3705[v3809];
    int v3707 = v3703[v3796];
    int v3708 = v3705[v3796];
    bool v3811 = !(((~(((v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v3762;
    if (v3811) {
      int * v3709 = v3680->cache_age;
      int v3813 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v3710 = v3709[v3813];
      int v3711 = v3709[v3797];
      int v3814 = v3711 + ((int)((unsigned int)(v3711 - v3710) >> 31));
      v3709[v3797] = v3814;
      int * v3713 = v3680->cache_age;
      int v3714 = v3713[v3798];
      int v3816 = v3714 + ((int)((unsigned int)(v3714 - v3710) >> 31));
      v3713[v3798] = v3816;
      int * v3716 = v3680->cache_age;
      v3716[v3813] = 0;
      v3762 = v3813;
    } else {
      int * v3719 = v3680->cache_age;
      int v3820 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2);
      int v3720 = v3719[v3820];
      int * v3721 = v3680->cache_tags;
      int v3722 = v3721[v3820];
      int v3723 = v3719[v3798];
      int v3724 = v3721[v3798];
      int * v3725 = v3680->cache_dirty;
      int v3823 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3726 = v3725[v3823];
      bool v3824 = !(v3726 == 0);
      if (v3824) {
        int * v3727 = v3680->cache_tags;
        int v3728 = v3727[v3823];
        int * v3729 = v3680->cache_vals;
        int v3827 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3730 = v3729[v3827];
        int v3828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3731 = v3729[v3828];
        int * v3732 = v3680->mem;
        int v3830 = v3728 * 2;
        v3732[v3830] = v3730;
        int * v3734 = v3680->mem;
        int v3833 = (v3728 * 2) + 1;
        v3734[v3833] = v3731;
        ;
      } else {
        ;
      }
      int * v3739 = v3680->mem;
      int v3838 = ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) * 2;
      int v3740 = v3739[v3838];
      int v3839 = (((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) * 2) + 1;
      int v3741 = v3739[v3839];
      int * v3742 = v3680->cache_vals;
      int v3841 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3742[v3841] = v3740;
      int * v3744 = v3680->cache_vals;
      int v3844 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3744[v3844] = v3741;
      int * v3746 = v3680->cache_tags;
      int v3847 = (int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1);
      v3746[v3823] = v3847;
      int * v3748 = v3680->cache_dirty;
      v3748[v3823] = 0;
      int * v3750 = v3680->cache_age;
      v3750[v3823] = 1;
      int * v3752 = v3680->cache_age;
      int v3753 = v3752[v3823];
      int v3754 = v3752[v3797];
      int v3853 = v3754 + ((int)((unsigned int)(v3754 - v3753) >> 31));
      v3752[v3797] = v3853;
      int * v3756 = v3680->cache_age;
      int v3757 = v3756[v3798];
      int v3855 = v3757 + ((int)((unsigned int)(v3757 - v3753) >> 31));
      v3756[v3798] = v3855;
      int * v3759 = v3680->cache_age;
      v3759[v3823] = 0;
      v3762 = v3823;
    }
    int * v3763 = v3680->cache_vals;
    int v3858 = v3762 * 2;
    int v3764 = v3763[v3858];
    int v3859 = (v3762 * 2) + 1;
    int v3765 = v3763[v3859];
    int v3860 = (((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3704 + ((~(((v3706 ^ -1) | (-(v3706 ^ -1))) >> 31)) & 2)) - (v3707 + ((~(((v3708 ^ -1) | (-(v3708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3763[v3860] = v3764;
    int * v3767 = v3680->cache_vals;
    int v3863 = ((((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3704 + ((~(((v3706 ^ -1) | (-(v3706 ^ -1))) >> 31)) & 2)) - (v3707 + ((~(((v3708 ^ -1) | (-(v3708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3767[v3863] = v3765;
    int * v3769 = v3680->cache_tags;
    int v3866 = ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3704 + ((~(((v3706 ^ -1) | (-(v3706 ^ -1))) >> 31)) & 2)) - (v3707 + ((~(((v3708 ^ -1) | (-(v3708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3867 = (int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1);
    v3769[v3866] = v3867;
    int * v3771 = v3680->cache_dirty;
    v3771[v3866] = 0;
    int * v3773 = v3680->cache_age;
    v3773[v3866] = 1;
    int * v3775 = v3680->cache_age;
    int v3776 = v3775[v3866];
    int v3777 = v3775[v3795];
    int v3873 = v3777 + ((int)((unsigned int)(v3777 - v3776) >> 31));
    v3775[v3795] = v3873;
    int * v3779 = v3680->cache_age;
    int v3780 = v3779[v3796];
    int v3875 = v3780 + ((int)((unsigned int)(v3780 - v3776) >> 31));
    v3779[v3796] = v3875;
    int * v3782 = v3680->cache_age;
    v3782[v3866] = 0;
    v3785 = v3866;
  }
  int v3878 = (v3785 * 2) + (((int)((unsigned int)(v3684 + 16) >> 2)) & 1);
  int v3786 = v3692[v3878];
  int * v3787 = v3680->regs;
  v3787[15] = v3786;
  struct StateT * v3789 = slot_16(v3680);
  return v3789;
}

struct StateT * slot_480(struct StateT * v21014) {
  int v21015 = v21014->timer;
  int v21023 = v21015 + 1;
  v21014->timer = v21023;
  int * v21017 = v21014->regs;
  int v21018 = v21017[29];
  int v21019 = v21017[9];
  int v21028 = v21018 + v21019;
  v21017[21] = v21028;
  struct StateT * v21021 = slot_481(v21014);
  return v21021;
}

struct StateT * slot_133(struct StateT * v7151) {
  int v7152 = v7151->timer;
  int v7160 = v7152 + 1;
  v7151->timer = v7160;
  int * v7154 = v7151->regs;
  int v7155 = v7154[14];
  int v7156 = v7154[30];
  int v7165 = v7155 + v7156;
  v7154[20] = v7165;
  struct StateT * v7158 = slot_134(v7151);
  return v7158;
}

struct StateT * slot_56(struct StateT * v5870) {
  int v5871 = v5870->timer;
  int v5879 = v5871 + 1;
  v5870->timer = v5879;
  int * v5873 = v5870->regs;
  int v5874 = v5873[8];
  int v5875 = v5873[31];
  int v5884 = v5874 + v5875;
  v5873[23] = v5884;
  struct StateT * v5877 = slot_57(v5870);
  return v5877;
}

struct StateT * slot_171(struct StateT * v7743) {
  int v7744 = v7743->timer;
  int v7752 = v7744 + 1;
  v7743->timer = v7752;
  int * v7746 = v7743->regs;
  int v7747 = v7746[18];
  int v7748 = v7746[22];
  int v7756 = v7747 ^ v7748;
  v7746[18] = v7756;
  struct StateT * v7750 = slot_172(v7743);
  return v7750;
}

struct StateT * slot_162(struct StateT * v7605) {
  int v7606 = v7605->timer;
  int v7614 = v7606 + 1;
  v7605->timer = v7614;
  int * v7608 = v7605->regs;
  int v7609 = v7608[21];
  int v7610 = v7608[24];
  int v7618 = v7609 | v7610;
  v7608[21] = v7618;
  struct StateT * v7612 = slot_163(v7605);
  return v7612;
}

struct StateT * slot_377(struct StateT * v19268) {
  int v19269 = v19268->timer;
  int v19277 = v19269 + 1;
  v19268->timer = v19277;
  int * v19271 = v19268->regs;
  int v19272 = v19271[8];
  int v19273 = v19271[17];
  int v19282 = v19272 + v19273;
  v19271[20] = v19282;
  struct StateT * v19275 = slot_378(v19268);
  return v19275;
}

struct StateT * slot_552(struct StateT * v22136) {
  int v22137 = v22136->timer;
  int v22144 = v22137 + 1;
  v22136->timer = v22144;
  int * v22139 = v22136->regs;
  int v22140 = v22139[23];
  int v22148 = (int)((unsigned int)v22140 >> 14);
  v22139[24] = v22148;
  struct StateT * v22142 = slot_553(v22136);
  return v22142;
}

struct StateT * slot_427(struct StateT * v20105) {
  int v20106 = v20105->timer;
  int v20113 = v20106 + 1;
  v20105->timer = v20113;
  int * v20108 = v20105->regs;
  int v20109 = v20108[21];
  int v20116 = v20109 << 9;
  v20108[21] = v20116;
  struct StateT * v20111 = slot_428(v20105);
  return v20111;
}

struct StateT * slot_399(struct StateT * v19602) {
  int * v19603 = v19602->saved_regs;
  int * v19604 = v19602->regs;
  int v19605 = v19604[20];
  v19603[20] = v19605;
  int v19607 = v19602->timer;
  int v19619 = v19607 + 1;
  v19602->timer = v19619;
  int * v19609 = v19602->regs;
  int v19610 = v19609[30];
  int v19611 = v19609[16];
  int v19623 = v19610 + v19611;
  v19609[20] = v19623;
  struct StateT * v19613 = slot_400(v19602);
  return v19613;
}

struct StateT * slot_239(struct StateT * v16229) {
  int v16230 = v16229->timer;
  int v16237 = v16230 + 1;
  v16229->timer = v16237;
  int * v16232 = v16229->regs;
  int v16233 = v16232[23];
  int v16241 = (int)((unsigned int)v16233 >> 25);
  v16232[24] = v16241;
  struct StateT * v16235 = slot_242(v16229);
  return v16235;
}

struct StateT * slot_464(struct StateT * v20740) {
  int v20741 = v20740->timer;
  int v20748 = v20741 + 1;
  v20740->timer = v20748;
  int * v20743 = v20740->regs;
  int v20744 = v20743[20];
  int v20751 = v20744 << 18;
  v20743[20] = v20751;
  struct StateT * v20746 = slot_465(v20740);
  return v20746;
}

struct StateT * slot_500(struct StateT * v21326) {
  int v21327 = v21326->timer;
  int v21335 = v21327 + 1;
  v21326->timer = v21335;
  int * v21329 = v21326->regs;
  int v21330 = v21329[12];
  int v21331 = v21329[29];
  int v21340 = v21330 + v21331;
  v21329[21] = v21340;
  struct StateT * v21333 = slot_501(v21326);
  return v21333;
}

struct StateT * slot_433(struct StateT * v20195) {
  int v20196 = v20195->timer;
  int v20203 = v20196 + 1;
  v20195->timer = v20203;
  int * v20198 = v20195->regs;
  int v20199 = v20198[23];
  int v20206 = v20199 << 9;
  v20198[23] = v20206;
  struct StateT * v20201 = slot_434(v20195);
  return v20201;
}

struct StateT * slot_121(struct StateT * v6967) {
  int v6968 = v6967->timer;
  int v6975 = v6968 + 1;
  v6967->timer = v6975;
  int * v6970 = v6967->regs;
  int v6971 = v6970[21];
  int v6978 = v6971 << 7;
  v6970[21] = v6978;
  struct StateT * v6973 = slot_122(v6967);
  return v6973;
}

struct StateT * slot_144(struct StateT * v7324) {
  int v7325 = v7324->timer;
  int v7332 = v7325 + 1;
  v7324->timer = v7332;
  int * v7327 = v7324->regs;
  int v7328 = v7327[22];
  int v7335 = v7328 << 9;
  v7327[22] = v7335;
  struct StateT * v7330 = slot_145(v7324);
  return v7330;
}

struct StateT * slot_267(struct StateT * v17554) {
  int v17555 = v17554->timer;
  int v17562 = v17555 + 1;
  v17554->timer = v17562;
  int * v17557 = v17554->regs;
  int v17558 = v17557[22];
  int v17566 = (int)((unsigned int)v17558 >> 23);
  v17557[24] = v17566;
  struct StateT * v17560 = slot_268(v17554);
  return v17560;
}

struct StateT * slot_492(struct StateT * v21200) {
  int v21201 = v21200->timer;
  int v21208 = v21201 + 1;
  v21200->timer = v21208;
  int * v21203 = v21200->regs;
  int v21204 = v21203[23];
  int v21212 = (int)((unsigned int)v21204 >> 25);
  v21203[24] = v21212;
  struct StateT * v21206 = slot_493(v21200);
  return v21206;
}

struct StateT * slot_201(struct StateT * v9296) {
  int v9297 = v9296->timer;
  int v9467 = v9297 + 1;
  v9296->timer = v9467;
  int * v9299 = v9296->regs;
  int v9300 = v9299[10];
  int v9301 = v9299[30];
  int * v9302 = v9296->cache_tags;
  int v9472 = (((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2;
  int v9303 = v9302[v9472];
  int v9473 = ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9304 = v9302[v9473];
  int v9474 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2);
  int v9305 = v9302[v9474];
  int v9475 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9306 = v9302[v9475];
  int v9307 = v9296->timer;
  int v9476 = v9307 + ((100 ^ (((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) | (~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) | (~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) | (~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31))) & 104)))));
  v9296->timer = v9476;
  bool v9477 = !(((~(((v9303 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9303 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) | (~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31))) == 0);
  int v9401;
  if (v9477) {
    int * v9309 = v9296->cache_age;
    int v9479 = ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2) + ((~(((v9304 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9304 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) & 1);
    int v9310 = v9309[v9479];
    int v9311 = v9309[v9472];
    int v9480 = v9311 + ((int)((unsigned int)(v9311 - v9310) >> 31));
    v9309[v9472] = v9480;
    int * v9313 = v9296->cache_age;
    int v9314 = v9313[v9473];
    int v9482 = v9314 + ((int)((unsigned int)(v9314 - v9310) >> 31));
    v9313[v9473] = v9482;
    int * v9316 = v9296->cache_age;
    v9316[v9479] = 0;
    v9401 = v9479;
  } else {
    int * v9319 = v9296->cache_age;
    int v9486 = (((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2;
    int v9320 = v9319[v9486];
    int * v9321 = v9296->cache_tags;
    int v9322 = v9321[v9486];
    int v9323 = v9319[v9473];
    int v9324 = v9321[v9473];
    bool v9488 = !(((~(((v9305 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9305 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) | (~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31))) == 0);
    int v9378;
    if (v9488) {
      int * v9325 = v9296->cache_age;
      int v9490 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9306 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) & 1);
      int v9326 = v9325[v9490];
      int v9327 = v9325[v9474];
      int v9491 = v9327 + ((int)((unsigned int)(v9327 - v9326) >> 31));
      v9325[v9474] = v9491;
      int * v9329 = v9296->cache_age;
      int v9330 = v9329[v9475];
      int v9493 = v9330 + ((int)((unsigned int)(v9330 - v9326) >> 31));
      v9329[v9475] = v9493;
      int * v9332 = v9296->cache_age;
      v9332[v9490] = 0;
      v9378 = v9490;
    } else {
      int * v9335 = v9296->cache_age;
      int v9497 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2);
      int v9336 = v9335[v9497];
      int * v9337 = v9296->cache_tags;
      int v9338 = v9337[v9497];
      int v9339 = v9335[v9475];
      int v9340 = v9337[v9475];
      int * v9341 = v9296->cache_dirty;
      int v9500 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9342 = v9341[v9500];
      bool v9501 = !(v9342 == 0);
      if (v9501) {
        int * v9343 = v9296->cache_tags;
        int v9344 = v9343[v9500];
        int * v9345 = v9296->cache_vals;
        int v9504 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9346 = v9345[v9504];
        int v9505 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9347 = v9345[v9505];
        int * v9348 = v9296->mem;
        int v9507 = v9344 * 2;
        v9348[v9507] = v9346;
        int * v9350 = v9296->mem;
        int v9510 = (v9344 * 2) + 1;
        v9350[v9510] = v9347;
        ;
      } else {
        ;
      }
      int * v9355 = v9296->mem;
      int v9515 = ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) * 2;
      int v9356 = v9355[v9515];
      int v9516 = (((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) * 2) + 1;
      int v9357 = v9355[v9516];
      int * v9358 = v9296->cache_vals;
      int v9518 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9358[v9518] = v9356;
      int * v9360 = v9296->cache_vals;
      int v9521 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9336 + ((~(((v9338 ^ -1) | (-(v9338 ^ -1))) >> 31)) & 2)) - (v9339 + ((~(((v9340 ^ -1) | (-(v9340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9360[v9521] = v9357;
      int * v9362 = v9296->cache_tags;
      int v9524 = (int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1);
      v9362[v9500] = v9524;
      int * v9364 = v9296->cache_dirty;
      v9364[v9500] = 0;
      int * v9366 = v9296->cache_age;
      v9366[v9500] = 1;
      int * v9368 = v9296->cache_age;
      int v9369 = v9368[v9500];
      int v9370 = v9368[v9474];
      int v9530 = v9370 + ((int)((unsigned int)(v9370 - v9369) >> 31));
      v9368[v9474] = v9530;
      int * v9372 = v9296->cache_age;
      int v9373 = v9372[v9475];
      int v9532 = v9373 + ((int)((unsigned int)(v9373 - v9369) >> 31));
      v9372[v9475] = v9532;
      int * v9375 = v9296->cache_age;
      v9375[v9500] = 0;
      v9378 = v9500;
    }
    int * v9379 = v9296->cache_vals;
    int v9535 = v9378 * 2;
    int v9380 = v9379[v9535];
    int v9536 = (v9378 * 2) + 1;
    int v9381 = v9379[v9536];
    int v9537 = (((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2) + ((((v9320 + ((~(((v9322 ^ -1) | (-(v9322 ^ -1))) >> 31)) & 2)) - (v9323 + ((~(((v9324 ^ -1) | (-(v9324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9379[v9537] = v9380;
    int * v9383 = v9296->cache_vals;
    int v9540 = ((((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2) + ((((v9320 + ((~(((v9322 ^ -1) | (-(v9322 ^ -1))) >> 31)) & 2)) - (v9323 + ((~(((v9324 ^ -1) | (-(v9324 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9383[v9540] = v9381;
    int * v9385 = v9296->cache_tags;
    int v9543 = ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 1) * 2) + ((((v9320 + ((~(((v9322 ^ -1) | (-(v9322 ^ -1))) >> 31)) & 2)) - (v9323 + ((~(((v9324 ^ -1) | (-(v9324 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9544 = (int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1);
    v9385[v9543] = v9544;
    int * v9387 = v9296->cache_dirty;
    v9387[v9543] = 0;
    int * v9389 = v9296->cache_age;
    v9389[v9543] = 1;
    int * v9391 = v9296->cache_age;
    int v9392 = v9391[v9543];
    int v9393 = v9391[v9472];
    int v9550 = v9393 + ((int)((unsigned int)(v9393 - v9392) >> 31));
    v9391[v9472] = v9550;
    int * v9395 = v9296->cache_age;
    int v9396 = v9395[v9473];
    int v9552 = v9396 + ((int)((unsigned int)(v9396 - v9392) >> 31));
    v9395[v9473] = v9552;
    int * v9398 = v9296->cache_age;
    v9398[v9543] = 0;
    v9401 = v9543;
  }
  int * v9402 = v9296->cache_vals;
  int v9555 = (v9401 * 2) + (((int)((unsigned int)v9300 >> 2)) & 1);
  v9402[v9555] = v9301;
  int * v9404 = v9296->cache_tags;
  int v9405 = v9404[v9474];
  int v9406 = v9404[v9475];
  bool v9558 = !(((~(((v9405 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9405 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) | (~(((v9406 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9406 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31))) == 0);
  int v9460;
  if (v9558) {
    int * v9407 = v9296->cache_age;
    int v9560 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((~(((v9406 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))) | (-(v9406 ^ ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1))))) >> 31)) & 1);
    int v9408 = v9407[v9560];
    int v9409 = v9407[v9474];
    int v9561 = v9409 + ((int)((unsigned int)(v9409 - v9408) >> 31));
    v9407[v9474] = v9561;
    int * v9411 = v9296->cache_age;
    int v9412 = v9411[v9475];
    int v9563 = v9412 + ((int)((unsigned int)(v9412 - v9408) >> 31));
    v9411[v9475] = v9563;
    int * v9414 = v9296->cache_age;
    v9414[v9560] = 0;
    v9460 = v9560;
  } else {
    int * v9417 = v9296->cache_age;
    int v9567 = 4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2);
    int v9418 = v9417[v9567];
    int * v9419 = v9296->cache_tags;
    int v9420 = v9419[v9567];
    int v9421 = v9417[v9475];
    int v9422 = v9419[v9475];
    int * v9423 = v9296->cache_dirty;
    int v9570 = (4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9424 = v9423[v9570];
    bool v9571 = !(v9424 == 0);
    if (v9571) {
      int * v9425 = v9296->cache_tags;
      int v9426 = v9425[v9570];
      int * v9427 = v9296->cache_vals;
      int v9574 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v9428 = v9427[v9574];
      int v9575 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v9429 = v9427[v9575];
      int * v9430 = v9296->mem;
      int v9577 = v9426 * 2;
      v9430[v9577] = v9428;
      int * v9432 = v9296->mem;
      int v9580 = (v9426 * 2) + 1;
      v9432[v9580] = v9429;
      ;
    } else {
      ;
    }
    int * v9437 = v9296->mem;
    int v9585 = ((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) * 2;
    int v9438 = v9437[v9585];
    int v9586 = (((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) * 2) + 1;
    int v9439 = v9437[v9586];
    int * v9440 = v9296->cache_vals;
    int v9588 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9440[v9588] = v9438;
    int * v9442 = v9296->cache_vals;
    int v9591 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1)) & 3) * 2)) + ((((v9418 + ((~(((v9420 ^ -1) | (-(v9420 ^ -1))) >> 31)) & 2)) - (v9421 + ((~(((v9422 ^ -1) | (-(v9422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9442[v9591] = v9439;
    int * v9444 = v9296->cache_tags;
    int v9594 = (int)((unsigned int)((int)((unsigned int)v9300 >> 2)) >> 1);
    v9444[v9570] = v9594;
    int * v9446 = v9296->cache_dirty;
    v9446[v9570] = 0;
    int * v9448 = v9296->cache_age;
    v9448[v9570] = 1;
    int * v9450 = v9296->cache_age;
    int v9451 = v9450[v9570];
    int v9452 = v9450[v9474];
    int v9600 = v9452 + ((int)((unsigned int)(v9452 - v9451) >> 31));
    v9450[v9474] = v9600;
    int * v9454 = v9296->cache_age;
    int v9455 = v9454[v9475];
    int v9602 = v9455 + ((int)((unsigned int)(v9455 - v9451) >> 31));
    v9454[v9475] = v9602;
    int * v9457 = v9296->cache_age;
    v9457[v9570] = 0;
    v9460 = v9570;
  }
  int * v9461 = v9296->cache_vals;
  int v9605 = (v9460 * 2) + (((int)((unsigned int)v9300 >> 2)) & 1);
  v9461[v9605] = v9301;
  int * v9463 = v9296->cache_dirty;
  v9463[v9460] = 1;
  struct StateT * v9465 = slot_197(v9296);
  return v9465;
}

struct StateT * slot_63(struct StateT * v5977) {
  int v5978 = v5977->timer;
  int v5985 = v5978 + 1;
  v5977->timer = v5985;
  int * v5980 = v5977->regs;
  int v5981 = v5980[22];
  int v5989 = (int)((unsigned int)v5981 >> 23);
  v5980[24] = v5989;
  struct StateT * v5983 = slot_64(v5977);
  return v5983;
}

struct StateT * slot_326(struct StateT * v18474) {
  int v18475 = v18474->timer;
  int v18483 = v18475 + 1;
  v18474->timer = v18483;
  int * v18477 = v18474->regs;
  int v18478 = v18477[21];
  int v18479 = v18477[24];
  int v18487 = v18478 | v18479;
  v18477[21] = v18487;
  struct StateT * v18481 = slot_327(v18474);
  return v18481;
}

struct StateT * slot_303(struct StateT * v18117) {
  int v18118 = v18117->timer;
  int v18126 = v18118 + 1;
  v18117->timer = v18126;
  int * v18120 = v18117->regs;
  int v18121 = v18120[20];
  int v18122 = v18120[24];
  int v18130 = v18121 | v18122;
  v18120[20] = v18130;
  struct StateT * v18124 = slot_304(v18117);
  return v18124;
}

struct StateT * slot_511(struct StateT * v21496) {
  int v21497 = v21496->timer;
  int v21505 = v21497 + 1;
  v21496->timer = v21505;
  int * v21499 = v21496->regs;
  int v21500 = v21499[22];
  int v21501 = v21499[24];
  int v21509 = v21500 | v21501;
  v21499[22] = v21509;
  struct StateT * v21503 = slot_512(v21496);
  return v21503;
}

struct StateT * slot_335(struct StateT * v18612) {
  int v18613 = v18612->timer;
  int v18621 = v18613 + 1;
  v18612->timer = v18621;
  int * v18615 = v18612->regs;
  int v18616 = v18615[15];
  int v18617 = v18615[22];
  int v18625 = v18616 ^ v18617;
  v18615[15] = v18625;
  struct StateT * v18619 = slot_336(v18612);
  return v18619;
}

struct StateT * slot_316(struct StateT * v18316) {
  int v18317 = v18316->timer;
  int v18325 = v18317 + 1;
  v18316->timer = v18325;
  int * v18319 = v18316->regs;
  int v18320 = v18319[31];
  int v18321 = v18319[23];
  int v18329 = v18320 ^ v18321;
  v18319[31] = v18329;
  struct StateT * v18323 = slot_317(v18316);
  return v18323;
}

struct StateT * slot_424(struct StateT * v20060) {
  int v20061 = v20060->timer;
  int v20068 = v20061 + 1;
  v20060->timer = v20068;
  int * v20063 = v20060->regs;
  int v20064 = v20063[20];
  int v20071 = v20064 << 9;
  v20063[20] = v20071;
  struct StateT * v20066 = slot_425(v20060);
  return v20066;
}

struct StateT * slot_332(struct StateT * v18564) {
  int v18565 = v18564->timer;
  int v18573 = v18565 + 1;
  v18564->timer = v18573;
  int * v18567 = v18564->regs;
  int v18568 = v18567[23];
  int v18569 = v18567[24];
  int v18577 = v18568 | v18569;
  v18567[23] = v18577;
  struct StateT * v18571 = slot_333(v18564);
  return v18571;
}

struct StateT * slot_41(struct StateT * v5607) {
  int v5608 = v5607->timer;
  int v5615 = v5608 + 1;
  v5607->timer = v5615;
  int * v5610 = v5607->regs;
  int v5611 = v5610[21];
  int v5618 = v5611 << 7;
  v5610[21] = v5618;
  struct StateT * v5613 = slot_42(v5607);
  return v5613;
}

struct StateT * slot_39(struct StateT * v5576) {
  int v5577 = v5576->timer;
  int v5585 = v5577 + 1;
  v5576->timer = v5585;
  int * v5579 = v5576->regs;
  int v5580 = v5579[20];
  int v5581 = v5579[24];
  int v5589 = v5580 | v5581;
  v5579[20] = v5589;
  struct StateT * v5583 = slot_40(v5576);
  return v5583;
}

struct StateT * slot_508(struct StateT * v21451) {
  int v21452 = v21451->timer;
  int v21460 = v21452 + 1;
  v21451->timer = v21460;
  int * v21454 = v21451->regs;
  int v21455 = v21454[21];
  int v21456 = v21454[24];
  int v21464 = v21455 | v21456;
  v21454[21] = v21464;
  struct StateT * v21458 = slot_509(v21451);
  return v21458;
}

struct StateT * slot_537(struct StateT * v21901) {
  int v21902 = v21901->timer;
  int v21910 = v21902 + 1;
  v21901->timer = v21910;
  int * v21904 = v21901->regs;
  int v21905 = v21904[18];
  int v21906 = v21904[22];
  int v21914 = v21905 ^ v21906;
  v21904[18] = v21914;
  struct StateT * v21908 = slot_538(v21901);
  return v21908;
}

struct StateT * slot_60(struct StateT * v5932) {
  int v5933 = v5932->timer;
  int v5940 = v5933 + 1;
  v5932->timer = v5940;
  int * v5935 = v5932->regs;
  int v5936 = v5935[21];
  int v5944 = (int)((unsigned int)v5936 >> 23);
  v5935[24] = v5944;
  struct StateT * v5938 = slot_61(v5932);
  return v5938;
}

struct StateT * slot_289(struct StateT * v17895) {
  int v17896 = v17895->timer;
  int v17904 = v17896 + 1;
  v17895->timer = v17904;
  int * v17898 = v17895->regs;
  int v17899 = v17898[22];
  int v17900 = v17898[24];
  int v17908 = v17899 | v17900;
  v17898[22] = v17908;
  struct StateT * v17902 = slot_290(v17895);
  return v17902;
}

struct StateT * slot_238(struct StateT * v16025) {
  int v16026 = v16025->timer;
  int v16136 = v16026 + 1;
  v16025->timer = v16136;
  int * v16028 = v16025->regs;
  int v16029 = v16028[2];
  int * v16030 = v16025->cache_tags;
  int v16140 = (((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2;
  int v16031 = v16030[v16140];
  int v16141 = ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v16032 = v16030[v16141];
  int v16142 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2);
  int v16033 = v16030[v16142];
  int v16143 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v16034 = v16030[v16143];
  int v16035 = v16025->timer;
  int v16144 = v16035 + ((100 ^ (((~(((v16033 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16033 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v16031 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16031 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v16032 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16032 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v16033 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16033 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16025->timer = v16144;
  int * v16037 = v16025->cache_vals;
  bool v16145 = !(((~(((v16031 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16031 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v16032 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16032 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v16130;
  if (v16145) {
    int * v16038 = v16025->cache_age;
    int v16147 = ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v16032 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16032 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v16039 = v16038[v16147];
    int v16040 = v16038[v16140];
    int v16148 = v16040 + ((int)((unsigned int)(v16040 - v16039) >> 31));
    v16038[v16140] = v16148;
    int * v16042 = v16025->cache_age;
    int v16043 = v16042[v16141];
    int v16150 = v16043 + ((int)((unsigned int)(v16043 - v16039) >> 31));
    v16042[v16141] = v16150;
    int * v16045 = v16025->cache_age;
    v16045[v16147] = 0;
    v16130 = v16147;
  } else {
    int * v16048 = v16025->cache_age;
    int v16154 = (((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2;
    int v16049 = v16048[v16154];
    int * v16050 = v16025->cache_tags;
    int v16051 = v16050[v16154];
    int v16052 = v16048[v16141];
    int v16053 = v16050[v16141];
    bool v16156 = !(((~(((v16033 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16033 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v16107;
    if (v16156) {
      int * v16054 = v16025->cache_age;
      int v16158 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))) | (-(v16034 ^ ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v16055 = v16054[v16158];
      int v16056 = v16054[v16142];
      int v16159 = v16056 + ((int)((unsigned int)(v16056 - v16055) >> 31));
      v16054[v16142] = v16159;
      int * v16058 = v16025->cache_age;
      int v16059 = v16058[v16143];
      int v16161 = v16059 + ((int)((unsigned int)(v16059 - v16055) >> 31));
      v16058[v16143] = v16161;
      int * v16061 = v16025->cache_age;
      v16061[v16158] = 0;
      v16107 = v16158;
    } else {
      int * v16064 = v16025->cache_age;
      int v16165 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2);
      int v16065 = v16064[v16165];
      int * v16066 = v16025->cache_tags;
      int v16067 = v16066[v16165];
      int v16068 = v16064[v16143];
      int v16069 = v16066[v16143];
      int * v16070 = v16025->cache_dirty;
      int v16168 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v16065 + ((~(((v16067 ^ -1) | (-(v16067 ^ -1))) >> 31)) & 2)) - (v16068 + ((~(((v16069 ^ -1) | (-(v16069 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v16071 = v16070[v16168];
      bool v16169 = !(v16071 == 0);
      if (v16169) {
        int * v16072 = v16025->cache_tags;
        int v16073 = v16072[v16168];
        int * v16074 = v16025->cache_vals;
        int v16172 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v16065 + ((~(((v16067 ^ -1) | (-(v16067 ^ -1))) >> 31)) & 2)) - (v16068 + ((~(((v16069 ^ -1) | (-(v16069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v16075 = v16074[v16172];
        int v16173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v16065 + ((~(((v16067 ^ -1) | (-(v16067 ^ -1))) >> 31)) & 2)) - (v16068 + ((~(((v16069 ^ -1) | (-(v16069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v16076 = v16074[v16173];
        int * v16077 = v16025->mem;
        int v16175 = v16073 * 2;
        v16077[v16175] = v16075;
        int * v16079 = v16025->mem;
        int v16178 = (v16073 * 2) + 1;
        v16079[v16178] = v16076;
        ;
      } else {
        ;
      }
      int * v16084 = v16025->mem;
      int v16183 = ((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) * 2;
      int v16085 = v16084[v16183];
      int v16184 = (((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) * 2) + 1;
      int v16086 = v16084[v16184];
      int * v16087 = v16025->cache_vals;
      int v16186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v16065 + ((~(((v16067 ^ -1) | (-(v16067 ^ -1))) >> 31)) & 2)) - (v16068 + ((~(((v16069 ^ -1) | (-(v16069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v16087[v16186] = v16085;
      int * v16089 = v16025->cache_vals;
      int v16189 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v16065 + ((~(((v16067 ^ -1) | (-(v16067 ^ -1))) >> 31)) & 2)) - (v16068 + ((~(((v16069 ^ -1) | (-(v16069 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v16089[v16189] = v16086;
      int * v16091 = v16025->cache_tags;
      int v16192 = (int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1);
      v16091[v16168] = v16192;
      int * v16093 = v16025->cache_dirty;
      v16093[v16168] = 0;
      int * v16095 = v16025->cache_age;
      v16095[v16168] = 1;
      int * v16097 = v16025->cache_age;
      int v16098 = v16097[v16168];
      int v16099 = v16097[v16142];
      int v16198 = v16099 + ((int)((unsigned int)(v16099 - v16098) >> 31));
      v16097[v16142] = v16198;
      int * v16101 = v16025->cache_age;
      int v16102 = v16101[v16143];
      int v16200 = v16102 + ((int)((unsigned int)(v16102 - v16098) >> 31));
      v16101[v16143] = v16200;
      int * v16104 = v16025->cache_age;
      v16104[v16168] = 0;
      v16107 = v16168;
    }
    int * v16108 = v16025->cache_vals;
    int v16203 = v16107 * 2;
    int v16109 = v16108[v16203];
    int v16204 = (v16107 * 2) + 1;
    int v16110 = v16108[v16204];
    int v16205 = (((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v16049 + ((~(((v16051 ^ -1) | (-(v16051 ^ -1))) >> 31)) & 2)) - (v16052 + ((~(((v16053 ^ -1) | (-(v16053 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v16108[v16205] = v16109;
    int * v16112 = v16025->cache_vals;
    int v16208 = ((((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v16049 + ((~(((v16051 ^ -1) | (-(v16051 ^ -1))) >> 31)) & 2)) - (v16052 + ((~(((v16053 ^ -1) | (-(v16053 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v16112[v16208] = v16110;
    int * v16114 = v16025->cache_tags;
    int v16211 = ((((int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v16049 + ((~(((v16051 ^ -1) | (-(v16051 ^ -1))) >> 31)) & 2)) - (v16052 + ((~(((v16053 ^ -1) | (-(v16053 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v16212 = (int)((unsigned int)((int)((unsigned int)(v16029 + 16) >> 2)) >> 1);
    v16114[v16211] = v16212;
    int * v16116 = v16025->cache_dirty;
    v16116[v16211] = 0;
    int * v16118 = v16025->cache_age;
    v16118[v16211] = 1;
    int * v16120 = v16025->cache_age;
    int v16121 = v16120[v16211];
    int v16122 = v16120[v16140];
    int v16218 = v16122 + ((int)((unsigned int)(v16122 - v16121) >> 31));
    v16120[v16140] = v16218;
    int * v16124 = v16025->cache_age;
    int v16125 = v16124[v16141];
    int v16220 = v16125 + ((int)((unsigned int)(v16125 - v16121) >> 31));
    v16124[v16141] = v16220;
    int * v16127 = v16025->cache_age;
    v16127[v16211] = 0;
    v16130 = v16211;
  }
  int v16223 = (v16130 * 2) + (((int)((unsigned int)(v16029 + 16) >> 2)) & 1);
  int v16131 = v16037[v16223];
  int * v16132 = v16025->regs;
  v16132[23] = v16131;
  struct StateT * v16134 = slot_241(v16025);
  return v16134;
}

struct StateT * slot_112(struct StateT * v6816) {
  int * v6817 = v6816->saved_regs;
  int * v6818 = v6816->regs;
  int v6819 = v6818[31];
  v6817[31] = v6819;
  int v6821 = v6816->timer;
  int v6833 = v6821 + 1;
  v6816->timer = v6833;
  int * v6823 = v6816->regs;
  int v6824 = v6823[31];
  int v6825 = v6823[23];
  int v6836 = v6824 ^ v6825;
  v6823[31] = v6836;
  struct StateT * v6827 = slot_113(v6816);
  return v6827;
}

struct StateT * slot_544(struct StateT * v22016) {
  int v22017 = v22016->timer;
  int v22024 = v22017 + 1;
  v22016->timer = v22024;
  int * v22019 = v22016->regs;
  int v22020 = v22019[20];
  int v22027 = v22020 << 18;
  v22019[20] = v22027;
  struct StateT * v22022 = slot_545(v22016);
  return v22022;
}

struct StateT * slot_16(struct StateT * v3884) {
  int v3885 = v3884->timer;
  int v3995 = v3885 + 1;
  v3884->timer = v3995;
  int * v3887 = v3884->regs;
  int v3888 = v3887[12];
  int * v3889 = v3884->cache_tags;
  int v3999 = (((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2;
  int v3890 = v3889[v3999];
  int v4000 = ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3891 = v3889[v4000];
  int v4001 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2);
  int v3892 = v3889[v4001];
  int v4002 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3893 = v3889[v4002];
  int v3894 = v3884->timer;
  int v4003 = v3894 + ((100 ^ (((~(((v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3884->timer = v4003;
  int * v3896 = v3884->cache_vals;
  bool v4004 = !(((~(((v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v3989;
  if (v4004) {
    int * v3897 = v3884->cache_age;
    int v4006 = ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v3898 = v3897[v4006];
    int v3899 = v3897[v3999];
    int v4007 = v3899 + ((int)((unsigned int)(v3899 - v3898) >> 31));
    v3897[v3999] = v4007;
    int * v3901 = v3884->cache_age;
    int v3902 = v3901[v4000];
    int v4009 = v3902 + ((int)((unsigned int)(v3902 - v3898) >> 31));
    v3901[v4000] = v4009;
    int * v3904 = v3884->cache_age;
    v3904[v4006] = 0;
    v3989 = v4006;
  } else {
    int * v3907 = v3884->cache_age;
    int v4013 = (((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2;
    int v3908 = v3907[v4013];
    int * v3909 = v3884->cache_tags;
    int v3910 = v3909[v4013];
    int v3911 = v3907[v4000];
    int v3912 = v3909[v4000];
    bool v4015 = !(((~(((v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v3966;
    if (v4015) {
      int * v3913 = v3884->cache_age;
      int v4017 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v3914 = v3913[v4017];
      int v3915 = v3913[v4001];
      int v4018 = v3915 + ((int)((unsigned int)(v3915 - v3914) >> 31));
      v3913[v4001] = v4018;
      int * v3917 = v3884->cache_age;
      int v3918 = v3917[v4002];
      int v4020 = v3918 + ((int)((unsigned int)(v3918 - v3914) >> 31));
      v3917[v4002] = v4020;
      int * v3920 = v3884->cache_age;
      v3920[v4017] = 0;
      v3966 = v4017;
    } else {
      int * v3923 = v3884->cache_age;
      int v4024 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2);
      int v3924 = v3923[v4024];
      int * v3925 = v3884->cache_tags;
      int v3926 = v3925[v4024];
      int v3927 = v3923[v4002];
      int v3928 = v3925[v4002];
      int * v3929 = v3884->cache_dirty;
      int v4027 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3930 = v3929[v4027];
      bool v4028 = !(v3930 == 0);
      if (v4028) {
        int * v3931 = v3884->cache_tags;
        int v3932 = v3931[v4027];
        int * v3933 = v3884->cache_vals;
        int v4031 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3934 = v3933[v4031];
        int v4032 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3935 = v3933[v4032];
        int * v3936 = v3884->mem;
        int v4034 = v3932 * 2;
        v3936[v4034] = v3934;
        int * v3938 = v3884->mem;
        int v4037 = (v3932 * 2) + 1;
        v3938[v4037] = v3935;
        ;
      } else {
        ;
      }
      int * v3943 = v3884->mem;
      int v4042 = ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) * 2;
      int v3944 = v3943[v4042];
      int v4043 = (((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) * 2) + 1;
      int v3945 = v3943[v4043];
      int * v3946 = v3884->cache_vals;
      int v4045 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3946[v4045] = v3944;
      int * v3948 = v3884->cache_vals;
      int v4048 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3948[v4048] = v3945;
      int * v3950 = v3884->cache_tags;
      int v4051 = (int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1);
      v3950[v4027] = v4051;
      int * v3952 = v3884->cache_dirty;
      v3952[v4027] = 0;
      int * v3954 = v3884->cache_age;
      v3954[v4027] = 1;
      int * v3956 = v3884->cache_age;
      int v3957 = v3956[v4027];
      int v3958 = v3956[v4001];
      int v4057 = v3958 + ((int)((unsigned int)(v3958 - v3957) >> 31));
      v3956[v4001] = v4057;
      int * v3960 = v3884->cache_age;
      int v3961 = v3960[v4002];
      int v4059 = v3961 + ((int)((unsigned int)(v3961 - v3957) >> 31));
      v3960[v4002] = v4059;
      int * v3963 = v3884->cache_age;
      v3963[v4027] = 0;
      v3966 = v4027;
    }
    int * v3967 = v3884->cache_vals;
    int v4062 = v3966 * 2;
    int v3968 = v3967[v4062];
    int v4063 = (v3966 * 2) + 1;
    int v3969 = v3967[v4063];
    int v4064 = (((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3908 + ((~(((v3910 ^ -1) | (-(v3910 ^ -1))) >> 31)) & 2)) - (v3911 + ((~(((v3912 ^ -1) | (-(v3912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3967[v4064] = v3968;
    int * v3971 = v3884->cache_vals;
    int v4067 = ((((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3908 + ((~(((v3910 ^ -1) | (-(v3910 ^ -1))) >> 31)) & 2)) - (v3911 + ((~(((v3912 ^ -1) | (-(v3912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3971[v4067] = v3969;
    int * v3973 = v3884->cache_tags;
    int v4070 = ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3908 + ((~(((v3910 ^ -1) | (-(v3910 ^ -1))) >> 31)) & 2)) - (v3911 + ((~(((v3912 ^ -1) | (-(v3912 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4071 = (int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1);
    v3973[v4070] = v4071;
    int * v3975 = v3884->cache_dirty;
    v3975[v4070] = 0;
    int * v3977 = v3884->cache_age;
    v3977[v4070] = 1;
    int * v3979 = v3884->cache_age;
    int v3980 = v3979[v4070];
    int v3981 = v3979[v3999];
    int v4077 = v3981 + ((int)((unsigned int)(v3981 - v3980) >> 31));
    v3979[v3999] = v4077;
    int * v3983 = v3884->cache_age;
    int v3984 = v3983[v4000];
    int v4079 = v3984 + ((int)((unsigned int)(v3984 - v3980) >> 31));
    v3983[v4000] = v4079;
    int * v3986 = v3884->cache_age;
    v3986[v4070] = 0;
    v3989 = v4070;
  }
  int v4082 = (v3989 * 2) + (((int)((unsigned int)(v3888 + 20) >> 2)) & 1);
  int v3990 = v3896[v4082];
  int * v3991 = v3884->regs;
  v3991[16] = v3990;
  struct StateT * v3993 = slot_17(v3884);
  return v3993;
}

struct StateT * slot_245(struct StateT * v16884) {
  int v16885 = v16884->timer;
  int v16893 = v16885 + 1;
  v16884->timer = v16893;
  int * v16887 = v16884->regs;
  int v16888 = v16887[23];
  int v16889 = v16887[24];
  int v16897 = v16888 | v16889;
  v16887[23] = v16897;
  struct StateT * v16891 = slot_248(v16884);
  return v16891;
}

struct StateT * slot_113(struct StateT * v6839) {
  int v6840 = v6839->timer;
  int v6848 = v6840 + 1;
  v6839->timer = v6848;
  int * v6842 = v6839->regs;
  int v6843 = v6842[30];
  int v6844 = v6842[8];
  int v6853 = v6843 + v6844;
  v6842[20] = v6853;
  struct StateT * v6846 = slot_114(v6839);
  return v6846;
}

struct StateT * slot_302(struct StateT * v18103) {
  int v18104 = v18103->timer;
  int v18111 = v18104 + 1;
  v18103->timer = v18111;
  int * v18106 = v18103->regs;
  int v18107 = v18106[20];
  int v18114 = v18107 << 18;
  v18106[20] = v18114;
  struct StateT * v18109 = slot_303(v18103);
  return v18109;
}

struct StateT * slot_388(struct StateT * v19441) {
  int v19442 = v19441->timer;
  int v19449 = v19442 + 1;
  v19441->timer = v19449;
  int * v19444 = v19441->regs;
  int v19445 = v19444[22];
  int v19452 = v19445 << 18;
  v19444[22] = v19452;
  struct StateT * v19447 = slot_389(v19441);
  return v19447;
}

struct StateT * slot_191(struct StateT * v8055) {
  int v8056 = v8055->timer;
  int v8064 = v8056 + 1;
  v8055->timer = v8064;
  int * v8058 = v8055->regs;
  int v8059 = v8058[28];
  int v8060 = v8058[22];
  int v8068 = v8059 ^ v8060;
  v8058[28] = v8068;
  struct StateT * v8062 = slot_192(v8055);
  return v8062;
}

struct StateT * slot_103(struct StateT * v6657) {
  int v6658 = v6657->timer;
  int v6665 = v6658 + 1;
  v6657->timer = v6665;
  int * v6660 = v6657->regs;
  int v6661 = v6660[22];
  int v6669 = (int)((unsigned int)v6661 >> 14);
  v6660[24] = v6669;
  struct StateT * v6663 = slot_104(v6657);
  return v6663;
}

struct StateT * slot_487(struct StateT * v21125) {
  int v21126 = v21125->timer;
  int v21133 = v21126 + 1;
  v21125->timer = v21133;
  int * v21128 = v21125->regs;
  int v21129 = v21128[21];
  int v21136 = v21129 << 7;
  v21128[21] = v21136;
  struct StateT * v21131 = slot_488(v21125);
  return v21131;
}

struct StateT * slot_324(struct StateT * v18445) {
  int v18446 = v18445->timer;
  int v18453 = v18446 + 1;
  v18445->timer = v18453;
  int * v18448 = v18445->regs;
  int v18449 = v18448[21];
  int v18457 = (int)((unsigned int)v18449 >> 25);
  v18448[24] = v18457;
  struct StateT * v18451 = slot_325(v18445);
  return v18451;
}

struct StateT * slot_440(struct StateT * v20334) {
  int v20335 = v20334->timer;
  int v20343 = v20335 + 1;
  v20334->timer = v20343;
  int * v20337 = v20334->regs;
  int v20338 = v20337[7];
  int v20339 = v20337[18];
  int v20348 = v20338 + v20339;
  v20337[21] = v20348;
  struct StateT * v20341 = slot_441(v20334);
  return v20341;
}

struct StateT * slot_547(struct StateT * v22061) {
  int v22062 = v22061->timer;
  int v22069 = v22062 + 1;
  v22061->timer = v22069;
  int * v22064 = v22061->regs;
  int v22065 = v22064[21];
  int v22072 = v22065 << 18;
  v22064[21] = v22072;
  struct StateT * v22067 = slot_548(v22061);
  return v22067;
}

struct StateT * slot_518(struct StateT * v21605) {
  int v21606 = v21605->timer;
  int v21614 = v21606 + 1;
  v21605->timer = v21614;
  int * v21608 = v21605->regs;
  int v21609 = v21608[7];
  int v21610 = v21608[23];
  int v21618 = v21609 ^ v21610;
  v21608[7] = v21618;
  struct StateT * v21612 = slot_519(v21605);
  return v21612;
}

struct StateT * slot_95(struct StateT * v6533) {
  int v6534 = v6533->timer;
  int v6542 = v6534 + 1;
  v6533->timer = v6542;
  int * v6536 = v6533->regs;
  int v6537 = v6536[12];
  int v6538 = v6536[17];
  int v6547 = v6537 + v6538;
  v6536[22] = v6547;
  struct StateT * v6540 = slot_96(v6533);
  return v6540;
}

struct StateT * slot_451(struct StateT * v20504) {
  int v20505 = v20504->timer;
  int v20513 = v20505 + 1;
  v20504->timer = v20513;
  int * v20507 = v20504->regs;
  int v20508 = v20507[22];
  int v20509 = v20507[24];
  int v20517 = v20508 | v20509;
  v20507[22] = v20517;
  struct StateT * v20511 = slot_452(v20504);
  return v20511;
}

struct StateT * slot_458(struct StateT * v20634) {
  int * v20635 = v20634->saved_regs;
  int * v20636 = v20634->regs;
  int v20637 = v20636[15];
  v20635[15] = v20637;
  int v20639 = v20634->timer;
  int v20651 = v20639 + 1;
  v20634->timer = v20651;
  int * v20641 = v20634->regs;
  int v20642 = v20641[15];
  int v20643 = v20641[23];
  int v20654 = v20642 ^ v20643;
  v20641[15] = v20654;
  struct StateT * v20645 = slot_459(v20634);
  return v20645;
}

struct StateT * slot_415(struct StateT * v19885) {
  int * v19886 = v19885->saved_regs;
  int * v19887 = v19885->regs;
  int v19888 = v19887[9];
  v19886[9] = v19888;
  int v19890 = v19885->timer;
  int v19902 = v19890 + 1;
  v19885->timer = v19902;
  int * v19892 = v19885->regs;
  int v19893 = v19892[9];
  int v19894 = v19892[20];
  int v19905 = v19893 ^ v19894;
  v19892[9] = v19905;
  struct StateT * v19896 = slot_416(v19885);
  return v19896;
}

struct StateT * slot_354(struct StateT * v18908) {
  int v18909 = v18908->timer;
  int v18917 = v18909 + 1;
  v18908->timer = v18917;
  int * v18911 = v18908->regs;
  int v18912 = v18911[5];
  int v18913 = v18911[21];
  int v18921 = v18912 ^ v18913;
  v18911[5] = v18921;
  struct StateT * v18915 = slot_355(v18908);
  return v18915;
}

struct StateT * slot_531(struct StateT * v21808) {
  int v21809 = v21808->timer;
  int v21817 = v21809 + 1;
  v21808->timer = v21817;
  int * v21811 = v21808->regs;
  int v21812 = v21811[22];
  int v21813 = v21811[24];
  int v21821 = v21812 | v21813;
  v21811[22] = v21821;
  struct StateT * v21815 = slot_532(v21808);
  return v21815;
}

struct StateT * slot_115(struct StateT * v6873) {
  int v6874 = v6873->timer;
  int v6882 = v6874 + 1;
  v6873->timer = v6882;
  int * v6876 = v6873->regs;
  int v6877 = v6876[28];
  int v6878 = v6876[18];
  int v6887 = v6877 + v6878;
  v6876[22] = v6887;
  struct StateT * v6880 = slot_116(v6873);
  return v6880;
}

struct StateT * slot_78(struct StateT * v6242) {
  int v6243 = v6242->timer;
  int v6250 = v6243 + 1;
  v6242->timer = v6250;
  int * v6245 = v6242->regs;
  int v6246 = v6245[20];
  int v6253 = v6246 << 13;
  v6245[20] = v6253;
  struct StateT * v6248 = slot_79(v6242);
  return v6248;
}

struct StateT * slot_321(struct StateT * v18400) {
  int v18401 = v18400->timer;
  int v18408 = v18401 + 1;
  v18400->timer = v18408;
  int * v18403 = v18400->regs;
  int v18404 = v18403[20];
  int v18412 = (int)((unsigned int)v18404 >> 25);
  v18403[24] = v18412;
  struct StateT * v18406 = slot_322(v18400);
  return v18406;
}

struct StateT * slot_317(struct StateT * v18332) {
  int v18333 = v18332->timer;
  int v18341 = v18333 + 1;
  v18332->timer = v18341;
  int * v18335 = v18332->regs;
  int v18336 = v18335[30];
  int v18337 = v18335[8];
  int v18346 = v18336 + v18337;
  v18335[20] = v18346;
  struct StateT * v18339 = slot_318(v18332);
  return v18339;
}

struct StateT * slot_558(struct StateT * v22229) {
  int v22230 = v22229->timer;
  int v22238 = v22230 + 1;
  v22229->timer = v22238;
  int * v22232 = v22229->regs;
  int v22233 = v22232[31];
  int v22234 = v22232[23];
  int v22242 = v22233 ^ v22234;
  v22232[31] = v22242;
  struct StateT * v22236 = slot_559(v22229);
  return v22236;
}

struct StateT * slot_193(struct StateT * v8087) {
  int * v8088 = v8087->saved_regs;
  int * v8089 = v8087->regs;
  int v8090 = v8089[13];
  v8088[13] = v8090;
  int v8092 = v8087->timer;
  int v8103 = v8092 + 1;
  v8087->timer = v8103;
  int * v8094 = v8087->regs;
  int v8095 = v8094[13];
  int v8105 = v8095 + 1;
  v8094[13] = v8105;
  struct StateT * v8097 = slot_194(v8087);
  return v8097;
}

struct StateT * slot_554(struct StateT * v22165) {
  int v22166 = v22165->timer;
  int v22174 = v22166 + 1;
  v22165->timer = v22174;
  int * v22168 = v22165->regs;
  int v22169 = v22168[23];
  int v22170 = v22168[24];
  int v22178 = v22169 | v22170;
  v22168[23] = v22178;
  struct StateT * v22172 = slot_555(v22165);
  return v22172;
}

struct StateT * slot_375(struct StateT * v19236) {
  int v19237 = v19236->timer;
  int v19245 = v19237 + 1;
  v19236->timer = v19245;
  int * v19239 = v19236->regs;
  int v19240 = v19239[18];
  int v19241 = v19239[22];
  int v19249 = v19240 ^ v19241;
  v19239[18] = v19249;
  struct StateT * v19243 = slot_376(v19236);
  return v19243;
}

struct StateT * slot_331(struct StateT * v18550) {
  int v18551 = v18550->timer;
  int v18558 = v18551 + 1;
  v18550->timer = v18558;
  int * v18553 = v18550->regs;
  int v18554 = v18553[23];
  int v18561 = v18554 << 7;
  v18553[23] = v18561;
  struct StateT * v18556 = slot_332(v18550);
  return v18556;
}

struct StateT * slot_380(struct StateT * v19319) {
  int v19320 = v19319->timer;
  int v19328 = v19320 + 1;
  v19319->timer = v19328;
  int * v19322 = v19319->regs;
  int v19323 = v19322[19];
  int v19324 = v19322[7];
  int v19333 = v19323 + v19324;
  v19322[23] = v19333;
  struct StateT * v19326 = slot_381(v19319);
  return v19326;
}

struct StateT * slot_412(struct StateT * v19840) {
  int v19841 = v19840->timer;
  int v19848 = v19841 + 1;
  v19840->timer = v19848;
  int * v19843 = v19840->regs;
  int v19844 = v19843[23];
  int v19852 = (int)((unsigned int)v19844 >> 25);
  v19843[24] = v19852;
  struct StateT * v19846 = slot_413(v19840);
  return v19846;
}

struct StateT * slot_381(struct StateT * v19336) {
  int v19337 = v19336->timer;
  int v19344 = v19337 + 1;
  v19336->timer = v19344;
  int * v19339 = v19336->regs;
  int v19340 = v19339[20];
  int v19348 = (int)((unsigned int)v19340 >> 14);
  v19339[24] = v19348;
  struct StateT * v19342 = slot_382(v19336);
  return v19342;
}

struct StateT * slot_478(struct StateT * v20974) {
  int * v20975 = v20974->saved_regs;
  int * v20976 = v20974->regs;
  int v20977 = v20976[31];
  v20975[31] = v20977;
  int v20979 = v20974->timer;
  int v20991 = v20979 + 1;
  v20974->timer = v20991;
  int * v20981 = v20974->regs;
  int v20982 = v20981[31];
  int v20983 = v20981[23];
  int v20994 = v20982 ^ v20983;
  v20981[31] = v20994;
  struct StateT * v20985 = slot_479(v20974);
  return v20985;
}

struct StateT * slot_210(struct StateT * v11237) {
  int v11238 = v11237->timer;
  int v11408 = v11238 + 1;
  v11237->timer = v11408;
  int * v11240 = v11237->regs;
  int v11241 = v11240[10];
  int v11242 = v11240[31];
  int * v11243 = v11237->cache_tags;
  int v11413 = (((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2;
  int v11244 = v11243[v11413];
  int v11414 = ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11245 = v11243[v11414];
  int v11415 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2);
  int v11246 = v11243[v11415];
  int v11416 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11247 = v11243[v11416];
  int v11248 = v11237->timer;
  int v11417 = v11248 + ((100 ^ (((~(((v11246 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11246 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11244 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11244 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11245 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11245 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11246 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11246 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11237->timer = v11417;
  bool v11418 = !(((~(((v11244 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11244 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11245 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11245 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v11342;
  if (v11418) {
    int * v11250 = v11237->cache_age;
    int v11420 = ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v11245 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11245 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v11251 = v11250[v11420];
    int v11252 = v11250[v11413];
    int v11421 = v11252 + ((int)((unsigned int)(v11252 - v11251) >> 31));
    v11250[v11413] = v11421;
    int * v11254 = v11237->cache_age;
    int v11255 = v11254[v11414];
    int v11423 = v11255 + ((int)((unsigned int)(v11255 - v11251) >> 31));
    v11254[v11414] = v11423;
    int * v11257 = v11237->cache_age;
    v11257[v11420] = 0;
    v11342 = v11420;
  } else {
    int * v11260 = v11237->cache_age;
    int v11427 = (((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2;
    int v11261 = v11260[v11427];
    int * v11262 = v11237->cache_tags;
    int v11263 = v11262[v11427];
    int v11264 = v11260[v11414];
    int v11265 = v11262[v11414];
    bool v11429 = !(((~(((v11246 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11246 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v11319;
    if (v11429) {
      int * v11266 = v11237->cache_age;
      int v11431 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11247 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v11267 = v11266[v11431];
      int v11268 = v11266[v11415];
      int v11432 = v11268 + ((int)((unsigned int)(v11268 - v11267) >> 31));
      v11266[v11415] = v11432;
      int * v11270 = v11237->cache_age;
      int v11271 = v11270[v11416];
      int v11434 = v11271 + ((int)((unsigned int)(v11271 - v11267) >> 31));
      v11270[v11416] = v11434;
      int * v11273 = v11237->cache_age;
      v11273[v11431] = 0;
      v11319 = v11431;
    } else {
      int * v11276 = v11237->cache_age;
      int v11438 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2);
      int v11277 = v11276[v11438];
      int * v11278 = v11237->cache_tags;
      int v11279 = v11278[v11438];
      int v11280 = v11276[v11416];
      int v11281 = v11278[v11416];
      int * v11282 = v11237->cache_dirty;
      int v11441 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11277 + ((~(((v11279 ^ -1) | (-(v11279 ^ -1))) >> 31)) & 2)) - (v11280 + ((~(((v11281 ^ -1) | (-(v11281 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11283 = v11282[v11441];
      bool v11442 = !(v11283 == 0);
      if (v11442) {
        int * v11284 = v11237->cache_tags;
        int v11285 = v11284[v11441];
        int * v11286 = v11237->cache_vals;
        int v11445 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11277 + ((~(((v11279 ^ -1) | (-(v11279 ^ -1))) >> 31)) & 2)) - (v11280 + ((~(((v11281 ^ -1) | (-(v11281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11287 = v11286[v11445];
        int v11446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11277 + ((~(((v11279 ^ -1) | (-(v11279 ^ -1))) >> 31)) & 2)) - (v11280 + ((~(((v11281 ^ -1) | (-(v11281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11288 = v11286[v11446];
        int * v11289 = v11237->mem;
        int v11448 = v11285 * 2;
        v11289[v11448] = v11287;
        int * v11291 = v11237->mem;
        int v11451 = (v11285 * 2) + 1;
        v11291[v11451] = v11288;
        ;
      } else {
        ;
      }
      int * v11296 = v11237->mem;
      int v11456 = ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) * 2;
      int v11297 = v11296[v11456];
      int v11457 = (((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) * 2) + 1;
      int v11298 = v11296[v11457];
      int * v11299 = v11237->cache_vals;
      int v11459 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11277 + ((~(((v11279 ^ -1) | (-(v11279 ^ -1))) >> 31)) & 2)) - (v11280 + ((~(((v11281 ^ -1) | (-(v11281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11299[v11459] = v11297;
      int * v11301 = v11237->cache_vals;
      int v11462 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11277 + ((~(((v11279 ^ -1) | (-(v11279 ^ -1))) >> 31)) & 2)) - (v11280 + ((~(((v11281 ^ -1) | (-(v11281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11301[v11462] = v11298;
      int * v11303 = v11237->cache_tags;
      int v11465 = (int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1);
      v11303[v11441] = v11465;
      int * v11305 = v11237->cache_dirty;
      v11305[v11441] = 0;
      int * v11307 = v11237->cache_age;
      v11307[v11441] = 1;
      int * v11309 = v11237->cache_age;
      int v11310 = v11309[v11441];
      int v11311 = v11309[v11415];
      int v11471 = v11311 + ((int)((unsigned int)(v11311 - v11310) >> 31));
      v11309[v11415] = v11471;
      int * v11313 = v11237->cache_age;
      int v11314 = v11313[v11416];
      int v11473 = v11314 + ((int)((unsigned int)(v11314 - v11310) >> 31));
      v11313[v11416] = v11473;
      int * v11316 = v11237->cache_age;
      v11316[v11441] = 0;
      v11319 = v11441;
    }
    int * v11320 = v11237->cache_vals;
    int v11476 = v11319 * 2;
    int v11321 = v11320[v11476];
    int v11477 = (v11319 * 2) + 1;
    int v11322 = v11320[v11477];
    int v11478 = (((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v11261 + ((~(((v11263 ^ -1) | (-(v11263 ^ -1))) >> 31)) & 2)) - (v11264 + ((~(((v11265 ^ -1) | (-(v11265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11320[v11478] = v11321;
    int * v11324 = v11237->cache_vals;
    int v11481 = ((((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v11261 + ((~(((v11263 ^ -1) | (-(v11263 ^ -1))) >> 31)) & 2)) - (v11264 + ((~(((v11265 ^ -1) | (-(v11265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11324[v11481] = v11322;
    int * v11326 = v11237->cache_tags;
    int v11484 = ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v11261 + ((~(((v11263 ^ -1) | (-(v11263 ^ -1))) >> 31)) & 2)) - (v11264 + ((~(((v11265 ^ -1) | (-(v11265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11485 = (int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1);
    v11326[v11484] = v11485;
    int * v11328 = v11237->cache_dirty;
    v11328[v11484] = 0;
    int * v11330 = v11237->cache_age;
    v11330[v11484] = 1;
    int * v11332 = v11237->cache_age;
    int v11333 = v11332[v11484];
    int v11334 = v11332[v11413];
    int v11491 = v11334 + ((int)((unsigned int)(v11334 - v11333) >> 31));
    v11332[v11413] = v11491;
    int * v11336 = v11237->cache_age;
    int v11337 = v11336[v11414];
    int v11493 = v11337 + ((int)((unsigned int)(v11337 - v11333) >> 31));
    v11336[v11414] = v11493;
    int * v11339 = v11237->cache_age;
    v11339[v11484] = 0;
    v11342 = v11484;
  }
  int * v11343 = v11237->cache_vals;
  int v11496 = (v11342 * 2) + (((int)((unsigned int)(v11241 + 12) >> 2)) & 1);
  v11343[v11496] = v11242;
  int * v11345 = v11237->cache_tags;
  int v11346 = v11345[v11415];
  int v11347 = v11345[v11416];
  bool v11499 = !(((~(((v11346 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11346 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v11347 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11347 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v11401;
  if (v11499) {
    int * v11348 = v11237->cache_age;
    int v11501 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11347 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))) | (-(v11347 ^ ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v11349 = v11348[v11501];
    int v11350 = v11348[v11415];
    int v11502 = v11350 + ((int)((unsigned int)(v11350 - v11349) >> 31));
    v11348[v11415] = v11502;
    int * v11352 = v11237->cache_age;
    int v11353 = v11352[v11416];
    int v11504 = v11353 + ((int)((unsigned int)(v11353 - v11349) >> 31));
    v11352[v11416] = v11504;
    int * v11355 = v11237->cache_age;
    v11355[v11501] = 0;
    v11401 = v11501;
  } else {
    int * v11358 = v11237->cache_age;
    int v11508 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2);
    int v11359 = v11358[v11508];
    int * v11360 = v11237->cache_tags;
    int v11361 = v11360[v11508];
    int v11362 = v11358[v11416];
    int v11363 = v11360[v11416];
    int * v11364 = v11237->cache_dirty;
    int v11511 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11359 + ((~(((v11361 ^ -1) | (-(v11361 ^ -1))) >> 31)) & 2)) - (v11362 + ((~(((v11363 ^ -1) | (-(v11363 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11365 = v11364[v11511];
    bool v11512 = !(v11365 == 0);
    if (v11512) {
      int * v11366 = v11237->cache_tags;
      int v11367 = v11366[v11511];
      int * v11368 = v11237->cache_vals;
      int v11515 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11359 + ((~(((v11361 ^ -1) | (-(v11361 ^ -1))) >> 31)) & 2)) - (v11362 + ((~(((v11363 ^ -1) | (-(v11363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11369 = v11368[v11515];
      int v11516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11359 + ((~(((v11361 ^ -1) | (-(v11361 ^ -1))) >> 31)) & 2)) - (v11362 + ((~(((v11363 ^ -1) | (-(v11363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11370 = v11368[v11516];
      int * v11371 = v11237->mem;
      int v11518 = v11367 * 2;
      v11371[v11518] = v11369;
      int * v11373 = v11237->mem;
      int v11521 = (v11367 * 2) + 1;
      v11373[v11521] = v11370;
      ;
    } else {
      ;
    }
    int * v11378 = v11237->mem;
    int v11526 = ((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) * 2;
    int v11379 = v11378[v11526];
    int v11527 = (((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) * 2) + 1;
    int v11380 = v11378[v11527];
    int * v11381 = v11237->cache_vals;
    int v11529 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11359 + ((~(((v11361 ^ -1) | (-(v11361 ^ -1))) >> 31)) & 2)) - (v11362 + ((~(((v11363 ^ -1) | (-(v11363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11381[v11529] = v11379;
    int * v11383 = v11237->cache_vals;
    int v11532 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v11359 + ((~(((v11361 ^ -1) | (-(v11361 ^ -1))) >> 31)) & 2)) - (v11362 + ((~(((v11363 ^ -1) | (-(v11363 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11383[v11532] = v11380;
    int * v11385 = v11237->cache_tags;
    int v11535 = (int)((unsigned int)((int)((unsigned int)(v11241 + 12) >> 2)) >> 1);
    v11385[v11511] = v11535;
    int * v11387 = v11237->cache_dirty;
    v11387[v11511] = 0;
    int * v11389 = v11237->cache_age;
    v11389[v11511] = 1;
    int * v11391 = v11237->cache_age;
    int v11392 = v11391[v11511];
    int v11393 = v11391[v11415];
    int v11541 = v11393 + ((int)((unsigned int)(v11393 - v11392) >> 31));
    v11391[v11415] = v11541;
    int * v11395 = v11237->cache_age;
    int v11396 = v11395[v11416];
    int v11543 = v11396 + ((int)((unsigned int)(v11396 - v11392) >> 31));
    v11395[v11416] = v11543;
    int * v11398 = v11237->cache_age;
    v11398[v11511] = 0;
    v11401 = v11511;
  }
  int * v11402 = v11237->cache_vals;
  int v11546 = (v11401 * 2) + (((int)((unsigned int)(v11241 + 12) >> 2)) & 1);
  v11402[v11546] = v11242;
  int * v11404 = v11237->cache_dirty;
  v11404[v11401] = 1;
  struct StateT * v11406 = slot_213(v11237);
  return v11406;
}

struct StateT * slot_472(struct StateT * v20860) {
  int v20861 = v20860->timer;
  int v20868 = v20861 + 1;
  v20860->timer = v20868;
  int * v20863 = v20860->regs;
  int v20864 = v20863[23];
  int v20872 = (int)((unsigned int)v20864 >> 14);
  v20863[24] = v20872;
  struct StateT * v20866 = slot_473(v20860);
  return v20866;
}

struct StateT * slot_284(struct StateT * v17821) {
  int v17822 = v17821->timer;
  int v17829 = v17822 + 1;
  v17821->timer = v17829;
  int * v17824 = v17821->regs;
  int v17825 = v17824[21];
  int v17833 = (int)((unsigned int)v17825 >> 19);
  v17824[24] = v17833;
  struct StateT * v17827 = slot_285(v17821);
  return v17827;
}

struct StateT * slot_52(struct StateT * v5796) {
  int * v5797 = v5796->saved_regs;
  int * v5798 = v5796->regs;
  int v5799 = v5798[8];
  v5797[8] = v5799;
  int v5801 = v5796->timer;
  int v5813 = v5801 + 1;
  v5796->timer = v5813;
  int * v5803 = v5796->regs;
  int v5804 = v5803[8];
  int v5805 = v5803[23];
  int v5816 = v5804 ^ v5805;
  v5803[8] = v5816;
  struct StateT * v5807 = slot_53(v5796);
  return v5807;
}

struct StateT * slot_83(struct StateT * v6317) {
  int v6318 = v6317->timer;
  int v6325 = v6318 + 1;
  v6317->timer = v6325;
  int * v6320 = v6317->regs;
  int v6321 = v6320[22];
  int v6329 = (int)((unsigned int)v6321 >> 19);
  v6320[24] = v6329;
  struct StateT * v6323 = slot_84(v6317);
  return v6323;
}

struct StateT * slot_209(struct StateT * v11220) {
  int v11221 = v11220->timer;
  int v11229 = v11221 + 1;
  v11220->timer = v11229;
  int * v11223 = v11220->regs;
  int v11224 = v11223[31];
  int v11225 = v11223[15];
  int v11234 = v11224 + v11225;
  v11223[23] = v11234;
  struct StateT * v11227 = slot_212(v11220);
  return v11227;
}

struct StateT * slot_420(struct StateT * v19994) {
  int v19995 = v19994->timer;
  int v20003 = v19995 + 1;
  v19994->timer = v20003;
  int * v19997 = v19994->regs;
  int v19998 = v19997[18];
  int v19999 = v19997[29];
  int v20008 = v19998 + v19999;
  v19997[21] = v20008;
  struct StateT * v20001 = slot_421(v19994);
  return v20001;
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

struct StateT * slot_73(struct StateT * v6159) {
  int v6160 = v6159->timer;
  int v6168 = v6160 + 1;
  v6159->timer = v6168;
  int * v6162 = v6159->regs;
  int v6163 = v6162[6];
  int v6164 = v6162[9];
  int v6173 = v6163 + v6164;
  v6162[20] = v6173;
  struct StateT * v6166 = slot_74(v6159);
  return v6166;
}

struct StateT * slot_270(struct StateT * v17599) {
  int v17600 = v17599->timer;
  int v17607 = v17600 + 1;
  v17599->timer = v17607;
  int * v17602 = v17599->regs;
  int v17603 = v17602[23];
  int v17611 = (int)((unsigned int)v17603 >> 23);
  v17602[24] = v17611;
  struct StateT * v17605 = slot_271(v17599);
  return v17605;
}

struct StateT * slot_198(struct StateT * v8942) {
  int * v8943 = v8942->regs;
  int v8944 = v8943[11];
  int v8945 = v8943[13];
  bool v8957 = (v8944 ^ -2147483648) >= (v8945 ^ -2147483648);
  struct StateT * v8952;
  if (v8957) {
    int v8946 = v8942->timer;
    int v8958 = v8946 + 15;
    v8942->timer = v8958;
    struct StateT * v8948 = slot_200(v8942);
    v8952 = v8948;
  } else {
    struct StateT * v8950 = slot_201(v8942);
    v8952 = v8950;
  }
  return v8952;
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

struct StateT * slot_187(struct StateT * v7993) {
  int v7994 = v7993->timer;
  int v8001 = v7994 + 1;
  v7993->timer = v8001;
  int * v7996 = v7993->regs;
  int v7997 = v7996[23];
  int v8004 = v7997 << 18;
  v7996[23] = v8004;
  struct StateT * v7999 = slot_188(v7993);
  return v7999;
}

struct StateT * slot_446(struct StateT * v20430) {
  int v20431 = v20430->timer;
  int v20438 = v20431 + 1;
  v20430->timer = v20438;
  int * v20433 = v20430->regs;
  int v20434 = v20433[21];
  int v20442 = (int)((unsigned int)v20434 >> 19);
  v20433[24] = v20442;
  struct StateT * v20436 = slot_447(v20430);
  return v20436;
}

struct StateT * slot_182(struct StateT * v7917) {
  int v7918 = v7917->timer;
  int v7926 = v7918 + 1;
  v7917->timer = v7926;
  int * v7920 = v7917->regs;
  int v7921 = v7920[21];
  int v7922 = v7920[24];
  int v7930 = v7921 | v7922;
  v7920[21] = v7930;
  struct StateT * v7924 = slot_183(v7917);
  return v7924;
}

struct StateT * slot_361(struct StateT * v19024) {
  int v19025 = v19024->timer;
  int v19032 = v19025 + 1;
  v19024->timer = v19032;
  int * v19027 = v19024->regs;
  int v19028 = v19027[20];
  int v19036 = (int)((unsigned int)v19028 >> 19);
  v19027[24] = v19036;
  struct StateT * v19030 = slot_362(v19024);
  return v19030;
}

struct StateT * slot_38(struct StateT * v5562) {
  int v5563 = v5562->timer;
  int v5570 = v5563 + 1;
  v5562->timer = v5570;
  int * v5565 = v5562->regs;
  int v5566 = v5565[20];
  int v5573 = v5566 << 7;
  v5565[20] = v5573;
  struct StateT * v5568 = slot_39(v5562);
  return v5568;
}

struct StateT * slot_178(struct StateT * v7858) {
  int v7859 = v7858->timer;
  int v7866 = v7859 + 1;
  v7858->timer = v7866;
  int * v7861 = v7858->regs;
  int v7862 = v7861[20];
  int v7869 = v7862 << 18;
  v7861[20] = v7869;
  struct StateT * v7864 = slot_179(v7858);
  return v7864;
}

struct StateT * slot_98(struct StateT * v6582) {
  int v6583 = v6582->timer;
  int v6590 = v6583 + 1;
  v6582->timer = v6590;
  int * v6585 = v6582->regs;
  int v6586 = v6585[20];
  int v6593 = v6586 << 18;
  v6585[20] = v6593;
  struct StateT * v6588 = slot_99(v6582);
  return v6588;
}

struct StateT * slot_159(struct StateT * v7560) {
  int v7561 = v7560->timer;
  int v7569 = v7561 + 1;
  v7560->timer = v7569;
  int * v7563 = v7560->regs;
  int v7564 = v7563[20];
  int v7565 = v7563[24];
  int v7573 = v7564 | v7565;
  v7563[20] = v7573;
  struct StateT * v7567 = slot_160(v7560);
  return v7567;
}

struct StateT * slot_510(struct StateT * v21482) {
  int v21483 = v21482->timer;
  int v21490 = v21483 + 1;
  v21482->timer = v21490;
  int * v21485 = v21482->regs;
  int v21486 = v21485[22];
  int v21493 = v21486 << 9;
  v21485[22] = v21493;
  struct StateT * v21488 = slot_511(v21482);
  return v21488;
}

struct StateT * slot_459(struct StateT * v20657) {
  int v20658 = v20657->timer;
  int v20666 = v20658 + 1;
  v20657->timer = v20666;
  int * v20660 = v20657->regs;
  int v20661 = v20660[16];
  int v20662 = v20660[6];
  int v20671 = v20661 + v20662;
  v20660[20] = v20671;
  struct StateT * v20664 = slot_460(v20657);
  return v20664;
}

struct StateT * slot_404(struct StateT * v19720) {
  int v19721 = v19720->timer;
  int v19728 = v19721 + 1;
  v19720->timer = v19728;
  int * v19723 = v19720->regs;
  int v19724 = v19723[20];
  int v19731 = v19724 << 7;
  v19723[20] = v19731;
  struct StateT * v19726 = slot_405(v19720);
  return v19726;
}

struct StateT * slot_46(struct StateT * v5682) {
  int v5683 = v5682->timer;
  int v5690 = v5683 + 1;
  v5682->timer = v5690;
  int * v5685 = v5682->regs;
  int v5686 = v5685[23];
  int v5694 = (int)((unsigned int)v5686 >> 25);
  v5685[24] = v5694;
  struct StateT * v5688 = slot_47(v5682);
  return v5688;
}

struct StateT * slot_212(struct StateT * v11867) {
  int v11868 = v11867->timer;
  int v11875 = v11868 + 1;
  v11867->timer = v11875;
  int * v11870 = v11867->regs;
  int v11871 = v11870[20];
  int v11879 = (int)((unsigned int)v11871 >> 25);
  v11870[24] = v11879;
  struct StateT * v11873 = slot_215(v11867);
  return v11873;
}

struct StateT * slot_132(struct StateT * v7135) {
  int v7136 = v7135->timer;
  int v7144 = v7136 + 1;
  v7135->timer = v7144;
  int * v7138 = v7135->regs;
  int v7139 = v7138[16];
  int v7140 = v7138[23];
  int v7148 = v7139 ^ v7140;
  v7138[16] = v7148;
  struct StateT * v7142 = slot_133(v7135);
  return v7142;
}

struct StateT * slot_313(struct StateT * v18268) {
  int v18269 = v18268->timer;
  int v18277 = v18269 + 1;
  v18268->timer = v18277;
  int * v18271 = v18268->regs;
  int v18272 = v18271[30];
  int v18273 = v18271[20];
  int v18281 = v18272 ^ v18273;
  v18271[30] = v18281;
  struct StateT * v18275 = slot_314(v18268);
  return v18275;
}

struct StateT * slot_553(struct StateT * v22151) {
  int v22152 = v22151->timer;
  int v22159 = v22152 + 1;
  v22151->timer = v22159;
  int * v22154 = v22151->regs;
  int v22155 = v22154[23];
  int v22162 = v22155 << 18;
  v22154[23] = v22162;
  struct StateT * v22157 = slot_554(v22151);
  return v22157;
}

struct StateT * slot_211(struct StateT * v11552) {
  int v11553 = v11552->timer;
  int v11723 = v11553 + 1;
  v11552->timer = v11723;
  int * v11555 = v11552->regs;
  int v11556 = v11555[10];
  int v11557 = v11555[6];
  int * v11558 = v11552->cache_tags;
  int v11728 = (((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2;
  int v11559 = v11558[v11728];
  int v11729 = ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v11560 = v11558[v11729];
  int v11730 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2);
  int v11561 = v11558[v11730];
  int v11731 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11562 = v11558[v11731];
  int v11563 = v11552->timer;
  int v11732 = v11563 + ((100 ^ (((~(((v11561 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11561 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v11559 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11559 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11560 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11560 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v11561 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11561 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v11552->timer = v11732;
  bool v11733 = !(((~(((v11559 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11559 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11560 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11560 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v11657;
  if (v11733) {
    int * v11565 = v11552->cache_age;
    int v11735 = ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v11560 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11560 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v11566 = v11565[v11735];
    int v11567 = v11565[v11728];
    int v11736 = v11567 + ((int)((unsigned int)(v11567 - v11566) >> 31));
    v11565[v11728] = v11736;
    int * v11569 = v11552->cache_age;
    int v11570 = v11569[v11729];
    int v11738 = v11570 + ((int)((unsigned int)(v11570 - v11566) >> 31));
    v11569[v11729] = v11738;
    int * v11572 = v11552->cache_age;
    v11572[v11735] = 0;
    v11657 = v11735;
  } else {
    int * v11575 = v11552->cache_age;
    int v11742 = (((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2;
    int v11576 = v11575[v11742];
    int * v11577 = v11552->cache_tags;
    int v11578 = v11577[v11742];
    int v11579 = v11575[v11729];
    int v11580 = v11577[v11729];
    bool v11744 = !(((~(((v11561 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11561 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v11634;
    if (v11744) {
      int * v11581 = v11552->cache_age;
      int v11746 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11562 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v11582 = v11581[v11746];
      int v11583 = v11581[v11730];
      int v11747 = v11583 + ((int)((unsigned int)(v11583 - v11582) >> 31));
      v11581[v11730] = v11747;
      int * v11585 = v11552->cache_age;
      int v11586 = v11585[v11731];
      int v11749 = v11586 + ((int)((unsigned int)(v11586 - v11582) >> 31));
      v11585[v11731] = v11749;
      int * v11588 = v11552->cache_age;
      v11588[v11746] = 0;
      v11634 = v11746;
    } else {
      int * v11591 = v11552->cache_age;
      int v11753 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2);
      int v11592 = v11591[v11753];
      int * v11593 = v11552->cache_tags;
      int v11594 = v11593[v11753];
      int v11595 = v11591[v11731];
      int v11596 = v11593[v11731];
      int * v11597 = v11552->cache_dirty;
      int v11756 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11592 + ((~(((v11594 ^ -1) | (-(v11594 ^ -1))) >> 31)) & 2)) - (v11595 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v11598 = v11597[v11756];
      bool v11757 = !(v11598 == 0);
      if (v11757) {
        int * v11599 = v11552->cache_tags;
        int v11600 = v11599[v11756];
        int * v11601 = v11552->cache_vals;
        int v11760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11592 + ((~(((v11594 ^ -1) | (-(v11594 ^ -1))) >> 31)) & 2)) - (v11595 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v11602 = v11601[v11760];
        int v11761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11592 + ((~(((v11594 ^ -1) | (-(v11594 ^ -1))) >> 31)) & 2)) - (v11595 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v11603 = v11601[v11761];
        int * v11604 = v11552->mem;
        int v11763 = v11600 * 2;
        v11604[v11763] = v11602;
        int * v11606 = v11552->mem;
        int v11766 = (v11600 * 2) + 1;
        v11606[v11766] = v11603;
        ;
      } else {
        ;
      }
      int * v11611 = v11552->mem;
      int v11771 = ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) * 2;
      int v11612 = v11611[v11771];
      int v11772 = (((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) * 2) + 1;
      int v11613 = v11611[v11772];
      int * v11614 = v11552->cache_vals;
      int v11774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11592 + ((~(((v11594 ^ -1) | (-(v11594 ^ -1))) >> 31)) & 2)) - (v11595 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v11614[v11774] = v11612;
      int * v11616 = v11552->cache_vals;
      int v11777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11592 + ((~(((v11594 ^ -1) | (-(v11594 ^ -1))) >> 31)) & 2)) - (v11595 + ((~(((v11596 ^ -1) | (-(v11596 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v11616[v11777] = v11613;
      int * v11618 = v11552->cache_tags;
      int v11780 = (int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1);
      v11618[v11756] = v11780;
      int * v11620 = v11552->cache_dirty;
      v11620[v11756] = 0;
      int * v11622 = v11552->cache_age;
      v11622[v11756] = 1;
      int * v11624 = v11552->cache_age;
      int v11625 = v11624[v11756];
      int v11626 = v11624[v11730];
      int v11786 = v11626 + ((int)((unsigned int)(v11626 - v11625) >> 31));
      v11624[v11730] = v11786;
      int * v11628 = v11552->cache_age;
      int v11629 = v11628[v11731];
      int v11788 = v11629 + ((int)((unsigned int)(v11629 - v11625) >> 31));
      v11628[v11731] = v11788;
      int * v11631 = v11552->cache_age;
      v11631[v11756] = 0;
      v11634 = v11756;
    }
    int * v11635 = v11552->cache_vals;
    int v11791 = v11634 * 2;
    int v11636 = v11635[v11791];
    int v11792 = (v11634 * 2) + 1;
    int v11637 = v11635[v11792];
    int v11793 = (((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v11576 + ((~(((v11578 ^ -1) | (-(v11578 ^ -1))) >> 31)) & 2)) - (v11579 + ((~(((v11580 ^ -1) | (-(v11580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11635[v11793] = v11636;
    int * v11639 = v11552->cache_vals;
    int v11796 = ((((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v11576 + ((~(((v11578 ^ -1) | (-(v11578 ^ -1))) >> 31)) & 2)) - (v11579 + ((~(((v11580 ^ -1) | (-(v11580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11639[v11796] = v11637;
    int * v11641 = v11552->cache_tags;
    int v11799 = ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v11576 + ((~(((v11578 ^ -1) | (-(v11578 ^ -1))) >> 31)) & 2)) - (v11579 + ((~(((v11580 ^ -1) | (-(v11580 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11800 = (int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1);
    v11641[v11799] = v11800;
    int * v11643 = v11552->cache_dirty;
    v11643[v11799] = 0;
    int * v11645 = v11552->cache_age;
    v11645[v11799] = 1;
    int * v11647 = v11552->cache_age;
    int v11648 = v11647[v11799];
    int v11649 = v11647[v11728];
    int v11806 = v11649 + ((int)((unsigned int)(v11649 - v11648) >> 31));
    v11647[v11728] = v11806;
    int * v11651 = v11552->cache_age;
    int v11652 = v11651[v11729];
    int v11808 = v11652 + ((int)((unsigned int)(v11652 - v11648) >> 31));
    v11651[v11729] = v11808;
    int * v11654 = v11552->cache_age;
    v11654[v11799] = 0;
    v11657 = v11799;
  }
  int * v11658 = v11552->cache_vals;
  int v11811 = (v11657 * 2) + (((int)((unsigned int)(v11556 + 24) >> 2)) & 1);
  v11658[v11811] = v11557;
  int * v11660 = v11552->cache_tags;
  int v11661 = v11660[v11730];
  int v11662 = v11660[v11731];
  bool v11814 = !(((~(((v11661 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11661 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v11662 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11662 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v11716;
  if (v11814) {
    int * v11663 = v11552->cache_age;
    int v11816 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v11662 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))) | (-(v11662 ^ ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v11664 = v11663[v11816];
    int v11665 = v11663[v11730];
    int v11817 = v11665 + ((int)((unsigned int)(v11665 - v11664) >> 31));
    v11663[v11730] = v11817;
    int * v11667 = v11552->cache_age;
    int v11668 = v11667[v11731];
    int v11819 = v11668 + ((int)((unsigned int)(v11668 - v11664) >> 31));
    v11667[v11731] = v11819;
    int * v11670 = v11552->cache_age;
    v11670[v11816] = 0;
    v11716 = v11816;
  } else {
    int * v11673 = v11552->cache_age;
    int v11823 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2);
    int v11674 = v11673[v11823];
    int * v11675 = v11552->cache_tags;
    int v11676 = v11675[v11823];
    int v11677 = v11673[v11731];
    int v11678 = v11675[v11731];
    int * v11679 = v11552->cache_dirty;
    int v11826 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11674 + ((~(((v11676 ^ -1) | (-(v11676 ^ -1))) >> 31)) & 2)) - (v11677 + ((~(((v11678 ^ -1) | (-(v11678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v11680 = v11679[v11826];
    bool v11827 = !(v11680 == 0);
    if (v11827) {
      int * v11681 = v11552->cache_tags;
      int v11682 = v11681[v11826];
      int * v11683 = v11552->cache_vals;
      int v11830 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11674 + ((~(((v11676 ^ -1) | (-(v11676 ^ -1))) >> 31)) & 2)) - (v11677 + ((~(((v11678 ^ -1) | (-(v11678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v11684 = v11683[v11830];
      int v11831 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11674 + ((~(((v11676 ^ -1) | (-(v11676 ^ -1))) >> 31)) & 2)) - (v11677 + ((~(((v11678 ^ -1) | (-(v11678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v11685 = v11683[v11831];
      int * v11686 = v11552->mem;
      int v11833 = v11682 * 2;
      v11686[v11833] = v11684;
      int * v11688 = v11552->mem;
      int v11836 = (v11682 * 2) + 1;
      v11688[v11836] = v11685;
      ;
    } else {
      ;
    }
    int * v11693 = v11552->mem;
    int v11841 = ((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) * 2;
    int v11694 = v11693[v11841];
    int v11842 = (((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) * 2) + 1;
    int v11695 = v11693[v11842];
    int * v11696 = v11552->cache_vals;
    int v11844 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11674 + ((~(((v11676 ^ -1) | (-(v11676 ^ -1))) >> 31)) & 2)) - (v11677 + ((~(((v11678 ^ -1) | (-(v11678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v11696[v11844] = v11694;
    int * v11698 = v11552->cache_vals;
    int v11847 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v11674 + ((~(((v11676 ^ -1) | (-(v11676 ^ -1))) >> 31)) & 2)) - (v11677 + ((~(((v11678 ^ -1) | (-(v11678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v11698[v11847] = v11695;
    int * v11700 = v11552->cache_tags;
    int v11850 = (int)((unsigned int)((int)((unsigned int)(v11556 + 24) >> 2)) >> 1);
    v11700[v11826] = v11850;
    int * v11702 = v11552->cache_dirty;
    v11702[v11826] = 0;
    int * v11704 = v11552->cache_age;
    v11704[v11826] = 1;
    int * v11706 = v11552->cache_age;
    int v11707 = v11706[v11826];
    int v11708 = v11706[v11730];
    int v11856 = v11708 + ((int)((unsigned int)(v11708 - v11707) >> 31));
    v11706[v11730] = v11856;
    int * v11710 = v11552->cache_age;
    int v11711 = v11710[v11731];
    int v11858 = v11711 + ((int)((unsigned int)(v11711 - v11707) >> 31));
    v11710[v11731] = v11858;
    int * v11713 = v11552->cache_age;
    v11713[v11826] = 0;
    v11716 = v11826;
  }
  int * v11717 = v11552->cache_vals;
  int v11861 = (v11716 * 2) + (((int)((unsigned int)(v11556 + 24) >> 2)) & 1);
  v11717[v11861] = v11557;
  int * v11719 = v11552->cache_dirty;
  v11719[v11716] = 1;
  struct StateT * v11721 = slot_214(v11552);
  return v11721;
}

struct StateT * slot_20(struct StateT * v4700) {
  int v4701 = v4700->timer;
  int v4811 = v4701 + 1;
  v4700->timer = v4811;
  int * v4703 = v4700->regs;
  int v4704 = v4703[11];
  int * v4705 = v4700->cache_tags;
  int v4815 = (((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4706 = v4705[v4815];
  int v4816 = ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4707 = v4705[v4816];
  int v4817 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4708 = v4705[v4817];
  int v4818 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4709 = v4705[v4818];
  int v4710 = v4700->timer;
  int v4819 = v4710 + ((100 ^ (((~(((v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4700->timer = v4819;
  int * v4712 = v4700->cache_vals;
  bool v4820 = !(((~(((v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4805;
  if (v4820) {
    int * v4713 = v4700->cache_age;
    int v4822 = ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4714 = v4713[v4822];
    int v4715 = v4713[v4815];
    int v4823 = v4715 + ((int)((unsigned int)(v4715 - v4714) >> 31));
    v4713[v4815] = v4823;
    int * v4717 = v4700->cache_age;
    int v4718 = v4717[v4816];
    int v4825 = v4718 + ((int)((unsigned int)(v4718 - v4714) >> 31));
    v4717[v4816] = v4825;
    int * v4720 = v4700->cache_age;
    v4720[v4822] = 0;
    v4805 = v4822;
  } else {
    int * v4723 = v4700->cache_age;
    int v4829 = (((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4724 = v4723[v4829];
    int * v4725 = v4700->cache_tags;
    int v4726 = v4725[v4829];
    int v4727 = v4723[v4816];
    int v4728 = v4725[v4816];
    bool v4831 = !(((~(((v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4782;
    if (v4831) {
      int * v4729 = v4700->cache_age;
      int v4833 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4730 = v4729[v4833];
      int v4731 = v4729[v4817];
      int v4834 = v4731 + ((int)((unsigned int)(v4731 - v4730) >> 31));
      v4729[v4817] = v4834;
      int * v4733 = v4700->cache_age;
      int v4734 = v4733[v4818];
      int v4836 = v4734 + ((int)((unsigned int)(v4734 - v4730) >> 31));
      v4733[v4818] = v4836;
      int * v4736 = v4700->cache_age;
      v4736[v4833] = 0;
      v4782 = v4833;
    } else {
      int * v4739 = v4700->cache_age;
      int v4840 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4740 = v4739[v4840];
      int * v4741 = v4700->cache_tags;
      int v4742 = v4741[v4840];
      int v4743 = v4739[v4818];
      int v4744 = v4741[v4818];
      int * v4745 = v4700->cache_dirty;
      int v4843 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4746 = v4745[v4843];
      bool v4844 = !(v4746 == 0);
      if (v4844) {
        int * v4747 = v4700->cache_tags;
        int v4748 = v4747[v4843];
        int * v4749 = v4700->cache_vals;
        int v4847 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4750 = v4749[v4847];
        int v4848 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4751 = v4749[v4848];
        int * v4752 = v4700->mem;
        int v4850 = v4748 * 2;
        v4752[v4850] = v4750;
        int * v4754 = v4700->mem;
        int v4853 = (v4748 * 2) + 1;
        v4754[v4853] = v4751;
        ;
      } else {
        ;
      }
      int * v4759 = v4700->mem;
      int v4858 = ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) * 2;
      int v4760 = v4759[v4858];
      int v4859 = (((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4761 = v4759[v4859];
      int * v4762 = v4700->cache_vals;
      int v4861 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4762[v4861] = v4760;
      int * v4764 = v4700->cache_vals;
      int v4864 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4764[v4864] = v4761;
      int * v4766 = v4700->cache_tags;
      int v4867 = (int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1);
      v4766[v4843] = v4867;
      int * v4768 = v4700->cache_dirty;
      v4768[v4843] = 0;
      int * v4770 = v4700->cache_age;
      v4770[v4843] = 1;
      int * v4772 = v4700->cache_age;
      int v4773 = v4772[v4843];
      int v4774 = v4772[v4817];
      int v4873 = v4774 + ((int)((unsigned int)(v4774 - v4773) >> 31));
      v4772[v4817] = v4873;
      int * v4776 = v4700->cache_age;
      int v4777 = v4776[v4818];
      int v4875 = v4777 + ((int)((unsigned int)(v4777 - v4773) >> 31));
      v4776[v4818] = v4875;
      int * v4779 = v4700->cache_age;
      v4779[v4843] = 0;
      v4782 = v4843;
    }
    int * v4783 = v4700->cache_vals;
    int v4878 = v4782 * 2;
    int v4784 = v4783[v4878];
    int v4879 = (v4782 * 2) + 1;
    int v4785 = v4783[v4879];
    int v4880 = (((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4724 + ((~(((v4726 ^ -1) | (-(v4726 ^ -1))) >> 31)) & 2)) - (v4727 + ((~(((v4728 ^ -1) | (-(v4728 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4783[v4880] = v4784;
    int * v4787 = v4700->cache_vals;
    int v4883 = ((((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4724 + ((~(((v4726 ^ -1) | (-(v4726 ^ -1))) >> 31)) & 2)) - (v4727 + ((~(((v4728 ^ -1) | (-(v4728 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4787[v4883] = v4785;
    int * v4789 = v4700->cache_tags;
    int v4886 = ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4724 + ((~(((v4726 ^ -1) | (-(v4726 ^ -1))) >> 31)) & 2)) - (v4727 + ((~(((v4728 ^ -1) | (-(v4728 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4887 = (int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1);
    v4789[v4886] = v4887;
    int * v4791 = v4700->cache_dirty;
    v4791[v4886] = 0;
    int * v4793 = v4700->cache_age;
    v4793[v4886] = 1;
    int * v4795 = v4700->cache_age;
    int v4796 = v4795[v4886];
    int v4797 = v4795[v4815];
    int v4893 = v4797 + ((int)((unsigned int)(v4797 - v4796) >> 31));
    v4795[v4815] = v4893;
    int * v4799 = v4700->cache_age;
    int v4800 = v4799[v4816];
    int v4895 = v4800 + ((int)((unsigned int)(v4800 - v4796) >> 31));
    v4799[v4816] = v4895;
    int * v4802 = v4700->cache_age;
    v4802[v4886] = 0;
    v4805 = v4886;
  }
  int v4898 = (v4805 * 2) + (((int)((unsigned int)(v4704 + 4) >> 2)) & 1);
  int v4806 = v4712[v4898];
  int * v4807 = v4700->regs;
  v4807[5] = v4806;
  struct StateT * v4809 = slot_21(v4700);
  return v4809;
}

struct StateT * slot_436(struct StateT * v20248) {
  int * v20249 = v20248->saved_regs;
  int * v20250 = v20248->regs;
  int v20251 = v20250[7];
  v20249[7] = v20251;
  int v20253 = v20248->timer;
  int v20265 = v20253 + 1;
  v20248->timer = v20265;
  int * v20255 = v20248->regs;
  int v20256 = v20255[7];
  int v20257 = v20255[21];
  int v20268 = v20256 ^ v20257;
  v20255[7] = v20268;
  struct StateT * v20259 = slot_437(v20248);
  return v20259;
}

struct StateT * slot_61(struct StateT * v5947) {
  int v5948 = v5947->timer;
  int v5955 = v5948 + 1;
  v5947->timer = v5955;
  int * v5950 = v5947->regs;
  int v5951 = v5950[21];
  int v5958 = v5951 << 9;
  v5950[21] = v5958;
  struct StateT * v5953 = slot_62(v5947);
  return v5953;
}

struct StateT * slot_499(struct StateT * v21309) {
  int v21310 = v21309->timer;
  int v21318 = v21310 + 1;
  v21309->timer = v21318;
  int * v21312 = v21309->regs;
  int v21313 = v21312[14];
  int v21314 = v21312[30];
  int v21323 = v21313 + v21314;
  v21312[20] = v21323;
  struct StateT * v21316 = slot_500(v21309);
  return v21316;
}

struct StateT * slot_359(struct StateT * v18990) {
  int v18991 = v18990->timer;
  int v18999 = v18991 + 1;
  v18990->timer = v18999;
  int * v18993 = v18990->regs;
  int v18994 = v18993[6];
  int v18995 = v18993[15];
  int v19004 = v18994 + v18995;
  v18993[22] = v19004;
  struct StateT * v18997 = slot_360(v18990);
  return v18997;
}

struct StateT * slot_514(struct StateT * v21541) {
  int v21542 = v21541->timer;
  int v21550 = v21542 + 1;
  v21541->timer = v21550;
  int * v21544 = v21541->regs;
  int v21545 = v21544[23];
  int v21546 = v21544[24];
  int v21554 = v21545 | v21546;
  v21544[23] = v21554;
  struct StateT * v21548 = slot_515(v21541);
  return v21548;
}

struct StateT * slot_296(struct StateT * v18004) {
  int v18005 = v18004->timer;
  int v18013 = v18005 + 1;
  v18004->timer = v18013;
  int * v18007 = v18004->regs;
  int v18008 = v18007[15];
  int v18009 = v18007[23];
  int v18017 = v18008 ^ v18009;
  v18007[15] = v18017;
  struct StateT * v18011 = slot_297(v18004);
  return v18011;
}

struct StateT * slot_30(struct StateT * v5409) {
  int v5410 = v5409->timer;
  int v5417 = v5410 + 1;
  v5409->timer = v5417;
  int * v5412 = v5409->regs;
  int v5413 = v5412[31];
  int v5420 = v5413 + 1396;
  v5412[31] = v5420;
  struct StateT * v5415 = slot_31(v5409);
  return v5415;
}

struct StateT * slot_18(struct StateT * v4292) {
  int v4293 = v4292->timer;
  int v4403 = v4293 + 1;
  v4292->timer = v4403;
  int * v4295 = v4292->regs;
  int v4296 = v4295[12];
  int * v4297 = v4292->cache_tags;
  int v4407 = (((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2;
  int v4298 = v4297[v4407];
  int v4408 = ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4299 = v4297[v4408];
  int v4409 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2);
  int v4300 = v4297[v4409];
  int v4410 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4301 = v4297[v4410];
  int v4302 = v4292->timer;
  int v4411 = v4302 + ((100 ^ (((~(((v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4292->timer = v4411;
  int * v4304 = v4292->cache_vals;
  bool v4412 = !(((~(((v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v4397;
  if (v4412) {
    int * v4305 = v4292->cache_age;
    int v4414 = ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v4306 = v4305[v4414];
    int v4307 = v4305[v4407];
    int v4415 = v4307 + ((int)((unsigned int)(v4307 - v4306) >> 31));
    v4305[v4407] = v4415;
    int * v4309 = v4292->cache_age;
    int v4310 = v4309[v4408];
    int v4417 = v4310 + ((int)((unsigned int)(v4310 - v4306) >> 31));
    v4309[v4408] = v4417;
    int * v4312 = v4292->cache_age;
    v4312[v4414] = 0;
    v4397 = v4414;
  } else {
    int * v4315 = v4292->cache_age;
    int v4421 = (((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2;
    int v4316 = v4315[v4421];
    int * v4317 = v4292->cache_tags;
    int v4318 = v4317[v4421];
    int v4319 = v4315[v4408];
    int v4320 = v4317[v4408];
    bool v4423 = !(((~(((v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v4374;
    if (v4423) {
      int * v4321 = v4292->cache_age;
      int v4425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v4322 = v4321[v4425];
      int v4323 = v4321[v4409];
      int v4426 = v4323 + ((int)((unsigned int)(v4323 - v4322) >> 31));
      v4321[v4409] = v4426;
      int * v4325 = v4292->cache_age;
      int v4326 = v4325[v4410];
      int v4428 = v4326 + ((int)((unsigned int)(v4326 - v4322) >> 31));
      v4325[v4410] = v4428;
      int * v4328 = v4292->cache_age;
      v4328[v4425] = 0;
      v4374 = v4425;
    } else {
      int * v4331 = v4292->cache_age;
      int v4432 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2);
      int v4332 = v4331[v4432];
      int * v4333 = v4292->cache_tags;
      int v4334 = v4333[v4432];
      int v4335 = v4331[v4410];
      int v4336 = v4333[v4410];
      int * v4337 = v4292->cache_dirty;
      int v4435 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4338 = v4337[v4435];
      bool v4436 = !(v4338 == 0);
      if (v4436) {
        int * v4339 = v4292->cache_tags;
        int v4340 = v4339[v4435];
        int * v4341 = v4292->cache_vals;
        int v4439 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4342 = v4341[v4439];
        int v4440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4343 = v4341[v4440];
        int * v4344 = v4292->mem;
        int v4442 = v4340 * 2;
        v4344[v4442] = v4342;
        int * v4346 = v4292->mem;
        int v4445 = (v4340 * 2) + 1;
        v4346[v4445] = v4343;
        ;
      } else {
        ;
      }
      int * v4351 = v4292->mem;
      int v4450 = ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) * 2;
      int v4352 = v4351[v4450];
      int v4451 = (((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) * 2) + 1;
      int v4353 = v4351[v4451];
      int * v4354 = v4292->cache_vals;
      int v4453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4354[v4453] = v4352;
      int * v4356 = v4292->cache_vals;
      int v4456 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4356[v4456] = v4353;
      int * v4358 = v4292->cache_tags;
      int v4459 = (int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1);
      v4358[v4435] = v4459;
      int * v4360 = v4292->cache_dirty;
      v4360[v4435] = 0;
      int * v4362 = v4292->cache_age;
      v4362[v4435] = 1;
      int * v4364 = v4292->cache_age;
      int v4365 = v4364[v4435];
      int v4366 = v4364[v4409];
      int v4465 = v4366 + ((int)((unsigned int)(v4366 - v4365) >> 31));
      v4364[v4409] = v4465;
      int * v4368 = v4292->cache_age;
      int v4369 = v4368[v4410];
      int v4467 = v4369 + ((int)((unsigned int)(v4369 - v4365) >> 31));
      v4368[v4410] = v4467;
      int * v4371 = v4292->cache_age;
      v4371[v4435] = 0;
      v4374 = v4435;
    }
    int * v4375 = v4292->cache_vals;
    int v4470 = v4374 * 2;
    int v4376 = v4375[v4470];
    int v4471 = (v4374 * 2) + 1;
    int v4377 = v4375[v4471];
    int v4472 = (((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4316 + ((~(((v4318 ^ -1) | (-(v4318 ^ -1))) >> 31)) & 2)) - (v4319 + ((~(((v4320 ^ -1) | (-(v4320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4375[v4472] = v4376;
    int * v4379 = v4292->cache_vals;
    int v4475 = ((((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4316 + ((~(((v4318 ^ -1) | (-(v4318 ^ -1))) >> 31)) & 2)) - (v4319 + ((~(((v4320 ^ -1) | (-(v4320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4379[v4475] = v4377;
    int * v4381 = v4292->cache_tags;
    int v4478 = ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4316 + ((~(((v4318 ^ -1) | (-(v4318 ^ -1))) >> 31)) & 2)) - (v4319 + ((~(((v4320 ^ -1) | (-(v4320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4479 = (int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1);
    v4381[v4478] = v4479;
    int * v4383 = v4292->cache_dirty;
    v4383[v4478] = 0;
    int * v4385 = v4292->cache_age;
    v4385[v4478] = 1;
    int * v4387 = v4292->cache_age;
    int v4388 = v4387[v4478];
    int v4389 = v4387[v4407];
    int v4485 = v4389 + ((int)((unsigned int)(v4389 - v4388) >> 31));
    v4387[v4407] = v4485;
    int * v4391 = v4292->cache_age;
    int v4392 = v4391[v4408];
    int v4487 = v4392 + ((int)((unsigned int)(v4392 - v4388) >> 31));
    v4391[v4408] = v4487;
    int * v4394 = v4292->cache_age;
    v4394[v4478] = 0;
    v4397 = v4478;
  }
  int v4490 = (v4397 * 2) + (((int)((unsigned int)(v4296 + 28) >> 2)) & 1);
  int v4398 = v4304[v4490];
  int * v4399 = v4292->regs;
  v4399[19] = v4398;
  struct StateT * v4401 = slot_19(v4292);
  return v4401;
}

struct StateT * slot_9(struct StateT * v2536) {
  int v2537 = v2536->timer;
  int v2707 = v2537 + 1;
  v2536->timer = v2707;
  int * v2539 = v2536->regs;
  int v2540 = v2539[2];
  int v2541 = v2539[24];
  int * v2542 = v2536->cache_tags;
  int v2712 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2543 = v2542[v2712];
  int v2713 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2544 = v2542[v2713];
  int v2714 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2545 = v2542[v2714];
  int v2715 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2546 = v2542[v2715];
  int v2547 = v2536->timer;
  int v2716 = v2547 + ((100 ^ (((~(((v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2536->timer = v2716;
  bool v2717 = !(((~(((v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2641;
  if (v2717) {
    int * v2549 = v2536->cache_age;
    int v2719 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2550 = v2549[v2719];
    int v2551 = v2549[v2712];
    int v2720 = v2551 + ((int)((unsigned int)(v2551 - v2550) >> 31));
    v2549[v2712] = v2720;
    int * v2553 = v2536->cache_age;
    int v2554 = v2553[v2713];
    int v2722 = v2554 + ((int)((unsigned int)(v2554 - v2550) >> 31));
    v2553[v2713] = v2722;
    int * v2556 = v2536->cache_age;
    v2556[v2719] = 0;
    v2641 = v2719;
  } else {
    int * v2559 = v2536->cache_age;
    int v2726 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2560 = v2559[v2726];
    int * v2561 = v2536->cache_tags;
    int v2562 = v2561[v2726];
    int v2563 = v2559[v2713];
    int v2564 = v2561[v2713];
    bool v2728 = !(((~(((v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v2618;
    if (v2728) {
      int * v2565 = v2536->cache_age;
      int v2730 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2566 = v2565[v2730];
      int v2567 = v2565[v2714];
      int v2731 = v2567 + ((int)((unsigned int)(v2567 - v2566) >> 31));
      v2565[v2714] = v2731;
      int * v2569 = v2536->cache_age;
      int v2570 = v2569[v2715];
      int v2733 = v2570 + ((int)((unsigned int)(v2570 - v2566) >> 31));
      v2569[v2715] = v2733;
      int * v2572 = v2536->cache_age;
      v2572[v2730] = 0;
      v2618 = v2730;
    } else {
      int * v2575 = v2536->cache_age;
      int v2737 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
      int v2576 = v2575[v2737];
      int * v2577 = v2536->cache_tags;
      int v2578 = v2577[v2737];
      int v2579 = v2575[v2715];
      int v2580 = v2577[v2715];
      int * v2581 = v2536->cache_dirty;
      int v2740 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2582 = v2581[v2740];
      bool v2741 = !(v2582 == 0);
      if (v2741) {
        int * v2583 = v2536->cache_tags;
        int v2584 = v2583[v2740];
        int * v2585 = v2536->cache_vals;
        int v2744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2586 = v2585[v2744];
        int v2745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2587 = v2585[v2745];
        int * v2588 = v2536->mem;
        int v2747 = v2584 * 2;
        v2588[v2747] = v2586;
        int * v2590 = v2536->mem;
        int v2750 = (v2584 * 2) + 1;
        v2590[v2750] = v2587;
        ;
      } else {
        ;
      }
      int * v2595 = v2536->mem;
      int v2755 = ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2;
      int v2596 = v2595[v2755];
      int v2756 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2) + 1;
      int v2597 = v2595[v2756];
      int * v2598 = v2536->cache_vals;
      int v2758 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2598[v2758] = v2596;
      int * v2600 = v2536->cache_vals;
      int v2761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2600[v2761] = v2597;
      int * v2602 = v2536->cache_tags;
      int v2764 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
      v2602[v2740] = v2764;
      int * v2604 = v2536->cache_dirty;
      v2604[v2740] = 0;
      int * v2606 = v2536->cache_age;
      v2606[v2740] = 1;
      int * v2608 = v2536->cache_age;
      int v2609 = v2608[v2740];
      int v2610 = v2608[v2714];
      int v2770 = v2610 + ((int)((unsigned int)(v2610 - v2609) >> 31));
      v2608[v2714] = v2770;
      int * v2612 = v2536->cache_age;
      int v2613 = v2612[v2715];
      int v2772 = v2613 + ((int)((unsigned int)(v2613 - v2609) >> 31));
      v2612[v2715] = v2772;
      int * v2615 = v2536->cache_age;
      v2615[v2740] = 0;
      v2618 = v2740;
    }
    int * v2619 = v2536->cache_vals;
    int v2775 = v2618 * 2;
    int v2620 = v2619[v2775];
    int v2776 = (v2618 * 2) + 1;
    int v2621 = v2619[v2776];
    int v2777 = (((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2560 + ((~(((v2562 ^ -1) | (-(v2562 ^ -1))) >> 31)) & 2)) - (v2563 + ((~(((v2564 ^ -1) | (-(v2564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2619[v2777] = v2620;
    int * v2623 = v2536->cache_vals;
    int v2780 = ((((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2560 + ((~(((v2562 ^ -1) | (-(v2562 ^ -1))) >> 31)) & 2)) - (v2563 + ((~(((v2564 ^ -1) | (-(v2564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2623[v2780] = v2621;
    int * v2625 = v2536->cache_tags;
    int v2783 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2560 + ((~(((v2562 ^ -1) | (-(v2562 ^ -1))) >> 31)) & 2)) - (v2563 + ((~(((v2564 ^ -1) | (-(v2564 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2784 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
    v2625[v2783] = v2784;
    int * v2627 = v2536->cache_dirty;
    v2627[v2783] = 0;
    int * v2629 = v2536->cache_age;
    v2629[v2783] = 1;
    int * v2631 = v2536->cache_age;
    int v2632 = v2631[v2783];
    int v2633 = v2631[v2712];
    int v2790 = v2633 + ((int)((unsigned int)(v2633 - v2632) >> 31));
    v2631[v2712] = v2790;
    int * v2635 = v2536->cache_age;
    int v2636 = v2635[v2713];
    int v2792 = v2636 + ((int)((unsigned int)(v2636 - v2632) >> 31));
    v2635[v2713] = v2792;
    int * v2638 = v2536->cache_age;
    v2638[v2783] = 0;
    v2641 = v2783;
  }
  int * v2642 = v2536->cache_vals;
  int v2795 = (v2641 * 2) + (((int)((unsigned int)(v2540 + 12) >> 2)) & 1);
  v2642[v2795] = v2541;
  int * v2644 = v2536->cache_tags;
  int v2645 = v2644[v2714];
  int v2646 = v2644[v2715];
  bool v2798 = !(((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2700;
  if (v2798) {
    int * v2647 = v2536->cache_age;
    int v2800 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2648 = v2647[v2800];
    int v2649 = v2647[v2714];
    int v2801 = v2649 + ((int)((unsigned int)(v2649 - v2648) >> 31));
    v2647[v2714] = v2801;
    int * v2651 = v2536->cache_age;
    int v2652 = v2651[v2715];
    int v2803 = v2652 + ((int)((unsigned int)(v2652 - v2648) >> 31));
    v2651[v2715] = v2803;
    int * v2654 = v2536->cache_age;
    v2654[v2800] = 0;
    v2700 = v2800;
  } else {
    int * v2657 = v2536->cache_age;
    int v2807 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
    int v2658 = v2657[v2807];
    int * v2659 = v2536->cache_tags;
    int v2660 = v2659[v2807];
    int v2661 = v2657[v2715];
    int v2662 = v2659[v2715];
    int * v2663 = v2536->cache_dirty;
    int v2810 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2664 = v2663[v2810];
    bool v2811 = !(v2664 == 0);
    if (v2811) {
      int * v2665 = v2536->cache_tags;
      int v2666 = v2665[v2810];
      int * v2667 = v2536->cache_vals;
      int v2814 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2668 = v2667[v2814];
      int v2815 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2669 = v2667[v2815];
      int * v2670 = v2536->mem;
      int v2817 = v2666 * 2;
      v2670[v2817] = v2668;
      int * v2672 = v2536->mem;
      int v2820 = (v2666 * 2) + 1;
      v2672[v2820] = v2669;
      ;
    } else {
      ;
    }
    int * v2677 = v2536->mem;
    int v2825 = ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2;
    int v2678 = v2677[v2825];
    int v2826 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2) + 1;
    int v2679 = v2677[v2826];
    int * v2680 = v2536->cache_vals;
    int v2828 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2680[v2828] = v2678;
    int * v2682 = v2536->cache_vals;
    int v2831 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2682[v2831] = v2679;
    int * v2684 = v2536->cache_tags;
    int v2834 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
    v2684[v2810] = v2834;
    int * v2686 = v2536->cache_dirty;
    v2686[v2810] = 0;
    int * v2688 = v2536->cache_age;
    v2688[v2810] = 1;
    int * v2690 = v2536->cache_age;
    int v2691 = v2690[v2810];
    int v2692 = v2690[v2714];
    int v2840 = v2692 + ((int)((unsigned int)(v2692 - v2691) >> 31));
    v2690[v2714] = v2840;
    int * v2694 = v2536->cache_age;
    int v2695 = v2694[v2715];
    int v2842 = v2695 + ((int)((unsigned int)(v2695 - v2691) >> 31));
    v2694[v2715] = v2842;
    int * v2697 = v2536->cache_age;
    v2697[v2810] = 0;
    v2700 = v2810;
  }
  int * v2701 = v2536->cache_vals;
  int v2845 = (v2700 * 2) + (((int)((unsigned int)(v2540 + 12) >> 2)) & 1);
  v2701[v2845] = v2541;
  int * v2703 = v2536->cache_dirty;
  v2703[v2700] = 1;
  struct StateT * v2705 = slot_10(v2536);
  return v2705;
}

struct StateT * slot_300(struct StateT * v18071) {
  int v18072 = v18071->timer;
  int v18080 = v18072 + 1;
  v18071->timer = v18080;
  int * v18074 = v18071->regs;
  int v18075 = v18074[15];
  int v18076 = v18074[5];
  int v18085 = v18075 + v18076;
  v18074[23] = v18085;
  struct StateT * v18078 = slot_301(v18071);
  return v18078;
}

struct StateT * slot_183(struct StateT * v7933) {
  int v7934 = v7933->timer;
  int v7941 = v7934 + 1;
  v7933->timer = v7941;
  int * v7936 = v7933->regs;
  int v7937 = v7936[22];
  int v7945 = (int)((unsigned int)v7937 >> 14);
  v7936[24] = v7945;
  struct StateT * v7939 = slot_184(v7933);
  return v7939;
}

struct StateT * slot_282(struct StateT * v17791) {
  int v17792 = v17791->timer;
  int v17799 = v17792 + 1;
  v17791->timer = v17799;
  int * v17794 = v17791->regs;
  int v17795 = v17794[20];
  int v17802 = v17795 << 13;
  v17794[20] = v17802;
  struct StateT * v17797 = slot_283(v17791);
  return v17797;
}

struct StateT * slot_309(struct StateT * v18207) {
  int v18208 = v18207->timer;
  int v18216 = v18208 + 1;
  v18207->timer = v18216;
  int * v18210 = v18207->regs;
  int v18211 = v18210[22];
  int v18212 = v18210[24];
  int v18220 = v18211 | v18212;
  v18210[22] = v18220;
  struct StateT * v18214 = slot_310(v18207);
  return v18214;
}

struct StateT * slot_362(struct StateT * v19039) {
  int v19040 = v19039->timer;
  int v19047 = v19040 + 1;
  v19039->timer = v19047;
  int * v19042 = v19039->regs;
  int v19043 = v19042[20];
  int v19050 = v19043 << 13;
  v19042[20] = v19050;
  struct StateT * v19045 = slot_363(v19039);
  return v19045;
}

struct StateT * slot_43(struct StateT * v5637) {
  int v5638 = v5637->timer;
  int v5645 = v5638 + 1;
  v5637->timer = v5645;
  int * v5640 = v5637->regs;
  int v5641 = v5640[22];
  int v5649 = (int)((unsigned int)v5641 >> 25);
  v5640[24] = v5649;
  struct StateT * v5643 = slot_44(v5637);
  return v5643;
}

struct StateT * slot_76(struct StateT * v6210) {
  int v6211 = v6210->timer;
  int v6219 = v6211 + 1;
  v6210->timer = v6219;
  int * v6213 = v6210->regs;
  int v6214 = v6213[5];
  int v6215 = v6213[8];
  int v6224 = v6214 + v6215;
  v6213[23] = v6224;
  struct StateT * v6217 = slot_77(v6210);
  return v6217;
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

struct StateT * slot_55(struct StateT * v5853) {
  int v5854 = v5853->timer;
  int v5862 = v5854 + 1;
  v5853->timer = v5862;
  int * v5856 = v5853->regs;
  int v5857 = v5856[19];
  int v5858 = v5856[28];
  int v5867 = v5857 + v5858;
  v5856[22] = v5867;
  struct StateT * v5860 = slot_56(v5853);
  return v5860;
}

struct StateT * slot_283(struct StateT * v17805) {
  int v17806 = v17805->timer;
  int v17814 = v17806 + 1;
  v17805->timer = v17814;
  int * v17808 = v17805->regs;
  int v17809 = v17808[20];
  int v17810 = v17808[24];
  int v17818 = v17809 | v17810;
  v17808[20] = v17818;
  struct StateT * v17812 = slot_284(v17805);
  return v17812;
}

struct StateT * slot_346(struct StateT * v18786) {
  int v18787 = v18786->timer;
  int v18795 = v18787 + 1;
  v18786->timer = v18795;
  int * v18789 = v18786->regs;
  int v18790 = v18789[21];
  int v18791 = v18789[24];
  int v18799 = v18790 | v18791;
  v18789[21] = v18799;
  struct StateT * v18793 = slot_347(v18786);
  return v18793;
}

struct StateT * slot_516(struct StateT * v21573) {
  int v21574 = v21573->timer;
  int v21582 = v21574 + 1;
  v21573->timer = v21582;
  int * v21576 = v21573->regs;
  int v21577 = v21576[5];
  int v21578 = v21576[21];
  int v21586 = v21577 ^ v21578;
  v21576[5] = v21586;
  struct StateT * v21580 = slot_517(v21573);
  return v21580;
}

struct StateT * slot_274(struct StateT * v17660) {
  int v17661 = v17660->timer;
  int v17669 = v17661 + 1;
  v17660->timer = v17669;
  int * v17663 = v17660->regs;
  int v17664 = v17663[7];
  int v17665 = v17663[21];
  int v17673 = v17664 ^ v17665;
  v17663[7] = v17673;
  struct StateT * v17667 = slot_275(v17660);
  return v17667;
}

struct StateT * slot_535(struct StateT * v21869) {
  int v21870 = v21869->timer;
  int v21878 = v21870 + 1;
  v21869->timer = v21878;
  int * v21872 = v21869->regs;
  int v21873 = v21872[8];
  int v21874 = v21872[20];
  int v21882 = v21873 ^ v21874;
  v21872[8] = v21882;
  struct StateT * v21876 = slot_536(v21869);
  return v21876;
}

struct StateT * slot_318(struct StateT * v18349) {
  int v18350 = v18349->timer;
  int v18358 = v18350 + 1;
  v18349->timer = v18358;
  int * v18352 = v18349->regs;
  int v18353 = v18352[29];
  int v18354 = v18352[9];
  int v18363 = v18353 + v18354;
  v18352[21] = v18363;
  struct StateT * v18356 = slot_319(v18349);
  return v18356;
}

struct StateT * slot_91(struct StateT * v6453) {
  int * v6454 = v6453->saved_regs;
  int * v6455 = v6453->regs;
  int v6456 = v6455[12];
  v6454[12] = v6456;
  int v6458 = v6453->timer;
  int v6470 = v6458 + 1;
  v6453->timer = v6470;
  int * v6460 = v6453->regs;
  int v6461 = v6460[12];
  int v6462 = v6460[22];
  int v6473 = v6461 ^ v6462;
  v6460[12] = v6473;
  struct StateT * v6464 = slot_92(v6453);
  return v6464;
}

struct StateT * slot_58(struct StateT * v5902) {
  int v5903 = v5902->timer;
  int v5910 = v5903 + 1;
  v5902->timer = v5910;
  int * v5905 = v5902->regs;
  int v5906 = v5905[20];
  int v5913 = v5906 << 9;
  v5905[20] = v5913;
  struct StateT * v5908 = slot_59(v5902);
  return v5908;
}

struct StateT * slot_255(struct StateT * v17380) {
  int v17381 = v17380->timer;
  int v17389 = v17381 + 1;
  v17380->timer = v17389;
  int * v17383 = v17380->regs;
  int v17384 = v17383[8];
  int v17385 = v17383[23];
  int v17393 = v17384 ^ v17385;
  v17383[8] = v17393;
  struct StateT * v17387 = slot_257(v17380);
  return v17387;
}

struct StateT * slot_540(struct StateT * v21950) {
  int v21951 = v21950->timer;
  int v21959 = v21951 + 1;
  v21950->timer = v21959;
  int * v21953 = v21950->regs;
  int v21954 = v21953[9];
  int v21955 = v21953[5];
  int v21964 = v21954 + v21955;
  v21953[21] = v21964;
  struct StateT * v21957 = slot_541(v21950);
  return v21957;
}

struct StateT * slot_66(struct StateT * v6022) {
  int v6023 = v6022->timer;
  int v6030 = v6023 + 1;
  v6022->timer = v6030;
  int * v6025 = v6022->regs;
  int v6026 = v6025[23];
  int v6034 = (int)((unsigned int)v6026 >> 23);
  v6025[24] = v6034;
  struct StateT * v6028 = slot_67(v6022);
  return v6028;
}

struct StateT * slot_550(struct StateT * v22106) {
  int v22107 = v22106->timer;
  int v22114 = v22107 + 1;
  v22106->timer = v22114;
  int * v22109 = v22106->regs;
  int v22110 = v22109[22];
  int v22117 = v22110 << 18;
  v22109[22] = v22117;
  struct StateT * v22112 = slot_551(v22106);
  return v22112;
}

struct StateT * slot_368(struct StateT * v19129) {
  int v19130 = v19129->timer;
  int v19137 = v19130 + 1;
  v19129->timer = v19137;
  int * v19132 = v19129->regs;
  int v19133 = v19132[22];
  int v19140 = v19133 << 13;
  v19132[22] = v19140;
  struct StateT * v19135 = slot_369(v19129);
  return v19135;
}

struct StateT * slot_265(struct StateT * v17524) {
  int v17525 = v17524->timer;
  int v17532 = v17525 + 1;
  v17524->timer = v17532;
  int * v17527 = v17524->regs;
  int v17528 = v17527[21];
  int v17535 = v17528 << 9;
  v17527[21] = v17535;
  struct StateT * v17530 = slot_266(v17524);
  return v17530;
}

struct StateT * slot_37(struct StateT * v5540) {
  int * v5541 = v5540->saved_regs;
  int * v5542 = v5540->regs;
  int v5543 = v5542[24];
  v5541[24] = v5543;
  int v5545 = v5540->timer;
  int v5556 = v5545 + 1;
  v5540->timer = v5556;
  int * v5547 = v5540->regs;
  int v5548 = v5547[20];
  int v5559 = (int)((unsigned int)v5548 >> 25);
  v5547[24] = v5559;
  struct StateT * v5550 = slot_38(v5540);
  return v5550;
}

struct StateT * slot_114(struct StateT * v6856) {
  int v6857 = v6856->timer;
  int v6865 = v6857 + 1;
  v6856->timer = v6865;
  int * v6859 = v6856->regs;
  int v6860 = v6859[29];
  int v6861 = v6859[9];
  int v6870 = v6860 + v6861;
  v6859[21] = v6870;
  struct StateT * v6863 = slot_115(v6856);
  return v6863;
}

struct StateT * slot_257(struct StateT * v17396) {
  int v17397 = v17396->timer;
  int v17405 = v17397 + 1;
  v17396->timer = v17405;
  int * v17399 = v17396->regs;
  int v17400 = v17399[9];
  int v17401 = v17399[30];
  int v17410 = v17400 + v17401;
  v17399[20] = v17410;
  struct StateT * v17403 = slot_258(v17396);
  return v17403;
}

struct StateT * slot_192(struct StateT * v8071) {
  int v8072 = v8071->timer;
  int v8080 = v8072 + 1;
  v8071->timer = v8080;
  int * v8074 = v8071->regs;
  int v8075 = v8074[31];
  int v8076 = v8074[23];
  int v8084 = v8075 ^ v8076;
  v8074[31] = v8084;
  struct StateT * v8078 = slot_193(v8071);
  return v8078;
}

struct StateT * slot_327(struct StateT * v18490) {
  int v18491 = v18490->timer;
  int v18498 = v18491 + 1;
  v18490->timer = v18498;
  int * v18493 = v18490->regs;
  int v18494 = v18493[22];
  int v18502 = (int)((unsigned int)v18494 >> 25);
  v18493[24] = v18502;
  struct StateT * v18496 = slot_328(v18490);
  return v18496;
}

struct StateT * slot_48(struct StateT * v5711) {
  int v5712 = v5711->timer;
  int v5720 = v5712 + 1;
  v5711->timer = v5720;
  int * v5714 = v5711->regs;
  int v5715 = v5714[23];
  int v5716 = v5714[24];
  int v5724 = v5715 | v5716;
  v5714[23] = v5724;
  struct StateT * v5718 = slot_49(v5711);
  return v5718;
}

struct StateT * slot_396(struct StateT * v19564) {
  int v19565 = v19564->timer;
  int v19573 = v19565 + 1;
  v19564->timer = v19573;
  int * v19567 = v19564->regs;
  int v19568 = v19567[31];
  int v19569 = v19567[23];
  int v19577 = v19568 ^ v19569;
  v19567[31] = v19577;
  struct StateT * v19571 = slot_397(v19564);
  return v19571;
}

struct StateT * slot_528(struct StateT * v21763) {
  int v21764 = v21763->timer;
  int v21772 = v21764 + 1;
  v21763->timer = v21772;
  int * v21766 = v21763->regs;
  int v21767 = v21766[21];
  int v21768 = v21766[24];
  int v21776 = v21767 | v21768;
  v21766[21] = v21776;
  struct StateT * v21770 = slot_529(v21763);
  return v21770;
}

struct StateT * slot_72(struct StateT * v6136) {
  int * v6137 = v6136->saved_regs;
  int * v6138 = v6136->regs;
  int v6139 = v6138[5];
  v6137[5] = v6139;
  int v6141 = v6136->timer;
  int v6153 = v6141 + 1;
  v6136->timer = v6153;
  int * v6143 = v6136->regs;
  int v6144 = v6143[5];
  int v6145 = v6143[23];
  int v6156 = v6144 ^ v6145;
  v6143[5] = v6156;
  struct StateT * v6147 = slot_73(v6136);
  return v6147;
}

struct StateT * slot_526(struct StateT * v21734) {
  int v21735 = v21734->timer;
  int v21742 = v21735 + 1;
  v21734->timer = v21742;
  int * v21737 = v21734->regs;
  int v21738 = v21737[21];
  int v21746 = (int)((unsigned int)v21738 >> 19);
  v21737[24] = v21746;
  struct StateT * v21740 = slot_527(v21734);
  return v21740;
}

struct StateT * slot_119(struct StateT * v6936) {
  int v6937 = v6936->timer;
  int v6945 = v6937 + 1;
  v6936->timer = v6945;
  int * v6939 = v6936->regs;
  int v6940 = v6939[20];
  int v6941 = v6939[24];
  int v6949 = v6940 | v6941;
  v6939[20] = v6949;
  struct StateT * v6943 = slot_120(v6936);
  return v6943;
}

struct StateT * slot_101(struct StateT * v6627) {
  int v6628 = v6627->timer;
  int v6635 = v6628 + 1;
  v6627->timer = v6635;
  int * v6630 = v6627->regs;
  int v6631 = v6630[21];
  int v6638 = v6631 << 18;
  v6630[21] = v6638;
  struct StateT * v6633 = slot_102(v6627);
  return v6633;
}

struct StateT * slot_276(struct StateT * v17692) {
  int v17693 = v17692->timer;
  int v17701 = v17693 + 1;
  v17692->timer = v17701;
  int * v17695 = v17692->regs;
  int v17696 = v17695[5];
  int v17697 = v17695[23];
  int v17705 = v17696 ^ v17697;
  v17695[5] = v17705;
  struct StateT * v17699 = slot_277(v17692);
  return v17699;
}

struct StateT * slot_290(struct StateT * v17911) {
  int v17912 = v17911->timer;
  int v17919 = v17912 + 1;
  v17911->timer = v17919;
  int * v17914 = v17911->regs;
  int v17915 = v17914[23];
  int v17923 = (int)((unsigned int)v17915 >> 19);
  v17914[24] = v17923;
  struct StateT * v17917 = slot_291(v17911);
  return v17917;
}

struct StateT * slot_93(struct StateT * v6499) {
  int v6500 = v6499->timer;
  int v6508 = v6500 + 1;
  v6499->timer = v6508;
  int * v6502 = v6499->regs;
  int v6503 = v6502[16];
  int v6504 = v6502[6];
  int v6513 = v6503 + v6504;
  v6502[20] = v6513;
  struct StateT * v6506 = slot_94(v6499);
  return v6506;
}

struct StateT * slot_266(struct StateT * v17538) {
  int v17539 = v17538->timer;
  int v17547 = v17539 + 1;
  v17538->timer = v17547;
  int * v17541 = v17538->regs;
  int v17542 = v17541[21];
  int v17543 = v17541[24];
  int v17551 = v17542 | v17543;
  v17541[21] = v17551;
  struct StateT * v17545 = slot_267(v17538);
  return v17545;
}

struct StateT * slot_88(struct StateT * v6391) {
  int v6392 = v6391->timer;
  int v6400 = v6392 + 1;
  v6391->timer = v6400;
  int * v6394 = v6391->regs;
  int v6395 = v6394[23];
  int v6396 = v6394[24];
  int v6404 = v6395 | v6396;
  v6394[23] = v6404;
  struct StateT * v6398 = slot_89(v6391);
  return v6398;
}

struct StateT * slot_96(struct StateT * v6550) {
  int v6551 = v6550->timer;
  int v6559 = v6551 + 1;
  v6550->timer = v6559;
  int * v6553 = v6550->regs;
  int v6554 = v6553[15];
  int v6555 = v6553[5];
  int v6564 = v6554 + v6555;
  v6553[23] = v6564;
  struct StateT * v6557 = slot_97(v6550);
  return v6557;
}

struct StateT * slot_471(struct StateT * v20844) {
  int v20845 = v20844->timer;
  int v20853 = v20845 + 1;
  v20844->timer = v20853;
  int * v20847 = v20844->regs;
  int v20848 = v20847[22];
  int v20849 = v20847[24];
  int v20857 = v20848 | v20849;
  v20847[22] = v20857;
  struct StateT * v20851 = slot_472(v20844);
  return v20851;
}

struct StateT * slot_419(struct StateT * v19977) {
  int v19978 = v19977->timer;
  int v19986 = v19978 + 1;
  v19977->timer = v19986;
  int * v19980 = v19977->regs;
  int v19981 = v19980[9];
  int v19982 = v19980[30];
  int v19991 = v19981 + v19982;
  v19980[20] = v19991;
  struct StateT * v19984 = slot_420(v19977);
  return v19984;
}

struct StateT * slot_218(struct StateT * v13045) {
  int v13046 = v13045->timer;
  int v13054 = v13046 + 1;
  v13045->timer = v13054;
  int * v13048 = v13045->regs;
  int v13049 = v13048[20];
  int v13050 = v13048[24];
  int v13058 = v13049 | v13050;
  v13048[20] = v13058;
  struct StateT * v13052 = slot_221(v13045);
  return v13052;
}

struct StateT * slot_336(struct StateT * v18628) {
  int v18629 = v18628->timer;
  int v18637 = v18629 + 1;
  v18628->timer = v18637;
  int * v18631 = v18628->regs;
  int v18632 = v18631[16];
  int v18633 = v18631[23];
  int v18641 = v18632 ^ v18633;
  v18631[16] = v18641;
  struct StateT * v18635 = slot_337(v18628);
  return v18635;
}

struct StateT * slot_230(struct StateT * v14960) {
  int v14961 = v14960->timer;
  int v14968 = v14961 + 1;
  v14960->timer = v14968;
  int * v14963 = v14960->regs;
  int v14964 = v14963[22];
  int v14972 = (int)((unsigned int)v14964 >> 25);
  v14963[24] = v14972;
  struct StateT * v14966 = slot_233(v14960);
  return v14966;
}

struct StateT * slot_294(struct StateT * v17972) {
  int v17973 = v17972->timer;
  int v17981 = v17973 + 1;
  v17972->timer = v17981;
  int * v17975 = v17972->regs;
  int v17976 = v17975[14];
  int v17977 = v17975[21];
  int v17985 = v17976 ^ v17977;
  v17975[14] = v17985;
  struct StateT * v17979 = slot_295(v17972);
  return v17979;
}

struct StateT * slot_408(struct StateT * v19779) {
  int v19780 = v19779->timer;
  int v19788 = v19780 + 1;
  v19779->timer = v19788;
  int * v19782 = v19779->regs;
  int v19783 = v19782[21];
  int v19784 = v19782[24];
  int v19792 = v19783 | v19784;
  v19782[21] = v19792;
  struct StateT * v19786 = slot_409(v19779);
  return v19786;
}

struct StateT * slot_342(struct StateT * v18727) {
  int v18728 = v18727->timer;
  int v18735 = v18728 + 1;
  v18727->timer = v18735;
  int * v18730 = v18727->regs;
  int v18731 = v18730[20];
  int v18738 = v18731 << 9;
  v18730[20] = v18738;
  struct StateT * v18733 = slot_343(v18727);
  return v18733;
}

struct StateT * slot_488(struct StateT * v21139) {
  int v21140 = v21139->timer;
  int v21148 = v21140 + 1;
  v21139->timer = v21148;
  int * v21142 = v21139->regs;
  int v21143 = v21142[21];
  int v21144 = v21142[24];
  int v21152 = v21143 | v21144;
  v21142[21] = v21152;
  struct StateT * v21146 = slot_489(v21139);
  return v21146;
}

struct StateT * slot_439(struct StateT * v20317) {
  int v20318 = v20317->timer;
  int v20326 = v20318 + 1;
  v20317->timer = v20326;
  int * v20320 = v20317->regs;
  int v20321 = v20320[6];
  int v20322 = v20320[9];
  int v20331 = v20321 + v20322;
  v20320[20] = v20331;
  struct StateT * v20324 = slot_440(v20317);
  return v20324;
}

struct StateT * slot_389(struct StateT * v19455) {
  int v19456 = v19455->timer;
  int v19464 = v19456 + 1;
  v19455->timer = v19464;
  int * v19458 = v19455->regs;
  int v19459 = v19458[22];
  int v19460 = v19458[24];
  int v19468 = v19459 | v19460;
  v19458[22] = v19468;
  struct StateT * v19462 = slot_390(v19455);
  return v19462;
}

struct StateT * slot_479(struct StateT * v20997) {
  int v20998 = v20997->timer;
  int v21006 = v20998 + 1;
  v20997->timer = v21006;
  int * v21000 = v20997->regs;
  int v21001 = v21000[30];
  int v21002 = v21000[8];
  int v21011 = v21001 + v21002;
  v21000[20] = v21011;
  struct StateT * v21004 = slot_480(v20997);
  return v21004;
}

struct StateT * slot_138(struct StateT * v7234) {
  int v7235 = v7234->timer;
  int v7242 = v7235 + 1;
  v7234->timer = v7242;
  int * v7237 = v7234->regs;
  int v7238 = v7237[20];
  int v7245 = v7238 << 9;
  v7237[20] = v7245;
  struct StateT * v7240 = slot_139(v7234);
  return v7240;
}

struct StateT * slot_483(struct StateT * v21065) {
  int v21066 = v21065->timer;
  int v21073 = v21066 + 1;
  v21065->timer = v21073;
  int * v21068 = v21065->regs;
  int v21069 = v21068[20];
  int v21077 = (int)((unsigned int)v21069 >> 25);
  v21068[24] = v21077;
  struct StateT * v21071 = slot_484(v21065);
  return v21071;
}

struct StateT * slot_196(struct StateT * v8619) {
  int v8620 = v8619->timer;
  int v8624 = v8620 + 1;
  v8619->timer = v8624;
  struct StateT * v8622 = slot_198(v8619);
  return v8622;
}

struct StateT * slot_172(struct StateT * v7759) {
  int v7760 = v7759->timer;
  int v7768 = v7760 + 1;
  v7759->timer = v7768;
  int * v7762 = v7759->regs;
  int v7763 = v7762[19];
  int v7764 = v7762[23];
  int v7772 = v7763 ^ v7764;
  v7762[19] = v7772;
  struct StateT * v7766 = slot_173(v7759);
  return v7766;
}

struct StateT * slot_425(struct StateT * v20074) {
  int v20075 = v20074->timer;
  int v20083 = v20075 + 1;
  v20074->timer = v20083;
  int * v20077 = v20074->regs;
  int v20078 = v20077[20];
  int v20079 = v20077[24];
  int v20087 = v20078 | v20079;
  v20077[20] = v20087;
  struct StateT * v20081 = slot_426(v20074);
  return v20081;
}

struct StateT * slot_443(struct StateT * v20385) {
  int v20386 = v20385->timer;
  int v20393 = v20386 + 1;
  v20385->timer = v20393;
  int * v20388 = v20385->regs;
  int v20389 = v20388[20];
  int v20397 = (int)((unsigned int)v20389 >> 19);
  v20388[24] = v20397;
  struct StateT * v20391 = slot_444(v20385);
  return v20391;
}

struct StateT * slot_131(struct StateT * v7119) {
  int v7120 = v7119->timer;
  int v7128 = v7120 + 1;
  v7119->timer = v7128;
  int * v7122 = v7119->regs;
  int v7123 = v7122[15];
  int v7124 = v7122[22];
  int v7132 = v7123 ^ v7124;
  v7122[15] = v7132;
  struct StateT * v7126 = slot_132(v7119);
  return v7126;
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

struct StateT * slot_534(struct StateT * v21853) {
  int v21854 = v21853->timer;
  int v21862 = v21854 + 1;
  v21853->timer = v21862;
  int * v21856 = v21853->regs;
  int v21857 = v21856[23];
  int v21858 = v21856[24];
  int v21866 = v21857 | v21858;
  v21856[23] = v21866;
  struct StateT * v21860 = slot_535(v21853);
  return v21860;
}

struct StateT * slot_180(struct StateT * v7888) {
  int v7889 = v7888->timer;
  int v7896 = v7889 + 1;
  v7888->timer = v7896;
  int * v7891 = v7888->regs;
  int v7892 = v7891[21];
  int v7900 = (int)((unsigned int)v7892 >> 14);
  v7891[24] = v7900;
  struct StateT * v7894 = slot_181(v7888);
  return v7894;
}

struct StateT * slot_504(struct StateT * v21392) {
  int v21393 = v21392->timer;
  int v21400 = v21393 + 1;
  v21392->timer = v21400;
  int * v21395 = v21392->regs;
  int v21396 = v21395[20];
  int v21403 = v21396 << 9;
  v21395[20] = v21403;
  struct StateT * v21398 = slot_505(v21392);
  return v21398;
}

struct StateT * slot_512(struct StateT * v21512) {
  int v21513 = v21512->timer;
  int v21520 = v21513 + 1;
  v21512->timer = v21520;
  int * v21515 = v21512->regs;
  int v21516 = v21515[23];
  int v21524 = (int)((unsigned int)v21516 >> 23);
  v21515[24] = v21524;
  struct StateT * v21518 = slot_513(v21512);
  return v21518;
}

struct StateT * slot_496(struct StateT * v21261) {
  int v21262 = v21261->timer;
  int v21270 = v21262 + 1;
  v21261->timer = v21270;
  int * v21264 = v21261->regs;
  int v21265 = v21264[12];
  int v21266 = v21264[21];
  int v21274 = v21265 ^ v21266;
  v21264[12] = v21274;
  struct StateT * v21268 = slot_497(v21261);
  return v21268;
}

struct StateT * slot_494(struct StateT * v21229) {
  int v21230 = v21229->timer;
  int v21238 = v21230 + 1;
  v21229->timer = v21238;
  int * v21232 = v21229->regs;
  int v21233 = v21232[23];
  int v21234 = v21232[24];
  int v21242 = v21233 | v21234;
  v21232[23] = v21242;
  struct StateT * v21236 = slot_495(v21229);
  return v21236;
}

struct StateT * slot_242(struct StateT * v16652) {
  int v16653 = v16652->timer;
  int v16660 = v16653 + 1;
  v16652->timer = v16660;
  int * v16655 = v16652->regs;
  int v16656 = v16655[23];
  int v16663 = v16656 << 7;
  v16655[23] = v16663;
  struct StateT * v16658 = slot_245(v16652);
  return v16658;
}

struct StateT * slot_328(struct StateT * v18505) {
  int v18506 = v18505->timer;
  int v18513 = v18506 + 1;
  v18505->timer = v18513;
  int * v18508 = v18505->regs;
  int v18509 = v18508[22];
  int v18516 = v18509 << 7;
  v18508[22] = v18516;
  struct StateT * v18511 = slot_329(v18505);
  return v18511;
}

struct StateT * slot_402(struct StateT * v19674) {
  int * v19675 = v19674->saved_regs;
  int * v19676 = v19674->regs;
  int v19677 = v19676[23];
  v19675[23] = v19677;
  int v19679 = v19674->timer;
  int v19691 = v19679 + 1;
  v19674->timer = v19691;
  int * v19681 = v19674->regs;
  int v19682 = v19681[31];
  int v19683 = v19681[15];
  int v19695 = v19682 + v19683;
  v19681[23] = v19695;
  struct StateT * v19685 = slot_403(v19674);
  return v19685;
}

struct StateT * slot_200(struct StateT * v9279) {
  int v9280 = v9279->timer;
  int v9288 = v9280 + 1;
  v9279->timer = v9288;
  int * v9282 = v9279->regs;
  int v9283 = v9282[30];
  int v9284 = v9282[16];
  int v9293 = v9283 + v9284;
  v9282[20] = v9293;
  struct StateT * v9286 = slot_203(v9279);
  return v9286;
}

struct StateT * slot_149(struct StateT * v7399) {
  int v7400 = v7399->timer;
  int v7408 = v7400 + 1;
  v7399->timer = v7408;
  int * v7402 = v7399->regs;
  int v7403 = v7402[17];
  int v7404 = v7402[20];
  int v7412 = v7403 ^ v7404;
  v7402[17] = v7412;
  struct StateT * v7406 = slot_150(v7399);
  return v7406;
}

struct StateT * slot_527(struct StateT * v21749) {
  int v21750 = v21749->timer;
  int v21757 = v21750 + 1;
  v21749->timer = v21757;
  int * v21752 = v21749->regs;
  int v21753 = v21752[21];
  int v21760 = v21753 << 13;
  v21752[21] = v21760;
  struct StateT * v21755 = slot_528(v21749);
  return v21755;
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

struct StateT * slot_334(struct StateT * v18596) {
  int v18597 = v18596->timer;
  int v18605 = v18597 + 1;
  v18596->timer = v18605;
  int * v18599 = v18596->regs;
  int v18600 = v18599[12];
  int v18601 = v18599[21];
  int v18609 = v18600 ^ v18601;
  v18599[12] = v18609;
  struct StateT * v18603 = slot_335(v18596);
  return v18603;
}

struct StateT * slot_104(struct StateT * v6672) {
  int v6673 = v6672->timer;
  int v6680 = v6673 + 1;
  v6672->timer = v6680;
  int * v6675 = v6672->regs;
  int v6676 = v6675[22];
  int v6683 = v6676 << 18;
  v6675[22] = v6683;
  struct StateT * v6678 = slot_105(v6672);
  return v6678;
}

struct StateT * slot_275(struct StateT * v17676) {
  int v17677 = v17676->timer;
  int v17685 = v17677 + 1;
  v17676->timer = v17685;
  int * v17679 = v17676->regs;
  int v17680 = v17679[17];
  int v17681 = v17679[22];
  int v17689 = v17680 ^ v17681;
  v17679[17] = v17689;
  struct StateT * v17683 = slot_276(v17676);
  return v17683;
}

struct StateT * slot_329(struct StateT * v18519) {
  int v18520 = v18519->timer;
  int v18528 = v18520 + 1;
  v18519->timer = v18528;
  int * v18522 = v18519->regs;
  int v18523 = v18522[22];
  int v18524 = v18522[24];
  int v18532 = v18523 | v18524;
  v18522[22] = v18532;
  struct StateT * v18526 = slot_330(v18519);
  return v18526;
}

struct StateT * slot_428(struct StateT * v20119) {
  int v20120 = v20119->timer;
  int v20128 = v20120 + 1;
  v20119->timer = v20128;
  int * v20122 = v20119->regs;
  int v20123 = v20122[21];
  int v20124 = v20122[24];
  int v20132 = v20123 | v20124;
  v20122[21] = v20132;
  struct StateT * v20126 = slot_429(v20119);
  return v20126;
}

struct StateT * slot_395(struct StateT * v19548) {
  int v19549 = v19548->timer;
  int v19557 = v19549 + 1;
  v19548->timer = v19557;
  int * v19551 = v19548->regs;
  int v19552 = v19551[28];
  int v19553 = v19551[22];
  int v19561 = v19552 ^ v19553;
  v19551[28] = v19561;
  struct StateT * v19555 = slot_396(v19548);
  return v19555;
}

struct StateT * slot_345(struct StateT * v18772) {
  int v18773 = v18772->timer;
  int v18780 = v18773 + 1;
  v18772->timer = v18780;
  int * v18775 = v18772->regs;
  int v18776 = v18775[21];
  int v18783 = v18776 << 9;
  v18775[21] = v18783;
  struct StateT * v18778 = slot_346(v18772);
  return v18778;
}

struct StateT * slot_298(struct StateT * v18037) {
  int v18038 = v18037->timer;
  int v18046 = v18038 + 1;
  v18037->timer = v18046;
  int * v18040 = v18037->regs;
  int v18041 = v18040[14];
  int v18042 = v18040[7];
  int v18051 = v18041 + v18042;
  v18040[21] = v18051;
  struct StateT * v18044 = slot_299(v18037);
  return v18044;
}

struct StateT * slot_414(struct StateT * v19869) {
  int v19870 = v19869->timer;
  int v19878 = v19870 + 1;
  v19869->timer = v19878;
  int * v19872 = v19869->regs;
  int v19873 = v19872[23];
  int v19874 = v19872[24];
  int v19882 = v19873 | v19874;
  v19872[23] = v19882;
  struct StateT * v19876 = slot_415(v19869);
  return v19876;
}

struct StateT * slot_364(struct StateT * v19069) {
  int v19070 = v19069->timer;
  int v19077 = v19070 + 1;
  v19069->timer = v19077;
  int * v19072 = v19069->regs;
  int v19073 = v19072[21];
  int v19081 = (int)((unsigned int)v19073 >> 19);
  v19072[24] = v19081;
  struct StateT * v19075 = slot_365(v19069);
  return v19075;
}

struct StateT * slot_356(struct StateT * v18940) {
  int v18941 = v18940->timer;
  int v18949 = v18941 + 1;
  v18940->timer = v18949;
  int * v18943 = v18940->regs;
  int v18944 = v18943[7];
  int v18945 = v18943[23];
  int v18953 = v18944 ^ v18945;
  v18943[7] = v18953;
  struct StateT * v18947 = slot_357(v18940);
  return v18947;
}

struct StateT * slot_253(struct StateT * v17359) {
  int v17360 = v17359->timer;
  int v17368 = v17360 + 1;
  v17359->timer = v17368;
  int * v17362 = v17359->regs;
  int v17363 = v17362[19];
  int v17364 = v17362[22];
  int v17372 = v17363 ^ v17364;
  v17362[19] = v17372;
  struct StateT * v17366 = slot_255(v17359);
  return v17366;
}

struct StateT * slot_434(struct StateT * v20209) {
  int v20210 = v20209->timer;
  int v20218 = v20210 + 1;
  v20209->timer = v20218;
  int * v20212 = v20209->regs;
  int v20213 = v20212[23];
  int v20214 = v20212[24];
  int v20222 = v20213 | v20214;
  v20212[23] = v20222;
  struct StateT * v20216 = slot_435(v20209);
  return v20216;
}

struct StateT * slot_64(struct StateT * v5992) {
  int v5993 = v5992->timer;
  int v6000 = v5993 + 1;
  v5992->timer = v6000;
  int * v5995 = v5992->regs;
  int v5996 = v5995[22];
  int v6003 = v5996 << 9;
  v5995[22] = v6003;
  struct StateT * v5998 = slot_65(v5992);
  return v5998;
}

struct StateT * slot_170(struct StateT * v7727) {
  int v7728 = v7727->timer;
  int v7736 = v7728 + 1;
  v7727->timer = v7736;
  int * v7730 = v7727->regs;
  int v7731 = v7730[9];
  int v7732 = v7730[21];
  int v7740 = v7731 ^ v7732;
  v7730[9] = v7740;
  struct StateT * v7734 = slot_171(v7727);
  return v7734;
}

struct StateT * slot_53(struct StateT * v5819) {
  int v5820 = v5819->timer;
  int v5828 = v5820 + 1;
  v5819->timer = v5828;
  int * v5822 = v5819->regs;
  int v5823 = v5822[9];
  int v5824 = v5822[30];
  int v5833 = v5823 + v5824;
  v5822[20] = v5833;
  struct StateT * v5826 = slot_54(v5819);
  return v5826;
}

struct StateT * slot_522(struct StateT * v21672) {
  int v21673 = v21672->timer;
  int v21681 = v21673 + 1;
  v21672->timer = v21681;
  int * v21675 = v21672->regs;
  int v21676 = v21675[7];
  int v21677 = v21675[16];
  int v21686 = v21676 + v21677;
  v21675[23] = v21686;
  struct StateT * v21679 = slot_523(v21672);
  return v21679;
}

struct StateT * slot_80(struct StateT * v6272) {
  int v6273 = v6272->timer;
  int v6280 = v6273 + 1;
  v6272->timer = v6280;
  int * v6275 = v6272->regs;
  int v6276 = v6275[21];
  int v6284 = (int)((unsigned int)v6276 >> 19);
  v6275[24] = v6284;
  struct StateT * v6278 = slot_81(v6272);
  return v6278;
}

struct StateT * slot_503(struct StateT * v21377) {
  int v21378 = v21377->timer;
  int v21385 = v21378 + 1;
  v21377->timer = v21385;
  int * v21380 = v21377->regs;
  int v21381 = v21380[20];
  int v21389 = (int)((unsigned int)v21381 >> 23);
  v21380[24] = v21389;
  struct StateT * v21383 = slot_504(v21377);
  return v21383;
}

struct StateT * slot_390(struct StateT * v19471) {
  int v19472 = v19471->timer;
  int v19479 = v19472 + 1;
  v19471->timer = v19479;
  int * v19474 = v19471->regs;
  int v19475 = v19474[23];
  int v19483 = (int)((unsigned int)v19475 >> 14);
  v19474[24] = v19483;
  struct StateT * v19477 = slot_391(v19471);
  return v19477;
}

struct StateT * slot_44(struct StateT * v5652) {
  int v5653 = v5652->timer;
  int v5660 = v5653 + 1;
  v5652->timer = v5660;
  int * v5655 = v5652->regs;
  int v5656 = v5655[22];
  int v5663 = v5656 << 7;
  v5655[22] = v5663;
  struct StateT * v5658 = slot_45(v5652);
  return v5658;
}

struct StateT * slot_137(struct StateT * v7219) {
  int v7220 = v7219->timer;
  int v7227 = v7220 + 1;
  v7219->timer = v7227;
  int * v7222 = v7219->regs;
  int v7223 = v7222[20];
  int v7231 = (int)((unsigned int)v7223 >> 23);
  v7222[24] = v7231;
  struct StateT * v7225 = slot_138(v7219);
  return v7225;
}

struct StateT * slot_386(struct StateT * v19410) {
  int v19411 = v19410->timer;
  int v19419 = v19411 + 1;
  v19410->timer = v19419;
  int * v19413 = v19410->regs;
  int v19414 = v19413[21];
  int v19415 = v19413[24];
  int v19423 = v19414 | v19415;
  v19413[21] = v19423;
  struct StateT * v19417 = slot_387(v19410);
  return v19417;
}

struct StateT * slot_122(struct StateT * v6981) {
  int v6982 = v6981->timer;
  int v6990 = v6982 + 1;
  v6981->timer = v6990;
  int * v6984 = v6981->regs;
  int v6985 = v6984[21];
  int v6986 = v6984[24];
  int v6994 = v6985 | v6986;
  v6984[21] = v6994;
  struct StateT * v6988 = slot_123(v6981);
  return v6988;
}

struct StateT * slot_99(struct StateT * v6596) {
  int v6597 = v6596->timer;
  int v6605 = v6597 + 1;
  v6596->timer = v6605;
  int * v6599 = v6596->regs;
  int v6600 = v6599[20];
  int v6601 = v6599[24];
  int v6609 = v6600 | v6601;
  v6599[20] = v6609;
  struct StateT * v6603 = slot_100(v6596);
  return v6603;
}

struct StateT * slot_179(struct StateT * v7872) {
  int v7873 = v7872->timer;
  int v7881 = v7873 + 1;
  v7872->timer = v7881;
  int * v7875 = v7872->regs;
  int v7876 = v7875[20];
  int v7877 = v7875[24];
  int v7885 = v7876 | v7877;
  v7875[20] = v7885;
  struct StateT * v7879 = slot_180(v7872);
  return v7879;
}

struct StateT * slot_338(struct StateT * v18661) {
  int v18662 = v18661->timer;
  int v18670 = v18662 + 1;
  v18661->timer = v18670;
  int * v18664 = v18661->regs;
  int v18665 = v18664[12];
  int v18666 = v18664[29];
  int v18675 = v18665 + v18666;
  v18664[21] = v18675;
  struct StateT * v18668 = slot_339(v18661);
  return v18668;
}

struct StateT * slot_22(struct StateT * v5108) {
  int v5109 = v5108->timer;
  int v5219 = v5109 + 1;
  v5108->timer = v5219;
  int * v5111 = v5108->regs;
  int v5112 = v5111[11];
  int * v5113 = v5108->cache_tags;
  int v5223 = (((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2;
  int v5114 = v5113[v5223];
  int v5224 = ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5115 = v5113[v5224];
  int v5225 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2);
  int v5116 = v5113[v5225];
  int v5226 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5117 = v5113[v5226];
  int v5118 = v5108->timer;
  int v5227 = v5118 + ((100 ^ (((~(((v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5108->timer = v5227;
  int * v5120 = v5108->cache_vals;
  bool v5228 = !(((~(((v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5213;
  if (v5228) {
    int * v5121 = v5108->cache_age;
    int v5230 = ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5122 = v5121[v5230];
    int v5123 = v5121[v5223];
    int v5231 = v5123 + ((int)((unsigned int)(v5123 - v5122) >> 31));
    v5121[v5223] = v5231;
    int * v5125 = v5108->cache_age;
    int v5126 = v5125[v5224];
    int v5233 = v5126 + ((int)((unsigned int)(v5126 - v5122) >> 31));
    v5125[v5224] = v5233;
    int * v5128 = v5108->cache_age;
    v5128[v5230] = 0;
    v5213 = v5230;
  } else {
    int * v5131 = v5108->cache_age;
    int v5237 = (((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2;
    int v5132 = v5131[v5237];
    int * v5133 = v5108->cache_tags;
    int v5134 = v5133[v5237];
    int v5135 = v5131[v5224];
    int v5136 = v5133[v5224];
    bool v5239 = !(((~(((v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v5190;
    if (v5239) {
      int * v5137 = v5108->cache_age;
      int v5241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v5138 = v5137[v5241];
      int v5139 = v5137[v5225];
      int v5242 = v5139 + ((int)((unsigned int)(v5139 - v5138) >> 31));
      v5137[v5225] = v5242;
      int * v5141 = v5108->cache_age;
      int v5142 = v5141[v5226];
      int v5244 = v5142 + ((int)((unsigned int)(v5142 - v5138) >> 31));
      v5141[v5226] = v5244;
      int * v5144 = v5108->cache_age;
      v5144[v5241] = 0;
      v5190 = v5241;
    } else {
      int * v5147 = v5108->cache_age;
      int v5248 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2);
      int v5148 = v5147[v5248];
      int * v5149 = v5108->cache_tags;
      int v5150 = v5149[v5248];
      int v5151 = v5147[v5226];
      int v5152 = v5149[v5226];
      int * v5153 = v5108->cache_dirty;
      int v5251 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5154 = v5153[v5251];
      bool v5252 = !(v5154 == 0);
      if (v5252) {
        int * v5155 = v5108->cache_tags;
        int v5156 = v5155[v5251];
        int * v5157 = v5108->cache_vals;
        int v5255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5158 = v5157[v5255];
        int v5256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5159 = v5157[v5256];
        int * v5160 = v5108->mem;
        int v5258 = v5156 * 2;
        v5160[v5258] = v5158;
        int * v5162 = v5108->mem;
        int v5261 = (v5156 * 2) + 1;
        v5162[v5261] = v5159;
        ;
      } else {
        ;
      }
      int * v5167 = v5108->mem;
      int v5266 = ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) * 2;
      int v5168 = v5167[v5266];
      int v5267 = (((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) * 2) + 1;
      int v5169 = v5167[v5267];
      int * v5170 = v5108->cache_vals;
      int v5269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5170[v5269] = v5168;
      int * v5172 = v5108->cache_vals;
      int v5272 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5172[v5272] = v5169;
      int * v5174 = v5108->cache_tags;
      int v5275 = (int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1);
      v5174[v5251] = v5275;
      int * v5176 = v5108->cache_dirty;
      v5176[v5251] = 0;
      int * v5178 = v5108->cache_age;
      v5178[v5251] = 1;
      int * v5180 = v5108->cache_age;
      int v5181 = v5180[v5251];
      int v5182 = v5180[v5225];
      int v5281 = v5182 + ((int)((unsigned int)(v5182 - v5181) >> 31));
      v5180[v5225] = v5281;
      int * v5184 = v5108->cache_age;
      int v5185 = v5184[v5226];
      int v5283 = v5185 + ((int)((unsigned int)(v5185 - v5181) >> 31));
      v5184[v5226] = v5283;
      int * v5187 = v5108->cache_age;
      v5187[v5251] = 0;
      v5190 = v5251;
    }
    int * v5191 = v5108->cache_vals;
    int v5286 = v5190 * 2;
    int v5192 = v5191[v5286];
    int v5287 = (v5190 * 2) + 1;
    int v5193 = v5191[v5287];
    int v5288 = (((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5132 + ((~(((v5134 ^ -1) | (-(v5134 ^ -1))) >> 31)) & 2)) - (v5135 + ((~(((v5136 ^ -1) | (-(v5136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5191[v5288] = v5192;
    int * v5195 = v5108->cache_vals;
    int v5291 = ((((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5132 + ((~(((v5134 ^ -1) | (-(v5134 ^ -1))) >> 31)) & 2)) - (v5135 + ((~(((v5136 ^ -1) | (-(v5136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5195[v5291] = v5193;
    int * v5197 = v5108->cache_tags;
    int v5294 = ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5132 + ((~(((v5134 ^ -1) | (-(v5134 ^ -1))) >> 31)) & 2)) - (v5135 + ((~(((v5136 ^ -1) | (-(v5136 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5295 = (int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1);
    v5197[v5294] = v5295;
    int * v5199 = v5108->cache_dirty;
    v5199[v5294] = 0;
    int * v5201 = v5108->cache_age;
    v5201[v5294] = 1;
    int * v5203 = v5108->cache_age;
    int v5204 = v5203[v5294];
    int v5205 = v5203[v5223];
    int v5301 = v5205 + ((int)((unsigned int)(v5205 - v5204) >> 31));
    v5203[v5223] = v5301;
    int * v5207 = v5108->cache_age;
    int v5208 = v5207[v5224];
    int v5303 = v5208 + ((int)((unsigned int)(v5208 - v5204) >> 31));
    v5207[v5224] = v5303;
    int * v5210 = v5108->cache_age;
    v5210[v5294] = 0;
    v5213 = v5294;
  }
  int v5306 = (v5213 * 2) + (((int)((unsigned int)(v5112 + 12) >> 2)) & 1);
  int v5214 = v5120[v5306];
  int * v5215 = v5108->regs;
  v5215[18] = v5214;
  struct StateT * v5217 = slot_23(v5108);
  return v5217;
}

struct StateT * slot_366(struct StateT * v19098) {
  int v19099 = v19098->timer;
  int v19107 = v19099 + 1;
  v19098->timer = v19107;
  int * v19101 = v19098->regs;
  int v19102 = v19101[21];
  int v19103 = v19101[24];
  int v19111 = v19102 | v19103;
  v19101[21] = v19111;
  struct StateT * v19105 = slot_367(v19098);
  return v19105;
}

struct StateT * slot_139(struct StateT * v7248) {
  int v7249 = v7248->timer;
  int v7257 = v7249 + 1;
  v7248->timer = v7257;
  int * v7251 = v7248->regs;
  int v7252 = v7251[20];
  int v7253 = v7251[24];
  int v7261 = v7252 | v7253;
  v7251[20] = v7261;
  struct StateT * v7255 = slot_140(v7248);
  return v7255;
}

struct StateT * slot_438(struct StateT * v20294) {
  int * v20295 = v20294->saved_regs;
  int * v20296 = v20294->regs;
  int v20297 = v20296[5];
  v20295[5] = v20297;
  int v20299 = v20294->timer;
  int v20311 = v20299 + 1;
  v20294->timer = v20311;
  int * v20301 = v20294->regs;
  int v20302 = v20301[5];
  int v20303 = v20301[23];
  int v20314 = v20302 ^ v20303;
  v20301[5] = v20314;
  struct StateT * v20305 = slot_439(v20294);
  return v20305;
}

struct StateT * slot_333(struct StateT * v18580) {
  int v18581 = v18580->timer;
  int v18589 = v18581 + 1;
  v18580->timer = v18589;
  int * v18583 = v18580->regs;
  int v18584 = v18583[14];
  int v18585 = v18583[20];
  int v18593 = v18584 ^ v18585;
  v18583[14] = v18593;
  struct StateT * v18587 = slot_334(v18580);
  return v18587;
}

struct StateT * slot_221(struct StateT * v13580) {
  int v13581 = v13580->timer;
  int v13588 = v13581 + 1;
  v13580->timer = v13588;
  int * v13583 = v13580->regs;
  int v13584 = v13583[21];
  int v13592 = (int)((unsigned int)v13584 >> 25);
  v13583[24] = v13592;
  struct StateT * v13586 = slot_224(v13580);
  return v13586;
}

struct StateT * slot_153(struct StateT * v7463) {
  int v7464 = v7463->timer;
  int v7472 = v7464 + 1;
  v7463->timer = v7472;
  int * v7466 = v7463->regs;
  int v7467 = v7466[17];
  int v7468 = v7466[14];
  int v7477 = v7467 + v7468;
  v7466[20] = v7477;
  struct StateT * v7470 = slot_154(v7463);
  return v7470;
}

struct StateT * slot_129(struct StateT * v7087) {
  int v7088 = v7087->timer;
  int v7096 = v7088 + 1;
  v7087->timer = v7096;
  int * v7090 = v7087->regs;
  int v7091 = v7090[14];
  int v7092 = v7090[20];
  int v7100 = v7091 ^ v7092;
  v7090[14] = v7100;
  struct StateT * v7094 = slot_130(v7087);
  return v7094;
}

struct StateT * slot_158(struct StateT * v7546) {
  int v7547 = v7546->timer;
  int v7554 = v7547 + 1;
  v7546->timer = v7554;
  int * v7549 = v7546->regs;
  int v7550 = v7549[20];
  int v7557 = v7550 << 13;
  v7549[20] = v7557;
  struct StateT * v7552 = slot_159(v7546);
  return v7552;
}

struct StateT * slot_311(struct StateT * v18238) {
  int v18239 = v18238->timer;
  int v18246 = v18239 + 1;
  v18238->timer = v18246;
  int * v18241 = v18238->regs;
  int v18242 = v18241[23];
  int v18249 = v18242 << 18;
  v18241[23] = v18249;
  struct StateT * v18244 = slot_312(v18238);
  return v18244;
}

struct StateT * slot_498(struct StateT * v21293) {
  int v21294 = v21293->timer;
  int v21302 = v21294 + 1;
  v21293->timer = v21302;
  int * v21296 = v21293->regs;
  int v21297 = v21296[16];
  int v21298 = v21296[23];
  int v21306 = v21297 ^ v21298;
  v21296[16] = v21306;
  struct StateT * v21300 = slot_499(v21293);
  return v21300;
}

struct StateT * slot_279(struct StateT * v17742) {
  int v17743 = v17742->timer;
  int v17751 = v17743 + 1;
  v17742->timer = v17751;
  int * v17745 = v17742->regs;
  int v17746 = v17745[17];
  int v17747 = v17745[19];
  int v17756 = v17746 + v17747;
  v17745[22] = v17756;
  struct StateT * v17749 = slot_280(v17742);
  return v17749;
}

struct StateT * slot_271(struct StateT * v17614) {
  int v17615 = v17614->timer;
  int v17622 = v17615 + 1;
  v17614->timer = v17622;
  int * v17617 = v17614->regs;
  int v17618 = v17617[23];
  int v17625 = v17618 << 9;
  v17617[23] = v17625;
  struct StateT * v17620 = slot_272(v17614);
  return v17620;
}

struct StateT * slot_524(struct StateT * v21704) {
  int v21705 = v21704->timer;
  int v21712 = v21705 + 1;
  v21704->timer = v21712;
  int * v21707 = v21704->regs;
  int v21708 = v21707[20];
  int v21715 = v21708 << 13;
  v21707[20] = v21715;
  struct StateT * v21710 = slot_525(v21704);
  return v21710;
}

struct StateT * slot_505(struct StateT * v21406) {
  int v21407 = v21406->timer;
  int v21415 = v21407 + 1;
  v21406->timer = v21415;
  int * v21409 = v21406->regs;
  int v21410 = v21409[20];
  int v21411 = v21409[24];
  int v21419 = v21410 | v21411;
  v21409[20] = v21419;
  struct StateT * v21413 = slot_506(v21406);
  return v21413;
}

struct StateT * slot_401(struct StateT * v19650) {
  int * v19651 = v19650->saved_regs;
  int * v19652 = v19650->regs;
  int v19653 = v19652[22];
  v19651[22] = v19653;
  int v19655 = v19650->timer;
  int v19667 = v19655 + 1;
  v19650->timer = v19667;
  int * v19657 = v19650->regs;
  int v19658 = v19657[28];
  int v19659 = v19657[12];
  int v19671 = v19658 + v19659;
  v19657[22] = v19671;
  struct StateT * v19661 = slot_402(v19650);
  return v19661;
}

struct StateT * slot_423(struct StateT * v20045) {
  int v20046 = v20045->timer;
  int v20053 = v20046 + 1;
  v20045->timer = v20053;
  int * v20048 = v20045->regs;
  int v20049 = v20048[20];
  int v20057 = (int)((unsigned int)v20049 >> 23);
  v20048[24] = v20057;
  struct StateT * v20051 = slot_424(v20045);
  return v20051;
}

struct StateT * slot_532(struct StateT * v21824) {
  int v21825 = v21824->timer;
  int v21832 = v21825 + 1;
  v21824->timer = v21832;
  int * v21827 = v21824->regs;
  int v21828 = v21827[23];
  int v21836 = (int)((unsigned int)v21828 >> 19);
  v21827[24] = v21836;
  struct StateT * v21830 = slot_533(v21824);
  return v21830;
}

struct StateT * slot_111(struct StateT * v6793) {
  int * v6794 = v6793->saved_regs;
  int * v6795 = v6793->regs;
  int v6796 = v6795[28];
  v6794[28] = v6796;
  int v6798 = v6793->timer;
  int v6810 = v6798 + 1;
  v6793->timer = v6810;
  int * v6800 = v6793->regs;
  int v6801 = v6800[28];
  int v6802 = v6800[22];
  int v6813 = v6801 ^ v6802;
  v6800[28] = v6813;
  struct StateT * v6804 = slot_112(v6793);
  return v6804;
}

struct StateT * slot_549(struct StateT * v22091) {
  int v22092 = v22091->timer;
  int v22099 = v22092 + 1;
  v22091->timer = v22099;
  int * v22094 = v22091->regs;
  int v22095 = v22094[22];
  int v22103 = (int)((unsigned int)v22095 >> 14);
  v22094[24] = v22103;
  struct StateT * v22097 = slot_550(v22091);
  return v22097;
}

struct StateT * slot_349(struct StateT * v18831) {
  int v18832 = v18831->timer;
  int v18840 = v18832 + 1;
  v18831->timer = v18840;
  int * v18834 = v18831->regs;
  int v18835 = v18834[22];
  int v18836 = v18834[24];
  int v18844 = v18835 | v18836;
  v18834[22] = v18844;
  struct StateT * v18838 = slot_350(v18831);
  return v18838;
}

struct StateT * slot_291(struct StateT * v17926) {
  int v17927 = v17926->timer;
  int v17934 = v17927 + 1;
  v17926->timer = v17934;
  int * v17929 = v17926->regs;
  int v17930 = v17929[23];
  int v17937 = v17930 << 13;
  v17929[23] = v17937;
  struct StateT * v17932 = slot_292(v17926);
  return v17932;
}

struct StateT * slot_147(struct StateT * v7369) {
  int v7370 = v7369->timer;
  int v7377 = v7370 + 1;
  v7369->timer = v7377;
  int * v7372 = v7369->regs;
  int v7373 = v7372[23];
  int v7380 = v7373 << 9;
  v7372[23] = v7380;
  struct StateT * v7375 = slot_148(v7369);
  return v7375;
}

struct StateT * slot_410(struct StateT * v19810) {
  int v19811 = v19810->timer;
  int v19818 = v19811 + 1;
  v19810->timer = v19818;
  int * v19813 = v19810->regs;
  int v19814 = v19813[22];
  int v19821 = v19814 << 7;
  v19813[22] = v19821;
  struct StateT * v19816 = slot_411(v19810);
  return v19816;
}

struct StateT * slot_491(struct StateT * v21184) {
  int v21185 = v21184->timer;
  int v21193 = v21185 + 1;
  v21184->timer = v21193;
  int * v21187 = v21184->regs;
  int v21188 = v21187[22];
  int v21189 = v21187[24];
  int v21197 = v21188 | v21189;
  v21187[22] = v21197;
  struct StateT * v21191 = slot_492(v21184);
  return v21191;
}

struct StateT * slot_163(struct StateT * v7621) {
  int v7622 = v7621->timer;
  int v7629 = v7622 + 1;
  v7621->timer = v7629;
  int * v7624 = v7621->regs;
  int v7625 = v7624[22];
  int v7633 = (int)((unsigned int)v7625 >> 19);
  v7624[24] = v7633;
  struct StateT * v7627 = slot_164(v7621);
  return v7627;
}

struct StateT * slot_422(struct StateT * v20028) {
  int v20029 = v20028->timer;
  int v20037 = v20029 + 1;
  v20028->timer = v20037;
  int * v20031 = v20028->regs;
  int v20032 = v20031[8];
  int v20033 = v20031[31];
  int v20042 = v20032 + v20033;
  v20031[23] = v20042;
  struct StateT * v20035 = slot_423(v20028);
  return v20035;
}

struct StateT * slot_448(struct StateT * v20459) {
  int v20460 = v20459->timer;
  int v20468 = v20460 + 1;
  v20459->timer = v20468;
  int * v20462 = v20459->regs;
  int v20463 = v20462[21];
  int v20464 = v20462[24];
  int v20472 = v20463 | v20464;
  v20462[21] = v20472;
  struct StateT * v20466 = slot_449(v20459);
  return v20466;
}

struct StateT * slot_194(struct StateT * v8108) {
  int * v8109 = v8108->regs;
  int v8110 = v8109[11];
  bool v8209 = (v8110 ^ -2147483648) < -2147483648;
  struct StateT * v8205;
  if (v8209) {
    int v8111 = v8108->timer;
    int v8210 = v8111 + 15;
    v8108->timer = v8210;
    int * v8113 = v8108->saved_regs;
    int v8114 = v8113[20];
    int * v8115 = v8108->regs;
    v8115[20] = v8114;
    int * v8117 = v8108->saved_regs;
    int v8118 = v8117[21];
    int * v8119 = v8108->regs;
    v8119[21] = v8118;
    int * v8121 = v8108->saved_regs;
    int v8122 = v8121[22];
    int * v8123 = v8108->regs;
    v8123[22] = v8122;
    int * v8125 = v8108->saved_regs;
    int v8126 = v8125[23];
    int * v8127 = v8108->regs;
    v8127[23] = v8126;
    int * v8129 = v8108->saved_regs;
    int v8130 = v8129[24];
    int * v8131 = v8108->regs;
    v8131[24] = v8130;
    int * v8133 = v8108->saved_regs;
    int v8134 = v8133[9];
    int * v8135 = v8108->regs;
    v8135[9] = v8134;
    int * v8137 = v8108->saved_regs;
    int v8138 = v8137[18];
    int * v8139 = v8108->regs;
    v8139[18] = v8138;
    int * v8141 = v8108->saved_regs;
    int v8142 = v8141[19];
    int * v8143 = v8108->regs;
    v8143[19] = v8142;
    int * v8145 = v8108->saved_regs;
    int v8146 = v8145[8];
    int * v8147 = v8108->regs;
    v8147[8] = v8146;
    int * v8149 = v8108->saved_regs;
    int v8150 = v8149[6];
    int * v8151 = v8108->regs;
    v8151[6] = v8150;
    int * v8153 = v8108->saved_regs;
    int v8154 = v8153[7];
    int * v8155 = v8108->regs;
    v8155[7] = v8154;
    int * v8157 = v8108->saved_regs;
    int v8158 = v8157[17];
    int * v8159 = v8108->regs;
    v8159[17] = v8158;
    int * v8161 = v8108->saved_regs;
    int v8162 = v8161[5];
    int * v8163 = v8108->regs;
    v8163[5] = v8162;
    int * v8165 = v8108->saved_regs;
    int v8166 = v8165[16];
    int * v8167 = v8108->regs;
    v8167[16] = v8166;
    int * v8169 = v8108->saved_regs;
    int v8170 = v8169[14];
    int * v8171 = v8108->regs;
    v8171[14] = v8170;
    int * v8173 = v8108->saved_regs;
    int v8174 = v8173[12];
    int * v8175 = v8108->regs;
    v8175[12] = v8174;
    int * v8177 = v8108->saved_regs;
    int v8178 = v8177[15];
    int * v8179 = v8108->regs;
    v8179[15] = v8178;
    int * v8181 = v8108->saved_regs;
    int v8182 = v8181[30];
    int * v8183 = v8108->regs;
    v8183[30] = v8182;
    int * v8185 = v8108->saved_regs;
    int v8186 = v8185[29];
    int * v8187 = v8108->regs;
    v8187[29] = v8186;
    int * v8189 = v8108->saved_regs;
    int v8190 = v8189[28];
    int * v8191 = v8108->regs;
    v8191[28] = v8190;
    int * v8193 = v8108->saved_regs;
    int v8194 = v8193[31];
    int * v8195 = v8108->regs;
    v8195[31] = v8194;
    int * v8197 = v8108->saved_regs;
    int v8198 = v8197[13];
    int * v8199 = v8108->regs;
    v8199[13] = v8198;
    struct StateT * v8201 = slot_201(v8108);
    v8205 = v8201;
  } else {
    struct StateT * v8203 = slot_196(v8108);
    v8205 = v8203;
  }
  return v8205;
}

struct StateT * slot_551(struct StateT * v22120) {
  int v22121 = v22120->timer;
  int v22129 = v22121 + 1;
  v22120->timer = v22129;
  int * v22123 = v22120->regs;
  int v22124 = v22123[22];
  int v22125 = v22123[24];
  int v22133 = v22124 | v22125;
  v22123[22] = v22133;
  struct StateT * v22127 = slot_552(v22120);
  return v22127;
}

struct StateT * slot_407(struct StateT * v19765) {
  int v19766 = v19765->timer;
  int v19773 = v19766 + 1;
  v19765->timer = v19773;
  int * v19768 = v19765->regs;
  int v19769 = v19768[21];
  int v19776 = v19769 << 7;
  v19768[21] = v19776;
  struct StateT * v19771 = slot_408(v19765);
  return v19771;
}

struct StateT * slot_543(struct StateT * v22001) {
  int v22002 = v22001->timer;
  int v22009 = v22002 + 1;
  v22001->timer = v22009;
  int * v22004 = v22001->regs;
  int v22005 = v22004[20];
  int v22013 = (int)((unsigned int)v22005 >> 14);
  v22004[24] = v22013;
  struct StateT * v22007 = slot_544(v22001);
  return v22007;
}

struct StateT * slot_360(struct StateT * v19007) {
  int v19008 = v19007->timer;
  int v19016 = v19008 + 1;
  v19007->timer = v19016;
  int * v19010 = v19007->regs;
  int v19011 = v19010[7];
  int v19012 = v19010[16];
  int v19021 = v19011 + v19012;
  v19010[23] = v19021;
  struct StateT * v19014 = slot_361(v19007);
  return v19014;
}

struct StateT * slot_259(struct StateT * v17430) {
  int v17431 = v17430->timer;
  int v17439 = v17431 + 1;
  v17430->timer = v17439;
  int * v17433 = v17430->regs;
  int v17434 = v17433[19];
  int v17435 = v17433[28];
  int v17444 = v17434 + v17435;
  v17433[22] = v17444;
  struct StateT * v17437 = slot_260(v17430);
  return v17437;
}

struct StateT * slot_469(struct StateT * v20815) {
  int v20816 = v20815->timer;
  int v20823 = v20816 + 1;
  v20815->timer = v20823;
  int * v20818 = v20815->regs;
  int v20819 = v20818[22];
  int v20827 = (int)((unsigned int)v20819 >> 14);
  v20818[24] = v20827;
  struct StateT * v20821 = slot_470(v20815);
  return v20821;
}

struct StateT * slot_117(struct StateT * v6907) {
  int v6908 = v6907->timer;
  int v6915 = v6908 + 1;
  v6907->timer = v6915;
  int * v6910 = v6907->regs;
  int v6911 = v6910[20];
  int v6919 = (int)((unsigned int)v6911 >> 25);
  v6910[24] = v6919;
  struct StateT * v6913 = slot_118(v6907);
  return v6913;
}

struct StateT * slot_90(struct StateT * v6430) {
  int * v6431 = v6430->saved_regs;
  int * v6432 = v6430->regs;
  int v6433 = v6432[14];
  v6431[14] = v6433;
  int v6435 = v6430->timer;
  int v6447 = v6435 + 1;
  v6430->timer = v6447;
  int * v6437 = v6430->regs;
  int v6438 = v6437[14];
  int v6439 = v6437[21];
  int v6450 = v6438 ^ v6439;
  v6437[14] = v6450;
  struct StateT * v6441 = slot_91(v6430);
  return v6441;
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